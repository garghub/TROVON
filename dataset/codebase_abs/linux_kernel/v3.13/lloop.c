static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
T_1 V_4 , V_5 , V_6 ;
V_4 = F_2 ( V_3 -> V_7 -> V_8 ) ;
V_5 = V_2 -> V_9 ;
V_6 = V_4 - V_5 ;
if ( V_2 -> V_10 > 0 && V_2 -> V_10 < V_6 )
V_6 = V_2 -> V_10 ;
return V_6 >> 9 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
const struct V_13 * V_14 = V_2 -> V_15 ;
struct V_16 * V_17 = & V_2 -> V_18 ;
struct V_19 * V_19 = V_2 -> V_20 -> V_21 -> V_22 ;
struct V_23 * V_24 = F_4 ( V_19 ) -> V_25 ;
T_2 V_5 ;
int V_26 ;
int V_27 ;
int V_28 ;
T_3 V_29 = 0 ;
struct V_30 * V_31 ;
struct V_11 * V_11 ;
T_4 V_32 ;
struct V_33 * V_34 = & V_2 -> V_35 ;
struct V_36 * * V_37 = V_34 -> V_38 ;
T_1 * V_39 = V_34 -> V_40 ;
F_5 ( V_19 -> V_41 , 0 ) ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> V_42 = V_24 ;
V_26 = F_6 ( V_14 , V_17 , V_43 , V_24 ) ;
if ( V_26 )
return V_17 -> V_44 ;
V_17 -> V_45 = V_46 ;
F_7 ( V_12 != NULL ) ;
V_28 = V_12 -> V_47 ;
for ( V_11 = V_12 ; V_11 != NULL ; V_11 = V_11 -> V_48 ) {
F_7 ( V_28 == V_11 -> V_47 ) ;
V_5 = ( T_2 ) ( V_11 -> V_49 << 9 ) + V_2 -> V_9 ;
F_8 (bvec, bio, i) {
F_9 ( V_31 -> V_50 != 0 ) ;
F_9 ( V_31 -> V_51 != V_52 ) ;
V_37 [ V_29 ] = V_31 -> V_53 ;
V_39 [ V_29 ] = V_5 ;
V_29 ++ ;
V_5 += V_31 -> V_51 ;
}
F_7 ( V_29 <= V_54 ) ;
}
F_10 ( F_11 ( V_19 ) ,
( V_28 == V_55 ) ? V_56 : V_57 ,
V_29 ) ;
V_34 -> V_58 = V_29 << V_59 ;
V_34 -> V_60 = V_29 ;
F_12 ( & V_19 -> V_61 ) ;
V_32 = F_13 ( V_14 , V_17 , V_28 , V_19 , V_34 ) ;
F_14 ( & V_19 -> V_61 ) ;
F_15 ( V_14 , V_17 ) ;
return ( V_32 == V_34 -> V_58 ) ? 0 : ( int ) V_32 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
unsigned long V_62 ;
F_17 ( & V_2 -> V_63 , V_62 ) ;
if ( V_2 -> V_64 ) {
V_2 -> V_64 -> V_48 = V_11 ;
V_2 -> V_64 = V_11 ;
} else
V_2 -> V_65 = V_2 -> V_64 = V_11 ;
F_18 ( & V_2 -> V_63 , V_62 ) ;
F_19 ( & V_2 -> V_66 ) ;
if ( F_20 ( & V_2 -> V_67 ) )
F_21 ( & V_2 -> V_67 ) ;
}
static unsigned int F_22 ( struct V_1 * V_2 , struct V_11 * * V_68 )
{
struct V_11 * V_69 ;
struct V_11 * * V_11 ;
unsigned int V_70 = 0 ;
unsigned int V_29 = 0 ;
int V_28 ;
F_23 ( & V_2 -> V_63 ) ;
V_69 = V_2 -> V_65 ;
if ( F_24 ( V_69 == NULL ) ) {
F_25 ( & V_2 -> V_63 ) ;
return 0 ;
}
F_7 ( V_69 -> V_71 <= V_54 ) ;
V_28 = V_69 -> V_47 ;
V_11 = & V_2 -> V_65 ;
while ( * V_11 && ( * V_11 ) -> V_47 == V_28 ) {
F_26 ( V_72 , L_1 ,
( unsigned long long ) ( * V_11 ) -> V_49 , ( * V_11 ) -> V_73 ,
V_29 , ( * V_11 ) -> V_71 ) ;
if ( V_29 + ( * V_11 ) -> V_71 > V_54 )
break;
V_29 += ( * V_11 ) -> V_71 ;
V_70 ++ ;
V_11 = & ( * V_11 ) -> V_48 ;
}
if ( * V_11 ) {
V_2 -> V_65 = * V_11 ;
* V_11 = NULL ;
} else {
V_2 -> V_64 = NULL ;
V_2 -> V_65 = NULL ;
}
* V_68 = V_69 ;
F_25 ( & V_2 -> V_63 ) ;
return V_70 ;
}
static void F_27 ( struct V_74 * V_75 , struct V_11 * V_76 )
{
struct V_1 * V_2 = V_75 -> V_77 ;
int V_28 = F_28 ( V_76 ) ;
int V_78 ;
if ( ! V_2 )
goto V_79;
F_26 ( V_72 , L_2 ,
( unsigned long long ) V_76 -> V_49 , V_76 -> V_73 ) ;
F_23 ( & V_2 -> V_63 ) ;
V_78 = ( V_2 -> V_80 != V_81 ) ;
F_25 ( & V_2 -> V_63 ) ;
if ( V_78 )
goto V_79;
if ( V_28 == V_55 ) {
if ( V_2 -> V_82 & V_83 )
goto V_79;
} else if ( V_28 == V_84 ) {
V_28 = V_85 ;
} else if ( V_28 != V_85 ) {
F_29 ( L_3 , V_28 ) ;
goto V_79;
}
F_16 ( V_2 , V_76 ) ;
return;
V_79:
F_30 ( V_76 , V_76 -> V_73 ) ;
}
static inline void F_31 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_26 ;
V_26 = F_3 ( V_2 , V_11 ) ;
while ( V_11 ) {
struct V_11 * V_86 = V_11 -> V_48 ;
V_11 -> V_48 = NULL ;
F_32 ( V_11 , V_11 -> V_73 , V_26 ) ;
V_11 = V_86 ;
}
}
static inline int F_33 ( struct V_1 * V_2 )
{
return F_34 ( & V_2 -> V_66 ) ||
( V_2 -> V_80 == V_87 ) ;
}
static int F_35 ( void * V_88 )
{
struct V_1 * V_2 = V_88 ;
struct V_11 * V_11 ;
unsigned int V_70 ;
unsigned long V_89 = 0 ;
unsigned long V_90 = 0 ;
struct V_13 * V_14 ;
int V_91 ;
int V_26 = 0 ;
F_36 ( V_92 , - 20 ) ;
V_2 -> V_80 = V_81 ;
V_14 = F_37 ( & V_91 ) ;
if ( F_38 ( V_14 ) )
GOTO ( V_93 , V_26 = F_39 ( V_14 ) ) ;
V_2 -> V_15 = V_14 ;
memset ( & V_2 -> V_35 , 0 , sizeof( V_2 -> V_35 ) ) ;
V_2 -> V_35 . V_38 = V_2 -> V_94 [ 0 ] . V_95 ;
V_2 -> V_35 . V_40 = V_2 -> V_94 [ 0 ] . V_96 ;
F_40 ( & V_2 -> V_97 ) ;
for (; ; ) {
F_41 ( V_2 -> V_67 , F_33 ( V_2 ) ) ;
if ( ! F_34 ( & V_2 -> V_66 ) ) {
int V_98 = 0 ;
F_23 ( & V_2 -> V_63 ) ;
V_98 = ( V_2 -> V_80 == V_87 ) ;
F_25 ( & V_2 -> V_63 ) ;
if ( V_98 )
break;
}
V_11 = NULL ;
V_70 = F_22 ( V_2 , & V_11 ) ;
if ( ! V_70 ) {
F_42 ( L_4 , V_2 -> V_99 ) ;
continue;
}
V_90 += V_70 ;
if ( V_90 < V_70 ) {
V_90 = V_70 ;
V_89 = 1 ;
} else {
V_89 ++ ;
}
if ( ( V_89 & 127 ) == 0 ) {
F_26 ( V_72 , L_5 ,
V_90 , V_89 , V_90 / V_89 ) ;
}
F_7 ( V_11 != NULL ) ;
F_7 ( V_70 <= F_34 ( & V_2 -> V_66 ) ) ;
F_31 ( V_2 , V_11 ) ;
F_43 ( V_70 , & V_2 -> V_66 ) ;
}
F_44 ( V_14 , & V_91 ) ;
V_93:
F_40 ( & V_2 -> V_97 ) ;
return V_26 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_3 * V_100 ,
struct V_101 * V_102 , struct V_3 * V_3 )
{
struct V_19 * V_19 ;
struct V_103 * V_104 ;
int V_82 = 0 ;
int error ;
T_1 V_4 ;
if ( ! F_46 ( V_105 ) )
return - V_106 ;
error = - V_107 ;
if ( V_2 -> V_80 != V_108 )
goto V_93;
V_104 = V_3 -> V_7 ;
V_19 = V_104 -> V_8 ;
error = - V_109 ;
if ( ! F_47 ( V_19 -> V_110 ) || V_19 -> V_111 -> V_112 != V_113 )
goto V_93;
if ( ! ( V_3 -> V_114 & V_115 ) )
V_82 |= V_83 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( ( T_1 ) ( V_116 ) V_4 != V_4 ) {
error = - V_117 ;
goto V_93;
}
F_5 ( V_104 , 0 ) ;
F_48 ( V_102 , ( V_82 & V_83 ) != 0 ) ;
V_2 -> V_118 = V_52 ;
V_2 -> V_119 = V_102 ;
V_2 -> V_82 = V_82 ;
V_2 -> V_20 = V_3 ;
V_2 -> V_120 = NULL ;
V_2 -> V_10 = 0 ;
V_2 -> V_121 = F_49 ( V_104 ) ;
F_50 ( V_104 , V_2 -> V_121 & ~ ( V_122 | V_123 ) ) ;
V_2 -> V_65 = V_2 -> V_64 = NULL ;
F_51 ( V_2 -> V_124 , F_27 ) ;
V_2 -> V_124 -> V_77 = V_2 ;
F_52 ( V_52 < ( 1 << (sizeof( unsigned short ) * 8 ) ) ) ;
F_53 ( V_2 -> V_124 ,
( unsigned short ) V_52 ) ;
F_54 ( V_2 -> V_124 ,
V_54 << ( V_59 - 9 ) ) ;
F_55 ( V_2 -> V_124 , V_54 ) ;
F_56 ( V_125 [ V_2 -> V_99 ] , V_4 ) ;
F_57 ( V_102 , V_4 << 9 ) ;
F_58 ( V_102 , V_2 -> V_118 ) ;
F_59 ( F_35 , V_2 , L_6 , V_2 -> V_99 ) ;
F_60 ( & V_2 -> V_97 ) ;
return 0 ;
V_93:
F_61 ( V_105 ) ;
return error ;
}
static int F_62 ( struct V_1 * V_2 , struct V_101 * V_102 ,
int V_70 )
{
struct V_3 * V_126 = V_2 -> V_20 ;
int V_127 = V_2 -> V_121 ;
if ( V_2 -> V_80 != V_81 )
return - V_128 ;
if ( V_2 -> V_129 > V_70 )
return - V_107 ;
if ( V_126 == NULL )
return - V_109 ;
F_23 ( & V_2 -> V_63 ) ;
V_2 -> V_80 = V_87 ;
F_25 ( & V_2 -> V_63 ) ;
F_21 ( & V_2 -> V_67 ) ;
F_60 ( & V_2 -> V_97 ) ;
V_2 -> V_20 = NULL ;
V_2 -> V_120 = NULL ;
V_2 -> V_119 = NULL ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_82 = 0 ;
F_63 ( V_102 ) ;
F_56 ( V_125 [ V_2 -> V_99 ] , 0 ) ;
F_57 ( V_102 , 0 ) ;
F_50 ( V_126 -> V_7 , V_127 ) ;
V_2 -> V_80 = V_108 ;
F_64 ( V_126 ) ;
F_61 ( V_105 ) ;
return 0 ;
}
static int F_65 ( struct V_101 * V_102 , T_5 V_130 )
{
struct V_1 * V_2 = V_102 -> V_131 -> V_132 ;
F_12 ( & V_2 -> V_133 ) ;
V_2 -> V_129 ++ ;
F_14 ( & V_2 -> V_133 ) ;
return 0 ;
}
static void F_66 ( struct V_134 * V_135 , T_5 V_130 )
{
struct V_1 * V_2 = V_135 -> V_132 ;
F_12 ( & V_2 -> V_133 ) ;
-- V_2 -> V_129 ;
F_14 ( & V_2 -> V_133 ) ;
}
static int F_67 ( struct V_101 * V_102 , T_5 V_130 ,
unsigned int V_136 , unsigned long V_137 )
{
struct V_1 * V_2 = V_102 -> V_131 -> V_132 ;
struct V_19 * V_19 = NULL ;
int V_79 = 0 ;
F_12 ( & V_138 ) ;
switch ( V_136 ) {
case V_139 : {
V_79 = F_62 ( V_2 , V_102 , 2 ) ;
if ( V_79 == 0 )
F_68 ( V_102 , 0 ) ;
break;
}
case V_140 : {
struct V_141 V_142 ;
F_7 ( V_2 -> V_20 != NULL ) ;
if ( V_19 == NULL )
V_19 = V_2 -> V_20 -> V_21 -> V_22 ;
if ( V_2 -> V_80 == V_81 )
V_142 = F_4 ( V_19 ) -> V_143 ;
else
F_69 ( & V_142 ) ;
if ( F_70 ( (struct V_141 * ) V_137 , & V_142 , sizeof( V_142 ) ) )
V_79 = - V_144 ;
break;
}
default:
V_79 = - V_109 ;
break;
}
F_14 ( & V_138 ) ;
return V_79 ;
}
static enum V_145 F_71 ( struct V_19 * V_100 , struct V_3 * V_3 ,
unsigned int V_136 , unsigned long V_137 ,
void * V_146 , int * V_147 )
{
struct V_1 * V_2 = NULL ;
struct V_101 * V_102 = NULL ;
int V_79 = 0 ;
T_6 V_148 ;
if ( V_146 != V_149 )
return V_150 ;
if ( V_125 == NULL )
GOTO ( V_151 , V_79 = - V_106 ) ;
F_42 ( L_7 ) ;
F_12 ( & V_138 ) ;
switch ( V_136 ) {
case V_152 : {
struct V_1 * V_153 = NULL ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_154 ; V_27 ++ , V_2 = NULL ) {
V_2 = & V_155 [ V_27 ] ;
if ( V_2 -> V_80 == V_108 ) {
if ( ! V_153 )
V_153 = V_2 ;
continue;
}
if ( V_2 -> V_20 -> V_21 -> V_22 ==
V_3 -> V_21 -> V_22 )
break;
}
if ( V_2 || ! V_153 )
GOTO ( V_93 , V_79 = - V_107 ) ;
V_2 = V_153 ;
V_148 = F_72 ( V_156 , V_2 -> V_99 ) ;
if ( F_73 ( ( long ) F_74 ( V_148 ) , ( long * ) V_137 ) )
GOTO ( V_93 , V_79 = - V_144 ) ;
V_102 = F_75 ( V_148 , V_3 -> V_114 , NULL ) ;
if ( F_38 ( V_102 ) )
GOTO ( V_93 , V_79 = F_39 ( V_102 ) ) ;
F_76 ( V_3 ) ;
V_79 = F_45 ( V_2 , NULL , V_102 , V_3 ) ;
if ( V_79 ) {
F_64 ( V_3 ) ;
F_68 ( V_102 , 0 ) ;
}
break;
}
case V_157 : {
int V_158 ;
V_148 = F_77 ( V_137 ) ;
if ( F_78 ( V_148 ) != V_156 )
GOTO ( V_93 , V_79 = - V_109 ) ;
V_158 = F_79 ( V_148 ) ;
if ( V_158 > V_154 - 1 )
GOTO ( V_93 , V_79 = - V_109 ) ;
V_2 = & V_155 [ V_158 ] ;
if ( V_2 -> V_80 != V_81 )
GOTO ( V_93 , V_79 = - V_109 ) ;
V_102 = V_2 -> V_119 ;
V_79 = F_62 ( V_2 , V_102 , 1 ) ;
if ( V_79 == 0 )
F_68 ( V_102 , 0 ) ;
break;
}
default:
V_79 = - V_109 ;
break;
}
V_93:
F_14 ( & V_138 ) ;
V_151:
if ( V_147 )
* V_147 = V_79 ;
return V_159 ;
}
static int T_7 F_80 ( void )
{
int V_27 ;
unsigned int V_160 [] = {
V_152 ,
V_157 ,
} ;
if ( V_154 < 1 || V_154 > 256 ) {
V_154 = V_161 ;
F_42 ( L_8
L_9 , V_154 ) ;
}
V_156 = F_81 ( 0 , L_10 ) ;
if ( V_156 < 0 )
return - V_162 ;
F_26 ( V_163 , L_11 ,
V_156 , V_154 ) ;
V_149 = F_82 ( F_71 , 2 , V_160 ) ;
if ( V_149 == NULL )
goto V_164;
F_83 ( V_155 , V_154 * sizeof( * V_155 ) ) ;
if ( ! V_155 )
goto V_164;
F_83 ( V_125 , V_154 * sizeof( * V_125 ) ) ;
if ( ! V_125 )
goto V_165;
for ( V_27 = 0 ; V_27 < V_154 ; V_27 ++ ) {
V_125 [ V_27 ] = F_84 ( 1 ) ;
if ( ! V_125 [ V_27 ] )
goto V_166;
}
F_85 ( & V_138 ) ;
for ( V_27 = 0 ; V_27 < V_154 ; V_27 ++ ) {
struct V_1 * V_2 = & V_155 [ V_27 ] ;
struct V_134 * V_135 = V_125 [ V_27 ] ;
V_2 -> V_124 = F_86 ( V_167 ) ;
if ( ! V_2 -> V_124 )
goto V_168;
F_85 ( & V_2 -> V_133 ) ;
F_87 ( & V_2 -> V_97 , 0 ) ;
F_88 ( & V_2 -> V_67 ) ;
V_2 -> V_99 = V_27 ;
F_89 ( & V_2 -> V_63 ) ;
V_135 -> V_169 = V_156 ;
V_135 -> V_170 = V_27 ;
V_135 -> V_171 = & V_172 ;
sprintf ( V_135 -> V_173 , L_6 , V_27 ) ;
V_135 -> V_132 = V_2 ;
V_135 -> V_174 = V_2 -> V_124 ;
}
for ( V_27 = 0 ; V_27 < V_154 ; V_27 ++ )
F_90 ( V_125 [ V_27 ] ) ;
return 0 ;
V_168:
while ( V_27 -- )
F_91 ( V_155 [ V_27 ] . V_124 ) ;
V_27 = V_154 ;
V_166:
while ( V_27 -- )
F_92 ( V_125 [ V_27 ] ) ;
F_93 ( V_125 , V_154 * sizeof( * V_125 ) ) ;
V_165:
F_93 ( V_155 , V_154 * sizeof( * V_155 ) ) ;
V_164:
F_94 ( V_156 , L_10 ) ;
F_95 ( V_149 ) ;
F_29 ( L_12 ) ;
return - V_175 ;
}
static void F_96 ( void )
{
int V_27 ;
F_95 ( V_149 ) ;
for ( V_27 = 0 ; V_27 < V_154 ; V_27 ++ ) {
F_97 ( V_125 [ V_27 ] ) ;
F_91 ( V_155 [ V_27 ] . V_124 ) ;
F_92 ( V_125 [ V_27 ] ) ;
}
F_94 ( V_156 , L_10 ) ;
F_93 ( V_125 , V_154 * sizeof( * V_125 ) ) ;
F_93 ( V_155 , V_154 * sizeof( * V_155 ) ) ;
}
