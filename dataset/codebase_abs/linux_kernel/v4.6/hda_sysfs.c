static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( V_7 ) ;
return sprintf ( V_5 , L_1 , F_4 ( V_7 -> V_8 ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( V_7 ) ;
return sprintf ( V_5 , L_1 , F_4 ( V_7 -> V_9 ) ) ;
}
static T_1 F_6 ( struct V_6 * V_7 ,
struct V_10 * V_11 ,
char * V_5 )
{
int V_12 , V_13 = 0 ;
F_7 ( & V_7 -> V_14 ) ;
for ( V_12 = 0 ; V_12 < V_11 -> V_15 ; V_12 ++ ) {
struct V_16 * V_17 = F_8 ( V_11 , V_12 ) ;
V_13 += sprintf ( V_5 + V_13 , L_2 ,
V_17 -> V_18 , V_17 -> V_19 ) ;
}
F_9 ( & V_7 -> V_14 ) ;
return V_13 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_6 ( V_7 , & V_7 -> V_20 , V_5 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_6 ( V_7 , & V_7 -> V_21 , V_5 ) ;
}
static int F_12 ( struct V_6 * V_7 )
{
int V_22 ;
V_22 = F_13 ( V_7 ) ;
if ( V_22 < 0 ) {
F_14 ( V_7 , L_3 ) ;
return V_22 ;
}
F_15 ( V_7 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 )
{
int V_22 ;
F_17 ( V_7 ) ;
F_18 ( V_7 , L_4 ) ;
V_22 = F_13 ( V_7 ) ;
if ( V_22 < 0 ) {
F_14 ( V_7 ,
L_5 ) ;
goto error;
}
V_22 = F_19 ( V_7 ) ;
if ( V_22 < 0 )
goto error;
V_22 = F_20 ( V_7 -> V_23 ) ;
error:
F_21 ( V_7 ) ;
return V_22 ;
}
static char * F_22 ( const char * V_24 , T_2 V_13 )
{
char * V_25 = F_23 ( V_24 , V_13 , V_26 ) ;
char * V_27 ;
if ( ! V_25 )
return NULL ;
V_27 = strchr ( V_25 , '\n' ) ;
if ( V_27 )
* V_27 = 0 ;
return V_25 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_12 , V_13 = 0 ;
F_7 ( & V_7 -> V_14 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_28 . V_15 ; V_12 ++ ) {
struct V_29 * V_30 = F_8 ( & V_7 -> V_28 , V_12 ) ;
V_13 += snprintf ( V_5 + V_13 , V_31 - V_13 ,
L_6 ,
V_30 -> V_18 , V_30 -> V_32 , V_30 -> V_33 ) ;
}
F_9 ( & V_7 -> V_14 ) ;
return V_13 ;
}
static int F_25 ( struct V_6 * V_7 , const char * V_5 )
{
struct V_29 * V_30 ;
int V_18 , V_32 , V_33 ;
if ( sscanf ( V_5 , L_7 , & V_18 , & V_32 , & V_33 ) != 3 )
return - V_34 ;
if ( ! V_18 || ! V_32 )
return - V_34 ;
F_7 ( & V_7 -> V_14 ) ;
V_30 = F_26 ( & V_7 -> V_28 ) ;
if ( ! V_30 ) {
F_9 ( & V_7 -> V_14 ) ;
return - V_35 ;
}
V_30 -> V_18 = V_18 ;
V_30 -> V_32 = V_32 ;
V_30 -> V_33 = V_33 ;
F_9 ( & V_7 -> V_14 ) ;
return 0 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_36 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_22 = F_25 ( V_7 , V_5 ) ;
if ( V_22 < 0 )
return V_22 ;
return V_36 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_12 , V_13 = 0 ;
F_7 ( & V_7 -> V_14 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_37 . V_15 ; V_12 ++ ) {
struct V_38 * V_39 = F_8 ( & V_7 -> V_37 , V_12 ) ;
V_13 += snprintf ( V_5 + V_13 , V_31 - V_13 ,
L_8 , V_39 -> V_40 , V_39 -> V_41 ) ;
}
F_9 ( & V_7 -> V_14 ) ;
return V_13 ;
}
static struct V_38 * F_29 ( struct V_6 * V_7 , const char * V_40 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_37 . V_15 ; V_12 ++ ) {
struct V_38 * V_39 = F_8 ( & V_7 -> V_37 , V_12 ) ;
if ( ! strcmp ( V_39 -> V_40 , V_40 ) )
return V_39 ;
}
return NULL ;
}
static void F_30 ( char * V_42 )
{
char * V_27 ;
if ( ! * V_42 )
return;
V_27 = V_42 + strlen ( V_42 ) - 1 ;
for (; isspace ( * V_27 ) ; V_27 -- ) {
* V_27 = 0 ;
if ( V_27 == V_42 )
return;
}
}
static int F_31 ( struct V_6 * V_7 , const char * V_5 )
{
char * V_40 , * V_41 ;
struct V_38 * V_39 ;
int V_22 = 0 ;
V_5 = F_32 ( V_5 ) ;
if ( ! * V_5 || * V_5 == '#' || * V_5 == '\n' )
return 0 ;
if ( * V_5 == '=' )
return - V_34 ;
V_40 = F_22 ( V_5 , 1024 ) ;
if ( ! V_40 )
return - V_35 ;
V_41 = strchr ( V_40 , '=' ) ;
if ( ! V_41 ) {
F_33 ( V_40 ) ;
return - V_34 ;
}
* V_41 ++ = 0 ;
V_41 = F_32 ( V_41 ) ;
F_30 ( V_40 ) ;
F_30 ( V_41 ) ;
F_7 ( & V_7 -> V_14 ) ;
V_39 = F_29 ( V_7 , V_40 ) ;
if ( V_39 ) {
F_33 ( V_39 -> V_40 ) ;
V_39 -> V_40 = V_40 ;
V_39 -> V_41 = V_41 ;
goto V_43;
}
if ( V_7 -> V_37 . V_15 >= V_44 )
V_39 = NULL ;
else
V_39 = F_26 ( & V_7 -> V_37 ) ;
if ( V_39 ) {
V_39 -> V_40 = V_40 ;
V_39 -> V_41 = V_41 ;
} else {
V_22 = - V_35 ;
}
V_43:
F_9 ( & V_7 -> V_14 ) ;
if ( V_22 )
F_33 ( V_40 ) ;
return V_22 ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_36 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_22 = F_31 ( V_7 , V_5 ) ;
if ( V_22 < 0 )
return V_22 ;
return V_36 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_6 ( V_7 , & V_7 -> V_45 , V_5 ) ;
}
static int F_36 ( struct V_6 * V_7 , const char * V_5 )
{
int V_18 , V_19 , V_22 ;
if ( sscanf ( V_5 , L_9 , & V_18 , & V_19 ) != 2 )
return - V_34 ;
if ( ! V_18 )
return - V_34 ;
F_7 ( & V_7 -> V_14 ) ;
V_22 = F_37 ( V_7 , & V_7 -> V_45 , V_18 , V_19 ) ;
F_9 ( & V_7 -> V_14 ) ;
return V_22 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_36 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_22 = F_36 ( V_7 , V_5 ) ;
if ( V_22 < 0 )
return V_22 ;
return V_36 ;
}
const char * F_39 ( struct V_6 * V_7 , const char * V_40 )
{
struct V_38 * V_39 = F_29 ( V_7 , V_40 ) ;
return V_39 ? V_39 -> V_41 : NULL ;
}
int F_40 ( struct V_6 * V_7 , const char * V_40 )
{
const char * V_27 ;
int V_46 ;
F_7 ( & V_7 -> V_14 ) ;
V_27 = F_39 ( V_7 , V_40 ) ;
if ( ! V_27 || ! * V_27 )
V_46 = - V_47 ;
else {
switch ( toupper ( * V_27 ) ) {
case 'T' :
case 'Y' :
case '1' :
V_46 = 1 ;
break;
default:
V_46 = 0 ;
break;
}
}
F_9 ( & V_7 -> V_14 ) ;
return V_46 ;
}
int F_41 ( struct V_6 * V_7 , const char * V_40 , int * V_48 )
{
const char * V_27 ;
unsigned long V_41 ;
int V_46 ;
F_7 ( & V_7 -> V_14 ) ;
V_27 = F_39 ( V_7 , V_40 ) ;
if ( ! V_27 )
V_46 = - V_47 ;
else if ( F_42 ( V_27 , 0 , & V_41 ) )
V_46 = - V_34 ;
else {
* V_48 = V_41 ;
V_46 = 0 ;
}
F_9 ( & V_7 -> V_14 ) ;
return V_46 ;
}
static inline int F_43 ( const char * V_49 , const char * V_50 )
{
return strncasecmp ( V_49 , V_50 , strlen ( V_50 ) ) == 0 ;
}
static void F_44 ( char * V_5 , struct V_51 * V_52 ,
struct V_6 * * V_53 )
{
int V_54 , V_55 , V_56 ;
struct V_6 * V_7 ;
* V_53 = NULL ;
if ( sscanf ( V_5 , L_7 , & V_54 , & V_55 , & V_56 ) == 3 ) {
F_45 (codec, bus) {
if ( ( V_54 <= 0 || V_7 -> V_57 . V_58 == V_54 ) &&
( V_55 <= 0 || V_7 -> V_57 . V_59 == V_55 ) &&
V_7 -> V_57 . V_60 == V_56 ) {
* V_53 = V_7 ;
break;
}
}
}
}
static void F_46 ( char * V_5 , struct V_51 * V_52 ,
struct V_6 * * V_53 )
{
F_36 ( * V_53 , V_5 ) ;
}
static void F_47 ( char * V_5 , struct V_51 * V_52 ,
struct V_6 * * V_53 )
{
F_25 ( * V_53 , V_5 ) ;
}
static void F_48 ( char * V_5 , struct V_51 * V_52 ,
struct V_6 * * V_53 )
{
F_31 ( * V_53 , V_5 ) ;
}
static void F_49 ( char * V_5 , struct V_51 * V_52 ,
struct V_6 * * V_53 )
{
F_33 ( ( * V_53 ) -> V_61 ) ;
( * V_53 ) -> V_61 = F_50 ( V_5 , V_26 ) ;
}
static void F_51 ( char * V_5 , struct V_51 * V_52 ,
struct V_6 * * V_53 )
{
F_52 ( * V_53 , V_5 ) ;
}
static int F_53 ( char * V_5 , struct V_51 * V_52 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < F_54 ( V_62 ) ; V_12 ++ ) {
if ( ! V_62 [ V_12 ] . V_63 )
continue;
if ( F_43 ( V_5 , V_62 [ V_12 ] . V_63 ) )
return V_12 ;
if ( V_62 [ V_12 ] . V_64 && F_43 ( V_5 , V_62 [ V_12 ] . V_64 ) )
return V_12 ;
}
return V_65 ;
}
static int F_55 ( char * V_5 , int V_66 , T_2 * V_67 ,
const void * * V_68 )
{
int V_13 ;
T_2 V_69 = * V_67 ;
const char * V_27 = * V_68 ;
while ( isspace ( * V_27 ) && V_69 ) {
V_27 ++ ;
V_69 -- ;
}
if ( ! V_69 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_69 ; V_13 ++ ) {
if ( ! * V_27 )
break;
if ( * V_27 == '\n' ) {
V_27 ++ ;
V_13 ++ ;
break;
}
if ( V_13 < V_66 )
* V_5 ++ = * V_27 ++ ;
}
* V_5 = 0 ;
* V_67 = V_69 - V_13 ;
* V_68 = V_27 ;
F_30 ( V_5 ) ;
return 1 ;
}
int F_56 ( struct V_51 * V_52 , T_2 V_69 , const void * V_70 )
{
char V_5 [ 128 ] ;
struct V_6 * V_7 ;
int V_71 ;
V_71 = V_65 ;
V_7 = NULL ;
while ( F_55 ( V_5 , sizeof( V_5 ) - 1 , & V_69 , & V_70 ) ) {
if ( ! * V_5 || * V_5 == '#' || * V_5 == '\n' )
continue;
if ( * V_5 == '[' )
V_71 = F_53 ( V_5 , V_52 ) ;
else if ( V_62 [ V_71 ] . V_72 &&
( V_7 || V_71 <= V_73 ) )
V_62 [ V_71 ] . V_72 ( V_5 , V_52 , & V_7 ) ;
}
return 0 ;
}
void F_57 ( struct V_6 * V_7 )
{
F_58 ( & V_7 -> V_14 ) ;
#ifdef F_59
F_60 ( & V_7 -> V_28 , sizeof( struct V_29 ) , 32 ) ;
F_60 ( & V_7 -> V_37 , sizeof( struct V_38 ) , 32 ) ;
F_60 ( & V_7 -> V_45 , sizeof( struct V_16 ) , 16 ) ;
#endif
}
void F_15 ( struct V_6 * V_7 )
{
#ifdef F_59
int V_12 ;
F_61 ( & V_7 -> V_28 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_37 . V_15 ; V_12 ++ ) {
struct V_38 * V_39 = F_8 ( & V_7 -> V_37 , V_12 ) ;
F_33 ( V_39 -> V_40 ) ;
}
F_61 ( & V_7 -> V_37 ) ;
F_61 ( & V_7 -> V_45 ) ;
#endif
}
