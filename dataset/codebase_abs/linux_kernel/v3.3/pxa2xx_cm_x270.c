static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_4 , L_1 ) ;
if ( V_3 )
return V_3 ;
F_3 ( V_4 , 0 ) ;
V_2 -> V_5 . V_6 = V_7 ;
V_8 [ 0 ] . V_9 = V_10 ;
V_3 = F_4 ( V_2 , V_8 , F_5 ( V_8 ) ) ;
if ( ! V_3 )
F_6 ( V_4 ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_8 , F_5 ( V_8 ) ) ;
F_6 ( V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
V_12 -> V_13 = ( F_10 ( V_14 ) == 0 ) ? 1 : 0 ;
V_12 -> V_15 = ( F_10 ( V_16 ) == 0 ) ? 0 : 1 ;
V_12 -> V_17 = 1 ;
V_12 -> V_18 = 1 ;
V_12 -> V_19 = 0 ;
V_12 -> V_20 = 0 ;
V_12 -> V_21 = 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
const T_1 * V_12 )
{
switch ( V_2 -> V_22 ) {
case 0 :
if ( V_12 -> V_23 & V_24 ) {
F_12 ( V_4 , 1 ) ;
F_13 ( 10 ) ;
F_12 ( V_4 , 0 ) ;
}
break;
}
return 0 ;
}
int T_2 F_14 ( void )
{
int V_3 ;
V_25 = F_15 ( L_2 , - 1 ) ;
if ( ! V_25 )
return - V_26 ;
V_3 = F_16 ( V_25 , & V_27 ,
sizeof( V_27 ) ) ;
if ( V_3 == 0 ) {
F_17 ( V_28 L_3 ) ;
V_3 = F_18 ( V_25 ) ;
}
if ( V_3 )
F_19 ( V_25 ) ;
return V_3 ;
}
void T_3 F_20 ( void )
{
F_21 ( V_25 ) ;
}
