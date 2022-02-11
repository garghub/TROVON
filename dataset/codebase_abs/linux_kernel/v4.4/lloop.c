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
static T_5 F_28 ( struct V_74 * V_75 , struct V_11 * V_76 )
{
struct V_1 * V_2 = V_75 -> V_77 ;
int V_25 = F_29 ( V_76 ) ;
int V_78 ;
F_30 ( V_75 , & V_76 , V_75 -> V_79 ) ;
if ( ! V_2 )
goto V_80;
F_27 ( V_72 , L_2 ,
( unsigned long long ) V_76 -> V_48 . V_49 ,
V_76 -> V_48 . V_73 ) ;
F_24 ( & V_2 -> V_63 ) ;
V_78 = V_2 -> V_81 != V_82 ;
F_26 ( & V_2 -> V_63 ) ;
if ( V_78 )
goto V_80;
if ( V_25 == V_55 ) {
if ( V_2 -> V_83 & V_84 )
goto V_80;
} else if ( V_25 == V_85 ) {
V_25 = V_86 ;
} else if ( V_25 != V_86 ) {
F_31 ( L_3 , V_25 ) ;
goto V_80;
}
F_17 ( V_2 , V_76 ) ;
return V_87 ;
V_80:
F_32 ( V_76 ) ;
return V_87 ;
}
static inline void F_33 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_24 ;
V_24 = F_3 ( V_2 , V_11 ) ;
while ( V_11 ) {
struct V_11 * V_88 = V_11 -> V_47 ;
V_11 -> V_47 = NULL ;
V_11 -> V_89 = V_24 ;
F_34 ( V_11 ) ;
V_11 = V_88 ;
}
}
static inline int F_35 ( struct V_1 * V_2 )
{
return F_36 ( & V_2 -> V_66 ) ||
( V_2 -> V_81 == V_90 ) ;
}
static int F_37 ( void * V_91 )
{
struct V_1 * V_2 = V_91 ;
struct V_11 * V_11 ;
unsigned int V_70 ;
unsigned long V_92 = 0 ;
unsigned long V_93 = 0 ;
struct V_13 * V_14 ;
int V_94 ;
int V_24 = 0 ;
F_38 ( V_95 , V_96 ) ;
V_2 -> V_81 = V_82 ;
V_14 = F_39 ( & V_94 ) ;
if ( F_40 ( V_14 ) ) {
V_24 = F_41 ( V_14 ) ;
goto V_97;
}
V_2 -> V_15 = V_14 ;
memset ( & V_2 -> V_34 , 0 , sizeof( V_2 -> V_34 ) ) ;
V_2 -> V_34 . V_37 = V_2 -> V_98 [ 0 ] . V_99 ;
V_2 -> V_34 . V_39 = V_2 -> V_98 [ 0 ] . V_100 ;
F_42 ( & V_2 -> V_101 ) ;
for (; ; ) {
F_43 ( V_2 -> V_67 , F_35 ( V_2 ) ) ;
if ( ! F_36 ( & V_2 -> V_66 ) ) {
int V_102 = 0 ;
F_24 ( & V_2 -> V_63 ) ;
V_102 = ( V_2 -> V_81 == V_90 ) ;
F_26 ( & V_2 -> V_63 ) ;
if ( V_102 )
break;
}
V_11 = NULL ;
V_70 = F_23 ( V_2 , & V_11 ) ;
if ( ! V_70 ) {
F_44 ( L_4 , V_2 -> V_103 ) ;
continue;
}
V_93 += V_70 ;
if ( V_93 < V_70 ) {
V_93 = V_70 ;
V_92 = 1 ;
} else {
V_92 ++ ;
}
if ( ( V_92 & 127 ) == 0 ) {
F_27 ( V_72 , L_5 ,
V_93 , V_92 , V_93 / V_92 ) ;
}
F_8 ( V_11 != NULL ) ;
F_8 ( V_70 <= F_36 ( & V_2 -> V_66 ) ) ;
F_33 ( V_2 , V_11 ) ;
F_45 ( V_70 , & V_2 -> V_66 ) ;
}
F_46 ( V_14 , & V_94 ) ;
V_97:
F_42 ( & V_2 -> V_101 ) ;
return V_24 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_3 * V_104 ,
struct V_105 * V_106 , struct V_3 * V_3 )
{
struct V_19 * V_19 ;
struct V_107 * V_108 ;
int V_83 = 0 ;
int error ;
T_1 V_4 ;
if ( ! F_48 ( V_109 ) )
return - V_110 ;
error = - V_111 ;
if ( V_2 -> V_81 != V_112 )
goto V_97;
V_108 = V_3 -> V_7 ;
V_19 = V_108 -> V_8 ;
error = - V_113 ;
if ( ! F_49 ( V_19 -> V_114 ) || V_19 -> V_115 -> V_116 != V_117 )
goto V_97;
if ( ! ( V_3 -> V_118 & V_119 ) )
V_83 |= V_84 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( ( T_1 ) ( V_120 ) V_4 != V_4 ) {
error = - V_121 ;
goto V_97;
}
F_6 ( V_108 , 0 ) ;
F_50 ( V_106 , ( V_83 & V_84 ) != 0 ) ;
V_2 -> V_122 = V_52 ;
V_2 -> V_123 = V_106 ;
V_2 -> V_83 = V_83 ;
V_2 -> V_20 = V_3 ;
V_2 -> V_10 = 0 ;
V_2 -> V_124 = F_51 ( V_108 ) ;
F_52 ( V_108 , V_2 -> V_124 & ~ ( V_125 | V_126 ) ) ;
V_2 -> V_65 = V_2 -> V_64 = NULL ;
F_53 ( V_2 -> V_127 , F_28 ) ;
V_2 -> V_127 -> V_77 = V_2 ;
F_54 ( V_52 < ( 1 << (sizeof( unsigned short ) * 8 ) ) ) ;
F_55 ( V_2 -> V_127 ,
( unsigned short ) V_52 ) ;
F_56 ( V_2 -> V_127 ,
V_54 << ( V_59 - 9 ) ) ;
F_57 ( V_2 -> V_127 , V_54 ) ;
F_58 ( V_128 [ V_2 -> V_103 ] , V_4 ) ;
F_59 ( V_106 , V_4 << 9 ) ;
F_60 ( V_106 , V_2 -> V_122 ) ;
F_61 ( F_37 , V_2 , L_6 , V_2 -> V_103 ) ;
F_62 ( & V_2 -> V_101 ) ;
return 0 ;
V_97:
F_63 ( V_109 ) ;
return error ;
}
static int F_64 ( struct V_1 * V_2 , struct V_105 * V_106 ,
int V_70 )
{
struct V_3 * V_129 = V_2 -> V_20 ;
T_6 V_130 = V_2 -> V_124 ;
if ( V_2 -> V_81 != V_82 )
return - V_131 ;
if ( V_2 -> V_132 > V_70 )
return - V_111 ;
if ( V_129 == NULL )
return - V_113 ;
F_24 ( & V_2 -> V_63 ) ;
V_2 -> V_81 = V_90 ;
F_26 ( & V_2 -> V_63 ) ;
F_22 ( & V_2 -> V_67 ) ;
F_62 ( & V_2 -> V_101 ) ;
V_2 -> V_20 = NULL ;
V_2 -> V_123 = NULL ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_83 = 0 ;
F_65 ( V_106 ) ;
F_58 ( V_128 [ V_2 -> V_103 ] , 0 ) ;
F_59 ( V_106 , 0 ) ;
F_52 ( V_129 -> V_7 , V_130 ) ;
V_2 -> V_81 = V_112 ;
F_66 ( V_129 ) ;
F_63 ( V_109 ) ;
return 0 ;
}
static int F_67 ( struct V_105 * V_106 , T_7 V_133 )
{
struct V_1 * V_2 = V_106 -> V_134 -> V_135 ;
F_13 ( & V_2 -> V_136 ) ;
V_2 -> V_132 ++ ;
F_15 ( & V_2 -> V_136 ) ;
return 0 ;
}
static void F_68 ( struct V_137 * V_138 , T_7 V_133 )
{
struct V_1 * V_2 = V_138 -> V_135 ;
F_13 ( & V_2 -> V_136 ) ;
-- V_2 -> V_132 ;
F_15 ( & V_2 -> V_136 ) ;
}
static int F_69 ( struct V_105 * V_106 , T_7 V_133 ,
unsigned int V_139 , unsigned long V_140 )
{
struct V_1 * V_2 = V_106 -> V_134 -> V_135 ;
struct V_19 * V_19 = NULL ;
int V_80 = 0 ;
F_13 ( & V_141 ) ;
switch ( V_139 ) {
case V_142 : {
V_80 = F_64 ( V_2 , V_106 , 2 ) ;
if ( V_80 == 0 )
F_70 ( V_106 , 0 ) ;
break;
}
case V_143 : {
struct V_144 V_145 ;
if ( V_2 -> V_20 == NULL ) {
V_80 = - V_146 ;
break;
}
if ( V_19 == NULL )
V_19 = F_4 ( V_2 -> V_20 ) ;
if ( V_2 -> V_81 == V_82 )
V_145 = F_5 ( V_19 ) -> V_147 ;
else
F_71 ( & V_145 ) ;
if ( F_72 ( (struct V_144 * ) V_140 , & V_145 , sizeof( V_145 ) ) )
V_80 = - V_148 ;
break;
}
default:
V_80 = - V_113 ;
break;
}
F_15 ( & V_141 ) ;
return V_80 ;
}
static enum V_149 F_73 ( struct V_19 * V_104 , struct V_3 * V_3 ,
unsigned int V_139 , unsigned long V_140 ,
void * V_150 , int * V_151 )
{
struct V_1 * V_2 = NULL ;
struct V_105 * V_106 = NULL ;
int V_80 = 0 ;
T_8 V_152 ;
if ( V_150 != V_153 )
return V_154 ;
if ( V_128 == NULL ) {
V_80 = - V_110 ;
goto V_155;
}
F_44 ( L_7 ) ;
F_13 ( & V_141 ) ;
switch ( V_139 ) {
case V_156 : {
struct V_1 * V_157 = NULL ;
int V_158 ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ , V_2 = NULL ) {
V_2 = & V_160 [ V_158 ] ;
if ( V_2 -> V_81 == V_112 ) {
if ( ! V_157 )
V_157 = V_2 ;
continue;
}
if ( F_4 ( V_2 -> V_20 ) == F_4 ( V_3 ) )
break;
}
if ( V_2 || ! V_157 ) {
V_80 = - V_111 ;
goto V_97;
}
V_2 = V_157 ;
V_152 = F_74 ( V_161 , V_2 -> V_103 ) ;
if ( F_75 ( ( long ) F_76 ( V_152 ) , ( long * ) V_140 ) ) {
V_80 = - V_148 ;
goto V_97;
}
V_106 = F_77 ( V_152 , V_3 -> V_118 , NULL ) ;
if ( F_40 ( V_106 ) ) {
V_80 = F_41 ( V_106 ) ;
goto V_97;
}
F_78 ( V_3 ) ;
V_80 = F_47 ( V_2 , NULL , V_106 , V_3 ) ;
if ( V_80 ) {
F_66 ( V_3 ) ;
F_70 ( V_106 , 0 ) ;
}
break;
}
case V_162 : {
int V_163 ;
V_152 = F_79 ( V_140 ) ;
if ( F_80 ( V_152 ) != V_161 ) {
V_80 = - V_113 ;
goto V_97;
}
V_163 = F_81 ( V_152 ) ;
if ( V_163 > V_159 - 1 ) {
V_80 = - V_113 ;
goto V_97;
}
V_2 = & V_160 [ V_163 ] ;
if ( V_2 -> V_81 != V_82 ) {
V_80 = - V_113 ;
goto V_97;
}
V_106 = V_2 -> V_123 ;
V_80 = F_64 ( V_2 , V_106 , 1 ) ;
if ( V_80 == 0 )
F_70 ( V_106 , 0 ) ;
break;
}
default:
V_80 = - V_113 ;
break;
}
V_97:
F_15 ( & V_141 ) ;
V_155:
if ( V_151 )
* V_151 = V_80 ;
return V_164 ;
}
static int T_9 F_82 ( void )
{
int V_158 ;
unsigned int V_165 [] = {
V_156 ,
V_162 ,
} ;
if ( V_159 < 1 || V_159 > 256 ) {
V_159 = V_166 ;
F_44 ( L_8 ,
V_159 ) ;
}
V_161 = F_83 ( 0 , L_9 ) ;
if ( V_161 < 0 )
return - V_167 ;
F_27 ( V_168 , L_10 ,
V_161 , V_159 ) ;
V_153 = F_84 ( F_73 , 2 , V_165 ) ;
if ( V_153 == NULL )
goto V_169;
V_160 = F_85 ( V_159 , sizeof( * V_160 ) , V_170 ) ;
if ( ! V_160 )
goto V_169;
V_128 = F_85 ( V_159 , sizeof( * V_128 ) , V_170 ) ;
if ( ! V_128 )
goto V_171;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
V_128 [ V_158 ] = F_86 ( 1 ) ;
if ( ! V_128 [ V_158 ] )
goto V_172;
}
F_87 ( & V_141 ) ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
struct V_1 * V_2 = & V_160 [ V_158 ] ;
struct V_137 * V_138 = V_128 [ V_158 ] ;
V_2 -> V_127 = F_88 ( V_170 ) ;
if ( ! V_2 -> V_127 )
goto V_173;
F_87 ( & V_2 -> V_136 ) ;
F_89 ( & V_2 -> V_101 , 0 ) ;
F_90 ( & V_2 -> V_67 ) ;
V_2 -> V_103 = V_158 ;
F_91 ( & V_2 -> V_63 ) ;
V_138 -> V_174 = V_161 ;
V_138 -> V_175 = V_158 ;
V_138 -> V_176 = & V_177 ;
sprintf ( V_138 -> V_178 , L_6 , V_158 ) ;
V_138 -> V_135 = V_2 ;
V_138 -> V_179 = V_2 -> V_127 ;
}
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ )
F_92 ( V_128 [ V_158 ] ) ;
return 0 ;
V_173:
while ( V_158 -- )
F_93 ( V_160 [ V_158 ] . V_127 ) ;
V_158 = V_159 ;
V_172:
while ( V_158 -- )
F_94 ( V_128 [ V_158 ] ) ;
F_95 ( V_128 ) ;
V_171:
F_95 ( V_160 ) ;
V_169:
F_96 ( V_161 , L_9 ) ;
F_97 ( V_153 ) ;
F_31 ( L_11 ) ;
return - V_180 ;
}
static void F_98 ( void )
{
int V_158 ;
F_97 ( V_153 ) ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_99 ( V_128 [ V_158 ] ) ;
F_93 ( V_160 [ V_158 ] . V_127 ) ;
F_94 ( V_128 [ V_158 ] ) ;
}
F_96 ( V_161 , L_9 ) ;
F_95 ( V_128 ) ;
F_95 ( V_160 ) ;
}
