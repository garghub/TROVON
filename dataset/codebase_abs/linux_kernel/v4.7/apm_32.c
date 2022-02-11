static void F_1 ( char * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
if ( V_5 [ V_3 ] . V_6 == V_2 )
break;
if ( V_3 < V_4 )
F_2 ( L_1 , V_1 , V_5 [ V_3 ] . V_7 ) ;
else if ( V_2 < 0 )
F_2 ( L_2 , V_1 , V_2 ) ;
else
F_2 ( L_3 ,
V_1 , V_2 ) ;
}
static inline unsigned long F_3 ( void )
{
unsigned long V_8 ;
F_4 ( V_8 ) ;
if ( V_9 . V_10 ) {
if ( F_5 ( V_8 ) )
F_6 () ;
} else
F_7 () ;
return V_8 ;
}
static inline void F_8 ( unsigned long V_8 )
{
if ( F_5 ( V_8 ) )
F_7 () ;
else if ( F_9 () )
F_6 () ;
}
static long F_10 ( void * V_11 )
{
T_1
unsigned long V_8 ;
int V_12 ;
struct V_13 V_14 ;
struct V_13 * V_15 ;
struct V_16 * V_17 = V_11 ;
V_12 = F_11 () ;
F_12 ( V_12 != 0 ) ;
V_15 = F_13 ( V_12 ) ;
V_14 = V_15 [ 0x40 / 8 ] ;
V_15 [ 0x40 / 8 ] = V_18 ;
F_14 ( V_8 ) ;
V_19 ;
F_15 ( V_17 -> V_20 , V_17 -> V_21 , V_17 -> V_22 ,
& V_17 -> V_23 , & V_17 -> V_21 , & V_17 -> V_22 , & V_17 -> V_24 ,
& V_17 -> V_25 ) ;
V_26 ;
F_8 ( V_8 ) ;
V_15 [ 0x40 / 8 ] = V_14 ;
F_16 () ;
return V_17 -> V_23 & 0xff ;
}
static int F_17 ( long (* F_18)( void * ) , struct V_16 * V_17 )
{
int V_27 ;
if ( F_11 () == 0 ) {
V_27 = F_18 ( V_17 ) ;
F_16 () ;
} else {
F_16 () ;
V_27 = F_19 ( 0 , F_18 , V_17 ) ;
}
if ( V_27 < 0 )
V_17 -> V_2 = V_27 ;
else
V_17 -> V_2 = ( V_17 -> V_23 >> 8 ) & 0xff ;
return V_27 ;
}
static int V_16 ( struct V_16 * V_17 )
{
return F_17 ( F_10 , V_17 ) ;
}
static long F_20 ( void * V_11 )
{
T_2 error ;
T_1
unsigned long V_8 ;
int V_12 ;
struct V_13 V_14 ;
struct V_13 * V_15 ;
struct V_16 * V_17 = V_11 ;
V_12 = F_11 () ;
F_12 ( V_12 != 0 ) ;
V_15 = F_13 ( V_12 ) ;
V_14 = V_15 [ 0x40 / 8 ] ;
V_15 [ 0x40 / 8 ] = V_18 ;
F_14 ( V_8 ) ;
V_19 ;
error = F_21 ( V_17 -> V_20 , V_17 -> V_21 , V_17 -> V_22 ,
& V_17 -> V_23 ) ;
V_26 ;
F_8 ( V_8 ) ;
V_15 [ 0x40 / 8 ] = V_14 ;
F_16 () ;
return error ;
}
static int F_22 ( T_3 V_20 , T_3 V_28 , T_3 V_29 , T_3 * V_23 ,
int * V_2 )
{
struct V_16 V_17 ;
int V_27 ;
V_17 . V_20 = V_20 ;
V_17 . V_21 = V_28 ;
V_17 . V_22 = V_29 ;
V_27 = F_17 ( F_20 , & V_17 ) ;
* V_23 = V_17 . V_23 ;
* V_2 = V_17 . V_2 ;
return V_27 ;
}
static int F_23 ( T_4 * V_30 )
{
T_3 V_23 ;
int V_2 ;
if ( F_22 ( V_31 , 0 , * V_30 , & V_23 , & V_2 ) )
return V_2 ;
* V_30 = V_23 ;
return V_32 ;
}
static int F_24 ( T_5 * V_33 , T_6 * V_34 )
{
struct V_16 V_17 ;
V_17 . V_20 = V_35 ;
V_17 . V_21 = V_17 . V_22 = 0 ;
if ( V_16 ( & V_17 ) )
return V_17 . V_2 ;
* V_33 = V_17 . V_21 ;
if ( V_9 . V_36 < 0x0102 )
* V_34 = ~ 0 ;
else
* V_34 = V_17 . V_22 ;
return V_32 ;
}
static int F_25 ( T_4 V_37 , T_4 V_38 )
{
T_3 V_23 ;
int V_2 ;
if ( F_22 ( V_39 , V_37 , V_38 , & V_23 , & V_2 ) )
return V_2 ;
return V_32 ;
}
static int F_26 ( T_4 V_38 )
{
return F_25 ( V_40 , V_38 ) ;
}
static int F_27 ( void )
{
T_3 V_23 ;
T_2 V_27 = 0 ;
int V_41 = 0 ;
int V_2 = 0 ;
if ( ! F_28 () ) {
V_41 = 1 ;
V_27 = F_22 ( V_42 , 0 , 0 , & V_23 , & V_2 ) ;
}
if ( ! V_41 )
return 0 ;
if ( V_27 ) {
static unsigned long V_43 ;
if ( ++ V_43 < 5 ) {
F_29 ( V_44 L_4 , V_2 ) ;
V_43 = V_45 ;
}
return - 1 ;
}
V_46 = ( V_9 . V_47 . V_8 & V_48 ) != 0 ;
return V_46 ;
}
static void F_30 ( void )
{
T_3 V_49 ;
int V_2 ;
if ( V_46 || V_50 ) {
( void ) F_22 ( V_51 , 0 , 0 , & V_49 , & V_2 ) ;
V_46 = 0 ;
}
}
static int F_31 ( struct V_52 * V_53 ,
struct V_54 * V_55 , int V_56 )
{
static int V_57 ;
static unsigned int V_58 ;
static unsigned int V_59 ;
T_7 V_60 ;
int V_61 = 0 ;
unsigned int V_62 = V_45 - V_58 ;
unsigned int V_63 ;
V_64:
F_32 ( V_65 , NULL , & V_60 ) ;
if ( V_62 > V_66 ) {
V_57 = 0 ;
} else if ( V_62 > V_67 ) {
unsigned int V_68 ;
V_68 = F_33 ( V_60 - V_59 ) ;
V_68 *= 100 ;
V_68 /= V_62 ;
V_57 = ( V_68 > V_69 ) ;
if ( V_9 . V_70 )
V_57 = 0 ;
}
V_58 = V_45 ;
V_59 = V_60 ;
V_63 = V_71 ;
while ( ! F_28 () ) {
if ( V_57 ) {
unsigned int V_43 ;
V_43 = V_45 ;
switch ( F_27 () ) {
case 0 :
V_61 = 1 ;
if ( V_43 != V_45 ) {
if ( V_63 ) {
V_63 = V_71 ;
continue;
}
} else if ( V_63 ) {
V_63 -- ;
continue;
}
break;
case 1 :
V_61 = 1 ;
break;
default:
break;
}
}
F_34 () ;
F_7 () ;
V_62 = V_45 - V_58 ;
if ( V_62 > V_67 )
goto V_64;
}
if ( V_61 )
F_30 () ;
return V_56 ;
}
static void F_35 ( void )
{
if ( V_9 . V_72 ) {
F_36 ( V_65 , F_37 ( 0 ) ) ;
F_38 ( V_73 ) ;
} else {
( void ) F_26 ( V_74 ) ;
}
}
static int F_39 ( int V_75 )
{
T_3 V_23 ;
int V_2 ;
if ( ( V_75 == 0 ) && ( V_9 . V_47 . V_8 & V_76 ) )
return V_77 ;
if ( F_22 ( V_78 , V_79 ,
V_75 , & V_23 , & V_2 ) )
return V_2 ;
if ( V_75 )
V_9 . V_47 . V_8 &= ~ V_80 ;
else
V_9 . V_47 . V_8 |= V_80 ;
return V_32 ;
}
static int F_40 ( T_4 * V_81 , T_4 * V_82 , T_4 * V_83 )
{
struct V_16 V_17 ;
V_17 . V_20 = V_84 ;
V_17 . V_21 = V_40 ;
V_17 . V_22 = 0 ;
if ( V_9 . V_85 )
return V_86 ;
if ( V_16 ( & V_17 ) )
return V_17 . V_2 ;
* V_81 = V_17 . V_21 ;
* V_82 = V_17 . V_22 ;
if ( V_9 . V_87 ) {
* V_83 = F_41 ( ( V_88 ) V_17 . V_24 ) ;
* V_83 |= 0x8000 ;
} else
* V_83 = V_17 . V_24 ;
return V_32 ;
}
static int F_42 ( T_4 V_89 , int V_75 )
{
T_3 V_23 ;
int V_2 ;
if ( ( V_75 == 0 ) && ( V_89 == V_40 )
&& ( V_9 . V_47 . V_8 & V_80 ) )
return V_90 ;
if ( F_22 ( V_91 , V_89 , V_75 ,
& V_23 , & V_2 ) )
return V_2 ;
if ( V_89 == V_40 ) {
if ( V_75 )
V_9 . V_47 . V_8 &= ~ V_76 ;
else
V_9 . V_47 . V_8 |= V_76 ;
}
return V_32 ;
}
static int F_43 ( int V_92 )
{
int error = V_77 ;
int V_3 ;
T_4 V_38 ;
static const T_4 V_53 [ 3 ] = { 0x100 , 0x1FF , 0x101 } ;
V_38 = V_92 ? V_93 : V_94 ;
for ( V_3 = 0 ; V_3 < F_44 ( V_53 ) ; V_3 ++ ) {
error = F_25 ( V_53 [ V_3 ] , V_38 ) ;
if ( ( error == V_32 ) || ( error == V_95 ) )
return 1 ;
if ( error == V_77 )
break;
}
if ( error == V_77 ) {
static int V_96 ;
int V_97 ;
if ( V_96 ++ == 0 ) {
V_97 = F_42 ( V_40 , 1 ) ;
if ( V_97 ) {
F_1 ( L_5 , error ) ;
F_1 ( L_6 , V_97 ) ;
return 0 ;
} else
return F_43 ( V_92 ) ;
}
}
F_1 ( L_5 , error ) ;
return 0 ;
}
static int F_45 ( struct V_98 * V_99 )
{
return V_99 -> V_100 == V_99 -> V_101 ;
}
static T_5 F_46 ( struct V_98 * V_99 )
{
if ( ++ V_99 -> V_101 >= V_102 )
V_99 -> V_101 = 0 ;
return V_99 -> V_103 [ V_99 -> V_101 ] ;
}
static void F_47 ( T_5 V_33 , struct V_98 * V_104 )
{
struct V_98 * V_99 ;
F_48 ( & V_105 ) ;
if ( V_106 == NULL )
goto V_107;
for ( V_99 = V_106 ; V_99 != NULL ; V_99 = V_99 -> V_108 ) {
if ( ( V_99 == V_104 ) || ( ! V_99 -> V_109 ) )
continue;
if ( ++ V_99 -> V_100 >= V_102 )
V_99 -> V_100 = 0 ;
if ( V_99 -> V_100 == V_99 -> V_101 ) {
static int V_110 ;
if ( V_110 ++ == 0 )
F_49 ( L_7 ) ;
if ( ++ V_99 -> V_101 >= V_102 )
V_99 -> V_101 = 0 ;
}
V_99 -> V_103 [ V_99 -> V_100 ] = V_33 ;
if ( ! V_99 -> V_111 || ! V_99 -> V_112 )
continue;
switch ( V_33 ) {
case V_113 :
case V_114 :
V_99 -> V_115 ++ ;
V_115 ++ ;
break;
case V_116 :
case V_117 :
V_99 -> V_118 ++ ;
V_118 ++ ;
break;
}
}
F_50 ( & V_119 ) ;
V_107:
F_51 ( & V_105 ) ;
}
static void F_52 ( void )
{
#ifdef F_53
unsigned long V_8 ;
F_54 ( & V_120 , V_8 ) ;
F_55 ( 0x34 , V_121 ) ;
F_56 ( 10 ) ;
F_55 ( V_122 & 0xff , V_123 ) ;
F_56 ( 10 ) ;
F_55 ( V_122 >> 8 , V_123 ) ;
F_56 ( 10 ) ;
F_57 ( & V_120 , V_8 ) ;
#endif
}
static int F_58 ( int V_124 )
{
int V_2 ;
struct V_98 * V_99 ;
F_59 ( V_125 ) ;
F_60 ( V_125 ) ;
F_7 () ;
F_61 () ;
F_6 () ;
F_62 () ;
V_2 = F_26 ( V_126 ) ;
V_127 = 1 ;
F_63 () ;
F_7 () ;
F_52 () ;
if ( V_2 == V_95 )
V_2 = V_32 ;
if ( V_2 != V_32 )
F_1 ( L_8 , V_2 ) ;
V_2 = ( V_2 == V_32 ) ? 0 : - V_128 ;
F_64 () ;
F_6 () ;
F_65 ( V_129 ) ;
F_66 ( V_129 ) ;
F_47 ( V_130 , NULL ) ;
F_48 ( & V_105 ) ;
for ( V_99 = V_106 ; V_99 != NULL ; V_99 = V_99 -> V_108 ) {
V_99 -> V_131 = 0 ;
V_99 -> V_132 = V_2 ;
}
F_51 ( & V_105 ) ;
F_50 ( & V_133 ) ;
return V_2 ;
}
static void F_67 ( void )
{
int V_2 ;
F_60 ( V_125 ) ;
F_7 () ;
F_61 () ;
F_6 () ;
V_2 = F_26 ( V_93 ) ;
if ( ( V_2 != V_32 ) && ( V_2 != V_95 ) )
F_1 ( L_9 , V_2 ) ;
F_7 () ;
F_64 () ;
F_6 () ;
F_65 ( V_129 ) ;
}
static T_5 F_68 ( void )
{
int error ;
T_5 V_33 = V_134 ;
T_6 V_34 ;
static int V_110 ;
error = F_24 ( & V_33 , & V_34 ) ;
if ( error == V_32 )
return V_33 ;
if ( ( error != V_134 ) && ( V_110 ++ == 0 ) )
F_1 ( L_10 , error ) ;
return 0 ;
}
static void F_69 ( void )
{
T_5 V_33 ;
static unsigned long V_135 ;
static int V_136 ;
while ( ( V_33 = F_68 () ) != 0 ) {
if ( V_137 ) {
if ( V_33 <= V_138 )
F_29 ( V_44 L_11 ,
V_139 [ V_33 - 1 ] ) ;
else
F_29 ( V_44 L_12
L_13 , V_33 ) ;
}
if ( V_136
&& ( F_70 ( V_45 , V_135 + V_140 ) ) )
V_136 = 0 ;
switch ( V_33 ) {
case V_116 :
case V_117 :
F_47 ( V_33 , NULL ) ;
if ( V_118 <= 0 )
F_67 () ;
break;
case V_114 :
#ifdef F_71
if ( V_9 . V_36 > 0x100 )
F_26 ( V_141 ) ;
break;
#endif
case V_113 :
if ( V_136 ) {
if ( V_9 . V_36 > 0x100 )
F_26 ( V_141 ) ;
break;
}
if ( V_142 )
return;
V_142 = 1 ;
F_47 ( V_33 , NULL ) ;
if ( V_115 <= 0 )
( void ) F_58 ( 1 ) ;
break;
case V_130 :
case V_143 :
case V_144 :
V_142 = 0 ;
V_135 = V_45 ;
V_136 = 1 ;
if ( ( V_33 != V_130 )
|| ( V_127 == 0 ) ) {
F_66 ( V_129 ) ;
F_47 ( V_33 , NULL ) ;
}
V_127 = 0 ;
break;
case V_145 :
case V_146 :
case V_147 :
F_47 ( V_33 , NULL ) ;
break;
case V_148 :
break;
case V_149 :
( void ) F_58 ( 0 ) ;
break;
}
}
}
static void F_72 ( void )
{
static int V_150 = 4 ;
int V_2 ;
if ( ( V_118 > 0 ) || ( V_115 > 0 ) ) {
if ( ( V_9 . V_36 > 0x100 ) &&
( V_150 -- <= 0 ) ) {
V_150 = 4 ;
if ( V_137 )
F_29 ( V_44 L_14 ) ;
V_2 = F_26 ( V_151 ) ;
if ( V_2 )
F_1 ( L_15 , V_2 ) ;
}
} else
V_150 = 4 ;
F_69 () ;
}
static void F_73 ( void )
{
F_74 ( V_152 , V_65 ) ;
F_75 ( & V_119 , & V_152 ) ;
F_76 ( V_153 ) ;
for (; ; ) {
F_77 ( V_154 ) ;
if ( F_78 () )
break;
F_76 ( V_153 ) ;
F_72 () ;
}
F_79 ( & V_119 , & V_152 ) ;
}
static int F_80 ( struct V_98 * V_99 , const char * V_20 )
{
if ( V_99 == NULL || V_99 -> V_155 != V_156 ) {
F_49 ( L_16 , V_20 ) ;
return 1 ;
}
return 0 ;
}
static T_8 F_81 ( struct V_157 * V_158 , char T_9 * V_159 , T_10 V_160 , T_11 * V_161 )
{
struct V_98 * V_99 ;
int V_3 ;
T_5 V_33 ;
V_99 = V_158 -> V_162 ;
if ( F_80 ( V_99 , L_17 ) )
return - V_128 ;
if ( ( int ) V_160 < sizeof( T_5 ) )
return - V_163 ;
if ( ( F_45 ( V_99 ) ) && ( V_158 -> V_164 & V_165 ) )
return - V_166 ;
F_82 ( V_119 , ! F_45 ( V_99 ) ) ;
V_3 = V_160 ;
while ( ( V_3 >= sizeof( V_33 ) ) && ! F_45 ( V_99 ) ) {
V_33 = F_46 ( V_99 ) ;
if ( F_83 ( V_159 , & V_33 , sizeof( V_33 ) ) ) {
if ( V_3 < V_160 )
break;
return - V_167 ;
}
switch ( V_33 ) {
case V_113 :
case V_114 :
V_99 -> V_168 ++ ;
break;
case V_116 :
case V_117 :
V_99 -> V_169 ++ ;
break;
}
V_159 += sizeof( V_33 ) ;
V_3 -= sizeof( V_33 ) ;
}
if ( V_3 < V_160 )
return V_160 - V_3 ;
if ( F_84 ( V_65 ) )
return - V_170 ;
return 0 ;
}
static unsigned int F_85 ( struct V_157 * V_158 , T_12 * V_152 )
{
struct V_98 * V_99 ;
V_99 = V_158 -> V_162 ;
if ( F_80 ( V_99 , L_18 ) )
return 0 ;
F_86 ( V_158 , & V_119 , V_152 ) ;
if ( ! F_45 ( V_99 ) )
return V_171 | V_172 ;
return 0 ;
}
static long F_87 ( struct V_157 * V_173 , T_13 V_174 , T_14 V_175 )
{
struct V_98 * V_99 ;
int V_27 ;
V_99 = V_173 -> V_162 ;
if ( F_80 ( V_99 , L_19 ) )
return - V_128 ;
if ( ! V_99 -> V_111 || ! V_99 -> V_112 )
return - V_176 ;
switch ( V_174 ) {
case V_177 :
F_88 ( & V_178 ) ;
if ( V_99 -> V_169 > 0 ) {
V_99 -> V_169 -- ;
V_99 -> V_118 -- ;
V_118 -- ;
} else
F_47 ( V_117 , V_99 ) ;
if ( V_118 <= 0 )
F_67 () ;
F_89 ( & V_178 ) ;
break;
case V_179 :
F_88 ( & V_178 ) ;
if ( V_99 -> V_168 > 0 ) {
V_99 -> V_168 -- ;
V_99 -> V_115 -- ;
V_115 -- ;
} else
F_47 ( V_114 , V_99 ) ;
if ( V_115 <= 0 ) {
V_27 = F_58 ( 1 ) ;
F_89 ( & V_178 ) ;
} else {
V_99 -> V_131 = 1 ;
F_89 ( & V_178 ) ;
F_82 ( V_133 ,
V_99 -> V_131 == 0 ) ;
V_27 = V_99 -> V_132 ;
}
return V_27 ;
default:
return - V_180 ;
}
return 0 ;
}
static int F_90 ( struct V_181 * V_181 , struct V_157 * V_173 )
{
struct V_98 * V_99 ;
V_99 = V_173 -> V_162 ;
if ( F_80 ( V_99 , L_20 ) )
return 0 ;
V_173 -> V_162 = NULL ;
if ( V_99 -> V_118 > 0 ) {
V_118 -= V_99 -> V_118 ;
if ( V_118 <= 0 )
F_67 () ;
}
if ( V_99 -> V_115 > 0 ) {
V_115 -= V_99 -> V_115 ;
if ( V_115 <= 0 )
( void ) F_58 ( 1 ) ;
}
F_48 ( & V_105 ) ;
if ( V_106 == V_99 )
V_106 = V_99 -> V_108 ;
else {
struct V_98 * V_182 ;
for ( V_182 = V_106 ;
( V_182 != NULL ) && ( V_182 -> V_108 != V_99 ) ;
V_182 = V_182 -> V_108 )
;
if ( V_182 == NULL )
F_49 ( L_21 ) ;
else
V_182 -> V_108 = V_99 -> V_108 ;
}
F_51 ( & V_105 ) ;
F_91 ( V_99 ) ;
return 0 ;
}
static int F_92 ( struct V_181 * V_181 , struct V_157 * V_173 )
{
struct V_98 * V_99 ;
V_99 = F_93 ( sizeof( * V_99 ) , V_183 ) ;
if ( V_99 == NULL )
return - V_184 ;
V_99 -> V_155 = V_156 ;
V_99 -> V_101 = V_99 -> V_100 = 0 ;
V_99 -> V_115 = V_99 -> V_118 = 0 ;
V_99 -> V_168 = V_99 -> V_169 = 0 ;
V_99 -> V_111 = F_94 ( V_185 ) ;
V_99 -> V_112 = ( V_173 -> V_186 & V_187 ) == V_187 ;
V_99 -> V_109 = ( V_173 -> V_186 & V_188 ) == V_188 ;
F_48 ( & V_105 ) ;
V_99 -> V_108 = V_106 ;
V_106 = V_99 ;
F_51 ( & V_105 ) ;
V_173 -> V_162 = V_99 ;
return 0 ;
}
static int F_95 ( struct V_189 * V_190 , void * V_191 )
{
unsigned short V_192 ;
unsigned short V_193 ;
unsigned short V_194 ;
int error ;
unsigned short V_195 = 0xff ;
unsigned short V_196 = 0xff ;
unsigned short V_197 = 0xff ;
int V_198 = - 1 ;
int V_199 = - 1 ;
char * V_200 = L_22 ;
if ( ( F_96 () == 1 ) &&
! ( error = F_40 ( & V_192 , & V_193 , & V_194 ) ) ) {
V_195 = ( V_192 >> 8 ) & 0xff ;
V_196 = V_192 & 0xff ;
if ( ( V_193 & 0xff ) != 0xff )
V_198 = V_193 & 0xff ;
if ( V_9 . V_36 > 0x100 ) {
V_197 = ( V_193 >> 8 ) & 0xff ;
if ( V_194 != 0xffff ) {
V_200 = ( V_194 & 0x8000 ) ? L_23 : L_24 ;
V_199 = V_194 & 0x7fff ;
}
}
}
F_97 ( V_190 , L_25 ,
V_201 ,
( V_9 . V_47 . V_202 >> 8 ) & 0xff ,
V_9 . V_47 . V_202 & 0xff ,
V_9 . V_47 . V_8 ,
V_195 ,
V_196 ,
V_197 ,
V_198 ,
V_199 ,
V_200 ) ;
return 0 ;
}
static int F_98 ( struct V_181 * V_181 , struct V_157 * V_157 )
{
return F_99 ( V_157 , F_95 , NULL ) ;
}
static int F_100 ( void * V_203 )
{
unsigned short V_192 ;
unsigned short V_193 ;
unsigned short V_194 ;
int error ;
char * V_204 ;
char * V_205 ;
F_36 ( V_65 , F_37 ( 0 ) ) ;
F_12 ( F_101 () != 0 ) ;
if ( V_9 . V_36 == 0 ) {
V_9 . V_36 = V_9 . V_47 . V_202 ;
if ( V_9 . V_36 > 0x100 ) {
if ( V_9 . V_36 > 0x0102 )
V_9 . V_36 = 0x0102 ;
error = F_23 ( & V_9 . V_36 ) ;
if ( error != V_32 ) {
F_1 ( L_26 , error ) ;
V_9 . V_36 = 0x100 ;
}
}
}
if ( V_137 )
F_29 ( V_206 L_27 ,
( V_9 . V_36 >> 8 ) & 0xff ,
V_9 . V_36 & 0xff ) ;
#ifdef F_102
if ( V_9 . V_47 . V_8 & V_80 ) {
error = F_39 ( 1 ) ;
if ( error ) {
F_1 ( L_28 , error ) ;
return - 1 ;
}
}
#endif
if ( ( V_9 . V_47 . V_8 & V_76 )
&& ( V_9 . V_36 > 0x0100 ) ) {
error = F_42 ( V_40 , 1 ) ;
if ( error ) {
F_1 ( L_29 , error ) ;
return - 1 ;
}
}
if ( V_137 && ( F_96 () == 1 || V_207 ) ) {
error = F_40 ( & V_192 , & V_193 , & V_194 ) ;
if ( error )
F_29 ( V_206 L_30 ) ;
else {
switch ( ( V_192 >> 8 ) & 0xff ) {
case 0 :
V_204 = L_31 ;
break;
case 1 :
V_204 = L_32 ;
break;
case 2 :
V_204 = L_33 ;
break;
default:
V_204 = L_34 ;
break;
}
switch ( V_192 & 0xff ) {
case 0 :
V_205 = L_35 ;
break;
case 1 :
V_205 = L_36 ;
break;
case 2 :
V_205 = L_37 ;
break;
case 3 :
V_205 = L_38 ;
break;
default:
V_205 = L_34 ;
break;
}
F_29 ( V_206
L_39 ,
V_204 , V_205 ) ;
if ( ( V_193 & 0xff ) == 0xff )
F_29 ( L_40 ) ;
else
F_29 ( L_41 , V_193 & 0xff ) ;
if ( V_9 . V_36 > 0x100 ) {
F_29 ( V_206
L_42 ,
( V_193 >> 8 ) & 0xff ) ;
if ( V_194 == 0xffff )
F_29 ( L_40 ) ;
else
F_29 ( L_43 , V_194 & 0x7fff ,
( V_194 & 0x8000 ) ?
L_44 : L_45 ) ;
}
}
}
if ( V_208 )
V_209 = F_35 ;
if ( F_96 () == 1 || V_207 ) {
#if F_103 ( V_210 ) && F_103 ( V_211 )
V_212 = F_43 ;
#endif
F_73 () ;
#if F_103 ( V_210 ) && F_103 ( V_211 )
V_212 = NULL ;
#endif
}
return 0 ;
}
static int T_15 F_104 ( char * V_1 )
{
int V_213 ;
while ( ( V_1 != NULL ) && ( * V_1 != '\0' ) ) {
if ( strncmp ( V_1 , L_46 , 3 ) == 0 )
V_214 = 1 ;
if ( strncmp ( V_1 , L_47 , 2 ) == 0 )
V_214 = 0 ;
if ( ( strncmp ( V_1 , L_48 , 16 ) == 0 ) ||
( strncmp ( V_1 , L_49 , 16 ) == 0 ) )
V_140 = F_105 ( V_1 + 16 , NULL , 0 ) ;
if ( ( strncmp ( V_1 , L_50 , 15 ) == 0 ) ||
( strncmp ( V_1 , L_51 , 15 ) == 0 ) )
V_69 = F_105 ( V_1 + 15 , NULL , 0 ) ;
if ( ( strncmp ( V_1 , L_52 , 12 ) == 0 ) ||
( strncmp ( V_1 , L_53 , 12 ) == 0 ) )
V_67 = F_105 ( V_1 + 12 , NULL , 0 ) ;
V_213 = ( strncmp ( V_1 , L_54 , 3 ) == 0 ) ||
( strncmp ( V_1 , L_55 , 3 ) == 0 ) ;
if ( V_213 )
V_1 += 3 ;
if ( strncmp ( V_1 , L_56 , 5 ) == 0 )
V_137 = ! V_213 ;
if ( ( strncmp ( V_1 , L_57 , 9 ) == 0 ) ||
( strncmp ( V_1 , L_58 , 9 ) == 0 ) )
V_208 = ! V_213 ;
if ( strncmp ( V_1 , L_59 , 3 ) == 0 ) {
V_207 = ! V_213 ;
V_69 = 100 ;
}
if ( ( strncmp ( V_1 , L_60 , 10 ) == 0 ) ||
( strncmp ( V_1 , L_61 , 10 ) == 0 ) )
V_9 . V_10 = ! V_213 ;
if ( ( strncmp ( V_1 , L_62 , 10 ) == 0 ) ||
( strncmp ( V_1 , L_63 , 10 ) == 0 ) )
V_9 . V_85 = ! V_213 ;
if ( ( strncmp ( V_1 , L_64 , 18 ) == 0 ) ||
( strncmp ( V_1 , L_65 , 18 ) == 0 ) )
V_9 . V_72 = ! V_213 ;
V_1 = strchr ( V_1 , ',' ) ;
if ( V_1 != NULL )
V_1 += strspn ( V_1 , L_66 ) ;
}
return 1 ;
}
static int T_15 F_106 ( const struct V_215 * V_216 )
{
F_29 ( L_67 , V_216 -> V_217 ) ;
return 0 ;
}
static int T_15 F_107 ( const struct V_215 * V_216 )
{
F_29 ( V_206 L_68
L_69 , V_216 -> V_217 ) ;
return 0 ;
}
static int T_15 F_108 ( const struct V_215 * V_216 )
{
if ( V_9 . V_72 == 0 ) {
V_9 . V_72 = 1 ;
F_29 ( V_206 L_70
L_71 , V_216 -> V_217 ) ;
}
return 0 ;
}
static int T_15 F_109 ( const struct V_215 * V_216 )
{
if ( V_9 . V_10 == 0 ) {
V_9 . V_10 = 1 ;
F_29 ( V_206 L_72
L_73 , V_216 -> V_217 ) ;
}
return 0 ;
}
static int T_15 F_110 ( const struct V_215 * V_216 )
{
if ( V_9 . V_218 == 0 ) {
V_9 . V_218 = 1 ;
F_29 ( V_206 L_72
L_74 , V_216 -> V_217 ) ;
}
return 0 ;
}
static int T_15 F_111 ( const struct V_215 * V_216 )
{
if ( V_9 . V_218 == 0 ) {
V_9 . V_218 = 1 ;
F_29 ( V_206 L_72
L_74 , V_216 -> V_217 ) ;
F_29 ( V_206 L_75 ) ;
F_29 ( V_206 L_76 ) ;
}
return 0 ;
}
static int T_15 F_112 ( const struct V_215 * V_216 )
{
if ( V_9 . V_70 == 0 ) {
V_9 . V_70 = 1 ;
F_29 ( V_206 L_72
L_77 , V_216 -> V_217 ) ;
}
return 0 ;
}
static int T_15 F_113 ( const struct V_215 * V_216 )
{
V_9 . V_85 = 1 ;
F_29 ( V_219 L_78
L_79 ) ;
return 0 ;
}
static int T_15 F_114 ( const struct V_215 * V_216 )
{
V_9 . V_87 = 1 ;
F_29 ( V_219 L_80
L_81 ) ;
return 0 ;
}
static int T_15 F_115 ( void )
{
struct V_13 * V_15 ;
int V_2 ;
F_116 ( V_220 ) ;
if ( V_9 . V_47 . V_202 == 0 || F_117 () ) {
F_29 ( V_206 L_82 ) ;
return - V_221 ;
}
F_29 ( V_206
L_83 ,
( ( V_9 . V_47 . V_202 >> 8 ) & 0xff ) ,
( V_9 . V_47 . V_202 & 0xff ) ,
V_9 . V_47 . V_8 ,
V_201 ) ;
if ( ( V_9 . V_47 . V_8 & V_222 ) == 0 ) {
F_29 ( V_206 L_84 ) ;
return - V_221 ;
}
if ( V_10 )
V_9 . V_10 = 1 ;
if ( V_223 )
V_9 . V_85 = 1 ;
if ( V_72 )
V_9 . V_72 = 1 ;
if ( V_214 != - 1 )
V_9 . V_218 = V_214 ;
if ( V_9 . V_47 . V_202 == 0x001 )
V_9 . V_47 . V_202 = 0x100 ;
if ( V_9 . V_47 . V_202 < 0x102 )
V_9 . V_47 . V_224 = 0 ;
if ( V_137 ) {
F_29 ( V_206 L_85 ,
V_9 . V_47 . V_225 , V_9 . V_47 . V_226 ,
V_9 . V_47 . V_227 , V_9 . V_47 . V_228 ) ;
if ( V_9 . V_47 . V_202 > 0x100 )
F_29 ( L_86 ,
V_9 . V_47 . V_229 ,
V_9 . V_47 . V_230 ) ;
if ( V_9 . V_47 . V_202 > 0x101 )
F_29 ( L_87 , V_9 . V_47 . V_224 ) ;
F_29 ( L_88 ) ;
}
if ( V_9 . V_218 ) {
F_2 ( L_89 ) ;
return - V_221 ;
}
if ( ( F_96 () > 1 ) && ! V_208 && ! V_207 ) {
F_2 ( L_90 ) ;
V_9 . V_218 = 1 ;
return - V_221 ;
}
if ( ! V_231 ) {
F_2 ( L_91 ) ;
V_9 . V_218 = 1 ;
return - V_221 ;
}
V_232 . V_226 = V_9 . V_47 . V_226 ;
V_232 . V_233 = V_234 ;
V_15 = F_13 ( 0 ) ;
F_118 ( & V_15 [ V_234 >> 3 ] ,
( unsigned long ) F_119 ( ( unsigned long ) V_9 . V_47 . V_225 << 4 ) ) ;
F_118 ( & V_15 [ V_235 >> 3 ] ,
( unsigned long ) F_119 ( ( unsigned long ) V_9 . V_47 . V_227 << 4 ) ) ;
F_118 ( & V_15 [ V_236 >> 3 ] ,
( unsigned long ) F_119 ( ( unsigned long ) V_9 . V_47 . V_228 << 4 ) ) ;
F_120 ( L_92 , 0 , NULL , & V_237 ) ;
V_238 = F_121 ( F_100 , NULL , L_93 ) ;
if ( F_122 ( V_238 ) ) {
F_49 ( L_94 ) ;
V_2 = F_123 ( V_238 ) ;
V_238 = NULL ;
F_124 ( L_92 , NULL ) ;
return V_2 ;
}
F_125 ( V_238 ) ;
if ( F_96 () > 1 && ! V_207 ) {
F_29 ( V_239
L_95 ) ;
return 0 ;
}
if ( F_126 ( & V_240 ) )
F_29 ( V_219 L_96 ) ;
if ( V_241 != 100 )
V_67 = ( V_67 * V_241 ) / 100 ;
if ( V_69 < 100 ) {
if ( ! F_127 ( & V_242 ) )
if ( F_128 ( & V_243 ) )
F_129 ( & V_242 ) ;
}
return 0 ;
}
static void T_16 F_130 ( void )
{
int error ;
F_131 ( & V_243 ) ;
F_129 ( & V_242 ) ;
if ( ( ( V_9 . V_47 . V_8 & V_76 ) == 0 )
&& ( V_9 . V_36 > 0x0100 ) ) {
error = F_42 ( V_40 , 0 ) ;
if ( error )
F_1 ( L_97 , error ) ;
}
F_132 ( & V_240 ) ;
F_124 ( L_92 , NULL ) ;
if ( V_208 )
V_209 = NULL ;
if ( V_238 ) {
F_133 ( V_238 ) ;
V_238 = NULL ;
}
}
