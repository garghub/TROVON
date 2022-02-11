static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 = NULL ;
int V_8 ;
int V_9 ;
if ( V_3 >= V_10 )
return V_11 ;
V_7 = F_2 ( V_2 -> V_12 , V_3 ) ;
if ( ! V_7 )
return V_11 ;
V_6 = & V_7 -> V_13 . V_14 ;
V_8 = F_3 ( V_6 -> V_8 ) ;
if ( ! ( V_8 & ( V_15 | V_16 ) ) )
V_9 = V_17 ;
else {
* V_4 &= 0xffffffff00000000UL ;
if ( V_8 & V_15 )
* V_4 |= V_18 ;
if ( V_8 & V_16 )
* V_4 |= V_19 ;
V_9 = V_20 ;
}
F_4 ( V_2 , 4 , L_1 , V_3 , V_9 ) ;
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_21 V_22 = {
. type = V_23 ,
. V_24 = V_2 -> V_25 ,
} ;
struct V_1 * V_7 = NULL ;
int V_9 = 0 ;
if ( V_3 < V_10 )
V_7 = F_2 ( V_2 -> V_12 , V_3 ) ;
if ( ! V_7 )
return V_11 ;
V_9 = F_6 ( V_7 , & V_22 ) ;
if ( ! V_9 )
F_4 ( V_2 , 4 , L_2 , V_3 ) ;
return V_9 ? V_9 : V_17 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_26 , T_2 * V_4 )
{
struct V_1 * V_7 = NULL ;
const T_2 V_27 = V_28 | V_29 ;
T_1 V_30 , V_31 ;
T_3 * V_32 ;
T_4 V_33 ;
if ( V_3 < V_10 )
V_7 = F_2 ( V_2 -> V_12 , V_3 ) ;
if ( ! V_7 )
return V_11 ;
V_33 = F_3 ( & V_7 -> V_13 . V_34 -> V_8 ) ;
V_32 = & V_7 -> V_13 . V_34 -> V_35 ;
V_30 = V_7 -> V_13 . V_34 -> V_36 [ 4 ] & 0xffff ;
V_31 = V_7 -> V_13 . V_34 -> V_36 [ 3 ] & 0xffff ;
if ( ! ( V_33 & V_16 )
|| ( V_32 -> V_37 & V_27 ) != V_27
|| ( ( V_33 & V_38 ) && V_32 -> V_39 != 0 )
|| ( ! ( V_33 & V_38 ) && ( V_26 == V_30 || V_26 == V_31 ) ) ) {
return F_5 ( V_2 , V_3 ) ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_40 ;
return V_20 ;
}
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_21 V_22 = {
. type = V_41 ,
. V_24 = V_2 -> V_25 ,
} ;
struct V_1 * V_7 = NULL ;
int V_9 ;
if ( V_3 < V_10 )
V_7 = F_2 ( V_2 -> V_12 , V_3 ) ;
if ( ! V_7 )
return V_11 ;
V_9 = F_6 ( V_7 , & V_22 ) ;
if ( ! V_9 )
F_4 ( V_2 , 4 , L_3 , V_3 ) ;
return V_9 ? V_9 : V_17 ;
}
static int F_9 ( struct V_1 * V_7 , int V_42 )
{
struct V_5 * V_6 = & V_7 -> V_13 . V_14 ;
struct V_43 * V_44 ;
int V_9 = V_17 ;
V_44 = F_10 ( sizeof( * V_44 ) , V_45 ) ;
if ( ! V_44 )
return - V_46 ;
V_44 -> type = V_47 ;
F_11 ( & V_6 -> V_48 ) ;
if ( V_6 -> V_49 & V_50 ) {
F_12 ( V_44 ) ;
V_9 = V_51 ;
goto V_52;
}
if ( ( F_3 ( V_6 -> V_8 ) & V_16 ) ) {
F_12 ( V_44 ) ;
if ( ( V_42 & V_53 ) != 0 )
V_9 = - V_54 ;
goto V_52;
}
F_13 ( & V_44 -> V_55 , & V_6 -> V_55 ) ;
F_14 ( & V_6 -> V_56 , 1 ) ;
V_6 -> V_49 |= V_42 ;
F_15 ( V_57 , V_6 -> V_8 ) ;
F_16 ( V_7 ) ;
V_52:
F_17 ( & V_6 -> V_48 ) ;
return V_9 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_3 , int V_42 )
{
struct V_1 * V_7 = NULL ;
int V_9 ;
if ( V_3 >= V_10 )
return V_11 ;
V_7 = F_2 ( V_2 -> V_12 , V_3 ) ;
if ( ! V_7 )
return V_11 ;
V_9 = F_9 ( V_7 , V_42 ) ;
F_4 ( V_2 , 4 , L_4 , V_3 ) ;
if ( ( V_42 & V_53 ) != 0 && V_9 == - V_54 ) {
V_9 = F_19 ( V_7 ,
V_58 ) ;
}
return V_9 ;
}
static int F_20 ( struct V_1 * V_2 , T_4 V_59 )
{
int V_9 ;
unsigned int V_60 ;
struct V_1 * V_61 ;
switch ( V_59 & 0xff ) {
case 0 :
V_9 = V_11 ;
break;
case 1 :
case 2 :
F_21 (i, v, vcpu->kvm) {
V_61 -> V_13 . V_62 = V_63 ;
F_22 ( V_61 ) ;
}
V_9 = V_17 ;
break;
default:
V_9 = - V_64 ;
}
return V_9 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_3 , T_4 V_65 ,
T_2 * V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 = NULL ;
struct V_43 * V_44 ;
int V_9 ;
if ( V_3 < V_10 )
V_7 = F_2 ( V_2 -> V_12 , V_3 ) ;
if ( ! V_7 )
return V_11 ;
V_6 = & V_7 -> V_13 . V_14 ;
V_65 &= 0x7fffe000u ;
if ( F_24 ( V_2 -> V_12 , V_65 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_66 ;
return V_20 ;
}
V_44 = F_10 ( sizeof( * V_44 ) , V_67 ) ;
if ( ! V_44 )
return V_51 ;
F_11 ( & V_6 -> V_48 ) ;
if ( ! ( F_3 ( V_6 -> V_8 ) & V_16 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_40 ;
V_9 = V_20 ;
F_12 ( V_44 ) ;
goto V_68;
}
V_44 -> type = V_69 ;
V_44 -> V_70 . V_65 = V_65 ;
F_13 ( & V_44 -> V_55 , & V_6 -> V_55 ) ;
F_14 ( & V_6 -> V_56 , 1 ) ;
F_16 ( V_7 ) ;
V_9 = V_17 ;
F_4 ( V_2 , 4 , L_5 , V_3 , V_65 ) ;
V_68:
F_17 ( & V_6 -> V_48 ) ;
return V_9 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_71 ,
T_4 V_39 , T_2 * V_4 )
{
struct V_1 * V_7 = NULL ;
int V_33 ;
int V_9 ;
if ( V_71 < V_10 )
V_7 = F_2 ( V_2 -> V_12 , V_71 ) ;
if ( ! V_7 )
return V_11 ;
F_11 ( & V_7 -> V_13 . V_14 . V_48 ) ;
V_33 = F_3 ( V_7 -> V_13 . V_14 . V_8 ) ;
F_17 ( & V_7 -> V_13 . V_14 . V_48 ) ;
if ( ! ( V_33 & V_16 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_40 ;
return V_20 ;
}
V_39 &= 0x7ffffe00 ;
V_9 = F_19 ( V_7 , V_39 ) ;
if ( V_9 == - V_72 ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_66 ;
V_9 = V_20 ;
}
return V_9 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 = NULL ;
int V_9 ;
if ( V_3 >= V_10 )
return V_11 ;
V_7 = F_2 ( V_2 -> V_12 , V_3 ) ;
if ( ! V_7 )
return V_11 ;
V_6 = & V_7 -> V_13 . V_14 ;
if ( F_3 ( V_6 -> V_8 ) & V_73 ) {
V_9 = V_17 ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_74 ;
V_9 = V_20 ;
}
F_4 ( V_2 , 4 , L_6 , V_3 ,
V_9 ) ;
return V_9 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 ;
int V_9 = V_17 ;
struct V_1 * V_7 = NULL ;
if ( V_3 >= V_10 )
return V_11 ;
V_7 = F_2 ( V_2 -> V_12 , V_3 ) ;
if ( ! V_7 )
return V_11 ;
V_6 = & V_7 -> V_13 . V_14 ;
F_11 ( & V_6 -> V_48 ) ;
if ( V_6 -> V_49 & V_50 )
V_9 = V_51 ;
F_17 ( & V_6 -> V_48 ) ;
return V_9 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_75 = ( V_2 -> V_13 . V_34 -> V_76 & 0x00f0 ) >> 4 ;
int V_77 = V_2 -> V_13 . V_34 -> V_76 & 0x000f ;
T_4 V_59 ;
T_1 V_3 = V_2 -> V_78 -> V_79 . V_80 . V_81 [ V_77 ] ;
T_5 V_82 ;
int V_9 ;
if ( V_2 -> V_13 . V_34 -> V_35 . V_37 & V_83 )
return F_29 ( V_2 , V_84 ) ;
V_82 = F_30 ( V_2 ) ;
if ( V_75 % 2 )
V_59 = V_2 -> V_78 -> V_79 . V_80 . V_81 [ V_75 ] ;
else
V_59 = V_2 -> V_78 -> V_79 . V_80 . V_81 [ V_75 + 1 ] ;
F_31 ( V_2 , V_82 , V_3 , V_59 ) ;
switch ( V_82 ) {
case V_85 :
V_2 -> V_86 . V_87 ++ ;
V_9 = F_1 ( V_2 , V_3 ,
& V_2 -> V_78 -> V_79 . V_80 . V_81 [ V_75 ] ) ;
break;
case V_88 :
V_2 -> V_86 . V_89 ++ ;
V_9 = F_8 ( V_2 , V_3 ) ;
break;
case V_90 :
V_2 -> V_86 . V_91 ++ ;
V_9 = F_5 ( V_2 , V_3 ) ;
break;
case V_92 :
V_2 -> V_86 . V_93 ++ ;
V_9 = F_18 ( V_2 , V_3 , V_50 ) ;
break;
case V_94 :
V_2 -> V_86 . V_93 ++ ;
V_9 = F_18 ( V_2 , V_3 , V_53 |
V_50 ) ;
break;
case V_95 :
V_9 = F_25 ( V_2 , V_3 , V_59 ,
& V_2 -> V_78 -> V_79 . V_80 . V_81 [ V_75 ] ) ;
break;
case V_96 :
V_2 -> V_86 . V_97 ++ ;
V_9 = F_20 ( V_2 , V_59 ) ;
break;
case V_98 :
V_2 -> V_86 . V_99 ++ ;
V_9 = F_23 ( V_2 , V_3 , V_59 ,
& V_2 -> V_78 -> V_79 . V_80 . V_81 [ V_75 ] ) ;
break;
case V_100 :
V_9 = F_7 ( V_2 , V_3 , V_59 ,
& V_2 -> V_78 -> V_79 . V_80 . V_81 [ V_75 ] ) ;
break;
case V_101 :
V_2 -> V_86 . V_102 ++ ;
V_9 = F_26 ( V_2 , V_3 ,
& V_2 -> V_78 -> V_79 . V_80 . V_81 [ V_75 ] ) ;
break;
case V_103 :
V_9 = F_27 ( V_2 , V_3 ) ;
if ( V_9 == V_17 )
V_9 = - V_64 ;
break;
case V_104 :
V_2 -> V_86 . V_105 ++ ;
V_9 = F_27 ( V_2 , V_3 ) ;
if ( V_9 == V_17 ) {
F_4 ( V_2 , 4 ,
L_7 ,
V_3 ) ;
V_9 = - V_64 ;
}
break;
default:
return - V_64 ;
}
if ( V_9 < 0 )
return V_9 ;
F_32 ( V_2 , V_9 ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_77 = V_2 -> V_13 . V_34 -> V_76 & 0x000f ;
T_1 V_3 = V_2 -> V_78 -> V_79 . V_80 . V_81 [ V_77 ] ;
struct V_1 * V_106 ;
T_5 V_82 = F_30 ( V_2 ) ;
F_34 ( V_2 , V_82 , V_3 ) ;
if ( V_82 == V_88 ) {
V_106 = F_2 ( V_2 -> V_12 , V_3 ) ;
F_35 ( V_106 == NULL ) ;
F_16 ( V_106 ) ;
F_32 ( V_2 , V_17 ) ;
return 0 ;
}
return - V_64 ;
}
