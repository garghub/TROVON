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
F_7 ( struct V_2 * V_3 , T_2 V_4 , T_2 V_5 )
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
* V_12 &= 0xfe ;
* V_13 |= 0x01 ;
}
static void T_1 F_12 ( void )
{
F_13 ( & V_14 ) ;
F_13 ( & V_15 ) ;
F_13 ( & V_16 ) ;
F_13 ( & V_17 ) ;
F_13 ( & V_18 ) ;
F_13 ( & V_19 ) ;
F_14 ( 0 , V_20 ,
F_6 ( V_20 ) ) ;
V_21 = F_11 ;
}
