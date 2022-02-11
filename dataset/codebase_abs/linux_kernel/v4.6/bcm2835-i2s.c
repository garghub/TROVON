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
V_35 = 32 ;
break;
default:
return - V_43 ;
}
if ( V_2 -> V_29 )
V_29 = V_2 -> V_29 ;
else
V_29 = 2 * V_35 ;
F_15 ( V_2 -> V_9 , V_34 * V_29 ) ;
V_40 = V_44 ;
if ( V_35 > 24 )
V_40 |= V_45 ;
V_40 |= F_16 ( ( V_35 - 8 ) & 0xf ) ;
switch ( V_2 -> V_4 & V_46 ) {
case V_47 :
V_36 = 1 ;
break;
default:
F_8 ( V_2 -> V_2 , L_2 , V_48 ) ;
return - V_43 ;
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
return - V_43 ;
}
F_21 ( V_2 -> V_23 , V_49 , V_40 ) ;
F_21 ( V_2 -> V_23 , V_50 , V_40 ) ;
V_39 = 0 ;
if ( V_35 <= 16 ) {
V_39 |= V_51 | V_52 ;
}
V_39 |= F_22 ( V_29 - 1 ) ;
V_39 |= F_23 ( V_29 / 2 ) ;
switch ( V_2 -> V_4 & V_5 ) {
case V_7 :
break;
case V_53 :
V_39 |= V_54 ;
break;
case V_8 :
V_39 |= V_55 ;
break;
case V_56 :
V_39 |= V_54 ;
V_39 |= V_55 ;
break;
default:
F_8 ( V_2 -> V_2 , L_3 , V_48 ) ;
return - V_43 ;
}
switch ( V_2 -> V_4 & V_57 ) {
case V_58 :
V_39 |= V_59 ;
V_39 |= V_60 ;
break;
case V_61 :
break;
case V_62 :
V_39 |= V_59 ;
break;
case V_63 :
V_39 |= V_60 ;
break;
default:
return - V_43 ;
}
F_21 ( V_2 -> V_23 , V_64 , V_39 ) ;
F_7 ( V_2 -> V_23 , V_24 ,
F_24 ( 1 )
| F_25 ( 1 )
| V_65 , 0xffffffff ) ;
F_7 ( V_2 -> V_23 , V_66 ,
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
T_1 V_67 ;
F_1 ( V_2 ) ;
F_6 ( V_2 -> V_23 , V_24 , & V_67 ) ;
if ( V_31 -> V_68 == V_69
&& ! ( V_67 & V_70 ) )
F_5 ( V_2 , true , false ) ;
else if ( V_31 -> V_68 == V_71
&& ( V_67 & V_72 ) )
F_5 ( V_2 , false , true ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_26 * V_27 )
{
T_1 V_73 ;
if ( V_31 -> V_68 == V_71 )
V_73 = V_20 ;
else
V_73 = V_19 ;
F_7 ( V_2 -> V_23 ,
V_24 , V_73 , 0 ) ;
if ( ! V_27 -> V_74 && ! ( V_2 -> V_4 & V_75 ) )
F_3 ( V_2 ) ;
}
static int F_32 ( struct V_30 * V_31 , int V_76 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_27 ) ;
T_1 V_73 ;
switch ( V_76 ) {
case V_77 :
case V_78 :
case V_79 :
F_1 ( V_2 ) ;
if ( V_31 -> V_68 == V_71 )
V_73 = V_20 ;
else
V_73 = V_19 ;
F_7 ( V_2 -> V_23 ,
V_24 , V_73 , V_73 ) ;
break;
case V_80 :
case V_81 :
case V_82 :
F_31 ( V_2 , V_31 , V_27 ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_33 ( struct V_30 * V_31 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_27 ) ;
if ( V_27 -> V_74 )
return 0 ;
F_3 ( V_2 ) ;
F_7 ( V_2 -> V_23 , V_24 ,
V_83 , V_83 ) ;
F_7 ( V_2 -> V_23 , V_24 ,
V_84 , V_84 ) ;
return 0 ;
}
static void F_34 ( struct V_30 * V_31 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_27 ) ;
F_31 ( V_2 , V_31 , V_27 ) ;
if ( V_27 -> V_74 )
return;
F_7 ( V_2 -> V_23 , V_24 ,
V_83 , 0 ) ;
F_3 ( V_2 ) ;
}
static int F_35 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_27 ) ;
F_36 ( V_27 ,
& V_2 -> V_85 [ V_69 ] ,
& V_2 -> V_85 [ V_71 ] ) ;
return 0 ;
}
static bool F_37 ( struct V_86 * V_2 , unsigned int V_87 )
{
switch ( V_87 ) {
case V_24 :
case V_88 :
case V_89 :
case V_90 :
return true ;
default:
return false ;
} ;
}
static bool F_38 ( struct V_86 * V_2 , unsigned int V_87 )
{
switch ( V_87 ) {
case V_88 :
return true ;
default:
return false ;
} ;
}
static int F_39 ( struct V_91 * V_92 )
{
struct V_1 * V_2 ;
int V_93 ;
struct V_94 * V_95 ;
void T_2 * V_96 ;
const T_3 * V_97 ;
T_4 V_98 ;
V_2 = F_40 ( & V_92 -> V_2 , sizeof( * V_2 ) ,
V_99 ) ;
if ( ! V_2 )
return - V_100 ;
V_2 -> V_6 = false ;
V_2 -> V_9 = F_41 ( & V_92 -> V_2 , NULL ) ;
if ( F_42 ( V_2 -> V_9 ) ) {
F_8 ( & V_92 -> V_2 , L_4 ,
F_43 ( V_2 -> V_9 ) ) ;
return F_43 ( V_2 -> V_9 ) ;
}
V_95 = F_44 ( V_92 , V_101 , 0 ) ;
V_96 = F_45 ( & V_92 -> V_2 , V_95 ) ;
if ( F_42 ( V_96 ) )
return F_43 ( V_96 ) ;
V_2 -> V_23 = F_46 ( & V_92 -> V_2 , V_96 ,
& V_102 ) ;
if ( F_42 ( V_2 -> V_23 ) )
return F_43 ( V_2 -> V_23 ) ;
V_97 = F_47 ( V_92 -> V_2 . V_103 , 0 , NULL , NULL ) ;
if ( ! V_97 ) {
F_8 ( & V_92 -> V_2 , L_5 ) ;
return - V_43 ;
}
V_98 = F_48 ( V_97 ) ;
V_2 -> V_85 [ V_69 ] . V_97 =
V_98 + V_88 ;
V_2 -> V_85 [ V_71 ] . V_97 =
V_98 + V_88 ;
V_2 -> V_85 [ V_69 ] . V_104 =
V_105 ;
V_2 -> V_85 [ V_71 ] . V_104 =
V_105 ;
V_2 -> V_85 [ V_69 ] . V_106 = 2 ;
V_2 -> V_85 [ V_71 ] . V_106 = 2 ;
V_2 -> V_29 = 0 ;
V_2 -> V_2 = & V_92 -> V_2 ;
F_49 ( & V_92 -> V_2 , V_2 ) ;
V_93 = F_50 ( & V_92 -> V_2 ,
& V_107 , & V_108 , 1 ) ;
if ( V_93 ) {
F_8 ( & V_92 -> V_2 , L_6 , V_93 ) ;
return V_93 ;
}
V_93 = F_51 ( & V_92 -> V_2 , NULL , 0 ) ;
if ( V_93 ) {
F_8 ( & V_92 -> V_2 , L_7 , V_93 ) ;
return V_93 ;
}
return 0 ;
}
