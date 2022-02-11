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
free ( ( void * ) V_4 -> V_23 ) ;
free ( V_4 ) ;
}
F_22 ( V_2 ) ;
return NULL ;
}
static void F_23 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 )
F_22 ( V_4 -> V_2 ) ;
free ( ( void * ) V_4 -> V_23 ) ;
free ( V_4 -> V_7 ) ;
free ( V_4 ) ;
}
static int F_24 ( const char * V_24 , unsigned long V_17 ,
char * * V_25 , unsigned int * line )
{
int V_26 = 0 ;
struct V_3 * V_4 ;
V_4 = F_17 ( V_24 ) ;
if ( V_4 == NULL ) {
F_25 ( L_3 , V_24 ) ;
return 0 ;
}
V_4 -> V_17 = V_17 ;
F_26 ( V_4 -> V_2 , F_12 , V_4 ) ;
if ( V_4 -> V_15 && V_4 -> V_18 ) {
* V_25 = F_21 ( V_4 -> V_18 ) ;
* line = V_4 -> line ;
if ( * V_25 )
V_26 = 1 ;
}
F_23 ( V_4 ) ;
return V_26 ;
}
static int F_24 ( const char * V_24 , unsigned long V_17 ,
char * * V_25 , unsigned int * V_27 )
{
T_7 * V_28 ;
char V_29 [ V_30 ] ;
char * V_18 = NULL ;
T_8 V_31 ;
char * V_32 ;
int V_26 = 0 ;
F_27 ( V_29 , sizeof( V_29 ) , L_4 V_33 ,
V_24 , V_17 ) ;
V_28 = F_28 ( V_29 , L_5 ) ;
if ( V_28 == NULL ) {
F_25 ( L_6 , V_24 ) ;
return 0 ;
}
if ( F_29 ( & V_18 , & V_31 , V_28 ) < 0 || ! V_31 ) {
F_25 ( L_7 , V_24 ) ;
goto V_22;
}
V_32 = strchr ( V_18 , '\n' ) ;
if ( V_32 )
* V_32 = '\0' ;
if ( ! strcmp ( V_18 , L_8 ) ) {
F_4 ( L_9 , V_24 ) ;
free ( V_18 ) ;
goto V_22;
}
V_32 = strchr ( V_18 , ':' ) ;
if ( V_32 ) {
* V_32 ++ = '\0' ;
* V_25 = V_18 ;
* V_27 = strtoul ( V_32 , NULL , 0 ) ;
V_26 = 1 ;
}
V_22:
F_30 ( V_28 ) ;
return V_26 ;
}
char * F_31 ( struct V_34 * V_34 , unsigned long V_17 )
{
char * V_25 = NULL ;
unsigned line = 0 ;
char * V_35 ;
char * V_24 = V_34 -> V_36 ;
T_8 V_14 ;
if ( ! V_34 -> V_37 )
return V_38 ;
if ( V_24 [ 0 ] == '[' )
goto V_22;
if ( ! strncmp ( V_24 , L_10 , 10 ) )
goto V_22;
if ( ! F_24 ( V_24 , V_17 , & V_25 , & line ) )
goto V_22;
V_14 = snprintf ( NULL , 0 , L_11 , V_25 , line ) + 1 ;
V_35 = malloc ( V_14 ) ;
if ( V_35 )
snprintf ( V_35 , V_14 , L_11 , V_25 , line ) ;
else
V_35 = V_38 ;
free ( V_25 ) ;
return V_35 ;
V_22:
V_34 -> V_37 = 0 ;
return V_38 ;
}
void F_32 ( char * V_35 )
{
if ( V_35 && strcmp ( V_35 , V_38 ) != 0 )
free ( V_35 ) ;
}
