static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 type ;
for ( type = 0 ; type < V_5 ; type ++ ) {
V_4 -> V_6 += V_2 -> V_7 [ type ] . V_8 ;
V_4 -> V_9 += V_2 -> V_7 [ type ] . V_10 ;
}
}
static void F_2 ( struct V_11 * V_12 ,
struct V_13 * V_4 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
T_1 V_15 = 0 , type ;
for ( type = 0 ; type < V_5 ; type ++ ) {
V_4 -> V_16 += V_2 -> V_7 [ type ] . V_8 ;
V_15 += V_2 -> V_7 [ type ] . V_10 ;
}
V_4 -> V_15 += V_15 * V_2 -> V_17 ;
F_3 ( V_12 , V_18 ,
L_1 ,
V_4 -> V_16 , V_4 -> V_15 ) ;
}
static void F_4 ( struct V_11 * V_12 ,
enum V_19 type ,
T_1 V_8 , T_1 V_20 )
{
struct V_1 * V_21 = V_12 -> V_14 ;
struct V_22 * V_23 = & V_21 -> V_7 [ type ] ;
V_23 -> V_8 = F_5 ( V_8 , V_24 ) ;
V_23 -> V_10 = F_5 ( V_20 , V_24 ) ;
}
T_1 F_6 ( struct V_11 * V_12 ,
enum V_19 type ,
T_1 * V_25 )
{
if ( V_25 )
* V_25 = V_12 -> V_14 -> V_7 [ type ] . V_10 ;
return V_12 -> V_14 -> V_7 [ type ] . V_8 ;
}
static void F_7 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
T_1 V_30 , T_1 V_31 ,
T_1 V_32 )
{
T_1 V_33 = F_8 ( V_27 -> V_34 . V_35 ) ;
if ( V_29 -> V_31 )
return;
V_29 -> V_31 = V_31 ;
V_29 -> V_36 = 0 ;
if ( V_32 )
V_29 -> V_36 = ( V_33 / V_32 ) * V_32 ;
V_29 -> V_30 = V_30 ;
}
static void F_9 ( struct V_11 * V_12 ,
struct V_26 * V_27 ,
struct V_28 * V_29 ,
T_1 * V_37 , enum V_38 V_39 )
{
if ( ! V_29 -> V_31 )
return;
if ( ! V_27 -> V_40 )
V_27 -> V_41 . V_35 = * V_37 ;
V_27 -> V_40 = true ;
* V_37 += F_10 ( V_29 -> V_31 ,
V_29 -> V_36 ) ;
V_27 -> V_42 . V_35 = * V_37 - 1 ;
F_3 ( V_12 , V_18 ,
L_2 ,
V_39 , V_27 -> V_41 . V_35 ,
V_27 -> V_42 . V_35 , V_29 -> V_31 ,
V_29 -> V_36 , V_29 -> V_30 ) ;
}
int F_11 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_3 V_43 ;
struct V_13 V_44 ;
T_1 V_45 , V_46 , V_47 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_2 -> V_48 = F_12 ( V_12 , V_49 ) ;
F_3 ( V_12 , V_18 ,
L_3 ,
V_12 -> V_50 , V_12 -> V_14 -> V_48 ) ;
V_27 = & V_2 -> V_51 [ V_52 ] ;
V_45 = V_2 -> V_48 ;
V_27 -> V_53 = 0 ;
F_1 ( V_2 , & V_43 ) ;
V_29 = & V_27 -> V_54 [ V_55 ] ;
V_46 = V_43 . V_6 * F_13 ( V_12 ) ;
F_7 ( V_27 , V_29 , V_45 ,
V_46 , F_13 ( V_12 ) ) ;
F_9 ( V_12 , V_27 , V_29 , & V_45 , V_52 ) ;
V_27 -> V_53 = V_45 - V_29 -> V_30 ;
V_29 = & V_27 -> V_56 [ V_55 ] ;
V_46 = V_43 . V_9 * F_13 ( V_12 ) ;
F_7 ( V_27 , V_29 , V_45 ,
V_46 , F_13 ( V_12 ) ) ;
F_9 ( V_12 , V_27 , V_29 , & V_45 , V_52 ) ;
V_27 -> V_57 = V_45 - V_29 -> V_30 ;
for ( V_47 = 1 ; V_47 < V_2 -> V_17 ; V_47 ++ )
F_9 ( V_12 , V_27 , V_29 , & V_45 ,
V_52 ) ;
V_27 = & V_2 -> V_51 [ V_58 ] ;
V_29 = & V_27 -> V_54 [ 0 ] ;
F_2 ( V_12 , & V_44 ) ;
V_46 = F_14 ( V_12 -> V_59 , V_44 . V_16 ,
V_44 . V_15 , 0 ,
V_12 -> V_60 . V_61 ,
V_12 -> V_60 . V_62 ) ;
F_3 ( V_12 ,
V_18 ,
L_4 ,
V_44 . V_16 ,
V_44 . V_15 ,
V_12 -> V_60 . V_61 , V_12 -> V_60 . V_62 , V_46 ) ;
F_7 ( V_27 , V_29 ,
V_45 , V_46 * 0x1000 ,
V_63 ) ;
F_9 ( V_12 , V_27 , V_29 , & V_45 , V_58 ) ;
V_27 -> V_53 = V_45 - V_29 -> V_30 ;
if ( V_45 - V_12 -> V_14 -> V_48 >
F_15 ( V_12 , V_49 ) ) {
F_16 ( V_12 , L_5 ,
V_45 - V_12 -> V_14 -> V_48 ) ;
return - V_64 ;
}
return 0 ;
}
static T_1 F_17 ( struct V_26 * V_38 )
{
T_1 V_65 = 0 ;
T_1 V_47 ;
F_18 (i, ilt_clients) {
if ( ! V_38 [ V_47 ] . V_40 )
continue;
V_65 += ( V_38 [ V_47 ] . V_42 . V_35 -
V_38 [ V_47 ] . V_41 . V_35 + 1 ) ;
}
return V_65 ;
}
static void F_19 ( struct V_11 * V_12 )
{
struct V_26 * V_27 = V_12 -> V_14 -> V_51 ;
struct V_1 * V_2 = V_12 -> V_14 ;
T_1 V_33 , V_47 ;
V_33 = F_17 ( V_27 ) ;
for ( V_47 = 0 ; V_2 -> V_66 && V_47 < V_33 ; V_47 ++ ) {
struct V_67 * V_68 = & V_2 -> V_66 [ V_47 ] ;
if ( V_68 -> V_69 )
F_20 ( & V_12 -> V_70 -> V_71 -> V_72 ,
V_68 -> V_65 , V_68 -> V_69 ,
V_68 -> V_73 ) ;
V_68 -> V_69 = NULL ;
}
F_21 ( V_2 -> V_66 ) ;
}
static int F_22 ( struct V_11 * V_12 ,
struct V_28 * V_29 ,
enum V_38 V_74 ,
T_1 V_75 )
{
struct V_67 * V_66 = V_12 -> V_14 -> V_66 ;
T_1 V_76 , line , V_77 ;
if ( ! V_29 -> V_31 )
return 0 ;
V_77 = V_29 -> V_31 ;
V_76 = F_10 ( V_77 , V_29 -> V_36 ) ;
line = V_29 -> V_30 + V_75 -
V_12 -> V_14 -> V_48 ;
for (; V_76 ; V_76 -- ) {
T_2 V_73 ;
void * V_69 ;
T_1 V_65 ;
V_65 = F_23 ( T_1 , V_77 ,
V_29 -> V_36 ) ;
V_69 = F_24 ( & V_12 -> V_70 -> V_71 -> V_72 ,
V_65 ,
& V_73 ,
V_78 ) ;
if ( ! V_69 )
return - V_79 ;
memset ( V_69 , 0 , V_65 ) ;
V_66 [ line ] . V_73 = V_73 ;
V_66 [ line ] . V_69 = V_69 ;
V_66 [ line ] . V_65 = V_65 ;
F_3 ( V_12 , V_18 ,
L_6 ,
line , ( V_80 ) V_73 , V_69 , V_65 ) ;
V_77 -= V_65 ;
line ++ ;
}
return 0 ;
}
static int F_25 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
struct V_26 * V_51 = V_2 -> V_51 ;
struct V_28 * V_29 ;
T_1 V_65 , V_47 , V_81 , V_82 ;
int V_83 ;
V_65 = F_17 ( V_51 ) ;
V_2 -> V_66 = F_26 ( V_65 , sizeof( struct V_67 ) ,
V_78 ) ;
if ( ! V_2 -> V_66 ) {
F_27 ( V_12 , L_7 ) ;
V_83 = - V_79 ;
goto V_84;
}
F_3 ( V_12 , V_18 ,
L_8 ,
( T_1 ) ( V_65 * sizeof( struct V_67 ) ) ) ;
F_18 (i, clients) {
if ( ! V_51 [ V_47 ] . V_40 )
continue;
for ( V_81 = 0 ; V_81 < V_85 ; V_81 ++ ) {
V_29 = & V_51 [ V_47 ] . V_54 [ V_81 ] ;
V_83 = F_22 ( V_12 , V_29 , V_47 , 0 ) ;
if ( V_83 != 0 )
goto V_84;
}
for ( V_82 = 0 ; V_82 < V_2 -> V_17 ; V_82 ++ ) {
for ( V_81 = 0 ; V_81 < V_86 ; V_81 ++ ) {
T_1 V_76 = V_51 [ V_47 ] . V_57 * V_82 ;
V_29 = & V_51 [ V_47 ] . V_56 [ V_81 ] ;
V_83 = F_22 ( V_12 , V_29 , V_47 , V_76 ) ;
if ( V_83 != 0 )
goto V_84;
}
}
}
return 0 ;
V_84:
F_19 ( V_12 ) ;
return V_83 ;
}
static void F_28 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
T_1 type ;
for ( type = 0 ; type < V_5 ; type ++ ) {
F_21 ( V_2 -> V_87 [ type ] . V_88 ) ;
V_2 -> V_87 [ type ] . V_89 = 0 ;
V_2 -> V_87 [ type ] . V_90 = 0 ;
}
}
static int F_29 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
T_1 V_90 = 0 ;
T_1 type ;
for ( type = 0 ; type < V_5 ; type ++ ) {
T_1 V_91 = V_12 -> V_14 -> V_7 [ type ] . V_8 ;
T_1 V_65 ;
if ( V_91 == 0 )
continue;
V_65 = F_10 ( V_91 ,
sizeof( unsigned long ) * V_92 ) *
sizeof( unsigned long ) ;
V_2 -> V_87 [ type ] . V_88 = F_30 ( V_65 , V_78 ) ;
if ( ! V_2 -> V_87 [ type ] . V_88 )
goto V_93;
V_2 -> V_87 [ type ] . V_89 = V_91 ;
V_2 -> V_87 [ type ] . V_90 = V_90 ;
V_12 -> V_14 -> V_7 [ type ] . V_94 = V_90 ;
F_3 ( V_12 , V_95 ,
L_9 ,
type , V_2 -> V_87 [ type ] . V_90 ,
V_2 -> V_87 [ type ] . V_89 ) ;
V_90 += V_91 ;
}
return 0 ;
V_93:
F_28 ( V_12 ) ;
return - V_79 ;
}
int F_31 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
T_1 V_47 ;
V_2 = F_30 ( sizeof( * V_2 ) , V_78 ) ;
if ( ! V_2 ) {
F_27 ( V_12 , L_10 ) ;
return - V_79 ;
}
V_2 -> V_51 [ V_52 ] . V_41 . V_96 = F_32 ( V_97 , V_98 ) ;
V_2 -> V_51 [ V_52 ] . V_42 . V_96 = F_32 ( V_97 , V_99 ) ;
V_2 -> V_51 [ V_52 ] . V_34 . V_96 = F_32 ( V_97 , V_100 ) ;
V_2 -> V_51 [ V_58 ] . V_41 . V_96 = F_32 ( V_101 , V_98 ) ;
V_2 -> V_51 [ V_58 ] . V_42 . V_96 = F_32 ( V_101 , V_99 ) ;
V_2 -> V_51 [ V_58 ] . V_34 . V_96 = F_32 ( V_101 , V_100 ) ;
for ( V_47 = 0 ; V_47 < V_102 ; V_47 ++ )
V_2 -> V_51 [ V_47 ] . V_34 . V_35 = V_103 ;
if ( V_12 -> V_70 -> V_104 )
V_2 -> V_17 = V_12 -> V_70 -> V_104 -> V_105 ;
V_12 -> V_14 = V_2 ;
return 0 ;
}
int F_33 ( struct V_11 * V_12 )
{
int V_83 ;
V_83 = F_25 ( V_12 ) ;
if ( V_83 ) {
F_27 ( V_12 , L_11 ) ;
goto V_106;
}
V_83 = F_29 ( V_12 ) ;
if ( V_83 ) {
F_27 ( V_12 , L_12 ) ;
goto V_106;
}
return 0 ;
V_106:
F_34 ( V_12 ) ;
return V_83 ;
}
void F_34 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_14 )
return;
F_28 ( V_12 ) ;
F_19 ( V_12 ) ;
F_21 ( V_12 -> V_14 ) ;
V_12 -> V_14 = NULL ;
}
void F_35 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
int type ;
for ( type = 0 ; type < V_5 ; type ++ ) {
T_1 V_91 = V_12 -> V_14 -> V_7 [ type ] . V_8 ;
if ( V_91 == 0 )
continue;
memset ( V_2 -> V_87 [ type ] . V_88 , 0 ,
F_10 ( V_91 ,
sizeof( unsigned long ) * V_92 ) *
sizeof( unsigned long ) ) ;
}
}
static void F_36 ( struct V_11 * V_12 )
{
T_1 V_107 , V_108 , V_109 , V_110 , V_111 = 0 ;
V_107 = V_12 -> V_14 -> V_51 [ V_52 ] . V_34 . V_35 ;
V_110 = F_13 ( V_12 ) ;
V_108 = F_8 ( V_107 ) / V_110 ;
V_109 = F_8 ( V_107 ) - V_108 * V_110 ;
F_37 ( V_111 , V_112 , V_110 ) ;
F_37 ( V_111 , V_113 , V_109 ) ;
F_37 ( V_111 , V_114 , V_108 ) ;
F_38 ( V_12 , V_115 , V_111 ) ;
}
void F_39 ( struct V_11 * V_12 )
{
struct V_116 V_117 ;
struct V_118 * V_60 = & V_12 -> V_60 ;
struct V_13 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
F_2 ( V_12 , & V_4 ) ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_117 . V_119 = V_12 -> V_119 ;
V_117 . V_120 = V_12 -> V_59 ;
V_117 . V_121 = V_60 -> V_121 ;
V_117 . V_122 = V_12 -> V_123 ;
V_117 . V_124 = V_4 . V_16 ;
V_117 . V_125 = V_4 . V_15 ;
V_117 . V_126 = V_60 -> V_126 ;
V_117 . V_127 = V_60 -> V_61 - V_60 -> V_62 ;
V_117 . V_62 = V_60 -> V_62 ;
V_117 . V_128 = V_60 -> V_128 ;
V_117 . V_129 = V_60 -> V_129 ;
V_117 . V_130 = V_60 -> V_130 ;
V_117 . V_131 = V_60 -> V_131 ;
V_117 . V_132 = V_60 -> V_133 ;
V_117 . V_134 = V_60 -> V_135 ;
F_40 ( V_12 , V_12 -> V_136 , & V_117 ) ;
}
static int F_41 ( struct V_11 * V_12 )
{
union V_137 V_132 ;
T_3 V_138 ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_132 . V_139 . V_140 = V_141 ;
V_138 = F_42 ( V_12 , V_142 , & V_132 ) ;
F_38 ( V_12 , V_143 , V_138 ) ;
return 0 ;
}
static void F_43 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
T_1 V_144 = 0 , V_145 = 0 ;
V_144 += ( V_2 -> V_7 [ 0 ] . V_8 >> V_146 ) ;
F_38 ( V_12 , V_147 , V_144 ) ;
V_145 += ( V_2 -> V_7 [ 0 ] . V_10 >> V_146 ) ;
F_38 ( V_12 , V_148 , V_145 ) ;
V_144 += ( V_2 -> V_7 [ 1 ] . V_8 >> V_146 ) ;
F_38 ( V_12 , V_149 , V_144 ) ;
V_145 += ( V_2 -> V_7 [ 1 ] . V_10 >> V_146 ) ;
F_38 ( V_12 , V_150 , V_145 ) ;
V_144 += ( V_2 -> V_7 [ 2 ] . V_8 >> V_146 ) ;
F_38 ( V_12 , V_151 , V_144 ) ;
V_145 += ( V_2 -> V_7 [ 2 ] . V_10 >> V_146 ) ;
F_38 ( V_12 , V_152 , V_145 ) ;
V_144 += ( V_2 -> V_7 [ 3 ] . V_8 >> V_146 ) ;
F_38 ( V_12 , V_153 , V_144 ) ;
V_145 += ( V_2 -> V_7 [ 3 ] . V_10 >> V_146 ) ;
F_38 ( V_12 , V_154 , V_145 ) ;
V_144 += ( V_2 -> V_7 [ 4 ] . V_8 >> V_146 ) ;
F_38 ( V_12 , V_155 , V_144 ) ;
V_145 += ( V_2 -> V_7 [ 4 ] . V_10 >> V_146 ) ;
F_38 ( V_12 , V_156 , V_145 ) ;
V_144 += ( V_2 -> V_7 [ 5 ] . V_8 >> V_146 ) ;
F_38 ( V_12 , V_157 , V_144 ) ;
V_145 += ( V_2 -> V_7 [ 5 ] . V_10 >> V_146 ) ;
F_38 ( V_12 , V_158 , V_145 ) ;
F_38 ( V_12 , V_159 , V_144 ) ;
F_38 ( V_12 , V_160 , V_145 ) ;
F_38 ( V_12 , V_161 , V_144 ) ;
F_38 ( V_12 , V_162 , V_145 ) ;
}
static void F_44 ( struct V_11 * V_12 )
{
struct V_26 * V_38 ;
int V_47 ;
V_38 = V_12 -> V_14 -> V_51 ;
F_18 (i, ilt_clients) {
if ( ! V_38 [ V_47 ] . V_40 )
continue;
F_38 ( V_12 ,
V_38 [ V_47 ] . V_41 . V_96 ,
V_38 [ V_47 ] . V_41 . V_35 ) ;
F_38 ( V_12 ,
V_38 [ V_47 ] . V_42 . V_96 ,
V_38 [ V_47 ] . V_42 . V_35 ) ;
F_38 ( V_12 ,
V_38 [ V_47 ] . V_34 . V_96 ,
V_38 [ V_47 ] . V_34 . V_35 ) ;
}
}
static void F_45 ( struct V_11 * V_12 )
{
struct V_26 * V_27 ;
T_1 V_163 ;
if ( V_12 -> V_70 -> V_104 ) {
struct V_164 * V_165 = V_12 -> V_70 -> V_104 ;
F_38 ( V_12 ,
V_166 ,
V_165 -> V_167 ) ;
F_38 ( V_12 ,
V_168 ,
V_165 -> V_167 + V_165 -> V_105 ) ;
}
V_27 = & V_12 -> V_14 -> V_51 [ V_52 ] ;
V_163 = F_46 ( F_8 ( V_27 -> V_34 . V_35 ) >> 10 ) ;
if ( V_27 -> V_40 ) {
F_38 ( V_12 ,
V_169 ,
V_163 ) ;
F_38 ( V_12 ,
V_170 ,
V_27 -> V_53 ) ;
F_38 ( V_12 ,
V_171 ,
V_27 -> V_57 ) ;
}
}
static void F_47 ( struct V_11 * V_12 )
{
struct V_26 * V_51 ;
struct V_1 * V_2 ;
struct V_67 * V_172 ;
T_1 line , V_173 , V_47 ;
F_44 ( V_12 ) ;
F_45 ( V_12 ) ;
V_2 = V_12 -> V_14 ;
V_172 = V_2 -> V_66 ;
V_51 = V_12 -> V_14 -> V_51 ;
F_18 (i, clients) {
if ( ! V_51 [ V_47 ] . V_40 )
continue;
line = V_51 [ V_47 ] . V_41 . V_35 - V_2 -> V_48 ;
V_173 = V_174 +
V_51 [ V_47 ] . V_41 . V_35 * V_175 ;
for (; line <= V_51 [ V_47 ] . V_42 . V_35 - V_2 -> V_48 ;
line ++ , V_173 += V_175 ) {
V_80 V_176 = 0 ;
if ( V_172 [ line ] . V_69 ) {
F_37 ( V_176 , V_177 , 1ULL ) ;
F_37 ( V_176 , V_178 ,
( V_172 [ line ] . V_73 >> 12 ) ) ;
F_3 ( V_12 , V_18 ,
L_13 ,
V_173 , line , V_47 ,
( V_80 ) ( V_172 [ line ] . V_73 >> 12 ) ) ;
}
F_48 ( V_12 , V_173 , V_176 ) ;
}
}
}
void F_49 ( struct V_11 * V_12 )
{
F_36 ( V_12 ) ;
}
void F_50 ( struct V_11 * V_12 )
{
F_39 ( V_12 ) ;
F_41 ( V_12 ) ;
F_43 ( V_12 ) ;
F_47 ( V_12 ) ;
}
int F_51 ( struct V_11 * V_12 ,
enum V_19 type ,
T_1 * V_179 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
T_1 V_180 ;
if ( type >= V_5 || ! V_2 -> V_87 [ type ] . V_88 ) {
F_27 ( V_12 , L_14 , type ) ;
return - V_64 ;
}
V_180 = F_52 ( V_2 -> V_87 [ type ] . V_88 ,
V_2 -> V_87 [ type ] . V_89 ) ;
if ( V_180 >= V_2 -> V_87 [ type ] . V_89 ) {
F_27 ( V_12 , L_15 ,
type ) ;
return - V_64 ;
}
F_53 ( V_180 , V_2 -> V_87 [ type ] . V_88 ) ;
* V_179 = V_180 + V_2 -> V_87 [ type ] . V_90 ;
return 0 ;
}
static bool F_54 ( struct V_11 * V_12 ,
T_1 V_181 ,
enum V_19 * V_182 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
struct V_183 * V_184 ;
enum V_19 V_185 ;
T_1 V_180 ;
for ( V_185 = 0 ; V_185 < V_5 ; V_185 ++ ) {
V_184 = & V_2 -> V_87 [ V_185 ] ;
if ( ! V_184 -> V_88 )
continue;
if ( V_181 >= V_184 -> V_90 &&
V_181 < V_184 -> V_90 + V_184 -> V_89 )
break;
}
* V_182 = V_185 ;
if ( V_185 == V_5 ) {
F_27 ( V_12 , L_16 , V_181 ) ;
return false ;
}
V_180 = V_181 - V_184 -> V_90 ;
if ( ! F_55 ( V_180 , V_184 -> V_88 ) ) {
F_27 ( V_12 , L_17 , V_181 ) ;
return false ;
}
return true ;
}
void F_56 ( struct V_11 * V_12 ,
T_1 V_181 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
enum V_19 type ;
bool V_186 ;
T_1 V_180 ;
V_186 = F_54 ( V_12 , V_181 , & type ) ;
if ( ! V_186 )
return;
V_180 = V_181 - V_2 -> V_87 [ type ] . V_90 ;
F_57 ( V_180 , V_2 -> V_87 [ type ] . V_88 ) ;
}
int F_58 ( struct V_11 * V_12 ,
struct V_187 * V_188 )
{
struct V_1 * V_2 = V_12 -> V_14 ;
T_1 V_189 , V_190 , V_191 , line ;
enum V_19 type ;
bool V_186 ;
V_186 = F_54 ( V_12 , V_188 -> V_192 , & type ) ;
if ( ! V_186 )
return - V_64 ;
V_188 -> type = type ;
V_190 = V_12 -> V_14 -> V_51 [ V_52 ] . V_34 . V_35 ;
V_189 = F_13 ( V_12 ) ;
V_191 = F_8 ( V_190 ) / V_189 ;
line = V_188 -> V_192 / V_191 ;
if ( ! V_2 -> V_66 [ line ] . V_69 )
return - V_64 ;
V_188 -> V_193 = V_2 -> V_66 [ line ] . V_69 +
V_188 -> V_192 % V_191 * V_189 ;
F_3 ( V_12 , ( V_18 | V_95 ) ,
L_18 ,
V_188 -> V_192 / V_191 , V_188 -> V_193 , V_188 -> V_192 ) ;
return 0 ;
}
int F_59 ( struct V_11 * V_12 )
{
struct V_194 * V_195 = & V_12 -> V_196 . V_197 ;
T_1 V_198 = 1 ;
F_4 ( V_12 , V_142 , V_198 , 0 ) ;
F_4 ( V_12 , V_199 ,
V_195 -> V_200 , 1 ) ;
return 0 ;
}
