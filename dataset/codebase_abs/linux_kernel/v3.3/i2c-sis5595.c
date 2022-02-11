static T_1 F_1 ( T_1 V_1 )
{
F_2 ( V_1 , V_2 + V_3 ) ;
return F_3 ( V_2 + V_4 ) ;
}
static void F_4 ( T_1 V_1 , T_1 V_5 )
{
F_2 ( V_1 , V_2 + V_3 ) ;
F_2 ( V_5 , V_2 + V_4 ) ;
}
static int T_2 F_5 ( struct V_6 * V_7 )
{
T_3 V_8 ;
T_1 V_9 ;
int * V_10 ;
int V_11 ;
for ( V_10 = V_12 ; * V_10 != 0 ; V_10 ++ ) {
struct V_6 * V_13 ;
V_13 = F_6 ( V_14 , * V_10 , NULL ) ;
if ( V_13 ) {
F_7 ( & V_7 -> V_13 , L_1 , * V_10 ) ;
F_8 ( V_13 ) ;
return - V_15 ;
}
}
F_9 ( V_7 , V_16 , & V_2 ) ;
if ( V_2 == 0 && V_17 == 0 ) {
F_7 ( & V_7 -> V_13 , L_2 ) ;
return - V_15 ;
}
if ( V_17 )
V_2 = V_17 & ~ ( V_18 - 1 ) ;
F_10 ( & V_7 -> V_13 , L_3 , V_2 ) ;
V_11 = F_11 ( V_2 + V_3 , 2 ,
V_19 . V_20 ) ;
if ( V_11 )
return V_11 ;
if ( ! F_12 ( V_2 + V_3 , 2 ,
V_19 . V_20 ) ) {
F_7 ( & V_7 -> V_13 , L_4 ,
V_2 + V_3 , V_2 + V_3 + 1 ) ;
return - V_15 ;
}
if ( V_17 ) {
F_13 ( & V_7 -> V_13 , L_5 , V_2 ) ;
if ( F_14 ( V_7 , V_16 , V_2 )
!= V_21 )
goto error;
if ( F_9 ( V_7 , V_16 , & V_8 )
!= V_21 )
goto error;
if ( ( V_8 & ~ ( V_18 - 1 ) ) != V_2 ) {
F_7 ( & V_7 -> V_13 , L_6 ) ;
goto error;
}
}
if ( F_15 ( V_7 , V_22 , & V_9 )
!= V_21 )
goto error;
if ( ( V_9 & 0x80 ) == 0 ) {
F_13 ( & V_7 -> V_13 , L_7 ) ;
if ( F_16 ( V_7 , V_22 , V_9 | 0x80 )
!= V_21 )
goto error;
if ( F_15 ( V_7 , V_22 , & V_9 )
!= V_21 )
goto error;
if ( ( V_9 & 0x80 ) == 0 ) {
F_7 ( & V_7 -> V_13 , L_8 ) ;
goto error;
}
}
return 0 ;
error:
F_17 ( V_2 + V_3 , 2 ) ;
return - V_15 ;
}
static int F_18 ( struct V_23 * V_24 )
{
int V_25 ;
int V_26 = 0 ;
int V_27 = 0 ;
V_25 = F_1 ( V_28 ) + ( F_1 ( V_29 ) << 8 ) ;
if ( V_25 != 0x00 ) {
F_10 ( & V_24 -> V_13 , L_9 , V_25 ) ;
F_4 ( V_28 , V_25 & 0xff ) ;
F_4 ( V_29 , V_25 >> 8 ) ;
if ( ( V_25 = F_1 ( V_28 ) + ( F_1 ( V_29 ) << 8 ) ) != 0x00 ) {
F_10 ( & V_24 -> V_13 , L_10 , V_25 ) ;
return - V_30 ;
} else {
F_10 ( & V_24 -> V_13 , L_11 ) ;
}
}
F_4 ( V_31 , F_1 ( V_31 ) | 0x10 ) ;
do {
F_19 ( 1 ) ;
V_25 = F_1 ( V_28 ) ;
} while ( ! ( V_25 & 0x40 ) && ( V_27 ++ < V_32 ) );
if ( V_27 > V_32 ) {
F_10 ( & V_24 -> V_13 , L_12 ) ;
V_26 = - V_33 ;
}
if ( V_25 & 0x10 ) {
F_10 ( & V_24 -> V_13 , L_13 ) ;
V_26 = - V_34 ;
}
if ( V_25 & 0x20 ) {
F_7 ( & V_24 -> V_13 , L_14
L_15 ) ;
V_26 = - V_35 ;
}
V_25 = F_1 ( V_28 ) + ( F_1 ( V_29 ) << 8 ) ;
if ( V_25 != 0x00 ) {
F_4 ( V_28 , V_25 & 0xff ) ;
F_4 ( V_29 , V_25 >> 8 ) ;
}
V_25 = F_1 ( V_28 ) + ( F_1 ( V_29 ) << 8 ) ;
if ( V_25 != 0x00 )
F_10 ( & V_24 -> V_13 , L_16 , V_25 ) ;
return V_26 ;
}
static T_4 F_20 ( struct V_23 * V_24 , T_3 V_36 ,
unsigned short V_37 , char V_38 ,
T_1 V_39 , int V_40 , union V_41 * V_5 )
{
int V_42 ;
switch ( V_40 ) {
case V_43 :
F_4 ( V_44 , ( ( V_36 & 0x7f ) << 1 ) | ( V_38 & 0x01 ) ) ;
V_40 = V_45 ;
break;
case V_46 :
F_4 ( V_44 , ( ( V_36 & 0x7f ) << 1 ) | ( V_38 & 0x01 ) ) ;
if ( V_38 == V_47 )
F_4 ( V_48 , V_39 ) ;
V_40 = V_49 ;
break;
case V_50 :
F_4 ( V_44 , ( ( V_36 & 0x7f ) << 1 ) | ( V_38 & 0x01 ) ) ;
F_4 ( V_48 , V_39 ) ;
if ( V_38 == V_47 )
F_4 ( V_51 , V_5 -> V_52 ) ;
V_40 = V_53 ;
break;
case V_54 :
case V_55 :
F_4 ( V_44 , ( ( V_36 & 0x7f ) << 1 ) | ( V_38 & 0x01 ) ) ;
F_4 ( V_48 , V_39 ) ;
if ( V_38 == V_47 ) {
F_4 ( V_51 , V_5 -> V_56 & 0xff ) ;
F_4 ( V_51 + 1 ,
( V_5 -> V_56 & 0xff00 ) >> 8 ) ;
}
V_40 = ( V_40 == V_54 ) ? V_57 : V_58 ;
break;
default:
F_21 ( & V_24 -> V_13 , L_17 , V_40 ) ;
return - V_59 ;
}
F_4 ( V_31 , ( ( V_40 & 0x0E ) ) ) ;
V_42 = F_18 ( V_24 ) ;
if ( V_42 )
return V_42 ;
if ( ( V_40 != V_57 ) &&
( ( V_38 == V_47 ) || ( V_40 == V_45 ) ) )
return 0 ;
switch ( V_40 ) {
case V_49 :
case V_53 :
V_5 -> V_52 = F_1 ( V_51 ) ;
break;
case V_58 :
case V_57 :
V_5 -> V_56 = F_1 ( V_51 ) + ( F_1 ( V_51 + 1 ) << 8 ) ;
break;
}
return 0 ;
}
static T_5 F_22 ( struct V_23 * V_60 )
{
return V_61 | V_62 |
V_63 | V_64 |
V_65 ;
}
static int T_2 F_23 ( struct V_6 * V_13 , const struct V_66 * V_67 )
{
int V_68 ;
if ( F_5 ( V_13 ) ) {
F_7 ( & V_13 -> V_13 , L_18 ) ;
return - V_15 ;
}
V_69 . V_13 . V_70 = & V_13 -> V_13 ;
snprintf ( V_69 . V_20 , sizeof( V_69 . V_20 ) ,
L_19 , V_2 + V_3 ) ;
V_68 = F_24 ( & V_69 ) ;
if ( V_68 ) {
F_17 ( V_2 + V_3 , 2 ) ;
return V_68 ;
}
V_71 = F_25 ( V_13 ) ;
return - V_15 ;
}
static int T_6 F_26 ( void )
{
return F_27 ( & V_19 ) ;
}
static void T_7 F_28 ( void )
{
F_29 ( & V_19 ) ;
if ( V_71 ) {
F_30 ( & V_69 ) ;
F_17 ( V_2 + V_3 , 2 ) ;
F_8 ( V_71 ) ;
V_71 = NULL ;
}
}
