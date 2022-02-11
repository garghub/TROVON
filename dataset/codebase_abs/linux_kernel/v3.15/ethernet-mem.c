static int F_1 ( int V_1 , int V_2 , int V_3 )
{
int V_4 = V_3 ;
while ( V_4 ) {
struct V_5 * V_6 = F_2 ( V_2 + 256 ) ;
if ( F_3 ( V_6 == NULL ) )
break;
F_4 ( V_6 , 256 - ( ( ( unsigned long ) V_6 -> V_7 ) & 0x7f ) ) ;
* (struct V_5 * * ) ( V_6 -> V_7 - sizeof( void * ) ) = V_6 ;
F_5 ( V_6 -> V_7 , V_1 , F_6 ( V_2 / 128 ) ) ;
V_4 -- ;
}
return V_3 - V_4 ;
}
static void F_7 ( int V_1 , int V_2 , int V_3 )
{
char * V_8 ;
do {
V_8 = F_8 ( V_1 ) ;
if ( V_8 ) {
struct V_5 * V_6 =
* (struct V_5 * * ) ( V_8 - sizeof( void * ) ) ;
V_3 -- ;
F_9 ( V_6 ) ;
}
} while ( V_8 );
if ( V_3 < 0 )
F_10 ( L_1 ,
V_1 , V_3 ) ;
else if ( V_3 > 0 )
F_10 ( L_2 ,
V_1 , V_3 ) ;
}
static int F_11 ( int V_1 , int V_2 , int V_3 )
{
char * V_8 ;
char * V_9 ;
int V_4 = V_3 ;
while ( V_4 ) {
V_8 = F_12 ( V_2 + 256 , V_10 ) ;
if ( F_3 ( V_8 == NULL ) ) {
F_10 ( L_3 ,
V_3 * V_2 , V_1 ) ;
break;
}
V_9 = ( char * ) ( ( ( unsigned long ) V_8 + 256 ) & ~ 0x7fUL ) ;
* ( ( char * * ) V_9 - 1 ) = V_8 ;
F_5 ( V_9 , V_1 , 0 ) ;
V_4 -- ;
}
return V_3 - V_4 ;
}
static void F_13 ( int V_1 , int V_2 , int V_3 )
{
char * V_8 ;
char * V_9 ;
do {
V_9 = F_8 ( V_1 ) ;
if ( V_9 ) {
V_3 -- ;
V_9 = ( char * ) F_14 ( F_15 ( V_9 ) ) ;
V_8 = * ( ( char * * ) V_9 - 1 ) ;
F_16 ( V_8 ) ;
}
} while ( V_9 );
if ( V_3 < 0 )
F_10 ( L_4 ,
V_1 , V_3 ) ;
else if ( V_3 > 0 )
F_10 ( L_5 ,
V_1 , V_3 ) ;
}
int F_17 ( int V_1 , int V_2 , int V_3 )
{
int V_4 ;
if ( V_11 && V_1 == V_12 )
V_4 = F_1 ( V_1 , V_2 , V_3 ) ;
else
V_4 = F_11 ( V_1 , V_2 , V_3 ) ;
return V_4 ;
}
void F_18 ( int V_1 , int V_2 , int V_3 )
{
if ( V_11 && V_1 == V_12 )
F_7 ( V_1 , V_2 , V_3 ) ;
else
F_13 ( V_1 , V_2 , V_3 ) ;
}
