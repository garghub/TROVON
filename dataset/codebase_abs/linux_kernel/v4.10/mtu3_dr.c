static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 . V_4 ) {
F_2 ( V_2 -> V_5 , V_6 , V_7 ) ;
F_2 ( V_2 -> V_5 , V_8 , V_9 ) ;
}
}
static int F_3 ( struct V_1 * V_2 ,
int V_10 , bool V_11 )
{
void T_1 * V_12 = V_2 -> V_13 ;
T_2 V_14 ;
F_4 ( V_2 -> V_15 , L_1 , V_16 ,
V_10 , V_11 ? L_2 : L_3 ) ;
if ( V_10 == V_17 ) {
V_14 = F_5 ( V_12 , F_6 ( 0 ) ) ;
V_14 |= V_18 | V_19 ;
F_7 ( V_12 , F_6 ( 0 ) , V_14 ) ;
V_14 = F_5 ( V_12 , F_6 ( 0 ) ) ;
V_14 &= ~ ( V_18 | V_19 ) ;
V_14 = V_11 ? ( V_14 | V_20 ) :
( V_14 & ( ~ V_20 ) ) ;
F_7 ( V_12 , F_6 ( 0 ) , V_14 ) ;
} else {
V_14 = F_5 ( V_12 , F_8 ( 0 ) ) ;
V_14 |= V_21 | V_22 ;
F_7 ( V_12 , F_8 ( 0 ) , V_14 ) ;
V_14 = F_5 ( V_12 , F_8 ( 0 ) ) ;
V_14 &= ~ ( V_21 | V_22 ) ;
V_14 = V_11 ? ( V_14 | V_23 ) :
( V_14 & ( ~ V_23 ) ) ;
F_7 ( V_12 , F_8 ( 0 ) , V_14 ) ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_2 V_24 = 0 ;
F_4 ( V_2 -> V_15 , L_4 , V_16 ) ;
F_3 ( V_2 , V_17 , true ) ;
if ( V_2 -> V_3 . V_4 ) {
F_3 ( V_2 , V_25 , true ) ;
V_24 = V_26 ;
}
F_10 ( V_2 , V_24 ) ;
F_1 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_2 V_24 = 0 ;
F_4 ( V_2 -> V_15 , L_4 , V_16 ) ;
F_3 ( V_2 , V_17 , false ) ;
if ( V_2 -> V_3 . V_4 ) {
F_3 ( V_2 , V_25 , false ) ;
V_24 = V_26 ;
}
F_10 ( V_2 , V_24 ) ;
}
int F_12 ( struct V_27 * V_28 , int V_29 )
{
struct V_1 * V_2 =
F_13 ( V_28 , struct V_1 , V_3 ) ;
struct V_30 * V_31 = V_28 -> V_31 ;
int V_32 ;
if ( ! V_31 )
return 0 ;
F_4 ( V_2 -> V_15 , L_5 , V_16 , V_29 ? L_6 : L_7 ) ;
if ( V_29 ) {
V_32 = F_14 ( V_31 ) ;
if ( V_32 ) {
F_15 ( V_2 -> V_15 , L_8 ) ;
return V_32 ;
}
} else {
F_16 ( V_31 ) ;
}
return 0 ;
}
static void F_17 ( struct V_27 * V_28 ,
enum V_33 V_34 )
{
struct V_1 * V_2 =
F_13 ( V_28 , struct V_1 , V_3 ) ;
struct V_35 * V_36 = V_2 -> V_37 ;
F_4 ( V_2 -> V_15 , L_9 , V_34 ) ;
switch ( V_34 ) {
case V_38 :
F_9 ( V_2 ) ;
F_12 ( V_28 , 1 ) ;
V_2 -> V_39 = true ;
break;
case V_40 :
V_2 -> V_39 = false ;
F_12 ( V_28 , 0 ) ;
F_11 ( V_2 ) ;
break;
case V_41 :
F_18 ( V_36 ) ;
F_19 ( V_2 -> V_15 ) ;
break;
case V_42 :
F_20 ( V_2 -> V_15 ) ;
F_21 ( V_36 ) ;
break;
default:
F_15 ( V_2 -> V_15 , L_10 ) ;
}
}
static int F_22 ( struct V_43 * V_44 ,
unsigned long V_45 , void * V_46 )
{
struct V_27 * V_28 =
F_13 ( V_44 , struct V_27 , V_47 ) ;
if ( V_45 )
F_17 ( V_28 , V_38 ) ;
else
F_17 ( V_28 , V_40 ) ;
return V_48 ;
}
static int F_23 ( struct V_43 * V_44 ,
unsigned long V_45 , void * V_46 )
{
struct V_27 * V_28 =
F_13 ( V_44 , struct V_27 , V_49 ) ;
if ( V_45 )
F_17 ( V_28 , V_42 ) ;
else
F_17 ( V_28 , V_41 ) ;
return V_48 ;
}
static int F_24 ( struct V_27 * V_28 )
{
struct V_1 * V_2 =
F_13 ( V_28 , struct V_1 , V_3 ) ;
struct V_50 * V_51 = V_28 -> V_51 ;
int V_32 ;
if ( ! V_51 )
return 0 ;
V_28 -> V_49 . V_52 = F_23 ;
V_32 = F_25 ( V_51 , V_53 ,
& V_28 -> V_49 ) ;
if ( V_32 < 0 )
F_15 ( V_2 -> V_15 , L_11 ) ;
V_28 -> V_47 . V_52 = F_22 ;
V_32 = F_25 ( V_51 , V_54 ,
& V_28 -> V_47 ) ;
if ( V_32 < 0 )
F_15 ( V_2 -> V_15 , L_12 ) ;
F_4 ( V_2 -> V_15 , L_13 ,
F_26 ( V_51 , V_53 ) ,
F_26 ( V_51 , V_54 ) ) ;
if ( F_26 ( V_51 , V_54 ) == false )
F_17 ( V_28 , V_40 ) ;
if ( F_26 ( V_51 , V_53 ) == true )
F_17 ( V_28 , V_42 ) ;
return 0 ;
}
static void F_27 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_28 ( V_56 ) ;
struct V_27 * V_28 =
F_13 ( V_58 , struct V_27 , V_59 ) ;
F_24 ( V_28 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_60 )
{
struct V_27 * V_28 = & V_2 -> V_3 ;
if ( V_60 )
F_30 ( V_28 -> V_61 , V_28 -> V_62 ) ;
else
F_30 ( V_28 -> V_61 , V_28 -> V_63 ) ;
}
static int F_31 ( struct V_64 * V_65 , void * V_66 )
{
struct V_1 * V_2 = V_65 -> V_67 ;
F_32 ( V_65 , L_14 ,
V_2 -> V_39 ? L_2 : L_3 ,
V_2 -> V_3 . V_68 ? L_15 : L_16 ) ;
return 0 ;
}
static int F_33 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
return F_34 ( V_70 , F_31 , V_69 -> V_71 ) ;
}
static T_3 F_35 ( struct V_70 * V_70 ,
const char T_4 * V_72 , T_5 V_73 , T_6 * V_74 )
{
struct V_64 * V_65 = V_70 -> V_75 ;
struct V_1 * V_2 = V_65 -> V_67 ;
char V_76 [ 16 ] ;
if ( F_36 ( & V_76 , V_72 , F_37 ( T_5 , sizeof( V_76 ) - 1 , V_73 ) ) )
return - V_77 ;
if ( ! strncmp ( V_76 , L_2 , 4 ) && ! V_2 -> V_39 ) {
F_29 ( V_2 , 1 ) ;
} else if ( ! strncmp ( V_76 , L_3 , 6 ) && V_2 -> V_39 ) {
F_29 ( V_2 , 0 ) ;
} else {
F_15 ( V_2 -> V_15 , L_17 ) ;
return - V_78 ;
}
return V_73 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_79 * V_80 ;
struct V_79 * V_70 ;
V_80 = F_39 ( F_40 ( V_2 -> V_15 ) , V_81 ) ;
if ( F_41 ( V_80 ) ) {
if ( ! V_80 )
F_15 ( V_2 -> V_15 , L_18 ) ;
return;
}
V_2 -> V_82 = V_80 ;
V_70 = F_42 ( L_19 , V_83 | V_84 , V_80 ,
V_2 , & V_85 ) ;
if ( ! V_70 )
F_4 ( V_2 -> V_15 , L_20 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_44 ( V_2 -> V_82 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_3 ;
F_46 ( & V_28 -> V_59 , F_27 ) ;
if ( V_28 -> V_68 )
F_38 ( V_2 ) ;
F_47 ( & V_28 -> V_59 , V_86 ) ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_3 ;
F_49 ( & V_28 -> V_59 ) ;
if ( V_28 -> V_51 ) {
F_50 ( V_28 -> V_51 ,
V_53 , & V_28 -> V_49 ) ;
F_50 ( V_28 -> V_51 ,
V_54 , & V_28 -> V_47 ) ;
}
if ( V_28 -> V_68 )
F_43 ( V_2 ) ;
}
