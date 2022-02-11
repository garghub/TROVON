static int F_1 ( const char * string )
{
const char * V_1 ;
V_1 = F_2 ( F_3 () ) ;
fflush ( stdout ) ;
if ( string )
F_4 ( L_1 , string , V_1 ) ;
else
F_4 ( L_2 , V_1 ) ;
return - 1 ;
}
static int F_5 ( T_1 * V_2 , struct V_3 * V_4 )
{
long V_5 ;
long V_6 ;
T_2 * * V_7 ;
T_3 V_8 = FALSE ;
if ( ( F_6 ( V_2 ) & V_9 ) == 0 )
return F_1 ( F_7 ( V_2 ) ) ;
V_5 = F_8 ( V_2 ) ;
if ( V_5 == 0L ) {
V_5 = F_9 ( V_2 ) ;
V_8 = TRUE ;
}
if ( V_5 < 0L )
return F_1 ( F_7 ( V_2 ) ) ;
V_7 = malloc ( V_5 ) ;
if ( V_8 )
V_6 = F_10 ( V_2 , V_7 ) ;
else
V_6 = F_11 ( V_2 , V_7 ) ;
if ( V_6 < 0 ) {
free ( V_7 ) ;
return F_1 ( F_7 ( V_2 ) ) ;
}
V_4 -> V_7 = V_7 ;
return 0 ;
}
static void F_12 ( T_1 * V_2 , T_4 * V_10 , void * V_11 )
{
T_5 V_12 , V_13 ;
T_6 V_14 ;
struct V_3 * V_4 = V_11 ;
if ( V_4 -> V_15 )
return;
if ( ( F_13 ( V_2 , V_10 ) & V_16 ) == 0 )
return;
V_12 = V_4 -> V_17 ;
V_13 = F_14 ( V_2 , V_10 ) ;
V_14 = F_15 ( V_10 ) ;
if ( V_12 < V_13 || V_12 >= V_13 + V_14 )
return;
V_4 -> V_15 = F_16 ( V_2 , V_10 , V_4 -> V_7 , V_12 - V_13 ,
& V_4 -> V_18 , & V_4 -> V_19 ,
& V_4 -> line ) ;
}
static struct V_3 * F_17 ( const char * V_20 )
{
T_1 * V_2 ;
struct V_3 * V_4 = NULL ;
V_2 = F_18 ( V_20 , NULL ) ;
if ( V_2 == NULL )
return NULL ;
if ( ! F_19 ( V_2 , V_21 ) )
goto V_22;
V_4 = F_20 ( sizeof( * V_4 ) ) ;
if ( V_4 == NULL )
goto V_22;
V_4 -> V_2 = V_2 ;
V_4 -> V_23 = F_21 ( V_20 ) ;
if ( V_4 -> V_23 == NULL )
goto V_22;
if ( F_5 ( V_2 , V_4 ) )
goto V_22;
return V_4 ;
V_22:
if ( V_4 ) {
F_22 ( ( char * * ) & V_4 -> V_23 ) ;
free ( V_4 ) ;
}
F_23 ( V_2 ) ;
return NULL ;
}
static void F_24 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 )
F_23 ( V_4 -> V_2 ) ;
F_22 ( ( char * * ) & V_4 -> V_23 ) ;
F_22 ( & V_4 -> V_7 ) ;
free ( V_4 ) ;
}
static int F_25 ( const char * V_24 , T_7 V_17 ,
char * * V_25 , unsigned int * line , struct V_26 * V_26 )
{
int V_27 = 0 ;
struct V_3 * V_4 = V_26 -> V_4 ;
if ( ! V_4 ) {
V_26 -> V_4 = F_17 ( V_24 ) ;
V_4 = V_26 -> V_4 ;
}
if ( V_4 == NULL ) {
F_26 ( L_3 , V_24 ) ;
return 0 ;
}
V_4 -> V_17 = V_17 ;
V_4 -> V_15 = false ;
F_27 ( V_4 -> V_2 , F_12 , V_4 ) ;
if ( V_4 -> V_15 && V_4 -> V_18 ) {
* V_25 = F_21 ( V_4 -> V_18 ) ;
* line = V_4 -> line ;
if ( * V_25 )
V_27 = 1 ;
}
return V_27 ;
}
void F_28 ( struct V_26 * V_26 )
{
struct V_3 * V_4 = V_26 -> V_4 ;
if ( ! V_4 )
return;
F_24 ( V_4 ) ;
V_26 -> V_4 = NULL ;
}
static int F_25 ( const char * V_24 , T_7 V_17 ,
char * * V_25 , unsigned int * V_28 ,
struct V_26 * V_26 V_29 )
{
T_8 * V_30 ;
char V_31 [ V_32 ] ;
char * V_18 = NULL ;
T_9 V_33 ;
char * V_34 ;
int V_27 = 0 ;
F_29 ( V_31 , sizeof( V_31 ) , L_4 V_35 ,
V_24 , V_17 ) ;
V_30 = F_30 ( V_31 , L_5 ) ;
if ( V_30 == NULL ) {
F_26 ( L_6 , V_24 ) ;
return 0 ;
}
if ( F_31 ( & V_18 , & V_33 , V_30 ) < 0 || ! V_33 ) {
F_26 ( L_7 , V_24 ) ;
goto V_22;
}
V_34 = strchr ( V_18 , '\n' ) ;
if ( V_34 )
* V_34 = '\0' ;
if ( ! strcmp ( V_18 , L_8 ) ) {
F_4 ( L_9 , V_24 ) ;
free ( V_18 ) ;
goto V_22;
}
V_34 = strchr ( V_18 , ':' ) ;
if ( V_34 ) {
* V_34 ++ = '\0' ;
* V_25 = V_18 ;
* V_28 = strtoul ( V_34 , NULL , 0 ) ;
V_27 = 1 ;
}
V_22:
F_32 ( V_30 ) ;
return V_27 ;
}
void F_28 ( struct V_26 * V_26 V_29 )
{
}
char * F_33 ( struct V_26 * V_26 , T_7 V_17 , struct V_36 * V_37 ,
bool V_38 )
{
char * V_25 = NULL ;
unsigned line = 0 ;
char * V_39 ;
const char * V_24 ;
if ( ! V_26 -> V_40 )
goto V_22;
if ( V_26 -> V_41 )
V_24 = V_26 -> V_41 ;
else
V_24 = V_26 -> V_42 ;
if ( V_24 [ 0 ] == '[' )
goto V_22;
if ( ! strncmp ( V_24 , L_10 , 10 ) )
goto V_22;
if ( ! F_25 ( V_24 , V_17 , & V_25 , & line , V_26 ) )
goto V_22;
if ( F_34 ( & V_39 , L_11 ,
V_43 ? V_25 : F_35 ( V_25 ) ,
line ) < 0 ) {
free ( V_25 ) ;
goto V_22;
}
V_26 -> V_44 = 0 ;
free ( V_25 ) ;
return V_39 ;
V_22:
if ( V_26 -> V_44 && ++ V_26 -> V_44 > V_45 ) {
V_26 -> V_40 = 0 ;
F_28 ( V_26 ) ;
}
if ( V_37 ) {
if ( F_34 ( & V_39 , L_12 V_46 , V_38 ? V_37 -> V_47 : L_13 ,
V_17 - V_37 -> V_48 ) < 0 )
return V_49 ;
} else if ( F_34 ( & V_39 , L_14 V_35 L_15 , V_26 -> V_50 , V_17 ) < 0 )
return V_49 ;
return V_39 ;
}
void F_36 ( char * V_39 )
{
if ( V_39 && strcmp ( V_39 , V_49 ) != 0 )
free ( V_39 ) ;
}
