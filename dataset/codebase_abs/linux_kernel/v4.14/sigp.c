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
bool V_31 ;
V_31 = F_9 ( V_2 ) ;
V_30 = & V_3 -> V_10 . V_32 -> V_33 ;
V_28 = V_3 -> V_10 . V_32 -> V_34 [ 4 ] & 0xffff ;
V_29 = V_3 -> V_10 . V_32 -> V_34 [ 3 ] & 0xffff ;
if ( ! F_10 ( V_2 )
|| ( V_30 -> V_35 & V_25 ) != V_25
|| ( V_31 && V_30 -> V_36 != 0 )
|| ( ! V_31 && ( V_24 == V_28 || V_24 == V_29 ) ) ) {
return F_5 ( V_2 , V_3 ) ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_37 ;
return V_16 ;
}
}
static int F_11 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_1 * V_4 )
{
struct V_18 V_19 = {
. type = V_38 ,
. V_21 . V_39 . V_23 = V_2 -> V_17 ,
} ;
int V_8 ;
V_8 = F_6 ( V_3 , & V_19 ) ;
if ( V_8 == - V_40 ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_14 ;
return V_16 ;
} else if ( V_8 == 0 ) {
F_4 ( V_2 , 4 , L_3 ,
V_3 -> V_17 ) ;
}
return V_8 ? V_8 : V_13 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
struct V_18 V_19 = {
. type = V_41 ,
} ;
int V_8 ;
V_8 = F_6 ( V_3 , & V_19 ) ;
if ( V_8 == - V_40 )
V_8 = V_42 ;
else if ( V_8 == 0 )
F_4 ( V_2 , 4 , L_4 ,
V_3 -> V_17 ) ;
return V_8 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_1 * V_4 )
{
struct V_18 V_19 = {
. type = V_41 ,
. V_21 . V_43 . V_44 = V_45 ,
} ;
int V_8 ;
V_8 = F_6 ( V_3 , & V_19 ) ;
if ( V_8 == - V_40 )
V_8 = V_42 ;
else if ( V_8 == 0 )
F_4 ( V_2 , 4 , L_5 ,
V_3 -> V_17 ) ;
return V_8 ;
}
static int F_14 ( struct V_1 * V_2 , T_4 V_46 ,
T_1 * V_47 )
{
unsigned int V_48 ;
struct V_1 * V_49 ;
bool V_50 = true ;
F_15 (i, v, vcpu->kvm) {
if ( V_49 == V_2 )
continue;
if ( ! F_10 ( V_49 ) )
V_50 = false ;
}
* V_47 &= 0xffffffff00000000UL ;
* V_47 |= ( V_50 ? V_51 :
V_37 ) ;
return V_16 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_1 * V_3 ,
T_4 V_52 , T_1 * V_4 )
{
struct V_18 V_19 = {
. type = V_53 ,
. V_21 . V_54 . V_52 = V_52 & 0x7fffe000u ,
} ;
int V_8 ;
if ( F_17 ( V_2 -> V_55 , V_19 . V_21 . V_54 . V_52 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_51 ;
return V_16 ;
}
V_8 = F_6 ( V_3 , & V_19 ) ;
if ( V_8 == - V_40 ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_37 ;
return V_16 ;
}
return V_8 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
T_4 V_36 , T_1 * V_4 )
{
int V_44 ;
int V_8 ;
V_44 = F_2 ( V_3 -> V_10 . V_11 . V_7 ) ;
if ( ! ( V_44 & V_12 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_37 ;
return V_16 ;
}
V_36 &= 0x7ffffe00 ;
V_8 = F_19 ( V_3 , V_36 ) ;
if ( V_8 == - V_56 ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_51 ;
V_8 = V_16 ;
}
return V_8 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_1 * V_4 )
{
struct V_5 * V_6 ;
int V_8 ;
if ( ! F_21 ( V_2 -> V_55 , 9 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_57 ;
return V_16 ;
}
V_6 = & V_3 -> V_10 . V_11 ;
if ( F_2 ( V_6 -> V_7 ) & V_58 ) {
V_8 = V_13 ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_59 ;
V_8 = V_16 ;
}
F_4 ( V_2 , 4 , L_6 ,
V_3 -> V_17 , V_8 ) ;
return V_8 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_5 V_60 )
{
struct V_5 * V_6 = & V_3 -> V_10 . V_11 ;
int V_8 = - V_61 ;
F_23 ( & V_6 -> V_62 ) ;
if ( F_24 ( V_3 ) )
V_8 = V_42 ;
F_25 ( & V_6 -> V_62 ) ;
return V_8 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_5 V_60 )
{
return - V_61 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
return - V_61 ;
}
static int F_28 ( struct V_1 * V_2 , T_5 V_60 ,
T_2 V_63 , T_4 V_46 , T_1 * V_47 )
{
int V_8 ;
struct V_1 * V_3 = F_29 ( V_2 -> V_55 , V_63 ) ;
if ( ! V_3 )
return V_64 ;
switch ( V_60 ) {
case V_65 :
V_2 -> V_66 . V_67 ++ ;
V_8 = F_1 ( V_2 , V_3 , V_47 ) ;
break;
case V_68 :
V_2 -> V_66 . V_69 ++ ;
V_8 = F_11 ( V_2 , V_3 , V_47 ) ;
break;
case V_70 :
V_2 -> V_66 . V_71 ++ ;
V_8 = F_7 ( V_2 , V_3 ) ;
break;
case V_72 :
V_2 -> V_66 . V_73 ++ ;
V_8 = F_12 ( V_2 , V_3 ) ;
break;
case V_74 :
V_2 -> V_66 . V_75 ++ ;
V_8 = F_13 ( V_2 , V_3 , V_47 ) ;
break;
case V_76 :
V_2 -> V_66 . V_77 ++ ;
V_8 = F_18 ( V_2 , V_3 , V_46 ,
V_47 ) ;
break;
case V_78 :
V_2 -> V_66 . V_79 ++ ;
V_8 = F_16 ( V_2 , V_3 , V_46 , V_47 ) ;
break;
case V_80 :
V_2 -> V_66 . V_81 ++ ;
V_8 = F_8 ( V_2 , V_3 , V_46 ,
V_47 ) ;
break;
case V_82 :
V_2 -> V_66 . V_83 ++ ;
V_8 = F_20 ( V_2 , V_3 , V_47 ) ;
break;
case V_84 :
V_2 -> V_66 . V_85 ++ ;
V_8 = F_22 ( V_2 , V_3 , V_60 ) ;
break;
case V_86 :
V_2 -> V_66 . V_87 ++ ;
V_8 = F_22 ( V_2 , V_3 , V_60 ) ;
break;
case V_88 :
V_2 -> V_66 . V_89 ++ ;
V_8 = F_26 ( V_2 , V_3 , V_60 ) ;
break;
case V_90 :
V_2 -> V_66 . V_91 ++ ;
V_8 = F_26 ( V_2 , V_3 , V_60 ) ;
break;
default:
V_2 -> V_66 . V_92 ++ ;
V_8 = F_27 ( V_2 , V_3 ) ;
}
if ( V_8 == - V_61 )
F_4 ( V_2 , 4 ,
L_7 ,
V_60 , V_3 -> V_17 ) ;
return V_8 ;
}
static int F_30 ( struct V_1 * V_2 , T_5 V_60 ,
T_2 V_63 )
{
if ( ! V_2 -> V_55 -> V_10 . V_93 )
return 0 ;
switch ( V_60 ) {
case V_65 :
case V_68 :
case V_70 :
case V_80 :
case V_82 :
return 0 ;
case V_72 :
V_2 -> V_66 . V_73 ++ ;
break;
case V_74 :
V_2 -> V_66 . V_75 ++ ;
break;
case V_76 :
V_2 -> V_66 . V_77 ++ ;
break;
case V_94 :
V_2 -> V_66 . V_95 ++ ;
break;
case V_78 :
V_2 -> V_66 . V_79 ++ ;
break;
case V_84 :
V_2 -> V_66 . V_85 ++ ;
break;
case V_86 :
V_2 -> V_66 . V_87 ++ ;
break;
case V_88 :
V_2 -> V_66 . V_89 ++ ;
break;
case V_90 :
V_2 -> V_66 . V_91 ++ ;
break;
default:
V_2 -> V_66 . V_92 ++ ;
}
F_4 ( V_2 , 3 , L_8 ,
V_60 , V_63 ) ;
return 1 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_96 = ( V_2 -> V_10 . V_32 -> V_97 & 0x00f0 ) >> 4 ;
int V_98 = V_2 -> V_10 . V_32 -> V_97 & 0x000f ;
T_4 V_46 ;
T_2 V_63 = V_2 -> V_99 -> V_100 . V_101 . V_102 [ V_98 ] ;
T_5 V_60 ;
int V_8 ;
if ( V_2 -> V_10 . V_32 -> V_33 . V_35 & V_103 )
return F_32 ( V_2 , V_104 ) ;
V_60 = F_33 ( V_2 , NULL ) ;
if ( F_30 ( V_2 , V_60 , V_63 ) )
return - V_61 ;
if ( V_96 % 2 )
V_46 = V_2 -> V_99 -> V_100 . V_101 . V_102 [ V_96 ] ;
else
V_46 = V_2 -> V_99 -> V_100 . V_101 . V_102 [ V_96 + 1 ] ;
F_34 ( V_2 , V_60 , V_63 , V_46 ) ;
switch ( V_60 ) {
case V_105 :
V_2 -> V_66 . V_106 ++ ;
V_8 = F_14 ( V_2 , V_46 ,
& V_2 -> V_99 -> V_100 . V_101 . V_102 [ V_96 ] ) ;
break;
default:
V_8 = F_28 ( V_2 , V_60 , V_63 ,
V_46 ,
& V_2 -> V_99 -> V_100 . V_101 . V_102 [ V_96 ] ) ;
}
if ( V_8 < 0 )
return V_8 ;
F_35 ( V_2 , V_8 ) ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 )
{
int V_98 = V_2 -> V_10 . V_32 -> V_97 & 0x000f ;
T_2 V_63 = V_2 -> V_99 -> V_100 . V_101 . V_102 [ V_98 ] ;
struct V_1 * V_107 ;
T_5 V_60 = F_33 ( V_2 , NULL ) ;
F_37 ( V_2 , V_60 , V_63 ) ;
if ( V_60 == V_68 ) {
V_107 = F_29 ( V_2 -> V_55 , V_63 ) ;
F_38 ( V_107 == NULL ) ;
F_39 ( V_107 ) ;
F_35 ( V_2 , V_13 ) ;
return 0 ;
}
return - V_61 ;
}
