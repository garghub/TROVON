static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = 0 ;
int V_5 = 0 ;
F_2 ( & V_2 -> V_6 , L_1
L_2 , F_3 ( V_7 ) ,
F_3 ( V_8 ) , F_3 ( V_9 ) ,
F_4 ( V_10 ) ) ;
if ( ( V_3 = F_3 ( V_7 ) ) & ( V_11 | V_12 ) ) {
F_2 ( & V_2 -> V_6 , L_3 , V_3 ) ;
do {
F_5 ( 1 ) ;
V_3 = F_3 ( V_7 ) ;
} while ( ( V_3 & ( V_11 | V_12 ) ) &&
( V_5 ++ < V_13 ) );
if ( V_5 > V_13 ) {
F_2 ( & V_2 -> V_6 , L_4 , V_3 ) ;
goto abort;
}
V_5 = 0 ;
}
F_6 ( F_7 ( V_8 ) | V_14 , V_8 ) ;
do {
F_5 ( 1 ) ;
V_3 = F_3 ( V_7 ) ;
} while ( ( V_3 & V_11 ) && ( V_5 ++ < V_13 ) );
if ( V_5 > V_13 ) {
F_2 ( & V_2 -> V_6 , L_5 ) ;
goto abort;
}
if ( V_3 & V_15 ) {
V_4 = - V_16 ;
F_2 ( & V_2 -> V_6 , L_6 ) ;
}
if ( V_3 & V_17 ) {
V_4 = - V_18 ;
F_8 ( & V_2 -> V_6 , L_7 ) ;
}
if ( V_3 & V_19 ) {
V_4 = - V_20 ;
F_2 ( & V_2 -> V_6 , L_8 ) ;
}
if ( V_3 & V_21 )
F_2 ( & V_2 -> V_6 , L_9 ) ;
F_6 ( V_22 , V_7 ) ;
#ifdef F_9
if ( ( ( V_3 = F_3 ( V_7 ) ) & V_22 ) != 0x00 ) {
F_2 ( & V_2 -> V_6 ,
L_10 , V_3 ) ;
}
#endif
F_2 ( & V_2 -> V_6 ,
L_11 ,
F_3 ( V_7 ) , F_3 ( V_8 ) ,
F_3 ( V_9 ) , F_4 ( V_10 ) ) ;
return V_4 ;
abort:
F_8 ( & V_2 -> V_6 , L_12 ) ;
F_6 ( F_7 ( V_8 ) | V_23 , V_8 ) ;
F_5 ( 100 ) ;
F_6 ( V_22 , V_7 ) ;
return - V_18 ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_2 V_24 ,
unsigned short V_25 , char V_26 ,
T_3 V_27 , int V_28 , union V_29 * V_30 )
{
int V_31 , V_32 ;
int V_33 ;
switch ( V_28 ) {
case V_34 :
F_6 ( ( ( V_24 & 0x7f ) << 1 ) | ( V_26 & 0x01 ) ,
V_9 ) ;
V_28 = V_35 ;
break;
case V_36 :
F_6 ( ( ( V_24 & 0x7f ) << 1 ) | ( V_26 & 0x01 ) ,
V_9 ) ;
if ( V_26 == V_37 )
F_11 ( V_27 , V_10 ) ;
V_28 = V_38 ;
break;
case V_39 :
F_6 ( ( ( V_24 & 0x7f ) << 1 ) | ( V_26 & 0x01 ) ,
V_9 ) ;
F_11 ( V_27 , V_40 ) ;
if ( V_26 == V_37 )
F_6 ( V_30 -> V_41 , V_10 ) ;
V_28 = V_42 ;
break;
case V_43 :
F_6 ( ( ( V_24 & 0x7f ) << 1 ) | ( V_26 & 0x01 ) ,
V_9 ) ;
F_11 ( V_27 , V_40 ) ;
if ( V_26 == V_37 )
F_6 ( V_30 -> V_44 , V_10 ) ;
V_28 = V_45 ;
break;
case V_46 :
F_6 ( ( ( V_24 & 0x7f ) << 1 ) | ( V_26 & 0x01 ) ,
V_9 ) ;
F_11 ( V_27 , V_40 ) ;
if ( V_26 == V_37 ) {
V_32 = V_30 -> V_47 [ 0 ] ;
if ( V_32 < 0 )
V_32 = 0 ;
if ( V_32 > 32 )
V_32 = 32 ;
F_6 ( V_32 , V_10 ) ;
for ( V_31 = 1 ; V_31 <= V_32 ; V_31 ++ )
F_11 ( V_30 -> V_47 [ V_31 ] ,
V_48 ) ;
}
V_28 = V_49 ;
break;
default:
F_8 ( & V_2 -> V_6 , L_13 , V_28 ) ;
return - V_50 ;
}
F_6 ( V_28 & V_51 , V_8 ) ;
V_33 = F_1 ( V_2 ) ;
if ( V_33 )
return V_33 ;
if ( ( V_26 == V_37 ) || ( V_28 == V_35 ) )
return 0 ;
switch ( V_28 ) {
case V_38 :
V_30 -> V_41 = F_3 ( V_10 ) ;
break;
case V_42 :
V_30 -> V_41 = F_3 ( V_10 ) ;
break;
case V_45 :
V_30 -> V_44 = F_3 ( V_10 ) ;
break;
case V_49 :
V_30 -> V_47 [ 0 ] = F_3 ( V_10 ) & 0x3f ;
if( V_30 -> V_47 [ 0 ] > 32 )
V_30 -> V_47 [ 0 ] = 32 ;
for ( V_31 = 1 ; V_31 <= V_30 -> V_47 [ 0 ] ; V_31 ++ )
V_30 -> V_47 [ V_31 ] = F_4 ( V_48 ) ;
break;
}
return 0 ;
}
static T_4 F_12 ( struct V_1 * V_52 )
{
return V_53 | V_54 |
V_55 | V_56 |
V_57 ;
}
static int T_5 F_13 ( struct V_58 * V_59 ,
const struct V_60 * V_61 )
{
int V_62 = ( V_61 -> V_63 == V_64 ) ;
int error ;
T_3 V_3 ;
if ( V_65 ) {
F_14 ( & V_59 -> V_6 , L_14
L_15 ) ;
return - V_66 ;
}
if ( V_62 ) {
if ( F_15 ( V_59 -> V_67 ) != 1 )
return - V_66 ;
F_16 ( V_59 , V_68 , & V_65 ) ;
V_65 &= 0xfffc ;
} else {
if ( F_15 ( V_59 -> V_67 ) != 3 )
return - V_66 ;
F_17 ( V_59 , V_69 , & V_3 ) ;
if ( ( V_3 & 128 ) == 0 ) {
F_14 ( & V_59 -> V_6 ,
L_16 ) ;
return - V_66 ;
}
F_16 ( V_59 , V_70 , & V_65 ) ;
V_65 &= 0xff00 ;
V_65 += V_71 ;
}
error = F_18 ( V_65 , V_72 ,
V_73 . V_74 ) ;
if ( error )
return - V_66 ;
if ( ! F_19 ( V_65 , V_72 , V_73 . V_74 ) ) {
F_14 ( & V_59 -> V_6 , L_17 ,
V_65 ) ;
return - V_66 ;
}
F_17 ( V_59 , V_75 , & V_3 ) ;
F_2 ( & V_59 -> V_6 , L_18 , V_3 ) ;
F_2 ( & V_59 -> V_6 , L_19 , V_65 ) ;
V_76 . V_6 . V_77 = & V_59 -> V_6 ;
snprintf ( V_76 . V_74 , sizeof( V_76 . V_74 ) ,
L_20 , V_78 [ V_61 -> V_63 ] ,
V_65 ) ;
error = F_20 ( & V_76 ) ;
if ( error ) {
F_14 ( & V_59 -> V_6 ,
L_21 ) ;
goto V_79;
}
return 0 ;
V_79:
F_21 ( V_65 , V_72 ) ;
return error ;
}
static void T_6 F_22 ( struct V_58 * V_6 )
{
F_23 ( & V_76 ) ;
F_21 ( V_65 , V_72 ) ;
}
static int T_7 F_24 ( void )
{
return F_25 ( & V_73 ) ;
}
static void T_8 F_26 ( void )
{
F_27 ( & V_73 ) ;
}
