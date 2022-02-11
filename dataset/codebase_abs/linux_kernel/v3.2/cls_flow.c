static inline T_1 F_1 ( void * V_1 )
{
unsigned long V_2 = ( unsigned long ) V_1 ;
return ( V_2 & 0xFFFFFFFF ) ^ ( V_3 > 32 ? V_2 >> 32 : 0 ) ;
}
static T_1 F_2 ( const struct V_4 * V_5 , int V_6 )
{
T_2 * V_7 = NULL , V_8 ;
switch ( V_5 -> V_9 ) {
case F_3 ( V_10 ) :
V_7 = F_4 ( V_5 ,
V_6 + F_5 ( struct V_11 ,
V_12 ) ,
4 , & V_8 ) ;
break;
case F_3 ( V_13 ) :
V_7 = F_4 ( V_5 ,
V_6 + F_5 ( struct V_14 ,
V_12 . V_15 [ 3 ] ) ,
4 , & V_8 ) ;
break;
}
if ( V_7 )
return F_6 ( * V_7 ) ;
return F_1 ( V_5 -> V_16 ) ;
}
static T_1 F_7 ( const struct V_4 * V_5 , int V_6 )
{
T_2 * V_7 = NULL , V_8 ;
switch ( V_5 -> V_9 ) {
case F_3 ( V_10 ) :
V_7 = F_4 ( V_5 ,
V_6 + F_5 ( struct V_11 ,
V_17 ) ,
4 , & V_8 ) ;
break;
case F_3 ( V_13 ) :
V_7 = F_4 ( V_5 ,
V_6 + F_5 ( struct V_14 ,
V_17 . V_15 [ 3 ] ) ,
4 , & V_8 ) ;
break;
}
if ( V_7 )
return F_6 ( * V_7 ) ;
return F_1 ( F_8 ( V_5 ) ) ^ ( V_18 V_19 ) V_5 -> V_9 ;
}
static T_1 F_9 ( const struct V_4 * V_5 , int V_6 )
{
T_3 * V_7 = NULL , V_8 ;
switch ( V_5 -> V_9 ) {
case F_3 ( V_10 ) :
V_7 = F_4 ( V_5 ,
V_6 + F_5 ( struct V_11 ,
V_9 ) ,
1 , & V_8 ) ;
break;
case F_3 ( V_13 ) :
V_7 = F_4 ( V_5 ,
V_6 + F_5 ( struct V_14 ,
V_20 ) ,
1 , & V_8 ) ;
break;
}
if ( V_7 )
return * V_7 ;
return 0 ;
}
static T_4 * F_10 ( const struct V_4 * V_5 , int V_6 ,
T_4 * V_21 , int V_22 )
{
T_4 * V_23 = NULL ;
int V_24 ;
switch ( V_5 -> V_9 ) {
case F_3 ( V_10 ) : {
struct V_11 * V_25 , V_26 ;
V_25 = F_4 ( V_5 , V_6 , sizeof( V_26 ) , & V_26 ) ;
if ( ! V_25 )
break;
if ( F_11 ( V_25 ) )
break;
V_24 = F_12 ( V_25 -> V_9 ) ;
if ( V_24 >= 0 )
V_23 = F_4 ( V_5 ,
V_6 + V_25 -> V_27 * 4 + V_24 + V_22 ,
sizeof( * V_21 ) , V_21 ) ;
break;
}
case F_3 ( V_13 ) : {
struct V_14 * V_25 , V_26 ;
V_25 = F_4 ( V_5 , V_6 , sizeof( V_26 ) , & V_26 ) ;
if ( ! V_25 )
break;
V_24 = F_12 ( V_25 -> V_20 ) ;
if ( V_24 >= 0 )
V_23 = F_4 ( V_5 ,
V_6 + sizeof( * V_25 ) + V_24 + V_22 ,
sizeof( * V_21 ) , V_21 ) ;
break;
}
}
return V_23 ;
}
static T_1 F_13 ( const struct V_4 * V_5 , int V_6 )
{
T_4 V_21 , * V_23 = F_10 ( V_5 , V_6 , & V_21 , 0 ) ;
if ( V_23 )
return F_14 ( * V_23 ) ;
return F_1 ( V_5 -> V_16 ) ;
}
static T_1 F_15 ( const struct V_4 * V_5 , int V_6 )
{
T_4 V_21 , * V_23 = F_10 ( V_5 , V_6 , & V_21 , 2 ) ;
if ( V_23 )
return F_14 ( * V_23 ) ;
return F_1 ( F_8 ( V_5 ) ) ^ ( V_18 V_19 ) V_5 -> V_9 ;
}
static T_1 F_16 ( const struct V_4 * V_5 )
{
return V_5 -> V_28 ;
}
static T_1 F_17 ( const struct V_4 * V_5 )
{
return V_5 -> V_29 ;
}
static T_1 F_18 ( const struct V_4 * V_5 )
{
return V_5 -> V_30 ;
}
static T_1 F_19 ( const struct V_4 * V_5 )
{
#if F_20 ( V_31 ) || F_20 ( V_32 )
return F_1 ( V_5 -> V_33 ) ;
#else
return 0 ;
#endif
}
static T_1 F_21 ( const struct V_4 * V_5 , int V_6 )
{
switch ( V_5 -> V_9 ) {
case F_3 ( V_10 ) :
return F_6 ( F_22 ( V_5 , V_34 . V_35 . V_36 ) ) ;
case F_3 ( V_13 ) :
return F_6 ( F_22 ( V_5 , V_34 . V_35 . V_37 [ 3 ] ) ) ;
}
V_38:
return F_2 ( V_5 , V_6 ) ;
}
static T_1 F_23 ( const struct V_4 * V_5 , int V_6 )
{
switch ( V_5 -> V_9 ) {
case F_3 ( V_10 ) :
return F_6 ( F_22 ( V_5 , V_22 . V_35 . V_36 ) ) ;
case F_3 ( V_13 ) :
return F_6 ( F_22 ( V_5 , V_22 . V_35 . V_37 [ 3 ] ) ) ;
}
V_38:
return F_7 ( V_5 , V_6 ) ;
}
static T_1 F_24 ( const struct V_4 * V_5 , int V_6 )
{
return F_14 ( F_22 ( V_5 , V_34 . V_39 . V_40 ) ) ;
V_38:
return F_13 ( V_5 , V_6 ) ;
}
static T_1 F_25 ( const struct V_4 * V_5 , int V_6 )
{
return F_14 ( F_22 ( V_5 , V_22 . V_39 . V_40 ) ) ;
V_38:
return F_15 ( V_5 , V_6 ) ;
}
static T_1 F_26 ( const struct V_4 * V_5 )
{
#ifdef F_27
if ( F_8 ( V_5 ) )
return F_8 ( V_5 ) -> V_41 ;
#endif
return 0 ;
}
static T_1 F_28 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_16 && V_5 -> V_16 -> V_42 && V_5 -> V_16 -> V_42 -> V_43 )
return V_5 -> V_16 -> V_42 -> V_43 -> V_44 -> V_45 ;
return 0 ;
}
static T_1 F_29 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_16 && V_5 -> V_16 -> V_42 && V_5 -> V_16 -> V_42 -> V_43 )
return V_5 -> V_16 -> V_42 -> V_43 -> V_44 -> V_46 ;
return 0 ;
}
static T_1 F_30 ( const struct V_4 * V_5 )
{
V_19 V_47 ( V_48 ) ;
if ( F_31 ( V_5 , & V_48 ) < 0 )
return 0 ;
return V_48 & V_49 ;
}
static T_1 F_32 ( struct V_4 * V_5 )
{
return F_33 ( V_5 ) ;
}
static T_1 F_34 ( struct V_4 * V_5 , int V_50 )
{
int V_6 = F_35 ( V_5 ) ;
switch ( V_50 ) {
case V_51 :
return F_2 ( V_5 , V_6 ) ;
case V_52 :
return F_7 ( V_5 , V_6 ) ;
case V_53 :
return F_9 ( V_5 , V_6 ) ;
case V_54 :
return F_13 ( V_5 , V_6 ) ;
case V_55 :
return F_15 ( V_5 , V_6 ) ;
case V_56 :
return F_16 ( V_5 ) ;
case V_57 :
return F_17 ( V_5 ) ;
case V_58 :
return F_18 ( V_5 ) ;
case V_59 :
return F_19 ( V_5 ) ;
case V_60 :
return F_21 ( V_5 , V_6 ) ;
case V_61 :
return F_23 ( V_5 , V_6 ) ;
case V_62 :
return F_24 ( V_5 , V_6 ) ;
case V_63 :
return F_25 ( V_5 , V_6 ) ;
case V_64 :
return F_26 ( V_5 ) ;
case V_65 :
return F_28 ( V_5 ) ;
case V_66 :
return F_29 ( V_5 ) ;
case V_67 :
return F_30 ( V_5 ) ;
case V_68 :
return F_32 ( V_5 ) ;
default:
F_36 ( 1 ) ;
return 0 ;
}
}
static int F_37 ( struct V_4 * V_5 , const struct V_69 * V_70 ,
struct V_71 * V_72 )
{
struct V_73 * V_74 = V_70 -> V_75 ;
struct V_76 * V_77 ;
T_1 V_78 ;
T_1 V_79 ;
unsigned int V_80 , V_50 ;
int V_81 ;
F_38 (f, &head->filters, list) {
T_1 V_82 [ V_77 -> V_83 ] ;
if ( ! F_39 ( V_5 , & V_77 -> V_84 , NULL ) )
continue;
V_78 = V_77 -> V_78 ;
for ( V_80 = 0 ; V_80 < V_77 -> V_83 ; V_80 ++ ) {
V_50 = F_40 ( V_78 ) - 1 ;
V_78 &= ~ ( 1 << V_50 ) ;
V_82 [ V_80 ] = F_34 ( V_5 , V_50 ) ;
}
if ( V_77 -> V_85 == V_86 )
V_79 = F_41 ( V_82 , V_77 -> V_83 , V_77 -> V_87 ) ;
else {
V_79 = V_82 [ 0 ] ;
V_79 = ( V_79 & V_77 -> V_88 ) ^ V_77 -> V_89 ;
V_79 = ( V_79 >> V_77 -> V_90 ) + V_77 -> V_91 ;
}
if ( V_77 -> V_92 )
V_79 %= V_77 -> V_92 ;
V_72 -> V_93 = 0 ;
V_72 -> V_79 = F_42 ( V_77 -> V_94 , V_77 -> V_94 + V_79 ) ;
V_81 = F_43 ( V_5 , & V_77 -> V_95 , V_72 ) ;
if ( V_81 < 0 )
continue;
return V_81 ;
}
return - 1 ;
}
static void F_44 ( unsigned long V_96 )
{
struct V_76 * V_77 = (struct V_76 * ) V_96 ;
F_45 ( & V_77 -> V_87 , 4 ) ;
if ( V_77 -> V_97 )
F_46 ( & V_77 -> V_98 , V_99 + V_77 -> V_97 ) ;
}
static int F_47 ( struct V_69 * V_70 , unsigned long V_100 ,
T_1 V_101 , struct V_102 * * V_103 ,
unsigned long * V_96 )
{
struct V_73 * V_74 = V_70 -> V_75 ;
struct V_76 * V_77 ;
struct V_102 * V_104 = V_103 [ V_105 ] ;
struct V_102 * V_106 [ V_107 + 1 ] ;
struct V_108 V_109 ;
struct V_110 V_111 ;
unsigned int V_83 = 0 ;
unsigned int V_97 = 0 ;
T_1 V_94 = 0 ;
T_1 V_78 = 0 ;
T_1 V_85 ;
int V_112 ;
if ( V_104 == NULL )
return - V_113 ;
V_112 = F_48 ( V_106 , V_107 , V_104 , V_114 ) ;
if ( V_112 < 0 )
return V_112 ;
if ( V_106 [ V_115 ] ) {
V_94 = F_49 ( V_106 [ V_115 ] ) ;
if ( F_50 ( V_94 ) == 0 )
return - V_113 ;
}
if ( V_106 [ V_116 ] ) {
V_78 = F_49 ( V_106 [ V_116 ] ) ;
V_83 = F_51 ( V_78 ) ;
if ( V_83 == 0 )
return - V_113 ;
if ( F_52 ( V_78 ) - 1 > V_117 )
return - V_118 ;
}
V_112 = F_53 ( V_70 , V_106 , V_103 [ V_119 ] , & V_109 , & V_120 ) ;
if ( V_112 < 0 )
return V_112 ;
V_112 = F_54 ( V_70 , V_106 [ V_121 ] , & V_111 ) ;
if ( V_112 < 0 )
goto V_122;
V_77 = (struct V_76 * ) * V_96 ;
if ( V_77 != NULL ) {
V_112 = - V_113 ;
if ( V_77 -> V_101 != V_101 && V_101 )
goto V_123;
V_85 = V_77 -> V_85 ;
if ( V_106 [ V_124 ] )
V_85 = F_49 ( V_106 [ V_124 ] ) ;
if ( V_85 != V_86 && V_83 > 1 )
goto V_123;
if ( V_85 == V_86 )
V_97 = V_77 -> V_97 ;
if ( V_106 [ V_125 ] ) {
if ( V_85 != V_86 )
goto V_123;
V_97 = F_49 ( V_106 [ V_125 ] ) * V_126 ;
}
} else {
V_112 = - V_113 ;
if ( ! V_101 )
goto V_123;
if ( ! V_106 [ V_116 ] )
goto V_123;
V_85 = V_127 ;
if ( V_106 [ V_124 ] )
V_85 = F_49 ( V_106 [ V_124 ] ) ;
if ( V_85 != V_86 && V_83 > 1 )
goto V_123;
if ( V_106 [ V_125 ] ) {
if ( V_85 != V_86 )
goto V_123;
V_97 = F_49 ( V_106 [ V_125 ] ) * V_126 ;
}
if ( F_55 ( V_94 ) == 0 )
V_94 = F_42 ( V_70 -> V_128 -> V_101 , V_94 ) ;
if ( F_50 ( V_94 ) == 0 )
V_94 = F_42 ( V_94 , 1 ) ;
V_112 = - V_129 ;
V_77 = F_56 ( sizeof( * V_77 ) , V_130 ) ;
if ( V_77 == NULL )
goto V_123;
V_77 -> V_101 = V_101 ;
V_77 -> V_88 = ~ 0U ;
F_45 ( & V_77 -> V_87 , 4 ) ;
V_77 -> V_98 . V_131 = F_44 ;
V_77 -> V_98 . V_7 = ( unsigned long ) V_77 ;
F_57 ( & V_77 -> V_98 ) ;
}
F_58 ( V_70 , & V_77 -> V_95 , & V_109 ) ;
F_59 ( V_70 , & V_77 -> V_84 , & V_111 ) ;
F_60 ( V_70 ) ;
if ( V_106 [ V_116 ] ) {
V_77 -> V_78 = V_78 ;
V_77 -> V_83 = V_83 ;
}
V_77 -> V_85 = V_85 ;
if ( V_106 [ V_132 ] )
V_77 -> V_88 = F_49 ( V_106 [ V_132 ] ) ;
if ( V_106 [ V_133 ] )
V_77 -> V_89 = F_49 ( V_106 [ V_133 ] ) ;
if ( V_106 [ V_134 ] )
V_77 -> V_90 = F_49 ( V_106 [ V_134 ] ) ;
if ( V_106 [ V_135 ] )
V_77 -> V_91 = F_49 ( V_106 [ V_135 ] ) ;
if ( V_106 [ V_136 ] )
V_77 -> V_92 = F_49 ( V_106 [ V_136 ] ) ;
if ( V_94 )
V_77 -> V_94 = V_94 ;
V_77 -> V_97 = V_97 ;
F_61 ( & V_77 -> V_98 ) ;
if ( V_97 )
F_46 ( & V_77 -> V_98 , V_99 + V_97 ) ;
if ( * V_96 == 0 )
F_62 ( & V_77 -> V_137 , & V_74 -> V_138 ) ;
F_63 ( V_70 ) ;
* V_96 = ( unsigned long ) V_77 ;
return 0 ;
V_123:
F_64 ( V_70 , & V_111 ) ;
V_122:
F_65 ( V_70 , & V_109 ) ;
return V_112 ;
}
static void F_66 ( struct V_69 * V_70 , struct V_76 * V_77 )
{
F_67 ( & V_77 -> V_98 ) ;
F_65 ( V_70 , & V_77 -> V_95 ) ;
F_64 ( V_70 , & V_77 -> V_84 ) ;
F_68 ( V_77 ) ;
}
static int F_69 ( struct V_69 * V_70 , unsigned long V_96 )
{
struct V_76 * V_77 = (struct V_76 * ) V_96 ;
F_60 ( V_70 ) ;
F_70 ( & V_77 -> V_137 ) ;
F_63 ( V_70 ) ;
F_66 ( V_70 , V_77 ) ;
return 0 ;
}
static int F_71 ( struct V_69 * V_70 )
{
struct V_73 * V_74 ;
V_74 = F_56 ( sizeof( * V_74 ) , V_130 ) ;
if ( V_74 == NULL )
return - V_129 ;
F_72 ( & V_74 -> V_138 ) ;
V_70 -> V_75 = V_74 ;
return 0 ;
}
static void F_73 ( struct V_69 * V_70 )
{
struct V_73 * V_74 = V_70 -> V_75 ;
struct V_76 * V_77 , * V_139 ;
F_74 (f, next, &head->filters, list) {
F_70 ( & V_77 -> V_137 ) ;
F_66 ( V_70 , V_77 ) ;
}
F_68 ( V_74 ) ;
}
static unsigned long F_75 ( struct V_69 * V_70 , T_1 V_101 )
{
struct V_73 * V_74 = V_70 -> V_75 ;
struct V_76 * V_77 ;
F_38 (f, &head->filters, list)
if ( V_77 -> V_101 == V_101 )
return ( unsigned long ) V_77 ;
return 0 ;
}
static void F_76 ( struct V_69 * V_70 , unsigned long V_77 )
{
}
static int F_77 ( struct V_69 * V_70 , unsigned long V_140 ,
struct V_4 * V_5 , struct V_141 * V_111 )
{
struct V_76 * V_77 = (struct V_76 * ) V_140 ;
struct V_102 * V_142 ;
if ( V_77 == NULL )
return V_5 -> V_143 ;
V_111 -> V_144 = V_77 -> V_101 ;
V_142 = F_78 ( V_5 , V_105 ) ;
if ( V_142 == NULL )
goto V_145;
F_79 ( V_5 , V_116 , V_77 -> V_78 ) ;
F_79 ( V_5 , V_124 , V_77 -> V_85 ) ;
if ( V_77 -> V_88 != ~ 0 || V_77 -> V_89 != 0 ) {
F_79 ( V_5 , V_132 , V_77 -> V_88 ) ;
F_79 ( V_5 , V_133 , V_77 -> V_89 ) ;
}
if ( V_77 -> V_90 )
F_79 ( V_5 , V_134 , V_77 -> V_90 ) ;
if ( V_77 -> V_91 )
F_79 ( V_5 , V_135 , V_77 -> V_91 ) ;
if ( V_77 -> V_92 )
F_79 ( V_5 , V_136 , V_77 -> V_92 ) ;
if ( V_77 -> V_94 )
F_79 ( V_5 , V_115 , V_77 -> V_94 ) ;
if ( V_77 -> V_97 )
F_79 ( V_5 , V_125 , V_77 -> V_97 / V_126 ) ;
if ( F_80 ( V_5 , & V_77 -> V_95 , & V_120 ) < 0 )
goto V_145;
#ifdef F_81
if ( V_77 -> V_84 . V_146 . V_147 &&
F_82 ( V_5 , & V_77 -> V_84 , V_121 ) < 0 )
goto V_145;
#endif
F_83 ( V_5 , V_142 ) ;
if ( F_84 ( V_5 , & V_77 -> V_95 , & V_120 ) < 0 )
goto V_145;
return V_5 -> V_143 ;
V_145:
F_85 ( V_5 , V_142 ) ;
return - 1 ;
}
static void F_86 ( struct V_69 * V_70 , struct V_148 * V_96 )
{
struct V_73 * V_74 = V_70 -> V_75 ;
struct V_76 * V_77 ;
F_38 (f, &head->filters, list) {
if ( V_96 -> V_149 < V_96 -> V_150 )
goto V_150;
if ( V_96 -> V_151 ( V_70 , ( unsigned long ) V_77 , V_96 ) < 0 ) {
V_96 -> V_152 = 1 ;
break;
}
V_150:
V_96 -> V_149 ++ ;
}
}
static int T_5 F_87 ( void )
{
return F_88 ( & V_153 ) ;
}
static void T_6 F_89 ( void )
{
F_90 ( & V_153 ) ;
}
