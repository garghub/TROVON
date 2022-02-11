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
struct V_7 * V_8 = F_15 ( V_22 ) ;
int V_23 = - V_24 ;
if ( ! F_6 ( V_8 , V_9 ) ) {
F_16 ( & V_8 -> V_25 ) ;
V_23 = F_9 ( V_8 , V_9 ) ;
F_17 ( & V_8 -> V_25 ) ;
}
return ( V_23 < 0 ) ? V_23 : ! ! V_23 ;
}
static void F_18 ( struct V_21 * V_22 , unsigned V_9 , int V_4 )
{
struct V_7 * V_8 = F_15 ( V_22 ) ;
F_16 ( & V_8 -> V_25 ) ;
if ( F_6 ( V_8 , V_9 ) )
F_10 ( V_8 , V_4 ) ;
else
F_11 ( V_8 , V_9 , V_4 ) ;
F_17 ( & V_8 -> V_25 ) ;
}
static int F_19 ( struct V_21 * V_22 ,
unsigned V_9 ,
enum V_26 V_27 )
{
struct V_7 * V_8 = F_15 ( V_22 ) ;
if ( V_8 -> V_10 -> V_28 != V_29 )
return - V_30 ;
if ( V_27 == V_31 )
return F_8 ( V_8 ,
V_9 ,
1 ,
V_8 -> V_10 -> V_17 . V_18 . V_32 ,
0 ) ;
if ( V_27 == V_33 )
return F_8 ( V_8 ,
V_9 ,
1 ,
V_8 -> V_10 -> V_17 . V_18 . V_32 ,
1 ) ;
return - V_30 ;
}
static int F_20 ( struct V_21 * V_22 , unsigned V_9 )
{
struct V_7 * V_8 = F_15 ( V_22 ) ;
int V_23 = - V_24 ;
if ( ! F_6 ( V_8 , V_9 ) ) {
F_16 ( & V_8 -> V_25 ) ;
V_23 = F_12 ( V_8 , V_9 ) ;
F_17 ( & V_8 -> V_25 ) ;
}
return V_23 ;
}
static int F_21 ( struct V_21 * V_22 ,
unsigned V_9 ,
int V_4 )
{
struct V_7 * V_8 = F_15 ( V_22 ) ;
int V_23 = 0 ;
if ( ! F_6 ( V_8 , V_9 ) ) {
F_16 ( & V_8 -> V_25 ) ;
V_23 = F_13 ( V_8 , V_9 , V_4 ) ;
F_17 ( & V_8 -> V_25 ) ;
}
return V_23 ;
}
static void F_22 ( struct V_34 * V_35 )
{
struct V_7 * V_8 = F_15 ( F_23 ( V_35 ) ) ;
unsigned V_36 = V_35 -> V_37 ;
V_8 -> V_38 |= ( 1 << V_36 ) ;
V_8 -> V_39 = V_36 ;
}
static void F_24 ( struct V_34 * V_35 )
{
struct V_7 * V_8 = F_15 ( F_23 ( V_35 ) ) ;
unsigned V_36 = V_35 -> V_37 ;
V_8 -> V_38 &= ~ ( 1 << V_36 ) ;
V_8 -> V_39 = V_36 ;
}
static int F_25 ( struct V_34 * V_35 , unsigned int V_40 )
{
struct V_7 * V_8 = F_15 ( F_23 ( V_35 ) ) ;
unsigned V_36 , V_4 = 0 ;
if ( V_40 & ( V_41 | V_42 ) )
return - V_24 ;
V_36 = V_35 -> V_37 ;
if ( V_40 & V_43 )
V_4 |= 0x1 ;
if ( V_40 & V_44 )
V_4 |= 0x2 ;
V_8 -> V_45 &= ~ ( 3UL << ( V_36 * 2 ) ) ;
V_8 -> V_45 |= V_4 << ( V_36 * 2 ) ;
V_8 -> V_39 = V_36 ;
return 0 ;
}
static T_3 F_26 ( int V_46 , void * V_47 )
{
struct V_7 * V_8 = (struct V_7 * ) V_47 ;
unsigned V_48 = 0 ;
unsigned V_49 ;
unsigned V_36 ;
T_1 V_5 ;
T_2 V_4 ;
int V_50 ;
for ( V_50 = ( V_8 -> V_10 -> V_11 / 8 ) - 1 ; V_50 >= 0 ; -- V_50 ) {
V_5 = F_4 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_51 - V_50 ,
& V_4 ) ;
if ( V_5 < 0 )
continue;
F_1 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_51 - V_50 ,
V_4 ) ;
for ( V_36 = 0 ; V_36 < 8 ; ++ V_36 ) {
if ( V_4 & ( 1 << V_36 ) ) {
V_49 = F_27 (
V_8 -> V_21 . V_52 ,
( V_50 * 8 ) + V_36 ) ;
F_28 ( V_49 ) ;
++ V_48 ;
}
}
}
return ( V_48 > 0 ? V_53 : V_54 ) ;
}
static void F_29 ( struct V_34 * V_35 )
{
struct V_7 * V_8 = F_15 ( F_23 ( V_35 ) ) ;
F_16 ( & V_8 -> V_25 ) ;
}
static void F_30 ( struct V_34 * V_35 )
{
struct V_7 * V_8 = F_15 ( F_23 ( V_35 ) ) ;
unsigned V_36 ;
if ( V_8 -> V_39 == V_55 )
goto V_56;
V_36 = V_8 -> V_39 ;
V_8 -> V_39 = V_55 ;
if ( V_8 -> V_57 == V_8 -> V_45 &&
V_8 -> V_58 == V_8 -> V_38 )
goto V_56;
V_8 -> V_57 = V_8 -> V_45 ;
V_8 -> V_58 = V_8 -> V_38 ;
if ( V_8 -> V_38 & ( 1 << V_36 ) ) {
F_8 ( V_8 , V_36 , 1 , V_8 -> V_10 -> V_59 , 1 ) ;
F_8 ( V_8 , V_36 , 2 , V_8 -> V_10 -> V_60 , 0 ) ;
} else {
F_8 ( V_8 , V_36 , 1 , V_8 -> V_10 -> V_59 , 0 ) ;
F_8 ( V_8 , V_36 , 2 , V_8 -> V_10 -> V_60 ,
V_8 -> V_45 >> ( V_36 * 2 ) ) ;
}
V_56:
F_17 ( & V_8 -> V_25 ) ;
}
static void F_31 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
T_4 V_61 ,
struct V_62 * V_63 )
{
F_32 ( & V_8 -> V_25 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_10 = & V_64 [ V_61 ] ;
V_8 -> V_21 . V_65 = & V_2 -> V_6 ;
V_8 -> V_21 . V_66 = V_2 -> V_67 ;
V_8 -> V_21 . V_68 = F_20 ;
V_8 -> V_21 . V_69 = F_21 ;
V_8 -> V_21 . V_70 = F_14 ;
V_8 -> V_21 . V_71 = F_18 ;
V_8 -> V_21 . V_72 = F_19 ;
V_8 -> V_21 . V_73 = V_63 -> V_74 ;
V_8 -> V_21 . V_75 = true ;
V_8 -> V_21 . V_76 = V_8 -> V_10 -> V_11 ;
#ifdef F_33
V_8 -> V_21 . V_77 = V_2 -> V_6 . V_77 ;
V_8 -> V_21 . V_78 = 2 ;
#endif
if ( V_63 -> V_79 )
++ V_8 -> V_21 . V_76 ;
V_8 -> V_80 . V_67 = V_2 -> V_67 ;
V_8 -> V_80 . V_81 = F_22 ;
V_8 -> V_80 . V_82 = F_24 ;
V_8 -> V_80 . V_83 = F_25 ;
V_8 -> V_80 . V_84 = F_29 ;
V_8 -> V_80 . V_85 = F_30 ;
V_8 -> V_86 = - 1 ;
V_8 -> V_87 = - 1 ;
V_8 -> V_38 = ~ 0 ;
V_8 -> V_45 = 0 ;
V_8 -> V_58 = ~ 0 ;
V_8 -> V_57 = 0 ;
V_8 -> V_39 = V_55 ;
}
static int F_34 ( struct V_7 * V_8 , T_2 V_73 , T_5 V_88 )
{
int V_5 = 0 ;
unsigned V_36 ;
for ( V_36 = 0 ; V_5 >= 0 && V_36 < ( V_8 -> V_10 -> V_11 / 8 ) ; ++ V_36 )
V_5 = F_1 ( V_8 -> V_2 , V_73 - V_36 , V_88 >> ( V_36 * 8 ) ) ;
return V_5 ;
}
static int F_35 ( struct V_7 * V_8 )
{
int V_5 ;
V_5 = F_2 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_17 . V_18 . V_89 ,
0x12 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_17 . V_18 . V_89 ,
0x34 ) ;
return V_5 ;
}
static int F_36 ( struct V_7 * V_8 ,
struct V_62 * V_63 )
{
int V_5 = 0 ;
if ( V_63 -> V_90 ) {
V_5 = F_35 ( V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_8 -> V_10 -> V_28 == V_29 )
V_5 = F_1 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_17 . V_18 . V_91 ,
0x01 ) ;
else if ( V_8 -> V_10 -> V_28 == V_92 )
V_5 = F_1 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_17 . V_93 . V_94 ,
0x04 ) ;
else
V_5 = F_1 ( V_8 -> V_2 ,
V_8 -> V_10 -> V_17 . V_95 . V_94 ,
0x00 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_34 ( V_8 , V_8 -> V_10 -> V_96 ,
V_63 -> V_97 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_34 ( V_8 , V_8 -> V_10 -> V_98 ,
V_63 -> V_99 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_8 -> V_10 -> V_28 == V_29 ) {
V_5 = F_34 ( V_8 ,
V_8 -> V_10 -> V_17 . V_18 . V_100 ,
V_63 -> V_101 ) ;
if ( V_5 < 0 )
return V_5 ;
} else if ( V_8 -> V_10 -> V_28 == V_92 ) {
V_5 = F_34 ( V_8 ,
V_8 -> V_10 -> V_17 . V_93 . V_102 ,
0 ) ;
if ( V_5 < 0 )
return V_5 ;
} else {
V_5 = F_34 ( V_8 ,
V_8 -> V_10 -> V_17 . V_95 . V_102 ,
0 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_63 -> V_79 )
F_10 ( V_8 , 0 ) ;
return V_5 ;
}
static int F_37 ( struct V_7 * V_8 ,
int V_86 ,
int V_87 )
{
int V_5 ;
V_8 -> V_86 = V_86 ;
V_8 -> V_87 = V_87 ;
V_5 = F_38 ( & V_8 -> V_21 ,
& V_8 -> V_80 , V_8 -> V_87 ,
V_103 , V_104 ) ;
if ( V_5 ) {
F_39 ( & V_8 -> V_2 -> V_6 ,
L_3 ) ;
return V_5 ;
}
V_5 = F_40 ( & V_8 -> V_2 -> V_6 ,
V_86 , NULL , F_26 ,
V_105 | V_106 | V_107 ,
V_8 -> V_80 . V_67 , V_8 ) ;
if ( V_5 < 0 ) {
V_8 -> V_86 = - 1 ;
V_8 -> V_87 = - 1 ;
}
return V_5 ;
}
static int F_41 ( struct V_1 * V_2 ,
const struct V_108 * V_109 )
{
static const T_6 V_110 = V_111 |
V_112 ;
struct V_62 * V_63 ;
struct V_7 * V_8 ;
int V_113 ;
V_63 = F_42 ( & V_2 -> V_6 ) ;
if ( ! V_63 )
return - V_24 ;
if ( ! F_43 ( V_2 -> V_114 , V_110 ) )
return - V_115 ;
V_8 = F_44 ( & V_2 -> V_6 ,
sizeof( struct V_7 ) , V_116 ) ;
if ( ! V_8 )
return - V_117 ;
F_31 ( V_8 , V_2 , V_109 -> V_61 , V_63 ) ;
V_113 = F_36 ( V_8 , V_63 ) ;
if ( V_113 < 0 )
return V_113 ;
V_113 = F_45 ( & V_2 -> V_6 , & V_8 -> V_21 , V_8 ) ;
if ( V_113 )
return V_113 ;
if ( V_63 -> V_86 >= 0 ) {
V_113 = F_37 ( V_8 ,
V_63 -> V_86 ,
V_63 -> V_87 ) ;
if ( V_113 < 0 )
return V_113 ;
}
F_46 ( V_2 , V_8 ) ;
return 0 ;
}
static int T_7 F_47 ( void )
{
return F_48 ( & V_118 ) ;
}
