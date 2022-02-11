static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_9 = F_2 ( V_4 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < F_3 ( V_11 ) ; V_10 ++ ) {
if ( V_9 == V_11 [ V_10 ] ) {
F_4 ( V_8 , V_12 ,
0xf << 17 , V_10 << 17 ) ;
return 0 ;
}
}
return - V_13 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_9 = F_2 ( V_4 ) ;
unsigned int V_14 ;
switch ( V_9 ) {
case 8000 :
V_14 = 0 ;
break;
case 16000 :
V_14 = V_15 ;
break;
default:
return - V_13 ;
}
F_4 ( V_8 , V_16 , V_15 ,
V_14 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( V_2 -> V_17 == V_18 )
return F_1 ( V_2 , V_4 , V_6 ) ;
else
return F_5 ( V_2 , V_4 , V_6 ) ;
}
static int F_7 ( struct V_5 * V_6 , unsigned int V_19 ,
unsigned int V_20 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_14 = 0 ;
unsigned int V_21 = F_8 ( 3 ) | V_22 | V_23 |
V_24 | V_25 | V_26 ;
switch ( V_19 & V_27 ) {
case V_28 :
V_14 |= F_8 ( 2 ) ;
break;
case V_29 :
V_14 |= F_8 ( 1 ) ;
break;
default:
return - V_13 ;
}
switch ( V_19 & V_30 ) {
case V_31 :
V_14 |= V_22 ;
break;
case V_32 :
V_14 |= V_22 | V_23 ;
break;
case V_33 :
break;
case V_34 :
V_14 |= V_23 ;
break;
}
switch ( V_19 & V_35 ) {
case V_36 :
V_14 |= V_25 ;
break;
case V_37 :
V_14 |= V_24 ;
break;
case V_38 :
case V_39 :
return - V_13 ;
}
V_14 |= V_26 ;
F_4 ( V_8 , V_20 , V_21 , V_14 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , unsigned int V_19 )
{
if ( V_6 -> V_40 == V_41 )
return F_7 ( V_6 , V_19 , V_12 ) ;
else
return F_7 ( V_6 , V_19 , V_16 ) ;
}
static int F_10 ( struct V_5 * V_6 , unsigned int V_19 )
{
int V_42 ;
V_42 = F_7 ( V_6 , V_19 , V_12 ) ;
if ( V_42 )
return V_42 ;
V_19 &= ~ V_35 ;
V_19 |= V_37 ;
V_42 = F_7 ( V_6 , V_19 , V_16 ) ;
return V_42 ;
}
static int F_11 ( struct V_5 * V_6 ,
int V_43 , unsigned int V_44 , int V_45 ,
unsigned int V_20 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_46 ;
unsigned int V_14 = 0 ;
unsigned int V_21 = F_12 ( 0x7 ) | V_47 ;
for ( V_46 = 0 ; V_46 < F_3 ( V_48 ) ; V_46 ++ ) {
if ( V_48 [ V_46 ] < 0 )
continue;
if ( V_48 [ V_46 ] == V_44 )
break;
}
if ( V_46 == F_3 ( V_48 ) )
return - V_13 ;
if ( V_43 == V_49 )
V_14 |= V_47 ;
V_14 |= F_12 ( V_46 ) ;
F_4 ( V_8 , V_20 , V_21 , V_14 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 ,
int V_43 , unsigned int V_44 , int V_45 )
{
return F_11 ( V_6 , V_43 , V_44 , V_45 , V_12 ) ;
}
static int F_14 ( struct V_5 * V_6 ,
int V_43 , unsigned int V_44 , int V_45 )
{
return F_11 ( V_6 , V_43 , V_44 , V_45 , V_16 ) ;
}
static int F_15 ( struct V_5 * V_6 ,
int V_43 , unsigned int V_44 , int V_45 )
{
int V_42 ;
V_42 = F_11 ( V_6 , V_43 , V_44 , V_45 , V_12 ) ;
if ( V_42 )
return V_42 ;
return F_11 ( V_6 , V_43 , V_44 , V_45 , V_16 ) ;
}
static int F_16 ( struct V_5 * V_6 ,
unsigned int V_50 , unsigned int V_51 , int V_52 ,
int V_53 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_14 = 0 ;
unsigned int V_21 = V_54 |
V_55 ;
switch ( V_52 ) {
case 2 :
V_14 |= V_56 ;
break;
case 4 :
V_14 |= V_57 ;
break;
case 8 :
V_14 |= V_58 ;
break;
default:
return - V_13 ;
}
switch ( V_51 ) {
case 0xfffffffc :
V_14 |= V_59 ;
break;
case 0xfffffff3 :
V_14 |= V_60 ;
break;
case 0xffffffcf :
V_14 |= V_61 ;
break;
case 0xffffff3f :
V_14 |= V_62 ;
break;
default:
return - V_13 ;
}
F_4 ( V_8 , V_63 , V_21 , V_14 ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
unsigned int V_50 , unsigned int V_51 , int V_52 ,
int V_53 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_14 = 0 ;
unsigned int V_21 = 0x3f ;
if ( V_52 != 4 )
return - V_13 ;
if ( V_50 != 0xfffffffc )
return - V_13 ;
V_14 |= ( 0x00 << 2 ) ;
V_14 |= ( 0x01 << 4 ) ;
F_4 ( V_8 , V_63 , V_21 , V_14 ) ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 ,
unsigned int V_50 , unsigned int V_51 , int V_52 ,
int V_53 )
{
int V_42 ;
V_42 = F_16 ( V_6 , V_50 , V_51 , V_52 ,
V_53 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_17 ( V_6 , V_50 , V_51 , V_52 ,
V_53 ) ;
return V_42 ;
}
static int F_19 ( struct V_7 * V_8 )
{
struct V_64 * V_65 = F_20 ( V_8 ) ;
F_21 ( V_65 -> V_66 , V_67 , 0x25893 ) ;
F_21 ( V_65 -> V_66 , V_68 , 0x00d35A ) ;
F_21 ( V_65 -> V_66 , V_69 , 0x420000 ) ;
F_21 ( V_65 -> V_66 , V_63 , 0x013060 ) ;
F_21 ( V_65 -> V_66 , V_16 , 0x180027 ) ;
F_21 ( V_65 -> V_66 , V_12 , 0x0e0004 ) ;
if ( V_65 -> V_70 == V_71 )
F_22 ( V_65 -> V_66 , V_16 ,
V_72 , 0 ) ;
else
F_22 ( V_65 -> V_66 , V_16 ,
0 , V_72 ) ;
if ( V_65 -> V_73 == V_71 )
F_22 ( V_65 -> V_66 , V_12 ,
V_72 , 0 ) ;
else
F_22 ( V_65 -> V_66 , V_12 ,
0 , V_72 ) ;
return 0 ;
}
static int F_23 ( struct V_7 * V_8 )
{
struct V_64 * V_65 = F_20 ( V_8 ) ;
F_22 ( V_65 -> V_66 , V_67 , 0x3 , 0 ) ;
return 0 ;
}
static struct V_74 * F_24 ( struct V_75 * V_76 )
{
return F_25 ( V_76 -> V_77 , NULL ) ;
}
static int T_1 F_26 ( struct V_78 * V_79 )
{
struct V_64 * V_65 ;
struct V_80 * V_81 = V_79 -> V_76 . V_82 ;
struct V_83 * V_84 ;
int V_42 ;
V_65 = F_27 ( & V_79 -> V_76 , sizeof( * V_65 ) , V_85 ) ;
if ( ! V_65 )
return - V_86 ;
if ( V_81 ) {
V_65 -> V_70 = V_81 -> V_70 ;
V_65 -> V_73 = V_81 -> V_73 ;
} else {
V_84 = F_28 ( V_79 -> V_76 . V_77 -> V_87 , L_1 ) ;
if ( ! V_84 )
return - V_88 ;
V_42 = F_29 ( V_84 , L_2 , & V_65 -> V_70 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_29 ( V_84 , L_3 , & V_65 -> V_73 ) ;
if ( V_42 )
return V_42 ;
}
F_30 ( & V_79 -> V_76 , V_65 ) ;
V_65 -> V_66 = F_31 ( V_79 -> V_76 . V_77 ) ;
if ( V_65 -> V_70 == V_65 -> V_73 )
V_42 = F_32 ( & V_79 -> V_76 , & V_89 ,
V_90 , F_3 ( V_90 ) ) ;
else
V_42 = F_32 ( & V_79 -> V_76 , & V_89 ,
V_91 , F_3 ( V_91 ) ) ;
return V_42 ;
}
static int F_33 ( struct V_78 * V_79 )
{
F_34 ( & V_79 -> V_76 ) ;
return 0 ;
}
