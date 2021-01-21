#include <stdio.h>
#include <string.h>

struct rankArrayList
{
  int size, cap;
  struct rank *ranks;
};

struct rank
{
  int locaton;
  int num_pieces;
  int capacity;
  struct piece *array;
};

struct piece
{
  int rank, file, id;
};

void addPieceToBoard (struct rankArrayList *board, struct piece *newPiece);
void expandBoard (struct rankArrayList *board);
void cleanBoard (struct rankArrayList *board);
struct rankArrayList *createBoard();

void addPieceToRank (struct rank *rank, struct piece *newPiece);
void expandRank (struct rank *curRank);
void cleanRank (struct rank *curRank);
struct rank *createRank();

void addPieceToBoard (struct rankArrayList *board, struct piece *newPiece)
{

}

int main ()
{
    struct rankArrayList create;
    int n = 1;
    int r = 1;
    int f = 1;
    printf("Enter no of rooks: ");
    scanf("%d", &n);
    struct piece pieces[n];
    
    for(int i = 1; i<=n; i++){
        pieces[i].id = i;
        printf("Enter rank of rook %d : ",i);
        scanf("%d", &r);
        printf("Enter file of rook %d : ",i);
        scanf("%d", &f);
        pieces[i].rank = r;
        pieces[i].file = f;
    }
    int cFileP = 1;
    int cFileM = 2;
    int cRankP = 3;
    int cRankM = 4;
    int location = 0;
    int count = 0;
    int def = 0;
    int defP = 0;
    int defM = 0;
    int defP2 = 0;
    int defM2 = 0;
    int ids[n];
   
    for(int a = 1; a<=n; a++){
        ids[cFileP] = 0;
        ids[cFileM] = 0;
        ids[cRankP] = 0;
        ids[cRankM] = 0;
        defP = 0;
        defM = 0;
        defP2 = 0;
        defM2 = 0;
        
        
        for(int j = 1; j<=n; j++){
            if(a!=j&&pieces[a].rank == pieces[j].rank){
                def = pieces[a].file - pieces[j].file; 
                if(def>0){
                    if(defP>def||defP==0){
                        ids[cFileP] = pieces[j].id;
                        defP = def;
                    }
                }
                if(def<0){ 
                    if(defM<def||defM==0){  
                        ids[cFileM] = pieces[j].id;
                        defM = def;
                    }
                }
            }
            if(a!=j&&pieces[a].file == pieces[j].file){
                def = pieces[a].rank - pieces[j].rank;
                if(def>0){
                    if(defP2>def||defP2==0){
                        ids[cRankP] = pieces[j].id;
                        defP2 = def;
                    }
                }
                if(def<0){
                    if(defM2<def||defM2==0){
                        ids[cRankM] = pieces[j].id;
                        defM2 = def;
                    }
                }
            }
        }
        
        for(int b = 1; b<5; b++){
            if(ids[b] != 0){
                count++;
            }
        }
        printf("%d\t",count);
        for(int b = 1; b<5; b++){
            if(ids[b] != 0){
                printf("%d ",ids[b]);
            }
            
        }
        printf("\n");
        count = 0;
    }
    
    return 0;
}



