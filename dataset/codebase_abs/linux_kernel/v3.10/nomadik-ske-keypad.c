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
int V_10 = V_2 -> V_11 -> V_12 ;
while ( ( F_3 ( V_2 -> V_8 + V_13 ) != 0x00000000 ) && V_10 -- )
F_7 () ;
if ( ! V_10 )
return - V_14 ;
F_2 ( & V_2 -> V_7 ) ;
V_9 = F_3 ( V_2 -> V_8 + V_15 ) ;
V_9 = V_9 & 0xff ;
V_9 |= ( ( V_2 -> V_11 -> V_12 * 32000 ) / 32768 ) << 8 ;
F_4 ( V_9 , V_2 -> V_8 + V_15 ) ;
F_5 ( & V_2 -> V_7 ) ;
F_1 ( V_2 , V_16 , 0x0 , V_17 ) ;
V_9 = ( V_2 -> V_11 -> V_18 - 1 ) << 3 ;
F_1 ( V_2 , V_16 , V_19 , V_9 ) ;
F_1 ( V_2 , V_20 , 0x0 , V_21 | V_22 ) ;
F_1 ( V_2 , V_23 , 0x0 , V_24 ) ;
F_1 ( V_2 , V_16 , 0x0 , V_25 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_26 , int V_27 )
{
int V_28 = 0 , V_29 , V_30 ;
struct V_31 * V_32 = V_2 -> V_32 ;
T_3 V_33 ;
int V_34 ;
int V_35 ;
V_35 = F_9 ( V_26 ) ;
do {
V_30 = F_10 ( V_26 ) ;
V_28 = V_30 ;
V_26 &= ~ ( 1 << V_30 ) ;
V_29 = F_11 ( V_28 , V_27 , V_36 ) ;
V_33 = F_3 ( V_2 -> V_8 + V_13 ) ;
V_34 = V_33 & V_37 ;
F_12 ( V_32 , V_38 , V_39 , V_29 ) ;
F_13 ( V_32 , V_2 -> V_40 [ V_29 ] , V_34 ) ;
F_14 ( V_32 ) ;
V_35 -- ;
} while ( V_35 );
}
static void F_15 ( struct V_1 * V_2 )
{
T_2 V_26 ;
int V_27 = 0 ;
int V_41 , V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_41 = F_3 ( V_2 -> V_8 + V_44 + ( 4 * V_42 ) ) ;
if ( ! V_41 )
continue;
V_26 = V_41 & 0xff ;
if ( V_26 ) {
V_27 = V_42 * 2 ;
F_8 ( V_2 , V_26 , V_27 ) ;
}
V_26 = ( V_41 & 0xff00 ) >> 8 ;
if ( V_26 ) {
V_27 = ( V_42 * 2 ) + 1 ;
F_8 ( V_2 , V_26 , V_27 ) ;
}
}
}
static T_5 F_16 ( int V_45 , void * V_46 )
{
struct V_1 * V_2 = V_46 ;
int V_10 = V_2 -> V_11 -> V_12 ;
F_1 ( V_2 , V_23 , ~ V_24 , 0x0 ) ;
F_1 ( V_2 , V_20 , 0x0 , V_21 ) ;
while ( ( F_3 ( V_2 -> V_8 + V_16 ) & V_47 ) && -- V_10 )
F_7 () ;
F_15 ( V_2 ) ;
while ( ( F_3 ( V_2 -> V_8 + V_13 ) ) && -- V_10 )
F_17 ( V_48 ) ;
F_1 ( V_2 , V_23 , 0x0 , V_24 ) ;
return V_49 ;
}
static int T_4 F_18 ( struct V_50 * V_51 )
{
const struct V_52 * V_53 = V_51 -> V_54 . V_55 ;
struct V_1 * V_2 ;
struct V_31 * V_32 ;
struct V_56 * V_57 ;
int V_45 ;
int error ;
if ( ! V_53 ) {
F_19 ( & V_51 -> V_54 , L_1 ) ;
return - V_14 ;
}
V_45 = F_20 ( V_51 , 0 ) ;
if ( V_45 < 0 ) {
F_19 ( & V_51 -> V_54 , L_2 ) ;
return - V_14 ;
}
V_57 = F_21 ( V_51 , V_58 , 0 ) ;
if ( ! V_57 ) {
F_19 ( & V_51 -> V_54 , L_3 ) ;
return - V_14 ;
}
V_2 = F_22 ( sizeof( struct V_1 ) , V_59 ) ;
V_32 = F_23 () ;
if ( ! V_2 || ! V_32 ) {
F_19 ( & V_51 -> V_54 , L_4 ) ;
error = - V_60 ;
goto V_61;
}
V_2 -> V_45 = V_45 ;
V_2 -> V_11 = V_53 ;
V_2 -> V_32 = V_32 ;
F_24 ( & V_2 -> V_7 ) ;
if ( ! F_25 ( V_57 -> V_62 , F_26 ( V_57 ) , V_51 -> V_63 ) ) {
F_19 ( & V_51 -> V_54 , L_5 ) ;
error = - V_64 ;
goto V_61;
}
V_2 -> V_8 = F_27 ( V_57 -> V_62 , F_26 ( V_57 ) ) ;
if ( ! V_2 -> V_8 ) {
F_19 ( & V_51 -> V_54 , L_6 ) ;
error = - V_65 ;
goto V_66;
}
V_2 -> V_67 = F_28 ( & V_51 -> V_54 , L_7 ) ;
if ( F_29 ( V_2 -> V_67 ) ) {
F_19 ( & V_51 -> V_54 , L_8 ) ;
error = F_30 ( V_2 -> V_67 ) ;
goto V_68;
}
V_2 -> V_69 = F_28 ( & V_51 -> V_54 , NULL ) ;
if ( F_29 ( V_2 -> V_69 ) ) {
F_19 ( & V_51 -> V_54 , L_9 ) ;
error = F_30 ( V_2 -> V_69 ) ;
goto V_70;
}
V_32 -> V_71 . V_72 = V_73 ;
V_32 -> V_63 = L_10 ;
V_32 -> V_54 . V_74 = & V_51 -> V_54 ;
error = F_31 ( V_53 -> V_75 , NULL ,
V_76 , V_77 ,
V_2 -> V_40 , V_32 ) ;
if ( error ) {
F_19 ( & V_51 -> V_54 , L_11 ) ;
goto V_78;
}
F_32 ( V_32 , V_38 , V_39 ) ;
if ( ! V_53 -> V_79 )
F_33 ( V_80 , V_32 -> V_81 ) ;
error = F_34 ( V_2 -> V_67 ) ;
if ( error ) {
F_19 ( & V_51 -> V_54 , L_12 ) ;
goto V_78;
}
error = F_34 ( V_2 -> V_69 ) ;
if ( error ) {
F_19 ( & V_51 -> V_54 , L_13 ) ;
goto V_82;
}
if ( V_2 -> V_11 -> V_83 )
V_2 -> V_11 -> V_83 () ;
error = F_6 ( V_2 ) ;
if ( error ) {
F_19 ( & V_51 -> V_54 , L_14 ) ;
goto V_84;
}
error = F_35 ( V_2 -> V_45 , NULL , F_16 ,
V_85 , L_15 , V_2 ) ;
if ( error ) {
F_19 ( & V_51 -> V_54 , L_16 , V_2 -> V_45 ) ;
goto V_84;
}
error = F_36 ( V_32 ) ;
if ( error ) {
F_19 ( & V_51 -> V_54 ,
L_17 , error ) ;
goto V_86;
}
if ( V_53 -> V_87 )
F_37 ( & V_51 -> V_54 , true ) ;
F_38 ( V_51 , V_2 ) ;
return 0 ;
V_86:
F_39 ( V_2 -> V_45 , V_2 ) ;
V_84:
F_40 ( V_2 -> V_69 ) ;
V_82:
F_40 ( V_2 -> V_67 ) ;
V_78:
F_41 ( V_2 -> V_69 ) ;
V_70:
F_41 ( V_2 -> V_67 ) ;
V_68:
F_42 ( V_2 -> V_8 ) ;
V_66:
F_43 ( V_57 -> V_62 , F_26 ( V_57 ) ) ;
V_61:
F_44 ( V_32 ) ;
F_45 ( V_2 ) ;
return error ;
}
static int F_46 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_47 ( V_51 ) ;
struct V_56 * V_57 = F_21 ( V_51 , V_58 , 0 ) ;
F_39 ( V_2 -> V_45 , V_2 ) ;
F_48 ( V_2 -> V_32 ) ;
F_40 ( V_2 -> V_69 ) ;
F_41 ( V_2 -> V_69 ) ;
if ( V_2 -> V_11 -> exit )
V_2 -> V_11 -> exit () ;
F_42 ( V_2 -> V_8 ) ;
F_43 ( V_57 -> V_62 , F_26 ( V_57 ) ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static int F_49 ( struct V_88 * V_54 )
{
struct V_50 * V_51 = F_50 ( V_54 ) ;
struct V_1 * V_2 = F_47 ( V_51 ) ;
int V_45 = F_20 ( V_51 , 0 ) ;
if ( F_51 ( V_54 ) )
F_52 ( V_45 ) ;
else
F_1 ( V_2 , V_23 , ~ V_24 , 0x0 ) ;
return 0 ;
}
static int F_53 ( struct V_88 * V_54 )
{
struct V_50 * V_51 = F_50 ( V_54 ) ;
struct V_1 * V_2 = F_47 ( V_51 ) ;
int V_45 = F_20 ( V_51 , 0 ) ;
if ( F_51 ( V_54 ) )
F_54 ( V_45 ) ;
else
F_1 ( V_2 , V_23 , 0x0 , V_24 ) ;
return 0 ;
}
