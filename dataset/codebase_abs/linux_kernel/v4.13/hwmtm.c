T_1 F_1 ( void )
{
#ifdef F_2
#ifdef F_3
V_1 ++ ;
if ( V_1 == 1 ) {
return V_2 ;
}
else {
return V_3 ;
}
#else
return V_2 ;
#endif
#else
return 0 ;
#endif
}
int F_4 ( struct V_4 * V_5 )
{
if ( sizeof( struct V_6 ) % 16 ) {
F_5 ( V_5 , V_7 , V_8 ) ;
}
if ( sizeof( struct V_9 ) % 16 ) {
F_5 ( V_5 , V_10 , V_11 ) ;
}
if ( ! ( V_5 -> V_12 . V_13 . V_14 = (union V_15 volatile * )
F_6 ( V_5 , ( T_1 )
( V_16 + 1 ) * sizeof( struct V_9 ) ) ) ) {
return 1 ;
}
#ifndef F_2
V_5 -> V_12 . V_13 . V_17 . V_18 = ( V_19 * ) ( & V_5 -> V_12 . V_13 . V_17 . V_20 [ 0 ] ) ;
#else
#ifndef F_3
if ( ! ( V_5 -> V_12 . V_13 . V_17 . V_18 = ( V_19 * ) F_7 ( V_5 ,
V_21 * sizeof( V_19 ) ) ) ) {
return 1 ;
}
#else
if ( ! V_18 ) {
if ( ! ( V_18 = ( V_19 * ) F_7 ( V_5 ,
V_21 * sizeof( V_19 ) ) ) ) {
return 1 ;
}
}
#endif
#endif
return 0 ;
}
void F_8 ( struct V_4 * V_5 )
{
V_5 -> V_22 . V_23 . V_24 = V_25 | V_26 | V_27 | V_28 | 3 ;
#ifdef F_9
V_5 -> V_22 . V_23 . V_24 |= V_29 | V_30 ;
#endif
V_5 -> V_22 . V_23 . V_31 = V_32 | V_33 ;
#ifdef F_10
V_5 -> V_22 . V_23 . V_34 = V_35 | V_36 ;
#endif
}
static T_2 F_11 ( struct V_4 * V_5 ,
union V_15 volatile * V_37 ,
int V_38 )
{
int V_39 ;
union V_15 volatile * V_40 ;
union V_15 volatile * V_41 ;
T_2 V_42 ;
F_12 ( 3 , L_1 , V_37 ) ;
for ( V_39 = V_38 - 1 , V_40 = V_37 ; V_39 ; V_39 -- ) {
V_41 = V_40 ;
V_40 ++ ;
V_41 -> V_43 . V_44 = F_13 ( V_45 ) ;
V_41 -> V_43 . V_46 = & V_40 -> V_43 ;
V_42 = F_14 ( V_5 , ( void * ) V_40 ) ;
V_41 -> V_43 . V_47 = F_13 ( V_42 ) ;
}
F_12 ( 3 , L_2 , V_40 ) ;
V_40 -> V_43 . V_44 = F_13 ( V_45 ) ;
V_40 -> V_43 . V_46 = & V_37 -> V_43 ;
V_42 = F_14 ( V_5 , ( void * ) V_37 ) ;
V_40 -> V_43 . V_47 = F_13 ( V_42 ) ;
for ( V_39 = V_38 , V_40 = V_37 ; V_39 ; V_39 -- ) {
F_15 ( & V_40 -> V_43 , V_48 ) ;
V_40 ++ ;
}
return V_42 ;
}
static void F_16 ( struct V_4 * V_5 )
{
struct V_9 volatile * V_49 ;
struct V_50 * V_51 ;
T_2 V_42 ;
V_49 = (struct V_9 volatile * ) ( ( char * ) V_5 -> V_12 . V_13 . V_14 +
V_52 * sizeof( struct V_6 ) ) ;
V_51 = V_5 -> V_22 . V_23 . V_53 [ V_54 ] ;
F_12 ( 3 , L_3 , V_55 ) ;
( void ) F_11 ( V_5 , (union V_15 volatile * ) V_49 ,
V_55 ) ;
V_42 = F_17 ( V_49 -> V_56 ) ;
V_49 ++ ;
V_51 -> V_57 = V_51 -> V_58 = V_49 ;
V_49 -- ;
V_51 -> V_59 = V_55 ;
V_51 -> V_60 = 0 ;
F_18 ( F_19 ( V_61 ) , V_42 ) ;
V_49 = (struct V_9 volatile * ) ( ( char * ) V_49 +
V_55 * sizeof( struct V_9 ) ) ;
V_51 = V_5 -> V_22 . V_23 . V_53 [ V_62 ] ;
F_12 ( 3 , L_4 , V_63 ) ;
( void ) F_11 ( V_5 , (union V_15 volatile * ) V_49 ,
V_63 ) ;
V_42 = F_17 ( V_49 -> V_56 ) ;
V_49 ++ ;
V_51 -> V_57 = V_51 -> V_58 = V_49 ;
V_51 -> V_59 = V_63 ;
V_51 -> V_60 = 0 ;
F_18 ( F_19 ( V_64 ) , V_42 ) ;
}
static void F_20 ( struct V_4 * V_5 )
{
struct V_6 volatile * V_49 ;
struct V_65 * V_51 ;
T_2 V_42 ;
V_49 = (struct V_6 volatile * ) V_5 -> V_12 . V_13 . V_14 ;
V_51 = V_5 -> V_22 . V_23 . V_66 [ V_67 ] ;
F_12 ( 3 , L_5 , V_52 ) ;
( void ) F_11 ( V_5 , (union V_15 volatile * ) V_49 ,
V_52 ) ;
V_42 = F_17 ( V_49 -> V_47 ) ;
V_49 ++ ;
V_51 -> V_68 = V_51 -> V_69 = V_49 ;
V_51 -> V_70 = V_52 ;
V_51 -> V_71 = 0 ;
F_18 ( F_19 ( V_72 ) , V_42 ) ;
}
void F_21 ( struct V_4 * V_5 , T_3 * V_73 )
{
V_19 * V_20 ;
int V_39 ;
F_22 ( V_5 , V_73 ) ;
( void ) F_23 ( V_5 ) ;
#ifndef F_3
V_20 = V_5 -> V_12 . V_13 . V_17 . V_18 ;
V_5 -> V_12 . V_13 . V_17 . V_74 = ( V_19 * ) NULL ;
for ( V_39 = 0 ; V_39 < V_21 ; V_39 ++ ) {
V_20 -> V_75 = 1 ;
F_24 ( V_5 , V_20 ) ;
V_20 ++ ;
}
#else
V_20 = V_18 ;
if ( ! V_76 ) {
V_74 = 0 ;
for ( V_39 = 0 ; V_39 < V_21 ; V_39 ++ ) {
V_20 -> V_75 = 1 ;
F_24 ( V_5 , V_20 ) ;
V_20 ++ ;
}
V_76 = TRUE ;
}
#endif
V_5 -> V_12 . V_13 . V_77 = V_5 -> V_12 . V_13 . V_78 = ( V_19 * ) NULL ;
V_5 -> V_12 . V_13 . V_79 = V_5 -> V_12 . V_13 . V_80 = NULL ;
V_5 -> V_12 . V_13 . V_81 = V_5 -> V_12 . V_13 . V_82 = V_5 -> V_12 . V_13 . V_83 = 0 ;
V_5 -> V_12 . V_13 . V_84 = TRUE ;
V_5 -> V_12 . V_13 . V_85 = V_5 -> V_12 . V_13 . V_86 = 0 ;
V_5 -> V_12 . V_13 . V_87 = 0 ;
V_5 -> V_12 . V_13 . V_88 = 0 ;
V_5 -> V_12 . V_13 . V_89 = 0 ;
V_5 -> V_12 . V_13 . V_90 = FALSE ;
V_39 = 16 - ( ( long ) V_5 -> V_12 . V_13 . V_14 & 0xf ) ;
if ( V_39 != 16 ) {
F_12 ( 3 , L_6 , V_39 ) ;
V_5 -> V_12 . V_13 . V_14 = (union V_15 volatile * )
( ( char * ) V_5 -> V_12 . V_13 . V_14 + V_39 ) ;
}
F_12 ( 3 , L_7 , V_5 -> V_12 . V_13 . V_14 ) ;
F_16 ( V_5 ) ;
F_20 ( V_5 ) ;
F_25 ( V_5 ) ;
F_26 ( V_5 ) ;
}
V_19 * F_27 ( struct V_4 * V_5 )
{
register V_19 * V_20 ;
#ifndef F_3
V_20 = V_5 -> V_12 . V_13 . V_17 . V_74 ;
#else
V_20 = V_74 ;
#endif
if ( V_20 ) {
#ifndef F_3
V_5 -> V_12 . V_13 . V_17 . V_74 = V_20 -> V_91 ;
#else
V_74 = V_20 -> V_91 ;
#endif
V_20 -> V_92 = 8 ;
V_20 -> V_75 = 1 ;
}
F_12 ( 3 , L_8 , V_20 ) ;
return V_20 ;
}
void F_24 ( struct V_4 * V_5 , V_19 * V_20 )
{
if ( V_20 ) {
V_20 -> V_75 -- ;
F_12 ( 3 , L_9 , V_20 -> V_75 ) ;
if ( ! V_20 -> V_75 ) {
F_12 ( 3 , L_10 , V_20 ) ;
#ifndef F_3
V_20 -> V_91 = V_5 -> V_12 . V_13 . V_17 . V_74 ;
V_5 -> V_12 . V_13 . V_17 . V_74 = V_20 ;
#else
V_20 -> V_91 = V_74 ;
V_74 = V_20 ;
#endif
}
}
else
F_5 ( V_5 , V_93 , V_94 ) ;
}
void F_28 ( struct V_4 * V_5 )
{
T_2 V_42 ;
if ( V_5 -> V_22 . V_95 != V_96 ) {
F_29 () ;
F_5 ( V_5 , V_97 , V_98 ) ;
return ;
}
V_42 = F_30 ( V_5 , V_5 -> V_22 . V_23 . V_53 [ V_54 ] ) ;
F_18 ( F_19 ( V_61 ) , V_42 ) ;
if ( V_5 -> V_22 . V_23 . V_99 [ V_54 ] . V_60 ) {
F_18 ( F_19 ( V_100 ) , V_101 ) ;
}
V_42 = F_30 ( V_5 , V_5 -> V_22 . V_23 . V_53 [ V_62 ] ) ;
F_18 ( F_19 ( V_64 ) , V_42 ) ;
if ( V_5 -> V_22 . V_23 . V_99 [ V_62 ] . V_60 ) {
F_18 ( F_19 ( V_102 ) , V_101 ) ;
}
V_42 = F_31 ( V_5 , V_5 -> V_22 . V_23 . V_66 [ V_67 ] ) ;
F_18 ( F_19 ( V_72 ) , V_42 ) ;
F_18 ( F_19 ( V_103 ) , V_101 ) ;
}
static T_2 F_30 ( struct V_4 * V_5 , struct V_50 * V_51 )
{
int V_39 ;
int V_60 ;
T_2 V_42 ;
T_2 V_104 ;
struct V_9 volatile * V_105 ;
F_32 ( V_5 ) ;
V_105 = V_51 -> V_58 ;
V_60 = V_51 -> V_60 ;
for ( V_39 = V_60 + V_51 -> V_59 - 1 ; V_39 ; V_39 -- ) {
V_105 = V_105 -> V_106 ;
}
V_42 = F_17 ( V_105 -> V_56 ) ;
V_105 = V_51 -> V_58 ;
while ( V_60 ) {
F_15 ( V_105 , V_107 ) ;
V_104 = F_17 ( V_105 -> V_108 ) ;
if ( V_104 & V_109 ) {
if ( V_104 & V_110 ) {
break ;
}
else {
V_105 -> V_108 &= ~ F_13 ( V_109 ) ;
}
}
V_42 = F_17 ( V_105 -> V_56 ) ;
F_15 ( V_105 , V_48 ) ;
V_105 = V_105 -> V_106 ;
V_60 -- ;
}
return V_42 ;
}
static T_2 F_31 ( struct V_4 * V_5 , struct V_65 * V_51 )
{
int V_39 ;
int V_71 ;
T_2 V_42 ;
T_2 V_111 ;
struct V_6 volatile * V_43 ;
F_32 ( V_5 ) ;
V_43 = V_51 -> V_69 ;
V_71 = V_51 -> V_71 ;
for ( V_39 = V_52 - 1 ; V_39 ; V_39 -- ) {
V_43 = V_43 -> V_46 ;
}
V_42 = F_17 ( V_43 -> V_47 ) ;
V_43 = V_51 -> V_69 ;
while ( V_71 ) {
F_15 ( V_43 , V_107 ) ;
V_111 = F_17 ( V_43 -> V_44 ) ;
if ( V_111 & V_109 ) {
if ( V_111 & V_110 ) {
break ;
}
else {
V_43 -> V_44 &= ~ F_13 ( V_109 ) ;
}
}
V_42 = F_17 ( V_43 -> V_47 ) ;
F_15 ( V_43 , V_48 ) ;
V_43 = V_43 -> V_46 ;
V_71 -- ;
}
return V_42 ;
}
void F_33 ( struct V_4 * V_5 )
{
T_2 V_112 ;
T_4 V_113 , V_114 ;
V_19 * V_20 ;
#ifdef F_34
int V_115 ;
#endif
#ifdef F_35
if ( V_5 -> V_12 . V_13 . V_88 ) {
F_25 ( V_5 ) ;
if ( V_5 -> V_22 . V_23 . V_116 [ V_67 ] . V_71 > 0 ) {
V_5 -> V_12 . V_13 . V_88 = 0 ;
F_36 ( V_5 ) ;
}
else {
V_5 -> V_12 . V_13 . V_87 = 0 ;
F_37 ( V_5 ) ;
}
}
#endif
V_5 -> V_12 . V_13 . V_90 = TRUE ;
#ifdef F_34
V_115 = TRUE ;
if ( V_5 -> V_12 . V_13 . V_117 ) {
V_5 -> V_12 . V_13 . V_117 = FALSE ;
F_36 ( V_5 ) ;
}
#endif
while ( ( V_112 = F_38 () & V_118 ) ) {
F_39 ( L_11 , V_112 , 0 , 0 ) ;
F_12 ( 7 , L_12 , V_112 ) ;
if ( V_112 & V_119 ) {
F_39 ( L_13 , V_112 , 0 , 0 ) ;
if ( V_112 & V_120 ) {
F_40 ( V_5 ) ;
}
if ( V_112 & V_121 ) {
F_41 ( V_5 ) ;
}
if ( V_112 & V_122 ) {
V_113 = F_42 ( F_43 ( V_123 ) ) ;
V_114 = F_42 ( F_43 ( V_124 ) ) ;
F_12 ( 6 , L_14 ) ;
F_44 ( V_5 , V_113 , V_114 ) ;
}
if ( V_112 & V_125 ) {
V_113 = F_42 ( F_43 ( V_126 ) ) ;
V_114 = F_42 ( F_43 ( V_127 ) ) ;
F_12 ( 6 , L_15 ) ;
F_12 ( 7 , L_16 , V_114 , V_113 ) ;
F_45 ( V_5 , V_113 , V_114 ) ;
}
if ( V_112 & V_128 ) {
V_113 = F_42 ( F_43 ( V_129 ) ) ;
V_114 = F_42 ( F_43 ( V_130 ) ) ;
F_12 ( 6 , L_17 ) ;
F_46 ( V_5 , V_113 , V_114 ) ;
}
if ( V_112 & V_131 ) {
F_47 ( V_5 ) ;
#ifdef F_48
V_132 = 0 ;
#endif
if ( ++ V_5 -> V_12 . V_13 . V_87 > 4 ) {
F_36 ( V_5 ) ;
}
}
if ( V_112 & V_133 ) {
F_49 ( V_5 ) ;
}
if ( V_112 & V_134 ) {
F_18 ( F_19 ( V_135 ) , V_136 ) ;
F_5 ( V_5 , V_137 , V_138 ) ;
}
if ( V_112 & V_139 ) {
F_18 ( F_19 ( V_135 ) , V_140 ) ;
F_5 ( V_5 , V_141 , V_142 ) ;
}
if ( V_112 & V_143 ) {
F_18 ( F_19 ( V_144 ) , V_140 ) ;
F_5 ( V_5 , V_145 , V_146 ) ;
}
if ( V_112 & V_147 ) {
F_18 ( F_19 ( V_148 ) , V_140 ) ;
F_5 ( V_5 , V_149 , V_150 ) ;
}
}
if ( V_112 & ( V_151 | V_152 ) ) {
F_12 ( 6 , L_18 ) ;
F_18 ( F_19 ( V_148 ) , V_153 ) ;
F_18 ( F_19 ( V_144 ) , V_153 ) ;
F_50 ( V_5 ) ;
F_51 ( V_5 ) ;
}
if ( V_112 & V_154 ) {
F_12 ( 6 , L_19 ) ;
#ifndef F_34
F_18 ( F_19 ( V_135 ) , V_153 ) ;
F_36 ( V_5 ) ;
#else
F_36 ( V_5 ) ;
if ( V_5 -> V_12 . V_13 . V_117 ) {
V_115 = FALSE ;
} else {
F_18 ( F_19 ( V_135 ) , V_153 ) ;
F_36 ( V_5 ) ;
}
#endif
}
#ifndef F_48
while ( ( V_20 = F_52 ( V_5 ) ) ) {
F_53 ( V_5 , V_20 ) ;
}
#else
if ( V_155 )
F_54 () ;
while ( ! V_155 && ( V_20 = F_52 ( V_5 ) ) ) {
F_53 ( V_5 , V_20 ) ;
}
if ( ! V_155 && V_5 -> V_12 . V_13 . V_88 ) {
F_36 ( V_5 ) ;
}
#endif
if ( V_5 -> V_156 . V_157 != V_5 -> V_156 . V_158 ) {
F_39 ( L_20 , 0 , 0 , 0 ) ;
F_55 ( V_5 ) ;
}
#ifdef F_48
F_54 () ;
if ( V_155 ) {
break ;
}
#endif
#ifdef F_34
if ( V_5 -> V_12 . V_13 . V_117 ) {
break ;
}
#endif
}
#ifdef F_34
if ( V_5 -> V_12 . V_13 . V_117 && V_115 ) {
F_37 ( V_5 ) ;
}
#endif
V_5 -> V_12 . V_13 . V_90 = FALSE ;
F_39 ( L_21 , 0 , 0 , 0 ) ;
}
void F_56 ( struct V_4 * V_5 , int V_159 )
{
switch( V_159 ) {
case V_160 :
V_5 -> V_12 . V_13 . V_81 = TRUE ;
break ;
case V_161 :
V_5 -> V_12 . V_13 . V_81 = FALSE ;
break ;
case V_162 :
V_5 -> V_12 . V_13 . V_82 = TRUE ;
break ;
case V_163 :
V_5 -> V_12 . V_13 . V_82 = FALSE ;
break ;
case V_164 :
V_5 -> V_12 . V_13 . V_83 = TRUE ;
break ;
case V_165 :
V_5 -> V_12 . V_13 . V_83 = FALSE ;
break ;
case V_166 :
V_5 -> V_12 . V_13 . V_81 = V_5 -> V_12 . V_13 . V_82 = FALSE ;
V_5 -> V_12 . V_13 . V_83 = FALSE ;
V_5 -> V_12 . V_13 . V_84 = TRUE ;
F_57 ( V_5 , V_167 ) ;
break ;
case V_168 :
V_5 -> V_12 . V_13 . V_84 = FALSE ;
break ;
case V_169 :
V_5 -> V_12 . V_13 . V_84 = TRUE ;
break ;
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_167 :
default:
F_57 ( V_5 , V_159 ) ;
break ;
}
}
void F_36 ( struct V_4 * V_5 )
{
int V_39 ;
int V_175 ;
int V_176 ;
int V_177 ;
struct V_65 * V_51 ;
struct V_6 volatile * V_43 ;
struct V_6 volatile * V_178 ;
T_2 V_111 ;
T_2 V_179 ;
T_4 V_71 ;
T_3 T_5 * V_180 ;
char T_5 * V_181 ;
V_19 * V_20 ;
T_3 V_182 ;
int V_183 ;
V_5 -> V_12 . V_13 . V_87 = 0 ;
V_51 = V_5 -> V_22 . V_23 . V_66 [ V_67 ] ;
F_39 ( L_22 , 0 , 0 , 0 ) ;
for ( ; ; ) {
V_43 = V_51 -> V_69 ;
V_71 = V_51 -> V_71 ;
V_176 = 0 ;
#ifdef F_34
if ( V_5 -> V_12 . V_13 . V_117 ) {
goto V_184 ;
}
#endif
#ifdef F_48
if ( V_155 ) {
V_5 -> V_12 . V_13 . V_88 = 1 ;
goto V_184 ;
}
V_5 -> V_12 . V_13 . V_88 = 0 ;
#endif
#ifdef F_35
if ( V_5 -> V_12 . V_13 . V_88 ) {
goto V_184 ;
}
#endif
V_175 = 0 ;
do {
F_58 ( 5 , L_23 , V_43 ) ;
F_15 ( V_43 , V_107 ) ;
V_111 = F_17 ( F_59 ( V_43 -> V_44 ) ) ;
if ( V_111 & V_109 ) {
F_39 ( L_24 , V_43 , V_179 , V_111 ) ;
F_58 ( 4 , L_25 ) ;
goto V_184 ;
}
if ( ! V_71 ) {
F_29 () ;
F_5 ( V_5 , V_185 , V_186 ) ;
V_5 -> V_22 . V_95 = V_96 ;
F_60 ( V_5 ) ;
V_5 -> V_22 . V_95 = V_187 ;
F_25 ( V_5 ) ;
V_5 -> V_12 . V_13 . V_87 = 0 ;
goto V_184 ;
}
V_179 = F_17 ( V_43 -> V_188 ) ;
if ( ( V_111 & V_110 ) != ( ( V_111 & V_189 ) << 5 ) ) {
F_29 () ;
V_179 = 0 ;
if ( V_176 ) {
break ;
}
}
V_175 += V_111 & 0xffff ;
V_43 = V_43 -> V_46 ;
V_176 ++ ;
V_71 -- ;
} while ( ! ( V_111 & V_190 ) ) ;
V_177 = V_176 ;
F_58 ( 5 , L_26 , V_177 ) ;
F_15 ( V_43 , V_107 ) ;
while ( V_71 && ! ( V_43 -> V_44 & F_13 ( V_189 ) ) ) {
F_58 ( 5 , L_27 , V_43 ) ;
V_43 = V_43 -> V_46 ;
F_15 ( V_43 , V_107 ) ;
V_176 ++ ;
V_71 -- ;
}
F_58 ( 5 , L_28 ) ;
V_178 = V_51 -> V_69 ;
V_51 -> V_69 = V_43 ;
V_51 -> V_70 += V_176 ;
V_51 -> V_71 = V_71 ;
V_178 -> V_44 &= F_13 ( ~ V_110 ) ;
for ( V_43 = V_178 , V_39 = V_176 ; V_39 ; V_43 = V_43 -> V_46 , V_39 -- ) {
F_58 ( 5 , L_29 , V_43 ) ;
F_61 ( V_5 , (union V_15 volatile * ) V_43 , V_191 ) ;
}
V_5 -> V_22 . V_23 . V_192 . V_193 ++ ;
V_5 -> V_194 . V_195 [ V_196 ] . V_197 ++ ;
V_183 = ( V_179 & V_198 ) - 4 ;
F_58 ( 4 , L_30 , V_183 ) ;
if ( V_179 & ( V_199 | V_200 | V_201 | V_202 ) ) {
if ( V_179 & V_203 ) {
F_58 ( 2 , L_31 ) ;
V_5 -> V_22 . V_23 . V_192 . V_204 ++ ;
}
if ( V_179 & V_205 ) {
F_58 ( 2 , L_32 ) ;
V_5 -> V_22 . V_23 . V_192 . V_206 ++ ;
}
if ( V_179 & V_207 ) {
F_58 ( 2 , L_33 ) ;
V_5 -> V_22 . V_23 . V_192 . V_208 ++ ;
}
if ( V_179 & V_202 ) {
F_58 ( 2 , L_34 ) ;
V_5 -> V_22 . V_23 . V_192 . V_209 ++ ;
}
goto V_210 ;
}
if ( V_183 > V_211 - 4 ) {
F_58 ( 2 , L_35 ) ;
V_5 -> V_22 . V_23 . V_192 . V_212 ++ ;
goto V_210 ;
}
if ( V_183 <= 4 ) {
F_58 ( 2 , L_36 ) ;
goto V_210 ;
}
if ( V_183 != ( V_175 - 4 ) ) {
F_58 ( 4 , L_37 , V_183 , V_175 ) ;
V_5 -> V_12 . V_13 . V_89 ++ ;
goto V_210 ;
}
V_180 = ( T_3 T_5 * ) V_178 -> V_213 ;
F_58 ( 2 , L_38 , * V_180 ) ;
if ( V_180 [ 12 ] == V_214 [ 5 ] &&
V_180 [ 11 ] == V_214 [ 4 ] &&
V_180 [ 10 ] == V_214 [ 3 ] &&
V_180 [ 9 ] == V_214 [ 2 ] &&
V_180 [ 8 ] == V_214 [ 1 ] &&
( V_180 [ 7 ] & ~ V_215 ) == V_214 [ 0 ] ) {
goto V_210 ;
}
if ( V_179 & V_216 ) {
if ( ! V_5 -> V_12 . V_13 . V_84 ) {
if( ! ( V_180 [ 1 ] & V_215 ) ) {
if ( V_180 [ 6 ] != V_214 [ 5 ] ||
V_180 [ 5 ] != V_214 [ 4 ] ||
V_180 [ 4 ] != V_214 [ 3 ] ||
V_180 [ 3 ] != V_214 [ 2 ] ||
V_180 [ 2 ] != V_214 [ 1 ] ||
V_180 [ 1 ] != V_214 [ 0 ] ) {
F_58 ( 2 , L_39 ) ;
goto V_210 ;
}
}
}
F_58 ( 4 , L_40 ) ;
F_62 ( V_5 , V_178 , V_176 , V_183 ) ;
}
else {
if ( ! ( V_20 = F_27 ( V_5 ) ) ) {
V_5 -> V_22 . V_23 . V_192 . V_217 ++ ;
F_58 ( 4 , L_41 ) ;
goto V_210 ;
}
V_181 = F_63 ( V_20 , char * ) - 1 ;
#ifdef F_64
F_65 ( V_178 , V_181 , V_183 ) ;
#else
for ( V_43 = V_178 , V_39 = V_177 ; V_39 ; V_43 = V_43 -> V_46 , V_39 -- ) {
V_175 = F_17 ( V_43 -> V_44 ) & V_198 ;
F_58 ( 6 , L_42 , V_175 ) ;
memcpy ( V_181 , V_43 -> V_213 , V_175 ) ;
V_181 += V_175 ;
}
V_181 = F_63 ( V_20 , char * ) - 1 ;
#endif
V_182 = * ( char * ) V_20 -> V_218 = * V_181 ;
V_20 -> V_219 = V_183 - 1 ;
V_181 ++ ;
switch( V_182 ) {
case V_220 :
V_5 -> V_22 . V_23 . V_192 . V_221 ++ ;
F_58 ( 5 , L_43 ) ;
if ( V_5 -> V_12 . V_13 . V_81 ) {
F_58 ( 5 , L_44 ) ;
F_62 ( V_5 , V_178 ,
V_176 , V_183 ) ;
}
else {
F_58 ( 5 , L_45 ) ;
F_66 ( V_5 , V_178 , V_176 ) ;
}
F_67 ( V_5 , V_20 , ( int ) ( V_179 >> 25 ) ) ;
break ;
case V_222 :
V_5 -> V_22 . V_23 . V_192 . V_221 ++ ;
F_58 ( 5 , L_43 ) ;
if ( V_5 -> V_12 . V_13 . V_82 ||
( V_5 -> V_12 . V_13 . V_81 &&
! ( V_179 & V_223 ) ) ) {
F_58 ( 5 , L_44 ) ;
F_62 ( V_5 , V_178 ,
V_176 , V_183 ) ;
}
else {
F_58 ( 5 , L_45 ) ;
F_66 ( V_5 , V_178 , V_176 ) ;
}
F_67 ( V_5 , V_20 , ( int ) ( V_179 >> 25 ) ) ;
break ;
case V_224 :
if ( V_5 -> V_12 . V_13 . V_83 ) {
F_58 ( 5 , L_46 ) ;
F_62 ( V_5 , V_178 ,
V_176 , V_183 ) ;
}
else {
F_58 ( 5 , L_45 ) ;
F_66 ( V_5 , V_178 , V_176 ) ;
}
F_24 ( V_5 , V_20 ) ;
break ;
default :
F_58 ( 2 , L_47 ) ;
F_24 ( V_5 , V_20 ) ;
F_58 ( 5 , L_45 ) ;
F_66 ( V_5 , V_178 , V_176 ) ;
if ( ( V_182 & 0xf0 ) == V_225 )
V_5 -> V_22 . V_23 . V_192 . V_226 ++ ;
else
V_5 -> V_22 . V_23 . V_192 . V_209 ++ ;
break ;
}
}
F_58 ( 3 , L_48 , V_51 -> V_69 ) ;
F_39 ( L_49 , V_51 -> V_69 , 0 , 0 ) ;
continue ;
V_210:
F_58 ( 5 , L_45 ) ;
F_66 ( V_5 , V_178 , V_176 ) ;
F_58 ( 3 , L_48 , V_51 -> V_69 ) ;
F_39 ( L_50 , V_51 -> V_69 , 0 , 0 ) ;
}
V_184:
#ifdef F_68
F_69 ( V_5 ) ;
#endif
return ;
}
static void F_53 ( struct V_4 * V_5 , V_19 * V_20 )
{
T_3 V_182 ;
F_58 ( 4 , L_51 ) ;
V_5 -> V_12 . V_13 . V_43 . V_183 = V_20 -> V_219 ;
V_5 -> V_12 . V_13 . V_43 . V_227 = F_63 ( V_20 , char * ) ;
V_182 = * V_5 -> V_12 . V_13 . V_43 . V_227 ;
( void ) F_70 ( V_5 , ( int ) V_20 -> V_219 , ( int ) V_182 ,
V_5 -> V_12 . V_13 . V_43 . V_227 , ( int ) V_20 -> V_219 ) ;
F_24 ( V_5 , V_20 ) ;
}
void F_71 ( struct V_4 * V_5 , char T_5 * V_180 , T_2 V_42 , int V_183 ,
int V_228 )
{
struct V_6 volatile * V_43 ;
T_6 V_111 ;
F_39 ( L_52 , V_180 , V_183 , V_228 ) ;
F_58 ( 2 , L_53 , V_183 , V_228 ) ;
V_43 = V_5 -> V_22 . V_23 . V_116 [ V_67 ] . V_68 ;
V_43 -> V_213 = V_180 ;
V_43 -> V_229 = F_13 ( V_42 ) ;
V_111 = F_13 ( ( ( ( V_230 ) V_228 &
( V_231 | V_232 ) ) << 26 ) |
( ( ( T_2 ) V_228 & V_231 ) << 21 ) |
V_109 | V_45 | V_233 | V_183 ) ;
V_43 -> V_44 = V_111 ;
F_15 ( V_43 , V_48 ) ;
F_18 ( F_19 ( V_103 ) , V_101 ) ;
V_5 -> V_22 . V_23 . V_116 [ V_67 ] . V_70 -- ;
V_5 -> V_22 . V_23 . V_116 [ V_67 ] . V_71 ++ ;
V_5 -> V_22 . V_23 . V_116 [ V_67 ] . V_68 = V_43 -> V_46 ;
F_39 ( L_54 , V_43 , F_17 ( V_43 -> V_229 ) , 0 ) ;
}
void F_60 ( struct V_4 * V_5 )
{
struct V_6 volatile * V_43 ;
struct V_6 volatile * V_234 ;
struct V_65 * V_51 ;
int V_176 ;
int V_39 ;
if ( V_5 -> V_22 . V_95 != V_96 ) {
F_29 () ;
F_5 ( V_5 , V_235 , V_236 ) ;
return ;
}
V_51 = V_5 -> V_22 . V_23 . V_66 [ V_67 ] ;
F_58 ( 5 , L_55 ) ;
V_43 = V_51 -> V_69 ;
while ( V_51 -> V_71 ) {
F_15 ( V_43 , V_107 ) ;
F_58 ( 5 , L_56 , V_43 ) ;
V_43 -> V_44 &= ~ F_13 ( V_109 ) ;
V_176 = 1 ;
F_15 ( V_43 , V_48 ) ;
V_43 = V_43 -> V_46 ;
F_15 ( V_43 , V_107 ) ;
while ( V_43 != V_51 -> V_68 &&
! ( V_43 -> V_44 & F_13 ( V_189 ) ) ) {
F_58 ( 5 , L_27 , V_43 ) ;
V_43 -> V_44 &= ~ F_13 ( V_109 ) ;
F_15 ( V_43 , V_48 ) ;
V_43 = V_43 -> V_46 ;
F_15 ( V_43 , V_107 ) ;
V_176 ++ ;
}
F_58 ( 5 , L_28 ) ;
V_234 = V_43 ;
for ( V_43 = V_51 -> V_69 , V_39 = V_176 ; V_39 ; V_43 = V_43 -> V_46 , V_39 -- ) {
F_58 ( 5 , L_29 , V_43 ) ;
F_61 ( V_5 , (union V_15 volatile * ) V_43 , V_191 ) ;
}
F_58 ( 5 , L_57 ,
V_51 -> V_69 , V_176 ) ;
F_72 ( V_5 , V_51 -> V_69 , V_176 ) ;
V_51 -> V_69 = V_234 ;
V_51 -> V_71 -= V_176 ;
V_51 -> V_70 += V_176 ;
}
}
int F_73 ( struct V_4 * V_5 , T_3 V_182 , int V_176 , int V_237 ,
int V_228 )
{
F_39 ( L_58 , V_182 , V_176 , V_237 ) ;
V_5 -> V_12 . V_13 . V_238 = V_5 -> V_22 . V_23 . V_53 [ V_228 & V_54 ] ;
V_5 -> V_12 . V_13 . V_239 = V_240 | ( ( ( T_2 ) ( V_237 - 1 ) & 3 ) << 27 ) ;
V_5 -> V_12 . V_13 . V_241 = V_237 ;
F_74 ( 3 , L_59 , V_182 , V_237 ) ;
if ( ( V_182 & ~ ( V_242 | V_243 ) ) == V_244 ) {
V_228 |= V_245 ;
}
else {
switch ( V_182 ) {
case V_220 :
case V_222 :
V_228 |= V_245 ;
break ;
case V_246 :
V_228 |= V_247 ;
break ;
case V_248 :
V_228 |= V_245 | V_247 ;
break ;
default :
F_5 ( V_5 , V_249 , V_250 ) ;
}
}
if ( ! V_5 -> V_22 . V_251 ) {
V_228 &= ~ V_245 ;
V_228 |= V_252 ;
F_74 ( 2 , L_60 ) ;
}
if ( V_176 > V_5 -> V_12 . V_13 . V_238 -> V_59 ) {
#ifndef F_48
F_50 ( V_5 ) ;
if ( V_176 > V_5 -> V_12 . V_13 . V_238 -> V_59 ) {
F_74 ( 2 , L_61 ) ;
V_228 &= ~ V_245 ;
V_228 |= V_253 ;
}
#else
F_74 ( 2 , L_61 ) ;
V_228 &= ~ V_245 ;
V_228 |= V_253 ;
#endif
}
F_74 ( 3 , L_62 , V_228 ) ;
F_39 ( L_63 , V_228 , V_5 -> V_12 . V_13 . V_238 -> V_59 , 0 ) ;
return V_228 ;
}
void F_75 ( struct V_4 * V_5 , char T_5 * V_180 , T_2 V_42 , int V_183 ,
int V_228 )
{
struct V_9 volatile * V_105 ;
struct V_50 * V_51 ;
T_6 V_104 ;
V_51 = V_5 -> V_12 . V_13 . V_238 ;
F_39 ( L_64 , V_180 , V_183 , V_228 ) ;
V_105 = V_51 -> V_57 ;
F_74 ( 2 , L_65 , V_183 , V_228 ) ;
if ( V_228 & V_245 ) {
F_74 ( 3 , L_66 , V_105 , V_180 ) ;
V_105 -> V_254 = V_180 ;
V_105 -> V_255 = F_13 ( V_5 -> V_12 . V_13 . V_239 ) ;
V_105 -> V_256 = F_13 ( V_42 ) ;
V_104 = F_13 ( ( ( ( V_230 ) V_228 &
( V_231 | V_232 | V_257 ) ) << 26 ) |
V_109 | V_45 | V_183 ) ;
V_105 -> V_108 = V_104 ;
#ifndef F_76
F_15 ( V_105 , V_48 ) ;
F_18 ( V_51 -> V_258 , V_101 ) ;
#else
F_15 ( V_105 , V_48 ) ;
if ( V_228 & V_54 ) {
F_18 ( F_19 ( V_100 ) , V_101 ) ;
}
else {
F_18 ( F_19 ( V_102 ) , V_101 ) ;
}
#endif
V_51 -> V_59 -- ;
V_51 -> V_60 ++ ;
V_51 -> V_57 = V_105 -> V_106 ;
if ( V_228 & V_232 ) {
V_5 -> V_194 . V_195 [ V_196 ] . V_259 ++ ;
}
}
if ( V_228 & V_247 ) {
F_74 ( 3 , L_67 ) ;
if ( V_228 & V_231 ) {
if( ! ( V_5 -> V_12 . V_13 . V_260 = F_27 ( V_5 ) ) ) {
V_5 -> V_22 . V_23 . V_192 . V_217 ++ ;
F_74 ( 4 , L_68 ) ;
}
else {
V_5 -> V_12 . V_13 . V_261 =
F_63 ( V_5 -> V_12 . V_13 . V_260 , char * ) - 1 ;
#ifdef F_64
#ifdef F_77
F_78 ( V_105 , V_5 -> V_12 . V_13 . V_261 ,
V_5 -> V_12 . V_13 . V_241 ) ;
#endif
#endif
}
}
if ( V_5 -> V_12 . V_13 . V_260 ) {
#ifndef F_64
F_74 ( 3 , L_69 ) ;
memcpy ( V_5 -> V_12 . V_13 . V_261 , V_180 , V_183 ) ;
V_5 -> V_12 . V_13 . V_261 += V_183 ;
#endif
if ( V_228 & V_232 ) {
#ifdef F_64
#ifndef F_77
F_78 ( V_105 , V_5 -> V_12 . V_13 . V_261 ,
V_5 -> V_12 . V_13 . V_241 ) ;
#endif
#endif
V_5 -> V_12 . V_13 . V_261 =
F_63 ( V_5 -> V_12 . V_13 . V_260 , char * ) - 1 ;
* ( char * ) V_5 -> V_12 . V_13 . V_260 -> V_218 =
* V_5 -> V_12 . V_13 . V_261 ;
V_5 -> V_12 . V_13 . V_261 ++ ;
V_5 -> V_12 . V_13 . V_260 -> V_219 =
V_5 -> V_12 . V_13 . V_241 - 1 ;
F_74 ( 3 , L_70 ) ;
F_67 ( V_5 , V_5 -> V_12 . V_13 . V_260 ,
V_262 ) ;
}
}
}
F_39 ( L_71 , V_105 , V_51 -> V_59 , 0 ) ;
}
static void F_79 ( struct V_4 * V_5 , V_19 * V_20 )
{
F_12 ( 4 , L_72 , V_20 ) ;
V_5 -> V_12 . V_13 . V_85 ++ ;
V_20 -> V_91 = ( V_19 * ) NULL ;
if ( V_5 -> V_12 . V_13 . V_77 == NULL ) {
V_5 -> V_12 . V_13 . V_77 = V_20 ;
}
else {
V_5 -> V_12 . V_13 . V_78 -> V_91 = V_20 ;
}
V_5 -> V_12 . V_13 . V_78 = V_20 ;
if ( ! V_5 -> V_12 . V_13 . V_90 ) {
F_37 ( V_5 ) ;
}
}
static V_19 * F_52 ( struct V_4 * V_5 )
{
V_19 * V_20 ;
if ( ( V_20 = V_5 -> V_12 . V_13 . V_77 ) ) {
V_5 -> V_12 . V_13 . V_85 -- ;
V_5 -> V_12 . V_13 . V_77 = V_20 -> V_91 ;
}
F_12 ( 4 , L_73 , V_20 ) ;
return V_20 ;
}
static void F_80 ( struct V_4 * V_5 , V_19 * V_20 )
{
F_12 ( 4 , L_74 , V_20 ) ;
V_5 -> V_12 . V_13 . V_86 ++ ;
V_20 -> V_91 = ( V_19 * ) NULL ;
if ( V_5 -> V_12 . V_13 . V_79 == NULL ) {
V_5 -> V_12 . V_13 . V_79 = V_20 ;
}
else {
V_5 -> V_12 . V_13 . V_80 -> V_91 = V_20 ;
}
V_5 -> V_12 . V_13 . V_80 = V_20 ;
}
static V_19 * F_81 ( struct V_4 * V_5 )
{
V_19 * V_20 ;
if ( ( V_20 = V_5 -> V_12 . V_13 . V_79 ) ) {
V_5 -> V_12 . V_13 . V_86 -- ;
V_5 -> V_12 . V_13 . V_79 = V_20 -> V_91 ;
}
F_12 ( 4 , L_75 , V_20 ) ;
return V_20 ;
}
void F_82 ( struct V_4 * V_5 , V_19 * V_20 , int V_182 )
{
char T_5 * V_181 ;
int V_183 ;
int V_175 ;
int V_39 ;
int V_176 ;
int V_228 ;
F_83 (char far,*virt[3]) ;
int V_263 [ 3 ] ;
struct V_50 * V_51 ;
struct V_9 volatile * V_105 ;
T_2 V_42 ;
T_6 V_104 ;
F_39 ( L_76 , V_20 , V_182 , 0 ) ;
F_74 ( 4 , L_77 , V_20 , V_182 ) ;
V_20 -> V_92 -- ;
V_20 -> V_219 ++ ;
V_181 = F_63 ( V_20 , char * ) ;
* V_181 = V_182 ;
if ( V_182 == V_246 )
* V_181 = V_220 ;
V_176 = 0 ;
V_183 = V_20 -> V_219 ;
while ( V_183 ) {
V_175 = V_264 - ( ( long ) V_181 & ( V_264 - 1 ) ) ;
if ( V_175 >= V_183 ) {
V_175 = V_183 ;
}
F_74 ( 5 , L_78 , V_181 , V_175 ) ;
V_180 [ V_176 ] = V_181 ;
V_263 [ V_176 ] = V_175 ;
V_176 ++ ;
V_183 -= V_175 ;
V_181 += V_175 ;
}
V_51 = V_5 -> V_22 . V_23 . V_53 [ V_54 ] ;
if ( V_182 == V_224 || V_182 == V_246 ) {
V_228 = V_247 ;
}
else {
V_228 = V_245 ;
if ( ( V_5 -> V_12 . V_13 . V_82 && ( V_182 == V_222 ) ) ||
( V_5 -> V_12 . V_13 . V_81 && ( V_182 == V_220 ) ) )
V_228 |= V_247 ;
}
if ( ! V_5 -> V_22 . V_251 || V_176 > V_51 -> V_59 ) {
V_228 &= ~ V_245 ;
if ( V_228 ) {
F_74 ( 2 , L_60 ) ;
}
else {
F_74 ( 2 , L_79 ) ;
F_24 ( V_5 , V_20 ) ;
return ;
}
}
F_74 ( 5 , L_80 , V_228 ) ;
if ( ( V_228 & V_245 ) && ( V_228 & V_247 ) ) {
V_20 -> V_75 = 2 ;
}
if ( V_228 & V_245 ) {
V_105 = V_51 -> V_57 ;
V_228 |= V_231 ;
for ( V_39 = 0 ; V_39 < V_176 ; V_39 ++ ) {
F_74 ( 5 , L_81 , V_105 ) ;
if ( V_39 == V_176 - 1 ) {
V_228 |= V_232 ;
V_105 -> V_255 = F_13 ( V_240 |
( ( ( V_230 ) ( V_20 -> V_219 - 1 ) & 3 ) << 27 ) ) ;
}
V_105 -> V_254 = V_180 [ V_39 ] ;
V_42 = F_84 ( V_5 , ( void T_5 * ) V_180 [ V_39 ] ,
V_263 [ V_39 ] , V_265 | V_266 ) ;
V_105 -> V_256 = F_13 ( V_42 ) ;
V_104 = F_13 ( ( ( ( V_230 ) V_228 &
( V_231 | V_232 ) ) << 26 ) |
V_109 | V_45 | V_267 | V_263 [ V_39 ] ) ;
V_105 -> V_108 = V_104 ;
#ifndef F_76
F_15 ( V_105 , V_48 ) ;
F_18 ( V_51 -> V_258 , V_101 ) ;
#else
F_15 ( V_105 , V_48 ) ;
F_18 ( F_19 ( V_100 ) , V_101 ) ;
#endif
V_228 &= ~ V_231 ;
V_51 -> V_57 = V_105 = V_105 -> V_106 ;
V_51 -> V_59 -- ;
V_51 -> V_60 ++ ;
}
V_5 -> V_194 . V_195 [ V_196 ] . V_259 ++ ;
F_80 ( V_5 , V_20 ) ;
}
if ( V_228 & V_247 ) {
F_74 ( 5 , L_82 ) ;
F_79 ( V_5 , V_20 ) ;
}
F_50 ( V_5 ) ;
F_39 ( L_83 , V_105 , V_51 -> V_59 , V_176 ) ;
}
static void F_50 ( struct V_4 * V_5 )
{
struct V_50 * V_51 ;
struct V_9 volatile * V_268 ;
struct V_9 volatile * V_269 = NULL ;
V_19 * V_20 ;
T_2 V_104 ;
int V_39 ;
int V_176 ;
int V_175 ;
F_39 ( L_84 , 0 , 0 , 0 ) ;
for ( V_39 = V_62 ; V_39 <= V_54 ; V_39 ++ ) {
V_51 = V_5 -> V_22 . V_23 . V_53 [ V_39 ] ;
V_268 = V_51 -> V_58 ;
F_74 ( 5 , L_85 , V_39 ) ;
for ( ; ; ) {
V_176 = 0 ;
do {
F_15 ( V_268 , V_107 ) ;
F_74 ( 5 , L_86 , V_268 ) ;
V_104 = F_17 ( F_59 ( V_268 -> V_108 ) ) ;
if ( V_104 & V_109 || ! V_51 -> V_60 ) {
F_74 ( 4 , L_87 , V_39 ) ;
goto V_270 ;
}
V_268 = V_268 -> V_106 ;
V_176 ++ ;
} while ( ! ( V_104 & V_190 ) ) ;
V_268 = V_51 -> V_58 ;
for ( V_175 = V_176 ; V_175 ; V_175 -- ) {
V_104 = F_17 ( V_268 -> V_108 ) ;
F_61 ( V_5 ,
(union V_15 volatile * ) V_268 ,
( int ) ( V_265 |
( ( V_104 & V_267 ) >> 18 ) ) ) ;
V_269 = V_268 ;
V_268 = V_268 -> V_106 ;
}
if ( V_104 & V_267 ) {
V_20 = F_81 ( V_5 ) ;
F_24 ( V_5 , V_20 ) ;
}
else {
#ifndef F_77
F_74 ( 4 , L_88 , V_269 ) ;
F_85 ( V_5 , V_269 ) ;
#else
F_74 ( 4 , L_89 ,
V_51 -> V_58 ) ;
F_85 ( V_5 , V_51 -> V_58 ) ;
#endif
}
V_51 -> V_58 = V_268 ;
V_51 -> V_59 += V_176 ;
V_51 -> V_60 -= V_176 ;
}
V_270: ;
}
F_39 ( L_90 , 0 , 0 , 0 ) ;
}
void F_86 ( struct V_4 * V_5 )
{
struct V_9 volatile * V_105 ;
struct V_50 * V_51 ;
int V_60 ;
int V_39 ;
if ( V_5 -> V_22 . V_95 != V_96 ) {
F_29 () ;
F_5 ( V_5 , V_271 , V_272 ) ;
return ;
}
for ( V_39 = V_62 ; V_39 <= V_54 ; V_39 ++ ) {
V_51 = V_5 -> V_22 . V_23 . V_53 [ V_39 ] ;
F_74 ( 5 , L_91 , V_39 ) ;
V_105 = V_51 -> V_58 ;
V_60 = V_51 -> V_60 ;
while ( V_60 ) {
F_15 ( V_105 , V_107 ) ;
F_74 ( 5 , L_92 , V_105 ) ;
V_105 -> V_108 &= ~ F_13 ( V_109 ) ;
F_15 ( V_105 , V_48 ) ;
V_105 = V_105 -> V_106 ;
V_60 -- ;
}
}
F_50 ( V_5 ) ;
for ( V_39 = V_62 ; V_39 <= V_54 ; V_39 ++ ) {
V_51 = V_5 -> V_22 . V_23 . V_53 [ V_39 ] ;
V_105 = V_51 -> V_58 ;
if ( V_39 == V_62 ) {
F_18 ( F_19 ( V_64 ) , F_17 ( V_105 -> V_56 ) ) ;
}
else {
F_18 ( F_19 ( V_61 ) , F_17 ( V_105 -> V_56 ) ) ;
}
V_51 -> V_57 = V_51 -> V_58 -> V_106 ;
V_51 -> V_58 = V_51 -> V_57 ;
}
}
void F_87 ( struct V_4 * V_5 , int V_273 , int V_274 )
{
switch( V_273 ) {
case ( int ) NULL :
V_275 . V_276 = V_275 . V_277 = V_275 . V_278 = V_275 . V_279 = 0 ;
V_275 . V_280 = 0 ;
V_275 . V_281 . V_282 = V_275 . V_281 . V_283 = V_275 . V_281 . V_284 = 0 ;
#ifdef F_88
V_275 . V_285 = 0 ;
#endif
#ifdef F_89
V_275 . V_286 = 0 ;
#endif
break ;
case V_287 :
V_275 . V_276 = V_274 ;
break ;
case V_288 :
V_275 . V_277 = V_274 ;
break ;
case V_289 :
V_275 . V_278 = V_274 ;
break ;
case V_290 :
V_275 . V_279 = V_274 ;
break ;
case V_291 :
V_275 . V_280 = V_274 ;
break ;
case V_292 :
V_275 . V_293 = V_274 ;
break ;
case V_294 :
#ifdef F_88
V_275 . V_285 = V_274 ;
#endif
break ;
case V_295 :
#ifdef F_89
V_275 . V_286 = V_274 ;
#endif
break ;
case V_296 :
V_275 . V_281 . V_282 = V_274 ;
break ;
case V_297 :
V_275 . V_281 . V_283 = V_274 ;
break ;
case V_298 :
V_275 . V_281 . V_284 = V_274 ;
break ;
default:
break ;
}
}
