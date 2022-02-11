static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_4 , L_1 ) ;
if ( V_3 )
return V_3 ;
F_3 ( V_4 , 0 ) ;
V_2 -> V_5 [ V_6 ] . V_7 = V_8 ;
V_2 -> V_5 [ V_6 ] . V_9 = L_2 ;
V_2 -> V_5 [ V_10 ] . V_7 = V_11 ;
V_2 -> V_5 [ V_10 ] . V_9 = L_3 ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
V_13 -> V_14 = 0 ;
V_13 -> V_15 = 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const T_1 * V_13 )
{
switch ( V_2 -> V_16 ) {
case 0 :
if ( V_13 -> V_17 & V_18 ) {
F_8 ( V_4 , 1 ) ;
F_9 ( 10 ) ;
F_8 ( V_4 , 0 ) ;
}
break;
}
return 0 ;
}
int T_2 F_10 ( void )
{
int V_3 ;
V_19 = F_11 ( L_4 , - 1 ) ;
if ( ! V_19 )
return - V_20 ;
V_3 = F_12 ( V_19 , & V_21 ,
sizeof( V_21 ) ) ;
if ( V_3 == 0 ) {
F_13 ( V_22 L_5 ) ;
V_3 = F_14 ( V_19 ) ;
}
if ( V_3 )
F_15 ( V_19 ) ;
return V_3 ;
}
void T_3 F_16 ( void )
{
F_17 ( V_19 ) ;
}
