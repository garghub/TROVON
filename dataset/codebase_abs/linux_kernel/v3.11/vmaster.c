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
if ( V_28 -> V_30 )
V_28 -> V_30 ( V_28 -> V_31 , V_28 -> V_29 ) ;
return 1 ;
}
return - V_32 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_33 )
{
int V_5 , V_6 ;
V_5 = F_4 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 . V_12 ; V_6 ++ )
V_33 -> V_14 . integer . V_14 [ V_6 ] = V_2 -> V_13 [ V_6 ] ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_33 )
{
int V_5 , V_6 , V_34 ;
V_5 = F_6 ( V_2 -> V_28 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( V_2 -> V_11 . type ) {
case V_20 :
for ( V_6 = 0 ; V_6 < V_2 -> V_11 . V_12 ; V_6 ++ )
V_33 -> V_14 . integer . V_14 [ V_6 ] &=
! ! V_2 -> V_28 -> V_29 ;
break;
case V_19 :
for ( V_6 = 0 ; V_6 < V_2 -> V_11 . V_12 ; V_6 ++ ) {
V_34 = V_33 -> V_14 . integer . V_14 [ V_6 ] ;
V_34 += V_2 -> V_28 -> V_29 - V_2 -> V_28 -> V_11 . V_25 ;
if ( V_34 < V_2 -> V_11 . V_23 )
V_34 = V_2 -> V_11 . V_23 ;
else if ( V_34 > V_2 -> V_11 . V_25 )
V_34 = V_2 -> V_11 . V_25 ;
V_33 -> V_14 . integer . V_14 [ V_6 ] = V_34 ;
}
break;
}
return V_2 -> V_2 . V_35 ( & V_2 -> V_2 , V_33 ) ;
}
static int F_10 ( struct V_36 * V_37 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_37 ) ;
return V_2 -> V_2 . V_11 ( & V_2 -> V_2 , V_16 ) ;
}
static int F_12 ( struct V_36 * V_37 ,
struct V_3 * V_33 )
{
struct V_1 * V_2 = F_11 ( V_37 ) ;
return F_8 ( V_2 , V_33 ) ;
}
static int F_13 ( struct V_36 * V_37 ,
struct V_3 * V_33 )
{
struct V_1 * V_2 = F_11 ( V_37 ) ;
int V_5 , V_6 , V_38 = 0 ;
V_5 = F_4 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 . V_12 ; V_6 ++ ) {
if ( V_2 -> V_13 [ V_6 ] != V_33 -> V_14 . integer . V_14 [ V_6 ] ) {
V_38 = 1 ;
V_2 -> V_13 [ V_6 ] = V_33 -> V_14 . integer . V_14 [ V_6 ] ;
}
}
if ( ! V_38 )
return 0 ;
V_5 = F_9 ( V_2 , V_33 ) ;
if ( V_5 < 0 )
return V_5 ;
return 1 ;
}
static int F_14 ( struct V_36 * V_37 ,
int V_39 , unsigned int V_40 ,
unsigned int T_1 * V_41 )
{
struct V_1 * V_2 = F_11 ( V_37 ) ;
return V_2 -> V_2 . V_41 . V_42 ( & V_2 -> V_2 , V_39 , V_40 , V_41 ) ;
}
static void F_15 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_11 ( V_37 ) ;
if ( V_2 -> V_2 . V_43 )
V_2 -> V_2 . V_43 ( & V_2 -> V_2 ) ;
if ( V_2 -> V_28 )
F_16 ( & V_2 -> V_44 ) ;
F_3 ( V_2 ) ;
}
int F_17 ( struct V_36 * V_28 , struct V_36 * V_2 ,
unsigned int V_17 )
{
struct V_27 * V_45 = F_11 ( V_28 ) ;
struct V_1 * V_46 ;
V_46 = F_18 ( sizeof( * V_46 ) +
V_2 -> V_12 * sizeof( * V_2 -> V_47 ) , V_7 ) ;
if ( ! V_46 )
return - V_8 ;
V_46 -> V_48 = V_2 ;
V_46 -> V_2 = * V_2 ;
memcpy ( V_46 -> V_2 . V_47 , V_2 -> V_47 , V_2 -> V_12 * sizeof( * V_2 -> V_47 ) ) ;
V_46 -> V_28 = V_45 ;
V_46 -> V_17 = V_17 ;
V_2 -> V_11 = F_10 ;
V_2 -> V_10 = F_12 ;
V_2 -> V_35 = F_13 ;
if ( V_2 -> V_47 [ 0 ] . V_49 & V_50 )
V_2 -> V_41 . V_42 = F_14 ;
V_2 -> V_51 = V_46 ;
V_2 -> V_43 = F_15 ;
F_19 ( & V_46 -> V_44 , & V_45 -> V_52 ) ;
return 0 ;
}
static int F_20 ( struct V_36 * V_37 ,
struct V_15 * V_16 )
{
struct V_27 * V_28 = F_11 ( V_37 ) ;
int V_53 ;
V_53 = F_6 ( V_28 ) ;
if ( V_53 < 0 )
return V_53 ;
V_16 -> type = V_28 -> V_11 . type ;
V_16 -> V_12 = V_28 -> V_11 . V_12 ;
V_16 -> V_14 . integer . V_24 = V_28 -> V_11 . V_23 ;
V_16 -> V_14 . integer . V_26 = V_28 -> V_11 . V_25 ;
return 0 ;
}
static int F_21 ( struct V_36 * V_37 ,
struct V_3 * V_33 )
{
struct V_27 * V_28 = F_11 ( V_37 ) ;
int V_5 = F_6 ( V_28 ) ;
if ( V_5 < 0 )
return V_5 ;
V_33 -> V_14 . integer . V_14 [ 0 ] = V_28 -> V_29 ;
return 0 ;
}
static int F_22 ( struct V_27 * V_28 , int V_54 , int V_55 )
{
struct V_1 * V_2 ;
struct V_3 * V_56 ;
V_56 = F_2 ( sizeof( * V_56 ) , V_7 ) ;
if ( ! V_56 )
return - V_8 ;
F_7 (slave, &master->slaves, list) {
V_28 -> V_29 = V_54 ;
V_56 -> V_9 = V_2 -> V_2 . V_9 ;
F_8 ( V_2 , V_56 ) ;
V_28 -> V_29 = V_55 ;
F_9 ( V_2 , V_56 ) ;
}
F_3 ( V_56 ) ;
return 0 ;
}
static int F_23 ( struct V_36 * V_37 ,
struct V_3 * V_33 )
{
struct V_27 * V_28 = F_11 ( V_37 ) ;
int V_5 , V_55 , V_54 ;
bool V_57 ;
V_5 = F_6 ( V_28 ) ;
if ( V_5 < 0 )
return V_5 ;
V_57 = V_5 ;
V_54 = V_28 -> V_29 ;
V_55 = V_33 -> V_14 . integer . V_14 [ 0 ] ;
if ( V_55 == V_54 )
return 0 ;
V_5 = F_22 ( V_28 , V_54 , V_55 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_28 -> V_30 && ! V_57 )
V_28 -> V_30 ( V_28 -> V_31 , V_28 -> V_29 ) ;
return 1 ;
}
static void F_24 ( struct V_36 * V_37 )
{
struct V_27 * V_28 = F_11 ( V_37 ) ;
struct V_1 * V_2 , * V_58 ;
F_25 (slave, n, &master->slaves, list) {
struct V_36 * V_59 = V_2 -> V_48 ;
struct V_60 V_61 = V_59 -> V_44 ;
memcpy ( V_59 , & V_2 -> V_2 , sizeof( * V_59 ) ) ;
memcpy ( V_59 -> V_47 , V_2 -> V_2 . V_47 ,
V_59 -> V_12 * sizeof( * V_59 -> V_47 ) ) ;
V_59 -> V_44 = V_61 ;
F_3 ( V_2 ) ;
}
F_3 ( V_28 ) ;
}
struct V_36 * F_26 ( char * V_62 ,
const unsigned int * V_41 )
{
struct V_27 * V_28 ;
struct V_36 * V_48 ;
struct V_63 V_64 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_65 = V_66 ;
V_64 . V_62 = V_62 ;
V_64 . V_11 = F_20 ;
V_28 = F_18 ( sizeof( * V_28 ) , V_7 ) ;
if ( ! V_28 )
return NULL ;
F_27 ( & V_28 -> V_52 ) ;
V_48 = F_28 ( & V_64 , V_28 ) ;
if ( ! V_48 ) {
F_3 ( V_28 ) ;
return NULL ;
}
V_48 -> V_11 = F_20 ;
V_48 -> V_10 = F_21 ;
V_48 -> V_35 = F_23 ;
V_48 -> V_43 = F_24 ;
if ( V_41 &&
( V_41 [ 0 ] == V_67 ||
V_41 [ 0 ] == V_68 ||
V_41 [ 0 ] == V_69 ) ) {
V_48 -> V_47 [ 0 ] . V_49 |= V_70 ;
memcpy ( V_28 -> V_41 , V_41 , sizeof( V_28 -> V_41 ) ) ;
V_48 -> V_41 . V_71 = V_28 -> V_41 ;
}
return V_48 ;
}
int F_29 ( struct V_36 * V_37 ,
void (* V_30)( void * V_51 , int ) ,
void * V_51 )
{
struct V_27 * V_28 = F_11 ( V_37 ) ;
V_28 -> V_30 = V_30 ;
V_28 -> V_31 = V_51 ;
return 0 ;
}
void F_30 ( struct V_36 * V_37 , bool V_72 )
{
struct V_27 * V_28 ;
bool V_57 = false ;
if ( ! V_37 )
return;
V_28 = F_11 ( V_37 ) ;
if ( ! V_72 ) {
int V_5 = F_6 ( V_28 ) ;
if ( V_5 < 0 )
return;
V_57 = V_5 ;
V_5 = F_22 ( V_28 , V_28 -> V_29 , V_28 -> V_29 ) ;
if ( V_5 < 0 )
return;
}
if ( V_28 -> V_30 && ! V_57 )
V_28 -> V_30 ( V_28 -> V_31 , V_28 -> V_29 ) ;
}
