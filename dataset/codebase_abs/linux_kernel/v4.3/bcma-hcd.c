static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
int V_5 )
{
int V_6 ;
T_2 V_7 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_7 = F_2 ( V_2 , V_3 ) ;
if ( ( V_7 & V_4 ) == V_4 )
return 0 ;
F_3 ( 10 ) ;
}
return - V_8 ;
}
static void F_4 ( struct V_1 * V_2 )
{
#ifdef F_5
if ( V_2 -> V_9 -> V_10 . V_11 == 0x4716 ) {
T_2 V_12 ;
V_12 = F_6 ( & V_2 -> V_9 -> V_13 ) ;
if ( V_12 >= 480000000 )
V_12 = 0x1846b ;
else if ( V_12 == 453000000 )
V_12 = 0x1046b ;
else
V_12 = 0 ;
if ( V_12 ) {
F_7 ( V_2 , 0x524 , 0x1 ) ;
F_3 ( 500 ) ;
F_7 ( V_2 , 0x524 , V_12 ) ;
F_3 ( 500 ) ;
F_7 ( V_2 , 0x524 , 0x4ab ) ;
F_3 ( 500 ) ;
F_2 ( V_2 , 0x528 ) ;
F_7 ( V_2 , 0x528 , 0x80000000 ) ;
}
}
#endif
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 V_12 ;
if ( ! F_9 ( V_2 ) ) {
F_10 ( V_2 , 0 ) ;
F_11 ( 10 ) ;
if ( V_2 -> V_11 . V_14 >= 5 ) {
V_12 = F_2 ( V_2 , 0x1e0 ) ;
V_12 |= 0x100 ;
F_7 ( V_2 , 0x1e0 , V_12 ) ;
if ( F_1 ( V_2 , 0x1e0 , 1 << 24 , 100 ) )
F_12 ( V_15 L_1 ) ;
F_7 ( V_2 , 0x200 , 0x4ff ) ;
F_3 ( 25 ) ;
F_7 ( V_2 , 0x200 , 0x6ff ) ;
F_3 ( 25 ) ;
F_7 ( V_2 , 0x524 , 0x6b ) ;
F_3 ( 50 ) ;
V_12 = F_2 ( V_2 , 0x524 ) ;
F_3 ( 50 ) ;
F_7 ( V_2 , 0x524 , 0xab ) ;
F_3 ( 50 ) ;
V_12 = F_2 ( V_2 , 0x524 ) ;
F_3 ( 50 ) ;
F_7 ( V_2 , 0x524 , 0x2b ) ;
F_3 ( 50 ) ;
V_12 = F_2 ( V_2 , 0x524 ) ;
F_3 ( 50 ) ;
F_7 ( V_2 , 0x524 , 0x10ab ) ;
F_3 ( 50 ) ;
V_12 = F_2 ( V_2 , 0x524 ) ;
if ( F_1 ( V_2 , 0x528 , 0xc000 , 10000 ) ) {
V_12 = F_2 ( V_2 , 0x528 ) ;
F_12 ( V_15
L_2 , V_12 ) ;
}
F_7 ( V_2 , 0x528 , 0x80000000 ) ;
V_12 = F_2 ( V_2 , 0x314 ) ;
F_3 ( 265 ) ;
F_7 ( V_2 , 0x200 , 0x7ff ) ;
F_3 ( 10 ) ;
F_7 ( V_2 , 0x510 , 0 ) ;
} else {
F_7 ( V_2 , 0x200 , 0x7ff ) ;
F_3 ( 1 ) ;
}
F_4 ( V_2 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_1 * V_16 ;
void T_3 * V_17 ;
V_16 = F_14 ( V_2 -> V_9 , V_18 ) ;
if ( ! V_16 ) {
F_15 ( & V_2 -> V_2 , L_3 ) ;
return;
}
V_17 = F_16 ( V_16 -> V_19 [ 0 ] , 0x1000 ) ;
if ( ! V_17 ) {
F_15 ( & V_2 -> V_2 , L_4 ) ;
return;
}
F_17 ( 0x0000ea68 , V_17 + 0x180 ) ;
F_17 ( 0x00dd10c3 , V_17 + 0x164 ) ;
F_17 ( 0x00000000 , V_17 + 0x180 ) ;
F_18 ( V_17 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_2 V_7 ;
F_20 ( 1000 , 2000 ) ;
V_7 = F_2 ( V_2 , 0x94 ) ;
V_7 &= 0xffff ;
V_7 |= 0x80 << 16 ;
F_7 ( V_2 , 0x94 , V_7 ) ;
V_7 = F_2 ( V_2 , 0x9c ) ;
V_7 |= 1 ;
F_7 ( V_2 , 0x9c , V_7 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_10 ( V_2 , 0 ) ;
if ( V_2 -> V_9 -> V_10 . V_11 == V_20 ||
V_2 -> V_9 -> V_10 . V_11 == V_21 ) {
if ( V_2 -> V_9 -> V_10 . V_22 == V_23 ||
V_2 -> V_9 -> V_10 . V_22 == V_24 )
F_13 ( V_2 ) ;
F_19 ( V_2 ) ;
}
}
static void F_22 ( struct V_1 * V_2 , bool V_7 )
{
int V_25 ;
V_25 = F_23 ( V_2 -> V_2 . V_26 , L_5 , 0 ) ;
if ( ! F_24 ( V_25 ) )
return;
if ( V_7 ) {
F_25 ( V_25 , L_6 ) ;
F_26 ( V_25 , 1 ) ;
} else {
F_26 ( V_25 , 0 ) ;
F_27 ( V_25 ) ;
}
}
static struct V_27 * F_28 ( struct V_1 * V_2 , bool V_28 , T_2 V_29 )
{
struct V_27 * V_30 ;
struct V_31 V_32 [ 2 ] ;
int V_33 ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
V_32 [ 0 ] . V_34 = V_29 ;
V_32 [ 0 ] . V_35 = V_32 [ 0 ] . V_34 + 0x1000 - 1 ;
V_32 [ 0 ] . V_36 = V_37 ;
V_32 [ 1 ] . V_34 = V_2 -> V_38 ;
V_32 [ 1 ] . V_36 = V_39 ;
V_30 = F_29 ( V_28 ? L_7 :
L_8 , 0 ) ;
if ( ! V_30 )
return F_30 ( - V_40 ) ;
V_30 -> V_2 . V_41 = & V_2 -> V_2 ;
V_30 -> V_2 . V_42 = & V_30 -> V_2 . V_43 ;
V_33 = F_31 ( V_30 , V_32 ,
F_32 ( V_32 ) ) ;
if ( V_33 )
goto V_44;
if ( V_28 )
V_33 = F_33 ( V_30 , & V_45 ,
sizeof( V_45 ) ) ;
else
V_33 = F_33 ( V_30 , & V_46 ,
sizeof( V_46 ) ) ;
if ( V_33 )
goto V_44;
V_33 = F_34 ( V_30 ) ;
if ( V_33 )
goto V_44;
return V_30 ;
V_44:
F_35 ( V_30 ) ;
return F_30 ( V_33 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_47 ;
T_2 V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_10 ;
V_10 = & V_2 -> V_9 -> V_10 ;
if ( F_37 ( V_2 -> V_52 , F_38 ( 32 ) ) )
return - V_53 ;
V_50 = F_39 ( & V_2 -> V_2 , sizeof( struct V_49 ) ,
V_54 ) ;
if ( ! V_50 )
return - V_40 ;
F_22 ( V_2 , true ) ;
switch ( V_2 -> V_11 . V_11 ) {
case V_55 :
F_21 ( V_2 ) ;
break;
case V_56 :
F_8 ( V_2 ) ;
break;
default:
return - V_57 ;
}
V_48 = V_2 -> V_19 [ 0 ] ;
if ( ( V_10 -> V_11 == V_58 ||
V_10 -> V_11 == V_59 )
&& V_10 -> V_14 == 0 )
V_48 = 0x18009000 ;
V_50 -> V_60 = F_28 ( V_2 , true , V_48 ) ;
if ( F_40 ( V_50 -> V_60 ) )
return F_41 ( V_50 -> V_60 ) ;
V_50 -> V_61 = F_28 ( V_2 , false , V_2 -> V_29 ) ;
if ( F_40 ( V_50 -> V_61 ) ) {
V_47 = F_41 ( V_50 -> V_61 ) ;
goto V_62;
}
F_42 ( V_2 , V_50 ) ;
return 0 ;
V_62:
F_43 ( V_50 -> V_60 ) ;
return V_47 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = F_45 ( V_2 ) ;
struct V_27 * V_60 = V_50 -> V_60 ;
struct V_27 * V_61 = V_50 -> V_61 ;
if ( V_60 )
F_43 ( V_60 ) ;
if ( V_61 )
F_43 ( V_61 ) ;
F_46 ( V_2 , 0 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_22 ( V_2 , false ) ;
F_46 ( V_2 , 0 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
F_22 ( V_2 , false ) ;
F_46 ( V_2 , 0 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
F_22 ( V_2 , true ) ;
F_10 ( V_2 , 0 ) ;
return 0 ;
}
static int T_4 F_50 ( void )
{
return F_51 ( & V_63 ) ;
}
static void T_5 F_52 ( void )
{
F_53 ( & V_63 ) ;
}
