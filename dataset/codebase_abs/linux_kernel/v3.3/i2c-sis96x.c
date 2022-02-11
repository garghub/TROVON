static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( T_1 V_1 , T_1 V_3 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static int F_5 ( int V_4 )
{
int V_5 ;
int V_6 = 0 ;
int V_7 = 0 ;
F_6 ( & V_8 . V_9 , L_1 , V_4 ) ;
if ( ( ( V_5 = F_1 ( V_10 ) ) & 0x03 ) != 0x00 ) {
F_6 ( & V_8 . V_9 , L_2
L_3 , V_5 ) ;
F_3 ( V_11 , 0x20 ) ;
if ( ( ( V_5 = F_1 ( V_10 ) ) & 0x03 ) != 0x00 ) {
F_6 ( & V_8 . V_9 , L_4 , V_5 ) ;
return - V_12 ;
} else {
F_6 ( & V_8 . V_9 , L_5 ) ;
}
}
F_3 ( V_10 , 0x20 ) ;
V_5 = F_1 ( V_13 ) ;
F_3 ( V_13 , V_5 & 0x1e ) ;
F_3 ( V_11 , 0x10 | ( V_4 & 0x07 ) ) ;
do {
F_7 ( 1 ) ;
V_5 = F_1 ( V_13 ) ;
} while ( ! ( V_5 & 0x0e ) && ( V_7 ++ < V_14 ) );
if ( V_7 > V_14 ) {
F_6 ( & V_8 . V_9 , L_6 , V_5 ) ;
V_6 = - V_15 ;
}
if ( V_5 & 0x02 ) {
F_6 ( & V_8 . V_9 , L_7 ) ;
V_6 = - V_16 ;
}
if ( V_5 & 0x04 ) {
F_6 ( & V_8 . V_9 , L_8 ) ;
V_6 = - V_17 ;
}
F_3 ( V_13 , V_5 ) ;
if ( ( V_5 = F_1 ( V_13 ) ) ) {
F_6 ( & V_8 . V_9 , L_9
L_10 , V_5 ) ;
}
return V_6 ;
}
static T_2 F_8 ( struct V_18 * V_19 , T_3 V_20 ,
unsigned short V_21 , char V_22 ,
T_1 V_23 , int V_4 , union V_24 * V_3 )
{
int V_25 ;
switch ( V_4 ) {
case V_26 :
F_3 ( V_27 , ( ( V_20 & 0x7f ) << 1 ) | ( V_22 & 0x01 ) ) ;
V_4 = V_28 ;
break;
case V_29 :
F_3 ( V_27 , ( ( V_20 & 0x7f ) << 1 ) | ( V_22 & 0x01 ) ) ;
if ( V_22 == V_30 )
F_3 ( V_31 , V_23 ) ;
V_4 = V_32 ;
break;
case V_33 :
F_3 ( V_27 , ( ( V_20 & 0x7f ) << 1 ) | ( V_22 & 0x01 ) ) ;
F_3 ( V_31 , V_23 ) ;
if ( V_22 == V_30 )
F_3 ( V_34 , V_3 -> V_35 ) ;
V_4 = V_36 ;
break;
case V_37 :
case V_38 :
F_3 ( V_27 , ( ( V_20 & 0x7f ) << 1 ) | ( V_22 & 0x01 ) ) ;
F_3 ( V_31 , V_23 ) ;
if ( V_22 == V_30 ) {
F_3 ( V_34 , V_3 -> V_39 & 0xff ) ;
F_3 ( V_34 + 1 , ( V_3 -> V_39 & 0xff00 ) >> 8 ) ;
}
V_4 = ( V_4 == V_37 ?
V_40 : V_41 ) ;
break;
default:
F_9 ( & V_19 -> V_9 , L_11 , V_4 ) ;
return - V_42 ;
}
V_25 = F_5 ( V_4 ) ;
if ( V_25 )
return V_25 ;
if ( ( V_4 != V_40 ) &&
( ( V_22 == V_30 ) || ( V_4 == V_28 ) ) )
return 0 ;
switch ( V_4 ) {
case V_32 :
case V_36 :
V_3 -> V_35 = F_1 ( V_34 ) ;
break;
case V_41 :
case V_40 :
V_3 -> V_39 = F_1 ( V_34 ) +
( F_1 ( V_34 + 1 ) << 8 ) ;
break;
}
return 0 ;
}
static T_4 F_10 ( struct V_18 * V_43 )
{
return V_44 | V_45 |
V_46 | V_47 |
V_48 ;
}
static int T_5 F_11 ( struct V_49 * V_9 ,
const struct V_50 * V_51 )
{
T_3 V_52 = 0 ;
int V_53 ;
if ( V_2 ) {
F_12 ( & V_9 -> V_9 , L_12 ) ;
return - V_12 ;
}
F_13 ( V_9 , V_54 , & V_52 ) ;
if ( V_55 != V_52 ) {
F_12 ( & V_9 -> V_9 , L_13 , V_52 ) ;
return - V_56 ;
}
V_2 = F_14 ( V_9 , V_57 ) ;
if ( ! V_2 ) {
F_12 ( & V_9 -> V_9 , L_14
L_15 ) ;
return - V_58 ;
}
F_15 ( & V_9 -> V_9 , L_16 ,
V_2 ) ;
V_53 = F_16 ( & V_9 -> V_59 [ V_57 ] ) ;
if ( V_53 )
return - V_56 ;
if ( ! F_17 ( V_2 , V_60 ,
V_61 . V_62 ) ) {
F_12 ( & V_9 -> V_9 , L_17
L_18 , V_2 ,
V_2 + V_60 - 1 ) ;
V_2 = 0 ;
return - V_58 ;
}
V_8 . V_9 . V_63 = & V_9 -> V_9 ;
snprintf ( V_8 . V_62 , sizeof( V_8 . V_62 ) ,
L_19 , V_2 ) ;
if ( ( V_53 = F_18 ( & V_8 ) ) ) {
F_12 ( & V_9 -> V_9 , L_20 ) ;
F_19 ( V_2 , V_60 ) ;
V_2 = 0 ;
}
return V_53 ;
}
static void T_6 F_20 ( struct V_49 * V_9 )
{
if ( V_2 ) {
F_21 ( & V_8 ) ;
F_19 ( V_2 , V_60 ) ;
V_2 = 0 ;
}
}
static int T_7 F_22 ( void )
{
return F_23 ( & V_61 ) ;
}
static void T_8 F_24 ( void )
{
F_25 ( & V_61 ) ;
}
