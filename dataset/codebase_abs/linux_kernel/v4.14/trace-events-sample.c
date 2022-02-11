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
& V_8 -> V_9 ) ;
F_5 ( L_2 , V_1 ) ;
F_6 ( L_3 , V_1 ) ;
F_7 ( L_4 , V_1 ) ;
F_8 ( L_5 , V_1 ) ;
}
static int F_9 ( void * V_10 )
{
int V_1 = 0 ;
while ( ! F_10 () )
F_1 ( V_1 ++ ) ;
return 0 ;
}
static void F_11 ( int V_1 )
{
F_2 ( V_5 ) ;
F_3 ( V_6 ) ;
F_12 ( L_6 , V_1 ) ;
F_13 ( L_7 , V_1 ) ;
}
static int F_14 ( void * V_10 )
{
int V_1 = 0 ;
while ( ! F_10 () )
F_11 ( V_1 ++ ) ;
return 0 ;
}
int F_15 ( void )
{
F_16 ( & V_11 ) ;
if ( V_12 ++ )
goto V_13;
F_17 ( L_8 ) ;
V_14 = F_18 ( F_14 , NULL , L_9 ) ;
V_13:
F_19 ( & V_11 ) ;
return 0 ;
}
void F_20 ( void )
{
F_16 ( & V_11 ) ;
if ( -- V_12 )
goto V_13;
F_17 ( L_10 ) ;
if ( V_14 )
F_21 ( V_14 ) ;
V_14 = NULL ;
V_13:
F_19 ( & V_11 ) ;
}
static int T_1 F_22 ( void )
{
V_15 = F_18 ( F_9 , NULL , L_11 ) ;
if ( F_23 ( V_15 ) )
return - 1 ;
return 0 ;
}
static void T_2 F_24 ( void )
{
F_21 ( V_15 ) ;
F_16 ( & V_11 ) ;
if ( V_14 )
F_21 ( V_14 ) ;
V_14 = NULL ;
F_19 ( & V_11 ) ;
}
