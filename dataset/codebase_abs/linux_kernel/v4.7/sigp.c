static int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
T_1 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
int V_8 ;
int V_9 ;
V_6 = & V_3 -> V_10 . V_11 ;
V_7 = F_2 ( V_6 -> V_7 ) ;
V_9 = F_3 ( V_3 ) ;
if ( ! ( V_7 & V_12 ) && ! V_9 )
V_8 = V_13 ;
else {
* V_4 &= 0xffffffff00000000UL ;
if ( V_9 )
* V_4 |= V_14 ;
if ( V_7 & V_12 )
* V_4 |= V_15 ;
V_8 = V_16 ;
}
F_4 ( V_2 , 4 , L_1 , V_3 -> V_17 ,
V_8 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_18 V_19 = {
. type = V_20 ,
. V_21 . V_22 . V_23 = V_2 -> V_17 ,
} ;
int V_8 = 0 ;
V_8 = F_6 ( V_3 , & V_19 ) ;
if ( ! V_8 )
F_4 ( V_2 , 4 , L_2 ,
V_3 -> V_17 ) ;
return V_8 ? V_8 : V_13 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
return F_5 ( V_2 , V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
T_2 V_24 , T_1 * V_4 )
{
const T_1 V_25 = V_26 | V_27 ;
T_2 V_28 , V_29 ;
T_3 * V_30 ;
T_4 V_31 ;
V_31 = F_2 ( & V_3 -> V_10 . V_32 -> V_7 ) ;
V_30 = & V_3 -> V_10 . V_32 -> V_33 ;
V_28 = V_3 -> V_10 . V_32 -> V_34 [ 4 ] & 0xffff ;
V_29 = V_3 -> V_10 . V_32 -> V_34 [ 3 ] & 0xffff ;
if ( ! ( V_31 & V_12 )
|| ( V_30 -> V_35 & V_25 ) != V_25
|| ( ( V_31 & V_36 ) && V_30 -> V_37 != 0 )
|| ( ! ( V_31 & V_36 ) && ( V_24 == V_28 || V_24 == V_29 ) ) ) {
return F_5 ( V_2 , V_3 ) ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_38 ;
return V_16 ;
}
}
static int F_9 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_1 * V_4 )
{
struct V_18 V_19 = {
. type = V_39 ,
. V_21 . V_40 . V_23 = V_2 -> V_17 ,
} ;
int V_8 ;
V_8 = F_6 ( V_3 , & V_19 ) ;
if ( V_8 == - V_41 ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_14 ;
return V_16 ;
} else if ( V_8 == 0 ) {
F_4 ( V_2 , 4 , L_3 ,
V_3 -> V_17 ) ;
}
return V_8 ? V_8 : V_13 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
struct V_18 V_19 = {
. type = V_42 ,
} ;
int V_8 ;
V_8 = F_6 ( V_3 , & V_19 ) ;
if ( V_8 == - V_41 )
V_8 = V_43 ;
else if ( V_8 == 0 )
F_4 ( V_2 , 4 , L_4 ,
V_3 -> V_17 ) ;
return V_8 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_1 * V_4 )
{
struct V_18 V_19 = {
. type = V_42 ,
. V_21 . V_44 . V_31 = V_45 ,
} ;
int V_8 ;
V_8 = F_6 ( V_3 , & V_19 ) ;
if ( V_8 == - V_41 )
V_8 = V_43 ;
else if ( V_8 == 0 )
F_4 ( V_2 , 4 , L_5 ,
V_3 -> V_17 ) ;
return V_8 ;
}
static int F_12 ( struct V_1 * V_2 , T_4 V_46 )
{
int V_8 ;
unsigned int V_47 ;
struct V_1 * V_48 ;
switch ( V_46 & 0xff ) {
case 0 :
V_8 = V_49 ;
break;
case 1 :
case 2 :
F_13 (i, v, vcpu->kvm) {
V_48 -> V_10 . V_50 = V_51 ;
F_14 ( V_48 ) ;
}
V_8 = V_13 ;
break;
default:
V_8 = - V_52 ;
}
return V_8 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_1 * V_3 ,
T_4 V_53 , T_1 * V_4 )
{
struct V_18 V_19 = {
. type = V_54 ,
. V_21 . V_55 . V_53 = V_53 & 0x7fffe000u ,
} ;
int V_8 ;
if ( F_16 ( V_2 -> V_56 , V_19 . V_21 . V_55 . V_53 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_57 ;
return V_16 ;
}
V_8 = F_6 ( V_3 , & V_19 ) ;
if ( V_8 == - V_41 ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_38 ;
return V_16 ;
}
return V_8 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
T_4 V_37 , T_1 * V_4 )
{
int V_31 ;
int V_8 ;
V_31 = F_2 ( V_3 -> V_10 . V_11 . V_7 ) ;
if ( ! ( V_31 & V_12 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_38 ;
return V_16 ;
}
V_37 &= 0x7ffffe00 ;
V_8 = F_18 ( V_3 , V_37 ) ;
if ( V_8 == - V_58 ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_57 ;
V_8 = V_16 ;
}
return V_8 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_1 * V_4 )
{
struct V_5 * V_6 ;
int V_8 ;
if ( ! F_20 ( V_2 -> V_56 , 9 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_59 ;
return V_16 ;
}
V_6 = & V_3 -> V_10 . V_11 ;
if ( F_2 ( V_6 -> V_7 ) & V_60 ) {
V_8 = V_13 ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_61 ;
V_8 = V_16 ;
}
F_4 ( V_2 , 4 , L_6 ,
V_3 -> V_17 , V_8 ) ;
return V_8 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_5 V_62 )
{
struct V_5 * V_6 = & V_3 -> V_10 . V_11 ;
int V_8 = - V_52 ;
F_22 ( & V_6 -> V_63 ) ;
if ( F_23 ( V_3 ) )
V_8 = V_43 ;
F_24 ( & V_6 -> V_63 ) ;
return V_8 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_5 V_62 )
{
return - V_52 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
return - V_52 ;
}
static int F_27 ( struct V_1 * V_2 , T_5 V_62 ,
T_2 V_64 , T_4 V_46 , T_1 * V_65 )
{
int V_8 ;
struct V_1 * V_3 = F_28 ( V_2 -> V_56 , V_64 ) ;
if ( ! V_3 )
return V_49 ;
switch ( V_62 ) {
case V_66 :
V_2 -> V_67 . V_68 ++ ;
V_8 = F_1 ( V_2 , V_3 , V_65 ) ;
break;
case V_69 :
V_2 -> V_67 . V_70 ++ ;
V_8 = F_9 ( V_2 , V_3 , V_65 ) ;
break;
case V_71 :
V_2 -> V_67 . V_72 ++ ;
V_8 = F_7 ( V_2 , V_3 ) ;
break;
case V_73 :
V_2 -> V_67 . V_74 ++ ;
V_8 = F_10 ( V_2 , V_3 ) ;
break;
case V_75 :
V_2 -> V_67 . V_76 ++ ;
V_8 = F_11 ( V_2 , V_3 , V_65 ) ;
break;
case V_77 :
V_2 -> V_67 . V_78 ++ ;
V_8 = F_17 ( V_2 , V_3 , V_46 ,
V_65 ) ;
break;
case V_79 :
V_2 -> V_67 . V_80 ++ ;
V_8 = F_15 ( V_2 , V_3 , V_46 , V_65 ) ;
break;
case V_81 :
V_2 -> V_67 . V_82 ++ ;
V_8 = F_8 ( V_2 , V_3 , V_46 ,
V_65 ) ;
break;
case V_83 :
V_2 -> V_67 . V_84 ++ ;
V_8 = F_19 ( V_2 , V_3 , V_65 ) ;
break;
case V_85 :
V_2 -> V_67 . V_86 ++ ;
V_8 = F_21 ( V_2 , V_3 , V_62 ) ;
break;
case V_87 :
V_2 -> V_67 . V_88 ++ ;
V_8 = F_21 ( V_2 , V_3 , V_62 ) ;
break;
case V_89 :
V_2 -> V_67 . V_90 ++ ;
V_8 = F_25 ( V_2 , V_3 , V_62 ) ;
break;
case V_91 :
V_2 -> V_67 . V_92 ++ ;
V_8 = F_25 ( V_2 , V_3 , V_62 ) ;
break;
default:
V_2 -> V_67 . V_93 ++ ;
V_8 = F_26 ( V_2 , V_3 ) ;
}
if ( V_8 == - V_52 )
F_4 ( V_2 , 4 ,
L_7 ,
V_62 , V_3 -> V_17 ) ;
return V_8 ;
}
static int F_29 ( struct V_1 * V_2 , T_5 V_62 ,
T_2 V_64 )
{
if ( ! V_2 -> V_56 -> V_10 . V_94 )
return 0 ;
switch ( V_62 ) {
case V_66 :
case V_69 :
case V_71 :
case V_81 :
case V_83 :
return 0 ;
case V_73 :
V_2 -> V_67 . V_74 ++ ;
break;
case V_75 :
V_2 -> V_67 . V_76 ++ ;
break;
case V_77 :
V_2 -> V_67 . V_78 ++ ;
break;
case V_95 :
V_2 -> V_67 . V_96 ++ ;
break;
case V_79 :
V_2 -> V_67 . V_80 ++ ;
break;
case V_85 :
V_2 -> V_67 . V_86 ++ ;
break;
case V_87 :
V_2 -> V_67 . V_88 ++ ;
break;
case V_89 :
V_2 -> V_67 . V_90 ++ ;
break;
case V_91 :
V_2 -> V_67 . V_92 ++ ;
break;
default:
V_2 -> V_67 . V_93 ++ ;
}
F_4 ( V_2 , 3 , L_8 ,
V_62 , V_64 ) ;
return 1 ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_97 = ( V_2 -> V_10 . V_32 -> V_98 & 0x00f0 ) >> 4 ;
int V_99 = V_2 -> V_10 . V_32 -> V_98 & 0x000f ;
T_4 V_46 ;
T_2 V_64 = V_2 -> V_100 -> V_101 . V_102 . V_103 [ V_99 ] ;
T_5 V_62 ;
int V_8 ;
if ( V_2 -> V_10 . V_32 -> V_33 . V_35 & V_104 )
return F_31 ( V_2 , V_105 ) ;
V_62 = F_32 ( V_2 , NULL ) ;
if ( F_29 ( V_2 , V_62 , V_64 ) )
return - V_52 ;
if ( V_97 % 2 )
V_46 = V_2 -> V_100 -> V_101 . V_102 . V_103 [ V_97 ] ;
else
V_46 = V_2 -> V_100 -> V_101 . V_102 . V_103 [ V_97 + 1 ] ;
F_33 ( V_2 , V_62 , V_64 , V_46 ) ;
switch ( V_62 ) {
case V_106 :
V_2 -> V_67 . V_107 ++ ;
V_8 = F_12 ( V_2 , V_46 ) ;
break;
default:
V_8 = F_27 ( V_2 , V_62 , V_64 ,
V_46 ,
& V_2 -> V_100 -> V_101 . V_102 . V_103 [ V_97 ] ) ;
}
if ( V_8 < 0 )
return V_8 ;
F_34 ( V_2 , V_8 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_99 = V_2 -> V_10 . V_32 -> V_98 & 0x000f ;
T_2 V_64 = V_2 -> V_100 -> V_101 . V_102 . V_103 [ V_99 ] ;
struct V_1 * V_108 ;
T_5 V_62 = F_32 ( V_2 , NULL ) ;
F_36 ( V_2 , V_62 , V_64 ) ;
if ( V_62 == V_69 ) {
V_108 = F_28 ( V_2 -> V_56 , V_64 ) ;
F_37 ( V_108 == NULL ) ;
F_38 ( V_108 ) ;
F_34 ( V_2 , V_13 ) ;
return 0 ;
}
return - V_52 ;
}
