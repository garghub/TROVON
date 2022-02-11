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
if ( V_5 -> V_9 && V_5 -> V_9 -> V_32 && V_5 -> V_9 -> V_32 -> V_33 )
return V_5 -> V_9 -> V_32 -> V_33 -> V_34 -> V_35 ;
return 0 ;
}
static T_1 F_24 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_9 && V_5 -> V_9 -> V_32 && V_5 -> V_9 -> V_32 -> V_33 )
return V_5 -> V_9 -> V_32 -> V_33 -> V_34 -> V_36 ;
return 0 ;
}
static T_1 F_25 ( const struct V_4 * V_5 )
{
V_12 V_37 ( V_38 ) ;
if ( F_26 ( V_5 , & V_38 ) < 0 )
return 0 ;
return V_38 & V_39 ;
}
static T_1 F_27 ( struct V_4 * V_5 )
{
return F_28 ( V_5 ) ;
}
static T_1 F_29 ( struct V_4 * V_5 , int V_40 , struct V_6 * V_7 )
{
switch ( V_40 ) {
case V_41 :
return F_2 ( V_5 , V_7 ) ;
case V_42 :
return F_4 ( V_5 , V_7 ) ;
case V_43 :
return F_6 ( V_5 , V_7 ) ;
case V_44 :
return F_7 ( V_5 , V_7 ) ;
case V_45 :
return F_9 ( V_5 , V_7 ) ;
case V_46 :
return F_10 ( V_5 ) ;
case V_47 :
return F_11 ( V_5 ) ;
case V_48 :
return F_12 ( V_5 ) ;
case V_49 :
return F_13 ( V_5 ) ;
case V_50 :
return F_15 ( V_5 , V_7 ) ;
case V_51 :
return F_18 ( V_5 , V_7 ) ;
case V_52 :
return F_19 ( V_5 , V_7 ) ;
case V_53 :
return F_20 ( V_5 , V_7 ) ;
case V_54 :
return F_21 ( V_5 ) ;
case V_55 :
return F_23 ( V_5 ) ;
case V_56 :
return F_24 ( V_5 ) ;
case V_57 :
return F_25 ( V_5 ) ;
case V_58 :
return F_27 ( V_5 ) ;
default:
F_30 ( 1 ) ;
return 0 ;
}
}
static int F_31 ( struct V_4 * V_5 , const struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = V_60 -> V_65 ;
struct V_66 * V_67 ;
T_1 V_68 ;
T_1 V_69 ;
unsigned int V_70 , V_40 ;
int V_71 ;
F_32 (f, &head->filters, list) {
T_1 V_72 [ V_73 + 1 ] ;
struct V_6 V_6 ;
if ( ! F_33 ( V_5 , & V_67 -> V_74 , NULL ) )
continue;
V_68 = V_67 -> V_68 ;
if ( V_68 & V_75 )
F_34 ( V_5 , & V_6 ) ;
for ( V_70 = 0 ; V_70 < V_67 -> V_76 ; V_70 ++ ) {
V_40 = F_35 ( V_68 ) - 1 ;
V_68 &= ~ ( 1 << V_40 ) ;
V_72 [ V_70 ] = F_29 ( V_5 , V_40 , & V_6 ) ;
}
if ( V_67 -> V_77 == V_78 )
V_69 = F_36 ( V_72 , V_67 -> V_76 , V_67 -> V_79 ) ;
else {
V_69 = V_72 [ 0 ] ;
V_69 = ( V_69 & V_67 -> V_80 ) ^ V_67 -> V_81 ;
V_69 = ( V_69 >> V_67 -> V_82 ) + V_67 -> V_83 ;
}
if ( V_67 -> V_84 )
V_69 %= V_67 -> V_84 ;
V_62 -> V_85 = 0 ;
V_62 -> V_69 = F_37 ( V_67 -> V_86 , V_67 -> V_86 + V_69 ) ;
V_71 = F_38 ( V_5 , & V_67 -> V_87 , V_62 ) ;
if ( V_71 < 0 )
continue;
return V_71 ;
}
return - 1 ;
}
static void F_39 ( unsigned long V_88 )
{
struct V_66 * V_67 = (struct V_66 * ) V_88 ;
F_40 ( & V_67 -> V_79 , 4 ) ;
if ( V_67 -> V_89 )
F_41 ( & V_67 -> V_90 , V_91 + V_67 -> V_89 ) ;
}
static int F_42 ( struct V_59 * V_60 , unsigned long V_92 ,
T_1 V_93 , struct V_94 * * V_95 ,
unsigned long * V_88 )
{
struct V_63 * V_64 = V_60 -> V_65 ;
struct V_66 * V_67 ;
struct V_94 * V_96 = V_95 [ V_97 ] ;
struct V_94 * V_98 [ V_99 + 1 ] ;
struct V_100 V_101 ;
struct V_102 V_103 ;
unsigned int V_76 = 0 ;
unsigned int V_89 = 0 ;
T_1 V_86 = 0 ;
T_1 V_68 = 0 ;
T_1 V_77 ;
int V_104 ;
if ( V_96 == NULL )
return - V_105 ;
V_104 = F_43 ( V_98 , V_99 , V_96 , V_106 ) ;
if ( V_104 < 0 )
return V_104 ;
if ( V_98 [ V_107 ] ) {
V_86 = F_44 ( V_98 [ V_107 ] ) ;
if ( F_45 ( V_86 ) == 0 )
return - V_105 ;
}
if ( V_98 [ V_108 ] ) {
V_68 = F_44 ( V_98 [ V_108 ] ) ;
V_76 = F_46 ( V_68 ) ;
if ( V_76 == 0 )
return - V_105 ;
if ( F_47 ( V_68 ) - 1 > V_73 )
return - V_109 ;
}
V_104 = F_48 ( V_60 , V_98 , V_95 [ V_110 ] , & V_101 , & V_111 ) ;
if ( V_104 < 0 )
return V_104 ;
V_104 = F_49 ( V_60 , V_98 [ V_112 ] , & V_103 ) ;
if ( V_104 < 0 )
goto V_113;
V_67 = (struct V_66 * ) * V_88 ;
if ( V_67 != NULL ) {
V_104 = - V_105 ;
if ( V_67 -> V_93 != V_93 && V_93 )
goto V_114;
V_77 = V_67 -> V_77 ;
if ( V_98 [ V_115 ] )
V_77 = F_44 ( V_98 [ V_115 ] ) ;
if ( V_77 != V_78 && V_76 > 1 )
goto V_114;
if ( V_77 == V_78 )
V_89 = V_67 -> V_89 ;
if ( V_98 [ V_116 ] ) {
if ( V_77 != V_78 )
goto V_114;
V_89 = F_44 ( V_98 [ V_116 ] ) * V_117 ;
}
} else {
V_104 = - V_105 ;
if ( ! V_93 )
goto V_114;
if ( ! V_98 [ V_108 ] )
goto V_114;
V_77 = V_118 ;
if ( V_98 [ V_115 ] )
V_77 = F_44 ( V_98 [ V_115 ] ) ;
if ( V_77 != V_78 && V_76 > 1 )
goto V_114;
if ( V_98 [ V_116 ] ) {
if ( V_77 != V_78 )
goto V_114;
V_89 = F_44 ( V_98 [ V_116 ] ) * V_117 ;
}
if ( F_50 ( V_86 ) == 0 )
V_86 = F_37 ( V_60 -> V_119 -> V_93 , V_86 ) ;
if ( F_45 ( V_86 ) == 0 )
V_86 = F_37 ( V_86 , 1 ) ;
V_104 = - V_120 ;
V_67 = F_51 ( sizeof( * V_67 ) , V_121 ) ;
if ( V_67 == NULL )
goto V_114;
V_67 -> V_93 = V_93 ;
V_67 -> V_80 = ~ 0U ;
F_40 ( & V_67 -> V_79 , 4 ) ;
V_67 -> V_90 . V_122 = F_39 ;
V_67 -> V_90 . V_123 = ( unsigned long ) V_67 ;
F_52 ( & V_67 -> V_90 ) ;
}
F_53 ( V_60 , & V_67 -> V_87 , & V_101 ) ;
F_54 ( V_60 , & V_67 -> V_74 , & V_103 ) ;
F_55 ( V_60 ) ;
if ( V_98 [ V_108 ] ) {
V_67 -> V_68 = V_68 ;
V_67 -> V_76 = V_76 ;
}
V_67 -> V_77 = V_77 ;
if ( V_98 [ V_124 ] )
V_67 -> V_80 = F_44 ( V_98 [ V_124 ] ) ;
if ( V_98 [ V_125 ] )
V_67 -> V_81 = F_44 ( V_98 [ V_125 ] ) ;
if ( V_98 [ V_126 ] )
V_67 -> V_82 = F_44 ( V_98 [ V_126 ] ) ;
if ( V_98 [ V_127 ] )
V_67 -> V_83 = F_44 ( V_98 [ V_127 ] ) ;
if ( V_98 [ V_128 ] )
V_67 -> V_84 = F_44 ( V_98 [ V_128 ] ) ;
if ( V_86 )
V_67 -> V_86 = V_86 ;
V_67 -> V_89 = V_89 ;
F_56 ( & V_67 -> V_90 ) ;
if ( V_89 )
F_41 ( & V_67 -> V_90 , V_91 + V_89 ) ;
if ( * V_88 == 0 )
F_57 ( & V_67 -> V_129 , & V_64 -> V_130 ) ;
F_58 ( V_60 ) ;
* V_88 = ( unsigned long ) V_67 ;
return 0 ;
V_114:
F_59 ( V_60 , & V_103 ) ;
V_113:
F_60 ( V_60 , & V_101 ) ;
return V_104 ;
}
static void F_61 ( struct V_59 * V_60 , struct V_66 * V_67 )
{
F_62 ( & V_67 -> V_90 ) ;
F_60 ( V_60 , & V_67 -> V_87 ) ;
F_59 ( V_60 , & V_67 -> V_74 ) ;
F_63 ( V_67 ) ;
}
static int F_64 ( struct V_59 * V_60 , unsigned long V_88 )
{
struct V_66 * V_67 = (struct V_66 * ) V_88 ;
F_55 ( V_60 ) ;
F_65 ( & V_67 -> V_129 ) ;
F_58 ( V_60 ) ;
F_61 ( V_60 , V_67 ) ;
return 0 ;
}
static int F_66 ( struct V_59 * V_60 )
{
struct V_63 * V_64 ;
V_64 = F_51 ( sizeof( * V_64 ) , V_121 ) ;
if ( V_64 == NULL )
return - V_120 ;
F_67 ( & V_64 -> V_130 ) ;
V_60 -> V_65 = V_64 ;
return 0 ;
}
static void F_68 ( struct V_59 * V_60 )
{
struct V_63 * V_64 = V_60 -> V_65 ;
struct V_66 * V_67 , * V_131 ;
F_69 (f, next, &head->filters, list) {
F_65 ( & V_67 -> V_129 ) ;
F_61 ( V_60 , V_67 ) ;
}
F_63 ( V_64 ) ;
}
static unsigned long F_70 ( struct V_59 * V_60 , T_1 V_93 )
{
struct V_63 * V_64 = V_60 -> V_65 ;
struct V_66 * V_67 ;
F_32 (f, &head->filters, list)
if ( V_67 -> V_93 == V_93 )
return ( unsigned long ) V_67 ;
return 0 ;
}
static void F_71 ( struct V_59 * V_60 , unsigned long V_67 )
{
}
static int F_72 ( struct V_59 * V_60 , unsigned long V_132 ,
struct V_4 * V_5 , struct V_133 * V_103 )
{
struct V_66 * V_67 = (struct V_66 * ) V_132 ;
struct V_94 * V_134 ;
if ( V_67 == NULL )
return V_5 -> V_135 ;
V_103 -> V_136 = V_67 -> V_93 ;
V_134 = F_73 ( V_5 , V_97 ) ;
if ( V_134 == NULL )
goto V_137;
if ( F_74 ( V_5 , V_108 , V_67 -> V_68 ) ||
F_74 ( V_5 , V_115 , V_67 -> V_77 ) )
goto V_137;
if ( V_67 -> V_80 != ~ 0 || V_67 -> V_81 != 0 ) {
if ( F_74 ( V_5 , V_124 , V_67 -> V_80 ) ||
F_74 ( V_5 , V_125 , V_67 -> V_81 ) )
goto V_137;
}
if ( V_67 -> V_82 &&
F_74 ( V_5 , V_126 , V_67 -> V_82 ) )
goto V_137;
if ( V_67 -> V_83 &&
F_74 ( V_5 , V_127 , V_67 -> V_83 ) )
goto V_137;
if ( V_67 -> V_84 &&
F_74 ( V_5 , V_128 , V_67 -> V_84 ) )
goto V_137;
if ( V_67 -> V_86 &&
F_74 ( V_5 , V_107 , V_67 -> V_86 ) )
goto V_137;
if ( V_67 -> V_89 &&
F_74 ( V_5 , V_116 , V_67 -> V_89 / V_117 ) )
goto V_137;
if ( F_75 ( V_5 , & V_67 -> V_87 , & V_111 ) < 0 )
goto V_137;
#ifdef F_76
if ( V_67 -> V_74 . V_138 . V_139 &&
F_77 ( V_5 , & V_67 -> V_74 , V_112 ) < 0 )
goto V_137;
#endif
F_78 ( V_5 , V_134 ) ;
if ( F_79 ( V_5 , & V_67 -> V_87 , & V_111 ) < 0 )
goto V_137;
return V_5 -> V_135 ;
V_137:
F_80 ( V_5 , V_134 ) ;
return - 1 ;
}
static void F_81 ( struct V_59 * V_60 , struct V_140 * V_88 )
{
struct V_63 * V_64 = V_60 -> V_65 ;
struct V_66 * V_67 ;
F_32 (f, &head->filters, list) {
if ( V_88 -> V_141 < V_88 -> V_142 )
goto V_142;
if ( V_88 -> V_143 ( V_60 , ( unsigned long ) V_67 , V_88 ) < 0 ) {
V_88 -> V_144 = 1 ;
break;
}
V_142:
V_88 -> V_141 ++ ;
}
}
static int T_2 F_82 ( void )
{
return F_83 ( & V_145 ) ;
}
static void T_3 F_84 ( void )
{
F_85 ( & V_145 ) ;
}
