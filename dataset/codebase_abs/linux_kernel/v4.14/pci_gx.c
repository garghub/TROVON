static int F_1 ( int V_1 )
{
unsigned int V_2 ;
int V_3 = 0 ;
int V_4 ;
V_2 = F_2 ( & V_5 ) ;
if ( F_3 ( V_2 == 0 ) ) {
F_4 ( L_1 ) ;
return V_1 % ( V_6 * V_7 ) ;
}
V_2 = V_1 % V_2 ;
F_5 (cpu, &intr_cpus_map) {
if ( V_3 ++ == V_2 )
break;
}
return V_4 ;
}
static int F_6 ( int V_8 )
{
T_1 * V_9 = & V_10 [ V_8 ] ;
int V_11 ;
int V_12 ;
V_11 = F_7 ( V_9 , V_8 ) ;
if ( V_11 < 0 )
goto V_13;
V_11 = F_8 ( V_9 , 1 , 0 , 0 ) ;
if ( V_11 < 0 ) {
F_9 ( L_2 ,
V_8 ) ;
goto V_14;
}
V_9 -> V_15 = V_11 ;
#ifdef F_10
V_11 = F_11 ( V_9 , 1 , 0 , 0 ) ;
if ( V_11 < 0 ) {
F_9 ( L_3 ,
V_8 ) ;
goto V_16;
}
V_9 -> V_17 = V_11 ;
V_11 = F_12 ( V_9 , V_9 -> V_17 ,
0 , 0 , V_18 ) ;
if ( V_11 < 0 ) {
F_9 ( L_4 ,
V_8 ) ;
goto V_16;
}
#endif
V_11 = F_13 ( V_9 , & V_19 [ V_8 ] ) ;
if ( V_11 < 0 ) {
F_9 ( L_5 ,
V_11 , V_8 ) ;
goto V_20;
}
V_9 -> V_21 =
F_14 ( V_9 -> V_22 , 0 , V_23 ) ;
if ( V_9 -> V_21 == NULL ) {
F_9 ( L_6 ,
V_11 , V_8 ) ;
V_11 = - V_24 ;
goto V_25;
}
for ( V_12 = 0 ; V_12 < V_26 ; V_12 ++ ) {
T_2 V_27 ;
unsigned int V_28 ;
if ( ! V_19 [ V_8 ] . V_29 [ V_12 ] . V_30 &&
! V_19 [ V_8 ] . V_29 [ V_12 ] . V_31 )
continue;
V_28 =
( V_32 <<
V_33 ) |
( V_34 <<
V_35 ) |
( V_12 << V_36 ) ;
V_27 . V_37 =
F_15 ( V_9 -> V_21 + V_28 ) ;
if ( V_27 . V_38 != V_39 &&
V_27 . V_38 != V_40 ) {
if ( V_27 . V_38 == V_41 ||
V_27 . V_38 == V_42 )
V_19 [ V_8 ] . V_29 [ V_12 ] . V_31 = 1 ;
}
}
return V_11 ;
V_25:
V_20:
V_14:
#ifdef F_10
V_16:
#endif
F_16 ( V_9 -> V_22 ) ;
V_13:
V_9 -> V_22 = - 1 ;
return V_11 ;
}
static int T_3 F_17 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ ) {
if ( F_6 ( V_3 ) < 0 )
continue;
V_44 ++ ;
}
return 0 ;
}
static void F_18 ( struct V_45 * V_46 )
{
F_19 ( V_47 , 1UL << V_46 -> V_1 ) ;
}
static void F_20 ( struct V_45 * V_46 )
{
F_19 ( V_48 , 1UL << V_46 -> V_1 ) ;
}
static void F_21 ( struct V_45 * V_46 )
{
F_19 ( V_49 , 1UL << V_46 -> V_1 ) ;
}
static void F_22 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_23 ( V_51 ) ;
T_1 * V_54 = V_53 -> V_55 ;
T_4 V_56 = ( T_4 ) F_24 ( V_51 ) ;
int V_12 = V_53 -> V_12 ;
unsigned int V_28 ;
T_4 V_57 ;
F_25 ( V_51 ) ;
V_28 = ( V_58 <<
V_33 ) |
( V_34 <<
V_35 ) |
( V_12 << V_36 ) ;
V_57 = V_59 << V_56 ;
F_26 ( V_54 -> V_21 + V_28 , V_57 ) ;
}
static int F_27 ( struct V_52 * V_53 )
{
int V_3 ;
int V_60 ;
int V_1 ;
int V_61 ;
F_28 ( & V_5 , V_62 ) ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
T_1 * V_9 = V_53 -> V_55 ;
int V_4 ;
V_1 = F_29 ( - 1 ) ;
if ( ! V_1 ) {
F_9 ( L_7 , V_3 ) ;
goto V_63;
}
V_53 -> V_64 [ V_3 ] = V_1 ;
V_4 = F_1 ( V_1 ) ;
V_61 = F_30 ( V_9 , F_31 ( V_4 ) ,
F_32 ( V_4 ) , V_65 ,
V_1 , V_53 -> V_12 , V_3 ) ;
if ( V_61 < 0 ) {
F_9 ( L_8 , V_3 ) ;
goto V_63;
}
F_33 ( V_1 , & V_66 ,
F_22 ) ;
F_34 ( V_1 , ( void * ) ( T_4 ) V_3 ) ;
F_35 ( V_1 , V_53 ) ;
}
return 0 ;
V_63:
for ( V_60 = 0 ; V_60 < V_3 ; V_60 ++ )
F_36 ( V_53 -> V_64 [ V_60 ] ) ;
return - 1 ;
}
static int
F_37 ( T_1 * V_54 , int V_12 )
{
T_2 V_27 ;
unsigned int V_28 ;
V_28 =
( V_32 <<
V_33 ) |
( V_34 <<
V_35 ) |
( V_12 << V_36 ) ;
V_27 . V_37 =
F_15 ( V_54 -> V_21 + V_28 ) ;
if ( V_27 . V_38 == V_39 ||
V_27 . V_38 == V_40 )
return 1 ;
else
return 0 ;
}
int T_3 F_38 ( void )
{
int V_67 = 0 ;
int V_3 , V_60 ;
if ( ! V_68 ) {
F_39 ( L_9 ) ;
return 0 ;
}
F_39 ( L_10 ) ;
if ( V_44 == 0 || F_40 () )
return 0 ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ ) {
T_1 * V_9 = & V_10 [ V_3 ] ;
if ( V_9 -> V_22 < 0 )
continue;
for ( V_60 = 0 ; V_60 < V_26 ; V_60 ++ ) {
int V_69 = 0 ;
if ( V_19 [ V_3 ] . V_70 &&
V_19 [ V_3 ] . V_29 [ V_60 ] . V_30 ) {
if ( ! V_19 [ V_3 ] . V_29 [ V_60 ] . V_31 ||
F_37 ( V_9 , V_60 ) )
V_69 = 1 ;
} else if ( V_19 [ V_3 ] . V_29 [ V_60 ] . V_30 &&
F_37 ( V_9 , V_60 ) ) {
V_69 = 1 ;
}
if ( V_69 ) {
V_71 [ V_3 ] [ V_60 ] = 1 ;
V_72 ++ ;
}
}
}
if ( V_72 == 0 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ ) {
for ( V_60 = 0 ; V_60 < V_26 ; V_60 ++ ) {
if ( V_71 [ V_3 ] [ V_60 ] ) {
V_73 [ V_67 ] . V_55 =
& V_10 [ V_3 ] ;
V_73 [ V_67 ] . V_12 = V_60 ;
V_73 [ V_67 ] . V_8 = V_3 ;
V_67 ++ ;
if ( V_67 == V_72 )
goto V_74;
}
}
}
V_74:
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ ) {
struct V_52 * V_53 = & V_73 [ V_3 ] ;
V_53 -> V_75 = V_3 ;
V_53 -> V_76 = & V_77 ;
V_53 -> V_78 . V_79 = V_80 +
( V_3 * V_81 ) ;
V_53 -> V_78 . V_82 = V_53 -> V_78 . V_79 +
V_81 - 1 ;
F_41 ( V_53 -> V_78 . V_82 > V_83 ) ;
V_53 -> V_78 . V_84 = V_85 ;
snprintf ( V_53 -> V_86 ,
sizeof( V_53 -> V_86 ) ,
L_11 , V_3 ) ;
V_53 -> V_78 . V_87 = V_53 -> V_86 ;
V_53 -> V_88 = V_89 +
( V_3 * V_90 ) ;
V_53 -> V_91 . V_79 = V_53 -> V_88 +
V_90 - V_92 ;
V_53 -> V_91 . V_82 = V_53 -> V_88 +
V_90 - 1 ;
V_53 -> V_91 . V_84 = V_93 ;
snprintf ( V_53 -> V_94 ,
sizeof( V_53 -> V_94 ) ,
L_12 , V_3 ) ;
V_53 -> V_91 . V_87 = V_53 -> V_94 ;
}
return V_72 ;
}
static int F_42 ( const struct V_95 * V_96 , T_5 V_97 , T_5 V_98 )
{
struct V_52 * V_53 =
(struct V_52 * ) V_96 -> V_99 ;
return V_53 -> V_64 [ V_98 - 1 ] ;
}
static void F_43 ( struct V_52 * V_53 )
{
T_1 * V_54 = V_53 -> V_55 ;
struct V_100 * V_101 = V_53 -> V_101 ;
T_6 V_102 ;
T_7 V_103 ;
unsigned int V_28 ;
struct V_100 * V_104 ;
int V_12 ;
int V_105 ;
V_12 = V_53 -> V_12 ;
V_28 =
( V_106 <<
V_33 ) |
( V_107 <<
V_35 ) |
( V_12 << V_36 ) ;
V_102 . V_37 = F_44 ( V_54 -> V_21 +
V_28 ) ;
V_102 . V_108 = 5 ;
F_45 ( V_54 -> V_21 + V_28 ,
V_102 . V_37 ) ;
V_28 =
( V_109 <<
V_33 ) |
( V_107 <<
V_35 ) |
( V_12 << V_36 ) ;
V_103 . V_37 = F_44 ( V_54 -> V_21 +
V_28 ) ;
V_103 . V_110 = 1 ;
F_45 ( V_54 -> V_21 + V_28 ,
V_103 . V_37 ) ;
F_46 (child, &root_bus->children, node)
F_47 ( V_104 ) ;
V_28 =
( V_106 <<
V_33 ) |
( V_107 <<
V_35 ) |
( V_12 << V_36 ) ;
V_102 . V_37 = F_44 ( V_54 -> V_21 +
V_28 ) ;
V_105 = F_48 ( V_54 ,
V_102 . V_111 ,
V_102 . V_108 ,
V_12 ) ;
if ( V_105 < 0 ) {
F_9 ( L_13 ,
V_12 , V_53 -> V_8 ) ;
}
}
static int F_49 ( char * V_112 )
{
unsigned long V_113 = 0 ;
unsigned long V_8 ;
unsigned long V_12 ;
if ( V_112 == NULL || ! isdigit ( * V_112 ) )
return - V_114 ;
V_8 = F_50 ( V_112 , ( char * * ) & V_112 , 10 ) ;
if ( V_8 >= V_43 )
return - V_114 ;
if ( * V_112 != ',' )
return - V_114 ;
V_112 ++ ;
if ( ! isdigit ( * V_112 ) )
return - V_114 ;
V_12 = F_50 ( V_112 , ( char * * ) & V_112 , 10 ) ;
if ( V_12 >= V_26 )
return - V_114 ;
if ( * V_112 != '\0' ) {
if ( * V_112 != ',' )
return - V_114 ;
V_112 ++ ;
if ( ! isdigit ( * V_112 ) )
return - V_114 ;
V_113 = F_50 ( V_112 , ( char * * ) & V_112 , 10 ) ;
}
V_115 [ V_8 ] [ V_12 ] = V_113 ? : V_116 ;
return 0 ;
}
int T_3 F_51 ( void )
{
T_8 V_117 ;
F_52 ( V_118 ) ;
int V_119 ;
struct V_120 * V_121 ;
int V_3 ;
F_38 () ;
if ( V_72 == 0 )
return 0 ;
F_53 ( 250 ) ;
for ( V_119 = 0 , V_3 = 0 ; V_3 < V_72 ; V_3 ++ ) {
struct V_52 * V_53 = & V_73 [ V_3 ] ;
T_1 * V_54 = V_53 -> V_55 ;
T_9 V_122 ;
T_10 V_123 ;
struct V_100 * V_124 ;
unsigned int V_28 ;
unsigned int V_125 ;
int V_8 ;
int V_12 ;
int V_11 ;
if ( V_54 -> V_22 < 0 )
continue;
V_8 = V_53 -> V_8 ;
V_12 = V_53 -> V_12 ;
V_28 =
( V_126 <<
V_33 ) |
( V_34 <<
V_35 ) |
( V_12 << V_36 ) ;
V_122 . V_37 =
F_15 ( V_54 -> V_21 +
V_28 ) ;
if ( ! V_122 . V_127 ) {
if ( V_115 [ V_8 ] [ V_12 ] ) {
F_39 ( L_14 ,
V_115 [ V_8 ] [ V_12 ] , V_12 ,
V_8 ) ;
F_53 ( V_115 [ V_8 ] [ V_12 ] * 1000 ) ;
}
V_11 = F_54 ( V_54 , V_12 ) ;
if ( V_11 < 0 )
F_9 ( L_15 ,
V_12 , V_8 ) ;
}
F_39 ( L_16 ,
V_3 , V_8 , V_53 -> V_12 ) ;
if ( V_115 [ V_8 ] [ V_12 ] ) {
F_39 ( L_17 ,
V_115 [ V_8 ] [ V_12 ] , V_12 , V_8 ) ;
F_53 ( V_115 [ V_8 ] [ V_12 ] * 1000 ) ;
} else {
F_53 ( 1000 ) ;
}
V_122 . V_37 =
F_15 ( V_54 -> V_21 +
V_28 ) ;
if ( ! V_122 . V_127 ) {
if ( V_19 [ V_8 ] . V_29 [ V_12 ] . V_128 ) {
F_39 ( L_18 ,
V_12 , V_8 ) ;
F_39 ( L_19 ) ;
} else
F_9 ( L_18 ,
V_12 , V_8 ) ;
continue;
}
V_28 =
( V_129 <<
V_33 ) |
( V_34 <<
V_35 ) |
( V_12 << V_36 ) ;
V_123 . V_37 =
F_15 ( V_54 -> V_21 +
V_28 ) ;
V_123 . V_130 = 0 ;
F_26 ( V_54 -> V_21 + V_28 ,
V_123 . V_37 ) ;
V_28 =
( V_131 <<
V_33 ) |
( V_107 <<
V_35 ) |
( V_12 << V_36 ) ;
F_45 ( V_54 -> V_21 + V_28 ,
( V_132 <<
V_133 ) |
V_134 ) ;
V_28 =
( V_135 <<
V_33 ) |
( V_107 <<
V_35 ) |
( V_12 << V_36 ) ;
V_125 =
F_44 ( V_54 -> V_21 +
V_28 ) ;
V_125 = ( V_125 & 0xff ) |
( V_136 << 16 ) ;
F_45 ( V_54 -> V_21 +
V_28 , V_125 ) ;
#ifdef F_10
V_117 = F_55 ( V_54 -> V_17 ) |
( ( ( unsigned long long ) V_12 ) <<
V_137 ) ;
#else
V_11 = F_11 ( V_54 , 1 , 0 , 0 ) ;
if ( V_11 < 0 ) {
F_9 ( L_20 ,
V_12 , V_8 ) ;
continue;
}
V_54 -> V_17 [ V_12 ] = V_11 ;
V_11 = F_12 ( V_54 ,
V_54 -> V_17 [ V_12 ] ,
V_12 , 0 , V_18 ) ;
if ( V_11 < 0 ) {
F_9 ( L_21 ,
V_12 , V_8 ) ;
continue;
}
V_117 = F_55 ( V_54 -> V_17 [ V_12 ] ) |
( ( ( unsigned long long ) V_12 ) <<
V_137 ) ;
#endif
V_54 -> V_138 [ V_12 ] =
F_14 ( V_54 -> V_22 , V_117 , ( 1UL <<
( V_137 - 1 ) ) ) ;
if ( V_54 -> V_138 [ V_12 ] == NULL ) {
F_9 ( L_22 ,
V_12 , V_8 ) ;
continue;
}
if ( F_27 ( V_53 ) ) {
F_9 ( L_23 ,
V_12 , V_8 ) ;
continue;
}
F_56 ( & V_118 , & V_53 -> V_91 ,
V_53 -> V_88 ) ;
F_57 ( & V_118 , & V_53 -> V_78 ) ;
V_53 -> V_139 = V_119 ;
V_121 = F_58 ( 0 ) ;
if ( ! V_121 )
break;
F_59 ( & V_118 , & V_121 -> V_140 ) ;
V_121 -> V_96 . V_141 = NULL ;
V_121 -> V_99 = V_53 ;
V_121 -> V_142 = V_119 ;
V_121 -> V_76 = V_53 -> V_76 ;
V_121 -> V_143 = V_144 ;
V_121 -> V_145 = F_42 ;
F_60 ( V_121 ) ;
V_124 = V_121 -> V_124 ;
V_53 -> V_101 = V_124 ;
V_119 = V_124 -> V_146 . V_82 + 1 ;
}
F_61 () ;
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ ) {
struct V_52 * V_53 = & V_73 [ V_3 ] ;
T_1 * V_54 = V_53 -> V_55 ;
struct V_100 * V_101 = V_73 [ V_3 ] . V_101 ;
int V_11 ;
int V_60 ;
if ( V_101 == NULL )
continue;
F_43 ( V_53 ) ;
V_11 = F_11 ( V_54 , 1 , 0 , 0 ) ;
if ( V_11 < 0 ) {
F_9 ( L_24 ,
V_53 -> V_8 , V_53 -> V_12 ) ;
continue;
}
V_53 -> V_147 = V_11 ;
V_11 = F_12 ( V_54 ,
V_53 -> V_147 ,
V_53 -> V_12 ,
0 ,
0 ) ;
if ( V_11 < 0 ) {
F_9 ( L_25 ,
V_53 -> V_8 , V_53 -> V_12 ) ;
continue;
}
#ifdef F_62
V_11 = F_11 ( V_54 , 1 , 0 , 0 ) ;
if ( V_11 < 0 ) {
F_9 ( L_26 ,
V_53 -> V_8 , V_53 -> V_12 ) ;
continue;
}
V_53 -> V_148 = V_11 ;
V_11 = F_12 ( V_54 ,
V_53 -> V_148 ,
V_53 -> V_12 ,
0 ,
V_149 ) ;
if ( V_11 < 0 ) {
F_9 ( L_27 ,
V_53 -> V_8 , V_53 -> V_12 ) ;
continue;
}
#endif
F_63 (j) {
unsigned long V_150 = V_151 [ V_60 ] ;
unsigned long V_152 = V_153 [ V_60 ] ;
unsigned long V_154 = V_152 - V_150 ;
V_11 = F_64 ( V_54 , 1 , 0 ,
0 ) ;
if ( V_11 < 0 ) {
F_9 ( L_28 ,
V_53 -> V_8 , V_53 -> V_12 ,
V_60 ) ;
goto V_155;
}
V_53 -> V_156 [ V_60 ] = V_11 ;
V_11 = F_65 ( V_54 ,
V_53 -> V_156 [ V_60 ] ,
V_150 << V_157 ,
V_154 << V_157 ,
V_54 -> V_15 ,
V_53 -> V_12 ,
( V_150 << V_157 ) +
V_158 ,
V_60 ,
V_159 ) ;
if ( V_11 < 0 ) {
F_9 ( L_29 ,
V_53 -> V_8 , V_53 -> V_12 ,
V_60 ) ;
goto V_155;
}
continue;
V_155:
break;
}
F_66 ( V_101 ) ;
}
return 0 ;
}
char * T_3 F_67 ( char * V_112 )
{
if ( ! strcmp ( V_112 , L_30 ) ) {
V_68 = 0 ;
return NULL ;
}
return V_112 ;
}
static void F_68 ( struct V_95 * V_160 )
{
F_69 ( & V_160 -> V_96 , V_161 ) ;
F_70 ( & V_160 -> V_96 , V_158 ) ;
V_160 -> V_96 . V_162 . V_163 =
V_164 ;
V_160 -> V_96 . V_165 = V_164 ;
}
void T_11 * F_71 ( T_8 V_166 , unsigned long V_167 )
{
struct V_52 * V_53 = NULL ;
T_8 V_168 ;
T_8 V_169 ;
T_8 V_117 ;
T_8 V_79 ;
T_8 V_82 ;
int V_170 ;
int V_3 ;
V_79 = V_166 ;
V_82 = V_166 + V_167 - 1 ;
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ ) {
if ( V_73 [ V_3 ] . V_101 == NULL )
continue;
V_168 = V_73 [ V_3 ] . V_91 . V_79 ;
V_169 = V_73 [ V_3 ] . V_91 . V_82 ;
if ( ( V_79 >= V_168 ) && ( V_82 <= V_169 ) ) {
V_53 = & V_73 [ V_3 ] ;
break;
}
}
if ( V_53 == NULL )
return NULL ;
V_170 = V_53 -> V_55 -> V_22 ;
V_79 = V_166 - V_53 -> V_88 ;
V_117 = F_55 ( V_53 -> V_147 ) + V_79 ;
return F_14 ( V_170 , V_117 , V_167 ) +
( V_79 & ( V_171 - 1 ) ) ;
}
void T_11 * F_72 ( unsigned long V_172 , unsigned int V_167 )
{
struct V_52 * V_53 = NULL ;
T_8 V_168 ;
T_8 V_169 ;
T_8 V_117 ;
T_8 V_79 ;
T_8 V_82 ;
int V_170 ;
int V_3 ;
V_79 = V_172 ;
V_82 = V_172 + V_167 - 1 ;
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ ) {
if ( V_73 [ V_3 ] . V_101 == NULL )
continue;
V_168 = V_73 [ V_3 ] . V_78 . V_79 ;
V_169 = V_73 [ V_3 ] . V_78 . V_82 ;
if ( ( V_79 >= V_168 ) && ( V_82 <= V_169 ) ) {
V_53 = & V_73 [ V_3 ] ;
break;
}
}
if ( V_53 == NULL )
return NULL ;
V_170 = V_53 -> V_55 -> V_22 ;
V_172 -= V_53 -> V_78 . V_79 ;
V_117 = F_55 ( V_53 -> V_148 ) + V_172 ;
return F_14 ( V_170 , V_117 , V_167 ) + ( V_172 & ( V_171 - 1 ) ) ;
}
void F_73 ( void T_11 * V_173 )
{
F_74 ( V_173 ) ;
}
void F_75 ( struct V_95 * V_96 , void T_11 * V_173 )
{
F_74 ( V_173 ) ;
}
static int F_76 ( struct V_100 * V_124 , unsigned int V_174 , int V_117 ,
int V_167 , T_12 * V_175 )
{
struct V_52 * V_53 = V_124 -> V_99 ;
T_1 * V_54 = V_53 -> V_55 ;
int V_176 = V_124 -> V_177 & 0xff ;
int V_97 = F_77 ( V_174 ) ;
int V_178 = F_78 ( V_174 ) ;
int V_179 = 1 ;
T_13 V_180 ;
void * V_181 ;
if ( F_79 ( V_124 ) ) {
if ( V_97 == 0 ) {
unsigned int V_28 ;
V_28 = ( ( V_117 & 0xFFF ) <<
V_33 ) |
( V_182
<< V_35 ) |
( V_53 -> V_12 <<
V_36 ) ;
V_181 = V_54 -> V_21 + V_28 ;
goto V_183;
} else {
goto V_184;
}
}
if ( V_176 == ( V_53 -> V_139 + 1 ) ) {
if ( V_97 != 0 )
goto V_184;
V_179 = 0 ;
}
V_180 . V_37 = 0 ;
V_180 . V_185 = ( V_117 & 0xFFF ) ;
V_180 . V_186 = V_178 ;
V_180 . V_96 = V_97 ;
V_180 . V_124 = V_176 ;
V_180 . type = V_179 ;
V_181 = V_54 -> V_138 [ V_53 -> V_12 ] +
V_180 . V_37 ;
V_183:
switch ( V_167 ) {
case 4 :
* V_175 = F_44 ( V_181 ) ;
break;
case 2 :
* V_175 = F_80 ( V_181 ) ;
break;
case 1 :
* V_175 = F_81 ( V_181 ) ;
break;
default:
return V_187 ;
}
F_82 ( V_167 , * V_175 , V_176 , V_97 , V_178 , V_117 ) ;
return 0 ;
V_184:
switch ( V_167 ) {
case 4 :
* V_175 = 0xFFFFFFFF ;
break;
case 2 :
* V_175 = 0xFFFF ;
break;
case 1 :
* V_175 = 0xFF ;
break;
default:
return V_187 ;
}
return 0 ;
}
static int F_83 ( struct V_100 * V_124 , unsigned int V_174 , int V_117 ,
int V_167 , T_12 V_175 )
{
struct V_52 * V_53 = V_124 -> V_99 ;
T_1 * V_54 = V_53 -> V_55 ;
int V_176 = V_124 -> V_177 & 0xff ;
int V_97 = F_77 ( V_174 ) ;
int V_178 = F_78 ( V_174 ) ;
int V_179 = 1 ;
T_13 V_180 ;
void * V_181 ;
T_12 V_188 = ( T_12 ) V_175 ;
T_14 V_189 = ( T_14 ) V_175 ;
T_5 V_190 = ( T_5 ) V_175 ;
if ( F_79 ( V_124 ) ) {
if ( V_97 == 0 ) {
unsigned int V_28 ;
V_28 = ( ( V_117 & 0xFFF ) <<
V_33 ) |
( V_182
<< V_35 ) |
( V_53 -> V_12 <<
V_36 ) ;
V_181 = V_54 -> V_21 + V_28 ;
goto V_183;
} else {
goto V_184;
}
}
if ( V_176 == ( V_53 -> V_139 + 1 ) ) {
if ( V_97 != 0 )
goto V_184;
V_179 = 0 ;
}
V_180 . V_37 = 0 ;
V_180 . V_185 = ( V_117 & 0xFFF ) ;
V_180 . V_186 = V_178 ;
V_180 . V_96 = V_97 ;
V_180 . V_124 = V_176 ;
V_180 . type = V_179 ;
V_181 = V_54 -> V_138 [ V_53 -> V_12 ] +
V_180 . V_37 ;
V_183:
switch ( V_167 ) {
case 4 :
F_45 ( V_181 , V_188 ) ;
F_84 ( V_167 , V_188 , V_176 , V_97 , V_178 , V_117 ) ;
break;
case 2 :
F_85 ( V_181 , V_189 ) ;
F_84 ( V_167 , V_189 , V_176 , V_97 , V_178 , V_117 ) ;
break;
case 1 :
F_86 ( V_181 , V_190 ) ;
F_84 ( V_167 , V_190 , V_176 , V_97 , V_178 , V_117 ) ;
break;
default:
return V_187 ;
}
V_184:
return 0 ;
}
static unsigned int F_87 ( struct V_45 * V_46 )
{
if ( F_88 ( V_46 ) )
F_89 ( V_46 ) ;
return 0 ;
}
static void F_90 ( struct V_45 * V_46 )
{
F_19 ( V_47 , 1UL << V_46 -> V_1 ) ;
}
static void F_91 ( struct V_45 * V_46 )
{
F_92 ( V_46 ) ;
F_19 ( V_48 , 1UL << V_46 -> V_1 ) ;
}
static void F_93 ( struct V_45 * V_46 )
{
F_19 ( V_49 , 1UL << V_46 -> V_1 ) ;
F_89 ( V_46 ) ;
}
int F_94 ( struct V_95 * V_160 , struct V_191 * V_51 )
{
struct V_52 * V_53 ;
T_1 * V_54 ;
struct V_192 V_193 ;
int V_194 ;
T_4 V_195 ;
T_4 V_196 ;
T_15 V_197 ;
int V_198 ;
int V_4 ;
int V_1 ;
int V_11 ;
V_1 = F_29 ( - 1 ) ;
if ( ! V_1 )
return - V_199 ;
if ( V_51 -> V_200 . V_201 == 0 ) {
F_95 ( & V_160 -> V_96 , L_31 ) ;
V_11 = - V_24 ;
goto V_202;
}
V_194 = V_51 -> V_200 . V_194 ;
V_53 = F_96 ( V_194 ) ;
F_41 ( ! V_53 ) ;
V_54 = V_53 -> V_55 ;
V_198 = F_97 ( V_54 , 1 , 0 , 0 ) ;
if ( V_198 >= 0 ) {
T_16 V_203 = { {
. V_204 = 0 ,
. V_205 = 1 ,
} } ;
V_198 += V_206 ;
V_195 = V_207 +
V_198 * V_208 ;
V_196 = V_195 + V_208 - 1 ;
V_197 = V_195 + V_208 - 8 ;
V_193 . V_209 = ( unsigned int ) V_203 . V_37 ;
} else {
V_198 = F_64 ( V_54 , 1 , 0 , 0 ) ;
if ( V_198 < 0 ) {
F_95 ( & V_160 -> V_96 , L_32 ,
V_51 -> V_200 . V_210 ? L_33 : L_34 ) ;
V_11 = - V_24 ;
goto V_211;
}
V_195 = V_207 +
V_198 * V_208 ;
V_196 = V_195 + V_208 - 1 ;
V_197 = V_195 + V_212 -
V_213 ;
V_193 . V_209 = V_198 ;
}
V_4 = F_1 ( V_1 ) ;
V_11 = F_98 ( V_54 , F_31 ( V_4 ) , F_32 ( V_4 ) ,
V_65 , V_1 , V_53 -> V_12 ,
V_198 , V_195 , V_196 ,
V_54 -> V_15 ) ;
if ( V_11 < 0 ) {
F_95 ( & V_160 -> V_96 , L_35 ) ;
goto V_214;
}
F_99 ( V_1 , V_51 ) ;
V_193 . V_215 = V_197 >> 32 ;
V_193 . V_216 = V_197 & 0xffffffff ;
F_100 ( V_1 , & V_193 ) ;
F_33 ( V_1 , & V_217 , F_25 ) ;
F_35 ( V_1 , V_53 ) ;
return 0 ;
V_214:
V_211:
V_202:
F_36 ( V_1 ) ;
return V_11 ;
}
void F_101 ( unsigned int V_1 )
{
F_36 ( V_1 ) ;
}
