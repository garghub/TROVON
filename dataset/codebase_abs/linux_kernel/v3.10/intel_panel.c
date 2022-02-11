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
V_17 -> V_52 . V_50 = V_50 ;
if ( V_17 -> V_52 . V_53 )
V_17 -> V_52 . V_53 -> V_54 . V_55 = V_50 ;
if ( V_17 -> V_52 . V_56 )
F_18 ( V_13 , V_50 ) ;
}
void F_21 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
V_17 -> V_52 . V_56 = false ;
F_18 ( V_13 , 0 ) ;
if ( F_4 ( V_13 ) -> V_31 >= 4 ) {
T_3 V_57 , V_51 ;
V_57 = F_8 ( V_13 ) ? V_58 : V_32 ;
F_9 ( V_57 , F_5 ( V_57 ) & ~ V_59 ) ;
if ( F_8 ( V_13 ) ) {
V_51 = F_5 ( V_60 ) ;
V_51 &= ~ V_61 ;
F_9 ( V_60 , V_51 ) ;
}
}
}
void F_22 ( struct V_12 * V_13 ,
enum V_62 V_62 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( V_17 -> V_52 . V_50 == 0 ) {
V_17 -> V_52 . V_50 = F_11 ( V_13 ) ;
if ( V_17 -> V_52 . V_53 )
V_17 -> V_52 . V_53 -> V_54 . V_55 =
V_17 -> V_52 . V_50 ;
}
if ( F_4 ( V_13 ) -> V_31 >= 4 ) {
T_3 V_57 , V_51 ;
V_57 = F_8 ( V_13 ) ? V_58 : V_32 ;
V_51 = F_5 ( V_57 ) ;
if ( V_51 & V_59 )
goto V_63;
if ( F_4 ( V_13 ) -> V_64 == 3 )
V_51 &= ~ V_65 ;
else
V_51 &= ~ V_66 ;
V_51 |= F_23 ( V_62 ) ;
V_51 &= ~ V_59 ;
F_9 ( V_57 , V_51 ) ;
F_24 ( V_57 ) ;
F_9 ( V_57 , V_51 | V_59 ) ;
if ( F_8 ( V_13 ) ) {
V_51 = F_5 ( V_60 ) ;
V_51 |= V_61 ;
V_51 &= ~ V_67 ;
F_9 ( V_60 , V_51 ) ;
}
}
V_63:
V_17 -> V_52 . V_56 = true ;
F_18 ( V_13 , V_17 -> V_52 . V_50 ) ;
}
static void F_25 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
V_17 -> V_52 . V_50 = F_15 ( V_13 ) ;
V_17 -> V_52 . V_56 = V_17 -> V_52 . V_50 != 0 ;
}
enum V_68
F_26 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( ! V_69 && V_17 -> V_70 . V_71 ) {
return F_27 ( V_17 -> V_70 . V_71 ) & 0x1 ?
V_72 :
V_73 ;
}
switch ( V_69 ) {
case - 2 :
return V_72 ;
case - 1 :
return V_73 ;
default:
return V_74 ;
}
}
static int F_28 ( struct V_75 * V_76 )
{
struct V_12 * V_13 = F_29 ( V_76 ) ;
F_20 ( V_13 , V_76 -> V_54 . V_55 ) ;
return 0 ;
}
static int F_30 ( struct V_75 * V_76 )
{
struct V_12 * V_13 = F_29 ( V_76 ) ;
return F_15 ( V_13 ) ;
}
int F_31 ( struct V_77 * V_78 )
{
struct V_12 * V_13 = V_78 -> V_13 ;
struct V_16 * V_17 = V_13 -> V_18 ;
struct V_79 V_54 ;
F_25 ( V_13 ) ;
if ( F_32 ( V_17 -> V_52 . V_53 ) )
return - V_80 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . type = V_81 ;
V_54 . V_55 = V_17 -> V_52 . V_50 ;
V_54 . V_82 = F_10 ( V_13 ) ;
if ( V_54 . V_82 == 0 ) {
F_13 ( L_5 ) ;
return - V_80 ;
}
V_17 -> V_52 . V_53 =
F_33 ( L_6 ,
& V_78 -> V_83 , V_13 ,
& V_84 , & V_54 ) ;
if ( F_34 ( V_17 -> V_52 . V_53 ) ) {
F_35 ( L_7 ,
F_36 ( V_17 -> V_52 . V_53 ) ) ;
V_17 -> V_52 . V_53 = NULL ;
return - V_80 ;
}
return 0 ;
}
void F_37 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( V_17 -> V_52 . V_53 ) {
F_38 ( V_17 -> V_52 . V_53 ) ;
V_17 -> V_52 . V_53 = NULL ;
}
}
int F_31 ( struct V_77 * V_78 )
{
F_25 ( V_78 -> V_13 ) ;
return 0 ;
}
void F_37 ( struct V_12 * V_13 )
{
return;
}
int F_39 ( struct V_85 * V_86 ,
struct V_1 * V_2 )
{
V_86 -> V_2 = V_2 ;
return 0 ;
}
void F_40 ( struct V_85 * V_86 )
{
struct V_87 * V_87 =
F_41 ( V_86 , struct V_87 , V_86 ) ;
if ( V_86 -> V_2 )
F_42 ( V_87 -> V_88 . V_13 , V_86 -> V_2 ) ;
}
