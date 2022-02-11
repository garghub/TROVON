static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_3 [ V_4 ] . V_5 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_4 ,
const unsigned * * V_6 ,
unsigned * V_7 )
{
* V_6 = V_3 [ V_4 ] . V_6 ;
* V_7 = V_3 [ V_4 ] . V_7 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_8 * V_9 ,
unsigned V_10 )
{
F_6 ( V_9 , L_1 V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * * V_15 , unsigned * V_16 )
{
struct V_17 * V_18 = F_8 ( V_2 ) ;
struct V_12 * V_19 ;
struct V_20 * V_21 ;
const char * V_22 , * V_23 ;
int V_24 , V_25 = 0 , V_26 = 0 ;
F_9 (np_config, np) {
V_24 = F_10 ( V_19 , L_2 , & V_22 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_11 ( V_19 , L_3 ) ;
if ( V_24 < 0 )
return V_24 ;
V_26 += V_24 ;
}
if ( ! V_26 ) {
F_12 ( V_18 -> V_27 , L_4 ) ;
return - V_28 ;
}
* V_15 = F_13 ( sizeof( * * V_15 ) * V_26 , V_29 ) ;
if ( ! * V_15 )
return - V_30 ;
F_9 (np_config, np) {
F_10 ( V_19 , L_2 , & V_22 ) ;
F_14 (np, L_3 , prop, group) {
( * V_15 ) [ V_25 ] . type = V_31 ;
( * V_15 ) [ V_25 ] . V_32 . V_33 . V_23 = V_23 ;
( * V_15 ) [ V_25 ] . V_32 . V_33 . V_22 = V_22 ;
V_25 ++ ;
}
}
* V_16 = V_26 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_14 * V_15 , unsigned V_16 )
{
F_16 ( V_15 ) ;
}
static void F_17 ( struct V_17 * V_18 , unsigned V_4 ,
bool V_34 )
{
int V_35 ;
const struct V_36 * V_33 = V_37 [ V_4 ] . V_38 ;
const struct V_39 * V_40 = V_33 -> V_41 ;
for ( V_35 = 0 ; V_35 < V_33 -> V_42 ; V_35 ++ ) {
T_1 V_43 ;
if ( ! V_18 -> V_44 ) {
V_43 = F_18 ( V_18 -> V_45 + F_19 ( V_40 [ V_35 ] . V_23 ) ) ;
if ( V_34 )
V_43 = V_43 & ~ V_40 [ V_35 ] . V_40 ;
else
V_43 = V_43 | V_40 [ V_35 ] . V_40 ;
F_20 ( V_43 , V_18 -> V_45 + F_19 ( V_40 [ V_35 ] . V_23 ) ) ;
} else {
if ( V_34 )
F_20 ( V_40 [ V_35 ] . V_40 , V_18 -> V_45 +
F_21 ( V_40 [ V_35 ] . V_23 ) ) ;
else
F_20 ( V_40 [ V_35 ] . V_40 , V_18 -> V_45 +
F_19 ( V_40 [ V_35 ] . V_23 ) ) ;
}
}
if ( V_33 -> V_46 && V_34 ) {
T_1 V_47 ;
V_47 =
F_18 ( V_18 -> V_48 + V_49 ) ;
V_47 =
( V_47 & ~ V_33 -> V_46 ) | ( V_33 ->
V_50 ) ;
F_20 ( V_47 , V_18 -> V_48 + V_49 ) ;
}
}
static int F_22 ( struct V_1 * V_51 , unsigned V_4 ,
unsigned V_23 )
{
struct V_17 * V_18 ;
V_18 = F_8 ( V_51 ) ;
F_17 ( V_18 , V_4 , true ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_51 , unsigned V_4 ,
unsigned V_23 )
{
struct V_17 * V_18 ;
V_18 = F_8 ( V_51 ) ;
F_17 ( V_18 , V_4 , false ) ;
}
static int F_24 ( struct V_1 * V_51 )
{
return F_2 ( V_37 ) ;
}
static const char * F_25 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_37 [ V_4 ] . V_5 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned V_4 ,
const char * const * * V_52 ,
unsigned * const V_53 )
{
* V_52 = V_37 [ V_4 ] . V_52 ;
* V_53 = V_37 [ V_4 ] . V_53 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_51 ,
struct V_54 * V_55 , unsigned V_10 )
{
struct V_17 * V_18 ;
int V_23 = V_55 -> V_56 ;
T_1 V_43 ;
V_18 = F_8 ( V_51 ) ;
if ( ! V_18 -> V_44 ) {
V_43 = F_18 ( V_18 -> V_45 + F_19 ( V_23 ) ) ;
V_43 = V_43 | ( 1 << ( V_10 - V_55 -> V_57 ) ) ;
F_20 ( V_43 , V_18 -> V_45 + F_19 ( V_23 ) ) ;
} else {
F_20 ( 1 << ( V_10 - V_55 -> V_57 ) , V_18 -> V_45 +
F_19 ( V_23 ) ) ;
}
return 0 ;
}
static void T_2 * F_28 ( void )
{
const struct V_58 V_59 [] = {
{ . V_60 = L_5 } ,
{ . V_60 = L_6 } ,
{}
} ;
struct V_12 * V_19 ;
V_19 = F_29 ( NULL , V_59 ) ;
if ( ! V_19 )
F_30 ( L_7 ) ;
return F_31 ( V_19 , 0 ) ;
}
static int F_32 ( struct V_61 * V_62 ,
const struct V_63 * V_64 ,
T_1 * V_65 )
{
if ( V_64 -> args [ 0 ] > V_66 * V_67 )
return - V_68 ;
if ( V_62 != & V_69 [ V_64 -> args [ 0 ] / V_67 ] . V_70 . V_62 )
return - V_68 ;
if ( V_65 )
* V_65 = V_64 -> args [ 1 ] ;
return V_64 -> args [ 0 ] % V_67 ;
}
static int F_33 ( struct V_71 * V_72 )
{
int V_24 ;
struct V_17 * V_18 ;
struct V_12 * V_19 = V_72 -> V_27 . V_73 ;
int V_35 ;
V_18 = F_34 ( & V_72 -> V_27 , sizeof( * V_18 ) , V_29 ) ;
if ( ! V_18 )
return - V_30 ;
V_18 -> V_27 = & V_72 -> V_27 ;
F_35 ( V_72 , V_18 ) ;
V_18 -> V_45 = F_31 ( V_19 , 0 ) ;
if ( ! V_18 -> V_45 ) {
V_24 = - V_30 ;
F_12 ( & V_72 -> V_27 , L_8 ) ;
goto V_74;
}
V_18 -> V_48 = F_28 () ;
if ( ! V_18 -> V_48 ) {
V_24 = - V_30 ;
F_12 ( & V_72 -> V_27 , L_9 ) ;
goto V_75;
}
if ( F_36 ( V_19 , L_10 ) )
V_18 -> V_44 = 1 ;
V_18 -> V_76 = F_37 ( & V_77 , & V_72 -> V_27 , V_18 ) ;
if ( ! V_18 -> V_76 ) {
F_12 ( & V_72 -> V_27 , L_11 ) ;
V_24 = - V_68 ;
goto V_78;
}
for ( V_35 = 0 ; V_35 < F_2 ( V_79 ) ; V_35 ++ ) {
V_79 [ V_35 ] . V_62 = & V_69 [ V_35 ] . V_70 . V_62 ;
F_38 ( V_18 -> V_76 , & V_79 [ V_35 ] ) ;
}
F_39 ( & V_72 -> V_27 , L_12 ) ;
return 0 ;
V_78:
F_40 ( V_18 -> V_48 ) ;
V_75:
F_40 ( V_18 -> V_45 ) ;
V_74:
F_35 ( V_72 , NULL ) ;
return V_24 ;
}
static int T_3 F_41 ( void )
{
return F_42 ( & V_80 ) ;
}
static inline int F_43 ( struct V_61 * V_70 , unsigned V_10 )
{
struct V_81 * V_82 = F_44 ( F_45 ( V_70 ) ,
struct V_81 , V_70 ) ;
return F_46 ( V_82 -> V_83 , V_10 ) ;
}
static inline int F_47 ( unsigned int V_84 )
{
return V_84 % V_67 ;
}
static inline struct V_81 * F_48 ( unsigned int V_84 )
{
return & V_69 [ V_84 / V_67 ] ;
}
static inline struct V_81 * F_49 ( struct V_61 * V_70 )
{
return F_44 ( F_45 ( V_70 ) , struct V_81 , V_70 ) ;
}
static void F_50 ( struct V_85 * V_86 )
{
struct V_81 * V_82 = F_51 ( V_86 ) ;
int V_87 = V_86 -> V_88 % V_67 ;
T_1 V_89 , V_10 ;
unsigned long V_65 ;
V_10 = F_52 ( V_82 -> V_56 , V_87 ) ;
F_53 ( & V_90 , V_65 ) ;
V_89 = F_18 ( V_82 -> V_70 . V_91 + V_10 ) ;
F_20 ( V_89 , V_82 -> V_70 . V_91 + V_10 ) ;
F_54 ( & V_90 , V_65 ) ;
}
static void F_55 ( struct V_81 * V_82 , int V_87 )
{
T_1 V_89 , V_10 ;
unsigned long V_65 ;
V_10 = F_52 ( V_82 -> V_56 , V_87 ) ;
F_53 ( & V_90 , V_65 ) ;
V_89 = F_18 ( V_82 -> V_70 . V_91 + V_10 ) ;
V_89 &= ~ V_92 ;
V_89 &= ~ V_93 ;
F_20 ( V_89 , V_82 -> V_70 . V_91 + V_10 ) ;
F_54 ( & V_90 , V_65 ) ;
}
static void F_56 ( struct V_85 * V_86 )
{
struct V_81 * V_82 = F_51 ( V_86 ) ;
F_55 ( V_82 , V_86 -> V_88 % V_67 ) ;
}
static void F_57 ( struct V_85 * V_86 )
{
struct V_81 * V_82 = F_51 ( V_86 ) ;
int V_87 = V_86 -> V_88 % V_67 ;
T_1 V_89 , V_10 ;
unsigned long V_65 ;
V_10 = F_52 ( V_82 -> V_56 , V_87 ) ;
F_53 ( & V_90 , V_65 ) ;
V_89 = F_18 ( V_82 -> V_70 . V_91 + V_10 ) ;
V_89 &= ~ V_93 ;
V_89 |= V_92 ;
F_20 ( V_89 , V_82 -> V_70 . V_91 + V_10 ) ;
F_54 ( & V_90 , V_65 ) ;
}
static int F_58 ( struct V_85 * V_86 , unsigned type )
{
struct V_81 * V_82 = F_51 ( V_86 ) ;
int V_87 = V_86 -> V_88 % V_67 ;
T_1 V_89 , V_10 ;
unsigned long V_65 ;
V_10 = F_52 ( V_82 -> V_56 , V_87 ) ;
F_53 ( & V_90 , V_65 ) ;
V_89 = F_18 ( V_82 -> V_70 . V_91 + V_10 ) ;
V_89 &= ~ V_93 ;
switch ( type ) {
case V_94 :
break;
case V_95 :
V_89 |= V_96 | V_97 ;
V_89 &= ~ V_98 ;
break;
case V_99 :
V_89 &= ~ V_96 ;
V_89 |= V_98 | V_97 ;
break;
case V_100 :
V_89 |= V_96 | V_98 |
V_97 ;
break;
case V_101 :
V_89 &= ~ ( V_96 | V_97 ) ;
V_89 |= V_98 ;
break;
case V_102 :
V_89 |= V_96 ;
V_89 &= ~ ( V_98 | V_97 ) ;
break;
}
F_20 ( V_89 , V_82 -> V_70 . V_91 + V_10 ) ;
F_54 ( & V_90 , V_65 ) ;
return 0 ;
}
static void F_59 ( unsigned int V_103 , struct V_104 * V_105 )
{
struct V_81 * V_82 = F_60 ( V_103 ) ;
T_1 V_106 , V_107 ;
int V_87 = 0 ;
struct V_108 * V_70 = F_61 ( V_103 ) ;
F_62 ( V_70 , V_105 ) ;
V_106 = F_18 ( V_82 -> V_70 . V_91 + F_63 ( V_82 -> V_56 ) ) ;
if ( ! V_106 ) {
F_64 ( V_109
L_13 ,
V_110 , V_82 -> V_56 , V_106 ) ;
F_65 ( V_103 , V_105 ) ;
return;
}
while ( V_106 ) {
V_107 = F_18 ( V_82 -> V_70 . V_91 + F_52 ( V_82 -> V_56 , V_87 ) ) ;
if ( ( V_106 & 0x1 ) && ( V_107 & V_92 ) ) {
F_66 ( L_14 ,
V_110 , V_82 -> V_56 , V_87 ) ;
F_67 ( F_68 ( V_82 -> V_83 , V_87 ) ) ;
}
V_87 ++ ;
V_106 = V_106 >> 1 ;
}
F_69 ( V_70 , V_105 ) ;
}
static inline void F_70 ( struct V_81 * V_82 , unsigned V_111 )
{
T_1 V_89 ;
V_89 = F_18 ( V_82 -> V_70 . V_91 + V_111 ) ;
V_89 &= ~ V_112 ;
F_20 ( V_89 , V_82 -> V_70 . V_91 + V_111 ) ;
}
static int F_71 ( struct V_61 * V_70 , unsigned V_10 )
{
struct V_81 * V_82 = F_49 ( V_70 ) ;
unsigned long V_65 ;
if ( F_72 ( V_70 -> V_113 + V_10 ) )
return - V_28 ;
F_53 ( & V_82 -> V_114 , V_65 ) ;
F_70 ( V_82 , F_52 ( V_82 -> V_56 , V_10 ) ) ;
F_55 ( V_82 , V_10 ) ;
F_54 ( & V_82 -> V_114 , V_65 ) ;
return 0 ;
}
static void F_73 ( struct V_61 * V_70 , unsigned V_10 )
{
struct V_81 * V_82 = F_49 ( V_70 ) ;
unsigned long V_65 ;
F_53 ( & V_82 -> V_114 , V_65 ) ;
F_55 ( V_82 , V_10 ) ;
F_70 ( V_82 , F_52 ( V_82 -> V_56 , V_10 ) ) ;
F_54 ( & V_82 -> V_114 , V_65 ) ;
F_74 ( V_70 -> V_113 + V_10 ) ;
}
static int F_75 ( struct V_61 * V_70 , unsigned V_84 )
{
struct V_81 * V_82 = F_49 ( V_70 ) ;
int V_87 = F_47 ( V_84 ) ;
unsigned long V_65 ;
unsigned V_10 ;
V_10 = F_52 ( V_82 -> V_56 , V_87 ) ;
F_53 ( & V_82 -> V_114 , V_65 ) ;
F_70 ( V_82 , V_10 ) ;
F_54 ( & V_82 -> V_114 , V_65 ) ;
return 0 ;
}
static inline void F_76 ( struct V_81 * V_82 , unsigned V_10 ,
int V_115 )
{
T_1 V_116 ;
unsigned long V_65 ;
F_53 ( & V_82 -> V_114 , V_65 ) ;
V_116 = F_18 ( V_82 -> V_70 . V_91 + V_10 ) ;
if ( V_115 )
V_116 |= V_117 ;
else
V_116 &= ~ V_117 ;
V_116 &= ~ V_92 ;
V_116 |= V_112 ;
F_20 ( V_116 , V_82 -> V_70 . V_91 + V_10 ) ;
F_54 ( & V_82 -> V_114 , V_65 ) ;
}
static int F_77 ( struct V_61 * V_70 , unsigned V_84 , int V_115 )
{
struct V_81 * V_82 = F_49 ( V_70 ) ;
int V_87 = F_47 ( V_84 ) ;
T_1 V_10 ;
unsigned long V_65 ;
V_10 = F_52 ( V_82 -> V_56 , V_87 ) ;
F_53 ( & V_90 , V_65 ) ;
F_76 ( V_82 , V_10 , V_115 ) ;
F_54 ( & V_90 , V_65 ) ;
return 0 ;
}
static int F_78 ( struct V_61 * V_70 , unsigned V_10 )
{
struct V_81 * V_82 = F_49 ( V_70 ) ;
T_1 V_89 ;
unsigned long V_65 ;
F_53 ( & V_82 -> V_114 , V_65 ) ;
V_89 = F_18 ( V_82 -> V_70 . V_91 + F_52 ( V_82 -> V_56 , V_10 ) ) ;
F_54 ( & V_82 -> V_114 , V_65 ) ;
return ! ! ( V_89 & V_118 ) ;
}
static void F_79 ( struct V_61 * V_70 , unsigned V_10 ,
int V_115 )
{
struct V_81 * V_82 = F_49 ( V_70 ) ;
T_1 V_107 ;
unsigned long V_65 ;
F_53 ( & V_82 -> V_114 , V_65 ) ;
V_107 = F_18 ( V_82 -> V_70 . V_91 + F_52 ( V_82 -> V_56 , V_10 ) ) ;
if ( V_115 )
V_107 |= V_117 ;
else
V_107 &= ~ V_117 ;
F_20 ( V_107 , V_82 -> V_70 . V_91 + F_52 ( V_82 -> V_56 , V_10 ) ) ;
F_54 ( & V_82 -> V_114 , V_65 ) ;
}
static int F_80 ( struct V_119 * V_86 , unsigned int V_103 ,
T_4 V_88 )
{
struct V_81 * V_82 = V_86 -> V_120 ;
if ( ! V_82 )
return - V_68 ;
F_81 ( V_103 , & V_121 ) ;
F_82 ( V_103 , V_122 ) ;
F_83 ( V_103 , V_82 ) ;
F_84 ( V_103 , V_123 ) ;
return 0 ;
}
static void F_85 ( const T_1 * V_124 )
{
int V_35 , V_125 ;
const unsigned long * V_126 = ( const unsigned long * ) V_124 ;
for ( V_35 = 0 ; V_35 < V_66 ; V_35 ++ ) {
F_86 (n, p + i, BITS_PER_LONG) {
T_1 V_10 = F_52 ( V_35 , V_125 ) ;
T_1 V_89 = F_18 ( V_69 [ V_35 ] . V_70 . V_91 + V_10 ) ;
V_89 |= V_127 ;
V_89 |= V_128 ;
F_20 ( V_89 , V_69 [ V_35 ] . V_70 . V_91 + V_10 ) ;
}
}
}
static void F_87 ( const T_1 * V_129 )
{
int V_35 , V_125 ;
const unsigned long * V_126 = ( const unsigned long * ) V_129 ;
for ( V_35 = 0 ; V_35 < V_66 ; V_35 ++ ) {
F_86 (n, p + i, BITS_PER_LONG) {
T_1 V_10 = F_52 ( V_35 , V_125 ) ;
T_1 V_89 = F_18 ( V_69 [ V_35 ] . V_70 . V_91 + V_10 ) ;
V_89 |= V_127 ;
V_89 &= ~ V_128 ;
F_20 ( V_89 , V_69 [ V_35 ] . V_70 . V_91 + V_10 ) ;
}
}
}
static int F_88 ( struct V_12 * V_19 )
{
int V_35 , V_130 = 0 ;
struct V_81 * V_82 ;
void * V_91 ;
struct V_71 * V_72 ;
bool V_44 = false ;
T_1 V_124 [ V_66 ] , V_129 [ V_66 ] ;
V_72 = F_89 ( V_19 ) ;
if ( ! V_72 )
return - V_28 ;
V_91 = F_31 ( V_19 , 0 ) ;
if ( ! V_91 )
return - V_30 ;
if ( F_36 ( V_19 , L_10 ) )
V_44 = 1 ;
for ( V_35 = 0 ; V_35 < V_66 ; V_35 ++ ) {
V_82 = & V_69 [ V_35 ] ;
F_90 ( & V_82 -> V_114 ) ;
V_82 -> V_70 . V_62 . V_131 = F_71 ;
V_82 -> V_70 . V_62 . free = F_73 ;
V_82 -> V_70 . V_62 . V_132 = F_75 ;
V_82 -> V_70 . V_62 . V_133 = F_78 ;
V_82 -> V_70 . V_62 . V_134 = F_77 ;
V_82 -> V_70 . V_62 . V_135 = F_79 ;
V_82 -> V_70 . V_62 . V_136 = F_43 ;
V_82 -> V_70 . V_62 . V_113 = V_35 * V_67 ;
V_82 -> V_70 . V_62 . V_137 = V_67 ;
V_82 -> V_70 . V_62 . V_138 = F_91 ( V_19 -> V_139 , V_29 ) ;
V_82 -> V_70 . V_62 . V_73 = V_19 ;
V_82 -> V_70 . V_62 . V_140 = F_32 ;
V_82 -> V_70 . V_62 . V_141 = 2 ;
V_82 -> V_70 . V_91 = V_91 ;
V_82 -> V_56 = V_35 ;
V_82 -> V_44 = V_44 ;
V_82 -> V_142 = F_92 ( V_72 , V_35 ) ;
if ( V_82 -> V_142 < 0 ) {
V_130 = V_82 -> V_142 ;
goto V_143;
}
V_130 = F_93 ( & V_82 -> V_70 . V_62 ) ;
if ( V_130 ) {
F_94 ( L_15 ,
V_19 -> V_139 , V_130 ) ;
goto V_143;
}
V_82 -> V_83 = F_95 ( V_19 , V_67 ,
& V_144 , V_82 ) ;
if ( ! V_82 -> V_83 ) {
F_94 ( L_16 , V_19 -> V_139 ) ;
V_130 = - V_145 ;
goto V_143;
}
F_96 ( V_82 -> V_142 , F_59 ) ;
F_97 ( V_82 -> V_142 , V_82 ) ;
}
if ( ! F_98 ( V_19 , L_17 , V_124 ,
V_66 ) )
F_85 ( V_124 ) ;
if ( ! F_98 ( V_19 , L_18 , V_129 ,
V_66 ) )
F_87 ( V_129 ) ;
return 0 ;
V_143:
F_40 ( V_91 ) ;
return V_130 ;
}
static int T_3 F_99 ( void )
{
struct V_12 * V_19 ;
V_19 = F_29 ( NULL , V_146 ) ;
if ( ! V_19 )
return - V_28 ;
return F_88 ( V_19 ) ;
}
