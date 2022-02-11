T_1 F_1 ( void * V_1 , const struct V_2 * V_3 ,
T_1 V_4 ,
T_1 V_5 )
{
return V_3 -> V_6 ;
}
static int F_2 ( int V_7 )
{
unsigned int V_8 ;
int V_9 = 0 ;
int V_10 ;
V_8 = F_3 ( & V_11 ) ;
if ( F_4 ( V_8 == 0 ) ) {
F_5 ( L_1 ) ;
return V_7 % ( V_12 * V_13 ) ;
}
V_8 = V_7 % V_8 ;
F_6 (cpu, &intr_cpus_map) {
if ( V_9 ++ == V_8 )
break;
}
return V_10 ;
}
static int F_7 ( int V_14 )
{
T_2 * V_15 = & V_16 [ V_14 ] ;
int V_17 ;
int V_18 ;
V_17 = F_8 ( V_15 , V_14 ) ;
if ( V_17 < 0 )
goto V_19;
V_17 = F_9 ( V_15 , 1 , 0 , 0 ) ;
if ( V_17 < 0 ) {
F_10 ( L_2 ,
V_14 ) ;
goto V_20;
}
V_15 -> V_21 = V_17 ;
#ifdef F_11
V_17 = F_12 ( V_15 , 1 , 0 , 0 ) ;
if ( V_17 < 0 ) {
F_10 ( L_3 ,
V_14 ) ;
goto V_22;
}
V_15 -> V_23 = V_17 ;
V_17 = F_13 ( V_15 , V_15 -> V_23 ,
0 , 0 , V_24 ) ;
if ( V_17 < 0 ) {
F_10 ( L_4 ,
V_14 ) ;
goto V_22;
}
#endif
V_17 = F_14 ( V_15 , & V_25 [ V_14 ] ) ;
if ( V_17 < 0 ) {
F_10 ( L_5 ,
V_17 , V_14 ) ;
goto V_26;
}
V_15 -> V_27 =
F_15 ( V_15 -> V_28 , 0 , V_29 ) ;
if ( V_15 -> V_27 == NULL ) {
F_10 ( L_6 ,
V_17 , V_14 ) ;
V_17 = - V_30 ;
goto V_31;
}
for ( V_18 = 0 ; V_18 < V_32 ; V_18 ++ ) {
T_3 V_33 ;
unsigned int V_34 ;
if ( ! V_25 [ V_14 ] . V_35 [ V_18 ] . V_36 &&
! V_25 [ V_14 ] . V_35 [ V_18 ] . V_37 )
continue;
V_34 =
( V_38 <<
V_39 ) |
( V_40 <<
V_41 ) |
( V_18 << V_42 ) ;
V_33 . V_43 =
F_16 ( V_15 -> V_27 + V_34 ) ;
if ( V_33 . V_44 != V_45 &&
V_33 . V_44 != V_46 ) {
if ( V_33 . V_44 == V_47 ||
V_33 . V_44 == V_48 )
V_25 [ V_14 ] . V_35 [ V_18 ] . V_37 = 1 ;
}
}
return V_17 ;
V_31:
V_26:
V_20:
#ifdef F_11
V_22:
#endif
F_17 ( V_15 -> V_28 ) ;
V_19:
V_15 -> V_28 = - 1 ;
return V_17 ;
}
static int T_4 F_18 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_49 ; V_9 ++ ) {
if ( F_7 ( V_9 ) < 0 )
continue;
V_50 ++ ;
}
return 0 ;
}
static void F_19 ( struct V_51 * V_52 )
{
F_20 ( V_53 , 1UL << V_52 -> V_7 ) ;
}
static void F_21 ( struct V_51 * V_52 )
{
F_20 ( V_54 , 1UL << V_52 -> V_7 ) ;
}
static void F_22 ( struct V_51 * V_52 )
{
F_20 ( V_55 , 1UL << V_52 -> V_7 ) ;
}
static void F_23 ( unsigned int V_7 , struct V_56 * V_57 )
{
struct V_58 * V_59 = F_24 ( V_57 ) ;
T_2 * V_60 = V_59 -> V_61 ;
T_5 V_62 = ( T_5 ) F_25 ( V_57 ) ;
int V_18 = V_59 -> V_18 ;
unsigned int V_34 ;
T_5 V_63 ;
F_26 ( V_7 , V_57 ) ;
V_34 = ( V_64 <<
V_39 ) |
( V_40 <<
V_41 ) |
( V_18 << V_42 ) ;
V_63 = V_65 << V_62 ;
F_27 ( V_60 -> V_27 + V_34 , V_63 ) ;
}
static int F_28 ( struct V_58 * V_59 )
{
int V_9 ;
int V_66 ;
int V_7 ;
int V_67 ;
F_29 ( & V_11 , V_68 ) ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
T_2 * V_15 = V_59 -> V_61 ;
int V_10 ;
V_7 = F_30 ( - 1 ) ;
if ( ! V_7 ) {
F_10 ( L_7 , V_9 ) ;
goto V_69;
}
V_59 -> V_70 [ V_9 ] = V_7 ;
V_10 = F_2 ( V_7 ) ;
V_67 = F_31 ( V_15 , F_32 ( V_10 ) ,
F_33 ( V_10 ) , V_71 ,
V_7 , V_59 -> V_18 , V_9 ) ;
if ( V_67 < 0 ) {
F_10 ( L_8 , V_9 ) ;
goto V_69;
}
F_34 ( V_7 , & V_72 ,
F_23 ) ;
F_35 ( V_7 , ( void * ) ( T_5 ) V_9 ) ;
F_36 ( V_7 , V_59 ) ;
}
return 0 ;
V_69:
for ( V_66 = 0 ; V_66 < V_9 ; V_66 ++ )
F_37 ( V_59 -> V_70 [ V_66 ] ) ;
return - 1 ;
}
static int
F_38 ( T_2 * V_60 , int V_18 )
{
T_3 V_33 ;
unsigned int V_34 ;
V_34 =
( V_38 <<
V_39 ) |
( V_40 <<
V_41 ) |
( V_18 << V_42 ) ;
V_33 . V_43 =
F_16 ( V_60 -> V_27 + V_34 ) ;
if ( V_33 . V_44 == V_45 ||
V_33 . V_44 == V_46 )
return 1 ;
else
return 0 ;
}
int T_4 F_39 ( void )
{
int V_73 = 0 ;
int V_9 , V_66 ;
if ( ! V_74 ) {
F_40 ( L_9 ) ;
return 0 ;
}
F_40 ( L_10 ) ;
if ( V_50 == 0 || F_41 () )
return 0 ;
for ( V_9 = 0 ; V_9 < V_49 ; V_9 ++ ) {
T_2 * V_15 = & V_16 [ V_9 ] ;
if ( V_15 -> V_28 < 0 )
continue;
for ( V_66 = 0 ; V_66 < V_32 ; V_66 ++ ) {
int V_75 = 0 ;
if ( V_25 [ V_9 ] . V_76 &&
V_25 [ V_9 ] . V_35 [ V_66 ] . V_36 ) {
if ( ! V_25 [ V_9 ] . V_35 [ V_66 ] . V_37 ||
F_38 ( V_15 , V_66 ) )
V_75 = 1 ;
} else if ( V_25 [ V_9 ] . V_35 [ V_66 ] . V_36 &&
F_38 ( V_15 , V_66 ) ) {
V_75 = 1 ;
}
if ( V_75 ) {
V_77 [ V_9 ] [ V_66 ] = 1 ;
V_78 ++ ;
}
}
}
if ( V_78 == 0 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_49 ; V_9 ++ ) {
for ( V_66 = 0 ; V_66 < V_32 ; V_66 ++ ) {
if ( V_77 [ V_9 ] [ V_66 ] ) {
V_79 [ V_73 ] . V_61 =
& V_16 [ V_9 ] ;
V_79 [ V_73 ] . V_18 = V_66 ;
V_79 [ V_73 ] . V_14 = V_9 ;
V_73 ++ ;
if ( V_73 == V_78 )
goto V_80;
}
}
}
V_80:
for ( V_9 = 0 ; V_9 < V_78 ; V_9 ++ ) {
struct V_58 * V_59 = & V_79 [ V_9 ] ;
V_59 -> V_81 = V_9 ;
V_59 -> V_82 = & V_83 ;
V_59 -> V_84 . V_6 = V_85 +
( V_9 * V_86 ) ;
V_59 -> V_84 . V_87 = V_59 -> V_84 . V_6 +
V_86 - 1 ;
F_42 ( V_59 -> V_84 . V_87 > V_88 ) ;
V_59 -> V_84 . V_89 = V_90 ;
snprintf ( V_59 -> V_91 ,
sizeof( V_59 -> V_91 ) ,
L_11 , V_9 ) ;
V_59 -> V_84 . V_92 = V_59 -> V_91 ;
V_59 -> V_93 = V_94 +
( V_9 * V_95 ) ;
V_59 -> V_96 . V_6 = V_59 -> V_93 +
V_95 - V_97 ;
V_59 -> V_96 . V_87 = V_59 -> V_93 +
V_95 - 1 ;
V_59 -> V_96 . V_89 = V_98 ;
snprintf ( V_59 -> V_99 ,
sizeof( V_59 -> V_99 ) ,
L_12 , V_9 ) ;
V_59 -> V_96 . V_92 = V_59 -> V_99 ;
}
return V_78 ;
}
static int F_43 ( const struct V_100 * V_101 , T_6 V_102 , T_6 V_103 )
{
struct V_58 * V_59 =
(struct V_58 * ) V_101 -> V_104 ;
return V_59 -> V_70 [ V_103 - 1 ] ;
}
static void F_44 ( struct V_58 * V_59 )
{
T_2 * V_60 = V_59 -> V_61 ;
struct V_105 * V_106 = V_59 -> V_106 ;
T_7 V_107 ;
T_8 V_108 ;
unsigned int V_34 ;
struct V_105 * V_109 ;
int V_18 ;
int V_110 ;
V_18 = V_59 -> V_18 ;
V_34 =
( V_111 <<
V_39 ) |
( V_112 <<
V_41 ) |
( V_18 << V_42 ) ;
V_107 . V_43 = F_45 ( V_60 -> V_27 +
V_34 ) ;
V_107 . V_113 = 5 ;
F_46 ( V_60 -> V_27 + V_34 ,
V_107 . V_43 ) ;
V_34 =
( V_114 <<
V_39 ) |
( V_112 <<
V_41 ) |
( V_18 << V_42 ) ;
V_108 . V_43 = F_45 ( V_60 -> V_27 +
V_34 ) ;
V_108 . V_115 = 1 ;
F_46 ( V_60 -> V_27 + V_34 ,
V_108 . V_43 ) ;
F_47 (child, &root_bus->children, node)
F_48 ( V_109 ) ;
V_34 =
( V_111 <<
V_39 ) |
( V_112 <<
V_41 ) |
( V_18 << V_42 ) ;
V_107 . V_43 = F_45 ( V_60 -> V_27 +
V_34 ) ;
V_110 = F_49 ( V_60 ,
V_107 . V_116 ,
V_107 . V_113 ,
V_18 ) ;
if ( V_110 < 0 ) {
F_10 ( L_13 ,
V_18 , V_59 -> V_14 ) ;
}
}
static int F_50 ( char * V_117 )
{
unsigned long V_118 = 0 ;
unsigned long V_14 ;
unsigned long V_18 ;
if ( V_117 == NULL || ! isdigit ( * V_117 ) )
return - V_119 ;
V_14 = F_51 ( V_117 , ( char * * ) & V_117 , 10 ) ;
if ( V_14 >= V_49 )
return - V_119 ;
if ( * V_117 != ',' )
return - V_119 ;
V_117 ++ ;
if ( ! isdigit ( * V_117 ) )
return - V_119 ;
V_18 = F_51 ( V_117 , ( char * * ) & V_117 , 10 ) ;
if ( V_18 >= V_32 )
return - V_119 ;
if ( * V_117 != '\0' ) {
if ( * V_117 != ',' )
return - V_119 ;
V_117 ++ ;
if ( ! isdigit ( * V_117 ) )
return - V_119 ;
V_118 = F_51 ( V_117 , ( char * * ) & V_117 , 10 ) ;
}
V_120 [ V_14 ] [ V_18 ] = V_118 ? : V_121 ;
return 0 ;
}
int T_4 F_52 ( void )
{
T_1 V_122 ;
F_53 ( V_123 ) ;
int V_124 ;
int V_9 ;
F_39 () ;
if ( V_78 == 0 )
return 0 ;
F_54 ( 250 ) ;
for ( V_124 = 0 , V_9 = 0 ; V_9 < V_78 ; V_9 ++ ) {
struct V_58 * V_59 = & V_79 [ V_9 ] ;
T_2 * V_60 = V_59 -> V_61 ;
T_9 V_125 ;
T_10 V_126 ;
struct V_105 * V_127 ;
unsigned int V_34 ;
unsigned int V_128 ;
int V_14 ;
int V_18 ;
int V_17 ;
if ( V_60 -> V_28 < 0 )
continue;
V_14 = V_59 -> V_14 ;
V_18 = V_59 -> V_18 ;
V_34 =
( V_129 <<
V_39 ) |
( V_40 <<
V_41 ) |
( V_18 << V_42 ) ;
V_125 . V_43 =
F_16 ( V_60 -> V_27 +
V_34 ) ;
if ( ! V_125 . V_130 ) {
if ( V_120 [ V_14 ] [ V_18 ] ) {
F_40 ( L_14 ,
V_120 [ V_14 ] [ V_18 ] , V_18 ,
V_14 ) ;
F_54 ( V_120 [ V_14 ] [ V_18 ] * 1000 ) ;
}
V_17 = F_55 ( V_60 , V_18 ) ;
if ( V_17 < 0 )
F_10 ( L_15 ,
V_18 , V_14 ) ;
}
F_40 ( L_16 ,
V_9 , V_14 , V_59 -> V_18 ) ;
if ( V_120 [ V_14 ] [ V_18 ] ) {
F_40 ( L_17 ,
V_120 [ V_14 ] [ V_18 ] , V_18 , V_14 ) ;
F_54 ( V_120 [ V_14 ] [ V_18 ] * 1000 ) ;
} else {
F_54 ( 1000 ) ;
}
V_125 . V_43 =
F_16 ( V_60 -> V_27 +
V_34 ) ;
if ( ! V_125 . V_130 ) {
if ( V_25 [ V_14 ] . V_35 [ V_18 ] . V_131 ) {
F_40 ( L_18 ,
V_18 , V_14 ) ;
F_40 ( L_19 ) ;
} else
F_10 ( L_18 ,
V_18 , V_14 ) ;
continue;
}
V_34 =
( V_132 <<
V_39 ) |
( V_40 <<
V_41 ) |
( V_18 << V_42 ) ;
V_126 . V_43 =
F_16 ( V_60 -> V_27 +
V_34 ) ;
V_126 . V_133 = 0 ;
F_27 ( V_60 -> V_27 + V_34 ,
V_126 . V_43 ) ;
V_34 =
( V_134 <<
V_39 ) |
( V_112 <<
V_41 ) |
( V_18 << V_42 ) ;
F_46 ( V_60 -> V_27 + V_34 ,
( V_135 <<
V_136 ) |
V_137 ) ;
V_34 =
( V_138 <<
V_39 ) |
( V_112 <<
V_41 ) |
( V_18 << V_42 ) ;
V_128 =
F_45 ( V_60 -> V_27 +
V_34 ) ;
V_128 = ( V_128 & 0xff ) |
( V_139 << 16 ) ;
F_46 ( V_60 -> V_27 +
V_34 , V_128 ) ;
#ifdef F_11
V_122 = F_56 ( V_60 -> V_23 ) |
( ( ( unsigned long long ) V_18 ) <<
V_140 ) ;
#else
V_17 = F_12 ( V_60 , 1 , 0 , 0 ) ;
if ( V_17 < 0 ) {
F_10 ( L_20 ,
V_18 , V_14 ) ;
continue;
}
V_60 -> V_23 [ V_18 ] = V_17 ;
V_17 = F_13 ( V_60 ,
V_60 -> V_23 [ V_18 ] ,
V_18 , 0 , V_24 ) ;
if ( V_17 < 0 ) {
F_10 ( L_21 ,
V_18 , V_14 ) ;
continue;
}
V_122 = F_56 ( V_60 -> V_23 [ V_18 ] ) |
( ( ( unsigned long long ) V_18 ) <<
V_140 ) ;
#endif
V_60 -> V_141 [ V_18 ] =
F_15 ( V_60 -> V_28 , V_122 , ( 1UL <<
( V_140 - 1 ) ) ) ;
if ( V_60 -> V_141 [ V_18 ] == NULL ) {
F_10 ( L_22 ,
V_18 , V_14 ) ;
continue;
}
if ( F_28 ( V_59 ) ) {
F_10 ( L_23 ,
V_18 , V_14 ) ;
continue;
}
F_57 ( & V_123 , & V_59 -> V_96 ,
V_59 -> V_93 ) ;
F_58 ( & V_123 , & V_59 -> V_84 ) ;
V_59 -> V_142 = V_124 ;
V_127 = F_59 ( NULL , V_124 , V_59 -> V_82 ,
V_59 , & V_123 ) ;
V_59 -> V_106 = V_127 ;
V_124 = V_127 -> V_143 . V_87 + 1 ;
}
F_60 ( V_144 , F_43 ) ;
F_61 () ;
for ( V_9 = 0 ; V_9 < V_78 ; V_9 ++ ) {
struct V_58 * V_59 = & V_79 [ V_9 ] ;
T_2 * V_60 = V_59 -> V_61 ;
struct V_105 * V_106 = V_79 [ V_9 ] . V_106 ;
int V_17 ;
int V_66 ;
if ( V_106 == NULL )
continue;
F_44 ( V_59 ) ;
V_17 = F_12 ( V_60 , 1 , 0 , 0 ) ;
if ( V_17 < 0 ) {
F_10 ( L_24 ,
V_59 -> V_14 , V_59 -> V_18 ) ;
continue;
}
V_59 -> V_145 = V_17 ;
V_17 = F_13 ( V_60 ,
V_59 -> V_145 ,
V_59 -> V_18 ,
0 ,
0 ) ;
if ( V_17 < 0 ) {
F_10 ( L_25 ,
V_59 -> V_14 , V_59 -> V_18 ) ;
continue;
}
#ifdef F_62
V_17 = F_12 ( V_60 , 1 , 0 , 0 ) ;
if ( V_17 < 0 ) {
F_10 ( L_26 ,
V_59 -> V_14 , V_59 -> V_18 ) ;
continue;
}
V_59 -> V_146 = V_17 ;
V_17 = F_13 ( V_60 ,
V_59 -> V_146 ,
V_59 -> V_18 ,
0 ,
V_147 ) ;
if ( V_17 < 0 ) {
F_10 ( L_27 ,
V_59 -> V_14 , V_59 -> V_18 ) ;
continue;
}
#endif
F_63 (j) {
unsigned long V_148 = V_149 [ V_66 ] ;
unsigned long V_150 = V_151 [ V_66 ] ;
unsigned long V_152 = V_150 - V_148 ;
V_17 = F_64 ( V_60 , 1 , 0 ,
0 ) ;
if ( V_17 < 0 ) {
F_10 ( L_28 ,
V_59 -> V_14 , V_59 -> V_18 ,
V_66 ) ;
goto V_153;
}
V_59 -> V_154 [ V_66 ] = V_17 ;
V_17 = F_65 ( V_60 ,
V_59 -> V_154 [ V_66 ] ,
V_148 << V_155 ,
V_152 << V_155 ,
V_60 -> V_21 ,
V_59 -> V_18 ,
( V_148 << V_155 ) +
V_156 ,
V_66 ,
V_157 ) ;
if ( V_17 < 0 ) {
F_10 ( L_29 ,
V_59 -> V_14 , V_59 -> V_18 ,
V_66 ) ;
goto V_153;
}
continue;
V_153:
break;
}
}
return 0 ;
}
void F_66 ( struct V_105 * V_127 )
{
}
char * T_4 F_67 ( char * V_117 )
{
if ( ! strcmp ( V_117 , L_30 ) ) {
V_74 = 0 ;
return NULL ;
}
return V_117 ;
}
static void F_68 ( struct V_100 * V_158 )
{
F_69 ( & V_158 -> V_101 , V_159 ) ;
F_70 ( & V_158 -> V_101 , V_156 ) ;
V_158 -> V_101 . V_160 . V_161 =
V_162 ;
V_158 -> V_101 . V_163 = V_162 ;
}
void T_11 * F_71 ( T_1 V_164 , unsigned long V_4 )
{
struct V_58 * V_59 = NULL ;
T_1 V_165 ;
T_1 V_166 ;
T_1 V_122 ;
T_1 V_6 ;
T_1 V_87 ;
int V_167 ;
int V_9 ;
V_6 = V_164 ;
V_87 = V_164 + V_4 - 1 ;
for ( V_9 = 0 ; V_9 < V_78 ; V_9 ++ ) {
if ( V_79 [ V_9 ] . V_106 == NULL )
continue;
V_165 = V_79 [ V_9 ] . V_96 . V_6 ;
V_166 = V_79 [ V_9 ] . V_96 . V_87 ;
if ( ( V_6 >= V_165 ) && ( V_87 <= V_166 ) ) {
V_59 = & V_79 [ V_9 ] ;
break;
}
}
if ( V_59 == NULL )
return NULL ;
V_167 = V_59 -> V_61 -> V_28 ;
V_6 = V_164 - V_59 -> V_93 ;
V_122 = F_56 ( V_59 -> V_145 ) + V_6 ;
return F_15 ( V_167 , V_122 , V_4 ) +
( V_6 & ( V_168 - 1 ) ) ;
}
void T_11 * F_72 ( unsigned long V_169 , unsigned int V_4 )
{
struct V_58 * V_59 = NULL ;
T_1 V_165 ;
T_1 V_166 ;
T_1 V_122 ;
T_1 V_6 ;
T_1 V_87 ;
int V_167 ;
int V_9 ;
V_6 = V_169 ;
V_87 = V_169 + V_4 - 1 ;
for ( V_9 = 0 ; V_9 < V_78 ; V_9 ++ ) {
if ( V_79 [ V_9 ] . V_106 == NULL )
continue;
V_165 = V_79 [ V_9 ] . V_84 . V_6 ;
V_166 = V_79 [ V_9 ] . V_84 . V_87 ;
if ( ( V_6 >= V_165 ) && ( V_87 <= V_166 ) ) {
V_59 = & V_79 [ V_9 ] ;
break;
}
}
if ( V_59 == NULL )
return NULL ;
V_167 = V_59 -> V_61 -> V_28 ;
V_169 -= V_59 -> V_84 . V_6 ;
V_122 = F_56 ( V_59 -> V_146 ) + V_169 ;
return F_15 ( V_167 , V_122 , V_4 ) + ( V_169 & ( V_168 - 1 ) ) ;
}
void F_73 ( void T_11 * V_170 )
{
F_74 ( V_170 ) ;
}
void F_75 ( struct V_100 * V_101 , void T_11 * V_170 )
{
F_74 ( V_170 ) ;
}
static int F_76 ( struct V_105 * V_127 , unsigned int V_171 , int V_122 ,
int V_4 , T_12 * V_172 )
{
struct V_58 * V_59 = V_127 -> V_104 ;
T_2 * V_60 = V_59 -> V_61 ;
int V_173 = V_127 -> V_174 & 0xff ;
int V_102 = F_77 ( V_171 ) ;
int V_175 = F_78 ( V_171 ) ;
int V_176 = 1 ;
T_13 V_177 ;
void * V_178 ;
if ( F_79 ( V_127 ) ) {
if ( V_102 == 0 ) {
unsigned int V_34 ;
V_34 = ( ( V_122 & 0xFFF ) <<
V_39 ) |
( V_179
<< V_41 ) |
( V_59 -> V_18 <<
V_42 ) ;
V_178 = V_60 -> V_27 + V_34 ;
goto V_180;
} else {
goto V_181;
}
}
if ( V_173 == ( V_59 -> V_142 + 1 ) ) {
if ( V_102 != 0 )
goto V_181;
V_176 = 0 ;
}
V_177 . V_43 = 0 ;
V_177 . V_182 = ( V_122 & 0xFFF ) ;
V_177 . V_183 = V_175 ;
V_177 . V_101 = V_102 ;
V_177 . V_127 = V_173 ;
V_177 . type = V_176 ;
V_178 = V_60 -> V_141 [ V_59 -> V_18 ] +
V_177 . V_43 ;
V_180:
switch ( V_4 ) {
case 4 :
* V_172 = F_45 ( V_178 ) ;
break;
case 2 :
* V_172 = F_80 ( V_178 ) ;
break;
case 1 :
* V_172 = F_81 ( V_178 ) ;
break;
default:
return V_184 ;
}
F_82 ( V_4 , * V_172 , V_173 , V_102 , V_175 , V_122 ) ;
return 0 ;
V_181:
switch ( V_4 ) {
case 4 :
* V_172 = 0xFFFFFFFF ;
break;
case 2 :
* V_172 = 0xFFFF ;
break;
case 1 :
* V_172 = 0xFF ;
break;
default:
return V_184 ;
}
return 0 ;
}
static int F_83 ( struct V_105 * V_127 , unsigned int V_171 , int V_122 ,
int V_4 , T_12 V_172 )
{
struct V_58 * V_59 = V_127 -> V_104 ;
T_2 * V_60 = V_59 -> V_61 ;
int V_173 = V_127 -> V_174 & 0xff ;
int V_102 = F_77 ( V_171 ) ;
int V_175 = F_78 ( V_171 ) ;
int V_176 = 1 ;
T_13 V_177 ;
void * V_178 ;
T_12 V_185 = ( T_12 ) V_172 ;
T_14 V_186 = ( T_14 ) V_172 ;
T_6 V_187 = ( T_6 ) V_172 ;
if ( F_79 ( V_127 ) ) {
if ( V_102 == 0 ) {
unsigned int V_34 ;
V_34 = ( ( V_122 & 0xFFF ) <<
V_39 ) |
( V_179
<< V_41 ) |
( V_59 -> V_18 <<
V_42 ) ;
V_178 = V_60 -> V_27 + V_34 ;
goto V_180;
} else {
goto V_181;
}
}
if ( V_173 == ( V_59 -> V_142 + 1 ) ) {
if ( V_102 != 0 )
goto V_181;
V_176 = 0 ;
}
V_177 . V_43 = 0 ;
V_177 . V_182 = ( V_122 & 0xFFF ) ;
V_177 . V_183 = V_175 ;
V_177 . V_101 = V_102 ;
V_177 . V_127 = V_173 ;
V_177 . type = V_176 ;
V_178 = V_60 -> V_141 [ V_59 -> V_18 ] +
V_177 . V_43 ;
V_180:
switch ( V_4 ) {
case 4 :
F_46 ( V_178 , V_185 ) ;
F_84 ( V_4 , V_185 , V_173 , V_102 , V_175 , V_122 ) ;
break;
case 2 :
F_85 ( V_178 , V_186 ) ;
F_84 ( V_4 , V_186 , V_173 , V_102 , V_175 , V_122 ) ;
break;
case 1 :
F_86 ( V_178 , V_187 ) ;
F_84 ( V_4 , V_187 , V_173 , V_102 , V_175 , V_122 ) ;
break;
default:
return V_184 ;
}
V_181:
return 0 ;
}
static unsigned int F_87 ( struct V_51 * V_52 )
{
if ( V_52 -> V_188 )
F_88 ( V_52 ) ;
return 0 ;
}
static void F_89 ( struct V_51 * V_52 )
{
F_20 ( V_53 , 1UL << V_52 -> V_7 ) ;
}
static void F_90 ( struct V_51 * V_52 )
{
F_91 ( V_52 ) ;
F_20 ( V_54 , 1UL << V_52 -> V_7 ) ;
}
static void F_92 ( struct V_51 * V_52 )
{
F_20 ( V_55 , 1UL << V_52 -> V_7 ) ;
F_88 ( V_52 ) ;
}
int F_93 ( struct V_100 * V_158 , struct V_188 * V_57 )
{
struct V_58 * V_59 ;
T_2 * V_60 ;
struct V_189 V_190 ;
int V_191 ;
T_5 V_192 ;
T_5 V_193 ;
T_15 V_194 ;
int V_195 ;
int V_10 ;
int V_7 ;
int V_17 ;
V_7 = F_30 ( - 1 ) ;
if ( ! V_7 )
return - V_196 ;
if ( V_57 -> V_197 . V_198 == 0 ) {
F_94 ( & V_158 -> V_101 , L_31 ) ;
V_17 = - V_30 ;
goto V_199;
}
V_191 = V_57 -> V_197 . V_191 ;
V_59 = F_95 ( V_191 ) ;
F_42 ( ! V_59 ) ;
V_60 = V_59 -> V_61 ;
V_195 = F_96 ( V_60 , 1 , 0 , 0 ) ;
if ( V_195 >= 0 ) {
T_16 V_200 = { {
. V_201 = 0 ,
. V_202 = 1 ,
} } ;
V_195 += V_203 ;
V_192 = V_204 +
V_195 * V_205 ;
V_193 = V_192 + V_205 - 1 ;
V_194 = V_192 + V_205 - 8 ;
V_190 . V_1 = ( unsigned int ) V_200 . V_43 ;
} else {
V_195 = F_64 ( V_60 , 1 , 0 , 0 ) ;
if ( V_195 < 0 ) {
F_94 ( & V_158 -> V_101 , L_32 ,
V_57 -> V_197 . V_206 ? L_33 : L_34 ) ;
V_17 = - V_30 ;
goto V_207;
}
V_192 = V_204 +
V_195 * V_205 ;
V_193 = V_192 + V_205 - 1 ;
V_194 = V_192 + V_208 -
V_209 ;
V_190 . V_1 = V_195 ;
}
V_10 = F_2 ( V_7 ) ;
V_17 = F_97 ( V_60 , F_32 ( V_10 ) , F_33 ( V_10 ) ,
V_71 , V_7 , V_59 -> V_18 ,
V_195 , V_192 , V_193 ,
V_60 -> V_21 ) ;
if ( V_17 < 0 ) {
F_94 ( & V_158 -> V_101 , L_35 ) ;
goto V_210;
}
F_98 ( V_7 , V_57 ) ;
V_190 . V_211 = V_194 >> 32 ;
V_190 . V_212 = V_194 & 0xffffffff ;
F_99 ( V_7 , & V_190 ) ;
F_34 ( V_7 , & V_213 , F_26 ) ;
F_36 ( V_7 , V_59 ) ;
return 0 ;
V_210:
V_207:
V_199:
F_37 ( V_7 ) ;
return V_17 ;
}
void F_100 ( unsigned int V_7 )
{
F_37 ( V_7 ) ;
}
