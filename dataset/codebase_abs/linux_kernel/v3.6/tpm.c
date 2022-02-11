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
else if ( V_48 < V_51 )
return - V_52 ;
V_50 = F_10 ( V_47 -> V_53 . V_33 . V_54 ) ;
if ( V_50 != 0 )
F_11 ( V_3 -> V_28 , L_6 , V_50 , V_49 ) ;
return V_50 ;
}
T_2 F_16 ( struct V_55 * V_28 , V_26 V_56 , T_4 * V_57 ,
const char * V_49 )
{
struct V_46 V_58 ;
int V_23 ;
struct V_2 * V_3 = F_17 ( V_28 ) ;
V_58 . V_53 . V_59 = V_60 ;
if ( V_56 == V_61 || V_56 == V_62 ) {
V_58 . V_63 . V_64 . V_57 = V_56 ;
V_58 . V_63 . V_64 . V_65 = F_18 ( 0 ) ;
V_58 . V_53 . V_59 . V_66 -= F_18 ( sizeof( V_26 ) ) ;
} else {
if ( V_56 == V_67 ||
V_56 == V_68 )
V_58 . V_63 . V_64 . V_57 = V_69 ;
else
V_58 . V_63 . V_64 . V_57 = V_70 ;
V_58 . V_63 . V_64 . V_65 = F_18 ( 4 ) ;
V_58 . V_63 . V_64 . V_71 = V_56 ;
}
V_23 = F_15 ( V_3 , & V_58 , V_72 , V_49 ) ;
if ( ! V_23 )
* V_57 = V_58 . V_63 . V_73 . V_57 ;
return V_23 ;
}
void F_19 ( struct V_2 * V_3 )
{
struct V_46 V_58 ;
T_2 V_23 ;
V_58 . V_53 . V_59 = V_60 ;
V_58 . V_63 . V_64 . V_57 = V_70 ;
V_58 . V_63 . V_64 . V_65 = F_18 ( 4 ) ;
V_58 . V_63 . V_64 . V_71 = V_74 ;
V_23 = F_15 ( V_3 , & V_58 , V_72 ,
L_7 ) ;
}
int F_20 ( struct V_2 * V_3 )
{
struct V_46 V_58 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
T_2 V_23 ;
T_1 V_79 ;
unsigned int V_80 = 1 ;
V_58 . V_53 . V_59 = V_60 ;
V_58 . V_63 . V_64 . V_57 = V_70 ;
V_58 . V_63 . V_64 . V_65 = F_18 ( 4 ) ;
V_58 . V_63 . V_64 . V_71 = V_74 ;
V_23 = F_15 ( V_3 , & V_58 , V_72 ,
L_7 ) ;
if ( V_23 )
goto V_13;
if ( F_10 ( V_58 . V_53 . V_33 . V_54 ) != 0 ||
F_10 ( V_58 . V_53 . V_33 . V_66 )
!= sizeof( V_58 . V_53 . V_33 ) + sizeof( T_1 ) + 4 * sizeof( T_1 ) )
return - V_81 ;
V_76 = & V_58 . V_63 . V_73 . V_57 . V_79 ;
V_79 = F_10 ( V_76 -> V_82 ) ;
if ( V_79 && V_79 < 1000 ) {
V_80 = 1000 ;
V_3 -> V_19 . V_83 = true ;
}
if ( V_79 )
V_3 -> V_19 . V_84 = F_21 ( V_79 * V_80 ) ;
V_79 = F_10 ( V_76 -> V_85 ) ;
if ( V_79 )
V_3 -> V_19 . V_86 = F_21 ( V_79 * V_80 ) ;
V_79 = F_10 ( V_76 -> V_87 ) ;
if ( V_79 )
V_3 -> V_19 . V_88 = F_21 ( V_79 * V_80 ) ;
V_79 = F_10 ( V_76 -> V_89 ) ;
if ( V_79 )
V_3 -> V_19 . V_90 = F_21 ( V_79 * V_80 ) ;
V_13:
V_58 . V_53 . V_59 = V_60 ;
V_58 . V_63 . V_64 . V_57 = V_70 ;
V_58 . V_63 . V_64 . V_65 = F_18 ( 4 ) ;
V_58 . V_63 . V_64 . V_71 = V_91 ;
V_23 = F_15 ( V_3 , & V_58 , V_72 ,
L_8 ) ;
if ( V_23 )
return V_23 ;
if ( F_10 ( V_58 . V_53 . V_33 . V_54 ) != 0 ||
F_10 ( V_58 . V_53 . V_33 . V_66 )
!= sizeof( V_58 . V_53 . V_33 ) + sizeof( T_1 ) + 3 * sizeof( T_1 ) )
return - V_81 ;
V_78 = & V_58 . V_63 . V_73 . V_57 . V_13 ;
V_3 -> V_19 . V_13 [ V_92 ] =
F_21 ( F_10 ( V_78 -> V_93 ) ) ;
V_3 -> V_19 . V_13 [ V_94 ] =
F_21 ( F_10 ( V_78 -> V_95 ) ) ;
V_3 -> V_19 . V_13 [ V_96 ] =
F_21 ( F_10 ( V_78 -> V_97 ) ) ;
if ( V_3 -> V_19 . V_13 [ V_92 ] < ( V_20 / 100 ) ) {
V_3 -> V_19 . V_13 [ V_92 ] = V_20 ;
V_3 -> V_19 . V_13 [ V_94 ] *= 1000 ;
V_3 -> V_19 . V_13 [ V_96 ] *= 1000 ;
V_3 -> V_19 . V_98 = true ;
F_22 ( V_3 -> V_28 , L_9 ) ;
}
return 0 ;
}
static int F_23 ( struct V_2 * V_3 )
{
int V_23 ;
struct V_46 V_47 ;
V_47 . V_53 . V_59 = V_99 ;
V_23 = F_15 ( V_3 , & V_47 , V_100 ,
L_10 ) ;
return V_23 ;
}
T_2 F_24 ( struct V_55 * V_28 , struct V_101 * V_102 ,
char * V_21 )
{
T_4 V_57 ;
T_2 V_23 ;
V_23 = F_16 ( V_28 , V_67 , & V_57 ,
L_11 ) ;
if ( V_23 )
return 0 ;
V_23 = sprintf ( V_21 , L_12 , ! V_57 . V_103 . V_104 ) ;
return V_23 ;
}
T_2 F_25 ( struct V_55 * V_28 , struct V_101 * V_102 ,
char * V_21 )
{
T_4 V_57 ;
T_2 V_23 ;
V_23 = F_16 ( V_28 , V_67 , & V_57 ,
L_13 ) ;
if ( V_23 )
return 0 ;
V_23 = sprintf ( V_21 , L_12 , ! V_57 . V_103 . V_105 ) ;
return V_23 ;
}
T_2 F_26 ( struct V_55 * V_28 , struct V_101 * V_102 ,
char * V_21 )
{
T_4 V_57 ;
T_2 V_23 ;
V_23 = F_16 ( V_28 , V_106 , & V_57 ,
L_14 ) ;
if ( V_23 )
return 0 ;
V_23 = sprintf ( V_21 , L_12 , V_57 . V_107 ) ;
return V_23 ;
}
T_2 F_27 ( struct V_55 * V_28 ,
struct V_101 * V_102 , char * V_21 )
{
T_4 V_57 ;
T_2 V_23 ;
V_23 = F_16 ( V_28 , V_68 , & V_57 ,
L_15 ) ;
if ( V_23 )
return 0 ;
V_23 = sprintf ( V_21 , L_12 , V_57 . V_108 . V_105 ) ;
return V_23 ;
}
static struct V_2 * F_28 ( int V_109 )
{
struct V_2 * V_110 , * V_3 = NULL ;
F_29 () ;
F_30 (pos, &tpm_chip_list, list) {
if ( V_109 != V_111 && V_109 != V_110 -> V_112 )
continue;
if ( F_31 ( V_110 -> V_28 -> V_113 -> V_114 ) ) {
V_3 = V_110 ;
break;
}
}
F_32 () ;
return V_3 ;
}
static int F_33 ( struct V_2 * V_3 , int V_115 , V_32 * V_116 )
{
int V_23 ;
struct V_46 V_47 ;
V_47 . V_53 . V_59 = V_117 ;
V_47 . V_63 . V_118 . V_115 = F_18 ( V_115 ) ;
V_23 = F_15 ( V_3 , & V_47 , V_119 ,
L_16 ) ;
if ( V_23 == 0 )
memcpy ( V_116 , V_47 . V_63 . V_120 . V_121 ,
V_122 ) ;
return V_23 ;
}
int F_34 ( T_1 V_109 , int V_115 , V_32 * V_116 )
{
struct V_2 * V_3 ;
int V_23 ;
V_3 = F_28 ( V_109 ) ;
if ( V_3 == NULL )
return - V_123 ;
V_23 = F_33 ( V_3 , V_115 , V_116 ) ;
F_35 ( V_3 ) ;
return V_23 ;
}
int F_36 ( T_1 V_109 , int V_115 , const V_32 * V_124 )
{
struct V_46 V_47 ;
int V_23 ;
struct V_2 * V_3 ;
V_3 = F_28 ( V_109 ) ;
if ( V_3 == NULL )
return - V_123 ;
V_47 . V_53 . V_59 = V_125 ;
V_47 . V_63 . V_126 . V_115 = F_18 ( V_115 ) ;
memcpy ( V_47 . V_63 . V_126 . V_124 , V_124 , V_122 ) ;
V_23 = F_15 ( V_3 , & V_47 , V_127 ,
L_17 ) ;
F_35 ( V_3 ) ;
return V_23 ;
}
int F_37 ( struct V_2 * V_3 )
{
int V_23 ;
unsigned int V_128 ;
unsigned int V_129 = 1000 ;
unsigned long V_13 ;
struct V_46 V_47 ;
V_13 = F_8 ( V_3 ,
V_130 ) ;
V_128 = F_38 ( V_13 ) / V_129 ;
V_23 = F_23 ( V_3 ) ;
if ( V_23 )
return V_23 ;
do {
V_47 . V_53 . V_59 = V_117 ;
V_47 . V_63 . V_118 . V_115 = F_18 ( 0 ) ;
V_23 = F_9 ( V_3 , ( V_32 * ) & V_47 , V_119 ) ;
if ( V_23 < V_51 )
return - V_52 ;
V_23 = F_10 ( V_47 . V_53 . V_33 . V_54 ) ;
if ( V_23 == V_131 || V_23 == V_132 ) {
F_22 ( V_3 -> V_28 ,
L_18 , V_23 ) ;
return 0 ;
}
if ( V_23 != V_133 )
return V_23 ;
F_12 ( V_129 ) ;
} while ( -- V_128 > 0 );
return V_23 ;
}
int F_39 ( T_1 V_109 , void * V_47 , T_3 V_134 )
{
struct V_2 * V_3 ;
int V_23 ;
V_3 = F_28 ( V_109 ) ;
if ( V_3 == NULL )
return - V_123 ;
V_23 = F_15 ( V_3 , V_47 , V_134 , L_19 ) ;
F_35 ( V_3 ) ;
return V_23 ;
}
T_2 F_40 ( struct V_55 * V_28 , struct V_101 * V_102 ,
char * V_21 )
{
T_4 V_57 ;
V_32 V_135 [ V_122 ] ;
T_2 V_23 ;
int V_136 , V_137 , V_138 ;
char * V_139 = V_21 ;
struct V_2 * V_3 = F_17 ( V_28 ) ;
V_23 = F_16 ( V_28 , V_140 , & V_57 ,
L_20 ) ;
if ( V_23 )
return 0 ;
V_138 = F_10 ( V_57 . V_138 ) ;
for ( V_136 = 0 ; V_136 < V_138 ; V_136 ++ ) {
V_23 = F_33 ( V_3 , V_136 , V_135 ) ;
if ( V_23 )
break;
V_139 += sprintf ( V_139 , L_21 , V_136 ) ;
for ( V_137 = 0 ; V_137 < V_122 ; V_137 ++ )
V_139 += sprintf ( V_139 , L_22 , V_135 [ V_137 ] ) ;
V_139 += sprintf ( V_139 , L_23 ) ;
}
return V_139 - V_21 ;
}
T_2 F_41 ( struct V_55 * V_28 , struct V_101 * V_102 ,
char * V_21 )
{
V_32 * V_141 ;
struct V_46 V_58 ;
T_2 V_50 ;
int V_136 , V_23 ;
char * V_139 = V_21 ;
struct V_2 * V_3 = F_17 ( V_28 ) ;
V_58 . V_53 . V_59 = V_142 ;
V_50 = F_15 ( V_3 , & V_58 , V_143 ,
L_24 ) ;
if ( V_50 )
goto V_33;
V_141 = V_58 . V_63 . V_144 ;
V_139 +=
sprintf ( V_139 ,
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32 ,
V_141 [ 0 ] , V_141 [ 1 ] , V_141 [ 2 ] , V_141 [ 3 ] ,
V_141 [ 4 ] , V_141 [ 5 ] ,
V_141 [ 6 ] , V_141 [ 7 ] ,
V_141 [ 12 ] , V_141 [ 13 ] , V_141 [ 14 ] , V_141 [ 15 ] ,
V_141 [ 16 ] , V_141 [ 17 ] , V_141 [ 18 ] , V_141 [ 19 ] ,
V_141 [ 20 ] , V_141 [ 21 ] , V_141 [ 22 ] , V_141 [ 23 ] ,
F_10 ( * ( ( V_26 * ) ( V_141 + 24 ) ) ) ) ;
for ( V_136 = 0 ; V_136 < 256 ; V_136 ++ ) {
V_139 += sprintf ( V_139 , L_22 , V_141 [ V_136 + 28 ] ) ;
if ( ( V_136 + 1 ) % 16 == 0 )
V_139 += sprintf ( V_139 , L_23 ) ;
}
V_33:
V_23 = V_139 - V_21 ;
return V_23 ;
}
T_2 F_42 ( struct V_55 * V_28 , struct V_101 * V_102 ,
char * V_21 )
{
T_4 V_57 ;
T_2 V_23 ;
char * V_139 = V_21 ;
V_23 = F_16 ( V_28 , V_145 , & V_57 ,
L_33 ) ;
if ( V_23 )
return 0 ;
V_139 += sprintf ( V_139 , L_34 ,
F_10 ( V_57 . V_146 ) ) ;
V_23 = F_16 ( V_28 , V_61 , & V_57 ,
L_35 ) ;
if ( V_23 )
return 0 ;
V_139 += sprintf ( V_139 ,
L_36 ,
V_57 . V_147 . V_148 , V_57 . V_147 . V_149 ,
V_57 . V_147 . V_150 , V_57 . V_147 . V_151 ) ;
return V_139 - V_21 ;
}
T_2 F_43 ( struct V_55 * V_28 ,
struct V_101 * V_102 , char * V_21 )
{
T_4 V_57 ;
T_2 V_23 ;
char * V_139 = V_21 ;
V_23 = F_16 ( V_28 , V_145 , & V_57 ,
L_33 ) ;
if ( V_23 )
return 0 ;
V_139 += sprintf ( V_139 , L_34 ,
F_10 ( V_57 . V_146 ) ) ;
V_23 = F_16 ( V_28 , V_62 , & V_57 ,
L_37 ) ;
if ( V_23 )
return 0 ;
V_139 += sprintf ( V_139 ,
L_36 ,
V_57 . V_152 . V_148 , V_57 . V_152 . V_149 ,
V_57 . V_152 . V_150 ,
V_57 . V_152 . V_151 ) ;
return V_139 - V_21 ;
}
T_2 F_44 ( struct V_55 * V_28 , struct V_101 * V_102 ,
char * V_21 )
{
struct V_2 * V_3 = F_17 ( V_28 ) ;
if ( V_3 -> V_19 . V_13 [ V_96 ] == 0 )
return 0 ;
return sprintf ( V_21 , L_38 ,
F_45 ( V_3 -> V_19 . V_13 [ V_92 ] ) ,
F_45 ( V_3 -> V_19 . V_13 [ V_94 ] ) ,
F_45 ( V_3 -> V_19 . V_13 [ V_96 ] ) ,
V_3 -> V_19 . V_98
? L_39 : L_40 ) ;
}
T_2 F_46 ( struct V_55 * V_28 , struct V_101 * V_102 ,
char * V_21 )
{
struct V_2 * V_3 = F_17 ( V_28 ) ;
return sprintf ( V_21 , L_41 ,
F_45 ( V_3 -> V_19 . V_84 ) ,
F_45 ( V_3 -> V_19 . V_86 ) ,
F_45 ( V_3 -> V_19 . V_88 ) ,
F_45 ( V_3 -> V_19 . V_90 ) ,
V_3 -> V_19 . V_83
? L_39 : L_40 ) ;
}
T_2 F_47 ( struct V_55 * V_28 , struct V_101 * V_102 ,
const char * V_21 , T_3 V_24 )
{
struct V_2 * V_3 = F_17 ( V_28 ) ;
if ( V_3 == NULL )
return 0 ;
V_3 -> V_19 . V_43 ( V_3 ) ;
return V_24 ;
}
int F_48 ( struct V_2 * V_3 , V_32 V_153 , unsigned long V_79 ,
T_5 * V_154 )
{
unsigned long V_25 ;
long V_23 ;
V_32 V_37 ;
V_37 = V_3 -> V_19 . V_37 ( V_3 ) ;
if ( ( V_37 & V_153 ) == V_153 )
return 0 ;
V_25 = V_36 + V_79 ;
if ( V_3 -> V_19 . V_34 ) {
V_155:
V_79 = V_25 - V_36 ;
if ( ( long ) V_79 <= 0 )
return - V_44 ;
V_23 = F_49 ( * V_154 ,
( ( V_3 -> V_19 . V_37 ( V_3 )
& V_153 ) == V_153 ) ,
V_79 ) ;
if ( V_23 > 0 )
return 0 ;
if ( V_23 == - V_156 && F_50 ( V_157 ) ) {
F_51 ( V_158 ) ;
goto V_155;
}
} else {
do {
F_12 ( V_42 ) ;
V_37 = V_3 -> V_19 . V_37 ( V_3 ) ;
if ( ( V_37 & V_153 ) == V_153 )
return 0 ;
} while ( F_14 ( V_36 , V_25 ) );
}
return - V_44 ;
}
int F_52 ( struct V_159 * V_159 , struct V_160 * V_160 )
{
int V_161 = F_53 ( V_159 ) ;
struct V_2 * V_3 = NULL , * V_110 ;
F_29 () ;
F_30 (pos, &tpm_chip_list, list) {
if ( V_110 -> V_19 . V_162 . V_161 == V_161 ) {
V_3 = V_110 ;
F_54 ( V_3 -> V_28 ) ;
break;
}
}
F_32 () ;
if ( ! V_3 )
return - V_123 ;
if ( F_55 ( 0 , & V_3 -> V_163 ) ) {
F_56 ( V_3 -> V_28 , L_42 ) ;
F_57 ( V_3 -> V_28 ) ;
return - V_164 ;
}
V_3 -> V_8 = F_58 ( V_9 , V_165 ) ;
if ( V_3 -> V_8 == NULL ) {
F_59 ( 0 , & V_3 -> V_163 ) ;
F_57 ( V_3 -> V_28 ) ;
return - V_166 ;
}
F_6 ( & V_3 -> V_7 , 0 ) ;
V_160 -> V_167 = V_3 ;
return 0 ;
}
int F_60 ( struct V_159 * V_159 , struct V_160 * V_160 )
{
struct V_2 * V_3 = V_160 -> V_167 ;
F_61 ( & V_3 -> V_168 ) ;
F_62 ( & V_3 -> V_4 ) ;
V_160 -> V_167 = NULL ;
F_6 ( & V_3 -> V_7 , 0 ) ;
F_63 ( V_3 -> V_8 ) ;
F_59 ( 0 , & V_3 -> V_163 ) ;
F_57 ( V_3 -> V_28 ) ;
return 0 ;
}
T_2 F_64 ( struct V_160 * V_160 , const char T_6 * V_21 ,
T_3 V_169 , T_7 * V_170 )
{
struct V_2 * V_3 = V_160 -> V_167 ;
T_3 V_171 = V_169 , V_172 ;
while ( F_65 ( & V_3 -> V_7 ) != 0 )
F_12 ( V_42 ) ;
F_5 ( & V_3 -> V_6 ) ;
if ( V_171 > V_9 )
V_171 = V_9 ;
if ( F_66
( V_3 -> V_8 , ( void T_6 * ) V_21 , V_171 ) ) {
F_7 ( & V_3 -> V_6 ) ;
return - V_52 ;
}
V_172 = F_9 ( V_3 , V_3 -> V_8 , V_9 ) ;
F_6 ( & V_3 -> V_7 , V_172 ) ;
F_7 ( & V_3 -> V_6 ) ;
F_67 ( & V_3 -> V_168 , V_36 + ( 60 * V_20 ) ) ;
return V_171 ;
}
T_2 F_68 ( struct V_160 * V_160 , char T_6 * V_21 ,
T_3 V_169 , T_7 * V_170 )
{
struct V_2 * V_3 = V_160 -> V_167 ;
T_2 V_173 ;
int V_23 ;
F_61 ( & V_3 -> V_168 ) ;
F_62 ( & V_3 -> V_4 ) ;
V_173 = F_65 ( & V_3 -> V_7 ) ;
F_6 ( & V_3 -> V_7 , 0 ) ;
if ( V_173 > 0 ) {
T_2 V_174 = V_173 ;
if ( V_169 < V_173 )
V_173 = V_169 ;
F_5 ( & V_3 -> V_6 ) ;
V_23 = F_69 ( V_21 , V_3 -> V_8 , V_173 ) ;
memset ( V_3 -> V_8 , 0 , V_174 ) ;
if ( V_23 )
V_173 = - V_52 ;
F_7 ( & V_3 -> V_6 ) ;
}
return V_173 ;
}
void F_70 ( struct V_55 * V_28 )
{
struct V_2 * V_3 = F_17 ( V_28 ) ;
if ( V_3 == NULL ) {
F_11 ( V_28 , L_43 ) ;
return;
}
F_71 ( & V_175 ) ;
F_72 ( & V_3 -> V_176 ) ;
F_73 ( & V_175 ) ;
F_74 () ;
F_75 ( & V_3 -> V_19 . V_162 ) ;
F_76 ( & V_28 -> V_177 , V_3 -> V_19 . V_178 ) ;
F_77 ( V_3 -> V_179 ) ;
F_57 ( V_3 -> V_28 ) ;
}
int F_78 ( struct V_55 * V_28 )
{
struct V_2 * V_3 = F_17 ( V_28 ) ;
struct V_46 V_47 ;
int V_23 ;
V_32 V_180 [ V_122 ] = { 0 } ;
if ( V_3 == NULL )
return - V_123 ;
if ( V_181 ) {
V_47 . V_53 . V_59 = V_125 ;
V_47 . V_63 . V_126 . V_115 = F_18 ( V_181 ) ;
memcpy ( V_47 . V_63 . V_126 . V_124 , V_180 ,
V_122 ) ;
V_23 = F_15 ( V_3 , & V_47 , V_127 ,
L_44 ) ;
}
V_47 . V_53 . V_59 = V_182 ;
V_23 = F_15 ( V_3 , & V_47 , V_183 ,
L_45 ) ;
return V_23 ;
}
int F_79 ( struct V_55 * V_28 )
{
struct V_2 * V_3 = F_17 ( V_28 ) ;
if ( V_3 == NULL )
return - V_123 ;
return 0 ;
}
void F_80 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return;
if ( V_3 -> V_19 . V_184 )
V_3 -> V_19 . V_184 ( V_3 -> V_28 ) ;
F_59 ( V_3 -> V_112 , V_185 ) ;
F_63 ( V_3 -> V_19 . V_162 . V_186 ) ;
}
void F_81 ( struct V_55 * V_28 )
{
struct V_2 * V_3 = F_17 ( V_28 ) ;
if ( ! V_3 )
return;
F_80 ( V_3 ) ;
V_3 -> V_184 ( V_28 ) ;
F_63 ( V_3 ) ;
}
struct V_2 * F_82 ( struct V_55 * V_28 ,
const struct V_187 * V_188 )
{
#define F_83 7
char * V_189 ;
struct V_2 * V_3 ;
V_3 = F_58 ( sizeof( * V_3 ) , V_165 ) ;
V_189 = F_84 ( F_83 , V_165 ) ;
if ( V_3 == NULL || V_189 == NULL )
goto V_190;
F_85 ( & V_3 -> V_6 ) ;
F_85 ( & V_3 -> V_30 ) ;
F_86 ( & V_3 -> V_176 ) ;
F_87 ( & V_3 -> V_4 , F_3 ) ;
F_88 ( & V_3 -> V_168 , F_1 ,
( unsigned long ) V_3 ) ;
memcpy ( & V_3 -> V_19 , V_188 , sizeof( struct V_187 ) ) ;
V_3 -> V_112 = F_89 ( V_185 , V_191 ) ;
if ( V_3 -> V_112 >= V_191 ) {
F_11 ( V_28 , L_46 ) ;
goto V_190;
} else if ( V_3 -> V_112 == 0 )
V_3 -> V_19 . V_162 . V_161 = V_192 ;
else
V_3 -> V_19 . V_162 . V_161 = V_193 ;
F_90 ( V_3 -> V_112 , V_185 ) ;
F_91 ( V_189 , F_83 , L_47 , L_48 , V_3 -> V_112 ) ;
V_3 -> V_19 . V_162 . V_186 = V_189 ;
V_3 -> V_19 . V_162 . V_194 = V_28 ;
V_3 -> V_28 = F_54 ( V_28 ) ;
V_3 -> V_184 = V_28 -> V_184 ;
V_28 -> V_184 = F_81 ;
F_92 ( V_28 , V_3 ) ;
if ( F_93 ( & V_3 -> V_19 . V_162 ) ) {
F_11 ( V_3 -> V_28 ,
L_49 ,
V_3 -> V_19 . V_162 . V_186 ,
V_3 -> V_19 . V_162 . V_161 ) ;
goto F_57;
}
if ( F_94 ( & V_28 -> V_177 , V_3 -> V_19 . V_178 ) ) {
F_75 ( & V_3 -> V_19 . V_162 ) ;
goto F_57;
}
V_3 -> V_179 = F_95 ( V_189 ) ;
F_71 ( & V_175 ) ;
F_96 ( & V_3 -> V_176 , & V_195 ) ;
F_73 ( & V_175 ) ;
return V_3 ;
F_57:
F_57 ( V_3 -> V_28 ) ;
V_190:
F_63 ( V_3 ) ;
F_63 ( V_189 ) ;
return NULL ;
}
