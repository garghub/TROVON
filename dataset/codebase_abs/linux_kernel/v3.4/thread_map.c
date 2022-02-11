static int F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 [ 0 ] == '.' )
return 0 ;
else
return 1 ;
}
struct V_4 * F_2 ( T_1 V_5 )
{
struct V_4 * V_6 ;
char V_7 [ 256 ] ;
int V_8 ;
struct V_1 * * V_9 = NULL ;
int V_10 ;
sprintf ( V_7 , L_1 , V_5 ) ;
V_8 = F_3 ( V_7 , & V_9 , F_1 , NULL ) ;
if ( V_8 <= 0 )
return NULL ;
V_6 = malloc ( sizeof( * V_6 ) + sizeof( T_1 ) * V_8 ) ;
if ( V_6 != NULL ) {
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
V_6 -> V_11 [ V_10 ] = atoi ( V_9 [ V_10 ] -> V_3 ) ;
V_6 -> V_12 = V_8 ;
}
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
free ( V_9 [ V_10 ] ) ;
free ( V_9 ) ;
return V_6 ;
}
struct V_4 * F_4 ( T_1 V_13 )
{
struct V_4 * V_6 = malloc ( sizeof( * V_6 ) + sizeof( T_1 ) ) ;
if ( V_6 != NULL ) {
V_6 -> V_11 [ 0 ] = V_13 ;
V_6 -> V_12 = 1 ;
}
return V_6 ;
}
struct V_4 * F_5 ( T_2 V_14 )
{
T_3 * V_15 ;
int V_16 = 32 , V_8 , V_10 ;
char V_17 [ 256 ] ;
struct V_1 V_1 , * V_18 , * * V_9 = NULL ;
struct V_4 * V_6 = malloc ( sizeof( * V_6 ) +
V_16 * sizeof( T_1 ) ) ;
if ( V_6 == NULL )
goto V_19;
V_15 = F_6 ( L_2 ) ;
if ( V_15 == NULL )
goto V_20;
V_6 -> V_12 = 0 ;
while ( ! F_7 ( V_15 , & V_1 , & V_18 ) && V_18 ) {
char * V_21 ;
bool V_22 = false ;
struct V_23 V_24 ;
T_1 V_5 = strtol ( V_1 . V_3 , & V_21 , 10 ) ;
if ( * V_21 )
continue;
snprintf ( V_17 , sizeof( V_17 ) , L_3 , V_1 . V_3 ) ;
if ( V_23 ( V_17 , & V_24 ) != 0 )
continue;
if ( V_24 . V_25 != V_14 )
continue;
snprintf ( V_17 , sizeof( V_17 ) , L_1 , V_5 ) ;
V_8 = F_3 ( V_17 , & V_9 , F_1 , NULL ) ;
if ( V_8 <= 0 )
goto V_26;
while ( V_6 -> V_12 + V_8 >= V_16 ) {
V_16 *= 2 ;
V_22 = true ;
}
if ( V_22 ) {
struct V_4 * V_27 ;
V_27 = realloc ( V_6 , ( sizeof( * V_6 ) +
V_16 * sizeof( T_1 ) ) ) ;
if ( V_27 == NULL )
goto V_28;
V_6 = V_27 ;
}
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
V_6 -> V_11 [ V_6 -> V_12 + V_10 ] = atoi ( V_9 [ V_10 ] -> V_3 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
free ( V_9 [ V_10 ] ) ;
free ( V_9 ) ;
V_6 -> V_12 += V_8 ;
}
V_29:
F_8 ( V_15 ) ;
V_19:
return V_6 ;
V_20:
free ( V_6 ) ;
return NULL ;
V_28:
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
free ( V_9 [ V_10 ] ) ;
free ( V_9 ) ;
V_26:
free ( V_6 ) ;
V_6 = NULL ;
goto V_29;
}
struct V_4 * F_9 ( T_1 V_5 , T_1 V_13 , T_2 V_14 )
{
if ( V_5 != - 1 )
return F_2 ( V_5 ) ;
if ( V_13 == - 1 && V_14 != V_30 )
return F_5 ( V_14 ) ;
return F_4 ( V_13 ) ;
}
static struct V_4 * F_10 ( const char * V_31 )
{
struct V_4 * V_6 = NULL , * V_32 ;
char V_7 [ 256 ] ;
int V_8 , V_33 = 0 ;
struct V_1 * * V_9 = NULL ;
int V_10 , V_34 = 0 ;
T_1 V_5 , V_35 = V_36 ;
char * V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 = F_11 ( false , V_31 ) ;
if ( ! V_41 )
return NULL ;
F_12 (pos, slist) {
V_5 = strtol ( V_39 -> V_42 , & V_37 , 10 ) ;
if ( V_5 == V_43 || V_5 == V_36 ||
( * V_37 != '\0' && * V_37 != ',' ) )
goto V_20;
if ( V_5 == V_35 )
continue;
sprintf ( V_7 , L_1 , V_5 ) ;
V_8 = F_3 ( V_7 , & V_9 , F_1 , NULL ) ;
if ( V_8 <= 0 )
goto V_20;
V_33 += V_8 ;
V_32 = realloc ( V_6 , ( sizeof( * V_6 ) +
sizeof( T_1 ) * V_33 ) ) ;
if ( V_32 == NULL )
goto V_20;
V_6 = V_32 ;
if ( V_6 ) {
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
V_6 -> V_11 [ V_34 ++ ] = atoi ( V_9 [ V_10 ] -> V_3 ) ;
V_6 -> V_12 = V_33 ;
}
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
free ( V_9 [ V_10 ] ) ;
free ( V_9 ) ;
if ( ! V_6 )
break;
}
V_19:
F_13 ( V_41 ) ;
return V_6 ;
V_20:
free ( V_6 ) ;
V_6 = NULL ;
goto V_19;
}
static struct V_4 * F_14 ( const char * V_44 )
{
struct V_4 * V_6 = NULL , * V_32 ;
int V_45 = 0 ;
T_1 V_13 , V_46 = V_36 ;
char * V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
if ( ! V_44 ) {
V_6 = malloc ( sizeof( * V_6 ) + sizeof( T_1 ) ) ;
if ( V_6 != NULL ) {
V_6 -> V_11 [ 0 ] = - 1 ;
V_6 -> V_12 = 1 ;
}
return V_6 ;
}
V_41 = F_11 ( false , V_44 ) ;
if ( ! V_41 )
return NULL ;
F_12 (pos, slist) {
V_13 = strtol ( V_39 -> V_42 , & V_37 , 10 ) ;
if ( V_13 == V_43 || V_13 == V_36 ||
( * V_37 != '\0' && * V_37 != ',' ) )
goto V_20;
if ( V_13 == V_46 )
continue;
V_45 ++ ;
V_32 = realloc ( V_6 , sizeof( * V_6 ) + sizeof( T_1 ) * V_45 ) ;
if ( V_32 == NULL )
goto V_20;
V_6 = V_32 ;
V_6 -> V_11 [ V_45 - 1 ] = V_13 ;
V_6 -> V_12 = V_45 ;
}
V_19:
return V_6 ;
V_20:
free ( V_6 ) ;
V_6 = NULL ;
goto V_19;
}
struct V_4 * F_15 ( const char * V_5 , const char * V_13 ,
T_2 V_14 )
{
if ( V_5 )
return F_10 ( V_5 ) ;
if ( ! V_13 && V_14 != V_30 )
return F_5 ( V_14 ) ;
return F_14 ( V_13 ) ;
}
void F_16 ( struct V_4 * V_6 )
{
free ( V_6 ) ;
}
T_4 F_17 ( struct V_4 * V_6 , T_5 * V_47 )
{
int V_10 ;
T_4 V_48 = fprintf ( V_47 , L_4 ,
V_6 -> V_12 , V_6 -> V_12 > 1 ? L_5 : L_6 ) ;
for ( V_10 = 0 ; V_10 < V_6 -> V_12 ; ++ V_10 )
V_48 += fprintf ( V_47 , L_7 , V_10 ? L_8 : L_6 , V_6 -> V_11 [ V_10 ] ) ;
return V_48 + fprintf ( V_47 , L_9 ) ;
}
