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
static void F_44 ( struct V_95 * V_96 )
{
V_96 -> V_79 &= ~ V_97 ;
}
static void F_45 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 )
F_44 ( V_96 ) ;
else
V_77 -> V_79 &= ~ V_98 ;
}
static void F_46 ( struct V_58 * V_59 )
{
if ( ! V_59 )
return;
F_43 ( V_59 ) ;
F_22 ( V_59 -> V_66 ) ;
F_22 ( V_59 ) ;
}
void F_47 ( struct V_95 * V_96 )
{
F_46 ( V_96 -> V_59 ) ;
V_96 -> V_59 = NULL ;
}
static void F_48 ( struct V_76 * V_77 )
{
F_46 ( V_77 -> V_59 ) ;
V_77 -> V_59 = NULL ;
}
void F_49 ( struct V_76 * V_77 )
{
if ( V_77 -> V_78 -> V_79 & V_80 )
F_47 ( V_77 -> V_78 ) ;
else
F_48 ( V_77 ) ;
}
static struct V_58 * F_50 ( void )
{
struct V_58 * V_59 ;
V_59 = F_51 ( sizeof( * V_59 ) , V_67 ) ;
return V_59 ;
}
static int F_52 ( struct V_58 * V_59 , int V_60 )
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
static inline void F_53 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
F_45 ( V_77 ) ;
if ( V_96 -> V_79 & V_80 )
F_21 ( V_96 -> V_59 ) ;
else
F_21 ( V_77 -> V_59 ) ;
}
static void F_54 ( struct V_83 * system ,
struct V_99 * V_100 )
{
struct V_76 * V_77 ;
struct V_95 * V_96 ;
F_55 (file, &tr->events, list) {
V_96 = V_77 -> V_78 ;
if ( strcmp ( V_96 -> V_101 -> system , system -> V_102 ) != 0 )
continue;
F_53 ( V_77 ) ;
}
}
static inline void F_56 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 ) {
F_46 ( V_96 -> V_59 ) ;
V_96 -> V_59 = NULL ;
} else {
F_46 ( V_77 -> V_59 ) ;
V_77 -> V_59 = NULL ;
}
}
static void F_57 ( struct V_83 * system ,
struct V_99 * V_100 )
{
struct V_76 * V_77 ;
struct V_95 * V_96 ;
F_55 (file, &tr->events, list) {
V_96 = V_77 -> V_78 ;
if ( strcmp ( V_96 -> V_101 -> system , system -> V_102 ) != 0 )
continue;
F_56 ( V_77 ) ;
}
}
static int F_58 ( struct V_61 * V_62 ,
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
int F_59 ( const char * type )
{
if ( strstr ( type , L_5 ) && strstr ( type , L_6 ) )
return V_104 ;
if ( strchr ( type , '[' ) && strstr ( type , L_6 ) )
return V_105 ;
return V_106 ;
}
static bool F_60 ( struct V_107 * V_108 )
{
return V_108 -> V_109 == V_110 ;
}
static bool F_61 ( struct V_107 * V_108 )
{
return V_108 -> V_109 == V_104 ||
V_108 -> V_109 == V_105 ||
V_108 -> V_109 == V_111 ;
}
static int F_62 ( struct V_107 * V_108 , int V_26 )
{
if ( F_61 ( V_108 ) &&
( V_26 != V_112 && V_26 != V_113 && V_26 != V_27 ) )
return 0 ;
if ( ! F_61 ( V_108 ) && V_26 == V_27 )
return 0 ;
return 1 ;
}
static T_3 F_63 ( int V_26 , int V_114 ,
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
static int F_64 ( struct V_61 * V_62 ,
struct V_107 * V_108 ,
struct V_1 * V_2 )
{
T_3 V_54 = F_4 ;
unsigned long long V_52 ;
int V_43 ;
V_2 -> V_5 = V_108 -> V_5 ;
if ( ! F_62 ( V_108 , V_2 -> V_26 ) ) {
F_20 ( V_62 , V_128 , 0 ) ;
return - V_41 ;
}
if ( F_61 ( V_108 ) ) {
F_11 ( V_2 ) ;
if ( V_108 -> V_109 == V_105 ) {
V_54 = F_1 ;
V_2 -> V_8 . V_9 = V_108 -> V_129 ;
} else if ( V_108 -> V_109 == V_104 )
V_54 = F_3 ;
else
V_54 = F_2 ;
} else if ( F_60 ( V_108 ) ) {
if ( strcmp ( V_108 -> V_102 , L_7 ) ) {
F_20 ( V_62 , V_130 , 0 ) ;
return - V_41 ;
}
} else {
if ( V_108 -> V_131 )
V_43 = F_65 ( V_2 -> V_8 . V_17 , 0 , & V_52 ) ;
else
V_43 = F_66 ( V_2 -> V_8 . V_17 , 0 , & V_52 ) ;
if ( V_43 ) {
F_20 ( V_62 , V_132 , 0 ) ;
return - V_41 ;
}
V_2 -> V_52 = V_52 ;
V_54 = F_63 ( V_2 -> V_26 , V_108 -> V_129 ,
V_108 -> V_131 ) ;
if ( ! V_54 ) {
F_20 ( V_62 , V_133 , 0 ) ;
return - V_41 ;
}
}
if ( V_2 -> V_26 == V_113 )
V_2 -> V_10 = 1 ;
V_2 -> V_54 = V_54 ;
return 0 ;
}
static void F_67 ( struct V_61 * V_62 ,
struct V_134 * V_53 ,
char * V_135 )
{
memset ( V_62 , '\0' , sizeof( * V_62 ) ) ;
V_62 -> V_136 . string = V_135 ;
V_62 -> V_136 . V_137 = strlen ( V_135 ) ;
V_62 -> V_53 = V_53 ;
F_68 ( & V_62 -> V_138 ) ;
F_68 ( & V_62 -> V_139 ) ;
}
static char F_69 ( struct V_61 * V_62 )
{
V_62 -> V_136 . V_137 -- ;
return V_62 -> V_136 . string [ V_62 -> V_136 . V_140 ++ ] ;
}
static char F_70 ( struct V_61 * V_62 )
{
if ( V_62 -> V_136 . V_140 == strlen ( V_62 -> V_136 . string ) )
return 0 ;
return V_62 -> V_136 . string [ V_62 -> V_136 . V_140 ] ;
}
static void F_71 ( struct V_61 * V_62 )
{
V_62 -> V_136 . V_137 -- ;
V_62 -> V_136 . V_140 ++ ;
}
static inline int F_72 ( struct V_61 * V_62 ,
int V_141 , int V_142 )
{
return V_62 -> V_53 [ V_141 ] . V_143 < V_62 -> V_53 [ V_142 ] . V_143 ;
}
static inline int F_73 ( struct V_61 * V_62 , char V_144 )
{
int V_22 ;
for ( V_22 = 0 ; strcmp ( V_62 -> V_53 [ V_22 ] . string , L_8 ) ; V_22 ++ ) {
if ( V_62 -> V_53 [ V_22 ] . string [ 0 ] == V_144 )
return 1 ;
}
return 0 ;
}
static int F_74 ( struct V_61 * V_62 , char V_145 )
{
char V_146 = F_70 ( V_62 ) ;
char V_147 [ 3 ] ;
int V_22 ;
V_147 [ 0 ] = V_145 ;
V_147 [ 1 ] = V_146 ;
V_147 [ 2 ] = '\0' ;
for ( V_22 = 0 ; strcmp ( V_62 -> V_53 [ V_22 ] . string , L_8 ) ; V_22 ++ ) {
if ( ! strcmp ( V_147 , V_62 -> V_53 [ V_22 ] . string ) ) {
F_71 ( V_62 ) ;
return V_62 -> V_53 [ V_22 ] . V_148 ;
}
}
V_147 [ 1 ] = '\0' ;
for ( V_22 = 0 ; strcmp ( V_62 -> V_53 [ V_22 ] . string , L_8 ) ; V_22 ++ ) {
if ( ! strcmp ( V_147 , V_62 -> V_53 [ V_22 ] . string ) )
return V_62 -> V_53 [ V_22 ] . V_148 ;
}
return V_149 ;
}
static inline void F_75 ( struct V_61 * V_62 )
{
memset ( V_62 -> V_150 . string , '\0' , V_151 ) ;
V_62 -> V_150 . V_140 = 0 ;
}
static inline int F_76 ( struct V_61 * V_62 , char V_144 )
{
if ( V_62 -> V_150 . V_140 == V_151 - 1 )
return - V_41 ;
V_62 -> V_150 . string [ V_62 -> V_150 . V_140 ++ ] = V_144 ;
return 0 ;
}
static int F_77 ( struct V_61 * V_62 , int V_26 )
{
struct V_152 * V_152 ;
V_152 = F_27 ( sizeof( * V_152 ) , V_67 ) ;
if ( ! V_152 )
return - V_68 ;
V_152 -> V_26 = V_26 ;
F_78 ( & V_152 -> V_153 , & V_62 -> V_138 ) ;
return 0 ;
}
static int F_79 ( struct V_61 * V_62 )
{
return F_80 ( & V_62 -> V_138 ) ;
}
static int F_81 ( struct V_61 * V_62 )
{
struct V_152 * V_152 ;
if ( F_79 ( V_62 ) )
return V_149 ;
V_152 = F_82 ( & V_62 -> V_138 , struct V_152 , V_153 ) ;
return V_152 -> V_26 ;
}
static int F_83 ( struct V_61 * V_62 )
{
struct V_152 * V_152 ;
int V_26 ;
if ( F_79 ( V_62 ) )
return V_149 ;
V_152 = F_82 ( & V_62 -> V_138 , struct V_152 , V_153 ) ;
V_26 = V_152 -> V_26 ;
F_84 ( & V_152 -> V_153 ) ;
F_22 ( V_152 ) ;
return V_26 ;
}
static void F_85 ( struct V_61 * V_62 )
{
while ( ! F_79 ( V_62 ) )
F_83 ( V_62 ) ;
}
static char * F_86 ( struct V_61 * V_62 )
{
return V_62 -> V_150 . string ;
}
static int F_87 ( struct V_61 * V_62 , char * V_150 )
{
struct V_154 * V_155 ;
V_155 = F_27 ( sizeof( * V_155 ) , V_67 ) ;
if ( ! V_155 )
return - V_68 ;
V_155 -> V_26 = V_149 ;
V_155 -> V_150 = F_24 ( V_150 , V_67 ) ;
if ( ! V_155 -> V_150 ) {
F_22 ( V_155 ) ;
return - V_68 ;
}
F_88 ( & V_155 -> V_153 , & V_62 -> V_139 ) ;
return 0 ;
}
static int F_89 ( struct V_61 * V_62 , int V_26 )
{
struct V_154 * V_155 ;
V_155 = F_27 ( sizeof( * V_155 ) , V_67 ) ;
if ( ! V_155 )
return - V_68 ;
V_155 -> V_26 = V_26 ;
V_155 -> V_150 = NULL ;
F_88 ( & V_155 -> V_153 , & V_62 -> V_139 ) ;
return 0 ;
}
static void F_90 ( struct V_61 * V_62 )
{
struct V_154 * V_155 ;
while ( ! F_80 ( & V_62 -> V_139 ) ) {
V_155 = F_82 ( & V_62 -> V_139 , struct V_154 , V_153 ) ;
F_84 ( & V_155 -> V_153 ) ;
F_22 ( V_155 -> V_150 ) ;
F_22 ( V_155 ) ;
}
}
static int F_91 ( struct V_61 * V_62 )
{
int V_156 = 0 ;
int V_26 , V_157 ;
char V_158 ;
while ( ( V_158 = F_69 ( V_62 ) ) ) {
if ( V_158 == '"' ) {
V_156 ^= 1 ;
continue;
}
if ( V_156 )
goto V_159;
if ( isspace ( V_158 ) )
continue;
if ( F_73 ( V_62 , V_158 ) ) {
V_26 = F_74 ( V_62 , V_158 ) ;
if ( V_26 == V_149 ) {
F_20 ( V_62 , V_133 , 0 ) ;
return - V_41 ;
}
if ( strlen ( F_86 ( V_62 ) ) ) {
F_87 ( V_62 , F_86 ( V_62 ) ) ;
F_75 ( V_62 ) ;
}
while ( ! F_79 ( V_62 ) ) {
V_157 = F_81 ( V_62 ) ;
if ( ! F_72 ( V_62 , V_157 , V_26 ) ) {
V_157 = F_83 ( V_62 ) ;
F_89 ( V_62 , V_157 ) ;
continue;
}
break;
}
F_77 ( V_62 , V_26 ) ;
continue;
}
if ( V_158 == '(' ) {
F_77 ( V_62 , V_160 ) ;
continue;
}
if ( V_158 == ')' ) {
if ( strlen ( F_86 ( V_62 ) ) ) {
F_87 ( V_62 , F_86 ( V_62 ) ) ;
F_75 ( V_62 ) ;
}
V_157 = F_83 ( V_62 ) ;
while ( V_157 != V_149 ) {
if ( V_157 == V_160 )
break;
F_89 ( V_62 , V_157 ) ;
V_157 = F_83 ( V_62 ) ;
}
if ( V_157 == V_149 ) {
F_20 ( V_62 , V_161 , 0 ) ;
return - V_41 ;
}
continue;
}
V_159:
if ( F_76 ( V_62 , V_158 ) ) {
F_20 ( V_62 , V_162 , 0 ) ;
return - V_41 ;
}
}
if ( strlen ( F_86 ( V_62 ) ) )
F_87 ( V_62 , F_86 ( V_62 ) ) ;
while ( ! F_79 ( V_62 ) ) {
V_157 = F_83 ( V_62 ) ;
if ( V_157 == V_149 )
break;
if ( V_157 == V_160 ) {
F_20 ( V_62 , V_161 , 0 ) ;
return - V_41 ;
}
F_89 ( V_62 , V_157 ) ;
}
return 0 ;
}
static struct V_1 * F_92 ( struct V_61 * V_62 ,
struct V_95 * V_96 ,
int V_26 , char * V_163 , char * V_164 )
{
struct V_107 * V_108 ;
static struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_26 = V_26 ;
if ( V_26 == V_92 || V_26 == V_51 )
return & V_2 ;
if ( ! V_163 || ! V_164 ) {
F_20 ( V_62 , V_165 , 0 ) ;
return NULL ;
}
V_108 = F_93 ( V_96 , V_163 ) ;
if ( ! V_108 ) {
F_20 ( V_62 , V_166 , 0 ) ;
return NULL ;
}
strcpy ( V_2 . V_8 . V_17 , V_164 ) ;
V_2 . V_8 . V_11 = strlen ( V_2 . V_8 . V_17 ) ;
V_2 . V_108 = V_108 ;
return F_64 ( V_62 , V_108 , & V_2 ) ? NULL : & V_2 ;
}
static int F_94 ( struct V_61 * V_62 )
{
int V_167 = 0 , V_168 = 0 ;
struct V_154 * V_155 ;
F_55 (elt, &ps->postfix, list) {
if ( V_155 -> V_26 == V_149 )
continue;
if ( V_155 -> V_26 == V_92 || V_155 -> V_26 == V_51 ) {
V_168 ++ ;
continue;
}
V_167 ++ ;
}
if ( ! V_167 || V_168 >= V_167 ) {
F_20 ( V_62 , V_169 , 0 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_95 ( struct V_61 * V_62 )
{
struct V_154 * V_155 ;
int V_60 = 0 ;
F_55 (elt, &ps->postfix, list) {
if ( V_155 -> V_26 == V_149 )
continue;
V_60 ++ ;
}
return V_60 ;
}
static int F_96 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
struct V_170 * V_56 = V_38 ;
if ( F_19 ( V_56 -> V_171 ++ > V_56 -> V_172 ) ) {
* V_42 = - V_41 ;
return V_44 ;
}
return V_57 ;
}
static int F_97 ( struct V_58 * V_59 ,
struct V_1 * V_36 )
{
struct V_170 V_38 = {
. V_172 = 3 * V_59 -> V_60 ,
. V_171 = 0 ,
} ;
return F_13 ( V_59 -> V_28 , V_36 ,
F_96 , & V_38 ) ;
}
static int F_98 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
int * V_171 = V_38 ;
if ( ( V_31 == V_39 ) &&
( V_2 -> V_47 == V_48 ) )
( * V_171 ) ++ ;
return V_57 ;
}
static int F_99 ( struct V_1 * V_28 , struct V_1 * V_36 )
{
int V_171 = 0 , V_43 ;
V_43 = F_13 ( V_28 , V_36 , F_98 , & V_171 ) ;
F_19 ( V_43 ) ;
return V_171 ;
}
static int F_100 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
struct V_173 * V_56 = V_38 ;
struct V_1 * V_36 = V_56 -> V_36 ;
if ( V_31 != V_39 )
return V_57 ;
if ( V_2 -> V_47 != V_48 )
return V_57 ;
if ( F_19 ( V_56 -> V_171 == V_56 -> V_174 ) ) {
* V_42 = - V_41 ;
return V_44 ;
}
V_2 -> V_29 &= ~ V_93 ;
V_36 -> V_53 [ V_56 -> V_171 ++ ] = V_2 -> V_29 ;
return V_57 ;
}
static int F_101 ( struct V_1 * V_28 , struct V_1 * V_36 )
{
struct V_173 V_38 = {
. V_36 = V_36 ,
. V_171 = 0 ,
} ;
int V_174 ;
V_36 -> V_29 &= ~ V_93 ;
if ( V_36 -> V_47 == V_48 )
return 0 ;
V_174 = F_99 ( V_28 , & V_28 [ V_36 -> V_47 ] ) ;
V_174 += F_99 ( V_28 , & V_28 [ V_36 -> V_49 ] ) ;
V_36 -> V_53 = F_38 ( V_174 , sizeof( * V_36 -> V_53 ) , V_67 ) ;
if ( ! V_36 -> V_53 )
return - V_68 ;
V_36 -> V_52 = V_174 ;
V_38 . V_174 = V_174 ;
return F_13 ( V_28 , V_36 , F_100 , & V_38 ) ;
}
static int F_102 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
struct V_1 * V_28 = V_38 ;
if ( V_31 != V_39 )
return V_57 ;
if ( ! ( V_2 -> V_29 & V_93 ) )
return V_57 ;
* V_42 = F_101 ( V_28 , V_2 ) ;
if ( * V_42 )
return V_44 ;
return V_45 ;
}
static int F_103 ( struct V_58 * V_59 ,
struct V_1 * V_36 )
{
return F_13 ( V_59 -> V_28 , V_36 , F_102 ,
V_59 -> V_28 ) ;
}
static int F_104 ( struct V_95 * V_96 ,
struct V_58 * V_59 ,
struct V_61 * V_62 ,
char * V_66 ,
bool V_175 )
{
char * V_163 = NULL , * V_164 = NULL ;
struct V_1 * V_2 ;
struct V_1 * V_36 ;
struct V_154 * V_155 ;
struct V_86 V_87 = { } ;
int V_42 ;
int V_60 = 0 ;
V_60 = F_95 ( V_62 ) ;
if ( V_60 >= V_176 ) {
F_20 ( V_62 , V_103 , 0 ) ;
return - V_88 ;
}
V_42 = F_94 ( V_62 ) ;
if ( V_42 )
return V_42 ;
if ( ! V_175 ) {
V_42 = F_37 ( & V_87 , V_60 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_52 ( V_59 , V_60 ) ;
if ( V_42 )
goto V_177;
}
V_60 = 0 ;
F_55 (elt, &ps->postfix, list) {
if ( V_155 -> V_26 == V_149 ) {
if ( ! V_163 )
V_163 = V_155 -> V_150 ;
else if ( ! V_164 )
V_164 = V_155 -> V_150 ;
else {
F_20 ( V_62 , V_178 , 0 ) ;
V_42 = - V_41 ;
goto V_177;
}
continue;
}
if ( F_19 ( V_60 ++ == V_176 ) ) {
F_20 ( V_62 , V_103 , 0 ) ;
V_42 = - V_88 ;
goto V_177;
}
V_2 = F_92 ( V_62 , V_96 , V_155 -> V_26 , V_163 , V_164 ) ;
if ( ! V_2 ) {
V_42 = - V_41 ;
goto V_177;
}
if ( ! V_175 ) {
V_42 = F_58 ( V_62 , V_59 , V_2 , & V_87 ) ;
if ( V_42 )
goto V_177;
}
V_163 = V_164 = NULL ;
}
if ( ! V_175 ) {
V_2 = F_41 ( & V_87 ) ;
if ( ! V_2 )
return - V_41 ;
V_36 = V_2 ;
V_2 = F_41 ( & V_87 ) ;
if ( F_19 ( V_2 ) ) {
V_42 = - V_41 ;
V_59 -> V_36 = NULL ;
goto V_177;
}
V_42 = F_97 ( V_59 , V_36 ) ;
if ( V_42 )
goto V_177;
V_42 = F_103 ( V_59 , V_36 ) ;
if ( V_42 )
goto V_177;
F_105 () ;
V_59 -> V_36 = V_36 ;
}
V_42 = 0 ;
V_177:
F_39 ( & V_87 ) ;
return V_42 ;
}
static inline void F_106 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 )
V_96 -> V_79 |= V_97 ;
else
V_77 -> V_79 |= V_98 ;
}
static inline void F_107 ( struct V_76 * V_77 ,
struct V_58 * V_59 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 )
F_108 ( V_96 -> V_59 , V_59 ) ;
else
F_108 ( V_77 -> V_59 , V_59 ) ;
}
static inline void F_109 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 )
F_110 ( V_96 -> V_59 , NULL ) ;
else
F_110 ( V_77 -> V_59 , NULL ) ;
}
static inline void
F_111 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 )
V_96 -> V_79 |= V_179 ;
else
V_77 -> V_79 |= V_180 ;
}
static inline void
F_112 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_96 -> V_79 & V_80 )
V_96 -> V_79 &= ~ V_179 ;
else
V_77 -> V_79 &= ~ V_180 ;
}
static inline bool
F_113 ( struct V_76 * V_77 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
if ( V_77 -> V_79 & V_180 )
return true ;
if ( ( V_96 -> V_79 & V_80 ) &&
( V_96 -> V_79 & V_179 ) )
return true ;
return false ;
}
static int F_114 ( struct V_83 * system ,
struct V_99 * V_100 ,
struct V_61 * V_62 ,
char * V_66 )
{
struct V_76 * V_77 ;
struct V_95 * V_96 ;
struct V_181 * V_182 ;
struct V_181 * V_183 ;
F_115 ( V_181 ) ;
bool V_177 = true ;
int V_42 ;
F_55 (file, &tr->events, list) {
V_96 = V_77 -> V_78 ;
if ( strcmp ( V_96 -> V_101 -> system , system -> V_102 ) != 0 )
continue;
V_42 = F_104 ( V_96 , NULL , V_62 , V_66 , true ) ;
if ( V_42 )
F_111 ( V_77 ) ;
else
F_112 ( V_77 ) ;
}
F_55 (file, &tr->events, list) {
struct V_58 * V_59 ;
V_96 = V_77 -> V_78 ;
if ( strcmp ( V_96 -> V_101 -> system , system -> V_102 ) != 0 )
continue;
if ( F_113 ( V_77 ) )
continue;
V_182 = F_51 ( sizeof( * V_182 ) , V_67 ) ;
if ( ! V_182 )
goto V_184;
F_88 ( & V_182 -> V_153 , & V_181 ) ;
V_182 -> V_59 = F_50 () ;
if ( ! V_182 -> V_59 )
goto V_184;
V_59 = V_182 -> V_59 ;
V_42 = F_23 ( V_59 , V_66 ) ;
if ( V_42 )
goto V_184;
V_42 = F_104 ( V_96 , V_59 , V_62 , V_66 , false ) ;
if ( V_42 ) {
F_45 ( V_77 ) ;
F_20 ( V_62 , V_185 , 0 ) ;
F_28 ( V_62 , V_59 ) ;
} else
F_106 ( V_77 ) ;
V_59 = V_58 ( V_77 ) ;
F_107 ( V_77 , V_182 -> V_59 ) ;
V_182 -> V_59 = V_59 ;
V_177 = false ;
}
if ( V_177 )
goto V_177;
F_116 () ;
F_117 (filter_item, tmp, &filter_list, list) {
F_46 ( V_182 -> V_59 ) ;
F_84 ( & V_182 -> V_153 ) ;
F_22 ( V_182 ) ;
}
return 0 ;
V_177:
F_117 (filter_item, tmp, &filter_list, list) {
F_84 ( & V_182 -> V_153 ) ;
F_22 ( V_182 ) ;
}
F_20 ( V_62 , V_185 , 0 ) ;
return - V_41 ;
V_184:
if ( ! V_177 )
F_116 () ;
F_117 (filter_item, tmp, &filter_list, list) {
F_46 ( V_182 -> V_59 ) ;
F_84 ( & V_182 -> V_153 ) ;
F_22 ( V_182 ) ;
}
return - V_68 ;
}
static int F_118 ( char * V_186 , bool V_187 ,
struct V_61 * * V_188 ,
struct V_58 * * V_189 )
{
struct V_58 * V_59 ;
struct V_61 * V_62 = NULL ;
int V_42 = 0 ;
F_15 ( * V_188 || * V_189 ) ;
V_59 = F_50 () ;
if ( V_59 && V_187 )
V_42 = F_23 ( V_59 , V_186 ) ;
V_62 = F_51 ( sizeof( * V_62 ) , V_67 ) ;
if ( ! V_59 || ! V_62 || V_42 ) {
F_22 ( V_62 ) ;
F_46 ( V_59 ) ;
return - V_68 ;
}
* V_189 = V_59 ;
* V_188 = V_62 ;
F_67 ( V_62 , V_190 , V_186 ) ;
V_42 = F_91 ( V_62 ) ;
if ( V_42 && V_187 )
F_28 ( V_62 , V_59 ) ;
return V_42 ;
}
static void F_119 ( struct V_61 * V_62 )
{
if ( V_62 ) {
F_85 ( V_62 ) ;
F_90 ( V_62 ) ;
F_22 ( V_62 ) ;
}
}
static int F_120 ( struct V_95 * V_96 ,
char * V_186 , bool V_187 ,
struct V_58 * * V_189 )
{
struct V_58 * V_59 = NULL ;
struct V_61 * V_62 = NULL ;
int V_42 ;
V_42 = F_118 ( V_186 , V_187 , & V_62 , & V_59 ) ;
if ( ! V_42 ) {
V_42 = F_104 ( V_96 , V_59 , V_62 , V_186 , false ) ;
if ( V_42 && V_187 )
F_28 ( V_62 , V_59 ) ;
}
F_119 ( V_62 ) ;
* V_189 = V_59 ;
return V_42 ;
}
static int F_121 ( struct V_83 * system ,
struct V_99 * V_100 ,
char * V_186 , struct V_58 * * V_189 )
{
struct V_58 * V_59 = NULL ;
struct V_61 * V_62 = NULL ;
int V_42 ;
V_42 = F_118 ( V_186 , true , & V_62 , & V_59 ) ;
if ( ! V_42 ) {
V_42 = F_114 ( system , V_100 , V_62 , V_186 ) ;
if ( ! V_42 ) {
F_22 ( V_59 -> V_66 ) ;
V_59 -> V_66 = NULL ;
} else {
F_28 ( V_62 , V_59 ) ;
}
}
F_119 ( V_62 ) ;
* V_189 = V_59 ;
return V_42 ;
}
int F_122 ( struct V_76 * V_77 , char * V_66 )
{
struct V_95 * V_96 = V_77 -> V_78 ;
struct V_58 * V_59 ;
int V_42 ;
if ( ! strcmp ( F_123 ( V_66 ) , L_9 ) ) {
F_45 ( V_77 ) ;
V_59 = V_58 ( V_77 ) ;
if ( ! V_59 )
return 0 ;
F_109 ( V_77 ) ;
F_116 () ;
F_46 ( V_59 ) ;
return 0 ;
}
V_42 = F_120 ( V_96 , V_66 , true , & V_59 ) ;
if ( V_59 ) {
struct V_58 * V_183 ;
V_183 = V_58 ( V_77 ) ;
if ( ! V_42 )
F_106 ( V_77 ) ;
else
F_45 ( V_77 ) ;
F_107 ( V_77 , V_59 ) ;
if ( V_183 ) {
F_116 () ;
F_46 ( V_183 ) ;
}
}
return V_42 ;
}
int F_124 ( struct V_191 * V_192 ,
char * V_66 )
{
struct V_83 * system = V_192 -> V_193 ;
struct V_99 * V_100 = V_192 -> V_100 ;
struct V_58 * V_59 ;
int V_42 = 0 ;
F_35 ( & V_84 ) ;
if ( ! V_192 -> V_194 ) {
V_42 = - V_195 ;
goto V_196;
}
if ( ! strcmp ( F_123 ( V_66 ) , L_9 ) ) {
F_54 ( system , V_100 ) ;
F_21 ( system -> V_59 ) ;
V_59 = system -> V_59 ;
system -> V_59 = NULL ;
F_116 () ;
F_57 ( system , V_100 ) ;
F_46 ( V_59 ) ;
goto V_196;
}
V_42 = F_121 ( system , V_100 , V_66 , & V_59 ) ;
if ( V_59 ) {
F_46 ( system -> V_59 ) ;
system -> V_59 = V_59 ;
}
V_196:
F_36 ( & V_84 ) ;
return V_42 ;
}
void F_125 ( struct V_197 * V_3 )
{
struct V_58 * V_59 = V_3 -> V_59 ;
V_3 -> V_59 = NULL ;
F_46 ( V_59 ) ;
}
static char * *
F_126 ( char * V_71 , int V_11 , int * V_171 )
{
char * V_15 , * V_198 , * * V_199 ;
V_15 = F_127 ( V_71 , V_11 , V_67 ) ;
if ( ! V_15 )
return NULL ;
while ( ( V_198 = strchr ( V_15 , ',' ) ) )
* V_198 = ' ' ;
V_199 = F_128 ( V_67 , V_15 , V_171 ) ;
F_22 ( V_15 ) ;
return V_199 ;
}
static int F_129 ( struct V_200 * V_53 , int V_59 ,
int V_201 , char * V_199 , int V_11 )
{
int V_43 ;
if ( V_59 )
V_43 = F_130 ( V_53 , V_199 , V_11 , V_201 ) ;
else
V_43 = F_131 ( V_53 , V_199 , V_11 , V_201 ) ;
return V_43 ;
}
static int F_132 ( int V_59 , char * V_71 , int V_11 ,
struct V_202 * V_38 )
{
int V_22 , V_203 , V_43 = - V_41 ;
int * V_201 ;
char * * V_199 ;
V_201 = V_59 ? & V_38 -> V_204 : & V_38 -> V_205 ;
V_199 = F_126 ( V_71 , V_11 , & V_203 ) ;
if ( ! V_199 )
return - V_41 ;
for ( V_22 = 0 ; V_22 < V_203 ; V_22 ++ ) {
V_43 = F_129 ( V_38 -> V_53 , V_59 , * V_201 ,
V_199 [ V_22 ] , strlen ( V_199 [ V_22 ] ) ) ;
if ( V_43 )
break;
if ( * V_201 )
* V_201 = 0 ;
}
F_133 ( V_199 ) ;
return V_43 ;
}
static int F_134 ( struct V_1 * V_2 , int V_206 )
{
struct V_107 * V_108 = V_2 -> V_108 ;
if ( V_206 ) {
if ( ( V_2 -> V_26 != V_112 ) && ( V_2 -> V_26 != V_113 ) )
return - V_41 ;
if ( strcmp ( V_108 -> V_102 , L_7 ) )
return - V_41 ;
} else {
if ( V_2 -> V_26 != V_51 )
return - V_41 ;
}
return 0 ;
}
static int F_135 ( enum V_30 V_31 ,
struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
if ( ( V_31 != V_39 ) ||
( V_2 -> V_47 != V_48 ) ) {
* V_42 = F_134 ( V_2 , 0 ) ;
} else {
* V_42 = F_134 ( V_2 , 1 ) ;
if ( * V_42 )
return V_44 ;
* V_42 = F_132 ( V_2 -> V_26 == V_112 ,
V_2 -> V_8 . V_17 ,
V_2 -> V_8 . V_11 ,
V_38 ) ;
}
return ( * V_42 ) ? V_44 : V_57 ;
}
static int F_136 ( struct V_197 * V_3 ,
struct V_58 * V_59 )
{
struct V_202 V_38 = {
. V_204 = 1 ,
. V_205 = 1 ,
. V_53 = & V_3 -> V_200 ,
} ;
return F_13 ( V_59 -> V_28 , V_59 -> V_36 ,
F_135 , & V_38 ) ;
}
static int F_136 ( struct V_197 * V_3 ,
struct V_58 * V_59 )
{
return - V_195 ;
}
int F_137 ( struct V_197 * V_3 , int V_207 ,
char * V_186 )
{
int V_42 ;
struct V_58 * V_59 ;
struct V_95 * V_96 ;
F_35 ( & V_84 ) ;
V_96 = V_3 -> V_208 ;
V_42 = - V_41 ;
if ( ! V_96 )
goto V_196;
V_42 = - V_209 ;
if ( V_3 -> V_59 )
goto V_196;
V_42 = F_120 ( V_96 , V_186 , false , & V_59 ) ;
if ( V_42 )
goto V_210;
if ( F_138 ( V_96 ) )
V_42 = F_136 ( V_3 , V_59 ) ;
else
V_3 -> V_59 = V_59 ;
V_210:
if ( V_42 || F_138 ( V_96 ) )
F_46 ( V_59 ) ;
V_196:
F_36 ( & V_84 ) ;
return V_42 ;
}
static int F_139 ( struct V_1 * V_2 , void * V_3 )
{
struct V_107 * V_108 = V_2 -> V_108 ;
V_211 = 1 ;
F_140 ( V_212 L_10 , V_108 -> V_102 ) ;
return 1 ;
}
static int F_141 ( enum V_30 V_31 , struct V_1 * V_2 ,
int * V_42 , void * V_38 )
{
char * V_213 = V_38 ;
if ( ( V_31 == V_39 ) &&
( V_2 -> V_47 == V_48 ) ) {
struct V_107 * V_108 = V_2 -> V_108 ;
if ( ! V_108 ) {
F_142 ( 1 , L_11 ) ;
return V_57 ;
}
if ( ! strchr ( V_213 , * V_108 -> V_102 ) )
return V_57 ;
F_19 ( ! V_2 -> V_54 ) ;
V_2 -> V_54 = F_139 ;
}
return V_57 ;
}
static T_4 int F_143 ( void )
{
int V_22 ;
F_140 ( V_212 L_12 ) ;
for ( V_22 = 0 ; V_22 < V_214 ; V_22 ++ ) {
struct V_58 * V_59 = NULL ;
struct V_215 * V_56 = & V_216 [ V_22 ] ;
int V_42 ;
V_42 = F_120 ( & V_217 , V_56 -> V_59 ,
false , & V_59 ) ;
if ( V_42 ) {
F_140 ( V_212
L_13 ,
V_56 -> V_59 , V_42 ) ;
F_46 ( V_59 ) ;
break;
}
F_144 () ;
if ( * V_56 -> V_218 )
F_13 ( V_59 -> V_28 , V_59 -> V_36 ,
F_141 ,
V_56 -> V_218 ) ;
V_211 = 0 ;
V_42 = F_17 ( V_59 , & V_56 -> V_50 ) ;
F_145 () ;
F_46 ( V_59 ) ;
if ( V_211 ) {
F_140 ( V_212
L_14 ,
V_56 -> V_59 ) ;
break;
}
if ( V_42 != V_56 -> V_7 ) {
F_140 ( V_212
L_15 ,
V_56 -> V_59 , V_56 -> V_7 ) ;
break;
}
}
if ( V_22 == V_214 )
F_140 ( V_219 L_16 ) ;
return 0 ;
}
