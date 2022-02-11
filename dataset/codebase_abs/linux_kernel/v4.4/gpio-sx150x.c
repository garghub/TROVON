struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static T_1 F_3 ( struct V_4 * V_5 , T_2 V_6 , T_2 V_7 )
{
T_1 V_8 = F_4 ( V_5 , V_6 , V_7 ) ;
if ( V_8 < 0 )
F_5 ( & V_5 -> V_9 ,
L_1 ,
V_7 , V_6 , V_8 ) ;
return V_8 ;
}
static T_1 F_6 ( struct V_4 * V_5 , T_2 V_6 , T_2 * V_7 )
{
T_1 V_8 = F_7 ( V_5 , V_6 ) ;
if ( V_8 >= 0 )
* V_7 = V_8 ;
else
F_5 ( & V_5 -> V_9 ,
L_2 ,
V_6 , V_8 ) ;
return V_8 ;
}
static inline bool F_8 ( struct V_1 * V_10 , unsigned V_11 )
{
return ( V_10 -> V_12 -> V_13 == V_11 ) ;
}
static inline void F_9 ( T_2 V_11 , T_2 V_14 ,
T_2 * V_6 , T_2 * V_15 , T_2 * V_16 )
{
* V_6 -= V_11 * V_14 / 8 ;
* V_15 = ( 1 << V_14 ) - 1 ;
* V_16 = ( V_11 * V_14 ) % 8 ;
* V_15 <<= * V_16 ;
}
static T_1 F_10 ( struct V_1 * V_10 ,
T_2 V_11 , T_2 V_14 , T_2 V_6 , T_2 V_7 )
{
T_2 V_15 ;
T_2 V_17 ;
T_2 V_16 ;
T_1 V_8 ;
F_9 ( V_11 , V_14 , & V_6 , & V_15 , & V_16 ) ;
V_8 = F_6 ( V_10 -> V_5 , V_6 , & V_17 ) ;
if ( V_8 < 0 )
return V_8 ;
V_17 &= ~ V_15 ;
V_17 |= ( V_7 << V_16 ) & V_15 ;
return F_3 ( V_10 -> V_5 , V_6 , V_17 ) ;
}
static int F_11 ( struct V_1 * V_10 , unsigned V_11 )
{
T_2 V_6 = V_10 -> V_12 -> V_18 ;
T_2 V_15 ;
T_2 V_17 ;
T_2 V_16 ;
T_1 V_8 ;
F_9 ( V_11 , 1 , & V_6 , & V_15 , & V_16 ) ;
V_8 = F_6 ( V_10 -> V_5 , V_6 , & V_17 ) ;
if ( V_8 >= 0 )
V_8 = ( V_17 & V_15 ) != 0 ? 1 : 0 ;
return V_8 ;
}
static void F_12 ( struct V_1 * V_10 , int V_7 )
{
F_3 ( V_10 -> V_5 ,
V_10 -> V_12 -> V_19 . V_20 . V_21 ,
( V_7 ? 0x1f : 0x10 ) ) ;
}
static void F_13 ( struct V_1 * V_10 , unsigned V_11 , int V_7 )
{
F_10 ( V_10 ,
V_11 ,
1 ,
V_10 -> V_12 -> V_18 ,
( V_7 ? 1 : 0 ) ) ;
}
static int F_14 ( struct V_1 * V_10 , unsigned V_11 )
{
return F_10 ( V_10 ,
V_11 ,
1 ,
V_10 -> V_12 -> V_22 ,
1 ) ;
}
static int F_15 ( struct V_1 * V_10 , unsigned V_11 , int V_7 )
{
int V_8 ;
V_8 = F_10 ( V_10 ,
V_11 ,
1 ,
V_10 -> V_12 -> V_18 ,
( V_7 ? 1 : 0 ) ) ;
if ( V_8 >= 0 )
V_8 = F_10 ( V_10 ,
V_11 ,
1 ,
V_10 -> V_12 -> V_22 ,
0 ) ;
return V_8 ;
}
static int F_16 ( struct V_2 * V_3 , unsigned V_11 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_23 = - V_24 ;
if ( ! F_8 ( V_10 , V_11 ) ) {
F_17 ( & V_10 -> V_25 ) ;
V_23 = F_11 ( V_10 , V_11 ) ;
F_18 ( & V_10 -> V_25 ) ;
}
return V_23 ;
}
static void F_19 ( struct V_2 * V_3 , unsigned V_11 , int V_7 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
F_17 ( & V_10 -> V_25 ) ;
if ( F_8 ( V_10 , V_11 ) )
F_12 ( V_10 , V_7 ) ;
else
F_13 ( V_10 , V_11 , V_7 ) ;
F_18 ( & V_10 -> V_25 ) ;
}
static int F_20 ( struct V_2 * V_3 , unsigned V_11 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_23 = - V_24 ;
if ( ! F_8 ( V_10 , V_11 ) ) {
F_17 ( & V_10 -> V_25 ) ;
V_23 = F_14 ( V_10 , V_11 ) ;
F_18 ( & V_10 -> V_25 ) ;
}
return V_23 ;
}
static int F_21 ( struct V_2 * V_3 ,
unsigned V_11 ,
int V_7 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_23 = 0 ;
if ( ! F_8 ( V_10 , V_11 ) ) {
F_17 ( & V_10 -> V_25 ) ;
V_23 = F_15 ( V_10 , V_11 , V_7 ) ;
F_18 ( & V_10 -> V_25 ) ;
}
return V_23 ;
}
static void F_22 ( struct V_26 * V_27 )
{
struct V_1 * V_10 = F_1 ( F_23 ( V_27 ) ) ;
unsigned V_28 = V_27 -> V_29 ;
V_10 -> V_30 |= ( 1 << V_28 ) ;
V_10 -> V_31 = V_28 ;
}
static void F_24 ( struct V_26 * V_27 )
{
struct V_1 * V_10 = F_1 ( F_23 ( V_27 ) ) ;
unsigned V_28 = V_27 -> V_29 ;
V_10 -> V_30 &= ~ ( 1 << V_28 ) ;
V_10 -> V_31 = V_28 ;
}
static int F_25 ( struct V_26 * V_27 , unsigned int V_32 )
{
struct V_1 * V_10 = F_1 ( F_23 ( V_27 ) ) ;
unsigned V_28 , V_7 = 0 ;
if ( V_32 & ( V_33 | V_34 ) )
return - V_24 ;
V_28 = V_27 -> V_29 ;
if ( V_32 & V_35 )
V_7 |= 0x1 ;
if ( V_32 & V_36 )
V_7 |= 0x2 ;
V_10 -> V_37 &= ~ ( 3UL << ( V_28 * 2 ) ) ;
V_10 -> V_37 |= V_7 << ( V_28 * 2 ) ;
V_10 -> V_31 = V_28 ;
return 0 ;
}
static T_3 F_26 ( int V_38 , void * V_39 )
{
struct V_1 * V_10 = (struct V_1 * ) V_39 ;
unsigned V_40 = 0 ;
unsigned V_41 ;
unsigned V_28 ;
T_1 V_8 ;
T_2 V_7 ;
int V_42 ;
for ( V_42 = ( V_10 -> V_12 -> V_13 / 8 ) - 1 ; V_42 >= 0 ; -- V_42 ) {
V_8 = F_6 ( V_10 -> V_5 ,
V_10 -> V_12 -> V_43 - V_42 ,
& V_7 ) ;
if ( V_8 < 0 )
continue;
F_3 ( V_10 -> V_5 ,
V_10 -> V_12 -> V_43 - V_42 ,
V_7 ) ;
for ( V_28 = 0 ; V_28 < 8 ; ++ V_28 ) {
if ( V_7 & ( 1 << V_28 ) ) {
V_41 = F_27 (
V_10 -> V_2 . V_44 ,
( V_42 * 8 ) + V_28 ) ;
F_28 ( V_41 ) ;
++ V_40 ;
}
}
}
return ( V_40 > 0 ? V_45 : V_46 ) ;
}
static void F_29 ( struct V_26 * V_27 )
{
struct V_1 * V_10 = F_1 ( F_23 ( V_27 ) ) ;
F_17 ( & V_10 -> V_25 ) ;
}
static void F_30 ( struct V_26 * V_27 )
{
struct V_1 * V_10 = F_1 ( F_23 ( V_27 ) ) ;
unsigned V_28 ;
if ( V_10 -> V_31 == V_47 )
goto V_48;
V_28 = V_10 -> V_31 ;
V_10 -> V_31 = V_47 ;
if ( V_10 -> V_49 == V_10 -> V_37 &&
V_10 -> V_50 == V_10 -> V_30 )
goto V_48;
V_10 -> V_49 = V_10 -> V_37 ;
V_10 -> V_50 = V_10 -> V_30 ;
if ( V_10 -> V_30 & ( 1 << V_28 ) ) {
F_10 ( V_10 , V_28 , 1 , V_10 -> V_12 -> V_51 , 1 ) ;
F_10 ( V_10 , V_28 , 2 , V_10 -> V_12 -> V_52 , 0 ) ;
} else {
F_10 ( V_10 , V_28 , 1 , V_10 -> V_12 -> V_51 , 0 ) ;
F_10 ( V_10 , V_28 , 2 , V_10 -> V_12 -> V_52 ,
V_10 -> V_37 >> ( V_28 * 2 ) ) ;
}
V_48:
F_18 ( & V_10 -> V_25 ) ;
}
static void F_31 ( struct V_1 * V_10 ,
struct V_4 * V_5 ,
T_4 V_53 ,
struct V_54 * V_55 )
{
F_32 ( & V_10 -> V_25 ) ;
V_10 -> V_5 = V_5 ;
V_10 -> V_12 = & V_56 [ V_53 ] ;
V_10 -> V_2 . V_9 = & V_5 -> V_9 ;
V_10 -> V_2 . V_57 = V_5 -> V_58 ;
V_10 -> V_2 . V_59 = F_20 ;
V_10 -> V_2 . V_60 = F_21 ;
V_10 -> V_2 . V_61 = F_16 ;
V_10 -> V_2 . V_62 = F_19 ;
V_10 -> V_2 . V_63 = V_55 -> V_64 ;
V_10 -> V_2 . V_65 = true ;
V_10 -> V_2 . V_66 = V_10 -> V_12 -> V_13 ;
#ifdef F_33
V_10 -> V_2 . V_67 = V_5 -> V_9 . V_67 ;
V_10 -> V_2 . V_68 = 2 ;
#endif
if ( V_55 -> V_69 )
++ V_10 -> V_2 . V_66 ;
V_10 -> V_70 . V_58 = V_5 -> V_58 ;
V_10 -> V_70 . V_71 = F_22 ;
V_10 -> V_70 . V_72 = F_24 ;
V_10 -> V_70 . V_73 = F_25 ;
V_10 -> V_70 . V_74 = F_29 ;
V_10 -> V_70 . V_75 = F_30 ;
V_10 -> V_76 = - 1 ;
V_10 -> V_77 = - 1 ;
V_10 -> V_30 = ~ 0 ;
V_10 -> V_37 = 0 ;
V_10 -> V_50 = ~ 0 ;
V_10 -> V_49 = 0 ;
V_10 -> V_31 = V_47 ;
}
static int F_34 ( struct V_1 * V_10 , T_2 V_63 , T_5 V_78 )
{
int V_8 = 0 ;
unsigned V_28 ;
for ( V_28 = 0 ; V_8 >= 0 && V_28 < ( V_10 -> V_12 -> V_13 / 8 ) ; ++ V_28 )
V_8 = F_3 ( V_10 -> V_5 , V_63 - V_28 , V_78 >> ( V_28 * 8 ) ) ;
return V_8 ;
}
static int F_35 ( struct V_1 * V_10 )
{
int V_8 ;
V_8 = F_4 ( V_10 -> V_5 ,
V_10 -> V_12 -> V_19 . V_20 . V_79 ,
0x12 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_4 ( V_10 -> V_5 ,
V_10 -> V_12 -> V_19 . V_20 . V_79 ,
0x34 ) ;
return V_8 ;
}
static int F_36 ( struct V_1 * V_10 ,
struct V_54 * V_55 )
{
int V_8 = 0 ;
if ( V_55 -> V_80 ) {
V_8 = F_35 ( V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_10 -> V_12 -> V_81 == V_82 )
V_8 = F_3 ( V_10 -> V_5 ,
V_10 -> V_12 -> V_19 . V_20 . V_83 ,
0x01 ) ;
else
V_8 = F_3 ( V_10 -> V_5 ,
V_10 -> V_12 -> V_19 . V_84 . V_85 ,
0x04 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_34 ( V_10 , V_10 -> V_12 -> V_86 ,
V_55 -> V_87 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_34 ( V_10 , V_10 -> V_12 -> V_88 ,
V_55 -> V_89 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_10 -> V_12 -> V_81 == V_82 ) {
V_8 = F_34 ( V_10 ,
V_10 -> V_12 -> V_19 . V_20 . V_90 ,
V_55 -> V_91 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_34 ( V_10 ,
V_10 -> V_12 -> V_19 . V_20 . V_92 ,
V_55 -> V_93 ) ;
if ( V_8 < 0 )
return V_8 ;
} else {
V_8 = F_34 ( V_10 ,
V_10 -> V_12 -> V_19 . V_84 . V_94 ,
0 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_55 -> V_69 )
F_12 ( V_10 , 0 ) ;
return V_8 ;
}
static int F_37 ( struct V_1 * V_10 ,
int V_76 ,
int V_77 )
{
int V_8 ;
V_10 -> V_76 = V_76 ;
V_10 -> V_77 = V_77 ;
V_8 = F_38 ( & V_10 -> V_2 ,
& V_10 -> V_70 , V_10 -> V_77 ,
V_95 , V_96 ) ;
if ( V_8 ) {
F_39 ( & V_10 -> V_5 -> V_9 ,
L_3 ) ;
return V_8 ;
}
V_8 = F_40 ( & V_10 -> V_5 -> V_9 ,
V_76 , NULL , F_26 ,
V_97 | V_98 | V_99 ,
V_10 -> V_70 . V_58 , V_10 ) ;
if ( V_8 < 0 ) {
V_10 -> V_76 = - 1 ;
V_10 -> V_77 = - 1 ;
}
return V_8 ;
}
static int F_41 ( struct V_4 * V_5 ,
const struct V_100 * V_101 )
{
static const T_6 V_102 = V_103 |
V_104 ;
struct V_54 * V_55 ;
struct V_1 * V_10 ;
int V_105 ;
V_55 = F_42 ( & V_5 -> V_9 ) ;
if ( ! V_55 )
return - V_24 ;
if ( ! F_43 ( V_5 -> V_106 , V_102 ) )
return - V_107 ;
V_10 = F_44 ( & V_5 -> V_9 ,
sizeof( struct V_1 ) , V_108 ) ;
if ( ! V_10 )
return - V_109 ;
F_31 ( V_10 , V_5 , V_101 -> V_53 , V_55 ) ;
V_105 = F_36 ( V_10 , V_55 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_45 ( & V_10 -> V_2 ) ;
if ( V_105 )
return V_105 ;
if ( V_55 -> V_76 >= 0 ) {
V_105 = F_37 ( V_10 ,
V_55 -> V_76 ,
V_55 -> V_77 ) ;
if ( V_105 < 0 )
goto V_110;
}
F_46 ( V_5 , V_10 ) ;
return 0 ;
V_110:
F_47 ( & V_10 -> V_2 ) ;
return V_105 ;
}
static int F_48 ( struct V_4 * V_5 )
{
struct V_1 * V_10 ;
V_10 = F_49 ( V_5 ) ;
F_47 ( & V_10 -> V_2 ) ;
return 0 ;
}
static int T_7 F_50 ( void )
{
return F_51 ( & V_111 ) ;
}
static void T_8 F_52 ( void )
{
return F_53 ( & V_111 ) ;
}
