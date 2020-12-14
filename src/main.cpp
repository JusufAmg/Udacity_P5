#include <iostream>
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
  
  Score score("../high_scores.txt"); //start it in a thread
  if (!(score.Available()))
  {
    score.Create_file();
  } else 
  {
    score.Prev_Scores();
  }

  while (play_again)
  {
      std::cout << "Enter Your Name: \n";
      std::cin >> name;

      Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
      Controller controller;
      Game game(kGridWidth, kGridHeight);
      game.Run(controller, renderer, kMsPerFrame);

      score.Add_score(name, game.GetScore());
<<<<<<< HEAD
      
=======
      score.Write();
>>>>>>> fe27ab3caed47248b2843c52434b353707c9f71e
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
