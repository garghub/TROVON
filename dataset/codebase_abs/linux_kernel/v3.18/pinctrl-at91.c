static const inline struct V_1 * F_1 (
const struct V_2 * V_3 ,
const char * V_4 )
{
const struct V_1 * V_5 = NULL ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
if ( strcmp ( V_3 -> V_8 [ V_6 ] . V_4 , V_4 ) )
continue;
V_5 = & V_3 -> V_8 [ V_6 ] ;
F_2 ( V_3 -> V_9 , L_1 , V_4 , V_5 -> V_10 , V_5 -> V_11 [ 0 ] ) ;
break;
}
return V_5 ;
}
static int F_3 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_7 ;
}
static const char * F_5 ( struct V_12 * V_13 ,
unsigned V_14 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_8 [ V_14 ] . V_4 ;
}
static int F_6 ( struct V_12 * V_13 , unsigned V_14 ,
const unsigned * * V_11 ,
unsigned * V_10 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
if ( V_14 >= V_3 -> V_7 )
return - V_15 ;
* V_11 = V_3 -> V_8 [ V_14 ] . V_11 ;
* V_10 = V_3 -> V_8 [ V_14 ] . V_10 ;
return 0 ;
}
static void F_7 ( struct V_12 * V_13 , struct V_16 * V_17 ,
unsigned V_18 )
{
F_8 ( V_17 , L_2 , F_9 ( V_13 -> V_9 ) ) ;
}
static int F_10 ( struct V_12 * V_13 ,
struct V_19 * V_20 ,
struct V_21 * * V_22 , unsigned * V_23 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
const struct V_1 * V_5 ;
struct V_21 * V_24 ;
struct V_19 * V_25 ;
int V_26 = 1 ;
int V_6 ;
V_5 = F_1 ( V_3 , V_20 -> V_4 ) ;
if ( ! V_5 ) {
F_11 ( V_3 -> V_9 , L_3 ,
V_20 -> V_4 ) ;
return - V_15 ;
}
V_26 += V_5 -> V_10 ;
V_24 = F_12 ( V_13 -> V_9 , sizeof( * V_24 ) * V_26 , V_27 ) ;
if ( ! V_24 )
return - V_28 ;
* V_22 = V_24 ;
* V_23 = V_26 ;
V_25 = F_13 ( V_20 ) ;
if ( ! V_25 ) {
F_14 ( V_13 -> V_9 , V_24 ) ;
return - V_15 ;
}
V_24 [ 0 ] . type = V_29 ;
V_24 [ 0 ] . V_30 . V_31 . V_32 = V_25 -> V_4 ;
V_24 [ 0 ] . V_30 . V_31 . V_33 = V_20 -> V_4 ;
F_15 ( V_25 ) ;
V_24 ++ ;
for ( V_6 = 0 ; V_6 < V_5 -> V_10 ; V_6 ++ ) {
V_24 [ V_6 ] . type = V_34 ;
V_24 [ V_6 ] . V_30 . V_35 . V_36 =
F_16 ( V_13 , V_5 -> V_11 [ V_6 ] ) ;
V_24 [ V_6 ] . V_30 . V_35 . V_35 = & V_5 -> V_37 [ V_6 ] . V_38 ;
V_24 [ V_6 ] . V_30 . V_35 . V_39 = 1 ;
}
F_2 ( V_13 -> V_9 , L_4 ,
( * V_22 ) -> V_30 . V_31 . V_32 , ( * V_22 ) -> V_30 . V_31 . V_33 , V_26 ) ;
return 0 ;
}
static void F_17 ( struct V_12 * V_13 ,
struct V_21 * V_22 , unsigned V_23 )
{
}
static void T_1 * F_18 ( struct V_2 * V_3 ,
unsigned int V_40 )
{
return V_41 [ V_40 ] -> V_42 ;
}
static inline int F_19 ( unsigned V_43 )
{
return V_43 /= V_44 ;
}
static unsigned F_20 ( unsigned int V_43 )
{
return 1 << V_43 ;
}
static unsigned F_21 ( unsigned int V_43 )
{
return 2 * ( ( V_43 >= V_44 / 2 )
? V_43 - V_44 / 2 : V_43 ) ;
}
static unsigned F_22 ( unsigned int V_43 )
{
return ( V_43 >= V_44 / 2 )
? V_45 : V_46 ;
}
static unsigned F_23 ( unsigned int V_43 )
{
return ( V_43 >= V_44 / 2 )
? V_47 : V_48 ;
}
static void F_24 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( V_50 , V_49 + V_51 ) ;
}
static unsigned F_26 ( void T_1 * V_49 , unsigned V_43 )
{
return ! ( ( F_27 ( V_49 + V_52 ) >> V_43 ) & 0x1 ) ;
}
static void F_28 ( void T_1 * V_49 , unsigned V_50 , bool V_53 )
{
if ( V_53 )
F_25 ( V_50 , V_49 + V_54 ) ;
F_25 ( V_50 , V_49 + ( V_53 ? V_55 : V_56 ) ) ;
}
static unsigned F_29 ( void T_1 * V_49 , unsigned V_43 )
{
return ( F_27 ( V_49 + V_57 ) >> V_43 ) & 0x1 ;
}
static void F_30 ( void T_1 * V_49 , unsigned V_50 , bool V_53 )
{
F_25 ( V_50 , V_49 + ( V_53 ? V_58 : V_59 ) ) ;
}
static void F_31 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( V_50 , V_49 + V_60 ) ;
}
static void F_32 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( V_50 , V_49 + V_61 ) ;
}
static void F_33 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_62 ) & ~ V_50 ,
V_49 + V_62 ) ;
F_25 ( F_27 ( V_49 + V_63 ) & ~ V_50 ,
V_49 + V_63 ) ;
}
static void F_34 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_62 ) | V_50 ,
V_49 + V_62 ) ;
F_25 ( F_27 ( V_49 + V_63 ) & ~ V_50 ,
V_49 + V_63 ) ;
}
static void F_35 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_62 ) & ~ V_50 , V_49 + V_62 ) ;
F_25 ( F_27 ( V_49 + V_63 ) | V_50 , V_49 + V_63 ) ;
}
static void F_36 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_62 ) | V_50 , V_49 + V_62 ) ;
F_25 ( F_27 ( V_49 + V_63 ) | V_50 , V_49 + V_63 ) ;
}
static enum V_64 F_37 ( void T_1 * V_49 , unsigned V_50 )
{
unsigned V_65 ;
if ( F_27 ( V_49 + V_66 ) & V_50 )
return V_67 ;
V_65 = ! ! ( F_27 ( V_49 + V_62 ) & V_50 ) ;
V_65 |= ( ! ! ( F_27 ( V_49 + V_63 ) & V_50 ) << 1 ) ;
return V_65 + 1 ;
}
static enum V_64 F_38 ( void T_1 * V_49 , unsigned V_50 )
{
unsigned V_65 ;
if ( F_27 ( V_49 + V_66 ) & V_50 )
return V_67 ;
V_65 = F_27 ( V_49 + V_68 ) & V_50 ;
return V_65 + 1 ;
}
static bool F_39 ( void T_1 * V_49 , unsigned V_43 )
{
return ( F_40 ( V_49 + V_69 ) >> V_43 ) & 0x1 ;
}
static void F_41 ( void T_1 * V_49 , unsigned V_50 , bool V_70 )
{
F_42 ( V_50 , V_49 + ( V_70 ? V_71 : V_72 ) ) ;
}
static bool F_43 ( void T_1 * V_49 , unsigned V_43 )
{
if ( ( F_40 ( V_49 + V_69 ) >> V_43 ) & 0x1 )
return ! ( ( F_40 ( V_49 + V_73 ) >> V_43 ) & 0x1 ) ;
return false ;
}
static void F_44 ( void T_1 * V_49 , unsigned V_50 , bool V_70 )
{
if ( V_70 )
F_42 ( V_50 , V_49 + V_74 ) ;
F_41 ( V_49 , V_50 , V_70 ) ;
}
static bool F_45 ( void T_1 * V_49 , unsigned V_43 , T_2 * div )
{
* div = F_40 ( V_49 + V_75 ) ;
return ( ( F_40 ( V_49 + V_69 ) >> V_43 ) & 0x1 ) &&
( ( F_40 ( V_49 + V_73 ) >> V_43 ) & 0x1 ) ;
}
static void F_46 ( void T_1 * V_49 , unsigned V_50 ,
bool V_70 , T_2 div )
{
if ( V_70 ) {
F_42 ( V_50 , V_49 + V_76 ) ;
F_42 ( div & V_77 , V_49 + V_75 ) ;
F_42 ( V_50 , V_49 + V_71 ) ;
} else
F_42 ( V_50 , V_49 + V_74 ) ;
}
static bool F_47 ( void T_1 * V_49 , unsigned V_43 )
{
return ! ( ( F_40 ( V_49 + V_78 ) >> V_43 ) & 0x1 ) ;
}
static void F_48 ( void T_1 * V_49 , unsigned V_50 , bool V_70 )
{
if ( V_70 )
F_42 ( V_50 , V_49 + V_56 ) ;
F_42 ( V_50 , V_49 + ( V_70 ? V_79 : V_54 ) ) ;
}
static void F_49 ( void T_1 * V_49 , unsigned V_50 )
{
F_42 ( F_40 ( V_49 + V_80 ) | V_50 , V_49 + V_80 ) ;
}
static bool F_50 ( void T_1 * V_49 , unsigned V_43 )
{
return ( F_40 ( V_49 + V_80 ) >> V_43 ) & 0x1 ;
}
static inline T_2 F_51 ( void T_1 * V_81 , unsigned V_43 )
{
unsigned V_82 = F_40 ( V_81 ) ;
V_82 = V_82 >> F_21 ( V_43 ) ;
return V_82 & V_83 ;
}
static unsigned F_52 ( void T_1 * V_49 ,
unsigned V_43 )
{
unsigned V_82 = F_51 ( V_49 +
F_22 ( V_43 ) , V_43 ) ;
if ( ! V_82 )
V_82 = V_84 ;
return V_82 ;
}
static unsigned F_53 ( void T_1 * V_49 ,
unsigned V_43 )
{
unsigned V_82 = F_51 ( V_49 +
F_23 ( V_43 ) , V_43 ) ;
V_82 = V_85 - V_82 ;
return V_82 ;
}
static void F_54 ( void T_1 * V_81 , unsigned V_43 , T_2 V_86 )
{
unsigned V_82 = F_40 ( V_81 ) ;
unsigned V_87 = F_21 ( V_43 ) ;
V_82 &= ~ ( V_83 << V_87 ) ;
V_82 |= V_86 << V_87 ;
F_42 ( V_82 , V_81 ) ;
}
static void F_55 ( void T_1 * V_49 , unsigned V_43 ,
T_2 V_88 )
{
if ( ! V_88 )
return;
F_54 ( V_49 + F_22 ( V_43 ) , V_43 , V_88 ) ;
}
static void F_56 ( void T_1 * V_49 , unsigned V_43 ,
T_2 V_88 )
{
if ( ! V_88 )
return;
V_88 = V_85 - V_88 ;
F_54 ( V_49 + F_23 ( V_43 ) , V_43 ,
V_88 ) ;
}
static void F_57 ( const struct V_89 * V_9 , const struct V_90 * V_43 )
{
if ( V_43 -> V_31 ) {
F_2 ( V_9 , L_5 ,
V_43 -> V_40 + 'A' , V_43 -> V_43 , V_43 -> V_31 - 1 + 'A' , V_43 -> V_38 ) ;
} else {
F_2 ( V_9 , L_6 ,
V_43 -> V_40 + 'A' , V_43 -> V_43 , V_43 -> V_38 ) ;
}
}
static int F_58 ( struct V_2 * V_3 , const char * V_4 ,
int V_91 , const struct V_90 * V_43 )
{
int V_31 ;
if ( V_43 -> V_40 >= V_3 -> V_92 ) {
F_11 ( V_3 -> V_9 , L_7 ,
V_4 , V_91 , V_43 -> V_40 , V_3 -> V_92 ) ;
return - V_15 ;
}
if ( V_43 -> V_43 >= V_44 ) {
F_11 ( V_3 -> V_9 , L_8 ,
V_4 , V_91 , V_43 -> V_43 , V_44 ) ;
return - V_15 ;
}
if ( ! V_43 -> V_31 )
return 0 ;
V_31 = V_43 -> V_31 - 1 ;
if ( V_31 >= V_3 -> V_93 ) {
F_11 ( V_3 -> V_9 , L_9 ,
V_4 , V_91 , V_31 , V_3 -> V_93 ) ;
return - V_15 ;
}
if ( ! ( V_3 -> V_94 [ V_43 -> V_40 * V_3 -> V_93 + V_31 ] & 1 << V_43 -> V_43 ) ) {
F_11 ( V_3 -> V_9 , L_10 ,
V_4 , V_91 , V_31 , V_43 -> V_40 + 'A' , V_43 -> V_43 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_59 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( V_50 , V_49 + V_95 ) ;
}
static void F_60 ( void T_1 * V_49 , unsigned V_50 , bool V_96 )
{
F_25 ( V_50 , V_49 + V_97 ) ;
F_25 ( V_50 , V_49 + ( V_96 ? V_98 : V_99 ) ) ;
}
static int F_61 ( struct V_12 * V_13 , unsigned V_14 ,
unsigned V_33 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
const struct V_90 * V_37 = V_3 -> V_8 [ V_33 ] . V_37 ;
const struct V_90 * V_43 ;
T_3 V_10 = V_3 -> V_8 [ V_33 ] . V_10 ;
int V_6 , V_100 ;
unsigned V_50 ;
void T_1 * V_49 ;
F_2 ( V_3 -> V_9 , L_11 ,
V_3 -> V_101 [ V_14 ] . V_4 , V_3 -> V_8 [ V_33 ] . V_4 ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_43 = & V_37 [ V_6 ] ;
V_100 = F_58 ( V_3 , V_3 -> V_8 [ V_33 ] . V_4 , V_6 , V_43 ) ;
if ( V_100 )
return V_100 ;
}
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_43 = & V_37 [ V_6 ] ;
F_57 ( V_3 -> V_9 , V_43 ) ;
V_49 = F_18 ( V_3 , V_43 -> V_40 ) ;
V_50 = F_20 ( V_43 -> V_43 ) ;
F_24 ( V_49 , V_50 ) ;
switch ( V_43 -> V_31 ) {
case V_67 :
F_60 ( V_49 , V_50 , 1 ) ;
break;
case V_102 :
V_3 -> V_103 -> V_104 ( V_49 , V_50 ) ;
break;
case V_105 :
V_3 -> V_103 -> V_106 ( V_49 , V_50 ) ;
break;
case V_107 :
if ( ! V_3 -> V_103 -> V_108 )
return - V_15 ;
V_3 -> V_103 -> V_108 ( V_49 , V_50 ) ;
break;
case V_109 :
if ( ! V_3 -> V_103 -> V_110 )
return - V_15 ;
V_3 -> V_103 -> V_110 ( V_49 , V_50 ) ;
break;
}
if ( V_43 -> V_31 )
F_59 ( V_49 , V_50 ) ;
}
return 0 ;
}
static int F_62 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_111 ;
}
static const char * F_63 ( struct V_12 * V_13 ,
unsigned V_14 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_101 [ V_14 ] . V_4 ;
}
static int F_64 ( struct V_12 * V_13 , unsigned V_14 ,
const char * const * * V_8 ,
unsigned * const V_112 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_8 = V_3 -> V_101 [ V_14 ] . V_8 ;
* V_112 = V_3 -> V_101 [ V_14 ] . V_7 ;
return 0 ;
}
static int F_65 ( struct V_12 * V_13 ,
struct V_113 * V_114 ,
unsigned V_18 )
{
struct V_2 * V_115 = F_4 ( V_13 ) ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
unsigned V_50 ;
if ( ! V_114 ) {
F_11 ( V_115 -> V_9 , L_12 ) ;
return - V_15 ;
}
if ( ! V_114 -> V_120 ) {
F_11 ( V_115 -> V_9 , L_13 ) ;
return - V_15 ;
}
V_119 = V_114 -> V_120 ;
V_117 = F_66 ( V_119 , struct V_116 , V_119 ) ;
F_2 ( V_115 -> V_9 , L_14 , V_18 ) ;
V_50 = 1 << ( V_18 - V_119 -> V_121 ) ;
F_2 ( V_115 -> V_9 , L_15 ,
V_18 , 'A' + V_114 -> V_122 , V_18 - V_119 -> V_121 , V_50 ) ;
F_25 ( V_50 , V_117 -> V_42 + V_97 ) ;
return 0 ;
}
static void F_67 ( struct V_12 * V_13 ,
struct V_113 * V_114 ,
unsigned V_18 )
{
struct V_2 * V_115 = F_4 ( V_13 ) ;
F_2 ( V_115 -> V_9 , L_16 , V_18 ) ;
}
static int F_68 ( struct V_12 * V_13 ,
unsigned V_123 , unsigned long * V_124 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
void T_1 * V_49 ;
unsigned V_43 ;
int div ;
* V_124 = 0 ;
F_2 ( V_3 -> V_9 , L_17 , V_125 , __LINE__ , V_123 ) ;
V_49 = F_18 ( V_3 , F_19 ( V_123 ) ) ;
V_43 = V_123 % V_44 ;
if ( F_29 ( V_49 , V_43 ) )
* V_124 |= V_126 ;
if ( F_26 ( V_49 , V_43 ) )
* V_124 |= V_127 ;
if ( V_3 -> V_103 -> V_128 && V_3 -> V_103 -> V_128 ( V_49 , V_43 ) )
* V_124 |= V_129 ;
if ( V_3 -> V_103 -> V_130 && V_3 -> V_103 -> V_130 ( V_49 , V_43 , & div ) )
* V_124 |= V_131 | ( div << V_132 ) ;
if ( V_3 -> V_103 -> V_133 && V_3 -> V_103 -> V_133 ( V_49 , V_43 ) )
* V_124 |= V_134 ;
if ( V_3 -> V_103 -> V_135 && V_3 -> V_103 -> V_135 ( V_49 , V_43 ) )
* V_124 |= V_136 ;
if ( V_3 -> V_103 -> V_137 )
* V_124 |= ( V_3 -> V_103 -> V_137 ( V_49 , V_43 )
<< V_138 ) ;
return 0 ;
}
static int F_69 ( struct V_12 * V_13 ,
unsigned V_123 , unsigned long * V_35 ,
unsigned V_39 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
unsigned V_50 ;
void T_1 * V_49 ;
int V_6 ;
unsigned long V_124 ;
unsigned V_43 ;
for ( V_6 = 0 ; V_6 < V_39 ; V_6 ++ ) {
V_124 = V_35 [ V_6 ] ;
F_2 ( V_3 -> V_9 ,
L_18 ,
V_125 , __LINE__ , V_123 , V_124 ) ;
V_49 = F_18 ( V_3 , F_19 ( V_123 ) ) ;
V_43 = V_123 % V_44 ;
V_50 = F_20 ( V_43 ) ;
if ( V_124 & V_127 && V_124 & V_134 )
return - V_15 ;
F_28 ( V_49 , V_50 , V_124 & V_127 ) ;
F_30 ( V_49 , V_50 , V_124 & V_126 ) ;
if ( V_3 -> V_103 -> V_139 )
V_3 -> V_103 -> V_139 ( V_49 , V_50 , V_124 & V_129 ) ;
if ( V_3 -> V_103 -> V_140 )
V_3 -> V_103 -> V_140 ( V_49 , V_50 , V_124 & V_131 ,
( V_124 & V_141 ) >> V_132 ) ;
if ( V_3 -> V_103 -> V_142 )
V_3 -> V_103 -> V_142 ( V_49 , V_50 , V_124 & V_134 ) ;
if ( V_3 -> V_103 -> V_143 && V_124 & V_136 )
V_3 -> V_103 -> V_143 ( V_49 , V_50 ) ;
if ( V_3 -> V_103 -> V_144 )
V_3 -> V_103 -> V_144 ( V_49 , V_43 ,
( V_124 & V_145 )
>> V_138 ) ;
}
return 0 ;
}
static void F_70 ( struct V_12 * V_13 ,
struct V_16 * V_17 , unsigned V_123 )
{
unsigned long V_124 ;
int V_146 , V_147 = 0 ;
F_68 ( V_13 , V_123 , & V_124 ) ;
F_71 ( V_126 ) ;
F_71 ( V_127 ) ;
F_71 ( V_134 ) ;
F_71 ( V_136 ) ;
F_71 ( V_129 ) ;
F_72 ( V_145 , V_84 ) ;
F_72 ( V_145 , V_148 ) ;
F_72 ( V_145 , V_85 ) ;
F_71 ( V_131 ) ;
if ( V_124 & V_131 ) {
V_146 = V_124 >> V_132 ;
F_8 ( V_17 , L_19 , V_146 ) ;
}
return;
}
static void F_73 ( struct V_12 * V_13 ,
struct V_16 * V_17 , unsigned V_33 )
{
}
static void F_74 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_19 * V_149 ;
F_75 (np, child) {
if ( F_76 ( V_149 , V_150 ) ) {
V_3 -> V_92 ++ ;
} else {
V_3 -> V_111 ++ ;
V_3 -> V_7 += F_77 ( V_149 ) ;
}
}
}
static int F_78 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
int V_100 = 0 ;
int V_151 ;
const T_4 * V_152 ;
V_152 = F_79 ( V_20 , L_20 , & V_151 ) ;
if ( ! V_152 ) {
F_11 ( V_3 -> V_9 , L_21 , V_151 ) ;
return - V_15 ;
}
V_151 /= sizeof( * V_152 ) ;
if ( ! V_151 || V_151 % V_3 -> V_92 ) {
F_11 ( V_3 -> V_9 , L_22 , V_3 -> V_92 ) ;
return - V_15 ;
}
V_3 -> V_93 = V_151 / V_3 -> V_92 ;
V_3 -> V_94 = F_12 ( V_3 -> V_9 , sizeof( T_2 ) * V_151 , V_27 ) ;
if ( ! V_3 -> V_94 ) {
F_11 ( V_3 -> V_9 , L_23 ) ;
return - V_28 ;
}
V_100 = F_80 ( V_20 , L_20 ,
V_3 -> V_94 , V_151 ) ;
if ( V_100 )
F_11 ( V_3 -> V_9 , L_21 , V_151 ) ;
return V_100 ;
}
static int F_81 ( struct V_19 * V_20 ,
struct V_1 * V_5 ,
struct V_2 * V_3 , T_2 V_91 )
{
struct V_90 * V_43 ;
int V_151 ;
const T_4 * V_152 ;
int V_6 , V_153 ;
F_2 ( V_3 -> V_9 , L_24 , V_91 , V_20 -> V_4 ) ;
V_5 -> V_4 = V_20 -> V_4 ;
V_152 = F_79 ( V_20 , L_25 , & V_151 ) ;
V_151 /= sizeof( * V_152 ) ;
if ( ! V_151 || V_151 % 4 ) {
F_11 ( V_3 -> V_9 , L_26 ) ;
return - V_15 ;
}
V_5 -> V_10 = V_151 / 4 ;
V_43 = V_5 -> V_37 = F_12 ( V_3 -> V_9 , V_5 -> V_10 * sizeof( struct V_90 ) ,
V_27 ) ;
V_5 -> V_11 = F_12 ( V_3 -> V_9 , V_5 -> V_10 * sizeof( unsigned int ) ,
V_27 ) ;
if ( ! V_5 -> V_37 || ! V_5 -> V_11 )
return - V_28 ;
for ( V_6 = 0 , V_153 = 0 ; V_6 < V_151 ; V_6 += 4 , V_153 ++ ) {
V_43 -> V_40 = F_82 ( * V_152 ++ ) ;
V_43 -> V_43 = F_82 ( * V_152 ++ ) ;
V_5 -> V_11 [ V_153 ] = V_43 -> V_40 * V_44 + V_43 -> V_43 ;
V_43 -> V_31 = F_82 ( * V_152 ++ ) ;
V_43 -> V_38 = F_82 ( * V_152 ++ ) ;
F_57 ( V_3 -> V_9 , V_43 ) ;
V_43 ++ ;
}
return 0 ;
}
static int F_83 ( struct V_19 * V_20 ,
struct V_2 * V_3 , T_2 V_91 )
{
struct V_19 * V_149 ;
struct V_154 * V_155 ;
struct V_1 * V_5 ;
int V_100 ;
static T_2 V_156 ;
T_2 V_6 = 0 ;
F_2 ( V_3 -> V_9 , L_27 , V_91 , V_20 -> V_4 ) ;
V_155 = & V_3 -> V_101 [ V_91 ] ;
V_155 -> V_4 = V_20 -> V_4 ;
V_155 -> V_7 = F_77 ( V_20 ) ;
if ( V_155 -> V_7 == 0 ) {
F_11 ( V_3 -> V_9 , L_28 ) ;
return - V_15 ;
}
V_155 -> V_8 = F_12 ( V_3 -> V_9 ,
V_155 -> V_7 * sizeof( char * ) , V_27 ) ;
if ( ! V_155 -> V_8 )
return - V_28 ;
F_75 (np, child) {
V_155 -> V_8 [ V_6 ] = V_149 -> V_4 ;
V_5 = & V_3 -> V_8 [ V_156 ++ ] ;
V_100 = F_81 ( V_149 , V_5 , V_3 , V_6 ++ ) ;
if ( V_100 )
return V_100 ;
}
return 0 ;
}
static int F_84 ( struct V_157 * V_158 ,
struct V_2 * V_3 )
{
int V_100 = 0 ;
int V_6 , V_153 ;
T_3 * V_82 ;
struct V_19 * V_20 = V_158 -> V_9 . V_159 ;
struct V_19 * V_149 ;
if ( ! V_20 )
return - V_160 ;
V_3 -> V_9 = & V_158 -> V_9 ;
V_3 -> V_103 = (struct V_161 * )
F_85 ( V_162 , & V_158 -> V_9 ) -> V_30 ;
F_74 ( V_3 , V_20 ) ;
if ( V_3 -> V_92 < 1 ) {
F_11 ( & V_158 -> V_9 , L_29 ) ;
return - V_15 ;
}
V_100 = F_78 ( V_3 , V_20 ) ;
if ( V_100 )
return V_100 ;
F_2 ( & V_158 -> V_9 , L_30 , V_3 -> V_93 ) ;
F_2 ( & V_158 -> V_9 , L_31 ) ;
V_82 = V_3 -> V_94 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_92 ; V_6 ++ ) {
for ( V_153 = 0 ; V_153 < V_3 -> V_93 ; V_153 ++ , V_82 ++ ) {
F_2 ( & V_158 -> V_9 , L_32 , V_6 , V_153 , V_82 [ 0 ] ) ;
}
}
F_2 ( & V_158 -> V_9 , L_33 , V_3 -> V_111 ) ;
F_2 ( & V_158 -> V_9 , L_34 , V_3 -> V_7 ) ;
V_3 -> V_101 = F_12 ( & V_158 -> V_9 , V_3 -> V_111 * sizeof( struct V_154 ) ,
V_27 ) ;
if ( ! V_3 -> V_101 )
return - V_28 ;
V_3 -> V_8 = F_12 ( & V_158 -> V_9 , V_3 -> V_7 * sizeof( struct V_1 ) ,
V_27 ) ;
if ( ! V_3 -> V_8 )
return - V_28 ;
F_2 ( & V_158 -> V_9 , L_35 , V_3 -> V_92 ) ;
F_2 ( & V_158 -> V_9 , L_33 , V_3 -> V_111 ) ;
F_2 ( & V_158 -> V_9 , L_34 , V_3 -> V_7 ) ;
V_6 = 0 ;
F_75 (np, child) {
if ( F_76 ( V_149 , V_150 ) )
continue;
V_100 = F_83 ( V_149 , V_3 , V_6 ++ ) ;
if ( V_100 ) {
F_11 ( & V_158 -> V_9 , L_36 ) ;
return V_100 ;
}
}
return 0 ;
}
static int F_86 ( struct V_157 * V_158 )
{
struct V_2 * V_3 ;
struct V_163 * V_164 ;
int V_100 , V_6 , V_153 , V_165 ;
V_3 = F_12 ( & V_158 -> V_9 , sizeof( * V_3 ) , V_27 ) ;
if ( ! V_3 )
return - V_28 ;
V_100 = F_84 ( V_158 , V_3 ) ;
if ( V_100 )
return V_100 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_92 ; V_6 ++ ) {
if ( ! V_41 [ V_6 ] ) {
F_87 ( & V_158 -> V_9 , L_37 , V_6 ) ;
F_14 ( & V_158 -> V_9 , V_3 ) ;
return - V_166 ;
}
}
V_167 . V_4 = F_9 ( & V_158 -> V_9 ) ;
V_167 . V_10 = V_3 -> V_92 * V_44 ;
V_167 . V_11 = V_164 =
F_12 ( & V_158 -> V_9 , sizeof( * V_164 ) * V_167 . V_10 , V_27 ) ;
if ( ! V_167 . V_11 )
return - V_28 ;
for ( V_6 = 0 , V_165 = 0 ; V_6 < V_3 -> V_92 ; V_6 ++ ) {
for ( V_153 = 0 ; V_153 < V_44 ; V_153 ++ , V_165 ++ ) {
V_164 -> V_168 = V_165 ;
V_164 -> V_4 = F_88 ( V_27 , L_38 , V_6 + 'A' , V_153 ) ;
V_164 ++ ;
}
}
F_89 ( V_158 , V_3 ) ;
V_3 -> V_169 = F_90 ( & V_167 , & V_158 -> V_9 , V_3 ) ;
if ( ! V_3 -> V_169 ) {
F_11 ( & V_158 -> V_9 , L_39 ) ;
V_100 = - V_15 ;
goto V_170;
}
for ( V_6 = 0 ; V_6 < V_3 -> V_92 ; V_6 ++ )
F_91 ( V_3 -> V_169 , & V_41 [ V_6 ] -> V_114 ) ;
F_92 ( & V_158 -> V_9 , L_40 ) ;
return 0 ;
V_170:
return V_100 ;
}
static int F_93 ( struct V_157 * V_158 )
{
struct V_2 * V_3 = F_94 ( V_158 ) ;
F_95 ( V_3 -> V_169 ) ;
return 0 ;
}
static int F_96 ( struct V_118 * V_119 , unsigned V_18 )
{
int V_171 = V_119 -> V_121 + V_18 ;
int V_40 = V_119 -> V_121 / V_119 -> V_172 ;
F_2 ( V_119 -> V_9 , L_41 , V_125 , __LINE__ ,
'A' + V_40 , V_18 , V_171 ) ;
return F_97 ( V_171 ) ;
}
static void F_98 ( struct V_118 * V_119 , unsigned V_18 )
{
int V_171 = V_119 -> V_121 + V_18 ;
F_99 ( V_171 ) ;
}
static int F_100 ( struct V_118 * V_119 , unsigned V_18 )
{
struct V_116 * V_173 = F_101 ( V_119 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
T_2 V_174 ;
V_174 = F_27 ( V_49 + V_175 ) ;
return ! ( V_174 & V_50 ) ;
}
static int F_102 ( struct V_118 * V_119 , unsigned V_18 )
{
struct V_116 * V_173 = F_101 ( V_119 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
F_25 ( V_50 , V_49 + V_98 ) ;
return 0 ;
}
static int F_103 ( struct V_118 * V_119 , unsigned V_18 )
{
struct V_116 * V_173 = F_101 ( V_119 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
T_2 V_176 ;
V_176 = F_27 ( V_49 + V_177 ) ;
return ( V_176 & V_50 ) != 0 ;
}
static void F_104 ( struct V_118 * V_119 , unsigned V_18 ,
int V_146 )
{
struct V_116 * V_173 = F_101 ( V_119 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
F_25 ( V_50 , V_49 + ( V_146 ? V_178 : V_179 ) ) ;
}
static int F_105 ( struct V_118 * V_119 , unsigned V_18 ,
int V_146 )
{
struct V_116 * V_173 = F_101 ( V_119 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
F_25 ( V_50 , V_49 + ( V_146 ? V_178 : V_179 ) ) ;
F_25 ( V_50 , V_49 + V_99 ) ;
return 0 ;
}
static void F_106 ( struct V_16 * V_17 , struct V_118 * V_119 )
{
enum V_64 V_180 ;
int V_6 ;
struct V_116 * V_173 = F_101 ( V_119 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
for ( V_6 = 0 ; V_6 < V_119 -> V_172 ; V_6 ++ ) {
unsigned V_50 = F_20 ( V_6 ) ;
const char * V_181 ;
T_2 V_176 ;
V_181 = F_107 ( V_119 , V_6 ) ;
if ( ! V_181 )
continue;
V_180 = V_173 -> V_103 -> V_182 ( V_49 , V_50 ) ;
F_8 ( V_17 , L_42 ,
V_181 , V_119 -> V_183 , V_6 ) ;
if ( V_180 == V_67 ) {
V_176 = F_27 ( V_49 + V_177 ) ;
F_8 ( V_17 , L_43 ,
V_176 & V_50 ?
L_44 : L_45 ) ;
} else {
F_8 ( V_17 , L_46 ,
V_180 + 'A' - 1 ) ;
}
}
}
static void F_108 ( struct V_184 * V_185 )
{
struct V_116 * V_173 = F_109 ( V_185 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_185 -> V_186 ;
if ( V_49 )
F_25 ( V_50 , V_49 + V_51 ) ;
}
static void F_110 ( struct V_184 * V_185 )
{
struct V_116 * V_173 = F_109 ( V_185 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_185 -> V_186 ;
if ( V_49 )
F_25 ( V_50 , V_49 + V_187 ) ;
}
static int F_111 ( struct V_184 * V_185 , unsigned type )
{
switch ( type ) {
case V_188 :
case V_189 :
return 0 ;
default:
return - V_15 ;
}
}
static int F_112 ( struct V_184 * V_185 , unsigned type )
{
struct V_116 * V_173 = F_109 ( V_185 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_185 -> V_186 ;
switch ( type ) {
case V_190 :
F_113 ( V_185 -> V_191 , V_192 ) ;
F_25 ( V_50 , V_49 + V_193 ) ;
F_25 ( V_50 , V_49 + V_194 ) ;
break;
case V_195 :
F_113 ( V_185 -> V_191 , V_192 ) ;
F_25 ( V_50 , V_49 + V_193 ) ;
F_25 ( V_50 , V_49 + V_196 ) ;
break;
case V_197 :
F_113 ( V_185 -> V_191 , V_198 ) ;
F_25 ( V_50 , V_49 + V_199 ) ;
F_25 ( V_50 , V_49 + V_196 ) ;
break;
case V_200 :
F_113 ( V_185 -> V_191 , V_198 ) ;
F_25 ( V_50 , V_49 + V_199 ) ;
F_25 ( V_50 , V_49 + V_194 ) ;
break;
case V_189 :
F_113 ( V_185 -> V_191 , V_192 ) ;
F_25 ( V_50 , V_49 + V_201 ) ;
return 0 ;
case V_188 :
default:
F_114 ( L_47 , F_115 ( V_185 -> V_191 ) ) ;
return - V_15 ;
}
F_25 ( V_50 , V_49 + V_202 ) ;
return 0 ;
}
static void F_116 ( struct V_184 * V_185 )
{
}
static unsigned int F_117 ( struct V_184 * V_185 )
{
struct V_116 * V_173 = F_109 ( V_185 ) ;
unsigned V_43 = V_185 -> V_186 ;
int V_100 ;
V_100 = F_118 ( & V_173 -> V_119 , V_43 ) ;
if ( V_100 ) {
F_11 ( V_173 -> V_119 . V_9 , L_48 ,
V_185 -> V_186 ) ;
return V_100 ;
}
F_110 ( V_185 ) ;
return 0 ;
}
static void F_119 ( struct V_184 * V_185 )
{
struct V_116 * V_173 = F_109 ( V_185 ) ;
unsigned V_43 = V_185 -> V_186 ;
F_108 ( V_185 ) ;
F_120 ( & V_173 -> V_119 , V_43 ) ;
}
static int F_121 ( struct V_184 * V_185 , unsigned V_203 )
{
struct V_116 * V_173 = F_109 ( V_185 ) ;
unsigned V_40 = V_173 -> V_204 ;
unsigned V_50 = 1 << V_185 -> V_186 ;
if ( F_122 ( V_40 >= V_205 ) )
return - V_15 ;
if ( V_203 )
V_206 [ V_40 ] |= V_50 ;
else
V_206 [ V_40 ] &= ~ V_50 ;
F_123 ( V_173 -> V_207 , V_203 ) ;
return 0 ;
}
void F_124 ( void )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_208 ; V_6 ++ ) {
void T_1 * V_49 ;
if ( ! V_41 [ V_6 ] )
continue;
V_49 = V_41 [ V_6 ] -> V_42 ;
V_209 [ V_6 ] = F_40 ( V_49 + V_210 ) ;
F_42 ( V_209 [ V_6 ] , V_49 + V_51 ) ;
F_42 ( V_206 [ V_6 ] , V_49 + V_187 ) ;
if ( ! V_206 [ V_6 ] )
F_125 ( V_41 [ V_6 ] -> clock ) ;
else
F_126 ( V_211 L_49 ,
'A' + V_6 , V_206 [ V_6 ] ) ;
}
}
void F_127 ( void )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_208 ; V_6 ++ ) {
void T_1 * V_49 ;
if ( ! V_41 [ V_6 ] )
continue;
V_49 = V_41 [ V_6 ] -> V_42 ;
if ( ! V_206 [ V_6 ] )
F_128 ( V_41 [ V_6 ] -> clock ) ;
F_42 ( V_206 [ V_6 ] , V_49 + V_51 ) ;
F_42 ( V_209 [ V_6 ] , V_49 + V_187 ) ;
}
}
static void F_129 ( unsigned V_191 , struct V_212 * V_213 )
{
struct V_214 * V_119 = F_130 ( V_191 ) ;
struct V_118 * V_118 = F_131 ( V_213 ) ;
struct V_116 * V_173 = F_66 ( V_118 ,
struct V_116 , V_119 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned long V_215 ;
int V_216 ;
F_132 ( V_119 , V_213 ) ;
for (; ; ) {
V_215 = F_27 ( V_49 + V_217 ) & F_27 ( V_49 + V_210 ) ;
if ( ! V_215 ) {
if ( ! V_173 -> V_218 )
break;
V_173 = V_173 -> V_218 ;
V_49 = V_173 -> V_42 ;
V_118 = & V_173 -> V_119 ;
continue;
}
F_133 (n, &isr, BITS_PER_LONG) {
F_134 ( F_135 (
V_118 -> V_219 , V_216 ) ) ;
}
}
F_136 ( V_119 , V_213 ) ;
}
static int F_137 ( struct V_157 * V_158 ,
struct V_116 * V_173 )
{
struct V_116 * V_220 = NULL ;
struct V_184 * V_185 = F_138 ( V_173 -> V_207 ) ;
int V_100 ;
V_173 -> V_221 = F_139 ( V_185 ) ;
V_222 . V_223 = V_173 -> V_103 -> V_224 ;
F_25 ( ~ 0 , V_173 -> V_42 + V_51 ) ;
V_100 = F_140 ( & V_173 -> V_119 ,
& V_222 ,
0 ,
V_225 ,
V_189 ) ;
if ( V_100 ) {
F_11 ( & V_158 -> V_9 , L_50 ,
V_173 -> V_204 ) ;
return V_100 ;
}
if ( V_173 -> V_204 )
V_220 = V_41 [ V_173 -> V_204 - 1 ] ;
if ( V_220 && V_220 -> V_218 == V_173 )
return 0 ;
F_141 ( & V_173 -> V_119 ,
& V_222 ,
V_173 -> V_207 ,
F_129 ) ;
return 0 ;
}
static void F_142 ( void )
{
unsigned V_6 ;
struct V_116 * V_173 , * V_226 = NULL ;
for ( V_6 = 0 ; V_6 < V_208 ; V_6 ++ ) {
V_173 = V_41 [ V_6 ] ;
if ( V_226 && V_226 -> V_207 == V_173 -> V_207 )
V_226 -> V_218 = V_173 ;
V_226 = V_173 ;
}
}
static int F_143 ( struct V_157 * V_158 )
{
struct V_19 * V_20 = V_158 -> V_9 . V_159 ;
struct V_227 * V_228 ;
struct V_116 * V_117 = NULL ;
struct V_118 * V_119 ;
struct V_113 * V_114 ;
int V_100 = 0 ;
int V_191 , V_6 ;
int V_229 = F_144 ( V_20 , L_51 ) ;
T_3 V_172 ;
char * * V_230 ;
F_145 ( V_229 >= F_146 ( V_41 ) ) ;
if ( V_41 [ V_229 ] ) {
V_100 = - V_231 ;
goto V_170;
}
V_191 = F_147 ( V_158 , 0 ) ;
if ( V_191 < 0 ) {
V_100 = V_191 ;
goto V_170;
}
V_117 = F_12 ( & V_158 -> V_9 , sizeof( * V_117 ) , V_27 ) ;
if ( ! V_117 ) {
V_100 = - V_28 ;
goto V_170;
}
V_228 = F_148 ( V_158 , V_232 , 0 ) ;
V_117 -> V_42 = F_149 ( & V_158 -> V_9 , V_228 ) ;
if ( F_150 ( V_117 -> V_42 ) ) {
V_100 = F_151 ( V_117 -> V_42 ) ;
goto V_170;
}
V_117 -> V_103 = (struct V_161 * )
F_85 ( V_233 , & V_158 -> V_9 ) -> V_30 ;
V_117 -> V_207 = V_191 ;
V_117 -> V_204 = V_229 ;
V_117 -> clock = F_152 ( & V_158 -> V_9 , NULL ) ;
if ( F_150 ( V_117 -> clock ) ) {
F_11 ( & V_158 -> V_9 , L_52 ) ;
V_100 = F_151 ( V_117 -> clock ) ;
goto V_170;
}
V_100 = F_153 ( V_117 -> clock ) ;
if ( V_100 )
goto V_234;
V_100 = F_154 ( V_117 -> clock ) ;
if ( V_100 ) {
F_11 ( & V_158 -> V_9 , L_53 ) ;
goto V_235;
}
V_117 -> V_119 = V_236 ;
V_119 = & V_117 -> V_119 ;
V_119 -> V_159 = V_20 ;
V_119 -> V_183 = F_9 ( & V_158 -> V_9 ) ;
V_119 -> V_9 = & V_158 -> V_9 ;
V_119 -> V_237 = V_238 ;
V_119 -> V_121 = V_229 * V_44 ;
if ( ! F_155 ( V_20 , L_54 , & V_172 ) ) {
if ( V_172 >= V_44 )
F_156 ( L_55 ,
V_229 , V_44 , V_44 ) ;
else
V_119 -> V_172 = V_172 ;
}
V_230 = F_12 ( & V_158 -> V_9 , sizeof( char * ) * V_119 -> V_172 ,
V_27 ) ;
if ( ! V_230 ) {
V_100 = - V_28 ;
goto V_235;
}
for ( V_6 = 0 ; V_6 < V_119 -> V_172 ; V_6 ++ )
V_230 [ V_6 ] = F_88 ( V_27 , L_38 , V_229 + 'A' , V_6 ) ;
V_119 -> V_230 = ( const char * const * ) V_230 ;
V_114 = & V_117 -> V_114 ;
V_114 -> V_4 = V_119 -> V_183 ;
V_114 -> V_122 = V_229 ;
V_114 -> V_239 = V_114 -> V_121 = V_114 -> V_122 * V_44 ;
V_114 -> V_10 = V_119 -> V_172 ;
V_114 -> V_120 = V_119 ;
V_100 = F_157 ( V_119 ) ;
if ( V_100 )
goto V_240;
V_41 [ V_229 ] = V_117 ;
V_208 = F_158 ( V_208 , V_229 + 1 ) ;
F_142 () ;
V_100 = F_137 ( V_158 , V_117 ) ;
if ( V_100 )
goto V_241;
F_92 ( & V_158 -> V_9 , L_56 , V_117 -> V_42 ) ;
return 0 ;
V_241:
F_159 ( V_119 ) ;
V_240:
F_160 ( V_117 -> clock ) ;
V_235:
F_161 ( V_117 -> clock ) ;
V_234:
V_170:
F_11 ( & V_158 -> V_9 , L_57 , V_100 , V_229 ) ;
return V_100 ;
}
static int T_5 F_162 ( void )
{
int V_100 ;
V_100 = F_163 ( & V_242 ) ;
if ( V_100 )
return V_100 ;
return F_163 ( & V_243 ) ;
}
static void T_6 F_164 ( void )
{
F_165 ( & V_243 ) ;
}
