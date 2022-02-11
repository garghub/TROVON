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
if ( ! F_6 ( V_3 ) )
return 0 ;
if ( ! V_4 -> V_11 -> V_12 )
return 0 ;
return 1 ;
}
static int F_7 ( struct V_2 * V_3 )
{
if ( ! F_8 ( V_3 ) )
return 1 ;
if ( F_9 ( V_3 ) )
return 1 ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 ,
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
V_14 -> V_24 = F_11 ( V_17 , V_25 ) ;
if ( ! V_14 -> V_24 )
return - V_22 ;
V_18 = F_12 ( V_4 , V_14 -> V_3 . V_26 ,
( char * ) V_14 -> V_24 , V_17 ) ;
if ( F_13 ( V_18 != V_17 ) )
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
static int F_14 ( struct V_37 * V_38 )
{
struct V_13 V_39 , V_40 ;
struct V_41 * V_42 = F_15 () ;
struct V_21 * V_16 ;
unsigned long V_35 , V_43 ;
#ifdef F_16
unsigned long V_44 ;
#endif
#ifndef F_17
unsigned long V_45 ;
#endif
struct V_4 * V_46 = NULL ;
char * V_47 = NULL ;
int V_48 ;
int V_18 , V_49 ;
F_18 ( L_1 , V_50 -> V_51 ) ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_39 . V_3 = * (struct V_2 * ) V_38 -> V_52 ;
V_39 . V_32 = V_53 | V_54 ;
V_18 = - V_27 ;
if ( ! F_5 ( & V_39 . V_3 , V_38 -> V_4 ) )
goto error;
if ( ! F_8 ( & V_39 . V_3 ) ) {
#ifdef F_17
goto error;
#else
if ( V_39 . V_3 . V_8 != V_10 )
goto error;
#endif
}
V_18 = F_10 ( & V_39 , V_38 -> V_4 ) ;
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
V_47 = F_11 ( V_16 -> V_56 , V_25 ) ;
if ( ! V_47 )
goto error;
V_18 = F_12 ( V_38 -> V_4 ,
V_16 -> V_59 ,
V_47 ,
V_16 -> V_56 ) ;
if ( F_13 ( V_18 != V_16 -> V_56 ) ) {
if ( V_18 >= 0 )
V_18 = - V_27 ;
goto error;
}
V_18 = - V_58 ;
if ( V_47 [ V_16 -> V_56 - 1 ] != '\0' )
goto error;
F_18 ( L_2 , V_47 ) ;
V_46 = F_19 ( V_47 ) ;
V_18 = F_20 ( V_46 ) ;
if ( F_21 ( V_46 ) ) {
V_46 = NULL ;
goto error;
}
F_22 ( V_38 , V_46 ) ;
V_18 = F_12 ( V_46 , 0 , V_38 -> V_52 ,
V_60 ) ;
if ( F_13 ( V_18 != V_60 ) ) {
if ( V_18 >= 0 )
V_18 = - V_27 ;
goto error;
}
V_40 . V_3 = * ( (struct V_2 * ) V_38 -> V_52 ) ;
break;
case V_61 :
#ifdef F_17
if ( V_39 . V_62 == 0 )
V_39 . V_62 = V_16 -> V_63 ;
#endif
break;
}
}
if ( F_7 ( & V_39 . V_3 ) )
V_39 . V_32 |= V_64 ;
if ( V_47 ) {
V_18 = - V_65 ;
if ( ! F_5 ( & V_40 . V_3 , V_46 ) )
goto error;
V_40 . V_32 = V_53 ;
V_18 = F_10 ( & V_40 , V_46 ) ;
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
V_35 = 131072UL ;
if ( F_7 ( & V_40 . V_3 ) )
V_40 . V_32 |= V_64 ;
V_18 = F_23 ( V_38 ) ;
if ( V_18 )
goto error;
if ( F_8 ( & V_39 . V_3 ) )
F_24 ( V_69 ) ;
else
F_24 ( V_70 ) ;
if ( F_25 ( & V_39 . V_3 , V_48 ) )
V_50 -> V_71 |= V_72 ;
F_26 ( V_38 ) ;
F_27 ( & V_1 ) ;
V_50 -> V_73 -> V_74 = 0 ;
V_50 -> V_73 -> V_75 = 0 ;
V_50 -> V_73 -> V_76 = 0 ;
V_50 -> V_73 -> V_77 = 0 ;
V_50 -> V_73 -> V_78 = 0 ;
V_50 -> V_73 -> V_79 . V_80 = 0 ;
V_50 -> V_73 -> V_79 . V_81 = 0 ;
#ifdef F_17
F_28 ( & V_39 ,
& V_40 ,
& V_50 -> V_73 -> V_76 ,
& V_50 -> V_73 -> V_82 ) ;
V_18 = F_29 ( V_38 , V_50 -> V_73 -> V_76 ,
V_48 ) ;
if ( V_18 < 0 )
goto error;
#endif
V_18 = F_30 ( & V_39 , V_38 -> V_4 , V_50 -> V_73 ,
L_3 ) ;
if ( V_18 < 0 )
goto error;
if ( V_47 ) {
V_18 = F_30 ( & V_40 , V_46 ,
V_50 -> V_73 , L_4 ) ;
if ( V_18 < 0 ) {
F_31 ( V_83 L_5 ) ;
goto error;
}
F_32 ( V_46 ) ;
F_33 ( V_46 ) ;
V_46 = NULL ;
}
#ifdef F_17
if ( ! V_50 -> V_73 -> V_82 )
V_50 -> V_73 -> V_82 = V_50 -> V_73 -> V_78 ;
V_50 -> V_73 -> V_84 = V_50 -> V_73 -> V_82 =
F_34 ( V_50 -> V_73 -> V_82 ) ;
#else
V_35 = ( V_35 + V_85 - 1 ) & V_86 ;
if ( V_35 < V_85 * 2 )
V_35 = V_85 * 2 ;
V_45 = V_87 | V_88 ;
if ( V_48 == V_66 ||
( V_48 == V_68 && V_89 & V_90 ) )
V_45 |= V_91 ;
V_50 -> V_73 -> V_82 = F_35 ( NULL , 0 , V_35 , V_45 ,
V_92 | V_93 |
V_94 | V_95 ,
0 ) ;
if ( F_36 ( V_50 -> V_73 -> V_82 ) ) {
V_18 = V_50 -> V_73 -> V_82 ;
V_50 -> V_73 -> V_82 = 0 ;
goto error;
}
V_50 -> V_73 -> V_84 = V_50 -> V_73 -> V_82 ;
V_50 -> V_73 -> V_79 . V_96 = V_50 -> V_73 -> V_82 ;
V_50 -> V_73 -> V_76 = V_50 -> V_73 -> V_82 + V_35 ;
#endif
F_37 ( V_38 ) ;
if ( F_38 ( V_38 , V_50 -> V_73 ,
& V_39 , & V_40 ) < 0 )
goto error;
F_18 ( L_6 , V_50 -> V_73 -> V_74 ) ;
F_18 ( L_7 , V_50 -> V_73 -> V_75 ) ;
F_18 ( L_8 , V_50 -> V_73 -> V_77 ) ;
F_18 ( L_9 , V_50 -> V_73 -> V_78 ) ;
F_18 ( L_10 , V_50 -> V_73 -> V_82 ) ;
F_18 ( L_11 , V_50 -> V_73 -> V_84 ) ;
F_18 ( L_12 , V_50 -> V_73 -> V_76 ) ;
#ifdef F_16
V_44 = V_40 . V_97 ? : V_39 . V_97 ;
F_16 ( V_42 , V_39 . V_98 , V_40 . V_98 ,
V_44 ) ;
#endif
V_43 = V_40 . V_99 ? : V_39 . V_99 ;
F_39 ( V_42 , V_43 , V_50 -> V_73 -> V_76 ) ;
V_18 = 0 ;
error:
if ( V_46 ) {
F_32 ( V_46 ) ;
F_33 ( V_46 ) ;
}
F_40 ( V_47 ) ;
F_40 ( V_39 . V_24 ) ;
F_40 ( V_39 . V_100 ) ;
F_40 ( V_40 . V_24 ) ;
F_40 ( V_40 . V_100 ) ;
return V_18 ;
}
static int F_38 ( struct V_37 * V_38 ,
struct V_101 * V_73 ,
struct V_13 * V_39 ,
struct V_13 * V_40 )
{
const struct V_102 * V_102 = F_41 () ;
unsigned long V_103 , V_104 , V_105 ;
T_3 T_4 * V_106 , * V_107 ;
T_5 V_108 = 0 , V_109 ;
char * V_110 , * V_111 ;
char T_4 * V_112 , * V_113 , * V_114 ;
int V_19 ;
int V_115 ;
#ifdef F_17
V_103 = F_42 ( V_38 -> V_114 ) ;
#else
V_103 = V_73 -> V_76 ;
if ( F_43 ( V_38 , & V_103 ) < 0 )
return - V_116 ;
#endif
V_110 = V_117 ;
V_112 = NULL ;
if ( V_110 ) {
V_108 = strlen ( V_110 ) + 1 ;
V_103 -= V_108 ;
V_112 = ( char T_4 * ) V_103 ;
if ( F_44 ( V_112 , V_110 , V_108 ) != 0 )
return - V_116 ;
}
V_111 = V_118 ;
V_113 = NULL ;
if ( V_111 ) {
V_108 = strlen ( V_111 ) + 1 ;
V_103 -= V_108 ;
V_113 = ( char T_4 * ) V_103 ;
if ( F_44 ( V_113 , V_111 , V_108 ) != 0 )
return - V_116 ;
}
V_103 &= ~ 7UL ;
V_109 = sizeof( struct V_119 ) ;
V_109 += sizeof( struct V_120 ) * V_39 -> V_100 -> V_121 ;
V_103 = ( V_103 - V_109 ) & ~ 7UL ;
V_39 -> V_98 = V_103 ;
if ( F_45 ( ( void T_4 * ) V_103 , V_39 -> V_100 , V_109 ) != 0 )
return - V_116 ;
V_50 -> V_73 -> V_79 . V_80 = ( unsigned long ) V_103 ;
if ( V_40 -> V_100 ) {
V_109 = sizeof( struct V_119 ) ;
V_109 += sizeof( struct V_120 ) *
V_40 -> V_100 -> V_121 ;
V_103 = ( V_103 - V_109 ) & ~ 7UL ;
V_40 -> V_98 = V_103 ;
if ( F_45 ( ( void T_4 * ) V_103 , V_40 -> V_100 ,
V_109 ) != 0 )
return - V_116 ;
V_50 -> V_73 -> V_79 . V_81 = ( unsigned long ) V_103 ;
}
#define F_46 15
V_105 = 1 + F_46 + ( V_110 ? 1 : 0 ) +
( V_111 ? 1 : 0 ) + V_122 ;
if ( V_38 -> V_123 & V_124 )
V_105 ++ ;
V_104 = V_103 ;
V_103 -= V_105 * 2 * sizeof( unsigned long ) ;
V_103 -= ( V_38 -> V_125 + 1 ) * sizeof( char * ) ;
V_103 -= ( V_38 -> V_126 + 1 ) * sizeof( char * ) ;
V_103 -= 1 * sizeof( unsigned long ) ;
V_104 -= V_103 & 15UL ;
V_103 -= V_103 & 15UL ;
#define F_47 ( T_6 , T_7 ) \
do { \
struct { unsigned long _id, _val; } __user *ent; \
\
ent = (void __user *) csp; \
__put_user((id), &ent[nr]._id); \
__put_user((val), &ent[nr]._val); \
nr++; \
} while (0)
V_115 = 0 ;
V_104 -= 2 * sizeof( unsigned long ) ;
F_47 ( V_127 , 0 ) ;
if ( V_110 ) {
V_115 = 0 ;
V_104 -= 2 * sizeof( unsigned long ) ;
F_47 ( V_128 ,
( V_129 ) ( unsigned long ) V_112 ) ;
}
if ( V_111 ) {
V_115 = 0 ;
V_104 -= 2 * sizeof( unsigned long ) ;
F_47 ( V_130 ,
( V_129 ) ( unsigned long ) V_113 ) ;
}
if ( V_38 -> V_123 & V_124 ) {
V_115 = 0 ;
V_104 -= 2 * sizeof( unsigned long ) ;
F_47 ( V_131 , V_38 -> V_132 ) ;
}
V_115 = 0 ;
V_104 -= F_46 * 2 * sizeof( unsigned long ) ;
F_47 ( V_133 , V_134 ) ;
#ifdef F_48
F_47 ( V_135 , F_48 ) ;
#endif
F_47 ( V_136 , V_85 ) ;
F_47 ( V_137 , V_138 ) ;
F_47 ( V_139 , V_39 -> V_140 ) ;
F_47 ( V_141 , sizeof( struct V_21 ) ) ;
F_47 ( V_142 , V_39 -> V_3 . V_23 ) ;
F_47 ( V_143 , V_40 -> V_144 ) ;
F_47 ( V_145 , 0 ) ;
F_47 ( V_146 , V_39 -> V_99 ) ;
F_47 ( V_147 , ( V_129 ) F_49 ( V_102 -> V_148 , V_102 -> V_149 ) ) ;
F_47 ( V_150 , ( V_129 ) F_49 ( V_102 -> V_148 , V_102 -> V_151 ) ) ;
F_47 ( V_152 , ( V_129 ) F_50 ( V_102 -> V_148 , V_102 -> V_153 ) ) ;
F_47 ( V_154 , ( V_129 ) F_50 ( V_102 -> V_148 , V_102 -> V_155 ) ) ;
F_47 ( V_156 , F_51 ( V_38 ) ) ;
F_47 ( V_157 , V_38 -> V_158 ) ;
#ifdef F_52
V_115 = 0 ;
V_104 -= V_122 * 2 * sizeof( unsigned long ) ;
F_52 ;
#endif
#undef F_47
V_104 -= ( V_38 -> V_125 + 1 ) * sizeof( T_3 ) ;
V_107 = ( T_3 T_4 * ) V_104 ;
V_104 -= ( V_38 -> V_126 + 1 ) * sizeof( T_3 ) ;
V_106 = ( T_3 T_4 * ) V_104 ;
V_104 -= sizeof( unsigned long ) ;
F_53 ( V_38 -> V_126 , ( unsigned long T_4 * ) V_104 ) ;
F_54 ( V_104 != V_103 ) ;
#ifdef F_17
V_50 -> V_73 -> V_159 = V_38 -> V_114 ;
#else
V_50 -> V_73 -> V_159 = V_50 -> V_73 -> V_76 -
( V_160 * V_85 - V_38 -> V_114 ) ;
#endif
V_114 = ( char T_4 * ) V_50 -> V_73 -> V_159 ;
for ( V_19 = V_38 -> V_126 ; V_19 > 0 ; V_19 -- ) {
F_53 ( ( T_3 ) V_114 , V_106 ++ ) ;
V_109 = F_55 ( V_114 , V_161 ) ;
if ( ! V_109 || V_109 > V_161 )
return - V_162 ;
V_114 += V_109 ;
}
F_53 ( NULL , V_106 ) ;
V_50 -> V_73 -> V_163 = ( unsigned long ) V_114 ;
V_50 -> V_73 -> V_164 = ( unsigned long ) V_114 ;
for ( V_19 = V_38 -> V_125 ; V_19 > 0 ; V_19 -- ) {
F_53 ( ( T_3 ) ( unsigned long ) V_114 , V_107 ++ ) ;
V_109 = F_55 ( V_114 , V_161 ) ;
if ( ! V_109 || V_109 > V_161 )
return - V_162 ;
V_114 += V_109 ;
}
F_53 ( NULL , V_107 ) ;
V_50 -> V_73 -> V_165 = ( unsigned long ) V_114 ;
V_73 -> V_76 = ( unsigned long ) V_103 ;
return 0 ;
}
static int F_43 ( struct V_37 * V_38 ,
unsigned long * V_166 )
{
unsigned long V_167 , V_168 , V_103 ;
char * V_169 ;
int V_170 = 0 ;
V_168 = V_38 -> V_114 >> V_171 ;
V_103 = * V_166 ;
for ( V_167 = V_160 - 1 ; V_167 >= V_168 ; V_167 -- ) {
V_169 = F_56 ( V_38 -> V_172 [ V_167 ] ) ;
V_103 -= V_85 ;
if ( F_45 ( ( void * ) V_103 , V_169 , V_85 ) != 0 )
V_170 = - V_116 ;
F_57 ( V_38 -> V_172 [ V_167 ] ) ;
if ( V_170 < 0 )
goto V_173;
}
* V_166 = ( * V_166 - ( V_160 * V_85 - V_38 -> V_114 ) ) & ~ 15 ;
V_173:
return V_170 ;
}
static int F_30 ( struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_101 * V_73 ,
const char * V_174 )
{
struct V_119 * V_100 ;
#ifdef F_17
struct V_120 * V_175 ;
#endif
struct V_120 * V_176 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_168 ;
unsigned V_177 , V_178 ;
T_5 V_17 ;
int V_19 , V_170 ;
V_177 = 0 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ )
if ( V_14 -> V_24 [ V_19 ] . V_28 == V_61 )
V_177 ++ ;
if ( V_177 == 0 )
return - V_65 ;
V_17 = sizeof( * V_100 ) + V_177 * sizeof( * V_176 ) ;
V_100 = F_58 ( V_17 , V_25 ) ;
if ( ! V_100 )
return - V_22 ;
V_14 -> V_100 = V_100 ;
V_100 -> V_179 = V_180 ;
V_100 -> V_121 = V_177 ;
V_62 = V_14 -> V_62 ;
V_176 = V_100 -> V_181 ;
switch ( V_14 -> V_32 & V_182 ) {
case V_64 :
case V_183 :
#ifndef F_17
V_170 = F_59 ( V_14 , V_4 , V_73 ) ;
if ( V_170 < 0 )
return V_170 ;
break;
#endif
default:
V_170 = F_60 ( V_14 , V_4 , V_73 ) ;
if ( V_170 < 0 )
return V_170 ;
break;
}
if ( V_14 -> V_3 . V_184 ) {
V_176 = V_100 -> V_181 ;
for ( V_19 = V_100 -> V_121 ; V_19 > 0 ; V_19 -- , V_176 ++ ) {
if ( V_14 -> V_3 . V_184 >= V_176 -> V_63 &&
V_14 -> V_3 . V_184 < V_176 -> V_63 + V_176 -> V_36 ) {
V_14 -> V_99 =
( V_14 -> V_3 . V_184 - V_176 -> V_63 ) +
V_176 -> V_185 ;
break;
}
}
}
V_168 = V_14 -> V_3 . V_26 ;
V_168 += V_14 -> V_3 . V_23 * sizeof ( struct V_21 ) ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_16 -> V_28 != V_61 )
continue;
if ( V_16 -> V_59 > V_14 -> V_3 . V_26 ||
V_16 -> V_59 + V_16 -> V_56 < V_168 )
continue;
V_176 = V_100 -> V_181 ;
for ( V_19 = V_100 -> V_121 ; V_19 > 0 ; V_19 -- , V_176 ++ ) {
if ( V_16 -> V_63 >= V_176 -> V_63 &&
V_16 -> V_63 + V_16 -> V_56 <=
V_176 -> V_63 + V_176 -> V_36 ) {
V_14 -> V_140 =
( V_16 -> V_63 - V_176 -> V_63 ) +
V_176 -> V_185 +
V_14 -> V_3 . V_26 - V_16 -> V_59 ;
break;
}
}
break;
}
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_16 -> V_28 != V_186 )
continue;
V_176 = V_100 -> V_181 ;
for ( V_19 = V_100 -> V_121 ; V_19 > 0 ; V_19 -- , V_176 ++ ) {
if ( V_16 -> V_63 >= V_176 -> V_63 &&
V_16 -> V_63 + V_16 -> V_36 <=
V_176 -> V_63 + V_176 -> V_36 ) {
V_14 -> V_97 =
( V_16 -> V_63 - V_176 -> V_63 ) +
V_176 -> V_185 ;
if ( V_16 -> V_36 == 0 ||
V_16 -> V_36 % sizeof( V_187 ) != 0 )
goto V_188;
V_178 = V_16 -> V_36 / sizeof( V_187 ) ;
if ( ( ( V_187 * )
V_14 -> V_97 ) [ V_178 - 1 ] . V_189 != 0 )
goto V_188;
break;
}
}
break;
}
#ifdef F_17
V_177 = V_100 -> V_121 ;
V_175 = V_100 -> V_181 ;
V_176 = V_175 + 1 ;
for ( V_19 = 1 ; V_19 < V_177 ; V_19 ++ ) {
if ( V_176 -> V_63 - V_175 -> V_63 == V_176 -> V_185 - V_175 -> V_185 ) {
V_62 = F_34 ( V_175 -> V_185 + V_175 -> V_36 ) ;
if ( V_62 == ( V_176 -> V_185 & V_86 ) ) {
V_175 -> V_36 +=
V_62 -
( V_175 -> V_185 + V_175 -> V_36 ) ;
V_175 -> V_36 += V_176 -> V_185 & ~ V_86 ;
V_175 -> V_36 += V_176 -> V_36 ;
V_100 -> V_121 -- ;
continue;
}
}
V_175 ++ ;
if ( V_175 != V_176 )
* V_175 = * V_176 ;
}
#endif
F_18 ( L_13 , V_174 ) ;
F_18 ( L_14 , V_14 -> V_144 ) ;
F_18 ( L_15 , V_14 -> V_99 ) ;
F_18 ( L_16 , V_14 -> V_140 ) ;
F_18 ( L_17 , V_14 -> V_97 ) ;
V_176 = V_100 -> V_181 ;
for ( V_19 = 0 ; V_19 < V_100 -> V_121 ; V_19 ++ , V_176 ++ )
F_18 ( L_18 ,
V_19 ,
V_176 -> V_185 , V_176 -> V_185 + V_176 -> V_36 - 1 ,
V_176 -> V_63 , V_176 -> V_36 ) ;
return 0 ;
V_188:
F_31 ( L_19 ,
V_174 , F_61 ( V_4 ) -> V_190 ) ;
return - V_65 ;
}
static int F_59 (
struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_101 * V_73 )
{
struct V_120 * V_176 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_191 = V_192 , V_193 = 0 , V_194 = 0 , V_195 ;
int V_19 , V_170 ;
V_62 = V_14 -> V_62 ;
V_176 = V_14 -> V_100 -> V_181 ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_14 -> V_24 [ V_19 ] . V_28 != V_61 )
continue;
if ( V_191 > V_16 -> V_63 )
V_191 = V_16 -> V_63 ;
if ( V_193 < V_16 -> V_63 + V_16 -> V_36 )
V_193 = V_16 -> V_63 + V_16 -> V_36 ;
}
V_195 = V_92 ;
if ( V_14 -> V_32 & V_54 )
V_195 |= V_196 ;
V_194 = F_35 ( NULL , V_62 , V_193 - V_191 ,
V_87 | V_88 | V_91 , V_195 , 0 ) ;
if ( F_36 ( V_194 ) )
return ( int ) V_194 ;
if ( V_62 != 0 )
V_62 += F_34 ( V_193 - V_191 ) ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_14 -> V_24 [ V_19 ] . V_28 != V_61 )
continue;
V_176 -> V_185 = V_194 + ( V_16 -> V_63 - V_191 ) ;
V_176 -> V_63 = V_16 -> V_63 ;
V_176 -> V_36 = V_16 -> V_36 ;
V_170 = F_62 ( V_4 , V_176 -> V_185 , V_16 -> V_59 ,
V_16 -> V_56 ) ;
if ( V_170 < 0 )
return V_170 ;
if ( V_16 -> V_59 == 0 )
V_14 -> V_144 = V_176 -> V_185 ;
if ( V_16 -> V_56 < V_16 -> V_36 ) {
if ( F_63 ( ( void * ) ( V_176 -> V_185 + V_16 -> V_56 ) ,
V_16 -> V_36 - V_16 -> V_56 ) )
return - V_116 ;
}
if ( V_73 ) {
if ( V_16 -> V_30 & V_31 ) {
if ( ! V_73 -> V_74 ) {
V_73 -> V_74 = V_176 -> V_185 ;
V_73 -> V_75 = V_176 -> V_185 +
V_16 -> V_36 ;
}
} else if ( ! V_73 -> V_77 ) {
V_73 -> V_77 = V_176 -> V_185 ;
V_73 -> V_78 = V_176 -> V_185 + V_16 -> V_36 ;
}
}
V_176 ++ ;
}
return 0 ;
}
static int F_60 ( struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_101 * V_73 )
{
struct V_120 * V_176 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_197 ;
int V_19 , V_198 ;
V_62 = V_14 -> V_62 ;
V_197 = 0 ;
V_198 = 0 ;
V_176 = V_14 -> V_100 -> V_181 ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
unsigned long V_194 , V_199 , V_200 , V_201 ;
int V_202 = 0 , V_32 ;
if ( V_16 -> V_28 != V_61 )
continue;
F_18 ( L_20 ,
( unsigned long ) V_16 -> V_63 ,
( unsigned long ) V_16 -> V_59 ,
( unsigned long ) V_16 -> V_56 ,
( unsigned long ) V_16 -> V_36 ) ;
if ( V_16 -> V_30 & V_203 ) V_202 |= V_87 ;
if ( V_16 -> V_30 & V_204 ) V_202 |= V_88 ;
if ( V_16 -> V_30 & V_31 ) V_202 |= V_91 ;
V_32 = V_92 | V_205 ;
if ( V_14 -> V_32 & V_54 )
V_32 |= V_196 ;
V_194 = 0 ;
switch ( V_14 -> V_32 & V_182 ) {
case V_206 :
break;
case V_207 :
V_194 = V_16 -> V_63 ;
V_32 |= V_208 ;
break;
case V_64 :
if ( ! V_198 ) {
V_194 = V_62 ;
V_197 = V_16 -> V_63 ;
V_198 = 1 ;
} else {
V_194 = V_62 + V_16 -> V_63 - V_197 ;
V_32 |= V_208 ;
}
break;
case V_183 :
break;
default:
F_64 () ;
}
V_194 &= V_86 ;
V_199 = V_16 -> V_63 & ~ V_86 ;
V_194 = F_35 ( V_4 , V_194 , V_16 -> V_36 + V_199 , V_202 , V_32 ,
V_16 -> V_59 - V_199 ) ;
F_18 ( L_21 ,
V_19 , V_16 -> V_36 + V_199 , V_202 , V_32 ,
V_16 -> V_59 - V_199 , V_194 ) ;
if ( F_36 ( V_194 ) )
return ( int ) V_194 ;
if ( ( V_14 -> V_32 & V_182 ) ==
V_183 )
V_62 += F_34 ( V_16 -> V_36 + V_199 ) ;
V_176 -> V_185 = V_194 + V_199 ;
V_176 -> V_63 = V_16 -> V_63 ;
V_176 -> V_36 = V_16 -> V_36 ;
if ( V_16 -> V_59 == 0 )
V_14 -> V_144 = V_176 -> V_185 ;
if ( V_202 & V_88 && V_199 > 0 ) {
F_18 ( L_22 , V_19 , V_194 , V_199 ) ;
if ( F_63 ( ( void T_4 * ) V_194 , V_199 ) )
return - V_116 ;
V_194 += V_199 ;
}
V_200 = V_16 -> V_36 - V_16 -> V_56 ;
V_201 = V_85 - ( ( V_194 + V_16 -> V_56 ) & ~ V_86 ) ;
#ifdef F_17
if ( V_200 > V_201 ) {
unsigned long V_209 = V_194 + V_16 -> V_56 + V_201 ;
unsigned long V_210 ;
V_32 |= V_208 | V_93 ;
V_210 = F_35 ( NULL , V_209 , V_200 - V_201 ,
V_202 , V_32 , 0 ) ;
F_18 ( L_23
L_24 ,
V_19 , V_209 , V_200 - V_201 , V_202 , V_32 ,
V_210 ) ;
if ( V_210 != V_209 )
return - V_22 ;
}
if ( V_202 & V_88 && V_201 > 0 ) {
F_18 ( L_22 ,
V_19 , V_194 + V_16 -> V_56 , V_201 ) ;
if ( F_63 ( ( void T_4 * ) V_194 + V_16 -> V_56 ,
V_201 ) )
return - V_116 ;
}
#else
if ( V_200 > 0 ) {
F_18 ( L_22 ,
V_19 , V_194 + V_16 -> V_56 , V_200 ) ;
if ( F_63 ( ( void * ) V_194 + V_16 -> V_56 , V_200 ) )
return - V_116 ;
}
#endif
if ( V_73 ) {
if ( V_16 -> V_30 & V_31 ) {
if ( ! V_73 -> V_74 ) {
V_73 -> V_74 = V_194 ;
V_73 -> V_75 = V_194 + V_16 -> V_36 ;
}
} else if ( ! V_73 -> V_77 ) {
V_73 -> V_77 = V_194 ;
V_73 -> V_78 = V_194 + V_16 -> V_36 ;
}
}
V_176 ++ ;
}
return 0 ;
}
static int F_65 ( struct V_211 * V_212 , unsigned long V_213 )
{
int V_214 ;
if ( V_212 -> V_215 & V_216 ) {
F_66 ( L_25 , V_212 -> V_217 , V_212 -> V_215 ) ;
return 0 ;
}
if ( ! ( V_212 -> V_215 & V_218 ) ) {
F_66 ( L_26 , V_212 -> V_217 , V_212 -> V_215 ) ;
return 0 ;
}
if ( F_67 ( V_212 ) ) {
if ( V_212 -> V_215 & V_219 ) {
V_214 = F_68 ( V_220 , & V_213 ) ;
F_66 ( L_27 , V_212 -> V_217 ,
V_212 -> V_215 , V_214 ? L_28 : L_29 ) ;
} else {
V_214 = F_68 ( V_221 , & V_213 ) ;
F_66 ( L_30 , V_212 -> V_217 ,
V_212 -> V_215 , V_214 ? L_28 : L_29 ) ;
}
return V_214 ;
}
if ( V_212 -> V_215 & V_219 ) {
if ( F_61 ( V_212 -> V_222 ) -> V_223 == 0 ) {
V_214 = F_68 ( V_224 , & V_213 ) ;
F_66 ( L_31 , V_212 -> V_217 ,
V_212 -> V_215 , V_214 ? L_28 : L_29 ) ;
return V_214 ;
}
V_214 = F_68 ( V_225 , & V_213 ) ;
F_66 ( L_31 , V_212 -> V_217 ,
V_212 -> V_215 , V_214 ? L_28 : L_29 ) ;
return V_214 ;
}
#ifdef F_17
if ( ! V_212 -> V_226 ) {
V_214 = F_68 ( V_227 , & V_213 ) ;
F_66 ( L_32 , V_212 -> V_217 ,
V_212 -> V_215 , V_214 ? L_28 : L_29 ) ;
return V_214 ;
}
#endif
V_214 = F_68 ( V_228 , & V_213 ) ;
F_66 ( L_33 , V_212 -> V_217 , V_212 -> V_215 ,
V_214 ? L_28 : L_29 ) ;
return V_214 ;
}
static int F_69 ( struct V_229 * V_230 )
{
int V_231 ;
V_231 = sizeof( struct V_232 ) ;
V_231 += F_70 ( strlen ( V_230 -> V_233 ) + 1 , 4 ) ;
V_231 += F_70 ( V_230 -> V_234 , 4 ) ;
return V_231 ;
}
static int F_71 ( struct V_229 * V_235 , struct V_236 * V_237 )
{
struct V_232 V_230 ;
V_230 . V_238 = strlen ( V_235 -> V_233 ) + 1 ;
V_230 . V_239 = V_235 -> V_234 ;
V_230 . V_240 = V_235 -> type ;
return F_72 ( V_237 , & V_230 , sizeof( V_230 ) ) &&
F_72 ( V_237 , V_235 -> V_233 , V_230 . V_238 ) && F_73 ( V_237 , 4 ) &&
F_72 ( V_237 , V_235 -> V_241 , V_235 -> V_234 ) && F_73 ( V_237 , 4 ) ;
}
static inline void F_74 ( struct V_2 * V_242 , int V_181 )
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
V_242 -> V_184 = 0 ;
V_242 -> V_26 = sizeof( struct V_2 ) ;
V_242 -> V_257 = 0 ;
V_242 -> V_258 = V_259 ;
V_242 -> V_260 = sizeof( struct V_2 ) ;
V_242 -> V_20 = sizeof( struct V_21 ) ;
V_242 -> V_23 = V_181 ;
V_242 -> V_261 = 0 ;
V_242 -> V_262 = 0 ;
V_242 -> V_263 = 0 ;
return;
}
static inline void F_75 ( struct V_21 * V_16 , int V_231 , T_8 V_264 )
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
static inline void F_76 ( struct V_229 * V_268 , const char * V_233 , int type ,
unsigned int V_231 , void * V_241 )
{
V_268 -> V_233 = V_233 ;
V_268 -> type = type ;
V_268 -> V_234 = V_231 ;
V_268 -> V_241 = V_241 ;
return;
}
static void F_77 ( struct V_269 * V_270 ,
struct V_271 * V_114 , long V_272 )
{
V_270 -> V_273 . V_274 = V_270 -> V_275 = V_272 ;
V_270 -> V_276 = V_114 -> V_277 . signal . V_278 [ 0 ] ;
V_270 -> V_279 = V_114 -> V_280 . V_278 [ 0 ] ;
F_78 () ;
V_270 -> V_281 = F_79 ( F_80 ( V_114 -> V_282 ) ) ;
F_81 () ;
V_270 -> V_283 = F_79 ( V_114 ) ;
V_270 -> V_284 = F_82 ( V_114 ) ;
V_270 -> V_285 = F_83 ( V_114 ) ;
if ( F_84 ( V_114 ) ) {
struct V_286 V_287 ;
F_85 ( V_114 , & V_287 ) ;
F_86 ( V_287 . V_288 , & V_270 -> V_289 ) ;
F_86 ( V_287 . V_290 , & V_270 -> V_291 ) ;
} else {
T_9 V_288 , V_290 ;
V_286 ( V_114 , & V_288 , & V_290 ) ;
F_86 ( V_288 , & V_270 -> V_289 ) ;
F_86 ( V_290 , & V_270 -> V_291 ) ;
}
F_86 ( V_114 -> signal -> V_292 , & V_270 -> V_293 ) ;
F_86 ( V_114 -> signal -> V_294 , & V_270 -> V_295 ) ;
V_270 -> V_296 = V_114 -> V_73 -> V_79 . V_80 ;
V_270 -> V_297 = V_114 -> V_73 -> V_79 . V_81 ;
}
static int F_87 ( struct V_298 * V_299 , struct V_271 * V_114 ,
struct V_101 * V_73 )
{
const struct V_102 * V_102 ;
unsigned int V_49 , V_109 ;
memset ( V_299 , 0 , sizeof( struct V_298 ) ) ;
V_109 = V_73 -> V_163 - V_73 -> V_159 ;
if ( V_109 >= V_300 )
V_109 = V_300 - 1 ;
if ( F_88 ( & V_299 -> V_301 ,
( const char T_4 * ) V_73 -> V_159 , V_109 ) )
return - V_116 ;
for ( V_49 = 0 ; V_49 < V_109 ; V_49 ++ )
if ( V_299 -> V_301 [ V_49 ] == 0 )
V_299 -> V_301 [ V_49 ] = ' ' ;
V_299 -> V_301 [ V_109 ] = 0 ;
F_78 () ;
V_299 -> V_281 = F_79 ( F_80 ( V_114 -> V_282 ) ) ;
F_81 () ;
V_299 -> V_283 = F_79 ( V_114 ) ;
V_299 -> V_284 = F_82 ( V_114 ) ;
V_299 -> V_285 = F_83 ( V_114 ) ;
V_49 = V_114 -> V_302 ? F_89 ( ~ V_114 -> V_302 ) + 1 : 0 ;
V_299 -> V_303 = V_49 ;
V_299 -> V_304 = ( V_49 > 5 ) ? '.' : L_34 [ V_49 ] ;
V_299 -> V_305 = V_299 -> V_304 == 'Z' ;
V_299 -> V_306 = F_90 ( V_114 ) ;
V_299 -> V_307 = V_114 -> V_32 ;
F_78 () ;
V_102 = F_91 ( V_114 ) ;
F_92 ( V_299 -> V_308 , F_49 ( V_102 -> V_148 , V_102 -> V_149 ) ) ;
F_93 ( V_299 -> V_309 , F_50 ( V_102 -> V_148 , V_102 -> V_153 ) ) ;
F_81 () ;
strncpy ( V_299 -> V_310 , V_114 -> V_311 , sizeof( V_299 -> V_310 ) ) ;
return 0 ;
}
static int F_94 ( long V_272 , struct V_312 * V_313 )
{
struct V_271 * V_114 = V_313 -> V_314 ;
int V_231 = 0 ;
V_313 -> V_315 = 0 ;
F_77 ( & V_313 -> V_270 , V_114 , V_272 ) ;
F_95 ( V_114 , & V_313 -> V_270 . V_316 ) ;
F_76 ( & V_313 -> V_317 [ 0 ] , L_35 , V_318 , sizeof( V_313 -> V_270 ) ,
& V_313 -> V_270 ) ;
V_313 -> V_315 ++ ;
V_231 += F_69 ( & V_313 -> V_317 [ 0 ] ) ;
V_313 -> V_270 . V_319 = F_96 ( V_114 , NULL , & V_313 -> V_320 ) ;
if ( V_313 -> V_270 . V_319 ) {
F_76 ( & V_313 -> V_317 [ 1 ] , L_35 , V_321 , sizeof( V_313 -> V_320 ) ,
& V_313 -> V_320 ) ;
V_313 -> V_315 ++ ;
V_231 += F_69 ( & V_313 -> V_317 [ 1 ] ) ;
}
#ifdef F_97
if ( F_98 ( V_114 , & V_313 -> V_322 ) ) {
F_76 ( & V_313 -> V_317 [ 2 ] , L_36 , V_323 ,
sizeof( V_313 -> V_322 ) , & V_313 -> V_322 ) ;
V_313 -> V_315 ++ ;
V_231 += F_69 ( & V_313 -> V_317 [ 2 ] ) ;
}
#endif
return V_231 ;
}
static void F_99 ( struct V_2 * V_242 , struct V_324 * V_325 ,
V_129 V_257 , int V_181 )
{
V_242 -> V_257 = V_257 ;
V_242 -> V_261 = sizeof( * V_325 ) ;
V_242 -> V_262 = 1 ;
V_242 -> V_263 = V_326 ;
memset ( V_325 , 0 , sizeof( * V_325 ) ) ;
V_325 -> V_327 = V_328 ;
V_325 -> V_329 = V_242 -> V_262 ;
V_325 -> V_330 = V_242 -> V_263 ;
V_325 -> V_331 = V_181 ;
}
static bool F_100 ( struct V_236 * V_237 )
{
struct V_211 * V_212 ;
for ( V_212 = V_50 -> V_73 -> V_12 ; V_212 ; V_212 = V_212 -> V_332 ) {
unsigned long V_185 ;
if ( ! F_65 ( V_212 , V_237 -> V_213 ) )
continue;
#ifdef F_17
for ( V_185 = V_212 -> V_217 ; V_185 < V_212 -> V_333 ;
V_185 += V_85 ) {
bool V_334 ;
struct V_172 * V_172 = F_101 ( V_185 ) ;
if ( V_172 ) {
void * V_335 = F_56 ( V_172 ) ;
V_334 = F_72 ( V_237 , V_335 , V_85 ) ;
F_57 ( V_172 ) ;
F_102 ( V_172 ) ;
} else {
V_334 = F_103 ( V_237 , V_85 ) ;
}
if ( ! V_334 )
return false ;
}
#else
if ( ! F_72 ( V_237 , ( void * ) V_212 -> V_217 ,
V_212 -> V_333 - V_212 -> V_217 ) )
return false ;
#endif
}
return true ;
}
static T_5 F_104 ( unsigned long V_213 )
{
struct V_211 * V_212 ;
T_5 V_17 = 0 ;
for ( V_212 = V_50 -> V_73 -> V_12 ; V_212 ; V_212 = V_212 -> V_332 )
if ( F_65 ( V_212 , V_213 ) )
V_17 += V_212 -> V_333 - V_212 -> V_217 ;
return V_17 ;
}
static int F_105 ( struct V_236 * V_237 )
{
#define F_106 6
int V_336 = 0 ;
T_10 V_337 ;
int V_181 ;
int V_49 ;
struct V_211 * V_212 ;
struct V_2 * V_242 = NULL ;
T_8 V_264 = 0 , V_338 ;
int V_339 ;
struct V_229 * V_317 = NULL ;
struct V_269 * V_270 = NULL ;
struct V_298 * V_299 = NULL ;
F_107 ( V_340 ) ;
struct V_341 * V_313 ;
T_11 * V_320 = NULL ;
#ifdef F_97
T_12 * V_322 = NULL ;
#endif
int V_342 = 0 ;
V_129 * V_343 ;
struct V_21 * V_344 = NULL ;
struct V_324 * V_325 = NULL ;
T_13 V_23 ;
V_129 V_257 ;
struct V_345 * V_346 ;
struct V_312 * V_178 ;
V_242 = F_11 ( sizeof( * V_242 ) , V_25 ) ;
if ( ! V_242 )
goto V_347;
V_270 = F_58 ( sizeof( * V_270 ) , V_25 ) ;
if ( ! V_270 )
goto V_347;
V_299 = F_11 ( sizeof( * V_299 ) , V_25 ) ;
if ( ! V_299 )
goto V_347;
V_317 = F_11 ( F_106 * sizeof( struct V_229 ) , V_25 ) ;
if ( ! V_317 )
goto V_347;
V_320 = F_11 ( sizeof( * V_320 ) , V_25 ) ;
if ( ! V_320 )
goto V_347;
#ifdef F_97
V_322 = F_11 ( sizeof( * V_322 ) , V_25 ) ;
if ( ! V_322 )
goto V_347;
#endif
for ( V_346 = V_50 -> V_73 -> V_348 -> V_349 . V_350 ;
V_346 ; V_346 = V_346 -> V_350 ) {
V_178 = F_58 ( sizeof( * V_178 ) , V_25 ) ;
if ( ! V_178 )
goto V_347;
V_178 -> V_314 = V_346 -> V_351 ;
F_108 ( & V_178 -> V_352 , & V_340 ) ;
}
F_109 (t, &thread_list) {
struct V_312 * V_178 ;
int V_231 ;
V_178 = F_110 ( V_313 , struct V_312 , V_352 ) ;
V_231 = F_94 ( V_237 -> V_353 -> V_274 , V_178 ) ;
V_342 += V_231 ;
}
F_77 ( V_270 , V_50 , V_237 -> V_353 -> V_274 ) ;
F_111 ( & V_270 -> V_316 , V_237 -> V_42 ) ;
V_181 = V_50 -> V_73 -> V_354 ;
V_181 += F_112 () ;
V_181 ++ ;
V_23 = V_181 > V_355 ? V_355 : V_181 ;
F_74 ( V_242 , V_23 ) ;
V_336 = 1 ;
F_76 ( V_317 + 0 , L_35 , V_318 , sizeof( * V_270 ) , V_270 ) ;
F_87 ( V_299 , V_50 -> V_356 , V_50 -> V_73 ) ;
F_76 ( V_317 + 1 , L_35 , V_357 , sizeof( * V_299 ) , V_299 ) ;
V_339 = 2 ;
V_343 = ( V_129 * ) V_50 -> V_73 -> V_358 ;
V_49 = 0 ;
do
V_49 += 2 ;
while ( V_343 [ V_49 - 2 ] != V_127 );
F_76 ( & V_317 [ V_339 ++ ] , L_35 , V_359 ,
V_49 * sizeof( V_129 ) , V_343 ) ;
if ( ( V_270 -> V_319 =
F_96 ( V_50 , V_237 -> V_42 , V_320 ) ) )
F_76 ( V_317 + V_339 ++ ,
L_35 , V_321 , sizeof( * V_320 ) , V_320 ) ;
#ifdef F_97
if ( F_98 ( V_50 , V_322 ) )
F_76 ( V_317 + V_339 ++ ,
L_36 , V_323 , sizeof( * V_322 ) , V_322 ) ;
#endif
V_337 = F_113 () ;
F_114 ( V_360 ) ;
V_264 += sizeof( * V_242 ) ;
V_264 += V_181 * sizeof( struct V_21 ) ;
{
int V_231 = 0 ;
for ( V_49 = 0 ; V_49 < V_339 ; V_49 ++ )
V_231 += F_69 ( V_317 + V_49 ) ;
V_231 += V_342 ;
V_344 = F_11 ( sizeof( * V_344 ) , V_25 ) ;
if ( ! V_344 )
goto V_361;
F_75 ( V_344 , V_231 , V_264 ) ;
V_264 += V_231 ;
}
V_338 = V_264 = F_70 ( V_264 , V_362 ) ;
V_264 += F_104 ( V_237 -> V_213 ) ;
V_264 += F_115 () ;
V_257 = V_264 ;
if ( V_23 == V_355 ) {
V_325 = F_11 ( sizeof( * V_325 ) , V_25 ) ;
if ( ! V_325 )
goto V_361;
F_99 ( V_242 , V_325 , V_257 , V_181 ) ;
}
V_264 = V_338 ;
if ( ! F_72 ( V_237 , V_242 , sizeof( * V_242 ) ) )
goto V_361;
if ( ! F_72 ( V_237 , V_344 , sizeof( * V_344 ) ) )
goto V_361;
for ( V_212 = V_50 -> V_73 -> V_12 ; V_212 ; V_212 = V_212 -> V_332 ) {
struct V_21 V_16 ;
T_5 V_231 ;
V_231 = V_212 -> V_333 - V_212 -> V_217 ;
V_16 . V_28 = V_61 ;
V_16 . V_59 = V_264 ;
V_16 . V_63 = V_212 -> V_217 ;
V_16 . V_266 = 0 ;
V_16 . V_56 = F_65 ( V_212 , V_237 -> V_213 ) ? V_231 : 0 ;
V_16 . V_36 = V_231 ;
V_264 += V_16 . V_56 ;
V_16 . V_30 = V_212 -> V_215 & V_218 ? V_203 : 0 ;
if ( V_212 -> V_215 & V_363 )
V_16 . V_30 |= V_204 ;
if ( V_212 -> V_215 & V_90 )
V_16 . V_30 |= V_31 ;
V_16 . V_267 = V_362 ;
if ( ! F_72 ( V_237 , & V_16 , sizeof( V_16 ) ) )
goto V_361;
}
if ( ! F_116 ( V_237 , V_264 ) )
goto V_361;
for ( V_49 = 0 ; V_49 < V_339 ; V_49 ++ )
if ( ! F_71 ( V_317 + V_49 , V_237 ) )
goto V_361;
F_109 (t, &thread_list) {
struct V_312 * V_178 =
F_110 ( V_313 , struct V_312 , V_352 ) ;
for ( V_49 = 0 ; V_49 < V_178 -> V_315 ; V_49 ++ )
if ( ! F_71 ( & V_178 -> V_317 [ V_49 ] , V_237 ) )
goto V_361;
}
if ( ! F_103 ( V_237 , V_338 - V_237 -> V_364 ) )
goto V_361;
if ( ! F_100 ( V_237 ) )
goto V_361;
if ( ! F_117 ( V_237 ) )
goto V_361;
if ( V_23 == V_355 ) {
if ( ! F_72 ( V_237 , V_325 , sizeof( * V_325 ) ) )
goto V_361;
}
if ( V_237 -> V_4 -> V_365 != V_264 ) {
F_31 ( V_366
L_37 ,
V_237 -> V_4 -> V_365 , V_264 ) ;
}
V_361:
F_114 ( V_337 ) ;
V_347:
while ( ! F_118 ( & V_340 ) ) {
struct V_341 * V_178 = V_340 . V_350 ;
F_119 ( V_178 ) ;
F_40 ( F_110 ( V_178 , struct V_312 , V_352 ) ) ;
}
F_40 ( V_344 ) ;
F_40 ( V_242 ) ;
F_40 ( V_270 ) ;
F_40 ( V_299 ) ;
F_40 ( V_317 ) ;
F_40 ( V_320 ) ;
F_40 ( V_325 ) ;
#ifdef F_97
F_40 ( V_322 ) ;
#endif
return V_336 ;
#undef F_106
}
