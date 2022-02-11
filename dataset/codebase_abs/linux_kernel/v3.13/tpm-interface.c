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
T_2 V_14 = ( V_10 >> 24 ) & 0xFF ;
if ( ( V_14 == V_15 && V_10 < V_16 ) ||
( V_14 == V_17 && V_10 < V_18 ) )
V_11 = V_19 [ V_10 ] ;
if ( V_11 != V_12 )
V_13 = V_3 -> V_20 . V_13 [ V_11 ] ;
if ( V_13 <= 0 )
return 2 * 60 * V_21 ;
else
return V_13 ;
}
static T_3 F_9 ( struct V_2 * V_3 , const char * V_22 ,
T_4 V_23 )
{
T_3 V_24 ;
T_1 V_25 , V_10 ;
unsigned long V_26 ;
if ( V_23 > V_9 )
V_23 = V_9 ;
V_25 = F_10 ( * ( ( V_27 * ) ( V_22 + 2 ) ) ) ;
V_10 = F_10 ( * ( ( V_27 * ) ( V_22 + 6 ) ) ) ;
if ( V_25 == 0 )
return - V_28 ;
if ( V_25 > V_23 ) {
F_11 ( V_3 -> V_29 ,
L_1 , V_25 , V_23 ) ;
return - V_30 ;
}
F_5 ( & V_3 -> V_31 ) ;
V_24 = V_3 -> V_20 . V_32 ( V_3 , ( T_2 * ) V_22 , V_25 ) ;
if ( V_24 < 0 ) {
F_11 ( V_3 -> V_29 ,
L_2 , V_24 ) ;
goto V_33;
}
if ( V_3 -> V_20 . V_34 )
goto V_35;
V_26 = V_36 + F_8 ( V_3 , V_10 ) ;
do {
T_2 V_37 = V_3 -> V_20 . V_37 ( V_3 ) ;
if ( ( V_37 & V_3 -> V_20 . V_38 ) ==
V_3 -> V_20 . V_39 )
goto V_35;
if ( V_3 -> V_20 . V_40 ( V_3 , V_37 ) ) {
F_11 ( V_3 -> V_29 , L_3 ) ;
V_24 = - V_41 ;
goto V_33;
}
F_12 ( V_42 ) ;
F_13 () ;
} while ( F_14 ( V_36 , V_26 ) );
V_3 -> V_20 . V_43 ( V_3 ) ;
F_11 ( V_3 -> V_29 , L_4 ) ;
V_24 = - V_44 ;
goto V_33;
V_35:
V_24 = V_3 -> V_20 . V_45 ( V_3 , ( T_2 * ) V_22 , V_23 ) ;
if ( V_24 < 0 )
F_11 ( V_3 -> V_29 ,
L_5 , V_24 ) ;
V_33:
F_7 ( & V_3 -> V_31 ) ;
return V_24 ;
}
static T_3 F_15 ( struct V_2 * V_3 , struct V_46 * V_47 ,
int V_48 , const char * V_49 )
{
int V_50 ;
V_48 = F_9 ( V_3 , ( T_2 * ) V_47 , V_48 ) ;
if ( V_48 < 0 )
return V_48 ;
else if ( V_48 < V_51 )
return - V_52 ;
V_50 = F_10 ( V_47 -> V_53 . V_33 . V_54 ) ;
if ( V_50 != 0 && V_49 )
F_11 ( V_3 -> V_29 , L_6 , V_50 , V_49 ) ;
return V_50 ;
}
T_3 F_16 ( struct V_55 * V_29 , V_27 V_56 , T_5 * V_57 ,
const char * V_49 )
{
struct V_46 V_58 ;
int V_24 ;
struct V_2 * V_3 = F_17 ( V_29 ) ;
V_58 . V_53 . V_59 = V_60 ;
if ( V_56 == V_61 || V_56 == V_62 ) {
V_58 . V_63 . V_64 . V_57 = V_56 ;
V_58 . V_63 . V_64 . V_65 = F_18 ( 0 ) ;
V_58 . V_53 . V_59 . V_66 -= F_18 ( sizeof( V_27 ) ) ;
} else {
if ( V_56 == V_67 ||
V_56 == V_68 )
V_58 . V_63 . V_64 . V_57 = V_69 ;
else
V_58 . V_63 . V_64 . V_57 = V_70 ;
V_58 . V_63 . V_64 . V_65 = F_18 ( 4 ) ;
V_58 . V_63 . V_64 . V_71 = V_56 ;
}
V_24 = F_15 ( V_3 , & V_58 , V_72 , V_49 ) ;
if ( ! V_24 )
* V_57 = V_58 . V_63 . V_73 . V_57 ;
return V_24 ;
}
void F_19 ( struct V_2 * V_3 )
{
struct V_46 V_58 ;
T_3 V_24 ;
V_58 . V_53 . V_59 = V_60 ;
V_58 . V_63 . V_64 . V_57 = V_70 ;
V_58 . V_63 . V_64 . V_65 = F_18 ( 4 ) ;
V_58 . V_63 . V_64 . V_71 = V_74 ;
V_24 = F_15 ( V_3 , & V_58 , V_72 ,
L_7 ) ;
}
static int F_20 ( struct V_2 * V_3 , T_6 V_75 )
{
struct V_46 V_76 ;
V_76 . V_53 . V_59 = V_77 ;
V_76 . V_63 . V_78 . V_75 = V_75 ;
return F_15 ( V_3 , & V_76 , V_72 ,
L_8 ) ;
}
int F_21 ( struct V_2 * V_3 )
{
struct V_46 V_58 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
T_3 V_24 ;
T_1 V_83 ;
unsigned int V_84 = 1 ;
V_58 . V_53 . V_59 = V_60 ;
V_58 . V_63 . V_64 . V_57 = V_70 ;
V_58 . V_63 . V_64 . V_65 = F_18 ( 4 ) ;
V_58 . V_63 . V_64 . V_71 = V_74 ;
V_24 = F_15 ( V_3 , & V_58 , V_72 , NULL ) ;
if ( V_24 == V_85 ) {
F_22 ( V_3 -> V_29 , L_9 ) ;
if ( F_20 ( V_3 , V_86 ) )
return V_24 ;
V_58 . V_53 . V_59 = V_60 ;
V_58 . V_63 . V_64 . V_57 = V_70 ;
V_58 . V_63 . V_64 . V_65 = F_18 ( 4 ) ;
V_58 . V_63 . V_64 . V_71 = V_74 ;
V_24 = F_15 ( V_3 , & V_58 , V_72 ,
NULL ) ;
}
if ( V_24 ) {
F_11 ( V_3 -> V_29 ,
L_10 ,
V_24 ) ;
goto V_13;
}
if ( F_10 ( V_58 . V_53 . V_33 . V_54 ) != 0 ||
F_10 ( V_58 . V_53 . V_33 . V_66 )
!= sizeof( V_58 . V_53 . V_33 ) + sizeof( T_1 ) + 4 * sizeof( T_1 ) )
return - V_87 ;
V_80 = & V_58 . V_63 . V_73 . V_57 . V_83 ;
V_83 = F_10 ( V_80 -> V_88 ) ;
if ( V_83 && V_83 < 1000 ) {
V_84 = 1000 ;
V_3 -> V_20 . V_89 = true ;
}
if ( V_83 )
V_3 -> V_20 . V_90 = F_23 ( V_83 * V_84 ) ;
V_83 = F_10 ( V_80 -> V_91 ) ;
if ( V_83 )
V_3 -> V_20 . V_92 = F_23 ( V_83 * V_84 ) ;
V_83 = F_10 ( V_80 -> V_93 ) ;
if ( V_83 )
V_3 -> V_20 . V_94 = F_23 ( V_83 * V_84 ) ;
V_83 = F_10 ( V_80 -> V_95 ) ;
if ( V_83 )
V_3 -> V_20 . V_96 = F_23 ( V_83 * V_84 ) ;
V_13:
V_58 . V_53 . V_59 = V_60 ;
V_58 . V_63 . V_64 . V_57 = V_70 ;
V_58 . V_63 . V_64 . V_65 = F_18 ( 4 ) ;
V_58 . V_63 . V_64 . V_71 = V_97 ;
V_24 = F_15 ( V_3 , & V_58 , V_72 ,
L_11 ) ;
if ( V_24 )
return V_24 ;
if ( F_10 ( V_58 . V_53 . V_33 . V_54 ) != 0 ||
F_10 ( V_58 . V_53 . V_33 . V_66 )
!= sizeof( V_58 . V_53 . V_33 ) + sizeof( T_1 ) + 3 * sizeof( T_1 ) )
return - V_87 ;
V_82 = & V_58 . V_63 . V_73 . V_57 . V_13 ;
V_3 -> V_20 . V_13 [ V_98 ] =
F_23 ( F_10 ( V_82 -> V_99 ) ) ;
V_3 -> V_20 . V_13 [ V_100 ] =
F_23 ( F_10 ( V_82 -> V_101 ) ) ;
V_3 -> V_20 . V_13 [ V_102 ] =
F_23 ( F_10 ( V_82 -> V_103 ) ) ;
if ( V_3 -> V_20 . V_13 [ V_98 ] < ( V_21 / 100 ) ) {
V_3 -> V_20 . V_13 [ V_98 ] = V_21 ;
V_3 -> V_20 . V_13 [ V_100 ] *= 1000 ;
V_3 -> V_20 . V_13 [ V_102 ] *= 1000 ;
V_3 -> V_20 . V_104 = true ;
F_22 ( V_3 -> V_29 , L_12 ) ;
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
int V_24 ;
struct V_46 V_47 ;
V_47 . V_53 . V_59 = V_105 ;
V_24 = F_15 ( V_3 , & V_47 , V_106 ,
L_13 ) ;
return V_24 ;
}
T_3 F_25 ( struct V_55 * V_29 , struct V_107 * V_108 ,
char * V_22 )
{
T_5 V_57 ;
T_3 V_24 ;
V_24 = F_16 ( V_29 , V_67 , & V_57 ,
L_14 ) ;
if ( V_24 )
return 0 ;
V_24 = sprintf ( V_22 , L_15 , ! V_57 . V_109 . V_110 ) ;
return V_24 ;
}
T_3 F_26 ( struct V_55 * V_29 , struct V_107 * V_108 ,
char * V_22 )
{
T_5 V_57 ;
T_3 V_24 ;
V_24 = F_16 ( V_29 , V_67 , & V_57 ,
L_16 ) ;
if ( V_24 )
return 0 ;
V_24 = sprintf ( V_22 , L_15 , ! V_57 . V_109 . V_111 ) ;
return V_24 ;
}
T_3 F_27 ( struct V_55 * V_29 , struct V_107 * V_108 ,
char * V_22 )
{
T_5 V_57 ;
T_3 V_24 ;
V_24 = F_16 ( V_29 , V_112 , & V_57 ,
L_17 ) ;
if ( V_24 )
return 0 ;
V_24 = sprintf ( V_22 , L_15 , V_57 . V_113 ) ;
return V_24 ;
}
T_3 F_28 ( struct V_55 * V_29 ,
struct V_107 * V_108 , char * V_22 )
{
T_5 V_57 ;
T_3 V_24 ;
V_24 = F_16 ( V_29 , V_68 , & V_57 ,
L_18 ) ;
if ( V_24 )
return 0 ;
V_24 = sprintf ( V_22 , L_15 , V_57 . V_114 . V_111 ) ;
return V_24 ;
}
static struct V_2 * F_29 ( int V_115 )
{
struct V_2 * V_116 , * V_3 = NULL ;
F_30 () ;
F_31 (pos, &tpm_chip_list, list) {
if ( V_115 != V_117 && V_115 != V_116 -> V_118 )
continue;
if ( F_32 ( V_116 -> V_29 -> V_119 -> V_120 ) ) {
V_3 = V_116 ;
break;
}
}
F_33 () ;
return V_3 ;
}
static int F_34 ( struct V_2 * V_3 , int V_121 , T_2 * V_122 )
{
int V_24 ;
struct V_46 V_47 ;
V_47 . V_53 . V_59 = V_123 ;
V_47 . V_63 . V_124 . V_121 = F_18 ( V_121 ) ;
V_24 = F_15 ( V_3 , & V_47 , V_125 ,
L_19 ) ;
if ( V_24 == 0 )
memcpy ( V_122 , V_47 . V_63 . V_126 . V_127 ,
V_128 ) ;
return V_24 ;
}
int F_35 ( T_1 V_115 , int V_121 , T_2 * V_122 )
{
struct V_2 * V_3 ;
int V_24 ;
V_3 = F_29 ( V_115 ) ;
if ( V_3 == NULL )
return - V_129 ;
V_24 = F_34 ( V_3 , V_121 , V_122 ) ;
F_36 ( V_3 ) ;
return V_24 ;
}
int F_37 ( T_1 V_115 , int V_121 , const T_2 * V_130 )
{
struct V_46 V_47 ;
int V_24 ;
struct V_2 * V_3 ;
V_3 = F_29 ( V_115 ) ;
if ( V_3 == NULL )
return - V_129 ;
V_47 . V_53 . V_59 = V_131 ;
V_47 . V_63 . V_132 . V_121 = F_18 ( V_121 ) ;
memcpy ( V_47 . V_63 . V_132 . V_130 , V_130 , V_128 ) ;
V_24 = F_15 ( V_3 , & V_47 , V_133 ,
L_20 ) ;
F_36 ( V_3 ) ;
return V_24 ;
}
int F_38 ( struct V_2 * V_3 )
{
int V_24 ;
unsigned int V_134 ;
unsigned int V_135 = 100 ;
unsigned long V_13 ;
struct V_46 V_47 ;
V_13 = F_8 ( V_3 , V_136 ) ;
V_134 = F_39 ( V_13 ) / V_135 ;
V_24 = F_24 ( V_3 ) ;
if ( V_24 )
return V_24 ;
do {
V_47 . V_53 . V_59 = V_123 ;
V_47 . V_63 . V_124 . V_121 = F_18 ( 0 ) ;
V_24 = F_9 ( V_3 , ( T_2 * ) & V_47 , V_125 ) ;
if ( V_24 == - V_44 ) {
F_22 ( V_3 -> V_29 , V_137 L_21 ) ;
F_12 ( V_135 ) ;
continue;
}
if ( V_24 < V_51 )
return - V_52 ;
V_24 = F_10 ( V_47 . V_53 . V_33 . V_54 ) ;
if ( V_24 == V_138 || V_24 == V_139 ) {
F_22 ( V_3 -> V_29 ,
L_22 , V_24 ) ;
return 0 ;
}
if ( V_24 != V_140 )
return V_24 ;
F_12 ( V_135 ) ;
} while ( -- V_134 > 0 );
return V_24 ;
}
int F_40 ( T_1 V_115 , void * V_47 , T_4 V_141 )
{
struct V_2 * V_3 ;
int V_24 ;
V_3 = F_29 ( V_115 ) ;
if ( V_3 == NULL )
return - V_129 ;
V_24 = F_15 ( V_3 , V_47 , V_141 , L_23 ) ;
F_36 ( V_3 ) ;
return V_24 ;
}
T_3 F_41 ( struct V_55 * V_29 , struct V_107 * V_108 ,
char * V_22 )
{
T_5 V_57 ;
T_2 V_142 [ V_128 ] ;
T_3 V_24 ;
int V_143 , V_144 , V_145 ;
char * V_146 = V_22 ;
struct V_2 * V_3 = F_17 ( V_29 ) ;
V_24 = F_16 ( V_29 , V_147 , & V_57 ,
L_24 ) ;
if ( V_24 )
return 0 ;
V_145 = F_10 ( V_57 . V_145 ) ;
for ( V_143 = 0 ; V_143 < V_145 ; V_143 ++ ) {
V_24 = F_34 ( V_3 , V_143 , V_142 ) ;
if ( V_24 )
break;
V_146 += sprintf ( V_146 , L_25 , V_143 ) ;
for ( V_144 = 0 ; V_144 < V_128 ; V_144 ++ )
V_146 += sprintf ( V_146 , L_26 , V_142 [ V_144 ] ) ;
V_146 += sprintf ( V_146 , L_27 ) ;
}
return V_146 - V_22 ;
}
T_3 F_42 ( struct V_55 * V_29 , struct V_107 * V_108 ,
char * V_22 )
{
T_2 * V_148 ;
struct V_46 V_58 ;
T_3 V_50 ;
int V_143 , V_24 ;
char * V_146 = V_22 ;
struct V_2 * V_3 = F_17 ( V_29 ) ;
V_58 . V_53 . V_59 = V_149 ;
V_50 = F_15 ( V_3 , & V_58 , V_150 ,
L_28 ) ;
if ( V_50 )
goto V_33;
V_148 = V_58 . V_63 . V_151 ;
V_146 +=
sprintf ( V_146 ,
L_29
L_30
L_31
L_32
L_33
L_34
L_35
L_36 ,
V_148 [ 0 ] , V_148 [ 1 ] , V_148 [ 2 ] , V_148 [ 3 ] ,
V_148 [ 4 ] , V_148 [ 5 ] ,
V_148 [ 6 ] , V_148 [ 7 ] ,
V_148 [ 12 ] , V_148 [ 13 ] , V_148 [ 14 ] , V_148 [ 15 ] ,
V_148 [ 16 ] , V_148 [ 17 ] , V_148 [ 18 ] , V_148 [ 19 ] ,
V_148 [ 20 ] , V_148 [ 21 ] , V_148 [ 22 ] , V_148 [ 23 ] ,
F_10 ( * ( ( V_27 * ) ( V_148 + 24 ) ) ) ) ;
for ( V_143 = 0 ; V_143 < 256 ; V_143 ++ ) {
V_146 += sprintf ( V_146 , L_26 , V_148 [ V_143 + 28 ] ) ;
if ( ( V_143 + 1 ) % 16 == 0 )
V_146 += sprintf ( V_146 , L_27 ) ;
}
V_33:
V_24 = V_146 - V_22 ;
return V_24 ;
}
T_3 F_43 ( struct V_55 * V_29 , struct V_107 * V_108 ,
char * V_22 )
{
T_5 V_57 ;
T_3 V_24 ;
char * V_146 = V_22 ;
V_24 = F_16 ( V_29 , V_152 , & V_57 ,
L_37 ) ;
if ( V_24 )
return 0 ;
V_146 += sprintf ( V_146 , L_38 ,
F_10 ( V_57 . V_153 ) ) ;
V_24 = F_16 ( V_29 , V_62 , & V_57 ,
L_39 ) ;
if ( ! V_24 ) {
V_146 += sprintf ( V_146 ,
L_40 ,
V_57 . V_154 . V_155 ,
V_57 . V_154 . V_156 ,
V_57 . V_154 . V_157 ,
V_57 . V_154 . V_158 ) ;
} else {
V_24 = F_16 ( V_29 , V_61 , & V_57 ,
L_41 ) ;
if ( V_24 )
return 0 ;
V_146 += sprintf ( V_146 ,
L_40 ,
V_57 . V_159 . V_155 ,
V_57 . V_159 . V_156 ,
V_57 . V_159 . V_157 ,
V_57 . V_159 . V_158 ) ;
}
return V_146 - V_22 ;
}
T_3 F_44 ( struct V_55 * V_29 , struct V_107 * V_108 ,
char * V_22 )
{
struct V_2 * V_3 = F_17 ( V_29 ) ;
if ( V_3 -> V_20 . V_13 [ V_102 ] == 0 )
return 0 ;
return sprintf ( V_22 , L_42 ,
F_45 ( V_3 -> V_20 . V_13 [ V_98 ] ) ,
F_45 ( V_3 -> V_20 . V_13 [ V_100 ] ) ,
F_45 ( V_3 -> V_20 . V_13 [ V_102 ] ) ,
V_3 -> V_20 . V_104
? L_43 : L_44 ) ;
}
T_3 F_46 ( struct V_55 * V_29 , struct V_107 * V_108 ,
char * V_22 )
{
struct V_2 * V_3 = F_17 ( V_29 ) ;
return sprintf ( V_22 , L_45 ,
F_45 ( V_3 -> V_20 . V_90 ) ,
F_45 ( V_3 -> V_20 . V_92 ) ,
F_45 ( V_3 -> V_20 . V_94 ) ,
F_45 ( V_3 -> V_20 . V_96 ) ,
V_3 -> V_20 . V_89
? L_43 : L_44 ) ;
}
T_3 F_47 ( struct V_55 * V_29 , struct V_107 * V_108 ,
const char * V_22 , T_4 V_25 )
{
struct V_2 * V_3 = F_17 ( V_29 ) ;
if ( V_3 == NULL )
return 0 ;
V_3 -> V_20 . V_43 ( V_3 ) ;
return V_25 ;
}
static bool F_48 ( struct V_2 * V_3 , T_2 V_160 ,
bool V_161 , bool * V_162 )
{
T_2 V_37 = V_3 -> V_20 . V_37 ( V_3 ) ;
* V_162 = false ;
if ( ( V_37 & V_160 ) == V_160 )
return true ;
if ( V_161 && V_3 -> V_20 . V_40 ( V_3 , V_37 ) ) {
* V_162 = true ;
return true ;
}
return false ;
}
int F_49 ( struct V_2 * V_3 , T_2 V_160 , unsigned long V_83 ,
T_7 * V_163 , bool V_161 )
{
unsigned long V_26 ;
long V_24 ;
T_2 V_37 ;
bool V_162 = false ;
V_37 = V_3 -> V_20 . V_37 ( V_3 ) ;
if ( ( V_37 & V_160 ) == V_160 )
return 0 ;
V_26 = V_36 + V_83 ;
if ( V_3 -> V_20 . V_34 ) {
V_164:
V_83 = V_26 - V_36 ;
if ( ( long ) V_83 <= 0 )
return - V_44 ;
V_24 = F_50 ( * V_163 ,
F_48 ( V_3 , V_160 , V_161 ,
& V_162 ) ,
V_83 ) ;
if ( V_24 > 0 ) {
if ( V_162 )
return - V_41 ;
return 0 ;
}
if ( V_24 == - V_165 && F_51 ( V_166 ) ) {
F_52 ( V_167 ) ;
goto V_164;
}
} else {
do {
F_12 ( V_42 ) ;
V_37 = V_3 -> V_20 . V_37 ( V_3 ) ;
if ( ( V_37 & V_160 ) == V_160 )
return 0 ;
} while ( F_14 ( V_36 , V_26 ) );
}
return - V_44 ;
}
int F_53 ( struct V_168 * V_168 , struct V_169 * V_169 )
{
struct V_170 * V_171 = V_169 -> V_172 ;
struct V_2 * V_3 = F_4 ( V_171 , struct V_2 ,
V_20 . V_173 ) ;
if ( F_54 ( 0 , & V_3 -> V_174 ) ) {
F_55 ( V_3 -> V_29 , L_46 ) ;
return - V_175 ;
}
V_3 -> V_8 = F_56 ( V_9 , V_176 ) ;
if ( V_3 -> V_8 == NULL ) {
F_57 ( 0 , & V_3 -> V_174 ) ;
return - V_177 ;
}
F_6 ( & V_3 -> V_7 , 0 ) ;
V_169 -> V_172 = V_3 ;
F_58 ( V_3 -> V_29 ) ;
return 0 ;
}
int F_59 ( struct V_168 * V_168 , struct V_169 * V_169 )
{
struct V_2 * V_3 = V_169 -> V_172 ;
F_60 ( & V_3 -> V_178 ) ;
F_61 ( & V_3 -> V_4 ) ;
V_169 -> V_172 = NULL ;
F_6 ( & V_3 -> V_7 , 0 ) ;
F_62 ( V_3 -> V_8 ) ;
F_57 ( 0 , & V_3 -> V_174 ) ;
F_63 ( V_3 -> V_29 ) ;
return 0 ;
}
T_3 F_64 ( struct V_169 * V_169 , const char T_8 * V_22 ,
T_4 V_179 , T_9 * V_180 )
{
struct V_2 * V_3 = V_169 -> V_172 ;
T_4 V_181 = V_179 ;
T_3 V_182 ;
if ( F_65 ( & V_3 -> V_7 ) != 0 )
return - V_175 ;
if ( V_181 > V_9 )
return - V_30 ;
F_5 ( & V_3 -> V_6 ) ;
if ( F_66
( V_3 -> V_8 , ( void T_8 * ) V_22 , V_181 ) ) {
F_7 ( & V_3 -> V_6 ) ;
return - V_52 ;
}
V_182 = F_9 ( V_3 , V_3 -> V_8 , V_9 ) ;
if ( V_182 < 0 ) {
F_7 ( & V_3 -> V_6 ) ;
return V_182 ;
}
F_6 ( & V_3 -> V_7 , V_182 ) ;
F_7 ( & V_3 -> V_6 ) ;
F_67 ( & V_3 -> V_178 , V_36 + ( 60 * V_21 ) ) ;
return V_181 ;
}
T_3 F_68 ( struct V_169 * V_169 , char T_8 * V_22 ,
T_4 V_179 , T_9 * V_180 )
{
struct V_2 * V_3 = V_169 -> V_172 ;
T_3 V_183 ;
int V_24 ;
F_60 ( & V_3 -> V_178 ) ;
F_61 ( & V_3 -> V_4 ) ;
V_183 = F_65 ( & V_3 -> V_7 ) ;
if ( V_183 > 0 ) {
T_3 V_184 = V_183 ;
if ( V_179 < V_183 )
V_183 = V_179 ;
F_5 ( & V_3 -> V_6 ) ;
V_24 = F_69 ( V_22 , V_3 -> V_8 , V_183 ) ;
memset ( V_3 -> V_8 , 0 , V_184 ) ;
if ( V_24 )
V_183 = - V_52 ;
F_7 ( & V_3 -> V_6 ) ;
}
F_6 ( & V_3 -> V_7 , 0 ) ;
return V_183 ;
}
void F_70 ( struct V_55 * V_29 )
{
struct V_2 * V_3 = F_17 ( V_29 ) ;
if ( V_3 == NULL ) {
F_11 ( V_29 , L_47 ) ;
return;
}
F_71 ( & V_185 ) ;
F_72 ( & V_3 -> V_186 ) ;
F_73 ( & V_185 ) ;
F_74 () ;
F_75 ( & V_3 -> V_20 . V_173 ) ;
F_76 ( & V_29 -> V_187 , V_3 -> V_20 . V_188 ) ;
F_77 ( & V_29 -> V_187 ) ;
F_78 ( V_3 -> V_189 ) ;
F_63 ( V_3 -> V_29 ) ;
}
int F_79 ( struct V_55 * V_29 )
{
struct V_2 * V_3 = F_17 ( V_29 ) ;
struct V_46 V_47 ;
int V_24 , V_190 ;
T_2 V_191 [ V_128 ] = { 0 } ;
if ( V_3 == NULL )
return - V_129 ;
if ( V_192 ) {
V_47 . V_53 . V_59 = V_131 ;
V_47 . V_63 . V_132 . V_121 = F_18 ( V_192 ) ;
memcpy ( V_47 . V_63 . V_132 . V_130 , V_191 ,
V_128 ) ;
V_24 = F_15 ( V_3 , & V_47 , V_133 ,
L_48 ) ;
}
for ( V_190 = 0 ; V_190 < V_193 ; V_190 ++ ) {
V_47 . V_53 . V_59 = V_194 ;
V_24 = F_15 ( V_3 , & V_47 , V_195 , NULL ) ;
if ( V_24 != V_196 )
break;
F_12 ( V_197 ) ;
}
if ( V_24 )
F_11 ( V_3 -> V_29 ,
L_49 , V_24 ) ;
else if ( V_190 > 0 )
F_80 ( V_3 -> V_29 , L_50 ,
V_190 * V_197 ) ;
return V_24 ;
}
int F_81 ( struct V_55 * V_29 )
{
struct V_2 * V_3 = F_17 ( V_29 ) ;
if ( V_3 == NULL )
return - V_129 ;
return 0 ;
}
int F_82 ( T_1 V_115 , T_2 * V_33 , T_4 V_198 )
{
struct V_2 * V_3 ;
struct V_46 V_58 ;
T_1 V_199 , V_200 = F_83 ( T_1 , V_198 , V_201 ) ;
int V_50 , V_202 = 0 , V_203 = 5 ;
T_2 * V_204 = V_33 ;
V_3 = F_29 ( V_115 ) ;
if ( V_3 == NULL )
return - V_129 ;
if ( ! V_33 || ! V_200 || V_198 > V_201 )
return - V_87 ;
do {
V_58 . V_53 . V_59 = V_205 ;
V_58 . V_63 . V_206 . V_200 = F_18 ( V_200 ) ;
V_50 = F_15 ( V_3 , & V_58 ,
V_207 + V_200 ,
L_51 ) ;
if ( V_50 )
break;
V_199 = F_10 ( V_58 . V_63 . V_208 . V_209 ) ;
memcpy ( V_204 , V_58 . V_63 . V_208 . V_210 , V_199 ) ;
V_204 += V_199 ;
V_202 += V_199 ;
V_200 -= V_199 ;
} while ( V_203 -- && V_202 < V_198 );
return V_202 ? V_202 : - V_211 ;
}
void F_84 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return;
if ( V_3 -> V_20 . V_212 )
V_3 -> V_20 . V_212 ( V_3 -> V_29 ) ;
F_57 ( V_3 -> V_118 , V_213 ) ;
}
void F_85 ( struct V_55 * V_29 )
{
struct V_2 * V_3 = F_17 ( V_29 ) ;
if ( ! V_3 )
return;
F_84 ( V_3 ) ;
V_3 -> V_212 ( V_29 ) ;
F_86 ( V_3 ) ;
}
struct V_2 * F_87 ( struct V_55 * V_29 ,
const struct V_214 * V_215 )
{
struct V_2 * V_3 ;
V_3 = F_56 ( sizeof( * V_3 ) , V_176 ) ;
if ( V_3 == NULL )
return NULL ;
F_88 ( & V_3 -> V_6 ) ;
F_88 ( & V_3 -> V_31 ) ;
F_89 ( & V_3 -> V_186 ) ;
F_90 ( & V_3 -> V_4 , F_3 ) ;
F_91 ( & V_3 -> V_178 , F_1 ,
( unsigned long ) V_3 ) ;
memcpy ( & V_3 -> V_20 , V_215 , sizeof( struct V_214 ) ) ;
V_3 -> V_118 = F_92 ( V_213 , V_216 ) ;
if ( V_3 -> V_118 >= V_216 ) {
F_11 ( V_29 , L_52 ) ;
goto V_217;
} else if ( V_3 -> V_118 == 0 )
V_3 -> V_20 . V_173 . V_218 = V_219 ;
else
V_3 -> V_20 . V_173 . V_218 = V_220 ;
F_93 ( V_3 -> V_118 , V_213 ) ;
F_94 ( V_3 -> V_221 , sizeof( V_3 -> V_221 ) , L_53 , L_54 ,
V_3 -> V_118 ) ;
V_3 -> V_20 . V_173 . V_222 = V_3 -> V_221 ;
V_3 -> V_20 . V_173 . V_223 = V_29 ;
V_3 -> V_29 = F_58 ( V_29 ) ;
V_3 -> V_212 = V_29 -> V_212 ;
V_29 -> V_212 = F_85 ;
F_95 ( V_29 , V_3 ) ;
if ( F_96 ( & V_3 -> V_20 . V_173 ) ) {
F_11 ( V_3 -> V_29 ,
L_55 ,
V_3 -> V_20 . V_173 . V_222 ,
V_3 -> V_20 . V_173 . V_218 ) ;
goto F_63;
}
if ( F_97 ( & V_29 -> V_187 , V_3 -> V_20 . V_188 ) ) {
F_75 ( & V_3 -> V_20 . V_173 ) ;
goto F_63;
}
if ( F_98 ( & V_29 -> V_187 ) ) {
F_75 ( & V_3 -> V_20 . V_173 ) ;
goto F_63;
}
V_3 -> V_189 = F_99 ( V_3 -> V_221 ) ;
F_71 ( & V_185 ) ;
F_100 ( & V_3 -> V_186 , & V_224 ) ;
F_73 ( & V_185 ) ;
return V_3 ;
F_63:
F_63 ( V_3 -> V_29 ) ;
V_217:
F_86 ( V_3 ) ;
return NULL ;
}
