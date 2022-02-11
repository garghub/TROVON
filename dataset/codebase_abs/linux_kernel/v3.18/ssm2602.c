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
case 16 :
V_18 = 0x0 ;
break;
case 20 :
V_18 = 0x4 ;
break;
case 24 :
V_18 = 0x8 ;
break;
case 32 :
V_18 = 0xc ;
break;
default:
return - V_6 ;
}
F_8 ( V_16 -> V_19 , V_21 ,
V_22 , V_18 ) ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_4 ( V_14 ) ;
if ( V_16 -> V_23 ) {
F_10 ( V_8 -> V_24 , 0 ,
V_25 ,
V_16 -> V_23 ) ;
}
return 0 ;
}
static int F_11 ( struct V_11 * V_12 , int V_26 )
{
struct V_15 * V_16 = F_4 ( V_12 -> V_14 ) ;
if ( V_26 )
F_8 ( V_16 -> V_19 , V_27 ,
V_28 ,
V_28 ) ;
else
F_8 ( V_16 -> V_19 , V_27 ,
V_28 , 0 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_29 ,
int V_30 , unsigned int V_31 , int V_32 )
{
struct V_13 * V_14 = V_29 -> V_14 ;
struct V_15 * V_16 = F_4 ( V_14 ) ;
if ( V_32 == V_33 ) {
if ( V_30 != V_34 )
return - V_6 ;
switch ( V_31 ) {
case 12288000 :
case 18432000 :
V_16 -> V_23 = & V_35 ;
break;
case 11289600 :
case 16934400 :
V_16 -> V_23 = & V_36 ;
break;
case 12000000 :
V_16 -> V_23 = NULL ;
break;
default:
return - V_6 ;
}
V_16 -> V_17 = V_31 ;
} else {
unsigned int V_37 ;
switch ( V_30 ) {
case V_38 :
V_37 = V_39 ;
break;
case V_40 :
V_37 = V_41 ;
break;
default:
return - V_6 ;
}
if ( V_31 == 0 )
V_16 -> V_42 |= V_37 ;
else
V_16 -> V_42 &= ~ V_37 ;
F_8 ( V_16 -> V_19 , V_43 ,
V_39 | V_41 , V_16 -> V_42 ) ;
}
return 0 ;
}
static int F_13 ( struct V_11 * V_29 ,
unsigned int V_44 )
{
struct V_15 * V_16 = F_4 ( V_29 -> V_14 ) ;
unsigned int V_18 = 0 ;
switch ( V_44 & V_45 ) {
case V_46 :
V_18 |= 0x0040 ;
break;
case V_47 :
break;
default:
return - V_6 ;
}
switch ( V_44 & V_48 ) {
case V_49 :
V_18 |= 0x0002 ;
break;
case V_50 :
break;
case V_51 :
V_18 |= 0x0001 ;
break;
case V_52 :
V_18 |= 0x0013 ;
break;
case V_53 :
V_18 |= 0x0003 ;
break;
default:
return - V_6 ;
}
switch ( V_44 & V_54 ) {
case V_55 :
break;
case V_56 :
V_18 |= 0x0090 ;
break;
case V_57 :
V_18 |= 0x0080 ;
break;
case V_58 :
V_18 |= 0x0010 ;
break;
default:
return - V_6 ;
}
F_6 ( V_16 -> V_19 , V_21 , V_18 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 ,
enum V_59 V_60 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
switch ( V_60 ) {
case V_61 :
F_8 ( V_16 -> V_19 , V_43 ,
V_62 | V_39 | V_41 ,
V_16 -> V_42 ) ;
break;
case V_63 :
break;
case V_64 :
F_8 ( V_16 -> V_19 , V_43 ,
V_62 | V_39 | V_41 ,
V_39 | V_41 ) ;
break;
case V_65 :
F_8 ( V_16 -> V_19 , V_43 ,
V_62 , V_62 ) ;
break;
}
V_14 -> V_66 . V_67 = V_60 ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
F_16 ( V_16 -> V_19 ) ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
struct V_68 * V_66 = & V_14 -> V_66 ;
int V_69 ;
F_8 ( V_16 -> V_19 , V_70 ,
V_71 , V_71 ) ;
F_8 ( V_16 -> V_19 , V_72 ,
V_73 , V_73 ) ;
V_69 = F_18 ( V_14 , V_74 ,
F_2 ( V_74 ) ) ;
if ( V_69 )
return V_69 ;
V_69 = F_19 ( V_66 , V_75 ,
F_2 ( V_75 ) ) ;
if ( V_69 )
return V_69 ;
return F_20 ( V_66 , V_76 ,
F_2 ( V_76 ) ) ;
}
static int F_21 ( struct V_13 * V_14 )
{
struct V_68 * V_66 = & V_14 -> V_66 ;
int V_69 ;
V_69 = F_19 ( V_66 , V_77 ,
F_2 ( V_77 ) ) ;
if ( V_69 )
return V_69 ;
return F_20 ( V_66 , V_78 ,
F_2 ( V_78 ) ) ;
}
static int F_22 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_4 ( V_14 ) ;
int V_69 ;
V_69 = F_6 ( V_16 -> V_19 , V_79 , 0 ) ;
if ( V_69 < 0 ) {
F_23 ( V_14 -> V_80 , L_1 , V_69 ) ;
return V_69 ;
}
F_8 ( V_16 -> V_19 , V_81 ,
V_82 , V_82 ) ;
F_8 ( V_16 -> V_19 , V_83 ,
V_84 , V_84 ) ;
F_6 ( V_16 -> V_19 , V_85 , V_86 |
V_87 ) ;
switch ( V_16 -> type ) {
case V_88 :
V_69 = F_17 ( V_14 ) ;
break;
case V_89 :
V_69 = F_21 ( V_14 ) ;
break;
}
return V_69 ;
}
static bool F_24 ( struct V_90 * V_80 , unsigned int V_91 )
{
return V_91 == V_79 ;
}
int F_25 ( struct V_90 * V_80 , enum V_92 type ,
struct V_19 * V_19 )
{
struct V_15 * V_16 ;
if ( F_26 ( V_19 ) )
return F_27 ( V_19 ) ;
V_16 = F_28 ( V_80 , sizeof( * V_16 ) , V_93 ) ;
if ( V_16 == NULL )
return - V_94 ;
F_29 ( V_80 , V_16 ) ;
V_16 -> type = type ;
V_16 -> V_19 = V_19 ;
return F_30 ( V_80 , & V_95 ,
& V_96 , 1 ) ;
}
