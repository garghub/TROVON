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
static int F_18 ( struct V_6 * V_7 ,
int V_52 , int V_53 ,
unsigned int V_54 , int V_55 )
{
struct V_47 * V_56 = F_16 ( V_7 -> V_36 ) ;
return F_19 ( V_56 -> V_51 , V_54 ) ;
}
static int F_20 ( struct V_57 * V_58 ,
struct V_59 * V_60 ,
struct V_61 * V_62 )
{
T_2 V_63 ;
T_2 V_64 ;
switch ( F_21 ( V_60 ) ) {
case 8000 :
V_63 = V_65 ;
V_64 = V_66 ;
break;
case 16000 :
V_63 = V_67 ;
V_64 = V_68 ;
break;
case 32000 :
V_63 = V_69 ;
V_64 = V_70 ;
break;
case 48000 :
V_63 = V_71 ;
V_64 = V_72 ;
break;
default:
F_9 ( V_62 -> V_7 -> V_36 , L_8 ,
F_21 ( V_60 ) ) ;
return - V_37 ;
}
switch ( V_58 -> V_73 ) {
case V_74 :
F_7 ( V_62 -> V_7 , V_75 ,
V_76 , V_63 ) ;
break;
case V_77 :
F_7 ( V_62 -> V_7 , V_78 ,
V_79 , V_64 ) ;
break;
default:
return - V_37 ;
}
switch ( F_22 ( V_60 ) ) {
case V_80 :
F_7 ( V_62 -> V_7 , V_75 ,
V_81 ,
V_82 ) ;
F_7 ( V_62 -> V_7 , V_78 ,
V_83 ,
V_84 ) ;
break;
case V_85 :
F_7 ( V_62 -> V_7 , V_75 ,
V_81 ,
V_86 ) ;
F_7 ( V_62 -> V_7 , V_78 ,
V_83 ,
V_87 ) ;
break;
default:
F_9 ( V_62 -> V_36 , L_9 , V_88 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_23 ( struct V_57 * V_58 ,
struct V_61 * V_62 )
{
struct V_6 * V_7 = V_62 -> V_7 ;
struct V_47 * V_89 ;
unsigned long V_90 ;
V_89 = F_24 ( V_7 ) ;
F_7 ( V_7 , V_91 ,
V_92 ,
V_93 ) ;
F_7 ( V_7 , V_94 ,
V_95 ,
V_96 ) ;
V_90 = F_25 ( V_89 -> V_51 ) ;
switch ( V_90 ) {
case 12288000 :
F_7 ( V_7 , V_97 ,
V_98 ,
V_99 ) ;
break;
case 9600000 :
F_7 ( V_7 , V_97 ,
V_98 ,
V_100 ) ;
break;
default:
F_9 ( V_7 -> V_36 , L_10 , V_90 ) ;
break;
}
return 0 ;
}
static void F_26 ( struct V_57 * V_58 ,
struct V_61 * V_62 )
{
F_7 ( V_62 -> V_7 , V_94 ,
V_95 , 0 ) ;
}
static int F_27 ( struct V_45 * V_46 )
{
struct V_47 * V_48 ;
struct V_49 * V_36 = & V_46 -> V_36 ;
void T_3 * V_101 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
int V_33 ;
V_48 = F_28 ( V_36 , sizeof( * V_48 ) , V_106 ) ;
if ( ! V_48 )
return - V_107 ;
V_103 = F_29 ( V_46 , V_108 , 0 ) ;
V_101 = F_30 ( & V_46 -> V_36 , V_103 ) ;
if ( F_13 ( V_101 ) )
return F_14 ( V_101 ) ;
V_105 =
F_31 ( & V_46 -> V_36 , V_101 ,
& V_109 ) ;
if ( F_13 ( V_105 ) )
return F_14 ( V_105 ) ;
V_33 = F_11 ( V_46 , V_48 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_32 ( V_48 -> V_50 ) ;
if ( V_33 < 0 ) {
F_9 ( V_36 , L_11 , V_33 ) ;
return V_33 ;
}
V_33 = F_32 ( V_48 -> V_51 ) ;
if ( V_33 < 0 ) {
F_9 ( V_36 , L_12 , V_33 ) ;
return V_33 ;
}
F_33 ( V_36 , V_48 ) ;
return F_34 ( V_36 , & V_110 ,
V_111 ,
F_35 ( V_111 ) ) ;
}
static int F_36 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_16 ( & V_46 -> V_36 ) ;
F_37 ( & V_46 -> V_36 ) ;
F_38 ( V_48 -> V_51 ) ;
F_38 ( V_48 -> V_50 ) ;
return 0 ;
}
