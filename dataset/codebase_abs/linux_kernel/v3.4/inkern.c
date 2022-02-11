int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = 0 , V_6 = 0 ;
struct V_7 * V_8 ;
if ( V_4 == NULL )
return 0 ;
F_2 ( & V_9 ) ;
while ( V_4 [ V_5 ] . V_10 != NULL ) {
V_8 = F_3 ( sizeof( * V_8 ) , V_11 ) ;
if ( V_8 == NULL ) {
V_6 = - V_12 ;
goto V_13;
}
V_8 -> V_14 = & V_4 [ V_5 ] ;
V_8 -> V_2 = V_2 ;
F_4 ( & V_8 -> V_15 , & V_16 ) ;
V_5 ++ ;
}
V_13:
F_5 ( & V_9 ) ;
return V_6 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 , V_6 = 0 ;
bool V_17 ;
struct V_7 * V_8 ;
if ( V_4 == NULL )
return 0 ;
F_2 ( & V_9 ) ;
while ( V_4 [ V_5 ] . V_10 != NULL ) {
V_17 = false ;
F_7 (mapi, &iio_map_list, l)
if ( & V_4 [ V_5 ] == V_8 -> V_14 ) {
F_8 ( & V_8 -> V_15 ) ;
F_9 ( V_8 ) ;
V_17 = true ;
break;
}
if ( V_17 == false ) {
V_6 = - V_18 ;
goto V_13;
}
V_5 ++ ;
}
V_13:
F_5 ( & V_9 ) ;
return V_6 ;
}
static const struct V_19
* F_10 ( const struct V_1 * V_2 ,
const char * V_20 )
{
int V_5 ;
const struct V_19 * V_21 = NULL ;
for ( V_5 = 0 ; V_5 < V_2 -> V_22 ; V_5 ++ )
if ( V_2 -> V_23 [ V_5 ] . V_24 &&
strcmp ( V_20 , V_2 -> V_23 [ V_5 ] . V_24 ) == 0 ) {
V_21 = & V_2 -> V_23 [ V_5 ] ;
break;
}
return V_21 ;
}
struct V_25 * F_11 ( const char * V_20 ,
const char * V_26 )
{
struct V_7 * V_27 = NULL , * V_28 = NULL ;
struct V_25 * V_29 ;
if ( V_20 == NULL && V_26 == NULL )
return F_12 ( - V_18 ) ;
F_2 ( & V_9 ) ;
F_7 (c_i, &iio_map_list, l) {
if ( ( V_20 && strcmp ( V_20 , V_27 -> V_14 -> V_10 ) != 0 ) ||
( V_26 &&
strcmp ( V_26 , V_27 -> V_14 -> V_30 ) != 0 ) )
continue;
V_28 = V_27 ;
F_13 ( & V_28 -> V_2 -> V_31 ) ;
break;
}
F_5 ( & V_9 ) ;
if ( V_28 == NULL )
return F_12 ( - V_18 ) ;
V_29 = F_14 ( sizeof( * V_29 ) , V_11 ) ;
if ( V_29 == NULL )
return F_12 ( - V_12 ) ;
V_29 -> V_2 = V_28 -> V_2 ;
if ( V_28 -> V_14 -> V_32 )
V_29 -> V_29 =
F_10 ( V_29 -> V_2 ,
V_28 -> V_14 -> V_32 ) ;
return V_29 ;
}
void F_15 ( struct V_25 * V_29 )
{
F_16 ( & V_29 -> V_2 -> V_31 ) ;
F_9 ( V_29 ) ;
}
struct V_25 * F_17 ( const char * V_20 )
{
struct V_25 * V_33 ;
struct V_7 * V_28 = NULL ;
int V_34 = 0 ;
int V_35 = 0 ;
int V_5 , V_6 ;
if ( V_20 == NULL )
return F_12 ( - V_36 ) ;
F_2 ( & V_9 ) ;
F_7 (c, &iio_map_list, l)
if ( V_20 && strcmp ( V_20 , V_28 -> V_14 -> V_10 ) != 0 )
continue;
else
V_34 ++ ;
if ( V_34 == 0 ) {
V_6 = - V_18 ;
goto V_13;
}
V_33 = F_3 ( sizeof( * V_33 ) * ( V_34 + 1 ) , V_11 ) ;
if ( V_33 == NULL ) {
V_6 = - V_12 ;
goto V_13;
}
F_7 (c, &iio_map_list, l) {
if ( V_20 && strcmp ( V_20 , V_28 -> V_14 -> V_10 ) != 0 )
continue;
V_33 [ V_35 ] . V_2 = V_28 -> V_2 ;
V_33 [ V_35 ] . V_29 =
F_10 ( V_33 [ V_35 ] . V_2 ,
V_28 -> V_14 -> V_32 ) ;
if ( V_33 [ V_35 ] . V_29 == NULL ) {
V_6 = - V_36 ;
F_16 ( & V_33 [ V_35 ] . V_2 -> V_31 ) ;
goto V_37;
}
F_13 ( & V_33 [ V_35 ] . V_2 -> V_31 ) ;
V_35 ++ ;
}
F_5 ( & V_9 ) ;
if ( V_35 == 0 ) {
V_6 = - V_18 ;
goto V_37;
}
return V_33 ;
V_37:
for ( V_5 = 0 ; V_5 < V_34 ; V_5 ++ )
if ( V_33 [ V_5 ] . V_2 )
F_16 ( & V_33 [ V_5 ] . V_2 -> V_31 ) ;
F_9 ( V_33 ) ;
V_13:
F_5 ( & V_9 ) ;
return F_12 ( V_6 ) ;
}
void F_18 ( struct V_25 * V_23 )
{
struct V_25 * V_21 = & V_23 [ 0 ] ;
while ( V_21 -> V_2 ) {
F_16 ( & V_21 -> V_2 -> V_31 ) ;
V_21 ++ ;
}
F_9 ( V_23 ) ;
}
int F_19 ( struct V_25 * V_21 , int * V_38 )
{
int V_39 , V_6 ;
F_2 ( & V_21 -> V_2 -> V_40 ) ;
if ( V_21 -> V_2 -> V_41 == NULL ) {
V_6 = - V_18 ;
goto V_42;
}
V_6 = V_21 -> V_2 -> V_41 -> V_43 ( V_21 -> V_2 , V_21 -> V_29 ,
V_38 , & V_39 , 0 ) ;
V_42:
F_5 ( & V_21 -> V_2 -> V_40 ) ;
return V_6 ;
}
int F_20 ( struct V_25 * V_21 , int * V_38 , int * V_39 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_40 ) ;
if ( V_21 -> V_2 -> V_41 == NULL ) {
V_6 = - V_18 ;
goto V_42;
}
V_6 = V_21 -> V_2 -> V_41 -> V_43 ( V_21 -> V_2 ,
V_21 -> V_29 ,
V_38 , V_39 ,
V_44 ) ;
V_42:
F_5 ( & V_21 -> V_2 -> V_40 ) ;
return V_6 ;
}
int F_21 ( struct V_25 * V_21 ,
enum V_45 * type )
{
int V_6 = 0 ;
F_2 ( & V_21 -> V_2 -> V_40 ) ;
if ( V_21 -> V_2 -> V_41 == NULL ) {
V_6 = - V_18 ;
goto V_42;
}
* type = V_21 -> V_29 -> type ;
V_42:
F_5 ( & V_21 -> V_2 -> V_40 ) ;
return V_6 ;
}
