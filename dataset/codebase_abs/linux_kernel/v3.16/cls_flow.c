static inline T_1 F_1 ( void * V_1 )
{
unsigned long V_2 = ( unsigned long ) V_1 ;
return ( V_2 & 0xFFFFFFFF ) ^ ( V_3 > 32 ? V_2 >> 32 : 0 ) ;
}
static T_1 F_2 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
if ( V_7 -> V_8 )
return F_3 ( V_7 -> V_8 ) ;
return F_1 ( V_5 -> V_9 ) ;
}
static T_1 F_4 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
if ( V_7 -> V_10 )
return F_3 ( V_7 -> V_10 ) ;
return F_1 ( F_5 ( V_5 ) ) ^ ( V_11 V_12 ) V_5 -> V_13 ;
}
static T_1 F_6 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
return V_7 -> V_14 ;
}
static T_1 F_7 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
if ( V_7 -> V_15 )
return F_8 ( V_7 -> V_16 [ 0 ] ) ;
return F_1 ( V_5 -> V_9 ) ;
}
static T_1 F_9 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
if ( V_7 -> V_15 )
return F_8 ( V_7 -> V_16 [ 1 ] ) ;
return F_1 ( F_5 ( V_5 ) ) ^ ( V_11 V_12 ) V_5 -> V_13 ;
}
static T_1 F_10 ( const struct V_4 * V_5 )
{
return V_5 -> V_17 ;
}
static T_1 F_11 ( const struct V_4 * V_5 )
{
return V_5 -> V_18 ;
}
static T_1 F_12 ( const struct V_4 * V_5 )
{
return V_5 -> V_19 ;
}
static T_1 F_13 ( const struct V_4 * V_5 )
{
#if F_14 ( V_20 ) || F_14 ( V_21 )
return F_1 ( V_5 -> V_22 ) ;
#else
return 0 ;
#endif
}
static T_1 F_15 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
switch ( V_5 -> V_13 ) {
case F_16 ( V_23 ) :
return F_3 ( F_17 ( V_5 , V_8 . V_24 . V_25 ) ) ;
case F_16 ( V_26 ) :
return F_3 ( F_17 ( V_5 , V_8 . V_24 . V_27 [ 3 ] ) ) ;
}
V_28:
return F_2 ( V_5 , V_7 ) ;
}
static T_1 F_18 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
switch ( V_5 -> V_13 ) {
case F_16 ( V_23 ) :
return F_3 ( F_17 ( V_5 , V_10 . V_24 . V_25 ) ) ;
case F_16 ( V_26 ) :
return F_3 ( F_17 ( V_5 , V_10 . V_24 . V_27 [ 3 ] ) ) ;
}
V_28:
return F_4 ( V_5 , V_7 ) ;
}
static T_1 F_19 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
return F_8 ( F_17 ( V_5 , V_8 . V_29 . V_30 ) ) ;
V_28:
return F_7 ( V_5 , V_7 ) ;
}
static T_1 F_20 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
return F_8 ( F_17 ( V_5 , V_10 . V_29 . V_30 ) ) ;
V_28:
return F_9 ( V_5 , V_7 ) ;
}
static T_1 F_21 ( const struct V_4 * V_5 )
{
#ifdef F_22
if ( F_5 ( V_5 ) )
return F_5 ( V_5 ) -> V_31 ;
#endif
return 0 ;
}
static T_1 F_23 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_9 && V_5 -> V_9 -> V_32 && V_5 -> V_9 -> V_32 -> V_33 ) {
T_2 V_34 = V_5 -> V_9 -> V_32 -> V_33 -> V_35 -> V_36 ;
return F_24 ( & V_37 , V_34 ) ;
}
return 0 ;
}
static T_1 F_25 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_9 && V_5 -> V_9 -> V_32 && V_5 -> V_9 -> V_32 -> V_33 ) {
T_3 V_38 = V_5 -> V_9 -> V_32 -> V_33 -> V_35 -> V_39 ;
return F_26 ( & V_37 , V_38 ) ;
}
return 0 ;
}
static T_1 F_27 ( const struct V_4 * V_5 )
{
V_12 V_40 ( V_41 ) ;
if ( F_28 ( V_5 , & V_41 ) < 0 )
return 0 ;
return V_41 & V_42 ;
}
static T_1 F_29 ( struct V_4 * V_5 )
{
return F_30 ( V_5 ) ;
}
static T_1 F_31 ( struct V_4 * V_5 , int V_43 , struct V_6 * V_7 )
{
switch ( V_43 ) {
case V_44 :
return F_2 ( V_5 , V_7 ) ;
case V_45 :
return F_4 ( V_5 , V_7 ) ;
case V_46 :
return F_6 ( V_5 , V_7 ) ;
case V_47 :
return F_7 ( V_5 , V_7 ) ;
case V_48 :
return F_9 ( V_5 , V_7 ) ;
case V_49 :
return F_10 ( V_5 ) ;
case V_50 :
return F_11 ( V_5 ) ;
case V_51 :
return F_12 ( V_5 ) ;
case V_52 :
return F_13 ( V_5 ) ;
case V_53 :
return F_15 ( V_5 , V_7 ) ;
case V_54 :
return F_18 ( V_5 , V_7 ) ;
case V_55 :
return F_19 ( V_5 , V_7 ) ;
case V_56 :
return F_20 ( V_5 , V_7 ) ;
case V_57 :
return F_21 ( V_5 ) ;
case V_58 :
return F_23 ( V_5 ) ;
case V_59 :
return F_25 ( V_5 ) ;
case V_60 :
return F_27 ( V_5 ) ;
case V_61 :
return F_29 ( V_5 ) ;
default:
F_32 ( 1 ) ;
return 0 ;
}
}
static int F_33 ( struct V_4 * V_5 , const struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_66 * V_67 = V_63 -> V_68 ;
struct V_69 * V_70 ;
T_1 V_71 ;
T_1 V_72 ;
unsigned int V_73 , V_43 ;
int V_74 ;
F_34 (f, &head->filters, list) {
T_1 V_75 [ V_76 + 1 ] ;
struct V_6 V_6 ;
if ( ! F_35 ( V_5 , & V_70 -> V_77 , NULL ) )
continue;
V_71 = V_70 -> V_71 ;
if ( V_71 & V_78 )
F_36 ( V_5 , & V_6 ) ;
for ( V_73 = 0 ; V_73 < V_70 -> V_79 ; V_73 ++ ) {
V_43 = F_37 ( V_71 ) - 1 ;
V_71 &= ~ ( 1 << V_43 ) ;
V_75 [ V_73 ] = F_31 ( V_5 , V_43 , & V_6 ) ;
}
if ( V_70 -> V_80 == V_81 )
V_72 = F_38 ( V_75 , V_70 -> V_79 , V_70 -> V_82 ) ;
else {
V_72 = V_75 [ 0 ] ;
V_72 = ( V_72 & V_70 -> V_83 ) ^ V_70 -> V_84 ;
V_72 = ( V_72 >> V_70 -> V_85 ) + V_70 -> V_86 ;
}
if ( V_70 -> V_87 )
V_72 %= V_70 -> V_87 ;
V_65 -> V_88 = 0 ;
V_65 -> V_72 = F_39 ( V_70 -> V_89 , V_70 -> V_89 + V_72 ) ;
V_74 = F_40 ( V_5 , & V_70 -> V_90 , V_65 ) ;
if ( V_74 < 0 )
continue;
return V_74 ;
}
return - 1 ;
}
static void F_41 ( unsigned long V_91 )
{
struct V_69 * V_70 = (struct V_69 * ) V_91 ;
F_42 ( & V_70 -> V_82 , 4 ) ;
if ( V_70 -> V_92 )
F_43 ( & V_70 -> V_93 , V_94 + V_70 -> V_92 ) ;
}
static int F_44 ( struct V_95 * V_95 , struct V_4 * V_96 ,
struct V_62 * V_63 , unsigned long V_97 ,
T_1 V_98 , struct V_99 * * V_100 ,
unsigned long * V_91 , bool V_101 )
{
struct V_66 * V_67 = V_63 -> V_68 ;
struct V_69 * V_70 ;
struct V_99 * V_102 = V_100 [ V_103 ] ;
struct V_99 * V_104 [ V_105 + 1 ] ;
struct V_106 V_107 ;
struct V_108 V_109 ;
unsigned int V_79 = 0 ;
unsigned int V_92 = 0 ;
T_1 V_89 = 0 ;
T_1 V_71 = 0 ;
T_1 V_80 ;
int V_110 ;
if ( V_102 == NULL )
return - V_111 ;
V_110 = F_45 ( V_104 , V_105 , V_102 , V_112 ) ;
if ( V_110 < 0 )
return V_110 ;
if ( V_104 [ V_113 ] ) {
V_89 = F_46 ( V_104 [ V_113 ] ) ;
if ( F_47 ( V_89 ) == 0 )
return - V_111 ;
}
if ( V_104 [ V_114 ] ) {
V_71 = F_46 ( V_104 [ V_114 ] ) ;
V_79 = F_48 ( V_71 ) ;
if ( V_79 == 0 )
return - V_111 ;
if ( F_49 ( V_71 ) - 1 > V_76 )
return - V_115 ;
if ( ( V_71 & ( V_58 | V_59 ) ) &&
F_50 ( F_51 ( V_96 ) . V_9 ) != & V_37 )
return - V_115 ;
}
F_52 ( & V_107 , V_116 , V_117 ) ;
V_110 = F_53 ( V_95 , V_63 , V_104 , V_100 [ V_118 ] , & V_107 , V_101 ) ;
if ( V_110 < 0 )
return V_110 ;
V_110 = F_54 ( V_63 , V_104 [ V_119 ] , & V_109 ) ;
if ( V_110 < 0 )
goto V_120;
V_70 = (struct V_69 * ) * V_91 ;
if ( V_70 != NULL ) {
V_110 = - V_111 ;
if ( V_70 -> V_98 != V_98 && V_98 )
goto V_121;
V_80 = V_70 -> V_80 ;
if ( V_104 [ V_122 ] )
V_80 = F_46 ( V_104 [ V_122 ] ) ;
if ( V_80 != V_81 && V_79 > 1 )
goto V_121;
if ( V_80 == V_81 )
V_92 = V_70 -> V_92 ;
if ( V_104 [ V_123 ] ) {
if ( V_80 != V_81 )
goto V_121;
V_92 = F_46 ( V_104 [ V_123 ] ) * V_124 ;
}
} else {
V_110 = - V_111 ;
if ( ! V_98 )
goto V_121;
if ( ! V_104 [ V_114 ] )
goto V_121;
V_80 = V_125 ;
if ( V_104 [ V_122 ] )
V_80 = F_46 ( V_104 [ V_122 ] ) ;
if ( V_80 != V_81 && V_79 > 1 )
goto V_121;
if ( V_104 [ V_123 ] ) {
if ( V_80 != V_81 )
goto V_121;
V_92 = F_46 ( V_104 [ V_123 ] ) * V_124 ;
}
if ( F_55 ( V_89 ) == 0 )
V_89 = F_39 ( V_63 -> V_126 -> V_98 , V_89 ) ;
if ( F_47 ( V_89 ) == 0 )
V_89 = F_39 ( V_89 , 1 ) ;
V_110 = - V_127 ;
V_70 = F_56 ( sizeof( * V_70 ) , V_128 ) ;
if ( V_70 == NULL )
goto V_121;
V_70 -> V_98 = V_98 ;
V_70 -> V_83 = ~ 0U ;
F_52 ( & V_70 -> V_90 , V_116 , V_117 ) ;
F_42 ( & V_70 -> V_82 , 4 ) ;
V_70 -> V_93 . V_129 = F_41 ;
V_70 -> V_93 . V_130 = ( unsigned long ) V_70 ;
F_57 ( & V_70 -> V_93 ) ;
}
F_58 ( V_63 , & V_70 -> V_90 , & V_107 ) ;
F_59 ( V_63 , & V_70 -> V_77 , & V_109 ) ;
F_60 ( V_63 ) ;
if ( V_104 [ V_114 ] ) {
V_70 -> V_71 = V_71 ;
V_70 -> V_79 = V_79 ;
}
V_70 -> V_80 = V_80 ;
if ( V_104 [ V_131 ] )
V_70 -> V_83 = F_46 ( V_104 [ V_131 ] ) ;
if ( V_104 [ V_132 ] )
V_70 -> V_84 = F_46 ( V_104 [ V_132 ] ) ;
if ( V_104 [ V_133 ] )
V_70 -> V_85 = F_46 ( V_104 [ V_133 ] ) ;
if ( V_104 [ V_134 ] )
V_70 -> V_86 = F_46 ( V_104 [ V_134 ] ) ;
if ( V_104 [ V_135 ] )
V_70 -> V_87 = F_46 ( V_104 [ V_135 ] ) ;
if ( V_89 )
V_70 -> V_89 = V_89 ;
V_70 -> V_92 = V_92 ;
F_61 ( & V_70 -> V_93 ) ;
if ( V_92 )
F_43 ( & V_70 -> V_93 , V_94 + V_92 ) ;
if ( * V_91 == 0 )
F_62 ( & V_70 -> V_136 , & V_67 -> V_137 ) ;
F_63 ( V_63 ) ;
* V_91 = ( unsigned long ) V_70 ;
return 0 ;
V_121:
F_64 ( V_63 , & V_109 ) ;
V_120:
F_65 ( V_63 , & V_107 ) ;
return V_110 ;
}
static void F_66 ( struct V_62 * V_63 , struct V_69 * V_70 )
{
F_67 ( & V_70 -> V_93 ) ;
F_65 ( V_63 , & V_70 -> V_90 ) ;
F_64 ( V_63 , & V_70 -> V_77 ) ;
F_68 ( V_70 ) ;
}
static int F_69 ( struct V_62 * V_63 , unsigned long V_91 )
{
struct V_69 * V_70 = (struct V_69 * ) V_91 ;
F_60 ( V_63 ) ;
F_70 ( & V_70 -> V_136 ) ;
F_63 ( V_63 ) ;
F_66 ( V_63 , V_70 ) ;
return 0 ;
}
static int F_71 ( struct V_62 * V_63 )
{
struct V_66 * V_67 ;
V_67 = F_56 ( sizeof( * V_67 ) , V_128 ) ;
if ( V_67 == NULL )
return - V_127 ;
F_72 ( & V_67 -> V_137 ) ;
V_63 -> V_68 = V_67 ;
return 0 ;
}
static void F_73 ( struct V_62 * V_63 )
{
struct V_66 * V_67 = V_63 -> V_68 ;
struct V_69 * V_70 , * V_138 ;
F_74 (f, next, &head->filters, list) {
F_70 ( & V_70 -> V_136 ) ;
F_66 ( V_63 , V_70 ) ;
}
F_68 ( V_67 ) ;
}
static unsigned long F_75 ( struct V_62 * V_63 , T_1 V_98 )
{
struct V_66 * V_67 = V_63 -> V_68 ;
struct V_69 * V_70 ;
F_34 (f, &head->filters, list)
if ( V_70 -> V_98 == V_98 )
return ( unsigned long ) V_70 ;
return 0 ;
}
static void F_76 ( struct V_62 * V_63 , unsigned long V_70 )
{
}
static int F_77 ( struct V_95 * V_95 , struct V_62 * V_63 , unsigned long V_139 ,
struct V_4 * V_5 , struct V_140 * V_109 )
{
struct V_69 * V_70 = (struct V_69 * ) V_139 ;
struct V_99 * V_141 ;
if ( V_70 == NULL )
return V_5 -> V_142 ;
V_109 -> V_143 = V_70 -> V_98 ;
V_141 = F_78 ( V_5 , V_103 ) ;
if ( V_141 == NULL )
goto V_144;
if ( F_79 ( V_5 , V_114 , V_70 -> V_71 ) ||
F_79 ( V_5 , V_122 , V_70 -> V_80 ) )
goto V_144;
if ( V_70 -> V_83 != ~ 0 || V_70 -> V_84 != 0 ) {
if ( F_79 ( V_5 , V_131 , V_70 -> V_83 ) ||
F_79 ( V_5 , V_132 , V_70 -> V_84 ) )
goto V_144;
}
if ( V_70 -> V_85 &&
F_79 ( V_5 , V_133 , V_70 -> V_85 ) )
goto V_144;
if ( V_70 -> V_86 &&
F_79 ( V_5 , V_134 , V_70 -> V_86 ) )
goto V_144;
if ( V_70 -> V_87 &&
F_79 ( V_5 , V_135 , V_70 -> V_87 ) )
goto V_144;
if ( V_70 -> V_89 &&
F_79 ( V_5 , V_113 , V_70 -> V_89 ) )
goto V_144;
if ( V_70 -> V_92 &&
F_79 ( V_5 , V_123 , V_70 -> V_92 / V_124 ) )
goto V_144;
if ( F_80 ( V_5 , & V_70 -> V_90 ) < 0 )
goto V_144;
#ifdef F_81
if ( V_70 -> V_77 . V_145 . V_146 &&
F_82 ( V_5 , & V_70 -> V_77 , V_119 ) < 0 )
goto V_144;
#endif
F_83 ( V_5 , V_141 ) ;
if ( F_84 ( V_5 , & V_70 -> V_90 ) < 0 )
goto V_144;
return V_5 -> V_142 ;
V_144:
F_85 ( V_5 , V_141 ) ;
return - 1 ;
}
static void F_86 ( struct V_62 * V_63 , struct V_147 * V_91 )
{
struct V_66 * V_67 = V_63 -> V_68 ;
struct V_69 * V_70 ;
F_34 (f, &head->filters, list) {
if ( V_91 -> V_148 < V_91 -> V_149 )
goto V_149;
if ( V_91 -> V_150 ( V_63 , ( unsigned long ) V_70 , V_91 ) < 0 ) {
V_91 -> V_151 = 1 ;
break;
}
V_149:
V_91 -> V_148 ++ ;
}
}
static int T_4 F_87 ( void )
{
return F_88 ( & V_152 ) ;
}
static void T_5 F_89 ( void )
{
F_90 ( & V_152 ) ;
}
