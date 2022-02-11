static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
unsigned char V_5 ;
if ( ( V_2 -> V_6 == V_7 ) &&
( V_2 -> V_8 == V_9 ) )
V_10 = 1 ;
if ( F_2 ( V_11 ) ) {
F_3 ( & V_2 -> V_12 ,
L_1 ) ;
return - V_13 ;
}
if ( F_2 ( V_14 ) &&
V_2 -> V_6 == V_15 ) {
F_3 ( & V_2 -> V_12 , L_2
L_3
L_4 ) ;
return - V_13 ;
}
if ( V_16 ) {
V_17 = V_16 & 0xfff0 ;
V_18 = 0 ;
} else {
F_4 ( V_2 , V_19 , & V_17 ) ;
V_17 &= 0xfff0 ;
if( V_17 == 0 ) {
F_3 ( & V_2 -> V_12 , L_5
L_6
L_7 ) ;
return - V_20 ;
}
}
if ( F_5 ( V_17 , V_21 , V_22 . V_23 ) )
return - V_20 ;
if ( ! F_6 ( V_17 , V_21 , V_22 . V_23 ) ) {
F_3 ( & V_2 -> V_12 , L_8 ,
V_17 ) ;
return - V_24 ;
}
F_7 ( V_2 , V_25 , & V_5 ) ;
if ( V_16 ) {
F_8 ( V_2 , V_25 , V_5 & 0xfe ) ;
F_9 ( V_2 , V_19 , V_17 ) ;
F_8 ( V_2 , V_25 , V_5 | 0x01 ) ;
F_10 ( & V_2 -> V_12 , L_9
L_10 , V_17 ) ;
} else if ( ( V_5 & 1 ) == 0 ) {
if ( V_18 ) {
F_8 ( V_2 , V_25 ,
V_5 | 1 ) ;
F_11 ( V_26 , & V_2 -> V_12 ,
L_11
L_12 ) ;
} else {
F_3 ( & V_2 -> V_12 ,
L_13 ) ;
F_12 ( V_17 , V_21 ) ;
V_17 = 0 ;
return - V_20 ;
}
}
if ( ( ( V_5 & 0x0E ) == 8 ) || ( ( V_5 & 0x0E ) == 2 ) )
F_13 ( & V_2 -> V_12 , L_14 ) ;
else if ( ( V_5 & 0x0E ) == 0 )
F_13 ( & V_2 -> V_12 , L_15 ) ;
else
F_3 ( & V_2 -> V_12 , L_16
L_17 ) ;
F_7 ( V_2 , V_27 , & V_5 ) ;
F_10 ( & V_2 -> V_12 ,
L_18 ,
V_17 , V_5 ) ;
return 0 ;
}
static int T_1 F_14 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
unsigned short V_28 = 0xcd6 ;
T_2 V_29 , V_30 , V_31 , V_32 = 0x10 , V_33 = 0x2c ;
if ( V_18 || V_16 ) {
F_3 ( & V_2 -> V_12 , L_19
L_20 ) ;
return - V_34 ;
}
if ( ! F_6 ( V_28 , 2 , L_21 ) ) {
F_3 ( & V_2 -> V_12 , L_22
L_23 , V_28 ) ;
return - V_24 ;
}
F_15 ( V_33 , V_28 ) ;
V_29 = F_16 ( V_28 + 1 ) ;
F_15 ( V_33 + 1 , V_28 ) ;
V_30 = F_16 ( V_28 + 1 ) ;
F_12 ( V_28 , 2 ) ;
if ( ( V_29 & 1 ) == 0 ) {
F_3 ( & V_2 -> V_12 ,
L_13 ) ;
return - V_20 ;
}
V_17 = ( ( V_30 << 8 ) | V_29 ) & 0xffe0 ;
if ( F_5 ( V_17 , V_21 , V_22 . V_23 ) )
return - V_20 ;
if ( ! F_6 ( V_17 , V_21 , V_22 . V_23 ) ) {
F_3 ( & V_2 -> V_12 , L_8 ,
V_17 ) ;
return - V_24 ;
}
if ( ! F_6 ( V_17 + V_32 , 1 , L_24 ) ) {
F_3 ( & V_2 -> V_12 , L_25
L_23 , V_17 + V_32 ) ;
F_12 ( V_17 , V_21 ) ;
V_17 = 0 ;
return - V_24 ;
}
V_31 = F_16 ( V_17 + V_32 ) ;
F_12 ( V_17 + V_32 , 1 ) ;
if ( V_31 & 1 )
F_13 ( & V_2 -> V_12 , L_26 ) ;
else
F_13 ( & V_2 -> V_12 , L_27 ) ;
F_10 ( & V_2 -> V_12 ,
L_18 ,
V_17 , V_31 >> 4 ) ;
return 0 ;
}
static int F_17 ( void )
{
int V_5 ;
int V_35 = 0 ;
int V_36 = 0 ;
F_13 ( & V_37 . V_12 , L_28
L_29 , F_16 ( V_38 ) ,
F_16 ( V_39 ) , F_16 ( V_40 ) , F_16 ( V_41 ) ,
F_16 ( V_42 ) ) ;
if ( ( V_5 = F_16 ( V_43 ) ) != 0x00 ) {
F_13 ( & V_37 . V_12 , L_30
L_31 , V_5 ) ;
F_15 ( V_5 , V_43 ) ;
if ( ( V_5 = F_16 ( V_43 ) ) != 0x00 ) {
F_3 ( & V_37 . V_12 , L_32 , V_5 ) ;
return - V_24 ;
} else {
F_13 ( & V_37 . V_12 , L_33 ) ;
}
}
F_15 ( F_18 ( V_38 ) | 0x040 , V_38 ) ;
if ( V_10 )
F_19 ( 2 ) ;
else
F_19 ( 1 ) ;
while ( ( ++ V_36 < V_44 ) &&
( ( V_5 = F_16 ( V_43 ) ) & 0x01 ) )
F_19 ( 1 ) ;
if ( V_36 == V_44 ) {
F_3 ( & V_37 . V_12 , L_34 ) ;
V_35 = - V_45 ;
}
if ( V_5 & 0x10 ) {
V_35 = - V_46 ;
F_3 ( & V_37 . V_12 , L_35 ) ;
}
if ( V_5 & 0x08 ) {
V_35 = - V_46 ;
F_13 ( & V_37 . V_12 , L_36
L_37 ) ;
}
if ( V_5 & 0x04 ) {
V_35 = - V_47 ;
F_13 ( & V_37 . V_12 , L_38 ) ;
}
if ( F_16 ( V_43 ) != 0x00 )
F_15 ( F_18 ( V_43 ) , V_43 ) ;
if ( ( V_5 = F_16 ( V_43 ) ) != 0x00 ) {
F_3 ( & V_37 . V_12 , L_39
L_40 , V_5 ) ;
}
F_13 ( & V_37 . V_12 , L_41
L_29 , F_16 ( V_38 ) ,
F_16 ( V_39 ) , F_16 ( V_40 ) , F_16 ( V_41 ) ,
F_16 ( V_42 ) ) ;
return V_35 ;
}
static T_3 F_20 ( struct V_48 * V_49 , T_4 V_50 ,
unsigned short V_51 , char V_52 ,
T_2 V_53 , int V_54 , union V_55 * V_56 )
{
int V_57 , V_58 ;
int V_59 ;
switch ( V_54 ) {
case V_60 :
F_15 ( ( V_50 << 1 ) | V_52 ,
V_40 ) ;
V_54 = V_61 ;
break;
case V_62 :
F_15 ( ( V_50 << 1 ) | V_52 ,
V_40 ) ;
if ( V_52 == V_63 )
F_15 ( V_53 , V_39 ) ;
V_54 = V_64 ;
break;
case V_65 :
F_15 ( ( V_50 << 1 ) | V_52 ,
V_40 ) ;
F_15 ( V_53 , V_39 ) ;
if ( V_52 == V_63 )
F_15 ( V_56 -> V_66 , V_41 ) ;
V_54 = V_67 ;
break;
case V_68 :
F_15 ( ( V_50 << 1 ) | V_52 ,
V_40 ) ;
F_15 ( V_53 , V_39 ) ;
if ( V_52 == V_63 ) {
F_15 ( V_56 -> V_69 & 0xff , V_41 ) ;
F_15 ( ( V_56 -> V_69 & 0xff00 ) >> 8 , V_42 ) ;
}
V_54 = V_70 ;
break;
case V_71 :
F_15 ( ( V_50 << 1 ) | V_52 ,
V_40 ) ;
F_15 ( V_53 , V_39 ) ;
if ( V_52 == V_63 ) {
V_58 = V_56 -> V_72 [ 0 ] ;
if ( V_58 == 0 || V_58 > V_73 )
return - V_34 ;
F_15 ( V_58 , V_41 ) ;
V_57 = F_16 ( V_38 ) ;
for ( V_57 = 1 ; V_57 <= V_58 ; V_57 ++ )
F_15 ( V_56 -> V_72 [ V_57 ] , V_74 ) ;
}
V_54 = V_75 ;
break;
default:
F_21 ( & V_49 -> V_12 , L_42 , V_54 ) ;
return - V_76 ;
}
F_15 ( ( V_54 & 0x1C ) + ( V_77 & 1 ) , V_38 ) ;
V_59 = F_17 () ;
if ( V_59 )
return V_59 ;
if ( ( V_52 == V_63 ) || ( V_54 == V_61 ) )
return 0 ;
switch ( V_54 ) {
case V_64 :
case V_67 :
V_56 -> V_66 = F_16 ( V_41 ) ;
break;
case V_70 :
V_56 -> V_69 = F_16 ( V_41 ) + ( F_16 ( V_42 ) << 8 ) ;
break;
case V_75 :
V_56 -> V_72 [ 0 ] = F_16 ( V_41 ) ;
if ( V_56 -> V_72 [ 0 ] == 0 || V_56 -> V_72 [ 0 ] > V_73 )
return - V_78 ;
V_57 = F_16 ( V_38 ) ;
for ( V_57 = 1 ; V_57 <= V_56 -> V_72 [ 0 ] ; V_57 ++ )
V_56 -> V_72 [ V_57 ] = F_16 ( V_74 ) ;
break;
}
return 0 ;
}
static T_5 F_22 ( struct V_48 * V_79 )
{
return V_80 | V_81 |
V_82 | V_83 |
V_84 ;
}
static int T_1 F_23 ( struct V_1 * V_12 ,
const struct V_3 * V_4 )
{
int V_85 ;
if ( ( V_12 -> V_6 == V_86 &&
V_12 -> V_8 == V_87 &&
V_12 -> V_88 >= 0x40 ) ||
V_12 -> V_6 == V_89 )
V_85 = F_14 ( V_12 , V_4 ) ;
else
V_85 = F_1 ( V_12 , V_4 ) ;
if ( V_85 )
return V_85 ;
V_37 . V_12 . V_90 = & V_12 -> V_12 ;
snprintf ( V_37 . V_23 , sizeof( V_37 . V_23 ) ,
L_43 , V_17 ) ;
if ( ( V_85 = F_24 ( & V_37 ) ) ) {
F_3 ( & V_12 -> V_12 , L_44 ) ;
F_12 ( V_17 , V_21 ) ;
V_17 = 0 ;
}
return V_85 ;
}
static void T_6 F_25 ( struct V_1 * V_12 )
{
if ( V_17 ) {
F_26 ( & V_37 ) ;
F_12 ( V_17 , V_21 ) ;
V_17 = 0 ;
}
}
static int T_7 F_27 ( void )
{
return F_28 ( & V_22 ) ;
}
static void T_8 F_29 ( void )
{
F_30 ( & V_22 ) ;
}
