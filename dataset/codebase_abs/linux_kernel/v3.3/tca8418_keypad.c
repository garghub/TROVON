static int F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
int error ;
error = F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
if ( error < 0 ) {
F_3 ( & V_2 -> V_5 -> V_6 ,
L_1 ,
V_7 , V_3 , V_4 , error ) ;
return error ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_3 , T_1 * V_4 )
{
int error ;
error = F_5 ( V_2 -> V_5 , V_3 ) ;
if ( error < 0 ) {
F_3 ( & V_2 -> V_5 -> V_6 ,
L_2 ,
V_7 , V_3 , error ) ;
return error ;
}
* V_4 = ( T_1 ) error ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
int error , V_8 , V_9 ;
T_1 V_3 , V_10 , V_11 ;
error = F_4 ( V_2 , V_12 , & V_3 ) ;
while ( error >= 0 && V_3 > 0 ) {
V_10 = V_3 & V_13 ;
V_11 = V_3 & V_14 ;
V_9 = V_11 / V_15 ;
V_8 = V_11 % V_15 ;
V_9 = ( V_8 ) ? V_9 : V_9 - 1 ;
V_8 = ( V_8 ) ? V_8 - 1 : V_15 - 1 ;
V_11 = F_7 ( V_9 , V_8 , V_2 -> V_16 ) ;
F_8 ( V_2 -> V_17 , V_18 , V_19 , V_11 ) ;
F_9 ( V_2 -> V_17 ,
V_2 -> V_20 [ V_11 ] , V_10 ) ;
error = F_4 ( V_2 , V_12 , & V_3 ) ;
}
if ( error < 0 )
F_3 ( & V_2 -> V_5 -> V_6 ,
L_3 ) ;
F_10 ( V_2 -> V_17 ) ;
}
static T_2 F_11 ( int V_21 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
T_1 V_3 ;
int error ;
error = F_4 ( V_2 , V_23 , & V_3 ) ;
if ( error ) {
F_3 ( & V_2 -> V_5 -> V_6 ,
L_4 ) ;
goto exit;
}
if ( V_3 & V_24 )
F_12 ( & V_2 -> V_5 -> V_6 , L_5 ) ;
if ( V_3 & V_25 )
F_6 ( V_2 ) ;
exit:
V_3 = 0xff ;
error = F_1 ( V_2 , V_23 , V_3 ) ;
if ( error )
F_3 ( & V_2 -> V_5 -> V_6 ,
L_6 ) ;
return V_26 ;
}
static int T_3 F_13 ( struct V_1 * V_2 )
{
int V_3 , error ;
error = F_1 ( V_2 , V_27 ,
V_28 | V_29 | V_30 ) ;
if ( error < 0 )
return - V_31 ;
V_3 = ~ ( ~ 0 << V_2 -> V_32 ) ;
V_3 += ( ~ ( ~ 0 << V_2 -> V_33 ) ) << 8 ;
V_2 -> V_34 = V_3 ;
error |= F_1 ( V_2 , V_35 , V_3 ) ;
error |= F_1 ( V_2 , V_36 , V_3 >> 8 ) ;
error |= F_1 ( V_2 , V_37 , V_3 >> 16 ) ;
error |= F_1 ( V_2 , V_38 , V_3 ) ;
error |= F_1 ( V_2 , V_39 , V_3 >> 8 ) ;
error |= F_1 ( V_2 , V_40 , V_3 >> 16 ) ;
return error ;
}
static int T_3 F_14 ( struct V_41 * V_5 ,
const struct V_42 * V_43 )
{
const struct V_44 * V_45 =
V_5 -> V_6 . V_46 ;
struct V_1 * V_2 ;
struct V_47 * V_17 ;
int error , V_16 , V_48 ;
if ( ! V_45 ) {
F_15 ( & V_5 -> V_6 , L_7 ) ;
return - V_49 ;
}
if ( ! V_45 -> V_50 ) {
F_3 ( & V_5 -> V_6 , L_8 ) ;
return - V_49 ;
}
if ( ! V_45 -> V_32 || V_45 -> V_32 > V_51 ) {
F_3 ( & V_5 -> V_6 , L_9 ) ;
return - V_49 ;
}
if ( ! V_45 -> V_33 || V_45 -> V_33 > V_15 ) {
F_3 ( & V_5 -> V_6 , L_10 ) ;
return - V_49 ;
}
if ( ! F_16 ( V_5 -> V_52 , V_53 ) ) {
F_3 ( & V_5 -> V_6 , L_11 ,
F_17 ( & V_5 -> V_52 -> V_6 ) ) ;
return - V_31 ;
}
V_16 = F_18 ( V_45 -> V_33 ) ;
V_48 = V_45 -> V_32 << V_16 ;
V_2 = F_19 ( sizeof( * V_2 ) +
V_48 * sizeof( V_2 -> V_20 [ 0 ] ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
V_2 -> V_32 = V_45 -> V_32 ;
V_2 -> V_33 = V_45 -> V_33 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_16 = V_16 ;
error = F_13 ( V_2 ) ;
if ( error < 0 )
goto V_56;
V_17 = F_20 () ;
if ( ! V_17 ) {
error = - V_55 ;
goto V_56;
}
V_2 -> V_17 = V_17 ;
V_17 -> V_57 = V_5 -> V_57 ;
V_17 -> V_6 . V_58 = & V_5 -> V_6 ;
V_17 -> V_43 . V_59 = V_60 ;
V_17 -> V_43 . V_61 = 0x0001 ;
V_17 -> V_43 . V_62 = 0x001 ;
V_17 -> V_43 . V_63 = 0x0001 ;
V_17 -> V_64 = V_2 -> V_20 ;
V_17 -> V_65 = sizeof( V_2 -> V_20 [ 0 ] ) ;
V_17 -> V_66 = V_48 ;
F_21 ( V_67 , V_17 -> V_68 ) ;
if ( V_45 -> V_69 )
F_21 ( V_70 , V_17 -> V_68 ) ;
F_22 ( V_17 , V_18 , V_19 ) ;
F_23 ( V_17 , V_2 ) ;
F_24 ( V_45 -> V_50 , V_16 ,
V_17 -> V_64 , V_17 -> V_71 ) ;
if ( V_45 -> V_72 )
V_5 -> V_21 = F_25 ( V_5 -> V_21 ) ;
error = F_26 ( V_5 -> V_21 , NULL , F_11 ,
V_73 ,
V_5 -> V_57 , V_2 ) ;
if ( error ) {
F_15 ( & V_5 -> V_6 ,
L_12 ,
V_5 -> V_21 , error ) ;
goto V_74;
}
error = F_27 ( V_17 ) ;
if ( error ) {
F_15 ( & V_5 -> V_6 ,
L_13 , error ) ;
goto V_75;
}
F_28 ( V_5 , V_2 ) ;
return 0 ;
V_75:
F_29 ( V_5 -> V_21 , V_2 ) ;
V_74:
F_30 ( V_17 ) ;
V_56:
F_31 ( V_2 ) ;
return error ;
}
static int T_4 F_32 ( struct V_41 * V_5 )
{
struct V_1 * V_2 = F_33 ( V_5 ) ;
F_29 ( V_2 -> V_5 -> V_21 , V_2 ) ;
F_34 ( V_2 -> V_17 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
static int T_5 F_35 ( void )
{
return F_36 ( & V_76 ) ;
}
static void T_6 F_37 ( void )
{
F_38 ( & V_76 ) ;
}
