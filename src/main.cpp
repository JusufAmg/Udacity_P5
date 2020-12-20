#include <iostream>
#include <thread>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "score.h"


int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  std::string name;
  bool play_again = true;
  char input;
  bool flag = flase;
  Score score("../high_scores.txt"); //start it in a thread
  std::thread t = std::thread(&Score::Data, score); 
  
  while (play_again)
  {
      std::cout << "Enter Your Name: \n";
      std::cin >> name;

      Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
      Controller controller;
      Game game(kGridWidth, kGridHeight);
      game.Run(controller, renderer, kMsPerFrame);
      renderer.Destroy();
      if (!flag)
      {
        t.join();
        flag = true;
      }
      score.Add_score(name, game.GetScore());
      score.Write();
      score.Print_scores();
      std::cout << "Press y if you want to play again\n";
      std::cin >> input;
      if (input == 'y') continue;
      else
      {
          play_again = false;
      }
  }
  
  return 0;
}
