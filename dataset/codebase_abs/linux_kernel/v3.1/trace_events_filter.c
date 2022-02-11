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
struct V_1 * V_26 , void * V_36 )
{
struct V_1 * V_2 ;
int V_7 = 0 ;
int type ;
int V_22 ;
type = V_26 -> V_26 == V_37 ;
for ( V_22 = 0 ; V_22 < V_26 -> V_38 ; V_22 ++ ) {
V_2 = & V_28 [ V_26 -> V_39 [ V_22 ] ] ;
V_7 = V_2 -> V_40 ( V_2 , V_36 ) ;
if ( ! ! V_7 == type )
return V_7 ;
}
return V_7 ;
}
int F_14 ( struct V_41 * V_42 , void * V_36 )
{
int V_7 = - 1 ;
enum V_30 V_31 = V_43 ;
struct V_1 * V_28 ;
struct V_1 * V_2 ;
struct V_1 * V_44 ;
int V_45 ;
int V_46 = 0 ;
if ( ! V_42 )
return 1 ;
V_45 = V_42 -> V_45 ;
if ( ! V_45 )
return 1 ;
V_28 = F_15 ( V_42 -> V_28 ) ;
V_44 = F_15 ( V_42 -> V_44 ) ;
if ( ! V_44 )
return 1 ;
V_2 = V_44 ;
V_7 = - 1 ;
do {
switch ( V_31 ) {
case V_43 :
if ( V_2 -> V_47 != V_48 ) {
if ( ! V_2 -> V_39 ) {
V_2 = & V_28 [ V_2 -> V_47 ] ;
continue;
}
V_7 = F_13 ( V_28 , V_2 , V_36 ) ;
} else
V_7 = V_2 -> V_40 ( V_2 , V_36 ) ;
if ( V_2 == V_44 )
break;
V_2 = F_12 ( V_2 , V_28 ,
V_2 -> V_32 , & V_31 ) ;
continue;
case V_35 :
if ( ! ! V_7 == ( V_2 -> V_26 == V_37 ) ) {
if ( V_2 == V_44 )
break;
V_2 = F_12 ( V_2 , V_28 ,
V_2 -> V_32 , & V_31 ) ;
continue;
}
V_2 = & V_28 [ V_2 -> V_49 ] ;
V_31 = V_43 ;
continue;
case V_34 :
if ( V_2 == V_44 )
break;
V_2 = F_12 ( V_2 , V_28 ,
V_2 -> V_32 , & V_31 ) ;
continue;
}
V_46 = 1 ;
} while ( ! V_46 );
return V_7 ;
}
static void F_16 ( struct V_50 * V_51 , int V_52 , int V_53 )
{
V_51 -> V_54 = V_52 ;
V_51 -> V_55 = V_53 ;
}
static void F_17 ( struct V_41 * V_42 )
{
if ( ! V_42 )
return;
F_18 ( V_42 -> V_56 ) ;
V_42 -> V_56 = NULL ;
}
static int F_19 ( struct V_41 * V_42 ,
char * V_56 )
{
F_18 ( V_42 -> V_56 ) ;
V_42 -> V_56 = F_20 ( V_56 , V_57 ) ;
if ( ! V_42 -> V_56 )
return - V_58 ;
return 0 ;
}
static int F_21 ( struct V_41 * V_42 ,
char * string )
{
int V_59 ;
char * V_60 ;
F_22 ( ! V_42 -> V_56 ) ;
V_59 = strlen ( V_42 -> V_56 ) + strlen ( string ) + 1 ;
V_60 = F_23 ( V_59 , V_57 ) ;
if ( ! V_60 )
return - V_58 ;
strcpy ( V_60 , V_42 -> V_56 ) ;
strcat ( V_60 , string ) ;
F_18 ( V_42 -> V_56 ) ;
V_42 -> V_56 = V_60 ;
return 0 ;
}
static void F_24 ( struct V_50 * V_51 ,
struct V_41 * V_42 )
{
int V_53 = V_51 -> V_55 ;
char * V_61 , * V_62 ;
V_61 = ( char * ) F_25 ( V_63 ) ;
if ( ! V_61 )
return;
F_21 ( V_42 , L_1 ) ;
memset ( V_61 , ' ' , V_64 ) ;
if ( V_53 > V_64 - 128 )
V_53 = 0 ;
V_61 [ V_53 ] = '^' ;
V_62 = & V_61 [ V_53 ] + 1 ;
sprintf ( V_62 , L_2 , V_65 [ V_51 -> V_54 ] ) ;
F_21 ( V_42 , V_61 ) ;
F_26 ( ( unsigned long ) V_61 ) ;
}
void F_27 ( struct V_66 * V_67 , struct V_68 * V_69 )
{
struct V_41 * V_42 ;
F_28 ( & V_70 ) ;
V_42 = V_67 -> V_42 ;
if ( V_42 && V_42 -> V_56 )
F_29 ( V_69 , L_3 , V_42 -> V_56 ) ;
else
F_29 ( V_69 , L_4 ) ;
F_30 ( & V_70 ) ;
}
void F_31 ( struct V_71 * system ,
struct V_68 * V_69 )
{
struct V_41 * V_42 ;
F_28 ( & V_70 ) ;
V_42 = system -> V_42 ;
if ( V_42 && V_42 -> V_56 )
F_29 ( V_69 , L_3 , V_42 -> V_56 ) ;
else
F_29 ( V_69 , L_4 ) ;
F_30 ( & V_70 ) ;
}
static struct V_72 *
F_32 ( struct V_73 * V_74 , char * V_75 )
{
struct V_72 * V_76 ;
F_33 (field, head, link) {
if ( ! strcmp ( V_76 -> V_75 , V_75 ) )
return V_76 ;
}
return NULL ;
}
static struct V_72 *
F_34 ( struct V_66 * V_67 , char * V_75 )
{
struct V_72 * V_76 ;
struct V_73 * V_74 ;
V_76 = F_32 ( & V_77 , V_75 ) ;
if ( V_76 )
return V_76 ;
V_74 = F_35 ( V_67 ) ;
return F_32 ( V_74 , V_75 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_18 ( V_2 -> V_78 ) ;
F_18 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_18 ( V_2 -> V_78 ) ;
V_2 -> V_78 = NULL ;
V_2 -> V_8 . V_11 = 0 ;
}
static int F_38 ( struct V_79 * V_80 , int V_45 )
{
V_80 -> V_28 = F_39 ( sizeof( * V_80 -> V_28 ) * ( V_45 + 1 ) , V_57 ) ;
if ( ! V_80 -> V_28 )
return - V_58 ;
V_80 -> V_29 = V_45 ;
return 0 ;
}
static void F_40 ( struct V_79 * V_80 )
{
F_18 ( V_80 -> V_28 ) ;
V_80 -> V_29 = 0 ;
}
static int F_41 ( struct V_79 * V_80 ,
struct V_1 * V_2 )
{
int V_29 = V_80 -> V_29 ;
if ( F_42 ( V_29 == 0 ) )
return - V_81 ;
V_80 -> V_28 [ -- V_29 ] = V_2 ;
V_80 -> V_29 = V_29 ;
return 0 ;
}
static struct V_1 *
F_43 ( struct V_79 * V_80 )
{
struct V_1 * V_2 ;
int V_29 = V_80 -> V_29 ;
V_2 = V_80 -> V_28 [ V_29 ++ ] ;
if ( ! V_2 )
return NULL ;
V_80 -> V_29 = V_29 ;
return V_2 ;
}
static int F_44 ( struct V_41 * V_42 ,
int V_82 ,
struct V_79 * V_80 ,
struct V_1 * V_83 ,
T_2 V_40 )
{
struct V_1 * V_84 = & V_42 -> V_28 [ V_82 ] ;
struct V_1 * V_47 ;
struct V_1 * V_49 ;
* V_84 = * V_83 ;
if ( V_83 -> V_78 ) {
V_84 -> V_78 = F_20 ( V_83 -> V_78 , V_57 ) ;
if ( ! V_84 -> V_78 )
return - V_58 ;
}
V_84 -> V_40 = V_40 ;
V_84 -> V_29 = V_82 ;
if ( V_84 -> V_26 == V_37 || V_84 -> V_26 == V_85 ) {
V_49 = F_43 ( V_80 ) ;
V_47 = F_43 ( V_80 ) ;
if ( ! V_47 || ! V_49 )
return - V_86 ;
if ( V_47 -> V_29 & V_87 &&
( V_47 -> V_26 == V_84 -> V_26 ||
V_47 -> V_47 == V_48 ) &&
V_49 -> V_29 & V_87 &&
( V_49 -> V_26 == V_84 -> V_26 ||
V_49 -> V_47 == V_48 ) )
V_84 -> V_29 |= V_87 ;
V_84 -> V_47 = V_47 -> V_29 & ~ V_87 ;
V_84 -> V_49 = V_49 -> V_29 & ~ V_87 ;
V_47 -> V_32 = V_84 -> V_29 & ~ V_87 ;
V_49 -> V_32 = V_84 -> V_29 | V_33 ;
} else {
V_84 -> V_47 = V_48 ;
V_84 -> V_29 |= V_87 ;
}
return F_41 ( V_80 , V_84 ) ;
}
static void F_45 ( struct V_41 * V_42 )
{
int V_22 ;
if ( V_42 -> V_28 ) {
for ( V_22 = 0 ; V_22 < V_42 -> V_88 ; V_22 ++ )
F_18 ( V_42 -> V_28 [ V_22 ] . V_78 ) ;
F_18 ( V_42 -> V_28 ) ;
V_42 -> V_28 = NULL ;
}
V_42 -> V_88 = 0 ;
V_42 -> V_45 = 0 ;
}
static void F_46 ( struct V_66 * V_67 )
{
V_67 -> V_89 &= ~ V_90 ;
}
static void F_47 ( struct V_41 * V_42 )
{
if ( ! V_42 )
return;
F_45 ( V_42 ) ;
F_18 ( V_42 -> V_56 ) ;
F_18 ( V_42 ) ;
}
void F_48 ( struct V_66 * V_67 )
{
F_47 ( V_67 -> V_42 ) ;
V_67 -> V_42 = NULL ;
}
static struct V_41 * F_49 ( void )
{
struct V_41 * V_42 ;
V_42 = F_39 ( sizeof( * V_42 ) , V_57 ) ;
return V_42 ;
}
static int F_50 ( struct V_41 * V_42 , int V_45 )
{
struct V_1 * V_2 ;
int V_22 ;
if ( V_42 -> V_28 )
F_45 ( V_42 ) ;
V_42 -> V_28 =
F_39 ( sizeof( * V_42 -> V_28 ) * V_45 , V_57 ) ;
if ( ! V_42 -> V_28 )
return - V_58 ;
V_42 -> V_88 = V_45 ;
V_42 -> V_45 = 0 ;
for ( V_22 = 0 ; V_22 < V_45 ; V_22 ++ ) {
V_2 = & V_42 -> V_28 [ V_22 ] ;
V_2 -> V_40 = F_4 ;
}
return 0 ;
}
static void F_51 ( struct V_71 * system )
{
struct V_66 * V_67 ;
F_33 (call, &ftrace_events, list) {
if ( strcmp ( V_67 -> V_91 -> system , system -> V_75 ) != 0 )
continue;
F_46 ( V_67 ) ;
F_17 ( V_67 -> V_42 ) ;
}
}
static void F_52 ( struct V_71 * system )
{
struct V_66 * V_67 ;
F_33 (call, &ftrace_events, list) {
if ( strcmp ( V_67 -> V_91 -> system , system -> V_75 ) != 0 )
continue;
F_47 ( V_67 -> V_42 ) ;
V_67 -> V_42 = NULL ;
}
}
static int F_53 ( struct V_50 * V_51 ,
struct V_66 * V_67 ,
struct V_41 * V_42 ,
struct V_1 * V_2 ,
struct V_79 * V_80 ,
T_2 V_40 )
{
int V_82 , V_52 ;
if ( F_42 ( V_42 -> V_45 == V_42 -> V_88 ) ) {
F_16 ( V_51 , V_92 , 0 ) ;
return - V_81 ;
}
V_82 = V_42 -> V_45 ;
F_37 ( & V_42 -> V_28 [ V_82 ] ) ;
V_52 = F_44 ( V_42 , V_82 , V_80 , V_2 , V_40 ) ;
if ( V_52 )
return V_52 ;
V_42 -> V_45 ++ ;
return 0 ;
}
int F_54 ( const char * type )
{
if ( strstr ( type , L_5 ) && strstr ( type , L_6 ) )
return V_93 ;
if ( strchr ( type , '[' ) && strstr ( type , L_6 ) )
return V_94 ;
return V_95 ;
}
static bool F_55 ( struct V_72 * V_76 )
{
return V_76 -> V_96 == V_93 ||
V_76 -> V_96 == V_94 ||
V_76 -> V_96 == V_97 ;
}
static int F_56 ( struct V_72 * V_76 , int V_26 )
{
if ( F_55 ( V_76 ) &&
( V_26 != V_98 && V_26 != V_99 && V_26 != V_27 ) )
return 0 ;
if ( ! F_55 ( V_76 ) && V_26 == V_27 )
return 0 ;
return 1 ;
}
static T_2 F_57 ( int V_26 , int V_100 ,
int V_101 )
{
T_2 V_40 = NULL ;
switch ( V_100 ) {
case 8 :
if ( V_26 == V_98 || V_26 == V_99 )
V_40 = V_102 ;
else if ( V_101 )
V_40 = V_103 ;
else
V_40 = V_104 ;
break;
case 4 :
if ( V_26 == V_98 || V_26 == V_99 )
V_40 = V_105 ;
else if ( V_101 )
V_40 = V_106 ;
else
V_40 = V_107 ;
break;
case 2 :
if ( V_26 == V_98 || V_26 == V_99 )
V_40 = V_108 ;
else if ( V_101 )
V_40 = V_109 ;
else
V_40 = V_110 ;
break;
case 1 :
if ( V_26 == V_98 || V_26 == V_99 )
V_40 = V_111 ;
else if ( V_101 )
V_40 = V_112 ;
else
V_40 = V_113 ;
break;
}
return V_40 ;
}
static int F_58 ( struct V_50 * V_51 ,
struct V_66 * V_67 ,
struct V_41 * V_42 ,
struct V_1 * V_2 ,
struct V_79 * V_80 ,
bool V_114 )
{
struct V_72 * V_76 ;
T_2 V_40 ;
unsigned long long V_38 ;
int V_115 ;
V_40 = V_2 -> V_40 = F_4 ;
if ( V_2 -> V_26 == V_85 )
goto V_116;
else if ( V_2 -> V_26 == V_37 )
goto V_116;
V_76 = F_34 ( V_67 , V_2 -> V_78 ) ;
if ( ! V_76 ) {
F_16 ( V_51 , V_117 , 0 ) ;
return - V_86 ;
}
V_2 -> V_5 = V_76 -> V_5 ;
if ( ! F_56 ( V_76 , V_2 -> V_26 ) ) {
F_16 ( V_51 , V_118 , 0 ) ;
return - V_86 ;
}
if ( F_55 ( V_76 ) ) {
F_11 ( V_2 ) ;
if ( V_76 -> V_96 == V_94 ) {
V_40 = F_1 ;
V_2 -> V_8 . V_9 = V_76 -> V_119 ;
} else if ( V_76 -> V_96 == V_93 )
V_40 = F_3 ;
else
V_40 = F_2 ;
} else {
if ( V_76 -> V_120 )
V_115 = F_59 ( V_2 -> V_8 . V_17 , 0 , & V_38 ) ;
else
V_115 = F_60 ( V_2 -> V_8 . V_17 , 0 , & V_38 ) ;
if ( V_115 ) {
F_16 ( V_51 , V_121 , 0 ) ;
return - V_86 ;
}
V_2 -> V_38 = V_38 ;
V_40 = F_57 ( V_2 -> V_26 , V_76 -> V_119 ,
V_76 -> V_120 ) ;
if ( ! V_40 ) {
F_16 ( V_51 , V_122 , 0 ) ;
return - V_86 ;
}
}
if ( V_2 -> V_26 == V_99 )
V_2 -> V_10 = 1 ;
V_116:
if ( ! V_114 )
return F_53 ( V_51 , V_67 , V_42 , V_2 , V_80 , V_40 ) ;
return 0 ;
}
static void F_61 ( struct V_50 * V_51 ,
struct V_123 * V_39 ,
char * V_124 )
{
memset ( V_51 , '\0' , sizeof( * V_51 ) ) ;
V_51 -> V_125 . string = V_124 ;
V_51 -> V_125 . V_126 = strlen ( V_124 ) ;
V_51 -> V_39 = V_39 ;
F_62 ( & V_51 -> V_127 ) ;
F_62 ( & V_51 -> V_128 ) ;
}
static char F_63 ( struct V_50 * V_51 )
{
V_51 -> V_125 . V_126 -- ;
return V_51 -> V_125 . string [ V_51 -> V_125 . V_129 ++ ] ;
}
static char F_64 ( struct V_50 * V_51 )
{
if ( V_51 -> V_125 . V_129 == strlen ( V_51 -> V_125 . string ) )
return 0 ;
return V_51 -> V_125 . string [ V_51 -> V_125 . V_129 ] ;
}
static void F_65 ( struct V_50 * V_51 )
{
V_51 -> V_125 . V_126 -- ;
V_51 -> V_125 . V_129 ++ ;
}
static inline int F_66 ( struct V_50 * V_51 ,
int V_130 , int V_131 )
{
return V_51 -> V_39 [ V_130 ] . V_132 < V_51 -> V_39 [ V_131 ] . V_132 ;
}
static inline int F_67 ( struct V_50 * V_51 , char V_133 )
{
int V_22 ;
for ( V_22 = 0 ; strcmp ( V_51 -> V_39 [ V_22 ] . string , L_7 ) ; V_22 ++ ) {
if ( V_51 -> V_39 [ V_22 ] . string [ 0 ] == V_133 )
return 1 ;
}
return 0 ;
}
static int F_68 ( struct V_50 * V_51 , char V_134 )
{
char V_135 = F_64 ( V_51 ) ;
char V_136 [ 3 ] ;
int V_22 ;
V_136 [ 0 ] = V_134 ;
V_136 [ 1 ] = V_135 ;
V_136 [ 2 ] = '\0' ;
for ( V_22 = 0 ; strcmp ( V_51 -> V_39 [ V_22 ] . string , L_7 ) ; V_22 ++ ) {
if ( ! strcmp ( V_136 , V_51 -> V_39 [ V_22 ] . string ) ) {
F_65 ( V_51 ) ;
return V_51 -> V_39 [ V_22 ] . V_137 ;
}
}
V_136 [ 1 ] = '\0' ;
for ( V_22 = 0 ; strcmp ( V_51 -> V_39 [ V_22 ] . string , L_7 ) ; V_22 ++ ) {
if ( ! strcmp ( V_136 , V_51 -> V_39 [ V_22 ] . string ) )
return V_51 -> V_39 [ V_22 ] . V_137 ;
}
return V_138 ;
}
static inline void F_69 ( struct V_50 * V_51 )
{
memset ( V_51 -> V_139 . string , '\0' , V_140 ) ;
V_51 -> V_139 . V_129 = 0 ;
}
static inline int F_70 ( struct V_50 * V_51 , char V_133 )
{
if ( V_51 -> V_139 . V_129 == V_140 - 1 )
return - V_86 ;
V_51 -> V_139 . string [ V_51 -> V_139 . V_129 ++ ] = V_133 ;
return 0 ;
}
static int F_71 ( struct V_50 * V_51 , int V_26 )
{
struct V_141 * V_141 ;
V_141 = F_23 ( sizeof( * V_141 ) , V_57 ) ;
if ( ! V_141 )
return - V_58 ;
V_141 -> V_26 = V_26 ;
F_72 ( & V_141 -> V_142 , & V_51 -> V_127 ) ;
return 0 ;
}
static int F_73 ( struct V_50 * V_51 )
{
return F_74 ( & V_51 -> V_127 ) ;
}
static int F_75 ( struct V_50 * V_51 )
{
struct V_141 * V_141 ;
if ( F_73 ( V_51 ) )
return V_138 ;
V_141 = F_76 ( & V_51 -> V_127 , struct V_141 , V_142 ) ;
return V_141 -> V_26 ;
}
static int F_77 ( struct V_50 * V_51 )
{
struct V_141 * V_141 ;
int V_26 ;
if ( F_73 ( V_51 ) )
return V_138 ;
V_141 = F_76 ( & V_51 -> V_127 , struct V_141 , V_142 ) ;
V_26 = V_141 -> V_26 ;
F_78 ( & V_141 -> V_142 ) ;
F_18 ( V_141 ) ;
return V_26 ;
}
static void F_79 ( struct V_50 * V_51 )
{
while ( ! F_73 ( V_51 ) )
F_77 ( V_51 ) ;
}
static char * F_80 ( struct V_50 * V_51 )
{
return V_51 -> V_139 . string ;
}
static int F_81 ( struct V_50 * V_51 , char * V_139 )
{
struct V_143 * V_144 ;
V_144 = F_23 ( sizeof( * V_144 ) , V_57 ) ;
if ( ! V_144 )
return - V_58 ;
V_144 -> V_26 = V_138 ;
V_144 -> V_139 = F_20 ( V_139 , V_57 ) ;
if ( ! V_144 -> V_139 ) {
F_18 ( V_144 ) ;
return - V_58 ;
}
F_82 ( & V_144 -> V_142 , & V_51 -> V_128 ) ;
return 0 ;
}
static int F_83 ( struct V_50 * V_51 , int V_26 )
{
struct V_143 * V_144 ;
V_144 = F_23 ( sizeof( * V_144 ) , V_57 ) ;
if ( ! V_144 )
return - V_58 ;
V_144 -> V_26 = V_26 ;
V_144 -> V_139 = NULL ;
F_82 ( & V_144 -> V_142 , & V_51 -> V_128 ) ;
return 0 ;
}
static void F_84 ( struct V_50 * V_51 )
{
struct V_143 * V_144 ;
while ( ! F_74 ( & V_51 -> V_128 ) ) {
V_144 = F_76 ( & V_51 -> V_128 , struct V_143 , V_142 ) ;
F_78 ( & V_144 -> V_142 ) ;
F_18 ( V_144 -> V_139 ) ;
F_18 ( V_144 ) ;
}
}
static int F_85 ( struct V_50 * V_51 )
{
int V_145 = 0 ;
int V_26 , V_146 ;
char V_147 ;
while ( ( V_147 = F_63 ( V_51 ) ) ) {
if ( V_147 == '"' ) {
V_145 ^= 1 ;
continue;
}
if ( V_145 )
goto V_148;
if ( isspace ( V_147 ) )
continue;
if ( F_67 ( V_51 , V_147 ) ) {
V_26 = F_68 ( V_51 , V_147 ) ;
if ( V_26 == V_138 ) {
F_16 ( V_51 , V_122 , 0 ) ;
return - V_86 ;
}
if ( strlen ( F_80 ( V_51 ) ) ) {
F_81 ( V_51 , F_80 ( V_51 ) ) ;
F_69 ( V_51 ) ;
}
while ( ! F_73 ( V_51 ) ) {
V_146 = F_75 ( V_51 ) ;
if ( ! F_66 ( V_51 , V_146 , V_26 ) ) {
V_146 = F_77 ( V_51 ) ;
F_83 ( V_51 , V_146 ) ;
continue;
}
break;
}
F_71 ( V_51 , V_26 ) ;
continue;
}
if ( V_147 == '(' ) {
F_71 ( V_51 , V_149 ) ;
continue;
}
if ( V_147 == ')' ) {
if ( strlen ( F_80 ( V_51 ) ) ) {
F_81 ( V_51 , F_80 ( V_51 ) ) ;
F_69 ( V_51 ) ;
}
V_146 = F_77 ( V_51 ) ;
while ( V_146 != V_138 ) {
if ( V_146 == V_149 )
break;
F_83 ( V_51 , V_146 ) ;
V_146 = F_77 ( V_51 ) ;
}
if ( V_146 == V_138 ) {
F_16 ( V_51 , V_150 , 0 ) ;
return - V_86 ;
}
continue;
}
V_148:
if ( F_70 ( V_51 , V_147 ) ) {
F_16 ( V_51 , V_151 , 0 ) ;
return - V_86 ;
}
}
if ( strlen ( F_80 ( V_51 ) ) )
F_81 ( V_51 , F_80 ( V_51 ) ) ;
while ( ! F_73 ( V_51 ) ) {
V_146 = F_77 ( V_51 ) ;
if ( V_146 == V_138 )
break;
if ( V_146 == V_149 ) {
F_16 ( V_51 , V_150 , 0 ) ;
return - V_86 ;
}
F_83 ( V_51 , V_146 ) ;
}
return 0 ;
}
static struct V_1 * F_86 ( int V_26 , char * V_152 , char * V_153 )
{
struct V_1 * V_2 ;
V_2 = F_39 ( sizeof( * V_2 ) , V_57 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_78 = F_20 ( V_152 , V_57 ) ;
if ( ! V_2 -> V_78 ) {
F_18 ( V_2 ) ;
return NULL ;
}
strcpy ( V_2 -> V_8 . V_17 , V_153 ) ;
V_2 -> V_8 . V_11 = strlen ( V_2 -> V_8 . V_17 ) ;
V_2 -> V_26 = V_26 ;
return V_2 ;
}
static struct V_1 * F_87 ( int V_26 )
{
struct V_1 * V_2 ;
V_2 = F_39 ( sizeof( * V_2 ) , V_57 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_26 = V_26 ;
return V_2 ;
}
static int F_88 ( struct V_50 * V_51 )
{
int V_154 = 0 , V_155 = 0 ;
struct V_143 * V_144 ;
F_33 (elt, &ps->postfix, list) {
if ( V_144 -> V_26 == V_138 )
continue;
if ( V_144 -> V_26 == V_85 || V_144 -> V_26 == V_37 ) {
V_155 ++ ;
continue;
}
V_154 ++ ;
}
if ( ! V_154 || V_155 >= V_154 ) {
F_16 ( V_51 , V_156 , 0 ) ;
return - V_86 ;
}
return 0 ;
}
static int F_89 ( struct V_50 * V_51 )
{
struct V_143 * V_144 ;
int V_45 = 0 ;
F_33 (elt, &ps->postfix, list) {
if ( V_144 -> V_26 == V_138 )
continue;
V_45 ++ ;
}
return V_45 ;
}
static int F_90 ( struct V_41 * V_42 ,
struct V_1 * V_44 )
{
struct V_1 * V_28 ;
struct V_1 * V_2 ;
enum V_30 V_31 = V_43 ;
int V_157 = 0 ;
int V_46 = 0 ;
int V_158 ;
V_158 = 3 * V_42 -> V_45 ;
V_28 = V_42 -> V_28 ;
if ( ! V_28 )
return - V_86 ;
V_2 = V_44 ;
do {
if ( F_42 ( V_157 ++ > V_158 ) )
return - V_86 ;
switch ( V_31 ) {
case V_43 :
if ( V_2 -> V_47 != V_48 ) {
V_2 = & V_28 [ V_2 -> V_47 ] ;
continue;
}
if ( V_2 == V_44 )
break;
V_2 = F_12 ( V_2 , V_28 ,
V_2 -> V_32 , & V_31 ) ;
continue;
case V_35 :
V_2 = & V_28 [ V_2 -> V_49 ] ;
V_31 = V_43 ;
continue;
case V_34 :
if ( V_2 == V_44 )
break;
V_2 = F_12 ( V_2 , V_28 ,
V_2 -> V_32 , & V_31 ) ;
continue;
}
V_46 = 1 ;
} while ( ! V_46 );
return 0 ;
}
static int F_91 ( struct V_1 * V_28 , struct V_1 * V_44 )
{
struct V_1 * V_2 ;
enum V_30 V_31 = V_43 ;
int V_157 = 0 ;
int V_46 = 0 ;
V_2 = V_44 ;
do {
switch ( V_31 ) {
case V_43 :
if ( V_2 -> V_47 != V_48 ) {
V_2 = & V_28 [ V_2 -> V_47 ] ;
continue;
}
if ( V_2 == V_44 )
return 1 ;
V_157 ++ ;
V_2 = F_12 ( V_2 , V_28 ,
V_2 -> V_32 , & V_31 ) ;
continue;
case V_35 :
V_2 = & V_28 [ V_2 -> V_49 ] ;
V_31 = V_43 ;
continue;
case V_34 :
if ( V_2 == V_44 )
break;
V_2 = F_12 ( V_2 , V_28 ,
V_2 -> V_32 , & V_31 ) ;
continue;
}
V_46 = 1 ;
} while ( ! V_46 );
return V_157 ;
}
static int F_92 ( struct V_1 * V_28 , struct V_1 * V_44 )
{
struct V_1 * V_2 ;
enum V_30 V_31 = V_43 ;
int V_157 = 0 ;
int V_159 ;
int V_46 = 0 ;
V_44 -> V_29 &= ~ V_87 ;
if ( V_44 -> V_47 == V_48 )
return 0 ;
V_159 = F_91 ( V_28 , & V_28 [ V_44 -> V_47 ] ) ;
V_159 += F_91 ( V_28 , & V_28 [ V_44 -> V_49 ] ) ;
V_44 -> V_39 = F_39 ( sizeof( * V_44 -> V_39 ) * V_159 , V_57 ) ;
if ( ! V_44 -> V_39 )
return - V_58 ;
V_44 -> V_38 = V_159 ;
V_2 = V_44 ;
do {
switch ( V_31 ) {
case V_43 :
if ( V_2 -> V_47 != V_48 ) {
V_2 = & V_28 [ V_2 -> V_47 ] ;
continue;
}
if ( F_42 ( V_157 == V_159 ) )
return - V_86 ;
V_2 -> V_29 &= ~ V_87 ;
V_44 -> V_39 [ V_157 ++ ] = V_2 -> V_29 ;
V_2 = F_12 ( V_2 , V_28 ,
V_2 -> V_32 , & V_31 ) ;
continue;
case V_35 :
V_2 = & V_28 [ V_2 -> V_49 ] ;
V_31 = V_43 ;
continue;
case V_34 :
if ( V_2 == V_44 )
break;
V_2 = F_12 ( V_2 , V_28 ,
V_2 -> V_32 , & V_31 ) ;
continue;
}
V_46 = 1 ;
} while ( ! V_46 );
return 0 ;
}
static int F_93 ( struct V_41 * V_42 ,
struct V_1 * V_44 )
{
struct V_1 * V_28 ;
struct V_1 * V_2 ;
enum V_30 V_31 = V_43 ;
int V_46 = 0 ;
int V_52 ;
V_28 = V_42 -> V_28 ;
if ( ! V_28 )
return - V_86 ;
V_2 = V_44 ;
do {
switch ( V_31 ) {
case V_43 :
if ( V_2 -> V_29 & V_87 ) {
V_52 = F_92 ( V_28 , V_2 ) ;
if ( V_52 )
return V_52 ;
} else if ( V_2 -> V_47 != V_48 ) {
V_2 = & V_28 [ V_2 -> V_47 ] ;
continue;
}
if ( V_2 == V_44 )
break;
V_2 = F_12 ( V_2 , V_28 ,
V_2 -> V_32 , & V_31 ) ;
continue;
case V_35 :
V_2 = & V_28 [ V_2 -> V_49 ] ;
V_31 = V_43 ;
continue;
case V_34 :
if ( V_2 == V_44 )
break;
V_2 = F_12 ( V_2 , V_28 ,
V_2 -> V_32 , & V_31 ) ;
continue;
}
V_46 = 1 ;
} while ( ! V_46 );
return 0 ;
}
static int F_94 ( struct V_66 * V_67 ,
struct V_41 * V_42 ,
struct V_50 * V_51 ,
char * V_56 ,
bool V_114 )
{
char * V_152 = NULL , * V_153 = NULL ;
struct V_1 * V_2 ;
struct V_1 * V_44 ;
struct V_143 * V_144 ;
struct V_79 V_80 = { } ;
int V_52 ;
int V_45 = 0 ;
V_45 = F_89 ( V_51 ) ;
if ( V_45 >= V_160 ) {
F_16 ( V_51 , V_92 , 0 ) ;
return - V_81 ;
}
V_52 = F_88 ( V_51 ) ;
if ( V_52 )
return V_52 ;
if ( ! V_114 ) {
V_52 = F_38 ( & V_80 , V_45 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_50 ( V_42 , V_45 ) ;
if ( V_52 )
goto V_161;
}
V_45 = 0 ;
F_33 (elt, &ps->postfix, list) {
if ( V_144 -> V_26 == V_138 ) {
if ( ! V_152 )
V_152 = V_144 -> V_139 ;
else if ( ! V_153 )
V_153 = V_144 -> V_139 ;
else {
F_16 ( V_51 , V_162 , 0 ) ;
V_52 = - V_86 ;
goto V_161;
}
continue;
}
if ( F_42 ( V_45 ++ == V_160 ) ) {
F_16 ( V_51 , V_92 , 0 ) ;
V_52 = - V_81 ;
goto V_161;
}
if ( V_144 -> V_26 == V_85 || V_144 -> V_26 == V_37 ) {
V_2 = F_87 ( V_144 -> V_26 ) ;
goto V_163;
}
if ( ! V_152 || ! V_153 ) {
F_16 ( V_51 , V_164 , 0 ) ;
V_52 = - V_86 ;
goto V_161;
}
V_2 = F_86 ( V_144 -> V_26 , V_152 , V_153 ) ;
V_163:
if ( ! V_2 ) {
V_52 = - V_58 ;
goto V_161;
}
V_52 = F_58 ( V_51 , V_67 , V_42 , V_2 , & V_80 , V_114 ) ;
F_36 ( V_2 ) ;
if ( V_52 )
goto V_161;
V_152 = V_153 = NULL ;
}
if ( ! V_114 ) {
V_2 = F_43 ( & V_80 ) ;
if ( ! V_2 )
return - V_86 ;
V_44 = V_2 ;
V_2 = F_43 ( & V_80 ) ;
if ( F_42 ( V_2 ) ) {
V_52 = - V_86 ;
V_42 -> V_44 = NULL ;
goto V_161;
}
V_52 = F_90 ( V_42 , V_44 ) ;
if ( V_52 )
goto V_161;
V_52 = F_93 ( V_42 , V_44 ) ;
if ( V_52 )
goto V_161;
F_95 () ;
V_42 -> V_44 = V_44 ;
}
V_52 = 0 ;
V_161:
F_40 ( & V_80 ) ;
return V_52 ;
}
static int F_96 ( struct V_71 * system ,
struct V_50 * V_51 ,
char * V_56 )
{
struct V_66 * V_67 ;
struct V_165 * V_166 ;
struct V_165 * V_167 ;
F_97 ( V_165 ) ;
bool V_161 = true ;
int V_52 ;
F_33 (call, &ftrace_events, list) {
if ( strcmp ( V_67 -> V_91 -> system , system -> V_75 ) != 0 )
continue;
V_52 = F_94 ( V_67 , NULL , V_51 , V_56 , true ) ;
if ( V_52 )
goto V_161;
}
F_33 (call, &ftrace_events, list) {
struct V_41 * V_42 ;
if ( strcmp ( V_67 -> V_91 -> system , system -> V_75 ) != 0 )
continue;
V_166 = F_39 ( sizeof( * V_166 ) , V_57 ) ;
if ( ! V_166 )
goto V_168;
F_82 ( & V_166 -> V_142 , & V_165 ) ;
V_166 -> V_42 = F_49 () ;
if ( ! V_166 -> V_42 )
goto V_168;
V_42 = V_166 -> V_42 ;
V_52 = F_19 ( V_42 , V_56 ) ;
if ( V_52 )
goto V_168;
V_52 = F_94 ( V_67 , V_42 , V_51 , V_56 , false ) ;
if ( V_52 ) {
F_46 ( V_67 ) ;
F_16 ( V_51 , V_169 , 0 ) ;
F_24 ( V_51 , V_42 ) ;
} else
V_67 -> V_89 |= V_90 ;
V_42 = V_67 -> V_42 ;
V_67 -> V_42 = V_166 -> V_42 ;
V_166 -> V_42 = V_42 ;
V_161 = false ;
}
if ( V_161 )
goto V_161;
F_98 () ;
F_99 (filter_item, tmp, &filter_list, list) {
F_47 ( V_166 -> V_42 ) ;
F_78 ( & V_166 -> V_142 ) ;
F_18 ( V_166 ) ;
}
return 0 ;
V_161:
F_99 (filter_item, tmp, &filter_list, list) {
F_78 ( & V_166 -> V_142 ) ;
F_18 ( V_166 ) ;
}
F_16 ( V_51 , V_169 , 0 ) ;
return - V_86 ;
V_168:
if ( ! V_161 )
F_98 () ;
F_99 (filter_item, tmp, &filter_list, list) {
F_47 ( V_166 -> V_42 ) ;
F_78 ( & V_166 -> V_142 ) ;
F_18 ( V_166 ) ;
}
return - V_58 ;
}
int F_100 ( struct V_66 * V_67 , char * V_56 )
{
struct V_50 * V_51 ;
struct V_41 * V_42 ;
struct V_41 * V_167 ;
int V_52 = 0 ;
F_28 ( & V_70 ) ;
if ( ! strcmp ( F_101 ( V_56 ) , L_8 ) ) {
F_46 ( V_67 ) ;
V_42 = V_67 -> V_42 ;
if ( ! V_42 )
goto V_170;
V_67 -> V_42 = NULL ;
F_98 () ;
F_47 ( V_42 ) ;
goto V_170;
}
V_52 = - V_58 ;
V_51 = F_39 ( sizeof( * V_51 ) , V_57 ) ;
if ( ! V_51 )
goto V_170;
V_42 = F_49 () ;
if ( ! V_42 ) {
F_18 ( V_51 ) ;
goto V_170;
}
F_19 ( V_42 , V_56 ) ;
F_61 ( V_51 , V_171 , V_56 ) ;
V_52 = F_85 ( V_51 ) ;
if ( V_52 ) {
F_24 ( V_51 , V_42 ) ;
goto V_172;
}
V_52 = F_94 ( V_67 , V_42 , V_51 , V_56 , false ) ;
if ( V_52 ) {
F_46 ( V_67 ) ;
F_24 ( V_51 , V_42 ) ;
} else
V_67 -> V_89 |= V_90 ;
V_172:
V_167 = V_67 -> V_42 ;
V_67 -> V_42 = V_42 ;
if ( V_167 ) {
F_98 () ;
F_47 ( V_167 ) ;
}
F_79 ( V_51 ) ;
F_84 ( V_51 ) ;
F_18 ( V_51 ) ;
V_170:
F_30 ( & V_70 ) ;
return V_52 ;
}
int F_102 ( struct V_71 * system ,
char * V_56 )
{
struct V_50 * V_51 ;
struct V_41 * V_42 ;
int V_52 = 0 ;
F_28 ( & V_70 ) ;
if ( ! system -> V_173 ) {
V_52 = - V_174 ;
goto V_170;
}
if ( ! strcmp ( F_101 ( V_56 ) , L_8 ) ) {
F_51 ( system ) ;
F_17 ( system -> V_42 ) ;
V_42 = system -> V_42 ;
system -> V_42 = NULL ;
F_98 () ;
F_52 ( system ) ;
F_47 ( V_42 ) ;
goto V_170;
}
V_52 = - V_58 ;
V_51 = F_39 ( sizeof( * V_51 ) , V_57 ) ;
if ( ! V_51 )
goto V_170;
V_42 = F_49 () ;
if ( ! V_42 )
goto V_172;
F_19 ( V_42 , V_56 ) ;
F_47 ( system -> V_42 ) ;
system -> V_42 = V_42 ;
F_61 ( V_51 , V_171 , V_56 ) ;
V_52 = F_85 ( V_51 ) ;
if ( V_52 ) {
F_24 ( V_51 , system -> V_42 ) ;
goto V_172;
}
V_52 = F_96 ( system , V_51 , V_56 ) ;
if ( V_52 )
F_24 ( V_51 , system -> V_42 ) ;
V_172:
F_79 ( V_51 ) ;
F_84 ( V_51 ) ;
F_18 ( V_51 ) ;
V_170:
F_30 ( & V_70 ) ;
return V_52 ;
}
void F_103 ( struct V_175 * V_3 )
{
struct V_41 * V_42 = V_3 -> V_42 ;
V_3 -> V_42 = NULL ;
F_47 ( V_42 ) ;
}
int F_104 ( struct V_175 * V_3 , int V_176 ,
char * V_177 )
{
int V_52 ;
struct V_41 * V_42 ;
struct V_50 * V_51 ;
struct V_66 * V_67 = NULL ;
F_28 ( & V_70 ) ;
F_33 (call, &ftrace_events, list) {
if ( V_67 -> V_3 . type == V_176 )
break;
}
V_52 = - V_86 ;
if ( & V_67 -> V_142 == & V_178 )
goto V_170;
V_52 = - V_179 ;
if ( V_3 -> V_42 )
goto V_170;
V_42 = F_49 () ;
if ( ! V_42 ) {
V_52 = F_105 ( V_42 ) ;
goto V_170;
}
V_52 = - V_58 ;
V_51 = F_39 ( sizeof( * V_51 ) , V_57 ) ;
if ( ! V_51 )
goto V_180;
F_61 ( V_51 , V_171 , V_177 ) ;
V_52 = F_85 ( V_51 ) ;
if ( V_52 )
goto V_181;
V_52 = F_94 ( V_67 , V_42 , V_51 , V_177 , false ) ;
if ( ! V_52 )
V_3 -> V_42 = V_42 ;
V_181:
F_79 ( V_51 ) ;
F_84 ( V_51 ) ;
F_18 ( V_51 ) ;
V_180:
if ( V_52 )
F_47 ( V_42 ) ;
V_170:
F_30 ( & V_70 ) ;
return V_52 ;
}
