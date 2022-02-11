static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_4 , L_1 ) ;
if ( V_3 )
return V_3 ;
F_3 ( V_4 , 0 ) ;
V_2 -> V_5 . V_6 = V_7 ;
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
struct V_9 * V_10 )
{
V_10 -> V_11 = ( F_10 ( V_12 ) == 0 ) ? 1 : 0 ;
V_10 -> V_13 = ( F_10 ( V_14 ) == 0 ) ? 0 : 1 ;
V_10 -> V_15 = 1 ;
V_10 -> V_16 = 1 ;
V_10 -> V_17 = 0 ;
V_10 -> V_18 = 0 ;
V_10 -> V_19 = 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
const T_1 * V_10 )
{
switch ( V_2 -> V_20 ) {
case 0 :
if ( V_10 -> V_21 & V_22 ) {
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
V_23 = F_15 ( L_2 , - 1 ) ;
if ( ! V_23 )
return - V_24 ;
V_3 = F_16 ( V_23 , & V_25 ,
sizeof( V_25 ) ) ;
if ( V_3 == 0 ) {
F_17 ( V_26 L_3 ) ;
V_3 = F_18 ( V_23 ) ;
}
if ( V_3 )
F_19 ( V_23 ) ;
return V_3 ;
}
void T_3 F_20 ( void )
{
F_21 ( V_23 ) ;
}
