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
F_13 ( & V_19 -> V_61 ) ;
V_31 = F_14 ( V_14 , V_17 , V_25 , V_19 , V_33 ) ;
F_15 ( & V_19 -> V_61 ) ;
F_16 ( V_14 , V_17 ) ;
return ( V_31 == V_33 -> V_58 ) ? 0 : ( int ) V_31 ;
}
static void F_17 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
unsigned long V_62 ;
F_18 ( & V_2 -> V_63 , V_62 ) ;
if ( V_2 -> V_64 ) {
V_2 -> V_64 -> V_47 = V_11 ;
V_2 -> V_64 = V_11 ;
} else
V_2 -> V_65 = V_2 -> V_64 = V_11 ;
F_19 ( & V_2 -> V_63 , V_62 ) ;
F_20 ( & V_2 -> V_66 ) ;
if ( F_21 ( & V_2 -> V_67 ) )
F_22 ( & V_2 -> V_67 ) ;
}
static unsigned int F_23 ( struct V_1 * V_2 , struct V_11 * * V_68 )
{
struct V_11 * V_69 ;
struct V_11 * * V_11 ;
unsigned int V_70 = 0 ;
unsigned int V_26 = 0 ;
int V_25 ;
F_24 ( & V_2 -> V_63 ) ;
V_69 = V_2 -> V_65 ;
if ( F_25 ( V_69 == NULL ) ) {
F_26 ( & V_2 -> V_63 ) ;
return 0 ;
}
F_8 ( V_69 -> V_71 <= V_54 ) ;
V_25 = V_69 -> V_46 ;
V_11 = & V_2 -> V_65 ;
while ( * V_11 && ( * V_11 ) -> V_46 == V_25 ) {
F_27 ( V_72 , L_1 ,
( unsigned long long ) ( * V_11 ) -> V_48 . V_49 ,
( * V_11 ) -> V_48 . V_73 ,
V_26 , ( * V_11 ) -> V_71 ) ;
if ( V_26 + ( * V_11 ) -> V_71 > V_54 )
break;
V_26 += ( * V_11 ) -> V_71 ;
V_70 ++ ;
V_11 = & ( * V_11 ) -> V_47 ;
}
if ( * V_11 ) {
V_2 -> V_65 = * V_11 ;
* V_11 = NULL ;
} else {
V_2 -> V_64 = NULL ;
V_2 -> V_65 = NULL ;
}
* V_68 = V_69 ;
F_26 ( & V_2 -> V_63 ) ;
return V_70 ;
}
static void F_28 ( struct V_74 * V_75 , struct V_11 * V_76 )
{
struct V_1 * V_2 = V_75 -> V_77 ;
int V_25 = F_29 ( V_76 ) ;
int V_78 ;
if ( ! V_2 )
goto V_79;
F_27 ( V_72 , L_2 ,
( unsigned long long ) V_76 -> V_48 . V_49 ,
V_76 -> V_48 . V_73 ) ;
F_24 ( & V_2 -> V_63 ) ;
V_78 = V_2 -> V_80 != V_81 ;
F_26 ( & V_2 -> V_63 ) ;
if ( V_78 )
goto V_79;
if ( V_25 == V_55 ) {
if ( V_2 -> V_82 & V_83 )
goto V_79;
} else if ( V_25 == V_84 ) {
V_25 = V_85 ;
} else if ( V_25 != V_85 ) {
F_30 ( L_3 , V_25 ) ;
goto V_79;
}
F_17 ( V_2 , V_76 ) ;
return;
V_79:
F_31 ( V_76 , V_76 -> V_48 . V_73 ) ;
}
static inline void F_32 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_24 ;
V_24 = F_3 ( V_2 , V_11 ) ;
while ( V_11 ) {
struct V_11 * V_86 = V_11 -> V_47 ;
V_11 -> V_47 = NULL ;
F_33 ( V_11 , V_11 -> V_48 . V_73 , V_24 ) ;
V_11 = V_86 ;
}
}
static inline int F_34 ( struct V_1 * V_2 )
{
return F_35 ( & V_2 -> V_66 ) ||
( V_2 -> V_80 == V_87 ) ;
}
static int F_36 ( void * V_88 )
{
struct V_1 * V_2 = V_88 ;
struct V_11 * V_11 ;
unsigned int V_70 ;
unsigned long V_89 = 0 ;
unsigned long V_90 = 0 ;
struct V_13 * V_14 ;
int V_91 ;
int V_24 = 0 ;
F_37 ( V_92 , V_93 ) ;
V_2 -> V_80 = V_81 ;
V_14 = F_38 ( & V_91 ) ;
if ( F_39 ( V_14 ) ) {
V_24 = F_40 ( V_14 ) ;
goto V_94;
}
V_2 -> V_15 = V_14 ;
memset ( & V_2 -> V_34 , 0 , sizeof( V_2 -> V_34 ) ) ;
V_2 -> V_34 . V_37 = V_2 -> V_95 [ 0 ] . V_96 ;
V_2 -> V_34 . V_39 = V_2 -> V_95 [ 0 ] . V_97 ;
F_41 ( & V_2 -> V_98 ) ;
for (; ; ) {
F_42 ( V_2 -> V_67 , F_34 ( V_2 ) ) ;
if ( ! F_35 ( & V_2 -> V_66 ) ) {
int V_99 = 0 ;
F_24 ( & V_2 -> V_63 ) ;
V_99 = ( V_2 -> V_80 == V_87 ) ;
F_26 ( & V_2 -> V_63 ) ;
if ( V_99 )
break;
}
V_11 = NULL ;
V_70 = F_23 ( V_2 , & V_11 ) ;
if ( ! V_70 ) {
F_43 ( L_4 , V_2 -> V_100 ) ;
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
F_27 ( V_72 , L_5 ,
V_90 , V_89 , V_90 / V_89 ) ;
}
F_8 ( V_11 != NULL ) ;
F_8 ( V_70 <= F_35 ( & V_2 -> V_66 ) ) ;
F_32 ( V_2 , V_11 ) ;
F_44 ( V_70 , & V_2 -> V_66 ) ;
}
F_45 ( V_14 , & V_91 ) ;
V_94:
F_41 ( & V_2 -> V_98 ) ;
return V_24 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_3 * V_101 ,
struct V_102 * V_103 , struct V_3 * V_3 )
{
struct V_19 * V_19 ;
struct V_104 * V_105 ;
int V_82 = 0 ;
int error ;
T_1 V_4 ;
if ( ! F_47 ( V_106 ) )
return - V_107 ;
error = - V_108 ;
if ( V_2 -> V_80 != V_109 )
goto V_94;
V_105 = V_3 -> V_7 ;
V_19 = V_105 -> V_8 ;
error = - V_110 ;
if ( ! F_48 ( V_19 -> V_111 ) || V_19 -> V_112 -> V_113 != V_114 )
goto V_94;
if ( ! ( V_3 -> V_115 & V_116 ) )
V_82 |= V_83 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( ( T_1 ) ( V_117 ) V_4 != V_4 ) {
error = - V_118 ;
goto V_94;
}
F_6 ( V_105 , 0 ) ;
F_49 ( V_103 , ( V_82 & V_83 ) != 0 ) ;
V_2 -> V_119 = V_52 ;
V_2 -> V_120 = V_103 ;
V_2 -> V_82 = V_82 ;
V_2 -> V_20 = V_3 ;
V_2 -> V_10 = 0 ;
V_2 -> V_121 = F_50 ( V_105 ) ;
F_51 ( V_105 , V_2 -> V_121 & ~ ( V_122 | V_123 ) ) ;
V_2 -> V_65 = V_2 -> V_64 = NULL ;
F_52 ( V_2 -> V_124 , F_28 ) ;
V_2 -> V_124 -> V_77 = V_2 ;
F_53 ( V_52 < ( 1 << (sizeof( unsigned short ) * 8 ) ) ) ;
F_54 ( V_2 -> V_124 ,
( unsigned short ) V_52 ) ;
F_55 ( V_2 -> V_124 ,
V_54 << ( V_59 - 9 ) ) ;
F_56 ( V_2 -> V_124 , V_54 ) ;
F_57 ( V_125 [ V_2 -> V_100 ] , V_4 ) ;
F_58 ( V_103 , V_4 << 9 ) ;
F_59 ( V_103 , V_2 -> V_119 ) ;
F_60 ( F_36 , V_2 , L_6 , V_2 -> V_100 ) ;
F_61 ( & V_2 -> V_98 ) ;
return 0 ;
V_94:
F_62 ( V_106 ) ;
return error ;
}
static int F_63 ( struct V_1 * V_2 , struct V_102 * V_103 ,
int V_70 )
{
struct V_3 * V_126 = V_2 -> V_20 ;
T_5 V_127 = V_2 -> V_121 ;
if ( V_2 -> V_80 != V_81 )
return - V_128 ;
if ( V_2 -> V_129 > V_70 )
return - V_108 ;
if ( V_126 == NULL )
return - V_110 ;
F_24 ( & V_2 -> V_63 ) ;
V_2 -> V_80 = V_87 ;
F_26 ( & V_2 -> V_63 ) ;
F_22 ( & V_2 -> V_67 ) ;
F_61 ( & V_2 -> V_98 ) ;
V_2 -> V_20 = NULL ;
V_2 -> V_120 = NULL ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_82 = 0 ;
F_64 ( V_103 ) ;
F_57 ( V_125 [ V_2 -> V_100 ] , 0 ) ;
F_58 ( V_103 , 0 ) ;
F_51 ( V_126 -> V_7 , V_127 ) ;
V_2 -> V_80 = V_109 ;
F_65 ( V_126 ) ;
F_62 ( V_106 ) ;
return 0 ;
}
static int F_66 ( struct V_102 * V_103 , T_6 V_130 )
{
struct V_1 * V_2 = V_103 -> V_131 -> V_132 ;
F_13 ( & V_2 -> V_133 ) ;
V_2 -> V_129 ++ ;
F_15 ( & V_2 -> V_133 ) ;
return 0 ;
}
static void F_67 ( struct V_134 * V_135 , T_6 V_130 )
{
struct V_1 * V_2 = V_135 -> V_132 ;
F_13 ( & V_2 -> V_133 ) ;
-- V_2 -> V_129 ;
F_15 ( & V_2 -> V_133 ) ;
}
static int F_68 ( struct V_102 * V_103 , T_6 V_130 ,
unsigned int V_136 , unsigned long V_137 )
{
struct V_1 * V_2 = V_103 -> V_131 -> V_132 ;
struct V_19 * V_19 = NULL ;
int V_79 = 0 ;
F_13 ( & V_138 ) ;
switch ( V_136 ) {
case V_139 : {
V_79 = F_63 ( V_2 , V_103 , 2 ) ;
if ( V_79 == 0 )
F_69 ( V_103 , 0 ) ;
break;
}
case V_140 : {
struct V_141 V_142 ;
if ( V_2 -> V_20 == NULL ) {
V_79 = - V_143 ;
break;
}
if ( V_19 == NULL )
V_19 = F_4 ( V_2 -> V_20 ) ;
if ( V_2 -> V_80 == V_81 )
V_142 = F_5 ( V_19 ) -> V_144 ;
else
F_70 ( & V_142 ) ;
if ( F_71 ( (struct V_141 * ) V_137 , & V_142 , sizeof( V_142 ) ) )
V_79 = - V_145 ;
break;
}
default:
V_79 = - V_110 ;
break;
}
F_15 ( & V_138 ) ;
return V_79 ;
}
static enum V_146 F_72 ( struct V_19 * V_101 , struct V_3 * V_3 ,
unsigned int V_136 , unsigned long V_137 ,
void * V_147 , int * V_148 )
{
struct V_1 * V_2 = NULL ;
struct V_102 * V_103 = NULL ;
int V_79 = 0 ;
T_7 V_149 ;
if ( V_147 != V_150 )
return V_151 ;
if ( V_125 == NULL ) {
V_79 = - V_107 ;
goto V_152;
}
F_43 ( L_7 ) ;
F_13 ( & V_138 ) ;
switch ( V_136 ) {
case V_153 : {
struct V_1 * V_154 = NULL ;
int V_155 ;
for ( V_155 = 0 ; V_155 < V_156 ; V_155 ++ , V_2 = NULL ) {
V_2 = & V_157 [ V_155 ] ;
if ( V_2 -> V_80 == V_109 ) {
if ( ! V_154 )
V_154 = V_2 ;
continue;
}
if ( F_4 ( V_2 -> V_20 ) == F_4 ( V_3 ) )
break;
}
if ( V_2 || ! V_154 ) {
V_79 = - V_108 ;
goto V_94;
}
V_2 = V_154 ;
V_149 = F_73 ( V_158 , V_2 -> V_100 ) ;
if ( F_74 ( ( long ) F_75 ( V_149 ) , ( long * ) V_137 ) ) {
V_79 = - V_145 ;
goto V_94;
}
V_103 = F_76 ( V_149 , V_3 -> V_115 , NULL ) ;
if ( F_39 ( V_103 ) ) {
V_79 = F_40 ( V_103 ) ;
goto V_94;
}
F_77 ( V_3 ) ;
V_79 = F_46 ( V_2 , NULL , V_103 , V_3 ) ;
if ( V_79 ) {
F_65 ( V_3 ) ;
F_69 ( V_103 , 0 ) ;
}
break;
}
case V_159 : {
int V_160 ;
V_149 = F_78 ( V_137 ) ;
if ( F_79 ( V_149 ) != V_158 ) {
V_79 = - V_110 ;
goto V_94;
}
V_160 = F_80 ( V_149 ) ;
if ( V_160 > V_156 - 1 ) {
V_79 = - V_110 ;
goto V_94;
}
V_2 = & V_157 [ V_160 ] ;
if ( V_2 -> V_80 != V_81 ) {
V_79 = - V_110 ;
goto V_94;
}
V_103 = V_2 -> V_120 ;
V_79 = F_63 ( V_2 , V_103 , 1 ) ;
if ( V_79 == 0 )
F_69 ( V_103 , 0 ) ;
break;
}
default:
V_79 = - V_110 ;
break;
}
V_94:
F_15 ( & V_138 ) ;
V_152:
if ( V_148 )
* V_148 = V_79 ;
return V_161 ;
}
static int T_8 F_81 ( void )
{
int V_155 ;
unsigned int V_162 [] = {
V_153 ,
V_159 ,
} ;
if ( V_156 < 1 || V_156 > 256 ) {
V_156 = V_163 ;
F_43 ( L_8 ,
V_156 ) ;
}
V_158 = F_82 ( 0 , L_9 ) ;
if ( V_158 < 0 )
return - V_164 ;
F_27 ( V_165 , L_10 ,
V_158 , V_156 ) ;
V_150 = F_83 ( F_72 , 2 , V_162 ) ;
if ( V_150 == NULL )
goto V_166;
V_157 = F_84 ( V_156 , sizeof( * V_157 ) , V_167 ) ;
if ( ! V_157 )
goto V_166;
V_125 = F_84 ( V_156 , sizeof( * V_125 ) , V_167 ) ;
if ( ! V_125 )
goto V_168;
for ( V_155 = 0 ; V_155 < V_156 ; V_155 ++ ) {
V_125 [ V_155 ] = F_85 ( 1 ) ;
if ( ! V_125 [ V_155 ] )
goto V_169;
}
F_86 ( & V_138 ) ;
for ( V_155 = 0 ; V_155 < V_156 ; V_155 ++ ) {
struct V_1 * V_2 = & V_157 [ V_155 ] ;
struct V_134 * V_135 = V_125 [ V_155 ] ;
V_2 -> V_124 = F_87 ( V_167 ) ;
if ( ! V_2 -> V_124 )
goto V_170;
F_86 ( & V_2 -> V_133 ) ;
F_88 ( & V_2 -> V_98 , 0 ) ;
F_89 ( & V_2 -> V_67 ) ;
V_2 -> V_100 = V_155 ;
F_90 ( & V_2 -> V_63 ) ;
V_135 -> V_171 = V_158 ;
V_135 -> V_172 = V_155 ;
V_135 -> V_173 = & V_174 ;
sprintf ( V_135 -> V_175 , L_6 , V_155 ) ;
V_135 -> V_132 = V_2 ;
V_135 -> V_176 = V_2 -> V_124 ;
}
for ( V_155 = 0 ; V_155 < V_156 ; V_155 ++ )
F_91 ( V_125 [ V_155 ] ) ;
return 0 ;
V_170:
while ( V_155 -- )
F_92 ( V_157 [ V_155 ] . V_124 ) ;
V_155 = V_156 ;
V_169:
while ( V_155 -- )
F_93 ( V_125 [ V_155 ] ) ;
F_94 ( V_125 ) ;
V_168:
F_94 ( V_157 ) ;
V_166:
F_95 ( V_158 , L_9 ) ;
F_96 ( V_150 ) ;
F_30 ( L_11 ) ;
return - V_177 ;
}
static void F_97 ( void )
{
int V_155 ;
F_96 ( V_150 ) ;
for ( V_155 = 0 ; V_155 < V_156 ; V_155 ++ ) {
F_98 ( V_125 [ V_155 ] ) ;
F_92 ( V_157 [ V_155 ] . V_124 ) ;
F_93 ( V_125 [ V_155 ] ) ;
}
F_95 ( V_158 , L_9 ) ;
F_94 ( V_125 ) ;
F_94 ( V_157 ) ;
}
