static void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( L_1 , F_3 ( F_4 ( V_2 ) << V_4 ) ,
F_5 ( V_2 ) ,
V_2 -> V_5 ) ;
if ( V_3 && ! F_6 ( V_3 ) ) {
F_2 ( L_2 , F_3 ( F_4 ( V_3 )
<< V_4 ) ,
F_5 ( V_3 ) ,
V_3 -> V_5 ) ;
}
F_2 ( L_3 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
int V_8 ;
if ( ! V_7 || F_8 () ) {
F_2 ( L_4 , ( unsigned long ) V_9 ) ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
struct V_1 * V_2 = F_9 ( V_9 +
V_8 * V_11 ) ;
struct V_1 * V_3 = ( V_7 && V_7 -> V_12 ) ?
F_10 ( V_7 , V_7 -> V_13 + V_8 * V_11 , 0 )
: NULL ;
F_1 ( V_2 , V_3 ) ;
}
}
if ( ! V_7 || ! F_8 () ) {
F_2 ( L_5 , ( unsigned long ) V_14 ) ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
struct V_1 * V_2 = F_9 ( V_14 +
V_8 * V_11 ) ;
struct V_1 * V_3 = ( V_7 && V_7 -> V_12 ) ?
F_10 ( V_7 , V_7 -> V_13 + V_8 * V_11 , 0 )
: NULL ;
F_1 ( V_2 , V_3 ) ;
}
}
}
int F_11 ( struct V_16 * V_17 , int V_18 )
{
struct V_19 * V_20 = V_21 -> V_20 ;
struct V_1 * * V_22 ;
unsigned long V_23 ;
unsigned long V_24 ;
int V_25 ;
if ( ! V_26 )
return 0 ;
#ifdef F_12
if ( F_8 () ) {
V_22 = V_27 ;
V_23 = V_10 ;
V_24 = V_28 ;
} else {
V_22 = V_29 ;
V_23 = V_15 ;
V_24 = 0 ;
}
#else
V_22 = V_27 ;
V_23 = V_10 ;
V_24 = V_28 ;
#endif
V_21 -> V_20 -> V_30 . V_24 = 0 ;
if ( V_23 == 0 )
return 0 ;
V_23 ++ ;
F_13 ( & V_20 -> V_31 ) ;
V_24 = F_14 ( NULL , V_24 ,
( V_23 << V_4 ) +
( ( V_32 - 1 ) & V_33 ) ,
0 , 0 ) ;
if ( F_15 ( V_24 ) ) {
V_25 = V_24 ;
goto V_34;
}
V_24 = F_16 ( V_24 , V_32 ) ;
V_21 -> V_20 -> V_30 . V_24 = V_24 ;
V_25 = F_17 ( V_20 , V_24 , V_23 << V_4 ,
V_35 | V_36 |
V_37 | V_38 | V_39 |
V_40 ,
V_22 ) ;
if ( V_25 ) {
V_21 -> V_20 -> V_30 . V_24 = 0 ;
goto V_34;
}
F_18 ( & V_20 -> V_31 ) ;
return 0 ;
V_34:
F_18 ( & V_20 -> V_31 ) ;
return V_25 ;
}
const char * F_19 ( struct V_6 * V_7 )
{
if ( V_7 -> V_12 && V_7 -> V_13 == V_7 -> V_12 -> V_30 . V_24 )
return L_6 ;
return NULL ;
}
static void * T_1 F_20 ( T_2 * V_41 , const char * V_42 ,
unsigned long * V_43 )
{
T_3 * V_44 ;
unsigned int V_8 ;
char * V_45 ;
V_44 = ( void * ) V_41 + V_41 -> V_46 ;
V_45 = ( void * ) V_41 + V_44 [ V_41 -> V_47 ] . V_48 ;
for ( V_8 = 1 ; V_8 < V_41 -> V_49 ; V_8 ++ ) {
if ( strcmp ( V_45 + V_44 [ V_8 ] . V_50 , V_42 ) == 0 ) {
if ( V_43 )
* V_43 = V_44 [ V_8 ] . V_51 ;
return ( void * ) V_41 + V_44 [ V_8 ] . V_48 ;
}
}
* V_43 = 0 ;
return NULL ;
}
static T_4 * T_1 F_21 ( struct V_52 * V_53 ,
const char * V_54 )
{
unsigned int V_8 ;
char V_55 [ V_56 ] , * V_57 ;
for ( V_8 = 0 ; V_8 < ( V_53 -> V_58 / sizeof( T_4 ) ) ; V_8 ++ ) {
if ( V_53 -> V_59 [ V_8 ] . V_60 == 0 )
continue;
F_22 ( V_55 , V_53 -> V_61 + V_53 -> V_59 [ V_8 ] . V_60 ,
V_56 ) ;
V_57 = strchr ( V_55 , '@' ) ;
if ( V_57 )
* V_57 = 0 ;
if ( strcmp ( V_54 , V_55 ) == 0 )
return & V_53 -> V_59 [ V_8 ] ;
}
return NULL ;
}
static unsigned long T_1 F_23 ( struct V_52 * V_53 ,
const char * V_54 )
{
T_4 * V_62 = F_21 ( V_53 , V_54 ) ;
if ( V_62 == NULL ) {
F_2 ( V_63 L_7 ,
V_54 ) ;
return 0 ;
}
return V_62 -> V_64 - V_65 ;
}
static int T_1 F_24 ( struct V_52 * V_66 ,
struct V_67 * V_68 ,
const char * V_69 , const char * V_70 )
{
T_4 * V_71 , * V_72 ;
V_71 = F_21 ( V_66 , V_69 ) ;
if ( V_71 == NULL ) {
F_2 ( V_73 L_8 , V_69 ) ;
return - 1 ;
}
if ( V_70 == NULL ) {
V_71 -> V_60 = 0 ;
return 0 ;
}
V_72 = F_21 ( V_66 , V_70 ) ;
if ( V_72 == NULL ) {
F_2 ( V_73 L_8 , V_70 ) ;
return - 1 ;
}
V_71 -> V_64 = V_72 -> V_64 ;
V_71 -> V_74 = V_72 -> V_74 ;
V_71 -> V_75 = V_72 -> V_75 ;
V_71 -> V_76 = V_72 -> V_76 ;
V_71 -> V_77 = V_72 -> V_77 ;
return 0 ;
}
static void * T_1 F_25 ( T_5 * V_41 , const char * V_42 ,
unsigned long * V_43 )
{
T_6 * V_44 ;
unsigned int V_8 ;
char * V_45 ;
V_44 = ( void * ) V_41 + V_41 -> V_46 ;
V_45 = ( void * ) V_41 + V_44 [ V_41 -> V_47 ] . V_48 ;
for ( V_8 = 1 ; V_8 < V_41 -> V_49 ; V_8 ++ ) {
if ( strcmp ( V_45 + V_44 [ V_8 ] . V_50 , V_42 ) == 0 ) {
if ( V_43 )
* V_43 = V_44 [ V_8 ] . V_51 ;
return ( void * ) V_41 + V_44 [ V_8 ] . V_48 ;
}
}
if ( V_43 )
* V_43 = 0 ;
return NULL ;
}
static T_7 * T_1 F_26 ( struct V_67 * V_53 ,
const char * V_54 )
{
unsigned int V_8 ;
char V_55 [ V_56 ] , * V_57 ;
for ( V_8 = 0 ; V_8 < ( V_53 -> V_58 / sizeof( T_7 ) ) ; V_8 ++ ) {
if ( V_53 -> V_59 [ V_8 ] . V_60 == 0 )
continue;
F_22 ( V_55 , V_53 -> V_61 + V_53 -> V_59 [ V_8 ] . V_60 ,
V_56 ) ;
V_57 = strchr ( V_55 , '@' ) ;
if ( V_57 )
* V_57 = 0 ;
if ( strcmp ( V_54 , V_55 ) == 0 )
return & V_53 -> V_59 [ V_8 ] ;
}
return NULL ;
}
static unsigned long T_1 F_27 ( struct V_67 * V_53 ,
const char * V_54 )
{
T_7 * V_62 = F_26 ( V_53 , V_54 ) ;
if ( V_62 == NULL ) {
F_2 ( V_63 L_9 ,
V_54 ) ;
return 0 ;
}
#ifdef F_28
return * ( ( V_78 * ) ( V_14 + V_62 -> V_64 - V_79 ) ) -
V_79 ;
#else
return V_62 -> V_64 - V_79 ;
#endif
}
static int T_1 F_29 ( struct V_52 * V_66 ,
struct V_67 * V_68 ,
const char * V_69 , const char * V_70 )
{
T_7 * V_80 , * V_81 ;
V_80 = F_26 ( V_68 , V_69 ) ;
if ( V_80 == NULL ) {
F_2 ( V_73 L_10 , V_69 ) ;
return - 1 ;
}
if ( V_70 == NULL ) {
V_80 -> V_60 = 0 ;
return 0 ;
}
V_81 = F_26 ( V_68 , V_70 ) ;
if ( V_81 == NULL ) {
F_2 ( V_73 L_10 , V_70 ) ;
return - 1 ;
}
V_80 -> V_64 = V_81 -> V_64 ;
V_80 -> V_74 = V_81 -> V_74 ;
V_80 -> V_75 = V_81 -> V_75 ;
V_80 -> V_76 = V_81 -> V_76 ;
V_80 -> V_77 = V_81 -> V_77 ;
return 0 ;
}
static T_1 int F_30 ( struct V_52 * V_66 ,
struct V_67 * V_68 )
{
void * V_82 ;
V_66 -> V_59 = F_20 ( V_66 -> V_83 , L_11 , & V_66 -> V_58 ) ;
V_66 -> V_61 = F_20 ( V_66 -> V_83 , L_12 , NULL ) ;
if ( V_66 -> V_59 == NULL || V_66 -> V_61 == NULL ) {
F_2 ( V_73 L_13 ) ;
return - 1 ;
}
V_82 = F_20 ( V_66 -> V_83 , L_14 , NULL ) ;
if ( V_82 == NULL ) {
F_2 ( V_73 L_15 ) ;
return - 1 ;
}
V_66 -> V_84 = V_82 - V_9 ;
#ifdef F_12
V_68 -> V_59 = F_25 ( V_68 -> V_83 , L_11 , & V_68 -> V_58 ) ;
V_68 -> V_61 = F_25 ( V_68 -> V_83 , L_12 , NULL ) ;
if ( V_68 -> V_59 == NULL || V_68 -> V_61 == NULL ) {
F_2 ( V_73 L_16 ) ;
return - 1 ;
}
V_82 = F_25 ( V_68 -> V_83 , L_14 , NULL ) ;
if ( V_82 == NULL ) {
F_2 ( V_73 L_17 ) ;
return - 1 ;
}
V_68 -> V_84 = V_82 - V_14 ;
#endif
return 0 ;
}
static T_1 void F_31 ( struct V_52 * V_66 ,
struct V_67 * V_68 )
{
#ifdef F_12
V_85 = F_27 ( V_68 , L_18 ) ;
#endif
V_86 = F_23 ( V_66 , L_19 ) ;
V_87 = F_23 ( V_66 , L_20 ) ;
}
static T_1 int F_32 ( struct V_52 * V_66 ,
struct V_67 * V_68 )
{
T_4 * V_88 ;
#ifdef F_12
T_7 * V_89 ;
V_89 = F_26 ( V_68 , L_21 ) ;
if ( V_89 == NULL ) {
F_2 ( V_73 L_22
L_23 ) ;
return - 1 ;
}
* ( ( int * ) ( V_14 + V_89 -> V_64 - V_79 ) ) =
( V_15 << V_4 ) -
( V_89 -> V_64 - V_79 ) ;
#endif
V_88 = F_21 ( V_66 , L_21 ) ;
if ( V_88 == NULL ) {
F_2 ( V_73 L_24
L_23 ) ;
return - 1 ;
}
* ( ( int * ) ( V_9 + ( V_88 -> V_64 - V_65 ) ) ) =
( V_10 << V_4 ) -
( V_88 -> V_64 - V_65 ) ;
return 0 ;
}
static T_1 int F_33 ( struct V_52 * V_66 ,
struct V_67 * V_68 )
{
void * V_90 ;
unsigned long V_91 ;
#ifdef F_12
void * V_92 ;
unsigned long V_93 ;
V_92 = F_25 ( V_68 -> V_83 , L_25 , & V_93 ) ;
if ( V_92 )
F_34 ( V_94 -> V_95 ,
V_92 , V_92 + V_93 ) ;
V_92 = F_25 ( V_68 -> V_83 , L_26 , & V_93 ) ;
if ( V_92 )
F_34 ( V_94 -> V_96 ,
V_92 , V_92 + V_93 ) ;
V_92 = F_25 ( V_68 -> V_83 , L_27 , & V_93 ) ;
if ( V_92 )
F_34 ( V_97 ,
V_92 , V_92 + V_93 ) ;
V_92 = F_25 ( V_68 -> V_83 , L_28 , & V_93 ) ;
if ( V_92 )
F_35 ( V_94 -> V_95 ,
V_92 , V_92 + V_93 ) ;
#endif
V_90 = F_20 ( V_66 -> V_83 , L_25 , & V_91 ) ;
if ( V_90 )
F_34 ( V_94 -> V_95 ,
V_90 , V_90 + V_91 ) ;
V_90 = F_20 ( V_66 -> V_83 , L_26 , & V_91 ) ;
if ( V_90 )
F_34 ( V_94 -> V_96 ,
V_90 , V_90 + V_91 ) ;
#ifdef F_12
V_90 = F_20 ( V_66 -> V_83 , L_27 , & V_91 ) ;
if ( V_90 )
F_34 ( V_97 ,
V_90 , V_90 + V_91 ) ;
#endif
V_90 = F_20 ( V_66 -> V_83 , L_28 , & V_91 ) ;
if ( V_90 )
F_35 ( V_94 -> V_95 ,
V_90 , V_90 + V_91 ) ;
return 0 ;
}
static T_1 int F_36 ( struct V_52 * V_66 ,
struct V_67 * V_68 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_37 ( V_98 ) ; V_8 ++ ) {
struct V_99 * V_100 = & V_98 [ V_8 ] ;
int V_101 = ( V_94 -> V_95 & V_100 -> V_102 )
== V_100 -> V_103 ;
if ( ! V_101 )
continue;
F_38 ( L_29 , V_100 -> V_104 ,
V_100 -> V_105 ? L_30 : V_100 -> V_105 ) ;
F_24 ( V_66 , V_68 , V_100 -> V_104 ,
V_100 -> V_105 ) ;
#ifdef F_12
F_29 ( V_66 , V_68 , V_100 -> V_104 ,
V_100 -> V_105 ) ;
#endif
}
return 0 ;
}
static T_1 int F_39 ( void )
{
struct V_52 V_66 ;
struct V_67 V_68 ;
V_66 . V_83 = V_9 ;
#ifdef F_12
V_68 . V_83 = V_14 ;
#endif
if ( F_30 ( & V_66 , & V_68 ) )
return - 1 ;
if ( F_32 ( & V_66 , & V_68 ) )
return - 1 ;
if ( F_33 ( & V_66 , & V_68 ) )
return - 1 ;
if ( F_36 ( & V_66 , & V_68 ) )
return - 1 ;
F_31 ( & V_66 , & V_68 ) ;
return 0 ;
}
static void T_1 F_40 ( void )
{
unsigned int V_8 ;
extern unsigned long * V_106 ;
extern unsigned long V_107 ;
for ( V_8 = 0 ; V_8 < V_108 ; V_8 ++ ) {
#ifdef F_12
if ( V_106 [ V_8 * 2 ] != V_107 )
V_109 -> V_110 [ V_8 >> 5 ] |=
0x80000000UL >> ( V_8 & 0x1f ) ;
if ( V_106 [ V_8 * 2 + 1 ] != V_107 )
V_109 -> V_111 [ V_8 >> 5 ] |=
0x80000000UL >> ( V_8 & 0x1f ) ;
#else
if ( V_106 [ V_8 ] != V_107 )
V_109 -> V_111 [ V_8 >> 5 ] |=
0x80000000UL >> ( V_8 & 0x1f ) ;
#endif
}
}
static int T_1 F_41 ( void )
{
int V_8 ;
#ifdef F_12
strcpy ( ( char * ) V_109 -> V_112 , L_31 ) ;
V_109 -> V_113 . V_114 = V_115 ;
V_109 -> V_113 . V_116 = V_117 ;
V_109 -> V_118 = F_42 ( V_119 ) ;
V_109 -> V_120 = F_43 ( V_121 ) ? 0x200 : 0x100 ;
if ( F_44 ( V_122 ) )
V_109 -> V_120 |= 1 ;
V_109 -> V_123 = F_45 () ;
V_109 -> V_124 = V_125 . V_126 ;
V_109 -> V_127 = V_125 . V_128 ;
V_109 -> V_129 = V_125 . V_130 ;
V_109 -> V_131 = V_125 . V_132 ;
V_109 -> V_133 = V_125 . V_128 ;
V_109 -> V_134 = V_125 . V_132 ;
V_109 -> V_135 = V_125 . V_136 ;
V_109 -> V_137 = V_125 . V_138 ;
V_15 = ( & V_139 - & V_140 ) >> V_4 ;
F_38 ( L_32 , V_14 , V_15 ) ;
#else
V_109 -> V_133 = V_141 ;
V_109 -> V_135 = V_142 ;
V_109 -> V_134 = V_141 ;
V_109 -> V_137 = V_142 ;
#endif
V_10 = ( & V_143 - & V_144 ) >> V_4 ;
F_38 ( L_33 , V_9 , V_10 ) ;
F_40 () ;
if ( F_39 () ) {
F_2 ( V_73 L_34 ) ;
V_10 = 0 ;
#ifdef F_12
V_15 = 0 ;
#endif
return 0 ;
}
V_27 = F_46 ( sizeof( struct V_1 * ) * ( V_10 + 2 ) ,
V_145 ) ;
F_47 ( V_27 == NULL ) ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
struct V_1 * V_2 = F_9 ( V_9 + V_8 * V_11 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
V_27 [ V_8 ] = V_2 ;
}
V_27 [ V_8 ++ ] = F_9 ( V_109 ) ;
V_27 [ V_8 ] = NULL ;
#ifdef F_12
V_29 = F_46 ( sizeof( struct V_1 * ) * ( V_15 + 2 ) ,
V_145 ) ;
F_47 ( V_29 == NULL ) ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
struct V_1 * V_2 = F_9 ( V_14 + V_8 * V_11 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
V_29 [ V_8 ] = V_2 ;
}
V_29 [ V_8 ++ ] = F_9 ( V_109 ) ;
V_29 [ V_8 ] = NULL ;
#endif
F_49 ( F_9 ( V_109 ) ) ;
F_50 () ;
V_26 = 1 ;
return 0 ;
}
int F_51 ( unsigned long V_146 )
{
return 0 ;
}
int F_52 ( struct V_19 * V_20 , unsigned long V_146 )
{
return 0 ;
}
struct V_6 * F_53 ( struct V_19 * V_20 )
{
return NULL ;
}
