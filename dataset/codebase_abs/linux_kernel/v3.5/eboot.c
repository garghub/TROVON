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
static T_2 F_18 ( struct V_117 * V_117 ,
T_9 * V_121 ,
void * V_112 )
{
struct V_160 * V_161 = & V_117 -> V_160 ;
struct V_162 * V_163 = & V_117 -> V_162 ;
struct V_164 * V_165 = & V_117 -> V_164 ;
struct V_166 * V_167 = & V_117 -> V_167 [ 0 ] ;
struct V_166 * V_168 = NULL ;
struct V_122 * V_123 = & V_117 -> V_123 ;
unsigned long V_26 , V_15 , V_12 , V_169 ;
T_3 * V_170 ;
void * V_171 = V_121 -> V_172 ;
T_4 V_173 = V_121 -> V_173 / 2 ;
int V_174 = 0 ;
T_2 V_14 ;
T_14 V_16 ;
unsigned long V_175 ;
T_6 V_176 ;
T_8 * V_177 ;
T_6 * V_178 ;
int V_32 ;
V_123 -> V_179 = 0x21 ;
V_175 = 0 ;
V_177 = ( T_8 * ) V_171 ;
if ( V_177 ) {
while ( * V_177 && * V_177 != '\n' && V_174 < V_173 ) {
V_177 ++ ;
V_174 ++ ;
}
if ( V_174 ) {
if ( V_174 > V_123 -> V_180 )
V_174 = V_123 -> V_180 ;
V_174 ++ ;
V_14 = F_11 ( V_174 , 1 , & V_175 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_12 ) ;
goto V_22;
}
V_178 = ( T_6 * ) ( unsigned long ) V_175 ;
V_177 = ( T_8 * ) V_171 ;
for ( V_32 = 0 ; V_32 < V_174 - 1 ; V_32 ++ )
* V_178 ++ = * V_177 ++ ;
* V_178 = '\0' ;
}
}
V_123 -> V_135 = V_175 ;
V_123 -> V_158 = 0 ;
V_123 -> V_159 = 0 ;
V_14 = F_17 ( V_121 , V_123 ) ;
if ( V_14 != V_21 )
goto V_181;
F_16 ( V_117 ) ;
memset ( V_163 , 0 , sizeof( * V_163 ) ) ;
memset ( V_165 , 0 , sizeof( * V_165 ) ) ;
memcpy ( & V_161 -> V_182 , V_183 , sizeof( T_14 ) ) ;
V_26 = sizeof( * V_170 ) * 32 ;
V_17:
V_26 += sizeof( * V_170 ) ;
V_169 = V_26 ;
V_14 = F_11 ( V_26 , 1 , ( unsigned long * ) & V_170 ) ;
if ( V_14 != V_21 )
goto V_181;
V_14 = F_5 ( V_6 -> V_18 -> V_23 , & V_26 ,
V_170 , & V_15 , & V_12 , & V_16 ) ;
if ( V_14 == V_24 ) {
F_12 ( V_169 , ( unsigned long ) V_170 ) ;
goto V_17;
}
if ( V_14 != V_21 )
goto V_184;
V_161 -> V_185 = ( unsigned long ) V_6 ;
V_161 -> V_186 = V_12 ;
V_161 -> V_187 = V_16 ;
V_161 -> V_188 = ( unsigned long ) V_170 ;
V_161 -> V_189 = V_26 ;
#ifdef F_19
V_161 -> V_190 = ( unsigned long ) V_6 >> 32 ;
V_161 -> V_191 = ( unsigned long ) V_170 >> 32 ;
#endif
V_14 = F_2 ( V_6 -> V_18 -> V_192 ,
V_112 , V_15 ) ;
if ( V_14 != V_21 )
goto V_184;
V_117 -> V_193 = 32 * 1024 ;
V_176 = 0 ;
for ( V_32 = 0 ; V_32 < V_26 / V_12 ; V_32 ++ ) {
T_3 * V_194 ;
unsigned int V_195 = 0 ;
unsigned long V_13 = ( unsigned long ) V_170 ;
V_194 = ( T_3 * ) ( V_13 + ( V_32 * V_12 ) ) ;
switch ( V_194 -> type ) {
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
V_195 = V_202 ;
break;
case V_203 :
V_195 = V_204 ;
break;
case V_205 :
V_195 = V_206 ;
break;
case V_207 :
case V_20 :
case V_208 :
case V_209 :
case V_37 :
V_195 = V_210 ;
break;
case V_211 :
V_195 = V_212 ;
break;
default:
continue;
}
if ( V_168 && V_168 -> type == V_195 &&
( V_168 -> V_28 + V_168 -> V_26 ) == V_194 -> V_39 )
V_168 -> V_26 += V_194 -> V_38 << 12 ;
else {
V_167 -> V_28 = V_194 -> V_39 ;
V_167 -> V_26 = V_194 -> V_38 << 12 ;
V_167 -> type = V_195 ;
V_168 = V_167 ++ ;
V_176 ++ ;
}
}
V_117 -> V_213 = V_176 ;
return V_21 ;
V_184:
F_12 ( V_169 , ( unsigned long ) V_170 ) ;
V_181:
if ( V_174 )
F_12 ( V_174 , V_123 -> V_135 ) ;
V_22:
return V_14 ;
}
struct V_117 * F_20 ( void * V_112 , T_15 * V_214 )
{
struct V_117 * V_117 ;
unsigned long V_35 , V_30 ;
struct V_215 * V_216 , * V_217 ;
T_9 * V_121 ;
struct V_122 * V_123 ;
T_2 V_14 ;
T_7 V_51 = V_218 ;
struct V_219 * V_34 ;
V_6 = V_214 ;
if ( V_6 -> V_123 . V_220 != V_221 )
goto V_22;
V_14 = F_4 ( V_6 -> V_18 -> V_74 ,
V_112 , & V_51 , ( void * ) & V_121 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_13 ) ;
goto V_22;
}
V_14 = F_11 ( 0x4000 , 1 , ( unsigned long * ) & V_117 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_14 ) ;
goto V_22;
}
memset ( V_117 , 0x0 , 0x4000 ) ;
V_123 = & V_117 -> V_123 ;
memcpy ( & V_123 -> V_222 , V_121 -> V_223 + 512 , 512 ) ;
V_123 -> V_224 = 1 ;
V_123 -> V_225 = 0xffff ;
V_123 -> V_226 = 0xAA55 ;
V_35 = V_123 -> V_227 ;
V_30 = F_8 ( V_123 -> V_228 , V_33 ) / V_33 ;
V_14 = F_10 ( V_6 -> V_18 -> V_42 ,
V_43 , V_20 ,
V_30 , & V_35 ) ;
if ( V_14 != V_21 ) {
V_14 = F_11 ( V_123 -> V_228 , V_123 -> V_229 ,
& V_35 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_15 ) ;
goto V_22;
}
}
V_123 -> V_230 = ( T_14 ) V_35 ;
V_123 -> V_227 = ( V_231 ) ( unsigned long ) V_121 -> V_223 ;
memcpy ( ( void * ) V_35 , V_121 -> V_223 , V_121 -> V_232 ) ;
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 , sizeof( * V_216 ) ,
( void * * ) & V_216 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_16 ) ;
goto V_22;
}
V_216 -> V_26 = 0x800 ;
V_14 = F_11 ( V_216 -> V_26 , 8 , ( unsigned long * ) & V_216 -> V_233 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_17 ) ;
goto V_22;
}
V_14 = F_4 ( V_6 -> V_18 -> V_19 ,
V_20 , sizeof( * V_217 ) ,
( void * * ) & V_217 ) ;
if ( V_14 != V_21 ) {
F_1 ( L_18 ) ;
goto V_22;
}
V_217 -> V_26 = 0 ;
V_217 -> V_233 = 0 ;
V_14 = F_18 ( V_117 , V_121 , V_112 ) ;
if ( V_14 != V_21 )
goto V_22;
memset ( ( char * ) V_216 -> V_233 , 0x0 , V_216 -> V_26 ) ;
V_34 = (struct V_219 * ) V_216 -> V_233 ;
V_34 += 2 ;
V_34 -> V_234 = 0xffff ;
V_34 -> V_235 = 0x0000 ;
V_34 -> V_236 = 0x0000 ;
V_34 -> type = V_237 | V_238 ;
V_34 -> V_239 = V_240 ;
V_34 -> V_241 = 0 ;
V_34 -> V_140 = 1 ;
V_34 -> V_242 = 0xf ;
V_34 -> V_243 = 0 ;
V_34 -> V_244 = 0 ;
V_34 -> V_194 = V_245 ;
V_34 -> V_246 = V_247 ;
V_34 -> V_248 = 0x00 ;
V_34 ++ ;
V_34 -> V_234 = 0xffff ;
V_34 -> V_235 = 0x0000 ;
V_34 -> V_236 = 0x0000 ;
V_34 -> type = V_249 | V_250 ;
V_34 -> V_239 = V_240 ;
V_34 -> V_241 = 0 ;
V_34 -> V_140 = 1 ;
V_34 -> V_242 = 0xf ;
V_34 -> V_243 = 0 ;
V_34 -> V_244 = 0 ;
V_34 -> V_194 = V_245 ;
V_34 -> V_246 = V_247 ;
V_34 -> V_248 = 0x00 ;
#ifdef F_19
V_34 ++ ;
V_34 -> V_234 = 0x0000 ;
V_34 -> V_235 = 0x0000 ;
V_34 -> V_236 = 0x0000 ;
V_34 -> type = V_251 ;
V_34 -> V_239 = 0 ;
V_34 -> V_241 = 0 ;
V_34 -> V_140 = 1 ;
V_34 -> V_242 = 0x0 ;
V_34 -> V_243 = 0 ;
V_34 -> V_244 = 0 ;
V_34 -> V_194 = 0 ;
V_34 -> V_246 = V_247 ;
V_34 -> V_248 = 0x00 ;
#endif
asm volatile ("lidt %0" : : "m" (*idt));
asm volatile ("lgdt %0" : : "m" (*gdt));
asm volatile("cli");
return V_117 ;
V_22:
return NULL ;
}
