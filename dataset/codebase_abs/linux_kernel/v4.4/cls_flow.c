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
static T_1 F_9 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
return V_7 -> V_13 . V_14 ;
}
static T_1 F_10 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
if ( V_7 -> V_15 . V_15 )
return F_11 ( V_7 -> V_15 . V_8 ) ;
return F_1 ( V_5 -> V_9 ) ;
}
static T_1 F_12 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
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
#if F_17 ( V_19 ) || F_17 ( V_20 )
return F_1 ( V_5 -> V_21 ) ;
#else
return 0 ;
#endif
}
static T_1 F_18 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
switch ( F_8 ( V_5 ) ) {
case F_19 ( V_22 ) :
return F_4 ( F_20 ( V_5 , V_8 . V_23 . V_24 ) ) ;
case F_19 ( V_25 ) :
return F_4 ( F_20 ( V_5 , V_8 . V_23 . V_26 [ 3 ] ) ) ;
}
V_27:
return F_2 ( V_5 , V_7 ) ;
}
static T_1 F_21 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
switch ( F_8 ( V_5 ) ) {
case F_19 ( V_22 ) :
return F_4 ( F_20 ( V_5 , V_10 . V_23 . V_24 ) ) ;
case F_19 ( V_25 ) :
return F_4 ( F_20 ( V_5 , V_10 . V_23 . V_26 [ 3 ] ) ) ;
}
V_27:
return F_5 ( V_5 , V_7 ) ;
}
static T_1 F_22 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
return F_11 ( F_20 ( V_5 , V_8 . V_28 . V_29 ) ) ;
V_27:
return F_10 ( V_5 , V_7 ) ;
}
static T_1 F_23 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
return F_11 ( F_20 ( V_5 , V_10 . V_28 . V_29 ) ) ;
V_27:
return F_12 ( V_5 , V_7 ) ;
}
static T_1 F_24 ( const struct V_4 * V_5 )
{
#ifdef F_25
if ( F_7 ( V_5 ) )
return F_7 ( V_5 ) -> V_30 ;
#endif
return 0 ;
}
static T_1 F_26 ( const struct V_4 * V_5 )
{
struct V_31 * V_9 = F_27 ( V_5 ) ;
if ( V_9 && V_9 -> V_32 && V_9 -> V_32 -> V_33 ) {
T_3 V_34 = V_9 -> V_32 -> V_33 -> V_35 -> V_36 ;
return F_28 ( & V_37 , V_34 ) ;
}
return 0 ;
}
static T_1 F_29 ( const struct V_4 * V_5 )
{
struct V_31 * V_9 = F_27 ( V_5 ) ;
if ( V_9 && V_9 -> V_32 && V_9 -> V_32 -> V_33 ) {
T_4 V_38 = V_9 -> V_32 -> V_33 -> V_35 -> V_39 ;
return F_30 ( & V_37 , V_38 ) ;
}
return 0 ;
}
static T_1 F_31 ( const struct V_4 * V_5 )
{
V_12 V_40 ( V_41 ) ;
if ( F_32 ( V_5 , & V_41 ) < 0 )
return 0 ;
return V_41 & V_42 ;
}
static T_1 F_33 ( struct V_4 * V_5 )
{
return F_34 ( V_5 ) ;
}
static T_1 F_35 ( struct V_4 * V_5 , int V_43 , struct V_6 * V_7 )
{
switch ( V_43 ) {
case V_44 :
return F_2 ( V_5 , V_7 ) ;
case V_45 :
return F_5 ( V_5 , V_7 ) ;
case V_46 :
return F_9 ( V_5 , V_7 ) ;
case V_47 :
return F_10 ( V_5 , V_7 ) ;
case V_48 :
return F_12 ( V_5 , V_7 ) ;
case V_49 :
return F_13 ( V_5 ) ;
case V_50 :
return F_14 ( V_5 ) ;
case V_51 :
return F_15 ( V_5 ) ;
case V_52 :
return F_16 ( V_5 ) ;
case V_53 :
return F_18 ( V_5 , V_7 ) ;
case V_54 :
return F_21 ( V_5 , V_7 ) ;
case V_55 :
return F_22 ( V_5 , V_7 ) ;
case V_56 :
return F_23 ( V_5 , V_7 ) ;
case V_57 :
return F_24 ( V_5 ) ;
case V_58 :
return F_26 ( V_5 ) ;
case V_59 :
return F_29 ( V_5 ) ;
case V_60 :
return F_31 ( V_5 ) ;
case V_61 :
return F_33 ( V_5 ) ;
default:
F_36 ( 1 ) ;
return 0 ;
}
}
static int F_37 ( struct V_4 * V_5 , const struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_66 * V_67 = F_38 ( V_63 -> V_68 ) ;
struct V_69 * V_70 ;
T_1 V_71 ;
T_1 V_72 ;
unsigned int V_73 , V_43 ;
int V_74 ;
F_39 (f, &head->filters, list) {
T_1 V_75 [ V_76 + 1 ] ;
struct V_6 V_6 ;
if ( ! F_40 ( V_5 , & V_70 -> V_77 , NULL ) )
continue;
V_71 = V_70 -> V_71 ;
if ( V_71 & V_78 )
F_41 ( V_5 , & V_6 , 0 ) ;
for ( V_73 = 0 ; V_73 < V_70 -> V_79 ; V_73 ++ ) {
V_43 = F_42 ( V_71 ) - 1 ;
V_71 &= ~ ( 1 << V_43 ) ;
V_75 [ V_73 ] = F_35 ( V_5 , V_43 , & V_6 ) ;
}
if ( V_70 -> V_80 == V_81 )
V_72 = F_43 ( V_75 , V_70 -> V_79 , V_70 -> V_82 ) ;
else {
V_72 = V_75 [ 0 ] ;
V_72 = ( V_72 & V_70 -> V_83 ) ^ V_70 -> V_84 ;
V_72 = ( V_72 >> V_70 -> V_85 ) + V_70 -> V_86 ;
}
if ( V_70 -> V_87 )
V_72 %= V_70 -> V_87 ;
V_65 -> V_88 = 0 ;
V_65 -> V_72 = F_44 ( V_70 -> V_89 , V_70 -> V_89 + V_72 ) ;
V_74 = F_45 ( V_5 , & V_70 -> V_90 , V_65 ) ;
if ( V_74 < 0 )
continue;
return V_74 ;
}
return - 1 ;
}
static void F_46 ( unsigned long V_91 )
{
struct V_69 * V_70 = (struct V_69 * ) V_91 ;
F_47 ( & V_70 -> V_82 , 4 ) ;
if ( V_70 -> V_92 )
F_48 ( & V_70 -> V_93 , V_94 + V_70 -> V_92 ) ;
}
static void F_49 ( struct V_95 * V_67 )
{
struct V_69 * V_70 = F_50 ( V_67 , struct V_69 , V_96 ) ;
F_51 ( & V_70 -> V_93 ) ;
F_52 ( & V_70 -> V_90 ) ;
F_53 ( & V_70 -> V_77 ) ;
F_54 ( V_70 ) ;
}
static int F_55 ( struct V_97 * V_97 , struct V_4 * V_98 ,
struct V_62 * V_63 , unsigned long V_99 ,
T_1 V_100 , struct V_101 * * V_102 ,
unsigned long * V_91 , bool V_103 )
{
struct V_66 * V_67 = F_56 ( V_63 -> V_68 ) ;
struct V_69 * V_104 , * V_105 ;
struct V_101 * V_106 = V_102 [ V_107 ] ;
struct V_101 * V_108 [ V_109 + 1 ] ;
struct V_110 V_111 ;
struct V_112 V_113 ;
unsigned int V_79 = 0 ;
unsigned int V_92 = 0 ;
T_1 V_89 = 0 ;
T_1 V_71 = 0 ;
T_1 V_80 ;
int V_114 ;
if ( V_106 == NULL )
return - V_115 ;
V_114 = F_57 ( V_108 , V_109 , V_106 , V_116 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( V_108 [ V_117 ] ) {
V_89 = F_58 ( V_108 [ V_117 ] ) ;
if ( F_59 ( V_89 ) == 0 )
return - V_115 ;
}
if ( V_108 [ V_118 ] ) {
V_71 = F_58 ( V_108 [ V_118 ] ) ;
V_79 = F_60 ( V_71 ) ;
if ( V_79 == 0 )
return - V_115 ;
if ( F_61 ( V_71 ) - 1 > V_76 )
return - V_119 ;
if ( ( V_71 & ( V_58 | V_59 ) ) &&
F_62 ( F_63 ( V_98 ) . V_9 ) != & V_37 )
return - V_119 ;
}
F_64 ( & V_111 , V_120 , V_121 ) ;
V_114 = F_65 ( V_97 , V_63 , V_108 , V_102 [ V_122 ] , & V_111 , V_103 ) ;
if ( V_114 < 0 )
return V_114 ;
V_114 = F_66 ( V_63 , V_108 [ V_123 ] , & V_113 ) ;
if ( V_114 < 0 )
goto V_124;
V_114 = - V_125 ;
V_105 = F_67 ( sizeof( * V_105 ) , V_126 ) ;
if ( ! V_105 )
goto V_127;
F_64 ( & V_105 -> V_90 , V_120 , V_121 ) ;
V_104 = (struct V_69 * ) * V_91 ;
if ( V_104 ) {
V_114 = - V_115 ;
if ( V_104 -> V_100 != V_100 && V_100 )
goto V_127;
V_105 -> V_63 = V_104 -> V_63 ;
V_105 -> V_100 = V_104 -> V_100 ;
V_105 -> V_79 = V_104 -> V_79 ;
V_105 -> V_71 = V_104 -> V_71 ;
V_105 -> V_80 = V_104 -> V_80 ;
V_105 -> V_83 = V_104 -> V_83 ;
V_105 -> V_84 = V_104 -> V_84 ;
V_105 -> V_85 = V_104 -> V_85 ;
V_105 -> V_86 = V_104 -> V_86 ;
V_105 -> V_87 = V_104 -> V_87 ;
V_105 -> V_89 = V_104 -> V_89 ;
V_105 -> V_82 = V_104 -> V_82 ;
V_80 = V_104 -> V_80 ;
if ( V_108 [ V_128 ] )
V_80 = F_58 ( V_108 [ V_128 ] ) ;
if ( V_80 != V_81 && V_79 > 1 )
goto V_127;
if ( V_80 == V_81 )
V_92 = V_104 -> V_92 ;
if ( V_108 [ V_129 ] ) {
if ( V_80 != V_81 )
goto V_127;
V_92 = F_58 ( V_108 [ V_129 ] ) * V_130 ;
}
} else {
V_114 = - V_115 ;
if ( ! V_100 )
goto V_127;
if ( ! V_108 [ V_118 ] )
goto V_127;
V_80 = V_131 ;
if ( V_108 [ V_128 ] )
V_80 = F_58 ( V_108 [ V_128 ] ) ;
if ( V_80 != V_81 && V_79 > 1 )
goto V_127;
if ( V_108 [ V_129 ] ) {
if ( V_80 != V_81 )
goto V_127;
V_92 = F_58 ( V_108 [ V_129 ] ) * V_130 ;
}
if ( F_68 ( V_89 ) == 0 )
V_89 = F_44 ( V_63 -> V_132 -> V_100 , V_89 ) ;
if ( F_59 ( V_89 ) == 0 )
V_89 = F_44 ( V_89 , 1 ) ;
V_105 -> V_100 = V_100 ;
V_105 -> V_83 = ~ 0U ;
V_105 -> V_63 = V_63 ;
F_47 ( & V_105 -> V_82 , 4 ) ;
}
V_105 -> V_93 . V_133 = F_46 ;
V_105 -> V_93 . V_134 = ( unsigned long ) V_105 ;
F_69 ( & V_105 -> V_93 ) ;
F_70 ( V_63 , & V_105 -> V_90 , & V_111 ) ;
F_71 ( V_63 , & V_105 -> V_77 , & V_113 ) ;
F_72 ( F_73 ( V_63 -> V_132 ) ) ;
if ( V_108 [ V_118 ] ) {
V_105 -> V_71 = V_71 ;
V_105 -> V_79 = V_79 ;
}
V_105 -> V_80 = V_80 ;
if ( V_108 [ V_135 ] )
V_105 -> V_83 = F_58 ( V_108 [ V_135 ] ) ;
if ( V_108 [ V_136 ] )
V_105 -> V_84 = F_58 ( V_108 [ V_136 ] ) ;
if ( V_108 [ V_137 ] )
V_105 -> V_85 = F_58 ( V_108 [ V_137 ] ) ;
if ( V_108 [ V_138 ] )
V_105 -> V_86 = F_58 ( V_108 [ V_138 ] ) ;
if ( V_108 [ V_139 ] )
V_105 -> V_87 = F_58 ( V_108 [ V_139 ] ) ;
if ( V_89 )
V_105 -> V_89 = V_89 ;
V_105 -> V_92 = V_92 ;
if ( V_92 )
F_48 ( & V_105 -> V_93 , V_94 + V_92 ) ;
if ( * V_91 == 0 )
F_74 ( & V_105 -> V_140 , & V_67 -> V_141 ) ;
else
F_75 ( & V_104 -> V_140 , & V_105 -> V_140 ) ;
* V_91 = ( unsigned long ) V_105 ;
if ( V_104 )
F_76 ( & V_104 -> V_96 , F_49 ) ;
return 0 ;
V_127:
F_53 ( & V_113 ) ;
F_54 ( V_105 ) ;
V_124:
F_52 ( & V_111 ) ;
return V_114 ;
}
static int F_77 ( struct V_62 * V_63 , unsigned long V_91 )
{
struct V_69 * V_70 = (struct V_69 * ) V_91 ;
F_78 ( & V_70 -> V_140 ) ;
F_76 ( & V_70 -> V_96 , F_49 ) ;
return 0 ;
}
static int F_79 ( struct V_62 * V_63 )
{
struct V_66 * V_67 ;
V_67 = F_67 ( sizeof( * V_67 ) , V_126 ) ;
if ( V_67 == NULL )
return - V_125 ;
F_80 ( & V_67 -> V_141 ) ;
F_81 ( V_63 -> V_68 , V_67 ) ;
return 0 ;
}
static bool F_82 ( struct V_62 * V_63 , bool V_142 )
{
struct V_66 * V_67 = F_56 ( V_63 -> V_68 ) ;
struct V_69 * V_70 , * V_143 ;
if ( ! V_142 && ! F_83 ( & V_67 -> V_141 ) )
return false ;
F_84 (f, next, &head->filters, list) {
F_78 ( & V_70 -> V_140 ) ;
F_76 ( & V_70 -> V_96 , F_49 ) ;
}
F_85 ( V_63 -> V_68 , NULL ) ;
F_86 ( V_67 , V_96 ) ;
return true ;
}
static unsigned long F_87 ( struct V_62 * V_63 , T_1 V_100 )
{
struct V_66 * V_67 = F_56 ( V_63 -> V_68 ) ;
struct V_69 * V_70 ;
F_88 (f, &head->filters, list)
if ( V_70 -> V_100 == V_100 )
return ( unsigned long ) V_70 ;
return 0 ;
}
static int F_89 ( struct V_97 * V_97 , struct V_62 * V_63 , unsigned long V_144 ,
struct V_4 * V_5 , struct V_145 * V_113 )
{
struct V_69 * V_70 = (struct V_69 * ) V_144 ;
struct V_101 * V_146 ;
if ( V_70 == NULL )
return V_5 -> V_147 ;
V_113 -> V_148 = V_70 -> V_100 ;
V_146 = F_90 ( V_5 , V_107 ) ;
if ( V_146 == NULL )
goto V_149;
if ( F_91 ( V_5 , V_118 , V_70 -> V_71 ) ||
F_91 ( V_5 , V_128 , V_70 -> V_80 ) )
goto V_149;
if ( V_70 -> V_83 != ~ 0 || V_70 -> V_84 != 0 ) {
if ( F_91 ( V_5 , V_135 , V_70 -> V_83 ) ||
F_91 ( V_5 , V_136 , V_70 -> V_84 ) )
goto V_149;
}
if ( V_70 -> V_85 &&
F_91 ( V_5 , V_137 , V_70 -> V_85 ) )
goto V_149;
if ( V_70 -> V_86 &&
F_91 ( V_5 , V_138 , V_70 -> V_86 ) )
goto V_149;
if ( V_70 -> V_87 &&
F_91 ( V_5 , V_139 , V_70 -> V_87 ) )
goto V_149;
if ( V_70 -> V_89 &&
F_91 ( V_5 , V_117 , V_70 -> V_89 ) )
goto V_149;
if ( V_70 -> V_92 &&
F_91 ( V_5 , V_129 , V_70 -> V_92 / V_130 ) )
goto V_149;
if ( F_92 ( V_5 , & V_70 -> V_90 ) < 0 )
goto V_149;
#ifdef F_93
if ( V_70 -> V_77 . V_150 . V_151 &&
F_94 ( V_5 , & V_70 -> V_77 , V_123 ) < 0 )
goto V_149;
#endif
F_95 ( V_5 , V_146 ) ;
if ( F_96 ( V_5 , & V_70 -> V_90 ) < 0 )
goto V_149;
return V_5 -> V_147 ;
V_149:
F_97 ( V_5 , V_146 ) ;
return - 1 ;
}
static void F_98 ( struct V_62 * V_63 , struct V_152 * V_91 )
{
struct V_66 * V_67 = F_56 ( V_63 -> V_68 ) ;
struct V_69 * V_70 ;
F_88 (f, &head->filters, list) {
if ( V_91 -> V_153 < V_91 -> V_154 )
goto V_154;
if ( V_91 -> V_155 ( V_63 , ( unsigned long ) V_70 , V_91 ) < 0 ) {
V_91 -> V_156 = 1 ;
break;
}
V_154:
V_91 -> V_153 ++ ;
}
}
static int T_5 F_99 ( void )
{
return F_100 ( & V_157 ) ;
}
static void T_6 F_101 ( void )
{
F_102 ( & V_157 ) ;
}
