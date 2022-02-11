static inline int F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return ( V_1 * V_2 * 3 ) / 2 ;
default:
return 0 ;
}
}
static inline int F_2 ( T_1 V_1 , T_1 V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return V_1 ;
default:
return 0 ;
}
}
static inline int F_3 ( T_1 V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return 2 ;
default:
return 1 ;
}
}
static inline int F_4 ( T_1 V_1 , T_1 V_2 )
{
return ( V_1 * V_2 * 3 ) / 4 ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_10 * V_11 = & V_7 -> V_11 ;
V_9 -> V_12 = V_4 ;
V_9 -> V_13 = V_14 ;
V_9 -> V_15 = V_16 ;
V_9 -> V_17 = F_6 ( V_9 -> V_13 ,
V_18 ) ;
V_9 -> V_19 = F_6 ( V_9 -> V_15 ,
V_20 ) ;
V_9 -> V_21 = F_1 ( V_9 -> V_17 ,
V_9 -> V_19 ,
V_9 -> V_12 ) ;
V_11 -> V_22 = V_23 ;
V_11 -> V_13 = V_14 ;
V_11 -> V_15 = V_16 ;
V_7 -> V_24 = V_25 ;
V_7 -> V_26 = V_27 ;
V_7 -> V_28 = V_29 ;
V_7 -> V_30 = V_31 ;
V_7 -> V_32 = F_4 ( V_11 -> V_13 ,
V_11 -> V_15 ) ;
}
static const struct V_33 * F_7 ( struct V_6 * V_7 ,
T_1 V_12 ,
T_1 V_22 )
{
struct V_34 * V_35 = F_8 ( V_7 ) ;
const struct V_33 * V_36 ;
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_35 -> V_38 ; V_37 ++ ) {
V_36 = V_35 -> V_39 [ V_37 ] ;
if ( ( V_36 -> V_12 == V_12 ) &&
( V_36 -> V_22 == V_22 ) )
return V_36 ;
}
return NULL ;
}
static void F_9 ( T_1 V_40 , T_1 V_41 [] , T_1 * V_42 )
{
T_1 V_37 ;
bool V_43 = false ;
for ( V_37 = 0 ; V_37 < * V_42 ; V_37 ++ ) {
if ( V_40 == V_41 [ V_37 ] ) {
V_43 = true ;
break;
}
}
if ( ! V_43 )
V_41 [ ( * V_42 ) ++ ] = V_40 ;
}
static void F_10 ( struct V_34 * V_35 )
{
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_35 -> V_38 ; V_37 ++ ) {
F_9 ( V_35 -> V_39 [ V_37 ] -> V_12 ,
V_35 -> V_44 ,
& V_35 -> V_45 ) ;
F_9 ( V_35 -> V_39 [ V_37 ] -> V_22 ,
V_35 -> V_46 ,
& V_35 -> V_47 ) ;
}
}
static void F_11 ( struct V_34 * V_35 )
{
struct V_48 * V_49 = F_12 ( V_35 ) ;
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < F_13 ( V_50 ) ; V_37 ++ ) {
if ( V_35 -> V_38 >= V_51 ) {
F_14 ( V_49 ,
L_1 ,
V_52 , V_50 [ V_37 ] -> V_53 ,
V_51 ) ;
return;
}
V_35 -> V_39 [ V_35 -> V_38 ++ ] = V_50 [ V_37 ] ;
F_15 ( V_49 , L_2 , V_52 ,
V_50 [ V_37 ] -> V_53 ) ;
}
}
static int F_16 ( struct V_6 * V_7 , T_1 V_22 ,
T_1 V_12 , struct V_33 * * V_54 )
{
struct V_34 * V_35 = F_8 ( V_7 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_33 * V_36 ;
int V_55 ;
V_36 = (struct V_33 * ) F_7 ( V_7 , V_12 ,
V_22 ) ;
if ( ! V_36 ) {
F_18 ( V_49 , L_3 ,
V_7 -> V_53 , ( char * ) & V_12 , ( char * ) & V_22 ) ;
return - V_56 ;
}
F_14 ( V_49 , L_4 ,
V_7 -> V_53 , ( char * ) & V_12 , ( char * ) & V_22 ) ;
snprintf ( V_7 -> V_53 , sizeof( V_7 -> V_53 ) , L_5 ,
V_35 -> V_57 , ( char * ) & V_22 ) ;
V_55 = V_36 -> V_58 ( V_7 ) ;
if ( V_55 ) {
F_18 ( V_49 , L_6 ,
V_7 -> V_53 , V_55 ) ;
return V_55 ;
}
F_14 ( V_49 , L_7 , V_7 -> V_53 , V_36 -> V_53 ) ;
* V_54 = V_36 ;
return V_55 ;
}
static int F_19 ( struct V_59 * V_59 , void * V_60 ,
struct V_61 * V_62 )
{
struct V_6 * V_7 = F_20 ( V_59 -> V_63 ) ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
F_21 ( V_62 -> V_64 , V_65 , sizeof( V_62 -> V_64 ) ) ;
F_21 ( V_62 -> V_66 , V_35 -> V_67 -> V_53 , sizeof( V_62 -> V_66 ) ) ;
snprintf ( V_62 -> V_68 , sizeof( V_62 -> V_68 ) , L_8 ,
V_35 -> V_69 -> V_53 ) ;
return 0 ;
}
static int F_22 ( struct V_59 * V_59 , void * V_60 ,
struct V_70 * V_71 )
{
struct V_6 * V_7 = F_20 ( V_59 -> V_63 ) ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
if ( F_23 ( V_71 -> V_72 >= V_35 -> V_47 ) )
return - V_56 ;
V_71 -> V_12 = V_35 -> V_46 [ V_71 -> V_72 ] ;
return 0 ;
}
static int F_24 ( struct V_59 * V_59 , void * V_60 ,
struct V_70 * V_71 )
{
struct V_6 * V_7 = F_20 ( V_59 -> V_63 ) ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
if ( F_23 ( V_71 -> V_72 >= V_35 -> V_45 ) )
return - V_56 ;
V_71 -> V_12 = V_35 -> V_44 [ V_71 -> V_72 ] ;
return 0 ;
}
static int F_25 ( struct V_59 * V_59 , void * V_73 , struct V_74 * V_71 )
{
struct V_6 * V_7 = F_20 ( V_59 -> V_63 ) ;
struct V_10 * V_11 = & V_7 -> V_11 ;
V_71 -> V_3 . V_75 . V_13 = V_11 -> V_13 ;
V_71 -> V_3 . V_75 . V_15 = V_11 -> V_15 ;
V_71 -> V_3 . V_75 . V_76 = V_77 ;
V_71 -> V_3 . V_75 . V_24 = V_7 -> V_24 ;
V_71 -> V_3 . V_75 . V_26 = V_7 -> V_26 ;
V_71 -> V_3 . V_75 . V_28 = V_7 -> V_28 ;
V_71 -> V_3 . V_75 . V_30 = V_7 -> V_30 ;
V_71 -> V_3 . V_75 . V_12 = V_11 -> V_22 ;
V_71 -> V_3 . V_75 . V_78 = 0 ;
V_71 -> V_3 . V_75 . V_79 = V_7 -> V_32 ;
return 0 ;
}
static int F_26 ( struct V_59 * V_59 , void * V_73 , struct V_74 * V_71 )
{
struct V_6 * V_7 = F_20 ( V_59 -> V_63 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
V_71 -> V_3 . V_75 . V_13 = V_9 -> V_13 ;
V_71 -> V_3 . V_75 . V_15 = V_9 -> V_15 ;
V_71 -> V_3 . V_75 . V_76 = V_77 ;
V_71 -> V_3 . V_75 . V_24 = V_7 -> V_24 ;
V_71 -> V_3 . V_75 . V_26 = V_7 -> V_26 ;
V_71 -> V_3 . V_75 . V_28 = V_7 -> V_28 ;
V_71 -> V_3 . V_75 . V_30 = V_7 -> V_30 ;
V_71 -> V_3 . V_75 . V_12 = V_9 -> V_12 ;
V_71 -> V_3 . V_75 . V_78 = F_2 ( V_9 -> V_17 ,
V_9 -> V_12 ) ;
V_71 -> V_3 . V_75 . V_79 = V_9 -> V_21 ;
return 0 ;
}
static int F_27 ( struct V_59 * V_59 , void * V_60 ,
struct V_74 * V_71 )
{
struct V_6 * V_7 = F_20 ( V_59 -> V_63 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_80 * V_75 = & V_71 -> V_3 . V_75 ;
T_1 V_22 = V_75 -> V_12 ;
const struct V_33 * V_36 ;
T_1 V_13 , V_15 ;
T_1 V_81 ;
V_36 = F_7 ( V_7 , V_7 -> V_9 . V_12 , V_22 ) ;
if ( ! V_36 ) {
F_14 ( V_49 ,
L_9 ,
V_7 -> V_53 , ( char * ) & V_75 -> V_12 ) ;
return - V_56 ;
}
V_13 = V_75 -> V_13 ;
V_15 = V_75 -> V_15 ;
if ( V_7 -> V_82 & V_83 ) {
V_75 -> V_13 = V_7 -> V_9 . V_13 ;
V_75 -> V_15 = V_7 -> V_9 . V_15 ;
if ( ( V_75 -> V_13 != V_13 ) || ( V_75 -> V_15 != V_15 ) )
F_14 ( V_49 ,
L_10 ,
V_7 -> V_53 , V_13 , V_15 ,
V_75 -> V_13 , V_75 -> V_15 ) ;
} else {
F_28 ( & V_75 -> V_13 ,
V_84 , V_36 -> V_85 ,
0 ,
& V_75 -> V_15 ,
V_86 , V_36 -> V_87 ,
0 ,
0 ) ;
if ( ( V_75 -> V_13 != V_13 ) || ( V_75 -> V_15 != V_15 ) )
F_14 ( V_49 ,
L_11 ,
V_7 -> V_53 , V_13 , V_15 ,
V_75 -> V_13 , V_75 -> V_15 ) ;
}
V_81 = F_4 ( V_75 -> V_13 , V_75 -> V_15 ) ;
if ( V_75 -> V_79 < V_81 )
V_75 -> V_79 = V_81 ;
V_75 -> V_78 = 0 ;
V_75 -> V_24 = V_7 -> V_24 ;
V_75 -> V_26 = V_7 -> V_26 ;
V_75 -> V_28 = V_7 -> V_28 ;
V_75 -> V_30 = V_7 -> V_30 ;
V_75 -> V_76 = V_77 ;
return 0 ;
}
static int F_29 ( struct V_59 * V_59 , void * V_60 ,
struct V_74 * V_71 )
{
struct V_6 * V_7 = F_20 ( V_59 -> V_63 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_80 * V_75 = & V_71 -> V_3 . V_75 ;
T_1 V_12 = V_75 -> V_12 ;
const struct V_33 * V_36 ;
T_1 V_13 , V_15 ;
V_36 = F_7 ( V_7 , V_12 , V_7 -> V_11 . V_22 ) ;
if ( ! V_36 ) {
F_14 ( V_49 ,
L_12 ,
V_7 -> V_53 , ( char * ) & V_12 ) ;
return - V_56 ;
}
V_13 = V_75 -> V_13 ;
V_15 = V_75 -> V_15 ;
F_28 ( & V_75 -> V_13 ,
V_84 , V_88 ,
F_3 ( V_12 ) - 1 ,
& V_75 -> V_15 ,
V_86 , V_89 ,
F_3 ( V_12 ) - 1 ,
0 ) ;
if ( ( V_75 -> V_13 != V_13 ) || ( V_75 -> V_15 != V_15 ) )
F_14 ( V_49 ,
L_13 ,
V_7 -> V_53 , V_13 , V_15 , V_75 -> V_13 , V_75 -> V_15 ) ;
V_13 = F_6 ( V_75 -> V_13 , V_18 ) ;
V_15 = F_6 ( V_75 -> V_15 , V_20 ) ;
if ( ! V_75 -> V_24 ) {
V_75 -> V_24 = V_25 ;
V_75 -> V_26 = V_27 ;
V_75 -> V_28 = V_29 ;
V_75 -> V_30 = V_31 ;
}
V_75 -> V_78 = F_2 ( V_13 , V_12 ) ;
V_75 -> V_79 = F_1 ( V_13 , V_15 , V_12 ) ;
V_75 -> V_76 = V_77 ;
return 0 ;
}
static int F_30 ( struct V_59 * V_59 , void * V_73 , struct V_74 * V_71 )
{
struct V_6 * V_7 = F_20 ( V_59 -> V_63 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_90 * V_91 ;
int V_55 ;
V_55 = F_27 ( V_59 , V_73 , V_71 ) ;
if ( V_55 ) {
F_14 ( V_49 , L_14 ,
V_7 -> V_53 , ( char * ) & V_71 -> V_3 . V_75 . V_12 ) ;
return V_55 ;
}
V_91 = F_31 ( V_7 -> V_73 . V_92 , V_71 -> type ) ;
if ( F_32 ( V_91 ) ) {
F_14 ( V_49 , L_15 ,
V_7 -> V_53 ) ;
return - V_93 ;
}
V_7 -> V_32 = V_71 -> V_3 . V_75 . V_79 ;
V_7 -> V_11 . V_13 = V_71 -> V_3 . V_75 . V_13 ;
V_7 -> V_11 . V_15 = V_71 -> V_3 . V_75 . V_15 ;
V_7 -> V_11 . V_22 = V_71 -> V_3 . V_75 . V_12 ;
V_7 -> V_82 |= V_94 ;
return 0 ;
}
static int F_33 ( struct V_59 * V_59 , void * V_73 , struct V_74 * V_71 )
{
struct V_6 * V_7 = F_20 ( V_59 -> V_63 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_80 * V_75 = & V_71 -> V_3 . V_75 ;
struct V_90 * V_91 ;
int V_55 ;
V_55 = F_29 ( V_59 , V_73 , V_71 ) ;
if ( V_55 ) {
F_14 ( V_49 , L_16 ,
V_7 -> V_53 , ( char * ) & V_75 -> V_12 ) ;
return V_55 ;
}
V_91 = F_31 ( V_7 -> V_73 . V_92 , V_71 -> type ) ;
if ( F_32 ( V_91 ) ) {
F_14 ( V_49 , L_17 , V_7 -> V_53 ) ;
return - V_93 ;
}
V_7 -> V_24 = V_75 -> V_24 ;
V_7 -> V_26 = V_75 -> V_26 ;
V_7 -> V_28 = V_75 -> V_28 ;
V_7 -> V_30 = V_75 -> V_30 ;
V_7 -> V_9 . V_17 = F_6 ( V_75 -> V_13 , V_18 ) ;
V_7 -> V_9 . V_19 = F_6 ( V_75 -> V_15 ,
V_20 ) ;
V_7 -> V_9 . V_21 = V_75 -> V_79 ;
V_7 -> V_9 . V_12 = V_75 -> V_12 ;
V_7 -> V_9 . V_13 = V_75 -> V_13 ;
V_7 -> V_9 . V_15 = V_75 -> V_15 ;
V_7 -> V_82 |= V_83 ;
return 0 ;
}
static int F_34 ( struct V_59 * V_59 , void * V_73 , struct V_95 * V_96 )
{
struct V_6 * V_7 = F_20 ( V_59 -> V_63 ) ;
struct V_97 * V_98 = & V_7 -> V_99 . V_98 ;
if ( V_96 -> type != V_100 )
return - V_56 ;
V_96 -> V_101 . V_102 . V_103 = V_104 ;
V_96 -> V_101 . V_102 . V_105 . V_106 = V_98 -> V_106 ;
V_96 -> V_101 . V_102 . V_105 . V_107 =
V_98 -> V_107 ;
return 0 ;
}
static int F_35 ( struct V_59 * V_59 , void * V_73 , struct V_95 * V_96 )
{
struct V_6 * V_7 = F_20 ( V_59 -> V_63 ) ;
struct V_97 * V_98 = & V_7 -> V_99 . V_98 ;
if ( V_96 -> type != V_100 )
return - V_56 ;
if ( ! V_96 -> V_101 . V_102 . V_105 . V_106 ||
! V_96 -> V_101 . V_102 . V_105 . V_107 )
return F_34 ( V_59 , V_73 , V_96 ) ;
V_96 -> V_101 . V_102 . V_103 = V_104 ;
V_98 -> V_106 = V_96 -> V_101 . V_102 . V_105 . V_106 ;
V_98 -> V_107 =
V_96 -> V_101 . V_102 . V_105 . V_107 ;
return 0 ;
}
static int F_36 ( struct V_59 * V_59 , void * V_60 , struct V_108 * V_109 )
{
struct V_6 * V_7 = F_20 ( V_59 -> V_63 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
if ( V_109 -> type == V_110 ) {
struct V_90 * V_91 ;
struct V_111 * V_112 ;
V_91 = F_31 ( V_7 -> V_73 . V_92 , V_109 -> type ) ;
if ( V_109 -> V_72 >= V_91 -> V_113 ) {
F_14 ( V_49 , L_18 ,
V_7 -> V_53 , V_109 -> V_72 , V_91 -> V_113 ) ;
return - V_56 ;
}
V_112 = (struct V_111 * ) V_91 -> V_114 [ V_109 -> V_72 ] ;
V_112 -> V_115 = V_109 -> V_115 ;
}
return F_37 ( V_59 , V_7 -> V_73 . V_92 , V_109 ) ;
}
static int F_38 ( struct V_116 * V_117 )
{
struct V_6 * V_7 = F_39 ( V_117 -> V_118 , struct V_6 ,
V_119 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
F_14 ( V_49 , L_19 , V_7 -> V_53 ,
V_117 -> V_120 , V_117 -> V_121 ) ;
switch ( V_117 -> V_120 ) {
case V_122 :
V_7 -> V_99 . V_123 = V_117 -> V_121 ;
break;
case V_124 :
V_7 -> V_99 . V_125 = V_117 -> V_121 ;
break;
case V_126 :
V_7 -> V_99 . V_127 = V_117 -> V_121 ;
break;
case V_128 :
V_7 -> V_99 . V_129 = V_117 -> V_121 ;
break;
case V_130 :
V_7 -> V_99 . V_131 = V_117 -> V_121 ;
if ( V_7 -> V_82 & V_94 )
snprintf ( V_7 -> V_11 . V_131 ,
sizeof( V_7 -> V_11 . V_131 ) ,
L_20 ,
F_40 ( V_117 -> V_120 ) [ V_117 -> V_121 ] ) ;
break;
case V_132 :
V_7 -> V_99 . V_133 = V_117 -> V_121 ;
if ( V_7 -> V_82 & V_94 )
snprintf ( V_7 -> V_11 . V_133 ,
sizeof( V_7 -> V_11 . V_133 ) ,
L_21 ,
F_40 ( V_117 -> V_120 ) [ V_117 -> V_121 ] ) ;
break;
case V_134 :
V_7 -> V_99 . V_135 = V_117 -> V_121 ;
break;
case V_136 :
V_7 -> V_99 . V_137 = V_117 -> V_121 ;
break;
case V_138 :
V_7 -> V_99 . V_139 = V_117 -> V_121 ;
break;
case V_140 :
V_7 -> V_99 . V_141 = V_117 -> V_121 ;
break;
case V_142 :
V_7 -> V_99 . V_143 = V_117 -> V_121 ;
break;
case V_144 :
V_7 -> V_99 . V_145 = V_117 -> V_121 ;
break;
case V_146 :
V_7 -> V_99 . V_147 = V_117 -> V_121 ;
break;
case V_148 :
V_7 -> V_99 . V_149 = V_117 -> V_121 ;
break;
case V_150 :
V_7 -> V_99 . V_151 = V_117 -> V_121 ;
break;
default:
F_14 ( V_49 , L_22 ,
V_7 -> V_53 , V_117 -> V_120 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_48 * V_49 = F_17 ( V_7 ) ;
T_2 V_152 ;
enum V_153 V_151 =
V_154 ;
F_42 ( & V_7 -> V_119 , 15 ) ;
F_43 ( & V_7 -> V_119 , & V_155 ,
V_122 ,
V_156 ,
0 ,
V_156 ) ;
F_44 ( & V_7 -> V_119 , & V_155 ,
V_124 ,
1 , 60 , 1 , 16 ) ;
F_44 ( & V_7 -> V_119 , & V_155 ,
V_126 ,
1000 , 60000000 , 1000 , 20000000 ) ;
V_152 = ~ ( 1 << V_157 ) ;
F_43 ( & V_7 -> V_119 , & V_155 ,
V_128 ,
V_157 ,
V_152 ,
V_157 ) ;
V_152 = ~ ( ( 1 << V_158 ) |
( 1 << V_159 ) |
( 1 << V_160 ) |
( 1 << V_161 ) ) ;
F_43 ( & V_7 -> V_119 , & V_155 ,
V_130 ,
V_161 ,
V_152 ,
V_160 ) ;
F_43 ( & V_7 -> V_119 , & V_155 ,
V_132 ,
V_162 ,
0 ,
V_163 ) ;
F_43 ( & V_7 -> V_119 , & V_155 ,
V_134 ,
V_164 ,
0 ,
V_165 ) ;
F_44 ( & V_7 -> V_119 , & V_155 ,
V_136 ,
1 , 10000 , 1 , 3000 ) ;
F_44 ( & V_7 -> V_119 , & V_155 ,
V_138 ,
0 , 1 , 1 , 0 ) ;
F_44 ( & V_7 -> V_119 , & V_155 ,
V_140 ,
0 , 51 , 1 , 5 ) ;
F_44 ( & V_7 -> V_119 , & V_155 ,
V_142 ,
0 , 51 , 1 , 51 ) ;
F_44 ( & V_7 -> V_119 , & V_155 ,
V_144 ,
0 , 1 , 1 , 1 ) ;
V_152 = ~ ( 1 << V_166 ) ;
F_43 ( & V_7 -> V_119 , & V_155 ,
V_146 ,
V_166 ,
V_152 ,
V_166 ) ;
F_44 ( & V_7 -> V_119 , & V_155 ,
V_148 ,
0 , 1 , 1 , 0 ) ;
V_152 = ~ ( 1 << V_151 ) ;
F_43 ( & V_7 -> V_119 , & V_155 ,
V_150 ,
V_151 ,
V_152 ,
V_151 ) ;
if ( V_7 -> V_119 . error ) {
int V_167 = V_7 -> V_119 . error ;
F_14 ( V_49 , L_23 ,
V_7 -> V_53 , V_167 ) ;
F_45 ( & V_7 -> V_119 ) ;
return V_167 ;
}
F_46 ( & V_7 -> V_119 ) ;
V_7 -> V_99 . V_98 . V_106 = V_168 ;
V_7 -> V_99 . V_98 . V_107 = V_169 ;
return 0 ;
}
static void F_47 ( struct V_170 * V_171 )
{
struct V_6 * V_7 = F_39 ( V_171 , struct V_6 , V_172 ) ;
struct V_173 * V_174 , * V_175 ;
const struct V_33 * V_36 = V_7 -> V_36 ;
struct V_176 * V_177 ;
struct V_111 * V_112 ;
int V_55 ;
F_48 ( & V_7 -> V_178 ) ;
V_174 = F_49 ( V_7 -> V_73 . V_92 ) ;
V_175 = F_50 ( V_7 -> V_73 . V_92 ) ;
V_177 = F_51 ( V_174 ) ;
V_112 = F_52 ( V_175 ) ;
V_177 -> V_179 . V_180 = V_7 -> V_181 ++ ;
V_55 = V_36 -> V_182 ( V_7 , V_177 , V_112 ) ;
F_53 ( & V_175 -> V_183 , 0 , V_112 -> V_115 ) ;
if ( V_55 ) {
F_54 ( V_174 , V_184 ) ;
F_54 ( V_175 , V_184 ) ;
} else {
V_175 -> V_183 . V_185 = V_174 -> V_183 . V_185 ;
V_175 -> V_76 = V_77 ;
V_175 -> V_180 = V_7 -> V_186 - 1 ;
F_54 ( V_174 , V_187 ) ;
F_54 ( V_175 , V_187 ) ;
}
F_55 ( & V_7 -> V_178 ) ;
F_56 ( V_7 -> V_34 -> V_188 , V_7 -> V_73 . V_92 ) ;
}
static void F_57 ( void * V_60 )
{
struct V_6 * V_7 = V_60 ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
F_58 ( V_35 -> V_189 , & V_7 -> V_172 ) ;
}
static void F_59 ( void * V_60 )
{
struct V_6 * V_7 = V_60 ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
F_14 ( V_49 , L_24 , V_7 -> V_53 ) ;
V_7 -> V_190 = true ;
}
static int F_60 ( void * V_60 )
{
struct V_6 * V_7 = V_60 ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
if ( ! F_61 ( V_7 -> V_73 . V_92 ) ) {
F_14 ( V_49 , L_25 ,
V_7 -> V_53 ) ;
return 0 ;
}
if ( ! F_62 ( V_7 -> V_73 . V_92 ) ) {
F_14 ( V_49 , L_26 ,
V_7 -> V_53 ) ;
return 0 ;
}
if ( V_7 -> V_190 ) {
F_14 ( V_49 , L_27 , V_7 -> V_53 ) ;
return 0 ;
}
return 1 ;
}
static int F_63 ( struct V_90 * V_91 ,
unsigned int * V_113 , unsigned int * V_191 ,
unsigned int V_192 [] , struct V_48 * V_193 [] )
{
struct V_6 * V_7 = F_64 ( V_91 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
unsigned int V_21 ;
F_14 ( V_49 , L_28 , V_7 -> V_53 ,
F_65 ( V_91 -> type ) , * V_113 ) ;
V_21 = V_91 -> type == V_100 ?
V_7 -> V_9 . V_21 : V_7 -> V_32 ;
if ( * V_191 )
return V_192 [ 0 ] < V_21 ? - V_56 : 0 ;
* V_191 = 1 ;
V_192 [ 0 ] = V_21 ;
return 0 ;
}
static int F_66 ( struct V_194 * V_195 )
{
struct V_6 * V_7 = F_64 ( V_195 -> V_90 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_173 * V_179 = F_67 ( V_195 ) ;
if ( V_195 -> V_90 -> type == V_100 ) {
struct V_176 * V_177 = F_51 ( V_179 ) ;
if ( V_179 -> V_76 == V_196 )
V_179 -> V_76 = V_77 ;
if ( V_179 -> V_76 != V_77 ) {
F_14 ( V_49 ,
L_29 ,
V_7 -> V_53 , V_195 -> V_72 , V_179 -> V_76 ) ;
return - V_56 ;
}
if ( ! V_177 -> V_197 ) {
V_177 -> V_198 = F_68 ( & V_179 -> V_183 , 0 ) ;
V_177 -> V_199 = F_69 (
& V_179 -> V_183 , 0 ) ;
V_177 -> V_200 = V_7 -> V_9 ;
V_177 -> V_197 = true ;
F_14 ( V_49 ,
L_30 ,
V_7 -> V_53 , V_195 -> V_72 ,
V_177 -> V_198 , & V_177 -> V_199 ) ;
}
} else {
struct V_111 * V_112 = F_52 ( V_179 ) ;
if ( ! V_112 -> V_197 ) {
V_112 -> V_198 = F_68 ( & V_179 -> V_183 , 0 ) ;
V_112 -> V_199 = F_69 (
& V_179 -> V_183 , 0 ) ;
V_112 -> V_21 = F_70 ( & V_179 -> V_183 , 0 ) ;
V_112 -> V_197 = true ;
F_14 ( V_49 ,
L_31 ,
V_7 -> V_53 , V_195 -> V_72 ,
V_112 -> V_198 , & V_112 -> V_199 ) ;
}
}
return 0 ;
}
static void F_71 ( struct V_194 * V_195 )
{
struct V_6 * V_7 = F_64 ( V_195 -> V_90 ) ;
struct V_173 * V_179 = F_67 ( V_195 ) ;
if ( V_7 -> V_73 . V_92 )
F_72 ( V_7 -> V_73 . V_92 , V_179 ) ;
}
static int F_73 ( struct V_90 * V_91 , unsigned int V_201 )
{
struct V_6 * V_7 = F_64 ( V_91 ) ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_173 * V_179 ;
int V_55 ;
unsigned int V_37 ;
bool V_43 = false ;
F_14 ( V_49 , L_32 , V_7 -> V_53 ,
F_65 ( V_91 -> type ) ) ;
if ( F_74 ( V_91 -> type ) ) {
if ( ! F_75 ( & V_7 -> V_73 . V_92 -> V_202 . V_203 ) )
return 0 ;
} else {
if ( ! F_75 ( & V_7 -> V_73 . V_92 -> V_204 . V_203 ) )
return 0 ;
}
for ( V_37 = 0 ; V_37 < V_205 ; V_37 ++ ) {
if ( ! V_35 -> V_206 [ V_37 ] ) {
V_35 -> V_206 [ V_37 ] = V_7 ;
V_7 -> V_120 = V_37 ;
V_43 = true ;
break;
}
}
if ( ! V_43 ) {
F_18 ( V_49 , L_33 , V_7 -> V_53 ) ;
V_55 = - V_207 ;
goto V_167;
}
V_35 -> V_208 ++ ;
if ( ! V_7 -> V_36 ) {
V_55 = F_16 ( V_7 ,
V_7 -> V_11 . V_22 ,
V_7 -> V_9 . V_12 ,
& V_7 -> V_36 ) ;
if ( V_55 < 0 )
goto V_209;
}
return 0 ;
V_209:
V_35 -> V_206 [ V_7 -> V_120 ] = NULL ;
V_35 -> V_208 -- ;
V_167:
if ( V_91 -> type == V_100 ) {
while ( ( V_179 = F_49 ( V_7 -> V_73 . V_92 ) ) )
F_54 ( V_179 , V_210 ) ;
} else {
while ( ( V_179 = F_50 ( V_7 -> V_73 . V_92 ) ) )
F_54 ( V_179 , V_210 ) ;
}
return V_55 ;
}
static void F_76 ( struct V_90 * V_91 )
{
struct V_6 * V_7 = F_64 ( V_91 ) ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
const struct V_33 * V_36 = V_7 -> V_36 ;
struct V_173 * V_179 ;
F_14 ( V_49 , L_34 , V_7 -> V_53 ,
F_65 ( V_91 -> type ) ) ;
if ( V_91 -> type == V_100 ) {
V_7 -> V_181 = 0 ;
while ( ( V_179 = F_49 ( V_7 -> V_73 . V_92 ) ) )
F_54 ( V_179 , V_184 ) ;
} else {
V_7 -> V_186 = 0 ;
while ( ( V_179 = F_50 ( V_7 -> V_73 . V_92 ) ) )
F_54 ( V_179 , V_184 ) ;
}
if ( ( F_74 ( V_91 -> type ) &&
F_32 ( & V_7 -> V_73 . V_92 -> V_202 . V_203 ) ) ||
( ! F_74 ( V_91 -> type ) &&
F_32 ( & V_7 -> V_73 . V_92 -> V_204 . V_203 ) ) ) {
F_14 ( V_49 , L_35 ,
V_7 -> V_53 , F_65 ( V_91 -> type ) ,
F_32 ( & V_7 -> V_73 . V_92 -> V_204 . V_203 ) ,
F_32 ( & V_7 -> V_73 . V_92 -> V_202 . V_203 ) ) ;
return;
}
if ( V_36 ) {
F_14 ( V_49 , L_36 , V_7 -> V_53 , V_36 -> V_53 ) ;
V_36 -> V_211 ( V_7 ) ;
V_7 -> V_36 = NULL ;
V_35 -> V_206 [ V_7 -> V_120 ] = NULL ;
V_35 -> V_208 -- ;
}
V_7 -> V_190 = false ;
}
static int F_77 ( struct V_6 * V_7 , struct V_90 * V_91 )
{
V_91 -> V_212 = V_213 | V_214 ;
V_91 -> V_215 = V_7 ;
V_91 -> V_216 = & V_217 ;
V_91 -> V_218 = & V_219 ;
V_91 -> V_220 = V_221 ;
V_91 -> V_178 = & V_7 -> V_34 -> V_178 ;
return F_78 ( V_91 ) ;
}
static int F_79 ( void * V_60 , struct V_90 * V_222 ,
struct V_90 * V_223 )
{
struct V_6 * V_7 = V_60 ;
int V_55 ;
V_222 -> type = V_100 ;
V_222 -> V_224 = sizeof( struct V_176 ) ;
V_222 -> V_225 = V_226 ;
V_222 -> V_49 = V_7 -> V_34 -> V_49 ;
V_55 = F_77 ( V_7 , V_222 ) ;
if ( V_55 )
return V_55 ;
V_223 -> type = V_110 ;
V_223 -> V_224 = sizeof( struct V_111 ) ;
V_223 -> V_225 = V_227 ;
V_223 -> V_49 = V_7 -> V_34 -> V_49 ;
return F_77 ( V_7 , V_223 ) ;
}
static int F_80 ( struct V_59 * V_59 )
{
struct V_34 * V_35 = F_81 ( V_59 ) ;
struct V_48 * V_49 = F_12 ( V_35 ) ;
struct V_6 * V_7 ;
int V_55 ;
V_7 = F_82 ( sizeof( * V_7 ) , V_228 ) ;
if ( ! V_7 ) {
V_55 = - V_207 ;
goto V_229;
}
V_7 -> V_34 = V_35 ;
F_83 ( & V_7 -> V_172 , F_47 ) ;
F_84 ( & V_7 -> V_73 , F_85 ( V_59 ) ) ;
V_59 -> V_63 = & V_7 -> V_73 ;
F_86 ( & V_7 -> V_73 ) ;
V_55 = F_41 ( V_7 ) ;
if ( V_55 ) {
F_18 ( V_49 , L_37 ,
V_52 ) ;
goto V_230;
}
V_7 -> V_73 . V_119 = & V_7 -> V_119 ;
F_87 ( & V_7 -> V_178 ) ;
V_7 -> V_73 . V_92 = F_88 ( V_35 -> V_188 , V_7 ,
& F_79 ) ;
if ( F_89 ( V_7 -> V_73 . V_92 ) ) {
V_55 = F_90 ( V_7 -> V_73 . V_92 ) ;
F_18 ( V_49 , L_38 ,
V_52 , V_55 ) ;
goto V_231;
}
F_48 ( & V_35 -> V_178 ) ;
V_35 -> V_57 ++ ;
snprintf ( V_7 -> V_53 , sizeof( V_7 -> V_53 ) , L_39 ,
V_35 -> V_57 ) ;
F_55 ( & V_35 -> V_178 ) ;
F_5 ( V_7 ) ;
F_15 ( V_49 , L_40 , V_7 -> V_53 ) ;
return 0 ;
V_231:
F_45 ( & V_7 -> V_119 ) ;
V_230:
F_91 ( & V_7 -> V_73 ) ;
F_92 ( & V_7 -> V_73 ) ;
F_93 ( V_7 ) ;
V_229:
return V_55 ;
}
static int F_94 ( struct V_59 * V_59 )
{
struct V_6 * V_7 = F_20 ( V_59 -> V_63 ) ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
const struct V_33 * V_36 = V_7 -> V_36 ;
if ( V_36 ) {
F_14 ( V_49 , L_36 , V_7 -> V_53 , V_36 -> V_53 ) ;
V_36 -> V_211 ( V_7 ) ;
V_7 -> V_36 = NULL ;
V_35 -> V_206 [ V_7 -> V_120 ] = NULL ;
V_35 -> V_208 -- ;
}
F_95 ( V_7 -> V_73 . V_92 ) ;
F_45 ( & V_7 -> V_119 ) ;
F_91 ( & V_7 -> V_73 ) ;
F_92 ( & V_7 -> V_73 ) ;
F_15 ( V_49 , L_41 , V_7 -> V_53 ) ;
F_93 ( V_7 ) ;
return 0 ;
}
static int F_96 ( struct V_34 * V_35 )
{
int V_55 ;
struct V_232 * V_67 ;
struct V_48 * V_49 ;
if ( ! V_35 )
return - V_233 ;
V_49 = F_12 ( V_35 ) ;
V_35 -> V_188 = F_97 ( & V_234 ) ;
if ( F_89 ( V_35 -> V_188 ) ) {
F_18 ( V_49 , L_42 ,
V_52 ) ;
V_55 = F_90 ( V_35 -> V_188 ) ;
goto V_167;
}
V_67 = F_98 () ;
if ( ! V_67 ) {
F_18 ( V_49 , L_43 ,
V_52 ) ;
V_55 = - V_207 ;
goto V_235;
}
V_67 -> V_236 = & V_237 ;
V_67 -> V_238 = & V_239 ;
V_67 -> V_240 = V_241 ;
V_67 -> V_178 = & V_35 -> V_178 ;
V_67 -> V_242 = V_243 ;
V_67 -> V_244 = V_245 | V_246 ;
V_67 -> V_247 = & V_35 -> V_247 ;
snprintf ( V_67 -> V_53 , sizeof( V_67 -> V_53 ) , L_44 , V_65 ,
V_35 -> V_248 ) ;
V_55 = F_99 ( V_67 , V_249 , - 1 ) ;
if ( V_55 ) {
F_18 ( V_49 , L_45 ,
V_52 ) ;
goto V_250;
}
V_35 -> V_67 = V_67 ;
F_100 ( V_67 , V_35 ) ;
return 0 ;
V_250:
V_241 ( V_67 ) ;
V_235:
F_101 ( V_35 -> V_188 ) ;
V_167:
return V_55 ;
}
static void F_102 ( struct V_34 * V_35 )
{
if ( ! V_35 )
return;
if ( V_35 -> V_188 )
F_101 ( V_35 -> V_188 ) ;
F_103 ( V_35 -> V_67 ) ;
}
static int F_104 ( struct V_251 * V_69 )
{
struct V_34 * V_35 ;
struct V_48 * V_49 = & V_69 -> V_49 ;
int V_55 ;
V_35 = F_105 ( V_49 , sizeof( * V_35 ) , V_228 ) ;
if ( ! V_35 ) {
V_55 = - V_207 ;
goto V_167;
}
V_35 -> V_49 = V_49 ;
V_35 -> V_69 = V_69 ;
F_106 ( V_69 , V_35 ) ;
F_87 ( & V_35 -> V_178 ) ;
V_55 = F_107 ( V_69 , V_35 ) ;
if ( V_55 )
goto V_167;
F_11 ( V_35 ) ;
F_10 ( V_35 ) ;
V_55 = F_108 ( V_49 , & V_35 -> V_247 ) ;
if ( V_55 ) {
F_18 ( V_49 , L_46 ,
V_52 , V_65 ) ;
goto V_252;
}
V_35 -> V_189 = F_109 ( V_65 ) ;
if ( ! V_35 -> V_189 ) {
F_18 ( V_49 , L_47 ,
V_52 , V_65 ) ;
V_55 = - V_207 ;
goto V_253;
}
V_55 = F_96 ( V_35 ) ;
if ( V_55 )
goto V_254;
F_15 ( V_49 , L_48 , V_52 ,
V_65 , V_35 -> V_67 -> V_255 ) ;
return 0 ;
V_254:
F_110 ( V_35 -> V_189 ) ;
V_253:
F_111 ( & V_35 -> V_247 ) ;
V_252:
F_112 ( V_35 ) ;
V_167:
return V_55 ;
}
static int F_113 ( struct V_251 * V_69 )
{
struct V_34 * V_35 = F_114 ( V_69 ) ;
struct V_48 * V_49 = F_12 ( V_35 ) ;
F_102 ( V_35 ) ;
F_110 ( V_35 -> V_189 ) ;
F_112 ( V_35 ) ;
F_111 ( & V_35 -> V_247 ) ;
F_15 ( V_49 , L_49 , V_52 , V_69 -> V_53 ) ;
return 0 ;
}
