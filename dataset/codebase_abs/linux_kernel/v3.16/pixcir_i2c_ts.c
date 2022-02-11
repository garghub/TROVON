static void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = V_2 ;
T_1 V_4 [ 10 ] , V_5 [ 1 ] = { 0 } ;
T_1 V_6 ;
int V_7 ;
V_7 = F_2 ( V_3 -> V_8 , V_5 , sizeof( V_5 ) ) ;
if ( V_7 != sizeof( V_5 ) ) {
F_3 ( & V_3 -> V_8 -> V_9 ,
L_1 ,
V_10 , V_7 ) ;
return;
}
V_7 = F_4 ( V_3 -> V_8 , V_4 , sizeof( V_4 ) ) ;
if ( V_7 != sizeof( V_4 ) ) {
F_3 ( & V_3 -> V_8 -> V_9 ,
L_2 ,
V_10 , V_7 ) ;
return;
}
V_6 = V_4 [ 0 ] ;
if ( V_6 ) {
T_2 V_11 = ( V_4 [ 3 ] << 8 ) | V_4 [ 2 ] ;
T_2 V_12 = ( V_4 [ 5 ] << 8 ) | V_4 [ 4 ] ;
T_2 V_13 = ( V_4 [ 7 ] << 8 ) | V_4 [ 6 ] ;
T_2 V_14 = ( V_4 [ 9 ] << 8 ) | V_4 [ 8 ] ;
F_5 ( V_3 -> V_15 , V_16 , 1 ) ;
F_6 ( V_3 -> V_15 , V_17 , V_11 ) ;
F_6 ( V_3 -> V_15 , V_18 , V_12 ) ;
F_6 ( V_3 -> V_15 , V_19 , V_11 ) ;
F_6 ( V_3 -> V_15 , V_20 , V_12 ) ;
F_7 ( V_3 -> V_15 ) ;
if ( V_6 == 2 ) {
F_6 ( V_3 -> V_15 ,
V_19 , V_13 ) ;
F_6 ( V_3 -> V_15 ,
V_20 , V_14 ) ;
F_7 ( V_3 -> V_15 ) ;
}
} else {
F_5 ( V_3 -> V_15 , V_16 , 0 ) ;
}
F_8 ( V_3 -> V_15 ) ;
}
static T_3 F_9 ( int V_21 , void * V_22 )
{
struct V_1 * V_3 = V_22 ;
const struct V_23 * V_24 = V_3 -> V_25 ;
while ( V_3 -> V_26 ) {
F_1 ( V_3 ) ;
if ( F_10 ( V_24 -> V_27 ) )
break;
F_11 ( 20 ) ;
}
return V_28 ;
}
static int F_12 ( struct V_1 * V_29 ,
enum V_30 V_31 )
{
struct V_32 * V_9 = & V_29 -> V_8 -> V_9 ;
int V_7 ;
V_7 = F_13 ( V_29 -> V_8 , V_33 ) ;
if ( V_7 < 0 ) {
F_3 ( V_9 , L_3 ,
V_10 , V_33 , V_7 ) ;
return V_7 ;
}
V_7 &= ~ V_34 ;
V_7 |= V_31 ;
V_7 |= V_35 ;
V_7 = F_14 ( V_29 -> V_8 , V_33 , V_7 ) ;
if ( V_7 < 0 ) {
F_3 ( V_9 , L_4 ,
V_10 , V_33 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_29 ,
enum V_36 V_31 , bool V_37 )
{
struct V_32 * V_9 = & V_29 -> V_8 -> V_9 ;
int V_7 ;
V_7 = F_13 ( V_29 -> V_8 , V_38 ) ;
if ( V_7 < 0 ) {
F_3 ( V_9 , L_3 ,
V_10 , V_38 , V_7 ) ;
return V_7 ;
}
V_7 &= ~ V_39 ;
V_7 |= V_31 ;
if ( V_37 )
V_7 |= V_40 ;
else
V_7 &= ~ V_40 ;
V_7 = F_14 ( V_29 -> V_8 , V_38 , V_7 ) ;
if ( V_7 < 0 ) {
F_3 ( V_9 , L_4 ,
V_10 , V_38 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_29 , bool V_41 )
{
struct V_32 * V_9 = & V_29 -> V_8 -> V_9 ;
int V_7 ;
V_7 = F_13 ( V_29 -> V_8 , V_38 ) ;
if ( V_7 < 0 ) {
F_3 ( V_9 , L_3 ,
V_10 , V_38 , V_7 ) ;
return V_7 ;
}
if ( V_41 )
V_7 |= V_42 ;
else
V_7 &= ~ V_42 ;
V_7 = F_14 ( V_29 -> V_8 , V_38 , V_7 ) ;
if ( V_7 < 0 ) {
F_3 ( V_9 , L_4 ,
V_10 , V_38 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_29 )
{
struct V_32 * V_9 = & V_29 -> V_8 -> V_9 ;
int error ;
error = F_15 ( V_29 , V_43 , 0 ) ;
if ( error ) {
F_3 ( V_9 , L_5 , error ) ;
return error ;
}
V_29 -> V_26 = true ;
F_18 () ;
error = F_16 ( V_29 , true ) ;
if ( error ) {
F_3 ( V_9 , L_6 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_29 )
{
int error ;
error = F_16 ( V_29 , false ) ;
if ( error ) {
F_3 ( & V_29 -> V_8 -> V_9 ,
L_7 ,
error ) ;
return error ;
}
V_29 -> V_26 = false ;
F_18 () ;
F_20 ( V_29 -> V_8 -> V_21 ) ;
return 0 ;
}
static int F_21 ( struct V_44 * V_9 )
{
struct V_1 * V_29 = F_22 ( V_9 ) ;
return F_17 ( V_29 ) ;
}
static void F_23 ( struct V_44 * V_9 )
{
struct V_1 * V_29 = F_22 ( V_9 ) ;
F_19 ( V_29 ) ;
}
static int F_24 ( struct V_32 * V_9 )
{
struct V_45 * V_8 = F_25 ( V_9 ) ;
struct V_1 * V_29 = F_26 ( V_8 ) ;
struct V_44 * V_15 = V_29 -> V_15 ;
int V_7 = 0 ;
F_27 ( & V_15 -> V_46 ) ;
if ( F_28 ( & V_8 -> V_9 ) ) {
if ( ! V_15 -> V_47 ) {
V_7 = F_17 ( V_29 ) ;
if ( V_7 ) {
F_3 ( V_9 , L_8 ) ;
goto V_48;
}
}
F_29 ( V_8 -> V_21 ) ;
} else if ( V_15 -> V_47 ) {
V_7 = F_19 ( V_29 ) ;
}
V_48:
F_30 ( & V_15 -> V_46 ) ;
return V_7 ;
}
static int F_31 ( struct V_32 * V_9 )
{
struct V_45 * V_8 = F_25 ( V_9 ) ;
struct V_1 * V_29 = F_26 ( V_8 ) ;
struct V_44 * V_15 = V_29 -> V_15 ;
int V_7 = 0 ;
F_27 ( & V_15 -> V_46 ) ;
if ( F_28 ( & V_8 -> V_9 ) ) {
F_32 ( V_8 -> V_21 ) ;
if ( ! V_15 -> V_47 ) {
V_7 = F_19 ( V_29 ) ;
if ( V_7 ) {
F_3 ( V_9 , L_9 ) ;
goto V_48;
}
}
} else if ( V_15 -> V_47 ) {
V_7 = F_17 ( V_29 ) ;
}
V_48:
F_30 ( & V_15 -> V_46 ) ;
return V_7 ;
}
static int F_33 ( struct V_45 * V_8 ,
const struct V_49 * V_50 )
{
const struct V_23 * V_24 =
F_34 ( & V_8 -> V_9 ) ;
struct V_32 * V_9 = & V_8 -> V_9 ;
struct V_1 * V_3 ;
struct V_44 * V_15 ;
int error ;
if ( ! V_24 ) {
F_3 ( & V_8 -> V_9 , L_10 ) ;
return - V_51 ;
}
if ( ! F_35 ( V_24 -> V_27 ) ) {
F_3 ( V_9 , L_11 ) ;
return - V_51 ;
}
V_3 = F_36 ( V_9 , sizeof( * V_3 ) , V_52 ) ;
if ( ! V_3 )
return - V_53 ;
V_15 = F_37 ( V_9 ) ;
if ( ! V_15 ) {
F_3 ( V_9 , L_12 ) ;
return - V_53 ;
}
V_3 -> V_8 = V_8 ;
V_3 -> V_15 = V_15 ;
V_3 -> V_25 = V_24 ;
V_15 -> V_54 = V_8 -> V_54 ;
V_15 -> V_50 . V_55 = V_56 ;
V_15 -> V_57 = F_21 ;
V_15 -> V_58 = F_23 ;
V_15 -> V_9 . V_59 = & V_8 -> V_9 ;
F_38 ( V_60 , V_15 -> V_61 ) ;
F_38 ( V_62 , V_15 -> V_61 ) ;
F_38 ( V_16 , V_15 -> V_63 ) ;
F_39 ( V_15 , V_17 , 0 , V_24 -> V_64 , 0 , 0 ) ;
F_39 ( V_15 , V_18 , 0 , V_24 -> V_65 , 0 , 0 ) ;
F_39 ( V_15 , V_19 , 0 , V_24 -> V_64 , 0 , 0 ) ;
F_39 ( V_15 , V_20 , 0 , V_24 -> V_65 , 0 , 0 ) ;
F_40 ( V_15 , V_3 ) ;
error = F_41 ( V_9 , V_24 -> V_27 ,
V_66 , L_13 ) ;
if ( error ) {
F_3 ( V_9 , L_14 ) ;
return error ;
}
error = F_42 ( V_9 , V_8 -> V_21 , NULL , F_9 ,
V_67 | V_68 ,
V_8 -> V_54 , V_3 ) ;
if ( error ) {
F_3 ( V_9 , L_15 , V_8 -> V_21 ) ;
return error ;
}
error = F_12 ( V_3 , V_69 ) ;
if ( error ) {
F_3 ( V_9 , L_16 ) ;
return error ;
}
error = F_19 ( V_3 ) ;
if ( error )
return error ;
error = F_43 ( V_15 ) ;
if ( error )
return error ;
F_44 ( V_8 , V_3 ) ;
F_45 ( & V_8 -> V_9 , 1 ) ;
return 0 ;
}
static int F_46 ( struct V_45 * V_8 )
{
F_45 ( & V_8 -> V_9 , 0 ) ;
return 0 ;
}
