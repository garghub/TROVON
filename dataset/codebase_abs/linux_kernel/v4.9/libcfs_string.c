int F_1 ( const char * V_1 , const char * (* F_2)( int V_2 ) ,
int * V_3 , int V_4 , int V_5 )
{
const char * V_6 ;
char V_7 = '\0' ;
int V_8 = V_4 , V_9 , V_10 , V_11 = 0 ;
while ( * V_1 != '\0' ) {
while ( isspace ( * V_1 ) )
V_1 ++ ;
if ( * V_1 == '\0' )
break;
if ( * V_1 == '+' || * V_1 == '-' ) {
V_7 = * V_1 ++ ;
if ( ! V_11 )
V_8 = * V_3 ;
while ( isspace ( * V_1 ) )
V_1 ++ ;
if ( * V_1 == '\0' )
return - V_12 ;
}
V_10 = 0 ;
while ( V_1 [ V_10 ] != '\0' && ! isspace ( V_1 [ V_10 ] ) &&
V_1 [ V_10 ] != '+' && V_1 [ V_10 ] != '-' )
V_10 ++ ;
V_11 = 0 ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
V_6 = F_2 ( V_9 ) ;
if ( V_6 && strlen ( V_6 ) == V_10 &&
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
if ( ! V_17 -> V_20 )
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
if ( ! V_14 ) {
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
bool V_26 = true ;
char * V_27 , V_28 ;
int V_29 ;
for ( V_27 = V_1 ; V_27 < V_1 + V_22 ; V_27 ++ ) {
if ( ! isdigit ( * V_27 ) ) {
V_26 = false ;
break;
}
}
V_28 = * V_27 ;
* V_27 = '\0' ;
V_29 = F_8 ( V_1 , 10 , V_23 ) ;
* V_27 = V_28 ;
if ( V_29 || ! V_26 )
return 0 ;
return ( * V_23 >= V_24 && * V_23 <= V_25 ) ;
}
static int
F_9 ( struct V_16 * V_30 , unsigned V_24 , unsigned V_25 ,
int V_31 , struct V_32 * * V_33 )
{
struct V_32 * V_34 ;
struct V_16 V_35 ;
F_10 ( V_34 , sizeof( * V_34 ) ) ;
if ( ! V_34 )
return - V_36 ;
if ( V_30 -> V_21 == 1 && V_30 -> V_20 [ 0 ] == '*' ) {
V_34 -> V_37 = V_24 ;
V_34 -> V_38 = V_25 ;
V_34 -> V_39 = 1 ;
goto V_15;
}
if ( F_7 ( V_30 -> V_20 , V_30 -> V_21 ,
& V_34 -> V_37 , V_24 , V_25 ) ) {
V_34 -> V_38 = V_34 -> V_37 ;
V_34 -> V_39 = 1 ;
goto V_15;
}
if ( ! V_31 || ! F_6 ( V_30 , '-' , & V_35 ) )
goto V_40;
if ( ! F_7 ( V_35 . V_20 , V_35 . V_21 ,
& V_34 -> V_37 , V_24 , V_25 ) )
goto V_40;
if ( F_7 ( V_30 -> V_20 , V_30 -> V_21 ,
& V_34 -> V_38 , V_24 , V_25 ) ) {
V_34 -> V_39 = 1 ;
goto V_15;
}
if ( F_6 ( V_30 , '/' , & V_35 ) ) {
if ( ! F_7 ( V_35 . V_20 , V_35 . V_21 ,
& V_34 -> V_38 , V_24 , V_25 ) )
goto V_40;
if ( F_7 ( V_30 -> V_20 , V_30 -> V_21 ,
& V_34 -> V_39 , V_24 , V_25 ) ) {
goto V_15;
}
}
V_15:
* V_33 = V_34 ;
return 0 ;
V_40:
F_11 ( V_34 , sizeof( * V_34 ) ) ;
return - V_12 ;
}
static int
F_12 ( char * V_41 , int V_42 , struct V_32 * V_33 ,
bool V_31 )
{
int V_9 ;
char V_43 [] = L_4 ;
char V_44 [] = L_5 ;
if ( V_31 ) {
V_43 [ 0 ] = '\0' ;
V_44 [ 0 ] = '\0' ;
}
if ( V_33 -> V_37 == V_33 -> V_38 )
V_9 = F_13 ( V_41 , V_42 , L_6 , V_33 -> V_37 ) ;
else if ( V_33 -> V_39 == 1 )
V_9 = F_13 ( V_41 , V_42 , L_7 ,
V_43 , V_33 -> V_37 , V_33 -> V_38 , V_44 ) ;
else
V_9 = F_13 ( V_41 , V_42 , L_8 ,
V_43 , V_33 -> V_37 , V_33 -> V_38 , V_33 -> V_39 , V_44 ) ;
return V_9 ;
}
int
F_14 ( char * V_41 , int V_42 , struct V_45 * V_46 )
{
struct V_32 * V_33 ;
int V_9 = 0 , V_47 = 0 ;
int V_48 = 0 ;
if ( V_42 <= 0 )
return 0 ;
F_15 (expr, &expr_list->el_exprs, re_link)
V_48 ++ ;
if ( V_48 > 1 )
V_9 += F_13 ( V_41 + V_9 , V_42 - V_9 , L_4 ) ;
F_15 (expr, &expr_list->el_exprs, re_link) {
if ( V_47 ++ != 0 )
V_9 += F_13 ( V_41 + V_9 , V_42 - V_9 , L_9 ) ;
V_9 += F_12 ( V_41 + V_9 , V_42 - V_9 , V_33 ,
V_48 > 1 ) ;
}
if ( V_48 > 1 )
V_9 += F_13 ( V_41 + V_9 , V_42 - V_9 , L_5 ) ;
return V_9 ;
}
int
F_16 ( T_2 V_49 , struct V_45 * V_46 )
{
struct V_32 * V_33 ;
F_15 (expr, &expr_list->el_exprs, re_link) {
if ( V_49 >= V_33 -> V_37 && V_49 <= V_33 -> V_38 &&
( ( V_49 - V_33 -> V_37 ) % V_33 -> V_39 ) == 0 )
return 1 ;
}
return 0 ;
}
int
F_17 ( struct V_45 * V_46 , int V_25 , T_2 * * V_50 )
{
struct V_32 * V_33 ;
T_2 * V_51 ;
int V_42 = 0 ;
int V_9 ;
F_15 (expr, &expr_list->el_exprs, re_link) {
for ( V_9 = V_33 -> V_37 ; V_9 <= V_33 -> V_38 ; V_9 ++ ) {
if ( ( ( V_9 - V_33 -> V_37 ) % V_33 -> V_39 ) == 0 )
V_42 ++ ;
}
}
if ( V_42 == 0 )
return 0 ;
if ( V_42 > V_25 ) {
F_18 ( L_10 ,
V_25 , V_42 ) ;
return - V_12 ;
}
F_10 ( V_51 , sizeof( V_51 [ 0 ] ) * V_42 ) ;
if ( ! V_51 )
return - V_36 ;
V_42 = 0 ;
F_15 (expr, &expr_list->el_exprs, re_link) {
for ( V_9 = V_33 -> V_37 ; V_9 <= V_33 -> V_38 ; V_9 ++ ) {
if ( ( ( V_9 - V_33 -> V_37 ) % V_33 -> V_39 ) == 0 )
V_51 [ V_42 ++ ] = V_9 ;
}
}
* V_50 = V_51 ;
return V_42 ;
}
void
F_19 ( struct V_45 * V_46 )
{
while ( ! F_20 ( & V_46 -> V_52 ) ) {
struct V_32 * V_33 ;
V_33 = F_21 ( V_46 -> V_52 . V_17 ,
struct V_32 , V_53 ) ;
F_22 ( & V_33 -> V_53 ) ;
F_11 ( V_33 , sizeof( * V_33 ) ) ;
}
F_11 ( V_46 , sizeof( * V_46 ) ) ;
}
int
F_23 ( char * V_1 , int V_10 , unsigned V_24 , unsigned V_25 ,
struct V_45 * * V_54 )
{
struct V_45 * V_46 ;
struct V_32 * V_33 ;
struct V_16 V_30 ;
int V_29 ;
F_10 ( V_46 , sizeof( * V_46 ) ) ;
if ( ! V_46 )
return - V_36 ;
V_30 . V_20 = V_1 ;
V_30 . V_21 = V_10 ;
F_24 ( & V_46 -> V_52 ) ;
if ( V_30 . V_20 [ 0 ] == '[' &&
V_30 . V_20 [ V_30 . V_21 - 1 ] == ']' ) {
V_30 . V_20 ++ ;
V_30 . V_21 -= 2 ;
V_29 = - V_12 ;
while ( V_30 . V_20 ) {
struct V_16 V_35 ;
if ( ! F_6 ( & V_30 , ',' , & V_35 ) ) {
V_29 = - V_12 ;
break;
}
V_29 = F_9 ( & V_35 , V_24 , V_25 , 1 , & V_33 ) ;
if ( V_29 != 0 )
break;
F_25 ( & V_33 -> V_53 , & V_46 -> V_52 ) ;
}
} else {
V_29 = F_9 ( & V_30 , V_24 , V_25 , 0 , & V_33 ) ;
if ( V_29 == 0 )
F_25 ( & V_33 -> V_53 , & V_46 -> V_52 ) ;
}
if ( V_29 != 0 )
F_19 ( V_46 ) ;
else
* V_54 = V_46 ;
return V_29 ;
}
void
F_26 ( struct V_55 * V_56 )
{
struct V_45 * V_57 ;
while ( ! F_20 ( V_56 ) ) {
V_57 = F_21 ( V_56 -> V_17 , struct V_45 , V_58 ) ;
F_22 ( & V_57 -> V_58 ) ;
F_19 ( V_57 ) ;
}
}
