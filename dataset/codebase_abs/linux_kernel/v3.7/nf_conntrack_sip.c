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
const struct V_34 * V_50 , * V_35 , * V_51 ;
const char * V_22 = V_3 , * V_4 = V_3 + V_24 ;
int V_5 = 0 ;
V_50 = F_8 ( V_2 ) == V_52 ? V_53 : V_54 ;
V_35 = & V_50 [ type ] ;
V_51 = & V_50 [ V_49 ] ;
for ( V_3 += V_32 ; V_3 < V_4 ; V_3 ++ ) {
if ( * V_3 != '\r' && * V_3 != '\n' )
continue;
if ( ++ V_3 >= V_4 )
break;
if ( * ( V_3 - 1 ) == '\r' && * V_3 == '\n' ) {
if ( ++ V_3 >= V_4 )
break;
}
if ( V_49 != V_55 &&
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
unsigned int V_56 )
{
struct V_57 * V_58 = F_38 ( V_2 ) ;
struct V_59 * exp ;
struct V_60 * V_61 , * V_62 ;
int V_63 = 0 ;
F_39 ( & V_64 ) ;
F_40 (exp, n, next, &help->expectations, lnode) {
if ( exp -> V_65 != V_66 ||
! F_41 ( & exp -> V_67 . V_68 . V_69 , V_12 ) ||
exp -> V_67 . V_68 . V_70 != V_45 ||
exp -> V_67 . V_68 . V_71 . V_72 . V_27 != V_27 )
continue;
if ( ! F_42 ( & exp -> V_73 ) )
continue;
exp -> V_74 &= ~ V_75 ;
exp -> V_73 . V_56 = V_76 + V_56 * V_77 ;
F_43 ( & exp -> V_73 ) ;
V_63 = 1 ;
break;
}
F_44 ( & V_64 ) ;
return V_63 ;
}
static void F_45 ( struct V_1 * V_2 , bool V_78 )
{
struct V_57 * V_58 = F_38 ( V_2 ) ;
struct V_59 * exp ;
struct V_60 * V_61 , * V_62 ;
F_39 ( & V_64 ) ;
F_40 (exp, n, next, &help->expectations, lnode) {
if ( ( exp -> V_65 != V_66 ) ^ V_78 )
continue;
if ( ! F_42 ( & exp -> V_73 ) )
continue;
F_46 ( exp ) ;
F_47 ( exp ) ;
if ( ! V_78 )
break;
}
F_44 ( & V_64 ) ;
}
static int F_48 ( struct V_79 * V_80 , unsigned int V_81 ,
unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
union V_11 * V_82 , T_1 V_27 ,
enum V_83 V_65 ,
unsigned int V_84 , unsigned int V_85 )
{
struct V_59 * exp , * V_86 , * V_87 ;
enum V_88 V_89 ;
struct V_1 * V_2 = F_49 ( V_80 , & V_89 ) ;
struct V_90 * V_90 = F_50 ( V_2 ) ;
enum V_91 V_92 = F_51 ( V_89 ) ;
union V_11 * V_93 ;
struct V_94 V_67 ;
int V_95 = 0 , V_96 = 0 , V_15 = V_97 ;
T_2 V_98 ;
T_1 V_99 , V_100 ;
F_52 (nf_nat_sdp_port_hook) V_101 ;
F_52 (nf_nat_sdp_media_hook) V_102 ;
V_93 = NULL ;
if ( V_103 ) {
if ( ! F_41 ( V_82 , & V_2 -> V_104 [ V_92 ] . V_67 . V_105 . V_69 ) )
return V_106 ;
V_93 = & V_2 -> V_104 [ ! V_92 ] . V_67 . V_105 . V_69 ;
}
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
if ( V_93 )
V_67 . V_105 . V_69 = * V_93 ;
V_67 . V_105 . V_107 = F_8 ( V_2 ) ;
V_67 . V_68 . V_70 = V_47 ;
V_67 . V_68 . V_69 = * V_82 ;
V_67 . V_68 . V_71 . V_72 . V_27 = V_27 ;
F_53 () ;
do {
exp = F_54 ( V_90 , F_55 ( V_2 ) , & V_67 ) ;
if ( ! exp || exp -> V_108 == V_2 ||
F_38 ( exp -> V_108 ) -> V_109 != F_38 ( V_2 ) -> V_109 ||
exp -> V_65 != V_65 )
break;
#ifdef F_56
if ( ! V_95 &&
( ! F_41 ( & exp -> V_110 , & exp -> V_67 . V_68 . V_69 ) ||
exp -> V_111 . V_72 . V_27 != exp -> V_67 . V_68 . V_71 . V_72 . V_27 ) &&
V_2 -> V_112 & V_113 ) {
* V_82 = exp -> V_110 ;
V_67 . V_68 . V_69 = exp -> V_110 ;
V_67 . V_68 . V_71 . V_72 . V_27 = exp -> V_111 . V_72 . V_27 ;
V_95 = 1 ;
} else
#endif
V_96 = 1 ;
} while ( ! V_96 );
F_57 () ;
V_98 = F_58 ( V_67 . V_68 . V_71 . V_72 . V_27 ) & ~ 1 ;
V_99 = F_18 ( V_98 ) ;
V_100 = F_18 ( V_98 + 1 ) ;
if ( V_95 ) {
V_101 = F_59 ( V_114 ) ;
if ( V_101 &&
! V_101 ( V_80 , V_81 , V_32 , V_3 , V_24 ,
V_84 , V_85 , F_58 ( V_99 ) ) )
goto V_115;
}
if ( V_96 )
return V_106 ;
V_86 = F_60 ( V_2 ) ;
if ( V_86 == NULL )
goto V_115;
F_61 ( V_86 , V_65 , F_8 ( V_2 ) , V_93 , V_82 ,
V_47 , NULL , & V_99 ) ;
V_87 = F_60 ( V_2 ) ;
if ( V_87 == NULL )
goto V_116;
F_61 ( V_87 , V_65 , F_8 ( V_2 ) , V_93 , V_82 ,
V_47 , NULL , & V_100 ) ;
V_102 = F_59 ( V_117 ) ;
if ( V_102 && V_2 -> V_112 & V_113 && ! V_95 )
V_15 = V_102 ( V_80 , V_81 , V_32 , V_3 , V_24 ,
V_86 , V_87 ,
V_84 , V_85 , V_82 ) ;
else {
if ( F_62 ( V_86 ) == 0 ) {
if ( F_62 ( V_87 ) != 0 )
F_63 ( V_86 ) ;
else
V_15 = V_106 ;
}
}
F_47 ( V_87 ) ;
V_116:
F_47 ( V_86 ) ;
V_115:
return V_15 ;
}
static const struct V_118 * V_118 ( const char * V_3 ,
unsigned int V_25 ,
unsigned int V_26 )
{
const struct V_118 * V_119 ;
unsigned int V_120 ;
for ( V_120 = 0 ; V_120 < F_64 ( V_121 ) ; V_120 ++ ) {
V_119 = & V_121 [ V_120 ] ;
if ( V_26 < V_119 -> V_6 ||
strncmp ( V_3 + V_25 , V_119 -> V_37 , V_119 -> V_6 ) )
continue;
return V_119 ;
}
return NULL ;
}
static int F_65 ( struct V_79 * V_80 , unsigned int V_81 ,
unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_122 )
{
enum V_88 V_89 ;
struct V_1 * V_2 = F_49 ( V_80 , & V_89 ) ;
unsigned int V_25 , V_26 ;
unsigned int V_84 , V_85 ;
unsigned int V_123 ;
unsigned int V_124 , V_125 ;
unsigned int V_120 ;
union V_11 V_126 , V_127 , V_128 ;
unsigned int V_27 ;
const struct V_118 * V_119 ;
int V_15 = V_106 ;
F_52 (nf_nat_sdp_addr_hook) V_129 ;
F_52 (nf_nat_sdp_session_hook) V_130 ;
V_129 = F_59 ( V_131 ) ;
if ( F_35 ( V_2 , * V_3 , 0 , * V_24 ,
V_132 , V_55 ,
& V_25 , & V_26 ) <= 0 )
return V_106 ;
V_123 = V_25 ;
V_124 = 0 ;
if ( F_36 ( V_2 , * V_3 , V_123 , * V_24 ,
V_133 , V_134 ,
& V_25 , & V_26 , & V_126 ) > 0 )
V_124 = V_26 ;
V_84 = V_123 ;
for ( V_120 = 0 ; V_120 < F_64 ( V_121 ) ; ) {
if ( F_35 ( V_2 , * V_3 , V_84 , * V_24 ,
V_134 , V_55 ,
& V_84 , & V_85 ) <= 0 )
break;
V_119 = V_118 ( * V_3 , V_84 , V_85 ) ;
if ( ! V_119 ) {
V_84 += V_85 ;
continue;
}
V_84 += V_119 -> V_6 ;
V_85 -= V_119 -> V_6 ;
V_27 = F_17 ( * V_3 + V_84 , NULL , 10 ) ;
if ( V_27 == 0 )
continue;
if ( V_27 < 1024 || V_27 > 65535 )
return V_97 ;
V_125 = 0 ;
if ( F_36 ( V_2 , * V_3 , V_84 , * V_24 ,
V_133 , V_134 ,
& V_25 , & V_26 , & V_127 ) > 0 ) {
V_125 = V_26 ;
memcpy ( & V_128 , & V_127 , sizeof( V_128 ) ) ;
} else if ( V_124 )
memcpy ( & V_128 , & V_126 , sizeof( V_128 ) ) ;
else
return V_97 ;
V_15 = F_48 ( V_80 , V_81 , V_32 ,
V_3 , V_24 ,
& V_128 , F_18 ( V_27 ) , V_119 -> V_65 ,
V_84 , V_85 ) ;
if ( V_15 != V_106 )
return V_15 ;
if ( V_125 && V_129 && V_2 -> V_112 & V_113 ) {
V_15 = V_129 ( V_80 , V_81 , V_32 ,
V_3 , V_24 , V_84 ,
V_133 , V_134 ,
& V_128 ) ;
if ( V_15 != V_106 )
return V_15 ;
}
V_120 ++ ;
}
V_130 = F_59 ( V_135 ) ;
if ( V_130 && V_2 -> V_112 & V_113 )
V_15 = V_130 ( V_80 , V_81 , V_32 ,
V_3 , V_24 , V_123 , & V_128 ) ;
return V_15 ;
}
static int F_66 ( struct V_79 * V_80 , unsigned int V_81 ,
unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_122 , unsigned int V_136 )
{
enum V_88 V_89 ;
struct V_1 * V_2 = F_49 ( V_80 , & V_89 ) ;
struct V_137 * V_138 = F_67 ( V_2 ) ;
if ( ( V_136 >= 100 && V_136 <= 199 ) ||
( V_136 >= 200 && V_136 <= 299 ) )
return F_65 ( V_80 , V_81 , V_32 , V_3 , V_24 , V_122 ) ;
else if ( V_138 -> V_139 == V_122 )
F_45 ( V_2 , true ) ;
return V_106 ;
}
static int F_68 ( struct V_79 * V_80 , unsigned int V_81 ,
unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_122 , unsigned int V_136 )
{
enum V_88 V_89 ;
struct V_1 * V_2 = F_49 ( V_80 , & V_89 ) ;
struct V_137 * V_138 = F_67 ( V_2 ) ;
if ( ( V_136 >= 100 && V_136 <= 199 ) ||
( V_136 >= 200 && V_136 <= 299 ) )
return F_65 ( V_80 , V_81 , V_32 , V_3 , V_24 , V_122 ) ;
else if ( V_138 -> V_139 == V_122 )
F_45 ( V_2 , true ) ;
return V_106 ;
}
static int F_69 ( struct V_79 * V_80 , unsigned int V_81 ,
unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_122 , unsigned int V_136 )
{
enum V_88 V_89 ;
struct V_1 * V_2 = F_49 ( V_80 , & V_89 ) ;
struct V_137 * V_138 = F_67 ( V_2 ) ;
if ( ( V_136 >= 100 && V_136 <= 199 ) ||
( V_136 >= 200 && V_136 <= 299 ) )
return F_65 ( V_80 , V_81 , V_32 , V_3 , V_24 , V_122 ) ;
else if ( V_138 -> V_139 == V_122 )
F_45 ( V_2 , true ) ;
return V_106 ;
}
static int F_70 ( struct V_79 * V_80 , unsigned int V_81 ,
unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_122 )
{
enum V_88 V_89 ;
struct V_1 * V_2 = F_49 ( V_80 , & V_89 ) ;
struct V_137 * V_138 = F_67 ( V_2 ) ;
unsigned int V_15 ;
F_45 ( V_2 , true ) ;
V_15 = F_65 ( V_80 , V_81 , V_32 , V_3 , V_24 , V_122 ) ;
if ( V_15 == V_106 )
V_138 -> V_139 = V_122 ;
return V_15 ;
}
static int F_71 ( struct V_79 * V_80 , unsigned int V_81 ,
unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_122 )
{
enum V_88 V_89 ;
struct V_1 * V_2 = F_49 ( V_80 , & V_89 ) ;
F_45 ( V_2 , true ) ;
return V_106 ;
}
static int F_72 ( struct V_79 * V_80 , unsigned int V_81 ,
unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_122 )
{
enum V_88 V_89 ;
struct V_1 * V_2 = F_49 ( V_80 , & V_89 ) ;
struct V_137 * V_138 = F_67 ( V_2 ) ;
enum V_91 V_92 = F_51 ( V_89 ) ;
unsigned int V_25 , V_26 ;
struct V_59 * exp ;
union V_11 * V_93 , V_82 ;
T_1 V_27 ;
V_17 V_45 ;
unsigned int V_56 = 0 ;
int V_15 ;
F_52 (nf_nat_sip_expect_hook) V_140 ;
if ( V_2 -> V_112 & V_141 )
return V_106 ;
if ( F_22 ( V_2 , * V_3 , 0 , * V_24 , V_142 ,
& V_25 , & V_26 ) > 0 )
V_56 = F_17 ( * V_3 + V_25 , NULL , 10 ) ;
V_15 = F_25 ( V_2 , * V_3 , NULL , * V_24 ,
V_143 , NULL ,
& V_25 , & V_26 , & V_82 , & V_27 ) ;
if ( V_15 < 0 )
return V_97 ;
else if ( V_15 == 0 )
return V_106 ;
if ( ! F_41 ( & V_2 -> V_104 [ V_92 ] . V_67 . V_105 . V_69 , & V_82 ) )
return V_106 ;
if ( F_30 ( V_2 , * V_3 , V_25 + V_26 , * V_24 ,
& V_45 ) == 0 )
return V_106 ;
if ( F_29 ( V_2 , * V_3 ,
V_25 + V_26 , * V_24 ,
L_8 , NULL , NULL , & V_56 ) < 0 )
return V_97 ;
if ( V_56 == 0 ) {
V_15 = V_106 ;
goto V_144;
}
exp = F_60 ( V_2 ) ;
if ( ! exp )
return V_97 ;
V_93 = NULL ;
if ( V_145 )
V_93 = & V_2 -> V_104 [ ! V_92 ] . V_67 . V_105 . V_69 ;
F_61 ( exp , V_66 , F_8 ( V_2 ) ,
V_93 , & V_82 , V_45 , NULL , & V_27 ) ;
exp -> V_73 . V_56 = V_146 * V_77 ;
exp -> V_109 = F_38 ( V_2 ) -> V_109 ;
exp -> V_74 = V_147 | V_75 ;
V_140 = F_59 ( V_148 ) ;
if ( V_140 && V_2 -> V_112 & V_113 )
V_15 = V_140 ( V_80 , V_81 , V_32 , V_3 , V_24 ,
exp , V_25 , V_26 ) ;
else {
if ( F_62 ( exp ) != 0 )
V_15 = V_97 ;
else
V_15 = V_106 ;
}
F_47 ( exp ) ;
V_144:
if ( V_15 == V_106 )
V_138 -> V_149 = V_122 ;
return V_15 ;
}
static int F_73 ( struct V_79 * V_80 , unsigned int V_81 ,
unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 ,
unsigned int V_122 , unsigned int V_136 )
{
enum V_88 V_89 ;
struct V_1 * V_2 = F_49 ( V_80 , & V_89 ) ;
struct V_137 * V_138 = F_67 ( V_2 ) ;
enum V_91 V_92 = F_51 ( V_89 ) ;
union V_11 V_12 ;
T_1 V_27 ;
V_17 V_45 ;
unsigned int V_25 , V_26 , V_150 = 0 ;
unsigned int V_56 = 0 ;
int V_151 = 0 , V_15 ;
if ( V_138 -> V_149 != V_122 )
return V_106 ;
if ( V_136 >= 100 && V_136 <= 199 )
return V_106 ;
if ( V_136 < 200 || V_136 > 299 )
goto V_152;
if ( F_22 ( V_2 , * V_3 , 0 , * V_24 , V_142 ,
& V_25 , & V_26 ) > 0 )
V_56 = F_17 ( * V_3 + V_25 , NULL , 10 ) ;
while ( 1 ) {
unsigned int V_153 = V_56 ;
V_15 = F_25 ( V_2 , * V_3 , & V_150 , * V_24 ,
V_143 , & V_151 ,
& V_25 , & V_26 ,
& V_12 , & V_27 ) ;
if ( V_15 < 0 )
return V_97 ;
else if ( V_15 == 0 )
break;
if ( ! F_41 ( & V_2 -> V_104 [ V_92 ] . V_67 . V_68 . V_69 , & V_12 ) )
continue;
if ( F_30 ( V_2 , * V_3 , V_25 + V_26 ,
* V_24 , & V_45 ) == 0 )
continue;
V_15 = F_29 ( V_2 , * V_3 ,
V_25 + V_26 ,
* V_24 , L_8 ,
NULL , NULL , & V_153 ) ;
if ( V_15 < 0 )
return V_97 ;
if ( V_153 == 0 )
break;
if ( F_37 ( V_2 , & V_12 , V_45 , V_27 ,
V_153 ) )
return V_106 ;
}
V_152:
F_45 ( V_2 , false ) ;
return V_106 ;
}
static int F_74 ( struct V_79 * V_80 , unsigned int V_81 ,
unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 )
{
enum V_88 V_89 ;
struct V_1 * V_2 = F_49 ( V_80 , & V_89 ) ;
unsigned int V_25 , V_26 , V_154 ;
unsigned int V_136 , V_122 , V_120 ;
if ( * V_24 < strlen ( L_9 ) )
return V_106 ;
V_136 = F_17 ( * V_3 + strlen ( L_10 ) , NULL , 10 ) ;
if ( ! V_136 )
return V_97 ;
if ( F_22 ( V_2 , * V_3 , 0 , * V_24 , V_155 ,
& V_25 , & V_26 ) <= 0 )
return V_97 ;
V_122 = F_17 ( * V_3 + V_25 , NULL , 10 ) ;
if ( ! V_122 )
return V_97 ;
V_154 = V_25 + V_26 + 1 ;
for ( V_120 = 0 ; V_120 < F_64 ( V_156 ) ; V_120 ++ ) {
const struct V_157 * V_158 ;
V_158 = & V_156 [ V_120 ] ;
if ( V_158 -> V_159 == NULL )
continue;
if ( * V_24 < V_154 + V_158 -> V_6 ||
F_16 ( * V_3 + V_154 , V_158 -> V_160 , V_158 -> V_6 ) )
continue;
return V_158 -> V_159 ( V_80 , V_81 , V_32 , V_3 , V_24 ,
V_122 , V_136 ) ;
}
return V_106 ;
}
static int F_75 ( struct V_79 * V_80 , unsigned int V_81 ,
unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 )
{
enum V_88 V_89 ;
struct V_1 * V_2 = F_49 ( V_80 , & V_89 ) ;
unsigned int V_25 , V_26 ;
unsigned int V_122 , V_120 ;
for ( V_120 = 0 ; V_120 < F_64 ( V_156 ) ; V_120 ++ ) {
const struct V_157 * V_158 ;
V_158 = & V_156 [ V_120 ] ;
if ( V_158 -> V_161 == NULL )
continue;
if ( * V_24 < V_158 -> V_6 ||
F_16 ( * V_3 , V_158 -> V_160 , V_158 -> V_6 ) )
continue;
if ( F_22 ( V_2 , * V_3 , 0 , * V_24 , V_155 ,
& V_25 , & V_26 ) <= 0 )
return V_97 ;
V_122 = F_17 ( * V_3 + V_25 , NULL , 10 ) ;
if ( ! V_122 )
return V_97 ;
return V_158 -> V_161 ( V_80 , V_81 , V_32 , V_3 , V_24 ,
V_122 ) ;
}
return V_106 ;
}
static int F_76 ( struct V_79 * V_80 , struct V_1 * V_2 ,
unsigned int V_81 , unsigned int V_32 ,
const char * * V_3 , unsigned int * V_24 )
{
F_52 (nf_nat_sip_hook) V_162 ;
int V_15 ;
if ( F_16 ( * V_3 , L_10 , strlen ( L_10 ) ) != 0 )
V_15 = F_75 ( V_80 , V_81 , V_32 , V_3 , V_24 ) ;
else
V_15 = F_74 ( V_80 , V_81 , V_32 , V_3 , V_24 ) ;
if ( V_15 == V_106 && V_2 -> V_112 & V_113 ) {
V_162 = F_59 ( V_163 ) ;
if ( V_162 && ! V_162 ( V_80 , V_81 , V_32 ,
V_3 , V_24 ) )
V_15 = V_97 ;
}
return V_15 ;
}
static int F_77 ( struct V_79 * V_80 , unsigned int V_81 ,
struct V_1 * V_2 , enum V_88 V_89 )
{
struct V_164 * V_165 , V_166 ;
unsigned int V_32 , V_24 ;
unsigned int V_25 , V_26 , V_39 ;
unsigned int V_167 , V_168 ;
const char * V_3 , * V_14 ;
T_3 V_169 , V_170 = 0 ;
int V_15 = V_106 ;
bool V_49 ;
F_52 (nf_nat_sip_seq_adjust_hook) V_171 ;
if ( V_89 != V_172 &&
V_89 != V_173 )
return V_106 ;
V_165 = F_78 ( V_80 , V_81 , sizeof( V_166 ) , & V_166 ) ;
if ( V_165 == NULL )
return V_106 ;
V_32 = V_81 + V_165 -> V_174 * 4 ;
if ( V_32 >= V_80 -> V_6 )
return V_106 ;
F_79 ( V_2 , V_80 , V_146 * V_77 ) ;
if ( F_80 ( F_81 ( V_80 ) ) )
return V_97 ;
V_3 = V_80 -> V_175 + V_32 ;
V_24 = V_80 -> V_6 - V_32 ;
if ( V_24 < strlen ( L_9 ) )
return V_106 ;
while ( 1 ) {
if ( F_22 ( V_2 , V_3 , 0 , V_24 ,
V_176 ,
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
V_167 = V_168 = V_14 - V_3 ;
if ( V_167 > V_24 )
return V_97 ;
V_15 = F_76 ( V_80 , V_2 , V_81 , V_32 ,
& V_3 , & V_167 ) ;
if ( V_15 != V_106 )
break;
V_169 = V_167 - V_168 ;
V_170 += V_169 ;
V_32 += V_167 ;
V_3 += V_167 ;
V_24 = V_24 + V_169 - V_167 ;
}
if ( V_15 == V_106 && V_2 -> V_112 & V_113 ) {
V_171 = F_59 ( V_177 ) ;
if ( V_171 )
V_171 ( V_80 , V_81 , V_170 ) ;
}
return V_15 ;
}
static int F_82 ( struct V_79 * V_80 , unsigned int V_81 ,
struct V_1 * V_2 , enum V_88 V_89 )
{
unsigned int V_32 , V_24 ;
const char * V_3 ;
V_32 = V_81 + sizeof( struct V_178 ) ;
if ( V_32 >= V_80 -> V_6 )
return V_106 ;
F_79 ( V_2 , V_80 , V_146 * V_77 ) ;
if ( F_80 ( F_81 ( V_80 ) ) )
return V_97 ;
V_3 = V_80 -> V_175 + V_32 ;
V_24 = V_80 -> V_6 - V_32 ;
if ( V_24 < strlen ( L_9 ) )
return V_106 ;
return F_76 ( V_80 , V_2 , V_81 , V_32 , & V_3 , & V_24 ) ;
}
static void F_83 ( void )
{
int V_120 , V_179 ;
for ( V_120 = 0 ; V_120 < V_180 ; V_120 ++ ) {
for ( V_179 = 0 ; V_179 < F_64 ( V_181 [ V_120 ] ) ; V_179 ++ ) {
if ( V_181 [ V_120 ] [ V_179 ] . V_182 == NULL )
continue;
F_84 ( & V_181 [ V_120 ] [ V_179 ] ) ;
}
}
}
static int T_4 F_85 ( void )
{
int V_120 , V_179 , V_15 ;
if ( V_180 == 0 )
V_183 [ V_180 ++ ] = V_30 ;
for ( V_120 = 0 ; V_120 < V_180 ; V_120 ++ ) {
memset ( & V_181 [ V_120 ] , 0 , sizeof( V_181 [ V_120 ] ) ) ;
V_181 [ V_120 ] [ 0 ] . V_67 . V_105 . V_107 = V_16 ;
V_181 [ V_120 ] [ 0 ] . V_67 . V_68 . V_70 = V_47 ;
V_181 [ V_120 ] [ 0 ] . V_58 = F_82 ;
V_181 [ V_120 ] [ 1 ] . V_67 . V_105 . V_107 = V_16 ;
V_181 [ V_120 ] [ 1 ] . V_67 . V_68 . V_70 = V_46 ;
V_181 [ V_120 ] [ 1 ] . V_58 = F_77 ;
V_181 [ V_120 ] [ 2 ] . V_67 . V_105 . V_107 = V_19 ;
V_181 [ V_120 ] [ 2 ] . V_67 . V_68 . V_70 = V_47 ;
V_181 [ V_120 ] [ 2 ] . V_58 = F_82 ;
V_181 [ V_120 ] [ 3 ] . V_67 . V_105 . V_107 = V_19 ;
V_181 [ V_120 ] [ 3 ] . V_67 . V_68 . V_70 = V_46 ;
V_181 [ V_120 ] [ 3 ] . V_58 = F_77 ;
for ( V_179 = 0 ; V_179 < F_64 ( V_181 [ V_120 ] ) ; V_179 ++ ) {
V_181 [ V_120 ] [ V_179 ] . V_184 = sizeof( struct V_137 ) ;
V_181 [ V_120 ] [ V_179 ] . V_67 . V_105 . V_71 . V_72 . V_27 = F_18 ( V_183 [ V_120 ] ) ;
V_181 [ V_120 ] [ V_179 ] . V_185 = V_186 ;
V_181 [ V_120 ] [ V_179 ] . V_187 = V_188 ;
V_181 [ V_120 ] [ V_179 ] . V_182 = V_189 ;
if ( V_183 [ V_120 ] == V_30 )
sprintf ( V_181 [ V_120 ] [ V_179 ] . V_37 , L_12 ) ;
else
sprintf ( V_181 [ V_120 ] [ V_179 ] . V_37 , L_13 , V_120 ) ;
F_13 ( L_14 , V_120 , V_183 [ V_120 ] ) ;
V_15 = F_86 ( & V_181 [ V_120 ] [ V_179 ] ) ;
if ( V_15 ) {
F_87 ( V_190 L_15
L_16 ,
V_181 [ V_120 ] [ V_179 ] . V_67 . V_105 . V_107 , V_183 [ V_120 ] ) ;
F_83 () ;
return V_15 ;
}
}
}
return 0 ;
}
