static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_4 , L_1 ) ;
if ( V_3 )
return V_3 ;
F_3 ( V_4 , 0 ) ;
V_2 -> V_5 . V_6 = V_2 -> V_7 == 0 ? V_8 : V_9 ;
V_3 = F_4 ( V_2 , V_10 , F_5 ( V_10 ) ) ;
if ( ! V_3 )
F_6 ( V_4 ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_10 , F_5 ( V_10 ) ) ;
F_6 ( V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
int V_13 = V_2 -> V_7 ? V_14 : V_15 ;
int V_16 = V_2 -> V_7 ? V_17 : V_18 ;
V_12 -> V_19 = ! F_10 ( V_13 ) ;
V_12 -> V_20 = ! ! F_10 ( V_16 ) ;
V_12 -> V_21 = 1 ;
V_12 -> V_22 = 1 ;
V_12 -> V_23 = 0 ;
V_12 -> V_24 = 0 ;
V_12 -> V_25 = 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
const T_1 * V_12 )
{
switch ( V_2 -> V_7 ) {
case 0 :
if ( V_12 -> V_26 & V_27 ) {
F_12 ( V_28 , 0 ) ;
F_13 ( 1 ) ;
F_12 ( V_4 , 1 ) ;
F_13 ( 10 ) ;
F_12 ( V_4 , 0 ) ;
}
break;
case 1 :
if ( V_12 -> V_26 & V_27 ) {
F_12 ( V_28 , 1 ) ;
F_13 ( 1 ) ;
F_12 ( V_4 , 1 ) ;
F_13 ( 10 ) ;
F_12 ( V_4 , 0 ) ;
}
break;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
}
static void F_15 ( struct V_1 * V_2 )
{
}
int T_2 F_16 ( void )
{
int V_3 ;
V_29 = F_17 ( L_2 , - 1 ) ;
if ( ! V_29 )
return - V_30 ;
V_3 = F_18 ( V_29 , & V_31 ,
sizeof( V_31 ) ) ;
if ( V_3 == 0 ) {
F_19 ( V_32 L_3 ) ;
V_3 = F_20 ( V_29 ) ;
}
if ( V_3 )
F_21 ( V_29 ) ;
return V_3 ;
}
void T_3 F_22 ( void )
{
F_23 ( V_29 ) ;
}
