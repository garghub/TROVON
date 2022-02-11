int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
int V_5 ;
struct V_6 V_7 ;
struct V_8 * V_9 ;
T_1 V_10 [ V_11 ] = { 0 } ;
if ( V_3 >= V_12 )
return - V_13 ;
V_5 = F_2 ( & V_7 , V_14 , V_15 ) ;
if ( V_5 )
return V_5 ;
V_10 [ V_3 >> 3 ] = 1 << ( V_3 & 0x7 ) ;
F_3 ( & V_7 , 1 ) ;
F_4 ( & V_7 , V_16 ) ;
F_5 ( & V_7 , V_11 ) ;
F_6 ( & V_7 , ( const unsigned char * ) V_10 ,
sizeof( V_10 ) ) ;
V_5 = F_7 ( V_2 , NULL , V_7 . V_17 , V_18 , 0 , 0 ,
V_4 ? L_1 : NULL ) ;
if ( V_5 == 0 && V_4 ) {
V_9 = (struct V_8 * ) & V_7 . V_17 [ V_19 ] ;
memcpy ( V_4 , V_9 -> V_20 , V_21 ) ;
}
F_8 ( & V_7 ) ;
return V_5 ;
}
int F_9 ( struct V_1 * V_2 , int V_3 , T_2 V_22 ,
struct V_23 * V_24 )
{
struct V_6 V_7 ;
struct V_25 V_26 ;
int V_5 ;
int V_27 ;
int V_28 ;
if ( V_22 > F_10 ( V_2 -> V_29 ) )
return - V_13 ;
V_5 = F_2 ( & V_7 , V_30 , V_31 ) ;
if ( V_5 )
return V_5 ;
F_3 ( & V_7 , V_3 ) ;
V_26 . V_32 = F_11 ( V_33 ) ;
V_26 . V_34 = 0 ;
V_26 . V_35 = 0 ;
V_26 . V_36 = 0 ;
F_3 ( & V_7 , sizeof( struct V_25 ) ) ;
F_6 ( & V_7 , ( const unsigned char * ) & V_26 ,
sizeof( V_26 ) ) ;
F_3 ( & V_7 , V_22 ) ;
for ( V_27 = 0 ; V_27 < V_22 ; V_27 ++ ) {
for ( V_28 = 0 ; V_28 < F_10 ( V_37 ) ; V_28 ++ ) {
if ( V_24 [ V_27 ] . V_38 != V_37 [ V_28 ] . V_39 )
continue;
F_4 ( & V_7 , V_24 [ V_27 ] . V_38 ) ;
F_6 ( & V_7 , ( const unsigned char
* ) & V_24 [ V_27 ] . V_20 ,
V_40 [ V_37 [ V_28 ] . V_41 ] ) ;
}
}
V_5 = F_7 ( V_2 , NULL , V_7 . V_17 , V_18 , 0 , 0 ,
L_2 ) ;
F_8 ( & V_7 ) ;
return V_5 ;
}
int F_12 ( struct V_1 * V_2 , T_1 * V_9 , T_3 V_42 )
{
struct V_43 V_44 ;
T_2 V_45 , V_46 ;
T_2 V_47 ;
int V_48 ;
int V_49 = 0 ;
int V_50 = 5 ;
T_1 * V_51 = V_9 ;
V_47 = F_13 ( T_2 , V_42 , sizeof( V_44 . V_52 . V_53 . V_54 ) ) ;
if ( ! V_9 || ! V_47 ||
V_42 > sizeof( V_44 . V_52 . V_53 . V_54 ) )
return - V_13 ;
do {
V_44 . V_55 . V_56 = V_57 ;
V_44 . V_52 . V_58 . V_59 = F_14 ( V_47 ) ;
V_48 = F_7 ( V_2 , NULL , & V_44 , sizeof( V_44 ) ,
F_15 ( struct V_60 ,
V_54 ) ,
0 , L_3 ) ;
if ( V_48 )
break;
V_45 = F_13 ( T_2 , F_16 ( V_44 . V_52 . V_53 . V_59 ) ,
V_47 ) ;
V_46 = F_17 ( V_44 . V_55 . V_9 . V_61 ) ;
if ( V_46 < F_15 ( struct V_60 , V_54 ) +
V_45 )
return - V_62 ;
memcpy ( V_51 , V_44 . V_52 . V_53 . V_54 , V_45 ) ;
V_51 += V_45 ;
V_49 += V_45 ;
V_47 -= V_45 ;
} while ( V_50 -- && V_49 < V_42 );
return V_49 ? V_49 : - V_63 ;
}
void F_18 ( struct V_1 * V_2 , T_2 V_32 ,
unsigned int V_64 )
{
struct V_6 V_7 ;
int V_5 ;
V_5 = F_2 ( & V_7 , V_14 , V_65 ) ;
if ( V_5 ) {
F_19 ( & V_2 -> V_66 , L_4 ,
V_32 ) ;
return;
}
F_3 ( & V_7 , V_32 ) ;
( void ) F_7 ( V_2 , NULL , V_7 . V_17 , V_18 , 0 , V_64 ,
L_5 ) ;
F_8 ( & V_7 ) ;
}
static void F_20 ( struct V_6 * V_7 , T_2 V_67 ,
const T_1 * V_68 , T_4 V_69 ,
T_1 V_35 ,
const T_1 * V_70 , T_4 V_71 )
{
F_3 ( V_7 , 9 + V_69 + V_71 ) ;
F_3 ( V_7 , V_67 ) ;
F_4 ( V_7 , V_69 ) ;
if ( V_68 && V_69 )
F_6 ( V_7 , V_68 , V_69 ) ;
F_5 ( V_7 , V_35 ) ;
F_4 ( V_7 , V_71 ) ;
if ( V_70 && V_71 )
F_6 ( V_7 , V_70 , V_71 ) ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
struct V_74 * V_75 )
{
unsigned int V_76 ;
struct V_6 V_7 ;
T_2 V_77 , V_46 ;
int V_27 ;
int V_5 ;
for ( V_27 = 0 ; V_27 < F_10 ( V_37 ) ; V_27 ++ ) {
if ( V_75 -> V_77 == V_37 [ V_27 ] . V_41 ) {
V_77 = V_37 [ V_27 ] . V_39 ;
break;
}
}
if ( V_27 == F_10 ( V_37 ) )
return - V_13 ;
V_5 = F_2 ( & V_7 , V_30 , V_78 ) ;
if ( V_5 )
return V_5 ;
F_3 ( & V_7 , V_75 -> V_79 ) ;
F_20 ( & V_7 , V_33 ,
NULL , 0 ,
0 ,
V_75 -> V_80 ,
V_81 ) ;
F_4 ( & V_7 , 4 + V_81 + V_73 -> V_82 + 1 ) ;
F_4 ( & V_7 , V_81 ) ;
F_6 ( & V_7 , V_75 -> V_83 , V_81 ) ;
F_4 ( & V_7 , V_73 -> V_82 + 1 ) ;
F_6 ( & V_7 , V_73 -> V_84 , V_73 -> V_82 ) ;
F_5 ( & V_7 , V_73 -> V_85 ) ;
F_4 ( & V_7 , 14 + V_75 -> V_86 ) ;
F_4 ( & V_7 , V_87 ) ;
F_4 ( & V_7 , V_77 ) ;
if ( V_75 -> V_86 ) {
F_3 ( & V_7 , 0 ) ;
F_4 ( & V_7 , V_75 -> V_86 ) ;
F_6 ( & V_7 , V_75 -> V_88 ,
V_75 -> V_86 ) ;
} else {
F_3 ( & V_7 , V_89 ) ;
F_4 ( & V_7 , 0 ) ;
}
F_4 ( & V_7 , V_90 ) ;
F_4 ( & V_7 , 0 ) ;
F_4 ( & V_7 , 0 ) ;
F_3 ( & V_7 , 0 ) ;
if ( V_7 . V_64 & V_91 ) {
V_5 = - V_92 ;
goto V_9;
}
V_5 = F_7 ( V_2 , NULL , V_7 . V_17 , V_18 , 4 , 0 ,
L_6 ) ;
if ( V_5 )
goto V_9;
V_76 = F_22 ( ( V_93 * ) & V_7 . V_17 [ V_19 ] ) ;
if ( V_76 > V_94 ) {
V_5 = - V_92 ;
goto V_9;
}
V_46 = F_17 ( ( (struct V_43 * ) & V_7 ) -> V_55 . V_9 . V_61 ) ;
if ( V_46 < V_19 + 4 + V_76 ) {
V_5 = - V_62 ;
goto V_9;
}
memcpy ( V_73 -> V_95 , & V_7 . V_17 [ V_19 + 4 ] , V_76 ) ;
V_73 -> V_76 = V_76 ;
V_9:
F_8 ( & V_7 ) ;
if ( V_5 > 0 ) {
if ( F_23 ( V_5 ) == V_96 )
V_5 = - V_13 ;
else
V_5 = - V_97 ;
}
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
struct V_74 * V_75 ,
T_2 * V_98 , unsigned int V_64 )
{
struct V_6 V_7 ;
unsigned int V_99 ;
unsigned int V_100 ;
unsigned int V_76 ;
int V_5 ;
V_99 = F_25 ( ( V_101 * ) & V_73 -> V_95 [ 0 ] ) ;
if ( V_99 > ( V_73 -> V_76 - 2 ) )
return - V_92 ;
V_100 = F_25 ( ( V_101 * ) & V_73 -> V_95 [ 2 + V_99 ] ) ;
V_76 = V_99 + V_100 + 4 ;
if ( V_76 > V_73 -> V_76 )
return - V_92 ;
V_5 = F_2 ( & V_7 , V_30 , V_102 ) ;
if ( V_5 )
return V_5 ;
F_3 ( & V_7 , V_75 -> V_79 ) ;
F_20 ( & V_7 , V_33 ,
NULL , 0 ,
0 ,
V_75 -> V_80 ,
V_81 ) ;
F_6 ( & V_7 , V_73 -> V_95 , V_76 ) ;
if ( V_7 . V_64 & V_91 ) {
V_5 = - V_92 ;
goto V_9;
}
V_5 = F_7 ( V_2 , NULL , V_7 . V_17 , V_18 , 4 , V_64 ,
L_7 ) ;
if ( ! V_5 )
* V_98 = F_22 (
( V_93 * ) & V_7 . V_17 [ V_19 ] ) ;
V_9:
F_8 ( & V_7 ) ;
if ( V_5 > 0 )
V_5 = - V_97 ;
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
struct V_74 * V_75 ,
T_2 V_98 , unsigned int V_64 )
{
struct V_6 V_7 ;
T_4 V_103 ;
T_1 * V_17 ;
int V_5 ;
T_2 V_46 ;
V_5 = F_2 ( & V_7 , V_30 , V_104 ) ;
if ( V_5 )
return V_5 ;
F_3 ( & V_7 , V_98 ) ;
F_20 ( & V_7 ,
V_75 -> V_105 ?
V_75 -> V_105 : V_33 ,
NULL , 0 ,
V_106 ,
V_75 -> V_83 ,
V_81 ) ;
V_5 = F_7 ( V_2 , NULL , V_7 . V_17 , V_18 , 6 , V_64 ,
L_8 ) ;
if ( V_5 > 0 )
V_5 = - V_97 ;
if ( ! V_5 ) {
V_103 = F_25 (
( V_101 * ) & V_7 . V_17 [ V_19 + 4 ] ) ;
V_46 = F_17 ( ( (struct V_43 * ) & V_7 )
-> V_55 . V_9 . V_61 ) ;
if ( V_46 < V_19 + 6 + V_103 ) {
V_5 = - V_62 ;
goto V_9;
}
V_17 = & V_7 . V_17 [ V_19 + 6 ] ;
memcpy ( V_73 -> V_84 , V_17 , V_103 - 1 ) ;
V_73 -> V_82 = V_103 - 1 ;
V_73 -> V_85 = V_17 [ V_103 - 1 ] ;
}
V_9:
F_8 ( & V_7 ) ;
return V_5 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
struct V_74 * V_75 )
{
T_2 V_98 ;
int V_5 ;
F_28 ( & V_2 -> V_107 ) ;
V_5 = F_24 ( V_2 , V_73 , V_75 , & V_98 ,
V_108 ) ;
if ( V_5 )
goto V_9;
V_5 = F_26 ( V_2 , V_73 , V_75 , V_98 ,
V_108 ) ;
F_18 ( V_2 , V_98 , V_108 ) ;
V_9:
F_29 ( & V_2 -> V_107 ) ;
return V_5 ;
}
T_5 F_30 ( struct V_1 * V_2 , T_2 V_109 , T_2 * V_110 ,
const char * V_111 )
{
struct V_43 V_44 ;
int V_5 ;
V_44 . V_55 . V_56 = V_112 ;
V_44 . V_52 . V_113 . V_114 = F_11 ( V_115 ) ;
V_44 . V_52 . V_113 . V_109 = F_11 ( V_109 ) ;
V_44 . V_52 . V_113 . V_116 = F_11 ( 1 ) ;
V_5 = F_7 ( V_2 , NULL , & V_44 , sizeof( V_44 ) ,
V_117 , 0 , V_111 ) ;
if ( ! V_5 )
* V_110 = F_17 ( V_44 . V_52 . V_118 . V_110 ) ;
return V_5 ;
}
void F_31 ( struct V_1 * V_2 , T_4 V_119 )
{
struct V_43 V_44 ;
int V_5 ;
V_44 . V_55 . V_56 = V_120 ;
V_44 . V_52 . V_121 . V_122 = F_14 ( V_119 ) ;
V_5 = F_7 ( V_2 , NULL , & V_44 , sizeof( V_44 ) , 0 , 0 ,
L_9 ) ;
if ( V_5 < 0 && V_5 != - V_123 )
F_19 ( & V_2 -> V_66 , L_10 ,
V_5 ) ;
}
unsigned long F_32 ( struct V_1 * V_2 , T_2 V_124 )
{
int V_125 = V_126 ;
int V_127 = 0 ;
if ( V_124 >= V_128 && V_124 <= V_129 )
V_125 = V_130 [ V_124 - V_128 ] ;
if ( V_125 != V_126 )
V_127 = V_2 -> V_127 [ V_125 ] ;
if ( V_127 <= 0 )
V_127 = 2 * 60 * V_131 ;
return V_127 ;
}
static int F_33 ( struct V_1 * V_2 , bool V_132 )
{
int V_5 ;
struct V_43 V_44 ;
V_44 . V_55 . V_56 = V_133 ;
V_44 . V_52 . V_134 . V_135 = V_132 ;
V_5 = F_7 ( V_2 , NULL , & V_44 , V_136 , 0 , 0 ,
L_11 ) ;
if ( V_5 == V_137 ) {
F_19 ( & V_2 -> V_66 , L_12 ) ;
V_5 = 0 ;
}
return V_5 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned int V_138 ;
unsigned int V_139 = 100 ;
unsigned long V_127 ;
int V_27 ;
V_127 = F_32 ( V_2 , V_140 ) ;
V_138 = F_35 ( V_127 ) / V_139 ;
V_5 = F_33 ( V_2 , true ) ;
if ( V_5 )
return V_5 ;
for ( V_27 = 0 ; V_27 < V_138 ; V_27 ++ ) {
V_5 = F_1 ( V_2 , 0 , NULL ) ;
if ( V_5 < 0 )
break;
if ( V_5 != V_137 )
break;
F_36 ( V_139 ) ;
}
return V_5 ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_43 V_44 ;
int V_5 ;
V_44 . V_55 . V_56 = V_112 ;
V_44 . V_52 . V_113 . V_114 = F_11 ( V_115 ) ;
V_44 . V_52 . V_113 . V_109 = F_11 ( 0x100 ) ;
V_44 . V_52 . V_113 . V_116 = F_11 ( 1 ) ;
V_5 = F_7 ( V_2 , NULL , & V_44 , sizeof( V_44 ) , 0 , 0 , NULL ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_16 ( V_44 . V_55 . V_9 . V_141 ) == V_14 )
V_2 -> V_64 |= V_142 ;
return 0 ;
}
static T_5 F_38 ( struct V_1 * V_2 )
{
struct V_143 V_144 ;
struct V_6 V_7 ;
void * V_145 ;
void * V_146 ;
void * V_147 ;
unsigned int V_22 ;
T_2 V_148 ;
T_2 V_149 ;
int V_5 ;
int V_27 = 0 ;
V_5 = F_2 ( & V_7 , V_14 , V_150 ) ;
if ( V_5 )
return V_5 ;
F_3 ( & V_7 , V_151 ) ;
F_3 ( & V_7 , 0 ) ;
F_3 ( & V_7 , 1 ) ;
V_5 = F_7 ( V_2 , NULL , V_7 . V_17 , V_18 , 9 , 0 ,
L_13 ) ;
if ( V_5 )
goto V_9;
V_22 = F_22 (
( V_93 * ) & V_7 . V_17 [ V_19 + 5 ] ) ;
if ( V_22 > F_10 ( V_2 -> V_29 ) ) {
V_5 = - V_152 ;
goto V_9;
}
V_145 = & V_7 . V_17 [ V_19 + 9 ] ;
V_149 = F_22 ( ( V_93 * ) & V_7 . V_17 [ 2 ] ) ;
V_146 = & V_7 . V_17 [ V_149 ] ;
for ( V_27 = 0 ; V_27 < V_22 ; V_27 ++ ) {
V_147 = V_145 +
F_15 ( struct V_143 , V_153 ) ;
if ( V_147 >= V_146 ) {
V_5 = - V_62 ;
break;
}
memcpy ( & V_144 , V_145 , sizeof( V_144 ) ) ;
V_2 -> V_29 [ V_27 ] = F_16 ( V_144 . V_154 ) ;
V_148 = sizeof( V_144 . V_154 ) +
sizeof( V_144 . V_153 ) +
V_144 . V_153 ;
V_145 = V_145 + V_148 ;
}
V_9:
if ( V_27 < F_10 ( V_2 -> V_29 ) )
V_2 -> V_29 [ V_27 ] = V_155 ;
F_8 ( & V_7 ) ;
return V_5 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_6 V_7 ;
T_2 V_156 ;
T_2 * V_157 ;
T_2 V_158 ;
int V_27 ;
int V_5 ;
V_5 = F_30 ( V_2 , V_159 , & V_156 , NULL ) ;
if ( V_5 )
goto V_9;
if ( V_156 > 0xFFFFF ) {
V_5 = - V_62 ;
goto V_9;
}
V_2 -> V_160 = F_40 ( & V_2 -> V_66 , 4 * V_156 ,
V_161 ) ;
V_5 = F_2 ( & V_7 , V_14 , V_150 ) ;
if ( V_5 )
goto V_9;
F_3 ( & V_7 , V_162 ) ;
F_3 ( & V_7 , V_128 ) ;
F_3 ( & V_7 , V_156 ) ;
V_5 = F_7 ( V_2 , NULL , V_7 . V_17 , V_18 ,
9 + 4 * V_156 , 0 , NULL ) ;
if ( V_5 ) {
F_8 ( & V_7 ) ;
goto V_9;
}
if ( V_156 !=
F_22 ( ( V_93 * ) & V_7 . V_17 [ V_19 + 5 ] ) ) {
F_8 ( & V_7 ) ;
goto V_9;
}
V_2 -> V_156 = V_156 ;
V_157 = ( T_2 * ) & V_7 . V_17 [ V_19 + 9 ] ;
for ( V_27 = 0 ; V_27 < V_156 ; V_27 ++ , V_157 ++ ) {
V_2 -> V_160 [ V_27 ] = F_22 ( V_157 ) ;
V_158 = V_2 -> V_160 [ V_27 ] & 0xFFFF ;
if ( V_158 == V_163 || V_158 == V_65 ) {
V_2 -> V_160 [ V_27 ] &=
~ ( F_41 ( 2 , 0 ) << V_164 ) ;
V_2 -> V_160 [ V_27 ] |= 1 << V_164 ;
}
}
F_8 ( & V_7 ) ;
V_9:
if ( V_5 > 0 )
V_5 = - V_152 ;
return V_5 ;
}
int F_42 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_43 ( V_2 ) ;
if ( V_5 )
goto V_9;
V_5 = F_34 ( V_2 ) ;
if ( V_5 != 0 && V_5 != V_165 ) {
F_44 ( & V_2 -> V_66 , L_14 ) ;
goto V_9;
}
if ( V_5 == V_165 ) {
V_5 = F_45 ( V_2 ) ;
if ( V_5 )
goto V_9;
V_5 = F_34 ( V_2 ) ;
if ( V_5 ) {
F_44 ( & V_2 -> V_66 , L_14 ) ;
goto V_9;
}
}
V_5 = F_38 ( V_2 ) ;
if ( V_5 )
goto V_9;
V_5 = F_39 ( V_2 ) ;
V_9:
if ( V_5 > 0 )
V_5 = - V_152 ;
return V_5 ;
}
int F_46 ( struct V_1 * V_2 , T_2 V_158 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_156 ; V_27 ++ )
if ( V_158 == ( V_2 -> V_160 [ V_27 ] & F_41 ( 15 , 0 ) ) )
return V_27 ;
return - 1 ;
}
