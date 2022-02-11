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
F_5 ( L_1 ) ;
F_3 ( V_16 ) ;
return - V_21 ;
}
V_2 -> V_11 . V_22 = V_16 -> V_14 . integer . V_23 ;
V_2 -> V_11 . V_24 = V_16 -> V_14 . integer . V_25 ;
F_3 ( V_16 ) ;
return F_1 ( V_2 ) ;
}
static int F_6 ( struct V_26 * V_27 )
{
struct V_1 * V_2 ;
if ( V_27 -> V_11 . V_12 )
return 0 ;
F_7 (slave, &master->slaves, list) {
int V_5 = F_4 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_27 -> V_11 = V_2 -> V_11 ;
V_27 -> V_11 . V_12 = 1 ;
V_27 -> V_28 = V_27 -> V_11 . V_24 ;
if ( V_27 -> V_29 )
V_27 -> V_29 ( V_27 -> V_30 , V_27 -> V_28 ) ;
return 1 ;
}
return - V_31 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_32 )
{
int V_5 , V_6 ;
V_5 = F_4 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 . V_12 ; V_6 ++ )
V_32 -> V_14 . integer . V_14 [ V_6 ] = V_2 -> V_13 [ V_6 ] ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_32 )
{
int V_5 , V_6 , V_33 ;
V_5 = F_6 ( V_2 -> V_27 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( V_2 -> V_11 . type ) {
case V_20 :
for ( V_6 = 0 ; V_6 < V_2 -> V_11 . V_12 ; V_6 ++ )
V_32 -> V_14 . integer . V_14 [ V_6 ] &=
! ! V_2 -> V_27 -> V_28 ;
break;
case V_19 :
for ( V_6 = 0 ; V_6 < V_2 -> V_11 . V_12 ; V_6 ++ ) {
V_33 = V_32 -> V_14 . integer . V_14 [ V_6 ] ;
V_33 += V_2 -> V_27 -> V_28 - V_2 -> V_27 -> V_11 . V_24 ;
if ( V_33 < V_2 -> V_11 . V_22 )
V_33 = V_2 -> V_11 . V_22 ;
else if ( V_33 > V_2 -> V_11 . V_24 )
V_33 = V_2 -> V_11 . V_24 ;
V_32 -> V_14 . integer . V_14 [ V_6 ] = V_33 ;
}
break;
}
return V_2 -> V_2 . V_34 ( & V_2 -> V_2 , V_32 ) ;
}
static int F_10 ( struct V_35 * V_36 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_36 ) ;
return V_2 -> V_2 . V_11 ( & V_2 -> V_2 , V_16 ) ;
}
static int F_12 ( struct V_35 * V_36 ,
struct V_3 * V_32 )
{
struct V_1 * V_2 = F_11 ( V_36 ) ;
return F_8 ( V_2 , V_32 ) ;
}
static int F_13 ( struct V_35 * V_36 ,
struct V_3 * V_32 )
{
struct V_1 * V_2 = F_11 ( V_36 ) ;
int V_5 , V_6 , V_37 = 0 ;
V_5 = F_4 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 . V_12 ; V_6 ++ ) {
if ( V_2 -> V_13 [ V_6 ] != V_32 -> V_14 . integer . V_14 [ V_6 ] ) {
V_37 = 1 ;
V_2 -> V_13 [ V_6 ] = V_32 -> V_14 . integer . V_14 [ V_6 ] ;
}
}
if ( ! V_37 )
return 0 ;
V_5 = F_9 ( V_2 , V_32 ) ;
if ( V_5 < 0 )
return V_5 ;
return 1 ;
}
static int F_14 ( struct V_35 * V_36 ,
int V_38 , unsigned int V_39 ,
unsigned int T_1 * V_40 )
{
struct V_1 * V_2 = F_11 ( V_36 ) ;
return V_2 -> V_2 . V_40 . V_41 ( & V_2 -> V_2 , V_38 , V_39 , V_40 ) ;
}
static void F_15 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_11 ( V_36 ) ;
if ( V_2 -> V_2 . V_42 )
V_2 -> V_2 . V_42 ( & V_2 -> V_2 ) ;
if ( V_2 -> V_27 )
F_16 ( & V_2 -> V_43 ) ;
F_3 ( V_2 ) ;
}
int F_17 ( struct V_35 * V_27 , struct V_35 * V_2 ,
unsigned int V_17 )
{
struct V_26 * V_44 = F_11 ( V_27 ) ;
struct V_1 * V_45 ;
V_45 = F_18 ( sizeof( * V_45 ) +
V_2 -> V_12 * sizeof( * V_2 -> V_46 ) , V_7 ) ;
if ( ! V_45 )
return - V_8 ;
V_45 -> V_47 = V_2 ;
V_45 -> V_2 = * V_2 ;
memcpy ( V_45 -> V_2 . V_46 , V_2 -> V_46 , V_2 -> V_12 * sizeof( * V_2 -> V_46 ) ) ;
V_45 -> V_27 = V_44 ;
V_45 -> V_17 = V_17 ;
V_2 -> V_11 = F_10 ;
V_2 -> V_10 = F_12 ;
V_2 -> V_34 = F_13 ;
if ( V_2 -> V_46 [ 0 ] . V_48 & V_49 )
V_2 -> V_40 . V_41 = F_14 ;
V_2 -> V_50 = V_45 ;
V_2 -> V_42 = F_15 ;
F_19 ( & V_45 -> V_43 , & V_44 -> V_51 ) ;
return 0 ;
}
static int F_20 ( struct V_35 * V_36 ,
struct V_15 * V_16 )
{
struct V_26 * V_27 = F_11 ( V_36 ) ;
int V_52 ;
V_52 = F_6 ( V_27 ) ;
if ( V_52 < 0 )
return V_52 ;
V_16 -> type = V_27 -> V_11 . type ;
V_16 -> V_12 = V_27 -> V_11 . V_12 ;
V_16 -> V_14 . integer . V_23 = V_27 -> V_11 . V_22 ;
V_16 -> V_14 . integer . V_25 = V_27 -> V_11 . V_24 ;
return 0 ;
}
static int F_21 ( struct V_35 * V_36 ,
struct V_3 * V_32 )
{
struct V_26 * V_27 = F_11 ( V_36 ) ;
int V_5 = F_6 ( V_27 ) ;
if ( V_5 < 0 )
return V_5 ;
V_32 -> V_14 . integer . V_14 [ 0 ] = V_27 -> V_28 ;
return 0 ;
}
static int F_22 ( struct V_26 * V_27 , int V_53 , int V_54 )
{
struct V_1 * V_2 ;
struct V_3 * V_55 ;
V_55 = F_2 ( sizeof( * V_55 ) , V_7 ) ;
if ( ! V_55 )
return - V_8 ;
F_7 (slave, &master->slaves, list) {
V_27 -> V_28 = V_53 ;
V_55 -> V_9 = V_2 -> V_2 . V_9 ;
F_8 ( V_2 , V_55 ) ;
V_27 -> V_28 = V_54 ;
F_9 ( V_2 , V_55 ) ;
}
F_3 ( V_55 ) ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_3 * V_32 )
{
struct V_26 * V_27 = F_11 ( V_36 ) ;
int V_5 , V_54 , V_53 ;
bool V_56 ;
V_5 = F_6 ( V_27 ) ;
if ( V_5 < 0 )
return V_5 ;
V_56 = V_5 ;
V_53 = V_27 -> V_28 ;
V_54 = V_32 -> V_14 . integer . V_14 [ 0 ] ;
if ( V_54 == V_53 )
return 0 ;
V_5 = F_22 ( V_27 , V_53 , V_54 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_27 -> V_29 && ! V_56 )
V_27 -> V_29 ( V_27 -> V_30 , V_27 -> V_28 ) ;
return 1 ;
}
static void F_24 ( struct V_35 * V_36 )
{
struct V_26 * V_27 = F_11 ( V_36 ) ;
struct V_1 * V_2 , * V_57 ;
F_25 (slave, n, &master->slaves, list) {
struct V_35 * V_58 = V_2 -> V_47 ;
struct V_59 V_60 = V_58 -> V_43 ;
memcpy ( V_58 , & V_2 -> V_2 , sizeof( * V_58 ) ) ;
memcpy ( V_58 -> V_46 , V_2 -> V_2 . V_46 ,
V_58 -> V_12 * sizeof( * V_58 -> V_46 ) ) ;
V_58 -> V_43 = V_60 ;
F_3 ( V_2 ) ;
}
F_3 ( V_27 ) ;
}
struct V_35 * F_26 ( char * V_61 ,
const unsigned int * V_40 )
{
struct V_26 * V_27 ;
struct V_35 * V_47 ;
struct V_62 V_63 ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_64 = V_65 ;
V_63 . V_61 = V_61 ;
V_63 . V_11 = F_20 ;
V_27 = F_18 ( sizeof( * V_27 ) , V_7 ) ;
if ( ! V_27 )
return NULL ;
F_27 ( & V_27 -> V_51 ) ;
V_47 = F_28 ( & V_63 , V_27 ) ;
if ( ! V_47 ) {
F_3 ( V_27 ) ;
return NULL ;
}
V_47 -> V_11 = F_20 ;
V_47 -> V_10 = F_21 ;
V_47 -> V_34 = F_23 ;
V_47 -> V_42 = F_24 ;
if ( V_40 &&
( V_40 [ 0 ] == V_66 ||
V_40 [ 0 ] == V_67 ||
V_40 [ 0 ] == V_68 ) ) {
V_47 -> V_46 [ 0 ] . V_48 |= V_69 ;
memcpy ( V_27 -> V_40 , V_40 , sizeof( V_27 -> V_40 ) ) ;
V_47 -> V_40 . V_70 = V_27 -> V_40 ;
}
return V_47 ;
}
int F_29 ( struct V_35 * V_36 ,
void (* V_29)( void * V_50 , int ) ,
void * V_50 )
{
struct V_26 * V_27 = F_11 ( V_36 ) ;
V_27 -> V_29 = V_29 ;
V_27 -> V_30 = V_50 ;
return 0 ;
}
void F_30 ( struct V_35 * V_36 , bool V_71 )
{
struct V_26 * V_27 ;
bool V_56 = false ;
if ( ! V_36 )
return;
V_27 = F_11 ( V_36 ) ;
if ( ! V_71 ) {
int V_5 = F_6 ( V_27 ) ;
if ( V_5 < 0 )
return;
V_56 = V_5 ;
V_5 = F_22 ( V_27 , V_27 -> V_28 , V_27 -> V_28 ) ;
if ( V_5 < 0 )
return;
}
if ( V_27 -> V_29 && ! V_56 )
V_27 -> V_29 ( V_27 -> V_30 , V_27 -> V_28 ) ;
}
int F_31 ( struct V_35 * V_47 ,
int (* F_32)( struct V_35 * , void * ) ,
void * V_72 )
{
struct V_26 * V_27 ;
struct V_1 * V_2 ;
int V_5 ;
V_27 = F_11 ( V_47 ) ;
V_5 = F_6 ( V_27 ) ;
if ( V_5 < 0 )
return V_5 ;
F_7 (slave, &master->slaves, list) {
V_5 = F_32 ( & V_2 -> V_2 , V_72 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
