#include "translator/lib.h"
#include "sbl/tree.cpp"

P gmap;

int randx;
int turn;
int fruitbonus;

int h;
int w;

int randomv;

P boardtree;

int mod(int a, int b){
	int c;
	c = a / b;
	return a - b * c;
}



int myrand(){
	randx = mod(randx * 163 + 43751, 1000033);
	return randx;
}

int getNumber2(int x, P map){
	int ret;
	if(x == 0){
		ret = toi(fst(map));
	}
	else{
		ret = getNumber2(x - 1, snd(map));
	}
	return ret;
}

int getNumber(int y, int x, P map){
	int ret;
	ret = toi(read_tree2d(boardtree, y, x));
	return ret;
}

int getNumberold(int y, int x, P map){
	int ret;

	if(y == 0){
		ret = getNumber2(x, fst(map));
	}
	else
	{
		ret = getNumber(y - 1, x, snd(map));
	}
	return ret;
}

int getPoint(int y, int x){
	int ret;
	ret = getNumber(y, x, gmap);
	if(ret == 0){
		ret = -1;
	}
	else{
		if(ret == 1){
			ret = 0;
		}
		else{
			if(ret == 2){
				ret = 30;
			}
			else{
				if(ret == 3){
					ret = 200;
				}
				else{
					if(ret == 4){
						ret = fruitbonus;
					}
					else{
						ret = 0;
					}
				}
			}
		}
	}
	return ret;
}

int powdiv(int a, int mul, int div){
	int ret;
	if(a == 0){
		ret = 1;
	}
	else{
		ret = powdiv(a - 1, mul, div) * mul / div;
	}
	return ret;
}

int getLength(P a){
	int ret;
	if(atom(a)) {
		ret = 0;
	}
	else{
		ret = getLength(snd(a));
	}
	return ret;
}


int pow(int a, int b){
	int ret;
	if(a == 0){
		ret = 1;
	}
	else{
		ret = b * pow(a - 1, b);
	}
	return ret;
}

int pow2(int a){
	int ret;
	if(a <= 0){
		ret = 1;
	}
	else{
		ret = 2 * pow2(a - 1);
	}
	return ret;
}

int dfs(int y, int x, int depth, int predirection){
	int ret;
	int gp;
	ret = 0;
	if(depth > 0 - 1){
		gp = getPoint(y, x);
		if(gp > 0 - 1){
			ret = ret + gp * pow2(depth);
			if(predirection == 2){}
			else
			{
				ret = ret + dfs(y - 1, x, depth - 1, 0);
			}
			if(predirection == 3){}
			else
			{
				ret = ret + dfs(y, x + 1, depth - 1, 1);
			}
			if(predirection == 0){}
			else
			{
				ret = ret + dfs(y + 1, x, depth - 1, 2);
			}
			if(predirection == 1){}
			else
			{
				ret = ret + dfs(y, x - 1, depth - 1, 3);
			}

		}
		else{}
	}
	else{}
	return ret;
}

int abs(int a){
	int ret;
	if(a < 0){
		ret = 0 - a;
	}
	else{
		ret = a;
	}
	return ret;
}

int sign(int a){
	int ret;
	if(a < 0){
		ret = 0 - 1;
	}
	else{
		if(a > 0){
			ret = 1;
		}
		else{
			ret = 0;
		}
	}
	return ret;
}

P getfarpoint2(int y, int x, P map, int ly, int lx){
	P ret;
	P temp;
	int point;

	ret = P(0, 0);
	if(atom(map)){}
	else{
		point = getPoint(y, x) / 10;
		//point = 0;
		ret = P(point * sign(y - ly), point * sign(x - lx));
		temp = getfarpoint2(y, x + 1, snd(map), ly, lx);
		ret = P(toi(fst(ret)) + toi(fst(temp)), toi(snd(ret)) + toi(snd(temp)));
	}
	return ret;
}


P getfarpoint(int y, int x, P map, int ly, int lx){
	P ret;
	P temp;
	ret = P(0, 0);
	if(atom(map)){}
	else{
		ret = getfarpoint2(y, x, fst(map), ly, lx);
		temp = getfarpoint(y + 1, x, snd(map), ly, lx);
		ret = P(toi(fst(ret)) + toi(fst(temp)), toi(snd(ret)) + toi(snd(temp)));
	}
	return ret;
}


