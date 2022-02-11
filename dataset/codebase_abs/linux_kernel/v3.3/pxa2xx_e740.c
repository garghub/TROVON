static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == 0 )
V_2 -> V_4 . V_5 = F_2 ( V_6 ) ;
else
V_2 -> V_4 . V_5 = F_2 ( V_7 ) ;
V_8 [ 0 ] . V_9 = F_2 ( V_10 ) ;
V_8 [ 1 ] . V_9 = F_2 ( V_11 ) ;
return F_3 ( V_2 , & V_8 [ V_2 -> V_3 ] , 1 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , & V_8 [ V_2 -> V_3 ] , 1 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
if ( V_2 -> V_3 == 0 ) {
V_13 -> V_14 = F_7 ( V_10 ) ? 0 : 1 ;
V_13 -> V_15 = F_7 ( V_6 ) ? 1 : 0 ;
} else {
V_13 -> V_14 = F_7 ( V_11 ) ? 0 : 1 ;
V_13 -> V_15 = F_7 ( V_7 ) ? 1 : 0 ;
}
V_13 -> V_16 = 1 ;
V_13 -> V_17 = 1 ;
V_13 -> V_18 = 1 ;
V_13 -> V_19 = 0 ;
V_13 -> V_20 = 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const T_1 * V_13 )
{
if ( V_13 -> V_21 & V_22 ) {
if ( V_2 -> V_3 == 0 )
F_9 ( V_23 , 1 ) ;
else
F_9 ( V_24 , 1 ) ;
} else {
if ( V_2 -> V_3 == 0 )
F_9 ( V_23 , 0 ) ;
else
F_9 ( V_24 , 0 ) ;
}
switch ( V_13 -> V_25 ) {
case 0 :
if ( V_2 -> V_3 == 0 )
F_9 ( V_26 , 0 ) ;
else
F_9 ( V_27 , 1 ) ;
break;
case 50 :
case 33 :
if ( V_2 -> V_3 == 0 )
F_9 ( V_26 , 1 ) ;
else
F_9 ( V_27 , 0 ) ;
break;
default:
F_10 ( V_28 L_1 , V_13 -> V_25 ) ;
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
int V_29 ;
if ( ! F_17 () )
return - V_30 ;
V_31 = F_18 ( L_2 , - 1 ) ;
if ( ! V_31 )
return - V_32 ;
V_29 = F_19 ( V_31 , & V_33 ,
sizeof( V_33 ) ) ;
if ( ! V_29 )
V_29 = F_20 ( V_31 ) ;
if ( V_29 )
F_21 ( V_31 ) ;
return V_29 ;
}
static void T_3 F_22 ( void )
{
F_23 ( V_31 ) ;
}
