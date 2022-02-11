static void F_1 ( char * V_1 )
{
char * V_2 ;
for ( V_2 = V_1 ; * V_2 ; V_2 ++ ) {
struct V_3 * V_4 ;
T_1 V_5 [ 2 ] = { 0 } ;
V_5 [ 0 ] = * V_2 ;
V_4 = (struct V_3 * ) V_6 -> V_7 ;
if ( * V_2 == '\n' ) {
T_1 V_8 [ 2 ] = { '\r' , 0 } ;
F_2 ( V_4 -> V_9 , V_4 , V_8 ) ;
}
F_2 ( V_4 -> V_9 , V_4 , V_5 ) ;
}
}
static T_2 F_3 ( T_3 * * V_10 , unsigned long * V_11 ,
unsigned long * V_12 )
{
T_3 * V_13 = NULL ;
T_2 V_14 ;
unsigned long V_15 ;
T_4 V_16 ;
* V_11 = sizeof( * V_13 ) * 32 ;
V_17:
* V_11 += sizeof( * V_13 ) ;
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 , * V_11 , ( void * * ) & V_13 ) ;
if ( V_14 != V_21 )
goto V_22;
V_14 = F_5 ( V_6 -> V_18 -> V_23 , V_11 ,
V_13 , & V_15 , V_12 , & V_16 ) ;
if ( V_14 == V_24 ) {
F_6 ( V_6 -> V_18 -> V_25 , V_13 ) ;
goto V_17;
}
if ( V_14 != V_21 )
F_6 ( V_6 -> V_18 -> V_25 , V_13 ) ;
V_22:
* V_10 = V_13 ;
return V_14 ;
}
static T_2 F_7 ( unsigned long V_26 , unsigned long V_27 ,
unsigned long * V_28 , unsigned long V_29 )
{
unsigned long V_11 , V_12 ;
T_3 * V_10 ;
T_2 V_14 ;
unsigned long V_30 ;
T_5 V_31 = 0 ;
int V_32 ;
V_14 = F_3 ( & V_10 , & V_11 , & V_12 ) ;
if ( V_14 != V_21 )
goto V_22;
V_30 = F_8 ( V_26 , V_33 ) / V_33 ;
V_17:
for ( V_32 = 0 ; V_32 < V_11 / V_12 ; V_32 ++ ) {
T_3 * V_34 ;
unsigned long V_13 = ( unsigned long ) V_10 ;
T_5 V_35 , V_36 ;
V_34 = ( T_3 * ) ( V_13 + ( V_32 * V_12 ) ) ;
if ( V_34 -> type != V_37 )
continue;
if ( V_34 -> V_38 < V_30 )
continue;
V_35 = V_34 -> V_39 ;
V_36 = V_35 + V_34 -> V_38 * ( 1UL << V_40 ) ;
if ( ( V_35 + V_26 ) > V_36 || ( V_35 + V_26 ) > V_29 )
continue;
if ( V_36 - V_26 > V_29 )
V_36 = V_29 ;
if ( F_9 ( V_36 - V_26 , V_27 ) < V_35 )
continue;
V_35 = F_9 ( V_36 - V_26 , V_27 ) ;
if ( V_35 == 0x0 )
continue;
if ( V_35 > V_31 )
V_31 = V_35 ;
}
if ( ! V_31 )
V_14 = V_41 ;
else {
V_14 = F_10 ( V_6 -> V_18 -> V_42 ,
V_43 , V_20 ,
V_30 , & V_31 ) ;
if ( V_14 != V_21 ) {
V_29 = V_31 ;
V_31 = 0 ;
goto V_17;
}
* V_28 = V_31 ;
}
V_25:
F_6 ( V_6 -> V_18 -> V_25 , V_10 ) ;
V_22:
return V_14 ;
}
static T_2 F_11 ( unsigned long V_26 , unsigned long V_27 ,
unsigned long * V_28 )
{
unsigned long V_11 , V_12 ;
T_3 * V_10 ;
T_2 V_14 ;
unsigned long V_30 ;
int V_32 ;
V_14 = F_3 ( & V_10 , & V_11 , & V_12 ) ;
if ( V_14 != V_21 )
goto V_22;
V_30 = F_8 ( V_26 , V_33 ) / V_33 ;
for ( V_32 = 0 ; V_32 < V_11 / V_12 ; V_32 ++ ) {
T_3 * V_34 ;
unsigned long V_13 = ( unsigned long ) V_10 ;
T_5 V_35 , V_36 ;
V_34 = ( T_3 * ) ( V_13 + ( V_32 * V_12 ) ) ;
if ( V_34 -> type != V_37 )
continue;
if ( V_34 -> V_38 < V_30 )
continue;
V_35 = V_34 -> V_39 ;
V_36 = V_35 + V_34 -> V_38 * ( 1UL << V_40 ) ;
if ( V_35 == 0x0 )
V_35 += 8 ;
V_35 = F_8 ( V_35 , V_27 ) ;
if ( ( V_35 + V_26 ) > V_36 )
continue;
V_14 = F_10 ( V_6 -> V_18 -> V_42 ,
V_43 , V_20 ,
V_30 , & V_35 ) ;
if ( V_14 == V_21 ) {
* V_28 = V_35 ;
break;
}
}
if ( V_32 == V_11 / V_12 )
V_14 = V_41 ;
V_25:
F_6 ( V_6 -> V_18 -> V_25 , V_10 ) ;
V_22:
return V_14 ;
}
static void F_12 ( unsigned long V_26 , unsigned long V_28 )
{
unsigned long V_30 ;
V_30 = F_8 ( V_26 , V_33 ) / V_33 ;
F_2 ( V_6 -> V_18 -> V_44 , V_28 , V_26 ) ;
}
static void F_13 ( unsigned long V_45 , T_6 * V_46 , T_6 * V_26 )
{
T_6 V_47 , V_48 ;
V_47 = 0 ;
V_48 = 0 ;
if ( V_45 ) {
while ( ! ( V_45 & 0x1 ) ) {
V_45 = V_45 >> 1 ;
V_47 ++ ;
}
while ( V_45 & 0x1 ) {
V_45 = V_45 >> 1 ;
V_48 ++ ;
}
}
* V_46 = V_47 ;
* V_26 = V_48 ;
}
static T_2 F_14 ( struct V_49 * V_50 , T_7 * V_51 ,
unsigned long V_26 )
{
struct V_52 * V_53 , * V_54 ;
struct V_55 V_56 ;
unsigned long V_57 ;
T_2 V_14 ;
void * * V_58 ;
T_8 V_59 , V_60 ;
T_4 V_61 , V_62 ;
T_4 V_63 ;
int V_64 ;
int V_32 ;
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 , V_26 , & V_58 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_14 = F_5 ( V_6 -> V_18 -> V_65 ,
V_66 , V_51 ,
NULL , & V_26 , V_58 ) ;
if ( V_14 != V_21 )
goto V_67;
V_54 = NULL ;
V_57 = V_26 / sizeof( void * ) ;
for ( V_32 = 0 ; V_32 < V_57 ; V_32 ++ ) {
struct V_68 * V_69 ;
T_7 V_70 = V_71 ;
bool V_72 = false ;
void * V_73 ;
void * V_74 = V_58 [ V_32 ] ;
V_14 = F_4 ( V_6 -> V_18 -> V_75 ,
V_74 , V_51 , & V_53 ) ;
if ( V_14 != V_21 )
continue;
V_14 = F_4 ( V_6 -> V_18 -> V_75 ,
V_74 , & V_70 , & V_73 ) ;
if ( V_14 == V_21 )
V_72 = true ;
V_14 = F_10 ( V_53 -> V_76 , V_53 ,
V_53 -> V_77 -> V_77 , & V_26 , & V_69 ) ;
if ( V_14 == V_21 && ( ! V_54 || V_72 ) ) {
V_59 = V_69 -> V_78 ;
V_60 = V_69 -> V_79 ;
V_61 = V_53 -> V_77 -> V_80 ;
V_62 = V_53 -> V_77 -> V_81 ;
V_64 = V_69 -> V_64 ;
V_56 = V_69 -> V_82 ;
V_63 = V_69 -> V_63 ;
if ( V_72 )
break;
V_54 = V_53 ;
}
}
if ( ! V_54 )
goto V_67;
V_50 -> V_83 = V_84 ;
V_50 -> V_85 = V_59 ;
V_50 -> V_86 = V_60 ;
V_50 -> V_87 = V_61 ;
V_50 -> V_88 = 1 ;
if ( V_64 == V_89 ) {
V_50 -> V_90 = 32 ;
V_50 -> V_91 = V_63 * 4 ;
V_50 -> V_92 = 8 ;
V_50 -> V_93 = 0 ;
V_50 -> V_94 = 8 ;
V_50 -> V_95 = 8 ;
V_50 -> V_96 = 8 ;
V_50 -> V_97 = 16 ;
V_50 -> V_98 = 8 ;
V_50 -> V_99 = 24 ;
} else if ( V_64 == V_100 ) {
V_50 -> V_90 = 32 ;
V_50 -> V_91 = V_63 * 4 ;
V_50 -> V_92 = 8 ;
V_50 -> V_93 = 16 ;
V_50 -> V_94 = 8 ;
V_50 -> V_95 = 8 ;
V_50 -> V_96 = 8 ;
V_50 -> V_97 = 0 ;
V_50 -> V_98 = 8 ;
V_50 -> V_99 = 24 ;
} else if ( V_64 == V_101 ) {
F_13 ( V_56 . V_102 , & V_50 -> V_93 , & V_50 -> V_92 ) ;
F_13 ( V_56 . V_103 , & V_50 -> V_95 ,
& V_50 -> V_94 ) ;
F_13 ( V_56 . V_104 , & V_50 -> V_97 , & V_50 -> V_96 ) ;
F_13 ( V_56 . V_105 , & V_50 -> V_99 ,
& V_50 -> V_98 ) ;
V_50 -> V_90 = V_50 -> V_92 + V_50 -> V_94 +
V_50 -> V_96 + V_50 -> V_98 ;
V_50 -> V_91 = ( V_63 * V_50 -> V_90 ) / 8 ;
} else {
V_50 -> V_90 = 4 ;
V_50 -> V_91 = V_50 -> V_85 / 2 ;
V_50 -> V_92 = 0 ;
V_50 -> V_93 = 0 ;
V_50 -> V_94 = 0 ;
V_50 -> V_95 = 0 ;
V_50 -> V_96 = 0 ;
V_50 -> V_97 = 0 ;
V_50 -> V_98 = 0 ;
V_50 -> V_99 = 0 ;
}
V_50 -> V_106 = V_50 -> V_91 * V_50 -> V_86 ;
V_50 -> V_107 |= V_108 ;
V_67:
F_6 ( V_6 -> V_18 -> V_25 , V_58 ) ;
return V_14 ;
}
static T_2 F_15 ( struct V_49 * V_50 , T_7 * V_109 ,
unsigned long V_26 )
{
struct V_110 * V_111 , * V_112 ;
unsigned long V_113 ;
T_2 V_14 ;
T_4 V_59 , V_60 ;
void * * V_114 = NULL ;
int V_32 ;
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 , V_26 , & V_114 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_14 = F_5 ( V_6 -> V_18 -> V_65 ,
V_66 , V_109 ,
NULL , & V_26 , V_114 ) ;
if ( V_14 != V_21 )
goto V_67;
V_112 = NULL ;
V_113 = V_26 / sizeof( void * ) ;
for ( V_32 = 0 ; V_32 < V_113 ; V_32 ++ ) {
T_7 V_115 = V_116 ;
void * V_117 = V_114 [ V_32 ] ;
T_4 V_118 , V_74 , V_119 , V_120 ;
void * V_121 ;
V_14 = F_4 ( V_6 -> V_18 -> V_75 ,
V_117 , V_109 , & V_111 ) ;
if ( V_14 != V_21 )
continue;
F_4 ( V_6 -> V_18 -> V_75 ,
V_117 , & V_115 , & V_121 ) ;
V_14 = F_5 ( V_111 -> V_122 , V_111 , & V_118 , & V_74 ,
& V_119 , & V_120 ) ;
if ( V_14 == V_21 && ( ! V_112 || V_121 ) ) {
V_59 = V_118 ;
V_60 = V_74 ;
if ( V_121 )
break;
V_112 = V_111 ;
}
}
if ( ! V_112 )
goto V_67;
V_50 -> V_83 = V_84 ;
V_50 -> V_90 = 32 ;
V_50 -> V_85 = V_59 ;
V_50 -> V_86 = V_60 ;
V_50 -> V_92 = 8 ;
V_50 -> V_93 = 16 ;
V_50 -> V_94 = 8 ;
V_50 -> V_95 = 8 ;
V_50 -> V_96 = 8 ;
V_50 -> V_97 = 0 ;
V_50 -> V_98 = 8 ;
V_50 -> V_99 = 24 ;
V_67:
F_6 ( V_6 -> V_18 -> V_25 , V_114 ) ;
return V_14 ;
}
void F_16 ( struct V_123 * V_123 )
{
T_7 V_124 = V_125 ;
struct V_49 * V_50 ;
T_7 V_109 = V_126 ;
T_2 V_14 ;
unsigned long V_26 ;
void * * V_58 = NULL ;
void * * V_114 = NULL ;
V_50 = & V_123 -> V_49 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_26 = 0 ;
V_14 = F_5 ( V_6 -> V_18 -> V_65 ,
V_66 , & V_124 ,
NULL , & V_26 , V_58 ) ;
if ( V_14 == V_24 )
V_14 = F_14 ( V_50 , & V_124 , V_26 ) ;
if ( V_14 != V_21 ) {
V_26 = 0 ;
V_14 = F_5 ( V_6 -> V_18 -> V_65 ,
V_66 , & V_109 ,
NULL , & V_26 , V_114 ) ;
if ( V_14 == V_24 )
F_15 ( V_50 , & V_109 , V_26 ) ;
}
}
static T_2 F_17 ( T_9 * V_127 ,
struct V_128 * V_129 )
{
struct V_130 * V_131 ;
unsigned long V_132 ;
T_7 V_133 = V_134 ;
T_5 V_135 ;
T_10 * V_136 ;
T_11 * V_137 ;
T_2 V_14 ;
int V_138 ;
char * V_1 ;
int V_32 , V_139 , V_140 ;
V_132 = 0 ;
V_135 = 0 ;
V_1 = ( char * ) ( unsigned long ) V_129 -> V_141 ;
V_139 = 0 ;
if ( ! V_1 || ! * V_1 )
return V_21 ;
for ( V_138 = 0 ; * V_1 ; V_138 ++ ) {
V_1 = strstr ( V_1 , L_1 ) ;
if ( ! V_1 )
break;
V_1 += 7 ;
while ( * V_1 == '/' || * V_1 == '\\' )
V_1 ++ ;
while ( * V_1 && * V_1 != ' ' && * V_1 != '\n' )
V_1 ++ ;
}
if ( ! V_138 )
return V_21 ;
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 ,
V_138 * sizeof( * V_131 ) ,
& V_131 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_2 ) ;
goto V_22;
}
V_1 = ( char * ) ( unsigned long ) V_129 -> V_141 ;
for ( V_32 = 0 ; V_32 < V_138 ; V_32 ++ ) {
struct V_130 * V_130 ;
T_11 * V_74 ;
T_12 * V_69 ;
T_1 V_142 [ 256 ] ;
unsigned long V_143 ;
T_7 V_144 = V_145 ;
T_1 * V_146 ;
T_5 V_147 ;
V_1 = strstr ( V_1 , L_1 ) ;
if ( ! V_1 )
break;
V_1 += 7 ;
V_130 = & V_131 [ V_32 ] ;
V_146 = V_142 ;
while ( * V_1 == '/' || * V_1 == '\\' )
V_1 ++ ;
while ( * V_1 && * V_1 != ' ' && * V_1 != '\n' ) {
if ( ( T_6 * ) V_146 >= ( T_6 * ) V_142 + sizeof( V_142 ) )
break;
* V_146 ++ = * V_1 ++ ;
}
* V_146 = '\0' ;
if ( ! V_32 ) {
T_13 * V_18 ;
V_18 = V_6 -> V_18 ;
V_14 = F_4 ( V_18 -> V_75 ,
V_127 -> V_148 , & V_133 , & V_136 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_3 ) ;
goto V_149;
}
V_14 = F_2 ( V_136 -> V_150 , V_136 , & V_137 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_4 ) ;
goto V_149;
}
}
V_14 = F_5 ( V_137 -> V_151 , V_137 , & V_74 , V_142 ,
V_152 , ( T_5 ) 0 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_5 ) ;
goto V_153;
}
V_130 -> V_117 = V_74 ;
V_143 = 0 ;
V_14 = F_10 ( V_74 -> V_154 , V_74 , & V_144 ,
& V_143 , NULL ) ;
if ( V_14 != V_24 ) {
F_1 ( L_6 ) ;
goto V_153;
}
V_155:
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 , V_143 , & V_69 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_7 ) ;
goto V_153;
}
V_14 = F_10 ( V_74 -> V_154 , V_74 , & V_144 ,
& V_143 , V_69 ) ;
if ( V_14 == V_24 ) {
F_6 ( V_6 -> V_18 -> V_25 , V_69 ) ;
goto V_155;
}
V_147 = V_69 -> V_156 ;
F_6 ( V_6 -> V_18 -> V_25 , V_69 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_8 ) ;
goto V_153;
}
V_130 -> V_26 = V_147 ;
V_135 += V_147 ;
}
if ( V_135 ) {
unsigned long V_28 ;
V_14 = F_7 ( V_135 , 0x1000 ,
& V_132 , V_129 -> V_157 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_9 ) ;
goto V_153;
}
if ( V_132 > V_129 -> V_157 ) {
F_1 ( L_10 ) ;
V_14 = V_158 ;
goto V_159;
}
V_28 = V_132 ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 ++ ) {
T_5 V_26 ;
V_26 = V_131 [ V_139 ] . V_26 ;
while ( V_26 ) {
T_5 V_160 ;
if ( V_26 > V_161 )
V_160 = V_161 ;
else
V_160 = V_26 ;
V_14 = F_4 ( V_137 -> V_162 ,
V_131 [ V_139 ] . V_117 ,
& V_160 , V_28 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_11 ) ;
goto V_159;
}
V_28 += V_160 ;
V_26 -= V_160 ;
}
F_6 ( V_137 -> V_163 , V_131 [ V_139 ] . V_117 ) ;
}
}
F_6 ( V_6 -> V_18 -> V_25 , V_131 ) ;
V_129 -> V_164 = V_132 ;
V_129 -> V_165 = V_135 ;
return V_14 ;
V_159:
F_12 ( V_135 , V_132 ) ;
V_153:
for ( V_140 = V_139 ; V_140 < V_32 ; V_140 ++ )
F_6 ( V_137 -> V_163 , V_131 [ V_140 ] . V_117 ) ;
V_149:
F_6 ( V_6 -> V_18 -> V_25 , V_131 ) ;
V_22:
V_129 -> V_164 = 0 ;
V_129 -> V_165 = 0 ;
return V_14 ;
}
struct V_123 * F_18 ( void * V_117 , T_14 * V_166 )
{
struct V_123 * V_123 ;
struct V_167 * V_168 ;
struct V_169 * V_170 ;
struct V_128 * V_129 ;
struct V_171 * V_172 ;
T_9 * V_127 ;
void * V_173 ;
T_4 V_174 ;
T_7 V_51 = V_175 ;
int V_176 = 0 ;
T_2 V_14 ;
unsigned long V_177 ;
T_8 * V_178 ;
T_6 * V_179 ;
int V_32 ;
V_6 = V_166 ;
if ( V_6 -> V_129 . V_180 != V_181 )
return NULL ;
V_14 = F_4 ( V_6 -> V_18 -> V_75 ,
V_117 , & V_51 , ( void * ) & V_127 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_12 ) ;
return NULL ;
}
V_14 = F_11 ( 0x4000 , 1 , ( unsigned long * ) & V_123 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_13 ) ;
return NULL ;
}
memset ( V_123 , 0x0 , 0x4000 ) ;
V_129 = & V_123 -> V_129 ;
V_172 = & V_123 -> V_171 ;
V_170 = & V_123 -> V_169 ;
V_168 = & V_123 -> V_167 ;
memcpy ( & V_129 -> V_182 , V_127 -> V_183 + 512 , 512 ) ;
V_129 -> V_184 = 1 ;
V_129 -> V_185 = 0xffff ;
V_129 -> V_186 = 0xAA55 ;
V_129 -> V_187 = ( V_188 ) ( unsigned long ) V_127 -> V_183 ;
V_129 -> V_189 = 0x21 ;
V_173 = V_127 -> V_190 ;
V_174 = V_127 -> V_174 / 2 ;
V_177 = 0 ;
V_178 = ( T_8 * ) V_173 ;
if ( V_178 ) {
while ( * V_178 && * V_178 != '\n' && V_176 < V_174 ) {
V_178 ++ ;
V_176 ++ ;
}
if ( V_176 ) {
if ( V_176 > V_129 -> V_191 )
V_176 = V_129 -> V_191 ;
V_176 ++ ;
V_14 = F_11 ( V_176 , 1 , & V_177 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_14 ) ;
goto V_22;
}
V_179 = ( T_6 * ) ( unsigned long ) V_177 ;
V_178 = ( T_8 * ) V_173 ;
for ( V_32 = 0 ; V_32 < V_176 - 1 ; V_32 ++ )
* V_179 ++ = * V_178 ++ ;
* V_179 = '\0' ;
}
}
V_129 -> V_141 = V_177 ;
V_129 -> V_164 = 0 ;
V_129 -> V_165 = 0 ;
memset ( V_170 , 0 , sizeof( * V_170 ) ) ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
V_14 = F_17 ( V_127 , V_129 ) ;
if ( V_14 != V_21 )
goto V_192;
return V_123 ;
V_192:
if ( V_176 )
F_12 ( V_176 , V_129 -> V_141 ) ;
V_22:
F_12 ( 0x4000 , ( unsigned long ) V_123 ) ;
return NULL ;
}
static T_2 F_19 ( struct V_123 * V_123 ,
void * V_117 )
{
struct V_171 * V_172 = & V_123 -> V_171 ;
struct V_193 * V_194 = & V_123 -> V_194 [ 0 ] ;
struct V_193 * V_195 = NULL ;
unsigned long V_26 , V_15 , V_12 , V_196 ;
T_3 * V_197 ;
T_2 V_14 ;
T_15 V_16 ;
T_6 V_198 ;
int V_32 ;
V_26 = sizeof( * V_197 ) * 32 ;
V_17:
V_26 += sizeof( * V_197 ) ;
V_196 = V_26 ;
V_14 = F_11 ( V_26 , 1 , ( unsigned long * ) & V_197 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_14 = F_5 ( V_6 -> V_18 -> V_23 , & V_26 ,
V_197 , & V_15 , & V_12 , & V_16 ) ;
if ( V_14 == V_24 ) {
F_12 ( V_196 , ( unsigned long ) V_197 ) ;
goto V_17;
}
if ( V_14 != V_21 )
goto V_199;
memcpy ( & V_172 -> V_200 , V_201 , sizeof( T_15 ) ) ;
V_172 -> V_202 = ( unsigned long ) V_6 ;
V_172 -> V_203 = V_12 ;
V_172 -> V_204 = V_16 ;
V_172 -> V_205 = ( unsigned long ) V_197 ;
V_172 -> V_206 = V_26 ;
#ifdef F_20
V_172 -> V_207 = ( unsigned long ) V_6 >> 32 ;
V_172 -> V_208 = ( unsigned long ) V_197 >> 32 ;
#endif
V_14 = F_2 ( V_6 -> V_18 -> V_209 ,
V_117 , V_15 ) ;
if ( V_14 != V_21 )
goto V_199;
V_123 -> V_210 = 32 * 1024 ;
V_198 = 0 ;
for ( V_32 = 0 ; V_32 < V_26 / V_12 ; V_32 ++ ) {
T_3 * V_211 ;
unsigned int V_212 = 0 ;
unsigned long V_13 = ( unsigned long ) V_197 ;
V_211 = ( T_3 * ) ( V_13 + ( V_32 * V_12 ) ) ;
switch ( V_211 -> type ) {
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
V_212 = V_219 ;
break;
case V_220 :
V_212 = V_221 ;
break;
case V_222 :
V_212 = V_223 ;
break;
case V_224 :
case V_20 :
case V_225 :
case V_226 :
case V_37 :
V_212 = V_227 ;
break;
case V_228 :
V_212 = V_229 ;
break;
default:
continue;
}
if ( V_195 && V_195 -> type == V_212 &&
( V_195 -> V_28 + V_195 -> V_26 ) == V_211 -> V_39 )
V_195 -> V_26 += V_211 -> V_38 << 12 ;
else {
V_194 -> V_28 = V_211 -> V_39 ;
V_194 -> V_26 = V_211 -> V_38 << 12 ;
V_194 -> type = V_212 ;
V_195 = V_194 ++ ;
V_198 ++ ;
}
}
V_123 -> V_230 = V_198 ;
return V_21 ;
V_199:
F_12 ( V_196 , ( unsigned long ) V_197 ) ;
return V_14 ;
}
static T_2 F_21 ( struct V_128 * V_129 )
{
unsigned long V_35 , V_30 ;
T_2 V_14 ;
V_35 = V_129 -> V_231 ;
V_30 = F_8 ( V_129 -> V_232 , V_33 ) / V_33 ;
V_14 = F_10 ( V_6 -> V_18 -> V_42 ,
V_43 , V_20 ,
V_30 , & V_35 ) ;
if ( V_14 != V_21 ) {
V_14 = F_11 ( V_129 -> V_232 , V_129 -> V_233 ,
& V_35 ) ;
if ( V_14 != V_21 )
F_1 ( L_15 ) ;
}
if ( V_14 == V_21 )
memcpy ( ( void * ) V_35 , ( void * ) ( unsigned long ) V_129 -> V_187 ,
V_129 -> V_232 ) ;
V_129 -> V_231 = V_129 -> V_187 ;
V_129 -> V_187 = ( T_15 ) V_35 ;
return V_14 ;
}
struct V_123 * F_22 ( void * V_117 , T_14 * V_166 ,
struct V_123 * V_123 )
{
struct V_234 * V_235 , * V_236 ;
T_9 * V_127 ;
struct V_128 * V_129 = & V_123 -> V_129 ;
T_2 V_14 ;
struct V_237 * V_34 ;
V_6 = V_166 ;
if ( V_6 -> V_129 . V_180 != V_181 )
goto V_22;
F_16 ( V_123 ) ;
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 , sizeof( * V_235 ) ,
( void * * ) & V_235 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_16 ) ;
goto V_22;
}
V_235 -> V_26 = 0x800 ;
V_14 = F_11 ( V_235 -> V_26 , 8 , ( unsigned long * ) & V_235 -> V_238 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_17 ) ;
goto V_22;
}
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 , sizeof( * V_236 ) ,
( void * * ) & V_236 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_18 ) ;
goto V_22;
}
V_236 -> V_26 = 0 ;
V_236 -> V_238 = 0 ;
if ( V_129 -> V_231 != V_129 -> V_187 ) {
V_14 = F_21 ( V_129 ) ;
if ( V_14 != V_21 )
goto V_22;
}
V_14 = F_19 ( V_123 , V_117 ) ;
if ( V_14 != V_21 )
goto V_22;
memset ( ( char * ) V_235 -> V_238 , 0x0 , V_235 -> V_26 ) ;
V_34 = (struct V_237 * ) V_235 -> V_238 ;
V_34 += 2 ;
V_34 -> V_239 = 0xffff ;
V_34 -> V_240 = 0x0000 ;
V_34 -> V_241 = 0x0000 ;
V_34 -> type = V_242 | V_243 ;
V_34 -> V_244 = V_245 ;
V_34 -> V_246 = 0 ;
V_34 -> V_146 = 1 ;
V_34 -> V_247 = 0xf ;
V_34 -> V_248 = 0 ;
V_34 -> V_249 = 0 ;
V_34 -> V_211 = V_250 ;
V_34 -> V_251 = V_252 ;
V_34 -> V_253 = 0x00 ;
V_34 ++ ;
V_34 -> V_239 = 0xffff ;
V_34 -> V_240 = 0x0000 ;
V_34 -> V_241 = 0x0000 ;
V_34 -> type = V_254 | V_255 ;
V_34 -> V_244 = V_245 ;
V_34 -> V_246 = 0 ;
V_34 -> V_146 = 1 ;
V_34 -> V_247 = 0xf ;
V_34 -> V_248 = 0 ;
V_34 -> V_249 = 0 ;
V_34 -> V_211 = V_250 ;
V_34 -> V_251 = V_252 ;
V_34 -> V_253 = 0x00 ;
#ifdef F_20
V_34 ++ ;
V_34 -> V_239 = 0x0000 ;
V_34 -> V_240 = 0x0000 ;
V_34 -> V_241 = 0x0000 ;
V_34 -> type = V_256 ;
V_34 -> V_244 = 0 ;
V_34 -> V_246 = 0 ;
V_34 -> V_146 = 1 ;
V_34 -> V_247 = 0x0 ;
V_34 -> V_248 = 0 ;
V_34 -> V_249 = 0 ;
V_34 -> V_211 = 0 ;
V_34 -> V_251 = V_252 ;
V_34 -> V_253 = 0x00 ;
#endif
asm volatile ("lidt %0" : : "m" (*idt));
asm volatile ("lgdt %0" : : "m" (*gdt));
asm volatile("cli");
return V_123 ;
V_22:
return NULL ;
}
