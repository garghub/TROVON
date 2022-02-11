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
return F_1 ( F_18 ( V_5 ) ) ;
#else
return 0 ;
#endif
}
static T_1 F_19 ( const struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
switch ( F_8 ( V_5 ) ) {
case F_20 ( V_20 ) :
return F_4 ( F_21 ( V_5 , V_8 . V_21 . V_22 ) ) ;
case F_20 ( V_23 ) :
return F_4 ( F_21 ( V_5 , V_8 . V_21 . V_24 [ 3 ] ) ) ;
}
V_25:
return F_2 ( V_5 , V_7 ) ;
}
static T_1 F_22 ( const struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
switch ( F_8 ( V_5 ) ) {
case F_20 ( V_20 ) :
return F_4 ( F_21 ( V_5 , V_10 . V_21 . V_22 ) ) ;
case F_20 ( V_23 ) :
return F_4 ( F_21 ( V_5 , V_10 . V_21 . V_24 [ 3 ] ) ) ;
}
V_25:
return F_5 ( V_5 , V_7 ) ;
}
static T_1 F_23 ( const struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
return F_11 ( F_21 ( V_5 , V_8 . V_26 . V_27 ) ) ;
V_25:
return F_10 ( V_5 , V_7 ) ;
}
static T_1 F_24 ( const struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
return F_11 ( F_21 ( V_5 , V_10 . V_26 . V_27 ) ) ;
V_25:
return F_12 ( V_5 , V_7 ) ;
}
static T_1 F_25 ( const struct V_4 * V_5 )
{
#ifdef F_26
if ( F_7 ( V_5 ) )
return F_7 ( V_5 ) -> V_28 ;
#endif
return 0 ;
}
static T_1 F_27 ( const struct V_4 * V_5 )
{
struct V_29 * V_9 = F_28 ( V_5 ) ;
if ( V_9 && V_9 -> V_30 && V_9 -> V_30 -> V_31 ) {
T_3 V_32 = V_9 -> V_30 -> V_31 -> V_33 -> V_34 ;
return F_29 ( & V_35 , V_32 ) ;
}
return 0 ;
}
static T_1 F_30 ( const struct V_4 * V_5 )
{
struct V_29 * V_9 = F_28 ( V_5 ) ;
if ( V_9 && V_9 -> V_30 && V_9 -> V_30 -> V_31 ) {
T_4 V_36 = V_9 -> V_30 -> V_31 -> V_33 -> V_37 ;
return F_31 ( & V_35 , V_36 ) ;
}
return 0 ;
}
static T_1 F_32 ( const struct V_4 * V_5 )
{
V_12 V_38 ( V_39 ) ;
if ( F_33 ( V_5 , & V_39 ) < 0 )
return 0 ;
return V_39 & V_40 ;
}
static T_1 F_34 ( struct V_4 * V_5 )
{
return F_35 ( V_5 ) ;
}
static T_1 F_36 ( struct V_4 * V_5 , int V_41 , struct V_6 * V_7 )
{
switch ( V_41 ) {
case V_42 :
return F_2 ( V_5 , V_7 ) ;
case V_43 :
return F_5 ( V_5 , V_7 ) ;
case V_44 :
return F_9 ( V_5 , V_7 ) ;
case V_45 :
return F_10 ( V_5 , V_7 ) ;
case V_46 :
return F_12 ( V_5 , V_7 ) ;
case V_47 :
return F_13 ( V_5 ) ;
case V_48 :
return F_14 ( V_5 ) ;
case V_49 :
return F_15 ( V_5 ) ;
case V_50 :
return F_16 ( V_5 ) ;
case V_51 :
return F_19 ( V_5 , V_7 ) ;
case V_52 :
return F_22 ( V_5 , V_7 ) ;
case V_53 :
return F_23 ( V_5 , V_7 ) ;
case V_54 :
return F_24 ( V_5 , V_7 ) ;
case V_55 :
return F_25 ( V_5 ) ;
case V_56 :
return F_27 ( V_5 ) ;
case V_57 :
return F_30 ( V_5 ) ;
case V_58 :
return F_32 ( V_5 ) ;
case V_59 :
return F_34 ( V_5 ) ;
default:
F_37 ( 1 ) ;
return 0 ;
}
}
static int F_38 ( struct V_4 * V_5 , const struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 = F_39 ( V_61 -> V_66 ) ;
struct V_67 * V_68 ;
T_1 V_69 ;
T_1 V_70 ;
unsigned int V_71 , V_41 ;
int V_72 ;
F_40 (f, &head->filters, list) {
T_1 V_73 [ V_74 + 1 ] ;
struct V_6 V_6 ;
if ( ! F_41 ( V_5 , & V_68 -> V_75 , NULL ) )
continue;
V_69 = V_68 -> V_69 ;
if ( V_69 & V_76 )
F_42 ( V_5 , & V_6 , 0 ) ;
for ( V_71 = 0 ; V_71 < V_68 -> V_77 ; V_71 ++ ) {
V_41 = F_43 ( V_69 ) - 1 ;
V_69 &= ~ ( 1 << V_41 ) ;
V_73 [ V_71 ] = F_36 ( V_5 , V_41 , & V_6 ) ;
}
if ( V_68 -> V_78 == V_79 )
V_70 = F_44 ( V_73 , V_68 -> V_77 , V_68 -> V_80 ) ;
else {
V_70 = V_73 [ 0 ] ;
V_70 = ( V_70 & V_68 -> V_81 ) ^ V_68 -> V_82 ;
V_70 = ( V_70 >> V_68 -> V_83 ) + V_68 -> V_84 ;
}
if ( V_68 -> V_85 )
V_70 %= V_68 -> V_85 ;
V_63 -> V_86 = 0 ;
V_63 -> V_70 = F_45 ( V_68 -> V_87 , V_68 -> V_87 + V_70 ) ;
V_72 = F_46 ( V_5 , & V_68 -> V_88 , V_63 ) ;
if ( V_72 < 0 )
continue;
return V_72 ;
}
return - 1 ;
}
static void F_47 ( unsigned long V_89 )
{
struct V_67 * V_68 = (struct V_67 * ) V_89 ;
F_48 ( & V_68 -> V_80 , 4 ) ;
if ( V_68 -> V_90 )
F_49 ( & V_68 -> V_91 , V_92 + V_68 -> V_90 ) ;
}
static void F_50 ( struct V_93 * V_65 )
{
struct V_67 * V_68 = F_51 ( V_65 , struct V_67 , V_94 ) ;
F_52 ( & V_68 -> V_91 ) ;
F_53 ( & V_68 -> V_88 ) ;
F_54 ( & V_68 -> V_75 ) ;
F_55 ( V_68 ) ;
}
static int F_56 ( struct V_95 * V_95 , struct V_4 * V_96 ,
struct V_60 * V_61 , unsigned long V_97 ,
T_1 V_98 , struct V_99 * * V_100 ,
unsigned long * V_89 , bool V_101 )
{
struct V_64 * V_65 = F_57 ( V_61 -> V_66 ) ;
struct V_67 * V_102 , * V_103 ;
struct V_99 * V_104 = V_100 [ V_105 ] ;
struct V_99 * V_106 [ V_107 + 1 ] ;
struct V_108 V_109 ;
struct V_110 V_111 ;
unsigned int V_77 = 0 ;
unsigned int V_90 = 0 ;
T_1 V_87 = 0 ;
T_1 V_69 = 0 ;
T_1 V_78 ;
int V_112 ;
if ( V_104 == NULL )
return - V_113 ;
V_112 = F_58 ( V_106 , V_107 , V_104 , V_114 , NULL ) ;
if ( V_112 < 0 )
return V_112 ;
if ( V_106 [ V_115 ] ) {
V_87 = F_59 ( V_106 [ V_115 ] ) ;
if ( F_60 ( V_87 ) == 0 )
return - V_113 ;
}
if ( V_106 [ V_116 ] ) {
V_69 = F_59 ( V_106 [ V_116 ] ) ;
V_77 = F_61 ( V_69 ) ;
if ( V_77 == 0 )
return - V_113 ;
if ( F_62 ( V_69 ) - 1 > V_74 )
return - V_117 ;
if ( ( V_69 & ( V_56 | V_57 ) ) &&
F_63 ( F_64 ( V_96 ) . V_9 ) != & V_35 )
return - V_117 ;
}
V_112 = F_65 ( & V_109 , V_118 , V_119 ) ;
if ( V_112 < 0 )
goto V_120;
V_112 = F_66 ( V_95 , V_61 , V_106 , V_100 [ V_121 ] , & V_109 , V_101 ) ;
if ( V_112 < 0 )
goto V_120;
V_112 = F_67 ( V_61 , V_106 [ V_122 ] , & V_111 ) ;
if ( V_112 < 0 )
goto V_120;
V_112 = - V_123 ;
V_103 = F_68 ( sizeof( * V_103 ) , V_124 ) ;
if ( ! V_103 )
goto V_125;
V_112 = F_65 ( & V_103 -> V_88 , V_118 , V_119 ) ;
if ( V_112 < 0 )
goto V_126;
V_102 = (struct V_67 * ) * V_89 ;
if ( V_102 ) {
V_112 = - V_113 ;
if ( V_102 -> V_98 != V_98 && V_98 )
goto V_126;
V_103 -> V_61 = V_102 -> V_61 ;
V_103 -> V_98 = V_102 -> V_98 ;
V_103 -> V_77 = V_102 -> V_77 ;
V_103 -> V_69 = V_102 -> V_69 ;
V_103 -> V_78 = V_102 -> V_78 ;
V_103 -> V_81 = V_102 -> V_81 ;
V_103 -> V_82 = V_102 -> V_82 ;
V_103 -> V_83 = V_102 -> V_83 ;
V_103 -> V_84 = V_102 -> V_84 ;
V_103 -> V_85 = V_102 -> V_85 ;
V_103 -> V_87 = V_102 -> V_87 ;
V_103 -> V_80 = V_102 -> V_80 ;
V_78 = V_102 -> V_78 ;
if ( V_106 [ V_127 ] )
V_78 = F_59 ( V_106 [ V_127 ] ) ;
if ( V_78 != V_79 && V_77 > 1 )
goto V_126;
if ( V_78 == V_79 )
V_90 = V_102 -> V_90 ;
if ( V_106 [ V_128 ] ) {
if ( V_78 != V_79 )
goto V_126;
V_90 = F_59 ( V_106 [ V_128 ] ) * V_129 ;
}
} else {
V_112 = - V_113 ;
if ( ! V_98 )
goto V_126;
if ( ! V_106 [ V_116 ] )
goto V_126;
V_78 = V_130 ;
if ( V_106 [ V_127 ] )
V_78 = F_59 ( V_106 [ V_127 ] ) ;
if ( V_78 != V_79 && V_77 > 1 )
goto V_126;
if ( V_106 [ V_128 ] ) {
if ( V_78 != V_79 )
goto V_126;
V_90 = F_59 ( V_106 [ V_128 ] ) * V_129 ;
}
if ( F_69 ( V_87 ) == 0 )
V_87 = F_45 ( V_61 -> V_131 -> V_98 , V_87 ) ;
if ( F_60 ( V_87 ) == 0 )
V_87 = F_45 ( V_87 , 1 ) ;
V_103 -> V_98 = V_98 ;
V_103 -> V_81 = ~ 0U ;
V_103 -> V_61 = V_61 ;
F_48 ( & V_103 -> V_80 , 4 ) ;
}
F_70 ( & V_103 -> V_91 , F_47 ,
( unsigned long ) V_103 ) ;
F_71 ( V_61 , & V_103 -> V_88 , & V_109 ) ;
F_72 ( V_61 , & V_103 -> V_75 , & V_111 ) ;
F_73 ( F_74 ( V_61 -> V_131 ) ) ;
if ( V_106 [ V_116 ] ) {
V_103 -> V_69 = V_69 ;
V_103 -> V_77 = V_77 ;
}
V_103 -> V_78 = V_78 ;
if ( V_106 [ V_132 ] )
V_103 -> V_81 = F_59 ( V_106 [ V_132 ] ) ;
if ( V_106 [ V_133 ] )
V_103 -> V_82 = F_59 ( V_106 [ V_133 ] ) ;
if ( V_106 [ V_134 ] )
V_103 -> V_83 = F_59 ( V_106 [ V_134 ] ) ;
if ( V_106 [ V_135 ] )
V_103 -> V_84 = F_59 ( V_106 [ V_135 ] ) ;
if ( V_106 [ V_136 ] )
V_103 -> V_85 = F_59 ( V_106 [ V_136 ] ) ;
if ( V_87 )
V_103 -> V_87 = V_87 ;
V_103 -> V_90 = V_90 ;
if ( V_90 )
F_49 ( & V_103 -> V_91 , V_92 + V_90 ) ;
if ( * V_89 == 0 )
F_75 ( & V_103 -> V_137 , & V_65 -> V_138 ) ;
else
F_76 ( & V_102 -> V_137 , & V_103 -> V_137 ) ;
* V_89 = ( unsigned long ) V_103 ;
if ( V_102 )
F_77 ( & V_102 -> V_94 , F_50 ) ;
return 0 ;
V_126:
F_53 ( & V_103 -> V_88 ) ;
V_125:
F_54 ( & V_111 ) ;
F_55 ( V_103 ) ;
V_120:
F_53 ( & V_109 ) ;
return V_112 ;
}
static int F_78 ( struct V_60 * V_61 , unsigned long V_89 , bool * V_139 )
{
struct V_64 * V_65 = F_57 ( V_61 -> V_66 ) ;
struct V_67 * V_68 = (struct V_67 * ) V_89 ;
F_79 ( & V_68 -> V_137 ) ;
F_77 ( & V_68 -> V_94 , F_50 ) ;
* V_139 = F_80 ( & V_65 -> V_138 ) ;
return 0 ;
}
static int F_81 ( struct V_60 * V_61 )
{
struct V_64 * V_65 ;
V_65 = F_68 ( sizeof( * V_65 ) , V_124 ) ;
if ( V_65 == NULL )
return - V_123 ;
F_82 ( & V_65 -> V_138 ) ;
F_83 ( V_61 -> V_66 , V_65 ) ;
return 0 ;
}
static void F_84 ( struct V_60 * V_61 )
{
struct V_64 * V_65 = F_57 ( V_61 -> V_66 ) ;
struct V_67 * V_68 , * V_140 ;
F_85 (f, next, &head->filters, list) {
F_79 ( & V_68 -> V_137 ) ;
F_77 ( & V_68 -> V_94 , F_50 ) ;
}
F_86 ( V_65 , V_94 ) ;
}
static unsigned long F_87 ( struct V_60 * V_61 , T_1 V_98 )
{
struct V_64 * V_65 = F_57 ( V_61 -> V_66 ) ;
struct V_67 * V_68 ;
F_88 (f, &head->filters, list)
if ( V_68 -> V_98 == V_98 )
return ( unsigned long ) V_68 ;
return 0 ;
}
static int F_89 ( struct V_95 * V_95 , struct V_60 * V_61 , unsigned long V_141 ,
struct V_4 * V_5 , struct V_142 * V_111 )
{
struct V_67 * V_68 = (struct V_67 * ) V_141 ;
struct V_99 * V_143 ;
if ( V_68 == NULL )
return V_5 -> V_144 ;
V_111 -> V_145 = V_68 -> V_98 ;
V_143 = F_90 ( V_5 , V_105 ) ;
if ( V_143 == NULL )
goto V_146;
if ( F_91 ( V_5 , V_116 , V_68 -> V_69 ) ||
F_91 ( V_5 , V_127 , V_68 -> V_78 ) )
goto V_146;
if ( V_68 -> V_81 != ~ 0 || V_68 -> V_82 != 0 ) {
if ( F_91 ( V_5 , V_132 , V_68 -> V_81 ) ||
F_91 ( V_5 , V_133 , V_68 -> V_82 ) )
goto V_146;
}
if ( V_68 -> V_83 &&
F_91 ( V_5 , V_134 , V_68 -> V_83 ) )
goto V_146;
if ( V_68 -> V_84 &&
F_91 ( V_5 , V_135 , V_68 -> V_84 ) )
goto V_146;
if ( V_68 -> V_85 &&
F_91 ( V_5 , V_136 , V_68 -> V_85 ) )
goto V_146;
if ( V_68 -> V_87 &&
F_91 ( V_5 , V_115 , V_68 -> V_87 ) )
goto V_146;
if ( V_68 -> V_90 &&
F_91 ( V_5 , V_128 , V_68 -> V_90 / V_129 ) )
goto V_146;
if ( F_92 ( V_5 , & V_68 -> V_88 ) < 0 )
goto V_146;
#ifdef F_93
if ( V_68 -> V_75 . V_147 . V_148 &&
F_94 ( V_5 , & V_68 -> V_75 , V_122 ) < 0 )
goto V_146;
#endif
F_95 ( V_5 , V_143 ) ;
if ( F_96 ( V_5 , & V_68 -> V_88 ) < 0 )
goto V_146;
return V_5 -> V_144 ;
V_146:
F_97 ( V_5 , V_143 ) ;
return - 1 ;
}
static void F_98 ( struct V_60 * V_61 , struct V_149 * V_89 )
{
struct V_64 * V_65 = F_57 ( V_61 -> V_66 ) ;
struct V_67 * V_68 ;
F_88 (f, &head->filters, list) {
if ( V_89 -> V_150 < V_89 -> V_151 )
goto V_151;
if ( V_89 -> V_152 ( V_61 , ( unsigned long ) V_68 , V_89 ) < 0 ) {
V_89 -> V_153 = 1 ;
break;
}
V_151:
V_89 -> V_150 ++ ;
}
}
static int T_5 F_99 ( void )
{
return F_100 ( & V_154 ) ;
}
static void T_6 F_101 ( void )
{
F_102 ( & V_154 ) ;
}
