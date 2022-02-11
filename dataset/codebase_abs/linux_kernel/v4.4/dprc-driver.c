static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_3 ) ;
V_8 = F_3 ( V_2 ) ;
V_6 = V_3 ;
for ( V_4 = 0 ; V_4 < V_6 -> V_9 ; V_4 ++ ) {
struct V_10 * V_11 = & V_6 -> V_12 [ V_4 ] ;
if ( strlen ( V_11 -> type ) != 0 &&
F_4 ( V_8 , V_11 ) )
break;
}
if ( V_4 == V_6 -> V_9 )
F_5 ( V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( ! V_2 ) ;
F_2 ( V_3 ) ;
F_5 ( F_3 ( V_2 ) ) ;
return 0 ;
}
static void F_7 ( struct V_7 * V_13 ,
struct V_10 * V_14 ,
int V_15 )
{
if ( V_15 != 0 ) {
struct V_5 V_6 ;
V_6 . V_9 = V_15 ;
V_6 . V_12 = V_14 ;
F_8 ( & V_13 -> V_2 , & V_6 ,
F_1 ) ;
} else {
F_8 ( & V_13 -> V_2 , NULL ,
F_6 ) ;
}
}
static int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_10 * V_11 = V_3 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
return F_4 ( V_8 , V_11 ) ;
}
static struct V_7 * F_10 ( struct V_10
* V_11 ,
struct V_7
* V_13 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( & V_13 -> V_2 , V_11 ,
F_9 ) ;
return V_2 ? F_3 ( V_2 ) : NULL ;
}
static void F_12 ( struct V_7 * V_8 ,
struct V_10 * V_11 )
{
int error ;
T_1 V_16 =
( V_11 -> V_17 & V_18 ) ;
if ( V_16 !=
( V_8 -> V_11 . V_17 & V_18 ) ) {
if ( V_16 ) {
V_8 -> V_11 . V_17 |= V_18 ;
error = F_13 ( & V_8 -> V_2 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 ,
L_1 ,
error ) ;
}
} else {
V_8 -> V_11 . V_17 &= ~ V_18 ;
F_15 ( & V_8 -> V_2 ) ;
}
}
}
static void F_16 ( struct V_7 * V_13 ,
struct V_10 * V_14 ,
int V_15 )
{
int error ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_15 ; V_4 ++ ) {
struct V_7 * V_19 ;
struct V_10 * V_11 = & V_14 [ V_4 ] ;
if ( strlen ( V_11 -> type ) == 0 )
continue;
V_19 = F_10 ( V_11 , V_13 ) ;
if ( V_19 ) {
F_12 ( V_19 , V_11 ) ;
continue;
}
error = F_17 ( V_11 , NULL , & V_13 -> V_2 ,
& V_19 ) ;
if ( error < 0 )
continue;
}
}
static void F_18 ( struct V_7 * V_13 )
{
int V_20 ;
struct V_21 * V_22 = F_19 ( V_13 ) ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
struct V_24 * V_25 =
& V_22 -> V_26 [ V_20 ] ;
V_25 -> type = V_20 ;
V_25 -> V_27 = 0 ;
V_25 -> V_28 = 0 ;
V_25 -> V_22 = V_22 ;
F_20 ( & V_25 -> V_29 ) ;
F_21 ( & V_25 -> V_30 ) ;
}
}
static void F_22 ( struct V_7 * V_13 ,
enum V_31 V_20 )
{
struct V_32 * V_33 ;
struct V_32 * V_34 ;
struct V_21 * V_22 = F_19 ( V_13 ) ;
struct V_24 * V_25 =
& V_22 -> V_26 [ V_20 ] ;
int V_28 = 0 ;
F_2 ( V_25 -> type != V_20 ) ;
F_2 ( V_25 -> V_28 != V_25 -> V_27 ) ;
F_23 (resource, next, &res_pool->free_list, node) {
V_28 ++ ;
F_2 ( V_33 -> type != V_25 -> type ) ;
F_2 ( V_33 -> V_35 != V_25 ) ;
F_24 ( & V_13 -> V_2 , V_33 ) ;
}
F_2 ( V_28 != V_25 -> V_28 ) ;
}
static void F_25 ( struct V_7 * V_13 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ )
F_22 ( V_13 , V_20 ) ;
}
int F_26 ( struct V_7 * V_13 )
{
int V_36 ;
int V_37 ;
int error ;
struct V_10 * V_38 = NULL ;
error = F_27 ( V_13 -> V_39 ,
0 ,
V_13 -> V_40 ,
& V_36 ) ;
if ( error < 0 ) {
F_14 ( & V_13 -> V_2 , L_2 ,
error ) ;
return error ;
}
if ( V_36 != 0 ) {
int V_4 ;
V_38 =
F_28 ( & V_13 -> V_2 , V_36 ,
sizeof( * V_38 ) ,
V_41 ) ;
if ( ! V_38 )
return - V_42 ;
V_37 = 0 ;
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ ) {
struct V_10 * V_11 =
& V_38 [ V_4 ] ;
error = F_29 ( V_13 -> V_39 ,
0 ,
V_13 -> V_40 ,
V_4 , V_11 ) ;
if ( error < 0 ) {
F_14 ( & V_13 -> V_2 ,
L_3 ,
V_4 , error ) ;
V_11 -> type [ 0 ] = '\0' ;
V_11 -> V_43 = error ;
V_37 ++ ;
continue;
}
F_30 ( & V_13 -> V_2 ,
L_4 ,
V_11 -> type , V_11 -> V_43 ) ;
}
if ( V_37 != 0 ) {
F_14 ( & V_13 -> V_2 ,
L_5 ,
V_37 , V_36 ) ;
}
}
F_7 ( V_13 , V_38 ,
V_36 ) ;
F_16 ( V_13 , V_38 ,
V_36 ) ;
if ( V_38 )
F_24 ( & V_13 -> V_2 , V_38 ) ;
return 0 ;
}
int F_31 ( struct V_7 * V_13 )
{
int error ;
struct V_21 * V_22 = F_19 ( V_13 ) ;
F_18 ( V_13 ) ;
F_32 ( & V_22 -> V_44 ) ;
error = F_26 ( V_13 ) ;
F_33 ( & V_22 -> V_44 ) ;
if ( error < 0 )
goto error;
return 0 ;
error:
F_25 ( V_13 ) ;
return error ;
}
static int F_34 ( struct V_7 * V_8 )
{
int error ;
T_2 V_45 ;
struct V_21 * V_22 = F_19 ( V_8 ) ;
if ( F_2 ( strcmp ( V_8 -> V_11 . type , L_6 ) != 0 ) )
return - V_46 ;
if ( ! V_8 -> V_39 ) {
if ( F_2 ( V_8 -> V_11 . V_47 == 0 ) )
return - V_46 ;
V_45 = V_8 -> V_48 [ 0 ] . V_49 -
V_8 -> V_48 [ 0 ] . V_50 + 1 ;
error = F_35 ( & V_8 -> V_2 ,
V_8 -> V_48 [ 0 ] . V_50 ,
V_45 ,
NULL , 0 , & V_8 -> V_39 ) ;
if ( error < 0 )
return error ;
}
error = F_36 ( V_8 -> V_39 , 0 , V_8 -> V_11 . V_43 ,
& V_8 -> V_40 ) ;
if ( error < 0 ) {
F_14 ( & V_8 -> V_2 , L_7 , error ) ;
goto V_51;
}
F_21 ( & V_22 -> V_44 ) ;
error = F_31 ( V_8 ) ;
if ( error < 0 )
goto V_52;
F_37 ( & V_8 -> V_2 , L_8 ) ;
return 0 ;
V_52:
( void ) F_38 ( V_8 -> V_39 , 0 , V_8 -> V_40 ) ;
V_51:
F_39 ( V_8 -> V_39 ) ;
return error ;
}
static int F_40 ( struct V_7 * V_8 )
{
int error ;
if ( F_2 ( strcmp ( V_8 -> V_11 . type , L_6 ) != 0 ) )
return - V_46 ;
if ( F_2 ( ! V_8 -> V_39 ) )
return - V_46 ;
F_8 ( & V_8 -> V_2 , NULL , F_6 ) ;
F_25 ( V_8 ) ;
error = F_38 ( V_8 -> V_39 , 0 , V_8 -> V_40 ) ;
if ( error < 0 )
F_14 ( & V_8 -> V_2 , L_9 , error ) ;
F_37 ( & V_8 -> V_2 , L_10 ) ;
return 0 ;
}
int T_3 F_41 ( void )
{
return F_42 ( & V_53 ) ;
}
void F_43 ( void )
{
F_44 ( & V_53 ) ;
}
