static void F_1 ( const char * V_1 , T_1 V_2 )
{
F_2 ( & V_3 . V_4 , L_1
L_2 , V_1 , F_3 ( V_5 ) , F_3 ( V_6 ) ,
F_3 ( V_7 ) , F_3 ( V_8 ) , F_3 ( V_9 ) ,
F_3 ( V_10 ) ) ;
if ( V_2 == V_11
|| V_2 == V_12 ) {
int V_13 ;
F_2 ( & V_3 . V_4 , L_3 ) ;
for ( V_13 = 0 ; V_13 < V_14 / 2 ; V_13 ++ )
F_4 ( L_4 , F_3 ( V_15 ) ) ;
F_4 ( L_5 ) ;
F_2 ( & V_3 . V_4 , L_6 ) ;
for (; V_13 < V_14 - 1 ; V_13 ++ )
F_4 ( L_4 , F_3 ( V_15 ) ) ;
F_4 ( L_7 , F_3 ( V_15 ) ) ;
}
}
static inline void F_1 ( const char * V_1 , T_1 V_2 ) { }
static int F_5 ( T_1 V_2 )
{
int V_16 ;
int V_17 = 0 ;
int V_18 = 0 ;
F_1 ( L_8 , V_2 ) ;
if ( ( V_16 = F_3 ( V_5 ) ) & 0x1F ) {
F_2 ( & V_3 . V_4 , L_9
L_10 , V_16 ) ;
F_6 ( V_16 , V_5 ) ;
if ( ( V_16 = F_3 ( V_5 ) ) & 0x1F ) {
F_7 ( & V_3 . V_4 , L_11
L_12 , V_16 ) ;
return - V_19 ;
}
}
F_6 ( 0x40 | V_2 , V_6 ) ;
do {
F_8 ( 1 ) ;
V_16 = F_3 ( V_5 ) ;
} while ( ( V_16 & 0x01 ) && ( ++ V_18 < V_20 ) );
if ( V_18 == V_20 ) {
V_17 = - V_21 ;
F_7 ( & V_3 . V_4 , L_13 ) ;
}
if ( V_16 & 0x10 ) {
V_17 = - V_22 ;
F_7 ( & V_3 . V_4 , L_14 ,
V_2 ) ;
}
if ( V_16 & 0x08 ) {
V_17 = - V_22 ;
F_7 ( & V_3 . V_4 , L_15 ) ;
}
if ( V_16 & 0x04 ) {
V_17 = - V_23 ;
F_2 ( & V_3 . V_4 , L_16 ) ;
}
if ( V_16 & 0x1F )
F_6 ( V_16 , V_5 ) ;
F_1 ( L_17 , V_2 ) ;
return V_17 ;
}
static T_2 F_9 ( struct V_24 * V_25 , T_3 V_26 ,
unsigned short V_27 , char V_28 , T_1 V_29 ,
int V_2 , union V_30 * V_31 )
{
int V_13 ;
int V_32 ;
switch ( V_2 ) {
case V_33 :
V_2 = V_34 ;
break;
case V_35 :
if ( V_28 == V_36 )
F_6 ( V_29 , V_7 ) ;
V_2 = V_37 ;
break;
case V_38 :
F_6 ( V_29 , V_7 ) ;
if ( V_28 == V_36 )
F_6 ( V_31 -> V_39 , V_9 ) ;
V_2 = V_40 ;
break;
case V_41 :
F_6 ( V_29 , V_7 ) ;
if ( V_28 == V_36 ) {
F_6 ( V_31 -> V_42 & 0xff , V_9 ) ;
F_6 ( ( V_31 -> V_42 & 0xff00 ) >> 8 , V_10 ) ;
}
V_2 = V_43 ;
break;
case V_44 :
F_6 ( V_29 , V_7 ) ;
F_6 ( V_31 -> V_42 & 0xff , V_9 ) ;
F_6 ( ( V_31 -> V_42 & 0xff00 ) >> 8 , V_10 ) ;
V_2 = V_45 ;
break;
case V_46 :
if ( ! ( V_47 & V_48 ) )
goto V_49;
if ( V_28 == V_50 )
F_6 ( V_31 -> V_51 [ 0 ] , V_9 ) ;
case V_52 :
F_6 ( V_29 , V_7 ) ;
if ( V_28 == V_36 ) {
T_1 V_53 = V_31 -> V_51 [ 0 ] ;
if ( V_53 > V_14 )
V_53 = V_14 ;
F_6 ( V_53 , V_9 ) ;
F_3 ( V_6 ) ;
for ( V_13 = 1 ; V_13 <= V_53 ; V_13 ++ )
F_6 ( V_31 -> V_51 [ V_13 ] , V_15 ) ;
}
V_2 = ( V_2 == V_46 ) ?
V_12 : V_11 ;
break;
default:
goto V_49;
}
F_6 ( ( ( V_26 & 0x7f ) << 1 ) | V_28 , V_8 ) ;
V_32 = F_5 ( V_2 ) ;
if ( V_32 )
return V_32 ;
if ( V_2 == V_45 )
V_28 = V_50 ;
if ( ( V_28 == V_36 ) || ( V_2 == V_34 ) )
return 0 ;
switch ( V_2 ) {
case V_37 :
case V_40 :
V_31 -> V_39 = F_3 ( V_9 ) ;
break;
case V_43 :
case V_45 :
V_31 -> V_42 = F_3 ( V_9 ) + ( F_3 ( V_10 ) << 8 ) ;
break;
case V_12 :
case V_11 :
V_31 -> V_51 [ 0 ] = F_3 ( V_9 ) ;
if ( V_31 -> V_51 [ 0 ] > V_14 )
V_31 -> V_51 [ 0 ] = V_14 ;
F_3 ( V_6 ) ;
for ( V_13 = 1 ; V_13 <= V_31 -> V_51 [ 0 ] ; V_13 ++ )
V_31 -> V_51 [ V_13 ] = F_3 ( V_15 ) ;
break;
}
return 0 ;
V_49:
F_10 ( & V_3 . V_4 , L_18 ,
V_2 ) ;
return - V_54 ;
}
static T_4 F_11 ( struct V_24 * V_55 )
{
T_4 V_56 = V_57 | V_58 |
V_59 | V_60 |
V_44 | V_61 ;
if ( V_47 & V_48 )
V_56 |= V_62 ;
return V_56 ;
}
static int T_5 F_12 ( struct V_63 * V_64 ,
const struct V_65 * V_66 )
{
unsigned char V_16 ;
int error ;
if ( V_67 ) {
V_68 = V_67 & 0xfff0 ;
V_69 = 0 ;
goto V_70;
}
if ( ( F_13 ( V_64 , V_66 -> V_71 , & V_68 ) ) ||
! ( V_68 & 0x0001 ) ) {
if ( V_66 -> V_72 == V_73 &&
! F_13 ( V_64 , V_74 , & V_68 ) &&
( V_68 & 0x0001 ) ) {
V_75 = 0x84 ;
} else {
F_7 ( & V_64 -> V_4 , L_19
L_20 ) ;
return - V_76 ;
}
}
V_68 &= 0xfff0 ;
if ( V_68 == 0 ) {
F_7 ( & V_64 -> V_4 , L_21
L_22
L_23 ) ;
return - V_76 ;
}
V_70:
error = F_14 ( V_68 , 8 , V_77 . V_78 ) ;
if ( error )
return - V_76 ;
if ( ! F_15 ( V_68 , 8 , V_77 . V_78 ) ) {
F_7 ( & V_64 -> V_4 , L_24 ,
V_68 ) ;
return - V_76 ;
}
F_16 ( V_64 , V_75 , & V_16 ) ;
if ( V_67 ) {
F_17 ( V_64 , V_75 , V_16 & 0xfe ) ;
F_18 ( V_64 , V_66 -> V_71 , V_68 ) ;
F_17 ( V_64 , V_75 , V_16 | 0x01 ) ;
F_10 ( & V_64 -> V_4 , L_25
L_26 , V_68 ) ;
} else if ( ! ( V_16 & 0x01 ) ) {
if ( V_69 ) {
F_17 ( V_64 , V_75 , V_16 | 0x01 ) ;
F_19 ( & V_64 -> V_4 , L_27 ) ;
} else {
F_7 ( & V_64 -> V_4 , L_28
L_29
L_30 ) ;
error = - V_76 ;
goto V_79;
}
}
F_2 ( & V_64 -> V_4 , L_31 , V_68 ) ;
switch ( V_64 -> V_72 ) {
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
V_47 |= V_48 ;
break;
case V_91 :
if ( V_64 -> V_92 >= 0x40 )
V_47 |= V_48 ;
break;
}
V_3 . V_4 . V_93 = & V_64 -> V_4 ;
snprintf ( V_3 . V_78 , sizeof( V_3 . V_78 ) ,
L_32 , V_68 ) ;
V_94 = F_20 ( V_64 ) ;
error = F_21 ( & V_3 ) ;
if ( error ) {
F_22 ( V_94 ) ;
V_94 = NULL ;
goto V_79;
}
return - V_76 ;
V_79:
V_79 ( V_68 , 8 ) ;
return error ;
}
static int T_6 F_23 ( void )
{
return F_24 ( & V_77 ) ;
}
static void T_7 F_25 ( void )
{
F_26 ( & V_77 ) ;
if ( V_94 != NULL ) {
F_27 ( & V_3 ) ;
V_79 ( V_68 , 8 ) ;
F_22 ( V_94 ) ;
V_94 = NULL ;
}
}
