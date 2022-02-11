static int F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
switch ( V_5 ) {
case V_9 :
F_3 ( 10000 , 10100 ) ;
F_4 ( V_7 , V_10 [ V_2 -> V_11 ] ,
F_5 ( V_7 , V_10 [ V_2 -> V_11 ] ) ) ;
break;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
unsigned int V_12 = V_2 -> V_11 + 1 ;
T_1 V_13 , V_14 , V_15 ;
T_2 V_16 ;
V_13 = V_17 ;
V_14 = V_18 + 32 * ( V_12 - 1 ) ;
V_15 = V_19 + 32 * ( V_12 - 1 ) ;
switch ( V_5 ) {
case V_20 :
F_7 ( V_7 , V_14 ,
V_21 ,
V_22 ) ;
V_16 = F_5 ( V_7 , V_15 ) &
V_23 ;
V_16 >>= V_24 ;
if ( V_16 != V_25 ) {
F_7 ( V_7 , V_15 ,
V_23 ,
V_25 ) ;
}
break;
case V_9 :
F_7 ( V_7 , V_15 ,
V_26 ,
V_27 ) ;
F_4 ( V_7 , V_28 [ V_2 -> V_11 ] ,
F_5 ( V_7 , V_28 [ V_2 -> V_11 ] ) ) ;
F_7 ( V_7 , V_14 ,
V_21 , 0 ) ;
break;
case V_29 :
F_7 ( V_7 , V_14 ,
V_21 ,
V_22 ) ;
F_7 ( V_7 , V_15 ,
V_26 ,
V_30 ) ;
break;
case V_31 :
F_7 ( V_7 , V_13 , 1 << V_2 -> V_11 ,
1 << V_2 -> V_11 ) ;
F_7 ( V_7 , V_13 , 1 << V_2 -> V_11 , 0x0 ) ;
F_7 ( V_7 , V_15 ,
V_26 ,
V_30 ) ;
F_7 ( V_7 , V_14 ,
V_21 , 0 ) ;
break;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
unsigned int V_32 ;
int V_33 ;
char * V_34 = strpbrk ( V_2 -> V_35 , L_1 ) ;
if ( V_34 == NULL ) {
F_9 ( V_7 -> V_36 , L_2 ) ;
return - V_37 ;
}
V_33 = F_10 ( V_34 , 10 , & V_32 ) ;
if ( V_33 < 0 || V_32 > 2 ) {
F_9 ( V_7 -> V_36 , L_3 ) ;
return - V_37 ;
}
switch ( V_5 ) {
case V_20 :
F_7 ( V_7 , V_38 ,
V_39 ,
V_40 ) ;
switch ( V_32 ) {
case 1 :
F_7 ( V_7 , V_41 ,
V_42 ,
V_43 ) ;
break;
case 2 :
F_7 ( V_7 , V_44 ,
V_42 ,
V_43 ) ;
break;
}
break;
}
return 0 ;
}
static int F_11 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_49 * V_36 = & V_46 -> V_36 ;
V_48 -> V_50 = F_12 ( V_36 , L_4 ) ;
if ( F_13 ( V_48 -> V_50 ) ) {
F_9 ( V_36 , L_5 ) ;
return F_14 ( V_48 -> V_50 ) ;
}
V_48 -> V_51 = F_12 ( V_36 , L_6 ) ;
if ( F_13 ( V_48 -> V_51 ) ) {
F_9 ( V_36 , L_7 ) ;
return F_14 ( V_48 -> V_51 ) ;
}
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_47 * V_48 = F_16 ( V_7 -> V_36 ) ;
F_17 ( V_7 , V_48 ) ;
return 0 ;
}
static int F_18 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_56 * V_57 )
{
T_2 V_58 ;
T_2 V_59 ;
switch ( F_19 ( V_55 ) ) {
case 8000 :
V_58 = V_60 ;
V_59 = V_61 ;
break;
case 16000 :
V_58 = V_62 ;
V_59 = V_63 ;
break;
case 32000 :
V_58 = V_64 ;
V_59 = V_65 ;
break;
case 48000 :
V_58 = V_66 ;
V_59 = V_67 ;
break;
default:
F_9 ( V_57 -> V_7 -> V_36 , L_8 ,
F_19 ( V_55 ) ) ;
return - V_37 ;
}
switch ( V_53 -> V_68 ) {
case V_69 :
F_7 ( V_57 -> V_7 , V_70 ,
V_71 , V_58 ) ;
break;
case V_72 :
F_7 ( V_57 -> V_7 , V_73 ,
V_74 , V_59 ) ;
break;
default:
return - V_37 ;
}
switch ( F_20 ( V_55 ) ) {
case V_75 :
F_7 ( V_57 -> V_7 , V_70 ,
V_76 ,
V_77 ) ;
F_7 ( V_57 -> V_7 , V_73 ,
V_78 ,
V_79 ) ;
break;
case V_80 :
F_7 ( V_57 -> V_7 , V_70 ,
V_76 ,
V_81 ) ;
F_7 ( V_57 -> V_7 , V_73 ,
V_78 ,
V_82 ) ;
break;
default:
F_9 ( V_57 -> V_36 , L_9 , V_83 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_21 ( struct V_52 * V_53 ,
struct V_56 * V_57 )
{
struct V_6 * V_7 = V_57 -> V_7 ;
struct V_47 * V_84 ;
unsigned long V_85 ;
V_84 = F_22 ( V_7 ) ;
F_7 ( V_7 , V_86 ,
V_87 ,
V_88 ) ;
F_7 ( V_7 , V_89 ,
V_90 ,
V_91 ) ;
V_85 = F_23 ( V_84 -> V_51 ) ;
switch ( V_85 ) {
case 12288000 :
F_7 ( V_7 , V_92 ,
V_93 ,
V_94 ) ;
break;
case 9600000 :
F_7 ( V_7 , V_92 ,
V_93 ,
V_95 ) ;
break;
default:
F_9 ( V_7 -> V_36 , L_10 , V_85 ) ;
break;
}
return 0 ;
}
static void F_24 ( struct V_52 * V_53 ,
struct V_56 * V_57 )
{
F_7 ( V_57 -> V_7 , V_89 ,
V_90 , 0 ) ;
}
static int F_25 ( struct V_45 * V_46 )
{
struct V_47 * V_48 ;
struct V_49 * V_36 = & V_46 -> V_36 ;
void T_3 * V_96 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
int V_33 ;
V_48 = F_26 ( V_36 , sizeof( * V_48 ) , V_101 ) ;
if ( ! V_48 )
return - V_102 ;
V_98 = F_27 ( V_46 , V_103 , 0 ) ;
V_96 = F_28 ( & V_46 -> V_36 , V_98 ) ;
if ( F_13 ( V_96 ) )
return F_14 ( V_96 ) ;
V_100 =
F_29 ( & V_46 -> V_36 , V_96 ,
& V_104 ) ;
if ( F_13 ( V_100 ) )
return F_14 ( V_100 ) ;
V_33 = F_11 ( V_46 , V_48 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_30 ( V_48 -> V_50 ) ;
if ( V_33 < 0 ) {
F_9 ( V_36 , L_11 , V_33 ) ;
return V_33 ;
}
V_33 = F_30 ( V_48 -> V_51 ) ;
if ( V_33 < 0 ) {
F_9 ( V_36 , L_12 , V_33 ) ;
return V_33 ;
}
F_31 ( V_36 , V_48 ) ;
return F_32 ( V_36 , & V_105 ,
V_106 ,
F_33 ( V_106 ) ) ;
}
static int F_34 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_16 ( & V_46 -> V_36 ) ;
F_35 ( & V_46 -> V_36 ) ;
F_36 ( V_48 -> V_51 ) ;
F_36 ( V_48 -> V_50 ) ;
return 0 ;
}
