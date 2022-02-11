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
if ( V_18 < 0 )
goto error;
#endif
V_18 = F_29 ( & V_39 , V_38 -> V_4 , V_50 -> V_72 ,
L_3 ) ;
if ( V_18 < 0 )
goto error;
if ( V_47 ) {
V_18 = F_29 ( & V_40 , V_46 ,
V_50 -> V_72 , L_4 ) ;
if ( V_18 < 0 ) {
F_30 ( V_82 L_5 ) ;
goto error;
}
F_31 ( V_46 ) ;
F_32 ( V_46 ) ;
V_46 = NULL ;
}
#ifdef F_15
if ( ! V_50 -> V_72 -> V_81 )
V_50 -> V_72 -> V_81 = V_50 -> V_72 -> V_77 ;
V_50 -> V_72 -> V_83 = V_50 -> V_72 -> V_81 =
F_33 ( V_50 -> V_72 -> V_81 ) ;
#else
V_35 = ( V_35 + V_84 - 1 ) & V_85 ;
if ( V_35 < V_84 * 2 )
V_35 = V_84 * 2 ;
V_45 = V_86 | V_87 ;
if ( V_48 == V_66 ||
( V_48 == V_68 && V_88 & V_89 ) )
V_45 |= V_90 ;
V_50 -> V_72 -> V_81 = F_34 ( NULL , 0 , V_35 , V_45 ,
V_91 | V_92 |
V_93 | V_94 ,
0 ) ;
if ( F_35 ( V_50 -> V_72 -> V_81 ) ) {
V_18 = V_50 -> V_72 -> V_81 ;
V_50 -> V_72 -> V_81 = 0 ;
goto error;
}
V_50 -> V_72 -> V_83 = V_50 -> V_72 -> V_81 ;
V_50 -> V_72 -> V_78 . V_95 = V_50 -> V_72 -> V_81 ;
V_50 -> V_72 -> V_78 . V_95 +=
( V_35 > V_84 ) ? ( V_35 - V_84 ) : 0 ;
V_50 -> V_72 -> V_75 = V_50 -> V_72 -> V_81 + V_35 ;
#endif
F_36 ( V_38 ) ;
if ( F_37 ( V_38 , V_50 -> V_72 ,
& V_39 , & V_40 ) < 0 )
goto error;
F_16 ( L_6 , V_50 -> V_72 -> V_73 ) ;
F_16 ( L_7 , V_50 -> V_72 -> V_74 ) ;
F_16 ( L_8 , V_50 -> V_72 -> V_76 ) ;
F_16 ( L_9 , V_50 -> V_72 -> V_77 ) ;
F_16 ( L_10 , V_50 -> V_72 -> V_81 ) ;
F_16 ( L_11 , V_50 -> V_72 -> V_83 ) ;
F_16 ( L_12 , V_50 -> V_72 -> V_75 ) ;
#ifdef F_14
V_44 = V_40 . V_96 ? : V_39 . V_96 ;
F_14 ( V_42 , V_39 . V_97 , V_40 . V_97 ,
V_44 ) ;
#endif
V_43 = V_40 . V_98 ? : V_39 . V_98 ;
F_38 ( V_42 , V_43 , V_50 -> V_72 -> V_75 ) ;
V_18 = 0 ;
error:
if ( V_46 ) {
F_31 ( V_46 ) ;
F_32 ( V_46 ) ;
}
F_39 ( V_47 ) ;
F_39 ( V_39 . V_24 ) ;
F_39 ( V_39 . V_99 ) ;
F_39 ( V_40 . V_24 ) ;
F_39 ( V_40 . V_99 ) ;
return V_18 ;
}
static int F_37 ( struct V_37 * V_38 ,
struct V_100 * V_72 ,
struct V_13 * V_39 ,
struct V_13 * V_40 )
{
const struct V_101 * V_101 = F_40 () ;
unsigned long V_102 , V_103 , V_104 ;
T_3 T_4 * V_105 , * V_106 ;
T_5 V_107 = 0 , V_108 ;
char * V_109 , * V_110 ;
char T_4 * V_111 , * V_112 , * V_113 ;
int V_19 ;
int V_114 ;
#ifdef F_15
V_102 = F_41 ( V_38 -> V_113 ) ;
#else
V_102 = V_72 -> V_75 ;
if ( F_42 ( V_38 , & V_102 ) < 0 )
return - V_115 ;
#endif
V_109 = V_116 ;
V_111 = NULL ;
if ( V_109 ) {
V_107 = strlen ( V_109 ) + 1 ;
V_102 -= V_107 ;
V_111 = ( char T_4 * ) V_102 ;
if ( F_43 ( V_111 , V_109 , V_107 ) != 0 )
return - V_115 ;
}
V_110 = V_117 ;
V_112 = NULL ;
if ( V_110 ) {
V_107 = strlen ( V_110 ) + 1 ;
V_102 -= V_107 ;
V_112 = ( char T_4 * ) V_102 ;
if ( F_43 ( V_112 , V_110 , V_107 ) != 0 )
return - V_115 ;
}
V_102 &= ~ 7UL ;
V_108 = sizeof( struct V_118 ) ;
V_108 += sizeof( struct V_119 ) * V_39 -> V_99 -> V_120 ;
V_102 = ( V_102 - V_108 ) & ~ 7UL ;
V_39 -> V_97 = V_102 ;
if ( F_44 ( ( void T_4 * ) V_102 , V_39 -> V_99 , V_108 ) != 0 )
return - V_115 ;
V_50 -> V_72 -> V_78 . V_79 = ( unsigned long ) V_102 ;
if ( V_40 -> V_99 ) {
V_108 = sizeof( struct V_118 ) ;
V_108 += sizeof( struct V_119 ) *
V_40 -> V_99 -> V_120 ;
V_102 = ( V_102 - V_108 ) & ~ 7UL ;
V_40 -> V_97 = V_102 ;
if ( F_44 ( ( void T_4 * ) V_102 , V_40 -> V_99 ,
V_108 ) != 0 )
return - V_115 ;
V_50 -> V_72 -> V_78 . V_80 = ( unsigned long ) V_102 ;
}
#define F_45 15
V_104 = 1 + F_45 + ( V_109 ? 1 : 0 ) +
( V_110 ? 1 : 0 ) + V_121 ;
if ( V_38 -> V_122 & V_123 )
V_104 ++ ;
V_103 = V_102 ;
V_102 -= V_104 * 2 * sizeof( unsigned long ) ;
V_102 -= ( V_38 -> V_124 + 1 ) * sizeof( char * ) ;
V_102 -= ( V_38 -> V_125 + 1 ) * sizeof( char * ) ;
V_102 -= 1 * sizeof( unsigned long ) ;
V_103 -= V_102 & 15UL ;
V_102 -= V_102 & 15UL ;
#define F_46 ( T_6 , T_7 ) \
do { \
struct { unsigned long _id, _val; } __user *ent; \
\
ent = (void __user *) csp; \
__put_user((id), &ent[nr]._id); \
__put_user((val), &ent[nr]._val); \
nr++; \
} while (0)
V_114 = 0 ;
V_103 -= 2 * sizeof( unsigned long ) ;
F_46 ( V_126 , 0 ) ;
if ( V_109 ) {
V_114 = 0 ;
V_103 -= 2 * sizeof( unsigned long ) ;
F_46 ( V_127 ,
( V_128 ) ( unsigned long ) V_111 ) ;
}
if ( V_110 ) {
V_114 = 0 ;
V_103 -= 2 * sizeof( unsigned long ) ;
F_46 ( V_129 ,
( V_128 ) ( unsigned long ) V_112 ) ;
}
if ( V_38 -> V_122 & V_123 ) {
V_114 = 0 ;
V_103 -= 2 * sizeof( unsigned long ) ;
F_46 ( V_130 , V_38 -> V_131 ) ;
}
V_114 = 0 ;
V_103 -= F_45 * 2 * sizeof( unsigned long ) ;
F_46 ( V_132 , V_133 ) ;
#ifdef F_47
F_46 ( V_134 , F_47 ) ;
#endif
F_46 ( V_135 , V_84 ) ;
F_46 ( V_136 , V_137 ) ;
F_46 ( V_138 , V_39 -> V_139 ) ;
F_46 ( V_140 , sizeof( struct V_21 ) ) ;
F_46 ( V_141 , V_39 -> V_3 . V_23 ) ;
F_46 ( V_142 , V_40 -> V_143 ) ;
F_46 ( V_144 , 0 ) ;
F_46 ( V_145 , V_39 -> V_98 ) ;
F_46 ( V_146 , ( V_128 ) F_48 ( V_101 -> V_147 , V_101 -> V_148 ) ) ;
F_46 ( V_149 , ( V_128 ) F_48 ( V_101 -> V_147 , V_101 -> V_150 ) ) ;
F_46 ( V_151 , ( V_128 ) F_49 ( V_101 -> V_147 , V_101 -> V_152 ) ) ;
F_46 ( V_153 , ( V_128 ) F_49 ( V_101 -> V_147 , V_101 -> V_154 ) ) ;
F_46 ( V_155 , F_50 ( V_38 ) ) ;
F_46 ( V_156 , V_38 -> V_157 ) ;
#ifdef F_51
V_114 = 0 ;
V_103 -= V_121 * 2 * sizeof( unsigned long ) ;
F_51 ;
#endif
#undef F_46
V_103 -= ( V_38 -> V_124 + 1 ) * sizeof( T_3 ) ;
V_106 = ( T_3 T_4 * ) V_103 ;
V_103 -= ( V_38 -> V_125 + 1 ) * sizeof( T_3 ) ;
V_105 = ( T_3 T_4 * ) V_103 ;
V_103 -= sizeof( unsigned long ) ;
F_52 ( V_38 -> V_125 , ( unsigned long T_4 * ) V_103 ) ;
F_53 ( V_103 != V_102 ) ;
#ifdef F_15
V_50 -> V_72 -> V_158 = V_38 -> V_113 ;
#else
V_50 -> V_72 -> V_158 = V_50 -> V_72 -> V_75 -
( V_159 * V_84 - V_38 -> V_113 ) ;
#endif
V_113 = ( char T_4 * ) V_50 -> V_72 -> V_158 ;
for ( V_19 = V_38 -> V_125 ; V_19 > 0 ; V_19 -- ) {
F_52 ( ( T_3 ) V_113 , V_105 ++ ) ;
V_108 = F_54 ( V_113 , V_160 ) ;
if ( ! V_108 || V_108 > V_160 )
return - V_161 ;
V_113 += V_108 ;
}
F_52 ( NULL , V_105 ) ;
V_50 -> V_72 -> V_162 = ( unsigned long ) V_113 ;
V_50 -> V_72 -> V_163 = ( unsigned long ) V_113 ;
for ( V_19 = V_38 -> V_124 ; V_19 > 0 ; V_19 -- ) {
F_52 ( ( T_3 ) ( unsigned long ) V_113 , V_106 ++ ) ;
V_108 = F_54 ( V_113 , V_160 ) ;
if ( ! V_108 || V_108 > V_160 )
return - V_161 ;
V_113 += V_108 ;
}
F_52 ( NULL , V_106 ) ;
V_50 -> V_72 -> V_164 = ( unsigned long ) V_113 ;
V_72 -> V_75 = ( unsigned long ) V_102 ;
return 0 ;
}
static int F_42 ( struct V_37 * V_38 ,
unsigned long * V_165 )
{
unsigned long V_166 , V_167 , V_102 ;
char * V_168 ;
int V_169 = 0 ;
V_167 = V_38 -> V_113 >> V_170 ;
V_102 = * V_165 ;
for ( V_166 = V_159 - 1 ; V_166 >= V_167 ; V_166 -- ) {
V_168 = F_55 ( V_38 -> V_171 [ V_166 ] ) ;
V_102 -= V_84 ;
if ( F_44 ( ( void * ) V_102 , V_168 , V_84 ) != 0 )
V_169 = - V_115 ;
F_56 ( V_38 -> V_171 [ V_166 ] ) ;
if ( V_169 < 0 )
goto V_172;
}
* V_165 = ( * V_165 - ( V_159 * V_84 - V_38 -> V_113 ) ) & ~ 15 ;
V_172:
return V_169 ;
}
static int F_29 ( struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_100 * V_72 ,
const char * V_173 )
{
struct V_118 * V_99 ;
#ifdef F_15
struct V_119 * V_174 ;
#endif
struct V_119 * V_175 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_167 ;
unsigned V_176 , V_177 ;
T_5 V_17 ;
int V_19 , V_169 ;
V_176 = 0 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ )
if ( V_14 -> V_24 [ V_19 ] . V_28 == V_61 )
V_176 ++ ;
if ( V_176 == 0 )
return - V_65 ;
V_17 = sizeof( * V_99 ) + V_176 * sizeof( * V_175 ) ;
V_99 = F_57 ( V_17 , V_25 ) ;
if ( ! V_99 )
return - V_22 ;
V_14 -> V_99 = V_99 ;
V_99 -> V_178 = V_179 ;
V_99 -> V_120 = V_176 ;
V_62 = V_14 -> V_62 ;
V_175 = V_99 -> V_180 ;
switch ( V_14 -> V_32 & V_181 ) {
case V_64 :
case V_182 :
#ifndef F_15
V_169 = F_58 ( V_14 , V_4 , V_72 ) ;
if ( V_169 < 0 )
return V_169 ;
break;
#endif
default:
V_169 = F_59 ( V_14 , V_4 , V_72 ) ;
if ( V_169 < 0 )
return V_169 ;
break;
}
if ( V_14 -> V_3 . V_183 ) {
V_175 = V_99 -> V_180 ;
for ( V_19 = V_99 -> V_120 ; V_19 > 0 ; V_19 -- , V_175 ++ ) {
if ( V_14 -> V_3 . V_183 >= V_175 -> V_63 &&
V_14 -> V_3 . V_183 < V_175 -> V_63 + V_175 -> V_36 ) {
V_14 -> V_98 =
( V_14 -> V_3 . V_183 - V_175 -> V_63 ) +
V_175 -> V_184 ;
break;
}
}
}
V_167 = V_14 -> V_3 . V_26 ;
V_167 += V_14 -> V_3 . V_23 * sizeof ( struct V_21 ) ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_16 -> V_28 != V_61 )
continue;
if ( V_16 -> V_59 > V_14 -> V_3 . V_26 ||
V_16 -> V_59 + V_16 -> V_56 < V_167 )
continue;
V_175 = V_99 -> V_180 ;
for ( V_19 = V_99 -> V_120 ; V_19 > 0 ; V_19 -- , V_175 ++ ) {
if ( V_16 -> V_63 >= V_175 -> V_63 &&
V_16 -> V_63 + V_16 -> V_56 <=
V_175 -> V_63 + V_175 -> V_36 ) {
V_14 -> V_139 =
( V_16 -> V_63 - V_175 -> V_63 ) +
V_175 -> V_184 +
V_14 -> V_3 . V_26 - V_16 -> V_59 ;
break;
}
}
break;
}
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_16 -> V_28 != V_185 )
continue;
V_175 = V_99 -> V_180 ;
for ( V_19 = V_99 -> V_120 ; V_19 > 0 ; V_19 -- , V_175 ++ ) {
if ( V_16 -> V_63 >= V_175 -> V_63 &&
V_16 -> V_63 + V_16 -> V_36 <=
V_175 -> V_63 + V_175 -> V_36 ) {
V_14 -> V_96 =
( V_16 -> V_63 - V_175 -> V_63 ) +
V_175 -> V_184 ;
if ( V_16 -> V_36 == 0 ||
V_16 -> V_36 % sizeof( V_186 ) != 0 )
goto V_187;
V_177 = V_16 -> V_36 / sizeof( V_186 ) ;
if ( ( ( V_186 * )
V_14 -> V_96 ) [ V_177 - 1 ] . V_188 != 0 )
goto V_187;
break;
}
}
break;
}
#ifdef F_15
V_176 = V_99 -> V_120 ;
V_174 = V_99 -> V_180 ;
V_175 = V_174 + 1 ;
for ( V_19 = 1 ; V_19 < V_176 ; V_19 ++ ) {
if ( V_175 -> V_63 - V_174 -> V_63 == V_175 -> V_184 - V_174 -> V_184 ) {
V_62 = F_33 ( V_174 -> V_184 + V_174 -> V_36 ) ;
if ( V_62 == ( V_175 -> V_184 & V_85 ) ) {
V_174 -> V_36 +=
V_62 -
( V_174 -> V_184 + V_174 -> V_36 ) ;
V_174 -> V_36 += V_175 -> V_184 & ~ V_85 ;
V_174 -> V_36 += V_175 -> V_36 ;
V_99 -> V_120 -- ;
continue;
}
}
V_174 ++ ;
if ( V_174 != V_175 )
* V_174 = * V_175 ;
}
#endif
F_16 ( L_13 , V_173 ) ;
F_16 ( L_14 , V_14 -> V_143 ) ;
F_16 ( L_15 , V_14 -> V_98 ) ;
F_16 ( L_16 , V_14 -> V_139 ) ;
F_16 ( L_17 , V_14 -> V_96 ) ;
V_175 = V_99 -> V_180 ;
for ( V_19 = 0 ; V_19 < V_99 -> V_120 ; V_19 ++ , V_175 ++ )
F_16 ( L_18 ,
V_19 ,
V_175 -> V_184 , V_175 -> V_184 + V_175 -> V_36 - 1 ,
V_175 -> V_63 , V_175 -> V_36 ) ;
return 0 ;
V_187:
F_30 ( L_19 ,
V_173 , F_60 ( V_4 ) -> V_189 ) ;
return - V_65 ;
}
static int F_58 (
struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_100 * V_72 )
{
struct V_119 * V_175 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_190 = V_191 , V_192 = 0 , V_193 = 0 , V_194 ;
int V_19 , V_169 ;
V_62 = V_14 -> V_62 ;
V_175 = V_14 -> V_99 -> V_180 ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_14 -> V_24 [ V_19 ] . V_28 != V_61 )
continue;
if ( V_190 > V_16 -> V_63 )
V_190 = V_16 -> V_63 ;
if ( V_192 < V_16 -> V_63 + V_16 -> V_36 )
V_192 = V_16 -> V_63 + V_16 -> V_36 ;
}
V_194 = V_91 ;
if ( V_14 -> V_32 & V_54 )
V_194 |= V_195 ;
V_193 = F_34 ( NULL , V_62 , V_192 - V_190 ,
V_86 | V_87 | V_90 , V_194 , 0 ) ;
if ( F_35 ( V_193 ) )
return ( int ) V_193 ;
if ( V_62 != 0 )
V_62 += F_33 ( V_192 - V_190 ) ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_14 -> V_24 [ V_19 ] . V_28 != V_61 )
continue;
V_175 -> V_184 = V_193 + ( V_16 -> V_63 - V_190 ) ;
V_175 -> V_63 = V_16 -> V_63 ;
V_175 -> V_36 = V_16 -> V_36 ;
V_169 = F_61 ( V_4 , V_175 -> V_184 , V_16 -> V_59 ,
V_16 -> V_56 ) ;
if ( V_169 < 0 )
return V_169 ;
if ( V_16 -> V_59 == 0 )
V_14 -> V_143 = V_175 -> V_184 ;
if ( V_16 -> V_56 < V_16 -> V_36 ) {
if ( F_62 ( ( void * ) ( V_175 -> V_184 + V_16 -> V_56 ) ,
V_16 -> V_36 - V_16 -> V_56 ) )
return - V_115 ;
}
if ( V_72 ) {
if ( V_16 -> V_30 & V_31 ) {
if ( ! V_72 -> V_73 ) {
V_72 -> V_73 = V_175 -> V_184 ;
V_72 -> V_74 = V_175 -> V_184 +
V_16 -> V_36 ;
}
} else if ( ! V_72 -> V_76 ) {
V_72 -> V_76 = V_175 -> V_184 ;
V_72 -> V_77 = V_175 -> V_184 + V_16 -> V_36 ;
}
}
V_175 ++ ;
}
return 0 ;
}
static int F_59 ( struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_100 * V_72 )
{
struct V_119 * V_175 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_196 ;
int V_19 , V_197 ;
V_62 = V_14 -> V_62 ;
V_196 = 0 ;
V_197 = 0 ;
V_175 = V_14 -> V_99 -> V_180 ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
unsigned long V_193 , V_198 , V_199 , V_200 ;
int V_201 = 0 , V_32 ;
if ( V_16 -> V_28 != V_61 )
continue;
F_16 ( L_20 ,
( unsigned long ) V_16 -> V_63 ,
( unsigned long ) V_16 -> V_59 ,
( unsigned long ) V_16 -> V_56 ,
( unsigned long ) V_16 -> V_36 ) ;
if ( V_16 -> V_30 & V_202 ) V_201 |= V_86 ;
if ( V_16 -> V_30 & V_203 ) V_201 |= V_87 ;
if ( V_16 -> V_30 & V_31 ) V_201 |= V_90 ;
V_32 = V_91 | V_204 ;
if ( V_14 -> V_32 & V_54 )
V_32 |= V_195 ;
V_193 = 0 ;
switch ( V_14 -> V_32 & V_181 ) {
case V_205 :
break;
case V_206 :
V_193 = V_16 -> V_63 ;
V_32 |= V_207 ;
break;
case V_64 :
if ( ! V_197 ) {
V_193 = V_62 ;
V_196 = V_16 -> V_63 ;
V_197 = 1 ;
} else {
V_193 = V_62 + V_16 -> V_63 - V_196 ;
V_32 |= V_207 ;
}
break;
case V_182 :
break;
default:
F_63 () ;
}
V_193 &= V_85 ;
V_198 = V_16 -> V_63 & ~ V_85 ;
V_193 = F_34 ( V_4 , V_193 , V_16 -> V_36 + V_198 , V_201 , V_32 ,
V_16 -> V_59 - V_198 ) ;
F_16 ( L_21 ,
V_19 , V_16 -> V_36 + V_198 , V_201 , V_32 ,
V_16 -> V_59 - V_198 , V_193 ) ;
if ( F_35 ( V_193 ) )
return ( int ) V_193 ;
if ( ( V_14 -> V_32 & V_181 ) ==
V_182 )
V_62 += F_33 ( V_16 -> V_36 + V_198 ) ;
V_175 -> V_184 = V_193 + V_198 ;
V_175 -> V_63 = V_16 -> V_63 ;
V_175 -> V_36 = V_16 -> V_36 ;
if ( V_16 -> V_59 == 0 )
V_14 -> V_143 = V_175 -> V_184 ;
if ( V_201 & V_87 && V_198 > 0 ) {
F_16 ( L_22 , V_19 , V_193 , V_198 ) ;
if ( F_62 ( ( void T_4 * ) V_193 , V_198 ) )
return - V_115 ;
V_193 += V_198 ;
}
V_199 = V_16 -> V_36 - V_16 -> V_56 ;
V_200 = V_84 - ( ( V_193 + V_16 -> V_56 ) & ~ V_85 ) ;
#ifdef F_15
if ( V_199 > V_200 ) {
unsigned long V_208 = V_193 + V_16 -> V_56 + V_200 ;
unsigned long V_209 ;
V_32 |= V_207 | V_92 ;
V_209 = F_34 ( NULL , V_208 , V_199 - V_200 ,
V_201 , V_32 , 0 ) ;
F_16 ( L_23
L_24 ,
V_19 , V_208 , V_199 - V_200 , V_201 , V_32 ,
V_209 ) ;
if ( V_209 != V_208 )
return - V_22 ;
}
if ( V_201 & V_87 && V_200 > 0 ) {
F_16 ( L_22 ,
V_19 , V_193 + V_16 -> V_56 , V_200 ) ;
if ( F_62 ( ( void T_4 * ) V_193 + V_16 -> V_56 ,
V_200 ) )
return - V_115 ;
}
#else
if ( V_199 > 0 ) {
F_16 ( L_22 ,
V_19 , V_193 + V_16 -> V_56 , V_199 ) ;
if ( F_62 ( ( void * ) V_193 + V_16 -> V_56 , V_199 ) )
return - V_115 ;
}
#endif
if ( V_72 ) {
if ( V_16 -> V_30 & V_31 ) {
if ( ! V_72 -> V_73 ) {
V_72 -> V_73 = V_193 ;
V_72 -> V_74 = V_193 + V_16 -> V_36 ;
}
} else if ( ! V_72 -> V_76 ) {
V_72 -> V_76 = V_193 ;
V_72 -> V_77 = V_193 + V_16 -> V_36 ;
}
}
V_175 ++ ;
}
return 0 ;
}
static int F_64 ( struct V_210 * V_211 , unsigned long V_212 )
{
int V_213 ;
if ( V_211 -> V_214 & V_215 ) {
F_65 ( L_25 , V_211 -> V_216 , V_211 -> V_214 ) ;
return 0 ;
}
if ( ! ( V_211 -> V_214 & V_217 ) ) {
F_65 ( L_26 , V_211 -> V_216 , V_211 -> V_214 ) ;
return 0 ;
}
if ( V_211 -> V_214 & V_218 ) {
if ( F_60 ( V_211 -> V_219 ) -> V_220 == 0 ) {
V_213 = F_66 ( V_221 , & V_212 ) ;
F_65 ( L_27 , V_211 -> V_216 ,
V_211 -> V_214 , V_213 ? L_28 : L_29 ) ;
return V_213 ;
}
V_213 = F_66 ( V_222 , & V_212 ) ;
F_65 ( L_27 , V_211 -> V_216 ,
V_211 -> V_214 , V_213 ? L_28 : L_29 ) ;
return V_213 ;
}
#ifdef F_15
if ( ! V_211 -> V_223 ) {
V_213 = F_66 ( V_224 , & V_212 ) ;
F_65 ( L_30 , V_211 -> V_216 ,
V_211 -> V_214 , V_213 ? L_28 : L_29 ) ;
return V_213 ;
}
#endif
V_213 = F_66 ( V_225 , & V_212 ) ;
F_65 ( L_31 , V_211 -> V_216 , V_211 -> V_214 ,
V_213 ? L_28 : L_29 ) ;
return V_213 ;
}
static int F_67 ( struct V_226 * V_227 )
{
int V_228 ;
V_228 = sizeof( struct V_229 ) ;
V_228 += F_68 ( strlen ( V_227 -> V_230 ) + 1 , 4 ) ;
V_228 += F_68 ( V_227 -> V_231 , 4 ) ;
return V_228 ;
}
static int F_69 ( struct V_226 * V_232 , struct V_233 * V_234 )
{
struct V_229 V_227 ;
V_227 . V_235 = strlen ( V_232 -> V_230 ) + 1 ;
V_227 . V_236 = V_232 -> V_231 ;
V_227 . V_237 = V_232 -> type ;
return F_70 ( V_234 , & V_227 , sizeof( V_227 ) ) &&
F_70 ( V_234 , V_232 -> V_230 , V_227 . V_235 ) && F_71 ( V_234 , 4 ) &&
F_70 ( V_234 , V_232 -> V_238 , V_232 -> V_231 ) && F_71 ( V_234 , 4 ) ;
}
static inline void F_72 ( struct V_2 * V_239 , int V_180 )
{
memcpy ( V_239 -> V_5 , V_6 , V_7 ) ;
V_239 -> V_5 [ V_240 ] = V_241 ;
V_239 -> V_5 [ V_242 ] = V_243 ;
V_239 -> V_5 [ V_244 ] = V_245 ;
V_239 -> V_5 [ V_246 ] = V_247 ;
memset ( V_239 -> V_5 + V_248 , 0 , V_249 - V_248 ) ;
V_239 -> V_8 = V_250 ;
V_239 -> V_251 = V_252 ;
V_239 -> V_253 = V_245 ;
V_239 -> V_183 = 0 ;
V_239 -> V_26 = sizeof( struct V_2 ) ;
V_239 -> V_254 = 0 ;
V_239 -> V_255 = V_256 ;
V_239 -> V_257 = sizeof( struct V_2 ) ;
V_239 -> V_20 = sizeof( struct V_21 ) ;
V_239 -> V_23 = V_180 ;
V_239 -> V_258 = 0 ;
V_239 -> V_259 = 0 ;
V_239 -> V_260 = 0 ;
return;
}
static inline void F_73 ( struct V_21 * V_16 , int V_228 , T_8 V_261 )
{
V_16 -> V_28 = V_262 ;
V_16 -> V_59 = V_261 ;
V_16 -> V_63 = 0 ;
V_16 -> V_263 = 0 ;
V_16 -> V_56 = V_228 ;
V_16 -> V_36 = 0 ;
V_16 -> V_30 = 0 ;
V_16 -> V_264 = 0 ;
return;
}
static inline void F_74 ( struct V_226 * V_265 , const char * V_230 , int type ,
unsigned int V_228 , void * V_238 )
{
V_265 -> V_230 = V_230 ;
V_265 -> type = type ;
V_265 -> V_231 = V_228 ;
V_265 -> V_238 = V_238 ;
return;
}
static void F_75 ( struct V_266 * V_267 ,
struct V_268 * V_113 , long V_269 )
{
V_267 -> V_270 . V_271 = V_267 -> V_272 = V_269 ;
V_267 -> V_273 = V_113 -> V_274 . signal . V_275 [ 0 ] ;
V_267 -> V_276 = V_113 -> V_277 . V_275 [ 0 ] ;
F_76 () ;
V_267 -> V_278 = F_77 ( F_78 ( V_113 -> V_279 ) ) ;
F_79 () ;
V_267 -> V_280 = F_77 ( V_113 ) ;
V_267 -> V_281 = F_80 ( V_113 ) ;
V_267 -> V_282 = F_81 ( V_113 ) ;
if ( F_82 ( V_113 ) ) {
struct V_283 V_284 ;
F_83 ( V_113 , & V_284 ) ;
F_84 ( V_284 . V_285 , & V_267 -> V_286 ) ;
F_84 ( V_284 . V_287 , & V_267 -> V_288 ) ;
} else {
T_9 V_285 , V_287 ;
V_283 ( V_113 , & V_285 , & V_287 ) ;
F_84 ( V_285 , & V_267 -> V_286 ) ;
F_84 ( V_287 , & V_267 -> V_288 ) ;
}
F_84 ( V_113 -> signal -> V_289 , & V_267 -> V_290 ) ;
F_84 ( V_113 -> signal -> V_291 , & V_267 -> V_292 ) ;
V_267 -> V_293 = V_113 -> V_72 -> V_78 . V_79 ;
V_267 -> V_294 = V_113 -> V_72 -> V_78 . V_80 ;
}
static int F_85 ( struct V_295 * V_296 , struct V_268 * V_113 ,
struct V_100 * V_72 )
{
const struct V_101 * V_101 ;
unsigned int V_49 , V_108 ;
memset ( V_296 , 0 , sizeof( struct V_295 ) ) ;
V_108 = V_72 -> V_162 - V_72 -> V_158 ;
if ( V_108 >= V_297 )
V_108 = V_297 - 1 ;
if ( F_86 ( & V_296 -> V_298 ,
( const char T_4 * ) V_72 -> V_158 , V_108 ) )
return - V_115 ;
for ( V_49 = 0 ; V_49 < V_108 ; V_49 ++ )
if ( V_296 -> V_298 [ V_49 ] == 0 )
V_296 -> V_298 [ V_49 ] = ' ' ;
V_296 -> V_298 [ V_108 ] = 0 ;
F_76 () ;
V_296 -> V_278 = F_77 ( F_78 ( V_113 -> V_279 ) ) ;
F_79 () ;
V_296 -> V_280 = F_77 ( V_113 ) ;
V_296 -> V_281 = F_80 ( V_113 ) ;
V_296 -> V_282 = F_81 ( V_113 ) ;
V_49 = V_113 -> V_299 ? F_87 ( ~ V_113 -> V_299 ) + 1 : 0 ;
V_296 -> V_300 = V_49 ;
V_296 -> V_301 = ( V_49 > 5 ) ? '.' : L_32 [ V_49 ] ;
V_296 -> V_302 = V_296 -> V_301 == 'Z' ;
V_296 -> V_303 = F_88 ( V_113 ) ;
V_296 -> V_304 = V_113 -> V_32 ;
F_76 () ;
V_101 = F_89 ( V_113 ) ;
F_90 ( V_296 -> V_305 , F_48 ( V_101 -> V_147 , V_101 -> V_148 ) ) ;
F_91 ( V_296 -> V_306 , F_49 ( V_101 -> V_147 , V_101 -> V_152 ) ) ;
F_79 () ;
strncpy ( V_296 -> V_307 , V_113 -> V_308 , sizeof( V_296 -> V_307 ) ) ;
return 0 ;
}
static int F_92 ( long V_269 , struct V_309 * V_310 )
{
struct V_268 * V_113 = V_310 -> V_311 ;
int V_228 = 0 ;
V_310 -> V_312 = 0 ;
F_75 ( & V_310 -> V_267 , V_113 , V_269 ) ;
F_93 ( V_113 , & V_310 -> V_267 . V_313 ) ;
F_74 ( & V_310 -> V_314 [ 0 ] , L_33 , V_315 , sizeof( V_310 -> V_267 ) ,
& V_310 -> V_267 ) ;
V_310 -> V_312 ++ ;
V_228 += F_67 ( & V_310 -> V_314 [ 0 ] ) ;
V_310 -> V_267 . V_316 = F_94 ( V_113 , NULL , & V_310 -> V_317 ) ;
if ( V_310 -> V_267 . V_316 ) {
F_74 ( & V_310 -> V_314 [ 1 ] , L_33 , V_318 , sizeof( V_310 -> V_317 ) ,
& V_310 -> V_317 ) ;
V_310 -> V_312 ++ ;
V_228 += F_67 ( & V_310 -> V_314 [ 1 ] ) ;
}
#ifdef F_95
if ( F_96 ( V_113 , & V_310 -> V_319 ) ) {
F_74 ( & V_310 -> V_314 [ 2 ] , L_34 , V_320 ,
sizeof( V_310 -> V_319 ) , & V_310 -> V_319 ) ;
V_310 -> V_312 ++ ;
V_228 += F_67 ( & V_310 -> V_314 [ 2 ] ) ;
}
#endif
return V_228 ;
}
static void F_97 ( struct V_2 * V_239 , struct V_321 * V_322 ,
V_128 V_254 , int V_180 )
{
V_239 -> V_254 = V_254 ;
V_239 -> V_258 = sizeof( * V_322 ) ;
V_239 -> V_259 = 1 ;
V_239 -> V_260 = V_323 ;
memset ( V_322 , 0 , sizeof( * V_322 ) ) ;
V_322 -> V_324 = V_325 ;
V_322 -> V_326 = V_239 -> V_259 ;
V_322 -> V_327 = V_239 -> V_260 ;
V_322 -> V_328 = V_180 ;
}
static bool F_98 ( struct V_233 * V_234 )
{
struct V_210 * V_211 ;
for ( V_211 = V_50 -> V_72 -> V_12 ; V_211 ; V_211 = V_211 -> V_329 ) {
unsigned long V_184 ;
if ( ! F_64 ( V_211 , V_234 -> V_212 ) )
continue;
#ifdef F_15
for ( V_184 = V_211 -> V_216 ; V_184 < V_211 -> V_330 ;
V_184 += V_84 ) {
bool V_331 ;
struct V_171 * V_171 = F_99 ( V_184 ) ;
if ( V_171 ) {
void * V_332 = F_55 ( V_171 ) ;
V_331 = F_70 ( V_234 , V_332 , V_84 ) ;
F_56 ( V_171 ) ;
F_100 ( V_171 ) ;
} else {
V_331 = F_101 ( V_234 , V_84 ) ;
}
if ( ! V_331 )
return false ;
}
#else
if ( ! F_70 ( V_234 , ( void * ) V_211 -> V_216 ,
V_211 -> V_330 - V_211 -> V_216 ) )
return false ;
#endif
}
return true ;
}
static T_5 F_102 ( unsigned long V_212 )
{
struct V_210 * V_211 ;
T_5 V_17 = 0 ;
for ( V_211 = V_50 -> V_72 -> V_12 ; V_211 ; V_211 = V_211 -> V_329 )
if ( F_64 ( V_211 , V_212 ) )
V_17 += V_211 -> V_330 - V_211 -> V_216 ;
return V_17 ;
}
static int F_103 ( struct V_233 * V_234 )
{
#define F_104 6
int V_333 = 0 ;
T_10 V_334 ;
int V_180 ;
int V_49 ;
struct V_210 * V_211 ;
struct V_2 * V_239 = NULL ;
T_8 V_261 = 0 , V_335 ;
int V_336 ;
struct V_226 * V_314 = NULL ;
struct V_266 * V_267 = NULL ;
struct V_295 * V_296 = NULL ;
F_105 ( V_337 ) ;
struct V_338 * V_310 ;
T_11 * V_317 = NULL ;
#ifdef F_95
T_12 * V_319 = NULL ;
#endif
int V_339 = 0 ;
V_128 * V_340 ;
struct V_21 * V_341 = NULL ;
struct V_321 * V_322 = NULL ;
T_13 V_23 ;
V_128 V_254 ;
struct V_342 * V_343 ;
struct V_309 * V_177 ;
V_239 = F_9 ( sizeof( * V_239 ) , V_25 ) ;
if ( ! V_239 )
goto V_344;
V_267 = F_57 ( sizeof( * V_267 ) , V_25 ) ;
if ( ! V_267 )
goto V_344;
V_296 = F_9 ( sizeof( * V_296 ) , V_25 ) ;
if ( ! V_296 )
goto V_344;
V_314 = F_9 ( F_104 * sizeof( struct V_226 ) , V_25 ) ;
if ( ! V_314 )
goto V_344;
V_317 = F_9 ( sizeof( * V_317 ) , V_25 ) ;
if ( ! V_317 )
goto V_344;
#ifdef F_95
V_319 = F_9 ( sizeof( * V_319 ) , V_25 ) ;
if ( ! V_319 )
goto V_344;
#endif
for ( V_343 = V_50 -> V_72 -> V_345 -> V_346 . V_347 ;
V_343 ; V_343 = V_343 -> V_347 ) {
V_177 = F_57 ( sizeof( * V_177 ) , V_25 ) ;
if ( ! V_177 )
goto V_344;
V_177 -> V_311 = V_343 -> V_348 ;
F_106 ( & V_177 -> V_349 , & V_337 ) ;
}
F_107 (t, &thread_list) {
struct V_309 * V_177 ;
int V_228 ;
V_177 = F_108 ( V_310 , struct V_309 , V_349 ) ;
V_228 = F_92 ( V_234 -> V_350 -> V_271 , V_177 ) ;
V_339 += V_228 ;
}
F_75 ( V_267 , V_50 , V_234 -> V_350 -> V_271 ) ;
F_109 ( & V_267 -> V_313 , V_234 -> V_42 ) ;
V_180 = V_50 -> V_72 -> V_351 ;
V_180 += F_110 () ;
V_180 ++ ;
V_23 = V_180 > V_352 ? V_352 : V_180 ;
F_72 ( V_239 , V_23 ) ;
V_333 = 1 ;
F_74 ( V_314 + 0 , L_33 , V_315 , sizeof( * V_267 ) , V_267 ) ;
F_85 ( V_296 , V_50 -> V_353 , V_50 -> V_72 ) ;
F_74 ( V_314 + 1 , L_33 , V_354 , sizeof( * V_296 ) , V_296 ) ;
V_336 = 2 ;
V_340 = ( V_128 * ) V_50 -> V_72 -> V_355 ;
V_49 = 0 ;
do
V_49 += 2 ;
while ( V_340 [ V_49 - 2 ] != V_126 );
F_74 ( & V_314 [ V_336 ++ ] , L_33 , V_356 ,
V_49 * sizeof( V_128 ) , V_340 ) ;
if ( ( V_267 -> V_316 =
F_94 ( V_50 , V_234 -> V_42 , V_317 ) ) )
F_74 ( V_314 + V_336 ++ ,
L_33 , V_318 , sizeof( * V_317 ) , V_317 ) ;
#ifdef F_95
if ( F_96 ( V_50 , V_319 ) )
F_74 ( V_314 + V_336 ++ ,
L_34 , V_320 , sizeof( * V_319 ) , V_319 ) ;
#endif
V_334 = F_111 () ;
F_112 ( V_357 ) ;
V_261 += sizeof( * V_239 ) ;
V_261 += V_180 * sizeof( struct V_21 ) ;
{
int V_228 = 0 ;
for ( V_49 = 0 ; V_49 < V_336 ; V_49 ++ )
V_228 += F_67 ( V_314 + V_49 ) ;
V_228 += V_339 ;
V_341 = F_9 ( sizeof( * V_341 ) , V_25 ) ;
if ( ! V_341 )
goto V_358;
F_73 ( V_341 , V_228 , V_261 ) ;
V_261 += V_228 ;
}
V_335 = V_261 = F_68 ( V_261 , V_359 ) ;
V_261 += F_102 ( V_234 -> V_212 ) ;
V_261 += F_113 () ;
V_254 = V_261 ;
if ( V_23 == V_352 ) {
V_322 = F_9 ( sizeof( * V_322 ) , V_25 ) ;
if ( ! V_322 )
goto V_358;
F_97 ( V_239 , V_322 , V_254 , V_180 ) ;
}
V_261 = V_335 ;
if ( ! F_70 ( V_234 , V_239 , sizeof( * V_239 ) ) )
goto V_358;
if ( ! F_70 ( V_234 , V_341 , sizeof( * V_341 ) ) )
goto V_358;
for ( V_211 = V_50 -> V_72 -> V_12 ; V_211 ; V_211 = V_211 -> V_329 ) {
struct V_21 V_16 ;
T_5 V_228 ;
V_228 = V_211 -> V_330 - V_211 -> V_216 ;
V_16 . V_28 = V_61 ;
V_16 . V_59 = V_261 ;
V_16 . V_63 = V_211 -> V_216 ;
V_16 . V_263 = 0 ;
V_16 . V_56 = F_64 ( V_211 , V_234 -> V_212 ) ? V_228 : 0 ;
V_16 . V_36 = V_228 ;
V_261 += V_16 . V_56 ;
V_16 . V_30 = V_211 -> V_214 & V_217 ? V_202 : 0 ;
if ( V_211 -> V_214 & V_360 )
V_16 . V_30 |= V_203 ;
if ( V_211 -> V_214 & V_89 )
V_16 . V_30 |= V_31 ;
V_16 . V_264 = V_359 ;
if ( ! F_70 ( V_234 , & V_16 , sizeof( V_16 ) ) )
goto V_358;
}
if ( ! F_114 ( V_234 , V_261 ) )
goto V_358;
for ( V_49 = 0 ; V_49 < V_336 ; V_49 ++ )
if ( ! F_69 ( V_314 + V_49 , V_234 ) )
goto V_358;
F_107 (t, &thread_list) {
struct V_309 * V_177 =
F_108 ( V_310 , struct V_309 , V_349 ) ;
for ( V_49 = 0 ; V_49 < V_177 -> V_312 ; V_49 ++ )
if ( ! F_69 ( & V_177 -> V_314 [ V_49 ] , V_234 ) )
goto V_358;
}
if ( ! F_101 ( V_234 , V_335 - V_234 -> V_361 ) )
goto V_358;
if ( ! F_98 ( V_234 ) )
goto V_358;
if ( ! F_115 ( V_234 ) )
goto V_358;
if ( V_23 == V_352 ) {
if ( ! F_70 ( V_234 , V_322 , sizeof( * V_322 ) ) )
goto V_358;
}
if ( V_234 -> V_4 -> V_362 != V_261 ) {
F_30 ( V_363
L_35 ,
V_234 -> V_4 -> V_362 , V_261 ) ;
}
V_358:
F_112 ( V_334 ) ;
V_344:
while ( ! F_116 ( & V_337 ) ) {
struct V_338 * V_177 = V_337 . V_347 ;
F_117 ( V_177 ) ;
F_39 ( F_108 ( V_177 , struct V_309 , V_349 ) ) ;
}
F_39 ( V_341 ) ;
F_39 ( V_239 ) ;
F_39 ( V_267 ) ;
F_39 ( V_296 ) ;
F_39 ( V_314 ) ;
F_39 ( V_317 ) ;
F_39 ( V_322 ) ;
#ifdef F_95
F_39 ( V_319 ) ;
#endif
return V_333 ;
#undef F_104
}
