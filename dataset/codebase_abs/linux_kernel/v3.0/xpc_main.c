static void
F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( F_3 ( V_3 -> V_4 ) ) ;
( void ) F_4 ( V_3 ) ;
F_2 ( V_3 -> V_4 != 0 ) ;
F_2 ( V_5 . V_6 ( F_5 ( V_3 ) ) ) ;
}
static void
F_6 ( unsigned long V_7 )
{
V_5 . V_8 () ;
if ( F_7 ( V_9 ) )
F_8 ( & V_10 ) ;
V_11 . V_12 = V_13 + ( V_14 * V_15 ) ;
F_9 ( & V_11 ) ;
}
static void
F_10 ( void )
{
V_5 . V_16 () ;
F_11 ( & V_11 ) ;
V_11 . V_17 = F_6 ;
F_6 ( 0 ) ;
}
static void
F_12 ( void )
{
F_13 ( & V_11 ) ;
V_5 . V_18 () ;
}
static void
F_14 ( void )
{
struct V_2 * V_3 ;
short V_19 ;
enum V_20 V_21 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
if ( V_23 )
break;
if ( V_19 == V_24 )
continue;
V_3 = & V_25 [ V_19 ] ;
if ( V_3 -> V_26 == V_27 ||
V_3 -> V_26 == V_28 ) {
continue;
}
V_21 = V_5 . V_29 ( V_3 ) ;
if ( V_21 != V_30 )
F_15 ( V_3 , V_21 ) ;
}
}
static int
F_16 ( void * V_31 )
{
int V_32 = 0 ;
F_17 ( V_33 , F_18 ( V_34 ) ) ;
V_9 = V_13 + ( V_35 * V_15 ) ;
F_10 () ;
while ( ! V_23 ) {
F_19 ( V_36 , L_1
L_2 ,
( int ) ( V_9 - V_13 ) ,
V_37 ) ;
if ( F_7 ( V_9 ) ) {
V_9 = V_13 +
( V_35 * V_15 ) ;
F_19 ( V_36 , L_3 ) ;
F_14 () ;
if ( F_20 () )
V_32 = 1 ;
}
if ( V_37 > 0 || V_32 != 0 ) {
V_32 = 0 ;
F_19 ( V_36 , L_4
L_5 ) ;
V_5 . V_38 () ;
}
( void ) F_21 ( V_10 ,
( F_7 (
V_9 ) ||
V_37 > 0 ||
V_23 ) ) ;
}
F_12 () ;
F_19 ( V_36 , L_6 ) ;
F_22 ( & V_39 ) ;
return 0 ;
}
static int
F_23 ( void * V_31 )
{
F_24 () ;
F_19 ( V_36 , L_7 ) ;
F_22 ( & V_40 ) ;
return 0 ;
}
static void
F_25 ( struct V_2 * V_3 )
{
while ( V_3 -> V_26 != V_28 ||
F_26 ( & V_3 -> V_41 ) > 0 ||
! F_4 ( V_3 ) ) {
F_27 ( V_3 ) ;
F_28 ( & V_3 -> V_42 ) ;
( void ) F_21 ( V_3 -> V_43 ,
( F_26 ( & V_3 -> V_42 ) > 0 ||
V_3 -> V_44 . V_45 != 0 ||
( V_3 -> V_26 == V_28 &&
F_26 ( & V_3 -> V_41 ) == 0 &&
F_4 ( V_3 ) ) ) ) ;
F_29 ( & V_3 -> V_42 , 1 ) ;
}
}
void *
F_30 ( T_1 V_46 , T_2 V_47 , void * * V_48 )
{
* V_48 = F_31 ( V_46 , V_47 ) ;
if ( * V_48 == NULL )
return NULL ;
if ( ( V_49 ) * V_48 == F_32 ( ( V_49 ) * V_48 ) )
return * V_48 ;
F_33 ( * V_48 ) ;
* V_48 = F_31 ( V_46 + V_50 , V_47 ) ;
if ( * V_48 == NULL )
return NULL ;
return ( void * ) F_32 ( ( V_49 ) * V_48 ) ;
}
static enum V_20
F_34 ( struct V_2 * V_3 )
{
enum V_20 V_21 ;
int V_51 ;
struct V_52 * V_53 ;
short V_19 = F_5 ( V_3 ) ;
F_2 ( V_3 -> V_54 != NULL ) ;
V_3 -> V_54 = F_31 ( sizeof( struct V_52 ) * V_55 ,
V_56 ) ;
if ( V_3 -> V_54 == NULL ) {
F_35 ( V_57 , L_8 ) ;
return V_58 ;
}
V_3 -> V_59 =
F_30 ( V_60 ,
V_56 , & V_3 ->
V_61 ) ;
if ( V_3 -> V_59 == NULL ) {
F_35 ( V_57 , L_9 ) ;
V_21 = V_58 ;
goto V_62;
}
V_3 -> V_44 . V_45 = 0 ;
F_36 ( & V_3 -> V_63 ) ;
F_29 ( & V_3 -> V_42 , 1 ) ;
F_37 ( & V_3 -> V_43 ) ;
V_3 -> V_64 = V_55 ;
F_29 ( & V_3 -> V_41 , 0 ) ;
F_29 ( & V_3 -> V_65 , 0 ) ;
for ( V_51 = 0 ; V_51 < V_3 -> V_64 ; V_51 ++ ) {
V_53 = & V_3 -> V_54 [ V_51 ] ;
V_53 -> V_19 = V_19 ;
V_53 -> V_66 = V_51 ;
V_53 -> V_47 = V_67 ;
F_29 ( & V_53 -> V_68 , 0 ) ;
F_29 ( & V_53 -> V_69 , 0 ) ;
F_29 ( & V_53 -> V_70 , 0 ) ;
F_29 ( & V_53 -> V_71 , 0 ) ;
F_29 ( & V_53 -> V_72 , 0 ) ;
F_36 ( & V_53 -> V_73 ) ;
F_38 ( & V_53 -> V_74 ) ;
F_29 ( & V_53 -> V_75 , 0 ) ;
F_37 ( & V_53 -> V_76 ) ;
F_37 ( & V_53 -> V_77 ) ;
}
V_21 = V_5 . V_78 ( V_3 ) ;
if ( V_21 != V_30 )
goto V_79;
V_3 -> V_80 = V_81 ;
return V_30 ;
V_79:
F_33 ( V_3 -> V_61 ) ;
V_3 -> V_59 = NULL ;
V_62:
F_33 ( V_3 -> V_54 ) ;
V_3 -> V_54 = NULL ;
return V_21 ;
}
static void
F_39 ( struct V_2 * V_3 )
{
F_2 ( F_26 ( & V_3 -> V_65 ) != 0 ) ;
F_2 ( F_26 ( & V_3 -> V_41 ) != 0 ) ;
F_2 ( V_3 -> V_80 != V_81 ) ;
V_3 -> V_80 = V_82 ;
F_40 ( V_3 -> V_83 , ( F_26 ( & V_3 -> V_71 ) == 0 ) ) ;
V_5 . V_84 ( V_3 ) ;
F_33 ( V_3 -> V_61 ) ;
V_3 -> V_59 = NULL ;
F_33 ( V_3 -> V_54 ) ;
V_3 -> V_54 = NULL ;
V_3 -> V_80 = V_85 ;
}
static int
F_41 ( void * V_86 )
{
short V_19 = ( V_49 ) V_86 ;
struct V_2 * V_3 = & V_25 [ V_19 ] ;
unsigned long V_87 ;
F_2 ( V_19 < 0 || V_19 >= V_22 ) ;
F_42 ( & V_3 -> V_88 , V_87 ) ;
if ( V_3 -> V_26 == V_28 ) {
V_3 -> V_26 = V_27 ;
F_43 ( & V_3 -> V_88 , V_87 ) ;
V_3 -> V_89 = 0 ;
return 0 ;
}
F_2 ( V_3 -> V_26 != V_90 ) ;
V_3 -> V_26 = V_91 ;
F_44 ( V_3 , 0 , 0 ) ;
F_43 ( & V_3 -> V_88 , V_87 ) ;
F_19 ( V_36 , L_10 , V_19 ) ;
V_5 . V_92 ( V_19 ) ;
if ( F_34 ( V_3 ) == V_30 ) {
( void ) F_45 ( V_3 ) ;
if ( V_5 . V_93 ( V_3 ) == V_30 ) {
F_46 ( V_3 ) ;
F_25 ( V_3 ) ;
}
F_47 ( V_3 ) ;
F_39 ( V_3 ) ;
}
V_5 . V_94 ( V_19 ) ;
F_48 ( V_3 ) ;
if ( V_3 -> V_95 == V_96 ) {
V_5 . V_97 ( V_3 ) ;
}
return 0 ;
}
void
F_49 ( struct V_2 * V_3 )
{
short V_19 = F_5 ( V_3 ) ;
unsigned long V_87 ;
struct V_98 * V_99 ;
F_42 ( & V_3 -> V_88 , V_87 ) ;
F_2 ( V_3 -> V_26 != V_27 ) ;
V_3 -> V_26 = V_90 ;
F_44 ( V_3 , V_100 , __LINE__ ) ;
F_43 ( & V_3 -> V_88 , V_87 ) ;
V_99 = F_50 ( F_41 , ( void * ) ( ( V_49 ) V_19 ) , L_11 ,
V_19 ) ;
if ( F_51 ( V_99 ) ) {
F_42 ( & V_3 -> V_88 , V_87 ) ;
V_3 -> V_26 = V_27 ;
F_44 ( V_3 , V_101 , __LINE__ ) ;
F_43 ( & V_3 -> V_88 , V_87 ) ;
}
}
void
F_52 ( struct V_52 * V_53 , int V_102 )
{
int V_103 = F_26 ( & V_53 -> V_69 ) ;
int V_104 = F_26 ( & V_53 -> V_68 ) ;
int V_105 ;
F_2 ( V_102 <= 0 ) ;
if ( V_103 > 0 ) {
V_105 = ( V_102 > V_103 ) ? V_103 : V_102 ;
V_102 -= V_105 ;
F_19 ( V_57 , L_12
L_13 , V_105 , V_53 -> V_19 , V_53 -> V_66 ) ;
F_53 ( & V_53 -> V_77 , V_105 ) ;
}
if ( V_102 <= 0 )
return;
if ( V_102 + V_104 > V_53 -> V_106 ) {
V_102 = V_53 -> V_106 - V_104 ;
if ( V_102 <= 0 )
return;
}
F_19 ( V_57 , L_14 ,
V_102 , V_53 -> V_19 , V_53 -> V_66 ) ;
F_54 ( V_53 , V_102 , 0 ) ;
}
static void
F_55 ( struct V_2 * V_3 , struct V_52 * V_53 )
{
int (* F_56) ( struct V_52 * ) =
V_5 . F_56 ;
do {
while ( F_56 ( V_53 ) > 0 &&
! ( V_53 -> V_47 & V_107 ) ) {
F_57 ( V_53 ) ;
}
if ( F_58 ( & V_53 -> V_69 ) >
V_53 -> V_108 ) {
F_28 ( & V_53 -> V_69 ) ;
break;
}
F_19 ( V_57 , L_15
L_16 ) ;
( void ) F_59 ( V_53 -> V_77 ,
( F_56 ( V_53 ) > 0 ||
( V_53 -> V_47 & V_107 ) ) ) ;
F_28 ( & V_53 -> V_69 ) ;
} while ( ! ( V_53 -> V_47 & V_107 ) );
}
static int
F_60 ( void * args )
{
short V_19 = F_61 ( args ) ;
T_3 V_51 = F_62 ( args ) ;
struct V_2 * V_3 = & V_25 [ V_19 ] ;
struct V_52 * V_53 ;
int V_109 ;
unsigned long V_87 ;
int (* F_56) ( struct V_52 * ) =
V_5 . F_56 ;
F_19 ( V_57 , L_17 ,
V_19 , V_51 ) ;
V_53 = & V_3 -> V_54 [ V_51 ] ;
if ( ! ( V_53 -> V_47 & V_107 ) ) {
F_42 ( & V_53 -> V_73 , V_87 ) ;
if ( ! ( V_53 -> V_47 & V_110 ) ) {
V_53 -> V_47 |= V_110 ;
F_43 ( & V_53 -> V_73 , V_87 ) ;
F_63 ( V_53 ) ;
F_42 ( & V_53 -> V_73 , V_87 ) ;
V_53 -> V_47 |= V_111 ;
F_43 ( & V_53 -> V_73 , V_87 ) ;
V_109 = F_56 ( V_53 ) - 1 ;
if ( V_109 > 0 && ! ( V_53 -> V_47 & V_107 ) )
F_52 ( V_53 , V_109 ) ;
} else {
F_43 ( & V_53 -> V_73 , V_87 ) ;
}
F_55 ( V_3 , V_53 ) ;
}
F_42 ( & V_53 -> V_73 , V_87 ) ;
if ( ( V_53 -> V_47 & V_111 ) &&
! ( V_53 -> V_47 & V_112 ) ) {
V_53 -> V_47 |= V_112 ;
F_43 ( & V_53 -> V_73 , V_87 ) ;
F_64 ( V_53 , V_113 ) ;
F_42 ( & V_53 -> V_73 , V_87 ) ;
V_53 -> V_47 |= V_114 ;
}
F_43 ( & V_53 -> V_73 , V_87 ) ;
if ( F_65 ( & V_53 -> V_68 ) == 0 &&
F_65 ( & V_3 -> V_65 ) == 0 ) {
V_5 . V_115 ( V_3 ) ;
}
F_66 ( V_53 ) ;
F_19 ( V_57 , L_18 ,
V_19 , V_51 ) ;
F_47 ( V_3 ) ;
return 0 ;
}
void
F_54 ( struct V_52 * V_53 , int V_102 ,
int V_116 )
{
unsigned long V_87 ;
V_49 args = F_67 ( V_53 -> V_19 , V_53 -> V_66 ) ;
struct V_2 * V_3 = & V_25 [ V_53 -> V_19 ] ;
struct V_98 * V_99 ;
void (* V_115) ( struct V_2 * ) =
V_5 . V_115 ;
while ( V_102 -- > 0 ) {
if ( V_116 ) {
if ( ! F_68 ( & V_53 -> V_68 ) ) {
F_69 ( ! ( V_53 -> V_47 &
V_114 ) ) ;
break;
}
} else if ( V_53 -> V_47 & V_107 ) {
break;
} else if ( F_58 ( & V_53 -> V_68 ) == 1 &&
F_58 ( & V_3 -> V_65 ) == 1 ) {
V_5 . V_117 ( V_3 ) ;
}
( void ) F_45 ( V_3 ) ;
F_70 ( V_53 ) ;
V_99 = F_50 ( F_60 , ( void * ) args ,
L_19 , V_53 -> V_19 , V_53 -> V_66 ) ;
if ( F_51 ( V_99 ) ) {
if ( F_65 ( & V_53 -> V_68 ) == 0 &&
F_65 ( & V_3 -> V_65 ) == 0 ) {
V_115 ( V_3 ) ;
}
F_66 ( V_53 ) ;
F_47 ( V_3 ) ;
if ( F_26 ( & V_53 -> V_68 ) <
V_53 -> V_108 ) {
F_42 ( & V_53 -> V_73 , V_87 ) ;
F_71 ( V_53 , V_118 ,
& V_87 ) ;
F_43 ( & V_53 -> V_73 , V_87 ) ;
}
break;
}
}
}
void
F_72 ( int V_51 )
{
unsigned long V_87 ;
short V_19 ;
struct V_2 * V_3 ;
struct V_52 * V_53 ;
int V_119 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
V_3 = & V_25 [ V_19 ] ;
if ( ! F_45 ( V_3 ) )
continue;
V_53 = & V_3 -> V_54 [ V_51 ] ;
if ( ! ( V_53 -> V_47 & V_120 ) ) {
F_47 ( V_3 ) ;
continue;
}
F_73 ( & V_53 -> V_74 ) ;
F_42 ( & V_53 -> V_73 , V_87 ) ;
F_2 ( ! ( V_53 -> V_47 & V_67 ) ) ;
V_119 = 0 ;
if ( V_53 -> V_121 ) {
if ( V_3 -> V_26 != V_28 ) {
F_74 ( & V_3 -> V_63 ) ;
V_3 -> V_44 . V_47 [ V_53 -> V_66 ] |=
V_53 -> V_121 ;
F_75 ( & V_3 -> V_63 ) ;
V_119 = 1 ;
}
V_53 -> V_121 = 0 ;
}
V_53 -> V_47 &= ~ V_120 ;
F_43 ( & V_53 -> V_73 , V_87 ) ;
if ( V_119 )
F_76 ( V_3 ) ;
F_47 ( V_3 ) ;
}
}
static int
F_77 ( void )
{
short V_19 ;
struct V_2 * V_3 ;
V_25 = F_31 ( sizeof( struct V_2 ) *
V_22 , V_56 ) ;
if ( V_25 == NULL ) {
F_35 ( V_36 , L_20 ) ;
return - V_122 ;
}
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
V_3 = & V_25 [ V_19 ] ;
F_2 ( ( V_49 ) V_3 != F_32 ( ( V_49 ) V_3 ) ) ;
V_3 -> V_123 = 0 ;
F_36 ( & V_3 -> V_88 ) ;
V_3 -> V_26 = V_27 ;
F_44 ( V_3 , 0 , 0 ) ;
F_11 ( & V_3 -> V_124 ) ;
V_3 -> V_124 . V_17 =
F_1 ;
V_3 -> V_124 . V_1 = ( unsigned long ) V_3 ;
V_3 -> V_80 = V_125 ;
F_37 ( & V_3 -> V_83 ) ;
F_29 ( & V_3 -> V_71 , 0 ) ;
}
return V_5 . V_126 () ;
}
static void
F_78 ( void )
{
V_5 . V_127 () ;
F_33 ( V_25 ) ;
}
static void
F_79 ( enum V_20 V_95 )
{
short V_19 ;
int V_128 , V_129 = 0 ;
struct V_2 * V_3 ;
unsigned long V_130 , V_4 = 0 ;
F_2 ( V_23 == 1 ) ;
V_23 = 1 ;
F_8 ( & V_10 ) ;
F_73 ( & V_40 ) ;
F_73 ( & V_39 ) ;
( void ) F_80 ( 300 ) ;
V_130 = V_13 + ( V_131 * V_15 ) ;
V_132 = 0 ;
do {
V_128 = 0 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
V_3 = & V_25 [ V_19 ] ;
if ( F_4 ( V_3 ) &&
V_3 -> V_26 == V_27 ) {
continue;
}
V_128 ++ ;
F_15 ( V_3 , V_95 ) ;
if ( V_3 -> V_4 > V_4 )
V_4 = V_3 -> V_4 ;
}
if ( V_5 . V_133 () ) {
if ( F_81 ( V_130 ) ) {
F_82 ( V_36 , L_21
L_22
L_23 , ( V_4 -
V_13 ) / V_15 ) ;
V_130 = V_13 +
( V_131 * V_15 ) ;
V_129 = 1 ;
}
} else if ( V_128 > 0 ) {
if ( V_129 ) {
F_82 ( V_36 , L_24
L_25 ) ;
V_129 = 0 ;
}
} else {
if ( ! V_132 ) {
F_82 ( V_36 , L_26
L_27 ) ;
}
break;
}
( void ) F_80 ( 300 ) ;
} while ( 1 );
F_2 ( V_5 . V_133 () ) ;
F_83 () ;
if ( V_95 == V_134 ) {
( void ) F_84 ( & V_135 ) ;
( void ) F_85 ( & V_136 ) ;
}
F_86 () ;
if ( V_137 )
F_87 ( V_137 ) ;
F_78 () ;
if ( F_20 () )
F_88 () ;
else if ( F_89 () )
F_90 () ;
}
static int
F_91 ( struct V_138 * V_139 , unsigned long V_140 , void * V_141 )
{
enum V_20 V_95 ;
switch ( V_140 ) {
case V_142 :
V_95 = V_143 ;
break;
case V_144 :
V_95 = V_145 ;
break;
case V_146 :
V_95 = V_147 ;
break;
default:
V_95 = V_148 ;
}
F_79 ( V_95 ) ;
return V_149 ;
}
static void
F_92 ( void )
{
struct V_2 * V_3 ;
short V_19 ;
int V_150 ;
long V_151 ;
long V_152 ;
V_23 = 1 ;
V_5 . V_153 () ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
V_3 = & V_25 [ V_19 ] ;
if ( V_5 . V_6 ( V_19 ) ||
V_3 -> V_26 != V_27 ) {
V_5 . V_154 ( V_3 ) ;
V_5 . V_115 ( V_3 ) ;
}
}
V_151 = V_155 * 1000 * 5 ;
V_152 = V_131 * 1000 * 5 ;
while ( 1 ) {
V_150 = V_5 . V_133 () ;
if ( ! V_150 ) {
F_82 ( V_36 , L_28 ) ;
break;
}
if ( ! V_151 -- ) {
for ( V_19 = 0 ; V_19 < V_22 ;
V_19 ++ ) {
if ( V_5 . V_6 ( V_19 ) ) {
F_82 ( V_36 , L_29
L_30
L_31 , V_19 ) ;
}
}
break;
}
if ( ! V_152 -- ) {
F_82 ( V_36 , L_32
L_33 ,
V_151 / ( 1000 * 5 ) ) ;
V_152 = V_131 *
1000 * 5 ;
}
F_93 ( 200 ) ;
}
}
static int
F_94 ( struct V_138 * V_139 , unsigned long V_140 , void * V_141 )
{
#ifdef F_95
switch ( V_140 ) {
case V_156 :
case V_157 :
F_92 () ;
break;
case V_158 :
if ( ! V_159 )
break;
case V_160 :
case V_161 :
V_5 . V_162 () ;
break;
case V_163 :
if ( ! V_159 )
break;
case V_164 :
case V_165 :
V_5 . V_166 () ;
break;
}
#else
F_92 () ;
#endif
return V_149 ;
}
int T_4
F_96 ( void )
{
int V_21 ;
struct V_98 * V_99 ;
F_97 ( V_36 , L_34 ) ;
F_97 ( V_57 , L_35 ) ;
if ( F_20 () ) {
if ( V_22 != 64 ) {
F_35 ( V_36 , L_36 ) ;
V_21 = - V_167 ;
} else {
V_21 = F_98 () ;
}
} else if ( F_89 () ) {
V_21 = F_99 () ;
} else {
V_21 = - V_168 ;
}
if ( V_21 != 0 )
return V_21 ;
V_21 = F_77 () ;
if ( V_21 != 0 ) {
F_35 ( V_36 , L_20 ) ;
goto V_62;
}
V_137 = F_100 ( V_169 ) ;
V_21 = F_101 () ;
if ( V_21 != 0 ) {
F_35 ( V_36 , L_37 ) ;
goto V_79;
}
V_21 = F_102 ( & V_136 ) ;
if ( V_21 != 0 )
F_103 ( V_36 , L_38 ) ;
V_21 = F_104 ( & V_135 ) ;
if ( V_21 != 0 )
F_103 ( V_36 , L_39 ) ;
V_99 = F_50 ( F_16 , NULL , V_170 ) ;
if ( F_51 ( V_99 ) ) {
F_35 ( V_36 , L_40 ) ;
V_21 = - V_171 ;
goto V_172;
}
V_99 = F_50 ( F_23 , NULL ,
V_173 ) ;
if ( F_51 ( V_99 ) ) {
F_35 ( V_36 , L_41 ) ;
F_22 ( & V_40 ) ;
F_79 ( V_134 ) ;
return - V_171 ;
}
F_105 ( V_174 , V_175 ,
V_176 , V_177 ,
V_178 , V_179 ) ;
return 0 ;
V_172:
F_83 () ;
( void ) F_84 ( & V_135 ) ;
( void ) F_85 ( & V_136 ) ;
V_79:
if ( V_137 )
F_87 ( V_137 ) ;
F_78 () ;
V_62:
if ( F_20 () )
F_88 () ;
else if ( F_89 () )
F_90 () ;
return V_21 ;
}
void T_5
F_106 ( void )
{
F_79 ( V_134 ) ;
}
