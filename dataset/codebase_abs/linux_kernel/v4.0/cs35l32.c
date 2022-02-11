static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_31 * V_32 , unsigned int V_33 )
{
struct V_34 * V_35 = V_32 -> V_35 ;
switch ( V_33 & V_36 ) {
case V_37 :
F_5 ( V_35 , V_17 ,
V_38 ,
V_38 ) ;
break;
case V_39 :
F_5 ( V_35 , V_17 ,
V_38 , 0 ) ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static int F_6 ( struct V_31 * V_41 , int V_42 )
{
struct V_34 * V_35 = V_41 -> V_35 ;
return F_5 ( V_35 , V_10 ,
V_43 , V_42 << 3 ) ;
}
static int F_7 ( struct V_34 * V_35 ,
int V_44 , int V_45 , unsigned int V_46 , int V_47 )
{
unsigned int V_48 ;
switch ( V_46 ) {
case 6000000 :
V_48 = V_49 ;
break;
case 12000000 :
V_48 = V_50 | V_49 ;
break;
case 6144000 :
V_48 = 0 ;
break;
case 12288000 :
V_48 = V_50 ;
break;
default:
return - V_40 ;
}
return F_5 ( V_35 , V_11 ,
V_50 | V_51 , V_48 ) ;
}
static int F_8 ( struct V_52 * V_52 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = V_52 -> V_2 . V_57 ;
unsigned int V_48 ;
if ( F_9 ( V_56 , L_1 , & V_48 ) >= 0 )
V_54 -> V_58 = V_48 ;
F_9 ( V_56 , L_2 , & V_48 ) ;
switch ( V_48 ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
V_54 -> V_63 = V_48 ;
break;
default:
F_10 ( & V_52 -> V_2 ,
L_3 , V_48 ) ;
V_54 -> V_63 = V_61 ;
}
F_9 ( V_56 , L_4 , & V_48 ) ;
switch ( V_48 ) {
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_54 -> V_68 = V_48 ;
break;
default:
F_10 ( & V_52 -> V_2 ,
L_5 , V_48 ) ;
V_54 -> V_68 = V_66 ;
}
F_9 ( V_56 , L_6 , & V_48 ) ;
switch ( V_48 ) {
case V_69 :
case V_70 :
case V_71 :
case V_72 :
V_54 -> V_73 = V_48 ;
break;
default:
F_10 ( & V_52 -> V_2 ,
L_7 , V_48 ) ;
V_54 -> V_73 = V_71 ;
}
F_9 ( V_56 , L_8 , & V_48 ) ;
switch ( V_48 ) {
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
V_54 -> V_80 = V_48 ;
break;
default:
F_10 ( & V_52 -> V_2 ,
L_9 , V_48 ) ;
V_54 -> V_80 = V_77 ;
}
return 0 ;
}
static int F_11 ( struct V_52 * V_52 ,
const struct V_81 * V_82 )
{
struct V_83 * V_84 ;
struct V_53 * V_54 =
F_12 ( & V_52 -> V_2 ) ;
int V_85 , V_86 ;
unsigned int V_87 = 0 ;
unsigned int V_3 ;
V_84 = F_13 ( & V_52 -> V_2 , sizeof( struct V_83 ) ,
V_88 ) ;
if ( ! V_84 ) {
F_10 ( & V_52 -> V_2 , L_10 ) ;
return - V_89 ;
}
F_14 ( V_52 , V_84 ) ;
V_84 -> V_90 = F_15 ( V_52 , & V_91 ) ;
if ( F_16 ( V_84 -> V_90 ) ) {
V_85 = F_17 ( V_84 -> V_90 ) ;
F_10 ( & V_52 -> V_2 , L_11 , V_85 ) ;
return V_85 ;
}
if ( V_54 ) {
V_84 -> V_54 = * V_54 ;
} else {
V_54 = F_13 ( & V_52 -> V_2 ,
sizeof( struct V_53 ) ,
V_88 ) ;
if ( ! V_54 ) {
F_10 ( & V_52 -> V_2 , L_12 ) ;
return - V_89 ;
}
if ( V_52 -> V_2 . V_57 ) {
V_85 = F_8 ( V_52 ,
& V_84 -> V_54 ) ;
if ( V_85 != 0 )
return V_85 ;
}
}
for ( V_86 = 0 ; V_86 < F_18 ( V_84 -> V_92 ) ; V_86 ++ )
V_84 -> V_92 [ V_86 ] . V_93 = V_94 [ V_86 ] ;
V_85 = F_19 ( & V_52 -> V_2 ,
F_18 ( V_84 -> V_92 ) ,
V_84 -> V_92 ) ;
if ( V_85 != 0 ) {
F_10 ( & V_52 -> V_2 ,
L_13 , V_85 ) ;
return V_85 ;
}
V_85 = F_20 ( F_18 ( V_84 -> V_92 ) ,
V_84 -> V_92 ) ;
if ( V_85 != 0 ) {
F_10 ( & V_52 -> V_2 ,
L_14 , V_85 ) ;
return V_85 ;
}
V_84 -> V_95 = F_21 ( & V_52 -> V_2 ,
L_15 ) ;
if ( F_16 ( V_84 -> V_95 ) ) {
V_85 = F_17 ( V_84 -> V_95 ) ;
if ( V_85 != - V_96 && V_85 != - V_97 )
return V_85 ;
V_84 -> V_95 = NULL ;
} else {
V_85 = F_22 ( V_84 -> V_95 , 0 ) ;
if ( V_85 )
return V_85 ;
F_23 ( V_84 -> V_95 , 1 ) ;
}
V_85 = F_24 ( V_84 -> V_90 , V_4 , & V_3 ) ;
V_87 = ( V_3 & 0xFF ) << 12 ;
V_85 = F_24 ( V_84 -> V_90 , V_5 , & V_3 ) ;
V_87 |= ( V_3 & 0xFF ) << 4 ;
V_85 = F_24 ( V_84 -> V_90 , V_6 , & V_3 ) ;
V_87 |= ( V_3 & 0xF0 ) >> 4 ;
if ( V_87 != V_98 ) {
V_85 = - V_99 ;
F_10 ( & V_52 -> V_2 ,
L_16 ,
V_87 , V_98 ) ;
return V_85 ;
}
V_85 = F_24 ( V_84 -> V_90 , V_8 , & V_3 ) ;
if ( V_85 < 0 ) {
F_10 ( & V_52 -> V_2 , L_17 ) ;
return V_85 ;
}
V_85 = F_25 ( V_84 -> V_90 , V_100 ,
F_18 ( V_100 ) ) ;
if ( V_85 < 0 ) {
F_10 ( & V_52 -> V_2 , L_18 ) ;
return V_85 ;
}
F_26 ( & V_52 -> V_2 ,
L_19 , V_3 & 0xFF ) ;
if ( V_84 -> V_54 . V_63 )
F_27 ( V_84 -> V_90 , V_16 ,
V_101 ,
V_84 -> V_54 . V_63 ) ;
if ( V_84 -> V_54 . V_58 )
F_27 ( V_84 -> V_90 , V_17 ,
V_102 ,
V_84 -> V_54 . V_58 << 3 ) ;
if ( V_84 -> V_54 . V_68 )
F_27 ( V_84 -> V_90 , V_17 ,
V_103 ,
V_84 -> V_54 . V_68 << 4 ) ;
if ( V_84 -> V_54 . V_80 )
F_27 ( V_84 -> V_90 , V_12 ,
V_104 ,
V_84 -> V_54 . V_80 << 1 ) ;
if ( V_84 -> V_54 . V_73 )
F_27 ( V_84 -> V_90 , V_12 ,
V_105 ,
V_84 -> V_54 . V_73 << 4 ) ;
F_27 ( V_84 -> V_90 , V_9 , V_106 ,
V_106 ) ;
V_85 = F_24 ( V_84 -> V_90 , V_23 , & V_3 ) ;
V_85 = F_28 ( & V_52 -> V_2 ,
& V_107 , V_108 ,
F_18 ( V_108 ) ) ;
if ( V_85 < 0 )
goto V_109;
return 0 ;
V_109:
F_29 ( F_18 ( V_84 -> V_92 ) ,
V_84 -> V_92 ) ;
return V_85 ;
}
static int F_30 ( struct V_52 * V_52 )
{
struct V_83 * V_84 = F_31 ( V_52 ) ;
F_32 ( & V_52 -> V_2 ) ;
if ( V_84 -> V_95 )
F_23 ( V_84 -> V_95 , 0 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = F_34 ( V_2 ) ;
F_35 ( V_84 -> V_90 , true ) ;
F_36 ( V_84 -> V_90 ) ;
if ( V_84 -> V_95 )
F_23 ( V_84 -> V_95 , 0 ) ;
F_29 ( F_18 ( V_84 -> V_92 ) ,
V_84 -> V_92 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = F_34 ( V_2 ) ;
int V_85 ;
V_85 = F_20 ( F_18 ( V_84 -> V_92 ) ,
V_84 -> V_92 ) ;
if ( V_85 != 0 ) {
F_10 ( V_2 , L_14 ,
V_85 ) ;
return V_85 ;
}
if ( V_84 -> V_95 )
F_23 ( V_84 -> V_95 , 1 ) ;
F_35 ( V_84 -> V_90 , false ) ;
F_38 ( V_84 -> V_90 ) ;
return 0 ;
}
