static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_8 , V_9 ) -> V_10 ;
}
static inline
struct V_11 * F_4 ( struct V_12 * V_13 )
{
return F_2 ( V_13 , struct V_11 , V_13 ) ;
}
static inline
struct V_11 * F_5 (
struct V_1 * V_14 )
{
return F_6 ( & V_14 -> V_15 ,
struct V_11 , V_16 ) ;
}
static int F_7 ( struct V_1 * V_14 , int V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 = V_14 -> V_4 . V_20 -> V_21 ;
T_1 * V_22 ;
T_2 V_23 ;
T_2 V_24 ;
int V_25 ;
#ifdef F_8
struct V_5 * V_10 = F_3 ( V_14 -> V_4 . V_20 ) ;
#endif
F_9 ( V_21 , L_1 , V_14 -> V_26 ) ;
V_19 = F_10 ( V_21 ,
( V_17 + 1 ) * sizeof( struct V_18 ) ,
& V_23 , V_27 ) ;
if ( ! V_19 )
return - V_28 ;
V_14 -> V_17 = V_17 ;
V_14 -> V_23 = V_23 ;
V_14 -> V_29 = V_19 ;
F_9 ( V_21 , L_2 ,
V_19 , ( unsigned long long ) V_23 ) ;
V_25 = ( ( V_17 + 1 ) >= V_30 ) ?
( V_17 + 1 ) : V_30 ;
V_25 = F_11 ( V_25 ) ;
V_22 = F_10 ( V_21 ,
V_25 * sizeof( struct V_31 ) ,
& V_24 , V_27 ) ;
if ( ! V_22 ) {
F_12 ( V_21 ,
( V_17 + 1 ) * sizeof( struct V_18 ) ,
V_19 , V_23 ) ;
V_14 -> V_29 = NULL ;
return - V_28 ;
}
V_14 -> V_24 = V_24 ;
V_14 -> V_32 = V_22 ;
V_14 -> V_25 = V_25 ;
F_9 ( V_21 ,
L_3 ,
V_22 , ( unsigned long long ) V_24 , V_25 ) ;
V_19 [ V_17 ] . V_33 = F_13 ( V_34 << 29 ) ;
V_19 [ V_17 ] . V_35 = F_13 ( ( T_1 ) V_23 &
V_36 ) ;
V_19 [ V_17 ] . V_37 = F_13 ( ( T_1 ) V_23 >> 32 ) ;
F_14 ( ( ( T_1 ) V_23 >> 32 ) ,
V_14 -> V_38 + V_39 ) ;
F_14 ( ( ( T_1 ) V_23 & V_36 ) ,
V_14 -> V_38 + V_40 ) ;
F_14 ( ( ( T_1 ) V_24 >> 32 ) ,
V_14 -> V_38 + V_41 ) ;
F_14 ( ( ( T_1 ) V_24 & V_42 ) ,
V_14 -> V_38 + V_43 ) ;
F_14 ( F_15 ( V_25 ) ,
V_14 -> V_38 + V_44 ) ;
F_14 ( V_45 ,
V_14 -> V_38 + V_46 ) ;
F_16 ( V_14 -> V_38 + V_46 ) ;
#ifdef F_8
if ( V_10 -> V_47 & V_48 ) {
int V_49 , V_50 ;
V_50 = V_51 + V_14 -> V_26 ;
V_49 = F_17 ( V_10 -> V_52 [ V_50 ] . V_53 , V_54 , 0 ,
V_10 -> V_52 [ V_50 ] . V_55 , ( void * ) V_14 ) ;
if ( V_49 ) {
F_9 ( V_21 , L_4 ,
V_14 -> V_26 ) ;
goto V_56;
}
V_50 = V_57 + V_14 -> V_26 ;
V_49 = F_17 ( V_10 -> V_52 [ V_50 ] . V_53 , V_54 , 0 ,
V_10 -> V_52 [ V_50 ] . V_55 , ( void * ) V_14 ) ;
if ( V_49 ) {
F_9 ( V_21 , L_5 ,
V_14 -> V_26 ) ;
F_18 (
V_10 -> V_52 [ V_51 +
V_14 -> V_26 ] . V_53 ,
( void * ) V_14 ) ;
}
V_56:
if ( V_49 ) {
F_12 ( V_21 ,
( V_17 + 1 ) * sizeof( struct V_18 ) ,
V_19 , V_23 ) ;
V_14 -> V_29 = NULL ;
F_12 ( V_21 ,
V_25 * sizeof( struct V_31 ) ,
V_22 , V_24 ) ;
V_14 -> V_32 = NULL ;
return - V_58 ;
}
}
#endif
F_14 ( V_59 , V_14 -> V_38 + V_60 ) ;
F_16 ( V_14 -> V_38 + V_60 ) ;
V_14 -> V_61 = V_14 -> V_62 = 0 ;
V_14 -> V_63 = 0 ;
F_19 ( 10 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_14 )
{
T_3 V_64 ;
#ifdef F_8
struct V_5 * V_10 = F_3 ( V_14 -> V_4 . V_20 ) ;
#endif
if ( V_14 -> V_29 == NULL )
return 0 ;
V_64 = F_16 ( V_14 -> V_38 + V_65 ) ;
if ( V_64 & V_66 )
return - V_67 ;
F_14 ( V_59 , V_14 -> V_38 + V_60 ) ;
#ifdef F_8
if ( V_10 -> V_47 & V_48 ) {
F_18 ( V_10 -> V_52 [ V_51 +
V_14 -> V_26 ] . V_53 , ( void * ) V_14 ) ;
F_18 ( V_10 -> V_52 [ V_57 +
V_14 -> V_26 ] . V_53 , ( void * ) V_14 ) ;
}
#endif
F_12 ( V_14 -> V_4 . V_20 -> V_21 ,
( V_14 -> V_17 + 1 ) * sizeof( struct V_18 ) ,
V_14 -> V_29 , V_14 -> V_23 ) ;
V_14 -> V_29 = NULL ;
F_12 ( V_14 -> V_4 . V_20 -> V_21 ,
V_14 -> V_25 * sizeof( struct V_31 ) ,
V_14 -> V_32 , V_14 -> V_24 ) ;
V_14 -> V_32 = NULL ;
return 0 ;
}
static void
F_21 ( struct V_1 * V_14 , int V_68 )
{
if ( V_68 ) {
F_14 ( V_45 ,
V_14 -> V_38 + V_46 ) ;
F_16 ( V_14 -> V_38 + V_46 ) ;
F_14 ( V_45 ,
V_14 -> V_38 + V_69 ) ;
} else {
F_14 ( 0 , V_14 -> V_38 + V_69 ) ;
F_14 ( V_45 ,
V_14 -> V_38 + V_46 ) ;
}
}
static bool F_22 ( struct V_1 * V_14 )
{
T_3 V_70 ;
V_70 = F_16 ( V_14 -> V_38 + V_65 ) ;
return ( ( V_70 & V_66 ) == 0 ) ;
}
void F_23 ( struct V_1 * V_14 )
{
F_14 ( 0 , V_14 -> V_38 + V_69 ) ;
if ( V_14 -> V_71 )
F_24 ( & V_14 -> V_72 ) ;
}
static T_4 V_54 ( int V_73 , void * V_74 )
{
struct V_1 * V_14 = V_74 ;
F_23 ( V_14 ) ;
return V_75 ;
}
static void F_25 ( struct V_1 * V_14 )
{
if ( ! F_22 ( V_14 ) ) {
F_26 ( V_14 -> V_4 . V_20 -> V_21 ,
L_6 ) ;
return;
}
if ( V_14 -> V_61 == V_14 -> V_62 ) {
F_26 ( V_14 -> V_4 . V_20 -> V_21 ,
L_7 ) ;
return;
}
F_9 ( V_14 -> V_4 . V_20 -> V_21 ,
L_8 , V_76 , V_14 -> V_26 ,
V_14 -> V_62 ) ;
F_14 ( V_14 -> V_62 ,
V_14 -> V_38 + V_77 ) ;
F_16 ( V_14 -> V_38 + V_77 ) ;
V_14 -> V_61 = V_14 -> V_62 ;
}
static int
F_27 ( struct V_11 * V_78 ,
struct V_18 * V_19 ,
struct V_79 * V_80 , T_3 V_81 )
{
T_1 V_82 ;
if ( V_19 == NULL )
return - V_83 ;
V_19 -> V_33 = F_13 ( ( V_84 << 29 ) |
( V_78 -> V_85 << 19 ) | V_78 -> V_86 ) ;
V_19 -> V_87 = F_13 ( ( ( V_78 -> V_82 & 0x3 ) << 30 ) |
( V_81 << 26 ) ) ;
V_82 = ( V_78 -> V_82 >> 2 ) |
( ( T_1 ) ( V_78 -> V_88 & 0x3 ) << 62 ) ;
V_19 -> V_89 = F_13 ( V_82 & 0xffffffff ) ;
V_19 -> V_90 = F_13 ( V_82 >> 32 ) ;
V_19 -> V_91 . V_92 = F_13 (
( T_1 ) F_28 ( V_80 ) & 0xffffffff ) ;
V_19 -> V_91 . V_93 = F_13 ( ( T_1 ) F_28 ( V_80 ) >> 32 ) ;
V_19 -> V_91 . V_94 = 0 ;
V_19 -> V_91 . V_95 = 0 ;
return 0 ;
}
static int
F_29 ( struct V_18 * V_19 , T_3 V_87 , bool V_96 )
{
if ( V_19 == NULL )
return - V_83 ;
if ( V_96 )
V_19 -> V_33 |= F_13 ( V_97 ) ;
V_19 -> V_87 |= F_13 ( V_87 & V_98 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_14 ,
struct V_11 * V_78 )
{
struct V_12 * V_13 = & V_78 -> V_13 ;
T_5 V_99 = V_13 -> V_99 ;
void * V_100 = V_13 -> V_101 ;
F_31 ( & V_78 -> V_16 , & V_14 -> V_102 ) ;
if ( V_99 )
V_99 ( V_100 ) ;
}
static void F_32 ( struct V_1 * V_14 )
{
T_3 V_103 ;
T_1 * V_22 ;
int V_104 , V_105 ;
V_103 = V_14 -> V_63 ;
V_22 = V_14 -> V_32 ;
V_105 = V_103 * 8 ;
while ( V_22 [ V_105 ] ) {
for ( V_104 = 0 ; V_104 < 8 && V_22 [ V_105 ] ; V_104 ++ , V_105 ++ )
V_22 [ V_105 ] = 0 ;
++ V_103 ;
V_103 %= V_14 -> V_25 ;
V_105 = V_103 * 8 ;
}
F_14 ( V_103 , V_14 -> V_38 + V_106 ) ;
V_14 -> V_63 = V_103 ;
}
static int F_33 ( struct V_11 * V_78 )
{
struct V_2 * V_4 = V_78 -> V_13 . V_3 ;
struct V_1 * V_14 = F_1 ( V_4 ) ;
T_3 V_81 ;
T_1 V_82 ;
T_2 V_107 ;
T_3 V_87 ;
struct V_79 * V_80 ;
unsigned int V_104 ;
int V_108 = 0 ;
struct V_18 * V_19 = NULL ;
T_3 V_50 , V_109 ;
T_3 V_110 = 0 ;
if ( ! F_22 ( V_14 ) ) {
F_26 ( V_14 -> V_4 . V_20 -> V_21 ,
L_9 ) ;
return - V_58 ;
}
V_82 = V_78 -> V_82 ;
V_107 = - 1 ;
V_87 = 0 ;
V_81 = F_34 ( V_14 -> V_4 . V_20 ) -> V_81 ;
V_109 = F_16 ( V_14 -> V_38 + V_111 ) ;
V_109 %= ( V_14 -> V_17 + 1 ) ;
V_50 = V_14 -> V_62 % ( V_14 -> V_17 + 1 ) ;
if ( V_50 == V_14 -> V_17 ) {
V_50 = 0 ;
V_110 ++ ;
}
F_9 ( V_4 -> V_20 -> V_21 , L_10 ,
V_76 , V_109 , V_50 ) ;
F_35 (desc->sg, sg, desc->sg_len, i) {
F_9 ( V_4 -> V_20 -> V_21 , L_11 ,
V_104 , V_78 -> V_112 ,
( unsigned long long ) F_28 ( V_80 ) , F_36 ( V_80 ) ) ;
if ( F_36 ( V_80 ) > V_113 ) {
F_26 ( V_4 -> V_20 -> V_21 ,
L_12 , V_76 , V_104 ) ;
V_108 = - V_83 ;
break;
}
if ( V_107 == F_28 ( V_80 ) &&
V_87 + F_36 ( V_80 ) <= V_113 ) {
V_87 += F_36 ( V_80 ) ;
goto V_114;
} else if ( V_107 != - 1 ) {
F_29 ( V_19 , V_87 , 0 ) ;
F_9 ( V_4 -> V_20 -> V_21 ,
L_13 ,
V_76 , V_87 ) ;
}
V_78 -> V_82 = V_82 ;
if ( V_104 && V_50 == V_109 ) {
F_9 ( V_4 -> V_20 -> V_21 ,
L_14 ,
V_76 , V_104 ) ;
V_78 -> V_80 = V_80 ;
V_78 -> V_112 -= V_104 ;
break;
}
V_19 = & ( (struct V_18 * ) V_14 -> V_29 ) [ V_50 ] ;
V_108 = F_27 ( V_78 , V_19 , V_80 , V_81 ) ;
if ( V_108 ) {
F_26 ( V_4 -> V_20 -> V_21 ,
L_15 , V_108 ) ;
break;
}
F_9 ( V_4 -> V_20 -> V_21 , L_16 ,
V_19 , V_78 -> V_86 , V_78 -> V_82 ) ;
V_107 = F_28 ( V_80 ) ;
V_87 = F_36 ( V_80 ) ;
V_110 ++ ;
if ( ++ V_50 == V_14 -> V_17 ) {
V_50 = 0 ;
V_110 ++ ;
}
V_114:
if ( F_37 ( V_80 ) ) {
F_29 ( V_19 , V_87 , 0 ) ;
F_9 ( V_4 -> V_20 -> V_21 , L_17 ,
V_76 , V_87 ) ;
V_78 -> V_112 = 0 ;
} else {
V_82 += F_36 ( V_80 ) ;
V_107 += F_36 ( V_80 ) ;
}
}
if ( ! V_108 )
V_14 -> V_62 += V_110 ;
return V_108 ;
}
static void F_38 ( struct V_1 * V_14 )
{
struct V_11 * V_78 ;
int V_108 ;
F_9 ( V_14 -> V_4 . V_20 -> V_21 , L_18 , V_76 ) ;
if ( ! F_39 ( & V_14 -> V_115 ) )
F_40 ( & V_14 -> V_115 , & V_14 -> V_15 ) ;
if ( ! F_39 ( & V_14 -> V_15 ) ) {
V_78 = F_5 ( V_14 ) ;
V_108 = F_33 ( V_78 ) ;
if ( ! V_108 )
F_25 ( V_14 ) ;
else {
F_30 ( V_14 , V_78 ) ;
F_9 ( V_14 -> V_4 . V_20 -> V_21 ,
L_19 ,
V_108 ) ;
}
}
F_9 ( V_14 -> V_4 . V_20 -> V_21 , L_20 , V_76 ) ;
}
static void F_41 ( unsigned long V_116 )
{
struct V_1 * V_14 = (struct V_1 * ) V_116 ;
T_3 V_117 , V_118 ;
V_117 = F_16 ( V_14 -> V_38 + V_46 ) ;
F_9 ( V_14 -> V_4 . V_20 -> V_21 , L_21 ,
V_76 , V_14 -> V_26 , V_117 ) ;
F_14 ( V_117 , V_14 -> V_38 + V_46 ) ;
if ( V_117 & V_119 ) {
V_118 = F_16 ( V_14 -> V_38 + V_65 ) ;
F_26 ( V_14 -> V_4 . V_20 -> V_21 ,
L_22 ,
V_76 , V_14 -> V_26 , V_118 ) ;
}
if ( V_117 & V_120 ) {
F_26 ( V_14 -> V_4 . V_20 -> V_21 ,
L_23 ,
V_76 , V_14 -> V_26 ) ;
}
if ( V_117 & ( V_121 | V_122 ) ) {
struct V_11 * V_78 ;
F_32 ( V_14 ) ;
F_42 ( & V_14 -> V_123 ) ;
V_78 = F_5 ( V_14 ) ;
if ( V_78 -> V_112 == 0 ) {
T_5 V_99 = NULL ;
void * V_100 = NULL ;
V_78 -> V_124 = V_125 ;
F_43 ( & V_78 -> V_13 ) ;
if ( V_78 -> V_13 . V_47 & V_126 ) {
V_99 = V_78 -> V_13 . V_99 ;
V_100 = V_78 -> V_13 . V_101 ;
}
F_31 ( & V_78 -> V_16 , & V_14 -> V_102 ) ;
F_44 ( & V_14 -> V_123 ) ;
if ( V_99 )
V_99 ( V_100 ) ;
F_42 ( & V_14 -> V_123 ) ;
}
F_38 ( V_14 ) ;
F_44 ( & V_14 -> V_123 ) ;
}
F_14 ( V_45 , V_14 -> V_38 + V_69 ) ;
}
static T_6 F_45 ( struct V_12 * V_13 )
{
struct V_11 * V_78 = F_4 ( V_13 ) ;
struct V_1 * V_14 = F_1 ( V_13 -> V_3 ) ;
T_6 V_127 ;
if ( ! F_39 ( & V_78 -> V_16 ) ) {
F_26 ( V_14 -> V_4 . V_20 -> V_21 ,
L_24 , V_76 , V_13 ) ;
return - V_58 ;
}
F_46 ( & V_14 -> V_123 ) ;
if ( ! V_14 -> V_71 ) {
F_47 ( & V_14 -> V_123 ) ;
return - V_128 ;
}
V_127 = F_48 ( V_13 ) ;
V_78 -> V_124 = V_129 ;
F_49 ( & V_78 -> V_16 , & V_14 -> V_115 ) ;
F_47 ( & V_14 -> V_123 ) ;
return V_127 ;
}
static int F_50 ( struct V_2 * V_4 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_11 * V_78 = NULL ;
int V_104 ;
F_9 ( V_4 -> V_20 -> V_21 , L_25 ,
V_76 , V_14 -> V_26 ) ;
if ( V_14 -> V_29 )
return V_130 ;
if ( F_7 ( V_14 , V_131 ) ) {
F_26 ( V_4 -> V_20 -> V_21 , L_26
L_27 , V_14 -> V_26 ) ;
return - V_128 ;
}
V_78 = F_51 ( V_130 , sizeof( struct V_11 ) ,
V_27 ) ;
if ( ! V_78 ) {
F_26 ( V_4 -> V_20 -> V_21 ,
L_28 ) ;
F_20 ( V_14 ) ;
return - V_28 ;
}
V_14 -> V_132 = V_78 ;
for ( V_104 = 0 ; V_104 < V_130 ; V_104 ++ ) {
F_52 ( & V_78 [ V_104 ] . V_13 , V_4 ) ;
V_78 [ V_104 ] . V_13 . V_133 = F_45 ;
V_78 [ V_104 ] . V_13 . V_47 = V_134 ;
F_53 ( & V_78 [ V_104 ] . V_16 , & V_14 -> V_102 ) ;
}
F_54 ( V_4 ) ;
V_14 -> V_71 = true ;
F_21 ( V_14 , 1 ) ;
return V_130 ;
}
static void F_55 ( struct V_1 * V_14 )
{
struct V_5 * V_10 = F_3 ( V_14 -> V_4 . V_20 ) ;
#ifdef F_8
if ( V_10 -> V_47 & V_48 ) {
F_56 ( V_10 -> V_52 [ V_51 +
V_14 -> V_26 ] . V_53 ) ;
F_56 ( V_10 -> V_52 [ V_57 +
V_14 -> V_26 ] . V_53 ) ;
} else
#endif
F_56 ( V_10 -> V_135 -> V_73 ) ;
}
static void F_57 ( struct V_2 * V_4 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
F_9 ( V_4 -> V_20 -> V_21 , L_25 ,
V_76 , V_14 -> V_26 ) ;
if ( V_14 -> V_29 == NULL )
return;
F_58 ( ! F_39 ( & V_14 -> V_15 ) ) ;
F_58 ( ! F_39 ( & V_14 -> V_115 ) ) ;
F_21 ( V_14 , 0 ) ;
V_14 -> V_71 = false ;
F_55 ( V_14 ) ;
F_59 ( & V_14 -> V_72 ) ;
F_60 ( & V_14 -> V_102 ) ;
F_61 ( V_14 -> V_132 ) ;
F_20 ( V_14 ) ;
}
static
enum V_136 F_62 ( struct V_2 * V_4 , T_6 V_127 ,
struct V_137 * V_138 )
{
return F_63 ( V_4 , V_127 , V_138 ) ;
}
static void F_64 ( struct V_2 * V_4 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
F_9 ( V_4 -> V_20 -> V_21 , L_18 , V_76 ) ;
if ( F_22 ( V_14 ) && V_14 -> V_71 ) {
F_46 ( & V_14 -> V_123 ) ;
F_38 ( V_14 ) ;
F_47 ( & V_14 -> V_123 ) ;
}
}
static
struct V_12 * F_65 ( struct V_2 * V_4 ,
struct V_79 * V_139 , unsigned int V_112 ,
enum V_140 V_141 , unsigned long V_47 ,
void * V_142 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_11 * V_78 , * V_143 ;
struct V_144 * V_145 = V_142 ;
enum V_146 V_85 ;
struct V_12 * V_13 = NULL ;
if ( ! V_139 || ! V_112 ) {
F_26 ( V_4 -> V_20 -> V_21 , L_29 , V_76 ) ;
return NULL ;
}
F_9 ( V_4 -> V_20 -> V_21 , L_30 , V_76 ,
( V_141 == V_147 ) ? L_31 : L_32 ) ;
if ( V_141 == V_147 )
V_85 = V_148 ;
else if ( V_141 == V_149 ) {
switch ( V_145 -> V_150 ) {
case V_151 :
V_85 = V_152 ;
break;
case V_153 :
V_85 = V_154 ;
break;
case V_155 :
default:
V_85 = V_156 ;
break;
}
} else {
F_26 ( V_4 -> V_20 -> V_21 ,
L_33 , V_76 ) ;
return NULL ;
}
F_46 ( & V_14 -> V_123 ) ;
F_66 (desc, _d, &bdma_chan->free_list, desc_node) {
if ( F_67 ( & V_78 -> V_13 ) ) {
F_68 ( & V_78 -> V_16 ) ;
V_78 -> V_86 = V_145 -> V_86 ;
V_78 -> V_82 = V_145 -> V_82 ;
V_78 -> V_88 = 0 ;
V_78 -> V_85 = V_85 ;
V_78 -> V_112 = V_112 ;
V_78 -> V_80 = V_139 ;
V_13 = & V_78 -> V_13 ;
V_13 -> V_47 = V_47 ;
break;
}
}
F_47 ( & V_14 -> V_123 ) ;
return V_13 ;
}
static int F_69 ( struct V_2 * V_4 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_11 * V_78 , * V_143 ;
T_3 V_117 ;
F_70 ( V_157 ) ;
F_9 ( V_4 -> V_20 -> V_21 , L_34 , V_76 ) ;
F_46 ( & V_14 -> V_123 ) ;
V_14 -> V_71 = false ;
if ( ! F_22 ( V_14 ) ) {
F_14 ( V_158 ,
V_14 -> V_38 + V_60 ) ;
do {
V_117 = F_16 ( V_14 -> V_38 + V_46 ) ;
} while ( ( V_117 & V_159 ) == 0 );
}
F_40 ( & V_14 -> V_15 , & V_157 ) ;
F_40 ( & V_14 -> V_115 , & V_157 ) ;
F_66 (desc, _d, &list, desc_node)
F_30 ( V_14 , V_78 ) ;
F_47 ( & V_14 -> V_123 ) ;
return 0 ;
}
int F_71 ( struct V_5 * V_10 )
{
int V_104 ;
int V_160 = 0 ;
int V_108 ;
struct V_8 * V_161 = V_10 -> V_161 ;
F_60 ( & V_161 -> V_9 . V_162 ) ;
for ( V_104 = 0 ; V_104 < V_163 ; V_104 ++ ) {
struct V_1 * V_14 = & V_10 -> V_164 [ V_104 ] ;
if ( V_104 == V_165 )
continue;
V_14 -> V_38 = V_10 -> V_38 + F_72 ( V_104 ) ;
V_14 -> V_4 . V_20 = & V_161 -> V_9 ;
V_14 -> V_4 . V_127 = 1 ;
V_14 -> V_4 . V_166 = V_104 ;
V_14 -> V_26 = V_104 ;
V_14 -> V_71 = false ;
F_73 ( & V_14 -> V_123 ) ;
F_60 ( & V_14 -> V_15 ) ;
F_60 ( & V_14 -> V_115 ) ;
F_60 ( & V_14 -> V_102 ) ;
F_74 ( & V_14 -> V_72 , F_41 ,
( unsigned long ) V_14 ) ;
F_49 ( & V_14 -> V_4 . V_167 ,
& V_161 -> V_9 . V_162 ) ;
V_160 ++ ;
}
V_161 -> V_9 . V_168 = V_160 ;
F_75 ( V_161 -> V_9 . V_169 ) ;
F_76 ( V_170 , V_161 -> V_9 . V_169 ) ;
F_76 ( V_171 , V_161 -> V_9 . V_169 ) ;
V_161 -> V_9 . V_21 = & V_10 -> V_135 -> V_21 ;
V_161 -> V_9 . V_172 = F_50 ;
V_161 -> V_9 . V_173 = F_57 ;
V_161 -> V_9 . V_174 = F_62 ;
V_161 -> V_9 . V_175 = F_64 ;
V_161 -> V_9 . V_176 = F_65 ;
V_161 -> V_9 . V_177 = F_69 ;
V_108 = F_77 ( & V_161 -> V_9 ) ;
if ( V_108 )
F_26 ( & V_10 -> V_135 -> V_21 , L_35 ) ;
return V_108 ;
}
