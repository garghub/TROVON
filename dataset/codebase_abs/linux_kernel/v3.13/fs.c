static int T_1 F_1 ( char * V_1 )
{
unsigned long V_2 ;
if ( F_2 ( V_1 , 0 , & V_2 ) ) {
F_3 ( L_1 , V_1 ) ;
return 0 ;
}
V_3 = V_2 ;
F_4 ( L_2 , V_3 ) ;
return 1 ;
}
static void * F_5 ( struct V_4 * V_5 , T_2 * V_6 )
{
T_2 V_7 ;
F_6 ( V_5 -> V_8 ) ;
for ( V_7 = 0 ; V_7 < * V_6 ; V_7 ++ ) {
if ( F_7 ( V_5 -> V_8 ) )
return NULL ;
}
return V_5 -> V_8 ;
}
static void * F_8 ( struct V_4 * V_5 , void * V_9 , T_2 * V_6 )
{
struct V_10 * V_11 = V_9 ;
if ( F_7 ( V_11 ) )
return NULL ;
( * V_6 ) ++ ;
return V_11 ;
}
static int F_9 ( struct V_4 * V_5 , void * V_9 )
{
struct V_10 * V_11 = V_9 ;
if ( F_10 ( V_11 , V_5 ) )
return - V_12 ;
return 0 ;
}
static void F_11 ( struct V_4 * V_5 , void * V_9 )
{
}
static struct V_13 * F_12 ( struct V_14 * V_15 )
{
if ( V_15 -> V_16 > 0 )
return V_15 -> V_17 [ 0 ] ;
return V_15 -> V_18 ;
}
static struct V_13 * F_13 ( struct V_14 * V_15 )
{
struct V_13 * V_19 ;
int V_7 = 0 ;
if ( V_15 -> V_18 )
V_19 = F_14 ( V_15 -> V_18 ) ;
else
V_19 = F_14 ( V_15 -> V_17 [ V_7 ++ ] ) ;
if ( ! V_19 )
return NULL ;
for (; V_7 < V_15 -> V_16 ; V_7 ++ )
F_15 ( V_19 , V_15 -> V_17 [ V_7 ] ) ;
return V_19 ;
}
static int F_16 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
struct V_14 * V_15 = V_20 -> V_22 ;
struct V_10 * V_11 ;
struct V_4 * V_5 ;
struct V_13 * V_19 ;
int V_23 = - V_24 ;
F_17 ( & V_25 ) ;
V_19 = F_13 ( V_15 ) ;
if ( ! V_19 )
goto V_26;
V_11 = F_18 ( V_19 ) ;
if ( ! V_11 )
goto V_27;
V_23 = F_19 ( V_21 , & V_28 ) ;
if ( V_23 )
goto V_29;
V_5 = V_21 -> V_30 ;
V_5 -> V_8 = V_11 ;
V_26:
F_20 ( & V_25 ) ;
return V_23 ;
V_29:
F_21 ( V_11 ) ;
V_27:
F_22 ( V_19 ) ;
goto V_26;
}
static int F_23 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
struct V_10 * V_11 ;
struct V_13 * V_19 ;
struct V_4 * V_5 ;
V_5 = V_21 -> V_30 ;
V_11 = V_5 -> V_8 ;
V_19 = F_24 ( V_11 ) ;
F_21 ( V_11 ) ;
F_22 ( V_19 ) ;
F_25 ( V_20 , V_21 ) ;
return 0 ;
}
static struct V_14 * F_26 ( const char * V_31 )
{
struct V_14 * V_15 ;
struct V_13 * V_19 ;
F_27 (node, &all_head, all) {
V_19 = F_12 ( V_15 ) ;
if ( V_19 && ( strcmp ( F_28 ( V_19 ) , V_31 ) == 0 ) )
return V_15 ;
}
return NULL ;
}
static void F_29 ( struct V_14 * V_15 )
{
int V_7 ;
if ( V_15 -> V_18 )
F_30 ( V_15 -> V_18 ) ;
for ( V_7 = 0 ; V_7 < V_15 -> V_16 ; V_7 ++ )
F_30 ( V_15 -> V_17 [ V_7 ] ) ;
}
static T_3 F_31 ( struct V_21 * V_21 , const char T_4 * V_32 ,
T_5 V_33 , T_2 * V_6 )
{
struct V_4 * V_5 ;
struct V_13 * V_19 ;
struct V_14 * V_15 ;
V_5 = V_21 -> V_30 ;
V_19 = F_24 ( V_5 -> V_8 ) ;
F_17 ( & V_25 ) ;
V_15 = F_26 ( F_28 ( V_19 ) ) ;
if ( V_15 ) {
if ( V_15 -> V_16 == 0 )
F_32 ( V_15 ) ;
else
F_29 ( V_15 ) ;
}
F_30 ( V_19 ) ;
F_20 ( & V_25 ) ;
return V_33 ;
}
static char * F_33 ( const char * V_34 , const char * V_35 , const char * V_36 )
{
char * V_37 ;
char * V_38 ;
char * V_39 ;
V_39 = F_34 ( V_35 , V_40 ) ;
if ( ! V_39 )
return NULL ;
V_38 = strrchr ( V_39 , '.' ) ;
if ( V_38 )
* V_38 = '\0' ;
if ( V_34 )
V_37 = F_35 ( V_40 , L_3 , V_34 , V_39 , V_36 ) ;
else
V_37 = F_35 ( V_40 , L_4 , V_39 , V_36 ) ;
F_36 ( V_39 ) ;
return V_37 ;
}
static char * F_37 ( const char * V_41 , const struct V_42 * V_36 )
{
const char * V_43 ;
char * V_44 ;
if ( strncmp ( V_41 , V_45 , strlen ( V_45 ) ) == 0 ) {
V_43 = V_41 + strlen ( V_45 ) + 1 ;
if ( V_36 -> V_34 == V_46 )
V_44 = F_33 ( V_47 , V_43 , V_36 -> V_36 ) ;
else
V_44 = F_33 ( V_45 , V_43 , V_36 -> V_36 ) ;
} else {
V_44 = F_33 ( NULL , V_41 , V_36 -> V_36 ) ;
}
return V_44 ;
}
static const char * F_38 ( const char * V_48 )
{
if ( strncmp ( V_48 , V_49 , sizeof( V_49 ) - 1 ) == 0 )
return V_48 + sizeof( V_49 ) - 1 ;
return V_48 ;
}
static void F_39 ( struct V_14 * V_15 , struct V_50 * V_51 )
{
const char * V_48 ;
char * V_37 ;
int V_52 ;
int V_7 ;
for ( V_52 = 0 ; V_42 [ V_52 ] . V_36 ; V_52 ++ )
;
V_15 -> V_53 = F_40 ( V_52 , sizeof( struct V_50 * ) , V_40 ) ;
if ( ! V_15 -> V_53 )
return;
for ( V_7 = 0 ; V_7 < V_52 ; V_7 ++ ) {
V_37 = F_37 (
F_28 ( F_12 ( V_15 ) ) ,
& V_42 [ V_7 ] ) ;
if ( ! V_37 )
goto V_54;
V_48 = F_41 ( V_37 ) ;
if ( V_48 == V_37 )
goto V_54;
V_15 -> V_53 [ V_7 ] = F_42 ( F_38 ( V_48 ) ,
V_51 , V_37 ) ;
if ( ! V_15 -> V_53 [ V_7 ] )
goto V_54;
F_36 ( V_37 ) ;
}
return;
V_54:
F_36 ( V_37 ) ;
while ( V_7 -- > 0 )
F_43 ( V_15 -> V_53 [ V_7 ] ) ;
F_36 ( V_15 -> V_53 ) ;
V_15 -> V_53 = NULL ;
}
static void F_44 ( struct V_14 * V_15 , struct V_13 * V_19 ,
const char * V_31 , struct V_14 * V_51 )
{
F_45 ( & V_15 -> V_55 ) ;
F_45 ( & V_15 -> V_56 ) ;
F_45 ( & V_15 -> V_57 ) ;
if ( V_15 -> V_17 ) {
V_15 -> V_17 [ 0 ] = V_19 ;
V_15 -> V_16 = 1 ;
}
V_15 -> V_51 = V_51 ;
if ( V_31 )
strcpy ( V_15 -> V_31 , V_31 ) ;
}
static struct V_14 * F_46 ( struct V_14 * V_51 ,
struct V_13 * V_19 , const char * V_31 )
{
struct V_14 * V_15 ;
V_15 = F_47 ( sizeof( struct V_14 ) + strlen ( V_31 ) + 1 , V_40 ) ;
if ( ! V_15 )
goto V_58;
if ( V_19 ) {
V_15 -> V_17 = F_40 ( 1 , sizeof( struct V_13 * ) ,
V_40 ) ;
if ( ! V_15 -> V_17 )
goto V_58;
}
F_44 ( V_15 , V_19 , V_31 , V_51 ) ;
if ( V_19 ) {
V_15 -> V_50 = F_48 ( F_38 ( V_15 -> V_31 ) , 0600 ,
V_51 -> V_50 , V_15 , & V_59 ) ;
} else
V_15 -> V_50 = F_49 ( V_15 -> V_31 , V_51 -> V_50 ) ;
if ( ! V_15 -> V_50 ) {
F_3 ( L_5 ) ;
F_36 ( V_15 ) ;
return NULL ;
}
if ( V_19 )
F_39 ( V_15 , V_51 -> V_50 ) ;
F_50 ( & V_15 -> V_55 , & V_51 -> V_56 ) ;
F_50 ( & V_15 -> V_57 , & V_60 ) ;
return V_15 ;
V_58:
F_36 ( V_15 ) ;
F_3 ( L_6 ) ;
return NULL ;
}
static void F_51 ( struct V_14 * V_15 )
{
int V_7 ;
if ( ! V_15 -> V_53 )
return;
for ( V_7 = 0 ; V_42 [ V_7 ] . V_36 ; V_7 ++ )
F_43 ( V_15 -> V_53 [ V_7 ] ) ;
F_36 ( V_15 -> V_53 ) ;
V_15 -> V_53 = NULL ;
}
static void F_52 ( struct V_14 * V_15 )
{
F_53 ( & V_15 -> V_55 ) ;
F_53 ( & V_15 -> V_57 ) ;
F_43 ( V_15 -> V_50 ) ;
F_51 ( V_15 ) ;
F_36 ( V_15 -> V_17 ) ;
if ( V_15 -> V_18 )
F_22 ( V_15 -> V_18 ) ;
F_36 ( V_15 ) ;
}
static void F_32 ( struct V_14 * V_15 )
{
struct V_14 * V_51 ;
while ( ( V_15 != & V_61 ) && F_54 ( & V_15 -> V_56 ) ) {
V_51 = V_15 -> V_51 ;
F_52 ( V_15 ) ;
V_15 = V_51 ;
}
}
static struct V_14 * F_55 ( struct V_14 * V_51 ,
const char * V_31 )
{
struct V_14 * V_15 ;
F_27 (node, &parent->children, list) {
if ( strcmp ( V_15 -> V_31 , V_31 ) == 0 )
return V_15 ;
}
return NULL ;
}
static T_3 F_56 ( struct V_21 * V_21 , const char T_4 * V_32 ,
T_5 V_33 , T_2 * V_6 )
{
struct V_14 * V_15 ;
F_17 ( & V_25 ) ;
V_62:
F_27 (node, &all_head, all) {
if ( V_15 -> V_16 > 0 )
F_29 ( V_15 ) ;
else if ( F_54 ( & V_15 -> V_56 ) ) {
F_32 ( V_15 ) ;
goto V_62;
}
}
F_20 ( & V_25 ) ;
return V_33 ;
}
static T_3 F_57 ( struct V_21 * V_21 , char T_4 * V_32 , T_5 V_33 ,
T_2 * V_6 )
{
return 0 ;
}
static void F_58 ( struct V_13 * V_19 )
{
char * V_41 ;
char * V_63 ;
char * V_64 ;
struct V_14 * V_51 ;
struct V_14 * V_15 ;
V_41 = F_34 ( F_28 ( V_19 ) , V_40 ) ;
if ( ! V_41 )
return;
V_51 = & V_61 ;
for ( V_63 = V_41 ; ( V_64 = strchr ( V_63 , '/' ) ) ; V_63 = V_64 + 1 ) {
if ( V_63 == V_64 )
continue;
* V_64 = 0 ;
if ( strcmp ( V_63 , L_7 ) == 0 )
continue;
if ( strcmp ( V_63 , L_8 ) == 0 ) {
if ( ! V_51 -> V_51 )
goto V_65;
V_51 = V_51 -> V_51 ;
continue;
}
V_15 = F_55 ( V_51 , V_63 ) ;
if ( ! V_15 ) {
V_15 = F_46 ( V_51 , NULL , V_63 ) ;
if ( ! V_15 )
goto V_65;
}
V_51 = V_15 ;
}
V_15 = F_46 ( V_51 , V_19 , V_63 ) ;
if ( ! V_15 )
goto V_65;
V_66:
F_36 ( V_41 ) ;
return;
V_65:
F_32 ( V_51 ) ;
goto V_66;
}
static void F_59 ( struct V_14 * V_15 , struct V_13 * V_19 )
{
struct V_13 * * V_17 ;
int V_52 = V_15 -> V_16 ;
V_17 = F_40 ( V_52 + 1 , sizeof( struct V_13 * ) , V_40 ) ;
if ( ! V_17 ) {
F_3 ( L_9 ,
F_28 ( V_19 ) ) ;
return;
}
memcpy ( V_17 , V_15 -> V_17 ,
V_52 * sizeof( struct V_13 * ) ) ;
V_17 [ V_52 ] = V_19 ;
if ( V_52 == 0 ) {
if ( ! F_60 ( V_15 -> V_18 , V_19 ) ) {
F_3 ( L_10
L_11 ,
F_28 ( V_19 ) ) ;
F_22 ( V_15 -> V_18 ) ;
V_15 -> V_18 = NULL ;
}
} else {
if ( ! F_60 ( V_15 -> V_17 [ 0 ] , V_19 ) ) {
F_3 ( L_12
L_13 , F_28 ( V_19 ) ) ;
F_36 ( V_17 ) ;
return;
}
}
F_36 ( V_15 -> V_17 ) ;
V_15 -> V_17 = V_17 ;
V_15 -> V_16 = V_52 + 1 ;
}
static int F_61 ( struct V_14 * V_15 , struct V_13 * V_19 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_15 -> V_16 ; V_7 ++ ) {
if ( V_15 -> V_17 [ V_7 ] == V_19 )
return V_7 ;
}
return - V_67 ;
}
static void F_62 ( struct V_14 * V_15 , struct V_13 * V_19 )
{
if ( V_15 -> V_18 )
F_15 ( V_15 -> V_18 , V_19 ) ;
else {
V_15 -> V_18 = F_14 ( V_19 ) ;
if ( ! V_15 -> V_18 ) {
F_3 ( L_14
L_15 ,
F_28 ( V_19 ) ) ;
}
}
}
static void F_63 ( struct V_14 * V_15 , struct V_13 * V_19 )
{
int V_7 ;
V_7 = F_61 ( V_15 , V_19 ) ;
if ( V_7 < 0 ) {
F_3 ( L_16 ,
F_28 ( V_19 ) ) ;
return;
}
if ( V_3 )
F_62 ( V_15 , V_19 ) ;
V_15 -> V_17 [ V_7 ] = V_15 -> V_17 [ V_15 -> V_16 - 1 ] ;
V_15 -> V_16 -- ;
if ( V_15 -> V_16 > 0 )
return;
F_36 ( V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
V_15 -> V_16 = 0 ;
if ( ! V_15 -> V_18 )
F_32 ( V_15 ) ;
}
void F_64 ( enum V_68 V_69 , struct V_13 * V_19 )
{
struct V_14 * V_15 ;
F_17 ( & V_25 ) ;
V_15 = F_26 ( F_28 ( V_19 ) ) ;
switch ( V_69 ) {
case V_70 :
if ( V_15 )
F_59 ( V_15 , V_19 ) ;
else
F_58 ( V_19 ) ;
break;
case V_71 :
if ( V_15 )
F_63 ( V_15 , V_19 ) ;
else {
F_3 ( L_16 ,
F_28 ( V_19 ) ) ;
}
break;
}
F_20 ( & V_25 ) ;
}
static T_1 int F_65 ( void )
{
int V_23 = - V_72 ;
F_44 ( & V_61 , NULL , NULL , NULL ) ;
V_61 . V_50 = F_49 ( L_17 , NULL ) ;
if ( ! V_61 . V_50 )
goto V_65;
V_73 = F_48 ( L_18 , 0600 , V_61 . V_50 ,
NULL , & V_74 ) ;
if ( ! V_73 )
goto V_65;
F_66 () ;
return 0 ;
V_65:
F_67 ( L_19 ) ;
if ( V_61 . V_50 )
F_43 ( V_61 . V_50 ) ;
return V_23 ;
}
