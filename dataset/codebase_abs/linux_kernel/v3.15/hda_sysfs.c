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
V_22 = F_20 ( V_7 ) ;
if ( V_22 < 0 )
goto error;
V_22 = F_21 ( V_7 ) ;
if ( V_22 < 0 )
goto error;
V_22 = F_22 ( V_7 -> V_23 -> V_24 ) ;
error:
F_23 ( V_7 ) ;
return V_22 ;
}
static char * F_24 ( const char * V_25 , T_2 V_13 )
{
char * V_26 = F_25 ( V_25 , V_13 , V_27 ) ;
char * V_28 ;
if ( ! V_26 )
return NULL ;
V_28 = strchr ( V_26 , '\n' ) ;
if ( V_28 )
* V_28 = 0 ;
return V_26 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_12 , V_13 = 0 ;
F_7 ( & V_7 -> V_14 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_29 . V_15 ; V_12 ++ ) {
struct V_30 * V_31 = F_8 ( & V_7 -> V_29 , V_12 ) ;
V_13 += snprintf ( V_5 + V_13 , V_32 - V_13 ,
L_6 ,
V_31 -> V_18 , V_31 -> V_33 , V_31 -> V_34 ) ;
}
F_9 ( & V_7 -> V_14 ) ;
return V_13 ;
}
static int F_27 ( struct V_6 * V_7 , const char * V_5 )
{
struct V_30 * V_31 ;
int V_18 , V_33 , V_34 ;
if ( sscanf ( V_5 , L_7 , & V_18 , & V_33 , & V_34 ) != 3 )
return - V_35 ;
if ( ! V_18 || ! V_33 )
return - V_35 ;
F_7 ( & V_7 -> V_14 ) ;
V_31 = F_28 ( & V_7 -> V_29 ) ;
if ( ! V_31 ) {
F_9 ( & V_7 -> V_14 ) ;
return - V_36 ;
}
V_31 -> V_18 = V_18 ;
V_31 -> V_33 = V_33 ;
V_31 -> V_34 = V_34 ;
F_9 ( & V_7 -> V_14 ) ;
return 0 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_37 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_22 = F_27 ( V_7 , V_5 ) ;
if ( V_22 < 0 )
return V_22 ;
return V_37 ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_12 , V_13 = 0 ;
F_7 ( & V_7 -> V_14 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_38 . V_15 ; V_12 ++ ) {
struct V_39 * V_40 = F_8 ( & V_7 -> V_38 , V_12 ) ;
V_13 += snprintf ( V_5 + V_13 , V_32 - V_13 ,
L_8 , V_40 -> V_41 , V_40 -> V_42 ) ;
}
F_9 ( & V_7 -> V_14 ) ;
return V_13 ;
}
static struct V_39 * F_31 ( struct V_6 * V_7 , const char * V_41 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_38 . V_15 ; V_12 ++ ) {
struct V_39 * V_40 = F_8 ( & V_7 -> V_38 , V_12 ) ;
if ( ! strcmp ( V_40 -> V_41 , V_41 ) )
return V_40 ;
}
return NULL ;
}
static void F_32 ( char * V_43 )
{
char * V_28 ;
if ( ! * V_43 )
return;
V_28 = V_43 + strlen ( V_43 ) - 1 ;
for (; isspace ( * V_28 ) ; V_28 -- ) {
* V_28 = 0 ;
if ( V_28 == V_43 )
return;
}
}
static int F_33 ( struct V_6 * V_7 , const char * V_5 )
{
char * V_41 , * V_42 ;
struct V_39 * V_40 ;
int V_22 = 0 ;
V_5 = F_34 ( V_5 ) ;
if ( ! * V_5 || * V_5 == '#' || * V_5 == '\n' )
return 0 ;
if ( * V_5 == '=' )
return - V_35 ;
V_41 = F_24 ( V_5 , 1024 ) ;
if ( ! V_41 )
return - V_36 ;
V_42 = strchr ( V_41 , '=' ) ;
if ( ! V_42 ) {
F_35 ( V_41 ) ;
return - V_35 ;
}
* V_42 ++ = 0 ;
V_42 = F_34 ( V_42 ) ;
F_32 ( V_41 ) ;
F_32 ( V_42 ) ;
F_7 ( & V_7 -> V_14 ) ;
V_40 = F_31 ( V_7 , V_41 ) ;
if ( V_40 ) {
F_35 ( V_40 -> V_41 ) ;
V_40 -> V_41 = V_41 ;
V_40 -> V_42 = V_42 ;
goto V_44;
}
if ( V_7 -> V_38 . V_15 >= V_45 )
V_40 = NULL ;
else
V_40 = F_28 ( & V_7 -> V_38 ) ;
if ( V_40 ) {
V_40 -> V_41 = V_41 ;
V_40 -> V_42 = V_42 ;
} else {
V_22 = - V_36 ;
}
V_44:
F_9 ( & V_7 -> V_14 ) ;
if ( V_22 )
F_35 ( V_41 ) ;
return V_22 ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_37 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_22 = F_33 ( V_7 , V_5 ) ;
if ( V_22 < 0 )
return V_22 ;
return V_37 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_6 ( V_7 , & V_7 -> V_46 , V_5 ) ;
}
static int F_38 ( struct V_6 * V_7 , const char * V_5 )
{
int V_18 , V_19 , V_22 ;
if ( sscanf ( V_5 , L_9 , & V_18 , & V_19 ) != 2 )
return - V_35 ;
if ( ! V_18 )
return - V_35 ;
F_7 ( & V_7 -> V_14 ) ;
V_22 = F_39 ( V_7 , & V_7 -> V_46 , V_18 , V_19 ) ;
F_9 ( & V_7 -> V_14 ) ;
return V_22 ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_37 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_22 = F_38 ( V_7 , V_5 ) ;
if ( V_22 < 0 )
return V_22 ;
return V_37 ;
}
const char * F_41 ( struct V_6 * V_7 , const char * V_41 )
{
struct V_39 * V_40 = F_31 ( V_7 , V_41 ) ;
return V_40 ? V_40 -> V_42 : NULL ;
}
int F_42 ( struct V_6 * V_7 , const char * V_41 )
{
const char * V_28 ;
int V_47 ;
F_7 ( & V_7 -> V_14 ) ;
V_28 = F_41 ( V_7 , V_41 ) ;
if ( ! V_28 || ! * V_28 )
V_47 = - V_48 ;
else {
switch ( toupper ( * V_28 ) ) {
case 'T' :
case 'Y' :
case '1' :
V_47 = 1 ;
break;
default:
V_47 = 0 ;
break;
}
}
F_9 ( & V_7 -> V_14 ) ;
return V_47 ;
}
int F_43 ( struct V_6 * V_7 , const char * V_41 , int * V_49 )
{
const char * V_28 ;
unsigned long V_42 ;
int V_47 ;
F_7 ( & V_7 -> V_14 ) ;
V_28 = F_41 ( V_7 , V_41 ) ;
if ( ! V_28 )
V_47 = - V_48 ;
else if ( F_44 ( V_28 , 0 , & V_42 ) )
V_47 = - V_35 ;
else {
* V_49 = V_42 ;
V_47 = 0 ;
}
F_9 ( & V_7 -> V_14 ) ;
return V_47 ;
}
static inline int F_45 ( const char * V_50 , const char * V_51 )
{
return F_46 ( V_50 , V_51 , strlen ( V_51 ) ) == 0 ;
}
static void F_47 ( char * V_5 , struct V_52 * V_23 ,
struct V_6 * * V_53 )
{
int V_54 , V_55 , V_56 ;
struct V_6 * V_7 ;
* V_53 = NULL ;
if ( sscanf ( V_5 , L_7 , & V_54 , & V_55 , & V_56 ) == 3 ) {
F_48 (codec, &bus->codec_list, list) {
if ( ( V_54 <= 0 || V_7 -> V_57 == V_54 ) &&
( V_55 <= 0 || V_7 -> V_58 == V_55 ) &&
V_7 -> V_59 == V_56 ) {
* V_53 = V_7 ;
break;
}
}
}
}
static void F_49 ( char * V_5 , struct V_52 * V_23 ,
struct V_6 * * V_53 )
{
F_38 ( * V_53 , V_5 ) ;
}
static void F_50 ( char * V_5 , struct V_52 * V_23 ,
struct V_6 * * V_53 )
{
F_27 ( * V_53 , V_5 ) ;
}
static void F_51 ( char * V_5 , struct V_52 * V_23 ,
struct V_6 * * V_53 )
{
F_33 ( * V_53 , V_5 ) ;
}
static void F_52 ( char * V_5 , struct V_52 * V_23 ,
struct V_6 * * V_53 )
{
F_35 ( ( * V_53 ) -> V_60 ) ;
( * V_53 ) -> V_60 = F_53 ( V_5 , V_27 ) ;
}
static void F_54 ( char * V_5 , struct V_52 * V_23 ,
struct V_6 * * V_53 )
{
F_35 ( ( * V_53 ) -> V_61 ) ;
( * V_53 ) -> V_61 = F_53 ( V_5 , V_27 ) ;
}
static int F_55 ( char * V_5 , struct V_52 * V_23 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < F_56 ( V_62 ) ; V_12 ++ ) {
if ( ! V_62 [ V_12 ] . V_63 )
continue;
if ( F_45 ( V_5 , V_62 [ V_12 ] . V_63 ) )
return V_12 ;
if ( V_62 [ V_12 ] . V_64 && F_45 ( V_5 , V_62 [ V_12 ] . V_64 ) )
return V_12 ;
}
return V_65 ;
}
static int F_57 ( char * V_5 , int V_66 , T_2 * V_67 ,
const void * * V_68 )
{
int V_13 ;
T_2 V_69 = * V_67 ;
const char * V_28 = * V_68 ;
while ( isspace ( * V_28 ) && V_69 ) {
V_28 ++ ;
V_69 -- ;
}
if ( ! V_69 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_69 ; V_13 ++ ) {
if ( ! * V_28 )
break;
if ( * V_28 == '\n' ) {
V_28 ++ ;
V_13 ++ ;
break;
}
if ( V_13 < V_66 )
* V_5 ++ = * V_28 ++ ;
}
* V_5 = 0 ;
* V_67 = V_69 - V_13 ;
* V_68 = V_28 ;
F_32 ( V_5 ) ;
return 1 ;
}
int F_58 ( struct V_52 * V_23 , T_2 V_69 , const void * V_70 )
{
char V_5 [ 128 ] ;
struct V_6 * V_7 ;
int V_71 ;
V_71 = V_65 ;
V_7 = NULL ;
while ( F_57 ( V_5 , sizeof( V_5 ) - 1 , & V_69 , & V_70 ) ) {
if ( ! * V_5 || * V_5 == '#' || * V_5 == '\n' )
continue;
if ( * V_5 == '[' )
V_71 = F_55 ( V_5 , V_23 ) ;
else if ( V_62 [ V_71 ] . V_72 &&
( V_7 || V_71 <= V_73 ) )
V_62 [ V_71 ] . V_72 ( V_5 , V_23 , & V_7 ) ;
}
return 0 ;
}
void F_59 ( struct V_6 * V_7 )
{
F_60 ( & V_7 -> V_14 ) ;
#ifdef F_61
F_62 ( & V_7 -> V_29 , sizeof( struct V_30 ) , 32 ) ;
F_62 ( & V_7 -> V_38 , sizeof( struct V_39 ) , 32 ) ;
F_62 ( & V_7 -> V_46 , sizeof( struct V_16 ) , 16 ) ;
#endif
}
void F_15 ( struct V_6 * V_7 )
{
#ifdef F_61
int V_12 ;
F_63 ( & V_7 -> V_29 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_38 . V_15 ; V_12 ++ ) {
struct V_39 * V_40 = F_8 ( & V_7 -> V_38 , V_12 ) ;
F_35 ( V_40 -> V_41 ) ;
}
F_63 ( & V_7 -> V_38 ) ;
F_63 ( & V_7 -> V_46 ) ;
#endif
}
