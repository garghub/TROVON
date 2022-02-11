static int F_1 ( void )
{
int V_1 ;
int V_2 = 0 ;
int V_3 = 0 ;
F_2 ( & V_4 . V_5 , L_1
L_2 , F_3 ( V_6 ) ,
F_3 ( V_7 ) , F_3 ( V_8 ) , F_3 ( V_9 ) ,
F_3 ( V_10 ) ) ;
V_1 = F_3 ( V_11 ) & 0x0f ;
if ( V_1 ) {
if ( V_1 & 0x01 ) {
F_2 ( & V_4 . V_5 , L_3
L_4 , V_1 ) ;
}
if ( V_1 & 0x06 ) {
F_2 ( & V_4 . V_5 , L_5
L_6 , V_1 ) ;
}
F_4 ( V_1 , V_11 ) ;
V_1 = F_3 ( V_11 ) & 0x0f ;
if ( V_1 ) {
F_5 ( & V_4 . V_5 ,
L_7 , V_1 ) ;
return - V_12 ;
}
}
F_4 ( F_3 ( V_6 ) | 0x10 , V_6 ) ;
do {
F_6 ( 100 , 200 ) ;
V_1 = F_3 ( V_11 ) & 0x0f ;
} while ( ( V_1 & 0x08 ) && ( V_3 ++ < V_13 ) );
if ( V_3 > V_13 ) {
F_5 ( & V_4 . V_5 , L_8 ) ;
V_2 = - V_14 ;
}
if ( V_1 & 0x04 ) {
V_2 = - V_15 ;
F_2 ( & V_4 . V_5 , L_9
L_10 ) ;
} else if ( V_1 & 0x02 ) {
V_2 = - V_15 ;
F_5 ( & V_4 . V_5 , L_11 ) ;
} else if ( V_1 & 0x01 ) {
F_2 ( & V_4 . V_5 , L_12 ) ;
F_4 ( V_1 , V_11 ) ;
V_1 = F_3 ( V_11 ) & 0x07 ;
if ( V_1 & 0x06 ) {
F_2 ( & V_4 . V_5 , L_13
L_14 , V_1 ) ;
}
} else {
V_2 = - V_16 ;
F_2 ( & V_4 . V_5 , L_15 ) ;
}
F_2 ( & V_4 . V_5 , L_16
L_2 , F_3 ( V_6 ) ,
F_3 ( V_7 ) , F_3 ( V_8 ) , F_3 ( V_9 ) ,
F_3 ( V_10 ) ) ;
return V_2 ;
}
static T_1 F_7 ( struct V_17 * V_18 , T_2 V_19 ,
unsigned short V_20 , char V_21 ,
T_3 V_22 , int V_23 , union V_24 * V_25 )
{
int V_26 , V_27 , V_1 , V_28 ;
V_1 = F_3 ( V_11 ) & 0x0f ;
if ( V_1 & 0x08 ) {
F_2 ( & V_4 . V_5 , L_17 , V_1 ) ;
return - V_12 ;
}
V_1 = F_8 ( V_29 ) ;
if ( ! V_1 ) {
F_9 ( & V_4 . V_5 ,
L_18 ) ;
F_10 ( V_30 / ( 4 * 100 ) , V_29 ) ;
}
F_2 ( & V_4 . V_5 , L_19 , V_23 ,
( V_21 ) ? L_20 : L_21 ) ;
switch ( V_23 ) {
case V_31 :
F_4 ( ( V_19 << 1 ) | V_21 , V_8 ) ;
V_23 = V_32 ;
break;
case V_33 :
F_4 ( ( V_19 << 1 ) | V_21 , V_8 ) ;
if ( V_21 == V_34 )
F_4 ( V_22 , V_7 ) ;
V_23 = V_35 ;
break;
case V_36 :
F_4 ( ( V_19 << 1 ) | V_21 , V_8 ) ;
F_4 ( V_22 , V_7 ) ;
if ( V_21 == V_34 )
F_4 ( V_25 -> V_37 , V_9 ) ;
V_23 = V_38 ;
break;
case V_39 :
F_4 ( ( V_19 << 1 ) | V_21 , V_8 ) ;
F_4 ( V_22 , V_7 ) ;
if ( V_21 == V_34 ) {
F_4 ( V_25 -> V_40 & 0xff , V_9 ) ;
F_4 ( ( V_25 -> V_40 & 0xff00 ) >> 8 , V_10 ) ;
}
V_23 = V_41 ;
break;
case V_42 :
F_4 ( ( V_19 << 1 ) | V_21 , V_8 ) ;
F_4 ( V_22 , V_7 ) ;
if ( V_21 == V_34 ) {
V_27 = V_25 -> V_43 [ 0 ] ;
if ( V_27 == 0 || V_27 > V_44 )
return - V_45 ;
F_4 ( V_27 , V_9 ) ;
for ( V_26 = 1 ; V_26 <= V_27 ; V_26 ++ )
F_4 ( V_25 -> V_43 [ V_26 ] , V_46 + V_26 - 1 ) ;
}
V_23 = V_47 ;
break;
default:
F_11 ( & V_18 -> V_5 , L_22 , V_23 ) ;
return - V_48 ;
}
F_2 ( & V_4 . V_5 , L_23 , V_23 , V_6 ) ;
F_4 ( ( F_3 ( V_6 ) & 0xb0 ) | ( V_23 & 0x7 ) , V_6 ) ;
V_28 = F_1 () ;
if ( V_28 )
return V_28 ;
if ( ( V_21 == V_34 ) || ( V_23 == V_32 ) )
return 0 ;
switch ( V_23 ) {
case V_35 :
case V_38 :
V_25 -> V_37 = F_3 ( V_9 ) ;
break;
case V_41 :
V_25 -> V_40 = F_3 ( V_9 ) + ( F_3 ( V_10 ) << 8 ) ;
break;
case V_47 :
V_25 -> V_43 [ 0 ] = F_3 ( V_9 ) ;
if ( V_25 -> V_43 [ 0 ] == 0 || V_25 -> V_43 [ 0 ] > V_44 )
return - V_49 ;
for ( V_26 = 1 ; V_26 <= V_25 -> V_43 [ 0 ] ; V_26 ++ )
V_25 -> V_43 [ V_26 ] = F_3 ( V_46 + V_26 - 1 ) ;
break;
}
return 0 ;
}
static T_4 F_12 ( struct V_17 * V_50 )
{
return V_51 | V_52 |
V_53 | V_54 |
V_55 ;
}
static int F_13 ( struct V_56 * V_5 )
{
struct V_57 * V_58 ;
int V_59 ;
V_58 = F_14 ( V_5 , V_60 , 0 ) ;
if ( ! V_58 )
return - V_61 ;
if ( ! F_15 ( & V_5 -> V_5 , V_58 -> V_62 , F_16 ( V_58 ) ,
V_5 -> V_63 ) ) {
F_5 ( & V_5 -> V_5 , L_24 ,
V_64 ) ;
return - V_61 ;
}
V_64 = V_58 -> V_62 ;
F_2 ( & V_5 -> V_5 , L_25 , V_64 ) ;
V_4 . V_5 . V_65 = & V_5 -> V_5 ;
snprintf ( V_4 . V_63 , sizeof( V_4 . V_63 ) ,
L_26 , V_64 ) ;
V_59 = F_17 ( & V_4 ) ;
if ( V_59 ) {
F_5 ( & V_5 -> V_5 , L_27 ) ;
V_64 = 0 ;
}
return V_59 ;
}
static int F_18 ( struct V_56 * V_66 )
{
if ( V_64 ) {
F_19 ( & V_4 ) ;
V_64 = 0 ;
}
return 0 ;
}
