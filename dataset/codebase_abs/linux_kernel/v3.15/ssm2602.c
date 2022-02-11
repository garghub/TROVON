static inline int F_1 ( int V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 &&
V_4 [ V_3 ] . V_1 == V_1 )
return V_4 [ V_3 ] . V_5 ;
}
return - V_6 ;
}
static int F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_4 ( V_14 ) ;
int V_5 = F_1 ( V_16 -> V_17 , F_5 ( V_10 ) ) ;
unsigned int V_18 ;
if ( V_5 < 0 )
return V_5 ;
F_6 ( V_16 -> V_19 , V_20 , V_5 ) ;
switch ( F_7 ( V_10 ) ) {
case V_21 :
V_18 = 0x0 ;
break;
case V_22 :
V_18 = 0x4 ;
break;
case V_23 :
V_18 = 0x8 ;
break;
case V_24 :
V_18 = 0xc ;
break;
default:
return - V_6 ;
}
F_8 ( V_16 -> V_19 , V_25 ,
V_26 , V_18 ) ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_4 ( V_14 ) ;
if ( V_16 -> V_27 ) {
F_10 ( V_8 -> V_28 , 0 ,
V_29 ,
V_16 -> V_27 ) ;
}
return 0 ;
}
static int F_11 ( struct V_11 * V_12 , int V_30 )
{
struct V_15 * V_16 = F_4 ( V_12 -> V_14 ) ;
if ( V_30 )
F_8 ( V_16 -> V_19 , V_31 ,
V_32 ,
V_32 ) ;
else
F_8 ( V_16 -> V_19 , V_31 ,
V_32 , 0 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_33 ,
int V_34 , unsigned int V_35 , int V_36 )
{
struct V_13 * V_14 = V_33 -> V_14 ;
struct V_15 * V_16 = F_4 ( V_14 ) ;
if ( V_36 == V_37 ) {
if ( V_34 != V_38 )
return - V_6 ;
switch ( V_35 ) {
case 12288000 :
case 18432000 :
V_16 -> V_27 = & V_39 ;
break;
case 11289600 :
case 16934400 :
V_16 -> V_27 = & V_40 ;
break;
case 12000000 :
V_16 -> V_27 = NULL ;
break;
default:
return - V_6 ;
}
V_16 -> V_17 = V_35 ;
} else {
unsigned int V_41 ;
switch ( V_34 ) {
case V_42 :
V_41 = V_43 ;
break;
case V_44 :
V_41 = V_45 ;
break;
default:
return - V_6 ;
}
if ( V_35 == 0 )
V_16 -> V_46 |= V_41 ;
else
V_16 -> V_46 &= ~ V_41 ;
F_8 ( V_16 -> V_19 , V_47 ,
V_43 | V_45 , V_16 -> V_46 ) ;
}
return 0 ;
}
static int F_13 ( struct V_11 * V_33 ,
unsigned int V_48 )
{
struct V_15 * V_16 = F_4 ( V_33 -> V_14 ) ;
unsigned int V_18 = 0 ;
switch ( V_48 & V_49 ) {
case V_50 :
V_18 |= 0x0040 ;
break;
case V_51 :
break;
default:
return - V_6 ;
}
switch ( V_48 & V_52 ) {
case V_53 :
V_18 |= 0x0002 ;
break;
case V_54 :
break;
case V_55 :
V_18 |= 0x0001 ;
break;
case V_56 :
V_18 |= 0x0013 ;
break;
case V_57 :
V_18 |= 0x0003 ;
break;
default:
return - V_6 ;
}
switch ( V_48 & V_58 ) {
case V_59 :
break;
case V_60 :
V_18 |= 0x0090 ;
break;
case V_61 :
V_18 |= 0x0080 ;
break;
case V_62 :
V_18 |= 0x0010 ;
break;
default:
return - V_6 ;
}
F_6 ( V_16 -> V_19 , V_25 , V_18 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 ,
enum V_63 V_64 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
switch ( V_64 ) {
case V_65 :
F_8 ( V_16 -> V_19 , V_47 ,
V_66 | V_43 | V_45 ,
V_16 -> V_46 ) ;
break;
case V_67 :
break;
case V_68 :
F_8 ( V_16 -> V_19 , V_47 ,
V_66 | V_43 | V_45 ,
V_43 | V_45 ) ;
break;
case V_69 :
F_8 ( V_16 -> V_19 , V_47 ,
V_66 , V_66 ) ;
break;
}
V_14 -> V_70 . V_71 = V_64 ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 )
{
F_14 ( V_14 , V_69 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
F_17 ( V_16 -> V_19 ) ;
F_14 ( V_14 , V_68 ) ;
return 0 ;
}
static int F_18 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
struct V_72 * V_70 = & V_14 -> V_70 ;
int V_73 ;
F_8 ( V_16 -> V_19 , V_74 ,
V_75 , V_75 ) ;
F_8 ( V_16 -> V_19 , V_76 ,
V_77 , V_77 ) ;
V_73 = F_19 ( V_14 , V_78 ,
F_2 ( V_78 ) ) ;
if ( V_73 )
return V_73 ;
V_73 = F_20 ( V_70 , V_79 ,
F_2 ( V_79 ) ) ;
if ( V_73 )
return V_73 ;
return F_21 ( V_70 , V_80 ,
F_2 ( V_80 ) ) ;
}
static int F_22 ( struct V_13 * V_14 )
{
struct V_72 * V_70 = & V_14 -> V_70 ;
int V_73 ;
V_73 = F_20 ( V_70 , V_81 ,
F_2 ( V_81 ) ) ;
if ( V_73 )
return V_73 ;
return F_21 ( V_70 , V_82 ,
F_2 ( V_82 ) ) ;
}
static int F_23 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
int V_73 ;
V_73 = F_6 ( V_16 -> V_19 , V_83 , 0 ) ;
if ( V_73 < 0 ) {
F_24 ( V_14 -> V_84 , L_1 , V_73 ) ;
return V_73 ;
}
F_8 ( V_16 -> V_19 , V_85 ,
V_86 , V_86 ) ;
F_8 ( V_16 -> V_19 , V_87 ,
V_88 , V_88 ) ;
F_6 ( V_16 -> V_19 , V_89 , V_90 |
V_91 ) ;
switch ( V_16 -> type ) {
case V_92 :
V_73 = F_18 ( V_14 ) ;
break;
case V_93 :
V_73 = F_22 ( V_14 ) ;
break;
}
if ( V_73 )
return V_73 ;
F_14 ( V_14 , V_68 ) ;
return 0 ;
}
static int F_25 ( struct V_13 * V_14 )
{
F_14 ( V_14 , V_69 ) ;
return 0 ;
}
static bool F_26 ( struct V_94 * V_84 , unsigned int V_95 )
{
return V_95 == V_83 ;
}
int F_27 ( struct V_94 * V_84 , enum V_96 type ,
struct V_19 * V_19 )
{
struct V_15 * V_16 ;
if ( F_28 ( V_19 ) )
return F_29 ( V_19 ) ;
V_16 = F_30 ( V_84 , sizeof( * V_16 ) , V_97 ) ;
if ( V_16 == NULL )
return - V_98 ;
F_31 ( V_84 , V_16 ) ;
V_16 -> type = V_92 ;
V_16 -> V_19 = V_19 ;
return F_32 ( V_84 , & V_99 ,
& V_100 , 1 ) ;
}
