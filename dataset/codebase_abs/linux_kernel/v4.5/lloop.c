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
struct V_19 * V_19 = F_4 ( V_2 -> V_20 ) ;
struct V_21 * V_22 = F_5 ( V_19 ) -> V_23 ;
T_2 V_5 ;
int V_24 ;
int V_25 ;
T_3 V_26 = 0 ;
struct V_27 V_28 ;
struct V_29 V_30 ;
struct V_11 * V_11 ;
T_4 V_31 ;
struct V_32 * V_33 = & V_2 -> V_34 ;
struct V_35 * * V_36 = V_33 -> V_37 ;
T_1 * V_38 = V_33 -> V_39 ;
F_6 ( V_19 -> V_40 , 0 ) ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> V_41 = V_22 ;
V_24 = F_7 ( V_14 , V_17 , V_42 , V_22 ) ;
if ( V_24 )
return V_17 -> V_43 ;
V_17 -> V_44 = V_45 ;
F_8 ( V_12 != NULL ) ;
V_25 = V_12 -> V_46 ;
for ( V_11 = V_12 ; V_11 != NULL ; V_11 = V_11 -> V_47 ) {
F_8 ( V_25 == V_11 -> V_46 ) ;
V_5 = ( T_2 ) ( V_11 -> V_48 . V_49 << 9 ) + V_2 -> V_9 ;
F_9 (bvec, bio, iter) {
F_10 ( V_28 . V_50 != 0 ) ;
F_10 ( V_28 . V_51 != V_52 ) ;
V_36 [ V_26 ] = V_28 . V_53 ;
V_38 [ V_26 ] = V_5 ;
V_26 ++ ;
V_5 += V_28 . V_51 ;
}
F_8 ( V_26 <= V_54 ) ;
}
F_11 ( F_12 ( V_19 ) ,
( V_25 == V_55 ) ? V_56 : V_57 ,
V_26 ) ;
V_33 -> V_58 = V_26 << V_59 ;
V_33 -> V_60 = V_26 ;
F_13 ( V_19 ) ;
V_31 = F_14 ( V_14 , V_17 , V_25 , V_19 , V_33 ) ;
F_15 ( V_19 ) ;
F_16 ( V_14 , V_17 ) ;
return ( V_31 == V_33 -> V_58 ) ? 0 : ( int ) V_31 ;
}
static void F_17 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
unsigned long V_61 ;
F_18 ( & V_2 -> V_62 , V_61 ) ;
if ( V_2 -> V_63 ) {
V_2 -> V_63 -> V_47 = V_11 ;
V_2 -> V_63 = V_11 ;
} else
V_2 -> V_64 = V_2 -> V_63 = V_11 ;
F_19 ( & V_2 -> V_62 , V_61 ) ;
F_20 ( & V_2 -> V_65 ) ;
if ( F_21 ( & V_2 -> V_66 ) )
F_22 ( & V_2 -> V_66 ) ;
}
static unsigned int F_23 ( struct V_1 * V_2 , struct V_11 * * V_67 )
{
struct V_11 * V_68 ;
struct V_11 * * V_11 ;
unsigned int V_69 = 0 ;
unsigned int V_26 = 0 ;
int V_25 ;
F_24 ( & V_2 -> V_62 ) ;
V_68 = V_2 -> V_64 ;
if ( F_25 ( V_68 == NULL ) ) {
F_26 ( & V_2 -> V_62 ) ;
return 0 ;
}
F_8 ( V_68 -> V_70 <= V_54 ) ;
V_25 = V_68 -> V_46 ;
V_11 = & V_2 -> V_64 ;
while ( * V_11 && ( * V_11 ) -> V_46 == V_25 ) {
F_27 ( V_71 , L_1 ,
( unsigned long long ) ( * V_11 ) -> V_48 . V_49 ,
( * V_11 ) -> V_48 . V_72 ,
V_26 , ( * V_11 ) -> V_70 ) ;
if ( V_26 + ( * V_11 ) -> V_70 > V_54 )
break;
V_26 += ( * V_11 ) -> V_70 ;
V_69 ++ ;
V_11 = & ( * V_11 ) -> V_47 ;
}
if ( * V_11 ) {
V_2 -> V_64 = * V_11 ;
* V_11 = NULL ;
} else {
V_2 -> V_63 = NULL ;
V_2 -> V_64 = NULL ;
}
* V_67 = V_68 ;
F_26 ( & V_2 -> V_62 ) ;
return V_69 ;
}
static T_5 F_28 ( struct V_73 * V_74 , struct V_11 * V_75 )
{
struct V_1 * V_2 = V_74 -> V_76 ;
int V_25 = F_29 ( V_75 ) ;
int V_77 ;
F_30 ( V_74 , & V_75 , V_74 -> V_78 ) ;
if ( ! V_2 )
goto V_79;
F_27 ( V_71 , L_2 ,
( unsigned long long ) V_75 -> V_48 . V_49 ,
V_75 -> V_48 . V_72 ) ;
F_24 ( & V_2 -> V_62 ) ;
V_77 = V_2 -> V_80 != V_81 ;
F_26 ( & V_2 -> V_62 ) ;
if ( V_77 )
goto V_79;
if ( V_25 == V_55 ) {
if ( V_2 -> V_82 & V_83 )
goto V_79;
} else if ( V_25 == V_84 ) {
V_25 = V_85 ;
} else if ( V_25 != V_85 ) {
F_31 ( L_3 , V_25 ) ;
goto V_79;
}
F_17 ( V_2 , V_75 ) ;
return V_86 ;
V_79:
F_32 ( V_75 ) ;
return V_86 ;
}
static inline void F_33 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_24 ;
V_24 = F_3 ( V_2 , V_11 ) ;
while ( V_11 ) {
struct V_11 * V_87 = V_11 -> V_47 ;
V_11 -> V_47 = NULL ;
V_11 -> V_88 = V_24 ;
F_34 ( V_11 ) ;
V_11 = V_87 ;
}
}
static inline int F_35 ( struct V_1 * V_2 )
{
return F_36 ( & V_2 -> V_65 ) ||
( V_2 -> V_80 == V_89 ) ;
}
static int F_37 ( void * V_90 )
{
struct V_1 * V_2 = V_90 ;
struct V_11 * V_11 ;
unsigned int V_69 ;
unsigned long V_91 = 0 ;
unsigned long V_92 = 0 ;
struct V_13 * V_14 ;
int V_93 ;
int V_24 = 0 ;
F_38 ( V_94 , V_95 ) ;
V_2 -> V_80 = V_81 ;
V_14 = F_39 ( & V_93 ) ;
if ( F_40 ( V_14 ) ) {
V_24 = F_41 ( V_14 ) ;
goto V_96;
}
V_2 -> V_15 = V_14 ;
memset ( & V_2 -> V_34 , 0 , sizeof( V_2 -> V_34 ) ) ;
V_2 -> V_34 . V_37 = V_2 -> V_97 [ 0 ] . V_98 ;
V_2 -> V_34 . V_39 = V_2 -> V_97 [ 0 ] . V_99 ;
F_42 ( & V_2 -> V_100 ) ;
for (; ; ) {
F_43 ( V_2 -> V_66 , F_35 ( V_2 ) ) ;
if ( ! F_36 ( & V_2 -> V_65 ) ) {
int V_101 = 0 ;
F_24 ( & V_2 -> V_62 ) ;
V_101 = ( V_2 -> V_80 == V_89 ) ;
F_26 ( & V_2 -> V_62 ) ;
if ( V_101 )
break;
}
V_11 = NULL ;
V_69 = F_23 ( V_2 , & V_11 ) ;
if ( ! V_69 ) {
F_44 ( L_4 , V_2 -> V_102 ) ;
continue;
}
V_92 += V_69 ;
if ( V_92 < V_69 ) {
V_92 = V_69 ;
V_91 = 1 ;
} else {
V_91 ++ ;
}
if ( ( V_91 & 127 ) == 0 ) {
F_27 ( V_71 , L_5 ,
V_92 , V_91 , V_92 / V_91 ) ;
}
F_8 ( V_11 != NULL ) ;
F_8 ( V_69 <= F_36 ( & V_2 -> V_65 ) ) ;
F_33 ( V_2 , V_11 ) ;
F_45 ( V_69 , & V_2 -> V_65 ) ;
}
F_46 ( V_14 , & V_93 ) ;
V_96:
F_42 ( & V_2 -> V_100 ) ;
return V_24 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_3 * V_103 ,
struct V_104 * V_105 , struct V_3 * V_3 )
{
struct V_19 * V_19 ;
struct V_106 * V_107 ;
int V_82 = 0 ;
int error ;
T_1 V_4 ;
if ( ! F_48 ( V_108 ) )
return - V_109 ;
error = - V_110 ;
if ( V_2 -> V_80 != V_111 )
goto V_96;
V_107 = V_3 -> V_7 ;
V_19 = V_107 -> V_8 ;
error = - V_112 ;
if ( ! F_49 ( V_19 -> V_113 ) || V_19 -> V_114 -> V_115 != V_116 )
goto V_96;
if ( ! ( V_3 -> V_117 & V_118 ) )
V_82 |= V_83 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( ( T_1 ) ( V_119 ) V_4 != V_4 ) {
error = - V_120 ;
goto V_96;
}
F_6 ( V_107 , 0 ) ;
F_50 ( V_105 , ( V_82 & V_83 ) != 0 ) ;
V_2 -> V_121 = V_52 ;
V_2 -> V_122 = V_105 ;
V_2 -> V_82 = V_82 ;
V_2 -> V_20 = V_3 ;
V_2 -> V_10 = 0 ;
V_2 -> V_123 = F_51 ( V_107 ) ;
F_52 ( V_107 , V_2 -> V_123 & ~ ( V_124 | V_125 ) ) ;
V_2 -> V_64 = V_2 -> V_63 = NULL ;
F_53 ( V_2 -> V_126 , F_28 ) ;
V_2 -> V_126 -> V_76 = V_2 ;
F_54 ( V_52 < ( 1 << (sizeof( unsigned short ) * 8 ) ) ) ;
F_55 ( V_2 -> V_126 ,
( unsigned short ) V_52 ) ;
F_56 ( V_2 -> V_126 ,
V_54 << ( V_59 - 9 ) ) ;
F_57 ( V_2 -> V_126 , V_54 ) ;
F_58 ( V_127 [ V_2 -> V_102 ] , V_4 ) ;
F_59 ( V_105 , V_4 << 9 ) ;
F_60 ( V_105 , V_2 -> V_121 ) ;
F_61 ( F_37 , V_2 , L_6 , V_2 -> V_102 ) ;
F_62 ( & V_2 -> V_100 ) ;
return 0 ;
V_96:
F_63 ( V_108 ) ;
return error ;
}
static int F_64 ( struct V_1 * V_2 , struct V_104 * V_105 ,
int V_69 )
{
struct V_3 * V_128 = V_2 -> V_20 ;
T_6 V_129 = V_2 -> V_123 ;
if ( V_2 -> V_80 != V_81 )
return - V_130 ;
if ( V_2 -> V_131 > V_69 )
return - V_110 ;
if ( V_128 == NULL )
return - V_112 ;
F_24 ( & V_2 -> V_62 ) ;
V_2 -> V_80 = V_89 ;
F_26 ( & V_2 -> V_62 ) ;
F_22 ( & V_2 -> V_66 ) ;
F_62 ( & V_2 -> V_100 ) ;
V_2 -> V_20 = NULL ;
V_2 -> V_122 = NULL ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_82 = 0 ;
F_65 ( V_105 ) ;
F_58 ( V_127 [ V_2 -> V_102 ] , 0 ) ;
F_59 ( V_105 , 0 ) ;
F_52 ( V_128 -> V_7 , V_129 ) ;
V_2 -> V_80 = V_111 ;
F_66 ( V_128 ) ;
F_63 ( V_108 ) ;
return 0 ;
}
static int F_67 ( struct V_104 * V_105 , T_7 V_132 )
{
struct V_1 * V_2 = V_105 -> V_133 -> V_134 ;
F_68 ( & V_2 -> V_135 ) ;
V_2 -> V_131 ++ ;
F_69 ( & V_2 -> V_135 ) ;
return 0 ;
}
static void F_70 ( struct V_136 * V_137 , T_7 V_132 )
{
struct V_1 * V_2 = V_137 -> V_134 ;
F_68 ( & V_2 -> V_135 ) ;
-- V_2 -> V_131 ;
F_69 ( & V_2 -> V_135 ) ;
}
static int F_71 ( struct V_104 * V_105 , T_7 V_132 ,
unsigned int V_138 , unsigned long V_139 )
{
struct V_1 * V_2 = V_105 -> V_133 -> V_134 ;
struct V_19 * V_19 = NULL ;
int V_79 = 0 ;
F_68 ( & V_140 ) ;
switch ( V_138 ) {
case V_141 : {
V_79 = F_64 ( V_2 , V_105 , 2 ) ;
if ( V_79 == 0 )
F_72 ( V_105 , 0 ) ;
break;
}
case V_142 : {
struct V_143 V_144 ;
if ( V_2 -> V_20 == NULL ) {
V_79 = - V_145 ;
break;
}
if ( V_19 == NULL )
V_19 = F_4 ( V_2 -> V_20 ) ;
if ( V_2 -> V_80 == V_81 )
V_144 = F_5 ( V_19 ) -> V_146 ;
else
F_73 ( & V_144 ) ;
if ( F_74 ( (struct V_143 * ) V_139 , & V_144 , sizeof( V_144 ) ) )
V_79 = - V_147 ;
break;
}
default:
V_79 = - V_112 ;
break;
}
F_69 ( & V_140 ) ;
return V_79 ;
}
static enum V_148 F_75 ( struct V_19 * V_103 , struct V_3 * V_3 ,
unsigned int V_138 , unsigned long V_139 ,
void * V_149 , int * V_150 )
{
struct V_1 * V_2 = NULL ;
struct V_104 * V_105 = NULL ;
int V_79 = 0 ;
T_8 V_151 ;
if ( V_149 != V_152 )
return V_153 ;
if ( V_127 == NULL ) {
V_79 = - V_109 ;
goto V_154;
}
F_44 ( L_7 ) ;
F_68 ( & V_140 ) ;
switch ( V_138 ) {
case V_155 : {
struct V_1 * V_156 = NULL ;
int V_157 ;
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ , V_2 = NULL ) {
V_2 = & V_159 [ V_157 ] ;
if ( V_2 -> V_80 == V_111 ) {
if ( ! V_156 )
V_156 = V_2 ;
continue;
}
if ( F_4 ( V_2 -> V_20 ) == F_4 ( V_3 ) )
break;
}
if ( V_2 || ! V_156 ) {
V_79 = - V_110 ;
goto V_96;
}
V_2 = V_156 ;
V_151 = F_76 ( V_160 , V_2 -> V_102 ) ;
if ( F_77 ( ( long ) F_78 ( V_151 ) , ( long * ) V_139 ) ) {
V_79 = - V_147 ;
goto V_96;
}
V_105 = F_79 ( V_151 , V_3 -> V_117 , NULL ) ;
if ( F_40 ( V_105 ) ) {
V_79 = F_41 ( V_105 ) ;
goto V_96;
}
F_80 ( V_3 ) ;
V_79 = F_47 ( V_2 , NULL , V_105 , V_3 ) ;
if ( V_79 ) {
F_66 ( V_3 ) ;
F_72 ( V_105 , 0 ) ;
}
break;
}
case V_161 : {
int V_162 ;
V_151 = F_81 ( V_139 ) ;
if ( F_82 ( V_151 ) != V_160 ) {
V_79 = - V_112 ;
goto V_96;
}
V_162 = F_83 ( V_151 ) ;
if ( V_162 > V_158 - 1 ) {
V_79 = - V_112 ;
goto V_96;
}
V_2 = & V_159 [ V_162 ] ;
if ( V_2 -> V_80 != V_81 ) {
V_79 = - V_112 ;
goto V_96;
}
V_105 = V_2 -> V_122 ;
V_79 = F_64 ( V_2 , V_105 , 1 ) ;
if ( V_79 == 0 )
F_72 ( V_105 , 0 ) ;
break;
}
default:
V_79 = - V_112 ;
break;
}
V_96:
F_69 ( & V_140 ) ;
V_154:
if ( V_150 )
* V_150 = V_79 ;
return V_163 ;
}
static int T_9 F_84 ( void )
{
int V_157 ;
unsigned int V_164 [] = {
V_155 ,
V_161 ,
} ;
if ( V_158 < 1 || V_158 > 256 ) {
V_158 = V_165 ;
F_44 ( L_8 ,
V_158 ) ;
}
V_160 = F_85 ( 0 , L_9 ) ;
if ( V_160 < 0 )
return - V_166 ;
F_27 ( V_167 , L_10 ,
V_160 , V_158 ) ;
V_152 = F_86 ( F_75 , 2 , V_164 ) ;
if ( V_152 == NULL )
goto V_168;
V_159 = F_87 ( V_158 , sizeof( * V_159 ) , V_169 ) ;
if ( ! V_159 )
goto V_168;
V_127 = F_87 ( V_158 , sizeof( * V_127 ) , V_169 ) ;
if ( ! V_127 )
goto V_170;
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ ) {
V_127 [ V_157 ] = F_88 ( 1 ) ;
if ( ! V_127 [ V_157 ] )
goto V_171;
}
F_89 ( & V_140 ) ;
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ ) {
struct V_1 * V_2 = & V_159 [ V_157 ] ;
struct V_136 * V_137 = V_127 [ V_157 ] ;
V_2 -> V_126 = F_90 ( V_169 ) ;
if ( ! V_2 -> V_126 )
goto V_172;
F_89 ( & V_2 -> V_135 ) ;
F_91 ( & V_2 -> V_100 , 0 ) ;
F_92 ( & V_2 -> V_66 ) ;
V_2 -> V_102 = V_157 ;
F_93 ( & V_2 -> V_62 ) ;
V_137 -> V_173 = V_160 ;
V_137 -> V_174 = V_157 ;
V_137 -> V_175 = & V_176 ;
sprintf ( V_137 -> V_177 , L_6 , V_157 ) ;
V_137 -> V_134 = V_2 ;
V_137 -> V_178 = V_2 -> V_126 ;
}
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ )
F_94 ( V_127 [ V_157 ] ) ;
return 0 ;
V_172:
while ( V_157 -- )
F_95 ( V_159 [ V_157 ] . V_126 ) ;
V_157 = V_158 ;
V_171:
while ( V_157 -- )
F_96 ( V_127 [ V_157 ] ) ;
F_97 ( V_127 ) ;
V_170:
F_97 ( V_159 ) ;
V_168:
F_98 ( V_160 , L_9 ) ;
F_99 ( V_152 ) ;
F_31 ( L_11 ) ;
return - V_179 ;
}
static void F_100 ( void )
{
int V_157 ;
F_99 ( V_152 ) ;
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ ) {
F_101 ( V_127 [ V_157 ] ) ;
F_95 ( V_159 [ V_157 ] . V_126 ) ;
F_96 ( V_127 [ V_157 ] ) ;
}
F_98 ( V_160 , L_9 ) ;
F_97 ( V_127 ) ;
F_97 ( V_159 ) ;
}
