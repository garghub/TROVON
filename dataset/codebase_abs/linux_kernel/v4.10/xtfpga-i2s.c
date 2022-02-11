static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 >= V_4 ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 < V_5 ;
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 == V_6 ;
}
static bool F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
bool V_11 ;
F_5 () ;
V_10 = F_6 ( V_8 -> V_10 ) ;
V_11 = V_10 && F_7 ( V_10 ) ;
if ( V_11 ) {
unsigned V_12 = F_8 ( V_8 -> V_12 ) ;
unsigned V_13 = V_8 -> V_14 ( V_8 , V_10 -> V_15 ,
V_12 ) ;
F_9 ( & V_8 -> V_12 , V_12 , V_13 ) ;
}
F_10 () ;
return V_11 ;
}
static void F_11 ( struct V_7 * V_8 )
{
unsigned V_16 ;
unsigned V_17 ;
F_12 ( V_8 -> V_18 , V_6 ,
& V_16 ) ;
for ( V_17 = 0 ; V_17 < 2 ; ++ V_17 ) {
bool V_11 = F_4 ( V_8 ) ;
F_13 ( V_8 -> V_18 , V_6 ,
V_19 ) ;
if ( V_11 )
F_12 ( V_8 -> V_18 , V_6 ,
& V_16 ) ;
if ( ! V_11 ||
! ( V_16 & V_20 ) )
break;
V_8 -> V_21 = V_8 -> V_22 ;
}
if ( ! ( V_16 & V_20 ) )
F_13 ( V_8 -> V_18 , V_23 ,
V_19 ) ;
else if ( ! ( V_16 & V_24 ) )
F_13 ( V_8 -> V_18 , V_23 ,
V_24 ) ;
if ( ! ( V_16 & V_24 ) )
F_14 ( V_8 -> V_18 , V_4 ,
V_25 |
V_26 ,
V_25 |
V_26 ) ;
else
F_14 ( V_8 -> V_18 , V_4 ,
V_25 |
V_26 , 0 ) ;
}
static T_1 F_15 ( int V_27 , void * V_28 )
{
struct V_7 * V_8 = V_28 ;
struct V_9 * V_10 ;
unsigned V_29 , V_16 , V_30 ;
F_12 ( V_8 -> V_18 , V_4 , & V_29 ) ;
F_12 ( V_8 -> V_18 , V_23 , & V_30 ) ;
F_12 ( V_8 -> V_18 , V_6 , & V_16 ) ;
if ( ! ( V_29 & V_25 ) ||
! ( V_16 & V_30 & V_19 ) )
return V_31 ;
if ( V_16 & V_24 ) {
V_8 -> V_21 = 0 ;
F_14 ( V_8 -> V_18 , V_4 ,
V_26 , 0 ) ;
} else {
V_8 -> V_21 = V_8 -> V_22 ;
}
F_5 () ;
V_10 = F_6 ( V_8 -> V_10 ) ;
if ( V_10 && F_7 ( V_10 ) ) {
F_16 ( V_10 ) ;
if ( V_16 & V_24 )
F_17 ( V_8 -> V_2 , L_1 ,
V_32 ) ;
}
F_10 () ;
F_11 ( V_8 ) ;
return V_33 ;
}
static int F_18 ( struct V_9 * V_34 ,
struct V_35 * V_36 )
{
struct V_7 * V_8 = F_19 ( V_36 ) ;
F_20 ( V_36 , V_34 , V_8 ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_34 ,
struct V_37 * V_38 ,
struct V_35 * V_36 )
{
struct V_7 * V_8 = F_19 ( V_36 ) ;
unsigned V_39 = F_22 ( V_38 ) ;
unsigned V_40 = F_23 ( V_38 ) ;
unsigned V_41 = F_24 ( V_38 ) ;
unsigned V_42 = F_25 ( F_26 ( V_38 ) ) ;
unsigned V_43 , V_44 , V_45 ;
int V_46 ;
F_14 ( V_8 -> V_18 , V_4 ,
V_47 ,
V_42 << V_48 ) ;
V_43 = 256 * V_39 ;
V_46 = F_27 ( V_8 -> V_49 , V_43 ) ;
if ( V_46 < 0 )
return V_46 ;
V_44 = ( V_43 - ( V_39 * V_42 * 8 ) ) /
( V_39 * V_42 * 4 ) ;
F_14 ( V_8 -> V_18 , V_4 ,
V_50 ,
V_44 << V_51 ) ;
V_8 -> V_22 = V_52 / 2 ;
for ( V_45 = 1 ;
V_8 -> V_22 / 2 >= V_41 * 2 &&
V_45 < ( V_53 >>
V_54 ) ; ++ V_45 )
V_8 -> V_22 /= 2 ;
V_8 -> V_55 = 2 * V_8 -> V_22 ;
F_14 ( V_8 -> V_18 , V_4 ,
V_53 ,
V_45 << V_54 ) ;
F_28 ( V_8 -> V_2 ,
L_2 ,
V_32 , V_39 , V_40 , V_42 , V_41 ) ;
F_28 ( V_8 -> V_2 , L_3 ,
V_32 , V_43 , V_44 , V_45 ) ;
return 0 ;
}
static int F_29 ( struct V_35 * V_56 ,
unsigned int V_57 )
{
if ( ( V_57 & V_58 ) != V_59 )
return - V_60 ;
if ( ( V_57 & V_61 ) != V_62 )
return - V_60 ;
if ( ( V_57 & V_63 ) != V_64 )
return - V_60 ;
return 0 ;
}
static int F_30 ( struct V_9 * V_34 )
{
struct V_65 * V_15 = V_34 -> V_15 ;
struct V_66 * V_67 = V_34 -> V_68 ;
void * V_69 ;
F_31 ( V_34 , & V_70 ) ;
V_69 = F_32 ( V_67 -> V_56 , V_34 ) ;
V_15 -> V_68 = V_69 ;
return 0 ;
}
static int F_33 ( struct V_9 * V_34 )
{
F_34 () ;
return 0 ;
}
static int F_35 ( struct V_9 * V_34 ,
struct V_37 * V_71 )
{
int V_72 ;
struct V_65 * V_15 = V_34 -> V_15 ;
struct V_7 * V_8 = V_15 -> V_68 ;
unsigned V_40 = F_23 ( V_71 ) ;
switch ( V_40 ) {
case 1 :
case 2 :
break;
default:
return - V_60 ;
}
switch ( F_26 ( V_71 ) ) {
case V_73 :
V_8 -> V_14 = ( V_40 == 1 ) ?
V_74 :
V_75 ;
break;
case V_76 :
V_8 -> V_14 = ( V_40 == 1 ) ?
V_77 :
V_78 ;
break;
default:
return - V_60 ;
}
V_72 = F_36 ( V_34 ,
F_37 ( V_71 ) ) ;
return V_72 ;
}
static int F_38 ( struct V_9 * V_34 , int V_79 )
{
int V_72 = 0 ;
struct V_65 * V_15 = V_34 -> V_15 ;
struct V_7 * V_8 = V_15 -> V_68 ;
switch ( V_79 ) {
case V_80 :
case V_81 :
case V_82 :
F_8 ( V_8 -> V_12 ) = 0 ;
F_39 ( V_8 -> V_10 , V_34 ) ;
F_11 ( V_8 ) ;
break;
case V_83 :
case V_84 :
case V_85 :
F_39 ( V_8 -> V_10 , NULL ) ;
break;
default:
V_72 = - V_60 ;
break;
}
return V_72 ;
}
static T_2 F_40 ( struct V_9 * V_34 )
{
struct V_65 * V_15 = V_34 -> V_15 ;
struct V_7 * V_8 = V_15 -> V_68 ;
T_2 V_86 = F_8 ( V_8 -> V_12 ) ;
return V_86 < V_15 -> V_87 ? V_86 : 0 ;
}
static int F_41 ( struct V_66 * V_67 )
{
struct V_88 * V_89 = V_67 -> V_89 -> V_88 ;
T_3 V_90 = V_70 . V_91 ;
return F_42 ( V_67 -> V_92 ,
V_93 ,
V_89 -> V_2 , V_90 , V_90 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_44 ( V_2 ) ;
F_45 ( V_8 -> V_49 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_44 ( V_2 ) ;
int V_72 ;
V_72 = F_47 ( V_8 -> V_49 ) ;
if ( V_72 ) {
F_48 ( V_2 , L_4 , V_72 ) ;
return V_72 ;
}
return 0 ;
}
static int F_49 ( struct V_94 * V_95 )
{
struct V_7 * V_8 ;
struct V_96 * V_97 ;
int V_46 , V_27 ;
V_8 = F_50 ( & V_95 -> V_2 , sizeof( * V_8 ) , V_98 ) ;
if ( ! V_8 ) {
V_46 = - V_99 ;
goto V_46;
}
F_51 ( V_95 , V_8 ) ;
V_8 -> V_2 = & V_95 -> V_2 ;
F_28 ( & V_95 -> V_2 , L_5 , & V_95 -> V_2 , V_8 ) ;
V_97 = F_52 ( V_95 , V_100 , 0 ) ;
V_8 -> V_101 = F_53 ( & V_95 -> V_2 , V_97 ) ;
if ( F_54 ( V_8 -> V_101 ) ) {
V_46 = F_55 ( V_8 -> V_101 ) ;
goto V_46;
}
V_8 -> V_18 = F_56 ( & V_95 -> V_2 , V_8 -> V_101 ,
& V_102 ) ;
if ( F_54 ( V_8 -> V_18 ) ) {
F_48 ( & V_95 -> V_2 , L_6 ) ;
V_46 = F_55 ( V_8 -> V_18 ) ;
goto V_46;
}
V_8 -> V_49 = F_57 ( & V_95 -> V_2 , NULL ) ;
if ( F_54 ( V_8 -> V_49 ) ) {
F_48 ( & V_95 -> V_2 , L_7 ) ;
V_46 = F_55 ( V_8 -> V_49 ) ;
goto V_46;
}
F_13 ( V_8 -> V_18 , V_4 ,
( 0x1 << V_103 ) ) ;
F_13 ( V_8 -> V_18 , V_6 , V_19 ) ;
F_13 ( V_8 -> V_18 , V_23 , V_24 ) ;
V_27 = F_58 ( V_95 , 0 ) ;
if ( V_27 < 0 ) {
F_48 ( & V_95 -> V_2 , L_8 ) ;
V_46 = V_27 ;
goto V_46;
}
V_46 = F_59 ( & V_95 -> V_2 , V_27 , NULL ,
F_15 ,
V_104 | V_105 ,
V_95 -> V_106 , V_8 ) ;
if ( V_46 < 0 ) {
F_48 ( & V_95 -> V_2 , L_9 ) ;
goto V_46;
}
V_46 = F_60 ( & V_95 -> V_2 , & V_107 ) ;
if ( V_46 < 0 ) {
F_48 ( & V_95 -> V_2 , L_10 ) ;
goto V_46;
}
V_46 = F_61 ( & V_95 -> V_2 ,
& V_108 ,
V_109 ,
F_62 ( V_109 ) ) ;
if ( V_46 < 0 ) {
F_48 ( & V_95 -> V_2 , L_11 ) ;
goto V_110;
}
F_63 ( & V_95 -> V_2 ) ;
if ( ! F_64 ( & V_95 -> V_2 ) ) {
V_46 = F_46 ( & V_95 -> V_2 ) ;
if ( V_46 )
goto V_111;
}
return 0 ;
V_111:
F_65 ( & V_95 -> V_2 ) ;
V_110:
F_66 ( & V_95 -> V_2 ) ;
V_46:
F_48 ( & V_95 -> V_2 , L_12 , V_32 , V_46 ) ;
return V_46 ;
}
static int F_67 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = F_44 ( & V_95 -> V_2 ) ;
F_66 ( & V_95 -> V_2 ) ;
if ( V_8 -> V_18 && ! F_54 ( V_8 -> V_18 ) ) {
F_13 ( V_8 -> V_18 , V_4 , 0 ) ;
F_13 ( V_8 -> V_18 , V_23 , 0 ) ;
F_13 ( V_8 -> V_18 , V_6 ,
V_19 ) ;
}
F_65 ( & V_95 -> V_2 ) ;
if ( ! F_68 ( & V_95 -> V_2 ) )
F_43 ( & V_95 -> V_2 ) ;
return 0 ;
}
