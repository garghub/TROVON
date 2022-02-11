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
} ;
F_8 ( V_5 < 1 || V_5 > 4 ) ;
return V_6 [ V_4 % 4 ] [ V_5 - 1 ] ;
}
static int T_1 F_9 ( void )
{
if ( F_10 () )
F_11 ( & V_11 ) ;
return 0 ;
}
static void F_12 ( void )
{
F_13 ( 0x01 , F_14 ( 0xfe8d0004 ) ) ;
while ( 1 )
;
}
static void T_1 F_15 ( void )
{
F_16 ( & V_12 ) ;
F_16 ( & V_13 ) ;
F_16 ( & V_14 ) ;
F_16 ( & V_15 ) ;
F_16 ( & V_16 ) ;
F_16 ( & V_17 ) ;
F_17 ( 0 , V_18 ,
F_6 ( V_18 ) ) ;
V_19 = F_12 ;
}
