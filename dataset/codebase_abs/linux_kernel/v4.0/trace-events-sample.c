static void F_1 ( int V_1 )
{
int V_2 [ 6 ] ;
int V_3 = V_1 % 5 ;
int V_4 ;
F_2 ( V_5 ) ;
F_3 ( V_6 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_2 [ V_4 ] = V_4 + 1 ;
V_2 [ V_4 ] = 0 ;
F_4 ( L_1 , V_1 , V_2 , V_7 [ V_3 ] ,
F_5 ( V_8 ) ) ;
F_6 ( L_2 , V_1 ) ;
F_7 ( L_3 , V_1 ) ;
F_8 ( L_4 , V_1 ) ;
F_9 ( L_5 , V_1 ) ;
}
static int F_10 ( void * V_9 )
{
int V_1 = 0 ;
while ( ! F_11 () )
F_1 ( V_1 ++ ) ;
return 0 ;
}
static void F_12 ( int V_1 )
{
F_2 ( V_5 ) ;
F_3 ( V_6 ) ;
F_13 ( L_6 , V_1 ) ;
F_14 ( L_7 , V_1 ) ;
}
static int F_15 ( void * V_9 )
{
int V_1 = 0 ;
while ( ! F_11 () )
F_12 ( V_1 ++ ) ;
return 0 ;
}
void F_16 ( void )
{
F_17 ( L_8 ) ;
F_18 ( & V_10 ) ;
V_11 = F_19 ( F_15 , NULL , L_9 ) ;
F_20 ( & V_10 ) ;
}
void F_21 ( void )
{
F_17 ( L_10 ) ;
F_18 ( & V_10 ) ;
if ( V_11 )
F_22 ( V_11 ) ;
V_11 = NULL ;
F_20 ( & V_10 ) ;
}
static int T_1 F_23 ( void )
{
V_12 = F_19 ( F_10 , NULL , L_11 ) ;
if ( F_24 ( V_12 ) )
return - 1 ;
return 0 ;
}
static void T_2 F_25 ( void )
{
F_22 ( V_12 ) ;
F_18 ( & V_10 ) ;
if ( V_11 )
F_22 ( V_11 ) ;
V_11 = NULL ;
F_20 ( & V_10 ) ;
}
