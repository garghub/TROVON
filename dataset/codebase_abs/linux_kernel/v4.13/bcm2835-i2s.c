static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 & V_5 ;
if ( V_2 -> V_6 )
return;
switch ( V_3 ) {
case V_7 :
case V_8 :
F_2 ( V_2 -> V_9 ) ;
V_2 -> V_6 = true ;
break;
default:
break;
}
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 )
F_4 ( V_2 -> V_9 ) ;
V_2 -> V_6 = false ;
}
static void F_5 ( struct V_1 * V_2 ,
bool V_10 , bool V_11 )
{
int V_12 = 1000 ;
T_1 V_13 ;
T_1 V_14 ;
T_1 V_15 ;
bool V_16 ;
T_1 V_17 ;
T_1 V_18 ;
V_17 = V_10 ? V_19 : 0 ;
V_17 |= V_11 ? V_20 : 0 ;
V_18 = V_10 ? V_21 : 0 ;
V_18 |= V_11 ? V_22 : 0 ;
F_6 ( V_2 -> V_23 , V_24 , & V_14 ) ;
V_15 = V_14 & ( V_20 | V_19 ) ;
V_16 = V_2 -> V_6 ;
if ( ! V_16 )
F_1 ( V_2 ) ;
F_7 ( V_2 -> V_23 , V_24 , V_17 , 0 ) ;
F_7 ( V_2 -> V_23 , V_24 , V_18 , V_18 ) ;
F_6 ( V_2 -> V_23 , V_24 , & V_13 ) ;
V_13 &= V_25 ;
F_7 ( V_2 -> V_23 , V_24 ,
V_25 , ~ V_13 ) ;
while ( -- V_12 ) {
F_6 ( V_2 -> V_23 , V_24 , & V_14 ) ;
if ( ( V_14 & V_25 ) != V_13 )
break;
}
if ( ! V_12 )
F_8 ( V_2 -> V_2 , L_1 ) ;
if ( ! V_16 )
F_3 ( V_2 ) ;
F_7 ( V_2 -> V_23 , V_24 ,
V_20 | V_19 , V_15 ) ;
}
static int F_9 ( struct V_26 * V_27 ,
unsigned int V_4 )
{
struct V_1 * V_2 = F_10 ( V_27 ) ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
static int F_11 ( struct V_26 * V_27 ,
unsigned int V_28 )
{
struct V_1 * V_2 = F_10 ( V_27 ) ;
V_2 -> V_29 = V_28 ;
return 0 ;
}
static int F_12 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_27 ) ;
unsigned int V_34 = F_13 ( V_33 ) ;
unsigned int V_35 , V_36 , V_29 ;
unsigned int V_37 , V_38 , V_39 , V_40 ;
T_1 V_14 ;
F_6 ( V_2 -> V_23 , V_24 , & V_14 ) ;
if ( V_14 & ( V_19 | V_20 ) )
return 0 ;
switch ( F_14 ( V_33 ) ) {
case V_41 :
V_35 = 16 ;
break;
case V_42 :
V_35 = 24 ;
break;
case V_43 :
V_35 = 32 ;
break;
default:
return - V_44 ;
}
if ( V_2 -> V_29 )
V_29 = V_2 -> V_29 ;
else
V_29 = 2 * V_35 ;
switch ( V_2 -> V_4 & V_5 ) {
case V_7 :
case V_8 :
F_15 ( V_2 -> V_9 , V_34 * V_29 ) ;
break;
default:
break;
}
V_40 = V_45 ;
if ( V_35 >= 24 )
V_40 |= V_46 ;
V_40 |= F_16 ( ( V_35 - 8 ) & 0xf ) ;
switch ( V_2 -> V_4 & V_47 ) {
case V_48 :
V_36 = 1 ;
break;
default:
F_8 ( V_2 -> V_2 , L_2 , V_49 ) ;
return - V_44 ;
}
V_37 = V_36 ;
V_38 = V_29 / 2 + V_36 ;
switch ( F_17 ( V_33 ) ) {
case 2 :
V_40 = F_18 ( V_40 ) | F_19 ( V_40 ) ;
V_40 |= F_18 ( F_20 ( V_37 ) ) ;
V_40 |= F_19 ( F_20 ( V_38 ) ) ;
break;
default:
return - V_44 ;
}
F_21 ( V_2 -> V_23 , V_50 , V_40 ) ;
F_21 ( V_2 -> V_23 , V_51 , V_40 ) ;
V_39 = 0 ;
if ( V_35 <= 16 ) {
V_39 |= V_52 | V_53 ;
}
V_39 |= F_22 ( V_29 - 1 ) ;
V_39 |= F_23 ( V_29 / 2 ) ;
switch ( V_2 -> V_4 & V_5 ) {
case V_7 :
break;
case V_54 :
V_39 |= V_55 ;
break;
case V_8 :
V_39 |= V_56 ;
break;
case V_57 :
V_39 |= V_55 ;
V_39 |= V_56 ;
break;
default:
F_8 ( V_2 -> V_2 , L_3 , V_49 ) ;
return - V_44 ;
}
switch ( V_2 -> V_4 & V_58 ) {
case V_59 :
V_39 |= V_60 ;
V_39 |= V_61 ;
break;
case V_62 :
break;
case V_63 :
V_39 |= V_60 ;
break;
case V_64 :
V_39 |= V_61 ;
break;
default:
return - V_44 ;
}
F_21 ( V_2 -> V_23 , V_65 , V_39 ) ;
F_7 ( V_2 -> V_23 , V_24 ,
F_24 ( 1 )
| F_25 ( 1 )
| V_66 , 0xffffffff ) ;
F_7 ( V_2 -> V_23 , V_67 ,
F_26 ( 0x10 )
| F_27 ( 0x30 )
| F_28 ( 0x30 )
| F_29 ( 0x20 ) , 0xffffffff ) ;
F_5 ( V_2 , true , true ) ;
return 0 ;
}
static int F_30 ( struct V_30 * V_31 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_27 ) ;
T_1 V_68 ;
F_1 ( V_2 ) ;
F_6 ( V_2 -> V_23 , V_24 , & V_68 ) ;
if ( V_31 -> V_69 == V_70
&& ! ( V_68 & V_71 ) )
F_5 ( V_2 , true , false ) ;
else if ( V_31 -> V_69 == V_72
&& ( V_68 & V_73 ) )
F_5 ( V_2 , false , true ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_26 * V_27 )
{
T_1 V_74 ;
if ( V_31 -> V_69 == V_72 )
V_74 = V_20 ;
else
V_74 = V_19 ;
F_7 ( V_2 -> V_23 ,
V_24 , V_74 , 0 ) ;
if ( ! V_27 -> V_75 && ! ( V_2 -> V_4 & V_76 ) )
F_3 ( V_2 ) ;
}
static int F_32 ( struct V_30 * V_31 , int V_77 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_27 ) ;
T_1 V_74 ;
switch ( V_77 ) {
case V_78 :
case V_79 :
case V_80 :
F_1 ( V_2 ) ;
if ( V_31 -> V_69 == V_72 )
V_74 = V_20 ;
else
V_74 = V_19 ;
F_7 ( V_2 -> V_23 ,
V_24 , V_74 , V_74 ) ;
break;
case V_81 :
case V_82 :
case V_83 :
F_31 ( V_2 , V_31 , V_27 ) ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static int F_33 ( struct V_30 * V_31 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_27 ) ;
if ( V_27 -> V_75 )
return 0 ;
F_3 ( V_2 ) ;
F_7 ( V_2 -> V_23 , V_24 ,
V_84 , V_84 ) ;
F_7 ( V_2 -> V_23 , V_24 ,
V_85 , V_85 ) ;
return 0 ;
}
static void F_34 ( struct V_30 * V_31 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_27 ) ;
F_31 ( V_2 , V_31 , V_27 ) ;
if ( V_27 -> V_75 )
return;
F_7 ( V_2 -> V_23 , V_24 ,
V_84 , 0 ) ;
F_3 ( V_2 ) ;
}
static int F_35 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_27 ) ;
F_36 ( V_27 ,
& V_2 -> V_86 [ V_70 ] ,
& V_2 -> V_86 [ V_72 ] ) ;
return 0 ;
}
static bool F_37 ( struct V_87 * V_2 , unsigned int V_88 )
{
switch ( V_88 ) {
case V_24 :
case V_89 :
case V_90 :
case V_91 :
return true ;
default:
return false ;
} ;
}
static bool F_38 ( struct V_87 * V_2 , unsigned int V_88 )
{
switch ( V_88 ) {
case V_89 :
return true ;
default:
return false ;
} ;
}
static int F_39 ( struct V_92 * V_93 )
{
struct V_1 * V_2 ;
int V_94 ;
struct V_95 * V_96 ;
void T_2 * V_97 ;
const T_3 * V_98 ;
T_4 V_99 ;
V_2 = F_40 ( & V_93 -> V_2 , sizeof( * V_2 ) ,
V_100 ) ;
if ( ! V_2 )
return - V_101 ;
V_2 -> V_6 = false ;
V_2 -> V_9 = F_41 ( & V_93 -> V_2 , NULL ) ;
if ( F_42 ( V_2 -> V_9 ) ) {
F_8 ( & V_93 -> V_2 , L_4 ,
F_43 ( V_2 -> V_9 ) ) ;
return F_43 ( V_2 -> V_9 ) ;
}
V_96 = F_44 ( V_93 , V_102 , 0 ) ;
V_97 = F_45 ( & V_93 -> V_2 , V_96 ) ;
if ( F_42 ( V_97 ) )
return F_43 ( V_97 ) ;
V_2 -> V_23 = F_46 ( & V_93 -> V_2 , V_97 ,
& V_103 ) ;
if ( F_42 ( V_2 -> V_23 ) )
return F_43 ( V_2 -> V_23 ) ;
V_98 = F_47 ( V_93 -> V_2 . V_104 , 0 , NULL , NULL ) ;
if ( ! V_98 ) {
F_8 ( & V_93 -> V_2 , L_5 ) ;
return - V_44 ;
}
V_99 = F_48 ( V_98 ) ;
V_2 -> V_86 [ V_70 ] . V_98 =
V_99 + V_89 ;
V_2 -> V_86 [ V_72 ] . V_98 =
V_99 + V_89 ;
V_2 -> V_86 [ V_70 ] . V_105 =
V_106 ;
V_2 -> V_86 [ V_72 ] . V_105 =
V_106 ;
V_2 -> V_86 [ V_70 ] . V_107 = 2 ;
V_2 -> V_86 [ V_72 ] . V_107 = 2 ;
V_2 -> V_86 [ V_70 ] . V_108 =
V_109 ;
V_2 -> V_86 [ V_72 ] . V_108 =
V_109 ;
V_2 -> V_29 = 0 ;
V_2 -> V_2 = & V_93 -> V_2 ;
F_49 ( & V_93 -> V_2 , V_2 ) ;
V_94 = F_50 ( & V_93 -> V_2 ,
& V_110 , & V_111 , 1 ) ;
if ( V_94 ) {
F_8 ( & V_93 -> V_2 , L_6 , V_94 ) ;
return V_94 ;
}
V_94 = F_51 ( & V_93 -> V_2 , NULL , 0 ) ;
if ( V_94 ) {
F_8 ( & V_93 -> V_2 , L_7 , V_94 ) ;
return V_94 ;
}
return 0 ;
}
