static inline T_1 F_1 ( void * V_1 , void * * V_2 )
{
T_2 * V_3 ;
T_3 * V_4 = V_1 ;
T_4 * V_5 ;
T_5 V_6 = V_7 ;
T_1 V_8 ;
void * V_9 = ( void * ) ( unsigned long ) V_4 -> V_10 ;
unsigned long V_11 ;
V_8 = F_2 ( V_12 , V_9 ,
& V_6 , ( void * * ) & V_3 ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_1 ) ;
return V_8 ;
}
V_11 = ( unsigned long ) V_3 -> V_15 ;
V_8 = V_16 -> V_17 ( V_11 , V_3 , & V_5 ) ;
if ( V_8 != V_13 )
F_3 ( V_14 , L_2 ) ;
* V_2 = V_5 ;
return V_8 ;
}
static inline T_1 F_4 ( void * V_1 , void * * V_2 )
{
T_2 * V_3 ;
T_6 * V_4 = V_1 ;
T_7 * V_5 ;
T_5 V_6 = V_7 ;
T_1 V_8 ;
void * V_9 = ( void * ) ( unsigned long ) V_4 -> V_10 ;
unsigned long V_11 ;
V_8 = F_2 ( V_12 , V_9 ,
& V_6 , ( void * * ) & V_3 ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_1 ) ;
return V_8 ;
}
V_11 = ( unsigned long ) V_3 -> V_15 ;
V_8 = V_16 -> V_17 ( V_11 , V_3 , & V_5 ) ;
if ( V_8 != V_13 )
F_3 ( V_14 , L_2 ) ;
* V_2 = V_5 ;
return V_8 ;
}
T_1
F_5 ( T_8 * V_14 , void * V_1 , void * * V_2 )
{
if ( V_16 -> V_18 )
return F_4 ( V_1 , V_2 ) ;
return F_1 ( V_1 , V_2 ) ;
}
void F_6 ( T_8 * V_19 , T_9 * V_20 )
{
F_7 ( V_21 , V_22 ,
V_16 -> V_23 , V_20 ) ;
}
static T_1
F_8 ( T_10 * V_24 , struct V_25 * * V_26 )
{
struct V_25 * V_27 = NULL ;
T_1 V_8 ;
unsigned long V_28 ;
T_11 V_29 ;
V_8 = V_16 -> V_17 ( V_24 -> V_29 , V_24 ,
V_30 , 0 , 0 ,
& V_29 ) ;
if ( V_8 != V_13 )
return V_8 ;
if ( ! V_24 -> V_31 || ! V_24 -> V_32 )
return V_33 ;
V_28 = V_24 -> V_32 + sizeof( * V_27 ) ;
V_8 = F_2 ( V_34 , V_35 , V_28 , & V_27 ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_3 ) ;
return V_8 ;
}
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_36 . type = V_37 ;
V_27 -> V_36 . V_38 = V_28 - sizeof( struct V_39 ) ;
V_27 -> V_36 . V_40 = 0 ;
V_27 -> V_41 = V_24 -> V_32 ;
* V_26 = V_27 ;
V_8 = V_16 -> V_17 ( V_24 -> V_24 . V_42 , V_24 , V_43 ,
V_44 , 1 , & ( V_27 -> V_45 ) ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_4 ) ;
goto V_46;
}
V_8 = V_16 -> V_17 ( V_24 -> V_24 . V_42 , V_24 , V_43 ,
V_47 , 1 , & ( V_27 -> V_48 ) ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_5 ) ;
goto V_46;
}
V_8 = V_16 -> V_17 ( V_24 -> V_49 , V_24 , & ( V_27 -> V_50 ) ,
& ( V_27 -> V_51 ) , & ( V_27 -> V_52 ) , & ( V_27 -> V_53 ) ) ;
if ( V_8 != V_13 )
goto V_46;
memcpy ( V_27 -> V_54 , V_24 -> V_31 , V_24 -> V_32 ) ;
return V_8 ;
V_46:
F_2 ( V_55 , V_27 ) ;
return V_8 ;
}
static void
F_9 ( struct V_56 * V_57 , void * * V_58 ,
unsigned long V_28 )
{
T_10 * V_24 = NULL ;
T_5 V_59 = V_60 ;
T_12 * V_61 = ( T_12 * ) ( unsigned long ) V_58 ;
T_1 V_8 ;
unsigned long V_62 ;
struct V_39 * V_36 ;
int V_63 ;
V_36 = (struct V_39 * ) ( unsigned long ) V_57 -> V_64 . V_39 ;
while ( V_36 && V_36 -> V_40 )
V_36 = (struct V_39 * ) ( unsigned long ) V_36 -> V_40 ;
V_62 = V_28 / sizeof( T_12 ) ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
struct V_25 * V_27 = NULL ;
T_12 V_65 = V_61 [ V_63 ] ;
V_8 = F_2 ( V_12 , V_65 ,
& V_59 , ( void * * ) & V_24 ) ;
if ( V_8 != V_13 )
continue;
if ( ! V_24 )
continue;
V_8 = F_8 ( V_24 , & V_27 ) ;
if ( V_8 != V_13 )
continue;
if ( V_36 )
V_36 -> V_40 = ( unsigned long ) V_27 ;
else
V_57 -> V_64 . V_39 = ( unsigned long ) V_27 ;
V_36 = (struct V_39 * ) V_27 ;
}
}
static T_1
F_10 ( T_13 * V_24 , struct V_25 * * V_26 )
{
struct V_25 * V_27 ;
T_1 V_8 ;
unsigned long V_28 ;
T_11 V_29 ;
V_8 = V_16 -> V_17 ( V_24 -> V_29 , V_24 ,
V_30 , 0 ,
& V_29 ) ;
if ( V_8 != V_13 )
return V_8 ;
if ( ! V_24 -> V_31 || ! V_24 -> V_32 )
return V_33 ;
V_28 = V_24 -> V_32 + sizeof( * V_27 ) ;
V_8 = F_2 ( V_34 , V_35 , V_28 , & V_27 ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_3 ) ;
return V_8 ;
}
V_27 -> V_36 . type = V_37 ;
V_27 -> V_36 . V_38 = V_28 - sizeof( struct V_39 ) ;
V_27 -> V_36 . V_40 = 0 ;
V_27 -> V_41 = V_24 -> V_32 ;
* V_26 = V_27 ;
V_8 = V_16 -> V_17 ( V_24 -> V_24 . V_42 , V_24 , V_43 ,
V_44 , 1 , & ( V_27 -> V_45 ) ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_4 ) ;
goto V_46;
}
V_8 = V_16 -> V_17 ( V_24 -> V_24 . V_42 , V_24 , V_43 ,
V_47 , 1 , & ( V_27 -> V_48 ) ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_5 ) ;
goto V_46;
}
V_8 = V_16 -> V_17 ( V_24 -> V_49 , V_24 , & ( V_27 -> V_50 ) ,
& ( V_27 -> V_51 ) , & ( V_27 -> V_52 ) , & ( V_27 -> V_53 ) ) ;
if ( V_8 != V_13 )
goto V_46;
memcpy ( V_27 -> V_54 , V_24 -> V_31 , V_24 -> V_32 ) ;
return V_8 ;
V_46:
F_2 ( V_55 , V_27 ) ;
return V_8 ;
}
static void
F_11 ( struct V_56 * V_57 , void * * V_58 ,
unsigned long V_28 )
{
T_13 * V_24 = NULL ;
T_5 V_59 = V_60 ;
T_14 * V_61 = ( T_14 * ) ( unsigned long ) V_58 ;
T_1 V_8 ;
unsigned long V_62 ;
struct V_39 * V_36 ;
int V_63 ;
V_36 = (struct V_39 * ) ( unsigned long ) V_57 -> V_64 . V_39 ;
while ( V_36 && V_36 -> V_40 )
V_36 = (struct V_39 * ) ( unsigned long ) V_36 -> V_40 ;
V_62 = V_28 / sizeof( T_14 ) ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
struct V_25 * V_27 = NULL ;
T_14 V_65 = V_61 [ V_63 ] ;
V_8 = F_2 ( V_12 , V_65 ,
& V_59 , ( void * * ) & V_24 ) ;
if ( V_8 != V_13 )
continue;
if ( ! V_24 )
continue;
V_8 = F_10 ( V_24 , & V_27 ) ;
if ( V_8 != V_13 )
continue;
if ( V_36 )
V_36 -> V_40 = ( unsigned long ) V_27 ;
else
V_57 -> V_64 . V_39 = ( unsigned long ) V_27 ;
V_36 = (struct V_39 * ) V_27 ;
}
}
static void F_12 ( struct V_56 * V_57 )
{
T_1 V_8 ;
void * * V_58 = NULL ;
T_5 V_59 = V_60 ;
unsigned long V_28 = 0 ;
V_8 = F_2 ( V_66 ,
V_67 ,
& V_59 , NULL , & V_28 , V_58 ) ;
if ( V_8 == V_68 ) {
V_8 = F_2 ( V_34 ,
V_35 ,
V_28 , ( void * * ) & V_58 ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_6 ) ;
return;
}
V_8 = F_2 ( V_66 ,
V_67 , & V_59 ,
NULL , & V_28 , V_58 ) ;
}
if ( V_8 != V_13 )
goto V_69;
if ( V_16 -> V_18 )
F_11 ( V_57 , V_58 , V_28 ) ;
else
F_9 ( V_57 , V_58 , V_28 ) ;
V_69:
F_2 ( V_55 , V_58 ) ;
}
static void F_13 ( struct V_56 * V_56 )
{
T_5 V_70 = V_71 ;
struct V_39 * V_36 , * V_72 ;
T_1 V_8 ;
T_12 V_28 = 0 ;
void * V_73 ;
V_8 = F_2 ( V_74 , & V_70 , NULL , & V_73 ) ;
if ( V_8 != V_13 )
return;
if ( F_14 ( V_75 , V_76 , V_73 ) != 0x10000 ) {
F_3 ( V_14 , L_7 ) ;
return;
}
F_7 ( V_75 , V_77 , V_73 , NULL , & V_28 ) ;
if ( ! V_28 )
return;
do {
V_8 = F_2 ( V_34 , V_35 ,
V_28 + sizeof( struct V_39 ) , & V_72 ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 ,
L_8 ) ;
return;
}
V_8 = F_7 ( V_75 , V_77 , V_73 ,
V_72 -> V_36 , & V_28 ) ;
if ( V_8 == V_68 )
F_2 ( V_55 , V_72 ) ;
} while ( V_8 == V_68 );
V_72 -> type = V_78 ;
V_72 -> V_38 = V_28 ;
V_72 -> V_40 = 0 ;
V_36 = (struct V_39 * ) ( unsigned long ) V_56 -> V_64 . V_39 ;
if ( ! V_36 )
V_56 -> V_64 . V_39 = ( unsigned long ) V_72 ;
else {
while ( V_36 -> V_40 )
V_36 = (struct V_39 * ) ( unsigned long ) V_36 -> V_40 ;
V_36 -> V_40 = ( unsigned long ) V_72 ;
}
}
static void F_15 ( struct V_56 * V_56 )
{
T_9 const V_79 [] = { 'A' , 'p' , 'p' , 'l' , 'e' , 0 } ;
T_9 * V_80 = ( T_9 * ) ( unsigned long )
F_14 ( V_81 , V_80 , V_14 ) ;
if ( ! memcmp ( V_80 , V_79 , sizeof( V_79 ) ) ) {
if ( F_16 ( V_82 ) )
F_13 ( V_56 ) ;
}
}
static T_1
F_17 ( void * * V_83 , unsigned long V_28 , T_12 * V_84 , T_12 * V_85 )
{
struct V_86 * V_87 = NULL , * V_88 ;
T_5 V_89 = V_90 ;
unsigned long V_91 ;
T_12 * V_61 = ( T_12 * ) V_83 ; ;
T_1 V_8 = V_33 ;
int V_63 ;
V_88 = NULL ;
V_91 = V_28 / sizeof( T_12 ) ;
for ( V_63 = 0 ; V_63 < V_91 ; V_63 ++ ) {
T_5 V_92 = V_60 ;
T_12 V_93 , V_65 , V_94 , V_95 ;
void * V_96 ;
T_12 V_9 = V_61 [ V_63 ] ;
V_8 = F_2 ( V_12 , V_9 ,
& V_89 , ( void * * ) & V_87 ) ;
if ( V_8 != V_13 )
continue;
F_2 ( V_12 , V_9 , & V_92 , & V_96 ) ;
V_8 = V_16 -> V_17 ( ( unsigned long ) V_87 -> V_97 , V_87 ,
& V_93 , & V_65 , & V_94 , & V_95 ) ;
if ( V_8 == V_13 && ( ! V_88 || V_96 ) ) {
* V_84 = V_93 ;
* V_85 = V_65 ;
if ( V_96 )
break;
V_88 = V_87 ;
}
}
return V_8 ;
}
static T_1
F_18 ( void * * V_83 , unsigned long V_28 , T_12 * V_84 , T_12 * V_85 )
{
struct V_86 * V_87 = NULL , * V_88 ;
T_5 V_89 = V_90 ;
unsigned long V_91 ;
T_14 * V_61 = ( T_14 * ) V_83 ; ;
T_1 V_8 = V_33 ;
int V_63 ;
V_88 = NULL ;
V_91 = V_28 / sizeof( T_14 ) ;
for ( V_63 = 0 ; V_63 < V_91 ; V_63 ++ ) {
T_5 V_92 = V_60 ;
T_12 V_93 , V_65 , V_94 , V_95 ;
void * V_96 ;
T_14 V_9 = V_61 [ V_63 ] ;
V_8 = F_2 ( V_12 , V_9 ,
& V_89 , ( void * * ) & V_87 ) ;
if ( V_8 != V_13 )
continue;
F_2 ( V_12 , V_9 , & V_92 , & V_96 ) ;
V_8 = V_16 -> V_17 ( ( unsigned long ) V_87 -> V_97 , V_87 ,
& V_93 , & V_65 , & V_94 , & V_95 ) ;
if ( V_8 == V_13 && ( ! V_88 || V_96 ) ) {
* V_84 = V_93 ;
* V_85 = V_65 ;
if ( V_96 )
break;
V_88 = V_87 ;
}
}
return V_8 ;
}
static T_1 F_19 ( struct V_98 * V_99 , T_5 * V_89 ,
unsigned long V_28 )
{
T_1 V_8 ;
T_12 V_84 , V_85 ;
void * * V_83 = NULL ;
V_8 = F_2 ( V_34 , V_35 ,
V_28 , ( void * * ) & V_83 ) ;
if ( V_8 != V_13 )
return V_8 ;
V_8 = F_2 ( V_66 ,
V_67 ,
V_89 , NULL , & V_28 , V_83 ) ;
if ( V_8 != V_13 )
goto V_69;
V_85 = 0 ;
V_84 = 0 ;
if ( V_16 -> V_18 )
V_8 = F_18 ( V_83 , V_28 , & V_84 , & V_85 ) ;
else
V_8 = F_17 ( V_83 , V_28 , & V_84 , & V_85 ) ;
if ( ! V_84 && ! V_85 )
goto V_69;
V_99 -> V_100 = V_101 ;
V_99 -> V_102 = 32 ;
V_99 -> V_103 = V_84 ;
V_99 -> V_104 = V_85 ;
V_99 -> V_105 = 8 ;
V_99 -> V_106 = 16 ;
V_99 -> V_107 = 8 ;
V_99 -> V_108 = 8 ;
V_99 -> V_109 = 8 ;
V_99 -> V_110 = 0 ;
V_99 -> V_111 = 8 ;
V_99 -> V_112 = 24 ;
V_69:
F_2 ( V_55 , V_83 ) ;
return V_8 ;
}
void F_20 ( struct V_56 * V_56 )
{
T_5 V_113 = V_114 ;
struct V_98 * V_99 ;
T_5 V_89 = V_90 ;
T_1 V_8 ;
unsigned long V_28 ;
void * * V_115 = NULL ;
void * * V_83 = NULL ;
V_99 = & V_56 -> V_98 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
V_28 = 0 ;
V_8 = F_2 ( V_66 ,
V_67 ,
& V_113 , NULL , & V_28 , V_115 ) ;
if ( V_8 == V_68 )
V_8 = F_21 ( NULL , V_99 , & V_113 , V_28 ) ;
if ( V_8 != V_13 ) {
V_28 = 0 ;
V_8 = F_2 ( V_66 ,
V_67 ,
& V_89 , NULL , & V_28 , V_83 ) ;
if ( V_8 == V_68 )
F_19 ( V_99 , & V_89 , V_28 ) ;
}
}
struct V_56 * F_22 ( struct V_116 * V_117 )
{
struct V_56 * V_56 ;
struct V_118 * V_119 ;
struct V_120 * V_64 ;
T_15 * V_4 ;
void * V_121 , * V_9 ;
T_5 V_122 = V_123 ;
int V_124 = 0 ;
T_1 V_8 ;
char * V_125 ;
T_16 * V_126 ;
T_17 * V_127 ;
int V_63 ;
unsigned long V_128 ;
unsigned long V_129 ;
V_16 = V_117 ;
V_14 = ( T_8 * ) ( unsigned long ) V_16 -> V_19 ;
V_9 = ( void * ) ( unsigned long ) V_16 -> V_130 ;
if ( V_14 -> V_64 . V_131 != V_132 )
return NULL ;
if ( V_16 -> V_18 )
F_23 ( V_16 ) ;
else
F_24 ( V_16 ) ;
V_8 = F_2 ( V_12 , V_9 ,
& V_122 , ( void * ) & V_4 ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_9 ) ;
return NULL ;
}
V_8 = F_25 ( V_14 , 0x4000 , 1 ,
( unsigned long * ) & V_56 ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_10 ) ;
return NULL ;
}
memset ( V_56 , 0x0 , 0x4000 ) ;
V_64 = & V_56 -> V_64 ;
V_119 = & V_56 -> V_118 ;
memcpy ( & V_64 -> V_133 , V_4 -> V_134 + 512 , 512 ) ;
V_64 -> V_135 = 1 ;
V_64 -> V_136 = 0xffff ;
V_64 -> V_137 = 0xAA55 ;
V_64 -> V_138 = 0x21 ;
V_125 = F_26 ( V_14 , V_4 , & V_124 ) ;
if ( ! V_125 )
goto V_139;
V_64 -> V_140 = ( unsigned long ) V_125 ;
V_56 -> V_141 = ( T_14 ) ( unsigned long ) V_125 >> 32 ;
V_64 -> V_142 = 0 ;
V_64 -> V_129 = 0 ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
V_8 = F_27 ( V_125 ) ;
if ( V_8 != V_13 )
goto V_143;
V_8 = F_28 ( V_14 , V_4 ,
( char * ) ( unsigned long ) V_64 -> V_140 ,
L_11 , V_64 -> V_144 ,
& V_128 , & V_129 ) ;
if ( V_8 != V_13 &&
V_64 -> V_145 & V_146 ) {
F_3 ( V_14 , L_12 ) ;
V_8 = F_28 ( V_14 , V_4 ,
( char * ) ( unsigned long ) V_64 -> V_140 ,
L_11 , - 1UL ,
& V_128 , & V_129 ) ;
}
if ( V_8 != V_13 )
goto V_143;
V_64 -> V_142 = V_128 & 0xffffffff ;
V_64 -> V_129 = V_129 & 0xffffffff ;
V_56 -> V_147 = ( T_14 ) V_128 >> 32 ;
V_56 -> V_148 = ( T_14 ) V_129 >> 32 ;
return V_56 ;
V_143:
F_29 ( V_14 , V_124 , V_64 -> V_140 ) ;
V_139:
F_29 ( V_14 , 0x4000 , ( unsigned long ) V_56 ) ;
return NULL ;
}
static void F_30 ( struct V_56 * V_57 ,
struct V_39 * V_149 , T_12 V_150 )
{
struct V_39 * V_36 ;
T_1 V_8 ;
unsigned long V_28 ;
V_149 -> type = V_151 ;
V_149 -> V_38 = V_150 * sizeof( struct V_152 ) ;
V_149 -> V_40 = 0 ;
V_36 = (struct V_39 * ) ( unsigned long ) V_57 -> V_64 . V_39 ;
while ( V_36 && V_36 -> V_40 )
V_36 = (struct V_39 * ) ( unsigned long ) V_36 -> V_40 ;
if ( V_36 )
V_36 -> V_40 = ( unsigned long ) V_149 ;
else
V_57 -> V_64 . V_39 = ( unsigned long ) V_149 ;
}
static T_1 F_31 ( struct V_56 * V_57 ,
struct V_39 * V_149 , T_12 V_153 )
{
struct V_152 * V_154 = & V_57 -> V_154 [ 0 ] ;
struct V_155 * V_156 = & V_57 -> V_155 ;
struct V_152 * V_157 = NULL ;
T_12 V_150 ;
T_12 V_158 ;
int V_63 ;
V_150 = 0 ;
V_158 = V_156 -> V_159 / V_156 -> V_160 ;
for ( V_63 = 0 ; V_63 < V_158 ; V_63 ++ ) {
T_18 * V_161 ;
unsigned int V_162 = 0 ;
unsigned long V_163 = V_156 -> V_164 ;
#ifdef F_32
V_163 |= ( T_14 ) V_156 -> V_165 << 32 ;
#endif
V_161 = ( T_18 * ) ( V_163 + ( V_63 * V_156 -> V_160 ) ) ;
switch ( V_161 -> type ) {
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
V_162 = V_172 ;
break;
case V_173 :
V_162 = V_174 ;
break;
case V_175 :
V_162 = V_176 ;
break;
case V_177 :
case V_35 :
case V_178 :
case V_179 :
case V_180 :
V_162 = V_181 ;
break;
case V_182 :
V_162 = V_183 ;
break;
case V_184 :
V_162 = V_185 ;
break;
default:
continue;
}
if ( V_157 && V_157 -> type == V_162 &&
( V_157 -> V_186 + V_157 -> V_28 ) == V_161 -> V_187 ) {
V_157 -> V_28 += V_161 -> V_188 << 12 ;
continue;
}
if ( V_150 == F_33 ( V_57 -> V_154 ) ) {
T_12 V_189 = ( V_158 - V_63 ) * sizeof( struct V_152 ) +
sizeof( struct V_39 ) ;
if ( ! V_149 || V_153 < V_189 )
return V_68 ;
V_154 = (struct V_152 * ) V_149 -> V_36 ;
}
V_154 -> V_186 = V_161 -> V_187 ;
V_154 -> V_28 = V_161 -> V_188 << V_190 ;
V_154 -> type = V_162 ;
V_157 = V_154 ++ ;
V_150 ++ ;
}
if ( V_150 > F_33 ( V_57 -> V_154 ) ) {
T_12 V_191 = V_150 - F_33 ( V_57 -> V_154 ) ;
F_30 ( V_57 , V_149 , V_191 ) ;
V_150 -= V_191 ;
}
V_57 -> V_192 = ( T_17 ) V_150 ;
return V_13 ;
}
static T_1 F_34 ( T_12 V_158 , struct V_39 * * V_149 ,
T_12 * V_153 )
{
T_1 V_8 ;
unsigned long V_28 ;
V_28 = sizeof( struct V_39 ) +
sizeof( struct V_152 ) * V_158 ;
if ( * V_149 ) {
F_2 ( V_55 , * V_149 ) ;
* V_149 = NULL ;
* V_153 = 0 ;
}
V_8 = F_2 ( V_34 , V_35 ,
V_28 , ( void * * ) V_149 ) ;
if ( V_8 == V_13 )
* V_153 = V_28 ;
return V_8 ;
}
static T_1 F_35 ( T_8 * V_193 ,
struct V_194 * V_195 ,
void * V_196 )
{
static bool V_197 = true ;
const char * V_131 ;
T_19 V_158 ;
T_1 V_8 ;
struct V_198 * V_73 = V_196 ;
if ( V_197 ) {
V_158 = * V_195 -> V_199 / * V_195 -> V_200 ;
if ( V_158 > F_33 ( V_73 -> V_56 -> V_154 ) ) {
T_12 V_191 = V_158 -
F_33 ( V_73 -> V_56 -> V_154 ) ;
V_8 = F_34 ( V_191 , & V_73 -> V_149 ,
& V_73 -> V_153 ) ;
if ( V_8 != V_13 )
return V_8 ;
}
V_197 = false ;
}
V_131 = V_73 -> V_18 ? V_201 : V_202 ;
memcpy ( & V_73 -> V_156 -> V_203 , V_131 , sizeof( T_19 ) ) ;
V_73 -> V_156 -> V_204 = ( unsigned long ) V_193 ;
V_73 -> V_156 -> V_160 = * V_195 -> V_200 ;
V_73 -> V_156 -> V_205 = * V_195 -> V_206 ;
V_73 -> V_156 -> V_164 = ( unsigned long ) * V_195 -> V_195 ;
V_73 -> V_156 -> V_159 = * V_195 -> V_207 ;
#ifdef F_32
V_73 -> V_156 -> V_208 = ( unsigned long ) V_193 >> 32 ;
V_73 -> V_156 -> V_165 = ( unsigned long ) * V_195 -> V_195 >> 32 ;
#endif
return V_13 ;
}
static T_1 F_36 ( struct V_56 * V_56 ,
void * V_9 , bool V_18 )
{
unsigned long V_209 , V_210 , V_200 , V_199 ;
T_18 * V_211 ;
struct V_39 * V_149 ;
T_19 V_153 ;
T_1 V_8 ;
T_19 V_212 ;
struct V_194 V_195 ;
struct V_198 V_196 ;
V_195 . V_195 = & V_211 ;
V_195 . V_207 = & V_209 ;
V_195 . V_200 = & V_200 ;
V_195 . V_206 = & V_212 ;
V_195 . V_213 = & V_210 ;
V_195 . V_199 = & V_199 ;
V_196 . V_56 = V_56 ;
V_196 . V_156 = & V_56 -> V_155 ;
V_196 . V_149 = NULL ;
V_196 . V_153 = 0 ;
V_196 . V_18 = V_18 ;
V_8 = F_37 ( V_14 , V_9 , & V_195 , & V_196 ,
F_35 ) ;
if ( V_8 != V_13 )
return V_8 ;
V_149 = V_196 . V_149 ;
V_153 = V_196 . V_153 ;
V_56 -> V_214 = 32 * 1024 ;
V_8 = F_31 ( V_56 , V_149 , V_153 ) ;
if ( V_8 != V_13 )
return V_8 ;
return V_13 ;
}
struct V_56 * F_38 ( struct V_116 * V_117 ,
struct V_56 * V_56 )
{
struct V_215 * V_216 = NULL ;
T_15 * V_4 ;
struct V_120 * V_64 = & V_56 -> V_64 ;
T_1 V_8 ;
struct V_217 * V_218 ;
void * V_9 ;
T_8 * V_219 ;
bool V_18 ;
V_16 = V_117 ;
V_219 = ( T_8 * ) ( unsigned long ) V_16 -> V_19 ;
V_9 = ( void * ) ( unsigned long ) V_16 -> V_130 ;
V_18 = V_16 -> V_18 ;
V_14 = V_219 ;
if ( V_14 -> V_64 . V_131 != V_132 )
goto V_139;
if ( V_18 )
F_23 ( V_16 ) ;
else
F_24 ( V_16 ) ;
if ( V_56 -> V_220 == V_221 )
V_56 -> V_220 = F_39 ( V_14 ) ;
F_20 ( V_56 ) ;
F_12 ( V_56 ) ;
F_15 ( V_56 ) ;
V_8 = F_2 ( V_34 , V_35 ,
sizeof( * V_216 ) , ( void * * ) & V_216 ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_13 ) ;
goto V_139;
}
V_216 -> V_28 = 0x800 ;
V_8 = F_25 ( V_14 , V_216 -> V_28 , 8 ,
( unsigned long * ) & V_216 -> V_222 ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_14 ) ;
goto V_139;
}
if ( V_64 -> V_223 != V_64 -> V_224 ) {
unsigned long V_225 = V_64 -> V_224 ;
V_8 = F_40 ( V_14 , & V_225 ,
V_64 -> V_226 , V_64 -> V_226 ,
V_64 -> V_223 ,
V_64 -> V_227 ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_15 ) ;
goto V_139;
}
V_64 -> V_223 = V_64 -> V_224 ;
V_64 -> V_224 = V_225 ;
}
V_8 = F_36 ( V_56 , V_9 , V_18 ) ;
if ( V_8 != V_13 ) {
F_3 ( V_14 , L_16 ) ;
goto V_139;
}
memset ( ( char * ) V_216 -> V_222 , 0x0 , V_216 -> V_28 ) ;
V_218 = (struct V_217 * ) V_216 -> V_222 ;
V_218 += 2 ;
V_218 -> V_228 = 0xffff ;
V_218 -> V_229 = 0x0000 ;
V_218 -> V_230 = 0x0000 ;
V_218 -> type = V_231 | V_232 ;
V_218 -> V_233 = V_234 ;
V_218 -> V_235 = 0 ;
V_218 -> V_73 = 1 ;
V_218 -> V_236 = 0xf ;
V_218 -> V_237 = 0 ;
V_218 -> V_238 = 0 ;
V_218 -> V_161 = V_239 ;
V_218 -> V_240 = V_241 ;
V_218 -> V_242 = 0x00 ;
V_218 ++ ;
V_218 -> V_228 = 0xffff ;
V_218 -> V_229 = 0x0000 ;
V_218 -> V_230 = 0x0000 ;
V_218 -> type = V_243 | V_244 ;
V_218 -> V_233 = V_234 ;
V_218 -> V_235 = 0 ;
V_218 -> V_73 = 1 ;
V_218 -> V_236 = 0xf ;
V_218 -> V_237 = 0 ;
V_218 -> V_238 = 0 ;
V_218 -> V_161 = V_239 ;
V_218 -> V_240 = V_241 ;
V_218 -> V_242 = 0x00 ;
#ifdef F_32
V_218 ++ ;
V_218 -> V_228 = 0x0000 ;
V_218 -> V_229 = 0x0000 ;
V_218 -> V_230 = 0x0000 ;
V_218 -> type = V_245 ;
V_218 -> V_233 = 0 ;
V_218 -> V_235 = 0 ;
V_218 -> V_73 = 1 ;
V_218 -> V_236 = 0x0 ;
V_218 -> V_237 = 0 ;
V_218 -> V_238 = 0 ;
V_218 -> V_161 = 0 ;
V_218 -> V_240 = V_241 ;
V_218 -> V_242 = 0x00 ;
#endif
asm volatile("cli");
asm volatile ("lgdt %0" : : "m" (*gdt));
return V_56 ;
V_139:
F_3 ( V_14 , L_17 ) ;
return NULL ;
}
