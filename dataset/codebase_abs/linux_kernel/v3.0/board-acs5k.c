static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_4 ,
void * V_5 )
{
static int V_6 [] = {
- 1 , - 1 , - 1 , - 1 , - 1 , - 1 , - 1 , 0 , 1 , 1 , - 1 , 0 , 1 , 0 , - 1 , - 1
} ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_2 ( V_6 ) ; ++ V_7 ) {
F_3 ( V_3 + V_7 , L_1 ) ;
if ( V_6 [ V_7 ] < 0 )
F_4 ( V_3 + V_7 ) ;
else
F_5 ( V_3 + V_7 ,
V_6 [ V_7 ] ) ;
F_6 ( V_3 + V_7 , 0 ) ;
}
return 0 ;
}
static void T_1 F_7 ( void )
{
F_8 ( & V_8 ) ;
F_9 ( 0 , V_9 ,
F_2 ( V_9 ) ) ;
}
static void T_2 F_10 ( void )
{
int V_10 ;
if ( V_11 [ 0 ] . V_12 == 0 )
F_11 ( V_13 L_2 ) ;
V_10 = F_8 ( & V_14 ) ;
if ( V_10 < 0 )
F_11 ( V_15 L_3 ) ;
}
static int T_2 F_12 ( char * V_16 )
{
if ( strcmp ( V_16 , L_4 ) == 0 )
V_11 [ 0 ] . V_12 = 0 ;
return 1 ;
}
static void T_2 F_13 ( void )
{
int V_17 ;
F_14 () ;
for ( V_17 = 0 ; V_17 < 4 ; ++ V_17 )
F_3 ( V_17 , L_5 ) ;
F_3 ( 7 , L_6 ) ;
for ( V_17 = 8 ; V_17 < 16 ; ++ V_17 )
F_3 ( V_17 , L_7 ) ;
F_3 ( 3 , L_8 ) ;
F_3 ( 6 , L_9 ) ;
F_5 ( 3 , 1 ) ;
F_5 ( 6 , 0 ) ;
F_6 ( 3 , 0 ) ;
F_6 ( 6 , 0 ) ;
}
static void T_2 F_15 ( void )
{
F_13 () ;
F_16 () ;
F_17 () ;
F_10 () ;
F_7 () ;
}
