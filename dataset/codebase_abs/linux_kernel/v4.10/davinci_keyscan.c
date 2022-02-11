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
struct V_5 * V_6 = F_10 ( & V_40 -> V_3 ) ;
int error , V_35 ;
if ( V_6 -> V_46 ) {
error = V_6 -> V_46 ( V_3 ) ;
if ( error < 0 ) {
F_6 ( V_3 , L_5 ) ;
return error ;
}
}
if ( ! V_6 -> V_27 ) {
F_6 ( V_3 , L_6 ) ;
return - V_21 ;
}
V_1 = F_11 ( sizeof( struct V_1 ) +
sizeof( unsigned short ) * V_6 -> V_28 , V_47 ) ;
if ( ! V_1 ) {
F_6 ( V_3 , L_7 ) ;
return - V_48 ;
}
memcpy ( V_1 -> V_27 , V_6 -> V_27 ,
sizeof( unsigned short ) * V_6 -> V_28 ) ;
V_42 = F_12 () ;
if ( ! V_42 ) {
F_6 ( V_3 , L_8 ) ;
error = - V_48 ;
goto V_49;
}
V_1 -> V_4 = V_42 ;
V_1 -> V_25 = F_13 ( V_40 , 0 ) ;
if ( V_1 -> V_25 < 0 ) {
F_3 ( V_3 , L_9 ) ;
error = V_1 -> V_25 ;
goto V_50;
}
V_44 = F_14 ( V_40 , V_51 , 0 ) ;
if ( ! V_44 ) {
F_3 ( V_3 , L_10 ) ;
error = - V_21 ;
goto V_50;
}
V_1 -> V_52 = V_44 -> V_53 ;
V_1 -> V_54 = F_15 ( V_44 ) ;
V_45 = F_16 ( V_1 -> V_52 , V_1 -> V_54 ,
V_40 -> V_55 ) ;
if ( ! V_45 ) {
F_3 ( V_3 , L_11 ,
V_1 -> V_52 ) ;
error = - V_56 ;
goto V_50;
}
V_1 -> V_9 = F_17 ( V_1 -> V_52 , V_1 -> V_54 ) ;
if ( ! V_1 -> V_9 ) {
F_3 ( V_3 , L_12 ) ;
error = - V_48 ;
goto V_57;
}
if ( V_6 -> V_58 )
F_18 ( V_59 , V_42 -> V_60 ) ;
F_18 ( V_61 , V_42 -> V_60 ) ;
V_1 -> V_6 = V_6 ;
for ( V_35 = 0 ; V_35 < V_1 -> V_6 -> V_28 ; V_35 ++ )
F_18 ( V_1 -> V_6 -> V_27 [ V_35 ] , V_42 -> V_62 ) ;
V_42 -> V_55 = L_13 ;
V_42 -> V_63 = L_14 ;
V_42 -> V_3 . V_20 = & V_40 -> V_3 ;
V_42 -> V_64 . V_65 = V_66 ;
V_42 -> V_64 . V_67 = 0x0001 ;
V_42 -> V_64 . V_68 = 0x0001 ;
V_42 -> V_64 . V_69 = 0x0001 ;
V_42 -> V_33 = V_1 -> V_27 ;
V_42 -> V_70 = sizeof( V_1 -> V_27 [ 0 ] ) ;
V_42 -> V_71 = V_1 -> V_6 -> V_28 ;
error = F_19 ( V_1 -> V_4 ) ;
if ( error < 0 ) {
F_3 ( V_3 , L_15 ) ;
goto V_72;
}
error = F_20 ( V_1 -> V_25 , F_4 ,
0 , V_40 -> V_55 , V_1 ) ;
if ( error < 0 ) {
F_3 ( V_3 , L_16 ) ;
goto V_73;
}
error = F_1 ( V_1 ) ;
if ( error < 0 ) {
F_3 ( V_3 , L_17 ) ;
goto V_74;
}
F_21 ( V_40 , V_1 ) ;
return 0 ;
V_74:
F_22 ( V_1 -> V_25 , V_1 ) ;
V_73:
F_23 ( V_1 -> V_4 ) ;
V_42 = NULL ;
V_72:
F_24 ( V_1 -> V_9 ) ;
V_57:
F_25 ( V_1 -> V_52 , V_1 -> V_54 ) ;
V_50:
F_26 ( V_42 ) ;
V_49:
F_27 ( V_1 ) ;
return error ;
}
static int F_28 ( struct V_39 * V_40 )
{
struct V_1 * V_1 = F_29 ( V_40 ) ;
F_22 ( V_1 -> V_25 , V_1 ) ;
F_23 ( V_1 -> V_4 ) ;
F_24 ( V_1 -> V_9 ) ;
F_25 ( V_1 -> V_52 , V_1 -> V_54 ) ;
F_27 ( V_1 ) ;
return 0 ;
}
