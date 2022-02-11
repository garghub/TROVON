static inline T_1 F_1 ( void * V_1 )
{
unsigned long V_2 = ( unsigned long ) V_1 ;
return ( V_2 & 0xFFFFFFFF ) ^ ( V_3 > 32 ? V_2 >> 32 : 0 ) ;
}
static T_1 F_2 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
T_2 V_8 = F_3 ( V_7 ) ;
if ( V_8 )
return F_4 ( V_8 ) ;
return F_1 ( V_5 -> V_9 ) ;
}
static T_1 F_5 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
T_2 V_10 = F_6 ( V_7 ) ;
if ( V_10 )
return F_4 ( V_10 ) ;
return F_1 ( F_7 ( V_5 ) ) ^ ( V_11 V_12 ) F_8 ( V_5 ) ;
}
static T_1 F_9 ( const struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
return V_7 -> V_13 . V_14 ;
}
static T_1 F_10 ( const struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
if ( V_7 -> V_15 . V_15 )
return F_11 ( V_7 -> V_15 . V_8 ) ;
return F_1 ( V_5 -> V_9 ) ;
}
static T_1 F_12 ( const struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
if ( V_7 -> V_15 . V_15 )
return F_11 ( V_7 -> V_15 . V_10 ) ;
return F_1 ( F_7 ( V_5 ) ) ^ ( V_11 V_12 ) F_8 ( V_5 ) ;
}
static T_1 F_13 ( const struct V_4 * V_5 )
{
return V_5 -> V_16 ;
}
static T_1 F_14 ( const struct V_4 * V_5 )
{
return V_5 -> V_17 ;
}
static T_1 F_15 ( const struct V_4 * V_5 )
{
return V_5 -> V_18 ;
}
static T_1 F_16 ( const struct V_4 * V_5 )
{
#if F_17 ( V_19 )
return F_1 ( V_5 -> V_20 ) ;
#else
return 0 ;
#endif
}
static T_1 F_18 ( const struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
switch ( F_8 ( V_5 ) ) {
case F_19 ( V_21 ) :
return F_4 ( F_20 ( V_5 , V_8 . V_22 . V_23 ) ) ;
case F_19 ( V_24 ) :
return F_4 ( F_20 ( V_5 , V_8 . V_22 . V_25 [ 3 ] ) ) ;
}
V_26:
return F_2 ( V_5 , V_7 ) ;
}
static T_1 F_21 ( const struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
switch ( F_8 ( V_5 ) ) {
case F_19 ( V_21 ) :
return F_4 ( F_20 ( V_5 , V_10 . V_22 . V_23 ) ) ;
case F_19 ( V_24 ) :
return F_4 ( F_20 ( V_5 , V_10 . V_22 . V_25 [ 3 ] ) ) ;
}
V_26:
return F_5 ( V_5 , V_7 ) ;
}
static T_1 F_22 ( const struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
return F_11 ( F_20 ( V_5 , V_8 . V_27 . V_28 ) ) ;
V_26:
return F_10 ( V_5 , V_7 ) ;
}
static T_1 F_23 ( const struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
return F_11 ( F_20 ( V_5 , V_10 . V_27 . V_28 ) ) ;
V_26:
return F_12 ( V_5 , V_7 ) ;
}
static T_1 F_24 ( const struct V_4 * V_5 )
{
#ifdef F_25
if ( F_7 ( V_5 ) )
return F_7 ( V_5 ) -> V_29 ;
#endif
return 0 ;
}
static T_1 F_26 ( const struct V_4 * V_5 )
{
struct V_30 * V_9 = F_27 ( V_5 ) ;
if ( V_9 && V_9 -> V_31 && V_9 -> V_31 -> V_32 ) {
T_3 V_33 = V_9 -> V_31 -> V_32 -> V_34 -> V_35 ;
return F_28 ( & V_36 , V_33 ) ;
}
return 0 ;
}
static T_1 F_29 ( const struct V_4 * V_5 )
{
struct V_30 * V_9 = F_27 ( V_5 ) ;
if ( V_9 && V_9 -> V_31 && V_9 -> V_31 -> V_32 ) {
T_4 V_37 = V_9 -> V_31 -> V_32 -> V_34 -> V_38 ;
return F_30 ( & V_36 , V_37 ) ;
}
return 0 ;
}
static T_1 F_31 ( const struct V_4 * V_5 )
{
V_12 V_39 ( V_40 ) ;
if ( F_32 ( V_5 , & V_40 ) < 0 )
return 0 ;
return V_40 & V_41 ;
}
static T_1 F_33 ( struct V_4 * V_5 )
{
return F_34 ( V_5 ) ;
}
static T_1 F_35 ( struct V_4 * V_5 , int V_42 , struct V_6 * V_7 )
{
switch ( V_42 ) {
case V_43 :
return F_2 ( V_5 , V_7 ) ;
case V_44 :
return F_5 ( V_5 , V_7 ) ;
case V_45 :
return F_9 ( V_5 , V_7 ) ;
case V_46 :
return F_10 ( V_5 , V_7 ) ;
case V_47 :
return F_12 ( V_5 , V_7 ) ;
case V_48 :
return F_13 ( V_5 ) ;
case V_49 :
return F_14 ( V_5 ) ;
case V_50 :
return F_15 ( V_5 ) ;
case V_51 :
return F_16 ( V_5 ) ;
case V_52 :
return F_18 ( V_5 , V_7 ) ;
case V_53 :
return F_21 ( V_5 , V_7 ) ;
case V_54 :
return F_22 ( V_5 , V_7 ) ;
case V_55 :
return F_23 ( V_5 , V_7 ) ;
case V_56 :
return F_24 ( V_5 ) ;
case V_57 :
return F_26 ( V_5 ) ;
case V_58 :
return F_29 ( V_5 ) ;
case V_59 :
return F_31 ( V_5 ) ;
case V_60 :
return F_33 ( V_5 ) ;
default:
F_36 ( 1 ) ;
return 0 ;
}
}
static int F_37 ( struct V_4 * V_5 , const struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_65 * V_66 = F_38 ( V_62 -> V_67 ) ;
struct V_68 * V_69 ;
T_1 V_70 ;
T_1 V_71 ;
unsigned int V_72 , V_42 ;
int V_73 ;
F_39 (f, &head->filters, list) {
T_1 V_74 [ V_75 + 1 ] ;
struct V_6 V_6 ;
if ( ! F_40 ( V_5 , & V_69 -> V_76 , NULL ) )
continue;
V_70 = V_69 -> V_70 ;
if ( V_70 & V_77 )
F_41 ( V_5 , & V_6 , 0 ) ;
for ( V_72 = 0 ; V_72 < V_69 -> V_78 ; V_72 ++ ) {
V_42 = F_42 ( V_70 ) - 1 ;
V_70 &= ~ ( 1 << V_42 ) ;
V_74 [ V_72 ] = F_35 ( V_5 , V_42 , & V_6 ) ;
}
if ( V_69 -> V_79 == V_80 )
V_71 = F_43 ( V_74 , V_69 -> V_78 , V_69 -> V_81 ) ;
else {
V_71 = V_74 [ 0 ] ;
V_71 = ( V_71 & V_69 -> V_82 ) ^ V_69 -> V_83 ;
V_71 = ( V_71 >> V_69 -> V_84 ) + V_69 -> V_85 ;
}
if ( V_69 -> V_86 )
V_71 %= V_69 -> V_86 ;
V_64 -> V_87 = 0 ;
V_64 -> V_71 = F_44 ( V_69 -> V_88 , V_69 -> V_88 + V_71 ) ;
V_73 = F_45 ( V_5 , & V_69 -> V_89 , V_64 ) ;
if ( V_73 < 0 )
continue;
return V_73 ;
}
return - 1 ;
}
static void F_46 ( unsigned long V_90 )
{
struct V_68 * V_69 = (struct V_68 * ) V_90 ;
F_47 ( & V_69 -> V_81 , 4 ) ;
if ( V_69 -> V_91 )
F_48 ( & V_69 -> V_92 , V_93 + V_69 -> V_91 ) ;
}
static void F_49 ( struct V_94 * V_66 )
{
struct V_68 * V_69 = F_50 ( V_66 , struct V_68 , V_95 ) ;
F_51 ( & V_69 -> V_92 ) ;
F_52 ( & V_69 -> V_89 ) ;
F_53 ( & V_69 -> V_76 ) ;
F_54 ( V_69 ) ;
}
static int F_55 ( struct V_96 * V_96 , struct V_4 * V_97 ,
struct V_61 * V_62 , unsigned long V_98 ,
T_1 V_99 , struct V_100 * * V_101 ,
unsigned long * V_90 , bool V_102 )
{
struct V_65 * V_66 = F_56 ( V_62 -> V_67 ) ;
struct V_68 * V_103 , * V_104 ;
struct V_100 * V_105 = V_101 [ V_106 ] ;
struct V_100 * V_107 [ V_108 + 1 ] ;
struct V_109 V_110 ;
struct V_111 V_112 ;
unsigned int V_78 = 0 ;
unsigned int V_91 = 0 ;
T_1 V_88 = 0 ;
T_1 V_70 = 0 ;
T_1 V_79 ;
int V_113 ;
if ( V_105 == NULL )
return - V_114 ;
V_113 = F_57 ( V_107 , V_108 , V_105 , V_115 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_107 [ V_116 ] ) {
V_88 = F_58 ( V_107 [ V_116 ] ) ;
if ( F_59 ( V_88 ) == 0 )
return - V_114 ;
}
if ( V_107 [ V_117 ] ) {
V_70 = F_58 ( V_107 [ V_117 ] ) ;
V_78 = F_60 ( V_70 ) ;
if ( V_78 == 0 )
return - V_114 ;
if ( F_61 ( V_70 ) - 1 > V_75 )
return - V_118 ;
if ( ( V_70 & ( V_57 | V_58 ) ) &&
F_62 ( F_63 ( V_97 ) . V_9 ) != & V_36 )
return - V_118 ;
}
V_113 = F_64 ( & V_110 , V_119 , V_120 ) ;
if ( V_113 < 0 )
goto V_121;
V_113 = F_65 ( V_96 , V_62 , V_107 , V_101 [ V_122 ] , & V_110 , V_102 ) ;
if ( V_113 < 0 )
goto V_121;
V_113 = F_66 ( V_62 , V_107 [ V_123 ] , & V_112 ) ;
if ( V_113 < 0 )
goto V_121;
V_113 = - V_124 ;
V_104 = F_67 ( sizeof( * V_104 ) , V_125 ) ;
if ( ! V_104 )
goto V_126;
V_113 = F_64 ( & V_104 -> V_89 , V_119 , V_120 ) ;
if ( V_113 < 0 )
goto V_127;
V_103 = (struct V_68 * ) * V_90 ;
if ( V_103 ) {
V_113 = - V_114 ;
if ( V_103 -> V_99 != V_99 && V_99 )
goto V_127;
V_104 -> V_62 = V_103 -> V_62 ;
V_104 -> V_99 = V_103 -> V_99 ;
V_104 -> V_78 = V_103 -> V_78 ;
V_104 -> V_70 = V_103 -> V_70 ;
V_104 -> V_79 = V_103 -> V_79 ;
V_104 -> V_82 = V_103 -> V_82 ;
V_104 -> V_83 = V_103 -> V_83 ;
V_104 -> V_84 = V_103 -> V_84 ;
V_104 -> V_85 = V_103 -> V_85 ;
V_104 -> V_86 = V_103 -> V_86 ;
V_104 -> V_88 = V_103 -> V_88 ;
V_104 -> V_81 = V_103 -> V_81 ;
V_79 = V_103 -> V_79 ;
if ( V_107 [ V_128 ] )
V_79 = F_58 ( V_107 [ V_128 ] ) ;
if ( V_79 != V_80 && V_78 > 1 )
goto V_127;
if ( V_79 == V_80 )
V_91 = V_103 -> V_91 ;
if ( V_107 [ V_129 ] ) {
if ( V_79 != V_80 )
goto V_127;
V_91 = F_58 ( V_107 [ V_129 ] ) * V_130 ;
}
} else {
V_113 = - V_114 ;
if ( ! V_99 )
goto V_127;
if ( ! V_107 [ V_117 ] )
goto V_127;
V_79 = V_131 ;
if ( V_107 [ V_128 ] )
V_79 = F_58 ( V_107 [ V_128 ] ) ;
if ( V_79 != V_80 && V_78 > 1 )
goto V_127;
if ( V_107 [ V_129 ] ) {
if ( V_79 != V_80 )
goto V_127;
V_91 = F_58 ( V_107 [ V_129 ] ) * V_130 ;
}
if ( F_68 ( V_88 ) == 0 )
V_88 = F_44 ( V_62 -> V_132 -> V_99 , V_88 ) ;
if ( F_59 ( V_88 ) == 0 )
V_88 = F_44 ( V_88 , 1 ) ;
V_104 -> V_99 = V_99 ;
V_104 -> V_82 = ~ 0U ;
V_104 -> V_62 = V_62 ;
F_47 ( & V_104 -> V_81 , 4 ) ;
}
V_104 -> V_92 . V_133 = F_46 ;
V_104 -> V_92 . V_134 = ( unsigned long ) V_104 ;
F_69 ( & V_104 -> V_92 ) ;
F_70 ( V_62 , & V_104 -> V_89 , & V_110 ) ;
F_71 ( V_62 , & V_104 -> V_76 , & V_112 ) ;
F_72 ( F_73 ( V_62 -> V_132 ) ) ;
if ( V_107 [ V_117 ] ) {
V_104 -> V_70 = V_70 ;
V_104 -> V_78 = V_78 ;
}
V_104 -> V_79 = V_79 ;
if ( V_107 [ V_135 ] )
V_104 -> V_82 = F_58 ( V_107 [ V_135 ] ) ;
if ( V_107 [ V_136 ] )
V_104 -> V_83 = F_58 ( V_107 [ V_136 ] ) ;
if ( V_107 [ V_137 ] )
V_104 -> V_84 = F_58 ( V_107 [ V_137 ] ) ;
if ( V_107 [ V_138 ] )
V_104 -> V_85 = F_58 ( V_107 [ V_138 ] ) ;
if ( V_107 [ V_139 ] )
V_104 -> V_86 = F_58 ( V_107 [ V_139 ] ) ;
if ( V_88 )
V_104 -> V_88 = V_88 ;
V_104 -> V_91 = V_91 ;
if ( V_91 )
F_48 ( & V_104 -> V_92 , V_93 + V_91 ) ;
if ( * V_90 == 0 )
F_74 ( & V_104 -> V_140 , & V_66 -> V_141 ) ;
else
F_75 ( & V_103 -> V_140 , & V_104 -> V_140 ) ;
* V_90 = ( unsigned long ) V_104 ;
if ( V_103 )
F_76 ( & V_103 -> V_95 , F_49 ) ;
return 0 ;
V_127:
F_52 ( & V_104 -> V_89 ) ;
V_126:
F_53 ( & V_112 ) ;
F_54 ( V_104 ) ;
V_121:
F_52 ( & V_110 ) ;
return V_113 ;
}
static int F_77 ( struct V_61 * V_62 , unsigned long V_90 )
{
struct V_68 * V_69 = (struct V_68 * ) V_90 ;
F_78 ( & V_69 -> V_140 ) ;
F_76 ( & V_69 -> V_95 , F_49 ) ;
return 0 ;
}
static int F_79 ( struct V_61 * V_62 )
{
struct V_65 * V_66 ;
V_66 = F_67 ( sizeof( * V_66 ) , V_125 ) ;
if ( V_66 == NULL )
return - V_124 ;
F_80 ( & V_66 -> V_141 ) ;
F_81 ( V_62 -> V_67 , V_66 ) ;
return 0 ;
}
static bool F_82 ( struct V_61 * V_62 , bool V_142 )
{
struct V_65 * V_66 = F_56 ( V_62 -> V_67 ) ;
struct V_68 * V_69 , * V_143 ;
if ( ! V_142 && ! F_83 ( & V_66 -> V_141 ) )
return false ;
F_84 (f, next, &head->filters, list) {
F_78 ( & V_69 -> V_140 ) ;
F_76 ( & V_69 -> V_95 , F_49 ) ;
}
F_85 ( V_66 , V_95 ) ;
return true ;
}
static unsigned long F_86 ( struct V_61 * V_62 , T_1 V_99 )
{
struct V_65 * V_66 = F_56 ( V_62 -> V_67 ) ;
struct V_68 * V_69 ;
F_87 (f, &head->filters, list)
if ( V_69 -> V_99 == V_99 )
return ( unsigned long ) V_69 ;
return 0 ;
}
static int F_88 ( struct V_96 * V_96 , struct V_61 * V_62 , unsigned long V_144 ,
struct V_4 * V_5 , struct V_145 * V_112 )
{
struct V_68 * V_69 = (struct V_68 * ) V_144 ;
struct V_100 * V_146 ;
if ( V_69 == NULL )
return V_5 -> V_147 ;
V_112 -> V_148 = V_69 -> V_99 ;
V_146 = F_89 ( V_5 , V_106 ) ;
if ( V_146 == NULL )
goto V_149;
if ( F_90 ( V_5 , V_117 , V_69 -> V_70 ) ||
F_90 ( V_5 , V_128 , V_69 -> V_79 ) )
goto V_149;
if ( V_69 -> V_82 != ~ 0 || V_69 -> V_83 != 0 ) {
if ( F_90 ( V_5 , V_135 , V_69 -> V_82 ) ||
F_90 ( V_5 , V_136 , V_69 -> V_83 ) )
goto V_149;
}
if ( V_69 -> V_84 &&
F_90 ( V_5 , V_137 , V_69 -> V_84 ) )
goto V_149;
if ( V_69 -> V_85 &&
F_90 ( V_5 , V_138 , V_69 -> V_85 ) )
goto V_149;
if ( V_69 -> V_86 &&
F_90 ( V_5 , V_139 , V_69 -> V_86 ) )
goto V_149;
if ( V_69 -> V_88 &&
F_90 ( V_5 , V_116 , V_69 -> V_88 ) )
goto V_149;
if ( V_69 -> V_91 &&
F_90 ( V_5 , V_129 , V_69 -> V_91 / V_130 ) )
goto V_149;
if ( F_91 ( V_5 , & V_69 -> V_89 ) < 0 )
goto V_149;
#ifdef F_92
if ( V_69 -> V_76 . V_150 . V_151 &&
F_93 ( V_5 , & V_69 -> V_76 , V_123 ) < 0 )
goto V_149;
#endif
F_94 ( V_5 , V_146 ) ;
if ( F_95 ( V_5 , & V_69 -> V_89 ) < 0 )
goto V_149;
return V_5 -> V_147 ;
V_149:
F_96 ( V_5 , V_146 ) ;
return - 1 ;
}
static void F_97 ( struct V_61 * V_62 , struct V_152 * V_90 )
{
struct V_65 * V_66 = F_56 ( V_62 -> V_67 ) ;
struct V_68 * V_69 ;
F_87 (f, &head->filters, list) {
if ( V_90 -> V_153 < V_90 -> V_154 )
goto V_154;
if ( V_90 -> V_155 ( V_62 , ( unsigned long ) V_69 , V_90 ) < 0 ) {
V_90 -> V_156 = 1 ;
break;
}
V_154:
V_90 -> V_153 ++ ;
}
}
static int T_5 F_98 ( void )
{
return F_99 ( & V_157 ) ;
}
static void T_6 F_100 ( void )
{
F_101 ( & V_157 ) ;
}
