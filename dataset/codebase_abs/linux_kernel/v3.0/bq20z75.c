static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 = 0 ;
int V_7 = 1 ;
if ( V_5 -> V_8 )
V_7 = F_3 ( V_5 -> V_8 -> V_9 + 1 , 1 ) ;
while ( V_7 > 0 ) {
V_6 = F_4 ( V_2 , V_3 ) ;
if ( V_6 >= 0 )
break;
V_7 -- ;
}
if ( V_6 < 0 ) {
F_5 ( & V_2 -> V_10 ,
L_1 ,
V_11 , V_3 ) ;
return V_6 ;
}
return F_6 ( V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_3 V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 = 0 ;
int V_7 = 1 ;
if ( V_5 -> V_8 )
V_7 = F_3 ( V_5 -> V_8 -> V_9 + 1 , 1 ) ;
while ( V_7 > 0 ) {
V_6 = F_8 ( V_2 , V_3 ,
F_6 ( V_12 ) ) ;
if ( V_6 >= 0 )
break;
V_7 -- ;
}
if ( V_6 < 0 ) {
F_5 ( & V_2 -> V_10 ,
L_2 ,
V_11 , V_3 ) ;
return V_6 ;
}
return 0 ;
}
static int F_9 (
struct V_1 * V_2 , enum V_13 V_14 ,
union V_15 * V_16 )
{
T_2 V_6 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_14 == V_17 &&
V_5 -> V_18 ) {
V_6 = F_10 (
V_5 -> V_8 -> V_19 ) ;
if ( V_6 == V_5 -> V_8 -> V_20 )
V_16 -> V_21 = 1 ;
else
V_16 -> V_21 = 0 ;
V_5 -> V_22 = V_16 -> V_21 ;
return V_6 ;
}
V_6 = F_7 ( V_2 ,
V_23 [ V_24 ] . V_25 ,
V_26 ) ;
if ( V_6 < 0 ) {
if ( V_14 == V_17 )
V_16 -> V_21 = 0 ;
return V_6 ;
}
V_6 = F_1 ( V_2 ,
V_23 [ V_24 ] . V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 < V_23 [ V_24 ] . V_27 ||
V_6 > V_23 [ V_24 ] . V_28 ) {
V_16 -> V_21 = 0 ;
return 0 ;
}
V_6 &= 0x0F00 ;
V_6 >>= 8 ;
if ( V_14 == V_17 ) {
if ( V_6 == 0x0F )
V_16 -> V_21 = 0 ;
else
V_16 -> V_21 = 1 ;
} else if ( V_14 == V_29 ) {
if ( V_6 == 0x09 )
V_16 -> V_21 = V_30 ;
else if ( V_6 == 0x0B )
V_16 -> V_21 = V_31 ;
else if ( V_6 == 0x0C )
V_16 -> V_21 = V_32 ;
else
V_16 -> V_21 = V_33 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_34 , enum V_13 V_14 ,
union V_15 * V_16 )
{
T_2 V_6 ;
V_6 = F_1 ( V_2 ,
V_23 [ V_34 ] . V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_23 [ V_34 ] . V_27 < 0 )
V_6 = ( V_35 ) V_6 ;
if ( V_6 >= V_23 [ V_34 ] . V_27 &&
V_6 <= V_23 [ V_34 ] . V_28 ) {
V_16 -> V_21 = V_6 ;
if ( V_14 == V_36 ) {
if ( V_6 & V_37 )
V_16 -> V_21 = V_38 ;
else if ( V_6 & V_39 )
V_16 -> V_21 = V_40 ;
else if ( V_6 & V_41 )
V_16 -> V_21 = V_42 ;
else
V_16 -> V_21 = V_43 ;
}
} else {
if ( V_14 == V_36 )
V_16 -> V_21 = V_44 ;
else
V_16 -> V_21 = 0 ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
enum V_13 V_14 , union V_15 * V_16 )
{
#define F_13 1000
#define F_14 (10 * BASE_UNIT_CONVERSION)
#define F_15 60
#define F_16 2731
switch ( V_14 ) {
case V_45 :
case V_46 :
case V_47 :
V_16 -> V_21 *= F_14 ;
break;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
V_16 -> V_21 *= F_13 ;
break;
case V_54 :
V_16 -> V_21 -= F_16 ;
break;
case V_55 :
case V_56 :
V_16 -> V_21 *= F_15 ;
break;
default:
F_5 ( & V_2 -> V_10 ,
L_3 , V_11 , V_14 ) ;
}
}
static enum V_57
F_17 ( struct V_1 * V_2 ,
enum V_57 V_58 )
{
int V_6 , V_59 ;
V_59 = F_1 ( V_2 , V_60 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( ( V_59 & V_61 ) == V_58 )
return V_58 ;
if ( V_58 == V_62 )
V_6 = V_59 & ~ V_61 ;
else
V_6 = V_59 | V_61 ;
V_6 = F_7 ( V_2 , V_60 , V_6 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_59 & V_61 ;
}
static int F_18 ( struct V_1 * V_2 ,
int V_34 , enum V_13 V_14 ,
union V_15 * V_16 )
{
T_2 V_6 ;
enum V_57 V_58 = V_63 ;
if ( F_19 ( V_14 ) )
V_58 = V_62 ;
V_58 = F_17 ( V_2 , V_58 ) ;
if ( V_58 < 0 )
return V_58 ;
V_6 = F_1 ( V_2 , V_23 [ V_34 ] . V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_14 == V_64 ) {
V_16 -> V_21 = F_20 ( V_6 , 100 ) ;
} else
V_16 -> V_21 = V_6 ;
V_6 = F_17 ( V_2 , V_58 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
union V_15 * V_16 )
{
int V_6 ;
V_6 = F_1 ( V_2 ,
V_23 [ V_65 ] . V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = sprintf ( V_66 , L_4 , V_6 ) ;
V_16 -> V_67 = V_66 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
enum V_13 V_14 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < F_23 ( V_23 ) ; V_68 ++ )
if ( V_14 == V_23 [ V_68 ] . V_14 )
return V_68 ;
F_24 ( & V_2 -> V_10 ,
L_5 , V_11 , V_14 ) ;
return - V_69 ;
}
static int F_25 ( struct V_70 * V_71 ,
enum V_13 V_14 ,
union V_15 * V_16 )
{
int V_6 = 0 ;
struct V_4 * V_5 = F_26 ( V_71 ,
struct V_4 , V_70 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
switch ( V_14 ) {
case V_17 :
case V_29 :
V_6 = F_9 ( V_2 , V_14 , V_16 ) ;
if ( V_14 == V_17 )
return 0 ;
break;
case V_72 :
V_16 -> V_21 = V_73 ;
break;
case V_45 :
case V_46 :
case V_47 :
case V_51 :
case V_52 :
case V_53 :
case V_64 :
V_6 = F_22 ( V_2 , V_14 ) ;
if ( V_6 < 0 )
break;
V_6 = F_18 ( V_2 , V_6 , V_14 , V_16 ) ;
break;
case V_74 :
V_6 = F_21 ( V_2 , V_16 ) ;
break;
case V_36 :
case V_75 :
case V_48 :
case V_50 :
case V_54 :
case V_55 :
case V_56 :
case V_49 :
V_6 = F_22 ( V_2 , V_14 ) ;
if ( V_6 < 0 )
break;
V_6 = F_11 ( V_2 , V_6 , V_14 , V_16 ) ;
break;
default:
F_27 ( & V_2 -> V_10 ,
L_6 , V_11 ) ;
return - V_69 ;
}
if ( ! V_5 -> V_76 )
goto V_77;
if ( ! V_5 -> V_18 &&
V_5 -> V_22 != ( V_6 >= 0 ) ) {
V_5 -> V_22 = ( V_6 >= 0 ) ;
F_28 ( & V_5 -> V_70 ) ;
}
V_77:
if ( ! V_6 ) {
F_12 ( V_2 , V_14 , V_16 ) ;
}
F_5 ( & V_2 -> V_10 ,
L_7 , V_11 , V_14 , V_16 -> V_21 ) ;
if ( V_6 && V_5 -> V_22 )
return V_6 ;
if ( V_6 )
return - V_78 ;
return 0 ;
}
static T_4 F_29 ( int V_79 , void * V_80 )
{
struct V_70 * V_81 = V_80 ;
F_28 ( V_81 ) ;
return V_82 ;
}
static int T_5 F_30 ( struct V_1 * V_2 ,
const struct V_83 * V_84 )
{
struct V_4 * V_5 ;
struct V_85 * V_8 = V_2 -> V_10 . V_86 ;
int V_87 ;
int V_79 ;
V_5 = F_31 ( sizeof( struct V_4 ) , V_88 ) ;
if ( ! V_5 )
return - V_89 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_76 = false ;
V_5 -> V_18 = false ;
V_5 -> V_70 . V_90 = L_8 ;
V_5 -> V_70 . type = V_91 ;
V_5 -> V_70 . V_92 = V_93 ;
V_5 -> V_70 . V_94 =
F_23 ( V_93 ) ;
V_5 -> V_70 . V_95 = F_25 ;
if ( V_8 ) {
V_5 -> V_18 =
F_32 ( V_8 -> V_19 ) ;
V_5 -> V_8 = V_8 ;
}
F_33 ( V_2 , V_5 ) ;
if ( ! V_5 -> V_18 )
goto V_96;
V_87 = F_34 ( V_8 -> V_19 , F_35 ( & V_2 -> V_10 ) ) ;
if ( V_87 ) {
F_24 ( & V_2 -> V_10 , L_9 , V_87 ) ;
V_5 -> V_18 = false ;
goto V_96;
}
V_87 = F_36 ( V_8 -> V_19 ) ;
if ( V_87 ) {
F_24 ( & V_2 -> V_10 , L_10 , V_87 ) ;
F_37 ( V_8 -> V_19 ) ;
V_5 -> V_18 = false ;
goto V_96;
}
V_79 = F_38 ( V_8 -> V_19 ) ;
if ( V_79 <= 0 ) {
F_24 ( & V_2 -> V_10 , L_11 , V_79 ) ;
F_37 ( V_8 -> V_19 ) ;
V_5 -> V_18 = false ;
goto V_96;
}
V_87 = F_39 ( V_79 , F_29 ,
V_97 | V_98 ,
F_35 ( & V_2 -> V_10 ) , & V_5 -> V_70 ) ;
if ( V_87 ) {
F_24 ( & V_2 -> V_10 , L_12 , V_87 ) ;
F_37 ( V_8 -> V_19 ) ;
V_5 -> V_18 = false ;
goto V_96;
}
V_5 -> V_79 = V_79 ;
V_96:
V_87 = F_40 ( & V_2 -> V_10 , & V_5 -> V_70 ) ;
if ( V_87 ) {
F_27 ( & V_2 -> V_10 ,
L_13 , V_11 ) ;
goto V_99;
}
F_41 ( & V_2 -> V_10 ,
L_14 , V_2 -> V_90 ) ;
return 0 ;
V_99:
if ( V_5 -> V_79 )
F_42 ( V_5 -> V_79 , & V_5 -> V_70 ) ;
if ( V_5 -> V_18 )
F_37 ( V_8 -> V_19 ) ;
F_43 ( V_5 ) ;
return V_87 ;
}
static int T_6 F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_79 )
F_42 ( V_5 -> V_79 , & V_5 -> V_70 ) ;
if ( V_5 -> V_18 )
F_37 ( V_5 -> V_8 -> V_19 ) ;
F_45 ( & V_5 -> V_70 ) ;
F_43 ( V_5 ) ;
V_5 = NULL ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
T_7 V_100 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 ;
V_6 = F_7 ( V_2 ,
V_23 [ V_24 ] . V_25 ,
V_101 ) ;
if ( V_5 -> V_22 && V_6 < 0 )
return V_6 ;
return 0 ;
}
static int T_8 F_47 ( void )
{
return F_48 ( & V_102 ) ;
}
static void T_9 F_49 ( void )
{
F_50 ( & V_102 ) ;
}
