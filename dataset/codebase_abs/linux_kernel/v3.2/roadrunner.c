static int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 ,
T_2 V_4 )
{
static int V_5 [] = { V_6 , V_7 , V_8 , V_9 } ;
static int V_10 [] = { V_9 , V_6 , V_7 , V_8 } ;
static int V_11 [] = { V_6 , V_7 , V_8 , - 1 } ;
static int V_12 [] = { V_6 , V_7 , - 1 , - 1 } ;
static int V_13 [] = { V_7 , V_8 , - 1 , - 1 } ;
switch( V_2 -> V_14 -> V_15 ) {
case 0 :
switch( V_2 -> V_16 ) {
case 0x0 :
break;
case 0x8 :
return V_5 [ V_4 - 1 ] ;
case 0x10 :
return V_10 [ V_4 - 1 ] ;
case 0x18 :
break;
case 0x20 :
break;
default:
return V_17 ;
}
break;
case 1 :
switch( V_2 -> V_16 ) {
case 0x0 :
return ( V_4 == 1 ) ? V_7 : - 1 ;
case 0x8 :
case 0x9 :
case 0xa :
return V_11 [ V_4 - 1 ] ;
case 0x10 :
return V_12 [ V_4 - 1 ] ;
case 0x18 :
return V_13 [ V_4 - 1 ] ;
case 0x20 :
return ( V_4 == 1 ) ? V_9 : - 1 ;
default:
return V_17 ;
}
break;
default:
return V_17 ;
}
return V_17 ;
}
static void T_1 F_2 ( void )
{
F_3 ( V_18 , V_19 ) ;
F_3 ( V_20 , V_19 ) ;
F_4 () ;
}
static int T_1 F_5 ( void )
{
if ( F_6 () )
F_7 ( & V_21 ) ;
return 0 ;
}
static void T_1 F_8 ( void )
{
F_9 ( & V_22 ) ;
V_23 [ 0 ] |= V_24 ;
V_23 [ 1 ] |= V_24 ;
V_23 [ 2 ] |= V_24 ;
V_23 [ 3 ] |= V_24 ;
F_10 () ;
}
