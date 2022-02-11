static int F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static const char * F_2 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_5 [ V_4 ] . V_6 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_4 ,
const unsigned * * V_7 ,
unsigned * V_8 )
{
* V_7 = V_5 [ V_4 ] . V_7 ;
* V_8 = V_5 [ V_4 ] . V_8 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_9 * V_10 ,
unsigned V_11 )
{
F_5 ( V_10 , L_1 V_12 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * * V_16 , unsigned * V_17 )
{
struct V_18 * V_19 = F_7 ( V_2 ) ;
struct V_13 * V_20 ;
struct V_21 * V_22 ;
const char * V_23 , * V_24 ;
int V_25 , V_26 = 0 , V_27 = 0 ;
F_8 (np_config, np) {
V_25 = F_9 ( V_20 , L_2 , & V_23 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_10 ( V_20 , L_3 ) ;
if ( V_25 < 0 )
return V_25 ;
V_27 += V_25 ;
}
if ( ! V_27 ) {
F_11 ( V_19 -> V_28 , L_4 ) ;
return - V_29 ;
}
* V_16 = F_12 ( sizeof( * * V_16 ) * V_27 , V_30 ) ;
if ( ! * V_16 )
return - V_31 ;
F_8 (np_config, np) {
F_9 ( V_20 , L_2 , & V_23 ) ;
F_13 (np, L_3 , prop, group) {
( * V_16 ) [ V_26 ] . type = V_32 ;
( * V_16 ) [ V_26 ] . V_33 . V_34 . V_24 = V_24 ;
( * V_16 ) [ V_26 ] . V_33 . V_34 . V_23 = V_23 ;
V_26 ++ ;
}
}
* V_17 = V_27 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_15 * V_16 , unsigned V_17 )
{
F_15 ( V_16 ) ;
}
static void F_16 ( struct V_18 * V_19 , unsigned V_4 ,
bool V_35 )
{
int V_36 ;
const struct V_37 * V_34 = V_38 [ V_4 ] . V_39 ;
const struct V_40 * V_41 = V_34 -> V_42 ;
for ( V_36 = 0 ; V_36 < V_34 -> V_43 ; V_36 ++ ) {
T_1 V_44 ;
if ( ! V_19 -> V_45 ) {
V_44 = F_17 ( V_19 -> V_46 + F_18 ( V_41 [ V_36 ] . V_24 ) ) ;
if ( V_35 )
V_44 = V_44 & ~ V_41 [ V_36 ] . V_41 ;
else
V_44 = V_44 | V_41 [ V_36 ] . V_41 ;
F_19 ( V_44 , V_19 -> V_46 + F_18 ( V_41 [ V_36 ] . V_24 ) ) ;
} else {
if ( V_35 )
F_19 ( V_41 [ V_36 ] . V_41 , V_19 -> V_46 +
F_20 ( V_41 [ V_36 ] . V_24 ) ) ;
else
F_19 ( V_41 [ V_36 ] . V_41 , V_19 -> V_46 +
F_18 ( V_41 [ V_36 ] . V_24 ) ) ;
}
}
if ( V_34 -> V_47 && V_35 ) {
T_1 V_48 ;
V_48 =
F_17 ( V_19 -> V_49 + V_50 ) ;
V_48 =
( V_48 & ~ V_34 -> V_47 ) | ( V_34 ->
V_51 ) ;
F_19 ( V_48 , V_19 -> V_49 + V_50 ) ;
}
}
static int F_21 ( struct V_1 * V_52 , unsigned V_4 ,
unsigned V_24 )
{
struct V_18 * V_19 ;
V_19 = F_7 ( V_52 ) ;
F_16 ( V_19 , V_4 , true ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_52 , unsigned V_4 ,
unsigned V_24 )
{
struct V_18 * V_19 ;
V_19 = F_7 ( V_52 ) ;
F_16 ( V_19 , V_4 , false ) ;
}
static int F_23 ( struct V_1 * V_52 )
{
return V_53 ;
}
static const char * F_24 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_38 [ V_4 ] . V_6 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned V_4 ,
const char * const * * V_54 ,
unsigned * const V_55 )
{
* V_54 = V_38 [ V_4 ] . V_54 ;
* V_55 = V_38 [ V_4 ] . V_55 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_52 ,
struct V_56 * V_57 , unsigned V_11 )
{
struct V_18 * V_19 ;
int V_24 = V_57 -> V_58 ;
T_1 V_44 ;
V_19 = F_7 ( V_52 ) ;
if ( ! V_19 -> V_45 ) {
V_44 = F_17 ( V_19 -> V_46 + F_18 ( V_24 ) ) ;
V_44 = V_44 | ( 1 << ( V_11 - V_57 -> V_59 ) ) ;
F_19 ( V_44 , V_19 -> V_46 + F_18 ( V_24 ) ) ;
} else {
F_19 ( 1 << ( V_11 - V_57 -> V_59 ) , V_19 -> V_46 +
F_18 ( V_24 ) ) ;
}
return 0 ;
}
static void T_2 * F_27 ( void )
{
const struct V_60 V_61 [] = {
{ . V_62 = L_5 } ,
{ . V_62 = L_6 } ,
{}
} ;
struct V_13 * V_20 ;
V_20 = F_28 ( NULL , V_61 ) ;
if ( ! V_20 )
F_29 ( L_7 ) ;
return F_30 ( V_20 , 0 ) ;
}
static int F_31 ( struct V_63 * V_64 ,
const struct V_65 * V_66 ,
T_1 * V_67 )
{
if ( V_66 -> args [ 0 ] > V_68 * V_69 )
return - V_70 ;
if ( V_64 != & V_71 [ V_66 -> args [ 0 ] / V_69 ] . V_72 . V_64 )
return - V_70 ;
if ( V_67 )
* V_67 = V_66 -> args [ 1 ] ;
return V_66 -> args [ 0 ] % V_69 ;
}
static int F_32 ( struct V_73 * V_74 )
{
int V_25 ;
struct V_18 * V_19 ;
struct V_13 * V_20 = V_74 -> V_28 . V_75 ;
const struct V_76 * V_77 ;
int V_36 ;
V_19 = F_33 ( & V_74 -> V_28 , sizeof( * V_19 ) , V_30 ) ;
if ( ! V_19 )
return - V_31 ;
V_19 -> V_28 = & V_74 -> V_28 ;
F_34 ( V_74 , V_19 ) ;
V_19 -> V_46 = F_30 ( V_20 , 0 ) ;
if ( ! V_19 -> V_46 ) {
F_11 ( & V_74 -> V_28 , L_8 ) ;
return - V_31 ;
}
V_19 -> V_49 = F_27 () ;
if ( ! V_19 -> V_49 ) {
V_25 = - V_31 ;
F_11 ( & V_74 -> V_28 , L_9 ) ;
goto V_78;
}
if ( F_35 ( V_20 , L_10 ) )
V_19 -> V_45 = 1 ;
V_77 = F_36 ( V_79 , V_20 ) -> V_33 ;
V_5 = V_77 -> V_80 ;
V_3 = V_77 -> V_81 ;
V_38 = V_77 -> V_82 ;
V_53 = V_77 -> V_83 ;
V_84 . V_7 = V_77 -> V_85 ;
V_84 . V_86 = V_77 -> V_87 ;
V_19 -> V_88 = F_37 ( & V_84 , & V_74 -> V_28 , V_19 ) ;
if ( ! V_19 -> V_88 ) {
F_11 ( & V_74 -> V_28 , L_11 ) ;
V_25 = - V_70 ;
goto V_89;
}
for ( V_36 = 0 ; V_36 < F_38 ( V_90 ) ; V_36 ++ ) {
V_90 [ V_36 ] . V_64 = & V_71 [ V_36 ] . V_72 . V_64 ;
F_39 ( V_19 -> V_88 , & V_90 [ V_36 ] ) ;
}
F_40 ( & V_74 -> V_28 , L_12 ) ;
return 0 ;
V_89:
F_41 ( V_19 -> V_49 ) ;
V_78:
F_41 ( V_19 -> V_46 ) ;
return V_25 ;
}
static int F_42 ( struct V_91 * V_28 )
{
int V_36 , V_92 ;
struct V_18 * V_19 = F_43 ( V_28 ) ;
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ ) {
for ( V_92 = 0 ; V_92 < V_69 ; V_92 ++ ) {
V_19 -> V_93 [ V_36 ] [ V_92 ] = F_17 ( V_19 -> V_46 +
F_44 ( V_36 , V_92 ) ) ;
}
V_19 -> V_94 [ V_36 ] = F_17 ( V_19 -> V_46 +
F_45 ( V_36 ) ) ;
V_19 -> V_95 [ V_36 ] = F_17 ( V_19 -> V_46 +
F_18 ( V_36 ) ) ;
}
V_19 -> V_96 = F_17 ( V_19 -> V_46 + V_97 ) ;
for ( V_36 = 0 ; V_36 < 3 ; V_36 ++ )
V_19 -> V_98 [ V_36 ] = F_17 ( V_19 -> V_49 + 4 * V_36 ) ;
return 0 ;
}
static int F_46 ( struct V_91 * V_28 )
{
int V_36 , V_92 ;
struct V_18 * V_19 = F_43 ( V_28 ) ;
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ ) {
for ( V_92 = 0 ; V_92 < V_69 ; V_92 ++ ) {
F_19 ( V_19 -> V_93 [ V_36 ] [ V_92 ] , V_19 -> V_46 +
F_44 ( V_36 , V_92 ) ) ;
}
F_19 ( V_19 -> V_94 [ V_36 ] , V_19 -> V_46 +
F_45 ( V_36 ) ) ;
F_19 ( V_19 -> V_95 [ V_36 ] , V_19 -> V_46 +
F_18 ( V_36 ) ) ;
}
F_19 ( V_19 -> V_96 , V_19 -> V_46 + V_97 ) ;
for ( V_36 = 0 ; V_36 < 3 ; V_36 ++ )
F_19 ( V_19 -> V_98 [ V_36 ] , V_19 -> V_49 + 4 * V_36 ) ;
return 0 ;
}
static int T_3 F_47 ( void )
{
return F_48 ( & V_99 ) ;
}
static inline int F_49 ( struct V_63 * V_72 , unsigned V_11 )
{
struct V_100 * V_101 = F_50 ( F_51 ( V_72 ) ,
struct V_100 , V_72 ) ;
return F_52 ( V_101 -> V_102 , V_11 ) ;
}
static inline int F_53 ( unsigned int V_103 )
{
return V_103 % V_69 ;
}
static inline struct V_100 * F_54 ( unsigned int V_103 )
{
return & V_71 [ V_103 / V_69 ] ;
}
static inline struct V_100 * F_55 ( struct V_63 * V_72 )
{
return F_50 ( F_51 ( V_72 ) , struct V_100 , V_72 ) ;
}
static void F_56 ( struct V_104 * V_105 )
{
struct V_100 * V_101 = F_57 ( V_105 ) ;
int V_106 = V_105 -> V_107 % V_69 ;
T_1 V_108 , V_11 ;
unsigned long V_67 ;
V_11 = F_44 ( V_101 -> V_58 , V_106 ) ;
F_58 ( & V_109 , V_67 ) ;
V_108 = F_17 ( V_101 -> V_72 . V_110 + V_11 ) ;
F_19 ( V_108 , V_101 -> V_72 . V_110 + V_11 ) ;
F_59 ( & V_109 , V_67 ) ;
}
static void F_60 ( struct V_100 * V_101 , int V_106 )
{
T_1 V_108 , V_11 ;
unsigned long V_67 ;
V_11 = F_44 ( V_101 -> V_58 , V_106 ) ;
F_58 ( & V_109 , V_67 ) ;
V_108 = F_17 ( V_101 -> V_72 . V_110 + V_11 ) ;
V_108 &= ~ V_111 ;
V_108 &= ~ V_112 ;
F_19 ( V_108 , V_101 -> V_72 . V_110 + V_11 ) ;
F_59 ( & V_109 , V_67 ) ;
}
static void F_61 ( struct V_104 * V_105 )
{
struct V_100 * V_101 = F_57 ( V_105 ) ;
F_60 ( V_101 , V_105 -> V_107 % V_69 ) ;
}
static void F_62 ( struct V_104 * V_105 )
{
struct V_100 * V_101 = F_57 ( V_105 ) ;
int V_106 = V_105 -> V_107 % V_69 ;
T_1 V_108 , V_11 ;
unsigned long V_67 ;
V_11 = F_44 ( V_101 -> V_58 , V_106 ) ;
F_58 ( & V_109 , V_67 ) ;
V_108 = F_17 ( V_101 -> V_72 . V_110 + V_11 ) ;
V_108 &= ~ V_112 ;
V_108 |= V_111 ;
F_19 ( V_108 , V_101 -> V_72 . V_110 + V_11 ) ;
F_59 ( & V_109 , V_67 ) ;
}
static int F_63 ( struct V_104 * V_105 , unsigned type )
{
struct V_100 * V_101 = F_57 ( V_105 ) ;
int V_106 = V_105 -> V_107 % V_69 ;
T_1 V_108 , V_11 ;
unsigned long V_67 ;
V_11 = F_44 ( V_101 -> V_58 , V_106 ) ;
F_58 ( & V_109 , V_67 ) ;
V_108 = F_17 ( V_101 -> V_72 . V_110 + V_11 ) ;
V_108 &= ~ V_112 ;
switch ( type ) {
case V_113 :
break;
case V_114 :
V_108 |= V_115 | V_116 ;
V_108 &= ~ V_117 ;
break;
case V_118 :
V_108 &= ~ V_115 ;
V_108 |= V_117 | V_116 ;
break;
case V_119 :
V_108 |= V_115 | V_117 |
V_116 ;
break;
case V_120 :
V_108 &= ~ ( V_115 | V_116 ) ;
V_108 |= V_117 ;
break;
case V_121 :
V_108 |= V_115 ;
V_108 &= ~ ( V_117 | V_116 ) ;
break;
}
F_19 ( V_108 , V_101 -> V_72 . V_110 + V_11 ) ;
F_59 ( & V_109 , V_67 ) ;
return 0 ;
}
static void F_64 ( unsigned int V_122 , struct V_123 * V_124 )
{
struct V_100 * V_101 = F_65 ( V_122 ) ;
T_1 V_125 , V_126 ;
int V_106 = 0 ;
struct V_127 * V_72 = F_66 ( V_122 ) ;
F_67 ( V_72 , V_124 ) ;
V_125 = F_17 ( V_101 -> V_72 . V_110 + F_45 ( V_101 -> V_58 ) ) ;
if ( ! V_125 ) {
F_68 ( V_128
L_13 ,
V_129 , V_101 -> V_58 , V_125 ) ;
F_69 ( V_122 , V_124 ) ;
return;
}
while ( V_125 ) {
V_126 = F_17 ( V_101 -> V_72 . V_110 + F_44 ( V_101 -> V_58 , V_106 ) ) ;
if ( ( V_125 & 0x1 ) && ( V_126 & V_111 ) ) {
F_70 ( L_14 ,
V_129 , V_101 -> V_58 , V_106 ) ;
F_71 ( F_72 ( V_101 -> V_102 , V_106 ) ) ;
}
V_106 ++ ;
V_125 = V_125 >> 1 ;
}
F_73 ( V_72 , V_124 ) ;
}
static inline void F_74 ( struct V_100 * V_101 , unsigned V_130 )
{
T_1 V_108 ;
V_108 = F_17 ( V_101 -> V_72 . V_110 + V_130 ) ;
V_108 &= ~ V_131 ;
F_19 ( V_108 , V_101 -> V_72 . V_110 + V_130 ) ;
}
static int F_75 ( struct V_63 * V_72 , unsigned V_11 )
{
struct V_100 * V_101 = F_55 ( V_72 ) ;
unsigned long V_67 ;
if ( F_76 ( V_72 -> V_132 + V_11 ) )
return - V_29 ;
F_58 ( & V_101 -> V_133 , V_67 ) ;
F_74 ( V_101 , F_44 ( V_101 -> V_58 , V_11 ) ) ;
F_60 ( V_101 , V_11 ) ;
F_59 ( & V_101 -> V_133 , V_67 ) ;
return 0 ;
}
static void F_77 ( struct V_63 * V_72 , unsigned V_11 )
{
struct V_100 * V_101 = F_55 ( V_72 ) ;
unsigned long V_67 ;
F_58 ( & V_101 -> V_133 , V_67 ) ;
F_60 ( V_101 , V_11 ) ;
F_74 ( V_101 , F_44 ( V_101 -> V_58 , V_11 ) ) ;
F_59 ( & V_101 -> V_133 , V_67 ) ;
F_78 ( V_72 -> V_132 + V_11 ) ;
}
static int F_79 ( struct V_63 * V_72 , unsigned V_103 )
{
struct V_100 * V_101 = F_55 ( V_72 ) ;
int V_106 = F_53 ( V_103 ) ;
unsigned long V_67 ;
unsigned V_11 ;
V_11 = F_44 ( V_101 -> V_58 , V_106 ) ;
F_58 ( & V_101 -> V_133 , V_67 ) ;
F_74 ( V_101 , V_11 ) ;
F_59 ( & V_101 -> V_133 , V_67 ) ;
return 0 ;
}
static inline void F_80 ( struct V_100 * V_101 , unsigned V_11 ,
int V_134 )
{
T_1 V_135 ;
unsigned long V_67 ;
F_58 ( & V_101 -> V_133 , V_67 ) ;
V_135 = F_17 ( V_101 -> V_72 . V_110 + V_11 ) ;
if ( V_134 )
V_135 |= V_136 ;
else
V_135 &= ~ V_136 ;
V_135 &= ~ V_111 ;
V_135 |= V_131 ;
F_19 ( V_135 , V_101 -> V_72 . V_110 + V_11 ) ;
F_59 ( & V_101 -> V_133 , V_67 ) ;
}
static int F_81 ( struct V_63 * V_72 , unsigned V_103 , int V_134 )
{
struct V_100 * V_101 = F_55 ( V_72 ) ;
int V_106 = F_53 ( V_103 ) ;
T_1 V_11 ;
unsigned long V_67 ;
V_11 = F_44 ( V_101 -> V_58 , V_106 ) ;
F_58 ( & V_109 , V_67 ) ;
F_80 ( V_101 , V_11 , V_134 ) ;
F_59 ( & V_109 , V_67 ) ;
return 0 ;
}
static int F_82 ( struct V_63 * V_72 , unsigned V_11 )
{
struct V_100 * V_101 = F_55 ( V_72 ) ;
T_1 V_108 ;
unsigned long V_67 ;
F_58 ( & V_101 -> V_133 , V_67 ) ;
V_108 = F_17 ( V_101 -> V_72 . V_110 + F_44 ( V_101 -> V_58 , V_11 ) ) ;
F_59 ( & V_101 -> V_133 , V_67 ) ;
return ! ! ( V_108 & V_137 ) ;
}
static void F_83 ( struct V_63 * V_72 , unsigned V_11 ,
int V_134 )
{
struct V_100 * V_101 = F_55 ( V_72 ) ;
T_1 V_126 ;
unsigned long V_67 ;
F_58 ( & V_101 -> V_133 , V_67 ) ;
V_126 = F_17 ( V_101 -> V_72 . V_110 + F_44 ( V_101 -> V_58 , V_11 ) ) ;
if ( V_134 )
V_126 |= V_136 ;
else
V_126 &= ~ V_136 ;
F_19 ( V_126 , V_101 -> V_72 . V_110 + F_44 ( V_101 -> V_58 , V_11 ) ) ;
F_59 ( & V_101 -> V_133 , V_67 ) ;
}
static int F_84 ( struct V_138 * V_105 , unsigned int V_122 ,
T_4 V_107 )
{
struct V_100 * V_101 = V_105 -> V_139 ;
if ( ! V_101 )
return - V_70 ;
F_85 ( V_122 , & V_140 ) ;
F_86 ( V_122 , V_141 ) ;
F_87 ( V_122 , V_101 ) ;
F_88 ( V_122 , V_142 ) ;
return 0 ;
}
static void F_89 ( const T_1 * V_143 )
{
int V_36 , V_144 ;
const unsigned long * V_145 = ( const unsigned long * ) V_143 ;
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ ) {
F_90 (n, p + i, BITS_PER_LONG) {
T_1 V_11 = F_44 ( V_36 , V_144 ) ;
T_1 V_108 = F_17 ( V_71 [ V_36 ] . V_72 . V_110 + V_11 ) ;
V_108 |= V_146 ;
V_108 |= V_147 ;
F_19 ( V_108 , V_71 [ V_36 ] . V_72 . V_110 + V_11 ) ;
}
}
}
static void F_91 ( const T_1 * V_148 )
{
int V_36 , V_144 ;
const unsigned long * V_145 = ( const unsigned long * ) V_148 ;
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ ) {
F_90 (n, p + i, BITS_PER_LONG) {
T_1 V_11 = F_44 ( V_36 , V_144 ) ;
T_1 V_108 = F_17 ( V_71 [ V_36 ] . V_72 . V_110 + V_11 ) ;
V_108 |= V_146 ;
V_108 &= ~ V_147 ;
F_19 ( V_108 , V_71 [ V_36 ] . V_72 . V_110 + V_11 ) ;
}
}
}
static int F_92 ( struct V_13 * V_20 )
{
int V_36 , V_149 = 0 ;
struct V_100 * V_101 ;
void T_2 * V_110 ;
struct V_73 * V_74 ;
bool V_45 = false ;
T_1 V_143 [ V_68 ] , V_148 [ V_68 ] ;
V_74 = F_93 ( V_20 ) ;
if ( ! V_74 )
return - V_29 ;
V_110 = F_30 ( V_20 , 0 ) ;
if ( ! V_110 )
return - V_31 ;
if ( F_35 ( V_20 , L_10 ) )
V_45 = 1 ;
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ ) {
V_101 = & V_71 [ V_36 ] ;
F_94 ( & V_101 -> V_133 ) ;
V_101 -> V_72 . V_64 . V_150 = F_75 ;
V_101 -> V_72 . V_64 . free = F_77 ;
V_101 -> V_72 . V_64 . V_151 = F_79 ;
V_101 -> V_72 . V_64 . V_152 = F_82 ;
V_101 -> V_72 . V_64 . V_153 = F_81 ;
V_101 -> V_72 . V_64 . V_154 = F_83 ;
V_101 -> V_72 . V_64 . V_155 = F_49 ;
V_101 -> V_72 . V_64 . V_132 = V_36 * V_69 ;
V_101 -> V_72 . V_64 . V_156 = V_69 ;
V_101 -> V_72 . V_64 . V_157 = F_95 ( V_20 -> V_158 , V_30 ) ;
V_101 -> V_72 . V_64 . V_75 = V_20 ;
V_101 -> V_72 . V_64 . V_159 = F_31 ;
V_101 -> V_72 . V_64 . V_160 = 2 ;
V_101 -> V_72 . V_110 = V_110 ;
V_101 -> V_58 = V_36 ;
V_101 -> V_45 = V_45 ;
V_101 -> V_161 = F_96 ( V_74 , V_36 ) ;
if ( V_101 -> V_161 < 0 ) {
V_149 = V_101 -> V_161 ;
goto V_162;
}
V_149 = F_97 ( & V_101 -> V_72 . V_64 ) ;
if ( V_149 ) {
F_98 ( L_15 ,
V_20 -> V_158 , V_149 ) ;
goto V_162;
}
V_101 -> V_102 = F_99 ( V_20 , V_69 ,
& V_163 , V_101 ) ;
if ( ! V_101 -> V_102 ) {
F_98 ( L_16 , V_20 -> V_158 ) ;
V_149 = - V_164 ;
goto V_162;
}
F_100 ( V_101 -> V_161 , F_64 ) ;
F_101 ( V_101 -> V_161 , V_101 ) ;
}
if ( ! F_102 ( V_20 , L_17 , V_143 ,
V_68 ) )
F_89 ( V_143 ) ;
if ( ! F_102 ( V_20 , L_18 , V_148 ,
V_68 ) )
F_91 ( V_148 ) ;
return 0 ;
V_162:
F_41 ( V_110 ) ;
return V_149 ;
}
static int T_3 F_103 ( void )
{
struct V_13 * V_20 ;
V_20 = F_28 ( NULL , V_79 ) ;
if ( ! V_20 )
return - V_29 ;
return F_92 ( V_20 ) ;
}
