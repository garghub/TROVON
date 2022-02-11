static int T_1 F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 -> V_3 ;
struct V_5 * V_6 = V_1 -> V_6 ;
T_2 V_7 ;
F_2 ( V_8 ,
V_1 -> V_9 + V_10 ) ;
F_2 ( V_8 ,
V_1 -> V_9 + V_11 ) ;
F_2 ( V_6 -> V_12 ,
V_1 -> V_9 + V_13 ) ;
F_2 ( V_6 -> V_14 ,
V_1 -> V_9 + V_15 ) ;
F_2 ( 0x01 ,
V_1 -> V_9 + V_16 ) ;
switch ( V_6 -> V_17 ) {
case V_18 :
V_7 = 0 ;
break;
case V_19 :
V_7 = ( 1 << 6 ) ;
break;
default:
F_3 ( V_3 -> V_20 , L_1 ) ;
return - V_21 ;
}
F_2 ( V_22 | V_23 |
V_7 , V_1 -> V_9 + V_24 ) ;
return 0 ;
}
static T_3 F_4 ( int V_25 , void * V_26 )
{
struct V_1 * V_1 = V_26 ;
struct V_2 * V_3 = & V_1 -> V_4 -> V_3 ;
unsigned short * V_27 = V_1 -> V_27 ;
int V_28 = V_1 -> V_6 -> V_28 ;
T_2 V_29 , V_30 , V_31 ;
bool V_32 ;
int V_33 = V_34 ;
int V_35 ;
F_2 ( 0x0 , V_1 -> V_9 + V_10 ) ;
V_29 = F_5 ( V_1 -> V_9 + V_36 ) ;
V_30 = F_5 ( V_1 -> V_9 + V_37 ) ;
V_31 = V_29 ^ V_30 ;
if ( V_31 ) {
for ( V_35 = 0 ; V_35 < V_28 ; V_35 ++ ) {
if ( ( V_31 >> V_35 ) & 0x1 ) {
V_33 = V_27 [ V_35 ] ;
V_32 = ( V_30 >> V_35 ) & 0x1 ;
F_6 ( V_3 -> V_20 , L_2 , V_33 ,
V_32 ? L_3 : L_4 ) ;
F_7 ( V_1 -> V_4 , V_33 ,
! V_32 ) ;
F_8 ( V_1 -> V_4 ) ;
}
}
F_2 ( V_8 ,
V_1 -> V_9 + V_11 ) ;
}
F_2 ( 0x1 , V_1 -> V_9 + V_10 ) ;
return V_38 ;
}
static int T_1 F_9 ( struct V_39 * V_40 )
{
struct V_1 * V_1 ;
struct V_41 * V_42 ;
struct V_43 * V_44 , * V_45 ;
struct V_2 * V_3 = & V_40 -> V_3 ;
struct V_5 * V_6 = V_40 -> V_3 . V_46 ;
int error , V_35 ;
if ( V_6 -> V_47 ) {
error = V_6 -> V_47 ( V_3 ) ;
if ( error < 0 ) {
F_6 ( V_3 , L_5 ) ;
return error ;
}
}
if ( ! V_6 -> V_27 ) {
F_6 ( V_3 , L_6 ) ;
return - V_21 ;
}
V_1 = F_10 ( sizeof( struct V_1 ) +
sizeof( unsigned short ) * V_6 -> V_28 , V_48 ) ;
if ( ! V_1 ) {
F_6 ( V_3 , L_7 ) ;
return - V_49 ;
}
memcpy ( V_1 -> V_27 , V_6 -> V_27 ,
sizeof( unsigned short ) * V_6 -> V_28 ) ;
V_42 = F_11 () ;
if ( ! V_42 ) {
F_6 ( V_3 , L_8 ) ;
error = - V_49 ;
goto V_50;
}
V_1 -> V_4 = V_42 ;
V_1 -> V_25 = F_12 ( V_40 , 0 ) ;
if ( V_1 -> V_25 < 0 ) {
F_3 ( V_3 , L_9 ) ;
error = V_1 -> V_25 ;
goto V_51;
}
V_44 = F_13 ( V_40 , V_52 , 0 ) ;
if ( ! V_44 ) {
F_3 ( V_3 , L_10 ) ;
error = - V_21 ;
goto V_51;
}
V_1 -> V_53 = V_44 -> V_54 ;
V_1 -> V_55 = F_14 ( V_44 ) ;
V_45 = F_15 ( V_1 -> V_53 , V_1 -> V_55 ,
V_40 -> V_56 ) ;
if ( ! V_45 ) {
F_3 ( V_3 , L_11 ,
V_1 -> V_53 ) ;
error = - V_57 ;
goto V_51;
}
V_1 -> V_9 = F_16 ( V_1 -> V_53 , V_1 -> V_55 ) ;
if ( ! V_1 -> V_9 ) {
F_3 ( V_3 , L_12 ) ;
error = - V_49 ;
goto V_58;
}
if ( V_6 -> V_59 )
F_17 ( V_60 , V_42 -> V_61 ) ;
F_17 ( V_62 , V_42 -> V_61 ) ;
V_1 -> V_6 = V_6 ;
for ( V_35 = 0 ; V_35 < V_1 -> V_6 -> V_28 ; V_35 ++ )
F_17 ( V_1 -> V_6 -> V_27 [ V_35 ] , V_42 -> V_63 ) ;
V_42 -> V_56 = L_13 ;
V_42 -> V_64 = L_14 ;
V_42 -> V_3 . V_20 = & V_40 -> V_3 ;
V_42 -> V_65 . V_66 = V_67 ;
V_42 -> V_65 . V_68 = 0x0001 ;
V_42 -> V_65 . V_69 = 0x0001 ;
V_42 -> V_65 . V_70 = 0x0001 ;
V_42 -> V_33 = V_1 -> V_27 ;
V_42 -> V_71 = sizeof( V_1 -> V_27 [ 0 ] ) ;
V_42 -> V_72 = V_1 -> V_6 -> V_28 ;
error = F_18 ( V_1 -> V_4 ) ;
if ( error < 0 ) {
F_3 ( V_3 , L_15 ) ;
goto V_73;
}
error = F_19 ( V_1 -> V_25 , F_4 ,
0 , V_40 -> V_56 , V_1 ) ;
if ( error < 0 ) {
F_3 ( V_3 , L_16 ) ;
goto V_74;
}
error = F_1 ( V_1 ) ;
if ( error < 0 ) {
F_3 ( V_3 , L_17 ) ;
goto V_75;
}
F_20 ( V_40 , V_1 ) ;
return 0 ;
V_75:
F_21 ( V_1 -> V_25 , V_1 ) ;
V_74:
F_22 ( V_1 -> V_4 ) ;
V_42 = NULL ;
V_73:
F_23 ( V_1 -> V_9 ) ;
V_58:
F_24 ( V_1 -> V_53 , V_1 -> V_55 ) ;
V_51:
F_25 ( V_42 ) ;
V_50:
F_26 ( V_1 ) ;
return error ;
}
static int T_4 F_27 ( struct V_39 * V_40 )
{
struct V_1 * V_1 = F_28 ( V_40 ) ;
F_21 ( V_1 -> V_25 , V_1 ) ;
F_22 ( V_1 -> V_4 ) ;
F_23 ( V_1 -> V_9 ) ;
F_24 ( V_1 -> V_53 , V_1 -> V_55 ) ;
F_20 ( V_40 , NULL ) ;
F_26 ( V_1 ) ;
return 0 ;
}
static int T_1 F_29 ( void )
{
return F_30 ( & V_76 , F_9 ) ;
}
static void T_5 F_31 ( void )
{
F_32 ( & V_76 ) ;
}
