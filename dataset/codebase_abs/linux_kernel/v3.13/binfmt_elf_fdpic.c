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
if ( ! V_4 -> V_11 -> V_12 )
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
static int F_12 ( struct V_37 * V_38 )
{
struct V_13 V_39 , V_40 ;
struct V_41 * V_42 = F_13 () ;
struct V_21 * V_16 ;
unsigned long V_35 , V_43 ;
#ifdef F_14
unsigned long V_44 ;
#endif
#ifndef F_15
unsigned long V_45 ;
#endif
struct V_4 * V_46 = NULL ;
char * V_47 = NULL ;
int V_48 ;
int V_18 , V_49 ;
F_16 ( L_1 , V_50 -> V_51 ) ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_39 . V_3 = * (struct V_2 * ) V_38 -> V_52 ;
V_39 . V_32 = V_53 | V_54 ;
V_18 = - V_27 ;
if ( ! F_5 ( & V_39 . V_3 , V_38 -> V_4 ) )
goto error;
V_18 = F_8 ( & V_39 , V_38 -> V_4 ) ;
if ( V_18 < 0 )
goto error;
V_16 = V_39 . V_24 ;
for ( V_49 = 0 ; V_49 < V_39 . V_3 . V_23 ; V_49 ++ , V_16 ++ ) {
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
F_16 ( L_2 , V_47 ) ;
V_46 = F_17 ( V_47 ) ;
V_18 = F_18 ( V_46 ) ;
if ( F_19 ( V_46 ) ) {
V_46 = NULL ;
goto error;
}
F_20 ( V_38 , V_46 ) ;
V_18 = F_10 ( V_46 , 0 , V_38 -> V_52 ,
V_60 ) ;
if ( F_11 ( V_18 != V_60 ) ) {
if ( V_18 >= 0 )
V_18 = - V_27 ;
goto error;
}
V_40 . V_3 = * ( (struct V_2 * ) V_38 -> V_52 ) ;
break;
case V_61 :
#ifdef F_15
if ( V_39 . V_62 == 0 )
V_39 . V_62 = V_16 -> V_63 ;
#endif
break;
}
}
if ( F_21 ( & V_39 . V_3 ) )
V_39 . V_32 |= V_64 ;
if ( V_47 ) {
V_18 = - V_65 ;
if ( ! F_5 ( & V_40 . V_3 , V_46 ) )
goto error;
V_40 . V_32 = V_53 ;
V_18 = F_8 ( & V_40 , V_46 ) ;
if ( V_18 < 0 )
goto error;
}
V_35 = V_39 . V_35 ;
if ( V_39 . V_32 & V_33 )
V_48 = V_66 ;
else if ( V_39 . V_32 & V_34 )
V_48 = V_67 ;
else
V_48 = V_68 ;
if ( V_35 == 0 ) {
V_35 = V_40 . V_35 ;
if ( V_40 . V_32 & V_33 )
V_48 = V_66 ;
else if ( V_40 . V_32 & V_34 )
V_48 = V_67 ;
else
V_48 = V_68 ;
}
V_18 = - V_27 ;
if ( V_35 == 0 )
goto error;
if ( F_21 ( & V_40 . V_3 ) )
V_40 . V_32 |= V_64 ;
V_18 = F_22 ( V_38 ) ;
if ( V_18 )
goto error;
F_23 ( V_69 ) ;
if ( F_24 ( & V_39 . V_3 , V_48 ) )
V_50 -> V_70 |= V_71 ;
F_25 ( V_38 ) ;
F_26 ( & V_1 ) ;
V_50 -> V_72 -> V_73 = 0 ;
V_50 -> V_72 -> V_74 = 0 ;
V_50 -> V_72 -> V_75 = 0 ;
V_50 -> V_72 -> V_76 = 0 ;
V_50 -> V_72 -> V_77 = 0 ;
V_50 -> V_72 -> V_78 . V_79 = 0 ;
V_50 -> V_72 -> V_78 . V_80 = 0 ;
#ifdef F_15
F_27 ( & V_39 ,
& V_40 ,
& V_50 -> V_72 -> V_75 ,
& V_50 -> V_72 -> V_81 ) ;
V_18 = F_28 ( V_38 , V_50 -> V_72 -> V_75 ,
V_48 ) ;
if ( V_18 < 0 ) {
F_29 ( V_82 , V_50 , 0 ) ;
goto V_83;
}
#endif
V_18 = F_30 ( & V_39 , V_38 -> V_4 , V_50 -> V_72 ,
L_3 ) ;
if ( V_18 < 0 )
goto V_83;
if ( V_47 ) {
V_18 = F_30 ( & V_40 , V_46 ,
V_50 -> V_72 , L_4 ) ;
if ( V_18 < 0 ) {
F_31 ( V_84 L_5 ) ;
goto V_83;
}
F_32 ( V_46 ) ;
F_33 ( V_46 ) ;
V_46 = NULL ;
}
#ifdef F_15
if ( ! V_50 -> V_72 -> V_81 )
V_50 -> V_72 -> V_81 = V_50 -> V_72 -> V_77 ;
V_50 -> V_72 -> V_85 = V_50 -> V_72 -> V_81 =
F_34 ( V_50 -> V_72 -> V_81 ) ;
#else
V_35 = ( V_35 + V_86 - 1 ) & V_87 ;
if ( V_35 < V_86 * 2 )
V_35 = V_86 * 2 ;
V_45 = V_88 | V_89 ;
if ( V_48 == V_66 ||
( V_48 == V_68 && V_90 & V_91 ) )
V_45 |= V_92 ;
V_50 -> V_72 -> V_81 = F_35 ( NULL , 0 , V_35 , V_45 ,
V_93 | V_94 |
V_95 | V_96 ,
0 ) ;
if ( F_36 ( V_50 -> V_72 -> V_81 ) ) {
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
F_37 ( V_38 ) ;
if ( F_38 ( V_38 , V_50 -> V_72 ,
& V_39 , & V_40 ) < 0 )
goto V_83;
F_16 ( L_6 , V_50 -> V_72 -> V_73 ) ;
F_16 ( L_7 , V_50 -> V_72 -> V_74 ) ;
F_16 ( L_8 , V_50 -> V_72 -> V_76 ) ;
F_16 ( L_9 , V_50 -> V_72 -> V_77 ) ;
F_16 ( L_10 , V_50 -> V_72 -> V_81 ) ;
F_16 ( L_11 , V_50 -> V_72 -> V_85 ) ;
F_16 ( L_12 , V_50 -> V_72 -> V_75 ) ;
#ifdef F_14
V_44 = V_40 . V_98 ? : V_39 . V_98 ;
F_14 ( V_42 , V_39 . V_99 , V_40 . V_99 ,
V_44 ) ;
#endif
V_43 = V_40 . V_100 ? : V_39 . V_100 ;
F_39 ( V_42 , V_43 , V_50 -> V_72 -> V_75 ) ;
V_18 = 0 ;
error:
if ( V_46 ) {
F_32 ( V_46 ) ;
F_33 ( V_46 ) ;
}
F_40 ( V_47 ) ;
F_40 ( V_39 . V_24 ) ;
F_40 ( V_39 . V_101 ) ;
F_40 ( V_40 . V_24 ) ;
F_40 ( V_40 . V_101 ) ;
return V_18 ;
V_83:
F_29 ( V_102 , V_50 , 0 ) ;
goto error;
}
static int F_38 ( struct V_37 * V_38 ,
struct V_103 * V_72 ,
struct V_13 * V_39 ,
struct V_13 * V_40 )
{
const struct V_104 * V_104 = F_41 () ;
unsigned long V_105 , V_106 , V_107 ;
T_3 T_4 * V_108 , * V_109 ;
T_5 V_110 = 0 , V_111 ;
char * V_112 , * V_113 ;
char T_4 * V_114 , * V_115 , * V_116 ;
int V_19 ;
int V_117 ;
#ifdef F_15
V_105 = F_42 ( V_38 -> V_116 ) ;
#else
V_105 = V_72 -> V_75 ;
if ( F_43 ( V_38 , & V_105 ) < 0 )
return - V_118 ;
#endif
V_112 = V_119 ;
V_114 = NULL ;
if ( V_112 ) {
V_110 = strlen ( V_112 ) + 1 ;
V_105 -= V_110 ;
V_114 = ( char T_4 * ) V_105 ;
if ( F_44 ( V_114 , V_112 , V_110 ) != 0 )
return - V_118 ;
}
V_113 = V_120 ;
V_115 = NULL ;
if ( V_113 ) {
V_110 = strlen ( V_113 ) + 1 ;
V_105 -= V_110 ;
V_115 = ( char T_4 * ) V_105 ;
if ( F_44 ( V_115 , V_113 , V_110 ) != 0 )
return - V_118 ;
}
V_105 &= ~ 7UL ;
V_111 = sizeof( struct V_121 ) ;
V_111 += sizeof( struct V_122 ) * V_39 -> V_101 -> V_123 ;
V_105 = ( V_105 - V_111 ) & ~ 7UL ;
V_39 -> V_99 = V_105 ;
if ( F_45 ( ( void T_4 * ) V_105 , V_39 -> V_101 , V_111 ) != 0 )
return - V_118 ;
V_50 -> V_72 -> V_78 . V_79 = ( unsigned long ) V_105 ;
if ( V_40 -> V_101 ) {
V_111 = sizeof( struct V_121 ) ;
V_111 += sizeof( struct V_122 ) *
V_40 -> V_101 -> V_123 ;
V_105 = ( V_105 - V_111 ) & ~ 7UL ;
V_40 -> V_99 = V_105 ;
if ( F_45 ( ( void T_4 * ) V_105 , V_40 -> V_101 ,
V_111 ) != 0 )
return - V_118 ;
V_50 -> V_72 -> V_78 . V_80 = ( unsigned long ) V_105 ;
}
#define F_46 15
V_107 = 1 + F_46 + ( V_112 ? 1 : 0 ) +
( V_113 ? 1 : 0 ) + V_124 ;
if ( V_38 -> V_125 & V_126 )
V_107 ++ ;
V_106 = V_105 ;
V_105 -= V_107 * 2 * sizeof( unsigned long ) ;
V_105 -= ( V_38 -> V_127 + 1 ) * sizeof( char * ) ;
V_105 -= ( V_38 -> V_128 + 1 ) * sizeof( char * ) ;
V_105 -= 1 * sizeof( unsigned long ) ;
V_106 -= V_105 & 15UL ;
V_105 -= V_105 & 15UL ;
#define F_47 ( T_6 , T_7 ) \
do { \
struct { unsigned long _id, _val; } __user *ent; \
\
ent = (void __user *) csp; \
__put_user((id), &ent[nr]._id); \
__put_user((val), &ent[nr]._val); \
nr++; \
} while (0)
V_117 = 0 ;
V_106 -= 2 * sizeof( unsigned long ) ;
F_47 ( V_129 , 0 ) ;
if ( V_112 ) {
V_117 = 0 ;
V_106 -= 2 * sizeof( unsigned long ) ;
F_47 ( V_130 ,
( V_131 ) ( unsigned long ) V_114 ) ;
}
if ( V_113 ) {
V_117 = 0 ;
V_106 -= 2 * sizeof( unsigned long ) ;
F_47 ( V_132 ,
( V_131 ) ( unsigned long ) V_115 ) ;
}
if ( V_38 -> V_125 & V_126 ) {
V_117 = 0 ;
V_106 -= 2 * sizeof( unsigned long ) ;
F_47 ( V_133 , V_38 -> V_134 ) ;
}
V_117 = 0 ;
V_106 -= F_46 * 2 * sizeof( unsigned long ) ;
F_47 ( V_135 , V_136 ) ;
#ifdef F_48
F_47 ( V_137 , F_48 ) ;
#endif
F_47 ( V_138 , V_86 ) ;
F_47 ( V_139 , V_140 ) ;
F_47 ( V_141 , V_39 -> V_142 ) ;
F_47 ( V_143 , sizeof( struct V_21 ) ) ;
F_47 ( V_144 , V_39 -> V_3 . V_23 ) ;
F_47 ( V_145 , V_40 -> V_146 ) ;
F_47 ( V_147 , 0 ) ;
F_47 ( V_148 , V_39 -> V_100 ) ;
F_47 ( V_149 , ( V_131 ) F_49 ( V_104 -> V_150 , V_104 -> V_151 ) ) ;
F_47 ( V_152 , ( V_131 ) F_49 ( V_104 -> V_150 , V_104 -> V_153 ) ) ;
F_47 ( V_154 , ( V_131 ) F_50 ( V_104 -> V_150 , V_104 -> V_155 ) ) ;
F_47 ( V_156 , ( V_131 ) F_50 ( V_104 -> V_150 , V_104 -> V_157 ) ) ;
F_47 ( V_158 , F_51 ( V_38 ) ) ;
F_47 ( V_159 , V_38 -> V_160 ) ;
#ifdef F_52
V_117 = 0 ;
V_106 -= V_124 * 2 * sizeof( unsigned long ) ;
F_52 ;
#endif
#undef F_47
V_106 -= ( V_38 -> V_127 + 1 ) * sizeof( T_3 ) ;
V_109 = ( T_3 T_4 * ) V_106 ;
V_106 -= ( V_38 -> V_128 + 1 ) * sizeof( T_3 ) ;
V_108 = ( T_3 T_4 * ) V_106 ;
V_106 -= sizeof( unsigned long ) ;
F_53 ( V_38 -> V_128 , ( unsigned long T_4 * ) V_106 ) ;
F_54 ( V_106 != V_105 ) ;
#ifdef F_15
V_50 -> V_72 -> V_161 = V_38 -> V_116 ;
#else
V_50 -> V_72 -> V_161 = V_50 -> V_72 -> V_75 -
( V_162 * V_86 - V_38 -> V_116 ) ;
#endif
V_116 = ( char T_4 * ) V_50 -> V_72 -> V_161 ;
for ( V_19 = V_38 -> V_128 ; V_19 > 0 ; V_19 -- ) {
F_53 ( ( T_3 ) V_116 , V_108 ++ ) ;
V_111 = F_55 ( V_116 , V_163 ) ;
if ( ! V_111 || V_111 > V_163 )
return - V_164 ;
V_116 += V_111 ;
}
F_53 ( NULL , V_108 ) ;
V_50 -> V_72 -> V_165 = ( unsigned long ) V_116 ;
V_50 -> V_72 -> V_166 = ( unsigned long ) V_116 ;
for ( V_19 = V_38 -> V_127 ; V_19 > 0 ; V_19 -- ) {
F_53 ( ( T_3 ) ( unsigned long ) V_116 , V_109 ++ ) ;
V_111 = F_55 ( V_116 , V_163 ) ;
if ( ! V_111 || V_111 > V_163 )
return - V_164 ;
V_116 += V_111 ;
}
F_53 ( NULL , V_109 ) ;
V_50 -> V_72 -> V_167 = ( unsigned long ) V_116 ;
V_72 -> V_75 = ( unsigned long ) V_105 ;
return 0 ;
}
static int F_43 ( struct V_37 * V_38 ,
unsigned long * V_168 )
{
unsigned long V_169 , V_170 , V_105 ;
char * V_171 ;
int V_172 = 0 ;
V_170 = V_38 -> V_116 >> V_173 ;
V_105 = * V_168 ;
for ( V_169 = V_162 - 1 ; V_169 >= V_170 ; V_169 -- ) {
V_171 = F_56 ( V_38 -> V_174 [ V_169 ] ) ;
V_105 -= V_86 ;
if ( F_45 ( ( void * ) V_105 , V_171 , V_86 ) != 0 )
V_172 = - V_118 ;
F_57 ( V_38 -> V_174 [ V_169 ] ) ;
if ( V_172 < 0 )
goto V_175;
}
* V_168 = ( * V_168 - ( V_162 * V_86 - V_38 -> V_116 ) ) & ~ 15 ;
V_175:
return V_172 ;
}
static int F_30 ( struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_103 * V_72 ,
const char * V_176 )
{
struct V_121 * V_101 ;
#ifdef F_15
struct V_122 * V_177 ;
#endif
struct V_122 * V_178 ;
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
V_101 = F_58 ( V_17 , V_25 ) ;
if ( ! V_101 )
return - V_22 ;
V_14 -> V_101 = V_101 ;
V_101 -> V_181 = V_182 ;
V_101 -> V_123 = V_179 ;
V_62 = V_14 -> V_62 ;
V_178 = V_101 -> V_183 ;
switch ( V_14 -> V_32 & V_184 ) {
case V_64 :
case V_185 :
#ifndef F_15
V_172 = F_59 ( V_14 , V_4 , V_72 ) ;
if ( V_172 < 0 )
return V_172 ;
break;
#endif
default:
V_172 = F_60 ( V_14 , V_4 , V_72 ) ;
if ( V_172 < 0 )
return V_172 ;
break;
}
if ( V_14 -> V_3 . V_186 ) {
V_178 = V_101 -> V_183 ;
for ( V_19 = V_101 -> V_123 ; V_19 > 0 ; V_19 -- , V_178 ++ ) {
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
for ( V_19 = V_101 -> V_123 ; V_19 > 0 ; V_19 -- , V_178 ++ ) {
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
for ( V_19 = V_101 -> V_123 ; V_19 > 0 ; V_19 -- , V_178 ++ ) {
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
#ifdef F_15
V_179 = V_101 -> V_123 ;
V_177 = V_101 -> V_183 ;
V_178 = V_177 + 1 ;
for ( V_19 = 1 ; V_19 < V_179 ; V_19 ++ ) {
if ( V_178 -> V_63 - V_177 -> V_63 == V_178 -> V_187 - V_177 -> V_187 ) {
V_62 = F_34 ( V_177 -> V_187 + V_177 -> V_36 ) ;
if ( V_62 == ( V_178 -> V_187 & V_87 ) ) {
V_177 -> V_36 +=
V_62 -
( V_177 -> V_187 + V_177 -> V_36 ) ;
V_177 -> V_36 += V_178 -> V_187 & ~ V_87 ;
V_177 -> V_36 += V_178 -> V_36 ;
V_101 -> V_123 -- ;
continue;
}
}
V_177 ++ ;
if ( V_177 != V_178 )
* V_177 = * V_178 ;
}
#endif
F_16 ( L_13 , V_176 ) ;
F_16 ( L_14 , V_14 -> V_146 ) ;
F_16 ( L_15 , V_14 -> V_100 ) ;
F_16 ( L_16 , V_14 -> V_142 ) ;
F_16 ( L_17 , V_14 -> V_98 ) ;
V_178 = V_101 -> V_183 ;
for ( V_19 = 0 ; V_19 < V_101 -> V_123 ; V_19 ++ , V_178 ++ )
F_16 ( L_18 ,
V_19 ,
V_178 -> V_187 , V_178 -> V_187 + V_178 -> V_36 - 1 ,
V_178 -> V_63 , V_178 -> V_36 ) ;
return 0 ;
V_190:
F_31 ( L_19 ,
V_176 , F_61 ( V_4 ) -> V_192 ) ;
return - V_65 ;
}
static int F_59 (
struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_103 * V_72 )
{
struct V_122 * V_178 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_193 = V_194 , V_195 = 0 , V_196 = 0 , V_197 ;
int V_19 , V_172 ;
V_62 = V_14 -> V_62 ;
V_178 = V_14 -> V_101 -> V_183 ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_14 -> V_24 [ V_19 ] . V_28 != V_61 )
continue;
if ( V_193 > V_16 -> V_63 )
V_193 = V_16 -> V_63 ;
if ( V_195 < V_16 -> V_63 + V_16 -> V_36 )
V_195 = V_16 -> V_63 + V_16 -> V_36 ;
}
V_197 = V_93 ;
if ( V_14 -> V_32 & V_54 )
V_197 |= V_198 ;
V_196 = F_35 ( NULL , V_62 , V_195 - V_193 ,
V_88 | V_89 | V_92 , V_197 , 0 ) ;
if ( F_36 ( V_196 ) )
return ( int ) V_196 ;
if ( V_62 != 0 )
V_62 += F_34 ( V_195 - V_193 ) ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_14 -> V_24 [ V_19 ] . V_28 != V_61 )
continue;
V_178 -> V_187 = V_196 + ( V_16 -> V_63 - V_193 ) ;
V_178 -> V_63 = V_16 -> V_63 ;
V_178 -> V_36 = V_16 -> V_36 ;
V_172 = F_62 ( V_4 , V_178 -> V_187 , V_16 -> V_59 ,
V_16 -> V_56 ) ;
if ( V_172 < 0 )
return V_172 ;
if ( V_16 -> V_59 == 0 )
V_14 -> V_146 = V_178 -> V_187 ;
if ( V_16 -> V_56 < V_16 -> V_36 ) {
if ( F_63 ( ( void * ) ( V_178 -> V_187 + V_16 -> V_56 ) ,
V_16 -> V_36 - V_16 -> V_56 ) )
return - V_118 ;
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
static int F_60 ( struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_103 * V_72 )
{
struct V_122 * V_178 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_199 ;
int V_19 , V_200 ;
V_62 = V_14 -> V_62 ;
V_199 = 0 ;
V_200 = 0 ;
V_178 = V_14 -> V_101 -> V_183 ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
unsigned long V_196 , V_201 , V_202 , V_203 ;
int V_204 = 0 , V_32 ;
if ( V_16 -> V_28 != V_61 )
continue;
F_16 ( L_20 ,
( unsigned long ) V_16 -> V_63 ,
( unsigned long ) V_16 -> V_59 ,
( unsigned long ) V_16 -> V_56 ,
( unsigned long ) V_16 -> V_36 ) ;
if ( V_16 -> V_30 & V_205 ) V_204 |= V_88 ;
if ( V_16 -> V_30 & V_206 ) V_204 |= V_89 ;
if ( V_16 -> V_30 & V_31 ) V_204 |= V_92 ;
V_32 = V_93 | V_207 ;
if ( V_14 -> V_32 & V_54 )
V_32 |= V_198 ;
V_196 = 0 ;
switch ( V_14 -> V_32 & V_184 ) {
case V_208 :
break;
case V_209 :
V_196 = V_16 -> V_63 ;
V_32 |= V_210 ;
break;
case V_64 :
if ( ! V_200 ) {
V_196 = V_62 ;
V_199 = V_16 -> V_63 ;
V_200 = 1 ;
} else {
V_196 = V_62 + V_16 -> V_63 - V_199 ;
V_32 |= V_210 ;
}
break;
case V_185 :
break;
default:
F_64 () ;
}
V_196 &= V_87 ;
V_201 = V_16 -> V_63 & ~ V_87 ;
V_196 = F_35 ( V_4 , V_196 , V_16 -> V_36 + V_201 , V_204 , V_32 ,
V_16 -> V_59 - V_201 ) ;
F_16 ( L_21 ,
V_19 , V_16 -> V_36 + V_201 , V_204 , V_32 ,
V_16 -> V_59 - V_201 , V_196 ) ;
if ( F_36 ( V_196 ) )
return ( int ) V_196 ;
if ( ( V_14 -> V_32 & V_184 ) ==
V_185 )
V_62 += F_34 ( V_16 -> V_36 + V_201 ) ;
V_178 -> V_187 = V_196 + V_201 ;
V_178 -> V_63 = V_16 -> V_63 ;
V_178 -> V_36 = V_16 -> V_36 ;
if ( V_16 -> V_59 == 0 )
V_14 -> V_146 = V_178 -> V_187 ;
if ( V_204 & V_89 && V_201 > 0 ) {
F_16 ( L_22 , V_19 , V_196 , V_201 ) ;
if ( F_63 ( ( void T_4 * ) V_196 , V_201 ) )
return - V_118 ;
V_196 += V_201 ;
}
V_202 = V_16 -> V_36 - V_16 -> V_56 ;
V_203 = V_86 - ( ( V_196 + V_16 -> V_56 ) & ~ V_87 ) ;
#ifdef F_15
if ( V_202 > V_203 ) {
unsigned long V_211 = V_196 + V_16 -> V_56 + V_203 ;
unsigned long V_212 ;
V_32 |= V_210 | V_94 ;
V_212 = F_35 ( NULL , V_211 , V_202 - V_203 ,
V_204 , V_32 , 0 ) ;
F_16 ( L_23
L_24 ,
V_19 , V_211 , V_202 - V_203 , V_204 , V_32 ,
V_212 ) ;
if ( V_212 != V_211 )
return - V_22 ;
}
if ( V_204 & V_89 && V_203 > 0 ) {
F_16 ( L_22 ,
V_19 , V_196 + V_16 -> V_56 , V_203 ) ;
if ( F_63 ( ( void T_4 * ) V_196 + V_16 -> V_56 ,
V_203 ) )
return - V_118 ;
}
#else
if ( V_202 > 0 ) {
F_16 ( L_22 ,
V_19 , V_196 + V_16 -> V_56 , V_202 ) ;
if ( F_63 ( ( void * ) V_196 + V_16 -> V_56 , V_202 ) )
return - V_118 ;
}
#endif
if ( V_72 ) {
if ( V_16 -> V_30 & V_31 ) {
if ( ! V_72 -> V_73 ) {
V_72 -> V_73 = V_196 ;
V_72 -> V_74 = V_196 + V_16 -> V_36 ;
}
} else if ( ! V_72 -> V_76 ) {
V_72 -> V_76 = V_196 ;
V_72 -> V_77 = V_196 + V_16 -> V_36 ;
}
}
V_178 ++ ;
}
return 0 ;
}
static int F_65 ( struct V_213 * V_214 , unsigned long V_215 )
{
int V_216 ;
if ( V_214 -> V_217 & V_218 ) {
F_66 ( L_25 , V_214 -> V_219 , V_214 -> V_217 ) ;
return 0 ;
}
if ( ! ( V_214 -> V_217 & V_220 ) ) {
F_66 ( L_26 , V_214 -> V_219 , V_214 -> V_217 ) ;
return 0 ;
}
if ( V_214 -> V_217 & V_221 ) {
if ( F_61 ( V_214 -> V_222 ) -> V_223 == 0 ) {
V_216 = F_67 ( V_224 , & V_215 ) ;
F_66 ( L_27 , V_214 -> V_219 ,
V_214 -> V_217 , V_216 ? L_28 : L_29 ) ;
return V_216 ;
}
V_216 = F_67 ( V_225 , & V_215 ) ;
F_66 ( L_27 , V_214 -> V_219 ,
V_214 -> V_217 , V_216 ? L_28 : L_29 ) ;
return V_216 ;
}
#ifdef F_15
if ( ! V_214 -> V_226 ) {
V_216 = F_67 ( V_227 , & V_215 ) ;
F_66 ( L_30 , V_214 -> V_219 ,
V_214 -> V_217 , V_216 ? L_28 : L_29 ) ;
return V_216 ;
}
#endif
V_216 = F_67 ( V_228 , & V_215 ) ;
F_66 ( L_31 , V_214 -> V_219 , V_214 -> V_217 ,
V_216 ? L_28 : L_29 ) ;
return V_216 ;
}
static int F_68 ( struct V_229 * V_230 )
{
int V_231 ;
V_231 = sizeof( struct V_232 ) ;
V_231 += F_69 ( strlen ( V_230 -> V_233 ) + 1 , 4 ) ;
V_231 += F_69 ( V_230 -> V_234 , 4 ) ;
return V_231 ;
}
static int F_70 ( struct V_229 * V_235 , struct V_236 * V_237 )
{
struct V_232 V_230 ;
V_230 . V_238 = strlen ( V_235 -> V_233 ) + 1 ;
V_230 . V_239 = V_235 -> V_234 ;
V_230 . V_240 = V_235 -> type ;
return F_71 ( V_237 , & V_230 , sizeof( V_230 ) ) &&
F_71 ( V_237 , V_235 -> V_233 , V_230 . V_238 ) && F_72 ( V_237 , 4 ) &&
F_71 ( V_237 , V_235 -> V_241 , V_235 -> V_234 ) && F_72 ( V_237 , 4 ) ;
}
static inline void F_73 ( struct V_2 * V_242 , int V_183 )
{
memcpy ( V_242 -> V_5 , V_6 , V_7 ) ;
V_242 -> V_5 [ V_243 ] = V_244 ;
V_242 -> V_5 [ V_245 ] = V_246 ;
V_242 -> V_5 [ V_247 ] = V_248 ;
V_242 -> V_5 [ V_249 ] = V_250 ;
memset ( V_242 -> V_5 + V_251 , 0 , V_252 - V_251 ) ;
V_242 -> V_8 = V_253 ;
V_242 -> V_254 = V_255 ;
V_242 -> V_256 = V_248 ;
V_242 -> V_186 = 0 ;
V_242 -> V_26 = sizeof( struct V_2 ) ;
V_242 -> V_257 = 0 ;
V_242 -> V_258 = V_259 ;
V_242 -> V_260 = sizeof( struct V_2 ) ;
V_242 -> V_20 = sizeof( struct V_21 ) ;
V_242 -> V_23 = V_183 ;
V_242 -> V_261 = 0 ;
V_242 -> V_262 = 0 ;
V_242 -> V_263 = 0 ;
return;
}
static inline void F_74 ( struct V_21 * V_16 , int V_231 , T_8 V_264 )
{
V_16 -> V_28 = V_265 ;
V_16 -> V_59 = V_264 ;
V_16 -> V_63 = 0 ;
V_16 -> V_266 = 0 ;
V_16 -> V_56 = V_231 ;
V_16 -> V_36 = 0 ;
V_16 -> V_30 = 0 ;
V_16 -> V_267 = 0 ;
return;
}
static inline void F_75 ( struct V_229 * V_268 , const char * V_233 , int type ,
unsigned int V_231 , void * V_241 )
{
V_268 -> V_233 = V_233 ;
V_268 -> type = type ;
V_268 -> V_234 = V_231 ;
V_268 -> V_241 = V_241 ;
return;
}
static void F_76 ( struct V_269 * V_270 ,
struct V_271 * V_116 , long V_272 )
{
V_270 -> V_273 . V_274 = V_270 -> V_275 = V_272 ;
V_270 -> V_276 = V_116 -> V_277 . signal . V_278 [ 0 ] ;
V_270 -> V_279 = V_116 -> V_280 . V_278 [ 0 ] ;
F_77 () ;
V_270 -> V_281 = F_78 ( F_79 ( V_116 -> V_282 ) ) ;
F_80 () ;
V_270 -> V_283 = F_78 ( V_116 ) ;
V_270 -> V_284 = F_81 ( V_116 ) ;
V_270 -> V_285 = F_82 ( V_116 ) ;
if ( F_83 ( V_116 ) ) {
struct V_286 V_287 ;
F_84 ( V_116 , & V_287 ) ;
F_85 ( V_287 . V_288 , & V_270 -> V_289 ) ;
F_85 ( V_287 . V_290 , & V_270 -> V_291 ) ;
} else {
T_9 V_288 , V_290 ;
V_286 ( V_116 , & V_288 , & V_290 ) ;
F_85 ( V_288 , & V_270 -> V_289 ) ;
F_85 ( V_290 , & V_270 -> V_291 ) ;
}
F_85 ( V_116 -> signal -> V_292 , & V_270 -> V_293 ) ;
F_85 ( V_116 -> signal -> V_294 , & V_270 -> V_295 ) ;
V_270 -> V_296 = V_116 -> V_72 -> V_78 . V_79 ;
V_270 -> V_297 = V_116 -> V_72 -> V_78 . V_80 ;
}
static int F_86 ( struct V_298 * V_299 , struct V_271 * V_116 ,
struct V_103 * V_72 )
{
const struct V_104 * V_104 ;
unsigned int V_49 , V_111 ;
memset ( V_299 , 0 , sizeof( struct V_298 ) ) ;
V_111 = V_72 -> V_165 - V_72 -> V_161 ;
if ( V_111 >= V_300 )
V_111 = V_300 - 1 ;
if ( F_87 ( & V_299 -> V_301 ,
( const char T_4 * ) V_72 -> V_161 , V_111 ) )
return - V_118 ;
for ( V_49 = 0 ; V_49 < V_111 ; V_49 ++ )
if ( V_299 -> V_301 [ V_49 ] == 0 )
V_299 -> V_301 [ V_49 ] = ' ' ;
V_299 -> V_301 [ V_111 ] = 0 ;
F_77 () ;
V_299 -> V_281 = F_78 ( F_79 ( V_116 -> V_282 ) ) ;
F_80 () ;
V_299 -> V_283 = F_78 ( V_116 ) ;
V_299 -> V_284 = F_81 ( V_116 ) ;
V_299 -> V_285 = F_82 ( V_116 ) ;
V_49 = V_116 -> V_302 ? F_88 ( ~ V_116 -> V_302 ) + 1 : 0 ;
V_299 -> V_303 = V_49 ;
V_299 -> V_304 = ( V_49 > 5 ) ? '.' : L_32 [ V_49 ] ;
V_299 -> V_305 = V_299 -> V_304 == 'Z' ;
V_299 -> V_306 = F_89 ( V_116 ) ;
V_299 -> V_307 = V_116 -> V_32 ;
F_77 () ;
V_104 = F_90 ( V_116 ) ;
F_91 ( V_299 -> V_308 , F_49 ( V_104 -> V_150 , V_104 -> V_151 ) ) ;
F_92 ( V_299 -> V_309 , F_50 ( V_104 -> V_150 , V_104 -> V_155 ) ) ;
F_80 () ;
strncpy ( V_299 -> V_310 , V_116 -> V_311 , sizeof( V_299 -> V_310 ) ) ;
return 0 ;
}
static int F_93 ( long V_272 , struct V_312 * V_313 )
{
struct V_271 * V_116 = V_313 -> V_314 ;
int V_231 = 0 ;
V_313 -> V_315 = 0 ;
F_76 ( & V_313 -> V_270 , V_116 , V_272 ) ;
F_94 ( V_116 , & V_313 -> V_270 . V_316 ) ;
F_75 ( & V_313 -> V_317 [ 0 ] , L_33 , V_318 , sizeof( V_313 -> V_270 ) ,
& V_313 -> V_270 ) ;
V_313 -> V_315 ++ ;
V_231 += F_68 ( & V_313 -> V_317 [ 0 ] ) ;
V_313 -> V_270 . V_319 = F_95 ( V_116 , NULL , & V_313 -> V_320 ) ;
if ( V_313 -> V_270 . V_319 ) {
F_75 ( & V_313 -> V_317 [ 1 ] , L_33 , V_321 , sizeof( V_313 -> V_320 ) ,
& V_313 -> V_320 ) ;
V_313 -> V_315 ++ ;
V_231 += F_68 ( & V_313 -> V_317 [ 1 ] ) ;
}
#ifdef F_96
if ( F_97 ( V_116 , & V_313 -> V_322 ) ) {
F_75 ( & V_313 -> V_317 [ 2 ] , L_34 , V_323 ,
sizeof( V_313 -> V_322 ) , & V_313 -> V_322 ) ;
V_313 -> V_315 ++ ;
V_231 += F_68 ( & V_313 -> V_317 [ 2 ] ) ;
}
#endif
return V_231 ;
}
static void F_98 ( struct V_2 * V_242 , struct V_324 * V_325 ,
V_131 V_257 , int V_183 )
{
V_242 -> V_257 = V_257 ;
V_242 -> V_261 = sizeof( * V_325 ) ;
V_242 -> V_262 = 1 ;
V_242 -> V_263 = V_326 ;
memset ( V_325 , 0 , sizeof( * V_325 ) ) ;
V_325 -> V_327 = V_328 ;
V_325 -> V_329 = V_242 -> V_262 ;
V_325 -> V_330 = V_242 -> V_263 ;
V_325 -> V_331 = V_183 ;
}
static bool F_99 ( struct V_236 * V_237 )
{
struct V_213 * V_214 ;
for ( V_214 = V_50 -> V_72 -> V_12 ; V_214 ; V_214 = V_214 -> V_332 ) {
unsigned long V_187 ;
if ( ! F_65 ( V_214 , V_237 -> V_215 ) )
continue;
#ifdef F_15
for ( V_187 = V_214 -> V_219 ; V_187 < V_214 -> V_333 ;
V_187 += V_86 ) {
bool V_334 ;
struct V_174 * V_174 = F_100 ( V_187 ) ;
if ( V_174 ) {
void * V_335 = F_56 ( V_174 ) ;
V_334 = F_71 ( V_237 , V_335 , V_86 ) ;
F_57 ( V_174 ) ;
F_101 ( V_174 ) ;
} else {
V_334 = F_102 ( V_237 , V_86 ) ;
}
if ( ! V_334 )
return false ;
}
#else
if ( ! F_71 ( V_237 , ( void * ) V_214 -> V_219 ,
V_214 -> V_333 - V_214 -> V_219 ) )
return false ;
#endif
}
return true ;
}
static T_5 F_103 ( unsigned long V_215 )
{
struct V_213 * V_214 ;
T_5 V_17 = 0 ;
for ( V_214 = V_50 -> V_72 -> V_12 ; V_214 ; V_214 = V_214 -> V_332 )
if ( F_65 ( V_214 , V_215 ) )
V_17 += V_214 -> V_333 - V_214 -> V_219 ;
return V_17 ;
}
static int F_104 ( struct V_236 * V_237 )
{
#define F_105 6
int V_336 = 0 ;
T_10 V_337 ;
int V_183 ;
int V_49 ;
struct V_213 * V_214 ;
struct V_2 * V_242 = NULL ;
T_8 V_264 = 0 , V_338 ;
int V_339 ;
struct V_229 * V_317 = NULL ;
struct V_269 * V_270 = NULL ;
struct V_298 * V_299 = NULL ;
F_106 ( V_340 ) ;
struct V_341 * V_313 ;
T_11 * V_320 = NULL ;
#ifdef F_96
T_12 * V_322 = NULL ;
#endif
int V_342 = 0 ;
V_131 * V_343 ;
struct V_21 * V_344 = NULL ;
struct V_324 * V_325 = NULL ;
T_13 V_23 ;
V_131 V_257 ;
struct V_345 * V_346 ;
struct V_312 * V_180 ;
V_242 = F_9 ( sizeof( * V_242 ) , V_25 ) ;
if ( ! V_242 )
goto V_347;
V_270 = F_58 ( sizeof( * V_270 ) , V_25 ) ;
if ( ! V_270 )
goto V_347;
V_299 = F_9 ( sizeof( * V_299 ) , V_25 ) ;
if ( ! V_299 )
goto V_347;
V_317 = F_9 ( F_105 * sizeof( struct V_229 ) , V_25 ) ;
if ( ! V_317 )
goto V_347;
V_320 = F_9 ( sizeof( * V_320 ) , V_25 ) ;
if ( ! V_320 )
goto V_347;
#ifdef F_96
V_322 = F_9 ( sizeof( * V_322 ) , V_25 ) ;
if ( ! V_322 )
goto V_347;
#endif
for ( V_346 = V_50 -> V_72 -> V_348 -> V_349 . V_350 ;
V_346 ; V_346 = V_346 -> V_350 ) {
V_180 = F_58 ( sizeof( * V_180 ) , V_25 ) ;
if ( ! V_180 )
goto V_347;
V_180 -> V_314 = V_346 -> V_351 ;
F_107 ( & V_180 -> V_352 , & V_340 ) ;
}
F_108 (t, &thread_list) {
struct V_312 * V_180 ;
int V_231 ;
V_180 = F_109 ( V_313 , struct V_312 , V_352 ) ;
V_231 = F_93 ( V_237 -> V_353 -> V_274 , V_180 ) ;
V_342 += V_231 ;
}
F_76 ( V_270 , V_50 , V_237 -> V_353 -> V_274 ) ;
F_110 ( & V_270 -> V_316 , V_237 -> V_42 ) ;
V_183 = V_50 -> V_72 -> V_354 ;
V_183 += F_111 () ;
V_183 ++ ;
V_23 = V_183 > V_355 ? V_355 : V_183 ;
F_73 ( V_242 , V_23 ) ;
V_336 = 1 ;
F_75 ( V_317 + 0 , L_33 , V_318 , sizeof( * V_270 ) , V_270 ) ;
F_86 ( V_299 , V_50 -> V_356 , V_50 -> V_72 ) ;
F_75 ( V_317 + 1 , L_33 , V_357 , sizeof( * V_299 ) , V_299 ) ;
V_339 = 2 ;
V_343 = ( V_131 * ) V_50 -> V_72 -> V_358 ;
V_49 = 0 ;
do
V_49 += 2 ;
while ( V_343 [ V_49 - 2 ] != V_129 );
F_75 ( & V_317 [ V_339 ++ ] , L_33 , V_359 ,
V_49 * sizeof( V_131 ) , V_343 ) ;
if ( ( V_270 -> V_319 =
F_95 ( V_50 , V_237 -> V_42 , V_320 ) ) )
F_75 ( V_317 + V_339 ++ ,
L_33 , V_321 , sizeof( * V_320 ) , V_320 ) ;
#ifdef F_96
if ( F_97 ( V_50 , V_322 ) )
F_75 ( V_317 + V_339 ++ ,
L_34 , V_323 , sizeof( * V_322 ) , V_322 ) ;
#endif
V_337 = F_112 () ;
F_113 ( V_360 ) ;
V_264 += sizeof( * V_242 ) ;
V_264 += V_183 * sizeof( struct V_21 ) ;
{
int V_231 = 0 ;
for ( V_49 = 0 ; V_49 < V_339 ; V_49 ++ )
V_231 += F_68 ( V_317 + V_49 ) ;
V_231 += V_342 ;
V_344 = F_9 ( sizeof( * V_344 ) , V_25 ) ;
if ( ! V_344 )
goto V_361;
F_74 ( V_344 , V_231 , V_264 ) ;
V_264 += V_231 ;
}
V_338 = V_264 = F_69 ( V_264 , V_362 ) ;
V_264 += F_103 ( V_237 -> V_215 ) ;
V_264 += F_114 () ;
V_257 = V_264 ;
if ( V_23 == V_355 ) {
V_325 = F_9 ( sizeof( * V_325 ) , V_25 ) ;
if ( ! V_325 )
goto V_361;
F_98 ( V_242 , V_325 , V_257 , V_183 ) ;
}
V_264 = V_338 ;
if ( ! F_71 ( V_237 , V_242 , sizeof( * V_242 ) ) )
goto V_361;
if ( ! F_71 ( V_237 , V_344 , sizeof( * V_344 ) ) )
goto V_361;
for ( V_214 = V_50 -> V_72 -> V_12 ; V_214 ; V_214 = V_214 -> V_332 ) {
struct V_21 V_16 ;
T_5 V_231 ;
V_231 = V_214 -> V_333 - V_214 -> V_219 ;
V_16 . V_28 = V_61 ;
V_16 . V_59 = V_264 ;
V_16 . V_63 = V_214 -> V_219 ;
V_16 . V_266 = 0 ;
V_16 . V_56 = F_65 ( V_214 , V_237 -> V_215 ) ? V_231 : 0 ;
V_16 . V_36 = V_231 ;
V_264 += V_16 . V_56 ;
V_16 . V_30 = V_214 -> V_217 & V_220 ? V_205 : 0 ;
if ( V_214 -> V_217 & V_363 )
V_16 . V_30 |= V_206 ;
if ( V_214 -> V_217 & V_91 )
V_16 . V_30 |= V_31 ;
V_16 . V_267 = V_362 ;
if ( ! F_71 ( V_237 , & V_16 , sizeof( V_16 ) ) )
goto V_361;
}
if ( ! F_115 ( V_237 , V_264 ) )
goto V_361;
for ( V_49 = 0 ; V_49 < V_339 ; V_49 ++ )
if ( ! F_70 ( V_317 + V_49 , V_237 ) )
goto V_361;
F_108 (t, &thread_list) {
struct V_312 * V_180 =
F_109 ( V_313 , struct V_312 , V_352 ) ;
for ( V_49 = 0 ; V_49 < V_180 -> V_315 ; V_49 ++ )
if ( ! F_70 ( & V_180 -> V_317 [ V_49 ] , V_237 ) )
goto V_361;
}
if ( ! F_102 ( V_237 , V_338 - V_237 -> V_364 ) )
goto V_361;
if ( ! F_99 ( V_237 ) )
goto V_361;
if ( ! F_116 ( V_237 ) )
goto V_361;
if ( V_23 == V_355 ) {
if ( ! F_71 ( V_237 , V_325 , sizeof( * V_325 ) ) )
goto V_361;
}
if ( V_237 -> V_4 -> V_365 != V_264 ) {
F_31 ( V_366
L_35 ,
V_237 -> V_4 -> V_365 , V_264 ) ;
}
V_361:
F_113 ( V_337 ) ;
V_347:
while ( ! F_117 ( & V_340 ) ) {
struct V_341 * V_180 = V_340 . V_350 ;
F_118 ( V_180 ) ;
F_40 ( F_109 ( V_180 , struct V_312 , V_352 ) ) ;
}
F_40 ( V_344 ) ;
F_40 ( V_242 ) ;
F_40 ( V_270 ) ;
F_40 ( V_299 ) ;
F_40 ( V_317 ) ;
F_40 ( V_320 ) ;
F_40 ( V_325 ) ;
#ifdef F_96
F_40 ( V_322 ) ;
#endif
return V_336 ;
#undef F_105
}
