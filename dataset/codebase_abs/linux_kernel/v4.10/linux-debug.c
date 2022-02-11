void F_1 ( char * V_1 )
{
char * V_2 [ 3 ] ;
int V_3 ;
static const char * const V_4 [] = {
L_1 ,
L_2 ,
NULL
} ;
V_2 [ 0 ] = V_5 ;
F_2 ( V_1 , L_3 ) ;
V_2 [ 1 ] = V_1 ;
V_2 [ 2 ] = NULL ;
V_3 = F_3 ( V_2 [ 0 ] , V_2 , ( char * * ) V_4 , 1 ) ;
if ( V_3 < 0 && V_3 != - V_6 ) {
F_4 ( L_4 ,
V_3 , V_2 [ 0 ] , V_2 [ 1 ] ) ;
} else {
F_5 ( V_7 , L_5 ,
V_2 [ 0 ] , V_2 [ 1 ] ) ;
}
}
void T_1 F_6 ( struct V_8 * V_9 )
{
V_10 = 1 ;
F_7 ( V_9 , L_6 ) ;
if ( F_8 () ) {
F_9 ( L_7 ) ;
}
F_10 () ;
if ( ! V_11 )
F_11 () ;
if ( V_11 )
F_9 ( L_8 ) ;
F_12 ( V_12 , V_13 ) ;
while ( 1 )
F_13 () ;
}
static int F_14 ( struct V_14 * V_15 , unsigned long V_16 ,
void * V_17 )
{
if ( V_18 )
return 0 ;
V_18 = 1 ;
F_15 () ;
return 0 ;
}
void F_16 ( void )
{
F_17 ( & V_19 ,
& V_20 ) ;
}
void F_18 ( void )
{
F_19 ( & V_19 ,
& V_20 ) ;
}
