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
static inline struct V_58 * V_58 ( struct V_76 * V_77 )
{
if ( V_77 -> V_78 -> V_79 & V_80 )
return V_77 -> V_78 -> V_59 ;
else
return V_77 -> V_59 ;
}
void F_31 ( struct V_76 * V_77 , struct V_81 * V_82 )
{
struct V_58 * V_59 = V_58 ( V_77 ) ;
if ( V_59 && V_59 -> V_66 )
F_32 ( V_82 , L_3 , V_59 -> V_66 ) ;
else
F_33 ( V_82 , L_4 ) ;
}
void F_34 ( struct V_83 * system ,
struct V_81 * V_82 )
{
struct V_58 * V_59 ;
F_35 ( & V_84 ) ;
V_59 = system -> V_59 ;
if ( V_59 && V_59 -> V_66 )
F_32 ( V_82 , L_3 , V_59 -> V_66 ) ;
else
F_33 ( V_82 , V_85 L_1 ) ;
F_36 ( & V_84 ) ;
}
static int F_37 ( struct V_86 * V_87 , int V_60 )
{
V_87 -> V_28 = F_38 ( V_60 + 1 , sizeof( * V_87 -> V_28 ) , V_67 ) ;
if ( ! V_87 -> V_28 )
return - V_68 ;
V_87 -> V_29 = V_60 ;
return 0 ;
}
static void F_39 ( struct V_86 * V_87 )
{
F_22 ( V_87 -> V_28 ) ;
V_87 -> V_29 = 0 ;
}
static int F_40 ( struct V_86 * V_87 ,
struct V_1 * V_2 )
{
int V_29 = V_87 -> V_29 ;
if ( F_19 ( V_29 == 0 ) )
return - V_88 ;
V_87 -> V_28 [ -- V_29 ] = V_2 ;
V_87 -> V_29 = V_29 ;
return 0 ;
}
static struct V_1 *
F_41 ( struct V_86 * V_87 )
{
struct V_1 * V_2 ;
int V_29 = V_87 -> V_29 ;
V_2 = V_87 -> V_28 [ V_29 ++ ] ;
if ( ! V_2 )
return NULL ;
V_87 -> V_29 = V_29 ;
return V_2 ;
}
static int F_42 ( struct V_58 * V_59 ,
int V_89 ,
struct V_86 * V_87 ,
struct V_1 * V_90 )
{
struct V_1 * V_91 = & V_59 -> V_28 [ V_89 ] ;
struct V_1 * V_47 ;
struct V_1 * V_49 ;
* V_91 = * V_90 ;
V_91 -> V_29 = V_89 ;
if ( V_91 -> V_26 == V_51 || V_91 -> V_26 == V_92 ) {
V_49 = F_41 ( V_87 ) ;
V_47 = F_41 ( V_87 ) ;
if ( ! V_47 || ! V_49 )
return - V_41 ;
if ( V_47 -> V_29 & V_93 &&
( V_47 -> V_26 == V_91 -> V_26 ||
V_47 -> V_47 == V_48 ) &&
V_49 -> V_29 & V_93 &&
( V_49 -> V_26 == V_91 -> V_26 ||
V_49 -> V_47 == V_48 ) )
V_91 -> V_29 |= V_93 ;
V_91 -> V_47 = V_47 -> V_29 & ~ V_93 ;
V_91 -> V_49 = V_49 -> V_29 & ~ V_93 ;
V_47 -> V_32 = V_91 -> V_29 & ~ V_93 ;
V_49 -> V_32 = V_91 -> V_29 | V_33 ;
} else {
V_91 -> V_47 = V_48 ;
V_91 -> V_29 |= V_93 ;
}
return F_40 ( V_87 , V_91 ) ;
}
static void F_43 ( struct V_58 * V_59 )
{
int V_22 ;
if ( V_59 -> V_28 ) {
for ( V_22 = 0 ; V_22 < V_59 -> V_60 ; V_22 ++ )
F_22 ( V_59 -> V_28 [ V_22 ] . V_53 ) ;
F_22 ( V_59 -> V_28 ) ;
V_59 -> V_28 = NULL ;
}
V_59 -> V_94 = 0 ;
V_59 -> V_60 = 0 ;
}
static void F_44 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 )
V_96 -> V_79 &= ~ V_97 ;
else
V_77 -> V_79 &= ~ V_98 ;
}
static void F_45 ( struct V_58 * V_59 )
{
if ( ! V_59 )
return;
F_43 ( V_59 ) ;
F_22 ( V_59 -> V_66 ) ;
F_22 ( V_59 ) ;
}
void F_46 ( struct V_58 * V_59 )
{
F_45 ( V_59 ) ;
}
static struct V_58 * F_47 ( void )
{
struct V_58 * V_59 ;
V_59 = F_48 ( sizeof( * V_59 ) , V_67 ) ;
return V_59 ;
}
static int F_49 ( struct V_58 * V_59 , int V_60 )
{
struct V_1 * V_2 ;
int V_22 ;
if ( V_59 -> V_28 )
F_43 ( V_59 ) ;
V_59 -> V_28 = F_38 ( V_60 , sizeof( * V_59 -> V_28 ) , V_67 ) ;
if ( ! V_59 -> V_28 )
return - V_68 ;
V_59 -> V_94 = V_60 ;
V_59 -> V_60 = 0 ;
for ( V_22 = 0 ; V_22 < V_60 ; V_22 ++ ) {
V_2 = & V_59 -> V_28 [ V_22 ] ;
V_2 -> V_54 = F_4 ;
}
return 0 ;
}
static inline void F_50 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
F_44 ( V_77 ) ;
if ( V_96 -> V_79 & V_80 )
F_21 ( V_96 -> V_59 ) ;
else
F_21 ( V_77 -> V_59 ) ;
}
static void F_51 ( struct V_99 * V_100 ,
struct V_101 * V_102 )
{
struct V_76 * V_77 ;
F_52 (file, &tr->events, list) {
if ( V_77 -> system != V_100 )
continue;
F_50 ( V_77 ) ;
}
}
static inline void F_53 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 ) {
F_45 ( V_96 -> V_59 ) ;
V_96 -> V_59 = NULL ;
} else {
F_45 ( V_77 -> V_59 ) ;
V_77 -> V_59 = NULL ;
}
}
static void F_54 ( struct V_99 * V_100 ,
struct V_101 * V_102 )
{
struct V_76 * V_77 ;
F_52 (file, &tr->events, list) {
if ( V_77 -> system != V_100 )
continue;
F_53 ( V_77 ) ;
}
}
static int F_55 ( struct V_61 * V_62 ,
struct V_58 * V_59 ,
struct V_1 * V_2 ,
struct V_86 * V_87 )
{
int V_42 ;
if ( F_19 ( V_59 -> V_60 == V_59 -> V_94 ) ) {
F_20 ( V_62 , V_103 , 0 ) ;
return - V_88 ;
}
V_42 = F_42 ( V_59 , V_59 -> V_60 , V_87 , V_2 ) ;
if ( V_42 )
return V_42 ;
V_59 -> V_60 ++ ;
return 0 ;
}
int F_56 ( const char * type )
{
if ( strstr ( type , L_5 ) && strstr ( type , L_6 ) )
return V_104 ;
if ( strchr ( type , '[' ) && strstr ( type , L_6 ) )
return V_105 ;
return V_106 ;
}
static bool F_57 ( struct V_107 * V_108 )
{
return V_108 -> V_109 == V_110 ;
}
static bool F_58 ( struct V_107 * V_108 )
{
return V_108 -> V_109 == V_104 ||
V_108 -> V_109 == V_105 ||
V_108 -> V_109 == V_111 ;
}
static int F_59 ( struct V_107 * V_108 , int V_26 )
{
if ( F_58 ( V_108 ) &&
( V_26 != V_112 && V_26 != V_113 && V_26 != V_27 ) )
return 0 ;
if ( ! F_58 ( V_108 ) && V_26 == V_27 )
return 0 ;
return 1 ;
}
static T_3 F_60 ( int V_26 , int V_114 ,
int V_115 )
{
T_3 V_54 = NULL ;
switch ( V_114 ) {
case 8 :
if ( V_26 == V_112 || V_26 == V_113 )
V_54 = V_116 ;
else if ( V_115 )
V_54 = V_117 ;
else
V_54 = V_118 ;
break;
case 4 :
if ( V_26 == V_112 || V_26 == V_113 )
V_54 = V_119 ;
else if ( V_115 )
V_54 = V_120 ;
else
V_54 = V_121 ;
break;
case 2 :
if ( V_26 == V_112 || V_26 == V_113 )
V_54 = V_122 ;
else if ( V_115 )
V_54 = V_123 ;
else
V_54 = V_124 ;
break;
case 1 :
if ( V_26 == V_112 || V_26 == V_113 )
V_54 = V_125 ;
else if ( V_115 )
V_54 = V_126 ;
else
V_54 = V_127 ;
break;
}
return V_54 ;
}
static int F_61 ( struct V_61 * V_62 ,
struct V_107 * V_108 ,
struct V_1 * V_2 )
{
T_3 V_54 = F_4 ;
unsigned long long V_52 ;
int V_43 ;
V_2 -> V_5 = V_108 -> V_5 ;
if ( ! F_59 ( V_108 , V_2 -> V_26 ) ) {
F_20 ( V_62 , V_128 , 0 ) ;
return - V_41 ;
}
if ( F_58 ( V_108 ) ) {
F_11 ( V_2 ) ;
if ( V_108 -> V_109 == V_105 ) {
V_54 = F_1 ;
V_2 -> V_8 . V_9 = V_108 -> V_129 ;
} else if ( V_108 -> V_109 == V_104 )
V_54 = F_3 ;
else
V_54 = F_2 ;
} else if ( F_57 ( V_108 ) ) {
if ( strcmp ( V_108 -> V_130 , L_7 ) ) {
F_20 ( V_62 , V_131 , 0 ) ;
return - V_41 ;
}
} else {
if ( V_108 -> V_132 )
V_43 = F_62 ( V_2 -> V_8 . V_17 , 0 , & V_52 ) ;
else
V_43 = F_63 ( V_2 -> V_8 . V_17 , 0 , & V_52 ) ;
if ( V_43 ) {
F_20 ( V_62 , V_133 , 0 ) ;
return - V_41 ;
}
V_2 -> V_52 = V_52 ;
V_54 = F_60 ( V_2 -> V_26 , V_108 -> V_129 ,
V_108 -> V_132 ) ;
if ( ! V_54 ) {
F_20 ( V_62 , V_134 , 0 ) ;
return - V_41 ;
}
}
if ( V_2 -> V_26 == V_113 )
V_2 -> V_10 = 1 ;
V_2 -> V_54 = V_54 ;
return 0 ;
}
static void F_64 ( struct V_61 * V_62 ,
struct V_135 * V_53 ,
char * V_136 )
{
memset ( V_62 , '\0' , sizeof( * V_62 ) ) ;
V_62 -> V_137 . string = V_136 ;
V_62 -> V_137 . V_138 = strlen ( V_136 ) ;
V_62 -> V_53 = V_53 ;
F_65 ( & V_62 -> V_139 ) ;
F_65 ( & V_62 -> V_140 ) ;
}
static char F_66 ( struct V_61 * V_62 )
{
V_62 -> V_137 . V_138 -- ;
return V_62 -> V_137 . string [ V_62 -> V_137 . V_141 ++ ] ;
}
static char F_67 ( struct V_61 * V_62 )
{
if ( V_62 -> V_137 . V_141 == strlen ( V_62 -> V_137 . string ) )
return 0 ;
return V_62 -> V_137 . string [ V_62 -> V_137 . V_141 ] ;
}
static void F_68 ( struct V_61 * V_62 )
{
V_62 -> V_137 . V_138 -- ;
V_62 -> V_137 . V_141 ++ ;
}
static inline int F_69 ( struct V_61 * V_62 ,
int V_142 , int V_143 )
{
return V_62 -> V_53 [ V_142 ] . V_144 < V_62 -> V_53 [ V_143 ] . V_144 ;
}
static inline int F_70 ( struct V_61 * V_62 , char V_145 )
{
int V_22 ;
for ( V_22 = 0 ; strcmp ( V_62 -> V_53 [ V_22 ] . string , L_8 ) ; V_22 ++ ) {
if ( V_62 -> V_53 [ V_22 ] . string [ 0 ] == V_145 )
return 1 ;
}
return 0 ;
}
static int F_71 ( struct V_61 * V_62 , char V_146 )
{
char V_147 = F_67 ( V_62 ) ;
char V_148 [ 3 ] ;
int V_22 ;
V_148 [ 0 ] = V_146 ;
V_148 [ 1 ] = V_147 ;
V_148 [ 2 ] = '\0' ;
for ( V_22 = 0 ; strcmp ( V_62 -> V_53 [ V_22 ] . string , L_8 ) ; V_22 ++ ) {
if ( ! strcmp ( V_148 , V_62 -> V_53 [ V_22 ] . string ) ) {
F_68 ( V_62 ) ;
return V_62 -> V_53 [ V_22 ] . V_149 ;
}
}
V_148 [ 1 ] = '\0' ;
for ( V_22 = 0 ; strcmp ( V_62 -> V_53 [ V_22 ] . string , L_8 ) ; V_22 ++ ) {
if ( ! strcmp ( V_148 , V_62 -> V_53 [ V_22 ] . string ) )
return V_62 -> V_53 [ V_22 ] . V_149 ;
}
return V_150 ;
}
static inline void F_72 ( struct V_61 * V_62 )
{
memset ( V_62 -> V_151 . string , '\0' , V_152 ) ;
V_62 -> V_151 . V_141 = 0 ;
}
static inline int F_73 ( struct V_61 * V_62 , char V_145 )
{
if ( V_62 -> V_151 . V_141 == V_152 - 1 )
return - V_41 ;
V_62 -> V_151 . string [ V_62 -> V_151 . V_141 ++ ] = V_145 ;
return 0 ;
}
static int F_74 ( struct V_61 * V_62 , int V_26 )
{
struct V_153 * V_153 ;
V_153 = F_27 ( sizeof( * V_153 ) , V_67 ) ;
if ( ! V_153 )
return - V_68 ;
V_153 -> V_26 = V_26 ;
F_75 ( & V_153 -> V_154 , & V_62 -> V_139 ) ;
return 0 ;
}
static int F_76 ( struct V_61 * V_62 )
{
return F_77 ( & V_62 -> V_139 ) ;
}
static int F_78 ( struct V_61 * V_62 )
{
struct V_153 * V_153 ;
if ( F_76 ( V_62 ) )
return V_150 ;
V_153 = F_79 ( & V_62 -> V_139 , struct V_153 , V_154 ) ;
return V_153 -> V_26 ;
}
static int F_80 ( struct V_61 * V_62 )
{
struct V_153 * V_153 ;
int V_26 ;
if ( F_76 ( V_62 ) )
return V_150 ;
V_153 = F_79 ( & V_62 -> V_139 , struct V_153 , V_154 ) ;
V_26 = V_153 -> V_26 ;
F_81 ( & V_153 -> V_154 ) ;
F_22 ( V_153 ) ;
return V_26 ;
}
static void F_82 ( struct V_61 * V_62 )
{
while ( ! F_76 ( V_62 ) )
F_80 ( V_62 ) ;
}
static char * F_83 ( struct V_61 * V_62 )
{
return V_62 -> V_151 . string ;
}
static int F_84 ( struct V_61 * V_62 , char * V_151 )
{
struct V_155 * V_156 ;
V_156 = F_27 ( sizeof( * V_156 ) , V_67 ) ;
if ( ! V_156 )
return - V_68 ;
V_156 -> V_26 = V_150 ;
V_156 -> V_151 = F_24 ( V_151 , V_67 ) ;
if ( ! V_156 -> V_151 ) {
F_22 ( V_156 ) ;
return - V_68 ;
}
F_85 ( & V_156 -> V_154 , & V_62 -> V_140 ) ;
return 0 ;
}
static int F_86 ( struct V_61 * V_62 , int V_26 )
{
struct V_155 * V_156 ;
V_156 = F_27 ( sizeof( * V_156 ) , V_67 ) ;
if ( ! V_156 )
return - V_68 ;
V_156 -> V_26 = V_26 ;
V_156 -> V_151 = NULL ;
F_85 ( & V_156 -> V_154 , & V_62 -> V_140 ) ;
return 0 ;
}
static void F_87 ( struct V_61 * V_62 )
{
struct V_155 * V_156 ;
while ( ! F_77 ( & V_62 -> V_140 ) ) {
V_156 = F_79 ( & V_62 -> V_140 , struct V_155 , V_154 ) ;
F_81 ( & V_156 -> V_154 ) ;
F_22 ( V_156 -> V_151 ) ;
F_22 ( V_156 ) ;
}
}
static int F_88 ( struct V_61 * V_62 )
{
int V_157 = 0 ;
int V_26 , V_158 ;
char V_159 ;
while ( ( V_159 = F_66 ( V_62 ) ) ) {
if ( V_159 == '"' ) {
V_157 ^= 1 ;
continue;
}
if ( V_157 )
goto V_160;
if ( isspace ( V_159 ) )
continue;
if ( F_70 ( V_62 , V_159 ) ) {
V_26 = F_71 ( V_62 , V_159 ) ;
if ( V_26 == V_150 ) {
F_20 ( V_62 , V_134 , 0 ) ;
return - V_41 ;
}
if ( strlen ( F_83 ( V_62 ) ) ) {
F_84 ( V_62 , F_83 ( V_62 ) ) ;
F_72 ( V_62 ) ;
}
while ( ! F_76 ( V_62 ) ) {
V_158 = F_78 ( V_62 ) ;
if ( ! F_69 ( V_62 , V_158 , V_26 ) ) {
V_158 = F_80 ( V_62 ) ;
F_86 ( V_62 , V_158 ) ;
continue;
}
break;
}
F_74 ( V_62 , V_26 ) ;
continue;
}
if ( V_159 == '(' ) {
F_74 ( V_62 , V_161 ) ;
continue;
}
if ( V_159 == ')' ) {
if ( strlen ( F_83 ( V_62 ) ) ) {
F_84 ( V_62 , F_83 ( V_62 ) ) ;
F_72 ( V_62 ) ;
}
V_158 = F_80 ( V_62 ) ;
while ( V_158 != V_150 ) {
if ( V_158 == V_161 )
break;
F_86 ( V_62 , V_158 ) ;
V_158 = F_80 ( V_62 ) ;
}
if ( V_158 == V_150 ) {
F_20 ( V_62 , V_162 , 0 ) ;
return - V_41 ;
}
continue;
}
V_160:
if ( F_73 ( V_62 , V_159 ) ) {
F_20 ( V_62 , V_163 , 0 ) ;
return - V_41 ;
}
}
if ( strlen ( F_83 ( V_62 ) ) )
F_84 ( V_62 , F_83 ( V_62 ) ) ;
while ( ! F_76 ( V_62 ) ) {
V_158 = F_80 ( V_62 ) ;
if ( V_158 == V_150 )
break;
if ( V_158 == V_161 ) {
F_20 ( V_62 , V_162 , 0 ) ;
return - V_41 ;
}
F_86 ( V_62 , V_158 ) ;
}
return 0 ;
}
static struct V_1 * F_89 ( struct V_61 * V_62 ,
struct V_95 * V_96 ,
int V_26 , char * V_164 , char * V_165 )
{
struct V_107 * V_108 ;
static struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_26 = V_26 ;
if ( V_26 == V_92 || V_26 == V_51 )
return & V_2 ;
if ( ! V_164 || ! V_165 ) {
F_20 ( V_62 , V_166 , 0 ) ;
return NULL ;
}
V_108 = F_90 ( V_96 , V_164 ) ;
if ( ! V_108 ) {
F_20 ( V_62 , V_167 , 0 ) ;
return NULL ;
}
strcpy ( V_2 . V_8 . V_17 , V_165 ) ;
V_2 . V_8 . V_11 = strlen ( V_2 . V_8 . V_17 ) ;
V_2 . V_108 = V_108 ;
return F_61 ( V_62 , V_108 , & V_2 ) ? NULL : & V_2 ;
}
static int F_91 ( struct V_61 * V_62 )
{
int V_168 = 0 , V_169 = 0 ;
struct V_155 * V_156 ;
F_52 (elt, &ps->postfix, list) {
if ( V_156 -> V_26 == V_150 )
continue;
if ( V_156 -> V_26 == V_92 || V_156 -> V_26 == V_51 ) {
V_169 ++ ;
continue;
}
V_168 ++ ;
}
if ( ! V_168 || V_169 >= V_168 ) {
F_20 ( V_62 , V_170 , 0 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_92 ( struct V_61 * V_62 )
{
struct V_155 * V_156 ;
int V_60 = 0 ;
F_52 (elt, &ps->postfix, list) {
if ( V_156 -> V_26 == V_150 )
continue;
V_60 ++ ;
}
return V_60 ;
}
static int F_93 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
struct V_171 * V_56 = V_38 ;
if ( F_19 ( V_56 -> V_172 ++ > V_56 -> V_173 ) ) {
* V_42 = - V_41 ;
return V_44 ;
}
return V_57 ;
}
static int F_94 ( struct V_58 * V_59 ,
struct V_1 * V_36 )
{
struct V_171 V_38 = {
. V_173 = 3 * V_59 -> V_60 ,
. V_172 = 0 ,
} ;
return F_13 ( V_59 -> V_28 , V_36 ,
F_93 , & V_38 ) ;
}
static int F_95 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
int * V_172 = V_38 ;
if ( ( V_31 == V_39 ) &&
( V_2 -> V_47 == V_48 ) )
( * V_172 ) ++ ;
return V_57 ;
}
static int F_96 ( struct V_1 * V_28 , struct V_1 * V_36 )
{
int V_172 = 0 , V_43 ;
V_43 = F_13 ( V_28 , V_36 , F_95 , & V_172 ) ;
F_19 ( V_43 ) ;
return V_172 ;
}
static int F_97 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
struct V_174 * V_56 = V_38 ;
struct V_1 * V_36 = V_56 -> V_36 ;
if ( V_31 != V_39 )
return V_57 ;
if ( V_2 -> V_47 != V_48 )
return V_57 ;
if ( F_19 ( V_56 -> V_172 == V_56 -> V_175 ) ) {
* V_42 = - V_41 ;
return V_44 ;
}
V_2 -> V_29 &= ~ V_93 ;
V_36 -> V_53 [ V_56 -> V_172 ++ ] = V_2 -> V_29 ;
return V_57 ;
}
static int F_98 ( struct V_1 * V_28 , struct V_1 * V_36 )
{
struct V_174 V_38 = {
. V_36 = V_36 ,
. V_172 = 0 ,
} ;
int V_175 ;
V_36 -> V_29 &= ~ V_93 ;
if ( V_36 -> V_47 == V_48 )
return 0 ;
V_175 = F_96 ( V_28 , & V_28 [ V_36 -> V_47 ] ) ;
V_175 += F_96 ( V_28 , & V_28 [ V_36 -> V_49 ] ) ;
V_36 -> V_53 = F_38 ( V_175 , sizeof( * V_36 -> V_53 ) , V_67 ) ;
if ( ! V_36 -> V_53 )
return - V_68 ;
V_36 -> V_52 = V_175 ;
V_38 . V_175 = V_175 ;
return F_13 ( V_28 , V_36 , F_97 , & V_38 ) ;
}
static int F_99 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
struct V_1 * V_28 = V_38 ;
if ( V_31 != V_39 )
return V_57 ;
if ( ! ( V_2 -> V_29 & V_93 ) )
return V_57 ;
* V_42 = F_98 ( V_28 , V_2 ) ;
if ( * V_42 )
return V_44 ;
return V_45 ;
}
static int F_100 ( struct V_58 * V_59 ,
struct V_1 * V_36 )
{
return F_13 ( V_59 -> V_28 , V_36 , F_99 ,
V_59 -> V_28 ) ;
}
static int F_101 ( struct V_95 * V_96 ,
struct V_58 * V_59 ,
struct V_61 * V_62 ,
bool V_176 )
{
char * V_164 = NULL , * V_165 = NULL ;
struct V_1 * V_2 ;
struct V_1 * V_36 ;
struct V_155 * V_156 ;
struct V_86 V_87 = { } ;
int V_42 ;
int V_60 = 0 ;
V_60 = F_92 ( V_62 ) ;
if ( V_60 >= V_177 ) {
F_20 ( V_62 , V_103 , 0 ) ;
return - V_88 ;
}
V_42 = F_91 ( V_62 ) ;
if ( V_42 )
return V_42 ;
if ( ! V_176 ) {
V_42 = F_37 ( & V_87 , V_60 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_49 ( V_59 , V_60 ) ;
if ( V_42 )
goto V_178;
}
V_60 = 0 ;
F_52 (elt, &ps->postfix, list) {
if ( V_156 -> V_26 == V_150 ) {
if ( ! V_164 )
V_164 = V_156 -> V_151 ;
else if ( ! V_165 )
V_165 = V_156 -> V_151 ;
else {
F_20 ( V_62 , V_179 , 0 ) ;
V_42 = - V_41 ;
goto V_178;
}
continue;
}
if ( F_19 ( V_60 ++ == V_177 ) ) {
F_20 ( V_62 , V_103 , 0 ) ;
V_42 = - V_88 ;
goto V_178;
}
V_2 = F_89 ( V_62 , V_96 , V_156 -> V_26 , V_164 , V_165 ) ;
if ( ! V_2 ) {
V_42 = - V_41 ;
goto V_178;
}
if ( ! V_176 ) {
V_42 = F_55 ( V_62 , V_59 , V_2 , & V_87 ) ;
if ( V_42 )
goto V_178;
}
V_164 = V_165 = NULL ;
}
if ( ! V_176 ) {
V_2 = F_41 ( & V_87 ) ;
if ( ! V_2 )
return - V_41 ;
V_36 = V_2 ;
V_2 = F_41 ( & V_87 ) ;
if ( F_19 ( V_2 ) ) {
V_42 = - V_41 ;
V_59 -> V_36 = NULL ;
goto V_178;
}
V_42 = F_94 ( V_59 , V_36 ) ;
if ( V_42 )
goto V_178;
V_42 = F_100 ( V_59 , V_36 ) ;
if ( V_42 )
goto V_178;
F_102 () ;
V_59 -> V_36 = V_36 ;
}
V_42 = 0 ;
V_178:
F_39 ( & V_87 ) ;
return V_42 ;
}
static inline void F_103 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 )
V_96 -> V_79 |= V_97 ;
else
V_77 -> V_79 |= V_98 ;
}
static inline void F_104 ( struct V_76 * V_77 ,
struct V_58 * V_59 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 )
F_105 ( V_96 -> V_59 , V_59 ) ;
else
F_105 ( V_77 -> V_59 , V_59 ) ;
}
static inline void F_106 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 )
F_107 ( V_96 -> V_59 , NULL ) ;
else
F_107 ( V_77 -> V_59 , NULL ) ;
}
static inline void
F_108 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 )
V_96 -> V_79 |= V_180 ;
else
V_77 -> V_79 |= V_181 ;
}
static inline void
F_109 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 )
V_96 -> V_79 &= ~ V_180 ;
else
V_77 -> V_79 &= ~ V_181 ;
}
static inline bool
F_110 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_77 -> V_79 & V_181 )
return true ;
if ( ( V_96 -> V_79 & V_80 ) &&
( V_96 -> V_79 & V_180 ) )
return true ;
return false ;
}
static int F_111 ( struct V_99 * V_100 ,
struct V_101 * V_102 ,
struct V_61 * V_62 ,
char * V_66 )
{
struct V_76 * V_77 ;
struct V_182 * V_183 ;
struct V_182 * V_184 ;
F_112 ( V_182 ) ;
bool V_178 = true ;
int V_42 ;
F_52 (file, &tr->events, list) {
if ( V_77 -> system != V_100 )
continue;
V_42 = F_101 ( V_77 -> V_78 , NULL , V_62 , true ) ;
if ( V_42 )
F_108 ( V_77 ) ;
else
F_109 ( V_77 ) ;
}
F_52 (file, &tr->events, list) {
struct V_58 * V_59 ;
if ( V_77 -> system != V_100 )
continue;
if ( F_110 ( V_77 ) )
continue;
V_183 = F_48 ( sizeof( * V_183 ) , V_67 ) ;
if ( ! V_183 )
goto V_185;
F_85 ( & V_183 -> V_154 , & V_182 ) ;
V_183 -> V_59 = F_47 () ;
if ( ! V_183 -> V_59 )
goto V_185;
V_59 = V_183 -> V_59 ;
V_42 = F_23 ( V_59 , V_66 ) ;
if ( V_42 )
goto V_185;
V_42 = F_101 ( V_77 -> V_78 , V_59 , V_62 , false ) ;
if ( V_42 ) {
F_44 ( V_77 ) ;
F_20 ( V_62 , V_186 , 0 ) ;
F_28 ( V_62 , V_59 ) ;
} else
F_103 ( V_77 ) ;
V_59 = V_58 ( V_77 ) ;
F_104 ( V_77 , V_183 -> V_59 ) ;
V_183 -> V_59 = V_59 ;
V_178 = false ;
}
if ( V_178 )
goto V_178;
F_113 () ;
F_114 (filter_item, tmp, &filter_list, list) {
F_45 ( V_183 -> V_59 ) ;
F_81 ( & V_183 -> V_154 ) ;
F_22 ( V_183 ) ;
}
return 0 ;
V_178:
F_114 (filter_item, tmp, &filter_list, list) {
F_81 ( & V_183 -> V_154 ) ;
F_22 ( V_183 ) ;
}
F_20 ( V_62 , V_186 , 0 ) ;
return - V_41 ;
V_185:
if ( ! V_178 )
F_113 () ;
F_114 (filter_item, tmp, &filter_list, list) {
F_45 ( V_183 -> V_59 ) ;
F_81 ( & V_183 -> V_154 ) ;
F_22 ( V_183 ) ;
}
return - V_68 ;
}
static int F_115 ( char * V_187 , bool V_188 ,
struct V_61 * * V_189 ,
struct V_58 * * V_190 )
{
struct V_58 * V_59 ;
struct V_61 * V_62 = NULL ;
int V_42 = 0 ;
F_15 ( * V_189 || * V_190 ) ;
V_59 = F_47 () ;
if ( V_59 && V_188 )
V_42 = F_23 ( V_59 , V_187 ) ;
V_62 = F_48 ( sizeof( * V_62 ) , V_67 ) ;
if ( ! V_59 || ! V_62 || V_42 ) {
F_22 ( V_62 ) ;
F_45 ( V_59 ) ;
return - V_68 ;
}
* V_190 = V_59 ;
* V_189 = V_62 ;
F_64 ( V_62 , V_191 , V_187 ) ;
V_42 = F_88 ( V_62 ) ;
if ( V_42 && V_188 )
F_28 ( V_62 , V_59 ) ;
return V_42 ;
}
static void F_116 ( struct V_61 * V_62 )
{
if ( V_62 ) {
F_82 ( V_62 ) ;
F_87 ( V_62 ) ;
F_22 ( V_62 ) ;
}
}
static int F_117 ( struct V_95 * V_96 ,
char * V_187 , bool V_188 ,
struct V_58 * * V_190 )
{
struct V_58 * V_59 = NULL ;
struct V_61 * V_62 = NULL ;
int V_42 ;
V_42 = F_115 ( V_187 , V_188 , & V_62 , & V_59 ) ;
if ( ! V_42 ) {
V_42 = F_101 ( V_96 , V_59 , V_62 , false ) ;
if ( V_42 && V_188 )
F_28 ( V_62 , V_59 ) ;
}
F_116 ( V_62 ) ;
* V_190 = V_59 ;
return V_42 ;
}
int F_118 ( struct V_95 * V_96 ,
char * V_187 , bool V_188 ,
struct V_58 * * V_190 )
{
return F_117 ( V_96 , V_187 , V_188 , V_190 ) ;
}
static int F_119 ( struct V_99 * V_100 ,
struct V_101 * V_102 ,
char * V_187 , struct V_58 * * V_190 )
{
struct V_58 * V_59 = NULL ;
struct V_61 * V_62 = NULL ;
int V_42 ;
V_42 = F_115 ( V_187 , true , & V_62 , & V_59 ) ;
if ( ! V_42 ) {
V_42 = F_111 ( V_100 , V_102 , V_62 , V_187 ) ;
if ( ! V_42 ) {
F_22 ( V_59 -> V_66 ) ;
V_59 -> V_66 = NULL ;
} else {
F_28 ( V_62 , V_59 ) ;
}
}
F_116 ( V_62 ) ;
* V_190 = V_59 ;
return V_42 ;
}
int F_120 ( struct V_76 * V_77 , char * V_66 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
struct V_58 * V_59 ;
int V_42 ;
if ( ! strcmp ( F_121 ( V_66 ) , L_9 ) ) {
F_44 ( V_77 ) ;
V_59 = V_58 ( V_77 ) ;
if ( ! V_59 )
return 0 ;
F_106 ( V_77 ) ;
F_113 () ;
F_45 ( V_59 ) ;
return 0 ;
}
V_42 = F_117 ( V_96 , V_66 , true , & V_59 ) ;
if ( V_59 ) {
struct V_58 * V_184 ;
V_184 = V_58 ( V_77 ) ;
if ( ! V_42 )
F_103 ( V_77 ) ;
else
F_44 ( V_77 ) ;
F_104 ( V_77 , V_59 ) ;
if ( V_184 ) {
F_113 () ;
F_45 ( V_184 ) ;
}
}
return V_42 ;
}
int F_122 ( struct V_99 * V_100 ,
char * V_66 )
{
struct V_83 * system = V_100 -> V_192 ;
struct V_101 * V_102 = V_100 -> V_102 ;
struct V_58 * V_59 ;
int V_42 = 0 ;
F_35 ( & V_84 ) ;
if ( ! V_100 -> V_193 ) {
V_42 = - V_194 ;
goto V_195;
}
if ( ! strcmp ( F_121 ( V_66 ) , L_9 ) ) {
F_51 ( V_100 , V_102 ) ;
F_21 ( system -> V_59 ) ;
V_59 = system -> V_59 ;
system -> V_59 = NULL ;
F_113 () ;
F_54 ( V_100 , V_102 ) ;
F_45 ( V_59 ) ;
goto V_195;
}
V_42 = F_119 ( V_100 , V_102 , V_66 , & V_59 ) ;
if ( V_59 ) {
F_45 ( system -> V_59 ) ;
system -> V_59 = V_59 ;
}
V_195:
F_36 ( & V_84 ) ;
return V_42 ;
}
void F_123 ( struct V_196 * V_3 )
{
struct V_58 * V_59 = V_3 -> V_59 ;
V_3 -> V_59 = NULL ;
F_45 ( V_59 ) ;
}
static char * *
F_124 ( char * V_71 , int V_11 , int * V_172 )
{
char * V_15 , * V_197 , * * V_198 ;
V_15 = F_125 ( V_71 , V_11 , V_67 ) ;
if ( ! V_15 )
return NULL ;
while ( ( V_197 = strchr ( V_15 , ',' ) ) )
* V_197 = ' ' ;
V_198 = F_126 ( V_67 , V_15 , V_172 ) ;
F_22 ( V_15 ) ;
return V_198 ;
}
static int F_127 ( struct V_199 * V_53 , int V_59 ,
int V_200 , char * V_198 , int V_11 )
{
int V_43 ;
if ( V_59 )
V_43 = F_128 ( V_53 , V_198 , V_11 , V_200 ) ;
else
V_43 = F_129 ( V_53 , V_198 , V_11 , V_200 ) ;
return V_43 ;
}
static int F_130 ( int V_59 , char * V_71 , int V_11 ,
struct V_201 * V_38 )
{
int V_22 , V_202 , V_43 = - V_41 ;
int * V_200 ;
char * * V_198 ;
V_200 = V_59 ? & V_38 -> V_203 : & V_38 -> V_204 ;
V_198 = F_124 ( V_71 , V_11 , & V_202 ) ;
if ( ! V_198 )
return - V_41 ;
for ( V_22 = 0 ; V_22 < V_202 ; V_22 ++ ) {
V_43 = F_127 ( V_38 -> V_53 , V_59 , * V_200 ,
V_198 [ V_22 ] , strlen ( V_198 [ V_22 ] ) ) ;
if ( V_43 )
break;
if ( * V_200 )
* V_200 = 0 ;
}
F_131 ( V_198 ) ;
return V_43 ;
}
static int F_132 ( struct V_1 * V_2 , int V_205 )
{
struct V_107 * V_108 = V_2 -> V_108 ;
if ( V_205 ) {
if ( ( V_2 -> V_26 != V_112 ) && ( V_2 -> V_26 != V_113 ) )
return - V_41 ;
if ( strcmp ( V_108 -> V_130 , L_7 ) )
return - V_41 ;
} else {
if ( V_2 -> V_26 != V_51 )
return - V_41 ;
}
return 0 ;
}
static int F_133 ( enum V_30 V_31 ,
struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
if ( ( V_31 != V_39 ) ||
( V_2 -> V_47 != V_48 ) ) {
* V_42 = F_132 ( V_2 , 0 ) ;
} else {
* V_42 = F_132 ( V_2 , 1 ) ;
if ( * V_42 )
return V_44 ;
* V_42 = F_130 ( V_2 -> V_26 == V_112 ,
V_2 -> V_8 . V_17 ,
V_2 -> V_8 . V_11 ,
V_38 ) ;
}
return ( * V_42 ) ? V_44 : V_57 ;
}
static int F_134 ( struct V_196 * V_3 ,
struct V_58 * V_59 )
{
struct V_201 V_38 = {
. V_203 = 1 ,
. V_204 = 1 ,
. V_53 = & V_3 -> V_199 ,
} ;
return F_13 ( V_59 -> V_28 , V_59 -> V_36 ,
F_133 , & V_38 ) ;
}
static int F_134 ( struct V_196 * V_3 ,
struct V_58 * V_59 )
{
return - V_194 ;
}
int F_135 ( struct V_196 * V_3 , int V_206 ,
char * V_187 )
{
int V_42 ;
struct V_58 * V_59 ;
struct V_95 * V_96 ;
F_35 ( & V_84 ) ;
V_96 = V_3 -> V_207 ;
V_42 = - V_41 ;
if ( ! V_96 )
goto V_195;
V_42 = - V_208 ;
if ( V_3 -> V_59 )
goto V_195;
V_42 = F_117 ( V_96 , V_187 , false , & V_59 ) ;
if ( V_42 )
goto V_209;
if ( F_136 ( V_96 ) )
V_42 = F_134 ( V_3 , V_59 ) ;
else
V_3 -> V_59 = V_59 ;
V_209:
if ( V_42 || F_136 ( V_96 ) )
F_45 ( V_59 ) ;
V_195:
F_36 ( & V_84 ) ;
return V_42 ;
}
static int F_137 ( struct V_1 * V_2 , void * V_3 )
{
struct V_107 * V_108 = V_2 -> V_108 ;
V_210 = 1 ;
F_138 ( V_211 L_10 , V_108 -> V_130 ) ;
return 1 ;
}
static int F_139 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
char * V_212 = V_38 ;
if ( ( V_31 == V_39 ) &&
( V_2 -> V_47 == V_48 ) ) {
struct V_107 * V_108 = V_2 -> V_108 ;
if ( ! V_108 ) {
F_140 ( 1 , L_11 ) ;
return V_57 ;
}
if ( ! strchr ( V_212 , * V_108 -> V_130 ) )
return V_57 ;
F_19 ( ! V_2 -> V_54 ) ;
V_2 -> V_54 = F_137 ;
}
return V_57 ;
}
static T_4 int F_141 ( void )
{
int V_22 ;
F_138 ( V_211 L_12 ) ;
for ( V_22 = 0 ; V_22 < V_213 ; V_22 ++ ) {
struct V_58 * V_59 = NULL ;
struct V_214 * V_56 = & V_215 [ V_22 ] ;
int V_42 ;
V_42 = F_117 ( & V_216 , V_56 -> V_59 ,
false , & V_59 ) ;
if ( V_42 ) {
F_138 ( V_211
L_13 ,
V_56 -> V_59 , V_42 ) ;
F_45 ( V_59 ) ;
break;
}
F_142 () ;
if ( * V_56 -> V_217 )
F_13 ( V_59 -> V_28 , V_59 -> V_36 ,
F_139 ,
V_56 -> V_217 ) ;
V_210 = 0 ;
V_42 = F_17 ( V_59 , & V_56 -> V_50 ) ;
F_143 () ;
F_45 ( V_59 ) ;
if ( V_210 ) {
F_138 ( V_211
L_14 ,
V_56 -> V_59 ) ;
break;
}
if ( V_42 != V_56 -> V_7 ) {
F_138 ( V_211
L_15 ,
V_56 -> V_59 , V_56 -> V_7 ) ;
break;
}
}
if ( V_22 == V_213 )
F_138 ( V_218 L_16 ) ;
return 0 ;
}
