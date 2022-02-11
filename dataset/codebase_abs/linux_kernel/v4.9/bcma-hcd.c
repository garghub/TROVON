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
static int F_13 ( struct V_16 * V_17 )
{
struct V_1 * V_18 = V_17 -> V_18 ;
struct V_19 * V_2 = & V_18 -> V_2 ;
struct V_1 * V_20 ;
F_14 ( 10000 , 20000 ) ;
if ( V_18 -> V_11 . V_14 < 5 )
return 0 ;
V_20 = F_15 ( V_18 -> V_9 , V_21 ) ;
if ( ! V_20 ) {
F_16 ( V_2 , L_3 ) ;
return - V_22 ;
}
F_17 ( V_18 , V_23 , V_24 | V_25 ) ;
F_14 ( 100 , 200 ) ;
F_17 ( V_18 , V_26 , V_27 ) ;
F_14 ( 100 , 200 ) ;
F_17 ( V_18 , V_26 , 0 ) ;
F_14 ( 100 , 200 ) ;
F_17 ( V_18 , V_23 , V_24 ) ;
F_14 ( 100 , 200 ) ;
F_7 ( V_18 , V_28 , V_29 |
V_30 |
V_31 ) ;
F_14 ( 100 , 200 ) ;
F_7 ( V_18 , 0x510 , 0xc7f85000 ) ;
F_7 ( V_18 , 0x510 , 0xc7f85003 ) ;
F_14 ( 300 , 600 ) ;
F_7 ( V_20 , V_32 , 0x6 ) ;
F_7 ( V_20 , V_33 , 0x005360c1 ) ;
F_14 ( 100 , 200 ) ;
F_7 ( V_20 , V_32 , 0x7 ) ;
F_7 ( V_20 , V_33 , 0x0 ) ;
F_14 ( 100 , 200 ) ;
F_18 ( V_20 , V_34 , V_35 ) ;
F_14 ( 100 , 200 ) ;
F_7 ( V_18 , 0x510 , 0x7f8d007 ) ;
F_3 ( 1000 ) ;
F_7 ( V_18 , 0x200 , 0x4ff ) ;
F_14 ( 25 , 50 ) ;
F_7 ( V_18 , 0x200 , 0x6ff ) ;
F_14 ( 25 , 50 ) ;
F_7 ( V_18 , 0x200 , 0x7ff ) ;
F_14 ( 25 , 50 ) ;
F_19 ( V_2 -> V_36 , NULL , V_2 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_2 V_7 ;
V_7 = F_2 ( V_2 , 0x94 ) ;
V_7 &= 0xffff ;
V_7 |= 0x80 << 16 ;
F_7 ( V_2 , 0x94 , V_7 ) ;
V_7 = F_2 ( V_2 , 0x9c ) ;
V_7 |= 1 ;
F_7 ( V_2 , 0x9c , V_7 ) ;
F_14 ( 1000 , 2000 ) ;
}
static int F_21 ( struct V_16 * V_37 )
{
struct V_1 * V_18 = V_37 -> V_18 ;
struct V_38 * V_39 = & V_18 -> V_9 -> V_10 ;
struct V_19 * V_2 = & V_18 -> V_2 ;
F_10 ( V_18 , 0 ) ;
if ( V_39 -> V_11 == V_40 ||
V_39 -> V_11 == V_41 )
F_20 ( V_18 ) ;
F_19 ( V_2 -> V_36 , NULL , V_2 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 , bool V_7 )
{
struct V_16 * V_17 = F_23 ( V_2 ) ;
if ( F_24 ( V_17 -> V_42 ) )
return;
F_25 ( V_17 -> V_42 , V_7 ) ;
}
static struct V_43 * F_26 ( struct V_1 * V_2 ,
const char * V_44 , T_2 V_45 ,
const void * V_46 ,
T_3 V_47 )
{
struct V_43 * V_48 ;
struct V_49 V_50 [ 2 ] ;
int V_51 ;
memset ( V_50 , 0 , sizeof( V_50 ) ) ;
V_50 [ 0 ] . V_52 = V_45 ;
V_50 [ 0 ] . V_53 = V_50 [ 0 ] . V_52 + 0x1000 - 1 ;
V_50 [ 0 ] . V_54 = V_55 ;
V_50 [ 1 ] . V_52 = V_2 -> V_56 ;
V_50 [ 1 ] . V_54 = V_57 ;
V_48 = F_27 ( V_44 , 0 ) ;
if ( ! V_48 )
return F_28 ( - V_58 ) ;
V_48 -> V_2 . V_59 = & V_2 -> V_2 ;
V_48 -> V_2 . V_60 = & V_48 -> V_2 . V_61 ;
V_51 = F_29 ( V_48 , V_50 ,
F_30 ( V_50 ) ) ;
if ( V_51 )
goto V_62;
if ( V_46 )
V_51 = F_31 ( V_48 , V_46 , V_47 ) ;
if ( V_51 )
goto V_62;
V_51 = F_32 ( V_48 ) ;
if ( V_51 )
goto V_62;
return V_48 ;
V_62:
F_33 ( V_48 ) ;
return F_28 ( V_51 ) ;
}
static int F_34 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_38 * V_10 = & V_2 -> V_9 -> V_10 ;
T_2 V_63 ;
int V_64 ;
if ( F_35 ( V_2 -> V_65 , F_36 ( 32 ) ) )
return - V_66 ;
F_8 ( V_2 ) ;
V_63 = V_2 -> V_67 [ 0 ] ;
if ( ( V_10 -> V_11 == V_68 ||
V_10 -> V_11 == V_69 )
&& V_10 -> V_14 == 0 )
V_63 = 0x18009000 ;
V_17 -> V_70 = F_26 ( V_2 , L_4 ,
V_63 , & V_71 ,
sizeof( V_71 ) ) ;
if ( F_37 ( V_17 -> V_70 ) )
return F_38 ( V_17 -> V_70 ) ;
V_17 -> V_72 = F_26 ( V_2 , L_5 ,
V_2 -> V_45 , & V_73 ,
sizeof( V_73 ) ) ;
if ( F_37 ( V_17 -> V_72 ) ) {
V_64 = F_38 ( V_17 -> V_72 ) ;
goto V_74;
}
return 0 ;
V_74:
F_39 ( V_17 -> V_70 ) ;
return V_64 ;
}
static int F_40 ( struct V_16 * V_37 )
{
struct V_1 * V_18 = V_37 -> V_18 ;
struct V_19 * V_2 = & V_18 -> V_2 ;
F_10 ( V_18 , 0 ) ;
F_19 ( V_2 -> V_36 , NULL , V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_18 )
{
int V_64 ;
struct V_16 * V_17 ;
V_17 = F_42 ( & V_18 -> V_2 , sizeof( struct V_16 ) ,
V_75 ) ;
if ( ! V_17 )
return - V_58 ;
V_17 -> V_18 = V_18 ;
if ( V_18 -> V_2 . V_36 )
V_17 -> V_42 = F_43 ( & V_18 -> V_2 , L_6 ,
V_76 ) ;
switch ( V_18 -> V_11 . V_11 ) {
case V_77 :
if ( F_44 ( V_78 ) )
V_64 = F_13 ( V_17 ) ;
else if ( F_44 ( V_79 ) )
V_64 = F_34 ( V_17 ) ;
else
V_64 = - V_80 ;
break;
case V_81 :
V_64 = F_21 ( V_17 ) ;
break;
case V_82 :
V_64 = F_40 ( V_17 ) ;
break;
default:
return - V_83 ;
}
if ( V_64 )
return V_64 ;
F_45 ( V_18 , V_17 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_23 ( V_2 ) ;
struct V_43 * V_70 = V_17 -> V_70 ;
struct V_43 * V_72 = V_17 -> V_72 ;
if ( V_70 )
F_39 ( V_70 ) ;
if ( V_72 )
F_39 ( V_72 ) ;
F_47 ( V_2 , 0 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_22 ( V_2 , false ) ;
F_47 ( V_2 , 0 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
F_22 ( V_2 , false ) ;
F_47 ( V_2 , 0 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
F_22 ( V_2 , true ) ;
F_10 ( V_2 , 0 ) ;
return 0 ;
}
static int T_4 F_51 ( void )
{
return F_52 ( & V_84 ) ;
}
static void T_5 F_53 ( void )
{
F_54 ( & V_84 ) ;
}
