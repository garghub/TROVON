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
T_3 V_28 = 0 ;
struct V_29 V_30 ;
struct V_31 V_32 ;
struct V_11 * V_11 ;
T_4 V_33 ;
struct V_34 * V_35 = & V_2 -> V_36 ;
struct V_37 * * V_38 = V_35 -> V_39 ;
T_1 * V_40 = V_35 -> V_41 ;
F_5 ( V_19 -> V_42 , 0 ) ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> V_43 = V_24 ;
V_26 = F_6 ( V_14 , V_17 , V_44 , V_24 ) ;
if ( V_26 )
return V_17 -> V_45 ;
V_17 -> V_46 = V_47 ;
F_7 ( V_12 != NULL ) ;
V_27 = V_12 -> V_48 ;
for ( V_11 = V_12 ; V_11 != NULL ; V_11 = V_11 -> V_49 ) {
F_7 ( V_27 == V_11 -> V_48 ) ;
V_5 = ( T_2 ) ( V_11 -> V_50 . V_51 << 9 ) + V_2 -> V_9 ;
F_8 (bvec, bio, iter) {
F_9 ( V_30 . V_52 != 0 ) ;
F_9 ( V_30 . V_53 != V_54 ) ;
V_38 [ V_28 ] = V_30 . V_55 ;
V_40 [ V_28 ] = V_5 ;
V_28 ++ ;
V_5 += V_30 . V_53 ;
}
F_7 ( V_28 <= V_56 ) ;
}
F_10 ( F_11 ( V_19 ) ,
( V_27 == V_57 ) ? V_58 : V_59 ,
V_28 ) ;
V_35 -> V_60 = V_28 << V_61 ;
V_35 -> V_62 = V_28 ;
F_12 ( & V_19 -> V_63 ) ;
V_33 = F_13 ( V_14 , V_17 , V_27 , V_19 , V_35 ) ;
F_14 ( & V_19 -> V_63 ) ;
F_15 ( V_14 , V_17 ) ;
return ( V_33 == V_35 -> V_60 ) ? 0 : ( int ) V_33 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
unsigned long V_64 ;
F_17 ( & V_2 -> V_65 , V_64 ) ;
if ( V_2 -> V_66 ) {
V_2 -> V_66 -> V_49 = V_11 ;
V_2 -> V_66 = V_11 ;
} else
V_2 -> V_67 = V_2 -> V_66 = V_11 ;
F_18 ( & V_2 -> V_65 , V_64 ) ;
F_19 ( & V_2 -> V_68 ) ;
if ( F_20 ( & V_2 -> V_69 ) )
F_21 ( & V_2 -> V_69 ) ;
}
static unsigned int F_22 ( struct V_1 * V_2 , struct V_11 * * V_70 )
{
struct V_11 * V_71 ;
struct V_11 * * V_11 ;
unsigned int V_72 = 0 ;
unsigned int V_28 = 0 ;
int V_27 ;
F_23 ( & V_2 -> V_65 ) ;
V_71 = V_2 -> V_67 ;
if ( F_24 ( V_71 == NULL ) ) {
F_25 ( & V_2 -> V_65 ) ;
return 0 ;
}
F_7 ( V_71 -> V_73 <= V_56 ) ;
V_27 = V_71 -> V_48 ;
V_11 = & V_2 -> V_67 ;
while ( * V_11 && ( * V_11 ) -> V_48 == V_27 ) {
F_26 ( V_74 , L_1 ,
( unsigned long long ) ( * V_11 ) -> V_50 . V_51 ,
( * V_11 ) -> V_50 . V_75 ,
V_28 , ( * V_11 ) -> V_73 ) ;
if ( V_28 + ( * V_11 ) -> V_73 > V_56 )
break;
V_28 += ( * V_11 ) -> V_73 ;
V_72 ++ ;
V_11 = & ( * V_11 ) -> V_49 ;
}
if ( * V_11 ) {
V_2 -> V_67 = * V_11 ;
* V_11 = NULL ;
} else {
V_2 -> V_66 = NULL ;
V_2 -> V_67 = NULL ;
}
* V_70 = V_71 ;
F_25 ( & V_2 -> V_65 ) ;
return V_72 ;
}
static void F_27 ( struct V_76 * V_77 , struct V_11 * V_78 )
{
struct V_1 * V_2 = V_77 -> V_79 ;
int V_27 = F_28 ( V_78 ) ;
int V_80 ;
if ( ! V_2 )
goto V_81;
F_26 ( V_74 , L_2 ,
( unsigned long long ) V_78 -> V_50 . V_51 ,
V_78 -> V_50 . V_75 ) ;
F_23 ( & V_2 -> V_65 ) ;
V_80 = ( V_2 -> V_82 != V_83 ) ;
F_25 ( & V_2 -> V_65 ) ;
if ( V_80 )
goto V_81;
if ( V_27 == V_57 ) {
if ( V_2 -> V_84 & V_85 )
goto V_81;
} else if ( V_27 == V_86 ) {
V_27 = V_87 ;
} else if ( V_27 != V_87 ) {
F_29 ( L_3 , V_27 ) ;
goto V_81;
}
F_16 ( V_2 , V_78 ) ;
return;
V_81:
F_30 ( V_78 , V_78 -> V_50 . V_75 ) ;
}
static inline void F_31 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_26 ;
V_26 = F_3 ( V_2 , V_11 ) ;
while ( V_11 ) {
struct V_11 * V_88 = V_11 -> V_49 ;
V_11 -> V_49 = NULL ;
F_32 ( V_11 , V_11 -> V_50 . V_75 , V_26 ) ;
V_11 = V_88 ;
}
}
static inline int F_33 ( struct V_1 * V_2 )
{
return F_34 ( & V_2 -> V_68 ) ||
( V_2 -> V_82 == V_89 ) ;
}
static int F_35 ( void * V_90 )
{
struct V_1 * V_2 = V_90 ;
struct V_11 * V_11 ;
unsigned int V_72 ;
unsigned long V_91 = 0 ;
unsigned long V_92 = 0 ;
struct V_13 * V_14 ;
int V_93 ;
int V_26 = 0 ;
F_36 ( V_94 , V_95 ) ;
V_2 -> V_82 = V_83 ;
V_14 = F_37 ( & V_93 ) ;
if ( F_38 ( V_14 ) )
GOTO ( V_96 , V_26 = F_39 ( V_14 ) ) ;
V_2 -> V_15 = V_14 ;
memset ( & V_2 -> V_36 , 0 , sizeof( V_2 -> V_36 ) ) ;
V_2 -> V_36 . V_39 = V_2 -> V_97 [ 0 ] . V_98 ;
V_2 -> V_36 . V_41 = V_2 -> V_97 [ 0 ] . V_99 ;
F_40 ( & V_2 -> V_100 ) ;
for (; ; ) {
F_41 ( V_2 -> V_69 , F_33 ( V_2 ) ) ;
if ( ! F_34 ( & V_2 -> V_68 ) ) {
int V_101 = 0 ;
F_23 ( & V_2 -> V_65 ) ;
V_101 = ( V_2 -> V_82 == V_89 ) ;
F_25 ( & V_2 -> V_65 ) ;
if ( V_101 )
break;
}
V_11 = NULL ;
V_72 = F_22 ( V_2 , & V_11 ) ;
if ( ! V_72 ) {
F_42 ( L_4 , V_2 -> V_102 ) ;
continue;
}
V_92 += V_72 ;
if ( V_92 < V_72 ) {
V_92 = V_72 ;
V_91 = 1 ;
} else {
V_91 ++ ;
}
if ( ( V_91 & 127 ) == 0 ) {
F_26 ( V_74 , L_5 ,
V_92 , V_91 , V_92 / V_91 ) ;
}
F_7 ( V_11 != NULL ) ;
F_7 ( V_72 <= F_34 ( & V_2 -> V_68 ) ) ;
F_31 ( V_2 , V_11 ) ;
F_43 ( V_72 , & V_2 -> V_68 ) ;
}
F_44 ( V_14 , & V_93 ) ;
V_96:
F_40 ( & V_2 -> V_100 ) ;
return V_26 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_3 * V_103 ,
struct V_104 * V_105 , struct V_3 * V_3 )
{
struct V_19 * V_19 ;
struct V_106 * V_107 ;
int V_84 = 0 ;
int error ;
T_1 V_4 ;
if ( ! F_46 ( V_108 ) )
return - V_109 ;
error = - V_110 ;
if ( V_2 -> V_82 != V_111 )
goto V_96;
V_107 = V_3 -> V_7 ;
V_19 = V_107 -> V_8 ;
error = - V_112 ;
if ( ! F_47 ( V_19 -> V_113 ) || V_19 -> V_114 -> V_115 != V_116 )
goto V_96;
if ( ! ( V_3 -> V_117 & V_118 ) )
V_84 |= V_85 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( ( T_1 ) ( V_119 ) V_4 != V_4 ) {
error = - V_120 ;
goto V_96;
}
F_5 ( V_107 , 0 ) ;
F_48 ( V_105 , ( V_84 & V_85 ) != 0 ) ;
V_2 -> V_121 = V_54 ;
V_2 -> V_122 = V_105 ;
V_2 -> V_84 = V_84 ;
V_2 -> V_20 = V_3 ;
V_2 -> V_10 = 0 ;
V_2 -> V_123 = F_49 ( V_107 ) ;
F_50 ( V_107 , V_2 -> V_123 & ~ ( V_124 | V_125 ) ) ;
V_2 -> V_67 = V_2 -> V_66 = NULL ;
F_51 ( V_2 -> V_126 , F_27 ) ;
V_2 -> V_126 -> V_79 = V_2 ;
F_52 ( V_54 < ( 1 << (sizeof( unsigned short ) * 8 ) ) ) ;
F_53 ( V_2 -> V_126 ,
( unsigned short ) V_54 ) ;
F_54 ( V_2 -> V_126 ,
V_56 << ( V_61 - 9 ) ) ;
F_55 ( V_2 -> V_126 , V_56 ) ;
F_56 ( V_127 [ V_2 -> V_102 ] , V_4 ) ;
F_57 ( V_105 , V_4 << 9 ) ;
F_58 ( V_105 , V_2 -> V_121 ) ;
F_59 ( F_35 , V_2 , L_6 , V_2 -> V_102 ) ;
F_60 ( & V_2 -> V_100 ) ;
return 0 ;
V_96:
F_61 ( V_108 ) ;
return error ;
}
static int F_62 ( struct V_1 * V_2 , struct V_104 * V_105 ,
int V_72 )
{
struct V_3 * V_128 = V_2 -> V_20 ;
int V_129 = V_2 -> V_123 ;
if ( V_2 -> V_82 != V_83 )
return - V_130 ;
if ( V_2 -> V_131 > V_72 )
return - V_110 ;
if ( V_128 == NULL )
return - V_112 ;
F_23 ( & V_2 -> V_65 ) ;
V_2 -> V_82 = V_89 ;
F_25 ( & V_2 -> V_65 ) ;
F_21 ( & V_2 -> V_69 ) ;
F_60 ( & V_2 -> V_100 ) ;
V_2 -> V_20 = NULL ;
V_2 -> V_122 = NULL ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_84 = 0 ;
F_63 ( V_105 ) ;
F_56 ( V_127 [ V_2 -> V_102 ] , 0 ) ;
F_57 ( V_105 , 0 ) ;
F_50 ( V_128 -> V_7 , V_129 ) ;
V_2 -> V_82 = V_111 ;
F_64 ( V_128 ) ;
F_61 ( V_108 ) ;
return 0 ;
}
static int F_65 ( struct V_104 * V_105 , T_5 V_132 )
{
struct V_1 * V_2 = V_105 -> V_133 -> V_134 ;
F_12 ( & V_2 -> V_135 ) ;
V_2 -> V_131 ++ ;
F_14 ( & V_2 -> V_135 ) ;
return 0 ;
}
static void F_66 ( struct V_136 * V_137 , T_5 V_132 )
{
struct V_1 * V_2 = V_137 -> V_134 ;
F_12 ( & V_2 -> V_135 ) ;
-- V_2 -> V_131 ;
F_14 ( & V_2 -> V_135 ) ;
}
static int F_67 ( struct V_104 * V_105 , T_5 V_132 ,
unsigned int V_138 , unsigned long V_139 )
{
struct V_1 * V_2 = V_105 -> V_133 -> V_134 ;
struct V_19 * V_19 = NULL ;
int V_81 = 0 ;
F_12 ( & V_140 ) ;
switch ( V_138 ) {
case V_141 : {
V_81 = F_62 ( V_2 , V_105 , 2 ) ;
if ( V_81 == 0 )
F_68 ( V_105 , 0 ) ;
break;
}
case V_142 : {
struct V_143 V_144 ;
if ( V_2 -> V_20 == NULL ) {
V_81 = - V_145 ;
break;
}
if ( V_19 == NULL )
V_19 = V_2 -> V_20 -> V_21 -> V_22 ;
if ( V_2 -> V_82 == V_83 )
V_144 = F_4 ( V_19 ) -> V_146 ;
else
F_69 ( & V_144 ) ;
if ( F_70 ( (struct V_143 * ) V_139 , & V_144 , sizeof( V_144 ) ) )
V_81 = - V_147 ;
break;
}
default:
V_81 = - V_112 ;
break;
}
F_14 ( & V_140 ) ;
return V_81 ;
}
static enum V_148 F_71 ( struct V_19 * V_103 , struct V_3 * V_3 ,
unsigned int V_138 , unsigned long V_139 ,
void * V_149 , int * V_150 )
{
struct V_1 * V_2 = NULL ;
struct V_104 * V_105 = NULL ;
int V_81 = 0 ;
T_6 V_151 ;
if ( V_149 != V_152 )
return V_153 ;
if ( V_127 == NULL )
GOTO ( V_154 , V_81 = - V_109 ) ;
F_42 ( L_7 ) ;
F_12 ( & V_140 ) ;
switch ( V_138 ) {
case V_155 : {
struct V_1 * V_156 = NULL ;
int V_157 ;
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ , V_2 = NULL ) {
V_2 = & V_159 [ V_157 ] ;
if ( V_2 -> V_82 == V_111 ) {
if ( ! V_156 )
V_156 = V_2 ;
continue;
}
if ( V_2 -> V_20 -> V_21 -> V_22 ==
V_3 -> V_21 -> V_22 )
break;
}
if ( V_2 || ! V_156 )
GOTO ( V_96 , V_81 = - V_110 ) ;
V_2 = V_156 ;
V_151 = F_72 ( V_160 , V_2 -> V_102 ) ;
if ( F_73 ( ( long ) F_74 ( V_151 ) , ( long * ) V_139 ) )
GOTO ( V_96 , V_81 = - V_147 ) ;
V_105 = F_75 ( V_151 , V_3 -> V_117 , NULL ) ;
if ( F_38 ( V_105 ) )
GOTO ( V_96 , V_81 = F_39 ( V_105 ) ) ;
F_76 ( V_3 ) ;
V_81 = F_45 ( V_2 , NULL , V_105 , V_3 ) ;
if ( V_81 ) {
F_64 ( V_3 ) ;
F_68 ( V_105 , 0 ) ;
}
break;
}
case V_161 : {
int V_162 ;
V_151 = F_77 ( V_139 ) ;
if ( F_78 ( V_151 ) != V_160 )
GOTO ( V_96 , V_81 = - V_112 ) ;
V_162 = F_79 ( V_151 ) ;
if ( V_162 > V_158 - 1 )
GOTO ( V_96 , V_81 = - V_112 ) ;
V_2 = & V_159 [ V_162 ] ;
if ( V_2 -> V_82 != V_83 )
GOTO ( V_96 , V_81 = - V_112 ) ;
V_105 = V_2 -> V_122 ;
V_81 = F_62 ( V_2 , V_105 , 1 ) ;
if ( V_81 == 0 )
F_68 ( V_105 , 0 ) ;
break;
}
default:
V_81 = - V_112 ;
break;
}
V_96:
F_14 ( & V_140 ) ;
V_154:
if ( V_150 )
* V_150 = V_81 ;
return V_163 ;
}
static int T_7 F_80 ( void )
{
int V_157 ;
unsigned int V_164 [] = {
V_155 ,
V_161 ,
} ;
if ( V_158 < 1 || V_158 > 256 ) {
V_158 = V_165 ;
F_42 ( L_8
L_9 , V_158 ) ;
}
V_160 = F_81 ( 0 , L_10 ) ;
if ( V_160 < 0 )
return - V_166 ;
F_26 ( V_167 , L_11 ,
V_160 , V_158 ) ;
V_152 = F_82 ( F_71 , 2 , V_164 ) ;
if ( V_152 == NULL )
goto V_168;
F_83 ( V_159 , V_158 * sizeof( * V_159 ) ) ;
if ( ! V_159 )
goto V_168;
F_83 ( V_127 , V_158 * sizeof( * V_127 ) ) ;
if ( ! V_127 )
goto V_169;
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ ) {
V_127 [ V_157 ] = F_84 ( 1 ) ;
if ( ! V_127 [ V_157 ] )
goto V_170;
}
F_85 ( & V_140 ) ;
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ ) {
struct V_1 * V_2 = & V_159 [ V_157 ] ;
struct V_136 * V_137 = V_127 [ V_157 ] ;
V_2 -> V_126 = F_86 ( V_171 ) ;
if ( ! V_2 -> V_126 )
goto V_172;
F_85 ( & V_2 -> V_135 ) ;
F_87 ( & V_2 -> V_100 , 0 ) ;
F_88 ( & V_2 -> V_69 ) ;
V_2 -> V_102 = V_157 ;
F_89 ( & V_2 -> V_65 ) ;
V_137 -> V_173 = V_160 ;
V_137 -> V_174 = V_157 ;
V_137 -> V_175 = & V_176 ;
sprintf ( V_137 -> V_177 , L_6 , V_157 ) ;
V_137 -> V_134 = V_2 ;
V_137 -> V_178 = V_2 -> V_126 ;
}
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ )
F_90 ( V_127 [ V_157 ] ) ;
return 0 ;
V_172:
while ( V_157 -- )
F_91 ( V_159 [ V_157 ] . V_126 ) ;
V_157 = V_158 ;
V_170:
while ( V_157 -- )
F_92 ( V_127 [ V_157 ] ) ;
F_93 ( V_127 , V_158 * sizeof( * V_127 ) ) ;
V_169:
F_93 ( V_159 , V_158 * sizeof( * V_159 ) ) ;
V_168:
F_94 ( V_160 , L_10 ) ;
F_95 ( V_152 ) ;
F_29 ( L_12 ) ;
return - V_179 ;
}
static void F_96 ( void )
{
int V_157 ;
F_95 ( V_152 ) ;
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ ) {
F_97 ( V_127 [ V_157 ] ) ;
F_91 ( V_159 [ V_157 ] . V_126 ) ;
F_92 ( V_127 [ V_157 ] ) ;
}
F_94 ( V_160 , L_10 ) ;
F_93 ( V_127 , V_158 * sizeof( * V_127 ) ) ;
F_93 ( V_159 , V_158 * sizeof( * V_159 ) ) ;
}
