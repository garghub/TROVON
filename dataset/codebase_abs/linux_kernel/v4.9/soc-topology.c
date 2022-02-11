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
if ( V_67 -> V_85 . V_86 ) {
struct V_76 * V_77 =
(struct V_76 * ) V_43 -> V_87 [ 0 ] -> V_88 ;
F_24 ( V_55 , V_43 -> V_87 [ 0 ] ) ;
F_26 ( V_77 -> V_67 . V_73 . V_78 ) ;
for ( V_18 = 0 ; V_18 < V_77 -> V_79 ; V_18 ++ )
F_26 ( V_77 -> V_67 . V_73 . V_80 [ V_18 ] ) ;
F_26 ( V_77 ) ;
F_26 ( V_43 -> V_89 ) ;
} else {
for ( V_18 = 0 ; V_18 < V_43 -> V_90 ; V_18 ++ ) {
struct V_60 * V_61 = V_43 -> V_87 [ V_18 ] ;
struct V_68 * V_69 =
(struct V_68 * ) V_61 -> V_88 ;
F_26 ( V_43 -> V_87 [ V_18 ] -> V_74 . V_70 ) ;
F_24 ( V_55 , V_43 -> V_87 [ V_18 ] ) ;
F_26 ( V_69 ) ;
}
F_26 ( V_43 -> V_89 ) ;
}
}
static void F_30 ( struct V_65 * V_37 ,
struct V_66 * V_67 , int V_40 )
{
struct V_47 * V_48 =
F_23 ( V_67 , struct V_47 , V_67 ) ;
if ( V_40 != V_91 )
return;
if ( V_67 -> V_30 && V_67 -> V_30 -> V_92 )
V_67 -> V_30 -> V_92 ( V_37 , V_67 ) ;
F_25 ( & V_67 -> V_75 ) ;
F_26 ( V_48 ) ;
}
static void F_31 ( struct V_65 * V_37 ,
struct V_66 * V_67 , int V_40 )
{
struct V_50 * V_51 =
F_23 ( V_67 , struct V_50 , V_67 ) ;
if ( V_40 != V_91 )
return;
if ( V_67 -> V_30 && V_67 -> V_30 -> V_93 )
V_67 -> V_30 -> V_93 ( V_37 , V_67 ) ;
F_25 ( & V_67 -> V_75 ) ;
F_32 ( V_37 -> V_55 , V_51 ) ;
F_26 ( V_51 ) ;
}
static int F_33 ( struct V_27 * V_28 ,
struct V_57 * V_64 ,
const struct V_1 * V_2 )
{
const struct V_94 * V_30 ;
const struct V_95 * V_96 ;
int V_97 , V_18 ;
if ( V_28 -> V_30 . V_33 == V_98
&& V_64 -> V_99 & V_100
&& V_64 -> V_101 & V_102
&& V_64 -> V_101 & V_103 ) {
struct V_81 * V_104 ;
struct V_105 * V_106 ;
V_104 = (struct V_81 * ) V_64 -> V_88 ;
V_106 = F_23 ( V_28 , struct V_105 , V_28 ) ;
V_64 -> V_33 = V_107 ;
V_64 -> V_74 . V_108 = V_109 ;
V_96 = V_2 -> V_110 ;
V_97 = V_2 -> V_111 ;
for ( V_18 = 0 ; V_18 < V_97 ; V_18 ++ ) {
if ( ! V_104 -> V_32 && V_96 [ V_18 ] . V_20 == V_106 -> V_96 . V_32 )
V_104 -> V_32 = V_96 [ V_18 ] . V_32 ;
if ( ! V_104 -> V_31 && V_96 [ V_18 ] . V_20 == V_106 -> V_96 . V_31 )
V_104 -> V_31 = V_96 [ V_18 ] . V_31 ;
}
if ( V_104 -> V_32 && V_104 -> V_31 )
return 0 ;
else
return - V_13 ;
}
V_30 = V_2 -> V_112 ;
V_97 = V_2 -> V_113 ;
for ( V_18 = 0 ; V_18 < V_97 ; V_18 ++ ) {
if ( V_64 -> V_32 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_32 )
V_64 -> V_32 = V_30 [ V_18 ] . V_32 ;
if ( V_64 -> V_31 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_31 )
V_64 -> V_31 = V_30 [ V_18 ] . V_31 ;
if ( V_64 -> V_33 == NULL && V_30 [ V_18 ] . V_20 == V_28 -> V_30 . V_33 )
V_64 -> V_33 = V_30 [ V_18 ] . V_33 ;
}
if ( V_64 -> V_32 && V_64 -> V_31 && V_64 -> V_33 )
return 0 ;
V_30 = V_112 ;
V_97 = F_9 ( V_112 ) ;
for ( V_18 = 0 ; V_18 < V_97 ; V_18 ++ ) {
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
const struct V_114 * V_115 ,
int V_116 , T_3 V_117 )
{
int V_18 ;
V_43 -> V_118 = NULL ;
for ( V_18 = 0 ; V_18 < V_116 ; V_18 ++ ) {
if ( V_117 == V_115 [ V_18 ] . type ) {
V_43 -> V_118 = V_115 [ V_18 ] . V_119 ;
return 0 ;
}
}
return - V_13 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_57 * V_64 , struct V_27 * V_28 )
{
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_120 )
return V_2 -> V_30 -> V_120 ( V_2 -> V_37 , V_64 , V_28 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_57 * V_121 , struct V_122 * V_123 )
{
unsigned int V_124 = 2 * sizeof( unsigned int ) ;
unsigned int * V_70 ;
V_70 = F_37 ( V_124 + 2 * sizeof( unsigned int ) , V_125 ) ;
if ( ! V_70 )
return - V_63 ;
V_70 [ 0 ] = V_126 ;
V_70 [ 1 ] = V_124 ;
V_70 [ 2 ] = V_123 -> V_127 ;
V_70 [ 3 ] = ( V_123 -> V_128 & V_129 )
| ( V_123 -> V_130 ? V_131 : 0 ) ;
V_121 -> V_74 . V_70 = ( void * ) V_70 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_57 * V_121 , struct V_27 * V_132 )
{
struct V_133 * V_134 ;
if ( ! ( V_132 -> V_101 & V_102 ) )
return 0 ;
if ( ! ( V_132 -> V_101 & V_103 ) ) {
V_134 = & V_132 -> V_74 ;
switch ( V_134 -> type ) {
case V_126 :
return F_36 ( V_2 , V_121 ,
& V_134 -> V_123 ) ;
default:
F_39 ( V_2 -> V_12 , L_9 ,
V_134 -> type ) ;
return - V_13 ;
}
}
return 0 ;
}
static inline void F_40 ( struct V_1 * V_2 ,
struct V_57 * V_121 )
{
F_26 ( V_121 -> V_74 . V_70 ) ;
}
static int F_41 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_105 * V_106 ;
struct V_81 * V_104 ;
struct V_57 V_121 ;
int V_18 , V_62 ;
if ( F_1 ( V_2 ,
sizeof( struct V_105 ) , V_4 ,
V_11 , L_10 ) ) {
F_2 ( V_2 -> V_12 , L_11 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_106 = (struct V_105 * ) V_2 -> V_8 ;
if ( F_42 ( V_106 -> V_28 . V_34 , V_135 ) ==
V_135 )
return - V_13 ;
V_104 = F_37 ( sizeof( * V_104 ) , V_125 ) ;
if ( V_104 == NULL )
return - V_63 ;
V_2 -> V_8 += ( sizeof( struct V_105 ) +
V_106 -> V_136 . V_11 ) ;
F_39 ( V_2 -> V_12 ,
L_12 ,
V_106 -> V_28 . V_34 , V_106 -> V_28 . V_101 ) ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_34 = V_106 -> V_28 . V_34 ;
V_121 . V_88 = ( long ) V_104 ;
V_121 . V_99 = V_100 ;
V_121 . V_101 = V_106 -> V_28 . V_101 ;
V_104 -> V_137 = V_106 -> V_137 ;
V_104 -> V_67 . type = V_138 ;
V_104 -> V_67 . V_30 = V_2 -> V_30 ;
F_43 ( & V_104 -> V_67 . V_75 ) ;
V_62 = F_33 ( & V_106 -> V_28 , & V_121 , V_2 ) ;
if ( V_62 ) {
F_11 ( V_2 , & V_106 -> V_28 , V_106 -> V_28 . V_34 ) ;
F_26 ( V_104 ) ;
continue;
}
V_62 = F_35 ( V_2 , & V_121 ,
(struct V_27 * ) V_106 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_106 -> V_28 . V_34 ) ;
F_26 ( V_104 ) ;
continue;
}
V_62 = F_21 ( V_2 , & V_121 ,
& V_104 -> V_67 . V_73 . V_61 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_14 ,
V_106 -> V_28 . V_34 ) ;
F_26 ( V_104 ) ;
continue;
}
F_44 ( & V_104 -> V_67 . V_75 , & V_2 -> V_37 -> V_139 ) ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_140 * V_141 ;
struct V_68 * V_69 ;
struct V_57 V_121 ;
int V_18 , V_62 ;
if ( F_1 ( V_2 ,
sizeof( struct V_140 ) ,
V_4 , V_11 , L_15 ) ) {
F_2 ( V_2 -> V_12 , L_16 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_141 = (struct V_140 * ) V_2 -> V_8 ;
if ( F_42 ( V_141 -> V_28 . V_34 , V_135 ) ==
V_135 )
return - V_13 ;
V_69 = F_37 ( sizeof( * V_69 ) , V_125 ) ;
if ( V_69 == NULL )
return - V_63 ;
V_2 -> V_8 += ( sizeof( struct V_140 ) +
V_141 -> V_136 . V_11 ) ;
F_39 ( V_2 -> V_12 ,
L_17 ,
V_141 -> V_28 . V_34 , V_141 -> V_28 . V_101 ) ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_34 = V_141 -> V_28 . V_34 ;
V_121 . V_88 = ( long ) V_69 ;
V_121 . V_99 = V_100 ;
V_121 . V_101 = V_141 -> V_28 . V_101 ;
V_69 -> V_21 = F_6 ( V_2 , V_141 -> V_142 ,
V_143 ) ;
V_69 -> V_144 = F_6 ( V_2 , V_141 -> V_142 ,
V_145 ) ;
V_69 -> V_22 = F_7 ( V_2 , V_141 -> V_142 ,
V_143 ) ;
V_69 -> V_146 = F_7 ( V_2 , V_141 -> V_142 ,
V_145 ) ;
V_69 -> V_137 = V_141 -> V_137 ;
V_69 -> V_127 = V_141 -> V_127 ;
V_69 -> V_147 = V_141 -> V_147 ;
V_69 -> V_148 = V_141 -> V_148 ;
V_69 -> V_67 . V_29 = V_2 -> V_29 ;
V_69 -> V_67 . V_30 = V_2 -> V_30 ;
V_69 -> V_67 . type = V_149 ;
F_43 ( & V_69 -> V_67 . V_75 ) ;
V_62 = F_33 ( & V_141 -> V_28 , & V_121 , V_2 ) ;
if ( V_62 ) {
F_11 ( V_2 , & V_141 -> V_28 , V_141 -> V_28 . V_34 ) ;
F_26 ( V_69 ) ;
continue;
}
V_62 = F_35 ( V_2 , & V_121 ,
(struct V_27 * ) V_141 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_141 -> V_28 . V_34 ) ;
F_26 ( V_69 ) ;
continue;
}
F_38 ( V_2 , & V_121 , & V_141 -> V_28 ) ;
V_62 = F_21 ( V_2 , & V_121 ,
& V_69 -> V_67 . V_73 . V_61 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_14 ,
V_141 -> V_28 . V_34 ) ;
F_40 ( V_2 , & V_121 ) ;
F_26 ( V_69 ) ;
continue;
}
F_44 ( & V_69 -> V_67 . V_75 , & V_2 -> V_37 -> V_139 ) ;
}
return 0 ;
}
static int F_46 ( struct V_76 * V_77 ,
struct V_150 * V_151 )
{
int V_18 , V_36 ;
V_77 -> V_67 . V_73 . V_80 =
F_37 ( sizeof( char * ) * V_151 -> V_79 , V_125 ) ;
if ( V_77 -> V_67 . V_73 . V_80 == NULL )
return - V_63 ;
for ( V_18 = 0 ; V_18 < V_151 -> V_79 ; V_18 ++ ) {
if ( F_42 ( V_151 -> V_152 [ V_18 ] , V_135 ) ==
V_135 ) {
V_36 = - V_13 ;
goto V_62;
}
V_77 -> V_67 . V_73 . V_80 [ V_18 ] = F_47 ( V_151 -> V_152 [ V_18 ] , V_125 ) ;
if ( ! V_77 -> V_67 . V_73 . V_80 [ V_18 ] ) {
V_36 = - V_63 ;
goto V_62;
}
}
return 0 ;
V_62:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_26 ( V_77 -> V_67 . V_73 . V_80 [ V_18 ] ) ;
F_26 ( V_77 -> V_67 . V_73 . V_80 ) ;
return V_36 ;
}
static int F_48 ( struct V_76 * V_77 ,
struct V_150 * V_151 )
{
if ( V_151 -> V_79 > sizeof( * V_151 -> V_153 ) )
return - V_13 ;
V_77 -> V_67 . V_73 . V_78 = F_49 ( V_151 -> V_153 ,
V_151 -> V_79 * sizeof( V_154 ) ,
V_125 ) ;
if ( ! V_77 -> V_67 . V_73 . V_78 )
return - V_63 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , unsigned int V_4 ,
T_1 V_11 )
{
struct V_150 * V_151 ;
struct V_76 * V_77 ;
struct V_57 V_121 ;
int V_18 , V_36 , V_62 ;
if ( F_1 ( V_2 ,
sizeof( struct V_150 ) ,
V_4 , V_11 , L_18 ) ) {
F_2 ( V_2 -> V_12 , L_19 ,
V_4 ) ;
return - V_13 ;
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_151 = (struct V_150 * ) V_2 -> V_8 ;
V_2 -> V_8 += ( sizeof( struct V_150 ) +
V_151 -> V_136 . V_11 ) ;
if ( F_42 ( V_151 -> V_28 . V_34 , V_135 ) ==
V_135 )
return - V_13 ;
V_77 = F_37 ( ( sizeof( * V_77 ) ) , V_125 ) ;
if ( V_77 == NULL )
return - V_63 ;
F_39 ( V_2 -> V_12 , L_20 ,
V_151 -> V_28 . V_34 , V_151 -> V_79 ) ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_34 = V_151 -> V_28 . V_34 ;
V_121 . V_88 = ( long ) V_77 ;
V_121 . V_99 = V_100 ;
V_121 . V_101 = V_151 -> V_28 . V_101 ;
V_77 -> V_21 = F_6 ( V_2 , V_151 -> V_142 , V_143 ) ;
V_77 -> V_155 = F_7 ( V_2 , V_151 -> V_142 ,
V_143 ) ;
V_77 -> V_156 = F_7 ( V_2 , V_151 -> V_142 ,
V_143 ) ;
V_77 -> V_79 = V_151 -> V_79 ;
V_77 -> V_157 = V_151 -> V_157 ;
V_77 -> V_67 . V_29 = V_2 -> V_29 ;
V_77 -> V_67 . type = V_158 ;
V_77 -> V_67 . V_30 = V_2 -> V_30 ;
F_43 ( & V_77 -> V_67 . V_75 ) ;
switch ( V_151 -> V_28 . V_30 . V_33 ) {
case V_159 :
case V_160 :
V_62 = F_48 ( V_77 , V_151 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 ,
L_21 ,
V_151 -> V_28 . V_34 ) ;
F_26 ( V_77 ) ;
continue;
}
case V_161 :
case V_162 :
case V_163 :
V_62 = F_46 ( V_77 , V_151 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 ,
L_22 ,
V_151 -> V_28 . V_34 ) ;
F_26 ( V_77 ) ;
continue;
}
break;
default:
F_2 ( V_2 -> V_12 ,
L_23 ,
V_151 -> V_28 . V_30 . V_33 , V_151 -> V_28 . V_34 ) ;
F_26 ( V_77 ) ;
continue;
}
V_62 = F_33 ( & V_151 -> V_28 , & V_121 , V_2 ) ;
if ( V_62 ) {
F_11 ( V_2 , & V_151 -> V_28 , V_151 -> V_28 . V_34 ) ;
F_26 ( V_77 ) ;
continue;
}
V_62 = F_35 ( V_2 , & V_121 ,
(struct V_27 * ) V_151 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_151 -> V_28 . V_34 ) ;
F_26 ( V_77 ) ;
continue;
}
V_36 = F_21 ( V_2 ,
& V_121 , & V_77 -> V_67 . V_73 . V_61 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_12 , L_24 ,
V_151 -> V_28 . V_34 ) ;
F_26 ( V_77 ) ;
continue;
}
F_44 ( & V_77 -> V_67 . V_75 , & V_2 -> V_37 -> V_139 ) ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_27 * V_164 ;
int V_18 ;
if ( V_2 -> V_40 != V_71 ) {
V_2 -> V_8 += V_28 -> V_11 + V_28 -> V_165 ;
return 0 ;
}
F_39 ( V_2 -> V_12 , L_25 , V_28 -> V_4 ,
F_5 ( V_2 ) ) ;
for ( V_18 = 0 ; V_18 < V_28 -> V_4 ; V_18 ++ ) {
V_164 = (struct V_27 * ) V_2 -> V_8 ;
if ( V_164 -> V_11 != sizeof( * V_164 ) ) {
F_2 ( V_2 -> V_12 , L_26 ) ;
return - V_13 ;
}
switch ( V_164 -> V_30 . V_33 ) {
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
F_45 ( V_2 , 1 , V_28 -> V_165 ) ;
break;
case V_161 :
case V_160 :
case V_162 :
case V_163 :
case V_159 :
F_50 ( V_2 , 1 , V_28 -> V_165 ) ;
break;
case V_98 :
F_41 ( V_2 , 1 , V_28 -> V_165 ) ;
break;
default:
F_10 ( V_2 , V_164 , V_18 ) ;
return - V_13 ;
}
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_173 * V_174 = & V_2 -> V_37 -> V_174 ;
struct V_175 V_176 ;
struct V_177 * V_178 ;
int V_4 = V_28 -> V_4 , V_18 ;
if ( V_2 -> V_40 != V_179 ) {
V_2 -> V_8 += V_28 -> V_11 + V_28 -> V_165 ;
return 0 ;
}
if ( F_1 ( V_2 ,
sizeof( struct V_177 ) ,
V_4 , V_28 -> V_165 , L_27 ) ) {
F_2 ( V_2 -> V_12 , L_28 ,
V_4 ) ;
return - V_13 ;
}
F_39 ( V_2 -> V_12 , L_29 , V_4 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_178 = (struct V_177 * ) V_2 -> V_8 ;
V_2 -> V_8 += sizeof( struct V_177 ) ;
if ( F_42 ( V_178 -> V_180 , V_135 ) ==
V_135 )
return - V_13 ;
if ( F_42 ( V_178 -> V_181 , V_135 ) ==
V_135 )
return - V_13 ;
if ( F_42 ( V_178 -> V_73 , V_135 ) ==
V_135 )
return - V_13 ;
V_176 . V_180 = V_178 -> V_180 ;
V_176 . V_181 = V_178 -> V_181 ;
V_176 . V_182 = NULL ;
if ( F_42 ( V_178 -> V_73 , V_135 ) == 0 )
V_176 . V_73 = NULL ;
else
V_176 . V_73 = V_178 -> V_73 ;
F_53 ( V_174 , & V_176 , 1 ) ;
}
return 0 ;
}
static struct V_57 * F_54 (
struct V_1 * V_2 , int V_90 )
{
struct V_57 * V_121 ;
struct V_68 * V_69 ;
struct V_140 * V_141 ;
int V_18 , V_62 ;
V_121 = F_55 ( V_90 , sizeof( * V_121 ) , V_125 ) ;
if ( V_121 == NULL )
return NULL ;
for ( V_18 = 0 ; V_18 < V_90 ; V_18 ++ ) {
V_141 = (struct V_140 * ) V_2 -> V_8 ;
V_69 = F_37 ( sizeof( * V_69 ) , V_125 ) ;
if ( V_69 == NULL )
goto V_62;
V_2 -> V_8 += ( sizeof( struct V_140 ) +
V_141 -> V_136 . V_11 ) ;
if ( F_42 ( V_141 -> V_28 . V_34 , V_135 ) ==
V_135 )
goto V_183;
F_39 ( V_2 -> V_12 , L_30 ,
V_141 -> V_28 . V_34 , V_18 ) ;
V_121 [ V_18 ] . V_34 = V_141 -> V_28 . V_34 ;
V_121 [ V_18 ] . V_88 = ( long ) V_69 ;
V_121 [ V_18 ] . V_99 = V_100 ;
V_121 [ V_18 ] . V_101 = V_141 -> V_28 . V_101 ;
V_69 -> V_21 = F_6 ( V_2 , V_141 -> V_142 ,
V_143 ) ;
V_69 -> V_144 = F_6 ( V_2 , V_141 -> V_142 ,
V_145 ) ;
V_69 -> V_22 = F_7 ( V_2 , V_141 -> V_142 ,
V_143 ) ;
V_69 -> V_146 = F_7 ( V_2 , V_141 -> V_142 ,
V_145 ) ;
V_69 -> V_137 = V_141 -> V_137 ;
V_69 -> V_127 = V_141 -> V_127 ;
V_69 -> V_147 = V_141 -> V_147 ;
V_69 -> V_148 = V_141 -> V_148 ;
V_69 -> V_67 . V_29 = V_2 -> V_29 ;
F_43 ( & V_69 -> V_67 . V_75 ) ;
V_62 = F_33 ( & V_141 -> V_28 , & V_121 [ V_18 ] , V_2 ) ;
if ( V_62 ) {
F_11 ( V_2 , & V_141 -> V_28 , V_141 -> V_28 . V_34 ) ;
F_26 ( V_69 ) ;
continue;
}
V_62 = F_35 ( V_2 , & V_121 [ V_18 ] ,
(struct V_27 * ) V_141 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_141 -> V_28 . V_34 ) ;
F_26 ( V_69 ) ;
continue;
}
}
return V_121 ;
V_183:
F_26 ( V_69 ) ;
V_62:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_26 ( ( void * ) V_121 [ V_18 ] . V_88 ) ;
F_26 ( V_121 ) ;
return NULL ;
}
static struct V_57 * F_56 (
struct V_1 * V_2 )
{
struct V_57 * V_121 ;
struct V_150 * V_151 ;
struct V_76 * V_77 ;
int V_18 , V_62 ;
V_151 = (struct V_150 * ) V_2 -> V_8 ;
V_2 -> V_8 += ( sizeof( struct V_150 ) +
V_151 -> V_136 . V_11 ) ;
if ( F_42 ( V_151 -> V_28 . V_34 , V_135 ) ==
V_135 )
return NULL ;
V_121 = F_37 ( sizeof( * V_121 ) , V_125 ) ;
if ( V_121 == NULL )
return NULL ;
V_77 = F_37 ( sizeof( * V_77 ) , V_125 ) ;
if ( V_77 == NULL )
goto V_62;
F_39 ( V_2 -> V_12 , L_31 ,
V_151 -> V_28 . V_34 ) ;
V_121 -> V_34 = V_151 -> V_28 . V_34 ;
V_121 -> V_88 = ( long ) V_77 ;
V_121 -> V_99 = V_100 ;
V_121 -> V_101 = V_151 -> V_28 . V_101 ;
V_77 -> V_21 = F_6 ( V_2 , V_151 -> V_142 , V_143 ) ;
V_77 -> V_155 = F_7 ( V_2 , V_151 -> V_142 , V_143 ) ;
V_77 -> V_156 = F_7 ( V_2 , V_151 -> V_142 , V_145 ) ;
V_77 -> V_79 = V_151 -> V_79 ;
V_77 -> V_157 = V_151 -> V_157 ;
V_77 -> V_67 . V_29 = V_2 -> V_29 ;
switch ( V_151 -> V_28 . V_30 . V_33 ) {
case V_160 :
case V_159 :
V_62 = F_48 ( V_77 , V_151 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_21 ,
V_151 -> V_28 . V_34 ) ;
goto V_184;
}
case V_161 :
case V_162 :
case V_163 :
V_62 = F_46 ( V_77 , V_151 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_22 ,
V_151 -> V_28 . V_34 ) ;
goto V_184;
}
break;
default:
F_2 ( V_2 -> V_12 , L_23 ,
V_151 -> V_28 . V_30 . V_33 , V_151 -> V_28 . V_34 ) ;
goto V_184;
}
V_62 = F_33 ( & V_151 -> V_28 , V_121 , V_2 ) ;
if ( V_62 ) {
F_11 ( V_2 , & V_151 -> V_28 , V_151 -> V_28 . V_34 ) ;
goto V_184;
}
V_62 = F_35 ( V_2 , V_121 ,
(struct V_27 * ) V_151 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_151 -> V_28 . V_34 ) ;
goto V_184;
}
return V_121 ;
V_184:
F_26 ( V_77 -> V_67 . V_73 . V_78 ) ;
for ( V_18 = 0 ; V_18 < V_151 -> V_79 ; V_18 ++ )
F_26 ( V_77 -> V_67 . V_73 . V_80 [ V_18 ] ) ;
F_26 ( V_77 ) ;
V_62:
F_26 ( V_121 ) ;
return NULL ;
}
static struct V_57 * F_57 (
struct V_1 * V_2 , int V_4 )
{
struct V_105 * V_106 ;
struct V_81 * V_104 ;
struct V_57 * V_121 ;
int V_18 , V_62 ;
V_121 = F_55 ( V_4 , sizeof( * V_121 ) , V_125 ) ;
if ( ! V_121 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_106 = (struct V_105 * ) V_2 -> V_8 ;
if ( F_42 ( V_106 -> V_28 . V_34 , V_135 ) ==
V_135 )
goto V_62;
V_104 = F_37 ( sizeof( * V_104 ) , V_125 ) ;
if ( V_104 == NULL )
goto V_62;
V_2 -> V_8 += ( sizeof( struct V_105 ) +
V_106 -> V_136 . V_11 ) ;
F_39 ( V_2 -> V_12 ,
L_12 ,
V_106 -> V_28 . V_34 , V_106 -> V_28 . V_101 ) ;
V_121 [ V_18 ] . V_34 = V_106 -> V_28 . V_34 ;
V_121 [ V_18 ] . V_88 = ( long ) V_104 ;
V_121 [ V_18 ] . V_99 = V_100 ;
V_121 [ V_18 ] . V_101 = V_106 -> V_28 . V_101 ;
V_104 -> V_137 = V_106 -> V_137 ;
F_43 ( & V_104 -> V_67 . V_75 ) ;
V_62 = F_33 ( & V_106 -> V_28 , & V_121 [ V_18 ] , V_2 ) ;
if ( V_62 ) {
F_11 ( V_2 , & V_106 -> V_28 , V_106 -> V_28 . V_34 ) ;
F_26 ( V_104 ) ;
continue;
}
V_62 = F_35 ( V_2 , & V_121 [ V_18 ] ,
(struct V_27 * ) V_106 ) ;
if ( V_62 < 0 ) {
F_2 ( V_2 -> V_12 , L_13 ,
V_106 -> V_28 . V_34 ) ;
F_26 ( V_104 ) ;
continue;
}
}
return V_121 ;
V_62:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_26 ( ( void * ) V_121 [ V_18 ] . V_88 ) ;
F_26 ( V_121 ) ;
return NULL ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_44 * V_43 )
{
struct V_173 * V_174 = & V_2 -> V_37 -> V_174 ;
struct V_42 V_185 , * V_85 ;
struct V_27 * V_164 ;
struct V_186 * V_55 = V_2 -> V_37 -> V_55 ;
int V_36 = 0 ;
if ( F_42 ( V_43 -> V_34 , V_135 ) ==
V_135 )
return - V_13 ;
if ( F_42 ( V_43 -> V_187 , V_135 ) ==
V_135 )
return - V_13 ;
F_39 ( V_2 -> V_12 , L_32 ,
V_43 -> V_34 , V_43 -> V_20 ) ;
memset ( & V_185 , 0 , sizeof( V_185 ) ) ;
V_185 . V_20 = F_8 ( V_43 -> V_20 ) ;
if ( V_185 . V_20 < 0 )
return V_185 . V_20 ;
V_185 . V_34 = F_47 ( V_43 -> V_34 , V_125 ) ;
if ( ! V_185 . V_34 )
return - V_63 ;
V_185 . V_187 = F_47 ( V_43 -> V_187 , V_125 ) ;
if ( ! V_185 . V_187 ) {
V_36 = - V_63 ;
goto V_62;
}
V_185 . V_21 = V_43 -> V_21 ;
V_185 . V_22 = V_43 -> V_22 ;
V_185 . V_157 = V_43 -> V_157 ;
V_185 . V_188 = V_43 -> V_188 ;
V_185 . V_189 = V_43 -> V_147 ? 0 : 1 ;
V_185 . V_190 = V_43 -> V_147 ? 1 : 0 ;
V_185 . V_191 = V_43 -> V_191 ;
V_185 . V_192 = V_43 -> V_192 ;
V_185 . V_67 . V_29 = V_2 -> V_29 ;
V_2 -> V_8 +=
( sizeof( struct V_44 ) + V_43 -> V_136 . V_11 ) ;
if ( V_43 -> V_90 == 0 ) {
V_185 . V_90 = 0 ;
goto V_85;
}
V_164 = (struct V_27 * ) V_2 -> V_8 ;
F_39 ( V_2 -> V_12 , L_33 ,
V_43 -> V_34 , V_43 -> V_90 , V_164 -> type ) ;
switch ( V_164 -> V_30 . V_33 ) {
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
V_185 . V_90 = V_43 -> V_90 ;
V_185 . V_89 =
F_54 ( V_2 ,
V_185 . V_90 ) ;
if ( ! V_185 . V_89 ) {
V_36 = - V_63 ;
goto V_193;
}
break;
case V_161 :
case V_160 :
case V_162 :
case V_163 :
case V_159 :
V_185 . V_67 . V_85 . V_86 = 1 ;
V_185 . V_90 = 1 ;
V_185 . V_89 =
F_56 ( V_2 ) ;
if ( ! V_185 . V_89 ) {
V_36 = - V_63 ;
goto V_193;
}
break;
case V_98 :
V_185 . V_90 = V_43 -> V_90 ;
V_185 . V_89 =
F_57 ( V_2 ,
V_185 . V_90 ) ;
if ( ! V_185 . V_89 ) {
V_36 = - V_63 ;
goto V_193;
}
break;
default:
F_2 ( V_2 -> V_12 , L_34 ,
V_164 -> V_30 . V_31 , V_164 -> V_30 . V_32 ,
V_164 -> V_30 . V_33 ) ;
V_36 = - V_13 ;
goto V_193;
}
V_85:
V_36 = F_14 ( V_2 , & V_185 , V_43 ) ;
if ( V_36 < 0 )
goto V_193;
if ( V_55 -> V_194 )
V_85 = F_59 ( V_174 , & V_185 ) ;
else
V_85 = F_60 ( V_174 , & V_185 ) ;
if ( V_85 == NULL ) {
F_2 ( V_2 -> V_12 , L_35 ,
V_43 -> V_34 ) ;
V_36 = - V_63 ;
goto V_193;
}
V_85 -> V_67 . type = V_195 ;
V_85 -> V_67 . V_30 = V_2 -> V_30 ;
V_85 -> V_67 . V_29 = V_2 -> V_29 ;
F_26 ( V_185 . V_187 ) ;
F_26 ( V_185 . V_34 ) ;
F_44 ( & V_85 -> V_67 . V_75 , & V_2 -> V_37 -> V_139 ) ;
return 0 ;
V_193:
F_26 ( V_185 . V_187 ) ;
V_62:
F_26 ( V_185 . V_34 ) ;
return V_36 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_44 * V_85 ;
int V_36 , V_4 = V_28 -> V_4 , V_18 ;
if ( V_2 -> V_40 != V_83 )
return 0 ;
F_39 ( V_2 -> V_12 , L_36 , V_4 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_85 = (struct V_44 * ) V_2 -> V_8 ;
if ( V_85 -> V_11 != sizeof( * V_85 ) ) {
F_2 ( V_2 -> V_12 , L_37 ) ;
return - V_13 ;
}
V_36 = F_58 ( V_2 , V_85 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_12 , L_38 ,
V_85 -> V_34 ) ;
return V_36 ;
}
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_186 * V_55 = V_2 -> V_37 -> V_55 ;
int V_36 ;
if ( ! V_55 || ! V_55 -> V_194 ) {
F_63 ( V_2 -> V_12 , L_39
L_40 ) ;
return 0 ;
}
V_36 = F_64 ( V_55 ) ;
if ( V_36 < 0 )
F_2 ( V_2 -> V_12 , L_41 ,
V_36 ) ;
return 0 ;
}
static void F_65 ( struct V_196 * V_197 ,
struct V_198 * V_199 )
{
V_197 -> V_200 = F_47 ( V_199 -> V_34 , V_125 ) ;
V_197 -> V_201 = V_199 -> V_201 ;
V_197 -> V_202 = V_199 -> V_202 ;
V_197 -> V_203 = V_199 -> V_203 ;
V_197 -> V_204 = V_199 -> V_204 ;
V_197 -> V_205 = V_199 -> V_205 ;
V_197 -> V_206 = V_199 -> V_206 ;
V_197 -> V_207 = V_199 -> V_207 ;
}
static void F_66 ( struct V_47 * V_48 ,
unsigned int V_208 , unsigned int V_209 )
{
if ( V_208 & V_210 )
V_48 -> V_211 =
V_209 & V_210 ? 1 : 0 ;
if ( V_208 & V_212 )
V_48 -> V_213 =
V_209 & V_212 ?
1 : 0 ;
if ( V_208 & V_214 )
V_48 -> V_215 =
V_209 & V_214 ?
1 : 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
struct V_47 * V_48 ;
struct V_196 * V_197 ;
struct V_198 * V_199 ;
int V_36 ;
V_48 = F_37 ( sizeof( struct V_47 ) , V_125 ) ;
if ( V_48 == NULL )
return - V_63 ;
V_48 -> V_34 = V_217 -> V_218 ;
V_48 -> V_20 = V_217 -> V_219 ;
if ( V_217 -> V_220 ) {
V_197 = & V_48 -> V_220 ;
V_199 = & V_217 -> V_199 [ V_221 ] ;
F_65 ( V_197 , V_199 ) ;
}
if ( V_217 -> V_222 ) {
V_197 = & V_48 -> V_222 ;
V_199 = & V_217 -> V_199 [ V_223 ] ;
F_65 ( V_197 , V_199 ) ;
}
V_36 = F_15 ( V_2 , V_48 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_37 -> V_12 , L_42 ) ;
F_26 ( V_48 ) ;
return V_36 ;
}
V_48 -> V_67 . V_29 = V_2 -> V_29 ;
V_48 -> V_67 . V_30 = V_2 -> V_30 ;
V_48 -> V_67 . type = V_224 ;
F_44 ( & V_48 -> V_67 . V_75 , & V_2 -> V_37 -> V_139 ) ;
return F_68 ( V_2 -> V_37 , V_48 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
struct V_50 * V_51 ;
int V_36 ;
V_51 = F_37 ( sizeof( struct V_50 ) , V_125 ) ;
if ( V_51 == NULL )
return - V_63 ;
V_51 -> V_34 = V_217 -> V_225 ;
V_51 -> V_200 = V_217 -> V_225 ;
V_51 -> V_20 = V_217 -> V_226 ;
V_51 -> V_227 = V_217 -> V_218 ;
V_51 -> V_228 = L_43 ;
V_51 -> V_229 = L_44 ;
V_51 -> V_230 = 1 ;
V_51 -> V_231 = V_217 -> V_220 ;
V_51 -> V_232 = V_217 -> V_222 ;
V_36 = F_16 ( V_2 , V_51 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_37 -> V_12 , L_45 ) ;
F_26 ( V_51 ) ;
return V_36 ;
}
V_51 -> V_67 . V_29 = V_2 -> V_29 ;
V_51 -> V_67 . V_30 = V_2 -> V_30 ;
V_51 -> V_67 . type = V_233 ;
F_44 ( & V_51 -> V_67 . V_75 , & V_2 -> V_37 -> V_139 ) ;
F_70 ( V_2 -> V_37 -> V_55 , V_51 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
int V_36 ;
V_36 = F_67 ( V_2 , V_217 ) ;
if ( V_36 < 0 )
return V_36 ;
return F_69 ( V_2 , V_217 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_216 * V_217 ;
int V_4 = V_28 -> V_4 ;
int V_18 ;
if ( V_2 -> V_40 != V_91 )
return 0 ;
if ( F_1 ( V_2 ,
sizeof( struct V_216 ) , V_4 ,
V_28 -> V_165 , L_46 ) ) {
F_2 ( V_2 -> V_12 , L_47 ,
V_4 ) ;
return - V_13 ;
}
V_217 = (struct V_216 * ) V_2 -> V_8 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
if ( V_217 -> V_11 != sizeof( * V_217 ) ) {
F_2 ( V_2 -> V_12 , L_48 ) ;
return - V_13 ;
}
F_71 ( V_2 , V_217 ) ;
V_217 ++ ;
}
F_39 ( V_2 -> V_12 , L_49 , V_4 ) ;
V_2 -> V_8 += sizeof( struct V_216 ) * V_4 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_234 * V_106 )
{
struct V_235 V_236 = { 0 } ;
struct V_237 * V_238 ;
struct V_47 * V_48 ;
struct V_196 * V_197 ;
struct V_198 * V_199 ;
int V_36 ;
V_236 . V_218 = V_106 -> V_218 ;
V_238 = F_74 ( & V_236 ) ;
if ( ! V_238 ) {
F_2 ( V_2 -> V_12 , L_50 ,
V_106 -> V_218 ) ;
return - V_13 ;
}
if ( V_106 -> V_219 != V_238 -> V_20 ) {
F_2 ( V_2 -> V_12 , L_51 ,
V_106 -> V_218 ) ;
return - V_13 ;
}
V_48 = V_238 -> V_239 ;
if ( ! V_48 )
return - V_13 ;
if ( V_106 -> V_220 ) {
V_197 = & V_48 -> V_220 ;
V_199 = & V_106 -> V_199 [ V_221 ] ;
F_65 ( V_197 , V_199 ) ;
}
if ( V_106 -> V_222 ) {
V_197 = & V_48 -> V_222 ;
V_199 = & V_106 -> V_199 [ V_223 ] ;
F_65 ( V_197 , V_199 ) ;
}
if ( V_106 -> V_208 )
F_66 ( V_48 , V_106 -> V_208 , V_106 -> V_209 ) ;
V_36 = F_15 ( V_2 , V_48 ) ;
if ( V_36 < 0 ) {
F_2 ( V_2 -> V_37 -> V_12 , L_42 ) ;
return V_36 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_234 * V_106 ;
int V_4 = V_28 -> V_4 ;
int V_18 ;
if ( V_2 -> V_40 != V_240 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_106 = (struct V_234 * ) V_2 -> V_8 ;
if ( V_106 -> V_11 != sizeof( * V_106 ) ) {
F_2 ( V_2 -> V_12 , L_52 ) ;
return - V_13 ;
}
F_73 ( V_2 , V_106 ) ;
V_2 -> V_8 += ( sizeof( * V_106 ) + V_106 -> V_136 . V_11 ) ;
}
F_39 ( V_2 -> V_12 , L_53 , V_4 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
struct V_241 * V_242 ;
if ( V_2 -> V_40 != V_243 )
return 0 ;
V_242 = (struct V_241 * ) V_2 -> V_8 ;
if ( V_242 -> V_11 != sizeof( * V_242 ) ) {
F_2 ( V_2 -> V_12 , L_54 ) ;
return - V_13 ;
}
V_2 -> V_8 += sizeof( struct V_241 ) ;
if ( V_2 -> V_37 && V_2 -> V_30 && V_2 -> V_30 -> V_242 )
return V_2 -> V_30 -> V_242 ( V_2 -> V_37 , V_242 ) ;
F_2 ( V_2 -> V_12 , L_55 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
if ( F_4 ( V_2 ) >= V_2 -> V_9 -> V_11 )
return 0 ;
if ( V_28 -> V_11 != sizeof( * V_28 ) ) {
F_2 ( V_2 -> V_12 ,
L_56 ,
V_28 -> type , F_4 ( V_2 ) ,
V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_28 -> V_244 == F_78 ( V_245 ) ) {
F_2 ( V_2 -> V_12 ,
L_57 ,
V_2 -> V_40 , V_28 -> V_244 ,
F_4 ( V_2 ) , V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_28 -> V_244 != V_245 ) {
F_2 ( V_2 -> V_12 ,
L_58 ,
V_2 -> V_40 , V_28 -> V_244 ,
F_4 ( V_2 ) , V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_28 -> V_246 != V_247 ) {
F_2 ( V_2 -> V_12 ,
L_59 ,
V_2 -> V_40 , V_28 -> V_246 ,
V_247 , F_4 ( V_2 ) ,
V_2 -> V_9 -> V_11 ) ;
return - V_13 ;
}
if ( V_28 -> V_165 == 0 ) {
F_2 ( V_2 -> V_12 , L_60 ,
F_4 ( V_2 ) ) ;
return - V_13 ;
}
if ( V_2 -> V_40 == V_28 -> type )
F_39 ( V_2 -> V_12 ,
L_61 ,
V_28 -> V_165 , V_28 -> type , V_28 -> V_248 ,
V_28 -> V_39 , V_2 -> V_40 ) ;
return 1 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_35 * V_28 )
{
V_2 -> V_8 = V_2 -> V_14 + sizeof( struct V_35 ) ;
if ( V_28 -> V_29 != V_2 -> V_249 &&
V_28 -> V_29 != V_250 )
return 0 ;
V_2 -> V_29 = V_28 -> V_29 ;
switch ( V_28 -> type ) {
case V_251 :
case V_252 :
case V_253 :
return F_51 ( V_2 , V_28 ) ;
case V_254 :
return F_52 ( V_2 , V_28 ) ;
case V_255 :
return F_61 ( V_2 , V_28 ) ;
case V_256 :
return F_72 ( V_2 , V_28 ) ;
case V_257 :
return F_75 ( V_2 , V_28 ) ;
case V_258 :
return F_76 ( V_2 , V_28 ) ;
default:
return F_13 ( V_2 , V_28 ) ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_35 * V_28 ;
int V_36 ;
V_2 -> V_40 = V_259 ;
while ( V_2 -> V_40 <= V_260 ) {
V_2 -> V_14 = V_2 -> V_9 -> V_10 ;
V_28 = (struct V_35 * ) V_2 -> V_14 ;
while ( ! F_3 ( V_2 ) ) {
V_36 = F_77 ( V_2 , V_28 ) ;
if ( V_36 < 0 )
return V_36 ;
else if ( V_36 == 0 )
break;
V_36 = F_79 ( V_2 , V_28 ) ;
if ( V_36 < 0 )
return V_36 ;
V_2 -> V_14 += V_28 -> V_165 +
sizeof( struct V_35 ) ;
V_28 = (struct V_35 * ) V_2 -> V_14 ;
}
V_2 -> V_40 ++ ;
}
V_36 = F_62 ( V_2 ) ;
if ( V_36 < 0 )
F_2 ( V_2 -> V_12 ,
L_62 ) ;
return V_36 ;
}
static int F_81 ( struct V_1 * V_2 )
{
int V_36 ;
V_36 = F_80 ( V_2 ) ;
if ( V_36 == 0 )
F_17 ( V_2 ) ;
return V_36 ;
}
int F_82 ( struct V_65 * V_37 ,
struct V_261 * V_30 , const struct V_262 * V_9 , V_154 V_20 )
{
struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_9 = V_9 ;
V_2 . V_12 = V_37 -> V_12 ;
V_2 . V_37 = V_37 ;
V_2 . V_30 = V_30 ;
V_2 . V_249 = V_20 ;
V_2 . V_112 = V_30 -> V_112 ;
V_2 . V_113 = V_30 -> V_113 ;
V_2 . V_110 = V_30 -> V_110 ;
V_2 . V_111 = V_30 -> V_111 ;
return F_81 ( & V_2 ) ;
}
void F_83 ( struct V_42 * V_43 )
{
if ( V_43 -> V_67 . type != V_195 )
return;
F_29 ( V_43 -> V_174 -> V_263 , & V_43 -> V_67 , V_83 ) ;
}
void F_84 ( struct V_173 * V_174 ,
V_154 V_29 )
{
struct V_42 * V_43 , * V_264 ;
F_85 (w, next_w, &dapm->card->widgets, list) {
if ( V_43 -> V_67 . type != V_195 || V_43 -> V_174 != V_174 )
continue;
if ( V_43 -> V_67 . V_29 != V_29 &&
V_43 -> V_67 . V_29 != V_250 )
continue;
F_83 ( V_43 ) ;
F_86 ( V_43 ) ;
}
F_87 ( V_174 ) ;
}
int F_88 ( struct V_65 * V_37 , V_154 V_29 )
{
struct V_66 * V_67 , * V_265 ;
int V_40 = V_260 ;
while ( V_40 >= V_259 ) {
F_85 (dobj, next_dobj, &comp->dobj_list,
list) {
if ( V_67 -> V_29 != V_29 &&
V_67 -> V_29 != V_250 )
continue;
switch ( V_67 -> type ) {
case V_149 :
F_22 ( V_37 , V_67 , V_40 ) ;
break;
case V_158 :
F_27 ( V_37 , V_67 , V_40 ) ;
break;
case V_138 :
F_28 ( V_37 , V_67 , V_40 ) ;
break;
case V_195 :
F_29 ( V_37 , V_67 , V_40 ) ;
break;
case V_224 :
F_30 ( V_37 , V_67 , V_40 ) ;
break;
case V_233 :
F_31 ( V_37 , V_67 , V_40 ) ;
break;
default:
F_2 ( V_37 -> V_12 , L_63 ,
V_67 -> type ) ;
break;
}
}
V_40 -- ;
}
return ! F_89 ( & V_37 -> V_139 ) ;
}
