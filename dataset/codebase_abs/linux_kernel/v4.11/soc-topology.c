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
struct V_47 * V_48 )
{
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_49 )
return V_2 -> V_30 -> V_49 ( V_2 -> V_37 , V_48 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_52 )
return V_2 -> V_30 -> V_52 ( V_2 -> V_37 , V_51 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_53 )
V_2 -> V_30 -> V_53 ( V_2 -> V_37 ) ;
}
static int F_18 ( struct V_54 * V_55 , struct V_56 * V_12 ,
const struct V_57 * V_58 , const char * V_59 ,
void * V_10 , struct V_60 * * V_61 )
{
int V_62 ;
* V_61 = F_19 ( V_58 , V_10 , V_58 -> V_34 , V_59 ) ;
if ( * V_61 == NULL ) {
F_2 ( V_12 , L_7 ,
V_58 -> V_34 ) ;
return - V_63 ;
}
V_62 = F_20 ( V_55 , * V_61 ) ;
if ( V_62 < 0 ) {
F_2 ( V_12 , L_8 ,
V_58 -> V_34 , V_62 ) ;
return V_62 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_57 * V_64 , struct V_60 * * V_61 )
{
struct V_65 * V_37 = V_2 -> V_37 ;
return F_18 ( V_37 -> V_55 -> V_54 ,
V_37 -> V_12 , V_64 , NULL , V_37 , V_61 ) ;
}
static void F_22 ( struct V_65 * V_37 ,
struct V_66 * V_67 , int V_40 )
{
struct V_54 * V_55 = V_37 -> V_55 -> V_54 ;
struct V_68 * V_69 =
F_23 ( V_67 , struct V_68 , V_67 ) ;
const unsigned int * V_70 = NULL ;
if ( V_40 != V_71 )
return;
if ( V_67 -> V_30 && V_67 -> V_30 -> V_72 )
V_67 -> V_30 -> V_72 ( V_37 , V_67 ) ;
if ( V_69 -> V_67 . V_73 . V_61 -> V_74 . V_70 )
V_70 = V_69 -> V_67 . V_73 . V_61 -> V_74 . V_70 ;
F_24 ( V_55 , V_69 -> V_67 . V_73 . V_61 ) ;
F_25 ( & V_69 -> V_67 . V_75 ) ;
F_26 ( V_69 ) ;
F_26 ( V_70 ) ;
}
static void F_27 ( struct V_65 * V_37 ,
struct V_66 * V_67 , int V_40 )
{
struct V_54 * V_55 = V_37 -> V_55 -> V_54 ;
struct V_76 * V_77 = F_23 ( V_67 , struct V_76 , V_67 ) ;
int V_18 ;
if ( V_40 != V_71 )
return;
if ( V_67 -> V_30 && V_67 -> V_30 -> V_72 )
V_67 -> V_30 -> V_72 ( V_37 , V_67 ) ;
F_24 ( V_55 , V_77 -> V_67 . V_73 . V_61 ) ;
F_25 ( & V_77 -> V_67 . V_75 ) ;
F_26 ( V_77 -> V_67 . V_73 . V_78 ) ;
for ( V_18 = 0 ; V_18 < V_77 -> V_79 ; V_18 ++ )
F_26 ( V_77 -> V_67 . V_73 . V_80 [ V_18 ] ) ;
F_26 ( V_77 ) ;
}
static void F_28 ( struct V_65 * V_37 ,
struct V_66 * V_67 , int V_40 )
{
struct V_54 * V_55 = V_37 -> V_55 -> V_54 ;
struct V_81 * V_82 =
F_23 ( V_67 , struct V_81 , V_67 ) ;
if ( V_40 != V_71 )
return;
if ( V_67 -> V_30 && V_67 -> V_30 -> V_72 )
V_67 -> V_30 -> V_72 ( V_37 , V_67 ) ;
F_24 ( V_55 , V_82 -> V_67 . V_73 . V_61 ) ;
F_25 ( & V_82 -> V_67 . V_75 ) ;
F_26 ( V_82 ) ;
}
static void F_29 ( struct V_65 * V_37 ,
struct V_66 * V_67 , int V_40 )
{
struct V_54 * V_55 = V_37 -> V_55 -> V_54 ;
struct V_42 * V_43 =
F_23 ( V_67 , struct V_42 , V_67 ) ;
int V_18 ;
if ( V_40 != V_83 )
return;
if ( V_67 -> V_30 && V_67 -> V_30 -> V_84 )
V_67 -> V_30 -> V_84 ( V_37 , V_67 ) ;
if ( V_67 -> V_85 . V_86 == V_87 ) {
for ( V_18 = 0 ; V_18 < V_43 -> V_88 ; V_18 ++ ) {
struct V_60 * V_61 = V_43 -> V_89 [ V_18 ] ;
struct V_76 * V_77 =
(struct V_76 * ) V_61 -> V_90 ;
F_24 ( V_55 , V_61 ) ;
F_26 ( V_77 -> V_67 . V_73 . V_78 ) ;
for ( V_18 = 0 ; V_18 < V_77 -> V_79 ; V_18 ++ )
F_26 ( V_77 -> V_67 . V_73 . V_80 [ V_18 ] ) ;
F_26 ( V_77 ) ;
}
F_26 ( V_43 -> V_91 ) ;
} else {
for ( V_18 = 0 ; V_18 < V_43 -> V_88 ; V_18 ++ ) {
struct V_60 * V_61 = V_43 -> V_89 [ V_18 ] ;
if ( V_67 -> V_85 . V_86
== V_92 )
F_26 ( V_61 -> V_74 . V_70 ) ;
F_26 ( ( void * ) V_61 -> V_90 ) ;
F_24 ( V_55 , V_61 ) ;
}
F_26 ( V_43 -> V_91 ) ;
}
}
static void F_30 ( struct V_65 * V_37 ,
struct V_66 * V_67 , int V_40 )
{
struct V_47 * V_48 =
F_23 ( V_67 , struct V_47 , V_67 ) ;
if ( V_40 != V_93 )
return;
if ( V_67 -> V_30 && V_67 -> V_30 -> V_94 )
V_67 -> V_30 -> V_94 ( V_37 , V_67 ) ;
F_26 ( V_48 -> V_34 ) ;
F_25 ( & V_67 -> V_75 ) ;
F_26 ( V_48 ) ;
}
static void F_31 ( struct V_65 * V_37 ,
struct V_66 * V_67 , int V_40 )
{
struct V_50 * V_51 =
F_23 ( V_67 , struct V_50 , V_67 ) ;
if ( V_40 != V_93 )
return;
if ( V_67 -> V_30 && V_67 -> V_30 -> V_95 )
V_67 -> V_30 -> V_95 ( V_37 , V_67 ) ;
F_26 ( V_51 -> V_34 ) ;
F_26 ( V_51 -> V_96 ) ;
F_26 ( V_51 -> V_97 ) ;
F_25 ( & V_67 -> V_75 ) ;
F_32 ( V_37 -> V_55 , V_51 ) ;
F_26 ( V_51 ) ;
}
static int F_33 ( struct V_27 * V_28 ,
struct V_57 * V_64 ,
const struct V_1 * V_2 )
{
const struct V_98 * V_30 ;
const struct V_99 * V_100 ;
int V_101 , V_18 ;
if ( V_28 -> V_30 . V_33 == V_102
&& V_64 -> V_103 & V_104
&& V_64 -> V_105 & V_106
&& V_64 -> V_105 & V_107 ) {
struct V_81 * V_108 ;
struct V_109 * V_110 ;
V_108 = (struct V_81 * ) V_64 -> V_90 ;
V_110 = F_23 ( V_28 , struct V_109 , V_28 ) ;
V_64 -> V_33 = V_111 ;
V_64 -> V_74 . V_112 = V_113 ;
V_100 = V_2 -> V_114 ;
V_101 = V_2 -> V_115 ;
for ( V_18 = 0 ; V_18 < V_101 ; V_18 ++ ) {
if ( ! V_108 -> V_32 && V_100 [ V_18 ] . V_20 == V_110 -> V_100 . V_32 )
V_108 -> V_32 = V_100 [ V_18 ] . V_32 ;
if ( ! V_108 -> V_31 && V_100 [ V_18 ] . V_20 == V_110 -> V_100 . V_31 )
V_108 -> V_31 = V_100 [ V_18 ] . V_31 ;
}
if ( V_108 -> V_32 && V_108 -> V_31 )
return 0 ;
else
return - V_13 ;
}
V_30 = V_2 -> V_116 ;
V_101 = V_2 -> V_117 ;
for ( V_18 = 0 ; V_18 < V_101 ; V_18 ++ ) {
if ( V_64 -> V_32 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_32 )
V_64 -> V_32 = V_30 [ V_18 ] . V_32 ;
if ( V_64 -> V_31 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_31 )
V_64 -> V_31 = V_30 [ V_18 ] . V_31 ;
if ( V_64 -> V_33 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_33 )
V_64 -> V_33 = V_30 [ V_18 ] . V_33 ;
}
if ( V_64 -> V_32 && V_64 -> V_31 && V_64 -> V_33 )
return 0 ;
V_30 = V_116 ;
V_101 = F_9 ( V_116 ) ;
for ( V_18 = 0 ; V_18 < V_101 ; V_18 ++ ) {
if ( V_64 -> V_32 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_32 )
V_64 -> V_32 = V_30 [ V_18 ] . V_32 ;
if ( V_64 -> V_31 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_31 )
V_64 -> V_31 = V_30 [ V_18 ] . V_31 ;
if ( V_64 -> V_33 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_33 )
V_64 -> V_33 = V_30 [ V_18 ] . V_33 ;
}
if ( V_64 -> V_32 && V_64 -> V_31 && V_64 -> V_33 )
return 0 ;
return - V_13 ;
}
int F_34 ( struct V_42 * V_43 ,
const struct V_118 * V_119 ,
int V_120 , T_3 V_121 )
{
int V_18 ;
V_43 -> V_122 = NULL ;
for ( V_18 = 0 ; V_18 < V_120 ; V_18 ++ ) {
if ( V_121 == V_119 [ V_18 ] . type ) {
V_43 -> V_122 = V_119 [ V_18 ] . V_123 ;
return 0 ;
}
}
return - V_13 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_57 * V_64 , struct V_27 * V_28 )
{
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_124 )
return V_2 -> V_30 -> V_124 ( V_2 -> V_37 , V_64 , V_28 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_57 * V_125 , struct V_126 * V_127 )
{
unsigned int V_128 = 2 * sizeof( unsigned int ) ;
unsigned int * V_70 ;
V_70 = F_37 ( V_128 + 2 * sizeof( unsigned int ) , V_129 ) ;
if ( ! V_70 )
return - V_63 ;
V_70 [ 0 ] = V_130 ;
V_70 [ 1 ] = V_128 ;
V_70 [ 2 ] = V_127 -> V_131 ;
V_70 [ 3 ] = ( V_127 -> V_132 & V_133 )
| ( V_127 -> V_134 ? V_135 : 0 ) ;
V_125 -> V_74 . V_70 = ( void * ) V_70 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_57 * V_125 , struct V_27 * V_136 )
{
struct V_137 * V_138 ;
if ( ! ( V_136 -> V_105 & V_106 ) )
return 0 ;
if ( ! ( V_136 -> V_105 & V_107 ) ) {
V_138 = & V_136 -> V_74 ;
switch ( V_138 -> type ) {
case V_130 :
return F_36 ( V_2 , V_125 ,
& V_138 -> V_127 ) ;
default:
F_39 ( V_2 -> V_12 , L_9 ,
V_138 -> type ) ;
return - V_13 ;
}
}
return 0 ;
}
static inline void F_40 ( struct V_1 * V_2 ,
struct V_57 * V_125 )
{
F_26 ( V_125 -> V_74 . V_70 ) ;
}
static int F_41 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_109 * V_110 ;
struct V_81 * V_108 ;
struct V_57 V_125 ;
int V_18 , V_62 ;
if ( F_1 ( V_2 ,
sizeof( struct V_109 ) , V_4 ,
V_11 , L_10 ) ) {
F_2 ( V_2 -> V_12 , L_11 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_110 = (struct V_109 * ) V_2 -> V_8 ;
if ( F_42 ( V_110 -> V_28 . V_34 , V_139 ) ==
V_139 )
return - V_13 ;
V_108 = F_37 ( sizeof( * V_108 ) , V_129 ) ;
if ( V_108 == NULL )
return - V_63 ;
V_2 -> V_8 += ( sizeof( struct V_109 ) +
V_110 -> V_140 . V_11 ) ;
F_39 ( V_2 -> V_12 ,
L_12 ,
V_110 -> V_28 . V_34 , V_110 -> V_28 . V_105 ) ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_34 = V_110 -> V_28 . V_34 ;
V_125 . V_90 = ( long ) V_108 ;
V_125 . V_103 = V_104 ;
V_125 . V_105 = V_110 -> V_28 . V_105 ;
V_108 -> V_141 = V_110 -> V_141 ;
V_108 -> V_67 . type = V_142 ;
V_108 -> V_67 . V_30 = V_2 -> V_30 ;
F_43 ( & V_108 -> V_67 . V_75 ) ;
V_62 = F_33 ( & V_110 -> V_28 , & V_125 , V_2 ) ;
if ( V_62 ) {
F_11 ( V_2 , & V_110 -> V_28 , V_110 -> V_28 . V_34 ) ;
F_26 ( V_108 ) ;
continue;
}
V_62 = F_35 ( V_2 , & V_125 ,
(struct V_27 * ) V_110 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_110 -> V_28 . V_34 ) ;
F_26 ( V_108 ) ;
continue;
}
V_62 = F_21 ( V_2 , & V_125 ,
& V_108 -> V_67 . V_73 . V_61 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_14 ,
V_110 -> V_28 . V_34 ) ;
F_26 ( V_108 ) ;
continue;
}
F_44 ( & V_108 -> V_67 . V_75 , & V_2 -> V_37 -> V_143 ) ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_144 * V_145 ;
struct V_68 * V_69 ;
struct V_57 V_125 ;
int V_18 , V_62 ;
if ( F_1 ( V_2 ,
sizeof( struct V_144 ) ,
V_4 , V_11 , L_15 ) ) {
F_2 ( V_2 -> V_12 , L_16 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_145 = (struct V_144 * ) V_2 -> V_8 ;
if ( F_42 ( V_145 -> V_28 . V_34 , V_139 ) ==
V_139 )
return - V_13 ;
V_69 = F_37 ( sizeof( * V_69 ) , V_129 ) ;
if ( V_69 == NULL )
return - V_63 ;
V_2 -> V_8 += ( sizeof( struct V_144 ) +
V_145 -> V_140 . V_11 ) ;
F_39 ( V_2 -> V_12 ,
L_17 ,
V_145 -> V_28 . V_34 , V_145 -> V_28 . V_105 ) ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_34 = V_145 -> V_28 . V_34 ;
V_125 . V_90 = ( long ) V_69 ;
V_125 . V_103 = V_104 ;
V_125 . V_105 = V_145 -> V_28 . V_105 ;
V_69 -> V_21 = F_6 ( V_2 , V_145 -> V_146 ,
V_147 ) ;
V_69 -> V_148 = F_6 ( V_2 , V_145 -> V_146 ,
V_149 ) ;
V_69 -> V_22 = F_7 ( V_2 , V_145 -> V_146 ,
V_147 ) ;
V_69 -> V_150 = F_7 ( V_2 , V_145 -> V_146 ,
V_149 ) ;
V_69 -> V_141 = V_145 -> V_141 ;
V_69 -> V_131 = V_145 -> V_131 ;
V_69 -> V_151 = V_145 -> V_151 ;
V_69 -> V_152 = V_145 -> V_152 ;
V_69 -> V_67 . V_29 = V_2 -> V_29 ;
V_69 -> V_67 . V_30 = V_2 -> V_30 ;
V_69 -> V_67 . type = V_153 ;
F_43 ( & V_69 -> V_67 . V_75 ) ;
V_62 = F_33 ( & V_145 -> V_28 , & V_125 , V_2 ) ;
if ( V_62 ) {
F_11 ( V_2 , & V_145 -> V_28 , V_145 -> V_28 . V_34 ) ;
F_26 ( V_69 ) ;
continue;
}
V_62 = F_35 ( V_2 , & V_125 ,
(struct V_27 * ) V_145 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_145 -> V_28 . V_34 ) ;
F_26 ( V_69 ) ;
continue;
}
F_38 ( V_2 , & V_125 , & V_145 -> V_28 ) ;
V_62 = F_21 ( V_2 , & V_125 ,
& V_69 -> V_67 . V_73 . V_61 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_14 ,
V_145 -> V_28 . V_34 ) ;
F_40 ( V_2 , & V_125 ) ;
F_26 ( V_69 ) ;
continue;
}
F_44 ( & V_69 -> V_67 . V_75 , & V_2 -> V_37 -> V_143 ) ;
}
return 0 ;
}
static int F_46 ( struct V_76 * V_77 ,
struct V_154 * V_155 )
{
int V_18 , V_36 ;
V_77 -> V_67 . V_73 . V_80 =
F_37 ( sizeof( char * ) * V_155 -> V_79 , V_129 ) ;
if ( V_77 -> V_67 . V_73 . V_80 == NULL )
return - V_63 ;
for ( V_18 = 0 ; V_18 < V_155 -> V_79 ; V_18 ++ ) {
if ( F_42 ( V_155 -> V_156 [ V_18 ] , V_139 ) ==
V_139 ) {
V_36 = - V_13 ;
goto V_62;
}
V_77 -> V_67 . V_73 . V_80 [ V_18 ] = F_47 ( V_155 -> V_156 [ V_18 ] , V_129 ) ;
if ( ! V_77 -> V_67 . V_73 . V_80 [ V_18 ] ) {
V_36 = - V_63 ;
goto V_62;
}
}
V_77 -> V_156 = ( const char * const * ) V_77 -> V_67 . V_73 . V_80 ;
return 0 ;
V_62:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_26 ( V_77 -> V_67 . V_73 . V_80 [ V_18 ] ) ;
F_26 ( V_77 -> V_67 . V_73 . V_80 ) ;
return V_36 ;
}
static int F_48 ( struct V_76 * V_77 ,
struct V_154 * V_155 )
{
if ( V_155 -> V_79 > sizeof( * V_155 -> V_157 ) )
return - V_13 ;
V_77 -> V_67 . V_73 . V_78 = F_49 ( V_155 -> V_157 ,
V_155 -> V_79 * sizeof( V_158 ) ,
V_129 ) ;
if ( ! V_77 -> V_67 . V_73 . V_78 )
return - V_63 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_154 * V_155 ;
struct V_76 * V_77 ;
struct V_57 V_125 ;
int V_18 , V_36 , V_62 ;
if ( F_1 ( V_2 ,
sizeof( struct V_154 ) ,
V_4 , V_11 , L_18 ) ) {
F_2 ( V_2 -> V_12 , L_19 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_155 = (struct V_154 * ) V_2 -> V_8 ;
V_2 -> V_8 += ( sizeof( struct V_154 ) +
V_155 -> V_140 . V_11 ) ;
if ( F_42 ( V_155 -> V_28 . V_34 , V_139 ) ==
V_139 )
return - V_13 ;
V_77 = F_37 ( ( sizeof( * V_77 ) ) , V_129 ) ;
if ( V_77 == NULL )
return - V_63 ;
F_39 ( V_2 -> V_12 , L_20 ,
V_155 -> V_28 . V_34 , V_155 -> V_79 ) ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_34 = V_155 -> V_28 . V_34 ;
V_125 . V_90 = ( long ) V_77 ;
V_125 . V_103 = V_104 ;
V_125 . V_105 = V_155 -> V_28 . V_105 ;
V_77 -> V_21 = F_6 ( V_2 , V_155 -> V_146 , V_147 ) ;
V_77 -> V_159 = F_7 ( V_2 , V_155 -> V_146 ,
V_147 ) ;
V_77 -> V_160 = F_7 ( V_2 , V_155 -> V_146 ,
V_147 ) ;
V_77 -> V_79 = V_155 -> V_79 ;
V_77 -> V_161 = V_155 -> V_161 ;
V_77 -> V_67 . V_29 = V_2 -> V_29 ;
V_77 -> V_67 . type = V_162 ;
V_77 -> V_67 . V_30 = V_2 -> V_30 ;
F_43 ( & V_77 -> V_67 . V_75 ) ;
switch ( V_155 -> V_28 . V_30 . V_33 ) {
case V_163 :
case V_164 :
V_62 = F_48 ( V_77 , V_155 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 ,
L_21 ,
V_155 -> V_28 . V_34 ) ;
F_26 ( V_77 ) ;
continue;
}
case V_165 :
case V_166 :
case V_167 :
V_62 = F_46 ( V_77 , V_155 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 ,
L_22 ,
V_155 -> V_28 . V_34 ) ;
F_26 ( V_77 ) ;
continue;
}
break;
default:
F_2 ( V_2 -> V_12 ,
L_23 ,
V_155 -> V_28 . V_30 . V_33 , V_155 -> V_28 . V_34 ) ;
F_26 ( V_77 ) ;
continue;
}
V_62 = F_33 ( & V_155 -> V_28 , & V_125 , V_2 ) ;
if ( V_62 ) {
F_11 ( V_2 , & V_155 -> V_28 , V_155 -> V_28 . V_34 ) ;
F_26 ( V_77 ) ;
continue;
}
V_62 = F_35 ( V_2 , & V_125 ,
(struct V_27 * ) V_155 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_155 -> V_28 . V_34 ) ;
F_26 ( V_77 ) ;
continue;
}
V_36 = F_21 ( V_2 ,
& V_125 , & V_77 -> V_67 . V_73 . V_61 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_12 , L_24 ,
V_155 -> V_28 . V_34 ) ;
F_26 ( V_77 ) ;
continue;
}
F_44 ( & V_77 -> V_67 . V_75 , & V_2 -> V_37 -> V_143 ) ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_27 * V_168 ;
int V_18 ;
if ( V_2 -> V_40 != V_71 ) {
V_2 -> V_8 += V_28 -> V_11 + V_28 -> V_169 ;
return 0 ;
}
F_39 ( V_2 -> V_12 , L_25 , V_28 -> V_4 ,
F_5 ( V_2 ) ) ;
for ( V_18 = 0 ; V_18 < V_28 -> V_4 ; V_18 ++ ) {
V_168 = (struct V_27 * ) V_2 -> V_8 ;
if ( V_168 -> V_11 != sizeof( * V_168 ) ) {
F_2 ( V_2 -> V_12 , L_26 ) ;
return - V_13 ;
}
switch ( V_168 -> V_30 . V_33 ) {
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
F_45 ( V_2 , 1 , V_28 -> V_169 ) ;
break;
case V_165 :
case V_164 :
case V_166 :
case V_167 :
case V_163 :
F_50 ( V_2 , 1 , V_28 -> V_169 ) ;
break;
case V_102 :
F_41 ( V_2 , 1 , V_28 -> V_169 ) ;
break;
default:
F_10 ( V_2 , V_168 , V_18 ) ;
return - V_13 ;
}
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_177 * V_178 = & V_2 -> V_37 -> V_178 ;
struct V_179 V_180 ;
struct V_181 * V_182 ;
int V_4 = V_28 -> V_4 , V_18 ;
if ( V_2 -> V_40 != V_183 ) {
V_2 -> V_8 += V_28 -> V_11 + V_28 -> V_169 ;
return 0 ;
}
if ( F_1 ( V_2 ,
sizeof( struct V_181 ) ,
V_4 , V_28 -> V_169 , L_27 ) ) {
F_2 ( V_2 -> V_12 , L_28 ,
V_4 ) ;
return - V_13 ;
}
F_39 ( V_2 -> V_12 , L_29 , V_4 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_182 = (struct V_181 * ) V_2 -> V_8 ;
V_2 -> V_8 += sizeof( struct V_181 ) ;
if ( F_42 ( V_182 -> V_184 , V_139 ) ==
V_139 )
return - V_13 ;
if ( F_42 ( V_182 -> V_185 , V_139 ) ==
V_139 )
return - V_13 ;
if ( F_42 ( V_182 -> V_73 , V_139 ) ==
V_139 )
return - V_13 ;
V_180 . V_184 = V_182 -> V_184 ;
V_180 . V_185 = V_182 -> V_185 ;
V_180 . V_186 = NULL ;
if ( F_42 ( V_182 -> V_73 , V_139 ) == 0 )
V_180 . V_73 = NULL ;
else
V_180 . V_73 = V_182 -> V_73 ;
F_53 ( V_178 , & V_180 , 1 ) ;
}
return 0 ;
}
static struct V_57 * F_54 (
struct V_1 * V_2 , int V_88 )
{
struct V_57 * V_125 ;
struct V_68 * V_69 ;
struct V_144 * V_145 ;
int V_18 , V_62 ;
V_125 = F_55 ( V_88 , sizeof( * V_125 ) , V_129 ) ;
if ( V_125 == NULL )
return NULL ;
for ( V_18 = 0 ; V_18 < V_88 ; V_18 ++ ) {
V_145 = (struct V_144 * ) V_2 -> V_8 ;
V_69 = F_37 ( sizeof( * V_69 ) , V_129 ) ;
if ( V_69 == NULL )
goto V_62;
V_2 -> V_8 += ( sizeof( struct V_144 ) +
V_145 -> V_140 . V_11 ) ;
if ( F_42 ( V_145 -> V_28 . V_34 , V_139 ) ==
V_139 )
goto V_187;
F_39 ( V_2 -> V_12 , L_30 ,
V_145 -> V_28 . V_34 , V_18 ) ;
V_125 [ V_18 ] . V_34 = V_145 -> V_28 . V_34 ;
V_125 [ V_18 ] . V_90 = ( long ) V_69 ;
V_125 [ V_18 ] . V_103 = V_104 ;
V_125 [ V_18 ] . V_105 = V_145 -> V_28 . V_105 ;
V_69 -> V_21 = F_6 ( V_2 , V_145 -> V_146 ,
V_147 ) ;
V_69 -> V_148 = F_6 ( V_2 , V_145 -> V_146 ,
V_149 ) ;
V_69 -> V_22 = F_7 ( V_2 , V_145 -> V_146 ,
V_147 ) ;
V_69 -> V_150 = F_7 ( V_2 , V_145 -> V_146 ,
V_149 ) ;
V_69 -> V_141 = V_145 -> V_141 ;
V_69 -> V_131 = V_145 -> V_131 ;
V_69 -> V_151 = V_145 -> V_151 ;
V_69 -> V_152 = V_145 -> V_152 ;
V_69 -> V_67 . V_29 = V_2 -> V_29 ;
F_43 ( & V_69 -> V_67 . V_75 ) ;
V_62 = F_33 ( & V_145 -> V_28 , & V_125 [ V_18 ] , V_2 ) ;
if ( V_62 ) {
F_11 ( V_2 , & V_145 -> V_28 , V_145 -> V_28 . V_34 ) ;
F_26 ( V_69 ) ;
continue;
}
V_62 = F_35 ( V_2 , & V_125 [ V_18 ] ,
(struct V_27 * ) V_145 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_145 -> V_28 . V_34 ) ;
F_26 ( V_69 ) ;
continue;
}
}
return V_125 ;
V_187:
F_26 ( V_69 ) ;
V_62:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_26 ( ( void * ) V_125 [ V_18 ] . V_90 ) ;
F_26 ( V_125 ) ;
return NULL ;
}
static struct V_57 * F_56 (
struct V_1 * V_2 , int V_88 )
{
struct V_57 * V_125 ;
struct V_154 * V_155 ;
struct V_76 * V_77 ;
int V_18 , V_188 , V_62 ;
V_125 = F_55 ( V_88 , sizeof( * V_125 ) , V_129 ) ;
if ( V_125 == NULL )
return NULL ;
for ( V_18 = 0 ; V_18 < V_88 ; V_18 ++ ) {
V_155 = (struct V_154 * ) V_2 -> V_8 ;
if ( F_42 ( V_155 -> V_28 . V_34 , V_139 ) ==
V_139 )
return NULL ;
V_77 = F_37 ( sizeof( * V_77 ) , V_129 ) ;
if ( V_77 == NULL )
goto V_62;
F_39 ( V_2 -> V_12 , L_31 ,
V_155 -> V_28 . V_34 ) ;
V_125 [ V_18 ] . V_34 = V_155 -> V_28 . V_34 ;
V_125 [ V_18 ] . V_90 = ( long ) V_77 ;
V_125 [ V_18 ] . V_103 = V_104 ;
V_125 [ V_18 ] . V_105 = V_155 -> V_28 . V_105 ;
V_77 -> V_21 = F_6 ( V_2 , V_155 -> V_146 , V_147 ) ;
V_77 -> V_159 = F_7 ( V_2 , V_155 -> V_146 ,
V_147 ) ;
V_77 -> V_160 = F_7 ( V_2 , V_155 -> V_146 ,
V_149 ) ;
V_77 -> V_79 = V_155 -> V_79 ;
V_77 -> V_161 = V_155 -> V_161 ;
V_77 -> V_67 . V_29 = V_2 -> V_29 ;
switch ( V_155 -> V_28 . V_30 . V_33 ) {
case V_164 :
case V_163 :
V_62 = F_48 ( V_77 , V_155 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_21 ,
V_155 -> V_28 . V_34 ) ;
goto V_189;
}
case V_165 :
case V_166 :
case V_167 :
V_62 = F_46 ( V_77 , V_155 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_22 ,
V_155 -> V_28 . V_34 ) ;
goto V_189;
}
break;
default:
F_2 ( V_2 -> V_12 , L_23 ,
V_155 -> V_28 . V_30 . V_33 , V_155 -> V_28 . V_34 ) ;
goto V_189;
}
V_62 = F_33 ( & V_155 -> V_28 , & V_125 [ V_18 ] , V_2 ) ;
if ( V_62 ) {
F_11 ( V_2 , & V_155 -> V_28 , V_155 -> V_28 . V_34 ) ;
goto V_189;
}
V_62 = F_35 ( V_2 , & V_125 [ V_18 ] ,
(struct V_27 * ) V_155 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_155 -> V_28 . V_34 ) ;
goto V_189;
}
V_2 -> V_8 += ( sizeof( struct V_154 ) +
V_155 -> V_140 . V_11 ) ;
}
return V_125 ;
V_189:
for (; V_18 >= 0 ; V_18 -- ) {
V_77 = (struct V_76 * ) V_125 [ V_18 ] . V_90 ;
F_26 ( V_77 -> V_67 . V_73 . V_78 ) ;
for ( V_188 = 0 ; V_188 < V_155 -> V_79 ; V_188 ++ )
F_26 ( V_77 -> V_67 . V_73 . V_80 [ V_188 ] ) ;
F_26 ( V_77 ) ;
}
V_62:
F_26 ( V_125 ) ;
return NULL ;
}
static struct V_57 * F_57 (
struct V_1 * V_2 , int V_4 )
{
struct V_109 * V_110 ;
struct V_81 * V_108 ;
struct V_57 * V_125 ;
int V_18 , V_62 ;
V_125 = F_55 ( V_4 , sizeof( * V_125 ) , V_129 ) ;
if ( ! V_125 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_110 = (struct V_109 * ) V_2 -> V_8 ;
if ( F_42 ( V_110 -> V_28 . V_34 , V_139 ) ==
V_139 )
goto V_62;
V_108 = F_37 ( sizeof( * V_108 ) , V_129 ) ;
if ( V_108 == NULL )
goto V_62;
V_2 -> V_8 += ( sizeof( struct V_109 ) +
V_110 -> V_140 . V_11 ) ;
F_39 ( V_2 -> V_12 ,
L_12 ,
V_110 -> V_28 . V_34 , V_110 -> V_28 . V_105 ) ;
V_125 [ V_18 ] . V_34 = V_110 -> V_28 . V_34 ;
V_125 [ V_18 ] . V_90 = ( long ) V_108 ;
V_125 [ V_18 ] . V_103 = V_104 ;
V_125 [ V_18 ] . V_105 = V_110 -> V_28 . V_105 ;
V_108 -> V_141 = V_110 -> V_141 ;
F_43 ( & V_108 -> V_67 . V_75 ) ;
V_62 = F_33 ( & V_110 -> V_28 , & V_125 [ V_18 ] , V_2 ) ;
if ( V_62 ) {
F_11 ( V_2 , & V_110 -> V_28 , V_110 -> V_28 . V_34 ) ;
F_26 ( V_108 ) ;
continue;
}
V_62 = F_35 ( V_2 , & V_125 [ V_18 ] ,
(struct V_27 * ) V_110 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_110 -> V_28 . V_34 ) ;
F_26 ( V_108 ) ;
continue;
}
}
return V_125 ;
V_62:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_26 ( ( void * ) V_125 [ V_18 ] . V_90 ) ;
F_26 ( V_125 ) ;
return NULL ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_44 * V_43 )
{
struct V_177 * V_178 = & V_2 -> V_37 -> V_178 ;
struct V_42 V_190 , * V_85 ;
struct V_27 * V_168 ;
struct V_191 * V_55 = V_2 -> V_37 -> V_55 ;
unsigned int V_86 ;
int V_36 = 0 ;
if ( F_42 ( V_43 -> V_34 , V_139 ) ==
V_139 )
return - V_13 ;
if ( F_42 ( V_43 -> V_192 , V_139 ) ==
V_139 )
return - V_13 ;
F_39 ( V_2 -> V_12 , L_32 ,
V_43 -> V_34 , V_43 -> V_20 ) ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
V_190 . V_20 = F_8 ( V_43 -> V_20 ) ;
if ( V_190 . V_20 < 0 )
return V_190 . V_20 ;
V_190 . V_34 = F_47 ( V_43 -> V_34 , V_129 ) ;
if ( ! V_190 . V_34 )
return - V_63 ;
V_190 . V_192 = F_47 ( V_43 -> V_192 , V_129 ) ;
if ( ! V_190 . V_192 ) {
V_36 = - V_63 ;
goto V_62;
}
V_190 . V_21 = V_43 -> V_21 ;
V_190 . V_22 = V_43 -> V_22 ;
V_190 . V_161 = V_43 -> V_161 ;
V_190 . V_193 = V_43 -> V_193 ;
V_190 . V_194 = V_43 -> V_151 ? 0 : 1 ;
V_190 . V_195 = V_43 -> V_151 ? 1 : 0 ;
V_190 . V_196 = V_43 -> V_196 ;
V_190 . V_197 = V_43 -> V_197 ;
V_190 . V_67 . V_29 = V_2 -> V_29 ;
V_2 -> V_8 +=
( sizeof( struct V_44 ) + V_43 -> V_140 . V_11 ) ;
if ( V_43 -> V_88 == 0 ) {
V_86 = 0 ;
V_190 . V_88 = 0 ;
goto V_85;
}
V_168 = (struct V_27 * ) V_2 -> V_8 ;
F_39 ( V_2 -> V_12 , L_33 ,
V_43 -> V_34 , V_43 -> V_88 , V_168 -> type ) ;
switch ( V_168 -> V_30 . V_33 ) {
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
V_86 = V_92 ;
V_190 . V_88 = V_43 -> V_88 ;
V_190 . V_91 =
F_54 ( V_2 ,
V_190 . V_88 ) ;
if ( ! V_190 . V_91 ) {
V_36 = - V_63 ;
goto V_198;
}
break;
case V_165 :
case V_164 :
case V_166 :
case V_167 :
case V_163 :
V_86 = V_87 ;
V_190 . V_88 = V_43 -> V_88 ;
V_190 . V_91 =
F_56 ( V_2 ,
V_190 . V_88 ) ;
if ( ! V_190 . V_91 ) {
V_36 = - V_63 ;
goto V_198;
}
break;
case V_102 :
V_86 = V_199 ;
V_190 . V_88 = V_43 -> V_88 ;
V_190 . V_91 =
F_57 ( V_2 ,
V_190 . V_88 ) ;
if ( ! V_190 . V_91 ) {
V_36 = - V_63 ;
goto V_198;
}
break;
default:
F_2 ( V_2 -> V_12 , L_34 ,
V_168 -> V_30 . V_31 , V_168 -> V_30 . V_32 ,
V_168 -> V_30 . V_33 ) ;
V_36 = - V_13 ;
goto V_198;
}
V_85:
V_36 = F_14 ( V_2 , & V_190 , V_43 ) ;
if ( V_36 < 0 )
goto V_198;
if ( V_55 -> V_200 )
V_85 = F_59 ( V_178 , & V_190 ) ;
else
V_85 = F_60 ( V_178 , & V_190 ) ;
if ( F_61 ( V_85 ) ) {
V_36 = F_62 ( V_85 ) ;
if ( V_36 != - V_201 )
F_2 ( V_2 -> V_12 ,
L_35 ,
V_43 -> V_34 , V_36 ) ;
goto V_198;
}
if ( V_85 == NULL ) {
F_2 ( V_2 -> V_12 , L_36 ,
V_43 -> V_34 ) ;
V_36 = - V_63 ;
goto V_198;
}
V_85 -> V_67 . type = V_202 ;
V_85 -> V_67 . V_85 . V_86 = V_86 ;
V_85 -> V_67 . V_30 = V_2 -> V_30 ;
V_85 -> V_67 . V_29 = V_2 -> V_29 ;
F_26 ( V_190 . V_192 ) ;
F_26 ( V_190 . V_34 ) ;
F_44 ( & V_85 -> V_67 . V_75 , & V_2 -> V_37 -> V_143 ) ;
return 0 ;
V_198:
F_26 ( V_190 . V_192 ) ;
V_62:
F_26 ( V_190 . V_34 ) ;
return V_36 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_44 * V_85 ;
int V_36 , V_4 = V_28 -> V_4 , V_18 ;
if ( V_2 -> V_40 != V_83 )
return 0 ;
F_39 ( V_2 -> V_12 , L_37 , V_4 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_85 = (struct V_44 * ) V_2 -> V_8 ;
if ( V_85 -> V_11 != sizeof( * V_85 ) ) {
F_2 ( V_2 -> V_12 , L_38 ) ;
return - V_13 ;
}
V_36 = F_58 ( V_2 , V_85 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_12 , L_39 ,
V_85 -> V_34 ) ;
return V_36 ;
}
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_191 * V_55 = V_2 -> V_37 -> V_55 ;
int V_36 ;
if ( ! V_55 || ! V_55 -> V_200 ) {
F_65 ( V_2 -> V_12 , L_40
L_41 ) ;
return 0 ;
}
V_36 = F_66 ( V_55 ) ;
if ( V_36 < 0 )
F_2 ( V_2 -> V_12 , L_42 ,
V_36 ) ;
return 0 ;
}
static void F_67 ( struct V_203 * V_204 ,
struct V_205 * V_206 )
{
V_204 -> V_96 = F_47 ( V_206 -> V_34 , V_129 ) ;
V_204 -> V_207 = V_206 -> V_207 ;
V_204 -> V_208 = V_206 -> V_208 ;
V_204 -> V_209 = V_206 -> V_209 ;
V_204 -> V_210 = V_206 -> V_210 ;
V_204 -> V_211 = V_206 -> V_211 ;
V_204 -> V_212 = V_206 -> V_212 ;
V_204 -> V_213 = V_206 -> V_213 ;
}
static void F_68 ( struct V_47 * V_48 ,
unsigned int V_214 , unsigned int V_215 )
{
if ( V_214 & V_216 )
V_48 -> V_217 =
V_215 & V_216 ? 1 : 0 ;
if ( V_214 & V_218 )
V_48 -> V_219 =
V_215 & V_218 ?
1 : 0 ;
if ( V_214 & V_220 )
V_48 -> V_221 =
V_215 & V_220 ?
1 : 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_222 * V_223 )
{
struct V_47 * V_48 ;
struct V_203 * V_204 ;
struct V_205 * V_206 ;
int V_36 ;
V_48 = F_37 ( sizeof( struct V_47 ) , V_129 ) ;
if ( V_48 == NULL )
return - V_63 ;
if ( strlen ( V_223 -> V_224 ) )
V_48 -> V_34 = F_47 ( V_223 -> V_224 , V_129 ) ;
V_48 -> V_20 = V_223 -> V_225 ;
if ( V_223 -> V_226 ) {
V_204 = & V_48 -> V_226 ;
V_206 = & V_223 -> V_206 [ V_227 ] ;
F_67 ( V_204 , V_206 ) ;
}
if ( V_223 -> V_228 ) {
V_204 = & V_48 -> V_228 ;
V_206 = & V_223 -> V_206 [ V_229 ] ;
F_67 ( V_204 , V_206 ) ;
}
V_36 = F_15 ( V_2 , V_48 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_37 -> V_12 , L_43 ) ;
F_26 ( V_48 ) ;
return V_36 ;
}
V_48 -> V_67 . V_29 = V_2 -> V_29 ;
V_48 -> V_67 . V_30 = V_2 -> V_30 ;
V_48 -> V_67 . type = V_230 ;
F_44 ( & V_48 -> V_67 . V_75 , & V_2 -> V_37 -> V_143 ) ;
return F_70 ( V_2 -> V_37 , V_48 ) ;
}
static void F_71 ( struct V_50 * V_51 ,
unsigned int V_214 , unsigned int V_215 )
{
if ( V_214 & V_231 )
V_51 -> V_217 =
V_215 & V_231 ? 1 : 0 ;
if ( V_214 & V_232 )
V_51 -> V_219 =
V_215 & V_232 ?
1 : 0 ;
if ( V_214 & V_233 )
V_51 -> V_221 =
V_215 & V_233 ?
1 : 0 ;
if ( V_214 & V_234 )
V_51 -> V_196 =
V_215 & V_234 ?
1 : 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_222 * V_223 )
{
struct V_50 * V_51 ;
int V_36 ;
V_51 = F_37 ( sizeof( struct V_50 ) , V_129 ) ;
if ( V_51 == NULL )
return - V_63 ;
if ( strlen ( V_223 -> V_235 ) ) {
V_51 -> V_34 = F_47 ( V_223 -> V_235 , V_129 ) ;
V_51 -> V_96 = F_47 ( V_223 -> V_235 , V_129 ) ;
}
V_51 -> V_20 = V_223 -> V_236 ;
if ( strlen ( V_223 -> V_224 ) )
V_51 -> V_97 = F_47 ( V_223 -> V_224 , V_129 ) ;
V_51 -> V_237 = L_44 ;
V_51 -> V_238 = L_45 ;
V_51 -> V_239 = 1 ;
V_51 -> V_240 = V_223 -> V_226 ;
V_51 -> V_241 = V_223 -> V_228 ;
if ( V_223 -> V_214 )
F_71 ( V_51 , V_223 -> V_214 , V_223 -> V_215 ) ;
V_36 = F_16 ( V_2 , V_51 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_37 -> V_12 , L_46 ) ;
F_26 ( V_51 ) ;
return V_36 ;
}
V_51 -> V_67 . V_29 = V_2 -> V_29 ;
V_51 -> V_67 . V_30 = V_2 -> V_30 ;
V_51 -> V_67 . type = V_242 ;
F_44 ( & V_51 -> V_67 . V_75 , & V_2 -> V_37 -> V_143 ) ;
F_73 ( V_2 -> V_37 -> V_55 , V_51 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_222 * V_223 )
{
int V_36 ;
V_36 = F_69 ( V_2 , V_223 ) ;
if ( V_36 < 0 )
return V_36 ;
return F_72 ( V_2 , V_223 ) ;
}
static void F_75 ( struct V_205 * V_243 ,
struct V_244 * V_245 )
{
V_243 -> V_11 = sizeof( * V_243 ) ;
memcpy ( V_243 -> V_34 , V_245 -> V_34 , V_139 ) ;
V_243 -> V_212 = V_245 -> V_212 ;
V_243 -> V_209 = V_245 -> V_209 ;
V_243 -> V_210 = V_245 -> V_210 ;
V_243 -> V_211 = V_245 -> V_211 ;
V_243 -> V_207 = V_245 -> V_207 ;
V_243 -> V_208 = V_245 -> V_208 ;
V_243 -> V_246 = V_245 -> V_246 ;
V_243 -> V_247 = V_245 -> V_247 ;
V_243 -> V_248 = V_245 -> V_248 ;
V_243 -> V_249 = V_245 -> V_249 ;
V_243 -> V_250 = V_245 -> V_250 ;
V_243 -> V_251 = V_245 -> V_251 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_222 * V_245 ,
struct V_222 * * V_223 )
{
struct V_222 * V_243 ;
struct V_252 * V_253 ;
int V_18 ;
* V_223 = NULL ;
if ( V_245 -> V_11 != sizeof( * V_253 ) ) {
F_2 ( V_2 -> V_12 , L_47 ) ;
return - V_13 ;
}
F_65 ( V_2 -> V_12 , L_48 ) ;
V_253 = (struct V_252 * ) V_245 ;
V_243 = F_37 ( sizeof( * V_243 ) , V_129 ) ;
if ( ! V_243 )
return - V_63 ;
V_243 -> V_11 = sizeof( * V_243 ) ;
memcpy ( V_243 -> V_235 , V_253 -> V_235 , V_139 ) ;
memcpy ( V_243 -> V_224 , V_253 -> V_224 , V_139 ) ;
V_243 -> V_236 = V_253 -> V_236 ;
V_243 -> V_225 = V_253 -> V_225 ;
V_243 -> V_226 = V_253 -> V_226 ;
V_243 -> V_228 = V_253 -> V_228 ;
V_243 -> V_254 = V_253 -> V_254 ;
V_243 -> V_255 = V_253 -> V_255 ;
for ( V_18 = 0 ; V_18 < V_243 -> V_255 ; V_18 ++ )
memcpy ( & V_243 -> V_204 [ V_18 ] , & V_253 -> V_204 [ V_18 ] ,
sizeof( struct V_256 ) ) ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ )
F_75 ( & V_243 -> V_206 [ V_18 ] , & V_253 -> V_206 [ V_18 ] ) ;
* V_223 = V_243 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_222 * V_223 , * V_257 ;
int V_4 = V_28 -> V_4 ;
int V_18 ;
bool V_258 ;
if ( V_2 -> V_40 != V_93 )
return 0 ;
V_223 = (struct V_222 * ) V_2 -> V_8 ;
if ( V_223 -> V_11 > sizeof( struct V_222 )
|| V_223 -> V_11 < sizeof( struct V_252 ) ) {
F_2 ( V_2 -> V_12 , L_49 ,
V_223 -> V_11 ) ;
return - V_13 ;
}
if ( F_1 ( V_2 ,
V_223 -> V_11 , V_4 ,
V_28 -> V_169 , L_50 ) ) {
F_2 ( V_2 -> V_12 , L_51 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_223 = (struct V_222 * ) V_2 -> V_8 ;
if ( V_223 -> V_11 == sizeof( * V_223 ) ) {
V_258 = true ;
V_257 = V_223 ;
} else {
V_258 = false ;
F_76 ( V_2 , V_223 , & V_257 ) ;
}
F_74 ( V_2 , V_257 ) ;
V_2 -> V_8 += V_223 -> V_11 + V_257 -> V_140 . V_11 ;
if ( ! V_258 )
F_26 ( V_257 ) ;
}
F_39 ( V_2 -> V_12 , L_52 , V_4 ) ;
return 0 ;
}
static void F_78 ( struct V_50 * V_51 ,
struct V_259 * V_260 )
{
struct V_261 * V_262 ;
unsigned char V_263 , V_264 ;
unsigned char V_265 , V_266 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_260 -> V_267 ; V_18 ++ ) {
V_262 = & V_260 -> V_262 [ V_18 ] ;
if ( V_262 -> V_20 != V_260 -> V_268 )
continue;
V_51 -> V_269 = V_262 -> V_270 & V_271 ;
V_265 = V_262 -> V_265 ;
V_266 = V_262 -> V_266 ;
if ( ! V_265 && ! V_266 )
V_51 -> V_269 |= V_272 ;
else if ( ! V_265 && V_266 )
V_51 -> V_269 |= V_273 ;
else if ( V_265 && ! V_266 )
V_51 -> V_269 |= V_274 ;
else
V_51 -> V_269 |= V_275 ;
V_263 = V_262 -> V_263 ;
V_264 = V_262 -> V_264 ;
if ( ! V_263 && ! V_264 )
V_51 -> V_269 |= V_276 ;
else if ( V_263 && ! V_264 )
V_51 -> V_269 |= V_277 ;
else if ( ! V_263 && V_264 )
V_51 -> V_269 |= V_278 ;
else
V_51 -> V_269 |= V_279 ;
}
}
static int F_79 ( struct V_1 * V_2 ,
struct V_259 * V_245 ,
struct V_259 * * V_51 )
{
struct V_259 * V_243 ;
struct V_280 * V_253 ;
int V_18 ;
* V_51 = NULL ;
if ( V_245 -> V_11 != sizeof( struct V_280 ) ) {
F_2 ( V_2 -> V_12 , L_53 ) ;
return - V_13 ;
}
F_65 ( V_2 -> V_12 , L_54 ) ;
V_253 = (struct V_280 * ) V_245 ;
V_243 = F_37 ( sizeof( * V_243 ) , V_129 ) ;
if ( ! V_243 )
return - V_63 ;
V_243 -> V_11 = sizeof( * V_243 ) ;
V_243 -> V_20 = V_253 -> V_20 ;
V_243 -> V_255 = V_253 -> V_255 ;
for ( V_18 = 0 ; V_18 < V_243 -> V_255 ; V_18 ++ )
memcpy ( & V_243 -> V_204 [ V_18 ] , & V_253 -> V_204 [ V_18 ] ,
sizeof( struct V_256 ) ) ;
* V_51 = V_243 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_259 * V_260 )
{
struct V_50 * V_51 ;
const char * V_34 , * V_96 ;
T_1 V_281 ;
int V_36 ;
V_281 = F_42 ( V_260 -> V_34 , V_139 ) ;
if ( V_281 == V_139 )
return - V_13 ;
else if ( V_281 )
V_34 = V_260 -> V_34 ;
else
V_34 = NULL ;
V_281 = F_42 ( V_260 -> V_96 , V_139 ) ;
if ( V_281 == V_139 )
return - V_13 ;
else if ( V_281 )
V_96 = V_260 -> V_96 ;
else
V_96 = NULL ;
V_51 = F_81 ( V_2 -> V_37 -> V_55 , V_260 -> V_20 ,
V_34 , V_96 ) ;
if ( ! V_51 ) {
F_2 ( V_2 -> V_12 , L_55 ,
V_34 , V_260 -> V_20 ) ;
return - V_13 ;
}
if ( V_260 -> V_267 )
F_78 ( V_51 , V_260 ) ;
if ( V_260 -> V_214 )
F_71 ( V_51 , V_260 -> V_214 , V_260 -> V_215 ) ;
V_36 = F_16 ( V_2 , V_51 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_12 , L_56 ) ;
return V_36 ;
}
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_259 * V_51 , * V_282 ;
int V_4 = V_28 -> V_4 ;
int V_18 , V_36 ;
bool V_258 ;
if ( V_2 -> V_40 != V_283 ) {
V_2 -> V_8 += V_28 -> V_11 + V_28 -> V_169 ;
return 0 ;
} ;
V_51 = (struct V_259 * ) V_2 -> V_8 ;
if ( V_51 -> V_11 > sizeof( struct V_259 )
|| V_51 -> V_11 < sizeof( struct V_280 ) ) {
F_2 ( V_2 -> V_12 , L_57 ,
V_51 -> V_11 ) ;
return - V_13 ;
}
if ( F_1 ( V_2 ,
V_51 -> V_11 , V_4 ,
V_28 -> V_169 , L_58 ) ) {
F_2 ( V_2 -> V_12 , L_59 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_51 = (struct V_259 * ) V_2 -> V_8 ;
if ( V_51 -> V_11 == sizeof( * V_51 ) ) {
V_258 = true ;
V_282 = V_51 ;
} else {
V_258 = false ;
V_36 = F_79 ( V_2 , V_51 , & V_282 ) ;
if ( V_36 < 0 )
return V_36 ;
}
V_36 = F_80 ( V_2 , V_282 ) ;
if ( V_36 < 0 )
return V_36 ;
V_2 -> V_8 += V_51 -> V_11 + V_282 -> V_140 . V_11 ;
if ( ! V_258 )
F_26 ( V_282 ) ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_284 * V_285 )
{
struct V_286 V_287 = { 0 } ;
struct V_288 * V_289 ;
struct V_47 * V_48 ;
struct V_203 * V_204 ;
struct V_205 * V_206 ;
int V_36 ;
V_287 . V_224 = V_285 -> V_224 ;
V_289 = F_84 ( & V_287 ) ;
if ( ! V_289 ) {
F_2 ( V_2 -> V_12 , L_60 ,
V_285 -> V_224 ) ;
return - V_13 ;
}
if ( V_285 -> V_225 != V_289 -> V_20 ) {
F_2 ( V_2 -> V_12 , L_61 ,
V_285 -> V_224 ) ;
return - V_13 ;
}
V_48 = V_289 -> V_290 ;
if ( ! V_48 )
return - V_13 ;
if ( V_285 -> V_226 ) {
V_204 = & V_48 -> V_226 ;
V_206 = & V_285 -> V_206 [ V_227 ] ;
F_67 ( V_204 , V_206 ) ;
}
if ( V_285 -> V_228 ) {
V_204 = & V_48 -> V_228 ;
V_206 = & V_285 -> V_206 [ V_229 ] ;
F_67 ( V_204 , V_206 ) ;
}
if ( V_285 -> V_214 )
F_68 ( V_48 , V_285 -> V_214 , V_285 -> V_215 ) ;
V_36 = F_15 ( V_2 , V_48 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_37 -> V_12 , L_43 ) ;
return V_36 ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_284 * V_289 ;
int V_4 = V_28 -> V_4 ;
int V_18 ;
if ( V_2 -> V_40 != V_291 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_289 = (struct V_284 * ) V_2 -> V_8 ;
if ( V_289 -> V_11 != sizeof( * V_289 ) ) {
F_2 ( V_2 -> V_12 , L_62 ) ;
return - V_13 ;
}
F_83 ( V_2 , V_289 ) ;
V_2 -> V_8 += ( sizeof( * V_289 ) + V_289 -> V_140 . V_11 ) ;
}
F_39 ( V_2 -> V_12 , L_63 , V_4 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_292 * V_245 ,
struct V_292 * * V_293 )
{
struct V_292 * V_243 ;
struct V_294 * V_253 ;
* V_293 = NULL ;
if ( V_245 -> V_11 != sizeof( * V_253 ) ) {
F_2 ( V_2 -> V_12 , L_64 ) ;
return - V_13 ;
}
F_65 ( V_2 -> V_12 , L_65 ) ;
V_253 = (struct V_294 * ) V_245 ;
V_243 = F_37 ( sizeof( * V_243 ) + V_253 -> V_140 . V_11 , V_129 ) ;
if ( ! V_243 )
return - V_63 ;
V_243 -> V_11 = sizeof( * V_243 ) ;
V_243 -> V_295 = V_253 -> V_295 ;
V_243 -> V_296 = V_253 -> V_296 ;
V_243 -> V_297 = V_253 -> V_297 ;
V_243 -> V_298 = V_253 -> V_298 ;
V_243 -> V_299 = V_253 -> V_299 ;
V_243 -> V_140 . V_11 = V_253 -> V_140 . V_11 ;
if ( V_243 -> V_140 . V_11 )
memcpy ( V_243 -> V_140 . V_10 , V_253 -> V_140 . V_10 ,
V_253 -> V_140 . V_11 ) ;
* V_293 = V_243 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_292 * V_293 , * V_300 ;
bool V_258 ;
int V_62 ;
if ( V_2 -> V_40 != V_301 )
return 0 ;
V_293 = (struct V_292 * ) V_2 -> V_8 ;
if ( V_293 -> V_11 == sizeof( * V_293 ) ) {
V_258 = true ;
V_300 = V_293 ;
} else {
V_258 = false ;
V_62 = F_86 ( V_2 , V_293 , & V_300 ) ;
if ( V_62 < 0 )
return V_62 ;
}
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_293 )
return V_2 -> V_30 -> V_293 ( V_2 -> V_37 , V_300 ) ;
if ( ! V_258 )
F_26 ( V_300 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
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
if ( V_28 -> V_302 == F_89 ( V_303 ) ) {
F_2 ( V_2 -> V_12 ,
L_67 ,
V_2 -> V_40 , V_28 -> V_302 ,
F_4 ( V_2 ) , V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_28 -> V_302 != V_303 ) {
F_2 ( V_2 -> V_12 ,
L_68 ,
V_2 -> V_40 , V_28 -> V_302 ,
F_4 ( V_2 ) , V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_28 -> V_304 > V_305
|| V_28 -> V_304 < V_306 ) {
F_2 ( V_2 -> V_12 ,
L_69 ,
V_2 -> V_40 , V_28 -> V_304 ,
V_305 , F_4 ( V_2 ) ,
V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_28 -> V_169 == 0 ) {
F_2 ( V_2 -> V_12 , L_70 ,
F_4 ( V_2 ) ) ;
return - V_13 ;
}
if ( V_2 -> V_40 == V_28 -> type )
F_39 ( V_2 -> V_12 ,
L_71 ,
V_28 -> V_169 , V_28 -> type , V_28 -> V_307 ,
V_28 -> V_39 , V_2 -> V_40 ) ;
return 1 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
V_2 -> V_8 = V_2 -> V_14 + sizeof( struct V_35 ) ;
if ( V_28 -> V_29 != V_2 -> V_308 &&
V_28 -> V_29 != V_309 )
return 0 ;
V_2 -> V_29 = V_28 -> V_29 ;
switch ( V_28 -> type ) {
case V_92 :
case V_87 :
case V_199 :
return F_51 ( V_2 , V_28 ) ;
case V_310 :
return F_52 ( V_2 , V_28 ) ;
case V_311 :
return F_63 ( V_2 , V_28 ) ;
case V_312 :
return F_77 ( V_2 , V_28 ) ;
case V_313 :
return F_85 ( V_2 , V_28 ) ;
case V_314 :
case V_315 :
return F_82 ( V_2 , V_28 ) ;
case V_316 :
return F_87 ( V_2 , V_28 ) ;
default:
return F_13 ( V_2 , V_28 ) ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_35 * V_28 ;
int V_36 ;
V_2 -> V_40 = V_317 ;
while ( V_2 -> V_40 <= V_318 ) {
V_2 -> V_14 = V_2 -> V_9 -> V_10 ;
V_28 = (struct V_35 * ) V_2 -> V_14 ;
while ( ! F_3 ( V_2 ) ) {
V_36 = F_88 ( V_2 , V_28 ) ;
if ( V_36 < 0 )
return V_36 ;
else if ( V_36 == 0 )
break;
V_36 = F_90 ( V_2 , V_28 ) ;
if ( V_36 < 0 )
return V_36 ;
V_2 -> V_14 += V_28 -> V_169 +
sizeof( struct V_35 ) ;
V_28 = (struct V_35 * ) V_2 -> V_14 ;
}
V_2 -> V_40 ++ ;
}
V_36 = F_64 ( V_2 ) ;
if ( V_36 < 0 )
F_2 ( V_2 -> V_12 ,
L_72 ) ;
return V_36 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_36 ;
V_36 = F_91 ( V_2 ) ;
if ( V_36 == 0 )
F_17 ( V_2 ) ;
return V_36 ;
}
int F_93 ( struct V_65 * V_37 ,
struct V_319 * V_30 , const struct V_320 * V_9 , V_158 V_20 )
{
struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_9 = V_9 ;
V_2 . V_12 = V_37 -> V_12 ;
V_2 . V_37 = V_37 ;
V_2 . V_30 = V_30 ;
V_2 . V_308 = V_20 ;
V_2 . V_116 = V_30 -> V_116 ;
V_2 . V_117 = V_30 -> V_117 ;
V_2 . V_114 = V_30 -> V_114 ;
V_2 . V_115 = V_30 -> V_115 ;
return F_92 ( & V_2 ) ;
}
void F_94 ( struct V_42 * V_43 )
{
if ( V_43 -> V_67 . type != V_202 )
return;
F_29 ( V_43 -> V_178 -> V_321 , & V_43 -> V_67 , V_83 ) ;
}
void F_95 ( struct V_177 * V_178 ,
V_158 V_29 )
{
struct V_42 * V_43 , * V_322 ;
F_96 (w, next_w, &dapm->card->widgets, list) {
if ( V_43 -> V_67 . type != V_202 || V_43 -> V_178 != V_178 )
continue;
if ( V_43 -> V_67 . V_29 != V_29 &&
V_43 -> V_67 . V_29 != V_309 )
continue;
F_94 ( V_43 ) ;
F_97 ( V_43 ) ;
}
F_98 ( V_178 ) ;
}
int F_99 ( struct V_65 * V_37 , V_158 V_29 )
{
struct V_66 * V_67 , * V_323 ;
int V_40 = V_318 ;
while ( V_40 >= V_317 ) {
F_96 (dobj, next_dobj, &comp->dobj_list,
list) {
if ( V_67 -> V_29 != V_29 &&
V_67 -> V_29 != V_309 )
continue;
switch ( V_67 -> type ) {
case V_153 :
F_22 ( V_37 , V_67 , V_40 ) ;
break;
case V_162 :
F_27 ( V_37 , V_67 , V_40 ) ;
break;
case V_142 :
F_28 ( V_37 , V_67 , V_40 ) ;
break;
case V_202 :
F_29 ( V_37 , V_67 , V_40 ) ;
break;
case V_230 :
F_30 ( V_37 , V_67 , V_40 ) ;
break;
case V_242 :
F_31 ( V_37 , V_67 , V_40 ) ;
break;
default:
F_2 ( V_37 -> V_12 , L_73 ,
V_67 -> type ) ;
break;
}
}
V_40 -- ;
}
return ! F_100 ( & V_37 -> V_143 ) ;
}
