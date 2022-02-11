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
F_33 ( V_79 , L_4 ) ;
F_34 ( & V_80 ) ;
}
static struct V_82 *
F_36 ( struct V_83 * V_84 , char * V_85 )
{
struct V_82 * V_86 ;
F_37 (field, head, link) {
if ( ! strcmp ( V_86 -> V_85 , V_85 ) )
return V_86 ;
}
return NULL ;
}
static struct V_82 *
F_38 ( struct V_76 * V_77 , char * V_85 )
{
struct V_82 * V_86 ;
struct V_83 * V_84 ;
V_86 = F_36 ( & V_87 , V_85 ) ;
if ( V_86 )
return V_86 ;
V_84 = F_39 ( V_77 ) ;
return F_36 ( V_84 , V_85 ) ;
}
static int F_40 ( struct V_88 * V_89 , int V_60 )
{
V_89 -> V_28 = F_41 ( sizeof( * V_89 -> V_28 ) * ( V_60 + 1 ) , V_67 ) ;
if ( ! V_89 -> V_28 )
return - V_68 ;
V_89 -> V_29 = V_60 ;
return 0 ;
}
static void F_42 ( struct V_88 * V_89 )
{
F_22 ( V_89 -> V_28 ) ;
V_89 -> V_29 = 0 ;
}
static int F_43 ( struct V_88 * V_89 ,
struct V_1 * V_2 )
{
int V_29 = V_89 -> V_29 ;
if ( F_19 ( V_29 == 0 ) )
return - V_90 ;
V_89 -> V_28 [ -- V_29 ] = V_2 ;
V_89 -> V_29 = V_29 ;
return 0 ;
}
static struct V_1 *
F_44 ( struct V_88 * V_89 )
{
struct V_1 * V_2 ;
int V_29 = V_89 -> V_29 ;
V_2 = V_89 -> V_28 [ V_29 ++ ] ;
if ( ! V_2 )
return NULL ;
V_89 -> V_29 = V_29 ;
return V_2 ;
}
static int F_45 ( struct V_58 * V_59 ,
int V_91 ,
struct V_88 * V_89 ,
struct V_1 * V_92 )
{
struct V_1 * V_93 = & V_59 -> V_28 [ V_91 ] ;
struct V_1 * V_47 ;
struct V_1 * V_49 ;
* V_93 = * V_92 ;
V_93 -> V_29 = V_91 ;
if ( V_93 -> V_26 == V_51 || V_93 -> V_26 == V_94 ) {
V_49 = F_44 ( V_89 ) ;
V_47 = F_44 ( V_89 ) ;
if ( ! V_47 || ! V_49 )
return - V_41 ;
if ( V_47 -> V_29 & V_95 &&
( V_47 -> V_26 == V_93 -> V_26 ||
V_47 -> V_47 == V_48 ) &&
V_49 -> V_29 & V_95 &&
( V_49 -> V_26 == V_93 -> V_26 ||
V_49 -> V_47 == V_48 ) )
V_93 -> V_29 |= V_95 ;
V_93 -> V_47 = V_47 -> V_29 & ~ V_95 ;
V_93 -> V_49 = V_49 -> V_29 & ~ V_95 ;
V_47 -> V_32 = V_93 -> V_29 & ~ V_95 ;
V_49 -> V_32 = V_93 -> V_29 | V_33 ;
} else {
V_93 -> V_47 = V_48 ;
V_93 -> V_29 |= V_95 ;
}
return F_43 ( V_89 , V_93 ) ;
}
static void F_46 ( struct V_58 * V_59 )
{
if ( V_59 -> V_28 ) {
F_22 ( V_59 -> V_28 ) ;
V_59 -> V_28 = NULL ;
}
V_59 -> V_96 = 0 ;
V_59 -> V_60 = 0 ;
}
static void F_47 ( struct V_76 * V_77 )
{
V_77 -> V_97 &= ~ V_98 ;
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
V_59 -> V_96 = V_60 ;
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
if ( strcmp ( V_77 -> V_99 -> system , system -> V_85 ) != 0 )
continue;
F_47 ( V_77 ) ;
F_21 ( V_77 -> V_59 ) ;
}
}
static void F_53 ( struct V_81 * system )
{
struct V_76 * V_77 ;
F_37 (call, &ftrace_events, list) {
if ( strcmp ( V_77 -> V_99 -> system , system -> V_85 ) != 0 )
continue;
F_48 ( V_77 -> V_59 ) ;
V_77 -> V_59 = NULL ;
}
}
static int F_54 ( struct V_61 * V_62 ,
struct V_58 * V_59 ,
struct V_1 * V_2 ,
struct V_88 * V_89 )
{
int V_42 ;
if ( F_19 ( V_59 -> V_60 == V_59 -> V_96 ) ) {
F_20 ( V_62 , V_100 , 0 ) ;
return - V_90 ;
}
V_42 = F_45 ( V_59 , V_59 -> V_60 , V_89 , V_2 ) ;
if ( V_42 )
return V_42 ;
V_59 -> V_60 ++ ;
return 0 ;
}
int F_55 ( const char * type )
{
if ( strstr ( type , L_5 ) && strstr ( type , L_6 ) )
return V_101 ;
if ( strchr ( type , '[' ) && strstr ( type , L_6 ) )
return V_102 ;
return V_103 ;
}
static bool F_56 ( struct V_82 * V_86 )
{
return V_86 -> V_104 == V_101 ||
V_86 -> V_104 == V_102 ||
V_86 -> V_104 == V_105 ;
}
static int F_57 ( struct V_82 * V_86 , int V_26 )
{
if ( F_56 ( V_86 ) &&
( V_26 != V_106 && V_26 != V_107 && V_26 != V_27 ) )
return 0 ;
if ( ! F_56 ( V_86 ) && V_26 == V_27 )
return 0 ;
return 1 ;
}
static T_3 F_58 ( int V_26 , int V_108 ,
int V_109 )
{
T_3 V_54 = NULL ;
switch ( V_108 ) {
case 8 :
if ( V_26 == V_106 || V_26 == V_107 )
V_54 = V_110 ;
else if ( V_109 )
V_54 = V_111 ;
else
V_54 = V_112 ;
break;
case 4 :
if ( V_26 == V_106 || V_26 == V_107 )
V_54 = V_113 ;
else if ( V_109 )
V_54 = V_114 ;
else
V_54 = V_115 ;
break;
case 2 :
if ( V_26 == V_106 || V_26 == V_107 )
V_54 = V_116 ;
else if ( V_109 )
V_54 = V_117 ;
else
V_54 = V_118 ;
break;
case 1 :
if ( V_26 == V_106 || V_26 == V_107 )
V_54 = V_119 ;
else if ( V_109 )
V_54 = V_120 ;
else
V_54 = V_121 ;
break;
}
return V_54 ;
}
static int F_59 ( struct V_61 * V_62 ,
struct V_82 * V_86 ,
struct V_1 * V_2 )
{
T_3 V_54 = F_4 ;
unsigned long long V_52 ;
int V_43 ;
V_2 -> V_5 = V_86 -> V_5 ;
if ( ! F_57 ( V_86 , V_2 -> V_26 ) ) {
F_20 ( V_62 , V_122 , 0 ) ;
return - V_41 ;
}
if ( F_56 ( V_86 ) ) {
F_11 ( V_2 ) ;
if ( V_86 -> V_104 == V_102 ) {
V_54 = F_1 ;
V_2 -> V_8 . V_9 = V_86 -> V_123 ;
} else if ( V_86 -> V_104 == V_101 )
V_54 = F_3 ;
else
V_54 = F_2 ;
} else {
if ( V_86 -> V_124 )
V_43 = F_60 ( V_2 -> V_8 . V_17 , 0 , & V_52 ) ;
else
V_43 = F_61 ( V_2 -> V_8 . V_17 , 0 , & V_52 ) ;
if ( V_43 ) {
F_20 ( V_62 , V_125 , 0 ) ;
return - V_41 ;
}
V_2 -> V_52 = V_52 ;
V_54 = F_58 ( V_2 -> V_26 , V_86 -> V_123 ,
V_86 -> V_124 ) ;
if ( ! V_54 ) {
F_20 ( V_62 , V_126 , 0 ) ;
return - V_41 ;
}
}
if ( V_2 -> V_26 == V_107 )
V_2 -> V_10 = 1 ;
V_2 -> V_54 = V_54 ;
return 0 ;
}
static void F_62 ( struct V_61 * V_62 ,
struct V_127 * V_53 ,
char * V_128 )
{
memset ( V_62 , '\0' , sizeof( * V_62 ) ) ;
V_62 -> V_129 . string = V_128 ;
V_62 -> V_129 . V_130 = strlen ( V_128 ) ;
V_62 -> V_53 = V_53 ;
F_63 ( & V_62 -> V_131 ) ;
F_63 ( & V_62 -> V_132 ) ;
}
static char F_64 ( struct V_61 * V_62 )
{
V_62 -> V_129 . V_130 -- ;
return V_62 -> V_129 . string [ V_62 -> V_129 . V_133 ++ ] ;
}
static char F_65 ( struct V_61 * V_62 )
{
if ( V_62 -> V_129 . V_133 == strlen ( V_62 -> V_129 . string ) )
return 0 ;
return V_62 -> V_129 . string [ V_62 -> V_129 . V_133 ] ;
}
static void F_66 ( struct V_61 * V_62 )
{
V_62 -> V_129 . V_130 -- ;
V_62 -> V_129 . V_133 ++ ;
}
static inline int F_67 ( struct V_61 * V_62 ,
int V_134 , int V_135 )
{
return V_62 -> V_53 [ V_134 ] . V_136 < V_62 -> V_53 [ V_135 ] . V_136 ;
}
static inline int F_68 ( struct V_61 * V_62 , char V_137 )
{
int V_22 ;
for ( V_22 = 0 ; strcmp ( V_62 -> V_53 [ V_22 ] . string , L_7 ) ; V_22 ++ ) {
if ( V_62 -> V_53 [ V_22 ] . string [ 0 ] == V_137 )
return 1 ;
}
return 0 ;
}
static int F_69 ( struct V_61 * V_62 , char V_138 )
{
char V_139 = F_65 ( V_62 ) ;
char V_140 [ 3 ] ;
int V_22 ;
V_140 [ 0 ] = V_138 ;
V_140 [ 1 ] = V_139 ;
V_140 [ 2 ] = '\0' ;
for ( V_22 = 0 ; strcmp ( V_62 -> V_53 [ V_22 ] . string , L_7 ) ; V_22 ++ ) {
if ( ! strcmp ( V_140 , V_62 -> V_53 [ V_22 ] . string ) ) {
F_66 ( V_62 ) ;
return V_62 -> V_53 [ V_22 ] . V_141 ;
}
}
V_140 [ 1 ] = '\0' ;
for ( V_22 = 0 ; strcmp ( V_62 -> V_53 [ V_22 ] . string , L_7 ) ; V_22 ++ ) {
if ( ! strcmp ( V_140 , V_62 -> V_53 [ V_22 ] . string ) )
return V_62 -> V_53 [ V_22 ] . V_141 ;
}
return V_142 ;
}
static inline void F_70 ( struct V_61 * V_62 )
{
memset ( V_62 -> V_143 . string , '\0' , V_144 ) ;
V_62 -> V_143 . V_133 = 0 ;
}
static inline int F_71 ( struct V_61 * V_62 , char V_137 )
{
if ( V_62 -> V_143 . V_133 == V_144 - 1 )
return - V_41 ;
V_62 -> V_143 . string [ V_62 -> V_143 . V_133 ++ ] = V_137 ;
return 0 ;
}
static int F_72 ( struct V_61 * V_62 , int V_26 )
{
struct V_145 * V_145 ;
V_145 = F_27 ( sizeof( * V_145 ) , V_67 ) ;
if ( ! V_145 )
return - V_68 ;
V_145 -> V_26 = V_26 ;
F_73 ( & V_145 -> V_146 , & V_62 -> V_131 ) ;
return 0 ;
}
static int F_74 ( struct V_61 * V_62 )
{
return F_75 ( & V_62 -> V_131 ) ;
}
static int F_76 ( struct V_61 * V_62 )
{
struct V_145 * V_145 ;
if ( F_74 ( V_62 ) )
return V_142 ;
V_145 = F_77 ( & V_62 -> V_131 , struct V_145 , V_146 ) ;
return V_145 -> V_26 ;
}
static int F_78 ( struct V_61 * V_62 )
{
struct V_145 * V_145 ;
int V_26 ;
if ( F_74 ( V_62 ) )
return V_142 ;
V_145 = F_77 ( & V_62 -> V_131 , struct V_145 , V_146 ) ;
V_26 = V_145 -> V_26 ;
F_79 ( & V_145 -> V_146 ) ;
F_22 ( V_145 ) ;
return V_26 ;
}
static void F_80 ( struct V_61 * V_62 )
{
while ( ! F_74 ( V_62 ) )
F_78 ( V_62 ) ;
}
static char * F_81 ( struct V_61 * V_62 )
{
return V_62 -> V_143 . string ;
}
static int F_82 ( struct V_61 * V_62 , char * V_143 )
{
struct V_147 * V_148 ;
V_148 = F_27 ( sizeof( * V_148 ) , V_67 ) ;
if ( ! V_148 )
return - V_68 ;
V_148 -> V_26 = V_142 ;
V_148 -> V_143 = F_24 ( V_143 , V_67 ) ;
if ( ! V_148 -> V_143 ) {
F_22 ( V_148 ) ;
return - V_68 ;
}
F_83 ( & V_148 -> V_146 , & V_62 -> V_132 ) ;
return 0 ;
}
static int F_84 ( struct V_61 * V_62 , int V_26 )
{
struct V_147 * V_148 ;
V_148 = F_27 ( sizeof( * V_148 ) , V_67 ) ;
if ( ! V_148 )
return - V_68 ;
V_148 -> V_26 = V_26 ;
V_148 -> V_143 = NULL ;
F_83 ( & V_148 -> V_146 , & V_62 -> V_132 ) ;
return 0 ;
}
static void F_85 ( struct V_61 * V_62 )
{
struct V_147 * V_148 ;
while ( ! F_75 ( & V_62 -> V_132 ) ) {
V_148 = F_77 ( & V_62 -> V_132 , struct V_147 , V_146 ) ;
F_79 ( & V_148 -> V_146 ) ;
F_22 ( V_148 -> V_143 ) ;
F_22 ( V_148 ) ;
}
}
static int F_86 ( struct V_61 * V_62 )
{
int V_149 = 0 ;
int V_26 , V_150 ;
char V_151 ;
while ( ( V_151 = F_64 ( V_62 ) ) ) {
if ( V_151 == '"' ) {
V_149 ^= 1 ;
continue;
}
if ( V_149 )
goto V_152;
if ( isspace ( V_151 ) )
continue;
if ( F_68 ( V_62 , V_151 ) ) {
V_26 = F_69 ( V_62 , V_151 ) ;
if ( V_26 == V_142 ) {
F_20 ( V_62 , V_126 , 0 ) ;
return - V_41 ;
}
if ( strlen ( F_81 ( V_62 ) ) ) {
F_82 ( V_62 , F_81 ( V_62 ) ) ;
F_70 ( V_62 ) ;
}
while ( ! F_74 ( V_62 ) ) {
V_150 = F_76 ( V_62 ) ;
if ( ! F_67 ( V_62 , V_150 , V_26 ) ) {
V_150 = F_78 ( V_62 ) ;
F_84 ( V_62 , V_150 ) ;
continue;
}
break;
}
F_72 ( V_62 , V_26 ) ;
continue;
}
if ( V_151 == '(' ) {
F_72 ( V_62 , V_153 ) ;
continue;
}
if ( V_151 == ')' ) {
if ( strlen ( F_81 ( V_62 ) ) ) {
F_82 ( V_62 , F_81 ( V_62 ) ) ;
F_70 ( V_62 ) ;
}
V_150 = F_78 ( V_62 ) ;
while ( V_150 != V_142 ) {
if ( V_150 == V_153 )
break;
F_84 ( V_62 , V_150 ) ;
V_150 = F_78 ( V_62 ) ;
}
if ( V_150 == V_142 ) {
F_20 ( V_62 , V_154 , 0 ) ;
return - V_41 ;
}
continue;
}
V_152:
if ( F_71 ( V_62 , V_151 ) ) {
F_20 ( V_62 , V_155 , 0 ) ;
return - V_41 ;
}
}
if ( strlen ( F_81 ( V_62 ) ) )
F_82 ( V_62 , F_81 ( V_62 ) ) ;
while ( ! F_74 ( V_62 ) ) {
V_150 = F_78 ( V_62 ) ;
if ( V_150 == V_142 )
break;
if ( V_150 == V_153 ) {
F_20 ( V_62 , V_154 , 0 ) ;
return - V_41 ;
}
F_84 ( V_62 , V_150 ) ;
}
return 0 ;
}
static struct V_1 * F_87 ( struct V_61 * V_62 ,
struct V_76 * V_77 ,
int V_26 , char * V_156 , char * V_157 )
{
struct V_82 * V_86 ;
static struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_26 = V_26 ;
if ( V_26 == V_94 || V_26 == V_51 )
return & V_2 ;
if ( ! V_156 || ! V_157 ) {
F_20 ( V_62 , V_158 , 0 ) ;
return NULL ;
}
V_86 = F_38 ( V_77 , V_156 ) ;
if ( ! V_86 ) {
F_20 ( V_62 , V_159 , 0 ) ;
return NULL ;
}
strcpy ( V_2 . V_8 . V_17 , V_157 ) ;
V_2 . V_8 . V_11 = strlen ( V_2 . V_8 . V_17 ) ;
#ifdef F_88
V_2 . V_86 = V_86 ;
#endif
return F_59 ( V_62 , V_86 , & V_2 ) ? NULL : & V_2 ;
}
static int F_89 ( struct V_61 * V_62 )
{
int V_160 = 0 , V_161 = 0 ;
struct V_147 * V_148 ;
F_37 (elt, &ps->postfix, list) {
if ( V_148 -> V_26 == V_142 )
continue;
if ( V_148 -> V_26 == V_94 || V_148 -> V_26 == V_51 ) {
V_161 ++ ;
continue;
}
V_160 ++ ;
}
if ( ! V_160 || V_161 >= V_160 ) {
F_20 ( V_62 , V_162 , 0 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_90 ( struct V_61 * V_62 )
{
struct V_147 * V_148 ;
int V_60 = 0 ;
F_37 (elt, &ps->postfix, list) {
if ( V_148 -> V_26 == V_142 )
continue;
V_60 ++ ;
}
return V_60 ;
}
static int F_91 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
struct V_163 * V_56 = V_38 ;
if ( F_19 ( V_56 -> V_164 ++ > V_56 -> V_165 ) ) {
* V_42 = - V_41 ;
return V_44 ;
}
return V_57 ;
}
static int F_92 ( struct V_58 * V_59 ,
struct V_1 * V_36 )
{
struct V_163 V_38 = {
. V_165 = 3 * V_59 -> V_60 ,
. V_164 = 0 ,
} ;
return F_13 ( V_59 -> V_28 , V_36 ,
F_91 , & V_38 ) ;
}
static int F_93 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
int * V_164 = V_38 ;
if ( ( V_31 == V_39 ) &&
( V_2 -> V_47 == V_48 ) )
( * V_164 ) ++ ;
return V_57 ;
}
static int F_94 ( struct V_1 * V_28 , struct V_1 * V_36 )
{
int V_164 = 0 , V_43 ;
V_43 = F_13 ( V_28 , V_36 , F_93 , & V_164 ) ;
F_19 ( V_43 ) ;
return V_164 ;
}
static int F_95 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
struct V_166 * V_56 = V_38 ;
struct V_1 * V_36 = V_56 -> V_36 ;
if ( V_31 != V_39 )
return V_57 ;
if ( V_2 -> V_47 != V_48 )
return V_57 ;
if ( F_19 ( V_56 -> V_164 == V_56 -> V_167 ) ) {
* V_42 = - V_41 ;
return V_44 ;
}
V_2 -> V_29 &= ~ V_95 ;
V_36 -> V_53 [ V_56 -> V_164 ++ ] = V_2 -> V_29 ;
return V_57 ;
}
static int F_96 ( struct V_1 * V_28 , struct V_1 * V_36 )
{
struct V_166 V_38 = {
. V_36 = V_36 ,
. V_164 = 0 ,
} ;
int V_167 ;
V_36 -> V_29 &= ~ V_95 ;
if ( V_36 -> V_47 == V_48 )
return 0 ;
V_167 = F_94 ( V_28 , & V_28 [ V_36 -> V_47 ] ) ;
V_167 += F_94 ( V_28 , & V_28 [ V_36 -> V_49 ] ) ;
V_36 -> V_53 = F_41 ( sizeof( * V_36 -> V_53 ) * V_167 , V_67 ) ;
if ( ! V_36 -> V_53 )
return - V_68 ;
V_36 -> V_52 = V_167 ;
V_38 . V_167 = V_167 ;
return F_13 ( V_28 , V_36 , F_95 , & V_38 ) ;
}
static int F_97 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
struct V_1 * V_28 = V_38 ;
if ( V_31 != V_39 )
return V_57 ;
if ( ! ( V_2 -> V_29 & V_95 ) )
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
bool V_168 )
{
char * V_156 = NULL , * V_157 = NULL ;
struct V_1 * V_2 ;
struct V_1 * V_36 ;
struct V_147 * V_148 ;
struct V_88 V_89 = { } ;
int V_42 ;
int V_60 = 0 ;
V_60 = F_90 ( V_62 ) ;
if ( V_60 >= V_169 ) {
F_20 ( V_62 , V_100 , 0 ) ;
return - V_90 ;
}
V_42 = F_89 ( V_62 ) ;
if ( V_42 )
return V_42 ;
if ( ! V_168 ) {
V_42 = F_40 ( & V_89 , V_60 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_51 ( V_59 , V_60 ) ;
if ( V_42 )
goto V_170;
}
V_60 = 0 ;
F_37 (elt, &ps->postfix, list) {
if ( V_148 -> V_26 == V_142 ) {
if ( ! V_156 )
V_156 = V_148 -> V_143 ;
else if ( ! V_157 )
V_157 = V_148 -> V_143 ;
else {
F_20 ( V_62 , V_171 , 0 ) ;
V_42 = - V_41 ;
goto V_170;
}
continue;
}
if ( F_19 ( V_60 ++ == V_169 ) ) {
F_20 ( V_62 , V_100 , 0 ) ;
V_42 = - V_90 ;
goto V_170;
}
V_2 = F_87 ( V_62 , V_77 , V_148 -> V_26 , V_156 , V_157 ) ;
if ( ! V_2 ) {
V_42 = - V_41 ;
goto V_170;
}
if ( ! V_168 ) {
V_42 = F_54 ( V_62 , V_59 , V_2 , & V_89 ) ;
if ( V_42 )
goto V_170;
}
V_156 = V_157 = NULL ;
}
if ( ! V_168 ) {
V_2 = F_44 ( & V_89 ) ;
if ( ! V_2 )
return - V_41 ;
V_36 = V_2 ;
V_2 = F_44 ( & V_89 ) ;
if ( F_19 ( V_2 ) ) {
V_42 = - V_41 ;
V_59 -> V_36 = NULL ;
goto V_170;
}
V_42 = F_92 ( V_59 , V_36 ) ;
if ( V_42 )
goto V_170;
V_42 = F_98 ( V_59 , V_36 ) ;
if ( V_42 )
goto V_170;
F_100 () ;
V_59 -> V_36 = V_36 ;
}
V_42 = 0 ;
V_170:
F_42 ( & V_89 ) ;
return V_42 ;
}
static int F_101 ( struct V_81 * system ,
struct V_61 * V_62 ,
char * V_66 )
{
struct V_76 * V_77 ;
struct V_172 * V_173 ;
struct V_172 * V_174 ;
F_102 ( V_172 ) ;
bool V_170 = true ;
int V_42 ;
F_37 (call, &ftrace_events, list) {
if ( strcmp ( V_77 -> V_99 -> system , system -> V_85 ) != 0 )
continue;
V_42 = F_99 ( V_77 , NULL , V_62 , V_66 , true ) ;
if ( V_42 )
V_77 -> V_97 |= V_175 ;
else
V_77 -> V_97 &= ~ V_175 ;
}
F_37 (call, &ftrace_events, list) {
struct V_58 * V_59 ;
if ( strcmp ( V_77 -> V_99 -> system , system -> V_85 ) != 0 )
continue;
if ( V_77 -> V_97 & V_175 )
continue;
V_173 = F_41 ( sizeof( * V_173 ) , V_67 ) ;
if ( ! V_173 )
goto V_176;
F_83 ( & V_173 -> V_146 , & V_172 ) ;
V_173 -> V_59 = F_50 () ;
if ( ! V_173 -> V_59 )
goto V_176;
V_59 = V_173 -> V_59 ;
V_42 = F_23 ( V_59 , V_66 ) ;
if ( V_42 )
goto V_176;
V_42 = F_99 ( V_77 , V_59 , V_62 , V_66 , false ) ;
if ( V_42 ) {
F_47 ( V_77 ) ;
F_20 ( V_62 , V_177 , 0 ) ;
F_28 ( V_62 , V_59 ) ;
} else
V_77 -> V_97 |= V_98 ;
V_59 = V_77 -> V_59 ;
F_103 ( V_77 -> V_59 , V_173 -> V_59 ) ;
V_173 -> V_59 = V_59 ;
V_170 = false ;
}
if ( V_170 )
goto V_170;
F_104 () ;
F_105 (filter_item, tmp, &filter_list, list) {
F_48 ( V_173 -> V_59 ) ;
F_79 ( & V_173 -> V_146 ) ;
F_22 ( V_173 ) ;
}
return 0 ;
V_170:
F_105 (filter_item, tmp, &filter_list, list) {
F_79 ( & V_173 -> V_146 ) ;
F_22 ( V_173 ) ;
}
F_20 ( V_62 , V_177 , 0 ) ;
return - V_41 ;
V_176:
if ( ! V_170 )
F_104 () ;
F_105 (filter_item, tmp, &filter_list, list) {
F_48 ( V_173 -> V_59 ) ;
F_79 ( & V_173 -> V_146 ) ;
F_22 ( V_173 ) ;
}
return - V_68 ;
}
int F_106 ( struct V_76 * V_77 , char * V_66 )
{
struct V_61 * V_62 ;
struct V_58 * V_59 ;
struct V_58 * V_174 ;
int V_42 = 0 ;
F_32 ( & V_80 ) ;
if ( ! strcmp ( F_107 ( V_66 ) , L_8 ) ) {
F_47 ( V_77 ) ;
V_59 = V_77 -> V_59 ;
if ( ! V_59 )
goto V_178;
F_108 ( V_77 -> V_59 , NULL ) ;
F_104 () ;
F_48 ( V_59 ) ;
goto V_178;
}
V_42 = - V_68 ;
V_62 = F_41 ( sizeof( * V_62 ) , V_67 ) ;
if ( ! V_62 )
goto V_178;
V_59 = F_50 () ;
if ( ! V_59 ) {
F_22 ( V_62 ) ;
goto V_178;
}
F_23 ( V_59 , V_66 ) ;
F_62 ( V_62 , V_179 , V_66 ) ;
V_42 = F_86 ( V_62 ) ;
if ( V_42 ) {
F_28 ( V_62 , V_59 ) ;
goto V_180;
}
V_42 = F_99 ( V_77 , V_59 , V_62 , V_66 , false ) ;
if ( V_42 ) {
F_47 ( V_77 ) ;
F_28 ( V_62 , V_59 ) ;
} else
V_77 -> V_97 |= V_98 ;
V_180:
V_174 = V_77 -> V_59 ;
F_103 ( V_77 -> V_59 , V_59 ) ;
if ( V_174 ) {
F_104 () ;
F_48 ( V_174 ) ;
}
F_80 ( V_62 ) ;
F_85 ( V_62 ) ;
F_22 ( V_62 ) ;
V_178:
F_34 ( & V_80 ) ;
return V_42 ;
}
int F_109 ( struct V_81 * system ,
char * V_66 )
{
struct V_61 * V_62 ;
struct V_58 * V_59 ;
int V_42 = 0 ;
F_32 ( & V_80 ) ;
if ( ! system -> V_181 ) {
V_42 = - V_182 ;
goto V_178;
}
if ( ! strcmp ( F_107 ( V_66 ) , L_8 ) ) {
F_52 ( system ) ;
F_21 ( system -> V_59 ) ;
V_59 = system -> V_59 ;
system -> V_59 = NULL ;
F_104 () ;
F_53 ( system ) ;
F_48 ( V_59 ) ;
goto V_178;
}
V_42 = - V_68 ;
V_62 = F_41 ( sizeof( * V_62 ) , V_67 ) ;
if ( ! V_62 )
goto V_178;
V_59 = F_50 () ;
if ( ! V_59 )
goto V_180;
F_23 ( V_59 , V_66 ) ;
F_48 ( system -> V_59 ) ;
system -> V_59 = V_59 ;
F_62 ( V_62 , V_179 , V_66 ) ;
V_42 = F_86 ( V_62 ) ;
if ( V_42 ) {
F_28 ( V_62 , system -> V_59 ) ;
goto V_180;
}
V_42 = F_101 ( system , V_62 , V_66 ) ;
if ( V_42 )
F_28 ( V_62 , system -> V_59 ) ;
V_180:
F_80 ( V_62 ) ;
F_85 ( V_62 ) ;
F_22 ( V_62 ) ;
V_178:
F_34 ( & V_80 ) ;
return V_42 ;
}
void F_110 ( struct V_183 * V_3 )
{
struct V_58 * V_59 = V_3 -> V_59 ;
V_3 -> V_59 = NULL ;
F_48 ( V_59 ) ;
}
int F_111 ( struct V_183 * V_3 , int V_184 ,
char * V_185 )
{
int V_42 ;
struct V_58 * V_59 ;
struct V_61 * V_62 ;
struct V_76 * V_77 ;
F_32 ( & V_80 ) ;
V_77 = V_3 -> V_186 ;
V_42 = - V_41 ;
if ( ! V_77 )
goto V_178;
V_42 = - V_187 ;
if ( V_3 -> V_59 )
goto V_178;
V_59 = F_50 () ;
if ( ! V_59 ) {
V_42 = F_112 ( V_59 ) ;
goto V_178;
}
V_42 = - V_68 ;
V_62 = F_41 ( sizeof( * V_62 ) , V_67 ) ;
if ( ! V_62 )
goto V_188;
F_62 ( V_62 , V_179 , V_185 ) ;
V_42 = F_86 ( V_62 ) ;
if ( V_42 )
goto V_189;
V_42 = F_99 ( V_77 , V_59 , V_62 , V_185 , false ) ;
if ( ! V_42 )
V_3 -> V_59 = V_59 ;
V_189:
F_80 ( V_62 ) ;
F_85 ( V_62 ) ;
F_22 ( V_62 ) ;
V_188:
if ( V_42 )
F_48 ( V_59 ) ;
V_178:
F_34 ( & V_80 ) ;
return V_42 ;
}
static int F_113 ( char * V_185 , struct V_76 * V_77 ,
struct V_58 * * V_190 )
{
struct V_58 * V_59 ;
struct V_61 * V_62 ;
int V_42 = - V_68 ;
V_59 = F_50 () ;
if ( ! V_59 )
goto V_180;
V_62 = F_41 ( sizeof( * V_62 ) , V_67 ) ;
if ( ! V_62 )
goto V_188;
F_62 ( V_62 , V_179 , V_185 ) ;
V_42 = F_86 ( V_62 ) ;
if ( V_42 )
goto V_189;
V_42 = F_99 ( V_77 , V_59 , V_62 , V_185 , false ) ;
if ( ! V_42 )
* V_190 = V_59 ;
V_189:
F_80 ( V_62 ) ;
F_85 ( V_62 ) ;
F_22 ( V_62 ) ;
V_188:
if ( V_42 )
F_48 ( V_59 ) ;
V_180:
return V_42 ;
}
static int F_114 ( struct V_1 * V_2 , void * V_3 )
{
struct V_82 * V_86 = V_2 -> V_86 ;
V_191 = 1 ;
F_115 ( V_192 L_9 , V_86 -> V_85 ) ;
return 1 ;
}
static int F_116 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
char * V_193 = V_38 ;
if ( ( V_31 == V_39 ) &&
( V_2 -> V_47 == V_48 ) ) {
struct V_82 * V_86 = V_2 -> V_86 ;
if ( ! V_86 ) {
F_117 ( 1 , L_10 ) ;
return V_57 ;
}
if ( ! strchr ( V_193 , * V_86 -> V_85 ) )
return V_57 ;
F_19 ( ! V_2 -> V_54 ) ;
V_2 -> V_54 = F_114 ;
}
return V_57 ;
}
static T_4 int F_118 ( void )
{
int V_22 ;
F_115 ( V_192 L_11 ) ;
for ( V_22 = 0 ; V_22 < V_194 ; V_22 ++ ) {
struct V_58 * V_59 = NULL ;
struct V_195 * V_56 = & V_196 [ V_22 ] ;
int V_42 ;
V_42 = F_113 ( V_56 -> V_59 , & V_197 ,
& V_59 ) ;
if ( V_42 ) {
F_115 ( V_192
L_12 ,
V_56 -> V_59 , V_42 ) ;
break;
}
F_119 () ;
if ( * V_56 -> V_198 )
F_13 ( V_59 -> V_28 , V_59 -> V_36 ,
F_116 ,
V_56 -> V_198 ) ;
V_191 = 0 ;
V_42 = F_17 ( V_59 , & V_56 -> V_50 ) ;
F_120 () ;
F_48 ( V_59 ) ;
if ( V_191 ) {
F_115 ( V_192
L_13 ,
V_56 -> V_59 ) ;
break;
}
if ( V_42 != V_56 -> V_7 ) {
F_115 ( V_192
L_14 ,
V_56 -> V_59 , V_56 -> V_7 ) ;
break;
}
}
if ( V_22 == V_194 )
F_115 ( V_199 L_15 ) ;
return 0 ;
}
