void F_1 ( unsigned long V_1 , unsigned long * V_2 ,
unsigned long * V_3 )
{
DEFINE ( V_4 ) ;
DEFINE ( V_5 ) ;
unsigned long V_6 = V_1 / ( sizeof( V_7 ) ) / 4 ;
do {
F_2 ( V_4 ) ;
F_2 ( V_5 ) ;
F_3 ( V_4 , V_5 ) ;
F_4 ( V_4 ) ;
V_4 += 4 ;
V_5 += 4 ;
} while ( -- V_6 > 0 );
}
void F_5 ( unsigned long V_1 , unsigned long * V_2 ,
unsigned long * V_3 , unsigned long * V_8 )
{
DEFINE ( V_4 ) ;
DEFINE ( V_5 ) ;
DEFINE ( V_9 ) ;
unsigned long V_6 = V_1 / ( sizeof( V_7 ) ) / 4 ;
do {
F_2 ( V_4 ) ;
F_2 ( V_5 ) ;
F_2 ( V_9 ) ;
F_3 ( V_4 , V_5 ) ;
F_3 ( V_4 , V_9 ) ;
F_4 ( V_4 ) ;
V_4 += 4 ;
V_5 += 4 ;
V_9 += 4 ;
} while ( -- V_6 > 0 );
}
void F_6 ( unsigned long V_1 , unsigned long * V_2 ,
unsigned long * V_3 , unsigned long * V_8 ,
unsigned long * V_10 )
{
DEFINE ( V_4 ) ;
DEFINE ( V_5 ) ;
DEFINE ( V_9 ) ;
DEFINE ( V_11 ) ;
unsigned long V_6 = V_1 / ( sizeof( V_7 ) ) / 4 ;
do {
F_2 ( V_4 ) ;
F_2 ( V_5 ) ;
F_2 ( V_9 ) ;
F_2 ( V_11 ) ;
F_3 ( V_4 , V_5 ) ;
F_3 ( V_9 , V_11 ) ;
F_3 ( V_4 , V_9 ) ;
F_4 ( V_4 ) ;
V_4 += 4 ;
V_5 += 4 ;
V_9 += 4 ;
V_11 += 4 ;
} while ( -- V_6 > 0 );
}
void F_7 ( unsigned long V_1 , unsigned long * V_2 ,
unsigned long * V_3 , unsigned long * V_8 ,
unsigned long * V_10 , unsigned long * V_12 )
{
DEFINE ( V_4 ) ;
DEFINE ( V_5 ) ;
DEFINE ( V_9 ) ;
DEFINE ( V_11 ) ;
DEFINE ( V_13 ) ;
unsigned long V_6 = V_1 / ( sizeof( V_7 ) ) / 4 ;
do {
F_2 ( V_4 ) ;
F_2 ( V_5 ) ;
F_2 ( V_9 ) ;
F_2 ( V_11 ) ;
F_2 ( V_13 ) ;
F_3 ( V_4 , V_5 ) ;
F_3 ( V_9 , V_11 ) ;
F_3 ( V_4 , V_13 ) ;
F_3 ( V_4 , V_9 ) ;
F_4 ( V_4 ) ;
V_4 += 4 ;
V_5 += 4 ;
V_9 += 4 ;
V_11 += 4 ;
V_13 += 4 ;
} while ( -- V_6 > 0 );
}
