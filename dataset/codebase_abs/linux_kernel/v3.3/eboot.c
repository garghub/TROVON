static T_1 F_1 ( T_2 * * V_1 , unsigned long * V_2 ,
unsigned long * V_3 )
{
T_2 * V_4 = NULL ;
T_1 V_5 ;
unsigned long V_6 ;
T_3 V_7 ;
* V_2 = sizeof( * V_4 ) * 32 ;
V_8:
* V_2 += sizeof( * V_4 ) ;
V_5 = F_2 ( V_9 -> V_10 -> V_11 ,
V_12 , * V_2 , ( void * * ) & V_4 ) ;
if ( V_5 != V_13 )
goto V_14;
V_5 = F_3 ( V_9 -> V_10 -> V_15 , V_2 ,
V_4 , & V_6 , V_3 , & V_7 ) ;
if ( V_5 == V_16 ) {
F_4 ( V_9 -> V_10 -> V_17 , V_4 ) ;
goto V_8;
}
if ( V_5 != V_13 )
F_4 ( V_9 -> V_10 -> V_17 , V_4 ) ;
V_14:
* V_1 = V_4 ;
return V_5 ;
}
static T_1 F_5 ( unsigned long V_18 , unsigned long V_19 ,
unsigned long * V_20 , unsigned long V_21 )
{
unsigned long V_2 , V_3 ;
T_2 * V_1 ;
T_1 V_5 ;
unsigned long V_22 ;
T_4 V_23 = 0 ;
int V_24 ;
V_5 = F_1 ( & V_1 , & V_2 , & V_3 ) ;
if ( V_5 != V_13 )
goto V_14;
V_22 = F_6 ( V_18 , V_25 ) / V_25 ;
V_8:
for ( V_24 = 0 ; V_24 < V_2 / V_3 ; V_24 ++ ) {
T_2 * V_26 ;
unsigned long V_4 = ( unsigned long ) V_1 ;
T_4 V_27 , V_28 ;
V_26 = ( T_2 * ) ( V_4 + ( V_24 * V_3 ) ) ;
if ( V_26 -> type != V_29 )
continue;
if ( V_26 -> V_30 < V_22 )
continue;
V_27 = V_26 -> V_31 ;
V_28 = V_27 + V_26 -> V_30 * ( 1UL << V_32 ) ;
if ( ( V_27 + V_18 ) > V_28 || ( V_27 + V_18 ) > V_21 )
continue;
if ( V_28 - V_18 > V_21 )
V_28 = V_21 ;
if ( F_7 ( V_28 - V_18 , V_19 ) < V_27 )
continue;
V_27 = F_7 ( V_28 - V_18 , V_19 ) ;
if ( V_27 == 0x0 )
continue;
if ( V_27 > V_23 )
V_23 = V_27 ;
}
if ( ! V_23 )
V_5 = V_33 ;
else {
V_5 = F_8 ( V_9 -> V_10 -> V_34 ,
V_35 , V_12 ,
V_22 , & V_23 ) ;
if ( V_5 != V_13 ) {
V_21 = V_23 ;
V_23 = 0 ;
goto V_8;
}
* V_20 = V_23 ;
}
V_17:
F_4 ( V_9 -> V_10 -> V_17 , V_1 ) ;
V_14:
return V_5 ;
}
static T_1 F_9 ( unsigned long V_18 , unsigned long V_19 ,
unsigned long * V_20 )
{
unsigned long V_2 , V_3 ;
T_2 * V_1 ;
T_1 V_5 ;
unsigned long V_22 ;
int V_24 ;
V_5 = F_1 ( & V_1 , & V_2 , & V_3 ) ;
if ( V_5 != V_13 )
goto V_14;
V_22 = F_6 ( V_18 , V_25 ) / V_25 ;
for ( V_24 = 0 ; V_24 < V_2 / V_3 ; V_24 ++ ) {
T_2 * V_26 ;
unsigned long V_4 = ( unsigned long ) V_1 ;
T_4 V_27 , V_28 ;
V_26 = ( T_2 * ) ( V_4 + ( V_24 * V_3 ) ) ;
if ( V_26 -> type != V_29 )
continue;
if ( V_26 -> V_30 < V_22 )
continue;
V_27 = V_26 -> V_31 ;
V_28 = V_27 + V_26 -> V_30 * ( 1UL << V_32 ) ;
if ( V_27 == 0x0 )
V_27 += 8 ;
V_27 = F_6 ( V_27 , V_19 ) ;
if ( ( V_27 + V_18 ) > V_28 )
continue;
V_5 = F_8 ( V_9 -> V_10 -> V_34 ,
V_35 , V_12 ,
V_22 , & V_27 ) ;
if ( V_5 == V_13 ) {
* V_20 = V_27 ;
break;
}
}
if ( V_24 == V_2 / V_3 )
V_5 = V_33 ;
V_17:
F_4 ( V_9 -> V_10 -> V_17 , V_1 ) ;
V_14:
return V_5 ;
}
static void F_10 ( unsigned long V_18 , unsigned long V_20 )
{
unsigned long V_22 ;
V_22 = F_6 ( V_18 , V_25 ) / V_25 ;
F_11 ( V_9 -> V_10 -> V_36 , V_20 , V_18 ) ;
}
static void F_12 ( unsigned long V_37 , T_5 * V_38 , T_5 * V_18 )
{
T_5 V_39 , V_40 ;
V_39 = 0 ;
V_40 = 0 ;
if ( V_37 ) {
while ( ! ( V_37 & 0x1 ) ) {
V_37 = V_37 >> 1 ;
V_39 ++ ;
}
while ( V_37 & 0x1 ) {
V_37 = V_37 >> 1 ;
V_40 ++ ;
}
}
* V_38 = V_39 ;
* V_18 = V_40 ;
}
static T_1 F_13 ( struct V_41 * V_42 , T_6 * V_43 ,
unsigned long V_18 )
{
struct V_44 * V_45 , * V_46 ;
struct V_47 V_48 ;
unsigned long V_49 ;
T_1 V_5 ;
void * * V_50 ;
T_7 V_51 , V_52 ;
T_3 V_53 , V_54 ;
T_3 V_55 ;
int V_56 ;
int V_24 ;
V_5 = F_2 ( V_9 -> V_10 -> V_11 ,
V_12 , V_18 , & V_50 ) ;
if ( V_5 != V_13 )
return V_5 ;
V_5 = F_3 ( V_9 -> V_10 -> V_57 ,
V_58 , V_43 ,
NULL , & V_18 , V_50 ) ;
if ( V_5 != V_13 )
goto V_59;
V_46 = NULL ;
V_49 = V_18 / sizeof( void * ) ;
for ( V_24 = 0 ; V_24 < V_49 ; V_24 ++ ) {
struct V_60 * V_61 ;
T_6 V_62 = V_63 ;
void * V_64 ;
void * V_65 = V_50 [ V_24 ] ;
V_5 = F_2 ( V_9 -> V_10 -> V_66 ,
V_65 , V_43 , & V_45 ) ;
if ( V_5 != V_13 )
continue;
F_2 ( V_9 -> V_10 -> V_66 ,
V_65 , & V_62 , & V_64 ) ;
V_5 = F_8 ( V_45 -> V_67 , V_45 ,
V_45 -> V_68 -> V_68 , & V_18 , & V_61 ) ;
if ( V_5 == V_13 && ( ! V_46 || V_64 ) ) {
V_51 = V_61 -> V_69 ;
V_52 = V_61 -> V_70 ;
V_53 = V_45 -> V_68 -> V_71 ;
V_54 = V_45 -> V_68 -> V_72 ;
V_56 = V_61 -> V_56 ;
V_48 = V_61 -> V_73 ;
V_55 = V_61 -> V_55 ;
if ( V_64 )
break;
V_46 = V_45 ;
}
}
if ( ! V_46 )
goto V_59;
V_42 -> V_74 = V_75 ;
V_42 -> V_76 = V_51 ;
V_42 -> V_77 = V_52 ;
V_42 -> V_78 = V_53 ;
V_42 -> V_79 = V_54 ;
V_42 -> V_80 = 1 ;
if ( V_56 == V_81 ) {
V_42 -> V_82 = 32 ;
V_42 -> V_83 = V_55 * 4 ;
V_42 -> V_84 = 8 ;
V_42 -> V_85 = 0 ;
V_42 -> V_86 = 8 ;
V_42 -> V_87 = 8 ;
V_42 -> V_88 = 8 ;
V_42 -> V_89 = 16 ;
V_42 -> V_90 = 8 ;
V_42 -> V_91 = 24 ;
} else if ( V_56 == V_92 ) {
V_42 -> V_82 = 32 ;
V_42 -> V_83 = V_55 * 4 ;
V_42 -> V_84 = 8 ;
V_42 -> V_85 = 16 ;
V_42 -> V_86 = 8 ;
V_42 -> V_87 = 8 ;
V_42 -> V_88 = 8 ;
V_42 -> V_89 = 0 ;
V_42 -> V_90 = 8 ;
V_42 -> V_91 = 24 ;
} else if ( V_56 == V_93 ) {
F_12 ( V_48 . V_94 , & V_42 -> V_85 , & V_42 -> V_84 ) ;
F_12 ( V_48 . V_95 , & V_42 -> V_87 ,
& V_42 -> V_86 ) ;
F_12 ( V_48 . V_96 , & V_42 -> V_89 , & V_42 -> V_88 ) ;
F_12 ( V_48 . V_97 , & V_42 -> V_91 ,
& V_42 -> V_90 ) ;
V_42 -> V_82 = V_42 -> V_84 + V_42 -> V_86 +
V_42 -> V_88 + V_42 -> V_90 ;
V_42 -> V_83 = ( V_55 * V_42 -> V_82 ) / 8 ;
} else {
V_42 -> V_82 = 4 ;
V_42 -> V_83 = V_42 -> V_76 / 2 ;
V_42 -> V_84 = 0 ;
V_42 -> V_85 = 0 ;
V_42 -> V_86 = 0 ;
V_42 -> V_87 = 0 ;
V_42 -> V_88 = 0 ;
V_42 -> V_89 = 0 ;
V_42 -> V_90 = 0 ;
V_42 -> V_91 = 0 ;
}
V_59:
F_4 ( V_9 -> V_10 -> V_17 , V_50 ) ;
return V_5 ;
}
static T_1 F_14 ( struct V_41 * V_42 , T_6 * V_98 ,
unsigned long V_18 )
{
struct V_99 * V_100 , * V_101 ;
unsigned long V_102 ;
T_1 V_5 ;
T_3 V_51 , V_52 ;
void * * V_103 = NULL ;
int V_24 ;
V_5 = F_2 ( V_9 -> V_10 -> V_11 ,
V_12 , V_18 , & V_103 ) ;
if ( V_5 != V_13 )
return V_5 ;
V_5 = F_3 ( V_9 -> V_10 -> V_57 ,
V_58 , V_98 ,
NULL , & V_18 , V_103 ) ;
if ( V_5 != V_13 )
goto V_59;
V_101 = NULL ;
V_102 = V_18 / sizeof( void * ) ;
for ( V_24 = 0 ; V_24 < V_102 ; V_24 ++ ) {
T_6 V_62 = V_63 ;
void * V_104 = V_103 [ V_24 ] ;
T_3 V_105 , V_65 , V_106 , V_107 ;
void * V_64 ;
V_5 = F_2 ( V_9 -> V_10 -> V_66 ,
V_104 , V_98 , & V_100 ) ;
if ( V_5 != V_13 )
continue;
F_2 ( V_9 -> V_10 -> V_66 ,
V_104 , & V_62 , & V_64 ) ;
V_5 = F_3 ( V_100 -> V_108 , V_100 , & V_105 , & V_65 ,
& V_106 , & V_107 ) ;
if ( V_5 == V_13 && ( ! V_101 || V_64 ) ) {
V_51 = V_105 ;
V_52 = V_65 ;
if ( V_64 )
break;
V_101 = V_100 ;
}
}
if ( ! V_101 )
goto V_59;
V_42 -> V_74 = V_75 ;
V_42 -> V_82 = 32 ;
V_42 -> V_76 = V_51 ;
V_42 -> V_77 = V_52 ;
V_42 -> V_84 = 8 ;
V_42 -> V_85 = 16 ;
V_42 -> V_86 = 8 ;
V_42 -> V_87 = 8 ;
V_42 -> V_88 = 8 ;
V_42 -> V_89 = 0 ;
V_42 -> V_90 = 8 ;
V_42 -> V_91 = 24 ;
V_59:
F_4 ( V_9 -> V_10 -> V_17 , V_103 ) ;
return V_5 ;
}
void F_15 ( struct V_109 * V_109 )
{
T_6 V_110 = V_111 ;
struct V_41 * V_42 ;
T_6 V_98 = V_112 ;
T_1 V_5 ;
unsigned long V_18 ;
void * * V_50 = NULL ;
void * * V_103 = NULL ;
V_42 = & V_109 -> V_41 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_18 = 0 ;
V_5 = F_3 ( V_9 -> V_10 -> V_57 ,
V_58 , & V_110 ,
NULL , & V_18 , V_50 ) ;
if ( V_5 == V_16 )
V_5 = F_13 ( V_42 , & V_110 , V_18 ) ;
if ( V_5 != V_13 ) {
V_18 = 0 ;
V_5 = F_3 ( V_9 -> V_10 -> V_57 ,
V_58 , & V_98 ,
NULL , & V_18 , V_103 ) ;
if ( V_5 == V_16 )
F_14 ( V_42 , & V_98 , V_18 ) ;
}
}
static T_1 F_16 ( T_8 * V_113 ,
struct V_114 * V_115 )
{
struct V_116 * V_117 ;
unsigned long V_118 ;
T_6 V_119 = V_120 ;
T_4 V_121 ;
T_9 * V_122 ;
T_10 * V_123 ;
T_1 V_5 ;
int V_124 ;
char * V_125 ;
int V_24 , V_126 , V_127 ;
V_118 = 0 ;
V_121 = 0 ;
V_125 = ( char * ) ( unsigned long ) V_115 -> V_128 ;
V_126 = 0 ;
if ( ! V_125 || ! * V_125 )
return V_13 ;
for ( V_124 = 0 ; * V_125 ; V_124 ++ ) {
V_125 = strstr ( V_125 , L_1 ) ;
if ( ! V_125 )
break;
V_125 += 7 ;
while ( * V_125 == '/' || * V_125 == '\\' )
V_125 ++ ;
while ( * V_125 && * V_125 != ' ' && * V_125 != '\n' )
V_125 ++ ;
}
if ( ! V_124 )
return V_13 ;
V_5 = F_2 ( V_9 -> V_10 -> V_11 ,
V_12 ,
V_124 * sizeof( * V_117 ) ,
& V_117 ) ;
if ( V_5 != V_13 )
goto V_14;
V_125 = ( char * ) ( unsigned long ) V_115 -> V_128 ;
for ( V_24 = 0 ; V_24 < V_124 ; V_24 ++ ) {
struct V_116 * V_116 ;
T_10 * V_65 ;
T_11 * V_61 ;
T_12 V_129 [ 256 ] ;
unsigned long V_130 ;
T_6 V_131 = V_132 ;
T_12 * V_133 ;
T_4 V_134 ;
V_125 = strstr ( V_125 , L_1 ) ;
if ( ! V_125 )
break;
V_125 += 7 ;
V_116 = & V_117 [ V_24 ] ;
V_133 = V_129 ;
while ( * V_125 == '/' || * V_125 == '\\' )
V_125 ++ ;
while ( * V_125 && * V_125 != ' ' && * V_125 != '\n' ) {
if ( V_133 >= V_129 + sizeof( V_129 ) )
break;
* V_133 ++ = * V_125 ++ ;
}
* V_133 = '\0' ;
if ( ! V_24 ) {
T_13 * V_10 ;
V_10 = V_9 -> V_10 ;
V_5 = F_2 ( V_10 -> V_66 ,
V_113 -> V_135 , & V_119 , & V_122 ) ;
if ( V_5 != V_13 )
goto V_136;
V_5 = F_11 ( V_122 -> V_137 , V_122 , & V_123 ) ;
if ( V_5 != V_13 )
goto V_136;
}
V_5 = F_3 ( V_123 -> V_138 , V_123 , & V_65 , V_129 ,
V_139 , ( T_4 ) 0 ) ;
if ( V_5 != V_13 )
goto V_140;
V_116 -> V_104 = V_65 ;
V_130 = 0 ;
V_5 = F_8 ( V_65 -> V_141 , V_65 , & V_131 ,
& V_130 , NULL ) ;
if ( V_5 != V_16 )
goto V_140;
V_142:
V_5 = F_2 ( V_9 -> V_10 -> V_11 ,
V_12 , V_130 , & V_61 ) ;
if ( V_5 != V_13 )
goto V_140;
V_5 = F_8 ( V_65 -> V_141 , V_65 , & V_131 ,
& V_130 , V_61 ) ;
if ( V_5 == V_16 ) {
F_4 ( V_9 -> V_10 -> V_17 , V_61 ) ;
goto V_142;
}
V_134 = V_61 -> V_143 ;
F_4 ( V_9 -> V_10 -> V_17 , V_61 ) ;
if ( V_5 != V_13 )
goto V_140;
V_116 -> V_18 = V_134 ;
V_121 += V_134 ;
}
if ( V_121 ) {
unsigned long V_20 ;
V_5 = F_5 ( V_121 , 0x1000 ,
& V_118 , V_115 -> V_144 ) ;
if ( V_5 != V_13 )
goto V_140;
if ( V_118 > V_115 -> V_144 ) {
V_5 = V_145 ;
goto V_146;
}
V_20 = V_118 ;
for ( V_126 = 0 ; V_126 < V_124 ; V_126 ++ ) {
T_4 V_18 ;
V_18 = V_117 [ V_126 ] . V_18 ;
while ( V_18 ) {
T_4 V_147 ;
if ( V_18 > V_148 )
V_147 = V_148 ;
else
V_147 = V_18 ;
V_5 = F_2 ( V_123 -> V_149 ,
V_117 [ V_126 ] . V_104 ,
& V_147 , V_20 ) ;
if ( V_5 != V_13 )
goto V_146;
V_20 += V_147 ;
V_18 -= V_147 ;
}
F_4 ( V_123 -> V_150 , V_117 [ V_126 ] . V_104 ) ;
}
}
F_4 ( V_9 -> V_10 -> V_17 , V_117 ) ;
V_115 -> V_151 = V_118 ;
V_115 -> V_152 = V_121 ;
return V_5 ;
V_146:
F_10 ( V_121 , V_118 ) ;
V_140:
for ( V_127 = V_126 ; V_127 < V_124 ; V_127 ++ )
F_4 ( V_123 -> V_150 , V_117 [ V_127 ] . V_104 ) ;
V_136:
F_4 ( V_9 -> V_10 -> V_17 , V_117 ) ;
V_14:
V_115 -> V_151 = 0 ;
V_115 -> V_152 = 0 ;
return V_5 ;
}
static T_1 F_17 ( struct V_109 * V_109 ,
T_8 * V_113 ,
void * V_104 )
{
struct V_153 * V_154 = & V_109 -> V_153 ;
struct V_155 * V_156 = & V_109 -> V_155 ;
struct V_157 * V_158 = & V_109 -> V_157 ;
struct V_159 * V_160 = & V_109 -> V_160 [ 0 ] ;
struct V_159 * V_161 = NULL ;
struct V_114 * V_115 = & V_109 -> V_115 ;
unsigned long V_18 , V_6 , V_3 , V_162 ;
T_2 * V_163 ;
void * V_164 = V_113 -> V_165 ;
T_3 V_166 = V_113 -> V_166 / 2 ;
int V_167 = 0 ;
T_1 V_5 ;
T_14 V_7 ;
unsigned long V_168 ;
T_5 V_169 ;
T_7 * V_170 ;
T_5 * V_171 ;
int V_24 ;
V_115 -> V_172 = 0x21 ;
V_168 = 0 ;
V_170 = ( T_7 * ) V_164 ;
if ( V_170 ) {
while ( * V_170 && * V_170 != '\n' && V_167 < V_166 ) {
V_170 ++ ;
V_167 ++ ;
}
if ( V_167 ) {
if ( V_167 > V_115 -> V_173 )
V_167 = V_115 -> V_173 ;
V_167 ++ ;
V_5 = F_9 ( V_167 , 1 , & V_168 ) ;
if ( V_5 != V_13 )
goto V_14;
V_171 = ( T_5 * ) ( unsigned long ) V_168 ;
V_170 = ( T_7 * ) V_164 ;
for ( V_24 = 0 ; V_24 < V_167 - 1 ; V_24 ++ )
* V_171 ++ = * V_170 ++ ;
* V_171 = '\0' ;
}
}
V_115 -> V_128 = V_168 ;
V_115 -> V_151 = 0 ;
V_115 -> V_152 = 0 ;
V_5 = F_16 ( V_113 , V_115 ) ;
if ( V_5 != V_13 )
goto V_174;
F_15 ( V_109 ) ;
memset ( V_156 , 0 , sizeof( * V_156 ) ) ;
memset ( V_158 , 0 , sizeof( * V_158 ) ) ;
memcpy ( & V_154 -> V_175 , V_176 , sizeof( T_14 ) ) ;
V_18 = sizeof( * V_163 ) * 32 ;
V_8:
V_18 += sizeof( * V_163 ) ;
V_162 = V_18 ;
V_5 = F_9 ( V_18 , 1 , ( unsigned long * ) & V_163 ) ;
if ( V_5 != V_13 )
goto V_174;
V_5 = F_3 ( V_9 -> V_10 -> V_15 , & V_18 ,
V_163 , & V_6 , & V_3 , & V_7 ) ;
if ( V_5 == V_16 ) {
F_10 ( V_162 , ( unsigned long ) V_163 ) ;
goto V_8;
}
if ( V_5 != V_13 )
goto V_177;
V_154 -> V_178 = ( unsigned long ) V_9 ;
V_154 -> V_179 = V_3 ;
V_154 -> V_180 = V_7 ;
V_154 -> V_181 = ( unsigned long ) V_163 ;
V_154 -> V_182 = V_18 ;
#ifdef F_18
V_154 -> V_183 = ( unsigned long ) V_9 >> 32 ;
V_154 -> V_184 = ( unsigned long ) V_163 >> 32 ;
#endif
V_5 = F_11 ( V_9 -> V_10 -> V_185 ,
V_104 , V_6 ) ;
if ( V_5 != V_13 )
goto V_177;
V_109 -> V_186 = 32 * 1024 ;
V_169 = 0 ;
for ( V_24 = 0 ; V_24 < V_18 / V_3 ; V_24 ++ ) {
T_2 * V_187 ;
unsigned int V_188 = 0 ;
unsigned long V_4 = ( unsigned long ) V_163 ;
V_187 = ( T_2 * ) ( V_4 + ( V_24 * V_3 ) ) ;
switch ( V_187 -> type ) {
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
V_188 = V_195 ;
break;
case V_196 :
V_188 = V_197 ;
break;
case V_198 :
V_188 = V_199 ;
break;
case V_200 :
case V_12 :
case V_201 :
case V_202 :
case V_29 :
V_188 = V_203 ;
break;
case V_204 :
V_188 = V_205 ;
break;
default:
continue;
}
if ( V_161 && V_161 -> type == V_188 &&
( V_161 -> V_20 + V_161 -> V_18 ) == V_187 -> V_31 )
V_161 -> V_18 += V_187 -> V_30 << 12 ;
else {
V_160 -> V_20 = V_187 -> V_31 ;
V_160 -> V_18 = V_187 -> V_30 << 12 ;
V_160 -> type = V_188 ;
V_161 = V_160 ++ ;
V_169 ++ ;
}
}
V_109 -> V_206 = V_169 ;
return V_13 ;
V_177:
F_10 ( V_162 , ( unsigned long ) V_163 ) ;
V_174:
if ( V_167 )
F_10 ( V_167 , V_115 -> V_128 ) ;
V_14:
return V_5 ;
}
struct V_109 * F_19 ( void * V_104 , T_15 * V_207 )
{
struct V_109 * V_109 ;
unsigned long V_27 , V_22 ;
struct V_208 * V_209 , * V_210 ;
T_8 * V_113 ;
struct V_114 * V_115 ;
T_1 V_5 ;
T_6 V_43 = V_211 ;
struct V_212 * V_26 ;
V_9 = V_207 ;
if ( V_9 -> V_115 . V_213 != V_214 )
goto V_14;
V_5 = F_2 ( V_9 -> V_10 -> V_66 ,
V_104 , & V_43 , ( void * ) & V_113 ) ;
if ( V_5 != V_13 )
goto V_14;
V_5 = F_9 ( 0x4000 , 1 , ( unsigned long * ) & V_109 ) ;
if ( V_5 != V_13 )
goto V_14;
memset ( V_109 , 0x0 , 0x4000 ) ;
memcpy ( V_109 , V_113 -> V_215 , 1024 ) ;
V_115 = & V_109 -> V_115 ;
V_27 = V_115 -> V_216 ;
V_22 = F_6 ( V_115 -> V_217 , V_25 ) / V_25 ;
V_5 = F_8 ( V_9 -> V_10 -> V_34 ,
V_35 , V_12 ,
V_22 , & V_27 ) ;
if ( V_5 != V_13 ) {
V_5 = F_9 ( V_115 -> V_217 , V_115 -> V_218 ,
& V_27 ) ;
if ( V_5 != V_13 )
goto V_14;
}
V_115 -> V_219 = ( T_14 ) V_27 ;
V_115 -> V_216 = ( V_220 ) ( unsigned long ) V_113 -> V_215 ;
memcpy ( ( void * ) V_27 , V_113 -> V_215 , V_113 -> V_221 ) ;
V_5 = F_2 ( V_9 -> V_10 -> V_11 ,
V_12 , sizeof( * V_209 ) ,
( void * * ) & V_209 ) ;
if ( V_5 != V_13 )
goto V_14;
V_209 -> V_18 = 0x800 ;
V_5 = F_9 ( V_209 -> V_18 , 8 , ( unsigned long * ) & V_209 -> V_222 ) ;
if ( V_5 != V_13 )
goto V_14;
V_5 = F_2 ( V_9 -> V_10 -> V_11 ,
V_12 , sizeof( * V_210 ) ,
( void * * ) & V_210 ) ;
if ( V_5 != V_13 )
goto V_14;
V_210 -> V_18 = 0 ;
V_210 -> V_222 = 0 ;
V_5 = F_17 ( V_109 , V_113 , V_104 ) ;
if ( V_5 != V_13 )
goto V_14;
memset ( ( char * ) V_209 -> V_222 , 0x0 , V_209 -> V_18 ) ;
V_26 = (struct V_212 * ) V_209 -> V_222 ;
V_26 += 2 ;
V_26 -> V_223 = 0xffff ;
V_26 -> V_224 = 0x0000 ;
V_26 -> V_225 = 0x0000 ;
V_26 -> type = V_226 | V_227 ;
V_26 -> V_228 = V_229 ;
V_26 -> V_230 = 0 ;
V_26 -> V_133 = 1 ;
V_26 -> V_231 = 0xf ;
V_26 -> V_232 = 0 ;
V_26 -> V_233 = 0 ;
V_26 -> V_187 = V_234 ;
V_26 -> V_235 = V_236 ;
V_26 -> V_237 = 0x00 ;
V_26 ++ ;
V_26 -> V_223 = 0xffff ;
V_26 -> V_224 = 0x0000 ;
V_26 -> V_225 = 0x0000 ;
V_26 -> type = V_238 | V_239 ;
V_26 -> V_228 = V_229 ;
V_26 -> V_230 = 0 ;
V_26 -> V_133 = 1 ;
V_26 -> V_231 = 0xf ;
V_26 -> V_232 = 0 ;
V_26 -> V_233 = 0 ;
V_26 -> V_187 = V_234 ;
V_26 -> V_235 = V_236 ;
V_26 -> V_237 = 0x00 ;
#ifdef F_18
V_26 ++ ;
V_26 -> V_223 = 0x0000 ;
V_26 -> V_224 = 0x0000 ;
V_26 -> V_225 = 0x0000 ;
V_26 -> type = V_240 ;
V_26 -> V_228 = 0 ;
V_26 -> V_230 = 0 ;
V_26 -> V_133 = 1 ;
V_26 -> V_231 = 0x0 ;
V_26 -> V_232 = 0 ;
V_26 -> V_233 = 0 ;
V_26 -> V_187 = 0 ;
V_26 -> V_235 = V_236 ;
V_26 -> V_237 = 0x00 ;
#endif
asm volatile ("lidt %0" : : "m" (*idt));
asm volatile ("lgdt %0" : : "m" (*gdt));
asm volatile("cli");
return V_109 ;
V_14:
return NULL ;
}
