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
struct V_25 * V_26 = F_23 ( V_2 ) ;
if ( F_24 ( V_26 -> V_27 ) )
return;
F_25 ( V_26 -> V_27 , V_7 ) ;
}
static struct V_28 * F_26 ( struct V_1 * V_2 ,
const char * V_29 , T_2 V_30 ,
const void * V_31 ,
T_4 V_32 )
{
struct V_28 * V_33 ;
struct V_34 V_35 [ 2 ] ;
int V_36 ;
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
V_35 [ 0 ] . V_37 = V_30 ;
V_35 [ 0 ] . V_38 = V_35 [ 0 ] . V_37 + 0x1000 - 1 ;
V_35 [ 0 ] . V_39 = V_40 ;
V_35 [ 1 ] . V_37 = V_2 -> V_41 ;
V_35 [ 1 ] . V_39 = V_42 ;
V_33 = F_27 ( V_29 , 0 ) ;
if ( ! V_33 )
return F_28 ( - V_43 ) ;
V_33 -> V_2 . V_44 = & V_2 -> V_2 ;
V_33 -> V_2 . V_45 = & V_33 -> V_2 . V_46 ;
V_36 = F_29 ( V_33 , V_35 ,
F_30 ( V_35 ) ) ;
if ( V_36 )
goto V_47;
if ( V_31 )
V_36 = F_31 ( V_33 , V_31 , V_32 ) ;
if ( V_36 )
goto V_47;
V_36 = F_32 ( V_33 ) ;
if ( V_36 )
goto V_47;
return V_33 ;
V_47:
F_33 ( V_33 ) ;
return F_28 ( V_36 ) ;
}
static int F_34 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_48 ;
struct V_49 * V_10 = & V_2 -> V_9 -> V_10 ;
T_2 V_50 ;
int V_51 ;
if ( F_35 ( V_2 -> V_52 , F_36 ( 32 ) ) )
return - V_53 ;
switch ( V_2 -> V_11 . V_11 ) {
case V_54 :
F_21 ( V_2 ) ;
break;
case V_55 :
F_8 ( V_2 ) ;
break;
default:
return - V_56 ;
}
V_50 = V_2 -> V_19 [ 0 ] ;
if ( ( V_10 -> V_11 == V_57 ||
V_10 -> V_11 == V_58 )
&& V_10 -> V_14 == 0 )
V_50 = 0x18009000 ;
V_26 -> V_59 = F_26 ( V_2 , L_5 ,
V_50 , & V_60 ,
sizeof( V_60 ) ) ;
if ( F_37 ( V_26 -> V_59 ) )
return F_38 ( V_26 -> V_59 ) ;
V_26 -> V_61 = F_26 ( V_2 , L_6 ,
V_2 -> V_30 , & V_62 ,
sizeof( V_62 ) ) ;
if ( F_37 ( V_26 -> V_61 ) ) {
V_51 = F_38 ( V_26 -> V_61 ) ;
goto V_63;
}
return 0 ;
V_63:
F_39 ( V_26 -> V_59 ) ;
return V_51 ;
}
static int F_40 ( struct V_1 * V_48 )
{
int V_51 ;
struct V_25 * V_26 ;
V_26 = F_41 ( & V_48 -> V_2 , sizeof( struct V_25 ) ,
V_64 ) ;
if ( ! V_26 )
return - V_43 ;
V_26 -> V_48 = V_48 ;
if ( V_48 -> V_2 . V_65 )
V_26 -> V_27 = F_42 ( & V_48 -> V_2 , L_7 ,
& V_48 -> V_2 . V_65 -> V_66 ) ;
if ( ! F_24 ( V_26 -> V_27 ) )
F_43 ( V_26 -> V_27 , 1 ) ;
switch ( V_48 -> V_11 . V_11 ) {
case V_55 :
case V_54 :
V_51 = F_34 ( V_26 ) ;
if ( V_51 )
return V_51 ;
break;
default:
return - V_56 ;
}
F_44 ( V_48 , V_26 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_23 ( V_2 ) ;
struct V_28 * V_59 = V_26 -> V_59 ;
struct V_28 * V_61 = V_26 -> V_61 ;
if ( V_59 )
F_39 ( V_59 ) ;
if ( V_61 )
F_39 ( V_61 ) ;
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
static int T_5 F_50 ( void )
{
return F_51 ( & V_67 ) ;
}
static void T_6 F_52 ( void )
{
F_53 ( & V_67 ) ;
}
