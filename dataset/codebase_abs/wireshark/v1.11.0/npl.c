static void F_1 ( const char * V_1 , int line , const char * V_2 ) {
fprintf ( V_3 , L_1 , V_1 , line , V_2 ) ;
abort () ;
}
static struct V_4 *
F_2 ( void )
{
V_5 ++ ;
return V_6 ;
}
static void
F_3 ( struct V_4 * V_7 )
{
-- V_5 ;
while ( V_6 != V_7 ) {
struct V_4 * V_8 = V_6 ;
V_6 = V_6 -> V_9 ;
free ( V_8 ) ;
}
}
static unsigned int
F_4 ( const char * V_10 )
{
unsigned int V_11 = 5381 ;
while ( * V_10 ) {
V_11 = ( ( V_11 << 5 ) + V_11 ) + tolower ( * V_10 ) ;
V_10 ++ ;
}
return V_11 ;
}
static struct V_4 *
F_5 ( const char * V_12 , int type )
{
struct V_4 * V_7 ;
unsigned int V_11 ;
V_11 = F_4 ( V_12 ) ;
for ( V_7 = V_6 ; V_7 ; V_7 = V_7 -> V_9 ) {
if ( V_7 -> V_11 == V_11 && ! strcasecmp ( V_7 -> V_12 , V_12 ) ) {
return V_7 ;
}
}
return NULL ;
}
static struct V_4 *
F_6 ( const char * V_12 , enum V_13 type , void * V_14 )
{
struct V_4 * V_7 ;
V_7 = F_5 ( V_12 , V_15 ) ;
if ( V_7 ) {
if ( V_7 -> V_16 == V_5 ) {
fprintf ( V_3 , L_2 , V_12 , V_7 -> type ) ;
abort () ;
} else
fprintf ( V_3 , L_3 , V_12 , V_7 -> type ) ;
}
V_7 = F_7 ( struct V_4 ) ;
V_7 -> V_12 = V_12 ;
V_7 -> V_11 = F_4 ( V_12 ) ;
V_7 -> type = type ;
V_7 -> V_16 = V_5 ;
V_7 -> V_14 = V_14 ;
V_7 -> V_9 = V_6 ;
V_6 = V_7 ;
return V_7 ;
}
static struct V_17 *
F_8 ( T_1 * V_18 )
{
struct V_17 * V_19 = F_7 ( struct V_17 ) ;
V_19 -> V_18 = V_18 ;
V_19 -> V_9 = V_20 ;
V_20 = V_19 ;
return V_19 ;
}
static const char *
F_9 ( const struct V_17 * V_21 )
{
static char V_22 [ 256 ] ;
snprintf ( V_22 , sizeof( V_22 ) , L_4 , V_21 -> V_18 -> V_12 ) ;
return V_22 ;
}
static struct V_23 *
F_10 ( struct V_24 * V_18 , const struct V_25 * V_26 )
{
struct V_23 * V_19 = F_7 ( struct V_23 ) ;
V_19 -> V_18 = V_18 ;
V_19 -> V_26 = V_26 -> V_12 ;
V_19 -> V_9 = V_27 ;
V_27 = V_19 ;
return V_19 ;
}
static T_2
F_11 ( char * V_28 , T_2 V_29 , const char * V_10 )
{
T_2 V_30 = 0 ;
int V_31 ;
int V_32 = 0 ;
int V_33 = - 1 ;
for ( V_31 = 0 ; V_10 [ V_31 ] ; V_31 ++ ) {
int V_34 = isupper ( V_10 [ V_31 ] ) ;
if ( V_33 != V_34 && V_34 ) {
if ( V_32 > 0 ) {
if ( V_30 < V_29 )
V_28 [ V_30 ++ ] = '_' ;
}
V_32 ++ ;
}
V_33 = V_34 ;
if ( V_30 < V_29 )
V_28 [ V_30 ++ ] = tolower ( V_10 [ V_31 ] ) ;
}
return V_30 ;
}
static const char *
F_12 ( const struct V_23 * V_35 )
{
static char V_36 [ 256 ] ;
T_2 V_30 ;
V_30 = snprintf ( V_36 , sizeof( V_36 ) , L_5 ) ;
F_13 ( V_30 < sizeof( V_36 ) ) ;
if ( V_35 -> V_26 ) {
V_30 += F_11 ( V_36 + V_30 , sizeof( V_36 ) - V_30 , V_35 -> V_26 ) ;
F_13 ( V_30 < sizeof( V_36 ) ) ;
V_36 [ V_30 ++ ] = '_' ;
F_13 ( V_30 < sizeof( V_36 ) ) ;
}
V_30 += F_11 ( V_36 + V_30 , sizeof( V_36 ) - V_30 , V_35 -> V_18 -> V_12 ) ;
F_13 ( V_30 < sizeof( V_36 ) ) ;
V_36 [ V_30 ++ ] = '\0' ;
return V_36 ;
}
static const char *
F_14 ( const struct V_23 * V_35 )
{
return V_35 -> V_18 -> V_12 ;
}
static const char *
F_15 ( const struct V_23 * V_35 )
{
static char V_37 [ 1024 ] ;
T_2 V_30 ;
V_30 = 0 ;
if ( V_35 -> V_26 ) {
V_30 += F_11 ( V_37 + V_30 , sizeof( V_37 ) - V_30 , V_35 -> V_26 ) ;
F_13 ( V_30 < sizeof( V_37 ) ) ;
V_37 [ V_30 ++ ] = '.' ;
F_13 ( V_30 < sizeof( V_37 ) ) ;
}
V_30 += F_11 ( V_37 + V_30 , sizeof( V_37 ) - V_30 , V_35 -> V_18 -> V_12 ) ;
F_13 ( V_30 < sizeof( V_37 ) ) ;
V_37 [ V_30 ++ ] = '\0' ;
F_13 ( V_30 < sizeof( V_37 ) ) ;
return V_37 ;
}
static const char *
F_16 ( const struct V_23 * V_35 )
{
if ( V_35 -> V_38 )
return V_35 -> V_38 ;
return L_6 ;
}
static const char *
F_17 ( const struct V_23 * V_35 )
{
return L_7 ;
}
static unsigned int
F_18 ( const struct V_23 * V_35 )
{
return 0 ;
}
static int
F_19 ( const T_3 * V_39 )
{
int V_40 = 0 ;
while ( V_39 ) {
V_40 ++ ;
V_39 = V_39 -> V_9 ;
}
return V_40 ;
}
static struct V_4 *
F_20 ( const T_4 * V_41 )
{
struct V_4 * V_7 = NULL ;
if ( V_41 -> type == V_42 ) {
const char * V_12 = V_41 -> V_12 . V_12 ;
V_7 = F_5 ( V_12 , V_15 ) ;
if ( ! V_7 ) {
fprintf ( V_3 , L_8 , V_12 ) ;
abort () ;
}
if ( V_7 -> type == V_43 ) {
struct V_4 * V_44 = F_20 ( V_7 -> V_14 ) ;
if ( V_44 )
V_7 = V_44 ;
}
}
return V_7 ;
}
static int
F_21 ( const T_4 * V_41 , int * V_45 )
{
struct V_4 * V_7 ;
if ( V_41 -> type == V_46 ) {
* V_45 = V_41 -> V_47 . V_48 ;
return 1 ;
}
if ( V_41 -> type == V_49 ) {
if ( ! F_21 ( V_41 -> V_50 . V_51 , V_45 ) )
return 0 ;
switch ( V_41 -> V_50 . V_52 ) {
case V_53 :
* V_45 = - ( * V_45 ) ;
return 1 ;
case V_54 :
* V_45 = ~ ( * V_45 ) ;
return 1 ;
case V_55 :
* V_45 = ! ( * V_45 ) ;
return 1 ;
}
return 0 ;
}
V_7 = F_20 ( V_41 ) ;
if ( V_7 && V_7 -> type == V_43 )
return F_21 ( V_7 -> V_14 , V_45 ) ;
return 0 ;
}
static int
F_22 ( const T_4 * V_41 , const char * * V_45 )
{
struct V_4 * V_7 ;
if ( V_41 -> type == V_56 ) {
* V_45 = V_41 -> V_10 . V_10 ;
return 1 ;
}
V_7 = F_20 ( V_41 ) ;
if ( V_7 && V_7 -> type == V_43 )
return F_22 ( V_7 -> V_14 , V_45 ) ;
return 0 ;
}
static const char *
F_23 ( const T_5 * V_32 , int V_57 )
{
switch ( V_32 -> type ) {
case V_58 :
if ( V_57 == 4 )
return L_9 ;
if ( V_57 == 8 )
return L_10 ;
fprintf ( V_3 , L_11 , V_57 ) ;
return NULL ;
case V_59 :
if ( V_57 == 1 )
return L_12 ;
if ( V_57 == 2 )
return L_13 ;
if ( V_57 == 3 || V_57 == 4 )
return L_14 ;
if ( V_57 > 4 && V_57 <= 8 )
return L_15 ;
fprintf ( V_3 , L_16 , V_57 ) ;
return NULL ;
case V_60 :
if ( V_57 == 1 )
return L_17 ;
if ( V_57 == 2 )
return L_18 ;
if ( V_57 == 3 || V_57 == 4 )
return L_19 ;
if ( V_57 > 4 && V_57 <= 8 )
return L_20 ;
fprintf ( V_3 , L_16 , V_57 ) ;
return NULL ;
case V_61 :
return L_21 ;
}
fprintf ( V_3 , L_22 , V_32 -> type , V_57 ) ;
return NULL ;
}
static const char *
F_24 ( const T_5 * V_32 , int V_57 , int V_62 )
{
switch ( V_32 -> type ) {
case V_58 :
if ( V_57 == 4 && V_62 == V_63 )
return L_23 ;
if ( V_57 == 4 && V_62 == V_64 )
return L_24 ;
if ( V_57 == 8 && V_62 == V_63 )
return L_25 ;
if ( V_57 == 8 && V_62 == V_64 )
return L_26 ;
fprintf ( V_3 , L_27 , V_57 , V_62 ) ;
return NULL ;
case V_60 :
case V_59 :
if ( V_57 == 1 )
return L_28 ;
if ( V_57 == 2 && V_62 == V_63 )
return L_29 ;
if ( V_57 == 2 && V_62 == V_64 )
return L_30 ;
if ( V_32 -> type == V_60 && V_57 == 3 && V_62 == V_63 )
return L_31 ;
if ( V_32 -> type == V_60 && V_57 == 3 && V_62 == V_64 )
return L_32 ;
if ( V_57 == 4 && V_62 == V_63 )
return L_33 ;
if ( V_57 == 4 && V_62 == V_64 )
return L_34 ;
fprintf ( V_3 , L_35 , V_57 , V_62 ) ;
return NULL ;
}
fprintf ( V_3 , L_36 , V_32 -> type , V_57 , V_62 ) ;
return NULL ;
}
static const char *
F_25 ( const T_5 * V_32 , int V_57 )
{
switch ( V_32 -> type ) {
case V_58 :
if ( V_57 == 4 )
return L_37 ;
if ( V_57 == 8 )
return L_38 ;
fprintf ( V_3 , L_11 , V_57 ) ;
return NULL ;
case V_59 :
if ( V_57 == 1 )
return L_39 ;
if ( V_57 == 2 )
return L_40 ;
if ( V_57 == 3 )
return L_41 ;
if ( V_57 == 4 )
return L_42 ;
if ( V_57 > 4 && V_57 <= 8 )
return L_43 ;
fprintf ( V_3 , L_16 , V_57 ) ;
return NULL ;
case V_60 :
if ( V_57 == 1 )
return L_44 ;
if ( V_57 == 2 )
return L_45 ;
if ( V_57 == 3 )
return L_46 ;
if ( V_57 == 4 )
return L_47 ;
if ( V_57 > 4 && V_57 <= 8 )
return L_48 ;
fprintf ( V_3 , L_16 , V_57 ) ;
return NULL ;
case V_61 :
fprintf ( V_3 , L_49 , V_57 ) ;
return L_50 ;
}
fprintf ( V_3 , L_22 , V_32 -> type , V_57 ) ;
return NULL ;
}
static const char *
F_26 ( T_6 V_65 )
{
switch ( V_65 ) {
case V_53 :
return L_51 ;
case V_55 :
return L_52 ;
case V_54 :
return L_53 ;
}
fprintf ( V_3 , L_54 , V_65 ) ;
return L_55 ;
}
static const char *
F_27 ( T_7 V_65 )
{
switch ( V_65 ) {
case V_66 :
return L_56 ;
case V_67 :
return L_51 ;
case V_68 :
return L_57 ;
case V_69 :
return L_58 ;
case V_70 :
return L_59 ;
case V_71 :
return L_60 ;
case V_72 :
return L_61 ;
case V_73 :
return L_62 ;
case V_74 :
return L_63 ;
case V_75 :
return L_64 ;
case V_76 :
return L_65 ;
case V_77 :
return L_66 ;
case V_78 :
return L_67 ;
case V_79 :
return L_68 ;
case V_80 :
return L_69 ;
}
fprintf ( V_3 , L_54 , V_65 ) ;
return L_55 ;
}
static enum V_81
F_28 ( const char * V_12 )
{
if ( ! strcasecmp ( V_12 , L_70 ) )
return V_82 ;
if ( ! strcasecmp ( V_12 , L_71 ) )
return V_83 ;
if ( ! strcasecmp ( V_12 , L_72 ) )
return V_84 ;
if ( ! strcasecmp ( V_12 , L_73 ) )
return V_85 ;
if ( ! strcasecmp ( V_12 , L_74 ) )
return V_86 ;
fprintf ( V_3 , L_75 , V_12 ) ;
abort () ;
return - 1 ;
}
static int
F_29 ( const struct V_87 * V_88 )
{
int V_89 = 0 ;
switch ( V_88 -> type ) {
case V_42 :
V_89 |= ( int ) F_28 ( V_88 -> V_12 . V_12 ) ;
break;
case V_90 :
V_89 |= F_29 ( V_88 -> V_91 . V_92 ) ;
V_89 |= ( int ) F_28 ( V_88 -> V_91 . V_93 ) ;
break;
default:
fprintf ( V_3 , L_76 , V_88 -> type ) ;
break;
}
F_13 ( ! ( ( V_89 & V_83 ) && ( V_89 & V_84 ) ) ) ;
return V_89 ;
}
static void
F_30 ( T_8 * V_94 )
{
while ( V_94 ) {
struct V_87 * V_88 ;
const char * V_12 = NULL ;
int V_89 = 0 ;
if ( V_94 -> V_88 -> type == V_95 && V_94 -> V_88 -> V_96 . V_52 == V_97 ) {
V_88 = V_94 -> V_88 -> V_96 . V_98 ;
V_94 -> V_99 = V_94 -> V_88 -> V_96 . V_100 ;
} else
V_88 = V_94 -> V_88 ;
switch ( V_88 -> type ) {
case V_42 :
V_12 = V_88 -> V_12 . V_12 ;
break;
case V_90 :
V_89 = F_29 ( V_88 -> V_91 . V_92 ) ;
V_12 = V_88 -> V_91 . V_93 ;
break;
default:
fprintf ( V_3 , L_77 , V_88 -> type ) ;
break;
}
V_94 -> V_89 = V_89 ;
V_94 -> V_101 = V_12 ;
V_94 = V_94 -> V_9 ;
}
}
static void
F_31 ( T_9 * V_102 , struct V_24 * V_93 )
{
F_13 ( V_93 -> V_103 || V_102 == NULL ) ;
V_93 -> V_103 = 1 ;
F_32 ( V_102 , L_78 , V_93 -> V_12 ) ;
}
static void
F_33 ( T_9 * V_102 , T_5 * V_32 )
{
int V_57 = - 1 ;
int V_104 = - 1 ;
const char * V_105 ;
if ( V_32 -> V_57 && ! F_21 ( V_32 -> V_57 , & V_57 ) )
fprintf ( V_3 , L_79 , V_32 -> V_12 ) ;
if ( V_32 -> V_104 && ! F_21 ( V_32 -> V_104 , & V_104 ) )
fprintf ( V_3 , L_80 , V_32 -> V_12 ) ;
V_105 = F_24 ( V_32 , V_57 , V_104 ) ;
if ( V_105 )
F_32 ( V_102 , L_81 , V_105 ) ;
else
F_32 ( V_102 , L_82 , V_32 -> V_12 ) ;
}
static void
F_34 ( T_9 * V_102 , T_10 * V_32 )
{
F_32 ( V_102 , L_83 , V_32 -> V_12 ) ;
}
static struct V_4 *
F_35 ( T_9 * V_102 , T_4 * V_41 )
{
switch ( V_41 -> type ) {
case V_42 :
{
struct V_4 * V_7 = F_5 ( V_41 -> V_12 . V_12 , V_43 | V_106 | V_107 | V_108 | V_109 ) ;
if ( ! V_7 ) {
fprintf ( V_3 , L_8 , V_41 -> V_12 . V_12 ) ;
abort () ;
}
V_7 -> V_110 = 1 ;
if ( V_7 -> type == V_43 )
F_35 ( V_102 , V_7 -> V_14 ) ;
else if ( V_7 -> type == V_106 )
F_31 ( V_102 , V_7 -> V_14 ) ;
else if ( V_7 -> type == V_107 )
F_33 ( V_102 , V_7 -> V_14 ) ;
else if ( V_7 -> type == V_109 )
F_34 ( V_102 , V_7 -> V_14 ) ;
else if ( V_7 -> type == V_108 )
F_32 ( V_102 , L_81 , ( const char * ) V_7 -> V_14 ) ;
else {
fprintf ( V_3 , L_84 , V_7 -> V_12 , V_7 -> type ) ;
abort () ;
}
return V_7 ;
}
case V_46 :
F_32 ( V_102 , L_85 , V_41 -> V_47 . V_48 ) ;
return NULL ;
case V_56 :
F_32 ( V_102 , L_86 , V_41 -> V_10 . V_10 ) ;
return NULL ;
case V_49 :
F_32 ( V_102 , L_87 ) ;
F_32 ( V_102 , L_81 , F_26 ( V_41 -> V_50 . V_52 ) ) ;
F_35 ( V_102 , V_41 -> V_50 . V_51 ) ;
F_32 ( V_102 , L_88 ) ;
return NULL ;
case V_95 :
F_32 ( V_102 , L_87 ) ;
F_35 ( V_102 , V_41 -> V_96 . V_98 ) ;
F_32 ( V_102 , L_89 , F_27 ( V_41 -> V_96 . V_52 ) ) ;
F_35 ( V_102 , V_41 -> V_96 . V_100 ) ;
F_32 ( V_102 , L_88 ) ;
return NULL ;
case V_111 :
{
T_3 * V_112 ;
struct V_4 * V_7 ;
const char * V_113 = L_55 ;
V_7 = F_35 ( NULL , V_41 -> V_114 . V_115 ) ;
if ( ! V_7 ) {
fprintf ( V_3 , L_90 ) ;
abort () ;
}
F_35 ( V_102 , V_41 -> V_114 . V_115 ) ;
F_32 ( V_102 , L_87 ) ;
for ( V_112 = V_41 -> V_114 . args ; V_112 ; V_112 = V_112 -> V_9 ) {
F_32 ( V_102 , L_81 , V_113 ) ;
F_35 ( V_102 , V_112 -> V_88 ) ;
V_113 = L_91 ;
}
F_32 ( V_102 , L_88 ) ;
return NULL ;
}
case V_116 :
F_32 ( V_102 , L_92 ) ;
F_35 ( V_102 , V_41 -> V_40 . V_117 ) ;
F_32 ( V_102 , L_93 ) ;
F_35 ( V_102 , V_41 -> V_40 . V_118 ) ;
F_32 ( V_102 , L_94 ) ;
F_35 ( V_102 , V_41 -> V_40 . V_119 ) ;
F_32 ( V_102 , L_88 ) ;
return NULL ;
case V_90 :
{
struct V_4 * V_7 ;
V_7 = F_35 ( NULL , V_41 -> V_91 . V_92 ) ;
if ( ! V_7 ) {
fprintf ( V_3 , L_95 , V_41 -> V_91 . V_93 ) ;
abort () ;
}
if ( V_7 -> V_14 == & V_120 ) {
F_32 ( V_102 , L_96 , V_41 -> V_91 . V_93 ) ;
} else if ( V_7 -> V_14 == & V_121 ) {
F_32 ( V_102 , L_97 , V_41 -> V_91 . V_93 ) ;
} else if ( V_7 -> V_14 == & V_122 ) {
F_32 ( V_102 , L_98 , V_41 -> V_91 . V_93 ) ;
} else {
F_35 ( V_102 , V_41 -> V_91 . V_92 ) ;
F_32 ( V_102 , L_99 , V_41 -> V_91 . V_93 ) ;
}
return NULL ;
}
}
if ( V_41 == & V_123 )
F_32 ( V_102 , L_100 ) ;
else if ( V_41 == & V_124 )
F_32 ( V_102 , L_101 ) ;
else if ( V_41 == & V_125 )
F_32 ( V_102 , L_102 ) ;
else if ( V_41 == & V_120 || V_41 == & V_122 || V_41 == & V_121 )
{ }
else
fprintf ( V_3 , L_103 , V_41 -> type ) ;
return NULL ;
}
static enum V_126
F_36 ( T_9 * V_102 , T_10 * V_32 )
{
struct V_127 * V_40 ;
int V_128 = 1 ;
int V_129 = 1 ;
if ( V_32 -> V_130 . V_131 > 1 || ! V_32 -> V_132 )
return V_133 ;
for ( V_40 = V_32 -> V_134 ; V_40 ; V_40 = V_40 -> V_9 ) {
const char * V_10 ;
int V_45 ;
if ( ! V_40 -> V_135 || ! F_22 ( V_40 -> V_135 , & V_10 ) )
return 0 ;
if ( V_128 && ! F_21 ( & V_40 -> V_41 , & V_45 ) )
V_128 = 0 ;
if ( V_129 && ! F_22 ( & V_40 -> V_41 , & V_10 ) )
V_129 = 0 ;
if ( ! V_128 && ! V_129 )
return V_133 ;
}
if ( V_128 ) {
F_32 ( V_102 ,
L_104 ,
V_32 -> V_12 ) ;
if ( V_102 )
for ( V_40 = V_32 -> V_134 ; V_40 ; V_40 = V_40 -> V_9 ) {
const char * V_10 ;
int V_45 ;
if ( ! F_22 ( V_40 -> V_135 , & V_10 ) )
F_37 ( L_105 ) ;
if ( ! F_21 ( & V_40 -> V_41 , & V_45 ) )
F_37 ( L_106 ) ;
F_32 ( V_102 , L_107 , V_45 , V_10 ) ;
}
F_32 ( V_102 , L_108 ) ;
F_32 ( V_102 , L_109 ) ;
return V_136 ;
}
if ( V_129 ) {
F_32 ( V_102 ,
L_110 ,
V_32 -> V_12 ) ;
if ( V_102 )
for ( V_40 = V_32 -> V_134 ; V_40 ; V_40 = V_40 -> V_9 ) {
const char * V_10 ;
const char * V_45 ;
if ( ! F_22 ( V_40 -> V_135 , & V_10 ) )
F_37 ( L_105 ) ;
if ( ! F_22 ( & V_40 -> V_41 , & V_45 ) )
F_37 ( L_111 ) ;
F_32 ( V_102 , L_112 , V_45 , V_10 ) ;
}
F_32 ( V_102 , L_113 ) ;
F_32 ( V_102 , L_109 ) ;
return V_137 ;
}
return V_133 ;
}
static void
F_38 ( T_9 * V_102 , T_10 * V_32 )
{
struct V_127 * V_40 ;
if ( V_32 -> V_132 ) {
F_32 ( V_102 , L_114 ) ;
F_35 ( V_102 , V_32 -> V_132 ) ;
F_32 ( V_102 , L_115 ) ;
for ( V_40 = V_32 -> V_134 ; V_40 ; V_40 = V_40 -> V_9 ) {
V_138:
F_32 ( V_102 , L_116 ) ;
F_35 ( V_102 , & V_40 -> V_41 ) ;
F_32 ( V_102 , L_117 ) ;
if ( ! V_40 -> V_135 ) {
V_40 = V_40 -> V_9 ;
F_13 ( V_40 != NULL ) ;
F_32 ( V_102 , L_118 ) ;
goto V_138;
} else {
F_32 ( V_102 , L_118 ) ;
F_32 ( V_102 , L_119 ) ;
F_35 ( V_102 , V_40 -> V_135 ) ;
F_32 ( V_102 , L_120 ) ;
}
}
F_32 ( V_102 , L_121 ) ;
} else {
for ( V_40 = V_32 -> V_134 ; V_40 ; V_40 = V_40 -> V_9 ) {
if ( V_40 == V_32 -> V_134 )
F_32 ( V_102 , L_122 ) ;
else
F_32 ( V_102 , L_123 ) ;
V_139:
F_32 ( V_102 , L_87 ) ;
F_35 ( V_102 , & V_40 -> V_41 ) ;
F_32 ( V_102 , L_88 ) ;
if ( ! V_40 -> V_135 ) {
F_32 ( V_102 , L_124 ) ;
V_40 = V_40 -> V_9 ;
F_13 ( V_40 != NULL ) ;
goto V_139;
} else {
F_32 ( V_102 , L_125 ) ;
F_32 ( V_102 , L_126 ) ;
F_35 ( V_102 , V_40 -> V_135 ) ;
F_32 ( V_102 , L_120 ) ;
}
}
}
}
static void
F_39 ( T_10 * V_32 )
{
if ( ! V_32 -> V_7 )
V_32 -> V_7 = F_6 ( V_32 -> V_12 , V_109 , V_32 ) ;
}
static void
F_40 ( T_9 * V_102 , T_10 * V_32 )
{
struct V_4 * V_140 ;
const char * V_141 ;
enum V_126 type ;
V_32 -> V_7 -> V_142 = 1 ;
F_32 ( V_102 ,
L_127
L_128 , V_32 -> V_12 ) ;
V_140 = F_2 () ;
F_32 ( V_102 , L_87 ) ;
if ( V_32 -> V_130 . V_131 ) {
int V_31 ;
for ( V_31 = 0 ; V_31 < V_32 -> V_130 . V_131 ; V_31 ++ ) {
if ( V_31 )
F_32 ( V_102 , L_91 ) ;
F_32 ( V_102 , L_129 , V_32 -> V_130 . args [ V_31 ] ) ;
F_6 ( V_32 -> V_130 . args [ V_31 ] , V_108 , V_32 -> V_130 . args [ V_31 ] ) ;
}
V_141 = V_32 -> V_130 . args [ 0 ] ;
} else {
F_32 ( V_102 , L_130 ) ;
F_6 ( L_131 , V_108 , L_131 ) ;
V_141 = L_131 ;
}
F_32 ( V_102 , L_132 ) ;
type = F_36 ( V_102 , V_32 ) ;
switch ( type ) {
case V_136 :
F_32 ( V_102 , L_118 ) ;
F_32 ( V_102 , L_133 , V_32 -> V_12 , V_141 ) ;
F_32 ( V_102 , L_134 ) ;
break;
case V_137 :
F_32 ( V_102 , L_135 , V_32 -> V_12 , V_141 ) ;
F_32 ( V_102 , L_134 ) ;
break;
case V_133 :
default:
F_38 ( V_102 , V_32 ) ;
break;
}
if ( V_32 -> V_143 ) {
F_32 ( V_102 , L_136 ) ;
F_35 ( V_102 , V_32 -> V_143 ) ;
F_32 ( V_102 , L_120 ) ;
} else
F_32 ( V_102 , L_137 ) ;
F_32 ( V_102 , L_138 ) ;
F_3 ( V_140 ) ;
}
static void
F_41 ( T_9 * V_102 , struct V_24 * V_93 , T_11 * V_144 )
{
F_32 ( V_102 , L_139 , V_144 -> V_12 ) ;
V_93 -> V_145 = - 1 ;
}
static void
F_42 ( T_9 * V_102 , struct V_24 * V_93 , T_1 * V_8 )
{
F_32 ( V_102 , L_140 , V_8 -> V_146 , F_12 ( V_93 -> V_35 ) ) ;
V_93 -> V_35 -> V_38 = L_6 ;
V_93 -> V_145 = - 1 ;
}
static void
F_43 ( T_9 * V_102 , struct V_4 * V_147 , int V_57 )
{
if ( V_147 ) {
if ( V_147 -> type == V_106 ) {
F_32 ( V_102 , L_78 , V_147 -> V_12 ) ;
} else if ( V_147 -> type == V_43 ) {
F_32 ( V_102 , L_87 ) ;
F_35 ( V_102 , V_147 -> V_14 ) ;
F_32 ( V_102 , L_141 ) ;
} else if ( V_147 -> type == V_108 ) {
F_32 ( V_102 , L_142 , ( const char * ) V_147 -> V_14 ) ;
} else {
fprintf ( V_3 , L_143 , V_147 -> V_12 , V_147 -> type ) ;
F_32 ( V_102 , L_144 , V_147 -> V_12 ) ;
}
} else {
F_32 ( V_102 , L_145 , V_57 ) ;
}
}
static void
F_44 ( T_9 * V_102 , struct V_24 * V_93 , T_5 * V_32 )
{
struct V_4 * V_140 ;
int V_31 ;
int V_57 = - 1 ;
struct V_4 * V_148 = NULL ;
int V_104 = - 1 ;
T_4 * V_149 ;
struct V_4 * V_150 = NULL ;
T_4 * V_151 ;
const char * V_38 ;
T_3 * V_152 = V_93 -> V_130 ;
int V_153 = F_19 ( V_152 ) ;
if ( V_32 -> V_130 . V_131 != V_153 ) {
fprintf ( V_3 , L_146 , V_32 -> V_12 , V_32 -> V_130 . V_131 , V_153 ) ;
abort () ;
}
V_140 = F_2 () ;
for ( V_31 = 0 ; V_31 < V_153 ; V_31 ++ ) {
F_6 ( V_32 -> V_130 . args [ V_31 ] , V_43 , V_152 -> V_88 ) ;
V_152 = V_152 -> V_9 ;
}
F_13 ( V_32 -> V_57 != NULL ) ;
if ( ! F_21 ( V_32 -> V_57 , & V_57 ) ) {
V_148 = F_20 ( V_32 -> V_57 ) ;
if ( ! V_148 ) {
fprintf ( V_3 , L_147 , V_32 -> V_12 ) ;
abort () ;
}
}
if ( V_93 -> V_154 )
V_149 = V_93 -> V_154 ;
else if ( V_32 -> V_104 )
V_149 = V_32 -> V_104 ;
else
V_149 = NULL ;
if ( V_93 -> V_155 )
V_151 = V_93 -> V_155 ;
else
V_151 = V_32 -> V_151 ;
if ( V_149 ) {
if ( ! F_21 ( V_149 , & V_104 ) ) {
V_150 = F_20 ( V_149 ) ;
if ( ! V_150 ) {
fprintf ( V_3 , L_148 , V_32 -> V_12 ) ;
abort () ;
}
}
}
if ( V_93 -> V_103 ) {
const char * V_156 = F_23 ( V_32 , V_57 ) ;
const char * V_105 = F_24 ( V_32 , V_57 , V_104 ) ;
F_32 ( V_102 , L_149 , V_156 , V_93 -> V_12 , V_105 ) ;
}
if ( V_148 ) {
if ( V_148 -> type == V_106 ) {
struct V_24 * V_157 = V_148 -> V_14 ;
F_13 ( V_157 -> V_103 || V_102 == NULL ) ;
V_157 -> V_103 = 1 ;
} else
fprintf ( V_3 , L_143 , V_148 -> V_12 , V_148 -> type ) ;
V_38 = NULL ;
} else
V_38 = F_25 ( V_32 , V_57 ) ;
V_93 -> V_35 -> V_38 = V_38 ;
V_93 -> V_145 = V_57 ;
#if 0
if (display_format)
fprintf(stderr, "XXX, format\n");
else
#endif
F_32 ( V_102 , L_150 , F_12 ( V_93 -> V_35 ) ) ;
F_43 ( V_102 , V_148 , V_57 ) ;
F_32 ( V_102 , L_151 ,
( V_104 == V_63 ) ? L_152 :
( V_104 == V_64 ) ? L_153 :
L_154 ) ;
F_32 ( V_102 , L_155 ) ;
F_43 ( V_102 , V_148 , V_57 ) ;
F_32 ( V_102 , L_120 ) ;
F_3 ( V_140 ) ;
}
static void
F_45 ( T_9 * V_102 , struct V_25 * V_26 , struct V_24 * V_93 , T_8 * V_158 )
{
struct V_4 * V_7 ;
const char * V_159 = NULL ;
int V_160 = 0 ;
V_7 = F_5 ( V_93 -> V_161 , V_162 | V_163 | V_107 ) ;
if ( ! V_7 ) {
fprintf ( V_3 , L_156 , V_93 -> V_161 ) ;
abort () ;
}
V_7 -> V_110 = 1 ;
if ( ! V_93 -> V_35 && V_7 -> type != V_163 ) {
V_93 -> V_35 = F_10 ( V_93 , V_26 ) ;
F_13 ( V_102 == NULL ) ;
}
F_6 ( V_93 -> V_12 , V_106 , V_93 ) ;
V_93 -> V_154 = V_26 -> V_104 ;
while ( V_158 ) {
const char * V_164 = V_158 -> V_101 ;
T_4 * V_165 = V_158 -> V_99 ;
int V_166 = V_158 -> V_89 ;
if ( V_164 ) {
if ( ! strcasecmp ( V_164 , L_157 ) ) {
F_13 ( V_166 == 0 ) ;
F_13 ( V_165 != NULL ) ;
V_93 -> V_154 = V_165 ;
} else if ( V_165 ) {
if ( V_166 & V_84 ) {
F_32 ( V_102 , L_158 , V_164 ) ;
F_35 ( V_102 , V_165 ) ;
F_32 ( V_102 , L_120 ) ;
} else {
F_32 ( V_102 , L_159 , V_166 , V_164 ) ;
F_35 ( V_102 , V_165 ) ;
F_32 ( V_102 , L_160 ) ;
}
} else {
F_13 ( V_159 == NULL ) ;
V_159 = V_164 ;
V_160 = V_166 ;
V_93 -> V_103 = 1 ;
}
} else
fprintf ( V_3 , L_161 ) ;
V_158 = V_158 -> V_9 ;
}
if ( V_7 -> type == V_162 )
F_42 ( V_102 , V_93 , V_7 -> V_14 ) ;
else if ( V_7 -> type == V_107 )
F_44 ( V_102 , V_93 , V_7 -> V_14 ) ;
else if ( V_7 -> type == V_163 )
F_41 ( V_102 , V_93 , V_7 -> V_14 ) ;
else {
fprintf ( V_3 , L_162 , V_7 -> V_12 , V_7 -> type ) ;
abort () ;
}
if ( V_159 ) {
F_32 ( V_102 , L_163 , V_160 , V_159 , V_93 -> V_12 ) ;
}
}
static void
F_46 ( T_9 * V_102 , struct V_25 * V_26 , T_12 * V_18 )
{
F_30 ( V_18 -> V_158 ) ;
switch ( V_18 -> type ) {
case V_167 :
F_32 ( V_102 , L_164 ) ;
F_35 ( V_102 , & V_18 -> V_168 . V_88 ) ;
F_32 ( V_102 , L_115 ) ;
V_26 -> V_169 = - 1 ;
F_47 ( V_102 , V_26 , V_18 -> V_168 . V_170 ) ;
F_32 ( V_102 , L_121 ) ;
return;
case V_171 :
V_26 -> V_169 = - 1 ;
F_48 ( NULL , & V_18 -> V_8 . V_14 , NULL ) ;
F_32 ( V_102 , L_165 , V_18 -> V_8 . V_14 . V_146 ) ;
return;
case V_172 :
F_45 ( V_102 , V_26 , & V_18 -> V_102 , V_18 -> V_158 ) ;
if ( V_26 -> V_169 != - 1 ) {
if ( V_18 -> V_102 . V_145 != - 1 )
V_26 -> V_169 += V_18 -> V_102 . V_145 ;
else
V_26 -> V_169 = - 1 ;
}
return;
case V_173 :
{
struct V_174 * V_40 = V_18 -> V_175 . V_14 . V_134 ;
V_26 -> V_169 = - 1 ;
if ( V_18 -> V_175 . V_14 . V_132 ) {
F_32 ( V_102 , L_114 ) ;
F_35 ( V_102 , V_18 -> V_175 . V_14 . V_132 ) ;
F_32 ( V_102 , L_115 ) ;
while ( V_40 ) {
F_32 ( V_102 , L_116 ) ;
F_35 ( V_102 , & V_40 -> V_41 ) ;
F_32 ( V_102 , L_166 ) ;
if ( V_40 -> V_18 ) {
F_32 ( V_102 , L_167 ) ;
F_46 ( V_102 , V_26 , V_40 -> V_18 ) ;
F_32 ( V_102 , L_168 ) ;
}
V_40 = V_40 -> V_9 ;
}
if ( V_18 -> V_175 . V_14 . V_176 ) {
F_32 ( V_102 , L_169 ) ;
F_32 ( V_102 , L_167 ) ;
F_46 ( V_102 , V_26 , V_18 -> V_175 . V_14 . V_176 ) ;
}
F_32 ( V_102 , L_121 ) ;
return;
}
if ( V_40 ) {
T_12 * V_176 = V_18 -> V_175 . V_14 . V_176 ;
F_32 ( V_102 , L_170 ) ;
while ( V_40 ) {
T_12 * V_177 ;
F_32 ( V_102 , L_171 ) ;
F_32 ( V_102 , L_87 ) ;
F_35 ( V_102 , & V_40 -> V_41 ) ;
F_32 ( V_102 , L_88 ) ;
V_177 = V_40 -> V_18 ;
V_40 = V_40 -> V_9 ;
while ( V_40 && ! V_177 ) {
V_177 = V_40 -> V_18 ;
F_32 ( V_102 , L_124 ) ;
F_32 ( V_102 , L_87 ) ;
F_35 ( V_102 , & V_40 -> V_41 ) ;
F_32 ( V_102 , L_88 ) ;
V_40 = V_40 -> V_9 ;
}
if ( ! V_177 ) {
F_32 ( V_102 , L_172 ) ;
V_177 = V_176 ;
V_176 = NULL ;
}
F_32 ( V_102 , L_115 ) ;
F_32 ( V_102 , L_170 ) ;
F_46 ( V_102 , V_26 , V_177 ) ;
F_32 ( V_102 , L_173 ) ;
if ( V_40 || V_176 )
F_32 ( V_102 , L_174 ) ;
}
if ( V_176 ) {
F_32 ( V_102 , L_175 ) ;
F_32 ( V_102 , L_170 ) ;
F_46 ( V_102 , V_26 , V_176 ) ;
F_32 ( V_102 , L_121 ) ;
}
} else {
if ( V_18 -> V_175 . V_14 . V_176 )
F_46 ( V_102 , V_26 , V_18 -> V_175 . V_14 . V_176 ) ;
}
return;
}
}
fprintf ( V_3 , L_176 , V_18 -> type ) ;
}
static void
F_47 ( T_9 * V_102 , struct V_25 * V_26 , struct V_178 * V_170 )
{
struct V_4 * V_140 ;
V_140 = F_2 () ;
while ( V_170 ) {
F_46 ( V_102 , V_26 , & V_170 -> V_18 ) ;
V_170 = V_170 -> V_9 ;
}
F_3 ( V_140 ) ;
}
static void
F_49 ( T_11 * V_144 )
{
if ( ! V_144 -> V_7 )
V_144 -> V_7 = F_6 ( V_144 -> V_12 , V_163 , V_144 ) ;
}
static void
F_50 ( T_9 * V_102 , T_11 * V_144 , T_8 * V_158 )
{
struct V_25 V_179 ;
T_4 * V_154 = NULL ;
V_144 -> V_7 -> V_142 = 1 ;
F_32 ( V_102 ,
L_177
L_178 , V_144 -> V_12 ) ;
F_13 ( V_144 -> V_130 . V_131 == 0 ) ;
F_32 ( V_102 , L_175 ) ;
F_32 ( V_102 ,
L_179
L_180
L_181
L_118
) ;
F_30 ( V_158 ) ;
while ( V_158 ) {
const char * V_164 = V_158 -> V_101 ;
T_4 * V_165 = V_158 -> V_99 ;
int V_89 = V_158 -> V_89 ;
if ( V_164 ) {
if ( ! strcasecmp ( V_164 , L_182 ) ) {
F_13 ( V_89 == 0 ) ;
F_13 ( V_165 != NULL ) ;
V_154 = V_165 ;
} else
fprintf ( V_3 , L_183 , V_164 ) ;
} else
fprintf ( V_3 , L_184 ) ;
V_158 = V_158 -> V_9 ;
}
F_32 ( V_102 , L_185 ) ;
if ( V_144 -> V_155 ) {
F_32 ( V_102 , L_186 , V_144 -> V_12 ) ;
F_32 ( V_102 , L_187 ) ;
F_35 ( V_3 , V_144 -> V_155 ) ;
F_32 ( V_102 , L_188 ) ;
} else
F_32 ( V_102 , L_189 , V_144 -> V_12 ) ;
F_32 ( V_102 , L_190 , V_144 -> V_12 ) ;
F_32 ( V_102 , L_121 ) ;
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
V_179 . V_12 = V_144 -> V_12 ;
V_179 . V_12 = NULL ;
V_179 . V_104 = V_154 ;
F_47 ( V_102 , & V_179 , V_144 -> V_170 ) ;
F_32 ( V_102 , L_191 ) ;
F_32 ( V_102 , L_192 ) ;
F_32 ( V_102 , L_193 ) ;
F_32 ( V_102 , L_118 ) ;
}
static void
F_51 ( T_1 * V_8 )
{
if ( ! V_8 -> V_7 && V_8 -> V_12 ) {
V_8 -> V_146 = V_8 -> V_12 ;
V_8 -> V_7 = F_6 ( V_8 -> V_12 , V_162 , V_8 ) ;
}
}
static void
F_48 ( T_9 * V_102 , T_1 * V_8 , T_8 * V_158 )
{
const char * V_12 = V_8 -> V_146 ;
struct V_25 V_179 ;
if ( ! V_12 )
V_12 = V_8 -> V_146 = V_8 -> V_12 ;
if ( ! V_12 ) {
static unsigned int V_180 = 0 ;
char V_181 [ 32 ] ;
snprintf ( V_181 , sizeof( V_181 ) , L_194 , ++ V_180 ) ;
V_12 = V_8 -> V_146 = F_52 ( V_181 ) ;
F_13 ( V_102 == NULL ) ;
}
if ( V_8 -> V_182 ) {
fprintf ( V_3 , L_195 ) ;
}
if ( V_8 -> V_7 )
V_8 -> V_7 -> V_142 = 1 ;
F_32 ( V_102 ,
L_177
L_196
L_175 , V_12 , V_8 -> V_183 ? L_197 : L_55 ) ;
if ( ! V_8 -> V_183 ) {
F_32 ( V_102 , L_198 ) ;
F_32 ( V_102 , L_180 ) ;
F_32 ( V_102 , L_181 ) ;
} else
F_32 ( V_102 , L_199 ) ;
F_32 ( V_102 , L_118 ) ;
F_30 ( V_158 ) ;
while ( V_158 ) {
const char * V_164 = V_158 -> V_101 ;
if ( V_164 ) {
fprintf ( V_3 , L_200 , V_164 ) ;
} else
fprintf ( V_3 , L_201 ) ;
V_158 = V_158 -> V_9 ;
}
if ( ! V_8 -> V_183 ) {
if ( ! V_8 -> V_21 )
V_8 -> V_21 = F_8 ( V_8 ) ;
F_32 ( V_102 ,
L_185
L_202
L_203
L_121 , V_8 -> V_184 , L_55 , F_9 ( V_8 -> V_21 ) ) ;
} else {
if ( V_8 -> V_155 )
fprintf ( V_3 , L_204 ) ;
}
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
V_179 . V_12 = V_8 -> V_12 ;
F_47 ( V_102 , & V_179 , V_8 -> V_170 ) ;
V_8 -> V_184 = V_179 . V_169 ;
if ( V_8 -> V_184 != - 1 ) {
}
if ( ! V_8 -> V_183 && V_8 -> V_184 == - 1 )
F_32 ( V_102 , L_205 ) ;
if ( V_8 -> V_184 == - 1 )
V_8 -> V_184 = 0 ;
F_32 ( V_102 , L_192 ) ;
F_32 ( V_102 , L_193 ) ;
F_32 ( V_102 , L_118 ) ;
}
static void
F_53 ( T_13 * V_40 )
{
if ( ! V_40 -> V_7 )
V_40 -> V_7 = F_6 ( V_40 -> V_12 , V_43 , & V_40 -> V_88 ) ;
}
static void
F_54 ( T_5 * V_32 )
{
if ( ! V_32 -> V_7 )
V_32 -> V_7 = F_6 ( V_32 -> V_12 , V_107 , V_32 ) ;
}
static void
F_55 ( T_9 * V_102 , T_14 * V_185 , int V_186 )
{
switch ( V_185 -> type ) {
case V_187 :
F_51 ( & V_185 -> V_8 . V_14 ) ;
if ( ! V_186 )
return;
F_48 ( V_102 , & V_185 -> V_8 . V_14 , V_185 -> V_158 ) ;
return;
case V_188 :
F_13 ( V_185 -> V_158 == NULL ) ;
F_39 ( & V_185 -> V_32 . V_14 ) ;
if ( ! V_186 )
return;
F_40 ( V_102 , & V_185 -> V_32 . V_14 ) ;
return;
case V_189 :
F_49 ( & V_185 -> V_144 . V_14 ) ;
if ( ! V_186 )
return;
F_50 ( V_102 , & V_185 -> V_144 . V_14 , V_185 -> V_158 ) ;
return;
case V_190 :
F_13 ( V_185 -> V_158 == NULL ) ;
F_53 ( & V_185 -> V_40 . V_14 ) ;
if ( ! V_186 )
return;
return;
case V_191 :
F_13 ( V_185 -> V_158 == NULL ) ;
F_54 ( & V_185 -> V_192 . V_14 ) ;
if ( ! V_186 )
return;
return;
case V_193 :
F_13 ( V_185 -> V_158 == NULL ) ;
return;
}
fprintf ( V_3 , L_206 , V_185 -> type ) ;
}
static void
F_56 ( T_9 * V_102 , T_15 * V_40 , int V_186 )
{
struct V_194 * V_195 ;
for ( V_195 = V_40 -> V_196 ; V_195 ; V_195 = V_195 -> V_9 )
F_55 ( V_102 , & V_195 -> V_185 , 0 ) ;
if ( ! V_186 )
return;
for ( V_195 = V_40 -> V_196 ; V_195 ; V_195 = V_195 -> V_9 )
F_55 ( V_102 , & V_195 -> V_185 , V_186 ) ;
}
static void
F_57 ( T_15 * V_40 )
{
struct V_194 * V_195 ;
for ( V_195 = V_40 -> V_196 ; V_195 ; V_195 = V_195 -> V_9 ) {
if ( V_195 -> V_185 . type == V_193 ) {
const char * V_197 = V_195 -> V_185 . V_31 . V_1 ;
T_9 * V_102 ;
T_15 V_198 ;
int V_199 ;
if ( ! ( V_102 = fopen ( V_197 , L_207 ) ) ) {
fprintf ( V_3 , L_208 , V_197 ) ;
abort () ;
}
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_199 = F_58 ( & V_198 , V_102 , V_197 ) ;
fclose ( V_102 ) ;
if ( ! V_199 ) {
fprintf ( V_3 , L_209 , V_197 ) ;
abort () ;
}
F_57 ( & V_198 ) ;
F_56 ( NULL , & V_198 , 0 ) ;
}
}
}
static void
F_59 ( T_9 * V_102 )
{
struct V_23 * V_35 ;
struct V_17 * V_21 ;
for ( V_35 = V_27 ; V_35 ; V_35 = V_35 -> V_9 )
F_32 ( V_102 , L_210 , F_12 ( V_35 ) ) ;
F_32 ( V_102 , L_118 ) ;
for ( V_21 = V_20 ; V_21 ; V_21 = V_21 -> V_9 )
F_32 ( V_102 , L_210 , F_9 ( V_21 ) ) ;
F_32 ( V_102 , L_118 ) ;
}
static void
F_60 ( T_9 * V_102 , const char * V_200 )
{
struct V_23 * V_35 ;
struct V_17 * V_21 ;
F_32 ( V_102 ,
L_211
L_212
L_175 , V_200 ) ;
F_32 ( V_102 , L_213 ) ;
for ( V_35 = V_27 ; V_35 ; V_35 = V_35 -> V_9 ) {
F_32 ( V_102 ,
L_214
L_215
L_216 , F_12 ( V_35 ) , F_14 ( V_35 ) , V_200 , F_15 ( V_35 ) , F_16 ( V_35 ) , F_17 ( V_35 ) , F_18 ( V_35 ) ) ;
}
F_32 ( V_102 , L_217 ) ;
F_32 ( V_102 , L_218 ) ;
for ( V_21 = V_20 ; V_21 ; V_21 = V_21 -> V_9 )
F_32 ( V_102 , L_219 , F_9 ( V_21 ) ) ;
F_32 ( V_102 , L_217 ) ;
F_32 ( V_102 , L_220 , V_200 , V_200 , V_200 , V_200 ) ;
F_32 ( V_102 , L_221 , V_200 ) ;
F_32 ( V_102 , L_222 ) ;
F_32 ( V_102 , L_138 ) ;
}
static void
F_61 ( T_9 * V_102 , const char * V_200 )
{
F_32 ( V_102 ,
L_211
L_223
L_175 , V_200 ) ;
F_32 ( V_102 , L_224 , V_200 , V_200 , V_200 ) ;
#if 0
dissector_add_uint("REG", XXX, %s_handle);
xml_handle = find_dissector("xml");
#endif
F_32 ( V_102 , L_138 ) ;
}
static const T_11 *
F_62 ( T_15 * V_201 )
{
struct V_194 * V_195 ;
for ( V_195 = V_201 -> V_196 ; V_195 ; V_195 = V_195 -> V_9 ) {
if ( V_195 -> V_185 . type == V_189 )
return & V_195 -> V_185 . V_144 . V_14 ;
}
return NULL ;
}
static void
F_63 ( T_15 * V_201 , T_15 * V_202 )
{
struct V_194 * * V_144 = & V_201 -> V_196 ;
while ( * V_144 )
V_144 = & ( * V_144 ) -> V_9 ;
* V_144 = V_202 -> V_196 ;
}
static void
F_64 ( T_15 * V_201 )
{
F_57 ( V_201 ) ;
F_56 ( NULL , V_201 , 1 ) ;
}
static void
F_65 ( T_15 * V_201 )
{
const T_11 * V_203 = F_62 ( V_201 ) ;
const char * V_200 = ( V_203 ) ? V_203 -> V_12 : L_225 ;
T_9 * V_204 ;
struct V_4 * V_7 ;
V_204 = fopen ( L_226 , L_227 ) ;
F_32 ( V_204 , L_228 ) ;
F_32 ( V_204 , L_229 ) ;
F_32 ( V_204 , L_230 ) ;
F_32 ( V_204 , L_118 ) ;
for ( V_7 = V_6 ; V_7 ; V_7 = V_7 -> V_9 ) {
const char * V_205 = ( V_7 -> V_142 ) ? L_231 : L_55 ;
if ( ! V_7 -> V_110 )
continue;
switch ( V_7 -> type ) {
case V_109 :
F_32 ( V_204 , L_232 , V_205 , V_7 -> V_12 ) ;
break;
case V_162 :
F_32 ( V_204 , L_233 , V_205 , V_7 -> V_12 ) ;
break;
case V_163 :
F_32 ( V_204 , L_234 , V_205 , V_7 -> V_12 ) ;
break;
}
}
F_32 ( V_204 , L_118 ) ;
F_32 ( V_204 , L_235 , V_200 ) ;
F_32 ( V_204 , L_236 , V_200 ) ;
F_59 ( V_204 ) ;
F_56 ( V_204 , V_201 , 1 ) ;
F_60 ( V_204 , V_200 ) ;
F_61 ( V_204 , V_200 ) ;
fclose ( V_204 ) ;
}
int main ( int V_153 , char * * V_152 ) {
T_9 * V_102 ;
T_15 V_201 ;
int V_31 ;
if ( V_153 < 2 ) {
fprintf ( V_3 , L_237 , V_152 [ 0 ] ) ;
return 1 ;
}
F_6 ( L_238 , V_108 , L_239 ) ;
F_6 ( L_240 , V_108 , L_241 ) ;
F_6 ( L_242 , V_43 , & V_123 ) ;
F_6 ( L_243 , V_43 , & V_124 ) ;
F_6 ( L_244 , V_43 , & V_125 ) ;
F_6 ( L_245 , V_43 , & V_120 ) ;
F_6 ( L_71 , V_43 , & V_122 ) ;
F_6 ( L_246 , V_43 , & V_121 ) ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
for ( V_31 = 1 ; V_31 < V_153 ; V_31 ++ ) {
T_15 V_206 ;
int V_199 ;
if ( ! ( V_102 = fopen ( V_152 [ V_31 ] , L_207 ) ) ) {
fprintf ( V_3 , L_208 , V_152 [ V_31 ] ) ;
continue;
return 1 ;
}
memset ( & V_206 , 0 , sizeof( V_206 ) ) ;
V_199 = F_58 ( & V_206 , V_102 , V_152 [ V_31 ] ) ;
fclose ( V_102 ) ;
if ( ! V_199 ) {
fprintf ( V_3 , L_247 , V_152 [ V_31 ] ) ;
return 1 ;
}
F_63 ( & V_201 , & V_206 ) ;
}
F_64 ( & V_201 ) ;
F_65 ( & V_201 ) ;
return 0 ;
}
