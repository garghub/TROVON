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
if ( F_14 ( V_10 ) )
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
while ( -- V_7 ) {
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
else
F_42 () ;
V_42 = F_43 ( V_4 . V_44 , V_41 , V_40 ) ;
if ( V_42 ) {
F_44 ( true , L_5 ) ;
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
#ifdef F_45
F_46 ( V_41 , V_40 ) ;
#else
F_44 ( true , L_6 ) ;
#endif
continue;
}
} while ( V_41 != V_45 );
}
static void T_7 F_47 ( void )
{
unsigned int V_46 ;
T_3 V_47 ;
void T_1 * V_6 = V_4 . V_5 ;
F_18 ( 0 , V_6 + V_8 ) ;
F_10 () ;
for ( V_46 = 32 ; V_46 < V_4 . V_25 ; V_46 += 32 )
F_18 ( ~ 0 , V_6 + V_48 + V_46 / 8 ) ;
F_48 ( V_6 , V_4 . V_25 , F_10 ) ;
F_18 ( V_49 | V_50 | V_51 ,
V_6 + V_8 ) ;
V_47 = F_37 ( F_49 ( F_50 () ) ) ;
for ( V_46 = 32 ; V_46 < V_4 . V_25 ; V_46 ++ )
F_51 ( V_47 , V_6 + V_52 + V_46 * 8 ) ;
}
static int F_52 ( int (* F_53)( struct V_53 * , void T_1 * ) )
{
int V_54 = - V_55 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_4 . V_56 ; V_46 ++ ) {
void T_1 * V_57 = V_4 . V_58 [ V_46 ] . V_59 ;
T_3 V_60 ;
T_2 V_24 ;
V_24 = F_6 ( V_57 + V_61 ) & V_62 ;
if ( V_24 != V_63 &&
V_24 != V_64 ) {
F_54 ( L_7 , V_57 ) ;
break;
}
do {
V_60 = F_55 ( V_57 + V_65 ) ;
V_54 = F_53 ( V_4 . V_58 + V_46 , V_57 ) ;
if ( ! V_54 )
return 0 ;
if ( V_4 . V_58 [ V_46 ] . V_66 )
break;
if ( V_4 . V_67 ) {
V_57 += V_4 . V_67 ;
} else {
V_57 += V_68 * 2 ;
if ( V_60 & V_69 )
V_57 += V_68 * 2 ;
}
} while ( ! ( V_60 & V_70 ) );
}
return V_54 ? - V_55 : 0 ;
}
static int F_56 ( struct V_53 * V_71 , void T_1 * V_57 )
{
unsigned long V_37 = F_49 ( F_50 () ) ;
T_3 V_60 ;
T_2 V_38 ;
V_38 = ( F_38 ( V_37 , 3 ) << 24 |
F_38 ( V_37 , 2 ) << 16 |
F_38 ( V_37 , 1 ) << 8 |
F_38 ( V_37 , 0 ) ) ;
V_60 = F_55 ( V_57 + V_65 ) ;
if ( ( V_60 >> 32 ) == V_38 ) {
T_3 V_17 = V_57 - V_71 -> V_59 ;
F_12 () = V_57 ;
F_57 () -> V_72 = V_71 -> V_72 + V_17 ;
F_58 ( L_8 ,
F_50 () , V_37 ,
( int ) ( V_71 - V_4 . V_58 ) ,
& F_57 () -> V_72 ) ;
return 0 ;
}
return 1 ;
}
static int F_59 ( void )
{
if ( F_52 ( F_56 ) == 0 )
return 0 ;
F_60 ( true , L_9 ,
F_50 () ,
( unsigned long ) F_49 ( F_50 () ) ) ;
return - V_55 ;
}
static int F_61 ( struct V_53 * V_71 ,
void T_1 * V_57 )
{
T_3 V_60 = F_55 ( V_57 + V_65 ) ;
V_4 . V_73 . V_74 &= ! ! ( V_60 & V_69 ) ;
V_4 . V_73 . V_75 &= ! ! ( V_60 & V_76 ) ;
return 1 ;
}
static void F_62 ( void )
{
F_52 ( F_61 ) ;
F_58 ( L_10 ,
! V_4 . V_73 . V_74 ? L_11 : L_12 ,
! V_4 . V_73 . V_75 ? L_11 : L_12 ) ;
}
static void F_63 ( void )
{
if ( ! F_64 () )
F_65 ( L_13 ) ;
F_66 ( V_77 ) ;
F_67 ( 0 ) ;
if ( F_41 ( & V_43 ) ) {
F_68 ( V_78 ) ;
} else {
F_68 ( V_79 ) ;
}
F_69 ( 1 ) ;
}
static int F_70 ( void )
{
return ! ! ( F_6 ( V_4 . V_5 + V_80 ) & V_81 ) ;
}
static void F_71 ( void )
{
void T_1 * V_12 ;
if ( F_59 () )
return;
F_17 ( true ) ;
V_12 = F_4 () ;
F_18 ( ~ 0 , V_12 + V_82 ) ;
F_72 ( V_12 , F_11 ) ;
if ( F_73 ( V_83 ) && F_70 () )
F_74 () ;
F_63 () ;
}
static int F_75 ( unsigned int V_84 )
{
F_71 () ;
return 0 ;
}
static T_8 F_76 ( int * V_85 , const struct V_86 * V_18 ,
unsigned long V_87 )
{
int V_88 , V_84 = * V_85 ;
unsigned long V_37 = F_49 ( V_84 ) ;
T_8 V_89 = 0 ;
while ( V_84 < V_90 ) {
if ( F_77 ( ( V_37 & 0xff ) >= 16 ) )
goto V_91;
V_89 |= 1 << ( V_37 & 0xf ) ;
V_88 = F_78 ( V_84 , V_18 ) ;
if ( V_88 >= V_90 )
goto V_91;
V_84 = V_88 ;
V_37 = F_49 ( V_84 ) ;
if ( V_87 != ( V_37 & ~ 0xffUL ) ) {
V_84 -- ;
goto V_91;
}
}
V_91:
* V_85 = V_84 ;
return V_89 ;
}
static void F_79 ( T_3 V_87 , T_8 V_89 , unsigned int V_33 )
{
T_3 V_13 ;
V_13 = ( F_80 ( V_87 , 3 ) |
F_80 ( V_87 , 2 ) |
V_33 << V_92 |
F_80 ( V_87 , 1 ) |
V_89 << V_93 ) ;
F_81 ( L_14 , F_50 () , V_13 ) ;
F_82 ( V_13 ) ;
}
static void F_83 ( const struct V_86 * V_18 , unsigned int V_33 )
{
int V_84 ;
if ( F_77 ( V_33 >= 16 ) )
return;
F_84 () ;
F_85 (cpu, mask) {
unsigned long V_87 = F_49 ( V_84 ) & ~ 0xffUL ;
T_8 V_89 ;
V_89 = F_76 ( & V_84 , V_18 , V_87 ) ;
F_79 ( V_87 , V_89 , V_33 ) ;
}
F_42 () ;
}
static void F_86 ( void )
{
F_87 ( F_83 ) ;
F_88 ( V_94 ,
L_15 ,
F_75 , NULL ) ;
}
static int F_89 ( struct V_1 * V_2 , const struct V_86 * V_95 ,
bool V_96 )
{
unsigned int V_84 ;
void T_1 * V_24 ;
int V_97 ;
T_3 V_13 ;
if ( V_96 )
V_84 = F_90 ( V_95 ) ;
else
V_84 = F_91 ( V_95 , V_98 ) ;
if ( V_84 >= V_90 )
return - V_26 ;
if ( F_2 ( V_2 ) )
return - V_26 ;
V_97 = F_19 ( V_2 , V_21 ) ;
if ( V_97 )
F_22 ( V_2 ) ;
V_24 = F_3 ( V_2 ) + V_52 + ( F_1 ( V_2 ) * 8 ) ;
V_13 = F_37 ( F_49 ( V_84 ) ) ;
F_51 ( V_13 , V_24 ) ;
if ( V_97 )
F_25 ( V_2 ) ;
else
F_10 () ;
F_92 ( V_2 , F_93 ( V_84 ) ) ;
return V_99 ;
}
static bool F_94 ( void )
{
return F_6 ( V_4 . V_5 + V_8 ) & V_100 ;
}
static int F_95 ( struct V_101 * V_102 ,
unsigned long V_103 , void * V_104 )
{
if ( V_103 == V_105 ) {
if ( F_94 () )
F_17 ( true ) ;
F_63 () ;
} else if ( V_103 == V_106 && F_94 () ) {
F_69 ( 0 ) ;
F_17 ( false ) ;
}
return V_107 ;
}
static void F_96 ( void )
{
F_97 ( & V_108 ) ;
}
static inline void F_96 ( void ) { }
static int F_98 ( struct V_109 * V_2 , unsigned int V_33 ,
T_9 V_110 )
{
struct V_111 * V_112 = & V_113 ;
if ( F_41 ( & V_43 ) )
V_112 = & V_114 ;
if ( V_110 < 16 )
return - V_115 ;
if ( V_110 >= V_4 . V_25 && V_110 < 8192 )
return - V_115 ;
if ( V_110 >= V_116 )
return - V_115 ;
if ( V_110 < 32 ) {
F_99 ( V_33 ) ;
F_100 ( V_2 , V_33 , V_110 , V_112 , V_2 -> V_117 ,
V_118 , NULL , NULL ) ;
F_101 ( V_33 , V_119 ) ;
}
if ( V_110 >= 32 && V_110 < V_4 . V_25 ) {
F_100 ( V_2 , V_33 , V_110 , V_112 , V_2 -> V_117 ,
V_120 , NULL , NULL ) ;
F_102 ( V_33 ) ;
F_103 ( F_104 ( F_105 ( V_33 ) ) ) ;
}
if ( V_110 >= 8192 && V_110 < V_116 ) {
if ( ! F_70 () )
return - V_115 ;
F_100 ( V_2 , V_33 , V_110 , V_112 , V_2 -> V_117 ,
V_120 , NULL , NULL ) ;
}
return 0 ;
}
static int F_106 ( struct V_109 * V_2 ,
struct V_121 * V_122 ,
unsigned long * V_3 ,
unsigned int * type )
{
if ( F_107 ( V_122 -> V_123 ) ) {
if ( V_122 -> V_124 < 3 )
return - V_26 ;
switch ( V_122 -> V_125 [ 0 ] ) {
case 0 :
* V_3 = V_122 -> V_125 [ 1 ] + 32 ;
break;
case 1 :
* V_3 = V_122 -> V_125 [ 1 ] + 16 ;
break;
case V_126 :
* V_3 = V_122 -> V_125 [ 1 ] ;
break;
default:
return - V_26 ;
}
* type = V_122 -> V_125 [ 2 ] & V_127 ;
return 0 ;
}
if ( F_108 ( V_122 -> V_123 ) ) {
if( V_122 -> V_124 != 2 )
return - V_26 ;
* V_3 = V_122 -> V_125 [ 0 ] ;
* type = V_122 -> V_125 [ 1 ] ;
return 0 ;
}
return - V_26 ;
}
static int F_109 ( struct V_109 * V_44 , unsigned int V_128 ,
unsigned int V_129 , void * V_130 )
{
int V_46 , V_54 ;
T_9 V_3 ;
unsigned int type = V_131 ;
struct V_121 * V_122 = V_130 ;
V_54 = F_106 ( V_44 , V_122 , & V_3 , & type ) ;
if ( V_54 )
return V_54 ;
for ( V_46 = 0 ; V_46 < V_129 ; V_46 ++ ) {
V_54 = F_98 ( V_44 , V_128 + V_46 , V_3 + V_46 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static void F_110 ( struct V_109 * V_44 , unsigned int V_128 ,
unsigned int V_129 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_129 ; V_46 ++ ) {
struct V_1 * V_2 = F_111 ( V_44 , V_128 + V_46 ) ;
F_112 ( V_128 + V_46 , NULL ) ;
F_113 ( V_2 ) ;
}
}
static int F_114 ( struct V_109 * V_2 ,
struct V_121 * V_122 ,
enum V_132 V_133 )
{
if ( V_122 -> V_123 != V_2 -> V_123 )
return 0 ;
if ( ! F_107 ( V_122 -> V_123 ) )
return 1 ;
if ( V_122 -> V_124 >= 4 &&
V_122 -> V_125 [ 0 ] == 1 && V_122 -> V_125 [ 3 ] != 0 )
return V_2 == F_115 ( V_4 . V_134 [ V_122 -> V_125 [ 1 ] ] ) ;
return V_2 == V_4 . V_44 ;
}
static int F_116 ( struct V_109 * V_2 ,
struct V_121 * V_122 ,
unsigned long * V_3 ,
unsigned int * type )
{
struct V_135 * V_136 ;
int V_54 ;
V_136 = F_117 ( V_122 -> V_125 [ 3 ] ) ;
if ( F_77 ( ! V_136 ) )
return - V_26 ;
V_54 = F_118 ( V_4 . V_134 [ V_122 -> V_125 [ 1 ] ] ,
F_119 ( V_136 ) ) ;
if ( V_54 < 0 )
return V_54 ;
* V_3 = V_54 ;
* type = V_122 -> V_125 [ 2 ] & V_127 ;
return 0 ;
}
static int T_7 F_120 ( void T_1 * V_5 ,
struct V_53 * V_137 ,
T_2 V_56 ,
T_3 V_67 ,
struct V_138 * V_139 )
{
T_2 V_60 ;
int V_140 ;
int V_42 ;
if ( ! F_121 () )
F_122 ( & V_43 ) ;
if ( F_41 ( & V_43 ) )
F_58 ( L_16 ) ;
V_4 . V_123 = V_139 ;
V_4 . V_5 = V_5 ;
V_4 . V_58 = V_137 ;
V_4 . V_56 = V_56 ;
V_4 . V_67 = V_67 ;
V_60 = F_6 ( V_4 . V_5 + V_80 ) ;
V_4 . V_73 . V_141 = F_123 ( V_60 ) ;
V_140 = F_124 ( V_60 ) ;
if ( V_140 > 1020 )
V_140 = 1020 ;
V_4 . V_25 = V_140 ;
V_4 . V_44 = F_125 ( V_139 , & V_142 ,
& V_4 ) ;
V_4 . V_73 . V_143 = F_126 ( F_127 ( * V_4 . V_73 . V_143 ) ) ;
V_4 . V_73 . V_74 = true ;
V_4 . V_73 . V_75 = true ;
if ( F_77 ( ! V_4 . V_44 ) || F_77 ( ! V_4 . V_73 . V_143 ) ) {
V_42 = - V_144 ;
goto V_145;
}
F_128 ( F_39 ) ;
F_62 () ;
if ( F_73 ( V_83 ) && F_70 () )
F_129 ( V_139 , & V_4 . V_73 , V_4 . V_44 ) ;
F_86 () ;
F_47 () ;
F_71 () ;
F_96 () ;
return 0 ;
V_145:
if ( V_4 . V_44 )
F_130 ( V_4 . V_44 ) ;
F_131 ( V_4 . V_73 . V_143 ) ;
return V_42 ;
}
static int T_7 F_132 ( void T_1 * V_5 )
{
T_2 V_24 = F_6 ( V_5 + V_146 ) & V_62 ;
if ( V_24 != V_63 && V_24 != V_64 )
return - V_55 ;
return 0 ;
}
static int F_133 ( struct V_135 * V_147 )
{
const T_10 * V_148 ;
T_3 V_149 ;
int V_84 ;
V_148 = F_134 ( V_147 , L_17 , NULL ) ;
if ( ! V_148 )
return - 1 ;
V_149 = F_135 ( V_148 , F_136 ( V_147 ) ) ;
if ( V_149 & ~ V_150 )
return - 1 ;
F_137 (cpu)
if ( F_49 ( V_84 ) == V_149 )
return V_84 ;
return - 1 ;
}
static void T_7 F_138 ( struct V_135 * V_151 )
{
struct V_135 * V_152 , * V_153 ;
int V_154 = 0 , V_46 ;
int V_155 ;
struct V_156 * V_157 ;
V_152 = F_139 ( V_151 , L_18 ) ;
if ( ! V_152 )
return;
V_155 = F_140 ( V_152 ) ;
if ( ! V_155 )
return;
V_157 = F_141 ( sizeof( * V_157 ) * V_155 , V_158 ) ;
if ( F_77 ( ! V_157 ) )
return;
F_142 (parts_node, child_part) {
struct V_156 * V_159 ;
int V_160 ;
V_159 = & V_157 [ V_154 ] ;
V_159 -> V_161 = F_119 ( V_153 ) ;
F_58 ( L_19 ,
V_153 -> V_162 , V_154 ) ;
V_160 = F_143 ( V_153 , L_20 ,
sizeof( T_2 ) ) ;
F_77 ( V_160 <= 0 ) ;
for ( V_46 = 0 ; V_46 < V_160 ; V_46 ++ ) {
int V_42 , V_84 ;
T_2 V_163 ;
struct V_135 * V_164 ;
V_42 = F_144 ( V_153 , L_20 ,
V_46 , & V_163 ) ;
if ( F_77 ( V_42 ) )
continue;
V_164 = F_117 ( V_163 ) ;
if ( F_77 ( ! V_164 ) )
continue;
V_84 = F_133 ( V_164 ) ;
if ( F_77 ( V_84 == - 1 ) )
continue;
F_145 ( L_21 , V_164 , V_84 ) ;
F_146 ( V_84 , & V_159 -> V_18 ) ;
}
F_145 ( L_22 ) ;
V_154 ++ ;
}
for ( V_46 = 0 ; V_46 < 16 ; V_46 ++ ) {
unsigned int V_33 ;
struct V_165 * V_166 ;
struct V_121 V_167 = {
. V_123 = V_4 . V_123 ,
. V_124 = 3 ,
. V_125 = {
[ 0 ] = 1 ,
[ 1 ] = V_46 ,
[ 2 ] = V_131 ,
} ,
} ;
V_33 = F_147 ( & V_167 ) ;
if ( F_77 ( ! V_33 ) )
continue;
V_166 = F_148 ( V_4 . V_123 , V_157 , V_155 ,
V_33 , & V_168 ) ;
if ( F_77 ( ! V_166 ) )
continue;
V_4 . V_134 [ V_46 ] = V_166 ;
}
}
static void T_7 F_149 ( struct V_135 * V_169 )
{
int V_54 ;
struct V_170 V_171 ;
T_2 V_172 ;
V_173 . type = V_174 ;
V_173 . V_175 = F_150 ( V_169 , 0 ) ;
if ( ! V_173 . V_175 )
return;
if ( F_151 ( V_169 , L_23 ,
& V_172 ) )
V_172 = 1 ;
V_172 += 3 ;
V_54 = F_152 ( V_169 , V_172 , & V_171 ) ;
if ( ! V_54 )
V_173 . V_36 = V_171 ;
V_173 . V_176 = V_4 . V_73 . V_74 ;
F_153 ( & V_173 ) ;
}
static int T_7 F_154 ( struct V_135 * V_169 , struct V_135 * V_177 )
{
void T_1 * V_5 ;
struct V_53 * V_137 ;
T_3 V_67 ;
T_2 V_56 ;
int V_42 , V_46 ;
V_5 = F_155 ( V_169 , 0 ) ;
if ( ! V_5 ) {
F_65 ( L_24 , V_169 ) ;
return - V_178 ;
}
V_42 = F_132 ( V_5 ) ;
if ( V_42 ) {
F_65 ( L_25 , V_169 ) ;
goto V_179;
}
if ( F_151 ( V_169 , L_23 , & V_56 ) )
V_56 = 1 ;
V_137 = F_141 ( sizeof( * V_137 ) * V_56 , V_158 ) ;
if ( ! V_137 ) {
V_42 = - V_144 ;
goto V_179;
}
for ( V_46 = 0 ; V_46 < V_56 ; V_46 ++ ) {
struct V_170 V_180 ;
int V_54 ;
V_54 = F_152 ( V_169 , 1 + V_46 , & V_180 ) ;
V_137 [ V_46 ] . V_59 = F_155 ( V_169 , 1 + V_46 ) ;
if ( V_54 || ! V_137 [ V_46 ] . V_59 ) {
F_65 ( L_26 , V_169 , V_46 ) ;
V_42 = - V_55 ;
goto V_181;
}
V_137 [ V_46 ] . V_72 = V_180 . V_182 ;
}
if ( F_156 ( V_169 , L_27 , & V_67 ) )
V_67 = 0 ;
V_42 = F_120 ( V_5 , V_137 , V_56 ,
V_67 , & V_169 -> V_123 ) ;
if ( V_42 )
goto V_181;
F_138 ( V_169 ) ;
F_149 ( V_169 ) ;
return 0 ;
V_181:
for ( V_46 = 0 ; V_46 < V_56 ; V_46 ++ )
if ( V_137 [ V_46 ] . V_59 )
F_157 ( V_137 [ V_46 ] . V_59 ) ;
F_158 ( V_137 ) ;
V_179:
F_157 ( V_5 ) ;
return V_42 ;
}
static void T_7
F_159 ( T_11 V_72 , void T_1 * V_59 )
{
static int V_7 = 0 ;
V_183 . V_184 [ V_7 ] . V_72 = V_72 ;
V_183 . V_184 [ V_7 ] . V_59 = V_59 ;
V_183 . V_184 [ V_7 ] . V_66 = V_183 . V_66 ;
V_7 ++ ;
}
static int T_7
F_160 ( struct V_185 * V_186 ,
const unsigned long V_187 )
{
struct V_188 * V_189 =
(struct V_188 * ) V_186 ;
void T_1 * V_59 ;
V_59 = F_161 ( V_189 -> V_190 , V_189 -> V_191 ) ;
if ( ! V_59 ) {
F_65 ( L_28 , V_189 -> V_190 ) ;
return - V_144 ;
}
F_159 ( V_189 -> V_190 , V_59 ) ;
return 0 ;
}
static int T_7
F_162 ( struct V_185 * V_186 ,
const unsigned long V_187 )
{
struct V_192 * V_193 =
(struct V_192 * ) V_186 ;
T_2 V_24 = F_6 ( V_183 . V_5 + V_146 ) & V_62 ;
T_2 V_194 = V_24 == V_64 ? V_68 * 4 : V_68 * 2 ;
void T_1 * V_59 ;
V_59 = F_161 ( V_193 -> V_195 , V_194 ) ;
if ( ! V_59 )
return - V_144 ;
F_159 ( V_193 -> V_195 , V_59 ) ;
return 0 ;
}
static int T_7 F_163 ( void )
{
T_12 V_196 ;
enum V_197 type ;
if ( V_183 . V_66 ) {
type = V_198 ;
V_196 = F_162 ;
} else {
type = V_199 ;
V_196 = F_160 ;
}
if ( F_164 ( type , V_196 , 0 ) > 0 )
return 0 ;
F_58 ( L_29 ) ;
return - V_55 ;
}
static int T_7 F_165 ( struct V_185 * V_186 ,
const unsigned long V_187 )
{
return 0 ;
}
static int T_7 F_166 ( struct V_185 * V_186 ,
const unsigned long V_187 )
{
struct V_192 * V_193 =
(struct V_192 * ) V_186 ;
if ( ( V_193 -> V_200 & V_201 ) && V_193 -> V_195 )
return 0 ;
return - V_55 ;
}
static int T_7 F_167 ( void )
{
int V_7 ;
V_7 = F_164 ( V_199 ,
F_165 , 0 ) ;
if ( V_7 > 0 ) {
V_183 . V_66 = false ;
return V_7 ;
}
V_7 = F_164 ( V_198 ,
F_166 , 0 ) ;
if ( V_7 > 0 )
V_183 . V_66 = true ;
return V_7 ;
}
static bool T_7 F_168 ( struct V_185 * V_186 ,
struct V_202 * V_203 )
{
struct V_204 * V_205 ;
int V_7 ;
V_205 = (struct V_204 * ) V_186 ;
if ( V_205 -> V_206 != V_203 -> V_207 )
return false ;
V_7 = F_167 () ;
if ( V_7 <= 0 )
return false ;
V_183 . V_56 = V_7 ;
return true ;
}
static int T_7 F_169 ( struct V_185 * V_186 ,
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
V_183 . V_175 = V_193 -> V_213 ;
V_183 . V_208 = V_208 ;
V_183 . V_214 = V_193 -> V_215 ;
return 0 ;
}
if ( ( V_183 . V_175 != V_193 -> V_213 ) ||
( V_183 . V_208 != V_208 ) ||
( V_183 . V_214 != V_193 -> V_215 ) )
return - V_26 ;
return 0 ;
}
static bool T_7 F_170 ( void )
{
int V_7 ;
V_7 = F_164 ( V_198 ,
F_169 , 0 ) ;
return ( V_7 > 0 ) ;
}
static void T_7 F_171 ( void )
{
int V_33 ;
if ( ! F_170 () ) {
F_54 ( L_30 ) ;
return;
}
V_173 . type = V_174 ;
V_33 = F_172 ( NULL , V_183 . V_175 ,
V_183 . V_208 ,
V_216 ) ;
if ( V_33 <= 0 )
return;
V_173 . V_175 = V_33 ;
if ( V_183 . V_214 ) {
struct V_170 * V_36 = & V_173 . V_36 ;
V_36 -> V_200 = V_217 ;
V_36 -> V_182 = V_183 . V_214 ;
V_36 -> V_187 = V_36 -> V_182 + V_218 - 1 ;
}
V_173 . V_176 = V_4 . V_73 . V_74 ;
F_153 ( & V_173 ) ;
}
static int T_7
F_173 ( struct V_185 * V_186 , const unsigned long V_187 )
{
struct V_204 * V_205 ;
struct V_138 * V_219 ;
T_13 V_194 ;
int V_46 , V_42 ;
V_205 = (struct V_204 * ) V_186 ;
V_183 . V_5 = F_161 ( V_205 -> V_190 ,
V_220 ) ;
if ( ! V_183 . V_5 ) {
F_65 ( L_31 ) ;
return - V_144 ;
}
V_42 = F_132 ( V_183 . V_5 ) ;
if ( V_42 ) {
F_65 ( L_32 ,
V_183 . V_5 ) ;
goto V_221;
}
V_194 = sizeof( * V_183 . V_184 ) * V_183 . V_56 ;
V_183 . V_184 = F_141 ( V_194 , V_158 ) ;
if ( ! V_183 . V_184 ) {
V_42 = - V_144 ;
goto V_221;
}
V_42 = F_163 () ;
if ( V_42 )
goto V_222;
V_219 = F_174 ( V_183 . V_5 ) ;
if ( ! V_219 ) {
V_42 = - V_144 ;
goto V_222;
}
V_42 = F_120 ( V_183 . V_5 , V_183 . V_184 ,
V_183 . V_56 , 0 , V_219 ) ;
if ( V_42 )
goto V_223;
F_175 ( V_224 , V_219 ) ;
F_171 () ;
return 0 ;
V_223:
F_176 ( V_219 ) ;
V_222:
for ( V_46 = 0 ; V_46 < V_183 . V_56 ; V_46 ++ )
if ( V_183 . V_184 [ V_46 ] . V_59 )
F_157 ( V_183 . V_184 [ V_46 ] . V_59 ) ;
F_158 ( V_183 . V_184 ) ;
V_221:
F_157 ( V_183 . V_5 ) ;
return V_42 ;
}
