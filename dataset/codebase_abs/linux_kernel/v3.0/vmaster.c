static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 , V_6 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 )
return - V_8 ;
V_4 -> V_9 = V_2 -> V_2 . V_9 ;
V_5 = V_2 -> V_2 . V_10 ( & V_2 -> V_2 , V_4 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 . V_12 ; V_6 ++ )
V_2 -> V_13 [ V_6 ] = V_4 -> V_14 . integer . V_14 [ V_6 ] ;
F_3 ( V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_5 ;
if ( V_2 -> V_11 . V_12 ) {
if ( V_2 -> V_17 & V_18 )
return F_1 ( V_2 ) ;
return 0 ;
}
V_16 = F_2 ( sizeof( * V_16 ) , V_7 ) ;
if ( ! V_16 )
return - V_8 ;
V_16 -> V_9 = V_2 -> V_2 . V_9 ;
V_5 = V_2 -> V_2 . V_11 ( & V_2 -> V_2 , V_16 ) ;
if ( V_5 < 0 ) {
F_3 ( V_16 ) ;
return V_5 ;
}
V_2 -> V_11 . type = V_16 -> type ;
V_2 -> V_11 . V_12 = V_16 -> V_12 ;
if ( V_2 -> V_11 . V_12 > 2 ||
( V_2 -> V_11 . type != V_19 &&
V_2 -> V_11 . type != V_20 ) ) {
F_5 ( V_21 L_1 ) ;
F_3 ( V_16 ) ;
return - V_22 ;
}
V_2 -> V_11 . V_23 = V_16 -> V_14 . integer . V_24 ;
V_2 -> V_11 . V_25 = V_16 -> V_14 . integer . V_26 ;
F_3 ( V_16 ) ;
return F_1 ( V_2 ) ;
}
static int F_6 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
if ( V_28 -> V_11 . V_12 )
return 0 ;
F_7 (slave, &master->slaves, list) {
int V_5 = F_4 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_28 -> V_11 = V_2 -> V_11 ;
V_28 -> V_11 . V_12 = 1 ;
V_28 -> V_29 = V_28 -> V_11 . V_25 ;
return 0 ;
}
return - V_30 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_31 )
{
int V_5 , V_6 ;
V_5 = F_4 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 . V_12 ; V_6 ++ )
V_31 -> V_14 . integer . V_14 [ V_6 ] = V_2 -> V_13 [ V_6 ] ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_31 )
{
int V_5 , V_6 , V_32 ;
V_5 = F_6 ( V_2 -> V_28 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( V_2 -> V_11 . type ) {
case V_20 :
for ( V_6 = 0 ; V_6 < V_2 -> V_11 . V_12 ; V_6 ++ )
V_31 -> V_14 . integer . V_14 [ V_6 ] &=
! ! V_2 -> V_28 -> V_29 ;
break;
case V_19 :
for ( V_6 = 0 ; V_6 < V_2 -> V_11 . V_12 ; V_6 ++ ) {
V_32 = V_31 -> V_14 . integer . V_14 [ V_6 ] ;
V_32 += V_2 -> V_28 -> V_29 - V_2 -> V_28 -> V_11 . V_25 ;
if ( V_32 < V_2 -> V_11 . V_23 )
V_32 = V_2 -> V_11 . V_23 ;
else if ( V_32 > V_2 -> V_11 . V_25 )
V_32 = V_2 -> V_11 . V_25 ;
V_31 -> V_14 . integer . V_14 [ V_6 ] = V_32 ;
}
break;
}
return V_2 -> V_2 . V_33 ( & V_2 -> V_2 , V_31 ) ;
}
static int F_10 ( struct V_34 * V_35 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_35 ) ;
return V_2 -> V_2 . V_11 ( & V_2 -> V_2 , V_16 ) ;
}
static int F_12 ( struct V_34 * V_35 ,
struct V_3 * V_31 )
{
struct V_1 * V_2 = F_11 ( V_35 ) ;
return F_8 ( V_2 , V_31 ) ;
}
static int F_13 ( struct V_34 * V_35 ,
struct V_3 * V_31 )
{
struct V_1 * V_2 = F_11 ( V_35 ) ;
int V_5 , V_6 , V_36 = 0 ;
V_5 = F_4 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 . V_12 ; V_6 ++ ) {
if ( V_2 -> V_13 [ V_6 ] != V_31 -> V_14 . integer . V_14 [ V_6 ] ) {
V_36 = 1 ;
V_2 -> V_13 [ V_6 ] = V_31 -> V_14 . integer . V_14 [ V_6 ] ;
}
}
if ( ! V_36 )
return 0 ;
return F_9 ( V_2 , V_31 ) ;
}
static int F_14 ( struct V_34 * V_35 ,
int V_37 , unsigned int V_38 ,
unsigned int T_1 * V_39 )
{
struct V_1 * V_2 = F_11 ( V_35 ) ;
return V_2 -> V_2 . V_39 . V_40 ( & V_2 -> V_2 , V_37 , V_38 , V_39 ) ;
}
static void F_15 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_11 ( V_35 ) ;
if ( V_2 -> V_2 . V_41 )
V_2 -> V_2 . V_41 ( & V_2 -> V_2 ) ;
if ( V_2 -> V_28 )
F_16 ( & V_2 -> V_42 ) ;
F_3 ( V_2 ) ;
}
int F_17 ( struct V_34 * V_28 , struct V_34 * V_2 ,
unsigned int V_17 )
{
struct V_27 * V_43 = F_11 ( V_28 ) ;
struct V_1 * V_44 ;
V_44 = F_18 ( sizeof( * V_44 ) +
V_2 -> V_12 * sizeof( * V_2 -> V_45 ) , V_7 ) ;
if ( ! V_44 )
return - V_8 ;
V_44 -> V_2 = * V_2 ;
memcpy ( V_44 -> V_2 . V_45 , V_2 -> V_45 , V_2 -> V_12 * sizeof( * V_2 -> V_45 ) ) ;
V_44 -> V_28 = V_43 ;
V_44 -> V_17 = V_17 ;
V_2 -> V_11 = F_10 ;
V_2 -> V_10 = F_12 ;
V_2 -> V_33 = F_13 ;
if ( V_2 -> V_45 [ 0 ] . V_46 & V_47 )
V_2 -> V_39 . V_40 = F_14 ;
V_2 -> V_48 = V_44 ;
V_2 -> V_41 = F_15 ;
F_19 ( & V_44 -> V_42 , & V_43 -> V_49 ) ;
return 0 ;
}
static int F_20 ( struct V_34 * V_35 ,
struct V_15 * V_16 )
{
struct V_27 * V_28 = F_11 ( V_35 ) ;
int V_50 ;
V_50 = F_6 ( V_28 ) ;
if ( V_50 < 0 )
return V_50 ;
V_16 -> type = V_28 -> V_11 . type ;
V_16 -> V_12 = V_28 -> V_11 . V_12 ;
V_16 -> V_14 . integer . V_24 = V_28 -> V_11 . V_23 ;
V_16 -> V_14 . integer . V_26 = V_28 -> V_11 . V_25 ;
return 0 ;
}
static int F_21 ( struct V_34 * V_35 ,
struct V_3 * V_31 )
{
struct V_27 * V_28 = F_11 ( V_35 ) ;
int V_5 = F_6 ( V_28 ) ;
if ( V_5 < 0 )
return V_5 ;
V_31 -> V_14 . integer . V_14 [ 0 ] = V_28 -> V_29 ;
return 0 ;
}
static int F_22 ( struct V_34 * V_35 ,
struct V_3 * V_31 )
{
struct V_27 * V_28 = F_11 ( V_35 ) ;
struct V_1 * V_2 ;
struct V_3 * V_51 ;
int V_5 , V_52 ;
V_5 = F_6 ( V_28 ) ;
if ( V_5 < 0 )
return V_5 ;
V_52 = V_28 -> V_29 ;
if ( V_31 -> V_14 . integer . V_14 [ 0 ] == V_52 )
return 0 ;
V_51 = F_2 ( sizeof( * V_51 ) , V_7 ) ;
if ( ! V_51 )
return - V_8 ;
F_7 (slave, &master->slaves, list) {
V_28 -> V_29 = V_52 ;
V_51 -> V_9 = V_2 -> V_2 . V_9 ;
F_8 ( V_2 , V_51 ) ;
V_28 -> V_29 = V_31 -> V_14 . integer . V_14 [ 0 ] ;
F_9 ( V_2 , V_51 ) ;
}
F_3 ( V_51 ) ;
return 1 ;
}
static void F_23 ( struct V_34 * V_35 )
{
struct V_27 * V_28 = F_11 ( V_35 ) ;
struct V_1 * V_2 ;
F_7 (slave, &master->slaves, list)
V_2 -> V_28 = NULL ;
F_3 ( V_28 ) ;
}
struct V_34 * F_24 ( char * V_53 ,
const unsigned int * V_39 )
{
struct V_27 * V_28 ;
struct V_34 * V_54 ;
struct V_55 V_56 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_57 = V_58 ;
V_56 . V_53 = V_53 ;
V_56 . V_11 = F_20 ;
V_28 = F_18 ( sizeof( * V_28 ) , V_7 ) ;
if ( ! V_28 )
return NULL ;
F_25 ( & V_28 -> V_49 ) ;
V_54 = F_26 ( & V_56 , V_28 ) ;
if ( ! V_54 ) {
F_3 ( V_28 ) ;
return NULL ;
}
V_54 -> V_11 = F_20 ;
V_54 -> V_10 = F_21 ;
V_54 -> V_33 = F_22 ;
V_54 -> V_41 = F_23 ;
if ( V_39 &&
( V_39 [ 0 ] == V_59 ||
V_39 [ 0 ] == V_60 ||
V_39 [ 0 ] == V_61 ) ) {
V_54 -> V_45 [ 0 ] . V_46 |= V_62 ;
memcpy ( V_28 -> V_39 , V_39 , sizeof( V_28 -> V_39 ) ) ;
V_54 -> V_39 . V_63 = V_28 -> V_39 ;
}
return V_54 ;
}
