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
T_3 V_20 = V_14 -> V_3 . V_21 ;
if ( V_14 -> V_3 . V_22 != sizeof( struct V_23 ) )
return - V_24 ;
if ( V_14 -> V_3 . V_25 > 65536U / sizeof( struct V_23 ) )
return - V_24 ;
V_17 = V_14 -> V_3 . V_25 * sizeof( struct V_23 ) ;
V_14 -> V_26 = F_11 ( V_17 , V_27 ) ;
if ( ! V_14 -> V_26 )
return - V_24 ;
V_18 = F_12 ( V_4 , V_14 -> V_26 , V_17 , & V_20 ) ;
if ( F_13 ( V_18 != V_17 ) )
return V_18 < 0 ? V_18 : - V_28 ;
V_16 = V_14 -> V_26 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_25 ; V_19 ++ , V_16 ++ ) {
if ( V_16 -> V_29 != V_30 )
continue;
if ( V_16 -> V_31 & V_32 )
V_14 -> V_33 |= V_34 ;
else
V_14 -> V_33 |= V_35 ;
V_14 -> V_36 = V_16 -> V_37 ;
break;
}
return 0 ;
}
static int F_14 ( struct V_38 * V_39 )
{
struct V_13 V_40 , V_41 ;
struct V_42 * V_43 = F_15 () ;
struct V_23 * V_16 ;
unsigned long V_36 , V_44 ;
#ifdef F_16
unsigned long V_45 ;
#endif
#ifndef F_17
unsigned long V_46 ;
#endif
struct V_4 * V_47 = NULL ;
char * V_48 = NULL ;
int V_49 ;
int V_18 , V_50 ;
T_3 V_20 ;
F_18 ( L_1 , V_51 -> V_52 ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_40 . V_3 = * (struct V_2 * ) V_39 -> V_53 ;
V_40 . V_33 = V_54 | V_55 ;
V_18 = - V_28 ;
if ( ! F_5 ( & V_40 . V_3 , V_39 -> V_4 ) )
goto error;
if ( ! F_8 ( & V_40 . V_3 ) ) {
#ifdef F_17
goto error;
#else
if ( V_40 . V_3 . V_8 != V_10 )
goto error;
#endif
}
V_18 = F_10 ( & V_40 , V_39 -> V_4 ) ;
if ( V_18 < 0 )
goto error;
V_16 = V_40 . V_26 ;
for ( V_50 = 0 ; V_50 < V_40 . V_3 . V_25 ; V_50 ++ , V_16 ++ ) {
switch ( V_16 -> V_29 ) {
case V_56 :
V_18 = - V_24 ;
if ( V_16 -> V_57 > V_58 )
goto error;
V_18 = - V_59 ;
if ( V_16 -> V_57 < 2 )
goto error;
V_48 = F_11 ( V_16 -> V_57 , V_27 ) ;
if ( ! V_48 )
goto error;
V_20 = V_16 -> V_60 ;
V_18 = F_12 ( V_39 -> V_4 , V_48 ,
V_16 -> V_57 , & V_20 ) ;
if ( F_13 ( V_18 != V_16 -> V_57 ) ) {
if ( V_18 >= 0 )
V_18 = - V_28 ;
goto error;
}
V_18 = - V_59 ;
if ( V_48 [ V_16 -> V_57 - 1 ] != '\0' )
goto error;
F_18 ( L_2 , V_48 ) ;
V_47 = F_19 ( V_48 ) ;
V_18 = F_20 ( V_47 ) ;
if ( F_21 ( V_47 ) ) {
V_47 = NULL ;
goto error;
}
F_22 ( V_39 , V_47 ) ;
V_20 = 0 ;
V_18 = F_12 ( V_47 , V_39 -> V_53 ,
V_61 , & V_20 ) ;
if ( F_13 ( V_18 != V_61 ) ) {
if ( V_18 >= 0 )
V_18 = - V_28 ;
goto error;
}
V_41 . V_3 = * ( (struct V_2 * ) V_39 -> V_53 ) ;
break;
case V_62 :
#ifdef F_17
if ( V_40 . V_63 == 0 )
V_40 . V_63 = V_16 -> V_64 ;
#endif
break;
}
}
if ( F_7 ( & V_40 . V_3 ) )
V_40 . V_33 |= V_65 ;
if ( V_48 ) {
V_18 = - V_66 ;
if ( ! F_5 ( & V_41 . V_3 , V_47 ) )
goto error;
V_41 . V_33 = V_54 ;
V_18 = F_10 ( & V_41 , V_47 ) ;
if ( V_18 < 0 )
goto error;
}
V_36 = V_40 . V_36 ;
if ( V_40 . V_33 & V_34 )
V_49 = V_67 ;
else if ( V_40 . V_33 & V_35 )
V_49 = V_68 ;
else
V_49 = V_69 ;
if ( V_36 == 0 ) {
V_36 = V_41 . V_36 ;
if ( V_41 . V_33 & V_34 )
V_49 = V_67 ;
else if ( V_41 . V_33 & V_35 )
V_49 = V_68 ;
else
V_49 = V_69 ;
}
V_18 = - V_28 ;
if ( V_36 == 0 )
V_36 = 131072UL ;
if ( F_7 ( & V_41 . V_3 ) )
V_41 . V_33 |= V_65 ;
V_18 = F_23 ( V_39 ) ;
if ( V_18 )
goto error;
if ( F_8 ( & V_40 . V_3 ) )
F_24 ( V_70 ) ;
else
F_24 ( V_71 ) ;
if ( F_25 ( & V_40 . V_3 , V_49 ) )
V_51 -> V_72 |= V_73 ;
F_26 ( V_39 ) ;
F_27 ( & V_1 ) ;
V_51 -> V_74 -> V_75 = 0 ;
V_51 -> V_74 -> V_76 = 0 ;
V_51 -> V_74 -> V_77 = 0 ;
V_51 -> V_74 -> V_78 = 0 ;
V_51 -> V_74 -> V_79 = 0 ;
V_51 -> V_74 -> V_80 . V_81 = 0 ;
V_51 -> V_74 -> V_80 . V_82 = 0 ;
#ifdef F_17
F_28 ( & V_40 ,
& V_41 ,
& V_51 -> V_74 -> V_77 ,
& V_51 -> V_74 -> V_83 ) ;
V_18 = F_29 ( V_39 , V_51 -> V_74 -> V_77 ,
V_49 ) ;
if ( V_18 < 0 )
goto error;
#endif
V_18 = F_30 ( & V_40 , V_39 -> V_4 , V_51 -> V_74 ,
L_3 ) ;
if ( V_18 < 0 )
goto error;
if ( V_48 ) {
V_18 = F_30 ( & V_41 , V_47 ,
V_51 -> V_74 , L_4 ) ;
if ( V_18 < 0 ) {
F_31 ( V_84 L_5 ) ;
goto error;
}
F_32 ( V_47 ) ;
F_33 ( V_47 ) ;
V_47 = NULL ;
}
#ifdef F_17
if ( ! V_51 -> V_74 -> V_83 )
V_51 -> V_74 -> V_83 = V_51 -> V_74 -> V_79 ;
V_51 -> V_74 -> V_85 = V_51 -> V_74 -> V_83 =
F_34 ( V_51 -> V_74 -> V_83 ) ;
#else
V_36 = ( V_36 + V_86 - 1 ) & V_87 ;
if ( V_36 < V_86 * 2 )
V_36 = V_86 * 2 ;
V_46 = V_88 | V_89 ;
if ( V_49 == V_67 ||
( V_49 == V_69 && V_90 & V_91 ) )
V_46 |= V_92 ;
V_51 -> V_74 -> V_83 = F_35 ( NULL , 0 , V_36 , V_46 ,
V_93 | V_94 |
V_95 | V_96 ,
0 ) ;
if ( F_36 ( V_51 -> V_74 -> V_83 ) ) {
V_18 = V_51 -> V_74 -> V_83 ;
V_51 -> V_74 -> V_83 = 0 ;
goto error;
}
V_51 -> V_74 -> V_85 = V_51 -> V_74 -> V_83 ;
V_51 -> V_74 -> V_80 . V_97 = V_51 -> V_74 -> V_83 ;
V_51 -> V_74 -> V_77 = V_51 -> V_74 -> V_83 + V_36 ;
#endif
F_37 ( V_39 ) ;
if ( F_38 ( V_39 , V_51 -> V_74 ,
& V_40 , & V_41 ) < 0 )
goto error;
F_18 ( L_6 , V_51 -> V_74 -> V_75 ) ;
F_18 ( L_7 , V_51 -> V_74 -> V_76 ) ;
F_18 ( L_8 , V_51 -> V_74 -> V_78 ) ;
F_18 ( L_9 , V_51 -> V_74 -> V_79 ) ;
F_18 ( L_10 , V_51 -> V_74 -> V_83 ) ;
F_18 ( L_11 , V_51 -> V_74 -> V_85 ) ;
F_18 ( L_12 , V_51 -> V_74 -> V_77 ) ;
#ifdef F_16
V_45 = V_41 . V_98 ? : V_40 . V_98 ;
F_16 ( V_43 , V_40 . V_99 , V_41 . V_99 ,
V_45 ) ;
#endif
V_44 = V_41 . V_100 ? : V_40 . V_100 ;
F_39 ( V_43 , V_44 , V_51 -> V_74 -> V_77 ) ;
V_18 = 0 ;
error:
if ( V_47 ) {
F_32 ( V_47 ) ;
F_33 ( V_47 ) ;
}
F_40 ( V_48 ) ;
F_40 ( V_40 . V_26 ) ;
F_40 ( V_40 . V_101 ) ;
F_40 ( V_41 . V_26 ) ;
F_40 ( V_41 . V_101 ) ;
return V_18 ;
}
static int F_38 ( struct V_38 * V_39 ,
struct V_102 * V_74 ,
struct V_13 * V_40 ,
struct V_13 * V_41 )
{
const struct V_103 * V_103 = F_41 () ;
unsigned long V_104 , V_105 , V_106 ;
T_4 T_5 * V_107 , * V_108 ;
T_6 V_109 = 0 , V_110 ;
char * V_111 , * V_112 ;
char T_5 * V_113 , * V_114 , * V_115 ;
int V_19 ;
int V_116 ;
#ifdef F_17
V_104 = F_42 ( V_39 -> V_115 ) ;
#else
V_104 = V_74 -> V_77 ;
if ( F_43 ( V_39 , & V_104 ) < 0 )
return - V_117 ;
V_104 &= ~ 15 ;
#endif
V_111 = V_118 ;
V_113 = NULL ;
if ( V_111 ) {
V_109 = strlen ( V_111 ) + 1 ;
V_104 -= V_109 ;
V_113 = ( char T_5 * ) V_104 ;
if ( F_44 ( V_113 , V_111 , V_109 ) != 0 )
return - V_117 ;
}
V_112 = V_119 ;
V_114 = NULL ;
if ( V_112 ) {
V_109 = strlen ( V_112 ) + 1 ;
V_104 -= V_109 ;
V_114 = ( char T_5 * ) V_104 ;
if ( F_44 ( V_114 , V_112 , V_109 ) != 0 )
return - V_117 ;
}
V_104 &= ~ 7UL ;
V_110 = sizeof( struct V_120 ) ;
V_110 += sizeof( struct V_121 ) * V_40 -> V_101 -> V_122 ;
V_104 = ( V_104 - V_110 ) & ~ 7UL ;
V_40 -> V_99 = V_104 ;
if ( F_45 ( ( void T_5 * ) V_104 , V_40 -> V_101 , V_110 ) != 0 )
return - V_117 ;
V_51 -> V_74 -> V_80 . V_81 = ( unsigned long ) V_104 ;
if ( V_41 -> V_101 ) {
V_110 = sizeof( struct V_120 ) ;
V_110 += sizeof( struct V_121 ) *
V_41 -> V_101 -> V_122 ;
V_104 = ( V_104 - V_110 ) & ~ 7UL ;
V_41 -> V_99 = V_104 ;
if ( F_45 ( ( void T_5 * ) V_104 , V_41 -> V_101 ,
V_110 ) != 0 )
return - V_117 ;
V_51 -> V_74 -> V_80 . V_82 = ( unsigned long ) V_104 ;
}
#define F_46 15
V_106 = 1 + F_46 + ( V_111 ? 1 : 0 ) +
( V_112 ? 1 : 0 ) + V_123 ;
if ( V_39 -> V_124 & V_125 )
V_106 ++ ;
V_105 = V_104 ;
V_104 -= V_106 * 2 * sizeof( unsigned long ) ;
V_104 -= ( V_39 -> V_126 + 1 ) * sizeof( char * ) ;
V_104 -= ( V_39 -> V_127 + 1 ) * sizeof( char * ) ;
V_104 -= 1 * sizeof( unsigned long ) ;
V_105 -= V_104 & 15UL ;
V_104 -= V_104 & 15UL ;
#define F_47 ( T_7 , T_8 ) \
do { \
struct { unsigned long _id, _val; } __user *ent; \
\
ent = (void __user *) csp; \
__put_user((id), &ent[nr]._id); \
__put_user((val), &ent[nr]._val); \
nr++; \
} while (0)
V_116 = 0 ;
V_105 -= 2 * sizeof( unsigned long ) ;
F_47 ( V_128 , 0 ) ;
if ( V_111 ) {
V_116 = 0 ;
V_105 -= 2 * sizeof( unsigned long ) ;
F_47 ( V_129 ,
( V_130 ) ( unsigned long ) V_113 ) ;
}
if ( V_112 ) {
V_116 = 0 ;
V_105 -= 2 * sizeof( unsigned long ) ;
F_47 ( V_131 ,
( V_130 ) ( unsigned long ) V_114 ) ;
}
if ( V_39 -> V_124 & V_125 ) {
V_116 = 0 ;
V_105 -= 2 * sizeof( unsigned long ) ;
F_47 ( V_132 , V_39 -> V_133 ) ;
}
V_116 = 0 ;
V_105 -= F_46 * 2 * sizeof( unsigned long ) ;
F_47 ( V_134 , V_135 ) ;
#ifdef F_48
F_47 ( V_136 , F_48 ) ;
#endif
F_47 ( V_137 , V_86 ) ;
F_47 ( V_138 , V_139 ) ;
F_47 ( V_140 , V_40 -> V_141 ) ;
F_47 ( V_142 , sizeof( struct V_23 ) ) ;
F_47 ( V_143 , V_40 -> V_3 . V_25 ) ;
F_47 ( V_144 , V_41 -> V_145 ) ;
F_47 ( V_146 , 0 ) ;
F_47 ( V_147 , V_40 -> V_100 ) ;
F_47 ( V_148 , ( V_130 ) F_49 ( V_103 -> V_149 , V_103 -> V_150 ) ) ;
F_47 ( V_151 , ( V_130 ) F_49 ( V_103 -> V_149 , V_103 -> V_152 ) ) ;
F_47 ( V_153 , ( V_130 ) F_50 ( V_103 -> V_149 , V_103 -> V_154 ) ) ;
F_47 ( V_155 , ( V_130 ) F_50 ( V_103 -> V_149 , V_103 -> V_156 ) ) ;
F_47 ( V_157 , V_39 -> V_158 ) ;
F_47 ( V_159 , V_39 -> V_160 ) ;
#ifdef F_51
V_116 = 0 ;
V_105 -= V_123 * 2 * sizeof( unsigned long ) ;
F_51 ;
#endif
#undef F_47
V_105 -= ( V_39 -> V_126 + 1 ) * sizeof( T_4 ) ;
V_108 = ( T_4 T_5 * ) V_105 ;
V_105 -= ( V_39 -> V_127 + 1 ) * sizeof( T_4 ) ;
V_107 = ( T_4 T_5 * ) V_105 ;
V_105 -= sizeof( unsigned long ) ;
F_52 ( V_39 -> V_127 , ( unsigned long T_5 * ) V_105 ) ;
F_53 ( V_105 != V_104 ) ;
#ifdef F_17
V_51 -> V_74 -> V_161 = V_39 -> V_115 ;
#else
V_51 -> V_74 -> V_161 = V_51 -> V_74 -> V_77 -
( V_162 * V_86 - V_39 -> V_115 ) ;
#endif
V_115 = ( char T_5 * ) V_51 -> V_74 -> V_161 ;
for ( V_19 = V_39 -> V_127 ; V_19 > 0 ; V_19 -- ) {
F_52 ( ( T_4 ) V_115 , V_107 ++ ) ;
V_110 = F_54 ( V_115 , V_163 ) ;
if ( ! V_110 || V_110 > V_163 )
return - V_164 ;
V_115 += V_110 ;
}
F_52 ( NULL , V_107 ) ;
V_51 -> V_74 -> V_165 = ( unsigned long ) V_115 ;
V_51 -> V_74 -> V_166 = ( unsigned long ) V_115 ;
for ( V_19 = V_39 -> V_126 ; V_19 > 0 ; V_19 -- ) {
F_52 ( ( T_4 ) ( unsigned long ) V_115 , V_108 ++ ) ;
V_110 = F_54 ( V_115 , V_163 ) ;
if ( ! V_110 || V_110 > V_163 )
return - V_164 ;
V_115 += V_110 ;
}
F_52 ( NULL , V_108 ) ;
V_51 -> V_74 -> V_167 = ( unsigned long ) V_115 ;
V_74 -> V_77 = ( unsigned long ) V_104 ;
return 0 ;
}
static int F_30 ( struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_102 * V_74 ,
const char * V_168 )
{
struct V_120 * V_101 ;
#ifdef F_17
struct V_121 * V_169 ;
#endif
struct V_121 * V_170 ;
struct V_15 * V_16 ;
unsigned long V_63 , V_171 ;
unsigned V_172 , V_173 ;
T_6 V_17 ;
int V_19 , V_174 ;
V_172 = 0 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_25 ; V_19 ++ )
if ( V_14 -> V_26 [ V_19 ] . V_29 == V_62 )
V_172 ++ ;
if ( V_172 == 0 )
return - V_66 ;
V_17 = sizeof( * V_101 ) + V_172 * sizeof( * V_170 ) ;
V_101 = F_55 ( V_17 , V_27 ) ;
if ( ! V_101 )
return - V_24 ;
V_14 -> V_101 = V_101 ;
V_101 -> V_175 = V_176 ;
V_101 -> V_122 = V_172 ;
V_63 = V_14 -> V_63 ;
V_170 = V_101 -> V_177 ;
switch ( V_14 -> V_33 & V_178 ) {
case V_65 :
case V_179 :
#ifndef F_17
V_174 = F_56 ( V_14 , V_4 , V_74 ) ;
if ( V_174 < 0 )
return V_174 ;
break;
#endif
default:
V_174 = F_57 ( V_14 , V_4 , V_74 ) ;
if ( V_174 < 0 )
return V_174 ;
break;
}
if ( V_14 -> V_3 . V_180 ) {
V_170 = V_101 -> V_177 ;
for ( V_19 = V_101 -> V_122 ; V_19 > 0 ; V_19 -- , V_170 ++ ) {
if ( V_14 -> V_3 . V_180 >= V_170 -> V_64 &&
V_14 -> V_3 . V_180 < V_170 -> V_64 + V_170 -> V_37 ) {
V_14 -> V_100 =
( V_14 -> V_3 . V_180 - V_170 -> V_64 ) +
V_170 -> V_181 ;
break;
}
}
}
V_171 = V_14 -> V_3 . V_21 ;
V_171 += V_14 -> V_3 . V_25 * sizeof ( struct V_23 ) ;
V_16 = V_14 -> V_26 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_25 ; V_19 ++ , V_16 ++ ) {
if ( V_16 -> V_29 != V_62 )
continue;
if ( V_16 -> V_60 > V_14 -> V_3 . V_21 ||
V_16 -> V_60 + V_16 -> V_57 < V_171 )
continue;
V_170 = V_101 -> V_177 ;
for ( V_19 = V_101 -> V_122 ; V_19 > 0 ; V_19 -- , V_170 ++ ) {
if ( V_16 -> V_64 >= V_170 -> V_64 &&
V_16 -> V_64 + V_16 -> V_57 <=
V_170 -> V_64 + V_170 -> V_37 ) {
V_14 -> V_141 =
( V_16 -> V_64 - V_170 -> V_64 ) +
V_170 -> V_181 +
V_14 -> V_3 . V_21 - V_16 -> V_60 ;
break;
}
}
break;
}
V_16 = V_14 -> V_26 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_25 ; V_19 ++ , V_16 ++ ) {
if ( V_16 -> V_29 != V_182 )
continue;
V_170 = V_101 -> V_177 ;
for ( V_19 = V_101 -> V_122 ; V_19 > 0 ; V_19 -- , V_170 ++ ) {
if ( V_16 -> V_64 >= V_170 -> V_64 &&
V_16 -> V_64 + V_16 -> V_37 <=
V_170 -> V_64 + V_170 -> V_37 ) {
V_14 -> V_98 =
( V_16 -> V_64 - V_170 -> V_64 ) +
V_170 -> V_181 ;
if ( V_16 -> V_37 == 0 ||
V_16 -> V_37 % sizeof( V_183 ) != 0 )
goto V_184;
V_173 = V_16 -> V_37 / sizeof( V_183 ) ;
if ( ( ( V_183 * )
V_14 -> V_98 ) [ V_173 - 1 ] . V_185 != 0 )
goto V_184;
break;
}
}
break;
}
#ifdef F_17
V_172 = V_101 -> V_122 ;
V_169 = V_101 -> V_177 ;
V_170 = V_169 + 1 ;
for ( V_19 = 1 ; V_19 < V_172 ; V_19 ++ ) {
if ( V_170 -> V_64 - V_169 -> V_64 == V_170 -> V_181 - V_169 -> V_181 ) {
V_63 = F_34 ( V_169 -> V_181 + V_169 -> V_37 ) ;
if ( V_63 == ( V_170 -> V_181 & V_87 ) ) {
V_169 -> V_37 +=
V_63 -
( V_169 -> V_181 + V_169 -> V_37 ) ;
V_169 -> V_37 += V_170 -> V_181 & ~ V_87 ;
V_169 -> V_37 += V_170 -> V_37 ;
V_101 -> V_122 -- ;
continue;
}
}
V_169 ++ ;
if ( V_169 != V_170 )
* V_169 = * V_170 ;
}
#endif
F_18 ( L_13 , V_168 ) ;
F_18 ( L_14 , V_14 -> V_145 ) ;
F_18 ( L_15 , V_14 -> V_100 ) ;
F_18 ( L_16 , V_14 -> V_141 ) ;
F_18 ( L_17 , V_14 -> V_98 ) ;
V_170 = V_101 -> V_177 ;
for ( V_19 = 0 ; V_19 < V_101 -> V_122 ; V_19 ++ , V_170 ++ )
F_18 ( L_18 ,
V_19 ,
V_170 -> V_181 , V_170 -> V_181 + V_170 -> V_37 - 1 ,
V_170 -> V_64 , V_170 -> V_37 ) ;
return 0 ;
V_184:
F_31 ( L_19 ,
V_168 , F_58 ( V_4 ) -> V_186 ) ;
return - V_66 ;
}
static int F_56 (
struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_102 * V_74 )
{
struct V_121 * V_170 ;
struct V_15 * V_16 ;
unsigned long V_63 , V_187 = V_188 , V_189 = 0 , V_190 = 0 , V_191 ;
int V_19 , V_174 ;
V_63 = V_14 -> V_63 ;
V_170 = V_14 -> V_101 -> V_177 ;
V_16 = V_14 -> V_26 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_25 ; V_19 ++ , V_16 ++ ) {
if ( V_14 -> V_26 [ V_19 ] . V_29 != V_62 )
continue;
if ( V_187 > V_16 -> V_64 )
V_187 = V_16 -> V_64 ;
if ( V_189 < V_16 -> V_64 + V_16 -> V_37 )
V_189 = V_16 -> V_64 + V_16 -> V_37 ;
}
V_191 = V_93 ;
if ( V_14 -> V_33 & V_55 )
V_191 |= V_192 ;
V_190 = F_35 ( NULL , V_63 , V_189 - V_187 ,
V_88 | V_89 | V_92 , V_191 , 0 ) ;
if ( F_36 ( V_190 ) )
return ( int ) V_190 ;
if ( V_63 != 0 )
V_63 += F_34 ( V_189 - V_187 ) ;
V_16 = V_14 -> V_26 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_25 ; V_19 ++ , V_16 ++ ) {
if ( V_14 -> V_26 [ V_19 ] . V_29 != V_62 )
continue;
V_170 -> V_181 = V_190 + ( V_16 -> V_64 - V_187 ) ;
V_170 -> V_64 = V_16 -> V_64 ;
V_170 -> V_37 = V_16 -> V_37 ;
V_174 = F_59 ( V_4 , V_170 -> V_181 , V_16 -> V_60 ,
V_16 -> V_57 ) ;
if ( V_174 < 0 )
return V_174 ;
if ( V_16 -> V_60 == 0 )
V_14 -> V_145 = V_170 -> V_181 ;
if ( V_16 -> V_57 < V_16 -> V_37 ) {
if ( F_60 ( ( void * ) ( V_170 -> V_181 + V_16 -> V_57 ) ,
V_16 -> V_37 - V_16 -> V_57 ) )
return - V_117 ;
}
if ( V_74 ) {
if ( V_16 -> V_31 & V_32 ) {
if ( ! V_74 -> V_75 ) {
V_74 -> V_75 = V_170 -> V_181 ;
V_74 -> V_76 = V_170 -> V_181 +
V_16 -> V_37 ;
}
} else if ( ! V_74 -> V_78 ) {
V_74 -> V_78 = V_170 -> V_181 ;
V_74 -> V_79 = V_170 -> V_181 + V_16 -> V_37 ;
}
}
V_170 ++ ;
}
return 0 ;
}
static int F_57 ( struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_102 * V_74 )
{
struct V_121 * V_170 ;
struct V_15 * V_16 ;
unsigned long V_63 , V_193 ;
int V_19 , V_194 ;
V_63 = V_14 -> V_63 ;
V_193 = 0 ;
V_194 = 0 ;
V_170 = V_14 -> V_101 -> V_177 ;
V_16 = V_14 -> V_26 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_25 ; V_19 ++ , V_16 ++ ) {
unsigned long V_190 , V_195 , V_196 , V_197 ;
int V_198 = 0 , V_33 ;
if ( V_16 -> V_29 != V_62 )
continue;
F_18 ( L_20 ,
( unsigned long ) V_16 -> V_64 ,
( unsigned long ) V_16 -> V_60 ,
( unsigned long ) V_16 -> V_57 ,
( unsigned long ) V_16 -> V_37 ) ;
if ( V_16 -> V_31 & V_199 ) V_198 |= V_88 ;
if ( V_16 -> V_31 & V_200 ) V_198 |= V_89 ;
if ( V_16 -> V_31 & V_32 ) V_198 |= V_92 ;
V_33 = V_93 | V_201 ;
if ( V_14 -> V_33 & V_55 )
V_33 |= V_192 ;
V_190 = 0 ;
switch ( V_14 -> V_33 & V_178 ) {
case V_202 :
break;
case V_203 :
V_190 = V_16 -> V_64 ;
V_33 |= V_204 ;
break;
case V_65 :
if ( ! V_194 ) {
V_190 = V_63 ;
V_193 = V_16 -> V_64 ;
V_194 = 1 ;
} else {
V_190 = V_63 + V_16 -> V_64 - V_193 ;
V_33 |= V_204 ;
}
break;
case V_179 :
break;
default:
F_61 () ;
}
V_190 &= V_87 ;
V_195 = V_16 -> V_64 & ~ V_87 ;
V_190 = F_35 ( V_4 , V_190 , V_16 -> V_37 + V_195 , V_198 , V_33 ,
V_16 -> V_60 - V_195 ) ;
F_18 ( L_21 ,
V_19 , V_16 -> V_37 + V_195 , V_198 , V_33 ,
V_16 -> V_60 - V_195 , V_190 ) ;
if ( F_36 ( V_190 ) )
return ( int ) V_190 ;
if ( ( V_14 -> V_33 & V_178 ) ==
V_179 )
V_63 += F_34 ( V_16 -> V_37 + V_195 ) ;
V_170 -> V_181 = V_190 + V_195 ;
V_170 -> V_64 = V_16 -> V_64 ;
V_170 -> V_37 = V_16 -> V_37 ;
if ( V_16 -> V_60 == 0 )
V_14 -> V_145 = V_170 -> V_181 ;
if ( V_198 & V_89 && V_195 > 0 ) {
F_18 ( L_22 , V_19 , V_190 , V_195 ) ;
if ( F_60 ( ( void T_5 * ) V_190 , V_195 ) )
return - V_117 ;
V_190 += V_195 ;
}
V_196 = V_16 -> V_37 - V_16 -> V_57 ;
V_197 = V_86 - ( ( V_190 + V_16 -> V_57 ) & ~ V_87 ) ;
#ifdef F_17
if ( V_196 > V_197 ) {
unsigned long V_205 = V_190 + V_16 -> V_57 + V_197 ;
unsigned long V_206 ;
V_33 |= V_204 | V_94 ;
V_206 = F_35 ( NULL , V_205 , V_196 - V_197 ,
V_198 , V_33 , 0 ) ;
F_18 ( L_23
L_24 ,
V_19 , V_205 , V_196 - V_197 , V_198 , V_33 ,
V_206 ) ;
if ( V_206 != V_205 )
return - V_24 ;
}
if ( V_198 & V_89 && V_197 > 0 ) {
F_18 ( L_22 ,
V_19 , V_190 + V_16 -> V_57 , V_197 ) ;
if ( F_60 ( ( void T_5 * ) V_190 + V_16 -> V_57 ,
V_197 ) )
return - V_117 ;
}
#else
if ( V_196 > 0 ) {
F_18 ( L_22 ,
V_19 , V_190 + V_16 -> V_57 , V_196 ) ;
if ( F_60 ( ( void * ) V_190 + V_16 -> V_57 , V_196 ) )
return - V_117 ;
}
#endif
if ( V_74 ) {
if ( V_16 -> V_31 & V_32 ) {
if ( ! V_74 -> V_75 ) {
V_74 -> V_75 = V_190 ;
V_74 -> V_76 = V_190 + V_16 -> V_37 ;
}
} else if ( ! V_74 -> V_78 ) {
V_74 -> V_78 = V_190 ;
V_74 -> V_79 = V_190 + V_16 -> V_37 ;
}
}
V_170 ++ ;
}
return 0 ;
}
static int F_62 ( struct V_207 * V_208 , unsigned long V_209 )
{
int V_210 ;
if ( V_208 -> V_211 & V_212 ) {
F_63 ( L_25 , V_208 -> V_213 , V_208 -> V_211 ) ;
return 0 ;
}
if ( ! ( V_208 -> V_211 & V_214 ) ) {
F_63 ( L_26 , V_208 -> V_213 , V_208 -> V_211 ) ;
return 0 ;
}
if ( F_64 ( V_208 ) ) {
if ( V_208 -> V_211 & V_215 ) {
V_210 = F_65 ( V_216 , & V_209 ) ;
F_63 ( L_27 , V_208 -> V_213 ,
V_208 -> V_211 , V_210 ? L_28 : L_29 ) ;
} else {
V_210 = F_65 ( V_217 , & V_209 ) ;
F_63 ( L_30 , V_208 -> V_213 ,
V_208 -> V_211 , V_210 ? L_28 : L_29 ) ;
}
return V_210 ;
}
if ( V_208 -> V_211 & V_215 ) {
if ( F_58 ( V_208 -> V_218 ) -> V_219 == 0 ) {
V_210 = F_65 ( V_220 , & V_209 ) ;
F_63 ( L_31 , V_208 -> V_213 ,
V_208 -> V_211 , V_210 ? L_28 : L_29 ) ;
return V_210 ;
}
V_210 = F_65 ( V_221 , & V_209 ) ;
F_63 ( L_31 , V_208 -> V_213 ,
V_208 -> V_211 , V_210 ? L_28 : L_29 ) ;
return V_210 ;
}
#ifdef F_17
if ( ! V_208 -> V_222 ) {
V_210 = F_65 ( V_223 , & V_209 ) ;
F_63 ( L_32 , V_208 -> V_213 ,
V_208 -> V_211 , V_210 ? L_28 : L_29 ) ;
return V_210 ;
}
#endif
V_210 = F_65 ( V_224 , & V_209 ) ;
F_63 ( L_33 , V_208 -> V_213 , V_208 -> V_211 ,
V_210 ? L_28 : L_29 ) ;
return V_210 ;
}
static int F_66 ( struct V_225 * V_226 )
{
int V_227 ;
V_227 = sizeof( struct V_228 ) ;
V_227 += F_67 ( strlen ( V_226 -> V_229 ) + 1 , 4 ) ;
V_227 += F_67 ( V_226 -> V_230 , 4 ) ;
return V_227 ;
}
static int F_68 ( struct V_225 * V_231 , struct V_232 * V_233 )
{
struct V_228 V_226 ;
V_226 . V_234 = strlen ( V_231 -> V_229 ) + 1 ;
V_226 . V_235 = V_231 -> V_230 ;
V_226 . V_236 = V_231 -> type ;
return F_69 ( V_233 , & V_226 , sizeof( V_226 ) ) &&
F_69 ( V_233 , V_231 -> V_229 , V_226 . V_234 ) && F_70 ( V_233 , 4 ) &&
F_69 ( V_233 , V_231 -> V_237 , V_231 -> V_230 ) && F_70 ( V_233 , 4 ) ;
}
static inline void F_71 ( struct V_2 * V_238 , int V_177 )
{
memcpy ( V_238 -> V_5 , V_6 , V_7 ) ;
V_238 -> V_5 [ V_239 ] = V_240 ;
V_238 -> V_5 [ V_241 ] = V_242 ;
V_238 -> V_5 [ V_243 ] = V_244 ;
V_238 -> V_5 [ V_245 ] = V_246 ;
memset ( V_238 -> V_5 + V_247 , 0 , V_248 - V_247 ) ;
V_238 -> V_8 = V_249 ;
V_238 -> V_250 = V_251 ;
V_238 -> V_252 = V_244 ;
V_238 -> V_180 = 0 ;
V_238 -> V_21 = sizeof( struct V_2 ) ;
V_238 -> V_253 = 0 ;
V_238 -> V_254 = V_255 ;
V_238 -> V_256 = sizeof( struct V_2 ) ;
V_238 -> V_22 = sizeof( struct V_23 ) ;
V_238 -> V_25 = V_177 ;
V_238 -> V_257 = 0 ;
V_238 -> V_258 = 0 ;
V_238 -> V_259 = 0 ;
return;
}
static inline void F_72 ( struct V_23 * V_16 , int V_227 , T_3 V_260 )
{
V_16 -> V_29 = V_261 ;
V_16 -> V_60 = V_260 ;
V_16 -> V_64 = 0 ;
V_16 -> V_262 = 0 ;
V_16 -> V_57 = V_227 ;
V_16 -> V_37 = 0 ;
V_16 -> V_31 = 0 ;
V_16 -> V_263 = 0 ;
return;
}
static inline void F_73 ( struct V_225 * V_264 , const char * V_229 , int type ,
unsigned int V_227 , void * V_237 )
{
V_264 -> V_229 = V_229 ;
V_264 -> type = type ;
V_264 -> V_230 = V_227 ;
V_264 -> V_237 = V_237 ;
return;
}
static void F_74 ( struct V_265 * V_266 ,
struct V_267 * V_115 , long V_268 )
{
V_266 -> V_269 . V_270 = V_266 -> V_271 = V_268 ;
V_266 -> V_272 = V_115 -> V_273 . signal . V_274 [ 0 ] ;
V_266 -> V_275 = V_115 -> V_276 . V_274 [ 0 ] ;
F_75 () ;
V_266 -> V_277 = F_76 ( F_77 ( V_115 -> V_278 ) ) ;
F_78 () ;
V_266 -> V_279 = F_76 ( V_115 ) ;
V_266 -> V_280 = F_79 ( V_115 ) ;
V_266 -> V_281 = F_80 ( V_115 ) ;
if ( F_81 ( V_115 ) ) {
struct V_282 V_283 ;
F_82 ( V_115 , & V_283 ) ;
V_266 -> V_284 = F_83 ( V_283 . V_285 ) ;
V_266 -> V_286 = F_83 ( V_283 . V_287 ) ;
} else {
T_9 V_285 , V_287 ;
V_282 ( V_115 , & V_285 , & V_287 ) ;
V_266 -> V_284 = F_83 ( V_285 ) ;
V_266 -> V_286 = F_83 ( V_287 ) ;
}
V_266 -> V_288 = F_83 ( V_115 -> signal -> V_289 ) ;
V_266 -> V_290 = F_83 ( V_115 -> signal -> V_291 ) ;
V_266 -> V_292 = V_115 -> V_74 -> V_80 . V_81 ;
V_266 -> V_293 = V_115 -> V_74 -> V_80 . V_82 ;
}
static int F_84 ( struct V_294 * V_295 , struct V_267 * V_115 ,
struct V_102 * V_74 )
{
const struct V_103 * V_103 ;
unsigned int V_50 , V_110 ;
memset ( V_295 , 0 , sizeof( struct V_294 ) ) ;
V_110 = V_74 -> V_165 - V_74 -> V_161 ;
if ( V_110 >= V_296 )
V_110 = V_296 - 1 ;
if ( F_85 ( & V_295 -> V_297 ,
( const char T_5 * ) V_74 -> V_161 , V_110 ) )
return - V_117 ;
for ( V_50 = 0 ; V_50 < V_110 ; V_50 ++ )
if ( V_295 -> V_297 [ V_50 ] == 0 )
V_295 -> V_297 [ V_50 ] = ' ' ;
V_295 -> V_297 [ V_110 ] = 0 ;
F_75 () ;
V_295 -> V_277 = F_76 ( F_77 ( V_115 -> V_278 ) ) ;
F_78 () ;
V_295 -> V_279 = F_76 ( V_115 ) ;
V_295 -> V_280 = F_79 ( V_115 ) ;
V_295 -> V_281 = F_80 ( V_115 ) ;
V_50 = V_115 -> V_298 ? F_86 ( ~ V_115 -> V_298 ) + 1 : 0 ;
V_295 -> V_299 = V_50 ;
V_295 -> V_300 = ( V_50 > 5 ) ? '.' : L_34 [ V_50 ] ;
V_295 -> V_301 = V_295 -> V_300 == 'Z' ;
V_295 -> V_302 = F_87 ( V_115 ) ;
V_295 -> V_303 = V_115 -> V_33 ;
F_75 () ;
V_103 = F_88 ( V_115 ) ;
F_89 ( V_295 -> V_304 , F_49 ( V_103 -> V_149 , V_103 -> V_150 ) ) ;
F_90 ( V_295 -> V_305 , F_50 ( V_103 -> V_149 , V_103 -> V_154 ) ) ;
F_78 () ;
strncpy ( V_295 -> V_306 , V_115 -> V_307 , sizeof( V_295 -> V_306 ) ) ;
return 0 ;
}
static int F_91 ( long V_268 , struct V_308 * V_309 )
{
struct V_267 * V_115 = V_309 -> V_310 ;
int V_227 = 0 ;
V_309 -> V_311 = 0 ;
F_74 ( & V_309 -> V_266 , V_115 , V_268 ) ;
F_92 ( V_115 , & V_309 -> V_266 . V_312 ) ;
F_73 ( & V_309 -> V_313 [ 0 ] , L_35 , V_314 , sizeof( V_309 -> V_266 ) ,
& V_309 -> V_266 ) ;
V_309 -> V_311 ++ ;
V_227 += F_66 ( & V_309 -> V_313 [ 0 ] ) ;
V_309 -> V_266 . V_315 = F_93 ( V_115 , NULL , & V_309 -> V_316 ) ;
if ( V_309 -> V_266 . V_315 ) {
F_73 ( & V_309 -> V_313 [ 1 ] , L_35 , V_317 , sizeof( V_309 -> V_316 ) ,
& V_309 -> V_316 ) ;
V_309 -> V_311 ++ ;
V_227 += F_66 ( & V_309 -> V_313 [ 1 ] ) ;
}
#ifdef F_94
if ( F_95 ( V_115 , & V_309 -> V_318 ) ) {
F_73 ( & V_309 -> V_313 [ 2 ] , L_36 , V_319 ,
sizeof( V_309 -> V_318 ) , & V_309 -> V_318 ) ;
V_309 -> V_311 ++ ;
V_227 += F_66 ( & V_309 -> V_313 [ 2 ] ) ;
}
#endif
return V_227 ;
}
static void F_96 ( struct V_2 * V_238 , struct V_320 * V_321 ,
V_130 V_253 , int V_177 )
{
V_238 -> V_253 = V_253 ;
V_238 -> V_257 = sizeof( * V_321 ) ;
V_238 -> V_258 = 1 ;
V_238 -> V_259 = V_322 ;
memset ( V_321 , 0 , sizeof( * V_321 ) ) ;
V_321 -> V_323 = V_324 ;
V_321 -> V_325 = V_238 -> V_258 ;
V_321 -> V_326 = V_238 -> V_259 ;
V_321 -> V_327 = V_177 ;
}
static bool F_97 ( struct V_232 * V_233 )
{
struct V_207 * V_208 ;
for ( V_208 = V_51 -> V_74 -> V_12 ; V_208 ; V_208 = V_208 -> V_328 ) {
unsigned long V_181 ;
if ( ! F_62 ( V_208 , V_233 -> V_209 ) )
continue;
#ifdef F_17
for ( V_181 = V_208 -> V_213 ; V_181 < V_208 -> V_329 ;
V_181 += V_86 ) {
bool V_330 ;
struct V_331 * V_331 = F_98 ( V_181 ) ;
if ( V_331 ) {
void * V_332 = F_99 ( V_331 ) ;
V_330 = F_69 ( V_233 , V_332 , V_86 ) ;
F_100 ( V_331 ) ;
F_101 ( V_331 ) ;
} else {
V_330 = F_102 ( V_233 , V_86 ) ;
}
if ( ! V_330 )
return false ;
}
#else
if ( ! F_69 ( V_233 , ( void * ) V_208 -> V_213 ,
V_208 -> V_329 - V_208 -> V_213 ) )
return false ;
#endif
}
return true ;
}
static T_6 F_103 ( unsigned long V_209 )
{
struct V_207 * V_208 ;
T_6 V_17 = 0 ;
for ( V_208 = V_51 -> V_74 -> V_12 ; V_208 ; V_208 = V_208 -> V_328 )
if ( F_62 ( V_208 , V_209 ) )
V_17 += V_208 -> V_329 - V_208 -> V_213 ;
return V_17 ;
}
static int F_104 ( struct V_232 * V_233 )
{
#define F_105 6
int V_333 = 0 ;
T_10 V_334 ;
int V_177 ;
int V_50 ;
struct V_207 * V_208 ;
struct V_2 * V_238 = NULL ;
T_3 V_260 = 0 , V_335 ;
int V_336 ;
struct V_225 * V_313 = NULL ;
struct V_265 * V_266 = NULL ;
struct V_294 * V_295 = NULL ;
F_106 ( V_337 ) ;
struct V_338 * V_309 ;
T_11 * V_316 = NULL ;
#ifdef F_94
T_12 * V_318 = NULL ;
#endif
int V_339 = 0 ;
V_130 * V_340 ;
struct V_23 * V_341 = NULL ;
struct V_320 * V_321 = NULL ;
T_13 V_25 ;
V_130 V_253 ;
struct V_342 * V_343 ;
struct V_308 * V_173 ;
V_238 = F_11 ( sizeof( * V_238 ) , V_27 ) ;
if ( ! V_238 )
goto V_344;
V_266 = F_55 ( sizeof( * V_266 ) , V_27 ) ;
if ( ! V_266 )
goto V_344;
V_295 = F_11 ( sizeof( * V_295 ) , V_27 ) ;
if ( ! V_295 )
goto V_344;
V_313 = F_11 ( F_105 * sizeof( struct V_225 ) , V_27 ) ;
if ( ! V_313 )
goto V_344;
V_316 = F_11 ( sizeof( * V_316 ) , V_27 ) ;
if ( ! V_316 )
goto V_344;
#ifdef F_94
V_318 = F_11 ( sizeof( * V_318 ) , V_27 ) ;
if ( ! V_318 )
goto V_344;
#endif
for ( V_343 = V_51 -> V_74 -> V_345 -> V_346 . V_347 ;
V_343 ; V_343 = V_343 -> V_347 ) {
V_173 = F_55 ( sizeof( * V_173 ) , V_27 ) ;
if ( ! V_173 )
goto V_344;
V_173 -> V_310 = V_343 -> V_348 ;
F_107 ( & V_173 -> V_349 , & V_337 ) ;
}
F_108 (t, &thread_list) {
struct V_308 * V_173 ;
int V_227 ;
V_173 = F_109 ( V_309 , struct V_308 , V_349 ) ;
V_227 = F_91 ( V_233 -> V_350 -> V_270 , V_173 ) ;
V_339 += V_227 ;
}
F_74 ( V_266 , V_51 , V_233 -> V_350 -> V_270 ) ;
F_110 ( & V_266 -> V_312 , V_233 -> V_43 ) ;
V_177 = V_51 -> V_74 -> V_351 ;
V_177 += F_111 () ;
V_177 ++ ;
V_25 = V_177 > V_352 ? V_352 : V_177 ;
F_71 ( V_238 , V_25 ) ;
V_333 = 1 ;
F_73 ( V_313 + 0 , L_35 , V_314 , sizeof( * V_266 ) , V_266 ) ;
F_84 ( V_295 , V_51 -> V_353 , V_51 -> V_74 ) ;
F_73 ( V_313 + 1 , L_35 , V_354 , sizeof( * V_295 ) , V_295 ) ;
V_336 = 2 ;
V_340 = ( V_130 * ) V_51 -> V_74 -> V_355 ;
V_50 = 0 ;
do
V_50 += 2 ;
while ( V_340 [ V_50 - 2 ] != V_128 );
F_73 ( & V_313 [ V_336 ++ ] , L_35 , V_356 ,
V_50 * sizeof( V_130 ) , V_340 ) ;
if ( ( V_266 -> V_315 =
F_93 ( V_51 , V_233 -> V_43 , V_316 ) ) )
F_73 ( V_313 + V_336 ++ ,
L_35 , V_317 , sizeof( * V_316 ) , V_316 ) ;
#ifdef F_94
if ( F_95 ( V_51 , V_318 ) )
F_73 ( V_313 + V_336 ++ ,
L_36 , V_319 , sizeof( * V_318 ) , V_318 ) ;
#endif
V_334 = F_112 () ;
F_113 ( V_357 ) ;
V_260 += sizeof( * V_238 ) ;
V_260 += V_177 * sizeof( struct V_23 ) ;
{
int V_227 = 0 ;
for ( V_50 = 0 ; V_50 < V_336 ; V_50 ++ )
V_227 += F_66 ( V_313 + V_50 ) ;
V_227 += V_339 ;
V_341 = F_11 ( sizeof( * V_341 ) , V_27 ) ;
if ( ! V_341 )
goto V_358;
F_72 ( V_341 , V_227 , V_260 ) ;
V_260 += V_227 ;
}
V_335 = V_260 = F_67 ( V_260 , V_359 ) ;
V_260 += F_103 ( V_233 -> V_209 ) ;
V_260 += F_114 () ;
V_253 = V_260 ;
if ( V_25 == V_352 ) {
V_321 = F_11 ( sizeof( * V_321 ) , V_27 ) ;
if ( ! V_321 )
goto V_358;
F_96 ( V_238 , V_321 , V_253 , V_177 ) ;
}
V_260 = V_335 ;
if ( ! F_69 ( V_233 , V_238 , sizeof( * V_238 ) ) )
goto V_358;
if ( ! F_69 ( V_233 , V_341 , sizeof( * V_341 ) ) )
goto V_358;
for ( V_208 = V_51 -> V_74 -> V_12 ; V_208 ; V_208 = V_208 -> V_328 ) {
struct V_23 V_16 ;
T_6 V_227 ;
V_227 = V_208 -> V_329 - V_208 -> V_213 ;
V_16 . V_29 = V_62 ;
V_16 . V_60 = V_260 ;
V_16 . V_64 = V_208 -> V_213 ;
V_16 . V_262 = 0 ;
V_16 . V_57 = F_62 ( V_208 , V_233 -> V_209 ) ? V_227 : 0 ;
V_16 . V_37 = V_227 ;
V_260 += V_16 . V_57 ;
V_16 . V_31 = V_208 -> V_211 & V_214 ? V_199 : 0 ;
if ( V_208 -> V_211 & V_360 )
V_16 . V_31 |= V_200 ;
if ( V_208 -> V_211 & V_91 )
V_16 . V_31 |= V_32 ;
V_16 . V_263 = V_359 ;
if ( ! F_69 ( V_233 , & V_16 , sizeof( V_16 ) ) )
goto V_358;
}
if ( ! F_115 ( V_233 , V_260 ) )
goto V_358;
for ( V_50 = 0 ; V_50 < V_336 ; V_50 ++ )
if ( ! F_68 ( V_313 + V_50 , V_233 ) )
goto V_358;
F_108 (t, &thread_list) {
struct V_308 * V_173 =
F_109 ( V_309 , struct V_308 , V_349 ) ;
for ( V_50 = 0 ; V_50 < V_173 -> V_311 ; V_50 ++ )
if ( ! F_68 ( & V_173 -> V_313 [ V_50 ] , V_233 ) )
goto V_358;
}
if ( ! F_102 ( V_233 , V_335 - V_233 -> V_20 ) )
goto V_358;
if ( ! F_97 ( V_233 ) )
goto V_358;
if ( ! F_116 ( V_233 ) )
goto V_358;
if ( V_25 == V_352 ) {
if ( ! F_69 ( V_233 , V_321 , sizeof( * V_321 ) ) )
goto V_358;
}
if ( V_233 -> V_4 -> V_361 != V_260 ) {
F_31 ( V_362
L_37 ,
V_233 -> V_4 -> V_361 , V_260 ) ;
}
V_358:
F_113 ( V_334 ) ;
V_344:
while ( ! F_117 ( & V_337 ) ) {
struct V_338 * V_173 = V_337 . V_347 ;
F_118 ( V_173 ) ;
F_40 ( F_109 ( V_173 , struct V_308 , V_349 ) ) ;
}
F_40 ( V_341 ) ;
F_40 ( V_238 ) ;
F_40 ( V_266 ) ;
F_40 ( V_295 ) ;
F_40 ( V_313 ) ;
F_40 ( V_316 ) ;
F_40 ( V_321 ) ;
#ifdef F_94
F_40 ( V_318 ) ;
#endif
return V_333 ;
#undef F_105
}
