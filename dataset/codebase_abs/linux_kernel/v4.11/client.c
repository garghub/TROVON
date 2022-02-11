static int
F_1 ( const struct V_1 * V_2 , void * V_3 , T_1 V_4 ,
struct V_5 * * V_6 )
{
union {
struct V_7 V_8 ;
} * args = V_3 ;
struct V_9 * V_10 ;
int V_11 = - V_12 ;
if ( ! ( V_11 = F_2 ( V_11 , & V_3 , & V_4 , args -> V_8 , 0 , 0 , false ) ) ) {
args -> V_8 . V_13 [ sizeof( args -> V_8 . V_13 ) - 1 ] = 0 ;
V_11 = F_3 ( args -> V_8 . V_13 , args -> V_8 . V_14 , NULL ,
NULL , V_2 -> V_10 -> V_15 , & V_10 ) ;
if ( V_11 )
return V_11 ;
} else
return V_11 ;
V_10 -> V_16 . V_10 = V_2 -> V_10 ;
V_10 -> V_16 . V_17 = V_2 -> V_17 ;
V_10 -> V_16 . V_18 = V_2 -> V_18 ;
V_10 -> V_16 . V_19 = V_2 -> V_19 ;
V_10 -> V_16 . V_16 = V_2 -> V_16 ;
V_10 -> V_20 = V_2 -> V_10 -> V_20 ;
* V_6 = & V_10 -> V_16 ;
return 0 ;
}
static int
F_4 ( struct V_21 * V_22 )
{
struct F_4 * V_23 = F_5 ( V_22 , F_6 ( * V_23 ) , V_22 ) ;
struct V_9 * V_10 = V_23 -> V_10 ;
return V_10 -> V_15 ( & V_23 -> V_24 , V_23 -> V_25 , V_22 -> V_26 , V_22 -> V_25 ) ;
}
int
F_7 ( struct V_9 * V_10 , int V_27 )
{
if ( V_27 < F_8 ( V_10 -> V_23 ) ) {
if ( V_10 -> V_23 [ V_27 ] ) {
F_9 ( & V_10 -> V_23 [ V_27 ] -> V_22 ) ;
return 0 ;
}
}
return - V_28 ;
}
int
F_10 ( struct V_9 * V_10 , int V_27 )
{
if ( V_27 < F_8 ( V_10 -> V_23 ) ) {
if ( V_10 -> V_23 [ V_27 ] ) {
F_11 ( & V_10 -> V_23 [ V_27 ] -> V_22 ) ;
return 0 ;
}
}
return - V_28 ;
}
int
F_12 ( struct V_9 * V_10 , int V_27 )
{
if ( V_27 < F_8 ( V_10 -> V_23 ) ) {
if ( V_10 -> V_23 [ V_27 ] ) {
F_13 ( & V_10 -> V_23 [ V_27 ] -> V_22 ) ;
F_14 ( V_10 -> V_23 [ V_27 ] ) ;
V_10 -> V_23 [ V_27 ] = NULL ;
return 0 ;
}
}
return - V_28 ;
}
int
F_15 ( struct V_5 * V_16 ,
struct V_29 * V_30 , void * V_26 , T_1 V_25 )
{
struct V_9 * V_10 = V_16 -> V_10 ;
struct F_4 * V_23 ;
union {
struct V_31 V_8 ;
} * V_32 = V_26 ;
T_2 V_27 , V_33 ;
int V_11 = - V_12 ;
for ( V_27 = 0 ; V_27 < F_8 ( V_10 -> V_23 ) ; V_27 ++ ) {
if ( ! V_10 -> V_23 [ V_27 ] )
break;
}
if ( V_27 == F_8 ( V_10 -> V_23 ) )
return - V_34 ;
V_23 = F_16 ( sizeof( * V_23 ) , V_35 ) ;
if ( ! V_23 )
return - V_36 ;
F_17 ( V_16 , L_1 , V_25 ) ;
if ( ! ( V_11 = F_2 ( V_11 , & V_26 , & V_25 , V_32 -> V_8 , 0 , 0 , true ) ) ) {
F_17 ( V_16 , L_2
L_3 , V_32 -> V_8 . V_37 ,
V_32 -> V_8 . V_33 , V_32 -> V_8 . V_18 , V_32 -> V_8 . V_19 ) ;
V_23 -> V_37 = V_32 -> V_8 . V_37 ;
V_23 -> V_25 = sizeof( V_23 -> V_24 . V_8 ) ;
V_23 -> V_24 . V_8 . V_37 = V_32 -> V_8 . V_37 ;
V_23 -> V_24 . V_8 . V_18 = V_32 -> V_8 . V_18 ;
V_23 -> V_24 . V_8 . V_19 = V_32 -> V_8 . V_19 ;
V_33 = V_32 -> V_8 . V_33 ;
}
if ( V_11 == 0 ) {
V_11 = F_18 ( V_16 , V_30 , F_4 ,
false , V_26 , V_25 , V_33 , & V_23 -> V_22 ) ;
if ( V_11 == 0 ) {
V_10 -> V_23 [ V_27 ] = V_23 ;
V_23 -> V_10 = V_10 ;
return V_27 ;
}
}
F_14 ( V_23 ) ;
return V_11 ;
}
struct V_9 *
F_19 ( struct V_9 * V_10 , T_3 V_17 )
{
struct V_5 * V_16 ;
V_16 = F_20 ( V_10 , V_17 , & V_9 ) ;
if ( F_21 ( V_16 ) )
return ( void * ) V_16 ;
return V_9 ( V_16 ) ;
}
static int
F_22 ( struct V_9 * V_10 , void * V_26 , T_1 V_25 )
{
union {
struct V_38 V_8 ;
} * args = V_26 ;
int V_11 = - V_12 ;
F_17 ( & V_10 -> V_16 , L_4 , V_25 ) ;
if ( ! ( V_11 = F_2 ( V_11 , & V_26 , & V_25 , args -> V_8 , 0 , 0 , true ) ) ) {
F_17 ( & V_10 -> V_16 , L_5 ,
args -> V_8 . V_37 , args -> V_8 . V_39 ) ;
if ( V_25 == sizeof( args -> V_8 . V_14 [ 0 ] ) * args -> V_8 . V_39 ) {
V_11 = F_23 ( args -> V_8 . V_14 , args -> V_8 . V_39 ) ;
if ( V_11 >= 0 ) {
args -> V_8 . V_39 = V_11 ;
V_11 = 0 ;
}
} else {
V_11 = - V_40 ;
}
}
return V_11 ;
}
static int
F_24 ( struct V_5 * V_16 , T_1 V_41 , void * V_26 , T_1 V_25 )
{
struct V_9 * V_10 = V_9 ( V_16 ) ;
switch ( V_41 ) {
case V_42 :
return F_22 ( V_10 , V_26 , V_25 ) ;
default:
break;
}
return - V_40 ;
}
static int
F_25 ( const struct V_1 * V_2 ,
void * V_26 , T_1 V_25 , struct V_5 * * V_6 )
{
return V_2 -> V_43 . V_44 ( V_2 , V_26 , V_25 , V_6 ) ;
}
static int
F_26 ( struct V_5 * V_16 , int V_27 ,
struct V_1 * V_2 )
{
const struct V_45 * V_46 ;
switch ( V_27 ) {
case 0 : V_46 = & V_47 ; break;
case 1 : V_46 = & V_48 ; break;
default:
return - V_40 ;
}
V_2 -> V_44 = F_25 ;
V_2 -> V_43 = * V_46 ;
return 0 ;
}
static int
F_27 ( struct V_5 * V_16 , bool V_49 )
{
struct V_9 * V_10 = V_9 ( V_16 ) ;
const char * V_13 [ 2 ] = { L_6 , L_7 } ;
int V_50 ;
F_28 ( V_16 , L_8 , V_13 [ V_49 ] ) ;
for ( V_50 = 0 ; V_50 < F_8 ( V_10 -> V_23 ) ; V_50 ++ )
F_7 ( V_10 , V_50 ) ;
return 0 ;
}
static void *
F_29 ( struct V_5 * V_16 )
{
struct V_9 * V_10 = V_9 ( V_16 ) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < F_8 ( V_10 -> V_23 ) ; V_50 ++ )
F_12 ( V_10 , V_50 ) ;
return V_10 ;
}
int
F_3 ( const char * V_13 , T_3 V_14 , const char * V_51 ,
const char * V_52 ,
int (* V_15)( const void * , T_1 , const void * , T_1 ) ,
struct V_9 * * V_53 )
{
struct V_1 V_2 = { . V_43 = V_47 } ;
struct V_9 * V_10 ;
if ( ! ( V_10 = * V_53 = F_16 ( sizeof( * V_10 ) , V_35 ) ) )
return - V_36 ;
V_2 . V_10 = V_10 ;
F_30 ( & V_9 , & V_2 , & V_10 -> V_16 ) ;
snprintf ( V_10 -> V_13 , sizeof( V_10 -> V_13 ) , L_9 , V_13 ) ;
V_10 -> V_14 = V_14 ;
V_10 -> V_20 = F_31 ( V_52 , L_10 ) ;
V_10 -> V_54 = V_55 ;
V_10 -> V_15 = V_15 ;
return 0 ;
}
