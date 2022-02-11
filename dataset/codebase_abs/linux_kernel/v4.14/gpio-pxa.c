static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
return V_4 ;
}
static inline void T_1 * F_3 ( struct V_2 * V_3 , int V_5 )
{
struct V_1 * V_6 = F_2 ( V_3 ) ;
struct V_7 * V_8 = V_6 -> V_9 + ( V_5 / 32 ) ;
return V_8 -> V_10 ;
}
static inline struct V_7 * F_4 ( struct V_2 * V_3 ,
unsigned V_5 )
{
return F_1 ( V_3 ) -> V_9 + V_5 / 32 ;
}
static inline int F_5 ( int type )
{
return ( type & V_11 ) == 0 ;
}
static inline int F_6 ( int type )
{
return ( type & V_11 ) != 0 ;
}
static inline int F_7 ( int V_5 )
{
if ( ( V_12 == V_13 ) && ( V_5 > 85 ) )
return 1 ;
return 0 ;
}
static inline int F_8 ( struct V_1 * V_14 , unsigned V_5 )
{
void T_1 * V_15 ;
unsigned long V_16 = 0 , V_17 = 0 ;
int V_18 , V_19 = 0 , V_20 = 0 ;
V_15 = F_3 ( & V_14 -> V_21 , V_5 ) ;
V_17 = F_9 ( V_15 + V_22 ) ;
switch ( V_12 ) {
case V_23 :
case V_13 :
case V_24 :
V_16 = F_9 ( V_15 + V_25 ) ;
V_19 = ( V_16 >> ( ( V_5 & 0xf ) * 2 ) ) & 0x3 ;
V_20 = V_17 & F_10 ( V_5 ) ;
if ( F_7 ( V_5 ) )
V_18 = ( V_19 != 1 ) || ( V_20 == 0 ) ;
else
V_18 = ( V_19 != 0 ) || ( V_20 != 0 ) ;
break;
default:
V_18 = V_17 & F_10 ( V_5 ) ;
break;
}
return V_18 ;
}
int F_11 ( int V_26 )
{
struct V_1 * V_14 = V_1 ;
int V_27 ;
V_27 = F_12 ( V_14 -> V_28 , 0 ) ;
if ( V_27 > 0 )
return V_26 - V_27 ;
return V_27 ;
}
static int F_13 ( struct V_2 * V_21 , unsigned V_29 )
{
struct V_1 * V_14 = F_1 ( V_21 ) ;
return F_12 ( V_14 -> V_28 , V_29 ) ;
}
static int F_14 ( struct V_2 * V_21 , unsigned V_29 )
{
void T_1 * V_15 = F_3 ( V_21 , V_29 ) ;
T_2 V_30 , V_31 = F_10 ( V_29 ) ;
unsigned long V_32 ;
int V_18 ;
V_18 = F_15 ( V_21 -> V_15 + V_29 ) ;
if ( ! V_18 )
return 0 ;
F_16 ( & V_33 , V_32 ) ;
V_30 = F_9 ( V_15 + V_22 ) ;
if ( F_7 ( V_21 -> V_15 + V_29 ) )
V_30 |= V_31 ;
else
V_30 &= ~ V_31 ;
F_17 ( V_30 , V_15 + V_22 ) ;
F_18 ( & V_33 , V_32 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_21 ,
unsigned V_29 , int V_30 )
{
void T_1 * V_15 = F_3 ( V_21 , V_29 ) ;
T_2 V_34 , V_31 = F_10 ( V_29 ) ;
unsigned long V_32 ;
int V_18 ;
F_17 ( V_31 , V_15 + ( V_30 ? V_35 : V_36 ) ) ;
V_18 = F_20 ( V_21 -> V_15 + V_29 ) ;
if ( V_18 )
return V_18 ;
F_16 ( & V_33 , V_32 ) ;
V_34 = F_9 ( V_15 + V_22 ) ;
if ( F_7 ( V_21 -> V_15 + V_29 ) )
V_34 &= ~ V_31 ;
else
V_34 |= V_31 ;
F_17 ( V_34 , V_15 + V_22 ) ;
F_18 ( & V_33 , V_32 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_21 , unsigned V_29 )
{
void T_1 * V_15 = F_3 ( V_21 , V_29 ) ;
T_3 V_37 = F_9 ( V_15 + V_38 ) ;
return ! ! ( V_37 & F_10 ( V_29 ) ) ;
}
static void F_22 ( struct V_2 * V_21 , unsigned V_29 , int V_30 )
{
void T_1 * V_15 = F_3 ( V_21 , V_29 ) ;
F_17 ( F_10 ( V_29 ) ,
V_15 + ( V_30 ? V_35 : V_36 ) ) ;
}
static int F_23 ( struct V_2 * V_39 ,
const struct V_40 * V_41 ,
T_3 * V_32 )
{
if ( V_41 -> args [ 0 ] > V_42 )
return - V_43 ;
if ( V_32 )
* V_32 = V_41 -> args [ 1 ] ;
return V_41 -> args [ 0 ] ;
}
static int F_24 ( struct V_2 * V_21 , unsigned int V_29 )
{
return F_25 ( V_21 -> V_15 + V_29 ) ;
}
static void F_26 ( struct V_2 * V_21 , unsigned int V_29 )
{
F_27 ( V_21 -> V_15 + V_29 ) ;
}
static int F_28 ( struct V_1 * V_14 , int V_44 ,
struct V_45 * V_46 , void T_1 * V_10 )
{
int V_47 , V_5 , V_48 = F_29 ( V_44 , 32 ) ;
struct V_7 * V_8 ;
V_14 -> V_9 = F_30 ( V_14 -> V_49 , V_48 , sizeof( * V_14 -> V_9 ) ,
V_50 ) ;
if ( ! V_14 -> V_9 )
return - V_51 ;
V_14 -> V_21 . V_52 = L_1 ;
V_14 -> V_21 . V_53 = F_14 ;
V_14 -> V_21 . V_54 = F_19 ;
V_14 -> V_21 . V_55 = F_21 ;
V_14 -> V_21 . V_56 = F_22 ;
V_14 -> V_21 . V_57 = F_13 ;
V_14 -> V_21 . V_44 = V_44 ;
V_14 -> V_21 . V_58 = F_24 ;
V_14 -> V_21 . free = F_26 ;
#ifdef F_31
V_14 -> V_21 . V_59 = V_46 ;
V_14 -> V_21 . V_60 = F_23 ;
V_14 -> V_21 . V_61 = 2 ;
#endif
for ( V_47 = 0 , V_5 = 0 ; V_47 < V_48 ; V_47 ++ , V_5 += 32 ) {
V_8 = V_14 -> V_9 + V_47 ;
V_8 -> V_10 = V_10 + F_32 ( V_47 ) ;
}
return F_33 ( & V_14 -> V_21 , V_14 ) ;
}
static inline void F_34 ( struct V_7 * V_3 )
{
T_2 V_62 , V_63 ;
V_62 = F_9 ( V_3 -> V_10 + V_64 ) & ~ V_3 -> V_65 ;
V_63 = F_9 ( V_3 -> V_10 + V_66 ) & ~ V_3 -> V_65 ;
V_62 |= V_3 -> V_67 & V_3 -> V_65 ;
V_63 |= V_3 -> V_68 & V_3 -> V_65 ;
F_17 ( V_62 , V_3 -> V_10 + V_64 ) ;
F_17 ( V_63 , V_3 -> V_10 + V_66 ) ;
}
static int F_35 ( struct V_69 * V_70 , unsigned int type )
{
struct V_1 * V_14 = F_36 ( V_70 ) ;
unsigned int V_5 = F_37 ( V_70 ) ;
struct V_7 * V_3 = F_4 ( & V_14 -> V_21 , V_5 ) ;
unsigned long V_17 , V_31 = F_10 ( V_5 ) ;
if ( type == V_71 ) {
if ( ( V_3 -> V_67 | V_3 -> V_68 ) & F_10 ( V_5 ) )
return 0 ;
if ( F_8 ( V_14 , V_5 ) )
return 0 ;
type = V_72 | V_73 ;
}
V_17 = F_9 ( V_3 -> V_10 + V_22 ) ;
if ( F_7 ( V_5 ) )
F_17 ( V_17 | V_31 , V_3 -> V_10 + V_22 ) ;
else
F_17 ( V_17 & ~ V_31 , V_3 -> V_10 + V_22 ) ;
if ( type & V_72 )
V_3 -> V_67 |= V_31 ;
else
V_3 -> V_67 &= ~ V_31 ;
if ( type & V_73 )
V_3 -> V_68 |= V_31 ;
else
V_3 -> V_68 &= ~ V_31 ;
F_34 ( V_3 ) ;
F_38 ( L_2 , V_74 , V_70 -> V_26 , V_5 ,
( ( type & V_72 ) ? L_3 : L_4 ) ,
( ( type & V_73 ) ? L_5 : L_4 ) ) ;
return 0 ;
}
static T_4 F_39 ( int V_75 , void * V_70 )
{
int V_76 , V_5 , V_77 , V_78 = 0 ;
unsigned long V_79 ;
struct V_1 * V_14 = V_70 ;
struct V_7 * V_3 ;
do {
V_76 = 0 ;
F_40 (gpio, c, pchip) {
V_79 = F_9 ( V_3 -> V_10 + V_80 ) ;
V_79 = V_79 & V_3 -> V_65 ;
F_17 ( V_79 , V_3 -> V_10 + V_80 ) ;
F_41 (n, &gedr, BITS_PER_LONG) {
V_76 = 1 ;
F_42 (
F_12 ( V_14 -> V_28 ,
V_5 + V_77 ) ) ;
}
}
V_78 += V_76 ;
} while ( V_76 );
return V_78 ? V_81 : V_82 ;
}
static T_4 F_43 ( int V_75 , void * V_70 )
{
struct V_1 * V_14 = V_70 ;
if ( V_75 == V_14 -> V_83 ) {
F_42 ( F_12 ( V_14 -> V_28 , 0 ) ) ;
} else if ( V_75 == V_14 -> V_84 ) {
F_42 ( F_12 ( V_14 -> V_28 , 1 ) ) ;
} else {
F_44 ( L_6 , V_74 , V_75 ) ;
return V_82 ;
}
return V_81 ;
}
static void F_45 ( struct V_69 * V_70 )
{
struct V_1 * V_14 = F_36 ( V_70 ) ;
unsigned int V_5 = F_37 ( V_70 ) ;
void T_1 * V_15 = F_3 ( & V_14 -> V_21 , V_5 ) ;
F_17 ( F_10 ( V_5 ) , V_15 + V_80 ) ;
}
static void F_46 ( struct V_69 * V_70 )
{
struct V_1 * V_14 = F_36 ( V_70 ) ;
unsigned int V_5 = F_37 ( V_70 ) ;
struct V_7 * V_85 = F_4 ( & V_14 -> V_21 , V_5 ) ;
void T_1 * V_15 = F_3 ( & V_14 -> V_21 , V_5 ) ;
T_2 V_62 , V_63 ;
V_85 -> V_65 &= ~ F_10 ( V_5 ) ;
V_62 = F_9 ( V_15 + V_64 ) & ~ F_10 ( V_5 ) ;
V_63 = F_9 ( V_15 + V_66 ) & ~ F_10 ( V_5 ) ;
F_17 ( V_62 , V_15 + V_64 ) ;
F_17 ( V_63 , V_15 + V_66 ) ;
}
static int F_47 ( struct V_69 * V_70 , unsigned int V_86 )
{
struct V_1 * V_14 = F_36 ( V_70 ) ;
unsigned int V_5 = F_37 ( V_70 ) ;
if ( V_14 -> V_87 )
return V_14 -> V_87 ( V_5 , V_86 ) ;
else
return 0 ;
}
static void F_48 ( struct V_69 * V_70 )
{
struct V_1 * V_14 = F_36 ( V_70 ) ;
unsigned int V_5 = F_37 ( V_70 ) ;
struct V_7 * V_3 = F_4 ( & V_14 -> V_21 , V_5 ) ;
V_3 -> V_65 |= F_10 ( V_5 ) ;
F_34 ( V_3 ) ;
}
static int F_49 ( struct V_88 * V_89 )
{
const struct V_90 * V_91 = F_50 ( V_89 ) ;
struct V_92 * V_93 = (struct V_92 * ) V_91 -> V_94 ;
int V_95 = 0 ;
switch ( V_93 -> type ) {
case V_23 :
case V_13 :
case V_24 :
case V_96 :
case V_97 :
case V_11 :
case V_98 :
case V_99 :
V_12 = V_93 -> type ;
V_95 = V_93 -> V_100 - 1 ;
break;
default:
V_95 = - V_43 ;
break;
}
return V_95 ;
}
static int F_51 ( struct V_101 * V_70 , unsigned int V_26 ,
T_5 V_102 )
{
F_52 ( V_26 , & V_103 ,
V_104 ) ;
F_53 ( V_26 , V_70 -> V_105 ) ;
F_54 ( V_26 ) ;
return 0 ;
}
static int F_55 ( struct V_88 * V_89 ,
struct V_1 * V_14 )
{
int V_106 ;
const struct V_107 * V_108 =
F_56 ( V_109 , & V_89 -> V_49 ) ;
const struct V_92 * V_110 ;
if ( ! V_108 || ! V_108 -> V_111 ) {
F_57 ( & V_89 -> V_49 , L_7 ) ;
return - V_112 ;
}
V_110 = V_108 -> V_111 ;
V_12 = V_110 -> type ;
V_106 = V_110 -> V_100 ;
V_42 = V_106 - 1 ;
V_113 = F_58 ( & V_89 -> V_49 , - 1 , 0 , V_106 , 0 ) ;
if ( V_113 < 0 ) {
F_57 ( & V_89 -> V_49 , L_8 ) ;
return V_113 ;
}
return V_113 ;
}
static int F_59 ( struct V_88 * V_89 )
{
struct V_1 * V_14 ;
struct V_7 * V_3 ;
struct V_114 * V_115 ;
struct V_116 * V_116 ;
struct V_117 * V_118 ;
void T_1 * V_119 ;
int V_5 , V_18 ;
int V_83 = 0 , V_84 = 0 , V_120 , V_121 = 0 ;
V_14 = F_60 ( & V_89 -> V_49 , sizeof( * V_14 ) , V_50 ) ;
if ( ! V_14 )
return - V_51 ;
V_14 -> V_49 = & V_89 -> V_49 ;
V_118 = F_61 ( & V_89 -> V_49 ) ;
if ( V_118 ) {
V_113 = V_118 -> V_113 ;
if ( V_113 <= 0 )
return - V_43 ;
V_42 = F_49 ( V_89 ) ;
V_14 -> V_87 = V_118 -> V_122 ;
} else {
V_113 = F_55 ( V_89 , V_14 ) ;
if ( V_113 < 0 )
return - V_43 ;
}
if ( ! V_42 )
return - V_43 ;
V_14 -> V_28 = F_62 ( V_89 -> V_49 . V_59 ,
V_42 + 1 , V_113 ,
0 , & V_123 , V_14 ) ;
if ( ! V_14 -> V_28 )
return - V_51 ;
V_83 = F_63 ( V_89 , L_9 ) ;
V_84 = F_63 ( V_89 , L_10 ) ;
V_120 = F_63 ( V_89 , L_11 ) ;
if ( ( V_83 > 0 && V_84 <= 0 ) || ( V_83 <= 0 && V_84 > 0 )
|| ( V_120 <= 0 ) )
return - V_43 ;
V_14 -> V_83 = V_83 ;
V_14 -> V_84 = V_84 ;
V_115 = F_64 ( V_89 , V_124 , 0 ) ;
V_119 = F_65 ( & V_89 -> V_49 , V_115 -> V_125 ,
F_66 ( V_115 ) ) ;
if ( ! V_119 )
return - V_43 ;
if ( V_83 > 0 )
V_121 = 2 ;
V_116 = F_67 ( & V_89 -> V_49 , NULL ) ;
if ( F_68 ( V_116 ) ) {
F_57 ( & V_89 -> V_49 , L_12 ,
F_69 ( V_116 ) ) ;
return F_69 ( V_116 ) ;
}
V_18 = F_70 ( V_116 ) ;
if ( V_18 ) {
F_71 ( V_116 ) ;
return V_18 ;
}
V_18 = F_28 ( V_14 , V_42 + 1 , V_89 -> V_49 . V_59 ,
V_119 ) ;
if ( V_18 ) {
F_71 ( V_116 ) ;
return V_18 ;
}
F_40 (gpio, c, pchip) {
F_17 ( 0 , V_3 -> V_10 + V_66 ) ;
F_17 ( 0 , V_3 -> V_10 + V_64 ) ;
F_17 ( ~ 0 , V_3 -> V_10 + V_80 ) ;
if ( F_6 ( V_12 ) )
F_17 ( ~ 0 , V_3 -> V_10 + V_126 ) ;
}
if ( V_83 > 0 ) {
V_18 = F_72 ( & V_89 -> V_49 ,
V_83 , F_43 , 0 ,
L_13 , V_14 ) ;
if ( V_18 )
F_57 ( & V_89 -> V_49 , L_14 ,
V_18 ) ;
}
if ( V_84 > 0 ) {
V_18 = F_72 ( & V_89 -> V_49 ,
V_84 , F_43 , 0 ,
L_15 , V_14 ) ;
if ( V_18 )
F_57 ( & V_89 -> V_49 , L_16 ,
V_18 ) ;
}
V_18 = F_72 ( & V_89 -> V_49 ,
V_120 , F_39 , 0 ,
L_17 , V_14 ) ;
if ( V_18 )
F_57 ( & V_89 -> V_49 , L_18 ,
V_18 ) ;
V_1 = V_14 ;
return 0 ;
}
static int T_6 F_73 ( void )
{
if ( F_74 () )
return 0 ;
return F_75 ( & V_127 ) ;
}
static int T_6 F_76 ( void )
{
if ( F_74 () )
return F_75 ( & V_127 ) ;
return 0 ;
}
static int F_77 ( void )
{
struct V_1 * V_14 = V_1 ;
struct V_7 * V_3 ;
int V_5 ;
F_40 (gpio, c, pchip) {
V_3 -> V_128 = F_9 ( V_3 -> V_10 + V_38 ) ;
V_3 -> V_129 = F_9 ( V_3 -> V_10 + V_22 ) ;
V_3 -> V_130 = F_9 ( V_3 -> V_10 + V_64 ) ;
V_3 -> V_131 = F_9 ( V_3 -> V_10 + V_66 ) ;
F_17 ( 0xffffffff , V_3 -> V_10 + V_80 ) ;
}
return 0 ;
}
static void F_78 ( void )
{
struct V_1 * V_14 = V_1 ;
struct V_7 * V_3 ;
int V_5 ;
F_40 (gpio, c, pchip) {
F_17 ( V_3 -> V_128 , V_3 -> V_10 + V_35 ) ;
F_17 ( ~ V_3 -> V_128 , V_3 -> V_10 + V_36 ) ;
F_17 ( V_3 -> V_130 , V_3 -> V_10 + V_64 ) ;
F_17 ( V_3 -> V_131 , V_3 -> V_10 + V_66 ) ;
F_17 ( V_3 -> V_129 , V_3 -> V_10 + V_22 ) ;
}
}
static int T_6 F_79 ( void )
{
F_80 ( & V_132 ) ;
return 0 ;
}
