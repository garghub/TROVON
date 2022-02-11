static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 = 0 ;
F_3 ( V_5 -> V_7 ) ;
F_4 ( V_5 -> V_7 , V_3 , & V_6 ) ;
F_5 ( V_5 -> V_7 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_6 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_8 ;
F_3 ( V_5 -> V_7 ) ;
V_8 = F_7 ( V_5 -> V_7 , V_3 , V_6 ) ;
F_5 ( V_5 -> V_7 ) ;
return V_8 ;
}
static int F_8 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_18 = F_9 ( V_12 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_10 ( V_20 ) ; V_19 ++ ) {
if ( V_18 == V_20 [ V_19 ] ) {
F_11 ( V_2 , V_21 ,
0xf << 17 , V_19 << 17 ) ;
return 0 ;
}
}
return - V_22 ;
}
static int F_12 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned int V_18 = F_9 ( V_12 ) ;
unsigned int V_23 ;
switch ( V_18 ) {
case 8000 :
V_23 = 0 ;
break;
case 16000 :
V_23 = V_24 ;
break;
default:
return - V_22 ;
}
F_11 ( V_2 , V_25 , V_24 ,
V_23 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
if ( V_10 -> V_26 == V_27 )
return F_8 ( V_10 , V_12 , V_14 ) ;
else
return F_12 ( V_10 , V_12 , V_14 ) ;
}
static int F_14 ( struct V_13 * V_14 , unsigned int V_28 ,
unsigned int V_3 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
unsigned int V_23 = 0 ;
unsigned int V_29 = F_15 ( 3 ) | V_30 | V_31 |
V_32 | V_33 | V_34 ;
switch ( V_28 & V_35 ) {
case V_36 :
V_23 |= F_15 ( 2 ) ;
break;
case V_37 :
V_23 |= F_15 ( 1 ) ;
break;
default:
return - V_22 ;
}
switch ( V_28 & V_38 ) {
case V_39 :
V_23 |= V_30 ;
break;
case V_40 :
V_23 |= V_30 | V_31 ;
break;
case V_41 :
break;
case V_42 :
V_23 |= V_31 ;
break;
}
switch ( V_28 & V_43 ) {
case V_44 :
V_23 |= V_33 ;
break;
case V_45 :
V_23 |= V_32 ;
break;
case V_46 :
case V_47 :
return - V_22 ;
}
V_23 |= V_34 ;
F_11 ( V_2 , V_3 , V_29 , V_23 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 , unsigned int V_28 )
{
if ( V_14 -> V_48 == V_49 )
return F_14 ( V_14 , V_28 , V_21 ) ;
else
return F_14 ( V_14 , V_28 , V_25 ) ;
}
static int F_17 ( struct V_13 * V_14 , unsigned int V_28 )
{
int V_8 ;
V_8 = F_14 ( V_14 , V_28 , V_21 ) ;
if ( V_8 )
return V_8 ;
V_28 &= ~ V_43 ;
V_28 |= V_45 ;
V_8 = F_14 ( V_14 , V_28 , V_25 ) ;
return V_8 ;
}
static int F_18 ( struct V_13 * V_14 ,
int V_50 , unsigned int V_51 , int V_52 ,
unsigned int V_3 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
int V_53 ;
unsigned int V_23 = 0 ;
unsigned int V_29 = F_19 ( 0x7 ) | V_54 ;
for ( V_53 = 0 ; V_53 < F_10 ( V_55 ) ; V_53 ++ ) {
if ( V_55 [ V_53 ] < 0 )
continue;
if ( V_55 [ V_53 ] == V_51 )
break;
}
if ( V_53 == F_10 ( V_55 ) )
return - V_22 ;
if ( V_50 == V_56 )
V_23 |= V_54 ;
V_23 |= F_19 ( V_53 ) ;
F_11 ( V_2 , V_3 , V_29 , V_23 ) ;
return 0 ;
}
static int F_20 ( struct V_13 * V_14 ,
int V_50 , unsigned int V_51 , int V_52 )
{
return F_18 ( V_14 , V_50 , V_51 , V_52 , V_21 ) ;
}
static int F_21 ( struct V_13 * V_14 ,
int V_50 , unsigned int V_51 , int V_52 )
{
return F_18 ( V_14 , V_50 , V_51 , V_52 , V_25 ) ;
}
static int F_22 ( struct V_13 * V_14 ,
int V_50 , unsigned int V_51 , int V_52 )
{
int V_8 ;
V_8 = F_18 ( V_14 , V_50 , V_51 , V_52 , V_21 ) ;
if ( V_8 )
return V_8 ;
return F_18 ( V_14 , V_50 , V_51 , V_52 , V_25 ) ;
}
static int F_23 ( struct V_13 * V_14 ,
unsigned int V_57 , unsigned int V_58 , int V_59 ,
int V_60 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
unsigned int V_23 = 0 ;
unsigned int V_29 = V_61 |
V_62 ;
switch ( V_59 ) {
case 2 :
V_23 |= V_63 ;
break;
case 4 :
V_23 |= V_64 ;
break;
case 8 :
V_23 |= V_65 ;
break;
default:
return - V_22 ;
}
switch ( V_58 ) {
case 0xfffffffc :
V_23 |= V_66 ;
break;
case 0xfffffff3 :
V_23 |= V_67 ;
break;
case 0xffffffcf :
V_23 |= V_68 ;
break;
case 0xffffff3f :
V_23 |= V_69 ;
break;
default:
return - V_22 ;
} ;
F_11 ( V_2 , V_70 , V_29 , V_23 ) ;
return 0 ;
}
static int F_24 ( struct V_13 * V_14 ,
unsigned int V_57 , unsigned int V_58 , int V_59 ,
int V_60 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
unsigned int V_23 = 0 ;
unsigned int V_29 = 0x3f ;
if ( V_59 != 4 )
return - V_22 ;
if ( V_57 != 0xfffffffc )
return - V_22 ;
V_23 |= ( 0x00 << 2 ) ;
V_23 |= ( 0x01 << 4 ) ;
F_11 ( V_2 , V_70 , V_29 , V_23 ) ;
return 0 ;
}
static int F_25 ( struct V_13 * V_14 ,
unsigned int V_57 , unsigned int V_58 , int V_59 ,
int V_60 )
{
int V_8 ;
V_8 = F_23 ( V_14 , V_57 , V_58 , V_59 ,
V_60 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_24 ( V_14 , V_57 , V_58 , V_59 ,
V_60 ) ;
return V_8 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_2 -> V_71 = V_5 -> V_7 ;
F_3 ( V_5 -> V_7 ) ;
F_7 ( V_5 -> V_7 , V_72 , 0x25893 ) ;
F_7 ( V_5 -> V_7 , V_73 , 0x00d35A ) ;
F_7 ( V_5 -> V_7 , V_74 , 0x420000 ) ;
F_7 ( V_5 -> V_7 , V_70 , 0x013060 ) ;
F_7 ( V_5 -> V_7 , V_25 , 0x180027 ) ;
F_7 ( V_5 -> V_7 , V_21 , 0x0e0004 ) ;
if ( V_5 -> V_75 == V_76 )
F_27 ( V_5 -> V_7 , V_25 ,
V_77 , 0 ) ;
else
F_27 ( V_5 -> V_7 , V_25 ,
0 , V_77 ) ;
if ( V_5 -> V_78 == V_76 )
F_27 ( V_5 -> V_7 , V_21 ,
V_77 , 0 ) ;
else
F_27 ( V_5 -> V_7 , V_21 ,
0 , V_77 ) ;
F_5 ( V_5 -> V_7 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_5 -> V_7 ) ;
F_27 ( V_5 -> V_7 , V_72 , 0x3 , 0 ) ;
F_5 ( V_5 -> V_7 ) ;
return 0 ;
}
static int F_29 ( struct V_79 * V_80 )
{
struct V_7 * V_7 ;
struct V_4 * V_5 ;
struct V_81 * V_82 = V_80 -> V_83 . V_84 ;
int V_8 ;
V_7 = F_30 ( V_80 -> V_83 . V_85 ) ;
V_5 = F_31 ( & V_80 -> V_83 , sizeof( * V_5 ) , V_86 ) ;
if ( V_5 == NULL )
return - V_87 ;
F_32 ( & V_80 -> V_83 , V_5 ) ;
V_5 -> V_7 = V_7 ;
if ( V_82 ) {
V_5 -> V_75 = V_82 -> V_75 ;
V_5 -> V_78 = V_82 -> V_78 ;
} else {
V_5 -> V_75 = V_76 ;
V_5 -> V_78 = V_88 ;
}
if ( V_5 -> V_75 == V_5 -> V_78 )
V_8 = F_33 ( & V_80 -> V_83 , & V_89 ,
V_90 , F_10 ( V_90 ) ) ;
else
V_8 = F_33 ( & V_80 -> V_83 , & V_89 ,
V_91 , F_10 ( V_91 ) ) ;
if ( V_8 )
goto V_92;
return 0 ;
V_92:
F_34 ( & V_80 -> V_83 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_35 ( struct V_79 * V_80 )
{
F_36 ( & V_80 -> V_83 ) ;
return 0 ;
}
