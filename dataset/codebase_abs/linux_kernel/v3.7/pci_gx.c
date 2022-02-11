T_1 F_1 ( void * V_1 , const struct V_2 * V_3 ,
T_1 V_4 , T_1 V_5 )
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
F_5 ( L_1
L_2 ) ;
return V_7 % ( V_12 * V_13 ) ;
}
V_8 = V_7 % V_8 ;
F_6 (cpu, &intr_cpus_map) {
if ( V_9 ++ == V_8 )
break;
}
return V_10 ;
}
static int T_2 F_7 ( int V_14 )
{
T_3 * V_15 = & V_16 [ V_14 ] ;
int V_17 ;
V_17 = F_8 ( V_15 , V_14 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_9 ( V_15 , 1 , 0 , 0 ) ;
if ( V_17 < 0 ) {
F_10 ( L_3 ,
V_14 ) ;
goto V_18;
}
V_15 -> V_19 = V_17 ;
#ifdef F_11
V_17 = F_12 ( V_15 , 1 , 0 , 0 ) ;
if ( V_17 < 0 ) {
F_10 ( L_4 ,
V_14 ) ;
goto V_20;
}
V_15 -> V_21 = V_17 ;
V_17 = F_13 ( V_15 , V_15 -> V_21 ,
0 , 0 , V_22 ) ;
if ( V_17 < 0 ) {
F_10 ( L_5 ,
V_14 ) ;
goto V_20;
}
#endif
return V_17 ;
V_18:
#ifdef F_11
V_20:
#endif
F_14 ( V_15 -> V_23 ) ;
return V_17 ;
}
static void
F_15 ( struct V_24 * V_25 )
{
F_16 ( V_26 , 1UL << V_25 -> V_7 ) ;
}
static void
F_17 ( struct V_24 * V_25 )
{
F_16 ( V_27 , 1UL << V_25 -> V_7 ) ;
}
static void
F_18 ( struct V_24 * V_25 )
{
F_16 ( V_28 , 1UL << V_25 -> V_7 ) ;
}
static void
F_19 ( unsigned int V_7 , struct V_29 * V_30 )
{
struct V_31 * V_32 = F_20 ( V_30 ) ;
T_3 * V_33 = V_32 -> V_34 ;
T_4 V_35 = ( T_4 ) F_21 ( V_30 ) ;
int V_36 = V_32 -> V_36 ;
unsigned int V_37 ;
T_4 V_38 ;
F_22 ( V_7 , V_30 ) ;
V_37 = ( V_39 <<
V_40 ) |
( V_41 <<
V_42 ) |
( V_36 << V_43 ) ;
V_38 = V_44 << V_35 ;
F_23 ( V_33 -> V_45 + V_37 , V_38 ) ;
}
static int T_2 F_24 ( struct V_31 * V_32 )
{
int V_9 ;
int V_46 ;
int V_7 ;
int V_47 ;
F_25 ( & V_11 , V_48 ) ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
T_3 * V_15 = V_32 -> V_34 ;
int V_10 ;
V_7 = F_26 () ;
if ( V_7 < 0 ) {
F_10 ( L_6 , V_9 ) ;
goto V_49;
}
V_32 -> V_50 [ V_9 ] = V_7 ;
V_10 = F_2 ( V_7 ) ;
V_47 = F_27 ( V_15 , F_28 ( V_10 ) ,
F_29 ( V_10 ) , V_51 ,
V_7 , V_32 -> V_36 , V_9 ) ;
if ( V_47 < 0 ) {
F_10 ( L_7 , V_9 ) ;
goto V_49;
}
F_30 ( V_7 , & V_52 ,
F_19 ) ;
F_31 ( V_7 , ( void * ) ( T_4 ) V_9 ) ;
F_32 ( V_7 , V_32 ) ;
}
return 0 ;
V_49:
for ( V_46 = 0 ; V_46 < V_9 ; V_46 ++ )
F_33 ( V_32 -> V_50 [ V_46 ] ) ;
return - 1 ;
}
int T_5 F_34 ( void )
{
int V_53 = 0 ;
int V_54 = 0 ;
int V_9 , V_46 ;
if ( ! V_55 ) {
F_35 ( L_8 ) ;
return 0 ;
}
F_35 ( L_9 ) ;
for ( V_9 = 0 ; V_9 < V_56 ; V_9 ++ ) {
int V_17 ;
V_17 = F_7 ( V_9 ) ;
if ( V_17 < 0 )
continue;
V_53 ++ ;
}
if ( V_53 == 0 || F_36 () )
return 0 ;
for ( V_9 = 0 ; V_9 < V_56 ; V_9 ++ ) {
T_3 * V_15 = & V_16 [ V_9 ] ;
int V_17 ;
if ( V_15 -> V_23 < 0 )
continue;
V_17 = F_37 ( V_15 -> V_23 , 0 ,
( V_57 ) & V_58 [ V_9 ] [ 0 ] ,
sizeof( struct V_59 ) * V_60 ,
V_61 ) ;
if ( V_17 < 0 ) {
F_10 ( L_10
L_11 , V_17 , V_9 ) ;
continue;
}
for ( V_46 = 0 ; V_46 < V_60 ; V_46 ++ ) {
if ( V_58 [ V_9 ] [ V_46 ] . V_62 ) {
V_63 [ V_9 ] [ V_46 ] = 1 ;
V_64 ++ ;
}
else if ( V_58 [ V_9 ] [ V_46 ] . V_65 ) {
V_66 ++ ;
}
}
}
if ( V_64 == 0 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_56 ; V_9 ++ ) {
for ( V_46 = 0 ; V_46 < V_60 ; V_46 ++ ) {
if ( V_63 [ V_9 ] [ V_46 ] ) {
V_67 [ V_54 ] . V_34 =
& V_16 [ V_9 ] ;
V_67 [ V_54 ] . V_36 = V_46 ;
V_67 [ V_54 ] . V_14 = V_9 ;
V_54 ++ ;
if ( V_54 == V_64 )
goto V_68;
}
}
}
V_68:
for ( V_9 = 0 ; V_9 < V_64 ; V_9 ++ ) {
struct V_31 * V_32 = & V_67 [ V_9 ] ;
V_32 -> V_69 = V_9 ;
V_32 -> V_70 = & V_71 ;
V_32 -> V_72 = V_73 +
( V_9 * V_74 ) ;
V_32 -> V_75 . V_6 = V_32 -> V_72 +
V_74 - V_76 ;
V_32 -> V_75 . V_77 = V_32 -> V_72 +
V_74 - 1 ;
V_32 -> V_75 . V_78 = V_79 ;
snprintf ( V_32 -> V_80 ,
sizeof( V_32 -> V_80 ) ,
L_12 , V_9 ) ;
V_32 -> V_75 . V_81 = V_32 -> V_80 ;
}
return V_64 ;
}
static int F_38 ( const struct V_82 * V_83 , T_6 V_84 , T_6 V_85 )
{
struct V_31 * V_32 =
(struct V_31 * ) V_83 -> V_86 ;
return V_32 -> V_50 [ V_85 - 1 ] ;
}
static void T_2 F_39 ( struct V_31 *
V_32 )
{
T_3 * V_33 = V_32 -> V_34 ;
struct V_87 * V_88 = V_32 -> V_88 ;
T_7 V_89 ;
T_8 V_90 ;
unsigned int V_37 ;
struct V_87 * V_91 ;
int V_36 ;
int V_92 ;
V_36 = V_32 -> V_36 ;
V_37 =
( V_93 <<
V_40 ) |
( V_94 <<
V_42 ) |
( V_36 << V_43 ) ;
V_89 . V_95 = F_40 ( V_33 -> V_45 +
V_37 ) ;
V_89 . V_96 = 5 ;
F_41 ( V_33 -> V_45 + V_37 ,
V_89 . V_95 ) ;
V_37 =
( V_97 <<
V_40 ) |
( V_94 <<
V_42 ) |
( V_36 << V_43 ) ;
V_90 . V_95 = F_40 ( V_33 -> V_45 +
V_37 ) ;
V_90 . V_98 = 1 ;
F_41 ( V_33 -> V_45 + V_37 ,
V_90 . V_95 ) ;
F_42 (child, &root_bus->children, node) {
struct V_82 * V_99 = V_91 -> V_99 ;
if ( ! V_99 )
continue;
F_43 ( V_91 , V_99 -> V_100 ) ;
}
V_37 =
( V_93 <<
V_40 ) |
( V_94 <<
V_42 ) |
( V_36 << V_43 ) ;
V_89 . V_95 = F_40 ( V_33 -> V_45 +
V_37 ) ;
V_92 = F_44 ( V_33 ,
V_89 . V_101 ,
V_89 . V_96 ,
V_36 ) ;
if ( V_92 < 0 ) {
F_10 ( L_13
L_14 ,
V_36 , V_32 -> V_14 ) ;
}
}
static int T_2 F_45 ( char * V_102 )
{
unsigned long V_103 = 0 ;
unsigned long V_14 ;
unsigned long V_36 ;
if ( V_102 == NULL || ! isdigit ( * V_102 ) )
return - V_104 ;
V_14 = F_46 ( V_102 , ( char * * ) & V_102 , 10 ) ;
if ( V_14 >= V_56 )
return - V_104 ;
if ( * V_102 != ',' )
return - V_104 ;
V_102 ++ ;
if ( ! isdigit ( * V_102 ) )
return - V_104 ;
V_36 = F_46 ( V_102 , ( char * * ) & V_102 , 10 ) ;
if ( V_36 >= V_60 )
return - V_104 ;
if ( * V_102 != '\0' ) {
if ( * V_102 != ',' )
return - V_104 ;
V_102 ++ ;
if ( ! isdigit ( * V_102 ) )
return - V_104 ;
V_103 = F_46 ( V_102 , ( char * * ) & V_102 , 10 ) ;
if ( V_103 > V_105 )
return - V_104 ;
}
V_106 [ V_14 ] [ V_36 ] = V_103 ? : V_107 ;
F_35 ( L_15
L_16 , V_106 [ V_14 ] [ V_36 ] ,
V_36 , V_14 ) ;
return 0 ;
}
int T_5 F_47 ( void )
{
T_1 V_108 ;
F_48 ( V_109 ) ;
int V_110 ;
int V_9 ;
F_34 () ;
if ( V_64 == 0 && V_66 == 0 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_56 ; V_9 ++ ) {
T_3 * V_15 = & V_16 [ V_9 ] ;
if ( V_15 -> V_23 < 0 )
continue;
V_108 = 0 ;
V_15 -> V_45 =
F_49 ( V_15 -> V_23 , V_108 ,
V_111 ) ;
if ( V_15 -> V_45 == NULL ) {
F_10 ( L_17 , V_9 ) ;
F_14 ( V_15 -> V_23 ) ;
V_15 -> V_23 = - 1 ;
continue;
}
}
F_50 ( 250 ) ;
for ( V_110 = 0 , V_9 = 0 ; V_9 < V_64 ; V_9 ++ ) {
struct V_31 * V_32 = & V_67 [ V_9 ] ;
T_3 * V_33 = V_32 -> V_34 ;
T_9 V_112 ;
T_10 V_113 ;
T_11 V_114 ;
struct V_87 * V_115 ;
unsigned int V_37 ;
unsigned int V_116 ;
int V_14 ;
int V_36 ;
int V_17 ;
if ( V_33 -> V_23 < 0 )
continue;
V_14 = V_32 -> V_14 ;
V_36 = V_32 -> V_36 ;
V_37 =
( V_117 <<
V_40 ) |
( V_41 <<
V_42 ) |
( V_36 << V_43 ) ;
V_112 . V_95 =
F_51 ( V_33 -> V_45 +
V_37 ) ;
if ( ( V_112 . V_118 !=
V_119 ) &&
( V_112 . V_118 !=
V_120 ) ) {
if ( V_112 . V_118 ==
V_121 ||
V_112 . V_118 ==
V_122 )
V_58 [ V_14 ] [ V_36 ] . V_65 = 1 ;
continue;
}
if ( V_106 [ V_14 ] [ V_36 ] )
F_50 ( V_106 [ V_14 ] [ V_36 ] * 1000 ) ;
V_17 = F_52 ( V_33 , V_36 ) ;
if ( V_17 < 0 )
F_10 ( L_18
L_14 , V_36 , V_14 ) ;
F_35 ( L_19 , V_9 ,
V_14 , V_32 -> V_36 ) ;
F_50 ( 1000 ) ;
V_37 =
( V_123 <<
V_40 ) |
( V_41 <<
V_42 ) |
( V_36 << V_43 ) ;
V_113 . V_95 =
F_51 ( V_33 -> V_45 +
V_37 ) ;
if ( ! V_113 . V_124 ) {
F_10 ( L_20 ,
V_36 , V_14 ) ;
continue;
}
V_37 =
( V_125 <<
V_40 ) |
( V_41 <<
V_42 ) |
( V_36 << V_43 ) ;
V_114 . V_95 =
F_51 ( V_33 -> V_45 +
V_37 ) ;
V_114 . V_126 = 0 ;
F_23 ( V_33 -> V_45 + V_37 ,
V_114 . V_95 ) ;
V_37 =
( V_127 <<
V_40 ) |
( V_94 <<
V_42 ) |
( V_36 << V_43 ) ;
F_41 ( V_33 -> V_45 + V_37 ,
( V_128 <<
V_129 ) |
V_130 ) ;
V_37 =
( V_131 <<
V_40 ) |
( V_94 <<
V_42 ) |
( V_36 << V_43 ) ;
V_116 =
F_40 ( V_33 -> V_45 +
V_37 ) ;
V_116 = ( V_116 & 0xff ) |
( V_132 << 16 ) ;
F_41 ( V_33 -> V_45 +
V_37 , V_116 ) ;
#ifdef F_11
V_108 = F_53 ( V_33 -> V_21 ) |
( ( ( unsigned long long ) V_36 ) <<
V_133 ) ;
#else
V_17 = F_12 ( V_33 , 1 , 0 , 0 ) ;
if ( V_17 < 0 ) {
F_10 ( L_21
L_22 , V_36 , V_14 ) ;
continue;
}
V_33 -> V_21 [ V_36 ] = V_17 ;
V_17 = F_13 ( V_33 ,
V_33 -> V_21 [ V_36 ] ,
V_36 , 0 , V_22 ) ;
if ( V_17 < 0 ) {
F_10 ( L_23
L_22 , V_36 , V_14 ) ;
continue;
}
V_108 = F_53 ( V_33 -> V_21 [ V_36 ] ) |
( ( ( unsigned long long ) V_36 ) <<
V_133 ) ;
#endif
V_33 -> V_134 [ V_36 ] =
F_49 ( V_33 -> V_23 , V_108 ,
( 1 << V_133 ) ) ;
if ( V_33 -> V_134 [ V_36 ] == NULL ) {
F_10 ( L_24 ,
V_36 , V_14 ) ;
continue;
}
if ( F_24 ( V_32 ) ) {
F_10 ( L_25 ,
V_36 , V_14 ) ;
continue;
}
F_54 ( & V_109 , & V_32 -> V_75 ,
V_32 -> V_72 ) ;
V_32 -> V_135 = V_110 ;
V_115 = F_55 ( NULL , V_110 , V_32 -> V_70 ,
V_32 , & V_109 ) ;
V_32 -> V_88 = V_115 ;
V_110 = V_115 -> V_136 . V_77 + 1 ;
}
F_56 ( V_137 , F_38 ) ;
F_57 () ;
for ( V_9 = 0 ; V_9 < V_64 ; V_9 ++ ) {
struct V_31 * V_32 = & V_67 [ V_9 ] ;
T_3 * V_33 = V_32 -> V_34 ;
struct V_87 * V_88 = V_67 [ V_9 ] . V_88 ;
struct V_87 * V_138 ;
T_12 V_139 ;
struct V_82 * V_83 ;
int V_17 ;
int V_46 ;
if ( V_88 == NULL )
continue;
F_39 ( V_32 ) ;
F_42 (dev, &root_bus->devices, bus_list) {
if ( ( V_83 -> V_140 >> 8 ) == V_132 &&
( F_58 ( V_83 -> V_141 ) == 0 ) ) {
V_138 = V_83 -> V_142 ;
V_67 [ V_9 ] . V_143 [ 0 ] =
* V_138 -> V_2 [ 0 ] ;
V_67 [ V_9 ] . V_143 [ 1 ] =
* V_138 -> V_2 [ 1 ] ;
V_67 [ V_9 ] . V_143 [ 2 ] =
* V_138 -> V_2 [ 2 ] ;
break;
}
}
if ( V_67 [ V_9 ] . V_143 [ 1 ] . V_78 & V_79 )
V_139 =
V_67 [ V_9 ] . V_143 [ 1 ] . V_6 >> 32 ;
else if ( V_67 [ V_9 ] . V_143 [ 2 ] . V_78 & V_144 )
V_139 =
V_67 [ V_9 ] . V_143 [ 2 ] . V_6 >> 32 ;
else {
F_10 ( L_26 ,
V_32 -> V_14 , V_32 -> V_36 ) ;
continue;
}
V_17 = F_12 ( V_33 , 1 , 0 , 0 ) ;
if ( V_17 < 0 ) {
F_10 ( L_27
L_28 , V_32 -> V_14 ,
V_32 -> V_36 ) ;
continue;
}
V_32 -> V_145 = V_17 ;
V_17 = F_13 ( V_33 ,
V_32 -> V_145 ,
V_32 -> V_36 ,
0 ,
0 ) ;
if ( V_17 < 0 ) {
F_10 ( L_29
L_28 , V_32 -> V_14 ,
V_32 -> V_36 ) ;
continue;
}
F_59 (j) {
unsigned long V_146 = V_147 [ V_46 ] ;
unsigned long V_148 = V_149 [ V_46 ] ;
unsigned long V_150 = V_148 - V_146 ;
V_17 = F_60 ( V_33 , 1 , 0 ,
0 ) ;
if ( V_17 < 0 ) {
F_10 ( L_30
L_31 ,
V_32 -> V_14 ,
V_32 -> V_36 , V_46 ) ;
goto V_151;
}
V_32 -> V_152 [ V_46 ] = V_17 ;
V_17 = F_61 ( V_33 ,
V_32 -> V_152 [ V_46 ] ,
V_146 << V_153 ,
V_150 << V_153 ,
V_33 -> V_19 ,
V_32 -> V_36 ,
( V_146 << V_153 ) +
V_154 ,
V_46 ,
V_155 ) ;
if ( V_17 < 0 ) {
F_10 ( L_32
L_31 ,
V_32 -> V_14 ,
V_32 -> V_36 , V_46 ) ;
goto V_151;
}
continue;
V_151:
break;
}
}
return 0 ;
}
void T_2 F_62 ( struct V_87 * V_115 )
{
}
char T_2 * F_63 ( char * V_102 )
{
if ( ! strcmp ( V_102 , L_33 ) ) {
V_55 = 0 ;
return NULL ;
}
return V_102 ;
}
int F_64 ( struct V_82 * V_83 , int V_156 )
{
return F_65 ( V_83 , V_156 ) ;
}
static void T_5
F_66 ( struct V_82 * V_157 )
{
F_67 ( & V_157 -> V_83 , V_158 ) ;
F_68 ( & V_157 -> V_83 , V_154 ) ;
V_157 -> V_83 . V_159 . V_160 =
V_161 ;
}
void T_13 * F_69 ( T_1 V_162 , unsigned long V_4 )
{
struct V_31 * V_32 = NULL ;
T_1 V_163 ;
T_1 V_164 ;
T_1 V_108 ;
T_1 V_6 ;
T_1 V_77 ;
int V_165 ;
int V_9 , V_46 ;
V_6 = V_162 ;
V_77 = V_162 + V_4 - 1 ;
for ( V_9 = 0 ; V_9 < V_64 ; V_9 ++ ) {
if ( V_67 [ V_9 ] . V_88 == NULL )
continue;
for ( V_46 = 1 ; V_46 < 3 ; V_46 ++ ) {
V_163 =
V_67 [ V_9 ] . V_143 [ V_46 ] . V_6 ;
V_164 =
V_67 [ V_9 ] . V_143 [ V_46 ] . V_77 ;
if ( ( V_6 >= V_163 ) && ( V_77 <= V_164 ) ) {
V_32 = & V_67 [ V_9 ] ;
goto V_166;
}
}
}
if ( V_32 == NULL )
return NULL ;
V_166:
V_165 = V_32 -> V_34 -> V_23 ;
V_6 = V_162 - V_32 -> V_72 ;
V_108 = F_53 ( V_32 -> V_145 ) + V_6 ;
return F_49 ( V_165 , V_108 , V_4 ) +
( V_162 & ( V_167 - 1 ) ) ;
}
void F_70 ( struct V_82 * V_83 , void T_13 * V_168 )
{
F_71 ( V_168 ) ;
}
static int T_2 F_72 ( struct V_87 * V_115 ,
unsigned int V_141 ,
int V_108 ,
int V_4 ,
T_14 * V_169 )
{
struct V_31 * V_32 = V_115 -> V_86 ;
T_3 * V_33 = V_32 -> V_34 ;
int V_170 = V_115 -> V_171 & 0xff ;
int V_84 = F_58 ( V_141 ) ;
int V_172 = F_73 ( V_141 ) ;
int V_173 = 1 ;
T_15 V_174 ;
void * V_175 ;
if ( F_74 ( V_115 ) ) {
if ( V_84 == 0 ) {
unsigned int V_37 ;
V_37 = ( ( V_108 & 0xFFF ) <<
V_40 ) |
( V_176
<< V_42 ) |
( V_32 -> V_36 <<
V_43 ) ;
V_175 = V_33 -> V_45 + V_37 ;
goto V_177;
} else {
goto V_178;
}
}
if ( V_170 == ( V_32 -> V_135 + 1 ) ) {
if ( V_84 != 0 )
goto V_178;
V_173 = 0 ;
}
V_174 . V_95 = 0 ;
V_174 . V_179 = ( V_108 & 0xFFF ) ;
V_174 . V_180 = V_172 ;
V_174 . V_83 = V_84 ;
V_174 . V_115 = V_170 ;
V_174 . type = V_173 ;
V_175 = V_33 -> V_134 [ V_32 -> V_36 ] +
V_174 . V_95 ;
V_177:
switch ( V_4 ) {
case 4 :
* V_169 = F_40 ( V_175 ) ;
break;
case 2 :
* V_169 = F_75 ( V_175 ) ;
break;
case 1 :
* V_169 = F_76 ( V_175 ) ;
break;
default:
return V_181 ;
}
F_77 ( V_4 , * V_169 , V_170 , V_84 , V_172 , V_108 ) ;
return 0 ;
V_178:
switch ( V_4 ) {
case 4 :
* V_169 = 0xFFFFFFFF ;
break;
case 2 :
* V_169 = 0xFFFF ;
break;
case 1 :
* V_169 = 0xFF ;
break;
default:
return V_181 ;
}
return 0 ;
}
static int T_2 F_78 ( struct V_87 * V_115 ,
unsigned int V_141 ,
int V_108 ,
int V_4 ,
T_14 V_169 )
{
struct V_31 * V_32 = V_115 -> V_86 ;
T_3 * V_33 = V_32 -> V_34 ;
int V_170 = V_115 -> V_171 & 0xff ;
int V_84 = F_58 ( V_141 ) ;
int V_172 = F_73 ( V_141 ) ;
int V_173 = 1 ;
T_15 V_174 ;
void * V_175 ;
T_14 V_182 = ( T_14 ) V_169 ;
T_16 V_183 = ( T_16 ) V_169 ;
T_6 V_184 = ( T_6 ) V_169 ;
if ( F_74 ( V_115 ) ) {
if ( V_84 == 0 ) {
unsigned int V_37 ;
V_37 = ( ( V_108 & 0xFFF ) <<
V_40 ) |
( V_176
<< V_42 ) |
( V_32 -> V_36 <<
V_43 ) ;
V_175 = V_33 -> V_45 + V_37 ;
goto V_177;
} else {
goto V_178;
}
}
if ( V_170 == ( V_32 -> V_135 + 1 ) ) {
if ( V_84 != 0 )
goto V_178;
V_173 = 0 ;
}
V_174 . V_95 = 0 ;
V_174 . V_179 = ( V_108 & 0xFFF ) ;
V_174 . V_180 = V_172 ;
V_174 . V_83 = V_84 ;
V_174 . V_115 = V_170 ;
V_174 . type = V_173 ;
V_175 = V_33 -> V_134 [ V_32 -> V_36 ] +
V_174 . V_95 ;
V_177:
switch ( V_4 ) {
case 4 :
F_41 ( V_175 , V_182 ) ;
F_79 ( V_4 , V_182 , V_170 , V_84 , V_172 , V_108 ) ;
break;
case 2 :
F_80 ( V_175 , V_183 ) ;
F_79 ( V_4 , V_183 , V_170 , V_84 , V_172 , V_108 ) ;
break;
case 1 :
F_81 ( V_175 , V_184 ) ;
F_79 ( V_4 , V_184 , V_170 , V_84 , V_172 , V_108 ) ;
break;
default:
return V_181 ;
}
V_178:
return 0 ;
}
static unsigned int
F_82 ( struct V_24 * V_25 )
{
if ( V_25 -> V_185 )
F_83 ( V_25 ) ;
return 0 ;
}
static void
F_84 ( struct V_24 * V_25 )
{
F_16 ( V_26 , 1UL << V_25 -> V_7 ) ;
}
static void
F_85 ( struct V_24 * V_25 )
{
F_86 ( V_25 ) ;
F_16 ( V_27 , 1UL << V_25 -> V_7 ) ;
}
static void
F_87 ( struct V_24 * V_25 )
{
F_16 ( V_28 , 1UL << V_25 -> V_7 ) ;
F_83 ( V_25 ) ;
}
int F_88 ( struct V_82 * V_157 , struct V_185 * V_30 )
{
struct V_31 * V_32 ;
T_3 * V_33 ;
struct V_186 V_187 ;
int V_188 ;
T_4 V_189 ;
T_4 V_190 ;
T_17 V_191 ;
int V_192 ;
int V_10 ;
int V_7 ;
int V_17 ;
V_7 = F_26 () ;
if ( V_7 < 0 )
return V_7 ;
if ( V_30 -> V_193 . V_194 == 0 ) {
F_89 ( V_195 , & V_157 -> V_83 ,
L_34
L_35 ) ;
V_17 = - V_196 ;
goto V_197;
}
V_188 = V_30 -> V_193 . V_188 ;
V_32 = F_90 ( V_188 ) ;
F_91 ( ! V_32 ) ;
V_33 = V_32 -> V_34 ;
V_192 = F_60 ( V_33 , 1 , 0 , 0 ) ;
if ( V_192 < 0 ) {
F_89 ( V_195 , & V_157 -> V_83 ,
L_36
L_37
L_38 ,
V_30 -> V_193 . V_198 ? L_39 : L_40 ) ;
V_17 = - V_196 ;
goto V_199;
}
V_10 = F_2 ( V_7 ) ;
V_189 = V_200 +
V_192 * V_201 ;
V_190 = V_189 + V_201 - 1 ;
V_17 = F_92 ( V_33 , F_28 ( V_10 ) , F_29 ( V_10 ) ,
V_51 , V_7 , V_32 -> V_36 ,
V_192 , V_189 , V_190 ,
V_33 -> V_19 ) ;
if ( V_17 < 0 ) {
F_89 ( V_195 , & V_157 -> V_83 , L_41 ) ;
goto V_202;
}
F_93 ( V_7 , V_30 ) ;
V_191 = V_189 + V_203 - V_204 ;
V_187 . V_205 = V_191 >> 32 ;
V_187 . V_206 = V_191 & 0xffffffff ;
V_187 . V_1 = V_192 ;
F_94 ( V_7 , & V_187 ) ;
F_30 ( V_7 , & V_207 , F_22 ) ;
F_32 ( V_7 , V_32 ) ;
return 0 ;
V_202:
V_199:
V_197:
F_33 ( V_7 ) ;
return V_17 ;
}
void F_95 ( unsigned int V_7 )
{
F_33 ( V_7 ) ;
}
