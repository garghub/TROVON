static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static inline union V_5 * F_2 ( struct V_6 * V_7 )
{
return (union V_5 * ) ( V_7 -> V_8 -> V_9 ) ;
}
static int F_3 ( struct V_6 * V_7 , T_1 V_10 , T_2 V_11 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
long V_13 , V_14 ;
union {
struct V_15 V_16 ;
T_1 V_17 [ 2 ] ;
} V_18 ;
V_13 = F_4 ( V_10 , V_12 -> V_19 , V_7 -> V_8 -> V_20 ,
V_12 -> V_21 , V_7 -> V_22 ) ;
if ( V_13 )
F_5 ( L_1 , V_13 ) ;
V_18 . V_16 . V_23 = 0x80 ;
V_18 . V_16 . V_11 = V_11 ;
V_18 . V_16 . V_24 = 0x00 ;
V_18 . V_16 . V_25 = 0x00 ;
V_18 . V_16 . V_26 = V_10 ;
V_18 . V_16 . V_27 = F_2 ( V_7 ) -> V_28 . V_29 . V_30 ;
if ( V_13 == 0 )
V_18 . V_16 . V_31 = 0x99 ;
else
V_18 . V_16 . V_31 = 0x00 ;
V_14 = F_6 ( V_12 -> V_32 -> V_33 , V_18 . V_17 [ 0 ] , V_18 . V_17 [ 1 ] ) ;
if ( V_14 ) {
F_5 ( L_2 , V_14 ) ;
return V_14 ;
}
return V_13 ;
}
static int F_7 ( struct V_6 * V_7 , struct V_34 * V_35 ,
unsigned char V_31 , unsigned char V_36 )
{
union V_5 * V_37 = F_2 ( V_7 ) ;
T_1 V_30 = V_37 -> V_28 . V_29 . V_30 ;
if ( F_8 ( V_38 , & V_7 -> V_39 ) && ( V_31 == V_40 ) )
V_31 = 0x10 ;
memset ( V_37 , 0 , sizeof( struct V_41 ) ) ;
V_37 -> V_28 . V_29 . V_42 = V_43 ;
V_37 -> V_28 . V_29 . V_44 = 1 ;
V_37 -> V_28 . V_29 . V_30 = V_30 ;
if ( F_8 ( V_45 , & V_7 -> V_39 ) )
V_37 -> V_28 . V_29 . V_39 |= V_46 ;
V_37 -> V_28 . V_29 . V_47 = 0 ;
V_37 -> V_28 . V_29 . V_48 = 0 ;
V_37 -> V_28 . V_29 . V_39 &= ~ V_49 ;
V_37 -> V_28 . V_29 . V_50 = 0 ;
V_37 -> V_28 . V_29 . V_31 = V_31 ;
if ( V_31 ) {
T_2 * V_51 = V_37 -> V_28 . V_29 . V_52 ;
if ( V_35 ) {
V_37 -> V_28 . V_29 . V_39 |= V_53 ;
V_37 -> V_28 . V_29 . V_54 = V_55 ;
memcpy ( V_51 , V_35 -> V_56 , V_55 ) ;
} else {
V_37 -> V_28 . V_29 . V_31 = V_57 ;
V_37 -> V_28 . V_29 . V_39 |= V_53 ;
V_37 -> V_28 . V_29 . V_54 = V_58 ;
V_51 [ 0 ] = ( 0x1 << 7 | 0x70 ) ;
V_51 [ 2 ] = V_31 ;
V_51 [ 7 ] = 0xa ;
V_51 [ 12 ] = V_36 ;
}
}
F_3 ( V_7 , sizeof( V_37 -> V_28 . V_29 ) + V_58 ,
V_59 ) ;
return 0 ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_60 * V_61 = V_3 -> V_61 ;
struct V_62 * V_63 = F_1 ( V_3 ) -> V_63 ;
struct V_6 * V_7 ;
struct V_64 * V_65 ;
unsigned long V_39 ;
int V_66 ;
V_67:
F_10 ( & V_3 -> V_68 , V_39 ) ;
F_11 (iue, &target->cmd_queue, ilist) {
if ( ! F_12 ( V_69 , & V_7 -> V_39 ) ) {
F_13 ( & V_3 -> V_68 , V_39 ) ;
V_65 = V_7 -> V_8 -> V_9 ;
V_66 = F_14 ( V_61 , V_65 , V_7 ,
( unsigned long ) V_63 , 0 ) ;
if ( V_66 ) {
F_5 ( L_3 , V_65 , V_66 ) ;
F_15 ( V_7 ) ;
}
goto V_67;
}
}
F_13 ( & V_3 -> V_68 , V_39 ) ;
}
static int F_16 ( struct V_34 * V_35 , struct V_70 * V_71 , int V_72 ,
struct V_73 * V_74 , int V_75 ,
enum V_76 V_77 , unsigned int V_78 )
{
struct V_6 * V_7 = (struct V_6 * ) V_35 -> V_79 . V_80 ;
struct V_2 * V_3 = V_7 -> V_3 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_3 V_81 ;
long V_66 ;
unsigned int V_82 = 0 ;
int V_83 , V_84 , V_85 ;
V_84 = V_85 = 0 ;
V_81 = F_17 ( V_71 + V_84 ) ;
for ( V_83 = 0 ; V_83 < V_75 && V_78 ; V_83 ++ ) {
unsigned int V_86 , V_87 ;
V_87 = F_18 ( V_78 , V_74 [ V_83 ] . V_88 ) ;
for ( V_86 = 0 ; V_87 ; ) {
int V_89 = F_18 ( F_19 ( V_71 + V_84 ) - V_85 , V_87 ) ;
if ( V_77 == V_90 )
V_66 = F_4 ( V_89 ,
V_12 -> V_21 ,
V_74 [ V_83 ] . V_91 + V_86 ,
V_12 -> V_19 ,
V_81 + V_85 ) ;
else
V_66 = F_4 ( V_89 ,
V_12 -> V_19 ,
V_81 + V_85 ,
V_12 -> V_21 ,
V_74 [ V_83 ] . V_91 + V_86 ) ;
if ( V_66 != V_92 ) {
F_5 ( L_4 , V_77 , V_89 , V_66 ) ;
return - V_93 ;
}
V_87 -= V_89 ;
V_86 += V_89 ;
V_85 += V_89 ;
V_82 += V_89 ;
if ( V_85 == F_19 ( V_71 + V_84 ) ) {
V_84 ++ ;
V_85 = 0 ;
V_81 = F_17 ( V_71 + V_84 ) ;
if ( V_84 > V_72 ) {
F_5 ( L_5 ,
V_7 , V_84 , V_72 ) ;
return - V_93 ;
}
}
} ;
V_78 -= V_87 ;
}
return 0 ;
}
static int F_20 ( struct V_34 * V_35 ,
void (* V_82)( struct V_34 * ) )
{
unsigned long V_39 ;
struct V_6 * V_7 = (struct V_6 * ) V_35 -> V_79 . V_80 ;
struct V_2 * V_3 = V_7 -> V_3 ;
int V_66 = 0 ;
F_21 ( L_6 , V_7 , V_3 , F_2 ( V_7 ) -> V_28 . V_65 . V_94 [ 0 ] ,
F_22 ( V_35 ) ) ;
if ( F_22 ( V_35 ) )
V_66 = F_23 ( V_35 , & F_2 ( V_7 ) -> V_28 . V_65 , F_16 , 1 , 1 ) ;
F_10 ( & V_3 -> V_68 , V_39 ) ;
F_24 ( & V_7 -> V_95 ) ;
F_13 ( & V_3 -> V_68 , V_39 ) ;
if ( V_66 || V_35 -> V_96 != V_97 ) {
F_5 ( L_7 ,
V_7 , V_35 -> V_96 , F_2 ( V_7 ) -> V_28 . V_65 . V_94 [ 0 ] ) ;
F_7 ( V_7 , V_35 , V_98 , 0x00 ) ;
} else
F_7 ( V_7 , V_35 , V_40 , 0x00 ) ;
V_82 ( V_35 ) ;
F_15 ( V_7 ) ;
return 0 ;
}
int F_25 ( struct V_6 * V_7 ,
T_3 V_99 , T_4 V_10 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_60 * V_61 = V_3 -> V_61 ;
T_3 V_100 ;
struct V_101 * V_102 ;
int V_66 ;
V_102 = F_26 ( V_3 -> V_103 , sizeof( * V_102 ) , & V_100 ,
V_104 ) ;
if ( ! V_102 ) {
F_5 ( L_8 , V_3 ) ;
return 1 ;
}
V_66 = F_4 ( sizeof( * V_102 ) , V_12 -> V_21 , V_99 ,
V_12 -> V_19 , V_100 ) ;
if ( V_66 == V_92 ) {
F_21 ( L_9 ,
V_102 -> V_105 , V_102 -> V_106 ) ;
}
memset ( V_102 , 0 , sizeof( * V_102 ) ) ;
strcpy ( V_102 -> V_107 , L_10 ) ;
strncpy ( V_102 -> V_105 , V_105 ,
sizeof( V_102 -> V_105 ) ) ;
V_102 -> V_106 = V_106 ;
V_102 -> V_108 = 1 ;
V_102 -> V_109 = 2 ;
V_102 -> V_110 [ 0 ] = V_61 -> V_111 -> V_112 << 9 ;
V_66 = F_4 ( sizeof( * V_102 ) , V_12 -> V_19 , V_100 ,
V_12 -> V_21 , V_99 ) ;
F_27 ( V_3 -> V_103 , sizeof( * V_102 ) , V_102 , V_100 ) ;
if ( V_66 != V_92 ) {
F_5 ( L_11 , V_66 ) ;
return 1 ;
}
return 0 ;
}
static void F_28 ( struct V_6 * V_7 )
{
union V_5 * V_37 = F_2 ( V_7 ) ;
struct V_113 * V_29 = & V_37 -> V_28 . V_114 ;
T_1 V_30 = V_37 -> V_28 . V_29 . V_30 ;
struct V_60 * V_61 = V_7 -> V_3 -> V_61 ;
struct V_2 * V_3 = F_29 ( V_61 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_115 V_116 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
sprintf ( V_116 . V_117 , L_12 , V_12 -> V_32 -> V_33 ) ;
V_116 . V_118 = V_119 ;
if ( ! V_12 -> V_63 )
V_12 -> V_63 = F_30 ( V_61 , & V_116 ) ;
memset ( V_37 , 0 , sizeof( struct V_113 ) ) ;
V_29 -> V_42 = V_120 ;
V_29 -> V_44 = V_121 ;
V_29 -> V_30 = V_30 ;
V_29 -> V_122 = sizeof( union V_123 ) ;
V_29 -> V_124 = sizeof( union V_123 ) ;
V_29 -> V_125 = V_126 | V_127 ;
F_3 ( V_7 , sizeof( * V_29 ) , V_59 ) ;
}
static inline void F_31 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_3 ;
unsigned long V_39 ;
F_10 ( & V_3 -> V_68 , V_39 ) ;
F_32 ( & V_7 -> V_95 , & V_3 -> V_128 ) ;
F_13 ( & V_3 -> V_68 , V_39 ) ;
}
static int F_33 ( struct V_6 * V_7 )
{
union V_5 * V_37 = F_2 ( V_7 ) ;
int V_129 ;
F_21 ( L_13 , V_7 , V_37 -> V_28 . V_130 . V_131 ) ;
switch ( V_37 -> V_28 . V_130 . V_131 ) {
case V_132 :
V_129 = V_133 ;
break;
case V_134 :
V_129 = V_135 ;
break;
case V_136 :
V_129 = V_137 ;
break;
case V_138 :
V_129 = V_139 ;
break;
case V_140 :
V_129 = V_141 ;
break;
default:
V_129 = 0 ;
}
if ( V_129 )
F_34 ( V_7 -> V_3 -> V_61 ,
( unsigned long ) V_7 -> V_3 -> V_61 ,
V_129 ,
V_37 -> V_28 . V_130 . V_142 ,
(struct V_143 * ) & V_37 -> V_28 . V_130 . V_144 ,
V_7 ) ;
else
F_7 ( V_7 , NULL , V_145 , 0x20 ) ;
return ! V_129 ;
}
static int F_35 ( struct V_6 * V_7 )
{
union V_5 * V_37 = F_2 ( V_7 ) ;
struct V_146 * V_102 ;
struct V_147 * V_148 ;
switch ( V_37 -> V_149 . V_150 . V_151 . type ) {
case V_152 :
F_5 ( L_14 , L_15 ) ;
break;
case V_153 :
F_5 ( L_14 , L_16 ) ;
V_37 -> V_149 . V_154 . V_151 . V_31 = 1 ;
F_3 ( V_7 , sizeof( V_37 -> V_149 . V_154 ) , V_155 ) ;
break;
case V_156 :
V_102 = & V_37 -> V_149 . V_157 ;
V_102 -> V_151 . V_31 = F_25 ( V_7 , V_102 -> V_158 ,
V_102 -> V_151 . V_10 ) ;
F_3 ( V_7 , sizeof( * V_102 ) , V_155 ) ;
break;
case V_159 :
V_148 = & V_37 -> V_149 . V_160 ;
V_148 -> V_151 . V_31 = 1 ;
F_3 ( V_7 , sizeof( * V_148 ) , V_155 ) ;
break;
default:
F_5 ( L_17 , V_37 -> V_28 . V_29 . V_42 ) ;
}
return 1 ;
}
static int F_36 ( struct V_6 * V_7 )
{
union V_5 * V_37 = F_2 ( V_7 ) ;
int V_82 = 1 ;
T_5 V_42 = V_37 -> V_28 . V_29 . V_42 ;
switch ( V_42 ) {
case V_161 :
F_28 ( V_7 ) ;
break;
case V_162 :
V_82 = F_33 ( V_7 ) ;
break;
case V_163 :
F_31 ( V_7 ) ;
V_82 = 0 ;
break;
case V_120 :
case V_164 :
case V_165 :
case V_43 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
F_5 ( L_18 , V_42 ) ;
break;
default:
F_5 ( L_17 , V_42 ) ;
}
return V_82 ;
}
static void F_37 ( struct V_15 * V_18 , struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_6 * V_7 ;
long V_66 ;
int V_82 = 1 ;
V_7 = F_38 ( V_3 ) ;
if ( ! V_7 ) {
F_5 ( L_19 , V_3 ) ;
return;
}
V_7 -> V_22 = V_18 -> V_27 ;
V_66 = F_4 ( V_18 -> V_26 , V_12 -> V_21 ,
V_7 -> V_22 , V_12 -> V_19 , V_7 -> V_8 -> V_20 ) ;
if ( V_66 != V_92 ) {
F_5 ( L_20 , V_66 , V_7 ) ;
goto V_170;
}
if ( V_18 -> V_11 == V_155 )
V_82 = F_35 ( V_7 ) ;
else
V_82 = F_36 ( V_7 ) ;
V_170:
if ( V_82 )
F_15 ( V_7 ) ;
}
static T_6 F_39 ( int V_171 , void * V_52 )
{
struct V_2 * V_3 = V_52 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_40 ( V_12 -> V_32 ) ;
F_41 ( V_172 , & V_12 -> V_173 ) ;
return V_174 ;
}
static int F_42 ( struct V_175 * V_176 , struct V_2 * V_3 )
{
int V_66 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
V_176 -> V_177 = (struct V_15 * ) F_43 ( V_104 ) ;
if ( ! V_176 -> V_177 )
goto V_178;
V_176 -> V_179 = V_180 / sizeof( * V_176 -> V_177 ) ;
V_176 -> V_181 = F_44 ( V_3 -> V_103 , V_176 -> V_177 ,
V_176 -> V_179 * sizeof( * V_176 -> V_177 ) ,
V_182 ) ;
if ( F_45 ( V_3 -> V_103 , V_176 -> V_181 ) )
goto V_183;
V_66 = F_46 ( V_12 -> V_32 -> V_33 , V_176 -> V_181 ,
V_180 ) ;
if ( V_66 == V_184 ) {
do {
V_66 = F_47 ( V_12 -> V_32 -> V_33 ) ;
} while ( V_66 == V_185 || F_48 ( V_66 ) );
V_66 = F_46 ( V_12 -> V_32 -> V_33 , V_176 -> V_181 ,
V_180 ) ;
}
if ( V_66 != V_92 && V_66 != 2 ) {
F_5 ( L_21 , V_66 ) ;
goto V_186;
}
V_66 = F_49 ( V_12 -> V_32 -> V_187 , & F_39 ,
V_188 , L_22 , V_3 ) ;
if ( V_66 )
goto V_189;
F_50 ( V_12 -> V_32 ) ;
F_6 ( V_12 -> V_32 -> V_33 , 0xC001000000000000 , 0 ) ;
V_176 -> V_190 = 0 ;
F_51 ( & V_176 -> V_68 ) ;
return 0 ;
V_189:
do {
V_66 = F_47 ( V_12 -> V_32 -> V_33 ) ;
} while ( V_66 == V_185 || F_48 ( V_66 ) );
V_186:
F_52 ( V_3 -> V_103 , V_176 -> V_181 ,
V_176 -> V_179 * sizeof( * V_176 -> V_177 ) , V_182 ) ;
V_183:
F_53 ( ( unsigned long ) V_176 -> V_177 ) ;
V_178:
return - V_191 ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_175 * V_176 = & V_12 -> V_175 ;
int V_66 ;
F_55 ( V_12 -> V_32 -> V_187 , V_3 ) ;
do {
V_66 = F_47 ( V_12 -> V_32 -> V_33 ) ;
} while ( V_66 == V_185 || F_48 ( V_66 ) );
F_52 ( V_3 -> V_103 , V_176 -> V_181 ,
V_176 -> V_179 * sizeof( * V_176 -> V_177 ) , V_182 ) ;
F_53 ( ( unsigned long ) V_176 -> V_177 ) ;
}
static void F_56 ( struct V_15 * V_18 , struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_21 ( L_23 , V_18 -> V_23 , V_18 -> V_11 ) ;
switch ( V_18 -> V_23 ) {
case 0xC0 :
switch ( V_18 -> V_11 ) {
case 0x01 :
F_6 ( V_12 -> V_32 -> V_33 ,
0xC002000000000000 , 0 ) ;
break;
case 0x02 :
break;
default:
F_5 ( L_24 , V_18 -> V_11 ) ;
}
break;
case 0xFF :
break;
case 0x80 :
switch ( V_18 -> V_11 ) {
case V_59 :
case V_155 :
F_37 ( V_18 , V_3 ) ;
break;
case V_192 :
case V_193 :
case V_194 :
case V_195 :
F_5 ( L_25 , V_18 -> V_11 ) ;
break;
default:
F_5 ( L_24 , V_18 -> V_11 ) ;
}
break;
default:
F_5 ( L_26 , V_18 -> V_23 ) ;
}
}
static inline struct V_15 * F_57 ( struct V_175 * V_176 )
{
struct V_15 * V_18 ;
unsigned long V_39 ;
F_10 ( & V_176 -> V_68 , V_39 ) ;
V_18 = & V_176 -> V_177 [ V_176 -> V_190 ] ;
if ( V_18 -> V_23 & 0x80 ) {
if ( ++ V_176 -> V_190 == V_176 -> V_179 )
V_176 -> V_190 = 0 ;
} else
V_18 = NULL ;
F_13 ( & V_176 -> V_68 , V_39 ) ;
return V_18 ;
}
static void F_58 ( struct V_196 * V_197 )
{
struct V_1 * V_12 = F_59 ( V_197 , struct V_1 , V_173 ) ;
struct V_2 * V_3 = V_12 -> V_3 ;
struct V_15 * V_18 ;
int V_82 = 0 ;
while ( ! V_82 ) {
while ( ( V_18 = F_57 ( & V_12 -> V_175 ) ) != NULL ) {
F_56 ( V_18 , V_3 ) ;
V_18 -> V_23 = 0x00 ;
}
F_50 ( V_12 -> V_32 ) ;
V_18 = F_57 ( & V_12 -> V_175 ) ;
if ( V_18 ) {
F_40 ( V_12 -> V_32 ) ;
F_56 ( V_18 , V_3 ) ;
V_18 -> V_23 = 0x00 ;
} else
V_82 = 1 ;
}
F_9 ( V_3 ) ;
}
static int F_60 ( struct V_34 * V_35 )
{
unsigned long V_39 ;
struct V_6 * V_7 = (struct V_6 * ) V_35 -> V_79 . V_80 ;
struct V_2 * V_3 = V_7 -> V_3 ;
F_21 ( L_27 , V_7 , V_3 , F_2 ( V_7 ) -> V_28 . V_65 . V_94 [ 0 ] ) ;
F_10 ( & V_3 -> V_68 , V_39 ) ;
F_24 ( & V_7 -> V_95 ) ;
F_13 ( & V_3 -> V_68 , V_39 ) ;
F_15 ( V_7 ) ;
return 0 ;
}
static int F_61 ( struct V_60 * V_61 ,
T_7 V_198 , T_7 V_199 , int V_96 )
{
struct V_6 * V_7 = (struct V_6 * ) ( ( void * ) V_199 ) ;
union V_5 * V_37 = F_2 ( V_7 ) ;
unsigned char V_31 , V_36 ;
F_5 ( L_28 , V_7 , V_96 ) ;
V_31 = V_40 ;
V_36 = 0 ;
switch ( V_37 -> V_28 . V_130 . V_131 ) {
case V_132 :
V_36 = 0x14 ;
if ( V_96 )
V_31 = V_200 ;
break;
default:
break;
}
F_7 ( V_7 , NULL , V_31 , V_36 ) ;
F_15 ( V_7 ) ;
return 0 ;
}
static int F_62 ( struct V_60 * V_61 , T_7 V_198 ,
int V_96 )
{
struct V_2 * V_3 = F_29 ( V_61 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( V_96 ) {
F_5 ( L_28 , V_61 , V_96 ) ;
F_63 ( V_12 -> V_63 ) ;
V_12 -> V_63 = NULL ;
}
return 0 ;
}
static T_8 F_64 ( struct V_201 * V_103 ,
struct V_202 * V_203 , char * V_9 )
{
return snprintf ( V_9 , V_180 , L_14 , V_204 ) ;
}
static T_8 F_65 ( struct V_201 * V_103 ,
struct V_202 * V_203 , char * V_9 )
{
return snprintf ( V_9 , V_180 , L_29 , V_106 ) ;
}
static T_8 F_66 ( struct V_201 * V_103 ,
struct V_202 * V_203 , char * V_9 )
{
struct V_60 * V_61 = F_67 ( V_103 ) ;
struct V_2 * V_3 = F_29 ( V_61 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
return snprintf ( V_9 , V_180 , L_29 , V_12 -> V_32 -> V_33 ) ;
}
static int F_68 ( struct V_205 * V_103 , const struct V_206 * V_207 )
{
struct V_60 * V_61 ;
struct V_2 * V_3 ;
struct V_1 * V_12 ;
unsigned int * V_20 , V_208 ;
int V_66 = - V_191 ;
V_12 = F_69 ( sizeof( struct V_1 ) , V_104 ) ;
if ( ! V_12 )
return V_66 ;
V_61 = F_70 ( & V_209 , sizeof( struct V_2 ) ) ;
if ( ! V_61 )
goto V_210;
V_61 -> V_211 = V_212 ;
V_3 = F_29 ( V_61 ) ;
V_3 -> V_61 = V_61 ;
V_12 -> V_32 = V_103 ;
V_3 -> V_4 = V_12 ;
V_12 -> V_3 = V_3 ;
V_66 = F_71 ( V_3 , & V_103 -> V_103 , V_121 ,
V_213 ) ;
if ( V_66 )
goto V_214;
V_20 = ( unsigned int * ) F_72 ( V_103 , L_30 ,
& V_208 ) ;
if ( ! V_20 || V_208 != 40 ) {
F_5 ( L_31 , V_208 ) ;
V_66 = - V_93 ;
goto V_215;
}
V_12 -> V_19 = V_20 [ 0 ] ;
V_12 -> V_21 = V_20 [ 5 ] ;
F_73 ( & V_12 -> V_173 , F_58 ) ;
V_66 = F_74 ( V_61 , V_3 -> V_103 ) ;
if ( V_66 )
goto V_215;
V_66 = F_75 ( V_61 ) ;
if ( V_66 )
goto V_216;
V_66 = F_42 ( & V_12 -> V_175 , V_3 ) ;
if ( V_66 )
goto V_217;
return 0 ;
V_217:
F_76 ( V_61 ) ;
V_216:
F_77 ( V_61 ) ;
V_215:
F_78 ( V_3 ) ;
V_214:
F_79 ( V_61 ) ;
V_210:
F_80 ( V_12 ) ;
return V_66 ;
}
static int F_81 ( struct V_205 * V_103 )
{
struct V_2 * V_3 = F_82 ( & V_103 -> V_103 ) ;
struct V_60 * V_61 = V_3 -> V_61 ;
struct V_1 * V_12 = V_3 -> V_4 ;
F_54 ( V_3 ) ;
F_83 ( V_61 ) ;
F_77 ( V_61 ) ;
F_76 ( V_61 ) ;
F_78 ( V_3 ) ;
F_80 ( V_12 ) ;
F_79 ( V_61 ) ;
return 0 ;
}
static int F_84 ( void )
{
struct V_218 * V_219 ;
const char * V_207 , * V_220 , * V_221 ;
const unsigned int * V_222 ;
V_219 = F_85 ( L_32 ) ;
if ( ! V_219 )
return - V_223 ;
V_220 = F_86 ( V_219 , L_33 , NULL ) ;
V_207 = F_86 ( V_219 , L_34 , NULL ) ;
if ( V_220 && V_207 )
snprintf ( V_204 , sizeof( V_204 ) , L_35 , V_220 , V_207 ) ;
V_221 = F_86 ( V_219 , L_36 , NULL ) ;
if ( V_221 )
strncpy ( V_105 , V_221 , sizeof( V_105 ) ) ;
V_222 = F_86 ( V_219 , L_37 , NULL ) ;
if ( V_222 )
V_106 = * V_222 ;
F_87 ( V_219 ) ;
return 0 ;
}
static int T_9 F_88 ( void )
{
int V_66 = - V_191 ;
F_89 ( L_38 ) ;
V_212 =
F_90 ( & V_224 ) ;
if ( ! V_212 )
return V_66 ;
V_172 = F_91 ( L_39 ) ;
if ( ! V_172 )
goto V_225;
V_66 = F_84 () ;
if ( V_66 )
goto V_226;
V_66 = F_92 ( & V_227 ) ;
if ( V_66 )
goto V_226;
return 0 ;
V_226:
F_93 ( V_172 ) ;
V_225:
F_94 ( V_212 ) ;
return V_66 ;
}
static void T_10 F_95 ( void )
{
F_89 ( L_40 ) ;
F_93 ( V_172 ) ;
F_96 ( & V_227 ) ;
F_94 ( V_212 ) ;
}
