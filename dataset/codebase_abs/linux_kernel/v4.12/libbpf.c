static int F_1 ( const char * V_1 , ... )
{
T_1 args ;
int V_2 ;
va_start ( args , V_1 ) ;
V_2 = vfprintf ( V_3 , V_1 , args ) ;
va_end ( args ) ;
return V_2 ;
}
void F_2 ( T_2 V_4 ,
T_2 V_5 ,
T_2 V_6 )
{
V_7 = V_4 ;
V_8 = V_5 ;
V_9 = V_6 ;
}
int F_3 ( int V_2 , char * V_10 , T_3 V_11 )
{
if ( ! V_10 || ! V_11 )
return - 1 ;
V_2 = V_2 > 0 ? V_2 : - V_2 ;
if ( V_2 < V_12 ) {
int V_13 ;
V_13 = F_4 ( V_2 , V_10 , V_11 ) ;
V_10 [ V_11 - 1 ] = '\0' ;
return V_13 ;
}
if ( V_2 < V_14 ) {
const char * V_15 ;
V_15 = V_16 [ F_5 ( V_2 ) ] ;
snprintf ( V_10 , V_11 , L_1 , V_15 ) ;
V_10 [ V_11 - 1 ] = '\0' ;
return 0 ;
}
snprintf ( V_10 , V_11 , L_2 , V_2 ) ;
V_10 [ V_11 - 1 ] = '\0' ;
return - 1 ;
}
static void F_6 ( struct V_17 * V_18 )
{
int V_19 ;
if ( ! V_18 )
return;
if ( V_18 -> V_20 . V_21 > 0 ) {
for ( V_19 = 0 ; V_19 < V_18 -> V_20 . V_21 ; V_19 ++ )
F_7 ( V_18 -> V_20 . V_22 [ V_19 ] ) ;
} else if ( V_18 -> V_20 . V_21 != - 1 ) {
F_8 ( L_3 ,
V_18 -> V_20 . V_21 ) ;
}
V_18 -> V_20 . V_21 = - 1 ;
F_9 ( & V_18 -> V_20 . V_22 ) ;
}
static void F_10 ( struct V_17 * V_18 )
{
if ( ! V_18 )
return;
if ( V_18 -> V_23 )
V_18 -> V_23 ( V_18 , V_18 -> V_24 ) ;
V_18 -> V_24 = NULL ;
V_18 -> V_23 = NULL ;
F_6 ( V_18 ) ;
F_9 ( & V_18 -> V_25 ) ;
F_9 ( & V_18 -> V_26 ) ;
F_9 ( & V_18 -> V_27 ) ;
V_18 -> V_28 = 0 ;
V_18 -> V_29 = 0 ;
V_18 -> V_30 = - 1 ;
}
static int
F_11 ( void * V_31 , T_3 V_11 , char * V_32 , int V_30 ,
struct V_17 * V_18 )
{
if ( V_11 < sizeof( struct V_33 ) ) {
F_8 ( L_4 , V_32 ) ;
return - V_34 ;
}
F_12 ( V_18 , sizeof( * V_18 ) ) ;
V_18 -> V_25 = F_13 ( V_32 ) ;
if ( ! V_18 -> V_25 ) {
F_8 ( L_5 ,
V_32 ) ;
goto V_35;
}
V_18 -> V_26 = malloc ( V_11 ) ;
if ( ! V_18 -> V_26 ) {
F_8 ( L_6 , V_32 ) ;
goto V_35;
}
V_18 -> V_29 = V_11 / sizeof( struct V_33 ) ;
memcpy ( V_18 -> V_26 , V_31 ,
V_18 -> V_29 * sizeof( struct V_33 ) ) ;
V_18 -> V_30 = V_30 ;
V_18 -> V_20 . V_22 = NULL ;
V_18 -> V_20 . V_21 = - 1 ;
V_18 -> type = V_36 ;
return 0 ;
V_35:
F_10 ( V_18 ) ;
return - V_37 ;
}
static int
F_14 ( struct V_38 * V_39 , void * V_31 , T_3 V_11 ,
char * V_32 , int V_30 )
{
struct V_17 V_18 , * V_40 ;
int V_41 , V_2 ;
V_2 = F_11 ( V_31 , V_11 , V_32 , V_30 , & V_18 ) ;
if ( V_2 )
return V_2 ;
V_40 = V_39 -> V_42 ;
V_41 = V_39 -> V_43 ;
V_40 = realloc ( V_40 , sizeof( V_40 [ 0 ] ) * ( V_41 + 1 ) ) ;
if ( ! V_40 ) {
F_8 ( L_7 ,
V_32 ) ;
F_10 ( & V_18 ) ;
return - V_37 ;
}
F_15 ( L_8 , V_18 . V_25 ) ;
V_39 -> V_42 = V_40 ;
V_39 -> V_43 = V_41 + 1 ;
V_18 . V_39 = V_39 ;
V_40 [ V_41 ] = V_18 ;
return 0 ;
}
static struct V_38 * F_16 ( const char * V_44 ,
void * V_45 ,
T_3 V_46 )
{
struct V_38 * V_39 ;
V_39 = calloc ( 1 , sizeof( struct V_38 ) + strlen ( V_44 ) + 1 ) ;
if ( ! V_39 ) {
F_8 ( L_9 , V_44 ) ;
return F_17 ( - V_37 ) ;
}
strcpy ( V_39 -> V_44 , V_44 ) ;
V_39 -> V_47 . V_48 = - 1 ;
V_39 -> V_47 . V_45 = V_45 ;
V_39 -> V_47 . V_46 = V_46 ;
V_39 -> V_47 . V_49 = - 1 ;
V_39 -> V_50 = false ;
F_18 ( & V_39 -> V_51 ) ;
F_19 ( & V_39 -> V_51 , & V_52 ) ;
return V_39 ;
}
static void F_20 ( struct V_38 * V_39 )
{
if ( ! F_21 ( V_39 ) )
return;
if ( V_39 -> V_47 . V_53 ) {
F_22 ( V_39 -> V_47 . V_53 ) ;
V_39 -> V_47 . V_53 = NULL ;
}
V_39 -> V_47 . V_54 = NULL ;
F_9 ( & V_39 -> V_47 . V_55 ) ;
V_39 -> V_47 . V_28 = 0 ;
F_7 ( V_39 -> V_47 . V_48 ) ;
V_39 -> V_47 . V_45 = NULL ;
V_39 -> V_47 . V_46 = 0 ;
}
static int F_23 ( struct V_38 * V_39 )
{
int V_2 = 0 ;
T_4 * V_56 ;
if ( F_21 ( V_39 ) ) {
F_8 ( L_10 ) ;
return - V_57 ;
}
if ( V_39 -> V_47 . V_46 > 0 ) {
V_39 -> V_47 . V_53 = F_24 ( V_39 -> V_47 . V_45 ,
V_39 -> V_47 . V_46 ) ;
} else {
V_39 -> V_47 . V_48 = F_25 ( V_39 -> V_44 , V_58 ) ;
if ( V_39 -> V_47 . V_48 < 0 ) {
F_8 ( L_11 , V_39 -> V_44 ,
strerror ( V_59 ) ) ;
return - V_59 ;
}
V_39 -> V_47 . V_53 = F_26 ( V_39 -> V_47 . V_48 ,
V_60 ,
NULL ) ;
}
if ( ! V_39 -> V_47 . V_53 ) {
F_8 ( L_12 ,
V_39 -> V_44 ) ;
V_2 = - V_57 ;
goto V_35;
}
if ( ! F_27 ( V_39 -> V_47 . V_53 , & V_39 -> V_47 . V_61 ) ) {
F_8 ( L_13 ,
V_39 -> V_44 ) ;
V_2 = - V_62 ;
goto V_35;
}
V_56 = & V_39 -> V_47 . V_61 ;
if ( ( V_56 -> V_63 != V_64 ) || ( V_56 -> V_65 && ( V_56 -> V_65 != V_66 ) ) ) {
F_8 ( L_14 ,
V_39 -> V_44 ) ;
V_2 = - V_62 ;
goto V_35;
}
return 0 ;
V_35:
F_20 ( V_39 ) ;
return V_2 ;
}
static int
F_28 ( struct V_38 * V_39 )
{
static unsigned int const V_67 = 1 ;
switch ( V_39 -> V_47 . V_61 . V_68 [ V_69 ] ) {
case V_70 :
if ( * ( unsigned char const * ) & V_67 != 1 )
goto V_71;
break;
case V_72 :
if ( * ( unsigned char const * ) & V_67 != 0 )
goto V_71;
break;
default:
return - V_73 ;
}
return 0 ;
V_71:
F_8 ( L_15 ) ;
return - V_73 ;
}
static int
F_29 ( struct V_38 * V_39 ,
void * V_31 , T_3 V_11 )
{
memcpy ( V_39 -> V_74 , V_31 ,
F_30 ( V_11 , sizeof( V_39 -> V_74 ) - 1 ) ) ;
F_15 ( L_16 , V_39 -> V_44 , V_39 -> V_74 ) ;
return 0 ;
}
static int
F_31 ( struct V_38 * V_39 ,
void * V_31 , T_3 V_11 )
{
T_5 V_75 ;
if ( V_11 != sizeof( V_75 ) ) {
F_8 ( L_17 , V_39 -> V_44 ) ;
return - V_62 ;
}
memcpy ( & V_75 , V_31 , sizeof( V_75 ) ) ;
V_39 -> V_76 = V_75 ;
F_15 ( L_18 , V_39 -> V_44 ,
V_39 -> V_76 ) ;
return 0 ;
}
static int
F_32 ( struct V_38 * V_39 )
{
int V_19 ;
if ( ! V_39 -> V_77 || ! V_39 -> V_78 || ( V_39 -> V_78 == 1 ) )
return 0 ;
for ( V_19 = 1 ; V_19 < V_39 -> V_78 ; V_19 ++ ) {
const struct V_79 * V_80 = & V_39 -> V_77 [ V_19 - 1 ] ;
const struct V_79 * V_81 = & V_39 -> V_77 [ V_19 ] ;
if ( V_81 -> V_82 - V_80 -> V_82 < sizeof( struct V_83 ) ) {
F_8 ( L_19 ,
V_39 -> V_44 , V_80 -> V_32 ) ;
return - V_34 ;
}
}
return 0 ;
}
static int F_33 ( const void * V_84 , const void * V_85 )
{
const struct V_79 * V_80 = V_84 ;
const struct V_79 * V_81 = V_85 ;
return V_80 -> V_82 - V_81 -> V_82 ;
}
static int
F_34 ( struct V_38 * V_39 )
{
int V_19 , V_86 , V_78 = 0 ;
T_6 * V_87 ;
T_7 * V_31 ;
T_7 * V_54 = V_39 -> V_47 . V_54 ;
if ( V_39 -> V_47 . V_49 < 0 )
return - V_34 ;
if ( ! V_54 )
return - V_34 ;
V_87 = F_35 ( V_39 -> V_47 . V_53 , V_39 -> V_47 . V_49 ) ;
if ( V_87 )
V_31 = F_36 ( V_87 , NULL ) ;
if ( ! V_87 || ! V_31 ) {
F_8 ( L_20 ,
V_39 -> V_47 . V_49 ) ;
return - V_34 ;
}
for ( V_19 = 0 ; V_19 < V_54 -> V_88 / sizeof( V_89 ) ; V_19 ++ ) {
V_89 V_90 ;
if ( ! F_37 ( V_54 , V_19 , & V_90 ) )
continue;
if ( V_90 . V_91 != V_39 -> V_47 . V_49 )
continue;
V_78 ++ ;
}
F_15 ( L_21 , V_39 -> V_44 ,
V_78 , V_31 -> V_88 ) ;
if ( ! V_78 )
return 0 ;
V_39 -> V_77 = calloc ( V_78 , sizeof( V_39 -> V_77 [ 0 ] ) ) ;
if ( ! V_39 -> V_77 ) {
F_8 ( L_22 ) ;
return - V_37 ;
}
V_39 -> V_78 = V_78 ;
for ( V_19 = 0 ; V_19 < V_78 ; V_19 ++ )
V_39 -> V_77 [ V_19 ] . V_48 = - 1 ;
for ( V_19 = 0 , V_86 = 0 ; V_19 < V_54 -> V_88 / sizeof( V_89 ) ; V_19 ++ ) {
V_89 V_90 ;
const char * V_92 ;
struct V_83 * V_93 ;
if ( ! F_37 ( V_54 , V_19 , & V_90 ) )
continue;
if ( V_90 . V_91 != V_39 -> V_47 . V_49 )
continue;
V_92 = F_38 ( V_39 -> V_47 . V_53 ,
V_39 -> V_47 . V_94 ,
V_90 . V_95 ) ;
V_39 -> V_77 [ V_86 ] . V_82 = V_90 . V_96 ;
if ( V_90 . V_96 + sizeof( struct V_83 ) > V_31 -> V_88 ) {
F_8 ( L_23 ,
V_39 -> V_44 , V_92 ) ;
return - V_34 ;
}
V_39 -> V_77 [ V_86 ] . V_32 = F_13 ( V_92 ) ;
if ( ! V_39 -> V_77 [ V_86 ] . V_32 ) {
F_8 ( L_24 ) ;
return - V_37 ;
}
F_15 ( L_25 , V_86 ,
V_39 -> V_77 [ V_86 ] . V_32 ) ;
V_93 = (struct V_83 * ) ( V_31 -> V_97 + V_90 . V_96 ) ;
V_39 -> V_77 [ V_86 ] . V_93 = * V_93 ;
V_86 ++ ;
}
qsort ( V_39 -> V_77 , V_39 -> V_78 , sizeof( V_39 -> V_77 [ 0 ] ) , F_33 ) ;
return F_32 ( V_39 ) ;
}
static int F_39 ( struct V_38 * V_39 )
{
T_8 * V_53 = V_39 -> V_47 . V_53 ;
T_4 * V_56 = & V_39 -> V_47 . V_61 ;
T_6 * V_87 = NULL ;
int V_30 = 0 , V_2 = 0 ;
if ( ! F_40 ( F_35 ( V_53 , V_56 -> V_98 ) , NULL ) ) {
F_8 ( L_26 ,
V_39 -> V_44 ) ;
return - V_62 ;
}
while ( ( V_87 = F_41 ( V_53 , V_87 ) ) != NULL ) {
char * V_32 ;
T_9 V_99 ;
T_7 * V_31 ;
V_30 ++ ;
if ( F_42 ( V_87 , & V_99 ) != & V_99 ) {
F_8 ( L_27 ,
V_39 -> V_44 ) ;
V_2 = - V_62 ;
goto V_100;
}
V_32 = F_38 ( V_53 , V_56 -> V_98 , V_99 . V_101 ) ;
if ( ! V_32 ) {
F_8 ( L_28 ,
V_39 -> V_44 ) ;
V_2 = - V_62 ;
goto V_100;
}
V_31 = F_36 ( V_87 , 0 ) ;
if ( ! V_31 ) {
F_8 ( L_29 ,
V_32 , V_39 -> V_44 ) ;
V_2 = - V_62 ;
goto V_100;
}
F_15 ( L_30 ,
V_32 , ( unsigned long ) V_31 -> V_88 ,
( int ) V_99 . V_102 , ( unsigned long ) V_99 . V_103 ,
( int ) V_99 . V_104 ) ;
if ( strcmp ( V_32 , L_31 ) == 0 )
V_2 = F_29 ( V_39 ,
V_31 -> V_97 ,
V_31 -> V_88 ) ;
else if ( strcmp ( V_32 , L_32 ) == 0 )
V_2 = F_31 ( V_39 ,
V_31 -> V_97 ,
V_31 -> V_88 ) ;
else if ( strcmp ( V_32 , L_33 ) == 0 )
V_39 -> V_47 . V_49 = V_30 ;
else if ( V_99 . V_104 == V_105 ) {
if ( V_39 -> V_47 . V_54 ) {
F_8 ( L_34 ,
V_39 -> V_44 ) ;
V_2 = - V_62 ;
} else {
V_39 -> V_47 . V_54 = V_31 ;
V_39 -> V_47 . V_94 = V_99 . V_102 ;
}
} else if ( ( V_99 . V_104 == V_106 ) &&
( V_99 . V_103 & V_107 ) &&
( V_31 -> V_88 > 0 ) ) {
V_2 = F_14 ( V_39 , V_31 -> V_97 ,
V_31 -> V_88 , V_32 , V_30 ) ;
if ( V_2 ) {
char V_108 [ V_109 ] ;
F_4 ( - V_2 , V_108 , sizeof( V_108 ) ) ;
F_8 ( L_35 ,
V_32 , V_39 -> V_44 , V_108 ) ;
}
} else if ( V_99 . V_104 == V_110 ) {
void * V_55 = V_39 -> V_47 . V_55 ;
int V_28 = V_39 -> V_47 . V_28 + 1 ;
V_55 = realloc ( V_55 ,
sizeof( * V_39 -> V_47 . V_55 ) * V_28 ) ;
if ( ! V_55 ) {
F_8 ( L_36 ) ;
V_2 = - V_37 ;
} else {
int V_111 = V_28 - 1 ;
V_39 -> V_47 . V_55 = V_55 ;
V_39 -> V_47 . V_28 = V_28 ;
V_39 -> V_47 . V_55 [ V_111 ] . V_112 = V_99 ;
V_39 -> V_47 . V_55 [ V_111 ] . V_31 = V_31 ;
}
}
if ( V_2 )
goto V_100;
}
if ( ! V_39 -> V_47 . V_94 || V_39 -> V_47 . V_94 >= V_30 ) {
F_8 ( L_37 ) ;
return V_62 ;
}
if ( V_39 -> V_47 . V_49 >= 0 )
V_2 = F_34 ( V_39 ) ;
V_100:
return V_2 ;
}
static struct V_17 *
F_43 ( struct V_38 * V_39 , int V_30 )
{
struct V_17 * V_18 ;
T_3 V_19 ;
for ( V_19 = 0 ; V_19 < V_39 -> V_43 ; V_19 ++ ) {
V_18 = & V_39 -> V_42 [ V_19 ] ;
if ( V_18 -> V_30 == V_30 )
return V_18 ;
}
return NULL ;
}
static int
F_44 ( struct V_17 * V_18 ,
T_3 V_78 , T_9 * V_112 ,
T_7 * V_31 , T_7 * V_54 ,
int V_49 , struct V_79 * V_77 )
{
int V_19 , V_113 ;
F_15 ( L_38 ,
V_18 -> V_25 ) ;
V_113 = V_112 -> V_114 / V_112 -> V_115 ;
V_18 -> V_27 = malloc ( sizeof( * V_18 -> V_27 ) * V_113 ) ;
if ( ! V_18 -> V_27 ) {
F_8 ( L_39 ) ;
return - V_37 ;
}
V_18 -> V_28 = V_113 ;
for ( V_19 = 0 ; V_19 < V_113 ; V_19 ++ ) {
V_89 V_90 ;
T_10 V_116 ;
unsigned int V_117 ;
struct V_33 * V_26 = V_18 -> V_26 ;
T_3 V_86 ;
if ( ! F_45 ( V_31 , V_19 , & V_116 ) ) {
F_8 ( L_40 , V_19 ) ;
return - V_62 ;
}
if ( ! F_37 ( V_54 ,
F_46 ( V_116 . V_118 ) ,
& V_90 ) ) {
F_8 ( L_41 V_119 L_42 ,
F_46 ( V_116 . V_118 ) ) ;
return - V_62 ;
}
if ( V_90 . V_91 != V_49 ) {
F_8 ( L_43 ,
V_18 -> V_25 , V_90 . V_91 ) ;
return - V_120 ;
}
V_117 = V_116 . V_121 / sizeof( struct V_33 ) ;
F_15 ( L_44 , V_117 ) ;
if ( V_26 [ V_117 ] . V_122 != ( V_123 | V_124 | V_125 ) ) {
F_8 ( L_45 ,
V_117 , V_26 [ V_117 ] . V_122 ) ;
return - V_120 ;
}
for ( V_86 = 0 ; V_86 < V_78 ; V_86 ++ ) {
if ( V_77 [ V_86 ] . V_82 == V_90 . V_96 ) {
F_15 ( L_46 ,
V_86 , V_77 [ V_86 ] . V_32 , V_117 ) ;
break;
}
}
if ( V_86 >= V_78 ) {
F_8 ( L_47 ,
( int ) V_86 , ( int ) V_78 - 1 ) ;
return - V_120 ;
}
V_18 -> V_27 [ V_19 ] . V_117 = V_117 ;
V_18 -> V_27 [ V_19 ] . V_86 = V_86 ;
}
return 0 ;
}
static int
F_47 ( struct V_38 * V_39 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_39 -> V_78 ; V_19 ++ ) {
struct V_83 * V_93 = & V_39 -> V_77 [ V_19 ] . V_93 ;
int * V_126 = & V_39 -> V_77 [ V_19 ] . V_48 ;
* V_126 = F_48 ( V_93 -> type ,
V_93 -> V_127 ,
V_93 -> V_128 ,
V_93 -> V_129 ,
0 ) ;
if ( * V_126 < 0 ) {
T_3 V_130 ;
int V_2 = * V_126 ;
F_8 ( L_48 ,
strerror ( V_59 ) ) ;
for ( V_130 = 0 ; V_130 < V_19 ; V_130 ++ )
F_7 ( V_39 -> V_77 [ V_130 ] . V_48 ) ;
return V_2 ;
}
F_15 ( L_49 , V_39 -> V_77 [ V_19 ] . V_32 , * V_126 ) ;
}
return 0 ;
}
static int
F_49 ( struct V_17 * V_18 , struct V_38 * V_39 )
{
int V_19 ;
if ( ! V_18 || ! V_18 -> V_27 )
return 0 ;
for ( V_19 = 0 ; V_19 < V_18 -> V_28 ; V_19 ++ ) {
int V_117 , V_86 ;
struct V_33 * V_26 = V_18 -> V_26 ;
V_117 = V_18 -> V_27 [ V_19 ] . V_117 ;
V_86 = V_18 -> V_27 [ V_19 ] . V_86 ;
if ( V_117 >= ( int ) V_18 -> V_29 ) {
F_8 ( L_50 ,
V_18 -> V_25 ) ;
return - V_120 ;
}
V_26 [ V_117 ] . V_131 = V_132 ;
V_26 [ V_117 ] . V_133 = V_39 -> V_77 [ V_86 ] . V_48 ;
}
F_9 ( & V_18 -> V_27 ) ;
V_18 -> V_28 = 0 ;
return 0 ;
}
static int
F_50 ( struct V_38 * V_39 )
{
struct V_17 * V_18 ;
T_3 V_19 ;
int V_2 ;
for ( V_19 = 0 ; V_19 < V_39 -> V_43 ; V_19 ++ ) {
V_18 = & V_39 -> V_42 [ V_19 ] ;
V_2 = F_49 ( V_18 , V_39 ) ;
if ( V_2 ) {
F_8 ( L_51 ,
V_18 -> V_25 ) ;
return V_2 ;
}
}
return 0 ;
}
static int F_51 ( struct V_38 * V_39 )
{
int V_19 , V_2 ;
if ( ! F_21 ( V_39 ) ) {
F_8 ( L_52 ) ;
return - V_134 ;
}
for ( V_19 = 0 ; V_19 < V_39 -> V_47 . V_28 ; V_19 ++ ) {
T_9 * V_112 = & V_39 -> V_47 . V_55 [ V_19 ] . V_112 ;
T_7 * V_31 = V_39 -> V_47 . V_55 [ V_19 ] . V_31 ;
int V_30 = V_112 -> V_135 ;
struct V_17 * V_18 ;
T_3 V_78 = V_39 -> V_78 ;
if ( V_112 -> V_104 != V_110 ) {
F_8 ( L_53 , __LINE__ ) ;
return - V_134 ;
}
V_18 = F_43 ( V_39 , V_30 ) ;
if ( ! V_18 ) {
F_8 ( L_54 ,
V_30 ) ;
return - V_120 ;
}
V_2 = F_44 ( V_18 , V_78 ,
V_112 , V_31 ,
V_39 -> V_47 . V_54 ,
V_39 -> V_47 . V_49 ,
V_39 -> V_77 ) ;
if ( V_2 )
return V_2 ;
}
return 0 ;
}
static int
F_52 ( enum V_136 type , struct V_33 * V_26 ,
int V_29 , char * V_74 , T_5 V_76 , int * V_126 )
{
int V_13 ;
char * V_137 ;
if ( ! V_26 || ! V_29 )
return - V_34 ;
V_137 = malloc ( V_138 ) ;
if ( ! V_137 )
F_8 ( L_55 ) ;
V_13 = F_53 ( type , V_26 , V_29 , V_74 ,
V_76 , V_137 , V_138 ) ;
if ( V_13 >= 0 ) {
* V_126 = V_13 ;
V_13 = 0 ;
goto V_100;
}
V_13 = - V_139 ;
F_8 ( L_56 , strerror ( V_59 ) ) ;
if ( V_137 && V_137 [ 0 ] != '\0' ) {
V_13 = - V_140 ;
F_8 ( L_57 ) ;
F_8 ( L_58 , V_137 ) ;
F_8 ( L_59 ) ;
} else if ( V_29 >= V_141 ) {
F_8 ( L_60 ,
V_29 , V_141 ) ;
V_13 = - V_142 ;
} else {
if ( type != V_36 ) {
int V_48 ;
V_48 = F_53 ( V_36 , V_26 ,
V_29 , V_74 , V_76 ,
NULL , 0 ) ;
if ( V_48 >= 0 ) {
F_54 ( V_48 ) ;
V_13 = - V_143 ;
goto V_100;
}
}
if ( V_137 )
V_13 = - V_144 ;
}
V_100:
free ( V_137 ) ;
return V_13 ;
}
static int
F_55 ( struct V_17 * V_18 ,
char * V_74 , T_5 V_76 )
{
int V_2 = 0 , V_48 , V_19 ;
if ( V_18 -> V_20 . V_21 < 0 || ! V_18 -> V_20 . V_22 ) {
if ( V_18 -> V_145 ) {
F_8 ( L_61 ,
V_18 -> V_25 ) ;
return - V_134 ;
}
V_18 -> V_20 . V_22 = malloc ( sizeof( int ) ) ;
if ( ! V_18 -> V_20 . V_22 ) {
F_8 ( L_62 ) ;
return - V_37 ;
}
V_18 -> V_20 . V_21 = 1 ;
V_18 -> V_20 . V_22 [ 0 ] = - 1 ;
}
if ( ! V_18 -> V_145 ) {
if ( V_18 -> V_20 . V_21 != 1 ) {
F_8 ( L_63 ,
V_18 -> V_25 , V_18 -> V_20 . V_21 ) ;
}
V_2 = F_52 ( V_18 -> type , V_18 -> V_26 , V_18 -> V_29 ,
V_74 , V_76 , & V_48 ) ;
if ( ! V_2 )
V_18 -> V_20 . V_22 [ 0 ] = V_48 ;
goto V_100;
}
for ( V_19 = 0 ; V_19 < V_18 -> V_20 . V_21 ; V_19 ++ ) {
struct V_146 V_147 ;
T_11 V_145 = V_18 -> V_145 ;
F_12 ( & V_147 , sizeof( V_147 ) ) ;
V_2 = V_145 ( V_18 , V_19 , V_18 -> V_26 ,
V_18 -> V_29 , & V_147 ) ;
if ( V_2 ) {
F_8 ( L_64 ,
V_19 , V_18 -> V_25 ) ;
goto V_100;
}
if ( ! V_147 . V_148 || ! V_147 . V_149 ) {
F_15 ( L_65 ,
V_19 , V_18 -> V_25 ) ;
V_18 -> V_20 . V_22 [ V_19 ] = - 1 ;
if ( V_147 . V_126 )
* V_147 . V_126 = - 1 ;
continue;
}
V_2 = F_52 ( V_18 -> type , V_147 . V_148 ,
V_147 . V_149 ,
V_74 , V_76 , & V_48 ) ;
if ( V_2 ) {
F_8 ( L_66 ,
V_19 , V_18 -> V_25 ) ;
goto V_100;
}
if ( V_147 . V_126 )
* V_147 . V_126 = V_48 ;
V_18 -> V_20 . V_22 [ V_19 ] = V_48 ;
}
V_100:
if ( V_2 )
F_8 ( L_67 ,
V_18 -> V_25 ) ;
F_9 ( & V_18 -> V_26 ) ;
V_18 -> V_29 = 0 ;
return V_2 ;
}
static int
F_56 ( struct V_38 * V_39 )
{
T_3 V_19 ;
int V_2 ;
for ( V_19 = 0 ; V_19 < V_39 -> V_43 ; V_19 ++ ) {
V_2 = F_55 ( & V_39 -> V_42 [ V_19 ] ,
V_39 -> V_74 ,
V_39 -> V_76 ) ;
if ( V_2 )
return V_2 ;
}
return 0 ;
}
static int F_57 ( struct V_38 * V_39 )
{
if ( V_39 -> V_76 == 0 ) {
F_8 ( L_68 ,
V_39 -> V_44 ) ;
return - V_150 ;
}
return 0 ;
}
static struct V_38 *
F_58 ( const char * V_44 , void * V_45 , T_3 V_46 )
{
struct V_38 * V_39 ;
int V_2 ;
if ( F_59 ( V_151 ) == V_152 ) {
F_8 ( L_69 , V_44 ) ;
return F_17 ( - V_57 ) ;
}
V_39 = F_16 ( V_44 , V_45 , V_46 ) ;
if ( F_60 ( V_39 ) )
return V_39 ;
F_61 ( F_23 ( V_39 ) , V_2 , V_100 ) ;
F_61 ( F_28 ( V_39 ) , V_2 , V_100 ) ;
F_61 ( F_39 ( V_39 ) , V_2 , V_100 ) ;
F_61 ( F_51 ( V_39 ) , V_2 , V_100 ) ;
F_61 ( F_57 ( V_39 ) , V_2 , V_100 ) ;
F_20 ( V_39 ) ;
return V_39 ;
V_100:
F_62 ( V_39 ) ;
return F_17 ( V_2 ) ;
}
struct V_38 * F_63 ( const char * V_44 )
{
if ( ! V_44 )
return NULL ;
F_15 ( L_70 , V_44 ) ;
return F_58 ( V_44 , NULL , 0 ) ;
}
struct V_38 * F_64 ( void * V_45 ,
T_3 V_46 ,
const char * V_32 )
{
char V_153 [ 64 ] ;
if ( ! V_45 || V_46 <= 0 )
return NULL ;
if ( ! V_32 ) {
snprintf ( V_153 , sizeof( V_153 ) , L_71 ,
( unsigned long ) V_45 ,
( unsigned long ) V_46 ) ;
V_153 [ sizeof( V_153 ) - 1 ] = '\0' ;
V_32 = V_153 ;
}
F_15 ( L_72 ,
V_32 ) ;
return F_58 ( V_32 , V_45 , V_46 ) ;
}
int F_65 ( struct V_38 * V_39 )
{
T_3 V_19 ;
if ( ! V_39 )
return - V_34 ;
for ( V_19 = 0 ; V_19 < V_39 -> V_78 ; V_19 ++ )
F_7 ( V_39 -> V_77 [ V_19 ] . V_48 ) ;
for ( V_19 = 0 ; V_19 < V_39 -> V_43 ; V_19 ++ )
F_6 ( & V_39 -> V_42 [ V_19 ] ) ;
return 0 ;
}
int F_66 ( struct V_38 * V_39 )
{
int V_2 ;
if ( ! V_39 )
return - V_34 ;
if ( V_39 -> V_50 ) {
F_8 ( L_73 ) ;
return - V_34 ;
}
V_39 -> V_50 = true ;
F_61 ( F_47 ( V_39 ) , V_2 , V_100 ) ;
F_61 ( F_50 ( V_39 ) , V_2 , V_100 ) ;
F_61 ( F_56 ( V_39 ) , V_2 , V_100 ) ;
return 0 ;
V_100:
F_65 ( V_39 ) ;
F_8 ( L_74 , V_39 -> V_44 ) ;
return V_2 ;
}
static int F_67 ( const char * V_44 )
{
struct V_154 V_155 ;
char * V_156 , * V_157 ;
int V_2 = 0 ;
if ( V_44 == NULL )
return - V_34 ;
V_156 = F_13 ( V_44 ) ;
if ( V_156 == NULL )
return - V_37 ;
V_157 = F_68 ( V_156 ) ;
if ( V_154 ( V_157 , & V_155 ) ) {
F_8 ( L_75 , V_157 , strerror ( V_59 ) ) ;
V_2 = - V_59 ;
}
free ( V_156 ) ;
if ( ! V_2 && V_155 . V_158 != V_159 ) {
F_8 ( L_76 , V_44 ) ;
V_2 = - V_34 ;
}
return V_2 ;
}
int F_69 ( struct V_17 * V_18 , const char * V_44 ,
int V_160 )
{
int V_2 ;
V_2 = F_67 ( V_44 ) ;
if ( V_2 )
return V_2 ;
if ( V_18 == NULL ) {
F_8 ( L_77 ) ;
return - V_34 ;
}
if ( V_160 < 0 || V_160 >= V_18 -> V_20 . V_21 ) {
F_8 ( L_78 ,
V_160 , V_18 -> V_25 , V_18 -> V_20 . V_21 ) ;
return - V_34 ;
}
if ( F_70 ( V_18 -> V_20 . V_22 [ V_160 ] , V_44 ) ) {
F_8 ( L_79 , strerror ( V_59 ) ) ;
return - V_59 ;
}
F_15 ( L_80 , V_44 ) ;
return 0 ;
}
static int F_71 ( const char * V_44 )
{
int V_2 = 0 ;
if ( F_72 ( V_44 , 0700 ) && V_59 != V_161 )
V_2 = - V_59 ;
if ( V_2 )
F_8 ( L_81 , V_44 , strerror ( - V_2 ) ) ;
return V_2 ;
}
int F_73 ( struct V_17 * V_18 , const char * V_44 )
{
int V_19 , V_2 ;
V_2 = F_67 ( V_44 ) ;
if ( V_2 )
return V_2 ;
if ( V_18 == NULL ) {
F_8 ( L_77 ) ;
return - V_34 ;
}
if ( V_18 -> V_20 . V_21 <= 0 ) {
F_8 ( L_82 ,
V_18 -> V_25 ) ;
return - V_34 ;
}
V_2 = F_71 ( V_44 ) ;
if ( V_2 )
return V_2 ;
for ( V_19 = 0 ; V_19 < V_18 -> V_20 . V_21 ; V_19 ++ ) {
char V_10 [ V_162 ] ;
int V_163 ;
V_163 = snprintf ( V_10 , V_162 , L_83 , V_44 , V_19 ) ;
if ( V_163 < 0 )
return - V_34 ;
else if ( V_163 >= V_162 )
return - V_164 ;
V_2 = F_69 ( V_18 , V_10 , V_19 ) ;
if ( V_2 )
return V_2 ;
}
return 0 ;
}
int F_74 ( struct V_79 * V_165 , const char * V_44 )
{
int V_2 ;
V_2 = F_67 ( V_44 ) ;
if ( V_2 )
return V_2 ;
if ( V_165 == NULL ) {
F_8 ( L_84 ) ;
return - V_34 ;
}
if ( F_70 ( V_165 -> V_48 , V_44 ) ) {
F_8 ( L_85 , strerror ( V_59 ) ) ;
return - V_59 ;
}
F_15 ( L_86 , V_44 ) ;
return 0 ;
}
int F_75 ( struct V_38 * V_39 , const char * V_44 )
{
struct V_17 * V_18 ;
struct V_79 * V_165 ;
int V_2 ;
if ( ! V_39 )
return - V_166 ;
if ( ! V_39 -> V_50 ) {
F_8 ( L_87 ) ;
return - V_166 ;
}
V_2 = F_71 ( V_44 ) ;
if ( V_2 )
return V_2 ;
F_76 (map, obj) {
char V_10 [ V_162 ] ;
int V_163 ;
V_163 = snprintf ( V_10 , V_162 , L_88 , V_44 ,
F_77 ( V_165 ) ) ;
if ( V_163 < 0 )
return - V_34 ;
else if ( V_163 >= V_162 )
return - V_164 ;
V_2 = F_74 ( V_165 , V_10 ) ;
if ( V_2 )
return V_2 ;
}
F_78 (prog, obj) {
char V_10 [ V_162 ] ;
int V_163 ;
V_163 = snprintf ( V_10 , V_162 , L_88 , V_44 ,
V_18 -> V_25 ) ;
if ( V_163 < 0 )
return - V_34 ;
else if ( V_163 >= V_162 )
return - V_164 ;
V_2 = F_73 ( V_18 , V_10 ) ;
if ( V_2 )
return V_2 ;
}
return 0 ;
}
void F_62 ( struct V_38 * V_39 )
{
T_3 V_19 ;
if ( ! V_39 )
return;
if ( V_39 -> V_23 )
V_39 -> V_23 ( V_39 , V_39 -> V_24 ) ;
F_20 ( V_39 ) ;
F_65 ( V_39 ) ;
for ( V_19 = 0 ; V_19 < V_39 -> V_78 ; V_19 ++ ) {
F_9 ( & V_39 -> V_77 [ V_19 ] . V_32 ) ;
if ( V_39 -> V_77 [ V_19 ] . V_23 )
V_39 -> V_77 [ V_19 ] . V_23 ( & V_39 -> V_77 [ V_19 ] ,
V_39 -> V_77 [ V_19 ] . V_24 ) ;
V_39 -> V_77 [ V_19 ] . V_24 = NULL ;
V_39 -> V_77 [ V_19 ] . V_23 = NULL ;
}
F_9 ( & V_39 -> V_77 ) ;
V_39 -> V_78 = 0 ;
if ( V_39 -> V_42 && V_39 -> V_43 ) {
for ( V_19 = 0 ; V_19 < V_39 -> V_43 ; V_19 ++ )
F_10 ( & V_39 -> V_42 [ V_19 ] ) ;
}
F_9 ( & V_39 -> V_42 ) ;
F_79 ( & V_39 -> V_51 ) ;
free ( V_39 ) ;
}
struct V_38 *
F_80 ( struct V_38 * V_167 )
{
struct V_38 * V_168 ;
if ( ! V_167 )
V_168 = F_81 ( & V_52 ,
struct V_38 ,
V_51 ) ;
else
V_168 = F_82 ( V_167 , V_51 ) ;
if ( & V_168 -> V_51 == & V_52 )
return NULL ;
return V_168 ;
}
const char * F_83 ( struct V_38 * V_39 )
{
return V_39 ? V_39 -> V_44 : F_17 ( - V_34 ) ;
}
unsigned int F_84 ( struct V_38 * V_39 )
{
return V_39 ? V_39 -> V_76 : 0 ;
}
int F_85 ( struct V_38 * V_39 , void * V_24 ,
T_12 V_23 )
{
if ( V_39 -> V_24 && V_39 -> V_23 )
V_39 -> V_23 ( V_39 , V_39 -> V_24 ) ;
V_39 -> V_24 = V_24 ;
V_39 -> V_23 = V_23 ;
return 0 ;
}
void * F_86 ( struct V_38 * V_39 )
{
return V_39 ? V_39 -> V_24 : F_17 ( - V_34 ) ;
}
struct V_17 *
F_87 ( struct V_17 * V_167 , struct V_38 * V_39 )
{
T_3 V_30 ;
if ( ! V_39 -> V_42 )
return NULL ;
if ( V_167 == NULL )
return & V_39 -> V_42 [ 0 ] ;
if ( V_167 -> V_39 != V_39 ) {
F_8 ( L_89 ) ;
return NULL ;
}
V_30 = ( V_167 - V_39 -> V_42 ) + 1 ;
if ( V_30 >= V_39 -> V_43 )
return NULL ;
return & V_39 -> V_42 [ V_30 ] ;
}
int F_88 ( struct V_17 * V_18 , void * V_24 ,
T_13 V_23 )
{
if ( V_18 -> V_24 && V_18 -> V_23 )
V_18 -> V_23 ( V_18 , V_18 -> V_24 ) ;
V_18 -> V_24 = V_24 ;
V_18 -> V_23 = V_23 ;
return 0 ;
}
void * F_89 ( struct V_17 * V_18 )
{
return V_18 ? V_18 -> V_24 : F_17 ( - V_34 ) ;
}
const char * F_90 ( struct V_17 * V_18 , bool V_169 )
{
const char * V_170 ;
V_170 = V_18 -> V_25 ;
if ( V_169 ) {
V_170 = F_13 ( V_170 ) ;
if ( ! V_170 ) {
F_8 ( L_90 ) ;
return F_17 ( - V_37 ) ;
}
}
return V_170 ;
}
int F_91 ( struct V_17 * V_18 )
{
return F_92 ( V_18 , 0 ) ;
}
int F_93 ( struct V_17 * V_18 , int V_171 ,
T_11 V_172 )
{
int * V_173 ;
if ( V_171 <= 0 || ! V_172 )
return - V_34 ;
if ( V_18 -> V_20 . V_21 > 0 || V_18 -> V_20 . V_22 ) {
F_8 ( L_91 ) ;
return - V_34 ;
}
V_173 = malloc ( sizeof( int ) * V_171 ) ;
if ( ! V_173 ) {
F_8 ( L_92 ) ;
return - V_37 ;
}
memset ( V_173 , - 1 , sizeof( int ) * V_171 ) ;
V_18 -> V_20 . V_21 = V_171 ;
V_18 -> V_20 . V_22 = V_173 ;
V_18 -> V_145 = V_172 ;
return 0 ;
}
int F_92 ( struct V_17 * V_18 , int V_111 )
{
int V_48 ;
if ( V_111 >= V_18 -> V_20 . V_21 || V_111 < 0 ) {
F_8 ( L_93 ,
V_111 , V_18 -> V_25 , V_18 -> V_20 . V_21 ) ;
return - V_34 ;
}
V_48 = V_18 -> V_20 . V_22 [ V_111 ] ;
if ( V_48 < 0 ) {
F_8 ( L_94 ,
V_111 , V_18 -> V_25 ) ;
return - V_166 ;
}
return V_48 ;
}
void F_94 ( struct V_17 * V_18 , enum V_136 type )
{
V_18 -> type = type ;
}
static bool F_95 ( struct V_17 * V_18 ,
enum V_136 type )
{
return V_18 ? ( V_18 -> type == type ) : false ;
}
int F_96 ( struct V_79 * V_165 )
{
return V_165 ? V_165 -> V_48 : - V_34 ;
}
const struct V_83 * F_97 ( struct V_79 * V_165 )
{
return V_165 ? & V_165 -> V_93 : F_17 ( - V_34 ) ;
}
const char * F_77 ( struct V_79 * V_165 )
{
return V_165 ? V_165 -> V_32 : NULL ;
}
int F_98 ( struct V_79 * V_165 , void * V_24 ,
T_14 V_23 )
{
if ( ! V_165 )
return - V_34 ;
if ( V_165 -> V_24 ) {
if ( V_165 -> V_23 )
V_165 -> V_23 ( V_165 , V_165 -> V_24 ) ;
}
V_165 -> V_24 = V_24 ;
V_165 -> V_23 = V_23 ;
return 0 ;
}
void * F_99 ( struct V_79 * V_165 )
{
return V_165 ? V_165 -> V_24 : F_17 ( - V_34 ) ;
}
struct V_79 *
F_100 ( struct V_79 * V_167 , struct V_38 * V_39 )
{
T_3 V_30 ;
struct V_79 * V_174 , * V_175 ;
if ( ! V_39 || ! V_39 -> V_77 )
return NULL ;
V_174 = V_39 -> V_77 ;
V_175 = V_39 -> V_77 + V_39 -> V_78 ;
if ( V_167 == NULL )
return V_174 ;
if ( ( V_167 < V_174 ) || ( V_167 >= V_175 ) ) {
F_8 ( L_95 ,
V_176 ) ;
return NULL ;
}
V_30 = ( V_167 - V_39 -> V_77 ) + 1 ;
if ( V_30 >= V_39 -> V_78 )
return NULL ;
return & V_39 -> V_77 [ V_30 ] ;
}
struct V_79 *
F_101 ( struct V_38 * V_39 , const char * V_32 )
{
struct V_79 * V_177 ;
F_76 (pos, obj) {
if ( V_177 -> V_32 && ! strcmp ( V_177 -> V_32 , V_32 ) )
return V_177 ;
}
return NULL ;
}
struct V_79 *
F_102 ( struct V_38 * V_39 , T_3 V_82 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_39 -> V_78 ; V_19 ++ ) {
if ( V_39 -> V_77 [ V_19 ] . V_82 == V_82 )
return & V_39 -> V_77 [ V_19 ] ;
}
return F_17 ( - V_166 ) ;
}
long F_103 ( const void * V_178 )
{
if ( F_60 ( V_178 ) )
return F_104 ( V_178 ) ;
return 0 ;
}
