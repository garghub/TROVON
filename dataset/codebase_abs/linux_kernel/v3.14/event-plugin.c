static void
F_1 ( struct V_1 * V_1 , const char * V_2 ,
const char * V_3 , void * V_4 )
{
struct V_5 * * V_5 = V_4 ;
T_1 V_6 ;
struct V_5 * V_7 ;
const char * V_8 ;
char * V_9 ;
void * V_10 ;
V_9 = malloc ( strlen ( V_2 ) + strlen ( V_3 ) + 2 ) ;
if ( ! V_9 ) {
F_2 ( L_1 ) ;
return;
}
strcpy ( V_9 , V_2 ) ;
strcat ( V_9 , L_2 ) ;
strcat ( V_9 , V_3 ) ;
V_10 = F_3 ( V_9 , V_11 | V_12 ) ;
if ( ! V_10 ) {
F_2 ( L_3 ,
V_9 , F_4 () ) ;
goto V_13;
}
V_8 = F_5 ( V_10 , V_14 ) ;
if ( ! V_8 )
V_8 = V_3 ;
V_6 = F_5 ( V_10 , V_15 ) ;
if ( ! V_6 ) {
F_2 ( L_4 ,
V_15 , V_9 , F_4 () ) ;
goto V_13;
}
V_7 = malloc ( sizeof( * V_7 ) ) ;
if ( ! V_7 ) {
F_2 ( L_1 ) ;
goto V_13;
}
V_7 -> V_16 = * V_5 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_17 = V_9 ;
* V_5 = V_7 ;
F_6 ( L_5 , V_9 ) ;
V_6 ( V_1 ) ;
return;
V_13:
free ( V_9 ) ;
}
static void
F_7 ( struct V_1 * V_1 , const char * V_18 ,
const char * V_2 ,
void (* F_1)( struct V_1 * V_1 ,
const char * V_2 ,
const char * V_17 ,
void * V_4 ) ,
void * V_4 )
{
struct V_19 * V_20 ;
struct V_21 V_22 ;
T_2 * V_23 ;
int V_24 ;
V_24 = V_21 ( V_2 , & V_22 ) ;
if ( V_24 < 0 )
return;
if ( ! F_8 ( V_22 . V_25 ) )
return;
V_23 = F_9 ( V_2 ) ;
if ( ! V_23 )
return;
while ( ( V_20 = F_10 ( V_23 ) ) ) {
const char * V_17 = V_20 -> V_26 ;
if ( strcmp ( V_17 , L_6 ) == 0 ||
strcmp ( V_17 , L_7 ) == 0 )
continue;
if ( strcmp ( V_17 + ( strlen ( V_17 ) - strlen ( V_18 ) ) , V_18 ) != 0 )
continue;
F_1 ( V_1 , V_2 , V_17 , V_4 ) ;
}
F_11 ( V_23 ) ;
}
static void
F_12 ( struct V_1 * V_1 , const char * V_18 ,
void (* F_1)( struct V_1 * V_1 ,
const char * V_2 ,
const char * V_17 ,
void * V_4 ) ,
void * V_4 )
{
char * V_27 ;
char * V_2 ;
char * V_28 ;
#ifdef F_13
F_7 ( V_1 , V_18 , F_13 , F_1 , V_4 ) ;
#endif
V_28 = getenv ( L_8 ) ;
if ( V_28 )
F_7 ( V_1 , V_18 , V_28 , F_1 , V_4 ) ;
V_27 = getenv ( L_9 ) ;
if ( ! V_27 )
return;
V_2 = malloc ( strlen ( V_27 ) + strlen ( V_29 ) + 2 ) ;
if ( ! V_2 ) {
F_2 ( L_1 ) ;
return;
}
strcpy ( V_2 , V_27 ) ;
strcat ( V_2 , L_2 ) ;
strcat ( V_2 , V_29 ) ;
F_7 ( V_1 , V_18 , V_2 , F_1 , V_4 ) ;
free ( V_2 ) ;
}
struct V_5 *
F_14 ( struct V_1 * V_1 )
{
struct V_5 * V_7 = NULL ;
F_12 ( V_1 , L_10 , F_1 , & V_7 ) ;
return V_7 ;
}
void
F_15 ( struct V_5 * V_5 , struct V_1 * V_1 )
{
T_3 V_6 ;
struct V_5 * V_7 ;
while ( V_5 ) {
V_7 = V_5 ;
V_5 = V_7 -> V_16 ;
V_6 = F_5 ( V_7 -> V_10 , V_30 ) ;
if ( V_6 )
V_6 ( V_1 ) ;
F_16 ( V_7 -> V_10 ) ;
free ( V_7 -> V_17 ) ;
free ( V_7 ) ;
}
}
