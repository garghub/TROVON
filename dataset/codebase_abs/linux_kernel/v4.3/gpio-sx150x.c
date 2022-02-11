static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
T_1 V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 ,
L_1 ,
V_4 , V_3 , V_5 ) ;
return V_5 ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_2 V_3 , T_2 * V_4 )
{
T_1 V_5 = F_5 ( V_2 , V_3 ) ;
if ( V_5 >= 0 )
* V_4 = V_5 ;
else
F_3 ( & V_2 -> V_6 ,
L_2 ,
V_3 , V_5 ) ;
return V_5 ;
}
static inline bool F_6 ( struct V_7 * V_8 , unsigned V_9 )
{
return ( V_8 -> V_10 -> V_11 == V_9 ) ;
}
static inline void F_7 ( T_2 V_9 , T_2 V_12 ,
T_2 * V_3 , T_2 * V_13 , T_2 * V_14 )
{
* V_3 -= V_9 * V_12 / 8 ;
* V_13 = ( 1 << V_12 ) - 1 ;
* V_14 = ( V_9 * V_12 ) % 8 ;
* V_13 <<= * V_14 ;
}
static T_1 F_8 ( struct V_7 * V_8 ,
T_2 V_9 , T_2 V_12 , T_2 V_3 , T_2 V_4 )
{
T_2 V_13 ;
T_2 V_15 ;
T_2 V_14 ;
T_1 V_5 ;
F_7 ( V_9 , V_12 , & V_3 , & V_13 , & V_14 ) ;
V_5 = F_4 ( V_8 -> V_2 , V_3 , & V_15 ) ;
if ( V_5 < 0 )
return V_5 ;
V_15 &= ~ V_13 ;
V_15 |= ( V_4 << V_14 ) & V_13 ;
return F_1 ( V_8 -> V_2 , V_3 , V_15 ) ;
}
static int F_9 ( struct V_7 * V_8 , unsigned V_9 )
{
T_2 V_3 = V_8 -> V_10 -> V_16 ;
T_2 V_13 ;
T_2 V_15 ;
T_2 V_14 ;
T_1 V_5 ;
F_7 ( V_9 , 1 , & V_3 , & V_13 , & V_14 ) ;
V_5 = F_4 ( V_8 -> V_2 , V_3 , & V_15 ) ;
if ( V_5 >= 0 )
V_5 = ( V_15 & V_13 ) != 0 ? 1 : 0 ;
return V_5 ;
}
static void F_10 ( struct V_7 * V_8 , int V_4 )
{
F_1 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_17 . V_18 . V_19 ,
( V_4 ? 0x1f : 0x10 ) ) ;
}
static void F_11 ( struct V_7 * V_8 , unsigned V_9 , int V_4 )
{
F_8 ( V_8 ,
V_9 ,
1 ,
V_8 -> V_10 -> V_16 ,
( V_4 ? 1 : 0 ) ) ;
}
static int F_12 ( struct V_7 * V_8 , unsigned V_9 )
{
return F_8 ( V_8 ,
V_9 ,
1 ,
V_8 -> V_10 -> V_20 ,
1 ) ;
}
static int F_13 ( struct V_7 * V_8 , unsigned V_9 , int V_4 )
{
int V_5 ;
V_5 = F_8 ( V_8 ,
V_9 ,
1 ,
V_8 -> V_10 -> V_16 ,
( V_4 ? 1 : 0 ) ) ;
if ( V_5 >= 0 )
V_5 = F_8 ( V_8 ,
V_9 ,
1 ,
V_8 -> V_10 -> V_20 ,
0 ) ;
return V_5 ;
}
static int F_14 ( struct V_21 * V_22 , unsigned V_9 )
{
struct V_7 * V_8 ;
int V_23 = - V_24 ;
V_8 = F_15 ( V_22 , struct V_7 , V_21 ) ;
if ( ! F_6 ( V_8 , V_9 ) ) {
F_16 ( & V_8 -> V_25 ) ;
V_23 = F_9 ( V_8 , V_9 ) ;
F_17 ( & V_8 -> V_25 ) ;
}
return V_23 ;
}
static void F_18 ( struct V_21 * V_22 , unsigned V_9 , int V_4 )
{
struct V_7 * V_8 ;
V_8 = F_15 ( V_22 , struct V_7 , V_21 ) ;
F_16 ( & V_8 -> V_25 ) ;
if ( F_6 ( V_8 , V_9 ) )
F_10 ( V_8 , V_4 ) ;
else
F_11 ( V_8 , V_9 , V_4 ) ;
F_17 ( & V_8 -> V_25 ) ;
}
static int F_19 ( struct V_21 * V_22 , unsigned V_9 )
{
struct V_7 * V_8 ;
int V_23 = - V_24 ;
V_8 = F_15 ( V_22 , struct V_7 , V_21 ) ;
if ( ! F_6 ( V_8 , V_9 ) ) {
F_16 ( & V_8 -> V_25 ) ;
V_23 = F_12 ( V_8 , V_9 ) ;
F_17 ( & V_8 -> V_25 ) ;
}
return V_23 ;
}
static int F_20 ( struct V_21 * V_22 ,
unsigned V_9 ,
int V_4 )
{
struct V_7 * V_8 ;
int V_23 = 0 ;
V_8 = F_15 ( V_22 , struct V_7 , V_21 ) ;
if ( ! F_6 ( V_8 , V_9 ) ) {
F_16 ( & V_8 -> V_25 ) ;
V_23 = F_13 ( V_8 , V_9 , V_4 ) ;
F_17 ( & V_8 -> V_25 ) ;
}
return V_23 ;
}
static void F_21 ( struct V_26 * V_27 )
{
struct V_7 * V_8 = F_22 ( V_27 ) ;
unsigned V_28 = V_27 -> V_29 ;
V_8 -> V_30 |= ( 1 << V_28 ) ;
V_8 -> V_31 = V_28 ;
}
static void F_23 ( struct V_26 * V_27 )
{
struct V_7 * V_8 = F_22 ( V_27 ) ;
unsigned V_28 = V_27 -> V_29 ;
V_8 -> V_30 &= ~ ( 1 << V_28 ) ;
V_8 -> V_31 = V_28 ;
}
static int F_24 ( struct V_26 * V_27 , unsigned int V_32 )
{
struct V_7 * V_8 = F_22 ( V_27 ) ;
unsigned V_28 , V_4 = 0 ;
if ( V_32 & ( V_33 | V_34 ) )
return - V_24 ;
V_28 = V_27 -> V_29 ;
if ( V_32 & V_35 )
V_4 |= 0x1 ;
if ( V_32 & V_36 )
V_4 |= 0x2 ;
V_8 -> V_37 &= ~ ( 3UL << ( V_28 * 2 ) ) ;
V_8 -> V_37 |= V_4 << ( V_28 * 2 ) ;
V_8 -> V_31 = V_28 ;
return 0 ;
}
static T_3 F_25 ( int V_38 , void * V_39 )
{
struct V_7 * V_8 = (struct V_7 * ) V_39 ;
unsigned V_40 = 0 ;
unsigned V_41 ;
unsigned V_28 ;
T_1 V_5 ;
T_2 V_4 ;
int V_42 ;
for ( V_42 = ( V_8 -> V_10 -> V_11 / 8 ) - 1 ; V_42 >= 0 ; -- V_42 ) {
V_5 = F_4 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_43 - V_42 ,
& V_4 ) ;
if ( V_5 < 0 )
continue;
F_1 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_43 - V_42 ,
V_4 ) ;
for ( V_28 = 0 ; V_28 < 8 ; ++ V_28 ) {
if ( V_4 & ( 1 << V_28 ) ) {
V_41 = F_26 (
V_8 -> V_21 . V_44 ,
( V_42 * 8 ) + V_28 ) ;
F_27 ( V_41 ) ;
++ V_40 ;
}
}
}
return ( V_40 > 0 ? V_45 : V_46 ) ;
}
static void F_28 ( struct V_26 * V_27 )
{
struct V_7 * V_8 = F_22 ( V_27 ) ;
F_16 ( & V_8 -> V_25 ) ;
}
static void F_29 ( struct V_26 * V_27 )
{
struct V_7 * V_8 = F_22 ( V_27 ) ;
unsigned V_28 ;
if ( V_8 -> V_31 == V_47 )
goto V_48;
V_28 = V_8 -> V_31 ;
V_8 -> V_31 = V_47 ;
if ( V_8 -> V_49 == V_8 -> V_37 &&
V_8 -> V_50 == V_8 -> V_30 )
goto V_48;
V_8 -> V_49 = V_8 -> V_37 ;
V_8 -> V_50 = V_8 -> V_30 ;
if ( V_8 -> V_30 & ( 1 << V_28 ) ) {
F_8 ( V_8 , V_28 , 1 , V_8 -> V_10 -> V_51 , 1 ) ;
F_8 ( V_8 , V_28 , 2 , V_8 -> V_10 -> V_52 , 0 ) ;
} else {
F_8 ( V_8 , V_28 , 1 , V_8 -> V_10 -> V_51 , 0 ) ;
F_8 ( V_8 , V_28 , 2 , V_8 -> V_10 -> V_52 ,
V_8 -> V_37 >> ( V_28 * 2 ) ) ;
}
V_48:
F_17 ( & V_8 -> V_25 ) ;
}
static void F_30 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
T_4 V_53 ,
struct V_54 * V_55 )
{
F_31 ( & V_8 -> V_25 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_10 = & V_56 [ V_53 ] ;
V_8 -> V_21 . V_6 = & V_2 -> V_6 ;
V_8 -> V_21 . V_57 = V_2 -> V_58 ;
V_8 -> V_21 . V_59 = F_19 ;
V_8 -> V_21 . V_60 = F_20 ;
V_8 -> V_21 . V_61 = F_14 ;
V_8 -> V_21 . V_62 = F_18 ;
V_8 -> V_21 . V_63 = V_55 -> V_64 ;
V_8 -> V_21 . V_65 = true ;
V_8 -> V_21 . V_66 = V_8 -> V_10 -> V_11 ;
#ifdef F_32
V_8 -> V_21 . V_67 = V_2 -> V_6 . V_67 ;
V_8 -> V_21 . V_68 = 2 ;
#endif
if ( V_55 -> V_69 )
++ V_8 -> V_21 . V_66 ;
V_8 -> V_70 . V_58 = V_2 -> V_58 ;
V_8 -> V_70 . V_71 = F_21 ;
V_8 -> V_70 . V_72 = F_23 ;
V_8 -> V_70 . V_73 = F_24 ;
V_8 -> V_70 . V_74 = F_28 ;
V_8 -> V_70 . V_75 = F_29 ;
V_8 -> V_76 = - 1 ;
V_8 -> V_77 = - 1 ;
V_8 -> V_30 = ~ 0 ;
V_8 -> V_37 = 0 ;
V_8 -> V_50 = ~ 0 ;
V_8 -> V_49 = 0 ;
V_8 -> V_31 = V_47 ;
}
static int F_33 ( struct V_7 * V_8 , T_2 V_63 , T_5 V_78 )
{
int V_5 = 0 ;
unsigned V_28 ;
for ( V_28 = 0 ; V_5 >= 0 && V_28 < ( V_8 -> V_10 -> V_11 / 8 ) ; ++ V_28 )
V_5 = F_1 ( V_8 -> V_2 , V_63 - V_28 , V_78 >> ( V_28 * 8 ) ) ;
return V_5 ;
}
static int F_34 ( struct V_7 * V_8 )
{
int V_5 ;
V_5 = F_2 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_17 . V_18 . V_79 ,
0x12 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_17 . V_18 . V_79 ,
0x34 ) ;
return V_5 ;
}
static int F_35 ( struct V_7 * V_8 ,
struct V_54 * V_55 )
{
int V_5 = 0 ;
if ( V_55 -> V_80 ) {
V_5 = F_34 ( V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_8 -> V_10 -> V_81 == V_82 )
V_5 = F_1 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_17 . V_18 . V_83 ,
0x01 ) ;
else
V_5 = F_1 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_17 . V_84 . V_85 ,
0x04 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_33 ( V_8 , V_8 -> V_10 -> V_86 ,
V_55 -> V_87 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_33 ( V_8 , V_8 -> V_10 -> V_88 ,
V_55 -> V_89 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_8 -> V_10 -> V_81 == V_82 ) {
V_5 = F_33 ( V_8 ,
V_8 -> V_10 -> V_17 . V_18 . V_90 ,
V_55 -> V_91 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_33 ( V_8 ,
V_8 -> V_10 -> V_17 . V_18 . V_92 ,
V_55 -> V_93 ) ;
if ( V_5 < 0 )
return V_5 ;
} else {
V_5 = F_33 ( V_8 ,
V_8 -> V_10 -> V_17 . V_84 . V_94 ,
0 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_55 -> V_69 )
F_10 ( V_8 , 0 ) ;
return V_5 ;
}
static int F_36 ( struct V_7 * V_8 ,
int V_76 ,
int V_77 )
{
int V_5 ;
V_8 -> V_76 = V_76 ;
V_8 -> V_77 = V_77 ;
V_5 = F_37 ( & V_8 -> V_21 ,
& V_8 -> V_70 , V_8 -> V_77 ,
V_95 , V_96 ) ;
if ( V_5 ) {
F_38 ( & V_8 -> V_2 -> V_6 ,
L_3 ) ;
return V_5 ;
}
V_5 = F_39 ( & V_8 -> V_2 -> V_6 ,
V_76 , NULL , F_25 ,
V_97 | V_98 | V_99 ,
V_8 -> V_70 . V_58 , V_8 ) ;
if ( V_5 < 0 ) {
V_8 -> V_76 = - 1 ;
V_8 -> V_77 = - 1 ;
}
return V_5 ;
}
static int F_40 ( struct V_1 * V_2 ,
const struct V_100 * V_101 )
{
static const T_6 V_102 = V_103 |
V_104 ;
struct V_54 * V_55 ;
struct V_7 * V_8 ;
int V_105 ;
V_55 = F_41 ( & V_2 -> V_6 ) ;
if ( ! V_55 )
return - V_24 ;
if ( ! F_42 ( V_2 -> V_106 , V_102 ) )
return - V_107 ;
V_8 = F_43 ( & V_2 -> V_6 ,
sizeof( struct V_7 ) , V_108 ) ;
if ( ! V_8 )
return - V_109 ;
F_30 ( V_8 , V_2 , V_101 -> V_53 , V_55 ) ;
V_105 = F_35 ( V_8 , V_55 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_44 ( & V_8 -> V_21 ) ;
if ( V_105 )
return V_105 ;
if ( V_55 -> V_76 >= 0 ) {
V_105 = F_36 ( V_8 ,
V_55 -> V_76 ,
V_55 -> V_77 ) ;
if ( V_105 < 0 )
goto V_110;
}
F_45 ( V_2 , V_8 ) ;
return 0 ;
V_110:
F_46 ( & V_8 -> V_21 ) ;
return V_105 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
V_8 = F_48 ( V_2 ) ;
F_46 ( & V_8 -> V_21 ) ;
return 0 ;
}
static int T_7 F_49 ( void )
{
return F_50 ( & V_111 ) ;
}
static void T_8 F_51 ( void )
{
return F_52 ( & V_111 ) ;
}
