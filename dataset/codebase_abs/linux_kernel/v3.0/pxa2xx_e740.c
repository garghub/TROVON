static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_2 -> V_5 == 0 ? F_2 ( V_6 ) :
F_2 ( V_7 ) ;
return F_3 ( V_2 , & V_8 [ V_2 -> V_5 ] , 1 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , & V_8 [ V_2 -> V_5 ] , 1 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
if ( V_2 -> V_5 == 0 ) {
V_10 -> V_11 = F_7 ( V_12 ) ? 0 : 1 ;
V_10 -> V_13 = F_7 ( V_6 ) ? 1 : 0 ;
} else {
V_10 -> V_11 = F_7 ( V_14 ) ? 0 : 1 ;
V_10 -> V_13 = F_7 ( V_7 ) ? 1 : 0 ;
}
V_10 -> V_15 = 1 ;
V_10 -> V_16 = 1 ;
V_10 -> V_17 = 1 ;
V_10 -> V_18 = 0 ;
V_10 -> V_19 = 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const T_1 * V_10 )
{
if ( V_10 -> V_20 & V_21 ) {
if ( V_2 -> V_5 == 0 )
F_9 ( V_22 , 1 ) ;
else
F_9 ( V_23 , 1 ) ;
} else {
if ( V_2 -> V_5 == 0 )
F_9 ( V_22 , 0 ) ;
else
F_9 ( V_23 , 0 ) ;
}
switch ( V_10 -> V_24 ) {
case 0 :
if ( V_2 -> V_5 == 0 )
F_9 ( V_25 , 0 ) ;
else
F_9 ( V_26 , 1 ) ;
break;
case 50 :
case 33 :
if ( V_2 -> V_5 == 0 )
F_9 ( V_25 , 1 ) ;
else
F_9 ( V_26 , 0 ) ;
break;
default:
F_10 ( V_27 L_1 , V_10 -> V_24 ) ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_8 , F_13 ( V_8 ) ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_8 , F_13 ( V_8 ) ) ;
}
static int T_2 F_16 ( void )
{
int V_28 ;
if ( ! F_17 () )
return - V_29 ;
V_30 = F_18 ( L_2 , - 1 ) ;
if ( ! V_30 )
return - V_31 ;
V_28 = F_19 ( V_30 , & V_32 ,
sizeof( V_32 ) ) ;
if ( ! V_28 )
V_28 = F_20 ( V_30 ) ;
if ( V_28 )
F_21 ( V_30 ) ;
return V_28 ;
}
static void T_3 F_22 ( void )
{
F_23 ( V_30 ) ;
}
