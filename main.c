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
    
    int location = 0;
    int count = 0;
    int ids[n];
    for(int a = 1; a<=n; a++){
        for(int j = 1; j<=n; j++){
            if(a!=j&&pieces[a].rank == pieces[j].rank){
                ids[count] = pieces[j].id;
                count++;
            }
            if(a!=j&&pieces[a].file == pieces[j].file){
                ids[count] = pieces[j].id;
                count++;
            }
        }
        printf("%d\t",count);
        for(int b = 0; b<count; b++){
            printf("%d ",ids[b]);
        }
        printf("\n");
        count = 0;
        ids[n] = 0;
        
    }
    
    return 0;
}


