static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( & V_3 -> V_4 ) ;
}
static void F_3 ( struct V_5 * V_4 )
{
struct V_2 * V_3 = F_4 ( V_4 , struct V_2 , V_4 ) ;
F_5 ( & V_3 -> V_6 ) ;
F_6 ( & V_3 -> V_7 , 0 ) ;
memset ( V_3 -> V_8 , 0 , V_9 ) ;
F_7 ( & V_3 -> V_6 ) ;
}
unsigned long F_8 ( struct V_2 * V_3 ,
T_1 V_10 )
{
int V_11 = V_12 ;
int V_13 = 0 ;
if ( V_10 < V_14 )
V_11 = V_15 [ V_10 ] ;
else if ( ( V_10 & V_16 ) <
V_17 )
V_11 =
V_18 [ V_10 &
V_16 ] ;
if ( V_11 != V_12 )
V_13 = V_3 -> V_19 . V_13 [ V_11 ] ;
if ( V_13 <= 0 )
return 2 * 60 * V_20 ;
else
return V_13 ;
}
static T_2 F_9 ( struct V_2 * V_3 , const char * V_21 ,
T_3 V_22 )
{
T_2 V_23 ;
T_1 V_24 , V_10 ;
unsigned long V_25 ;
V_24 = F_10 ( * ( ( V_26 * ) ( V_21 + 2 ) ) ) ;
V_10 = F_10 ( * ( ( V_26 * ) ( V_21 + 6 ) ) ) ;
if ( V_24 == 0 )
return - V_27 ;
if ( V_24 > V_22 ) {
F_11 ( V_3 -> V_28 ,
L_1 , V_24 , V_22 ) ;
return - V_29 ;
}
F_5 ( & V_3 -> V_30 ) ;
if ( ( V_23 = V_3 -> V_19 . V_31 ( V_3 , ( V_32 * ) V_21 , V_24 ) ) < 0 ) {
F_11 ( V_3 -> V_28 ,
L_2 , V_23 ) ;
goto V_33;
}
if ( V_3 -> V_19 . V_34 )
goto V_35;
V_25 = V_36 + F_8 ( V_3 , V_10 ) ;
do {
V_32 V_37 = V_3 -> V_19 . V_37 ( V_3 ) ;
if ( ( V_37 & V_3 -> V_19 . V_38 ) ==
V_3 -> V_19 . V_39 )
goto V_35;
if ( ( V_37 == V_3 -> V_19 . V_40 ) ) {
F_11 ( V_3 -> V_28 , L_3 ) ;
V_23 = - V_41 ;
goto V_33;
}
F_12 ( V_42 ) ;
F_13 () ;
} while ( F_14 ( V_36 , V_25 ) );
V_3 -> V_19 . V_43 ( V_3 ) ;
F_11 ( V_3 -> V_28 , L_4 ) ;
V_23 = - V_44 ;
goto V_33;
V_35:
V_23 = V_3 -> V_19 . V_45 ( V_3 , ( V_32 * ) V_21 , V_22 ) ;
if ( V_23 < 0 )
F_11 ( V_3 -> V_28 ,
L_5 , V_23 ) ;
V_33:
F_7 ( & V_3 -> V_30 ) ;
return V_23 ;
}
static T_2 F_15 ( struct V_2 * V_3 , struct V_46 * V_47 ,
int V_48 , const char * V_49 )
{
int V_50 ;
V_48 = F_9 ( V_3 , ( V_32 * ) V_47 , V_48 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_48 == V_51 ) {
V_50 = F_10 ( V_47 -> V_52 . V_33 . V_53 ) ;
F_16 ( V_3 -> V_28 , L_6 , V_50 , V_49 ) ;
return V_50 ;
}
return 0 ;
}
T_2 F_17 ( struct V_54 * V_28 , V_26 V_55 , T_4 * V_56 ,
const char * V_49 )
{
struct V_46 V_57 ;
int V_23 ;
struct V_2 * V_3 = F_18 ( V_28 ) ;
V_57 . V_52 . V_58 = V_59 ;
if ( V_55 == V_60 || V_55 == V_61 ) {
V_57 . V_62 . V_63 . V_56 = V_55 ;
V_57 . V_62 . V_63 . V_64 = F_19 ( 0 ) ;
V_57 . V_52 . V_58 . V_65 -= F_19 ( sizeof( V_26 ) ) ;
} else {
if ( V_55 == V_66 ||
V_55 == V_67 )
V_57 . V_62 . V_63 . V_56 = V_68 ;
else
V_57 . V_62 . V_63 . V_56 = V_69 ;
V_57 . V_62 . V_63 . V_64 = F_19 ( 4 ) ;
V_57 . V_62 . V_63 . V_70 = V_55 ;
}
V_23 = F_15 ( V_3 , & V_57 , V_71 , V_49 ) ;
if ( ! V_23 )
* V_56 = V_57 . V_62 . V_72 . V_56 ;
return V_23 ;
}
void F_20 ( struct V_2 * V_3 )
{
struct V_46 V_57 ;
T_2 V_23 ;
V_57 . V_52 . V_58 = V_59 ;
V_57 . V_62 . V_63 . V_56 = V_69 ;
V_57 . V_62 . V_63 . V_64 = F_19 ( 4 ) ;
V_57 . V_62 . V_63 . V_70 = V_73 ;
V_23 = F_15 ( V_3 , & V_57 , V_71 ,
L_7 ) ;
}
void F_21 ( struct V_2 * V_3 )
{
struct V_46 V_57 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
T_2 V_23 ;
T_1 V_78 ;
V_57 . V_52 . V_58 = V_59 ;
V_57 . V_62 . V_63 . V_56 = V_69 ;
V_57 . V_62 . V_63 . V_64 = F_19 ( 4 ) ;
V_57 . V_62 . V_63 . V_70 = V_73 ;
V_23 = F_15 ( V_3 , & V_57 , V_71 ,
L_7 ) ;
if ( V_23 )
goto V_13;
if ( F_10 ( V_57 . V_52 . V_33 . V_65 )
!= 4 * sizeof( T_1 ) )
goto V_13;
V_75 = & V_57 . V_62 . V_72 . V_56 . V_78 ;
V_78 = F_10 ( V_75 -> V_79 ) ;
if ( V_78 )
V_3 -> V_19 . V_80 = F_22 ( V_78 ) ;
V_78 = F_10 ( V_75 -> V_81 ) ;
if ( V_78 )
V_3 -> V_19 . V_82 = F_22 ( V_78 ) ;
V_78 = F_10 ( V_75 -> V_83 ) ;
if ( V_78 )
V_3 -> V_19 . V_84 = F_22 ( V_78 ) ;
V_78 = F_10 ( V_75 -> V_85 ) ;
if ( V_78 )
V_3 -> V_19 . V_86 = F_22 ( V_78 ) ;
V_13:
V_57 . V_52 . V_58 = V_59 ;
V_57 . V_62 . V_63 . V_56 = V_69 ;
V_57 . V_62 . V_63 . V_64 = F_19 ( 4 ) ;
V_57 . V_62 . V_63 . V_70 = V_87 ;
V_23 = F_15 ( V_3 , & V_57 , V_71 ,
L_8 ) ;
if ( V_23 )
return;
if ( F_10 ( V_57 . V_52 . V_33 . V_53 )
!= 3 * sizeof( T_1 ) )
return;
V_77 = & V_57 . V_62 . V_72 . V_56 . V_13 ;
V_3 -> V_19 . V_13 [ V_88 ] =
F_22 ( F_10 ( V_77 -> V_89 ) ) ;
if ( V_3 -> V_19 . V_13 [ V_88 ] < ( V_20 / 100 ) )
V_3 -> V_19 . V_13 [ V_88 ] = V_20 ;
V_3 -> V_19 . V_13 [ V_90 ] =
F_22 ( F_10 ( V_77 -> V_91 ) ) ;
V_3 -> V_19 . V_13 [ V_92 ] =
F_22 ( F_10 ( V_77 -> V_93 ) ) ;
}
void F_23 ( struct V_2 * V_3 )
{
V_32 V_94 [] = {
0 , 193 ,
0 , 0 , 0 , 10 ,
0 , 0 , 0 , 83 ,
} ;
F_9 ( V_3 , V_94 , sizeof( V_94 ) ) ;
}
T_2 F_24 ( struct V_54 * V_28 , struct V_95 * V_96 ,
char * V_21 )
{
T_4 V_56 ;
T_2 V_23 ;
V_23 = F_17 ( V_28 , V_66 , & V_56 ,
L_9 ) ;
if ( V_23 )
return 0 ;
V_23 = sprintf ( V_21 , L_10 , ! V_56 . V_97 . V_98 ) ;
return V_23 ;
}
T_2 F_25 ( struct V_54 * V_28 , struct V_95 * V_96 ,
char * V_21 )
{
T_4 V_56 ;
T_2 V_23 ;
V_23 = F_17 ( V_28 , V_66 , & V_56 ,
L_11 ) ;
if ( V_23 )
return 0 ;
V_23 = sprintf ( V_21 , L_10 , ! V_56 . V_97 . V_99 ) ;
return V_23 ;
}
T_2 F_26 ( struct V_54 * V_28 , struct V_95 * V_96 ,
char * V_21 )
{
T_4 V_56 ;
T_2 V_23 ;
V_23 = F_17 ( V_28 , V_100 , & V_56 ,
L_12 ) ;
if ( V_23 )
return 0 ;
V_23 = sprintf ( V_21 , L_10 , V_56 . V_101 ) ;
return V_23 ;
}
T_2 F_27 ( struct V_54 * V_28 ,
struct V_95 * V_96 , char * V_21 )
{
T_4 V_56 ;
T_2 V_23 ;
V_23 = F_17 ( V_28 , V_67 , & V_56 ,
L_13 ) ;
if ( V_23 )
return 0 ;
V_23 = sprintf ( V_21 , L_10 , V_56 . V_102 . V_99 ) ;
return V_23 ;
}
static struct V_2 * F_28 ( int V_103 )
{
struct V_2 * V_104 , * V_3 = NULL ;
F_29 () ;
F_30 (pos, &tpm_chip_list, list) {
if ( V_103 != V_105 && V_103 != V_104 -> V_106 )
continue;
if ( F_31 ( V_104 -> V_28 -> V_107 -> V_108 ) ) {
V_3 = V_104 ;
break;
}
}
F_32 () ;
return V_3 ;
}
int F_33 ( struct V_2 * V_3 , int V_109 , V_32 * V_110 )
{
int V_23 ;
struct V_46 V_47 ;
V_47 . V_52 . V_58 = V_111 ;
V_47 . V_62 . V_112 . V_109 = F_19 ( V_109 ) ;
V_23 = F_15 ( V_3 , & V_47 , V_113 ,
L_14 ) ;
if ( V_23 == 0 )
memcpy ( V_110 , V_47 . V_62 . V_114 . V_115 ,
V_116 ) ;
return V_23 ;
}
int F_34 ( T_1 V_103 , int V_109 , V_32 * V_110 )
{
struct V_2 * V_3 ;
int V_23 ;
V_3 = F_28 ( V_103 ) ;
if ( V_3 == NULL )
return - V_117 ;
V_23 = F_33 ( V_3 , V_109 , V_110 ) ;
F_35 ( V_3 ) ;
return V_23 ;
}
int F_36 ( T_1 V_103 , int V_109 , const V_32 * V_118 )
{
struct V_46 V_47 ;
int V_23 ;
struct V_2 * V_3 ;
V_3 = F_28 ( V_103 ) ;
if ( V_3 == NULL )
return - V_117 ;
V_47 . V_52 . V_58 = V_119 ;
V_47 . V_62 . V_120 . V_109 = F_19 ( V_109 ) ;
memcpy ( V_47 . V_62 . V_120 . V_118 , V_118 , V_116 ) ;
V_23 = F_15 ( V_3 , & V_47 , V_121 ,
L_15 ) ;
F_35 ( V_3 ) ;
return V_23 ;
}
int F_37 ( T_1 V_103 , void * V_47 , T_3 V_122 )
{
struct V_2 * V_3 ;
int V_23 ;
V_3 = F_28 ( V_103 ) ;
if ( V_3 == NULL )
return - V_117 ;
V_23 = F_15 ( V_3 , V_47 , V_122 , L_16 ) ;
F_35 ( V_3 ) ;
return V_23 ;
}
T_2 F_38 ( struct V_54 * V_28 , struct V_95 * V_96 ,
char * V_21 )
{
T_4 V_56 ;
V_32 V_123 [ V_116 ] ;
T_2 V_23 ;
int V_124 , V_125 , V_126 ;
char * V_127 = V_21 ;
struct V_2 * V_3 = F_18 ( V_28 ) ;
V_23 = F_17 ( V_28 , V_128 , & V_56 ,
L_17 ) ;
if ( V_23 )
return 0 ;
V_126 = F_10 ( V_56 . V_126 ) ;
for ( V_124 = 0 ; V_124 < V_126 ; V_124 ++ ) {
V_23 = F_33 ( V_3 , V_124 , V_123 ) ;
if ( V_23 )
break;
V_127 += sprintf ( V_127 , L_18 , V_124 ) ;
for ( V_125 = 0 ; V_125 < V_116 ; V_125 ++ )
V_127 += sprintf ( V_127 , L_19 , V_123 [ V_125 ] ) ;
V_127 += sprintf ( V_127 , L_20 ) ;
}
return V_127 - V_21 ;
}
T_2 F_39 ( struct V_54 * V_28 , struct V_95 * V_96 ,
char * V_21 )
{
V_32 * V_94 ;
struct V_46 V_57 ;
T_2 V_50 ;
int V_124 , V_23 ;
char * V_127 = V_21 ;
struct V_2 * V_3 = F_18 ( V_28 ) ;
V_57 . V_52 . V_58 = V_129 ;
V_50 = F_15 ( V_3 , & V_57 , V_130 ,
L_21 ) ;
if ( V_50 )
goto V_33;
V_94 = V_57 . V_62 . V_131 ;
V_127 +=
sprintf ( V_127 ,
L_22
L_23
L_24
L_25 ,
V_94 [ 10 ] , V_94 [ 11 ] , V_94 [ 12 ] , V_94 [ 13 ] , V_94 [ 14 ] ,
V_94 [ 15 ] , V_94 [ 16 ] , V_94 [ 17 ] , V_94 [ 22 ] , V_94 [ 23 ] ,
V_94 [ 24 ] , V_94 [ 25 ] , V_94 [ 26 ] , V_94 [ 27 ] , V_94 [ 28 ] ,
V_94 [ 29 ] , V_94 [ 30 ] , V_94 [ 31 ] , V_94 [ 32 ] , V_94 [ 33 ] ,
F_10 ( * ( ( V_26 * ) ( V_94 + 34 ) ) ) ) ;
for ( V_124 = 0 ; V_124 < 256 ; V_124 ++ ) {
V_127 += sprintf ( V_127 , L_19 , V_94 [ V_124 + 38 ] ) ;
if ( ( V_124 + 1 ) % 16 == 0 )
V_127 += sprintf ( V_127 , L_20 ) ;
}
V_33:
V_23 = V_127 - V_21 ;
return V_23 ;
}
T_2 F_40 ( struct V_54 * V_28 , struct V_95 * V_96 ,
char * V_21 )
{
T_4 V_56 ;
T_2 V_23 ;
char * V_127 = V_21 ;
V_23 = F_17 ( V_28 , V_132 , & V_56 ,
L_26 ) ;
if ( V_23 )
return 0 ;
V_127 += sprintf ( V_127 , L_27 ,
F_10 ( V_56 . V_133 ) ) ;
V_23 = F_17 ( V_28 , V_60 , & V_56 ,
L_28 ) ;
if ( V_23 )
return 0 ;
V_127 += sprintf ( V_127 ,
L_29 ,
V_56 . V_134 . V_135 , V_56 . V_134 . V_136 ,
V_56 . V_134 . V_137 , V_56 . V_134 . V_138 ) ;
return V_127 - V_21 ;
}
T_2 F_41 ( struct V_54 * V_28 ,
struct V_95 * V_96 , char * V_21 )
{
T_4 V_56 ;
T_2 V_23 ;
char * V_127 = V_21 ;
V_23 = F_17 ( V_28 , V_132 , & V_56 ,
L_26 ) ;
if ( V_23 )
return 0 ;
V_127 += sprintf ( V_127 , L_27 ,
F_10 ( V_56 . V_133 ) ) ;
V_23 = F_17 ( V_28 , V_61 , & V_56 ,
L_30 ) ;
if ( V_23 )
return 0 ;
V_127 += sprintf ( V_127 ,
L_29 ,
V_56 . V_139 . V_135 , V_56 . V_139 . V_136 ,
V_56 . V_139 . V_137 ,
V_56 . V_139 . V_138 ) ;
return V_127 - V_21 ;
}
T_2 F_42 ( struct V_54 * V_28 , struct V_95 * V_96 ,
const char * V_21 , T_3 V_24 )
{
struct V_2 * V_3 = F_18 ( V_28 ) ;
if ( V_3 == NULL )
return 0 ;
V_3 -> V_19 . V_43 ( V_3 ) ;
return V_24 ;
}
int F_43 ( struct V_140 * V_140 , struct V_141 * V_141 )
{
int V_142 = F_44 ( V_140 ) ;
struct V_2 * V_3 = NULL , * V_104 ;
F_29 () ;
F_30 (pos, &tpm_chip_list, list) {
if ( V_104 -> V_19 . V_143 . V_142 == V_142 ) {
V_3 = V_104 ;
F_45 ( V_3 -> V_28 ) ;
break;
}
}
F_32 () ;
if ( ! V_3 )
return - V_117 ;
if ( F_46 ( 0 , & V_3 -> V_144 ) ) {
F_16 ( V_3 -> V_28 , L_31 ) ;
F_47 ( V_3 -> V_28 ) ;
return - V_145 ;
}
V_3 -> V_8 = F_48 ( V_9 , V_146 ) ;
if ( V_3 -> V_8 == NULL ) {
F_49 ( 0 , & V_3 -> V_144 ) ;
F_47 ( V_3 -> V_28 ) ;
return - V_147 ;
}
F_6 ( & V_3 -> V_7 , 0 ) ;
V_141 -> V_148 = V_3 ;
return 0 ;
}
int F_50 ( struct V_140 * V_140 , struct V_141 * V_141 )
{
struct V_2 * V_3 = V_141 -> V_148 ;
F_51 ( & V_3 -> V_149 ) ;
F_52 ( & V_3 -> V_4 ) ;
V_141 -> V_148 = NULL ;
F_6 ( & V_3 -> V_7 , 0 ) ;
F_53 ( V_3 -> V_8 ) ;
F_49 ( 0 , & V_3 -> V_144 ) ;
F_47 ( V_3 -> V_28 ) ;
return 0 ;
}
T_2 F_54 ( struct V_141 * V_141 , const char T_5 * V_21 ,
T_3 V_150 , T_6 * V_151 )
{
struct V_2 * V_3 = V_141 -> V_148 ;
T_3 V_152 = V_150 , V_153 ;
while ( F_55 ( & V_3 -> V_7 ) != 0 )
F_12 ( V_42 ) ;
F_5 ( & V_3 -> V_6 ) ;
if ( V_152 > V_9 )
V_152 = V_9 ;
if ( F_56
( V_3 -> V_8 , ( void T_5 * ) V_21 , V_152 ) ) {
F_7 ( & V_3 -> V_6 ) ;
return - V_154 ;
}
V_153 = F_9 ( V_3 , V_3 -> V_8 , V_9 ) ;
F_6 ( & V_3 -> V_7 , V_153 ) ;
F_7 ( & V_3 -> V_6 ) ;
F_57 ( & V_3 -> V_149 , V_36 + ( 60 * V_20 ) ) ;
return V_152 ;
}
T_2 F_58 ( struct V_141 * V_141 , char T_5 * V_21 ,
T_3 V_150 , T_6 * V_151 )
{
struct V_2 * V_3 = V_141 -> V_148 ;
T_2 V_155 ;
F_51 ( & V_3 -> V_149 ) ;
F_52 ( & V_3 -> V_4 ) ;
V_155 = F_55 ( & V_3 -> V_7 ) ;
F_6 ( & V_3 -> V_7 , 0 ) ;
if ( V_155 > 0 ) {
if ( V_150 < V_155 )
V_155 = V_150 ;
F_5 ( & V_3 -> V_6 ) ;
if ( F_59 ( V_21 , V_3 -> V_8 , V_155 ) )
V_155 = - V_154 ;
F_7 ( & V_3 -> V_6 ) ;
}
return V_155 ;
}
void F_60 ( struct V_54 * V_28 )
{
struct V_2 * V_3 = F_18 ( V_28 ) ;
if ( V_3 == NULL ) {
F_11 ( V_28 , L_32 ) ;
return;
}
F_61 ( & V_156 ) ;
F_62 ( & V_3 -> V_157 ) ;
F_63 ( & V_156 ) ;
F_64 () ;
F_65 ( & V_3 -> V_19 . V_143 ) ;
F_66 ( & V_28 -> V_158 , V_3 -> V_19 . V_159 ) ;
F_67 ( V_3 -> V_160 ) ;
F_47 ( V_3 -> V_28 ) ;
}
int F_68 ( struct V_54 * V_28 , T_7 V_161 )
{
struct V_2 * V_3 = F_18 ( V_28 ) ;
struct V_46 V_47 ;
int V_23 ;
V_32 V_162 [ V_116 ] = { 0 } ;
if ( V_3 == NULL )
return - V_117 ;
if ( V_163 ) {
V_47 . V_52 . V_58 = V_119 ;
V_47 . V_62 . V_120 . V_109 = F_19 ( V_163 ) ;
memcpy ( V_47 . V_62 . V_120 . V_118 , V_162 ,
V_116 ) ;
V_23 = F_15 ( V_3 , & V_47 , V_121 ,
L_33 ) ;
}
V_47 . V_52 . V_58 = V_164 ;
V_23 = F_15 ( V_3 , & V_47 , V_165 ,
L_34 ) ;
return V_23 ;
}
int F_69 ( struct V_54 * V_28 )
{
struct V_2 * V_3 = F_18 ( V_28 ) ;
if ( V_3 == NULL )
return - V_117 ;
return 0 ;
}
void F_70 ( struct V_2 * V_3 )
{
if ( V_3 -> V_19 . V_166 )
V_3 -> V_19 . V_166 ( V_3 -> V_28 ) ;
F_49 ( V_3 -> V_106 , V_167 ) ;
F_53 ( V_3 -> V_19 . V_143 . V_168 ) ;
}
void F_71 ( struct V_54 * V_28 )
{
struct V_2 * V_3 = F_18 ( V_28 ) ;
F_70 ( V_3 ) ;
V_3 -> V_166 ( V_28 ) ;
F_53 ( V_3 ) ;
}
struct V_2 * F_72 ( struct V_54 * V_28 ,
const struct V_169 * V_170 )
{
#define F_73 7
char * V_171 ;
struct V_2 * V_3 ;
V_3 = F_48 ( sizeof( * V_3 ) , V_146 ) ;
V_171 = F_74 ( F_73 , V_146 ) ;
if ( V_3 == NULL || V_171 == NULL )
goto V_172;
F_75 ( & V_3 -> V_6 ) ;
F_75 ( & V_3 -> V_30 ) ;
F_76 ( & V_3 -> V_157 ) ;
F_77 ( & V_3 -> V_4 , F_3 ) ;
F_78 ( & V_3 -> V_149 , F_1 ,
( unsigned long ) V_3 ) ;
memcpy ( & V_3 -> V_19 , V_170 , sizeof( struct V_169 ) ) ;
V_3 -> V_106 = F_79 ( V_167 , V_173 ) ;
if ( V_3 -> V_106 >= V_173 ) {
F_11 ( V_28 , L_35 ) ;
goto V_172;
} else if ( V_3 -> V_106 == 0 )
V_3 -> V_19 . V_143 . V_142 = V_174 ;
else
V_3 -> V_19 . V_143 . V_142 = V_175 ;
F_80 ( V_3 -> V_106 , V_167 ) ;
F_81 ( V_171 , F_73 , L_36 , L_37 , V_3 -> V_106 ) ;
V_3 -> V_19 . V_143 . V_168 = V_171 ;
V_3 -> V_19 . V_143 . V_176 = V_28 ;
V_3 -> V_28 = F_45 ( V_28 ) ;
V_3 -> V_166 = V_28 -> V_166 ;
V_28 -> V_166 = F_71 ;
F_82 ( V_28 , V_3 ) ;
if ( F_83 ( & V_3 -> V_19 . V_143 ) ) {
F_11 ( V_3 -> V_28 ,
L_38 ,
V_3 -> V_19 . V_143 . V_168 ,
V_3 -> V_19 . V_143 . V_142 ) ;
F_47 ( V_3 -> V_28 ) ;
return NULL ;
}
if ( F_84 ( & V_28 -> V_158 , V_3 -> V_19 . V_159 ) ) {
F_65 ( & V_3 -> V_19 . V_143 ) ;
F_47 ( V_3 -> V_28 ) ;
return NULL ;
}
V_3 -> V_160 = F_85 ( V_171 ) ;
F_61 ( & V_156 ) ;
F_86 ( & V_3 -> V_157 , & V_177 ) ;
F_63 ( & V_156 ) ;
return V_3 ;
V_172:
F_53 ( V_3 ) ;
F_53 ( V_171 ) ;
return NULL ;
}
