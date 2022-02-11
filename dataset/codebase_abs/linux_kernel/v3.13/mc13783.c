static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = V_8 -> V_11 ;
unsigned int V_12 = F_2 ( V_4 ) ;
int V_13 ;
for ( V_13 = 0 ; V_13 < F_3 ( V_14 ) ; V_13 ++ ) {
if ( V_12 == V_14 [ V_13 ] ) {
F_4 ( V_11 , V_15 ,
0xf << 17 , V_13 << 17 ) ;
return 0 ;
}
}
return - V_16 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = V_8 -> V_11 ;
unsigned int V_12 = F_2 ( V_4 ) ;
unsigned int V_17 ;
switch ( V_12 ) {
case 8000 :
V_17 = 0 ;
break;
case 16000 :
V_17 = V_18 ;
break;
default:
return - V_16 ;
}
F_4 ( V_11 , V_19 , V_18 ,
V_17 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( V_2 -> V_20 == V_21 )
return F_1 ( V_2 , V_4 , V_6 ) ;
else
return F_5 ( V_2 , V_4 , V_6 ) ;
}
static int F_7 ( struct V_5 * V_6 , unsigned int V_22 ,
unsigned int V_23 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
unsigned int V_17 = 0 ;
unsigned int V_24 = F_8 ( 3 ) | V_25 | V_26 |
V_27 | V_28 | V_29 ;
switch ( V_22 & V_30 ) {
case V_31 :
V_17 |= F_8 ( 2 ) ;
break;
case V_32 :
V_17 |= F_8 ( 1 ) ;
break;
default:
return - V_16 ;
}
switch ( V_22 & V_33 ) {
case V_34 :
V_17 |= V_25 ;
break;
case V_35 :
V_17 |= V_25 | V_26 ;
break;
case V_36 :
break;
case V_37 :
V_17 |= V_26 ;
break;
}
switch ( V_22 & V_38 ) {
case V_39 :
V_17 |= V_28 ;
break;
case V_40 :
V_17 |= V_27 ;
break;
case V_41 :
case V_42 :
return - V_16 ;
}
V_17 |= V_29 ;
F_4 ( V_11 , V_23 , V_24 , V_17 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , unsigned int V_22 )
{
if ( V_6 -> V_43 == V_44 )
return F_7 ( V_6 , V_22 , V_15 ) ;
else
return F_7 ( V_6 , V_22 , V_19 ) ;
}
static int F_10 ( struct V_5 * V_6 , unsigned int V_22 )
{
int V_45 ;
V_45 = F_7 ( V_6 , V_22 , V_15 ) ;
if ( V_45 )
return V_45 ;
V_22 &= ~ V_38 ;
V_22 |= V_40 ;
V_45 = F_7 ( V_6 , V_22 , V_19 ) ;
return V_45 ;
}
static int F_11 ( struct V_5 * V_6 ,
int V_46 , unsigned int V_47 , int V_48 ,
unsigned int V_23 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
int V_49 ;
unsigned int V_17 = 0 ;
unsigned int V_24 = F_12 ( 0x7 ) | V_50 ;
for ( V_49 = 0 ; V_49 < F_3 ( V_51 ) ; V_49 ++ ) {
if ( V_51 [ V_49 ] < 0 )
continue;
if ( V_51 [ V_49 ] == V_47 )
break;
}
if ( V_49 == F_3 ( V_51 ) )
return - V_16 ;
if ( V_46 == V_52 )
V_17 |= V_50 ;
V_17 |= F_12 ( V_49 ) ;
F_4 ( V_11 , V_23 , V_24 , V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 ,
int V_46 , unsigned int V_47 , int V_48 )
{
return F_11 ( V_6 , V_46 , V_47 , V_48 , V_15 ) ;
}
static int F_14 ( struct V_5 * V_6 ,
int V_46 , unsigned int V_47 , int V_48 )
{
return F_11 ( V_6 , V_46 , V_47 , V_48 , V_19 ) ;
}
static int F_15 ( struct V_5 * V_6 ,
int V_46 , unsigned int V_47 , int V_48 )
{
int V_45 ;
V_45 = F_11 ( V_6 , V_46 , V_47 , V_48 , V_15 ) ;
if ( V_45 )
return V_45 ;
return F_11 ( V_6 , V_46 , V_47 , V_48 , V_19 ) ;
}
static int F_16 ( struct V_5 * V_6 ,
unsigned int V_53 , unsigned int V_54 , int V_55 ,
int V_56 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
unsigned int V_17 = 0 ;
unsigned int V_24 = V_57 |
V_58 ;
switch ( V_55 ) {
case 2 :
V_17 |= V_59 ;
break;
case 4 :
V_17 |= V_60 ;
break;
case 8 :
V_17 |= V_61 ;
break;
default:
return - V_16 ;
}
switch ( V_54 ) {
case 0xfffffffc :
V_17 |= V_62 ;
break;
case 0xfffffff3 :
V_17 |= V_63 ;
break;
case 0xffffffcf :
V_17 |= V_64 ;
break;
case 0xffffff3f :
V_17 |= V_65 ;
break;
default:
return - V_16 ;
}
F_4 ( V_11 , V_66 , V_24 , V_17 ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
unsigned int V_53 , unsigned int V_54 , int V_55 ,
int V_56 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
unsigned int V_17 = 0 ;
unsigned int V_24 = 0x3f ;
if ( V_55 != 4 )
return - V_16 ;
if ( V_53 != 0xfffffffc )
return - V_16 ;
V_17 |= ( 0x00 << 2 ) ;
V_17 |= ( 0x01 << 4 ) ;
F_4 ( V_11 , V_66 , V_24 , V_17 ) ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 ,
unsigned int V_53 , unsigned int V_54 , int V_55 ,
int V_56 )
{
int V_45 ;
V_45 = F_16 ( V_6 , V_53 , V_54 , V_55 ,
V_56 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_17 ( V_6 , V_53 , V_54 , V_55 ,
V_56 ) ;
return V_45 ;
}
static int F_19 ( struct V_10 * V_11 )
{
struct V_67 * V_68 = F_20 ( V_11 ) ;
int V_45 ;
V_11 -> V_69 = F_21 ( V_11 -> V_70 -> V_71 , NULL ) ;
V_45 = F_22 ( V_11 , 8 , 24 , V_72 ) ;
if ( V_45 != 0 ) {
F_23 ( V_11 -> V_70 , L_1 , V_45 ) ;
return V_45 ;
}
F_24 ( V_68 -> V_73 , V_74 , 0x25893 ) ;
F_24 ( V_68 -> V_73 , V_75 , 0x00d35A ) ;
F_24 ( V_68 -> V_73 , V_76 , 0x420000 ) ;
F_24 ( V_68 -> V_73 , V_66 , 0x013060 ) ;
F_24 ( V_68 -> V_73 , V_19 , 0x180027 ) ;
F_24 ( V_68 -> V_73 , V_15 , 0x0e0004 ) ;
if ( V_68 -> V_77 == V_78 )
F_25 ( V_68 -> V_73 , V_19 ,
V_79 , 0 ) ;
else
F_25 ( V_68 -> V_73 , V_19 ,
0 , V_79 ) ;
if ( V_68 -> V_80 == V_78 )
F_25 ( V_68 -> V_73 , V_15 ,
V_79 , 0 ) ;
else
F_25 ( V_68 -> V_73 , V_15 ,
0 , V_79 ) ;
return 0 ;
}
static int F_26 ( struct V_10 * V_11 )
{
struct V_67 * V_68 = F_20 ( V_11 ) ;
F_25 ( V_68 -> V_73 , V_74 , 0x3 , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_81 * V_82 )
{
struct V_73 * V_73 ;
struct V_67 * V_68 ;
struct V_83 * V_84 = V_82 -> V_70 . V_85 ;
int V_45 ;
V_73 = F_28 ( V_82 -> V_70 . V_71 ) ;
V_68 = F_29 ( & V_82 -> V_70 , sizeof( * V_68 ) , V_86 ) ;
if ( V_68 == NULL )
return - V_87 ;
F_30 ( & V_82 -> V_70 , V_68 ) ;
V_68 -> V_73 = V_73 ;
if ( V_84 ) {
V_68 -> V_77 = V_84 -> V_77 ;
V_68 -> V_80 = V_84 -> V_80 ;
} else {
V_68 -> V_77 = V_78 ;
V_68 -> V_80 = V_88 ;
}
if ( V_68 -> V_77 == V_68 -> V_80 )
V_45 = F_31 ( & V_82 -> V_70 , & V_89 ,
V_90 , F_3 ( V_90 ) ) ;
else
V_45 = F_31 ( & V_82 -> V_70 , & V_89 ,
V_91 , F_3 ( V_91 ) ) ;
if ( V_45 )
goto V_92;
return 0 ;
V_92:
F_23 ( & V_82 -> V_70 , L_2 , V_45 ) ;
return V_45 ;
}
static int F_32 ( struct V_81 * V_82 )
{
F_33 ( & V_82 -> V_70 ) ;
return 0 ;
}
