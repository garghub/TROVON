static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_5 , int V_6 )
{
int V_7 = V_6 ;
switch ( V_4 -> V_8 ) {
case 0 :
while ( -- V_7 > 1 ) {
if ( V_5 [ V_7 ] < 0xE0 || V_5 [ V_7 ] > 0xE7 )
continue;
V_5 [ 0 ] |= ( 1 << ( V_5 [ V_7 ] - 0xE0 ) ) ;
V_5 [ V_7 ] = 0 ;
}
F_2 ( V_2 , V_9 , V_5 , V_6 , 0 ) ;
return 1 ;
default:
F_3 ( V_2 , L_1 , V_4 -> V_8 ) ;
break;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , const struct V_10 * V_8 )
{
int V_11 ;
V_11 = F_5 ( V_2 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_2 ) ;
goto V_12;
}
V_11 = F_7 ( V_2 , V_13 ) ;
if ( V_11 )
F_6 ( V_2 , L_3 ) ;
V_12:
return V_11 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
}
static int T_2 F_10 ( void )
{
return F_11 ( & V_14 ) ;
}
static void T_3 F_12 ( void )
{
F_13 ( & V_14 ) ;
}
