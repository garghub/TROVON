char * * F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
char * * V_5 = NULL ;
char * V_6 ;
int V_7 = 0 ;
for ( V_2 = V_8 ; V_2 ; V_2 = V_2 -> V_9 ) {
for ( V_4 = V_2 -> V_10 ; V_4 -> V_6 ; V_4 ++ ) {
char * V_11 = V_4 -> V_12 ? V_4 -> V_12 : V_4 -> V_13 ;
char * * V_14 = V_5 ;
V_6 = malloc ( strlen ( V_4 -> V_6 ) + strlen ( V_11 ) + 2 ) ;
if ( ! V_6 )
goto V_15;
sprintf ( V_6 , L_1 , V_11 , V_4 -> V_6 ) ;
V_5 = realloc ( V_5 , V_7 + 2 ) ;
if ( ! V_5 ) {
V_5 = V_14 ;
free ( V_6 ) ;
goto V_15;
}
V_5 [ V_7 ++ ] = V_6 ;
V_5 [ V_7 ] = NULL ;
}
}
return V_5 ;
V_15:
while ( -- V_7 >= 0 )
free ( V_5 [ V_7 ] ) ;
free ( V_5 ) ;
return V_16 ;
}
void F_2 ( char * * V_5 )
{
int V_17 ;
if ( ! V_5 )
return;
if ( V_5 == V_16 )
return;
for ( V_17 = 0 ; V_5 [ V_17 ] ; V_17 ++ )
free ( V_5 [ V_17 ] ) ;
free ( V_5 ) ;
}
static int
F_3 ( const char * V_13 , struct V_3 * V_18 )
{
struct V_19 * V_4 ;
char * V_20 ;
if ( V_18 -> V_12 ) {
V_20 = F_4 ( V_18 -> V_12 ) ;
if ( ! V_20 )
return - 1 ;
} else {
char * V_21 ;
V_20 = F_4 ( V_13 ) ;
if ( ! V_20 )
return - 1 ;
V_21 = strstr ( V_20 , L_2 ) ;
if ( V_21 )
* V_21 = '\0' ;
}
for ( V_4 = V_19 ; V_4 ; V_4 = V_4 -> V_9 ) {
if ( ! V_4 -> V_20 )
continue;
if ( strcmp ( V_4 -> V_20 , V_20 ) != 0 )
continue;
if ( strcmp ( V_4 -> V_18 , V_18 -> V_6 ) != 0 )
continue;
V_18 -> V_22 = V_4 -> V_22 ;
V_18 -> V_23 ^= 1 ;
goto V_24;
}
for ( V_4 = V_19 ; V_4 ; V_4 = V_4 -> V_9 ) {
if ( V_4 -> V_20 )
continue;
if ( strcmp ( V_4 -> V_18 , V_18 -> V_6 ) != 0 )
continue;
V_18 -> V_22 = V_4 -> V_22 ;
V_18 -> V_23 ^= 1 ;
break;
}
V_24:
free ( V_20 ) ;
return 0 ;
}
int F_5 ( const char * V_6 ,
struct V_3 * V_10 )
{
struct V_1 * V_2 ;
V_2 = malloc ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
return - 1 ;
V_2 -> V_9 = V_8 ;
V_2 -> V_10 = V_10 ;
V_8 = V_2 ;
while ( V_10 -> V_6 ) {
F_3 ( V_6 , V_10 ) ;
V_10 ++ ;
}
return 0 ;
}
void F_6 ( struct V_3 * V_10 )
{
struct V_1 * * V_25 ;
struct V_1 * V_2 ;
for ( V_25 = & V_8 ; * V_25 ; V_25 = & ( * V_25 ) -> V_9 ) {
if ( ( * V_25 ) -> V_10 == V_10 ) {
V_2 = * V_25 ;
* V_25 = V_2 -> V_9 ;
free ( V_2 ) ;
return;
}
}
}
void F_7 ( struct V_26 * V_27 ,
const char * V_28 , const char * V_29 ,
const struct V_30 * V_5 )
{
while ( V_5 ) {
F_8 ( V_27 , L_3 , V_28 , V_5 -> V_6 , V_29 ) ;
V_5 = V_5 -> V_9 ;
}
}
static void
F_9 ( struct V_31 * V_31 , const char * V_32 ,
const char * V_13 , void * V_33 )
{
struct V_30 * * V_30 = V_33 ;
T_1 V_34 ;
struct V_30 * V_5 ;
const char * V_11 ;
char * V_20 ;
void * V_35 ;
V_20 = malloc ( strlen ( V_32 ) + strlen ( V_13 ) + 2 ) ;
if ( ! V_20 ) {
F_10 ( L_4 ) ;
return;
}
strcpy ( V_20 , V_32 ) ;
strcat ( V_20 , L_5 ) ;
strcat ( V_20 , V_13 ) ;
V_35 = F_11 ( V_20 , V_36 | V_37 ) ;
if ( ! V_35 ) {
F_10 ( L_6 ,
V_20 , F_12 () ) ;
goto V_38;
}
V_11 = F_13 ( V_35 , V_39 ) ;
if ( ! V_11 )
V_11 = V_13 ;
V_34 = F_13 ( V_35 , V_40 ) ;
if ( ! V_34 ) {
F_10 ( L_7 ,
V_40 , V_20 , F_12 () ) ;
goto V_38;
}
V_5 = malloc ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_10 ( L_4 ) ;
goto V_38;
}
V_5 -> V_9 = * V_30 ;
V_5 -> V_35 = V_35 ;
V_5 -> V_6 = V_20 ;
* V_30 = V_5 ;
F_14 ( L_8 , V_20 ) ;
V_34 ( V_31 ) ;
return;
V_38:
free ( V_20 ) ;
}
static void
F_15 ( struct V_31 * V_31 , const char * V_29 ,
const char * V_32 ,
void (* F_9)( struct V_31 * V_31 ,
const char * V_32 ,
const char * V_6 ,
void * V_33 ) ,
void * V_33 )
{
struct V_41 * V_42 ;
struct V_43 V_44 ;
T_2 * V_45 ;
int V_46 ;
V_46 = V_43 ( V_32 , & V_44 ) ;
if ( V_46 < 0 )
return;
if ( ! F_16 ( V_44 . V_47 ) )
return;
V_45 = F_17 ( V_32 ) ;
if ( ! V_45 )
return;
while ( ( V_42 = F_18 ( V_45 ) ) ) {
const char * V_6 = V_42 -> V_48 ;
if ( strcmp ( V_6 , L_2 ) == 0 ||
strcmp ( V_6 , L_9 ) == 0 )
continue;
if ( strcmp ( V_6 + ( strlen ( V_6 ) - strlen ( V_29 ) ) , V_29 ) != 0 )
continue;
F_9 ( V_31 , V_32 , V_6 , V_33 ) ;
}
F_19 ( V_45 ) ;
}
static void
F_20 ( struct V_31 * V_31 , const char * V_29 ,
void (* F_9)( struct V_31 * V_31 ,
const char * V_32 ,
const char * V_6 ,
void * V_33 ) ,
void * V_33 )
{
char * V_49 ;
char * V_32 ;
char * V_50 ;
if ( V_31 -> V_51 & V_52 )
return;
#ifdef F_21
if ( ! ( V_31 -> V_51 & V_53 ) )
F_15 ( V_31 , V_29 , F_21 ,
F_9 , V_33 ) ;
#endif
V_50 = getenv ( L_10 ) ;
if ( V_50 )
F_15 ( V_31 , V_29 , V_50 , F_9 , V_33 ) ;
V_49 = getenv ( L_11 ) ;
if ( ! V_49 )
return;
V_32 = malloc ( strlen ( V_49 ) + strlen ( V_54 ) + 2 ) ;
if ( ! V_32 ) {
F_10 ( L_4 ) ;
return;
}
strcpy ( V_32 , V_49 ) ;
strcat ( V_32 , L_5 ) ;
strcat ( V_32 , V_54 ) ;
F_15 ( V_31 , V_29 , V_32 , F_9 , V_33 ) ;
free ( V_32 ) ;
}
struct V_30 *
F_22 ( struct V_31 * V_31 )
{
struct V_30 * V_5 = NULL ;
F_20 ( V_31 , L_12 , F_9 , & V_5 ) ;
return V_5 ;
}
void
F_23 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
T_3 V_34 ;
struct V_30 * V_5 ;
while ( V_30 ) {
V_5 = V_30 ;
V_30 = V_5 -> V_9 ;
V_34 = F_13 ( V_5 -> V_35 , V_55 ) ;
if ( V_34 )
V_34 ( V_31 ) ;
F_24 ( V_5 -> V_35 ) ;
free ( V_5 -> V_6 ) ;
free ( V_5 ) ;
}
}
