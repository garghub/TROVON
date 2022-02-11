void
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
V_3 -> V_4 = V_2 -> V_4 ;
V_3 -> V_5 = V_2 -> V_5 ;
V_3 -> V_6 = V_2 -> V_6 ;
V_3 -> V_7 = V_2 -> V_7 ;
V_3 -> V_8 = V_2 -> V_8 ;
V_3 -> V_9 = V_2 -> V_9 ;
V_3 -> V_10 = V_2 -> V_10 ;
V_3 -> V_11 = V_2 -> V_11 ;
V_3 -> clock = V_2 -> clock ;
}
void
F_2 ( struct V_12 * V_13 ,
int V_14 ,
const struct V_1 * V_15 ,
struct V_1 * V_3 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
int V_19 , V_20 , V_21 , V_22 ;
V_19 = V_20 = V_21 = V_22 = 0 ;
if ( V_3 -> V_4 == V_15 -> V_4 &&
V_3 -> V_8 == V_15 -> V_8 )
goto V_23;
switch ( V_14 ) {
case V_24 :
V_21 = V_15 -> V_4 ;
V_22 = V_15 -> V_8 ;
V_19 = ( V_3 -> V_4 - V_21 + 1 ) / 2 ;
V_20 = ( V_3 -> V_8 - V_22 + 1 ) / 2 ;
break;
case V_25 :
{
T_1 V_26 = V_3 -> V_4 * V_15 -> V_8 ;
T_1 V_27 = V_15 -> V_4 * V_3 -> V_8 ;
if ( V_26 > V_27 ) {
V_21 = V_27 / V_15 -> V_8 ;
if ( V_21 & 1 )
V_21 ++ ;
V_19 = ( V_3 -> V_4 - V_21 + 1 ) / 2 ;
V_20 = 0 ;
V_22 = V_3 -> V_8 ;
} else if ( V_26 < V_27 ) {
V_22 = V_26 / V_15 -> V_4 ;
if ( V_22 & 1 )
V_22 ++ ;
V_20 = ( V_3 -> V_8 - V_22 + 1 ) / 2 ;
V_19 = 0 ;
V_21 = V_3 -> V_4 ;
} else {
V_19 = V_20 = 0 ;
V_21 = V_3 -> V_4 ;
V_22 = V_3 -> V_8 ;
}
}
break;
default:
case V_28 :
V_19 = V_20 = 0 ;
V_21 = V_3 -> V_4 ;
V_22 = V_3 -> V_8 ;
break;
}
V_23:
V_17 -> V_29 = ( V_19 << 16 ) | V_20 ;
V_17 -> V_30 = ( V_21 << 16 ) | V_22 ;
}
static int F_3 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( F_4 ( V_13 ) -> V_31 >= 4 )
return F_5 ( V_32 ) & V_33 ;
if ( F_6 ( V_13 ) )
return F_5 ( V_34 ) & V_35 ;
return 0 ;
}
static T_1 F_7 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
T_1 V_36 ;
if ( F_8 ( V_17 -> V_13 ) ) {
V_36 = F_5 ( V_37 ) ;
if ( V_17 -> V_38 . V_39 == 0 ) {
V_17 -> V_38 . V_39 = V_36 ;
} else if ( V_36 == 0 ) {
V_36 = V_17 -> V_38 . V_39 ;
F_9 ( V_37 , V_36 ) ;
}
} else {
V_36 = F_5 ( V_34 ) ;
if ( V_17 -> V_38 . V_40 == 0 ) {
V_17 -> V_38 . V_40 = V_36 ;
if ( F_4 ( V_13 ) -> V_31 >= 4 )
V_17 -> V_38 . V_39 =
F_5 ( V_32 ) ;
} else if ( V_36 == 0 ) {
V_36 = V_17 -> V_38 . V_40 ;
F_9 ( V_34 , V_36 ) ;
if ( F_4 ( V_13 ) -> V_31 >= 4 )
F_9 ( V_32 ,
V_17 -> V_38 . V_39 ) ;
}
}
return V_36 ;
}
static T_1 F_10 ( struct V_12 * V_13 )
{
T_1 V_41 ;
V_41 = F_7 ( V_13 ) ;
if ( F_8 ( V_13 ) ) {
V_41 >>= 16 ;
} else {
if ( F_4 ( V_13 ) -> V_31 < 4 )
V_41 >>= 17 ;
else
V_41 >>= 16 ;
if ( F_3 ( V_13 ) )
V_41 *= 0xff ;
}
return V_41 ;
}
T_1 F_11 ( struct V_12 * V_13 )
{
T_1 V_41 ;
V_41 = F_10 ( V_13 ) ;
if ( V_41 == 0 ) {
F_12 ( L_1 ) ;
return 1 ;
}
F_13 ( L_2 , V_41 ) ;
return V_41 ;
}
static T_1 F_14 ( struct V_12 * V_13 , T_1 V_36 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( V_42 < 0 )
return V_36 ;
if ( V_42 > 0 ||
V_17 -> V_43 & V_44 )
return F_11 ( V_13 ) - V_36 ;
return V_36 ;
}
static T_1 F_15 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
T_1 V_36 ;
if ( F_8 ( V_13 ) ) {
V_36 = F_5 ( V_45 ) & V_46 ;
} else {
V_36 = F_5 ( V_34 ) & V_46 ;
if ( F_4 ( V_13 ) -> V_31 < 4 )
V_36 >>= 1 ;
if ( F_3 ( V_13 ) ) {
T_2 V_47 ;
F_16 ( V_13 -> V_48 , V_49 , & V_47 ) ;
V_36 *= V_47 ;
}
}
V_36 = F_14 ( V_13 , V_36 ) ;
F_13 ( L_3 , V_36 ) ;
return V_36 ;
}
static void F_17 ( struct V_12 * V_13 , T_1 V_50 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
T_1 V_36 = F_5 ( V_45 ) & ~ V_46 ;
F_9 ( V_45 , V_36 | V_50 ) ;
}
static void F_18 ( struct V_12 * V_13 , T_1 V_50 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
T_1 V_51 ;
F_13 ( L_4 , V_50 ) ;
V_50 = F_14 ( V_13 , V_50 ) ;
if ( F_8 ( V_13 ) )
return F_17 ( V_13 , V_50 ) ;
if ( F_3 ( V_13 ) ) {
T_1 V_41 = F_11 ( V_13 ) ;
T_2 V_47 ;
V_47 = V_50 * 0xfe / V_41 + 1 ;
V_50 /= V_47 ;
F_19 ( V_13 -> V_48 , V_49 , V_47 ) ;
}
V_51 = F_5 ( V_34 ) ;
if ( F_4 ( V_13 ) -> V_31 < 4 )
V_50 <<= 1 ;
V_51 &= ~ V_46 ;
F_9 ( V_34 , V_51 | V_50 ) ;
}
void F_20 ( struct V_12 * V_13 , T_1 V_50 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
V_17 -> V_52 = V_50 ;
if ( V_17 -> V_53 )
F_18 ( V_13 , V_50 ) ;
}
void F_21 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
V_17 -> V_53 = false ;
F_18 ( V_13 , 0 ) ;
if ( F_4 ( V_13 ) -> V_31 >= 4 ) {
T_3 V_54 , V_51 ;
V_54 = F_8 ( V_13 ) ? V_55 : V_32 ;
F_9 ( V_54 , F_5 ( V_54 ) & ~ V_56 ) ;
if ( F_8 ( V_13 ) ) {
V_51 = F_5 ( V_57 ) ;
V_51 &= ~ V_58 ;
F_9 ( V_57 , V_51 ) ;
}
}
}
void F_22 ( struct V_12 * V_13 ,
enum V_59 V_59 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( V_17 -> V_52 == 0 )
V_17 -> V_52 = F_11 ( V_13 ) ;
if ( F_4 ( V_13 ) -> V_31 >= 4 ) {
T_3 V_54 , V_51 ;
V_54 = F_8 ( V_13 ) ? V_55 : V_32 ;
V_51 = F_5 ( V_54 ) ;
if ( V_51 & V_56 )
goto V_60;
if ( V_17 -> V_61 == 3 )
V_51 &= ~ V_62 ;
else
V_51 &= ~ V_63 ;
V_51 |= F_23 ( V_59 ) ;
V_51 &= ~ V_56 ;
F_9 ( V_54 , V_51 ) ;
F_24 ( V_54 ) ;
F_9 ( V_54 , V_51 | V_56 ) ;
if ( F_8 ( V_13 ) ) {
V_51 = F_5 ( V_57 ) ;
V_51 |= V_58 ;
V_51 &= ~ V_64 ;
F_9 ( V_57 , V_51 ) ;
}
}
V_60:
V_17 -> V_53 = true ;
F_18 ( V_13 , V_17 -> V_52 ) ;
}
static void F_25 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
V_17 -> V_52 = F_15 ( V_13 ) ;
V_17 -> V_53 = V_17 -> V_52 != 0 ;
}
enum V_65
F_26 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( ! V_66 && V_17 -> V_67 . V_68 ) {
return F_27 ( V_17 -> V_67 . V_68 ) & 0x1 ?
V_69 :
V_70 ;
}
switch ( V_66 ) {
case - 2 :
return V_69 ;
case - 1 :
return V_70 ;
default:
return V_71 ;
}
}
static int F_28 ( struct V_72 * V_73 )
{
struct V_12 * V_13 = F_29 ( V_73 ) ;
F_20 ( V_13 , V_73 -> V_74 . V_75 ) ;
return 0 ;
}
static int F_30 ( struct V_72 * V_73 )
{
struct V_12 * V_13 = F_29 ( V_73 ) ;
struct V_16 * V_17 = V_13 -> V_18 ;
return V_17 -> V_52 ;
}
int F_31 ( struct V_76 * V_77 )
{
struct V_12 * V_13 = V_77 -> V_13 ;
struct V_16 * V_17 = V_13 -> V_18 ;
struct V_78 V_74 ;
F_25 ( V_13 ) ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . type = V_79 ;
V_74 . V_80 = F_10 ( V_13 ) ;
if ( V_74 . V_80 == 0 ) {
F_13 ( L_5 ) ;
return - V_81 ;
}
V_17 -> V_82 =
F_32 ( L_6 ,
& V_77 -> V_83 , V_13 ,
& V_84 , & V_74 ) ;
if ( F_33 ( V_17 -> V_82 ) ) {
F_34 ( L_7 ,
F_35 ( V_17 -> V_82 ) ) ;
V_17 -> V_82 = NULL ;
return - V_81 ;
}
V_17 -> V_82 -> V_74 . V_75 = F_15 ( V_13 ) ;
return 0 ;
}
void F_36 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( V_17 -> V_82 )
F_37 ( V_17 -> V_82 ) ;
}
int F_31 ( struct V_76 * V_77 )
{
F_25 ( V_77 -> V_13 ) ;
return 0 ;
}
void F_36 ( struct V_12 * V_13 )
{
return;
}
int F_38 ( struct V_85 * V_86 ,
struct V_1 * V_2 )
{
V_86 -> V_2 = V_2 ;
return 0 ;
}
void F_39 ( struct V_85 * V_86 )
{
struct V_87 * V_87 =
F_40 ( V_86 , struct V_87 , V_86 ) ;
if ( V_86 -> V_2 )
F_41 ( V_87 -> V_88 . V_13 , V_86 -> V_2 ) ;
}
