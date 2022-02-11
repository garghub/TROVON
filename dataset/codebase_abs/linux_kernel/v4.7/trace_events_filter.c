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
int V_15 , V_6 ;
int V_7 = 0 ;
V_15 = F_5 () ;
V_6 = V_2 -> V_16 ;
switch ( V_2 -> V_17 ) {
case V_18 :
V_7 = V_15 == V_6 ;
break;
case V_19 :
V_7 = V_15 < V_6 ;
break;
case V_20 :
V_7 = V_15 <= V_6 ;
break;
case V_21 :
V_7 = V_15 > V_6 ;
break;
case V_22 :
V_7 = V_15 >= V_6 ;
break;
default:
break;
}
return ! ! V_7 == ! V_2 -> V_10 ;
}
static int F_6 ( struct V_1 * V_2 , void * V_3 )
{
int V_6 , V_7 ;
V_6 = V_2 -> V_8 . V_7 ( V_23 -> V_24 , & V_2 -> V_8 ,
V_2 -> V_8 . V_9 ) ;
V_7 = V_6 ^ V_2 -> V_10 ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , void * V_3 )
{
return 0 ;
}
static int F_8 ( char * V_25 , struct V_8 * V_26 , int V_11 )
{
if ( strncmp ( V_25 , V_26 -> V_27 , V_11 ) == 0 )
return 1 ;
return 0 ;
}
static int F_9 ( char * V_25 , struct V_8 * V_26 , int V_11 )
{
if ( strncmp ( V_25 , V_26 -> V_27 , V_26 -> V_11 ) == 0 )
return 1 ;
return 0 ;
}
static int F_10 ( char * V_25 , struct V_8 * V_26 , int V_11 )
{
if ( F_11 ( V_25 , V_26 -> V_27 , V_11 ) )
return 1 ;
return 0 ;
}
static int F_12 ( char * V_25 , struct V_8 * V_26 , int V_11 )
{
int strlen = V_11 - 1 ;
if ( strlen >= V_26 -> V_11 &&
memcmp ( V_25 + strlen - V_26 -> V_11 , V_26 -> V_27 , V_26 -> V_11 ) == 0 )
return 1 ;
return 0 ;
}
enum V_28 F_13 ( char * V_29 , int V_11 , char * * V_30 , int * V_10 )
{
int type = V_31 ;
int V_32 ;
if ( V_29 [ 0 ] == '!' ) {
* V_10 = 1 ;
V_29 ++ ;
V_11 -- ;
} else
* V_10 = 0 ;
* V_30 = V_29 ;
for ( V_32 = 0 ; V_32 < V_11 ; V_32 ++ ) {
if ( V_29 [ V_32 ] == '*' ) {
if ( ! V_32 ) {
* V_30 = V_29 + 1 ;
type = V_33 ;
} else {
if ( type == V_33 )
type = V_34 ;
else
type = V_35 ;
V_29 [ V_32 ] = 0 ;
break;
}
}
}
return type ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_26 = & V_2 -> V_8 ;
char * V_30 ;
enum V_28 type = V_31 ;
int V_10 = 0 ;
if ( V_2 -> V_17 == V_36 ) {
type = F_13 ( V_26 -> V_27 , V_26 -> V_11 , & V_30 , & V_10 ) ;
V_26 -> V_11 = strlen ( V_30 ) ;
memmove ( V_26 -> V_27 , V_30 , V_26 -> V_11 + 1 ) ;
}
switch ( type ) {
case V_31 :
V_26 -> V_7 = F_8 ;
break;
case V_35 :
V_26 -> V_7 = F_9 ;
break;
case V_34 :
V_26 -> V_7 = F_10 ;
break;
case V_33 :
V_26 -> V_7 = F_12 ;
break;
}
V_2 -> V_10 ^= V_10 ;
}
static struct V_1 *
F_15 ( struct V_1 * V_2 , struct V_1 * V_37 ,
int V_38 , enum V_39 * V_40 )
{
if ( V_2 -> V_41 & V_42 )
* V_40 = V_43 ;
else
* V_40 = V_44 ;
V_2 = & V_37 [ V_2 -> V_41 & ~ V_42 ] ;
return V_2 ;
}
static int F_16 ( struct V_1 * V_37 ,
struct V_1 * V_45 ,
T_2 V_46 , void * V_47 )
{
struct V_1 * V_2 = V_45 ;
enum V_39 V_40 = V_48 ;
int V_49 = 0 ;
if ( ! V_37 )
return - V_50 ;
do {
int V_51 = 0 , V_52 ;
V_52 = V_46 ( V_40 , V_2 , & V_51 , V_47 ) ;
if ( V_52 == V_53 )
return V_51 ;
if ( V_52 == V_54 )
goto V_55;
switch ( V_40 ) {
case V_48 :
if ( V_2 -> V_56 != V_57 ) {
V_2 = & V_37 [ V_2 -> V_56 ] ;
continue;
}
goto V_55;
case V_44 :
V_2 = & V_37 [ V_2 -> V_58 ] ;
V_40 = V_48 ;
continue;
case V_43 :
V_55:
if ( V_2 == V_45 )
break;
V_2 = F_15 ( V_2 , V_37 ,
V_2 -> V_41 ,
& V_40 ) ;
continue;
}
V_49 = 1 ;
} while ( ! V_49 );
return 0 ;
}
static int F_17 ( struct V_1 * V_37 ,
struct V_1 * V_17 , void * V_59 )
{
struct V_1 * V_2 ;
int V_7 = 0 ;
int type ;
int V_32 ;
type = V_17 -> V_17 == V_60 ;
for ( V_32 = 0 ; V_32 < V_17 -> V_16 ; V_32 ++ ) {
V_2 = & V_37 [ V_17 -> V_61 [ V_32 ] ] ;
if ( ! F_18 ( ! V_2 -> V_62 ) )
V_7 = V_2 -> V_62 ( V_2 , V_59 ) ;
if ( ! ! V_7 == type )
break;
}
return ! ! V_7 == ! V_17 -> V_10 ;
}
static int F_19 ( enum V_39 V_40 , struct V_1 * V_2 ,
int * V_51 , void * V_47 )
{
struct V_63 * V_64 = V_47 ;
* V_51 = 0 ;
switch ( V_40 ) {
case V_48 :
if ( V_2 -> V_56 != V_57 ) {
if ( ! V_2 -> V_61 )
return V_65 ;
V_64 -> V_7 = F_17 ( V_64 -> V_37 , V_2 , V_64 -> V_59 ) ;
} else {
if ( ! F_18 ( ! V_2 -> V_62 ) )
V_64 -> V_7 = V_2 -> V_62 ( V_2 , V_64 -> V_59 ) ;
}
return V_54 ;
case V_44 :
if ( ! ! V_64 -> V_7 == ( V_2 -> V_17 == V_60 ) )
return V_54 ;
break;
case V_43 :
break;
}
return V_65 ;
}
int F_20 ( struct V_66 * V_67 , void * V_59 )
{
struct V_1 * V_37 ;
struct V_1 * V_45 ;
struct V_63 V_47 = {
. V_7 = - 1 ,
. V_59 = V_59 ,
} ;
int V_68 , V_52 ;
if ( ! V_67 )
return 1 ;
V_68 = V_67 -> V_68 ;
if ( ! V_68 )
return 1 ;
V_45 = F_21 ( V_67 -> V_45 ) ;
if ( ! V_45 )
return 1 ;
V_47 . V_37 = V_37 = F_21 ( V_67 -> V_37 ) ;
V_52 = F_16 ( V_37 , V_45 , F_19 , & V_47 ) ;
F_22 ( V_52 ) ;
return V_47 . V_7 ;
}
static void F_23 ( struct V_69 * V_70 , int V_51 , int V_71 )
{
V_70 -> V_72 = V_51 ;
V_70 -> V_73 = V_71 ;
}
static void F_24 ( struct V_66 * V_67 )
{
if ( ! V_67 )
return;
F_25 ( V_67 -> V_74 ) ;
V_67 -> V_74 = NULL ;
}
static int F_26 ( struct V_66 * V_67 ,
char * V_74 )
{
F_25 ( V_67 -> V_74 ) ;
V_67 -> V_74 = F_27 ( V_74 , V_75 ) ;
if ( ! V_67 -> V_74 )
return - V_76 ;
return 0 ;
}
static int F_28 ( struct V_66 * V_67 ,
char * string )
{
int V_77 ;
char * V_78 ;
F_29 ( ! V_67 -> V_74 ) ;
V_77 = strlen ( V_67 -> V_74 ) + strlen ( string ) + 1 ;
V_78 = F_30 ( V_77 , V_75 ) ;
if ( ! V_78 )
return - V_76 ;
strcpy ( V_78 , V_67 -> V_74 ) ;
strcat ( V_78 , string ) ;
F_25 ( V_67 -> V_74 ) ;
V_67 -> V_74 = V_78 ;
return 0 ;
}
static void F_31 ( struct V_69 * V_70 ,
struct V_66 * V_67 )
{
int V_71 = V_70 -> V_73 ;
char * V_79 , * V_80 ;
V_79 = ( char * ) F_32 ( V_81 ) ;
if ( ! V_79 )
return;
F_28 ( V_67 , L_1 ) ;
memset ( V_79 , ' ' , V_82 ) ;
if ( V_71 > V_82 - 128 )
V_71 = 0 ;
V_79 [ V_71 ] = '^' ;
V_80 = & V_79 [ V_71 ] + 1 ;
sprintf ( V_80 , L_2 , V_83 [ V_70 -> V_72 ] ) ;
F_28 ( V_67 , V_79 ) ;
F_33 ( ( unsigned long ) V_79 ) ;
}
static inline struct V_66 * V_66 ( struct V_84 * V_85 )
{
return V_85 -> V_67 ;
}
void F_34 ( struct V_84 * V_85 , struct V_86 * V_87 )
{
struct V_66 * V_67 = V_66 ( V_85 ) ;
if ( V_67 && V_67 -> V_74 )
F_35 ( V_87 , L_3 , V_67 -> V_74 ) ;
else
F_36 ( V_87 , L_4 ) ;
}
void F_37 ( struct V_88 * system ,
struct V_86 * V_87 )
{
struct V_66 * V_67 ;
F_38 ( & V_89 ) ;
V_67 = system -> V_67 ;
if ( V_67 && V_67 -> V_74 )
F_35 ( V_87 , L_3 , V_67 -> V_74 ) ;
else
F_36 ( V_87 , V_90 L_1 ) ;
F_39 ( & V_89 ) ;
}
static int F_40 ( struct V_91 * V_92 , int V_68 )
{
V_92 -> V_37 = F_41 ( V_68 + 1 , sizeof( * V_92 -> V_37 ) , V_75 ) ;
if ( ! V_92 -> V_37 )
return - V_76 ;
V_92 -> V_38 = V_68 ;
return 0 ;
}
static void F_42 ( struct V_91 * V_92 )
{
F_25 ( V_92 -> V_37 ) ;
V_92 -> V_38 = 0 ;
}
static int F_43 ( struct V_91 * V_92 ,
struct V_1 * V_2 )
{
int V_38 = V_92 -> V_38 ;
if ( F_22 ( V_38 == 0 ) )
return - V_93 ;
V_92 -> V_37 [ -- V_38 ] = V_2 ;
V_92 -> V_38 = V_38 ;
return 0 ;
}
static struct V_1 *
F_44 ( struct V_91 * V_92 )
{
struct V_1 * V_2 ;
int V_38 = V_92 -> V_38 ;
V_2 = V_92 -> V_37 [ V_38 ++ ] ;
if ( ! V_2 )
return NULL ;
V_92 -> V_38 = V_38 ;
return V_2 ;
}
static int F_45 ( struct V_66 * V_67 ,
int V_94 ,
struct V_91 * V_92 ,
struct V_1 * V_95 )
{
struct V_1 * V_96 = & V_67 -> V_37 [ V_94 ] ;
struct V_1 * V_56 ;
struct V_1 * V_58 ;
* V_96 = * V_95 ;
V_96 -> V_38 = V_94 ;
if ( V_96 -> V_17 == V_60 || V_96 -> V_17 == V_97 ) {
V_58 = F_44 ( V_92 ) ;
V_56 = F_44 ( V_92 ) ;
if ( ! V_56 || ! V_58 )
return - V_50 ;
if ( V_56 -> V_38 & V_98 &&
( ( V_56 -> V_17 == V_96 -> V_17 && ! V_56 -> V_10 ) ||
V_56 -> V_56 == V_57 ) &&
V_58 -> V_38 & V_98 &&
( ( V_58 -> V_17 == V_96 -> V_17 && ! V_58 -> V_10 ) ||
V_58 -> V_56 == V_57 ) )
V_96 -> V_38 |= V_98 ;
V_96 -> V_56 = V_56 -> V_38 & ~ V_98 ;
V_96 -> V_58 = V_58 -> V_38 & ~ V_98 ;
V_56 -> V_41 = V_96 -> V_38 & ~ V_98 ;
V_58 -> V_41 = V_96 -> V_38 | V_42 ;
} else {
V_96 -> V_56 = V_57 ;
V_96 -> V_38 |= V_98 ;
}
return F_43 ( V_92 , V_96 ) ;
}
static void F_46 ( struct V_66 * V_67 )
{
int V_32 ;
if ( V_67 -> V_37 ) {
for ( V_32 = 0 ; V_32 < V_67 -> V_68 ; V_32 ++ )
F_25 ( V_67 -> V_37 [ V_32 ] . V_61 ) ;
F_25 ( V_67 -> V_37 ) ;
V_67 -> V_37 = NULL ;
}
V_67 -> V_99 = 0 ;
V_67 -> V_68 = 0 ;
}
static void F_47 ( struct V_84 * V_85 )
{
unsigned long V_100 = V_85 -> V_101 ;
V_85 -> V_101 &= ~ V_102 ;
if ( V_100 != V_85 -> V_101 )
F_48 () ;
}
static void F_49 ( struct V_66 * V_67 )
{
if ( ! V_67 )
return;
F_46 ( V_67 ) ;
F_25 ( V_67 -> V_74 ) ;
F_25 ( V_67 ) ;
}
void F_50 ( struct V_66 * V_67 )
{
F_49 ( V_67 ) ;
}
static struct V_66 * F_51 ( void )
{
struct V_66 * V_67 ;
V_67 = F_52 ( sizeof( * V_67 ) , V_75 ) ;
return V_67 ;
}
static int F_53 ( struct V_66 * V_67 , int V_68 )
{
struct V_1 * V_2 ;
int V_32 ;
if ( V_67 -> V_37 )
F_46 ( V_67 ) ;
V_67 -> V_37 = F_41 ( V_68 , sizeof( * V_67 -> V_37 ) , V_75 ) ;
if ( ! V_67 -> V_37 )
return - V_76 ;
V_67 -> V_99 = V_68 ;
V_67 -> V_68 = 0 ;
for ( V_32 = 0 ; V_32 < V_68 ; V_32 ++ ) {
V_2 = & V_67 -> V_37 [ V_32 ] ;
V_2 -> V_62 = F_7 ;
}
return 0 ;
}
static inline void F_54 ( struct V_84 * V_85 )
{
F_47 ( V_85 ) ;
F_24 ( V_85 -> V_67 ) ;
}
static void F_55 ( struct V_103 * V_104 ,
struct V_105 * V_106 )
{
struct V_84 * V_85 ;
F_56 (file, &tr->events, list) {
if ( V_85 -> system != V_104 )
continue;
F_54 ( V_85 ) ;
}
}
static inline void F_57 ( struct V_84 * V_85 )
{
F_49 ( V_85 -> V_67 ) ;
V_85 -> V_67 = NULL ;
}
static void F_58 ( struct V_103 * V_104 ,
struct V_105 * V_106 )
{
struct V_84 * V_85 ;
F_56 (file, &tr->events, list) {
if ( V_85 -> system != V_104 )
continue;
F_57 ( V_85 ) ;
}
}
static int F_59 ( struct V_69 * V_70 ,
struct V_66 * V_67 ,
struct V_1 * V_2 ,
struct V_91 * V_92 )
{
int V_51 ;
if ( F_22 ( V_67 -> V_68 == V_67 -> V_99 ) ) {
F_23 ( V_70 , V_107 , 0 ) ;
return - V_93 ;
}
V_51 = F_45 ( V_67 , V_67 -> V_68 , V_92 , V_2 ) ;
if ( V_51 )
return V_51 ;
V_67 -> V_68 ++ ;
return 0 ;
}
int F_60 ( const char * type )
{
if ( strstr ( type , L_5 ) && strstr ( type , L_6 ) )
return V_108 ;
if ( strchr ( type , '[' ) && strstr ( type , L_6 ) )
return V_109 ;
return V_110 ;
}
static bool F_61 ( struct V_111 * V_112 , int V_17 )
{
if ( F_62 ( V_112 ) &&
( V_17 != V_18 && V_17 != V_113 && V_17 != V_36 ) )
return false ;
if ( ! F_62 ( V_112 ) && V_17 == V_36 )
return false ;
return true ;
}
static T_3 F_63 ( int V_17 , int V_114 ,
int V_115 )
{
T_3 V_62 = NULL ;
switch ( V_114 ) {
case 8 :
if ( V_17 == V_18 || V_17 == V_113 )
V_62 = V_116 ;
else if ( V_115 )
V_62 = V_117 ;
else
V_62 = V_118 ;
break;
case 4 :
if ( V_17 == V_18 || V_17 == V_113 )
V_62 = V_119 ;
else if ( V_115 )
V_62 = V_120 ;
else
V_62 = V_121 ;
break;
case 2 :
if ( V_17 == V_18 || V_17 == V_113 )
V_62 = V_122 ;
else if ( V_115 )
V_62 = V_123 ;
else
V_62 = V_124 ;
break;
case 1 :
if ( V_17 == V_18 || V_17 == V_113 )
V_62 = V_125 ;
else if ( V_115 )
V_62 = V_126 ;
else
V_62 = V_127 ;
break;
}
return V_62 ;
}
static int F_64 ( struct V_69 * V_70 ,
struct V_111 * V_112 ,
struct V_1 * V_2 )
{
T_3 V_62 = F_7 ;
unsigned long long V_16 ;
int V_52 ;
V_2 -> V_5 = V_112 -> V_5 ;
if ( ! F_61 ( V_112 , V_2 -> V_17 ) ) {
F_23 ( V_70 , V_128 , 0 ) ;
return - V_50 ;
}
if ( V_112 -> V_129 == V_130 ) {
F_14 ( V_2 ) ;
V_62 = F_6 ;
V_2 -> V_8 . V_9 = V_131 ;
} else if ( F_62 ( V_112 ) ) {
F_14 ( V_2 ) ;
if ( V_112 -> V_129 == V_109 ) {
V_62 = F_1 ;
V_2 -> V_8 . V_9 = V_112 -> V_132 ;
} else if ( V_112 -> V_129 == V_108 )
V_62 = F_3 ;
else
V_62 = F_2 ;
} else if ( F_65 ( V_112 ) ) {
if ( strcmp ( V_112 -> V_133 , L_7 ) ) {
F_23 ( V_70 , V_134 , 0 ) ;
return - V_50 ;
}
} else {
if ( V_112 -> V_135 )
V_52 = F_66 ( V_2 -> V_8 . V_27 , 0 , & V_16 ) ;
else
V_52 = F_67 ( V_2 -> V_8 . V_27 , 0 , & V_16 ) ;
if ( V_52 ) {
F_23 ( V_70 , V_136 , 0 ) ;
return - V_50 ;
}
V_2 -> V_16 = V_16 ;
if ( V_112 -> V_129 == V_137 )
V_62 = F_4 ;
else
V_62 = F_63 ( V_2 -> V_17 , V_112 -> V_132 ,
V_112 -> V_135 ) ;
if ( ! V_62 ) {
F_23 ( V_70 , V_138 , 0 ) ;
return - V_50 ;
}
}
if ( V_2 -> V_17 == V_113 )
V_2 -> V_10 ^= 1 ;
V_2 -> V_62 = V_62 ;
return 0 ;
}
static void F_68 ( struct V_69 * V_70 ,
struct V_139 * V_61 ,
char * V_140 )
{
memset ( V_70 , '\0' , sizeof( * V_70 ) ) ;
V_70 -> V_141 . string = V_140 ;
V_70 -> V_141 . V_142 = strlen ( V_140 ) ;
V_70 -> V_61 = V_61 ;
F_69 ( & V_70 -> V_143 ) ;
F_69 ( & V_70 -> V_144 ) ;
}
static char F_70 ( struct V_69 * V_70 )
{
if ( ! V_70 -> V_141 . V_142 )
return 0 ;
V_70 -> V_141 . V_142 -- ;
return V_70 -> V_141 . string [ V_70 -> V_141 . V_145 ++ ] ;
}
static char F_71 ( struct V_69 * V_70 )
{
if ( V_70 -> V_141 . V_145 == strlen ( V_70 -> V_141 . string ) )
return 0 ;
return V_70 -> V_141 . string [ V_70 -> V_141 . V_145 ] ;
}
static void F_72 ( struct V_69 * V_70 )
{
if ( ! V_70 -> V_141 . V_142 )
return;
V_70 -> V_141 . V_142 -- ;
V_70 -> V_141 . V_145 ++ ;
}
static inline int F_73 ( struct V_69 * V_70 ,
int V_146 , int V_147 )
{
return V_70 -> V_61 [ V_146 ] . V_148 < V_70 -> V_61 [ V_147 ] . V_148 ;
}
static inline int F_74 ( struct V_69 * V_70 , char V_149 )
{
int V_32 ;
for ( V_32 = 0 ; strcmp ( V_70 -> V_61 [ V_32 ] . string , L_8 ) ; V_32 ++ ) {
if ( V_70 -> V_61 [ V_32 ] . string [ 0 ] == V_149 )
return 1 ;
}
return 0 ;
}
static int F_75 ( struct V_69 * V_70 , char V_150 )
{
char V_151 = F_71 ( V_70 ) ;
char V_152 [ 3 ] ;
int V_32 ;
V_152 [ 0 ] = V_150 ;
V_152 [ 1 ] = V_151 ;
V_152 [ 2 ] = '\0' ;
for ( V_32 = 0 ; strcmp ( V_70 -> V_61 [ V_32 ] . string , L_8 ) ; V_32 ++ ) {
if ( ! strcmp ( V_152 , V_70 -> V_61 [ V_32 ] . string ) ) {
F_72 ( V_70 ) ;
return V_70 -> V_61 [ V_32 ] . V_153 ;
}
}
V_152 [ 1 ] = '\0' ;
for ( V_32 = 0 ; strcmp ( V_70 -> V_61 [ V_32 ] . string , L_8 ) ; V_32 ++ ) {
if ( ! strcmp ( V_152 , V_70 -> V_61 [ V_32 ] . string ) )
return V_70 -> V_61 [ V_32 ] . V_153 ;
}
return V_154 ;
}
static inline void F_76 ( struct V_69 * V_70 )
{
memset ( V_70 -> V_155 . string , '\0' , V_156 ) ;
V_70 -> V_155 . V_145 = 0 ;
}
static inline int F_77 ( struct V_69 * V_70 , char V_149 )
{
if ( V_70 -> V_155 . V_145 == V_156 - 1 )
return - V_50 ;
V_70 -> V_155 . string [ V_70 -> V_155 . V_145 ++ ] = V_149 ;
return 0 ;
}
static int F_78 ( struct V_69 * V_70 , int V_17 )
{
struct V_157 * V_157 ;
V_157 = F_30 ( sizeof( * V_157 ) , V_75 ) ;
if ( ! V_157 )
return - V_76 ;
V_157 -> V_17 = V_17 ;
F_79 ( & V_157 -> V_158 , & V_70 -> V_143 ) ;
return 0 ;
}
static int F_80 ( struct V_69 * V_70 )
{
return F_81 ( & V_70 -> V_143 ) ;
}
static int F_82 ( struct V_69 * V_70 )
{
struct V_157 * V_157 ;
if ( F_80 ( V_70 ) )
return V_154 ;
V_157 = F_83 ( & V_70 -> V_143 , struct V_157 , V_158 ) ;
return V_157 -> V_17 ;
}
static int F_84 ( struct V_69 * V_70 )
{
struct V_157 * V_157 ;
int V_17 ;
if ( F_80 ( V_70 ) )
return V_154 ;
V_157 = F_83 ( & V_70 -> V_143 , struct V_157 , V_158 ) ;
V_17 = V_157 -> V_17 ;
F_85 ( & V_157 -> V_158 ) ;
F_25 ( V_157 ) ;
return V_17 ;
}
static void F_86 ( struct V_69 * V_70 )
{
while ( ! F_80 ( V_70 ) )
F_84 ( V_70 ) ;
}
static char * F_87 ( struct V_69 * V_70 )
{
return V_70 -> V_155 . string ;
}
static int F_88 ( struct V_69 * V_70 , char * V_155 )
{
struct V_159 * V_160 ;
V_160 = F_30 ( sizeof( * V_160 ) , V_75 ) ;
if ( ! V_160 )
return - V_76 ;
V_160 -> V_17 = V_154 ;
V_160 -> V_155 = F_27 ( V_155 , V_75 ) ;
if ( ! V_160 -> V_155 ) {
F_25 ( V_160 ) ;
return - V_76 ;
}
F_89 ( & V_160 -> V_158 , & V_70 -> V_144 ) ;
return 0 ;
}
static int F_90 ( struct V_69 * V_70 , int V_17 )
{
struct V_159 * V_160 ;
V_160 = F_30 ( sizeof( * V_160 ) , V_75 ) ;
if ( ! V_160 )
return - V_76 ;
V_160 -> V_17 = V_17 ;
V_160 -> V_155 = NULL ;
F_89 ( & V_160 -> V_158 , & V_70 -> V_144 ) ;
return 0 ;
}
static void F_91 ( struct V_69 * V_70 )
{
struct V_159 * V_160 ;
while ( ! F_81 ( & V_70 -> V_144 ) ) {
V_160 = F_83 ( & V_70 -> V_144 , struct V_159 , V_158 ) ;
F_85 ( & V_160 -> V_158 ) ;
F_25 ( V_160 -> V_155 ) ;
F_25 ( V_160 ) ;
}
}
static int F_92 ( struct V_69 * V_70 )
{
int V_161 = 0 ;
int V_17 , V_162 ;
char V_163 ;
while ( ( V_163 = F_70 ( V_70 ) ) ) {
if ( V_163 == '"' ) {
V_161 ^= 1 ;
continue;
}
if ( V_161 )
goto V_164;
if ( isspace ( V_163 ) )
continue;
if ( F_74 ( V_70 , V_163 ) ) {
V_17 = F_75 ( V_70 , V_163 ) ;
if ( V_17 == V_154 ) {
F_23 ( V_70 , V_138 , 0 ) ;
return - V_50 ;
}
if ( strlen ( F_87 ( V_70 ) ) ) {
F_88 ( V_70 , F_87 ( V_70 ) ) ;
F_76 ( V_70 ) ;
}
while ( ! F_80 ( V_70 ) ) {
V_162 = F_82 ( V_70 ) ;
if ( ! F_73 ( V_70 , V_162 , V_17 ) ) {
V_162 = F_84 ( V_70 ) ;
F_90 ( V_70 , V_162 ) ;
continue;
}
break;
}
F_78 ( V_70 , V_17 ) ;
continue;
}
if ( V_163 == '(' ) {
F_78 ( V_70 , V_165 ) ;
continue;
}
if ( V_163 == ')' ) {
if ( strlen ( F_87 ( V_70 ) ) ) {
F_88 ( V_70 , F_87 ( V_70 ) ) ;
F_76 ( V_70 ) ;
}
V_162 = F_84 ( V_70 ) ;
while ( V_162 != V_154 ) {
if ( V_162 == V_165 )
break;
F_90 ( V_70 , V_162 ) ;
V_162 = F_84 ( V_70 ) ;
}
if ( V_162 == V_154 ) {
F_23 ( V_70 , V_166 , 0 ) ;
return - V_50 ;
}
continue;
}
V_164:
if ( F_77 ( V_70 , V_163 ) ) {
F_23 ( V_70 , V_167 , 0 ) ;
return - V_50 ;
}
}
if ( strlen ( F_87 ( V_70 ) ) )
F_88 ( V_70 , F_87 ( V_70 ) ) ;
while ( ! F_80 ( V_70 ) ) {
V_162 = F_84 ( V_70 ) ;
if ( V_162 == V_154 )
break;
if ( V_162 == V_165 ) {
F_23 ( V_70 , V_166 , 0 ) ;
return - V_50 ;
}
F_90 ( V_70 , V_162 ) ;
}
return 0 ;
}
static struct V_1 * F_93 ( struct V_69 * V_70 ,
struct V_168 * V_169 ,
int V_17 , char * V_170 , char * V_171 )
{
struct V_111 * V_112 ;
static struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_17 = V_17 ;
if ( V_17 == V_97 || V_17 == V_60 )
return & V_2 ;
if ( ! V_170 || ! V_171 ) {
F_23 ( V_70 , V_172 , 0 ) ;
return NULL ;
}
V_112 = F_94 ( V_169 , V_170 ) ;
if ( ! V_112 ) {
F_23 ( V_70 , V_173 , 0 ) ;
return NULL ;
}
strcpy ( V_2 . V_8 . V_27 , V_171 ) ;
V_2 . V_8 . V_11 = strlen ( V_2 . V_8 . V_27 ) ;
V_2 . V_112 = V_112 ;
return F_64 ( V_70 , V_112 , & V_2 ) ? NULL : & V_2 ;
}
static int F_95 ( struct V_69 * V_70 )
{
int V_174 = 0 , V_175 = 0 ;
struct V_159 * V_160 ;
int V_142 = 0 ;
F_56 (elt, &ps->postfix, list) {
if ( V_160 -> V_17 == V_154 ) {
V_142 ++ ;
continue;
}
if ( V_160 -> V_17 == V_97 || V_160 -> V_17 == V_60 ) {
V_175 ++ ;
V_142 -- ;
continue;
}
if ( V_160 -> V_17 != V_176 )
V_142 -- ;
V_174 ++ ;
if ( V_142 < 0 )
break;
}
if ( V_142 != 1 || ! V_174 || V_175 >= V_174 ) {
F_23 ( V_70 , V_177 , 0 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_96 ( struct V_69 * V_70 )
{
struct V_159 * V_160 ;
int V_68 = 0 ;
F_56 (elt, &ps->postfix, list) {
if ( V_160 -> V_17 == V_154 )
continue;
V_68 ++ ;
}
return V_68 ;
}
static int F_97 ( enum V_39 V_40 , struct V_1 * V_2 ,
int * V_51 , void * V_47 )
{
struct V_178 * V_64 = V_47 ;
if ( F_22 ( V_64 -> V_179 ++ > V_64 -> V_180 ) ) {
* V_51 = - V_50 ;
return V_53 ;
}
return V_65 ;
}
static int F_98 ( struct V_66 * V_67 ,
struct V_1 * V_45 )
{
struct V_178 V_47 = {
. V_180 = 3 * V_67 -> V_68 ,
. V_179 = 0 ,
} ;
return F_16 ( V_67 -> V_37 , V_45 ,
F_97 , & V_47 ) ;
}
static int F_99 ( enum V_39 V_40 , struct V_1 * V_2 ,
int * V_51 , void * V_47 )
{
int * V_179 = V_47 ;
if ( ( V_40 == V_48 ) &&
( V_2 -> V_56 == V_57 ) )
( * V_179 ) ++ ;
return V_65 ;
}
static int F_100 ( struct V_1 * V_37 , struct V_1 * V_45 )
{
int V_179 = 0 , V_52 ;
V_52 = F_16 ( V_37 , V_45 , F_99 , & V_179 ) ;
F_22 ( V_52 ) ;
return V_179 ;
}
static int F_101 ( enum V_39 V_40 , struct V_1 * V_2 ,
int * V_51 , void * V_47 )
{
struct V_181 * V_64 = V_47 ;
struct V_1 * V_45 = V_64 -> V_45 ;
if ( V_40 != V_48 )
return V_65 ;
if ( V_2 -> V_56 != V_57 )
return V_65 ;
if ( F_22 ( V_64 -> V_179 == V_64 -> V_182 ) ) {
* V_51 = - V_50 ;
return V_53 ;
}
V_2 -> V_38 &= ~ V_98 ;
V_45 -> V_61 [ V_64 -> V_179 ++ ] = V_2 -> V_38 ;
return V_65 ;
}
static int F_102 ( struct V_1 * V_37 , struct V_1 * V_45 )
{
struct V_181 V_47 = {
. V_45 = V_45 ,
. V_179 = 0 ,
} ;
int V_182 ;
V_45 -> V_38 &= ~ V_98 ;
if ( V_45 -> V_56 == V_57 )
return 0 ;
V_182 = F_100 ( V_37 , & V_37 [ V_45 -> V_56 ] ) ;
V_182 += F_100 ( V_37 , & V_37 [ V_45 -> V_58 ] ) ;
V_45 -> V_61 = F_41 ( V_182 , sizeof( * V_45 -> V_61 ) , V_75 ) ;
if ( ! V_45 -> V_61 )
return - V_76 ;
V_45 -> V_16 = V_182 ;
V_47 . V_182 = V_182 ;
return F_16 ( V_37 , V_45 , F_101 , & V_47 ) ;
}
static int F_103 ( enum V_39 V_40 , struct V_1 * V_2 ,
int * V_51 , void * V_47 )
{
struct V_1 * V_37 = V_47 ;
if ( V_40 != V_48 )
return V_65 ;
if ( ! ( V_2 -> V_38 & V_98 ) )
return V_65 ;
* V_51 = F_102 ( V_37 , V_2 ) ;
if ( * V_51 )
return V_53 ;
return V_54 ;
}
static int F_104 ( struct V_66 * V_67 ,
struct V_1 * V_45 )
{
return F_16 ( V_67 -> V_37 , V_45 , F_103 ,
V_67 -> V_37 ) ;
}
static int F_105 ( struct V_168 * V_169 ,
struct V_66 * V_67 ,
struct V_69 * V_70 ,
bool V_183 )
{
char * V_170 = NULL , * V_171 = NULL ;
struct V_1 * V_2 ;
struct V_1 * V_45 ;
struct V_159 * V_160 ;
struct V_91 V_92 = { } ;
int V_51 ;
int V_68 = 0 ;
V_68 = F_96 ( V_70 ) ;
if ( V_68 >= V_184 ) {
F_23 ( V_70 , V_107 , 0 ) ;
return - V_93 ;
}
V_51 = F_95 ( V_70 ) ;
if ( V_51 )
return V_51 ;
if ( ! V_183 ) {
V_51 = F_40 ( & V_92 , V_68 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_53 ( V_67 , V_68 ) ;
if ( V_51 )
goto V_185;
}
V_68 = 0 ;
F_56 (elt, &ps->postfix, list) {
if ( V_160 -> V_17 == V_154 ) {
if ( ! V_170 )
V_170 = V_160 -> V_155 ;
else if ( ! V_171 )
V_171 = V_160 -> V_155 ;
else {
F_23 ( V_70 , V_186 , 0 ) ;
V_51 = - V_50 ;
goto V_185;
}
continue;
}
if ( V_160 -> V_17 == V_176 ) {
if ( ! V_68 || V_170 || V_171 ) {
F_23 ( V_70 , V_187 , 0 ) ;
V_51 = - V_50 ;
goto V_185;
}
if ( ! V_183 )
V_67 -> V_37 [ V_68 - 1 ] . V_10 ^= 1 ;
continue;
}
if ( F_22 ( V_68 ++ == V_184 ) ) {
F_23 ( V_70 , V_107 , 0 ) ;
V_51 = - V_93 ;
goto V_185;
}
V_2 = F_93 ( V_70 , V_169 , V_160 -> V_17 , V_170 , V_171 ) ;
if ( ! V_2 ) {
V_51 = - V_50 ;
goto V_185;
}
if ( ! V_183 ) {
V_51 = F_59 ( V_70 , V_67 , V_2 , & V_92 ) ;
if ( V_51 )
goto V_185;
}
V_170 = V_171 = NULL ;
}
if ( ! V_183 ) {
V_2 = F_44 ( & V_92 ) ;
if ( ! V_2 )
return - V_50 ;
V_45 = V_2 ;
V_2 = F_44 ( & V_92 ) ;
if ( F_22 ( V_2 ) ) {
V_51 = - V_50 ;
V_67 -> V_45 = NULL ;
goto V_185;
}
V_51 = F_98 ( V_67 , V_45 ) ;
if ( V_51 )
goto V_185;
V_51 = F_104 ( V_67 , V_45 ) ;
if ( V_51 )
goto V_185;
F_106 () ;
V_67 -> V_45 = V_45 ;
}
V_51 = 0 ;
V_185:
F_42 ( & V_92 ) ;
return V_51 ;
}
static inline void F_107 ( struct V_84 * V_85 )
{
unsigned long V_100 = V_85 -> V_101 ;
V_85 -> V_101 |= V_102 ;
if ( V_100 != V_85 -> V_101 )
F_108 () ;
}
static inline void F_109 ( struct V_84 * V_85 ,
struct V_66 * V_67 )
{
F_110 ( V_85 -> V_67 , V_67 ) ;
}
static inline void F_111 ( struct V_84 * V_85 )
{
F_112 ( V_85 -> V_67 , NULL ) ;
}
static inline void
F_113 ( struct V_84 * V_85 )
{
V_85 -> V_101 |= V_188 ;
}
static inline void
F_114 ( struct V_84 * V_85 )
{
V_85 -> V_101 &= ~ V_188 ;
}
static inline bool
F_115 ( struct V_84 * V_85 )
{
if ( V_85 -> V_101 & V_188 )
return true ;
return false ;
}
static int F_116 ( struct V_103 * V_104 ,
struct V_105 * V_106 ,
struct V_69 * V_70 ,
char * V_74 )
{
struct V_84 * V_85 ;
struct V_189 * V_190 ;
struct V_189 * V_191 ;
F_117 ( V_189 ) ;
bool V_185 = true ;
int V_51 ;
F_56 (file, &tr->events, list) {
if ( V_85 -> system != V_104 )
continue;
V_51 = F_105 ( V_85 -> V_192 , NULL , V_70 , true ) ;
if ( V_51 )
F_113 ( V_85 ) ;
else
F_114 ( V_85 ) ;
}
F_56 (file, &tr->events, list) {
struct V_66 * V_67 ;
if ( V_85 -> system != V_104 )
continue;
if ( F_115 ( V_85 ) )
continue;
V_190 = F_52 ( sizeof( * V_190 ) , V_75 ) ;
if ( ! V_190 )
goto V_193;
F_89 ( & V_190 -> V_158 , & V_189 ) ;
V_190 -> V_67 = F_51 () ;
if ( ! V_190 -> V_67 )
goto V_193;
V_67 = V_190 -> V_67 ;
V_51 = F_26 ( V_67 , V_74 ) ;
if ( V_51 )
goto V_193;
V_51 = F_105 ( V_85 -> V_192 , V_67 , V_70 , false ) ;
if ( V_51 ) {
F_47 ( V_85 ) ;
F_23 ( V_70 , V_194 , 0 ) ;
F_31 ( V_70 , V_67 ) ;
} else
F_107 ( V_85 ) ;
V_67 = V_66 ( V_85 ) ;
F_109 ( V_85 , V_190 -> V_67 ) ;
V_190 -> V_67 = V_67 ;
V_185 = false ;
}
if ( V_185 )
goto V_185;
F_118 () ;
F_119 (filter_item, tmp, &filter_list, list) {
F_49 ( V_190 -> V_67 ) ;
F_85 ( & V_190 -> V_158 ) ;
F_25 ( V_190 ) ;
}
return 0 ;
V_185:
F_119 (filter_item, tmp, &filter_list, list) {
F_85 ( & V_190 -> V_158 ) ;
F_25 ( V_190 ) ;
}
F_23 ( V_70 , V_194 , 0 ) ;
return - V_50 ;
V_193:
if ( ! V_185 )
F_118 () ;
F_119 (filter_item, tmp, &filter_list, list) {
F_49 ( V_190 -> V_67 ) ;
F_85 ( & V_190 -> V_158 ) ;
F_25 ( V_190 ) ;
}
return - V_76 ;
}
static int F_120 ( char * V_195 , bool V_196 ,
struct V_69 * * V_197 ,
struct V_66 * * V_198 )
{
struct V_66 * V_67 ;
struct V_69 * V_70 = NULL ;
int V_51 = 0 ;
F_18 ( * V_197 || * V_198 ) ;
V_67 = F_51 () ;
if ( V_67 && V_196 )
V_51 = F_26 ( V_67 , V_195 ) ;
V_70 = F_52 ( sizeof( * V_70 ) , V_75 ) ;
if ( ! V_67 || ! V_70 || V_51 ) {
F_25 ( V_70 ) ;
F_49 ( V_67 ) ;
return - V_76 ;
}
* V_198 = V_67 ;
* V_197 = V_70 ;
F_68 ( V_70 , V_199 , V_195 ) ;
V_51 = F_92 ( V_70 ) ;
if ( V_51 && V_196 )
F_31 ( V_70 , V_67 ) ;
return V_51 ;
}
static void F_121 ( struct V_69 * V_70 )
{
if ( V_70 ) {
F_86 ( V_70 ) ;
F_91 ( V_70 ) ;
F_25 ( V_70 ) ;
}
}
static int F_122 ( struct V_168 * V_169 ,
char * V_195 , bool V_196 ,
struct V_66 * * V_198 )
{
struct V_66 * V_67 = NULL ;
struct V_69 * V_70 = NULL ;
int V_51 ;
V_51 = F_120 ( V_195 , V_196 , & V_70 , & V_67 ) ;
if ( ! V_51 ) {
V_51 = F_105 ( V_169 , V_67 , V_70 , false ) ;
if ( V_51 && V_196 )
F_31 ( V_70 , V_67 ) ;
}
F_121 ( V_70 ) ;
* V_198 = V_67 ;
return V_51 ;
}
int F_123 ( struct V_168 * V_169 ,
char * V_195 , bool V_196 ,
struct V_66 * * V_198 )
{
return F_122 ( V_169 , V_195 , V_196 , V_198 ) ;
}
static int F_124 ( struct V_103 * V_104 ,
struct V_105 * V_106 ,
char * V_195 , struct V_66 * * V_198 )
{
struct V_66 * V_67 = NULL ;
struct V_69 * V_70 = NULL ;
int V_51 ;
V_51 = F_120 ( V_195 , true , & V_70 , & V_67 ) ;
if ( ! V_51 ) {
V_51 = F_116 ( V_104 , V_106 , V_70 , V_195 ) ;
if ( ! V_51 ) {
F_25 ( V_67 -> V_74 ) ;
V_67 -> V_74 = NULL ;
} else {
F_31 ( V_70 , V_67 ) ;
}
}
F_121 ( V_70 ) ;
* V_198 = V_67 ;
return V_51 ;
}
int F_125 ( struct V_84 * V_85 , char * V_74 )
{
struct V_168 * V_169 = V_85 -> V_192 ;
struct V_66 * V_67 ;
int V_51 ;
if ( ! strcmp ( F_126 ( V_74 ) , L_9 ) ) {
F_47 ( V_85 ) ;
V_67 = V_66 ( V_85 ) ;
if ( ! V_67 )
return 0 ;
F_111 ( V_85 ) ;
F_118 () ;
F_49 ( V_67 ) ;
return 0 ;
}
V_51 = F_122 ( V_169 , V_74 , true , & V_67 ) ;
if ( V_67 ) {
struct V_66 * V_191 ;
V_191 = V_66 ( V_85 ) ;
if ( ! V_51 )
F_107 ( V_85 ) ;
else
F_47 ( V_85 ) ;
F_109 ( V_85 , V_67 ) ;
if ( V_191 ) {
F_118 () ;
F_49 ( V_191 ) ;
}
}
return V_51 ;
}
int F_127 ( struct V_103 * V_104 ,
char * V_74 )
{
struct V_88 * system = V_104 -> V_200 ;
struct V_105 * V_106 = V_104 -> V_106 ;
struct V_66 * V_67 ;
int V_51 = 0 ;
F_38 ( & V_89 ) ;
if ( ! V_104 -> V_201 ) {
V_51 = - V_202 ;
goto V_203;
}
if ( ! strcmp ( F_126 ( V_74 ) , L_9 ) ) {
F_55 ( V_104 , V_106 ) ;
F_24 ( system -> V_67 ) ;
V_67 = system -> V_67 ;
system -> V_67 = NULL ;
F_118 () ;
F_58 ( V_104 , V_106 ) ;
F_49 ( V_67 ) ;
goto V_203;
}
V_51 = F_124 ( V_104 , V_106 , V_74 , & V_67 ) ;
if ( V_67 ) {
F_49 ( system -> V_67 ) ;
system -> V_67 = V_67 ;
}
V_203:
F_39 ( & V_89 ) ;
return V_51 ;
}
void F_128 ( struct V_204 * V_3 )
{
struct V_66 * V_67 = V_3 -> V_67 ;
V_3 -> V_67 = NULL ;
F_49 ( V_67 ) ;
}
static char * *
F_129 ( char * V_79 , int V_11 , int * V_179 )
{
char * V_25 , * * V_205 ;
V_25 = F_130 ( V_79 , V_11 , V_75 ) ;
if ( ! V_25 )
return NULL ;
F_131 ( V_25 , ',' , ' ' ) ;
V_205 = F_132 ( V_75 , V_25 , V_179 ) ;
F_25 ( V_25 ) ;
return V_205 ;
}
static int F_133 ( struct V_206 * V_61 , int V_67 ,
int V_207 , char * V_205 , int V_11 )
{
int V_52 ;
if ( V_67 )
V_52 = F_134 ( V_61 , V_205 , V_11 , V_207 ) ;
else
V_52 = F_135 ( V_61 , V_205 , V_11 , V_207 ) ;
return V_52 ;
}
static int F_136 ( int V_67 , char * V_79 , int V_11 ,
struct V_208 * V_47 )
{
int V_32 , V_209 , V_52 = - V_50 ;
int * V_207 ;
char * * V_205 ;
V_207 = V_67 ? & V_47 -> V_210 : & V_47 -> V_211 ;
V_205 = F_129 ( V_79 , V_11 , & V_209 ) ;
if ( ! V_205 )
return - V_50 ;
for ( V_32 = 0 ; V_32 < V_209 ; V_32 ++ ) {
V_52 = F_133 ( V_47 -> V_61 , V_67 , * V_207 ,
V_205 [ V_32 ] , strlen ( V_205 [ V_32 ] ) ) ;
if ( V_52 )
break;
if ( * V_207 )
* V_207 = 0 ;
}
F_137 ( V_205 ) ;
return V_52 ;
}
static int F_138 ( struct V_1 * V_2 , int V_212 )
{
struct V_111 * V_112 = V_2 -> V_112 ;
if ( V_212 ) {
if ( ( V_2 -> V_17 != V_18 ) && ( V_2 -> V_17 != V_113 ) )
return - V_50 ;
if ( strcmp ( V_112 -> V_133 , L_7 ) )
return - V_50 ;
} else {
if ( V_2 -> V_17 != V_60 )
return - V_50 ;
}
return 0 ;
}
static int F_139 ( enum V_39 V_40 ,
struct V_1 * V_2 ,
int * V_51 , void * V_47 )
{
if ( ( V_40 != V_48 ) ||
( V_2 -> V_56 != V_57 ) ) {
* V_51 = F_138 ( V_2 , 0 ) ;
} else {
* V_51 = F_138 ( V_2 , 1 ) ;
if ( * V_51 )
return V_53 ;
* V_51 = F_136 ( V_2 -> V_17 == V_18 ,
V_2 -> V_8 . V_27 ,
V_2 -> V_8 . V_11 ,
V_47 ) ;
}
return ( * V_51 ) ? V_53 : V_65 ;
}
static int F_140 ( struct V_204 * V_3 ,
struct V_66 * V_67 )
{
struct V_208 V_47 = {
. V_210 = 1 ,
. V_211 = 1 ,
. V_61 = & V_3 -> V_206 ,
} ;
return F_16 ( V_67 -> V_37 , V_67 -> V_45 ,
F_139 , & V_47 ) ;
}
static int F_140 ( struct V_204 * V_3 ,
struct V_66 * V_67 )
{
return - V_202 ;
}
int F_141 ( struct V_204 * V_3 , int V_213 ,
char * V_195 )
{
int V_51 ;
struct V_66 * V_67 ;
struct V_168 * V_169 ;
F_38 ( & V_89 ) ;
V_169 = V_3 -> V_214 ;
V_51 = - V_50 ;
if ( ! V_169 )
goto V_203;
V_51 = - V_215 ;
if ( V_3 -> V_67 )
goto V_203;
V_51 = F_122 ( V_169 , V_195 , false , & V_67 ) ;
if ( V_51 )
goto V_216;
if ( F_142 ( V_169 ) )
V_51 = F_140 ( V_3 , V_67 ) ;
else
V_3 -> V_67 = V_67 ;
V_216:
if ( V_51 || F_142 ( V_169 ) )
F_49 ( V_67 ) ;
V_203:
F_39 ( & V_89 ) ;
return V_51 ;
}
static int F_143 ( struct V_1 * V_2 , void * V_3 )
{
struct V_111 * V_112 = V_2 -> V_112 ;
V_217 = 1 ;
F_144 ( V_218 L_10 , V_112 -> V_133 ) ;
return 1 ;
}
static int F_145 ( enum V_39 V_40 , struct V_1 * V_2 ,
int * V_51 , void * V_47 )
{
char * V_219 = V_47 ;
if ( ( V_40 == V_48 ) &&
( V_2 -> V_56 == V_57 ) ) {
struct V_111 * V_112 = V_2 -> V_112 ;
if ( ! V_112 ) {
F_146 ( 1 , L_11 ) ;
return V_65 ;
}
if ( ! strchr ( V_219 , * V_112 -> V_133 ) )
return V_65 ;
F_22 ( ! V_2 -> V_62 ) ;
V_2 -> V_62 = F_143 ;
}
return V_65 ;
}
static T_4 int F_147 ( void )
{
int V_32 ;
F_144 ( V_218 L_12 ) ;
for ( V_32 = 0 ; V_32 < V_220 ; V_32 ++ ) {
struct V_66 * V_67 = NULL ;
struct V_221 * V_64 = & V_222 [ V_32 ] ;
int V_51 ;
V_51 = F_122 ( & V_223 , V_64 -> V_67 ,
false , & V_67 ) ;
if ( V_51 ) {
F_144 ( V_218
L_13 ,
V_64 -> V_67 , V_51 ) ;
F_49 ( V_67 ) ;
break;
}
F_148 () ;
if ( * V_64 -> V_224 )
F_16 ( V_67 -> V_37 , V_67 -> V_45 ,
F_145 ,
V_64 -> V_224 ) ;
V_217 = 0 ;
V_51 = F_20 ( V_67 , & V_64 -> V_59 ) ;
F_149 () ;
F_49 ( V_67 ) ;
if ( V_217 ) {
F_144 ( V_218
L_14 ,
V_64 -> V_67 ) ;
break;
}
if ( V_51 != V_64 -> V_7 ) {
F_144 ( V_218
L_15 ,
V_64 -> V_67 , V_64 -> V_7 ) ;
break;
}
}
if ( V_32 == V_220 )
F_144 ( V_225 L_16 ) ;
return 0 ;
}
