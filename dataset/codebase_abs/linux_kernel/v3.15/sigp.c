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
struct V_5 * V_6 ;
struct V_21 * V_22 ;
struct V_1 * V_7 = NULL ;
if ( V_3 < V_10 )
V_7 = F_2 ( V_2 -> V_12 , V_3 ) ;
if ( ! V_7 )
return V_11 ;
V_22 = F_6 ( sizeof( * V_22 ) , V_23 ) ;
if ( ! V_22 )
return - V_24 ;
V_22 -> type = V_25 ;
V_22 -> V_26 . V_27 = V_2 -> V_28 ;
V_6 = & V_7 -> V_13 . V_14 ;
F_7 ( & V_6 -> V_29 ) ;
F_8 ( & V_22 -> V_30 , & V_6 -> V_30 ) ;
F_9 ( & V_6 -> V_31 , 1 ) ;
F_10 ( V_32 , V_6 -> V_8 ) ;
if ( F_11 ( V_6 -> V_33 ) )
F_12 ( V_6 -> V_33 ) ;
F_13 ( & V_6 -> V_29 ) ;
F_4 ( V_2 , 4 , L_2 , V_3 ) ;
return V_17 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_34 , T_2 * V_4 )
{
struct V_1 * V_7 = NULL ;
const T_2 V_35 = V_36 | V_37 ;
T_1 V_38 , V_39 ;
T_3 * V_40 ;
T_4 V_41 ;
if ( V_3 < V_10 )
V_7 = F_2 ( V_2 -> V_12 , V_3 ) ;
if ( ! V_7 )
return V_11 ;
V_41 = F_3 ( & V_7 -> V_13 . V_42 -> V_8 ) ;
V_40 = & V_7 -> V_13 . V_42 -> V_43 ;
V_38 = V_7 -> V_13 . V_42 -> V_44 [ 4 ] & 0xffff ;
V_39 = V_7 -> V_13 . V_42 -> V_44 [ 3 ] & 0xffff ;
if ( ! ( V_41 & V_16 )
|| ( V_40 -> V_45 & V_35 ) != V_35
|| ( ( V_41 & V_46 ) && V_40 -> V_47 != 0 )
|| ( ! ( V_41 & V_46 ) && ( V_34 == V_38 || V_34 == V_39 ) ) ) {
return F_5 ( V_2 , V_3 ) ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_48 ;
return V_20 ;
}
}
static int F_15 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 ;
struct V_21 * V_22 ;
struct V_1 * V_7 = NULL ;
if ( V_3 < V_10 )
V_7 = F_2 ( V_2 -> V_12 , V_3 ) ;
if ( ! V_7 )
return V_11 ;
V_22 = F_6 ( sizeof( * V_22 ) , V_23 ) ;
if ( ! V_22 )
return - V_24 ;
V_22 -> type = V_49 ;
V_22 -> V_50 . V_27 = V_2 -> V_28 ;
V_6 = & V_7 -> V_13 . V_14 ;
F_7 ( & V_6 -> V_29 ) ;
F_8 ( & V_22 -> V_30 , & V_6 -> V_30 ) ;
F_9 ( & V_6 -> V_31 , 1 ) ;
F_10 ( V_32 , V_6 -> V_8 ) ;
if ( F_11 ( V_6 -> V_33 ) )
F_12 ( V_6 -> V_33 ) ;
F_13 ( & V_6 -> V_29 ) ;
F_4 ( V_2 , 4 , L_3 , V_3 ) ;
return V_17 ;
}
static int F_16 ( struct V_5 * V_6 , int V_51 )
{
struct V_21 * V_22 ;
int V_9 = V_17 ;
V_22 = F_6 ( sizeof( * V_22 ) , V_52 ) ;
if ( ! V_22 )
return - V_24 ;
V_22 -> type = V_53 ;
F_7 ( & V_6 -> V_29 ) ;
if ( ( F_3 ( V_6 -> V_8 ) & V_16 ) ) {
F_17 ( V_22 ) ;
if ( ( V_51 & V_54 ) != 0 )
V_9 = - V_55 ;
goto V_56;
}
F_8 ( & V_22 -> V_30 , & V_6 -> V_30 ) ;
F_9 ( & V_6 -> V_31 , 1 ) ;
F_10 ( V_57 , V_6 -> V_8 ) ;
V_6 -> V_58 |= V_51 ;
if ( F_11 ( V_6 -> V_33 ) )
F_12 ( V_6 -> V_33 ) ;
V_56:
F_13 ( & V_6 -> V_29 ) ;
return V_9 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_3 , int V_51 )
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
V_9 = F_16 ( V_6 , V_51 ) ;
F_4 ( V_2 , 4 , L_4 , V_3 ) ;
if ( ( V_51 & V_54 ) != 0 && V_9 == - V_55 ) {
V_9 = F_19 ( V_7 ,
V_59 ) ;
}
return V_9 ;
}
static int F_20 ( struct V_1 * V_2 , T_4 V_60 )
{
int V_9 ;
unsigned int V_61 ;
struct V_1 * V_62 ;
switch ( V_60 & 0xff ) {
case 0 :
V_9 = V_11 ;
break;
case 1 :
case 2 :
F_21 (i, v, vcpu->kvm) {
V_62 -> V_13 . V_63 = V_64 ;
F_22 ( V_62 ) ;
}
V_9 = V_17 ;
break;
default:
V_9 = - V_65 ;
}
return V_9 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_3 , T_4 V_66 ,
T_2 * V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 = NULL ;
struct V_21 * V_22 ;
int V_9 ;
T_5 V_67 ;
if ( V_3 < V_10 )
V_7 = F_2 ( V_2 -> V_12 , V_3 ) ;
if ( ! V_7 )
return V_11 ;
V_6 = & V_7 -> V_13 . V_14 ;
V_66 = V_66 & 0x7fffe000u ;
if ( F_24 ( V_2 , & V_67 , V_66 , 1 ) ||
F_24 ( V_2 , & V_67 , V_66 + V_68 , 1 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_69 ;
return V_20 ;
}
V_22 = F_6 ( sizeof( * V_22 ) , V_23 ) ;
if ( ! V_22 )
return V_70 ;
F_7 ( & V_6 -> V_29 ) ;
if ( ! ( F_3 ( V_6 -> V_8 ) & V_16 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_48 ;
V_9 = V_20 ;
F_17 ( V_22 ) ;
goto V_71;
}
V_22 -> type = V_72 ;
V_22 -> V_73 . V_66 = V_66 ;
F_8 ( & V_22 -> V_30 , & V_6 -> V_30 ) ;
F_9 ( & V_6 -> V_31 , 1 ) ;
if ( F_11 ( V_6 -> V_33 ) )
F_12 ( V_6 -> V_33 ) ;
V_9 = V_17 ;
F_4 ( V_2 , 4 , L_5 , V_3 , V_66 ) ;
V_71:
F_13 ( & V_6 -> V_29 ) ;
return V_9 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_74 ,
T_4 V_47 , T_2 * V_4 )
{
struct V_1 * V_7 = NULL ;
int V_41 ;
int V_9 ;
if ( V_74 < V_10 )
V_7 = F_2 ( V_2 -> V_12 , V_74 ) ;
if ( ! V_7 )
return V_11 ;
F_7 ( & V_7 -> V_13 . V_14 . V_29 ) ;
V_41 = F_3 ( V_7 -> V_13 . V_14 . V_8 ) ;
F_13 ( & V_7 -> V_13 . V_14 . V_29 ) ;
if ( ! ( V_41 & V_16 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_48 ;
return V_20 ;
}
V_47 &= 0x7ffffe00 ;
V_9 = F_19 ( V_7 , V_47 ) ;
if ( V_9 == - V_75 ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_69 ;
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
if ( F_3 ( V_6 -> V_8 ) & V_76 ) {
V_9 = V_17 ;
} else {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_77 ;
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
F_7 ( & V_6 -> V_29 ) ;
if ( V_6 -> V_58 & V_78 )
V_9 = V_70 ;
F_13 ( & V_6 -> V_29 ) ;
return V_9 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_79 = ( V_2 -> V_13 . V_42 -> V_80 & 0x00f0 ) >> 4 ;
int V_81 = V_2 -> V_13 . V_42 -> V_80 & 0x000f ;
T_4 V_60 ;
T_1 V_3 = V_2 -> V_82 -> V_83 . V_84 . V_85 [ V_81 ] ;
T_5 V_86 ;
int V_9 ;
if ( V_2 -> V_13 . V_42 -> V_43 . V_45 & V_87 )
return F_29 ( V_2 , V_88 ) ;
V_86 = F_30 ( V_2 ) ;
if ( V_79 % 2 )
V_60 = V_2 -> V_82 -> V_83 . V_84 . V_85 [ V_79 ] ;
else
V_60 = V_2 -> V_82 -> V_83 . V_84 . V_85 [ V_79 + 1 ] ;
F_31 ( V_2 , V_86 , V_3 , V_60 ) ;
switch ( V_86 ) {
case V_89 :
V_2 -> V_90 . V_91 ++ ;
V_9 = F_1 ( V_2 , V_3 ,
& V_2 -> V_82 -> V_83 . V_84 . V_85 [ V_79 ] ) ;
break;
case V_92 :
V_2 -> V_90 . V_93 ++ ;
V_9 = F_15 ( V_2 , V_3 ) ;
break;
case V_94 :
V_2 -> V_90 . V_95 ++ ;
V_9 = F_5 ( V_2 , V_3 ) ;
break;
case V_96 :
V_2 -> V_90 . V_97 ++ ;
V_9 = F_18 ( V_2 , V_3 , V_78 ) ;
break;
case V_98 :
V_2 -> V_90 . V_97 ++ ;
V_9 = F_18 ( V_2 , V_3 , V_54 |
V_78 ) ;
break;
case V_99 :
V_9 = F_25 ( V_2 , V_3 , V_60 ,
& V_2 -> V_82 -> V_83 . V_84 . V_85 [ V_79 ] ) ;
break;
case V_100 :
V_2 -> V_90 . V_101 ++ ;
V_9 = F_20 ( V_2 , V_60 ) ;
break;
case V_102 :
V_2 -> V_90 . V_103 ++ ;
V_9 = F_23 ( V_2 , V_3 , V_60 ,
& V_2 -> V_82 -> V_83 . V_84 . V_85 [ V_79 ] ) ;
break;
case V_104 :
V_9 = F_14 ( V_2 , V_3 , V_60 ,
& V_2 -> V_82 -> V_83 . V_84 . V_85 [ V_79 ] ) ;
break;
case V_105 :
V_2 -> V_90 . V_106 ++ ;
V_9 = F_26 ( V_2 , V_3 ,
& V_2 -> V_82 -> V_83 . V_84 . V_85 [ V_79 ] ) ;
break;
case V_107 :
V_9 = F_27 ( V_2 , V_3 ) ;
if ( V_9 == V_17 )
V_9 = - V_65 ;
break;
case V_108 :
V_2 -> V_90 . V_109 ++ ;
V_9 = F_27 ( V_2 , V_3 ) ;
if ( V_9 == V_17 ) {
F_4 ( V_2 , 4 ,
L_7 ,
V_3 ) ;
V_9 = - V_65 ;
}
break;
default:
return - V_65 ;
}
if ( V_9 < 0 )
return V_9 ;
F_32 ( V_2 , V_9 ) ;
return 0 ;
}
