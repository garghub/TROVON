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
int V_42 ;
int V_2 = 0 ;
V_42 = ! ! ( F_28 () -> V_43 & V_44 ) ;
if ( V_42 ) {
F_28 () -> V_43 &= ~ V_44 ;
F_29 () ;
}
if ( ! F_30 () ) {
V_41 = 1 ;
V_27 = F_22 ( V_45 , 0 , 0 , & V_23 , & V_2 ) ;
}
if ( V_42 )
F_28 () -> V_43 |= V_44 ;
if ( ! V_41 )
return 0 ;
if ( V_27 ) {
static unsigned long V_46 ;
if ( ++ V_46 < 5 ) {
F_31 ( V_47 L_4 , V_2 ) ;
V_46 = V_48 ;
}
return - 1 ;
}
V_49 = ( V_9 . V_50 . V_8 & V_51 ) != 0 ;
return V_49 ;
}
static void F_32 ( void )
{
T_3 V_52 ;
int V_2 ;
if ( V_49 || V_53 ) {
( void ) F_22 ( V_54 , 0 , 0 , & V_52 , & V_2 ) ;
V_49 = 0 ;
}
}
static int F_33 ( struct V_55 * V_56 ,
struct V_57 * V_58 , int V_59 )
{
static int V_60 ;
static unsigned int V_61 ;
static unsigned int V_62 ;
T_7 V_63 ;
int V_64 = 0 ;
unsigned int V_65 = V_48 - V_61 ;
unsigned int V_66 ;
V_67:
F_34 ( V_68 , NULL , & V_63 ) ;
if ( V_65 > V_69 ) {
V_60 = 0 ;
} else if ( V_65 > V_70 ) {
unsigned int V_71 ;
V_71 = V_63 - V_62 ;
V_71 *= 100 ;
V_71 /= V_65 ;
V_60 = ( V_71 > V_72 ) ;
if ( V_9 . V_73 )
V_60 = 0 ;
}
V_61 = V_48 ;
V_62 = V_63 ;
V_66 = V_74 ;
while ( ! F_30 () ) {
if ( V_60 ) {
unsigned int V_46 ;
V_46 = V_48 ;
switch ( F_27 () ) {
case 0 :
V_64 = 1 ;
if ( V_46 != V_48 ) {
if ( V_66 ) {
V_66 = V_74 ;
continue;
}
} else if ( V_66 ) {
V_66 -- ;
continue;
}
break;
case 1 :
V_64 = 1 ;
break;
default:
break;
}
}
F_35 () ;
F_7 () ;
V_65 = V_48 - V_61 ;
if ( V_65 > V_70 )
goto V_67;
}
if ( V_64 )
F_32 () ;
return V_59 ;
}
static void F_36 ( void )
{
if ( V_9 . V_75 ) {
F_37 ( V_68 , F_38 ( 0 ) ) ;
F_39 ( V_76 ) ;
} else {
( void ) F_26 ( V_77 ) ;
}
}
static int F_40 ( int V_78 )
{
T_3 V_23 ;
int V_2 ;
if ( ( V_78 == 0 ) && ( V_9 . V_50 . V_8 & V_79 ) )
return V_80 ;
if ( F_22 ( V_81 , V_82 ,
V_78 , & V_23 , & V_2 ) )
return V_2 ;
if ( V_78 )
V_9 . V_50 . V_8 &= ~ V_83 ;
else
V_9 . V_50 . V_8 |= V_83 ;
return V_32 ;
}
static int F_41 ( T_4 * V_43 , T_4 * V_84 , T_4 * V_85 )
{
struct V_16 V_17 ;
V_17 . V_20 = V_86 ;
V_17 . V_21 = V_40 ;
V_17 . V_22 = 0 ;
if ( V_9 . V_87 )
return V_88 ;
if ( V_16 ( & V_17 ) )
return V_17 . V_2 ;
* V_43 = V_17 . V_21 ;
* V_84 = V_17 . V_22 ;
if ( V_9 . V_89 ) {
* V_85 = F_42 ( ( V_90 ) V_17 . V_24 ) ;
* V_85 |= 0x8000 ;
} else
* V_85 = V_17 . V_24 ;
return V_32 ;
}
static int F_43 ( T_4 V_91 , int V_78 )
{
T_3 V_23 ;
int V_2 ;
if ( ( V_78 == 0 ) && ( V_91 == V_40 )
&& ( V_9 . V_50 . V_8 & V_83 ) )
return V_92 ;
if ( F_22 ( V_93 , V_91 , V_78 ,
& V_23 , & V_2 ) )
return V_2 ;
if ( V_91 == V_40 ) {
if ( V_78 )
V_9 . V_50 . V_8 &= ~ V_79 ;
else
V_9 . V_50 . V_8 |= V_79 ;
}
return V_32 ;
}
static int F_44 ( int V_94 )
{
int error = V_80 ;
int V_3 ;
T_4 V_38 ;
static const T_4 V_56 [ 3 ] = { 0x100 , 0x1FF , 0x101 } ;
V_38 = V_94 ? V_95 : V_96 ;
for ( V_3 = 0 ; V_3 < F_45 ( V_56 ) ; V_3 ++ ) {
error = F_25 ( V_56 [ V_3 ] , V_38 ) ;
if ( ( error == V_32 ) || ( error == V_97 ) )
return 1 ;
if ( error == V_80 )
break;
}
if ( error == V_80 ) {
static int V_98 ;
int V_99 ;
if ( V_98 ++ == 0 ) {
V_99 = F_43 ( V_40 , 1 ) ;
if ( V_99 ) {
F_1 ( L_5 , error ) ;
F_1 ( L_6 , V_99 ) ;
return 0 ;
} else
return F_44 ( V_94 ) ;
}
}
F_1 ( L_5 , error ) ;
return 0 ;
}
static int F_46 ( struct V_100 * V_101 )
{
return V_101 -> V_102 == V_101 -> V_103 ;
}
static T_5 F_47 ( struct V_100 * V_101 )
{
if ( ++ V_101 -> V_103 >= V_104 )
V_101 -> V_103 = 0 ;
return V_101 -> V_105 [ V_101 -> V_103 ] ;
}
static void F_48 ( T_5 V_33 , struct V_100 * V_106 )
{
struct V_100 * V_101 ;
F_49 ( & V_107 ) ;
if ( V_108 == NULL )
goto V_109;
for ( V_101 = V_108 ; V_101 != NULL ; V_101 = V_101 -> V_110 ) {
if ( ( V_101 == V_106 ) || ( ! V_101 -> V_111 ) )
continue;
if ( ++ V_101 -> V_102 >= V_104 )
V_101 -> V_102 = 0 ;
if ( V_101 -> V_102 == V_101 -> V_103 ) {
static int V_112 ;
if ( V_112 ++ == 0 )
F_50 ( L_7 ) ;
if ( ++ V_101 -> V_103 >= V_104 )
V_101 -> V_103 = 0 ;
}
V_101 -> V_105 [ V_101 -> V_102 ] = V_33 ;
if ( ! V_101 -> V_113 || ! V_101 -> V_114 )
continue;
switch ( V_33 ) {
case V_115 :
case V_116 :
V_101 -> V_117 ++ ;
V_117 ++ ;
break;
case V_118 :
case V_119 :
V_101 -> V_120 ++ ;
V_120 ++ ;
break;
}
}
F_51 ( & V_121 ) ;
V_109:
F_52 ( & V_107 ) ;
}
static void F_53 ( void )
{
#ifdef F_54
unsigned long V_8 ;
F_55 ( & V_122 , V_8 ) ;
F_56 ( 0x34 , V_123 ) ;
F_57 ( 10 ) ;
F_56 ( V_124 & 0xff , V_125 ) ;
F_57 ( 10 ) ;
F_56 ( V_124 >> 8 , V_125 ) ;
F_57 ( 10 ) ;
F_58 ( & V_122 , V_8 ) ;
#endif
}
static int F_59 ( int V_126 )
{
int V_2 ;
struct V_100 * V_101 ;
F_60 ( V_127 ) ;
F_61 ( V_127 ) ;
F_7 () ;
F_62 () ;
F_6 () ;
F_63 () ;
V_2 = F_26 ( V_128 ) ;
V_129 = 1 ;
F_64 () ;
F_7 () ;
F_53 () ;
if ( V_2 == V_97 )
V_2 = V_32 ;
if ( V_2 != V_32 )
F_1 ( L_8 , V_2 ) ;
V_2 = ( V_2 == V_32 ) ? 0 : - V_130 ;
F_65 () ;
F_6 () ;
F_66 ( V_131 ) ;
F_67 ( V_131 ) ;
F_48 ( V_132 , NULL ) ;
F_49 ( & V_107 ) ;
for ( V_101 = V_108 ; V_101 != NULL ; V_101 = V_101 -> V_110 ) {
V_101 -> V_133 = 0 ;
V_101 -> V_134 = V_2 ;
}
F_52 ( & V_107 ) ;
F_51 ( & V_135 ) ;
return V_2 ;
}
static void F_68 ( void )
{
int V_2 ;
F_61 ( V_127 ) ;
F_7 () ;
F_62 () ;
F_6 () ;
V_2 = F_26 ( V_95 ) ;
if ( ( V_2 != V_32 ) && ( V_2 != V_97 ) )
F_1 ( L_9 , V_2 ) ;
F_7 () ;
F_65 () ;
F_6 () ;
F_66 ( V_131 ) ;
}
static T_5 F_69 ( void )
{
int error ;
T_5 V_33 = V_136 ;
T_6 V_34 ;
static int V_112 ;
error = F_24 ( & V_33 , & V_34 ) ;
if ( error == V_32 )
return V_33 ;
if ( ( error != V_136 ) && ( V_112 ++ == 0 ) )
F_1 ( L_10 , error ) ;
return 0 ;
}
static void F_70 ( void )
{
T_5 V_33 ;
static unsigned long V_137 ;
static int V_138 ;
while ( ( V_33 = F_69 () ) != 0 ) {
if ( V_139 ) {
if ( V_33 <= V_140 )
F_31 ( V_47 L_11 ,
V_141 [ V_33 - 1 ] ) ;
else
F_31 ( V_47 L_12
L_13 , V_33 ) ;
}
if ( V_138
&& ( F_71 ( V_48 , V_137 + V_142 ) ) )
V_138 = 0 ;
switch ( V_33 ) {
case V_118 :
case V_119 :
F_48 ( V_33 , NULL ) ;
if ( V_120 <= 0 )
F_68 () ;
break;
case V_116 :
#ifdef F_72
if ( V_9 . V_36 > 0x100 )
F_26 ( V_143 ) ;
break;
#endif
case V_115 :
if ( V_138 ) {
if ( V_9 . V_36 > 0x100 )
F_26 ( V_143 ) ;
break;
}
if ( V_144 )
return;
V_144 = 1 ;
F_48 ( V_33 , NULL ) ;
if ( V_117 <= 0 )
( void ) F_59 ( 1 ) ;
break;
case V_132 :
case V_145 :
case V_146 :
V_144 = 0 ;
V_137 = V_48 ;
V_138 = 1 ;
if ( ( V_33 != V_132 )
|| ( V_129 == 0 ) ) {
F_67 ( V_131 ) ;
F_48 ( V_33 , NULL ) ;
}
V_129 = 0 ;
break;
case V_147 :
case V_148 :
case V_149 :
F_48 ( V_33 , NULL ) ;
break;
case V_150 :
break;
case V_151 :
( void ) F_59 ( 0 ) ;
break;
}
}
}
static void F_73 ( void )
{
static int V_152 = 4 ;
int V_2 ;
if ( ( V_120 > 0 ) || ( V_117 > 0 ) ) {
if ( ( V_9 . V_36 > 0x100 ) &&
( V_152 -- <= 0 ) ) {
V_152 = 4 ;
if ( V_139 )
F_31 ( V_47 L_14 ) ;
V_2 = F_26 ( V_153 ) ;
if ( V_2 )
F_1 ( L_15 , V_2 ) ;
}
} else
V_152 = 4 ;
F_70 () ;
}
static void F_74 ( void )
{
F_75 ( V_154 , V_68 ) ;
F_76 ( & V_121 , & V_154 ) ;
F_77 ( V_155 ) ;
for (; ; ) {
F_78 ( V_156 ) ;
if ( F_79 () )
break;
F_77 ( V_155 ) ;
F_73 () ;
}
F_80 ( & V_121 , & V_154 ) ;
}
static int F_81 ( struct V_100 * V_101 , const char * V_20 )
{
if ( V_101 == NULL || V_101 -> V_157 != V_158 ) {
F_50 ( L_16 , V_20 ) ;
return 1 ;
}
return 0 ;
}
static T_8 F_82 ( struct V_159 * V_160 , char T_9 * V_161 , T_10 V_162 , T_11 * V_163 )
{
struct V_100 * V_101 ;
int V_3 ;
T_5 V_33 ;
V_101 = V_160 -> V_164 ;
if ( F_81 ( V_101 , L_17 ) )
return - V_130 ;
if ( ( int ) V_162 < sizeof( T_5 ) )
return - V_165 ;
if ( ( F_46 ( V_101 ) ) && ( V_160 -> V_166 & V_167 ) )
return - V_168 ;
F_83 ( V_121 , ! F_46 ( V_101 ) ) ;
V_3 = V_162 ;
while ( ( V_3 >= sizeof( V_33 ) ) && ! F_46 ( V_101 ) ) {
V_33 = F_47 ( V_101 ) ;
if ( F_84 ( V_161 , & V_33 , sizeof( V_33 ) ) ) {
if ( V_3 < V_162 )
break;
return - V_169 ;
}
switch ( V_33 ) {
case V_115 :
case V_116 :
V_101 -> V_170 ++ ;
break;
case V_118 :
case V_119 :
V_101 -> V_171 ++ ;
break;
}
V_161 += sizeof( V_33 ) ;
V_3 -= sizeof( V_33 ) ;
}
if ( V_3 < V_162 )
return V_162 - V_3 ;
if ( F_85 ( V_68 ) )
return - V_172 ;
return 0 ;
}
static unsigned int F_86 ( struct V_159 * V_160 , T_12 * V_154 )
{
struct V_100 * V_101 ;
V_101 = V_160 -> V_164 ;
if ( F_81 ( V_101 , L_18 ) )
return 0 ;
F_87 ( V_160 , & V_121 , V_154 ) ;
if ( ! F_46 ( V_101 ) )
return V_173 | V_174 ;
return 0 ;
}
static long F_88 ( struct V_159 * V_175 , T_13 V_176 , T_14 V_177 )
{
struct V_100 * V_101 ;
int V_27 ;
V_101 = V_175 -> V_164 ;
if ( F_81 ( V_101 , L_19 ) )
return - V_130 ;
if ( ! V_101 -> V_113 || ! V_101 -> V_114 )
return - V_178 ;
switch ( V_176 ) {
case V_179 :
F_89 ( & V_180 ) ;
if ( V_101 -> V_171 > 0 ) {
V_101 -> V_171 -- ;
V_101 -> V_120 -- ;
V_120 -- ;
} else
F_48 ( V_119 , V_101 ) ;
if ( V_120 <= 0 )
F_68 () ;
F_90 ( & V_180 ) ;
break;
case V_181 :
F_89 ( & V_180 ) ;
if ( V_101 -> V_170 > 0 ) {
V_101 -> V_170 -- ;
V_101 -> V_117 -- ;
V_117 -- ;
} else
F_48 ( V_116 , V_101 ) ;
if ( V_117 <= 0 ) {
V_27 = F_59 ( 1 ) ;
F_90 ( & V_180 ) ;
} else {
V_101 -> V_133 = 1 ;
F_90 ( & V_180 ) ;
F_83 ( V_135 ,
V_101 -> V_133 == 0 ) ;
V_27 = V_101 -> V_134 ;
}
return V_27 ;
default:
return - V_182 ;
}
return 0 ;
}
static int F_91 ( struct V_183 * V_183 , struct V_159 * V_175 )
{
struct V_100 * V_101 ;
V_101 = V_175 -> V_164 ;
if ( F_81 ( V_101 , L_20 ) )
return 0 ;
V_175 -> V_164 = NULL ;
if ( V_101 -> V_120 > 0 ) {
V_120 -= V_101 -> V_120 ;
if ( V_120 <= 0 )
F_68 () ;
}
if ( V_101 -> V_117 > 0 ) {
V_117 -= V_101 -> V_117 ;
if ( V_117 <= 0 )
( void ) F_59 ( 1 ) ;
}
F_49 ( & V_107 ) ;
if ( V_108 == V_101 )
V_108 = V_101 -> V_110 ;
else {
struct V_100 * V_184 ;
for ( V_184 = V_108 ;
( V_184 != NULL ) && ( V_184 -> V_110 != V_101 ) ;
V_184 = V_184 -> V_110 )
;
if ( V_184 == NULL )
F_50 ( L_21 ) ;
else
V_184 -> V_110 = V_101 -> V_110 ;
}
F_52 ( & V_107 ) ;
F_92 ( V_101 ) ;
return 0 ;
}
static int F_93 ( struct V_183 * V_183 , struct V_159 * V_175 )
{
struct V_100 * V_101 ;
V_101 = F_94 ( sizeof( * V_101 ) , V_185 ) ;
if ( V_101 == NULL )
return - V_186 ;
V_101 -> V_157 = V_158 ;
V_101 -> V_103 = V_101 -> V_102 = 0 ;
V_101 -> V_117 = V_101 -> V_120 = 0 ;
V_101 -> V_170 = V_101 -> V_171 = 0 ;
V_101 -> V_113 = F_95 ( V_187 ) ;
V_101 -> V_114 = ( V_175 -> V_188 & V_189 ) == V_189 ;
V_101 -> V_111 = ( V_175 -> V_188 & V_190 ) == V_190 ;
F_49 ( & V_107 ) ;
V_101 -> V_110 = V_108 ;
V_108 = V_101 ;
F_52 ( & V_107 ) ;
V_175 -> V_164 = V_101 ;
return 0 ;
}
static int F_96 ( struct V_191 * V_192 , void * V_193 )
{
unsigned short V_194 ;
unsigned short V_195 ;
unsigned short V_196 ;
int error ;
unsigned short V_197 = 0xff ;
unsigned short V_198 = 0xff ;
unsigned short V_199 = 0xff ;
int V_200 = - 1 ;
int V_201 = - 1 ;
char * V_202 = L_22 ;
if ( ( F_97 () == 1 ) &&
! ( error = F_41 ( & V_194 , & V_195 , & V_196 ) ) ) {
V_197 = ( V_194 >> 8 ) & 0xff ;
V_198 = V_194 & 0xff ;
if ( ( V_195 & 0xff ) != 0xff )
V_200 = V_195 & 0xff ;
if ( V_9 . V_36 > 0x100 ) {
V_199 = ( V_195 >> 8 ) & 0xff ;
if ( V_196 != 0xffff ) {
V_202 = ( V_196 & 0x8000 ) ? L_23 : L_24 ;
V_201 = V_196 & 0x7fff ;
}
}
}
F_98 ( V_192 , L_25 ,
V_203 ,
( V_9 . V_50 . V_204 >> 8 ) & 0xff ,
V_9 . V_50 . V_204 & 0xff ,
V_9 . V_50 . V_8 ,
V_197 ,
V_198 ,
V_199 ,
V_200 ,
V_201 ,
V_202 ) ;
return 0 ;
}
static int F_99 ( struct V_183 * V_183 , struct V_159 * V_159 )
{
return F_100 ( V_159 , F_96 , NULL ) ;
}
static int F_101 ( void * V_205 )
{
unsigned short V_194 ;
unsigned short V_195 ;
unsigned short V_196 ;
int error ;
char * V_206 ;
char * V_207 ;
F_37 ( V_68 , F_38 ( 0 ) ) ;
F_12 ( F_102 () != 0 ) ;
if ( V_9 . V_36 == 0 ) {
V_9 . V_36 = V_9 . V_50 . V_204 ;
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
if ( V_139 )
F_31 ( V_208 L_27 ,
( V_9 . V_36 >> 8 ) & 0xff ,
V_9 . V_36 & 0xff ) ;
#ifdef F_103
if ( V_9 . V_50 . V_8 & V_83 ) {
error = F_40 ( 1 ) ;
if ( error ) {
F_1 ( L_28 , error ) ;
return - 1 ;
}
}
#endif
if ( ( V_9 . V_50 . V_8 & V_79 )
&& ( V_9 . V_36 > 0x0100 ) ) {
error = F_43 ( V_40 , 1 ) ;
if ( error ) {
F_1 ( L_29 , error ) ;
return - 1 ;
}
}
if ( V_139 && ( F_97 () == 1 || V_209 ) ) {
error = F_41 ( & V_194 , & V_195 , & V_196 ) ;
if ( error )
F_31 ( V_208 L_30 ) ;
else {
switch ( ( V_194 >> 8 ) & 0xff ) {
case 0 :
V_206 = L_31 ;
break;
case 1 :
V_206 = L_32 ;
break;
case 2 :
V_206 = L_33 ;
break;
default:
V_206 = L_34 ;
break;
}
switch ( V_194 & 0xff ) {
case 0 :
V_207 = L_35 ;
break;
case 1 :
V_207 = L_36 ;
break;
case 2 :
V_207 = L_37 ;
break;
case 3 :
V_207 = L_38 ;
break;
default:
V_207 = L_34 ;
break;
}
F_31 ( V_208
L_39 ,
V_206 , V_207 ) ;
if ( ( V_195 & 0xff ) == 0xff )
F_31 ( L_40 ) ;
else
F_31 ( L_41 , V_195 & 0xff ) ;
if ( V_9 . V_36 > 0x100 ) {
F_31 ( V_208
L_42 ,
( V_195 >> 8 ) & 0xff ) ;
if ( V_196 == 0xffff )
F_31 ( L_40 ) ;
else
F_31 ( L_43 , V_196 & 0x7fff ,
( V_196 & 0x8000 ) ?
L_44 : L_45 ) ;
}
}
}
if ( V_210 )
V_211 = F_36 ;
if ( F_97 () == 1 || V_209 ) {
#if F_104 ( V_212 ) && F_104 ( V_213 )
V_214 = F_44 ;
#endif
F_74 () ;
#if F_104 ( V_212 ) && F_104 ( V_213 )
V_214 = NULL ;
#endif
}
return 0 ;
}
static int T_15 F_105 ( char * V_1 )
{
int V_215 ;
while ( ( V_1 != NULL ) && ( * V_1 != '\0' ) ) {
if ( strncmp ( V_1 , L_46 , 3 ) == 0 )
V_216 = 1 ;
if ( strncmp ( V_1 , L_47 , 2 ) == 0 )
V_216 = 0 ;
if ( ( strncmp ( V_1 , L_48 , 16 ) == 0 ) ||
( strncmp ( V_1 , L_49 , 16 ) == 0 ) )
V_142 = F_106 ( V_1 + 16 , NULL , 0 ) ;
if ( ( strncmp ( V_1 , L_50 , 15 ) == 0 ) ||
( strncmp ( V_1 , L_51 , 15 ) == 0 ) )
V_72 = F_106 ( V_1 + 15 , NULL , 0 ) ;
if ( ( strncmp ( V_1 , L_52 , 12 ) == 0 ) ||
( strncmp ( V_1 , L_53 , 12 ) == 0 ) )
V_70 = F_106 ( V_1 + 12 , NULL , 0 ) ;
V_215 = ( strncmp ( V_1 , L_54 , 3 ) == 0 ) ||
( strncmp ( V_1 , L_55 , 3 ) == 0 ) ;
if ( V_215 )
V_1 += 3 ;
if ( strncmp ( V_1 , L_56 , 5 ) == 0 )
V_139 = ! V_215 ;
if ( ( strncmp ( V_1 , L_57 , 9 ) == 0 ) ||
( strncmp ( V_1 , L_58 , 9 ) == 0 ) )
V_210 = ! V_215 ;
if ( strncmp ( V_1 , L_59 , 3 ) == 0 ) {
V_209 = ! V_215 ;
V_72 = 100 ;
}
if ( ( strncmp ( V_1 , L_60 , 10 ) == 0 ) ||
( strncmp ( V_1 , L_61 , 10 ) == 0 ) )
V_9 . V_10 = ! V_215 ;
if ( ( strncmp ( V_1 , L_62 , 10 ) == 0 ) ||
( strncmp ( V_1 , L_63 , 10 ) == 0 ) )
V_9 . V_87 = ! V_215 ;
if ( ( strncmp ( V_1 , L_64 , 18 ) == 0 ) ||
( strncmp ( V_1 , L_65 , 18 ) == 0 ) )
V_9 . V_75 = ! V_215 ;
V_1 = strchr ( V_1 , ',' ) ;
if ( V_1 != NULL )
V_1 += strspn ( V_1 , L_66 ) ;
}
return 1 ;
}
static int T_15 F_107 ( const struct V_217 * V_218 )
{
F_31 ( L_67 , V_218 -> V_219 ) ;
return 0 ;
}
static int T_15 F_108 ( const struct V_217 * V_218 )
{
F_31 ( V_208 L_68
L_69 , V_218 -> V_219 ) ;
return 0 ;
}
static int T_15 F_109 ( const struct V_217 * V_218 )
{
if ( V_9 . V_75 == 0 ) {
V_9 . V_75 = 1 ;
F_31 ( V_208 L_70
L_71 , V_218 -> V_219 ) ;
}
return 0 ;
}
static int T_15 F_110 ( const struct V_217 * V_218 )
{
if ( V_9 . V_10 == 0 ) {
V_9 . V_10 = 1 ;
F_31 ( V_208 L_72
L_73 , V_218 -> V_219 ) ;
}
return 0 ;
}
static int T_15 F_111 ( const struct V_217 * V_218 )
{
if ( V_9 . V_220 == 0 ) {
V_9 . V_220 = 1 ;
F_31 ( V_208 L_72
L_74 , V_218 -> V_219 ) ;
}
return 0 ;
}
static int T_15 F_112 ( const struct V_217 * V_218 )
{
if ( V_9 . V_220 == 0 ) {
V_9 . V_220 = 1 ;
F_31 ( V_208 L_72
L_74 , V_218 -> V_219 ) ;
F_31 ( V_208 L_75 ) ;
F_31 ( V_208 L_76 ) ;
}
return 0 ;
}
static int T_15 F_113 ( const struct V_217 * V_218 )
{
if ( V_9 . V_73 == 0 ) {
V_9 . V_73 = 1 ;
F_31 ( V_208 L_72
L_77 , V_218 -> V_219 ) ;
}
return 0 ;
}
static int T_15 F_114 ( const struct V_217 * V_218 )
{
V_9 . V_87 = 1 ;
F_31 ( V_221 L_78
L_79 ) ;
return 0 ;
}
static int T_15 F_115 ( const struct V_217 * V_218 )
{
V_9 . V_89 = 1 ;
F_31 ( V_221 L_80
L_81 ) ;
return 0 ;
}
static int T_15 F_116 ( void )
{
struct V_13 * V_15 ;
int V_2 ;
F_117 ( V_222 ) ;
if ( V_9 . V_50 . V_204 == 0 || F_118 () || F_119 () ) {
F_31 ( V_208 L_82 ) ;
return - V_223 ;
}
F_31 ( V_208
L_83 ,
( ( V_9 . V_50 . V_204 >> 8 ) & 0xff ) ,
( V_9 . V_50 . V_204 & 0xff ) ,
V_9 . V_50 . V_8 ,
V_203 ) ;
if ( ( V_9 . V_50 . V_8 & V_224 ) == 0 ) {
F_31 ( V_208 L_84 ) ;
return - V_223 ;
}
if ( V_10 )
V_9 . V_10 = 1 ;
if ( V_225 )
V_9 . V_87 = 1 ;
if ( V_75 )
V_9 . V_75 = 1 ;
if ( V_216 != - 1 )
V_9 . V_220 = V_216 ;
if ( V_9 . V_50 . V_204 == 0x001 )
V_9 . V_50 . V_204 = 0x100 ;
if ( V_9 . V_50 . V_204 < 0x102 )
V_9 . V_50 . V_226 = 0 ;
if ( V_139 ) {
F_31 ( V_208 L_85 ,
V_9 . V_50 . V_227 , V_9 . V_50 . V_228 ,
V_9 . V_50 . V_229 , V_9 . V_50 . V_230 ) ;
if ( V_9 . V_50 . V_204 > 0x100 )
F_31 ( L_86 ,
V_9 . V_50 . V_231 ,
V_9 . V_50 . V_232 ) ;
if ( V_9 . V_50 . V_204 > 0x101 )
F_31 ( L_87 , V_9 . V_50 . V_226 ) ;
F_31 ( L_88 ) ;
}
if ( V_9 . V_220 ) {
F_2 ( L_89 ) ;
return - V_223 ;
}
if ( ( F_97 () > 1 ) && ! V_210 && ! V_209 ) {
F_2 ( L_90 ) ;
V_9 . V_220 = 1 ;
return - V_223 ;
}
if ( ! V_233 ) {
F_2 ( L_91 ) ;
V_9 . V_220 = 1 ;
return - V_223 ;
}
V_234 . V_228 = V_9 . V_50 . V_228 ;
V_234 . V_235 = V_236 ;
V_15 = F_13 ( 0 ) ;
F_120 ( & V_15 [ V_236 >> 3 ] ,
( unsigned long ) F_121 ( ( unsigned long ) V_9 . V_50 . V_227 << 4 ) ) ;
F_120 ( & V_15 [ V_237 >> 3 ] ,
( unsigned long ) F_121 ( ( unsigned long ) V_9 . V_50 . V_229 << 4 ) ) ;
F_120 ( & V_15 [ V_238 >> 3 ] ,
( unsigned long ) F_121 ( ( unsigned long ) V_9 . V_50 . V_230 << 4 ) ) ;
F_122 ( L_92 , 0 , NULL , & V_239 ) ;
V_240 = F_123 ( F_101 , NULL , L_93 ) ;
if ( F_124 ( V_240 ) ) {
F_50 ( L_94 ) ;
V_2 = F_125 ( V_240 ) ;
V_240 = NULL ;
F_126 ( L_92 , NULL ) ;
return V_2 ;
}
F_127 ( V_240 ) ;
if ( F_97 () > 1 && ! V_209 ) {
F_31 ( V_241
L_95 ) ;
return 0 ;
}
if ( F_128 ( & V_242 ) )
F_31 ( V_221 L_96 ) ;
if ( V_243 != 100 )
V_70 = ( V_70 * V_243 ) / 100 ;
if ( V_72 < 100 ) {
if ( ! F_129 ( & V_244 ) )
if ( F_130 ( & V_245 ) )
F_131 ( & V_244 ) ;
}
return 0 ;
}
static void T_16 F_132 ( void )
{
int error ;
F_133 ( & V_245 ) ;
F_131 ( & V_244 ) ;
if ( ( ( V_9 . V_50 . V_8 & V_79 ) == 0 )
&& ( V_9 . V_36 > 0x0100 ) ) {
error = F_43 ( V_40 , 0 ) ;
if ( error )
F_1 ( L_97 , error ) ;
}
F_134 ( & V_242 ) ;
F_126 ( L_92 , NULL ) ;
if ( V_210 )
V_211 = NULL ;
if ( V_240 ) {
F_135 ( V_240 ) ;
V_240 = NULL ;
}
}
