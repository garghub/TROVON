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
static int F_68 ( struct V_77 * V_78 ,
unsigned long V_79 , void * V_80 )
{
if ( V_79 == V_81 || V_79 == V_82 )
F_64 () ;
return V_83 ;
}
static T_8 F_69 ( int * V_84 , const struct V_85 * V_18 ,
unsigned long V_86 )
{
int V_87 = * V_84 ;
unsigned long V_37 = F_48 ( V_87 ) ;
T_8 V_88 = 0 ;
while ( V_87 < V_89 ) {
if ( F_70 ( ( V_37 & 0xff ) >= 16 ) )
goto V_90;
V_88 |= 1 << ( V_37 & 0xf ) ;
V_87 = F_71 ( V_87 , V_18 ) ;
if ( V_87 >= V_89 )
goto V_90;
V_37 = F_48 ( V_87 ) ;
if ( V_86 != ( V_37 & ~ 0xffUL ) ) {
V_87 -- ;
goto V_90;
}
}
V_90:
* V_84 = V_87 ;
return V_88 ;
}
static void F_72 ( T_3 V_86 , T_8 V_88 , unsigned int V_33 )
{
T_3 V_13 ;
V_13 = ( F_73 ( V_86 , 3 ) |
F_73 ( V_86 , 2 ) |
V_33 << V_91 |
F_73 ( V_86 , 1 ) |
V_88 << V_92 ) ;
F_74 ( L_11 , F_49 () , V_13 ) ;
F_75 ( V_13 ) ;
}
static void F_76 ( const struct V_85 * V_18 , unsigned int V_33 )
{
int V_87 ;
if ( F_70 ( V_33 >= 16 ) )
return;
F_77 () ;
F_78 (cpu, mask) {
unsigned long V_86 = F_48 ( V_87 ) & ~ 0xffUL ;
T_8 V_88 ;
V_88 = F_69 ( & V_87 , V_18 , V_86 ) ;
F_72 ( V_86 , V_88 , V_33 ) ;
}
F_79 () ;
}
static void F_80 ( void )
{
F_81 ( F_76 ) ;
F_82 ( & V_93 ) ;
}
static int F_83 ( struct V_1 * V_2 , const struct V_85 * V_94 ,
bool V_95 )
{
unsigned int V_87 = F_84 ( V_94 , V_96 ) ;
void T_1 * V_24 ;
int V_97 ;
T_3 V_13 ;
if ( F_2 ( V_2 ) )
return - V_26 ;
V_97 = F_19 ( V_2 , V_21 ) ;
if ( V_97 )
F_22 ( V_2 ) ;
V_24 = F_3 ( V_2 ) + V_52 + ( F_1 ( V_2 ) * 8 ) ;
V_13 = F_37 ( F_48 ( V_87 ) ) ;
F_50 ( V_13 , V_24 ) ;
if ( V_97 )
F_25 ( V_2 ) ;
else
F_10 () ;
return V_98 ;
}
static int F_85 ( struct V_77 * V_99 ,
unsigned long V_100 , void * V_101 )
{
if ( V_100 == V_102 ) {
F_17 ( true ) ;
F_57 () ;
} else if ( V_100 == V_103 ) {
F_62 ( 0 ) ;
F_17 ( false ) ;
}
return V_83 ;
}
static void F_86 ( void )
{
F_87 ( & V_104 ) ;
}
static inline void F_86 ( void ) { }
static int F_88 ( struct V_105 * V_2 , unsigned int V_33 ,
T_9 V_106 )
{
struct V_107 * V_108 = & V_109 ;
if ( F_41 ( & V_43 ) )
V_108 = & V_110 ;
if ( V_106 < 16 )
return - V_111 ;
if ( V_106 >= V_4 . V_25 && V_106 < 8192 )
return - V_111 ;
if ( V_106 >= V_112 )
return - V_111 ;
if ( V_106 < 32 ) {
F_89 ( V_33 ) ;
F_90 ( V_2 , V_33 , V_106 , V_108 , V_2 -> V_113 ,
V_114 , NULL , NULL ) ;
F_91 ( V_33 , V_115 ) ;
}
if ( V_106 >= 32 && V_106 < V_4 . V_25 ) {
F_90 ( V_2 , V_33 , V_106 , V_108 , V_2 -> V_113 ,
V_116 , NULL , NULL ) ;
F_92 ( V_33 ) ;
}
if ( V_106 >= 8192 && V_106 < V_112 ) {
if ( ! F_63 () )
return - V_111 ;
F_90 ( V_2 , V_33 , V_106 , V_108 , V_2 -> V_113 ,
V_116 , NULL , NULL ) ;
}
return 0 ;
}
static int F_93 ( struct V_105 * V_2 ,
struct V_117 * V_118 ,
unsigned long * V_3 ,
unsigned int * type )
{
if ( F_94 ( V_118 -> V_119 ) ) {
if ( V_118 -> V_120 < 3 )
return - V_26 ;
switch ( V_118 -> V_121 [ 0 ] ) {
case 0 :
* V_3 = V_118 -> V_121 [ 1 ] + 32 ;
break;
case 1 :
* V_3 = V_118 -> V_121 [ 1 ] + 16 ;
break;
case V_122 :
* V_3 = V_118 -> V_121 [ 1 ] ;
break;
default:
return - V_26 ;
}
* type = V_118 -> V_121 [ 2 ] & V_123 ;
return 0 ;
}
if ( F_95 ( V_118 -> V_119 ) ) {
if( V_118 -> V_120 != 2 )
return - V_26 ;
* V_3 = V_118 -> V_121 [ 0 ] ;
* type = V_118 -> V_121 [ 1 ] ;
return 0 ;
}
return - V_26 ;
}
static int F_96 ( struct V_105 * V_44 , unsigned int V_124 ,
unsigned int V_125 , void * V_126 )
{
int V_46 , V_127 ;
T_9 V_3 ;
unsigned int type = V_128 ;
struct V_117 * V_118 = V_126 ;
V_127 = F_93 ( V_44 , V_118 , & V_3 , & type ) ;
if ( V_127 )
return V_127 ;
for ( V_46 = 0 ; V_46 < V_125 ; V_46 ++ )
F_88 ( V_44 , V_124 + V_46 , V_3 + V_46 ) ;
return 0 ;
}
static void F_97 ( struct V_105 * V_44 , unsigned int V_124 ,
unsigned int V_125 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_125 ; V_46 ++ ) {
struct V_1 * V_2 = F_98 ( V_44 , V_124 + V_46 ) ;
F_99 ( V_124 + V_46 , NULL ) ;
F_100 ( V_2 ) ;
}
}
static int F_101 ( struct V_105 * V_2 ,
struct V_117 * V_118 ,
enum V_129 V_130 )
{
if ( V_118 -> V_119 != V_2 -> V_119 )
return 0 ;
if ( ! F_94 ( V_118 -> V_119 ) )
return 1 ;
if ( V_118 -> V_120 >= 4 &&
V_118 -> V_121 [ 0 ] == 1 && V_118 -> V_121 [ 3 ] != 0 )
return V_2 == F_102 ( V_4 . V_131 [ V_118 -> V_121 [ 1 ] ] ) ;
return V_2 == V_4 . V_44 ;
}
static int F_103 ( struct V_105 * V_2 ,
struct V_117 * V_118 ,
unsigned long * V_3 ,
unsigned int * type )
{
struct V_132 * V_133 ;
int V_127 ;
V_133 = F_104 ( V_118 -> V_121 [ 3 ] ) ;
if ( F_70 ( ! V_133 ) )
return - V_26 ;
V_127 = F_105 ( V_4 . V_131 [ V_118 -> V_121 [ 1 ] ] ,
F_106 ( V_133 ) ) ;
if ( V_127 < 0 )
return V_127 ;
* V_3 = V_127 ;
* type = V_118 -> V_121 [ 2 ] & V_123 ;
return 0 ;
}
static void F_107 ( void )
{
#ifdef F_108
if ( F_109 ( V_134 ) )
F_110 ( & V_10 ) ;
#endif
}
static int T_7 F_111 ( void T_1 * V_5 ,
struct V_135 * V_136 ,
T_2 V_54 ,
T_3 V_65 ,
struct V_137 * V_138 )
{
struct V_132 * V_139 ;
T_2 V_53 ;
int V_140 ;
int V_42 ;
if ( ! F_112 () )
F_113 ( & V_43 ) ;
if ( F_41 ( & V_43 ) )
F_55 ( L_12 ) ;
V_4 . V_119 = V_138 ;
V_4 . V_5 = V_5 ;
V_4 . V_56 = V_136 ;
V_4 . V_54 = V_54 ;
V_4 . V_65 = V_65 ;
F_107 () ;
V_53 = F_6 ( V_4 . V_5 + V_73 ) ;
V_4 . V_141 . V_142 = F_114 ( V_53 ) ;
V_140 = F_115 ( V_53 ) ;
if ( V_140 > 1020 )
V_140 = 1020 ;
V_4 . V_25 = V_140 ;
V_4 . V_44 = F_116 ( V_138 , & V_143 ,
& V_4 ) ;
V_4 . V_141 . V_144 = F_117 ( F_118 ( * V_4 . V_141 . V_144 ) ) ;
if ( F_70 ( ! V_4 . V_44 ) || F_70 ( ! V_4 . V_141 . V_144 ) ) {
V_42 = - V_145 ;
goto V_146;
}
F_119 ( F_39 ) ;
V_139 = F_120 ( V_138 ) ;
if ( F_66 ( V_76 ) && F_63 () &&
V_139 )
F_121 ( V_139 , & V_4 . V_141 , V_4 . V_44 ) ;
F_80 () ;
F_46 () ;
F_64 () ;
F_86 () ;
return 0 ;
V_146:
if ( V_4 . V_44 )
F_122 ( V_4 . V_44 ) ;
F_123 ( V_4 . V_141 . V_144 ) ;
return V_42 ;
}
static int T_7 F_124 ( void T_1 * V_5 )
{
T_2 V_24 = F_6 ( V_5 + V_147 ) & V_59 ;
if ( V_24 != V_60 && V_24 != V_61 )
return - V_69 ;
return 0 ;
}
static int F_125 ( struct V_132 * V_148 )
{
const T_10 * V_149 ;
T_3 V_150 ;
int V_46 ;
V_149 = F_126 ( V_148 , L_13 , NULL ) ;
if ( ! V_149 )
return - 1 ;
V_150 = F_127 ( V_149 , F_128 ( V_148 ) ) ;
if ( V_150 & ~ V_151 )
return - 1 ;
for ( V_46 = 0 ; V_46 < F_129 () ; V_46 ++ )
if ( F_48 ( V_46 ) == V_150 )
return V_46 ;
return - 1 ;
}
static void T_7 F_130 ( struct V_132 * V_152 )
{
struct V_132 * V_153 , * V_154 ;
int V_155 = 0 , V_46 ;
int V_156 ;
struct V_157 * V_158 ;
V_153 = F_131 ( V_152 , L_14 ) ;
if ( ! V_153 )
return;
V_156 = F_132 ( V_153 ) ;
if ( ! V_156 )
return;
V_158 = F_133 ( sizeof( * V_158 ) * V_156 , V_159 ) ;
if ( F_70 ( ! V_158 ) )
return;
F_134 (parts_node, child_part) {
struct V_157 * V_160 ;
int V_161 ;
V_160 = & V_158 [ V_155 ] ;
V_160 -> V_162 = F_106 ( V_154 ) ;
F_55 ( L_15 ,
V_154 -> V_163 , V_155 ) ;
V_161 = F_135 ( V_154 , L_16 ,
sizeof( T_2 ) ) ;
F_70 ( V_161 <= 0 ) ;
for ( V_46 = 0 ; V_46 < V_161 ; V_46 ++ ) {
int V_42 , V_87 ;
T_2 V_164 ;
struct V_132 * V_165 ;
V_42 = F_136 ( V_154 , L_16 ,
V_46 , & V_164 ) ;
if ( F_70 ( V_42 ) )
continue;
V_165 = F_104 ( V_164 ) ;
if ( F_70 ( ! V_165 ) )
continue;
V_87 = F_125 ( V_165 ) ;
if ( F_70 ( V_87 == - 1 ) )
continue;
F_137 ( L_17 , V_165 -> V_166 , V_87 ) ;
F_138 ( V_87 , & V_160 -> V_18 ) ;
}
F_137 ( L_18 ) ;
V_155 ++ ;
}
for ( V_46 = 0 ; V_46 < 16 ; V_46 ++ ) {
unsigned int V_33 ;
struct V_167 * V_168 ;
struct V_117 V_169 = {
. V_119 = V_4 . V_119 ,
. V_120 = 3 ,
. V_121 = {
[ 0 ] = 1 ,
[ 1 ] = V_46 ,
[ 2 ] = V_128 ,
} ,
} ;
V_33 = F_139 ( & V_169 ) ;
if ( F_70 ( ! V_33 ) )
continue;
V_168 = F_140 ( V_4 . V_119 , V_158 , V_156 ,
V_33 , & V_170 ) ;
if ( F_70 ( ! V_168 ) )
continue;
V_4 . V_131 [ V_46 ] = V_168 ;
}
}
static void T_7 F_141 ( struct V_132 * V_139 )
{
int V_127 ;
struct V_171 V_172 ;
T_2 V_173 ;
V_174 . type = V_175 ;
V_174 . V_176 = F_142 ( V_139 , 0 ) ;
if ( ! V_174 . V_176 )
return;
if ( F_143 ( V_139 , L_19 ,
& V_173 ) )
V_173 = 1 ;
V_173 += 3 ;
V_127 = F_144 ( V_139 , V_173 , & V_172 ) ;
if ( ! V_127 )
V_174 . V_36 = V_172 ;
F_145 ( & V_174 ) ;
}
static int T_7 F_146 ( struct V_132 * V_139 , struct V_132 * V_177 )
{
void T_1 * V_5 ;
struct V_135 * V_136 ;
T_3 V_65 ;
T_2 V_54 ;
int V_42 , V_46 ;
V_5 = F_147 ( V_139 , 0 ) ;
if ( ! V_5 ) {
F_59 ( L_20 ,
V_139 -> V_166 ) ;
return - V_178 ;
}
V_42 = F_124 ( V_5 ) ;
if ( V_42 ) {
F_59 ( L_21 ,
V_139 -> V_166 ) ;
goto V_179;
}
if ( F_143 ( V_139 , L_19 , & V_54 ) )
V_54 = 1 ;
V_136 = F_133 ( sizeof( * V_136 ) * V_54 , V_159 ) ;
if ( ! V_136 ) {
V_42 = - V_145 ;
goto V_179;
}
for ( V_46 = 0 ; V_46 < V_54 ; V_46 ++ ) {
struct V_171 V_180 ;
int V_127 ;
V_127 = F_144 ( V_139 , 1 + V_46 , & V_180 ) ;
V_136 [ V_46 ] . V_57 = F_147 ( V_139 , 1 + V_46 ) ;
if ( V_127 || ! V_136 [ V_46 ] . V_57 ) {
F_59 ( L_22 ,
V_139 -> V_166 , V_46 ) ;
V_42 = - V_69 ;
goto V_181;
}
V_136 [ V_46 ] . V_63 = V_180 . V_182 ;
}
if ( F_148 ( V_139 , L_23 , & V_65 ) )
V_65 = 0 ;
V_42 = F_111 ( V_5 , V_136 , V_54 ,
V_65 , & V_139 -> V_119 ) ;
if ( V_42 )
goto V_181;
F_130 ( V_139 ) ;
F_141 ( V_139 ) ;
return 0 ;
V_181:
for ( V_46 = 0 ; V_46 < V_54 ; V_46 ++ )
if ( V_136 [ V_46 ] . V_57 )
F_149 ( V_136 [ V_46 ] . V_57 ) ;
F_150 ( V_136 ) ;
V_179:
F_149 ( V_5 ) ;
return V_42 ;
}
static void T_7
F_151 ( T_11 V_63 , void T_1 * V_57 )
{
static int V_7 = 0 ;
V_183 . V_184 [ V_7 ] . V_63 = V_63 ;
V_183 . V_184 [ V_7 ] . V_57 = V_57 ;
V_183 . V_184 [ V_7 ] . V_64 = V_183 . V_64 ;
V_7 ++ ;
}
static int T_7
F_152 ( struct V_185 * V_186 ,
const unsigned long V_187 )
{
struct V_188 * V_189 =
(struct V_188 * ) V_186 ;
void T_1 * V_57 ;
V_57 = F_153 ( V_189 -> V_190 , V_189 -> V_191 ) ;
if ( ! V_57 ) {
F_59 ( L_24 , V_189 -> V_190 ) ;
return - V_145 ;
}
F_151 ( V_189 -> V_190 , V_57 ) ;
return 0 ;
}
static int T_7
F_154 ( struct V_185 * V_186 ,
const unsigned long V_187 )
{
struct V_192 * V_193 =
(struct V_192 * ) V_186 ;
T_2 V_24 = F_6 ( V_183 . V_5 + V_147 ) & V_59 ;
T_2 V_194 = V_24 == V_61 ? V_66 * 4 : V_66 * 2 ;
void T_1 * V_57 ;
V_57 = F_153 ( V_193 -> V_195 , V_194 ) ;
if ( ! V_57 )
return - V_145 ;
F_151 ( V_193 -> V_195 , V_57 ) ;
return 0 ;
}
static int T_7 F_155 ( void )
{
T_12 V_196 ;
enum V_197 type ;
if ( V_183 . V_64 ) {
type = V_198 ;
V_196 = F_154 ;
} else {
type = V_199 ;
V_196 = F_152 ;
}
if ( F_156 ( type , V_196 , 0 ) > 0 )
return 0 ;
F_55 ( L_25 ) ;
return - V_69 ;
}
static int T_7 F_157 ( struct V_185 * V_186 ,
const unsigned long V_187 )
{
return 0 ;
}
static int T_7 F_158 ( struct V_185 * V_186 ,
const unsigned long V_187 )
{
struct V_192 * V_193 =
(struct V_192 * ) V_186 ;
if ( ( V_193 -> V_200 & V_201 ) && V_193 -> V_195 )
return 0 ;
return - V_69 ;
}
static int T_7 F_159 ( void )
{
int V_7 ;
V_7 = F_156 ( V_199 ,
F_157 , 0 ) ;
if ( V_7 > 0 ) {
V_183 . V_64 = false ;
return V_7 ;
}
V_7 = F_156 ( V_198 ,
F_158 , 0 ) ;
if ( V_7 > 0 )
V_183 . V_64 = true ;
return V_7 ;
}
static bool T_7 F_160 ( struct V_185 * V_186 ,
struct V_202 * V_203 )
{
struct V_204 * V_205 ;
int V_7 ;
V_205 = (struct V_204 * ) V_186 ;
if ( V_205 -> V_206 != V_203 -> V_207 )
return false ;
V_7 = F_159 () ;
if ( V_7 <= 0 )
return false ;
V_183 . V_54 = V_7 ;
return true ;
}
static int T_7 F_161 ( struct V_185 * V_186 ,
const unsigned long V_187 )
{
struct V_192 * V_193 =
(struct V_192 * ) V_186 ;
int V_208 ;
static int V_209 = true ;
if ( ! ( V_193 -> V_200 & V_201 ) )
return 0 ;
V_208 = ( V_193 -> V_200 & V_210 ) ?
V_211 : V_212 ;
if ( V_209 ) {
V_209 = false ;
V_183 . V_176 = V_193 -> V_213 ;
V_183 . V_208 = V_208 ;
V_183 . V_214 = V_193 -> V_215 ;
return 0 ;
}
if ( ( V_183 . V_176 != V_193 -> V_213 ) ||
( V_183 . V_208 != V_208 ) ||
( V_183 . V_214 != V_193 -> V_215 ) )
return - V_26 ;
return 0 ;
}
static bool T_7 F_162 ( void )
{
int V_7 ;
V_7 = F_156 ( V_198 ,
F_161 , 0 ) ;
return ( V_7 > 0 ) ;
}
static void T_7 F_163 ( void )
{
int V_33 ;
if ( ! F_162 () ) {
F_52 ( L_26 ) ;
return;
}
V_174 . type = V_175 ;
V_33 = F_164 ( NULL , V_183 . V_176 ,
V_183 . V_208 ,
V_216 ) ;
if ( V_33 <= 0 )
return;
V_174 . V_176 = V_33 ;
if ( V_183 . V_214 ) {
struct V_171 * V_36 = & V_174 . V_36 ;
V_36 -> V_200 = V_217 ;
V_36 -> V_182 = V_183 . V_214 ;
V_36 -> V_187 = V_36 -> V_182 + V_218 - 1 ;
}
F_145 ( & V_174 ) ;
}
static int T_7
F_165 ( struct V_185 * V_186 , const unsigned long V_187 )
{
struct V_204 * V_205 ;
struct V_137 * V_219 ;
T_13 V_194 ;
int V_46 , V_42 ;
V_205 = (struct V_204 * ) V_186 ;
V_183 . V_5 = F_153 ( V_205 -> V_190 ,
V_220 ) ;
if ( ! V_183 . V_5 ) {
F_59 ( L_27 ) ;
return - V_145 ;
}
V_42 = F_124 ( V_183 . V_5 ) ;
if ( V_42 ) {
F_59 ( L_28 ,
V_183 . V_5 ) ;
goto V_221;
}
V_194 = sizeof( * V_183 . V_184 ) * V_183 . V_54 ;
V_183 . V_184 = F_133 ( V_194 , V_159 ) ;
if ( ! V_183 . V_184 ) {
V_42 = - V_145 ;
goto V_221;
}
V_42 = F_155 () ;
if ( V_42 )
goto V_222;
V_219 = F_166 ( V_183 . V_5 ) ;
if ( ! V_219 ) {
V_42 = - V_145 ;
goto V_222;
}
V_42 = F_111 ( V_183 . V_5 , V_183 . V_184 ,
V_183 . V_54 , 0 , V_219 ) ;
if ( V_42 )
goto V_223;
F_167 ( V_224 , V_219 ) ;
F_163 () ;
return 0 ;
V_223:
F_168 ( V_219 ) ;
V_222:
for ( V_46 = 0 ; V_46 < V_183 . V_54 ; V_46 ++ )
if ( V_183 . V_184 [ V_46 ] . V_57 )
F_149 ( V_183 . V_184 [ V_46 ] . V_57 ) ;
F_150 ( V_183 . V_184 ) ;
V_221:
F_149 ( V_183 . V_5 ) ;
return V_42 ;
}
