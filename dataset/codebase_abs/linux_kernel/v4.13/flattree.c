static void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
* V_4 = F_2 ( * V_4 , V_2 ) ;
}
static void F_3 ( void * V_1 , const char * V_5 , int V_6 )
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
static void F_15 ( void * V_1 , const char * V_5 , int V_6 )
{
T_2 * V_14 = V_1 ;
if ( V_6 != 0 )
fprintf ( V_14 , L_7 , V_6 , V_5 ) ;
else
fprintf ( V_14 , L_8 , V_5 ) ;
}
static void F_16 ( void * V_1 , int V_7 )
{
T_2 * V_14 = V_1 ;
fprintf ( V_14 , L_9 , V_7 ) ;
}
static void F_17 ( void * V_1 , struct V_3 V_8 )
{
T_2 * V_14 = V_1 ;
int V_17 = 0 ;
struct V_18 * V_19 = V_8 . V_20 ;
F_18 (m, LABEL)
F_13 ( V_14 , V_19 -> V_21 , V_19 -> V_16 ) ;
while ( ( V_8 . V_6 - V_17 ) >= sizeof( V_22 ) ) {
F_14 ( V_1 , F_19 ( * ( ( V_23 * ) ( V_8 . V_2 + V_17 ) ) ) ) ;
V_17 += sizeof( V_22 ) ;
}
while ( ( V_8 . V_6 - V_17 ) >= 1 ) {
fprintf ( V_14 , L_10 , V_8 . V_2 [ V_17 ] ) ;
V_17 += 1 ;
}
assert ( V_17 == V_8 . V_6 ) ;
}
static void F_20 ( void * V_1 , struct V_9 * V_10 )
{
T_2 * V_14 = V_1 ;
struct V_9 * V_24 ;
F_21 (labels, l) {
fprintf ( V_14 , L_4 , V_24 -> V_9 ) ;
fprintf ( V_14 , L_11 , V_24 -> V_9 ) ;
}
fprintf ( V_14 , L_12 ) ;
F_14 ( V_1 , V_11 ) ;
}
static void F_22 ( void * V_1 , struct V_9 * V_10 )
{
T_2 * V_14 = V_1 ;
struct V_9 * V_24 ;
fprintf ( V_14 , L_13 ) ;
F_14 ( V_1 , V_12 ) ;
F_21 (labels, l) {
fprintf ( V_14 , L_14 , V_24 -> V_9 ) ;
fprintf ( V_14 , L_15 , V_24 -> V_9 ) ;
}
}
static void F_23 ( void * V_1 , struct V_9 * V_10 )
{
T_2 * V_14 = V_1 ;
struct V_9 * V_24 ;
F_21 (labels, l) {
fprintf ( V_14 , L_4 , V_24 -> V_9 ) ;
fprintf ( V_14 , L_11 , V_24 -> V_9 ) ;
}
fprintf ( V_14 , L_16 ) ;
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
if ( F_25 ( V_35 -> V_43 , L_17 ) )
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
V_29 -> V_46 ( V_30 , F_24 ( V_31 , L_17 ) ) ;
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
int V_55 ;
for ( V_53 = V_52 ; V_53 ; V_53 = V_53 -> V_56 ) {
V_8 = F_30 ( V_8 , V_53 -> V_57 , V_53 -> V_58 ) ;
}
for ( V_55 = 0 ; V_55 < V_59 ; V_55 ++ ) {
V_8 = F_30 ( V_8 , 0 , 0 ) ;
}
return V_8 ;
}
static void F_31 ( struct V_60 * V_61 ,
struct V_32 * V_33 ,
int V_62 , int V_63 , int V_64 ,
int V_65 )
{
int V_66 ;
V_62 += sizeof( struct V_67 ) ;
memset ( V_61 , 0xff , sizeof( * V_61 ) ) ;
V_61 -> V_68 = F_32 ( V_69 ) ;
V_61 -> V_70 = F_32 ( V_33 -> V_70 ) ;
V_61 -> V_71 = F_32 ( V_33 -> V_71 ) ;
V_66 = F_33 ( V_33 -> V_72 , 8 ) ;
V_61 -> V_73 = F_32 ( V_66 ) ;
V_61 -> V_74 = F_32 ( V_66 + V_62 ) ;
V_61 -> V_75 = F_32 ( V_66 + V_62
+ V_63 ) ;
V_61 -> V_76 = F_32 ( V_66 + V_62 + V_63 + V_64 ) ;
if ( V_33 -> V_40 & V_77 )
V_61 -> V_65 = F_32 ( V_65 ) ;
if ( V_33 -> V_40 & V_78 )
V_61 -> V_79 = F_32 ( V_64 ) ;
if ( V_33 -> V_40 & V_80 )
V_61 -> V_81 = F_32 ( V_63 ) ;
}
void F_34 ( T_2 * V_14 , struct V_82 * V_83 , int V_70 )
{
struct V_32 * V_33 = NULL ;
int V_25 ;
struct V_3 V_84 = V_54 ;
struct V_3 V_85 = V_54 ;
struct V_3 V_4 = V_54 ;
struct V_3 V_31 = V_54 ;
struct V_60 V_61 ;
int V_86 = 0 ;
for ( V_25 = 0 ; V_25 < F_35 ( V_87 ) ; V_25 ++ ) {
if ( V_87 [ V_25 ] . V_70 == V_70 )
V_33 = & V_87 [ V_25 ] ;
}
if ( ! V_33 )
F_36 ( L_18 , V_70 ) ;
F_26 ( V_83 -> V_88 , & V_89 , & V_4 , & V_31 , V_33 ) ;
F_1 ( & V_4 , V_90 ) ;
V_85 = F_29 ( V_83 -> V_52 , V_33 ) ;
F_31 ( & V_61 , V_33 , V_85 . V_6 , V_4 . V_6 , V_31 . V_6 ,
V_83 -> V_65 ) ;
if ( V_91 > 0 ) {
V_86 = V_91 - F_19 ( V_61 . V_76 ) ;
if ( V_86 < 0 ) {
V_86 = 0 ;
if ( V_92 < 1 )
fprintf ( V_93 ,
L_19 ,
F_19 ( V_61 . V_76 ) , V_91 ) ;
}
}
if ( V_94 > 0 )
V_86 = V_94 ;
if ( V_95 > 0 )
V_86 = F_33 ( F_19 ( V_61 . V_76 ) + V_86 , V_95 )
- F_19 ( V_61 . V_76 ) ;
if ( V_86 > 0 ) {
int V_96 = F_19 ( V_61 . V_76 ) ;
V_96 += V_86 ;
V_61 . V_76 = F_32 ( V_96 ) ;
}
V_84 = F_4 ( V_84 , & V_61 , V_33 -> V_72 ) ;
V_84 = F_7 ( V_84 , 8 ) ;
V_84 = F_37 ( V_84 , V_85 ) ;
V_84 = F_38 ( V_84 , sizeof( struct V_67 ) ) ;
V_84 = F_37 ( V_84 , V_4 ) ;
V_84 = F_37 ( V_84 , V_31 ) ;
if ( V_86 > 0 )
V_84 = F_38 ( V_84 , V_86 ) ;
if ( fwrite ( V_84 . V_2 , V_84 . V_6 , 1 , V_14 ) != 1 ) {
if ( ferror ( V_14 ) )
F_36 ( L_20 ,
strerror ( V_97 ) ) ;
else
F_36 ( L_21 ) ;
}
F_39 ( V_84 ) ;
}
static void F_40 ( T_2 * V_14 , struct V_3 V_31 )
{
const char * V_98 ;
int V_6 ;
V_98 = V_31 . V_2 ;
while ( V_98 < ( V_31 . V_2 + V_31 . V_6 ) ) {
V_6 = strlen ( V_98 ) ;
fprintf ( V_14 , L_22 , V_98 ) ;
V_98 += V_6 + 1 ;
}
}
void F_41 ( T_2 * V_14 , struct V_82 * V_83 , int V_70 )
{
struct V_32 * V_33 = NULL ;
int V_25 ;
struct V_3 V_31 = V_54 ;
struct V_51 * V_53 ;
const char * V_99 = L_23 ;
for ( V_25 = 0 ; V_25 < F_35 ( V_87 ) ; V_25 ++ ) {
if ( V_87 [ V_25 ] . V_70 == V_70 )
V_33 = & V_87 [ V_25 ] ;
}
if ( ! V_33 )
F_36 ( L_18 , V_70 ) ;
fprintf ( V_14 , L_24 ) ;
F_12 ( V_14 , V_99 , L_25 ) ;
F_12 ( V_14 , V_99 , L_26 ) ;
fprintf ( V_14 , L_27 ) ;
F_14 ( V_14 , V_69 ) ;
fprintf ( V_14 , L_28 ) ;
F_42 ( V_14 , L_29 ,
V_99 , V_99 ) ;
fprintf ( V_14 , L_30 ) ;
F_42 ( V_14 , L_31 ,
V_99 , V_99 ) ;
fprintf ( V_14 , L_32 ) ;
F_42 ( V_14 , L_33 ,
V_99 , V_99 ) ;
fprintf ( V_14 , L_34 ) ;
F_42 ( V_14 , L_35 ,
V_99 , V_99 ) ;
fprintf ( V_14 , L_36 ) ;
F_14 ( V_14 , V_33 -> V_70 ) ;
fprintf ( V_14 , L_37 ) ;
F_14 ( V_14 , V_33 -> V_71 ) ;
if ( V_33 -> V_40 & V_77 ) {
fprintf ( V_14 , L_38 ) ;
F_14 ( V_14 , V_83 -> V_65 ) ;
}
if ( V_33 -> V_40 & V_78 ) {
fprintf ( V_14 , L_39 ) ;
F_42 ( V_14 , L_40 ,
V_99 , V_99 ) ;
}
if ( V_33 -> V_40 & V_80 ) {
fprintf ( V_14 , L_41 ) ;
F_42 ( V_14 , L_42 ,
V_99 , V_99 ) ;
}
F_16 ( V_14 , 8 ) ;
F_12 ( V_14 , V_99 , L_43 ) ;
fprintf ( V_14 , L_44 ) ;
for ( V_53 = V_83 -> V_52 ; V_53 ; V_53 = V_53 -> V_56 ) {
struct V_9 * V_24 ;
F_21 (re->labels, l) {
fprintf ( V_14 , L_4 , V_24 -> V_9 ) ;
fprintf ( V_14 , L_11 , V_24 -> V_9 ) ;
}
F_42 ( V_14 , L_45 , ( unsigned int ) ( V_53 -> V_57 >> 32 ) ) ;
F_42 ( V_14 , L_45 ,
( unsigned int ) ( V_53 -> V_57 & 0xffffffff ) ) ;
F_42 ( V_14 , L_45 , ( unsigned int ) ( V_53 -> V_58 >> 32 ) ) ;
F_42 ( V_14 , L_45 , ( unsigned int ) ( V_53 -> V_58 & 0xffffffff ) ) ;
}
for ( V_25 = 0 ; V_25 < V_59 ; V_25 ++ ) {
fprintf ( V_14 , L_46 ) ;
}
fprintf ( V_14 , L_46 ) ;
F_12 ( V_14 , V_99 , L_47 ) ;
F_26 ( V_83 -> V_88 , & V_100 , V_14 , & V_31 , V_33 ) ;
fprintf ( V_14 , L_48 ) ;
F_14 ( V_14 , V_90 ) ;
F_12 ( V_14 , V_99 , L_49 ) ;
F_12 ( V_14 , V_99 , L_50 ) ;
F_40 ( V_14 , V_31 ) ;
F_12 ( V_14 , V_99 , L_51 ) ;
F_12 ( V_14 , V_99 , L_52 ) ;
if ( V_91 > 0 ) {
fprintf ( V_14 , L_53 ,
V_91 , V_99 , V_99 ) ;
}
if ( V_94 > 0 ) {
fprintf ( V_14 , L_54 , V_94 ) ;
}
if ( V_95 > 0 )
F_16 ( V_14 , V_95 ) ;
F_12 ( V_14 , V_99 , L_55 ) ;
F_39 ( V_31 ) ;
}
static void F_43 ( struct V_101 * V_102 , void * V_103 , void * V_104 )
{
V_102 -> V_103 = V_103 ;
V_102 -> V_104 = V_104 ;
V_102 -> V_105 = V_102 -> V_103 ;
}
static void F_44 ( struct V_101 * V_102 , void * V_98 , int V_6 )
{
if ( ( V_102 -> V_105 + V_6 ) > V_102 -> V_104 )
F_36 ( L_56 ) ;
memcpy ( V_98 , V_102 -> V_105 , V_6 ) ;
V_102 -> V_105 += V_6 ;
}
static V_22 F_45 ( struct V_101 * V_102 )
{
V_23 V_2 ;
assert ( ( ( V_102 -> V_105 - V_102 -> V_103 ) % sizeof( V_2 ) ) == 0 ) ;
F_44 ( V_102 , & V_2 , sizeof( V_2 ) ) ;
return F_19 ( V_2 ) ;
}
static void F_46 ( struct V_101 * V_102 , int V_44 )
{
int V_17 = V_102 -> V_105 - V_102 -> V_103 ;
V_102 -> V_105 = V_102 -> V_103 + F_33 ( V_17 , V_44 ) ;
if ( V_102 -> V_105 > V_102 -> V_104 )
F_36 ( L_56 ) ;
}
static char * F_47 ( struct V_101 * V_102 )
{
int V_6 = 0 ;
const char * V_98 = V_102 -> V_105 ;
char * V_5 ;
do {
if ( V_98 >= V_102 -> V_104 )
F_36 ( L_56 ) ;
V_6 ++ ;
} while ( ( * V_98 ++ ) != '\0' );
V_5 = F_48 ( V_102 -> V_105 ) ;
V_102 -> V_105 += V_6 ;
F_46 ( V_102 , sizeof( V_22 ) ) ;
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
F_46 ( V_102 , sizeof( V_22 ) ) ;
return V_8 ;
}
static char * F_51 ( struct V_101 * V_102 , int V_16 )
{
const char * V_98 ;
V_98 = V_102 -> V_103 + V_16 ;
while ( 1 ) {
if ( V_98 >= V_102 -> V_104 || V_98 < V_102 -> V_103 )
F_36 ( L_57 ,
V_16 ) ;
if ( * V_98 == '\0' )
break;
V_98 ++ ;
}
return F_48 ( V_102 -> V_103 + V_16 ) ;
}
static struct V_34 * F_52 ( struct V_101 * V_4 ,
struct V_101 * V_31 , int V_40 )
{
V_22 V_106 , V_107 ;
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
struct V_67 V_53 ;
while ( 1 ) {
T_3 V_57 , V_58 ;
F_44 ( V_102 , & V_53 , sizeof( V_53 ) ) ;
V_57 = F_55 ( V_53 . V_57 ) ;
V_58 = F_55 ( V_53 . V_58 ) ;
if ( V_58 == 0 )
break;
V_108 = F_56 ( V_57 , V_58 ) ;
V_52 = F_57 ( V_52 , V_108 ) ;
}
return V_52 ;
}
static char * F_58 ( const char * V_109 , const char * V_110 )
{
int V_111 ;
V_111 = strlen ( V_109 ) ;
if ( ! F_59 ( V_109 , V_110 , V_111 ) )
F_36 ( L_58 ,
V_110 , V_109 ) ;
if ( ! F_25 ( V_109 , L_59 ) )
V_111 ++ ;
return F_48 ( V_110 + V_111 ) ;
}
static struct V_26 * F_60 ( struct V_101 * V_4 ,
struct V_101 * V_31 ,
const char * V_112 , int V_40 )
{
struct V_26 * V_26 ;
char * V_113 ;
V_22 V_2 ;
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
fprintf ( V_93 , L_60
L_61 ) ;
V_35 = F_52 ( V_4 , V_31 , V_40 ) ;
F_62 ( V_26 , V_35 ) ;
break;
case V_11 :
V_36 = F_60 ( V_4 , V_31 , V_113 , V_40 ) ;
F_63 ( V_26 , V_36 ) ;
break;
case V_12 :
break;
case V_90 :
F_36 ( L_62 ) ;
break;
case V_115 :
if ( ! ( V_40 & V_116 ) )
fprintf ( V_93 , L_63
L_64 ) ;
break;
default:
F_36 ( L_65 ,
V_2 ) ;
}
} while ( V_2 != V_12 );
if ( V_26 -> V_43 != V_113 ) {
free ( V_113 ) ;
}
return V_26 ;
}
struct V_82 * F_64 ( const char * V_117 )
{
T_2 * V_14 ;
V_23 V_118 , V_119 ;
V_22 V_68 , V_76 , V_70 , V_120 , V_65 ;
V_22 V_121 , V_122 , V_73 ;
int V_123 ;
char * V_84 ;
struct V_60 * V_61 ;
char * V_98 ;
struct V_101 V_4 , V_31 ;
struct V_101 V_124 ;
int V_125 ;
struct V_51 * V_52 ;
struct V_26 * V_27 ;
V_22 V_2 ;
int V_40 = 0 ;
V_14 = F_65 ( V_117 , NULL ) ;
V_123 = fread ( & V_118 , sizeof( V_118 ) , 1 , V_14 ) ;
if ( ferror ( V_14 ) )
F_36 ( L_66 ,
strerror ( V_97 ) ) ;
if ( V_123 < 1 ) {
if ( feof ( V_14 ) )
F_36 ( L_67 ) ;
else
F_36 ( L_68 ) ;
}
V_68 = F_19 ( V_118 ) ;
if ( V_68 != V_69 )
F_36 ( L_69 ) ;
V_123 = fread ( & V_119 , sizeof( V_119 ) , 1 , V_14 ) ;
if ( ferror ( V_14 ) )
F_36 ( L_70 , strerror ( V_97 ) ) ;
if ( V_123 < 1 ) {
if ( feof ( V_14 ) )
F_36 ( L_71 ) ;
else
F_36 ( L_72 ) ;
}
V_76 = F_19 ( V_119 ) ;
if ( V_76 < V_126 )
F_36 ( L_73 , V_76 ) ;
V_84 = xmalloc ( V_76 ) ;
V_61 = (struct V_60 * ) V_84 ;
V_61 -> V_68 = F_32 ( V_68 ) ;
V_61 -> V_76 = F_32 ( V_76 ) ;
V_125 = V_76 - sizeof( V_68 ) - sizeof( V_76 ) ;
V_98 = V_84 + sizeof( V_68 ) + sizeof( V_76 ) ;
while ( V_125 ) {
if ( feof ( V_14 ) )
F_36 ( L_74 ,
V_76 ) ;
V_123 = fread ( V_98 , 1 , V_125 , V_14 ) ;
if ( ferror ( V_14 ) )
F_36 ( L_75 ,
strerror ( V_97 ) ) ;
V_125 -= V_123 ;
V_98 += V_123 ;
}
V_121 = F_19 ( V_61 -> V_74 ) ;
V_122 = F_19 ( V_61 -> V_75 ) ;
V_73 = F_19 ( V_61 -> V_73 ) ;
V_70 = F_19 ( V_61 -> V_70 ) ;
V_65 = F_19 ( V_61 -> V_65 ) ;
if ( V_73 >= V_76 )
F_36 ( L_76 ) ;
if ( V_121 >= V_76 )
F_36 ( L_77 ) ;
if ( V_122 > V_76 )
F_36 ( L_78 ) ;
if ( V_70 >= 3 ) {
V_22 V_127 = F_19 ( V_61 -> V_79 ) ;
if ( ( V_122 + V_127 < V_122 ) || ( V_122 + V_127 > V_76 ) )
F_36 ( L_79 ) ;
F_43 ( & V_31 , V_84 + V_122 , V_84 + V_122 + V_127 ) ;
} else {
F_43 ( & V_31 , V_84 + V_122 , V_84 + V_76 ) ;
}
if ( V_70 >= 17 ) {
V_120 = F_19 ( V_61 -> V_81 ) ;
if ( ( V_121 + V_120 < V_121 ) || ( V_121 + V_120 > V_76 ) )
F_36 ( L_80 ) ;
}
if ( V_70 < 16 ) {
V_40 |= V_41 | V_48 | V_47 ;
} else {
V_40 |= V_116 ;
}
F_43 ( & V_124 ,
V_84 + V_73 , V_84 + V_76 ) ;
F_43 ( & V_4 , V_84 + V_121 , V_84 + V_76 ) ;
V_52 = F_54 ( & V_124 ) ;
V_2 = F_45 ( & V_4 ) ;
if ( V_2 != V_11 )
F_36 ( L_81 , V_2 ) ;
V_27 = F_60 ( & V_4 , & V_31 , L_82 , V_40 ) ;
V_2 = F_45 ( & V_4 ) ;
if ( V_2 != V_90 )
F_36 ( L_83 ) ;
free ( V_84 ) ;
fclose ( V_14 ) ;
return F_66 ( V_128 , V_52 , V_27 , V_65 ) ;
}
