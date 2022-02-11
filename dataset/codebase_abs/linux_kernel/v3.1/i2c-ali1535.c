static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 = - V_4 ;
unsigned char V_5 ;
F_2 ( V_2 , V_6 , & V_7 ) ;
V_7 &= ( 0xffff & ~ ( V_8 - 1 ) ) ;
if ( V_7 == 0 ) {
F_3 ( & V_2 -> V_2 ,
L_1 ) ;
goto exit;
}
V_3 = F_4 ( V_7 , V_8 ,
V_9 . V_10 ) ;
if ( V_3 )
goto exit;
if ( ! F_5 ( V_7 , V_8 ,
V_9 . V_10 ) ) {
F_6 ( & V_2 -> V_2 , L_2 ,
V_7 ) ;
goto exit;
}
F_7 ( V_2 , V_11 , & V_5 ) ;
if ( ( V_5 & V_12 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_3 ) ;
goto V_13;
}
F_7 ( V_2 , V_14 , & V_5 ) ;
if ( ( V_5 & 1 ) == 0 ) {
F_6 ( & V_2 -> V_2 , L_4 ) ;
goto V_13;
}
F_8 ( V_2 , V_15 , 0x20 ) ;
F_7 ( V_2 , V_16 , & V_5 ) ;
F_9 ( & V_2 -> V_2 , L_5 , V_5 ) ;
F_9 ( & V_2 -> V_2 , L_6 , V_7 ) ;
V_3 = 0 ;
exit:
return V_3 ;
V_13:
F_10 ( V_7 , V_8 ) ;
return V_3 ;
}
static int F_11 ( struct V_17 * V_18 )
{
int V_5 ;
int V_19 = 0 ;
int V_20 = 0 ;
F_9 ( & V_18 -> V_2 , L_7
L_8 ,
F_12 ( V_21 ) , F_12 ( V_22 ) , F_12 ( V_23 ) ,
F_12 ( V_24 ) , F_12 ( V_25 ) , F_12 ( V_26 ) ) ;
V_5 = F_12 ( V_21 ) ;
if ( V_5 & V_27 ) {
F_13 ( & V_18 -> V_2 ,
L_9 ,
V_5 ) ;
F_14 ( V_28 , V_22 ) ;
V_5 = F_12 ( V_21 ) ;
}
if ( V_5 & ( V_29 | V_27 ) ) {
F_14 ( 0xFF , V_21 ) ;
V_5 = F_12 ( V_21 ) ;
if ( V_5 & ( V_29 | V_27 ) ) {
F_6 ( & V_18 -> V_2 ,
L_10
L_11 , V_5 ) ;
return - V_30 ;
}
} else {
if ( V_5 & V_31 )
F_14 ( V_5 , V_21 ) ;
}
F_14 ( 0xFF , V_32 ) ;
V_20 = 0 ;
do {
F_15 ( 1000 , 2000 ) ;
V_5 = F_12 ( V_21 ) ;
} while ( ( ( V_5 & V_27 ) && ! ( V_5 & V_33 ) )
&& ( V_20 ++ < V_34 ) );
if ( V_20 > V_34 ) {
V_19 = - V_35 ;
F_6 ( & V_18 -> V_2 , L_12 ) ;
}
if ( V_5 & V_36 ) {
V_19 = - V_37 ;
F_9 ( & V_18 -> V_2 , L_13 ) ;
}
if ( V_5 & V_38 ) {
V_19 = - V_39 ;
F_9 ( & V_18 -> V_2 ,
L_14 ,
F_12 ( V_24 ) ) ;
}
if ( V_5 & V_40 ) {
V_19 = - V_37 ;
F_6 ( & V_18 -> V_2 , L_15 ) ;
}
if ( ! ( V_5 & V_31 ) ) {
V_19 = - V_35 ;
F_6 ( & V_18 -> V_2 , L_16 ) ;
}
F_9 ( & V_18 -> V_2 , L_17
L_8 ,
F_12 ( V_21 ) , F_12 ( V_22 ) , F_12 ( V_23 ) ,
F_12 ( V_24 ) , F_12 ( V_25 ) , F_12 ( V_26 ) ) ;
if ( ! ( V_5 & V_31 ) ) {
F_14 ( V_41 , V_22 ) ;
F_14 ( 0xFF , V_21 ) ;
} else if ( V_5 & V_29 ) {
F_14 ( V_28 , V_22 ) ;
F_14 ( 0xFF , V_21 ) ;
}
return V_19 ;
}
static T_2 F_16 ( struct V_17 * V_18 , T_3 V_42 ,
unsigned short V_43 , char V_44 , T_4 V_45 ,
int V_46 , union V_47 * V_48 )
{
int V_49 , V_50 ;
int V_5 ;
int V_20 ;
T_2 V_19 = 0 ;
V_5 = F_12 ( V_21 ) ;
for ( V_20 = 0 ;
( V_20 < V_34 ) && ! ( V_5 & V_33 ) ;
V_20 ++ ) {
F_15 ( 1000 , 2000 ) ;
V_5 = F_12 ( V_21 ) ;
}
if ( V_20 >= V_34 )
F_3 ( & V_18 -> V_2 , L_18 , V_5 ) ;
F_14 ( 0xFF , V_21 ) ;
switch ( V_46 ) {
case V_51 :
F_14 ( ( ( V_42 & 0x7f ) << 1 ) | ( V_44 & 0x01 ) ,
V_24 ) ;
V_46 = V_52 ;
F_14 ( V_46 , V_22 ) ;
break;
case V_53 :
F_14 ( ( ( V_42 & 0x7f ) << 1 ) | ( V_44 & 0x01 ) ,
V_24 ) ;
V_46 = V_54 ;
F_14 ( V_46 , V_22 ) ;
if ( V_44 == V_55 )
F_14 ( V_45 , V_23 ) ;
break;
case V_56 :
F_14 ( ( ( V_42 & 0x7f ) << 1 ) | ( V_44 & 0x01 ) ,
V_24 ) ;
V_46 = V_57 ;
F_14 ( V_46 , V_22 ) ;
F_14 ( V_45 , V_23 ) ;
if ( V_44 == V_55 )
F_14 ( V_48 -> V_58 , V_25 ) ;
break;
case V_59 :
F_14 ( ( ( V_42 & 0x7f ) << 1 ) | ( V_44 & 0x01 ) ,
V_24 ) ;
V_46 = V_60 ;
F_14 ( V_46 , V_22 ) ;
F_14 ( V_45 , V_23 ) ;
if ( V_44 == V_55 ) {
F_14 ( V_48 -> V_61 & 0xff , V_25 ) ;
F_14 ( ( V_48 -> V_61 & 0xff00 ) >> 8 , V_26 ) ;
}
break;
case V_62 :
F_14 ( ( ( V_42 & 0x7f ) << 1 ) | ( V_44 & 0x01 ) ,
V_24 ) ;
V_46 = V_63 ;
F_14 ( V_46 , V_22 ) ;
F_14 ( V_45 , V_23 ) ;
if ( V_44 == V_55 ) {
V_50 = V_48 -> V_64 [ 0 ] ;
if ( V_50 < 0 ) {
V_50 = 0 ;
V_48 -> V_64 [ 0 ] = V_50 ;
}
if ( V_50 > 32 ) {
V_50 = 32 ;
V_48 -> V_64 [ 0 ] = V_50 ;
}
F_14 ( V_50 , V_25 ) ;
F_14 ( F_12 ( V_22 ) | V_65 , V_22 ) ;
for ( V_49 = 1 ; V_49 <= V_50 ; V_49 ++ )
F_14 ( V_48 -> V_64 [ V_49 ] , V_66 ) ;
}
break;
default:
F_3 ( & V_18 -> V_2 , L_19 , V_46 ) ;
V_19 = - V_67 ;
goto EXIT;
}
V_19 = F_11 ( V_18 ) ;
if ( V_19 )
goto EXIT;
if ( ( V_44 == V_55 ) || ( V_46 == V_52 ) ) {
V_19 = 0 ;
goto EXIT;
}
switch ( V_46 ) {
case V_54 :
V_48 -> V_58 = F_12 ( V_25 ) ;
break;
case V_57 :
V_48 -> V_58 = F_12 ( V_25 ) ;
break;
case V_60 :
V_48 -> V_61 = F_12 ( V_25 ) + ( F_12 ( V_26 ) << 8 ) ;
break;
case V_63 :
V_50 = F_12 ( V_25 ) ;
if ( V_50 > 32 )
V_50 = 32 ;
V_48 -> V_64 [ 0 ] = V_50 ;
F_14 ( F_12 ( V_22 ) | V_65 , V_22 ) ;
for ( V_49 = 1 ; V_49 <= V_48 -> V_64 [ 0 ] ; V_49 ++ ) {
V_48 -> V_64 [ V_49 ] = F_12 ( V_66 ) ;
F_9 ( & V_18 -> V_2 , L_20 ,
V_50 , V_49 , V_48 -> V_64 [ V_49 ] ) ;
}
break;
}
EXIT:
return V_19 ;
}
static T_5 F_17 ( struct V_17 * V_68 )
{
return V_69 | V_70 |
V_71 | V_72 |
V_73 ;
}
static int T_1 F_18 ( struct V_1 * V_2 , const struct V_74 * V_75 )
{
if ( F_1 ( V_2 ) ) {
F_3 ( & V_2 -> V_2 ,
L_21 ) ;
return - V_4 ;
}
V_76 . V_2 . V_77 = & V_2 -> V_2 ;
snprintf ( V_76 . V_10 , sizeof( V_76 . V_10 ) ,
L_22 , V_7 ) ;
return F_19 ( & V_76 ) ;
}
static void T_6 F_20 ( struct V_1 * V_2 )
{
F_21 ( & V_76 ) ;
F_10 ( V_7 , V_8 ) ;
}
static int T_7 F_22 ( void )
{
return F_23 ( & V_9 ) ;
}
static void T_8 F_24 ( void )
{
F_25 ( & V_9 ) ;
}
