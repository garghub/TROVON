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
F_2 ( & V_4 . V_5 , L_18 , V_23 ,
( V_21 ) ? L_19 : L_20 ) ;
switch ( V_23 ) {
case V_29 :
F_4 ( ( V_19 << 1 ) | V_21 , V_8 ) ;
V_23 = V_30 ;
break;
case V_31 :
F_4 ( ( V_19 << 1 ) | V_21 , V_8 ) ;
if ( V_21 == V_32 )
F_4 ( V_22 , V_7 ) ;
V_23 = V_33 ;
break;
case V_34 :
F_4 ( ( V_19 << 1 ) | V_21 , V_8 ) ;
F_4 ( V_22 , V_7 ) ;
if ( V_21 == V_32 )
F_4 ( V_25 -> V_35 , V_9 ) ;
V_23 = V_36 ;
break;
case V_37 :
F_4 ( ( V_19 << 1 ) | V_21 , V_8 ) ;
F_4 ( V_22 , V_7 ) ;
if ( V_21 == V_32 ) {
F_4 ( V_25 -> V_38 & 0xff , V_9 ) ;
F_4 ( ( V_25 -> V_38 & 0xff00 ) >> 8 , V_10 ) ;
}
V_23 = V_39 ;
break;
case V_40 :
F_4 ( ( V_19 << 1 ) | V_21 , V_8 ) ;
F_4 ( V_22 , V_7 ) ;
if ( V_21 == V_32 ) {
V_27 = V_25 -> V_41 [ 0 ] ;
if ( V_27 == 0 || V_27 > V_42 )
return - V_43 ;
F_4 ( V_27 , V_9 ) ;
for ( V_26 = 1 ; V_26 <= V_27 ; V_26 ++ )
F_4 ( V_25 -> V_41 [ V_26 ] , V_44 + V_26 - 1 ) ;
}
V_23 = V_45 ;
break;
default:
F_8 ( & V_18 -> V_5 , L_21 , V_23 ) ;
return - V_46 ;
}
F_2 ( & V_4 . V_5 , L_22 , V_23 , V_6 ) ;
F_4 ( ( F_3 ( V_6 ) & 0xb0 ) | ( V_23 & 0x7 ) , V_6 ) ;
V_28 = F_1 () ;
if ( V_28 )
return V_28 ;
if ( ( V_21 == V_32 ) || ( V_23 == V_30 ) )
return 0 ;
switch ( V_23 ) {
case V_33 :
case V_36 :
V_25 -> V_35 = F_3 ( V_9 ) ;
break;
case V_39 :
V_25 -> V_38 = F_3 ( V_9 ) + ( F_3 ( V_10 ) << 8 ) ;
break;
case V_45 :
V_25 -> V_41 [ 0 ] = F_3 ( V_9 ) ;
if ( V_25 -> V_41 [ 0 ] == 0 || V_25 -> V_41 [ 0 ] > V_42 )
return - V_47 ;
for ( V_26 = 1 ; V_26 <= V_25 -> V_41 [ 0 ] ; V_26 ++ )
V_25 -> V_41 [ V_26 ] = F_3 ( V_44 + V_26 - 1 ) ;
break;
}
return 0 ;
}
static T_4 F_9 ( struct V_17 * V_48 )
{
return V_49 | V_50 |
V_51 | V_52 |
V_53 ;
}
static int F_10 ( struct V_54 * V_5 )
{
struct V_55 * V_56 ;
int V_57 ;
V_56 = F_11 ( V_5 , V_58 , 0 ) ;
if ( ! V_56 )
return - V_59 ;
if ( ! F_12 ( V_56 -> V_60 , F_13 ( V_56 ) , V_5 -> V_61 ) ) {
F_5 ( & V_5 -> V_5 , L_23 ,
V_62 ) ;
return - V_59 ;
}
V_62 = V_56 -> V_60 ;
F_2 ( & V_5 -> V_5 , L_24 , V_62 ) ;
V_4 . V_5 . V_63 = & V_5 -> V_5 ;
snprintf ( V_4 . V_61 , sizeof( V_4 . V_61 ) ,
L_25 , V_62 ) ;
V_57 = F_14 ( & V_4 ) ;
if ( V_57 ) {
F_5 ( & V_5 -> V_5 , L_26 ) ;
F_15 ( V_56 -> V_60 , F_13 ( V_56 ) ) ;
V_62 = 0 ;
}
return V_57 ;
}
static int F_16 ( struct V_54 * V_64 )
{
struct V_55 * V_56 ;
if ( V_62 ) {
F_17 ( & V_4 ) ;
V_56 = F_11 ( V_64 , V_58 , 0 ) ;
F_15 ( V_56 -> V_60 , F_13 ( V_56 ) ) ;
V_62 = 0 ;
}
return 0 ;
}
