static void
F_1 ( struct V_1 * V_2 )
{
}
static void
F_2 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_5 :
F_4 ( V_2 , V_6 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_6 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_7 , V_8 ) ;
}
static void
V_6 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_9 :
F_4 ( V_2 , V_10 ) ;
break;
case V_11 :
F_7 ( V_2 ) ;
break;
case V_12 :
F_4 ( V_2 , F_2 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_7 , V_13 ) ;
}
static void
V_10 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_14 :
F_4 ( V_2 , V_15 ) ;
break;
case V_16 :
case V_17 :
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
F_4 ( V_2 , V_22 ) ;
if ( V_4 != V_16 )
F_9 ( & V_2 -> V_7 , V_23 ) ;
break;
case V_24 :
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
F_4 ( V_2 , V_25 ) ;
break;
case V_11 :
F_4 ( V_2 , V_26 ) ;
break;
case V_12 :
F_4 ( V_2 , F_2 ) ;
F_9 ( & V_2 -> V_7 , V_27 ) ;
break;
case V_9 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static void
V_15 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_28 :
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
F_4 ( V_2 , V_29 ) ;
break;
case V_30 :
F_13 ( V_2 ) ;
F_15 ( V_2 ) ;
F_4 ( V_2 , V_31 ) ;
break;
case V_16 :
case V_17 :
F_13 ( V_2 ) ;
case V_32 :
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
F_4 ( V_2 , V_22 ) ;
if ( V_4 != V_16 )
F_9 ( & V_2 -> V_7 , V_33 ) ;
break;
case V_11 :
F_13 ( V_2 ) ;
F_4 ( V_2 , V_26 ) ;
break;
case V_9 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_16 ( struct V_1 * V_2 )
{
}
static void
V_31 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_28 :
F_14 ( V_2 ) ;
F_4 ( V_2 , V_29 ) ;
break;
case V_16 :
case V_17 :
F_17 ( V_2 ) ;
case V_34 :
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
F_4 ( V_2 , V_22 ) ;
if ( V_4 != V_16 )
F_9 ( & V_2 -> V_7 , V_33 ) ;
break;
case V_11 :
F_17 ( V_2 ) ;
F_4 ( V_2 , V_26 ) ;
break;
case V_9 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_18 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = (struct V_35 * ) V_2 -> V_20 -> V_36 ;
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_37 ) ;
F_19 ( V_2 , V_38 ) ;
F_20 ( V_39 , V_36 , V_40 , L_1 ) ;
F_21 ( V_2 , V_41 ) ;
}
static void
V_29 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_9 :
break;
case V_11 :
F_17 ( V_2 ) ;
F_4 ( V_2 , V_26 ) ;
break;
case V_16 :
case V_17 :
F_17 ( V_2 ) ;
case V_34 :
if ( V_2 -> V_7 . V_42 )
F_4 ( V_2 , V_43 ) ;
else
F_4 ( V_2 , V_22 ) ;
F_22 ( V_2 ) ;
if ( V_4 != V_16 )
F_9 ( & V_2 -> V_7 , V_44 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_23 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = (struct V_35 * ) V_2 -> V_20 -> V_36 ;
F_9 ( & V_2 -> V_7 , V_45 ) ;
F_20 ( V_39 , V_36 , V_40 , L_2 ) ;
F_21 ( V_2 , V_46 ) ;
}
static void
V_26 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_47 :
F_4 ( V_2 , V_48 ) ;
break;
case V_17 :
F_9 ( & V_2 -> V_7 , V_44 ) ;
break;
case V_24 :
F_4 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_24 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
static void
V_48 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_9 :
F_4 ( V_2 , V_10 ) ;
break;
case V_11 :
V_2 -> V_18 -> V_49 ( V_2 -> V_20 ) ;
break;
case V_12 :
F_4 ( V_2 , F_2 ) ;
F_9 ( & V_2 -> V_7 , V_27 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_25 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0 ) ;
}
static void
V_43 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_14 :
F_4 ( V_2 , V_15 ) ;
break;
case V_16 :
case V_17 :
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
F_4 ( V_2 , V_22 ) ;
if ( V_4 != V_16 )
F_9 ( & V_2 -> V_7 , V_23 ) ;
break;
case V_24 :
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
F_4 ( V_2 , V_25 ) ;
break;
case V_9 :
break;
case V_11 :
F_4 ( V_2 , V_26 ) ;
break;
case V_12 :
F_4 ( V_2 , F_2 ) ;
F_9 ( & V_2 -> V_7 , V_27 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_26 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0 ) ;
}
static void
V_22 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_9 :
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
break;
case V_11 :
F_4 ( V_2 , V_26 ) ;
break;
case V_12 :
F_4 ( V_2 , F_2 ) ;
F_9 ( & V_2 -> V_7 , V_27 ) ;
break;
case V_17 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_27 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0 ) ;
}
static void
V_25 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_9 :
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
break;
case V_11 :
V_2 -> V_18 -> V_49 ( V_2 -> V_20 ) ;
break;
case V_12 :
F_4 ( V_2 , F_2 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_28 ( struct V_50 * V_7 )
{
V_7 -> V_51 = V_52 ;
V_7 -> V_42 = V_53 ;
}
static void
V_8 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_13 :
F_4 ( V_7 , V_55 ) ;
break;
case V_27 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_29 ( struct V_50 * V_7 )
{
struct V_56 V_57 ;
T_1 V_58 = F_30 ( V_7 -> V_2 -> V_59 . V_60 ) ;
if ( V_58 == V_61 )
goto V_62;
F_31 ( V_7 -> V_2 , & V_57 ) ;
if ( F_32 ( V_57 . V_63 ) == V_64 )
goto V_62;
F_3 ( V_7 -> V_2 , V_58 ) ;
F_3 ( V_7 -> V_2 , V_57 . V_63 ) ;
F_33 ( V_61 , V_7 -> V_2 -> V_59 . V_60 ) ;
F_30 ( V_7 -> V_2 -> V_59 . V_65 ) ;
F_33 ( 1 , V_7 -> V_2 -> V_59 . V_65 ) ;
V_62:
F_34 ( V_7 -> V_2 ) ;
}
static void
V_55 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_66 :
if ( F_35 ( V_2 ) ) {
if ( F_36 ( V_2 ) ) {
F_37 ( V_2 ) ;
F_4 ( V_7 , V_67 ) ;
} else {
F_38 ( V_2 ) ;
F_33 ( 1 , V_2 -> V_59 . V_65 ) ;
F_39 ( V_2 ) ;
}
} else {
F_33 ( 1 , V_2 -> V_59 . V_65 ) ;
F_4 ( V_7 , V_68 ) ;
}
break;
case V_69 :
F_4 ( V_7 , V_70 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_45 :
F_40 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
F_9 ( V_2 , V_47 ) ;
break;
case V_27 :
F_40 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_41 ( struct V_50 * V_7 )
{
if ( V_7 -> V_51 == V_52 )
F_42 ( V_7 -> V_2 ) ;
V_7 -> V_51 = V_71 ;
F_43 ( V_7 -> V_2 ) ;
}
static void
V_68 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_72 :
F_4 ( V_7 , V_55 ) ;
break;
case V_45 :
F_44 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
F_9 ( V_2 , V_47 ) ;
break;
case V_27 :
F_44 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_45 ( struct V_50 * V_7 )
{
F_34 ( V_7 -> V_2 ) ;
}
static void
F_46 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_66 :
if ( F_47 ( V_2 ) ) {
F_37 ( V_2 ) ;
F_4 ( V_7 , V_67 ) ;
} else {
F_33 ( 1 , V_2 -> V_59 . V_65 ) ;
F_39 ( V_2 ) ;
}
break;
case V_69 :
F_4 ( V_7 , V_70 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_45 :
F_40 ( V_2 ) ;
F_4 ( V_7 , V_73 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_48 ( struct V_50 * V_7 )
{
V_7 -> V_74 = 0 ;
F_49 ( V_7 -> V_2 , V_52 ) ;
}
static void
V_67 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_75 :
F_4 ( V_7 , V_76 ) ;
break;
case V_72 :
F_33 ( 1 , V_2 -> V_59 . V_65 ) ;
F_9 ( V_2 , V_16 ) ;
F_4 ( V_7 , V_77 ) ;
break;
case V_45 :
F_44 ( V_2 ) ;
F_50 ( V_2 ) ;
F_33 ( 1 , V_2 -> V_59 . V_65 ) ;
F_4 ( V_7 , V_78 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_51 ( struct V_50 * V_7 )
{
F_43 ( V_7 -> V_2 ) ;
V_7 -> V_2 -> V_18 -> V_79 ( V_7 -> V_2 -> V_20 ) ;
F_52 ( V_7 -> V_2 ) ;
}
static void
V_76 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_80 :
F_44 ( V_2 ) ;
F_33 ( 1 , V_2 -> V_59 . V_65 ) ;
F_4 ( V_7 , V_81 ) ;
break;
case V_23 :
F_44 ( V_2 ) ;
case V_72 :
F_33 ( 1 , V_2 -> V_59 . V_65 ) ;
if ( V_4 == V_72 )
F_9 ( V_2 , V_16 ) ;
F_4 ( V_7 , V_77 ) ;
break;
case V_45 :
F_44 ( V_2 ) ;
F_33 ( 1 , V_2 -> V_59 . V_65 ) ;
F_4 ( V_7 , V_82 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_53 ( struct V_50 * V_7 )
{
F_9 ( V_7 -> V_2 , V_14 ) ;
}
static void
V_81 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_45 :
F_4 ( V_7 , V_82 ) ;
break;
case V_33 :
F_4 ( V_7 , V_77 ) ;
break;
case V_44 :
F_4 ( V_7 , V_83 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_54 ( struct V_50 * V_7 )
{
F_43 ( V_7 -> V_2 ) ;
F_55 ( V_7 -> V_2 ) ;
}
static void
V_82 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_84 :
F_44 ( V_2 ) ;
F_4 ( V_7 , V_73 ) ;
break;
case V_44 :
F_44 ( V_2 ) ;
case V_72 :
F_33 ( V_85 , V_2 -> V_59 . V_60 ) ;
F_4 ( V_7 , V_73 ) ;
break;
case V_80 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_56 ( struct V_50 * V_7 )
{
F_34 ( V_7 -> V_2 ) ;
}
static void
V_73 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_66 :
F_50 ( V_2 ) ;
F_33 ( 1 , V_2 -> V_59 . V_65 ) ;
F_4 ( V_7 , V_78 ) ;
break;
case V_69 :
F_4 ( V_7 , V_70 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_44 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_57 ( struct V_50 * V_7 )
{
F_58 ( V_7 -> V_2 ) ;
F_9 ( V_7 -> V_2 , V_47 ) ;
}
static void
V_78 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_13 :
F_4 ( V_7 , F_46 ) ;
break;
case V_27 :
F_38 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_59 ( struct V_50 * V_7 )
{
F_60 ( V_7 -> V_2 ) ;
F_34 ( V_7 -> V_2 ) ;
}
static void
V_77 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_66 :
F_61 ( V_2 ) ;
F_50 ( V_2 ) ;
F_33 ( V_85 , V_2 -> V_59 . V_60 ) ;
F_33 ( 1 , V_2 -> V_59 . V_65 ) ;
F_4 ( V_7 , V_86 ) ;
break;
case V_69 :
F_4 ( V_7 , V_70 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_45 :
F_40 ( V_2 ) ;
F_4 ( V_7 , V_73 ) ;
break;
case V_27 :
F_40 ( V_2 ) ;
F_38 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
case V_44 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_62 ( struct V_50 * V_7 )
{
F_3 ( V_7 -> V_2 , 0 ) ;
}
static void
V_86 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_45 :
F_4 ( V_7 , V_78 ) ;
break;
case V_27 :
F_38 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_63 ( struct V_50 * V_7 )
{
F_64 ( V_7 -> V_2 ) ;
F_58 ( V_7 -> V_2 ) ;
F_34 ( V_7 -> V_2 ) ;
}
static void
V_83 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_66 :
F_65 ( V_2 ) ;
F_61 ( V_2 ) ;
if ( ! V_7 -> V_42 ) {
F_50 ( V_2 ) ;
F_33 ( V_85 , V_2 -> V_59 . V_60 ) ;
F_33 ( 1 , V_2 -> V_59 . V_65 ) ;
F_4 ( V_7 , V_70 ) ;
} else {
if ( F_47 ( V_2 ) )
F_4 ( V_7 , V_67 ) ;
else {
F_33 ( 1 , V_2 -> V_59 . V_65 ) ;
F_4 ( V_7 , F_46 ) ;
}
}
break;
case V_69 :
F_4 ( V_7 , V_70 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_45 :
F_40 ( V_2 ) ;
F_4 ( V_7 , V_73 ) ;
break;
case V_44 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_66 ( struct V_50 * V_7 )
{
F_3 ( V_7 -> V_2 , 0 ) ;
}
static void
V_70 ( struct V_50 * V_7 , enum V_54 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_45 :
F_4 ( V_7 , V_78 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_19 ( struct V_1 * V_2 , enum V_87 V_4 )
{
struct V_88 * V_89 ;
struct V_90 * V_91 ;
F_67 (qe, &ioc->notify_q) {
V_89 = (struct V_88 * ) V_91 ;
V_89 -> V_18 ( V_89 -> V_92 , V_4 ) ;
}
}
static void
F_7 ( struct V_1 * V_2 )
{
V_2 -> V_18 -> V_49 ( V_2 -> V_20 ) ;
F_19 ( V_2 , V_93 ) ;
}
T_2
F_68 ( void T_3 * V_94 )
{
T_1 V_95 ;
int V_96 = 0 ;
#define F_69 3000
V_95 = F_30 ( V_94 ) ;
while ( ( V_95 & 1 ) && ( V_96 < F_69 ) ) {
V_96 ++ ;
F_70 ( 2 ) ;
V_95 = F_30 ( V_94 ) ;
}
if ( ! ( V_95 & 1 ) )
return V_71 ;
return V_52 ;
}
static void
F_34 ( struct V_1 * V_2 )
{
T_1 V_95 ;
V_95 = F_30 ( V_2 -> V_59 . V_65 ) ;
if ( V_95 == ~ 0 ) {
F_71 ( V_95 == ~ 0 ) ;
F_9 ( & V_2 -> V_7 , V_69 ) ;
return;
}
if ( ! ( V_95 & 1 ) ) {
F_9 ( & V_2 -> V_7 , V_66 ) ;
return;
}
F_39 ( V_2 ) ;
}
static void
F_72 ( struct V_1 * V_2 )
{
T_1 V_97 ;
int V_98 ;
#define F_73 10000
V_97 = F_30 ( V_2 -> V_59 . V_99 ) ;
V_97 &= ~ V_100 ;
V_97 |= V_101 ;
V_97 |= F_74 ( 3UL ) ;
F_33 ( V_97 , V_2 -> V_59 . V_99 ) ;
V_98 = 0 ;
do {
V_97 = F_30 ( V_2 -> V_59 . V_99 ) ;
V_98 ++ ;
} while ( ! ( V_97 & V_102 ) && ( V_98 < F_73 ) );
F_71 ( ! ( V_97 & V_102 ) ) ;
F_3 ( V_2 , V_97 ) ;
V_97 &= ~ ( V_102 | V_101 ) ;
F_33 ( V_97 , V_2 -> V_59 . V_99 ) ;
}
static void
F_75 ( struct V_1 * V_2 )
{
T_1 V_97 ;
V_97 = F_30 ( V_2 -> V_59 . V_99 ) ;
V_97 &= ~ V_103 ;
F_33 ( V_97 , V_2 -> V_59 . V_99 ) ;
}
static void
F_64 ( struct V_1 * V_2 )
{
T_1 V_97 ;
V_97 = F_30 ( V_2 -> V_59 . V_99 ) ;
V_97 |= ( V_103 | V_104 ) ;
F_33 ( V_97 , V_2 -> V_59 . V_99 ) ;
}
void
F_31 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
T_1 V_105 , V_106 ;
T_1 V_107 = 0 ;
int V_98 ;
T_1 * V_108 = ( T_1 * ) V_57 ;
V_105 = F_76 ( V_2 -> V_59 . V_109 , V_107 ) ;
V_106 = F_77 ( V_107 ) ;
F_33 ( V_105 , V_2 -> V_59 . V_110 ) ;
for ( V_98 = 0 ; V_98 < ( sizeof( struct V_56 ) / sizeof( T_1 ) ) ;
V_98 ++ ) {
V_108 [ V_98 ] =
F_78 ( V_2 -> V_59 . V_111 , V_107 ) ;
V_107 += sizeof( T_1 ) ;
}
}
T_2
F_79 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
struct V_56 * V_112 ;
int V_98 ;
V_112 = (struct V_56 * )
F_80 ( F_81 ( V_2 ) , 0 ) ;
for ( V_98 = 0 ; V_98 < V_113 ; V_98 ++ ) {
if ( V_57 -> V_114 [ V_98 ] != V_112 -> V_114 [ V_98 ] ) {
F_3 ( V_2 , V_98 ) ;
F_3 ( V_2 , V_57 -> V_114 [ V_98 ] ) ;
F_3 ( V_2 , V_112 -> V_114 [ V_98 ] ) ;
return V_52 ;
}
}
F_3 ( V_2 , V_57 -> V_114 [ 0 ] ) ;
return V_71 ;
}
static T_2
F_82 ( struct V_1 * V_2 , T_1 V_115 )
{
struct V_56 V_57 , * V_112 ;
F_31 ( V_2 , & V_57 ) ;
V_112 = (struct V_56 * )
F_80 ( F_81 ( V_2 ) , 0 ) ;
if ( V_57 . V_116 != V_112 -> V_116 ) {
F_3 ( V_2 , V_57 . V_116 ) ;
F_3 ( V_2 , V_112 -> V_116 ) ;
return V_52 ;
}
if ( F_32 ( V_57 . V_117 ) != V_115 ) {
F_3 ( V_2 , V_57 . V_117 ) ;
F_3 ( V_2 , V_115 ) ;
return V_52 ;
}
return F_79 ( V_2 , & V_57 ) ;
}
static void
F_83 ( struct V_1 * V_2 )
{
T_1 V_95 ;
V_95 = F_30 ( V_2 -> V_59 . V_118 ) ;
if ( V_95 )
F_33 ( 1 , V_2 -> V_59 . V_118 ) ;
}
static void
F_49 ( struct V_1 * V_2 , T_2 V_119 )
{
enum V_120 V_60 ;
T_2 V_121 ;
T_1 V_122 ;
T_1 V_115 ;
V_60 = F_30 ( V_2 -> V_59 . V_60 ) ;
if ( V_119 )
V_60 = V_61 ;
F_3 ( V_2 , V_60 ) ;
V_122 = V_64 ;
V_115 = V_123 ;
V_121 = ( V_60 == V_61 ) ?
V_52 : F_82 ( V_2 , V_115 ) ;
if ( ! V_121 ) {
F_84 ( V_2 , V_122 , V_115 ) ;
F_85 ( V_2 ) ;
return;
}
if ( V_60 == V_124 ) {
F_85 ( V_2 ) ;
return;
}
if ( V_60 == V_125 || V_60 == V_126 ) {
F_83 ( V_2 ) ;
F_9 ( & V_2 -> V_7 , V_75 ) ;
return;
}
F_84 ( V_2 , V_122 , V_115 ) ;
F_85 ( V_2 ) ;
}
static void
F_86 ( void * V_127 )
{
struct V_1 * V_2 = (struct V_1 * ) V_127 ;
F_3 ( V_2 , 0 ) ;
F_9 ( V_2 , V_32 ) ;
}
void
F_87 ( struct V_1 * V_2 , void * V_128 , int V_129 )
{
T_1 * V_130 = ( T_1 * ) V_128 ;
T_1 V_98 ;
F_3 ( V_2 , V_130 [ 0 ] ) ;
F_3 ( V_2 , V_129 ) ;
F_71 ( V_129 > V_131 ) ;
for ( V_98 = 0 ; V_98 < V_129 / sizeof( T_1 ) ; V_98 ++ )
F_33 ( F_88 ( V_130 [ V_98 ] ) ,
V_2 -> V_59 . V_132 + V_98 * sizeof( T_1 ) ) ;
for (; V_98 < V_131 / sizeof( T_1 ) ; V_98 ++ )
F_33 ( 0 , V_2 -> V_59 . V_132 + V_98 * sizeof( T_1 ) ) ;
F_33 ( 1 , V_2 -> V_59 . V_133 ) ;
( void ) F_30 ( V_2 -> V_59 . V_133 ) ;
}
static void
F_52 ( struct V_1 * V_2 )
{
struct V_134 V_135 ;
struct V_136 V_137 ;
F_89 ( V_135 . V_138 , V_139 , V_140 ,
F_90 ( V_2 ) ) ;
V_135 . V_141 = F_91 ( V_2 -> V_141 ) ;
F_92 ( & V_137 ) ;
V_135 . V_142 = F_93 ( V_137 . V_142 ) ;
F_87 ( V_2 , & V_135 , sizeof( struct V_134 ) ) ;
}
static void
F_55 ( struct V_1 * V_2 )
{
struct V_134 V_143 ;
F_89 ( V_143 . V_138 , V_139 , V_144 ,
F_90 ( V_2 ) ) ;
F_87 ( V_2 , & V_143 , sizeof( struct V_134 ) ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
struct V_145 V_146 ;
F_89 ( V_146 . V_138 , V_139 , V_147 ,
F_90 ( V_2 ) ) ;
F_94 ( V_146 . V_148 , V_2 -> V_149 . V_150 ) ;
F_87 ( V_2 , & V_146 , sizeof( V_146 ) ) ;
}
static void
F_95 ( void * V_92 )
{
struct V_1 * V_2 = V_92 ;
T_1 V_151 ;
V_151 = F_30 ( V_2 -> V_59 . V_152 ) ;
if ( V_2 -> V_151 == V_151 ) {
F_96 ( V_2 ) ;
return;
} else {
V_2 -> V_151 = V_151 ;
}
F_97 ( V_2 ) ;
F_98 ( V_2 ) ;
}
static void
F_15 ( struct V_1 * V_2 )
{
V_2 -> V_151 = F_30 ( V_2 -> V_59 . V_152 ) ;
F_98 ( V_2 ) ;
}
static void
F_99 ( struct V_1 * V_2 , T_1 V_122 ,
T_1 V_115 )
{
T_1 * V_153 ;
T_1 V_105 , V_106 ;
T_1 V_107 = 0 ;
T_1 V_154 = 0 ;
T_1 V_98 ;
T_1 V_155 ;
F_72 ( V_2 ) ;
F_3 ( V_2 , F_100 ( F_81 ( V_2 ) ) ) ;
V_153 = F_80 ( F_81 ( V_2 ) , V_154 ) ;
V_105 = F_76 ( V_2 -> V_59 . V_109 , V_107 ) ;
V_106 = F_77 ( V_107 ) ;
F_33 ( V_105 , V_2 -> V_59 . V_110 ) ;
for ( V_98 = 0 ; V_98 < F_100 ( F_81 ( V_2 ) ) ; V_98 ++ ) {
if ( F_101 ( V_98 ) != V_154 ) {
V_154 = F_101 ( V_98 ) ;
V_153 = F_80 ( F_81 ( V_2 ) ,
F_102 ( V_154 ) ) ;
}
F_103 ( V_2 -> V_59 . V_111 , V_107 ,
V_153 [ F_104 ( V_98 ) ] ) ;
V_107 += sizeof( T_1 ) ;
V_107 = F_77 ( V_107 ) ;
if ( V_107 == 0 ) {
V_105 ++ ;
F_33 ( V_105 , V_2 -> V_59 . V_110 ) ;
}
}
F_33 ( F_76 ( V_2 -> V_59 . V_109 , 0 ) ,
V_2 -> V_59 . V_110 ) ;
V_155 = F_105 ( V_2 -> V_156 , V_2 -> V_157 ,
V_2 -> V_158 , V_2 -> V_159 ) ;
F_103 ( V_2 -> V_59 . V_111 , V_160 ,
F_32 ( V_155 ) ) ;
F_103 ( V_2 -> V_59 . V_111 , V_161 ,
F_32 ( V_122 ) ) ;
F_103 ( V_2 -> V_59 . V_111 , V_162 ,
F_32 ( V_115 ) ) ;
}
static void
F_106 ( struct V_1 * V_2 )
{
struct V_163 * V_164 = V_2 -> V_164 ;
V_164 -> V_165 = F_93 ( V_164 -> V_165 ) ;
V_164 -> V_166 = F_93 ( V_164 -> V_166 ) ;
V_164 -> V_167 = F_107 ( V_164 -> V_167 ) ;
V_2 -> V_168 = ( V_164 -> V_169 == V_170 ) ;
F_9 ( V_2 , V_28 ) ;
}
static void
F_108 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
int V_174 ;
F_109 ( & V_172 -> V_175 ) ;
for ( V_174 = 0 ; V_174 < V_176 ; V_174 ++ ) {
V_172 -> V_177 [ V_174 ] . V_18 = NULL ;
V_172 -> V_177 [ V_174 ] . V_92 = V_2 -> V_20 ;
}
}
static void
F_97 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
struct V_178 * V_179 ;
T_1 V_180 ;
if ( F_110 ( & V_172 -> V_175 ) )
return;
V_180 = F_30 ( V_2 -> V_59 . V_133 ) ;
if ( V_180 )
return;
F_111 ( & V_172 -> V_175 , & V_179 ) ;
F_87 ( V_2 , V_179 -> V_181 , sizeof( V_179 -> V_181 ) ) ;
}
static void
F_58 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
struct V_178 * V_179 ;
while ( ! F_110 ( & V_172 -> V_175 ) )
F_111 ( & V_172 -> V_175 , & V_179 ) ;
}
static T_4
F_112 ( struct V_1 * V_2 , void * V_182 , T_1 V_183 , T_1 V_184 )
{
T_1 V_105 , V_107 ;
T_5 V_95 ;
int V_98 , V_129 ;
T_1 * V_185 = V_182 ;
V_105 = F_76 ( V_2 -> V_59 . V_109 , V_183 ) ;
V_107 = F_77 ( V_183 ) ;
F_3 ( V_2 , V_105 ) ;
F_3 ( V_2 , V_107 ) ;
F_3 ( V_2 , V_184 ) ;
if ( V_52 == F_68 ( V_2 -> V_59 . V_186 ) ) {
F_3 ( V_2 , 0 ) ;
return V_187 ;
}
F_33 ( V_105 , V_2 -> V_59 . V_110 ) ;
V_129 = V_184 / sizeof( T_1 ) ;
F_3 ( V_2 , V_129 ) ;
for ( V_98 = 0 ; V_98 < V_129 ; V_98 ++ ) {
V_95 = F_78 ( V_2 -> V_59 . V_111 , V_107 ) ;
V_185 [ V_98 ] = F_93 ( V_95 ) ;
V_107 += sizeof( T_1 ) ;
V_107 = F_77 ( V_107 ) ;
if ( V_107 == 0 ) {
V_105 ++ ;
F_33 ( V_105 , V_2 -> V_59 . V_110 ) ;
}
}
F_33 ( F_76 ( V_2 -> V_59 . V_109 , 0 ) ,
V_2 -> V_59 . V_110 ) ;
F_30 ( V_2 -> V_59 . V_186 ) ;
F_33 ( 1 , V_2 -> V_59 . V_186 ) ;
F_3 ( V_2 , V_105 ) ;
return V_37 ;
}
static T_4
F_113 ( struct V_1 * V_2 , T_1 V_183 , T_1 V_184 )
{
int V_98 , V_129 ;
T_1 V_105 , V_107 ;
V_105 = F_76 ( V_2 -> V_59 . V_109 , V_183 ) ;
V_107 = F_77 ( V_183 ) ;
F_3 ( V_2 , V_105 ) ;
F_3 ( V_2 , V_107 ) ;
F_3 ( V_2 , V_184 ) ;
if ( V_52 == F_68 ( V_2 -> V_59 . V_186 ) ) {
F_3 ( V_2 , 0 ) ;
return V_187 ;
}
F_33 ( V_105 , V_2 -> V_59 . V_110 ) ;
V_129 = V_184 / sizeof( T_1 ) ;
F_3 ( V_2 , V_129 ) ;
for ( V_98 = 0 ; V_98 < V_129 ; V_98 ++ ) {
F_103 ( V_2 -> V_59 . V_111 , V_107 , 0 ) ;
V_107 += sizeof( T_1 ) ;
V_107 = F_77 ( V_107 ) ;
if ( V_107 == 0 ) {
V_105 ++ ;
F_33 ( V_105 , V_2 -> V_59 . V_110 ) ;
}
}
F_33 ( F_76 ( V_2 -> V_59 . V_109 , 0 ) ,
V_2 -> V_59 . V_110 ) ;
F_30 ( V_2 -> V_59 . V_186 ) ;
F_33 ( 1 , V_2 -> V_59 . V_186 ) ;
F_3 ( V_2 , V_105 ) ;
return V_37 ;
}
static void
F_22 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = (struct V_35 * ) V_2 -> V_20 -> V_36 ;
V_2 -> V_18 -> V_188 ( V_2 -> V_20 ) ;
F_19 ( V_2 , V_189 ) ;
F_60 ( V_2 ) ;
F_20 ( V_190 , V_36 , V_40 ,
L_3 ) ;
F_21 ( V_2 , V_191 ) ;
}
static void
F_42 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = (struct V_35 * ) V_2 -> V_20 -> V_36 ;
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
F_20 ( V_192 , V_36 , V_40 ,
L_4
L_5 ) ;
F_21 ( V_2 , V_193 ) ;
}
T_4
F_114 ( struct V_1 * V_2 )
{
F_68 ( V_2 -> V_59 . V_186 ) ;
F_115 ( V_2 ) ;
V_2 -> V_194 = V_71 ;
F_30 ( V_2 -> V_59 . V_186 ) ;
F_33 ( 1 , V_2 -> V_59 . V_186 ) ;
return V_37 ;
}
void
F_84 ( struct V_1 * V_2 , T_1 V_122 , T_1 V_115 )
{
F_116 ( V_2 , V_195 ) ;
if ( F_114 ( V_2 ) != V_37 )
return;
if ( V_122 == V_196 ) {
F_33 ( V_197 , V_2 -> V_59 . V_60 ) ;
F_33 ( V_197 , V_2 -> V_59 . V_198 ) ;
} else {
F_33 ( V_124 , V_2 -> V_59 . V_60 ) ;
F_33 ( V_124 , V_2 -> V_59 . V_198 ) ;
}
F_83 ( V_2 ) ;
F_99 ( V_2 , V_122 , V_115 ) ;
F_75 ( V_2 ) ;
}
void
F_117 ( T_2 V_42 )
{
V_53 = V_42 ;
}
T_2
F_118 ( struct V_1 * V_2 )
{
return F_119 ( V_2 , V_29 ) ;
}
T_2
F_120 ( struct V_1 * V_2 )
{
T_1 V_95 = F_30 ( V_2 -> V_59 . V_60 ) ;
return ( ( V_95 != V_61 ) &&
( V_95 != V_124 ) &&
( V_95 != V_197 ) ) ;
}
T_2
F_121 ( struct V_1 * V_2 , void * V_199 )
{
T_5 * V_130 = V_199 ;
T_1 V_95 ;
int V_98 ;
V_95 = F_30 ( V_2 -> V_59 . V_118 ) ;
if ( ( V_95 & 1 ) == 0 )
return V_52 ;
for ( V_98 = 0 ; V_98 < ( sizeof( union V_200 ) / sizeof( T_1 ) ) ;
V_98 ++ ) {
V_95 = F_30 ( V_2 -> V_59 . V_201 +
V_98 * sizeof( T_1 ) ) ;
V_130 [ V_98 ] = F_122 ( V_95 ) ;
}
F_33 ( 1 , V_2 -> V_59 . V_118 ) ;
F_30 ( V_2 -> V_59 . V_118 ) ;
return V_71 ;
}
void
F_123 ( struct V_1 * V_2 , struct V_202 * V_203 )
{
union V_200 * V_181 ;
struct V_50 * V_7 = & V_2 -> V_7 ;
V_181 = (union V_200 * ) V_203 ;
F_116 ( V_2 , V_204 ) ;
switch ( V_181 -> V_138 . V_205 ) {
case V_206 :
break;
case V_207 :
V_2 -> V_169 = V_2 -> V_208 =
(enum V_209 ) V_181 -> V_210 . V_169 ;
V_2 -> V_211 = V_181 -> V_210 . V_212 ;
F_9 ( V_7 , V_80 ) ;
break;
case V_213 :
F_9 ( V_7 , V_84 ) ;
break;
case V_214 :
F_106 ( V_2 ) ;
break;
case V_215 :
F_9 ( V_2 , V_30 ) ;
break;
default:
F_3 ( V_2 , V_181 -> V_138 . V_205 ) ;
F_71 ( 1 ) ;
}
}
void
F_124 ( struct V_1 * V_2 , void * V_20 , struct V_216 * V_18 ,
struct V_217 * V_218 )
{
V_2 -> V_20 = V_20 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_218 = V_218 ;
V_2 -> V_168 = V_52 ;
V_2 -> V_194 = V_52 ;
V_2 -> V_219 = V_71 ;
V_2 -> V_7 . V_2 = V_2 ;
F_108 ( V_2 ) ;
F_109 ( & V_2 -> V_220 ) ;
F_4 ( V_2 , F_2 ) ;
F_9 ( V_2 , V_5 ) ;
}
void
F_125 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_12 ) ;
F_109 ( & V_2 -> V_220 ) ;
}
void
F_126 ( struct V_1 * V_2 , struct V_221 * V_222 ,
enum V_223 V_141 )
{
V_2 -> V_141 = V_141 ;
V_2 -> V_222 = * V_222 ;
V_2 -> V_158 = V_2 -> V_159 = V_170 ;
V_2 -> V_157 = V_224 ;
switch ( V_222 -> V_225 ) {
case V_226 :
case V_227 :
V_2 -> V_156 = V_228 ;
V_2 -> V_168 = V_71 ;
V_2 -> V_169 = V_2 -> V_208 = V_229 ;
V_2 -> V_211 = V_230 ;
break;
case V_231 :
V_2 -> V_156 = V_232 ;
V_2 -> V_158 = V_2 -> V_159 = V_233 ;
V_2 -> V_157 = V_234 ;
V_2 -> V_169 = V_2 -> V_208 = V_235 ;
V_2 -> V_211 = V_236 ;
break;
case V_237 :
V_2 -> V_156 = V_232 ;
V_2 -> V_168 = V_71 ;
V_2 -> V_169 = V_2 -> V_208 = V_229 ;
V_2 -> V_211 = V_230 ;
break;
case V_238 :
V_2 -> V_156 = V_239 ;
if ( V_141 == V_240 &&
V_222 -> V_241 == V_242 ) {
V_2 -> V_157 = V_243 ;
V_2 -> V_168 = V_71 ;
V_2 -> V_169 = V_2 -> V_208 = V_229 ;
V_2 -> V_211 = V_230 ;
} else {
V_2 -> V_158 = V_2 -> V_159 = V_233 ;
V_2 -> V_157 = V_234 ;
if ( V_222 -> V_241 == V_244 ) {
V_2 -> V_169 =
V_2 -> V_208 = V_235 ;
V_2 -> V_211 = V_236 ;
} else {
V_2 -> V_169 =
V_2 -> V_208 = V_245 ;
V_2 -> V_211 = V_246 ;
}
}
break;
default:
F_71 ( 1 ) ;
}
if ( V_2 -> V_156 == V_228 )
F_127 ( V_2 ) ;
else if ( V_2 -> V_156 == V_232 )
F_128 ( V_2 ) ;
else {
F_71 ( V_2 -> V_156 != V_239 ) ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
}
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
}
void
F_133 ( struct V_1 * V_2 , T_6 * V_247 , T_7 V_248 )
{
V_2 -> V_149 . V_249 = V_247 ;
V_2 -> V_149 . V_150 = V_248 ;
V_2 -> V_164 = (struct V_163 * ) V_247 ;
}
void
F_134 ( struct V_1 * V_2 )
{
F_116 ( V_2 , V_250 ) ;
V_2 -> V_219 = V_71 ;
F_9 ( V_2 , V_9 ) ;
}
void
F_135 ( struct V_1 * V_2 )
{
F_116 ( V_2 , V_251 ) ;
F_9 ( V_2 , V_11 ) ;
}
void
F_136 ( struct V_1 * V_2 , void * V_252 )
{
V_2 -> V_252 = V_252 ;
V_2 -> V_253 = ( V_2 -> V_7 . V_42 ) ? V_254 : 0 ;
}
void
F_137 ( struct V_1 * V_2 , T_8 * V_255 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
int V_174 ;
for ( V_174 = 0 ; V_174 < V_176 ; V_174 ++ )
V_172 -> V_177 [ V_174 ] . V_18 = V_255 [ V_174 ] ;
}
void
F_138 ( struct V_1 * V_2 , enum V_256 V_174 ,
T_8 V_18 , void * V_92 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
V_172 -> V_177 [ V_174 ] . V_18 = V_18 ;
V_172 -> V_177 [ V_174 ] . V_92 = V_92 ;
}
void
F_139 ( struct V_1 * V_2 , struct V_178 * V_179 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
T_1 V_180 ;
if ( ! F_110 ( & V_172 -> V_175 ) ) {
F_140 ( & V_179 -> V_91 , & V_172 -> V_175 ) ;
return;
}
V_180 = F_30 ( V_2 -> V_59 . V_133 ) ;
if ( V_180 ) {
F_140 ( & V_179 -> V_91 , & V_172 -> V_175 ) ;
return;
}
F_87 ( V_2 , V_179 -> V_181 , sizeof( V_179 -> V_181 ) ) ;
}
void
F_141 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
struct V_202 V_203 ;
int V_174 ;
if ( F_121 ( V_2 , & V_203 ) ) {
V_174 = V_203 . V_138 . V_257 ;
if ( V_174 == V_139 ) {
F_123 ( V_2 , & V_203 ) ;
return;
}
if ( ( V_174 > V_176 ) || ( V_172 -> V_177 [ V_174 ] . V_18 == NULL ) )
return;
V_172 -> V_177 [ V_174 ] . V_18 ( V_172 -> V_177 [ V_174 ] . V_92 , & V_203 ) ;
}
F_142 ( V_2 ) ;
F_97 ( V_2 ) ;
}
void
F_143 ( struct V_1 * V_2 )
{
F_116 ( V_2 , V_258 ) ;
V_2 -> V_259 . V_151 = V_2 -> V_151 ;
F_9 ( V_2 , V_17 ) ;
}
T_2
F_144 ( struct V_1 * V_2 )
{
return F_119 ( V_2 , V_26 ) ||
F_119 ( V_2 , V_48 ) ;
}
T_2
F_145 ( struct V_1 * V_2 )
{
return F_119 ( V_2 , V_31 ) ;
}
T_2
F_146 ( struct V_1 * V_2 )
{
return F_119 ( V_2 , V_6 ) ||
F_119 ( & V_2 -> V_7 , V_55 ) ||
F_119 ( & V_2 -> V_7 , V_68 ) ;
}
T_2
F_147 ( struct V_1 * V_2 )
{
T_1 V_260 ;
if ( ! F_119 ( V_2 , V_48 ) )
return V_52 ;
V_260 = F_30 ( V_2 -> V_59 . V_60 ) ;
if ( ! F_148 ( V_260 ) )
return V_52 ;
if ( V_2 -> V_222 . V_225 != V_226 ) {
V_260 = F_30 ( V_2 -> V_59 . V_198 ) ;
if ( ! F_148 ( V_260 ) )
return V_52 ;
}
return V_71 ;
}
void
F_149 ( struct V_1 * V_2 )
{
F_33 ( V_61 , V_2 -> V_59 . V_60 ) ;
F_33 ( V_61 , V_2 -> V_59 . V_198 ) ;
}
void
F_150 ( struct V_1 * V_2 ,
struct V_261 * V_262 )
{
struct V_163 * V_263 ;
V_263 = V_2 -> V_164 ;
F_151 ( V_2 , V_262 -> V_264 ) ;
F_152 ( V_2 , V_262 -> V_265 ) ;
F_153 ( V_2 , V_262 -> V_266 ) ;
F_154 ( V_2 , V_262 -> V_267 ) ;
memcpy ( & V_262 -> V_268 , & V_263 -> V_268 ,
sizeof( struct V_269 ) ) ;
V_262 -> V_270 = F_155 ( V_2 ) ;
V_262 -> V_271 = F_156 ( V_2 ) ;
F_157 ( V_2 , V_262 -> V_272 ) ;
F_157 ( V_2 , V_262 -> V_273 ) ;
V_262 -> V_166 = V_263 -> V_166 ;
V_262 -> V_274 = F_158 ( V_263 -> V_166 ) ;
if ( F_159 ( V_263 -> V_165 ) )
V_262 -> V_275 = 1 ;
else
V_262 -> V_275 = 0 ;
V_262 -> V_276 = V_2 -> V_164 -> V_276 ;
V_262 -> V_277 = F_160 ( V_2 ) ;
V_262 -> V_278 = V_263 -> V_278 ;
V_262 -> V_279 = V_263 -> V_279 ;
V_262 -> V_280 = V_263 -> V_280 ;
V_262 -> V_281 = V_263 -> V_281 ;
F_161 ( V_2 , V_262 -> V_282 ) ;
V_262 -> V_283 = F_162 ( V_2 ) ;
V_262 -> V_284 = ( V_262 -> V_270 > 1 ) &&
! F_162 ( V_2 ) && ! V_262 -> V_274 ;
}
enum V_285
F_163 ( struct V_1 * V_2 )
{
if ( V_2 -> V_141 == V_286 )
return V_287 ;
F_71 ( V_2 -> V_141 != V_240 ) ;
return ( V_2 -> V_164 -> V_169 == V_170 )
? V_288 : V_289 ;
}
void
F_151 ( struct V_1 * V_2 , char * V_264 )
{
memset ( ( void * ) V_264 , 0 , V_290 ) ;
memcpy ( ( void * ) V_264 ,
( void * ) V_2 -> V_164 -> V_291 ,
V_290 ) ;
}
void
F_152 ( struct V_1 * V_2 , char * V_265 )
{
memset ( ( void * ) V_265 , 0 , V_292 ) ;
memcpy ( V_265 , V_2 -> V_164 -> V_293 , V_292 ) ;
}
void
F_161 ( struct V_1 * V_2 , char * V_294 )
{
F_71 ( ! V_294 ) ;
memset ( ( void * ) V_294 , 0 , V_295 ) ;
V_294 [ 0 ] = 'R' ;
V_294 [ 1 ] = 'e' ;
V_294 [ 2 ] = 'v' ;
V_294 [ 3 ] = '-' ;
V_294 [ 4 ] = V_2 -> V_164 -> V_281 ;
V_294 [ 5 ] = '\0' ;
}
void
F_153 ( struct V_1 * V_2 , char * V_266 )
{
memset ( ( void * ) V_266 , 0 , V_292 ) ;
memcpy ( V_266 , V_2 -> V_164 -> V_296 ,
V_292 ) ;
}
void
F_154 ( struct V_1 * V_2 , char * V_267 )
{
memset ( ( void * ) V_267 , 0 , V_297 ) ;
memcpy ( V_267 , V_298 , V_297 ) ;
}
void
F_157 ( struct V_1 * V_2 , char * V_272 )
{
struct V_163 * V_263 ;
F_71 ( ! V_272 ) ;
memset ( ( void * ) V_272 , 0 , V_299 ) ;
V_263 = V_2 -> V_164 ;
snprintf ( V_272 , V_299 , L_6 ,
V_298 , V_263 -> V_166 ) ;
}
enum V_300
F_164 ( struct V_1 * V_2 )
{
enum V_301 V_302 ;
enum V_300 V_303 = F_165 ( V_304 , V_2 -> V_305 ) ;
if ( V_303 == V_306 ||
V_303 == V_307 || V_303 == V_308 ) {
V_302 = F_165 ( V_309 , V_2 -> V_7 . V_305 ) ;
switch ( V_302 ) {
case V_310 :
V_303 = V_311 ;
break;
case V_312 :
V_303 = V_313 ;
break;
case V_314 :
V_303 = V_315 ;
break;
case V_316 :
V_303 = V_307 ;
break;
case V_317 :
V_303 = V_308 ;
break;
default:
break;
}
}
return V_303 ;
}
void
F_166 ( struct V_1 * V_2 , struct V_318 * V_263 )
{
memset ( ( void * ) V_263 , 0 , sizeof( struct V_318 ) ) ;
V_263 -> V_319 = F_164 ( V_2 ) ;
V_263 -> V_320 = V_2 -> V_320 ;
V_263 -> V_169 = V_2 -> V_169 ;
V_263 -> V_208 = V_2 -> V_208 ;
V_263 -> V_212 = V_2 -> V_211 ;
V_263 -> V_321 = F_163 ( V_2 ) ;
F_150 ( V_2 , & V_263 -> V_322 ) ;
V_263 -> V_323 . V_225 = V_2 -> V_222 . V_225 ;
V_263 -> V_323 . V_324 = V_2 -> V_222 . V_325 ;
F_161 ( V_2 , V_263 -> V_323 . V_294 ) ;
}
T_9
F_160 ( struct V_1 * V_2 )
{
if ( F_163 ( V_2 ) == V_289 )
return V_2 -> V_164 -> V_326 ;
else
return V_2 -> V_164 -> V_277 ;
}
T_9
F_167 ( struct V_1 * V_2 )
{
T_9 V_203 ;
V_203 = V_2 -> V_164 -> V_327 ;
if ( F_168 ( V_2 -> V_164 -> V_166 ) )
V_203 . V_277 [ V_328 - 1 ] += F_169 ( V_2 ) ;
else
F_170 ( & ( V_203 . V_277 [ V_328 - 3 ] ) ,
F_169 ( V_2 ) ) ;
return V_203 ;
}
void
F_21 ( struct V_1 * V_2 , enum V_329 V_4 )
{
struct V_35 * V_36 = (struct V_35 * ) V_2 -> V_20 -> V_36 ;
struct V_330 * V_331 ;
enum V_285 V_321 ;
F_171 ( V_36 , V_331 ) ;
if ( ! V_331 )
return;
V_321 = F_163 ( V_2 ) ;
switch ( V_321 ) {
case V_288 :
V_331 -> V_332 . V_2 . V_276 = V_2 -> V_164 -> V_276 ;
break;
case V_289 :
V_331 -> V_332 . V_2 . V_276 = V_2 -> V_164 -> V_276 ;
V_331 -> V_332 . V_2 . V_277 = F_160 ( V_2 ) ;
break;
case V_287 :
V_331 -> V_332 . V_2 . V_277 = F_160 ( V_2 ) ;
break;
default:
F_71 ( V_321 != V_288 ) ;
break;
}
V_331 -> V_332 . V_2 . V_321 = V_321 ;
F_172 ( V_331 , V_36 , ++ V_2 -> V_333 ,
V_334 , V_4 ) ;
}
T_4
F_173 ( struct V_1 * V_2 , void * V_335 , int * V_336 )
{
int V_337 ;
if ( V_2 -> V_253 == 0 )
return V_338 ;
V_337 = * V_336 ;
if ( V_337 > V_2 -> V_253 )
V_337 = V_2 -> V_253 ;
memcpy ( V_335 , V_2 -> V_252 , V_337 ) ;
* V_336 = V_337 ;
return V_37 ;
}
T_4
F_174 ( struct V_1 * V_2 , void * V_335 , int * V_336 )
{
T_1 V_107 = F_175 ( F_90 ( V_2 ) ) ;
int V_337 ;
T_4 V_339 ;
F_3 ( V_2 , * V_336 ) ;
V_337 = * V_336 ;
if ( V_337 > V_254 )
V_337 = V_254 ;
V_339 = F_112 ( V_2 , V_335 , V_107 , V_337 ) ;
* V_336 = V_337 ;
return V_339 ;
}
static void
F_176 ( struct V_1 * V_2 )
{
struct V_178 V_179 ;
struct V_134 * V_340 = (struct V_134 * ) V_179 . V_181 ;
F_89 ( V_340 -> V_138 , V_139 , V_341 ,
F_90 ( V_2 ) ) ;
V_340 -> V_141 = F_91 ( V_2 -> V_141 ) ;
F_139 ( V_2 , & V_179 ) ;
}
static void
F_177 ( struct V_1 * V_2 )
{
T_1 V_342 = 1000 ;
F_176 ( V_2 ) ;
while ( F_178 ( V_2 ) && V_342 > 0 )
V_342 -- ;
}
T_4
F_179 ( struct V_1 * V_2 , void * V_185 ,
T_1 * V_343 , int * V_344 )
{
T_1 V_107 ;
int V_345 ;
T_4 V_339 ;
T_1 V_346 = F_180 ( V_2 ) ;
if ( * V_343 >= V_346 ) {
* V_343 = * V_344 = 0 ;
return V_347 ;
}
V_107 = * V_343 ;
V_345 = * V_344 ;
if ( V_107 == 0 )
F_177 ( V_2 ) ;
if ( ( V_107 + V_345 ) >= V_346 )
V_345 = V_346 - V_107 ;
V_339 = F_112 ( V_2 , V_185 , V_107 , V_345 ) ;
if ( V_339 != V_37 ) {
* V_343 = * V_344 = 0 ;
return V_339 ;
}
* V_343 += V_345 ;
if ( * V_343 >= V_346 )
* V_343 = 0 ;
* V_344 = V_345 ;
return V_339 ;
}
T_4
F_181 ( struct V_1 * V_2 , void * V_259 )
{
T_1 V_107 = V_348 + \
V_349 * ( F_90 ( V_2 ) ) ;
int V_337 ;
T_4 V_339 ;
if ( V_2 -> V_350 ) {
F_3 ( V_2 , V_2 -> V_350 ) ;
return V_351 ;
}
V_2 -> V_350 = V_71 ;
V_337 = sizeof( struct V_352 ) ;
V_339 = F_112 ( V_2 , V_259 , V_107 , V_337 ) ;
V_2 -> V_350 = V_52 ;
return V_339 ;
}
T_4
F_182 ( struct V_1 * V_2 )
{
T_1 V_107 = V_348 + \
V_349 * ( F_90 ( V_2 ) ) ;
int V_337 ;
T_4 V_339 ;
if ( V_2 -> V_350 ) {
F_3 ( V_2 , V_2 -> V_350 ) ;
return V_351 ;
}
V_2 -> V_350 = V_71 ;
V_337 = sizeof( struct V_352 ) ;
V_339 = F_113 ( V_2 , V_107 , V_337 ) ;
V_2 -> V_350 = V_52 ;
return V_339 ;
}
static void
F_60 ( struct V_1 * V_2 )
{
int V_337 ;
if ( V_2 -> V_219 ) {
V_2 -> V_219 = V_52 ;
if ( V_2 -> V_253 ) {
V_337 = V_2 -> V_253 ;
F_174 ( V_2 , V_2 -> V_252 , & V_337 ) ;
}
}
}
static void
F_96 ( struct V_1 * V_2 )
{
F_116 ( V_2 , V_258 ) ;
V_2 -> V_259 . V_151 = V_2 -> V_151 ;
F_9 ( V_2 , V_34 ) ;
}
static void
F_14 ( struct V_1 * V_2 )
{
if ( F_163 ( V_2 ) == V_287 )
return;
if ( V_2 -> V_164 -> V_353 == 0 )
F_21 ( V_2 , V_354 ) ;
if ( V_2 -> V_164 -> V_276 == 0 )
F_21 ( V_2 , V_355 ) ;
}
static void
F_183 ( void * V_127 )
{
struct V_1 * V_2 = (struct V_1 * ) V_127 ;
F_3 ( V_2 , 0 ) ;
F_9 ( & V_2 -> V_7 , V_72 ) ;
}
static void
F_184 ( void * V_127 )
{
struct V_1 * V_2 = (struct V_1 * ) V_127 ;
F_34 ( V_2 ) ;
}
static void
F_85 ( struct V_1 * V_2 )
{
T_1 V_58 = F_30 ( V_2 -> V_59 . V_60 ) ;
F_3 ( V_2 , V_58 ) ;
if ( V_58 == V_125 ) {
F_9 ( & V_2 -> V_7 , V_75 ) ;
return;
}
if ( V_2 -> V_7 . V_74 >= V_356 )
F_183 ( V_2 ) ;
else {
V_2 -> V_7 . V_74 += V_357 ;
F_185 ( V_2 ) ;
}
}
static void
F_186 ( void * V_127 )
{
struct V_1 * V_2 = (struct V_1 * ) V_127 ;
F_85 ( V_2 ) ;
}
void
F_187 ( struct V_217 * V_172 )
{
struct V_90 * V_358 = & V_172 -> V_359 ;
struct V_90 * V_91 , * V_360 ;
struct V_361 * V_362 ;
struct V_90 V_363 ;
F_109 ( & V_363 ) ;
V_91 = F_188 ( V_358 ) ;
while ( V_91 != V_358 ) {
V_360 = F_188 ( V_91 ) ;
V_362 = (struct V_361 * ) V_91 ;
if ( V_362 -> V_364 <= V_365 ) {
V_362 -> V_364 = 0 ;
F_189 ( & V_362 -> V_91 ) ;
F_140 ( & V_362 -> V_91 , & V_363 ) ;
} else {
V_362 -> V_364 -= V_365 ;
}
V_91 = V_360 ;
}
while ( ! F_110 ( & V_363 ) ) {
F_111 ( & V_363 , & V_362 ) ;
V_362 -> V_366 ( V_362 -> V_367 ) ;
}
}
void
F_190 ( struct V_217 * V_172 , struct V_361 * V_368 ,
void (* V_366) ( void * ) , void * V_367 , unsigned int V_364 )
{
F_71 ( V_366 == NULL ) ;
F_71 ( F_191 ( & V_172 -> V_359 , V_368 ) ) ;
V_368 -> V_364 = V_364 ;
V_368 -> V_366 = V_366 ;
V_368 -> V_367 = V_367 ;
F_140 ( & V_368 -> V_91 , & V_172 -> V_359 ) ;
}
void
F_192 ( struct V_361 * V_368 )
{
F_71 ( F_110 ( & V_368 -> V_91 ) ) ;
F_189 ( & V_368 -> V_91 ) ;
}
static void
F_193 ( struct V_369 * V_370 )
{
struct V_371 * V_372 ;
int V_98 , V_373 ;
T_10 V_374 ;
T_1 V_375 ;
for ( V_98 = 0 ; V_98 < V_376 ; V_98 ++ ) {
V_372 = & V_370 -> V_377 [ V_98 ] ;
for ( V_373 = 0 ; V_373 < V_378 ; V_373 ++ ) {
V_374 = V_372 -> V_379 [ V_373 ] . V_380 ;
V_372 -> V_379 [ V_373 ] . V_380 = F_107 ( V_374 ) ;
V_374 = V_372 -> V_379 [ V_373 ] . V_381 ;
V_372 -> V_379 [ V_373 ] . V_381 = F_107 ( V_374 ) ;
V_374 = V_372 -> V_379 [ V_373 ] . V_382 ;
V_372 -> V_379 [ V_373 ] . V_382 = F_107 ( V_374 ) ;
V_375 = V_372 -> V_379 [ V_373 ] . V_383 ;
V_372 -> V_379 [ V_373 ] . V_383 = F_107 ( V_375 ) ;
}
}
}
static void
F_194 ( void * V_92 , struct V_202 * V_181 )
{
struct V_384 * V_385 = (struct V_384 * ) V_92 ;
struct V_386 * V_387 = (struct V_386 * ) V_181 ;
T_11 V_18 ;
F_71 ( V_181 -> V_138 . V_257 != V_388 ) ;
F_3 ( V_385 -> V_2 , V_181 -> V_138 . V_205 ) ;
switch ( V_181 -> V_138 . V_205 ) {
case V_389 :
if ( V_387 -> V_339 == V_37 ) {
memcpy ( V_385 -> V_370 , V_385 -> V_390 . V_249 ,
sizeof( struct V_369 ) ) ;
F_193 ( V_385 -> V_370 ) ;
V_385 -> V_370 = NULL ;
}
break;
case V_391 :
case V_392 :
V_385 -> V_2 -> V_208 = V_387 -> V_169 ;
case V_393 :
case V_394 :
case V_395 :
case V_396 :
break;
case V_397 :
* ( V_385 -> V_324 ) = V_387 -> V_324 ;
V_385 -> V_324 = NULL ;
break;
default:
F_71 ( 1 ) ;
}
V_385 -> V_398 = V_52 ;
if ( V_385 -> V_18 ) {
V_18 = V_385 -> V_18 ;
V_385 -> V_18 = NULL ;
V_18 ( V_385 -> V_92 , V_387 -> V_339 ) ;
}
}
static void
F_195 ( void * V_92 , enum V_87 V_4 )
{
struct V_384 * V_385 = (struct V_384 * ) V_92 ;
F_3 ( V_385 -> V_2 , V_4 ) ;
switch ( V_4 ) {
case V_38 :
F_71 ( V_385 -> V_398 != V_52 ) ;
break;
case V_93 :
case V_189 :
V_385 -> V_324 = NULL ;
if ( V_385 -> V_398 ) {
if ( V_385 -> V_18 )
V_385 -> V_18 ( V_385 -> V_92 , V_187 ) ;
V_385 -> V_18 = NULL ;
V_385 -> V_398 = V_52 ;
}
break;
default:
F_71 ( 1 ) ;
break;
}
}
T_1
F_196 ( void )
{
return F_197 ( sizeof( struct V_369 ) , V_399 ) ;
}
void
F_198 ( struct V_384 * V_385 , T_6 * V_400 , T_7 V_401 )
{
V_385 -> V_390 . V_249 = V_400 ;
V_385 -> V_390 . V_150 = V_401 ;
}
void
F_199 ( struct V_384 * V_385 , struct V_1 * V_2 )
{
V_385 -> V_2 = V_2 ;
F_138 ( V_385 -> V_2 , V_388 , F_194 , V_385 ) ;
F_200 ( & V_385 -> V_402 ) ;
F_201 ( & V_385 -> V_402 , F_195 , V_385 ) ;
F_140 ( & V_385 -> V_402 . V_91 , & V_385 -> V_2 -> V_220 ) ;
}
T_4
F_202 ( struct V_384 * V_385 , struct V_369 * V_403 ,
T_11 V_18 , void * V_92 )
{
struct V_404 * V_203 ;
F_71 ( ! V_403 ) ;
if ( ! F_118 ( V_385 -> V_2 ) ) {
F_3 ( V_385 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_385 -> V_398 ) {
F_3 ( V_385 -> V_2 , V_351 ) ;
return V_351 ;
}
V_385 -> V_370 = V_403 ;
V_385 -> V_18 = V_18 ;
V_385 -> V_92 = V_92 ;
V_385 -> V_398 = V_71 ;
V_203 = (struct V_404 * ) V_385 -> V_405 . V_181 ;
F_89 ( V_203 -> V_138 , V_388 , V_406 ,
F_90 ( V_385 -> V_2 ) ) ;
F_94 ( V_203 -> V_407 , V_385 -> V_390 . V_150 ) ;
F_139 ( V_385 -> V_2 , & V_385 -> V_405 ) ;
return V_37 ;
}
T_4
F_203 ( struct V_384 * V_385 , T_10 * V_324 ,
T_6 V_408 , enum V_223 V_409 , int V_383 ,
T_11 V_18 , void * V_92 )
{
struct V_410 * V_203 ;
if ( ! F_118 ( V_385 -> V_2 ) ) {
F_3 ( V_385 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_385 -> V_398 ) {
F_3 ( V_385 -> V_2 , V_351 ) ;
return V_351 ;
}
V_385 -> V_324 = V_324 ;
V_385 -> V_18 = V_18 ;
V_385 -> V_92 = V_92 ;
V_385 -> V_398 = V_71 ;
V_203 = (struct V_410 * ) V_385 -> V_405 . V_181 ;
F_89 ( V_203 -> V_138 , V_388 , V_411 ,
F_90 ( V_385 -> V_2 ) ) ;
V_203 -> V_380 = F_91 ( ( T_10 ) V_409 ) ;
V_203 -> V_383 = F_122 ( V_383 ) ;
V_203 -> V_408 = V_408 ;
F_139 ( V_385 -> V_2 , & V_385 -> V_405 ) ;
return V_37 ;
}
T_4
F_204 ( struct V_384 * V_385 , int V_324 ,
T_11 V_18 , void * V_92 )
{
struct V_410 * V_203 ;
if ( ! F_118 ( V_385 -> V_2 ) ) {
F_3 ( V_385 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_385 -> V_398 ) {
F_3 ( V_385 -> V_2 , V_351 ) ;
return V_351 ;
}
V_385 -> V_18 = V_18 ;
V_385 -> V_92 = V_92 ;
V_385 -> V_398 = V_71 ;
V_203 = (struct V_410 * ) V_385 -> V_405 . V_181 ;
F_89 ( V_203 -> V_138 , V_388 , V_412 ,
F_90 ( V_385 -> V_2 ) ) ;
V_203 -> V_324 = ( T_6 ) V_324 ;
F_139 ( V_385 -> V_2 , & V_385 -> V_405 ) ;
return V_37 ;
}
T_4
F_205 ( struct V_384 * V_385 , enum V_209 V_413 ,
int V_414 , int V_415 , T_11 V_18 , void * V_92 )
{
struct V_416 * V_203 ;
if ( ! F_118 ( V_385 -> V_2 ) ) {
F_3 ( V_385 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_385 -> V_398 ) {
F_3 ( V_385 -> V_2 , V_351 ) ;
return V_351 ;
}
V_385 -> V_18 = V_18 ;
V_385 -> V_92 = V_92 ;
V_385 -> V_398 = V_71 ;
V_203 = (struct V_416 * ) V_385 -> V_405 . V_181 ;
F_89 ( V_203 -> V_138 , V_388 , V_417 ,
F_90 ( V_385 -> V_2 ) ) ;
V_203 -> V_413 = ( T_6 ) V_413 ;
V_203 -> V_414 = ( T_6 ) V_414 ;
V_203 -> V_415 = ( T_6 ) V_415 ;
F_139 ( V_385 -> V_2 , & V_385 -> V_405 ) ;
return V_37 ;
}
T_4
F_206 ( struct V_384 * V_385 , int V_408 , enum V_209 V_413 ,
int V_414 , int V_415 , T_11 V_18 , void * V_92 )
{
struct V_416 * V_203 ;
if ( ! F_118 ( V_385 -> V_2 ) ) {
F_3 ( V_385 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_385 -> V_398 ) {
F_3 ( V_385 -> V_2 , V_351 ) ;
return V_351 ;
}
V_385 -> V_18 = V_18 ;
V_385 -> V_92 = V_92 ;
V_385 -> V_398 = V_71 ;
V_203 = (struct V_416 * ) V_385 -> V_405 . V_181 ;
F_89 ( V_203 -> V_138 , V_388 , V_418 ,
F_90 ( V_385 -> V_2 ) ) ;
V_203 -> V_408 = ( T_6 ) V_408 ;
V_203 -> V_413 = ( T_6 ) V_413 ;
V_203 -> V_414 = ( T_6 ) V_414 ;
V_203 -> V_415 = ( T_6 ) V_415 ;
F_139 ( V_385 -> V_2 , & V_385 -> V_405 ) ;
return V_37 ;
}
T_4
F_207 ( struct V_384 * V_385 , int V_324 , int V_383 ,
T_11 V_18 , void * V_92 )
{
struct V_410 * V_203 ;
if ( ! F_118 ( V_385 -> V_2 ) ) {
F_3 ( V_385 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_385 -> V_398 ) {
F_3 ( V_385 -> V_2 , V_351 ) ;
return V_351 ;
}
V_385 -> V_18 = V_18 ;
V_385 -> V_92 = V_92 ;
V_385 -> V_398 = V_71 ;
V_203 = (struct V_410 * ) V_385 -> V_405 . V_181 ;
F_89 ( V_203 -> V_138 , V_388 , V_419 ,
F_90 ( V_385 -> V_2 ) ) ;
V_203 -> V_324 = ( T_6 ) V_324 ;
V_203 -> V_383 = F_122 ( V_383 ) ;
F_139 ( V_385 -> V_2 , & V_385 -> V_405 ) ;
return V_37 ;
}
T_4
F_208 ( struct V_384 * V_385 , T_11 V_18 , void * V_92 )
{
struct V_420 * V_203 ;
if ( ! F_118 ( V_385 -> V_2 ) ) {
F_3 ( V_385 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_385 -> V_398 ) {
F_3 ( V_385 -> V_2 , V_351 ) ;
return V_351 ;
}
V_385 -> V_18 = V_18 ;
V_385 -> V_92 = V_92 ;
V_385 -> V_398 = V_71 ;
V_203 = (struct V_420 * ) V_385 -> V_405 . V_181 ;
F_89 ( V_203 -> V_138 , V_388 , V_421 ,
F_90 ( V_385 -> V_2 ) ) ;
F_139 ( V_385 -> V_2 , & V_385 -> V_405 ) ;
return V_37 ;
}
T_4
F_209 ( struct V_384 * V_385 , T_11 V_18 , void * V_92 )
{
struct V_420 * V_203 ;
if ( ! F_118 ( V_385 -> V_2 ) ) {
F_3 ( V_385 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_385 -> V_398 ) {
F_3 ( V_385 -> V_2 , V_351 ) ;
return V_351 ;
}
V_385 -> V_18 = V_18 ;
V_385 -> V_92 = V_92 ;
V_385 -> V_398 = V_71 ;
V_203 = (struct V_420 * ) V_385 -> V_405 . V_181 ;
F_89 ( V_203 -> V_138 , V_388 , V_422 ,
F_90 ( V_385 -> V_2 ) ) ;
F_139 ( V_385 -> V_2 , & V_385 -> V_405 ) ;
return V_37 ;
}
static void
F_210 ( struct V_423 * V_424 )
{
F_3 ( V_424 , V_424 -> V_425 ) ;
if ( V_424 -> V_18 )
V_424 -> V_18 ( V_424 -> V_92 , V_424 -> V_339 ) ;
V_424 -> V_425 = 0 ;
V_424 -> V_18 = NULL ;
}
static void
F_211 ( struct V_423 * V_424 )
{
F_3 ( V_424 , V_424 -> V_426 ) ;
if ( V_424 -> V_427 ) {
F_212 ( V_424 ) ;
if ( V_424 -> V_428 )
V_424 -> V_428 ( V_424 -> V_429 ,
V_424 -> V_339 ) ;
V_424 -> V_427 = NULL ;
}
if ( V_424 -> V_426 ) {
V_424 -> V_339 = F_213 ( V_424 , V_424 -> V_426 ) ;
if ( V_424 -> V_428 )
V_424 -> V_428 ( V_424 -> V_429 ,
V_424 -> V_339 ) ;
V_424 -> V_426 = V_430 ;
}
V_424 -> V_431 = 0 ;
V_424 -> V_428 = NULL ;
}
static void
F_214 ( void * V_432 , enum V_87 V_4 )
{
struct V_423 * V_424 = V_432 ;
F_3 ( V_424 , V_4 ) ;
F_3 ( V_424 , V_424 -> V_425 ) ;
F_3 ( V_424 , V_424 -> V_431 ) ;
switch ( V_4 ) {
case V_93 :
case V_189 :
if ( V_424 -> V_425 ) {
V_424 -> V_339 = V_21 ;
F_210 ( V_424 ) ;
}
if ( V_424 -> V_431 ) {
V_424 -> V_339 = V_21 ;
F_211 ( V_424 ) ;
}
break;
default:
break;
}
}
static void
F_215 ( struct V_423 * V_424 , struct V_433 * V_387 )
{
struct V_35 * V_36 = (struct V_35 * ) V_424 -> V_2 -> V_20 -> V_36 ;
struct V_330 * V_331 ;
enum V_434 V_435 = 0 ;
F_3 ( V_424 , ( ( ( T_7 ) V_387 -> V_436 ) << 16 ) | ( ( ( T_7 ) V_387 -> V_437 ) << 8 ) |
( ( T_7 ) V_387 -> V_4 ) ) ;
F_171 ( V_36 , V_331 ) ;
if ( ! V_331 )
return;
V_331 -> V_332 . V_408 . V_321 = F_163 ( V_424 -> V_2 ) ;
V_331 -> V_332 . V_408 . V_276 = V_424 -> V_2 -> V_164 -> V_276 ;
V_331 -> V_332 . V_408 . V_277 = F_160 ( V_424 -> V_2 ) ;
switch ( V_387 -> V_4 ) {
case V_438 :
V_435 = V_439 ;
break;
case V_440 :
V_435 = V_441 ;
break;
case V_442 :
V_435 = V_443 ;
break;
case V_444 :
V_435 = V_445 ;
break;
case V_446 :
V_435 = V_447 ;
V_331 -> V_332 . V_408 . V_448 = V_387 -> V_436 ;
break;
default:
F_3 ( V_424 , V_387 -> V_4 ) ;
F_71 ( 1 ) ;
}
F_172 ( V_331 , V_36 , ++ V_424 -> V_2 -> V_333 ,
V_449 , V_435 ) ;
}
static void
F_216 ( struct V_423 * V_424 )
{
struct V_450 * V_340 = (struct V_450 * ) V_424 -> V_451 . V_181 ;
F_3 ( V_424 , V_340 -> V_452 ) ;
F_89 ( V_340 -> V_138 , V_453 , V_454 ,
F_90 ( V_424 -> V_2 ) ) ;
F_139 ( V_424 -> V_2 , & V_424 -> V_451 ) ;
}
static void
F_217 ( struct V_423 * V_424 , enum V_455 V_452 )
{
struct V_450 * V_340 = (struct V_450 * ) V_424 -> V_451 . V_181 ;
F_71 ( V_424 -> V_425 != 0 ) ;
F_3 ( V_424 , V_424 -> V_319 ) ;
V_424 -> V_425 = 1 ;
V_424 -> V_452 = V_452 ;
V_340 -> V_452 = V_452 ;
F_218 ( & V_340 -> V_456 , sizeof( struct V_457 ) , V_424 -> V_458 ) ;
F_216 ( V_424 ) ;
}
static void
F_219 ( struct V_423 * V_424 , struct V_202 * V_181 )
{
struct V_433 * V_387 = (struct V_433 * ) V_181 ;
switch ( V_387 -> V_4 ) {
case V_438 :
V_424 -> V_319 = V_459 ;
V_424 -> V_460 = 0 ;
F_215 ( V_424 , V_387 ) ;
break;
case V_440 :
V_424 -> V_319 = V_461 ;
V_424 -> V_460 = 0 ;
F_215 ( V_424 , V_387 ) ;
break;
case V_442 :
V_424 -> V_319 = V_462 ;
V_424 -> V_460 = 0 ;
F_215 ( V_424 , V_387 ) ;
break;
case V_444 :
V_424 -> V_319 = V_463 ;
F_215 ( V_424 , V_387 ) ;
if ( ! V_424 -> V_425 )
F_217 ( V_424 , V_464 ) ;
break;
case V_446 :
F_215 ( V_424 , V_387 ) ;
break;
case V_465 :
V_424 -> V_319 = V_466 ;
if ( ! V_424 -> V_425 )
F_217 ( V_424 , V_464 ) ;
break;
default:
F_3 ( V_424 , V_387 -> V_4 ) ;
F_71 ( 1 ) ;
}
}
static void
F_220 ( struct V_423 * V_424 , struct V_202 * V_181 )
{
struct V_467 * V_387 = (struct V_467 * ) V_181 ;
if ( ! V_424 -> V_425 ) {
F_3 ( V_424 , V_424 -> V_425 ) ;
return;
}
F_3 ( V_424 , V_387 -> V_339 ) ;
if ( V_387 -> V_339 == V_37 ) {
V_424 -> V_460 = 1 ;
if ( V_424 -> V_319 == V_466 )
V_424 -> V_339 = V_37 ;
else if ( V_424 -> V_319 == V_463 )
V_424 -> V_339 = V_468 ;
else
F_3 ( V_424 , V_424 -> V_319 ) ;
} else {
V_424 -> V_460 = 0 ;
V_424 -> V_339 = V_387 -> V_339 ;
}
F_3 ( V_424 , V_424 -> V_452 ) ;
if ( V_424 -> V_452 == V_469 ) {
F_3 ( V_424 , V_424 -> V_460 ) ;
if ( V_424 -> V_460 ) {
T_1 V_470 = sizeof( struct V_457 ) ;
T_6 * V_471 = ( T_6 * ) & ( V_424 -> V_472 -> V_473 ) ;
memcpy ( V_471 , V_424 -> V_474 , V_470 ) ;
}
F_210 ( V_424 ) ;
} else
V_424 -> V_425 = 0 ;
F_3 ( V_424 , V_424 -> V_431 ) ;
if ( V_424 -> V_431 ) {
V_424 -> V_319 = V_387 -> V_319 ;
F_211 ( V_424 ) ;
}
}
static void
F_221 ( struct V_423 * V_424 )
{
struct V_450 * V_340 = (struct V_450 * ) V_424 -> V_451 . V_181 ;
F_71 ( V_424 -> V_319 != V_475 ) ;
F_71 ( V_424 -> V_431 != 0 ) ;
F_3 ( V_424 , V_424 -> V_319 ) ;
V_424 -> V_431 = 1 ;
V_340 -> V_452 = 0 ;
if ( ! V_424 -> V_425 )
F_217 ( V_424 , V_464 ) ;
}
static void
F_212 ( struct V_423 * V_424 )
{
enum V_476 * V_427 = V_424 -> V_427 ;
* V_427 = V_477 ;
if ( V_424 -> V_319 == V_463 )
* V_427 = V_478 ;
else if ( V_424 -> V_319 == V_466 ) {
union V_479 V_480 ;
struct V_457 * V_472 = (struct V_457 * ) V_424 -> V_474 ;
T_10 V_481 = ( V_472 -> V_473 . V_482 [ 4 ] & 0x3 ) << 7 |
( V_472 -> V_473 . V_482 [ 5 ] >> 1 ) ;
V_480 . V_483 = V_472 -> V_473 . V_482 [ 0 ] ;
F_3 ( V_424 , V_480 . V_483 ) ;
F_3 ( V_424 , V_481 ) ;
if ( ( V_481 & V_484 ) ||
( V_481 & V_485 ) ||
( V_481 & V_486 ) )
* V_427 = V_487 ;
else if ( ( V_481 & V_488 ) ||
( V_481 & V_489 ) )
* V_427 = V_490 ;
else if ( ( V_481 & V_491 ) ||
( V_481 & V_492 ) )
* V_427 = V_493 ;
else if ( ( V_481 & V_494 ) ||
( V_481 & V_495 ) ||
( V_481 & V_496 ) )
* V_427 = V_497 ;
else if ( V_480 . V_498 . V_499 )
* V_427 = V_497 ;
else if ( V_480 . V_498 . V_500 && V_480 . V_498 . V_501 )
* V_427 = V_493 ;
else if ( V_480 . V_498 . V_502 )
* V_427 = V_477 ;
else
F_3 ( V_424 , 0 ) ;
} else
F_3 ( V_424 , V_424 -> V_319 ) ;
}
static T_4
F_213 ( struct V_423 * V_424 , enum V_503 V_426 )
{
struct V_457 * V_472 = (struct V_457 * ) V_424 -> V_474 ;
struct V_504 * V_482 = (struct V_504 * ) V_472 -> V_473 . V_482 ;
union V_505 V_506 = V_482 -> V_506 ;
union V_479 V_480 = V_482 -> V_480 ;
if ( V_426 == V_507 ) {
if ( V_480 . V_498 . V_499 || V_480 . V_498 . V_501 )
return V_37 ;
else {
F_3 ( V_424 , V_480 . V_483 ) ;
return V_508 ;
}
}
if ( ( ( V_426 & V_509 ) && V_506 . V_498 . V_510 ) ||
( ( V_426 & V_511 ) && V_506 . V_498 . V_512 ) ||
( ( V_426 & V_513 ) && V_506 . V_498 . V_514 ) ||
( ( V_426 & V_515 ) && V_506 . V_498 . V_516 ) ||
( ( V_426 & V_517 ) && V_506 . V_498 . V_518 ) )
return V_37 ;
else {
F_3 ( V_424 , V_426 ) ;
F_3 ( V_424 , V_506 . V_483 ) ;
F_3 ( V_424 , V_480 . V_483 ) ;
return V_508 ;
}
}
void
F_222 ( void * V_519 , struct V_202 * V_181 )
{
struct V_423 * V_424 = V_519 ;
switch ( V_181 -> V_138 . V_205 ) {
case V_520 :
F_220 ( V_424 , V_181 ) ;
break;
case V_521 :
F_219 ( V_424 , V_181 ) ;
break;
default:
F_3 ( V_424 , V_181 -> V_138 . V_205 ) ;
F_71 ( 1 ) ;
}
}
T_1
F_223 ( void )
{
return F_197 ( sizeof( struct V_457 ) , V_399 ) ;
}
void
F_224 ( struct V_423 * V_424 , struct V_1 * V_2 , void * V_522 ,
struct V_523 * V_524 )
{
V_424 -> V_522 = V_522 ;
V_424 -> V_2 = V_2 ;
V_424 -> V_524 = V_524 ;
V_424 -> V_18 = NULL ;
V_424 -> V_92 = NULL ;
V_424 -> V_472 = NULL ;
V_424 -> V_425 = 0 ;
V_424 -> V_460 = 0 ;
V_424 -> V_319 = V_475 ;
V_424 -> V_431 = 0 ;
V_424 -> V_428 = NULL ;
V_424 -> V_429 = NULL ;
V_424 -> V_427 = NULL ;
V_424 -> V_426 = V_430 ;
V_424 -> V_525 = V_52 ;
F_138 ( V_424 -> V_2 , V_453 , F_222 , V_424 ) ;
F_200 ( & V_424 -> V_402 ) ;
F_201 ( & V_424 -> V_402 , F_214 , V_424 ) ;
F_140 ( & V_424 -> V_402 . V_91 , & V_424 -> V_2 -> V_220 ) ;
}
void
F_225 ( struct V_423 * V_424 , T_6 * V_247 , T_7 V_248 )
{
V_424 -> V_474 = V_247 ;
V_424 -> V_458 = V_248 ;
memset ( V_424 -> V_474 , 0 , sizeof( struct V_457 ) ) ;
V_247 += F_197 ( sizeof( struct V_457 ) , V_399 ) ;
V_248 += F_197 ( sizeof( struct V_457 ) , V_399 ) ;
}
T_4
F_226 ( struct V_423 * V_424 , struct V_457 * V_472 ,
T_12 V_18 , void * V_92 )
{
if ( ! F_118 ( V_424 -> V_2 ) ) {
F_3 ( V_424 , 0 ) ;
return V_526 ;
}
if ( V_424 -> V_425 ) {
F_3 ( V_424 , 0 ) ;
return V_351 ;
}
V_424 -> V_18 = V_18 ;
V_424 -> V_92 = V_92 ;
V_424 -> V_472 = V_472 ;
F_217 ( V_424 , V_469 ) ;
return V_37 ;
}
T_4
F_227 ( struct V_423 * V_424 , enum V_476 * V_427 ,
T_12 V_18 , void * V_92 )
{
if ( ! F_118 ( V_424 -> V_2 ) ) {
F_3 ( V_424 , 0 ) ;
return V_526 ;
}
V_424 -> V_427 = V_427 ;
if ( V_424 -> V_319 == V_475 ) {
if ( V_424 -> V_431 ) {
F_3 ( V_424 , 0 ) ;
return V_351 ;
} else {
V_424 -> V_428 = V_18 ;
V_424 -> V_429 = V_92 ;
F_221 ( V_424 ) ;
return V_527 ;
}
}
F_212 ( V_424 ) ;
return V_37 ;
}
T_4
F_228 ( struct V_423 * V_424 , enum V_503 V_426 ,
T_12 V_18 , void * V_92 )
{
F_71 ( V_426 == V_430 ) ;
if ( ! F_118 ( V_424 -> V_2 ) )
return V_526 ;
if ( F_158 ( V_424 -> V_2 -> V_164 -> V_166 ) )
return V_37 ;
V_424 -> V_426 = V_426 ;
if ( V_424 -> V_319 == V_475 ) {
if ( V_424 -> V_431 ) {
F_3 ( V_424 , 0 ) ;
return V_351 ;
} else {
V_424 -> V_428 = V_18 ;
V_424 -> V_429 = V_92 ;
F_221 ( V_424 ) ;
return V_527 ;
}
}
if ( V_424 -> V_319 == V_461 ||
V_424 -> V_319 == V_462 ) {
F_3 ( V_424 , V_424 -> V_319 ) ;
return V_528 ;
}
if ( V_424 -> V_319 == V_459 ) {
F_3 ( V_424 , V_424 -> V_319 ) ;
return V_351 ;
}
if ( V_424 -> V_525 )
return V_37 ;
return F_213 ( V_424 , V_426 ) ;
}
static void
F_229 ( struct V_1 * V_2 , enum V_529 V_4 ,
int V_377 , int type )
{
struct V_35 * V_36 = (struct V_35 * ) V_2 -> V_20 -> V_36 ;
struct V_330 * V_331 ;
F_171 ( V_36 , V_331 ) ;
if ( ! V_331 )
return;
V_331 -> V_332 . V_530 . V_276 = V_2 -> V_164 -> V_276 ;
V_331 -> V_332 . V_530 . V_531 = V_377 ;
V_331 -> V_332 . V_530 . V_532 = type ;
F_172 ( V_331 , V_36 , ++ V_2 -> V_333 ,
V_533 , V_4 ) ;
}
static void
F_230 ( struct V_534 * V_535 )
{
V_535 -> V_536 = 0 ;
if ( V_535 -> V_18 )
V_535 -> V_18 ( V_535 -> V_92 , V_535 -> V_339 ) ;
}
static void
F_231 ( void * V_92 , enum V_87 V_4 )
{
struct V_534 * V_535 = V_92 ;
F_3 ( V_535 , V_4 ) ;
switch ( V_4 ) {
case V_93 :
case V_189 :
if ( V_535 -> V_536 ) {
V_535 -> V_339 = V_21 ;
V_535 -> V_18 ( V_535 -> V_92 , V_535 -> V_339 ) ;
V_535 -> V_536 = 0 ;
}
break;
default:
break;
}
}
static void
F_232 ( void * V_92 )
{
struct V_534 * V_535 = V_92 ;
struct V_537 * V_181 =
(struct V_537 * ) V_535 -> V_405 . V_181 ;
F_89 ( V_181 -> V_138 , V_538 , V_539 ,
F_90 ( V_535 -> V_2 ) ) ;
F_218 ( & V_181 -> V_456 , sizeof( struct V_540 ) ,
V_535 -> V_458 ) ;
F_139 ( V_535 -> V_2 , & V_535 -> V_405 ) ;
}
static void
F_233 ( struct V_534 * V_535 )
{
struct V_541 * V_181 =
(struct V_541 * ) V_535 -> V_405 . V_181 ;
T_1 V_129 ;
V_181 -> type = F_93 ( V_535 -> type ) ;
V_181 -> V_542 = V_535 -> V_542 ;
V_181 -> V_343 = F_93 ( V_535 -> V_543 + V_535 -> V_343 ) ;
V_129 = ( V_535 -> V_544 < V_545 ) ?
V_535 -> V_544 : V_545 ;
V_181 -> V_546 = F_93 ( V_129 ) ;
V_181 -> V_547 = ( V_129 == V_535 -> V_544 ) ? 1 : 0 ;
F_89 ( V_181 -> V_138 , V_538 , V_548 ,
F_90 ( V_535 -> V_2 ) ) ;
F_218 ( & V_181 -> V_456 , V_129 , V_535 -> V_458 ) ;
memcpy ( V_535 -> V_474 , V_535 -> V_549 + V_535 -> V_343 , V_129 ) ;
F_139 ( V_535 -> V_2 , & V_535 -> V_405 ) ;
V_535 -> V_544 -= V_129 ;
V_535 -> V_343 += V_129 ;
}
static void
F_234 ( void * V_92 )
{
struct V_534 * V_535 = V_92 ;
struct V_550 * V_181 =
(struct V_550 * ) V_535 -> V_405 . V_181 ;
T_1 V_129 ;
V_181 -> type = F_93 ( V_535 -> type ) ;
V_181 -> V_542 = V_535 -> V_542 ;
V_181 -> V_343 = F_93 ( V_535 -> V_543 + V_535 -> V_343 ) ;
V_129 = ( V_535 -> V_544 < V_545 ) ?
V_535 -> V_544 : V_545 ;
V_181 -> V_546 = F_93 ( V_129 ) ;
F_89 ( V_181 -> V_138 , V_538 , V_551 ,
F_90 ( V_535 -> V_2 ) ) ;
F_218 ( & V_181 -> V_456 , V_129 , V_535 -> V_458 ) ;
F_139 ( V_535 -> V_2 , & V_535 -> V_405 ) ;
}
static void
F_235 ( void * V_92 )
{
struct V_534 * V_535 = V_92 ;
struct V_552 * V_181 =
(struct V_552 * ) V_535 -> V_405 . V_181 ;
V_181 -> type = F_93 ( V_535 -> type ) ;
V_181 -> V_542 = V_535 -> V_542 ;
F_89 ( V_181 -> V_138 , V_538 , V_553 ,
F_90 ( V_535 -> V_2 ) ) ;
F_139 ( V_535 -> V_2 , & V_535 -> V_405 ) ;
}
static void
F_236 ( void * V_554 , struct V_202 * V_181 )
{
struct V_534 * V_535 = V_554 ;
T_1 V_339 ;
union {
struct V_555 * V_556 ;
struct V_557 * V_558 ;
struct V_559 * V_560 ;
struct V_561 * V_562 ;
struct V_563 * V_4 ;
struct V_202 * V_181 ;
} V_203 ;
V_203 . V_181 = V_181 ;
F_3 ( V_535 , V_181 -> V_138 . V_205 ) ;
if ( ! V_535 -> V_536 && V_181 -> V_138 . V_205 != V_564 ) {
F_3 ( V_535 , 0x9999 ) ;
return;
}
switch ( V_181 -> V_138 . V_205 ) {
case V_565 :
V_339 = F_93 ( V_203 . V_556 -> V_339 ) ;
F_3 ( V_535 , V_339 ) ;
if ( V_339 == V_37 ) {
T_1 V_98 ;
struct V_540 * V_164 , * V_566 ;
V_164 = (struct V_540 * ) V_535 -> V_549 ;
V_566 = (struct V_540 * ) V_535 -> V_474 ;
V_164 -> V_339 = F_93 ( V_566 -> V_339 ) ;
V_164 -> V_567 = F_93 ( V_566 -> V_567 ) ;
F_3 ( V_535 , V_164 -> V_339 ) ;
F_3 ( V_535 , V_164 -> V_567 ) ;
for ( V_98 = 0 ; V_98 < V_164 -> V_567 ; V_98 ++ ) {
V_164 -> V_568 [ V_98 ] . V_569 =
F_93 ( V_566 -> V_568 [ V_98 ] . V_569 ) ;
V_164 -> V_568 [ V_98 ] . V_570 =
F_93 ( V_566 -> V_568 [ V_98 ] . V_570 ) ;
V_164 -> V_568 [ V_98 ] . V_571 =
F_93 ( V_566 -> V_568 [ V_98 ] . V_571 ) ;
V_164 -> V_568 [ V_98 ] . V_572 =
F_93 ( V_566 -> V_568 [ V_98 ] . V_572 ) ;
V_164 -> V_568 [ V_98 ] . V_573 =
F_93 ( V_566 -> V_568 [ V_98 ] . V_573 ) ;
V_164 -> V_568 [ V_98 ] . V_574 =
F_93 ( V_566 -> V_568 [ V_98 ] . V_574 ) ;
}
}
V_535 -> V_339 = V_339 ;
F_230 ( V_535 ) ;
break;
case V_575 :
V_339 = F_93 ( V_203 . V_558 -> V_339 ) ;
F_3 ( V_535 , V_339 ) ;
V_535 -> V_339 = V_339 ;
F_230 ( V_535 ) ;
break;
case V_576 :
V_339 = F_93 ( V_203 . V_560 -> V_339 ) ;
F_3 ( V_535 , V_339 ) ;
if ( V_339 != V_37 || V_535 -> V_544 == 0 ) {
V_535 -> V_339 = V_339 ;
F_230 ( V_535 ) ;
} else {
F_3 ( V_535 , V_535 -> V_343 ) ;
F_233 ( V_535 ) ;
}
break;
case V_577 :
V_339 = F_93 ( V_203 . V_562 -> V_339 ) ;
F_3 ( V_535 , V_339 ) ;
if ( V_339 != V_37 ) {
V_535 -> V_339 = V_339 ;
F_230 ( V_535 ) ;
} else {
T_1 V_129 = F_93 ( V_203 . V_562 -> V_546 ) ;
F_3 ( V_535 , V_535 -> V_343 ) ;
F_3 ( V_535 , V_129 ) ;
memcpy ( V_535 -> V_549 + V_535 -> V_343 ,
V_535 -> V_474 , V_129 ) ;
V_535 -> V_544 -= V_129 ;
V_535 -> V_343 += V_129 ;
if ( V_535 -> V_544 == 0 ) {
V_535 -> V_339 = V_339 ;
F_230 ( V_535 ) ;
} else
F_234 ( V_535 ) ;
}
break;
case V_578 :
break;
case V_564 :
V_339 = F_93 ( V_203 . V_4 -> V_339 ) ;
F_3 ( V_535 , V_339 ) ;
if ( V_339 == V_579 )
F_21 ( V_535 -> V_2 , V_580 ) ;
else if ( V_339 == V_581 ) {
T_1 V_582 ;
V_582 = F_93 ( V_203 . V_4 -> V_582 ) ;
F_3 ( V_535 , V_582 ) ;
F_21 ( V_535 -> V_2 ,
V_583 ) ;
}
break;
default:
F_71 ( 1 ) ;
}
}
T_1
F_237 ( T_2 V_584 )
{
if ( V_584 )
return 0 ;
return F_197 ( V_545 , V_399 ) ;
}
void
F_238 ( struct V_534 * V_535 , struct V_1 * V_2 , void * V_522 ,
struct V_523 * V_524 , T_2 V_584 )
{
V_535 -> V_2 = V_2 ;
V_535 -> V_524 = V_524 ;
V_535 -> V_18 = NULL ;
V_535 -> V_92 = NULL ;
V_535 -> V_536 = 0 ;
F_138 ( V_535 -> V_2 , V_538 , F_236 , V_535 ) ;
F_200 ( & V_535 -> V_402 ) ;
F_201 ( & V_535 -> V_402 , F_231 , V_535 ) ;
F_140 ( & V_535 -> V_402 . V_91 , & V_535 -> V_2 -> V_220 ) ;
if ( V_584 ) {
V_535 -> V_474 = NULL ;
V_535 -> V_458 = 0 ;
}
}
void
F_239 ( struct V_534 * V_535 , T_6 * V_247 , T_7 V_248 ,
T_2 V_584 )
{
if ( V_584 )
return;
V_535 -> V_474 = V_247 ;
V_535 -> V_458 = V_248 ;
memset ( V_535 -> V_474 , 0 , V_545 ) ;
V_247 += F_197 ( V_545 , V_399 ) ;
V_248 += F_197 ( V_545 , V_399 ) ;
}
T_4
F_240 ( struct V_534 * V_535 , struct V_540 * V_164 ,
T_13 V_18 , void * V_92 )
{
F_3 ( V_535 , V_539 ) ;
if ( ! F_118 ( V_535 -> V_2 ) )
return V_526 ;
if ( V_535 -> V_536 ) {
F_3 ( V_535 , V_535 -> V_536 ) ;
return V_351 ;
}
V_535 -> V_536 = 1 ;
V_535 -> V_18 = V_18 ;
V_535 -> V_92 = V_92 ;
V_535 -> V_549 = ( T_6 * ) V_164 ;
F_232 ( V_535 ) ;
return V_37 ;
}
T_4
F_241 ( struct V_534 * V_535 , enum V_585 type ,
T_6 V_542 , T_13 V_18 , void * V_92 )
{
F_3 ( V_535 , V_553 ) ;
F_3 ( V_535 , type ) ;
F_3 ( V_535 , V_542 ) ;
if ( ! F_118 ( V_535 -> V_2 ) )
return V_526 ;
if ( V_535 -> V_536 ) {
F_3 ( V_535 , V_535 -> V_536 ) ;
return V_351 ;
}
V_535 -> V_536 = 1 ;
V_535 -> V_18 = V_18 ;
V_535 -> V_92 = V_92 ;
V_535 -> type = type ;
V_535 -> V_542 = V_542 ;
F_235 ( V_535 ) ;
F_229 ( V_535 -> V_2 , V_586 ,
V_542 , type ) ;
return V_37 ;
}
T_4
F_242 ( struct V_534 * V_535 , enum V_585 type ,
T_6 V_542 , void * V_185 , T_1 V_129 , T_1 V_343 ,
T_13 V_18 , void * V_92 )
{
F_3 ( V_535 , V_548 ) ;
F_3 ( V_535 , type ) ;
F_3 ( V_535 , V_542 ) ;
F_3 ( V_535 , V_129 ) ;
F_3 ( V_535 , V_343 ) ;
if ( ! F_118 ( V_535 -> V_2 ) )
return V_526 ;
if ( ! V_129 || ( V_129 & 0x03 ) || ( V_343 & 0x00003FFF ) )
return V_587 ;
if ( type == V_588 )
return V_347 ;
if ( V_535 -> V_536 ) {
F_3 ( V_535 , V_535 -> V_536 ) ;
return V_351 ;
}
V_535 -> V_536 = 1 ;
V_535 -> V_18 = V_18 ;
V_535 -> V_92 = V_92 ;
V_535 -> type = type ;
V_535 -> V_542 = V_542 ;
V_535 -> V_544 = V_129 ;
V_535 -> V_343 = 0 ;
V_535 -> V_543 = V_343 ;
V_535 -> V_549 = V_185 ;
F_233 ( V_535 ) ;
return V_37 ;
}
T_4
F_243 ( struct V_534 * V_535 , enum V_585 type ,
T_6 V_542 , void * V_185 , T_1 V_129 , T_1 V_343 ,
T_13 V_18 , void * V_92 )
{
F_3 ( V_535 , V_551 ) ;
F_3 ( V_535 , type ) ;
F_3 ( V_535 , V_542 ) ;
F_3 ( V_535 , V_129 ) ;
F_3 ( V_535 , V_343 ) ;
if ( ! F_118 ( V_535 -> V_2 ) )
return V_526 ;
if ( ! V_129 || ( V_129 & 0x03 ) || ( V_343 & 0x00003FFF ) )
return V_587 ;
if ( V_535 -> V_536 ) {
F_3 ( V_535 , V_535 -> V_536 ) ;
return V_351 ;
}
V_535 -> V_536 = 1 ;
V_535 -> V_18 = V_18 ;
V_535 -> V_92 = V_92 ;
V_535 -> type = type ;
V_535 -> V_542 = V_542 ;
V_535 -> V_544 = V_129 ;
V_535 -> V_343 = 0 ;
V_535 -> V_543 = V_343 ;
V_535 -> V_549 = V_185 ;
F_234 ( V_535 ) ;
return V_37 ;
}
static void
F_244 ( void * V_589 , enum V_87 V_4 )
{
struct V_590 * V_591 = V_589 ;
F_3 ( V_591 , V_4 ) ;
F_3 ( V_591 , V_591 -> V_592 ) ;
F_3 ( V_591 , V_591 -> V_593 . V_425 ) ;
F_3 ( V_591 , V_591 -> V_594 . V_425 ) ;
switch ( V_4 ) {
case V_93 :
case V_189 :
if ( V_591 -> V_593 . V_425 ) {
V_591 -> V_593 . V_339 = V_21 ;
V_591 -> V_593 . V_18 ( V_591 -> V_593 . V_92 ,
V_591 -> V_593 . V_339 ) ;
V_591 -> V_593 . V_425 = 0 ;
}
if ( V_591 -> V_594 . V_425 ) {
V_591 -> V_594 . V_339 = V_21 ;
V_591 -> V_594 . V_18 ( V_591 -> V_594 . V_92 ,
V_591 -> V_594 . V_339 ) ;
V_591 -> V_594 . V_425 = 0 ;
}
if ( V_591 -> V_592 ) {
if ( V_591 -> V_595 ) {
F_192 ( & V_591 -> V_368 ) ;
V_591 -> V_595 = 0 ;
}
V_591 -> V_339 = V_21 ;
V_591 -> V_18 ( V_591 -> V_92 , V_591 -> V_339 ) ;
V_591 -> V_592 = 0 ;
}
break;
default:
break;
}
}
static void
F_245 ( void * V_92 )
{
struct V_590 * V_591 = V_92 ;
struct V_1 * V_2 = V_591 -> V_2 ;
struct V_596 * V_597 = V_591 -> V_598 ;
T_1 V_107 = V_599 ;
T_1 V_105 , V_106 , V_98 ;
V_105 = F_76 ( V_2 -> V_59 . V_109 , V_107 ) ;
V_106 = F_77 ( V_107 ) ;
F_33 ( V_105 , V_2 -> V_59 . V_110 ) ;
for ( V_98 = 0 ; V_98 < ( sizeof( struct V_596 ) /
sizeof( T_1 ) ) ; V_98 ++ ) {
* ( ( T_1 * ) V_597 + V_98 ) =
F_78 ( V_2 -> V_59 . V_111 , V_107 ) ;
V_107 += sizeof( T_1 ) ;
}
F_149 ( V_2 ) ;
V_597 -> V_339 = F_32 ( V_597 -> V_339 ) ;
F_3 ( V_591 , V_597 -> V_339 ) ;
if ( V_597 -> V_339 == V_600 )
V_591 -> V_339 = V_37 ;
else {
V_591 -> V_339 = V_601 ;
V_597 -> V_407 = F_32 ( V_597 -> V_407 ) ;
V_597 -> exp = F_32 ( V_597 -> exp ) ;
V_597 -> V_602 = F_32 ( V_597 -> V_602 ) ;
V_597 -> V_603 = F_32 ( V_597 -> V_603 ) ;
V_597 -> V_604 = F_32 ( V_597 -> V_604 ) ;
V_597 -> V_605 = F_32 ( V_597 -> V_605 ) ;
F_3 ( V_591 , V_597 -> V_407 ) ;
F_3 ( V_591 , V_597 -> exp ) ;
F_3 ( V_591 , V_597 -> V_602 ) ;
F_3 ( V_591 , V_597 -> V_603 ) ;
F_3 ( V_591 , V_597 -> V_604 ) ;
F_3 ( V_591 , V_597 -> V_605 ) ;
}
V_591 -> V_595 = 0 ;
V_591 -> V_18 ( V_591 -> V_92 , V_591 -> V_339 ) ;
V_591 -> V_592 = 0 ;
}
static void
F_246 ( struct V_590 * V_591 )
{
struct V_606 * V_607 ;
T_1 V_98 ;
F_3 ( V_591 , V_591 -> V_593 . V_458 ) ;
for ( V_98 = 0 ; V_98 < ( V_608 >> 2 ) ; V_98 ++ )
* ( ( T_1 * ) V_591 -> V_593 . V_474 + V_98 ) = V_591 -> V_593 . V_609 ;
V_607 = (struct V_606 * ) V_591 -> V_593 . V_451 . V_181 ;
F_218 ( & V_607 -> V_456 , V_608 ,
V_591 -> V_593 . V_458 ) ;
V_607 -> V_610 = F_122 ( V_591 -> V_593 . V_610 ) ;
V_607 -> V_609 = V_591 -> V_593 . V_609 ;
F_89 ( V_607 -> V_138 , V_611 , V_612 ,
F_90 ( V_591 -> V_2 ) ) ;
F_139 ( V_591 -> V_2 , & V_591 -> V_593 . V_451 ) ;
}
static void
F_247 ( struct V_590 * V_591 ,
struct V_613 * V_614 )
{
T_1 V_615 = V_614 -> V_609 ;
T_6 V_616 = V_614 -> V_617 ;
F_3 ( V_591 , V_615 ) ;
F_3 ( V_591 , V_616 ) ;
if ( V_616 == V_37 ) {
T_1 V_98 , V_618 ;
V_618 = ( V_591 -> V_593 . V_610 & 0x1 ) ? ~ ( V_591 -> V_593 . V_609 ) :
V_591 -> V_593 . V_609 ;
if ( V_591 -> V_593 . V_609 != V_615 ) {
F_3 ( V_591 , V_615 ) ;
V_591 -> V_593 . V_598 -> V_619 =
V_620 ;
V_591 -> V_593 . V_339 = V_620 ;
V_591 -> V_593 . V_18 ( V_591 -> V_593 . V_92 ,
V_591 -> V_593 . V_339 ) ;
V_591 -> V_593 . V_425 = 0 ;
return;
}
for ( V_98 = 0 ; V_98 < ( V_608 >> 2 ) ; V_98 ++ ) {
if ( * ( ( T_1 * ) V_591 -> V_593 . V_474 + V_98 ) != V_618 ) {
F_3 ( V_591 , V_98 ) ;
F_3 ( V_591 , V_618 ) ;
F_3 ( V_591 ,
* ( ( T_1 * ) V_591 -> V_593 . V_474 + V_98 ) ) ;
V_591 -> V_593 . V_598 -> V_619 =
V_620 ;
V_591 -> V_593 . V_339 = V_620 ;
V_591 -> V_593 . V_18 ( V_591 -> V_593 . V_92 ,
V_591 -> V_593 . V_339 ) ;
V_591 -> V_593 . V_425 = 0 ;
return;
}
}
V_591 -> V_593 . V_598 -> V_619 = V_37 ;
V_591 -> V_593 . V_339 = V_37 ;
V_591 -> V_593 . V_18 ( V_591 -> V_593 . V_92 , V_591 -> V_593 . V_339 ) ;
V_591 -> V_593 . V_425 = 0 ;
} else {
V_591 -> V_593 . V_339 = V_621 ;
V_591 -> V_593 . V_18 ( V_591 -> V_593 . V_92 , V_591 -> V_593 . V_339 ) ;
V_591 -> V_593 . V_425 = 0 ;
}
}
static void
F_248 ( struct V_590 * V_591 )
{
struct V_622 * V_181 ;
V_181 = (struct V_622 * ) V_591 -> V_594 . V_451 . V_181 ;
F_3 ( V_591 , V_181 -> V_623 ) ;
F_89 ( V_181 -> V_138 , V_611 , V_624 ,
F_90 ( V_591 -> V_2 ) ) ;
F_139 ( V_591 -> V_2 , & V_591 -> V_594 . V_451 ) ;
}
static void
F_249 ( struct V_590 * V_591 , T_14 * V_387 )
{
if ( ! V_591 -> V_594 . V_425 ) {
F_3 ( V_591 , V_591 -> V_594 . V_425 ) ;
return;
}
V_591 -> V_594 . V_623 -> V_623 = F_107 ( V_387 -> V_623 ) ;
V_591 -> V_594 . V_623 -> V_625 = V_387 -> V_625 ;
V_591 -> V_594 . V_623 -> V_626 = V_387 -> V_626 ;
V_591 -> V_594 . V_623 -> V_339 = V_37 ;
if ( V_387 -> V_626 ) {
if ( V_387 -> V_339 == V_37 ) {
V_591 -> V_594 . V_623 -> V_627 =
F_107 ( V_387 -> V_627 ) ;
} else {
F_3 ( V_591 , V_387 -> V_339 ) ;
V_591 -> V_594 . V_623 -> V_627 = 0 ;
V_591 -> V_594 . V_623 -> V_339 = V_351 ;
}
}
F_3 ( V_591 , V_387 -> V_625 ) ;
F_3 ( V_591 , V_387 -> V_623 ) ;
F_3 ( V_591 , V_387 -> V_626 ) ;
F_3 ( V_591 , V_387 -> V_627 ) ;
V_591 -> V_594 . V_18 ( V_591 -> V_594 . V_92 , V_591 -> V_594 . V_339 ) ;
V_591 -> V_594 . V_425 = 0 ;
}
static void
F_250 ( struct V_590 * V_591 , struct V_628 * V_629 )
{
struct V_630 * V_181 ;
V_181 = (struct V_630 * ) V_591 -> V_629 . V_451 . V_181 ;
F_89 ( V_181 -> V_138 , V_611 , V_631 ,
F_90 ( V_591 -> V_2 ) ) ;
if ( V_629 -> V_632 )
V_629 -> V_632 = 500 / V_629 -> V_632 ;
if ( V_629 -> V_632 == 0 )
V_629 -> V_632 = 1 ;
F_3 ( V_591 , V_629 -> V_632 ) ;
V_181 -> V_179 = ( T_6 ) V_629 -> V_179 ;
V_181 -> V_633 = ( T_6 ) V_629 -> V_633 ;
V_181 -> V_634 = F_90 ( V_591 -> V_2 ) ;
V_181 -> V_635 = V_629 -> V_635 ;
V_181 -> V_632 = F_91 ( V_629 -> V_632 ) ;
F_139 ( V_591 -> V_2 , & V_591 -> V_629 . V_451 ) ;
}
static void
F_251 ( struct V_590 * V_591 , struct V_636 * V_181 )
{
F_3 ( V_591 , V_591 -> V_629 . V_425 ) ;
V_591 -> V_629 . V_425 = V_52 ;
}
static void
F_252 ( struct V_590 * V_591 , T_2 V_637 , T_1 V_638 )
{
struct V_639 * V_181 ;
V_181 = (struct V_639 * ) V_591 -> V_637 . V_451 . V_181 ;
F_89 ( V_181 -> V_138 , V_611 , V_640 ,
F_90 ( V_591 -> V_2 ) ) ;
V_181 -> V_637 = V_637 ;
V_181 -> V_641 = F_122 ( V_638 ) ;
F_139 ( V_591 -> V_2 , & V_591 -> V_637 . V_451 ) ;
}
static void
F_253 ( struct V_590 * V_591 )
{
F_3 ( V_591 , V_591 -> V_637 . V_319 ) ;
V_591 -> V_637 . V_319 = V_52 ;
if ( V_591 -> V_642 )
V_591 -> V_642 ( V_591 -> V_522 , V_52 , V_591 -> V_637 . V_643 ) ;
}
void
F_254 ( void * V_644 , struct V_202 * V_181 )
{
struct V_590 * V_591 = V_644 ;
switch ( V_181 -> V_138 . V_205 ) {
case V_645 :
F_253 ( V_591 ) ;
break;
case V_646 :
F_247 ( V_591 , (struct V_613 * ) V_181 ) ;
break;
case V_647 :
F_249 ( V_591 , ( T_14 * ) V_181 ) ;
break;
case V_648 :
F_251 ( V_591 , (struct V_636 * ) V_181 ) ;
break;
default:
F_3 ( V_591 , V_181 -> V_138 . V_205 ) ;
F_71 ( 1 ) ;
}
}
T_4
F_255 ( struct V_590 * V_591 , struct V_649 * V_650 ,
T_1 V_651 , struct V_596 * V_598 ,
T_15 V_18 , void * V_92 )
{
F_3 ( V_591 , V_651 ) ;
if ( ! F_147 ( V_591 -> V_2 ) )
return V_652 ;
if ( V_591 -> V_592 ) {
F_3 ( V_591 , V_591 -> V_592 ) ;
return V_351 ;
} else
V_591 -> V_592 = 1 ;
V_591 -> V_598 = V_598 ;
V_591 -> V_18 = V_18 ;
V_591 -> V_92 = V_92 ;
F_84 ( V_591 -> V_2 , V_196 , V_123 ) ;
F_190 ( V_591 -> V_2 -> V_218 , & V_591 -> V_368 ,
F_245 , V_591 , V_653 ) ;
V_591 -> V_595 = 1 ;
return V_37 ;
}
T_4
F_256 ( struct V_590 * V_591 , T_1 V_96 , T_1 V_609 ,
struct V_654 * V_598 , T_15 V_18 ,
void * V_92 )
{
F_3 ( V_591 , V_96 ) ;
F_3 ( V_591 , V_609 ) ;
if ( ! F_118 ( V_591 -> V_2 ) )
return V_526 ;
if ( F_257 ( F_258 ( ( V_591 -> V_2 ) ) ) &&
( ( V_591 -> V_2 ) -> V_141 == V_286 ) )
return V_655 ;
if ( V_591 -> V_592 || V_591 -> V_593 . V_425 ) {
F_3 ( V_591 , V_591 -> V_592 ) ;
F_3 ( V_591 , V_591 -> V_593 . V_425 ) ;
return V_351 ;
}
V_591 -> V_593 . V_425 = 1 ;
V_591 -> V_593 . V_18 = V_18 ;
V_591 -> V_593 . V_92 = V_92 ;
V_591 -> V_593 . V_598 = V_598 ;
V_591 -> V_593 . V_609 = V_609 ;
V_591 -> V_593 . V_610 = V_96 ;
V_591 -> V_593 . V_598 -> V_609 = 0 ;
V_591 -> V_593 . V_598 -> V_339 = V_37 ;
F_246 ( V_591 ) ;
return V_37 ;
}
T_4
F_259 ( struct V_590 * V_591 ,
struct V_656 * V_598 ,
T_15 V_18 , void * V_92 )
{
if ( V_591 -> V_592 || V_591 -> V_594 . V_425 ) {
F_3 ( V_591 , V_591 -> V_592 ) ;
F_3 ( V_591 , V_591 -> V_594 . V_425 ) ;
return V_351 ;
}
if ( ! F_118 ( V_591 -> V_2 ) )
return V_526 ;
V_591 -> V_594 . V_425 = 1 ;
V_591 -> V_594 . V_623 = V_598 ;
V_591 -> V_594 . V_18 = V_18 ;
V_591 -> V_594 . V_92 = V_92 ;
F_248 ( V_591 ) ;
return V_37 ;
}
T_4
F_260 ( struct V_590 * V_591 , struct V_628 * V_629 )
{
F_3 ( V_591 , V_629 -> V_179 ) ;
if ( ! F_118 ( V_591 -> V_2 ) )
return V_526 ;
if ( V_591 -> V_637 . V_319 )
return V_657 ;
if ( V_591 -> V_629 . V_425 )
return V_658 ;
V_591 -> V_629 . V_425 = V_71 ;
F_250 ( V_591 , V_629 ) ;
return V_37 ;
}
T_4
F_261 ( struct V_590 * V_591 , T_2 V_637 ,
T_2 V_659 , T_16 V_638 )
{
F_3 ( V_591 , V_637 ) ;
F_3 ( V_591 , V_659 ) ;
F_3 ( V_591 , V_638 ) ;
if ( ! F_118 ( V_591 -> V_2 ) )
return V_526 ;
if ( V_591 -> V_629 . V_425 )
return V_658 ;
if ( V_591 -> V_637 . V_319 && V_637 )
return V_657 ;
V_591 -> V_637 . V_319 = V_637 ;
V_591 -> V_637 . V_643 = V_659 ;
if ( V_591 -> V_642 )
V_591 -> V_642 ( V_591 -> V_522 , V_637 , V_659 ) ;
F_252 ( V_591 , V_637 , V_638 ) ;
return V_37 ;
}
T_1
F_262 ( void )
{
return F_197 ( V_608 , V_399 ) ;
}
void
F_263 ( struct V_590 * V_591 , struct V_1 * V_2 , void * V_522 ,
T_17 V_642 , struct V_523 * V_524 )
{
V_591 -> V_522 = V_522 ;
V_591 -> V_2 = V_2 ;
V_591 -> V_524 = V_524 ;
V_591 -> V_592 = 0 ;
V_591 -> V_18 = NULL ;
V_591 -> V_92 = NULL ;
V_591 -> V_598 = NULL ;
V_591 -> V_642 = V_642 ;
F_138 ( V_591 -> V_2 , V_611 , F_254 , V_591 ) ;
F_200 ( & V_591 -> V_402 ) ;
F_201 ( & V_591 -> V_402 , F_244 , V_591 ) ;
F_140 ( & V_591 -> V_402 . V_91 , & V_591 -> V_2 -> V_220 ) ;
}
void
F_264 ( struct V_590 * V_591 , T_6 * V_247 , T_7 V_248 )
{
V_591 -> V_593 . V_474 = V_247 ;
V_591 -> V_593 . V_458 = V_248 ;
memset ( V_591 -> V_593 . V_474 , 0 , V_608 ) ;
}
static void
F_265 ( T_1 * V_660 , T_1 * V_661 , int V_184 )
{
int V_98 , V_203 = V_184 >> 2 ;
for ( V_98 = 0 ; V_98 < V_203 ; V_98 ++ )
V_660 [ V_98 ] = F_93 ( V_661 [ V_98 ] ) ;
}
static T_2
F_266 ( struct V_662 * V_663 )
{
return ( V_663 -> V_2 -> V_164 -> V_166 == V_664 ) ;
}
static void
F_267 ( void * V_92 , enum V_87 V_4 )
{
struct V_662 * V_663 = V_92 ;
F_3 ( V_663 , V_4 ) ;
switch ( V_4 ) {
case V_93 :
case V_189 :
if ( V_663 -> V_536 ) {
V_663 -> V_339 = V_21 ;
V_663 -> V_18 ( V_663 -> V_92 , V_663 -> V_339 ) ;
V_663 -> V_536 = 0 ;
}
break;
default:
break;
}
}
static void
F_268 ( void * V_92 )
{
struct V_662 * V_663 = V_92 ;
struct V_665 * V_181 =
(struct V_665 * ) V_663 -> V_405 . V_181 ;
V_181 -> V_542 = V_663 -> V_542 ;
F_89 ( V_181 -> V_138 , V_666 , V_667 ,
F_90 ( V_663 -> V_2 ) ) ;
F_218 ( & V_181 -> V_456 , sizeof( struct V_668 ) , V_663 -> V_458 ) ;
F_139 ( V_663 -> V_2 , & V_663 -> V_405 ) ;
}
static void
F_269 ( void * V_92 )
{
struct V_662 * V_663 = V_92 ;
struct V_669 * V_181 =
(struct V_669 * ) V_663 -> V_405 . V_181 ;
T_1 V_129 ;
T_10 * V_185 , * V_670 ;
int V_98 , V_184 ;
V_181 -> V_542 = V_663 -> V_542 ;
V_181 -> V_343 = F_122 ( V_663 -> V_543 + V_663 -> V_343 ) ;
V_129 = ( V_663 -> V_544 < V_671 ) ?
V_663 -> V_544 : V_671 ;
V_181 -> V_546 = F_122 ( V_129 ) ;
V_181 -> V_547 = ( V_129 == V_663 -> V_544 ) ? 1 : 0 ;
F_89 ( V_181 -> V_138 , V_666 , V_672 ,
F_90 ( V_663 -> V_2 ) ) ;
F_218 ( & V_181 -> V_456 , V_129 , V_663 -> V_458 ) ;
V_185 = ( T_10 * ) ( V_663 -> V_549 + V_663 -> V_343 ) ;
V_670 = ( T_10 * ) V_663 -> V_474 ;
V_184 = V_129 >> 1 ;
for ( V_98 = 0 ; V_98 < V_184 ; V_98 ++ )
V_185 [ V_98 ] = F_91 ( V_670 [ V_98 ] ) ;
F_139 ( V_663 -> V_2 , & V_663 -> V_405 ) ;
V_663 -> V_544 -= V_129 ;
V_663 -> V_343 += V_129 ;
}
static void
F_270 ( void * V_92 )
{
struct V_662 * V_663 = V_92 ;
struct V_673 * V_181 =
(struct V_673 * ) V_663 -> V_405 . V_181 ;
T_1 V_129 ;
V_181 -> V_542 = V_663 -> V_542 ;
V_181 -> V_343 = F_122 ( V_663 -> V_543 + V_663 -> V_343 ) ;
V_129 = ( V_663 -> V_544 < V_671 ) ?
V_663 -> V_544 : V_671 ;
V_181 -> V_546 = F_122 ( V_129 ) ;
F_89 ( V_181 -> V_138 , V_666 , V_674 ,
F_90 ( V_663 -> V_2 ) ) ;
F_218 ( & V_181 -> V_456 , V_129 , V_663 -> V_458 ) ;
F_139 ( V_663 -> V_2 , & V_663 -> V_405 ) ;
}
static void
F_271 ( void * V_92 )
{
struct V_662 * V_663 = V_92 ;
struct V_675 * V_181 =
(struct V_675 * ) V_663 -> V_405 . V_181 ;
V_181 -> V_542 = V_663 -> V_542 ;
F_89 ( V_181 -> V_138 , V_666 , V_676 ,
F_90 ( V_663 -> V_2 ) ) ;
F_218 ( & V_181 -> V_456 , sizeof( struct V_677 ) , V_663 -> V_458 ) ;
F_139 ( V_663 -> V_2 , & V_663 -> V_405 ) ;
}
T_1
F_272 ( T_2 V_584 )
{
if ( V_584 )
return 0 ;
return F_197 ( V_671 , V_399 ) ;
}
void
F_273 ( struct V_662 * V_663 , struct V_1 * V_2 , void * V_522 ,
struct V_523 * V_524 , T_2 V_584 )
{
V_663 -> V_2 = V_2 ;
V_663 -> V_524 = V_524 ;
V_663 -> V_18 = NULL ;
V_663 -> V_92 = NULL ;
V_663 -> V_536 = 0 ;
F_138 ( V_663 -> V_2 , V_666 , V_678 , V_663 ) ;
F_200 ( & V_663 -> V_402 ) ;
F_201 ( & V_663 -> V_402 , F_267 , V_663 ) ;
F_140 ( & V_663 -> V_402 . V_91 , & V_663 -> V_2 -> V_220 ) ;
if ( V_584 ) {
V_663 -> V_474 = NULL ;
V_663 -> V_458 = 0 ;
}
}
void
F_274 ( struct V_662 * V_663 , T_6 * V_247 , T_7 V_248 ,
T_2 V_584 )
{
if ( V_584 )
return;
V_663 -> V_474 = V_247 ;
V_663 -> V_458 = V_248 ;
memset ( V_663 -> V_474 , 0 , V_671 ) ;
V_247 += F_197 ( V_671 , V_399 ) ;
V_248 += F_197 ( V_671 , V_399 ) ;
}
T_2
F_275 ( struct V_1 * V_2 )
{
void T_3 * V_679 ;
V_679 = F_276 ( V_2 ) ;
return F_30 ( V_679 + V_680 ) ;
}
T_4
F_277 ( struct V_662 * V_663 , T_6 V_542 ,
struct V_668 * V_164 , T_18 V_18 , void * V_92 )
{
F_3 ( V_663 , V_667 ) ;
F_3 ( V_663 , V_542 ) ;
if ( ! F_266 ( V_663 ) )
return V_681 ;
if ( ! F_118 ( V_663 -> V_2 ) )
return V_526 ;
if ( V_663 -> V_536 || F_275 ( V_663 -> V_2 ) ) {
F_3 ( V_663 , V_663 -> V_536 ) ;
return V_351 ;
}
V_663 -> V_536 = 1 ;
V_663 -> V_18 = V_18 ;
V_663 -> V_92 = V_92 ;
V_663 -> V_542 = V_542 ;
V_663 -> V_549 = ( V_682 * ) V_164 ;
F_268 ( V_663 ) ;
return V_37 ;
}
T_4
F_278 ( struct V_662 * V_663 , T_6 V_542 ,
struct V_677 * V_259 ,
T_18 V_18 , void * V_92 )
{
F_3 ( V_663 , V_676 ) ;
F_3 ( V_663 , V_542 ) ;
if ( ! F_266 ( V_663 ) )
return V_681 ;
if ( ! F_118 ( V_663 -> V_2 ) )
return V_526 ;
if ( V_663 -> V_536 || F_275 ( V_663 -> V_2 ) ) {
F_3 ( V_663 , V_663 -> V_536 ) ;
return V_351 ;
}
V_663 -> V_536 = 1 ;
V_663 -> V_18 = V_18 ;
V_663 -> V_92 = V_92 ;
V_663 -> V_542 = V_542 ;
V_663 -> V_549 = ( T_6 * ) V_259 ;
F_271 ( V_663 ) ;
return V_37 ;
}
T_4
F_279 ( struct V_662 * V_663 , T_6 V_542 ,
void * V_185 , T_1 V_129 , T_1 V_343 ,
T_18 V_18 , void * V_92 )
{
F_3 ( V_663 , V_672 ) ;
F_3 ( V_663 , V_542 ) ;
F_3 ( V_663 , V_129 ) ;
F_3 ( V_663 , V_343 ) ;
if ( ! F_266 ( V_663 ) )
return V_681 ;
if ( ! F_118 ( V_663 -> V_2 ) )
return V_526 ;
if ( ! V_129 || ( V_129 & 0x03 ) )
return V_187 ;
if ( V_663 -> V_536 || F_275 ( V_663 -> V_2 ) ) {
F_3 ( V_663 , V_663 -> V_536 ) ;
return V_351 ;
}
V_663 -> V_536 = 1 ;
V_663 -> V_18 = V_18 ;
V_663 -> V_92 = V_92 ;
V_663 -> V_542 = V_542 ;
V_663 -> V_544 = V_129 ;
V_663 -> V_343 = 0 ;
V_663 -> V_543 = V_343 ;
V_663 -> V_549 = V_185 ;
F_269 ( V_663 ) ;
return V_37 ;
}
T_4
F_280 ( struct V_662 * V_663 , T_6 V_542 ,
void * V_185 , T_1 V_129 , T_1 V_343 ,
T_18 V_18 , void * V_92 )
{
F_3 ( V_663 , V_674 ) ;
F_3 ( V_663 , V_542 ) ;
F_3 ( V_663 , V_129 ) ;
F_3 ( V_663 , V_343 ) ;
if ( ! F_266 ( V_663 ) )
return V_681 ;
if ( ! F_118 ( V_663 -> V_2 ) )
return V_526 ;
if ( ! V_129 || ( V_129 & 0x03 ) )
return V_187 ;
if ( V_663 -> V_536 || F_275 ( V_663 -> V_2 ) ) {
F_3 ( V_663 , V_663 -> V_536 ) ;
return V_351 ;
}
V_663 -> V_536 = 1 ;
V_663 -> V_18 = V_18 ;
V_663 -> V_92 = V_92 ;
V_663 -> V_542 = V_542 ;
V_663 -> V_544 = V_129 ;
V_663 -> V_343 = 0 ;
V_663 -> V_543 = V_343 ;
V_663 -> V_549 = V_185 ;
F_270 ( V_663 ) ;
return V_37 ;
}
void
V_678 ( void * V_683 , struct V_202 * V_181 )
{
struct V_662 * V_663 = V_683 ;
T_1 V_339 ;
union {
struct V_684 * V_556 ;
struct V_685 * V_259 ;
struct V_686 * V_560 ;
struct V_687 * V_562 ;
struct V_202 * V_181 ;
} V_203 ;
V_203 . V_181 = V_181 ;
F_3 ( V_663 , V_181 -> V_138 . V_205 ) ;
if ( ! V_663 -> V_536 ) {
F_3 ( V_663 , 0x9999 ) ;
return;
}
switch ( V_181 -> V_138 . V_205 ) {
case V_688 :
V_339 = F_93 ( V_203 . V_556 -> V_339 ) ;
F_3 ( V_663 , V_339 ) ;
if ( V_339 == V_37 ) {
struct V_668 * V_164 =
(struct V_668 * ) V_663 -> V_549 ;
F_265 ( ( T_1 * ) V_164 , ( T_1 * ) V_663 -> V_474 ,
sizeof( struct V_668 ) ) ;
F_3 ( V_663 , V_164 -> V_339 ) ;
F_3 ( V_663 , V_164 -> V_546 ) ;
}
V_663 -> V_339 = V_339 ;
V_663 -> V_536 = 0 ;
if ( V_663 -> V_18 )
V_663 -> V_18 ( V_663 -> V_92 , V_663 -> V_339 ) ;
break;
case V_689 :
V_339 = F_93 ( V_203 . V_259 -> V_339 ) ;
F_3 ( V_663 , V_339 ) ;
if ( V_339 == V_37 ) {
struct V_677 * V_259 =
(struct V_677 * ) V_663 -> V_549 ;
F_265 ( ( T_1 * ) V_259 , ( T_1 * ) V_663 -> V_474 ,
sizeof( struct V_677 ) ) ;
F_3 ( V_663 , V_259 -> V_339 ) ;
}
V_663 -> V_339 = V_339 ;
V_663 -> V_536 = 0 ;
if ( V_663 -> V_18 )
V_663 -> V_18 ( V_663 -> V_92 , V_663 -> V_339 ) ;
break;
case V_690 :
V_339 = F_93 ( V_203 . V_560 -> V_339 ) ;
F_3 ( V_663 , V_339 ) ;
if ( V_339 != V_37 || V_663 -> V_544 == 0 ) {
V_663 -> V_339 = V_339 ;
V_663 -> V_536 = 0 ;
if ( V_663 -> V_18 )
V_663 -> V_18 ( V_663 -> V_92 , V_663 -> V_339 ) ;
} else {
F_3 ( V_663 , V_663 -> V_343 ) ;
F_269 ( V_663 ) ;
}
break;
case V_691 :
V_339 = F_93 ( V_203 . V_562 -> V_339 ) ;
F_3 ( V_663 , V_339 ) ;
if ( V_339 != V_37 ) {
V_663 -> V_339 = V_339 ;
V_663 -> V_536 = 0 ;
if ( V_663 -> V_18 )
V_663 -> V_18 ( V_663 -> V_92 , V_663 -> V_339 ) ;
} else {
T_1 V_129 = F_93 ( V_203 . V_562 -> V_546 ) ;
T_10 * V_185 = ( T_10 * ) ( V_663 -> V_549 + V_663 -> V_343 ) ;
T_10 * V_670 = ( T_10 * ) V_663 -> V_474 ;
int V_98 , V_184 = V_129 >> 1 ;
F_3 ( V_663 , V_663 -> V_343 ) ;
F_3 ( V_663 , V_129 ) ;
for ( V_98 = 0 ; V_98 < V_184 ; V_98 ++ )
V_185 [ V_98 ] = F_107 ( V_670 [ V_98 ] ) ;
V_663 -> V_544 -= V_129 ;
V_663 -> V_343 += V_129 ;
if ( V_663 -> V_544 == 0 ) {
V_663 -> V_339 = V_339 ;
V_663 -> V_536 = 0 ;
if ( V_663 -> V_18 )
V_663 -> V_18 ( V_663 -> V_92 , V_663 -> V_339 ) ;
} else
F_270 ( V_663 ) ;
}
break;
default:
F_71 ( 1 ) ;
}
}
static void
F_281 ( struct V_692 * V_693 , enum V_694 V_4 )
{
T_4 V_695 ;
F_3 ( V_693 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_696 :
if ( V_693 -> V_697 ) {
F_3 ( V_693 -> V_20 , V_693 -> V_697 ) ;
return;
}
F_282 ( V_693 , V_698 ) ;
V_693 -> V_699 = V_52 ;
F_3 ( V_693 -> V_20 , V_693 -> V_699 ) ;
V_695 = F_243 ( F_283 ( V_693 -> V_20 ) ,
V_700 , V_693 -> V_542 ,
V_693 -> V_693 ,
sizeof( struct V_701 ) , 0 ,
V_702 , V_693 -> V_20 ) ;
if ( V_695 != V_37 ) {
V_702 ( V_693 -> V_20 , V_187 ) ;
F_282 ( V_693 , F_281 ) ;
return;
}
break;
case V_703 :
V_693 -> V_699 = V_71 ;
case V_704 :
case V_705 :
case V_706 :
break;
default:
F_5 ( V_693 -> V_20 , V_4 ) ;
}
}
static void
V_698 ( struct V_692 * V_693 ,
enum V_694 V_4 )
{
F_3 ( V_693 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_706 :
F_282 ( V_693 , V_707 ) ;
break;
case V_708 :
F_282 ( V_693 , V_707 ) ;
break;
case V_703 :
V_693 -> V_699 = V_71 ;
F_3 ( V_693 -> V_20 , V_693 -> V_699 ) ;
case V_704 :
F_282 ( V_693 , F_281 ) ;
break;
default:
F_5 ( V_693 -> V_20 , V_4 ) ;
}
}
static void
V_707 ( struct V_692 * V_693 , enum V_694 V_4 )
{
F_3 ( V_693 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_705 :
F_284 ( V_693 -> V_20 , & V_693 -> V_368 ,
V_709 , V_693 , V_710 ) ;
F_282 ( V_693 , V_711 ) ;
break;
case V_703 :
V_693 -> V_699 = V_71 ;
F_3 ( V_693 -> V_20 , V_693 -> V_699 ) ;
F_282 ( V_693 , F_281 ) ;
break;
case V_696 :
case V_704 :
break;
default:
F_5 ( V_693 -> V_20 , V_4 ) ;
}
}
static void
V_711 ( struct V_692 * V_693 , enum V_694 V_4 )
{
F_3 ( V_693 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_708 :
F_282 ( V_693 , V_712 ) ;
F_285 ( V_693 ) ;
break;
case V_705 :
F_192 ( & V_693 -> V_368 ) ;
F_284 ( V_693 -> V_20 , & V_693 -> V_368 ,
V_709 , V_693 , V_710 ) ;
break;
case V_703 :
F_192 ( & V_693 -> V_368 ) ;
F_284 ( V_693 -> V_20 , & V_693 -> V_368 ,
V_709 , V_693 , V_710 ) ;
F_282 ( V_693 , V_713 ) ;
F_285 ( V_693 ) ;
break;
case V_706 :
break;
case V_704 :
F_192 ( & V_693 -> V_368 ) ;
F_282 ( V_693 , V_714 ) ;
break;
default:
F_5 ( V_693 -> V_20 , V_4 ) ;
}
}
static void
V_713 ( struct V_692 * V_693 ,
enum V_694 V_4 )
{
F_3 ( V_693 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_704 :
case V_706 :
F_192 ( & V_693 -> V_368 ) ;
case V_708 :
F_282 ( V_693 , F_281 ) ;
V_693 -> V_699 = V_71 ;
F_3 ( V_693 -> V_20 , V_693 -> V_699 ) ;
F_135 ( & V_693 -> V_20 -> V_2 ) ;
break;
default:
F_5 ( V_693 -> V_20 , V_4 ) ;
}
}
static void
V_712 ( struct V_692 * V_693 , enum V_694 V_4 )
{
F_3 ( V_693 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_706 :
F_282 ( V_693 , V_707 ) ;
break;
case V_705 :
F_284 ( V_693 -> V_20 , & V_693 -> V_368 ,
V_709 , V_693 , V_710 ) ;
F_282 ( V_693 , V_711 ) ;
break;
case V_703 :
F_284 ( V_693 -> V_20 , & V_693 -> V_368 ,
V_709 , V_693 , V_710 ) ;
F_282 ( V_693 , V_713 ) ;
break;
case V_704 :
F_282 ( V_693 , V_714 ) ;
break;
default:
F_5 ( V_693 -> V_20 , V_4 ) ;
}
}
static void
V_714 ( struct V_692 * V_693 ,
enum V_694 V_4 )
{
F_3 ( V_693 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_696 :
F_284 ( V_693 -> V_20 , & V_693 -> V_368 ,
V_709 , V_693 , V_710 ) ;
F_282 ( V_693 , V_711 ) ;
break;
case V_703 :
V_693 -> V_699 = V_71 ;
F_282 ( V_693 , F_281 ) ;
break;
case V_704 :
break;
default:
F_5 ( V_693 -> V_20 , V_4 ) ;
}
}
static void
F_286 ( struct V_715 * V_370 , struct V_716 * V_717 ,
struct V_718 * V_20 )
{
struct V_719 * V_720 = F_287 ( V_20 ) ;
if ( V_370 -> V_721 . V_697 )
F_288 ( V_717 , V_720 ,
sizeof( struct V_722 ) ) ;
else
F_288 ( V_717 , V_720 ,
sizeof( struct V_701 ) ) ;
}
static void
F_289 ( struct V_718 * V_20 , void * V_36 , struct V_715 * V_370 ,
struct V_221 * V_222 )
{
struct V_692 * V_693 = F_290 ( V_20 ) ;
V_693 -> V_36 = V_36 ;
V_693 -> V_20 = V_20 ;
V_693 -> V_542 = V_20 -> V_2 . V_320 ;
F_3 ( V_20 , V_693 -> V_542 ) ;
V_693 -> V_693 = (struct V_701 * ) F_291 ( V_693 ) ;
if ( V_370 -> V_721 . V_697 ) {
F_291 ( V_693 ) += sizeof( struct V_722 ) ;
V_693 -> V_697 = V_71 ;
V_693 -> V_699 = V_71 ;
} else {
V_693 -> V_697 = V_52 ;
F_291 ( V_693 ) += sizeof( struct V_701 ) ;
}
F_292 ( V_20 ) = V_52 ;
F_282 ( V_693 , F_281 ) ;
}
static void
V_702 ( void * V_367 , T_4 V_339 )
{
struct V_718 * V_20 = V_367 ;
struct V_692 * V_693 = F_290 ( V_20 ) ;
V_693 -> V_699 = V_71 ;
F_3 ( V_20 , V_693 -> V_699 ) ;
F_293 ( V_20 , V_339 ) ;
if ( V_339 == V_37 ) {
F_292 ( V_20 ) = V_71 ;
if ( V_693 -> V_693 -> V_723 . V_116 != V_724 )
V_693 -> V_693 -> V_723 . V_116 = V_724 ;
if ( V_693 -> V_693 -> V_723 . V_725 != V_726 )
V_693 -> V_693 -> V_723 . V_725 = V_726 ;
}
F_294 ( V_693 , V_706 ) ;
}
void
F_295 ( struct V_718 * V_20 )
{
struct V_692 * V_693 = F_290 ( V_20 ) ;
F_294 ( V_693 , V_696 ) ;
}
static void
F_296 ( struct V_718 * V_20 )
{
}
static void
F_297 ( struct V_718 * V_20 )
{
}
static void V_709 ( void * V_92 )
{
struct V_692 * V_693 = V_92 ;
F_294 ( V_693 , V_708 ) ;
}
static void
F_298 ( struct V_718 * V_20 )
{
struct V_692 * V_693 = F_290 ( V_20 ) ;
F_294 ( V_693 , V_704 ) ;
}
static void
F_299 ( struct V_718 * V_20 )
{
}
static T_4
F_285 ( struct V_692 * V_693 )
{
T_4 V_695 ;
F_3 ( V_693 -> V_20 , 0 ) ;
V_695 = F_242 ( F_283 ( V_693 -> V_20 ) ,
V_700 , V_693 -> V_542 ,
V_693 -> V_693 , sizeof( struct V_701 ) , 0 ,
V_727 , V_693 ) ;
if ( V_695 != V_37 )
F_71 ( V_695 ) ;
F_3 ( V_693 -> V_20 , V_695 ) ;
return V_695 ;
}
T_4
F_300 ( struct V_718 * V_20 )
{
struct V_692 * V_693 = F_290 ( V_20 ) ;
F_3 ( V_693 -> V_20 , 0 ) ;
if ( F_301 ( V_693 , V_714 ) )
return V_187 ;
if ( V_693 -> V_697 ) {
F_3 ( V_693 -> V_20 , V_693 -> V_697 ) ;
return V_187 ;
}
F_294 ( V_693 , V_705 ) ;
return V_37 ;
}
static void
V_727 ( void * V_367 , T_4 V_339 )
{
struct V_692 * V_693 = V_367 ;
F_71 ( V_339 ) ;
F_294 ( V_693 , V_706 ) ;
}
void
F_302 ( struct V_718 * V_20 )
{
struct V_692 * V_693 = F_290 ( V_20 ) ;
F_290 ( V_20 ) -> V_699 = V_52 ;
F_3 ( V_20 , F_290 ( V_20 ) -> V_699 ) ;
F_294 ( V_693 , V_703 ) ;
}
