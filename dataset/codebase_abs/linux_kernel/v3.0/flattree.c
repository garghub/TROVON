static void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
* V_4 = F_2 ( * V_4 , V_2 ) ;
}
static void F_3 ( void * V_1 , char * V_5 , int V_6 )
{
struct V_3 * V_4 = V_1 ;
if ( V_6 == 0 )
V_6 = strlen ( V_5 ) ;
* V_4 = F_4 ( * V_4 , V_5 , V_6 ) ;
* V_4 = F_5 ( * V_4 , '\0' ) ;
}
static void F_6 ( void * V_1 , int V_7 )
{
struct V_3 * V_4 = V_1 ;
* V_4 = F_7 ( * V_4 , V_7 ) ;
}
static void F_8 ( void * V_1 , struct V_3 V_8 )
{
struct V_3 * V_4 = V_1 ;
* V_4 = F_4 ( * V_4 , V_8 . V_2 , V_8 . V_6 ) ;
}
static void F_9 ( void * V_1 , struct V_9 * V_10 )
{
F_1 ( V_1 , V_11 ) ;
}
static void F_10 ( void * V_1 , struct V_9 * V_10 )
{
F_1 ( V_1 , V_12 ) ;
}
static void F_11 ( void * V_1 , struct V_9 * V_10 )
{
F_1 ( V_1 , V_13 ) ;
}
static void F_12 ( T_2 * V_14 , const char * V_15 , const char * V_9 )
{
fprintf ( V_14 , L_1 , V_15 , V_9 ) ;
fprintf ( V_14 , L_2 , V_15 , V_9 ) ;
fprintf ( V_14 , L_3 , V_15 , V_9 ) ;
}
static void F_13 ( T_2 * V_14 , const char * V_9 , int V_16 )
{
fprintf ( V_14 , L_4 , V_9 ) ;
fprintf ( V_14 , L_5 , V_9 , V_16 ) ;
}
static void F_14 ( void * V_1 , T_1 V_2 )
{
T_2 * V_14 = V_1 ;
fprintf ( V_14 , L_6 ,
( V_2 >> 24 ) & 0xff , ( V_2 >> 16 ) & 0xff ,
( V_2 >> 8 ) & 0xff , V_2 & 0xff ) ;
}
static void F_15 ( void * V_1 , char * V_5 , int V_6 )
{
T_2 * V_14 = V_1 ;
char V_17 = 0 ;
if ( V_6 != 0 ) {
V_17 = V_5 [ V_6 ] ;
V_5 [ V_6 ] = '\0' ;
}
fprintf ( V_14 , L_7 , V_5 ) ;
if ( V_6 != 0 ) {
V_5 [ V_6 ] = V_17 ;
}
}
static void F_16 ( void * V_1 , int V_7 )
{
T_2 * V_14 = V_1 ;
fprintf ( V_14 , L_8 , V_7 ) ;
}
static void F_17 ( void * V_1 , struct V_3 V_8 )
{
T_2 * V_14 = V_1 ;
int V_18 = 0 ;
struct V_19 * V_20 = V_8 . V_21 ;
F_18 (m, LABEL)
F_13 ( V_14 , V_20 -> V_22 , V_20 -> V_16 ) ;
while ( ( V_8 . V_6 - V_18 ) >= sizeof( V_23 ) ) {
F_14 ( V_1 , F_19 ( * ( ( V_23 * ) ( V_8 . V_2 + V_18 ) ) ) ) ;
V_18 += sizeof( V_23 ) ;
}
while ( ( V_8 . V_6 - V_18 ) >= 1 ) {
fprintf ( V_14 , L_9 , V_8 . V_2 [ V_18 ] ) ;
V_18 += 1 ;
}
assert ( V_18 == V_8 . V_6 ) ;
}
static void F_20 ( void * V_1 , struct V_9 * V_10 )
{
T_2 * V_14 = V_1 ;
struct V_9 * V_24 ;
F_21 (labels, l) {
fprintf ( V_14 , L_4 , V_24 -> V_9 ) ;
fprintf ( V_14 , L_10 , V_24 -> V_9 ) ;
}
fprintf ( V_14 , L_11 ) ;
F_14 ( V_1 , V_11 ) ;
}
static void F_22 ( void * V_1 , struct V_9 * V_10 )
{
T_2 * V_14 = V_1 ;
struct V_9 * V_24 ;
fprintf ( V_14 , L_12 ) ;
F_14 ( V_1 , V_12 ) ;
F_21 (labels, l) {
fprintf ( V_14 , L_13 , V_24 -> V_9 ) ;
fprintf ( V_14 , L_14 , V_24 -> V_9 ) ;
}
}
static void F_23 ( void * V_1 , struct V_9 * V_10 )
{
T_2 * V_14 = V_1 ;
struct V_9 * V_24 ;
F_21 (labels, l) {
fprintf ( V_14 , L_4 , V_24 -> V_9 ) ;
fprintf ( V_14 , L_10 , V_24 -> V_9 ) ;
}
fprintf ( V_14 , L_15 ) ;
F_14 ( V_1 , V_13 ) ;
}
static int F_24 ( struct V_3 * V_8 , const char * V_5 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_8 -> V_6 ; V_25 ++ ) {
if ( F_25 ( V_5 , V_8 -> V_2 + V_25 ) )
return V_25 ;
}
* V_8 = F_4 ( * V_8 , V_5 , strlen ( V_5 ) + 1 ) ;
return V_25 ;
}
static void F_26 ( struct V_26 * V_27 , struct V_28 * V_29 ,
void * V_30 , struct V_3 * V_31 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 ;
struct V_26 * V_36 ;
int V_37 = 0 ;
V_29 -> V_38 ( V_30 , V_27 -> V_10 ) ;
if ( V_33 -> V_39 & V_40 )
V_29 -> string ( V_30 , V_27 -> V_41 , 0 ) ;
else
V_29 -> string ( V_30 , V_27 -> V_42 , 0 ) ;
V_29 -> V_43 ( V_30 , sizeof( T_1 ) ) ;
F_27 (tree, prop) {
int V_44 ;
if ( F_25 ( V_35 -> V_42 , L_16 ) )
V_37 = 1 ;
V_44 = F_24 ( V_31 , V_35 -> V_42 ) ;
V_29 -> V_34 ( V_30 , V_35 -> V_10 ) ;
V_29 -> V_45 ( V_30 , V_35 -> V_2 . V_6 ) ;
V_29 -> V_45 ( V_30 , V_44 ) ;
if ( ( V_33 -> V_39 & V_46 ) && ( V_35 -> V_2 . V_6 >= 8 ) )
V_29 -> V_43 ( V_30 , 8 ) ;
V_29 -> V_3 ( V_30 , V_35 -> V_2 ) ;
V_29 -> V_43 ( V_30 , sizeof( T_1 ) ) ;
}
if ( ( V_33 -> V_39 & V_47 ) && ! V_37 ) {
V_29 -> V_34 ( V_30 , NULL ) ;
V_29 -> V_45 ( V_30 , V_27 -> V_48 + 1 ) ;
V_29 -> V_45 ( V_30 , F_24 ( V_31 , L_16 ) ) ;
if ( ( V_33 -> V_39 & V_46 ) && ( ( V_27 -> V_48 + 1 ) >= 8 ) )
V_29 -> V_43 ( V_30 , 8 ) ;
V_29 -> string ( V_30 , V_27 -> V_42 , V_27 -> V_48 ) ;
V_29 -> V_43 ( V_30 , sizeof( T_1 ) ) ;
}
F_28 (tree, child) {
F_26 ( V_36 , V_29 , V_30 , V_31 , V_33 ) ;
}
V_29 -> V_49 ( V_30 , V_27 -> V_10 ) ;
}
static struct V_3 F_29 ( struct V_50 * V_51 ,
struct V_32 * V_33 )
{
struct V_50 * V_52 ;
struct V_3 V_8 = V_53 ;
static struct V_54 V_55 = { 0 , 0 } ;
int V_56 ;
for ( V_52 = V_51 ; V_52 ; V_52 = V_52 -> V_57 ) {
V_8 = F_30 ( V_8 , & V_52 -> V_52 ) ;
}
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
V_8 = F_30 ( V_8 , & V_55 ) ;
}
return V_8 ;
}
static void F_31 ( struct V_59 * V_60 ,
struct V_32 * V_33 ,
int V_61 , int V_62 , int V_63 ,
int V_64 )
{
int V_65 ;
V_61 += sizeof( struct V_54 ) ;
memset ( V_60 , 0xff , sizeof( * V_60 ) ) ;
V_60 -> V_66 = F_32 ( V_67 ) ;
V_60 -> V_68 = F_32 ( V_33 -> V_68 ) ;
V_60 -> V_69 = F_32 ( V_33 -> V_69 ) ;
V_65 = F_33 ( V_33 -> V_70 , 8 ) ;
V_60 -> V_71 = F_32 ( V_65 ) ;
V_60 -> V_72 = F_32 ( V_65 + V_61 ) ;
V_60 -> V_73 = F_32 ( V_65 + V_61
+ V_62 ) ;
V_60 -> V_74 = F_32 ( V_65 + V_61 + V_62 + V_63 ) ;
if ( V_33 -> V_39 & V_75 )
V_60 -> V_64 = F_32 ( V_64 ) ;
if ( V_33 -> V_39 & V_76 )
V_60 -> V_77 = F_32 ( V_63 ) ;
if ( V_33 -> V_39 & V_78 )
V_60 -> V_79 = F_32 ( V_62 ) ;
}
void F_34 ( T_2 * V_14 , struct V_80 * V_81 , int V_68 )
{
struct V_32 * V_33 = NULL ;
int V_25 ;
struct V_3 V_82 = V_53 ;
struct V_3 V_83 = V_53 ;
struct V_3 V_4 = V_53 ;
struct V_3 V_31 = V_53 ;
struct V_59 V_60 ;
int V_84 = 0 ;
for ( V_25 = 0 ; V_25 < F_35 ( V_85 ) ; V_25 ++ ) {
if ( V_85 [ V_25 ] . V_68 == V_68 )
V_33 = & V_85 [ V_25 ] ;
}
if ( ! V_33 )
F_36 ( L_17 , V_68 ) ;
F_26 ( V_81 -> V_86 , & V_87 , & V_4 , & V_31 , V_33 ) ;
F_1 ( & V_4 , V_88 ) ;
V_83 = F_29 ( V_81 -> V_51 , V_33 ) ;
F_31 ( & V_60 , V_33 , V_83 . V_6 , V_4 . V_6 , V_31 . V_6 ,
V_81 -> V_64 ) ;
if ( V_89 > 0 ) {
V_84 = V_89 - F_19 ( V_60 . V_74 ) ;
if ( ( V_84 < 0 ) && ( V_90 < 1 ) )
fprintf ( V_91 ,
L_18 ,
F_19 ( V_60 . V_74 ) , V_89 ) ;
}
if ( V_92 > 0 )
V_84 = V_92 ;
if ( V_84 > 0 ) {
int V_93 = F_19 ( V_60 . V_74 ) ;
V_93 += V_84 ;
V_60 . V_74 = F_32 ( V_93 ) ;
}
V_82 = F_4 ( V_82 , & V_60 , V_33 -> V_70 ) ;
V_82 = F_7 ( V_82 , 8 ) ;
V_82 = F_37 ( V_82 , V_83 ) ;
V_82 = F_38 ( V_82 , sizeof( struct V_54 ) ) ;
V_82 = F_37 ( V_82 , V_4 ) ;
V_82 = F_37 ( V_82 , V_31 ) ;
if ( V_84 > 0 )
V_82 = F_38 ( V_82 , V_84 ) ;
if ( fwrite ( V_82 . V_2 , V_82 . V_6 , 1 , V_14 ) != 1 ) {
if ( ferror ( V_14 ) )
F_36 ( L_19 ,
strerror ( V_94 ) ) ;
else
F_36 ( L_20 ) ;
}
F_39 ( V_82 ) ;
}
static void F_40 ( T_2 * V_14 , struct V_3 V_31 )
{
const char * V_95 ;
int V_6 ;
V_95 = V_31 . V_2 ;
while ( V_95 < ( V_31 . V_2 + V_31 . V_6 ) ) {
V_6 = strlen ( V_95 ) ;
fprintf ( V_14 , L_21 , V_95 ) ;
V_95 += V_6 + 1 ;
}
}
void F_41 ( T_2 * V_14 , struct V_80 * V_81 , int V_68 )
{
struct V_32 * V_33 = NULL ;
int V_25 ;
struct V_3 V_31 = V_53 ;
struct V_50 * V_52 ;
const char * V_96 = L_22 ;
for ( V_25 = 0 ; V_25 < F_35 ( V_85 ) ; V_25 ++ ) {
if ( V_85 [ V_25 ] . V_68 == V_68 )
V_33 = & V_85 [ V_25 ] ;
}
if ( ! V_33 )
F_36 ( L_17 , V_68 ) ;
fprintf ( V_14 , L_23 ) ;
F_12 ( V_14 , V_96 , L_24 ) ;
F_12 ( V_14 , V_96 , L_25 ) ;
fprintf ( V_14 , L_26 ) ;
F_14 ( V_14 , V_67 ) ;
fprintf ( V_14 , L_27 ) ;
F_42 ( V_14 , L_28 ,
V_96 , V_96 ) ;
fprintf ( V_14 , L_29 ) ;
F_42 ( V_14 , L_30 ,
V_96 , V_96 ) ;
fprintf ( V_14 , L_31 ) ;
F_42 ( V_14 , L_32 ,
V_96 , V_96 ) ;
fprintf ( V_14 , L_33 ) ;
F_42 ( V_14 , L_34 ,
V_96 , V_96 ) ;
fprintf ( V_14 , L_35 ) ;
F_14 ( V_14 , V_33 -> V_68 ) ;
fprintf ( V_14 , L_36 ) ;
F_14 ( V_14 , V_33 -> V_69 ) ;
if ( V_33 -> V_39 & V_75 ) {
fprintf ( V_14 , L_37 ) ;
F_14 ( V_14 , V_81 -> V_64 ) ;
}
if ( V_33 -> V_39 & V_76 ) {
fprintf ( V_14 , L_38 ) ;
F_42 ( V_14 , L_39 ,
V_96 , V_96 ) ;
}
if ( V_33 -> V_39 & V_78 ) {
fprintf ( V_14 , L_40 ) ;
F_42 ( V_14 , L_41 ,
V_96 , V_96 ) ;
}
F_16 ( V_14 , 8 ) ;
F_12 ( V_14 , V_96 , L_42 ) ;
fprintf ( V_14 , L_43 ) ;
for ( V_52 = V_81 -> V_51 ; V_52 ; V_52 = V_52 -> V_57 ) {
struct V_9 * V_24 ;
F_21 (re->labels, l) {
fprintf ( V_14 , L_4 , V_24 -> V_9 ) ;
fprintf ( V_14 , L_10 , V_24 -> V_9 ) ;
}
F_42 ( V_14 , L_44 , ( unsigned int ) ( V_52 -> V_52 . V_97 >> 32 ) ) ;
F_42 ( V_14 , L_44 ,
( unsigned int ) ( V_52 -> V_52 . V_97 & 0xffffffff ) ) ;
F_42 ( V_14 , L_44 , ( unsigned int ) ( V_52 -> V_52 . V_98 >> 32 ) ) ;
F_42 ( V_14 , L_44 , ( unsigned int ) ( V_52 -> V_52 . V_98 & 0xffffffff ) ) ;
}
for ( V_25 = 0 ; V_25 < V_58 ; V_25 ++ ) {
fprintf ( V_14 , L_45 ) ;
}
fprintf ( V_14 , L_45 ) ;
F_12 ( V_14 , V_96 , L_46 ) ;
F_26 ( V_81 -> V_86 , & V_99 , V_14 , & V_31 , V_33 ) ;
fprintf ( V_14 , L_47 ) ;
F_14 ( V_14 , V_88 ) ;
F_12 ( V_14 , V_96 , L_48 ) ;
F_12 ( V_14 , V_96 , L_49 ) ;
F_40 ( V_14 , V_31 ) ;
F_12 ( V_14 , V_96 , L_50 ) ;
F_12 ( V_14 , V_96 , L_51 ) ;
if ( V_89 > 0 ) {
fprintf ( V_14 , L_52 ,
V_89 , V_96 , V_96 ) ;
}
if ( V_92 > 0 ) {
fprintf ( V_14 , L_53 , V_92 ) ;
}
F_12 ( V_14 , V_96 , L_54 ) ;
F_39 ( V_31 ) ;
}
static void F_43 ( struct V_100 * V_101 , void * V_102 , void * V_103 )
{
V_101 -> V_102 = V_102 ;
V_101 -> V_103 = V_103 ;
V_101 -> V_104 = V_101 -> V_102 ;
}
static void F_44 ( struct V_100 * V_101 , void * V_95 , int V_6 )
{
if ( ( V_101 -> V_104 + V_6 ) > V_101 -> V_103 )
F_36 ( L_55 ) ;
memcpy ( V_95 , V_101 -> V_104 , V_6 ) ;
V_101 -> V_104 += V_6 ;
}
static V_23 F_45 ( struct V_100 * V_101 )
{
V_23 V_2 ;
assert ( ( ( V_101 -> V_104 - V_101 -> V_102 ) % sizeof( V_2 ) ) == 0 ) ;
F_44 ( V_101 , & V_2 , sizeof( V_2 ) ) ;
return F_19 ( V_2 ) ;
}
static void F_46 ( struct V_100 * V_101 , int V_43 )
{
int V_18 = V_101 -> V_104 - V_101 -> V_102 ;
V_101 -> V_104 = V_101 -> V_102 + F_33 ( V_18 , V_43 ) ;
if ( V_101 -> V_104 > V_101 -> V_103 )
F_36 ( L_55 ) ;
}
static char * F_47 ( struct V_100 * V_101 )
{
int V_6 = 0 ;
const char * V_95 = V_101 -> V_104 ;
char * V_5 ;
do {
if ( V_95 >= V_101 -> V_103 )
F_36 ( L_55 ) ;
V_6 ++ ;
} while ( ( * V_95 ++ ) != '\0' );
V_5 = F_48 ( V_101 -> V_104 ) ;
V_101 -> V_104 += V_6 ;
F_46 ( V_101 , sizeof( V_23 ) ) ;
return V_5 ;
}
static struct V_3 F_49 ( struct V_100 * V_101 , int V_6 )
{
struct V_3 V_8 = V_53 ;
if ( V_6 == 0 )
return V_53 ;
V_8 = F_50 ( V_8 , V_6 ) ;
V_8 . V_6 = V_6 ;
F_44 ( V_101 , V_8 . V_2 , V_6 ) ;
F_46 ( V_101 , sizeof( V_23 ) ) ;
return V_8 ;
}
static char * F_51 ( struct V_100 * V_101 , int V_16 )
{
const char * V_95 ;
V_95 = V_101 -> V_102 + V_16 ;
while ( 1 ) {
if ( V_95 >= V_101 -> V_103 || V_95 < V_101 -> V_102 )
F_36 ( L_56 ,
V_16 ) ;
if ( * V_95 == '\0' )
break;
V_95 ++ ;
}
return F_48 ( V_101 -> V_102 + V_16 ) ;
}
static struct V_34 * F_52 ( struct V_100 * V_4 ,
struct V_100 * V_31 , int V_39 )
{
V_23 V_105 , V_106 ;
char * V_42 ;
struct V_3 V_2 ;
V_105 = F_45 ( V_4 ) ;
V_106 = F_45 ( V_4 ) ;
V_42 = F_51 ( V_31 , V_106 ) ;
if ( ( V_39 & V_46 ) && ( V_105 >= 8 ) )
F_46 ( V_4 , 8 ) ;
V_2 = F_49 ( V_4 , V_105 ) ;
return F_53 ( V_42 , V_2 ) ;
}
static struct V_50 * F_54 ( struct V_100 * V_101 )
{
struct V_50 * V_51 = NULL ;
struct V_50 * V_107 ;
const char * V_95 ;
struct V_54 V_52 ;
V_95 = V_101 -> V_104 ;
while ( 1 ) {
F_44 ( V_101 , & V_52 , sizeof( V_52 ) ) ;
V_52 . V_97 = F_55 ( V_52 . V_97 ) ;
V_52 . V_98 = F_55 ( V_52 . V_98 ) ;
if ( V_52 . V_98 == 0 )
break;
V_107 = F_56 ( V_52 . V_97 , V_52 . V_98 ) ;
V_51 = F_57 ( V_51 , V_107 ) ;
}
return V_51 ;
}
static char * F_58 ( const char * V_108 , const char * V_109 )
{
int V_110 ;
V_110 = strlen ( V_108 ) ;
if ( ! F_59 ( V_108 , V_109 , V_110 ) )
F_36 ( L_57 ,
V_109 , V_108 ) ;
if ( ! F_25 ( V_108 , L_58 ) )
V_110 ++ ;
return F_48 ( V_109 + V_110 ) ;
}
static struct V_26 * F_60 ( struct V_100 * V_4 ,
struct V_100 * V_31 ,
const char * V_111 , int V_39 )
{
struct V_26 * V_26 ;
char * V_112 ;
V_23 V_2 ;
V_26 = F_61 ( NULL , NULL ) ;
V_112 = F_47 ( V_4 ) ;
if ( V_39 & V_40 )
V_26 -> V_42 = F_58 ( V_111 , V_112 ) ;
else
V_26 -> V_42 = V_112 ;
do {
struct V_34 * V_35 ;
struct V_26 * V_36 ;
V_2 = F_45 ( V_4 ) ;
switch ( V_2 ) {
case V_13 :
if ( V_26 -> V_113 )
fprintf ( V_91 , L_59
L_60 ) ;
V_35 = F_52 ( V_4 , V_31 , V_39 ) ;
F_62 ( V_26 , V_35 ) ;
break;
case V_11 :
V_36 = F_60 ( V_4 , V_31 , V_112 , V_39 ) ;
F_63 ( V_26 , V_36 ) ;
break;
case V_12 :
break;
case V_88 :
F_36 ( L_61 ) ;
break;
case V_114 :
if ( ! ( V_39 & V_115 ) )
fprintf ( V_91 , L_62
L_63 ) ;
break;
default:
F_36 ( L_64 ,
V_2 ) ;
}
} while ( V_2 != V_12 );
return V_26 ;
}
struct V_80 * F_64 ( const char * V_116 )
{
T_2 * V_14 ;
V_23 V_66 , V_74 , V_68 , V_117 , V_64 ;
V_23 V_118 , V_119 , V_71 ;
int V_120 ;
char * V_82 ;
struct V_59 * V_60 ;
char * V_95 ;
struct V_100 V_4 , V_31 ;
struct V_100 V_121 ;
int V_122 ;
struct V_50 * V_51 ;
struct V_26 * V_27 ;
V_23 V_2 ;
int V_39 = 0 ;
V_14 = F_65 ( V_116 , NULL ) ;
V_120 = fread ( & V_66 , sizeof( V_66 ) , 1 , V_14 ) ;
if ( ferror ( V_14 ) )
F_36 ( L_65 ,
strerror ( V_94 ) ) ;
if ( V_120 < 1 ) {
if ( feof ( V_14 ) )
F_36 ( L_66 ) ;
else
F_36 ( L_67 ) ;
}
V_66 = F_19 ( V_66 ) ;
if ( V_66 != V_67 )
F_36 ( L_68 ) ;
V_120 = fread ( & V_74 , sizeof( V_74 ) , 1 , V_14 ) ;
if ( ferror ( V_14 ) )
F_36 ( L_69 , strerror ( V_94 ) ) ;
if ( V_120 < 1 ) {
if ( feof ( V_14 ) )
F_36 ( L_70 ) ;
else
F_36 ( L_71 ) ;
}
V_74 = F_19 ( V_74 ) ;
if ( V_74 < V_123 )
F_36 ( L_72 , V_74 ) ;
V_82 = xmalloc ( V_74 ) ;
V_60 = (struct V_59 * ) V_82 ;
V_60 -> V_66 = F_32 ( V_66 ) ;
V_60 -> V_74 = F_32 ( V_74 ) ;
V_122 = V_74 - sizeof( V_66 ) - sizeof( V_74 ) ;
V_95 = V_82 + sizeof( V_66 ) + sizeof( V_74 ) ;
while ( V_122 ) {
if ( feof ( V_14 ) )
F_36 ( L_73 ,
V_74 ) ;
V_120 = fread ( V_95 , 1 , V_122 , V_14 ) ;
if ( ferror ( V_14 ) )
F_36 ( L_74 ,
strerror ( V_94 ) ) ;
V_122 -= V_120 ;
V_95 += V_120 ;
}
V_118 = F_19 ( V_60 -> V_72 ) ;
V_119 = F_19 ( V_60 -> V_73 ) ;
V_71 = F_19 ( V_60 -> V_71 ) ;
V_68 = F_19 ( V_60 -> V_68 ) ;
V_64 = F_19 ( V_60 -> V_64 ) ;
if ( V_71 >= V_74 )
F_36 ( L_75 ) ;
if ( V_118 >= V_74 )
F_36 ( L_76 ) ;
if ( V_119 > V_74 )
F_36 ( L_77 ) ;
if ( V_68 >= 3 ) {
V_23 V_124 = F_19 ( V_60 -> V_77 ) ;
if ( V_119 + V_124 > V_74 )
F_36 ( L_78 ) ;
F_43 ( & V_31 , V_82 + V_119 , V_82 + V_119 + V_124 ) ;
} else {
F_43 ( & V_31 , V_82 + V_119 , V_82 + V_74 ) ;
}
if ( V_68 >= 17 ) {
V_117 = F_19 ( V_60 -> V_79 ) ;
if ( V_118 + V_117 > V_74 )
F_36 ( L_79 ) ;
}
if ( V_68 < 16 ) {
V_39 |= V_40 | V_47 | V_46 ;
} else {
V_39 |= V_115 ;
}
F_43 ( & V_121 ,
V_82 + V_71 , V_82 + V_74 ) ;
F_43 ( & V_4 , V_82 + V_118 , V_82 + V_74 ) ;
V_51 = F_54 ( & V_121 ) ;
V_2 = F_45 ( & V_4 ) ;
if ( V_2 != V_11 )
F_36 ( L_80 , V_2 ) ;
V_27 = F_60 ( & V_4 , & V_31 , L_81 , V_39 ) ;
V_2 = F_45 ( & V_4 ) ;
if ( V_2 != V_88 )
F_36 ( L_82 ) ;
free ( V_82 ) ;
fclose ( V_14 ) ;
return F_66 ( V_51 , V_27 , V_64 ) ;
}
