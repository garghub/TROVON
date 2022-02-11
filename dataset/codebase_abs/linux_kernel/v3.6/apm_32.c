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
static void F_33 ( void )
{
static int V_55 ;
static unsigned int V_56 ;
static unsigned int V_57 ;
int V_58 = 0 ;
unsigned int V_59 = V_48 - V_56 ;
unsigned int V_60 ;
F_34 ( 1 , L_5 ) ;
V_61:
if ( V_59 > V_62 ) {
V_55 = 0 ;
V_56 = V_48 ;
V_57 = V_63 -> V_64 ;
} else if ( V_59 > V_65 ) {
unsigned int V_66 ;
V_66 = V_63 -> V_64 - V_57 ;
V_66 *= 100 ;
V_66 /= V_59 ;
V_55 = ( V_66 > V_67 ) ;
if ( V_9 . V_68 )
V_55 = 0 ;
V_56 = V_48 ;
V_57 = V_63 -> V_64 ;
}
V_60 = V_69 ;
while ( ! F_30 () ) {
if ( V_55 ) {
unsigned int V_46 ;
V_46 = V_48 ;
switch ( F_27 () ) {
case 0 :
V_58 = 1 ;
if ( V_46 != V_48 ) {
if ( V_60 ) {
V_60 = V_69 ;
continue;
}
} else if ( V_60 ) {
V_60 -- ;
continue;
}
break;
case 1 :
V_58 = 1 ;
break;
default:
break;
}
}
if ( V_70 )
V_70 () ;
else
F_35 () ;
F_7 () ;
V_59 = V_48 - V_56 ;
if ( V_59 > V_65 )
goto V_61;
}
if ( V_58 )
F_32 () ;
F_6 () ;
}
static void F_36 ( void )
{
if ( V_9 . V_71 ) {
F_37 ( V_63 , F_38 ( 0 ) ) ;
F_39 ( V_72 ) ;
} else {
( void ) F_26 ( V_73 ) ;
}
}
static int F_40 ( int V_74 )
{
T_3 V_23 ;
int V_2 ;
if ( ( V_74 == 0 ) && ( V_9 . V_50 . V_8 & V_75 ) )
return V_76 ;
if ( F_22 ( V_77 , V_78 ,
V_74 , & V_23 , & V_2 ) )
return V_2 ;
if ( V_74 )
V_9 . V_50 . V_8 &= ~ V_79 ;
else
V_9 . V_50 . V_8 |= V_79 ;
return V_32 ;
}
static int F_41 ( T_4 * V_43 , T_4 * V_80 , T_4 * V_81 )
{
struct V_16 V_17 ;
V_17 . V_20 = V_82 ;
V_17 . V_21 = V_40 ;
V_17 . V_22 = 0 ;
if ( V_9 . V_83 )
return V_84 ;
if ( V_16 ( & V_17 ) )
return V_17 . V_2 ;
* V_43 = V_17 . V_21 ;
* V_80 = V_17 . V_22 ;
if ( V_9 . V_85 ) {
* V_81 = F_42 ( ( V_86 ) V_17 . V_24 ) ;
* V_81 |= 0x8000 ;
} else
* V_81 = V_17 . V_24 ;
return V_32 ;
}
static int F_43 ( T_4 V_87 , int V_74 )
{
T_3 V_23 ;
int V_2 ;
if ( ( V_74 == 0 ) && ( V_87 == V_40 )
&& ( V_9 . V_50 . V_8 & V_79 ) )
return V_88 ;
if ( F_22 ( V_89 , V_87 , V_74 ,
& V_23 , & V_2 ) )
return V_2 ;
if ( V_87 == V_40 ) {
if ( V_74 )
V_9 . V_50 . V_8 &= ~ V_75 ;
else
V_9 . V_50 . V_8 |= V_75 ;
}
return V_32 ;
}
static int F_44 ( int V_90 )
{
int error = V_76 ;
int V_3 ;
T_4 V_38 ;
static const T_4 V_91 [ 3 ] = { 0x100 , 0x1FF , 0x101 } ;
V_38 = V_90 ? V_92 : V_93 ;
for ( V_3 = 0 ; V_3 < F_45 ( V_91 ) ; V_3 ++ ) {
error = F_25 ( V_91 [ V_3 ] , V_38 ) ;
if ( ( error == V_32 ) || ( error == V_94 ) )
return 1 ;
if ( error == V_76 )
break;
}
if ( error == V_76 ) {
static int V_95 ;
int V_96 ;
if ( V_95 ++ == 0 ) {
V_96 = F_43 ( V_40 , 1 ) ;
if ( V_96 ) {
F_1 ( L_6 , error ) ;
F_1 ( L_7 , V_96 ) ;
return 0 ;
} else
return F_44 ( V_90 ) ;
}
}
F_1 ( L_6 , error ) ;
return 0 ;
}
static int F_46 ( struct V_97 * V_98 )
{
return V_98 -> V_99 == V_98 -> V_100 ;
}
static T_5 F_47 ( struct V_97 * V_98 )
{
if ( ++ V_98 -> V_100 >= V_101 )
V_98 -> V_100 = 0 ;
return V_98 -> V_102 [ V_98 -> V_100 ] ;
}
static void F_48 ( T_5 V_33 , struct V_97 * V_103 )
{
struct V_97 * V_98 ;
F_49 ( & V_104 ) ;
if ( V_105 == NULL )
goto V_106;
for ( V_98 = V_105 ; V_98 != NULL ; V_98 = V_98 -> V_107 ) {
if ( ( V_98 == V_103 ) || ( ! V_98 -> V_108 ) )
continue;
if ( ++ V_98 -> V_99 >= V_101 )
V_98 -> V_99 = 0 ;
if ( V_98 -> V_99 == V_98 -> V_100 ) {
static int V_109 ;
if ( V_109 ++ == 0 )
F_50 ( L_8 ) ;
if ( ++ V_98 -> V_100 >= V_101 )
V_98 -> V_100 = 0 ;
}
V_98 -> V_102 [ V_98 -> V_99 ] = V_33 ;
if ( ! V_98 -> V_110 || ! V_98 -> V_111 )
continue;
switch ( V_33 ) {
case V_112 :
case V_113 :
V_98 -> V_114 ++ ;
V_114 ++ ;
break;
case V_115 :
case V_116 :
V_98 -> V_117 ++ ;
V_117 ++ ;
break;
}
}
F_51 ( & V_118 ) ;
V_106:
F_52 ( & V_104 ) ;
}
static void F_53 ( void )
{
#ifdef F_54
unsigned long V_8 ;
F_55 ( & V_119 , V_8 ) ;
F_56 ( 0x34 , V_120 ) ;
F_57 ( 10 ) ;
F_56 ( V_121 & 0xff , V_122 ) ;
F_57 ( 10 ) ;
F_56 ( V_121 >> 8 , V_122 ) ;
F_57 ( 10 ) ;
F_58 ( & V_119 , V_8 ) ;
#endif
}
static int F_59 ( int V_123 )
{
int V_2 ;
struct V_97 * V_98 ;
F_60 ( V_124 ) ;
F_61 ( V_124 ) ;
F_7 () ;
F_62 () ;
F_6 () ;
F_63 () ;
V_2 = F_26 ( V_125 ) ;
V_126 = 1 ;
F_64 () ;
F_7 () ;
F_53 () ;
if ( V_2 == V_94 )
V_2 = V_32 ;
if ( V_2 != V_32 )
F_1 ( L_9 , V_2 ) ;
V_2 = ( V_2 == V_32 ) ? 0 : - V_127 ;
F_65 () ;
F_6 () ;
F_66 ( V_128 ) ;
F_67 ( V_128 ) ;
F_48 ( V_129 , NULL ) ;
F_49 ( & V_104 ) ;
for ( V_98 = V_105 ; V_98 != NULL ; V_98 = V_98 -> V_107 ) {
V_98 -> V_130 = 0 ;
V_98 -> V_131 = V_2 ;
}
F_52 ( & V_104 ) ;
F_51 ( & V_132 ) ;
return V_2 ;
}
static void F_68 ( void )
{
int V_2 ;
F_61 ( V_124 ) ;
F_7 () ;
F_62 () ;
F_6 () ;
V_2 = F_26 ( V_92 ) ;
if ( ( V_2 != V_32 ) && ( V_2 != V_94 ) )
F_1 ( L_10 , V_2 ) ;
F_7 () ;
F_65 () ;
F_6 () ;
F_66 ( V_128 ) ;
}
static T_5 F_69 ( void )
{
int error ;
T_5 V_33 = V_133 ;
T_6 V_34 ;
static int V_109 ;
error = F_24 ( & V_33 , & V_34 ) ;
if ( error == V_32 )
return V_33 ;
if ( ( error != V_133 ) && ( V_109 ++ == 0 ) )
F_1 ( L_11 , error ) ;
return 0 ;
}
static void F_70 ( void )
{
T_5 V_33 ;
static unsigned long V_134 ;
static int V_135 ;
while ( ( V_33 = F_69 () ) != 0 ) {
if ( V_136 ) {
if ( V_33 <= V_137 )
F_31 ( V_47 L_12 ,
V_138 [ V_33 - 1 ] ) ;
else
F_31 ( V_47 L_13
L_14 , V_33 ) ;
}
if ( V_135
&& ( F_71 ( V_48 , V_134 + V_139 ) ) )
V_135 = 0 ;
switch ( V_33 ) {
case V_115 :
case V_116 :
F_48 ( V_33 , NULL ) ;
if ( V_117 <= 0 )
F_68 () ;
break;
case V_113 :
#ifdef F_72
if ( V_9 . V_36 > 0x100 )
F_26 ( V_140 ) ;
break;
#endif
case V_112 :
if ( V_135 ) {
if ( V_9 . V_36 > 0x100 )
F_26 ( V_140 ) ;
break;
}
if ( V_141 )
return;
V_141 = 1 ;
F_48 ( V_33 , NULL ) ;
if ( V_114 <= 0 )
( void ) F_59 ( 1 ) ;
break;
case V_129 :
case V_142 :
case V_143 :
V_141 = 0 ;
V_134 = V_48 ;
V_135 = 1 ;
if ( ( V_33 != V_129 )
|| ( V_126 == 0 ) ) {
F_67 ( V_128 ) ;
F_48 ( V_33 , NULL ) ;
}
V_126 = 0 ;
break;
case V_144 :
case V_145 :
case V_146 :
F_48 ( V_33 , NULL ) ;
break;
case V_147 :
break;
case V_148 :
( void ) F_59 ( 0 ) ;
break;
}
}
}
static void F_73 ( void )
{
static int V_149 = 4 ;
int V_2 ;
if ( ( V_117 > 0 ) || ( V_114 > 0 ) ) {
if ( ( V_9 . V_36 > 0x100 ) &&
( V_149 -- <= 0 ) ) {
V_149 = 4 ;
if ( V_136 )
F_31 ( V_47 L_15 ) ;
V_2 = F_26 ( V_150 ) ;
if ( V_2 )
F_1 ( L_16 , V_2 ) ;
}
} else
V_149 = 4 ;
F_70 () ;
}
static void F_74 ( void )
{
F_75 ( V_151 , V_63 ) ;
F_76 ( & V_118 , & V_151 ) ;
F_77 ( V_152 ) ;
for (; ; ) {
F_78 ( V_153 ) ;
if ( F_79 () )
break;
F_77 ( V_152 ) ;
F_73 () ;
}
F_80 ( & V_118 , & V_151 ) ;
}
static int F_81 ( struct V_97 * V_98 , const char * V_20 )
{
if ( V_98 == NULL || V_98 -> V_154 != V_155 ) {
F_50 ( L_17 , V_20 ) ;
return 1 ;
}
return 0 ;
}
static T_7 F_82 ( struct V_156 * V_157 , char T_8 * V_158 , T_9 V_159 , T_10 * V_160 )
{
struct V_97 * V_98 ;
int V_3 ;
T_5 V_33 ;
V_98 = V_157 -> V_161 ;
if ( F_81 ( V_98 , L_18 ) )
return - V_127 ;
if ( ( int ) V_159 < sizeof( T_5 ) )
return - V_162 ;
if ( ( F_46 ( V_98 ) ) && ( V_157 -> V_163 & V_164 ) )
return - V_165 ;
F_83 ( V_118 , ! F_46 ( V_98 ) ) ;
V_3 = V_159 ;
while ( ( V_3 >= sizeof( V_33 ) ) && ! F_46 ( V_98 ) ) {
V_33 = F_47 ( V_98 ) ;
if ( F_84 ( V_158 , & V_33 , sizeof( V_33 ) ) ) {
if ( V_3 < V_159 )
break;
return - V_166 ;
}
switch ( V_33 ) {
case V_112 :
case V_113 :
V_98 -> V_167 ++ ;
break;
case V_115 :
case V_116 :
V_98 -> V_168 ++ ;
break;
}
V_158 += sizeof( V_33 ) ;
V_3 -= sizeof( V_33 ) ;
}
if ( V_3 < V_159 )
return V_159 - V_3 ;
if ( F_85 ( V_63 ) )
return - V_169 ;
return 0 ;
}
static unsigned int F_86 ( struct V_156 * V_157 , T_11 * V_151 )
{
struct V_97 * V_98 ;
V_98 = V_157 -> V_161 ;
if ( F_81 ( V_98 , L_19 ) )
return 0 ;
F_87 ( V_157 , & V_118 , V_151 ) ;
if ( ! F_46 ( V_98 ) )
return V_170 | V_171 ;
return 0 ;
}
static long F_88 ( struct V_156 * V_172 , T_12 V_173 , T_13 V_174 )
{
struct V_97 * V_98 ;
int V_27 ;
V_98 = V_172 -> V_161 ;
if ( F_81 ( V_98 , L_20 ) )
return - V_127 ;
if ( ! V_98 -> V_110 || ! V_98 -> V_111 )
return - V_175 ;
switch ( V_173 ) {
case V_176 :
F_89 ( & V_177 ) ;
if ( V_98 -> V_168 > 0 ) {
V_98 -> V_168 -- ;
V_98 -> V_117 -- ;
V_117 -- ;
} else
F_48 ( V_116 , V_98 ) ;
if ( V_117 <= 0 )
F_68 () ;
F_90 ( & V_177 ) ;
break;
case V_178 :
F_89 ( & V_177 ) ;
if ( V_98 -> V_167 > 0 ) {
V_98 -> V_167 -- ;
V_98 -> V_114 -- ;
V_114 -- ;
} else
F_48 ( V_113 , V_98 ) ;
if ( V_114 <= 0 ) {
V_27 = F_59 ( 1 ) ;
F_90 ( & V_177 ) ;
} else {
V_98 -> V_130 = 1 ;
F_90 ( & V_177 ) ;
F_83 ( V_132 ,
V_98 -> V_130 == 0 ) ;
V_27 = V_98 -> V_131 ;
}
return V_27 ;
default:
return - V_179 ;
}
return 0 ;
}
static int F_91 ( struct V_180 * V_180 , struct V_156 * V_172 )
{
struct V_97 * V_98 ;
V_98 = V_172 -> V_161 ;
if ( F_81 ( V_98 , L_21 ) )
return 0 ;
V_172 -> V_161 = NULL ;
if ( V_98 -> V_117 > 0 ) {
V_117 -= V_98 -> V_117 ;
if ( V_117 <= 0 )
F_68 () ;
}
if ( V_98 -> V_114 > 0 ) {
V_114 -= V_98 -> V_114 ;
if ( V_114 <= 0 )
( void ) F_59 ( 1 ) ;
}
F_49 ( & V_104 ) ;
if ( V_105 == V_98 )
V_105 = V_98 -> V_107 ;
else {
struct V_97 * V_181 ;
for ( V_181 = V_105 ;
( V_181 != NULL ) && ( V_181 -> V_107 != V_98 ) ;
V_181 = V_181 -> V_107 )
;
if ( V_181 == NULL )
F_50 ( L_22 ) ;
else
V_181 -> V_107 = V_98 -> V_107 ;
}
F_52 ( & V_104 ) ;
F_92 ( V_98 ) ;
return 0 ;
}
static int F_93 ( struct V_180 * V_180 , struct V_156 * V_172 )
{
struct V_97 * V_98 ;
V_98 = F_94 ( sizeof( * V_98 ) , V_182 ) ;
if ( V_98 == NULL )
return - V_183 ;
V_98 -> V_154 = V_155 ;
V_98 -> V_100 = V_98 -> V_99 = 0 ;
V_98 -> V_114 = V_98 -> V_117 = 0 ;
V_98 -> V_167 = V_98 -> V_168 = 0 ;
V_98 -> V_110 = F_95 ( V_184 ) ;
V_98 -> V_111 = ( V_172 -> V_185 & V_186 ) == V_186 ;
V_98 -> V_108 = ( V_172 -> V_185 & V_187 ) == V_187 ;
F_49 ( & V_104 ) ;
V_98 -> V_107 = V_105 ;
V_105 = V_98 ;
F_52 ( & V_104 ) ;
V_172 -> V_161 = V_98 ;
return 0 ;
}
static int F_96 ( struct V_188 * V_189 , void * V_190 )
{
unsigned short V_191 ;
unsigned short V_192 ;
unsigned short V_193 ;
int error ;
unsigned short V_194 = 0xff ;
unsigned short V_195 = 0xff ;
unsigned short V_196 = 0xff ;
int V_197 = - 1 ;
int V_198 = - 1 ;
char * V_199 = L_23 ;
if ( ( F_97 () == 1 ) &&
! ( error = F_41 ( & V_191 , & V_192 , & V_193 ) ) ) {
V_194 = ( V_191 >> 8 ) & 0xff ;
V_195 = V_191 & 0xff ;
if ( ( V_192 & 0xff ) != 0xff )
V_197 = V_192 & 0xff ;
if ( V_9 . V_36 > 0x100 ) {
V_196 = ( V_192 >> 8 ) & 0xff ;
if ( V_193 != 0xffff ) {
V_199 = ( V_193 & 0x8000 ) ? L_24 : L_25 ;
V_198 = V_193 & 0x7fff ;
}
}
}
F_98 ( V_189 , L_26 ,
V_200 ,
( V_9 . V_50 . V_201 >> 8 ) & 0xff ,
V_9 . V_50 . V_201 & 0xff ,
V_9 . V_50 . V_8 ,
V_194 ,
V_195 ,
V_196 ,
V_197 ,
V_198 ,
V_199 ) ;
return 0 ;
}
static int F_99 ( struct V_180 * V_180 , struct V_156 * V_156 )
{
return F_100 ( V_156 , F_96 , NULL ) ;
}
static int F_101 ( void * V_202 )
{
unsigned short V_191 ;
unsigned short V_192 ;
unsigned short V_193 ;
int error ;
char * V_203 ;
char * V_204 ;
F_37 ( V_63 , F_38 ( 0 ) ) ;
F_12 ( F_102 () != 0 ) ;
if ( V_9 . V_36 == 0 ) {
V_9 . V_36 = V_9 . V_50 . V_201 ;
if ( V_9 . V_36 > 0x100 ) {
if ( V_9 . V_36 > 0x0102 )
V_9 . V_36 = 0x0102 ;
error = F_23 ( & V_9 . V_36 ) ;
if ( error != V_32 ) {
F_1 ( L_27 , error ) ;
V_9 . V_36 = 0x100 ;
}
}
}
if ( V_136 )
F_31 ( V_205 L_28 ,
( V_9 . V_36 >> 8 ) & 0xff ,
V_9 . V_36 & 0xff ) ;
#ifdef F_103
if ( V_9 . V_50 . V_8 & V_79 ) {
error = F_40 ( 1 ) ;
if ( error ) {
F_1 ( L_29 , error ) ;
return - 1 ;
}
}
#endif
if ( ( V_9 . V_50 . V_8 & V_75 )
&& ( V_9 . V_36 > 0x0100 ) ) {
error = F_43 ( V_40 , 1 ) ;
if ( error ) {
F_1 ( L_30 , error ) ;
return - 1 ;
}
}
if ( V_136 && ( F_97 () == 1 || V_206 ) ) {
error = F_41 ( & V_191 , & V_192 , & V_193 ) ;
if ( error )
F_31 ( V_205 L_31 ) ;
else {
switch ( ( V_191 >> 8 ) & 0xff ) {
case 0 :
V_203 = L_32 ;
break;
case 1 :
V_203 = L_33 ;
break;
case 2 :
V_203 = L_34 ;
break;
default:
V_203 = L_35 ;
break;
}
switch ( V_191 & 0xff ) {
case 0 :
V_204 = L_36 ;
break;
case 1 :
V_204 = L_37 ;
break;
case 2 :
V_204 = L_38 ;
break;
case 3 :
V_204 = L_39 ;
break;
default:
V_204 = L_35 ;
break;
}
F_31 ( V_205
L_40 ,
V_203 , V_204 ) ;
if ( ( V_192 & 0xff ) == 0xff )
F_31 ( L_41 ) ;
else
F_31 ( L_42 , V_192 & 0xff ) ;
if ( V_9 . V_36 > 0x100 ) {
F_31 ( V_205
L_43 ,
( V_192 >> 8 ) & 0xff ) ;
if ( V_193 == 0xffff )
F_31 ( L_41 ) ;
else
F_31 ( L_44 , V_193 & 0x7fff ,
( V_193 & 0x8000 ) ?
L_45 : L_46 ) ;
}
}
}
if ( V_207 )
V_208 = F_36 ;
if ( F_97 () == 1 || V_206 ) {
#if F_104 ( V_209 ) && F_104 ( V_210 )
V_211 = F_44 ;
#endif
F_74 () ;
#if F_104 ( V_209 ) && F_104 ( V_210 )
V_211 = NULL ;
#endif
}
return 0 ;
}
static int T_14 F_105 ( char * V_1 )
{
int V_212 ;
while ( ( V_1 != NULL ) && ( * V_1 != '\0' ) ) {
if ( strncmp ( V_1 , L_47 , 3 ) == 0 )
V_213 = 1 ;
if ( strncmp ( V_1 , L_48 , 2 ) == 0 )
V_213 = 0 ;
if ( ( strncmp ( V_1 , L_49 , 16 ) == 0 ) ||
( strncmp ( V_1 , L_50 , 16 ) == 0 ) )
V_139 = F_106 ( V_1 + 16 , NULL , 0 ) ;
if ( ( strncmp ( V_1 , L_51 , 15 ) == 0 ) ||
( strncmp ( V_1 , L_52 , 15 ) == 0 ) )
V_67 = F_106 ( V_1 + 15 , NULL , 0 ) ;
if ( ( strncmp ( V_1 , L_53 , 12 ) == 0 ) ||
( strncmp ( V_1 , L_54 , 12 ) == 0 ) )
V_65 = F_106 ( V_1 + 12 , NULL , 0 ) ;
V_212 = ( strncmp ( V_1 , L_55 , 3 ) == 0 ) ||
( strncmp ( V_1 , L_56 , 3 ) == 0 ) ;
if ( V_212 )
V_1 += 3 ;
if ( strncmp ( V_1 , L_57 , 5 ) == 0 )
V_136 = ! V_212 ;
if ( ( strncmp ( V_1 , L_58 , 9 ) == 0 ) ||
( strncmp ( V_1 , L_59 , 9 ) == 0 ) )
V_207 = ! V_212 ;
if ( strncmp ( V_1 , L_60 , 3 ) == 0 ) {
V_206 = ! V_212 ;
V_67 = 100 ;
}
if ( ( strncmp ( V_1 , L_61 , 10 ) == 0 ) ||
( strncmp ( V_1 , L_62 , 10 ) == 0 ) )
V_9 . V_10 = ! V_212 ;
if ( ( strncmp ( V_1 , L_63 , 10 ) == 0 ) ||
( strncmp ( V_1 , L_64 , 10 ) == 0 ) )
V_9 . V_83 = ! V_212 ;
if ( ( strncmp ( V_1 , L_65 , 18 ) == 0 ) ||
( strncmp ( V_1 , L_66 , 18 ) == 0 ) )
V_9 . V_71 = ! V_212 ;
V_1 = strchr ( V_1 , ',' ) ;
if ( V_1 != NULL )
V_1 += strspn ( V_1 , L_67 ) ;
}
return 1 ;
}
static int T_14 F_107 ( const struct V_214 * V_215 )
{
F_31 ( L_68 , V_215 -> V_216 ) ;
return 0 ;
}
static int T_14 F_108 ( const struct V_214 * V_215 )
{
F_31 ( V_205 L_69
L_70 , V_215 -> V_216 ) ;
return 0 ;
}
static int T_14 F_109 ( const struct V_214 * V_215 )
{
if ( V_9 . V_71 == 0 ) {
V_9 . V_71 = 1 ;
F_31 ( V_205 L_71
L_72 , V_215 -> V_216 ) ;
}
return 0 ;
}
static int T_14 F_110 ( const struct V_214 * V_215 )
{
if ( V_9 . V_10 == 0 ) {
V_9 . V_10 = 1 ;
F_31 ( V_205 L_73
L_74 , V_215 -> V_216 ) ;
}
return 0 ;
}
static int T_14 F_111 ( const struct V_214 * V_215 )
{
if ( V_9 . V_217 == 0 ) {
V_9 . V_217 = 1 ;
F_31 ( V_205 L_73
L_75 , V_215 -> V_216 ) ;
}
return 0 ;
}
static int T_14 F_112 ( const struct V_214 * V_215 )
{
if ( V_9 . V_217 == 0 ) {
V_9 . V_217 = 1 ;
F_31 ( V_205 L_73
L_75 , V_215 -> V_216 ) ;
F_31 ( V_205 L_76 ) ;
F_31 ( V_205 L_77 ) ;
}
return 0 ;
}
static int T_14 F_113 ( const struct V_214 * V_215 )
{
if ( V_9 . V_68 == 0 ) {
V_9 . V_68 = 1 ;
F_31 ( V_205 L_73
L_78 , V_215 -> V_216 ) ;
}
return 0 ;
}
static int T_14 F_114 ( const struct V_214 * V_215 )
{
V_9 . V_83 = 1 ;
F_31 ( V_218 L_79
L_80 ) ;
return 0 ;
}
static int T_14 F_115 ( const struct V_214 * V_215 )
{
V_9 . V_85 = 1 ;
F_31 ( V_218 L_81
L_82 ) ;
return 0 ;
}
static int T_14 F_116 ( void )
{
struct V_13 * V_15 ;
int V_2 ;
F_117 ( V_219 ) ;
if ( V_9 . V_50 . V_201 == 0 || F_118 () || F_119 () ) {
F_31 ( V_205 L_83 ) ;
return - V_220 ;
}
F_31 ( V_205
L_84 ,
( ( V_9 . V_50 . V_201 >> 8 ) & 0xff ) ,
( V_9 . V_50 . V_201 & 0xff ) ,
V_9 . V_50 . V_8 ,
V_200 ) ;
if ( ( V_9 . V_50 . V_8 & V_221 ) == 0 ) {
F_31 ( V_205 L_85 ) ;
return - V_220 ;
}
if ( V_10 )
V_9 . V_10 = 1 ;
if ( V_222 )
V_9 . V_83 = 1 ;
if ( V_71 )
V_9 . V_71 = 1 ;
if ( V_213 != - 1 )
V_9 . V_217 = V_213 ;
if ( V_9 . V_50 . V_201 == 0x001 )
V_9 . V_50 . V_201 = 0x100 ;
if ( V_9 . V_50 . V_201 < 0x102 )
V_9 . V_50 . V_223 = 0 ;
if ( V_136 ) {
F_31 ( V_205 L_86 ,
V_9 . V_50 . V_224 , V_9 . V_50 . V_225 ,
V_9 . V_50 . V_226 , V_9 . V_50 . V_227 ) ;
if ( V_9 . V_50 . V_201 > 0x100 )
F_31 ( L_87 ,
V_9 . V_50 . V_228 ,
V_9 . V_50 . V_229 ) ;
if ( V_9 . V_50 . V_201 > 0x101 )
F_31 ( L_88 , V_9 . V_50 . V_223 ) ;
F_31 ( L_89 ) ;
}
if ( V_9 . V_217 ) {
F_2 ( L_90 ) ;
return - V_220 ;
}
if ( ( F_97 () > 1 ) && ! V_207 && ! V_206 ) {
F_2 ( L_91 ) ;
V_9 . V_217 = 1 ;
return - V_220 ;
}
if ( ! V_230 ) {
F_2 ( L_92 ) ;
V_9 . V_217 = 1 ;
return - V_220 ;
}
V_231 . V_225 = V_9 . V_50 . V_225 ;
V_231 . V_232 = V_233 ;
V_15 = F_13 ( 0 ) ;
F_120 ( & V_15 [ V_233 >> 3 ] ,
( unsigned long ) F_121 ( ( unsigned long ) V_9 . V_50 . V_224 << 4 ) ) ;
F_120 ( & V_15 [ V_234 >> 3 ] ,
( unsigned long ) F_121 ( ( unsigned long ) V_9 . V_50 . V_226 << 4 ) ) ;
F_120 ( & V_15 [ V_235 >> 3 ] ,
( unsigned long ) F_121 ( ( unsigned long ) V_9 . V_50 . V_227 << 4 ) ) ;
F_122 ( L_93 , 0 , NULL , & V_236 ) ;
V_237 = F_123 ( F_101 , NULL , L_94 ) ;
if ( F_124 ( V_237 ) ) {
F_50 ( L_95 ) ;
V_2 = F_125 ( V_237 ) ;
V_237 = NULL ;
F_126 ( L_93 , NULL ) ;
return V_2 ;
}
F_127 ( V_237 ) ;
if ( F_97 () > 1 && ! V_206 ) {
F_31 ( V_238
L_96 ) ;
return 0 ;
}
if ( F_128 ( & V_239 ) )
F_31 ( V_218 L_97 ) ;
if ( V_240 != 100 )
V_65 = ( V_65 * V_240 ) / 100 ;
if ( V_67 < 100 ) {
V_70 = V_241 ;
V_241 = F_33 ;
V_242 = 1 ;
}
return 0 ;
}
static void T_15 F_129 ( void )
{
int error ;
if ( V_242 ) {
V_241 = V_70 ;
F_130 () ;
}
if ( ( ( V_9 . V_50 . V_8 & V_75 ) == 0 )
&& ( V_9 . V_36 > 0x0100 ) ) {
error = F_43 ( V_40 , 0 ) ;
if ( error )
F_1 ( L_98 , error ) ;
}
F_131 ( & V_239 ) ;
F_126 ( L_93 , NULL ) ;
if ( V_207 )
V_208 = NULL ;
if ( V_237 ) {
F_132 ( V_237 ) ;
V_237 = NULL ;
}
}
