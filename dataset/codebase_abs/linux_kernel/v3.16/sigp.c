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
static int F_9 ( struct V_5 * V_6 , int V_42 )
{
struct V_43 * V_44 ;
int V_9 = V_17 ;
V_44 = F_10 ( sizeof( * V_44 ) , V_45 ) ;
if ( ! V_44 )
return - V_46 ;
V_44 -> type = V_47 ;
F_11 ( & V_6 -> V_48 ) ;
if ( ( F_3 ( V_6 -> V_8 ) & V_16 ) ) {
F_12 ( V_44 ) ;
if ( ( V_42 & V_49 ) != 0 )
V_9 = - V_50 ;
goto V_51;
}
F_13 ( & V_44 -> V_52 , & V_6 -> V_52 ) ;
F_14 ( & V_6 -> V_53 , 1 ) ;
F_15 ( V_54 , V_6 -> V_8 ) ;
V_6 -> V_55 |= V_42 ;
if ( F_16 ( V_6 -> V_56 ) )
F_17 ( V_6 -> V_56 ) ;
V_51:
F_18 ( & V_6 -> V_48 ) ;
return V_9 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_3 , int V_42 )
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
V_9 = F_9 ( V_6 , V_42 ) ;
F_4 ( V_2 , 4 , L_4 , V_3 ) ;
if ( ( V_42 & V_49 ) != 0 && V_9 == - V_50 ) {
V_9 = F_20 ( V_7 ,
V_57 ) ;
}
return V_9 ;
}
static int F_21 ( struct V_1 * V_2 , T_4 V_58 )
{
int V_9 ;
unsigned int V_59 ;
struct V_1 * V_60 ;
switch ( V_58 & 0xff ) {
case 0 :
V_9 = V_11 ;
break;
case 1 :
case 2 :
F_22 (i, v, vcpu->kvm) {
V_60 -> V_13 . V_61 = V_62 ;
F_23 ( V_60 ) ;
}
V_9 = V_17 ;
break;
default:
V_9 = - V_63 ;
}
return V_9 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_3 , T_4 V_64 ,
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
V_64 &= 0x7fffe000u ;
if ( F_25 ( V_2 -> V_12 , V_64 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_65 ;
return V_20 ;
}
V_44 = F_10 ( sizeof( * V_44 ) , V_66 ) ;
if ( ! V_44 )
return V_67 ;
F_11 ( & V_6 -> V_48 ) ;
if ( ! ( F_3 ( V_6 -> V_8 ) & V_16 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_40 ;
V_9 = V_20 ;
F_12 ( V_44 ) ;
goto V_68;
}
V_44 -> type = V_69 ;
V_44 -> V_70 . V_64 = V_64 ;
F_13 ( & V_44 -> V_52 , & V_6 -> V_52 ) ;
F_14 ( & V_6 -> V_53 , 1 ) ;
if ( F_16 ( V_6 -> V_56 ) )
F_17 ( V_6 -> V_56 ) ;
V_9 = V_17 ;
F_4 ( V_2 , 4 , L_5 , V_3 , V_64 ) ;
V_68:
F_18 ( & V_6 -> V_48 ) ;
return V_9 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_71 ,
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
F_18 ( & V_7 -> V_13 . V_14 . V_48 ) ;
if ( ! ( V_33 & V_16 ) ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_40 ;
return V_20 ;
}
V_39 &= 0x7ffffe00 ;
V_9 = F_20 ( V_7 , V_39 ) ;
if ( V_9 == - V_72 ) {
* V_4 &= 0xffffffff00000000UL ;
* V_4 |= V_65 ;
V_9 = V_20 ;
}
return V_9 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_3 ,
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
static int F_28 ( struct V_1 * V_2 , T_1 V_3 )
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
if ( V_6 -> V_55 & V_75 )
V_9 = V_67 ;
F_18 ( & V_6 -> V_48 ) ;
return V_9 ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_76 = ( V_2 -> V_13 . V_34 -> V_77 & 0x00f0 ) >> 4 ;
int V_78 = V_2 -> V_13 . V_34 -> V_77 & 0x000f ;
T_4 V_58 ;
T_1 V_3 = V_2 -> V_79 -> V_80 . V_81 . V_82 [ V_78 ] ;
T_5 V_83 ;
int V_9 ;
if ( V_2 -> V_13 . V_34 -> V_35 . V_37 & V_84 )
return F_30 ( V_2 , V_85 ) ;
V_83 = F_31 ( V_2 ) ;
if ( V_76 % 2 )
V_58 = V_2 -> V_79 -> V_80 . V_81 . V_82 [ V_76 ] ;
else
V_58 = V_2 -> V_79 -> V_80 . V_81 . V_82 [ V_76 + 1 ] ;
F_32 ( V_2 , V_83 , V_3 , V_58 ) ;
switch ( V_83 ) {
case V_86 :
V_2 -> V_87 . V_88 ++ ;
V_9 = F_1 ( V_2 , V_3 ,
& V_2 -> V_79 -> V_80 . V_81 . V_82 [ V_76 ] ) ;
break;
case V_89 :
V_2 -> V_87 . V_90 ++ ;
V_9 = F_8 ( V_2 , V_3 ) ;
break;
case V_91 :
V_2 -> V_87 . V_92 ++ ;
V_9 = F_5 ( V_2 , V_3 ) ;
break;
case V_93 :
V_2 -> V_87 . V_94 ++ ;
V_9 = F_19 ( V_2 , V_3 , V_75 ) ;
break;
case V_95 :
V_2 -> V_87 . V_94 ++ ;
V_9 = F_19 ( V_2 , V_3 , V_49 |
V_75 ) ;
break;
case V_96 :
V_9 = F_26 ( V_2 , V_3 , V_58 ,
& V_2 -> V_79 -> V_80 . V_81 . V_82 [ V_76 ] ) ;
break;
case V_97 :
V_2 -> V_87 . V_98 ++ ;
V_9 = F_21 ( V_2 , V_58 ) ;
break;
case V_99 :
V_2 -> V_87 . V_100 ++ ;
V_9 = F_24 ( V_2 , V_3 , V_58 ,
& V_2 -> V_79 -> V_80 . V_81 . V_82 [ V_76 ] ) ;
break;
case V_101 :
V_9 = F_7 ( V_2 , V_3 , V_58 ,
& V_2 -> V_79 -> V_80 . V_81 . V_82 [ V_76 ] ) ;
break;
case V_102 :
V_2 -> V_87 . V_103 ++ ;
V_9 = F_27 ( V_2 , V_3 ,
& V_2 -> V_79 -> V_80 . V_81 . V_82 [ V_76 ] ) ;
break;
case V_104 :
V_9 = F_28 ( V_2 , V_3 ) ;
if ( V_9 == V_17 )
V_9 = - V_63 ;
break;
case V_105 :
V_2 -> V_87 . V_106 ++ ;
V_9 = F_28 ( V_2 , V_3 ) ;
if ( V_9 == V_17 ) {
F_4 ( V_2 , 4 ,
L_7 ,
V_3 ) ;
V_9 = - V_63 ;
}
break;
default:
return - V_63 ;
}
if ( V_9 < 0 )
return V_9 ;
F_33 ( V_2 , V_9 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_78 = V_2 -> V_13 . V_34 -> V_77 & 0x000f ;
T_1 V_3 = V_2 -> V_79 -> V_80 . V_81 . V_82 [ V_78 ] ;
struct V_1 * V_107 ;
T_5 V_83 = F_31 ( V_2 ) ;
F_35 ( V_2 , V_83 , V_3 ) ;
if ( V_83 == V_89 ) {
V_107 = F_2 ( V_2 -> V_12 , V_3 ) ;
F_36 ( V_107 == NULL ) ;
F_11 ( & V_107 -> V_13 . V_14 . V_48 ) ;
if ( F_16 ( & V_107 -> V_56 ) )
F_17 ( & V_107 -> V_56 ) ;
V_107 -> V_108 = true ;
F_18 ( & V_107 -> V_13 . V_14 . V_48 ) ;
F_33 ( V_2 , V_17 ) ;
return 0 ;
}
return - V_63 ;
}
