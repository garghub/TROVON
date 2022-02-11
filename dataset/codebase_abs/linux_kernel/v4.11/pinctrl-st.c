static struct V_1 * F_1 (
struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 =
F_2 ( V_3 , V_4 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
return & V_8 -> V_9 ;
}
static inline int V_7 ( int V_10 )
{
return V_10 / V_11 ;
}
static inline int F_4 ( int V_10 )
{
return V_10 % V_11 ;
}
static void F_5 ( struct V_1 * V_9 ,
int V_4 , unsigned long V_12 )
{
struct V_13 * V_14 = V_9 -> V_15 ;
struct V_13 * V_16 = V_9 -> V_17 ;
struct V_13 * V_18 = V_9 -> V_19 ;
unsigned int V_20 , V_21 , V_22 ;
unsigned long V_23 = F_6 ( V_4 ) ;
if ( V_14 ) {
F_7 ( V_14 , & V_20 ) ;
V_20 &= ~ V_23 ;
if ( V_12 & V_24 )
V_20 |= V_23 ;
F_8 ( V_14 , V_20 ) ;
}
if ( V_16 ) {
F_7 ( V_16 , & V_21 ) ;
V_21 &= ~ V_23 ;
if ( V_12 & V_25 )
V_21 |= V_23 ;
F_8 ( V_16 , V_21 ) ;
}
if ( V_18 ) {
F_7 ( V_18 , & V_22 ) ;
V_22 &= ~ V_23 ;
if ( V_12 & V_26 )
V_22 |= V_23 ;
F_8 ( V_18 , V_22 ) ;
}
}
static void F_9 ( struct V_1 * V_9 ,
int V_27 , int V_28 )
{
struct V_13 * V_29 = V_9 -> V_29 ;
unsigned int V_30 ;
int V_4 = F_4 ( V_27 ) ;
int V_31 = V_4 * 4 ;
if ( ! V_29 )
return;
F_7 ( V_29 , & V_30 ) ;
V_30 &= ~ ( 0xf << V_31 ) ;
V_30 |= V_28 << V_31 ;
F_8 ( V_29 , V_30 ) ;
}
static unsigned int F_10 ( struct V_1 * V_9 , int V_4 )
{
struct V_13 * V_29 = V_9 -> V_29 ;
unsigned int V_30 ;
int V_31 = V_4 * 4 ;
if ( ! V_29 )
return 0 ;
F_7 ( V_29 , & V_30 ) ;
return ( V_30 >> V_31 ) & 0xf ;
}
static unsigned long F_11 ( unsigned int V_32 ,
const struct V_33 * V_34 , unsigned long V_12 )
{
const unsigned int * V_35 ;
int V_36 , V_37 , V_38 = - 1 ;
unsigned int V_39 = V_40 ;
if ( F_12 ( V_12 ) ) {
V_35 = V_34 -> V_41 ;
V_36 = V_34 -> V_42 ;
} else {
V_35 = V_34 -> V_43 ;
V_36 = V_34 -> V_44 ;
}
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
unsigned int V_45 = abs ( V_32 - V_35 [ V_37 ] ) ;
if ( V_45 == 0 )
return V_37 ;
if ( V_45 < V_39 ) {
V_39 = V_45 ;
V_38 = V_37 ;
}
}
F_13 ( L_1 ,
V_32 , V_35 [ V_38 ] ) ;
return V_38 ;
}
static unsigned long F_14 ( unsigned int V_46 ,
const struct V_33 * V_34 , unsigned long V_47 )
{
const unsigned int * V_35 ;
int V_36 ;
if ( V_47 ) {
V_35 = V_34 -> V_41 ;
V_36 = V_34 -> V_42 ;
} else {
V_35 = V_34 -> V_43 ;
V_36 = V_34 -> V_44 ;
}
if ( V_46 < V_36 ) {
return V_35 [ V_46 ] ;
} else {
F_13 ( L_2 ) ;
return 0 ;
}
}
static void F_15 ( struct V_13 * V_48 ,
int V_49 , int V_4 )
{
unsigned int V_30 = 0 ;
F_7 ( V_48 , & V_30 ) ;
if ( V_49 )
V_30 |= F_6 ( V_4 ) ;
else
V_30 &= ~ F_6 ( V_4 ) ;
F_8 ( V_48 , V_30 ) ;
}
static void F_16 ( struct V_50 * V_51 ,
struct V_1 * V_9 , unsigned long V_12 , int V_4 )
{
const struct V_33 * V_34 = V_51 -> V_34 ;
struct V_52 * V_53 = & V_9 -> V_54 . V_53 ;
unsigned int V_32 ;
F_15 ( V_53 -> V_55 ,
F_17 ( V_12 ) , V_4 ) ;
F_15 ( V_53 -> V_56 ,
F_18 ( V_12 ) , V_4 ) ;
F_15 ( V_53 -> V_57 ,
F_19 ( V_12 ) , V_4 ) ;
F_15 ( V_53 -> V_58 ,
F_20 ( V_12 ) , V_4 ) ;
F_15 ( V_53 -> V_59 ,
F_21 ( V_12 ) , V_4 ) ;
V_32 = F_11 ( F_22 ( V_12 ) ,
V_34 , V_12 ) ;
F_15 ( V_53 -> V_60 , V_32 & 0x1 , V_4 ) ;
F_15 ( V_53 -> V_61 , V_32 & 0x2 , V_4 ) ;
}
static void F_23 ( struct V_50 * V_51 ,
struct V_1 * V_9 , unsigned long V_12 , int V_4 )
{
int V_62 = F_12 ( V_12 ) ? 0 : 1 ;
int V_63 = F_17 ( V_12 ) ;
int V_56 = F_18 ( V_12 ) ;
int V_57 = F_19 ( V_12 ) ;
int V_58 = F_20 ( V_12 ) ;
int V_59 = F_21 ( V_12 ) ;
unsigned long V_32 = F_11 (
F_22 ( V_12 ) ,
V_51 -> V_34 , V_12 ) ;
struct V_64 * V_65 = & V_9 -> V_54 . V_65 ;
unsigned long V_66 =
( ( V_63 ) << V_67 ) |
( ( V_32 ) << V_68 ) |
( ( V_62 ) << V_69 ) |
( ( V_59 ) << V_70 ) |
( ( V_56 ) << V_71 ) |
( ( V_58 ) << V_72 ) |
( ( V_57 ) << V_73 ) ;
F_8 ( V_65 -> V_54 [ V_4 ] , V_66 ) ;
}
static void F_24 ( struct V_1 * V_9 ,
int V_4 , unsigned long * V_12 )
{
unsigned int V_20 , V_21 , V_22 ;
if ( V_9 -> V_15 ) {
F_7 ( V_9 -> V_15 , & V_20 ) ;
if ( V_20 & F_6 ( V_4 ) )
F_25 ( * V_12 ) ;
}
if ( V_9 -> V_17 ) {
F_7 ( V_9 -> V_17 , & V_21 ) ;
if ( V_21 & F_6 ( V_4 ) )
F_26 ( * V_12 ) ;
}
if ( V_9 -> V_19 ) {
F_7 ( V_9 -> V_19 , & V_22 ) ;
if ( V_22 & F_6 ( V_4 ) )
F_27 ( * V_12 ) ;
}
}
static int F_28 ( struct V_50 * V_51 ,
struct V_1 * V_9 , int V_4 , unsigned long * V_12 )
{
const struct V_33 * V_34 = V_51 -> V_34 ;
struct V_52 * V_53 = & V_9 -> V_54 . V_53 ;
unsigned int V_74 , V_32 , V_75 , V_76 , V_30 ;
int V_47 = F_12 ( * V_12 ) ;
if ( ! F_7 ( V_53 -> V_59 , & V_30 ) && ( V_30 & F_6 ( V_4 ) ) )
F_29 ( * V_12 ) ;
if ( ! F_7 ( V_53 -> V_55 , & V_30 ) && ( V_30 & F_6 ( V_4 ) ) )
F_30 ( * V_12 , 1 ) ;
if ( ! F_7 ( V_53 -> V_56 , & V_30 ) && ( V_30 & F_6 ( V_4 ) ) )
F_31 ( * V_12 ) ;
if ( ! F_7 ( V_53 -> V_57 , & V_30 ) && ( V_30 & F_6 ( V_4 ) ) )
F_32 ( * V_12 ) ;
if ( ! F_7 ( V_53 -> V_58 , & V_30 ) && ( V_30 & F_6 ( V_4 ) ) )
F_33 ( * V_12 ) ;
F_7 ( V_53 -> V_60 , & V_75 ) ;
F_7 ( V_53 -> V_61 , & V_76 ) ;
V_74 = ( ( ( V_76 & F_6 ( V_4 ) ) ? 1 : 0 ) << 1 ) |
( ( ( V_75 & F_6 ( V_4 ) ) ? 1 : 0 ) ) ;
V_32 = F_14 ( V_74 , V_34 , V_47 ) ;
F_34 ( * V_12 , V_32 ) ;
return 0 ;
}
static int F_35 ( struct V_50 * V_51 ,
struct V_1 * V_9 , int V_4 , unsigned long * V_12 )
{
unsigned int V_77 ;
unsigned long V_74 , V_32 , V_78 ;
int V_47 = F_12 ( * V_12 ) ;
struct V_64 * V_65 = & V_9 -> V_54 . V_65 ;
F_7 ( V_65 -> V_54 [ V_4 ] , & V_77 ) ;
V_78 = ( V_77 & V_79 ) >> V_67 ;
F_30 ( * V_12 , V_78 ) ;
V_74 = ( V_77 & V_80 ) >> V_68 ;
V_32 = F_14 ( V_74 , V_51 -> V_34 , V_47 ) ;
F_34 ( * V_12 , V_32 ) ;
if ( V_77 & V_81 )
F_31 ( * V_12 ) ;
if ( V_77 & V_82 )
F_32 ( * V_12 ) ;
if ( V_77 & V_83 )
F_33 ( * V_12 ) ;
if ( V_77 & V_84 )
F_29 ( * V_12 ) ;
return 0 ;
}
static inline void F_36 ( struct V_7 * V_8 ,
unsigned V_31 , int V_77 )
{
if ( V_77 )
F_37 ( F_6 ( V_31 ) , V_8 -> V_85 + V_86 ) ;
else
F_37 ( F_6 ( V_31 ) , V_8 -> V_85 + V_87 ) ;
}
static void F_38 ( struct V_7 * V_8 ,
unsigned int V_10 , unsigned int V_88 )
{
int V_31 = F_4 ( V_10 ) ;
int V_37 = 0 ;
for ( V_37 = 0 ; V_37 <= 2 ; V_37 ++ ) {
if ( V_88 & F_6 ( V_37 ) )
F_37 ( F_6 ( V_31 ) , V_8 -> V_85 + F_39 ( V_37 ) ) ;
else
F_37 ( F_6 ( V_31 ) , V_8 -> V_85 + F_40 ( V_37 ) ) ;
}
}
static int F_41 ( struct V_89 * V_90 , unsigned V_31 )
{
struct V_7 * V_8 = F_42 ( V_90 ) ;
return ! ! ( F_43 ( V_8 -> V_85 + V_91 ) & F_6 ( V_31 ) ) ;
}
static void F_44 ( struct V_89 * V_90 , unsigned V_31 , int V_77 )
{
struct V_7 * V_8 = F_42 ( V_90 ) ;
F_36 ( V_8 , V_31 , V_77 ) ;
}
static int F_45 ( struct V_89 * V_90 , unsigned V_31 )
{
F_46 ( V_90 -> V_85 + V_31 ) ;
return 0 ;
}
static int F_47 ( struct V_89 * V_90 ,
unsigned V_31 , int V_77 )
{
struct V_7 * V_8 = F_42 ( V_90 ) ;
F_36 ( V_8 , V_31 , V_77 ) ;
F_48 ( V_90 -> V_85 + V_31 ) ;
return 0 ;
}
static int F_49 ( struct V_89 * V_90 , unsigned V_31 )
{
struct V_7 * V_8 = F_42 ( V_90 ) ;
struct V_1 V_9 = V_8 -> V_9 ;
unsigned long V_12 ;
unsigned int V_88 = 0 ;
unsigned int V_28 ;
unsigned int V_77 ;
int V_37 = 0 ;
V_28 = F_10 ( & V_9 , V_31 ) ;
if ( V_28 ) {
F_24 ( & V_9 , V_31 , & V_12 ) ;
return ! F_12 ( V_12 ) ;
}
for ( V_37 = 0 ; V_37 <= 2 ; V_37 ++ ) {
V_77 = F_43 ( V_8 -> V_85 + F_50 ( V_37 ) ) ;
V_88 |= ( ( V_77 >> V_31 ) & 0x1 ) << V_37 ;
}
return ( V_88 == V_92 ) ;
}
static int F_51 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = F_52 ( V_3 ) ;
return V_51 -> V_93 ;
}
static const char * F_53 ( struct V_2 * V_3 ,
unsigned V_94 )
{
struct V_50 * V_51 = F_52 ( V_3 ) ;
return V_51 -> V_95 [ V_94 ] . V_96 ;
}
static int F_54 ( struct V_2 * V_3 ,
unsigned V_94 , const unsigned * * V_97 , unsigned * V_98 )
{
struct V_50 * V_51 = F_52 ( V_3 ) ;
if ( V_94 >= V_51 -> V_93 )
return - V_99 ;
* V_97 = V_51 -> V_95 [ V_94 ] . V_97 ;
* V_98 = V_51 -> V_95 [ V_94 ] . V_98 ;
return 0 ;
}
static inline const struct V_100 * F_55 (
const struct V_50 * V_51 , const char * V_96 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_51 -> V_93 ; V_37 ++ ) {
if ( ! strcmp ( V_51 -> V_95 [ V_37 ] . V_96 , V_96 ) )
return & V_51 -> V_95 [ V_37 ] ;
}
return NULL ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_101 * V_102 , struct V_103 * * V_104 , unsigned * V_105 )
{
struct V_50 * V_51 = F_52 ( V_3 ) ;
const struct V_100 * V_106 ;
struct V_103 * V_107 ;
struct V_101 * V_108 ;
int V_109 , V_37 ;
V_106 = F_55 ( V_51 , V_102 -> V_96 ) ;
if ( ! V_106 ) {
F_57 ( V_51 -> V_110 , L_3 ,
V_102 -> V_96 ) ;
return - V_99 ;
}
V_109 = V_106 -> V_98 + 1 ;
V_107 = F_58 ( V_3 -> V_110 ,
sizeof( * V_107 ) * V_109 , V_111 ) ;
if ( ! V_107 )
return - V_112 ;
V_108 = F_59 ( V_102 ) ;
if ( ! V_108 ) {
F_60 ( V_3 -> V_110 , V_107 ) ;
return - V_99 ;
}
* V_104 = V_107 ;
* V_105 = V_109 ;
V_107 [ 0 ] . type = V_113 ;
V_107 [ 0 ] . V_34 . V_114 . V_28 = V_108 -> V_96 ;
V_107 [ 0 ] . V_34 . V_114 . V_115 = V_102 -> V_96 ;
F_61 ( V_108 ) ;
V_107 ++ ;
for ( V_37 = 0 ; V_37 < V_106 -> V_98 ; V_37 ++ ) {
V_107 [ V_37 ] . type = V_116 ;
V_107 [ V_37 ] . V_34 . V_117 . V_118 =
F_62 ( V_3 , V_106 -> V_97 [ V_37 ] ) ;
V_107 [ V_37 ] . V_34 . V_117 . V_117 = & V_106 -> V_119 [ V_37 ] . V_12 ;
V_107 [ V_37 ] . V_34 . V_117 . V_120 = 1 ;
}
F_63 ( V_3 -> V_110 , L_4 ,
( * V_104 ) -> V_34 . V_114 . V_28 , V_106 -> V_96 , V_109 ) ;
return 0 ;
}
static void F_64 ( struct V_2 * V_3 ,
struct V_103 * V_104 , unsigned V_105 )
{
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = F_52 ( V_3 ) ;
return V_51 -> V_121 ;
}
static const char * F_66 ( struct V_2 * V_3 ,
unsigned V_94 )
{
struct V_50 * V_51 = F_52 ( V_3 ) ;
return V_51 -> V_122 [ V_94 ] . V_96 ;
}
static int F_67 ( struct V_2 * V_3 ,
unsigned V_94 , const char * const * * V_123 , unsigned * const V_124 )
{
struct V_50 * V_51 = F_52 ( V_3 ) ;
* V_123 = V_51 -> V_122 [ V_94 ] . V_95 ;
* V_124 = V_51 -> V_122 [ V_94 ] . V_93 ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 , unsigned V_125 ,
unsigned V_115 )
{
struct V_50 * V_51 = F_52 ( V_3 ) ;
struct V_126 * V_127 = V_51 -> V_95 [ V_115 ] . V_119 ;
struct V_1 * V_9 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_51 -> V_95 [ V_115 ] . V_98 ; V_37 ++ ) {
V_9 = F_1 ( V_3 , V_127 [ V_37 ] . V_4 ) ;
F_9 ( V_9 , V_127 [ V_37 ] . V_4 , V_127 [ V_37 ] . V_128 ) ;
}
return 0 ;
}
static int F_69 ( struct V_2 * V_3 ,
struct V_5 * V_6 , unsigned V_10 ,
bool V_62 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_9 ( & V_8 -> V_9 , V_10 , 0 ) ;
F_38 ( V_8 , V_10 , V_62 ?
V_92 : V_129 ) ;
return 0 ;
}
static void F_70 ( struct V_50 * V_51 ,
struct V_1 * V_9 , int V_4 , unsigned long * V_12 )
{
if ( V_51 -> V_34 -> V_130 == V_131 )
F_28 ( V_51 , V_9 , V_4 , V_12 ) ;
else if ( V_51 -> V_34 -> V_130 == V_132 )
if ( ( F_6 ( V_4 ) & V_9 -> V_133 ) )
F_35 ( V_51 , V_9 ,
V_4 , V_12 ) ;
}
static void F_71 ( struct V_50 * V_51 ,
struct V_1 * V_9 , int V_4 , unsigned long V_12 )
{
if ( V_51 -> V_34 -> V_130 == V_131 )
F_16 ( V_51 , V_9 , V_12 , V_4 ) ;
else if ( V_51 -> V_34 -> V_130 == V_132 )
if ( ( F_6 ( V_4 ) & V_9 -> V_133 ) )
F_23 ( V_51 , V_9 ,
V_12 , V_4 ) ;
}
static int F_72 ( struct V_2 * V_3 , unsigned V_27 ,
unsigned long * V_117 , unsigned V_120 )
{
int V_4 = F_4 ( V_27 ) ;
struct V_50 * V_51 = F_52 ( V_3 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_27 ) ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_120 ; V_37 ++ ) {
F_5 ( V_9 , V_4 , V_117 [ V_37 ] ) ;
F_71 ( V_51 , V_9 , V_4 , V_117 [ V_37 ] ) ;
}
return 0 ;
}
static int F_73 ( struct V_2 * V_3 ,
unsigned V_27 , unsigned long * V_12 )
{
int V_4 = F_4 ( V_27 ) ;
struct V_50 * V_51 = F_52 ( V_3 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_27 ) ;
* V_12 = 0 ;
F_24 ( V_9 , V_4 , V_12 ) ;
F_70 ( V_51 , V_9 , V_4 , V_12 ) ;
return 0 ;
}
static void F_74 ( struct V_2 * V_3 ,
struct V_134 * V_135 , unsigned V_27 )
{
struct V_1 * V_9 ;
unsigned long V_12 ;
unsigned int V_28 ;
int V_31 = F_4 ( V_27 ) ;
char V_136 [ 16 ] ;
F_75 ( & V_3 -> V_137 ) ;
V_9 = F_1 ( V_3 , V_27 ) ;
F_73 ( V_3 , V_27 , & V_12 ) ;
F_76 ( & V_3 -> V_137 ) ;
V_28 = F_10 ( V_9 , V_31 ) ;
if ( V_28 )
snprintf ( V_136 , 10 , L_5 , V_28 ) ;
else
snprintf ( V_136 , 5 , L_6 ) ;
F_77 ( V_135 , L_7
L_8
L_9 ,
! F_49 ( & F_78 ( V_9 ) -> V_89 , V_31 ) ,
F_79 ( V_12 ) ,
F_80 ( V_12 ) ,
V_136 ,
F_21 ( V_12 ) ,
F_20 ( V_12 ) ,
F_18 ( V_12 ) ,
F_19 ( V_12 ) ,
F_17 ( V_12 ) ,
F_22 ( V_12 ) ) ;
}
static void F_81 ( struct V_50 * V_51 ,
struct V_101 * V_102 )
{
struct V_101 * V_138 ;
F_82 (np, child) {
if ( F_83 ( V_138 , L_10 ) ) {
V_51 -> V_139 ++ ;
} else {
V_51 -> V_121 ++ ;
V_51 -> V_93 += F_84 ( V_138 ) ;
}
}
}
static int F_85 ( struct V_50 * V_51 ,
int V_8 , struct V_1 * V_9 )
{
struct V_140 * V_110 = V_51 -> V_110 ;
struct V_141 * V_142 = V_51 -> V_141 ;
const struct V_33 * V_34 = V_51 -> V_34 ;
int V_143 = ( V_34 -> V_54 + V_8 * V_144 ) * 4 ;
struct V_52 * V_53 = & V_9 -> V_54 . V_53 ;
struct V_145 V_55 = F_86 ( V_143 ) ;
struct V_145 V_60 = F_87 ( V_143 ) ;
struct V_145 V_61 = F_88 ( V_143 ) ;
struct V_145 V_58 = F_89 ( V_143 + 4 ) ;
struct V_145 V_59 = F_90 ( V_143 + 4 ) ;
struct V_145 V_56 = F_91 ( V_143 + 4 ) ;
struct V_145 V_57 = F_92 ( V_143 + 4 ) ;
V_53 -> V_55 = F_93 ( V_110 , V_142 , V_55 ) ;
V_53 -> V_60 = F_93 ( V_110 , V_142 , V_60 ) ;
V_53 -> V_61 = F_93 ( V_110 , V_142 , V_61 ) ;
V_53 -> V_58 = F_93 ( V_110 , V_142 , V_58 ) ;
V_53 -> V_59 = F_93 ( V_110 , V_142 , V_59 ) ;
V_53 -> V_56 = F_93 ( V_110 , V_142 , V_56 ) ;
V_53 -> V_57 = F_93 ( V_110 , V_142 , V_57 ) ;
if ( F_94 ( V_53 -> V_55 ) || F_94 ( V_53 -> V_60 ) ||
F_94 ( V_53 -> V_61 ) || F_94 ( V_53 -> V_58 ) ||
F_94 ( V_53 -> V_59 ) || F_94 ( V_53 -> V_56 ) ||
F_94 ( V_53 -> V_57 ) )
return - V_99 ;
return 0 ;
}
static int F_95 ( struct V_50 * V_51 ,
int V_8 , struct V_1 * V_9 )
{
struct V_140 * V_110 = V_51 -> V_110 ;
struct V_141 * V_142 = V_51 -> V_141 ;
const struct V_33 * V_34 = V_51 -> V_34 ;
int V_146 = ( V_34 -> V_54 + V_8 * V_147 ) * 4 ;
struct V_64 * V_65 = & V_9 -> V_54 . V_65 ;
unsigned int V_148 ;
T_1 V_149 = V_9 -> V_133 ;
for ( V_148 = 0 ; V_148 < V_147 ; V_148 ++ ) {
if ( F_6 ( V_148 ) & V_149 ) {
struct V_145 V_143 = F_96 ( V_146 , 0 , 31 ) ;
V_65 -> V_54 [ V_148 ] = F_93 ( V_110 , V_142 , V_143 ) ;
if ( F_94 ( V_65 -> V_54 [ V_148 ] ) )
return - V_99 ;
V_146 += 4 ;
}
}
return 0 ;
}
static int F_97 ( struct V_50 * V_51 ,
int V_8 , struct V_1 * V_9 )
{
const struct V_33 * V_34 = V_51 -> V_34 ;
if ( V_34 -> V_130 == V_131 )
return F_85 ( V_51 , V_8 , V_9 ) ;
else if ( V_34 -> V_130 == V_132 )
return F_95 ( V_51 , V_8 , V_9 ) ;
return - V_99 ;
}
static struct V_13 * F_98 ( struct V_140 * V_110 ,
struct V_141 * V_141 , int V_8 ,
int V_34 , int V_150 , int V_151 )
{
struct V_145 V_143 = F_96 ( ( V_34 + V_8 ) * 4 , V_150 , V_151 ) ;
if ( V_34 < 0 )
return NULL ;
return F_93 ( V_110 , V_141 , V_143 ) ;
}
static void F_99 ( struct V_50 * V_51 , int V_8 ,
struct V_101 * V_102 )
{
const struct V_33 * V_34 = V_51 -> V_34 ;
int V_150 = ( V_8 % 4 ) * V_11 ;
int V_151 = V_150 + V_11 - 1 ;
struct V_1 * V_9 = & V_51 -> V_152 [ V_8 ] . V_9 ;
struct V_140 * V_110 = V_51 -> V_110 ;
struct V_141 * V_141 = V_51 -> V_141 ;
V_9 -> V_29 = F_98 ( V_110 , V_141 , V_8 , V_34 -> V_29 , 0 , 31 ) ;
V_9 -> V_15 = F_98 ( V_110 , V_141 , V_8 / 4 , V_34 -> V_15 , V_150 , V_151 ) ;
V_9 -> V_17 = F_98 ( V_110 , V_141 , V_8 / 4 , V_34 -> V_17 , V_150 , V_151 ) ;
V_9 -> V_19 = F_98 ( V_110 , V_141 , V_8 / 4 , V_34 -> V_19 , V_150 , V_151 ) ;
V_9 -> V_133 = 0xff ;
F_100 ( V_102 , L_11 , & V_9 -> V_133 ) ;
F_97 ( V_51 , V_8 , V_9 ) ;
return;
}
static int F_101 ( struct V_101 * V_102 ,
struct V_100 * V_106 , struct V_50 * V_51 , int V_153 )
{
const T_2 * V_154 ;
struct V_155 * V_156 ;
struct V_126 * V_127 ;
struct V_101 * V_97 ;
int V_37 = 0 , V_98 = 0 , V_157 ;
V_97 = F_102 ( V_102 , L_12 ) ;
if ( ! V_97 )
return - V_158 ;
F_103 (pins, pp) {
if ( ! strcmp ( V_156 -> V_96 , L_13 ) )
continue;
if ( V_156 -> V_159 / sizeof( T_2 ) >= V_160 ) {
V_98 ++ ;
} else {
F_13 ( L_14 , V_102 -> V_96 ) ;
return - V_99 ;
}
}
V_106 -> V_98 = V_98 ;
V_106 -> V_96 = V_102 -> V_96 ;
V_106 -> V_97 = F_58 ( V_51 -> V_110 , V_98 * sizeof( T_1 ) , V_111 ) ;
V_106 -> V_119 = F_58 ( V_51 -> V_110 ,
V_98 * sizeof( * V_127 ) , V_111 ) ;
if ( ! V_106 -> V_97 || ! V_106 -> V_119 )
return - V_112 ;
F_103 (pins, pp) {
if ( ! strcmp ( V_156 -> V_96 , L_13 ) )
continue;
V_157 = V_156 -> V_159 / sizeof( T_1 ) ;
V_154 = V_156 -> V_77 ;
V_127 = & V_106 -> V_119 [ V_37 ] ;
F_104 ( V_154 ++ ) ;
F_104 ( V_154 ++ ) ;
V_127 -> V_4 = F_105 ( V_97 , V_156 -> V_96 , 0 ) ;
V_127 -> V_96 = V_156 -> V_96 ;
V_106 -> V_97 [ V_37 ] = V_127 -> V_4 ;
V_127 -> V_128 = F_104 ( V_154 ++ ) ;
V_127 -> V_12 = 0 ;
V_127 -> V_12 |= F_104 ( V_154 ++ ) ;
if ( V_157 >= V_160 + V_161 ) {
V_127 -> V_12 |= F_104 ( V_154 ++ ) ;
V_127 -> V_12 |= F_104 ( V_154 ++ ) ;
if ( V_157 > V_160 + V_161 )
V_127 -> V_12 |= F_104 ( V_154 ++ ) ;
}
V_37 ++ ;
}
F_61 ( V_97 ) ;
return 0 ;
}
static int F_106 ( struct V_101 * V_102 ,
struct V_50 * V_51 , T_1 V_46 , int * V_162 )
{
struct V_101 * V_138 ;
struct V_163 * V_164 ;
struct V_100 * V_106 ;
int V_165 , V_37 ;
V_164 = & V_51 -> V_122 [ V_46 ] ;
V_164 -> V_96 = V_102 -> V_96 ;
V_164 -> V_93 = F_84 ( V_102 ) ;
if ( V_164 -> V_93 == 0 ) {
F_57 ( V_51 -> V_110 , L_15 ) ;
return - V_99 ;
}
V_164 -> V_95 = F_58 ( V_51 -> V_110 ,
V_164 -> V_93 * sizeof( char * ) , V_111 ) ;
if ( ! V_164 -> V_95 )
return - V_112 ;
V_37 = 0 ;
F_82 (np, child) {
V_164 -> V_95 [ V_37 ] = V_138 -> V_96 ;
V_106 = & V_51 -> V_95 [ * V_162 ] ;
* V_162 += 1 ;
V_165 = F_101 ( V_138 , V_106 , V_51 , V_37 ++ ) ;
if ( V_165 )
return V_165 ;
}
F_63 ( V_51 -> V_110 , L_16 ,
V_46 , V_164 -> V_96 , V_164 -> V_93 ) ;
return 0 ;
}
static void F_107 ( struct V_166 * V_167 )
{
struct V_89 * V_168 = F_108 ( V_167 ) ;
struct V_7 * V_8 = F_42 ( V_168 ) ;
F_37 ( F_6 ( V_167 -> V_169 ) , V_8 -> V_85 + V_170 ) ;
}
static void F_109 ( struct V_166 * V_167 )
{
struct V_89 * V_168 = F_108 ( V_167 ) ;
struct V_7 * V_8 = F_42 ( V_168 ) ;
F_37 ( F_6 ( V_167 -> V_169 ) , V_8 -> V_85 + V_171 ) ;
}
static int F_110 ( struct V_166 * V_167 )
{
struct V_89 * V_168 = F_108 ( V_167 ) ;
F_45 ( V_168 , V_167 -> V_169 ) ;
return F_111 ( V_168 , V_167 -> V_169 ) ;
}
static void F_112 ( struct V_166 * V_167 )
{
struct V_89 * V_168 = F_108 ( V_167 ) ;
F_113 ( V_168 , V_167 -> V_169 ) ;
}
static int F_114 ( struct V_166 * V_167 , unsigned type )
{
struct V_89 * V_168 = F_108 ( V_167 ) ;
struct V_7 * V_8 = F_42 ( V_168 ) ;
unsigned long V_172 ;
int V_173 , V_4 = V_167 -> V_169 ;
T_1 V_30 ;
T_1 V_174 = 0 ;
switch ( type ) {
case V_175 :
V_173 = 0 ;
break;
case V_176 :
V_173 = 0 ;
V_174 = F_115 ( V_4 ) ;
break;
case V_177 :
V_173 = 1 ;
break;
case V_178 :
V_173 = 1 ;
V_174 = F_116 ( V_4 ) ;
break;
case V_179 :
V_173 = F_41 ( & V_8 -> V_89 , V_4 ) ;
V_174 = F_117 ( V_4 ) ;
break;
default:
return - V_99 ;
}
F_118 ( & V_8 -> V_180 , V_172 ) ;
V_8 -> V_181 &= ~ ( V_182 << (
V_4 * V_183 ) ) ;
V_8 -> V_181 |= V_174 ;
F_119 ( & V_8 -> V_180 , V_172 ) ;
V_30 = F_43 ( V_8 -> V_85 + V_184 ) ;
V_30 &= ~ F_6 ( V_4 ) ;
V_30 |= ( V_173 << V_4 ) ;
F_37 ( V_30 , V_8 -> V_85 + V_184 ) ;
return 0 ;
}
static void F_120 ( struct V_7 * V_8 )
{
unsigned long V_185 , V_186 , V_187 , V_188 ;
unsigned long V_189 , V_172 ;
int V_190 , V_30 , V_191 ;
F_118 ( & V_8 -> V_180 , V_172 ) ;
V_189 = V_8 -> V_181 ;
F_119 ( & V_8 -> V_180 , V_172 ) ;
for (; ; ) {
V_185 = F_43 ( V_8 -> V_85 + V_91 ) ;
V_187 = F_43 ( V_8 -> V_85 + V_184 ) ;
V_186 = F_43 ( V_8 -> V_85 + V_192 ) ;
V_188 = ( V_185 ^ V_187 ) & V_186 ;
if ( V_188 == 0 )
break;
F_121 (n, &active_irqs, BITS_PER_LONG) {
V_191 = F_122 ( V_189 , V_190 ) ;
if ( V_191 ) {
V_30 = F_41 ( & V_8 -> V_89 , V_190 ) ;
F_37 ( F_6 ( V_190 ) ,
V_30 ? V_8 -> V_85 + V_193 :
V_8 -> V_85 + V_194 ) ;
if ( V_191 != V_195 &&
! ( ( V_191 & V_196 ) ^ V_30 ) )
continue;
}
F_123 ( F_124 ( V_8 -> V_89 . V_197 , V_190 ) ) ;
}
}
}
static void F_125 ( struct V_198 * V_199 )
{
struct V_200 * V_90 = F_126 ( V_199 ) ;
struct V_89 * V_168 = F_127 ( V_199 ) ;
struct V_7 * V_8 = F_42 ( V_168 ) ;
F_128 ( V_90 , V_199 ) ;
F_120 ( V_8 ) ;
F_129 ( V_90 , V_199 ) ;
}
static void F_130 ( struct V_198 * V_199 )
{
struct V_200 * V_90 = F_126 ( V_199 ) ;
struct V_50 * V_51 = F_127 ( V_199 ) ;
unsigned long V_201 ;
int V_190 ;
F_128 ( V_90 , V_199 ) ;
V_201 = F_43 ( V_51 -> V_202 ) ;
F_121 (n, &status, info->nbanks)
F_120 ( & V_51 -> V_152 [ V_190 ] ) ;
F_129 ( V_90 , V_199 ) ;
}
static int F_131 ( struct V_50 * V_51 ,
int V_203 , struct V_101 * V_102 )
{
struct V_7 * V_8 = & V_51 -> V_152 [ V_203 ] ;
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_140 * V_110 = V_51 -> V_110 ;
int V_204 = F_132 ( V_102 , L_17 ) ;
struct V_205 V_206 , V_207 ;
int V_208 = 0 , V_209 ;
if ( F_133 ( V_102 , 0 , & V_206 ) )
return - V_210 ;
V_8 -> V_85 = F_134 ( V_110 , & V_206 ) ;
if ( F_94 ( V_8 -> V_85 ) )
return F_135 ( V_8 -> V_85 ) ;
V_8 -> V_89 = V_211 ;
V_8 -> V_89 . V_85 = V_204 * V_11 ;
V_8 -> V_89 . V_212 = V_11 ;
V_8 -> V_89 . V_213 = V_102 ;
V_8 -> V_89 . V_108 = V_110 ;
F_136 ( & V_8 -> V_180 ) ;
F_137 ( V_102 , L_18 , & V_6 -> V_96 ) ;
V_8 -> V_89 . V_214 = V_6 -> V_96 ;
V_6 -> V_215 = V_204 ;
V_6 -> V_216 = V_6 -> V_85 = V_6 -> V_215 * V_11 ;
V_6 -> V_98 = V_8 -> V_89 . V_212 ;
V_6 -> V_168 = & V_8 -> V_89 ;
V_209 = F_138 ( & V_8 -> V_89 , V_8 ) ;
if ( V_209 ) {
F_57 ( V_110 , L_19 , V_204 ) ;
return V_209 ;
}
F_63 ( V_110 , L_20 , V_6 -> V_96 ) ;
if ( F_139 ( V_102 , 0 , & V_207 ) ) {
V_208 = V_207 . V_217 ;
F_140 ( & V_8 -> V_89 , & V_218 ,
V_208 , F_125 ) ;
}
if ( V_51 -> V_202 || V_208 > 0 ) {
V_209 = F_141 ( & V_8 -> V_89 , & V_218 ,
0 , V_219 ,
V_220 ) ;
if ( V_209 ) {
F_142 ( & V_8 -> V_89 ) ;
F_63 ( V_110 , L_21 ) ;
return V_209 ;
}
} else {
F_63 ( V_110 , L_22 , V_102 -> V_221 ) ;
}
return 0 ;
}
static int F_143 ( struct V_222 * V_223 ,
struct V_224 * V_225 , struct V_50 * V_51 )
{
int V_165 = 0 ;
int V_37 = 0 , V_148 = 0 , V_226 = 0 , V_8 ;
struct V_227 * V_228 ;
struct V_101 * V_102 = V_223 -> V_110 . V_213 ;
struct V_101 * V_138 ;
int V_162 = 0 ;
int V_229 = 0 ;
struct V_205 * V_206 ;
F_81 ( V_51 , V_102 ) ;
if ( ! V_51 -> V_139 ) {
F_57 ( & V_223 -> V_110 , L_23 ) ;
return - V_99 ;
}
F_63 ( & V_223 -> V_110 , L_24 , V_51 -> V_139 ) ;
F_63 ( & V_223 -> V_110 , L_25 , V_51 -> V_121 ) ;
F_63 ( & V_223 -> V_110 , L_26 , V_51 -> V_93 ) ;
V_51 -> V_122 = F_58 ( & V_223 -> V_110 ,
V_51 -> V_121 * sizeof( * V_51 -> V_122 ) , V_111 ) ;
V_51 -> V_95 = F_58 ( & V_223 -> V_110 ,
V_51 -> V_93 * sizeof( * V_51 -> V_95 ) , V_111 ) ;
V_51 -> V_152 = F_58 ( & V_223 -> V_110 ,
V_51 -> V_139 * sizeof( * V_51 -> V_152 ) , V_111 ) ;
if ( ! V_51 -> V_122 || ! V_51 -> V_95 || ! V_51 -> V_152 )
return - V_112 ;
V_51 -> V_141 = F_144 ( V_102 , L_27 ) ;
if ( F_94 ( V_51 -> V_141 ) ) {
F_57 ( V_51 -> V_110 , L_28 ) ;
return F_135 ( V_51 -> V_141 ) ;
}
V_51 -> V_34 = F_145 ( V_230 , V_102 ) -> V_34 ;
V_229 = F_146 ( V_223 , 0 ) ;
if ( V_229 > 0 ) {
V_206 = F_147 ( V_223 ,
V_231 , L_29 ) ;
V_51 -> V_202 = F_134 ( & V_223 -> V_110 , V_206 ) ;
if ( F_94 ( V_51 -> V_202 ) )
return F_135 ( V_51 -> V_202 ) ;
F_148 ( V_229 , F_130 ,
V_51 ) ;
}
V_225 -> V_98 = V_51 -> V_139 * V_11 ;
V_228 = F_58 ( & V_223 -> V_110 ,
sizeof( * V_228 ) * V_225 -> V_98 , V_111 ) ;
if ( ! V_228 )
return - V_112 ;
V_225 -> V_97 = V_228 ;
V_8 = 0 ;
F_82 (np, child) {
if ( F_83 ( V_138 , L_10 ) ) {
const char * V_232 = NULL ;
V_165 = F_131 ( V_51 , V_8 , V_138 ) ;
if ( V_165 )
return V_165 ;
V_226 = V_51 -> V_152 [ V_8 ] . V_6 . V_216 ;
V_232 = V_51 -> V_152 [ V_8 ] . V_6 . V_96 ;
for ( V_148 = 0 ; V_148 < V_11 ; V_148 ++ , V_226 ++ ) {
V_228 -> V_233 = V_226 ;
V_228 -> V_96 = F_149 ( V_111 , L_30 ,
V_232 , V_148 ) ;
V_228 ++ ;
}
F_99 ( V_51 , V_8 , V_138 ) ;
V_8 ++ ;
} else {
V_165 = F_106 ( V_138 , V_51 ,
V_37 ++ , & V_162 ) ;
if ( V_165 ) {
F_57 ( & V_223 -> V_110 , L_31 ) ;
return V_165 ;
}
}
}
return 0 ;
}
static int F_150 ( struct V_222 * V_223 )
{
struct V_50 * V_51 ;
struct V_224 * V_225 ;
int V_165 , V_37 ;
if ( ! V_223 -> V_110 . V_213 ) {
F_57 ( & V_223 -> V_110 , L_32 ) ;
return - V_99 ;
}
V_225 = F_58 ( & V_223 -> V_110 , sizeof( * V_225 ) , V_111 ) ;
if ( ! V_225 )
return - V_112 ;
V_51 = F_58 ( & V_223 -> V_110 , sizeof( * V_51 ) , V_111 ) ;
if ( ! V_51 )
return - V_112 ;
V_51 -> V_110 = & V_223 -> V_110 ;
F_151 ( V_223 , V_51 ) ;
V_165 = F_143 ( V_223 , V_225 , V_51 ) ;
if ( V_165 )
return V_165 ;
V_225 -> V_234 = V_235 ;
V_225 -> V_236 = & V_237 ;
V_225 -> V_238 = & V_239 ;
V_225 -> V_240 = & V_241 ;
V_225 -> V_96 = F_152 ( & V_223 -> V_110 ) ;
V_51 -> V_242 = F_153 ( & V_223 -> V_110 , V_225 , V_51 ) ;
if ( F_94 ( V_51 -> V_242 ) ) {
F_57 ( & V_223 -> V_110 , L_33 ) ;
return F_135 ( V_51 -> V_242 ) ;
}
for ( V_37 = 0 ; V_37 < V_51 -> V_139 ; V_37 ++ )
F_154 ( V_51 -> V_242 , & V_51 -> V_152 [ V_37 ] . V_6 ) ;
return 0 ;
}
static int T_3 F_155 ( void )
{
return F_156 ( & V_243 ) ;
}
