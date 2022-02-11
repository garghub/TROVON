static void T_1 F_1 ( void )
{
F_2 ( 200000000 ) ;
}
void T_1 F_3 ( void )
{
F_4 () ;
F_5 ( V_1 , F_6 ( V_1 ) ) ;
}
static int T_1
F_7 ( const struct V_2 * V_3 , T_2 V_4 , T_2 V_5 )
{
static int V_6 [] [ 4 ] = {
{ V_7 , V_7 , V_7 , V_7 } ,
{ V_8 , V_8 , V_8 , V_8 } ,
{ V_9 , V_9 , V_9 , V_9 } ,
{ V_10 , V_10 , V_10 , V_10 } ,
{ V_9 , V_8 , V_8 , V_8 } ,
{ V_9 , V_10 , V_8 , V_8 } ,
} ;
if ( V_5 < 1 || V_5 > 4 )
return - 1 ;
return V_6 [ V_4 % 6 ] [ V_5 - 1 ] ;
}
static int T_1 F_8 ( void )
{
if ( F_9 () )
F_10 ( & V_11 ) ;
return 0 ;
}
void F_11 ( void )
{
int V_12 ;
V_12 = F_12 ( V_13 , 1 ) ;
if ( V_12 )
F_13 ( L_1 ) ;
}
static int T_1 F_14 ( void )
{
int V_12 ;
if ( ! F_9 () )
return 0 ;
V_12 = F_15 ( V_13 , L_2 ) ;
if ( V_12 ) {
F_16 ( L_3 ) ;
return 0 ;
}
V_14 = F_11 ;
return 0 ;
}
static void T_1 F_17 ( void )
{
F_18 () ;
F_19 ( & V_15 ) ;
F_19 ( & V_16 ) ;
F_19 ( & V_17 ) ;
F_19 ( & V_18 ) ;
F_19 ( & V_19 ) ;
F_19 ( & V_20 ) ;
F_20 ( 0 , V_21 ,
F_6 ( V_21 ) ) ;
}
