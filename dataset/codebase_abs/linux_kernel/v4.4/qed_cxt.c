static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 type , V_3 = 0 ;
for ( type = 0 ; type < V_4 ; type ++ )
V_3 += V_2 -> V_5 [ type ] . V_6 ;
return V_3 ;
}
static void F_2 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int type ;
for ( type = 0 ; type < V_4 ; type ++ )
V_10 -> V_12 += V_2 -> V_5 [ type ] . V_6 ;
F_3 ( V_8 , V_13 , L_1 , V_10 -> V_12 ) ;
}
static void F_4 ( struct V_7 * V_8 ,
enum V_14 type ,
T_1 V_6 )
{
struct V_1 * V_15 = V_8 -> V_11 ;
struct V_16 * V_17 = & V_15 -> V_5 [ type ] ;
V_17 -> V_6 = F_5 ( V_6 , V_18 ) ;
}
static void F_6 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
T_1 V_23 , T_1 V_24 ,
T_1 V_25 )
{
T_1 V_26 = F_7 ( V_20 -> V_27 . V_28 ) ;
if ( V_22 -> V_24 )
return;
V_22 -> V_24 = V_24 ;
V_22 -> V_29 = 0 ;
if ( V_25 )
V_22 -> V_29 = ( V_26 / V_25 ) * V_25 ;
V_22 -> V_23 = V_23 ;
}
static void F_8 ( struct V_7 * V_8 ,
struct V_19 * V_20 ,
struct V_21 * V_22 ,
T_1 * V_30 , enum V_31 V_32 )
{
if ( ! V_22 -> V_24 )
return;
if ( ! V_20 -> V_33 )
V_20 -> V_34 . V_28 = * V_30 ;
V_20 -> V_33 = true ;
* V_30 += F_9 ( V_22 -> V_24 ,
V_22 -> V_29 ) ;
V_20 -> V_35 . V_28 = * V_30 - 1 ;
F_3 ( V_8 , V_13 ,
L_2 ,
V_32 , V_20 -> V_34 . V_28 ,
V_20 -> V_35 . V_28 , V_22 -> V_24 ,
V_22 -> V_29 , V_22 -> V_23 ) ;
}
int F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
T_1 V_36 , V_37 , V_3 ;
struct V_9 V_38 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_2 -> V_39 = F_11 ( V_8 , V_40 ) ;
F_3 ( V_8 , V_13 ,
L_3 ,
V_8 -> V_41 , V_8 -> V_11 -> V_39 ) ;
V_20 = & V_2 -> V_42 [ V_43 ] ;
V_36 = V_2 -> V_39 ;
V_20 -> V_44 = 0 ;
V_3 = F_1 ( V_2 ) ;
V_22 = & V_20 -> V_45 [ V_46 ] ;
V_37 = V_3 * F_12 ( V_8 ) ;
F_6 ( V_20 , V_22 , V_36 ,
V_37 , F_12 ( V_8 ) ) ;
F_8 ( V_8 , V_20 , V_22 , & V_36 , V_43 ) ;
V_20 -> V_44 = V_36 - V_22 -> V_23 ;
V_20 = & V_2 -> V_42 [ V_47 ] ;
V_22 = & V_20 -> V_45 [ 0 ] ;
F_2 ( V_8 , & V_38 ) ;
V_37 = F_13 ( V_8 -> V_48 , V_38 . V_12 , 0 , 0 ,
V_8 -> V_49 . V_50 , 0 ) ;
F_3 ( V_8 , V_13 ,
L_4 ,
V_38 . V_12 , V_8 -> V_49 . V_50 , V_37 ) ;
F_6 ( V_20 , V_22 ,
V_36 , V_37 * 0x1000 ,
V_51 ) ;
F_8 ( V_8 , V_20 , V_22 , & V_36 , V_47 ) ;
V_20 -> V_44 = V_36 - V_22 -> V_23 ;
if ( V_36 - V_8 -> V_11 -> V_39 >
F_14 ( V_8 , V_40 ) ) {
F_15 ( V_8 , L_5 ,
V_36 - V_8 -> V_11 -> V_39 ) ;
return - V_52 ;
}
return 0 ;
}
static T_1 F_16 ( struct V_19 * V_31 )
{
T_1 V_53 = 0 ;
T_1 V_54 ;
F_17 (i, ilt_clients) {
if ( ! V_31 [ V_54 ] . V_33 )
continue;
V_53 += ( V_31 [ V_54 ] . V_35 . V_28 -
V_31 [ V_54 ] . V_34 . V_28 + 1 ) ;
}
return V_53 ;
}
static void F_18 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = V_8 -> V_11 -> V_42 ;
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_26 , V_54 ;
V_26 = F_16 ( V_20 ) ;
for ( V_54 = 0 ; V_2 -> V_55 && V_54 < V_26 ; V_54 ++ ) {
struct V_56 * V_57 = & V_2 -> V_55 [ V_54 ] ;
if ( V_57 -> V_58 )
F_19 ( & V_8 -> V_59 -> V_60 -> V_61 ,
V_57 -> V_53 , V_57 -> V_58 ,
V_57 -> V_62 ) ;
V_57 -> V_58 = NULL ;
}
F_20 ( V_2 -> V_55 ) ;
}
static int F_21 ( struct V_7 * V_8 ,
struct V_21 * V_22 ,
enum V_31 V_63 ,
T_1 V_64 )
{
struct V_56 * V_55 = V_8 -> V_11 -> V_55 ;
T_1 V_65 , line , V_66 ;
if ( ! V_22 -> V_24 )
return 0 ;
V_66 = V_22 -> V_24 ;
V_65 = F_9 ( V_66 , V_22 -> V_29 ) ;
line = V_22 -> V_23 + V_64 -
V_8 -> V_11 -> V_39 ;
for (; V_65 ; V_65 -- ) {
T_2 V_62 ;
void * V_58 ;
T_1 V_53 ;
V_53 = F_22 ( T_1 , V_66 ,
V_22 -> V_29 ) ;
V_58 = F_23 ( & V_8 -> V_59 -> V_60 -> V_61 ,
V_53 ,
& V_62 ,
V_67 ) ;
if ( ! V_58 )
return - V_68 ;
memset ( V_58 , 0 , V_53 ) ;
V_55 [ line ] . V_62 = V_62 ;
V_55 [ line ] . V_58 = V_58 ;
V_55 [ line ] . V_53 = V_53 ;
F_3 ( V_8 , V_13 ,
L_6 ,
line , ( V_69 ) V_62 , V_58 , V_53 ) ;
V_66 -= V_53 ;
line ++ ;
}
return 0 ;
}
static int F_24 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
struct V_19 * V_42 = V_2 -> V_42 ;
struct V_21 * V_22 ;
T_1 V_53 , V_54 , V_70 ;
int V_71 ;
V_53 = F_16 ( V_42 ) ;
V_2 -> V_55 = F_25 ( V_53 , sizeof( struct V_56 ) ,
V_67 ) ;
if ( ! V_2 -> V_55 ) {
F_26 ( V_8 , L_7 ) ;
V_71 = - V_68 ;
goto V_72;
}
F_3 ( V_8 , V_13 ,
L_8 ,
( T_1 ) ( V_53 * sizeof( struct V_56 ) ) ) ;
F_17 (i, clients) {
if ( ! V_42 [ V_54 ] . V_33 )
continue;
for ( V_70 = 0 ; V_70 < V_73 ; V_70 ++ ) {
V_22 = & V_42 [ V_54 ] . V_45 [ V_70 ] ;
V_71 = F_21 ( V_8 , V_22 , V_54 , 0 ) ;
if ( V_71 != 0 )
goto V_72;
}
}
return 0 ;
V_72:
F_18 ( V_8 ) ;
return V_71 ;
}
static void F_27 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 type ;
for ( type = 0 ; type < V_4 ; type ++ ) {
F_20 ( V_2 -> V_74 [ type ] . V_75 ) ;
V_2 -> V_74 [ type ] . V_76 = 0 ;
V_2 -> V_74 [ type ] . V_77 = 0 ;
}
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_77 = 0 ;
T_1 type ;
for ( type = 0 ; type < V_4 ; type ++ ) {
T_1 V_78 = V_8 -> V_11 -> V_5 [ type ] . V_6 ;
T_1 V_53 ;
if ( V_78 == 0 )
continue;
V_53 = F_9 ( V_78 ,
sizeof( unsigned long ) * V_79 ) *
sizeof( unsigned long ) ;
V_2 -> V_74 [ type ] . V_75 = F_29 ( V_53 , V_67 ) ;
if ( ! V_2 -> V_74 [ type ] . V_75 )
goto V_80;
V_2 -> V_74 [ type ] . V_76 = V_78 ;
V_2 -> V_74 [ type ] . V_77 = V_77 ;
V_8 -> V_11 -> V_5 [ type ] . V_81 = V_77 ;
F_3 ( V_8 , V_82 ,
L_9 ,
type , V_2 -> V_74 [ type ] . V_77 ,
V_2 -> V_74 [ type ] . V_76 ) ;
V_77 += V_78 ;
}
return 0 ;
V_80:
F_27 ( V_8 ) ;
return - V_68 ;
}
int F_30 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
T_1 V_54 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_83 ) ;
if ( ! V_2 ) {
F_26 ( V_8 , L_10 ) ;
return - V_68 ;
}
V_2 -> V_42 [ V_43 ] . V_34 . V_84 = F_31 ( V_85 , V_86 ) ;
V_2 -> V_42 [ V_43 ] . V_35 . V_84 = F_31 ( V_85 , V_87 ) ;
V_2 -> V_42 [ V_43 ] . V_27 . V_84 = F_31 ( V_85 , V_88 ) ;
V_2 -> V_42 [ V_47 ] . V_34 . V_84 = F_31 ( V_89 , V_86 ) ;
V_2 -> V_42 [ V_47 ] . V_35 . V_84 = F_31 ( V_89 , V_87 ) ;
V_2 -> V_42 [ V_47 ] . V_27 . V_84 = F_31 ( V_89 , V_88 ) ;
for ( V_54 = 0 ; V_54 < V_90 ; V_54 ++ )
V_2 -> V_42 [ V_54 ] . V_27 . V_28 = V_91 ;
V_8 -> V_11 = V_2 ;
return 0 ;
}
int F_32 ( struct V_7 * V_8 )
{
int V_71 ;
V_71 = F_24 ( V_8 ) ;
if ( V_71 ) {
F_26 ( V_8 , L_11 ) ;
goto V_92;
}
V_71 = F_28 ( V_8 ) ;
if ( V_71 ) {
F_26 ( V_8 , L_12 ) ;
goto V_92;
}
return 0 ;
V_92:
F_33 ( V_8 ) ;
return V_71 ;
}
void F_33 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_11 )
return;
F_27 ( V_8 ) ;
F_18 ( V_8 ) ;
F_20 ( V_8 -> V_11 ) ;
V_8 -> V_11 = NULL ;
}
void F_34 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int type ;
for ( type = 0 ; type < V_4 ; type ++ ) {
T_1 V_78 = V_8 -> V_11 -> V_5 [ type ] . V_6 ;
if ( V_78 == 0 )
continue;
memset ( V_2 -> V_74 [ type ] . V_75 , 0 ,
F_9 ( V_78 ,
sizeof( unsigned long ) * V_79 ) *
sizeof( unsigned long ) ) ;
}
}
static void F_35 ( struct V_7 * V_8 )
{
T_1 V_93 , V_94 , V_95 , V_96 , V_97 = 0 ;
V_93 = V_8 -> V_11 -> V_42 [ V_43 ] . V_27 . V_28 ;
V_96 = F_12 ( V_8 ) ;
V_94 = F_7 ( V_93 ) / V_96 ;
V_95 = F_7 ( V_93 ) - V_94 * V_96 ;
F_36 ( V_97 , V_98 , V_96 ) ;
F_36 ( V_97 , V_99 , V_95 ) ;
F_36 ( V_97 , V_100 , V_94 ) ;
F_37 ( V_8 , V_101 , V_97 ) ;
}
void F_38 ( struct V_7 * V_8 )
{
struct V_102 V_103 ;
struct V_104 * V_49 = & V_8 -> V_49 ;
struct V_9 V_10 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
F_2 ( V_8 , & V_10 ) ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_105 = V_8 -> V_105 ;
V_103 . V_106 = V_8 -> V_48 ;
V_103 . V_107 = V_49 -> V_107 ;
V_103 . V_108 = V_8 -> V_109 ;
V_103 . V_110 = V_10 . V_12 ;
V_103 . V_111 = V_49 -> V_111 ;
V_103 . V_112 = V_49 -> V_50 ;
V_103 . V_113 = V_49 -> V_114 ;
V_103 . V_115 = V_49 -> V_115 ;
V_103 . V_116 = V_49 -> V_116 ;
V_103 . V_117 = V_49 -> V_118 ;
V_103 . V_119 = V_49 -> V_120 ;
F_39 ( V_8 , V_8 -> V_121 , & V_103 ) ;
}
static int F_40 ( struct V_7 * V_8 )
{
union V_122 V_117 ;
T_3 V_123 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_124 . V_125 = V_126 ;
V_123 = F_41 ( V_8 , V_127 , & V_117 ) ;
F_37 ( V_8 , V_128 , V_123 ) ;
return 0 ;
}
static void F_42 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_129 = 0 ;
V_129 += ( V_2 -> V_5 [ 0 ] . V_6 >> V_130 ) ;
F_37 ( V_8 , V_131 , V_129 ) ;
V_129 += ( V_2 -> V_5 [ 1 ] . V_6 >> V_130 ) ;
F_37 ( V_8 , V_132 , V_129 ) ;
V_129 += ( V_2 -> V_5 [ 2 ] . V_6 >> V_130 ) ;
F_37 ( V_8 , V_133 , V_129 ) ;
V_129 += ( V_2 -> V_5 [ 3 ] . V_6 >> V_130 ) ;
F_37 ( V_8 , V_134 , V_129 ) ;
V_129 += ( V_2 -> V_5 [ 4 ] . V_6 >> V_130 ) ;
F_37 ( V_8 , V_135 , V_129 ) ;
V_129 += ( V_2 -> V_5 [ 5 ] . V_6 >> V_130 ) ;
F_37 ( V_8 , V_136 , V_129 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
struct V_19 * V_31 ;
int V_54 ;
V_31 = V_8 -> V_11 -> V_42 ;
F_17 (i, ilt_clients) {
if ( ! V_31 [ V_54 ] . V_33 )
continue;
F_37 ( V_8 ,
V_31 [ V_54 ] . V_34 . V_84 ,
V_31 [ V_54 ] . V_34 . V_28 ) ;
F_37 ( V_8 ,
V_31 [ V_54 ] . V_35 . V_84 ,
V_31 [ V_54 ] . V_35 . V_28 ) ;
F_37 ( V_8 ,
V_31 [ V_54 ] . V_27 . V_84 ,
V_31 [ V_54 ] . V_27 . V_28 ) ;
}
}
static void F_44 ( struct V_7 * V_8 )
{
struct V_19 * V_42 ;
struct V_1 * V_2 ;
struct V_56 * V_137 ;
T_1 line , V_138 , V_54 ;
F_43 ( V_8 ) ;
V_2 = V_8 -> V_11 ;
V_137 = V_2 -> V_55 ;
V_42 = V_8 -> V_11 -> V_42 ;
F_17 (i, clients) {
if ( ! V_42 [ V_54 ] . V_33 )
continue;
line = V_42 [ V_54 ] . V_34 . V_28 - V_2 -> V_39 ;
V_138 = V_139 +
V_42 [ V_54 ] . V_34 . V_28 * V_140 ;
for (; line <= V_42 [ V_54 ] . V_35 . V_28 - V_2 -> V_39 ;
line ++ , V_138 += V_140 ) {
V_69 V_141 = 0 ;
if ( V_137 [ line ] . V_58 ) {
F_36 ( V_141 , V_142 , 1ULL ) ;
F_36 ( V_141 , V_143 ,
( V_137 [ line ] . V_62 >> 12 ) ) ;
F_3 ( V_8 , V_13 ,
L_13 ,
V_138 , line , V_54 ,
( V_69 ) ( V_137 [ line ] . V_62 >> 12 ) ) ;
}
F_45 ( V_8 , V_138 , V_141 ) ;
}
}
}
void F_46 ( struct V_7 * V_8 )
{
F_35 ( V_8 ) ;
}
void F_47 ( struct V_7 * V_8 )
{
F_38 ( V_8 ) ;
F_40 ( V_8 ) ;
F_42 ( V_8 ) ;
F_44 ( V_8 ) ;
}
int F_48 ( struct V_7 * V_8 ,
enum V_14 type ,
T_1 * V_144 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_145 ;
if ( type >= V_4 || ! V_2 -> V_74 [ type ] . V_75 ) {
F_26 ( V_8 , L_14 , type ) ;
return - V_52 ;
}
V_145 = F_49 ( V_2 -> V_74 [ type ] . V_75 ,
V_2 -> V_74 [ type ] . V_76 ) ;
if ( V_145 >= V_2 -> V_74 [ type ] . V_76 ) {
F_26 ( V_8 , L_15 ,
type ) ;
return - V_52 ;
}
F_50 ( V_145 , V_2 -> V_74 [ type ] . V_75 ) ;
* V_144 = V_145 + V_2 -> V_74 [ type ] . V_77 ;
return 0 ;
}
static bool F_51 ( struct V_7 * V_8 ,
T_1 V_146 ,
enum V_14 * V_147 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
struct V_148 * V_149 ;
enum V_14 V_150 ;
T_1 V_145 ;
for ( V_150 = 0 ; V_150 < V_4 ; V_150 ++ ) {
V_149 = & V_2 -> V_74 [ V_150 ] ;
if ( ! V_149 -> V_75 )
continue;
if ( V_146 >= V_149 -> V_77 &&
V_146 < V_149 -> V_77 + V_149 -> V_76 )
break;
}
* V_147 = V_150 ;
if ( V_150 == V_4 ) {
F_26 ( V_8 , L_16 , V_146 ) ;
return false ;
}
V_145 = V_146 - V_149 -> V_77 ;
if ( ! F_52 ( V_145 , V_149 -> V_75 ) ) {
F_26 ( V_8 , L_17 , V_146 ) ;
return false ;
}
return true ;
}
void F_53 ( struct V_7 * V_8 ,
T_1 V_146 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
enum V_14 type ;
bool V_151 ;
T_1 V_145 ;
V_151 = F_51 ( V_8 , V_146 , & type ) ;
if ( ! V_151 )
return;
V_145 = V_146 - V_2 -> V_74 [ type ] . V_77 ;
F_54 ( V_145 , V_2 -> V_74 [ type ] . V_75 ) ;
}
int F_55 ( struct V_7 * V_8 ,
struct V_152 * V_153 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_154 , V_155 , V_156 , line ;
enum V_14 type ;
bool V_151 ;
V_151 = F_51 ( V_8 , V_153 -> V_157 , & type ) ;
if ( ! V_151 )
return - V_52 ;
V_153 -> type = type ;
V_155 = V_8 -> V_11 -> V_42 [ V_43 ] . V_27 . V_28 ;
V_154 = F_12 ( V_8 ) ;
V_156 = F_7 ( V_155 ) / V_154 ;
line = V_153 -> V_157 / V_156 ;
if ( ! V_2 -> V_55 [ line ] . V_58 )
return - V_52 ;
V_153 -> V_158 = V_2 -> V_55 [ line ] . V_58 +
V_153 -> V_157 % V_156 * V_154 ;
F_3 ( V_8 , ( V_13 | V_82 ) ,
L_18 ,
V_153 -> V_157 / V_156 , V_153 -> V_158 , V_153 -> V_157 ) ;
return 0 ;
}
int F_56 ( struct V_7 * V_8 )
{
struct V_159 * V_160 = & V_8 -> V_161 . V_162 ;
T_1 V_163 = 1 ;
F_4 ( V_8 , V_127 , V_163 ) ;
F_4 ( V_8 , V_164 ,
V_160 -> V_165 ) ;
return 0 ;
}
