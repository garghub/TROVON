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
bool V_37 = false ;
if ( V_27 -> V_38 )
return;
V_29 -> V_39 ( V_30 , V_27 -> V_10 ) ;
if ( V_33 -> V_40 & V_41 )
V_29 -> string ( V_30 , V_27 -> V_42 , 0 ) ;
else
V_29 -> string ( V_30 , V_27 -> V_43 , 0 ) ;
V_29 -> V_44 ( V_30 , sizeof( T_1 ) ) ;
F_27 (tree, prop) {
int V_45 ;
if ( F_25 ( V_35 -> V_43 , L_16 ) )
V_37 = true ;
V_45 = F_24 ( V_31 , V_35 -> V_43 ) ;
V_29 -> V_34 ( V_30 , V_35 -> V_10 ) ;
V_29 -> V_46 ( V_30 , V_35 -> V_2 . V_6 ) ;
V_29 -> V_46 ( V_30 , V_45 ) ;
if ( ( V_33 -> V_40 & V_47 ) && ( V_35 -> V_2 . V_6 >= 8 ) )
V_29 -> V_44 ( V_30 , 8 ) ;
V_29 -> V_3 ( V_30 , V_35 -> V_2 ) ;
V_29 -> V_44 ( V_30 , sizeof( T_1 ) ) ;
}
if ( ( V_33 -> V_40 & V_48 ) && ! V_37 ) {
V_29 -> V_34 ( V_30 , NULL ) ;
V_29 -> V_46 ( V_30 , V_27 -> V_49 + 1 ) ;
V_29 -> V_46 ( V_30 , F_24 ( V_31 , L_16 ) ) ;
if ( ( V_33 -> V_40 & V_47 ) && ( ( V_27 -> V_49 + 1 ) >= 8 ) )
V_29 -> V_44 ( V_30 , 8 ) ;
V_29 -> string ( V_30 , V_27 -> V_43 , V_27 -> V_49 ) ;
V_29 -> V_44 ( V_30 , sizeof( T_1 ) ) ;
}
F_28 (tree, child) {
F_26 ( V_36 , V_29 , V_30 , V_31 , V_33 ) ;
}
V_29 -> V_50 ( V_30 , V_27 -> V_10 ) ;
}
static struct V_3 F_29 ( struct V_51 * V_52 ,
struct V_32 * V_33 )
{
struct V_51 * V_53 ;
struct V_3 V_8 = V_54 ;
static struct V_55 V_56 = { 0 , 0 } ;
int V_57 ;
for ( V_53 = V_52 ; V_53 ; V_53 = V_53 -> V_58 ) {
V_8 = F_30 ( V_8 , & V_53 -> V_53 ) ;
}
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
V_8 = F_30 ( V_8 , & V_56 ) ;
}
return V_8 ;
}
static void F_31 ( struct V_60 * V_61 ,
struct V_32 * V_33 ,
int V_62 , int V_63 , int V_64 ,
int V_65 )
{
int V_66 ;
V_62 += sizeof( struct V_55 ) ;
memset ( V_61 , 0xff , sizeof( * V_61 ) ) ;
V_61 -> V_67 = F_32 ( V_68 ) ;
V_61 -> V_69 = F_32 ( V_33 -> V_69 ) ;
V_61 -> V_70 = F_32 ( V_33 -> V_70 ) ;
V_66 = F_33 ( V_33 -> V_71 , 8 ) ;
V_61 -> V_72 = F_32 ( V_66 ) ;
V_61 -> V_73 = F_32 ( V_66 + V_62 ) ;
V_61 -> V_74 = F_32 ( V_66 + V_62
+ V_63 ) ;
V_61 -> V_75 = F_32 ( V_66 + V_62 + V_63 + V_64 ) ;
if ( V_33 -> V_40 & V_76 )
V_61 -> V_65 = F_32 ( V_65 ) ;
if ( V_33 -> V_40 & V_77 )
V_61 -> V_78 = F_32 ( V_64 ) ;
if ( V_33 -> V_40 & V_79 )
V_61 -> V_80 = F_32 ( V_63 ) ;
}
void F_34 ( T_2 * V_14 , struct V_81 * V_82 , int V_69 )
{
struct V_32 * V_33 = NULL ;
int V_25 ;
struct V_3 V_83 = V_54 ;
struct V_3 V_84 = V_54 ;
struct V_3 V_4 = V_54 ;
struct V_3 V_31 = V_54 ;
struct V_60 V_61 ;
int V_85 = 0 ;
for ( V_25 = 0 ; V_25 < F_35 ( V_86 ) ; V_25 ++ ) {
if ( V_86 [ V_25 ] . V_69 == V_69 )
V_33 = & V_86 [ V_25 ] ;
}
if ( ! V_33 )
F_36 ( L_17 , V_69 ) ;
F_26 ( V_82 -> V_87 , & V_88 , & V_4 , & V_31 , V_33 ) ;
F_1 ( & V_4 , V_89 ) ;
V_84 = F_29 ( V_82 -> V_52 , V_33 ) ;
F_31 ( & V_61 , V_33 , V_84 . V_6 , V_4 . V_6 , V_31 . V_6 ,
V_82 -> V_65 ) ;
if ( V_90 > 0 ) {
V_85 = V_90 - F_19 ( V_61 . V_75 ) ;
if ( ( V_85 < 0 ) && ( V_91 < 1 ) )
fprintf ( V_92 ,
L_18 ,
F_19 ( V_61 . V_75 ) , V_90 ) ;
}
if ( V_93 > 0 )
V_85 = V_93 ;
if ( V_85 > 0 ) {
int V_94 = F_19 ( V_61 . V_75 ) ;
V_94 += V_85 ;
V_61 . V_75 = F_32 ( V_94 ) ;
}
V_83 = F_4 ( V_83 , & V_61 , V_33 -> V_71 ) ;
V_83 = F_7 ( V_83 , 8 ) ;
V_83 = F_37 ( V_83 , V_84 ) ;
V_83 = F_38 ( V_83 , sizeof( struct V_55 ) ) ;
V_83 = F_37 ( V_83 , V_4 ) ;
V_83 = F_37 ( V_83 , V_31 ) ;
if ( V_85 > 0 )
V_83 = F_38 ( V_83 , V_85 ) ;
if ( fwrite ( V_83 . V_2 , V_83 . V_6 , 1 , V_14 ) != 1 ) {
if ( ferror ( V_14 ) )
F_36 ( L_19 ,
strerror ( V_95 ) ) ;
else
F_36 ( L_20 ) ;
}
F_39 ( V_83 ) ;
}
static void F_40 ( T_2 * V_14 , struct V_3 V_31 )
{
const char * V_96 ;
int V_6 ;
V_96 = V_31 . V_2 ;
while ( V_96 < ( V_31 . V_2 + V_31 . V_6 ) ) {
V_6 = strlen ( V_96 ) ;
fprintf ( V_14 , L_21 , V_96 ) ;
V_96 += V_6 + 1 ;
}
}
void F_41 ( T_2 * V_14 , struct V_81 * V_82 , int V_69 )
{
struct V_32 * V_33 = NULL ;
int V_25 ;
struct V_3 V_31 = V_54 ;
struct V_51 * V_53 ;
const char * V_97 = L_22 ;
for ( V_25 = 0 ; V_25 < F_35 ( V_86 ) ; V_25 ++ ) {
if ( V_86 [ V_25 ] . V_69 == V_69 )
V_33 = & V_86 [ V_25 ] ;
}
if ( ! V_33 )
F_36 ( L_17 , V_69 ) ;
fprintf ( V_14 , L_23 ) ;
F_12 ( V_14 , V_97 , L_24 ) ;
F_12 ( V_14 , V_97 , L_25 ) ;
fprintf ( V_14 , L_26 ) ;
F_14 ( V_14 , V_68 ) ;
fprintf ( V_14 , L_27 ) ;
F_42 ( V_14 , L_28 ,
V_97 , V_97 ) ;
fprintf ( V_14 , L_29 ) ;
F_42 ( V_14 , L_30 ,
V_97 , V_97 ) ;
fprintf ( V_14 , L_31 ) ;
F_42 ( V_14 , L_32 ,
V_97 , V_97 ) ;
fprintf ( V_14 , L_33 ) ;
F_42 ( V_14 , L_34 ,
V_97 , V_97 ) ;
fprintf ( V_14 , L_35 ) ;
F_14 ( V_14 , V_33 -> V_69 ) ;
fprintf ( V_14 , L_36 ) ;
F_14 ( V_14 , V_33 -> V_70 ) ;
if ( V_33 -> V_40 & V_76 ) {
fprintf ( V_14 , L_37 ) ;
F_14 ( V_14 , V_82 -> V_65 ) ;
}
if ( V_33 -> V_40 & V_77 ) {
fprintf ( V_14 , L_38 ) ;
F_42 ( V_14 , L_39 ,
V_97 , V_97 ) ;
}
if ( V_33 -> V_40 & V_79 ) {
fprintf ( V_14 , L_40 ) ;
F_42 ( V_14 , L_41 ,
V_97 , V_97 ) ;
}
F_16 ( V_14 , 8 ) ;
F_12 ( V_14 , V_97 , L_42 ) ;
fprintf ( V_14 , L_43 ) ;
for ( V_53 = V_82 -> V_52 ; V_53 ; V_53 = V_53 -> V_58 ) {
struct V_9 * V_24 ;
F_21 (re->labels, l) {
fprintf ( V_14 , L_4 , V_24 -> V_9 ) ;
fprintf ( V_14 , L_10 , V_24 -> V_9 ) ;
}
F_42 ( V_14 , L_44 , ( unsigned int ) ( V_53 -> V_53 . V_98 >> 32 ) ) ;
F_42 ( V_14 , L_44 ,
( unsigned int ) ( V_53 -> V_53 . V_98 & 0xffffffff ) ) ;
F_42 ( V_14 , L_44 , ( unsigned int ) ( V_53 -> V_53 . V_99 >> 32 ) ) ;
F_42 ( V_14 , L_44 , ( unsigned int ) ( V_53 -> V_53 . V_99 & 0xffffffff ) ) ;
}
for ( V_25 = 0 ; V_25 < V_59 ; V_25 ++ ) {
fprintf ( V_14 , L_45 ) ;
}
fprintf ( V_14 , L_45 ) ;
F_12 ( V_14 , V_97 , L_46 ) ;
F_26 ( V_82 -> V_87 , & V_100 , V_14 , & V_31 , V_33 ) ;
fprintf ( V_14 , L_47 ) ;
F_14 ( V_14 , V_89 ) ;
F_12 ( V_14 , V_97 , L_48 ) ;
F_12 ( V_14 , V_97 , L_49 ) ;
F_40 ( V_14 , V_31 ) ;
F_12 ( V_14 , V_97 , L_50 ) ;
F_12 ( V_14 , V_97 , L_51 ) ;
if ( V_90 > 0 ) {
fprintf ( V_14 , L_52 ,
V_90 , V_97 , V_97 ) ;
}
if ( V_93 > 0 ) {
fprintf ( V_14 , L_53 , V_93 ) ;
}
F_12 ( V_14 , V_97 , L_54 ) ;
F_39 ( V_31 ) ;
}
static void F_43 ( struct V_101 * V_102 , void * V_103 , void * V_104 )
{
V_102 -> V_103 = V_103 ;
V_102 -> V_104 = V_104 ;
V_102 -> V_105 = V_102 -> V_103 ;
}
static void F_44 ( struct V_101 * V_102 , void * V_96 , int V_6 )
{
if ( ( V_102 -> V_105 + V_6 ) > V_102 -> V_104 )
F_36 ( L_55 ) ;
memcpy ( V_96 , V_102 -> V_105 , V_6 ) ;
V_102 -> V_105 += V_6 ;
}
static V_23 F_45 ( struct V_101 * V_102 )
{
V_23 V_2 ;
assert ( ( ( V_102 -> V_105 - V_102 -> V_103 ) % sizeof( V_2 ) ) == 0 ) ;
F_44 ( V_102 , & V_2 , sizeof( V_2 ) ) ;
return F_19 ( V_2 ) ;
}
static void F_46 ( struct V_101 * V_102 , int V_44 )
{
int V_18 = V_102 -> V_105 - V_102 -> V_103 ;
V_102 -> V_105 = V_102 -> V_103 + F_33 ( V_18 , V_44 ) ;
if ( V_102 -> V_105 > V_102 -> V_104 )
F_36 ( L_55 ) ;
}
static char * F_47 ( struct V_101 * V_102 )
{
int V_6 = 0 ;
const char * V_96 = V_102 -> V_105 ;
char * V_5 ;
do {
if ( V_96 >= V_102 -> V_104 )
F_36 ( L_55 ) ;
V_6 ++ ;
} while ( ( * V_96 ++ ) != '\0' );
V_5 = F_48 ( V_102 -> V_105 ) ;
V_102 -> V_105 += V_6 ;
F_46 ( V_102 , sizeof( V_23 ) ) ;
return V_5 ;
}
static struct V_3 F_49 ( struct V_101 * V_102 , int V_6 )
{
struct V_3 V_8 = V_54 ;
if ( V_6 == 0 )
return V_54 ;
V_8 = F_50 ( V_8 , V_6 ) ;
V_8 . V_6 = V_6 ;
F_44 ( V_102 , V_8 . V_2 , V_6 ) ;
F_46 ( V_102 , sizeof( V_23 ) ) ;
return V_8 ;
}
static char * F_51 ( struct V_101 * V_102 , int V_16 )
{
const char * V_96 ;
V_96 = V_102 -> V_103 + V_16 ;
while ( 1 ) {
if ( V_96 >= V_102 -> V_104 || V_96 < V_102 -> V_103 )
F_36 ( L_56 ,
V_16 ) ;
if ( * V_96 == '\0' )
break;
V_96 ++ ;
}
return F_48 ( V_102 -> V_103 + V_16 ) ;
}
static struct V_34 * F_52 ( struct V_101 * V_4 ,
struct V_101 * V_31 , int V_40 )
{
V_23 V_106 , V_107 ;
char * V_43 ;
struct V_3 V_2 ;
V_106 = F_45 ( V_4 ) ;
V_107 = F_45 ( V_4 ) ;
V_43 = F_51 ( V_31 , V_107 ) ;
if ( ( V_40 & V_47 ) && ( V_106 >= 8 ) )
F_46 ( V_4 , 8 ) ;
V_2 = F_49 ( V_4 , V_106 ) ;
return F_53 ( V_43 , V_2 ) ;
}
static struct V_51 * F_54 ( struct V_101 * V_102 )
{
struct V_51 * V_52 = NULL ;
struct V_51 * V_108 ;
struct V_55 V_53 ;
while ( 1 ) {
F_44 ( V_102 , & V_53 , sizeof( V_53 ) ) ;
V_53 . V_98 = F_55 ( V_53 . V_98 ) ;
V_53 . V_99 = F_55 ( V_53 . V_99 ) ;
if ( V_53 . V_99 == 0 )
break;
V_108 = F_56 ( V_53 . V_98 , V_53 . V_99 ) ;
V_52 = F_57 ( V_52 , V_108 ) ;
}
return V_52 ;
}
static char * F_58 ( const char * V_109 , const char * V_110 )
{
int V_111 ;
V_111 = strlen ( V_109 ) ;
if ( ! F_59 ( V_109 , V_110 , V_111 ) )
F_36 ( L_57 ,
V_110 , V_109 ) ;
if ( ! F_25 ( V_109 , L_58 ) )
V_111 ++ ;
return F_48 ( V_110 + V_111 ) ;
}
static struct V_26 * F_60 ( struct V_101 * V_4 ,
struct V_101 * V_31 ,
const char * V_112 , int V_40 )
{
struct V_26 * V_26 ;
char * V_113 ;
V_23 V_2 ;
V_26 = F_61 ( NULL , NULL ) ;
V_113 = F_47 ( V_4 ) ;
if ( V_40 & V_41 )
V_26 -> V_43 = F_58 ( V_112 , V_113 ) ;
else
V_26 -> V_43 = V_113 ;
do {
struct V_34 * V_35 ;
struct V_26 * V_36 ;
V_2 = F_45 ( V_4 ) ;
switch ( V_2 ) {
case V_13 :
if ( V_26 -> V_114 )
fprintf ( V_92 , L_59
L_60 ) ;
V_35 = F_52 ( V_4 , V_31 , V_40 ) ;
F_62 ( V_26 , V_35 ) ;
break;
case V_11 :
V_36 = F_60 ( V_4 , V_31 , V_113 , V_40 ) ;
F_63 ( V_26 , V_36 ) ;
break;
case V_12 :
break;
case V_89 :
F_36 ( L_61 ) ;
break;
case V_115 :
if ( ! ( V_40 & V_116 ) )
fprintf ( V_92 , L_62
L_63 ) ;
break;
default:
F_36 ( L_64 ,
V_2 ) ;
}
} while ( V_2 != V_12 );
return V_26 ;
}
struct V_81 * F_64 ( const char * V_117 )
{
T_2 * V_14 ;
V_23 V_67 , V_75 , V_69 , V_118 , V_65 ;
V_23 V_119 , V_120 , V_72 ;
int V_121 ;
char * V_83 ;
struct V_60 * V_61 ;
char * V_96 ;
struct V_101 V_4 , V_31 ;
struct V_101 V_122 ;
int V_123 ;
struct V_51 * V_52 ;
struct V_26 * V_27 ;
V_23 V_2 ;
int V_40 = 0 ;
V_14 = F_65 ( V_117 , NULL ) ;
V_121 = fread ( & V_67 , sizeof( V_67 ) , 1 , V_14 ) ;
if ( ferror ( V_14 ) )
F_36 ( L_65 ,
strerror ( V_95 ) ) ;
if ( V_121 < 1 ) {
if ( feof ( V_14 ) )
F_36 ( L_66 ) ;
else
F_36 ( L_67 ) ;
}
V_67 = F_19 ( V_67 ) ;
if ( V_67 != V_68 )
F_36 ( L_68 ) ;
V_121 = fread ( & V_75 , sizeof( V_75 ) , 1 , V_14 ) ;
if ( ferror ( V_14 ) )
F_36 ( L_69 , strerror ( V_95 ) ) ;
if ( V_121 < 1 ) {
if ( feof ( V_14 ) )
F_36 ( L_70 ) ;
else
F_36 ( L_71 ) ;
}
V_75 = F_19 ( V_75 ) ;
if ( V_75 < V_124 )
F_36 ( L_72 , V_75 ) ;
V_83 = xmalloc ( V_75 ) ;
V_61 = (struct V_60 * ) V_83 ;
V_61 -> V_67 = F_32 ( V_67 ) ;
V_61 -> V_75 = F_32 ( V_75 ) ;
V_123 = V_75 - sizeof( V_67 ) - sizeof( V_75 ) ;
V_96 = V_83 + sizeof( V_67 ) + sizeof( V_75 ) ;
while ( V_123 ) {
if ( feof ( V_14 ) )
F_36 ( L_73 ,
V_75 ) ;
V_121 = fread ( V_96 , 1 , V_123 , V_14 ) ;
if ( ferror ( V_14 ) )
F_36 ( L_74 ,
strerror ( V_95 ) ) ;
V_123 -= V_121 ;
V_96 += V_121 ;
}
V_119 = F_19 ( V_61 -> V_73 ) ;
V_120 = F_19 ( V_61 -> V_74 ) ;
V_72 = F_19 ( V_61 -> V_72 ) ;
V_69 = F_19 ( V_61 -> V_69 ) ;
V_65 = F_19 ( V_61 -> V_65 ) ;
if ( V_72 >= V_75 )
F_36 ( L_75 ) ;
if ( V_119 >= V_75 )
F_36 ( L_76 ) ;
if ( V_120 > V_75 )
F_36 ( L_77 ) ;
if ( V_69 >= 3 ) {
V_23 V_125 = F_19 ( V_61 -> V_78 ) ;
if ( ( V_120 + V_125 < V_120 ) || ( V_120 + V_125 > V_75 ) )
F_36 ( L_78 ) ;
F_43 ( & V_31 , V_83 + V_120 , V_83 + V_120 + V_125 ) ;
} else {
F_43 ( & V_31 , V_83 + V_120 , V_83 + V_75 ) ;
}
if ( V_69 >= 17 ) {
V_118 = F_19 ( V_61 -> V_80 ) ;
if ( ( V_119 + V_118 < V_119 ) || ( V_119 + V_118 > V_75 ) )
F_36 ( L_79 ) ;
}
if ( V_69 < 16 ) {
V_40 |= V_41 | V_48 | V_47 ;
} else {
V_40 |= V_116 ;
}
F_43 ( & V_122 ,
V_83 + V_72 , V_83 + V_75 ) ;
F_43 ( & V_4 , V_83 + V_119 , V_83 + V_75 ) ;
V_52 = F_54 ( & V_122 ) ;
V_2 = F_45 ( & V_4 ) ;
if ( V_2 != V_11 )
F_36 ( L_80 , V_2 ) ;
V_27 = F_60 ( & V_4 , & V_31 , L_81 , V_40 ) ;
V_2 = F_45 ( & V_4 ) ;
if ( V_2 != V_89 )
F_36 ( L_82 ) ;
free ( V_83 ) ;
fclose ( V_14 ) ;
return F_66 ( V_52 , V_27 , V_65 ) ;
}
