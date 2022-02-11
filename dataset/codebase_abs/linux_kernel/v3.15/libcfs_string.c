int F_1 ( const char * V_1 , const char * (* F_2)( int V_2 ) ,
int * V_3 , int V_4 , int V_5 )
{
const char * V_6 ;
char V_7 = 0 ;
int V_8 = V_4 , V_9 , V_10 , V_11 = 0 ;
while ( * V_1 != 0 ) {
while ( isspace ( * V_1 ) )
V_1 ++ ;
if ( * V_1 == 0 )
break;
if ( * V_1 == '+' || * V_1 == '-' ) {
V_7 = * V_1 ++ ;
if ( ! V_11 )
V_8 = * V_3 ;
while ( isspace ( * V_1 ) )
V_1 ++ ;
if ( * V_1 == 0 )
return - V_12 ;
}
for ( V_10 = 0 ; V_1 [ V_10 ] != 0 && ! isspace ( V_1 [ V_10 ] ) &&
V_1 [ V_10 ] != '+' && V_1 [ V_10 ] != '-' ; V_10 ++ ) ;
V_11 = 0 ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
V_6 = F_2 ( V_9 ) ;
if ( V_6 != NULL &&
strlen ( V_6 ) == V_10 &&
strncasecmp ( V_1 , V_6 , V_10 ) == 0 ) {
if ( V_7 == '-' )
V_8 &= ~ ( 1 << V_9 ) ;
else
V_8 |= ( 1 << V_9 ) ;
V_11 = 1 ;
break;
}
}
if ( ! V_11 && V_10 == 3 &&
( strncasecmp ( V_1 , L_1 , V_10 ) == 0 ) ) {
if ( V_7 == '-' )
V_8 = V_4 ;
else
V_8 = V_5 ;
V_11 = 1 ;
}
if ( ! V_11 ) {
F_3 ( L_2
L_3 , V_10 , V_1 ) ;
return - V_12 ;
}
V_1 += V_10 ;
}
* V_3 = V_8 ;
return 0 ;
}
char * F_4 ( char * V_1 , T_1 V_13 )
{
T_1 V_9 = 0 ;
char * V_14 ;
while ( V_9 < V_13 && * V_1 && isspace ( * V_1 ) ) {
++ V_9 ;
++ V_1 ;
}
if ( * V_1 == '\0' )
goto V_15;
V_14 = V_1 ;
while ( V_9 < V_13 && * V_14 != '\0' && ! isspace ( * V_14 ) ) {
++ V_9 ;
++ V_14 ;
}
* V_14 = '\0' ;
V_15:
return V_1 ;
}
char *
F_5 ( char * V_1 )
{
char * V_14 ;
while ( isspace ( * V_1 ) )
V_1 ++ ;
V_14 = V_1 + strlen ( V_1 ) ;
while ( V_14 > V_1 ) {
if ( ! isspace ( V_14 [ - 1 ] ) )
break;
V_14 -- ;
}
* V_14 = 0 ;
return V_1 ;
}
int
F_6 ( struct V_16 * V_17 , char V_18 , struct V_16 * V_19 )
{
char * V_14 ;
if ( V_17 -> V_20 == NULL )
return 0 ;
while ( V_17 -> V_21 ) {
if ( ! isspace ( * V_17 -> V_20 ) )
break;
V_17 -> V_20 ++ ;
V_17 -> V_21 -- ;
}
if ( V_17 -> V_21 == 0 )
return 0 ;
if ( * V_17 -> V_20 == V_18 ) {
return 0 ;
}
V_19 -> V_20 = V_17 -> V_20 ;
V_14 = memchr ( V_17 -> V_20 , V_18 , V_17 -> V_21 ) ;
if ( V_14 == NULL ) {
V_14 = V_17 -> V_20 + V_17 -> V_21 ;
V_17 -> V_20 = NULL ;
} else {
V_17 -> V_20 = V_14 + 1 ;
V_17 -> V_21 -= ( V_14 - V_19 -> V_20 + 1 ) ;
}
while ( -- V_14 != V_19 -> V_20 ) {
if ( ! isspace ( * V_14 ) )
break;
}
V_19 -> V_21 = V_14 - V_19 -> V_20 + 1 ;
return 1 ;
}
int
F_7 ( char * V_1 , int V_22 , unsigned * V_23 ,
unsigned V_24 , unsigned V_25 )
{
char * V_26 ;
V_1 = F_5 ( V_1 ) ;
* V_23 = strtoul ( V_1 , & V_26 , 0 ) ;
if ( V_26 == V_1 )
return 0 ;
for (; V_26 < V_1 + V_22 ; V_26 ++ ) {
if ( ! isspace ( * V_26 ) )
return 0 ;
}
return ( * V_23 >= V_24 && * V_23 <= V_25 ) ;
}
static int
F_8 ( struct V_16 * V_27 , unsigned V_24 , unsigned V_25 ,
int V_28 , struct V_29 * * V_30 )
{
struct V_29 * V_31 ;
struct V_16 V_32 ;
F_9 ( V_31 , sizeof( * V_31 ) ) ;
if ( V_31 == NULL )
return - V_33 ;
if ( V_27 -> V_21 == 1 && V_27 -> V_20 [ 0 ] == '*' ) {
V_31 -> V_34 = V_24 ;
V_31 -> V_35 = V_25 ;
V_31 -> V_36 = 1 ;
goto V_15;
}
if ( F_7 ( V_27 -> V_20 , V_27 -> V_21 ,
& V_31 -> V_34 , V_24 , V_25 ) ) {
V_31 -> V_35 = V_31 -> V_34 ;
V_31 -> V_36 = 1 ;
goto V_15;
}
if ( ! V_28 || ! F_6 ( V_27 , '-' , & V_32 ) )
goto V_37;
if ( ! F_7 ( V_32 . V_20 , V_32 . V_21 ,
& V_31 -> V_34 , V_24 , V_25 ) )
goto V_37;
if ( F_7 ( V_27 -> V_20 , V_27 -> V_21 ,
& V_31 -> V_35 , V_24 , V_25 ) ) {
V_31 -> V_36 = 1 ;
goto V_15;
}
if ( F_6 ( V_27 , '/' , & V_32 ) ) {
if ( ! F_7 ( V_32 . V_20 , V_32 . V_21 ,
& V_31 -> V_35 , V_24 , V_25 ) )
goto V_37;
if ( F_7 ( V_27 -> V_20 , V_27 -> V_21 ,
& V_31 -> V_36 , V_24 , V_25 ) ) {
goto V_15;
}
}
V_15:
* V_30 = V_31 ;
return 0 ;
V_37:
F_10 ( V_31 , sizeof( * V_31 ) ) ;
return - V_12 ;
}
int
F_11 ( T_2 V_38 , struct V_39 * V_40 )
{
struct V_29 * V_30 ;
F_12 (expr, &expr_list->el_exprs, re_link) {
if ( V_38 >= V_30 -> V_34 && V_38 <= V_30 -> V_35 &&
( ( V_38 - V_30 -> V_34 ) % V_30 -> V_36 ) == 0 )
return 1 ;
}
return 0 ;
}
int
F_13 ( struct V_39 * V_40 , int V_25 , T_2 * * V_41 )
{
struct V_29 * V_30 ;
T_2 * V_42 ;
int V_43 = 0 ;
int V_9 ;
F_12 (expr, &expr_list->el_exprs, re_link) {
for ( V_9 = V_30 -> V_34 ; V_9 <= V_30 -> V_35 ; V_9 ++ ) {
if ( ( ( V_9 - V_30 -> V_34 ) % V_30 -> V_36 ) == 0 )
V_43 ++ ;
}
}
if ( V_43 == 0 )
return 0 ;
if ( V_43 > V_25 ) {
F_14 ( L_4 ,
V_25 , V_43 ) ;
return - V_12 ;
}
F_9 ( V_42 , sizeof( V_42 [ 0 ] ) * V_43 ) ;
if ( V_42 == NULL )
return - V_33 ;
V_43 = 0 ;
F_12 (expr, &expr_list->el_exprs, re_link) {
for ( V_9 = V_30 -> V_34 ; V_9 <= V_30 -> V_35 ; V_9 ++ ) {
if ( ( ( V_9 - V_30 -> V_34 ) % V_30 -> V_36 ) == 0 )
V_42 [ V_43 ++ ] = V_9 ;
}
}
* V_41 = V_42 ;
return V_43 ;
}
void
F_15 ( struct V_39 * V_40 )
{
while ( ! F_16 ( & V_40 -> V_44 ) ) {
struct V_29 * V_30 ;
V_30 = F_17 ( V_40 -> V_44 . V_17 ,
struct V_29 , V_45 ) ,
F_18 ( & V_30 -> V_45 ) ;
F_10 ( V_30 , sizeof( * V_30 ) ) ;
}
F_10 ( V_40 , sizeof( * V_40 ) ) ;
}
int
F_19 ( char * V_1 , int V_10 , unsigned V_24 , unsigned V_25 ,
struct V_39 * * V_46 )
{
struct V_39 * V_40 ;
struct V_29 * V_30 ;
struct V_16 V_27 ;
int V_47 ;
F_9 ( V_40 , sizeof( * V_40 ) ) ;
if ( V_40 == NULL )
return - V_33 ;
V_27 . V_20 = V_1 ;
V_27 . V_21 = V_10 ;
F_20 ( & V_40 -> V_44 ) ;
if ( V_27 . V_20 [ 0 ] == '[' &&
V_27 . V_20 [ V_27 . V_21 - 1 ] == ']' ) {
V_27 . V_20 ++ ;
V_27 . V_21 -= 2 ;
V_47 = - V_12 ;
while ( V_27 . V_20 != NULL ) {
struct V_16 V_32 ;
if ( ! F_6 ( & V_27 , ',' , & V_32 ) ) {
V_47 = - V_12 ;
break;
}
V_47 = F_8 ( & V_32 , V_24 , V_25 , 1 , & V_30 ) ;
if ( V_47 != 0 )
break;
F_21 ( & V_30 -> V_45 ,
& V_40 -> V_44 ) ;
}
} else {
V_47 = F_8 ( & V_27 , V_24 , V_25 , 0 , & V_30 ) ;
if ( V_47 == 0 ) {
F_21 ( & V_30 -> V_45 ,
& V_40 -> V_44 ) ;
}
}
if ( V_47 != 0 )
F_15 ( V_40 ) ;
else
* V_46 = V_40 ;
return V_47 ;
}
void
F_22 ( struct V_48 * V_49 )
{
struct V_39 * V_50 ;
while ( ! F_16 ( V_49 ) ) {
V_50 = F_17 ( V_49 -> V_17 ,
struct V_39 , V_51 ) ;
F_18 ( & V_50 -> V_51 ) ;
F_15 ( V_50 ) ;
}
}
int
F_23 ( char * V_1 , int V_10 , struct V_48 * V_49 )
{
struct V_39 * V_50 ;
struct V_16 V_27 ;
int V_47 ;
int V_9 ;
V_27 . V_20 = V_1 ;
V_27 . V_21 = V_10 ;
V_9 = 0 ;
while ( V_27 . V_20 != NULL ) {
struct V_16 V_19 ;
if ( ! F_6 ( & V_27 , '.' , & V_19 ) ) {
V_47 = - V_12 ;
goto V_15;
}
V_47 = F_19 ( V_19 . V_20 , V_19 . V_21 , 0 , 255 , & V_50 ) ;
if ( V_47 != 0 )
goto V_15;
F_21 ( & V_50 -> V_51 , V_49 ) ;
V_9 ++ ;
}
if ( V_9 == 4 )
return 0 ;
V_47 = - V_12 ;
V_15:
F_22 ( V_49 ) ;
return V_47 ;
}
int
F_24 ( T_2 V_52 , struct V_48 * V_49 )
{
struct V_39 * V_50 ;
int V_9 = 0 ;
F_25 (el, list, el_link) {
if ( ! F_11 ( V_52 & 0xff , V_50 ) )
return 0 ;
V_52 >>= 8 ;
V_9 ++ ;
}
return V_9 == 4 ;
}
void
F_26 ( struct V_48 * V_49 )
{
F_22 ( V_49 ) ;
}
