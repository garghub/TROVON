void F_1 ( char * V_1 )
{
char * V_2 [ 3 ] ;
int V_3 ;
char * V_4 [] = {
L_1 ,
L_2 ,
NULL } ;
V_2 [ 0 ] = V_5 ;
F_2 ( V_1 != NULL , L_3 ) ;
V_2 [ 1 ] = V_1 ;
V_2 [ 2 ] = NULL ;
V_3 = F_3 ( V_2 [ 0 ] , V_2 , V_4 , 1 ) ;
if ( V_3 < 0 && V_3 != - V_6 ) {
F_4 ( L_4 ,
V_3 , V_2 [ 0 ] , V_2 [ 1 ] ) ;
} else {
F_5 ( V_7 , L_5 ,
V_2 [ 0 ] , V_2 [ 1 ] ) ;
}
}
void F_6 ( char * * V_2 )
{
int V_3 ;
int V_8 ;
char * V_4 [] = {
L_1 ,
L_2 ,
NULL } ;
V_2 [ 0 ] = V_9 ;
V_8 = 1 ;
while ( V_2 [ V_8 ] != NULL )
V_8 ++ ;
F_7 ( V_8 >= 2 ) ;
V_3 = F_3 ( V_2 [ 0 ] , V_2 , V_4 , 1 ) ;
if ( V_3 < 0 && V_3 != - V_6 ) {
F_4 ( L_6 ,
V_3 , V_2 [ 0 ] , V_2 [ 1 ] ,
V_8 < 3 ? L_7 : L_8 , V_8 < 3 ? L_7 : V_2 [ 2 ] ,
V_8 < 4 ? L_7 : L_8 , V_8 < 4 ? L_7 : V_2 [ 3 ] ,
V_8 < 5 ? L_7 : L_8 , V_8 < 5 ? L_7 : V_2 [ 4 ] ,
V_8 < 6 ? L_7 : L_9 ) ;
} else {
F_5 ( V_7 , L_10 ,
V_2 [ 0 ] , V_2 [ 1 ] ,
V_8 < 3 ? L_7 : L_8 , V_8 < 3 ? L_7 : V_2 [ 2 ] ,
V_8 < 4 ? L_7 : L_8 , V_8 < 4 ? L_7 : V_2 [ 3 ] ,
V_8 < 5 ? L_7 : L_8 , V_8 < 5 ? L_7 : V_2 [ 4 ] ,
V_8 < 6 ? L_7 : L_9 ) ;
}
}
void F_8 ( struct V_10 * V_11 )
{
char * V_2 [ 6 ] ;
char V_12 [ 32 ] ;
snprintf ( V_12 , sizeof( V_12 ) , L_11 , V_11 -> V_13 ) ;
V_2 [ 1 ] = L_12 ;
V_2 [ 2 ] = ( char * ) V_11 -> V_14 ;
V_2 [ 3 ] = ( char * ) V_11 -> V_15 ;
V_2 [ 4 ] = V_12 ;
V_2 [ 5 ] = NULL ;
F_6 ( V_2 ) ;
}
void F_9 ( struct V_10 * V_11 )
{
V_16 = 1 ;
F_10 ( V_11 , L_13 ) ;
if ( F_11 () ) {
F_12 ( L_14 ) ;
}
F_13 () ;
if ( ! V_17 )
F_14 () ;
F_8 ( V_11 ) ;
if ( V_17 )
F_12 ( L_12 ) ;
F_15 ( V_18 , V_19 ) ;
while ( 1 )
F_16 () ;
}
static int F_17 ( struct V_20 * V_21 , unsigned long V_22 ,
void * V_23 )
{
if ( V_24 )
return 0 ;
V_24 = 1 ;
F_18 () ;
return 0 ;
}
void F_19 ( void )
{
F_20 ( & V_25 , & V_26 ) ;
}
void F_21 ( void )
{
F_22 ( & V_25 , & V_26 ) ;
}
