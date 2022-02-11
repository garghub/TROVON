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
if ( V_18 -> V_20 & F_3 ( V_21 | V_22 ) )
break;
V_19 = F_12 ( V_18 -> V_6 ) ;
if ( V_19 >= 0 &&
F_4 ( V_5 , V_18 -> V_23 * 4 + 2 + V_19 ) ) {
V_18 = F_6 ( V_5 ) ;
return F_13 ( * ( V_24 * ) ( ( void * ) V_18 + V_18 -> V_23 * 4 +
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
V_19 = F_12 ( V_18 -> V_17 ) ;
if ( V_19 >= 0 &&
F_4 ( V_5 , sizeof( * V_18 ) + V_19 + 2 ) ) {
V_18 = F_7 ( V_5 ) ;
return F_13 ( * ( V_24 * ) ( ( void * ) V_18 + sizeof( * V_18 ) +
V_19 ) ) ;
}
break;
}
}
return F_1 ( V_5 -> V_13 ) ;
}
static T_1 F_14 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_6 ) {
case F_3 ( V_7 ) : {
struct V_8 * V_18 ;
int V_19 ;
if ( ! F_4 ( V_5 , sizeof( * V_18 ) ) )
break;
V_18 = F_6 ( V_5 ) ;
if ( V_18 -> V_20 & F_3 ( V_21 | V_22 ) )
break;
V_19 = F_12 ( V_18 -> V_6 ) ;
if ( V_19 >= 0 &&
F_4 ( V_5 , V_18 -> V_23 * 4 + 4 + V_19 ) ) {
V_18 = F_6 ( V_5 ) ;
return F_13 ( * ( V_24 * ) ( ( void * ) V_18 + V_18 -> V_23 * 4 +
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
V_19 = F_12 ( V_18 -> V_17 ) ;
if ( V_19 >= 0 &&
F_4 ( V_5 , sizeof( * V_18 ) + V_19 + 4 ) ) {
V_18 = F_7 ( V_5 ) ;
return F_13 ( * ( V_24 * ) ( ( void * ) V_18 + sizeof( * V_18 ) +
V_19 + 2 ) ) ;
}
break;
}
}
return F_1 ( F_9 ( V_5 ) ) ^ ( V_15 V_16 ) V_5 -> V_6 ;
}
static T_1 F_15 ( const struct V_4 * V_5 )
{
return V_5 -> V_25 ;
}
static T_1 F_16 ( const struct V_4 * V_5 )
{
return V_5 -> V_26 ;
}
static T_1 F_17 ( const struct V_4 * V_5 )
{
return V_5 -> V_27 ;
}
static T_1 F_18 ( const struct V_4 * V_5 )
{
#if F_19 ( V_28 ) || F_19 ( V_29 )
return F_1 ( V_5 -> V_30 ) ;
#else
return 0 ;
#endif
}
static T_1 F_20 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_6 ) {
case F_3 ( V_7 ) :
return F_5 ( F_21 ( V_5 , V_31 . V_32 . V_33 ) ) ;
case F_3 ( V_10 ) :
return F_5 ( F_21 ( V_5 , V_31 . V_32 . V_34 [ 3 ] ) ) ;
}
V_35:
return F_2 ( V_5 ) ;
}
static T_1 F_22 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_6 ) {
case F_3 ( V_7 ) :
return F_5 ( F_21 ( V_5 , V_36 . V_32 . V_33 ) ) ;
case F_3 ( V_10 ) :
return F_5 ( F_21 ( V_5 , V_36 . V_32 . V_34 [ 3 ] ) ) ;
}
V_35:
return F_8 ( V_5 ) ;
}
static T_1 F_23 ( struct V_4 * V_5 )
{
return F_13 ( F_21 ( V_5 , V_31 . V_37 . V_38 ) ) ;
V_35:
return F_11 ( V_5 ) ;
}
static T_1 F_24 ( struct V_4 * V_5 )
{
return F_13 ( F_21 ( V_5 , V_36 . V_37 . V_38 ) ) ;
V_35:
return F_14 ( V_5 ) ;
}
static T_1 F_25 ( const struct V_4 * V_5 )
{
#ifdef F_26
if ( F_9 ( V_5 ) )
return F_9 ( V_5 ) -> V_39 ;
#endif
return 0 ;
}
static T_1 F_27 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_13 && V_5 -> V_13 -> V_40 && V_5 -> V_13 -> V_40 -> V_41 )
return V_5 -> V_13 -> V_40 -> V_41 -> V_42 -> V_43 ;
return 0 ;
}
static T_1 F_28 ( const struct V_4 * V_5 )
{
if ( V_5 -> V_13 && V_5 -> V_13 -> V_40 && V_5 -> V_13 -> V_40 -> V_41 )
return V_5 -> V_13 -> V_40 -> V_41 -> V_42 -> V_44 ;
return 0 ;
}
static T_1 F_29 ( const struct V_4 * V_5 )
{
V_16 V_45 ( V_46 ) ;
if ( F_30 ( V_5 , & V_46 ) < 0 )
return 0 ;
return V_46 & V_47 ;
}
static T_1 F_31 ( struct V_4 * V_5 )
{
return F_32 ( V_5 ) ;
}
static T_1 F_33 ( struct V_4 * V_5 , int V_48 )
{
switch ( V_48 ) {
case V_49 :
return F_2 ( V_5 ) ;
case V_50 :
return F_8 ( V_5 ) ;
case V_51 :
return F_10 ( V_5 ) ;
case V_52 :
return F_11 ( V_5 ) ;
case V_53 :
return F_14 ( V_5 ) ;
case V_54 :
return F_15 ( V_5 ) ;
case V_55 :
return F_16 ( V_5 ) ;
case V_56 :
return F_17 ( V_5 ) ;
case V_57 :
return F_18 ( V_5 ) ;
case V_58 :
return F_20 ( V_5 ) ;
case V_59 :
return F_22 ( V_5 ) ;
case V_60 :
return F_23 ( V_5 ) ;
case V_61 :
return F_24 ( V_5 ) ;
case V_62 :
return F_25 ( V_5 ) ;
case V_63 :
return F_27 ( V_5 ) ;
case V_64 :
return F_28 ( V_5 ) ;
case V_65 :
return F_29 ( V_5 ) ;
case V_66 :
return F_31 ( V_5 ) ;
default:
F_34 ( 1 ) ;
return 0 ;
}
}
static int F_35 ( struct V_4 * V_5 , struct V_67 * V_68 ,
struct V_69 * V_70 )
{
struct V_71 * V_72 = V_68 -> V_73 ;
struct V_74 * V_75 ;
T_1 V_76 ;
T_1 V_77 ;
unsigned int V_78 , V_48 ;
int V_79 ;
F_36 (f, &head->filters, list) {
T_1 V_80 [ V_75 -> V_81 ] ;
if ( ! F_37 ( V_5 , & V_75 -> V_82 , NULL ) )
continue;
V_76 = V_75 -> V_76 ;
for ( V_78 = 0 ; V_78 < V_75 -> V_81 ; V_78 ++ ) {
V_48 = F_38 ( V_76 ) - 1 ;
V_76 &= ~ ( 1 << V_48 ) ;
V_80 [ V_78 ] = F_33 ( V_5 , V_48 ) ;
}
if ( V_75 -> V_83 == V_84 )
V_77 = F_39 ( V_80 , V_75 -> V_81 , V_75 -> V_85 ) ;
else {
V_77 = V_80 [ 0 ] ;
V_77 = ( V_77 & V_75 -> V_86 ) ^ V_75 -> V_87 ;
V_77 = ( V_77 >> V_75 -> V_88 ) + V_75 -> V_89 ;
}
if ( V_75 -> V_90 )
V_77 %= V_75 -> V_90 ;
V_70 -> V_91 = 0 ;
V_70 -> V_77 = F_40 ( V_75 -> V_92 , V_75 -> V_92 + V_77 ) ;
V_79 = F_41 ( V_5 , & V_75 -> V_93 , V_70 ) ;
if ( V_79 < 0 )
continue;
return V_79 ;
}
return - 1 ;
}
static void F_42 ( unsigned long V_94 )
{
struct V_74 * V_75 = (struct V_74 * ) V_94 ;
F_43 ( & V_75 -> V_85 , 4 ) ;
if ( V_75 -> V_95 )
F_44 ( & V_75 -> V_96 , V_97 + V_75 -> V_95 ) ;
}
static int F_45 ( struct V_67 * V_68 , unsigned long V_98 ,
T_1 V_99 , struct V_100 * * V_101 ,
unsigned long * V_94 )
{
struct V_71 * V_72 = V_68 -> V_73 ;
struct V_74 * V_75 ;
struct V_100 * V_102 = V_101 [ V_103 ] ;
struct V_100 * V_104 [ V_105 + 1 ] ;
struct V_106 V_107 ;
struct V_108 V_109 ;
unsigned int V_81 = 0 ;
unsigned int V_95 = 0 ;
T_1 V_92 = 0 ;
T_1 V_76 = 0 ;
T_1 V_83 ;
int V_110 ;
if ( V_102 == NULL )
return - V_111 ;
V_110 = F_46 ( V_104 , V_105 , V_102 , V_112 ) ;
if ( V_110 < 0 )
return V_110 ;
if ( V_104 [ V_113 ] ) {
V_92 = F_47 ( V_104 [ V_113 ] ) ;
if ( F_48 ( V_92 ) == 0 )
return - V_111 ;
}
if ( V_104 [ V_114 ] ) {
V_76 = F_47 ( V_104 [ V_114 ] ) ;
V_81 = F_49 ( V_76 ) ;
if ( V_81 == 0 )
return - V_111 ;
if ( F_50 ( V_76 ) - 1 > V_115 )
return - V_116 ;
}
V_110 = F_51 ( V_68 , V_104 , V_101 [ V_117 ] , & V_107 , & V_118 ) ;
if ( V_110 < 0 )
return V_110 ;
V_110 = F_52 ( V_68 , V_104 [ V_119 ] , & V_109 ) ;
if ( V_110 < 0 )
goto V_120;
V_75 = (struct V_74 * ) * V_94 ;
if ( V_75 != NULL ) {
V_110 = - V_111 ;
if ( V_75 -> V_99 != V_99 && V_99 )
goto V_121;
V_83 = V_75 -> V_83 ;
if ( V_104 [ V_122 ] )
V_83 = F_47 ( V_104 [ V_122 ] ) ;
if ( V_83 != V_84 && V_81 > 1 )
goto V_121;
if ( V_83 == V_84 )
V_95 = V_75 -> V_95 ;
if ( V_104 [ V_123 ] ) {
if ( V_83 != V_84 )
goto V_121;
V_95 = F_47 ( V_104 [ V_123 ] ) * V_124 ;
}
} else {
V_110 = - V_111 ;
if ( ! V_99 )
goto V_121;
if ( ! V_104 [ V_114 ] )
goto V_121;
V_83 = V_125 ;
if ( V_104 [ V_122 ] )
V_83 = F_47 ( V_104 [ V_122 ] ) ;
if ( V_83 != V_84 && V_81 > 1 )
goto V_121;
if ( V_104 [ V_123 ] ) {
if ( V_83 != V_84 )
goto V_121;
V_95 = F_47 ( V_104 [ V_123 ] ) * V_124 ;
}
if ( F_53 ( V_92 ) == 0 )
V_92 = F_40 ( V_68 -> V_126 -> V_99 , V_92 ) ;
if ( F_48 ( V_92 ) == 0 )
V_92 = F_40 ( V_92 , 1 ) ;
V_110 = - V_127 ;
V_75 = F_54 ( sizeof( * V_75 ) , V_128 ) ;
if ( V_75 == NULL )
goto V_121;
V_75 -> V_99 = V_99 ;
V_75 -> V_86 = ~ 0U ;
F_43 ( & V_75 -> V_85 , 4 ) ;
V_75 -> V_96 . V_129 = F_42 ;
V_75 -> V_96 . V_130 = ( unsigned long ) V_75 ;
F_55 ( & V_75 -> V_96 ) ;
}
F_56 ( V_68 , & V_75 -> V_93 , & V_107 ) ;
F_57 ( V_68 , & V_75 -> V_82 , & V_109 ) ;
F_58 ( V_68 ) ;
if ( V_104 [ V_114 ] ) {
V_75 -> V_76 = V_76 ;
V_75 -> V_81 = V_81 ;
}
V_75 -> V_83 = V_83 ;
if ( V_104 [ V_131 ] )
V_75 -> V_86 = F_47 ( V_104 [ V_131 ] ) ;
if ( V_104 [ V_132 ] )
V_75 -> V_87 = F_47 ( V_104 [ V_132 ] ) ;
if ( V_104 [ V_133 ] )
V_75 -> V_88 = F_47 ( V_104 [ V_133 ] ) ;
if ( V_104 [ V_134 ] )
V_75 -> V_89 = F_47 ( V_104 [ V_134 ] ) ;
if ( V_104 [ V_135 ] )
V_75 -> V_90 = F_47 ( V_104 [ V_135 ] ) ;
if ( V_92 )
V_75 -> V_92 = V_92 ;
V_75 -> V_95 = V_95 ;
F_59 ( & V_75 -> V_96 ) ;
if ( V_95 )
F_44 ( & V_75 -> V_96 , V_97 + V_95 ) ;
if ( * V_94 == 0 )
F_60 ( & V_75 -> V_136 , & V_72 -> V_137 ) ;
F_61 ( V_68 ) ;
* V_94 = ( unsigned long ) V_75 ;
return 0 ;
V_121:
F_62 ( V_68 , & V_109 ) ;
V_120:
F_63 ( V_68 , & V_107 ) ;
return V_110 ;
}
static void F_64 ( struct V_67 * V_68 , struct V_74 * V_75 )
{
F_65 ( & V_75 -> V_96 ) ;
F_63 ( V_68 , & V_75 -> V_93 ) ;
F_62 ( V_68 , & V_75 -> V_82 ) ;
F_66 ( V_75 ) ;
}
static int F_67 ( struct V_67 * V_68 , unsigned long V_94 )
{
struct V_74 * V_75 = (struct V_74 * ) V_94 ;
F_58 ( V_68 ) ;
F_68 ( & V_75 -> V_136 ) ;
F_61 ( V_68 ) ;
F_64 ( V_68 , V_75 ) ;
return 0 ;
}
static int F_69 ( struct V_67 * V_68 )
{
struct V_71 * V_72 ;
V_72 = F_54 ( sizeof( * V_72 ) , V_128 ) ;
if ( V_72 == NULL )
return - V_127 ;
F_70 ( & V_72 -> V_137 ) ;
V_68 -> V_73 = V_72 ;
return 0 ;
}
static void F_71 ( struct V_67 * V_68 )
{
struct V_71 * V_72 = V_68 -> V_73 ;
struct V_74 * V_75 , * V_138 ;
F_72 (f, next, &head->filters, list) {
F_68 ( & V_75 -> V_136 ) ;
F_64 ( V_68 , V_75 ) ;
}
F_66 ( V_72 ) ;
}
static unsigned long F_73 ( struct V_67 * V_68 , T_1 V_99 )
{
struct V_71 * V_72 = V_68 -> V_73 ;
struct V_74 * V_75 ;
F_36 (f, &head->filters, list)
if ( V_75 -> V_99 == V_99 )
return ( unsigned long ) V_75 ;
return 0 ;
}
static void F_74 ( struct V_67 * V_68 , unsigned long V_75 )
{
}
static int F_75 ( struct V_67 * V_68 , unsigned long V_139 ,
struct V_4 * V_5 , struct V_140 * V_109 )
{
struct V_74 * V_75 = (struct V_74 * ) V_139 ;
struct V_100 * V_141 ;
if ( V_75 == NULL )
return V_5 -> V_142 ;
V_109 -> V_143 = V_75 -> V_99 ;
V_141 = F_76 ( V_5 , V_103 ) ;
if ( V_141 == NULL )
goto V_144;
F_77 ( V_5 , V_114 , V_75 -> V_76 ) ;
F_77 ( V_5 , V_122 , V_75 -> V_83 ) ;
if ( V_75 -> V_86 != ~ 0 || V_75 -> V_87 != 0 ) {
F_77 ( V_5 , V_131 , V_75 -> V_86 ) ;
F_77 ( V_5 , V_132 , V_75 -> V_87 ) ;
}
if ( V_75 -> V_88 )
F_77 ( V_5 , V_133 , V_75 -> V_88 ) ;
if ( V_75 -> V_89 )
F_77 ( V_5 , V_134 , V_75 -> V_89 ) ;
if ( V_75 -> V_90 )
F_77 ( V_5 , V_135 , V_75 -> V_90 ) ;
if ( V_75 -> V_92 )
F_77 ( V_5 , V_113 , V_75 -> V_92 ) ;
if ( V_75 -> V_95 )
F_77 ( V_5 , V_123 , V_75 -> V_95 / V_124 ) ;
if ( F_78 ( V_5 , & V_75 -> V_93 , & V_118 ) < 0 )
goto V_144;
#ifdef F_79
if ( V_75 -> V_82 . V_145 . V_146 &&
F_80 ( V_5 , & V_75 -> V_82 , V_119 ) < 0 )
goto V_144;
#endif
F_81 ( V_5 , V_141 ) ;
if ( F_82 ( V_5 , & V_75 -> V_93 , & V_118 ) < 0 )
goto V_144;
return V_5 -> V_142 ;
V_144:
F_83 ( V_5 , V_141 ) ;
return - 1 ;
}
static void F_84 ( struct V_67 * V_68 , struct V_147 * V_94 )
{
struct V_71 * V_72 = V_68 -> V_73 ;
struct V_74 * V_75 ;
F_36 (f, &head->filters, list) {
if ( V_94 -> V_148 < V_94 -> V_149 )
goto V_149;
if ( V_94 -> V_150 ( V_68 , ( unsigned long ) V_75 , V_94 ) < 0 ) {
V_94 -> V_151 = 1 ;
break;
}
V_149:
V_94 -> V_148 ++ ;
}
}
static int T_2 F_85 ( void )
{
return F_86 ( & V_152 ) ;
}
static void T_3 F_87 ( void )
{
F_88 ( & V_152 ) ;
}
