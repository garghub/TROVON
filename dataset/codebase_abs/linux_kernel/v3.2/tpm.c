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
if ( V_22 > V_9 )
V_22 = V_9 ;
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
unsigned int V_79 = 1 ;
V_57 . V_52 . V_58 = V_59 ;
V_57 . V_62 . V_63 . V_56 = V_69 ;
V_57 . V_62 . V_63 . V_64 = F_19 ( 4 ) ;
V_57 . V_62 . V_63 . V_70 = V_73 ;
V_23 = F_15 ( V_3 , & V_57 , V_71 ,
L_7 ) ;
if ( V_23 )
goto V_13;
if ( F_10 ( V_57 . V_52 . V_33 . V_53 ) != 0 ||
F_10 ( V_57 . V_52 . V_33 . V_65 )
!= sizeof( V_57 . V_52 . V_33 ) + sizeof( T_1 ) + 4 * sizeof( T_1 ) )
return;
V_75 = & V_57 . V_62 . V_72 . V_56 . V_78 ;
V_78 = F_10 ( V_75 -> V_80 ) ;
if ( V_78 && V_78 < 1000 ) {
V_79 = 1000 ;
V_3 -> V_19 . V_81 = true ;
}
if ( V_78 )
V_3 -> V_19 . V_82 = F_22 ( V_78 * V_79 ) ;
V_78 = F_10 ( V_75 -> V_83 ) ;
if ( V_78 )
V_3 -> V_19 . V_84 = F_22 ( V_78 * V_79 ) ;
V_78 = F_10 ( V_75 -> V_85 ) ;
if ( V_78 )
V_3 -> V_19 . V_86 = F_22 ( V_78 * V_79 ) ;
V_78 = F_10 ( V_75 -> V_87 ) ;
if ( V_78 )
V_3 -> V_19 . V_88 = F_22 ( V_78 * V_79 ) ;
V_13:
V_57 . V_52 . V_58 = V_59 ;
V_57 . V_62 . V_63 . V_56 = V_69 ;
V_57 . V_62 . V_63 . V_64 = F_19 ( 4 ) ;
V_57 . V_62 . V_63 . V_70 = V_89 ;
V_23 = F_15 ( V_3 , & V_57 , V_71 ,
L_8 ) ;
if ( V_23 )
return;
if ( F_10 ( V_57 . V_52 . V_33 . V_53 ) != 0 ||
F_10 ( V_57 . V_52 . V_33 . V_65 )
!= sizeof( V_57 . V_52 . V_33 ) + sizeof( T_1 ) + 3 * sizeof( T_1 ) )
return;
V_77 = & V_57 . V_62 . V_72 . V_56 . V_13 ;
V_3 -> V_19 . V_13 [ V_90 ] =
F_22 ( F_10 ( V_77 -> V_91 ) ) ;
V_3 -> V_19 . V_13 [ V_92 ] =
F_22 ( F_10 ( V_77 -> V_93 ) ) ;
V_3 -> V_19 . V_13 [ V_94 ] =
F_22 ( F_10 ( V_77 -> V_95 ) ) ;
if ( V_3 -> V_19 . V_13 [ V_90 ] < ( V_20 / 100 ) ) {
V_3 -> V_19 . V_13 [ V_90 ] = V_20 ;
V_3 -> V_19 . V_13 [ V_92 ] *= 1000 ;
V_3 -> V_19 . V_13 [ V_94 ] *= 1000 ;
V_3 -> V_19 . V_96 = true ;
F_23 ( V_3 -> V_28 , L_9 ) ;
}
}
void F_24 ( struct V_2 * V_3 )
{
V_32 V_97 [] = {
0 , 193 ,
0 , 0 , 0 , 10 ,
0 , 0 , 0 , 83 ,
} ;
F_9 ( V_3 , V_97 , sizeof( V_97 ) ) ;
}
T_2 F_25 ( struct V_54 * V_28 , struct V_98 * V_99 ,
char * V_21 )
{
T_4 V_56 ;
T_2 V_23 ;
V_23 = F_17 ( V_28 , V_66 , & V_56 ,
L_10 ) ;
if ( V_23 )
return 0 ;
V_23 = sprintf ( V_21 , L_11 , ! V_56 . V_100 . V_101 ) ;
return V_23 ;
}
T_2 F_26 ( struct V_54 * V_28 , struct V_98 * V_99 ,
char * V_21 )
{
T_4 V_56 ;
T_2 V_23 ;
V_23 = F_17 ( V_28 , V_66 , & V_56 ,
L_12 ) ;
if ( V_23 )
return 0 ;
V_23 = sprintf ( V_21 , L_11 , ! V_56 . V_100 . V_102 ) ;
return V_23 ;
}
T_2 F_27 ( struct V_54 * V_28 , struct V_98 * V_99 ,
char * V_21 )
{
T_4 V_56 ;
T_2 V_23 ;
V_23 = F_17 ( V_28 , V_103 , & V_56 ,
L_13 ) ;
if ( V_23 )
return 0 ;
V_23 = sprintf ( V_21 , L_11 , V_56 . V_104 ) ;
return V_23 ;
}
T_2 F_28 ( struct V_54 * V_28 ,
struct V_98 * V_99 , char * V_21 )
{
T_4 V_56 ;
T_2 V_23 ;
V_23 = F_17 ( V_28 , V_67 , & V_56 ,
L_14 ) ;
if ( V_23 )
return 0 ;
V_23 = sprintf ( V_21 , L_11 , V_56 . V_105 . V_102 ) ;
return V_23 ;
}
static struct V_2 * F_29 ( int V_106 )
{
struct V_2 * V_107 , * V_3 = NULL ;
F_30 () ;
F_31 (pos, &tpm_chip_list, list) {
if ( V_106 != V_108 && V_106 != V_107 -> V_109 )
continue;
if ( F_32 ( V_107 -> V_28 -> V_110 -> V_111 ) ) {
V_3 = V_107 ;
break;
}
}
F_33 () ;
return V_3 ;
}
int F_34 ( struct V_2 * V_3 , int V_112 , V_32 * V_113 )
{
int V_23 ;
struct V_46 V_47 ;
V_47 . V_52 . V_58 = V_114 ;
V_47 . V_62 . V_115 . V_112 = F_19 ( V_112 ) ;
V_23 = F_15 ( V_3 , & V_47 , V_116 ,
L_15 ) ;
if ( V_23 == 0 )
memcpy ( V_113 , V_47 . V_62 . V_117 . V_118 ,
V_119 ) ;
return V_23 ;
}
int F_35 ( T_1 V_106 , int V_112 , V_32 * V_113 )
{
struct V_2 * V_3 ;
int V_23 ;
V_3 = F_29 ( V_106 ) ;
if ( V_3 == NULL )
return - V_120 ;
V_23 = F_34 ( V_3 , V_112 , V_113 ) ;
F_36 ( V_3 ) ;
return V_23 ;
}
int F_37 ( T_1 V_106 , int V_112 , const V_32 * V_121 )
{
struct V_46 V_47 ;
int V_23 ;
struct V_2 * V_3 ;
V_3 = F_29 ( V_106 ) ;
if ( V_3 == NULL )
return - V_120 ;
V_47 . V_52 . V_58 = V_122 ;
V_47 . V_62 . V_123 . V_112 = F_19 ( V_112 ) ;
memcpy ( V_47 . V_62 . V_123 . V_121 , V_121 , V_119 ) ;
V_23 = F_15 ( V_3 , & V_47 , V_124 ,
L_16 ) ;
F_36 ( V_3 ) ;
return V_23 ;
}
int F_38 ( T_1 V_106 , void * V_47 , T_3 V_125 )
{
struct V_2 * V_3 ;
int V_23 ;
V_3 = F_29 ( V_106 ) ;
if ( V_3 == NULL )
return - V_120 ;
V_23 = F_15 ( V_3 , V_47 , V_125 , L_17 ) ;
F_36 ( V_3 ) ;
return V_23 ;
}
T_2 F_39 ( struct V_54 * V_28 , struct V_98 * V_99 ,
char * V_21 )
{
T_4 V_56 ;
V_32 V_126 [ V_119 ] ;
T_2 V_23 ;
int V_127 , V_128 , V_129 ;
char * V_130 = V_21 ;
struct V_2 * V_3 = F_18 ( V_28 ) ;
V_23 = F_17 ( V_28 , V_131 , & V_56 ,
L_18 ) ;
if ( V_23 )
return 0 ;
V_129 = F_10 ( V_56 . V_129 ) ;
for ( V_127 = 0 ; V_127 < V_129 ; V_127 ++ ) {
V_23 = F_34 ( V_3 , V_127 , V_126 ) ;
if ( V_23 )
break;
V_130 += sprintf ( V_130 , L_19 , V_127 ) ;
for ( V_128 = 0 ; V_128 < V_119 ; V_128 ++ )
V_130 += sprintf ( V_130 , L_20 , V_126 [ V_128 ] ) ;
V_130 += sprintf ( V_130 , L_21 ) ;
}
return V_130 - V_21 ;
}
T_2 F_40 ( struct V_54 * V_28 , struct V_98 * V_99 ,
char * V_21 )
{
V_32 * V_97 ;
struct V_46 V_57 ;
T_2 V_50 ;
int V_127 , V_23 ;
char * V_130 = V_21 ;
struct V_2 * V_3 = F_18 ( V_28 ) ;
V_57 . V_52 . V_58 = V_132 ;
V_50 = F_15 ( V_3 , & V_57 , V_133 ,
L_22 ) ;
if ( V_50 )
goto V_33;
V_97 = V_57 . V_62 . V_134 ;
V_130 +=
sprintf ( V_130 ,
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30 ,
V_97 [ 0 ] , V_97 [ 1 ] , V_97 [ 2 ] , V_97 [ 3 ] ,
V_97 [ 4 ] , V_97 [ 5 ] ,
V_97 [ 6 ] , V_97 [ 7 ] ,
V_97 [ 12 ] , V_97 [ 13 ] , V_97 [ 14 ] , V_97 [ 15 ] ,
V_97 [ 16 ] , V_97 [ 17 ] , V_97 [ 18 ] , V_97 [ 19 ] ,
V_97 [ 20 ] , V_97 [ 21 ] , V_97 [ 22 ] , V_97 [ 23 ] ,
F_10 ( * ( ( V_26 * ) ( V_97 + 24 ) ) ) ) ;
for ( V_127 = 0 ; V_127 < 256 ; V_127 ++ ) {
V_130 += sprintf ( V_130 , L_20 , V_97 [ V_127 + 28 ] ) ;
if ( ( V_127 + 1 ) % 16 == 0 )
V_130 += sprintf ( V_130 , L_21 ) ;
}
V_33:
V_23 = V_130 - V_21 ;
return V_23 ;
}
T_2 F_41 ( struct V_54 * V_28 , struct V_98 * V_99 ,
char * V_21 )
{
T_4 V_56 ;
T_2 V_23 ;
char * V_130 = V_21 ;
V_23 = F_17 ( V_28 , V_135 , & V_56 ,
L_31 ) ;
if ( V_23 )
return 0 ;
V_130 += sprintf ( V_130 , L_32 ,
F_10 ( V_56 . V_136 ) ) ;
V_23 = F_17 ( V_28 , V_60 , & V_56 ,
L_33 ) ;
if ( V_23 )
return 0 ;
V_130 += sprintf ( V_130 ,
L_34 ,
V_56 . V_137 . V_138 , V_56 . V_137 . V_139 ,
V_56 . V_137 . V_140 , V_56 . V_137 . V_141 ) ;
return V_130 - V_21 ;
}
T_2 F_42 ( struct V_54 * V_28 ,
struct V_98 * V_99 , char * V_21 )
{
T_4 V_56 ;
T_2 V_23 ;
char * V_130 = V_21 ;
V_23 = F_17 ( V_28 , V_135 , & V_56 ,
L_31 ) ;
if ( V_23 )
return 0 ;
V_130 += sprintf ( V_130 , L_32 ,
F_10 ( V_56 . V_136 ) ) ;
V_23 = F_17 ( V_28 , V_61 , & V_56 ,
L_35 ) ;
if ( V_23 )
return 0 ;
V_130 += sprintf ( V_130 ,
L_34 ,
V_56 . V_142 . V_138 , V_56 . V_142 . V_139 ,
V_56 . V_142 . V_140 ,
V_56 . V_142 . V_141 ) ;
return V_130 - V_21 ;
}
T_2 F_43 ( struct V_54 * V_28 , struct V_98 * V_99 ,
char * V_21 )
{
struct V_2 * V_3 = F_18 ( V_28 ) ;
if ( V_3 -> V_19 . V_13 [ V_94 ] == 0 )
return 0 ;
return sprintf ( V_21 , L_36 ,
F_44 ( V_3 -> V_19 . V_13 [ V_90 ] ) ,
F_44 ( V_3 -> V_19 . V_13 [ V_92 ] ) ,
F_44 ( V_3 -> V_19 . V_13 [ V_94 ] ) ,
V_3 -> V_19 . V_96
? L_37 : L_38 ) ;
}
T_2 F_45 ( struct V_54 * V_28 , struct V_98 * V_99 ,
char * V_21 )
{
struct V_2 * V_3 = F_18 ( V_28 ) ;
return sprintf ( V_21 , L_39 ,
F_44 ( V_3 -> V_19 . V_82 ) ,
F_44 ( V_3 -> V_19 . V_84 ) ,
F_44 ( V_3 -> V_19 . V_86 ) ,
F_44 ( V_3 -> V_19 . V_88 ) ,
V_3 -> V_19 . V_81
? L_37 : L_38 ) ;
}
T_2 F_46 ( struct V_54 * V_28 , struct V_98 * V_99 ,
const char * V_21 , T_3 V_24 )
{
struct V_2 * V_3 = F_18 ( V_28 ) ;
if ( V_3 == NULL )
return 0 ;
V_3 -> V_19 . V_43 ( V_3 ) ;
return V_24 ;
}
int F_47 ( struct V_143 * V_143 , struct V_144 * V_144 )
{
int V_145 = F_48 ( V_143 ) ;
struct V_2 * V_3 = NULL , * V_107 ;
F_30 () ;
F_31 (pos, &tpm_chip_list, list) {
if ( V_107 -> V_19 . V_146 . V_145 == V_145 ) {
V_3 = V_107 ;
F_49 ( V_3 -> V_28 ) ;
break;
}
}
F_33 () ;
if ( ! V_3 )
return - V_120 ;
if ( F_50 ( 0 , & V_3 -> V_147 ) ) {
F_16 ( V_3 -> V_28 , L_40 ) ;
F_51 ( V_3 -> V_28 ) ;
return - V_148 ;
}
V_3 -> V_8 = F_52 ( V_9 , V_149 ) ;
if ( V_3 -> V_8 == NULL ) {
F_53 ( 0 , & V_3 -> V_147 ) ;
F_51 ( V_3 -> V_28 ) ;
return - V_150 ;
}
F_6 ( & V_3 -> V_7 , 0 ) ;
V_144 -> V_151 = V_3 ;
return 0 ;
}
int F_54 ( struct V_143 * V_143 , struct V_144 * V_144 )
{
struct V_2 * V_3 = V_144 -> V_151 ;
F_55 ( & V_3 -> V_152 ) ;
F_56 ( & V_3 -> V_4 ) ;
V_144 -> V_151 = NULL ;
F_6 ( & V_3 -> V_7 , 0 ) ;
F_57 ( V_3 -> V_8 ) ;
F_53 ( 0 , & V_3 -> V_147 ) ;
F_51 ( V_3 -> V_28 ) ;
return 0 ;
}
T_2 F_58 ( struct V_144 * V_144 , const char T_5 * V_21 ,
T_3 V_153 , T_6 * V_154 )
{
struct V_2 * V_3 = V_144 -> V_151 ;
T_3 V_155 = V_153 , V_156 ;
while ( F_59 ( & V_3 -> V_7 ) != 0 )
F_12 ( V_42 ) ;
F_5 ( & V_3 -> V_6 ) ;
if ( V_155 > V_9 )
V_155 = V_9 ;
if ( F_60
( V_3 -> V_8 , ( void T_5 * ) V_21 , V_155 ) ) {
F_7 ( & V_3 -> V_6 ) ;
return - V_157 ;
}
V_156 = F_9 ( V_3 , V_3 -> V_8 , V_9 ) ;
F_6 ( & V_3 -> V_7 , V_156 ) ;
F_7 ( & V_3 -> V_6 ) ;
F_61 ( & V_3 -> V_152 , V_36 + ( 60 * V_20 ) ) ;
return V_155 ;
}
T_2 F_62 ( struct V_144 * V_144 , char T_5 * V_21 ,
T_3 V_153 , T_6 * V_154 )
{
struct V_2 * V_3 = V_144 -> V_151 ;
T_2 V_158 ;
int V_23 ;
F_55 ( & V_3 -> V_152 ) ;
F_56 ( & V_3 -> V_4 ) ;
V_158 = F_59 ( & V_3 -> V_7 ) ;
F_6 ( & V_3 -> V_7 , 0 ) ;
if ( V_158 > 0 ) {
if ( V_153 < V_158 )
V_158 = V_153 ;
F_5 ( & V_3 -> V_6 ) ;
V_23 = F_63 ( V_21 , V_3 -> V_8 , V_158 ) ;
memset ( V_3 -> V_8 , 0 , V_158 ) ;
if ( V_23 )
V_158 = - V_157 ;
F_7 ( & V_3 -> V_6 ) ;
}
return V_158 ;
}
void F_64 ( struct V_54 * V_28 )
{
struct V_2 * V_3 = F_18 ( V_28 ) ;
if ( V_3 == NULL ) {
F_11 ( V_28 , L_41 ) ;
return;
}
F_65 ( & V_159 ) ;
F_66 ( & V_3 -> V_160 ) ;
F_67 ( & V_159 ) ;
F_68 () ;
F_69 ( & V_3 -> V_19 . V_146 ) ;
F_70 ( & V_28 -> V_161 , V_3 -> V_19 . V_162 ) ;
F_71 ( V_3 -> V_163 ) ;
F_51 ( V_3 -> V_28 ) ;
}
int F_72 ( struct V_54 * V_28 , T_7 V_164 )
{
struct V_2 * V_3 = F_18 ( V_28 ) ;
struct V_46 V_47 ;
int V_23 ;
V_32 V_165 [ V_119 ] = { 0 } ;
if ( V_3 == NULL )
return - V_120 ;
if ( V_166 ) {
V_47 . V_52 . V_58 = V_122 ;
V_47 . V_62 . V_123 . V_112 = F_19 ( V_166 ) ;
memcpy ( V_47 . V_62 . V_123 . V_121 , V_165 ,
V_119 ) ;
V_23 = F_15 ( V_3 , & V_47 , V_124 ,
L_42 ) ;
}
V_47 . V_52 . V_58 = V_167 ;
V_23 = F_15 ( V_3 , & V_47 , V_168 ,
L_43 ) ;
return V_23 ;
}
int F_73 ( struct V_54 * V_28 )
{
struct V_2 * V_3 = F_18 ( V_28 ) ;
if ( V_3 == NULL )
return - V_120 ;
return 0 ;
}
void F_74 ( struct V_2 * V_3 )
{
if ( V_3 -> V_19 . V_169 )
V_3 -> V_19 . V_169 ( V_3 -> V_28 ) ;
F_53 ( V_3 -> V_109 , V_170 ) ;
F_57 ( V_3 -> V_19 . V_146 . V_171 ) ;
}
void F_75 ( struct V_54 * V_28 )
{
struct V_2 * V_3 = F_18 ( V_28 ) ;
F_74 ( V_3 ) ;
V_3 -> V_169 ( V_28 ) ;
F_57 ( V_3 ) ;
}
struct V_2 * F_76 ( struct V_54 * V_28 ,
const struct V_172 * V_173 )
{
#define F_77 7
char * V_174 ;
struct V_2 * V_3 ;
V_3 = F_52 ( sizeof( * V_3 ) , V_149 ) ;
V_174 = F_78 ( F_77 , V_149 ) ;
if ( V_3 == NULL || V_174 == NULL )
goto V_175;
F_79 ( & V_3 -> V_6 ) ;
F_79 ( & V_3 -> V_30 ) ;
F_80 ( & V_3 -> V_160 ) ;
F_81 ( & V_3 -> V_4 , F_3 ) ;
F_82 ( & V_3 -> V_152 , F_1 ,
( unsigned long ) V_3 ) ;
memcpy ( & V_3 -> V_19 , V_173 , sizeof( struct V_172 ) ) ;
V_3 -> V_109 = F_83 ( V_170 , V_176 ) ;
if ( V_3 -> V_109 >= V_176 ) {
F_11 ( V_28 , L_44 ) ;
goto V_175;
} else if ( V_3 -> V_109 == 0 )
V_3 -> V_19 . V_146 . V_145 = V_177 ;
else
V_3 -> V_19 . V_146 . V_145 = V_178 ;
F_84 ( V_3 -> V_109 , V_170 ) ;
F_85 ( V_174 , F_77 , L_45 , L_46 , V_3 -> V_109 ) ;
V_3 -> V_19 . V_146 . V_171 = V_174 ;
V_3 -> V_19 . V_146 . V_179 = V_28 ;
V_3 -> V_28 = F_49 ( V_28 ) ;
V_3 -> V_169 = V_28 -> V_169 ;
V_28 -> V_169 = F_75 ;
F_86 ( V_28 , V_3 ) ;
if ( F_87 ( & V_3 -> V_19 . V_146 ) ) {
F_11 ( V_3 -> V_28 ,
L_47 ,
V_3 -> V_19 . V_146 . V_171 ,
V_3 -> V_19 . V_146 . V_145 ) ;
F_51 ( V_3 -> V_28 ) ;
return NULL ;
}
if ( F_88 ( & V_28 -> V_161 , V_3 -> V_19 . V_162 ) ) {
F_69 ( & V_3 -> V_19 . V_146 ) ;
F_51 ( V_3 -> V_28 ) ;
return NULL ;
}
V_3 -> V_163 = F_89 ( V_174 ) ;
F_65 ( & V_159 ) ;
F_90 ( & V_3 -> V_160 , & V_180 ) ;
F_67 ( & V_159 ) ;
return V_3 ;
V_175:
F_57 ( V_3 ) ;
F_57 ( V_174 ) ;
return NULL ;
}
