static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 , T_1 V_5 , const char * V_6 )
{
const T_2 * V_7 = V_2 -> V_8 + V_3 * V_4 ;
if ( V_7 > V_2 -> V_9 -> V_10 + V_2 -> V_9 -> V_11 ) {
F_2 ( V_2 -> V_12 , L_1 ,
V_6 ) ;
return - V_13 ;
}
if ( V_3 * V_4 > V_5 ) {
F_2 ( V_2 -> V_12 ,
L_2 ,
V_6 , V_4 , V_3 , V_5 ) ;
return - V_13 ;
}
return 0 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
const T_2 * V_7 = V_2 -> V_14 ;
if ( V_7 >= V_2 -> V_9 -> V_10 + V_2 -> V_9 -> V_11 )
return 1 ;
return 0 ;
}
static inline unsigned long F_4 ( struct V_1 * V_2 )
{
return ( unsigned long ) ( V_2 -> V_14 - V_2 -> V_9 -> V_10 ) ;
}
static inline unsigned long F_5 ( struct V_1 * V_2 )
{
return ( unsigned long ) ( V_2 -> V_8 - V_2 -> V_9 -> V_10 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
if ( V_16 [ V_18 ] . V_20 == V_17 )
return V_16 [ V_18 ] . V_21 ;
}
return - V_13 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
if ( V_16 [ V_18 ] . V_20 == V_17 )
return V_16 [ V_18 ] . V_22 ;
}
return - V_13 ;
}
static int F_8 ( int V_23 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_9 ( V_24 ) ; V_18 ++ ) {
if ( V_23 == V_24 [ V_18 ] . V_25 )
return V_24 [ V_18 ] . V_26 ;
}
return - V_13 ;
}
static inline void F_10 ( struct V_1 * V_2 ,
struct V_27 * V_28 , int V_29 )
{
F_2 ( V_2 -> V_12 ,
L_3 ,
V_28 -> V_30 . V_31 , V_28 -> V_30 . V_32 , V_28 -> V_30 . V_33 , V_29 ,
F_5 ( V_2 ) ) ;
}
static inline void F_11 ( struct V_1 * V_2 ,
struct V_27 * V_28 , const char * V_34 )
{
F_2 ( V_2 -> V_12 ,
L_4 ,
V_34 , V_28 -> V_30 . V_31 , V_28 -> V_30 . V_32 , V_28 -> V_30 . V_33 ,
F_5 ( V_2 ) ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
int V_36 = 0 ;
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_38 )
V_36 = V_2 -> V_30 -> V_38 ( V_2 -> V_37 , V_28 ) ;
else {
F_2 ( V_2 -> V_12 , L_5 ,
V_28 -> V_39 ) ;
return - V_13 ;
}
if ( V_36 < 0 )
F_2 ( V_2 -> V_12 ,
L_6 ,
F_4 ( V_2 ) ,
F_4 ( V_2 ) ,
V_28 -> type , V_28 -> V_39 ) ;
return V_36 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
if ( V_2 -> V_40 != V_41 )
return 0 ;
return F_12 ( V_2 , V_28 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_42 * V_43 , struct V_44 * V_45 )
{
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_46 )
return V_2 -> V_30 -> V_46 ( V_2 -> V_37 , V_43 , V_45 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_42 * V_43 , struct V_44 * V_45 )
{
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_47 )
return V_2 -> V_30 -> V_47 ( V_2 -> V_37 , V_43 , V_45 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_50 )
return V_2 -> V_30 -> V_50 ( V_2 -> V_37 , V_49 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_53 )
return V_2 -> V_30 -> V_53 ( V_2 -> V_37 , V_52 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_54 )
V_2 -> V_30 -> V_54 ( V_2 -> V_37 ) ;
}
static int F_19 ( struct V_55 * V_56 , struct V_57 * V_12 ,
const struct V_58 * V_59 , const char * V_60 ,
void * V_10 , struct V_61 * * V_62 )
{
int V_63 ;
* V_62 = F_20 ( V_59 , V_10 , V_59 -> V_34 , V_60 ) ;
if ( * V_62 == NULL ) {
F_2 ( V_12 , L_7 ,
V_59 -> V_34 ) ;
return - V_64 ;
}
V_63 = F_21 ( V_56 , * V_62 ) ;
if ( V_63 < 0 ) {
F_2 ( V_12 , L_8 ,
V_59 -> V_34 , V_63 ) ;
return V_63 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_58 * V_65 , struct V_61 * * V_62 )
{
struct V_66 * V_37 = V_2 -> V_37 ;
return F_19 ( V_37 -> V_56 -> V_55 ,
V_37 -> V_12 , V_65 , NULL , V_37 , V_62 ) ;
}
static void F_23 ( struct V_66 * V_37 ,
struct V_67 * V_68 , int V_40 )
{
struct V_55 * V_56 = V_37 -> V_56 -> V_55 ;
struct V_69 * V_70 =
F_24 ( V_68 , struct V_69 , V_68 ) ;
const unsigned int * V_71 = NULL ;
if ( V_40 != V_72 )
return;
if ( V_68 -> V_30 && V_68 -> V_30 -> V_73 )
V_68 -> V_30 -> V_73 ( V_37 , V_68 ) ;
if ( V_70 -> V_68 . V_74 . V_62 -> V_75 . V_71 )
V_71 = V_70 -> V_68 . V_74 . V_62 -> V_75 . V_71 ;
F_25 ( V_56 , V_70 -> V_68 . V_74 . V_62 ) ;
F_26 ( & V_70 -> V_68 . V_76 ) ;
F_27 ( V_70 ) ;
F_27 ( V_71 ) ;
}
static void F_28 ( struct V_66 * V_37 ,
struct V_67 * V_68 , int V_40 )
{
struct V_55 * V_56 = V_37 -> V_56 -> V_55 ;
struct V_77 * V_78 = F_24 ( V_68 , struct V_77 , V_68 ) ;
int V_18 ;
if ( V_40 != V_72 )
return;
if ( V_68 -> V_30 && V_68 -> V_30 -> V_73 )
V_68 -> V_30 -> V_73 ( V_37 , V_68 ) ;
F_25 ( V_56 , V_78 -> V_68 . V_74 . V_62 ) ;
F_26 ( & V_78 -> V_68 . V_76 ) ;
F_27 ( V_78 -> V_68 . V_74 . V_79 ) ;
for ( V_18 = 0 ; V_18 < V_78 -> V_80 ; V_18 ++ )
F_27 ( V_78 -> V_68 . V_74 . V_81 [ V_18 ] ) ;
F_27 ( V_78 ) ;
}
static void F_29 ( struct V_66 * V_37 ,
struct V_67 * V_68 , int V_40 )
{
struct V_55 * V_56 = V_37 -> V_56 -> V_55 ;
struct V_82 * V_83 =
F_24 ( V_68 , struct V_82 , V_68 ) ;
if ( V_40 != V_72 )
return;
if ( V_68 -> V_30 && V_68 -> V_30 -> V_73 )
V_68 -> V_30 -> V_73 ( V_37 , V_68 ) ;
F_25 ( V_56 , V_83 -> V_68 . V_74 . V_62 ) ;
F_26 ( & V_83 -> V_68 . V_76 ) ;
F_27 ( V_83 ) ;
}
static void F_30 ( struct V_66 * V_37 ,
struct V_67 * V_68 , int V_40 )
{
struct V_55 * V_56 = V_37 -> V_56 -> V_55 ;
struct V_42 * V_43 =
F_24 ( V_68 , struct V_42 , V_68 ) ;
int V_18 ;
if ( V_40 != V_84 )
return;
if ( V_68 -> V_30 && V_68 -> V_30 -> V_85 )
V_68 -> V_30 -> V_85 ( V_37 , V_68 ) ;
if ( V_68 -> V_86 . V_87 == V_88 ) {
for ( V_18 = 0 ; V_18 < V_43 -> V_89 ; V_18 ++ ) {
struct V_61 * V_62 = V_43 -> V_90 [ V_18 ] ;
struct V_77 * V_78 =
(struct V_77 * ) V_62 -> V_91 ;
int V_92 ;
F_25 ( V_56 , V_62 ) ;
F_27 ( V_78 -> V_68 . V_74 . V_79 ) ;
for ( V_92 = 0 ; V_92 < V_78 -> V_80 ; V_92 ++ )
F_27 ( V_78 -> V_68 . V_74 . V_81 [ V_92 ] ) ;
F_27 ( V_78 ) ;
}
F_27 ( V_43 -> V_93 ) ;
} else {
for ( V_18 = 0 ; V_18 < V_43 -> V_89 ; V_18 ++ ) {
struct V_61 * V_62 = V_43 -> V_90 [ V_18 ] ;
if ( V_68 -> V_86 . V_87
== V_94 )
F_27 ( V_62 -> V_75 . V_71 ) ;
F_27 ( ( void * ) V_62 -> V_91 ) ;
F_25 ( V_56 , V_62 ) ;
}
F_27 ( V_43 -> V_93 ) ;
}
}
static void F_31 ( struct V_66 * V_37 ,
struct V_67 * V_68 , int V_40 )
{
struct V_48 * V_49 =
F_24 ( V_68 , struct V_48 , V_68 ) ;
if ( V_40 != V_95 )
return;
if ( V_68 -> V_30 && V_68 -> V_30 -> V_96 )
V_68 -> V_30 -> V_96 ( V_37 , V_68 ) ;
F_27 ( V_49 -> V_34 ) ;
F_26 ( & V_68 -> V_76 ) ;
F_27 ( V_49 ) ;
}
static void F_32 ( struct V_66 * V_37 ,
struct V_67 * V_68 , int V_40 )
{
struct V_51 * V_52 =
F_24 ( V_68 , struct V_51 , V_68 ) ;
if ( V_40 != V_95 )
return;
if ( V_68 -> V_30 && V_68 -> V_30 -> V_97 )
V_68 -> V_30 -> V_97 ( V_37 , V_68 ) ;
F_27 ( V_52 -> V_34 ) ;
F_27 ( V_52 -> V_98 ) ;
F_27 ( V_52 -> V_99 ) ;
F_26 ( & V_68 -> V_76 ) ;
F_33 ( V_37 -> V_56 , V_52 ) ;
F_27 ( V_52 ) ;
}
static int F_34 ( struct V_27 * V_28 ,
struct V_58 * V_65 ,
const struct V_1 * V_2 )
{
const struct V_100 * V_30 ;
const struct V_101 * V_102 ;
int V_103 , V_18 ;
if ( V_28 -> V_30 . V_33 == V_104
&& V_65 -> V_105 & V_106
&& V_65 -> V_107 & V_108
&& V_65 -> V_107 & V_109 ) {
struct V_82 * V_110 ;
struct V_111 * V_112 ;
V_110 = (struct V_82 * ) V_65 -> V_91 ;
V_112 = F_24 ( V_28 , struct V_111 , V_28 ) ;
V_65 -> V_33 = V_113 ;
V_65 -> V_75 . V_114 = V_115 ;
V_102 = V_2 -> V_116 ;
V_103 = V_2 -> V_117 ;
for ( V_18 = 0 ; V_18 < V_103 ; V_18 ++ ) {
if ( ! V_110 -> V_32 && V_102 [ V_18 ] . V_20 == V_112 -> V_102 . V_32 )
V_110 -> V_32 = V_102 [ V_18 ] . V_32 ;
if ( ! V_110 -> V_31 && V_102 [ V_18 ] . V_20 == V_112 -> V_102 . V_31 )
V_110 -> V_31 = V_102 [ V_18 ] . V_31 ;
}
if ( V_110 -> V_32 && V_110 -> V_31 )
return 0 ;
else
return - V_13 ;
}
V_30 = V_2 -> V_118 ;
V_103 = V_2 -> V_119 ;
for ( V_18 = 0 ; V_18 < V_103 ; V_18 ++ ) {
if ( V_65 -> V_32 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_32 )
V_65 -> V_32 = V_30 [ V_18 ] . V_32 ;
if ( V_65 -> V_31 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_31 )
V_65 -> V_31 = V_30 [ V_18 ] . V_31 ;
if ( V_65 -> V_33 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_33 )
V_65 -> V_33 = V_30 [ V_18 ] . V_33 ;
}
if ( V_65 -> V_32 && V_65 -> V_31 && V_65 -> V_33 )
return 0 ;
V_30 = V_118 ;
V_103 = F_9 ( V_118 ) ;
for ( V_18 = 0 ; V_18 < V_103 ; V_18 ++ ) {
if ( V_65 -> V_32 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_32 )
V_65 -> V_32 = V_30 [ V_18 ] . V_32 ;
if ( V_65 -> V_31 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_31 )
V_65 -> V_31 = V_30 [ V_18 ] . V_31 ;
if ( V_65 -> V_33 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_33 )
V_65 -> V_33 = V_30 [ V_18 ] . V_33 ;
}
if ( V_65 -> V_32 && V_65 -> V_31 && V_65 -> V_33 )
return 0 ;
return - V_13 ;
}
int F_35 ( struct V_42 * V_43 ,
const struct V_120 * V_121 ,
int V_122 , T_3 V_123 )
{
int V_18 ;
V_43 -> V_124 = NULL ;
for ( V_18 = 0 ; V_18 < V_122 ; V_18 ++ ) {
if ( V_123 == V_121 [ V_18 ] . type ) {
V_43 -> V_124 = V_121 [ V_18 ] . V_125 ;
return 0 ;
}
}
return - V_13 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_58 * V_65 , struct V_27 * V_28 )
{
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_126 )
return V_2 -> V_30 -> V_126 ( V_2 -> V_37 , V_65 , V_28 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_58 * V_127 , struct V_128 * V_129 )
{
unsigned int V_130 = 2 * sizeof( unsigned int ) ;
unsigned int * V_71 ;
V_71 = F_38 ( V_130 + 2 * sizeof( unsigned int ) , V_131 ) ;
if ( ! V_71 )
return - V_64 ;
V_71 [ 0 ] = V_132 ;
V_71 [ 1 ] = V_130 ;
V_71 [ 2 ] = V_129 -> V_133 ;
V_71 [ 3 ] = ( V_129 -> V_134 & V_135 )
| ( V_129 -> V_136 ? V_137 : 0 ) ;
V_127 -> V_75 . V_71 = ( void * ) V_71 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_58 * V_127 , struct V_27 * V_138 )
{
struct V_139 * V_140 ;
if ( ! ( V_138 -> V_107 & V_108 ) )
return 0 ;
if ( ! ( V_138 -> V_107 & V_109 ) ) {
V_140 = & V_138 -> V_75 ;
switch ( V_140 -> type ) {
case V_132 :
return F_37 ( V_2 , V_127 ,
& V_140 -> V_129 ) ;
default:
F_40 ( V_2 -> V_12 , L_9 ,
V_140 -> type ) ;
return - V_13 ;
}
}
return 0 ;
}
static inline void F_41 ( struct V_1 * V_2 ,
struct V_58 * V_127 )
{
F_27 ( V_127 -> V_75 . V_71 ) ;
}
static int F_42 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_111 * V_112 ;
struct V_82 * V_110 ;
struct V_58 V_127 ;
int V_18 , V_63 ;
if ( F_1 ( V_2 ,
sizeof( struct V_111 ) , V_4 ,
V_11 , L_10 ) ) {
F_2 ( V_2 -> V_12 , L_11 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_112 = (struct V_111 * ) V_2 -> V_8 ;
if ( F_43 ( V_112 -> V_28 . V_34 , V_141 ) ==
V_141 )
return - V_13 ;
V_110 = F_38 ( sizeof( * V_110 ) , V_131 ) ;
if ( V_110 == NULL )
return - V_64 ;
V_2 -> V_8 += ( sizeof( struct V_111 ) +
V_112 -> V_142 . V_11 ) ;
F_40 ( V_2 -> V_12 ,
L_12 ,
V_112 -> V_28 . V_34 , V_112 -> V_28 . V_107 ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_34 = V_112 -> V_28 . V_34 ;
V_127 . V_91 = ( long ) V_110 ;
V_127 . V_105 = V_106 ;
V_127 . V_107 = V_112 -> V_28 . V_107 ;
V_110 -> V_143 = V_112 -> V_143 ;
V_110 -> V_68 . type = V_144 ;
V_110 -> V_68 . V_30 = V_2 -> V_30 ;
F_44 ( & V_110 -> V_68 . V_76 ) ;
V_63 = F_34 ( & V_112 -> V_28 , & V_127 , V_2 ) ;
if ( V_63 ) {
F_11 ( V_2 , & V_112 -> V_28 , V_112 -> V_28 . V_34 ) ;
F_27 ( V_110 ) ;
continue;
}
V_63 = F_36 ( V_2 , & V_127 ,
(struct V_27 * ) V_112 ) ;
if ( V_63 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_112 -> V_28 . V_34 ) ;
F_27 ( V_110 ) ;
continue;
}
V_63 = F_22 ( V_2 , & V_127 ,
& V_110 -> V_68 . V_74 . V_62 ) ;
if ( V_63 < 0 ) {
F_2 ( V_2 -> V_12 , L_14 ,
V_112 -> V_28 . V_34 ) ;
F_27 ( V_110 ) ;
continue;
}
F_45 ( & V_110 -> V_68 . V_76 , & V_2 -> V_37 -> V_145 ) ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_146 * V_147 ;
struct V_69 * V_70 ;
struct V_58 V_127 ;
int V_18 , V_63 ;
if ( F_1 ( V_2 ,
sizeof( struct V_146 ) ,
V_4 , V_11 , L_15 ) ) {
F_2 ( V_2 -> V_12 , L_16 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_147 = (struct V_146 * ) V_2 -> V_8 ;
if ( F_43 ( V_147 -> V_28 . V_34 , V_141 ) ==
V_141 )
return - V_13 ;
V_70 = F_38 ( sizeof( * V_70 ) , V_131 ) ;
if ( V_70 == NULL )
return - V_64 ;
V_2 -> V_8 += ( sizeof( struct V_146 ) +
V_147 -> V_142 . V_11 ) ;
F_40 ( V_2 -> V_12 ,
L_17 ,
V_147 -> V_28 . V_34 , V_147 -> V_28 . V_107 ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_34 = V_147 -> V_28 . V_34 ;
V_127 . V_91 = ( long ) V_70 ;
V_127 . V_105 = V_106 ;
V_127 . V_107 = V_147 -> V_28 . V_107 ;
V_70 -> V_21 = F_6 ( V_2 , V_147 -> V_148 ,
V_149 ) ;
V_70 -> V_150 = F_6 ( V_2 , V_147 -> V_148 ,
V_151 ) ;
V_70 -> V_22 = F_7 ( V_2 , V_147 -> V_148 ,
V_149 ) ;
V_70 -> V_152 = F_7 ( V_2 , V_147 -> V_148 ,
V_151 ) ;
V_70 -> V_143 = V_147 -> V_143 ;
V_70 -> V_133 = V_147 -> V_133 ;
V_70 -> V_153 = V_147 -> V_153 ;
V_70 -> V_154 = V_147 -> V_154 ;
V_70 -> V_68 . V_29 = V_2 -> V_29 ;
V_70 -> V_68 . V_30 = V_2 -> V_30 ;
V_70 -> V_68 . type = V_155 ;
F_44 ( & V_70 -> V_68 . V_76 ) ;
V_63 = F_34 ( & V_147 -> V_28 , & V_127 , V_2 ) ;
if ( V_63 ) {
F_11 ( V_2 , & V_147 -> V_28 , V_147 -> V_28 . V_34 ) ;
F_27 ( V_70 ) ;
continue;
}
V_63 = F_36 ( V_2 , & V_127 ,
(struct V_27 * ) V_147 ) ;
if ( V_63 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_147 -> V_28 . V_34 ) ;
F_27 ( V_70 ) ;
continue;
}
F_39 ( V_2 , & V_127 , & V_147 -> V_28 ) ;
V_63 = F_22 ( V_2 , & V_127 ,
& V_70 -> V_68 . V_74 . V_62 ) ;
if ( V_63 < 0 ) {
F_2 ( V_2 -> V_12 , L_14 ,
V_147 -> V_28 . V_34 ) ;
F_41 ( V_2 , & V_127 ) ;
F_27 ( V_70 ) ;
continue;
}
F_45 ( & V_70 -> V_68 . V_76 , & V_2 -> V_37 -> V_145 ) ;
}
return 0 ;
}
static int F_47 ( struct V_77 * V_78 ,
struct V_156 * V_157 )
{
int V_18 , V_36 ;
V_78 -> V_68 . V_74 . V_81 =
F_38 ( sizeof( char * ) * V_157 -> V_80 , V_131 ) ;
if ( V_78 -> V_68 . V_74 . V_81 == NULL )
return - V_64 ;
for ( V_18 = 0 ; V_18 < V_157 -> V_80 ; V_18 ++ ) {
if ( F_43 ( V_157 -> V_158 [ V_18 ] , V_141 ) ==
V_141 ) {
V_36 = - V_13 ;
goto V_63;
}
V_78 -> V_68 . V_74 . V_81 [ V_18 ] = F_48 ( V_157 -> V_158 [ V_18 ] , V_131 ) ;
if ( ! V_78 -> V_68 . V_74 . V_81 [ V_18 ] ) {
V_36 = - V_64 ;
goto V_63;
}
}
V_78 -> V_158 = ( const char * const * ) V_78 -> V_68 . V_74 . V_81 ;
return 0 ;
V_63:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_27 ( V_78 -> V_68 . V_74 . V_81 [ V_18 ] ) ;
F_27 ( V_78 -> V_68 . V_74 . V_81 ) ;
return V_36 ;
}
static int F_49 ( struct V_77 * V_78 ,
struct V_156 * V_157 )
{
if ( V_157 -> V_80 > sizeof( * V_157 -> V_159 ) )
return - V_13 ;
V_78 -> V_68 . V_74 . V_79 = F_50 ( V_157 -> V_159 ,
V_157 -> V_80 * sizeof( V_160 ) ,
V_131 ) ;
if ( ! V_78 -> V_68 . V_74 . V_79 )
return - V_64 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_156 * V_157 ;
struct V_77 * V_78 ;
struct V_58 V_127 ;
int V_18 , V_36 , V_63 ;
if ( F_1 ( V_2 ,
sizeof( struct V_156 ) ,
V_4 , V_11 , L_18 ) ) {
F_2 ( V_2 -> V_12 , L_19 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_157 = (struct V_156 * ) V_2 -> V_8 ;
V_2 -> V_8 += ( sizeof( struct V_156 ) +
V_157 -> V_142 . V_11 ) ;
if ( F_43 ( V_157 -> V_28 . V_34 , V_141 ) ==
V_141 )
return - V_13 ;
V_78 = F_38 ( ( sizeof( * V_78 ) ) , V_131 ) ;
if ( V_78 == NULL )
return - V_64 ;
F_40 ( V_2 -> V_12 , L_20 ,
V_157 -> V_28 . V_34 , V_157 -> V_80 ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_34 = V_157 -> V_28 . V_34 ;
V_127 . V_91 = ( long ) V_78 ;
V_127 . V_105 = V_106 ;
V_127 . V_107 = V_157 -> V_28 . V_107 ;
V_78 -> V_21 = F_6 ( V_2 , V_157 -> V_148 , V_149 ) ;
V_78 -> V_161 = F_7 ( V_2 , V_157 -> V_148 ,
V_149 ) ;
V_78 -> V_162 = F_7 ( V_2 , V_157 -> V_148 ,
V_149 ) ;
V_78 -> V_80 = V_157 -> V_80 ;
V_78 -> V_163 = V_157 -> V_163 ;
V_78 -> V_68 . V_29 = V_2 -> V_29 ;
V_78 -> V_68 . type = V_164 ;
V_78 -> V_68 . V_30 = V_2 -> V_30 ;
F_44 ( & V_78 -> V_68 . V_76 ) ;
switch ( V_157 -> V_28 . V_30 . V_33 ) {
case V_165 :
case V_166 :
V_63 = F_49 ( V_78 , V_157 ) ;
if ( V_63 < 0 ) {
F_2 ( V_2 -> V_12 ,
L_21 ,
V_157 -> V_28 . V_34 ) ;
F_27 ( V_78 ) ;
continue;
}
case V_167 :
case V_168 :
case V_169 :
V_63 = F_47 ( V_78 , V_157 ) ;
if ( V_63 < 0 ) {
F_2 ( V_2 -> V_12 ,
L_22 ,
V_157 -> V_28 . V_34 ) ;
F_27 ( V_78 ) ;
continue;
}
break;
default:
F_2 ( V_2 -> V_12 ,
L_23 ,
V_157 -> V_28 . V_30 . V_33 , V_157 -> V_28 . V_34 ) ;
F_27 ( V_78 ) ;
continue;
}
V_63 = F_34 ( & V_157 -> V_28 , & V_127 , V_2 ) ;
if ( V_63 ) {
F_11 ( V_2 , & V_157 -> V_28 , V_157 -> V_28 . V_34 ) ;
F_27 ( V_78 ) ;
continue;
}
V_63 = F_36 ( V_2 , & V_127 ,
(struct V_27 * ) V_157 ) ;
if ( V_63 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_157 -> V_28 . V_34 ) ;
F_27 ( V_78 ) ;
continue;
}
V_36 = F_22 ( V_2 ,
& V_127 , & V_78 -> V_68 . V_74 . V_62 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_12 , L_24 ,
V_157 -> V_28 . V_34 ) ;
F_27 ( V_78 ) ;
continue;
}
F_45 ( & V_78 -> V_68 . V_76 , & V_2 -> V_37 -> V_145 ) ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_27 * V_170 ;
int V_18 ;
if ( V_2 -> V_40 != V_72 ) {
V_2 -> V_8 += V_28 -> V_11 + V_28 -> V_171 ;
return 0 ;
}
F_40 ( V_2 -> V_12 , L_25 , V_28 -> V_4 ,
F_5 ( V_2 ) ) ;
for ( V_18 = 0 ; V_18 < V_28 -> V_4 ; V_18 ++ ) {
V_170 = (struct V_27 * ) V_2 -> V_8 ;
if ( V_170 -> V_11 != sizeof( * V_170 ) ) {
F_2 ( V_2 -> V_12 , L_26 ) ;
return - V_13 ;
}
switch ( V_170 -> V_30 . V_33 ) {
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
F_46 ( V_2 , 1 , V_28 -> V_171 ) ;
break;
case V_167 :
case V_166 :
case V_168 :
case V_169 :
case V_165 :
F_51 ( V_2 , 1 , V_28 -> V_171 ) ;
break;
case V_104 :
F_42 ( V_2 , 1 , V_28 -> V_171 ) ;
break;
default:
F_10 ( V_2 , V_170 , V_18 ) ;
return - V_13 ;
}
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_179 * V_180 = & V_2 -> V_37 -> V_180 ;
struct V_181 V_182 ;
struct V_183 * V_184 ;
int V_4 = V_28 -> V_4 , V_18 ;
if ( V_2 -> V_40 != V_185 ) {
V_2 -> V_8 += V_28 -> V_11 + V_28 -> V_171 ;
return 0 ;
}
if ( F_1 ( V_2 ,
sizeof( struct V_183 ) ,
V_4 , V_28 -> V_171 , L_27 ) ) {
F_2 ( V_2 -> V_12 , L_28 ,
V_4 ) ;
return - V_13 ;
}
F_40 ( V_2 -> V_12 , L_29 , V_4 ,
V_28 -> V_29 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_184 = (struct V_183 * ) V_2 -> V_8 ;
V_2 -> V_8 += sizeof( struct V_183 ) ;
if ( F_43 ( V_184 -> V_186 , V_141 ) ==
V_141 )
return - V_13 ;
if ( F_43 ( V_184 -> V_187 , V_141 ) ==
V_141 )
return - V_13 ;
if ( F_43 ( V_184 -> V_74 , V_141 ) ==
V_141 )
return - V_13 ;
V_182 . V_186 = V_184 -> V_186 ;
V_182 . V_187 = V_184 -> V_187 ;
V_182 . V_188 = NULL ;
if ( F_43 ( V_184 -> V_74 , V_141 ) == 0 )
V_182 . V_74 = NULL ;
else
V_182 . V_74 = V_184 -> V_74 ;
F_54 ( V_180 , & V_182 , 1 ) ;
}
return 0 ;
}
static struct V_58 * F_55 (
struct V_1 * V_2 , int V_89 )
{
struct V_58 * V_127 ;
struct V_69 * V_70 ;
struct V_146 * V_147 ;
int V_18 , V_63 ;
V_127 = F_56 ( V_89 , sizeof( * V_127 ) , V_131 ) ;
if ( V_127 == NULL )
return NULL ;
for ( V_18 = 0 ; V_18 < V_89 ; V_18 ++ ) {
V_147 = (struct V_146 * ) V_2 -> V_8 ;
V_70 = F_38 ( sizeof( * V_70 ) , V_131 ) ;
if ( V_70 == NULL )
goto V_63;
V_2 -> V_8 += ( sizeof( struct V_146 ) +
V_147 -> V_142 . V_11 ) ;
if ( F_43 ( V_147 -> V_28 . V_34 , V_141 ) ==
V_141 )
goto V_189;
F_40 ( V_2 -> V_12 , L_30 ,
V_147 -> V_28 . V_34 , V_18 ) ;
V_127 [ V_18 ] . V_34 = V_147 -> V_28 . V_34 ;
V_127 [ V_18 ] . V_91 = ( long ) V_70 ;
V_127 [ V_18 ] . V_105 = V_106 ;
V_127 [ V_18 ] . V_107 = V_147 -> V_28 . V_107 ;
V_70 -> V_21 = F_6 ( V_2 , V_147 -> V_148 ,
V_149 ) ;
V_70 -> V_150 = F_6 ( V_2 , V_147 -> V_148 ,
V_151 ) ;
V_70 -> V_22 = F_7 ( V_2 , V_147 -> V_148 ,
V_149 ) ;
V_70 -> V_152 = F_7 ( V_2 , V_147 -> V_148 ,
V_151 ) ;
V_70 -> V_143 = V_147 -> V_143 ;
V_70 -> V_133 = V_147 -> V_133 ;
V_70 -> V_153 = V_147 -> V_153 ;
V_70 -> V_154 = V_147 -> V_154 ;
V_70 -> V_68 . V_29 = V_2 -> V_29 ;
F_44 ( & V_70 -> V_68 . V_76 ) ;
V_63 = F_34 ( & V_147 -> V_28 , & V_127 [ V_18 ] , V_2 ) ;
if ( V_63 ) {
F_11 ( V_2 , & V_147 -> V_28 , V_147 -> V_28 . V_34 ) ;
F_27 ( V_70 ) ;
continue;
}
V_63 = F_36 ( V_2 , & V_127 [ V_18 ] ,
(struct V_27 * ) V_147 ) ;
if ( V_63 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_147 -> V_28 . V_34 ) ;
F_27 ( V_70 ) ;
continue;
}
}
return V_127 ;
V_189:
F_27 ( V_70 ) ;
V_63:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_27 ( ( void * ) V_127 [ V_18 ] . V_91 ) ;
F_27 ( V_127 ) ;
return NULL ;
}
static struct V_58 * F_57 (
struct V_1 * V_2 , int V_89 )
{
struct V_58 * V_127 ;
struct V_156 * V_157 ;
struct V_77 * V_78 ;
int V_18 , V_92 , V_63 ;
V_127 = F_56 ( V_89 , sizeof( * V_127 ) , V_131 ) ;
if ( V_127 == NULL )
return NULL ;
for ( V_18 = 0 ; V_18 < V_89 ; V_18 ++ ) {
V_157 = (struct V_156 * ) V_2 -> V_8 ;
if ( F_43 ( V_157 -> V_28 . V_34 , V_141 ) ==
V_141 )
return NULL ;
V_78 = F_38 ( sizeof( * V_78 ) , V_131 ) ;
if ( V_78 == NULL )
goto V_63;
F_40 ( V_2 -> V_12 , L_31 ,
V_157 -> V_28 . V_34 ) ;
V_127 [ V_18 ] . V_34 = V_157 -> V_28 . V_34 ;
V_127 [ V_18 ] . V_91 = ( long ) V_78 ;
V_127 [ V_18 ] . V_105 = V_106 ;
V_127 [ V_18 ] . V_107 = V_157 -> V_28 . V_107 ;
V_78 -> V_21 = F_6 ( V_2 , V_157 -> V_148 , V_149 ) ;
V_78 -> V_161 = F_7 ( V_2 , V_157 -> V_148 ,
V_149 ) ;
V_78 -> V_162 = F_7 ( V_2 , V_157 -> V_148 ,
V_151 ) ;
V_78 -> V_80 = V_157 -> V_80 ;
V_78 -> V_163 = V_157 -> V_163 ;
V_78 -> V_68 . V_29 = V_2 -> V_29 ;
switch ( V_157 -> V_28 . V_30 . V_33 ) {
case V_166 :
case V_165 :
V_63 = F_49 ( V_78 , V_157 ) ;
if ( V_63 < 0 ) {
F_2 ( V_2 -> V_12 , L_21 ,
V_157 -> V_28 . V_34 ) ;
goto V_190;
}
case V_167 :
case V_168 :
case V_169 :
V_63 = F_47 ( V_78 , V_157 ) ;
if ( V_63 < 0 ) {
F_2 ( V_2 -> V_12 , L_22 ,
V_157 -> V_28 . V_34 ) ;
goto V_190;
}
break;
default:
F_2 ( V_2 -> V_12 , L_23 ,
V_157 -> V_28 . V_30 . V_33 , V_157 -> V_28 . V_34 ) ;
goto V_190;
}
V_63 = F_34 ( & V_157 -> V_28 , & V_127 [ V_18 ] , V_2 ) ;
if ( V_63 ) {
F_11 ( V_2 , & V_157 -> V_28 , V_157 -> V_28 . V_34 ) ;
goto V_190;
}
V_63 = F_36 ( V_2 , & V_127 [ V_18 ] ,
(struct V_27 * ) V_157 ) ;
if ( V_63 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_157 -> V_28 . V_34 ) ;
goto V_190;
}
V_2 -> V_8 += ( sizeof( struct V_156 ) +
V_157 -> V_142 . V_11 ) ;
}
return V_127 ;
V_190:
for (; V_18 >= 0 ; V_18 -- ) {
V_78 = (struct V_77 * ) V_127 [ V_18 ] . V_91 ;
F_27 ( V_78 -> V_68 . V_74 . V_79 ) ;
for ( V_92 = 0 ; V_92 < V_157 -> V_80 ; V_92 ++ )
F_27 ( V_78 -> V_68 . V_74 . V_81 [ V_92 ] ) ;
F_27 ( V_78 ) ;
}
V_63:
F_27 ( V_127 ) ;
return NULL ;
}
static struct V_58 * F_58 (
struct V_1 * V_2 , int V_4 )
{
struct V_111 * V_112 ;
struct V_82 * V_110 ;
struct V_58 * V_127 ;
int V_18 , V_63 ;
V_127 = F_56 ( V_4 , sizeof( * V_127 ) , V_131 ) ;
if ( ! V_127 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_112 = (struct V_111 * ) V_2 -> V_8 ;
if ( F_43 ( V_112 -> V_28 . V_34 , V_141 ) ==
V_141 )
goto V_63;
V_110 = F_38 ( sizeof( * V_110 ) , V_131 ) ;
if ( V_110 == NULL )
goto V_63;
V_2 -> V_8 += ( sizeof( struct V_111 ) +
V_112 -> V_142 . V_11 ) ;
F_40 ( V_2 -> V_12 ,
L_12 ,
V_112 -> V_28 . V_34 , V_112 -> V_28 . V_107 ) ;
V_127 [ V_18 ] . V_34 = V_112 -> V_28 . V_34 ;
V_127 [ V_18 ] . V_91 = ( long ) V_110 ;
V_127 [ V_18 ] . V_105 = V_106 ;
V_127 [ V_18 ] . V_107 = V_112 -> V_28 . V_107 ;
V_110 -> V_143 = V_112 -> V_143 ;
F_44 ( & V_110 -> V_68 . V_76 ) ;
V_63 = F_34 ( & V_112 -> V_28 , & V_127 [ V_18 ] , V_2 ) ;
if ( V_63 ) {
F_11 ( V_2 , & V_112 -> V_28 , V_112 -> V_28 . V_34 ) ;
F_27 ( V_110 ) ;
continue;
}
V_63 = F_36 ( V_2 , & V_127 [ V_18 ] ,
(struct V_27 * ) V_112 ) ;
if ( V_63 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_112 -> V_28 . V_34 ) ;
F_27 ( V_110 ) ;
continue;
}
}
return V_127 ;
V_63:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_27 ( ( void * ) V_127 [ V_18 ] . V_91 ) ;
F_27 ( V_127 ) ;
return NULL ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_44 * V_43 )
{
struct V_179 * V_180 = & V_2 -> V_37 -> V_180 ;
struct V_42 V_191 , * V_86 ;
struct V_27 * V_170 ;
struct V_192 * V_56 = V_2 -> V_37 -> V_56 ;
unsigned int V_87 ;
int V_36 = 0 ;
if ( F_43 ( V_43 -> V_34 , V_141 ) ==
V_141 )
return - V_13 ;
if ( F_43 ( V_43 -> V_193 , V_141 ) ==
V_141 )
return - V_13 ;
F_40 ( V_2 -> V_12 , L_32 ,
V_43 -> V_34 , V_43 -> V_20 ) ;
memset ( & V_191 , 0 , sizeof( V_191 ) ) ;
V_191 . V_20 = F_8 ( V_43 -> V_20 ) ;
if ( V_191 . V_20 < 0 )
return V_191 . V_20 ;
V_191 . V_34 = F_48 ( V_43 -> V_34 , V_131 ) ;
if ( ! V_191 . V_34 )
return - V_64 ;
V_191 . V_193 = F_48 ( V_43 -> V_193 , V_131 ) ;
if ( ! V_191 . V_193 ) {
V_36 = - V_64 ;
goto V_63;
}
V_191 . V_21 = V_43 -> V_21 ;
V_191 . V_22 = V_43 -> V_22 ;
V_191 . V_163 = V_43 -> V_163 ;
V_191 . V_194 = V_43 -> V_194 ;
V_191 . V_195 = V_43 -> V_153 ? 0 : 1 ;
V_191 . V_196 = V_43 -> V_153 ? 1 : 0 ;
V_191 . V_197 = V_43 -> V_197 ;
V_191 . V_198 = V_43 -> V_198 ;
V_191 . V_68 . V_29 = V_2 -> V_29 ;
V_2 -> V_8 +=
( sizeof( struct V_44 ) + V_43 -> V_142 . V_11 ) ;
if ( V_43 -> V_89 == 0 ) {
V_87 = 0 ;
V_191 . V_89 = 0 ;
goto V_86;
}
V_170 = (struct V_27 * ) V_2 -> V_8 ;
F_40 ( V_2 -> V_12 , L_33 ,
V_43 -> V_34 , V_43 -> V_89 , V_170 -> type ) ;
switch ( V_170 -> V_30 . V_33 ) {
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
V_87 = V_94 ;
V_191 . V_89 = V_43 -> V_89 ;
V_191 . V_93 =
F_55 ( V_2 ,
V_191 . V_89 ) ;
if ( ! V_191 . V_93 ) {
V_36 = - V_64 ;
goto V_199;
}
break;
case V_167 :
case V_166 :
case V_168 :
case V_169 :
case V_165 :
V_87 = V_88 ;
V_191 . V_89 = V_43 -> V_89 ;
V_191 . V_93 =
F_57 ( V_2 ,
V_191 . V_89 ) ;
if ( ! V_191 . V_93 ) {
V_36 = - V_64 ;
goto V_199;
}
break;
case V_104 :
V_87 = V_200 ;
V_191 . V_89 = V_43 -> V_89 ;
V_191 . V_93 =
F_58 ( V_2 ,
V_191 . V_89 ) ;
if ( ! V_191 . V_93 ) {
V_36 = - V_64 ;
goto V_199;
}
break;
default:
F_2 ( V_2 -> V_12 , L_34 ,
V_170 -> V_30 . V_31 , V_170 -> V_30 . V_32 ,
V_170 -> V_30 . V_33 ) ;
V_36 = - V_13 ;
goto V_199;
}
V_86:
V_36 = F_14 ( V_2 , & V_191 , V_43 ) ;
if ( V_36 < 0 )
goto V_199;
if ( V_56 -> V_201 )
V_86 = F_60 ( V_180 , & V_191 ) ;
else
V_86 = F_61 ( V_180 , & V_191 ) ;
if ( F_62 ( V_86 ) ) {
V_36 = F_63 ( V_86 ) ;
if ( V_36 != - V_202 )
F_2 ( V_2 -> V_12 ,
L_35 ,
V_43 -> V_34 , V_36 ) ;
goto V_199;
}
if ( V_86 == NULL ) {
F_2 ( V_2 -> V_12 , L_36 ,
V_43 -> V_34 ) ;
V_36 = - V_64 ;
goto V_199;
}
V_86 -> V_68 . type = V_203 ;
V_86 -> V_68 . V_86 . V_87 = V_87 ;
V_86 -> V_68 . V_30 = V_2 -> V_30 ;
V_86 -> V_68 . V_29 = V_2 -> V_29 ;
F_45 ( & V_86 -> V_68 . V_76 , & V_2 -> V_37 -> V_145 ) ;
V_36 = F_15 ( V_2 , V_86 , V_43 ) ;
if ( V_36 < 0 )
goto V_204;
return 0 ;
V_204:
F_64 ( V_86 ) ;
F_65 ( V_86 ) ;
V_199:
F_27 ( V_191 . V_193 ) ;
V_63:
F_27 ( V_191 . V_34 ) ;
return V_36 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_44 * V_86 ;
int V_36 , V_4 = V_28 -> V_4 , V_18 ;
if ( V_2 -> V_40 != V_84 )
return 0 ;
F_40 ( V_2 -> V_12 , L_37 , V_4 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_86 = (struct V_44 * ) V_2 -> V_8 ;
if ( V_86 -> V_11 != sizeof( * V_86 ) ) {
F_2 ( V_2 -> V_12 , L_38 ) ;
return - V_13 ;
}
V_36 = F_59 ( V_2 , V_86 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_12 , L_39 ,
V_86 -> V_34 ) ;
return V_36 ;
}
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_192 * V_56 = V_2 -> V_37 -> V_56 ;
int V_36 ;
if ( ! V_56 || ! V_56 -> V_201 ) {
F_68 ( V_2 -> V_12 , L_40
L_41 ) ;
return 0 ;
}
V_36 = F_69 ( V_56 ) ;
if ( V_36 < 0 )
F_2 ( V_2 -> V_12 , L_42 ,
V_36 ) ;
return 0 ;
}
static void F_70 ( struct V_205 * V_206 ,
struct V_207 * V_208 )
{
V_206 -> V_98 = F_48 ( V_208 -> V_34 , V_131 ) ;
V_206 -> V_209 = V_208 -> V_209 ;
V_206 -> V_210 = V_208 -> V_210 ;
V_206 -> V_211 = V_208 -> V_211 ;
V_206 -> V_212 = V_208 -> V_212 ;
V_206 -> V_213 = V_208 -> V_213 ;
V_206 -> V_214 = V_208 -> V_214 ;
V_206 -> V_215 = V_208 -> V_215 ;
}
static void F_71 ( struct V_48 * V_49 ,
unsigned int V_216 , unsigned int V_217 )
{
if ( V_216 & V_218 )
V_49 -> V_219 =
V_217 & V_218 ? 1 : 0 ;
if ( V_216 & V_220 )
V_49 -> V_221 =
V_217 & V_220 ?
1 : 0 ;
if ( V_216 & V_222 )
V_49 -> V_223 =
V_217 & V_222 ?
1 : 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_224 * V_225 )
{
struct V_48 * V_49 ;
struct V_205 * V_206 ;
struct V_207 * V_208 ;
int V_36 ;
V_49 = F_38 ( sizeof( struct V_48 ) , V_131 ) ;
if ( V_49 == NULL )
return - V_64 ;
if ( strlen ( V_225 -> V_226 ) )
V_49 -> V_34 = F_48 ( V_225 -> V_226 , V_131 ) ;
V_49 -> V_20 = V_225 -> V_227 ;
if ( V_225 -> V_228 ) {
V_206 = & V_49 -> V_228 ;
V_208 = & V_225 -> V_208 [ V_229 ] ;
F_70 ( V_206 , V_208 ) ;
}
if ( V_225 -> V_230 ) {
V_206 = & V_49 -> V_230 ;
V_208 = & V_225 -> V_208 [ V_231 ] ;
F_70 ( V_206 , V_208 ) ;
}
V_36 = F_16 ( V_2 , V_49 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_37 -> V_12 , L_43 ) ;
F_27 ( V_49 ) ;
return V_36 ;
}
V_49 -> V_68 . V_29 = V_2 -> V_29 ;
V_49 -> V_68 . V_30 = V_2 -> V_30 ;
V_49 -> V_68 . type = V_232 ;
F_45 ( & V_49 -> V_68 . V_76 , & V_2 -> V_37 -> V_145 ) ;
return F_73 ( V_2 -> V_37 , V_49 ) ;
}
static void F_74 ( struct V_51 * V_52 ,
unsigned int V_216 , unsigned int V_217 )
{
if ( V_216 & V_233 )
V_52 -> V_219 =
V_217 & V_233 ? 1 : 0 ;
if ( V_216 & V_234 )
V_52 -> V_221 =
V_217 & V_234 ?
1 : 0 ;
if ( V_216 & V_235 )
V_52 -> V_223 =
V_217 & V_235 ?
1 : 0 ;
if ( V_216 & V_236 )
V_52 -> V_197 =
V_217 & V_236 ?
1 : 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_224 * V_225 )
{
struct V_51 * V_52 ;
int V_36 ;
V_52 = F_38 ( sizeof( struct V_51 ) , V_131 ) ;
if ( V_52 == NULL )
return - V_64 ;
if ( strlen ( V_225 -> V_237 ) ) {
V_52 -> V_34 = F_48 ( V_225 -> V_237 , V_131 ) ;
V_52 -> V_98 = F_48 ( V_225 -> V_237 , V_131 ) ;
}
V_52 -> V_20 = V_225 -> V_238 ;
if ( strlen ( V_225 -> V_226 ) )
V_52 -> V_99 = F_48 ( V_225 -> V_226 , V_131 ) ;
V_52 -> V_239 = L_44 ;
V_52 -> V_240 = L_45 ;
V_52 -> V_241 = 1 ;
V_52 -> V_242 = V_225 -> V_228 ;
V_52 -> V_243 = V_225 -> V_230 ;
if ( V_225 -> V_216 )
F_74 ( V_52 , V_225 -> V_216 , V_225 -> V_217 ) ;
V_36 = F_17 ( V_2 , V_52 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_37 -> V_12 , L_46 ) ;
F_27 ( V_52 ) ;
return V_36 ;
}
V_52 -> V_68 . V_29 = V_2 -> V_29 ;
V_52 -> V_68 . V_30 = V_2 -> V_30 ;
V_52 -> V_68 . type = V_244 ;
F_45 ( & V_52 -> V_68 . V_76 , & V_2 -> V_37 -> V_145 ) ;
F_76 ( V_2 -> V_37 -> V_56 , V_52 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_224 * V_225 )
{
int V_36 ;
V_36 = F_72 ( V_2 , V_225 ) ;
if ( V_36 < 0 )
return V_36 ;
return F_75 ( V_2 , V_225 ) ;
}
static void F_78 ( struct V_207 * V_245 ,
struct V_246 * V_247 )
{
V_245 -> V_11 = sizeof( * V_245 ) ;
memcpy ( V_245 -> V_34 , V_247 -> V_34 , V_141 ) ;
V_245 -> V_214 = V_247 -> V_214 ;
V_245 -> V_211 = V_247 -> V_211 ;
V_245 -> V_212 = V_247 -> V_212 ;
V_245 -> V_213 = V_247 -> V_213 ;
V_245 -> V_209 = V_247 -> V_209 ;
V_245 -> V_210 = V_247 -> V_210 ;
V_245 -> V_248 = V_247 -> V_248 ;
V_245 -> V_249 = V_247 -> V_249 ;
V_245 -> V_250 = V_247 -> V_250 ;
V_245 -> V_251 = V_247 -> V_251 ;
V_245 -> V_252 = V_247 -> V_252 ;
V_245 -> V_253 = V_247 -> V_253 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_224 * V_247 ,
struct V_224 * * V_225 )
{
struct V_224 * V_245 ;
struct V_254 * V_255 ;
int V_18 ;
* V_225 = NULL ;
if ( V_247 -> V_11 != sizeof( * V_255 ) ) {
F_2 ( V_2 -> V_12 , L_47 ) ;
return - V_13 ;
}
F_68 ( V_2 -> V_12 , L_48 ) ;
V_255 = (struct V_254 * ) V_247 ;
V_245 = F_38 ( sizeof( * V_245 ) , V_131 ) ;
if ( ! V_245 )
return - V_64 ;
V_245 -> V_11 = sizeof( * V_245 ) ;
memcpy ( V_245 -> V_237 , V_255 -> V_237 , V_141 ) ;
memcpy ( V_245 -> V_226 , V_255 -> V_226 , V_141 ) ;
V_245 -> V_238 = V_255 -> V_238 ;
V_245 -> V_227 = V_255 -> V_227 ;
V_245 -> V_228 = V_255 -> V_228 ;
V_245 -> V_230 = V_255 -> V_230 ;
V_245 -> V_256 = V_255 -> V_256 ;
V_245 -> V_257 = V_255 -> V_257 ;
for ( V_18 = 0 ; V_18 < V_245 -> V_257 ; V_18 ++ )
memcpy ( & V_245 -> V_206 [ V_18 ] , & V_255 -> V_206 [ V_18 ] ,
sizeof( struct V_258 ) ) ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ )
F_78 ( & V_245 -> V_208 [ V_18 ] , & V_255 -> V_208 [ V_18 ] ) ;
* V_225 = V_245 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_224 * V_225 , * V_259 ;
int V_4 = V_28 -> V_4 ;
int V_18 ;
bool V_260 ;
if ( V_2 -> V_40 != V_95 )
return 0 ;
V_225 = (struct V_224 * ) V_2 -> V_8 ;
if ( V_225 -> V_11 > sizeof( struct V_224 )
|| V_225 -> V_11 < sizeof( struct V_254 ) ) {
F_2 ( V_2 -> V_12 , L_49 ,
V_225 -> V_11 ) ;
return - V_13 ;
}
if ( F_1 ( V_2 ,
V_225 -> V_11 , V_4 ,
V_28 -> V_171 , L_50 ) ) {
F_2 ( V_2 -> V_12 , L_51 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_225 = (struct V_224 * ) V_2 -> V_8 ;
if ( V_225 -> V_11 == sizeof( * V_225 ) ) {
V_260 = true ;
V_259 = V_225 ;
} else {
V_260 = false ;
F_79 ( V_2 , V_225 , & V_259 ) ;
}
F_77 ( V_2 , V_259 ) ;
V_2 -> V_8 += V_225 -> V_11 + V_259 -> V_142 . V_11 ;
if ( ! V_260 )
F_27 ( V_259 ) ;
}
F_40 ( V_2 -> V_12 , L_52 , V_4 ) ;
return 0 ;
}
static void F_81 ( struct V_51 * V_52 ,
struct V_261 * V_262 )
{
struct V_263 * V_264 ;
unsigned char V_265 , V_266 ;
unsigned char V_267 , V_268 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_262 -> V_269 ; V_18 ++ ) {
V_264 = & V_262 -> V_264 [ V_18 ] ;
if ( V_264 -> V_20 != V_262 -> V_270 )
continue;
V_52 -> V_271 = V_264 -> V_272 & V_273 ;
V_267 = V_264 -> V_267 ;
V_268 = V_264 -> V_268 ;
if ( ! V_267 && ! V_268 )
V_52 -> V_271 |= V_274 ;
else if ( ! V_267 && V_268 )
V_52 -> V_271 |= V_275 ;
else if ( V_267 && ! V_268 )
V_52 -> V_271 |= V_276 ;
else
V_52 -> V_271 |= V_277 ;
V_265 = V_264 -> V_265 ;
V_266 = V_264 -> V_266 ;
if ( ! V_265 && ! V_266 )
V_52 -> V_271 |= V_278 ;
else if ( V_265 && ! V_266 )
V_52 -> V_271 |= V_279 ;
else if ( ! V_265 && V_266 )
V_52 -> V_271 |= V_280 ;
else
V_52 -> V_271 |= V_281 ;
}
}
static int F_82 ( struct V_1 * V_2 ,
struct V_261 * V_247 ,
struct V_261 * * V_52 )
{
struct V_261 * V_245 ;
struct V_282 * V_255 ;
int V_18 ;
* V_52 = NULL ;
if ( V_247 -> V_11 != sizeof( struct V_282 ) ) {
F_2 ( V_2 -> V_12 , L_53 ) ;
return - V_13 ;
}
F_68 ( V_2 -> V_12 , L_54 ) ;
V_255 = (struct V_282 * ) V_247 ;
V_245 = F_38 ( sizeof( * V_245 ) , V_131 ) ;
if ( ! V_245 )
return - V_64 ;
V_245 -> V_11 = sizeof( * V_245 ) ;
V_245 -> V_20 = V_255 -> V_20 ;
V_245 -> V_257 = V_255 -> V_257 ;
for ( V_18 = 0 ; V_18 < V_245 -> V_257 ; V_18 ++ )
memcpy ( & V_245 -> V_206 [ V_18 ] , & V_255 -> V_206 [ V_18 ] ,
sizeof( struct V_258 ) ) ;
* V_52 = V_245 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_261 * V_262 )
{
struct V_51 * V_52 ;
const char * V_34 , * V_98 ;
T_1 V_283 ;
int V_36 ;
V_283 = F_43 ( V_262 -> V_34 , V_141 ) ;
if ( V_283 == V_141 )
return - V_13 ;
else if ( V_283 )
V_34 = V_262 -> V_34 ;
else
V_34 = NULL ;
V_283 = F_43 ( V_262 -> V_98 , V_141 ) ;
if ( V_283 == V_141 )
return - V_13 ;
else if ( V_283 )
V_98 = V_262 -> V_98 ;
else
V_98 = NULL ;
V_52 = F_84 ( V_2 -> V_37 -> V_56 , V_262 -> V_20 ,
V_34 , V_98 ) ;
if ( ! V_52 ) {
F_2 ( V_2 -> V_12 , L_55 ,
V_34 , V_262 -> V_20 ) ;
return - V_13 ;
}
if ( V_262 -> V_269 )
F_81 ( V_52 , V_262 ) ;
if ( V_262 -> V_216 )
F_74 ( V_52 , V_262 -> V_216 , V_262 -> V_217 ) ;
V_36 = F_17 ( V_2 , V_52 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_12 , L_56 ) ;
return V_36 ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_261 * V_52 , * V_284 ;
int V_4 = V_28 -> V_4 ;
int V_18 , V_36 ;
bool V_260 ;
if ( V_2 -> V_40 != V_285 ) {
V_2 -> V_8 += V_28 -> V_11 + V_28 -> V_171 ;
return 0 ;
} ;
V_52 = (struct V_261 * ) V_2 -> V_8 ;
if ( V_52 -> V_11 > sizeof( struct V_261 )
|| V_52 -> V_11 < sizeof( struct V_282 ) ) {
F_2 ( V_2 -> V_12 , L_57 ,
V_52 -> V_11 ) ;
return - V_13 ;
}
if ( F_1 ( V_2 ,
V_52 -> V_11 , V_4 ,
V_28 -> V_171 , L_58 ) ) {
F_2 ( V_2 -> V_12 , L_59 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_52 = (struct V_261 * ) V_2 -> V_8 ;
if ( V_52 -> V_11 == sizeof( * V_52 ) ) {
V_260 = true ;
V_284 = V_52 ;
} else {
V_260 = false ;
V_36 = F_82 ( V_2 , V_52 , & V_284 ) ;
if ( V_36 < 0 )
return V_36 ;
}
V_36 = F_83 ( V_2 , V_284 ) ;
if ( V_36 < 0 )
return V_36 ;
V_2 -> V_8 += V_52 -> V_11 + V_284 -> V_142 . V_11 ;
if ( ! V_260 )
F_27 ( V_284 ) ;
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_286 * V_287 )
{
struct V_288 V_289 = { 0 } ;
struct V_290 * V_291 ;
struct V_48 * V_49 ;
struct V_205 * V_206 ;
struct V_207 * V_208 ;
int V_36 ;
V_289 . V_226 = V_287 -> V_226 ;
V_291 = F_87 ( & V_289 ) ;
if ( ! V_291 ) {
F_2 ( V_2 -> V_12 , L_60 ,
V_287 -> V_226 ) ;
return - V_13 ;
}
if ( V_287 -> V_227 != V_291 -> V_20 ) {
F_2 ( V_2 -> V_12 , L_61 ,
V_287 -> V_226 ) ;
return - V_13 ;
}
V_49 = V_291 -> V_292 ;
if ( ! V_49 )
return - V_13 ;
if ( V_287 -> V_228 ) {
V_206 = & V_49 -> V_228 ;
V_208 = & V_287 -> V_208 [ V_229 ] ;
F_70 ( V_206 , V_208 ) ;
}
if ( V_287 -> V_230 ) {
V_206 = & V_49 -> V_230 ;
V_208 = & V_287 -> V_208 [ V_231 ] ;
F_70 ( V_206 , V_208 ) ;
}
if ( V_287 -> V_216 )
F_71 ( V_49 , V_287 -> V_216 , V_287 -> V_217 ) ;
V_36 = F_16 ( V_2 , V_49 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_37 -> V_12 , L_43 ) ;
return V_36 ;
}
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_286 * V_291 ;
int V_4 = V_28 -> V_4 ;
int V_18 ;
if ( V_2 -> V_40 != V_293 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_291 = (struct V_286 * ) V_2 -> V_8 ;
if ( V_291 -> V_11 != sizeof( * V_291 ) ) {
F_2 ( V_2 -> V_12 , L_62 ) ;
return - V_13 ;
}
F_86 ( V_2 , V_291 ) ;
V_2 -> V_8 += ( sizeof( * V_291 ) + V_291 -> V_142 . V_11 ) ;
}
F_40 ( V_2 -> V_12 , L_63 , V_4 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_294 * V_247 ,
struct V_294 * * V_295 )
{
struct V_294 * V_245 ;
struct V_296 * V_255 ;
* V_295 = NULL ;
if ( V_247 -> V_11 != sizeof( * V_255 ) ) {
F_2 ( V_2 -> V_12 , L_64 ) ;
return - V_13 ;
}
F_68 ( V_2 -> V_12 , L_65 ) ;
V_255 = (struct V_296 * ) V_247 ;
V_245 = F_38 ( sizeof( * V_245 ) + V_255 -> V_142 . V_11 , V_131 ) ;
if ( ! V_245 )
return - V_64 ;
V_245 -> V_11 = sizeof( * V_245 ) ;
V_245 -> V_297 = V_255 -> V_297 ;
V_245 -> V_298 = V_255 -> V_298 ;
V_245 -> V_299 = V_255 -> V_299 ;
V_245 -> V_300 = V_255 -> V_300 ;
V_245 -> V_301 = V_255 -> V_301 ;
V_245 -> V_142 . V_11 = V_255 -> V_142 . V_11 ;
if ( V_245 -> V_142 . V_11 )
memcpy ( V_245 -> V_142 . V_10 , V_255 -> V_142 . V_10 ,
V_255 -> V_142 . V_11 ) ;
* V_295 = V_245 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_294 * V_295 , * V_302 ;
bool V_260 ;
int V_63 ;
if ( V_2 -> V_40 != V_303 )
return 0 ;
V_295 = (struct V_294 * ) V_2 -> V_8 ;
if ( V_295 -> V_11 == sizeof( * V_295 ) ) {
V_260 = true ;
V_302 = V_295 ;
} else {
V_260 = false ;
V_63 = F_89 ( V_2 , V_295 , & V_302 ) ;
if ( V_63 < 0 )
return V_63 ;
}
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_295 )
return V_2 -> V_30 -> V_295 ( V_2 -> V_37 , V_302 ) ;
if ( ! V_260 )
F_27 ( V_302 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
if ( F_4 ( V_2 ) >= V_2 -> V_9 -> V_11 )
return 0 ;
if ( V_28 -> V_11 != sizeof( * V_28 ) ) {
F_2 ( V_2 -> V_12 ,
L_66 ,
V_28 -> type , F_4 ( V_2 ) ,
V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_28 -> V_304 == F_92 ( V_305 ) ) {
F_2 ( V_2 -> V_12 ,
L_67 ,
V_2 -> V_40 , V_28 -> V_304 ,
F_4 ( V_2 ) , V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_28 -> V_304 != V_305 ) {
F_2 ( V_2 -> V_12 ,
L_68 ,
V_2 -> V_40 , V_28 -> V_304 ,
F_4 ( V_2 ) , V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_28 -> V_306 > V_307
|| V_28 -> V_306 < V_308 ) {
F_2 ( V_2 -> V_12 ,
L_69 ,
V_2 -> V_40 , V_28 -> V_306 ,
V_307 , F_4 ( V_2 ) ,
V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_28 -> V_171 == 0 ) {
F_2 ( V_2 -> V_12 , L_70 ,
F_4 ( V_2 ) ) ;
return - V_13 ;
}
if ( V_2 -> V_40 == V_28 -> type )
F_40 ( V_2 -> V_12 ,
L_71 ,
V_28 -> V_171 , V_28 -> type , V_28 -> V_309 ,
V_28 -> V_39 , V_2 -> V_40 ) ;
return 1 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
V_2 -> V_8 = V_2 -> V_14 + sizeof( struct V_35 ) ;
if ( V_28 -> V_29 != V_2 -> V_310 &&
V_2 -> V_310 != V_311 )
return 0 ;
V_2 -> V_29 = V_28 -> V_29 ;
switch ( V_28 -> type ) {
case V_94 :
case V_88 :
case V_200 :
return F_52 ( V_2 , V_28 ) ;
case V_312 :
return F_53 ( V_2 , V_28 ) ;
case V_313 :
return F_66 ( V_2 , V_28 ) ;
case V_314 :
return F_80 ( V_2 , V_28 ) ;
case V_315 :
return F_88 ( V_2 , V_28 ) ;
case V_316 :
case V_317 :
return F_85 ( V_2 , V_28 ) ;
case V_318 :
return F_90 ( V_2 , V_28 ) ;
default:
return F_13 ( V_2 , V_28 ) ;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_35 * V_28 ;
int V_36 ;
V_2 -> V_40 = V_319 ;
while ( V_2 -> V_40 <= V_320 ) {
V_2 -> V_14 = V_2 -> V_9 -> V_10 ;
V_28 = (struct V_35 * ) V_2 -> V_14 ;
while ( ! F_3 ( V_2 ) ) {
V_36 = F_91 ( V_2 , V_28 ) ;
if ( V_36 < 0 )
return V_36 ;
else if ( V_36 == 0 )
break;
V_36 = F_93 ( V_2 , V_28 ) ;
if ( V_36 < 0 )
return V_36 ;
V_2 -> V_14 += V_28 -> V_171 +
sizeof( struct V_35 ) ;
V_28 = (struct V_35 * ) V_2 -> V_14 ;
}
V_2 -> V_40 ++ ;
}
V_36 = F_67 ( V_2 ) ;
if ( V_36 < 0 )
F_2 ( V_2 -> V_12 ,
L_72 ) ;
return V_36 ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_36 ;
V_36 = F_94 ( V_2 ) ;
if ( V_36 == 0 )
F_18 ( V_2 ) ;
return V_36 ;
}
int F_96 ( struct V_66 * V_37 ,
struct V_321 * V_30 , const struct V_322 * V_9 , V_160 V_20 )
{
struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_9 = V_9 ;
V_2 . V_12 = V_37 -> V_12 ;
V_2 . V_37 = V_37 ;
V_2 . V_30 = V_30 ;
V_2 . V_310 = V_20 ;
V_2 . V_118 = V_30 -> V_118 ;
V_2 . V_119 = V_30 -> V_119 ;
V_2 . V_116 = V_30 -> V_116 ;
V_2 . V_117 = V_30 -> V_117 ;
return F_95 ( & V_2 ) ;
}
void F_64 ( struct V_42 * V_43 )
{
if ( V_43 -> V_68 . type != V_203 )
return;
F_30 ( V_43 -> V_180 -> V_323 , & V_43 -> V_68 , V_84 ) ;
}
void F_97 ( struct V_179 * V_180 ,
V_160 V_29 )
{
struct V_42 * V_43 , * V_324 ;
F_98 (w, next_w, &dapm->card->widgets, list) {
if ( V_43 -> V_68 . type != V_203 || V_43 -> V_180 != V_180 )
continue;
if ( V_43 -> V_68 . V_29 != V_29 &&
V_43 -> V_68 . V_29 != V_311 )
continue;
F_64 ( V_43 ) ;
F_65 ( V_43 ) ;
}
F_99 ( V_180 ) ;
}
int F_100 ( struct V_66 * V_37 , V_160 V_29 )
{
struct V_67 * V_68 , * V_325 ;
int V_40 = V_320 ;
while ( V_40 >= V_319 ) {
F_98 (dobj, next_dobj, &comp->dobj_list,
list) {
if ( V_68 -> V_29 != V_29 &&
V_68 -> V_29 != V_311 )
continue;
switch ( V_68 -> type ) {
case V_155 :
F_23 ( V_37 , V_68 , V_40 ) ;
break;
case V_164 :
F_28 ( V_37 , V_68 , V_40 ) ;
break;
case V_144 :
F_29 ( V_37 , V_68 , V_40 ) ;
break;
case V_203 :
F_30 ( V_37 , V_68 , V_40 ) ;
break;
case V_232 :
F_31 ( V_37 , V_68 , V_40 ) ;
break;
case V_244 :
F_32 ( V_37 , V_68 , V_40 ) ;
break;
default:
F_2 ( V_37 -> V_12 , L_73 ,
V_68 -> type ) ;
break;
}
}
V_40 -- ;
}
return ! F_101 ( & V_37 -> V_145 ) ;
}
