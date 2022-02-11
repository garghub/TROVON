static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = V_3 | V_6 ;
return F_3 ( V_2 -> V_4 , V_5 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_3 ;
if ( V_7 == V_2 -> V_8 )
return 0 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = V_3 & ~ V_9 ;
V_3 = V_3 | ( V_7 << V_10 ) ;
V_3 = F_3 ( V_2 -> V_4 , V_5 , V_3 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_2 -> V_4 , V_11 ,
V_12 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_8 = V_7 ;
F_5 ( V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_7 ;
if ( V_2 -> V_14 == V_15 ) {
V_3 = F_4 ( V_2 , V_16 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_17 = false ;
}
if ( V_2 -> V_18 )
return 0 ;
V_7 = V_2 -> V_17 ? V_19 : V_16 ;
V_3 = F_4 ( V_2 , V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_18 = true ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_7 ;
if ( V_2 -> V_14 == V_15 ) {
V_3 = F_4 ( V_2 , V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_18 = false ;
}
if ( V_2 -> V_17 )
return 0 ;
V_7 = V_2 -> V_18 ? V_19 : V_20 ;
V_3 = F_4 ( V_2 , V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_17 = true ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_21 ;
V_3 = F_6 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_9 ( V_2 -> V_4 ,
V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
V_21 = V_3 * V_2 -> V_23 / V_24 ;
if ( V_21 > 0xffff )
V_21 = 0xffff ;
return V_21 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_9 ( V_2 -> V_4 ,
V_25 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_26 )
{
int V_3 ;
if ( V_2 -> V_14 == V_15 )
return 0 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = V_3 & ~ V_27 ;
V_3 = V_3 | V_26 ;
V_3 = F_3 ( V_2 -> V_4 , V_5 , V_3 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_26 & V_27 ) {
V_2 -> V_18 = false ;
V_2 -> V_17 = false ;
}
return V_3 ;
}
static int F_12 ( struct V_1 * V_2 , bool V_28 )
{
int V_3 ;
if ( V_2 -> V_14 == V_15 )
return 0 ;
if ( V_28 ) {
V_3 = F_13 ( & V_2 -> V_4 -> V_29 ) ;
if ( V_3 < 0 )
F_14 ( & V_2 -> V_4 -> V_29 ) ;
} else {
F_15 ( & V_2 -> V_4 -> V_29 ) ;
V_3 = F_16 ( & V_2 -> V_4 -> V_29 ) ;
}
return V_3 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_30 const * V_31 )
{
int V_3 , V_32 ;
F_18 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_14 == V_15 ) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
goto V_34;
}
V_3 = F_12 ( V_2 , true ) ;
if ( V_3 < 0 )
goto V_34;
if ( V_31 -> type == V_35 )
V_3 = F_8 ( V_2 ) ;
else
V_3 = F_10 ( V_2 ) ;
if ( V_3 < 0 )
goto V_36;
V_32 = V_3 ;
V_3 = F_12 ( V_2 , false ) ;
if ( V_3 < 0 )
goto V_34;
F_19 ( & V_2 -> V_33 ) ;
return V_32 ;
V_36:
F_12 ( V_2 , false ) ;
V_34:
F_19 ( & V_2 -> V_33 ) ;
return V_3 ;
}
static int F_20 ( struct V_37 * V_38 ,
struct V_30 const * V_31 , int * V_39 ,
int * V_40 , long V_41 )
{
struct V_1 * V_2 = F_21 ( V_38 ) ;
int V_3 ;
switch ( V_41 ) {
case V_42 :
V_3 = F_17 ( V_2 , V_31 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_39 = V_3 ;
return V_43 ;
case V_44 :
V_3 = F_2 ( V_2 -> V_4 , V_45 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_39 = 0 ;
* V_40 = V_46 [ V_3 & V_47 ] ;
return V_48 ;
default:
return - V_49 ;
}
}
static int F_22 ( struct V_1 * V_2 , int V_50 )
{
T_2 V_51 = F_23 ( V_2 -> V_52 [ V_50 ] ) ;
int V_3 ;
V_3 = F_3 ( V_2 -> V_4 , V_53 ,
( ( T_1 * ) & V_51 ) [ 0 ] ) ;
if ( V_3 < 0 )
return V_3 ;
return F_3 ( V_2 -> V_4 , V_53 + 1 ,
( ( T_1 * ) & V_51 ) [ 1 ] ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_50 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_45 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = V_3 & ( ~ V_47 ) ;
V_3 |= V_50 ;
V_3 = F_3 ( V_2 -> V_4 , V_45 , V_3 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_22 ( V_2 , V_50 ) ;
}
static int F_25 ( struct V_37 * V_38 ,
struct V_30 const * V_31 , int V_39 ,
int V_40 , long V_41 )
{
struct V_1 * V_2 = F_21 ( V_38 ) ;
int V_3 , V_54 ;
switch ( V_41 ) {
case V_44 :
if ( V_39 != 0 )
return - V_49 ;
for ( V_54 = 0 ; V_54 < F_26 ( V_46 ) ; V_54 ++ )
if ( V_40 == V_46 [ V_54 ] ) {
F_18 ( & V_2 -> V_33 ) ;
V_3 = F_24 ( V_2 , V_54 ) ;
F_19 ( & V_2 -> V_33 ) ;
return V_3 ;
}
break;
default:
return - V_49 ;
}
return - V_49 ;
}
static int F_27 ( struct V_37 * V_38 ,
enum V_55 V_56 , T_3 V_39 )
{
struct V_1 * V_2 = F_21 ( V_38 ) ;
if ( V_56 == V_57 )
return F_28 ( V_2 -> V_4 ,
V_58 , V_39 ) ;
else if ( V_56 == V_59 )
return F_28 ( V_2 -> V_4 ,
V_60 , V_39 ) ;
return 0 ;
}
static int F_29 ( struct V_37 * V_38 ,
const struct V_30 * V_31 , enum V_61 type ,
enum V_55 V_56 , enum V_62 V_63 , int * V_39 ,
int * V_40 )
{
struct V_1 * V_2 = F_21 ( V_38 ) ;
switch ( V_56 ) {
case V_59 :
F_18 ( & V_2 -> V_33 ) ;
* V_39 = V_2 -> V_64 ;
F_19 ( & V_2 -> V_33 ) ;
break;
case V_57 :
F_18 ( & V_2 -> V_33 ) ;
* V_39 = V_2 -> V_65 ;
F_19 ( & V_2 -> V_33 ) ;
break;
default:
return - V_49 ;
}
return V_43 ;
}
static int F_30 ( struct V_37 * V_38 ,
const struct V_30 * V_31 , enum V_61 type ,
enum V_55 V_56 , enum V_62 V_63 , int V_39 ,
int V_40 )
{
struct V_1 * V_2 = F_21 ( V_38 ) ;
int V_3 ;
if ( V_39 < 0 || V_39 > V_66 || V_40 != 0 )
return - V_49 ;
switch ( V_56 ) {
case V_59 :
F_18 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_67 ) {
V_3 = F_27 ( V_38 , V_56 , V_39 ) ;
if ( V_3 < 0 )
goto V_68;
}
V_2 -> V_64 = V_39 ;
F_19 ( & V_2 -> V_33 ) ;
break;
case V_57 :
F_18 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_69 ) {
V_3 = F_27 ( V_38 , V_56 , V_39 ) ;
if ( V_3 < 0 )
goto V_68;
}
V_2 -> V_65 = V_39 ;
F_19 ( & V_2 -> V_33 ) ;
break;
default:
return - V_49 ;
}
return 0 ;
V_68:
F_19 ( & V_2 -> V_33 ) ;
return V_3 ;
}
static int F_31 ( struct V_37 * V_38 ,
const struct V_30 * V_31 , enum V_61 type ,
enum V_55 V_56 )
{
struct V_1 * V_2 = F_21 ( V_38 ) ;
int V_3 ;
switch ( V_56 ) {
case V_59 :
F_18 ( & V_2 -> V_33 ) ;
V_3 = V_2 -> V_67 ;
F_19 ( & V_2 -> V_33 ) ;
break;
case V_57 :
F_18 ( & V_2 -> V_33 ) ;
V_3 = V_2 -> V_69 ;
F_19 ( & V_2 -> V_33 ) ;
break;
default:
V_3 = - V_49 ;
break;
}
return V_3 ;
}
static int F_32 ( struct V_37 * V_38 ,
const struct V_30 * V_31 , enum V_61 type ,
enum V_55 V_56 , int V_26 )
{
struct V_1 * V_2 = F_21 ( V_38 ) ;
int V_3 ;
T_3 V_70 ;
F_18 ( & V_2 -> V_33 ) ;
switch ( V_56 ) {
case V_59 :
if ( V_2 -> V_67 == V_26 ) {
F_19 ( & V_2 -> V_33 ) ;
return 0 ;
}
V_70 = V_71 ;
if ( V_26 ) {
V_2 -> V_14 = V_72 ;
V_3 = F_12 ( V_2 , true ) ;
if ( V_3 < 0 )
goto V_68;
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
goto V_73;
V_70 = V_2 -> V_64 ;
}
V_3 = F_27 ( V_38 , V_56 , V_70 ) ;
if ( V_3 < 0 )
goto V_73;
V_2 -> V_67 = V_26 ;
break;
case V_57 :
if ( V_2 -> V_69 == V_26 ) {
F_19 ( & V_2 -> V_33 ) ;
return 0 ;
}
V_70 = V_74 ;
if ( V_26 ) {
V_2 -> V_14 = V_72 ;
V_3 = F_12 ( V_2 , true ) ;
if ( V_3 < 0 )
goto V_68;
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
goto V_73;
V_70 = V_2 -> V_65 ;
}
V_3 = F_27 ( V_38 , V_56 , V_70 ) ;
if ( V_3 < 0 )
goto V_73;
V_2 -> V_69 = V_26 ;
break;
default:
V_3 = - V_49 ;
goto V_68;
}
if ( ! V_26 ) {
V_3 = F_12 ( V_2 , false ) ;
if ( V_3 < 0 )
goto V_68;
}
if ( ! V_2 -> V_69 && ! V_2 -> V_67 && ! V_2 -> V_75 )
V_2 -> V_14 = V_15 ;
F_19 ( & V_2 -> V_33 ) ;
return 0 ;
V_73:
if ( V_26 )
F_12 ( V_2 , false ) ;
V_68:
F_19 ( & V_2 -> V_33 ) ;
return V_3 ;
}
static int F_33 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_21 ( V_38 ) ;
return F_3 ( V_2 -> V_4 , V_76 ,
V_77 ) ;
}
static int F_34 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_21 ( V_38 ) ;
int V_54 , V_3 ;
V_3 = F_33 ( V_38 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_8 = 0 ;
V_2 -> V_14 = V_72 ;
V_2 -> V_65 = V_78 ;
V_2 -> V_64 = V_79 ;
for ( V_54 = 0 ; V_54 < F_26 ( V_80 ) ; V_54 ++ ) {
V_3 = F_3 ( V_2 -> V_4 ,
V_80 [ V_54 ] . V_81 ,
V_80 [ V_54 ] . V_39 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_2 -> V_18 = true ;
V_2 -> V_17 = true ;
if ( ! V_2 -> V_75 ) {
V_3 = F_11 ( V_2 , V_27 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_14 = V_15 ;
}
return V_3 ;
}
static void F_35 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_21 ( V_38 ) ;
if ( F_36 ( & V_2 -> V_4 -> V_29 , L_1 ,
& V_2 -> V_23 ) )
V_2 -> V_23 = V_24 ;
if ( F_37 ( & V_2 -> V_4 -> V_29 ,
L_2 ,
V_2 -> V_52 ,
F_26 ( V_82 ) ) )
V_2 -> V_52 = V_82 ;
if ( F_38 ( & V_2 -> V_4 -> V_29 ,
L_3 ,
& V_2 -> V_83 ) )
V_2 -> V_83 = V_84 ;
if ( F_38 ( & V_2 -> V_4 -> V_29 ,
L_4 ,
& V_2 -> V_85 ) )
V_2 -> V_85 = V_86 ;
V_2 -> V_75 = F_39 ( & V_2 -> V_4 -> V_29 ,
L_5 ) ;
}
static int F_40 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_21 ( V_38 ) ;
int V_3 ;
V_3 = F_22 ( V_2 , V_87 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_2 -> V_4 ,
V_88 ,
V_2 -> V_85 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_2 -> V_4 ,
V_89 ,
V_2 -> V_83 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_3 ( V_2 -> V_4 , V_90 ,
V_91 ) ;
}
static T_4 F_41 ( int V_92 , void * V_93 )
{
struct V_37 * V_38 = V_93 ;
struct V_1 * V_2 = F_21 ( V_38 ) ;
enum V_55 V_56 ;
int V_3 ;
T_5 V_94 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( V_3 < 0 ) {
F_42 ( & V_2 -> V_4 -> V_29 , L_6 ) ;
return V_95 ;
}
V_56 = V_3 & V_96 ? V_59 : V_57 ;
V_94 = F_43 ( V_97 , 1 , V_98 , V_56 ) ;
F_44 ( V_38 , V_94 , F_45 () ) ;
V_3 = F_3 ( V_2 -> V_4 , V_5 ,
V_3 & ~ V_99 ) ;
if ( V_3 < 0 )
F_42 ( & V_2 -> V_4 -> V_29 , L_6 ) ;
return V_95 ;
}
static int F_46 ( struct V_100 * V_4 ,
const struct V_101 * V_102 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 ;
int V_3 ;
V_38 = F_47 ( & V_4 -> V_29 , sizeof( * V_2 ) ) ;
if ( ! V_38 )
return - V_103 ;
V_2 = F_21 ( V_38 ) ;
F_48 ( V_4 , V_38 ) ;
V_2 -> V_4 = V_4 ;
F_49 ( & V_2 -> V_33 ) ;
V_38 -> V_29 . V_104 = & V_4 -> V_29 ;
V_38 -> V_63 = & V_105 ;
V_38 -> V_106 = V_107 ;
V_38 -> V_108 = V_109 ;
V_38 -> V_110 = F_26 ( V_109 ) ;
V_38 -> V_111 = V_112 ;
V_3 = F_2 ( V_2 -> V_4 , V_113 ) ;
if ( V_3 != V_114 ) {
F_42 ( & V_2 -> V_4 -> V_29 ,
L_7 ) ;
return ( V_3 < 0 ) ? V_3 : - V_115 ;
}
if ( V_4 -> V_92 > 0 ) {
V_3 = F_50 ( & V_4 -> V_29 , V_4 -> V_92 , NULL ,
F_41 ,
V_116 | V_117 ,
L_8 , V_38 ) ;
if ( V_3 < 0 )
return V_3 ;
} else
F_51 ( & V_4 -> V_29 , L_9 ) ;
F_35 ( V_38 ) ;
V_3 = F_34 ( V_38 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_40 ( V_38 ) ;
if ( V_3 < 0 )
goto V_34;
if ( V_2 -> V_75 ) {
F_52 ( & V_4 -> V_29 ) ;
if ( V_3 < 0 )
goto V_34;
}
F_53 ( & V_4 -> V_29 ) ;
F_54 ( & V_4 -> V_29 ,
V_118 ) ;
F_55 ( & V_4 -> V_29 ) ;
V_3 = F_56 ( V_38 ) ;
if ( V_3 < 0 )
goto V_34;
return 0 ;
V_34:
F_11 ( V_2 , V_27 ) ;
return V_3 ;
}
static int F_57 ( struct V_100 * V_4 )
{
struct V_1 * V_2 = F_21 ( F_58 ( V_4 ) ) ;
F_59 ( F_58 ( V_4 ) ) ;
F_60 ( & V_4 -> V_29 ) ;
F_61 ( & V_4 -> V_29 ) ;
return F_11 ( V_2 , V_27 ) ;
}
static int F_62 ( struct V_119 * V_29 )
{
struct V_37 * V_38 = F_58 ( F_63 ( V_29 ) ) ;
struct V_1 * V_2 = F_21 ( V_38 ) ;
if ( V_2 -> V_14 == V_72 )
return F_11 ( V_2 , V_27 ) ;
return 0 ;
}
static int F_64 ( struct V_119 * V_29 )
{
struct V_37 * V_38 = F_58 ( F_63 ( V_29 ) ) ;
struct V_1 * V_2 = F_21 ( V_38 ) ;
if ( V_2 -> V_14 == V_72 )
return F_11 ( V_2 ,
~ V_27 & 0xff ) ;
return 0 ;
}
