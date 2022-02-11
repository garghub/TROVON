static void F_1 ( T_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_4 -> V_5 ;
F_2 ( V_3 -> V_6 , V_3 , V_1 ) ;
}
static void F_3 ( char * V_1 )
{
char * V_7 ;
for ( V_7 = V_1 ; * V_7 ; V_7 ++ ) {
T_1 V_8 [ 2 ] = { 0 } ;
V_8 [ 0 ] = * V_7 ;
if ( * V_7 == '\n' ) {
T_1 V_9 [ 2 ] = { '\r' , 0 } ;
F_1 ( V_9 ) ;
}
F_1 ( V_8 ) ;
}
}
static T_2 F_4 ( T_3 * * V_10 , unsigned long * V_11 ,
unsigned long * V_12 )
{
T_3 * V_13 = NULL ;
T_2 V_14 ;
unsigned long V_15 ;
T_4 V_16 ;
* V_11 = sizeof( * V_13 ) * 32 ;
V_17:
* V_11 += sizeof( * V_13 ) ;
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , * V_11 , ( void * * ) & V_13 ) ;
if ( V_14 != V_21 )
goto V_22;
V_14 = F_6 ( V_4 -> V_18 -> V_23 , V_11 ,
V_13 , & V_15 , V_12 , & V_16 ) ;
if ( V_14 == V_24 ) {
F_7 ( V_4 -> V_18 -> V_25 , V_13 ) ;
goto V_17;
}
if ( V_14 != V_21 )
F_7 ( V_4 -> V_18 -> V_25 , V_13 ) ;
V_22:
* V_10 = V_13 ;
return V_14 ;
}
static T_2 F_8 ( unsigned long V_26 , unsigned long V_27 ,
unsigned long * V_28 , unsigned long V_29 )
{
unsigned long V_11 , V_12 ;
T_3 * V_10 ;
T_2 V_14 ;
unsigned long V_30 ;
T_5 V_31 = 0 ;
int V_32 ;
V_14 = F_4 ( & V_10 , & V_11 , & V_12 ) ;
if ( V_14 != V_21 )
goto V_22;
V_30 = F_9 ( V_26 , V_33 ) / V_33 ;
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
if ( F_10 ( V_36 - V_26 , V_27 ) < V_35 )
continue;
V_35 = F_10 ( V_36 - V_26 , V_27 ) ;
if ( V_35 == 0x0 )
continue;
if ( V_35 > V_31 )
V_31 = V_35 ;
}
if ( ! V_31 )
V_14 = V_41 ;
else {
V_14 = F_11 ( V_4 -> V_18 -> V_42 ,
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
F_7 ( V_4 -> V_18 -> V_25 , V_10 ) ;
V_22:
return V_14 ;
}
static T_2 F_12 ( unsigned long V_26 , unsigned long V_27 ,
unsigned long * V_28 )
{
unsigned long V_11 , V_12 ;
T_3 * V_10 ;
T_2 V_14 ;
unsigned long V_30 ;
int V_32 ;
V_14 = F_4 ( & V_10 , & V_11 , & V_12 ) ;
if ( V_14 != V_21 )
goto V_22;
V_30 = F_9 ( V_26 , V_33 ) / V_33 ;
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
V_35 = F_9 ( V_35 , V_27 ) ;
if ( ( V_35 + V_26 ) > V_36 )
continue;
V_14 = F_11 ( V_4 -> V_18 -> V_42 ,
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
F_7 ( V_4 -> V_18 -> V_25 , V_10 ) ;
V_22:
return V_14 ;
}
static void F_13 ( unsigned long V_26 , unsigned long V_28 )
{
unsigned long V_30 ;
V_30 = F_9 ( V_26 , V_33 ) / V_33 ;
F_2 ( V_4 -> V_18 -> V_44 , V_28 , V_30 ) ;
}
static void F_14 ( unsigned long V_45 , T_6 * V_46 , T_6 * V_26 )
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
static T_2 F_15 ( struct V_49 * V_50 )
{
T_7 * V_51 ;
T_2 V_14 ;
void * * V_52 ;
T_8 V_53 = V_54 ;
unsigned long V_55 , V_26 = 0 ;
int V_32 ;
struct V_56 * V_57 ;
V_57 = (struct V_56 * ) ( unsigned long ) V_50 -> V_58 . V_56 ;
while ( V_57 && V_57 -> V_59 )
V_57 = (struct V_56 * ) ( unsigned long ) V_57 -> V_59 ;
V_14 = F_6 ( V_4 -> V_18 -> V_60 ,
V_61 , & V_53 ,
NULL , & V_26 , V_52 ) ;
if ( V_14 == V_24 ) {
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , V_26 , & V_52 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_14 = F_6 ( V_4 -> V_18 -> V_60 ,
V_61 , & V_53 ,
NULL , & V_26 , V_52 ) ;
}
if ( V_14 != V_21 )
goto V_62;
V_55 = V_26 / sizeof( void * ) ;
for ( V_32 = 0 ; V_32 < V_55 ; V_32 ++ ) {
void * V_63 = V_52 [ V_32 ] ;
T_9 V_64 ;
struct V_65 * V_66 ;
V_14 = F_5 ( V_4 -> V_18 -> V_67 ,
V_63 , & V_53 , & V_51 ) ;
if ( V_14 != V_21 )
continue;
if ( ! V_51 )
continue;
#ifdef F_16
V_14 = F_11 ( V_51 -> V_64 , V_51 ,
V_68 , 0 ,
& V_64 ) ;
#else
V_14 = F_6 ( V_51 -> V_64 , V_51 ,
V_68 , 0 , 0 ,
& V_64 ) ;
#endif
if ( V_14 != V_21 )
continue;
if ( ! V_51 -> V_69 || ! V_51 -> V_70 )
continue;
V_26 = V_51 -> V_70 + sizeof( * V_66 ) ;
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , V_26 , & V_66 ) ;
if ( V_14 != V_21 )
continue;
V_66 -> V_57 . type = V_71 ;
V_66 -> V_57 . V_48 = V_26 - sizeof( struct V_56 ) ;
V_66 -> V_57 . V_59 = 0 ;
V_66 -> V_72 = V_51 -> V_70 ;
V_14 = F_6 ( V_51 -> V_51 . V_73 , V_51 ,
V_74 , V_75 ,
1 , & ( V_66 -> V_76 ) ) ;
if ( V_14 != V_21 )
goto V_77;
V_14 = F_6 ( V_51 -> V_51 . V_73 , V_51 ,
V_74 , V_78 ,
1 , & ( V_66 -> V_79 ) ) ;
if ( V_14 != V_21 )
goto V_77;
V_14 = F_6 ( V_51 -> V_80 , V_51 ,
& ( V_66 -> V_81 ) , & ( V_66 -> V_82 ) ,
& ( V_66 -> V_83 ) , & ( V_66 -> V_84 ) ) ;
if ( V_14 != V_21 )
goto V_77;
memcpy ( V_66 -> V_85 , V_51 -> V_69 , V_51 -> V_70 ) ;
if ( V_57 )
V_57 -> V_59 = ( unsigned long ) V_66 ;
else
V_50 -> V_58 . V_56 = ( unsigned long ) V_66 ;
V_57 = (struct V_56 * ) V_66 ;
continue;
V_77:
F_7 ( V_4 -> V_18 -> V_25 , V_66 ) ;
}
V_62:
F_7 ( V_4 -> V_18 -> V_25 , V_52 ) ;
return V_14 ;
}
static T_2 F_17 ( struct V_86 * V_87 , T_8 * V_88 ,
unsigned long V_26 )
{
struct V_89 * V_90 , * V_91 ;
struct V_92 V_93 ;
unsigned long V_94 ;
T_2 V_14 ;
void * * V_95 ;
T_10 V_96 , V_97 ;
T_4 V_98 , V_99 ;
T_4 V_100 ;
int V_101 ;
int V_32 ;
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , V_26 , & V_95 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_14 = F_6 ( V_4 -> V_18 -> V_60 ,
V_61 , V_88 ,
NULL , & V_26 , V_95 ) ;
if ( V_14 != V_21 )
goto V_62;
V_91 = NULL ;
V_94 = V_26 / sizeof( void * ) ;
for ( V_32 = 0 ; V_32 < V_94 ; V_32 ++ ) {
struct V_102 * V_103 ;
T_8 V_104 = V_105 ;
bool V_106 = false ;
void * V_107 ;
void * V_63 = V_95 [ V_32 ] ;
V_14 = F_5 ( V_4 -> V_18 -> V_67 ,
V_63 , V_88 , & V_90 ) ;
if ( V_14 != V_21 )
continue;
V_14 = F_5 ( V_4 -> V_18 -> V_67 ,
V_63 , & V_104 , & V_107 ) ;
if ( V_14 == V_21 )
V_106 = true ;
V_14 = F_11 ( V_90 -> V_108 , V_90 ,
V_90 -> V_109 -> V_109 , & V_26 , & V_103 ) ;
if ( V_14 == V_21 && ( ! V_91 || V_106 ) ) {
V_96 = V_103 -> V_110 ;
V_97 = V_103 -> V_111 ;
V_98 = V_90 -> V_109 -> V_112 ;
V_99 = V_90 -> V_109 -> V_113 ;
V_101 = V_103 -> V_101 ;
V_93 = V_103 -> V_114 ;
V_100 = V_103 -> V_100 ;
V_91 = V_90 ;
if ( V_106 )
break;
}
}
if ( ! V_91 )
goto V_62;
V_87 -> V_115 = V_116 ;
V_87 -> V_117 = V_96 ;
V_87 -> V_118 = V_97 ;
V_87 -> V_119 = V_98 ;
V_87 -> V_120 = 1 ;
if ( V_101 == V_121 ) {
V_87 -> V_122 = 32 ;
V_87 -> V_123 = V_100 * 4 ;
V_87 -> V_124 = 8 ;
V_87 -> V_125 = 0 ;
V_87 -> V_126 = 8 ;
V_87 -> V_127 = 8 ;
V_87 -> V_128 = 8 ;
V_87 -> V_129 = 16 ;
V_87 -> V_130 = 8 ;
V_87 -> V_131 = 24 ;
} else if ( V_101 == V_132 ) {
V_87 -> V_122 = 32 ;
V_87 -> V_123 = V_100 * 4 ;
V_87 -> V_124 = 8 ;
V_87 -> V_125 = 16 ;
V_87 -> V_126 = 8 ;
V_87 -> V_127 = 8 ;
V_87 -> V_128 = 8 ;
V_87 -> V_129 = 0 ;
V_87 -> V_130 = 8 ;
V_87 -> V_131 = 24 ;
} else if ( V_101 == V_133 ) {
F_14 ( V_93 . V_134 , & V_87 -> V_125 , & V_87 -> V_124 ) ;
F_14 ( V_93 . V_135 , & V_87 -> V_127 ,
& V_87 -> V_126 ) ;
F_14 ( V_93 . V_136 , & V_87 -> V_129 , & V_87 -> V_128 ) ;
F_14 ( V_93 . V_137 , & V_87 -> V_131 ,
& V_87 -> V_130 ) ;
V_87 -> V_122 = V_87 -> V_124 + V_87 -> V_126 +
V_87 -> V_128 + V_87 -> V_130 ;
V_87 -> V_123 = ( V_100 * V_87 -> V_122 ) / 8 ;
} else {
V_87 -> V_122 = 4 ;
V_87 -> V_123 = V_87 -> V_117 / 2 ;
V_87 -> V_124 = 0 ;
V_87 -> V_125 = 0 ;
V_87 -> V_126 = 0 ;
V_87 -> V_127 = 0 ;
V_87 -> V_128 = 0 ;
V_87 -> V_129 = 0 ;
V_87 -> V_130 = 0 ;
V_87 -> V_131 = 0 ;
}
V_87 -> V_138 = V_87 -> V_123 * V_87 -> V_118 ;
V_87 -> V_139 |= V_140 ;
V_62:
F_7 ( V_4 -> V_18 -> V_25 , V_95 ) ;
return V_14 ;
}
static T_2 F_18 ( struct V_86 * V_87 , T_8 * V_141 ,
unsigned long V_26 )
{
struct V_142 * V_143 , * V_144 ;
unsigned long V_145 ;
T_2 V_14 ;
T_4 V_96 , V_97 ;
void * * V_146 = NULL ;
int V_32 ;
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , V_26 , & V_146 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_14 = F_6 ( V_4 -> V_18 -> V_60 ,
V_61 , V_141 ,
NULL , & V_26 , V_146 ) ;
if ( V_14 != V_21 )
goto V_62;
V_144 = NULL ;
V_145 = V_26 / sizeof( void * ) ;
for ( V_32 = 0 ; V_32 < V_145 ; V_32 ++ ) {
T_8 V_147 = V_54 ;
void * V_148 = V_146 [ V_32 ] ;
T_4 V_149 , V_63 , V_150 , V_151 ;
void * V_152 ;
V_14 = F_5 ( V_4 -> V_18 -> V_67 ,
V_148 , V_141 , & V_143 ) ;
if ( V_14 != V_21 )
continue;
F_5 ( V_4 -> V_18 -> V_67 ,
V_148 , & V_147 , & V_152 ) ;
V_14 = F_6 ( V_143 -> V_153 , V_143 , & V_149 , & V_63 ,
& V_150 , & V_151 ) ;
if ( V_14 == V_21 && ( ! V_144 || V_152 ) ) {
V_96 = V_149 ;
V_97 = V_63 ;
if ( V_152 )
break;
V_144 = V_143 ;
}
}
if ( ! V_144 )
goto V_62;
V_87 -> V_115 = V_116 ;
V_87 -> V_122 = 32 ;
V_87 -> V_117 = V_96 ;
V_87 -> V_118 = V_97 ;
V_87 -> V_124 = 8 ;
V_87 -> V_125 = 16 ;
V_87 -> V_126 = 8 ;
V_87 -> V_127 = 8 ;
V_87 -> V_128 = 8 ;
V_87 -> V_129 = 0 ;
V_87 -> V_130 = 8 ;
V_87 -> V_131 = 24 ;
V_62:
F_7 ( V_4 -> V_18 -> V_25 , V_146 ) ;
return V_14 ;
}
void F_19 ( struct V_49 * V_49 )
{
T_8 V_154 = V_155 ;
struct V_86 * V_87 ;
T_8 V_141 = V_156 ;
T_2 V_14 ;
unsigned long V_26 ;
void * * V_95 = NULL ;
void * * V_146 = NULL ;
V_87 = & V_49 -> V_86 ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_26 = 0 ;
V_14 = F_6 ( V_4 -> V_18 -> V_60 ,
V_61 , & V_154 ,
NULL , & V_26 , V_95 ) ;
if ( V_14 == V_24 )
V_14 = F_17 ( V_87 , & V_154 , V_26 ) ;
if ( V_14 != V_21 ) {
V_26 = 0 ;
V_14 = F_6 ( V_4 -> V_18 -> V_60 ,
V_61 , & V_141 ,
NULL , & V_26 , V_146 ) ;
if ( V_14 == V_24 )
F_18 ( V_87 , & V_141 , V_26 ) ;
}
}
static T_2 F_20 ( T_11 * V_157 ,
struct V_158 * V_58 )
{
struct V_159 * V_160 ;
unsigned long V_161 ;
T_8 V_162 = V_163 ;
T_5 V_164 ;
T_12 * V_165 ;
T_13 * V_166 ;
T_2 V_14 ;
int V_167 ;
char * V_1 ;
int V_32 , V_168 , V_169 ;
V_161 = 0 ;
V_164 = 0 ;
V_1 = ( char * ) ( unsigned long ) V_58 -> V_170 ;
V_168 = 0 ;
if ( ! V_1 || ! * V_1 )
return V_21 ;
for ( V_167 = 0 ; * V_1 ; V_167 ++ ) {
V_1 = strstr ( V_1 , L_1 ) ;
if ( ! V_1 )
break;
V_1 += 7 ;
while ( * V_1 == '/' || * V_1 == '\\' )
V_1 ++ ;
while ( * V_1 && * V_1 != ' ' && * V_1 != '\n' )
V_1 ++ ;
}
if ( ! V_167 )
return V_21 ;
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 ,
V_167 * sizeof( * V_160 ) ,
& V_160 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_2 ) ;
goto V_22;
}
V_1 = ( char * ) ( unsigned long ) V_58 -> V_170 ;
for ( V_32 = 0 ; V_32 < V_167 ; V_32 ++ ) {
struct V_159 * V_159 ;
T_13 * V_63 ;
T_14 * V_103 ;
T_1 V_171 [ 256 ] ;
unsigned long V_172 ;
T_8 V_173 = V_174 ;
T_1 * V_175 ;
T_5 V_176 ;
V_1 = strstr ( V_1 , L_1 ) ;
if ( ! V_1 )
break;
V_1 += 7 ;
V_159 = & V_160 [ V_32 ] ;
V_175 = V_171 ;
while ( * V_1 == '/' || * V_1 == '\\' )
V_1 ++ ;
while ( * V_1 && * V_1 != ' ' && * V_1 != '\n' ) {
if ( ( T_6 * ) V_175 >= ( T_6 * ) V_171 + sizeof( V_171 ) )
break;
if ( * V_1 == '/' ) {
* V_175 ++ = '\\' ;
* V_1 ++ ;
} else {
* V_175 ++ = * V_1 ++ ;
}
}
* V_175 = '\0' ;
if ( ! V_32 ) {
T_15 * V_18 ;
V_18 = V_4 -> V_18 ;
V_14 = F_5 ( V_18 -> V_67 ,
V_157 -> V_177 , & V_162 , & V_165 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_3 ) ;
goto V_178;
}
V_14 = F_2 ( V_165 -> V_179 , V_165 , & V_166 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_4 ) ;
goto V_178;
}
}
V_14 = F_6 ( V_166 -> V_180 , V_166 , & V_63 , V_171 ,
V_181 , ( T_5 ) 0 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_5 ) ;
F_1 ( V_171 ) ;
F_3 ( L_6 ) ;
goto V_182;
}
V_159 -> V_148 = V_63 ;
V_172 = 0 ;
V_14 = F_11 ( V_63 -> V_183 , V_63 , & V_173 ,
& V_172 , NULL ) ;
if ( V_14 != V_24 ) {
F_3 ( L_7 ) ;
goto V_182;
}
V_184:
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , V_172 , & V_103 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_8 ) ;
goto V_182;
}
V_14 = F_11 ( V_63 -> V_183 , V_63 , & V_173 ,
& V_172 , V_103 ) ;
if ( V_14 == V_24 ) {
F_7 ( V_4 -> V_18 -> V_25 , V_103 ) ;
goto V_184;
}
V_176 = V_103 -> V_185 ;
F_7 ( V_4 -> V_18 -> V_25 , V_103 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_9 ) ;
goto V_182;
}
V_159 -> V_26 = V_176 ;
V_164 += V_176 ;
}
if ( V_164 ) {
unsigned long V_28 ;
V_14 = F_8 ( V_164 , 0x1000 ,
& V_161 , V_58 -> V_186 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_10 ) ;
goto V_182;
}
if ( V_161 > V_58 -> V_186 ) {
F_3 ( L_11 ) ;
V_14 = V_187 ;
goto V_188;
}
V_28 = V_161 ;
for ( V_168 = 0 ; V_168 < V_167 ; V_168 ++ ) {
T_5 V_26 ;
V_26 = V_160 [ V_168 ] . V_26 ;
while ( V_26 ) {
T_5 V_189 ;
if ( V_26 > V_190 )
V_189 = V_190 ;
else
V_189 = V_26 ;
V_14 = F_5 ( V_166 -> V_73 ,
V_160 [ V_168 ] . V_148 ,
& V_189 , V_28 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_12 ) ;
goto V_188;
}
V_28 += V_189 ;
V_26 -= V_189 ;
}
F_7 ( V_166 -> V_191 , V_160 [ V_168 ] . V_148 ) ;
}
}
F_7 ( V_4 -> V_18 -> V_25 , V_160 ) ;
V_58 -> V_192 = V_161 ;
V_58 -> V_193 = V_164 ;
return V_14 ;
V_188:
F_13 ( V_164 , V_161 ) ;
V_182:
for ( V_169 = V_168 ; V_169 < V_32 ; V_169 ++ )
F_7 ( V_166 -> V_191 , V_160 [ V_169 ] . V_148 ) ;
V_178:
F_7 ( V_4 -> V_18 -> V_25 , V_160 ) ;
V_22:
V_58 -> V_192 = 0 ;
V_58 -> V_193 = 0 ;
return V_14 ;
}
struct V_49 * F_21 ( void * V_148 , T_16 * V_194 )
{
struct V_49 * V_49 ;
struct V_195 * V_196 ;
struct V_197 * V_198 ;
struct V_158 * V_58 ;
struct V_199 * V_200 ;
T_11 * V_157 ;
void * V_201 ;
T_4 V_202 ;
T_8 V_88 = V_203 ;
int V_204 = 0 ;
T_2 V_14 ;
unsigned long V_205 ;
T_10 * V_206 ;
T_6 * V_207 ;
int V_32 ;
V_4 = V_194 ;
if ( V_4 -> V_58 . V_208 != V_209 )
return NULL ;
V_14 = F_5 ( V_4 -> V_18 -> V_67 ,
V_148 , & V_88 , ( void * ) & V_157 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_13 ) ;
return NULL ;
}
V_14 = F_12 ( 0x4000 , 1 , ( unsigned long * ) & V_49 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_14 ) ;
return NULL ;
}
memset ( V_49 , 0x0 , 0x4000 ) ;
V_58 = & V_49 -> V_58 ;
V_200 = & V_49 -> V_199 ;
V_198 = & V_49 -> V_197 ;
V_196 = & V_49 -> V_195 ;
memcpy ( & V_58 -> V_210 , V_157 -> V_211 + 512 , 512 ) ;
V_58 -> V_212 = 1 ;
V_58 -> V_213 = 0xffff ;
V_58 -> V_214 = 0xAA55 ;
V_58 -> V_215 = ( V_216 ) ( unsigned long ) V_157 -> V_211 ;
V_58 -> V_217 = 0x21 ;
V_201 = V_157 -> V_218 ;
V_202 = V_157 -> V_202 / 2 ;
V_205 = 0 ;
V_206 = ( T_10 * ) V_201 ;
if ( V_206 ) {
while ( * V_206 && * V_206 != '\n' && V_204 < V_202 ) {
V_206 ++ ;
V_204 ++ ;
}
if ( V_204 ) {
if ( V_204 > V_58 -> V_219 )
V_204 = V_58 -> V_219 ;
V_204 ++ ;
V_14 = F_12 ( V_204 , 1 , & V_205 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_15 ) ;
goto V_22;
}
V_207 = ( T_6 * ) ( unsigned long ) V_205 ;
V_206 = ( T_10 * ) V_201 ;
for ( V_32 = 0 ; V_32 < V_204 - 1 ; V_32 ++ )
* V_207 ++ = * V_206 ++ ;
* V_207 = '\0' ;
}
}
V_58 -> V_170 = V_205 ;
V_58 -> V_192 = 0 ;
V_58 -> V_193 = 0 ;
memset ( V_198 , 0 , sizeof( * V_198 ) ) ;
memset ( V_196 , 0 , sizeof( * V_196 ) ) ;
V_14 = F_20 ( V_157 , V_58 ) ;
if ( V_14 != V_21 )
goto V_220;
return V_49 ;
V_220:
if ( V_204 )
F_13 ( V_204 , V_58 -> V_170 ) ;
V_22:
F_13 ( 0x4000 , ( unsigned long ) V_49 ) ;
return NULL ;
}
static T_2 F_22 ( struct V_49 * V_49 ,
void * V_148 )
{
struct V_199 * V_200 = & V_49 -> V_199 ;
struct V_221 * V_222 = & V_49 -> V_222 [ 0 ] ;
struct V_221 * V_223 = NULL ;
unsigned long V_26 , V_15 , V_12 , V_224 ;
T_3 * V_225 ;
T_2 V_14 ;
T_17 V_16 ;
bool V_226 = false ;
T_6 V_227 ;
int V_32 ;
V_26 = sizeof( * V_225 ) * 32 ;
V_17:
V_26 += sizeof( * V_225 ) * 2 ;
V_224 = V_26 ;
V_14 = F_12 ( V_26 , 1 , ( unsigned long * ) & V_225 ) ;
if ( V_14 != V_21 )
return V_14 ;
V_228:
V_14 = F_6 ( V_4 -> V_18 -> V_23 , & V_26 ,
V_225 , & V_15 , & V_12 , & V_16 ) ;
if ( V_14 == V_24 ) {
F_13 ( V_224 , ( unsigned long ) V_225 ) ;
goto V_17;
}
if ( V_14 != V_21 )
goto V_229;
memcpy ( & V_200 -> V_230 , V_231 , sizeof( T_17 ) ) ;
V_200 -> V_232 = ( unsigned long ) V_4 ;
V_200 -> V_233 = V_12 ;
V_200 -> V_234 = V_16 ;
V_200 -> V_235 = ( unsigned long ) V_225 ;
V_200 -> V_236 = V_26 ;
#ifdef F_16
V_200 -> V_237 = ( unsigned long ) V_4 >> 32 ;
V_200 -> V_238 = ( unsigned long ) V_225 >> 32 ;
#endif
V_14 = F_2 ( V_4 -> V_18 -> V_239 ,
V_148 , V_15 ) ;
if ( V_14 != V_21 ) {
if ( V_226 )
goto V_229;
V_226 = true ;
goto V_228;
}
V_49 -> V_240 = 32 * 1024 ;
V_227 = 0 ;
for ( V_32 = 0 ; V_32 < V_26 / V_12 ; V_32 ++ ) {
T_3 * V_241 ;
unsigned int V_242 = 0 ;
unsigned long V_13 = ( unsigned long ) V_225 ;
V_241 = ( T_3 * ) ( V_13 + ( V_32 * V_12 ) ) ;
switch ( V_241 -> type ) {
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
V_242 = V_249 ;
break;
case V_250 :
V_242 = V_251 ;
break;
case V_252 :
V_242 = V_253 ;
break;
case V_254 :
case V_20 :
case V_255 :
case V_256 :
case V_37 :
V_242 = V_257 ;
break;
case V_258 :
V_242 = V_259 ;
break;
default:
continue;
}
if ( V_223 && V_223 -> type == V_242 &&
( V_223 -> V_28 + V_223 -> V_26 ) == V_241 -> V_39 )
V_223 -> V_26 += V_241 -> V_38 << 12 ;
else {
V_222 -> V_28 = V_241 -> V_39 ;
V_222 -> V_26 = V_241 -> V_38 << 12 ;
V_222 -> type = V_242 ;
V_223 = V_222 ++ ;
V_227 ++ ;
}
}
V_49 -> V_260 = V_227 ;
return V_21 ;
V_229:
F_13 ( V_224 , ( unsigned long ) V_225 ) ;
return V_14 ;
}
static T_2 F_23 ( struct V_158 * V_58 )
{
unsigned long V_35 , V_30 ;
T_2 V_14 ;
V_35 = V_58 -> V_261 ;
V_30 = F_9 ( V_58 -> V_262 , V_33 ) / V_33 ;
V_14 = F_11 ( V_4 -> V_18 -> V_42 ,
V_43 , V_20 ,
V_30 , & V_35 ) ;
if ( V_14 != V_21 ) {
V_14 = F_12 ( V_58 -> V_262 , V_58 -> V_263 ,
& V_35 ) ;
if ( V_14 != V_21 )
F_3 ( L_16 ) ;
}
if ( V_14 == V_21 )
memcpy ( ( void * ) V_35 , ( void * ) ( unsigned long ) V_58 -> V_215 ,
V_58 -> V_262 ) ;
V_58 -> V_261 = V_58 -> V_215 ;
V_58 -> V_215 = ( T_17 ) V_35 ;
return V_14 ;
}
struct V_49 * F_24 ( void * V_148 , T_16 * V_194 ,
struct V_49 * V_49 )
{
struct V_264 * V_265 , * V_266 ;
T_11 * V_157 ;
struct V_158 * V_58 = & V_49 -> V_58 ;
T_2 V_14 ;
struct V_267 * V_34 ;
V_4 = V_194 ;
if ( V_4 -> V_58 . V_208 != V_209 )
goto V_22;
F_19 ( V_49 ) ;
F_15 ( V_49 ) ;
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , sizeof( * V_265 ) ,
( void * * ) & V_265 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_17 ) ;
goto V_22;
}
V_265 -> V_26 = 0x800 ;
V_14 = F_12 ( V_265 -> V_26 , 8 , ( unsigned long * ) & V_265 -> V_268 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_18 ) ;
goto V_22;
}
V_14 = F_5 ( V_4 -> V_18 -> V_19 ,
V_20 , sizeof( * V_266 ) ,
( void * * ) & V_266 ) ;
if ( V_14 != V_21 ) {
F_3 ( L_19 ) ;
goto V_22;
}
V_266 -> V_26 = 0 ;
V_266 -> V_268 = 0 ;
if ( V_58 -> V_261 != V_58 -> V_215 ) {
V_14 = F_23 ( V_58 ) ;
if ( V_14 != V_21 )
goto V_22;
}
V_14 = F_22 ( V_49 , V_148 ) ;
if ( V_14 != V_21 )
goto V_22;
memset ( ( char * ) V_265 -> V_268 , 0x0 , V_265 -> V_26 ) ;
V_34 = (struct V_267 * ) V_265 -> V_268 ;
V_34 += 2 ;
V_34 -> V_269 = 0xffff ;
V_34 -> V_270 = 0x0000 ;
V_34 -> V_271 = 0x0000 ;
V_34 -> type = V_272 | V_273 ;
V_34 -> V_274 = V_275 ;
V_34 -> V_276 = 0 ;
V_34 -> V_175 = 1 ;
V_34 -> V_277 = 0xf ;
V_34 -> V_278 = 0 ;
V_34 -> V_279 = 0 ;
V_34 -> V_241 = V_280 ;
V_34 -> V_281 = V_282 ;
V_34 -> V_283 = 0x00 ;
V_34 ++ ;
V_34 -> V_269 = 0xffff ;
V_34 -> V_270 = 0x0000 ;
V_34 -> V_271 = 0x0000 ;
V_34 -> type = V_284 | V_285 ;
V_34 -> V_274 = V_275 ;
V_34 -> V_276 = 0 ;
V_34 -> V_175 = 1 ;
V_34 -> V_277 = 0xf ;
V_34 -> V_278 = 0 ;
V_34 -> V_279 = 0 ;
V_34 -> V_241 = V_280 ;
V_34 -> V_281 = V_282 ;
V_34 -> V_283 = 0x00 ;
#ifdef F_16
V_34 ++ ;
V_34 -> V_269 = 0x0000 ;
V_34 -> V_270 = 0x0000 ;
V_34 -> V_271 = 0x0000 ;
V_34 -> type = V_286 ;
V_34 -> V_274 = 0 ;
V_34 -> V_276 = 0 ;
V_34 -> V_175 = 1 ;
V_34 -> V_277 = 0x0 ;
V_34 -> V_278 = 0 ;
V_34 -> V_279 = 0 ;
V_34 -> V_241 = 0 ;
V_34 -> V_281 = V_282 ;
V_34 -> V_283 = 0x00 ;
#endif
asm volatile ("lidt %0" : : "m" (*idt));
asm volatile ("lgdt %0" : : "m" (*gdt));
asm volatile("cli");
return V_49 ;
V_22:
return NULL ;
}
