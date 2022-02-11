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
if ( V_85 -> V_86 -> V_87 & V_88 )
return V_85 -> V_86 -> V_67 ;
else
return V_85 -> V_67 ;
}
void F_34 ( struct V_84 * V_85 , struct V_89 * V_90 )
{
struct V_66 * V_67 = V_66 ( V_85 ) ;
if ( V_67 && V_67 -> V_74 )
F_35 ( V_90 , L_3 , V_67 -> V_74 ) ;
else
F_36 ( V_90 , L_4 ) ;
}
void F_37 ( struct V_91 * system ,
struct V_89 * V_90 )
{
struct V_66 * V_67 ;
F_38 ( & V_92 ) ;
V_67 = system -> V_67 ;
if ( V_67 && V_67 -> V_74 )
F_35 ( V_90 , L_3 , V_67 -> V_74 ) ;
else
F_36 ( V_90 , V_93 L_1 ) ;
F_39 ( & V_92 ) ;
}
static int F_40 ( struct V_94 * V_95 , int V_68 )
{
V_95 -> V_37 = F_41 ( V_68 + 1 , sizeof( * V_95 -> V_37 ) , V_75 ) ;
if ( ! V_95 -> V_37 )
return - V_76 ;
V_95 -> V_38 = V_68 ;
return 0 ;
}
static void F_42 ( struct V_94 * V_95 )
{
F_25 ( V_95 -> V_37 ) ;
V_95 -> V_38 = 0 ;
}
static int F_43 ( struct V_94 * V_95 ,
struct V_1 * V_2 )
{
int V_38 = V_95 -> V_38 ;
if ( F_22 ( V_38 == 0 ) )
return - V_96 ;
V_95 -> V_37 [ -- V_38 ] = V_2 ;
V_95 -> V_38 = V_38 ;
return 0 ;
}
static struct V_1 *
F_44 ( struct V_94 * V_95 )
{
struct V_1 * V_2 ;
int V_38 = V_95 -> V_38 ;
V_2 = V_95 -> V_37 [ V_38 ++ ] ;
if ( ! V_2 )
return NULL ;
V_95 -> V_38 = V_38 ;
return V_2 ;
}
static int F_45 ( struct V_66 * V_67 ,
int V_97 ,
struct V_94 * V_95 ,
struct V_1 * V_98 )
{
struct V_1 * V_99 = & V_67 -> V_37 [ V_97 ] ;
struct V_1 * V_56 ;
struct V_1 * V_58 ;
* V_99 = * V_98 ;
V_99 -> V_38 = V_97 ;
if ( V_99 -> V_17 == V_60 || V_99 -> V_17 == V_100 ) {
V_58 = F_44 ( V_95 ) ;
V_56 = F_44 ( V_95 ) ;
if ( ! V_56 || ! V_58 )
return - V_50 ;
if ( V_56 -> V_38 & V_101 &&
( ( V_56 -> V_17 == V_99 -> V_17 && ! V_56 -> V_10 ) ||
V_56 -> V_56 == V_57 ) &&
V_58 -> V_38 & V_101 &&
( ( V_58 -> V_17 == V_99 -> V_17 && ! V_58 -> V_10 ) ||
V_58 -> V_56 == V_57 ) )
V_99 -> V_38 |= V_101 ;
V_99 -> V_56 = V_56 -> V_38 & ~ V_101 ;
V_99 -> V_58 = V_58 -> V_38 & ~ V_101 ;
V_56 -> V_41 = V_99 -> V_38 & ~ V_101 ;
V_58 -> V_41 = V_99 -> V_38 | V_42 ;
} else {
V_99 -> V_56 = V_57 ;
V_99 -> V_38 |= V_101 ;
}
return F_43 ( V_95 , V_99 ) ;
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
V_67 -> V_102 = 0 ;
V_67 -> V_68 = 0 ;
}
static void F_47 ( struct V_84 * V_85 )
{
struct V_103 * V_104 = V_85 -> V_86 ;
if ( V_104 -> V_87 & V_88 )
V_104 -> V_87 &= ~ V_105 ;
else
V_85 -> V_87 &= ~ V_106 ;
}
static void F_48 ( struct V_66 * V_67 )
{
if ( ! V_67 )
return;
F_46 ( V_67 ) ;
F_25 ( V_67 -> V_74 ) ;
F_25 ( V_67 ) ;
}
void F_49 ( struct V_66 * V_67 )
{
F_48 ( V_67 ) ;
}
static struct V_66 * F_50 ( void )
{
struct V_66 * V_67 ;
V_67 = F_51 ( sizeof( * V_67 ) , V_75 ) ;
return V_67 ;
}
static int F_52 ( struct V_66 * V_67 , int V_68 )
{
struct V_1 * V_2 ;
int V_32 ;
if ( V_67 -> V_37 )
F_46 ( V_67 ) ;
V_67 -> V_37 = F_41 ( V_68 , sizeof( * V_67 -> V_37 ) , V_75 ) ;
if ( ! V_67 -> V_37 )
return - V_76 ;
V_67 -> V_102 = V_68 ;
V_67 -> V_68 = 0 ;
for ( V_32 = 0 ; V_32 < V_68 ; V_32 ++ ) {
V_2 = & V_67 -> V_37 [ V_32 ] ;
V_2 -> V_62 = F_7 ;
}
return 0 ;
}
static inline void F_53 ( struct V_84 * V_85 )
{
struct V_103 * V_104 = V_85 -> V_86 ;
F_47 ( V_85 ) ;
if ( V_104 -> V_87 & V_88 )
F_24 ( V_104 -> V_67 ) ;
else
F_24 ( V_85 -> V_67 ) ;
}
static void F_54 ( struct V_107 * V_108 ,
struct V_109 * V_110 )
{
struct V_84 * V_85 ;
F_55 (file, &tr->events, list) {
if ( V_85 -> system != V_108 )
continue;
F_53 ( V_85 ) ;
}
}
static inline void F_56 ( struct V_84 * V_85 )
{
struct V_103 * V_104 = V_85 -> V_86 ;
if ( V_104 -> V_87 & V_88 ) {
F_48 ( V_104 -> V_67 ) ;
V_104 -> V_67 = NULL ;
} else {
F_48 ( V_85 -> V_67 ) ;
V_85 -> V_67 = NULL ;
}
}
static void F_57 ( struct V_107 * V_108 ,
struct V_109 * V_110 )
{
struct V_84 * V_85 ;
F_55 (file, &tr->events, list) {
if ( V_85 -> system != V_108 )
continue;
F_56 ( V_85 ) ;
}
}
static int F_58 ( struct V_69 * V_70 ,
struct V_66 * V_67 ,
struct V_1 * V_2 ,
struct V_94 * V_95 )
{
int V_51 ;
if ( F_22 ( V_67 -> V_68 == V_67 -> V_102 ) ) {
F_23 ( V_70 , V_111 , 0 ) ;
return - V_96 ;
}
V_51 = F_45 ( V_67 , V_67 -> V_68 , V_95 , V_2 ) ;
if ( V_51 )
return V_51 ;
V_67 -> V_68 ++ ;
return 0 ;
}
int F_59 ( const char * type )
{
if ( strstr ( type , L_5 ) && strstr ( type , L_6 ) )
return V_112 ;
if ( strchr ( type , '[' ) && strstr ( type , L_6 ) )
return V_113 ;
return V_114 ;
}
static bool F_60 ( struct V_115 * V_116 )
{
return V_116 -> V_117 == V_118 ;
}
static bool F_61 ( struct V_115 * V_116 )
{
return V_116 -> V_117 == V_112 ||
V_116 -> V_117 == V_113 ||
V_116 -> V_117 == V_119 ;
}
static bool F_62 ( struct V_115 * V_116 , int V_17 )
{
if ( F_61 ( V_116 ) &&
( V_17 != V_18 && V_17 != V_120 && V_17 != V_36 ) )
return false ;
if ( ! F_61 ( V_116 ) && V_17 == V_36 )
return false ;
return true ;
}
static T_3 F_63 ( int V_17 , int V_121 ,
int V_122 )
{
T_3 V_62 = NULL ;
switch ( V_121 ) {
case 8 :
if ( V_17 == V_18 || V_17 == V_120 )
V_62 = V_123 ;
else if ( V_122 )
V_62 = V_124 ;
else
V_62 = V_125 ;
break;
case 4 :
if ( V_17 == V_18 || V_17 == V_120 )
V_62 = V_126 ;
else if ( V_122 )
V_62 = V_127 ;
else
V_62 = V_128 ;
break;
case 2 :
if ( V_17 == V_18 || V_17 == V_120 )
V_62 = V_129 ;
else if ( V_122 )
V_62 = V_130 ;
else
V_62 = V_131 ;
break;
case 1 :
if ( V_17 == V_18 || V_17 == V_120 )
V_62 = V_132 ;
else if ( V_122 )
V_62 = V_133 ;
else
V_62 = V_134 ;
break;
}
return V_62 ;
}
static int F_64 ( struct V_69 * V_70 ,
struct V_115 * V_116 ,
struct V_1 * V_2 )
{
T_3 V_62 = F_7 ;
unsigned long long V_16 ;
int V_52 ;
V_2 -> V_5 = V_116 -> V_5 ;
if ( ! F_62 ( V_116 , V_2 -> V_17 ) ) {
F_23 ( V_70 , V_135 , 0 ) ;
return - V_50 ;
}
if ( F_61 ( V_116 ) ) {
F_14 ( V_2 ) ;
if ( ! strcmp ( V_116 -> V_136 , L_7 ) ) {
V_62 = F_6 ;
V_2 -> V_8 . V_9 = V_137 ;
} else if ( V_116 -> V_117 == V_113 ) {
V_62 = F_1 ;
V_2 -> V_8 . V_9 = V_116 -> V_138 ;
} else if ( V_116 -> V_117 == V_112 )
V_62 = F_3 ;
else
V_62 = F_2 ;
} else if ( F_60 ( V_116 ) ) {
if ( strcmp ( V_116 -> V_136 , L_8 ) ) {
F_23 ( V_70 , V_139 , 0 ) ;
return - V_50 ;
}
} else {
if ( V_116 -> V_140 )
V_52 = F_65 ( V_2 -> V_8 . V_27 , 0 , & V_16 ) ;
else
V_52 = F_66 ( V_2 -> V_8 . V_27 , 0 , & V_16 ) ;
if ( V_52 ) {
F_23 ( V_70 , V_141 , 0 ) ;
return - V_50 ;
}
V_2 -> V_16 = V_16 ;
if ( ! strcmp ( V_116 -> V_136 , L_9 ) )
V_62 = F_4 ;
else
V_62 = F_63 ( V_2 -> V_17 , V_116 -> V_138 ,
V_116 -> V_140 ) ;
if ( ! V_62 ) {
F_23 ( V_70 , V_142 , 0 ) ;
return - V_50 ;
}
}
if ( V_2 -> V_17 == V_120 )
V_2 -> V_10 ^= 1 ;
V_2 -> V_62 = V_62 ;
return 0 ;
}
static void F_67 ( struct V_69 * V_70 ,
struct V_143 * V_61 ,
char * V_144 )
{
memset ( V_70 , '\0' , sizeof( * V_70 ) ) ;
V_70 -> V_145 . string = V_144 ;
V_70 -> V_145 . V_146 = strlen ( V_144 ) ;
V_70 -> V_61 = V_61 ;
F_68 ( & V_70 -> V_147 ) ;
F_68 ( & V_70 -> V_148 ) ;
}
static char F_69 ( struct V_69 * V_70 )
{
if ( ! V_70 -> V_145 . V_146 )
return 0 ;
V_70 -> V_145 . V_146 -- ;
return V_70 -> V_145 . string [ V_70 -> V_145 . V_149 ++ ] ;
}
static char F_70 ( struct V_69 * V_70 )
{
if ( V_70 -> V_145 . V_149 == strlen ( V_70 -> V_145 . string ) )
return 0 ;
return V_70 -> V_145 . string [ V_70 -> V_145 . V_149 ] ;
}
static void F_71 ( struct V_69 * V_70 )
{
if ( ! V_70 -> V_145 . V_146 )
return;
V_70 -> V_145 . V_146 -- ;
V_70 -> V_145 . V_149 ++ ;
}
static inline int F_72 ( struct V_69 * V_70 ,
int V_150 , int V_151 )
{
return V_70 -> V_61 [ V_150 ] . V_152 < V_70 -> V_61 [ V_151 ] . V_152 ;
}
static inline int F_73 ( struct V_69 * V_70 , char V_153 )
{
int V_32 ;
for ( V_32 = 0 ; strcmp ( V_70 -> V_61 [ V_32 ] . string , L_10 ) ; V_32 ++ ) {
if ( V_70 -> V_61 [ V_32 ] . string [ 0 ] == V_153 )
return 1 ;
}
return 0 ;
}
static int F_74 ( struct V_69 * V_70 , char V_154 )
{
char V_155 = F_70 ( V_70 ) ;
char V_156 [ 3 ] ;
int V_32 ;
V_156 [ 0 ] = V_154 ;
V_156 [ 1 ] = V_155 ;
V_156 [ 2 ] = '\0' ;
for ( V_32 = 0 ; strcmp ( V_70 -> V_61 [ V_32 ] . string , L_10 ) ; V_32 ++ ) {
if ( ! strcmp ( V_156 , V_70 -> V_61 [ V_32 ] . string ) ) {
F_71 ( V_70 ) ;
return V_70 -> V_61 [ V_32 ] . V_157 ;
}
}
V_156 [ 1 ] = '\0' ;
for ( V_32 = 0 ; strcmp ( V_70 -> V_61 [ V_32 ] . string , L_10 ) ; V_32 ++ ) {
if ( ! strcmp ( V_156 , V_70 -> V_61 [ V_32 ] . string ) )
return V_70 -> V_61 [ V_32 ] . V_157 ;
}
return V_158 ;
}
static inline void F_75 ( struct V_69 * V_70 )
{
memset ( V_70 -> V_159 . string , '\0' , V_160 ) ;
V_70 -> V_159 . V_149 = 0 ;
}
static inline int F_76 ( struct V_69 * V_70 , char V_153 )
{
if ( V_70 -> V_159 . V_149 == V_160 - 1 )
return - V_50 ;
V_70 -> V_159 . string [ V_70 -> V_159 . V_149 ++ ] = V_153 ;
return 0 ;
}
static int F_77 ( struct V_69 * V_70 , int V_17 )
{
struct V_161 * V_161 ;
V_161 = F_30 ( sizeof( * V_161 ) , V_75 ) ;
if ( ! V_161 )
return - V_76 ;
V_161 -> V_17 = V_17 ;
F_78 ( & V_161 -> V_162 , & V_70 -> V_147 ) ;
return 0 ;
}
static int F_79 ( struct V_69 * V_70 )
{
return F_80 ( & V_70 -> V_147 ) ;
}
static int F_81 ( struct V_69 * V_70 )
{
struct V_161 * V_161 ;
if ( F_79 ( V_70 ) )
return V_158 ;
V_161 = F_82 ( & V_70 -> V_147 , struct V_161 , V_162 ) ;
return V_161 -> V_17 ;
}
static int F_83 ( struct V_69 * V_70 )
{
struct V_161 * V_161 ;
int V_17 ;
if ( F_79 ( V_70 ) )
return V_158 ;
V_161 = F_82 ( & V_70 -> V_147 , struct V_161 , V_162 ) ;
V_17 = V_161 -> V_17 ;
F_84 ( & V_161 -> V_162 ) ;
F_25 ( V_161 ) ;
return V_17 ;
}
static void F_85 ( struct V_69 * V_70 )
{
while ( ! F_79 ( V_70 ) )
F_83 ( V_70 ) ;
}
static char * F_86 ( struct V_69 * V_70 )
{
return V_70 -> V_159 . string ;
}
static int F_87 ( struct V_69 * V_70 , char * V_159 )
{
struct V_163 * V_164 ;
V_164 = F_30 ( sizeof( * V_164 ) , V_75 ) ;
if ( ! V_164 )
return - V_76 ;
V_164 -> V_17 = V_158 ;
V_164 -> V_159 = F_27 ( V_159 , V_75 ) ;
if ( ! V_164 -> V_159 ) {
F_25 ( V_164 ) ;
return - V_76 ;
}
F_88 ( & V_164 -> V_162 , & V_70 -> V_148 ) ;
return 0 ;
}
static int F_89 ( struct V_69 * V_70 , int V_17 )
{
struct V_163 * V_164 ;
V_164 = F_30 ( sizeof( * V_164 ) , V_75 ) ;
if ( ! V_164 )
return - V_76 ;
V_164 -> V_17 = V_17 ;
V_164 -> V_159 = NULL ;
F_88 ( & V_164 -> V_162 , & V_70 -> V_148 ) ;
return 0 ;
}
static void F_90 ( struct V_69 * V_70 )
{
struct V_163 * V_164 ;
while ( ! F_80 ( & V_70 -> V_148 ) ) {
V_164 = F_82 ( & V_70 -> V_148 , struct V_163 , V_162 ) ;
F_84 ( & V_164 -> V_162 ) ;
F_25 ( V_164 -> V_159 ) ;
F_25 ( V_164 ) ;
}
}
static int F_91 ( struct V_69 * V_70 )
{
int V_165 = 0 ;
int V_17 , V_166 ;
char V_167 ;
while ( ( V_167 = F_69 ( V_70 ) ) ) {
if ( V_167 == '"' ) {
V_165 ^= 1 ;
continue;
}
if ( V_165 )
goto V_168;
if ( isspace ( V_167 ) )
continue;
if ( F_73 ( V_70 , V_167 ) ) {
V_17 = F_74 ( V_70 , V_167 ) ;
if ( V_17 == V_158 ) {
F_23 ( V_70 , V_142 , 0 ) ;
return - V_50 ;
}
if ( strlen ( F_86 ( V_70 ) ) ) {
F_87 ( V_70 , F_86 ( V_70 ) ) ;
F_75 ( V_70 ) ;
}
while ( ! F_79 ( V_70 ) ) {
V_166 = F_81 ( V_70 ) ;
if ( ! F_72 ( V_70 , V_166 , V_17 ) ) {
V_166 = F_83 ( V_70 ) ;
F_89 ( V_70 , V_166 ) ;
continue;
}
break;
}
F_77 ( V_70 , V_17 ) ;
continue;
}
if ( V_167 == '(' ) {
F_77 ( V_70 , V_169 ) ;
continue;
}
if ( V_167 == ')' ) {
if ( strlen ( F_86 ( V_70 ) ) ) {
F_87 ( V_70 , F_86 ( V_70 ) ) ;
F_75 ( V_70 ) ;
}
V_166 = F_83 ( V_70 ) ;
while ( V_166 != V_158 ) {
if ( V_166 == V_169 )
break;
F_89 ( V_70 , V_166 ) ;
V_166 = F_83 ( V_70 ) ;
}
if ( V_166 == V_158 ) {
F_23 ( V_70 , V_170 , 0 ) ;
return - V_50 ;
}
continue;
}
V_168:
if ( F_76 ( V_70 , V_167 ) ) {
F_23 ( V_70 , V_171 , 0 ) ;
return - V_50 ;
}
}
if ( strlen ( F_86 ( V_70 ) ) )
F_87 ( V_70 , F_86 ( V_70 ) ) ;
while ( ! F_79 ( V_70 ) ) {
V_166 = F_83 ( V_70 ) ;
if ( V_166 == V_158 )
break;
if ( V_166 == V_169 ) {
F_23 ( V_70 , V_170 , 0 ) ;
return - V_50 ;
}
F_89 ( V_70 , V_166 ) ;
}
return 0 ;
}
static struct V_1 * F_92 ( struct V_69 * V_70 ,
struct V_103 * V_104 ,
int V_17 , char * V_172 , char * V_173 )
{
struct V_115 * V_116 ;
static struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_17 = V_17 ;
if ( V_17 == V_100 || V_17 == V_60 )
return & V_2 ;
if ( ! V_172 || ! V_173 ) {
F_23 ( V_70 , V_174 , 0 ) ;
return NULL ;
}
V_116 = F_93 ( V_104 , V_172 ) ;
if ( ! V_116 ) {
F_23 ( V_70 , V_175 , 0 ) ;
return NULL ;
}
strcpy ( V_2 . V_8 . V_27 , V_173 ) ;
V_2 . V_8 . V_11 = strlen ( V_2 . V_8 . V_27 ) ;
V_2 . V_116 = V_116 ;
return F_64 ( V_70 , V_116 , & V_2 ) ? NULL : & V_2 ;
}
static int F_94 ( struct V_69 * V_70 )
{
int V_176 = 0 , V_177 = 0 ;
struct V_163 * V_164 ;
int V_146 = 0 ;
F_55 (elt, &ps->postfix, list) {
if ( V_164 -> V_17 == V_158 ) {
V_146 ++ ;
continue;
}
if ( V_164 -> V_17 == V_100 || V_164 -> V_17 == V_60 ) {
V_177 ++ ;
V_146 -- ;
continue;
}
if ( V_164 -> V_17 != V_178 )
V_146 -- ;
V_176 ++ ;
if ( V_146 < 0 )
break;
}
if ( V_146 != 1 || ! V_176 || V_177 >= V_176 ) {
F_23 ( V_70 , V_179 , 0 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_95 ( struct V_69 * V_70 )
{
struct V_163 * V_164 ;
int V_68 = 0 ;
F_55 (elt, &ps->postfix, list) {
if ( V_164 -> V_17 == V_158 )
continue;
V_68 ++ ;
}
return V_68 ;
}
static int F_96 ( enum V_39 V_40 , struct V_1 * V_2 ,
int * V_51 , void * V_47 )
{
struct V_180 * V_64 = V_47 ;
if ( F_22 ( V_64 -> V_181 ++ > V_64 -> V_182 ) ) {
* V_51 = - V_50 ;
return V_53 ;
}
return V_65 ;
}
static int F_97 ( struct V_66 * V_67 ,
struct V_1 * V_45 )
{
struct V_180 V_47 = {
. V_182 = 3 * V_67 -> V_68 ,
. V_181 = 0 ,
} ;
return F_16 ( V_67 -> V_37 , V_45 ,
F_96 , & V_47 ) ;
}
static int F_98 ( enum V_39 V_40 , struct V_1 * V_2 ,
int * V_51 , void * V_47 )
{
int * V_181 = V_47 ;
if ( ( V_40 == V_48 ) &&
( V_2 -> V_56 == V_57 ) )
( * V_181 ) ++ ;
return V_65 ;
}
static int F_99 ( struct V_1 * V_37 , struct V_1 * V_45 )
{
int V_181 = 0 , V_52 ;
V_52 = F_16 ( V_37 , V_45 , F_98 , & V_181 ) ;
F_22 ( V_52 ) ;
return V_181 ;
}
static int F_100 ( enum V_39 V_40 , struct V_1 * V_2 ,
int * V_51 , void * V_47 )
{
struct V_183 * V_64 = V_47 ;
struct V_1 * V_45 = V_64 -> V_45 ;
if ( V_40 != V_48 )
return V_65 ;
if ( V_2 -> V_56 != V_57 )
return V_65 ;
if ( F_22 ( V_64 -> V_181 == V_64 -> V_184 ) ) {
* V_51 = - V_50 ;
return V_53 ;
}
V_2 -> V_38 &= ~ V_101 ;
V_45 -> V_61 [ V_64 -> V_181 ++ ] = V_2 -> V_38 ;
return V_65 ;
}
static int F_101 ( struct V_1 * V_37 , struct V_1 * V_45 )
{
struct V_183 V_47 = {
. V_45 = V_45 ,
. V_181 = 0 ,
} ;
int V_184 ;
V_45 -> V_38 &= ~ V_101 ;
if ( V_45 -> V_56 == V_57 )
return 0 ;
V_184 = F_99 ( V_37 , & V_37 [ V_45 -> V_56 ] ) ;
V_184 += F_99 ( V_37 , & V_37 [ V_45 -> V_58 ] ) ;
V_45 -> V_61 = F_41 ( V_184 , sizeof( * V_45 -> V_61 ) , V_75 ) ;
if ( ! V_45 -> V_61 )
return - V_76 ;
V_45 -> V_16 = V_184 ;
V_47 . V_184 = V_184 ;
return F_16 ( V_37 , V_45 , F_100 , & V_47 ) ;
}
static int F_102 ( enum V_39 V_40 , struct V_1 * V_2 ,
int * V_51 , void * V_47 )
{
struct V_1 * V_37 = V_47 ;
if ( V_40 != V_48 )
return V_65 ;
if ( ! ( V_2 -> V_38 & V_101 ) )
return V_65 ;
* V_51 = F_101 ( V_37 , V_2 ) ;
if ( * V_51 )
return V_53 ;
return V_54 ;
}
static int F_103 ( struct V_66 * V_67 ,
struct V_1 * V_45 )
{
return F_16 ( V_67 -> V_37 , V_45 , F_102 ,
V_67 -> V_37 ) ;
}
static int F_104 ( struct V_103 * V_104 ,
struct V_66 * V_67 ,
struct V_69 * V_70 ,
bool V_185 )
{
char * V_172 = NULL , * V_173 = NULL ;
struct V_1 * V_2 ;
struct V_1 * V_45 ;
struct V_163 * V_164 ;
struct V_94 V_95 = { } ;
int V_51 ;
int V_68 = 0 ;
V_68 = F_95 ( V_70 ) ;
if ( V_68 >= V_186 ) {
F_23 ( V_70 , V_111 , 0 ) ;
return - V_96 ;
}
V_51 = F_94 ( V_70 ) ;
if ( V_51 )
return V_51 ;
if ( ! V_185 ) {
V_51 = F_40 ( & V_95 , V_68 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_52 ( V_67 , V_68 ) ;
if ( V_51 )
goto V_187;
}
V_68 = 0 ;
F_55 (elt, &ps->postfix, list) {
if ( V_164 -> V_17 == V_158 ) {
if ( ! V_172 )
V_172 = V_164 -> V_159 ;
else if ( ! V_173 )
V_173 = V_164 -> V_159 ;
else {
F_23 ( V_70 , V_188 , 0 ) ;
V_51 = - V_50 ;
goto V_187;
}
continue;
}
if ( V_164 -> V_17 == V_178 ) {
if ( ! V_68 || V_172 || V_173 ) {
F_23 ( V_70 , V_189 , 0 ) ;
V_51 = - V_50 ;
goto V_187;
}
if ( ! V_185 )
V_67 -> V_37 [ V_68 - 1 ] . V_10 ^= 1 ;
continue;
}
if ( F_22 ( V_68 ++ == V_186 ) ) {
F_23 ( V_70 , V_111 , 0 ) ;
V_51 = - V_96 ;
goto V_187;
}
V_2 = F_92 ( V_70 , V_104 , V_164 -> V_17 , V_172 , V_173 ) ;
if ( ! V_2 ) {
V_51 = - V_50 ;
goto V_187;
}
if ( ! V_185 ) {
V_51 = F_58 ( V_70 , V_67 , V_2 , & V_95 ) ;
if ( V_51 )
goto V_187;
}
V_172 = V_173 = NULL ;
}
if ( ! V_185 ) {
V_2 = F_44 ( & V_95 ) ;
if ( ! V_2 )
return - V_50 ;
V_45 = V_2 ;
V_2 = F_44 ( & V_95 ) ;
if ( F_22 ( V_2 ) ) {
V_51 = - V_50 ;
V_67 -> V_45 = NULL ;
goto V_187;
}
V_51 = F_97 ( V_67 , V_45 ) ;
if ( V_51 )
goto V_187;
V_51 = F_103 ( V_67 , V_45 ) ;
if ( V_51 )
goto V_187;
F_105 () ;
V_67 -> V_45 = V_45 ;
}
V_51 = 0 ;
V_187:
F_42 ( & V_95 ) ;
return V_51 ;
}
static inline void F_106 ( struct V_84 * V_85 )
{
struct V_103 * V_104 = V_85 -> V_86 ;
if ( V_104 -> V_87 & V_88 )
V_104 -> V_87 |= V_105 ;
else
V_85 -> V_87 |= V_106 ;
}
static inline void F_107 ( struct V_84 * V_85 ,
struct V_66 * V_67 )
{
struct V_103 * V_104 = V_85 -> V_86 ;
if ( V_104 -> V_87 & V_88 )
F_108 ( V_104 -> V_67 , V_67 ) ;
else
F_108 ( V_85 -> V_67 , V_67 ) ;
}
static inline void F_109 ( struct V_84 * V_85 )
{
struct V_103 * V_104 = V_85 -> V_86 ;
if ( V_104 -> V_87 & V_88 )
F_110 ( V_104 -> V_67 , NULL ) ;
else
F_110 ( V_85 -> V_67 , NULL ) ;
}
static inline void
F_111 ( struct V_84 * V_85 )
{
struct V_103 * V_104 = V_85 -> V_86 ;
if ( V_104 -> V_87 & V_88 )
V_104 -> V_87 |= V_190 ;
else
V_85 -> V_87 |= V_191 ;
}
static inline void
F_112 ( struct V_84 * V_85 )
{
struct V_103 * V_104 = V_85 -> V_86 ;
if ( V_104 -> V_87 & V_88 )
V_104 -> V_87 &= ~ V_190 ;
else
V_85 -> V_87 &= ~ V_191 ;
}
static inline bool
F_113 ( struct V_84 * V_85 )
{
struct V_103 * V_104 = V_85 -> V_86 ;
if ( V_85 -> V_87 & V_191 )
return true ;
if ( ( V_104 -> V_87 & V_88 ) &&
( V_104 -> V_87 & V_190 ) )
return true ;
return false ;
}
static int F_114 ( struct V_107 * V_108 ,
struct V_109 * V_110 ,
struct V_69 * V_70 ,
char * V_74 )
{
struct V_84 * V_85 ;
struct V_192 * V_193 ;
struct V_192 * V_194 ;
F_115 ( V_192 ) ;
bool V_187 = true ;
int V_51 ;
F_55 (file, &tr->events, list) {
if ( V_85 -> system != V_108 )
continue;
V_51 = F_104 ( V_85 -> V_86 , NULL , V_70 , true ) ;
if ( V_51 )
F_111 ( V_85 ) ;
else
F_112 ( V_85 ) ;
}
F_55 (file, &tr->events, list) {
struct V_66 * V_67 ;
if ( V_85 -> system != V_108 )
continue;
if ( F_113 ( V_85 ) )
continue;
V_193 = F_51 ( sizeof( * V_193 ) , V_75 ) ;
if ( ! V_193 )
goto V_195;
F_88 ( & V_193 -> V_162 , & V_192 ) ;
V_193 -> V_67 = F_50 () ;
if ( ! V_193 -> V_67 )
goto V_195;
V_67 = V_193 -> V_67 ;
V_51 = F_26 ( V_67 , V_74 ) ;
if ( V_51 )
goto V_195;
V_51 = F_104 ( V_85 -> V_86 , V_67 , V_70 , false ) ;
if ( V_51 ) {
F_47 ( V_85 ) ;
F_23 ( V_70 , V_196 , 0 ) ;
F_31 ( V_70 , V_67 ) ;
} else
F_106 ( V_85 ) ;
V_67 = V_66 ( V_85 ) ;
F_107 ( V_85 , V_193 -> V_67 ) ;
V_193 -> V_67 = V_67 ;
V_187 = false ;
}
if ( V_187 )
goto V_187;
F_116 () ;
F_117 (filter_item, tmp, &filter_list, list) {
F_48 ( V_193 -> V_67 ) ;
F_84 ( & V_193 -> V_162 ) ;
F_25 ( V_193 ) ;
}
return 0 ;
V_187:
F_117 (filter_item, tmp, &filter_list, list) {
F_84 ( & V_193 -> V_162 ) ;
F_25 ( V_193 ) ;
}
F_23 ( V_70 , V_196 , 0 ) ;
return - V_50 ;
V_195:
if ( ! V_187 )
F_116 () ;
F_117 (filter_item, tmp, &filter_list, list) {
F_48 ( V_193 -> V_67 ) ;
F_84 ( & V_193 -> V_162 ) ;
F_25 ( V_193 ) ;
}
return - V_76 ;
}
static int F_118 ( char * V_197 , bool V_198 ,
struct V_69 * * V_199 ,
struct V_66 * * V_200 )
{
struct V_66 * V_67 ;
struct V_69 * V_70 = NULL ;
int V_51 = 0 ;
F_18 ( * V_199 || * V_200 ) ;
V_67 = F_50 () ;
if ( V_67 && V_198 )
V_51 = F_26 ( V_67 , V_197 ) ;
V_70 = F_51 ( sizeof( * V_70 ) , V_75 ) ;
if ( ! V_67 || ! V_70 || V_51 ) {
F_25 ( V_70 ) ;
F_48 ( V_67 ) ;
return - V_76 ;
}
* V_200 = V_67 ;
* V_199 = V_70 ;
F_67 ( V_70 , V_201 , V_197 ) ;
V_51 = F_91 ( V_70 ) ;
if ( V_51 && V_198 )
F_31 ( V_70 , V_67 ) ;
return V_51 ;
}
static void F_119 ( struct V_69 * V_70 )
{
if ( V_70 ) {
F_85 ( V_70 ) ;
F_90 ( V_70 ) ;
F_25 ( V_70 ) ;
}
}
static int F_120 ( struct V_103 * V_104 ,
char * V_197 , bool V_198 ,
struct V_66 * * V_200 )
{
struct V_66 * V_67 = NULL ;
struct V_69 * V_70 = NULL ;
int V_51 ;
V_51 = F_118 ( V_197 , V_198 , & V_70 , & V_67 ) ;
if ( ! V_51 ) {
V_51 = F_104 ( V_104 , V_67 , V_70 , false ) ;
if ( V_51 && V_198 )
F_31 ( V_70 , V_67 ) ;
}
F_119 ( V_70 ) ;
* V_200 = V_67 ;
return V_51 ;
}
int F_121 ( struct V_103 * V_104 ,
char * V_197 , bool V_198 ,
struct V_66 * * V_200 )
{
return F_120 ( V_104 , V_197 , V_198 , V_200 ) ;
}
static int F_122 ( struct V_107 * V_108 ,
struct V_109 * V_110 ,
char * V_197 , struct V_66 * * V_200 )
{
struct V_66 * V_67 = NULL ;
struct V_69 * V_70 = NULL ;
int V_51 ;
V_51 = F_118 ( V_197 , true , & V_70 , & V_67 ) ;
if ( ! V_51 ) {
V_51 = F_114 ( V_108 , V_110 , V_70 , V_197 ) ;
if ( ! V_51 ) {
F_25 ( V_67 -> V_74 ) ;
V_67 -> V_74 = NULL ;
} else {
F_31 ( V_70 , V_67 ) ;
}
}
F_119 ( V_70 ) ;
* V_200 = V_67 ;
return V_51 ;
}
int F_123 ( struct V_84 * V_85 , char * V_74 )
{
struct V_103 * V_104 = V_85 -> V_86 ;
struct V_66 * V_67 ;
int V_51 ;
if ( ! strcmp ( F_124 ( V_74 ) , L_11 ) ) {
F_47 ( V_85 ) ;
V_67 = V_66 ( V_85 ) ;
if ( ! V_67 )
return 0 ;
F_109 ( V_85 ) ;
F_116 () ;
F_48 ( V_67 ) ;
return 0 ;
}
V_51 = F_120 ( V_104 , V_74 , true , & V_67 ) ;
if ( V_67 ) {
struct V_66 * V_194 ;
V_194 = V_66 ( V_85 ) ;
if ( ! V_51 )
F_106 ( V_85 ) ;
else
F_47 ( V_85 ) ;
F_107 ( V_85 , V_67 ) ;
if ( V_194 ) {
F_116 () ;
F_48 ( V_194 ) ;
}
}
return V_51 ;
}
int F_125 ( struct V_107 * V_108 ,
char * V_74 )
{
struct V_91 * system = V_108 -> V_202 ;
struct V_109 * V_110 = V_108 -> V_110 ;
struct V_66 * V_67 ;
int V_51 = 0 ;
F_38 ( & V_92 ) ;
if ( ! V_108 -> V_203 ) {
V_51 = - V_204 ;
goto V_205;
}
if ( ! strcmp ( F_124 ( V_74 ) , L_11 ) ) {
F_54 ( V_108 , V_110 ) ;
F_24 ( system -> V_67 ) ;
V_67 = system -> V_67 ;
system -> V_67 = NULL ;
F_116 () ;
F_57 ( V_108 , V_110 ) ;
F_48 ( V_67 ) ;
goto V_205;
}
V_51 = F_122 ( V_108 , V_110 , V_74 , & V_67 ) ;
if ( V_67 ) {
F_48 ( system -> V_67 ) ;
system -> V_67 = V_67 ;
}
V_205:
F_39 ( & V_92 ) ;
return V_51 ;
}
void F_126 ( struct V_206 * V_3 )
{
struct V_66 * V_67 = V_3 -> V_67 ;
V_3 -> V_67 = NULL ;
F_48 ( V_67 ) ;
}
static char * *
F_127 ( char * V_79 , int V_11 , int * V_181 )
{
char * V_25 , * * V_207 ;
V_25 = F_128 ( V_79 , V_11 , V_75 ) ;
if ( ! V_25 )
return NULL ;
F_129 ( V_25 , ',' , ' ' ) ;
V_207 = F_130 ( V_75 , V_25 , V_181 ) ;
F_25 ( V_25 ) ;
return V_207 ;
}
static int F_131 ( struct V_208 * V_61 , int V_67 ,
int V_209 , char * V_207 , int V_11 )
{
int V_52 ;
if ( V_67 )
V_52 = F_132 ( V_61 , V_207 , V_11 , V_209 ) ;
else
V_52 = F_133 ( V_61 , V_207 , V_11 , V_209 ) ;
return V_52 ;
}
static int F_134 ( int V_67 , char * V_79 , int V_11 ,
struct V_210 * V_47 )
{
int V_32 , V_211 , V_52 = - V_50 ;
int * V_209 ;
char * * V_207 ;
V_209 = V_67 ? & V_47 -> V_212 : & V_47 -> V_213 ;
V_207 = F_127 ( V_79 , V_11 , & V_211 ) ;
if ( ! V_207 )
return - V_50 ;
for ( V_32 = 0 ; V_32 < V_211 ; V_32 ++ ) {
V_52 = F_131 ( V_47 -> V_61 , V_67 , * V_209 ,
V_207 [ V_32 ] , strlen ( V_207 [ V_32 ] ) ) ;
if ( V_52 )
break;
if ( * V_209 )
* V_209 = 0 ;
}
F_135 ( V_207 ) ;
return V_52 ;
}
static int F_136 ( struct V_1 * V_2 , int V_214 )
{
struct V_115 * V_116 = V_2 -> V_116 ;
if ( V_214 ) {
if ( ( V_2 -> V_17 != V_18 ) && ( V_2 -> V_17 != V_120 ) )
return - V_50 ;
if ( strcmp ( V_116 -> V_136 , L_8 ) )
return - V_50 ;
} else {
if ( V_2 -> V_17 != V_60 )
return - V_50 ;
}
return 0 ;
}
static int F_137 ( enum V_39 V_40 ,
struct V_1 * V_2 ,
int * V_51 , void * V_47 )
{
if ( ( V_40 != V_48 ) ||
( V_2 -> V_56 != V_57 ) ) {
* V_51 = F_136 ( V_2 , 0 ) ;
} else {
* V_51 = F_136 ( V_2 , 1 ) ;
if ( * V_51 )
return V_53 ;
* V_51 = F_134 ( V_2 -> V_17 == V_18 ,
V_2 -> V_8 . V_27 ,
V_2 -> V_8 . V_11 ,
V_47 ) ;
}
return ( * V_51 ) ? V_53 : V_65 ;
}
static int F_138 ( struct V_206 * V_3 ,
struct V_66 * V_67 )
{
struct V_210 V_47 = {
. V_212 = 1 ,
. V_213 = 1 ,
. V_61 = & V_3 -> V_208 ,
} ;
return F_16 ( V_67 -> V_37 , V_67 -> V_45 ,
F_137 , & V_47 ) ;
}
static int F_138 ( struct V_206 * V_3 ,
struct V_66 * V_67 )
{
return - V_204 ;
}
int F_139 ( struct V_206 * V_3 , int V_215 ,
char * V_197 )
{
int V_51 ;
struct V_66 * V_67 ;
struct V_103 * V_104 ;
F_38 ( & V_92 ) ;
V_104 = V_3 -> V_216 ;
V_51 = - V_50 ;
if ( ! V_104 )
goto V_205;
V_51 = - V_217 ;
if ( V_3 -> V_67 )
goto V_205;
V_51 = F_120 ( V_104 , V_197 , false , & V_67 ) ;
if ( V_51 )
goto V_218;
if ( F_140 ( V_104 ) )
V_51 = F_138 ( V_3 , V_67 ) ;
else
V_3 -> V_67 = V_67 ;
V_218:
if ( V_51 || F_140 ( V_104 ) )
F_48 ( V_67 ) ;
V_205:
F_39 ( & V_92 ) ;
return V_51 ;
}
static int F_141 ( struct V_1 * V_2 , void * V_3 )
{
struct V_115 * V_116 = V_2 -> V_116 ;
V_219 = 1 ;
F_142 ( V_220 L_12 , V_116 -> V_136 ) ;
return 1 ;
}
static int F_143 ( enum V_39 V_40 , struct V_1 * V_2 ,
int * V_51 , void * V_47 )
{
char * V_221 = V_47 ;
if ( ( V_40 == V_48 ) &&
( V_2 -> V_56 == V_57 ) ) {
struct V_115 * V_116 = V_2 -> V_116 ;
if ( ! V_116 ) {
F_144 ( 1 , L_13 ) ;
return V_65 ;
}
if ( ! strchr ( V_221 , * V_116 -> V_136 ) )
return V_65 ;
F_22 ( ! V_2 -> V_62 ) ;
V_2 -> V_62 = F_141 ;
}
return V_65 ;
}
static T_4 int F_145 ( void )
{
int V_32 ;
F_142 ( V_220 L_14 ) ;
for ( V_32 = 0 ; V_32 < V_222 ; V_32 ++ ) {
struct V_66 * V_67 = NULL ;
struct V_223 * V_64 = & V_224 [ V_32 ] ;
int V_51 ;
V_51 = F_120 ( & V_225 , V_64 -> V_67 ,
false , & V_67 ) ;
if ( V_51 ) {
F_142 ( V_220
L_15 ,
V_64 -> V_67 , V_51 ) ;
F_48 ( V_67 ) ;
break;
}
F_146 () ;
if ( * V_64 -> V_226 )
F_16 ( V_67 -> V_37 , V_67 -> V_45 ,
F_143 ,
V_64 -> V_226 ) ;
V_219 = 0 ;
V_51 = F_20 ( V_67 , & V_64 -> V_59 ) ;
F_147 () ;
F_48 ( V_67 ) ;
if ( V_219 ) {
F_142 ( V_220
L_16 ,
V_64 -> V_67 ) ;
break;
}
if ( V_51 != V_64 -> V_7 ) {
F_142 ( V_220
L_17 ,
V_64 -> V_67 , V_64 -> V_7 ) ;
break;
}
}
if ( V_32 == V_222 )
F_142 ( V_227 L_18 ) ;
return 0 ;
}
