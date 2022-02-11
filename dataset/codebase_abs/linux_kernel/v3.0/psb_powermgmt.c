void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = V_4 -> V_7 & 0xffff ;
V_4 -> V_8 &= 0xffff ;
V_4 -> V_9 = true ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = false ;
F_2 ( & V_12 ) ;
if ( ! F_3 ( V_2 ) ) {
T_1 V_13 = F_4 ( V_14 ) ;
V_13 &= ~ 3 ;
V_13 |= 1 ;
F_5 ( V_13 , V_14 ) ;
F_4 ( V_14 ) ;
}
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_12 ) ;
F_8 ( & V_2 -> V_15 -> V_2 ) ;
F_9 ( & V_2 -> V_15 -> V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
V_4 -> V_20 = F_11 ( V_21 ) ;
V_4 -> V_22 = F_11 ( V_23 ) ;
V_4 -> V_24 = F_11 ( V_25 ) ;
V_4 -> V_26 = F_11 ( V_27 ) ;
V_4 -> V_28 = F_11 ( V_29 ) ;
V_4 -> V_30 = F_11 ( V_31 ) ;
V_4 -> V_32 = F_11 ( V_33 ) ;
V_4 -> V_34 = F_11 ( V_35 ) ;
F_12 ( & V_2 -> V_36 . V_37 ) ;
F_13 (crtc, &dev->mode_config.crtc_list, head) {
if ( F_14 ( V_17 ) )
V_17 -> V_38 -> V_39 ( V_17 ) ;
}
F_13 (connector, &dev->mode_config.connector_list, head)
V_19 -> V_38 -> V_39 ( V_19 ) ;
F_15 ( & V_2 -> V_36 . V_37 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
F_17 ( V_4 -> V_20 , V_21 ) ;
F_17 ( V_4 -> V_22 , V_23 ) ;
F_17 ( V_4 -> V_24 , V_25 ) ;
F_17 ( V_4 -> V_26 , V_27 ) ;
F_17 ( V_4 -> V_28 , V_29 ) ;
F_17 ( V_4 -> V_30 , V_31 ) ;
F_17 ( V_4 -> V_32 , V_33 ) ;
F_17 ( V_4 -> V_34 , V_35 ) ;
F_17 ( 0x80000000 , V_40 ) ;
F_12 ( & V_2 -> V_36 . V_37 ) ;
F_13 (crtc, &dev->mode_config.crtc_list, head)
if ( F_14 ( V_17 ) )
V_17 -> V_38 -> V_41 ( V_17 ) ;
F_13 (connector, &dev->mode_config.connector_list, head)
V_19 -> V_38 -> V_41 ( V_19 ) ;
F_15 ( & V_2 -> V_36 . V_37 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_42 ;
T_1 V_43 ;
if ( F_3 ( V_2 ) ) {
V_42 = V_44 ;
F_19 ( V_42 , V_4 -> V_8 + V_45 ) ;
while ( true ) {
V_43 = F_20 ( V_4 -> V_8 + V_46 ) ;
if ( ( V_43 & V_42 ) == V_42 )
break;
else
F_21 ( 10 ) ;
}
V_4 -> V_9 = false ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_47 ;
if ( V_4 -> V_11 )
return;
F_10 ( V_2 ) ;
if ( V_4 -> V_48 ) {
F_17 ( 0 , V_49 ) ;
do {
V_47 = F_11 ( V_50 ) ;
} while ( V_47 & 0x80000000 );
F_17 ( 0x58000000 , V_51 ) ;
F_17 ( 0 , V_52 ) ;
F_23 ( 4 ) ;
F_17 ( 0x0 , V_53 ) ;
F_23 ( 8 ) ;
F_17 ( 0 , V_54 ) ;
} else {
F_17 ( V_55 , V_56 ) ;
F_17 ( 0x0 , V_53 ) ;
F_17 ( 0x2faf0000 , V_57 ) ;
while ( F_24 ( 0x70008 ) & 0x40000000 ) ;
while ( ( F_11 ( V_58 ) & V_59 )
!= V_59 ) ;
F_17 ( 0 , V_60 ) ;
}
F_18 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_42 = V_44 ;
T_1 V_43 , V_61 ;
if ( F_3 ( V_2 ) ) {
V_61 = F_20 ( V_4 -> V_8 + V_45 ) ;
V_61 &= ~ V_42 ;
F_19 ( V_61 , ( V_4 -> V_8 + V_45 ) ) ;
while ( true ) {
V_43 = F_20 ( V_4 -> V_8 + V_46 ) ;
if ( ( V_43 & V_42 ) == 0 )
break;
else
F_21 ( 10 ) ;
}
}
V_4 -> V_11 = false ;
V_4 -> V_9 = true ;
}
static void F_26 ( struct V_62 * V_15 )
{
struct V_1 * V_2 = F_27 ( V_15 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_11 == false )
return;
F_25 ( V_2 ) ;
F_17 ( V_4 -> V_63 | V_64 , V_65 ) ;
F_28 ( V_15 , V_66 ,
V_4 -> V_67 | V_68 ) ;
F_16 ( V_2 ) ;
}
static void F_29 ( struct V_62 * V_15 )
{
struct V_1 * V_2 = F_27 ( V_15 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_69 , V_70 ;
if ( V_4 -> V_11 )
return;
F_30 ( V_15 ) ;
F_31 ( V_15 , 0x5C , & V_69 ) ;
V_4 -> V_71 = V_69 ;
F_31 ( V_15 , 0xFC , & V_70 ) ;
V_4 -> V_72 = V_70 ;
F_31 ( V_15 , V_73 , & V_4 -> V_74 ) ;
F_31 ( V_15 , V_75 , & V_4 -> V_76 ) ;
F_32 ( V_15 ) ;
F_33 ( V_15 , V_77 ) ;
V_4 -> V_11 = true ;
}
static bool F_34 ( struct V_62 * V_15 )
{
struct V_1 * V_2 = F_27 ( V_15 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_78 ;
if ( ! V_4 -> V_11 )
return true ;
F_33 ( V_15 , V_79 ) ;
F_35 ( V_15 ) ;
F_36 ( V_15 , 0x5c , V_4 -> V_71 ) ;
F_36 ( V_15 , 0xFC , V_4 -> V_72 ) ;
F_36 ( V_15 , V_73 , V_4 -> V_74 ) ;
F_36 ( V_15 , V_75 , V_4 -> V_76 ) ;
V_78 = F_37 ( V_15 ) ;
if ( V_78 != 0 )
F_38 ( & V_15 -> V_2 , L_1 , V_78 ) ;
else
V_4 -> V_11 = false ;
return ! V_4 -> V_11 ;
}
int F_39 ( struct V_62 * V_15 , T_2 V_80 )
{
struct V_1 * V_2 = F_27 ( V_15 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_12 ( & V_12 ) ;
if ( ! V_4 -> V_11 ) {
if ( V_4 -> V_10 ) {
F_15 ( & V_12 ) ;
return - V_81 ;
}
F_40 ( V_2 ) ;
F_22 ( V_2 ) ;
F_29 ( V_15 ) ;
}
F_15 ( & V_12 ) ;
return 0 ;
}
int F_41 ( struct V_62 * V_15 )
{
struct V_1 * V_2 = F_27 ( V_15 ) ;
F_12 ( & V_12 ) ;
F_34 ( V_15 ) ;
F_26 ( V_15 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_15 ( & V_12 ) ;
return 0 ;
}
bool F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_9 ;
}
bool F_45 ( struct V_1 * V_2 , bool V_82 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_78 ;
if ( V_4 -> V_9 ) {
V_4 -> V_10 ++ ;
F_46 ( & V_2 -> V_15 -> V_2 ) ;
return true ;
}
if ( V_82 == false )
return false ;
V_78 = F_34 ( V_2 -> V_15 ) ;
if ( V_78 == 0 ) {
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_46 ( & V_2 -> V_15 -> V_2 ) ;
V_4 -> V_10 ++ ;
return true ;
}
return false ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_10 -- ;
F_48 ( V_4 -> V_10 < 0 ) ;
F_49 ( & V_2 -> V_15 -> V_2 ) ;
}
int F_50 ( struct V_83 * V_2 )
{
static T_2 V_84 ;
return F_39 ( F_51 ( V_2 ) , V_84 ) ;
}
int F_52 ( struct V_83 * V_2 )
{
return 0 ;
}
int F_53 ( struct V_83 * V_2 )
{
struct V_1 * V_85 = F_27 ( F_51 ( V_2 ) ) ;
struct V_3 * V_4 = V_85 -> V_5 ;
if ( V_4 -> V_10 )
return 0 ;
else
return 1 ;
}
