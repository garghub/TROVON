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
sprintf ( V_10 ,
L_17 ,
V_28 -> V_29 , V_28 -> V_30 ,
( unsigned long long ) V_28 -> V_31 , F_32 ( & ( V_28 -> V_32 ) ) ,
V_28 -> V_33 , V_28 -> V_34 ,
F_33 ( V_28 ) ? L_18 : L_19 ,
F_34 ( V_28 ) ? L_20 : L_21 ,
F_35 ( V_28 ) ? L_22 : L_23 ) ;
}
static void F_36 ( char * V_10 , struct V_35 * V_36 )
{
sprintf ( V_10 , L_24 , F_37 ( V_36 ) ,
F_38 ( V_36 ) ) ;
}
static char * F_39 ( char * V_37 , int * V_38 )
{
char * V_39 = V_37 ;
while ( ( V_39 = strchr ( V_39 , '%' ) ) != NULL ) {
if ( V_39 [ 1 ] == 'k' || V_39 [ 1 ] == 'K' || V_39 [ 1 ] == 'h' || V_39 [ 1 ] == 't' ||
V_39 [ 1 ] == 'z' || V_39 [ 1 ] == 'b' || V_39 [ 1 ] == 'y' || V_39 [ 1 ] == 'a' ) {
* V_38 = V_39 [ 1 ] ;
break;
}
V_39 ++ ;
}
return V_39 ;
}
static void F_40 ( const char * V_37 , T_1 args )
{
char * V_40 = V_41 ;
char * V_39 ;
char * V_42 = V_43 ;
int V_38 ;
F_41 ( & V_44 ) ;
strcpy ( V_40 , V_37 ) ;
while ( ( V_39 = F_39 ( V_40 , & V_38 ) ) != NULL ) {
* V_39 = 0 ;
V_42 += vsprintf ( V_42 , V_40 , args ) ;
switch ( V_38 ) {
case 'k' :
F_12 ( V_42 , va_arg ( args , struct V_5 * ) ) ;
break;
case 'K' :
F_14 ( V_42 , va_arg ( args , struct V_1 * ) ) ;
break;
case 'h' :
F_21 ( V_42 , va_arg ( args , struct V_16 * ) ) ;
break;
case 't' :
F_26 ( V_42 ,
va_arg ( args ,
struct V_20 * ) ) ;
break;
case 'y' :
F_36 ( V_42 ,
va_arg ( args , struct V_35 * ) ) ;
break;
case 'z' :
F_27 ( V_42 ,
va_arg ( args , struct V_27 * ) ) ;
break;
case 'b' :
F_31 ( V_42 ,
va_arg ( args , struct V_27 * ) ) ;
break;
case 'a' :
F_15 ( V_42 ,
va_arg ( args ,
struct V_14 * ) ) ;
break;
}
V_42 += strlen ( V_42 ) ;
V_40 = V_39 + 2 ;
}
vsprintf ( V_42 , V_40 , args ) ;
F_42 ( & V_44 ) ;
}
void F_43 ( struct V_45 * V_46 , const char * V_47 ,
const char * V_48 , const char * V_37 , ... )
{
F_44 ( V_37 ) ;
if ( V_46 )
F_45 ( V_49 L_25
L_26 , V_46 -> V_50 , V_47 ? V_47 : L_27 , V_47 ? L_28 : L_27 ,
V_48 , V_43 ) ;
else
F_45 ( V_49 L_29 ,
V_47 ? V_47 : L_27 , V_47 ? L_28 : L_27 , V_48 , V_43 ) ;
}
void F_46 ( struct V_45 * V_46 , const char * V_37 , ... )
{
F_44 ( V_37 ) ;
if ( V_46 )
F_45 ( V_51 L_30 ,
V_46 -> V_50 , V_43 ) ;
else
F_45 ( V_51 L_31 , V_43 ) ;
}
static void F_47 ( const char * V_37 , ... )
{
F_44 ( V_37 ) ;
F_45 ( V_43 ) ;
}
void F_48 ( struct V_45 * V_52 , int V_53 , const char * V_37 , ... )
{
#ifdef F_49
F_44 ( V_37 ) ;
if ( V_52 )
F_45 ( V_54 L_32 ,
V_52 -> V_50 , V_43 ) ;
else
F_45 ( V_54 L_33 , V_43 ) ;
#endif
}
void F_50 ( struct V_45 * V_46 , const char * V_47 ,
const char * V_48 , const char * V_37 , ... )
{
F_44 ( V_37 ) ;
#ifdef F_49
F_51 () ;
#endif
if ( V_46 )
F_45 ( V_49 L_34 ,
V_46 -> V_50 , V_47 ? V_47 : L_27 , V_47 ? L_28 : L_27 ,
V_48 , V_43 ) ;
else
F_45 ( V_49 L_35 ,
V_47 ? V_47 : L_27 , V_47 ? L_28 : L_27 , V_48 , V_43 ) ;
F_52 () ;
}
void F_53 ( struct V_45 * V_46 , const char * V_47 ,
const char * V_48 , const char * V_37 , ... )
{
F_44 ( V_37 ) ;
F_54 ( V_46 == NULL ) ;
if ( F_55 ( V_46 ) )
F_50 ( V_46 , V_47 , V_48 , V_43 ) ;
if ( V_47 && V_47 [ 0 ] )
F_45 ( V_55 L_36 ,
V_46 -> V_50 , V_47 , V_48 , V_43 ) ;
else
F_45 ( V_55 L_37 ,
V_46 -> V_50 , V_48 , V_43 ) ;
if ( F_56 ( V_46 ) )
return;
F_46 ( V_46 , L_38 ) ;
V_46 -> V_56 |= V_57 ;
F_57 ( V_46 , - V_58 ) ;
}
void F_58 ( struct V_45 * V_46 , int V_59 , const char * V_37 , ... )
{
F_44 ( V_37 ) ;
if ( F_55 ( V_46 ) ) {
F_59 ( V_55 L_39 , V_46 -> V_50 ,
V_43 ) ;
}
if ( F_60 ( F_61 ( V_46 ) ) )
return;
F_45 ( V_55 L_40 , V_46 -> V_50 ,
V_43 ) ;
V_46 -> V_56 |= V_57 ;
F_57 ( V_46 , V_59 ) ;
}
static int F_62 ( struct V_27 * V_28 , int V_60 , int V_61 )
{
struct V_5 * V_2 ;
struct V_35 * V_36 ;
int V_62 ;
int V_63 , V_64 ;
if ( ! F_63 ( V_28 ) )
return 1 ;
F_64 ( V_28 ) ;
if ( V_60 == - 1 ) {
V_63 = 0 ;
V_64 = F_29 ( V_28 ) ;
} else {
V_63 = V_60 ;
V_64 = V_61 < F_29 ( V_28 ) ? V_61 : F_29 ( V_28 ) ;
}
F_47 ( L_41 , V_28 -> V_31 , V_28 ) ;
V_36 = F_65 ( V_28 , V_63 ) ;
F_47 ( L_42 , V_63 , V_36 ) ;
for ( V_62 = V_63 , V_2 = F_66 ( V_28 , V_63 ) , V_36 ++ ; V_62 < V_64 ;
V_62 ++ , V_2 ++ , V_36 ++ ) {
F_47 ( L_43 , V_62 , V_2 , V_62 + 1 , V_36 ) ;
if ( V_62 && V_62 % 4 == 0 )
F_45 ( L_44 ) ;
}
F_45 ( L_44 ) ;
return 0 ;
}
static int F_67 ( struct V_27 * V_28 , int V_65 , int V_60 ,
int V_61 )
{
struct V_66 * V_67 ;
struct V_16 * V_17 ;
int V_62 , V_68 ;
int V_63 , V_64 ;
if ( ! F_68 ( V_28 ) )
return 1 ;
F_69 ( V_28 ) ;
V_67 = F_70 ( V_28 ) ;
V_17 = V_16 ( V_28 , 0 ) ;
V_68 = F_71 ( V_67 ) ;
F_45
( L_45 ) ;
F_47 ( L_46 , V_28 -> V_31 , V_28 ) ;
if ( ! ( V_65 & V_69 ) ) {
F_47 ( L_47 ,
& ( V_17 -> V_19 ) , & ( ( V_17 + V_68 - 1 ) -> V_19 ) ) ;
return 0 ;
}
if ( V_60 < 0 || V_60 > V_68 - 1 )
V_63 = 0 ;
else
V_63 = V_60 ;
if ( V_61 < 0 || V_61 > V_68 )
V_64 = V_68 ;
else
V_64 = V_61 ;
V_17 += V_63 ;
F_45
( L_48 ) ;
F_45
( L_49 ) ;
for ( V_62 = V_63 ; V_62 < V_64 ; V_62 ++ , V_17 ++ ) {
F_45
( L_48 ) ;
F_47 ( L_50 , V_62 , V_17 ) ;
if ( V_65 & V_69 )
F_72 ( V_17 , F_73 ( V_28 , V_17 ) ) ;
}
F_45
( L_51 ) ;
return 0 ;
}
char * F_74 ( int V_70 )
{
if ( V_70 == V_71 )
return L_52 ;
if ( V_70 == V_72 )
return L_53 ;
if ( V_70 == V_73 )
return L_54 ;
return L_55 ;
}
static int F_75 ( struct V_27 * V_28 )
{
struct V_74 * V_75 =
(struct V_74 * ) ( V_28 -> V_76 ) ;
int V_77 , V_78 ;
char * V_6 ;
if ( F_76 ( V_75 ) ) {
V_6 = L_56 ;
} else if ( F_77 ( V_75 ) ) {
V_6 = L_57 ;
} else if ( F_78 ( V_75 ) ) {
V_6 = ( ( F_79 ( V_75 ) == V_79 ) ?
L_57 : L_56 ) ;
} else {
return 1 ;
}
F_45 ( L_58 , V_28 -> V_29 ,
( unsigned long long ) V_28 -> V_31 ) ;
F_45 ( L_59 , V_6 ) ;
F_45 ( L_60 , F_80 ( V_75 ) ) ;
F_45 ( L_61 , F_81 ( V_75 ) ) ;
F_45 ( L_62 , F_82 ( V_75 ) ) ;
V_77 = V_28 -> V_31 ;
V_78 = F_80 ( V_75 ) - V_77 - 1 - F_83 ( V_75 ) -
( ! F_78 ( V_75 ) ? F_84 ( V_75 ) +
1 : F_85 ( V_75 ) ) - F_82 ( V_75 ) ;
F_45
( L_63
L_64 , V_77 , F_83 ( V_75 ) ,
( ! F_78 ( V_75 ) ? ( F_84 ( V_75 ) + 1 ) :
F_85 ( V_75 ) ) , V_78 ) ;
F_45 ( L_65 , F_86 ( V_75 ) ) ;
F_45 ( L_66 , F_87 ( V_75 ) ) ;
F_45 ( L_67 , F_88 ( V_75 ) ) ;
F_45 ( L_68 , F_84 ( V_75 ) ) ;
F_45 ( L_69 , F_89 ( V_75 ) ) ;
F_45 ( L_70 ,
F_74 ( F_90 ( V_75 ) ) ) ;
F_45 ( L_71 , F_91 ( V_75 ) ) ;
return 0 ;
}
static int F_92 ( struct V_27 * V_28 )
{
struct V_80 * V_81 ;
if ( memcmp ( F_93 ( V_28 ) , V_82 , 8 ) )
return 1 ;
V_81 = (struct V_80 * ) ( V_28 -> V_76 ) ;
F_45 ( L_72 ,
( unsigned long long ) V_28 -> V_31 , F_94 ( V_81 ) ,
F_95 ( V_81 ) , F_96 ( V_81 ) ) ;
return 0 ;
}
void F_97 ( struct V_27 * V_28 , ... )
{
T_1 args ;
int V_83 , V_60 , V_61 ;
if ( ! V_28 ) {
F_45 ( L_73 ) ;
return;
}
va_start ( args , V_28 ) ;
V_83 = va_arg ( args , int ) ;
V_60 = va_arg ( args , int ) ;
V_61 = va_arg ( args , int ) ;
if ( F_67 ( V_28 , V_83 , V_60 , V_61 ) )
if ( F_62 ( V_28 , V_60 , V_61 ) )
if ( F_75 ( V_28 ) )
if ( F_92 ( V_28 ) )
F_45
( L_74 ,
( unsigned long long ) V_28 -> V_31 ) ;
va_end ( args ) ;
}
void F_98 ( struct V_84 * V_85 )
{
int V_86 = 0 ;
int V_62 ;
struct V_27 * V_87 , * V_88 ;
if ( ! V_85 )
return;
sprintf ( V_89 , L_44
L_75
L_76
L_77
L_78 ,
F_99 ( V_85 -> V_90 ) -> V_91 ,
V_85 -> V_92 , F_100 ( V_85 -> V_93 ) ,
V_85 -> V_93 -> V_94 ) ;
for ( V_86 = 0 ; V_86 < F_101 ( V_85 -> V_95 ) ; V_86 ++ ) {
if ( F_102 ( V_85 -> V_93 , V_86 ) <=
V_85 -> V_93 -> V_96
&& F_102 ( V_85 -> V_93 ,
V_86 ) > V_97 ) {
V_87 = F_103 ( V_85 -> V_93 , V_86 ) ;
V_88 = F_104 ( V_85 -> V_93 , V_86 ) ;
} else {
V_87 = NULL ;
V_88 = NULL ;
}
sprintf ( V_89 + strlen ( V_89 ) ,
L_79 ,
V_86 ,
( V_87 ) ? ( long long ) ( V_87 -> V_31 ) : ( - 1LL ) ,
( V_87 ) ? F_32 ( & V_87 -> V_32 ) : - 1 ,
( V_85 -> V_98 [ V_86 ] ) ? ( long long ) ( V_85 -> V_98 [ V_86 ] -> V_31 ) : ( - 1LL ) ,
( V_85 -> V_98 [ V_86 ] ) ? F_32 ( & V_85 -> V_98 [ V_86 ] -> V_32 ) : - 1 ,
( V_85 -> V_99 [ V_86 ] ) ? ( long long ) ( V_85 -> V_99 [ V_86 ] -> V_31 ) : ( - 1LL ) ,
( V_85 -> V_99 [ V_86 ] ) ? F_32 ( & V_85 -> V_99 [ V_86 ] -> V_32 ) : - 1 ,
( V_88 ) ? ( long long ) ( V_88 -> V_31 ) : ( - 1LL ) ,
( V_85 -> V_100 [ V_86 ] ) ? ( long long ) ( V_85 -> V_100 [ V_86 ] ->
V_31 ) : ( - 1LL ) ,
( V_85 -> V_101 [ V_86 ] ) ? ( long long ) ( V_85 -> V_101 [ V_86 ] ->
V_31 ) : ( - 1LL ) ,
( V_85 -> V_102 [ V_86 ] ) ? ( long long ) ( V_85 -> V_102 [ V_86 ] ->
V_31 ) : ( - 1LL ) ,
( V_85 -> V_103 [ V_86 ] ) ? ( long long ) ( V_85 -> V_103 [ V_86 ] ->
V_31 ) : ( - 1LL ) ) ;
}
sprintf ( V_89 + strlen ( V_89 ) ,
L_77
L_80
L_81 ,
V_85 -> V_95 [ 0 ] , V_85 -> V_104 [ 0 ] , V_85 -> V_105 , V_85 -> V_106 [ 0 ] ,
V_85 -> V_107 , V_85 -> V_108 [ 0 ] , V_85 -> V_109 , V_85 -> V_110 [ 0 ] ,
V_85 -> V_111 [ 0 ] , V_85 -> V_110 [ 1 ] , V_85 -> V_111 [ 1 ] ,
V_85 -> V_112 , V_85 -> V_113 [ 0 ] , V_85 -> V_114 [ 0 ] ) ;
V_86 = 0 ;
do {
V_86 ++ ;
sprintf ( V_89 + strlen ( V_89 ) ,
L_82 ,
V_86 , V_85 -> V_95 [ V_86 ] , V_85 -> V_104 [ V_86 ] , V_85 -> V_106 [ V_86 ] ,
V_85 -> V_108 [ V_86 ] ) ;
} while ( V_85 -> V_95 [ V_86 ] );
sprintf ( V_89 + strlen ( V_89 ) ,
L_77
L_83 ) ;
V_86 = 0 ;
for ( V_62 = 0 ; V_62 < F_101 ( V_85 -> V_115 ) ; V_62 ++ )
sprintf ( V_89 + strlen ( V_89 ) ,
L_84 , V_85 -> V_115 [ V_62 ] ,
V_85 -> V_115 [ V_62 ] ? ( unsigned long long ) V_85 -> V_115 [ V_62 ] ->
V_31 : 0ULL ,
V_85 -> V_115 [ V_62 ] ? F_32 ( & V_85 -> V_115 [ V_62 ] -> V_32 ) : 0 ,
( V_62 == F_101 ( V_85 -> V_115 ) - 1 ) ? L_44 : L_85 ) ;
sprintf ( V_89 + strlen ( V_89 ) ,
L_86 ) ;
}
void F_105 ( char * V_116 )
{
F_45 ( L_87 , V_116 , V_89 ) ;
}
static void F_106 ( struct V_27 * V_28 )
{
struct V_66 * V_67 ;
int V_68 ;
V_67 = F_70 ( V_28 ) ;
V_68 = F_71 ( V_67 ) ;
if ( V_68 > ( V_28 -> V_30 - V_117 ) / V_118 )
F_107 ( NULL , L_88 , L_89 ,
V_28 ) ;
if ( F_108 ( V_67 ) > V_28 -> V_30 - V_117 - V_118 * V_68 )
F_107 ( NULL , L_90 , L_91 ,
V_28 ) ;
}
static void F_109 ( struct V_27 * V_28 )
{
struct V_66 * V_67 ;
V_67 = F_70 ( V_28 ) ;
if ( ! ( F_28 ( V_28 ) > V_119 && F_28 ( V_28 ) <= V_120 ) )
F_107 ( NULL , L_92 , L_93 , V_28 ) ;
if ( F_29 ( V_28 ) > ( V_28 -> V_30 - V_117 ) / V_118 )
F_107 ( NULL , L_94 , L_89 , V_28 ) ;
if ( F_30 ( V_28 ) !=
V_28 -> V_30 - V_117 - V_121 * F_29 ( V_28 ) -
V_122 * ( F_29 ( V_28 ) + 1 ) )
F_107 ( NULL , L_95 , L_91 , V_28 ) ;
}
void F_69 ( struct V_27 * V_28 )
{
int V_62 ;
struct V_16 * V_17 ;
if ( ! V_28 )
return;
F_106 ( V_28 ) ;
for ( V_62 = 0 , V_17 = V_16 ( V_28 , 0 ) ; V_62 < F_29 ( V_28 ) ; V_62 ++ , V_17 ++ )
F_110 ( V_17 , F_73 ( V_28 , V_17 ) ) ;
}
void F_64 ( struct V_27 * V_28 )
{
if ( ! V_28 )
return;
F_109 ( V_28 ) ;
}
void F_111 ( struct V_45 * V_52 )
{
}
