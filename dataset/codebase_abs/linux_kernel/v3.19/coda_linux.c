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
unsigned short F_3 ( unsigned short V_9 )
{
unsigned short V_10 = 0 ;
if ( ( V_9 & V_11 ) == V_12 )
V_10 |= V_13 ;
if ( ( V_9 & V_11 ) == V_14 )
V_10 |= V_13 | V_15 ;
if ( ( V_9 & V_11 ) == V_16 )
V_10 |= V_15 ;
if ( V_9 & V_17 )
V_10 |= V_18 ;
if ( V_9 & V_19 )
V_10 |= V_20 ;
if ( V_9 & V_21 )
V_10 |= V_22 ;
return V_10 ;
}
void F_4 ( struct V_23 * V_23 , struct V_24 * V_25 )
{
int V_26 ;
switch ( V_25 -> V_27 ) {
case V_28 :
V_26 = 0 ;
break;
case V_29 :
V_26 = V_30 ;
break;
case V_31 :
V_26 = V_32 ;
break;
case V_33 :
V_26 = V_34 ;
break;
default:
V_26 = 0 ;
}
V_23 -> V_35 |= V_26 ;
if ( V_25 -> V_36 != ( V_37 ) - 1 )
V_23 -> V_35 = V_25 -> V_36 | V_26 ;
if ( V_25 -> V_38 != - 1 )
V_23 -> V_39 = F_5 ( & V_40 , ( V_41 ) V_25 -> V_38 ) ;
if ( V_25 -> V_42 != - 1 )
V_23 -> V_43 = F_6 ( & V_40 , ( V_44 ) V_25 -> V_42 ) ;
if ( V_25 -> V_45 != - 1 )
F_7 ( V_23 , V_25 -> V_45 ) ;
if ( V_25 -> V_46 != - 1 )
V_23 -> V_47 = V_25 -> V_46 ;
if ( V_25 -> V_46 != - 1 )
V_23 -> V_48 = ( V_25 -> V_46 + 511 ) >> 9 ;
if ( V_25 -> V_49 . V_50 != - 1 )
V_23 -> V_51 = V_25 -> V_49 ;
if ( V_25 -> V_52 . V_50 != - 1 )
V_23 -> V_53 = V_25 -> V_52 ;
if ( V_25 -> V_54 . V_50 != - 1 )
V_23 -> V_55 = V_25 -> V_54 ;
}
void F_8 ( struct V_56 * V_56 , struct V_24 * V_57 )
{
unsigned int V_58 ;
V_57 -> V_36 = - 1 ;
V_57 -> V_38 = ( V_59 ) - 1 ;
V_57 -> V_42 = ( V_60 ) - 1 ;
V_57 -> V_46 = ( V_61 ) - 1 ;
V_57 -> V_49 . V_50 = ( V_62 ) - 1 ;
V_57 -> V_49 . V_63 = ( V_62 ) - 1 ;
V_57 -> V_52 . V_50 = ( V_62 ) - 1 ;
V_57 -> V_52 . V_63 = ( V_62 ) - 1 ;
V_57 -> V_54 . V_50 = ( V_62 ) - 1 ;
V_57 -> V_54 . V_63 = ( V_62 ) - 1 ;
V_57 -> V_27 = V_28 ;
V_57 -> V_64 = - 1 ;
V_57 -> V_65 = - 1 ;
V_57 -> V_66 = - 1 ;
V_57 -> V_45 = - 1 ;
V_57 -> V_67 = - 1 ;
V_57 -> V_68 = - 1 ;
V_57 -> V_69 = 0 ;
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
V_58 = V_56 -> V_70 ;
if ( V_58 & V_71 ) {
V_57 -> V_36 = V_56 -> V_72 ;
}
if ( V_58 & V_73 ) {
V_57 -> V_38 = ( V_59 ) F_9 ( & V_40 , V_56 -> V_74 ) ;
}
if ( V_58 & V_75 ) {
V_57 -> V_42 = ( V_60 ) F_10 ( & V_40 , V_56 -> V_76 ) ;
}
if ( V_58 & V_77 ) {
V_57 -> V_46 = V_56 -> V_78 ;
}
if ( V_58 & V_79 ) {
V_57 -> V_49 = V_56 -> V_80 ;
}
if ( V_58 & V_81 ) {
V_57 -> V_52 = V_56 -> V_82 ;
}
if ( V_58 & V_83 ) {
V_57 -> V_54 = V_56 -> V_84 ;
}
}
