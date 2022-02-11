char * F_1 ( struct V_1 * V_2 )
{
static char V_3 [ 60 ] ;
sprintf ( V_3 , L_1 , V_2 -> V_4 [ 0 ] , V_2 -> V_4 [ 1 ] , V_2 -> V_4 [ 2 ] , V_2 -> V_4 [ 3 ] ) ;
return V_3 ;
}
int F_2 ( const char * V_5 , T_1 V_6 )
{
return ( ( V_7 == V_6 ) &&
( strncmp ( V_5 , V_8 , V_7 ) == 0 ) ) ;
}
int F_3 ( struct V_9 * V_10 )
{
return ( V_10 -> V_11 -> V_12 -> V_13 == V_10 ) ;
}
unsigned short F_4 ( unsigned short V_14 )
{
unsigned short V_15 = 0 ;
if ( ( V_14 & V_16 ) == V_17 )
V_15 |= V_18 ;
if ( ( V_14 & V_16 ) == V_19 )
V_15 |= V_18 | V_20 ;
if ( ( V_14 & V_16 ) == V_21 )
V_15 |= V_20 ;
if ( V_14 & V_22 )
V_15 |= V_23 ;
if ( V_14 & V_24 )
V_15 |= V_25 ;
if ( V_14 & V_26 )
V_15 |= V_27 ;
return V_15 ;
}
void F_5 ( struct V_9 * V_9 , struct V_28 * V_29 )
{
int V_30 ;
switch ( V_29 -> V_31 ) {
case V_32 :
V_30 = 0 ;
break;
case V_33 :
V_30 = V_34 ;
break;
case V_35 :
V_30 = V_36 ;
break;
case V_37 :
V_30 = V_38 ;
break;
default:
V_30 = 0 ;
}
V_9 -> V_39 |= V_30 ;
if ( V_29 -> V_40 != ( V_41 ) - 1 )
V_9 -> V_39 = V_29 -> V_40 | V_30 ;
if ( V_29 -> V_42 != - 1 )
V_9 -> V_43 = ( V_44 ) V_29 -> V_42 ;
if ( V_29 -> V_45 != - 1 )
V_9 -> V_46 = ( V_47 ) V_29 -> V_45 ;
if ( V_29 -> V_48 != - 1 )
V_9 -> V_49 = V_29 -> V_48 ;
if ( V_29 -> V_50 != - 1 )
V_9 -> V_51 = V_29 -> V_50 ;
if ( V_29 -> V_50 != - 1 )
V_9 -> V_52 = ( V_29 -> V_50 + 511 ) >> 9 ;
if ( V_29 -> V_53 . V_54 != - 1 )
V_9 -> V_55 = V_29 -> V_53 ;
if ( V_29 -> V_56 . V_54 != - 1 )
V_9 -> V_57 = V_29 -> V_56 ;
if ( V_29 -> V_58 . V_54 != - 1 )
V_9 -> V_59 = V_29 -> V_58 ;
}
void F_6 ( struct V_60 * V_60 , struct V_28 * V_61 )
{
unsigned int V_62 ;
V_61 -> V_40 = - 1 ;
V_61 -> V_42 = ( V_63 ) - 1 ;
V_61 -> V_45 = ( V_64 ) - 1 ;
V_61 -> V_50 = ( V_65 ) - 1 ;
V_61 -> V_53 . V_54 = ( V_66 ) - 1 ;
V_61 -> V_53 . V_67 = ( V_66 ) - 1 ;
V_61 -> V_56 . V_54 = ( V_66 ) - 1 ;
V_61 -> V_56 . V_67 = ( V_66 ) - 1 ;
V_61 -> V_58 . V_54 = ( V_66 ) - 1 ;
V_61 -> V_58 . V_67 = ( V_66 ) - 1 ;
V_61 -> V_31 = V_32 ;
V_61 -> V_68 = - 1 ;
V_61 -> V_69 = - 1 ;
V_61 -> V_70 = - 1 ;
V_61 -> V_48 = - 1 ;
V_61 -> V_71 = - 1 ;
V_61 -> V_72 = - 1 ;
V_61 -> V_73 = 0 ;
#if 0
mode = iattr->ia_mode;
if ( S_ISDIR(mode) ) {
vattr->va_type = C_VDIR;
} else if ( S_ISREG(mode) ) {
vattr->va_type = C_VREG;
} else if ( S_ISLNK(mode) ) {
vattr->va_type = C_VLNK;
} else {
vattr->va_type = C_VNON;
}
#endif
V_62 = V_60 -> V_74 ;
if ( V_62 & V_75 ) {
V_61 -> V_40 = V_60 -> V_76 ;
}
if ( V_62 & V_77 ) {
V_61 -> V_42 = ( V_63 ) V_60 -> V_78 ;
}
if ( V_62 & V_79 ) {
V_61 -> V_45 = ( V_64 ) V_60 -> V_80 ;
}
if ( V_62 & V_81 ) {
V_61 -> V_50 = V_60 -> V_82 ;
}
if ( V_62 & V_83 ) {
V_61 -> V_53 = V_60 -> V_84 ;
}
if ( V_62 & V_85 ) {
V_61 -> V_56 = V_60 -> V_86 ;
}
if ( V_62 & V_87 ) {
V_61 -> V_58 = V_60 -> V_88 ;
}
}
