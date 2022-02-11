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
static void F_50 ( struct V_67 * V_68 )
{
F_51 ( & V_68 -> V_91 ) ;
F_52 ( & V_68 -> V_88 ) ;
F_53 ( & V_68 -> V_75 ) ;
F_54 ( & V_68 -> V_88 ) ;
F_55 ( V_68 ) ;
}
static void F_56 ( struct V_93 * V_94 )
{
struct V_67 * V_68 = F_57 ( V_94 , struct V_67 , V_94 ) ;
F_58 () ;
F_50 ( V_68 ) ;
F_59 () ;
}
static void F_60 ( struct V_95 * V_65 )
{
struct V_67 * V_68 = F_57 ( V_65 , struct V_67 , V_96 ) ;
F_61 ( & V_68 -> V_94 , F_56 ) ;
F_62 ( & V_68 -> V_94 ) ;
}
static int F_63 ( struct V_97 * V_97 , struct V_4 * V_98 ,
struct V_60 * V_61 , unsigned long V_99 ,
T_1 V_100 , struct V_101 * * V_102 ,
void * * V_89 , bool V_103 )
{
struct V_64 * V_65 = F_64 ( V_61 -> V_66 ) ;
struct V_67 * V_104 , * V_105 ;
struct V_101 * V_106 = V_102 [ V_107 ] ;
struct V_101 * V_108 [ V_109 + 1 ] ;
unsigned int V_77 = 0 ;
unsigned int V_90 = 0 ;
T_1 V_87 = 0 ;
T_1 V_69 = 0 ;
T_1 V_78 ;
int V_110 ;
if ( V_106 == NULL )
return - V_111 ;
V_110 = F_65 ( V_108 , V_109 , V_106 , V_112 , NULL ) ;
if ( V_110 < 0 )
return V_110 ;
if ( V_108 [ V_113 ] ) {
V_87 = F_66 ( V_108 [ V_113 ] ) ;
if ( F_67 ( V_87 ) == 0 )
return - V_111 ;
}
if ( V_108 [ V_114 ] ) {
V_69 = F_66 ( V_108 [ V_114 ] ) ;
V_77 = F_68 ( V_69 ) ;
if ( V_77 == 0 )
return - V_111 ;
if ( F_69 ( V_69 ) - 1 > V_74 )
return - V_115 ;
if ( ( V_69 & ( V_56 | V_57 ) ) &&
F_70 ( F_71 ( V_98 ) . V_9 ) != & V_35 )
return - V_115 ;
}
V_105 = F_72 ( sizeof( * V_105 ) , V_116 ) ;
if ( ! V_105 )
return - V_117 ;
V_110 = F_73 ( V_61 , V_108 [ V_118 ] , & V_105 -> V_75 ) ;
if ( V_110 < 0 )
goto V_119;
V_110 = F_74 ( & V_105 -> V_88 , V_120 , V_121 ) ;
if ( V_110 < 0 )
goto V_122;
V_110 = F_75 ( V_97 , V_61 , V_108 , V_102 [ V_123 ] , & V_105 -> V_88 , V_103 ) ;
if ( V_110 < 0 )
goto V_122;
V_104 = * V_89 ;
if ( V_104 ) {
V_110 = - V_111 ;
if ( V_104 -> V_100 != V_100 && V_100 )
goto V_122;
V_105 -> V_61 = V_104 -> V_61 ;
V_105 -> V_100 = V_104 -> V_100 ;
V_105 -> V_77 = V_104 -> V_77 ;
V_105 -> V_69 = V_104 -> V_69 ;
V_105 -> V_78 = V_104 -> V_78 ;
V_105 -> V_81 = V_104 -> V_81 ;
V_105 -> V_82 = V_104 -> V_82 ;
V_105 -> V_83 = V_104 -> V_83 ;
V_105 -> V_84 = V_104 -> V_84 ;
V_105 -> V_85 = V_104 -> V_85 ;
V_105 -> V_87 = V_104 -> V_87 ;
V_105 -> V_80 = V_104 -> V_80 ;
V_78 = V_104 -> V_78 ;
if ( V_108 [ V_124 ] )
V_78 = F_66 ( V_108 [ V_124 ] ) ;
if ( V_78 != V_79 && V_77 > 1 )
goto V_122;
if ( V_78 == V_79 )
V_90 = V_104 -> V_90 ;
if ( V_108 [ V_125 ] ) {
if ( V_78 != V_79 )
goto V_122;
V_90 = F_66 ( V_108 [ V_125 ] ) * V_126 ;
}
} else {
V_110 = - V_111 ;
if ( ! V_100 )
goto V_122;
if ( ! V_108 [ V_114 ] )
goto V_122;
V_78 = V_127 ;
if ( V_108 [ V_124 ] )
V_78 = F_66 ( V_108 [ V_124 ] ) ;
if ( V_78 != V_79 && V_77 > 1 )
goto V_122;
if ( V_108 [ V_125 ] ) {
if ( V_78 != V_79 )
goto V_122;
V_90 = F_66 ( V_108 [ V_125 ] ) * V_126 ;
}
if ( F_76 ( V_87 ) == 0 )
V_87 = F_45 ( V_61 -> V_128 -> V_100 , V_87 ) ;
if ( F_67 ( V_87 ) == 0 )
V_87 = F_45 ( V_87 , 1 ) ;
V_105 -> V_100 = V_100 ;
V_105 -> V_81 = ~ 0U ;
V_105 -> V_61 = V_61 ;
F_48 ( & V_105 -> V_80 , 4 ) ;
}
F_77 ( & V_105 -> V_91 , F_47 ,
( unsigned long ) V_105 ) ;
F_78 ( F_79 ( V_61 -> V_128 ) ) ;
if ( V_108 [ V_114 ] ) {
V_105 -> V_69 = V_69 ;
V_105 -> V_77 = V_77 ;
}
V_105 -> V_78 = V_78 ;
if ( V_108 [ V_129 ] )
V_105 -> V_81 = F_66 ( V_108 [ V_129 ] ) ;
if ( V_108 [ V_130 ] )
V_105 -> V_82 = F_66 ( V_108 [ V_130 ] ) ;
if ( V_108 [ V_131 ] )
V_105 -> V_83 = F_66 ( V_108 [ V_131 ] ) ;
if ( V_108 [ V_132 ] )
V_105 -> V_84 = F_66 ( V_108 [ V_132 ] ) ;
if ( V_108 [ V_133 ] )
V_105 -> V_85 = F_66 ( V_108 [ V_133 ] ) ;
if ( V_87 )
V_105 -> V_87 = V_87 ;
V_105 -> V_90 = V_90 ;
if ( V_90 )
F_49 ( & V_105 -> V_91 , V_92 + V_90 ) ;
if ( ! * V_89 )
F_80 ( & V_105 -> V_134 , & V_65 -> V_135 ) ;
else
F_81 ( & V_104 -> V_134 , & V_105 -> V_134 ) ;
* V_89 = V_105 ;
if ( V_104 ) {
F_82 ( & V_104 -> V_88 ) ;
F_83 ( & V_104 -> V_96 , F_60 ) ;
}
return 0 ;
V_122:
F_52 ( & V_105 -> V_88 ) ;
F_53 ( & V_105 -> V_75 ) ;
V_119:
F_55 ( V_105 ) ;
return V_110 ;
}
static int F_84 ( struct V_60 * V_61 , void * V_89 , bool * V_136 )
{
struct V_64 * V_65 = F_64 ( V_61 -> V_66 ) ;
struct V_67 * V_68 = V_89 ;
F_85 ( & V_68 -> V_134 ) ;
F_82 ( & V_68 -> V_88 ) ;
F_83 ( & V_68 -> V_96 , F_60 ) ;
* V_136 = F_86 ( & V_65 -> V_135 ) ;
return 0 ;
}
static int F_87 ( struct V_60 * V_61 )
{
struct V_64 * V_65 ;
V_65 = F_72 ( sizeof( * V_65 ) , V_116 ) ;
if ( V_65 == NULL )
return - V_117 ;
F_88 ( & V_65 -> V_135 ) ;
F_89 ( V_61 -> V_66 , V_65 ) ;
return 0 ;
}
static void F_90 ( struct V_60 * V_61 )
{
struct V_64 * V_65 = F_64 ( V_61 -> V_66 ) ;
struct V_67 * V_68 , * V_137 ;
F_91 (f, next, &head->filters, list) {
F_85 ( & V_68 -> V_134 ) ;
if ( F_82 ( & V_68 -> V_88 ) )
F_83 ( & V_68 -> V_96 , F_60 ) ;
else
F_50 ( V_68 ) ;
}
F_92 ( V_65 , V_96 ) ;
}
static void * F_93 ( struct V_60 * V_61 , T_1 V_100 )
{
struct V_64 * V_65 = F_64 ( V_61 -> V_66 ) ;
struct V_67 * V_68 ;
F_94 (f, &head->filters, list)
if ( V_68 -> V_100 == V_100 )
return V_68 ;
return NULL ;
}
static int F_95 ( struct V_97 * V_97 , struct V_60 * V_61 , void * V_138 ,
struct V_4 * V_5 , struct V_139 * V_140 )
{
struct V_67 * V_68 = V_138 ;
struct V_101 * V_141 ;
if ( V_68 == NULL )
return V_5 -> V_142 ;
V_140 -> V_143 = V_68 -> V_100 ;
V_141 = F_96 ( V_5 , V_107 ) ;
if ( V_141 == NULL )
goto V_144;
if ( F_97 ( V_5 , V_114 , V_68 -> V_69 ) ||
F_97 ( V_5 , V_124 , V_68 -> V_78 ) )
goto V_144;
if ( V_68 -> V_81 != ~ 0 || V_68 -> V_82 != 0 ) {
if ( F_97 ( V_5 , V_129 , V_68 -> V_81 ) ||
F_97 ( V_5 , V_130 , V_68 -> V_82 ) )
goto V_144;
}
if ( V_68 -> V_83 &&
F_97 ( V_5 , V_131 , V_68 -> V_83 ) )
goto V_144;
if ( V_68 -> V_84 &&
F_97 ( V_5 , V_132 , V_68 -> V_84 ) )
goto V_144;
if ( V_68 -> V_85 &&
F_97 ( V_5 , V_133 , V_68 -> V_85 ) )
goto V_144;
if ( V_68 -> V_87 &&
F_97 ( V_5 , V_113 , V_68 -> V_87 ) )
goto V_144;
if ( V_68 -> V_90 &&
F_97 ( V_5 , V_125 , V_68 -> V_90 / V_126 ) )
goto V_144;
if ( F_98 ( V_5 , & V_68 -> V_88 ) < 0 )
goto V_144;
#ifdef F_99
if ( V_68 -> V_75 . V_145 . V_146 &&
F_100 ( V_5 , & V_68 -> V_75 , V_118 ) < 0 )
goto V_144;
#endif
F_101 ( V_5 , V_141 ) ;
if ( F_102 ( V_5 , & V_68 -> V_88 ) < 0 )
goto V_144;
return V_5 -> V_142 ;
V_144:
F_103 ( V_5 , V_141 ) ;
return - 1 ;
}
static void F_104 ( struct V_60 * V_61 , struct V_147 * V_89 )
{
struct V_64 * V_65 = F_64 ( V_61 -> V_66 ) ;
struct V_67 * V_68 ;
F_94 (f, &head->filters, list) {
if ( V_89 -> V_148 < V_89 -> V_149 )
goto V_149;
if ( V_89 -> V_150 ( V_61 , V_68 , V_89 ) < 0 ) {
V_89 -> V_151 = 1 ;
break;
}
V_149:
V_89 -> V_148 ++ ;
}
}
static int T_5 F_105 ( void )
{
return F_106 ( & V_152 ) ;
}
static void T_6 F_107 ( void )
{
F_108 ( & V_152 ) ;
}
