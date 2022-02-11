static inline unsigned int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) < 32 ;
}
static inline void T_1 * F_3 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return F_4 () ;
if ( V_2 -> V_3 <= 1023 )
return V_4 . V_5 ;
return NULL ;
}
static void F_5 ( void T_1 * V_6 )
{
T_2 V_7 = 1000000 ;
while ( F_6 ( V_6 + V_8 ) & V_9 ) {
V_7 -- ;
if ( ! V_7 ) {
F_7 ( L_1 ) ;
return;
}
F_8 () ;
F_9 ( 1 ) ;
} ;
}
static void F_10 ( void )
{
F_5 ( V_4 . V_5 ) ;
}
static void F_11 ( void )
{
F_5 ( F_12 () ) ;
}
static T_3 T_4 F_13 ( void )
{
if ( F_14 ( & V_10 ) )
return F_15 () ;
else
return F_16 () ;
}
static void F_17 ( bool V_11 )
{
void T_1 * V_12 ;
T_2 V_7 = 1000000 ;
T_2 V_13 ;
V_12 = F_12 () ;
V_13 = F_6 ( V_12 + V_14 ) ;
if ( V_11 )
V_13 &= ~ V_15 ;
else
V_13 |= V_15 ;
F_18 ( V_13 , V_12 + V_14 ) ;
if ( ! V_11 ) {
V_13 = F_6 ( V_12 + V_14 ) ;
if ( ! ( V_13 & V_15 ) )
return;
}
while ( V_7 -- ) {
V_13 = F_6 ( V_12 + V_14 ) ;
if ( V_11 ^ ( bool ) ( V_13 & V_16 ) )
break;
F_8 () ;
F_9 ( 1 ) ;
} ;
if ( ! V_7 )
F_7 ( L_2 ,
V_11 ? L_3 : L_4 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_17 )
{
T_2 V_18 = 1 << ( F_1 ( V_2 ) % 32 ) ;
void T_1 * V_6 ;
if ( F_2 ( V_2 ) )
V_6 = F_4 () ;
else
V_6 = V_4 . V_5 ;
return ! ! ( F_6 ( V_6 + V_17 + ( F_1 ( V_2 ) / 32 ) * 4 ) & V_18 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_2 V_17 )
{
T_2 V_18 = 1 << ( F_1 ( V_2 ) % 32 ) ;
void (* F_21)( void );
void T_1 * V_6 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_21 = F_11 ;
} else {
V_6 = V_4 . V_5 ;
F_21 = F_10 ;
}
F_18 ( V_18 , V_6 + V_17 + ( F_1 ( V_2 ) / 32 ) * 4 ) ;
F_21 () ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_19 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
if ( F_24 ( V_2 ) )
F_20 ( V_2 , V_20 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_21 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
enum V_22 V_23 , bool V_13 )
{
T_2 V_24 ;
if ( V_2 -> V_3 >= V_4 . V_25 )
return - V_26 ;
switch ( V_23 ) {
case V_27 :
V_24 = V_13 ? V_28 : V_29 ;
break;
case V_30 :
V_24 = V_13 ? V_31 : V_20 ;
break;
case V_32 :
V_24 = V_13 ? V_19 : V_21 ;
break;
default:
return - V_26 ;
}
F_20 ( V_2 , V_24 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
enum V_22 V_23 , bool * V_13 )
{
if ( V_2 -> V_3 >= V_4 . V_25 )
return - V_26 ;
switch ( V_23 ) {
case V_27 :
* V_13 = F_19 ( V_2 , V_28 ) ;
break;
case V_30 :
* V_13 = F_19 ( V_2 , V_31 ) ;
break;
case V_32 :
* V_13 = ! F_19 ( V_2 , V_21 ) ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( F_1 ( V_2 ) ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) >= 8192 || F_24 ( V_2 ) )
return;
F_31 ( F_1 ( V_2 ) ) ;
}
static int F_32 ( struct V_1 * V_2 , unsigned int type )
{
unsigned int V_33 = F_1 ( V_2 ) ;
void (* F_21)( void );
void T_1 * V_6 ;
if ( V_33 < 16 )
return - V_26 ;
if ( V_33 >= 32 && type != V_34 &&
type != V_35 )
return - V_26 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_21 = F_11 ;
} else {
V_6 = V_4 . V_5 ;
F_21 = F_10 ;
}
return F_33 ( V_33 , type , V_6 , F_21 ) ;
}
static int F_34 ( struct V_1 * V_2 , void * V_36 )
{
if ( V_36 )
F_35 ( V_2 ) ;
else
F_36 ( V_2 ) ;
return 0 ;
}
static T_3 F_37 ( unsigned long V_37 )
{
T_3 V_38 ;
V_38 = ( ( T_3 ) F_38 ( V_37 , 3 ) << 32 |
F_38 ( V_37 , 2 ) << 16 |
F_38 ( V_37 , 1 ) << 8 |
F_38 ( V_37 , 0 ) ) ;
return V_38 ;
}
static T_5 void T_6 F_39 ( struct V_39 * V_40 )
{
T_2 V_41 ;
do {
V_41 = F_13 () ;
if ( F_40 ( V_41 > 15 && V_41 < 1020 ) || V_41 >= 8192 ) {
int V_42 ;
if ( F_41 ( & V_43 ) )
F_29 ( V_41 ) ;
V_42 = F_42 ( V_4 . V_44 , V_41 , V_40 ) ;
if ( V_42 ) {
F_43 ( true , L_5 ) ;
if ( F_41 ( & V_43 ) ) {
if ( V_41 < 8192 )
F_31 ( V_41 ) ;
} else {
F_29 ( V_41 ) ;
}
}
continue;
}
if ( V_41 < 16 ) {
F_29 ( V_41 ) ;
if ( F_41 ( & V_43 ) )
F_31 ( V_41 ) ;
#ifdef F_44
F_45 ( V_41 , V_40 ) ;
#else
F_43 ( true , L_6 ) ;
#endif
continue;
}
} while ( V_41 != V_45 );
}
static void T_7 F_46 ( void )
{
unsigned int V_46 ;
T_3 V_47 ;
void T_1 * V_6 = V_4 . V_5 ;
F_18 ( 0 , V_6 + V_8 ) ;
F_10 () ;
for ( V_46 = 32 ; V_46 < V_4 . V_25 ; V_46 += 32 )
F_18 ( ~ 0 , V_6 + V_48 + V_46 / 8 ) ;
F_47 ( V_6 , V_4 . V_25 , F_10 ) ;
F_18 ( V_49 | V_50 | V_51 ,
V_6 + V_8 ) ;
V_47 = F_37 ( F_48 ( F_49 () ) ) ;
for ( V_46 = 32 ; V_46 < V_4 . V_25 ; V_46 ++ )
F_50 ( V_47 , V_6 + V_52 + V_46 * 8 ) ;
}
static int F_51 ( void )
{
unsigned long V_37 = F_48 ( F_49 () ) ;
T_3 V_53 ;
T_2 V_38 ;
int V_46 ;
V_38 = ( F_38 ( V_37 , 3 ) << 24 |
F_38 ( V_37 , 2 ) << 16 |
F_38 ( V_37 , 1 ) << 8 |
F_38 ( V_37 , 0 ) ) ;
for ( V_46 = 0 ; V_46 < V_4 . V_54 ; V_46 ++ ) {
void T_1 * V_55 = V_4 . V_56 [ V_46 ] . V_57 ;
T_2 V_24 ;
V_24 = F_6 ( V_55 + V_58 ) & V_59 ;
if ( V_24 != V_60 &&
V_24 != V_61 ) {
F_52 ( L_7 , V_55 ) ;
break;
}
do {
V_53 = F_53 ( V_55 + V_62 ) ;
if ( ( V_53 >> 32 ) == V_38 ) {
T_3 V_17 = V_55 - V_4 . V_56 [ V_46 ] . V_57 ;
F_12 () = V_55 ;
F_54 () -> V_63 = V_4 . V_56 [ V_46 ] . V_63 + V_17 ;
F_55 ( L_8 ,
F_49 () , V_37 , V_46 ,
& F_54 () -> V_63 ) ;
return 0 ;
}
if ( V_4 . V_56 [ V_46 ] . V_64 )
break;
if ( V_4 . V_65 ) {
V_55 += V_4 . V_65 ;
} else {
V_55 += V_66 * 2 ;
if ( V_53 & V_67 )
V_55 += V_66 * 2 ;
}
} while ( ! ( V_53 & V_68 ) );
}
F_56 ( true , L_9 ,
F_49 () , V_37 ) ;
return - V_69 ;
}
static void F_57 ( void )
{
if ( ! F_58 () )
F_59 ( L_10 ) ;
F_60 ( V_70 ) ;
if ( F_41 ( & V_43 ) ) {
F_61 ( V_71 ) ;
} else {
F_61 ( V_72 ) ;
}
F_62 ( 1 ) ;
}
static int F_63 ( void )
{
return ! ! ( F_6 ( V_4 . V_5 + V_73 ) & V_74 ) ;
}
static void F_64 ( void )
{
void T_1 * V_12 ;
if ( F_51 () )
return;
F_17 ( true ) ;
V_12 = F_4 () ;
F_18 ( ~ 0 , V_12 + V_75 ) ;
F_65 ( V_12 , F_11 ) ;
if ( F_66 ( V_76 ) && F_63 () )
F_67 () ;
F_57 () ;
}
static int F_68 ( unsigned int V_77 )
{
F_64 () ;
return 0 ;
}
static T_8 F_69 ( int * V_78 , const struct V_79 * V_18 ,
unsigned long V_80 )
{
int V_81 , V_77 = * V_78 ;
unsigned long V_37 = F_48 ( V_77 ) ;
T_8 V_82 = 0 ;
while ( V_77 < V_83 ) {
if ( F_70 ( ( V_37 & 0xff ) >= 16 ) )
goto V_84;
V_82 |= 1 << ( V_37 & 0xf ) ;
V_81 = F_71 ( V_77 , V_18 ) ;
if ( V_81 >= V_83 )
goto V_84;
V_77 = V_81 ;
V_37 = F_48 ( V_77 ) ;
if ( V_80 != ( V_37 & ~ 0xffUL ) ) {
V_77 -- ;
goto V_84;
}
}
V_84:
* V_78 = V_77 ;
return V_82 ;
}
static void F_72 ( T_3 V_80 , T_8 V_82 , unsigned int V_33 )
{
T_3 V_13 ;
V_13 = ( F_73 ( V_80 , 3 ) |
F_73 ( V_80 , 2 ) |
V_33 << V_85 |
F_73 ( V_80 , 1 ) |
V_82 << V_86 ) ;
F_74 ( L_11 , F_49 () , V_13 ) ;
F_75 ( V_13 ) ;
}
static void F_76 ( const struct V_79 * V_18 , unsigned int V_33 )
{
int V_77 ;
if ( F_70 ( V_33 >= 16 ) )
return;
F_77 () ;
F_78 (cpu, mask) {
unsigned long V_80 = F_48 ( V_77 ) & ~ 0xffUL ;
T_8 V_82 ;
V_82 = F_69 ( & V_77 , V_18 , V_80 ) ;
F_72 ( V_80 , V_82 , V_33 ) ;
}
F_79 () ;
}
static void F_80 ( void )
{
F_81 ( F_76 ) ;
F_82 ( V_87 ,
L_12 , F_68 ,
NULL ) ;
}
static int F_83 ( struct V_1 * V_2 , const struct V_79 * V_88 ,
bool V_89 )
{
unsigned int V_77 = F_84 ( V_88 , V_90 ) ;
void T_1 * V_24 ;
int V_91 ;
T_3 V_13 ;
if ( F_2 ( V_2 ) )
return - V_26 ;
V_91 = F_19 ( V_2 , V_21 ) ;
if ( V_91 )
F_22 ( V_2 ) ;
V_24 = F_3 ( V_2 ) + V_52 + ( F_1 ( V_2 ) * 8 ) ;
V_13 = F_37 ( F_48 ( V_77 ) ) ;
F_50 ( V_13 , V_24 ) ;
if ( V_91 )
F_25 ( V_2 ) ;
else
F_10 () ;
return V_92 ;
}
static bool F_85 ( void )
{
return F_6 ( V_4 . V_5 + V_8 ) & V_93 ;
}
static int F_86 ( struct V_94 * V_95 ,
unsigned long V_96 , void * V_97 )
{
if ( V_96 == V_98 ) {
if ( F_85 () )
F_17 ( true ) ;
F_57 () ;
} else if ( V_96 == V_99 && F_85 () ) {
F_62 ( 0 ) ;
F_17 ( false ) ;
}
return V_100 ;
}
static void F_87 ( void )
{
F_88 ( & V_101 ) ;
}
static inline void F_87 ( void ) { }
static int F_89 ( struct V_102 * V_2 , unsigned int V_33 ,
T_9 V_103 )
{
struct V_104 * V_105 = & V_106 ;
if ( F_41 ( & V_43 ) )
V_105 = & V_107 ;
if ( V_103 < 16 )
return - V_108 ;
if ( V_103 >= V_4 . V_25 && V_103 < 8192 )
return - V_108 ;
if ( V_103 >= V_109 )
return - V_108 ;
if ( V_103 < 32 ) {
F_90 ( V_33 ) ;
F_91 ( V_2 , V_33 , V_103 , V_105 , V_2 -> V_110 ,
V_111 , NULL , NULL ) ;
F_92 ( V_33 , V_112 ) ;
}
if ( V_103 >= 32 && V_103 < V_4 . V_25 ) {
F_91 ( V_2 , V_33 , V_103 , V_105 , V_2 -> V_110 ,
V_113 , NULL , NULL ) ;
F_93 ( V_33 ) ;
}
if ( V_103 >= 8192 && V_103 < V_109 ) {
if ( ! F_63 () )
return - V_108 ;
F_91 ( V_2 , V_33 , V_103 , V_105 , V_2 -> V_110 ,
V_113 , NULL , NULL ) ;
}
return 0 ;
}
static int F_94 ( struct V_102 * V_2 ,
struct V_114 * V_115 ,
unsigned long * V_3 ,
unsigned int * type )
{
if ( F_95 ( V_115 -> V_116 ) ) {
if ( V_115 -> V_117 < 3 )
return - V_26 ;
switch ( V_115 -> V_118 [ 0 ] ) {
case 0 :
* V_3 = V_115 -> V_118 [ 1 ] + 32 ;
break;
case 1 :
* V_3 = V_115 -> V_118 [ 1 ] + 16 ;
break;
case V_119 :
* V_3 = V_115 -> V_118 [ 1 ] ;
break;
default:
return - V_26 ;
}
* type = V_115 -> V_118 [ 2 ] & V_120 ;
return 0 ;
}
if ( F_96 ( V_115 -> V_116 ) ) {
if( V_115 -> V_117 != 2 )
return - V_26 ;
* V_3 = V_115 -> V_118 [ 0 ] ;
* type = V_115 -> V_118 [ 1 ] ;
return 0 ;
}
return - V_26 ;
}
static int F_97 ( struct V_102 * V_44 , unsigned int V_121 ,
unsigned int V_122 , void * V_123 )
{
int V_46 , V_124 ;
T_9 V_3 ;
unsigned int type = V_125 ;
struct V_114 * V_115 = V_123 ;
V_124 = F_94 ( V_44 , V_115 , & V_3 , & type ) ;
if ( V_124 )
return V_124 ;
for ( V_46 = 0 ; V_46 < V_122 ; V_46 ++ )
F_89 ( V_44 , V_121 + V_46 , V_3 + V_46 ) ;
return 0 ;
}
static void F_98 ( struct V_102 * V_44 , unsigned int V_121 ,
unsigned int V_122 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_122 ; V_46 ++ ) {
struct V_1 * V_2 = F_99 ( V_44 , V_121 + V_46 ) ;
F_100 ( V_121 + V_46 , NULL ) ;
F_101 ( V_2 ) ;
}
}
static int F_102 ( struct V_102 * V_2 ,
struct V_114 * V_115 ,
enum V_126 V_127 )
{
if ( V_115 -> V_116 != V_2 -> V_116 )
return 0 ;
if ( ! F_95 ( V_115 -> V_116 ) )
return 1 ;
if ( V_115 -> V_117 >= 4 &&
V_115 -> V_118 [ 0 ] == 1 && V_115 -> V_118 [ 3 ] != 0 )
return V_2 == F_103 ( V_4 . V_128 [ V_115 -> V_118 [ 1 ] ] ) ;
return V_2 == V_4 . V_44 ;
}
static int F_104 ( struct V_102 * V_2 ,
struct V_114 * V_115 ,
unsigned long * V_3 ,
unsigned int * type )
{
struct V_129 * V_130 ;
int V_124 ;
V_130 = F_105 ( V_115 -> V_118 [ 3 ] ) ;
if ( F_70 ( ! V_130 ) )
return - V_26 ;
V_124 = F_106 ( V_4 . V_128 [ V_115 -> V_118 [ 1 ] ] ,
F_107 ( V_130 ) ) ;
if ( V_124 < 0 )
return V_124 ;
* V_3 = V_124 ;
* type = V_115 -> V_118 [ 2 ] & V_120 ;
return 0 ;
}
static void F_108 ( void )
{
#ifdef F_109
if ( F_110 ( V_131 ) )
F_111 ( & V_10 ) ;
#endif
}
static int T_7 F_112 ( void T_1 * V_5 ,
struct V_132 * V_133 ,
T_2 V_54 ,
T_3 V_65 ,
struct V_134 * V_135 )
{
struct V_129 * V_136 ;
T_2 V_53 ;
int V_137 ;
int V_42 ;
if ( ! F_113 () )
F_114 ( & V_43 ) ;
if ( F_41 ( & V_43 ) )
F_55 ( L_13 ) ;
V_4 . V_116 = V_135 ;
V_4 . V_5 = V_5 ;
V_4 . V_56 = V_133 ;
V_4 . V_54 = V_54 ;
V_4 . V_65 = V_65 ;
F_108 () ;
V_53 = F_6 ( V_4 . V_5 + V_73 ) ;
V_4 . V_138 . V_139 = F_115 ( V_53 ) ;
V_137 = F_116 ( V_53 ) ;
if ( V_137 > 1020 )
V_137 = 1020 ;
V_4 . V_25 = V_137 ;
V_4 . V_44 = F_117 ( V_135 , & V_140 ,
& V_4 ) ;
V_4 . V_138 . V_141 = F_118 ( F_119 ( * V_4 . V_138 . V_141 ) ) ;
if ( F_70 ( ! V_4 . V_44 ) || F_70 ( ! V_4 . V_138 . V_141 ) ) {
V_42 = - V_142 ;
goto V_143;
}
F_120 ( F_39 ) ;
V_136 = F_121 ( V_135 ) ;
if ( F_66 ( V_76 ) && F_63 () &&
V_136 )
F_122 ( V_136 , & V_4 . V_138 , V_4 . V_44 ) ;
F_80 () ;
F_46 () ;
F_64 () ;
F_87 () ;
return 0 ;
V_143:
if ( V_4 . V_44 )
F_123 ( V_4 . V_44 ) ;
F_124 ( V_4 . V_138 . V_141 ) ;
return V_42 ;
}
static int T_7 F_125 ( void T_1 * V_5 )
{
T_2 V_24 = F_6 ( V_5 + V_144 ) & V_59 ;
if ( V_24 != V_60 && V_24 != V_61 )
return - V_69 ;
return 0 ;
}
static int F_126 ( struct V_129 * V_145 )
{
const T_10 * V_146 ;
T_3 V_147 ;
int V_46 ;
V_146 = F_127 ( V_145 , L_14 , NULL ) ;
if ( ! V_146 )
return - 1 ;
V_147 = F_128 ( V_146 , F_129 ( V_145 ) ) ;
if ( V_147 & ~ V_148 )
return - 1 ;
for ( V_46 = 0 ; V_46 < F_130 () ; V_46 ++ )
if ( F_48 ( V_46 ) == V_147 )
return V_46 ;
return - 1 ;
}
static void T_7 F_131 ( struct V_129 * V_149 )
{
struct V_129 * V_150 , * V_151 ;
int V_152 = 0 , V_46 ;
int V_153 ;
struct V_154 * V_155 ;
V_150 = F_132 ( V_149 , L_15 ) ;
if ( ! V_150 )
return;
V_153 = F_133 ( V_150 ) ;
if ( ! V_153 )
return;
V_155 = F_134 ( sizeof( * V_155 ) * V_153 , V_156 ) ;
if ( F_70 ( ! V_155 ) )
return;
F_135 (parts_node, child_part) {
struct V_154 * V_157 ;
int V_158 ;
V_157 = & V_155 [ V_152 ] ;
V_157 -> V_159 = F_107 ( V_151 ) ;
F_55 ( L_16 ,
V_151 -> V_160 , V_152 ) ;
V_158 = F_136 ( V_151 , L_17 ,
sizeof( T_2 ) ) ;
F_70 ( V_158 <= 0 ) ;
for ( V_46 = 0 ; V_46 < V_158 ; V_46 ++ ) {
int V_42 , V_77 ;
T_2 V_161 ;
struct V_129 * V_162 ;
V_42 = F_137 ( V_151 , L_17 ,
V_46 , & V_161 ) ;
if ( F_70 ( V_42 ) )
continue;
V_162 = F_105 ( V_161 ) ;
if ( F_70 ( ! V_162 ) )
continue;
V_77 = F_126 ( V_162 ) ;
if ( F_70 ( V_77 == - 1 ) )
continue;
F_138 ( L_18 , V_162 -> V_163 , V_77 ) ;
F_139 ( V_77 , & V_157 -> V_18 ) ;
}
F_138 ( L_19 ) ;
V_152 ++ ;
}
for ( V_46 = 0 ; V_46 < 16 ; V_46 ++ ) {
unsigned int V_33 ;
struct V_164 * V_165 ;
struct V_114 V_166 = {
. V_116 = V_4 . V_116 ,
. V_117 = 3 ,
. V_118 = {
[ 0 ] = 1 ,
[ 1 ] = V_46 ,
[ 2 ] = V_125 ,
} ,
} ;
V_33 = F_140 ( & V_166 ) ;
if ( F_70 ( ! V_33 ) )
continue;
V_165 = F_141 ( V_4 . V_116 , V_155 , V_153 ,
V_33 , & V_167 ) ;
if ( F_70 ( ! V_165 ) )
continue;
V_4 . V_128 [ V_46 ] = V_165 ;
}
}
static void T_7 F_142 ( struct V_129 * V_136 )
{
int V_124 ;
struct V_168 V_169 ;
T_2 V_170 ;
V_171 . type = V_172 ;
V_171 . V_173 = F_143 ( V_136 , 0 ) ;
if ( ! V_171 . V_173 )
return;
if ( F_144 ( V_136 , L_20 ,
& V_170 ) )
V_170 = 1 ;
V_170 += 3 ;
V_124 = F_145 ( V_136 , V_170 , & V_169 ) ;
if ( ! V_124 )
V_171 . V_36 = V_169 ;
F_146 ( & V_171 ) ;
}
static int T_7 F_147 ( struct V_129 * V_136 , struct V_129 * V_174 )
{
void T_1 * V_5 ;
struct V_132 * V_133 ;
T_3 V_65 ;
T_2 V_54 ;
int V_42 , V_46 ;
V_5 = F_148 ( V_136 , 0 ) ;
if ( ! V_5 ) {
F_59 ( L_21 ,
V_136 -> V_163 ) ;
return - V_175 ;
}
V_42 = F_125 ( V_5 ) ;
if ( V_42 ) {
F_59 ( L_22 ,
V_136 -> V_163 ) ;
goto V_176;
}
if ( F_144 ( V_136 , L_20 , & V_54 ) )
V_54 = 1 ;
V_133 = F_134 ( sizeof( * V_133 ) * V_54 , V_156 ) ;
if ( ! V_133 ) {
V_42 = - V_142 ;
goto V_176;
}
for ( V_46 = 0 ; V_46 < V_54 ; V_46 ++ ) {
struct V_168 V_177 ;
int V_124 ;
V_124 = F_145 ( V_136 , 1 + V_46 , & V_177 ) ;
V_133 [ V_46 ] . V_57 = F_148 ( V_136 , 1 + V_46 ) ;
if ( V_124 || ! V_133 [ V_46 ] . V_57 ) {
F_59 ( L_23 ,
V_136 -> V_163 , V_46 ) ;
V_42 = - V_69 ;
goto V_178;
}
V_133 [ V_46 ] . V_63 = V_177 . V_179 ;
}
if ( F_149 ( V_136 , L_24 , & V_65 ) )
V_65 = 0 ;
V_42 = F_112 ( V_5 , V_133 , V_54 ,
V_65 , & V_136 -> V_116 ) ;
if ( V_42 )
goto V_178;
F_131 ( V_136 ) ;
F_142 ( V_136 ) ;
return 0 ;
V_178:
for ( V_46 = 0 ; V_46 < V_54 ; V_46 ++ )
if ( V_133 [ V_46 ] . V_57 )
F_150 ( V_133 [ V_46 ] . V_57 ) ;
F_151 ( V_133 ) ;
V_176:
F_150 ( V_5 ) ;
return V_42 ;
}
static void T_7
F_152 ( T_11 V_63 , void T_1 * V_57 )
{
static int V_7 = 0 ;
V_180 . V_181 [ V_7 ] . V_63 = V_63 ;
V_180 . V_181 [ V_7 ] . V_57 = V_57 ;
V_180 . V_181 [ V_7 ] . V_64 = V_180 . V_64 ;
V_7 ++ ;
}
static int T_7
F_153 ( struct V_182 * V_183 ,
const unsigned long V_184 )
{
struct V_185 * V_186 =
(struct V_185 * ) V_183 ;
void T_1 * V_57 ;
V_57 = F_154 ( V_186 -> V_187 , V_186 -> V_188 ) ;
if ( ! V_57 ) {
F_59 ( L_25 , V_186 -> V_187 ) ;
return - V_142 ;
}
F_152 ( V_186 -> V_187 , V_57 ) ;
return 0 ;
}
static int T_7
F_155 ( struct V_182 * V_183 ,
const unsigned long V_184 )
{
struct V_189 * V_190 =
(struct V_189 * ) V_183 ;
T_2 V_24 = F_6 ( V_180 . V_5 + V_144 ) & V_59 ;
T_2 V_191 = V_24 == V_61 ? V_66 * 4 : V_66 * 2 ;
void T_1 * V_57 ;
V_57 = F_154 ( V_190 -> V_192 , V_191 ) ;
if ( ! V_57 )
return - V_142 ;
F_152 ( V_190 -> V_192 , V_57 ) ;
return 0 ;
}
static int T_7 F_156 ( void )
{
T_12 V_193 ;
enum V_194 type ;
if ( V_180 . V_64 ) {
type = V_195 ;
V_193 = F_155 ;
} else {
type = V_196 ;
V_193 = F_153 ;
}
if ( F_157 ( type , V_193 , 0 ) > 0 )
return 0 ;
F_55 ( L_26 ) ;
return - V_69 ;
}
static int T_7 F_158 ( struct V_182 * V_183 ,
const unsigned long V_184 )
{
return 0 ;
}
static int T_7 F_159 ( struct V_182 * V_183 ,
const unsigned long V_184 )
{
struct V_189 * V_190 =
(struct V_189 * ) V_183 ;
if ( ( V_190 -> V_197 & V_198 ) && V_190 -> V_192 )
return 0 ;
return - V_69 ;
}
static int T_7 F_160 ( void )
{
int V_7 ;
V_7 = F_157 ( V_196 ,
F_158 , 0 ) ;
if ( V_7 > 0 ) {
V_180 . V_64 = false ;
return V_7 ;
}
V_7 = F_157 ( V_195 ,
F_159 , 0 ) ;
if ( V_7 > 0 )
V_180 . V_64 = true ;
return V_7 ;
}
static bool T_7 F_161 ( struct V_182 * V_183 ,
struct V_199 * V_200 )
{
struct V_201 * V_202 ;
int V_7 ;
V_202 = (struct V_201 * ) V_183 ;
if ( V_202 -> V_203 != V_200 -> V_204 )
return false ;
V_7 = F_160 () ;
if ( V_7 <= 0 )
return false ;
V_180 . V_54 = V_7 ;
return true ;
}
static int T_7 F_162 ( struct V_182 * V_183 ,
const unsigned long V_184 )
{
struct V_189 * V_190 =
(struct V_189 * ) V_183 ;
int V_205 ;
static int V_206 = true ;
if ( ! ( V_190 -> V_197 & V_198 ) )
return 0 ;
V_205 = ( V_190 -> V_197 & V_207 ) ?
V_208 : V_209 ;
if ( V_206 ) {
V_206 = false ;
V_180 . V_173 = V_190 -> V_210 ;
V_180 . V_205 = V_205 ;
V_180 . V_211 = V_190 -> V_212 ;
return 0 ;
}
if ( ( V_180 . V_173 != V_190 -> V_210 ) ||
( V_180 . V_205 != V_205 ) ||
( V_180 . V_211 != V_190 -> V_212 ) )
return - V_26 ;
return 0 ;
}
static bool T_7 F_163 ( void )
{
int V_7 ;
V_7 = F_157 ( V_195 ,
F_162 , 0 ) ;
return ( V_7 > 0 ) ;
}
static void T_7 F_164 ( void )
{
int V_33 ;
if ( ! F_163 () ) {
F_52 ( L_27 ) ;
return;
}
V_171 . type = V_172 ;
V_33 = F_165 ( NULL , V_180 . V_173 ,
V_180 . V_205 ,
V_213 ) ;
if ( V_33 <= 0 )
return;
V_171 . V_173 = V_33 ;
if ( V_180 . V_211 ) {
struct V_168 * V_36 = & V_171 . V_36 ;
V_36 -> V_197 = V_214 ;
V_36 -> V_179 = V_180 . V_211 ;
V_36 -> V_184 = V_36 -> V_179 + V_215 - 1 ;
}
F_146 ( & V_171 ) ;
}
static int T_7
F_166 ( struct V_182 * V_183 , const unsigned long V_184 )
{
struct V_201 * V_202 ;
struct V_134 * V_216 ;
T_13 V_191 ;
int V_46 , V_42 ;
V_202 = (struct V_201 * ) V_183 ;
V_180 . V_5 = F_154 ( V_202 -> V_187 ,
V_217 ) ;
if ( ! V_180 . V_5 ) {
F_59 ( L_28 ) ;
return - V_142 ;
}
V_42 = F_125 ( V_180 . V_5 ) ;
if ( V_42 ) {
F_59 ( L_29 ,
V_180 . V_5 ) ;
goto V_218;
}
V_191 = sizeof( * V_180 . V_181 ) * V_180 . V_54 ;
V_180 . V_181 = F_134 ( V_191 , V_156 ) ;
if ( ! V_180 . V_181 ) {
V_42 = - V_142 ;
goto V_218;
}
V_42 = F_156 () ;
if ( V_42 )
goto V_219;
V_216 = F_167 ( V_180 . V_5 ) ;
if ( ! V_216 ) {
V_42 = - V_142 ;
goto V_219;
}
V_42 = F_112 ( V_180 . V_5 , V_180 . V_181 ,
V_180 . V_54 , 0 , V_216 ) ;
if ( V_42 )
goto V_220;
F_168 ( V_221 , V_216 ) ;
F_164 () ;
return 0 ;
V_220:
F_169 ( V_216 ) ;
V_219:
for ( V_46 = 0 ; V_46 < V_180 . V_54 ; V_46 ++ )
if ( V_180 . V_181 [ V_46 ] . V_57 )
F_150 ( V_180 . V_181 [ V_46 ] . V_57 ) ;
F_151 ( V_180 . V_181 ) ;
V_218:
F_150 ( V_180 . V_5 ) ;
return V_42 ;
}
