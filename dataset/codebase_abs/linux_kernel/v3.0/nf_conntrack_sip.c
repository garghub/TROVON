static int F_1 ( const struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , int * V_5 )
{
int V_6 = 0 ;
while ( V_3 < V_4 && isalpha ( * V_3 ) ) {
V_3 ++ ;
V_6 ++ ;
}
return V_6 ;
}
static int F_2 ( const struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , int * V_5 )
{
int V_6 = 0 ;
while ( V_3 < V_4 && isdigit ( * V_3 ) ) {
V_3 ++ ;
V_6 ++ ;
}
return V_6 ;
}
static int F_3 ( const char V_7 )
{
if ( isalnum ( V_7 ) || V_7 == '!' || V_7 == '"' || V_7 == '%' ||
( V_7 >= '(' && V_7 <= '/' ) || V_7 == ':' || V_7 == '<' || V_7 == '>' ||
V_7 == '?' || ( V_7 >= '[' && V_7 <= ']' ) || V_7 == '_' || V_7 == '`' ||
V_7 == '{' || V_7 == '}' || V_7 == '~' )
return 1 ;
return 0 ;
}
static int F_4 ( const char * V_3 , const char * V_4 )
{
int V_6 = 0 ;
while ( V_3 < V_4 && F_3 ( * V_3 ) ) {
V_3 ++ ;
V_6 ++ ;
}
return V_6 ;
}
static int F_5 ( const struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , int * V_5 )
{
int V_6 , V_8 ;
V_6 = F_4 ( V_3 , V_4 ) ;
V_3 += V_6 ;
if ( ! V_6 || V_3 == V_4 || * V_3 != '@' )
return V_6 ;
V_3 ++ ;
V_6 ++ ;
V_8 = F_4 ( V_3 , V_4 ) ;
if ( ! V_8 )
return 0 ;
return V_6 + V_8 ;
}
static int F_6 ( const struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , int * V_5 )
{
int V_6 = F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
V_3 += V_6 ;
if ( V_3 >= V_4 || * V_3 != ' ' )
return 0 ;
V_6 ++ ;
V_3 ++ ;
return V_6 + F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_7 ( const struct V_1 * V_2 , const char * V_9 ,
const char * * V_10 , union V_11 * V_12 ,
const char * V_4 )
{
const char * V_13 ;
int V_14 = 0 ;
if ( ! V_2 )
return 0 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
switch ( F_8 ( V_2 ) ) {
case V_15 :
V_14 = F_9 ( V_9 , V_4 - V_9 , ( V_16 * ) & V_12 -> V_17 , - 1 , & V_13 ) ;
break;
case V_18 :
V_14 = F_10 ( V_9 , V_4 - V_9 , ( V_16 * ) & V_12 -> V_19 , - 1 , & V_13 ) ;
break;
default:
F_11 () ;
}
if ( V_14 == 0 || V_13 == V_9 )
return 0 ;
if ( V_10 )
* V_10 = V_13 ;
return 1 ;
}
static int F_12 ( const struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , int * V_5 )
{
union V_11 V_12 ;
const char * V_20 = V_3 ;
if ( ! F_7 ( V_2 , V_3 , & V_3 , & V_12 , V_4 ) ) {
F_13 ( L_1 , V_3 ) ;
return 0 ;
}
if ( * V_3 == ':' ) {
V_3 ++ ;
V_3 += F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
}
return V_3 - V_20 ;
}
static int F_14 ( const struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , int * V_5 )
{
const char * V_21 = V_3 ;
int V_22 = * V_5 ;
while ( V_3 < V_4 &&
* V_3 != '@' && * V_3 != '\r' && * V_3 != '\n' ) {
( * V_5 ) ++ ;
V_3 ++ ;
}
if ( V_3 < V_4 && * V_3 == '@' ) {
V_3 ++ ;
( * V_5 ) ++ ;
} else {
V_3 = V_21 ;
* V_5 = V_22 ;
}
return F_12 ( V_2 , V_3 , V_4 , V_5 ) ;
}
int F_15 ( const struct V_1 * V_2 ,
const char * V_3 , unsigned int V_23 ,
unsigned int * V_24 , unsigned int * V_25 ,
union V_11 * V_12 , T_1 * V_26 )
{
const char * V_21 = V_3 , * V_4 = V_3 + V_23 , * V_13 ;
unsigned int V_27 ;
unsigned int V_28 ;
int V_5 = 0 ;
V_27 = F_1 ( V_2 , V_3 , V_4 , NULL ) ;
if ( ! V_27 )
return 0 ;
V_3 += V_27 ;
if ( ++ V_3 >= V_4 )
return 0 ;
for (; V_3 < V_4 - strlen ( L_2 ) ; V_3 ++ ) {
if ( * V_3 == '\r' || * V_3 == '\n' )
return - 1 ;
if ( F_16 ( V_3 , L_2 , strlen ( L_2 ) ) == 0 ) {
V_3 += strlen ( L_2 ) ;
break;
}
}
if ( ! F_14 ( V_2 , V_3 , V_4 , & V_5 ) )
return 0 ;
V_3 += V_5 ;
if ( ! F_7 ( V_2 , V_3 , & V_13 , V_12 , V_4 ) )
return - 1 ;
if ( V_13 < V_4 && * V_13 == ':' ) {
V_13 ++ ;
V_28 = F_17 ( V_13 , ( char * * ) & V_13 , 10 ) ;
if ( V_28 < 1024 || V_28 > 65535 )
return - 1 ;
* V_26 = F_18 ( V_28 ) ;
} else
* V_26 = F_18 ( V_29 ) ;
if ( V_13 == V_3 )
return 0 ;
* V_24 = V_3 - V_21 ;
* V_25 = V_13 - V_3 ;
return 1 ;
}
static const char * F_19 ( const char * V_3 , const char * V_4 )
{
if ( ++ V_3 >= V_4 )
return NULL ;
if ( * ( V_3 - 1 ) == '\r' && * V_3 == '\n' ) {
if ( ++ V_3 >= V_4 )
return NULL ;
}
if ( * V_3 != ' ' && * V_3 != '\t' )
return NULL ;
for (; V_3 < V_4 ; V_3 ++ ) {
if ( * V_3 != ' ' && * V_3 != '\t' )
break;
}
return V_3 ;
}
static const char * F_20 ( const char * V_3 , const char * V_4 )
{
for (; V_3 < V_4 ; V_3 ++ ) {
if ( * V_3 == ' ' )
continue;
if ( * V_3 != '\r' && * V_3 != '\n' )
break;
V_3 = F_19 ( V_3 , V_4 ) ;
if ( V_3 == NULL )
return NULL ;
}
return V_3 ;
}
static const char * F_21 ( const char * V_3 , const char * V_4 ,
const char * V_30 , unsigned int V_6 )
{
for ( V_4 -= V_6 ; V_3 < V_4 ; V_3 ++ ) {
if ( * V_3 == '\r' || * V_3 == '\n' ) {
V_3 = F_19 ( V_3 , V_4 ) ;
if ( V_3 == NULL )
break;
continue;
}
if ( F_16 ( V_3 , V_30 , V_6 ) == 0 )
return V_3 ;
}
return NULL ;
}
int F_22 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_31 , unsigned int V_23 ,
enum V_32 type ,
unsigned int * V_24 , unsigned int * V_25 )
{
const struct V_33 * V_34 = & V_35 [ type ] ;
const char * V_21 = V_3 , * V_4 = V_3 + V_23 ;
int V_5 = 0 ;
for ( V_3 += V_31 ; V_3 < V_4 ; V_3 ++ ) {
if ( * V_3 != '\r' && * V_3 != '\n' )
continue;
if ( ++ V_3 >= V_4 )
break;
if ( * ( V_3 - 1 ) == '\r' && * V_3 == '\n' ) {
if ( ++ V_3 >= V_4 )
break;
}
if ( * V_3 == ' ' || * V_3 == '\t' )
continue;
if ( V_4 - V_3 >= V_34 -> V_6 &&
F_16 ( V_3 , V_34 -> V_36 , V_34 -> V_6 ) == 0 )
V_3 += V_34 -> V_6 ;
else if ( V_34 -> V_37 && V_4 - V_3 >= V_34 -> V_38 + 1 &&
F_16 ( V_3 , V_34 -> V_37 , V_34 -> V_38 ) == 0 &&
! isalpha ( * ( V_3 + V_34 -> V_38 ) ) )
V_3 += V_34 -> V_38 ;
else
continue;
V_3 = F_20 ( V_3 , V_4 ) ;
if ( V_3 == NULL )
break;
if ( * V_3 != ':' || ++ V_3 >= V_4 )
break;
V_3 = F_20 ( V_3 , V_4 ) ;
if ( V_3 == NULL )
break;
* V_24 = V_3 - V_21 ;
if ( V_34 -> V_39 ) {
V_3 = F_21 ( V_3 , V_4 , V_34 -> V_39 ,
V_34 -> V_40 ) ;
if ( ! V_3 )
return - 1 ;
V_3 += V_34 -> V_40 ;
}
* V_25 = V_34 -> V_41 ( V_2 , V_3 , V_4 , & V_5 ) ;
if ( ! * V_25 )
return - 1 ;
* V_24 = V_3 - V_21 + V_5 ;
return 1 ;
}
return 0 ;
}
static int F_23 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_31 , unsigned int V_23 ,
enum V_32 type ,
unsigned int * V_24 , unsigned int * V_25 )
{
const struct V_33 * V_34 = & V_35 [ type ] ;
const char * V_21 = V_3 , * V_4 = V_3 + V_23 ;
int V_5 = 0 ;
V_3 += V_31 ;
V_3 = F_21 ( V_3 , V_4 , L_3 , strlen ( L_3 ) ) ;
if ( ! V_3 )
return 0 ;
V_3 = F_21 ( V_3 , V_4 , V_34 -> V_39 , V_34 -> V_40 ) ;
if ( ! V_3 )
return 0 ;
V_3 += V_34 -> V_40 ;
* V_24 = V_3 - V_21 ;
* V_25 = V_34 -> V_41 ( V_2 , V_3 , V_4 , & V_5 ) ;
if ( ! * V_25 )
return - 1 ;
* V_24 += V_5 ;
return 1 ;
}
static int F_24 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_31 , unsigned int V_23 ,
enum V_32 type , int * V_42 ,
unsigned int * V_24 , unsigned int * V_25 )
{
int V_14 ;
if ( V_42 && * V_42 ) {
while ( 1 ) {
V_14 = F_23 ( V_2 , V_3 , V_31 , V_23 ,
type , V_24 , V_25 ) ;
if ( V_14 > 0 )
return V_14 ;
if ( V_14 == 0 )
break;
V_31 += * V_24 ;
}
* V_42 = 0 ;
}
while ( 1 ) {
V_14 = F_22 ( V_2 , V_3 , V_31 , V_23 ,
type , V_24 , V_25 ) ;
if ( V_14 > 0 )
break;
if ( V_14 == 0 )
return V_14 ;
V_31 += * V_24 ;
}
if ( V_42 )
* V_42 = 1 ;
return 1 ;
}
int F_25 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int * V_31 , unsigned int V_23 ,
enum V_32 type , int * V_42 ,
unsigned int * V_24 , unsigned int * V_25 ,
union V_11 * V_12 , T_1 * V_26 )
{
const char * V_7 , * V_4 = V_3 + V_23 ;
unsigned int V_28 ;
int V_14 ;
V_14 = F_24 ( V_2 , V_3 , V_31 ? * V_31 : 0 , V_23 ,
type , V_42 , V_24 , V_25 ) ;
F_26 ( V_14 < 0 ) ;
if ( V_14 == 0 )
return V_14 ;
if ( ! F_7 ( V_2 , V_3 + * V_24 , & V_7 , V_12 , V_4 ) )
return - 1 ;
if ( * V_7 == ':' ) {
V_7 ++ ;
V_28 = F_17 ( V_7 , ( char * * ) & V_7 , 10 ) ;
if ( V_28 < 1024 || V_28 > 65535 )
return - 1 ;
* V_26 = F_18 ( V_28 ) ;
} else
* V_26 = F_18 ( V_29 ) ;
if ( V_31 )
* V_31 = V_7 - V_3 ;
return 1 ;
}
static int F_27 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_31 , unsigned int V_23 ,
const char * V_36 ,
unsigned int * V_24 , unsigned int * V_25 )
{
const char * V_4 = V_3 + V_23 ;
const char * V_21 ;
const char * V_13 ;
V_4 = F_21 ( V_3 + V_31 , V_4 , L_3 , strlen ( L_3 ) ) ;
if ( ! V_4 )
V_4 = V_3 + V_23 ;
V_21 = F_21 ( V_3 + V_31 , V_4 , V_36 , strlen ( V_36 ) ) ;
if ( ! V_21 )
return 0 ;
V_21 += strlen ( V_36 ) ;
V_13 = F_21 ( V_21 , V_4 , L_4 , strlen ( L_4 ) ) ;
if ( ! V_13 )
V_13 = V_4 ;
* V_24 = V_21 - V_3 ;
* V_25 = V_13 - V_21 ;
return 1 ;
}
int F_28 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_31 , unsigned int V_23 ,
const char * V_36 ,
unsigned int * V_24 , unsigned int * V_25 ,
union V_11 * V_12 )
{
const char * V_4 = V_3 + V_23 ;
const char * V_21 , * V_13 ;
V_4 = F_21 ( V_3 + V_31 , V_4 , L_3 , strlen ( L_3 ) ) ;
if ( ! V_4 )
V_4 = V_3 + V_23 ;
V_21 = F_21 ( V_3 + V_31 , V_4 , V_36 , strlen ( V_36 ) ) ;
if ( ! V_21 )
return 0 ;
V_21 += strlen ( V_36 ) ;
if ( ! F_7 ( V_2 , V_21 , & V_13 , V_12 , V_4 ) )
return 0 ;
* V_24 = V_21 - V_3 ;
* V_25 = V_13 - V_21 ;
return 1 ;
}
int F_29 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_31 , unsigned int V_23 ,
const char * V_36 ,
unsigned int * V_24 , unsigned int * V_25 ,
unsigned int * V_43 )
{
const char * V_4 = V_3 + V_23 ;
const char * V_21 ;
char * V_13 ;
V_4 = F_21 ( V_3 + V_31 , V_4 , L_3 , strlen ( L_3 ) ) ;
if ( ! V_4 )
V_4 = V_3 + V_23 ;
V_21 = F_21 ( V_3 + V_31 , V_4 , V_36 , strlen ( V_36 ) ) ;
if ( ! V_21 )
return 0 ;
V_21 += strlen ( V_36 ) ;
* V_43 = F_17 ( V_21 , & V_13 , 0 ) ;
if ( V_21 == V_13 )
return 0 ;
if ( V_24 && V_25 ) {
* V_24 = V_21 - V_3 ;
* V_25 = V_13 - V_21 ;
}
return 1 ;
}
static int F_30 ( struct V_1 * V_2 , const char * V_3 ,
unsigned int V_31 , unsigned int V_23 ,
V_16 * V_44 )
{
unsigned int V_24 , V_25 ;
if ( F_27 ( V_2 , V_3 , V_31 , V_23 , L_5 ,
& V_24 , & V_25 ) ) {
if ( ! F_16 ( V_3 + V_24 , L_6 , strlen ( L_6 ) ) )
* V_44 = V_45 ;
else if ( ! F_16 ( V_3 + V_24 , L_7 , strlen ( L_7 ) ) )
* V_44 = V_46 ;
else
return 0 ;
if ( * V_44 != F_31 ( V_2 ) )
return 0 ;
} else
* V_44 = F_31 ( V_2 ) ;
return 1 ;
}
static const char * F_32 ( const char * V_3 , const char * V_4 ,
const char * V_30 , unsigned int V_6 )
{
for ( V_4 -= V_6 ; V_3 < V_4 ; V_3 ++ ) {
if ( * V_3 == '\r' || * V_3 == '\n' )
break;
if ( strncmp ( V_3 , V_30 , V_6 ) == 0 )
return V_3 ;
}
return NULL ;
}
int F_33 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_31 , unsigned int V_23 ,
enum V_47 type ,
enum V_47 V_48 ,
unsigned int * V_24 , unsigned int * V_25 )
{
const struct V_33 * V_34 = & V_49 [ type ] ;
const struct V_33 * V_50 = & V_49 [ V_48 ] ;
const char * V_21 = V_3 , * V_4 = V_3 + V_23 ;
int V_5 = 0 ;
for ( V_3 += V_31 ; V_3 < V_4 ; V_3 ++ ) {
if ( * V_3 != '\r' && * V_3 != '\n' )
continue;
if ( ++ V_3 >= V_4 )
break;
if ( * ( V_3 - 1 ) == '\r' && * V_3 == '\n' ) {
if ( ++ V_3 >= V_4 )
break;
}
if ( V_48 != V_51 &&
V_4 - V_3 >= V_50 -> V_6 &&
F_16 ( V_3 , V_50 -> V_36 , V_50 -> V_6 ) == 0 )
break;
else if ( V_4 - V_3 >= V_34 -> V_6 &&
F_16 ( V_3 , V_34 -> V_36 , V_34 -> V_6 ) == 0 )
V_3 += V_34 -> V_6 ;
else
continue;
* V_24 = V_3 - V_21 ;
if ( V_34 -> V_39 ) {
V_3 = F_32 ( V_3 , V_4 , V_34 -> V_39 ,
V_34 -> V_40 ) ;
if ( ! V_3 )
return - 1 ;
V_3 += V_34 -> V_40 ;
}
* V_25 = V_34 -> V_41 ( V_2 , V_3 , V_4 , & V_5 ) ;
if ( ! * V_25 )
return - 1 ;
* V_24 = V_3 - V_21 + V_5 ;
return 1 ;
}
return 0 ;
}
static int F_34 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_31 , unsigned int V_23 ,
enum V_47 type ,
enum V_47 V_48 ,
unsigned int * V_24 , unsigned int * V_25 ,
union V_11 * V_12 )
{
int V_14 ;
V_14 = F_33 ( V_2 , V_3 , V_31 , V_23 , type , V_48 ,
V_24 , V_25 ) ;
if ( V_14 <= 0 )
return V_14 ;
if ( ! F_7 ( V_2 , V_3 + * V_24 , NULL , V_12 ,
V_3 + * V_24 + * V_25 ) )
return - 1 ;
return 1 ;
}
static int F_35 ( struct V_1 * V_2 ,
union V_11 * V_12 ,
V_16 V_44 , T_1 V_26 ,
unsigned int V_52 )
{
struct V_53 * V_54 = F_36 ( V_2 ) ;
struct V_55 * exp ;
struct V_56 * V_57 , * V_58 ;
int V_59 = 0 ;
F_37 ( & V_60 ) ;
F_38 (exp, n, next, &help->expectations, lnode) {
if ( exp -> V_61 != V_62 ||
! F_39 ( & exp -> V_63 . V_64 . V_65 , V_12 ) ||
exp -> V_63 . V_64 . V_66 != V_44 ||
exp -> V_63 . V_64 . V_67 . V_68 . V_26 != V_26 )
continue;
if ( ! F_40 ( & exp -> V_69 ) )
continue;
exp -> V_70 &= ~ V_71 ;
exp -> V_69 . V_52 = V_72 + V_52 * V_73 ;
F_41 ( & exp -> V_69 ) ;
V_59 = 1 ;
break;
}
F_42 ( & V_60 ) ;
return V_59 ;
}
static void F_43 ( struct V_1 * V_2 , bool V_74 )
{
struct V_53 * V_54 = F_36 ( V_2 ) ;
struct V_55 * exp ;
struct V_56 * V_57 , * V_58 ;
F_37 ( & V_60 ) ;
F_38 (exp, n, next, &help->expectations, lnode) {
if ( ( exp -> V_61 != V_62 ) ^ V_74 )
continue;
if ( ! F_40 ( & exp -> V_69 ) )
continue;
F_44 ( exp ) ;
F_45 ( exp ) ;
if ( ! V_74 )
break;
}
F_42 ( & V_60 ) ;
}
static int F_46 ( struct V_75 * V_76 , unsigned int V_31 ,
const char * * V_3 , unsigned int * V_23 ,
union V_11 * V_77 , T_1 V_26 ,
enum V_78 V_61 ,
unsigned int V_79 , unsigned int V_80 )
{
struct V_55 * exp , * V_81 , * V_82 ;
enum V_83 V_84 ;
struct V_1 * V_2 = F_47 ( V_76 , & V_84 ) ;
struct V_85 * V_85 = F_48 ( V_2 ) ;
enum V_86 V_87 = F_49 ( V_84 ) ;
union V_11 * V_88 ;
struct V_89 V_63 ;
int V_90 = 0 , V_91 = 0 , V_14 = V_92 ;
T_2 V_93 ;
T_1 V_94 , V_95 ;
F_50 (nf_nat_sdp_port_hook) V_96 ;
F_50 (nf_nat_sdp_media_hook) V_97 ;
V_88 = NULL ;
if ( V_98 ) {
if ( ! F_39 ( V_77 , & V_2 -> V_99 [ V_87 ] . V_63 . V_100 . V_65 ) )
return V_101 ;
V_88 = & V_2 -> V_99 [ ! V_87 ] . V_63 . V_100 . V_65 ;
}
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
if ( V_88 )
V_63 . V_100 . V_65 = * V_88 ;
V_63 . V_100 . V_102 = F_8 ( V_2 ) ;
V_63 . V_64 . V_66 = V_46 ;
V_63 . V_64 . V_65 = * V_77 ;
V_63 . V_64 . V_67 . V_68 . V_26 = V_26 ;
F_51 () ;
do {
exp = F_52 ( V_85 , F_53 ( V_2 ) , & V_63 ) ;
if ( ! exp || exp -> V_103 == V_2 ||
F_36 ( exp -> V_103 ) -> V_104 != F_36 ( V_2 ) -> V_104 ||
exp -> V_61 != V_61 )
break;
#ifdef F_54
if ( exp -> V_63 . V_100 . V_102 == V_15 && ! V_90 &&
( exp -> V_105 != exp -> V_63 . V_64 . V_65 . V_17 ||
exp -> V_106 . V_68 . V_26 != exp -> V_63 . V_64 . V_67 . V_68 . V_26 ) &&
V_2 -> V_107 & V_108 ) {
V_77 -> V_17 = exp -> V_105 ;
V_63 . V_64 . V_65 . V_17 = exp -> V_105 ;
V_63 . V_64 . V_67 . V_68 . V_26 = exp -> V_106 . V_68 . V_26 ;
V_90 = 1 ;
} else
#endif
V_91 = 1 ;
} while ( ! V_91 );
F_55 () ;
V_93 = F_56 ( V_63 . V_64 . V_67 . V_68 . V_26 ) & ~ 1 ;
V_94 = F_18 ( V_93 ) ;
V_95 = F_18 ( V_93 + 1 ) ;
if ( V_90 ) {
V_96 = F_57 ( V_109 ) ;
if ( V_96 &&
! V_96 ( V_76 , V_31 , V_3 , V_23 ,
V_79 , V_80 , F_56 ( V_94 ) ) )
goto V_110;
}
if ( V_91 )
return V_101 ;
V_81 = F_58 ( V_2 ) ;
if ( V_81 == NULL )
goto V_110;
F_59 ( V_81 , V_61 , F_8 ( V_2 ) , V_88 , V_77 ,
V_46 , NULL , & V_94 ) ;
V_82 = F_58 ( V_2 ) ;
if ( V_82 == NULL )
goto V_111;
F_59 ( V_82 , V_61 , F_8 ( V_2 ) , V_88 , V_77 ,
V_46 , NULL , & V_95 ) ;
V_97 = F_57 ( V_112 ) ;
if ( V_97 && V_2 -> V_107 & V_108 && ! V_90 )
V_14 = V_97 ( V_76 , V_31 , V_3 , V_23 ,
V_81 , V_82 ,
V_79 , V_80 , V_77 ) ;
else {
if ( F_60 ( V_81 ) == 0 ) {
if ( F_60 ( V_82 ) != 0 )
F_61 ( V_81 ) ;
else
V_14 = V_101 ;
}
}
F_45 ( V_82 ) ;
V_111:
F_45 ( V_81 ) ;
V_110:
return V_14 ;
}
static const struct V_113 * V_113 ( const char * V_3 ,
unsigned int V_24 ,
unsigned int V_25 )
{
const struct V_113 * V_114 ;
unsigned int V_115 ;
for ( V_115 = 0 ; V_115 < F_62 ( V_116 ) ; V_115 ++ ) {
V_114 = & V_116 [ V_115 ] ;
if ( V_25 < V_114 -> V_6 ||
strncmp ( V_3 + V_24 , V_114 -> V_36 , V_114 -> V_6 ) )
continue;
return V_114 ;
}
return NULL ;
}
static int F_63 ( struct V_75 * V_76 , unsigned int V_31 ,
const char * * V_3 , unsigned int * V_23 ,
unsigned int V_117 )
{
enum V_83 V_84 ;
struct V_1 * V_2 = F_47 ( V_76 , & V_84 ) ;
unsigned int V_24 , V_25 ;
unsigned int V_79 , V_80 ;
unsigned int V_118 ;
unsigned int V_119 , V_120 ;
unsigned int V_115 ;
union V_11 V_121 , V_122 , V_123 ;
unsigned int V_26 ;
enum V_47 V_124 ;
const struct V_113 * V_114 ;
int V_14 = V_101 ;
F_50 (nf_nat_sdp_addr_hook) V_125 ;
F_50 (nf_nat_sdp_session_hook) V_126 ;
V_125 = F_57 ( V_127 ) ;
V_124 = F_8 ( V_2 ) == V_15 ? V_128 :
V_129 ;
if ( F_33 ( V_2 , * V_3 , 0 , * V_23 ,
V_130 , V_51 ,
& V_24 , & V_25 ) <= 0 )
return V_101 ;
V_118 = V_24 ;
V_119 = 0 ;
if ( F_34 ( V_2 , * V_3 , V_118 , * V_23 ,
V_124 , V_131 ,
& V_24 , & V_25 , & V_121 ) > 0 )
V_119 = V_25 ;
V_79 = V_118 ;
for ( V_115 = 0 ; V_115 < F_62 ( V_116 ) ; ) {
if ( F_33 ( V_2 , * V_3 , V_79 , * V_23 ,
V_131 , V_51 ,
& V_79 , & V_80 ) <= 0 )
break;
V_114 = V_113 ( * V_3 , V_79 , V_80 ) ;
if ( ! V_114 ) {
V_79 += V_80 ;
continue;
}
V_79 += V_114 -> V_6 ;
V_80 -= V_114 -> V_6 ;
V_26 = F_17 ( * V_3 + V_79 , NULL , 10 ) ;
if ( V_26 == 0 )
continue;
if ( V_26 < 1024 || V_26 > 65535 )
return V_92 ;
V_120 = 0 ;
if ( F_34 ( V_2 , * V_3 , V_79 , * V_23 ,
V_124 , V_131 ,
& V_24 , & V_25 , & V_122 ) > 0 ) {
V_120 = V_25 ;
memcpy ( & V_123 , & V_122 , sizeof( V_123 ) ) ;
} else if ( V_119 )
memcpy ( & V_123 , & V_121 , sizeof( V_123 ) ) ;
else
return V_92 ;
V_14 = F_46 ( V_76 , V_31 , V_3 , V_23 ,
& V_123 , F_18 ( V_26 ) , V_114 -> V_61 ,
V_79 , V_80 ) ;
if ( V_14 != V_101 )
return V_14 ;
if ( V_120 && V_125 && V_2 -> V_107 & V_108 ) {
V_14 = V_125 ( V_76 , V_31 , V_3 , V_23 ,
V_79 , V_124 , V_131 ,
& V_123 ) ;
if ( V_14 != V_101 )
return V_14 ;
}
V_115 ++ ;
}
V_126 = F_57 ( V_132 ) ;
if ( V_126 && V_2 -> V_107 & V_108 )
V_14 = V_126 ( V_76 , V_31 , V_3 , V_23 , V_118 ,
& V_123 ) ;
return V_14 ;
}
static int F_64 ( struct V_75 * V_76 , unsigned int V_31 ,
const char * * V_3 , unsigned int * V_23 ,
unsigned int V_117 , unsigned int V_133 )
{
enum V_83 V_84 ;
struct V_1 * V_2 = F_47 ( V_76 , & V_84 ) ;
struct V_53 * V_54 = F_36 ( V_2 ) ;
if ( ( V_133 >= 100 && V_133 <= 199 ) ||
( V_133 >= 200 && V_133 <= 299 ) )
return F_63 ( V_76 , V_31 , V_3 , V_23 , V_117 ) ;
else if ( V_54 -> V_54 . V_134 . V_135 == V_117 )
F_43 ( V_2 , true ) ;
return V_101 ;
}
static int F_65 ( struct V_75 * V_76 , unsigned int V_31 ,
const char * * V_3 , unsigned int * V_23 ,
unsigned int V_117 , unsigned int V_133 )
{
enum V_83 V_84 ;
struct V_1 * V_2 = F_47 ( V_76 , & V_84 ) ;
struct V_53 * V_54 = F_36 ( V_2 ) ;
if ( ( V_133 >= 100 && V_133 <= 199 ) ||
( V_133 >= 200 && V_133 <= 299 ) )
return F_63 ( V_76 , V_31 , V_3 , V_23 , V_117 ) ;
else if ( V_54 -> V_54 . V_134 . V_135 == V_117 )
F_43 ( V_2 , true ) ;
return V_101 ;
}
static int F_66 ( struct V_75 * V_76 , unsigned int V_31 ,
const char * * V_3 , unsigned int * V_23 ,
unsigned int V_117 , unsigned int V_133 )
{
enum V_83 V_84 ;
struct V_1 * V_2 = F_47 ( V_76 , & V_84 ) ;
struct V_53 * V_54 = F_36 ( V_2 ) ;
if ( ( V_133 >= 100 && V_133 <= 199 ) ||
( V_133 >= 200 && V_133 <= 299 ) )
return F_63 ( V_76 , V_31 , V_3 , V_23 , V_117 ) ;
else if ( V_54 -> V_54 . V_134 . V_135 == V_117 )
F_43 ( V_2 , true ) ;
return V_101 ;
}
static int F_67 ( struct V_75 * V_76 , unsigned int V_31 ,
const char * * V_3 , unsigned int * V_23 ,
unsigned int V_117 )
{
enum V_83 V_84 ;
struct V_1 * V_2 = F_47 ( V_76 , & V_84 ) ;
struct V_53 * V_54 = F_36 ( V_2 ) ;
unsigned int V_14 ;
F_43 ( V_2 , true ) ;
V_14 = F_63 ( V_76 , V_31 , V_3 , V_23 , V_117 ) ;
if ( V_14 == V_101 )
V_54 -> V_54 . V_134 . V_135 = V_117 ;
return V_14 ;
}
static int F_68 ( struct V_75 * V_76 , unsigned int V_31 ,
const char * * V_3 , unsigned int * V_23 ,
unsigned int V_117 )
{
enum V_83 V_84 ;
struct V_1 * V_2 = F_47 ( V_76 , & V_84 ) ;
F_43 ( V_2 , true ) ;
return V_101 ;
}
static int F_69 ( struct V_75 * V_76 , unsigned int V_31 ,
const char * * V_3 , unsigned int * V_23 ,
unsigned int V_117 )
{
enum V_83 V_84 ;
struct V_1 * V_2 = F_47 ( V_76 , & V_84 ) ;
struct V_53 * V_54 = F_36 ( V_2 ) ;
enum V_86 V_87 = F_49 ( V_84 ) ;
unsigned int V_24 , V_25 ;
struct V_55 * exp ;
union V_11 * V_88 , V_77 ;
T_1 V_26 ;
V_16 V_44 ;
unsigned int V_52 = 0 ;
int V_14 ;
F_50 (nf_nat_sip_expect_hook) V_136 ;
if ( V_2 -> V_107 & V_137 )
return V_101 ;
if ( F_22 ( V_2 , * V_3 , 0 , * V_23 , V_138 ,
& V_24 , & V_25 ) > 0 )
V_52 = F_17 ( * V_3 + V_24 , NULL , 10 ) ;
V_14 = F_25 ( V_2 , * V_3 , NULL , * V_23 ,
V_139 , NULL ,
& V_24 , & V_25 , & V_77 , & V_26 ) ;
if ( V_14 < 0 )
return V_92 ;
else if ( V_14 == 0 )
return V_101 ;
if ( ! F_39 ( & V_2 -> V_99 [ V_87 ] . V_63 . V_100 . V_65 , & V_77 ) )
return V_101 ;
if ( F_30 ( V_2 , * V_3 , V_24 + V_25 , * V_23 ,
& V_44 ) == 0 )
return V_101 ;
if ( F_29 ( V_2 , * V_3 ,
V_24 + V_25 , * V_23 ,
L_8 , NULL , NULL , & V_52 ) < 0 )
return V_92 ;
if ( V_52 == 0 ) {
V_14 = V_101 ;
goto V_140;
}
exp = F_58 ( V_2 ) ;
if ( ! exp )
return V_92 ;
V_88 = NULL ;
if ( V_141 )
V_88 = & V_2 -> V_99 [ ! V_87 ] . V_63 . V_100 . V_65 ;
F_59 ( exp , V_62 , F_8 ( V_2 ) ,
V_88 , & V_77 , V_44 , NULL , & V_26 ) ;
exp -> V_69 . V_52 = V_142 * V_73 ;
exp -> V_104 = F_36 ( V_2 ) -> V_104 ;
exp -> V_70 = V_143 | V_71 ;
V_136 = F_57 ( V_144 ) ;
if ( V_136 && V_2 -> V_107 & V_108 )
V_14 = V_136 ( V_76 , V_31 , V_3 , V_23 , exp ,
V_24 , V_25 ) ;
else {
if ( F_60 ( exp ) != 0 )
V_14 = V_92 ;
else
V_14 = V_101 ;
}
F_45 ( exp ) ;
V_140:
if ( V_14 == V_101 )
V_54 -> V_54 . V_134 . V_145 = V_117 ;
return V_14 ;
}
static int F_70 ( struct V_75 * V_76 , unsigned int V_31 ,
const char * * V_3 , unsigned int * V_23 ,
unsigned int V_117 , unsigned int V_133 )
{
enum V_83 V_84 ;
struct V_1 * V_2 = F_47 ( V_76 , & V_84 ) ;
struct V_53 * V_54 = F_36 ( V_2 ) ;
enum V_86 V_87 = F_49 ( V_84 ) ;
union V_11 V_12 ;
T_1 V_26 ;
V_16 V_44 ;
unsigned int V_24 , V_25 , V_146 = 0 ;
unsigned int V_52 = 0 ;
int V_147 = 0 , V_14 ;
if ( V_54 -> V_54 . V_134 . V_145 != V_117 )
return V_101 ;
if ( V_133 >= 100 && V_133 <= 199 )
return V_101 ;
if ( V_133 < 200 || V_133 > 299 )
goto V_148;
if ( F_22 ( V_2 , * V_3 , 0 , * V_23 , V_138 ,
& V_24 , & V_25 ) > 0 )
V_52 = F_17 ( * V_3 + V_24 , NULL , 10 ) ;
while ( 1 ) {
unsigned int V_149 = V_52 ;
V_14 = F_25 ( V_2 , * V_3 , & V_146 , * V_23 ,
V_139 , & V_147 ,
& V_24 , & V_25 ,
& V_12 , & V_26 ) ;
if ( V_14 < 0 )
return V_92 ;
else if ( V_14 == 0 )
break;
if ( ! F_39 ( & V_2 -> V_99 [ V_87 ] . V_63 . V_64 . V_65 , & V_12 ) )
continue;
if ( F_30 ( V_2 , * V_3 , V_24 + V_25 ,
* V_23 , & V_44 ) == 0 )
continue;
V_14 = F_29 ( V_2 , * V_3 ,
V_24 + V_25 ,
* V_23 , L_8 ,
NULL , NULL , & V_149 ) ;
if ( V_14 < 0 )
return V_92 ;
if ( V_149 == 0 )
break;
if ( F_35 ( V_2 , & V_12 , V_44 , V_26 ,
V_149 ) )
return V_101 ;
}
V_148:
F_43 ( V_2 , false ) ;
return V_101 ;
}
static int F_71 ( struct V_75 * V_76 , unsigned int V_31 ,
const char * * V_3 , unsigned int * V_23 )
{
enum V_83 V_84 ;
struct V_1 * V_2 = F_47 ( V_76 , & V_84 ) ;
unsigned int V_24 , V_25 , V_150 ;
unsigned int V_133 , V_117 , V_115 ;
if ( * V_23 < strlen ( L_9 ) )
return V_101 ;
V_133 = F_17 ( * V_3 + strlen ( L_10 ) , NULL , 10 ) ;
if ( ! V_133 )
return V_92 ;
if ( F_22 ( V_2 , * V_3 , 0 , * V_23 , V_151 ,
& V_24 , & V_25 ) <= 0 )
return V_92 ;
V_117 = F_17 ( * V_3 + V_24 , NULL , 10 ) ;
if ( ! V_117 )
return V_92 ;
V_150 = V_24 + V_25 + 1 ;
for ( V_115 = 0 ; V_115 < F_62 ( V_152 ) ; V_115 ++ ) {
const struct V_153 * V_154 ;
V_154 = & V_152 [ V_115 ] ;
if ( V_154 -> V_155 == NULL )
continue;
if ( * V_23 < V_150 + V_154 -> V_6 ||
F_16 ( * V_3 + V_150 , V_154 -> V_156 , V_154 -> V_6 ) )
continue;
return V_154 -> V_155 ( V_76 , V_31 , V_3 , V_23 ,
V_117 , V_133 ) ;
}
return V_101 ;
}
static int F_72 ( struct V_75 * V_76 , unsigned int V_31 ,
const char * * V_3 , unsigned int * V_23 )
{
enum V_83 V_84 ;
struct V_1 * V_2 = F_47 ( V_76 , & V_84 ) ;
unsigned int V_24 , V_25 ;
unsigned int V_117 , V_115 ;
for ( V_115 = 0 ; V_115 < F_62 ( V_152 ) ; V_115 ++ ) {
const struct V_153 * V_154 ;
V_154 = & V_152 [ V_115 ] ;
if ( V_154 -> V_157 == NULL )
continue;
if ( * V_23 < V_154 -> V_6 ||
F_16 ( * V_3 , V_154 -> V_156 , V_154 -> V_6 ) )
continue;
if ( F_22 ( V_2 , * V_3 , 0 , * V_23 , V_151 ,
& V_24 , & V_25 ) <= 0 )
return V_92 ;
V_117 = F_17 ( * V_3 + V_24 , NULL , 10 ) ;
if ( ! V_117 )
return V_92 ;
return V_154 -> V_157 ( V_76 , V_31 , V_3 , V_23 , V_117 ) ;
}
return V_101 ;
}
static int F_73 ( struct V_75 * V_76 , struct V_1 * V_2 ,
unsigned int V_31 , const char * * V_3 ,
unsigned int * V_23 )
{
F_50 (nf_nat_sip_hook) V_158 ;
int V_14 ;
if ( F_16 ( * V_3 , L_10 , strlen ( L_10 ) ) != 0 )
V_14 = F_72 ( V_76 , V_31 , V_3 , V_23 ) ;
else
V_14 = F_71 ( V_76 , V_31 , V_3 , V_23 ) ;
if ( V_14 == V_101 && V_2 -> V_107 & V_108 ) {
V_158 = F_57 ( V_159 ) ;
if ( V_158 && ! V_158 ( V_76 , V_31 , V_3 , V_23 ) )
V_14 = V_92 ;
}
return V_14 ;
}
static int F_74 ( struct V_75 * V_76 , unsigned int V_160 ,
struct V_1 * V_2 , enum V_83 V_84 )
{
struct V_161 * V_162 , V_163 ;
unsigned int V_31 , V_23 ;
unsigned int V_24 , V_25 , V_38 ;
unsigned int V_164 , V_165 ;
const char * V_3 , * V_13 ;
T_3 V_166 , V_167 = 0 ;
int V_14 = V_101 ;
bool V_48 ;
F_50 (nf_nat_sip_seq_adjust_hook) V_168 ;
if ( V_84 != V_169 &&
V_84 != V_170 )
return V_101 ;
V_162 = F_75 ( V_76 , V_160 , sizeof( V_163 ) , & V_163 ) ;
if ( V_162 == NULL )
return V_101 ;
V_31 = V_160 + V_162 -> V_171 * 4 ;
if ( V_31 >= V_76 -> V_6 )
return V_101 ;
F_76 ( V_2 , V_76 , V_142 * V_73 ) ;
if ( F_77 ( F_78 ( V_76 ) ) )
return V_92 ;
V_3 = V_76 -> V_172 + V_31 ;
V_23 = V_76 -> V_6 - V_31 ;
if ( V_23 < strlen ( L_9 ) )
return V_101 ;
while ( 1 ) {
if ( F_22 ( V_2 , V_3 , 0 , V_23 ,
V_173 ,
& V_24 , & V_25 ) <= 0 )
break;
V_38 = F_17 ( V_3 + V_24 , ( char * * ) & V_13 , 10 ) ;
if ( V_3 + V_24 == V_13 )
break;
V_48 = false ;
for (; V_13 + strlen ( L_11 ) <= V_3 + V_23 ; V_13 ++ ) {
if ( V_13 [ 0 ] == '\r' && V_13 [ 1 ] == '\n' &&
V_13 [ 2 ] == '\r' && V_13 [ 3 ] == '\n' ) {
V_48 = true ;
break;
}
}
if ( ! V_48 )
break;
V_13 += strlen ( L_11 ) + V_38 ;
V_164 = V_165 = V_13 - V_3 ;
if ( V_164 > V_23 )
return V_92 ;
V_14 = F_73 ( V_76 , V_2 , V_31 , & V_3 , & V_164 ) ;
if ( V_14 != V_101 )
break;
V_166 = V_164 - V_165 ;
V_167 += V_166 ;
V_31 += V_164 ;
V_3 += V_164 ;
V_23 = V_23 + V_166 - V_164 ;
}
if ( V_14 == V_101 && V_2 -> V_107 & V_108 ) {
V_168 = F_57 ( V_174 ) ;
if ( V_168 )
V_168 ( V_76 , V_167 ) ;
}
return V_14 ;
}
static int F_79 ( struct V_75 * V_76 , unsigned int V_160 ,
struct V_1 * V_2 , enum V_83 V_84 )
{
unsigned int V_31 , V_23 ;
const char * V_3 ;
V_31 = V_160 + sizeof( struct V_175 ) ;
if ( V_31 >= V_76 -> V_6 )
return V_101 ;
F_76 ( V_2 , V_76 , V_142 * V_73 ) ;
if ( F_77 ( F_78 ( V_76 ) ) )
return V_92 ;
V_3 = V_76 -> V_172 + V_31 ;
V_23 = V_76 -> V_6 - V_31 ;
if ( V_23 < strlen ( L_9 ) )
return V_101 ;
return F_73 ( V_76 , V_2 , V_31 , & V_3 , & V_23 ) ;
}
static void F_80 ( void )
{
int V_115 , V_176 ;
for ( V_115 = 0 ; V_115 < V_177 ; V_115 ++ ) {
for ( V_176 = 0 ; V_176 < F_62 ( V_178 [ V_115 ] ) ; V_176 ++ ) {
if ( V_178 [ V_115 ] [ V_176 ] . V_179 == NULL )
continue;
F_81 ( & V_178 [ V_115 ] [ V_176 ] ) ;
}
}
}
static int T_4 F_82 ( void )
{
int V_115 , V_176 , V_14 ;
char * V_180 ;
if ( V_177 == 0 )
V_181 [ V_177 ++ ] = V_29 ;
for ( V_115 = 0 ; V_115 < V_177 ; V_115 ++ ) {
memset ( & V_178 [ V_115 ] , 0 , sizeof( V_178 [ V_115 ] ) ) ;
V_178 [ V_115 ] [ 0 ] . V_63 . V_100 . V_102 = V_15 ;
V_178 [ V_115 ] [ 0 ] . V_63 . V_64 . V_66 = V_46 ;
V_178 [ V_115 ] [ 0 ] . V_54 = F_79 ;
V_178 [ V_115 ] [ 1 ] . V_63 . V_100 . V_102 = V_15 ;
V_178 [ V_115 ] [ 1 ] . V_63 . V_64 . V_66 = V_45 ;
V_178 [ V_115 ] [ 1 ] . V_54 = F_74 ;
V_178 [ V_115 ] [ 2 ] . V_63 . V_100 . V_102 = V_18 ;
V_178 [ V_115 ] [ 2 ] . V_63 . V_64 . V_66 = V_46 ;
V_178 [ V_115 ] [ 2 ] . V_54 = F_79 ;
V_178 [ V_115 ] [ 3 ] . V_63 . V_100 . V_102 = V_18 ;
V_178 [ V_115 ] [ 3 ] . V_63 . V_64 . V_66 = V_45 ;
V_178 [ V_115 ] [ 3 ] . V_54 = F_74 ;
for ( V_176 = 0 ; V_176 < F_62 ( V_178 [ V_115 ] ) ; V_176 ++ ) {
V_178 [ V_115 ] [ V_176 ] . V_63 . V_100 . V_67 . V_68 . V_26 = F_18 ( V_181 [ V_115 ] ) ;
V_178 [ V_115 ] [ V_176 ] . V_182 = V_183 ;
V_178 [ V_115 ] [ V_176 ] . V_184 = V_185 ;
V_178 [ V_115 ] [ V_176 ] . V_179 = V_186 ;
V_180 = & V_187 [ V_115 ] [ V_176 ] [ 0 ] ;
if ( V_181 [ V_115 ] == V_29 )
sprintf ( V_180 , L_12 ) ;
else
sprintf ( V_180 , L_13 , V_115 ) ;
V_178 [ V_115 ] [ V_176 ] . V_36 = V_180 ;
F_13 ( L_14 , V_115 , V_181 [ V_115 ] ) ;
V_14 = F_83 ( & V_178 [ V_115 ] [ V_176 ] ) ;
if ( V_14 ) {
F_84 ( V_188 L_15
L_16 ,
V_178 [ V_115 ] [ V_176 ] . V_63 . V_100 . V_102 , V_181 [ V_115 ] ) ;
F_80 () ;
return V_14 ;
}
}
}
return 0 ;
}
