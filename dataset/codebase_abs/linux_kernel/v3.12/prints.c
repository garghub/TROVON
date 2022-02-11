static char * F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) == V_3 )
sprintf ( V_4 , L_1 ,
( unsigned long long )
F_3 ( F_4 ( V_2 ) ) ,
( unsigned long long )
F_5 ( F_4 ( V_2 ) ) ) ;
else
sprintf ( V_4 , L_2 ,
( unsigned long long ) F_4 ( V_2 ) ) ;
return V_4 ;
}
static char * F_6 ( struct V_5 * V_2 )
{
int V_6 ;
V_6 = F_7 ( V_2 ) ;
if ( F_8 ( V_6 , V_2 ) == V_3 )
sprintf ( V_4 , L_1 ,
( unsigned long long )
F_3 ( F_9 ( V_6 , V_2 ) ) ,
( unsigned long long )
F_5 ( F_9 ( V_6 , V_2 ) ) ) ;
else
sprintf ( V_4 , L_2 ,
( unsigned long long ) F_9 ( V_6 , V_2 ) ) ;
return V_4 ;
}
static char * F_10 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) == V_7 )
return L_3 ;
if ( F_2 ( V_2 ) == V_3 )
return L_4 ;
if ( F_2 ( V_2 ) == V_8 )
return L_5 ;
if ( F_2 ( V_2 ) == V_9 )
return L_6 ;
return L_7 ;
}
static char * F_11 ( struct V_5 * V_2 )
{
int V_6 ;
V_6 = F_7 ( V_2 ) ;
if ( F_8 ( V_6 , V_2 ) == V_7 )
return L_3 ;
if ( F_8 ( V_6 , V_2 ) == V_3 )
return L_4 ;
if ( F_8 ( V_6 , V_2 ) == V_8 )
return L_5 ;
if ( F_8 ( V_6 , V_2 ) == V_9 )
return L_6 ;
return L_7 ;
}
static void F_12 ( char * V_10 , struct V_5 * V_2 )
{
if ( V_2 )
sprintf ( V_10 , L_8 , F_13 ( V_2 -> V_11 ) ,
F_13 ( V_2 -> V_12 ) , F_6 ( V_2 ) ,
F_11 ( V_2 ) ) ;
else
sprintf ( V_10 , L_9 ) ;
}
static void F_14 ( char * V_10 , struct V_1 * V_2 )
{
if ( V_2 )
sprintf ( V_10 , L_8 , V_2 -> V_13 . V_11 ,
V_2 -> V_13 . V_12 , F_1 ( V_2 ) ,
F_10 ( V_2 ) ) ;
else
sprintf ( V_10 , L_9 ) ;
}
static void F_15 ( char * V_10 , struct V_14 * V_15 )
{
if ( V_15 )
sprintf ( V_10 ,
L_10 ,
F_16 ( V_15 ) , F_17 ( V_15 ) , F_18 ( V_15 ) ,
F_19 ( V_15 ) , F_20 ( V_15 ) ) ;
else
sprintf ( V_10 , L_9 ) ;
}
static void F_21 ( char * V_10 , struct V_16 * V_17 )
{
if ( V_17 ) {
strcpy ( V_10 ,
( F_22 ( V_17 ) == V_18 ) ? L_11 : L_12 ) ;
F_12 ( V_10 + strlen ( V_10 ) , & ( V_17 -> V_19 ) ) ;
sprintf ( V_10 + strlen ( V_10 ) , L_13
L_14 ,
F_23 ( V_17 ) , F_24 ( V_17 ) , F_25 ( V_17 ) ) ;
} else
sprintf ( V_10 , L_9 ) ;
}
static void F_26 ( char * V_10 , struct V_20 * V_21 )
{
char V_22 [ 20 ] ;
memcpy ( V_22 , V_21 -> V_23 , V_21 -> V_24 > 19 ? 19 : V_21 -> V_24 ) ;
V_22 [ V_21 -> V_24 > 19 ? 19 : V_21 -> V_24 ] = 0 ;
sprintf ( V_10 , L_15 , V_22 , V_21 -> V_25 , V_21 -> V_26 ) ;
}
static void F_27 ( char * V_10 , struct V_27 * V_28 )
{
sprintf ( V_10 , L_16 ,
F_28 ( V_28 ) , F_29 ( V_28 ) , F_30 ( V_28 ) ) ;
}
static void F_31 ( char * V_10 , struct V_27 * V_28 )
{
char V_29 [ V_30 ] ;
sprintf ( V_10 ,
L_17 ,
F_32 ( V_28 -> V_31 , V_29 ) , V_28 -> V_32 ,
( unsigned long long ) V_28 -> V_33 , F_33 ( & ( V_28 -> V_34 ) ) ,
V_28 -> V_35 , V_28 -> V_36 ,
F_34 ( V_28 ) ? L_18 : L_19 ,
F_35 ( V_28 ) ? L_20 : L_21 ,
F_36 ( V_28 ) ? L_22 : L_23 ) ;
}
static void F_37 ( char * V_10 , struct V_37 * V_38 )
{
sprintf ( V_10 , L_24 , F_38 ( V_38 ) ,
F_39 ( V_38 ) ) ;
}
static char * F_40 ( char * V_39 , int * V_40 )
{
char * V_41 = V_39 ;
while ( ( V_41 = strchr ( V_41 , '%' ) ) != NULL ) {
if ( V_41 [ 1 ] == 'k' || V_41 [ 1 ] == 'K' || V_41 [ 1 ] == 'h' || V_41 [ 1 ] == 't' ||
V_41 [ 1 ] == 'z' || V_41 [ 1 ] == 'b' || V_41 [ 1 ] == 'y' || V_41 [ 1 ] == 'a' ) {
* V_40 = V_41 [ 1 ] ;
break;
}
V_41 ++ ;
}
return V_41 ;
}
static void F_41 ( const char * V_39 , T_1 args )
{
char * V_42 = V_43 ;
char * V_41 ;
char * V_44 = V_45 ;
int V_40 ;
F_42 ( & V_46 ) ;
strcpy ( V_42 , V_39 ) ;
while ( ( V_41 = F_40 ( V_42 , & V_40 ) ) != NULL ) {
* V_41 = 0 ;
V_44 += vsprintf ( V_44 , V_42 , args ) ;
switch ( V_40 ) {
case 'k' :
F_12 ( V_44 , va_arg ( args , struct V_5 * ) ) ;
break;
case 'K' :
F_14 ( V_44 , va_arg ( args , struct V_1 * ) ) ;
break;
case 'h' :
F_21 ( V_44 , va_arg ( args , struct V_16 * ) ) ;
break;
case 't' :
F_26 ( V_44 ,
va_arg ( args ,
struct V_20 * ) ) ;
break;
case 'y' :
F_37 ( V_44 ,
va_arg ( args , struct V_37 * ) ) ;
break;
case 'z' :
F_27 ( V_44 ,
va_arg ( args , struct V_27 * ) ) ;
break;
case 'b' :
F_31 ( V_44 ,
va_arg ( args , struct V_27 * ) ) ;
break;
case 'a' :
F_15 ( V_44 ,
va_arg ( args ,
struct V_14 * ) ) ;
break;
}
V_44 += strlen ( V_44 ) ;
V_42 = V_41 + 2 ;
}
vsprintf ( V_44 , V_42 , args ) ;
F_43 ( & V_46 ) ;
}
void F_44 ( struct V_47 * V_48 , const char * V_49 ,
const char * V_50 , const char * V_39 , ... )
{
F_45 ( V_39 ) ;
if ( V_48 )
F_46 ( V_51 L_25
L_26 , V_48 -> V_52 , V_49 ? V_49 : L_27 , V_49 ? L_28 : L_27 ,
V_50 , V_45 ) ;
else
F_46 ( V_51 L_29 ,
V_49 ? V_49 : L_27 , V_49 ? L_28 : L_27 , V_50 , V_45 ) ;
}
void F_47 ( struct V_47 * V_48 , const char * V_39 , ... )
{
F_45 ( V_39 ) ;
if ( V_48 )
F_46 ( V_53 L_30 ,
V_48 -> V_52 , V_45 ) ;
else
F_46 ( V_53 L_31 , V_45 ) ;
}
static void F_48 ( const char * V_39 , ... )
{
F_45 ( V_39 ) ;
F_46 ( V_45 ) ;
}
void F_49 ( struct V_47 * V_54 , int V_55 , const char * V_39 , ... )
{
#ifdef F_50
F_45 ( V_39 ) ;
if ( V_54 )
F_46 ( V_56 L_32 ,
V_54 -> V_52 , V_45 ) ;
else
F_46 ( V_56 L_33 , V_45 ) ;
#endif
}
void F_51 ( struct V_47 * V_48 , const char * V_49 ,
const char * V_50 , const char * V_39 , ... )
{
F_45 ( V_39 ) ;
#ifdef F_50
F_52 () ;
#endif
if ( V_48 )
F_46 ( V_51 L_34 ,
V_48 -> V_52 , V_49 ? V_49 : L_27 , V_49 ? L_28 : L_27 ,
V_50 , V_45 ) ;
else
F_46 ( V_51 L_35 ,
V_49 ? V_49 : L_27 , V_49 ? L_28 : L_27 , V_50 , V_45 ) ;
F_53 () ;
}
void F_54 ( struct V_47 * V_48 , const char * V_49 ,
const char * V_50 , const char * V_39 , ... )
{
F_45 ( V_39 ) ;
F_55 ( V_48 == NULL ) ;
if ( F_56 ( V_48 ) )
F_51 ( V_48 , V_49 , V_50 , V_45 ) ;
if ( V_49 && V_49 [ 0 ] )
F_46 ( V_57 L_36 ,
V_48 -> V_52 , V_49 , V_50 , V_45 ) ;
else
F_46 ( V_57 L_37 ,
V_48 -> V_52 , V_50 , V_45 ) ;
if ( V_48 -> V_58 & V_59 )
return;
F_47 ( V_48 , L_38 ) ;
V_48 -> V_58 |= V_59 ;
F_57 ( V_48 , - V_60 ) ;
}
void F_58 ( struct V_47 * V_48 , int V_61 , const char * V_39 , ... )
{
F_45 ( V_39 ) ;
if ( F_56 ( V_48 ) ) {
F_59 ( V_57 L_39 , V_48 -> V_52 ,
V_45 ) ;
}
if ( F_60 ( F_61 ( V_48 ) ) )
return;
F_46 ( V_57 L_40 , V_48 -> V_52 ,
V_45 ) ;
V_48 -> V_58 |= V_59 ;
F_57 ( V_48 , V_61 ) ;
}
static int F_62 ( struct V_27 * V_28 , int V_62 , int V_63 )
{
struct V_5 * V_2 ;
struct V_37 * V_38 ;
int V_64 ;
int V_65 , V_66 ;
if ( ! F_63 ( V_28 ) )
return 1 ;
F_64 ( V_28 ) ;
if ( V_62 == - 1 ) {
V_65 = 0 ;
V_66 = F_29 ( V_28 ) ;
} else {
V_65 = V_62 ;
V_66 = V_63 < F_29 ( V_28 ) ? V_63 : F_29 ( V_28 ) ;
}
F_48 ( L_41 , V_28 -> V_33 , V_28 ) ;
V_38 = F_65 ( V_28 , V_65 ) ;
F_48 ( L_42 , V_65 , V_38 ) ;
for ( V_64 = V_65 , V_2 = F_66 ( V_28 , V_65 ) , V_38 ++ ; V_64 < V_66 ;
V_64 ++ , V_2 ++ , V_38 ++ ) {
F_48 ( L_43 , V_64 , V_2 , V_64 + 1 , V_38 ) ;
if ( V_64 && V_64 % 4 == 0 )
F_46 ( L_44 ) ;
}
F_46 ( L_44 ) ;
return 0 ;
}
static int F_67 ( struct V_27 * V_28 , int V_67 , int V_62 ,
int V_63 )
{
struct V_68 * V_69 ;
struct V_16 * V_17 ;
int V_64 , V_70 ;
int V_65 , V_66 ;
if ( ! F_68 ( V_28 ) )
return 1 ;
F_69 ( V_28 ) ;
V_69 = F_70 ( V_28 ) ;
V_17 = F_71 ( V_28 , 0 ) ;
V_70 = F_72 ( V_69 ) ;
F_46
( L_45 ) ;
F_48 ( L_46 , V_28 -> V_33 , V_28 ) ;
if ( ! ( V_67 & V_71 ) ) {
F_48 ( L_47 ,
& ( V_17 -> V_19 ) , & ( ( V_17 + V_70 - 1 ) -> V_19 ) ) ;
return 0 ;
}
if ( V_62 < 0 || V_62 > V_70 - 1 )
V_65 = 0 ;
else
V_65 = V_62 ;
if ( V_63 < 0 || V_63 > V_70 )
V_66 = V_70 ;
else
V_66 = V_63 ;
V_17 += V_65 ;
F_46
( L_48 ) ;
F_46
( L_49 ) ;
for ( V_64 = V_65 ; V_64 < V_66 ; V_64 ++ , V_17 ++ ) {
F_46
( L_48 ) ;
F_48 ( L_50 , V_64 , V_17 ) ;
if ( V_67 & V_71 )
F_73 ( V_17 , F_74 ( V_28 , V_17 ) ) ;
}
F_46
( L_51 ) ;
return 0 ;
}
char * F_75 ( int V_72 )
{
if ( V_72 == V_73 )
return L_52 ;
if ( V_72 == V_74 )
return L_53 ;
if ( V_72 == V_75 )
return L_54 ;
return L_55 ;
}
static int F_76 ( struct V_27 * V_28 )
{
struct V_76 * V_77 =
(struct V_76 * ) ( V_28 -> V_78 ) ;
int V_79 , V_80 ;
char * V_6 ;
char V_29 [ V_30 ] ;
if ( F_77 ( V_77 ) ) {
V_6 = L_56 ;
} else if ( F_78 ( V_77 ) ) {
V_6 = L_57 ;
} else if ( F_79 ( V_77 ) ) {
V_6 = ( ( F_80 ( V_77 ) == V_81 ) ?
L_57 : L_56 ) ;
} else {
return 1 ;
}
F_46 ( L_58 , F_32 ( V_28 -> V_31 , V_29 ) ,
( unsigned long long ) V_28 -> V_33 ) ;
F_46 ( L_59 , V_6 ) ;
F_46 ( L_60 , F_81 ( V_77 ) ) ;
F_46 ( L_61 , F_82 ( V_77 ) ) ;
F_46 ( L_62 , F_83 ( V_77 ) ) ;
V_79 = V_28 -> V_33 ;
V_80 = F_81 ( V_77 ) - V_79 - 1 - F_84 ( V_77 ) -
( ! F_79 ( V_77 ) ? F_85 ( V_77 ) +
1 : F_86 ( V_77 ) ) - F_83 ( V_77 ) ;
F_46
( L_63
L_64 , V_79 , F_84 ( V_77 ) ,
( ! F_79 ( V_77 ) ? ( F_85 ( V_77 ) + 1 ) :
F_86 ( V_77 ) ) , V_80 ) ;
F_46 ( L_65 , F_87 ( V_77 ) ) ;
F_46 ( L_66 , F_88 ( V_77 ) ) ;
F_46 ( L_67 , F_89 ( V_77 ) ) ;
F_46 ( L_68 , F_85 ( V_77 ) ) ;
F_46 ( L_69 , F_90 ( V_77 ) ) ;
F_46 ( L_70 ,
F_75 ( F_91 ( V_77 ) ) ) ;
F_46 ( L_71 , F_92 ( V_77 ) ) ;
return 0 ;
}
static int F_93 ( struct V_27 * V_28 )
{
struct V_82 * V_83 ;
if ( memcmp ( F_94 ( V_28 ) , V_84 , 8 ) )
return 1 ;
V_83 = (struct V_82 * ) ( V_28 -> V_78 ) ;
F_46 ( L_72 ,
( unsigned long long ) V_28 -> V_33 , F_95 ( V_83 ) ,
F_96 ( V_83 ) , F_97 ( V_83 ) ) ;
return 0 ;
}
void F_98 ( struct V_27 * V_28 , ... )
{
T_1 args ;
int V_85 , V_62 , V_63 ;
if ( ! V_28 ) {
F_46 ( L_73 ) ;
return;
}
va_start ( args , V_28 ) ;
V_85 = va_arg ( args , int ) ;
V_62 = va_arg ( args , int ) ;
V_63 = va_arg ( args , int ) ;
if ( F_67 ( V_28 , V_85 , V_62 , V_63 ) )
if ( F_62 ( V_28 , V_62 , V_63 ) )
if ( F_76 ( V_28 ) )
if ( F_93 ( V_28 ) )
F_46
( L_74 ,
( unsigned long long ) V_28 -> V_33 ) ;
va_end ( args ) ;
}
void F_99 ( struct V_86 * V_87 )
{
int V_88 = 0 ;
int V_64 ;
struct V_27 * V_89 , * V_90 ;
if ( ! V_87 )
return;
sprintf ( V_91 , L_44
L_75
L_76
L_77
L_78 ,
F_100 ( V_87 -> V_92 ) -> V_93 ,
V_87 -> V_94 , F_101 ( V_87 -> V_95 ) ,
V_87 -> V_95 -> V_96 ) ;
for ( V_88 = 0 ; V_88 < F_102 ( V_87 -> V_97 ) ; V_88 ++ ) {
if ( F_103 ( V_87 -> V_95 , V_88 ) <=
V_87 -> V_95 -> V_98
&& F_103 ( V_87 -> V_95 ,
V_88 ) > V_99 ) {
V_89 = F_104 ( V_87 -> V_95 , V_88 ) ;
V_90 = F_105 ( V_87 -> V_95 , V_88 ) ;
} else {
V_89 = NULL ;
V_90 = NULL ;
}
sprintf ( V_91 + strlen ( V_91 ) ,
L_79 ,
V_88 ,
( V_89 ) ? ( long long ) ( V_89 -> V_33 ) : ( - 1LL ) ,
( V_89 ) ? F_33 ( & ( V_89 -> V_34 ) ) : - 1 ,
( V_87 -> V_100 [ V_88 ] ) ? ( long long ) ( V_87 -> V_100 [ V_88 ] -> V_33 ) : ( - 1LL ) ,
( V_87 -> V_100 [ V_88 ] ) ? F_33 ( & ( V_87 -> V_100 [ V_88 ] -> V_34 ) ) : - 1 ,
( V_87 -> V_101 [ V_88 ] ) ? ( long long ) ( V_87 -> V_101 [ V_88 ] -> V_33 ) : ( - 1LL ) ,
( V_87 -> V_101 [ V_88 ] ) ? F_33 ( & ( V_87 -> V_101 [ V_88 ] -> V_34 ) ) : - 1 ,
( V_90 ) ? ( long long ) ( V_90 -> V_33 ) : ( - 1LL ) ,
( V_87 -> V_102 [ V_88 ] ) ? ( long long ) ( V_87 -> V_102 [ V_88 ] ->
V_33 ) : ( - 1LL ) ,
( V_87 -> V_103 [ V_88 ] ) ? ( long long ) ( V_87 -> V_103 [ V_88 ] ->
V_33 ) : ( - 1LL ) ,
( V_87 -> V_104 [ V_88 ] ) ? ( long long ) ( V_87 -> V_104 [ V_88 ] ->
V_33 ) : ( - 1LL ) ,
( V_87 -> V_105 [ V_88 ] ) ? ( long long ) ( V_87 -> V_105 [ V_88 ] ->
V_33 ) : ( - 1LL ) ) ;
}
sprintf ( V_91 + strlen ( V_91 ) ,
L_77
L_80
L_81 ,
V_87 -> V_97 [ 0 ] , V_87 -> V_106 [ 0 ] , V_87 -> V_107 , V_87 -> V_108 [ 0 ] ,
V_87 -> V_109 , V_87 -> V_110 [ 0 ] , V_87 -> V_111 , V_87 -> V_112 , V_87 -> V_113 ,
V_87 -> V_114 , V_87 -> V_115 , V_87 -> V_116 , V_87 -> V_117 [ 0 ] ,
V_87 -> V_118 [ 0 ] ) ;
V_88 = 0 ;
do {
V_88 ++ ;
sprintf ( V_91 + strlen ( V_91 ) ,
L_82 ,
V_88 , V_87 -> V_97 [ V_88 ] , V_87 -> V_106 [ V_88 ] , V_87 -> V_108 [ V_88 ] ,
V_87 -> V_110 [ V_88 ] ) ;
} while ( V_87 -> V_97 [ V_88 ] );
sprintf ( V_91 + strlen ( V_91 ) ,
L_77
L_83 ) ;
V_88 = 0 ;
for ( V_64 = 0 ; V_64 < F_102 ( V_87 -> V_119 ) ; V_64 ++ )
sprintf ( V_91 + strlen ( V_91 ) ,
L_84 , V_87 -> V_119 [ V_64 ] ,
V_87 -> V_119 [ V_64 ] ? ( unsigned long long ) V_87 -> V_119 [ V_64 ] ->
V_33 : 0ULL ,
V_87 -> V_119 [ V_64 ] ? F_33 ( & ( V_87 -> V_119 [ V_64 ] -> V_34 ) ) : 0 ,
( V_64 == F_102 ( V_87 -> V_119 ) - 1 ) ? L_44 : L_85 ) ;
sprintf ( V_91 + strlen ( V_91 ) ,
L_86 ) ;
}
void F_106 ( char * V_120 )
{
F_46 ( L_87 , V_120 , V_91 ) ;
}
static void F_107 ( struct V_27 * V_28 )
{
struct V_68 * V_69 ;
int V_70 ;
V_69 = F_70 ( V_28 ) ;
V_70 = F_72 ( V_69 ) ;
if ( V_70 > ( V_28 -> V_32 - V_121 ) / V_122 )
F_108 ( NULL , L_88 , L_89 ,
V_28 ) ;
if ( F_109 ( V_69 ) > V_28 -> V_32 - V_121 - V_122 * V_70 )
F_108 ( NULL , L_90 , L_91 ,
V_28 ) ;
}
static void F_110 ( struct V_27 * V_28 )
{
struct V_68 * V_69 ;
V_69 = F_70 ( V_28 ) ;
if ( ! ( F_28 ( V_28 ) > V_123 && F_28 ( V_28 ) <= V_124 ) )
F_108 ( NULL , L_92 , L_93 , V_28 ) ;
if ( F_29 ( V_28 ) > ( V_28 -> V_32 - V_121 ) / V_122 )
F_108 ( NULL , L_94 , L_89 , V_28 ) ;
if ( F_30 ( V_28 ) !=
V_28 -> V_32 - V_121 - V_125 * F_29 ( V_28 ) -
V_126 * ( F_29 ( V_28 ) + 1 ) )
F_108 ( NULL , L_95 , L_91 , V_28 ) ;
}
void F_69 ( struct V_27 * V_28 )
{
int V_64 ;
struct V_16 * V_17 ;
if ( ! V_28 )
return;
F_107 ( V_28 ) ;
for ( V_64 = 0 , V_17 = F_71 ( V_28 , 0 ) ; V_64 < F_29 ( V_28 ) ; V_64 ++ , V_17 ++ )
F_111 ( V_17 , F_74 ( V_28 , V_17 ) ) ;
}
void F_64 ( struct V_27 * V_28 )
{
if ( ! V_28 )
return;
F_110 ( V_28 ) ;
}
void F_112 ( struct V_47 * V_54 )
{
}
