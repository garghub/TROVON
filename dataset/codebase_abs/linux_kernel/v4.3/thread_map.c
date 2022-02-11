static int F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 [ 0 ] == '.' )
return 0 ;
else
return 1 ;
}
static void F_2 ( struct V_4 * V_5 , int V_6 , int V_7 )
{
T_1 V_8 = ( V_7 - V_6 ) * sizeof( V_5 -> V_5 [ 0 ] ) ;
memset ( & V_5 -> V_5 [ V_6 ] , 0 , V_8 ) ;
}
static struct V_4 * F_3 ( struct V_4 * V_5 , int V_7 )
{
T_1 V_8 = sizeof( * V_5 ) + sizeof( V_5 -> V_5 [ 0 ] ) * V_7 ;
int V_6 = V_5 ? V_5 -> V_7 : 0 ;
V_5 = realloc ( V_5 , V_8 ) ;
if ( V_5 )
F_2 ( V_5 , V_6 , V_7 ) ;
return V_5 ;
}
struct V_4 * F_4 ( T_2 V_9 )
{
struct V_4 * V_10 ;
char V_11 [ 256 ] ;
int V_12 ;
struct V_1 * * V_13 = NULL ;
int V_14 ;
sprintf ( V_11 , L_1 , V_9 ) ;
V_12 = F_5 ( V_11 , & V_13 , F_1 , NULL ) ;
if ( V_12 <= 0 )
return NULL ;
V_10 = F_6 ( V_12 ) ;
if ( V_10 != NULL ) {
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
F_7 ( V_10 , V_14 , atoi ( V_13 [ V_14 ] -> V_3 ) ) ;
V_10 -> V_7 = V_12 ;
F_8 ( & V_10 -> V_15 , 1 ) ;
}
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
F_9 ( & V_13 [ V_14 ] ) ;
free ( V_13 ) ;
return V_10 ;
}
struct V_4 * F_10 ( T_2 V_16 )
{
struct V_4 * V_10 = F_6 ( 1 ) ;
if ( V_10 != NULL ) {
F_7 ( V_10 , 0 , V_16 ) ;
V_10 -> V_7 = 1 ;
F_8 ( & V_10 -> V_15 , 1 ) ;
}
return V_10 ;
}
struct V_4 * F_11 ( T_3 V_17 )
{
T_4 * V_18 ;
int V_19 = 32 , V_12 , V_14 ;
char V_20 [ 256 ] ;
struct V_1 V_1 , * V_21 , * * V_13 = NULL ;
struct V_4 * V_10 = F_6 ( V_19 ) ;
if ( V_10 == NULL )
goto V_22;
V_18 = F_12 ( L_2 ) ;
if ( V_18 == NULL )
goto V_23;
V_10 -> V_7 = 0 ;
F_8 ( & V_10 -> V_15 , 1 ) ;
while ( ! F_13 ( V_18 , & V_1 , & V_21 ) && V_21 ) {
char * V_24 ;
bool V_25 = false ;
struct V_26 V_27 ;
T_2 V_9 = strtol ( V_1 . V_3 , & V_24 , 10 ) ;
if ( * V_24 )
continue;
snprintf ( V_20 , sizeof( V_20 ) , L_3 , V_1 . V_3 ) ;
if ( V_26 ( V_20 , & V_27 ) != 0 )
continue;
if ( V_27 . V_28 != V_17 )
continue;
snprintf ( V_20 , sizeof( V_20 ) , L_1 , V_9 ) ;
V_12 = F_5 ( V_20 , & V_13 , F_1 , NULL ) ;
if ( V_12 <= 0 )
goto V_29;
while ( V_10 -> V_7 + V_12 >= V_19 ) {
V_19 *= 2 ;
V_25 = true ;
}
if ( V_25 ) {
struct V_4 * V_30 ;
V_30 = F_3 ( V_10 , V_19 ) ;
if ( V_30 == NULL )
goto V_31;
V_10 = V_30 ;
}
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
F_7 ( V_10 , V_10 -> V_7 + V_14 ,
atoi ( V_13 [ V_14 ] -> V_3 ) ) ;
}
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
F_9 ( & V_13 [ V_14 ] ) ;
free ( V_13 ) ;
V_10 -> V_7 += V_12 ;
}
V_32:
F_14 ( V_18 ) ;
V_22:
return V_10 ;
V_23:
free ( V_10 ) ;
return NULL ;
V_31:
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
F_9 ( & V_13 [ V_14 ] ) ;
free ( V_13 ) ;
V_29:
F_9 ( & V_10 ) ;
goto V_32;
}
struct V_4 * F_15 ( T_2 V_9 , T_2 V_16 , T_3 V_17 )
{
if ( V_9 != - 1 )
return F_4 ( V_9 ) ;
if ( V_16 == - 1 && V_17 != V_33 )
return F_11 ( V_17 ) ;
return F_10 ( V_16 ) ;
}
static struct V_4 * F_16 ( const char * V_34 )
{
struct V_4 * V_10 = NULL , * V_35 ;
char V_11 [ 256 ] ;
int V_12 , V_36 = 0 ;
struct V_1 * * V_13 = NULL ;
int V_14 , V_37 = 0 ;
T_2 V_9 , V_38 = V_39 ;
char * V_40 ;
struct V_41 * V_42 ;
struct V_43 V_44 = { . V_45 = true , } ;
struct V_46 * V_47 = F_17 ( V_34 , & V_44 ) ;
if ( ! V_47 )
return NULL ;
F_18 (pos, slist) {
V_9 = strtol ( V_42 -> V_48 , & V_40 , 10 ) ;
if ( V_9 == V_49 || V_9 == V_39 ||
( * V_40 != '\0' && * V_40 != ',' ) )
goto V_23;
if ( V_9 == V_38 )
continue;
sprintf ( V_11 , L_1 , V_9 ) ;
V_12 = F_5 ( V_11 , & V_13 , F_1 , NULL ) ;
if ( V_12 <= 0 )
goto V_23;
V_36 += V_12 ;
V_35 = F_3 ( V_10 , V_36 ) ;
if ( V_35 == NULL )
goto V_31;
V_10 = V_35 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
F_7 ( V_10 , V_37 ++ , atoi ( V_13 [ V_14 ] -> V_3 ) ) ;
F_9 ( & V_13 [ V_14 ] ) ;
}
V_10 -> V_7 = V_36 ;
free ( V_13 ) ;
}
V_22:
F_19 ( V_47 ) ;
if ( V_10 )
F_8 ( & V_10 -> V_15 , 1 ) ;
return V_10 ;
V_31:
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
F_9 ( & V_13 [ V_14 ] ) ;
free ( V_13 ) ;
V_23:
F_9 ( & V_10 ) ;
goto V_22;
}
struct V_4 * F_20 ( void )
{
struct V_4 * V_10 = F_6 ( 1 ) ;
if ( V_10 != NULL ) {
F_7 ( V_10 , 0 , - 1 ) ;
V_10 -> V_7 = 1 ;
F_8 ( & V_10 -> V_15 , 1 ) ;
}
return V_10 ;
}
static struct V_4 * F_21 ( const char * V_50 )
{
struct V_4 * V_10 = NULL , * V_35 ;
int V_51 = 0 ;
T_2 V_16 , V_52 = V_39 ;
char * V_40 ;
struct V_41 * V_42 ;
struct V_43 V_44 = { . V_45 = true , } ;
struct V_46 * V_47 ;
if ( ! V_50 )
return F_20 () ;
V_47 = F_17 ( V_50 , & V_44 ) ;
if ( ! V_47 )
return NULL ;
F_18 (pos, slist) {
V_16 = strtol ( V_42 -> V_48 , & V_40 , 10 ) ;
if ( V_16 == V_49 || V_16 == V_39 ||
( * V_40 != '\0' && * V_40 != ',' ) )
goto V_23;
if ( V_16 == V_52 )
continue;
V_51 ++ ;
V_35 = F_3 ( V_10 , V_51 ) ;
if ( V_35 == NULL )
goto V_23;
V_10 = V_35 ;
F_7 ( V_10 , V_51 - 1 , V_16 ) ;
V_10 -> V_7 = V_51 ;
}
V_22:
if ( V_10 )
F_8 ( & V_10 -> V_15 , 1 ) ;
return V_10 ;
V_23:
F_9 ( & V_10 ) ;
goto V_22;
}
struct V_4 * F_22 ( const char * V_9 , const char * V_16 ,
T_3 V_17 )
{
if ( V_9 )
return F_16 ( V_9 ) ;
if ( ! V_16 && V_17 != V_33 )
return F_11 ( V_17 ) ;
return F_21 ( V_16 ) ;
}
static void F_23 ( struct V_4 * V_10 )
{
if ( V_10 ) {
int V_14 ;
F_24 ( F_25 ( & V_10 -> V_15 ) != 0 ,
L_4 ) ;
for ( V_14 = 0 ; V_14 < V_10 -> V_7 ; V_14 ++ )
free ( F_26 ( V_10 , V_14 ) ) ;
free ( V_10 ) ;
}
}
struct V_4 * F_27 ( struct V_4 * V_5 )
{
if ( V_5 )
F_28 ( & V_5 -> V_15 ) ;
return V_5 ;
}
void F_29 ( struct V_4 * V_5 )
{
if ( V_5 && F_30 ( & V_5 -> V_15 ) )
F_23 ( V_5 ) ;
}
T_1 F_31 ( struct V_4 * V_10 , T_5 * V_53 )
{
int V_14 ;
T_1 V_54 = fprintf ( V_53 , L_5 ,
V_10 -> V_7 , V_10 -> V_7 > 1 ? L_6 : L_7 ) ;
for ( V_14 = 0 ; V_14 < V_10 -> V_7 ; ++ V_14 )
V_54 += fprintf ( V_53 , L_8 , V_14 ? L_9 : L_7 , F_32 ( V_10 , V_14 ) ) ;
return V_54 + fprintf ( V_53 , L_10 ) ;
}
static int F_33 ( char * * V_55 , T_2 V_9 )
{
char * V_20 ;
T_1 V_8 ;
int V_56 ;
if ( F_34 ( & V_20 , L_11 , F_35 () , V_9 ) == - 1 )
return - V_57 ;
V_56 = F_36 ( V_20 , V_55 , & V_8 ) ;
if ( ! V_56 ) {
( * V_55 ) [ V_8 ] = 0 ;
F_37 ( * V_55 ) ;
}
free ( V_20 ) ;
return V_56 ;
}
static void F_38 ( struct V_4 * V_5 , int V_14 )
{
T_2 V_9 = F_32 ( V_5 , V_14 ) ;
char * V_55 = NULL ;
if ( V_9 == - 1 ) {
V_5 -> V_5 [ V_14 ] . V_55 = F_39 ( L_12 ) ;
return;
}
if ( F_33 ( & V_55 , V_9 ) )
F_40 ( L_13 , V_9 ) ;
V_5 -> V_5 [ V_14 ] . V_55 = V_55 ;
}
void F_41 ( struct V_4 * V_10 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_10 -> V_7 ; ++ V_14 )
F_38 ( V_10 , V_14 ) ;
}
