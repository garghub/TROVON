static bool F_1 ( enum V_1 type )
{
return type == V_2 ||
type == V_3 ;
}
static bool F_2 ( enum V_1 type )
{
return type == V_2 ||
type == V_3 ;
}
static void F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
T_1 type ;
for ( type = 0 ; type < V_8 ; type ++ ) {
V_7 -> V_9 += V_5 -> V_10 [ type ] . V_11 ;
V_7 -> V_12 += V_5 -> V_10 [ type ] . V_13 ;
}
}
static void F_4 ( struct V_4 * V_5 ,
struct V_14 * V_7 )
{
T_1 V_15 ;
for ( V_15 = 0 ; V_15 < V_8 ; V_15 ++ ) {
if ( ! F_1 ( V_15 ) )
continue;
V_7 -> V_9 += V_5 -> V_10 [ V_15 ] . V_11 ;
V_7 -> V_12 += V_5 -> V_10 [ V_15 ] . V_13 ;
}
}
static void F_5 ( struct V_4 * V_5 ,
struct V_16 * V_7 )
{
T_1 V_15 , V_17 ;
for ( V_15 = 0 ; V_15 < V_8 ; V_15 ++ ) {
struct V_18 * V_19 = & V_5 -> V_10 [ V_15 ] ;
if ( F_2 ( V_15 ) ) {
V_7 -> V_9 += V_19 -> V_11 ;
V_7 -> V_12 += V_19 -> V_13 ;
}
}
V_7 -> V_9 = F_6 ( V_7 -> V_9 , V_20 ) ;
V_7 -> V_12 = F_6 ( V_7 -> V_12 , V_20 ) ;
V_7 -> V_21 = F_6 ( V_7 -> V_21 , V_20 ) ;
for ( V_7 -> V_22 = 0 , V_17 = 0 ; V_17 < V_23 ; V_17 ++ ) {
V_7 -> V_24 [ V_17 ] = F_6 ( V_7 -> V_24 [ V_17 ] , V_20 ) ;
V_7 -> V_22 += V_7 -> V_24 [ V_17 ] ;
}
}
static void F_7 ( struct V_25 * V_26 ,
struct V_27 * V_7 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
struct V_29 * V_30 ;
T_1 V_31 = 0 , type , V_17 ;
T_1 V_32 = 0 ;
for ( type = 0 ; type < V_8 ; type ++ ) {
V_7 -> V_33 += V_5 -> V_10 [ type ] . V_11 ;
V_31 += V_5 -> V_10 [ type ] . V_13 ;
V_30 = V_5 -> V_10 [ type ] . V_34 ;
for ( V_17 = 0 ; V_17 < V_23 ; V_17 ++ )
V_7 -> V_35 += V_30 [ V_17 ] . V_36 ;
V_32 += V_30 [ V_23 ] . V_36 ;
}
V_7 -> V_31 += V_31 * V_5 -> V_37 ;
V_7 -> V_35 += V_32 * V_5 -> V_37 ;
F_8 ( V_26 , V_38 ,
L_1 ,
V_7 -> V_33 , V_7 -> V_31 , V_7 -> V_35 , V_32 ) ;
}
static struct V_29 * F_9 ( struct V_25 * V_26 ,
T_1 V_39 )
{
struct V_4 * V_19 = V_26 -> V_28 ;
T_1 V_15 ;
for ( V_15 = 0 ; V_15 < V_8 ; V_15 ++ )
if ( V_19 -> V_10 [ V_15 ] . V_34 [ V_39 ] . V_36 )
return & V_19 -> V_10 [ V_15 ] . V_34 [ V_39 ] ;
return NULL ;
}
void F_10 ( struct V_25 * V_26 , T_1 V_40 )
{
struct V_4 * V_41 = V_26 -> V_28 ;
V_41 -> V_42 = V_40 ;
}
T_1 F_11 ( struct V_25 * V_26 )
{
struct V_4 * V_41 = V_26 -> V_28 ;
return V_41 -> V_42 ;
}
static void F_12 ( struct V_25 * V_26 ,
enum V_1 type ,
T_1 V_11 , T_1 V_43 )
{
struct V_4 * V_41 = V_26 -> V_28 ;
struct V_18 * V_44 = & V_41 -> V_10 [ type ] ;
V_44 -> V_11 = F_6 ( V_11 , V_45 ) ;
V_44 -> V_13 = F_6 ( V_43 , V_45 ) ;
if ( type == V_3 ) {
T_1 V_46 = V_41 -> V_47 [ V_48 ] . V_49 . V_50 ;
T_1 V_51 = F_13 ( V_26 ) ;
T_1 V_52 = F_14 ( V_46 ) / V_51 ;
V_44 -> V_11 = F_6 ( V_44 -> V_11 , V_52 ) ;
}
}
T_1 F_15 ( struct V_25 * V_26 ,
enum V_1 type ,
T_1 * V_53 )
{
if ( V_53 )
* V_53 = V_26 -> V_28 -> V_10 [ type ] . V_13 ;
return V_26 -> V_28 -> V_10 [ type ] . V_11 ;
}
T_1 F_16 ( struct V_25 * V_26 ,
enum V_1 type )
{
return V_26 -> V_28 -> V_54 [ type ] . V_55 ;
}
T_1 F_17 ( struct V_25 * V_26 ,
enum V_1 type )
{
T_1 V_56 = 0 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_57 ; V_15 ++ )
V_56 += V_26 -> V_28 -> V_10 [ type ] . V_34 [ V_15 ] . V_36 ;
return V_56 ;
}
static void
F_18 ( struct V_25 * V_26 ,
enum V_1 V_58 ,
T_2 V_39 , T_2 V_59 , T_1 V_36 , bool V_60 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
struct V_29 * V_61 = & V_5 -> V_10 [ V_58 ] . V_34 [ V_39 ] ;
V_61 -> V_36 = V_36 ;
V_61 -> V_62 = V_60 ;
V_61 -> type = V_59 ;
}
static void F_19 ( struct V_63 * V_64 ,
struct V_65 * V_66 ,
T_1 V_67 , T_1 V_68 ,
T_1 V_69 )
{
T_1 V_70 = F_14 ( V_64 -> V_49 . V_50 ) ;
if ( V_66 -> V_68 )
return;
V_66 -> V_68 = V_68 ;
V_66 -> V_71 = 0 ;
if ( V_69 )
V_66 -> V_71 = ( V_70 / V_69 ) * V_69 ;
V_66 -> V_67 = V_67 ;
}
static void F_20 ( struct V_25 * V_26 ,
struct V_63 * V_64 ,
struct V_65 * V_66 ,
T_1 * V_72 , enum V_73 V_74 )
{
if ( ! V_66 -> V_68 )
return;
if ( ! V_64 -> V_75 )
V_64 -> V_76 . V_50 = * V_72 ;
V_64 -> V_75 = true ;
* V_72 += F_21 ( V_66 -> V_68 ,
V_66 -> V_71 ) ;
V_64 -> V_77 . V_50 = * V_72 - 1 ;
F_8 ( V_26 , V_38 ,
L_2 ,
V_74 , V_64 -> V_76 . V_50 ,
V_64 -> V_77 . V_50 , V_66 -> V_68 ,
V_66 -> V_71 , V_66 -> V_67 ) ;
}
static T_1 F_22 ( struct V_25 * V_26 ,
enum V_73 V_78 )
{
T_1 V_11 = V_26 -> V_28 -> V_10 [ V_3 ] . V_11 ;
struct V_63 * V_64 ;
T_1 V_79 = 0 ;
T_1 V_80 ;
if ( V_78 == V_48 ) {
V_64 = & V_26 -> V_28 -> V_47 [ V_48 ] ;
V_80 = F_14 ( V_64 -> V_49 . V_50 ) /
( T_1 ) F_13 ( V_26 ) ;
V_79 = V_11 / V_80 ;
}
return V_79 ;
}
int F_23 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
T_1 V_81 , V_82 , V_15 , V_83 , line ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_6 V_84 ;
struct V_14 V_85 ;
struct V_27 V_86 ;
struct V_16 V_87 ;
struct V_29 * V_61 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_5 -> V_88 = F_24 ( V_26 , V_89 ) ;
F_8 ( V_26 , V_38 ,
L_3 ,
V_26 -> V_90 , V_26 -> V_28 -> V_88 ) ;
V_64 = & V_5 -> V_47 [ V_48 ] ;
V_81 = V_5 -> V_88 ;
V_64 -> V_91 = 0 ;
F_3 ( V_5 , & V_84 ) ;
V_66 = & V_64 -> V_92 [ V_93 ] ;
V_82 = V_84 . V_9 * F_13 ( V_26 ) ;
F_19 ( V_64 , V_66 , V_81 ,
V_82 , F_13 ( V_26 ) ) ;
F_20 ( V_26 , V_64 , V_66 , & V_81 , V_48 ) ;
V_64 -> V_91 = V_81 - V_66 -> V_67 ;
V_66 -> V_94 = F_22 ( V_26 ,
V_48 ) ;
V_66 = & V_64 -> V_95 [ V_93 ] ;
V_82 = V_84 . V_12 * F_13 ( V_26 ) ;
F_19 ( V_64 , V_66 , V_81 ,
V_82 , F_13 ( V_26 ) ) ;
F_20 ( V_26 , V_64 , V_66 , & V_81 , V_48 ) ;
V_64 -> V_96 = V_81 - V_66 -> V_67 ;
for ( V_15 = 1 ; V_15 < V_5 -> V_37 ; V_15 ++ )
F_20 ( V_26 , V_64 , V_66 , & V_81 ,
V_48 ) ;
V_64 = & V_5 -> V_47 [ V_97 ] ;
V_64 -> V_76 . V_50 = V_81 ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ ) {
V_61 = F_9 ( V_26 , V_15 ) ;
if ( ! V_61 || V_61 -> V_36 == 0 )
continue;
V_66 = & V_64 -> V_92 [ F_25 ( V_15 ) ] ;
V_82 = V_61 -> V_36 * V_5 -> V_98 [ V_61 -> type ] ;
F_19 ( V_64 , V_66 , V_81 , V_82 ,
V_5 -> V_98 [ V_61 -> type ] ) ;
F_20 ( V_26 , V_64 , V_66 , & V_81 ,
V_97 ) ;
}
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ ) {
V_61 = F_9 ( V_26 , V_15 ) ;
if ( ! V_61 || V_61 -> V_36 == 0 )
continue;
V_66 = & V_64 -> V_92 [ F_26 ( V_15 , V_99 ) ] ;
if ( ! V_61 -> V_62 ) {
line = V_64 -> V_92 [ F_25 ( V_15 ) ] . V_67 ;
F_19 ( V_64 , V_66 , line , 0 , 0 ) ;
continue;
}
V_82 = V_61 -> V_36 * V_5 -> V_98 [ V_61 -> type ] ;
F_19 ( V_64 , V_66 ,
V_81 , V_82 ,
V_5 -> V_98 [ V_61 -> type ] ) ;
F_20 ( V_26 , V_64 , V_66 , & V_81 ,
V_97 ) ;
}
V_64 -> V_91 = V_81 - V_64 -> V_92 [ 0 ] . V_67 ;
V_61 = F_9 ( V_26 , V_100 ) ;
if ( V_61 && V_61 -> V_36 ) {
V_82 = V_61 -> V_36 * V_5 -> V_98 [ V_61 -> type ] ;
V_66 = & V_64 -> V_95 [ F_25 ( 0 ) ] ;
F_19 ( V_64 , V_66 ,
V_81 , V_82 ,
V_5 -> V_98 [ V_61 -> type ] ) ;
F_20 ( V_26 , V_64 , V_66 , & V_81 ,
V_97 ) ;
V_66 = & V_64 -> V_95 [ F_26 ( 0 , V_101 ) ] ;
if ( ! V_61 -> V_62 ) {
line = V_64 -> V_95 [ F_25 ( 0 ) ] . V_67 ;
F_19 ( V_64 , V_66 , line , 0 , 0 ) ;
} else {
V_83 = V_5 -> V_98 [ V_61 -> type ] ;
F_19 ( V_64 , V_66 ,
V_81 , V_82 , V_83 ) ;
F_20 ( V_26 , V_64 , V_66 , & V_81 ,
V_97 ) ;
}
V_64 -> V_96 = V_81 -
V_64 -> V_95 [ 0 ] . V_67 ;
for ( V_15 = 1 ; V_15 < V_5 -> V_37 ; V_15 ++ ) {
V_66 = & V_64 -> V_95 [ F_25 ( 0 ) ] ;
F_20 ( V_26 , V_64 , V_66 , & V_81 ,
V_97 ) ;
V_66 = & V_64 -> V_95 [ F_26 ( 0 , V_101 ) ] ;
F_20 ( V_26 , V_64 , V_66 , & V_81 ,
V_97 ) ;
}
}
V_64 = & V_5 -> V_47 [ V_102 ] ;
V_66 = & V_64 -> V_92 [ 0 ] ;
F_7 ( V_26 , & V_86 ) ;
V_82 = F_27 ( V_26 -> V_103 , V_86 . V_33 ,
V_86 . V_31 , V_86 . V_35 ,
V_26 -> V_104 . V_105 ,
V_26 -> V_104 . V_106 ) ;
F_8 ( V_26 ,
V_38 ,
L_4 ,
V_86 . V_33 ,
V_86 . V_31 ,
V_86 . V_35 ,
V_26 -> V_104 . V_105 , V_26 -> V_104 . V_106 , V_82 ) ;
F_19 ( V_64 , V_66 ,
V_81 , V_82 * 0x1000 ,
V_107 ) ;
F_20 ( V_26 , V_64 , V_66 , & V_81 , V_102 ) ;
V_64 -> V_91 = V_81 - V_66 -> V_67 ;
V_64 = & V_5 -> V_47 [ V_108 ] ;
F_4 ( V_5 , & V_85 ) ;
V_82 = V_85 . V_9 + V_85 . V_12 * V_5 -> V_37 ;
if ( V_82 ) {
T_1 V_109 = F_28 ( T_1 , V_82 ,
V_110 ) ;
V_82 = F_29 ( V_109 ) ;
V_66 = & V_64 -> V_92 [ 0 ] ;
F_19 ( V_64 , V_66 , V_81 ,
V_82 * sizeof( struct V_111 ) ,
sizeof( struct V_111 ) ) ;
F_20 ( V_26 , V_64 , V_66 , & V_81 ,
V_108 ) ;
V_64 -> V_91 = V_81 - V_66 -> V_67 ;
}
V_64 = & V_5 -> V_47 [ V_112 ] ;
F_5 ( V_5 , & V_87 ) ;
V_82 = V_87 . V_9 + V_87 . V_22 ;
if ( V_82 ) {
V_66 = & V_64 -> V_92 [ 0 ] ;
F_19 ( V_64 , V_66 , V_81 ,
V_82 * V_113 , V_113 ) ;
F_20 ( V_26 , V_64 , V_66 , & V_81 ,
V_112 ) ;
V_64 -> V_91 = V_81 - V_66 -> V_67 ;
}
V_82 = V_87 . V_12 + V_87 . V_21 ;
if ( V_82 ) {
V_66 = & V_64 -> V_95 [ 0 ] ;
F_19 ( V_64 , V_66 , V_81 ,
V_82 * V_113 , V_113 ) ;
F_20 ( V_26 , V_64 , V_66 , & V_81 ,
V_112 ) ;
V_64 -> V_91 = V_81 - V_66 -> V_67 ;
for ( V_15 = 1 ; V_15 < V_5 -> V_37 ; V_15 ++ )
F_20 ( V_26 , V_64 , V_66 , & V_81 ,
V_112 ) ;
}
V_82 = F_11 ( V_26 ) ;
if ( V_82 ) {
V_64 = & V_5 -> V_47 [ V_114 ] ;
V_66 = & V_64 -> V_92 [ V_115 ] ;
F_19 ( V_64 , V_66 , V_81 ,
V_82 * V_116 , V_116 ) ;
F_20 ( V_26 , V_64 , V_66 , & V_81 ,
V_114 ) ;
V_64 -> V_91 = V_81 - V_66 -> V_67 ;
}
if ( V_81 - V_26 -> V_28 -> V_88 >
F_30 ( V_26 , V_89 ) ) {
F_31 ( V_26 , L_5 ,
V_81 - V_26 -> V_28 -> V_88 ) ;
return - V_117 ;
}
return 0 ;
}
static void F_32 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
T_1 V_15 ;
if ( ! V_5 -> V_118 )
return;
for ( V_15 = 0 ; V_15 < V_5 -> V_119 ; V_15 ++ )
if ( V_5 -> V_118 [ V_15 ] . V_120 )
F_33 ( & V_26 -> V_121 -> V_122 -> V_123 ,
V_5 -> V_118 [ V_15 ] . V_124 ,
V_5 -> V_118 [ V_15 ] . V_120 ,
V_5 -> V_118 [ V_15 ] . V_125 ) ;
F_34 ( V_5 -> V_118 ) ;
V_5 -> V_118 = NULL ;
}
static int F_35 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
T_1 V_126 , V_68 , V_127 , V_128 , V_15 ;
struct V_63 * V_129 ;
struct V_14 V_85 ;
struct V_130 * V_131 ;
int V_132 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_129 = & V_26 -> V_28 -> V_47 [ V_108 ] ;
if ( ! V_129 -> V_75 )
return 0 ;
F_4 ( V_5 , & V_85 ) ;
V_126 = V_85 . V_9 + V_85 . V_12 * V_5 -> V_37 ;
V_68 = V_126 * sizeof( struct V_111 ) ;
V_128 = F_14 ( V_129 -> V_49 . V_50 ) ;
V_5 -> V_119 = F_21 ( V_68 , V_128 ) ;
V_5 -> V_118 = F_36 ( V_5 -> V_119 * sizeof( struct V_130 ) ,
V_133 ) ;
if ( ! V_5 -> V_118 ) {
F_37 ( V_26 , L_6 ) ;
V_132 = - V_134 ;
goto V_135;
}
for ( V_15 = 0 ; V_15 < V_5 -> V_119 ; V_15 ++ ) {
T_1 V_124 = F_38 ( T_1 , V_68 , V_128 ) ;
void * * V_120 = & V_5 -> V_118 [ V_15 ] . V_120 ;
* V_120 = F_39 ( & V_26 -> V_121 -> V_122 -> V_123 ,
V_124 ,
& V_5 -> V_118 [ V_15 ] . V_125 , V_133 ) ;
if ( ! V_5 -> V_118 [ V_15 ] . V_120 ) {
V_132 = - V_134 ;
goto V_135;
}
memset ( * V_120 , 0 , V_124 ) ;
V_5 -> V_118 [ V_15 ] . V_124 = V_124 ;
V_68 -= V_124 ;
}
V_127 = V_128 / sizeof( struct V_111 ) ;
V_5 -> V_136 = ( V_137 ) V_5 -> V_118 [ 0 ] . V_125 ;
V_131 = & V_5 -> V_118 [ ( V_126 - 1 ) / V_127 ] ;
V_5 -> V_138 = ( V_137 ) V_131 -> V_125 +
( ( V_126 - 1 ) & ( V_127 - 1 ) ) * sizeof( struct V_111 ) ;
for ( V_15 = 0 ; V_15 < V_5 -> V_119 ; V_15 ++ ) {
T_1 V_139 = F_38 ( T_1 ,
V_127 ,
V_126 ) ;
struct V_111 * V_140 = V_5 -> V_118 [ V_15 ] . V_120 ;
V_137 V_141 = ( V_137 ) V_5 -> V_118 [ V_15 ] . V_125 , V_50 ;
T_1 V_17 ;
for ( V_17 = 0 ; V_17 < V_139 - 1 ; V_17 ++ ) {
V_50 = V_141 + ( V_17 + 1 ) * sizeof( struct V_111 ) ;
V_140 [ V_17 ] . V_142 = F_40 ( V_50 ) ;
}
if ( V_15 < V_5 -> V_119 - 1 )
V_50 = ( V_137 ) V_5 -> V_118 [ V_15 + 1 ] . V_125 ;
else
V_50 = 0 ;
V_140 [ V_17 ] . V_142 = F_40 ( V_50 ) ;
V_126 -= V_139 ;
}
return 0 ;
V_135:
F_32 ( V_26 ) ;
return V_132 ;
}
static T_1 F_41 ( struct V_63 * V_73 )
{
T_1 V_124 = 0 ;
T_1 V_15 ;
F_42 (i, ilt_clients)
V_124 += ( V_73 [ V_15 ] . V_77 . V_50 - V_73 [ V_15 ] . V_76 . V_50 + 1 ) ;
return V_124 ;
}
static void F_43 ( struct V_25 * V_26 )
{
struct V_63 * V_64 = V_26 -> V_28 -> V_47 ;
struct V_4 * V_5 = V_26 -> V_28 ;
T_1 V_70 , V_15 ;
V_70 = F_41 ( V_64 ) ;
for ( V_15 = 0 ; V_5 -> V_143 && V_15 < V_70 ; V_15 ++ ) {
struct V_130 * V_144 = & V_5 -> V_143 [ V_15 ] ;
if ( V_144 -> V_120 )
F_33 ( & V_26 -> V_121 -> V_122 -> V_123 ,
V_144 -> V_124 , V_144 -> V_120 ,
V_144 -> V_125 ) ;
V_144 -> V_120 = NULL ;
}
F_34 ( V_5 -> V_143 ) ;
}
static int F_44 ( struct V_25 * V_26 ,
struct V_65 * V_66 ,
enum V_73 V_78 ,
T_1 V_145 )
{
struct V_130 * V_143 = V_26 -> V_28 -> V_143 ;
T_1 V_146 , line , V_147 , V_79 = 0 ;
if ( ( V_26 -> V_148 . V_149 == V_150 ) &&
( ( V_78 == V_97 ) || V_78 == V_114 ) )
return 0 ;
V_79 = V_66 -> V_94 ;
if ( ! V_66 -> V_68 )
return 0 ;
V_147 = V_66 -> V_68 ;
V_146 = F_21 ( V_147 , V_66 -> V_71 ) - V_79 ;
line = V_66 -> V_67 + V_145 -
V_26 -> V_28 -> V_88 + V_79 ;
for (; V_146 ; V_146 -- ) {
T_3 V_125 ;
void * V_120 ;
T_1 V_124 ;
V_124 = F_38 ( T_1 , V_147 ,
V_66 -> V_71 ) ;
V_120 = F_39 ( & V_26 -> V_121 -> V_122 -> V_123 ,
V_124 ,
& V_125 ,
V_133 ) ;
if ( ! V_120 )
return - V_134 ;
memset ( V_120 , 0 , V_124 ) ;
V_143 [ line ] . V_125 = V_125 ;
V_143 [ line ] . V_120 = V_120 ;
V_143 [ line ] . V_124 = V_124 ;
F_8 ( V_26 , V_38 ,
L_7 ,
line , ( V_137 ) V_125 , V_120 , V_124 ) ;
V_147 -= V_124 ;
line ++ ;
}
return 0 ;
}
static int F_45 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
struct V_63 * V_47 = V_5 -> V_47 ;
struct V_65 * V_66 ;
T_1 V_124 , V_15 , V_17 , V_151 ;
int V_132 ;
V_124 = F_41 ( V_47 ) ;
V_5 -> V_143 = F_46 ( V_124 , sizeof( struct V_130 ) ,
V_133 ) ;
if ( ! V_5 -> V_143 ) {
F_37 ( V_26 , L_8 ) ;
V_132 = - V_134 ;
goto V_152;
}
F_8 ( V_26 , V_38 ,
L_9 ,
( T_1 ) ( V_124 * sizeof( struct V_130 ) ) ) ;
F_42 (i, clients) {
for ( V_17 = 0 ; V_17 < V_153 ; V_17 ++ ) {
V_66 = & V_47 [ V_15 ] . V_92 [ V_17 ] ;
V_132 = F_44 ( V_26 , V_66 , V_15 , 0 ) ;
if ( V_132 != 0 )
goto V_152;
}
for ( V_151 = 0 ; V_151 < V_5 -> V_37 ; V_151 ++ ) {
for ( V_17 = 0 ; V_17 < V_154 ; V_17 ++ ) {
T_1 V_146 = V_47 [ V_15 ] . V_96 * V_151 ;
V_66 = & V_47 [ V_15 ] . V_95 [ V_17 ] ;
V_132 = F_44 ( V_26 , V_66 , V_15 , V_146 ) ;
if ( V_132 != 0 )
goto V_152;
}
}
}
return 0 ;
V_152:
F_43 ( V_26 ) ;
return V_132 ;
}
static void F_47 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
T_1 type ;
for ( type = 0 ; type < V_8 ; type ++ ) {
F_34 ( V_5 -> V_54 [ type ] . V_155 ) ;
V_5 -> V_54 [ type ] . V_156 = 0 ;
V_5 -> V_54 [ type ] . V_55 = 0 ;
}
}
static int F_48 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
T_1 V_55 = 0 ;
T_1 type ;
for ( type = 0 ; type < V_8 ; type ++ ) {
T_1 V_157 = V_26 -> V_28 -> V_10 [ type ] . V_11 ;
T_1 V_124 ;
if ( V_157 == 0 )
continue;
V_124 = F_21 ( V_157 ,
sizeof( unsigned long ) * V_158 ) *
sizeof( unsigned long ) ;
V_5 -> V_54 [ type ] . V_155 = F_36 ( V_124 , V_133 ) ;
if ( ! V_5 -> V_54 [ type ] . V_155 )
goto V_159;
V_5 -> V_54 [ type ] . V_156 = V_157 ;
V_5 -> V_54 [ type ] . V_55 = V_55 ;
V_26 -> V_28 -> V_10 [ type ] . V_160 = V_55 ;
F_8 ( V_26 , V_161 ,
L_10 ,
type , V_5 -> V_54 [ type ] . V_55 ,
V_5 -> V_54 [ type ] . V_156 ) ;
V_55 += V_157 ;
}
return 0 ;
V_159:
F_47 ( V_26 ) ;
return - V_134 ;
}
int F_49 ( struct V_25 * V_26 )
{
struct V_63 * V_47 ;
struct V_4 * V_5 ;
T_1 V_15 ;
V_5 = F_36 ( sizeof( * V_5 ) , V_133 ) ;
if ( ! V_5 ) {
F_37 ( V_26 , L_11 ) ;
return - V_134 ;
}
V_47 = V_5 -> V_47 ;
V_47 [ V_48 ] . V_76 . V_162 = F_50 ( V_163 , V_164 ) ;
V_47 [ V_48 ] . V_77 . V_162 = F_50 ( V_163 , V_165 ) ;
V_47 [ V_48 ] . V_49 . V_162 = F_50 ( V_163 , V_166 ) ;
V_47 [ V_102 ] . V_76 . V_162 = F_50 ( V_167 , V_164 ) ;
V_47 [ V_102 ] . V_77 . V_162 = F_50 ( V_167 , V_165 ) ;
V_47 [ V_102 ] . V_49 . V_162 = F_50 ( V_167 , V_166 ) ;
V_47 [ V_112 ] . V_76 . V_162 = F_50 ( V_168 , V_164 ) ;
V_47 [ V_112 ] . V_77 . V_162 = F_50 ( V_168 , V_165 ) ;
V_47 [ V_112 ] . V_49 . V_162 = F_50 ( V_168 , V_166 ) ;
V_47 [ V_108 ] . V_76 . V_162 = F_50 ( V_169 , V_164 ) ;
V_47 [ V_108 ] . V_77 . V_162 = F_50 ( V_169 , V_165 ) ;
V_47 [ V_108 ] . V_49 . V_162 = F_50 ( V_169 , V_166 ) ;
V_47 [ V_97 ] . V_76 . V_162 = F_50 ( V_170 , V_164 ) ;
V_47 [ V_97 ] . V_77 . V_162 = F_50 ( V_170 , V_165 ) ;
V_47 [ V_97 ] . V_49 . V_162 = F_50 ( V_170 , V_166 ) ;
V_47 [ V_114 ] . V_76 . V_162 = F_50 ( V_171 , V_164 ) ;
V_47 [ V_114 ] . V_77 . V_162 = F_50 ( V_171 , V_165 ) ;
V_47 [ V_114 ] . V_49 . V_162 = F_50 ( V_171 , V_166 ) ;
for ( V_15 = 0 ; V_15 < V_172 ; V_15 ++ )
V_5 -> V_47 [ V_15 ] . V_49 . V_50 = V_173 ;
V_5 -> V_98 [ 0 ] = F_51 ( V_26 ) ;
V_5 -> V_98 [ 1 ] = F_52 ( V_26 ) ;
if ( V_26 -> V_121 -> V_174 )
V_5 -> V_37 = V_26 -> V_121 -> V_174 -> V_175 ;
F_53 ( & V_5 -> V_176 ) ;
V_26 -> V_28 = V_5 ;
return 0 ;
}
int F_54 ( struct V_25 * V_26 )
{
int V_132 ;
V_132 = F_45 ( V_26 ) ;
if ( V_132 ) {
F_37 ( V_26 , L_12 ) ;
goto V_177;
}
V_132 = F_35 ( V_26 ) ;
if ( V_132 ) {
F_37 ( V_26 , L_13 ) ;
goto V_177;
}
V_132 = F_48 ( V_26 ) ;
if ( V_132 ) {
F_37 ( V_26 , L_14 ) ;
goto V_177;
}
return 0 ;
V_177:
F_55 ( V_26 ) ;
return V_132 ;
}
void F_55 ( struct V_25 * V_26 )
{
if ( ! V_26 -> V_28 )
return;
F_47 ( V_26 ) ;
F_32 ( V_26 ) ;
F_43 ( V_26 ) ;
F_34 ( V_26 -> V_28 ) ;
V_26 -> V_28 = NULL ;
}
void F_56 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
int type ;
for ( type = 0 ; type < V_8 ; type ++ ) {
T_1 V_157 = V_26 -> V_28 -> V_10 [ type ] . V_11 ;
if ( V_157 == 0 )
continue;
memset ( V_5 -> V_54 [ type ] . V_155 , 0 ,
F_21 ( V_157 ,
sizeof( unsigned long ) * V_158 ) *
sizeof( unsigned long ) ) ;
}
}
static void F_57 ( struct V_25 * V_26 )
{
T_1 V_46 , V_52 , V_178 , V_51 , V_179 = 0 ;
V_46 = V_26 -> V_28 -> V_47 [ V_48 ] . V_49 . V_50 ;
V_51 = F_13 ( V_26 ) ;
V_52 = F_14 ( V_46 ) / V_51 ;
V_178 = F_14 ( V_46 ) - V_52 * V_51 ;
F_58 ( V_179 , V_180 , V_51 ) ;
F_58 ( V_179 , V_181 , V_178 ) ;
F_58 ( V_179 , V_182 , V_52 ) ;
F_59 ( V_26 , V_183 , V_179 ) ;
V_46 = V_26 -> V_28 -> V_47 [ V_97 ] . V_49 . V_50 ;
V_51 = V_26 -> V_28 -> V_98 [ 0 ] ;
V_52 = F_14 ( V_46 ) / V_51 ;
V_178 = F_14 ( V_46 ) - V_52 * V_51 ;
V_179 = 0 ;
F_58 ( V_179 , V_184 , ( V_51 >> 3 ) ) ;
F_58 ( V_179 , V_185 , ( V_178 >> 3 ) ) ;
F_58 ( V_179 , V_186 , V_52 ) ;
F_59 ( V_26 , V_187 , V_179 ) ;
V_51 = V_26 -> V_28 -> V_98 [ 1 ] ;
V_52 = F_14 ( V_46 ) / V_51 ;
V_178 = F_14 ( V_46 ) - V_52 * V_51 ;
V_179 = 0 ;
F_58 ( V_179 , V_188 , ( V_51 >> 3 ) ) ;
F_58 ( V_179 , V_189 , ( V_178 >> 3 ) ) ;
F_58 ( V_179 , V_190 , V_52 ) ;
F_59 ( V_26 , V_191 , V_179 ) ;
}
static void F_60 ( struct V_25 * V_26 )
{
struct V_63 * V_64 ;
struct V_29 * V_61 ;
T_1 V_192 , V_193 ;
int V_15 ;
static const T_1 V_194 [] = {
V_195 ,
V_196 ,
V_197 ,
V_198
} ;
static const T_1 V_199 [] = {
V_200 ,
V_201 ,
V_202 ,
V_203
} ;
V_64 = & V_26 -> V_28 -> V_47 [ V_97 ] ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ ) {
V_61 = F_9 ( V_26 , V_15 ) ;
if ( ! V_61 )
continue;
V_193 = ( F_14 ( V_64 -> V_49 . V_50 ) *
( V_64 -> V_92 [ F_25 ( V_15 ) ] . V_67 -
V_64 -> V_76 . V_50 ) ) / V_204 ;
V_192 = 0 ;
F_58 ( V_192 , V_205 , V_61 -> type ) ;
F_58 ( V_192 , V_206 , V_193 ) ;
F_59 ( V_26 , V_194 [ V_15 ] , V_192 ) ;
V_193 = ( F_14 ( V_64 -> V_49 . V_50 ) *
( V_64 -> V_92 [ F_26 ( V_15 , V_99 ) ] . V_67 -
V_64 -> V_76 . V_50 ) ) / V_204 ;
V_192 = 0 ;
F_58 ( V_192 , V_205 , V_61 -> type ) ;
F_58 ( V_192 , V_206 , V_193 ) ;
F_59 ( V_26 , V_199 [ V_15 ] , V_192 ) ;
}
}
void F_61 ( struct V_25 * V_26 )
{
struct V_207 V_208 ;
struct V_209 * V_104 = & V_26 -> V_104 ;
struct V_27 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
F_7 ( V_26 , & V_7 ) ;
memset ( & V_208 , 0 , sizeof( V_208 ) ) ;
V_208 . V_210 = V_26 -> V_210 ;
V_208 . V_211 = V_26 -> V_103 ;
V_208 . V_212 = V_104 -> V_212 ;
V_208 . V_213 = V_26 -> V_214 ;
V_208 . V_215 = V_7 . V_33 ;
V_208 . V_216 = V_7 . V_31 ;
V_208 . V_217 = V_104 -> V_217 ;
V_208 . V_218 = V_104 -> V_105 - V_104 -> V_106 ;
V_208 . V_106 = V_104 -> V_106 ;
V_208 . V_219 = V_104 -> V_219 ;
V_208 . V_220 = V_104 -> V_220 ;
V_208 . V_221 = V_104 -> V_221 ;
V_208 . V_222 = V_104 -> V_222 ;
V_208 . V_223 = V_104 -> V_224 ;
V_208 . V_225 = V_104 -> V_226 ;
F_62 ( V_26 , V_26 -> V_227 , & V_208 ) ;
}
static int F_63 ( struct V_25 * V_26 )
{
union V_228 V_223 ;
T_4 V_229 ;
memset ( & V_223 , 0 , sizeof( V_223 ) ) ;
V_223 . V_230 . V_231 = V_232 ;
V_229 = F_64 ( V_26 , V_233 , & V_223 ) ;
F_59 ( V_26 , V_234 , V_229 ) ;
return 0 ;
}
static void F_65 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
T_1 V_235 = 0 , V_236 = 0 ;
V_235 += ( V_5 -> V_10 [ 0 ] . V_11 >> V_237 ) ;
F_59 ( V_26 , V_238 , V_235 ) ;
V_236 += ( V_5 -> V_10 [ 0 ] . V_13 >> V_237 ) ;
F_59 ( V_26 , V_239 , V_236 ) ;
V_235 += ( V_5 -> V_10 [ 1 ] . V_11 >> V_237 ) ;
F_59 ( V_26 , V_240 , V_235 ) ;
V_236 += ( V_5 -> V_10 [ 1 ] . V_13 >> V_237 ) ;
F_59 ( V_26 , V_241 , V_236 ) ;
V_235 += ( V_5 -> V_10 [ 2 ] . V_11 >> V_237 ) ;
F_59 ( V_26 , V_242 , V_235 ) ;
V_236 += ( V_5 -> V_10 [ 2 ] . V_13 >> V_237 ) ;
F_59 ( V_26 , V_243 , V_236 ) ;
V_235 += ( V_5 -> V_10 [ 3 ] . V_11 >> V_237 ) ;
F_59 ( V_26 , V_244 , V_235 ) ;
V_236 += ( V_5 -> V_10 [ 3 ] . V_13 >> V_237 ) ;
F_59 ( V_26 , V_245 , V_236 ) ;
V_235 += ( V_5 -> V_10 [ 4 ] . V_11 >> V_237 ) ;
F_59 ( V_26 , V_246 , V_235 ) ;
V_236 += ( V_5 -> V_10 [ 4 ] . V_13 >> V_237 ) ;
F_59 ( V_26 , V_247 , V_236 ) ;
V_235 += ( V_5 -> V_10 [ 5 ] . V_11 >> V_237 ) ;
F_59 ( V_26 , V_248 , V_235 ) ;
V_236 += ( V_5 -> V_10 [ 5 ] . V_13 >> V_237 ) ;
F_59 ( V_26 , V_249 , V_236 ) ;
F_59 ( V_26 , V_250 , V_235 ) ;
F_59 ( V_26 , V_251 , V_236 ) ;
F_59 ( V_26 , V_252 , V_235 ) ;
F_59 ( V_26 , V_253 , V_236 ) ;
}
static void F_66 ( struct V_25 * V_26 )
{
struct V_63 * V_73 ;
int V_15 ;
V_73 = V_26 -> V_28 -> V_47 ;
F_42 (i, ilt_clients) {
F_59 ( V_26 ,
V_73 [ V_15 ] . V_76 . V_162 ,
V_73 [ V_15 ] . V_76 . V_50 ) ;
F_59 ( V_26 ,
V_73 [ V_15 ] . V_77 . V_162 , V_73 [ V_15 ] . V_77 . V_50 ) ;
F_59 ( V_26 ,
V_73 [ V_15 ] . V_49 . V_162 ,
V_73 [ V_15 ] . V_49 . V_50 ) ;
}
}
static void F_67 ( struct V_25 * V_26 )
{
struct V_63 * V_64 ;
T_1 V_254 ;
if ( V_26 -> V_121 -> V_174 ) {
struct V_255 * V_256 = V_26 -> V_121 -> V_174 ;
F_59 ( V_26 ,
V_257 ,
V_256 -> V_258 ) ;
F_59 ( V_26 ,
V_259 ,
V_256 -> V_258 + V_256 -> V_175 ) ;
}
V_64 = & V_26 -> V_28 -> V_47 [ V_48 ] ;
V_254 = F_68 ( F_14 ( V_64 -> V_49 . V_50 ) >> 10 ) ;
if ( V_64 -> V_75 ) {
F_59 ( V_26 ,
V_260 ,
V_254 ) ;
F_59 ( V_26 ,
V_261 ,
V_64 -> V_91 ) ;
F_59 ( V_26 ,
V_262 ,
V_64 -> V_96 ) ;
}
V_64 = & V_26 -> V_28 -> V_47 [ V_97 ] ;
V_254 = F_68 ( F_14 ( V_64 -> V_49 . V_50 ) >> 10 ) ;
if ( V_64 -> V_75 ) {
F_59 ( V_26 ,
V_263 ,
V_254 ) ;
F_59 ( V_26 ,
V_264 ,
V_64 -> V_91 ) ;
F_59 ( V_26 ,
V_265 ,
V_64 -> V_96 ) ;
}
V_64 = & V_26 -> V_28 -> V_47 [ V_112 ] ;
V_254 = F_68 ( F_14 ( V_64 -> V_49 . V_50 ) >> 10 ) ;
if ( V_64 -> V_75 ) {
F_59 ( V_26 ,
V_266 , V_254 ) ;
F_59 ( V_26 ,
V_267 ,
V_64 -> V_91 ) ;
F_59 ( V_26 ,
V_268 ,
V_64 -> V_96 ) ;
}
}
static void F_69 ( struct V_25 * V_26 )
{
struct V_63 * V_47 ;
struct V_4 * V_5 ;
struct V_130 * V_269 ;
T_1 line , V_270 , V_15 ;
F_66 ( V_26 ) ;
F_67 ( V_26 ) ;
V_5 = V_26 -> V_28 ;
V_269 = V_5 -> V_143 ;
V_47 = V_26 -> V_28 -> V_47 ;
F_42 (i, clients) {
line = V_47 [ V_15 ] . V_76 . V_50 - V_5 -> V_88 ;
V_270 = V_271 +
V_47 [ V_15 ] . V_76 . V_50 * V_272 ;
for (; line <= V_47 [ V_15 ] . V_77 . V_50 - V_5 -> V_88 ;
line ++ , V_270 += V_272 ) {
V_137 V_273 = 0 ;
if ( V_269 [ line ] . V_120 ) {
F_58 ( V_273 , V_274 , 1ULL ) ;
F_58 ( V_273 , V_275 ,
( V_269 [ line ] . V_125 >> 12 ) ) ;
F_8 ( V_26 , V_38 ,
L_15 ,
V_270 , line , V_15 ,
( V_137 ) ( V_269 [ line ] . V_125 >> 12 ) ) ;
}
F_70 ( V_26 , V_270 , V_273 ) ;
}
}
}
static void F_71 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
T_1 V_276 , V_126 , V_277 ;
struct V_14 V_85 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
F_4 ( V_5 , & V_85 ) ;
V_126 = V_85 . V_9 + V_85 . V_12 * V_5 -> V_37 ;
if ( ! V_126 )
return;
V_277 = F_28 ( T_1 , V_126 , V_110 ) ;
V_276 = F_29 ( V_277 ) ;
F_59 ( V_26 , V_278 , V_126 ) ;
F_59 ( V_26 , V_279 ,
F_68 ( V_276 ) ) ;
F_70 ( V_26 , V_280 ,
V_26 -> V_28 -> V_136 ) ;
F_70 ( V_26 , V_281 ,
V_26 -> V_28 -> V_138 ) ;
}
static void F_72 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
T_1 V_282 = 0 , V_283 , V_284 ;
struct V_16 V_87 ;
V_137 V_285 ;
T_2 V_15 ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
F_5 ( V_5 , & V_87 ) ;
for ( V_15 = 0 ; V_15 < V_5 -> V_37 ; V_15 ++ ) {
V_285 = 0 ;
F_58 ( V_285 , V_286 , V_87 . V_12 ) ;
F_58 ( V_285 , V_287 , 0 ) ;
F_58 ( V_285 , V_288 , V_26 -> V_103 ) ;
F_58 ( V_285 , V_289 , 0 ) ;
V_284 = V_290 +
( sizeof( V_285 ) / sizeof( T_1 ) ) *
( V_26 -> V_121 -> V_174 -> V_258 + V_15 ) ;
F_70 ( V_26 , V_284 , V_285 ) ;
}
V_285 = 0 ;
F_58 ( V_285 , V_286 , V_87 . V_9 ) ;
F_58 ( V_285 , V_287 , 0 ) ;
F_58 ( V_285 , V_288 , 0 ) ;
F_58 ( V_285 , V_289 , 0 ) ;
V_284 = V_290 +
( sizeof( V_285 ) / sizeof( T_1 ) ) *
( F_73 ( V_26 -> V_121 ) + V_26 -> V_103 ) ;
F_70 ( V_26 , V_284 , V_285 ) ;
F_59 ( V_26 , V_291 ,
V_87 . V_9 ? 0x1 : 0x0 ) ;
V_283 = V_87 . V_12 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_37 ; V_15 ++ ) {
V_285 = 0 ;
F_58 ( V_285 , V_286 , V_87 . V_21 ) ;
F_58 ( V_285 , V_287 , 0 ) ;
F_58 ( V_285 , V_288 , V_26 -> V_103 ) ;
F_58 ( V_285 , V_292 , V_283 ) ;
F_58 ( V_285 , V_293 , ( V_137 ) 0 ) ;
V_284 = V_294 +
( sizeof( V_285 ) / sizeof( T_1 ) ) *
( V_26 -> V_121 -> V_174 -> V_258 + V_15 ) ;
F_70 ( V_26 , V_284 , V_285 ) ;
}
V_283 = V_87 . V_9 ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ ) {
V_285 = 0 ;
F_58 ( V_285 , V_286 , V_87 . V_24 [ V_15 ] ) ;
F_58 ( V_285 , V_287 , 0 ) ;
F_58 ( V_285 , V_288 , 0 ) ;
F_58 ( V_285 , V_292 , V_283 ) ;
F_58 ( V_285 , V_293 , ( V_137 ) 0 ) ;
V_284 = V_294 +
( sizeof( V_285 ) / sizeof( T_1 ) ) *
( F_73 ( V_26 -> V_121 ) +
V_26 -> V_103 * V_23 + V_15 ) ;
F_70 ( V_26 , V_284 , V_285 ) ;
V_282 |= ( V_87 . V_24 [ V_15 ] ? ( 1 << V_15 ) : 0 ) ;
V_283 += V_87 . V_24 [ V_15 ] ;
}
if ( V_26 -> V_148 . V_149 == V_150 )
V_282 = 0 ;
F_59 ( V_26 , V_295 , V_282 ) ;
}
void F_74 ( struct V_25 * V_26 )
{
F_57 ( V_26 ) ;
}
void F_75 ( struct V_25 * V_26 )
{
F_61 ( V_26 ) ;
F_63 ( V_26 ) ;
F_65 ( V_26 ) ;
F_60 ( V_26 ) ;
F_69 ( V_26 ) ;
F_71 ( V_26 ) ;
F_72 ( V_26 ) ;
}
int F_76 ( struct V_25 * V_26 ,
enum V_1 type ,
T_1 * V_296 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
T_1 V_297 ;
if ( type >= V_8 || ! V_5 -> V_54 [ type ] . V_155 ) {
F_37 ( V_26 , L_16 , type ) ;
return - V_117 ;
}
V_297 = F_77 ( V_5 -> V_54 [ type ] . V_155 ,
V_5 -> V_54 [ type ] . V_156 ) ;
if ( V_297 >= V_5 -> V_54 [ type ] . V_156 ) {
F_37 ( V_26 , L_17 ,
type ) ;
return - V_117 ;
}
F_78 ( V_297 , V_5 -> V_54 [ type ] . V_155 ) ;
* V_296 = V_297 + V_5 -> V_54 [ type ] . V_55 ;
return 0 ;
}
static bool F_79 ( struct V_25 * V_26 ,
T_1 V_298 ,
enum V_1 * V_299 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
struct V_300 * V_301 ;
enum V_1 V_302 ;
T_1 V_297 ;
for ( V_302 = 0 ; V_302 < V_8 ; V_302 ++ ) {
V_301 = & V_5 -> V_54 [ V_302 ] ;
if ( ! V_301 -> V_155 )
continue;
if ( V_298 >= V_301 -> V_55 &&
V_298 < V_301 -> V_55 + V_301 -> V_156 )
break;
}
* V_299 = V_302 ;
if ( V_302 == V_8 ) {
F_37 ( V_26 , L_18 , V_298 ) ;
return false ;
}
V_297 = V_298 - V_301 -> V_55 ;
if ( ! F_80 ( V_297 , V_301 -> V_155 ) ) {
F_37 ( V_26 , L_19 , V_298 ) ;
return false ;
}
return true ;
}
void F_81 ( struct V_25 * V_26 ,
T_1 V_298 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
enum V_1 type ;
bool V_303 ;
T_1 V_297 ;
V_303 = F_79 ( V_26 , V_298 , & type ) ;
if ( ! V_303 )
return;
V_297 = V_298 - V_5 -> V_54 [ type ] . V_55 ;
F_82 ( V_297 , V_5 -> V_54 [ type ] . V_155 ) ;
}
int F_83 ( struct V_25 * V_26 ,
struct V_304 * V_305 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
T_1 V_306 , V_307 , V_80 , line ;
enum V_1 type ;
bool V_303 ;
V_303 = F_79 ( V_26 , V_305 -> V_308 , & type ) ;
if ( ! V_303 )
return - V_117 ;
V_305 -> type = type ;
V_307 = V_26 -> V_28 -> V_47 [ V_48 ] . V_49 . V_50 ;
V_306 = F_13 ( V_26 ) ;
V_80 = F_14 ( V_307 ) / V_306 ;
line = V_305 -> V_308 / V_80 ;
if ( ! V_5 -> V_143 [ line ] . V_120 )
return - V_117 ;
V_305 -> V_309 = V_5 -> V_143 [ line ] . V_120 +
V_305 -> V_308 % V_80 * V_306 ;
F_8 ( V_26 , ( V_38 | V_161 ) ,
L_20 ,
V_305 -> V_308 / V_80 , V_305 -> V_309 , V_305 -> V_308 ) ;
return 0 ;
}
void F_84 ( struct V_25 * V_26 ,
struct V_310 * V_311 )
{
T_1 V_312 , V_313 , V_314 , V_315 , V_40 ;
enum V_1 V_58 ;
V_315 = F_38 ( T_1 , V_316 , V_311 -> V_315 ) ;
V_313 = V_315 ;
V_40 = F_38 ( T_1 , 32 * 1024 , V_311 -> V_40 ) ;
switch ( V_26 -> V_148 . V_149 ) {
case V_150 :
V_314 = F_38 ( T_1 , V_317 , V_311 -> V_314 ) ;
V_312 = V_314 * 2 ;
V_58 = V_3 ;
break;
default:
return;
}
if ( V_312 && V_313 ) {
F_12 ( V_26 , V_58 , V_312 , 0 ) ;
F_18 ( V_26 , V_3 ,
V_318 , 1 ,
V_313 , false ) ;
F_10 ( V_26 , V_40 ) ;
} else {
F_85 ( V_26 -> V_121 ,
L_21 ) ;
}
}
int F_86 ( struct V_25 * V_26 )
{
T_1 V_319 = 1 ;
F_12 ( V_26 , V_233 , V_319 , 0 ) ;
switch ( V_26 -> V_148 . V_149 ) {
case V_150 :
{
F_84 ( V_26 ,
& V_26 ->
V_320 . V_321 ) ;
}
case V_322 :
{
struct V_323 * V_311 =
& V_26 -> V_320 . V_324 ;
F_12 ( V_26 , V_325 ,
V_311 -> V_312 , 1 ) ;
break;
}
case V_326 :
{
struct V_327 * V_311 ;
V_311 = & V_26 -> V_320 . V_328 ;
if ( V_311 -> V_312 && V_311 -> V_313 ) {
F_12 ( V_26 ,
V_2 ,
V_311 -> V_312 ,
0 ) ;
F_18 ( V_26 ,
V_2 ,
V_329 ,
0 ,
V_311 -> V_313 ,
true ) ;
} else {
F_85 ( V_26 -> V_121 ,
L_22 ) ;
}
break;
}
default:
return - V_117 ;
}
return 0 ;
}
int F_87 ( struct V_25 * V_26 ,
struct V_330 * V_305 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
T_1 V_58 , V_39 , V_331 , V_15 , V_332 ;
struct V_63 * V_64 ;
struct V_65 * V_333 ;
struct V_29 * V_334 ;
switch ( V_26 -> V_148 . V_149 ) {
case V_326 :
V_58 = V_2 ;
V_39 = V_329 ;
break;
default:
return - V_117 ;
}
V_64 = & V_5 -> V_47 [ V_97 ] ;
if ( ! V_64 -> V_75 )
return - V_117 ;
V_334 = & V_5 -> V_10 [ V_58 ] . V_34 [ V_39 ] ;
if ( ! V_334 -> V_62 )
return - V_117 ;
V_333 = & V_64 -> V_92 [ F_26 ( V_39 , V_99 ) ] ;
V_331 = F_21 ( V_333 -> V_68 ,
V_333 -> V_71 ) ;
for ( V_15 = 0 ; V_15 < V_331 ; V_15 ++ ) {
V_332 = V_15 + V_333 -> V_67 -
V_26 -> V_28 -> V_88 ;
V_305 -> V_335 [ V_15 ] = V_5 -> V_143 [ V_332 ] . V_120 ;
}
V_305 -> V_336 = F_14 ( V_64 -> V_49 . V_50 ) -
V_333 -> V_71 ;
V_305 -> V_337 = V_5 -> V_98 [ V_334 -> type ] ;
V_305 -> V_338 = V_333 -> V_71 /
V_305 -> V_337 ;
return 0 ;
}
int
F_88 ( struct V_25 * V_26 ,
enum V_339 V_340 , T_1 V_308 )
{
T_1 V_341 , V_332 , V_69 , V_307 , V_342 , line ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_343 * V_344 ;
T_3 V_125 ;
V_137 V_273 ;
void * V_120 ;
int V_132 = 0 ;
switch ( V_340 ) {
case V_345 :
V_64 = & V_26 -> V_28 -> V_47 [ V_48 ] ;
V_69 = F_13 ( V_26 ) ;
V_66 = & V_64 -> V_92 [ V_93 ] ;
break;
case V_346 :
V_64 = & V_26 -> V_28 -> V_47 [ V_114 ] ;
V_69 = V_116 ;
V_66 = & V_64 -> V_92 [ V_115 ] ;
break;
case V_347 :
V_64 = & V_26 -> V_28 -> V_47 [ V_97 ] ;
V_69 = F_52 ( V_26 ) ;
V_66 = & V_64 -> V_92 [ F_25 ( V_318 ) ] ;
break;
default:
F_37 ( V_26 , L_23 , V_340 ) ;
return - V_117 ;
}
V_307 = V_64 -> V_49 . V_50 ;
V_342 = F_14 ( V_307 ) / V_69 ;
line = V_66 -> V_67 + ( V_308 / V_342 ) ;
V_332 = line - V_26 -> V_28 -> V_88 ;
F_89 ( & V_26 -> V_28 -> V_176 ) ;
if ( V_26 -> V_28 -> V_143 [ V_332 ] . V_120 )
goto V_348;
V_344 = F_90 ( V_26 ) ;
if ( ! V_344 ) {
F_37 ( V_26 ,
L_24 ) ;
V_132 = - V_349 ;
goto V_348;
}
V_120 = F_39 ( & V_26 -> V_121 -> V_122 -> V_123 ,
V_66 -> V_71 ,
& V_125 , V_133 ) ;
if ( ! V_120 ) {
V_132 = - V_134 ;
goto V_350;
}
memset ( V_120 , 0 , V_66 -> V_71 ) ;
if ( V_340 == V_347 ) {
T_1 V_351 ;
T_2 * V_352 = ( T_2 * ) V_120 ;
union V_353 * V_354 ;
for ( V_351 = 0 ; V_351 < V_342 ; V_351 ++ ) {
V_354 = (union V_353 * ) V_352 ;
F_58 ( V_354 -> V_355 . V_356 . V_357 ,
V_358 , 0xf ) ;
V_352 += F_52 ( V_26 ) ;
}
}
V_26 -> V_28 -> V_143 [ V_332 ] . V_120 = V_120 ;
V_26 -> V_28 -> V_143 [ V_332 ] . V_125 = V_125 ;
V_26 -> V_28 -> V_143 [ V_332 ] . V_124 =
V_66 -> V_71 ;
V_341 = V_359 +
( line * V_360 * V_272 ) ;
V_273 = 0 ;
F_58 ( V_273 , V_274 , 1ULL ) ;
F_58 ( V_273 ,
V_275 ,
( V_26 -> V_28 -> V_143 [ V_332 ] . V_125 >> 12 ) ) ;
F_91 ( V_26 , V_344 , ( V_137 ) ( V_361 ) & V_273 ,
V_341 , sizeof( V_273 ) / sizeof( T_1 ) , 0 ) ;
if ( V_340 == V_345 ) {
T_1 V_362 = ( 1 + ( V_308 / V_342 ) ) *
V_342 ;
F_92 ( V_26 , V_344 , V_363 ,
V_362 - 1 ) ;
if ( ! V_26 -> V_364 ) {
F_92 ( V_26 , V_344 , V_26 -> V_365 , 1 ) ;
V_26 -> V_364 = true ;
}
}
V_350:
F_93 ( V_26 , V_344 ) ;
V_348:
F_94 ( & V_26 -> V_28 -> V_176 ) ;
return V_132 ;
}
static int
F_95 ( struct V_25 * V_26 ,
enum V_339 V_340 ,
T_1 V_366 , T_1 V_36 )
{
T_1 V_67 , V_367 , V_368 , V_369 ;
T_1 V_341 , V_69 , V_307 , V_342 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
T_1 V_370 = V_366 + V_36 ;
struct V_343 * V_344 ;
V_137 V_273 = 0 ;
T_1 V_15 ;
switch ( V_340 ) {
case V_345 :
V_64 = & V_26 -> V_28 -> V_47 [ V_48 ] ;
V_69 = F_13 ( V_26 ) ;
V_66 = & V_64 -> V_92 [ V_93 ] ;
break;
case V_346 :
V_64 = & V_26 -> V_28 -> V_47 [ V_114 ] ;
V_69 = V_116 ;
V_66 = & V_64 -> V_92 [ V_115 ] ;
break;
case V_347 :
V_64 = & V_26 -> V_28 -> V_47 [ V_97 ] ;
V_69 = F_52 ( V_26 ) ;
V_66 = & V_64 -> V_92 [ F_25 ( V_318 ) ] ;
break;
default:
F_37 ( V_26 , L_23 , V_340 ) ;
return - V_117 ;
}
V_307 = V_64 -> V_49 . V_50 ;
V_342 = F_14 ( V_307 ) / V_69 ;
V_67 = V_66 -> V_67 + ( V_366 / V_342 ) ;
V_367 = V_66 -> V_67 + ( V_370 / V_342 ) ;
if ( ( ( V_370 + 1 ) / V_342 ) != ( V_370 / V_342 ) )
V_367 -- ;
V_368 = V_67 - V_26 -> V_28 -> V_88 ;
V_369 = V_367 - V_26 -> V_28 -> V_88 ;
V_344 = F_90 ( V_26 ) ;
if ( ! V_344 ) {
F_37 ( V_26 ,
L_24 ) ;
return - V_349 ;
}
for ( V_15 = V_368 ; V_15 < V_369 ; V_15 ++ ) {
if ( ! V_26 -> V_28 -> V_143 [ V_15 ] . V_120 )
continue;
F_33 ( & V_26 -> V_121 -> V_122 -> V_123 ,
V_26 -> V_28 -> V_143 [ V_15 ] . V_124 ,
V_26 -> V_28 -> V_143 [ V_15 ] . V_120 ,
V_26 -> V_28 -> V_143 [ V_15 ] . V_125 ) ;
V_26 -> V_28 -> V_143 [ V_15 ] . V_120 = NULL ;
V_26 -> V_28 -> V_143 [ V_15 ] . V_125 = 0 ;
V_26 -> V_28 -> V_143 [ V_15 ] . V_124 = 0 ;
V_341 = V_359 +
( ( V_67 ++ ) * V_360 *
V_272 ) ;
F_91 ( V_26 , V_344 ,
( V_137 ) ( V_361 ) & V_273 ,
V_341 ,
sizeof( V_273 ) / sizeof( T_1 ) ,
0 ) ;
}
F_93 ( V_26 , V_344 ) ;
return 0 ;
}
int F_96 ( struct V_25 * V_26 , enum V_1 V_58 )
{
int V_132 ;
T_1 V_298 ;
V_132 = F_95 ( V_26 , V_345 ,
F_16 ( V_26 ,
V_58 ) ,
F_15 ( V_26 ,
V_58 , & V_298 ) ) ;
if ( V_132 )
return V_132 ;
V_132 = F_95 ( V_26 , V_347 , 0 ,
F_17 ( V_26 , V_58 ) ) ;
if ( V_132 )
return V_132 ;
V_132 = F_95 ( V_26 , V_346 , 0 ,
F_11 ( V_26 ) ) ;
return V_132 ;
}
int F_97 ( struct V_25 * V_26 ,
T_1 V_371 , T_2 V_372 , void * * V_373 )
{
struct V_4 * V_5 = V_26 -> V_28 ;
struct V_63 * V_64 ;
struct V_65 * V_61 ;
struct V_29 * V_334 ;
T_1 V_58 , V_39 ;
T_1 V_331 ;
T_1 V_337 , V_374 ;
T_1 V_338 ;
switch ( V_26 -> V_148 . V_149 ) {
case V_326 :
V_58 = V_2 ;
V_39 = V_329 ;
break;
default:
return - V_117 ;
}
V_64 = & V_5 -> V_47 [ V_97 ] ;
if ( ! V_64 -> V_75 )
return - V_117 ;
V_334 = & V_5 -> V_10 [ V_58 ] . V_34 [ V_39 ] ;
if ( V_372 == V_375 ) {
V_61 = & V_64 -> V_92 [ F_25 ( V_39 ) ] ;
} else if ( V_372 == V_376 ) {
if ( ! V_334 -> V_62 )
return - V_117 ;
V_61 = & V_64 -> V_92 [ F_26 ( V_39 , V_99 ) ] ;
} else {
return - V_117 ;
}
V_331 = F_21 ( V_61 -> V_68 , V_61 -> V_71 ) ;
V_337 = V_5 -> V_98 [ V_334 -> type ] ;
V_338 = V_61 -> V_71 / V_337 ;
if ( V_331 < V_371 / V_338 )
return - V_117 ;
V_374 = V_371 / V_338 + V_61 -> V_67 -
V_5 -> V_88 ;
* V_373 = ( T_2 * ) V_5 -> V_143 [ V_374 ] . V_120 +
( V_371 % V_338 ) * V_337 ;
return 0 ;
}
