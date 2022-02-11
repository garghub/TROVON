static int T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
return 0 ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 , struct V_4 * V_4 )
{
if ( memcmp ( V_3 -> V_5 , V_6 , V_7 ) != 0 )
return 0 ;
if ( V_3 -> V_8 != V_9 && V_3 -> V_8 != V_10 )
return 0 ;
if ( ! F_6 ( V_3 ) || ! F_7 ( V_3 ) )
return 0 ;
if ( ! V_4 -> V_11 || ! V_4 -> V_11 -> V_12 )
return 0 ;
return 1 ;
}
static int F_8 ( struct V_13 * V_14 ,
struct V_4 * V_4 )
{
struct V_15 * V_16 ;
unsigned long V_17 ;
int V_18 , V_19 ;
if ( V_14 -> V_3 . V_20 != sizeof( struct V_21 ) )
return - V_22 ;
if ( V_14 -> V_3 . V_23 > 65536U / sizeof( struct V_21 ) )
return - V_22 ;
V_17 = V_14 -> V_3 . V_23 * sizeof( struct V_21 ) ;
V_14 -> V_24 = F_9 ( V_17 , V_25 ) ;
if ( ! V_14 -> V_24 )
return - V_22 ;
V_18 = F_10 ( V_4 , V_14 -> V_3 . V_26 ,
( char * ) V_14 -> V_24 , V_17 ) ;
if ( F_11 ( V_18 != V_17 ) )
return V_18 < 0 ? V_18 : - V_27 ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_16 -> V_28 != V_29 )
continue;
if ( V_16 -> V_30 & V_31 )
V_14 -> V_32 |= V_33 ;
else
V_14 -> V_32 |= V_34 ;
V_14 -> V_35 = V_16 -> V_36 ;
break;
}
return 0 ;
}
static int F_12 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_13 V_41 , V_42 ;
struct V_21 * V_16 ;
unsigned long V_35 , V_43 ;
#ifdef F_13
unsigned long V_44 ;
#endif
#ifndef F_14
unsigned long V_45 ;
#endif
struct V_4 * V_46 = NULL ;
char * V_47 = NULL ;
int V_48 ;
int V_18 , V_49 ;
F_15 ( L_1 , V_50 -> V_51 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_41 . V_3 = * (struct V_2 * ) V_38 -> V_52 ;
V_41 . V_32 = V_53 | V_54 ;
V_18 = - V_27 ;
if ( ! F_5 ( & V_41 . V_3 , V_38 -> V_4 ) )
goto error;
V_18 = F_8 ( & V_41 , V_38 -> V_4 ) ;
if ( V_18 < 0 )
goto error;
V_16 = V_41 . V_24 ;
for ( V_49 = 0 ; V_49 < V_41 . V_3 . V_23 ; V_49 ++ , V_16 ++ ) {
switch ( V_16 -> V_28 ) {
case V_55 :
V_18 = - V_22 ;
if ( V_16 -> V_56 > V_57 )
goto error;
V_18 = - V_58 ;
if ( V_16 -> V_56 < 2 )
goto error;
V_47 = F_9 ( V_16 -> V_56 , V_25 ) ;
if ( ! V_47 )
goto error;
V_18 = F_10 ( V_38 -> V_4 ,
V_16 -> V_59 ,
V_47 ,
V_16 -> V_56 ) ;
if ( F_11 ( V_18 != V_16 -> V_56 ) ) {
if ( V_18 >= 0 )
V_18 = - V_27 ;
goto error;
}
V_18 = - V_58 ;
if ( V_47 [ V_16 -> V_56 - 1 ] != '\0' )
goto error;
F_15 ( L_2 , V_47 ) ;
V_46 = F_16 ( V_47 ) ;
V_18 = F_17 ( V_46 ) ;
if ( F_18 ( V_46 ) ) {
V_46 = NULL ;
goto error;
}
F_19 ( V_38 , V_46 ) ;
V_18 = F_10 ( V_46 , 0 , V_38 -> V_52 ,
V_60 ) ;
if ( F_11 ( V_18 != V_60 ) ) {
if ( V_18 >= 0 )
V_18 = - V_27 ;
goto error;
}
V_42 . V_3 = * ( (struct V_2 * ) V_38 -> V_52 ) ;
break;
case V_61 :
#ifdef F_14
if ( V_41 . V_62 == 0 )
V_41 . V_62 = V_16 -> V_63 ;
#endif
break;
}
}
if ( F_20 ( & V_41 . V_3 ) )
V_41 . V_32 |= V_64 ;
if ( V_47 ) {
V_18 = - V_65 ;
if ( ! F_5 ( & V_42 . V_3 , V_46 ) )
goto error;
V_42 . V_32 = V_53 ;
V_18 = F_8 ( & V_42 , V_46 ) ;
if ( V_18 < 0 )
goto error;
}
V_35 = V_41 . V_35 ;
if ( V_41 . V_32 & V_33 )
V_48 = V_66 ;
else if ( V_41 . V_32 & V_34 )
V_48 = V_67 ;
else
V_48 = V_68 ;
if ( V_35 == 0 ) {
V_35 = V_42 . V_35 ;
if ( V_42 . V_32 & V_33 )
V_48 = V_66 ;
else if ( V_42 . V_32 & V_34 )
V_48 = V_67 ;
else
V_48 = V_68 ;
}
V_18 = - V_27 ;
if ( V_35 == 0 )
goto error;
if ( F_20 ( & V_42 . V_3 ) )
V_42 . V_32 |= V_64 ;
V_18 = F_21 ( V_38 ) ;
if ( V_18 )
goto error;
F_22 ( V_69 ) ;
if ( F_23 ( & V_41 . V_3 , V_48 ) )
V_50 -> V_70 |= V_71 ;
F_24 ( V_38 ) ;
F_25 ( & V_1 ) ;
V_50 -> V_72 -> V_73 = 0 ;
V_50 -> V_72 -> V_74 = 0 ;
V_50 -> V_72 -> V_75 = 0 ;
V_50 -> V_72 -> V_76 = 0 ;
V_50 -> V_72 -> V_77 = 0 ;
V_50 -> V_72 -> V_78 . V_79 = 0 ;
V_50 -> V_72 -> V_78 . V_80 = 0 ;
#ifdef F_14
F_26 ( & V_41 ,
& V_42 ,
& V_50 -> V_72 -> V_75 ,
& V_50 -> V_72 -> V_81 ) ;
V_18 = F_27 ( V_38 , V_50 -> V_72 -> V_75 ,
V_48 ) ;
if ( V_18 < 0 ) {
F_28 ( V_82 , V_50 , 0 ) ;
goto V_83;
}
#endif
V_18 = F_29 ( & V_41 , V_38 -> V_4 , V_50 -> V_72 ,
L_3 ) ;
if ( V_18 < 0 )
goto V_83;
if ( V_47 ) {
V_18 = F_29 ( & V_42 , V_46 ,
V_50 -> V_72 , L_4 ) ;
if ( V_18 < 0 ) {
F_30 ( V_84 L_5 ) ;
goto V_83;
}
F_31 ( V_46 ) ;
F_32 ( V_46 ) ;
V_46 = NULL ;
}
#ifdef F_14
if ( ! V_50 -> V_72 -> V_81 )
V_50 -> V_72 -> V_81 = V_50 -> V_72 -> V_77 ;
V_50 -> V_72 -> V_85 = V_50 -> V_72 -> V_81 =
F_33 ( V_50 -> V_72 -> V_81 ) ;
#else
V_35 = ( V_35 + V_86 - 1 ) & V_87 ;
if ( V_35 < V_86 * 2 )
V_35 = V_86 * 2 ;
V_45 = V_88 | V_89 ;
if ( V_48 == V_66 ||
( V_48 == V_68 && V_90 & V_91 ) )
V_45 |= V_92 ;
V_50 -> V_72 -> V_81 = F_34 ( NULL , 0 , V_35 , V_45 ,
V_93 | V_94 |
V_95 | V_96 ,
0 ) ;
if ( F_35 ( V_50 -> V_72 -> V_81 ) ) {
V_18 = V_50 -> V_72 -> V_81 ;
V_50 -> V_72 -> V_81 = 0 ;
goto V_83;
}
V_50 -> V_72 -> V_85 = V_50 -> V_72 -> V_81 ;
V_50 -> V_72 -> V_78 . V_97 = V_50 -> V_72 -> V_81 ;
V_50 -> V_72 -> V_78 . V_97 +=
( V_35 > V_86 ) ? ( V_35 - V_86 ) : 0 ;
V_50 -> V_72 -> V_75 = V_50 -> V_72 -> V_81 + V_35 ;
#endif
F_36 ( V_38 ) ;
if ( F_37 ( V_38 , V_50 -> V_72 ,
& V_41 , & V_42 ) < 0 )
goto V_83;
F_15 ( L_6 , V_50 -> V_72 -> V_73 ) ;
F_15 ( L_7 , V_50 -> V_72 -> V_74 ) ;
F_15 ( L_8 , V_50 -> V_72 -> V_76 ) ;
F_15 ( L_9 , V_50 -> V_72 -> V_77 ) ;
F_15 ( L_10 , V_50 -> V_72 -> V_81 ) ;
F_15 ( L_11 , V_50 -> V_72 -> V_85 ) ;
F_15 ( L_12 , V_50 -> V_72 -> V_75 ) ;
#ifdef F_13
V_44 = V_42 . V_98 ? : V_41 . V_98 ;
F_13 ( V_40 , V_41 . V_99 , V_42 . V_99 ,
V_44 ) ;
#endif
V_43 = V_42 . V_100 ? : V_41 . V_100 ;
F_38 ( V_40 , V_43 , V_50 -> V_72 -> V_75 ) ;
V_18 = 0 ;
error:
if ( V_46 ) {
F_31 ( V_46 ) ;
F_32 ( V_46 ) ;
}
F_39 ( V_47 ) ;
F_39 ( V_41 . V_24 ) ;
F_39 ( V_41 . V_101 ) ;
F_39 ( V_42 . V_24 ) ;
F_39 ( V_42 . V_101 ) ;
return V_18 ;
V_83:
F_28 ( V_102 , V_50 , 0 ) ;
goto error;
}
static int F_37 ( struct V_37 * V_38 ,
struct V_103 * V_72 ,
struct V_13 * V_41 ,
struct V_13 * V_42 )
{
const struct V_104 * V_104 = F_40 () ;
unsigned long V_105 , V_106 , V_107 ;
T_3 T_4 * V_108 , * V_109 ;
T_5 V_110 = 0 , V_111 ;
char * V_112 , * V_113 ;
char T_4 * V_114 , * V_115 , * V_116 ;
long V_117 ;
int V_19 ;
int V_118 ;
#ifdef F_14
V_105 = F_41 ( V_38 -> V_116 ) ;
#else
V_105 = V_72 -> V_75 ;
if ( F_42 ( V_38 , & V_105 ) < 0 )
return - V_119 ;
#endif
V_117 = V_120 ;
V_112 = V_121 ;
V_114 = NULL ;
if ( V_112 ) {
V_110 = strlen ( V_112 ) + 1 ;
V_105 -= V_110 ;
V_114 = ( char T_4 * ) V_105 ;
if ( F_43 ( V_114 , V_112 , V_110 ) != 0 )
return - V_119 ;
}
V_113 = V_122 ;
V_115 = NULL ;
if ( V_113 ) {
V_110 = strlen ( V_113 ) + 1 ;
V_105 -= V_110 ;
V_115 = ( char T_4 * ) V_105 ;
if ( F_43 ( V_115 , V_113 , V_110 ) != 0 )
return - V_119 ;
}
V_105 &= ~ 7UL ;
V_111 = sizeof( struct V_123 ) ;
V_111 += sizeof( struct V_124 ) * V_41 -> V_101 -> V_125 ;
V_105 = ( V_105 - V_111 ) & ~ 7UL ;
V_41 -> V_99 = V_105 ;
if ( F_44 ( ( void T_4 * ) V_105 , V_41 -> V_101 , V_111 ) != 0 )
return - V_119 ;
V_50 -> V_72 -> V_78 . V_79 = ( unsigned long ) V_105 ;
if ( V_42 -> V_101 ) {
V_111 = sizeof( struct V_123 ) ;
V_111 += sizeof( struct V_124 ) *
V_42 -> V_101 -> V_125 ;
V_105 = ( V_105 - V_111 ) & ~ 7UL ;
V_42 -> V_99 = V_105 ;
if ( F_44 ( ( void T_4 * ) V_105 , V_42 -> V_101 ,
V_111 ) != 0 )
return - V_119 ;
V_50 -> V_72 -> V_78 . V_80 = ( unsigned long ) V_105 ;
}
#define F_45 15
V_107 = 1 + F_45 + ( V_112 ? 1 : 0 ) +
( V_113 ? 1 : 0 ) + V_126 ;
if ( V_38 -> V_127 & V_128 )
V_107 ++ ;
V_106 = V_105 ;
V_105 -= V_107 * 2 * sizeof( unsigned long ) ;
V_105 -= ( V_38 -> V_129 + 1 ) * sizeof( char * ) ;
V_105 -= ( V_38 -> V_130 + 1 ) * sizeof( char * ) ;
V_105 -= 1 * sizeof( unsigned long ) ;
V_106 -= V_105 & 15UL ;
V_105 -= V_105 & 15UL ;
#define F_46 ( T_6 , T_7 ) \
do { \
struct { unsigned long _id, _val; } __user *ent; \
\
ent = (void __user *) csp; \
__put_user((id), &ent[nr]._id); \
__put_user((val), &ent[nr]._val); \
nr++; \
} while (0)
V_118 = 0 ;
V_106 -= 2 * sizeof( unsigned long ) ;
F_46 ( V_131 , 0 ) ;
if ( V_112 ) {
V_118 = 0 ;
V_106 -= 2 * sizeof( unsigned long ) ;
F_46 ( V_132 ,
( V_133 ) ( unsigned long ) V_114 ) ;
}
if ( V_113 ) {
V_118 = 0 ;
V_106 -= 2 * sizeof( unsigned long ) ;
F_46 ( V_134 ,
( V_133 ) ( unsigned long ) V_115 ) ;
}
if ( V_38 -> V_127 & V_128 ) {
V_118 = 0 ;
V_106 -= 2 * sizeof( unsigned long ) ;
F_46 ( V_135 , V_38 -> V_136 ) ;
}
V_118 = 0 ;
V_106 -= F_45 * 2 * sizeof( unsigned long ) ;
F_46 ( V_137 , V_117 ) ;
F_46 ( V_138 , V_86 ) ;
F_46 ( V_139 , V_140 ) ;
F_46 ( V_141 , V_41 -> V_142 ) ;
F_46 ( V_143 , sizeof( struct V_21 ) ) ;
F_46 ( V_144 , V_41 -> V_3 . V_23 ) ;
F_46 ( V_145 , V_42 -> V_146 ) ;
F_46 ( V_147 , 0 ) ;
F_46 ( V_148 , V_41 -> V_100 ) ;
F_46 ( V_149 , ( V_133 ) F_47 ( V_104 -> V_150 , V_104 -> V_151 ) ) ;
F_46 ( V_152 , ( V_133 ) F_47 ( V_104 -> V_150 , V_104 -> V_153 ) ) ;
F_46 ( V_154 , ( V_133 ) F_48 ( V_104 -> V_150 , V_104 -> V_155 ) ) ;
F_46 ( V_156 , ( V_133 ) F_48 ( V_104 -> V_150 , V_104 -> V_157 ) ) ;
F_46 ( V_158 , F_49 ( V_38 ) ) ;
F_46 ( V_159 , V_38 -> V_160 ) ;
#ifdef F_50
V_118 = 0 ;
V_106 -= V_126 * 2 * sizeof( unsigned long ) ;
F_50 ;
#endif
#undef F_46
V_106 -= ( V_38 -> V_129 + 1 ) * sizeof( T_3 ) ;
V_109 = ( T_3 T_4 * ) V_106 ;
V_106 -= ( V_38 -> V_130 + 1 ) * sizeof( T_3 ) ;
V_108 = ( T_3 T_4 * ) V_106 ;
V_106 -= sizeof( unsigned long ) ;
F_51 ( V_38 -> V_130 , ( unsigned long T_4 * ) V_106 ) ;
F_52 ( V_106 != V_105 ) ;
#ifdef F_14
V_50 -> V_72 -> V_161 = V_38 -> V_116 ;
#else
V_50 -> V_72 -> V_161 = V_50 -> V_72 -> V_75 -
( V_162 * V_86 - V_38 -> V_116 ) ;
#endif
V_116 = ( char T_4 * ) V_50 -> V_72 -> V_161 ;
for ( V_19 = V_38 -> V_130 ; V_19 > 0 ; V_19 -- ) {
F_51 ( ( T_3 ) V_116 , V_108 ++ ) ;
V_111 = F_53 ( V_116 , V_163 ) ;
if ( ! V_111 || V_111 > V_163 )
return - V_164 ;
V_116 += V_111 ;
}
F_51 ( NULL , V_108 ) ;
V_50 -> V_72 -> V_165 = ( unsigned long ) V_116 ;
V_50 -> V_72 -> V_166 = ( unsigned long ) V_116 ;
for ( V_19 = V_38 -> V_129 ; V_19 > 0 ; V_19 -- ) {
F_51 ( ( T_3 ) ( unsigned long ) V_116 , V_109 ++ ) ;
V_111 = F_53 ( V_116 , V_163 ) ;
if ( ! V_111 || V_111 > V_163 )
return - V_164 ;
V_116 += V_111 ;
}
F_51 ( NULL , V_109 ) ;
V_50 -> V_72 -> V_167 = ( unsigned long ) V_116 ;
V_72 -> V_75 = ( unsigned long ) V_105 ;
return 0 ;
}
static int F_42 ( struct V_37 * V_38 ,
unsigned long * V_168 )
{
unsigned long V_169 , V_170 , V_105 ;
char * V_171 ;
int V_172 = 0 ;
V_170 = V_38 -> V_116 >> V_173 ;
V_105 = * V_168 ;
for ( V_169 = V_162 - 1 ; V_169 >= V_170 ; V_169 -- ) {
V_171 = F_54 ( V_38 -> V_174 [ V_169 ] ) ;
V_105 -= V_86 ;
if ( F_44 ( ( void * ) V_105 , V_171 , V_86 ) != 0 )
V_172 = - V_119 ;
F_55 ( V_38 -> V_174 [ V_169 ] ) ;
if ( V_172 < 0 )
goto V_175;
}
* V_168 = ( * V_168 - ( V_162 * V_86 - V_38 -> V_116 ) ) & ~ 15 ;
V_175:
return V_172 ;
}
static int F_29 ( struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_103 * V_72 ,
const char * V_176 )
{
struct V_123 * V_101 ;
#ifdef F_14
struct V_124 * V_177 ;
#endif
struct V_124 * V_178 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_170 ;
unsigned V_179 , V_180 ;
T_5 V_17 ;
int V_19 , V_172 ;
V_179 = 0 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ )
if ( V_14 -> V_24 [ V_19 ] . V_28 == V_61 )
V_179 ++ ;
if ( V_179 == 0 )
return - V_65 ;
V_17 = sizeof( * V_101 ) + V_179 * sizeof( * V_178 ) ;
V_101 = F_56 ( V_17 , V_25 ) ;
if ( ! V_101 )
return - V_22 ;
V_14 -> V_101 = V_101 ;
V_101 -> V_181 = V_182 ;
V_101 -> V_125 = V_179 ;
V_62 = V_14 -> V_62 ;
V_178 = V_101 -> V_183 ;
switch ( V_14 -> V_32 & V_184 ) {
case V_64 :
case V_185 :
#ifndef F_14
V_172 = F_57 ( V_14 , V_4 , V_72 ) ;
if ( V_172 < 0 )
return V_172 ;
break;
#endif
default:
V_172 = F_58 ( V_14 , V_4 , V_72 ) ;
if ( V_172 < 0 )
return V_172 ;
break;
}
if ( V_14 -> V_3 . V_186 ) {
V_178 = V_101 -> V_183 ;
for ( V_19 = V_101 -> V_125 ; V_19 > 0 ; V_19 -- , V_178 ++ ) {
if ( V_14 -> V_3 . V_186 >= V_178 -> V_63 &&
V_14 -> V_3 . V_186 < V_178 -> V_63 + V_178 -> V_36 ) {
V_14 -> V_100 =
( V_14 -> V_3 . V_186 - V_178 -> V_63 ) +
V_178 -> V_187 ;
break;
}
}
}
V_170 = V_14 -> V_3 . V_26 ;
V_170 += V_14 -> V_3 . V_23 * sizeof ( struct V_21 ) ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_16 -> V_28 != V_61 )
continue;
if ( V_16 -> V_59 > V_14 -> V_3 . V_26 ||
V_16 -> V_59 + V_16 -> V_56 < V_170 )
continue;
V_178 = V_101 -> V_183 ;
for ( V_19 = V_101 -> V_125 ; V_19 > 0 ; V_19 -- , V_178 ++ ) {
if ( V_16 -> V_63 >= V_178 -> V_63 &&
V_16 -> V_63 + V_16 -> V_56 <=
V_178 -> V_63 + V_178 -> V_36 ) {
V_14 -> V_142 =
( V_16 -> V_63 - V_178 -> V_63 ) +
V_178 -> V_187 +
V_14 -> V_3 . V_26 - V_16 -> V_59 ;
break;
}
}
break;
}
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_16 -> V_28 != V_188 )
continue;
V_178 = V_101 -> V_183 ;
for ( V_19 = V_101 -> V_125 ; V_19 > 0 ; V_19 -- , V_178 ++ ) {
if ( V_16 -> V_63 >= V_178 -> V_63 &&
V_16 -> V_63 + V_16 -> V_36 <=
V_178 -> V_63 + V_178 -> V_36 ) {
V_14 -> V_98 =
( V_16 -> V_63 - V_178 -> V_63 ) +
V_178 -> V_187 ;
if ( V_16 -> V_36 == 0 ||
V_16 -> V_36 % sizeof( V_189 ) != 0 )
goto V_190;
V_180 = V_16 -> V_36 / sizeof( V_189 ) ;
if ( ( ( V_189 * )
V_14 -> V_98 ) [ V_180 - 1 ] . V_191 != 0 )
goto V_190;
break;
}
}
break;
}
#ifdef F_14
V_179 = V_101 -> V_125 ;
V_177 = V_101 -> V_183 ;
V_178 = V_177 + 1 ;
for ( V_19 = 1 ; V_19 < V_179 ; V_19 ++ ) {
if ( V_178 -> V_63 - V_177 -> V_63 == V_178 -> V_187 - V_177 -> V_187 ) {
V_62 = F_33 ( V_177 -> V_187 + V_177 -> V_36 ) ;
if ( V_62 == ( V_178 -> V_187 & V_87 ) ) {
V_177 -> V_36 +=
V_62 -
( V_177 -> V_187 + V_177 -> V_36 ) ;
V_177 -> V_36 += V_178 -> V_187 & ~ V_87 ;
V_177 -> V_36 += V_178 -> V_36 ;
V_101 -> V_125 -- ;
continue;
}
}
V_177 ++ ;
if ( V_177 != V_178 )
* V_177 = * V_178 ;
}
#endif
F_15 ( L_13 , V_176 ) ;
F_15 ( L_14 , V_14 -> V_146 ) ;
F_15 ( L_15 , V_14 -> V_100 ) ;
F_15 ( L_16 , V_14 -> V_142 ) ;
F_15 ( L_17 , V_14 -> V_98 ) ;
V_178 = V_101 -> V_183 ;
for ( V_19 = 0 ; V_19 < V_101 -> V_125 ; V_19 ++ , V_178 ++ )
F_15 ( L_18 ,
V_19 ,
V_178 -> V_187 , V_178 -> V_187 + V_178 -> V_36 - 1 ,
V_178 -> V_63 , V_178 -> V_36 ) ;
return 0 ;
V_190:
F_30 ( L_19 ,
V_176 , V_4 -> V_192 . V_193 -> V_194 -> V_195 ) ;
return - V_65 ;
}
static int F_57 (
struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_103 * V_72 )
{
struct V_124 * V_178 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_196 = V_197 , V_198 = 0 , V_199 = 0 , V_200 ;
T_8 V_201 ;
int V_19 , V_172 ;
V_62 = V_14 -> V_62 ;
V_178 = V_14 -> V_101 -> V_183 ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_14 -> V_24 [ V_19 ] . V_28 != V_61 )
continue;
if ( V_196 > V_16 -> V_63 )
V_196 = V_16 -> V_63 ;
if ( V_198 < V_16 -> V_63 + V_16 -> V_36 )
V_198 = V_16 -> V_63 + V_16 -> V_36 ;
}
V_200 = V_93 ;
if ( V_14 -> V_32 & V_54 )
V_200 |= V_202 ;
V_199 = F_34 ( NULL , V_62 , V_198 - V_196 ,
V_88 | V_89 | V_92 , V_200 , 0 ) ;
if ( F_35 ( V_199 ) )
return ( int ) V_199 ;
if ( V_62 != 0 )
V_62 += F_33 ( V_198 - V_196 ) ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_14 -> V_24 [ V_19 ] . V_28 != V_61 )
continue;
V_201 = V_16 -> V_59 ;
V_178 -> V_187 = V_199 + ( V_16 -> V_63 - V_196 ) ;
V_178 -> V_63 = V_16 -> V_63 ;
V_178 -> V_36 = V_16 -> V_36 ;
V_172 = V_4 -> V_11 -> V_203 ( V_4 , ( void * ) V_178 -> V_187 ,
V_16 -> V_56 , & V_201 ) ;
if ( V_172 < 0 )
return V_172 ;
if ( V_16 -> V_59 == 0 )
V_14 -> V_146 = V_178 -> V_187 ;
if ( V_16 -> V_56 < V_16 -> V_36 ) {
if ( F_59 ( ( void * ) ( V_178 -> V_187 + V_16 -> V_56 ) ,
V_16 -> V_36 - V_16 -> V_56 ) )
return - V_119 ;
}
if ( V_72 ) {
if ( V_16 -> V_30 & V_31 ) {
if ( ! V_72 -> V_73 ) {
V_72 -> V_73 = V_178 -> V_187 ;
V_72 -> V_74 = V_178 -> V_187 +
V_16 -> V_36 ;
}
} else if ( ! V_72 -> V_76 ) {
V_72 -> V_76 = V_178 -> V_187 ;
V_72 -> V_77 = V_178 -> V_187 + V_16 -> V_36 ;
}
}
V_178 ++ ;
}
return 0 ;
}
static int F_58 ( struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_103 * V_72 )
{
struct V_124 * V_178 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_204 ;
int V_19 , V_205 ;
V_62 = V_14 -> V_62 ;
V_204 = 0 ;
V_205 = 0 ;
V_178 = V_14 -> V_101 -> V_183 ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
unsigned long V_199 , V_206 , V_207 , V_208 ;
int V_209 = 0 , V_32 ;
if ( V_16 -> V_28 != V_61 )
continue;
F_15 ( L_20 ,
( unsigned long ) V_16 -> V_63 ,
( unsigned long ) V_16 -> V_59 ,
( unsigned long ) V_16 -> V_56 ,
( unsigned long ) V_16 -> V_36 ) ;
if ( V_16 -> V_30 & V_210 ) V_209 |= V_88 ;
if ( V_16 -> V_30 & V_211 ) V_209 |= V_89 ;
if ( V_16 -> V_30 & V_31 ) V_209 |= V_92 ;
V_32 = V_93 | V_212 ;
if ( V_14 -> V_32 & V_54 )
V_32 |= V_202 ;
V_199 = 0 ;
switch ( V_14 -> V_32 & V_184 ) {
case V_213 :
break;
case V_214 :
V_199 = V_16 -> V_63 ;
V_32 |= V_215 ;
break;
case V_64 :
if ( ! V_205 ) {
V_199 = V_62 ;
V_204 = V_16 -> V_63 ;
V_205 = 1 ;
} else {
V_199 = V_62 + V_16 -> V_63 - V_204 ;
V_32 |= V_215 ;
}
break;
case V_185 :
break;
default:
F_60 () ;
}
V_199 &= V_87 ;
V_206 = V_16 -> V_63 & ~ V_87 ;
V_199 = F_34 ( V_4 , V_199 , V_16 -> V_36 + V_206 , V_209 , V_32 ,
V_16 -> V_59 - V_206 ) ;
F_15 ( L_21 ,
V_19 , V_16 -> V_36 + V_206 , V_209 , V_32 ,
V_16 -> V_59 - V_206 , V_199 ) ;
if ( F_35 ( V_199 ) )
return ( int ) V_199 ;
if ( ( V_14 -> V_32 & V_184 ) ==
V_185 )
V_62 += F_33 ( V_16 -> V_36 + V_206 ) ;
V_178 -> V_187 = V_199 + V_206 ;
V_178 -> V_63 = V_16 -> V_63 ;
V_178 -> V_36 = V_16 -> V_36 ;
if ( V_16 -> V_59 == 0 )
V_14 -> V_146 = V_178 -> V_187 ;
if ( V_209 & V_89 && V_206 > 0 ) {
F_15 ( L_22 , V_19 , V_199 , V_206 ) ;
if ( F_59 ( ( void T_4 * ) V_199 , V_206 ) )
return - V_119 ;
V_199 += V_206 ;
}
V_207 = V_16 -> V_36 - V_16 -> V_56 ;
V_208 = V_86 - ( ( V_199 + V_16 -> V_56 ) & ~ V_87 ) ;
#ifdef F_14
if ( V_207 > V_208 ) {
unsigned long V_216 = V_199 + V_16 -> V_56 + V_208 ;
unsigned long V_217 ;
V_32 |= V_215 | V_94 ;
V_217 = F_34 ( NULL , V_216 , V_207 - V_208 ,
V_209 , V_32 , 0 ) ;
F_15 ( L_23
L_24 ,
V_19 , V_216 , V_207 - V_208 , V_209 , V_32 ,
V_217 ) ;
if ( V_217 != V_216 )
return - V_22 ;
}
if ( V_209 & V_89 && V_208 > 0 ) {
F_15 ( L_22 ,
V_19 , V_199 + V_16 -> V_56 , V_208 ) ;
if ( F_59 ( ( void T_4 * ) V_199 + V_16 -> V_56 ,
V_208 ) )
return - V_119 ;
}
#else
if ( V_207 > 0 ) {
F_15 ( L_22 ,
V_19 , V_199 + V_16 -> V_56 , V_207 ) ;
if ( F_59 ( ( void * ) V_199 + V_16 -> V_56 , V_207 ) )
return - V_119 ;
}
#endif
if ( V_72 ) {
if ( V_16 -> V_30 & V_31 ) {
if ( ! V_72 -> V_73 ) {
V_72 -> V_73 = V_199 ;
V_72 -> V_74 = V_199 + V_16 -> V_36 ;
}
} else if ( ! V_72 -> V_76 ) {
V_72 -> V_76 = V_199 ;
V_72 -> V_77 = V_199 + V_16 -> V_36 ;
}
}
V_178 ++ ;
}
return 0 ;
}
static int F_61 ( struct V_218 * V_219 , unsigned long V_220 )
{
int V_221 ;
if ( V_219 -> V_222 & V_223 ) {
F_62 ( L_25 , V_219 -> V_224 , V_219 -> V_222 ) ;
return 0 ;
}
if ( ! ( V_219 -> V_222 & V_225 ) ) {
F_62 ( L_26 , V_219 -> V_224 , V_219 -> V_222 ) ;
return 0 ;
}
if ( V_219 -> V_222 & V_226 ) {
if ( V_219 -> V_227 -> V_192 . V_193 -> V_194 -> V_228 == 0 ) {
V_221 = F_63 ( V_229 , & V_220 ) ;
F_62 ( L_27 , V_219 -> V_224 ,
V_219 -> V_222 , V_221 ? L_28 : L_29 ) ;
return V_221 ;
}
V_221 = F_63 ( V_230 , & V_220 ) ;
F_62 ( L_27 , V_219 -> V_224 ,
V_219 -> V_222 , V_221 ? L_28 : L_29 ) ;
return V_221 ;
}
#ifdef F_14
if ( ! V_219 -> V_231 ) {
V_221 = F_63 ( V_232 , & V_220 ) ;
F_62 ( L_30 , V_219 -> V_224 ,
V_219 -> V_222 , V_221 ? L_28 : L_29 ) ;
return V_221 ;
}
#endif
V_221 = F_63 ( V_233 , & V_220 ) ;
F_62 ( L_31 , V_219 -> V_224 , V_219 -> V_222 ,
V_221 ? L_28 : L_29 ) ;
return V_221 ;
}
static int F_64 ( struct V_234 * V_235 )
{
int V_236 ;
V_236 = sizeof( struct V_237 ) ;
V_236 += F_65 ( strlen ( V_235 -> V_238 ) + 1 , 4 ) ;
V_236 += F_65 ( V_235 -> V_239 , 4 ) ;
return V_236 ;
}
static int F_66 ( struct V_4 * V_4 , T_8 * V_240 )
{
static const char V_52 [ 4 ] = { 0 , } ;
F_67 ( V_52 , F_65 ( * V_240 , 4 ) - * V_240 , V_240 ) ;
return 1 ;
}
static int F_68 ( struct V_234 * V_241 , struct V_4 * V_4 ,
T_8 * V_240 )
{
struct V_237 V_235 ;
V_235 . V_242 = strlen ( V_241 -> V_238 ) + 1 ;
V_235 . V_243 = V_241 -> V_239 ;
V_235 . V_244 = V_241 -> type ;
F_67 ( & V_235 , sizeof( V_235 ) , V_240 ) ;
F_67 ( V_241 -> V_238 , V_235 . V_242 , V_240 ) ;
if ( ! F_66 ( V_4 , V_240 ) )
return 0 ;
F_67 ( V_241 -> V_245 , V_241 -> V_239 , V_240 ) ;
if ( ! F_66 ( V_4 , V_240 ) )
return 0 ;
return 1 ;
}
static inline void F_69 ( struct V_2 * V_246 , int V_183 )
{
memcpy ( V_246 -> V_5 , V_6 , V_7 ) ;
V_246 -> V_5 [ V_247 ] = V_248 ;
V_246 -> V_5 [ V_249 ] = V_250 ;
V_246 -> V_5 [ V_251 ] = V_252 ;
V_246 -> V_5 [ V_253 ] = V_254 ;
memset ( V_246 -> V_5 + V_255 , 0 , V_256 - V_255 ) ;
V_246 -> V_8 = V_257 ;
V_246 -> V_258 = V_259 ;
V_246 -> V_260 = V_252 ;
V_246 -> V_186 = 0 ;
V_246 -> V_26 = sizeof( struct V_2 ) ;
V_246 -> V_261 = 0 ;
V_246 -> V_262 = V_263 ;
V_246 -> V_264 = sizeof( struct V_2 ) ;
V_246 -> V_20 = sizeof( struct V_21 ) ;
V_246 -> V_23 = V_183 ;
V_246 -> V_265 = 0 ;
V_246 -> V_266 = 0 ;
V_246 -> V_267 = 0 ;
return;
}
static inline void F_70 ( struct V_21 * V_16 , int V_236 , T_8 V_268 )
{
V_16 -> V_28 = V_269 ;
V_16 -> V_59 = V_268 ;
V_16 -> V_63 = 0 ;
V_16 -> V_270 = 0 ;
V_16 -> V_56 = V_236 ;
V_16 -> V_36 = 0 ;
V_16 -> V_30 = 0 ;
V_16 -> V_271 = 0 ;
return;
}
static inline void F_71 ( struct V_234 * V_272 , const char * V_238 , int type ,
unsigned int V_236 , void * V_245 )
{
V_272 -> V_238 = V_238 ;
V_272 -> type = type ;
V_272 -> V_239 = V_236 ;
V_272 -> V_245 = V_245 ;
return;
}
static void F_72 ( struct V_273 * V_274 ,
struct V_275 * V_116 , long V_276 )
{
V_274 -> V_277 . V_278 = V_274 -> V_279 = V_276 ;
V_274 -> V_280 = V_116 -> V_281 . signal . V_282 [ 0 ] ;
V_274 -> V_283 = V_116 -> V_284 . V_282 [ 0 ] ;
F_73 () ;
V_274 -> V_285 = F_74 ( F_75 ( V_116 -> V_286 ) ) ;
F_76 () ;
V_274 -> V_287 = F_74 ( V_116 ) ;
V_274 -> V_288 = F_77 ( V_116 ) ;
V_274 -> V_289 = F_78 ( V_116 ) ;
if ( F_79 ( V_116 ) ) {
struct V_290 V_291 ;
F_80 ( V_116 , & V_291 ) ;
F_81 ( V_291 . V_292 , & V_274 -> V_293 ) ;
F_81 ( V_291 . V_294 , & V_274 -> V_295 ) ;
} else {
F_81 ( V_116 -> V_292 , & V_274 -> V_293 ) ;
F_81 ( V_116 -> V_294 , & V_274 -> V_295 ) ;
}
F_81 ( V_116 -> signal -> V_296 , & V_274 -> V_297 ) ;
F_81 ( V_116 -> signal -> V_298 , & V_274 -> V_299 ) ;
V_274 -> V_300 = V_116 -> V_72 -> V_78 . V_79 ;
V_274 -> V_301 = V_116 -> V_72 -> V_78 . V_80 ;
}
static int F_82 ( struct V_302 * V_303 , struct V_275 * V_116 ,
struct V_103 * V_72 )
{
const struct V_104 * V_104 ;
unsigned int V_49 , V_111 ;
memset ( V_303 , 0 , sizeof( struct V_302 ) ) ;
V_111 = V_72 -> V_165 - V_72 -> V_161 ;
if ( V_111 >= V_304 )
V_111 = V_304 - 1 ;
if ( F_83 ( & V_303 -> V_305 ,
( const char T_4 * ) V_72 -> V_161 , V_111 ) )
return - V_119 ;
for ( V_49 = 0 ; V_49 < V_111 ; V_49 ++ )
if ( V_303 -> V_305 [ V_49 ] == 0 )
V_303 -> V_305 [ V_49 ] = ' ' ;
V_303 -> V_305 [ V_111 ] = 0 ;
F_73 () ;
V_303 -> V_285 = F_74 ( F_75 ( V_116 -> V_286 ) ) ;
F_76 () ;
V_303 -> V_287 = F_74 ( V_116 ) ;
V_303 -> V_288 = F_77 ( V_116 ) ;
V_303 -> V_289 = F_78 ( V_116 ) ;
V_49 = V_116 -> V_306 ? F_84 ( ~ V_116 -> V_306 ) + 1 : 0 ;
V_303 -> V_307 = V_49 ;
V_303 -> V_308 = ( V_49 > 5 ) ? '.' : L_32 [ V_49 ] ;
V_303 -> V_309 = V_303 -> V_308 == 'Z' ;
V_303 -> V_310 = F_85 ( V_116 ) ;
V_303 -> V_311 = V_116 -> V_32 ;
F_73 () ;
V_104 = F_86 ( V_116 ) ;
F_87 ( V_303 -> V_312 , F_47 ( V_104 -> V_150 , V_104 -> V_151 ) ) ;
F_88 ( V_303 -> V_313 , F_48 ( V_104 -> V_150 , V_104 -> V_155 ) ) ;
F_76 () ;
strncpy ( V_303 -> V_314 , V_116 -> V_315 , sizeof( V_303 -> V_314 ) ) ;
return 0 ;
}
static int F_89 ( long V_276 , struct V_316 * V_317 )
{
struct V_275 * V_116 = V_317 -> V_318 ;
int V_236 = 0 ;
V_317 -> V_319 = 0 ;
F_72 ( & V_317 -> V_274 , V_116 , V_276 ) ;
F_90 ( V_116 , & V_317 -> V_274 . V_320 ) ;
F_71 ( & V_317 -> V_321 [ 0 ] , L_33 , V_322 , sizeof( V_317 -> V_274 ) ,
& V_317 -> V_274 ) ;
V_317 -> V_319 ++ ;
V_236 += F_64 ( & V_317 -> V_321 [ 0 ] ) ;
V_317 -> V_274 . V_323 = F_91 ( V_116 , NULL , & V_317 -> V_324 ) ;
if ( V_317 -> V_274 . V_323 ) {
F_71 ( & V_317 -> V_321 [ 1 ] , L_33 , V_325 , sizeof( V_317 -> V_324 ) ,
& V_317 -> V_324 ) ;
V_317 -> V_319 ++ ;
V_236 += F_64 ( & V_317 -> V_321 [ 1 ] ) ;
}
#ifdef F_92
if ( F_93 ( V_116 , & V_317 -> V_326 ) ) {
F_71 ( & V_317 -> V_321 [ 2 ] , L_34 , V_327 ,
sizeof( V_317 -> V_326 ) , & V_317 -> V_326 ) ;
V_317 -> V_319 ++ ;
V_236 += F_64 ( & V_317 -> V_321 [ 2 ] ) ;
}
#endif
return V_236 ;
}
static void F_94 ( struct V_2 * V_246 , struct V_328 * V_329 ,
V_133 V_261 , int V_183 )
{
V_246 -> V_261 = V_261 ;
V_246 -> V_265 = sizeof( * V_329 ) ;
V_246 -> V_266 = 1 ;
V_246 -> V_267 = V_330 ;
memset ( V_329 , 0 , sizeof( * V_329 ) ) ;
V_329 -> V_331 = V_332 ;
V_329 -> V_333 = V_246 -> V_266 ;
V_329 -> V_334 = V_246 -> V_267 ;
V_329 -> V_335 = V_183 ;
}
static int F_95 ( struct V_4 * V_4 , T_5 * V_17 ,
unsigned long * V_336 , unsigned long V_220 )
{
struct V_218 * V_219 ;
int V_337 = 0 ;
for ( V_219 = V_50 -> V_72 -> V_12 ; V_219 ; V_219 = V_219 -> V_338 ) {
unsigned long V_187 ;
if ( ! F_61 ( V_219 , V_220 ) )
continue;
for ( V_187 = V_219 -> V_224 ; V_187 < V_219 -> V_339 ;
V_187 += V_86 ) {
struct V_174 * V_174 = F_96 ( V_187 ) ;
if ( V_174 ) {
void * V_340 = F_54 ( V_174 ) ;
* V_17 += V_86 ;
if ( * V_17 > * V_336 )
V_337 = - V_341 ;
else if ( ! F_97 ( V_4 , V_340 , V_86 ) )
V_337 = - V_342 ;
F_55 ( V_174 ) ;
F_98 ( V_174 ) ;
} else if ( ! F_99 ( V_4 , V_86 ) )
V_337 = - V_341 ;
if ( V_337 )
goto V_175;
}
}
V_175:
return V_337 ;
}
static int F_95 ( struct V_4 * V_4 , T_5 * V_17 ,
unsigned long * V_336 , unsigned long V_220 )
{
struct V_218 * V_219 ;
for ( V_219 = V_50 -> V_72 -> V_12 ; V_219 ; V_219 = V_219 -> V_338 ) {
if ( ! F_61 ( V_219 , V_220 ) )
continue;
if ( ( * V_17 += V_86 ) > * V_336 )
return - V_341 ;
if ( ! F_97 ( V_4 , ( void * ) V_219 -> V_224 ,
V_219 -> V_339 - V_219 -> V_224 ) )
return - V_342 ;
}
return 0 ;
}
static T_5 F_100 ( unsigned long V_220 )
{
struct V_218 * V_219 ;
T_5 V_17 = 0 ;
for ( V_219 = V_50 -> V_72 -> V_12 ; V_219 ; V_219 = V_219 -> V_338 )
if ( F_61 ( V_219 , V_220 ) )
V_17 += V_219 -> V_339 - V_219 -> V_224 ;
return V_17 ;
}
static int F_101 ( struct V_343 * V_344 )
{
#define F_102 6
int V_345 = 0 ;
T_9 V_346 ;
int V_183 ;
T_5 V_17 = 0 ;
int V_49 ;
struct V_218 * V_219 ;
struct V_2 * V_246 = NULL ;
T_8 V_268 = 0 , V_347 , V_240 ;
int V_348 ;
struct V_234 * V_321 = NULL ;
struct V_273 * V_274 = NULL ;
struct V_302 * V_303 = NULL ;
F_103 ( V_349 ) ;
struct V_350 * V_317 ;
T_10 * V_324 = NULL ;
#ifdef F_92
T_11 * V_326 = NULL ;
#endif
int V_351 = 0 ;
V_133 * V_352 ;
struct V_21 * V_353 = NULL ;
struct V_328 * V_329 = NULL ;
T_12 V_23 ;
V_133 V_261 ;
V_246 = F_9 ( sizeof( * V_246 ) , V_25 ) ;
if ( ! V_246 )
goto V_354;
V_274 = F_56 ( sizeof( * V_274 ) , V_25 ) ;
if ( ! V_274 )
goto V_354;
V_303 = F_9 ( sizeof( * V_303 ) , V_25 ) ;
if ( ! V_303 )
goto V_354;
V_321 = F_9 ( F_102 * sizeof( struct V_234 ) , V_25 ) ;
if ( ! V_321 )
goto V_354;
V_324 = F_9 ( sizeof( * V_324 ) , V_25 ) ;
if ( ! V_324 )
goto V_354;
#ifdef F_92
V_326 = F_9 ( sizeof( * V_326 ) , V_25 ) ;
if ( ! V_326 )
goto V_354;
#endif
if ( V_344 -> V_355 -> V_278 ) {
struct V_356 * V_357 ;
struct V_316 * V_180 ;
for ( V_357 = V_50 -> V_72 -> V_358 -> V_359 . V_360 ;
V_357 ; V_357 = V_357 -> V_360 ) {
V_180 = F_56 ( sizeof( * V_180 ) , V_25 ) ;
if ( ! V_180 )
goto V_354;
V_180 -> V_318 = V_357 -> V_361 ;
F_104 ( & V_180 -> V_362 , & V_349 ) ;
}
F_105 (t, &thread_list) {
struct V_316 * V_180 ;
int V_236 ;
V_180 = F_106 ( V_317 , struct V_316 , V_362 ) ;
V_236 = F_89 ( V_344 -> V_355 -> V_278 , V_180 ) ;
V_351 += V_236 ;
}
}
F_72 ( V_274 , V_50 , V_344 -> V_355 -> V_278 ) ;
F_107 ( & V_274 -> V_320 , V_344 -> V_40 ) ;
V_183 = V_50 -> V_72 -> V_363 ;
V_183 += F_108 () ;
V_183 ++ ;
V_23 = V_183 > V_364 ? V_364 : V_183 ;
F_69 ( V_246 , V_23 ) ;
V_345 = 1 ;
V_50 -> V_32 |= V_365 ;
F_71 ( V_321 + 0 , L_33 , V_322 , sizeof( * V_274 ) , V_274 ) ;
F_82 ( V_303 , V_50 -> V_366 , V_50 -> V_72 ) ;
F_71 ( V_321 + 1 , L_33 , V_367 , sizeof( * V_303 ) , V_303 ) ;
V_348 = 2 ;
V_352 = ( V_133 * ) V_50 -> V_72 -> V_368 ;
V_49 = 0 ;
do
V_49 += 2 ;
while ( V_352 [ V_49 - 2 ] != V_131 );
F_71 ( & V_321 [ V_348 ++ ] , L_33 , V_369 ,
V_49 * sizeof( V_133 ) , V_352 ) ;
if ( ( V_274 -> V_323 =
F_91 ( V_50 , V_344 -> V_40 , V_324 ) ) )
F_71 ( V_321 + V_348 ++ ,
L_33 , V_325 , sizeof( * V_324 ) , V_324 ) ;
#ifdef F_92
if ( F_93 ( V_50 , V_326 ) )
F_71 ( V_321 + V_348 ++ ,
L_34 , V_327 , sizeof( * V_326 ) , V_326 ) ;
#endif
V_346 = F_109 () ;
F_110 ( V_370 ) ;
V_268 += sizeof( * V_246 ) ;
V_268 += V_183 * sizeof( struct V_21 ) ;
V_240 = V_268 ;
{
int V_236 = 0 ;
for ( V_49 = 0 ; V_49 < V_348 ; V_49 ++ )
V_236 += F_64 ( V_321 + V_49 ) ;
V_236 += V_351 ;
V_353 = F_9 ( sizeof( * V_353 ) , V_25 ) ;
if ( ! V_353 )
goto V_371;
F_70 ( V_353 , V_236 , V_268 ) ;
V_268 += V_236 ;
}
V_347 = V_268 = F_65 ( V_268 , V_372 ) ;
V_268 += F_100 ( V_344 -> V_220 ) ;
V_268 += F_111 () ;
V_261 = V_268 ;
if ( V_23 == V_364 ) {
V_329 = F_9 ( sizeof( * V_329 ) , V_25 ) ;
if ( ! V_329 )
goto V_371;
F_94 ( V_246 , V_329 , V_261 , V_183 ) ;
}
V_268 = V_347 ;
V_17 += sizeof( * V_246 ) ;
if ( V_17 > V_344 -> V_336 || ! F_97 ( V_344 -> V_4 , V_246 , sizeof( * V_246 ) ) )
goto V_371;
V_17 += sizeof( * V_353 ) ;
if ( V_17 > V_344 -> V_336
|| ! F_97 ( V_344 -> V_4 , V_353 , sizeof( * V_353 ) ) )
goto V_371;
for ( V_219 = V_50 -> V_72 -> V_12 ; V_219 ; V_219 = V_219 -> V_338 ) {
struct V_21 V_16 ;
T_5 V_236 ;
V_236 = V_219 -> V_339 - V_219 -> V_224 ;
V_16 . V_28 = V_61 ;
V_16 . V_59 = V_268 ;
V_16 . V_63 = V_219 -> V_224 ;
V_16 . V_270 = 0 ;
V_16 . V_56 = F_61 ( V_219 , V_344 -> V_220 ) ? V_236 : 0 ;
V_16 . V_36 = V_236 ;
V_268 += V_16 . V_56 ;
V_16 . V_30 = V_219 -> V_222 & V_225 ? V_210 : 0 ;
if ( V_219 -> V_222 & V_373 )
V_16 . V_30 |= V_211 ;
if ( V_219 -> V_222 & V_91 )
V_16 . V_30 |= V_31 ;
V_16 . V_271 = V_372 ;
V_17 += sizeof( V_16 ) ;
if ( V_17 > V_344 -> V_336
|| ! F_97 ( V_344 -> V_4 , & V_16 , sizeof( V_16 ) ) )
goto V_371;
}
if ( ! F_112 ( V_344 -> V_4 , V_268 , & V_17 , V_344 -> V_336 ) )
goto V_371;
for ( V_49 = 0 ; V_49 < V_348 ; V_49 ++ )
if ( ! F_68 ( V_321 + V_49 , V_344 -> V_4 , & V_240 ) )
goto V_371;
F_105 (t, &thread_list) {
struct V_316 * V_180 =
F_106 ( V_317 , struct V_316 , V_362 ) ;
for ( V_49 = 0 ; V_49 < V_180 -> V_319 ; V_49 ++ )
if ( ! F_68 ( & V_180 -> V_321 [ V_49 ] , V_344 -> V_4 , & V_240 ) )
goto V_371;
}
if ( ! F_99 ( V_344 -> V_4 , V_347 - V_240 ) )
goto V_371;
if ( F_95 ( V_344 -> V_4 , & V_17 , & V_344 -> V_336 ,
V_344 -> V_220 ) < 0 )
goto V_371;
if ( ! F_113 ( V_344 -> V_4 , & V_17 , V_344 -> V_336 ) )
goto V_371;
if ( V_23 == V_364 ) {
V_17 += sizeof( * V_329 ) ;
if ( V_17 > V_344 -> V_336
|| ! F_97 ( V_344 -> V_4 , V_329 ,
sizeof( * V_329 ) ) )
goto V_371;
}
if ( V_344 -> V_4 -> V_374 != V_268 ) {
F_30 ( V_375
L_35 ,
V_344 -> V_4 -> V_374 , V_268 ) ;
}
V_371:
F_110 ( V_346 ) ;
V_354:
while ( ! F_114 ( & V_349 ) ) {
struct V_350 * V_180 = V_349 . V_360 ;
F_115 ( V_180 ) ;
F_39 ( F_106 ( V_180 , struct V_316 , V_362 ) ) ;
}
F_39 ( V_353 ) ;
F_39 ( V_246 ) ;
F_39 ( V_274 ) ;
F_39 ( V_303 ) ;
F_39 ( V_321 ) ;
F_39 ( V_324 ) ;
F_39 ( V_329 ) ;
#ifdef F_92
F_39 ( V_326 ) ;
#endif
return V_345 ;
#undef F_102
}
