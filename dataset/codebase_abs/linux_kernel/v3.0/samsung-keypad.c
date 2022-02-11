static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_5 type =
F_3 ( V_4 ) -> V_6 ;
return type == V_7 ;
}
static void F_4 ( struct V_8 * V_9 ,
unsigned int * V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 -> V_2 . V_12 ;
unsigned int V_13 ;
unsigned int V_14 ;
for ( V_13 = 0 ; V_13 < V_9 -> V_15 ; V_13 ++ ) {
if ( F_1 ( V_2 ) ) {
V_14 = V_16 ;
V_14 &= ~ ( 1 << V_13 ) << 8 ;
} else {
V_14 = V_17 ;
V_14 &= ~ ( 1 << V_13 ) ;
}
F_5 ( V_14 , V_9 -> V_18 + V_19 ) ;
F_6 ( 1 ) ;
V_14 = F_7 ( V_9 -> V_18 + V_20 ) ;
V_10 [ V_13 ] = ~ V_14 & ( ( 1 << V_9 -> V_21 ) - 1 ) ;
}
F_5 ( 0 , V_9 -> V_18 + V_19 ) ;
}
static bool F_8 ( struct V_8 * V_9 ,
unsigned int * V_10 )
{
struct V_11 * V_11 = V_9 -> V_11 ;
unsigned int V_22 ;
unsigned int V_23 ;
unsigned int V_24 = 0 ;
unsigned int V_14 ;
unsigned int V_13 , V_25 ;
for ( V_13 = 0 ; V_13 < V_9 -> V_15 ; V_13 ++ ) {
V_22 = V_10 [ V_13 ] ^ V_9 -> V_10 [ V_13 ] ;
V_24 |= V_10 [ V_13 ] ;
if ( ! V_22 )
continue;
for ( V_25 = 0 ; V_25 < V_9 -> V_21 ; V_25 ++ ) {
if ( ! ( V_22 & ( 1 << V_25 ) ) )
continue;
V_23 = V_10 [ V_13 ] & ( 1 << V_25 ) ;
F_9 ( & V_9 -> V_11 -> V_2 ,
L_1 ,
V_23 ? L_2 : L_3 , V_25 , V_13 ) ;
V_14 = F_10 ( V_25 , V_13 , V_9 -> V_26 ) ;
F_11 ( V_11 , V_27 , V_28 , V_14 ) ;
F_12 ( V_11 ,
V_9 -> V_29 [ V_14 ] , V_23 ) ;
}
F_13 ( V_9 -> V_11 ) ;
}
memcpy ( V_9 -> V_10 , V_10 , sizeof( V_9 -> V_10 ) ) ;
return V_24 ;
}
static T_1 F_14 ( int V_30 , void * V_31 )
{
struct V_8 * V_9 = V_31 ;
unsigned int V_10 [ V_32 ] ;
unsigned int V_14 ;
bool V_24 ;
do {
V_14 = F_7 ( V_9 -> V_18 + V_33 ) ;
F_5 ( ~ 0x0 , V_9 -> V_18 + V_33 ) ;
F_4 ( V_9 , V_10 ) ;
V_24 = F_8 ( V_9 , V_10 ) ;
if ( V_24 )
F_15 ( V_9 -> V_34 , V_9 -> V_35 ,
F_16 ( 50 ) ) ;
} while ( V_24 && ! V_9 -> V_35 );
return V_36 ;
}
static void F_17 ( struct V_8 * V_9 )
{
unsigned int V_14 ;
V_9 -> V_35 = false ;
F_18 ( V_9 -> V_37 ) ;
V_14 = F_7 ( V_9 -> V_18 + V_38 ) ;
V_14 |= V_39 | V_40 ;
F_5 ( V_14 , V_9 -> V_18 + V_38 ) ;
F_5 ( 0 , V_9 -> V_18 + V_19 ) ;
}
static void F_19 ( struct V_8 * V_9 )
{
unsigned int V_14 ;
V_9 -> V_35 = true ;
F_20 ( & V_9 -> V_34 ) ;
F_21 ( V_9 -> V_30 ) ;
F_5 ( ~ 0x0 , V_9 -> V_18 + V_33 ) ;
V_14 = F_7 ( V_9 -> V_18 + V_38 ) ;
V_14 &= ~ ( V_39 | V_40 ) ;
F_5 ( V_14 , V_9 -> V_18 + V_38 ) ;
F_22 ( V_9 -> V_37 ) ;
F_23 ( V_9 -> V_30 ) ;
}
static int F_24 ( struct V_11 * V_11 )
{
struct V_8 * V_9 = F_25 ( V_11 ) ;
F_17 ( V_9 ) ;
return 0 ;
}
static void F_26 ( struct V_11 * V_11 )
{
struct V_8 * V_9 = F_25 ( V_11 ) ;
F_19 ( V_9 ) ;
}
static int T_2 F_27 ( struct V_3 * V_4 )
{
const struct V_41 * V_42 ;
const struct V_43 * V_44 ;
struct V_8 * V_9 ;
struct V_45 * V_46 ;
struct V_11 * V_11 ;
unsigned int V_26 ;
unsigned int V_47 ;
int error ;
V_42 = V_4 -> V_2 . V_48 ;
if ( ! V_42 ) {
F_28 ( & V_4 -> V_2 , L_4 ) ;
return - V_49 ;
}
V_44 = V_42 -> V_44 ;
if ( ! V_44 ) {
F_28 ( & V_4 -> V_2 , L_5 ) ;
return - V_49 ;
}
if ( ! V_42 -> V_21 || V_42 -> V_21 > V_50 )
return - V_49 ;
if ( ! V_42 -> V_15 || V_42 -> V_15 > V_32 )
return - V_49 ;
if ( V_42 -> V_51 )
V_42 -> V_51 ( V_42 -> V_21 , V_42 -> V_15 ) ;
V_26 = F_29 ( V_42 -> V_15 ) ;
V_47 = ( V_42 -> V_21 << V_26 ) * sizeof( V_9 -> V_29 [ 0 ] ) ;
V_9 = F_30 ( sizeof( * V_9 ) + V_47 , V_52 ) ;
V_11 = F_31 () ;
if ( ! V_9 || ! V_11 ) {
error = - V_53 ;
goto V_54;
}
V_46 = F_32 ( V_4 , V_55 , 0 ) ;
if ( ! V_46 ) {
error = - V_56 ;
goto V_54;
}
V_9 -> V_18 = F_33 ( V_46 -> V_57 , F_34 ( V_46 ) ) ;
if ( ! V_9 -> V_18 ) {
error = - V_58 ;
goto V_54;
}
V_9 -> V_37 = F_35 ( & V_4 -> V_2 , L_6 ) ;
if ( F_36 ( V_9 -> V_37 ) ) {
F_28 ( & V_4 -> V_2 , L_7 ) ;
error = F_37 ( V_9 -> V_37 ) ;
goto V_59;
}
V_9 -> V_11 = V_11 ;
V_9 -> V_26 = V_26 ;
V_9 -> V_21 = V_42 -> V_21 ;
V_9 -> V_15 = V_42 -> V_15 ;
F_38 ( & V_9 -> V_34 ) ;
V_11 -> V_60 = V_4 -> V_60 ;
V_11 -> V_61 . V_62 = V_63 ;
V_11 -> V_2 . V_12 = & V_4 -> V_2 ;
F_39 ( V_11 , V_9 ) ;
V_11 -> V_64 = F_24 ;
V_11 -> V_65 = F_26 ;
V_11 -> V_66 [ 0 ] = F_40 ( V_67 ) ;
if ( ! V_42 -> V_68 )
V_11 -> V_66 [ 0 ] |= F_40 ( V_69 ) ;
F_41 ( V_11 , V_27 , V_28 ) ;
V_11 -> V_70 = V_9 -> V_29 ;
V_11 -> V_71 = sizeof( V_9 -> V_29 [ 0 ] ) ;
V_11 -> V_72 = V_42 -> V_21 << V_26 ;
F_42 ( V_44 , V_26 ,
V_11 -> V_70 , V_11 -> V_73 ) ;
V_9 -> V_30 = F_43 ( V_4 , 0 ) ;
if ( V_9 -> V_30 < 0 ) {
error = V_9 -> V_30 ;
goto V_74;
}
error = F_44 ( V_9 -> V_30 , NULL , F_14 ,
V_75 , F_45 ( & V_4 -> V_2 ) , V_9 ) ;
if ( error ) {
F_28 ( & V_4 -> V_2 , L_8 ) ;
goto V_74;
}
error = F_46 ( V_9 -> V_11 ) ;
if ( error )
goto V_76;
F_47 ( & V_4 -> V_2 , V_42 -> V_77 ) ;
F_48 ( V_4 , V_9 ) ;
return 0 ;
V_76:
F_49 ( V_9 -> V_30 , V_9 ) ;
V_74:
F_50 ( V_9 -> V_37 ) ;
V_59:
F_51 ( V_9 -> V_18 ) ;
V_54:
F_52 ( V_11 ) ;
F_53 ( V_9 ) ;
return error ;
}
static int T_3 F_54 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = F_55 ( V_4 ) ;
F_47 ( & V_4 -> V_2 , 0 ) ;
F_48 ( V_4 , NULL ) ;
F_56 ( V_9 -> V_11 ) ;
F_49 ( V_9 -> V_30 , V_9 ) ;
F_50 ( V_9 -> V_37 ) ;
F_51 ( V_9 -> V_18 ) ;
F_53 ( V_9 ) ;
return 0 ;
}
static void F_57 ( struct V_8 * V_9 ,
bool V_78 )
{
struct V_1 * V_2 = V_9 -> V_11 -> V_2 . V_12 ;
unsigned int V_14 ;
F_18 ( V_9 -> V_37 ) ;
V_14 = F_7 ( V_9 -> V_18 + V_38 ) ;
if ( V_78 ) {
V_14 |= V_79 ;
if ( F_58 ( V_2 ) )
F_59 ( V_9 -> V_30 ) ;
} else {
V_14 &= ~ V_79 ;
if ( F_58 ( V_2 ) )
F_60 ( V_9 -> V_30 ) ;
}
F_5 ( V_14 , V_9 -> V_18 + V_38 ) ;
F_22 ( V_9 -> V_37 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_55 ( V_4 ) ;
struct V_11 * V_11 = V_9 -> V_11 ;
F_62 ( & V_11 -> V_80 ) ;
if ( V_11 -> V_81 )
F_19 ( V_9 ) ;
F_57 ( V_9 , true ) ;
F_63 ( & V_11 -> V_80 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_55 ( V_4 ) ;
struct V_11 * V_11 = V_9 -> V_11 ;
F_62 ( & V_11 -> V_80 ) ;
F_57 ( V_9 , false ) ;
if ( V_11 -> V_81 )
F_17 ( V_9 ) ;
F_63 ( & V_11 -> V_80 ) ;
return 0 ;
}
static int T_4 F_65 ( void )
{
return F_66 ( & V_82 ) ;
}
static void T_5 F_67 ( void )
{
F_68 ( & V_82 ) ;
}
