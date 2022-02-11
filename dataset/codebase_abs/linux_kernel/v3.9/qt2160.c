static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 = V_4 -> V_10 ;
T_1 V_11 , V_12 ;
F_3 ( & V_6 -> V_13 ) ;
V_11 = F_4 ( V_8 , V_14 ) ;
V_12 = F_4 ( V_8 , V_15 ) ;
if ( V_9 != V_16 ) {
V_11 |= ( 1 << V_4 -> V_17 ) ;
V_12 |= ( 1 << V_4 -> V_17 ) ;
} else {
V_11 &= ~ ( 1 << V_4 -> V_17 ) ;
V_12 &= ~ ( 1 << V_4 -> V_17 ) ;
}
F_5 ( V_8 , V_14 , V_11 ) ;
F_5 ( V_8 , V_15 , V_12 ) ;
if ( V_9 != V_16 )
F_5 ( V_8 , V_18 , V_9 ) ;
F_6 ( & V_6 -> V_13 ) ;
}
static void F_7 ( struct V_19 * V_20 ,
enum V_21 V_9 )
{
struct V_3 * V_4 = F_2 ( V_20 , struct V_3 , V_20 ) ;
V_4 -> V_10 = V_9 ;
F_8 ( & V_4 -> V_2 ) ;
}
static int F_9 ( struct V_7 * V_8 ,
T_2 V_22 , T_2 * V_23 , unsigned int V_24 )
{
int error , V_25 = 0 ;
if ( F_10 ( V_8 -> V_26 , V_27 ) ) {
error = F_11 ( V_8 , V_22 + V_25 ) ;
if ( error ) {
F_12 ( & V_8 -> V_28 ,
L_1 , error ) ;
return error ;
}
error = F_13 ( V_8 , V_23 , V_24 ) ;
if ( error != V_24 ) {
F_12 ( & V_8 -> V_28 ,
L_2 , error ) ;
return error ;
}
} else {
while ( V_24 -- ) {
int V_29 ;
error = F_11 ( V_8 , V_22 + V_25 ) ;
if ( error ) {
F_12 ( & V_8 -> V_28 ,
L_1 , error ) ;
return error ;
}
V_29 = F_14 ( V_8 ) ;
if ( V_29 < 0 ) {
F_12 ( & V_8 -> V_28 ,
L_3 , V_29 ) ;
return V_29 ;
}
V_23 [ V_25 ++ ] = V_29 ;
}
}
return 0 ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_30 * V_31 = V_6 -> V_31 ;
T_2 V_32 [ 6 ] ;
T_3 V_33 , V_34 ;
int V_35 , V_36 , V_37 ;
F_16 ( & V_8 -> V_28 , L_4 ) ;
V_35 = F_9 ( V_8 , V_38 , V_32 , 6 ) ;
if ( V_35 ) {
F_12 ( & V_8 -> V_28 ,
L_5 ) ;
return V_35 ;
}
V_33 = V_6 -> V_39 ;
V_6 -> V_39 = V_34 = ( V_32 [ 2 ] << 8 ) | V_32 [ 1 ] ;
V_37 = 0x01 ;
for ( V_36 = 0 ; V_36 < 16 ; ++ V_36 , V_37 <<= 1 ) {
int V_40 = V_34 & V_37 ;
if ( ( V_33 & V_37 ) != V_40 ) {
F_17 ( V_31 , V_6 -> V_41 [ V_36 ] , V_40 ) ;
F_16 ( & V_8 -> V_28 , L_6 ,
V_36 , V_40 ? L_7 : L_8 ) ;
}
}
F_18 ( V_31 ) ;
return 0 ;
}
static T_4 F_19 ( int V_42 , void * V_43 )
{
struct V_5 * V_6 = V_43 ;
unsigned long V_44 ;
F_20 ( & V_6 -> V_45 , V_44 ) ;
F_21 ( V_46 , & V_6 -> V_47 , 0 ) ;
F_22 ( & V_6 -> V_45 , V_44 ) ;
return V_48 ;
}
static void F_23 ( struct V_5 * V_6 )
{
F_24 ( & V_6 -> V_45 ) ;
F_25 ( & V_6 -> V_47 , V_49 ) ;
F_26 ( & V_6 -> V_45 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_47 . V_2 ) ;
F_16 ( & V_6 -> V_8 -> V_28 , L_9 ) ;
F_15 ( V_6 ) ;
F_23 ( V_6 ) ;
}
static int F_4 ( struct V_7 * V_8 , T_2 V_50 )
{
int V_35 ;
V_35 = F_11 ( V_8 , V_50 ) ;
if ( V_35 ) {
F_12 ( & V_8 -> V_28 ,
L_1 , V_35 ) ;
return V_35 ;
}
V_35 = F_14 ( V_8 ) ;
if ( V_35 < 0 ) {
F_12 ( & V_8 -> V_28 ,
L_3 , V_35 ) ;
return V_35 ;
}
return V_35 ;
}
static int F_5 ( struct V_7 * V_8 , T_2 V_50 , T_2 V_29 )
{
int V_35 ;
V_35 = F_28 ( V_8 , V_50 , V_29 ) ;
if ( V_35 < 0 )
F_12 ( & V_8 -> V_28 ,
L_10 , V_35 ) ;
return V_35 ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_35 ;
int V_36 ;
F_30 ( & V_6 -> V_13 ) ;
for ( V_36 = 0 ; V_36 < V_51 ; V_36 ++ ) {
struct V_3 * V_4 = & V_6 -> V_52 [ V_36 ] ;
snprintf ( V_4 -> V_53 , sizeof( V_4 -> V_53 ) , L_11 , V_36 ) ;
V_4 -> V_20 . V_53 = V_4 -> V_53 ;
V_4 -> V_20 . V_54 = F_7 ;
V_4 -> V_20 . V_55 = V_16 ;
V_4 -> V_17 = V_36 ;
V_4 -> V_6 = V_6 ;
F_31 ( & V_4 -> V_2 , F_1 ) ;
V_35 = F_32 ( & V_8 -> V_28 , & V_4 -> V_20 ) ;
if ( V_35 < 0 )
return V_35 ;
}
F_5 ( V_8 , V_14 , 0 ) ;
F_5 ( V_8 , V_15 , 0 ) ;
F_5 ( V_8 , V_18 , 0 ) ;
return 0 ;
}
static void F_33 ( struct V_5 * V_6 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_51 ; V_36 ++ ) {
F_34 ( & V_6 -> V_52 [ V_36 ] . V_20 ) ;
F_35 ( & V_6 -> V_52 [ V_36 ] . V_2 ) ;
}
}
static inline int F_29 ( struct V_5 * V_6 )
{
return 0 ;
}
static inline void F_33 ( struct V_5 * V_6 )
{
}
static bool F_36 ( struct V_7 * V_8 )
{
int V_17 , V_56 , V_57 ;
V_17 = F_4 ( V_8 , V_58 ) ;
if ( V_17 != V_59 ) {
F_12 ( & V_8 -> V_28 , L_12 , V_17 ) ;
return false ;
}
V_56 = F_4 ( V_8 , V_60 ) ;
if ( V_56 < 0 ) {
F_12 ( & V_8 -> V_28 , L_13 ) ;
return false ;
}
V_57 = F_4 ( V_8 , V_61 ) ;
if ( V_57 < 0 ) {
F_12 ( & V_8 -> V_28 , L_14 ) ;
return false ;
}
F_37 ( & V_8 -> V_28 , L_15 ,
V_56 >> 4 , V_56 & 0xf , V_57 ) ;
return true ;
}
static int F_38 ( struct V_7 * V_8 ,
const struct V_62 * V_17 )
{
struct V_5 * V_6 ;
struct V_30 * V_31 ;
int V_36 ;
int error ;
error = F_10 ( V_8 -> V_26 ,
V_63 ) ;
if ( ! error ) {
F_12 ( & V_8 -> V_28 , L_16 ,
F_39 ( & V_8 -> V_26 -> V_28 ) ) ;
return - V_64 ;
}
if ( ! F_36 ( V_8 ) )
return - V_64 ;
V_6 = F_40 ( sizeof( struct V_5 ) , V_65 ) ;
V_31 = F_41 () ;
if ( ! V_6 || ! V_31 ) {
F_12 ( & V_8 -> V_28 , L_17 ) ;
error = - V_66 ;
goto V_67;
}
V_6 -> V_8 = V_8 ;
V_6 -> V_31 = V_31 ;
F_42 ( & V_6 -> V_47 , F_27 ) ;
F_43 ( & V_6 -> V_45 ) ;
V_31 -> V_53 = L_18 ;
V_31 -> V_17 . V_68 = V_69 ;
V_31 -> V_70 = V_6 -> V_41 ;
V_31 -> V_71 = sizeof( V_6 -> V_41 [ 0 ] ) ;
V_31 -> V_72 = F_44 ( V_73 ) ;
F_45 ( V_74 , V_31 -> V_75 ) ;
F_46 ( V_76 , V_31 -> V_75 ) ;
for ( V_36 = 0 ; V_36 < F_44 ( V_73 ) ; V_36 ++ ) {
V_6 -> V_41 [ V_36 ] = V_73 [ V_36 ] ;
F_45 ( V_73 [ V_36 ] , V_31 -> V_77 ) ;
}
F_46 ( V_78 , V_31 -> V_77 ) ;
error = F_5 ( V_8 , V_79 , 1 ) ;
if ( error ) {
F_12 ( & V_8 -> V_28 , L_19 ) ;
goto V_67;
}
if ( V_8 -> V_42 ) {
error = F_47 ( V_8 -> V_42 , F_19 ,
V_80 , L_20 , V_6 ) ;
if ( error ) {
F_12 ( & V_8 -> V_28 ,
L_21 , V_8 -> V_42 ) ;
goto V_67;
}
}
error = F_29 ( V_6 ) ;
if ( error ) {
F_12 ( & V_8 -> V_28 , L_22 ) ;
goto V_81;
}
error = F_48 ( V_6 -> V_31 ) ;
if ( error ) {
F_12 ( & V_8 -> V_28 ,
L_23 ) ;
goto V_82;
}
F_49 ( V_8 , V_6 ) ;
F_23 ( V_6 ) ;
return 0 ;
V_82:
F_33 ( V_6 ) ;
V_81:
if ( V_8 -> V_42 )
F_50 ( V_8 -> V_42 , V_6 ) ;
V_67:
F_51 ( V_31 ) ;
F_52 ( V_6 ) ;
return error ;
}
static int F_53 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = F_54 ( V_8 ) ;
F_33 ( V_6 ) ;
if ( V_8 -> V_42 )
F_50 ( V_8 -> V_42 , V_6 ) ;
F_55 ( & V_6 -> V_47 ) ;
F_56 ( V_6 -> V_31 ) ;
F_52 ( V_6 ) ;
return 0 ;
}
