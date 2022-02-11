static int F_1 ( struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , const char * V_5 )
{
struct V_6 * V_7 = NULL ;
struct V_8 * V_9 = NULL ;
const char * V_10 = L_1 ;
T_1 * V_11 ;
if ( V_2 == NULL )
return - 1 ;
V_11 = fopen ( V_3 , L_2 ) ;
if ( ! V_11 )
return - 1 ;
F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
fprintf ( V_11 , L_3 , V_10 ) ;
F_3 (&set->sections, section) {
if ( ! V_12 && V_7 -> V_13 )
continue;
fprintf ( V_11 , L_4 , V_7 -> V_14 ) ;
F_3 (&section->items, item) {
if ( ! V_12 && V_9 -> V_13 )
continue;
if ( V_9 -> V_5 )
fprintf ( V_11 , L_5 ,
V_9 -> V_14 , V_9 -> V_5 ) ;
}
}
fclose ( V_11 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , const char * V_4 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
if ( V_2 == NULL )
return - 1 ;
F_3 (&set->sections, section) {
if ( ! F_5 ( V_4 , V_7 -> V_14 ) )
continue;
F_3 (&section->items, item) {
const char * V_14 = V_4 + strlen ( V_7 -> V_14 ) + 1 ;
if ( strcmp ( V_14 , V_9 -> V_14 ) == 0 ) {
char * V_5 = V_9 -> V_5 ;
if ( V_5 ) {
printf ( L_6 , V_4 , V_5 ) ;
return 0 ;
}
}
}
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
if ( V_2 == NULL )
return - 1 ;
F_7 (set, section, item) {
char * V_5 = V_9 -> V_5 ;
if ( V_5 )
printf ( L_7 , V_7 -> V_14 ,
V_9 -> V_14 , V_5 ) ;
}
return 0 ;
}
static int F_8 ( char * V_15 , char * * V_4 , char * * V_5 )
{
const char * V_16 = strchr ( V_15 , '.' ) ;
if ( V_16 == NULL || V_16 == V_15 ) {
F_9 ( L_8 , V_15 ) ;
return - 1 ;
}
if ( ! V_16 [ 1 ] ) {
F_9 ( L_9 , V_15 ) ;
return - 1 ;
}
* V_5 = strchr ( V_15 , '=' ) ;
if ( * V_5 == NULL )
* V_4 = V_15 ;
else if ( ! strcmp ( * V_5 , L_10 ) ) {
F_9 ( L_11 , V_15 ) ;
return - 1 ;
} else {
* V_5 = * V_5 + 1 ;
* V_4 = F_10 ( & V_15 , L_10 ) ;
if ( * V_4 [ 0 ] == '\0' ) {
F_9 ( L_12 , V_15 ) ;
return - 1 ;
}
}
return 0 ;
}
int F_11 ( int V_17 , const char * * V_18 )
{
int V_19 , V_20 = - 1 ;
struct V_1 * V_2 ;
char * V_21 = F_12 ( L_13 , getenv ( L_14 ) ) ;
const char * V_22 ;
V_17 = F_13 ( V_17 , V_18 , V_23 , V_24 ,
V_25 ) ;
if ( V_12 && V_26 ) {
F_9 ( L_15 ) ;
F_14 ( V_24 , V_23 , L_16 , 0 ) ;
F_14 ( NULL , V_23 , L_17 , 0 ) ;
return - 1 ;
}
if ( V_12 )
V_27 = F_15 () ;
else if ( V_26 )
V_27 = V_21 ;
if ( ! V_27 )
V_22 = V_21 ;
else
V_22 = V_27 ;
V_2 = F_16 () ;
if ( ! V_2 )
goto V_28;
switch ( V_29 ) {
case V_30 :
if ( V_17 ) {
F_9 ( L_18 ) ;
F_14 ( V_24 , V_23 , L_19 , 1 ) ;
} else {
if ( F_6 ( V_2 ) < 0 ) {
F_9 ( L_20
L_21 , V_22 ) ;
goto V_28;
}
}
break;
default:
if ( ! V_17 ) {
F_17 ( V_24 , V_23 ) ;
break;
}
for ( V_19 = 0 ; V_18 [ V_19 ] ; V_19 ++ ) {
char * V_4 , * V_5 ;
char * V_15 = F_18 ( V_18 [ V_19 ] ) ;
if ( ! V_15 ) {
F_9 ( L_22 , V_31 ) ;
goto V_28;
}
if ( F_8 ( V_15 , & V_4 , & V_5 ) < 0 ) {
free ( V_15 ) ;
goto V_28;
}
if ( V_5 == NULL ) {
if ( F_4 ( V_2 , V_4 ) < 0 ) {
F_9 ( L_23 ,
V_4 , V_22 ) ;
free ( V_15 ) ;
goto V_28;
}
} else {
if ( F_1 ( V_2 , V_22 , V_4 , V_5 ) < 0 ) {
F_9 ( L_24 ,
V_4 , V_5 , V_22 ) ;
free ( V_15 ) ;
goto V_28;
}
}
free ( V_15 ) ;
}
}
V_20 = 0 ;
V_28:
F_19 ( V_2 ) ;
return V_20 ;
}
