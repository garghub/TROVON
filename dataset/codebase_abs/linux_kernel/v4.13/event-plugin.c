static void F_1 ( char * V_1 )
{
if ( ! V_1 )
return;
for (; * V_1 ; V_1 ++ )
* V_1 = tolower ( * V_1 ) ;
}
static int F_2 ( struct V_2 * V_3 , const char * V_4 )
{
char * V_5 ;
if ( ! V_4 ) {
if ( V_3 -> V_6 )
return 0 ;
V_3 -> V_7 ^= 1 ;
return 0 ;
}
if ( V_3 -> V_6 ) {
V_3 -> V_6 = V_4 ;
return 0 ;
}
V_5 = F_3 ( V_4 ) ;
if ( ! V_5 )
return - 1 ;
F_1 ( V_5 ) ;
if ( strcmp ( V_4 , L_1 ) == 0 || strcmp ( V_4 , L_2 ) == 0 )
V_3 -> V_7 = 1 ;
else if ( strcmp ( V_4 , L_3 ) == 0 || strcmp ( V_4 , L_4 ) == 0 )
V_3 -> V_7 = 0 ;
free ( V_5 ) ;
return 0 ;
}
char * * F_4 ( void )
{
struct V_8 * V_9 ;
struct V_2 * V_3 ;
char * * V_10 = NULL ;
char * V_11 ;
int V_12 = 0 ;
for ( V_9 = V_13 ; V_9 ; V_9 = V_9 -> V_14 ) {
for ( V_3 = V_9 -> V_15 ; V_3 -> V_11 ; V_3 ++ ) {
char * V_16 = V_3 -> V_17 ? V_3 -> V_17 : V_3 -> V_18 ;
char * * V_19 = V_10 ;
V_11 = malloc ( strlen ( V_3 -> V_11 ) + strlen ( V_16 ) + 2 ) ;
if ( ! V_11 )
goto V_20;
sprintf ( V_11 , L_5 , V_16 , V_3 -> V_11 ) ;
V_10 = realloc ( V_10 , V_12 + 2 ) ;
if ( ! V_10 ) {
V_10 = V_19 ;
free ( V_11 ) ;
goto V_20;
}
V_10 [ V_12 ++ ] = V_11 ;
V_10 [ V_12 ] = NULL ;
}
}
return V_10 ;
V_20:
while ( -- V_12 >= 0 )
free ( V_10 [ V_12 ] ) ;
free ( V_10 ) ;
return V_21 ;
}
void F_5 ( char * * V_10 )
{
int V_22 ;
if ( ! V_10 )
return;
if ( V_10 == V_21 )
return;
for ( V_22 = 0 ; V_10 [ V_22 ] ; V_22 ++ )
free ( V_10 [ V_22 ] ) ;
free ( V_10 ) ;
}
static int
F_6 ( const char * V_18 , struct V_2 * V_23 )
{
struct V_24 * V_3 ;
char * V_25 ;
int V_26 = 0 ;
if ( V_23 -> V_17 ) {
V_25 = F_3 ( V_23 -> V_17 ) ;
if ( ! V_25 )
return - 1 ;
} else {
char * V_27 ;
V_25 = F_3 ( V_18 ) ;
if ( ! V_25 )
return - 1 ;
V_27 = strstr ( V_25 , L_6 ) ;
if ( V_27 )
* V_27 = '\0' ;
}
for ( V_3 = V_24 ; V_3 ; V_3 = V_3 -> V_14 ) {
if ( ! V_3 -> V_25 )
continue;
if ( strcmp ( V_3 -> V_25 , V_25 ) != 0 )
continue;
if ( strcmp ( V_3 -> V_23 , V_23 -> V_11 ) != 0 )
continue;
V_26 = F_2 ( V_23 , V_3 -> V_6 ) ;
if ( V_26 )
goto V_28;
break;
}
for ( V_3 = V_24 ; V_3 ; V_3 = V_3 -> V_14 ) {
if ( V_3 -> V_25 )
continue;
if ( strcmp ( V_3 -> V_23 , V_23 -> V_11 ) != 0 )
continue;
V_26 = F_2 ( V_23 , V_3 -> V_6 ) ;
break;
}
V_28:
free ( V_25 ) ;
return V_26 ;
}
int F_7 ( const char * V_11 ,
struct V_2 * V_15 )
{
struct V_8 * V_9 ;
V_9 = malloc ( sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - 1 ;
V_9 -> V_14 = V_13 ;
V_9 -> V_15 = V_15 ;
V_13 = V_9 ;
while ( V_15 -> V_11 ) {
F_6 ( V_11 , V_15 ) ;
V_15 ++ ;
}
return 0 ;
}
void F_8 ( struct V_2 * V_15 )
{
struct V_8 * * V_29 ;
struct V_8 * V_9 ;
for ( V_29 = & V_13 ; * V_29 ; V_29 = & ( * V_29 ) -> V_14 ) {
if ( ( * V_29 ) -> V_15 == V_15 ) {
V_9 = * V_29 ;
* V_29 = V_9 -> V_14 ;
free ( V_9 ) ;
return;
}
}
}
void F_9 ( struct V_30 * V_31 ,
const char * V_32 , const char * V_33 ,
const struct V_34 * V_10 )
{
while ( V_10 ) {
F_10 ( V_31 , L_7 , V_32 , V_10 -> V_11 , V_33 ) ;
V_10 = V_10 -> V_14 ;
}
}
static void
F_11 ( struct V_35 * V_35 , const char * V_36 ,
const char * V_18 , void * V_37 )
{
struct V_34 * * V_34 = V_37 ;
T_1 V_38 ;
struct V_34 * V_10 ;
const char * V_16 ;
char * V_25 ;
void * V_39 ;
V_25 = malloc ( strlen ( V_36 ) + strlen ( V_18 ) + 2 ) ;
if ( ! V_25 ) {
F_12 ( L_8 ) ;
return;
}
strcpy ( V_25 , V_36 ) ;
strcat ( V_25 , L_9 ) ;
strcat ( V_25 , V_18 ) ;
V_39 = F_13 ( V_25 , V_40 | V_41 ) ;
if ( ! V_39 ) {
F_12 ( L_10 ,
V_25 , F_14 () ) ;
goto V_42;
}
V_16 = F_15 ( V_39 , V_43 ) ;
if ( ! V_16 )
V_16 = V_18 ;
V_38 = F_15 ( V_39 , V_44 ) ;
if ( ! V_38 ) {
F_12 ( L_11 ,
V_44 , V_25 , F_14 () ) ;
goto V_42;
}
V_10 = malloc ( sizeof( * V_10 ) ) ;
if ( ! V_10 ) {
F_12 ( L_8 ) ;
goto V_42;
}
V_10 -> V_14 = * V_34 ;
V_10 -> V_39 = V_39 ;
V_10 -> V_11 = V_25 ;
* V_34 = V_10 ;
F_16 ( L_12 , V_25 ) ;
V_38 ( V_35 ) ;
return;
V_42:
free ( V_25 ) ;
}
static void
F_17 ( struct V_35 * V_35 , const char * V_33 ,
const char * V_36 ,
void (* F_11)( struct V_35 * V_35 ,
const char * V_36 ,
const char * V_11 ,
void * V_37 ) ,
void * V_37 )
{
struct V_45 * V_46 ;
struct V_47 V_48 ;
T_2 * V_49 ;
int V_26 ;
V_26 = V_47 ( V_36 , & V_48 ) ;
if ( V_26 < 0 )
return;
if ( ! F_18 ( V_48 . V_50 ) )
return;
V_49 = F_19 ( V_36 ) ;
if ( ! V_49 )
return;
while ( ( V_46 = F_20 ( V_49 ) ) ) {
const char * V_11 = V_46 -> V_51 ;
if ( strcmp ( V_11 , L_6 ) == 0 ||
strcmp ( V_11 , L_13 ) == 0 )
continue;
if ( strcmp ( V_11 + ( strlen ( V_11 ) - strlen ( V_33 ) ) , V_33 ) != 0 )
continue;
F_11 ( V_35 , V_36 , V_11 , V_37 ) ;
}
F_21 ( V_49 ) ;
}
static void
F_22 ( struct V_35 * V_35 , const char * V_33 ,
void (* F_11)( struct V_35 * V_35 ,
const char * V_36 ,
const char * V_11 ,
void * V_37 ) ,
void * V_37 )
{
char * V_52 ;
char * V_36 ;
char * V_53 ;
if ( V_35 -> V_54 & V_55 )
return;
#ifdef F_23
if ( ! ( V_35 -> V_54 & V_56 ) )
F_17 ( V_35 , V_33 , F_23 ,
F_11 , V_37 ) ;
#endif
V_53 = getenv ( L_14 ) ;
if ( V_53 )
F_17 ( V_35 , V_33 , V_53 , F_11 , V_37 ) ;
V_52 = getenv ( L_15 ) ;
if ( ! V_52 )
return;
V_36 = malloc ( strlen ( V_52 ) + strlen ( V_57 ) + 2 ) ;
if ( ! V_36 ) {
F_12 ( L_8 ) ;
return;
}
strcpy ( V_36 , V_52 ) ;
strcat ( V_36 , L_9 ) ;
strcat ( V_36 , V_57 ) ;
F_17 ( V_35 , V_33 , V_36 , F_11 , V_37 ) ;
free ( V_36 ) ;
}
struct V_34 *
F_24 ( struct V_35 * V_35 )
{
struct V_34 * V_10 = NULL ;
F_22 ( V_35 , L_16 , F_11 , & V_10 ) ;
return V_10 ;
}
void
F_25 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
T_3 V_38 ;
struct V_34 * V_10 ;
while ( V_34 ) {
V_10 = V_34 ;
V_34 = V_10 -> V_14 ;
V_38 = F_15 ( V_10 -> V_39 , V_58 ) ;
if ( V_38 )
V_38 ( V_35 ) ;
F_26 ( V_10 -> V_39 ) ;
free ( V_10 -> V_11 ) ;
free ( V_10 ) ;
}
}
