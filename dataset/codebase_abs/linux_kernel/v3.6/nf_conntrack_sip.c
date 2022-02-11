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
const char * V_4 , bool V_13 )
{
const char * V_14 ;
int V_15 ;
if ( ! V_2 )
return 0 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
switch ( F_8 ( V_2 ) ) {
case V_16 :
V_15 = F_9 ( V_9 , V_4 - V_9 , ( V_17 * ) & V_12 -> V_18 , - 1 , & V_14 ) ;
if ( V_15 == 0 )
return 0 ;
break;
case V_19 :
if ( V_9 < V_4 && * V_9 == '[' )
V_9 ++ ;
else if ( V_13 )
return 0 ;
V_15 = F_10 ( V_9 , V_4 - V_9 , ( V_17 * ) & V_12 -> V_20 , - 1 , & V_14 ) ;
if ( V_15 == 0 )
return 0 ;
if ( V_14 < V_4 && * V_14 == ']' )
V_14 ++ ;
else if ( V_13 )
return 0 ;
break;
default:
F_11 () ;
}
if ( V_10 )
* V_10 = V_14 ;
return 1 ;
}
static int F_12 ( const struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , int * V_5 )
{
union V_11 V_12 ;
const char * V_21 = V_3 ;
if ( ! F_7 ( V_2 , V_3 , & V_3 , & V_12 , V_4 , true ) ) {
F_13 ( L_1 , V_3 ) ;
return 0 ;
}
if ( * V_3 == ':' ) {
V_3 ++ ;
V_3 += F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
}
return V_3 - V_21 ;
}
static int F_14 ( const struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , int * V_5 )
{
const char * V_22 = V_3 ;
int V_23 = * V_5 ;
while ( V_3 < V_4 &&
* V_3 != '@' && * V_3 != '\r' && * V_3 != '\n' ) {
( * V_5 ) ++ ;
V_3 ++ ;
}
if ( V_3 < V_4 && * V_3 == '@' ) {
V_3 ++ ;
( * V_5 ) ++ ;
} else {
V_3 = V_22 ;
* V_5 = V_23 ;
}
return F_12 ( V_2 , V_3 , V_4 , V_5 ) ;
}
int F_15 ( const struct V_1 * V_2 ,
const char * V_3 , unsigned int V_24 ,
unsigned int * V_25 , unsigned int * V_26 ,
union V_11 * V_12 , T_1 * V_27 )
{
const char * V_22 = V_3 , * V_4 = V_3 + V_24 , * V_14 ;
unsigned int V_28 ;
unsigned int V_29 ;
int V_5 = 0 ;
V_28 = F_1 ( V_2 , V_3 , V_4 , NULL ) ;
if ( ! V_28 )
return 0 ;
V_3 += V_28 ;
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
if ( ! F_7 ( V_2 , V_3 , & V_14 , V_12 , V_4 , true ) )
return - 1 ;
if ( V_14 < V_4 && * V_14 == ':' ) {
V_14 ++ ;
V_29 = F_17 ( V_14 , ( char * * ) & V_14 , 10 ) ;
if ( V_29 < 1024 || V_29 > 65535 )
return - 1 ;
* V_27 = F_18 ( V_29 ) ;
} else
* V_27 = F_18 ( V_30 ) ;
if ( V_14 == V_3 )
return 0 ;
* V_25 = V_3 - V_22 ;
* V_26 = V_14 - V_3 ;
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
const char * V_31 , unsigned int V_6 )
{
for ( V_4 -= V_6 ; V_3 < V_4 ; V_3 ++ ) {
if ( * V_3 == '\r' || * V_3 == '\n' ) {
V_3 = F_19 ( V_3 , V_4 ) ;
if ( V_3 == NULL )
break;
continue;
}
if ( F_16 ( V_3 , V_31 , V_6 ) == 0 )
return V_3 ;
}
return NULL ;
}
int F_22 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_32 , unsigned int V_24 ,
enum V_33 type ,
unsigned int * V_25 , unsigned int * V_26 )
{
const struct V_34 * V_35 = & V_36 [ type ] ;
const char * V_22 = V_3 , * V_4 = V_3 + V_24 ;
int V_5 = 0 ;
for ( V_3 += V_32 ; V_3 < V_4 ; V_3 ++ ) {
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
if ( V_4 - V_3 >= V_35 -> V_6 &&
F_16 ( V_3 , V_35 -> V_37 , V_35 -> V_6 ) == 0 )
V_3 += V_35 -> V_6 ;
else if ( V_35 -> V_38 && V_4 - V_3 >= V_35 -> V_39 + 1 &&
F_16 ( V_3 , V_35 -> V_38 , V_35 -> V_39 ) == 0 &&
! isalpha ( * ( V_3 + V_35 -> V_39 ) ) )
V_3 += V_35 -> V_39 ;
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
* V_25 = V_3 - V_22 ;
if ( V_35 -> V_40 ) {
V_3 = F_21 ( V_3 , V_4 , V_35 -> V_40 ,
V_35 -> V_41 ) ;
if ( ! V_3 )
return - 1 ;
V_3 += V_35 -> V_41 ;
}
* V_26 = V_35 -> V_42 ( V_2 , V_3 , V_4 , & V_5 ) ;
if ( ! * V_26 )
return - 1 ;
* V_25 = V_3 - V_22 + V_5 ;
return 1 ;
}
return 0 ;
}
static int F_23 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_32 , unsigned int V_24 ,
enum V_33 type ,
unsigned int * V_25 , unsigned int * V_26 )
{
const struct V_34 * V_35 = & V_36 [ type ] ;
const char * V_22 = V_3 , * V_4 = V_3 + V_24 ;
int V_5 = 0 ;
V_3 += V_32 ;
V_3 = F_21 ( V_3 , V_4 , L_3 , strlen ( L_3 ) ) ;
if ( ! V_3 )
return 0 ;
V_3 = F_21 ( V_3 , V_4 , V_35 -> V_40 , V_35 -> V_41 ) ;
if ( ! V_3 )
return 0 ;
V_3 += V_35 -> V_41 ;
* V_25 = V_3 - V_22 ;
* V_26 = V_35 -> V_42 ( V_2 , V_3 , V_4 , & V_5 ) ;
if ( ! * V_26 )
return - 1 ;
* V_25 += V_5 ;
return 1 ;
}
static int F_24 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_32 , unsigned int V_24 ,
enum V_33 type , int * V_43 ,
unsigned int * V_25 , unsigned int * V_26 )
{
int V_15 ;
if ( V_43 && * V_43 ) {
while ( 1 ) {
V_15 = F_23 ( V_2 , V_3 , V_32 , V_24 ,
type , V_25 , V_26 ) ;
if ( V_15 > 0 )
return V_15 ;
if ( V_15 == 0 )
break;
V_32 += * V_25 ;
}
* V_43 = 0 ;
}
while ( 1 ) {
V_15 = F_22 ( V_2 , V_3 , V_32 , V_24 ,
type , V_25 , V_26 ) ;
if ( V_15 > 0 )
break;
if ( V_15 == 0 )
return V_15 ;
V_32 += * V_25 ;
}
if ( V_43 )
* V_43 = 1 ;
return 1 ;
}
int F_25 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int * V_32 , unsigned int V_24 ,
enum V_33 type , int * V_43 ,
unsigned int * V_25 , unsigned int * V_26 ,
union V_11 * V_12 , T_1 * V_27 )
{
const char * V_7 , * V_4 = V_3 + V_24 ;
unsigned int V_29 ;
int V_15 ;
V_15 = F_24 ( V_2 , V_3 , V_32 ? * V_32 : 0 , V_24 ,
type , V_43 , V_25 , V_26 ) ;
F_26 ( V_15 < 0 ) ;
if ( V_15 == 0 )
return V_15 ;
if ( ! F_7 ( V_2 , V_3 + * V_25 , & V_7 , V_12 , V_4 , true ) )
return - 1 ;
if ( * V_7 == ':' ) {
V_7 ++ ;
V_29 = F_17 ( V_7 , ( char * * ) & V_7 , 10 ) ;
if ( V_29 < 1024 || V_29 > 65535 )
return - 1 ;
* V_27 = F_18 ( V_29 ) ;
} else
* V_27 = F_18 ( V_30 ) ;
if ( V_32 )
* V_32 = V_7 - V_3 ;
return 1 ;
}
static int F_27 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_32 , unsigned int V_24 ,
const char * V_37 ,
unsigned int * V_25 , unsigned int * V_26 )
{
const char * V_4 = V_3 + V_24 ;
const char * V_22 ;
const char * V_14 ;
V_4 = F_21 ( V_3 + V_32 , V_4 , L_3 , strlen ( L_3 ) ) ;
if ( ! V_4 )
V_4 = V_3 + V_24 ;
V_22 = F_21 ( V_3 + V_32 , V_4 , V_37 , strlen ( V_37 ) ) ;
if ( ! V_22 )
return 0 ;
V_22 += strlen ( V_37 ) ;
V_14 = F_21 ( V_22 , V_4 , L_4 , strlen ( L_4 ) ) ;
if ( ! V_14 )
V_14 = V_4 ;
* V_25 = V_22 - V_3 ;
* V_26 = V_14 - V_22 ;
return 1 ;
}
int F_28 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_32 , unsigned int V_24 ,
const char * V_37 ,
unsigned int * V_25 , unsigned int * V_26 ,
union V_11 * V_12 , bool V_13 )
{
const char * V_4 = V_3 + V_24 ;
const char * V_22 , * V_14 ;
V_4 = F_21 ( V_3 + V_32 , V_4 , L_3 , strlen ( L_3 ) ) ;
if ( ! V_4 )
V_4 = V_3 + V_24 ;
V_22 = F_21 ( V_3 + V_32 , V_4 , V_37 , strlen ( V_37 ) ) ;
if ( ! V_22 )
return 0 ;
V_22 += strlen ( V_37 ) ;
if ( ! F_7 ( V_2 , V_22 , & V_14 , V_12 , V_4 , V_13 ) )
return 0 ;
* V_25 = V_22 - V_3 ;
* V_26 = V_14 - V_22 ;
return 1 ;
}
int F_29 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_32 , unsigned int V_24 ,
const char * V_37 ,
unsigned int * V_25 , unsigned int * V_26 ,
unsigned int * V_44 )
{
const char * V_4 = V_3 + V_24 ;
const char * V_22 ;
char * V_14 ;
V_4 = F_21 ( V_3 + V_32 , V_4 , L_3 , strlen ( L_3 ) ) ;
if ( ! V_4 )
V_4 = V_3 + V_24 ;
V_22 = F_21 ( V_3 + V_32 , V_4 , V_37 , strlen ( V_37 ) ) ;
if ( ! V_22 )
return 0 ;
V_22 += strlen ( V_37 ) ;
* V_44 = F_17 ( V_22 , & V_14 , 0 ) ;
if ( V_22 == V_14 )
return 0 ;
if ( V_25 && V_26 ) {
* V_25 = V_22 - V_3 ;
* V_26 = V_14 - V_22 ;
}
return 1 ;
}
static int F_30 ( struct V_1 * V_2 , const char * V_3 ,
unsigned int V_32 , unsigned int V_24 ,
V_17 * V_45 )
{
unsigned int V_25 , V_26 ;
if ( F_27 ( V_2 , V_3 , V_32 , V_24 , L_5 ,
& V_25 , & V_26 ) ) {
if ( ! F_16 ( V_3 + V_25 , L_6 , strlen ( L_6 ) ) )
* V_45 = V_46 ;
else if ( ! F_16 ( V_3 + V_25 , L_7 , strlen ( L_7 ) ) )
* V_45 = V_47 ;
else
return 0 ;
if ( * V_45 != F_31 ( V_2 ) )
return 0 ;
} else
* V_45 = F_31 ( V_2 ) ;
return 1 ;
}
static int F_32 ( const struct V_1 * V_2 , const char * V_9 ,
const char * * V_10 , union V_11 * V_12 ,
const char * V_4 )
{
const char * V_14 ;
int V_15 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
switch ( F_8 ( V_2 ) ) {
case V_16 :
V_15 = F_9 ( V_9 , V_4 - V_9 , ( V_17 * ) & V_12 -> V_18 , - 1 , & V_14 ) ;
break;
case V_19 :
V_15 = F_10 ( V_9 , V_4 - V_9 , ( V_17 * ) & V_12 -> V_20 , - 1 , & V_14 ) ;
break;
default:
F_11 () ;
}
if ( V_15 == 0 )
return 0 ;
if ( V_10 )
* V_10 = V_14 ;
return 1 ;
}
static int F_33 ( const struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , int * V_5 )
{
union V_11 V_12 ;
const char * V_21 = V_3 ;
if ( ! F_32 ( V_2 , V_3 , & V_3 , & V_12 , V_4 ) ) {
F_13 ( L_1 , V_3 ) ;
return 0 ;
}
return V_3 - V_21 ;
}
static const char * F_34 ( const char * V_3 , const char * V_4 ,
const char * V_31 , unsigned int V_6 )
{
for ( V_4 -= V_6 ; V_3 < V_4 ; V_3 ++ ) {
if ( * V_3 == '\r' || * V_3 == '\n' )
break;
if ( strncmp ( V_3 , V_31 , V_6 ) == 0 )
return V_3 ;
}
return NULL ;
}
int F_35 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_32 , unsigned int V_24 ,
enum V_48 type ,
enum V_48 V_49 ,
unsigned int * V_25 , unsigned int * V_26 )
{
const struct V_34 * V_35 = & V_50 [ type ] ;
const struct V_34 * V_51 = & V_50 [ V_49 ] ;
const char * V_22 = V_3 , * V_4 = V_3 + V_24 ;
int V_5 = 0 ;
for ( V_3 += V_32 ; V_3 < V_4 ; V_3 ++ ) {
if ( * V_3 != '\r' && * V_3 != '\n' )
continue;
if ( ++ V_3 >= V_4 )
break;
if ( * ( V_3 - 1 ) == '\r' && * V_3 == '\n' ) {
if ( ++ V_3 >= V_4 )
break;
}
if ( V_49 != V_52 &&
V_4 - V_3 >= V_51 -> V_6 &&
F_16 ( V_3 , V_51 -> V_37 , V_51 -> V_6 ) == 0 )
break;
else if ( V_4 - V_3 >= V_35 -> V_6 &&
F_16 ( V_3 , V_35 -> V_37 , V_35 -> V_6 ) == 0 )
V_3 += V_35 -> V_6 ;
else
continue;
* V_25 = V_3 - V_22 ;
if ( V_35 -> V_40 ) {
V_3 = F_34 ( V_3 , V_4 , V_35 -> V_40 ,
V_35 -> V_41 ) ;
if ( ! V_3 )
return - 1 ;
V_3 += V_35 -> V_41 ;
}
* V_26 = V_35 -> V_42 ( V_2 , V_3 , V_4 , & V_5 ) ;
if ( ! * V_26 )
return - 1 ;
* V_25 = V_3 - V_22 + V_5 ;
return 1 ;
}
return 0 ;
}
static int F_36 ( const struct V_1 * V_2 , const char * V_3 ,
unsigned int V_32 , unsigned int V_24 ,
enum V_48 type ,
enum V_48 V_49 ,
unsigned int * V_25 , unsigned int * V_26 ,
union V_11 * V_12 )
{
int V_15 ;
V_15 = F_35 ( V_2 , V_3 , V_32 , V_24 , type , V_49 ,
V_25 , V_26 ) ;
if ( V_15 <= 0 )
return V_15 ;
if ( ! F_32 ( V_2 , V_3 + * V_25 , NULL , V_12 ,
V_3 + * V_25 + * V_26 ) )
return - 1 ;
return 1 ;
}
static int F_37 ( struct V_1 * V_2 ,
union V_11 * V_12 ,
V_17 V_45 , T_1 V_27 ,
unsigned int V_53 )
{
struct V_54 * V_55 = F_38 ( V_2 ) ;
struct V_56 * exp ;
struct V_57 * V_58 , * V_59 ;
int V_60 = 0 ;
F_39 ( & V_61 ) ;
F_40 (exp, n, next, &help->expectations, lnode) {
if ( exp -> V_62 != V_63 ||
! F_41 ( & exp -> V_64 . V_65 . V_66 , V_12 ) ||
exp -> V_64 . V_65 . V_67 != V_45 ||
exp -> V_64 . V_65 . V_68 . V_69 . V_27 != V_27 )
continue;
if ( ! F_42 ( & exp -> V_70 ) )
continue;
exp -> V_71 &= ~ V_72 ;
exp -> V_70 . V_53 = V_73 + V_53 * V_74 ;
F_43 ( & exp -> V_70 ) ;
V_60 = 1 ;
break;
}
F_44 ( & V_61 ) ;
return V_60 ;
}
static void F_45 ( struct V_1 * V_2 , bool V_75 )
{
struct V_54 * V_55 = F_38 ( V_2 ) ;
struct V_56 * exp ;
struct V_57 * V_58 , * V_59 ;
F_39 ( & V_61 ) ;
F_40 (exp, n, next, &help->expectations, lnode) {
if ( ( exp -> V_62 != V_63 ) ^ V_75 )
continue;
if ( ! F_42 ( & exp -> V_70 ) )
continue;
F_46 ( exp ) ;
F_47 ( exp ) ;
if ( ! V_75 )
break;
}
F_44 ( & V_61 ) ;
}
static int F_48 ( struct V_76 * V_77 , unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
union V_11 * V_78 , T_1 V_27 ,
enum V_79 V_62 ,
unsigned int V_80 , unsigned int V_81 )
{
struct V_56 * exp , * V_82 , * V_83 ;
enum V_84 V_85 ;
struct V_1 * V_2 = F_49 ( V_77 , & V_85 ) ;
struct V_86 * V_86 = F_50 ( V_2 ) ;
enum V_87 V_88 = F_51 ( V_85 ) ;
union V_11 * V_89 ;
struct V_90 V_64 ;
int V_91 = 0 , V_92 = 0 , V_15 = V_93 ;
T_2 V_94 ;
T_1 V_95 , V_96 ;
F_52 (nf_nat_sdp_port_hook) V_97 ;
F_52 (nf_nat_sdp_media_hook) V_98 ;
V_89 = NULL ;
if ( V_99 ) {
if ( ! F_41 ( V_78 , & V_2 -> V_100 [ V_88 ] . V_64 . V_101 . V_66 ) )
return V_102 ;
V_89 = & V_2 -> V_100 [ ! V_88 ] . V_64 . V_101 . V_66 ;
}
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
if ( V_89 )
V_64 . V_101 . V_66 = * V_89 ;
V_64 . V_101 . V_103 = F_8 ( V_2 ) ;
V_64 . V_65 . V_67 = V_47 ;
V_64 . V_65 . V_66 = * V_78 ;
V_64 . V_65 . V_68 . V_69 . V_27 = V_27 ;
F_53 () ;
do {
exp = F_54 ( V_86 , F_55 ( V_2 ) , & V_64 ) ;
if ( ! exp || exp -> V_104 == V_2 ||
F_38 ( exp -> V_104 ) -> V_105 != F_38 ( V_2 ) -> V_105 ||
exp -> V_62 != V_62 )
break;
#ifdef F_56
if ( exp -> V_64 . V_101 . V_103 == V_16 && ! V_91 &&
( exp -> V_106 != exp -> V_64 . V_65 . V_66 . V_18 ||
exp -> V_107 . V_69 . V_27 != exp -> V_64 . V_65 . V_68 . V_69 . V_27 ) &&
V_2 -> V_108 & V_109 ) {
V_78 -> V_18 = exp -> V_106 ;
V_64 . V_65 . V_66 . V_18 = exp -> V_106 ;
V_64 . V_65 . V_68 . V_69 . V_27 = exp -> V_107 . V_69 . V_27 ;
V_91 = 1 ;
} else
#endif
V_92 = 1 ;
} while ( ! V_92 );
F_57 () ;
V_94 = F_58 ( V_64 . V_65 . V_68 . V_69 . V_27 ) & ~ 1 ;
V_95 = F_18 ( V_94 ) ;
V_96 = F_18 ( V_94 + 1 ) ;
if ( V_91 ) {
V_97 = F_59 ( V_110 ) ;
if ( V_97 &&
! V_97 ( V_77 , V_32 , V_3 , V_24 ,
V_80 , V_81 , F_58 ( V_95 ) ) )
goto V_111;
}
if ( V_92 )
return V_102 ;
V_82 = F_60 ( V_2 ) ;
if ( V_82 == NULL )
goto V_111;
F_61 ( V_82 , V_62 , F_8 ( V_2 ) , V_89 , V_78 ,
V_47 , NULL , & V_95 ) ;
V_83 = F_60 ( V_2 ) ;
if ( V_83 == NULL )
goto V_112;
F_61 ( V_83 , V_62 , F_8 ( V_2 ) , V_89 , V_78 ,
V_47 , NULL , & V_96 ) ;
V_98 = F_59 ( V_113 ) ;
if ( V_98 && V_2 -> V_108 & V_109 && ! V_91 )
V_15 = V_98 ( V_77 , V_32 , V_3 , V_24 ,
V_82 , V_83 ,
V_80 , V_81 , V_78 ) ;
else {
if ( F_62 ( V_82 ) == 0 ) {
if ( F_62 ( V_83 ) != 0 )
F_63 ( V_82 ) ;
else
V_15 = V_102 ;
}
}
F_47 ( V_83 ) ;
V_112:
F_47 ( V_82 ) ;
V_111:
return V_15 ;
}
static const struct V_114 * V_114 ( const char * V_3 ,
unsigned int V_25 ,
unsigned int V_26 )
{
const struct V_114 * V_115 ;
unsigned int V_116 ;
for ( V_116 = 0 ; V_116 < F_64 ( V_117 ) ; V_116 ++ ) {
V_115 = & V_117 [ V_116 ] ;
if ( V_26 < V_115 -> V_6 ||
strncmp ( V_3 + V_25 , V_115 -> V_37 , V_115 -> V_6 ) )
continue;
return V_115 ;
}
return NULL ;
}
static int F_65 ( struct V_76 * V_77 , unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_118 )
{
enum V_84 V_85 ;
struct V_1 * V_2 = F_49 ( V_77 , & V_85 ) ;
unsigned int V_25 , V_26 ;
unsigned int V_80 , V_81 ;
unsigned int V_119 ;
unsigned int V_120 , V_121 ;
unsigned int V_116 ;
union V_11 V_122 , V_123 , V_124 ;
unsigned int V_27 ;
enum V_48 V_125 ;
const struct V_114 * V_115 ;
int V_15 = V_102 ;
F_52 (nf_nat_sdp_addr_hook) V_126 ;
F_52 (nf_nat_sdp_session_hook) V_127 ;
V_126 = F_59 ( V_128 ) ;
V_125 = F_8 ( V_2 ) == V_16 ? V_129 :
V_130 ;
if ( F_35 ( V_2 , * V_3 , 0 , * V_24 ,
V_131 , V_52 ,
& V_25 , & V_26 ) <= 0 )
return V_102 ;
V_119 = V_25 ;
V_120 = 0 ;
if ( F_36 ( V_2 , * V_3 , V_119 , * V_24 ,
V_125 , V_132 ,
& V_25 , & V_26 , & V_122 ) > 0 )
V_120 = V_26 ;
V_80 = V_119 ;
for ( V_116 = 0 ; V_116 < F_64 ( V_117 ) ; ) {
if ( F_35 ( V_2 , * V_3 , V_80 , * V_24 ,
V_132 , V_52 ,
& V_80 , & V_81 ) <= 0 )
break;
V_115 = V_114 ( * V_3 , V_80 , V_81 ) ;
if ( ! V_115 ) {
V_80 += V_81 ;
continue;
}
V_80 += V_115 -> V_6 ;
V_81 -= V_115 -> V_6 ;
V_27 = F_17 ( * V_3 + V_80 , NULL , 10 ) ;
if ( V_27 == 0 )
continue;
if ( V_27 < 1024 || V_27 > 65535 )
return V_93 ;
V_121 = 0 ;
if ( F_36 ( V_2 , * V_3 , V_80 , * V_24 ,
V_125 , V_132 ,
& V_25 , & V_26 , & V_123 ) > 0 ) {
V_121 = V_26 ;
memcpy ( & V_124 , & V_123 , sizeof( V_124 ) ) ;
} else if ( V_120 )
memcpy ( & V_124 , & V_122 , sizeof( V_124 ) ) ;
else
return V_93 ;
V_15 = F_48 ( V_77 , V_32 , V_3 , V_24 ,
& V_124 , F_18 ( V_27 ) , V_115 -> V_62 ,
V_80 , V_81 ) ;
if ( V_15 != V_102 )
return V_15 ;
if ( V_121 && V_126 && V_2 -> V_108 & V_109 ) {
V_15 = V_126 ( V_77 , V_32 , V_3 , V_24 ,
V_80 , V_125 , V_132 ,
& V_124 ) ;
if ( V_15 != V_102 )
return V_15 ;
}
V_116 ++ ;
}
V_127 = F_59 ( V_133 ) ;
if ( V_127 && V_2 -> V_108 & V_109 )
V_15 = V_127 ( V_77 , V_32 , V_3 , V_24 , V_119 ,
& V_124 ) ;
return V_15 ;
}
static int F_66 ( struct V_76 * V_77 , unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_118 , unsigned int V_134 )
{
enum V_84 V_85 ;
struct V_1 * V_2 = F_49 ( V_77 , & V_85 ) ;
struct V_135 * V_136 = F_67 ( V_2 ) ;
if ( ( V_134 >= 100 && V_134 <= 199 ) ||
( V_134 >= 200 && V_134 <= 299 ) )
return F_65 ( V_77 , V_32 , V_3 , V_24 , V_118 ) ;
else if ( V_136 -> V_137 == V_118 )
F_45 ( V_2 , true ) ;
return V_102 ;
}
static int F_68 ( struct V_76 * V_77 , unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_118 , unsigned int V_134 )
{
enum V_84 V_85 ;
struct V_1 * V_2 = F_49 ( V_77 , & V_85 ) ;
struct V_135 * V_136 = F_67 ( V_2 ) ;
if ( ( V_134 >= 100 && V_134 <= 199 ) ||
( V_134 >= 200 && V_134 <= 299 ) )
return F_65 ( V_77 , V_32 , V_3 , V_24 , V_118 ) ;
else if ( V_136 -> V_137 == V_118 )
F_45 ( V_2 , true ) ;
return V_102 ;
}
static int F_69 ( struct V_76 * V_77 , unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_118 , unsigned int V_134 )
{
enum V_84 V_85 ;
struct V_1 * V_2 = F_49 ( V_77 , & V_85 ) ;
struct V_135 * V_136 = F_67 ( V_2 ) ;
if ( ( V_134 >= 100 && V_134 <= 199 ) ||
( V_134 >= 200 && V_134 <= 299 ) )
return F_65 ( V_77 , V_32 , V_3 , V_24 , V_118 ) ;
else if ( V_136 -> V_137 == V_118 )
F_45 ( V_2 , true ) ;
return V_102 ;
}
static int F_70 ( struct V_76 * V_77 , unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_118 )
{
enum V_84 V_85 ;
struct V_1 * V_2 = F_49 ( V_77 , & V_85 ) ;
struct V_135 * V_136 = F_67 ( V_2 ) ;
unsigned int V_15 ;
F_45 ( V_2 , true ) ;
V_15 = F_65 ( V_77 , V_32 , V_3 , V_24 , V_118 ) ;
if ( V_15 == V_102 )
V_136 -> V_137 = V_118 ;
return V_15 ;
}
static int F_71 ( struct V_76 * V_77 , unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_118 )
{
enum V_84 V_85 ;
struct V_1 * V_2 = F_49 ( V_77 , & V_85 ) ;
F_45 ( V_2 , true ) ;
return V_102 ;
}
static int F_72 ( struct V_76 * V_77 , unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_118 )
{
enum V_84 V_85 ;
struct V_1 * V_2 = F_49 ( V_77 , & V_85 ) ;
struct V_135 * V_136 = F_67 ( V_2 ) ;
enum V_87 V_88 = F_51 ( V_85 ) ;
unsigned int V_25 , V_26 ;
struct V_56 * exp ;
union V_11 * V_89 , V_78 ;
T_1 V_27 ;
V_17 V_45 ;
unsigned int V_53 = 0 ;
int V_15 ;
F_52 (nf_nat_sip_expect_hook) V_138 ;
if ( V_2 -> V_108 & V_139 )
return V_102 ;
if ( F_22 ( V_2 , * V_3 , 0 , * V_24 , V_140 ,
& V_25 , & V_26 ) > 0 )
V_53 = F_17 ( * V_3 + V_25 , NULL , 10 ) ;
V_15 = F_25 ( V_2 , * V_3 , NULL , * V_24 ,
V_141 , NULL ,
& V_25 , & V_26 , & V_78 , & V_27 ) ;
if ( V_15 < 0 )
return V_93 ;
else if ( V_15 == 0 )
return V_102 ;
if ( ! F_41 ( & V_2 -> V_100 [ V_88 ] . V_64 . V_101 . V_66 , & V_78 ) )
return V_102 ;
if ( F_30 ( V_2 , * V_3 , V_25 + V_26 , * V_24 ,
& V_45 ) == 0 )
return V_102 ;
if ( F_29 ( V_2 , * V_3 ,
V_25 + V_26 , * V_24 ,
L_8 , NULL , NULL , & V_53 ) < 0 )
return V_93 ;
if ( V_53 == 0 ) {
V_15 = V_102 ;
goto V_142;
}
exp = F_60 ( V_2 ) ;
if ( ! exp )
return V_93 ;
V_89 = NULL ;
if ( V_143 )
V_89 = & V_2 -> V_100 [ ! V_88 ] . V_64 . V_101 . V_66 ;
F_61 ( exp , V_63 , F_8 ( V_2 ) ,
V_89 , & V_78 , V_45 , NULL , & V_27 ) ;
exp -> V_70 . V_53 = V_144 * V_74 ;
exp -> V_105 = F_38 ( V_2 ) -> V_105 ;
exp -> V_71 = V_145 | V_72 ;
V_138 = F_59 ( V_146 ) ;
if ( V_138 && V_2 -> V_108 & V_109 )
V_15 = V_138 ( V_77 , V_32 , V_3 , V_24 , exp ,
V_25 , V_26 ) ;
else {
if ( F_62 ( exp ) != 0 )
V_15 = V_93 ;
else
V_15 = V_102 ;
}
F_47 ( exp ) ;
V_142:
if ( V_15 == V_102 )
V_136 -> V_147 = V_118 ;
return V_15 ;
}
static int F_73 ( struct V_76 * V_77 , unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_118 , unsigned int V_134 )
{
enum V_84 V_85 ;
struct V_1 * V_2 = F_49 ( V_77 , & V_85 ) ;
struct V_135 * V_136 = F_67 ( V_2 ) ;
enum V_87 V_88 = F_51 ( V_85 ) ;
union V_11 V_12 ;
T_1 V_27 ;
V_17 V_45 ;
unsigned int V_25 , V_26 , V_148 = 0 ;
unsigned int V_53 = 0 ;
int V_149 = 0 , V_15 ;
if ( V_136 -> V_147 != V_118 )
return V_102 ;
if ( V_134 >= 100 && V_134 <= 199 )
return V_102 ;
if ( V_134 < 200 || V_134 > 299 )
goto V_150;
if ( F_22 ( V_2 , * V_3 , 0 , * V_24 , V_140 ,
& V_25 , & V_26 ) > 0 )
V_53 = F_17 ( * V_3 + V_25 , NULL , 10 ) ;
while ( 1 ) {
unsigned int V_151 = V_53 ;
V_15 = F_25 ( V_2 , * V_3 , & V_148 , * V_24 ,
V_141 , & V_149 ,
& V_25 , & V_26 ,
& V_12 , & V_27 ) ;
if ( V_15 < 0 )
return V_93 ;
else if ( V_15 == 0 )
break;
if ( ! F_41 ( & V_2 -> V_100 [ V_88 ] . V_64 . V_65 . V_66 , & V_12 ) )
continue;
if ( F_30 ( V_2 , * V_3 , V_25 + V_26 ,
* V_24 , & V_45 ) == 0 )
continue;
V_15 = F_29 ( V_2 , * V_3 ,
V_25 + V_26 ,
* V_24 , L_8 ,
NULL , NULL , & V_151 ) ;
if ( V_15 < 0 )
return V_93 ;
if ( V_151 == 0 )
break;
if ( F_37 ( V_2 , & V_12 , V_45 , V_27 ,
V_151 ) )
return V_102 ;
}
V_150:
F_45 ( V_2 , false ) ;
return V_102 ;
}
static int F_74 ( struct V_76 * V_77 , unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 )
{
enum V_84 V_85 ;
struct V_1 * V_2 = F_49 ( V_77 , & V_85 ) ;
unsigned int V_25 , V_26 , V_152 ;
unsigned int V_134 , V_118 , V_116 ;
if ( * V_24 < strlen ( L_9 ) )
return V_102 ;
V_134 = F_17 ( * V_3 + strlen ( L_10 ) , NULL , 10 ) ;
if ( ! V_134 )
return V_93 ;
if ( F_22 ( V_2 , * V_3 , 0 , * V_24 , V_153 ,
& V_25 , & V_26 ) <= 0 )
return V_93 ;
V_118 = F_17 ( * V_3 + V_25 , NULL , 10 ) ;
if ( ! V_118 )
return V_93 ;
V_152 = V_25 + V_26 + 1 ;
for ( V_116 = 0 ; V_116 < F_64 ( V_154 ) ; V_116 ++ ) {
const struct V_155 * V_156 ;
V_156 = & V_154 [ V_116 ] ;
if ( V_156 -> V_157 == NULL )
continue;
if ( * V_24 < V_152 + V_156 -> V_6 ||
F_16 ( * V_3 + V_152 , V_156 -> V_158 , V_156 -> V_6 ) )
continue;
return V_156 -> V_157 ( V_77 , V_32 , V_3 , V_24 ,
V_118 , V_134 ) ;
}
return V_102 ;
}
static int F_75 ( struct V_76 * V_77 , unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 )
{
enum V_84 V_85 ;
struct V_1 * V_2 = F_49 ( V_77 , & V_85 ) ;
unsigned int V_25 , V_26 ;
unsigned int V_118 , V_116 ;
for ( V_116 = 0 ; V_116 < F_64 ( V_154 ) ; V_116 ++ ) {
const struct V_155 * V_156 ;
V_156 = & V_154 [ V_116 ] ;
if ( V_156 -> V_159 == NULL )
continue;
if ( * V_24 < V_156 -> V_6 ||
F_16 ( * V_3 , V_156 -> V_158 , V_156 -> V_6 ) )
continue;
if ( F_22 ( V_2 , * V_3 , 0 , * V_24 , V_153 ,
& V_25 , & V_26 ) <= 0 )
return V_93 ;
V_118 = F_17 ( * V_3 + V_25 , NULL , 10 ) ;
if ( ! V_118 )
return V_93 ;
return V_156 -> V_159 ( V_77 , V_32 , V_3 , V_24 , V_118 ) ;
}
return V_102 ;
}
static int F_76 ( struct V_76 * V_77 , struct V_1 * V_2 ,
unsigned int V_32 , const char * * V_3 ,
unsigned int * V_24 )
{
F_52 (nf_nat_sip_hook) V_160 ;
int V_15 ;
if ( F_16 ( * V_3 , L_10 , strlen ( L_10 ) ) != 0 )
V_15 = F_75 ( V_77 , V_32 , V_3 , V_24 ) ;
else
V_15 = F_74 ( V_77 , V_32 , V_3 , V_24 ) ;
if ( V_15 == V_102 && V_2 -> V_108 & V_109 ) {
V_160 = F_59 ( V_161 ) ;
if ( V_160 && ! V_160 ( V_77 , V_32 , V_3 , V_24 ) )
V_15 = V_93 ;
}
return V_15 ;
}
static int F_77 ( struct V_76 * V_77 , unsigned int V_162 ,
struct V_1 * V_2 , enum V_84 V_85 )
{
struct V_163 * V_164 , V_165 ;
unsigned int V_32 , V_24 ;
unsigned int V_25 , V_26 , V_39 ;
unsigned int V_166 , V_167 ;
const char * V_3 , * V_14 ;
T_3 V_168 , V_169 = 0 ;
int V_15 = V_102 ;
bool V_49 ;
F_52 (nf_nat_sip_seq_adjust_hook) V_170 ;
if ( V_85 != V_171 &&
V_85 != V_172 )
return V_102 ;
V_164 = F_78 ( V_77 , V_162 , sizeof( V_165 ) , & V_165 ) ;
if ( V_164 == NULL )
return V_102 ;
V_32 = V_162 + V_164 -> V_173 * 4 ;
if ( V_32 >= V_77 -> V_6 )
return V_102 ;
F_79 ( V_2 , V_77 , V_144 * V_74 ) ;
if ( F_80 ( F_81 ( V_77 ) ) )
return V_93 ;
V_3 = V_77 -> V_174 + V_32 ;
V_24 = V_77 -> V_6 - V_32 ;
if ( V_24 < strlen ( L_9 ) )
return V_102 ;
while ( 1 ) {
if ( F_22 ( V_2 , V_3 , 0 , V_24 ,
V_175 ,
& V_25 , & V_26 ) <= 0 )
break;
V_39 = F_17 ( V_3 + V_25 , ( char * * ) & V_14 , 10 ) ;
if ( V_3 + V_25 == V_14 )
break;
V_49 = false ;
for (; V_14 + strlen ( L_11 ) <= V_3 + V_24 ; V_14 ++ ) {
if ( V_14 [ 0 ] == '\r' && V_14 [ 1 ] == '\n' &&
V_14 [ 2 ] == '\r' && V_14 [ 3 ] == '\n' ) {
V_49 = true ;
break;
}
}
if ( ! V_49 )
break;
V_14 += strlen ( L_11 ) + V_39 ;
V_166 = V_167 = V_14 - V_3 ;
if ( V_166 > V_24 )
return V_93 ;
V_15 = F_76 ( V_77 , V_2 , V_32 , & V_3 , & V_166 ) ;
if ( V_15 != V_102 )
break;
V_168 = V_166 - V_167 ;
V_169 += V_168 ;
V_32 += V_166 ;
V_3 += V_166 ;
V_24 = V_24 + V_168 - V_166 ;
}
if ( V_15 == V_102 && V_2 -> V_108 & V_109 ) {
V_170 = F_59 ( V_176 ) ;
if ( V_170 )
V_170 ( V_77 , V_169 ) ;
}
return V_15 ;
}
static int F_82 ( struct V_76 * V_77 , unsigned int V_162 ,
struct V_1 * V_2 , enum V_84 V_85 )
{
unsigned int V_32 , V_24 ;
const char * V_3 ;
V_32 = V_162 + sizeof( struct V_177 ) ;
if ( V_32 >= V_77 -> V_6 )
return V_102 ;
F_79 ( V_2 , V_77 , V_144 * V_74 ) ;
if ( F_80 ( F_81 ( V_77 ) ) )
return V_93 ;
V_3 = V_77 -> V_174 + V_32 ;
V_24 = V_77 -> V_6 - V_32 ;
if ( V_24 < strlen ( L_9 ) )
return V_102 ;
return F_76 ( V_77 , V_2 , V_32 , & V_3 , & V_24 ) ;
}
static void F_83 ( void )
{
int V_116 , V_178 ;
for ( V_116 = 0 ; V_116 < V_179 ; V_116 ++ ) {
for ( V_178 = 0 ; V_178 < F_64 ( V_180 [ V_116 ] ) ; V_178 ++ ) {
if ( V_180 [ V_116 ] [ V_178 ] . V_181 == NULL )
continue;
F_84 ( & V_180 [ V_116 ] [ V_178 ] ) ;
}
}
}
static int T_4 F_85 ( void )
{
int V_116 , V_178 , V_15 ;
if ( V_179 == 0 )
V_182 [ V_179 ++ ] = V_30 ;
for ( V_116 = 0 ; V_116 < V_179 ; V_116 ++ ) {
memset ( & V_180 [ V_116 ] , 0 , sizeof( V_180 [ V_116 ] ) ) ;
V_180 [ V_116 ] [ 0 ] . V_64 . V_101 . V_103 = V_16 ;
V_180 [ V_116 ] [ 0 ] . V_64 . V_65 . V_67 = V_47 ;
V_180 [ V_116 ] [ 0 ] . V_55 = F_82 ;
V_180 [ V_116 ] [ 1 ] . V_64 . V_101 . V_103 = V_16 ;
V_180 [ V_116 ] [ 1 ] . V_64 . V_65 . V_67 = V_46 ;
V_180 [ V_116 ] [ 1 ] . V_55 = F_77 ;
V_180 [ V_116 ] [ 2 ] . V_64 . V_101 . V_103 = V_19 ;
V_180 [ V_116 ] [ 2 ] . V_64 . V_65 . V_67 = V_47 ;
V_180 [ V_116 ] [ 2 ] . V_55 = F_82 ;
V_180 [ V_116 ] [ 3 ] . V_64 . V_101 . V_103 = V_19 ;
V_180 [ V_116 ] [ 3 ] . V_64 . V_65 . V_67 = V_46 ;
V_180 [ V_116 ] [ 3 ] . V_55 = F_77 ;
for ( V_178 = 0 ; V_178 < F_64 ( V_180 [ V_116 ] ) ; V_178 ++ ) {
V_180 [ V_116 ] [ V_178 ] . V_183 = sizeof( struct V_135 ) ;
V_180 [ V_116 ] [ V_178 ] . V_64 . V_101 . V_68 . V_69 . V_27 = F_18 ( V_182 [ V_116 ] ) ;
V_180 [ V_116 ] [ V_178 ] . V_184 = V_185 ;
V_180 [ V_116 ] [ V_178 ] . V_186 = V_187 ;
V_180 [ V_116 ] [ V_178 ] . V_181 = V_188 ;
if ( V_182 [ V_116 ] == V_30 )
sprintf ( V_180 [ V_116 ] [ V_178 ] . V_37 , L_12 ) ;
else
sprintf ( V_180 [ V_116 ] [ V_178 ] . V_37 , L_13 , V_116 ) ;
F_13 ( L_14 , V_116 , V_182 [ V_116 ] ) ;
V_15 = F_86 ( & V_180 [ V_116 ] [ V_178 ] ) ;
if ( V_15 ) {
F_87 ( V_189 L_15
L_16 ,
V_180 [ V_116 ] [ V_178 ] . V_64 . V_101 . V_103 , V_182 [ V_116 ] ) ;
F_83 () ;
return V_15 ;
}
}
}
return 0 ;
}
