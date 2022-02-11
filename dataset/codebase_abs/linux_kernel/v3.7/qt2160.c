static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_4 , unsigned int V_5 )
{
int error , V_6 = 0 ;
if ( F_2 ( V_2 -> V_7 , V_8 ) ) {
error = F_3 ( V_2 , V_3 + V_6 ) ;
if ( error ) {
F_4 ( & V_2 -> V_9 ,
L_1 , error ) ;
return error ;
}
error = F_5 ( V_2 , V_4 , V_5 ) ;
if ( error != V_5 ) {
F_4 ( & V_2 -> V_9 ,
L_2 , error ) ;
return error ;
}
} else {
while ( V_5 -- ) {
int V_10 ;
error = F_3 ( V_2 , V_3 + V_6 ) ;
if ( error ) {
F_4 ( & V_2 -> V_9 ,
L_1 , error ) ;
return error ;
}
V_10 = F_6 ( V_2 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_2 -> V_9 ,
L_3 , V_10 ) ;
return V_10 ;
}
V_4 [ V_6 ++ ] = V_10 ;
}
}
return 0 ;
}
static int F_7 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_13 * V_14 = V_12 -> V_14 ;
T_1 V_15 [ 6 ] ;
T_2 V_16 , V_17 ;
int V_18 , V_19 , V_20 ;
F_8 ( & V_2 -> V_9 , L_4 ) ;
V_18 = F_1 ( V_2 , V_21 , V_15 , 6 ) ;
if ( V_18 ) {
F_4 ( & V_2 -> V_9 ,
L_5 ) ;
return V_18 ;
}
V_16 = V_12 -> V_22 ;
V_12 -> V_22 = V_17 = ( V_15 [ 2 ] << 8 ) | V_15 [ 1 ] ;
V_20 = 0x01 ;
for ( V_19 = 0 ; V_19 < 16 ; ++ V_19 , V_20 <<= 1 ) {
int V_23 = V_17 & V_20 ;
if ( ( V_16 & V_20 ) != V_23 ) {
F_9 ( V_14 , V_12 -> V_24 [ V_19 ] , V_23 ) ;
F_8 ( & V_2 -> V_9 , L_6 ,
V_19 , V_23 ? L_7 : L_8 ) ;
}
}
F_10 ( V_14 ) ;
return 0 ;
}
static T_3 F_11 ( int V_25 , void * V_26 )
{
struct V_11 * V_12 = V_26 ;
unsigned long V_27 ;
F_12 ( & V_12 -> V_28 , V_27 ) ;
F_13 ( V_29 , & V_12 -> V_30 , 0 ) ;
F_14 ( & V_12 -> V_28 , V_27 ) ;
return V_31 ;
}
static void F_15 ( struct V_11 * V_12 )
{
F_16 ( & V_12 -> V_28 ) ;
F_17 ( & V_12 -> V_30 , V_32 ) ;
F_18 ( & V_12 -> V_28 ) ;
}
static void F_19 ( struct V_33 * V_34 )
{
struct V_11 * V_12 =
F_20 ( V_34 , struct V_11 , V_30 . V_34 ) ;
F_8 ( & V_12 -> V_2 -> V_9 , L_9 ) ;
F_7 ( V_12 ) ;
F_15 ( V_12 ) ;
}
static int T_4 F_21 ( struct V_1 * V_2 , T_1 V_35 )
{
int V_18 ;
V_18 = F_3 ( V_2 , V_35 ) ;
if ( V_18 ) {
F_4 ( & V_2 -> V_9 ,
L_1 , V_18 ) ;
return V_18 ;
}
V_18 = F_6 ( V_2 ) ;
if ( V_18 < 0 ) {
F_4 ( & V_2 -> V_9 ,
L_3 , V_18 ) ;
return V_18 ;
}
return V_18 ;
}
static int T_4 F_22 ( struct V_1 * V_2 , T_1 V_35 , T_1 V_10 )
{
int error ;
error = F_3 ( V_2 , V_35 ) ;
if ( error ) {
F_4 ( & V_2 -> V_9 ,
L_1 , error ) ;
return error ;
}
error = F_3 ( V_2 , V_10 ) ;
if ( error ) {
F_4 ( & V_2 -> V_9 ,
L_10 , error ) ;
return error ;
}
return error ;
}
static bool T_4 F_23 ( struct V_1 * V_2 )
{
int V_36 , V_37 , V_38 ;
V_36 = F_21 ( V_2 , V_39 ) ;
if ( V_36 != V_40 ) {
F_4 ( & V_2 -> V_9 , L_11 , V_36 ) ;
return false ;
}
V_37 = F_21 ( V_2 , V_41 ) ;
if ( V_37 < 0 ) {
F_4 ( & V_2 -> V_9 , L_12 ) ;
return false ;
}
V_38 = F_21 ( V_2 , V_42 ) ;
if ( V_38 < 0 ) {
F_4 ( & V_2 -> V_9 , L_13 ) ;
return false ;
}
F_24 ( & V_2 -> V_9 , L_14 ,
V_37 >> 4 , V_37 & 0xf , V_38 ) ;
return true ;
}
static int T_4 F_25 ( struct V_1 * V_2 ,
const struct V_43 * V_36 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_19 ;
int error ;
error = F_2 ( V_2 -> V_7 ,
V_44 ) ;
if ( ! error ) {
F_4 ( & V_2 -> V_9 , L_15 ,
F_26 ( & V_2 -> V_7 -> V_9 ) ) ;
return - V_45 ;
}
if ( ! F_23 ( V_2 ) )
return - V_45 ;
V_12 = F_27 ( sizeof( struct V_11 ) , V_46 ) ;
V_14 = F_28 () ;
if ( ! V_12 || ! V_14 ) {
F_4 ( & V_2 -> V_9 , L_16 ) ;
error = - V_47 ;
goto V_48;
}
V_12 -> V_2 = V_2 ;
V_12 -> V_14 = V_14 ;
F_29 ( & V_12 -> V_30 , F_19 ) ;
F_30 ( & V_12 -> V_28 ) ;
V_14 -> V_49 = L_17 ;
V_14 -> V_36 . V_50 = V_51 ;
V_14 -> V_52 = V_12 -> V_24 ;
V_14 -> V_53 = sizeof( V_12 -> V_24 [ 0 ] ) ;
V_14 -> V_54 = F_31 ( V_55 ) ;
F_32 ( V_56 , V_14 -> V_57 ) ;
F_33 ( V_58 , V_14 -> V_57 ) ;
for ( V_19 = 0 ; V_19 < F_31 ( V_55 ) ; V_19 ++ ) {
V_12 -> V_24 [ V_19 ] = V_55 [ V_19 ] ;
F_32 ( V_55 [ V_19 ] , V_14 -> V_59 ) ;
}
F_33 ( V_60 , V_14 -> V_59 ) ;
error = F_22 ( V_2 , V_61 , 1 ) ;
if ( error ) {
F_4 ( & V_2 -> V_9 , L_18 ) ;
goto V_48;
}
if ( V_2 -> V_25 ) {
error = F_34 ( V_2 -> V_25 , F_11 ,
V_62 , L_19 , V_12 ) ;
if ( error ) {
F_4 ( & V_2 -> V_9 ,
L_20 , V_2 -> V_25 ) ;
goto V_48;
}
}
error = F_35 ( V_12 -> V_14 ) ;
if ( error ) {
F_4 ( & V_2 -> V_9 ,
L_21 ) ;
goto V_63;
}
F_36 ( V_2 , V_12 ) ;
F_15 ( V_12 ) ;
return 0 ;
V_63:
if ( V_2 -> V_25 )
F_37 ( V_2 -> V_25 , V_12 ) ;
V_48:
F_38 ( V_14 ) ;
F_39 ( V_12 ) ;
return error ;
}
static int T_5 F_40 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_41 ( V_2 ) ;
if ( V_2 -> V_25 )
F_37 ( V_2 -> V_25 , V_12 ) ;
F_42 ( & V_12 -> V_30 ) ;
F_43 ( V_12 -> V_14 ) ;
F_39 ( V_12 ) ;
return 0 ;
}
