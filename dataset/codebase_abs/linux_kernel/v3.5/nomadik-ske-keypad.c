static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 )
{
T_3 V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_6 = F_3 ( V_2 -> V_8 + V_3 ) ;
V_6 &= ~ V_4 ;
V_6 |= V_5 ;
F_4 ( V_6 , V_2 -> V_8 + V_3 ) ;
F_5 ( & V_2 -> V_7 ) ;
}
static int T_4 F_6 ( struct V_1 * V_2 )
{
T_3 V_9 ;
int V_10 = 50 ;
while ( ( F_3 ( V_2 -> V_8 + V_11 ) != 0x00000000 ) && V_10 -- )
F_7 () ;
if ( ! V_10 )
return - V_12 ;
F_2 ( & V_2 -> V_7 ) ;
V_9 = F_3 ( V_2 -> V_8 + V_13 ) ;
V_9 = V_9 & 0xff ;
V_9 |= ( ( V_2 -> V_14 -> V_15 * 32000 ) / 32768 ) << 8 ;
F_4 ( V_9 , V_2 -> V_8 + V_13 ) ;
F_5 ( & V_2 -> V_7 ) ;
F_1 ( V_2 , V_16 , 0x0 , V_17 ) ;
V_9 = ( V_2 -> V_14 -> V_18 - 1 ) << 3 ;
F_1 ( V_2 , V_16 , V_19 , V_9 ) ;
F_1 ( V_2 , V_20 , 0x0 , V_21 | V_22 ) ;
F_1 ( V_2 , V_23 , 0x0 , V_24 ) ;
F_1 ( V_2 , V_16 , 0x0 , V_25 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
T_1 V_28 ;
int V_29 = 0 , V_30 = 0 , V_31 ;
int V_32 , V_33 , V_34 , V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_32 = F_3 ( V_2 -> V_8 + V_37 + ( 4 * V_35 ) ) ;
if ( ! V_32 )
continue;
if ( V_32 & 0xff ) {
V_29 = V_35 * 2 ;
V_28 = V_32 & 0xff ;
} else {
V_29 = ( V_35 * 2 ) + 1 ;
V_28 = ( V_32 & 0xff00 ) >> 8 ;
}
V_30 = F_9 ( V_28 ) ;
V_31 = F_10 ( V_30 , V_29 , V_38 ) ;
V_33 = F_3 ( V_2 -> V_8 + V_11 ) ;
V_34 = V_33 & V_39 ;
F_11 ( V_27 , V_40 , V_41 , V_31 ) ;
F_12 ( V_27 , V_2 -> V_42 [ V_31 ] , V_34 ) ;
F_13 ( V_27 ) ;
}
}
static T_5 F_14 ( int V_43 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
int V_45 = 20 ;
F_1 ( V_2 , V_23 , ~ V_24 , 0x0 ) ;
F_1 ( V_2 , V_20 , 0x0 , V_21 ) ;
while ( ( F_3 ( V_2 -> V_8 + V_16 ) & V_46 ) && -- V_45 )
F_15 ( 5 ) ;
if ( V_45 ) {
F_8 ( V_2 ) ;
}
F_1 ( V_2 , V_23 , 0x0 , V_24 ) ;
return V_47 ;
}
static int T_4 F_16 ( struct V_48 * V_49 )
{
const struct V_50 * V_51 = V_49 -> V_52 . V_53 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
struct V_54 * V_55 ;
int V_43 ;
int error ;
if ( ! V_51 ) {
F_17 ( & V_49 -> V_52 , L_1 ) ;
return - V_12 ;
}
V_43 = F_18 ( V_49 , 0 ) ;
if ( V_43 < 0 ) {
F_17 ( & V_49 -> V_52 , L_2 ) ;
return - V_12 ;
}
V_55 = F_19 ( V_49 , V_56 , 0 ) ;
if ( ! V_55 ) {
F_17 ( & V_49 -> V_52 , L_3 ) ;
return - V_12 ;
}
V_2 = F_20 ( sizeof( struct V_1 ) , V_57 ) ;
V_27 = F_21 () ;
if ( ! V_2 || ! V_27 ) {
F_17 ( & V_49 -> V_52 , L_4 ) ;
error = - V_58 ;
goto V_59;
}
V_2 -> V_43 = V_43 ;
V_2 -> V_14 = V_51 ;
V_2 -> V_27 = V_27 ;
F_22 ( & V_2 -> V_7 ) ;
if ( ! F_23 ( V_55 -> V_60 , F_24 ( V_55 ) , V_49 -> V_61 ) ) {
F_17 ( & V_49 -> V_52 , L_5 ) ;
error = - V_62 ;
goto V_59;
}
V_2 -> V_8 = F_25 ( V_55 -> V_60 , F_24 ( V_55 ) ) ;
if ( ! V_2 -> V_8 ) {
F_17 ( & V_49 -> V_52 , L_6 ) ;
error = - V_63 ;
goto V_64;
}
V_2 -> V_65 = F_26 ( & V_49 -> V_52 , NULL ) ;
if ( F_27 ( V_2 -> V_65 ) ) {
F_17 ( & V_49 -> V_52 , L_7 ) ;
error = F_28 ( V_2 -> V_65 ) ;
goto V_66;
}
V_27 -> V_67 . V_68 = V_69 ;
V_27 -> V_61 = L_8 ;
V_27 -> V_52 . V_70 = & V_49 -> V_52 ;
error = F_29 ( V_51 -> V_71 , NULL ,
V_72 , V_73 ,
V_2 -> V_42 , V_27 ) ;
if ( error ) {
F_17 ( & V_49 -> V_52 , L_9 ) ;
goto V_66;
}
F_30 ( V_27 , V_40 , V_41 ) ;
if ( ! V_51 -> V_74 )
F_31 ( V_75 , V_27 -> V_76 ) ;
F_32 ( V_2 -> V_65 ) ;
if ( V_2 -> V_14 -> V_77 )
V_2 -> V_14 -> V_77 () ;
error = F_6 ( V_2 ) ;
if ( error ) {
F_17 ( & V_49 -> V_52 , L_10 ) ;
goto V_78;
}
error = F_33 ( V_2 -> V_43 , NULL , F_14 ,
V_79 , L_11 , V_2 ) ;
if ( error ) {
F_17 ( & V_49 -> V_52 , L_12 , V_2 -> V_43 ) ;
goto V_78;
}
error = F_34 ( V_27 ) ;
if ( error ) {
F_17 ( & V_49 -> V_52 ,
L_13 , error ) ;
goto V_80;
}
if ( V_51 -> V_81 )
F_35 ( & V_49 -> V_52 , true ) ;
F_36 ( V_49 , V_2 ) ;
return 0 ;
V_80:
F_37 ( V_2 -> V_43 , V_2 ) ;
V_78:
F_38 ( V_2 -> V_65 ) ;
F_39 ( V_2 -> V_65 ) ;
V_66:
F_40 ( V_2 -> V_8 ) ;
V_64:
F_41 ( V_55 -> V_60 , F_24 ( V_55 ) ) ;
V_59:
F_42 ( V_27 ) ;
F_43 ( V_2 ) ;
return error ;
}
static int T_6 F_44 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_45 ( V_49 ) ;
struct V_54 * V_55 = F_19 ( V_49 , V_56 , 0 ) ;
F_37 ( V_2 -> V_43 , V_2 ) ;
F_46 ( V_2 -> V_27 ) ;
F_38 ( V_2 -> V_65 ) ;
F_39 ( V_2 -> V_65 ) ;
if ( V_2 -> V_14 -> exit )
V_2 -> V_14 -> exit () ;
F_40 ( V_2 -> V_8 ) ;
F_41 ( V_55 -> V_60 , F_24 ( V_55 ) ) ;
F_43 ( V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_82 * V_52 )
{
struct V_48 * V_49 = F_48 ( V_52 ) ;
struct V_1 * V_2 = F_45 ( V_49 ) ;
int V_43 = F_18 ( V_49 , 0 ) ;
if ( F_49 ( V_52 ) )
F_50 ( V_43 ) ;
else
F_1 ( V_2 , V_23 , ~ V_24 , 0x0 ) ;
return 0 ;
}
static int F_51 ( struct V_82 * V_52 )
{
struct V_48 * V_49 = F_48 ( V_52 ) ;
struct V_1 * V_2 = F_45 ( V_49 ) ;
int V_43 = F_18 ( V_49 , 0 ) ;
if ( F_49 ( V_52 ) )
F_52 ( V_43 ) ;
else
F_1 ( V_2 , V_23 , 0x0 , V_24 ) ;
return 0 ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_83 , F_16 ) ;
}
static void T_7 F_55 ( void )
{
F_56 ( & V_83 ) ;
}
