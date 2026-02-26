using System;

class GameSuite
{
	static void Main(string[] args)
	{
		bool running = true;
		while (running)
		{
			
			Console.WriteLine("--- MULTI-GAME CONSOLE SUITE ---");
			Console.WriteLine("------------------------------------");
			Console.WriteLine("1. Naughts and Crosses (PvP)");
			Console.WriteLine("------------------------------------");
			Console.WriteLine("2. Rock, Paper, Scissors (PvC)");
			Console.WriteLine("------------------------------------");
			Console.WriteLine("3. Black Jack (PvC)");
			Console.WriteLine("------------------------------------");
			Console.WriteLine("4. Exit");
			Console.Write("\nSelect an option: ");
			string choice = Console.ReadLine();
			switch (choice)
			{
				case "1":
					PlayNC();
					break;
				case "2":
					PlayRPS();
					break;
				case "3":
					PlayBJ();
					break;
				case "4":
					running = false;
					break;
				default:
					Console.WriteLine("Invalid selection. Press any key to try again.");
					Console.ReadKey();
					break;
			}
		}
	}

	static void PlayNC()
	{
		string[, ] columns =
		{
			{"-","-","-"},
			{"-","-","-"},
			{"-","-","-"}
		};
		
		bool playing = true;
		int player = 1;
		string sign = "X";
		
		while (playing) {
			string res = "";
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					res += "|" + columns[i, j] + "|";
				}
				res += "\n";
			}
			Console.WriteLine(res);
			
