static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_4 , L_1 ) ;
if ( V_3 )
return V_3 ;
F_3 ( V_4 , 0 ) ;
V_2 -> V_5 . V_6 = V_2 -> V_7 == 0 ? V_8 : V_9 ;
V_10 [ 0 ] . V_11 = V_12 ;
V_10 [ 1 ] . V_11 = V_13 ;
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
struct V_14 * V_15 )
{
int V_16 = V_2 -> V_7 ? V_17 : V_18 ;
int V_19 = V_2 -> V_7 ? V_20 : V_21 ;
V_15 -> V_22 = ! F_10 ( V_16 ) ;
V_15 -> V_23 = ! ! F_10 ( V_19 ) ;
V_15 -> V_24 = 1 ;
V_15 -> V_25 = 1 ;
V_15 -> V_26 = 0 ;
V_15 -> V_27 = 0 ;
V_15 -> V_28 = 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
const T_1 * V_15 )
{
switch ( V_2 -> V_7 ) {
case 0 :
if ( V_15 -> V_29 & V_30 ) {
F_12 ( V_31 , 0 ) ;
F_13 ( 1 ) ;
F_12 ( V_4 , 1 ) ;
F_13 ( 10 ) ;
F_12 ( V_4 , 0 ) ;
}
break;
case 1 :
if ( V_15 -> V_29 & V_30 ) {
F_12 ( V_31 , 1 ) ;
F_13 ( 1 ) ;
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
V_32 = F_15 ( L_2 , - 1 ) ;
if ( ! V_32 )
return - V_33 ;
V_3 = F_16 ( V_32 , & V_34 ,
sizeof( V_34 ) ) ;
if ( V_3 == 0 ) {
F_17 ( V_35 L_3 ) ;
V_3 = F_18 ( V_32 ) ;
}
if ( V_3 )
F_19 ( V_32 ) ;
return V_3 ;
}
void T_3 F_20 ( void )
{
F_21 ( V_32 ) ;
}
