static inline T_1 F_1 ( void * V_1 )
{
unsigned long V_2 = ( unsigned long ) V_1 ;
return ( V_2 & 0xFFFFFFFF ) ^ ( V_3 > 32 ? V_2 >> 32 : 0 ) ;
}
static T_1 F_2 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_6 ) {
case F_3 ( V_7 ) :
if ( F_4 ( V_5 , sizeof( struct V_8 ) ) )
return F_5 ( F_6 ( V_5 ) -> V_9 ) ;
break;
case F_3 ( V_10 ) :
if ( F_4 ( V_5 , sizeof( struct V_11 ) ) )
return F_5 ( F_7 ( V_5 ) -> V_9 . V_12 [ 3 ] ) ;
break;
}
return F_1 ( V_5 -> V_13 ) ;
}
static T_1 F_8 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_6 ) {
case F_3 ( V_7 ) :
if ( F_4 ( V_5 , sizeof( struct V_8 ) ) )
return F_5 ( F_6 ( V_5 ) -> V_14 ) ;
break;
case F_3 ( V_10 ) :
if ( F_4 ( V_5 , sizeof( struct V_11 ) ) )
return F_5 ( F_7 ( V_5 ) -> V_14 . V_12 [ 3 ] ) ;
break;
}
return F_1 ( F_9 ( V_5 ) ) ^ ( V_15 V_16 ) V_5 -> V_6 ;
}
static T_1 F_10 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_6 ) {
case F_3 ( V_7 ) :
return F_4 ( V_5 , sizeof( struct V_8 ) ) ?
F_6 ( V_5 ) -> V_6 : 0 ;
case F_3 ( V_10 ) :
return F_4 ( V_5 , sizeof( struct V_11 ) ) ?
F_7 ( V_5 ) -> V_17 : 0 ;
default:
return 0 ;
}
}
static T_1 F_11 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_6 ) {
case F_3 ( V_7 ) : {
struct V_8 * V_18 ;
int V_19 ;
if ( ! F_4 ( V_5 , sizeof( * V_18 ) ) )
break;
V_18 = F_6 ( V_5 ) ;
if ( F_12 ( V_18 ) )
break;
V_19 = F_13 ( V_18 -> V_6 ) ;
if ( V_19 >= 0 &&
F_4 ( V_5 , V_18 -> V_20 * 4 + 2 + V_19 ) ) {
V_18 = F_6 ( V_5 ) ;
return F_14 ( * ( V_21 * ) ( ( void * ) V_18 + V_18 -> V_20 * 4 +
V_19 ) ) ;
}
break;
}
case F_3 ( V_10 ) : {
struct V_11 * V_18 ;
int V_19 ;
if ( ! F_4 ( V_5 , sizeof( * V_18 ) ) )
break;
V_18 = F_7 ( V_5 ) ;
V_19 = F_13 ( V_18 -> V_17 ) ;
if ( V_19 >= 0 &&
F_4 ( V_5 , sizeof( * V_18 ) + V_19 + 2 ) ) {
V_18 = F_7 ( V_5 ) ;
return F_14 ( * ( V_21 * ) ( ( void * ) V_18 + sizeof( * V_18 ) +
V_19 ) ) ;
}
break;
}
}
return F_1 ( V_5 -> V_13 ) ;
}
static T_1 F_15 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_6 ) {
case F_3 ( V_7 ) : {
struct V_8 * V_18 ;
int V_19 ;
if ( ! F_4 ( V_5 , sizeof( * V_18 ) ) )
break;
V_18 = F_6 ( V_5 ) ;
if ( F_12 ( V_18 ) )
break;
V_19 = F_13 ( V_18 -> V_6 ) ;
if ( V_19 >= 0 &&
F_4 ( V_5 , V_18 -> V_20 * 4 + 4 + V_19 ) ) {
V_18 = F_6 ( V_5 ) ;
return F_14 ( * ( V_21 * ) ( ( void * ) V_18 + V_18 -> V_20 * 4 +
2 + V_19 ) ) ;
}
break;
}
case F_3 ( V_10 ) : {
struct V_11 * V_18 ;
int V_19 ;
if ( ! F_4 ( V_5 , sizeof( * V_18 ) ) )
break;
V_18 = F_7 ( V_5 ) ;
V_19 = F_13 ( V_18 -> V_17 ) ;
if ( V_19 >= 0 &&
F_4 ( V_5 , sizeof( * V_18 ) + V_19 + 4 ) ) {
V_18 = F_7 ( V_5 ) ;
return F_14 ( * ( V_21 * ) ( ( void * ) V_18 + sizeof( * V_18 ) +
V_19 + 2 ) ) ;
}
break;
}
}
return F_1 ( F_9 ( V_5 ) ) ^ ( V_15 V_16 ) V_5 -> V_6 ;
}
static T_1 F_16 ( const struct V_4 * V_5 )
{
return V_5 -> V_22 ;
}
static T_1 F_17 ( const struct V_4 * V_5 )
{
return V_5 -> V_23 ;
}
static T_1 F_18 ( const struct V_4 * V_5 )
{
return V_5 -> V_24 ;
}
static T_1 F_19 ( const struct V_4 * V_5 )
{
#if F_20 ( V_25 ) || F_20 ( V_26 )
return F_1 ( V_5 -> V_27 ) ;
#else
return 0 ;
#endif
}
static T_1 F_21 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_6 ) {
case F_3 ( V_7 ) :
return F_5 ( F_22 ( V_5 , V_28 . V_29 . V_30 ) ) ;
case F_3 ( V_10 ) :
return F_5 ( F_22 ( V_5 , V_28 . V_29 . V_31 [ 3 ] ) ) ;
}
V_32:
return F_2 ( V_5 ) ;
}
static T_1 F_23 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_6 ) {
case F_3 ( V_7 ) :
return F_5 ( F_22 ( V_5 , V_33 . V_29 . V_30 ) ) ;
case F_3 ( V_10 ) :
return F_5 ( F_22 ( V_5 , V_33 . V_29 . V_31 [ 3 ] ) ) ;
}
V_32:
return F_8 ( V_5 ) ;
}
static T_1 F_24 ( struct V_4 * V_5 )
{
return F_14 ( F_22 ( V_5 , V_28 . V_34 . V_35 ) ) ;
V_32:
return F_11 ( V_5 ) ;
}
static T_1 F_25 ( struct V_4 * V_5 )
{
return F_14 ( F_22 ( V_5 , V_33 . V_34 . V_35 ) ) ;
V_32:
return F_15 ( V_5 ) ;
}
static T_1 F_26 ( const struct V_4 * V_5 )
{
#ifdef F_27
if ( F_9 ( V_5 ) )
return F_9 ( V_5 ) -> V_36 ;
#endif
return 0 ;
}
static T_1 F_28 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_13 && V_5 -> V_13 -> V_37 && V_5 -> V_13 -> V_37 -> V_38 )
return V_5 -> V_13 -> V_37 -> V_38 -> V_39 -> V_40 ;
return 0 ;
}
static T_1 F_29 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_13 && V_5 -> V_13 -> V_37 && V_5 -> V_13 -> V_37 -> V_38 )
return V_5 -> V_13 -> V_37 -> V_38 -> V_39 -> V_41 ;
return 0 ;
}
static T_1 F_30 ( const struct V_4 * V_5 )
{
V_16 V_42 ( V_43 ) ;
if ( F_31 ( V_5 , & V_43 ) < 0 )
return 0 ;
return V_43 & V_44 ;
}
static T_1 F_32 ( struct V_4 * V_5 )
{
return F_33 ( V_5 ) ;
}
static T_1 F_34 ( struct V_4 * V_5 , int V_45 )
{
switch ( V_45 ) {
case V_46 :
return F_2 ( V_5 ) ;
case V_47 :
return F_8 ( V_5 ) ;
case V_48 :
return F_10 ( V_5 ) ;
case V_49 :
return F_11 ( V_5 ) ;
case V_50 :
return F_15 ( V_5 ) ;
case V_51 :
return F_16 ( V_5 ) ;
case V_52 :
return F_17 ( V_5 ) ;
case V_53 :
return F_18 ( V_5 ) ;
case V_54 :
return F_19 ( V_5 ) ;
case V_55 :
return F_21 ( V_5 ) ;
case V_56 :
return F_23 ( V_5 ) ;
case V_57 :
return F_24 ( V_5 ) ;
case V_58 :
return F_25 ( V_5 ) ;
case V_59 :
return F_26 ( V_5 ) ;
case V_60 :
return F_28 ( V_5 ) ;
case V_61 :
return F_29 ( V_5 ) ;
case V_62 :
return F_30 ( V_5 ) ;
case V_63 :
return F_32 ( V_5 ) ;
default:
F_35 ( 1 ) ;
return 0 ;
}
}
static int F_36 ( struct V_4 * V_5 , const struct V_64 * V_65 ,
struct V_66 * V_67 )
{
struct V_68 * V_69 = V_65 -> V_70 ;
struct V_71 * V_72 ;
T_1 V_73 ;
T_1 V_74 ;
unsigned int V_75 , V_45 ;
int V_76 ;
F_37 (f, &head->filters, list) {
T_1 V_77 [ V_72 -> V_78 ] ;
if ( ! F_38 ( V_5 , & V_72 -> V_79 , NULL ) )
continue;
V_73 = V_72 -> V_73 ;
for ( V_75 = 0 ; V_75 < V_72 -> V_78 ; V_75 ++ ) {
V_45 = F_39 ( V_73 ) - 1 ;
V_73 &= ~ ( 1 << V_45 ) ;
V_77 [ V_75 ] = F_34 ( V_5 , V_45 ) ;
}
if ( V_72 -> V_80 == V_81 )
V_74 = F_40 ( V_77 , V_72 -> V_78 , V_72 -> V_82 ) ;
else {
V_74 = V_77 [ 0 ] ;
V_74 = ( V_74 & V_72 -> V_83 ) ^ V_72 -> V_84 ;
V_74 = ( V_74 >> V_72 -> V_85 ) + V_72 -> V_86 ;
}
if ( V_72 -> V_87 )
V_74 %= V_72 -> V_87 ;
V_67 -> V_88 = 0 ;
V_67 -> V_74 = F_41 ( V_72 -> V_89 , V_72 -> V_89 + V_74 ) ;
V_76 = F_42 ( V_5 , & V_72 -> V_90 , V_67 ) ;
if ( V_76 < 0 )
continue;
return V_76 ;
}
return - 1 ;
}
static void F_43 ( unsigned long V_91 )
{
struct V_71 * V_72 = (struct V_71 * ) V_91 ;
F_44 ( & V_72 -> V_82 , 4 ) ;
if ( V_72 -> V_92 )
F_45 ( & V_72 -> V_93 , V_94 + V_72 -> V_92 ) ;
}
static int F_46 ( struct V_64 * V_65 , unsigned long V_95 ,
T_1 V_96 , struct V_97 * * V_98 ,
unsigned long * V_91 )
{
struct V_68 * V_69 = V_65 -> V_70 ;
struct V_71 * V_72 ;
struct V_97 * V_99 = V_98 [ V_100 ] ;
struct V_97 * V_101 [ V_102 + 1 ] ;
struct V_103 V_104 ;
struct V_105 V_106 ;
unsigned int V_78 = 0 ;
unsigned int V_92 = 0 ;
T_1 V_89 = 0 ;
T_1 V_73 = 0 ;
T_1 V_80 ;
int V_107 ;
if ( V_99 == NULL )
return - V_108 ;
V_107 = F_47 ( V_101 , V_102 , V_99 , V_109 ) ;
if ( V_107 < 0 )
return V_107 ;
if ( V_101 [ V_110 ] ) {
V_89 = F_48 ( V_101 [ V_110 ] ) ;
if ( F_49 ( V_89 ) == 0 )
return - V_108 ;
}
if ( V_101 [ V_111 ] ) {
V_73 = F_48 ( V_101 [ V_111 ] ) ;
V_78 = F_50 ( V_73 ) ;
if ( V_78 == 0 )
return - V_108 ;
if ( F_51 ( V_73 ) - 1 > V_112 )
return - V_113 ;
}
V_107 = F_52 ( V_65 , V_101 , V_98 [ V_114 ] , & V_104 , & V_115 ) ;
if ( V_107 < 0 )
return V_107 ;
V_107 = F_53 ( V_65 , V_101 [ V_116 ] , & V_106 ) ;
if ( V_107 < 0 )
goto V_117;
V_72 = (struct V_71 * ) * V_91 ;
if ( V_72 != NULL ) {
V_107 = - V_108 ;
if ( V_72 -> V_96 != V_96 && V_96 )
goto V_118;
V_80 = V_72 -> V_80 ;
if ( V_101 [ V_119 ] )
V_80 = F_48 ( V_101 [ V_119 ] ) ;
if ( V_80 != V_81 && V_78 > 1 )
goto V_118;
if ( V_80 == V_81 )
V_92 = V_72 -> V_92 ;
if ( V_101 [ V_120 ] ) {
if ( V_80 != V_81 )
goto V_118;
V_92 = F_48 ( V_101 [ V_120 ] ) * V_121 ;
}
} else {
V_107 = - V_108 ;
if ( ! V_96 )
goto V_118;
if ( ! V_101 [ V_111 ] )
goto V_118;
V_80 = V_122 ;
if ( V_101 [ V_119 ] )
V_80 = F_48 ( V_101 [ V_119 ] ) ;
if ( V_80 != V_81 && V_78 > 1 )
goto V_118;
if ( V_101 [ V_120 ] ) {
if ( V_80 != V_81 )
goto V_118;
V_92 = F_48 ( V_101 [ V_120 ] ) * V_121 ;
}
if ( F_54 ( V_89 ) == 0 )
V_89 = F_41 ( V_65 -> V_123 -> V_96 , V_89 ) ;
if ( F_49 ( V_89 ) == 0 )
V_89 = F_41 ( V_89 , 1 ) ;
V_107 = - V_124 ;
V_72 = F_55 ( sizeof( * V_72 ) , V_125 ) ;
if ( V_72 == NULL )
goto V_118;
V_72 -> V_96 = V_96 ;
V_72 -> V_83 = ~ 0U ;
F_44 ( & V_72 -> V_82 , 4 ) ;
V_72 -> V_93 . V_126 = F_43 ;
V_72 -> V_93 . V_127 = ( unsigned long ) V_72 ;
F_56 ( & V_72 -> V_93 ) ;
}
F_57 ( V_65 , & V_72 -> V_90 , & V_104 ) ;
F_58 ( V_65 , & V_72 -> V_79 , & V_106 ) ;
F_59 ( V_65 ) ;
if ( V_101 [ V_111 ] ) {
V_72 -> V_73 = V_73 ;
V_72 -> V_78 = V_78 ;
}
V_72 -> V_80 = V_80 ;
if ( V_101 [ V_128 ] )
V_72 -> V_83 = F_48 ( V_101 [ V_128 ] ) ;
if ( V_101 [ V_129 ] )
V_72 -> V_84 = F_48 ( V_101 [ V_129 ] ) ;
if ( V_101 [ V_130 ] )
V_72 -> V_85 = F_48 ( V_101 [ V_130 ] ) ;
if ( V_101 [ V_131 ] )
V_72 -> V_86 = F_48 ( V_101 [ V_131 ] ) ;
if ( V_101 [ V_132 ] )
V_72 -> V_87 = F_48 ( V_101 [ V_132 ] ) ;
if ( V_89 )
V_72 -> V_89 = V_89 ;
V_72 -> V_92 = V_92 ;
F_60 ( & V_72 -> V_93 ) ;
if ( V_92 )
F_45 ( & V_72 -> V_93 , V_94 + V_92 ) ;
if ( * V_91 == 0 )
F_61 ( & V_72 -> V_133 , & V_69 -> V_134 ) ;
F_62 ( V_65 ) ;
* V_91 = ( unsigned long ) V_72 ;
return 0 ;
V_118:
F_63 ( V_65 , & V_106 ) ;
V_117:
F_64 ( V_65 , & V_104 ) ;
return V_107 ;
}
static void F_65 ( struct V_64 * V_65 , struct V_71 * V_72 )
{
F_66 ( & V_72 -> V_93 ) ;
F_64 ( V_65 , & V_72 -> V_90 ) ;
F_63 ( V_65 , & V_72 -> V_79 ) ;
F_67 ( V_72 ) ;
}
static int F_68 ( struct V_64 * V_65 , unsigned long V_91 )
{
struct V_71 * V_72 = (struct V_71 * ) V_91 ;
F_59 ( V_65 ) ;
F_69 ( & V_72 -> V_133 ) ;
F_62 ( V_65 ) ;
F_65 ( V_65 , V_72 ) ;
return 0 ;
}
static int F_70 ( struct V_64 * V_65 )
{
struct V_68 * V_69 ;
V_69 = F_55 ( sizeof( * V_69 ) , V_125 ) ;
if ( V_69 == NULL )
return - V_124 ;
F_71 ( & V_69 -> V_134 ) ;
V_65 -> V_70 = V_69 ;
return 0 ;
}
static void F_72 ( struct V_64 * V_65 )
{
struct V_68 * V_69 = V_65 -> V_70 ;
struct V_71 * V_72 , * V_135 ;
F_73 (f, next, &head->filters, list) {
F_69 ( & V_72 -> V_133 ) ;
F_65 ( V_65 , V_72 ) ;
}
F_67 ( V_69 ) ;
}
static unsigned long F_74 ( struct V_64 * V_65 , T_1 V_96 )
{
struct V_68 * V_69 = V_65 -> V_70 ;
struct V_71 * V_72 ;
F_37 (f, &head->filters, list)
if ( V_72 -> V_96 == V_96 )
return ( unsigned long ) V_72 ;
return 0 ;
}
static void F_75 ( struct V_64 * V_65 , unsigned long V_72 )
{
}
static int F_76 ( struct V_64 * V_65 , unsigned long V_136 ,
struct V_4 * V_5 , struct V_137 * V_106 )
{
struct V_71 * V_72 = (struct V_71 * ) V_136 ;
struct V_97 * V_138 ;
if ( V_72 == NULL )
return V_5 -> V_139 ;
V_106 -> V_140 = V_72 -> V_96 ;
V_138 = F_77 ( V_5 , V_100 ) ;
if ( V_138 == NULL )
goto V_141;
F_78 ( V_5 , V_111 , V_72 -> V_73 ) ;
F_78 ( V_5 , V_119 , V_72 -> V_80 ) ;
if ( V_72 -> V_83 != ~ 0 || V_72 -> V_84 != 0 ) {
F_78 ( V_5 , V_128 , V_72 -> V_83 ) ;
F_78 ( V_5 , V_129 , V_72 -> V_84 ) ;
}
if ( V_72 -> V_85 )
F_78 ( V_5 , V_130 , V_72 -> V_85 ) ;
if ( V_72 -> V_86 )
F_78 ( V_5 , V_131 , V_72 -> V_86 ) ;
if ( V_72 -> V_87 )
F_78 ( V_5 , V_132 , V_72 -> V_87 ) ;
if ( V_72 -> V_89 )
F_78 ( V_5 , V_110 , V_72 -> V_89 ) ;
if ( V_72 -> V_92 )
F_78 ( V_5 , V_120 , V_72 -> V_92 / V_121 ) ;
if ( F_79 ( V_5 , & V_72 -> V_90 , & V_115 ) < 0 )
goto V_141;
#ifdef F_80
if ( V_72 -> V_79 . V_142 . V_143 &&
F_81 ( V_5 , & V_72 -> V_79 , V_116 ) < 0 )
goto V_141;
#endif
F_82 ( V_5 , V_138 ) ;
if ( F_83 ( V_5 , & V_72 -> V_90 , & V_115 ) < 0 )
goto V_141;
return V_5 -> V_139 ;
V_141:
F_84 ( V_5 , V_138 ) ;
return - 1 ;
}
static void F_85 ( struct V_64 * V_65 , struct V_144 * V_91 )
{
struct V_68 * V_69 = V_65 -> V_70 ;
struct V_71 * V_72 ;
F_37 (f, &head->filters, list) {
if ( V_91 -> V_145 < V_91 -> V_146 )
goto V_146;
if ( V_91 -> V_147 ( V_65 , ( unsigned long ) V_72 , V_91 ) < 0 ) {
V_91 -> V_148 = 1 ;
break;
}
V_146:
V_91 -> V_145 ++ ;
}
}
static int T_2 F_86 ( void )
{
return F_87 ( & V_149 ) ;
}
static void T_3 F_88 ( void )
{
F_89 ( & V_149 ) ;
}
