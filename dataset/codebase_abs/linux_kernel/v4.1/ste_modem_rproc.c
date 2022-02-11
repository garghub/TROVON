static int F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
memcpy ( V_4 -> V_6 , V_3 -> V_7 , V_3 -> V_8 ) ;
return 0 ;
}
static const struct V_9 * F_2 ( const void * V_7 )
{
int V_10 ;
const struct V_11 * V_12 ;
V_12 = V_7 ;
for ( V_10 = 0 ; V_10 < V_13 &&
V_12 -> V_14 [ V_10 ] . V_15 != 0xffffffff ; V_10 ++ ) {
if ( ! strncmp ( V_12 -> V_14 [ V_10 ] . V_16 , V_17 ,
sizeof( V_12 -> V_14 [ V_10 ] . V_16 ) ) )
return & V_12 -> V_14 [ V_10 ] ;
}
return NULL ;
}
static struct V_18 *
F_3 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
int * V_19 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
struct V_18 * V_14 ;
const struct V_9 * V_20 ;
if ( ! V_3 )
return NULL ;
V_20 = F_2 ( V_3 -> V_7 ) ;
if ( ! V_20 ) {
F_4 ( V_4 , L_1 ) ;
return NULL ;
}
V_14 = ( void * ) ( V_3 -> V_7 + V_20 -> V_15 ) ;
if ( V_20 -> V_15 > V_21 ||
V_20 -> V_8 > V_21 ||
V_3 -> V_8 > V_21 ||
V_20 -> V_15 + V_20 -> V_8 > V_3 -> V_8 ||
sizeof( struct V_18 ) > V_20 -> V_8 ) {
F_4 ( V_4 , L_2 ) ;
return NULL ;
}
if ( V_14 -> V_22 != 1 ) {
F_4 ( V_4 , L_3 , V_14 -> V_22 ) ;
return NULL ;
}
if ( V_14 -> V_23 [ 0 ] || V_14 -> V_23 [ 1 ] ) {
F_4 ( V_4 , L_4 ) ;
return NULL ;
}
if ( V_14 -> V_24 > V_13 ||
V_14 -> V_24 * sizeof( V_14 -> V_25 [ 0 ] ) +
sizeof( struct V_18 ) > V_20 -> V_8 ) {
F_4 ( V_4 , L_5 ) ;
return NULL ;
}
if ( V_21 < V_3 -> V_8 ) {
F_4 ( V_4 , L_6 ,
V_21 , V_3 -> V_8 ) ;
return NULL ;
}
V_4 -> V_26 = V_3 -> V_8 ;
* V_19 = V_20 -> V_8 ;
return V_14 ;
}
static struct V_18 *
F_5 ( struct V_1 * V_1 , const struct V_2 * V_3 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
const struct V_9 * V_20 ;
if ( ! V_3 || ! V_4 -> V_6 )
return NULL ;
V_20 = F_2 ( V_4 -> V_6 ) ;
if ( ! V_20 ) {
F_4 ( V_4 , L_1 ) ;
return NULL ;
}
return V_4 -> V_6 + V_20 -> V_15 ;
}
static void F_6 ( struct V_1 * V_1 , int V_27 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
F_7 ( V_4 , L_7 , V_27 ) ;
V_4 -> V_28 -> V_29 . V_30 ( V_4 -> V_28 , V_27 + V_31 ) ;
}
static void F_8 ( struct V_32 * V_28 , int V_27 )
{
struct V_4 * V_4 = V_28 -> V_33 ;
if ( F_9 ( V_4 -> V_1 , V_27 ) == V_34 )
F_7 ( V_4 , L_8 , V_27 ) ;
}
static int F_10 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
int V_10 , V_35 ;
F_7 ( V_4 , L_9 ) ;
if ( V_1 -> V_36 > V_31 ) {
F_4 ( V_4 , L_10 ,
V_1 -> V_36 ) ;
return - V_37 ;
}
for ( V_10 = 0 ; V_10 <= V_1 -> V_36 ; V_10 ++ ) {
V_35 = V_4 -> V_28 -> V_29 . V_38 ( V_4 -> V_28 , V_10 ) ;
if ( V_35 ) {
F_4 ( V_4 ,
L_11 , V_35 ) ;
return V_35 ;
}
}
return V_4 -> V_28 -> V_29 . V_39 ( V_4 -> V_28 , true ) ;
}
static int F_11 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
F_7 ( V_4 , L_12 ) ;
return V_4 -> V_28 -> V_29 . V_39 ( V_4 -> V_28 , false ) ;
}
static int F_12 ( struct V_40 * V_41 )
{
struct V_32 * V_28 =
F_13 ( V_41 , struct V_32 , V_41 ) ;
struct V_4 * V_4 = V_28 -> V_33 ;
F_7 ( V_4 , L_13 ) ;
V_4 -> V_28 -> V_29 . V_42 ( V_4 -> V_28 , NULL ) ;
F_14 ( V_4 -> V_1 ) ;
F_15 ( V_4 -> V_1 -> V_43 . V_44 , V_21 ,
V_4 -> V_6 , V_4 -> V_45 ) ;
F_16 ( V_4 -> V_1 ) ;
V_28 -> V_33 = NULL ;
return 0 ;
}
static int F_17 ( struct V_40 * V_41 )
{
struct V_32 * V_28 =
F_13 ( V_41 , struct V_32 , V_41 ) ;
struct V_4 * V_4 ;
struct V_1 * V_1 ;
int V_35 ;
F_18 ( & V_28 -> V_41 . V_43 , L_14 ) ;
if ( ! V_28 -> V_29 . V_42 || ! V_28 -> V_29 . V_30 || ! V_28 -> V_29 . V_38 ||
! V_28 -> V_29 . V_39 ) {
F_19 ( & V_28 -> V_41 . V_43 , L_15 ) ;
return - V_37 ;
}
V_1 = F_20 ( & V_28 -> V_41 . V_43 , V_28 -> V_41 . V_16 , & V_46 ,
V_47 , sizeof( * V_4 ) ) ;
if ( ! V_1 )
return - V_48 ;
V_4 = V_1 -> V_5 ;
V_4 -> V_28 = V_28 ;
V_4 -> V_1 = V_1 ;
V_1 -> V_49 = false ;
V_28 -> V_33 = V_4 ;
V_4 -> V_28 -> V_29 . V_42 ( V_4 -> V_28 , & V_50 ) ;
V_1 -> V_51 = & V_52 ;
V_4 -> V_6 = F_21 ( V_1 -> V_43 . V_44 , V_21 ,
& V_4 -> V_45 ,
V_53 ) ;
if ( ! V_4 -> V_6 ) {
F_4 ( V_4 , L_16 ) ;
V_35 = - V_48 ;
goto V_54;
}
V_35 = F_22 ( V_1 ) ;
if ( V_35 )
goto V_55;
return 0 ;
V_55:
F_15 ( V_1 -> V_43 . V_44 , V_21 ,
V_4 -> V_6 , V_4 -> V_45 ) ;
V_54:
V_28 -> V_33 = NULL ;
F_16 ( V_1 ) ;
return V_35 ;
}
