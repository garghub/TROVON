int F_1 ( void )
{
int V_1 = - 1 ;
V_2 = F_2 ( L_1 , NULL ) ;
if ( ! V_2 ) {
F_3 ( V_3 L_2 ) ;
return V_1 ;
}
if ( ! V_2 ) {
F_3 ( V_3
L_3 ) ;
return V_1 ;
}
V_4 = F_2 ( L_4 ,
V_2 ) ;
if ( ! V_4 ) {
F_3 ( V_3 L_5 ) ;
return V_1 ;
}
V_1 = 0 ;
return V_1 ;
}
void F_4 ( void )
{
F_5 ( V_4 ) ;
V_4 = NULL ;
F_5 ( V_2 ) ;
V_2 = NULL ;
}
static int F_6 ( struct V_5 * V_5 , struct V_6 * V_7 )
{
V_7 -> V_8 = V_5 -> V_9 ;
return 0 ;
}
static T_1 F_7 ( struct V_6 * V_7 ,
char T_2 * V_10 ,
T_3 V_11 , T_4 * V_12 )
{
char V_13 [ 64 ] ;
int V_14 ;
V_14 = sprintf ( V_13 , L_6 , V_15 ) ;
return F_8 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
}
static T_1 F_9 ( struct V_6 * V_7 ,
const char T_2 * V_10 ,
T_3 V_11 , T_4 * V_12 )
{
char V_13 [ 64 ] ;
unsigned long V_16 ;
int V_17 ;
if ( V_11 >= sizeof( V_13 ) )
return - V_18 ;
if ( F_10 ( & V_13 , V_10 , V_11 ) )
return - V_19 ;
V_13 [ V_11 ] = 0 ;
V_17 = F_11 ( V_13 , 10 , & V_16 ) ;
if ( V_17 < 0 )
return V_17 ;
V_15 = V_16 ;
( * V_12 ) ++ ;
return V_11 ;
}
static int F_12 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
T_5 * V_20 ;
V_20 = F_13 ( sizeof( T_5 ) , V_21 ) ;
if ( ! V_20 )
return - V_22 ;
V_20 -> V_23 = F_14 ( ( 3 * ( V_24 * V_25 ) ) ) ;
if ( ! V_20 -> V_23 ) {
F_15 ( V_20 ) ;
return - V_22 ;
}
memset ( ( void * ) V_20 -> V_23 , 0 ,
( 3 * ( V_24 * V_25 ) ) ) ;
V_20 -> V_26 = F_16 ( V_20 ) ;
V_6 -> V_8 = V_20 ;
return 0 ;
}
static T_4 F_17 ( struct V_6 * V_6 ,
T_4 V_27 ,
int V_28 )
{
T_5 * V_20 = V_6 -> V_8 ;
return F_18 ( V_6 , V_27 , V_28 ,
V_20 -> V_26 ) ;
}
static T_1 F_19 ( struct V_6 * V_6 ,
char T_2 * V_10 ,
T_3 V_29 ,
T_4 * V_30 )
{
T_5 * V_20 = V_6 -> V_8 ;
int V_1 = 0 ;
V_1 = F_8 ( V_10 , V_29 , V_30 ,
V_20 -> V_23 ,
V_20 -> V_26 ) ;
return V_1 ;
}
static int F_20 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
T_5 * V_20 = V_6 -> V_8 ;
F_21 ( V_20 -> V_23 ) ;
F_15 ( V_20 ) ;
return 0 ;
}
int F_22 ( void )
{
int V_1 = - 1 ;
if ( ! V_2 ) {
F_3 ( V_3
L_7 ) ;
return V_1 ;
}
V_31 = F_23 ( L_8 ,
V_32 | V_33 | V_34 ,
V_2 ,
NULL , & V_35 ) ;
if ( ! V_31 ) {
F_3 ( V_3
L_9 ) ;
return V_1 ;
}
V_36 = F_23 ( L_10 ,
V_32 | V_33 | V_34 ,
V_2 ,
NULL ,
& V_37 ) ;
if ( ! V_36 ) {
F_3 ( V_3
L_11 ) ;
return V_1 ;
}
V_1 = 0 ;
return V_1 ;
}
void F_24 ( void )
{
if ( V_36 ) {
F_5 ( V_36 ) ;
V_36 = NULL ;
}
if ( V_31 ) {
F_5 ( V_31 ) ;
V_31 = NULL ;
}
}
static int F_25 ( struct V_5 * V_5 , struct V_6 * V_6 )
{
struct V_38 * V_39 ;
V_39 = F_13 ( sizeof( struct V_38 ) , V_21 ) ;
if ( ! V_39 )
return - V_22 ;
V_39 -> V_9 = V_5 -> V_9 ;
V_6 -> V_8 = V_39 ;
return 0 ;
}
static T_1 F_26 ( struct V_6 * V_6 ,
char T_2 * V_10 ,
T_3 V_11 , T_4 * V_12 )
{
struct V_38 * V_39 = V_6 -> V_8 ;
struct V_40 * V_40 = (struct V_40 * ) V_39 -> V_9 ;
char V_13 [ 64 ] ;
int V_14 ;
V_14 = sprintf ( V_13 , L_6 , V_40 -> V_41 ) ;
return F_8 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
}
static T_1 F_27 ( struct V_6 * V_6 ,
const char T_2 * V_10 ,
T_3 V_11 , T_4 * V_12 )
{
struct V_38 * V_39 = V_6 -> V_8 ;
struct V_40 * V_40 = (struct V_40 * ) V_39 -> V_9 ;
struct V_42 * V_43 = & V_40 -> V_42 ;
T_6 * V_44 = ( T_6 * ) & V_43 -> V_45 ;
T_6 * V_46 = ( T_6 * ) & V_43 -> V_47 ;
char V_13 [ 64 ] ;
unsigned long V_16 ;
int V_17 ;
if ( V_11 >= sizeof( V_13 ) )
return - V_18 ;
if ( F_10 ( & V_13 , V_10 , V_11 ) )
return - V_19 ;
V_13 [ V_11 ] = 0 ;
V_17 = F_11 ( V_13 , 10 , & V_16 ) ;
if ( V_17 < 0 )
return V_17 ;
V_40 -> V_41 = V_16 ;
if ( V_40 -> V_41 ) {
F_28 ( & V_40 -> V_48 ,
F_29 ( & V_43 -> V_45 . V_49 ) ) ;
memset ( & V_43 -> V_50 , 0 , sizeof( struct V_51 ) ) ;
memset ( & V_43 -> V_52 , 0 ,
sizeof( struct V_53 ) ) ;
memset ( & V_43 -> V_41 , 0 , sizeof( struct V_41 ) ) ;
memset ( & V_43 -> V_54 , 0 , sizeof( struct V_54 ) ) ;
memset ( & V_43 -> V_55 , 0 , sizeof( struct V_55 ) ) ;
memset ( V_44 + 1 , 0 ,
sizeof( struct V_56 ) - sizeof( T_6 ) ) ;
memset ( V_46 + 1 , 0 ,
sizeof( struct V_47 ) - sizeof( T_6 ) ) ;
}
( * V_12 ) ++ ;
return V_11 ;
}
static int F_30 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_38 * V_39 = V_6 -> V_8 ;
F_15 ( V_39 ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_40 * V_40 = V_5 -> V_9 ;
struct V_42 * V_42 = & V_40 -> V_42 ;
struct V_38 * V_39 ;
int V_57 = 2 * V_25 ;
V_39 = F_13 ( sizeof( struct V_38 ) , V_21 ) ;
if ( ! V_39 )
return - V_22 ;
V_39 -> V_58 = F_14 ( V_57 ) ;
if ( ! V_39 -> V_58 ) {
F_15 ( V_39 ) ;
return - V_22 ;
}
V_39 -> V_57 = V_57 ;
memset ( ( void * ) V_39 -> V_58 , 0 , V_57 ) ;
V_39 -> V_26 = F_32 ( V_39 , V_42 ) ;
V_6 -> V_8 = V_39 ;
return 0 ;
}
static T_1 F_33 ( struct V_6 * V_6 ,
char T_2 * V_10 ,
T_3 V_29 ,
T_4 * V_30 )
{
struct V_38 * V_39 = V_6 -> V_8 ;
int V_1 = 0 ;
V_1 = F_8 ( V_10 , V_29 , V_30 ,
V_39 -> V_58 ,
V_39 -> V_26 ) ;
return V_1 ;
}
static int F_34 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_38 * V_39 = V_6 -> V_8 ;
F_21 ( V_39 -> V_58 ) ;
F_15 ( V_39 ) ;
return 0 ;
}
int F_35 ( struct V_40 * V_40 )
{
int V_1 = - 1 ;
char V_59 [ 16 ] ;
snprintf ( V_59 , sizeof( V_59 ) , L_12 , V_40 -> V_60 -> V_61 -> V_62 ) ;
if ( ! V_4 ) {
F_3 ( V_3 L_13 ) ;
return V_1 ;
}
V_40 -> V_63 = F_2 ( V_59 ,
V_4 ) ;
if ( ! V_40 -> V_63 ) {
F_3 ( V_3 L_14 ) ;
return V_1 ;
}
V_40 -> V_64 = F_23 ( L_15 ,
V_32 | V_33 | V_34 ,
V_40 -> V_63 ,
V_40 ,
& V_65 ) ;
if ( ! V_40 -> V_64 ) {
F_3 ( V_3 L_16 ) ;
return V_1 ;
}
V_40 -> V_66 = F_23 ( L_17 ,
V_32 | V_33 | V_34 ,
V_40 -> V_63 ,
V_40 ,
& V_67 ) ;
if ( ! V_40 -> V_66 ) {
F_3 ( V_3 L_16 ) ;
return V_1 ;
}
V_1 = 0 ;
return V_1 ;
}
void F_36 ( struct V_40 * V_40 )
{
if ( ! V_40 )
return;
F_5 ( V_40 -> V_64 ) ;
V_40 -> V_64 = NULL ;
F_5 ( V_40 -> V_66 ) ;
V_40 -> V_66 = NULL ;
F_5 ( V_40 -> V_63 ) ;
V_40 -> V_63 = NULL ;
}
