int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
int V_5 ;
struct V_6 V_7 ;
T_1 * V_8 ;
if ( V_3 >= V_9 )
return - V_10 ;
V_7 . V_11 . V_12 = V_13 ;
V_7 . V_14 . V_15 . V_16 = F_2 ( 1 ) ;
V_7 . V_14 . V_15 . V_17 = F_3 ( V_18 ) ;
V_7 . V_14 . V_15 . V_19 = V_20 ;
memset ( V_7 . V_14 . V_15 . V_21 , 0 ,
sizeof( V_7 . V_14 . V_15 . V_21 ) ) ;
V_7 . V_14 . V_15 . V_21 [ V_3 >> 3 ] = 1 << ( V_3 & 0x7 ) ;
V_5 = F_4 ( V_2 , NULL , & V_7 , sizeof( V_7 ) ,
V_22 ,
0 , L_1 ) ;
if ( V_5 == 0 ) {
V_8 = V_7 . V_14 . V_23 . V_24 ;
memcpy ( V_4 , V_8 , V_25 ) ;
}
return V_5 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 , T_2 V_26 ,
struct V_27 * V_28 )
{
struct V_29 V_8 ;
struct V_30 V_31 ;
int V_5 ;
int V_32 ;
int V_33 ;
if ( V_26 > F_6 ( V_2 -> V_34 ) )
return - V_10 ;
V_5 = F_7 ( & V_8 , V_35 , V_36 ) ;
if ( V_5 )
return V_5 ;
F_8 ( & V_8 , V_3 ) ;
V_31 . V_37 = F_2 ( V_38 ) ;
V_31 . V_39 = 0 ;
V_31 . V_40 = 0 ;
V_31 . V_41 = 0 ;
F_8 ( & V_8 , sizeof( struct V_30 ) ) ;
F_9 ( & V_8 , ( const unsigned char * ) & V_31 ,
sizeof( V_31 ) ) ;
F_8 ( & V_8 , V_26 ) ;
for ( V_32 = 0 ; V_32 < V_26 ; V_32 ++ ) {
for ( V_33 = 0 ; V_33 < F_6 ( V_42 ) ; V_33 ++ ) {
if ( V_28 [ V_32 ] . V_43 != V_42 [ V_33 ] . V_44 )
continue;
F_10 ( & V_8 , V_28 [ V_32 ] . V_43 ) ;
F_9 ( & V_8 , ( const unsigned char
* ) & V_28 [ V_32 ] . V_24 ,
V_45 [ V_42 [ V_33 ] . V_46 ] ) ;
}
}
V_5 = F_4 ( V_2 , NULL , V_8 . V_47 , V_48 , 0 , 0 ,
L_2 ) ;
F_11 ( & V_8 ) ;
return V_5 ;
}
int F_12 ( struct V_1 * V_2 , T_1 * V_49 , T_3 V_50 )
{
struct V_6 V_7 ;
T_2 V_51 , V_52 ;
T_2 V_53 ;
int V_54 ;
int V_55 = 0 ;
int V_56 = 5 ;
T_1 * V_57 = V_49 ;
V_53 = F_13 ( T_2 , V_50 , sizeof( V_7 . V_14 . V_58 . V_59 ) ) ;
if ( ! V_49 || ! V_53 ||
V_50 > sizeof( V_7 . V_14 . V_58 . V_59 ) )
return - V_10 ;
do {
V_7 . V_11 . V_12 = V_60 ;
V_7 . V_14 . V_61 . V_62 = F_3 ( V_53 ) ;
V_54 = F_4 ( V_2 , NULL , & V_7 , sizeof( V_7 ) ,
F_14 ( struct V_63 ,
V_59 ) ,
0 , L_3 ) ;
if ( V_54 )
break;
V_51 = F_13 ( T_2 , F_15 ( V_7 . V_14 . V_58 . V_62 ) ,
V_53 ) ;
V_52 = F_16 ( V_7 . V_11 . V_49 . V_64 ) ;
if ( V_52 < F_14 ( struct V_63 , V_59 ) +
V_51 )
return - V_65 ;
memcpy ( V_57 , V_7 . V_14 . V_58 . V_59 , V_51 ) ;
V_57 += V_51 ;
V_55 += V_51 ;
V_53 -= V_51 ;
} while ( V_56 -- && V_55 < V_50 );
return V_55 ? V_55 : - V_66 ;
}
void F_17 ( struct V_1 * V_2 , T_2 V_37 ,
unsigned int V_67 )
{
struct V_29 V_8 ;
int V_5 ;
V_5 = F_7 ( & V_8 , V_68 , V_69 ) ;
if ( V_5 ) {
F_18 ( & V_2 -> V_70 , L_4 ,
V_37 ) ;
return;
}
F_8 ( & V_8 , V_37 ) ;
( void ) F_4 ( V_2 , NULL , V_8 . V_47 , V_48 , 0 , V_67 ,
L_5 ) ;
F_11 ( & V_8 ) ;
}
static void F_19 ( struct V_29 * V_8 , T_2 V_71 ,
const T_1 * V_72 , T_4 V_73 ,
T_1 V_40 ,
const T_1 * V_74 , T_4 V_75 )
{
F_8 ( V_8 , 9 + V_73 + V_75 ) ;
F_8 ( V_8 , V_71 ) ;
F_10 ( V_8 , V_73 ) ;
if ( V_72 && V_73 )
F_9 ( V_8 , V_72 , V_73 ) ;
F_20 ( V_8 , V_40 ) ;
F_10 ( V_8 , V_75 ) ;
if ( V_74 && V_75 )
F_9 ( V_8 , V_74 , V_75 ) ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_78 * V_79 )
{
unsigned int V_80 ;
struct V_29 V_8 ;
T_2 V_81 , V_52 ;
int V_32 ;
int V_5 ;
for ( V_32 = 0 ; V_32 < F_6 ( V_42 ) ; V_32 ++ ) {
if ( V_79 -> V_81 == V_42 [ V_32 ] . V_46 ) {
V_81 = V_42 [ V_32 ] . V_44 ;
break;
}
}
if ( V_32 == F_6 ( V_42 ) )
return - V_10 ;
V_5 = F_7 ( & V_8 , V_35 , V_82 ) ;
if ( V_5 )
return V_5 ;
F_8 ( & V_8 , V_79 -> V_83 ) ;
F_19 ( & V_8 , V_38 ,
NULL , 0 ,
0 ,
V_79 -> V_84 ,
V_25 ) ;
F_10 ( & V_8 , 4 + V_25 + V_77 -> V_85 + 1 ) ;
F_10 ( & V_8 , V_25 ) ;
F_9 ( & V_8 , V_79 -> V_86 , V_25 ) ;
F_10 ( & V_8 , V_77 -> V_85 + 1 ) ;
F_9 ( & V_8 , V_77 -> V_87 , V_77 -> V_85 ) ;
F_20 ( & V_8 , V_77 -> V_88 ) ;
F_10 ( & V_8 , 14 + V_79 -> V_89 ) ;
F_10 ( & V_8 , V_90 ) ;
F_10 ( & V_8 , V_81 ) ;
if ( V_79 -> V_89 ) {
F_8 ( & V_8 , 0 ) ;
F_10 ( & V_8 , V_79 -> V_89 ) ;
F_9 ( & V_8 , V_79 -> V_91 ,
V_79 -> V_89 ) ;
} else {
F_8 ( & V_8 , V_92 ) ;
F_10 ( & V_8 , 0 ) ;
}
F_10 ( & V_8 , V_93 ) ;
F_10 ( & V_8 , 0 ) ;
F_10 ( & V_8 , 0 ) ;
F_8 ( & V_8 , 0 ) ;
if ( V_8 . V_67 & V_94 ) {
V_5 = - V_95 ;
goto V_49;
}
V_5 = F_4 ( V_2 , NULL , V_8 . V_47 , V_48 , 4 , 0 ,
L_6 ) ;
if ( V_5 )
goto V_49;
V_80 = F_22 ( ( V_96 * ) & V_8 . V_47 [ V_97 ] ) ;
if ( V_80 > V_98 ) {
V_5 = - V_95 ;
goto V_49;
}
V_52 = F_16 ( ( (struct V_6 * ) & V_8 ) -> V_11 . V_49 . V_64 ) ;
if ( V_52 < V_97 + 4 + V_80 ) {
V_5 = - V_65 ;
goto V_49;
}
memcpy ( V_77 -> V_99 , & V_8 . V_47 [ V_97 + 4 ] , V_80 ) ;
V_77 -> V_80 = V_80 ;
V_49:
F_11 ( & V_8 ) ;
if ( V_5 > 0 ) {
if ( F_23 ( V_5 ) == V_100 )
V_5 = - V_10 ;
else
V_5 = - V_101 ;
}
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_78 * V_79 ,
T_2 * V_102 , unsigned int V_67 )
{
struct V_29 V_8 ;
unsigned int V_103 ;
unsigned int V_104 ;
unsigned int V_80 ;
int V_5 ;
V_103 = F_25 ( ( V_105 * ) & V_77 -> V_99 [ 0 ] ) ;
if ( V_103 > ( V_77 -> V_80 - 2 ) )
return - V_95 ;
V_104 = F_25 ( ( V_105 * ) & V_77 -> V_99 [ 2 + V_103 ] ) ;
V_80 = V_103 + V_104 + 4 ;
if ( V_80 > V_77 -> V_80 )
return - V_95 ;
V_5 = F_7 ( & V_8 , V_35 , V_106 ) ;
if ( V_5 )
return V_5 ;
F_8 ( & V_8 , V_79 -> V_83 ) ;
F_19 ( & V_8 , V_38 ,
NULL , 0 ,
0 ,
V_79 -> V_84 ,
V_25 ) ;
F_9 ( & V_8 , V_77 -> V_99 , V_80 ) ;
if ( V_8 . V_67 & V_94 ) {
V_5 = - V_95 ;
goto V_49;
}
V_5 = F_4 ( V_2 , NULL , V_8 . V_47 , V_48 , 4 , V_67 ,
L_7 ) ;
if ( ! V_5 )
* V_102 = F_22 (
( V_96 * ) & V_8 . V_47 [ V_97 ] ) ;
V_49:
F_11 ( & V_8 ) ;
if ( V_5 > 0 )
V_5 = - V_101 ;
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_78 * V_79 ,
T_2 V_102 , unsigned int V_67 )
{
struct V_29 V_8 ;
T_4 V_107 ;
T_1 * V_47 ;
int V_5 ;
T_2 V_52 ;
V_5 = F_7 ( & V_8 , V_35 , V_108 ) ;
if ( V_5 )
return V_5 ;
F_8 ( & V_8 , V_102 ) ;
F_19 ( & V_8 ,
V_79 -> V_109 ?
V_79 -> V_109 : V_38 ,
NULL , 0 ,
V_110 ,
V_79 -> V_86 ,
V_25 ) ;
V_5 = F_4 ( V_2 , NULL , V_8 . V_47 , V_48 , 6 , V_67 ,
L_8 ) ;
if ( V_5 > 0 )
V_5 = - V_101 ;
if ( ! V_5 ) {
V_107 = F_25 (
( V_105 * ) & V_8 . V_47 [ V_97 + 4 ] ) ;
V_52 = F_16 ( ( (struct V_6 * ) & V_8 )
-> V_11 . V_49 . V_64 ) ;
if ( V_52 < V_97 + 6 + V_107 ) {
V_5 = - V_65 ;
goto V_49;
}
V_47 = & V_8 . V_47 [ V_97 + 6 ] ;
memcpy ( V_77 -> V_87 , V_47 , V_107 - 1 ) ;
V_77 -> V_85 = V_107 - 1 ;
V_77 -> V_88 = V_47 [ V_107 - 1 ] ;
}
V_49:
F_11 ( & V_8 ) ;
return V_5 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_78 * V_79 )
{
T_2 V_102 ;
int V_5 ;
F_28 ( & V_2 -> V_111 ) ;
V_5 = F_24 ( V_2 , V_77 , V_79 , & V_102 ,
V_112 ) ;
if ( V_5 )
goto V_49;
V_5 = F_26 ( V_2 , V_77 , V_79 , V_102 ,
V_112 ) ;
F_17 ( V_2 , V_102 , V_112 ) ;
V_49:
F_29 ( & V_2 -> V_111 ) ;
return V_5 ;
}
T_5 F_30 ( struct V_1 * V_2 , T_2 V_113 , T_2 * V_114 ,
const char * V_115 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_116 ;
V_7 . V_14 . V_117 . V_118 = F_2 ( V_119 ) ;
V_7 . V_14 . V_117 . V_113 = F_2 ( V_113 ) ;
V_7 . V_14 . V_117 . V_120 = F_2 ( 1 ) ;
V_5 = F_4 ( V_2 , NULL , & V_7 , sizeof( V_7 ) ,
V_121 , 0 , V_115 ) ;
if ( ! V_5 )
* V_114 = F_16 ( V_7 . V_14 . V_122 . V_114 ) ;
return V_5 ;
}
static int F_31 ( struct V_1 * V_2 , T_4 V_123 )
{
struct V_6 V_7 ;
V_7 . V_11 . V_12 = V_124 ;
V_7 . V_14 . V_125 . V_123 = F_3 ( V_123 ) ;
return F_4 ( V_2 , NULL , & V_7 , sizeof( V_7 ) , 0 , 0 ,
L_9 ) ;
}
void F_32 ( struct V_1 * V_2 , T_4 V_126 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_127 ;
V_7 . V_14 . V_125 . V_123 = F_3 ( V_126 ) ;
V_5 = F_4 ( V_2 , NULL , & V_7 , sizeof( V_7 ) , 0 , 0 ,
L_10 ) ;
if ( V_5 < 0 )
F_18 ( & V_2 -> V_70 , L_11 ,
V_5 ) ;
}
unsigned long F_33 ( struct V_1 * V_2 , T_2 V_128 )
{
int V_129 = V_130 ;
int V_131 = 0 ;
if ( V_128 >= V_132 && V_128 <= V_133 )
V_129 = V_134 [ V_128 - V_132 ] ;
if ( V_129 != V_130 )
V_131 = V_2 -> V_131 [ V_129 ] ;
if ( V_131 <= 0 )
V_131 = 2 * 60 * V_135 ;
return V_131 ;
}
static int F_34 ( struct V_1 * V_2 , bool V_136 )
{
int V_5 ;
struct V_6 V_7 ;
V_7 . V_11 . V_12 = V_137 ;
V_7 . V_14 . V_138 . V_139 = V_136 ;
V_5 = F_4 ( V_2 , NULL , & V_7 , V_140 , 0 , 0 ,
L_12 ) ;
if ( V_5 == V_141 ) {
F_18 ( & V_2 -> V_70 , L_13 ) ;
V_5 = 0 ;
}
return V_5 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned int V_142 ;
unsigned int V_143 = 100 ;
unsigned long V_131 ;
struct V_6 V_7 ;
int V_32 ;
V_131 = F_33 ( V_2 , V_144 ) ;
V_142 = F_36 ( V_131 ) / V_143 ;
V_5 = F_34 ( V_2 , true ) ;
if ( V_5 )
return V_5 ;
for ( V_32 = 0 ; V_32 < V_142 ; V_32 ++ ) {
V_7 . V_11 . V_12 = V_13 ;
V_7 . V_14 . V_15 . V_16 = F_2 ( 1 ) ;
V_7 . V_14 . V_15 . V_17 = F_3 ( V_18 ) ;
V_7 . V_14 . V_15 . V_19 = V_20 ;
V_7 . V_14 . V_15 . V_21 [ 0 ] = 0x01 ;
V_7 . V_14 . V_15 . V_21 [ 1 ] = 0x00 ;
V_7 . V_14 . V_15 . V_21 [ 2 ] = 0x00 ;
V_5 = F_4 ( V_2 , NULL , & V_7 , sizeof( V_7 ) , 0 , 0 ,
NULL ) ;
if ( V_5 < 0 )
break;
V_5 = F_16 ( V_7 . V_11 . V_49 . V_145 ) ;
if ( V_5 != V_141 )
break;
F_37 ( V_143 ) ;
}
return V_5 ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_6 V_7 ;
int V_5 ;
V_7 . V_11 . V_12 = V_116 ;
V_7 . V_14 . V_117 . V_118 = F_2 ( V_119 ) ;
V_7 . V_14 . V_117 . V_113 = F_2 ( 0x100 ) ;
V_7 . V_14 . V_117 . V_120 = F_2 ( 1 ) ;
V_5 = F_4 ( V_2 , NULL , & V_7 , sizeof( V_7 ) , 0 , 0 , NULL ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_15 ( V_7 . V_11 . V_49 . V_146 ) == V_68 )
V_2 -> V_67 |= V_147 ;
return 0 ;
}
static T_5 F_39 ( struct V_1 * V_2 )
{
struct V_148 V_149 ;
struct V_29 V_8 ;
void * V_150 ;
void * V_151 ;
void * V_152 ;
unsigned int V_26 ;
T_2 V_153 ;
T_2 V_154 ;
int V_5 ;
int V_32 = 0 ;
V_5 = F_7 ( & V_8 , V_68 , V_155 ) ;
if ( V_5 )
return V_5 ;
F_8 ( & V_8 , V_156 ) ;
F_8 ( & V_8 , 0 ) ;
F_8 ( & V_8 , 1 ) ;
V_5 = F_4 ( V_2 , NULL , V_8 . V_47 , V_48 , 9 , 0 ,
L_14 ) ;
if ( V_5 )
goto V_49;
V_26 = F_22 (
( V_96 * ) & V_8 . V_47 [ V_97 + 5 ] ) ;
if ( V_26 > F_6 ( V_2 -> V_34 ) ) {
V_5 = - V_157 ;
goto V_49;
}
V_150 = & V_8 . V_47 [ V_97 + 9 ] ;
V_154 = F_22 ( ( V_96 * ) & V_8 . V_47 [ 2 ] ) ;
V_151 = & V_8 . V_47 [ V_154 ] ;
for ( V_32 = 0 ; V_32 < V_26 ; V_32 ++ ) {
V_152 = V_150 +
F_14 ( struct V_148 , V_158 ) ;
if ( V_152 >= V_151 ) {
V_5 = - V_65 ;
break;
}
memcpy ( & V_149 , V_150 , sizeof( V_149 ) ) ;
V_2 -> V_34 [ V_32 ] = F_15 ( V_149 . V_17 ) ;
V_153 = sizeof( V_149 . V_17 ) +
sizeof( V_149 . V_158 ) +
V_149 . V_158 ;
V_150 = V_150 + V_153 ;
}
V_49:
if ( V_32 < F_6 ( V_2 -> V_34 ) )
V_2 -> V_34 [ V_32 ] = V_159 ;
F_11 ( & V_8 ) ;
return V_5 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_29 V_8 ;
T_2 V_160 ;
T_2 * V_161 ;
T_2 V_162 ;
int V_32 ;
int V_5 ;
V_5 = F_30 ( V_2 , V_163 , & V_160 , NULL ) ;
if ( V_5 )
goto V_49;
if ( V_160 > 0xFFFFF ) {
V_5 = - V_65 ;
goto V_49;
}
V_2 -> V_164 = F_41 ( & V_2 -> V_70 , 4 * V_160 ,
V_165 ) ;
V_5 = F_7 ( & V_8 , V_68 , V_155 ) ;
if ( V_5 )
goto V_49;
F_8 ( & V_8 , V_166 ) ;
F_8 ( & V_8 , V_132 ) ;
F_8 ( & V_8 , V_160 ) ;
V_5 = F_4 ( V_2 , NULL , V_8 . V_47 , V_48 ,
9 + 4 * V_160 , 0 , NULL ) ;
if ( V_5 ) {
F_11 ( & V_8 ) ;
goto V_49;
}
if ( V_160 !=
F_22 ( ( V_96 * ) & V_8 . V_47 [ V_97 + 5 ] ) ) {
F_11 ( & V_8 ) ;
goto V_49;
}
V_2 -> V_160 = V_160 ;
V_161 = ( T_2 * ) & V_8 . V_47 [ V_97 + 9 ] ;
for ( V_32 = 0 ; V_32 < V_160 ; V_32 ++ , V_161 ++ ) {
V_2 -> V_164 [ V_32 ] = F_22 ( V_161 ) ;
V_162 = V_2 -> V_164 [ V_32 ] & 0xFFFF ;
if ( V_162 == V_167 || V_162 == V_69 ) {
V_2 -> V_164 [ V_32 ] &=
~ ( F_42 ( 2 , 0 ) << V_168 ) ;
V_2 -> V_164 [ V_32 ] |= 1 << V_168 ;
}
}
F_11 ( & V_8 ) ;
V_49:
if ( V_5 > 0 )
V_5 = - V_157 ;
return V_5 ;
}
int F_43 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_44 ( V_2 ) ;
if ( V_5 )
goto V_49;
V_5 = F_35 ( V_2 ) ;
if ( V_5 != 0 && V_5 != V_169 ) {
F_45 ( & V_2 -> V_70 , L_15 ) ;
goto V_49;
}
if ( V_5 == V_169 ) {
V_5 = F_31 ( V_2 , V_170 ) ;
if ( V_5 )
goto V_49;
V_5 = F_35 ( V_2 ) ;
if ( V_5 ) {
F_45 ( & V_2 -> V_70 , L_15 ) ;
goto V_49;
}
}
V_5 = F_39 ( V_2 ) ;
if ( V_5 )
goto V_49;
V_5 = F_40 ( V_2 ) ;
V_49:
if ( V_5 > 0 )
V_5 = - V_157 ;
return V_5 ;
}
int F_46 ( struct V_1 * V_2 , T_2 V_162 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_160 ; V_32 ++ )
if ( V_162 == ( V_2 -> V_164 [ V_32 ] & F_42 ( 15 , 0 ) ) )
return V_32 ;
return - 1 ;
}
