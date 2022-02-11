static int F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 ,
T_2 V_5 )
{
struct V_6 V_7 [ 2 ] = {
{
. V_8 = V_2 -> V_8 ,
. V_9 = 0 ,
. V_5 = 1 ,
. V_4 = & V_3 ,
} ,
{
. V_8 = V_2 -> V_8 ,
. V_9 = V_10 ,
. V_5 = V_5 ,
. V_4 = V_4 ,
}
} ;
if ( F_2 ( V_2 -> V_11 , V_7 , 2 ) != 2 ) {
F_3 ( & V_2 -> V_12 , L_1 ) ;
return - V_13 ;
}
return 0 ;
}
static void F_4 ( struct V_14 * V_15 ,
const struct V_16 * V_16 )
{
int V_17 ;
bool V_18 ;
unsigned int V_19 , V_20 ;
const struct V_21 * V_21 ;
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ ) {
F_5 ( V_15 , V_17 ) ;
V_21 = & V_16 -> V_21 [ V_17 ] ;
V_18 = V_16 -> V_23 & ( 1 << V_17 ) ;
F_6 ( V_15 , V_24 , V_18 ) ;
if ( V_18 ) {
V_19 = V_21 -> V_25 | ( V_21 -> V_26 << 8 ) ;
V_20 = V_21 -> V_27 | ( V_21 -> V_28 << 8 ) ;
F_7 ( V_15 , V_29 , V_19 ) ;
F_7 ( V_15 , V_30 , V_20 ) ;
}
}
F_8 ( V_15 , false ) ;
F_9 ( V_15 ) ;
}
static bool F_10 ( const struct V_31 * V_32 )
{
bool V_33 = false ;
if ( V_32 -> F_10 )
V_33 = V_32 -> F_10 () ;
return V_33 ;
}
static void F_11 ( struct V_34 * V_35 )
{
struct V_31 * V_32 = F_12 ( V_35 , struct V_31 ,
V_36 . V_35 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_16 V_16 ;
int error ;
error = F_1 ( V_2 , V_37 ,
& V_16 , sizeof( V_16 ) ) ;
if ( error ) {
F_3 ( & V_2 -> V_12 ,
L_2 , error ) ;
return;
}
F_4 ( V_32 -> V_15 , & V_16 ) ;
if ( ( V_16 . V_23 & 0xf3 ) || F_10 ( V_32 ) )
F_13 ( & V_32 -> V_36 ,
F_14 ( V_32 -> V_38 ) ) ;
}
static T_3 F_15 ( int V_39 , void * V_40 )
{
struct V_31 * V_32 = V_40 ;
F_13 ( & V_32 -> V_36 , 0 ) ;
return V_41 ;
}
static T_4 F_16 ( struct V_42 * V_12 ,
struct V_43 * V_44 ,
const char * V_4 , T_2 V_45 )
{
struct V_1 * V_2 = F_17 ( V_12 ) ;
struct V_31 * V_32 = F_18 ( V_2 ) ;
unsigned long V_46 ;
int V_47 ;
T_1 V_48 = V_49 ;
if ( F_19 ( V_4 , 10 , & V_46 ) )
return - V_50 ;
if ( V_46 > 1 )
return - V_50 ;
if ( V_46 ) {
V_47 = F_20 ( V_32 -> V_2 , & V_48 , sizeof( V_48 ) ) ;
if ( V_47 != sizeof( V_48 ) )
return - V_13 ;
}
return V_45 ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_51 * V_52 )
{
struct V_42 * V_12 = & V_2 -> V_12 ;
const struct V_53 * V_54 = F_22 ( V_12 ) ;
struct V_31 * V_32 ;
struct V_14 * V_15 ;
struct V_55 V_56 ;
struct V_57 V_58 ;
int V_59 , V_60 ;
int error ;
F_23 ( V_12 , L_3 ) ;
if ( ! V_54 ) {
F_3 ( V_12 , L_4 ) ;
return - V_50 ;
}
if ( V_2 -> V_39 <= 0 ) {
F_3 ( V_12 , L_5 ) ;
return - V_50 ;
}
error = F_1 ( V_2 , V_61 ,
& V_58 , sizeof( V_58 ) ) ;
if ( error ) {
F_3 ( V_12 , L_6 ,
error ) ;
return error ;
}
error = F_1 ( V_2 , V_62 , & V_56 , sizeof( V_56 ) ) ;
if ( error ) {
F_3 ( V_12 , L_7 ,
error ) ;
return error ;
}
V_59 = V_56 . V_63 . V_25 | ( V_56 . V_63 . V_26 << 8 ) ;
V_60 = V_56 . V_63 . V_27 | ( V_56 . V_63 . V_28 << 8 ) ;
V_32 = F_24 ( sizeof( * V_32 ) , V_64 ) ;
V_15 = F_25 () ;
if ( ! V_32 || ! V_15 ) {
error = - V_65 ;
goto V_66;
}
V_32 -> V_2 = V_2 ;
V_32 -> V_15 = V_15 ;
V_32 -> F_10 = V_54 -> F_10 ;
V_32 -> V_38 = V_54 -> V_38 ? : V_67 ;
F_26 ( & V_32 -> V_36 , F_11 ) ;
V_15 -> V_68 = L_8 ;
V_15 -> V_52 . V_69 = V_70 ;
V_15 -> V_12 . V_71 = V_12 ;
F_27 ( V_72 , V_15 -> V_73 ) ;
F_27 ( V_74 , V_15 -> V_73 ) ;
F_27 ( V_75 , V_15 -> V_73 ) ;
F_27 ( V_76 , V_15 -> V_77 ) ;
F_28 ( V_15 , V_78 , 0 , V_59 , 0 , 0 ) ;
F_28 ( V_15 , V_79 , 0 , V_60 , 0 , 0 ) ;
F_29 ( V_15 , V_22 , 0 ) ;
F_28 ( V_15 , V_29 , 0 , V_59 , 0 , 0 ) ;
F_28 ( V_15 , V_30 , 0 , V_60 , 0 , 0 ) ;
F_30 ( V_15 , V_32 ) ;
F_31 ( V_2 , V_32 ) ;
error = F_32 ( V_2 -> V_39 , F_15 , V_54 -> V_80 ,
V_2 -> V_68 , V_32 ) ;
if ( error ) {
F_3 ( V_12 , L_9 ,
error ) ;
goto V_66;
}
error = F_33 ( & V_12 -> V_81 , & V_82 ) ;
if ( error ) {
F_3 ( V_12 , L_10 ,
error ) ;
goto V_83;
}
error = F_34 ( V_32 -> V_15 ) ;
if ( error ) {
F_3 ( V_12 , L_11 , error ) ;
goto V_84;
}
F_35 ( & V_2 -> V_12 , 1 ) ;
F_23 ( V_12 ,
L_12 ,
V_2 -> V_39 , V_58 . V_52 , V_58 . V_85 , V_58 . V_86 ) ;
return 0 ;
V_84:
F_36 ( & V_12 -> V_81 , & V_82 ) ;
V_83:
F_37 ( V_2 -> V_39 , V_32 ) ;
V_66:
F_38 ( V_15 ) ;
F_39 ( V_32 ) ;
return error ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_18 ( V_2 ) ;
F_36 ( & V_2 -> V_12 . V_81 , & V_82 ) ;
F_37 ( V_32 -> V_2 -> V_39 , V_32 ) ;
F_41 ( & V_32 -> V_36 ) ;
F_42 ( V_32 -> V_15 ) ;
F_39 ( V_32 ) ;
return 0 ;
}
static int F_43 ( struct V_42 * V_12 )
{
struct V_1 * V_2 = F_17 ( V_12 ) ;
if ( F_44 ( & V_2 -> V_12 ) )
F_45 ( V_2 -> V_39 ) ;
return 0 ;
}
static int F_46 ( struct V_42 * V_12 )
{
struct V_1 * V_2 = F_17 ( V_12 ) ;
if ( F_44 ( & V_2 -> V_12 ) )
F_47 ( V_2 -> V_39 ) ;
return 0 ;
}
