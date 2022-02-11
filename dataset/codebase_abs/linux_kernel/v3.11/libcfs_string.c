int F_1 ( const char * V_1 , const char * V_2 , T_1 V_3 )
{
if ( V_1 == NULL || V_2 == NULL )
return 1 ;
if ( V_3 == 0 )
return 0 ;
while ( V_3 -- != 0 && tolower ( * V_1 ) == tolower ( * V_2 ) ) {
if ( V_3 == 0 || * V_1 == '\0' || * V_2 == '\0' )
break;
V_1 ++ ;
V_2 ++ ;
}
return tolower ( * ( unsigned char * ) V_1 ) - tolower ( * ( unsigned char * ) V_2 ) ;
}
int F_2 ( const char * V_4 , const char * (* F_3)( int V_5 ) ,
int * V_6 , int V_7 , int V_8 )
{
const char * V_9 ;
char V_10 = 0 ;
int V_11 = V_7 , V_12 , V_13 , V_14 = 0 ;
V_15 ;
while ( * V_4 != 0 ) {
while ( isspace ( * V_4 ) )
V_4 ++ ;
if ( * V_4 == 0 )
break;
if ( * V_4 == '+' || * V_4 == '-' ) {
V_10 = * V_4 ++ ;
if ( ! V_14 )
V_11 = * V_6 ;
while ( isspace ( * V_4 ) )
V_4 ++ ;
if ( * V_4 == 0 )
return - V_16 ;
}
for ( V_13 = 0 ; V_4 [ V_13 ] != 0 && ! isspace ( V_4 [ V_13 ] ) &&
V_4 [ V_13 ] != '+' && V_4 [ V_13 ] != '-' ; V_13 ++ ) ;
V_14 = 0 ;
for ( V_12 = 0 ; V_12 < 32 ; V_12 ++ ) {
V_9 = F_3 ( V_12 ) ;
if ( V_9 != NULL &&
strlen ( V_9 ) == V_13 &&
F_1 ( V_4 , V_9 , V_13 ) == 0 ) {
if ( V_10 == '-' )
V_11 &= ~ ( 1 << V_12 ) ;
else
V_11 |= ( 1 << V_12 ) ;
V_14 = 1 ;
break;
}
}
if ( ! V_14 && V_13 == 3 &&
( F_1 ( V_4 , L_1 , V_13 ) == 0 ) ) {
if ( V_10 == '-' )
V_11 = V_7 ;
else
V_11 = V_8 ;
V_14 = 1 ;
}
if ( ! V_14 ) {
F_4 ( L_2
L_3 , V_13 , V_4 ) ;
return - V_16 ;
}
V_4 += V_13 ;
}
* V_6 = V_11 ;
return 0 ;
}
char * F_5 ( const char * V_4 , T_2 V_17 )
{
T_1 V_18 ;
char * V_19 ;
V_18 = strlen ( V_4 ) + 1 ;
V_19 = F_6 ( V_18 , V_17 ) ;
if ( V_19 == NULL )
return NULL ;
memcpy ( V_19 , V_4 , V_18 ) ;
return V_19 ;
}
int F_7 ( char * V_20 , T_1 V_21 , const char * V_22 , T_3 args )
{
int V_12 ;
F_8 ( V_21 > 0 ) ;
V_12 = vsnprintf ( V_20 , V_21 , V_22 , args ) ;
return ( V_12 >= V_21 ? V_21 - 1 : V_12 ) ;
}
int F_9 ( char * V_20 , T_1 V_21 , const char * V_22 , ... )
{
T_3 args ;
int V_12 ;
va_start ( args , V_22 ) ;
V_12 = F_7 ( V_20 , V_21 , V_22 , args ) ;
va_end ( args ) ;
return V_12 ;
}
char * F_10 ( char * V_4 , T_1 V_21 )
{
T_1 V_12 = 0 ;
char * V_23 ;
while ( V_12 < V_21 && * V_4 && isspace ( * V_4 ) ) {
++ V_12 ;
++ V_4 ;
}
if ( * V_4 == '\0' )
goto V_24;
V_23 = V_4 ;
while ( V_12 < V_21 && * V_23 != '\0' && ! isspace ( * V_23 ) ) {
++ V_12 ;
++ V_23 ;
}
* V_23 = '\0' ;
V_24:
return V_4 ;
}
char *
F_11 ( char * V_4 )
{
char * V_23 ;
while ( F_12 ( * V_4 ) )
V_4 ++ ;
V_23 = V_4 + strlen ( V_4 ) ;
while ( V_23 > V_4 ) {
if ( ! F_12 ( V_23 [ - 1 ] ) )
break;
V_23 -- ;
}
* V_23 = 0 ;
return V_4 ;
}
int
F_13 ( struct V_25 * V_26 , char V_27 , struct V_25 * V_28 )
{
char * V_23 ;
if ( V_26 -> V_29 == NULL )
return 0 ;
while ( V_26 -> V_30 ) {
if ( ! F_12 ( * V_26 -> V_29 ) )
break;
V_26 -> V_29 ++ ;
V_26 -> V_30 -- ;
}
if ( V_26 -> V_30 == 0 )
return 0 ;
if ( * V_26 -> V_29 == V_27 ) {
return 0 ;
}
V_28 -> V_29 = V_26 -> V_29 ;
V_23 = memchr ( V_26 -> V_29 , V_27 , V_26 -> V_30 ) ;
if ( V_23 == NULL ) {
V_23 = V_26 -> V_29 + V_26 -> V_30 ;
V_26 -> V_29 = NULL ;
} else {
V_26 -> V_29 = V_23 + 1 ;
V_26 -> V_30 -= ( V_23 - V_28 -> V_29 + 1 ) ;
}
while ( -- V_23 != V_28 -> V_29 ) {
if ( ! F_12 ( * V_23 ) )
break;
}
V_28 -> V_30 = V_23 - V_28 -> V_29 + 1 ;
return 1 ;
}
int
F_14 ( char * V_4 , int V_31 , unsigned * V_32 ,
unsigned V_33 , unsigned V_34 )
{
char * V_35 ;
V_4 = F_11 ( V_4 ) ;
* V_32 = strtoul ( V_4 , & V_35 , 0 ) ;
if ( V_35 == V_4 )
return 0 ;
for (; V_35 < V_4 + V_31 ; V_35 ++ ) {
if ( ! F_12 ( * V_35 ) )
return 0 ;
}
return ( * V_32 >= V_33 && * V_32 <= V_34 ) ;
}
int
F_15 ( struct V_25 * V_36 , unsigned V_33 , unsigned V_34 ,
int V_37 , struct V_38 * * V_39 )
{
struct V_38 * V_40 ;
struct V_25 V_41 ;
F_16 ( V_40 , sizeof( * V_40 ) ) ;
if ( V_40 == NULL )
return - V_42 ;
if ( V_36 -> V_30 == 1 && V_36 -> V_29 [ 0 ] == '*' ) {
V_40 -> V_43 = V_33 ;
V_40 -> V_44 = V_34 ;
V_40 -> V_45 = 1 ;
goto V_24;
}
if ( F_14 ( V_36 -> V_29 , V_36 -> V_30 ,
& V_40 -> V_43 , V_33 , V_34 ) ) {
V_40 -> V_44 = V_40 -> V_43 ;
V_40 -> V_45 = 1 ;
goto V_24;
}
if ( ! V_37 || ! F_13 ( V_36 , '-' , & V_41 ) )
goto V_46;
if ( ! F_14 ( V_41 . V_29 , V_41 . V_30 ,
& V_40 -> V_43 , V_33 , V_34 ) )
goto V_46;
if ( F_14 ( V_36 -> V_29 , V_36 -> V_30 ,
& V_40 -> V_44 , V_33 , V_34 ) ) {
V_40 -> V_45 = 1 ;
goto V_24;
}
if ( F_13 ( V_36 , '/' , & V_41 ) ) {
if ( ! F_14 ( V_41 . V_29 , V_41 . V_30 ,
& V_40 -> V_44 , V_33 , V_34 ) )
goto V_46;
if ( F_14 ( V_36 -> V_29 , V_36 -> V_30 ,
& V_40 -> V_45 , V_33 , V_34 ) ) {
goto V_24;
}
}
V_24:
* V_39 = V_40 ;
return 0 ;
V_46:
F_17 ( V_40 , sizeof( * V_40 ) ) ;
return - V_16 ;
}
int
F_18 ( T_4 V_47 , struct V_48 * V_49 )
{
struct V_38 * V_39 ;
F_19 (expr, &expr_list->el_exprs, re_link) {
if ( V_47 >= V_39 -> V_43 && V_47 <= V_39 -> V_44 &&
( ( V_47 - V_39 -> V_43 ) % V_39 -> V_45 ) == 0 )
return 1 ;
}
return 0 ;
}
int
F_20 ( struct V_48 * V_49 , int V_34 , T_4 * * V_50 )
{
struct V_38 * V_39 ;
T_4 * V_51 ;
int V_52 = 0 ;
int V_12 ;
F_19 (expr, &expr_list->el_exprs, re_link) {
for ( V_12 = V_39 -> V_43 ; V_12 <= V_39 -> V_44 ; V_12 ++ ) {
if ( ( ( V_12 - V_39 -> V_43 ) % V_39 -> V_45 ) == 0 )
V_52 ++ ;
}
}
if ( V_52 == 0 )
return 0 ;
if ( V_52 > V_34 ) {
F_21 ( L_4 ,
V_34 , V_52 ) ;
return - V_16 ;
}
F_16 ( V_51 , sizeof( V_51 [ 0 ] ) * V_52 ) ;
if ( V_51 == NULL )
return - V_42 ;
V_52 = 0 ;
F_19 (expr, &expr_list->el_exprs, re_link) {
for ( V_12 = V_39 -> V_43 ; V_12 <= V_39 -> V_44 ; V_12 ++ ) {
if ( ( ( V_12 - V_39 -> V_43 ) % V_39 -> V_45 ) == 0 )
V_51 [ V_52 ++ ] = V_12 ;
}
}
* V_50 = V_51 ;
return V_52 ;
}
void
F_22 ( struct V_48 * V_49 )
{
while ( ! F_23 ( & V_49 -> V_53 ) ) {
struct V_38 * V_39 ;
V_39 = F_24 ( V_49 -> V_53 . V_26 ,
struct V_38 , V_54 ) ,
F_25 ( & V_39 -> V_54 ) ;
F_17 ( V_39 , sizeof( * V_39 ) ) ;
}
F_17 ( V_49 , sizeof( * V_49 ) ) ;
}
void
F_26 ( struct V_48 * V_49 )
{
struct V_38 * V_39 ;
F_19 (expr, &expr_list->el_exprs, re_link) {
F_27 ( V_55 , L_5 ,
V_39 -> V_43 , V_39 -> V_44 , V_39 -> V_45 ) ;
}
}
int
F_28 ( char * V_4 , int V_13 , unsigned V_33 , unsigned V_34 ,
struct V_48 * * V_56 )
{
struct V_48 * V_49 ;
struct V_38 * V_39 ;
struct V_25 V_36 ;
int V_57 ;
F_16 ( V_49 , sizeof( * V_49 ) ) ;
if ( V_49 == NULL )
return - V_42 ;
V_36 . V_29 = V_4 ;
V_36 . V_30 = V_13 ;
F_29 ( & V_49 -> V_53 ) ;
if ( V_36 . V_29 [ 0 ] == '[' &&
V_36 . V_29 [ V_36 . V_30 - 1 ] == ']' ) {
V_36 . V_29 ++ ;
V_36 . V_30 -= 2 ;
V_57 = - V_16 ;
while ( V_36 . V_29 != NULL ) {
struct V_25 V_41 ;
if ( ! F_13 ( & V_36 , ',' , & V_41 ) ) {
V_57 = - V_16 ;
break;
}
V_57 = F_15 ( & V_41 , V_33 , V_34 , 1 , & V_39 ) ;
if ( V_57 != 0 )
break;
F_30 ( & V_39 -> V_54 ,
& V_49 -> V_53 ) ;
}
} else {
V_57 = F_15 ( & V_36 , V_33 , V_34 , 0 , & V_39 ) ;
if ( V_57 == 0 ) {
F_30 ( & V_39 -> V_54 ,
& V_49 -> V_53 ) ;
}
}
if ( V_57 != 0 )
F_22 ( V_49 ) ;
else
* V_56 = V_49 ;
return V_57 ;
}
void
F_31 ( struct V_58 * V_59 )
{
struct V_48 * V_60 ;
while ( ! F_23 ( V_59 ) ) {
V_60 = F_24 ( V_59 -> V_26 ,
struct V_48 , V_61 ) ;
F_25 ( & V_60 -> V_61 ) ;
F_22 ( V_60 ) ;
}
}
int
F_32 ( char * V_4 , int V_13 , struct V_58 * V_59 )
{
struct V_48 * V_60 ;
struct V_25 V_36 ;
int V_57 ;
int V_12 ;
V_36 . V_29 = V_4 ;
V_36 . V_30 = V_13 ;
V_12 = 0 ;
while ( V_36 . V_29 != NULL ) {
struct V_25 V_28 ;
if ( ! F_13 ( & V_36 , '.' , & V_28 ) ) {
V_57 = - V_16 ;
goto V_24;
}
V_57 = F_28 ( V_28 . V_29 , V_28 . V_30 , 0 , 255 , & V_60 ) ;
if ( V_57 != 0 )
goto V_24;
F_30 ( & V_60 -> V_61 , V_59 ) ;
V_12 ++ ;
}
if ( V_12 == 4 )
return 0 ;
V_57 = - V_16 ;
V_24:
F_31 ( V_59 ) ;
return V_57 ;
}
int
F_33 ( T_4 V_62 , struct V_58 * V_59 )
{
struct V_48 * V_60 ;
int V_12 = 0 ;
F_34 (el, list, el_link) {
if ( ! F_18 ( V_62 & 0xff , V_60 ) )
return 0 ;
V_62 >>= 8 ;
V_12 ++ ;
}
return V_12 == 4 ;
}
void
F_35 ( struct V_58 * V_59 )
{
F_31 ( V_59 ) ;
}
