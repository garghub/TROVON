static T_1 * F_1 ( T_1 V_1 , T_1 V_2 )
{
T_1 * V_3 ;
int V_4 ;
V_3 = V_5 ;
for ( V_4 = 0 ; ; V_3 ++ , V_4 ++ ) {
if ( ( * V_3 & V_2 ) == ( V_1 & V_2 ) )
break;
if ( * V_3 == 0 )
return NULL ;
}
return V_3 ;
}
static int F_2 ( const struct V_6 * V_7 )
{
T_1 * V_3 ;
if ( V_7 -> V_1 & V_8 ) {
V_3 = F_1 ( V_7 -> V_1 , V_8 ) ;
if ( V_3 )
F_3 ( & V_9 -> V_10 -> V_11 ,
L_1 ,
V_7 -> V_1 , F_4 ( V_7 -> V_1 ) ,
V_7 -> V_12 ) ;
else
F_5 ( V_13
L_2 ,
V_14 , V_7 -> V_1 , V_7 -> V_12 ) ;
return 1 ;
}
return 0 ;
}
static int F_6 ( struct V_15 * V_10 ,
const void * V_16 , unsigned long V_12 )
{
int error ;
F_3 ( & V_10 -> V_11 , L_3 , V_14 , __LINE__ ) ;
error = F_7 ( V_10 , V_16 , V_12 ) ;
F_3 ( & V_10 -> V_11 , L_4 , V_14 , __LINE__ ) ;
return error ? error : V_12 ;
}
static int F_8 ( struct V_15 * V_10 , void * V_16 ,
unsigned long V_12 , int V_17 )
{
int error ;
int V_18 = 0 ;
F_3 ( & V_10 -> V_11 , L_3 , V_14 , __LINE__ ) ;
V_17 = ( V_17 + V_19 - 1 ) / V_19 ;
while ( V_18 ++ <= V_17 ) {
error = F_9 ( V_10 , V_16 , V_12 ) ;
if ( ! error )
return V_12 ;
if ( error != - V_20 ) {
F_5 ( V_13 L_5 ,
V_14 , error ) ;
return error ;
}
F_10 ( V_19 ) ;
}
return - V_21 ;
}
static int F_11 ( const struct V_22 * V_23 ,
struct V_6 * V_24 , int V_25 ,
int V_26 )
{
int V_27 ;
T_1 V_28 ;
int V_29 ;
if ( ! V_9 )
return - V_30 ;
V_27 = F_6 ( V_9 -> V_10 , V_23 , V_25 ) ;
if ( V_27 < 0 ) {
F_3 ( & V_9 -> V_10 -> V_11 ,
L_6 ,
V_14 , V_27 ) ;
return V_27 ;
}
V_28 = V_23 -> V_1 ;
do {
V_27 = F_8 ( V_9 -> V_10 , V_24 , V_31 ,
V_17 ) ;
if ( V_27 != V_31 ) {
F_3 ( & V_9 -> V_10 -> V_11 ,
L_7 ,
V_14 , V_27 ) ;
return V_27 ;
}
V_27 = F_8 ( V_9 -> V_10 , & V_24 -> V_1 ,
V_24 -> V_12 , V_17 ) ;
if ( V_27 < 0 ) {
F_3 ( & V_9 -> V_10 -> V_11 ,
L_7 ,
V_14 , V_27 ) ;
return V_27 ;
}
V_27 += V_31 ;
V_29 = F_2 ( V_24 ) ;
} while ( V_29 );
if ( ( V_28 | V_32 ) != V_24 -> V_1 ) {
F_3 ( & V_9 -> V_10 -> V_11 , L_8 ,
V_14 , V_24 -> V_1 ) ;
return - V_33 ;
}
return 0 ;
}
static int F_12 ( struct V_22 * V_34 ,
const struct V_6 * V_24 ,
int V_35 )
{
int V_36 ;
if ( V_24 -> V_37 != V_38 ) {
F_3 ( & V_9 -> V_10 -> V_11 , L_9 ,
V_24 -> V_37 ) ;
return - V_39 ;
}
V_36 = V_24 -> V_12 + V_31 ;
if ( V_36 > V_35 )
V_36 = V_35 ;
memcpy ( V_34 , V_24 , V_36 ) ;
return 0 ;
}
void F_13 ( T_1 V_1 , T_2 V_12 , struct V_22 * V_7 )
{
V_7 -> V_37 = V_38 ;
V_7 -> V_12 = V_12 - V_31 ;
V_7 -> V_1 = V_1 ;
}
int F_14 ( T_1 V_1 , T_2 V_40 , T_3 V_41 ,
struct V_22 * V_16 )
{
int V_27 = 0 ;
T_1 * V_3 ;
F_15 ( ! V_9 ) ;
F_16 ( & V_9 -> V_42 ) ;
V_3 = F_1 ( V_1 , V_43 ) ;
F_15 ( ! V_3 ) ;
F_15 ( V_40 < V_31 ) ;
F_15 ( V_41 < V_40 ) ;
F_15 ( V_41 > V_44 ) ;
F_13 ( V_1 , V_40 , V_16 ) ;
V_27 = F_11 ( V_16 , & V_9 -> V_24 . V_45 , V_40 ,
V_41 ) ;
if ( V_27 < 0 ) {
F_5 ( V_13
L_10 ,
V_14 , V_27 ) ;
goto V_46;
}
V_27 = F_12 ( V_16 , & V_9 -> V_24 . V_45 ,
V_41 ) ;
if ( V_27 < 0 ) {
F_5 ( V_13 L_11 ,
V_14 , V_27 ) ;
goto V_46;
}
F_17 ( & V_9 -> V_42 ) ;
return 0 ;
V_46:
F_17 ( & V_9 -> V_42 ) ;
F_5 ( V_13 L_12 , V_14 , V_1 , V_27 ) ;
return V_27 ;
}
static int F_18 ( T_1 V_47 )
{
int V_4 , V_48 , V_27 ;
V_48 = V_9 -> V_49 . V_50 +
V_9 -> V_49 . V_51 ;
for ( V_4 = 0 ; V_4 < V_48 ; V_4 ++ ) {
V_27 = F_19 ( 1 , & V_9 -> V_52 [ V_4 ] , V_47 ) ;
if ( V_27 < 0 )
return - 1 ;
}
return 0 ;
}
static int F_20 ( void )
{
int V_4 , V_53 , V_48 , V_27 ;
V_53 = V_9 -> V_49 . V_50 ;
V_48 = V_9 -> V_49 . V_50 +
V_9 -> V_49 . V_51 ;
for ( V_4 = 0 ; V_4 < V_53 ; V_4 ++ ) {
V_27 = F_21 ( V_9 -> V_52 [ V_4 ] ,
V_54 ) ;
if ( V_27 < 0 )
return - 1 ;
}
F_10 ( 100 ) ;
for ( V_4 = 0 ; V_4 < V_48 ; V_4 ++ ) {
V_27 = F_22 ( V_9 -> V_52 [ V_4 ] ) ;
if ( V_27 < 0 )
return - 1 ;
if ( V_4 < V_53 ) {
V_27 = F_21 ( V_9 -> V_52 [ V_4 ] ,
V_55 ) ;
if ( V_27 < 0 )
return - 1 ;
}
}
F_10 ( 300 ) ;
return 0 ;
}
static int F_23 ( T_1 V_47 )
{
int V_4 , V_48 , V_56 , V_27 ;
V_48 = V_9 -> V_49 . V_50 +
V_9 -> V_49 . V_51 ;
V_56 = V_9 -> V_49 . V_57 ;
for ( V_4 = 0 ; V_4 < V_48 ; V_4 ++ ) {
V_27 = F_24 ( 1 , & V_9 -> V_52 [ V_4 ] , V_47 ) ;
if ( V_27 < 0 )
return - 1 ;
}
for ( V_4 = 0 ; V_4 < V_56 ; V_4 ++ ) {
V_27 = F_25 ( 1 , & V_9 -> V_58 [ V_4 ] , V_47 ) ;
if ( V_27 < 0 )
return - 1 ;
}
return 0 ;
}
int F_26 ( T_1 V_59 , T_1 V_60 , T_1 V_61 , T_1 V_62 , T_1 V_63 )
{
struct V_64 V_65 ;
int V_4 , V_66 , V_67 , V_27 ;
struct V_68 V_69 ;
T_1 V_70 = 0 ;
V_66 = V_9 -> V_49 . V_50 +
V_9 -> V_49 . V_51 +
V_9 -> V_49 . V_57 ;
V_65 . V_71 = 0 ;
V_65 . V_72 = V_73 ;
V_65 . V_74 = 0 ;
V_65 . V_75 = V_9 -> V_49 . V_50 ;
V_67 = V_76 [ V_9 -> V_77 ] . V_67 ;
F_23 ( V_54 ) ;
V_27 = F_27 ( 0 , V_9 -> V_78 ) ;
if ( V_27 < 0 )
F_3 ( & V_9 -> V_10 -> V_11 ,
L_13 ) ;
for ( V_4 = 0 ; V_4 < V_66 ; V_4 ++ ) {
F_28 ( & V_69 , V_9 -> V_52 [ V_4 ] , V_59 ,
V_60 , V_61 , V_62 , V_63 ) ;
if ( V_4 < V_9 -> V_49 . V_50 ) {
V_70 += F_29 ( & V_65 . V_16 [ V_70 ] ,
V_9 -> V_52 [ V_4 ] ,
& V_69 , V_67 ) ;
}
V_27 = F_30 ( & V_69 ) ;
if ( V_27 < 0 )
F_3 ( & V_9 -> V_10 -> V_11 ,
L_14 , V_4 ) ;
}
V_70 += F_31 ( struct V_64 , V_16 ) ;
V_27 = F_32 ( & V_65 , V_70 ) ;
if ( V_27 < 0 )
F_3 ( & V_9 -> V_10 -> V_11 , L_15 ) ;
F_23 ( V_55 ) ;
V_27 = F_27 ( 1 , V_9 -> V_78 ) ;
if ( V_27 < 0 )
F_3 ( & V_9 -> V_10 -> V_11 ,
L_16 ) ;
return 0 ;
}
static int F_33 ( void )
{
F_18 ( V_54 ) ;
F_34 ( V_9 -> V_79 , & V_9 -> V_80 ) ;
return 0 ;
}
static void F_35 ( T_1 V_81 )
{
struct V_64 V_65 ;
unsigned int V_4 ;
T_1 V_70 = 0 , V_82 ;
const struct V_83 * V_84 ;
int V_27 ;
V_84 = & V_76 [ V_81 & V_85 ] ;
V_65 . V_71 = V_86 ;
V_65 . V_72 = 0 ;
V_65 . V_74 = V_9 -> V_49 . V_50 +
V_9 -> V_49 . V_51 ;
V_65 . V_75 = 0 ;
for ( V_4 = 0 ; V_4 < V_65 . V_71 ; V_4 ++ )
V_70 += F_36 ( & V_65 . V_16 [ V_70 ] ,
V_9 -> V_87 [ V_4 ] , V_84 -> V_67 ,
V_84 -> V_88 , V_81 ) ;
for ( V_4 = 0 ; V_4 < V_65 . V_74 ; V_4 ++ ) {
if ( V_81 & V_89 || V_81 & V_90 )
V_82 = V_91 ;
else
V_82 = V_84 -> V_92 ;
#ifndef F_37
if ( V_9 -> V_52 [ V_4 ] == V_93 ||
V_9 -> V_52 [ V_4 ] == V_94 )
V_82 = V_91 ;
#endif
V_70 += F_38 ( & V_65 . V_16 [ V_70 ] ,
V_9 -> V_52 [ V_4 ] ,
V_84 -> V_67 , V_82 ,
V_84 -> V_95 , V_81 ) ;
}
V_70 += F_31 ( struct V_64 , V_16 ) ;
V_27 = F_32 ( & V_65 , V_70 ) ;
if ( V_27 == V_96 )
F_5 ( V_97
L_17 ,
V_14 ) ;
else if ( V_27 )
F_3 ( & V_9 -> V_10 -> V_11 , L_15 ) ;
}
static void F_39 ( T_1 V_81 , T_1 V_98 )
{
static int V_99 ;
int V_27 ;
F_20 () ;
if ( V_99 == 0 && ( V_81 & V_85 ) >= V_100 ) {
F_35 ( V_101 ) ;
}
V_99 = 1 ;
if ( V_81 & V_102 ) {
V_27 = F_40 ( V_103 ) ;
if ( V_27 == V_104 )
F_3 ( & V_9 -> V_10 -> V_11 , L_18 ) ;
else if ( V_27 )
F_3 ( & V_9 -> V_10 -> V_11 ,
L_19 ) ;
} else if ( V_98 & V_102 ) {
V_27 = F_40 ( V_105 ) ;
if ( V_27 < 0 && V_27 != V_104 )
F_3 ( & V_9 -> V_10 -> V_11 ,
L_19 ) ;
}
F_35 ( V_81 ) ;
F_10 ( 1500 ) ;
F_18 ( V_55 ) ;
}
static void F_41 ( struct V_106 * V_80 )
{
F_39 ( V_9 -> V_77 , V_9 -> V_107 ) ;
F_42 ( & V_9 -> V_108 ) ;
}
static enum V_109 F_43 ( T_1 V_110 , T_1 V_111 ,
T_1 V_112 )
{
unsigned int V_4 ;
T_1 V_113 ;
F_44 ( V_114 << V_115 &
V_116 << V_117 ) ;
F_44 ( V_114 << V_115 &
V_118 << V_119 ) ;
F_44 ( V_116 << V_117 &
V_118 << V_119 ) ;
V_113 = ( V_110 & V_114 ) << V_115 |
( V_111 & V_116 ) << V_117 |
( V_112 & V_118 ) << V_119 ;
if ( ! V_113 )
return 0 ;
for ( V_4 = 0 ; V_4 < F_45 ( V_120 ) ; V_4 ++ )
if ( V_113 & V_120 [ V_4 ] . V_2 )
return V_120 [ V_4 ] . V_81 ;
return 0 ;
}
static enum V_109 F_46 ( struct V_121 * V_122 )
{
enum V_109 V_81 ;
if ( V_123 )
return V_124 ;
V_81 = F_43 ( V_122 -> V_110 . V_125 , V_122 -> V_111 . V_125 ,
V_122 -> V_112 . V_125 ) ;
if ( V_81 ) {
F_47 ( L_20 , V_14 , V_81 ) ;
return V_81 ;
}
V_81 = F_43 ( V_122 -> V_110 . V_126 , V_122 -> V_111 . V_126 ,
V_122 -> V_112 . V_126 ) ;
if ( V_81 ) {
F_47 ( L_21 , V_14 , V_81 ) ;
return V_81 ;
}
if ( V_9 -> V_127 & V_128 )
V_81 = V_124 ;
else
V_81 = V_129 ;
F_47 ( L_22 , V_14 , V_81 ) ;
return V_81 ;
}
static void F_48 ( const struct V_130 * V_131 )
{
const struct V_121 * V_122 = & V_131 -> V_122 ;
const struct V_132 * V_133 = V_122 -> V_133 ;
char V_81 [ sizeof( V_122 -> V_134 ) * 3 + 1 ] ;
int V_4 ;
F_47 ( L_23 , V_131 -> V_135 . V_12 ) ;
F_47 ( L_24 , V_122 -> V_136 ) ;
for ( V_4 = 0 ; V_4 < sizeof( V_122 -> V_134 ) ; V_4 ++ )
sprintf ( & V_81 [ V_4 * 3 ] , L_25 , V_122 -> V_134 [ V_4 ] ) ;
F_47 ( L_26 , V_81 ) ;
F_47 ( L_27 , V_122 -> V_137 ) ;
F_47 ( L_28 , ( int ) sizeof( V_122 -> V_138 ) ,
V_122 -> V_138 ) ;
F_47 ( L_29 ,
V_122 -> V_111 . V_126 , V_122 -> V_111 . V_125 ) ;
F_47 ( L_30 ,
V_122 -> V_110 . V_126 , V_122 -> V_110 . V_125 ) ;
F_47 ( L_31 ,
V_122 -> V_139 . V_126 , V_122 -> V_139 . V_125 ) ;
F_47 ( L_32 ,
V_122 -> V_112 . V_126 , V_122 -> V_112 . V_125 ) ;
F_47 ( L_33 , V_122 -> V_92 . V_140 ) ;
F_47 ( L_34 , V_122 -> V_92 . V_141 ) ;
F_47 ( L_35 , V_122 -> V_92 . V_142 ) ;
F_47 ( L_36 , V_122 -> V_143 . V_144 ,
V_122 -> V_143 . V_145 ) ;
F_47 ( L_37 , V_122 -> V_143 . V_146 ,
V_122 -> V_143 . V_147 ) ;
F_47 ( L_38 , V_122 -> V_143 . V_148 ,
V_122 -> V_143 . V_149 ) ;
F_47 ( L_39 , V_122 -> V_143 . V_150 ,
V_122 -> V_143 . V_151 ) ;
F_47 ( L_40 , V_122 -> V_143 . gamma ) ;
F_47 ( L_41 , V_122 -> V_152 ) ;
F_47 ( L_42 , V_122 -> V_153 ) ;
F_47 ( L_43 , V_122 -> V_154 ) ;
for ( V_4 = 0 ; V_4 < V_122 -> V_154 ; V_4 ++ ) {
F_47 ( L_44
L_45 ,
V_4 , V_133 -> type , V_133 -> V_155 , V_133 -> V_60 ,
V_133 -> V_156 ) ;
V_133 ++ ;
}
}
static void F_49 ( struct V_121 * V_122 )
{
unsigned int V_4 ;
const struct V_157 * V_158 ;
for ( V_4 = 0 ; V_4 < F_45 ( V_159 ) ; V_4 ++ ) {
V_158 = & V_159 [ V_4 ] ;
if ( ! strncmp ( V_122 -> V_138 , V_158 -> V_138 ,
sizeof( V_122 -> V_138 ) ) ) {
F_50 ( L_46 , V_14 ,
V_158 -> V_138 ) ;
V_122 -> V_111 . V_126 &= ~ V_158 -> V_160 ;
V_122 -> V_111 . V_125 &= ~ V_158 -> V_160 ;
break;
}
}
}
static int F_51 ( struct V_161 * V_49 )
{
int V_4 , V_27 , V_81 = 0 , V_162 = 0 , V_140 = 0 ;
struct V_130 V_131 ;
struct V_121 * V_122 ;
for ( V_4 = 0 ; V_4 < V_49 -> V_50 && ! V_81 ; V_4 ++ ) {
V_27 = F_52 ( & V_131 ,
V_93 +
V_4 ) ;
if ( V_27 < 0 )
return - 1 ;
F_48 ( & V_131 ) ;
V_122 = & V_131 . V_122 ;
F_49 ( V_122 ) ;
switch ( V_122 -> V_137 ) {
case V_163 :
V_162 = V_89 ;
case V_164 :
V_81 = F_46 ( V_122 ) ;
break;
}
}
if ( ! V_81 ) {
if ( V_9 -> V_127 & V_128 )
V_81 = V_165 ;
else
V_81 = V_166 ;
if ( V_9 -> V_127 & V_167 )
V_140 = V_90 ;
F_47 ( L_47 , V_14 , V_81 ) ;
}
return V_81 | V_162 | V_140 ;
}
static int F_53 ( struct V_9 * V_9 )
{
int V_4 , V_168 , V_169 , V_27 ;
const struct V_161 * V_170 ;
V_27 = F_54 ( & V_9 -> V_49 ) ;
if ( V_27 < 0 )
return - 1 ;
V_170 = & V_9 -> V_49 ;
F_47 ( L_48 , V_170 -> V_50 ) ;
F_47 ( L_49 , V_170 -> V_51 ) ;
F_47 ( L_50 , V_170 -> V_57 ) ;
for ( V_4 = 0 ; V_4 < V_171 ; V_4 ++ )
V_9 -> V_87 [ V_4 ] = V_172 + V_4 ;
for ( V_4 = 0 ; V_4 < V_173 ; V_4 ++ )
V_9 -> V_58 [ V_4 ] = V_174 + V_4 ;
for ( V_4 = 0 ; V_4 < V_170 -> V_50 ; V_4 ++ )
V_9 -> V_52 [ V_4 ] = V_93 + V_4 ;
for ( V_168 = 0 ; V_168 < V_170 -> V_51 ; V_168 ++ )
V_9 -> V_52 [ V_4 + V_168 ] = V_175 + V_168 ;
for ( V_169 = 0 ; V_169 < V_170 -> V_57 ; V_169 ++ )
V_9 -> V_52 [ V_4 + V_168 + V_169 ] = V_174 + V_169 ;
V_9 -> V_78 = V_176
| V_177
| V_178
| V_179 | V_180 ;
return 0 ;
}
int F_55 ( int V_81 )
{
int V_12 ;
T_1 V_181 ;
V_12 = F_45 ( V_76 ) ;
if ( ( V_81 & V_85 ) > V_12 - 1 || V_81 < 0 ) {
F_3 ( & V_9 -> V_10 -> V_11 , L_51 , V_14 , V_81 ) ;
return - V_33 ;
}
V_181 = V_81 & ~ V_85 ;
if ( ( V_81 & V_85 ) == V_182 ) {
V_81 = F_51 ( & V_9 -> V_49 ) ;
if ( V_81 < 1 ) {
F_5 ( V_13 L_52 , V_14 , V_81 ) ;
return - V_33 ;
}
V_81 |= V_181 ;
}
F_56 ( & V_9 -> V_108 ) ;
V_9 -> V_107 = V_9 -> V_77 ;
V_9 -> V_77 = V_81 ;
if ( F_33 () )
V_9 -> V_77 = V_9 -> V_107 ;
return 0 ;
}
int F_57 ( void )
{
return F_51 ( & V_9 -> V_49 ) ;
}
int F_58 ( void )
{
return V_9 ? V_9 -> V_77 : 0 ;
}
int F_59 ( T_1 V_81 , T_1 * V_183 , T_1 * V_184 )
{
int V_12 ;
V_81 = V_81 & V_85 ;
V_12 = F_45 ( V_76 ) ;
if ( V_81 > V_12 - 1 || V_81 < 0 ) {
F_5 ( V_13 L_53 , V_14 , V_81 ) ;
return - V_33 ;
}
* V_183 = V_76 [ V_81 ] . V_185 ;
* V_184 = V_76 [ V_81 ] . V_186 ;
return 0 ;
}
int F_60 ( int V_47 )
{
return F_18 ( V_47 ? V_54
: V_55 ) ;
}
int F_61 ( int V_47 )
{
int V_4 , V_27 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_49 . V_51 ; V_4 ++ ) {
V_27 = F_24 ( 1 ,
& V_9 -> V_52 [ V_4 + V_9 -> V_49 . V_50 ] ,
V_47 ) ;
if ( V_27 < 0 )
return - 1 ;
}
return 0 ;
}
int F_62 ( int V_47 )
{
return F_23 ( V_47 ? V_54
: V_55 ) ;
}
static int T_4 F_63 ( struct V_15 * V_10 )
{
int V_27 ;
int V_81 ;
F_3 ( & V_10 -> V_11 , L_3 , V_14 , __LINE__ ) ;
F_3 ( & V_10 -> V_11 , L_54 , V_17 ) ;
if ( V_9 ) {
F_64 ( & V_10 -> V_11 , L_55 ) ;
return - V_187 ;
}
V_9 = F_65 ( sizeof( * V_9 ) , V_188 ) ;
if ( ! V_9 )
return - V_189 ;
F_66 ( & V_9 -> V_42 ) ;
V_9 -> V_77 = V_182 ;
V_9 -> V_10 = V_10 ;
F_67 ( & V_9 -> V_80 , F_41 ) ;
F_68 ( & V_9 -> V_108 ) ;
F_42 ( & V_9 -> V_108 ) ;
V_9 -> V_79 = F_69 ( L_56 ) ;
if ( ! V_9 -> V_79 ) {
V_27 = - V_189 ;
goto V_190;
}
switch ( F_70 () ) {
case V_191 :
V_9 -> V_127 = V_128 ;
break;
case V_192 :
case V_193 :
V_9 -> V_127 = V_194 ;
break;
case V_195 :
V_9 -> V_127 = V_194 | V_167 ;
break;
default:
V_9 -> V_127 = V_128 ;
break;
}
V_27 = F_71 () ;
if ( V_27 < 0 )
F_5 ( V_13 L_57 , V_14 ,
V_27 ) ;
F_53 ( V_9 ) ;
#ifdef F_72
if ( V_196 && ! strcmp ( V_196 , L_58 ) )
V_123 = 1 ;
#endif
V_81 = F_51 ( & V_9 -> V_49 ) ;
if ( V_81 < 0 ) {
F_5 ( V_13 L_52 , V_14 , V_81 ) ;
V_27 = - V_33 ;
goto V_190;
}
V_123 = 0 ;
F_16 ( & V_9 -> V_42 ) ;
V_9 -> V_77 = V_81 ;
F_17 ( & V_9 -> V_42 ) ;
F_3 ( & V_10 -> V_11 , L_4 , V_14 , __LINE__ ) ;
return 0 ;
V_190:
F_73 ( V_9 ) ;
V_9 = NULL ;
return V_27 ;
}
static int F_74 ( struct V_15 * V_10 )
{
F_3 ( & V_10 -> V_11 , L_3 , V_14 , __LINE__ ) ;
if ( V_9 ) {
F_75 () ;
if ( V_9 -> V_79 )
F_76 ( V_9 -> V_79 ) ;
F_73 ( V_9 ) ;
V_9 = NULL ;
}
F_3 ( & V_10 -> V_11 , L_4 , V_14 , __LINE__ ) ;
return 0 ;
}
static void F_77 ( struct V_15 * V_10 )
{
F_3 ( & V_10 -> V_11 , L_3 , V_14 , __LINE__ ) ;
F_74 ( V_10 ) ;
F_3 ( & V_10 -> V_11 , L_4 , V_14 , __LINE__ ) ;
}
static int T_5 F_78 ( void )
{
int error ;
if ( ! F_79 ( V_197 ) )
return - V_30 ;
F_47 ( L_3 , V_14 , __LINE__ ) ;
error = F_80 ( & V_198 ) ;
if ( error ) {
F_5 ( V_13
L_59 ,
V_14 , error ) ;
return error ;
}
F_47 ( L_4 , V_14 , __LINE__ ) ;
return error ;
}
static void T_6 F_81 ( void )
{
F_47 ( L_3 , V_14 , __LINE__ ) ;
F_82 ( & V_198 ) ;
F_47 ( L_4 , V_14 , __LINE__ ) ;
}
