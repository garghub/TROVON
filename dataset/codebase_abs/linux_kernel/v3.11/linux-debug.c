void F_1 ( char * V_1 )
{
char * V_2 [ 3 ] ;
int V_3 ;
char * V_4 [] = {
L_1 ,
L_2 ,
NULL } ;
V_5 ;
V_2 [ 0 ] = V_6 ;
F_2 ( V_1 != NULL , L_3 ) ;
V_2 [ 1 ] = V_1 ;
V_2 [ 2 ] = NULL ;
V_3 = F_3 ( V_2 [ 0 ] , V_2 , V_4 ) ;
if ( V_3 < 0 && V_3 != - V_7 ) {
F_4 ( L_4
L_5 ,
V_3 , V_2 [ 0 ] , V_2 [ 1 ] ) ;
} else {
F_5 ( V_8 , L_6 ,
V_2 [ 0 ] , V_2 [ 1 ] ) ;
}
EXIT ;
}
void F_6 ( char * * V_2 )
{
int V_3 ;
int V_9 ;
char * V_4 [] = {
L_1 ,
L_2 ,
NULL } ;
V_5 ;
V_2 [ 0 ] = V_10 ;
V_9 = 1 ;
while ( V_2 [ V_9 ] != NULL )
V_9 ++ ;
F_7 ( V_9 >= 2 ) ;
V_3 = F_3 ( V_2 [ 0 ] , V_2 , V_4 ) ;
if ( V_3 < 0 && V_3 != - V_7 ) {
F_4 ( L_7
L_8 ,
V_3 , V_2 [ 0 ] , V_2 [ 1 ] ,
V_9 < 3 ? L_9 : L_10 , V_9 < 3 ? L_9 : V_2 [ 2 ] ,
V_9 < 4 ? L_9 : L_10 , V_9 < 4 ? L_9 : V_2 [ 3 ] ,
V_9 < 5 ? L_9 : L_10 , V_9 < 5 ? L_9 : V_2 [ 4 ] ,
V_9 < 6 ? L_9 : L_11 ) ;
} else {
F_5 ( V_8 , L_12 ,
V_2 [ 0 ] , V_2 [ 1 ] ,
V_9 < 3 ? L_9 : L_10 , V_9 < 3 ? L_9 : V_2 [ 2 ] ,
V_9 < 4 ? L_9 : L_10 , V_9 < 4 ? L_9 : V_2 [ 3 ] ,
V_9 < 5 ? L_9 : L_10 , V_9 < 5 ? L_9 : V_2 [ 4 ] ,
V_9 < 6 ? L_9 : L_11 ) ;
}
}
void F_8 ( struct V_11 * V_12 )
{
char * V_2 [ 6 ] ;
char V_13 [ 32 ] ;
V_5 ;
snprintf ( V_13 , sizeof V_13 , L_13 , V_12 -> V_14 ) ;
V_2 [ 1 ] = L_14 ;
V_2 [ 2 ] = ( char * ) V_12 -> V_15 ;
V_2 [ 3 ] = ( char * ) V_12 -> V_16 ;
V_2 [ 4 ] = V_13 ;
V_2 [ 5 ] = NULL ;
F_6 ( V_2 ) ;
}
void F_9 ( struct V_11 * V_12 )
{
V_17 = 1 ;
F_10 ( V_12 , L_15 ) ;
if ( F_11 () ) {
F_12 ( L_16 ) ;
}
F_13 ( NULL ) ;
if ( ! V_18 )
F_14 () ;
F_8 ( V_12 ) ;
if ( V_18 )
F_12 ( L_14 ) ;
F_15 ( V_19 , V_20 ) ;
while ( 1 )
F_16 () ;
}
static int F_17 ( void * V_21 , char * V_22 )
{
F_18 ( L_17 , V_22 ) ;
return 0 ;
}
static void F_19 ( void * V_21 , unsigned long V_23 , int V_24 )
{
char V_25 [ 32 ] ;
F_20 () ;
sprintf ( V_25 , L_18 , V_23 , V_26 ? L_9 : L_19 ) ;
F_21 ( V_25 , V_23 ) ;
}
void F_13 ( struct V_27 * V_28 )
{
if ( V_28 == NULL )
V_28 = V_19 ;
F_18 ( L_20 , V_28 -> V_29 , V_28 -> V_30 ) ;
F_18 ( L_21 ) ;
F_22 ( V_28 , NULL , NULL ,
0 ,
& V_31 , NULL ) ;
F_18 ( L_22 ) ;
}
T_1 * F_23 ( void )
{
F_24 ( L_23 , V_19 ) ;
return V_19 ;
}
static int F_25 ( struct V_32 * V_33 , unsigned long V_34 ,
void * V_35 )
{
if ( V_36 )
return 0 ;
V_36 = 1 ;
F_26 () ;
return 0 ;
}
void F_27 ( void )
{
F_28 ( & V_37 , & V_38 ) ;
}
void F_29 ( void )
{
F_30 ( & V_37 , & V_38 ) ;
}
