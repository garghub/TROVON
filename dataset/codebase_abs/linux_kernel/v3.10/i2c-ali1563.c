static int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
int V_5 ;
int V_6 = - V_7 ;
F_2 ( & V_2 -> V_8 , L_1
L_2 ,
F_3 ( V_9 ) , F_3 ( V_10 ) , F_3 ( V_11 ) ,
F_3 ( V_12 ) , F_3 ( V_13 ) , F_3 ( V_14 ) ,
F_3 ( V_15 ) ) ;
V_4 = F_3 ( V_9 ) ;
if ( V_4 & V_16 ) {
F_4 ( & V_2 -> V_8 , L_3 ) ;
F_5 ( V_4 | V_16 , V_9 ) ;
V_4 = F_3 ( V_9 ) ;
if ( V_4 & V_16 )
return - V_17 ;
}
F_5 ( F_3 ( V_11 ) | V_18 , V_11 ) ;
V_5 = V_19 ;
do {
F_6 ( 1 ) ;
} while ( ( ( V_4 = F_3 ( V_9 ) ) & V_20 ) && -- V_5 );
F_2 ( & V_2 -> V_8 , L_4
L_2 ,
F_3 ( V_9 ) , F_3 ( V_10 ) , F_3 ( V_11 ) ,
F_3 ( V_12 ) , F_3 ( V_13 ) , F_3 ( V_14 ) ,
F_3 ( V_15 ) ) ;
if ( V_5 && ! ( V_4 & V_16 ) )
return 0 ;
if ( ! V_5 ) {
F_4 ( & V_2 -> V_8 , L_5 ) ;
F_5 ( V_21 , V_11 ) ;
V_4 = F_3 ( V_9 ) ;
V_6 = - V_22 ;
}
if ( V_4 & V_23 ) {
if ( V_3 != V_24 )
F_4 ( & V_2 -> V_8 , L_6 ) ;
V_6 = - V_25 ;
}
if ( V_4 & V_26 ) {
F_4 ( & V_2 -> V_8 , L_7 ) ;
F_5 ( V_27 , V_10 ) ;
}
if ( V_4 & V_28 ) {
F_4 ( & V_2 -> V_8 , L_8 ) ;
F_5 ( 0x0 , V_11 ) ;
}
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_5 ;
int V_6 = - V_7 ;
F_2 ( & V_2 -> V_8 , L_9
L_2 ,
F_3 ( V_9 ) , F_3 ( V_10 ) , F_3 ( V_11 ) ,
F_3 ( V_12 ) , F_3 ( V_13 ) , F_3 ( V_14 ) ,
F_3 ( V_15 ) ) ;
V_4 = F_3 ( V_9 ) ;
if ( V_4 & V_16 ) {
F_8 ( & V_2 -> V_8 , L_3 ) ;
F_5 ( V_4 | V_16 , V_9 ) ;
V_4 = F_3 ( V_9 ) ;
if ( V_4 & V_16 )
return - V_17 ;
}
F_5 ( V_4 | V_29 , V_9 ) ;
F_5 ( F_3 ( V_11 ) | V_18 , V_11 ) ;
V_5 = V_19 ;
do {
F_6 ( 1 ) ;
} while ( ! ( ( V_4 = F_3 ( V_9 ) ) & V_29 ) && -- V_5 );
F_2 ( & V_2 -> V_8 , L_10
L_2 ,
F_3 ( V_9 ) , F_3 ( V_10 ) , F_3 ( V_11 ) ,
F_3 ( V_12 ) , F_3 ( V_13 ) , F_3 ( V_14 ) ,
F_3 ( V_15 ) ) ;
if ( V_5 && ! ( V_4 & V_16 ) )
return 0 ;
if ( V_5 == 0 )
V_6 = - V_22 ;
if ( V_4 & V_23 )
V_6 = - V_25 ;
F_4 ( & V_2 -> V_8 , L_11 ,
V_5 ? L_12 : L_13 ,
V_4 & V_28 ? L_14 : L_12 ,
V_4 & V_26 ? L_15 : L_12 ,
V_4 & V_23 ? L_16 : L_12 ,
! ( V_4 & V_29 ) ? L_17 : L_12 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 , union V_30 * V_4 , T_2 V_31 )
{
int V_32 , V_33 ;
int error = 0 ;
F_5 ( V_34 , V_10 ) ;
if ( V_31 == V_35 ) {
V_33 = V_4 -> V_36 [ 0 ] ;
if ( V_33 < 1 )
V_33 = 1 ;
else if ( V_33 > 32 )
V_33 = 32 ;
F_5 ( V_33 , V_14 ) ;
F_5 ( V_4 -> V_36 [ 1 ] , V_37 ) ;
} else
V_33 = 32 ;
F_5 ( F_3 ( V_11 ) | V_38 , V_11 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
if ( V_31 == V_35 ) {
F_5 ( V_4 -> V_36 [ V_32 + 1 ] , V_37 ) ;
if ( ( error = F_7 ( V_2 ) ) )
break;
} else {
if ( ( error = F_7 ( V_2 ) ) )
break;
if ( V_32 == 0 ) {
V_33 = F_3 ( V_14 ) ;
if ( V_33 < 1 )
V_33 = 1 ;
else if ( V_33 > 32 )
V_33 = 32 ;
}
V_4 -> V_36 [ V_32 + 1 ] = F_3 ( V_37 ) ;
}
}
F_5 ( V_34 , V_10 ) ;
return error ;
}
static T_3 F_10 ( struct V_1 * V_2 , T_4 V_39 ,
unsigned short V_40 , char V_31 , T_2 V_41 ,
int V_3 , union V_30 * V_4 )
{
int error = 0 ;
int V_5 ;
T_1 V_42 ;
for ( V_5 = V_19 ; V_5 ; V_5 -- ) {
if ( ! ( V_42 = F_3 ( V_9 ) & V_20 ) )
break;
}
if ( ! V_5 )
F_8 ( & V_2 -> V_8 , L_18 , V_42 ) ;
F_5 ( 0xff , V_9 ) ;
switch ( V_3 ) {
case V_43 :
V_3 = V_24 ;
break;
case V_44 :
V_3 = V_45 ;
break;
case V_46 :
V_3 = V_47 ;
break;
case V_48 :
V_3 = V_49 ;
break;
case V_50 :
V_3 = V_38 ;
break;
default:
F_8 ( & V_2 -> V_8 , L_19 , V_3 ) ;
error = - V_51 ;
goto V_52;
}
F_5 ( ( ( V_39 & 0x7f ) << 1 ) | ( V_31 & 0x01 ) , V_13 ) ;
F_5 ( ( F_3 ( V_11 ) & ~ V_53 ) | ( V_3 << 3 ) , V_11 ) ;
switch( V_3 ) {
case V_45 :
if ( V_31 == V_35 )
F_5 ( V_41 , V_14 ) ;
break;
case V_47 :
F_5 ( V_41 , V_12 ) ;
if ( V_31 == V_35 )
F_5 ( V_4 -> V_54 , V_14 ) ;
break;
case V_49 :
F_5 ( V_41 , V_12 ) ;
if ( V_31 == V_35 ) {
F_5 ( V_4 -> V_55 & 0xff , V_14 ) ;
F_5 ( ( V_4 -> V_55 & 0xff00 ) >> 8 , V_15 ) ;
}
break;
case V_38 :
F_5 ( V_41 , V_12 ) ;
error = F_9 ( V_2 , V_4 , V_31 ) ;
goto V_52;
}
if ( ( error = F_1 ( V_2 , V_3 ) ) )
goto V_52;
if ( ( V_31 == V_35 ) || ( V_3 == V_24 ) )
goto V_52;
switch ( V_3 ) {
case V_45 :
V_4 -> V_54 = F_3 ( V_14 ) ;
break;
case V_47 :
V_4 -> V_54 = F_3 ( V_14 ) ;
break;
case V_49 :
V_4 -> V_55 = F_3 ( V_14 ) + ( F_3 ( V_15 ) << 8 ) ;
break;
}
V_52:
return error ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
return V_56 | V_57 |
V_58 | V_59 |
V_60 ;
}
static int F_12 ( struct V_61 * V_8 )
{
T_4 V_62 ;
F_13 ( V_8 , V_63 , & V_62 ) ;
V_64 = V_62 & ~ ( V_65 - 1 ) ;
if ( ! V_64 ) {
F_8 ( & V_8 -> V_8 , L_20 ) ;
goto V_66;
}
if ( ! ( V_62 & V_67 ) ) {
F_8 ( & V_8 -> V_8 , L_21 ) ;
goto V_66;
}
if ( ! ( V_62 & V_68 ) ) {
F_8 ( & V_8 -> V_8 , L_22 ) ;
F_14 ( V_8 , V_63 ,
V_62 | V_68 ) ;
F_13 ( V_8 , V_63 , & V_62 ) ;
if ( ! ( V_62 & V_68 ) ) {
F_4 ( & V_8 -> V_8 , L_23
L_24 ) ;
goto V_66;
}
}
if ( F_15 ( V_64 , V_65 ,
V_69 . V_70 ) )
goto V_66;
if ( ! F_16 ( V_64 , V_65 ,
V_69 . V_70 ) ) {
F_4 ( & V_8 -> V_8 , L_25 ,
V_64 ) ;
goto V_66;
}
F_17 ( & V_8 -> V_8 , L_26 , V_64 ) ;
return 0 ;
V_66:
return - V_71 ;
}
static void F_18 ( struct V_61 * V_8 )
{
F_19 ( V_64 , V_65 ) ;
}
static int F_20 ( struct V_61 * V_8 ,
const struct V_72 * V_73 )
{
int error ;
if ( ( error = F_12 ( V_8 ) ) )
goto exit;
V_74 . V_8 . V_75 = & V_8 -> V_8 ;
snprintf ( V_74 . V_70 , sizeof( V_74 . V_70 ) ,
L_27 , V_64 ) ;
if ( ( error = F_21 ( & V_74 ) ) )
goto V_76;
return 0 ;
V_76:
F_18 ( V_8 ) ;
exit:
F_8 ( & V_8 -> V_8 , L_28 , error ) ;
return error ;
}
static void F_22 ( struct V_61 * V_8 )
{
F_23 ( & V_74 ) ;
F_18 ( V_8 ) ;
}
