static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
char * V_4 = ( char * ) ( V_3 + V_2 -> V_5 ) ;
int V_6 , V_7 ;
V_6 = V_2 -> V_8 . V_7 ( V_4 , & V_2 -> V_8 , V_2 -> V_8 . V_9 ) ;
V_7 = V_6 ^ V_2 -> V_10 ;
return V_7 ;
}
static int F_2 ( struct V_1 * V_2 , void * V_3 )
{
char * * V_4 = ( char * * ) ( V_3 + V_2 -> V_5 ) ;
int V_6 , V_7 ;
int V_11 = strlen ( * V_4 ) + 1 ;
V_6 = V_2 -> V_8 . V_7 ( * V_4 , & V_2 -> V_8 , V_11 ) ;
V_7 = V_6 ^ V_2 -> V_10 ;
return V_7 ;
}
static int F_3 ( struct V_1 * V_2 , void * V_3 )
{
T_1 V_12 = * ( T_1 * ) ( V_3 + V_2 -> V_5 ) ;
int V_13 = V_12 & 0xffff ;
int V_14 = V_12 >> 16 ;
char * V_4 = ( char * ) ( V_3 + V_13 ) ;
int V_6 , V_7 ;
V_6 = V_2 -> V_8 . V_7 ( V_4 , & V_2 -> V_8 , V_14 ) ;
V_7 = V_6 ^ V_2 -> V_10 ;
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , void * V_3 )
{
return 0 ;
}
static int F_5 ( char * V_15 , struct V_8 * V_16 , int V_11 )
{
if ( strncmp ( V_15 , V_16 -> V_17 , V_11 ) == 0 )
return 1 ;
return 0 ;
}
static int F_6 ( char * V_15 , struct V_8 * V_16 , int V_11 )
{
if ( strncmp ( V_15 , V_16 -> V_17 , V_16 -> V_11 ) == 0 )
return 1 ;
return 0 ;
}
static int F_7 ( char * V_15 , struct V_8 * V_16 , int V_11 )
{
if ( F_8 ( V_15 , V_16 -> V_17 , V_11 ) )
return 1 ;
return 0 ;
}
static int F_9 ( char * V_15 , struct V_8 * V_16 , int V_11 )
{
int strlen = V_11 - 1 ;
if ( strlen >= V_16 -> V_11 &&
memcmp ( V_15 + strlen - V_16 -> V_11 , V_16 -> V_17 , V_16 -> V_11 ) == 0 )
return 1 ;
return 0 ;
}
enum V_18 F_10 ( char * V_19 , int V_11 , char * * V_20 , int * V_10 )
{
int type = V_21 ;
int V_22 ;
if ( V_19 [ 0 ] == '!' ) {
* V_10 = 1 ;
V_19 ++ ;
V_11 -- ;
} else
* V_10 = 0 ;
* V_20 = V_19 ;
for ( V_22 = 0 ; V_22 < V_11 ; V_22 ++ ) {
if ( V_19 [ V_22 ] == '*' ) {
if ( ! V_22 ) {
* V_20 = V_19 + 1 ;
type = V_23 ;
} else {
if ( type == V_23 )
type = V_24 ;
else
type = V_25 ;
V_19 [ V_22 ] = 0 ;
break;
}
}
}
return type ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_16 = & V_2 -> V_8 ;
char * V_20 ;
enum V_18 type = V_21 ;
int V_10 = 0 ;
if ( V_2 -> V_26 == V_27 ) {
type = F_10 ( V_16 -> V_17 , V_16 -> V_11 , & V_20 , & V_10 ) ;
V_16 -> V_11 = strlen ( V_20 ) ;
memmove ( V_16 -> V_17 , V_20 , V_16 -> V_11 + 1 ) ;
}
switch ( type ) {
case V_21 :
V_16 -> V_7 = F_5 ;
break;
case V_25 :
V_16 -> V_7 = F_6 ;
break;
case V_24 :
V_16 -> V_7 = F_7 ;
break;
case V_23 :
V_16 -> V_7 = F_9 ;
break;
}
V_2 -> V_10 ^= V_10 ;
}
static struct V_1 *
F_12 ( struct V_1 * V_2 , struct V_1 * V_28 ,
int V_29 , enum V_30 * V_31 )
{
if ( V_2 -> V_32 & V_33 )
* V_31 = V_34 ;
else
* V_31 = V_35 ;
V_2 = & V_28 [ V_2 -> V_32 & ~ V_33 ] ;
return V_2 ;
}
static int F_13 ( struct V_1 * V_28 ,
struct V_1 * V_36 ,
T_2 V_37 , void * V_38 )
{
struct V_1 * V_2 = V_36 ;
enum V_30 V_31 = V_39 ;
int V_40 = 0 ;
if ( ! V_28 )
return - V_41 ;
do {
int V_42 = 0 , V_43 ;
V_43 = V_37 ( V_31 , V_2 , & V_42 , V_38 ) ;
if ( V_43 == V_44 )
return V_42 ;
if ( V_43 == V_45 )
goto V_46;
switch ( V_31 ) {
case V_39 :
if ( V_2 -> V_47 != V_48 ) {
V_2 = & V_28 [ V_2 -> V_47 ] ;
continue;
}
goto V_46;
case V_35 :
V_2 = & V_28 [ V_2 -> V_49 ] ;
V_31 = V_39 ;
continue;
case V_34 :
V_46:
if ( V_2 == V_36 )
break;
V_2 = F_12 ( V_2 , V_28 ,
V_2 -> V_32 ,
& V_31 ) ;
continue;
}
V_40 = 1 ;
} while ( ! V_40 );
return 0 ;
}
static int F_14 ( struct V_1 * V_28 ,
struct V_1 * V_26 , void * V_50 )
{
struct V_1 * V_2 ;
int V_7 = 0 ;
int type ;
int V_22 ;
type = V_26 -> V_26 == V_51 ;
for ( V_22 = 0 ; V_22 < V_26 -> V_52 ; V_22 ++ ) {
V_2 = & V_28 [ V_26 -> V_53 [ V_22 ] ] ;
if ( ! F_15 ( ! V_2 -> V_54 ) )
V_7 = V_2 -> V_54 ( V_2 , V_50 ) ;
if ( ! ! V_7 == type )
return V_7 ;
}
return V_7 ;
}
static int F_16 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
struct V_55 * V_56 = V_38 ;
* V_42 = 0 ;
switch ( V_31 ) {
case V_39 :
if ( V_2 -> V_47 != V_48 ) {
if ( ! V_2 -> V_53 )
return V_57 ;
V_56 -> V_7 = F_14 ( V_56 -> V_28 , V_2 , V_56 -> V_50 ) ;
} else {
if ( ! F_15 ( ! V_2 -> V_54 ) )
V_56 -> V_7 = V_2 -> V_54 ( V_2 , V_56 -> V_50 ) ;
}
return V_45 ;
case V_35 :
if ( ! ! V_56 -> V_7 == ( V_2 -> V_26 == V_51 ) )
return V_45 ;
break;
case V_34 :
break;
}
return V_57 ;
}
int F_17 ( struct V_58 * V_59 , void * V_50 )
{
struct V_1 * V_28 ;
struct V_1 * V_36 ;
struct V_55 V_38 = {
. V_7 = - 1 ,
. V_50 = V_50 ,
} ;
int V_60 , V_43 ;
if ( ! V_59 )
return 1 ;
V_60 = V_59 -> V_60 ;
if ( ! V_60 )
return 1 ;
V_36 = F_18 ( V_59 -> V_36 ) ;
if ( ! V_36 )
return 1 ;
V_38 . V_28 = V_28 = F_18 ( V_59 -> V_28 ) ;
V_43 = F_13 ( V_28 , V_36 , F_16 , & V_38 ) ;
F_19 ( V_43 ) ;
return V_38 . V_7 ;
}
static void F_20 ( struct V_61 * V_62 , int V_42 , int V_63 )
{
V_62 -> V_64 = V_42 ;
V_62 -> V_65 = V_63 ;
}
static void F_21 ( struct V_58 * V_59 )
{
if ( ! V_59 )
return;
F_22 ( V_59 -> V_66 ) ;
V_59 -> V_66 = NULL ;
}
static int F_23 ( struct V_58 * V_59 ,
char * V_66 )
{
F_22 ( V_59 -> V_66 ) ;
V_59 -> V_66 = F_24 ( V_66 , V_67 ) ;
if ( ! V_59 -> V_66 )
return - V_68 ;
return 0 ;
}
static int F_25 ( struct V_58 * V_59 ,
char * string )
{
int V_69 ;
char * V_70 ;
F_26 ( ! V_59 -> V_66 ) ;
V_69 = strlen ( V_59 -> V_66 ) + strlen ( string ) + 1 ;
V_70 = F_27 ( V_69 , V_67 ) ;
if ( ! V_70 )
return - V_68 ;
strcpy ( V_70 , V_59 -> V_66 ) ;
strcat ( V_70 , string ) ;
F_22 ( V_59 -> V_66 ) ;
V_59 -> V_66 = V_70 ;
return 0 ;
}
static void F_28 ( struct V_61 * V_62 ,
struct V_58 * V_59 )
{
int V_63 = V_62 -> V_65 ;
char * V_71 , * V_72 ;
V_71 = ( char * ) F_29 ( V_73 ) ;
if ( ! V_71 )
return;
F_25 ( V_59 , L_1 ) ;
memset ( V_71 , ' ' , V_74 ) ;
if ( V_63 > V_74 - 128 )
V_63 = 0 ;
V_71 [ V_63 ] = '^' ;
V_72 = & V_71 [ V_63 ] + 1 ;
sprintf ( V_72 , L_2 , V_75 [ V_62 -> V_64 ] ) ;
F_25 ( V_59 , V_71 ) ;
F_30 ( ( unsigned long ) V_71 ) ;
}
void F_31 ( struct V_76 * V_77 , struct V_78 * V_79 )
{
struct V_58 * V_59 ;
F_32 ( & V_80 ) ;
V_59 = V_77 -> V_59 ;
if ( V_59 && V_59 -> V_66 )
F_33 ( V_79 , L_3 , V_59 -> V_66 ) ;
else
F_33 ( V_79 , L_4 ) ;
F_34 ( & V_80 ) ;
}
void F_35 ( struct V_81 * system ,
struct V_78 * V_79 )
{
struct V_58 * V_59 ;
F_32 ( & V_80 ) ;
V_59 = system -> V_59 ;
if ( V_59 && V_59 -> V_66 )
F_33 ( V_79 , L_3 , V_59 -> V_66 ) ;
else
F_33 ( V_79 , V_82 L_1 ) ;
F_34 ( & V_80 ) ;
}
static struct V_83 *
F_36 ( struct V_84 * V_85 , char * V_86 )
{
struct V_83 * V_87 ;
F_37 (field, head, link) {
if ( ! strcmp ( V_87 -> V_86 , V_86 ) )
return V_87 ;
}
return NULL ;
}
static struct V_83 *
F_38 ( struct V_76 * V_77 , char * V_86 )
{
struct V_83 * V_87 ;
struct V_84 * V_85 ;
V_87 = F_36 ( & V_88 , V_86 ) ;
if ( V_87 )
return V_87 ;
V_85 = F_39 ( V_77 ) ;
return F_36 ( V_85 , V_86 ) ;
}
static int F_40 ( struct V_89 * V_90 , int V_60 )
{
V_90 -> V_28 = F_41 ( sizeof( * V_90 -> V_28 ) * ( V_60 + 1 ) , V_67 ) ;
if ( ! V_90 -> V_28 )
return - V_68 ;
V_90 -> V_29 = V_60 ;
return 0 ;
}
static void F_42 ( struct V_89 * V_90 )
{
F_22 ( V_90 -> V_28 ) ;
V_90 -> V_29 = 0 ;
}
static int F_43 ( struct V_89 * V_90 ,
struct V_1 * V_2 )
{
int V_29 = V_90 -> V_29 ;
if ( F_19 ( V_29 == 0 ) )
return - V_91 ;
V_90 -> V_28 [ -- V_29 ] = V_2 ;
V_90 -> V_29 = V_29 ;
return 0 ;
}
static struct V_1 *
F_44 ( struct V_89 * V_90 )
{
struct V_1 * V_2 ;
int V_29 = V_90 -> V_29 ;
V_2 = V_90 -> V_28 [ V_29 ++ ] ;
if ( ! V_2 )
return NULL ;
V_90 -> V_29 = V_29 ;
return V_2 ;
}
static int F_45 ( struct V_58 * V_59 ,
int V_92 ,
struct V_89 * V_90 ,
struct V_1 * V_93 )
{
struct V_1 * V_94 = & V_59 -> V_28 [ V_92 ] ;
struct V_1 * V_47 ;
struct V_1 * V_49 ;
* V_94 = * V_93 ;
V_94 -> V_29 = V_92 ;
if ( V_94 -> V_26 == V_51 || V_94 -> V_26 == V_95 ) {
V_49 = F_44 ( V_90 ) ;
V_47 = F_44 ( V_90 ) ;
if ( ! V_47 || ! V_49 )
return - V_41 ;
if ( V_47 -> V_29 & V_96 &&
( V_47 -> V_26 == V_94 -> V_26 ||
V_47 -> V_47 == V_48 ) &&
V_49 -> V_29 & V_96 &&
( V_49 -> V_26 == V_94 -> V_26 ||
V_49 -> V_47 == V_48 ) )
V_94 -> V_29 |= V_96 ;
V_94 -> V_47 = V_47 -> V_29 & ~ V_96 ;
V_94 -> V_49 = V_49 -> V_29 & ~ V_96 ;
V_47 -> V_32 = V_94 -> V_29 & ~ V_96 ;
V_49 -> V_32 = V_94 -> V_29 | V_33 ;
} else {
V_94 -> V_47 = V_48 ;
V_94 -> V_29 |= V_96 ;
}
return F_43 ( V_90 , V_94 ) ;
}
static void F_46 ( struct V_58 * V_59 )
{
if ( V_59 -> V_28 ) {
F_22 ( V_59 -> V_28 ) ;
V_59 -> V_28 = NULL ;
}
V_59 -> V_97 = 0 ;
V_59 -> V_60 = 0 ;
}
static void F_47 ( struct V_76 * V_77 )
{
V_77 -> V_98 &= ~ V_99 ;
}
static void F_48 ( struct V_58 * V_59 )
{
if ( ! V_59 )
return;
F_46 ( V_59 ) ;
F_22 ( V_59 -> V_66 ) ;
F_22 ( V_59 ) ;
}
void F_49 ( struct V_76 * V_77 )
{
F_48 ( V_77 -> V_59 ) ;
V_77 -> V_59 = NULL ;
}
static struct V_58 * F_50 ( void )
{
struct V_58 * V_59 ;
V_59 = F_41 ( sizeof( * V_59 ) , V_67 ) ;
return V_59 ;
}
static int F_51 ( struct V_58 * V_59 , int V_60 )
{
struct V_1 * V_2 ;
int V_22 ;
if ( V_59 -> V_28 )
F_46 ( V_59 ) ;
V_59 -> V_28 =
F_41 ( sizeof( * V_59 -> V_28 ) * V_60 , V_67 ) ;
if ( ! V_59 -> V_28 )
return - V_68 ;
V_59 -> V_97 = V_60 ;
V_59 -> V_60 = 0 ;
for ( V_22 = 0 ; V_22 < V_60 ; V_22 ++ ) {
V_2 = & V_59 -> V_28 [ V_22 ] ;
V_2 -> V_54 = F_4 ;
}
return 0 ;
}
static void F_52 ( struct V_81 * system )
{
struct V_76 * V_77 ;
F_37 (call, &ftrace_events, list) {
if ( strcmp ( V_77 -> V_100 -> system , system -> V_86 ) != 0 )
continue;
F_47 ( V_77 ) ;
F_21 ( V_77 -> V_59 ) ;
}
}
static void F_53 ( struct V_81 * system )
{
struct V_76 * V_77 ;
F_37 (call, &ftrace_events, list) {
if ( strcmp ( V_77 -> V_100 -> system , system -> V_86 ) != 0 )
continue;
F_48 ( V_77 -> V_59 ) ;
V_77 -> V_59 = NULL ;
}
}
static int F_54 ( struct V_61 * V_62 ,
struct V_58 * V_59 ,
struct V_1 * V_2 ,
struct V_89 * V_90 )
{
int V_42 ;
if ( F_19 ( V_59 -> V_60 == V_59 -> V_97 ) ) {
F_20 ( V_62 , V_101 , 0 ) ;
return - V_91 ;
}
V_42 = F_45 ( V_59 , V_59 -> V_60 , V_90 , V_2 ) ;
if ( V_42 )
return V_42 ;
V_59 -> V_60 ++ ;
return 0 ;
}
int F_55 ( const char * type )
{
if ( strstr ( type , L_5 ) && strstr ( type , L_6 ) )
return V_102 ;
if ( strchr ( type , '[' ) && strstr ( type , L_6 ) )
return V_103 ;
return V_104 ;
}
static bool F_56 ( struct V_83 * V_87 )
{
return V_87 -> V_105 == V_102 ||
V_87 -> V_105 == V_103 ||
V_87 -> V_105 == V_106 ;
}
static int F_57 ( struct V_83 * V_87 , int V_26 )
{
if ( F_56 ( V_87 ) &&
( V_26 != V_107 && V_26 != V_108 && V_26 != V_27 ) )
return 0 ;
if ( ! F_56 ( V_87 ) && V_26 == V_27 )
return 0 ;
return 1 ;
}
static T_3 F_58 ( int V_26 , int V_109 ,
int V_110 )
{
T_3 V_54 = NULL ;
switch ( V_109 ) {
case 8 :
if ( V_26 == V_107 || V_26 == V_108 )
V_54 = V_111 ;
else if ( V_110 )
V_54 = V_112 ;
else
V_54 = V_113 ;
break;
case 4 :
if ( V_26 == V_107 || V_26 == V_108 )
V_54 = V_114 ;
else if ( V_110 )
V_54 = V_115 ;
else
V_54 = V_116 ;
break;
case 2 :
if ( V_26 == V_107 || V_26 == V_108 )
V_54 = V_117 ;
else if ( V_110 )
V_54 = V_118 ;
else
V_54 = V_119 ;
break;
case 1 :
if ( V_26 == V_107 || V_26 == V_108 )
V_54 = V_120 ;
else if ( V_110 )
V_54 = V_121 ;
else
V_54 = V_122 ;
break;
}
return V_54 ;
}
static int F_59 ( struct V_61 * V_62 ,
struct V_83 * V_87 ,
struct V_1 * V_2 )
{
T_3 V_54 = F_4 ;
unsigned long long V_52 ;
int V_43 ;
V_2 -> V_5 = V_87 -> V_5 ;
if ( ! F_57 ( V_87 , V_2 -> V_26 ) ) {
F_20 ( V_62 , V_123 , 0 ) ;
return - V_41 ;
}
if ( F_56 ( V_87 ) ) {
F_11 ( V_2 ) ;
if ( V_87 -> V_105 == V_103 ) {
V_54 = F_1 ;
V_2 -> V_8 . V_9 = V_87 -> V_124 ;
} else if ( V_87 -> V_105 == V_102 )
V_54 = F_3 ;
else
V_54 = F_2 ;
} else {
if ( V_87 -> V_125 )
V_43 = F_60 ( V_2 -> V_8 . V_17 , 0 , & V_52 ) ;
else
V_43 = F_61 ( V_2 -> V_8 . V_17 , 0 , & V_52 ) ;
if ( V_43 ) {
F_20 ( V_62 , V_126 , 0 ) ;
return - V_41 ;
}
V_2 -> V_52 = V_52 ;
V_54 = F_58 ( V_2 -> V_26 , V_87 -> V_124 ,
V_87 -> V_125 ) ;
if ( ! V_54 ) {
F_20 ( V_62 , V_127 , 0 ) ;
return - V_41 ;
}
}
if ( V_2 -> V_26 == V_108 )
V_2 -> V_10 = 1 ;
V_2 -> V_54 = V_54 ;
return 0 ;
}
static void F_62 ( struct V_61 * V_62 ,
struct V_128 * V_53 ,
char * V_129 )
{
memset ( V_62 , '\0' , sizeof( * V_62 ) ) ;
V_62 -> V_130 . string = V_129 ;
V_62 -> V_130 . V_131 = strlen ( V_129 ) ;
V_62 -> V_53 = V_53 ;
F_63 ( & V_62 -> V_132 ) ;
F_63 ( & V_62 -> V_133 ) ;
}
static char F_64 ( struct V_61 * V_62 )
{
V_62 -> V_130 . V_131 -- ;
return V_62 -> V_130 . string [ V_62 -> V_130 . V_134 ++ ] ;
}
static char F_65 ( struct V_61 * V_62 )
{
if ( V_62 -> V_130 . V_134 == strlen ( V_62 -> V_130 . string ) )
return 0 ;
return V_62 -> V_130 . string [ V_62 -> V_130 . V_134 ] ;
}
static void F_66 ( struct V_61 * V_62 )
{
V_62 -> V_130 . V_131 -- ;
V_62 -> V_130 . V_134 ++ ;
}
static inline int F_67 ( struct V_61 * V_62 ,
int V_135 , int V_136 )
{
return V_62 -> V_53 [ V_135 ] . V_137 < V_62 -> V_53 [ V_136 ] . V_137 ;
}
static inline int F_68 ( struct V_61 * V_62 , char V_138 )
{
int V_22 ;
for ( V_22 = 0 ; strcmp ( V_62 -> V_53 [ V_22 ] . string , L_7 ) ; V_22 ++ ) {
if ( V_62 -> V_53 [ V_22 ] . string [ 0 ] == V_138 )
return 1 ;
}
return 0 ;
}
static int F_69 ( struct V_61 * V_62 , char V_139 )
{
char V_140 = F_65 ( V_62 ) ;
char V_141 [ 3 ] ;
int V_22 ;
V_141 [ 0 ] = V_139 ;
V_141 [ 1 ] = V_140 ;
V_141 [ 2 ] = '\0' ;
for ( V_22 = 0 ; strcmp ( V_62 -> V_53 [ V_22 ] . string , L_7 ) ; V_22 ++ ) {
if ( ! strcmp ( V_141 , V_62 -> V_53 [ V_22 ] . string ) ) {
F_66 ( V_62 ) ;
return V_62 -> V_53 [ V_22 ] . V_142 ;
}
}
V_141 [ 1 ] = '\0' ;
for ( V_22 = 0 ; strcmp ( V_62 -> V_53 [ V_22 ] . string , L_7 ) ; V_22 ++ ) {
if ( ! strcmp ( V_141 , V_62 -> V_53 [ V_22 ] . string ) )
return V_62 -> V_53 [ V_22 ] . V_142 ;
}
return V_143 ;
}
static inline void F_70 ( struct V_61 * V_62 )
{
memset ( V_62 -> V_144 . string , '\0' , V_145 ) ;
V_62 -> V_144 . V_134 = 0 ;
}
static inline int F_71 ( struct V_61 * V_62 , char V_138 )
{
if ( V_62 -> V_144 . V_134 == V_145 - 1 )
return - V_41 ;
V_62 -> V_144 . string [ V_62 -> V_144 . V_134 ++ ] = V_138 ;
return 0 ;
}
static int F_72 ( struct V_61 * V_62 , int V_26 )
{
struct V_146 * V_146 ;
V_146 = F_27 ( sizeof( * V_146 ) , V_67 ) ;
if ( ! V_146 )
return - V_68 ;
V_146 -> V_26 = V_26 ;
F_73 ( & V_146 -> V_147 , & V_62 -> V_132 ) ;
return 0 ;
}
static int F_74 ( struct V_61 * V_62 )
{
return F_75 ( & V_62 -> V_132 ) ;
}
static int F_76 ( struct V_61 * V_62 )
{
struct V_146 * V_146 ;
if ( F_74 ( V_62 ) )
return V_143 ;
V_146 = F_77 ( & V_62 -> V_132 , struct V_146 , V_147 ) ;
return V_146 -> V_26 ;
}
static int F_78 ( struct V_61 * V_62 )
{
struct V_146 * V_146 ;
int V_26 ;
if ( F_74 ( V_62 ) )
return V_143 ;
V_146 = F_77 ( & V_62 -> V_132 , struct V_146 , V_147 ) ;
V_26 = V_146 -> V_26 ;
F_79 ( & V_146 -> V_147 ) ;
F_22 ( V_146 ) ;
return V_26 ;
}
static void F_80 ( struct V_61 * V_62 )
{
while ( ! F_74 ( V_62 ) )
F_78 ( V_62 ) ;
}
static char * F_81 ( struct V_61 * V_62 )
{
return V_62 -> V_144 . string ;
}
static int F_82 ( struct V_61 * V_62 , char * V_144 )
{
struct V_148 * V_149 ;
V_149 = F_27 ( sizeof( * V_149 ) , V_67 ) ;
if ( ! V_149 )
return - V_68 ;
V_149 -> V_26 = V_143 ;
V_149 -> V_144 = F_24 ( V_144 , V_67 ) ;
if ( ! V_149 -> V_144 ) {
F_22 ( V_149 ) ;
return - V_68 ;
}
F_83 ( & V_149 -> V_147 , & V_62 -> V_133 ) ;
return 0 ;
}
static int F_84 ( struct V_61 * V_62 , int V_26 )
{
struct V_148 * V_149 ;
V_149 = F_27 ( sizeof( * V_149 ) , V_67 ) ;
if ( ! V_149 )
return - V_68 ;
V_149 -> V_26 = V_26 ;
V_149 -> V_144 = NULL ;
F_83 ( & V_149 -> V_147 , & V_62 -> V_133 ) ;
return 0 ;
}
static void F_85 ( struct V_61 * V_62 )
{
struct V_148 * V_149 ;
while ( ! F_75 ( & V_62 -> V_133 ) ) {
V_149 = F_77 ( & V_62 -> V_133 , struct V_148 , V_147 ) ;
F_79 ( & V_149 -> V_147 ) ;
F_22 ( V_149 -> V_144 ) ;
F_22 ( V_149 ) ;
}
}
static int F_86 ( struct V_61 * V_62 )
{
int V_150 = 0 ;
int V_26 , V_151 ;
char V_152 ;
while ( ( V_152 = F_64 ( V_62 ) ) ) {
if ( V_152 == '"' ) {
V_150 ^= 1 ;
continue;
}
if ( V_150 )
goto V_153;
if ( isspace ( V_152 ) )
continue;
if ( F_68 ( V_62 , V_152 ) ) {
V_26 = F_69 ( V_62 , V_152 ) ;
if ( V_26 == V_143 ) {
F_20 ( V_62 , V_127 , 0 ) ;
return - V_41 ;
}
if ( strlen ( F_81 ( V_62 ) ) ) {
F_82 ( V_62 , F_81 ( V_62 ) ) ;
F_70 ( V_62 ) ;
}
while ( ! F_74 ( V_62 ) ) {
V_151 = F_76 ( V_62 ) ;
if ( ! F_67 ( V_62 , V_151 , V_26 ) ) {
V_151 = F_78 ( V_62 ) ;
F_84 ( V_62 , V_151 ) ;
continue;
}
break;
}
F_72 ( V_62 , V_26 ) ;
continue;
}
if ( V_152 == '(' ) {
F_72 ( V_62 , V_154 ) ;
continue;
}
if ( V_152 == ')' ) {
if ( strlen ( F_81 ( V_62 ) ) ) {
F_82 ( V_62 , F_81 ( V_62 ) ) ;
F_70 ( V_62 ) ;
}
V_151 = F_78 ( V_62 ) ;
while ( V_151 != V_143 ) {
if ( V_151 == V_154 )
break;
F_84 ( V_62 , V_151 ) ;
V_151 = F_78 ( V_62 ) ;
}
if ( V_151 == V_143 ) {
F_20 ( V_62 , V_155 , 0 ) ;
return - V_41 ;
}
continue;
}
V_153:
if ( F_71 ( V_62 , V_152 ) ) {
F_20 ( V_62 , V_156 , 0 ) ;
return - V_41 ;
}
}
if ( strlen ( F_81 ( V_62 ) ) )
F_82 ( V_62 , F_81 ( V_62 ) ) ;
while ( ! F_74 ( V_62 ) ) {
V_151 = F_78 ( V_62 ) ;
if ( V_151 == V_143 )
break;
if ( V_151 == V_154 ) {
F_20 ( V_62 , V_155 , 0 ) ;
return - V_41 ;
}
F_84 ( V_62 , V_151 ) ;
}
return 0 ;
}
static struct V_1 * F_87 ( struct V_61 * V_62 ,
struct V_76 * V_77 ,
int V_26 , char * V_157 , char * V_158 )
{
struct V_83 * V_87 ;
static struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_26 = V_26 ;
if ( V_26 == V_95 || V_26 == V_51 )
return & V_2 ;
if ( ! V_157 || ! V_158 ) {
F_20 ( V_62 , V_159 , 0 ) ;
return NULL ;
}
V_87 = F_38 ( V_77 , V_157 ) ;
if ( ! V_87 ) {
F_20 ( V_62 , V_160 , 0 ) ;
return NULL ;
}
strcpy ( V_2 . V_8 . V_17 , V_158 ) ;
V_2 . V_8 . V_11 = strlen ( V_2 . V_8 . V_17 ) ;
#ifdef F_88
V_2 . V_87 = V_87 ;
#endif
return F_59 ( V_62 , V_87 , & V_2 ) ? NULL : & V_2 ;
}
static int F_89 ( struct V_61 * V_62 )
{
int V_161 = 0 , V_162 = 0 ;
struct V_148 * V_149 ;
F_37 (elt, &ps->postfix, list) {
if ( V_149 -> V_26 == V_143 )
continue;
if ( V_149 -> V_26 == V_95 || V_149 -> V_26 == V_51 ) {
V_162 ++ ;
continue;
}
V_161 ++ ;
}
if ( ! V_161 || V_162 >= V_161 ) {
F_20 ( V_62 , V_163 , 0 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_90 ( struct V_61 * V_62 )
{
struct V_148 * V_149 ;
int V_60 = 0 ;
F_37 (elt, &ps->postfix, list) {
if ( V_149 -> V_26 == V_143 )
continue;
V_60 ++ ;
}
return V_60 ;
}
static int F_91 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
struct V_164 * V_56 = V_38 ;
if ( F_19 ( V_56 -> V_165 ++ > V_56 -> V_166 ) ) {
* V_42 = - V_41 ;
return V_44 ;
}
return V_57 ;
}
static int F_92 ( struct V_58 * V_59 ,
struct V_1 * V_36 )
{
struct V_164 V_38 = {
. V_166 = 3 * V_59 -> V_60 ,
. V_165 = 0 ,
} ;
return F_13 ( V_59 -> V_28 , V_36 ,
F_91 , & V_38 ) ;
}
static int F_93 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
int * V_165 = V_38 ;
if ( ( V_31 == V_39 ) &&
( V_2 -> V_47 == V_48 ) )
( * V_165 ) ++ ;
return V_57 ;
}
static int F_94 ( struct V_1 * V_28 , struct V_1 * V_36 )
{
int V_165 = 0 , V_43 ;
V_43 = F_13 ( V_28 , V_36 , F_93 , & V_165 ) ;
F_19 ( V_43 ) ;
return V_165 ;
}
static int F_95 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
struct V_167 * V_56 = V_38 ;
struct V_1 * V_36 = V_56 -> V_36 ;
if ( V_31 != V_39 )
return V_57 ;
if ( V_2 -> V_47 != V_48 )
return V_57 ;
if ( F_19 ( V_56 -> V_165 == V_56 -> V_168 ) ) {
* V_42 = - V_41 ;
return V_44 ;
}
V_2 -> V_29 &= ~ V_96 ;
V_36 -> V_53 [ V_56 -> V_165 ++ ] = V_2 -> V_29 ;
return V_57 ;
}
static int F_96 ( struct V_1 * V_28 , struct V_1 * V_36 )
{
struct V_167 V_38 = {
. V_36 = V_36 ,
. V_165 = 0 ,
} ;
int V_168 ;
V_36 -> V_29 &= ~ V_96 ;
if ( V_36 -> V_47 == V_48 )
return 0 ;
V_168 = F_94 ( V_28 , & V_28 [ V_36 -> V_47 ] ) ;
V_168 += F_94 ( V_28 , & V_28 [ V_36 -> V_49 ] ) ;
V_36 -> V_53 = F_41 ( sizeof( * V_36 -> V_53 ) * V_168 , V_67 ) ;
if ( ! V_36 -> V_53 )
return - V_68 ;
V_36 -> V_52 = V_168 ;
V_38 . V_168 = V_168 ;
return F_13 ( V_28 , V_36 , F_95 , & V_38 ) ;
}
static int F_97 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
struct V_1 * V_28 = V_38 ;
if ( V_31 != V_39 )
return V_57 ;
if ( ! ( V_2 -> V_29 & V_96 ) )
return V_57 ;
* V_42 = F_96 ( V_28 , V_2 ) ;
if ( * V_42 )
return V_44 ;
return V_45 ;
}
static int F_98 ( struct V_58 * V_59 ,
struct V_1 * V_36 )
{
return F_13 ( V_59 -> V_28 , V_36 , F_97 ,
V_59 -> V_28 ) ;
}
static int F_99 ( struct V_76 * V_77 ,
struct V_58 * V_59 ,
struct V_61 * V_62 ,
char * V_66 ,
bool V_169 )
{
char * V_157 = NULL , * V_158 = NULL ;
struct V_1 * V_2 ;
struct V_1 * V_36 ;
struct V_148 * V_149 ;
struct V_89 V_90 = { } ;
int V_42 ;
int V_60 = 0 ;
V_60 = F_90 ( V_62 ) ;
if ( V_60 >= V_170 ) {
F_20 ( V_62 , V_101 , 0 ) ;
return - V_91 ;
}
V_42 = F_89 ( V_62 ) ;
if ( V_42 )
return V_42 ;
if ( ! V_169 ) {
V_42 = F_40 ( & V_90 , V_60 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_51 ( V_59 , V_60 ) ;
if ( V_42 )
goto V_171;
}
V_60 = 0 ;
F_37 (elt, &ps->postfix, list) {
if ( V_149 -> V_26 == V_143 ) {
if ( ! V_157 )
V_157 = V_149 -> V_144 ;
else if ( ! V_158 )
V_158 = V_149 -> V_144 ;
else {
F_20 ( V_62 , V_172 , 0 ) ;
V_42 = - V_41 ;
goto V_171;
}
continue;
}
if ( F_19 ( V_60 ++ == V_170 ) ) {
F_20 ( V_62 , V_101 , 0 ) ;
V_42 = - V_91 ;
goto V_171;
}
V_2 = F_87 ( V_62 , V_77 , V_149 -> V_26 , V_157 , V_158 ) ;
if ( ! V_2 ) {
V_42 = - V_41 ;
goto V_171;
}
if ( ! V_169 ) {
V_42 = F_54 ( V_62 , V_59 , V_2 , & V_90 ) ;
if ( V_42 )
goto V_171;
}
V_157 = V_158 = NULL ;
}
if ( ! V_169 ) {
V_2 = F_44 ( & V_90 ) ;
if ( ! V_2 )
return - V_41 ;
V_36 = V_2 ;
V_2 = F_44 ( & V_90 ) ;
if ( F_19 ( V_2 ) ) {
V_42 = - V_41 ;
V_59 -> V_36 = NULL ;
goto V_171;
}
V_42 = F_92 ( V_59 , V_36 ) ;
if ( V_42 )
goto V_171;
V_42 = F_98 ( V_59 , V_36 ) ;
if ( V_42 )
goto V_171;
F_100 () ;
V_59 -> V_36 = V_36 ;
}
V_42 = 0 ;
V_171:
F_42 ( & V_90 ) ;
return V_42 ;
}
static int F_101 ( struct V_81 * system ,
struct V_61 * V_62 ,
char * V_66 )
{
struct V_76 * V_77 ;
struct V_173 * V_174 ;
struct V_173 * V_175 ;
F_102 ( V_173 ) ;
bool V_171 = true ;
int V_42 ;
F_37 (call, &ftrace_events, list) {
if ( strcmp ( V_77 -> V_100 -> system , system -> V_86 ) != 0 )
continue;
V_42 = F_99 ( V_77 , NULL , V_62 , V_66 , true ) ;
if ( V_42 )
V_77 -> V_98 |= V_176 ;
else
V_77 -> V_98 &= ~ V_176 ;
}
F_37 (call, &ftrace_events, list) {
struct V_58 * V_59 ;
if ( strcmp ( V_77 -> V_100 -> system , system -> V_86 ) != 0 )
continue;
if ( V_77 -> V_98 & V_176 )
continue;
V_174 = F_41 ( sizeof( * V_174 ) , V_67 ) ;
if ( ! V_174 )
goto V_177;
F_83 ( & V_174 -> V_147 , & V_173 ) ;
V_174 -> V_59 = F_50 () ;
if ( ! V_174 -> V_59 )
goto V_177;
V_59 = V_174 -> V_59 ;
V_42 = F_23 ( V_59 , V_66 ) ;
if ( V_42 )
goto V_177;
V_42 = F_99 ( V_77 , V_59 , V_62 , V_66 , false ) ;
if ( V_42 ) {
F_47 ( V_77 ) ;
F_20 ( V_62 , V_178 , 0 ) ;
F_28 ( V_62 , V_59 ) ;
} else
V_77 -> V_98 |= V_99 ;
V_59 = V_77 -> V_59 ;
F_103 ( V_77 -> V_59 , V_174 -> V_59 ) ;
V_174 -> V_59 = V_59 ;
V_171 = false ;
}
if ( V_171 )
goto V_171;
F_104 () ;
F_105 (filter_item, tmp, &filter_list, list) {
F_48 ( V_174 -> V_59 ) ;
F_79 ( & V_174 -> V_147 ) ;
F_22 ( V_174 ) ;
}
return 0 ;
V_171:
F_105 (filter_item, tmp, &filter_list, list) {
F_79 ( & V_174 -> V_147 ) ;
F_22 ( V_174 ) ;
}
F_20 ( V_62 , V_178 , 0 ) ;
return - V_41 ;
V_177:
if ( ! V_171 )
F_104 () ;
F_105 (filter_item, tmp, &filter_list, list) {
F_48 ( V_174 -> V_59 ) ;
F_79 ( & V_174 -> V_147 ) ;
F_22 ( V_174 ) ;
}
return - V_68 ;
}
static int F_106 ( char * V_179 , bool V_180 ,
struct V_61 * * V_181 ,
struct V_58 * * V_182 )
{
struct V_58 * V_59 ;
struct V_61 * V_62 = NULL ;
int V_42 = 0 ;
F_15 ( * V_181 || * V_182 ) ;
V_59 = F_50 () ;
if ( V_59 && V_180 )
V_42 = F_23 ( V_59 , V_179 ) ;
V_62 = F_41 ( sizeof( * V_62 ) , V_67 ) ;
if ( ! V_59 || ! V_62 || V_42 ) {
F_22 ( V_62 ) ;
F_48 ( V_59 ) ;
return - V_68 ;
}
* V_182 = V_59 ;
* V_181 = V_62 ;
F_62 ( V_62 , V_183 , V_179 ) ;
V_42 = F_86 ( V_62 ) ;
if ( V_42 && V_180 )
F_28 ( V_62 , V_59 ) ;
return V_42 ;
}
static void F_107 ( struct V_61 * V_62 )
{
if ( V_62 ) {
F_80 ( V_62 ) ;
F_85 ( V_62 ) ;
F_22 ( V_62 ) ;
}
}
static int F_108 ( struct V_76 * V_77 ,
char * V_179 , bool V_180 ,
struct V_58 * * V_182 )
{
struct V_58 * V_59 = NULL ;
struct V_61 * V_62 = NULL ;
int V_42 ;
V_42 = F_106 ( V_179 , V_180 , & V_62 , & V_59 ) ;
if ( ! V_42 ) {
V_42 = F_99 ( V_77 , V_59 , V_62 , V_179 , false ) ;
if ( V_42 && V_180 )
F_28 ( V_62 , V_59 ) ;
}
F_107 ( V_62 ) ;
* V_182 = V_59 ;
return V_42 ;
}
static int F_109 ( struct V_81 * system ,
char * V_179 , struct V_58 * * V_182 )
{
struct V_58 * V_59 = NULL ;
struct V_61 * V_62 = NULL ;
int V_42 ;
V_42 = F_106 ( V_179 , true , & V_62 , & V_59 ) ;
if ( ! V_42 ) {
V_42 = F_101 ( system , V_62 , V_179 ) ;
if ( ! V_42 ) {
F_22 ( V_59 -> V_66 ) ;
V_59 -> V_66 = NULL ;
} else {
F_28 ( V_62 , V_59 ) ;
}
}
F_107 ( V_62 ) ;
* V_182 = V_59 ;
return V_42 ;
}
int F_110 ( struct V_76 * V_77 , char * V_66 )
{
struct V_58 * V_59 ;
int V_42 = 0 ;
F_32 ( & V_80 ) ;
if ( ! strcmp ( F_111 ( V_66 ) , L_8 ) ) {
F_47 ( V_77 ) ;
V_59 = V_77 -> V_59 ;
if ( ! V_59 )
goto V_184;
F_112 ( V_77 -> V_59 , NULL ) ;
F_104 () ;
F_48 ( V_59 ) ;
goto V_184;
}
V_42 = F_108 ( V_77 , V_66 , true , & V_59 ) ;
if ( V_59 ) {
struct V_58 * V_175 = V_77 -> V_59 ;
if ( ! V_42 )
V_77 -> V_98 |= V_99 ;
else
F_47 ( V_77 ) ;
F_103 ( V_77 -> V_59 , V_59 ) ;
if ( V_175 ) {
F_104 () ;
F_48 ( V_175 ) ;
}
}
V_184:
F_34 ( & V_80 ) ;
return V_42 ;
}
int F_113 ( struct V_81 * system ,
char * V_66 )
{
struct V_58 * V_59 ;
int V_42 = 0 ;
F_32 ( & V_80 ) ;
if ( ! system -> V_185 ) {
V_42 = - V_186 ;
goto V_184;
}
if ( ! strcmp ( F_111 ( V_66 ) , L_8 ) ) {
F_52 ( system ) ;
F_21 ( system -> V_59 ) ;
V_59 = system -> V_59 ;
system -> V_59 = NULL ;
F_104 () ;
F_53 ( system ) ;
F_48 ( V_59 ) ;
goto V_184;
}
V_42 = F_109 ( system , V_66 , & V_59 ) ;
if ( V_59 ) {
F_48 ( system -> V_59 ) ;
system -> V_59 = V_59 ;
}
V_184:
F_34 ( & V_80 ) ;
return V_42 ;
}
void F_114 ( struct V_187 * V_3 )
{
struct V_58 * V_59 = V_3 -> V_59 ;
V_3 -> V_59 = NULL ;
F_48 ( V_59 ) ;
}
int F_115 ( struct V_187 * V_3 , int V_188 ,
char * V_179 )
{
int V_42 ;
struct V_58 * V_59 ;
struct V_76 * V_77 ;
F_32 ( & V_80 ) ;
V_77 = V_3 -> V_189 ;
V_42 = - V_41 ;
if ( ! V_77 )
goto V_184;
V_42 = - V_190 ;
if ( V_3 -> V_59 )
goto V_184;
V_42 = F_108 ( V_77 , V_179 , false , & V_59 ) ;
if ( ! V_42 )
V_3 -> V_59 = V_59 ;
else
F_48 ( V_59 ) ;
V_184:
F_34 ( & V_80 ) ;
return V_42 ;
}
static int F_116 ( struct V_1 * V_2 , void * V_3 )
{
struct V_83 * V_87 = V_2 -> V_87 ;
V_191 = 1 ;
F_117 ( V_192 L_9 , V_87 -> V_86 ) ;
return 1 ;
}
static int F_118 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
char * V_193 = V_38 ;
if ( ( V_31 == V_39 ) &&
( V_2 -> V_47 == V_48 ) ) {
struct V_83 * V_87 = V_2 -> V_87 ;
if ( ! V_87 ) {
F_119 ( 1 , L_10 ) ;
return V_57 ;
}
if ( ! strchr ( V_193 , * V_87 -> V_86 ) )
return V_57 ;
F_19 ( ! V_2 -> V_54 ) ;
V_2 -> V_54 = F_116 ;
}
return V_57 ;
}
static T_4 int F_120 ( void )
{
int V_22 ;
F_117 ( V_192 L_11 ) ;
for ( V_22 = 0 ; V_22 < V_194 ; V_22 ++ ) {
struct V_58 * V_59 = NULL ;
struct V_195 * V_56 = & V_196 [ V_22 ] ;
int V_42 ;
V_42 = F_108 ( & V_197 , V_56 -> V_59 ,
false , & V_59 ) ;
if ( V_42 ) {
F_117 ( V_192
L_12 ,
V_56 -> V_59 , V_42 ) ;
F_48 ( V_59 ) ;
break;
}
F_121 () ;
if ( * V_56 -> V_198 )
F_13 ( V_59 -> V_28 , V_59 -> V_36 ,
F_118 ,
V_56 -> V_198 ) ;
V_191 = 0 ;
V_42 = F_17 ( V_59 , & V_56 -> V_50 ) ;
F_122 () ;
F_48 ( V_59 ) ;
if ( V_191 ) {
F_117 ( V_192
L_13 ,
V_56 -> V_59 ) ;
break;
}
if ( V_42 != V_56 -> V_7 ) {
F_117 ( V_192
L_14 ,
V_56 -> V_59 , V_56 -> V_7 ) ;
break;
}
}
if ( V_22 == V_194 )
F_117 ( V_199 L_15 ) ;
return 0 ;
}
