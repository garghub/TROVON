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
return - V_15 ;
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
return - V_15 ;
}
V_4 += V_13 ;
}
* V_6 = V_11 ;
return 0 ;
}
char * F_5 ( char * V_4 , T_1 V_16 )
{
T_1 V_12 = 0 ;
char * V_17 ;
while ( V_12 < V_16 && * V_4 && isspace ( * V_4 ) ) {
++ V_12 ;
++ V_4 ;
}
if ( * V_4 == '\0' )
goto V_18;
V_17 = V_4 ;
while ( V_12 < V_16 && * V_17 != '\0' && ! isspace ( * V_17 ) ) {
++ V_12 ;
++ V_17 ;
}
* V_17 = '\0' ;
V_18:
return V_4 ;
}
char *
F_6 ( char * V_4 )
{
char * V_17 ;
while ( F_7 ( * V_4 ) )
V_4 ++ ;
V_17 = V_4 + strlen ( V_4 ) ;
while ( V_17 > V_4 ) {
if ( ! F_7 ( V_17 [ - 1 ] ) )
break;
V_17 -- ;
}
* V_17 = 0 ;
return V_4 ;
}
int
F_8 ( struct V_19 * V_20 , char V_21 , struct V_19 * V_22 )
{
char * V_17 ;
if ( V_20 -> V_23 == NULL )
return 0 ;
while ( V_20 -> V_24 ) {
if ( ! F_7 ( * V_20 -> V_23 ) )
break;
V_20 -> V_23 ++ ;
V_20 -> V_24 -- ;
}
if ( V_20 -> V_24 == 0 )
return 0 ;
if ( * V_20 -> V_23 == V_21 ) {
return 0 ;
}
V_22 -> V_23 = V_20 -> V_23 ;
V_17 = memchr ( V_20 -> V_23 , V_21 , V_20 -> V_24 ) ;
if ( V_17 == NULL ) {
V_17 = V_20 -> V_23 + V_20 -> V_24 ;
V_20 -> V_23 = NULL ;
} else {
V_20 -> V_23 = V_17 + 1 ;
V_20 -> V_24 -= ( V_17 - V_22 -> V_23 + 1 ) ;
}
while ( -- V_17 != V_22 -> V_23 ) {
if ( ! F_7 ( * V_17 ) )
break;
}
V_22 -> V_24 = V_17 - V_22 -> V_23 + 1 ;
return 1 ;
}
int
F_9 ( char * V_4 , int V_25 , unsigned * V_26 ,
unsigned V_27 , unsigned V_28 )
{
char * V_29 ;
V_4 = F_6 ( V_4 ) ;
* V_26 = strtoul ( V_4 , & V_29 , 0 ) ;
if ( V_29 == V_4 )
return 0 ;
for (; V_29 < V_4 + V_25 ; V_29 ++ ) {
if ( ! F_7 ( * V_29 ) )
return 0 ;
}
return ( * V_26 >= V_27 && * V_26 <= V_28 ) ;
}
int
F_10 ( struct V_19 * V_30 , unsigned V_27 , unsigned V_28 ,
int V_31 , struct V_32 * * V_33 )
{
struct V_32 * V_34 ;
struct V_19 V_35 ;
F_11 ( V_34 , sizeof( * V_34 ) ) ;
if ( V_34 == NULL )
return - V_36 ;
if ( V_30 -> V_24 == 1 && V_30 -> V_23 [ 0 ] == '*' ) {
V_34 -> V_37 = V_27 ;
V_34 -> V_38 = V_28 ;
V_34 -> V_39 = 1 ;
goto V_18;
}
if ( F_9 ( V_30 -> V_23 , V_30 -> V_24 ,
& V_34 -> V_37 , V_27 , V_28 ) ) {
V_34 -> V_38 = V_34 -> V_37 ;
V_34 -> V_39 = 1 ;
goto V_18;
}
if ( ! V_31 || ! F_8 ( V_30 , '-' , & V_35 ) )
goto V_40;
if ( ! F_9 ( V_35 . V_23 , V_35 . V_24 ,
& V_34 -> V_37 , V_27 , V_28 ) )
goto V_40;
if ( F_9 ( V_30 -> V_23 , V_30 -> V_24 ,
& V_34 -> V_38 , V_27 , V_28 ) ) {
V_34 -> V_39 = 1 ;
goto V_18;
}
if ( F_8 ( V_30 , '/' , & V_35 ) ) {
if ( ! F_9 ( V_35 . V_23 , V_35 . V_24 ,
& V_34 -> V_38 , V_27 , V_28 ) )
goto V_40;
if ( F_9 ( V_30 -> V_23 , V_30 -> V_24 ,
& V_34 -> V_39 , V_27 , V_28 ) ) {
goto V_18;
}
}
V_18:
* V_33 = V_34 ;
return 0 ;
V_40:
F_12 ( V_34 , sizeof( * V_34 ) ) ;
return - V_15 ;
}
int
F_13 ( T_2 V_41 , struct V_42 * V_43 )
{
struct V_32 * V_33 ;
F_14 (expr, &expr_list->el_exprs, re_link) {
if ( V_41 >= V_33 -> V_37 && V_41 <= V_33 -> V_38 &&
( ( V_41 - V_33 -> V_37 ) % V_33 -> V_39 ) == 0 )
return 1 ;
}
return 0 ;
}
int
F_15 ( struct V_42 * V_43 , int V_28 , T_2 * * V_44 )
{
struct V_32 * V_33 ;
T_2 * V_45 ;
int V_46 = 0 ;
int V_12 ;
F_14 (expr, &expr_list->el_exprs, re_link) {
for ( V_12 = V_33 -> V_37 ; V_12 <= V_33 -> V_38 ; V_12 ++ ) {
if ( ( ( V_12 - V_33 -> V_37 ) % V_33 -> V_39 ) == 0 )
V_46 ++ ;
}
}
if ( V_46 == 0 )
return 0 ;
if ( V_46 > V_28 ) {
F_16 ( L_4 ,
V_28 , V_46 ) ;
return - V_15 ;
}
F_11 ( V_45 , sizeof( V_45 [ 0 ] ) * V_46 ) ;
if ( V_45 == NULL )
return - V_36 ;
V_46 = 0 ;
F_14 (expr, &expr_list->el_exprs, re_link) {
for ( V_12 = V_33 -> V_37 ; V_12 <= V_33 -> V_38 ; V_12 ++ ) {
if ( ( ( V_12 - V_33 -> V_37 ) % V_33 -> V_39 ) == 0 )
V_45 [ V_46 ++ ] = V_12 ;
}
}
* V_44 = V_45 ;
return V_46 ;
}
void
F_17 ( struct V_42 * V_43 )
{
while ( ! F_18 ( & V_43 -> V_47 ) ) {
struct V_32 * V_33 ;
V_33 = F_19 ( V_43 -> V_47 . V_20 ,
struct V_32 , V_48 ) ,
F_20 ( & V_33 -> V_48 ) ;
F_12 ( V_33 , sizeof( * V_33 ) ) ;
}
F_12 ( V_43 , sizeof( * V_43 ) ) ;
}
void
F_21 ( struct V_42 * V_43 )
{
struct V_32 * V_33 ;
F_14 (expr, &expr_list->el_exprs, re_link) {
F_22 ( V_49 , L_5 ,
V_33 -> V_37 , V_33 -> V_38 , V_33 -> V_39 ) ;
}
}
int
F_23 ( char * V_4 , int V_13 , unsigned V_27 , unsigned V_28 ,
struct V_42 * * V_50 )
{
struct V_42 * V_43 ;
struct V_32 * V_33 ;
struct V_19 V_30 ;
int V_51 ;
F_11 ( V_43 , sizeof( * V_43 ) ) ;
if ( V_43 == NULL )
return - V_36 ;
V_30 . V_23 = V_4 ;
V_30 . V_24 = V_13 ;
F_24 ( & V_43 -> V_47 ) ;
if ( V_30 . V_23 [ 0 ] == '[' &&
V_30 . V_23 [ V_30 . V_24 - 1 ] == ']' ) {
V_30 . V_23 ++ ;
V_30 . V_24 -= 2 ;
V_51 = - V_15 ;
while ( V_30 . V_23 != NULL ) {
struct V_19 V_35 ;
if ( ! F_8 ( & V_30 , ',' , & V_35 ) ) {
V_51 = - V_15 ;
break;
}
V_51 = F_10 ( & V_35 , V_27 , V_28 , 1 , & V_33 ) ;
if ( V_51 != 0 )
break;
F_25 ( & V_33 -> V_48 ,
& V_43 -> V_47 ) ;
}
} else {
V_51 = F_10 ( & V_30 , V_27 , V_28 , 0 , & V_33 ) ;
if ( V_51 == 0 ) {
F_25 ( & V_33 -> V_48 ,
& V_43 -> V_47 ) ;
}
}
if ( V_51 != 0 )
F_17 ( V_43 ) ;
else
* V_50 = V_43 ;
return V_51 ;
}
void
F_26 ( struct V_52 * V_53 )
{
struct V_42 * V_54 ;
while ( ! F_18 ( V_53 ) ) {
V_54 = F_19 ( V_53 -> V_20 ,
struct V_42 , V_55 ) ;
F_20 ( & V_54 -> V_55 ) ;
F_17 ( V_54 ) ;
}
}
int
F_27 ( char * V_4 , int V_13 , struct V_52 * V_53 )
{
struct V_42 * V_54 ;
struct V_19 V_30 ;
int V_51 ;
int V_12 ;
V_30 . V_23 = V_4 ;
V_30 . V_24 = V_13 ;
V_12 = 0 ;
while ( V_30 . V_23 != NULL ) {
struct V_19 V_22 ;
if ( ! F_8 ( & V_30 , '.' , & V_22 ) ) {
V_51 = - V_15 ;
goto V_18;
}
V_51 = F_23 ( V_22 . V_23 , V_22 . V_24 , 0 , 255 , & V_54 ) ;
if ( V_51 != 0 )
goto V_18;
F_25 ( & V_54 -> V_55 , V_53 ) ;
V_12 ++ ;
}
if ( V_12 == 4 )
return 0 ;
V_51 = - V_15 ;
V_18:
F_26 ( V_53 ) ;
return V_51 ;
}
int
F_28 ( T_2 V_56 , struct V_52 * V_53 )
{
struct V_42 * V_54 ;
int V_12 = 0 ;
F_29 (el, list, el_link) {
if ( ! F_13 ( V_56 & 0xff , V_54 ) )
return 0 ;
V_56 >>= 8 ;
V_12 ++ ;
}
return V_12 == 4 ;
}
void
F_30 ( struct V_52 * V_53 )
{
F_26 ( V_53 ) ;
}
