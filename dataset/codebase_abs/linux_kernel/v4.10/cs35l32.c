static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
case V_6 ... V_7 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_8 :
case V_9 ... V_10 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_9 ... V_10 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_11 * V_12 , unsigned int V_13 )
{
struct V_14 * V_15 = V_12 -> V_15 ;
switch ( V_13 & V_16 ) {
case V_17 :
F_5 ( V_15 , V_6 ,
V_18 ,
V_18 ) ;
break;
case V_19 :
F_5 ( V_15 , V_6 ,
V_18 , 0 ) ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_6 ( struct V_11 * V_21 , int V_22 )
{
struct V_14 * V_15 = V_21 -> V_15 ;
return F_5 ( V_15 , V_23 ,
V_24 , V_22 << 3 ) ;
}
static int F_7 ( struct V_14 * V_15 ,
int V_25 , int V_26 , unsigned int V_27 , int V_28 )
{
unsigned int V_29 ;
switch ( V_27 ) {
case 6000000 :
V_29 = V_30 ;
break;
case 12000000 :
V_29 = V_31 | V_30 ;
break;
case 6144000 :
V_29 = 0 ;
break;
case 12288000 :
V_29 = V_31 ;
break;
default:
return - V_20 ;
}
return F_5 ( V_15 , V_32 ,
V_31 | V_33 , V_29 ) ;
}
static int F_8 ( struct V_34 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = V_34 -> V_2 . V_39 ;
unsigned int V_29 ;
if ( F_9 ( V_38 , L_1 , & V_29 ) >= 0 )
V_36 -> V_40 = V_29 ;
if ( F_9 ( V_38 , L_2 , & V_29 ) )
V_29 = - 1u ;
switch ( V_29 ) {
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_36 -> V_45 = V_29 ;
break;
case - 1u :
default:
F_10 ( & V_34 -> V_2 ,
L_3 , V_29 ) ;
V_36 -> V_45 = V_43 ;
}
if ( F_9 ( V_38 , L_4 , & V_29 ) )
V_29 = - 1u ;
switch ( V_29 ) {
case V_46 :
case V_47 :
case V_48 :
case V_49 :
V_36 -> V_50 = V_29 ;
break;
case - 1u :
default:
F_10 ( & V_34 -> V_2 ,
L_5 , V_29 ) ;
V_36 -> V_50 = V_48 ;
}
if ( F_9 ( V_38 , L_6 , & V_29 ) )
V_29 = - 1u ;
switch ( V_29 ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_36 -> V_55 = V_29 ;
break;
case - 1u :
default:
F_10 ( & V_34 -> V_2 ,
L_7 , V_29 ) ;
V_36 -> V_55 = V_53 ;
}
if ( F_9 ( V_38 , L_8 , & V_29 ) )
V_29 = - 1u ;
switch ( V_29 ) {
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
V_36 -> V_62 = V_29 ;
break;
case - 1u :
default:
F_10 ( & V_34 -> V_2 ,
L_9 , V_29 ) ;
V_36 -> V_62 = V_59 ;
}
return 0 ;
}
static int F_11 ( struct V_34 * V_34 ,
const struct V_63 * V_64 )
{
struct V_65 * V_66 ;
struct V_35 * V_36 =
F_12 ( & V_34 -> V_2 ) ;
int V_67 , V_68 ;
unsigned int V_69 = 0 ;
unsigned int V_3 ;
V_66 = F_13 ( & V_34 -> V_2 , sizeof( struct V_65 ) ,
V_70 ) ;
if ( ! V_66 ) {
F_10 ( & V_34 -> V_2 , L_10 ) ;
return - V_71 ;
}
F_14 ( V_34 , V_66 ) ;
V_66 -> V_72 = F_15 ( V_34 , & V_73 ) ;
if ( F_16 ( V_66 -> V_72 ) ) {
V_67 = F_17 ( V_66 -> V_72 ) ;
F_10 ( & V_34 -> V_2 , L_11 , V_67 ) ;
return V_67 ;
}
if ( V_36 ) {
V_66 -> V_36 = * V_36 ;
} else {
V_36 = F_13 ( & V_34 -> V_2 ,
sizeof( struct V_35 ) ,
V_70 ) ;
if ( ! V_36 ) {
F_10 ( & V_34 -> V_2 , L_12 ) ;
return - V_71 ;
}
if ( V_34 -> V_2 . V_39 ) {
V_67 = F_8 ( V_34 ,
& V_66 -> V_36 ) ;
if ( V_67 != 0 )
return V_67 ;
}
}
for ( V_68 = 0 ; V_68 < F_18 ( V_66 -> V_74 ) ; V_68 ++ )
V_66 -> V_74 [ V_68 ] . V_75 = V_76 [ V_68 ] ;
V_67 = F_19 ( & V_34 -> V_2 ,
F_18 ( V_66 -> V_74 ) ,
V_66 -> V_74 ) ;
if ( V_67 != 0 ) {
F_10 ( & V_34 -> V_2 ,
L_13 , V_67 ) ;
return V_67 ;
}
V_67 = F_20 ( F_18 ( V_66 -> V_74 ) ,
V_66 -> V_74 ) ;
if ( V_67 != 0 ) {
F_10 ( & V_34 -> V_2 ,
L_14 , V_67 ) ;
return V_67 ;
}
V_66 -> V_77 = F_21 ( & V_34 -> V_2 ,
L_15 , V_78 ) ;
if ( F_16 ( V_66 -> V_77 ) )
return F_17 ( V_66 -> V_77 ) ;
F_22 ( V_66 -> V_77 , 1 ) ;
V_67 = F_23 ( V_66 -> V_72 , V_4 , & V_3 ) ;
V_69 = ( V_3 & 0xFF ) << 12 ;
V_67 = F_23 ( V_66 -> V_72 , V_79 , & V_3 ) ;
V_69 |= ( V_3 & 0xFF ) << 4 ;
V_67 = F_23 ( V_66 -> V_72 , V_80 , & V_3 ) ;
V_69 |= ( V_3 & 0xF0 ) >> 4 ;
if ( V_69 != V_81 ) {
V_67 = - V_82 ;
F_10 ( & V_34 -> V_2 ,
L_16 ,
V_69 , V_81 ) ;
return V_67 ;
}
V_67 = F_23 ( V_66 -> V_72 , V_8 , & V_3 ) ;
if ( V_67 < 0 ) {
F_10 ( & V_34 -> V_2 , L_17 ) ;
return V_67 ;
}
V_67 = F_24 ( V_66 -> V_72 , V_83 ,
F_18 ( V_83 ) ) ;
if ( V_67 < 0 ) {
F_10 ( & V_34 -> V_2 , L_18 ) ;
return V_67 ;
}
F_25 ( & V_34 -> V_2 ,
L_19 , V_3 & 0xFF ) ;
if ( V_66 -> V_36 . V_45 )
F_26 ( V_66 -> V_72 , V_5 ,
V_84 ,
V_66 -> V_36 . V_45 ) ;
if ( V_66 -> V_36 . V_40 )
F_26 ( V_66 -> V_72 , V_6 ,
V_85 ,
V_66 -> V_36 . V_40 << 3 ) ;
if ( V_66 -> V_36 . V_50 )
F_26 ( V_66 -> V_72 , V_6 ,
V_86 ,
V_66 -> V_36 . V_50 << 4 ) ;
if ( V_66 -> V_36 . V_62 )
F_26 ( V_66 -> V_72 , V_87 ,
V_88 ,
V_66 -> V_36 . V_62 << 1 ) ;
if ( V_66 -> V_36 . V_55 )
F_26 ( V_66 -> V_72 , V_87 ,
V_89 ,
V_66 -> V_36 . V_55 << 4 ) ;
F_26 ( V_66 -> V_72 , V_90 , V_91 ,
V_91 ) ;
V_67 = F_23 ( V_66 -> V_72 , V_9 , & V_3 ) ;
V_67 = F_27 ( & V_34 -> V_2 ,
& V_92 , V_93 ,
F_18 ( V_93 ) ) ;
if ( V_67 < 0 )
goto V_94;
return 0 ;
V_94:
F_28 ( F_18 ( V_66 -> V_74 ) ,
V_66 -> V_74 ) ;
return V_67 ;
}
static int F_29 ( struct V_34 * V_34 )
{
struct V_65 * V_66 = F_30 ( V_34 ) ;
F_31 ( & V_34 -> V_2 ) ;
F_22 ( V_66 -> V_77 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_33 ( V_2 ) ;
F_34 ( V_66 -> V_72 , true ) ;
F_35 ( V_66 -> V_72 ) ;
F_22 ( V_66 -> V_77 , 0 ) ;
F_28 ( F_18 ( V_66 -> V_74 ) ,
V_66 -> V_74 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_33 ( V_2 ) ;
int V_67 ;
V_67 = F_20 ( F_18 ( V_66 -> V_74 ) ,
V_66 -> V_74 ) ;
if ( V_67 != 0 ) {
F_10 ( V_2 , L_14 ,
V_67 ) ;
return V_67 ;
}
F_22 ( V_66 -> V_77 , 1 ) ;
F_34 ( V_66 -> V_72 , false ) ;
F_37 ( V_66 -> V_72 ) ;
return 0 ;
}
