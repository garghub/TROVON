static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( F_2 ( V_6 , V_6 -> V_7 . V_8 ) )
V_4 -> V_9 ++ ;
if ( F_3 ( V_10 , V_4 -> V_11 +
F_4 ( V_12 ) ) ) {
V_2 -> V_13 &= ~ ( V_14 | V_15 ) ;
if ( V_4 -> V_9 >= V_16 ) {
F_5 ( F_6 ( V_6 ) , V_17 ,
L_1 ) ;
V_2 -> V_13 |= ( V_15 |
V_14 ) ;
} else if ( V_4 -> V_9 >= V_18 ) {
F_5 ( F_6 ( V_6 ) , V_17 ,
L_2 ) ;
V_2 -> V_13 |= V_14 ;
}
V_4 -> V_9 = 0 ;
V_4 -> V_11 = V_10 ;
}
}
static void F_7 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_8 ( V_20 , struct V_1 ,
V_21 . V_20 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_22 * V_23 = F_6 ( V_2 -> V_6 ) ;
T_1 V_24 ;
bool V_25 ;
int V_26 ;
F_1 ( V_2 ) ;
V_25 = ! ! ( V_2 -> V_13 & V_15 ) ;
V_26 = F_9 ( V_2 ,
! ! ( V_2 -> V_13 & V_14 ) ) ;
if ( V_26 ) {
F_10 ( V_23 , L_3 ) ;
return;
}
F_11 ( V_2 -> V_6 , V_25 ? V_27 :
V_4 -> V_28 ) ;
F_12 ( V_2 -> V_6 ) ;
V_24 = V_25 ? V_4 -> V_29 :
V_4 -> V_30 ;
F_13 ( V_2 -> V_31 , & V_2 -> V_32 ,
F_4 ( V_24 ) ) ;
F_13 ( V_2 -> V_31 , & V_2 -> V_21 ,
F_4 ( V_4 -> V_33 ) ) ;
}
static void F_14 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_8 ( V_20 , struct V_1 ,
V_32 . V_20 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_22 * V_23 = F_6 ( V_6 ) ;
bool V_25 = V_2 -> V_13 & V_15 ;
F_5 ( V_23 , V_17 , L_4 ) ;
if ( V_4 -> V_28 == V_34 || V_25 )
F_11 ( V_6 , V_35 ) ;
else if ( V_4 -> V_28 == V_27 )
F_11 ( V_6 , V_34 ) ;
F_12 ( V_2 -> V_6 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_33 = V_36 ;
V_4 -> V_30 = ( 100 - V_37 ) *
V_4 -> V_33 / 100 ;
V_4 -> V_29 = ( 100 - V_38 ) *
V_4 -> V_33 / 100 ;
F_16 ( & V_2 -> V_21 , F_7 ) ;
F_16 ( & V_2 -> V_32 , F_14 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_5 ( F_6 ( V_6 ) , V_17 , L_5 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_11 = V_10 ;
V_2 -> V_13 &= ~ ( V_14 | V_15 ) ;
F_13 ( V_2 -> V_31 , & V_2 -> V_21 , 0 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_21 ) ;
F_19 ( & V_2 -> V_32 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( F_21 ( V_6 ) == V_39 ) {
F_22 ( V_6 , V_40 ,
V_41 ) ;
F_12 ( V_6 ) ;
F_17 ( V_2 ) ;
}
}
void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 -> V_7 . V_42 &&
F_21 ( V_6 ) != V_43 ) {
F_24 ( V_6 ) ;
if ( V_6 -> V_7 . V_44 == V_39 )
F_18 ( V_2 ) ;
}
}
void F_25 ( struct V_1 * V_2 , char * V_45 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_46 ;
if ( V_45 && strncmp ( V_45 , V_47 , 5 ) == 0 ) {
V_6 -> V_7 . V_44 = V_39 ;
}
switch ( F_21 ( V_2 -> V_6 ) ) {
case V_43 :
break;
case V_39 :
V_2 -> V_6 -> V_7 . V_48 = 7 ;
V_2 -> V_6 -> V_7 . V_8 = 6 ;
V_2 -> V_6 -> V_7 . V_49 = 8 ;
V_2 -> V_4 . V_28 = V_34 ;
F_26 ( V_2 -> V_6 ) ;
F_15 ( V_2 ) ;
V_46 = V_2 -> V_50 [ V_51 ] ;
F_27 ( V_2 -> V_6 , V_46 ) ;
break;
default:
F_28 ( 1 ) ;
break;
}
}
void F_29 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_8 ( V_20 ,
struct V_1 ,
V_52 ) ;
F_30 ( V_2 -> V_6 , V_2 -> V_6 -> V_53 ,
( V_2 -> V_54 == V_55 ) ) ;
}
static void F_31 ( struct V_56 * V_57 ,
enum V_58 V_54 )
{
struct V_1 * V_2 = F_8 ( V_57 ,
struct V_1 ,
V_57 ) ;
V_2 -> V_54 = V_54 ;
F_32 ( V_2 -> V_31 , & V_2 -> V_52 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_59 )
return;
F_31 ( & V_2 -> V_57 , V_55 ) ;
F_34 ( & V_2 -> V_57 ) ;
F_35 ( & V_2 -> V_52 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
int V_26 ;
if ( F_37 ( V_2 -> V_6 ) )
V_2 -> V_6 -> V_53 = V_60 ;
else if ( F_38 ( V_2 -> V_6 ) )
V_2 -> V_6 -> V_53 = V_61 ;
else if ( F_39 ( V_2 -> V_6 ) )
V_2 -> V_6 -> V_53 = V_62 ;
else
V_2 -> V_6 -> V_53 = V_63 ;
F_40 ( V_2 -> V_6 , V_2 -> V_6 -> V_53 ,
V_64 ) ;
F_30 ( V_2 -> V_6 , V_2 -> V_6 -> V_53 , 1 ) ;
snprintf ( V_2 -> V_65 , sizeof( V_2 -> V_65 ) ,
L_6 , F_41 ( V_2 -> V_31 -> V_66 ) ) ;
V_2 -> V_57 . V_67 = V_2 -> V_65 ;
V_2 -> V_57 . V_68 = F_31 ;
V_26 = F_42 ( F_43 ( V_2 -> V_31 -> V_66 ) , & V_2 -> V_57 ) ;
if ( V_26 < 0 )
return;
F_44 ( & V_2 -> V_52 , F_29 ) ;
V_2 -> V_59 = true ;
return;
}
static bool F_45 ( struct V_1 * V_2 )
{
bool V_69 ;
F_46 ( V_2 ) ;
V_69 = F_2 ( V_2 -> V_6 , V_2 -> V_6 -> V_70 ) ==
V_2 -> V_6 -> V_71 ;
F_47 ( V_2 ) ;
return V_69 ;
}
void F_48 ( struct V_72 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
bool V_73 = ! ! F_45 ( V_2 ) ;
F_49 ( V_31 -> V_66 , V_73 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_74 . V_75 & V_76 )
F_51 ( V_2 -> V_31 -> V_66 ) ;
}
void F_52 ( struct V_72 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_22 * V_23 = F_6 ( V_6 ) ;
int V_26 ;
T_2 V_77 ;
if ( ! V_6 -> V_78 )
V_6 -> V_78 = F_53 ( V_31 , V_6 ) ;
V_26 = F_54 ( V_6 , V_6 -> V_78 , V_6 -> V_79 , false ) ;
if ( V_26 ) {
F_10 ( V_23 ,
L_7 ,
V_26 , V_6 -> V_78 -> V_80 ) ;
}
F_55 ( V_6 , V_2 -> V_81 , V_2 -> V_82 ,
& V_2 -> V_81 ) ;
F_56 ( V_83 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 -> V_84 ) ;
F_59 ( & V_2 -> V_85 . V_86 ) ;
V_2 -> V_85 . V_87 &= ~ V_88 ;
F_60 ( & V_2 -> V_85 . V_86 ) ;
F_61 ( V_31 ) ;
F_56 ( V_89 ) ;
F_40 ( V_6 , V_6 -> V_53 ,
V_64 ) ;
F_30 ( V_6 , V_6 -> V_53 , 0 ) ;
}
void F_62 ( struct V_72 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_22 * V_23 = F_6 ( V_6 ) ;
int V_26 ;
T_2 V_77 ;
F_46 ( V_2 ) ;
F_30 ( V_6 , V_6 -> V_53 , 1 ) ;
F_63 ( V_6 , V_6 -> V_53 ) ;
F_56 ( V_90 ) ;
F_64 ( V_31 ) ;
F_65 ( V_2 ) ;
F_56 ( V_91 ) ;
F_56 ( V_92 ) ;
F_66 ( V_2 ) ;
F_67 ( V_6 ) ;
if ( ! V_6 -> V_78 )
V_6 -> V_78 = F_53 ( V_31 , V_6 ) ;
V_26 = F_54 ( V_6 , V_6 -> V_78 , V_6 -> V_79 , false ) ;
if ( V_26 ) {
F_10 ( V_23 ,
L_7 ,
V_26 , V_6 -> V_78 -> V_80 ) ;
}
F_68 ( V_6 ) ;
F_47 ( V_2 ) ;
F_69 ( V_2 , V_93 ) ;
}
