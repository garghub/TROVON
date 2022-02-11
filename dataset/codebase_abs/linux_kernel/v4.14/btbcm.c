int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , V_7 , 0 , NULL ,
V_8 ) ;
if ( F_3 ( V_6 ) ) {
int V_9 = F_4 ( V_6 ) ;
F_5 ( L_1 ,
V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
if ( V_6 -> V_11 != sizeof( * V_4 ) ) {
F_5 ( L_2 , V_2 -> V_10 ) ;
F_6 ( V_6 ) ;
return - V_12 ;
}
V_4 = (struct V_3 * ) V_6 -> V_13 ;
if ( ! F_7 ( & V_4 -> V_14 , V_15 ) ||
! F_7 ( & V_4 -> V_14 , V_16 ) ||
! F_7 ( & V_4 -> V_14 , V_17 ) ) {
F_8 ( L_3 ,
V_2 -> V_10 , & V_4 -> V_14 ) ;
F_9 ( V_18 , & V_2 -> V_19 ) ;
}
F_6 ( V_6 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , const T_1 * V_14 )
{
struct V_5 * V_6 ;
int V_9 ;
V_6 = F_2 ( V_2 , 0xfc01 , 6 , V_14 , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_5 ( L_4 ,
V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
F_6 ( V_6 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , const struct V_20 * V_21 )
{
const struct V_22 * V_23 ;
const T_2 * V_24 ;
T_3 V_25 ;
struct V_5 * V_6 ;
T_4 V_26 ;
int V_9 = 0 ;
V_6 = F_2 ( V_2 , 0xfc2e , 0 , NULL , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_5 ( L_5 ,
V_2 -> V_10 , V_9 ) ;
goto V_27;
}
F_6 ( V_6 ) ;
F_12 ( 50 ) ;
V_24 = V_21 -> V_13 ;
V_25 = V_21 -> V_28 ;
while ( V_25 >= sizeof( * V_23 ) ) {
const T_2 * V_29 ;
V_23 = (struct V_22 * ) V_24 ;
V_24 += sizeof( * V_23 ) ;
V_25 -= sizeof( * V_23 ) ;
if ( V_25 < V_23 -> V_30 ) {
F_5 ( L_6 , V_2 -> V_10 ) ;
V_9 = - V_31 ;
goto V_27;
}
V_29 = V_24 ;
V_24 += V_23 -> V_30 ;
V_25 -= V_23 -> V_30 ;
V_26 = F_13 ( V_23 -> V_26 ) ;
V_6 = F_2 ( V_2 , V_26 , V_23 -> V_30 , V_29 ,
V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_5 ( L_7 ,
V_2 -> V_10 , V_26 , V_9 ) ;
goto V_27;
}
F_6 ( V_6 ) ;
}
F_12 ( 250 ) ;
V_27:
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , V_32 , 0 , NULL , V_8 ) ;
if ( F_3 ( V_6 ) ) {
int V_9 = F_4 ( V_6 ) ;
F_5 ( L_8 , V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
F_6 ( V_6 ) ;
F_12 ( 100 ) ;
return 0 ;
}
static struct V_5 * F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , V_33 , 0 , NULL ,
V_8 ) ;
if ( F_3 ( V_6 ) ) {
F_5 ( L_9 ,
V_2 -> V_10 , F_4 ( V_6 ) ) ;
return V_6 ;
}
if ( V_6 -> V_11 != sizeof( struct V_34 ) ) {
F_5 ( L_10 , V_2 -> V_10 ) ;
F_6 ( V_6 ) ;
return F_16 ( - V_12 ) ;
}
return V_6 ;
}
static struct V_5 * F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , V_35 , 0 , NULL ,
V_8 ) ;
if ( F_3 ( V_6 ) ) {
F_5 ( L_11 ,
V_2 -> V_10 , F_4 ( V_6 ) ) ;
return V_6 ;
}
if ( V_6 -> V_11 != sizeof( struct V_36 ) ) {
F_5 ( L_12 , V_2 -> V_10 ) ;
F_6 ( V_6 ) ;
return F_16 ( - V_12 ) ;
}
return V_6 ;
}
static struct V_5 * F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , 0xfc79 , 0 , NULL , V_8 ) ;
if ( F_3 ( V_6 ) ) {
F_5 ( L_13 ,
V_2 -> V_10 , F_4 ( V_6 ) ) ;
return V_6 ;
}
if ( V_6 -> V_11 != 7 ) {
F_5 ( L_14 , V_2 -> V_10 ) ;
F_6 ( V_6 ) ;
return F_16 ( - V_12 ) ;
}
return V_6 ;
}
static struct V_5 * F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , 0xfc6e , 0 , NULL , V_8 ) ;
if ( F_3 ( V_6 ) ) {
F_5 ( L_15 ,
V_2 -> V_10 , F_4 ( V_6 ) ) ;
return V_6 ;
}
if ( V_6 -> V_11 != 9 ) {
F_5 ( L_16 ,
V_2 -> V_10 ) ;
F_6 ( V_6 ) ;
return F_16 ( - V_12 ) ;
}
return V_6 ;
}
static struct V_5 * F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , 0xfc5a , 0 , NULL , V_8 ) ;
if ( F_3 ( V_6 ) ) {
F_5 ( L_17 ,
V_2 -> V_10 , F_4 ( V_6 ) ) ;
return V_6 ;
}
if ( V_6 -> V_11 != 5 ) {
F_5 ( L_18 , V_2 -> V_10 ) ;
F_6 ( V_6 ) ;
return F_16 ( - V_12 ) ;
}
return V_6 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_18 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
F_8 ( L_19 , V_2 -> V_10 , V_6 -> V_13 [ 1 ] ) ;
F_6 ( V_6 ) ;
V_6 = F_19 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
F_8 ( L_20 , V_2 -> V_10 , V_6 -> V_13 [ 1 ] ) ;
F_6 ( V_6 ) ;
V_6 = F_15 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
F_8 ( L_21 , V_2 -> V_10 , ( char * ) ( V_6 -> V_13 + 1 ) ) ;
F_6 ( V_6 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , char * V_37 , T_3 V_11 )
{
T_4 V_38 , V_39 ;
const char * V_40 = NULL ;
struct V_5 * V_6 ;
struct V_36 * V_41 ;
int V_42 , V_9 ;
V_9 = F_14 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_6 = F_17 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_41 = (struct V_36 * ) V_6 -> V_13 ;
V_39 = F_13 ( V_41 -> V_43 ) ;
V_38 = F_13 ( V_41 -> V_44 ) ;
F_6 ( V_6 ) ;
V_9 = F_21 ( V_2 ) ;
if ( V_9 )
return V_9 ;
switch ( ( V_39 & 0xf000 ) >> 12 ) {
case 0 :
case 1 :
case 3 :
for ( V_42 = 0 ; V_45 [ V_42 ] . V_10 ; V_42 ++ ) {
if ( V_38 == V_45 [ V_42 ] . V_38 ) {
V_40 = V_45 [ V_42 ] . V_10 ;
break;
}
}
snprintf ( V_37 , V_11 , L_22 , V_40 ? : L_23 ) ;
break;
default:
return 0 ;
}
F_8 ( L_24 , V_2 -> V_10 ,
V_40 ? : L_23 , ( V_38 & 0xe000 ) >> 13 ,
( V_38 & 0x1f00 ) >> 8 , ( V_38 & 0x00ff ) , V_39 & 0x0fff ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_36 * V_41 ;
T_4 V_38 , V_39 ;
int V_9 ;
V_9 = F_14 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_6 = F_17 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_41 = (struct V_36 * ) V_6 -> V_13 ;
V_39 = F_13 ( V_41 -> V_43 ) ;
V_38 = F_13 ( V_41 -> V_44 ) ;
F_6 ( V_6 ) ;
F_8 ( L_25 , V_2 -> V_10 ,
( V_38 & 0xe000 ) >> 13 , ( V_38 & 0x1f00 ) >> 8 ,
( V_38 & 0x00ff ) , V_39 & 0x0fff ) ;
F_1 ( V_2 ) ;
F_9 ( V_46 , & V_2 -> V_19 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
char V_37 [ 64 ] ;
const struct V_20 * V_21 ;
T_4 V_38 , V_39 , V_47 , V_48 ;
const char * V_40 = NULL ;
struct V_5 * V_6 ;
struct V_36 * V_41 ;
int V_42 , V_9 ;
V_9 = F_14 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_6 = F_17 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_41 = (struct V_36 * ) V_6 -> V_13 ;
V_39 = F_13 ( V_41 -> V_43 ) ;
V_38 = F_13 ( V_41 -> V_44 ) ;
F_6 ( V_6 ) ;
V_9 = F_21 ( V_2 ) ;
if ( V_9 )
return V_9 ;
switch ( ( V_39 & 0xf000 ) >> 12 ) {
case 0 :
case 3 :
for ( V_42 = 0 ; V_45 [ V_42 ] . V_10 ; V_42 ++ ) {
if ( V_38 == V_45 [ V_42 ] . V_38 ) {
V_40 = V_45 [ V_42 ] . V_10 ;
break;
}
}
snprintf ( V_37 , sizeof( V_37 ) , L_22 ,
V_40 ? : L_23 ) ;
break;
case 1 :
case 2 :
V_6 = F_20 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_48 = F_25 ( V_6 -> V_13 + 1 ) ;
V_47 = F_25 ( V_6 -> V_13 + 3 ) ;
F_6 ( V_6 ) ;
for ( V_42 = 0 ; V_49 [ V_42 ] . V_10 ; V_42 ++ ) {
if ( V_38 == V_49 [ V_42 ] . V_38 ) {
V_40 = V_49 [ V_42 ] . V_10 ;
break;
}
}
snprintf ( V_37 , sizeof( V_37 ) , L_26 ,
V_40 ? : L_23 , V_48 , V_47 ) ;
break;
default:
return 0 ;
}
F_8 ( L_24 , V_2 -> V_10 ,
V_40 ? : L_23 , ( V_38 & 0xe000 ) >> 13 ,
( V_38 & 0x1f00 ) >> 8 , ( V_38 & 0x00ff ) , V_39 & 0x0fff ) ;
V_9 = F_26 ( & V_21 , V_37 , & V_2 -> V_50 ) ;
if ( V_9 < 0 ) {
F_8 ( L_27 , V_2 -> V_10 , V_37 ) ;
goto V_27;
}
F_11 ( V_2 , V_21 ) ;
F_27 ( V_21 ) ;
V_9 = F_14 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_6 = F_17 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_41 = (struct V_36 * ) V_6 -> V_13 ;
V_39 = F_13 ( V_41 -> V_43 ) ;
V_38 = F_13 ( V_41 -> V_44 ) ;
F_6 ( V_6 ) ;
F_8 ( L_24 , V_2 -> V_10 ,
V_40 ? : L_23 , ( V_38 & 0xe000 ) >> 13 ,
( V_38 & 0x1f00 ) >> 8 , ( V_38 & 0x00ff ) , V_39 & 0x0fff ) ;
V_6 = F_15 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
F_8 ( L_21 , V_2 -> V_10 , ( char * ) ( V_6 -> V_13 + 1 ) ) ;
F_6 ( V_6 ) ;
V_27:
F_1 ( V_2 ) ;
F_9 ( V_46 , & V_2 -> V_19 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_9 ;
V_9 = F_14 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_6 = F_18 ( V_2 ) ;
if ( ! F_3 ( V_6 ) ) {
F_8 ( L_28 , V_2 -> V_10 ,
V_6 -> V_13 [ 1 ] , F_25 ( V_6 -> V_13 + 5 ) ) ;
F_6 ( V_6 ) ;
}
V_6 = F_20 ( V_2 ) ;
if ( ! F_3 ( V_6 ) ) {
F_8 ( L_29 , V_2 -> V_10 ,
F_25 ( V_6 -> V_13 + 1 ) ,
F_25 ( V_6 -> V_13 + 3 ) ) ;
F_6 ( V_6 ) ;
}
V_6 = F_19 ( V_2 ) ;
if ( ! F_3 ( V_6 ) ) {
F_8 ( L_20 , V_2 -> V_10 , V_6 -> V_13 [ 1 ] ) ;
F_6 ( V_6 ) ;
}
V_6 = F_15 ( V_2 ) ;
if ( ! F_3 ( V_6 ) ) {
F_8 ( L_21 , V_2 -> V_10 , ( char * ) ( V_6 -> V_13 + 1 ) ) ;
F_6 ( V_6 ) ;
}
F_9 ( V_46 , & V_2 -> V_19 ) ;
return 0 ;
}
