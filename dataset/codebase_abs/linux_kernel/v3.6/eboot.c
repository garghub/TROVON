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
void * V_72 ;
void * V_73 = V_58 [ V_32 ] ;
V_14 = F_4 ( V_6 -> V_18 -> V_74 ,
V_73 , V_51 , & V_53 ) ;
if ( V_14 != V_21 )
continue;
F_4 ( V_6 -> V_18 -> V_74 ,
V_73 , & V_70 , & V_72 ) ;
V_14 = F_10 ( V_53 -> V_75 , V_53 ,
V_53 -> V_76 -> V_76 , & V_26 , & V_69 ) ;
if ( V_14 == V_21 && ( ! V_54 || V_72 ) ) {
V_59 = V_69 -> V_77 ;
V_60 = V_69 -> V_78 ;
V_61 = V_53 -> V_76 -> V_79 ;
V_62 = V_53 -> V_76 -> V_80 ;
V_64 = V_69 -> V_64 ;
V_56 = V_69 -> V_81 ;
V_63 = V_69 -> V_63 ;
if ( V_72 )
break;
V_54 = V_53 ;
}
}
if ( ! V_54 )
goto V_67;
V_50 -> V_82 = V_83 ;
V_50 -> V_84 = V_59 ;
V_50 -> V_85 = V_60 ;
V_50 -> V_86 = V_61 ;
V_50 -> V_87 = V_62 ;
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
V_50 -> V_91 = V_50 -> V_84 / 2 ;
V_50 -> V_92 = 0 ;
V_50 -> V_93 = 0 ;
V_50 -> V_94 = 0 ;
V_50 -> V_95 = 0 ;
V_50 -> V_96 = 0 ;
V_50 -> V_97 = 0 ;
V_50 -> V_98 = 0 ;
V_50 -> V_99 = 0 ;
}
V_67:
F_6 ( V_6 -> V_18 -> V_25 , V_58 ) ;
return V_14 ;
}
static T_2 F_15 ( struct V_49 * V_50 , T_7 * V_106 ,
unsigned long V_26 )
{
struct V_107 * V_108 , * V_109 ;
unsigned long V_110 ;
T_2 V_14 ;
T_4 V_59 , V_60 ;
void * * V_111 = NULL ;
int V_32 ;
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 , V_26 , & V_111 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_14 = F_5 ( V_6 -> V_18 -> V_65 ,
V_66 , V_106 ,
NULL , & V_26 , V_111 ) ;
if ( V_14 != V_21 )
goto V_67;
V_109 = NULL ;
V_110 = V_26 / sizeof( void * ) ;
for ( V_32 = 0 ; V_32 < V_110 ; V_32 ++ ) {
T_7 V_70 = V_71 ;
void * V_112 = V_111 [ V_32 ] ;
T_4 V_113 , V_73 , V_114 , V_115 ;
void * V_72 ;
V_14 = F_4 ( V_6 -> V_18 -> V_74 ,
V_112 , V_106 , & V_108 ) ;
if ( V_14 != V_21 )
continue;
F_4 ( V_6 -> V_18 -> V_74 ,
V_112 , & V_70 , & V_72 ) ;
V_14 = F_5 ( V_108 -> V_116 , V_108 , & V_113 , & V_73 ,
& V_114 , & V_115 ) ;
if ( V_14 == V_21 && ( ! V_109 || V_72 ) ) {
V_59 = V_113 ;
V_60 = V_73 ;
if ( V_72 )
break;
V_109 = V_108 ;
}
}
if ( ! V_109 )
goto V_67;
V_50 -> V_82 = V_83 ;
V_50 -> V_90 = 32 ;
V_50 -> V_84 = V_59 ;
V_50 -> V_85 = V_60 ;
V_50 -> V_92 = 8 ;
V_50 -> V_93 = 16 ;
V_50 -> V_94 = 8 ;
V_50 -> V_95 = 8 ;
V_50 -> V_96 = 8 ;
V_50 -> V_97 = 0 ;
V_50 -> V_98 = 8 ;
V_50 -> V_99 = 24 ;
V_67:
F_6 ( V_6 -> V_18 -> V_25 , V_111 ) ;
return V_14 ;
}
void F_16 ( struct V_117 * V_117 )
{
T_7 V_118 = V_119 ;
struct V_49 * V_50 ;
T_7 V_106 = V_120 ;
T_2 V_14 ;
unsigned long V_26 ;
void * * V_58 = NULL ;
void * * V_111 = NULL ;
V_50 = & V_117 -> V_49 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_26 = 0 ;
V_14 = F_5 ( V_6 -> V_18 -> V_65 ,
V_66 , & V_118 ,
NULL , & V_26 , V_58 ) ;
if ( V_14 == V_24 )
V_14 = F_14 ( V_50 , & V_118 , V_26 ) ;
if ( V_14 != V_21 ) {
V_26 = 0 ;
V_14 = F_5 ( V_6 -> V_18 -> V_65 ,
V_66 , & V_106 ,
NULL , & V_26 , V_111 ) ;
if ( V_14 == V_24 )
F_15 ( V_50 , & V_106 , V_26 ) ;
}
}
static T_2 F_17 ( T_9 * V_121 ,
struct V_122 * V_123 )
{
struct V_124 * V_125 ;
unsigned long V_126 ;
T_7 V_127 = V_128 ;
T_5 V_129 ;
T_10 * V_130 ;
T_11 * V_131 ;
T_2 V_14 ;
int V_132 ;
char * V_1 ;
int V_32 , V_133 , V_134 ;
V_126 = 0 ;
V_129 = 0 ;
V_1 = ( char * ) ( unsigned long ) V_123 -> V_135 ;
V_133 = 0 ;
if ( ! V_1 || ! * V_1 )
return V_21 ;
for ( V_132 = 0 ; * V_1 ; V_132 ++ ) {
V_1 = strstr ( V_1 , L_1 ) ;
if ( ! V_1 )
break;
V_1 += 7 ;
while ( * V_1 == '/' || * V_1 == '\\' )
V_1 ++ ;
while ( * V_1 && * V_1 != ' ' && * V_1 != '\n' )
V_1 ++ ;
}
if ( ! V_132 )
return V_21 ;
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 ,
V_132 * sizeof( * V_125 ) ,
& V_125 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_2 ) ;
goto V_22;
}
V_1 = ( char * ) ( unsigned long ) V_123 -> V_135 ;
for ( V_32 = 0 ; V_32 < V_132 ; V_32 ++ ) {
struct V_124 * V_124 ;
T_11 * V_73 ;
T_12 * V_69 ;
T_1 V_136 [ 256 ] ;
unsigned long V_137 ;
T_7 V_138 = V_139 ;
T_1 * V_140 ;
T_5 V_141 ;
V_1 = strstr ( V_1 , L_1 ) ;
if ( ! V_1 )
break;
V_1 += 7 ;
V_124 = & V_125 [ V_32 ] ;
V_140 = V_136 ;
while ( * V_1 == '/' || * V_1 == '\\' )
V_1 ++ ;
while ( * V_1 && * V_1 != ' ' && * V_1 != '\n' ) {
if ( ( T_6 * ) V_140 >= ( T_6 * ) V_136 + sizeof( V_136 ) )
break;
* V_140 ++ = * V_1 ++ ;
}
* V_140 = '\0' ;
if ( ! V_32 ) {
T_13 * V_18 ;
V_18 = V_6 -> V_18 ;
V_14 = F_4 ( V_18 -> V_74 ,
V_121 -> V_142 , & V_127 , & V_130 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_3 ) ;
goto V_143;
}
V_14 = F_2 ( V_130 -> V_144 , V_130 , & V_131 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_4 ) ;
goto V_143;
}
}
V_14 = F_5 ( V_131 -> V_145 , V_131 , & V_73 , V_136 ,
V_146 , ( T_5 ) 0 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_5 ) ;
goto V_147;
}
V_124 -> V_112 = V_73 ;
V_137 = 0 ;
V_14 = F_10 ( V_73 -> V_148 , V_73 , & V_138 ,
& V_137 , NULL ) ;
if ( V_14 != V_24 ) {
F_1 ( L_6 ) ;
goto V_147;
}
V_149:
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 , V_137 , & V_69 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_7 ) ;
goto V_147;
}
V_14 = F_10 ( V_73 -> V_148 , V_73 , & V_138 ,
& V_137 , V_69 ) ;
if ( V_14 == V_24 ) {
F_6 ( V_6 -> V_18 -> V_25 , V_69 ) ;
goto V_149;
}
V_141 = V_69 -> V_150 ;
F_6 ( V_6 -> V_18 -> V_25 , V_69 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_8 ) ;
goto V_147;
}
V_124 -> V_26 = V_141 ;
V_129 += V_141 ;
}
if ( V_129 ) {
unsigned long V_28 ;
V_14 = F_7 ( V_129 , 0x1000 ,
& V_126 , V_123 -> V_151 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_9 ) ;
goto V_147;
}
if ( V_126 > V_123 -> V_151 ) {
F_1 ( L_10 ) ;
V_14 = V_152 ;
goto V_153;
}
V_28 = V_126 ;
for ( V_133 = 0 ; V_133 < V_132 ; V_133 ++ ) {
T_5 V_26 ;
V_26 = V_125 [ V_133 ] . V_26 ;
while ( V_26 ) {
T_5 V_154 ;
if ( V_26 > V_155 )
V_154 = V_155 ;
else
V_154 = V_26 ;
V_14 = F_4 ( V_131 -> V_156 ,
V_125 [ V_133 ] . V_112 ,
& V_154 , V_28 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_11 ) ;
goto V_153;
}
V_28 += V_154 ;
V_26 -= V_154 ;
}
F_6 ( V_131 -> V_157 , V_125 [ V_133 ] . V_112 ) ;
}
}
F_6 ( V_6 -> V_18 -> V_25 , V_125 ) ;
V_123 -> V_158 = V_126 ;
V_123 -> V_159 = V_129 ;
return V_14 ;
V_153:
F_12 ( V_129 , V_126 ) ;
V_147:
for ( V_134 = V_133 ; V_134 < V_32 ; V_134 ++ )
F_6 ( V_131 -> V_157 , V_125 [ V_134 ] . V_112 ) ;
V_143:
F_6 ( V_6 -> V_18 -> V_25 , V_125 ) ;
V_22:
V_123 -> V_158 = 0 ;
V_123 -> V_159 = 0 ;
return V_14 ;
}
struct V_117 * F_18 ( void * V_112 , T_14 * V_160 )
{
struct V_117 * V_117 ;
struct V_161 * V_162 ;
struct V_163 * V_164 ;
struct V_122 * V_123 ;
struct V_165 * V_166 ;
T_9 * V_121 ;
void * V_167 ;
T_4 V_168 ;
T_7 V_51 = V_169 ;
int V_170 = 0 ;
T_2 V_14 ;
unsigned long V_171 ;
T_8 * V_172 ;
T_6 * V_173 ;
int V_32 ;
V_6 = V_160 ;
if ( V_6 -> V_123 . V_174 != V_175 )
return NULL ;
V_14 = F_4 ( V_6 -> V_18 -> V_74 ,
V_112 , & V_51 , ( void * ) & V_121 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_12 ) ;
return NULL ;
}
V_14 = F_11 ( 0x4000 , 1 , ( unsigned long * ) & V_117 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_13 ) ;
return NULL ;
}
memset ( V_117 , 0x0 , 0x4000 ) ;
V_123 = & V_117 -> V_123 ;
V_166 = & V_117 -> V_165 ;
V_164 = & V_117 -> V_163 ;
V_162 = & V_117 -> V_161 ;
memcpy ( & V_123 -> V_176 , V_121 -> V_177 + 512 , 512 ) ;
V_123 -> V_178 = 1 ;
V_123 -> V_179 = 0xffff ;
V_123 -> V_180 = 0xAA55 ;
V_123 -> V_181 = ( V_182 ) ( unsigned long ) V_121 -> V_177 ;
V_123 -> V_183 = 0x21 ;
V_167 = V_121 -> V_184 ;
V_168 = V_121 -> V_168 / 2 ;
V_171 = 0 ;
V_172 = ( T_8 * ) V_167 ;
if ( V_172 ) {
while ( * V_172 && * V_172 != '\n' && V_170 < V_168 ) {
V_172 ++ ;
V_170 ++ ;
}
if ( V_170 ) {
if ( V_170 > V_123 -> V_185 )
V_170 = V_123 -> V_185 ;
V_170 ++ ;
V_14 = F_11 ( V_170 , 1 , & V_171 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_14 ) ;
goto V_22;
}
V_173 = ( T_6 * ) ( unsigned long ) V_171 ;
V_172 = ( T_8 * ) V_167 ;
for ( V_32 = 0 ; V_32 < V_170 - 1 ; V_32 ++ )
* V_173 ++ = * V_172 ++ ;
* V_173 = '\0' ;
}
}
V_123 -> V_135 = V_171 ;
V_123 -> V_158 = 0 ;
V_123 -> V_159 = 0 ;
memset ( V_164 , 0 , sizeof( * V_164 ) ) ;
memset ( V_162 , 0 , sizeof( * V_162 ) ) ;
V_14 = F_17 ( V_121 , V_123 ) ;
if ( V_14 != V_21 )
goto V_186;
return V_117 ;
V_186:
if ( V_170 )
F_12 ( V_170 , V_123 -> V_135 ) ;
V_22:
F_12 ( 0x4000 , ( unsigned long ) V_117 ) ;
return NULL ;
}
static T_2 F_19 ( struct V_117 * V_117 ,
void * V_112 )
{
struct V_165 * V_166 = & V_117 -> V_165 ;
struct V_187 * V_188 = & V_117 -> V_188 [ 0 ] ;
struct V_187 * V_189 = NULL ;
unsigned long V_26 , V_15 , V_12 , V_190 ;
T_3 * V_191 ;
T_2 V_14 ;
T_15 V_16 ;
T_6 V_192 ;
int V_32 ;
V_26 = sizeof( * V_191 ) * 32 ;
V_17:
V_26 += sizeof( * V_191 ) ;
V_190 = V_26 ;
V_14 = F_11 ( V_26 , 1 , ( unsigned long * ) & V_191 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_14 = F_5 ( V_6 -> V_18 -> V_23 , & V_26 ,
V_191 , & V_15 , & V_12 , & V_16 ) ;
if ( V_14 == V_24 ) {
F_12 ( V_190 , ( unsigned long ) V_191 ) ;
goto V_17;
}
if ( V_14 != V_21 )
goto V_193;
memcpy ( & V_166 -> V_194 , V_195 , sizeof( T_15 ) ) ;
V_166 -> V_196 = ( unsigned long ) V_6 ;
V_166 -> V_197 = V_12 ;
V_166 -> V_198 = V_16 ;
V_166 -> V_199 = ( unsigned long ) V_191 ;
V_166 -> V_200 = V_26 ;
#ifdef F_20
V_166 -> V_201 = ( unsigned long ) V_6 >> 32 ;
V_166 -> V_202 = ( unsigned long ) V_191 >> 32 ;
#endif
V_14 = F_2 ( V_6 -> V_18 -> V_203 ,
V_112 , V_15 ) ;
if ( V_14 != V_21 )
goto V_193;
V_117 -> V_204 = 32 * 1024 ;
V_192 = 0 ;
for ( V_32 = 0 ; V_32 < V_26 / V_12 ; V_32 ++ ) {
T_3 * V_205 ;
unsigned int V_206 = 0 ;
unsigned long V_13 = ( unsigned long ) V_191 ;
V_205 = ( T_3 * ) ( V_13 + ( V_32 * V_12 ) ) ;
switch ( V_205 -> type ) {
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
V_206 = V_213 ;
break;
case V_214 :
V_206 = V_215 ;
break;
case V_216 :
V_206 = V_217 ;
break;
case V_218 :
case V_20 :
case V_219 :
case V_220 :
case V_37 :
V_206 = V_221 ;
break;
case V_222 :
V_206 = V_223 ;
break;
default:
continue;
}
if ( V_189 && V_189 -> type == V_206 &&
( V_189 -> V_28 + V_189 -> V_26 ) == V_205 -> V_39 )
V_189 -> V_26 += V_205 -> V_38 << 12 ;
else {
V_188 -> V_28 = V_205 -> V_39 ;
V_188 -> V_26 = V_205 -> V_38 << 12 ;
V_188 -> type = V_206 ;
V_189 = V_188 ++ ;
V_192 ++ ;
}
}
V_117 -> V_224 = V_192 ;
return V_21 ;
V_193:
F_12 ( V_190 , ( unsigned long ) V_191 ) ;
return V_14 ;
}
static T_2 F_21 ( struct V_122 * V_123 )
{
unsigned long V_35 , V_30 ;
T_2 V_14 ;
V_35 = V_123 -> V_225 ;
V_30 = F_8 ( V_123 -> V_226 , V_33 ) / V_33 ;
V_14 = F_10 ( V_6 -> V_18 -> V_42 ,
V_43 , V_20 ,
V_30 , & V_35 ) ;
if ( V_14 != V_21 ) {
V_14 = F_11 ( V_123 -> V_226 , V_123 -> V_227 ,
& V_35 ) ;
if ( V_14 != V_21 )
F_1 ( L_15 ) ;
}
if ( V_14 == V_21 )
memcpy ( ( void * ) V_35 , ( void * ) ( unsigned long ) V_123 -> V_181 ,
V_123 -> V_226 ) ;
V_123 -> V_225 = V_123 -> V_181 ;
V_123 -> V_181 = ( T_15 ) V_35 ;
return V_14 ;
}
struct V_117 * F_22 ( void * V_112 , T_14 * V_160 ,
struct V_117 * V_117 )
{
struct V_228 * V_229 , * V_230 ;
T_9 * V_121 ;
struct V_122 * V_123 = & V_117 -> V_123 ;
T_2 V_14 ;
struct V_231 * V_34 ;
V_6 = V_160 ;
if ( V_6 -> V_123 . V_174 != V_175 )
goto V_22;
F_16 ( V_117 ) ;
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 , sizeof( * V_229 ) ,
( void * * ) & V_229 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_16 ) ;
goto V_22;
}
V_229 -> V_26 = 0x800 ;
V_14 = F_11 ( V_229 -> V_26 , 8 , ( unsigned long * ) & V_229 -> V_232 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_17 ) ;
goto V_22;
}
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 , sizeof( * V_230 ) ,
( void * * ) & V_230 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_18 ) ;
goto V_22;
}
V_230 -> V_26 = 0 ;
V_230 -> V_232 = 0 ;
if ( V_123 -> V_225 != V_123 -> V_181 ) {
V_14 = F_21 ( V_123 ) ;
if ( V_14 != V_21 )
goto V_22;
}
V_14 = F_19 ( V_117 , V_112 ) ;
if ( V_14 != V_21 )
goto V_22;
memset ( ( char * ) V_229 -> V_232 , 0x0 , V_229 -> V_26 ) ;
V_34 = (struct V_231 * ) V_229 -> V_232 ;
V_34 += 2 ;
V_34 -> V_233 = 0xffff ;
V_34 -> V_234 = 0x0000 ;
V_34 -> V_235 = 0x0000 ;
V_34 -> type = V_236 | V_237 ;
V_34 -> V_238 = V_239 ;
V_34 -> V_240 = 0 ;
V_34 -> V_140 = 1 ;
V_34 -> V_241 = 0xf ;
V_34 -> V_242 = 0 ;
V_34 -> V_243 = 0 ;
V_34 -> V_205 = V_244 ;
V_34 -> V_245 = V_246 ;
V_34 -> V_247 = 0x00 ;
V_34 ++ ;
V_34 -> V_233 = 0xffff ;
V_34 -> V_234 = 0x0000 ;
V_34 -> V_235 = 0x0000 ;
V_34 -> type = V_248 | V_249 ;
V_34 -> V_238 = V_239 ;
V_34 -> V_240 = 0 ;
V_34 -> V_140 = 1 ;
V_34 -> V_241 = 0xf ;
V_34 -> V_242 = 0 ;
V_34 -> V_243 = 0 ;
V_34 -> V_205 = V_244 ;
V_34 -> V_245 = V_246 ;
V_34 -> V_247 = 0x00 ;
#ifdef F_20
V_34 ++ ;
V_34 -> V_233 = 0x0000 ;
V_34 -> V_234 = 0x0000 ;
V_34 -> V_235 = 0x0000 ;
V_34 -> type = V_250 ;
V_34 -> V_238 = 0 ;
V_34 -> V_240 = 0 ;
V_34 -> V_140 = 1 ;
V_34 -> V_241 = 0x0 ;
V_34 -> V_242 = 0 ;
V_34 -> V_243 = 0 ;
V_34 -> V_205 = 0 ;
V_34 -> V_245 = V_246 ;
V_34 -> V_247 = 0x00 ;
#endif
asm volatile ("lidt %0" : : "m" (*idt));
asm volatile ("lgdt %0" : : "m" (*gdt));
asm volatile("cli");
return V_117 ;
V_22:
return NULL ;
}
