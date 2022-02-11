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
static int F_13 ( char * V_25 , struct V_8 * V_26 , int V_11 V_28 )
{
if ( F_14 ( V_26 -> V_27 , V_25 ) )
return 1 ;
return 0 ;
}
enum V_29 F_15 ( char * V_30 , int V_11 , char * * V_31 , int * V_10 )
{
int type = V_32 ;
int V_33 ;
if ( V_30 [ 0 ] == '!' ) {
* V_10 = 1 ;
V_30 ++ ;
V_11 -- ;
} else
* V_10 = 0 ;
* V_31 = V_30 ;
for ( V_33 = 0 ; V_33 < V_11 ; V_33 ++ ) {
if ( V_30 [ V_33 ] == '*' ) {
if ( ! V_33 ) {
* V_31 = V_30 + 1 ;
type = V_34 ;
} else if ( V_33 == V_11 - 1 ) {
if ( type == V_34 )
type = V_35 ;
else
type = V_36 ;
V_30 [ V_33 ] = 0 ;
break;
} else {
type = V_37 ;
break;
}
} else if ( strchr ( L_1 , V_30 [ V_33 ] ) ) {
type = V_37 ;
break;
}
}
return type ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_26 = & V_2 -> V_8 ;
char * V_31 ;
enum V_29 type = V_32 ;
int V_10 = 0 ;
if ( V_2 -> V_17 == V_38 ) {
type = F_15 ( V_26 -> V_27 , V_26 -> V_11 , & V_31 , & V_10 ) ;
V_26 -> V_11 = strlen ( V_31 ) ;
memmove ( V_26 -> V_27 , V_31 , V_26 -> V_11 + 1 ) ;
}
switch ( type ) {
case V_32 :
V_26 -> V_7 = F_8 ;
break;
case V_36 :
V_26 -> V_7 = F_9 ;
break;
case V_35 :
V_26 -> V_7 = F_10 ;
break;
case V_34 :
V_26 -> V_7 = F_12 ;
break;
case V_37 :
V_26 -> V_7 = F_13 ;
break;
}
V_2 -> V_10 ^= V_10 ;
}
static struct V_1 *
F_17 ( struct V_1 * V_2 , struct V_1 * V_39 ,
int V_40 , enum V_41 * V_42 )
{
if ( V_2 -> V_43 & V_44 )
* V_42 = V_45 ;
else
* V_42 = V_46 ;
V_2 = & V_39 [ V_2 -> V_43 & ~ V_44 ] ;
return V_2 ;
}
static int F_18 ( struct V_1 * V_39 ,
struct V_1 * V_47 ,
T_2 V_48 , void * V_49 )
{
struct V_1 * V_2 = V_47 ;
enum V_41 V_42 = V_50 ;
int V_51 = 0 ;
if ( ! V_39 )
return - V_52 ;
do {
int V_53 = 0 , V_54 ;
V_54 = V_48 ( V_42 , V_2 , & V_53 , V_49 ) ;
if ( V_54 == V_55 )
return V_53 ;
if ( V_54 == V_56 )
goto V_57;
switch ( V_42 ) {
case V_50 :
if ( V_2 -> V_58 != V_59 ) {
V_2 = & V_39 [ V_2 -> V_58 ] ;
continue;
}
goto V_57;
case V_46 :
V_2 = & V_39 [ V_2 -> V_60 ] ;
V_42 = V_50 ;
continue;
case V_45 :
V_57:
if ( V_2 == V_47 )
break;
V_2 = F_17 ( V_2 , V_39 ,
V_2 -> V_43 ,
& V_42 ) ;
continue;
}
V_51 = 1 ;
} while ( ! V_51 );
return 0 ;
}
static int F_19 ( struct V_1 * V_39 ,
struct V_1 * V_17 , void * V_61 )
{
struct V_1 * V_2 ;
int V_7 = 0 ;
int type ;
int V_33 ;
type = V_17 -> V_17 == V_62 ;
for ( V_33 = 0 ; V_33 < V_17 -> V_16 ; V_33 ++ ) {
V_2 = & V_39 [ V_17 -> V_63 [ V_33 ] ] ;
if ( ! F_20 ( ! V_2 -> V_64 ) )
V_7 = V_2 -> V_64 ( V_2 , V_61 ) ;
if ( ! ! V_7 == type )
break;
}
return ! ! V_7 == ! V_17 -> V_10 ;
}
static int F_21 ( enum V_41 V_42 , struct V_1 * V_2 ,
int * V_53 , void * V_49 )
{
struct V_65 * V_66 = V_49 ;
* V_53 = 0 ;
switch ( V_42 ) {
case V_50 :
if ( V_2 -> V_58 != V_59 ) {
if ( ! V_2 -> V_63 )
return V_67 ;
V_66 -> V_7 = F_19 ( V_66 -> V_39 , V_2 , V_66 -> V_61 ) ;
} else {
if ( ! F_20 ( ! V_2 -> V_64 ) )
V_66 -> V_7 = V_2 -> V_64 ( V_2 , V_66 -> V_61 ) ;
}
return V_56 ;
case V_46 :
if ( ! ! V_66 -> V_7 == ( V_2 -> V_17 == V_62 ) )
return V_56 ;
break;
case V_45 :
break;
}
return V_67 ;
}
int F_22 ( struct V_68 * V_69 , void * V_61 )
{
struct V_1 * V_39 ;
struct V_1 * V_47 ;
struct V_65 V_49 = {
. V_7 = - 1 ,
. V_61 = V_61 ,
} ;
int V_70 , V_54 ;
if ( ! V_69 )
return 1 ;
V_70 = V_69 -> V_70 ;
if ( ! V_70 )
return 1 ;
V_47 = F_23 ( V_69 -> V_47 ) ;
if ( ! V_47 )
return 1 ;
V_49 . V_39 = V_39 = F_23 ( V_69 -> V_39 ) ;
V_54 = F_18 ( V_39 , V_47 , F_21 , & V_49 ) ;
F_24 ( V_54 ) ;
return V_49 . V_7 ;
}
static void F_25 ( struct V_71 * V_72 , int V_53 , int V_73 )
{
V_72 -> V_74 = V_53 ;
V_72 -> V_75 = V_73 ;
}
static void F_26 ( struct V_68 * V_69 )
{
if ( ! V_69 )
return;
F_27 ( V_69 -> V_76 ) ;
V_69 -> V_76 = NULL ;
}
static int F_28 ( struct V_68 * V_69 ,
char * V_76 )
{
F_27 ( V_69 -> V_76 ) ;
V_69 -> V_76 = F_29 ( V_76 , V_77 ) ;
if ( ! V_69 -> V_76 )
return - V_78 ;
return 0 ;
}
static int F_30 ( struct V_68 * V_69 ,
char * string )
{
int V_79 ;
char * V_80 ;
F_31 ( ! V_69 -> V_76 ) ;
V_79 = strlen ( V_69 -> V_76 ) + strlen ( string ) + 1 ;
V_80 = F_32 ( V_79 , V_77 ) ;
if ( ! V_80 )
return - V_78 ;
strcpy ( V_80 , V_69 -> V_76 ) ;
strcat ( V_80 , string ) ;
F_27 ( V_69 -> V_76 ) ;
V_69 -> V_76 = V_80 ;
return 0 ;
}
static void F_33 ( struct V_71 * V_72 ,
struct V_68 * V_69 )
{
int V_73 = V_72 -> V_75 ;
char * V_81 , * V_82 ;
V_81 = ( char * ) F_34 ( V_83 ) ;
if ( ! V_81 )
return;
F_30 ( V_69 , L_2 ) ;
memset ( V_81 , ' ' , V_84 ) ;
if ( V_73 > V_84 - 128 )
V_73 = 0 ;
V_81 [ V_73 ] = '^' ;
V_82 = & V_81 [ V_73 ] + 1 ;
sprintf ( V_82 , L_3 , V_85 [ V_72 -> V_74 ] ) ;
F_30 ( V_69 , V_81 ) ;
F_35 ( ( unsigned long ) V_81 ) ;
}
static inline struct V_68 * V_68 ( struct V_86 * V_87 )
{
return V_87 -> V_69 ;
}
void F_36 ( struct V_86 * V_87 , struct V_88 * V_89 )
{
struct V_68 * V_69 = V_68 ( V_87 ) ;
if ( V_69 && V_69 -> V_76 )
F_37 ( V_89 , L_4 , V_69 -> V_76 ) ;
else
F_38 ( V_89 , L_5 ) ;
}
void F_39 ( struct V_90 * system ,
struct V_88 * V_89 )
{
struct V_68 * V_69 ;
F_40 ( & V_91 ) ;
V_69 = system -> V_69 ;
if ( V_69 && V_69 -> V_76 )
F_37 ( V_89 , L_4 , V_69 -> V_76 ) ;
else
F_38 ( V_89 , V_92 L_2 ) ;
F_41 ( & V_91 ) ;
}
static int F_42 ( struct V_93 * V_94 , int V_70 )
{
V_94 -> V_39 = F_43 ( V_70 + 1 , sizeof( * V_94 -> V_39 ) , V_77 ) ;
if ( ! V_94 -> V_39 )
return - V_78 ;
V_94 -> V_40 = V_70 ;
return 0 ;
}
static void F_44 ( struct V_93 * V_94 )
{
F_27 ( V_94 -> V_39 ) ;
V_94 -> V_40 = 0 ;
}
static int F_45 ( struct V_93 * V_94 ,
struct V_1 * V_2 )
{
int V_40 = V_94 -> V_40 ;
if ( F_24 ( V_40 == 0 ) )
return - V_95 ;
V_94 -> V_39 [ -- V_40 ] = V_2 ;
V_94 -> V_40 = V_40 ;
return 0 ;
}
static struct V_1 *
F_46 ( struct V_93 * V_94 )
{
struct V_1 * V_2 ;
int V_40 = V_94 -> V_40 ;
V_2 = V_94 -> V_39 [ V_40 ++ ] ;
if ( ! V_2 )
return NULL ;
V_94 -> V_40 = V_40 ;
return V_2 ;
}
static int F_47 ( struct V_68 * V_69 ,
int V_96 ,
struct V_93 * V_94 ,
struct V_1 * V_97 )
{
struct V_1 * V_98 = & V_69 -> V_39 [ V_96 ] ;
struct V_1 * V_58 ;
struct V_1 * V_60 ;
* V_98 = * V_97 ;
V_98 -> V_40 = V_96 ;
if ( V_98 -> V_17 == V_62 || V_98 -> V_17 == V_99 ) {
V_60 = F_46 ( V_94 ) ;
V_58 = F_46 ( V_94 ) ;
if ( ! V_58 || ! V_60 )
return - V_52 ;
if ( V_58 -> V_40 & V_100 &&
( ( V_58 -> V_17 == V_98 -> V_17 && ! V_58 -> V_10 ) ||
V_58 -> V_58 == V_59 ) &&
V_60 -> V_40 & V_100 &&
( ( V_60 -> V_17 == V_98 -> V_17 && ! V_60 -> V_10 ) ||
V_60 -> V_58 == V_59 ) )
V_98 -> V_40 |= V_100 ;
V_98 -> V_58 = V_58 -> V_40 & ~ V_100 ;
V_98 -> V_60 = V_60 -> V_40 & ~ V_100 ;
V_58 -> V_43 = V_98 -> V_40 & ~ V_100 ;
V_60 -> V_43 = V_98 -> V_40 | V_44 ;
} else {
V_98 -> V_58 = V_59 ;
V_98 -> V_40 |= V_100 ;
}
return F_45 ( V_94 , V_98 ) ;
}
static void F_48 ( struct V_68 * V_69 )
{
int V_33 ;
if ( V_69 -> V_39 ) {
for ( V_33 = 0 ; V_33 < V_69 -> V_70 ; V_33 ++ )
F_27 ( V_69 -> V_39 [ V_33 ] . V_63 ) ;
F_27 ( V_69 -> V_39 ) ;
V_69 -> V_39 = NULL ;
}
V_69 -> V_101 = 0 ;
V_69 -> V_70 = 0 ;
}
static void F_49 ( struct V_86 * V_87 )
{
unsigned long V_102 = V_87 -> V_103 ;
V_87 -> V_103 &= ~ V_104 ;
if ( V_102 != V_87 -> V_103 )
F_50 () ;
}
static void F_51 ( struct V_68 * V_69 )
{
if ( ! V_69 )
return;
F_48 ( V_69 ) ;
F_27 ( V_69 -> V_76 ) ;
F_27 ( V_69 ) ;
}
void F_52 ( struct V_68 * V_69 )
{
F_51 ( V_69 ) ;
}
static struct V_68 * F_53 ( void )
{
struct V_68 * V_69 ;
V_69 = F_54 ( sizeof( * V_69 ) , V_77 ) ;
return V_69 ;
}
static int F_55 ( struct V_68 * V_69 , int V_70 )
{
struct V_1 * V_2 ;
int V_33 ;
if ( V_69 -> V_39 )
F_48 ( V_69 ) ;
V_69 -> V_39 = F_43 ( V_70 , sizeof( * V_69 -> V_39 ) , V_77 ) ;
if ( ! V_69 -> V_39 )
return - V_78 ;
V_69 -> V_101 = V_70 ;
V_69 -> V_70 = 0 ;
for ( V_33 = 0 ; V_33 < V_70 ; V_33 ++ ) {
V_2 = & V_69 -> V_39 [ V_33 ] ;
V_2 -> V_64 = F_7 ;
}
return 0 ;
}
static inline void F_56 ( struct V_86 * V_87 )
{
F_49 ( V_87 ) ;
F_26 ( V_87 -> V_69 ) ;
}
static void F_57 ( struct V_105 * V_106 ,
struct V_107 * V_108 )
{
struct V_86 * V_87 ;
F_58 (file, &tr->events, list) {
if ( V_87 -> system != V_106 )
continue;
F_56 ( V_87 ) ;
}
}
static inline void F_59 ( struct V_86 * V_87 )
{
F_51 ( V_87 -> V_69 ) ;
V_87 -> V_69 = NULL ;
}
static void F_60 ( struct V_105 * V_106 ,
struct V_107 * V_108 )
{
struct V_86 * V_87 ;
F_58 (file, &tr->events, list) {
if ( V_87 -> system != V_106 )
continue;
F_59 ( V_87 ) ;
}
}
static int F_61 ( struct V_71 * V_72 ,
struct V_68 * V_69 ,
struct V_1 * V_2 ,
struct V_93 * V_94 )
{
int V_53 ;
if ( F_24 ( V_69 -> V_70 == V_69 -> V_101 ) ) {
F_25 ( V_72 , V_109 , 0 ) ;
return - V_95 ;
}
V_53 = F_47 ( V_69 , V_69 -> V_70 , V_94 , V_2 ) ;
if ( V_53 )
return V_53 ;
V_69 -> V_70 ++ ;
return 0 ;
}
int F_62 ( const char * type )
{
if ( strstr ( type , L_6 ) && strstr ( type , L_7 ) )
return V_110 ;
if ( strchr ( type , '[' ) && strstr ( type , L_7 ) )
return V_111 ;
return V_112 ;
}
static bool F_63 ( struct V_113 * V_114 , enum V_115 V_17 )
{
if ( F_64 ( V_114 ) &&
( V_17 != V_18 && V_17 != V_116 && V_17 != V_38 ) )
return false ;
if ( ! F_64 ( V_114 ) && V_17 == V_38 )
return false ;
return true ;
}
static T_3 F_65 ( enum V_115 V_17 ,
int V_117 , int V_118 )
{
T_3 V_64 = NULL ;
switch ( V_117 ) {
case 8 :
if ( V_17 == V_18 || V_17 == V_116 )
V_64 = V_119 ;
else if ( V_118 )
V_64 = V_120 [ V_17 - V_121 ] ;
else
V_64 = V_122 [ V_17 - V_121 ] ;
break;
case 4 :
if ( V_17 == V_18 || V_17 == V_116 )
V_64 = V_123 ;
else if ( V_118 )
V_64 = V_124 [ V_17 - V_121 ] ;
else
V_64 = V_125 [ V_17 - V_121 ] ;
break;
case 2 :
if ( V_17 == V_18 || V_17 == V_116 )
V_64 = V_126 ;
else if ( V_118 )
V_64 = V_127 [ V_17 - V_121 ] ;
else
V_64 = V_128 [ V_17 - V_121 ] ;
break;
case 1 :
if ( V_17 == V_18 || V_17 == V_116 )
V_64 = V_129 ;
else if ( V_118 )
V_64 = V_130 [ V_17 - V_121 ] ;
else
V_64 = V_131 [ V_17 - V_121 ] ;
break;
}
return V_64 ;
}
static int F_66 ( struct V_71 * V_72 ,
struct V_113 * V_114 ,
struct V_1 * V_2 )
{
T_3 V_64 = F_7 ;
unsigned long long V_16 ;
int V_54 ;
V_2 -> V_5 = V_114 -> V_5 ;
if ( ! F_63 ( V_114 , V_2 -> V_17 ) ) {
F_25 ( V_72 , V_132 , 0 ) ;
return - V_52 ;
}
if ( V_114 -> V_133 == V_134 ) {
F_16 ( V_2 ) ;
V_64 = F_6 ;
V_2 -> V_8 . V_9 = V_135 ;
} else if ( F_64 ( V_114 ) ) {
F_16 ( V_2 ) ;
if ( V_114 -> V_133 == V_111 ) {
V_64 = F_1 ;
V_2 -> V_8 . V_9 = V_114 -> V_136 ;
} else if ( V_114 -> V_133 == V_110 )
V_64 = F_3 ;
else
V_64 = F_2 ;
} else if ( F_67 ( V_114 ) ) {
if ( strcmp ( V_114 -> V_137 , L_8 ) ) {
F_25 ( V_72 , V_138 , 0 ) ;
return - V_52 ;
}
} else {
if ( V_114 -> V_139 )
V_54 = F_68 ( V_2 -> V_8 . V_27 , 0 , & V_16 ) ;
else
V_54 = F_69 ( V_2 -> V_8 . V_27 , 0 , & V_16 ) ;
if ( V_54 ) {
F_25 ( V_72 , V_140 , 0 ) ;
return - V_52 ;
}
V_2 -> V_16 = V_16 ;
if ( V_114 -> V_133 == V_141 )
V_64 = F_4 ;
else
V_64 = F_65 ( V_2 -> V_17 , V_114 -> V_136 ,
V_114 -> V_139 ) ;
if ( ! V_64 ) {
F_25 ( V_72 , V_142 , 0 ) ;
return - V_52 ;
}
}
if ( V_2 -> V_17 == V_116 )
V_2 -> V_10 ^= 1 ;
V_2 -> V_64 = V_64 ;
return 0 ;
}
static void F_70 ( struct V_71 * V_72 ,
struct V_143 * V_63 ,
char * V_144 )
{
memset ( V_72 , '\0' , sizeof( * V_72 ) ) ;
V_72 -> V_145 . string = V_144 ;
V_72 -> V_145 . V_146 = strlen ( V_144 ) ;
V_72 -> V_63 = V_63 ;
F_71 ( & V_72 -> V_147 ) ;
F_71 ( & V_72 -> V_148 ) ;
}
static char F_72 ( struct V_71 * V_72 )
{
if ( ! V_72 -> V_145 . V_146 )
return 0 ;
V_72 -> V_145 . V_146 -- ;
return V_72 -> V_145 . string [ V_72 -> V_145 . V_149 ++ ] ;
}
static char F_73 ( struct V_71 * V_72 )
{
if ( V_72 -> V_145 . V_149 == strlen ( V_72 -> V_145 . string ) )
return 0 ;
return V_72 -> V_145 . string [ V_72 -> V_145 . V_149 ] ;
}
static void F_74 ( struct V_71 * V_72 )
{
if ( ! V_72 -> V_145 . V_146 )
return;
V_72 -> V_145 . V_146 -- ;
V_72 -> V_145 . V_149 ++ ;
}
static inline int F_75 ( struct V_71 * V_72 ,
int V_150 , int V_151 )
{
return V_72 -> V_63 [ V_150 ] . V_152 < V_72 -> V_63 [ V_151 ] . V_152 ;
}
static inline int F_76 ( struct V_71 * V_72 , char V_153 )
{
int V_33 ;
for ( V_33 = 0 ; strcmp ( V_72 -> V_63 [ V_33 ] . string , L_9 ) ; V_33 ++ ) {
if ( V_72 -> V_63 [ V_33 ] . string [ 0 ] == V_153 )
return 1 ;
}
return 0 ;
}
static int F_77 ( struct V_71 * V_72 , char V_154 )
{
char V_155 = F_73 ( V_72 ) ;
char V_156 [ 3 ] ;
int V_33 ;
V_156 [ 0 ] = V_154 ;
V_156 [ 1 ] = V_155 ;
V_156 [ 2 ] = '\0' ;
for ( V_33 = 0 ; strcmp ( V_72 -> V_63 [ V_33 ] . string , L_9 ) ; V_33 ++ ) {
if ( ! strcmp ( V_156 , V_72 -> V_63 [ V_33 ] . string ) ) {
F_74 ( V_72 ) ;
return V_72 -> V_63 [ V_33 ] . V_157 ;
}
}
V_156 [ 1 ] = '\0' ;
for ( V_33 = 0 ; strcmp ( V_72 -> V_63 [ V_33 ] . string , L_9 ) ; V_33 ++ ) {
if ( ! strcmp ( V_156 , V_72 -> V_63 [ V_33 ] . string ) )
return V_72 -> V_63 [ V_33 ] . V_157 ;
}
return V_158 ;
}
static inline void F_78 ( struct V_71 * V_72 )
{
memset ( V_72 -> V_159 . string , '\0' , V_160 ) ;
V_72 -> V_159 . V_149 = 0 ;
}
static inline int F_79 ( struct V_71 * V_72 , char V_153 )
{
if ( V_72 -> V_159 . V_149 == V_160 - 1 )
return - V_52 ;
V_72 -> V_159 . string [ V_72 -> V_159 . V_149 ++ ] = V_153 ;
return 0 ;
}
static int F_80 ( struct V_71 * V_72 ,
enum V_115 V_17 )
{
struct V_161 * V_161 ;
V_161 = F_32 ( sizeof( * V_161 ) , V_77 ) ;
if ( ! V_161 )
return - V_78 ;
V_161 -> V_17 = V_17 ;
F_81 ( & V_161 -> V_162 , & V_72 -> V_147 ) ;
return 0 ;
}
static int F_82 ( struct V_71 * V_72 )
{
return F_83 ( & V_72 -> V_147 ) ;
}
static int F_84 ( struct V_71 * V_72 )
{
struct V_161 * V_161 ;
if ( F_82 ( V_72 ) )
return V_158 ;
V_161 = F_85 ( & V_72 -> V_147 , struct V_161 , V_162 ) ;
return V_161 -> V_17 ;
}
static int F_86 ( struct V_71 * V_72 )
{
struct V_161 * V_161 ;
enum V_115 V_17 ;
if ( F_82 ( V_72 ) )
return V_158 ;
V_161 = F_85 ( & V_72 -> V_147 , struct V_161 , V_162 ) ;
V_17 = V_161 -> V_17 ;
F_87 ( & V_161 -> V_162 ) ;
F_27 ( V_161 ) ;
return V_17 ;
}
static void F_88 ( struct V_71 * V_72 )
{
while ( ! F_82 ( V_72 ) )
F_86 ( V_72 ) ;
}
static char * F_89 ( struct V_71 * V_72 )
{
return V_72 -> V_159 . string ;
}
static int F_90 ( struct V_71 * V_72 , char * V_159 )
{
struct V_163 * V_164 ;
V_164 = F_32 ( sizeof( * V_164 ) , V_77 ) ;
if ( ! V_164 )
return - V_78 ;
V_164 -> V_17 = V_158 ;
V_164 -> V_159 = F_29 ( V_159 , V_77 ) ;
if ( ! V_164 -> V_159 ) {
F_27 ( V_164 ) ;
return - V_78 ;
}
F_91 ( & V_164 -> V_162 , & V_72 -> V_148 ) ;
return 0 ;
}
static int F_92 ( struct V_71 * V_72 , enum V_115 V_17 )
{
struct V_163 * V_164 ;
V_164 = F_32 ( sizeof( * V_164 ) , V_77 ) ;
if ( ! V_164 )
return - V_78 ;
V_164 -> V_17 = V_17 ;
V_164 -> V_159 = NULL ;
F_91 ( & V_164 -> V_162 , & V_72 -> V_148 ) ;
return 0 ;
}
static void F_93 ( struct V_71 * V_72 )
{
struct V_163 * V_164 ;
while ( ! F_83 ( & V_72 -> V_148 ) ) {
V_164 = F_85 ( & V_72 -> V_148 , struct V_163 , V_162 ) ;
F_87 ( & V_164 -> V_162 ) ;
F_27 ( V_164 -> V_159 ) ;
F_27 ( V_164 ) ;
}
}
static int F_94 ( struct V_71 * V_72 )
{
enum V_115 V_17 , V_165 ;
int V_166 = 0 ;
char V_167 ;
while ( ( V_167 = F_72 ( V_72 ) ) ) {
if ( V_167 == '"' ) {
V_166 ^= 1 ;
continue;
}
if ( V_166 )
goto V_168;
if ( isspace ( V_167 ) )
continue;
if ( F_76 ( V_72 , V_167 ) ) {
V_17 = F_77 ( V_72 , V_167 ) ;
if ( V_17 == V_158 ) {
F_25 ( V_72 , V_142 , 0 ) ;
return - V_52 ;
}
if ( strlen ( F_89 ( V_72 ) ) ) {
F_90 ( V_72 , F_89 ( V_72 ) ) ;
F_78 ( V_72 ) ;
}
while ( ! F_82 ( V_72 ) ) {
V_165 = F_84 ( V_72 ) ;
if ( ! F_75 ( V_72 , V_165 , V_17 ) ) {
V_165 = F_86 ( V_72 ) ;
F_92 ( V_72 , V_165 ) ;
continue;
}
break;
}
F_80 ( V_72 , V_17 ) ;
continue;
}
if ( V_167 == '(' ) {
F_80 ( V_72 , V_169 ) ;
continue;
}
if ( V_167 == ')' ) {
if ( strlen ( F_89 ( V_72 ) ) ) {
F_90 ( V_72 , F_89 ( V_72 ) ) ;
F_78 ( V_72 ) ;
}
V_165 = F_86 ( V_72 ) ;
while ( V_165 != V_158 ) {
if ( V_165 == V_169 )
break;
F_92 ( V_72 , V_165 ) ;
V_165 = F_86 ( V_72 ) ;
}
if ( V_165 == V_158 ) {
F_25 ( V_72 , V_170 , 0 ) ;
return - V_52 ;
}
continue;
}
V_168:
if ( F_79 ( V_72 , V_167 ) ) {
F_25 ( V_72 , V_171 , 0 ) ;
return - V_52 ;
}
}
if ( strlen ( F_89 ( V_72 ) ) )
F_90 ( V_72 , F_89 ( V_72 ) ) ;
while ( ! F_82 ( V_72 ) ) {
V_165 = F_86 ( V_72 ) ;
if ( V_165 == V_158 )
break;
if ( V_165 == V_169 ) {
F_25 ( V_72 , V_170 , 0 ) ;
return - V_52 ;
}
F_92 ( V_72 , V_165 ) ;
}
return 0 ;
}
static struct V_1 * F_95 ( struct V_71 * V_72 ,
struct V_172 * V_173 ,
enum V_115 V_17 ,
char * V_174 , char * V_175 )
{
struct V_113 * V_114 ;
static struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_17 = V_17 ;
if ( V_17 == V_99 || V_17 == V_62 )
return & V_2 ;
if ( ! V_174 || ! V_175 ) {
F_25 ( V_72 , V_176 , 0 ) ;
return NULL ;
}
V_114 = F_96 ( V_173 , V_174 ) ;
if ( ! V_114 ) {
F_25 ( V_72 , V_177 , 0 ) ;
return NULL ;
}
strcpy ( V_2 . V_8 . V_27 , V_175 ) ;
V_2 . V_8 . V_11 = strlen ( V_2 . V_8 . V_27 ) ;
V_2 . V_114 = V_114 ;
return F_66 ( V_72 , V_114 , & V_2 ) ? NULL : & V_2 ;
}
static int F_97 ( struct V_71 * V_72 )
{
int V_178 = 0 , V_179 = 0 ;
struct V_163 * V_164 ;
int V_146 = 0 ;
F_58 (elt, &ps->postfix, list) {
if ( V_164 -> V_17 == V_158 ) {
V_146 ++ ;
continue;
}
if ( V_164 -> V_17 == V_99 || V_164 -> V_17 == V_62 ) {
V_179 ++ ;
V_146 -- ;
continue;
}
if ( V_164 -> V_17 != V_180 )
V_146 -- ;
V_178 ++ ;
if ( V_146 < 0 )
break;
}
if ( V_146 != 1 || ! V_178 || V_179 >= V_178 ) {
F_25 ( V_72 , V_181 , 0 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_98 ( struct V_71 * V_72 )
{
struct V_163 * V_164 ;
int V_70 = 0 ;
F_58 (elt, &ps->postfix, list) {
if ( V_164 -> V_17 == V_158 )
continue;
V_70 ++ ;
}
return V_70 ;
}
static int F_99 ( enum V_41 V_42 , struct V_1 * V_2 ,
int * V_53 , void * V_49 )
{
struct V_182 * V_66 = V_49 ;
if ( F_24 ( V_66 -> V_183 ++ > V_66 -> V_184 ) ) {
* V_53 = - V_52 ;
return V_55 ;
}
return V_67 ;
}
static int F_100 ( struct V_68 * V_69 ,
struct V_1 * V_47 )
{
struct V_182 V_49 = {
. V_184 = 3 * V_69 -> V_70 ,
. V_183 = 0 ,
} ;
return F_18 ( V_69 -> V_39 , V_47 ,
F_99 , & V_49 ) ;
}
static int F_101 ( enum V_41 V_42 , struct V_1 * V_2 ,
int * V_53 , void * V_49 )
{
int * V_183 = V_49 ;
if ( ( V_42 == V_50 ) &&
( V_2 -> V_58 == V_59 ) )
( * V_183 ) ++ ;
return V_67 ;
}
static int F_102 ( struct V_1 * V_39 , struct V_1 * V_47 )
{
int V_183 = 0 , V_54 ;
V_54 = F_18 ( V_39 , V_47 , F_101 , & V_183 ) ;
F_24 ( V_54 ) ;
return V_183 ;
}
static int F_103 ( enum V_41 V_42 , struct V_1 * V_2 ,
int * V_53 , void * V_49 )
{
struct V_185 * V_66 = V_49 ;
struct V_1 * V_47 = V_66 -> V_47 ;
if ( V_42 != V_50 )
return V_67 ;
if ( V_2 -> V_58 != V_59 )
return V_67 ;
if ( F_24 ( V_66 -> V_183 == V_66 -> V_186 ) ) {
* V_53 = - V_52 ;
return V_55 ;
}
V_2 -> V_40 &= ~ V_100 ;
V_47 -> V_63 [ V_66 -> V_183 ++ ] = V_2 -> V_40 ;
return V_67 ;
}
static int F_104 ( struct V_1 * V_39 , struct V_1 * V_47 )
{
struct V_185 V_49 = {
. V_47 = V_47 ,
. V_183 = 0 ,
} ;
int V_186 ;
V_47 -> V_40 &= ~ V_100 ;
if ( V_47 -> V_58 == V_59 )
return 0 ;
V_186 = F_102 ( V_39 , & V_39 [ V_47 -> V_58 ] ) ;
V_186 += F_102 ( V_39 , & V_39 [ V_47 -> V_60 ] ) ;
V_47 -> V_63 = F_43 ( V_186 , sizeof( * V_47 -> V_63 ) , V_77 ) ;
if ( ! V_47 -> V_63 )
return - V_78 ;
V_47 -> V_16 = V_186 ;
V_49 . V_186 = V_186 ;
return F_18 ( V_39 , V_47 , F_103 , & V_49 ) ;
}
static int F_105 ( enum V_41 V_42 , struct V_1 * V_2 ,
int * V_53 , void * V_49 )
{
struct V_1 * V_39 = V_49 ;
if ( V_42 != V_50 )
return V_67 ;
if ( ! ( V_2 -> V_40 & V_100 ) )
return V_67 ;
* V_53 = F_104 ( V_39 , V_2 ) ;
if ( * V_53 )
return V_55 ;
return V_56 ;
}
static int F_106 ( struct V_68 * V_69 ,
struct V_1 * V_47 )
{
return F_18 ( V_69 -> V_39 , V_47 , F_105 ,
V_69 -> V_39 ) ;
}
static int F_107 ( struct V_172 * V_173 ,
struct V_68 * V_69 ,
struct V_71 * V_72 ,
bool V_187 )
{
char * V_174 = NULL , * V_175 = NULL ;
struct V_1 * V_2 ;
struct V_1 * V_47 ;
struct V_163 * V_164 ;
struct V_93 V_94 = { } ;
int V_53 ;
int V_70 = 0 ;
V_70 = F_98 ( V_72 ) ;
if ( V_70 >= V_188 ) {
F_25 ( V_72 , V_109 , 0 ) ;
return - V_95 ;
}
V_53 = F_97 ( V_72 ) ;
if ( V_53 )
return V_53 ;
if ( ! V_187 ) {
V_53 = F_42 ( & V_94 , V_70 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_55 ( V_69 , V_70 ) ;
if ( V_53 )
goto V_189;
}
V_70 = 0 ;
F_58 (elt, &ps->postfix, list) {
if ( V_164 -> V_17 == V_158 ) {
if ( ! V_174 )
V_174 = V_164 -> V_159 ;
else if ( ! V_175 )
V_175 = V_164 -> V_159 ;
else {
F_25 ( V_72 , V_190 , 0 ) ;
V_53 = - V_52 ;
goto V_189;
}
continue;
}
if ( V_164 -> V_17 == V_180 ) {
if ( ! V_70 || V_174 || V_175 ) {
F_25 ( V_72 , V_191 , 0 ) ;
V_53 = - V_52 ;
goto V_189;
}
if ( ! V_187 )
V_69 -> V_39 [ V_70 - 1 ] . V_10 ^= 1 ;
continue;
}
if ( F_24 ( V_70 ++ == V_188 ) ) {
F_25 ( V_72 , V_109 , 0 ) ;
V_53 = - V_95 ;
goto V_189;
}
V_2 = F_95 ( V_72 , V_173 , V_164 -> V_17 , V_174 , V_175 ) ;
if ( ! V_2 ) {
V_53 = - V_52 ;
goto V_189;
}
if ( ! V_187 ) {
V_53 = F_61 ( V_72 , V_69 , V_2 , & V_94 ) ;
if ( V_53 )
goto V_189;
}
V_174 = V_175 = NULL ;
}
if ( ! V_187 ) {
V_2 = F_46 ( & V_94 ) ;
if ( ! V_2 )
return - V_52 ;
V_47 = V_2 ;
V_2 = F_46 ( & V_94 ) ;
if ( F_24 ( V_2 ) ) {
V_53 = - V_52 ;
V_69 -> V_47 = NULL ;
goto V_189;
}
V_53 = F_100 ( V_69 , V_47 ) ;
if ( V_53 )
goto V_189;
V_53 = F_106 ( V_69 , V_47 ) ;
if ( V_53 )
goto V_189;
F_108 () ;
V_69 -> V_47 = V_47 ;
}
V_53 = 0 ;
V_189:
F_44 ( & V_94 ) ;
return V_53 ;
}
static inline void F_109 ( struct V_86 * V_87 )
{
unsigned long V_102 = V_87 -> V_103 ;
V_87 -> V_103 |= V_104 ;
if ( V_102 != V_87 -> V_103 )
F_110 () ;
}
static inline void F_111 ( struct V_86 * V_87 ,
struct V_68 * V_69 )
{
F_112 ( V_87 -> V_69 , V_69 ) ;
}
static inline void F_113 ( struct V_86 * V_87 )
{
F_114 ( V_87 -> V_69 , NULL ) ;
}
static inline void
F_115 ( struct V_86 * V_87 )
{
V_87 -> V_103 |= V_192 ;
}
static inline void
F_116 ( struct V_86 * V_87 )
{
V_87 -> V_103 &= ~ V_192 ;
}
static inline bool
F_117 ( struct V_86 * V_87 )
{
if ( V_87 -> V_103 & V_192 )
return true ;
return false ;
}
static int F_118 ( struct V_105 * V_106 ,
struct V_107 * V_108 ,
struct V_71 * V_72 ,
char * V_76 )
{
struct V_86 * V_87 ;
struct V_193 * V_194 ;
struct V_193 * V_195 ;
F_119 ( V_193 ) ;
bool V_189 = true ;
int V_53 ;
F_58 (file, &tr->events, list) {
if ( V_87 -> system != V_106 )
continue;
V_53 = F_107 ( V_87 -> V_196 , NULL , V_72 , true ) ;
if ( V_53 )
F_115 ( V_87 ) ;
else
F_116 ( V_87 ) ;
}
F_58 (file, &tr->events, list) {
struct V_68 * V_69 ;
if ( V_87 -> system != V_106 )
continue;
if ( F_117 ( V_87 ) )
continue;
V_194 = F_54 ( sizeof( * V_194 ) , V_77 ) ;
if ( ! V_194 )
goto V_197;
F_91 ( & V_194 -> V_162 , & V_193 ) ;
V_194 -> V_69 = F_53 () ;
if ( ! V_194 -> V_69 )
goto V_197;
V_69 = V_194 -> V_69 ;
V_53 = F_28 ( V_69 , V_76 ) ;
if ( V_53 )
goto V_197;
V_53 = F_107 ( V_87 -> V_196 , V_69 , V_72 , false ) ;
if ( V_53 ) {
F_49 ( V_87 ) ;
F_25 ( V_72 , V_198 , 0 ) ;
F_33 ( V_72 , V_69 ) ;
} else
F_109 ( V_87 ) ;
V_69 = V_68 ( V_87 ) ;
F_111 ( V_87 , V_194 -> V_69 ) ;
V_194 -> V_69 = V_69 ;
V_189 = false ;
}
if ( V_189 )
goto V_189;
F_120 () ;
F_121 (filter_item, tmp, &filter_list, list) {
F_51 ( V_194 -> V_69 ) ;
F_87 ( & V_194 -> V_162 ) ;
F_27 ( V_194 ) ;
}
return 0 ;
V_189:
F_121 (filter_item, tmp, &filter_list, list) {
F_87 ( & V_194 -> V_162 ) ;
F_27 ( V_194 ) ;
}
F_25 ( V_72 , V_198 , 0 ) ;
return - V_52 ;
V_197:
if ( ! V_189 )
F_120 () ;
F_121 (filter_item, tmp, &filter_list, list) {
F_51 ( V_194 -> V_69 ) ;
F_87 ( & V_194 -> V_162 ) ;
F_27 ( V_194 ) ;
}
return - V_78 ;
}
static int F_122 ( char * V_199 , bool V_200 ,
struct V_71 * * V_201 ,
struct V_68 * * V_202 )
{
struct V_68 * V_69 ;
struct V_71 * V_72 = NULL ;
int V_53 = 0 ;
F_20 ( * V_201 || * V_202 ) ;
V_69 = F_53 () ;
if ( V_69 && V_200 )
V_53 = F_28 ( V_69 , V_199 ) ;
V_72 = F_54 ( sizeof( * V_72 ) , V_77 ) ;
if ( ! V_69 || ! V_72 || V_53 ) {
F_27 ( V_72 ) ;
F_51 ( V_69 ) ;
return - V_78 ;
}
* V_202 = V_69 ;
* V_201 = V_72 ;
F_70 ( V_72 , V_203 , V_199 ) ;
V_53 = F_94 ( V_72 ) ;
if ( V_53 && V_200 )
F_33 ( V_72 , V_69 ) ;
return V_53 ;
}
static void F_123 ( struct V_71 * V_72 )
{
if ( V_72 ) {
F_88 ( V_72 ) ;
F_93 ( V_72 ) ;
F_27 ( V_72 ) ;
}
}
static int F_124 ( struct V_172 * V_173 ,
char * V_199 , bool V_200 ,
struct V_68 * * V_202 )
{
struct V_68 * V_69 = NULL ;
struct V_71 * V_72 = NULL ;
int V_53 ;
V_53 = F_122 ( V_199 , V_200 , & V_72 , & V_69 ) ;
if ( ! V_53 ) {
V_53 = F_107 ( V_173 , V_69 , V_72 , false ) ;
if ( V_53 && V_200 )
F_33 ( V_72 , V_69 ) ;
}
F_123 ( V_72 ) ;
* V_202 = V_69 ;
return V_53 ;
}
int F_125 ( struct V_172 * V_173 ,
char * V_199 , bool V_200 ,
struct V_68 * * V_202 )
{
return F_124 ( V_173 , V_199 , V_200 , V_202 ) ;
}
static int F_126 ( struct V_105 * V_106 ,
struct V_107 * V_108 ,
char * V_199 , struct V_68 * * V_202 )
{
struct V_68 * V_69 = NULL ;
struct V_71 * V_72 = NULL ;
int V_53 ;
V_53 = F_122 ( V_199 , true , & V_72 , & V_69 ) ;
if ( ! V_53 ) {
V_53 = F_118 ( V_106 , V_108 , V_72 , V_199 ) ;
if ( ! V_53 ) {
F_27 ( V_69 -> V_76 ) ;
V_69 -> V_76 = NULL ;
} else {
F_33 ( V_72 , V_69 ) ;
}
}
F_123 ( V_72 ) ;
* V_202 = V_69 ;
return V_53 ;
}
int F_127 ( struct V_86 * V_87 , char * V_76 )
{
struct V_172 * V_173 = V_87 -> V_196 ;
struct V_68 * V_69 ;
int V_53 ;
if ( ! strcmp ( F_128 ( V_76 ) , L_10 ) ) {
F_49 ( V_87 ) ;
V_69 = V_68 ( V_87 ) ;
if ( ! V_69 )
return 0 ;
F_113 ( V_87 ) ;
F_120 () ;
F_51 ( V_69 ) ;
return 0 ;
}
V_53 = F_124 ( V_173 , V_76 , true , & V_69 ) ;
if ( V_69 ) {
struct V_68 * V_195 ;
V_195 = V_68 ( V_87 ) ;
if ( ! V_53 )
F_109 ( V_87 ) ;
else
F_49 ( V_87 ) ;
F_111 ( V_87 , V_69 ) ;
if ( V_195 ) {
F_120 () ;
F_51 ( V_195 ) ;
}
}
return V_53 ;
}
int F_129 ( struct V_105 * V_106 ,
char * V_76 )
{
struct V_90 * system = V_106 -> V_204 ;
struct V_107 * V_108 = V_106 -> V_108 ;
struct V_68 * V_69 ;
int V_53 = 0 ;
F_40 ( & V_91 ) ;
if ( ! V_106 -> V_205 ) {
V_53 = - V_206 ;
goto V_207;
}
if ( ! strcmp ( F_128 ( V_76 ) , L_10 ) ) {
F_57 ( V_106 , V_108 ) ;
F_26 ( system -> V_69 ) ;
V_69 = system -> V_69 ;
system -> V_69 = NULL ;
F_120 () ;
F_60 ( V_106 , V_108 ) ;
F_51 ( V_69 ) ;
goto V_207;
}
V_53 = F_126 ( V_106 , V_108 , V_76 , & V_69 ) ;
if ( V_69 ) {
F_51 ( system -> V_69 ) ;
system -> V_69 = V_69 ;
}
V_207:
F_41 ( & V_91 ) ;
return V_53 ;
}
void F_130 ( struct V_208 * V_3 )
{
struct V_68 * V_69 = V_3 -> V_69 ;
V_3 -> V_69 = NULL ;
F_51 ( V_69 ) ;
}
static char * *
F_131 ( char * V_81 , int V_11 , int * V_183 )
{
char * V_25 , * * V_209 ;
V_25 = F_132 ( V_81 , V_11 , V_77 ) ;
if ( ! V_25 )
return NULL ;
F_133 ( V_25 , ',' , ' ' ) ;
V_209 = F_134 ( V_77 , V_25 , V_183 ) ;
F_27 ( V_25 ) ;
return V_209 ;
}
static int F_135 ( struct V_210 * V_63 , int V_69 ,
int V_211 , char * V_209 , int V_11 )
{
int V_54 ;
if ( V_69 )
V_54 = F_136 ( V_63 , V_209 , V_11 , V_211 ) ;
else
V_54 = F_137 ( V_63 , V_209 , V_11 , V_211 ) ;
return V_54 ;
}
static int F_138 ( int V_69 , char * V_81 , int V_11 ,
struct V_212 * V_49 )
{
int V_33 , V_213 , V_54 = - V_52 ;
int * V_211 ;
char * * V_209 ;
V_211 = V_69 ? & V_49 -> V_214 : & V_49 -> V_215 ;
V_209 = F_131 ( V_81 , V_11 , & V_213 ) ;
if ( ! V_209 )
return - V_52 ;
for ( V_33 = 0 ; V_33 < V_213 ; V_33 ++ ) {
V_54 = F_135 ( V_49 -> V_63 , V_69 , * V_211 ,
V_209 [ V_33 ] , strlen ( V_209 [ V_33 ] ) ) ;
if ( V_54 )
break;
if ( * V_211 )
* V_211 = 0 ;
}
F_139 ( V_209 ) ;
return V_54 ;
}
static int F_140 ( struct V_1 * V_2 , int V_216 )
{
struct V_113 * V_114 = V_2 -> V_114 ;
if ( V_216 ) {
if ( ( V_2 -> V_17 != V_18 ) && ( V_2 -> V_17 != V_116 ) )
return - V_52 ;
if ( strcmp ( V_114 -> V_137 , L_8 ) )
return - V_52 ;
} else {
if ( V_2 -> V_17 != V_62 )
return - V_52 ;
}
return 0 ;
}
static int F_141 ( enum V_41 V_42 ,
struct V_1 * V_2 ,
int * V_53 , void * V_49 )
{
if ( ( V_42 != V_50 ) ||
( V_2 -> V_58 != V_59 ) ) {
* V_53 = F_140 ( V_2 , 0 ) ;
} else {
* V_53 = F_140 ( V_2 , 1 ) ;
if ( * V_53 )
return V_55 ;
* V_53 = F_138 ( V_2 -> V_17 == V_18 ,
V_2 -> V_8 . V_27 ,
V_2 -> V_8 . V_11 ,
V_49 ) ;
}
return ( * V_53 ) ? V_55 : V_67 ;
}
static int F_142 ( struct V_208 * V_3 ,
struct V_68 * V_69 )
{
struct V_212 V_49 = {
. V_214 = 1 ,
. V_215 = 1 ,
. V_63 = & V_3 -> V_210 ,
} ;
return F_18 ( V_69 -> V_39 , V_69 -> V_47 ,
F_141 , & V_49 ) ;
}
static int F_142 ( struct V_208 * V_3 ,
struct V_68 * V_69 )
{
return - V_206 ;
}
int F_143 ( struct V_208 * V_3 , int V_217 ,
char * V_199 )
{
int V_53 ;
struct V_68 * V_69 ;
struct V_172 * V_173 ;
F_40 ( & V_91 ) ;
V_173 = V_3 -> V_218 ;
V_53 = - V_52 ;
if ( ! V_173 )
goto V_207;
V_53 = - V_219 ;
if ( V_3 -> V_69 )
goto V_207;
V_53 = F_124 ( V_173 , V_199 , false , & V_69 ) ;
if ( V_53 )
goto V_220;
if ( F_144 ( V_173 ) )
V_53 = F_142 ( V_3 , V_69 ) ;
else
V_3 -> V_69 = V_69 ;
V_220:
if ( V_53 || F_144 ( V_173 ) )
F_51 ( V_69 ) ;
V_207:
F_41 ( & V_91 ) ;
return V_53 ;
}
static int F_145 ( struct V_1 * V_2 , void * V_3 )
{
struct V_113 * V_114 = V_2 -> V_114 ;
V_221 = 1 ;
F_146 ( V_222 L_11 , V_114 -> V_137 ) ;
return 1 ;
}
static int F_147 ( enum V_41 V_42 , struct V_1 * V_2 ,
int * V_53 , void * V_49 )
{
char * V_223 = V_49 ;
if ( ( V_42 == V_50 ) &&
( V_2 -> V_58 == V_59 ) ) {
struct V_113 * V_114 = V_2 -> V_114 ;
if ( ! V_114 ) {
F_148 ( 1 , L_12 ) ;
return V_67 ;
}
if ( ! strchr ( V_223 , * V_114 -> V_137 ) )
return V_67 ;
F_24 ( ! V_2 -> V_64 ) ;
V_2 -> V_64 = F_145 ;
}
return V_67 ;
}
static T_4 int F_149 ( void )
{
int V_33 ;
F_146 ( V_222 L_13 ) ;
for ( V_33 = 0 ; V_33 < V_224 ; V_33 ++ ) {
struct V_68 * V_69 = NULL ;
struct V_225 * V_66 = & V_226 [ V_33 ] ;
int V_53 ;
V_53 = F_124 ( & V_227 , V_66 -> V_69 ,
false , & V_69 ) ;
if ( V_53 ) {
F_146 ( V_222
L_14 ,
V_66 -> V_69 , V_53 ) ;
F_51 ( V_69 ) ;
break;
}
F_150 () ;
if ( * V_66 -> V_228 )
F_18 ( V_69 -> V_39 , V_69 -> V_47 ,
F_147 ,
V_66 -> V_228 ) ;
V_221 = 0 ;
V_53 = F_22 ( V_69 , & V_66 -> V_61 ) ;
F_151 () ;
F_51 ( V_69 ) ;
if ( V_221 ) {
F_146 ( V_222
L_15 ,
V_66 -> V_69 ) ;
break;
}
if ( V_53 != V_66 -> V_7 ) {
F_146 ( V_222
L_16 ,
V_66 -> V_69 , V_66 -> V_7 ) ;
break;
}
}
if ( V_33 == V_224 )
F_146 ( V_229 L_17 ) ;
return 0 ;
}
