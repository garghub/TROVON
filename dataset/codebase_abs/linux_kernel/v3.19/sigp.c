static int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
T_1 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
int V_8 ;
V_6 = & V_3 -> V_9 . V_10 ;
V_7 = F_2 ( V_6 -> V_7 ) ;
if ( ! ( V_7 & ( V_11 | V_12 ) ) )
V_8 = V_13 ;
else {
* V_4 &= 0xffffffff00000000UL ;
if ( V_7 & V_11 )
* V_4 |= V_14 ;
if ( V_7 & V_12 )
* V_4 |= V_15 ;
V_8 = V_16 ;
}
F_3 ( V_2 , 4 , L_1 , V_3 -> V_17 ,
V_8 ) ;
return V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_18 V_19 = {
. type = V_20 ,
. V_21 . V_22 . V_23 = V_2 -> V_17 ,
} ;
int V_8 = 0 ;
V_8 = F_5 ( V_3 , & V_19 ) ;
if ( ! V_8 )
F_3 ( V_2 , 4 , L_2 ,
V_3 -> V_17 ) ;
return V_8 ? V_8 : V_13 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
return F_4 ( V_2 , V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
T_2 V_24 , T_1 * V_4 )
{
const T_1 V_25 = V_26 | V_27 ;
T_2 V_28 , V_29 ;
T_3 * V_30 ;
T_4 V_31 ;
V_31 = F_2 ( & V_3 -> V_9 . V_32 -> V_7 ) ;
V_30 = & V_3 -> V_9 . V_32 -> V_33 ;
V_28 = V_3 -> V_9 . V_32 -> V_34 [ 4 ] & 0xffff ;
V_29 = V_3 -> V_9 . V_32 -> V_34 [ 3 ] & 0xffff ;
if ( ! ( V_31 & V_12 )
|| ( V_30 -> V_35 & V_25 ) != V_25
|| ( ( V_31 & V_36 ) && V_30 -> V_37 != 0 )
|| ( ! ( V_31 & V_36 ) && ( V_24 == V_28 || V_24 == V_29 ) ) ) {
return F_4 ( V_2 , V_3 ) ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_38 ;
return V_16 ;
}
}
static int F_8 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_18 V_19 = {
. type = V_39 ,
. V_21 . V_40 . V_23 = V_2 -> V_17 ,
} ;
int V_8 ;
V_8 = F_5 ( V_3 , & V_19 ) ;
if ( ! V_8 )
F_3 ( V_2 , 4 , L_3 ,
V_3 -> V_17 ) ;
return V_8 ? V_8 : V_13 ;
}
static int F_9 ( struct V_1 * V_3 , int V_41 )
{
struct V_5 * V_6 = & V_3 -> V_9 . V_10 ;
int V_8 = V_13 ;
F_10 ( & V_6 -> V_42 ) ;
if ( V_6 -> V_43 & V_44 ) {
V_8 = V_45 ;
goto V_46;
}
if ( ( F_2 ( V_6 -> V_7 ) & V_12 ) ) {
if ( ( V_41 & V_47 ) != 0 )
V_8 = - V_48 ;
goto V_46;
}
F_11 ( V_49 , & V_6 -> V_50 ) ;
V_6 -> V_43 |= V_41 ;
F_12 ( V_51 , V_6 -> V_7 ) ;
F_13 ( V_3 ) ;
V_46:
F_14 ( & V_6 -> V_42 ) ;
return V_8 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
int V_8 ;
V_8 = F_9 ( V_3 , V_44 ) ;
F_3 ( V_2 , 4 , L_4 , V_3 -> V_17 ) ;
return V_8 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_1 * V_4 )
{
int V_8 ;
V_8 = F_9 ( V_3 , V_44 |
V_47 ) ;
F_3 ( V_2 , 4 , L_5 ,
V_3 -> V_17 ) ;
if ( V_8 == - V_48 ) {
V_8 = F_17 ( V_3 ,
V_52 ) ;
}
return V_8 ;
}
static int F_18 ( struct V_1 * V_2 , T_4 V_53 )
{
int V_8 ;
unsigned int V_54 ;
struct V_1 * V_55 ;
switch ( V_53 & 0xff ) {
case 0 :
V_8 = V_56 ;
break;
case 1 :
case 2 :
F_19 (i, v, vcpu->kvm) {
V_55 -> V_9 . V_57 = V_58 ;
F_20 ( V_55 ) ;
}
V_8 = V_13 ;
break;
default:
V_8 = - V_59 ;
}
return V_8 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_1 * V_3 ,
T_4 V_60 , T_1 * V_4 )
{
struct V_5 * V_6 ;
int V_8 ;
V_6 = & V_3 -> V_9 . V_10 ;
V_60 &= 0x7fffe000u ;
if ( F_22 ( V_2 -> V_61 , V_60 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_62 ;
return V_16 ;
}
F_10 ( & V_6 -> V_42 ) ;
if ( ! ( F_2 ( V_6 -> V_7 ) & V_12 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_38 ;
V_8 = V_16 ;
goto V_63;
}
V_6 -> V_19 . V_64 . V_60 = V_60 ;
F_11 ( V_65 , & V_6 -> V_50 ) ;
F_13 ( V_3 ) ;
V_8 = V_13 ;
F_3 ( V_2 , 4 , L_6 , V_3 -> V_17 ,
V_60 ) ;
V_63:
F_14 ( & V_6 -> V_42 ) ;
return V_8 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
T_4 V_37 , T_1 * V_4 )
{
int V_31 ;
int V_8 ;
F_10 ( & V_3 -> V_9 . V_10 . V_42 ) ;
V_31 = F_2 ( V_3 -> V_9 . V_10 . V_7 ) ;
F_14 ( & V_3 -> V_9 . V_10 . V_42 ) ;
if ( ! ( V_31 & V_12 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_38 ;
return V_16 ;
}
V_37 &= 0x7ffffe00 ;
V_8 = F_17 ( V_3 , V_37 ) ;
if ( V_8 == - V_66 ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_62 ;
V_8 = V_16 ;
}
return V_8 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_1 * V_4 )
{
struct V_5 * V_6 ;
int V_8 ;
V_6 = & V_3 -> V_9 . V_10 ;
if ( F_2 ( V_6 -> V_7 ) & V_67 ) {
V_8 = V_13 ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_68 ;
V_8 = V_16 ;
}
F_3 ( V_2 , 4 , L_7 ,
V_3 -> V_17 , V_8 ) ;
return V_8 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_5 V_69 )
{
struct V_5 * V_6 = & V_3 -> V_9 . V_10 ;
int V_8 = - V_59 ;
F_10 ( & V_6 -> V_42 ) ;
if ( V_6 -> V_43 & V_44 )
V_8 = V_45 ;
F_14 ( & V_6 -> V_42 ) ;
return V_8 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_5 V_69 )
{
return - V_59 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
return - V_59 ;
}
static int F_28 ( struct V_1 * V_2 , T_5 V_69 ,
T_2 V_70 , T_4 V_53 , T_1 * V_71 )
{
int V_8 ;
struct V_1 * V_3 ;
if ( V_70 >= V_72 )
return V_56 ;
V_3 = F_29 ( V_2 -> V_61 , V_70 ) ;
if ( ! V_3 )
return V_56 ;
switch ( V_69 ) {
case V_73 :
V_2 -> V_74 . V_75 ++ ;
V_8 = F_1 ( V_2 , V_3 , V_71 ) ;
break;
case V_76 :
V_2 -> V_74 . V_77 ++ ;
V_8 = F_8 ( V_2 , V_3 ) ;
break;
case V_78 :
V_2 -> V_74 . V_79 ++ ;
V_8 = F_6 ( V_2 , V_3 ) ;
break;
case V_80 :
V_2 -> V_74 . V_81 ++ ;
V_8 = F_15 ( V_2 , V_3 ) ;
break;
case V_82 :
V_2 -> V_74 . V_83 ++ ;
V_8 = F_16 ( V_2 , V_3 , V_71 ) ;
break;
case V_84 :
V_2 -> V_74 . V_85 ++ ;
V_8 = F_23 ( V_2 , V_3 , V_53 ,
V_71 ) ;
break;
case V_86 :
V_2 -> V_74 . V_87 ++ ;
V_8 = F_21 ( V_2 , V_3 , V_53 , V_71 ) ;
break;
case V_88 :
V_2 -> V_74 . V_89 ++ ;
V_8 = F_7 ( V_2 , V_3 , V_53 ,
V_71 ) ;
break;
case V_90 :
V_2 -> V_74 . V_91 ++ ;
V_8 = F_24 ( V_2 , V_3 , V_71 ) ;
break;
case V_92 :
V_2 -> V_74 . V_93 ++ ;
V_8 = F_25 ( V_2 , V_3 , V_69 ) ;
break;
case V_94 :
V_2 -> V_74 . V_95 ++ ;
V_8 = F_25 ( V_2 , V_3 , V_69 ) ;
break;
case V_96 :
V_2 -> V_74 . V_97 ++ ;
V_8 = F_26 ( V_2 , V_3 , V_69 ) ;
break;
case V_98 :
V_2 -> V_74 . V_99 ++ ;
V_8 = F_26 ( V_2 , V_3 , V_69 ) ;
break;
default:
V_2 -> V_74 . V_100 ++ ;
V_8 = F_27 ( V_2 , V_3 ) ;
}
if ( V_8 == - V_59 )
F_3 ( V_2 , 4 ,
L_8 ,
V_69 , V_3 -> V_17 ) ;
return V_8 ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_101 = ( V_2 -> V_9 . V_32 -> V_102 & 0x00f0 ) >> 4 ;
int V_103 = V_2 -> V_9 . V_32 -> V_102 & 0x000f ;
T_4 V_53 ;
T_2 V_70 = V_2 -> V_104 -> V_105 . V_106 . V_107 [ V_103 ] ;
T_5 V_69 ;
int V_8 ;
if ( V_2 -> V_9 . V_32 -> V_33 . V_35 & V_108 )
return F_31 ( V_2 , V_109 ) ;
V_69 = F_32 ( V_2 ) ;
if ( V_101 % 2 )
V_53 = V_2 -> V_104 -> V_105 . V_106 . V_107 [ V_101 ] ;
else
V_53 = V_2 -> V_104 -> V_105 . V_106 . V_107 [ V_101 + 1 ] ;
F_33 ( V_2 , V_69 , V_70 , V_53 ) ;
switch ( V_69 ) {
case V_110 :
V_2 -> V_74 . V_111 ++ ;
V_8 = F_18 ( V_2 , V_53 ) ;
break;
default:
V_8 = F_28 ( V_2 , V_69 , V_70 ,
V_53 ,
& V_2 -> V_104 -> V_105 . V_106 . V_107 [ V_101 ] ) ;
}
if ( V_8 < 0 )
return V_8 ;
F_34 ( V_2 , V_8 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_103 = V_2 -> V_9 . V_32 -> V_102 & 0x000f ;
T_2 V_70 = V_2 -> V_104 -> V_105 . V_106 . V_107 [ V_103 ] ;
struct V_1 * V_112 ;
T_5 V_69 = F_32 ( V_2 ) ;
F_36 ( V_2 , V_69 , V_70 ) ;
if ( V_69 == V_76 ) {
V_112 = F_29 ( V_2 -> V_61 , V_70 ) ;
F_37 ( V_112 == NULL ) ;
F_13 ( V_112 ) ;
F_34 ( V_2 , V_13 ) ;
return 0 ;
}
return - V_59 ;
}
