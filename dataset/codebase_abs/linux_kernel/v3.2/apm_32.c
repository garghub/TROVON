static void F_1 ( char * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
if ( V_5 [ V_3 ] . V_6 == V_2 )
break;
if ( V_3 < V_4 )
F_2 ( V_7 L_1 , V_1 , V_5 [ V_3 ] . V_8 ) ;
else if ( V_2 < 0 )
F_2 ( V_7 L_2 , V_1 , V_2 ) ;
else
F_2 ( V_7 L_3 ,
V_1 , V_2 ) ;
}
static inline unsigned long F_3 ( void )
{
unsigned long V_9 ;
F_4 ( V_9 ) ;
if ( V_10 . V_11 ) {
if ( F_5 ( V_9 ) )
F_6 () ;
} else
F_7 () ;
return V_9 ;
}
static inline void F_8 ( unsigned long V_9 )
{
if ( F_5 ( V_9 ) )
F_7 () ;
else if ( F_9 () )
F_6 () ;
}
static long F_10 ( void * V_12 )
{
T_1
unsigned long V_9 ;
int V_13 ;
struct V_14 V_15 ;
struct V_14 * V_16 ;
struct V_17 * V_18 = V_12 ;
V_13 = F_11 () ;
F_12 ( V_13 != 0 ) ;
V_16 = F_13 ( V_13 ) ;
V_15 = V_16 [ 0x40 / 8 ] ;
V_16 [ 0x40 / 8 ] = V_19 ;
F_14 ( V_9 ) ;
V_20 ;
F_15 ( V_18 -> V_21 , V_18 -> V_22 , V_18 -> V_23 ,
& V_18 -> V_24 , & V_18 -> V_22 , & V_18 -> V_23 , & V_18 -> V_25 ,
& V_18 -> V_26 ) ;
V_27 ;
F_8 ( V_9 ) ;
V_16 [ 0x40 / 8 ] = V_15 ;
F_16 () ;
return V_18 -> V_24 & 0xff ;
}
static int F_17 ( long (* F_18)( void * ) , struct V_17 * V_18 )
{
int V_28 ;
if ( F_11 () == 0 ) {
V_28 = F_18 ( V_18 ) ;
F_16 () ;
} else {
F_16 () ;
V_28 = F_19 ( 0 , F_18 , V_18 ) ;
}
if ( V_28 < 0 )
V_18 -> V_2 = V_28 ;
else
V_18 -> V_2 = ( V_18 -> V_24 >> 8 ) & 0xff ;
return V_28 ;
}
static int V_17 ( struct V_17 * V_18 )
{
return F_17 ( F_10 , V_18 ) ;
}
static long F_20 ( void * V_12 )
{
T_2 error ;
T_1
unsigned long V_9 ;
int V_13 ;
struct V_14 V_15 ;
struct V_14 * V_16 ;
struct V_17 * V_18 = V_12 ;
V_13 = F_11 () ;
F_12 ( V_13 != 0 ) ;
V_16 = F_13 ( V_13 ) ;
V_15 = V_16 [ 0x40 / 8 ] ;
V_16 [ 0x40 / 8 ] = V_19 ;
F_14 ( V_9 ) ;
V_20 ;
error = F_21 ( V_18 -> V_21 , V_18 -> V_22 , V_18 -> V_23 ,
& V_18 -> V_24 ) ;
V_27 ;
F_8 ( V_9 ) ;
V_16 [ 0x40 / 8 ] = V_15 ;
F_16 () ;
return error ;
}
static int F_22 ( T_3 V_21 , T_3 V_29 , T_3 V_30 , T_3 * V_24 ,
int * V_2 )
{
struct V_17 V_18 ;
int V_28 ;
V_18 . V_21 = V_21 ;
V_18 . V_22 = V_29 ;
V_18 . V_23 = V_30 ;
V_28 = F_17 ( F_20 , & V_18 ) ;
* V_24 = V_18 . V_24 ;
* V_2 = V_18 . V_2 ;
return V_28 ;
}
static int F_23 ( T_4 * V_31 )
{
T_3 V_24 ;
int V_2 ;
if ( F_22 ( V_32 , 0 , * V_31 , & V_24 , & V_2 ) )
return V_2 ;
* V_31 = V_24 ;
return V_33 ;
}
static int F_24 ( T_5 * V_34 , T_6 * V_35 )
{
struct V_17 V_18 ;
V_18 . V_21 = V_36 ;
V_18 . V_22 = V_18 . V_23 = 0 ;
if ( V_17 ( & V_18 ) )
return V_18 . V_2 ;
* V_34 = V_18 . V_22 ;
if ( V_10 . V_37 < 0x0102 )
* V_35 = ~ 0 ;
else
* V_35 = V_18 . V_23 ;
return V_33 ;
}
static int F_25 ( T_4 V_38 , T_4 V_39 )
{
T_3 V_24 ;
int V_2 ;
if ( F_22 ( V_40 , V_38 , V_39 , & V_24 , & V_2 ) )
return V_2 ;
return V_33 ;
}
static int F_26 ( T_4 V_39 )
{
return F_25 ( V_41 , V_39 ) ;
}
static int F_27 ( void )
{
T_3 V_24 ;
T_2 V_28 = 0 ;
int V_42 = 0 ;
int V_43 ;
int V_2 = 0 ;
V_43 = ! ! ( F_28 () -> V_44 & V_45 ) ;
if ( V_43 ) {
F_28 () -> V_44 &= ~ V_45 ;
F_29 () ;
}
if ( ! F_30 () ) {
V_42 = 1 ;
V_28 = F_22 ( V_46 , 0 , 0 , & V_24 , & V_2 ) ;
}
if ( V_43 )
F_28 () -> V_44 |= V_45 ;
if ( ! V_42 )
return 0 ;
if ( V_28 ) {
static unsigned long V_47 ;
if ( ++ V_47 < 5 ) {
F_2 ( V_48 L_4 , V_2 ) ;
V_47 = V_49 ;
}
return - 1 ;
}
V_50 = ( V_10 . V_51 . V_9 & V_52 ) != 0 ;
return V_50 ;
}
static void F_31 ( void )
{
T_3 V_53 ;
int V_2 ;
if ( V_50 || V_54 ) {
( void ) F_22 ( V_55 , 0 , 0 , & V_53 , & V_2 ) ;
V_50 = 0 ;
}
}
static void F_32 ( void )
{
static int V_56 ;
static unsigned int V_57 ;
static unsigned int V_58 ;
int V_59 = 0 ;
unsigned int V_60 = V_49 - V_57 ;
unsigned int V_61 ;
F_33 ( 1 , L_5 ) ;
V_62:
if ( V_60 > V_63 ) {
V_56 = 0 ;
V_57 = V_49 ;
V_58 = V_64 -> V_65 ;
} else if ( V_60 > V_66 ) {
unsigned int V_67 ;
V_67 = V_64 -> V_65 - V_58 ;
V_67 *= 100 ;
V_67 /= V_60 ;
V_56 = ( V_67 > V_68 ) ;
if ( V_10 . V_69 )
V_56 = 0 ;
V_57 = V_49 ;
V_58 = V_64 -> V_65 ;
}
V_61 = V_70 ;
while ( ! F_30 () ) {
if ( V_56 ) {
unsigned int V_47 ;
V_47 = V_49 ;
switch ( F_27 () ) {
case 0 :
V_59 = 1 ;
if ( V_47 != V_49 ) {
if ( V_61 ) {
V_61 = V_70 ;
continue;
}
} else if ( V_61 ) {
V_61 -- ;
continue;
}
break;
case 1 :
V_59 = 1 ;
break;
default:
break;
}
}
if ( V_71 )
V_71 () ;
else
F_34 () ;
F_7 () ;
V_60 = V_49 - V_57 ;
if ( V_60 > V_66 )
goto V_62;
}
if ( V_59 )
F_31 () ;
F_6 () ;
}
static void F_35 ( void )
{
if ( V_10 . V_72 ) {
F_36 ( V_64 , F_37 ( 0 ) ) ;
F_38 ( V_73 ) ;
} else {
( void ) F_26 ( V_74 ) ;
}
}
static int F_39 ( int V_75 )
{
T_3 V_24 ;
int V_2 ;
if ( ( V_75 == 0 ) && ( V_10 . V_51 . V_9 & V_76 ) )
return V_77 ;
if ( F_22 ( V_78 , V_79 ,
V_75 , & V_24 , & V_2 ) )
return V_2 ;
if ( V_75 )
V_10 . V_51 . V_9 &= ~ V_80 ;
else
V_10 . V_51 . V_9 |= V_80 ;
return V_33 ;
}
static int F_40 ( T_4 * V_44 , T_4 * V_81 , T_4 * V_82 )
{
struct V_17 V_18 ;
V_18 . V_21 = V_83 ;
V_18 . V_22 = V_41 ;
V_18 . V_23 = 0 ;
if ( V_10 . V_84 )
return V_85 ;
if ( V_17 ( & V_18 ) )
return V_18 . V_2 ;
* V_44 = V_18 . V_22 ;
* V_81 = V_18 . V_23 ;
if ( V_10 . V_86 ) {
* V_82 = F_41 ( ( V_87 ) V_18 . V_25 ) ;
* V_82 |= 0x8000 ;
} else
* V_82 = V_18 . V_25 ;
return V_33 ;
}
static int F_42 ( T_4 V_88 , int V_75 )
{
T_3 V_24 ;
int V_2 ;
if ( ( V_75 == 0 ) && ( V_88 == V_41 )
&& ( V_10 . V_51 . V_9 & V_80 ) )
return V_89 ;
if ( F_22 ( V_90 , V_88 , V_75 ,
& V_24 , & V_2 ) )
return V_2 ;
if ( V_88 == V_41 ) {
if ( V_75 )
V_10 . V_51 . V_9 &= ~ V_76 ;
else
V_10 . V_51 . V_9 |= V_76 ;
}
return V_33 ;
}
static int F_43 ( int V_91 )
{
int error = V_77 ;
int V_3 ;
T_4 V_39 ;
static const T_4 V_92 [ 3 ] = { 0x100 , 0x1FF , 0x101 } ;
V_39 = V_91 ? V_93 : V_94 ;
for ( V_3 = 0 ; V_3 < F_44 ( V_92 ) ; V_3 ++ ) {
error = F_25 ( V_92 [ V_3 ] , V_39 ) ;
if ( ( error == V_33 ) || ( error == V_95 ) )
return 1 ;
if ( error == V_77 )
break;
}
if ( error == V_77 ) {
static int V_96 ;
int V_97 ;
if ( V_96 ++ == 0 ) {
V_97 = F_42 ( V_41 , 1 ) ;
if ( V_97 ) {
F_1 ( L_6 , error ) ;
F_1 ( L_7 , V_97 ) ;
return 0 ;
} else
return F_43 ( V_91 ) ;
}
}
F_1 ( L_6 , error ) ;
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
static void F_47 ( T_5 V_34 , struct V_98 * V_104 )
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
F_2 ( V_111 L_8 ) ;
if ( ++ V_99 -> V_101 >= V_102 )
V_99 -> V_101 = 0 ;
}
V_99 -> V_103 [ V_99 -> V_100 ] = V_34 ;
if ( ! V_99 -> V_112 || ! V_99 -> V_113 )
continue;
switch ( V_34 ) {
case V_114 :
case V_115 :
V_99 -> V_116 ++ ;
V_116 ++ ;
break;
case V_117 :
case V_118 :
V_99 -> V_119 ++ ;
V_119 ++ ;
break;
}
}
F_49 ( & V_120 ) ;
V_107:
F_50 ( & V_105 ) ;
}
static void F_51 ( void )
{
#ifdef F_52
unsigned long V_9 ;
F_53 ( & V_121 , V_9 ) ;
F_54 ( 0x34 , V_122 ) ;
F_55 ( 10 ) ;
F_54 ( V_123 & 0xff , V_124 ) ;
F_55 ( 10 ) ;
F_54 ( V_123 >> 8 , V_124 ) ;
F_55 ( 10 ) ;
F_56 ( & V_121 , V_9 ) ;
#endif
}
static int F_57 ( int V_125 )
{
int V_2 ;
struct V_98 * V_99 ;
F_58 ( V_126 ) ;
F_59 ( V_126 ) ;
F_7 () ;
F_60 () ;
F_6 () ;
F_61 () ;
V_2 = F_26 ( V_127 ) ;
V_128 = 1 ;
F_62 () ;
F_7 () ;
F_51 () ;
if ( V_2 == V_95 )
V_2 = V_33 ;
if ( V_2 != V_33 )
F_1 ( L_9 , V_2 ) ;
V_2 = ( V_2 == V_33 ) ? 0 : - V_129 ;
F_63 () ;
F_6 () ;
F_64 ( V_130 ) ;
F_65 ( V_130 ) ;
F_47 ( V_131 , NULL ) ;
F_48 ( & V_105 ) ;
for ( V_99 = V_106 ; V_99 != NULL ; V_99 = V_99 -> V_108 ) {
V_99 -> V_132 = 0 ;
V_99 -> V_133 = V_2 ;
}
F_50 ( & V_105 ) ;
F_49 ( & V_134 ) ;
return V_2 ;
}
static void F_66 ( void )
{
int V_2 ;
F_59 ( V_126 ) ;
F_7 () ;
F_60 () ;
F_6 () ;
V_2 = F_26 ( V_93 ) ;
if ( ( V_2 != V_33 ) && ( V_2 != V_95 ) )
F_1 ( L_10 , V_2 ) ;
F_7 () ;
F_63 () ;
F_6 () ;
F_64 ( V_130 ) ;
}
static T_5 F_67 ( void )
{
int error ;
T_5 V_34 = V_135 ;
T_6 V_35 ;
static int V_110 ;
error = F_24 ( & V_34 , & V_35 ) ;
if ( error == V_33 )
return V_34 ;
if ( ( error != V_135 ) && ( V_110 ++ == 0 ) )
F_1 ( L_11 , error ) ;
return 0 ;
}
static void F_68 ( void )
{
T_5 V_34 ;
static unsigned long V_136 ;
static int V_137 ;
while ( ( V_34 = F_67 () ) != 0 ) {
if ( V_138 ) {
if ( V_34 <= V_139 )
F_2 ( V_48 L_12 ,
V_140 [ V_34 - 1 ] ) ;
else
F_2 ( V_48 L_13
L_14 , V_34 ) ;
}
if ( V_137
&& ( F_69 ( V_49 , V_136 + V_141 ) ) )
V_137 = 0 ;
switch ( V_34 ) {
case V_117 :
case V_118 :
F_47 ( V_34 , NULL ) ;
if ( V_119 <= 0 )
F_66 () ;
break;
case V_115 :
#ifdef F_70
if ( V_10 . V_37 > 0x100 )
F_26 ( V_142 ) ;
break;
#endif
case V_114 :
if ( V_137 ) {
if ( V_10 . V_37 > 0x100 )
F_26 ( V_142 ) ;
break;
}
if ( V_143 )
return;
V_143 = 1 ;
F_47 ( V_34 , NULL ) ;
if ( V_116 <= 0 )
( void ) F_57 ( 1 ) ;
break;
case V_131 :
case V_144 :
case V_145 :
V_143 = 0 ;
V_136 = V_49 ;
V_137 = 1 ;
if ( ( V_34 != V_131 )
|| ( V_128 == 0 ) ) {
F_65 ( V_130 ) ;
F_47 ( V_34 , NULL ) ;
}
V_128 = 0 ;
break;
case V_146 :
case V_147 :
case V_148 :
F_47 ( V_34 , NULL ) ;
break;
case V_149 :
break;
case V_150 :
( void ) F_57 ( 0 ) ;
break;
}
}
}
static void F_71 ( void )
{
static int V_151 = 4 ;
int V_2 ;
if ( ( V_119 > 0 ) || ( V_116 > 0 ) ) {
if ( ( V_10 . V_37 > 0x100 ) &&
( V_151 -- <= 0 ) ) {
V_151 = 4 ;
if ( V_138 )
F_2 ( V_48 L_15 ) ;
V_2 = F_26 ( V_152 ) ;
if ( V_2 )
F_1 ( L_16 , V_2 ) ;
}
} else
V_151 = 4 ;
F_68 () ;
}
static void F_72 ( void )
{
F_73 ( V_153 , V_64 ) ;
F_74 ( & V_120 , & V_153 ) ;
F_75 ( V_154 ) ;
for (; ; ) {
F_76 ( V_155 ) ;
if ( F_77 () )
break;
F_75 ( V_154 ) ;
F_71 () ;
}
F_78 ( & V_120 , & V_153 ) ;
}
static int F_79 ( struct V_98 * V_99 , const char * V_21 )
{
if ( V_99 == NULL || V_99 -> V_156 != V_157 ) {
F_2 ( V_111 L_17 , V_21 ) ;
return 1 ;
}
return 0 ;
}
static T_7 F_80 ( struct V_158 * V_159 , char T_8 * V_160 , T_9 V_161 , T_10 * V_162 )
{
struct V_98 * V_99 ;
int V_3 ;
T_5 V_34 ;
V_99 = V_159 -> V_163 ;
if ( F_79 ( V_99 , L_18 ) )
return - V_129 ;
if ( ( int ) V_161 < sizeof( T_5 ) )
return - V_164 ;
if ( ( F_45 ( V_99 ) ) && ( V_159 -> V_165 & V_166 ) )
return - V_167 ;
F_81 ( V_120 , ! F_45 ( V_99 ) ) ;
V_3 = V_161 ;
while ( ( V_3 >= sizeof( V_34 ) ) && ! F_45 ( V_99 ) ) {
V_34 = F_46 ( V_99 ) ;
if ( F_82 ( V_160 , & V_34 , sizeof( V_34 ) ) ) {
if ( V_3 < V_161 )
break;
return - V_168 ;
}
switch ( V_34 ) {
case V_114 :
case V_115 :
V_99 -> V_169 ++ ;
break;
case V_117 :
case V_118 :
V_99 -> V_170 ++ ;
break;
}
V_160 += sizeof( V_34 ) ;
V_3 -= sizeof( V_34 ) ;
}
if ( V_3 < V_161 )
return V_161 - V_3 ;
if ( F_83 ( V_64 ) )
return - V_171 ;
return 0 ;
}
static unsigned int F_84 ( struct V_158 * V_159 , T_11 * V_153 )
{
struct V_98 * V_99 ;
V_99 = V_159 -> V_163 ;
if ( F_79 ( V_99 , L_19 ) )
return 0 ;
F_85 ( V_159 , & V_120 , V_153 ) ;
if ( ! F_45 ( V_99 ) )
return V_172 | V_173 ;
return 0 ;
}
static long F_86 ( struct V_158 * V_174 , T_12 V_175 , T_13 V_176 )
{
struct V_98 * V_99 ;
int V_28 ;
V_99 = V_174 -> V_163 ;
if ( F_79 ( V_99 , L_20 ) )
return - V_129 ;
if ( ! V_99 -> V_112 || ! V_99 -> V_113 )
return - V_177 ;
switch ( V_175 ) {
case V_178 :
F_87 ( & V_179 ) ;
if ( V_99 -> V_170 > 0 ) {
V_99 -> V_170 -- ;
V_99 -> V_119 -- ;
V_119 -- ;
} else
F_47 ( V_118 , V_99 ) ;
if ( V_119 <= 0 )
F_66 () ;
F_88 ( & V_179 ) ;
break;
case V_180 :
F_87 ( & V_179 ) ;
if ( V_99 -> V_169 > 0 ) {
V_99 -> V_169 -- ;
V_99 -> V_116 -- ;
V_116 -- ;
} else
F_47 ( V_115 , V_99 ) ;
if ( V_116 <= 0 ) {
V_28 = F_57 ( 1 ) ;
F_88 ( & V_179 ) ;
} else {
V_99 -> V_132 = 1 ;
F_88 ( & V_179 ) ;
F_81 ( V_134 ,
V_99 -> V_132 == 0 ) ;
V_28 = V_99 -> V_133 ;
}
return V_28 ;
default:
return - V_181 ;
}
return 0 ;
}
static int F_89 ( struct V_182 * V_182 , struct V_158 * V_174 )
{
struct V_98 * V_99 ;
V_99 = V_174 -> V_163 ;
if ( F_79 ( V_99 , L_21 ) )
return 0 ;
V_174 -> V_163 = NULL ;
if ( V_99 -> V_119 > 0 ) {
V_119 -= V_99 -> V_119 ;
if ( V_119 <= 0 )
F_66 () ;
}
if ( V_99 -> V_116 > 0 ) {
V_116 -= V_99 -> V_116 ;
if ( V_116 <= 0 )
( void ) F_57 ( 1 ) ;
}
F_48 ( & V_105 ) ;
if ( V_106 == V_99 )
V_106 = V_99 -> V_108 ;
else {
struct V_98 * V_183 ;
for ( V_183 = V_106 ;
( V_183 != NULL ) && ( V_183 -> V_108 != V_99 ) ;
V_183 = V_183 -> V_108 )
;
if ( V_183 == NULL )
F_2 ( V_111 L_22 ) ;
else
V_183 -> V_108 = V_99 -> V_108 ;
}
F_50 ( & V_105 ) ;
F_90 ( V_99 ) ;
return 0 ;
}
static int F_91 ( struct V_182 * V_182 , struct V_158 * V_174 )
{
struct V_98 * V_99 ;
V_99 = F_92 ( sizeof( * V_99 ) , V_184 ) ;
if ( V_99 == NULL ) {
F_2 ( V_111 L_23 ,
sizeof( * V_99 ) ) ;
return - V_185 ;
}
V_99 -> V_156 = V_157 ;
V_99 -> V_101 = V_99 -> V_100 = 0 ;
V_99 -> V_116 = V_99 -> V_119 = 0 ;
V_99 -> V_169 = V_99 -> V_170 = 0 ;
V_99 -> V_112 = F_93 ( V_186 ) ;
V_99 -> V_113 = ( V_174 -> V_187 & V_188 ) == V_188 ;
V_99 -> V_109 = ( V_174 -> V_187 & V_189 ) == V_189 ;
F_48 ( & V_105 ) ;
V_99 -> V_108 = V_106 ;
V_106 = V_99 ;
F_50 ( & V_105 ) ;
V_174 -> V_163 = V_99 ;
return 0 ;
}
static int F_94 ( struct V_190 * V_191 , void * V_192 )
{
unsigned short V_193 ;
unsigned short V_194 ;
unsigned short V_195 ;
int error ;
unsigned short V_196 = 0xff ;
unsigned short V_197 = 0xff ;
unsigned short V_198 = 0xff ;
int V_199 = - 1 ;
int V_200 = - 1 ;
char * V_201 = L_24 ;
if ( ( F_95 () == 1 ) &&
! ( error = F_40 ( & V_193 , & V_194 , & V_195 ) ) ) {
V_196 = ( V_193 >> 8 ) & 0xff ;
V_197 = V_193 & 0xff ;
if ( ( V_194 & 0xff ) != 0xff )
V_199 = V_194 & 0xff ;
if ( V_10 . V_37 > 0x100 ) {
V_198 = ( V_194 >> 8 ) & 0xff ;
if ( V_195 != 0xffff ) {
V_201 = ( V_195 & 0x8000 ) ? L_25 : L_26 ;
V_200 = V_195 & 0x7fff ;
}
}
}
F_96 ( V_191 , L_27 ,
V_202 ,
( V_10 . V_51 . V_203 >> 8 ) & 0xff ,
V_10 . V_51 . V_203 & 0xff ,
V_10 . V_51 . V_9 ,
V_196 ,
V_197 ,
V_198 ,
V_199 ,
V_200 ,
V_201 ) ;
return 0 ;
}
static int F_97 ( struct V_182 * V_182 , struct V_158 * V_158 )
{
return F_98 ( V_158 , F_94 , NULL ) ;
}
static int F_99 ( void * V_204 )
{
unsigned short V_193 ;
unsigned short V_194 ;
unsigned short V_195 ;
int error ;
char * V_205 ;
char * V_206 ;
F_36 ( V_64 , F_37 ( 0 ) ) ;
F_12 ( F_100 () != 0 ) ;
if ( V_10 . V_37 == 0 ) {
V_10 . V_37 = V_10 . V_51 . V_203 ;
if ( V_10 . V_37 > 0x100 ) {
if ( V_10 . V_37 > 0x0102 )
V_10 . V_37 = 0x0102 ;
error = F_23 ( & V_10 . V_37 ) ;
if ( error != V_33 ) {
F_1 ( L_28 , error ) ;
V_10 . V_37 = 0x100 ;
}
}
}
if ( V_138 )
F_2 ( V_207 L_29 ,
( V_10 . V_37 >> 8 ) & 0xff ,
V_10 . V_37 & 0xff ) ;
#ifdef F_101
if ( V_10 . V_51 . V_9 & V_80 ) {
error = F_39 ( 1 ) ;
if ( error ) {
F_1 ( L_30 , error ) ;
return - 1 ;
}
}
#endif
if ( ( V_10 . V_51 . V_9 & V_76 )
&& ( V_10 . V_37 > 0x0100 ) ) {
error = F_42 ( V_41 , 1 ) ;
if ( error ) {
F_1 ( L_31 , error ) ;
return - 1 ;
}
}
if ( V_138 && ( F_95 () == 1 || V_208 ) ) {
error = F_40 ( & V_193 , & V_194 , & V_195 ) ;
if ( error )
F_2 ( V_207 L_32 ) ;
else {
switch ( ( V_193 >> 8 ) & 0xff ) {
case 0 :
V_205 = L_33 ;
break;
case 1 :
V_205 = L_34 ;
break;
case 2 :
V_205 = L_35 ;
break;
default:
V_205 = L_36 ;
break;
}
switch ( V_193 & 0xff ) {
case 0 :
V_206 = L_37 ;
break;
case 1 :
V_206 = L_38 ;
break;
case 2 :
V_206 = L_39 ;
break;
case 3 :
V_206 = L_40 ;
break;
default:
V_206 = L_36 ;
break;
}
F_2 ( V_207
L_41 ,
V_205 , V_206 ) ;
if ( ( V_194 & 0xff ) == 0xff )
F_2 ( L_42 ) ;
else
F_2 ( L_43 , V_194 & 0xff ) ;
if ( V_10 . V_37 > 0x100 ) {
F_2 ( V_207
L_44 ,
( V_194 >> 8 ) & 0xff ) ;
if ( V_195 == 0xffff )
F_2 ( L_42 ) ;
else
F_2 ( L_45 , V_195 & 0x7fff ,
( V_195 & 0x8000 ) ?
L_46 : L_47 ) ;
}
}
}
if ( V_209 )
V_210 = F_35 ;
if ( F_95 () == 1 || V_208 ) {
#if F_102 ( V_211 ) && F_102 ( V_212 )
V_213 = F_43 ;
#endif
F_72 () ;
#if F_102 ( V_211 ) && F_102 ( V_212 )
V_213 = NULL ;
#endif
}
return 0 ;
}
static int T_14 F_103 ( char * V_1 )
{
int V_214 ;
while ( ( V_1 != NULL ) && ( * V_1 != '\0' ) ) {
if ( strncmp ( V_1 , L_48 , 3 ) == 0 )
V_215 = 1 ;
if ( strncmp ( V_1 , L_49 , 2 ) == 0 )
V_215 = 0 ;
if ( ( strncmp ( V_1 , L_50 , 16 ) == 0 ) ||
( strncmp ( V_1 , L_51 , 16 ) == 0 ) )
V_141 = F_104 ( V_1 + 16 , NULL , 0 ) ;
if ( ( strncmp ( V_1 , L_52 , 15 ) == 0 ) ||
( strncmp ( V_1 , L_53 , 15 ) == 0 ) )
V_68 = F_104 ( V_1 + 15 , NULL , 0 ) ;
if ( ( strncmp ( V_1 , L_54 , 12 ) == 0 ) ||
( strncmp ( V_1 , L_55 , 12 ) == 0 ) )
V_66 = F_104 ( V_1 + 12 , NULL , 0 ) ;
V_214 = ( strncmp ( V_1 , L_56 , 3 ) == 0 ) ||
( strncmp ( V_1 , L_57 , 3 ) == 0 ) ;
if ( V_214 )
V_1 += 3 ;
if ( strncmp ( V_1 , L_58 , 5 ) == 0 )
V_138 = ! V_214 ;
if ( ( strncmp ( V_1 , L_59 , 9 ) == 0 ) ||
( strncmp ( V_1 , L_60 , 9 ) == 0 ) )
V_209 = ! V_214 ;
if ( strncmp ( V_1 , L_61 , 3 ) == 0 ) {
V_208 = ! V_214 ;
V_68 = 100 ;
}
if ( ( strncmp ( V_1 , L_62 , 10 ) == 0 ) ||
( strncmp ( V_1 , L_63 , 10 ) == 0 ) )
V_10 . V_11 = ! V_214 ;
if ( ( strncmp ( V_1 , L_64 , 10 ) == 0 ) ||
( strncmp ( V_1 , L_65 , 10 ) == 0 ) )
V_10 . V_84 = ! V_214 ;
if ( ( strncmp ( V_1 , L_66 , 18 ) == 0 ) ||
( strncmp ( V_1 , L_67 , 18 ) == 0 ) )
V_10 . V_72 = ! V_214 ;
V_1 = strchr ( V_1 , ',' ) ;
if ( V_1 != NULL )
V_1 += strspn ( V_1 , L_68 ) ;
}
return 1 ;
}
static int T_14 F_105 ( const struct V_216 * V_217 )
{
F_2 ( L_69 , V_217 -> V_218 ) ;
return 0 ;
}
static int T_14 F_106 ( const struct V_216 * V_217 )
{
F_2 ( V_207 L_70
L_71 , V_217 -> V_218 ) ;
return 0 ;
}
static int T_14 F_107 ( const struct V_216 * V_217 )
{
if ( V_10 . V_72 == 0 ) {
V_10 . V_72 = 1 ;
F_2 ( V_207 L_72
L_73 , V_217 -> V_218 ) ;
}
return 0 ;
}
static int T_14 F_108 ( const struct V_216 * V_217 )
{
if ( V_10 . V_11 == 0 ) {
V_10 . V_11 = 1 ;
F_2 ( V_207 L_74
L_75 , V_217 -> V_218 ) ;
}
return 0 ;
}
static int T_14 F_109 ( const struct V_216 * V_217 )
{
if ( V_10 . V_219 == 0 ) {
V_10 . V_219 = 1 ;
F_2 ( V_207 L_74
L_76 , V_217 -> V_218 ) ;
}
return 0 ;
}
static int T_14 F_110 ( const struct V_216 * V_217 )
{
if ( V_10 . V_219 == 0 ) {
V_10 . V_219 = 1 ;
F_2 ( V_207 L_74
L_76 , V_217 -> V_218 ) ;
F_2 ( V_207 L_77 ) ;
F_2 ( V_207 L_78 ) ;
}
return 0 ;
}
static int T_14 F_111 ( const struct V_216 * V_217 )
{
if ( V_10 . V_69 == 0 ) {
V_10 . V_69 = 1 ;
F_2 ( V_207 L_74
L_79 , V_217 -> V_218 ) ;
}
return 0 ;
}
static int T_14 F_112 ( const struct V_216 * V_217 )
{
V_10 . V_84 = 1 ;
F_2 ( V_220 L_80
L_81 ) ;
return 0 ;
}
static int T_14 F_113 ( const struct V_216 * V_217 )
{
V_10 . V_86 = 1 ;
F_2 ( V_220 L_82
L_83 ) ;
return 0 ;
}
static int T_14 F_114 ( void )
{
struct V_14 * V_16 ;
int V_2 ;
F_115 ( V_221 ) ;
if ( V_10 . V_51 . V_203 == 0 || F_116 () || F_117 () ) {
F_2 ( V_207 L_84 ) ;
return - V_222 ;
}
F_2 ( V_207
L_85 ,
( ( V_10 . V_51 . V_203 >> 8 ) & 0xff ) ,
( V_10 . V_51 . V_203 & 0xff ) ,
V_10 . V_51 . V_9 ,
V_202 ) ;
if ( ( V_10 . V_51 . V_9 & V_223 ) == 0 ) {
F_2 ( V_207 L_86 ) ;
return - V_222 ;
}
if ( V_11 )
V_10 . V_11 = 1 ;
if ( V_224 )
V_10 . V_84 = 1 ;
if ( V_72 )
V_10 . V_72 = 1 ;
if ( V_215 != - 1 )
V_10 . V_219 = V_215 ;
if ( V_10 . V_51 . V_203 == 0x001 )
V_10 . V_51 . V_203 = 0x100 ;
if ( V_10 . V_51 . V_203 < 0x102 )
V_10 . V_51 . V_225 = 0 ;
if ( V_138 ) {
F_2 ( V_207 L_87 ,
V_10 . V_51 . V_226 , V_10 . V_51 . V_227 ,
V_10 . V_51 . V_228 , V_10 . V_51 . V_229 ) ;
if ( V_10 . V_51 . V_203 > 0x100 )
F_2 ( L_88 ,
V_10 . V_51 . V_230 ,
V_10 . V_51 . V_231 ) ;
if ( V_10 . V_51 . V_203 > 0x101 )
F_2 ( L_89 , V_10 . V_51 . V_225 ) ;
F_2 ( L_90 ) ;
}
if ( V_10 . V_219 ) {
F_2 ( V_7 L_91 ) ;
return - V_222 ;
}
if ( ( F_95 () > 1 ) && ! V_209 && ! V_208 ) {
F_2 ( V_7 L_92 ) ;
V_10 . V_219 = 1 ;
return - V_222 ;
}
if ( ! V_232 ) {
F_2 ( V_7 L_93 ) ;
V_10 . V_219 = 1 ;
return - V_222 ;
}
V_233 . V_227 = V_10 . V_51 . V_227 ;
V_233 . V_234 = V_235 ;
V_16 = F_13 ( 0 ) ;
F_118 ( & V_16 [ V_235 >> 3 ] ,
( unsigned long ) F_119 ( ( unsigned long ) V_10 . V_51 . V_226 << 4 ) ) ;
F_118 ( & V_16 [ V_236 >> 3 ] ,
( unsigned long ) F_119 ( ( unsigned long ) V_10 . V_51 . V_228 << 4 ) ) ;
F_118 ( & V_16 [ V_237 >> 3 ] ,
( unsigned long ) F_119 ( ( unsigned long ) V_10 . V_51 . V_229 << 4 ) ) ;
F_120 ( L_94 , 0 , NULL , & V_238 ) ;
V_239 = F_121 ( F_99 , NULL , L_95 ) ;
if ( F_122 ( V_239 ) ) {
F_2 ( V_111 L_96
L_97 ) ;
V_2 = F_123 ( V_239 ) ;
V_239 = NULL ;
F_124 ( L_94 , NULL ) ;
return V_2 ;
}
F_125 ( V_239 ) ;
if ( F_95 () > 1 && ! V_208 ) {
F_2 ( V_7
L_98 ) ;
return 0 ;
}
if ( F_126 ( & V_240 ) )
F_2 ( V_220 L_99 ) ;
if ( V_241 != 100 )
V_66 = ( V_66 * V_241 ) / 100 ;
if ( V_68 < 100 ) {
V_71 = V_242 ;
V_242 = F_32 ;
V_243 = 1 ;
}
return 0 ;
}
static void T_15 F_127 ( void )
{
int error ;
if ( V_243 ) {
V_242 = V_71 ;
F_128 () ;
}
if ( ( ( V_10 . V_51 . V_9 & V_76 ) == 0 )
&& ( V_10 . V_37 > 0x0100 ) ) {
error = F_42 ( V_41 , 0 ) ;
if ( error )
F_1 ( L_100 , error ) ;
}
F_129 ( & V_240 ) ;
F_124 ( L_94 , NULL ) ;
if ( V_209 )
V_210 = NULL ;
if ( V_239 ) {
F_130 ( V_239 ) ;
V_239 = NULL ;
}
}
