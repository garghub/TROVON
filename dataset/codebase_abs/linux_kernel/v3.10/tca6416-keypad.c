static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
int error ;
error = V_2 -> V_5 > 8 ?
F_2 ( V_2 -> V_6 , V_3 << 1 , V_4 ) :
F_3 ( V_2 -> V_6 , V_3 , V_4 ) ;
if ( error < 0 ) {
F_4 ( & V_2 -> V_6 -> V_7 ,
L_1 ,
V_8 , V_3 , V_4 , error ) ;
return error ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
int V_9 ;
V_9 = V_2 -> V_5 > 8 ?
F_6 ( V_2 -> V_6 , V_3 << 1 ) :
F_7 ( V_2 -> V_6 , V_3 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_7 , L_2 ,
V_8 , V_3 , V_9 ) ;
return V_9 ;
}
* V_4 = ( T_1 ) V_9 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_12 , V_4 ;
int error , V_13 , V_14 ;
error = F_5 ( V_2 , V_15 , & V_12 ) ;
if ( error )
return;
V_12 &= V_2 -> V_16 ;
V_4 = V_12 ^ V_2 -> V_17 ;
V_2 -> V_17 = V_12 ;
for ( V_13 = 0 , V_14 = 0 ; V_13 < 16 ; V_13 ++ ) {
if ( V_4 & ( 1 << V_13 ) ) {
struct V_18 * V_19 = & V_2 -> V_20 [ V_14 ] ;
unsigned int type = V_19 -> type ? : V_21 ;
int V_22 = ( ( V_12 & ( 1 << V_13 ) ) ? 1 : 0 )
^ V_19 -> V_23 ;
F_9 ( V_11 , type , V_19 -> V_24 , ! ! V_22 ) ;
F_10 ( V_11 ) ;
}
if ( V_2 -> V_16 & ( 1 << V_13 ) )
V_14 ++ ;
}
}
static T_2 F_11 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
F_8 ( V_2 ) ;
return V_27 ;
}
static void F_12 ( struct V_28 * V_29 )
{
struct V_1 * V_2 =
F_13 ( V_29 , struct V_1 , V_30 . V_29 ) ;
F_8 ( V_2 ) ;
F_14 ( & V_2 -> V_30 , F_15 ( 100 ) ) ;
}
static int F_16 ( struct V_10 * V_7 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
F_8 ( V_2 ) ;
if ( V_2 -> V_31 )
F_14 ( & V_2 -> V_30 , F_15 ( 100 ) ) ;
else
F_18 ( V_2 -> V_32 ) ;
return 0 ;
}
static void F_19 ( struct V_10 * V_7 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
if ( V_2 -> V_31 )
F_20 ( & V_2 -> V_30 ) ;
else
F_21 ( V_2 -> V_32 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int error ;
error = F_5 ( V_2 , V_33 , & V_2 -> V_34 ) ;
if ( error )
return error ;
error = F_5 ( V_2 , V_35 , & V_2 -> V_36 ) ;
if ( error )
return error ;
error = F_1 ( V_2 , V_35 ,
V_2 -> V_36 | V_2 -> V_16 ) ;
if ( error )
return error ;
error = F_5 ( V_2 , V_35 , & V_2 -> V_36 ) ;
if ( error )
return error ;
error = F_5 ( V_2 , V_15 , & V_2 -> V_17 ) ;
if ( error )
return error ;
V_2 -> V_17 &= V_2 -> V_16 ;
return 0 ;
}
static int F_23 ( struct V_37 * V_6 ,
const struct V_38 * V_39 )
{
struct V_40 * V_41 ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
int error ;
int V_13 ;
if ( ! F_24 ( V_6 -> V_42 , V_43 ) ) {
F_4 ( & V_6 -> V_7 , L_3 ,
F_25 ( & V_6 -> V_42 -> V_7 ) ) ;
return - V_44 ;
}
V_41 = V_6 -> V_7 . V_45 ;
if ( ! V_41 ) {
F_26 ( & V_6 -> V_7 , L_4 ) ;
return - V_46 ;
}
V_2 = F_27 ( sizeof( struct V_1 ) +
V_41 -> V_47 * sizeof( struct V_18 ) ,
V_48 ) ;
V_11 = F_28 () ;
if ( ! V_2 || ! V_11 ) {
error = - V_49 ;
goto V_50;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_5 = V_39 -> V_51 ;
V_2 -> V_16 = V_41 -> V_16 ;
V_2 -> V_31 = V_41 -> V_31 ;
F_29 ( & V_2 -> V_30 , F_12 ) ;
V_11 -> V_52 = L_5 ;
V_11 -> V_53 = V_6 -> V_53 ;
V_11 -> V_7 . V_54 = & V_6 -> V_7 ;
V_11 -> V_55 = F_16 ;
V_11 -> V_56 = F_19 ;
V_11 -> V_39 . V_57 = V_58 ;
V_11 -> V_39 . V_59 = 0x0001 ;
V_11 -> V_39 . V_60 = 0x0001 ;
V_11 -> V_39 . V_61 = 0x0100 ;
if ( V_41 -> V_62 )
F_30 ( V_63 , V_11 -> V_64 ) ;
for ( V_13 = 0 ; V_13 < V_41 -> V_47 ; V_13 ++ ) {
unsigned int type ;
V_2 -> V_20 [ V_13 ] = V_41 -> V_20 [ V_13 ] ;
type = ( V_41 -> V_20 [ V_13 ] . type ) ? : V_21 ;
F_31 ( V_11 , type , V_41 -> V_20 [ V_13 ] . V_24 ) ;
}
F_32 ( V_11 , V_2 ) ;
error = F_22 ( V_2 ) ;
if ( error )
goto V_50;
if ( ! V_2 -> V_31 ) {
if ( V_41 -> V_65 )
V_2 -> V_32 = F_33 ( V_6 -> V_25 ) ;
else
V_2 -> V_32 = V_6 -> V_25 ;
error = F_34 ( V_2 -> V_32 , NULL ,
F_11 ,
V_66 |
V_67 ,
L_6 , V_2 ) ;
if ( error ) {
F_26 ( & V_6 -> V_7 ,
L_7 ,
V_2 -> V_32 , error ) ;
goto V_50;
}
F_21 ( V_2 -> V_32 ) ;
}
error = F_35 ( V_11 ) ;
if ( error ) {
F_26 ( & V_6 -> V_7 ,
L_8 , error ) ;
goto V_68;
}
F_36 ( V_6 , V_2 ) ;
F_37 ( & V_6 -> V_7 , 1 ) ;
return 0 ;
V_68:
if ( ! V_2 -> V_31 ) {
F_38 ( V_2 -> V_32 , V_2 ) ;
F_18 ( V_2 -> V_32 ) ;
}
V_50:
F_39 ( V_11 ) ;
F_40 ( V_2 ) ;
return error ;
}
static int F_41 ( struct V_37 * V_6 )
{
struct V_1 * V_2 = F_42 ( V_6 ) ;
if ( ! V_2 -> V_31 ) {
F_38 ( V_2 -> V_32 , V_2 ) ;
F_18 ( V_2 -> V_32 ) ;
}
F_43 ( V_2 -> V_11 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_69 * V_7 )
{
struct V_37 * V_6 = F_45 ( V_7 ) ;
struct V_1 * V_2 = F_42 ( V_6 ) ;
if ( F_46 ( V_7 ) )
F_47 ( V_2 -> V_32 ) ;
return 0 ;
}
static int F_48 ( struct V_69 * V_7 )
{
struct V_37 * V_6 = F_45 ( V_7 ) ;
struct V_1 * V_2 = F_42 ( V_6 ) ;
if ( F_46 ( V_7 ) )
F_49 ( V_2 -> V_32 ) ;
return 0 ;
}
static int T_3 F_50 ( void )
{
return F_51 ( & V_70 ) ;
}
static void T_4 F_52 ( void )
{
F_53 ( & V_70 ) ;
}