			Console.Write("\nSelections: 1.1, 1.2, 1.3 (Top Row)");
			Console.Write("\nSelections: 2.1, 2.2, 2.3 (Mid Row)");
			Console.Write("\nSelections: 3.1, 3.2, 3.3 (Bottom Row)");
			Console.Write("\nAny Key to Exit");
			Console.Write("\nPlayer" + player + " selecting " + sign + ": ");
			string choice = Console.ReadLine();
			bool goodinput = true;
			switch (choice)
			{
				case "1.1": 
					goodinput = moveEval(0, 0, sign);
					playing = winEval();
					break;
				case "1.2":
					goodinput = moveEval(0, 1, sign);
					playing = winEval();
					break;
				case "1.3":
					goodinput = moveEval(0, 2, sign);
					playing = winEval();
					break;
				case "2.1":
					goodinput = moveEval(1, 0, sign);
					playing = winEval();
					break;
				case "2.2":
					goodinput = moveEval(1, 1, sign);
					playing = winEval();
					break;	
				case "2.3":
					goodinput = moveEval(1, 2, sign);
					playing = winEval();
					break;	
				case "3.1":
					goodinput = moveEval(2, 0, sign);
					playing = winEval();
					break;		
				case "3.2":
					goodinput = moveEval(2, 1, sign);
					playing = winEval();
					break;	
				case "3.3":
					goodinput = moveEval(2, 2, sign);
					playing = winEval();
					break;	
					
				default:
					Console.WriteLine("Invalid selection - exiting.");
					playing = false;
					return;
					
			}
			if (goodinput) {
				if (player == 1) {
					player = 2;
					sign = "O";
				} else {
					player = 1; 
					sign = "X";
				}
			}
		}

		 bool moveEval(int X, int Y, string Lsign){
			if (columns[X,Y] == "-") {
				columns[X,Y] = Lsign;
				return true;
			} else {
				Console.Write("\nInvalid input, PLEASE SELECT AGAIN\n");
				return false;
			}
		}
		
		bool winEval() {
			bool play = true;
			string[] marklist = {"X", "O"};
			string winner = "";
			foreach (string mark in marklist){
				winner = mark;
				if ((columns[0,0] == mark) && (columns[0,1] == mark) && (columns[0,2] == mark) ) {
					play = false;
					break;
				}else if ((columns[1,0] == mark) && (columns[1,1] == mark) && (columns[1,2] == mark) ){
					play = false;
					break;
				}else if ((columns[2,0] == mark) && (columns[2,1] == mark) && (columns[2,2] == mark) ){
					play = false;
					break;
				}else if ((columns[0,0] == mark) && (columns[1,0] == mark) && (columns[2,0] == mark) ){
					play = false;
					break;
				}else if ((columns[1,0] == mark) && (columns[1,1] == mark) && (columns[2,1] == mark) ){
					play = false;
					break;
				}else if ((columns[0,2] == mark) && (columns[1,2] == mark) && (columns[2,2] == mark) ){
					play = false;
					break;
				}else if ((columns[0,0] == mark) && (columns[1,1] == mark) && (columns[2,2] == mark) ){
					play = false;
					break;
				}else if ((columns[0,2] == mark) && (columns[1,1] == mark) && (columns[2,0] == mark) ){
					play = false;
					break;
				}
			}
			if (play == false ){
				Console.Write("\n\nPlayer "+winner+" wins\n\n"); 
				Console.Write("\nAny Key to Exit\n");
				Console.ReadLine();
			}
			
			return play;
		}
	}

	static void PlayBJ()
	
	{
		Console.Write("! = Dimond\n");
		Console.Write("@ = Hearts\n");
		Console.Write("# = Clubs\n");
		Console.Write("$ = Spades\n");
		int playerComp = 0;
		int playerHum = 0;
		string[, ] cards =
		{
			{"A!","X","11"},
			{"2!","X","2"},
			{"3!","X","3"},
			{"4!","X","4"},
			{"5!","X","5"},
			{"6!","X","6"},
			{"7!","X","7"},
			{"8!","X","8"},
			{"9!","X","9"},
			{"10!","X","10"},
			{"J!","X","10"},
			{"Q!","X","10"},
			{"K!","X","10"},
			{"A@","X","11"},
			{"2@","X","2"},
			{"3@","X","3"},
			{"4@","X","4"},
			{"5@","X","5"},
			{"6@","X","6"},
			{"7@","X","7"},
			{"8@","X","8"},
			{"9@","X","9"},
			{"10@","X","10"},
			{"J@","X","10"},
			{"Q@","X","10"},
			{"K@","X","10"},
			{"A#","X","11"},
			{"2#","X","2"},
			{"3#","X","3"},
			{"4#","X","4"},
			{"5#","X","5"},
			{"6#","X","6"},
			{"7#","X","7"},
			{"8#","X","8"},
			{"9#","X","9"},
			{"10#","X","10"},
			{"J#","X","10"},
			{"Q#","X","10"},
			{"K#","X","10"},
			{"A$","X","11"},
			{"2$","X","2"},
			{"3$","X","3"},
			{"4$","X","4"},
			{"5$","X","5"},
			{"6$","X","6"},
			{"7$","X","7"},
			{"8$","X","8"},
			{"9$","X","9"},
			{"10$","X","10"},
			{"J$","X","10"},
			{"Q$","X","10"},
			{"K$","X","10"}
		};
		
		playerComp = playerComp + randomCard();
		playerComp = playerComp + randomCard();
		Console.WriteLine("Computer points after dealing " + playerComp);
		
		playerHum = playerHum + randomCard();
		playerHum = playerHum + randomCard();
		Console.WriteLine("Player points after dealing " + playerHum);
		
		bool playing = true;
		while (playing) {
			if (playerHum > 21){
				Console.Write("Dealer Won!\n");
				Console.ReadLine();
				playing = false;
				return;
				
			}
			else if (playerComp > 21) {
				Console.Write("Player Won!\n");
				Console.ReadLine();
				playing = false;
				return;
			}
			else if (playerHum == 21){
				Console.Write("Player Won!\n");
				Console.ReadLine();
				playing = false;
				return;
			}
			else if (playerComp == 21) {
				Console.Write("Dealer Won!\n");
				Console.ReadLine();
				playing = false;
				return;
			}
			
			if (playerComp < 16){
				playerComp = playerComp + randomCard();
				Console.WriteLine("Computer points " + playerComp);
				if (playerComp > 21) {
					Console.Write("Player Won!\n");
					Console.ReadLine();
					playing = false;
					return;
				}
			}
			
			if (playerHum < 21){
				Console.Write("\nDo you want to hit? h to hit and s to stop: ");
				string hit = Console.ReadLine();
				if (hit == "h"){
					playerHum = playerHum + randomCard();
				} else if (hit == "s") {
					if (playerComp > playerHum) {
						Console.Write("Dealer Won!\n");
						Console.ReadLine();
						playing = false;
						return;
					} else {
						Console.Write("Player Won!\n");
						Console.ReadLine();
						playing = false;
						return;
					}
				}
			}
			
			Console.Write(playerComp + " - current dealer points\n");
			Console.Write(playerHum + " - current player points\n");
			return;
		}
	
		int randomCard()
		{
			Random rand = new Random();
			bool cardNotChosen = true;
			int cardValue = 0;
			while (cardNotChosen){
				int randomValue = rand.Next(0, 51);
				if (cards [randomValue, 1] == "X"){
					cards[randomValue , 1] = "O";
					Console.Write(cards[randomValue, 0] + " ");
					Console.Write(cards[randomValue, 2] + "\n");
					cardValue = Convert.ToInt32(cards[randomValue, 2]);
					cardNotChosen = false;
				
				}
				
			}
			return cardValue;
		}
		
	}

	static void PlayRPS()
	{
		while (true)
		{
			int userInput;
			Console.WriteLine("Press 1 for Rock, 2 for Paper, and 3 for scissors");
			int.TryParse(Console.ReadLine(), out userInput);
			Console.WriteLine($"The player chose {userInput}");
			int computerInput = randomNumberGenerator();
			Console.WriteLine($"The computer chose {computerInput}");
			if (computerInput == userInput)
			{
				Console.WriteLine("It's a draw!");
			}
			else if (computerInput == 1 && userInput == 2)
			{
				Console.WriteLine("Player wins!");
			}
			else if (computerInput == 2 && userInput == 1)
			{
				Console.WriteLine("Player loses!");
			}
			else if (computerInput == 3 && userInput == 1)
			{
				Console.WriteLine("Player loses!");
			}
			else if (computerInput == 1 && userInput == 3)
			{
				Console.WriteLine("Player wins!");
			}
			else if (computerInput == 2 && userInput == 3)
			{
				Console.WriteLine("Player loses!");
			}
			else if (computerInput == 3 && userInput == 2)
			{
				Console.WriteLine("Player wins!");
			}
			else
			{
				Console.WriteLine("Please input a valid number or 0 to exit the game");
				Environment.ExitCode = 0;
				return;
			}
		}
	}

	static int randomNumberGenerator()
	{
		Random rand = new Random();
		int randomValue = rand.Next(1, 4);
		return randomValue;
	}
}
