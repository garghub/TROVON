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
static void F_19 ( struct V_6 * V_7 )
{
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_10 * V_59 = & V_7 -> V_11 ;
struct V_8 * V_60 = & V_7 -> V_9 ;
if ( ! ( V_7 -> V_61 & V_62 ) )
return;
F_14 ( V_49 , L_8 ,
V_7 -> V_53 ,
( char * ) & V_60 -> V_12 ,
V_60 -> V_17 , V_60 -> V_19 ,
( char * ) & V_59 -> V_22 ,
V_59 -> V_13 , V_59 -> V_15 ,
V_59 -> V_63 , V_59 -> V_64 ,
V_7 -> V_65 ,
V_7 -> V_66 ,
V_7 -> V_67 ,
V_7 -> V_68 ) ;
}
static int F_20 ( struct V_69 * V_69 , void * V_70 ,
struct V_71 * V_72 )
{
struct V_6 * V_7 = F_21 ( V_69 -> V_73 ) ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
F_22 ( V_72 -> V_74 , V_75 , sizeof( V_72 -> V_74 ) ) ;
F_22 ( V_72 -> V_76 , V_35 -> V_77 -> V_53 , sizeof( V_72 -> V_76 ) ) ;
snprintf ( V_72 -> V_78 , sizeof( V_72 -> V_78 ) , L_9 ,
V_35 -> V_79 -> V_53 ) ;
return 0 ;
}
static int F_23 ( struct V_69 * V_69 , void * V_70 ,
struct V_80 * V_81 )
{
struct V_6 * V_7 = F_21 ( V_69 -> V_73 ) ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
if ( F_24 ( V_81 -> V_82 >= V_35 -> V_47 ) )
return - V_56 ;
V_81 -> V_12 = V_35 -> V_46 [ V_81 -> V_82 ] ;
return 0 ;
}
static int F_25 ( struct V_69 * V_69 , void * V_70 ,
struct V_80 * V_81 )
{
struct V_6 * V_7 = F_21 ( V_69 -> V_73 ) ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
if ( F_24 ( V_81 -> V_82 >= V_35 -> V_45 ) )
return - V_56 ;
V_81 -> V_12 = V_35 -> V_44 [ V_81 -> V_82 ] ;
return 0 ;
}
static int F_26 ( struct V_69 * V_69 , void * V_83 , struct V_84 * V_81 )
{
struct V_6 * V_7 = F_21 ( V_69 -> V_73 ) ;
struct V_10 * V_11 = & V_7 -> V_11 ;
V_81 -> V_3 . V_85 . V_13 = V_11 -> V_13 ;
V_81 -> V_3 . V_85 . V_15 = V_11 -> V_15 ;
V_81 -> V_3 . V_85 . V_86 = V_87 ;
V_81 -> V_3 . V_85 . V_24 = V_7 -> V_24 ;
V_81 -> V_3 . V_85 . V_26 = V_7 -> V_26 ;
V_81 -> V_3 . V_85 . V_28 = V_7 -> V_28 ;
V_81 -> V_3 . V_85 . V_30 = V_7 -> V_30 ;
V_81 -> V_3 . V_85 . V_12 = V_11 -> V_22 ;
V_81 -> V_3 . V_85 . V_88 = 0 ;
V_81 -> V_3 . V_85 . V_89 = V_7 -> V_32 ;
return 0 ;
}
static int F_27 ( struct V_69 * V_69 , void * V_83 , struct V_84 * V_81 )
{
struct V_6 * V_7 = F_21 ( V_69 -> V_73 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
V_81 -> V_3 . V_85 . V_13 = V_9 -> V_13 ;
V_81 -> V_3 . V_85 . V_15 = V_9 -> V_15 ;
V_81 -> V_3 . V_85 . V_86 = V_87 ;
V_81 -> V_3 . V_85 . V_24 = V_7 -> V_24 ;
V_81 -> V_3 . V_85 . V_26 = V_7 -> V_26 ;
V_81 -> V_3 . V_85 . V_28 = V_7 -> V_28 ;
V_81 -> V_3 . V_85 . V_30 = V_7 -> V_30 ;
V_81 -> V_3 . V_85 . V_12 = V_9 -> V_12 ;
V_81 -> V_3 . V_85 . V_88 = F_2 ( V_9 -> V_17 ,
V_9 -> V_12 ) ;
V_81 -> V_3 . V_85 . V_89 = V_9 -> V_21 ;
return 0 ;
}
static int F_28 ( struct V_69 * V_69 , void * V_70 ,
struct V_84 * V_81 )
{
struct V_6 * V_7 = F_21 ( V_69 -> V_73 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_90 * V_85 = & V_81 -> V_3 . V_85 ;
T_1 V_22 = V_85 -> V_12 ;
const struct V_33 * V_36 ;
T_1 V_13 , V_15 ;
T_1 V_91 ;
V_36 = F_7 ( V_7 , V_7 -> V_9 . V_12 , V_22 ) ;
if ( ! V_36 ) {
F_14 ( V_49 ,
L_10 ,
V_7 -> V_53 , ( char * ) & V_85 -> V_12 ) ;
return - V_56 ;
}
V_13 = V_85 -> V_13 ;
V_15 = V_85 -> V_15 ;
if ( V_7 -> V_61 & V_92 ) {
V_85 -> V_13 = V_7 -> V_9 . V_13 ;
V_85 -> V_15 = V_7 -> V_9 . V_15 ;
if ( ( V_85 -> V_13 != V_13 ) || ( V_85 -> V_15 != V_15 ) )
F_14 ( V_49 ,
L_11 ,
V_7 -> V_53 , V_13 , V_15 ,
V_85 -> V_13 , V_85 -> V_15 ) ;
} else {
F_29 ( & V_85 -> V_13 ,
V_93 , V_36 -> V_94 ,
0 ,
& V_85 -> V_15 ,
V_95 , V_36 -> V_96 ,
0 ,
0 ) ;
if ( ( V_85 -> V_13 != V_13 ) || ( V_85 -> V_15 != V_15 ) )
F_14 ( V_49 ,
L_12 ,
V_7 -> V_53 , V_13 , V_15 ,
V_85 -> V_13 , V_85 -> V_15 ) ;
}
V_91 = F_4 ( V_85 -> V_13 , V_85 -> V_15 ) ;
if ( V_85 -> V_89 < V_91 )
V_85 -> V_89 = V_91 ;
V_85 -> V_88 = 0 ;
V_85 -> V_24 = V_7 -> V_24 ;
V_85 -> V_26 = V_7 -> V_26 ;
V_85 -> V_28 = V_7 -> V_28 ;
V_85 -> V_30 = V_7 -> V_30 ;
V_85 -> V_86 = V_87 ;
return 0 ;
}
static int F_30 ( struct V_69 * V_69 , void * V_70 ,
struct V_84 * V_81 )
{
struct V_6 * V_7 = F_21 ( V_69 -> V_73 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_90 * V_85 = & V_81 -> V_3 . V_85 ;
T_1 V_12 = V_85 -> V_12 ;
const struct V_33 * V_36 ;
T_1 V_13 , V_15 ;
V_36 = F_7 ( V_7 , V_12 , V_7 -> V_11 . V_22 ) ;
if ( ! V_36 ) {
F_14 ( V_49 ,
L_13 ,
V_7 -> V_53 , ( char * ) & V_12 ) ;
return - V_56 ;
}
V_13 = V_85 -> V_13 ;
V_15 = V_85 -> V_15 ;
F_29 ( & V_85 -> V_13 ,
V_93 , V_97 ,
F_3 ( V_12 ) - 1 ,
& V_85 -> V_15 ,
V_95 , V_98 ,
F_3 ( V_12 ) - 1 ,
0 ) ;
if ( ( V_85 -> V_13 != V_13 ) || ( V_85 -> V_15 != V_15 ) )
F_14 ( V_49 ,
L_14 ,
V_7 -> V_53 , V_13 , V_15 , V_85 -> V_13 , V_85 -> V_15 ) ;
V_13 = F_6 ( V_85 -> V_13 , V_18 ) ;
V_15 = F_6 ( V_85 -> V_15 , V_20 ) ;
if ( ! V_85 -> V_24 ) {
V_85 -> V_24 = V_25 ;
V_85 -> V_26 = V_27 ;
V_85 -> V_28 = V_29 ;
V_85 -> V_30 = V_31 ;
}
V_85 -> V_88 = F_2 ( V_13 , V_12 ) ;
V_85 -> V_89 = F_1 ( V_13 , V_15 , V_12 ) ;
V_85 -> V_86 = V_87 ;
return 0 ;
}
static int F_31 ( struct V_69 * V_69 , void * V_83 , struct V_84 * V_81 )
{
struct V_6 * V_7 = F_21 ( V_69 -> V_73 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_99 * V_100 ;
int V_55 ;
V_55 = F_28 ( V_69 , V_83 , V_81 ) ;
if ( V_55 ) {
F_14 ( V_49 , L_15 ,
V_7 -> V_53 , ( char * ) & V_81 -> V_3 . V_85 . V_12 ) ;
return V_55 ;
}
V_100 = F_32 ( V_7 -> V_83 . V_101 , V_81 -> type ) ;
if ( F_33 ( V_100 ) ) {
F_14 ( V_49 , L_16 ,
V_7 -> V_53 ) ;
return - V_102 ;
}
V_7 -> V_32 = V_81 -> V_3 . V_85 . V_89 ;
V_7 -> V_11 . V_13 = V_81 -> V_3 . V_85 . V_13 ;
V_7 -> V_11 . V_15 = V_81 -> V_3 . V_85 . V_15 ;
V_7 -> V_11 . V_22 = V_81 -> V_3 . V_85 . V_12 ;
V_7 -> V_61 |= V_62 ;
return 0 ;
}
static int F_34 ( struct V_69 * V_69 , void * V_83 , struct V_84 * V_81 )
{
struct V_6 * V_7 = F_21 ( V_69 -> V_73 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_90 * V_85 = & V_81 -> V_3 . V_85 ;
struct V_99 * V_100 ;
int V_55 ;
V_55 = F_30 ( V_69 , V_83 , V_81 ) ;
if ( V_55 ) {
F_14 ( V_49 , L_17 ,
V_7 -> V_53 , ( char * ) & V_85 -> V_12 ) ;
return V_55 ;
}
V_100 = F_32 ( V_7 -> V_83 . V_101 , V_81 -> type ) ;
if ( F_33 ( V_100 ) ) {
F_14 ( V_49 , L_18 , V_7 -> V_53 ) ;
return - V_102 ;
}
V_7 -> V_24 = V_85 -> V_24 ;
V_7 -> V_26 = V_85 -> V_26 ;
V_7 -> V_28 = V_85 -> V_28 ;
V_7 -> V_30 = V_85 -> V_30 ;
V_7 -> V_9 . V_17 = F_6 ( V_85 -> V_13 , V_18 ) ;
V_7 -> V_9 . V_19 = F_6 ( V_85 -> V_15 ,
V_20 ) ;
V_7 -> V_9 . V_21 = V_85 -> V_89 ;
V_7 -> V_9 . V_12 = V_85 -> V_12 ;
V_7 -> V_9 . V_13 = V_85 -> V_13 ;
V_7 -> V_9 . V_15 = V_85 -> V_15 ;
V_7 -> V_61 |= V_92 ;
return 0 ;
}
static int F_35 ( struct V_69 * V_69 , void * V_83 , struct V_103 * V_104 )
{
struct V_6 * V_7 = F_21 ( V_69 -> V_73 ) ;
struct V_105 * V_106 = & V_7 -> V_107 . V_106 ;
if ( V_104 -> type != V_108 )
return - V_56 ;
V_104 -> V_109 . V_110 . V_111 = V_112 ;
V_104 -> V_109 . V_110 . V_113 . V_114 = V_106 -> V_114 ;
V_104 -> V_109 . V_110 . V_113 . V_115 =
V_106 -> V_115 ;
return 0 ;
}
static int F_36 ( struct V_69 * V_69 , void * V_83 , struct V_103 * V_104 )
{
struct V_6 * V_7 = F_21 ( V_69 -> V_73 ) ;
struct V_105 * V_106 = & V_7 -> V_107 . V_106 ;
if ( V_104 -> type != V_108 )
return - V_56 ;
if ( ! V_104 -> V_109 . V_110 . V_113 . V_114 ||
! V_104 -> V_109 . V_110 . V_113 . V_115 )
return F_35 ( V_69 , V_83 , V_104 ) ;
V_104 -> V_109 . V_110 . V_111 = V_112 ;
V_106 -> V_114 = V_104 -> V_109 . V_110 . V_113 . V_114 ;
V_106 -> V_115 =
V_104 -> V_109 . V_110 . V_113 . V_115 ;
return 0 ;
}
static int F_37 ( struct V_69 * V_69 , void * V_70 , struct V_116 * V_117 )
{
struct V_6 * V_7 = F_21 ( V_69 -> V_73 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
if ( V_117 -> type == V_118 ) {
struct V_99 * V_100 ;
struct V_119 * V_59 ;
V_100 = F_32 ( V_7 -> V_83 . V_101 , V_117 -> type ) ;
if ( V_117 -> V_82 >= V_100 -> V_120 ) {
F_14 ( V_49 , L_19 ,
V_7 -> V_53 , V_117 -> V_82 , V_100 -> V_120 ) ;
return - V_56 ;
}
V_59 = (struct V_119 * ) V_100 -> V_121 [ V_117 -> V_82 ] ;
V_59 -> V_122 = V_117 -> V_122 ;
}
return F_38 ( V_69 , V_7 -> V_83 . V_101 , V_117 ) ;
}
static int F_39 ( struct V_123 * V_124 )
{
struct V_6 * V_7 = F_40 ( V_124 -> V_125 , struct V_6 ,
V_126 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
F_14 ( V_49 , L_20 , V_7 -> V_53 ,
V_124 -> V_127 , V_124 -> V_128 ) ;
switch ( V_124 -> V_127 ) {
case V_129 :
V_7 -> V_107 . V_130 = V_124 -> V_128 ;
break;
case V_131 :
V_7 -> V_107 . V_132 = V_124 -> V_128 ;
break;
case V_133 :
V_7 -> V_107 . V_134 = V_124 -> V_128 ;
break;
case V_135 :
V_7 -> V_107 . V_136 = V_124 -> V_128 ;
break;
case V_137 :
V_7 -> V_107 . V_63 = V_124 -> V_128 ;
snprintf ( V_7 -> V_11 . V_63 ,
sizeof( V_7 -> V_11 . V_63 ) ,
L_21 ,
F_41 ( V_124 -> V_127 ) [ V_124 -> V_128 ] ) ;
break;
case V_138 :
V_7 -> V_107 . V_64 = V_124 -> V_128 ;
snprintf ( V_7 -> V_11 . V_64 ,
sizeof( V_7 -> V_11 . V_64 ) ,
L_22 ,
F_41 ( V_124 -> V_127 ) [ V_124 -> V_128 ] ) ;
break;
case V_139 :
V_7 -> V_107 . V_140 = V_124 -> V_128 ;
break;
case V_141 :
V_7 -> V_107 . V_142 = V_124 -> V_128 ;
break;
case V_143 :
V_7 -> V_107 . V_144 = V_124 -> V_128 ;
break;
case V_145 :
V_7 -> V_107 . V_146 = V_124 -> V_128 ;
break;
case V_147 :
V_7 -> V_107 . V_148 = V_124 -> V_128 ;
break;
case V_149 :
V_7 -> V_107 . V_150 = V_124 -> V_128 ;
break;
case V_151 :
V_7 -> V_107 . V_152 = V_124 -> V_128 ;
break;
case V_153 :
V_7 -> V_107 . V_154 = V_124 -> V_128 ;
break;
case V_155 :
V_7 -> V_107 . V_156 = V_124 -> V_128 ;
break;
default:
F_14 ( V_49 , L_23 ,
V_7 -> V_53 , V_124 -> V_127 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_42 ( struct V_6 * V_7 )
{
struct V_48 * V_49 = F_17 ( V_7 ) ;
T_2 V_157 ;
enum V_158 V_156 =
V_159 ;
F_43 ( & V_7 -> V_126 , 15 ) ;
F_44 ( & V_7 -> V_126 , & V_160 ,
V_129 ,
V_161 ,
0 ,
V_161 ) ;
F_45 ( & V_7 -> V_126 , & V_160 ,
V_131 ,
1 , 60 , 1 , 16 ) ;
F_45 ( & V_7 -> V_126 , & V_160 ,
V_133 ,
1000 , 60000000 , 1000 , 20000000 ) ;
V_157 = ~ ( 1 << V_162 ) ;
F_44 ( & V_7 -> V_126 , & V_160 ,
V_135 ,
V_162 ,
V_157 ,
V_162 ) ;
V_157 = ~ ( ( 1 << V_163 ) |
( 1 << V_164 ) |
( 1 << V_165 ) |
( 1 << V_166 ) ) ;
F_44 ( & V_7 -> V_126 , & V_160 ,
V_137 ,
V_166 ,
V_157 ,
V_165 ) ;
F_44 ( & V_7 -> V_126 , & V_160 ,
V_138 ,
V_167 ,
0 ,
V_168 ) ;
F_44 ( & V_7 -> V_126 , & V_160 ,
V_139 ,
V_169 ,
0 ,
V_170 ) ;
F_45 ( & V_7 -> V_126 , & V_160 ,
V_141 ,
1 , 10000 , 1 , 3000 ) ;
F_45 ( & V_7 -> V_126 , & V_160 ,
V_143 ,
0 , 1 , 1 , 0 ) ;
F_45 ( & V_7 -> V_126 , & V_160 ,
V_145 ,
0 , 51 , 1 , 5 ) ;
F_45 ( & V_7 -> V_126 , & V_160 ,
V_147 ,
0 , 51 , 1 , 51 ) ;
F_45 ( & V_7 -> V_126 , & V_160 ,
V_149 ,
0 , 1 , 1 , 1 ) ;
V_157 = ~ ( 1 << V_171 ) ;
F_44 ( & V_7 -> V_126 , & V_160 ,
V_151 ,
V_171 ,
V_157 ,
V_171 ) ;
F_45 ( & V_7 -> V_126 , & V_160 ,
V_153 ,
0 , 1 , 1 , 0 ) ;
V_157 = ~ ( 1 << V_156 ) ;
F_44 ( & V_7 -> V_126 , & V_160 ,
V_155 ,
V_156 ,
V_157 ,
V_156 ) ;
if ( V_7 -> V_126 . error ) {
int V_172 = V_7 -> V_126 . error ;
F_14 ( V_49 , L_24 ,
V_7 -> V_53 , V_172 ) ;
F_46 ( & V_7 -> V_126 ) ;
return V_172 ;
}
F_47 ( & V_7 -> V_126 ) ;
V_7 -> V_107 . V_106 . V_114 = V_173 ;
V_7 -> V_107 . V_106 . V_115 = V_174 ;
return 0 ;
}
static void F_48 ( struct V_175 * V_176 )
{
struct V_6 * V_7 = F_40 ( V_176 , struct V_6 , V_177 ) ;
struct V_178 * V_179 , * V_180 ;
const struct V_33 * V_36 = V_7 -> V_36 ;
struct V_181 * V_60 ;
struct V_119 * V_59 ;
int V_55 ;
F_49 ( & V_7 -> V_182 ) ;
#ifdef F_50
F_51 ( V_7 ) ;
#endif
V_179 = F_52 ( V_7 -> V_83 . V_101 ) ;
V_180 = F_53 ( V_7 -> V_83 . V_101 ) ;
V_60 = F_54 ( V_179 ) ;
V_59 = F_55 ( V_180 ) ;
V_60 -> V_183 . V_184 = V_7 -> V_185 ++ ;
V_55 = V_36 -> V_186 ( V_7 , V_60 , V_59 ) ;
F_56 ( & V_180 -> V_187 , 0 , V_59 -> V_122 ) ;
if ( V_55 ) {
F_57 ( V_179 , V_188 ) ;
F_57 ( V_180 , V_188 ) ;
} else {
V_180 -> V_187 . V_189 = V_179 -> V_187 . V_189 ;
V_180 -> V_86 = V_87 ;
V_180 -> V_184 = V_7 -> V_190 - 1 ;
V_7 -> V_65 ++ ;
#ifdef F_50
F_58 ( V_7 , V_59 ) ;
#endif
F_57 ( V_179 , V_191 ) ;
F_57 ( V_180 , V_191 ) ;
}
F_59 ( & V_7 -> V_182 ) ;
F_60 ( V_7 -> V_34 -> V_192 , V_7 -> V_83 . V_101 ) ;
}
static void F_61 ( void * V_70 )
{
struct V_6 * V_7 = V_70 ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
F_62 ( V_35 -> V_193 , & V_7 -> V_177 ) ;
}
static void F_63 ( void * V_70 )
{
struct V_6 * V_7 = V_70 ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
F_14 ( V_49 , L_25 , V_7 -> V_53 ) ;
V_7 -> V_194 = true ;
}
static int F_64 ( void * V_70 )
{
struct V_6 * V_7 = V_70 ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
if ( ! F_65 ( V_7 -> V_83 . V_101 ) ) {
F_14 ( V_49 , L_26 ,
V_7 -> V_53 ) ;
return 0 ;
}
if ( ! F_66 ( V_7 -> V_83 . V_101 ) ) {
F_14 ( V_49 , L_27 ,
V_7 -> V_53 ) ;
return 0 ;
}
if ( V_7 -> V_194 ) {
F_14 ( V_49 , L_28 , V_7 -> V_53 ) ;
return 0 ;
}
return 1 ;
}
static int F_67 ( struct V_99 * V_100 ,
unsigned int * V_120 , unsigned int * V_195 ,
unsigned int V_196 [] , struct V_48 * V_197 [] )
{
struct V_6 * V_7 = F_68 ( V_100 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
unsigned int V_21 ;
F_14 ( V_49 , L_29 , V_7 -> V_53 ,
F_69 ( V_100 -> type ) , * V_120 ) ;
V_21 = V_100 -> type == V_108 ?
V_7 -> V_9 . V_21 : V_7 -> V_32 ;
if ( * V_195 )
return V_196 [ 0 ] < V_21 ? - V_56 : 0 ;
* V_195 = 1 ;
V_196 [ 0 ] = V_21 ;
return 0 ;
}
static int F_70 ( struct V_198 * V_199 )
{
struct V_6 * V_7 = F_68 ( V_199 -> V_99 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_178 * V_183 = F_71 ( V_199 ) ;
if ( V_199 -> V_99 -> type == V_108 ) {
struct V_181 * V_60 = F_54 ( V_183 ) ;
if ( V_183 -> V_86 == V_200 )
V_183 -> V_86 = V_87 ;
if ( V_183 -> V_86 != V_87 ) {
F_14 ( V_49 ,
L_30 ,
V_7 -> V_53 , V_199 -> V_82 , V_183 -> V_86 ) ;
return - V_56 ;
}
if ( ! V_60 -> V_201 ) {
V_60 -> V_202 = F_72 ( & V_183 -> V_187 , 0 ) ;
V_60 -> V_203 = F_73 (
& V_183 -> V_187 , 0 ) ;
V_60 -> V_204 = V_7 -> V_9 ;
V_60 -> V_201 = true ;
F_14 ( V_49 ,
L_31 ,
V_7 -> V_53 , V_199 -> V_82 ,
V_60 -> V_202 , & V_60 -> V_203 ) ;
}
} else {
struct V_119 * V_59 = F_55 ( V_183 ) ;
if ( ! V_59 -> V_201 ) {
V_59 -> V_202 = F_72 ( & V_183 -> V_187 , 0 ) ;
V_59 -> V_203 = F_73 (
& V_183 -> V_187 , 0 ) ;
V_59 -> V_21 = F_74 ( & V_183 -> V_187 , 0 ) ;
V_59 -> V_201 = true ;
F_14 ( V_49 ,
L_32 ,
V_7 -> V_53 , V_199 -> V_82 ,
V_59 -> V_202 , & V_59 -> V_203 ) ;
}
}
return 0 ;
}
static void F_75 ( struct V_198 * V_199 )
{
struct V_6 * V_7 = F_68 ( V_199 -> V_99 ) ;
struct V_178 * V_183 = F_71 ( V_199 ) ;
if ( V_7 -> V_83 . V_101 )
F_76 ( V_7 -> V_83 . V_101 , V_183 ) ;
}
static int F_77 ( struct V_99 * V_100 , unsigned int V_205 )
{
struct V_6 * V_7 = F_68 ( V_100 ) ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
struct V_178 * V_183 ;
int V_55 ;
unsigned int V_37 ;
bool V_43 = false ;
F_14 ( V_49 , L_33 , V_7 -> V_53 ,
F_69 ( V_100 -> type ) ) ;
if ( F_78 ( V_100 -> type ) ) {
if ( ! F_79 ( & V_7 -> V_83 . V_101 -> V_206 . V_207 ) )
return 0 ;
} else {
if ( ! F_79 ( & V_7 -> V_83 . V_101 -> V_208 . V_207 ) )
return 0 ;
}
for ( V_37 = 0 ; V_37 < V_209 ; V_37 ++ ) {
if ( ! V_35 -> V_210 [ V_37 ] ) {
V_35 -> V_210 [ V_37 ] = V_7 ;
V_7 -> V_127 = V_37 ;
V_43 = true ;
break;
}
}
if ( ! V_43 ) {
F_18 ( V_49 , L_34 , V_7 -> V_53 ) ;
V_55 = - V_211 ;
goto V_172;
}
V_35 -> V_212 ++ ;
if ( ! V_7 -> V_36 ) {
V_55 = F_16 ( V_7 ,
V_7 -> V_11 . V_22 ,
V_7 -> V_9 . V_12 ,
& V_7 -> V_36 ) ;
if ( V_55 < 0 )
goto V_213;
}
return 0 ;
V_213:
V_35 -> V_210 [ V_7 -> V_127 ] = NULL ;
V_35 -> V_212 -- ;
V_172:
if ( V_100 -> type == V_108 ) {
while ( ( V_183 = F_52 ( V_7 -> V_83 . V_101 ) ) )
F_57 ( V_183 , V_214 ) ;
} else {
while ( ( V_183 = F_53 ( V_7 -> V_83 . V_101 ) ) )
F_57 ( V_183 , V_214 ) ;
}
V_7 -> V_66 ++ ;
return V_55 ;
}
static void F_80 ( struct V_99 * V_100 )
{
struct V_6 * V_7 = F_68 ( V_100 ) ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
const struct V_33 * V_36 = V_7 -> V_36 ;
struct V_178 * V_183 ;
F_14 ( V_49 , L_35 , V_7 -> V_53 ,
F_69 ( V_100 -> type ) ) ;
if ( V_100 -> type == V_108 ) {
V_7 -> V_185 = 0 ;
while ( ( V_183 = F_52 ( V_7 -> V_83 . V_101 ) ) )
F_57 ( V_183 , V_188 ) ;
} else {
V_7 -> V_190 = 0 ;
while ( ( V_183 = F_53 ( V_7 -> V_83 . V_101 ) ) )
F_57 ( V_183 , V_188 ) ;
}
if ( ( F_78 ( V_100 -> type ) &&
F_33 ( & V_7 -> V_83 . V_101 -> V_206 . V_207 ) ) ||
( ! F_78 ( V_100 -> type ) &&
F_33 ( & V_7 -> V_83 . V_101 -> V_208 . V_207 ) ) ) {
F_14 ( V_49 , L_36 ,
V_7 -> V_53 , F_69 ( V_100 -> type ) ,
F_33 ( & V_7 -> V_83 . V_101 -> V_208 . V_207 ) ,
F_33 ( & V_7 -> V_83 . V_101 -> V_206 . V_207 ) ) ;
return;
}
if ( V_36 ) {
F_14 ( V_49 , L_37 , V_7 -> V_53 , V_36 -> V_53 ) ;
V_36 -> V_215 ( V_7 ) ;
V_7 -> V_36 = NULL ;
V_35 -> V_210 [ V_7 -> V_127 ] = NULL ;
V_35 -> V_212 -- ;
}
V_7 -> V_194 = false ;
}
static int F_81 ( struct V_6 * V_7 , struct V_99 * V_100 )
{
V_100 -> V_216 = V_217 | V_218 ;
V_100 -> V_219 = V_7 ;
V_100 -> V_220 = & V_221 ;
V_100 -> V_222 = & V_223 ;
V_100 -> V_224 = V_225 ;
V_100 -> V_182 = & V_7 -> V_34 -> V_182 ;
return F_82 ( V_100 ) ;
}
static int F_83 ( void * V_70 , struct V_99 * V_226 ,
struct V_99 * V_227 )
{
struct V_6 * V_7 = V_70 ;
int V_55 ;
V_226 -> type = V_108 ;
V_226 -> V_228 = sizeof( struct V_181 ) ;
V_226 -> V_229 = V_230 ;
V_226 -> V_49 = V_7 -> V_34 -> V_49 ;
V_55 = F_81 ( V_7 , V_226 ) ;
if ( V_55 )
return V_55 ;
V_227 -> type = V_118 ;
V_227 -> V_228 = sizeof( struct V_119 ) ;
V_227 -> V_229 = V_231 ;
V_227 -> V_49 = V_7 -> V_34 -> V_49 ;
return F_81 ( V_7 , V_227 ) ;
}
static int F_84 ( struct V_69 * V_69 )
{
struct V_34 * V_35 = F_85 ( V_69 ) ;
struct V_48 * V_49 = F_12 ( V_35 ) ;
struct V_6 * V_7 ;
int V_55 ;
V_7 = F_86 ( sizeof( * V_7 ) , V_232 ) ;
if ( ! V_7 ) {
V_55 = - V_211 ;
goto V_233;
}
V_7 -> V_34 = V_35 ;
F_87 ( & V_7 -> V_177 , F_48 ) ;
F_88 ( & V_7 -> V_83 , F_89 ( V_69 ) ) ;
V_69 -> V_73 = & V_7 -> V_83 ;
F_90 ( & V_7 -> V_83 ) ;
V_55 = F_42 ( V_7 ) ;
if ( V_55 ) {
F_18 ( V_49 , L_38 ,
V_52 ) ;
V_7 -> V_66 ++ ;
goto V_234;
}
V_7 -> V_83 . V_126 = & V_7 -> V_126 ;
F_91 ( & V_7 -> V_182 ) ;
V_7 -> V_83 . V_101 = F_92 ( V_35 -> V_192 , V_7 ,
& F_83 ) ;
if ( F_93 ( V_7 -> V_83 . V_101 ) ) {
V_55 = F_94 ( V_7 -> V_83 . V_101 ) ;
F_18 ( V_49 , L_39 ,
V_52 , V_55 ) ;
V_7 -> V_66 ++ ;
goto V_235;
}
F_49 ( & V_35 -> V_182 ) ;
V_35 -> V_57 ++ ;
snprintf ( V_7 -> V_53 , sizeof( V_7 -> V_53 ) , L_40 ,
V_35 -> V_57 ) ;
F_59 ( & V_35 -> V_182 ) ;
F_5 ( V_7 ) ;
#ifdef F_50
F_95 ( V_7 ) ;
#endif
F_15 ( V_49 , L_41 , V_7 -> V_53 ) ;
return 0 ;
V_235:
F_46 ( & V_7 -> V_126 ) ;
V_234:
F_96 ( & V_7 -> V_83 ) ;
F_97 ( & V_7 -> V_83 ) ;
F_98 ( V_7 ) ;
V_233:
return V_55 ;
}
static int F_99 ( struct V_69 * V_69 )
{
struct V_6 * V_7 = F_21 ( V_69 -> V_73 ) ;
struct V_34 * V_35 = F_8 ( V_7 ) ;
struct V_48 * V_49 = F_17 ( V_7 ) ;
const struct V_33 * V_36 = V_7 -> V_36 ;
if ( V_36 ) {
F_14 ( V_49 , L_37 , V_7 -> V_53 , V_36 -> V_53 ) ;
V_36 -> V_215 ( V_7 ) ;
V_7 -> V_36 = NULL ;
V_35 -> V_210 [ V_7 -> V_127 ] = NULL ;
V_35 -> V_212 -- ;
}
F_19 ( V_7 ) ;
F_100 ( V_7 -> V_83 . V_101 ) ;
F_46 ( & V_7 -> V_126 ) ;
F_96 ( & V_7 -> V_83 ) ;
F_97 ( & V_7 -> V_83 ) ;
#ifdef F_50
F_101 ( V_7 ) ;
#endif
F_15 ( V_49 , L_42 , V_7 -> V_53 ) ;
F_98 ( V_7 ) ;
return 0 ;
}
static int F_102 ( struct V_34 * V_35 )
{
int V_55 ;
struct V_236 * V_77 ;
struct V_48 * V_49 ;
if ( ! V_35 )
return - V_237 ;
V_49 = F_12 ( V_35 ) ;
V_35 -> V_192 = F_103 ( & V_238 ) ;
if ( F_93 ( V_35 -> V_192 ) ) {
F_18 ( V_49 , L_43 ,
V_52 ) ;
V_55 = F_94 ( V_35 -> V_192 ) ;
goto V_172;
}
V_77 = F_104 () ;
if ( ! V_77 ) {
F_18 ( V_49 , L_44 ,
V_52 ) ;
V_55 = - V_211 ;
goto V_239;
}
V_77 -> V_240 = & V_241 ;
V_77 -> V_242 = & V_243 ;
V_77 -> V_244 = V_245 ;
V_77 -> V_182 = & V_35 -> V_182 ;
V_77 -> V_246 = V_247 ;
V_77 -> V_248 = V_249 | V_250 ;
V_77 -> V_251 = & V_35 -> V_251 ;
snprintf ( V_77 -> V_53 , sizeof( V_77 -> V_53 ) , L_45 , V_75 ,
V_35 -> V_252 ) ;
V_55 = F_105 ( V_77 , V_253 , - 1 ) ;
if ( V_55 ) {
F_18 ( V_49 , L_46 ,
V_52 ) ;
goto V_254;
}
V_35 -> V_77 = V_77 ;
F_106 ( V_77 , V_35 ) ;
return 0 ;
V_254:
V_245 ( V_77 ) ;
V_239:
F_107 ( V_35 -> V_192 ) ;
V_172:
return V_55 ;
}
static void F_108 ( struct V_34 * V_35 )
{
if ( ! V_35 )
return;
if ( V_35 -> V_192 )
F_107 ( V_35 -> V_192 ) ;
F_109 ( V_35 -> V_77 ) ;
}
static int F_110 ( struct V_255 * V_79 )
{
struct V_34 * V_35 ;
struct V_48 * V_49 = & V_79 -> V_49 ;
int V_55 ;
V_35 = F_111 ( V_49 , sizeof( * V_35 ) , V_232 ) ;
if ( ! V_35 ) {
V_55 = - V_211 ;
goto V_172;
}
V_35 -> V_49 = V_49 ;
V_35 -> V_79 = V_79 ;
F_112 ( V_79 , V_35 ) ;
F_91 ( & V_35 -> V_182 ) ;
V_55 = F_113 ( V_79 , V_35 ) ;
if ( V_55 )
goto V_172;
F_11 ( V_35 ) ;
F_10 ( V_35 ) ;
V_55 = F_114 ( V_49 , & V_35 -> V_251 ) ;
if ( V_55 ) {
F_18 ( V_49 , L_47 ,
V_52 , V_75 ) ;
goto V_256;
}
#ifdef F_50
F_115 ( V_35 ) ;
#endif
V_35 -> V_193 = F_116 ( V_75 ) ;
if ( ! V_35 -> V_193 ) {
F_18 ( V_49 , L_48 ,
V_52 , V_75 ) ;
V_55 = - V_211 ;
goto V_257;
}
V_55 = F_102 ( V_35 ) ;
if ( V_55 )
goto V_258;
F_15 ( V_49 , L_49 , V_52 ,
V_75 , V_35 -> V_77 -> V_259 ) ;
return 0 ;
V_258:
F_117 ( V_35 -> V_193 ) ;
V_257:
#ifdef F_50
F_118 ( V_35 ) ;
#endif
F_119 ( & V_35 -> V_251 ) ;
V_256:
F_120 ( V_35 ) ;
V_172:
return V_55 ;
}
static int F_121 ( struct V_255 * V_79 )
{
struct V_34 * V_35 = F_122 ( V_79 ) ;
struct V_48 * V_49 = F_12 ( V_35 ) ;
F_108 ( V_35 ) ;
F_117 ( V_35 -> V_193 ) ;
F_120 ( V_35 ) ;
#ifdef F_50
F_118 ( V_35 ) ;
#endif
F_119 ( & V_35 -> V_251 ) ;
F_15 ( V_49 , L_50 , V_52 , V_79 -> V_53 ) ;
return 0 ;
}