// step
P step2(P ai, P game) {
	P map;

	P game2;

	P lambdaman;
	int vitality;
	P lambdaman2;
	P lambdalocation;
	int lambdax;
	int lambday;
	P lambdaman3;
	int lambdadirection;
	P lambdaman4;
	int lambdalive;
	int lambdascore;

	int ghostlength;
	int moremul;

	P game3;
	P ghosts;

	P tempghost;
	int ghostvitality;
	P ghostlocation;
	int ghosty;
	int ghostx;
	int ghostdirection;

	int ghostdist;
	int ghostdist2;
	int ghostpoint;

	P fruits;

	int uppoint;
	int rightpoint;
	int downpoint;
	int leftpoint;

	int maxpoint;

	int retdirection;

	int ghostmul;

	int fruittime;

	int dfsdepth;

	P farpoint;

	turn = turn + 1;

	uppoint = 0;
	rightpoint = 0;
	downpoint = 0;
	leftpoint = 0;

	maxpoint = 0 - 99999999;
	retdirection = 0;

	map = fst(game);
	gmap = map;

	boardtree = list2d_to_tree2d(map);

	

	//list_to_tree(game);

	game2 = snd(game);
	lambdaman = fst(game2);
	game3 = snd(game2);
	ghosts = fst(game3);
	fruits = snd(game3);

	fruitbonus = 0;

	fruittime = toi(fruits);
	if(fruittime > 0){
		fruitbonus = 1000;
	}
	else{}

	debug(fruittime);

	vitality = toi(fst(lambdaman));
	lambdaman2 = snd(lambdaman);
	lambdalocation = fst(lambdaman2);
	lambdax = toi(fst(lambdalocation));
	lambday = toi(snd(lambdalocation));
	lambdaman3 = snd(lambdaman2);
	lambdadirection = toi(fst(lambdaman3));
	lambdaman4 = snd(lambdaman3);
	lambdalive = toi(fst(lambdaman4));
	lambdascore = toi(snd(lambdaman4));

	dfsdepth = 12;
	if(h * w > 2000){
		dfsdepth = 8;
	}
	else{}
	moremul = pow2(dfsdepth - 8);

	uppoint = dfs(lambday - 1, lambdax, dfsdepth, 0) * 10;
	rightpoint = dfs(lambday, lambdax + 1, dfsdepth, 1) * 10;
	downpoint = dfs(lambday + 1, lambdax, dfsdepth, 2) * 10;
	leftpoint = dfs(lambday, lambdax - 1, dfsdepth, 3) * 10;

	if(getNumber(lambday - 1,lambdax, map) == 0){
		uppoint = 0 - 99999999;
	}
	else{}
	
	if(getNumber(lambday,lambdax + 1, map) == 0){
		rightpoint = 0 - 99999999;
	}
	else{}
	
	if(getNumber(lambday + 1,lambdax, map) == 0){
		downpoint = 0 - 99999999;
	}
	else{}
	
	if(getNumber(lambday,lambdax - 1, map) == 0){
		leftpoint = 0 - 99999999;
	}
	else{}

	//farpoint = P(0,0);
	//farpoint = getfarpoint(0, 0, map, lambday, lambdax);

	//uppoint = uppoint + toi(fst(farpoint));
	//rightpoint = rightpoint - toi(snd(farpoint));
	//downpoint = downpoint - toi(fst(farpoint));
	//leftpoint = leftpoint + toi(snd(farpoint));

	//ghostlength = 2 + mod(turn / 5, 13);
	ghostlength = 4;

	if(mod(myrand(), 10) == 0){
		randomv = mod(myrand(), 10);
	}

	if(randomv == 0){
		uppoint = uppoint + 1000;
	}
	else{}
	if(randomv == 1){
		rightpoint = rightpoint + 1000;
	}
	else{}
	if(randomv == 2){
		downpoint = downpoint + 1000;
	}
	else{}
	if(randomv == 3){
		leftpoint = leftpoint + 1000;
	}
	else{}


	while(1 - atom(ghosts)){
			tempghost = fst(ghosts);
		ghosts = snd(ghosts);
			ghostvitality = toi(fst(tempghost));
		tempghost = snd(tempghost);
			ghostlocation = fst(tempghost);
			ghostx = toi(fst(ghostlocation));
		ghosty = toi(snd(ghostlocation));
		ghostdirection = toi(snd(tempghost));
	
		ghostdist = abs(lambdax - ghostx) + abs(lambday - ghosty);

		if(ghostdist < (vitality / 127 - 3) * 2){
			if(ghostvitality == 2){
				ghostmul = 0;
			}
			else{
				ghostmul = -1;
			}
		}
		else{
			ghostmul = 1;
		}

		if(ghostdist < ghostlength){
			ghostpoint = 1000000 * ghostlength / pow2(ghostdist) * ghostmul * moremul;
		}
		else{
			ghostpoint = 0;
		}
	
		uppoint = uppoint - ghostpoint * sign(lambday - ghosty);
		rightpoint = rightpoint + ghostpoint * sign(lambdax - ghostx);
		downpoint = downpoint + ghostpoint * sign(lambday - ghosty);
		leftpoint = leftpoint - ghostpoint * sign(lambdax - ghostx);
	}

	if(maxpoint < uppoint){
		retdirection = 0;
		maxpoint = uppoint;
	}
	else{}
	if(maxpoint < rightpoint){
		retdirection = 1;
		maxpoint = rightpoint;
	}
	else{}
	if(maxpoint < downpoint){
		retdirection = 2;
		maxpoint = downpoint;
	}
	else{}
	if(maxpoint < leftpoint){
		retdirection = 3;
		maxpoint = leftpoint;
	}
	else{}



	return P(P(retdirection, 0), retdirection);
}

P init(P game, P nazo) {
	h = getLength(fst(game));
	w = getLength(fst(fst(game)));
	randx = 123456;
	turn = 0;
	randomv = 5;
	return P(0, 0);
}


P step(P ai, P game) {
	return step2(ai, game);
}

