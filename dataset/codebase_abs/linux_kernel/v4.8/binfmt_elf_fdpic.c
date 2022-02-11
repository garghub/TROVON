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
V_103 &= ~ 15 ;
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
static int F_30 ( struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_101 * V_73 ,
const char * V_166 )
{
struct V_119 * V_100 ;
#ifdef F_17
struct V_120 * V_167 ;
#endif
struct V_120 * V_168 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_169 ;
unsigned V_170 , V_171 ;
T_5 V_17 ;
int V_19 , V_172 ;
V_170 = 0 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ )
if ( V_14 -> V_24 [ V_19 ] . V_28 == V_61 )
V_170 ++ ;
if ( V_170 == 0 )
return - V_65 ;
V_17 = sizeof( * V_100 ) + V_170 * sizeof( * V_168 ) ;
V_100 = F_56 ( V_17 , V_25 ) ;
if ( ! V_100 )
return - V_22 ;
V_14 -> V_100 = V_100 ;
V_100 -> V_173 = V_174 ;
V_100 -> V_121 = V_170 ;
V_62 = V_14 -> V_62 ;
V_168 = V_100 -> V_175 ;
switch ( V_14 -> V_32 & V_176 ) {
case V_64 :
case V_177 :
#ifndef F_17
V_172 = F_57 ( V_14 , V_4 , V_73 ) ;
if ( V_172 < 0 )
return V_172 ;
break;
#endif
default:
V_172 = F_58 ( V_14 , V_4 , V_73 ) ;
if ( V_172 < 0 )
return V_172 ;
break;
}
if ( V_14 -> V_3 . V_178 ) {
V_168 = V_100 -> V_175 ;
for ( V_19 = V_100 -> V_121 ; V_19 > 0 ; V_19 -- , V_168 ++ ) {
if ( V_14 -> V_3 . V_178 >= V_168 -> V_63 &&
V_14 -> V_3 . V_178 < V_168 -> V_63 + V_168 -> V_36 ) {
V_14 -> V_99 =
( V_14 -> V_3 . V_178 - V_168 -> V_63 ) +
V_168 -> V_179 ;
break;
}
}
}
V_169 = V_14 -> V_3 . V_26 ;
V_169 += V_14 -> V_3 . V_23 * sizeof ( struct V_21 ) ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_16 -> V_28 != V_61 )
continue;
if ( V_16 -> V_59 > V_14 -> V_3 . V_26 ||
V_16 -> V_59 + V_16 -> V_56 < V_169 )
continue;
V_168 = V_100 -> V_175 ;
for ( V_19 = V_100 -> V_121 ; V_19 > 0 ; V_19 -- , V_168 ++ ) {
if ( V_16 -> V_63 >= V_168 -> V_63 &&
V_16 -> V_63 + V_16 -> V_56 <=
V_168 -> V_63 + V_168 -> V_36 ) {
V_14 -> V_140 =
( V_16 -> V_63 - V_168 -> V_63 ) +
V_168 -> V_179 +
V_14 -> V_3 . V_26 - V_16 -> V_59 ;
break;
}
}
break;
}
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_16 -> V_28 != V_180 )
continue;
V_168 = V_100 -> V_175 ;
for ( V_19 = V_100 -> V_121 ; V_19 > 0 ; V_19 -- , V_168 ++ ) {
if ( V_16 -> V_63 >= V_168 -> V_63 &&
V_16 -> V_63 + V_16 -> V_36 <=
V_168 -> V_63 + V_168 -> V_36 ) {
V_14 -> V_97 =
( V_16 -> V_63 - V_168 -> V_63 ) +
V_168 -> V_179 ;
if ( V_16 -> V_36 == 0 ||
V_16 -> V_36 % sizeof( V_181 ) != 0 )
goto V_182;
V_171 = V_16 -> V_36 / sizeof( V_181 ) ;
if ( ( ( V_181 * )
V_14 -> V_97 ) [ V_171 - 1 ] . V_183 != 0 )
goto V_182;
break;
}
}
break;
}
#ifdef F_17
V_170 = V_100 -> V_121 ;
V_167 = V_100 -> V_175 ;
V_168 = V_167 + 1 ;
for ( V_19 = 1 ; V_19 < V_170 ; V_19 ++ ) {
if ( V_168 -> V_63 - V_167 -> V_63 == V_168 -> V_179 - V_167 -> V_179 ) {
V_62 = F_34 ( V_167 -> V_179 + V_167 -> V_36 ) ;
if ( V_62 == ( V_168 -> V_179 & V_86 ) ) {
V_167 -> V_36 +=
V_62 -
( V_167 -> V_179 + V_167 -> V_36 ) ;
V_167 -> V_36 += V_168 -> V_179 & ~ V_86 ;
V_167 -> V_36 += V_168 -> V_36 ;
V_100 -> V_121 -- ;
continue;
}
}
V_167 ++ ;
if ( V_167 != V_168 )
* V_167 = * V_168 ;
}
#endif
F_18 ( L_13 , V_166 ) ;
F_18 ( L_14 , V_14 -> V_144 ) ;
F_18 ( L_15 , V_14 -> V_99 ) ;
F_18 ( L_16 , V_14 -> V_140 ) ;
F_18 ( L_17 , V_14 -> V_97 ) ;
V_168 = V_100 -> V_175 ;
for ( V_19 = 0 ; V_19 < V_100 -> V_121 ; V_19 ++ , V_168 ++ )
F_18 ( L_18 ,
V_19 ,
V_168 -> V_179 , V_168 -> V_179 + V_168 -> V_36 - 1 ,
V_168 -> V_63 , V_168 -> V_36 ) ;
return 0 ;
V_182:
F_31 ( L_19 ,
V_166 , F_59 ( V_4 ) -> V_184 ) ;
return - V_65 ;
}
static int F_57 (
struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_101 * V_73 )
{
struct V_120 * V_168 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_185 = V_186 , V_187 = 0 , V_188 = 0 , V_189 ;
int V_19 , V_172 ;
V_62 = V_14 -> V_62 ;
V_168 = V_14 -> V_100 -> V_175 ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_14 -> V_24 [ V_19 ] . V_28 != V_61 )
continue;
if ( V_185 > V_16 -> V_63 )
V_185 = V_16 -> V_63 ;
if ( V_187 < V_16 -> V_63 + V_16 -> V_36 )
V_187 = V_16 -> V_63 + V_16 -> V_36 ;
}
V_189 = V_92 ;
if ( V_14 -> V_32 & V_54 )
V_189 |= V_190 ;
V_188 = F_35 ( NULL , V_62 , V_187 - V_185 ,
V_87 | V_88 | V_91 , V_189 , 0 ) ;
if ( F_36 ( V_188 ) )
return ( int ) V_188 ;
if ( V_62 != 0 )
V_62 += F_34 ( V_187 - V_185 ) ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
if ( V_14 -> V_24 [ V_19 ] . V_28 != V_61 )
continue;
V_168 -> V_179 = V_188 + ( V_16 -> V_63 - V_185 ) ;
V_168 -> V_63 = V_16 -> V_63 ;
V_168 -> V_36 = V_16 -> V_36 ;
V_172 = F_60 ( V_4 , V_168 -> V_179 , V_16 -> V_59 ,
V_16 -> V_56 ) ;
if ( V_172 < 0 )
return V_172 ;
if ( V_16 -> V_59 == 0 )
V_14 -> V_144 = V_168 -> V_179 ;
if ( V_16 -> V_56 < V_16 -> V_36 ) {
if ( F_61 ( ( void * ) ( V_168 -> V_179 + V_16 -> V_56 ) ,
V_16 -> V_36 - V_16 -> V_56 ) )
return - V_116 ;
}
if ( V_73 ) {
if ( V_16 -> V_30 & V_31 ) {
if ( ! V_73 -> V_74 ) {
V_73 -> V_74 = V_168 -> V_179 ;
V_73 -> V_75 = V_168 -> V_179 +
V_16 -> V_36 ;
}
} else if ( ! V_73 -> V_77 ) {
V_73 -> V_77 = V_168 -> V_179 ;
V_73 -> V_78 = V_168 -> V_179 + V_16 -> V_36 ;
}
}
V_168 ++ ;
}
return 0 ;
}
static int F_58 ( struct V_13 * V_14 ,
struct V_4 * V_4 ,
struct V_101 * V_73 )
{
struct V_120 * V_168 ;
struct V_15 * V_16 ;
unsigned long V_62 , V_191 ;
int V_19 , V_192 ;
V_62 = V_14 -> V_62 ;
V_191 = 0 ;
V_192 = 0 ;
V_168 = V_14 -> V_100 -> V_175 ;
V_16 = V_14 -> V_24 ;
for ( V_19 = 0 ; V_19 < V_14 -> V_3 . V_23 ; V_19 ++ , V_16 ++ ) {
unsigned long V_188 , V_193 , V_194 , V_195 ;
int V_196 = 0 , V_32 ;
if ( V_16 -> V_28 != V_61 )
continue;
F_18 ( L_20 ,
( unsigned long ) V_16 -> V_63 ,
( unsigned long ) V_16 -> V_59 ,
( unsigned long ) V_16 -> V_56 ,
( unsigned long ) V_16 -> V_36 ) ;
if ( V_16 -> V_30 & V_197 ) V_196 |= V_87 ;
if ( V_16 -> V_30 & V_198 ) V_196 |= V_88 ;
if ( V_16 -> V_30 & V_31 ) V_196 |= V_91 ;
V_32 = V_92 | V_199 ;
if ( V_14 -> V_32 & V_54 )
V_32 |= V_190 ;
V_188 = 0 ;
switch ( V_14 -> V_32 & V_176 ) {
case V_200 :
break;
case V_201 :
V_188 = V_16 -> V_63 ;
V_32 |= V_202 ;
break;
case V_64 :
if ( ! V_192 ) {
V_188 = V_62 ;
V_191 = V_16 -> V_63 ;
V_192 = 1 ;
} else {
V_188 = V_62 + V_16 -> V_63 - V_191 ;
V_32 |= V_202 ;
}
break;
case V_177 :
break;
default:
F_62 () ;
}
V_188 &= V_86 ;
V_193 = V_16 -> V_63 & ~ V_86 ;
V_188 = F_35 ( V_4 , V_188 , V_16 -> V_36 + V_193 , V_196 , V_32 ,
V_16 -> V_59 - V_193 ) ;
F_18 ( L_21 ,
V_19 , V_16 -> V_36 + V_193 , V_196 , V_32 ,
V_16 -> V_59 - V_193 , V_188 ) ;
if ( F_36 ( V_188 ) )
return ( int ) V_188 ;
if ( ( V_14 -> V_32 & V_176 ) ==
V_177 )
V_62 += F_34 ( V_16 -> V_36 + V_193 ) ;
V_168 -> V_179 = V_188 + V_193 ;
V_168 -> V_63 = V_16 -> V_63 ;
V_168 -> V_36 = V_16 -> V_36 ;
if ( V_16 -> V_59 == 0 )
V_14 -> V_144 = V_168 -> V_179 ;
if ( V_196 & V_88 && V_193 > 0 ) {
F_18 ( L_22 , V_19 , V_188 , V_193 ) ;
if ( F_61 ( ( void T_4 * ) V_188 , V_193 ) )
return - V_116 ;
V_188 += V_193 ;
}
V_194 = V_16 -> V_36 - V_16 -> V_56 ;
V_195 = V_85 - ( ( V_188 + V_16 -> V_56 ) & ~ V_86 ) ;
#ifdef F_17
if ( V_194 > V_195 ) {
unsigned long V_203 = V_188 + V_16 -> V_56 + V_195 ;
unsigned long V_204 ;
V_32 |= V_202 | V_93 ;
V_204 = F_35 ( NULL , V_203 , V_194 - V_195 ,
V_196 , V_32 , 0 ) ;
F_18 ( L_23
L_24 ,
V_19 , V_203 , V_194 - V_195 , V_196 , V_32 ,
V_204 ) ;
if ( V_204 != V_203 )
return - V_22 ;
}
if ( V_196 & V_88 && V_195 > 0 ) {
F_18 ( L_22 ,
V_19 , V_188 + V_16 -> V_56 , V_195 ) ;
if ( F_61 ( ( void T_4 * ) V_188 + V_16 -> V_56 ,
V_195 ) )
return - V_116 ;
}
#else
if ( V_194 > 0 ) {
F_18 ( L_22 ,
V_19 , V_188 + V_16 -> V_56 , V_194 ) ;
if ( F_61 ( ( void * ) V_188 + V_16 -> V_56 , V_194 ) )
return - V_116 ;
}
#endif
if ( V_73 ) {
if ( V_16 -> V_30 & V_31 ) {
if ( ! V_73 -> V_74 ) {
V_73 -> V_74 = V_188 ;
V_73 -> V_75 = V_188 + V_16 -> V_36 ;
}
} else if ( ! V_73 -> V_77 ) {
V_73 -> V_77 = V_188 ;
V_73 -> V_78 = V_188 + V_16 -> V_36 ;
}
}
V_168 ++ ;
}
return 0 ;
}
static int F_63 ( struct V_205 * V_206 , unsigned long V_207 )
{
int V_208 ;
if ( V_206 -> V_209 & V_210 ) {
F_64 ( L_25 , V_206 -> V_211 , V_206 -> V_209 ) ;
return 0 ;
}
if ( ! ( V_206 -> V_209 & V_212 ) ) {
F_64 ( L_26 , V_206 -> V_211 , V_206 -> V_209 ) ;
return 0 ;
}
if ( F_65 ( V_206 ) ) {
if ( V_206 -> V_209 & V_213 ) {
V_208 = F_66 ( V_214 , & V_207 ) ;
F_64 ( L_27 , V_206 -> V_211 ,
V_206 -> V_209 , V_208 ? L_28 : L_29 ) ;
} else {
V_208 = F_66 ( V_215 , & V_207 ) ;
F_64 ( L_30 , V_206 -> V_211 ,
V_206 -> V_209 , V_208 ? L_28 : L_29 ) ;
}
return V_208 ;
}
if ( V_206 -> V_209 & V_213 ) {
if ( F_59 ( V_206 -> V_216 ) -> V_217 == 0 ) {
V_208 = F_66 ( V_218 , & V_207 ) ;
F_64 ( L_31 , V_206 -> V_211 ,
V_206 -> V_209 , V_208 ? L_28 : L_29 ) ;
return V_208 ;
}
V_208 = F_66 ( V_219 , & V_207 ) ;
F_64 ( L_31 , V_206 -> V_211 ,
V_206 -> V_209 , V_208 ? L_28 : L_29 ) ;
return V_208 ;
}
#ifdef F_17
if ( ! V_206 -> V_220 ) {
V_208 = F_66 ( V_221 , & V_207 ) ;
F_64 ( L_32 , V_206 -> V_211 ,
V_206 -> V_209 , V_208 ? L_28 : L_29 ) ;
return V_208 ;
}
#endif
V_208 = F_66 ( V_222 , & V_207 ) ;
F_64 ( L_33 , V_206 -> V_211 , V_206 -> V_209 ,
V_208 ? L_28 : L_29 ) ;
return V_208 ;
}
static int F_67 ( struct V_223 * V_224 )
{
int V_225 ;
V_225 = sizeof( struct V_226 ) ;
V_225 += F_68 ( strlen ( V_224 -> V_227 ) + 1 , 4 ) ;
V_225 += F_68 ( V_224 -> V_228 , 4 ) ;
return V_225 ;
}
static int F_69 ( struct V_223 * V_229 , struct V_230 * V_231 )
{
struct V_226 V_224 ;
V_224 . V_232 = strlen ( V_229 -> V_227 ) + 1 ;
V_224 . V_233 = V_229 -> V_228 ;
V_224 . V_234 = V_229 -> type ;
return F_70 ( V_231 , & V_224 , sizeof( V_224 ) ) &&
F_70 ( V_231 , V_229 -> V_227 , V_224 . V_232 ) && F_71 ( V_231 , 4 ) &&
F_70 ( V_231 , V_229 -> V_235 , V_229 -> V_228 ) && F_71 ( V_231 , 4 ) ;
}
static inline void F_72 ( struct V_2 * V_236 , int V_175 )
{
memcpy ( V_236 -> V_5 , V_6 , V_7 ) ;
V_236 -> V_5 [ V_237 ] = V_238 ;
V_236 -> V_5 [ V_239 ] = V_240 ;
V_236 -> V_5 [ V_241 ] = V_242 ;
V_236 -> V_5 [ V_243 ] = V_244 ;
memset ( V_236 -> V_5 + V_245 , 0 , V_246 - V_245 ) ;
V_236 -> V_8 = V_247 ;
V_236 -> V_248 = V_249 ;
V_236 -> V_250 = V_242 ;
V_236 -> V_178 = 0 ;
V_236 -> V_26 = sizeof( struct V_2 ) ;
V_236 -> V_251 = 0 ;
V_236 -> V_252 = V_253 ;
V_236 -> V_254 = sizeof( struct V_2 ) ;
V_236 -> V_20 = sizeof( struct V_21 ) ;
V_236 -> V_23 = V_175 ;
V_236 -> V_255 = 0 ;
V_236 -> V_256 = 0 ;
V_236 -> V_257 = 0 ;
return;
}
static inline void F_73 ( struct V_21 * V_16 , int V_225 , T_8 V_258 )
{
V_16 -> V_28 = V_259 ;
V_16 -> V_59 = V_258 ;
V_16 -> V_63 = 0 ;
V_16 -> V_260 = 0 ;
V_16 -> V_56 = V_225 ;
V_16 -> V_36 = 0 ;
V_16 -> V_30 = 0 ;
V_16 -> V_261 = 0 ;
return;
}
static inline void F_74 ( struct V_223 * V_262 , const char * V_227 , int type ,
unsigned int V_225 , void * V_235 )
{
V_262 -> V_227 = V_227 ;
V_262 -> type = type ;
V_262 -> V_228 = V_225 ;
V_262 -> V_235 = V_235 ;
return;
}
static void F_75 ( struct V_263 * V_264 ,
struct V_265 * V_114 , long V_266 )
{
V_264 -> V_267 . V_268 = V_264 -> V_269 = V_266 ;
V_264 -> V_270 = V_114 -> V_271 . signal . V_272 [ 0 ] ;
V_264 -> V_273 = V_114 -> V_274 . V_272 [ 0 ] ;
F_76 () ;
V_264 -> V_275 = F_77 ( F_78 ( V_114 -> V_276 ) ) ;
F_79 () ;
V_264 -> V_277 = F_77 ( V_114 ) ;
V_264 -> V_278 = F_80 ( V_114 ) ;
V_264 -> V_279 = F_81 ( V_114 ) ;
if ( F_82 ( V_114 ) ) {
struct V_280 V_281 ;
F_83 ( V_114 , & V_281 ) ;
F_84 ( V_281 . V_282 , & V_264 -> V_283 ) ;
F_84 ( V_281 . V_284 , & V_264 -> V_285 ) ;
} else {
T_9 V_282 , V_284 ;
V_280 ( V_114 , & V_282 , & V_284 ) ;
F_84 ( V_282 , & V_264 -> V_283 ) ;
F_84 ( V_284 , & V_264 -> V_285 ) ;
}
F_84 ( V_114 -> signal -> V_286 , & V_264 -> V_287 ) ;
F_84 ( V_114 -> signal -> V_288 , & V_264 -> V_289 ) ;
V_264 -> V_290 = V_114 -> V_73 -> V_79 . V_80 ;
V_264 -> V_291 = V_114 -> V_73 -> V_79 . V_81 ;
}
static int F_85 ( struct V_292 * V_293 , struct V_265 * V_114 ,
struct V_101 * V_73 )
{
const struct V_102 * V_102 ;
unsigned int V_49 , V_109 ;
memset ( V_293 , 0 , sizeof( struct V_292 ) ) ;
V_109 = V_73 -> V_163 - V_73 -> V_159 ;
if ( V_109 >= V_294 )
V_109 = V_294 - 1 ;
if ( F_86 ( & V_293 -> V_295 ,
( const char T_4 * ) V_73 -> V_159 , V_109 ) )
return - V_116 ;
for ( V_49 = 0 ; V_49 < V_109 ; V_49 ++ )
if ( V_293 -> V_295 [ V_49 ] == 0 )
V_293 -> V_295 [ V_49 ] = ' ' ;
V_293 -> V_295 [ V_109 ] = 0 ;
F_76 () ;
V_293 -> V_275 = F_77 ( F_78 ( V_114 -> V_276 ) ) ;
F_79 () ;
V_293 -> V_277 = F_77 ( V_114 ) ;
V_293 -> V_278 = F_80 ( V_114 ) ;
V_293 -> V_279 = F_81 ( V_114 ) ;
V_49 = V_114 -> V_296 ? F_87 ( ~ V_114 -> V_296 ) + 1 : 0 ;
V_293 -> V_297 = V_49 ;
V_293 -> V_298 = ( V_49 > 5 ) ? '.' : L_34 [ V_49 ] ;
V_293 -> V_299 = V_293 -> V_298 == 'Z' ;
V_293 -> V_300 = F_88 ( V_114 ) ;
V_293 -> V_301 = V_114 -> V_32 ;
F_76 () ;
V_102 = F_89 ( V_114 ) ;
F_90 ( V_293 -> V_302 , F_49 ( V_102 -> V_148 , V_102 -> V_149 ) ) ;
F_91 ( V_293 -> V_303 , F_50 ( V_102 -> V_148 , V_102 -> V_153 ) ) ;
F_79 () ;
strncpy ( V_293 -> V_304 , V_114 -> V_305 , sizeof( V_293 -> V_304 ) ) ;
return 0 ;
}
static int F_92 ( long V_266 , struct V_306 * V_307 )
{
struct V_265 * V_114 = V_307 -> V_308 ;
int V_225 = 0 ;
V_307 -> V_309 = 0 ;
F_75 ( & V_307 -> V_264 , V_114 , V_266 ) ;
F_93 ( V_114 , & V_307 -> V_264 . V_310 ) ;
F_74 ( & V_307 -> V_311 [ 0 ] , L_35 , V_312 , sizeof( V_307 -> V_264 ) ,
& V_307 -> V_264 ) ;
V_307 -> V_309 ++ ;
V_225 += F_67 ( & V_307 -> V_311 [ 0 ] ) ;
V_307 -> V_264 . V_313 = F_94 ( V_114 , NULL , & V_307 -> V_314 ) ;
if ( V_307 -> V_264 . V_313 ) {
F_74 ( & V_307 -> V_311 [ 1 ] , L_35 , V_315 , sizeof( V_307 -> V_314 ) ,
& V_307 -> V_314 ) ;
V_307 -> V_309 ++ ;
V_225 += F_67 ( & V_307 -> V_311 [ 1 ] ) ;
}
#ifdef F_95
if ( F_96 ( V_114 , & V_307 -> V_316 ) ) {
F_74 ( & V_307 -> V_311 [ 2 ] , L_36 , V_317 ,
sizeof( V_307 -> V_316 ) , & V_307 -> V_316 ) ;
V_307 -> V_309 ++ ;
V_225 += F_67 ( & V_307 -> V_311 [ 2 ] ) ;
}
#endif
return V_225 ;
}
static void F_97 ( struct V_2 * V_236 , struct V_318 * V_319 ,
V_129 V_251 , int V_175 )
{
V_236 -> V_251 = V_251 ;
V_236 -> V_255 = sizeof( * V_319 ) ;
V_236 -> V_256 = 1 ;
V_236 -> V_257 = V_320 ;
memset ( V_319 , 0 , sizeof( * V_319 ) ) ;
V_319 -> V_321 = V_322 ;
V_319 -> V_323 = V_236 -> V_256 ;
V_319 -> V_324 = V_236 -> V_257 ;
V_319 -> V_325 = V_175 ;
}
static bool F_98 ( struct V_230 * V_231 )
{
struct V_205 * V_206 ;
for ( V_206 = V_50 -> V_73 -> V_12 ; V_206 ; V_206 = V_206 -> V_326 ) {
unsigned long V_179 ;
if ( ! F_63 ( V_206 , V_231 -> V_207 ) )
continue;
#ifdef F_17
for ( V_179 = V_206 -> V_211 ; V_179 < V_206 -> V_327 ;
V_179 += V_85 ) {
bool V_328 ;
struct V_329 * V_329 = F_99 ( V_179 ) ;
if ( V_329 ) {
void * V_330 = F_100 ( V_329 ) ;
V_328 = F_70 ( V_231 , V_330 , V_85 ) ;
F_101 ( V_329 ) ;
F_102 ( V_329 ) ;
} else {
V_328 = F_103 ( V_231 , V_85 ) ;
}
if ( ! V_328 )
return false ;
}
#else
if ( ! F_70 ( V_231 , ( void * ) V_206 -> V_211 ,
V_206 -> V_327 - V_206 -> V_211 ) )
return false ;
#endif
}
return true ;
}
static T_5 F_104 ( unsigned long V_207 )
{
struct V_205 * V_206 ;
T_5 V_17 = 0 ;
for ( V_206 = V_50 -> V_73 -> V_12 ; V_206 ; V_206 = V_206 -> V_326 )
if ( F_63 ( V_206 , V_207 ) )
V_17 += V_206 -> V_327 - V_206 -> V_211 ;
return V_17 ;
}
static int F_105 ( struct V_230 * V_231 )
{
#define F_106 6
int V_331 = 0 ;
T_10 V_332 ;
int V_175 ;
int V_49 ;
struct V_205 * V_206 ;
struct V_2 * V_236 = NULL ;
T_8 V_258 = 0 , V_333 ;
int V_334 ;
struct V_223 * V_311 = NULL ;
struct V_263 * V_264 = NULL ;
struct V_292 * V_293 = NULL ;
F_107 ( V_335 ) ;
struct V_336 * V_307 ;
T_11 * V_314 = NULL ;
#ifdef F_95
T_12 * V_316 = NULL ;
#endif
int V_337 = 0 ;
V_129 * V_338 ;
struct V_21 * V_339 = NULL ;
struct V_318 * V_319 = NULL ;
T_13 V_23 ;
V_129 V_251 ;
struct V_340 * V_341 ;
struct V_306 * V_171 ;
V_236 = F_11 ( sizeof( * V_236 ) , V_25 ) ;
if ( ! V_236 )
goto V_342;
V_264 = F_56 ( sizeof( * V_264 ) , V_25 ) ;
if ( ! V_264 )
goto V_342;
V_293 = F_11 ( sizeof( * V_293 ) , V_25 ) ;
if ( ! V_293 )
goto V_342;
V_311 = F_11 ( F_106 * sizeof( struct V_223 ) , V_25 ) ;
if ( ! V_311 )
goto V_342;
V_314 = F_11 ( sizeof( * V_314 ) , V_25 ) ;
if ( ! V_314 )
goto V_342;
#ifdef F_95
V_316 = F_11 ( sizeof( * V_316 ) , V_25 ) ;
if ( ! V_316 )
goto V_342;
#endif
for ( V_341 = V_50 -> V_73 -> V_343 -> V_344 . V_345 ;
V_341 ; V_341 = V_341 -> V_345 ) {
V_171 = F_56 ( sizeof( * V_171 ) , V_25 ) ;
if ( ! V_171 )
goto V_342;
V_171 -> V_308 = V_341 -> V_346 ;
F_108 ( & V_171 -> V_347 , & V_335 ) ;
}
F_109 (t, &thread_list) {
struct V_306 * V_171 ;
int V_225 ;
V_171 = F_110 ( V_307 , struct V_306 , V_347 ) ;
V_225 = F_92 ( V_231 -> V_348 -> V_268 , V_171 ) ;
V_337 += V_225 ;
}
F_75 ( V_264 , V_50 , V_231 -> V_348 -> V_268 ) ;
F_111 ( & V_264 -> V_310 , V_231 -> V_42 ) ;
V_175 = V_50 -> V_73 -> V_349 ;
V_175 += F_112 () ;
V_175 ++ ;
V_23 = V_175 > V_350 ? V_350 : V_175 ;
F_72 ( V_236 , V_23 ) ;
V_331 = 1 ;
F_74 ( V_311 + 0 , L_35 , V_312 , sizeof( * V_264 ) , V_264 ) ;
F_85 ( V_293 , V_50 -> V_351 , V_50 -> V_73 ) ;
F_74 ( V_311 + 1 , L_35 , V_352 , sizeof( * V_293 ) , V_293 ) ;
V_334 = 2 ;
V_338 = ( V_129 * ) V_50 -> V_73 -> V_353 ;
V_49 = 0 ;
do
V_49 += 2 ;
while ( V_338 [ V_49 - 2 ] != V_127 );
F_74 ( & V_311 [ V_334 ++ ] , L_35 , V_354 ,
V_49 * sizeof( V_129 ) , V_338 ) ;
if ( ( V_264 -> V_313 =
F_94 ( V_50 , V_231 -> V_42 , V_314 ) ) )
F_74 ( V_311 + V_334 ++ ,
L_35 , V_315 , sizeof( * V_314 ) , V_314 ) ;
#ifdef F_95
if ( F_96 ( V_50 , V_316 ) )
F_74 ( V_311 + V_334 ++ ,
L_36 , V_317 , sizeof( * V_316 ) , V_316 ) ;
#endif
V_332 = F_113 () ;
F_114 ( V_355 ) ;
V_258 += sizeof( * V_236 ) ;
V_258 += V_175 * sizeof( struct V_21 ) ;
{
int V_225 = 0 ;
for ( V_49 = 0 ; V_49 < V_334 ; V_49 ++ )
V_225 += F_67 ( V_311 + V_49 ) ;
V_225 += V_337 ;
V_339 = F_11 ( sizeof( * V_339 ) , V_25 ) ;
if ( ! V_339 )
goto V_356;
F_73 ( V_339 , V_225 , V_258 ) ;
V_258 += V_225 ;
}
V_333 = V_258 = F_68 ( V_258 , V_357 ) ;
V_258 += F_104 ( V_231 -> V_207 ) ;
V_258 += F_115 () ;
V_251 = V_258 ;
if ( V_23 == V_350 ) {
V_319 = F_11 ( sizeof( * V_319 ) , V_25 ) ;
if ( ! V_319 )
goto V_356;
F_97 ( V_236 , V_319 , V_251 , V_175 ) ;
}
V_258 = V_333 ;
if ( ! F_70 ( V_231 , V_236 , sizeof( * V_236 ) ) )
goto V_356;
if ( ! F_70 ( V_231 , V_339 , sizeof( * V_339 ) ) )
goto V_356;
for ( V_206 = V_50 -> V_73 -> V_12 ; V_206 ; V_206 = V_206 -> V_326 ) {
struct V_21 V_16 ;
T_5 V_225 ;
V_225 = V_206 -> V_327 - V_206 -> V_211 ;
V_16 . V_28 = V_61 ;
V_16 . V_59 = V_258 ;
V_16 . V_63 = V_206 -> V_211 ;
V_16 . V_260 = 0 ;
V_16 . V_56 = F_63 ( V_206 , V_231 -> V_207 ) ? V_225 : 0 ;
V_16 . V_36 = V_225 ;
V_258 += V_16 . V_56 ;
V_16 . V_30 = V_206 -> V_209 & V_212 ? V_197 : 0 ;
if ( V_206 -> V_209 & V_358 )
V_16 . V_30 |= V_198 ;
if ( V_206 -> V_209 & V_90 )
V_16 . V_30 |= V_31 ;
V_16 . V_261 = V_357 ;
if ( ! F_70 ( V_231 , & V_16 , sizeof( V_16 ) ) )
goto V_356;
}
if ( ! F_116 ( V_231 , V_258 ) )
goto V_356;
for ( V_49 = 0 ; V_49 < V_334 ; V_49 ++ )
if ( ! F_69 ( V_311 + V_49 , V_231 ) )
goto V_356;
F_109 (t, &thread_list) {
struct V_306 * V_171 =
F_110 ( V_307 , struct V_306 , V_347 ) ;
for ( V_49 = 0 ; V_49 < V_171 -> V_309 ; V_49 ++ )
if ( ! F_69 ( & V_171 -> V_311 [ V_49 ] , V_231 ) )
goto V_356;
}
if ( ! F_103 ( V_231 , V_333 - V_231 -> V_359 ) )
goto V_356;
if ( ! F_98 ( V_231 ) )
goto V_356;
if ( ! F_117 ( V_231 ) )
goto V_356;
if ( V_23 == V_350 ) {
if ( ! F_70 ( V_231 , V_319 , sizeof( * V_319 ) ) )
goto V_356;
}
if ( V_231 -> V_4 -> V_360 != V_258 ) {
F_31 ( V_361
L_37 ,
V_231 -> V_4 -> V_360 , V_258 ) ;
}
V_356:
F_114 ( V_332 ) ;
V_342:
while ( ! F_118 ( & V_335 ) ) {
struct V_336 * V_171 = V_335 . V_345 ;
F_119 ( V_171 ) ;
F_40 ( F_110 ( V_171 , struct V_306 , V_347 ) ) ;
}
F_40 ( V_339 ) ;
F_40 ( V_236 ) ;
F_40 ( V_264 ) ;
F_40 ( V_293 ) ;
F_40 ( V_311 ) ;
F_40 ( V_314 ) ;
F_40 ( V_319 ) ;
#ifdef F_95
F_40 ( V_316 ) ;
#endif
return V_331 ;
#undef F_106
}
