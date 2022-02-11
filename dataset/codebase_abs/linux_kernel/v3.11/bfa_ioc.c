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
F_4 ( V_2 , V_29 ) ;
break;
case V_16 :
case V_17 :
F_13 ( V_2 ) ;
case V_30 :
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
F_4 ( V_2 , V_22 ) ;
if ( V_4 != V_16 )
F_9 ( & V_2 -> V_7 , V_31 ) ;
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
F_14 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 -> V_20 -> V_33 ;
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_34 ) ;
F_15 ( V_2 , V_35 ) ;
F_16 ( V_2 ) ;
F_17 ( V_36 , V_33 , V_37 , L_1 ) ;
F_18 ( V_2 , V_38 ) ;
}
static void
V_29 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_9 :
break;
case V_11 :
F_19 ( V_2 ) ;
F_4 ( V_2 , V_26 ) ;
break;
case V_16 :
case V_17 :
F_19 ( V_2 ) ;
case V_39 :
if ( V_2 -> V_7 . V_40 )
F_4 ( V_2 , V_41 ) ;
else
F_4 ( V_2 , V_22 ) ;
F_20 ( V_2 ) ;
if ( V_4 != V_16 )
F_9 ( & V_2 -> V_7 , V_42 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_21 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 -> V_20 -> V_33 ;
F_9 ( & V_2 -> V_7 , V_43 ) ;
F_17 ( V_36 , V_33 , V_37 , L_2 ) ;
F_18 ( V_2 , V_44 ) ;
}
static void
V_26 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_45 :
F_4 ( V_2 , V_46 ) ;
break;
case V_17 :
F_9 ( & V_2 -> V_7 , V_42 ) ;
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
F_22 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
static void
V_46 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_9 :
F_4 ( V_2 , V_10 ) ;
break;
case V_11 :
V_2 -> V_18 -> V_47 ( V_2 -> V_20 ) ;
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
F_23 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0 ) ;
}
static void
V_41 ( struct V_1 * V_2 , enum V_3 V_4 )
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
F_24 ( struct V_1 * V_2 )
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
case V_24 :
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
V_25 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_9 :
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
break;
case V_11 :
V_2 -> V_18 -> V_47 ( V_2 -> V_20 ) ;
break;
case V_12 :
F_4 ( V_2 , F_2 ) ;
break;
case V_17 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_26 ( struct V_48 * V_7 )
{
V_7 -> V_49 = V_50 ;
V_7 -> V_40 = V_51 ;
}
static void
V_8 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_13 :
F_4 ( V_7 , V_53 ) ;
break;
case V_27 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_27 ( struct V_48 * V_7 )
{
struct V_54 V_55 ;
T_1 V_56 , V_57 , V_58 , V_59 , V_60 = 0 ;
int V_61 ;
V_56 = F_28 ( V_7 -> V_2 -> V_62 . V_63 ) ;
while ( V_56 & 0x1 ) {
F_29 ( 20 ) ;
V_56 = F_28 ( V_7 -> V_2 -> V_62 . V_63 ) ;
}
V_57 = F_30 ( V_7 -> V_2 ) ;
if ( V_57 == V_64 ) {
F_31 ( 1 , V_7 -> V_2 -> V_62 . V_63 ) ;
goto V_65;
}
F_32 ( V_7 -> V_2 , & V_55 ) ;
if ( F_33 ( V_55 . V_66 ) == V_67 ) {
F_31 ( 1 , V_7 -> V_2 -> V_62 . V_63 ) ;
goto V_65;
}
V_58 = F_34 ( V_7 -> V_2 -> V_62 . V_68 , V_60 ) ;
V_59 = F_35 ( V_60 ) ;
F_31 ( V_58 , V_7 -> V_2 -> V_62 . V_69 ) ;
for ( V_61 = 0 ; V_61 < sizeof( struct V_54 ) / sizeof( T_1 ) ; V_61 ++ ) {
F_36 ( V_7 -> V_2 -> V_62 . V_70 , V_60 , 0 ) ;
V_60 += sizeof( T_1 ) ;
}
F_3 ( V_7 -> V_2 , V_57 ) ;
F_3 ( V_7 -> V_2 , F_33 ( V_55 . V_66 ) ) ;
F_37 ( V_7 -> V_2 , V_64 ) ;
F_38 ( V_7 -> V_2 , V_64 ) ;
F_39 ( V_7 -> V_2 ) ;
F_31 ( 1 , V_7 -> V_2 -> V_62 . V_63 ) ;
V_65:
F_40 ( V_7 -> V_2 ) ;
}
static void
V_53 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_71 :
if ( F_41 ( V_2 ) ) {
if ( F_42 ( V_2 ) ) {
F_43 ( V_2 ) ;
F_4 ( V_7 , V_72 ) ;
} else {
F_44 ( V_2 ) ;
F_31 ( 1 , V_2 -> V_62 . V_73 ) ;
F_45 ( V_2 ) ;
}
} else {
F_31 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_74 ) ;
}
break;
case V_75 :
F_4 ( V_7 , V_76 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_43 :
F_46 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
F_9 ( V_2 , V_45 ) ;
break;
case V_27 :
F_46 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_47 ( struct V_48 * V_7 )
{
if ( V_7 -> V_49 == V_50 )
F_48 ( V_7 -> V_2 ) ;
V_7 -> V_49 = V_77 ;
F_49 ( V_7 -> V_2 ) ;
}
static void
V_74 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_78 :
F_4 ( V_7 , V_53 ) ;
break;
case V_43 :
F_50 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
F_9 ( V_2 , V_45 ) ;
break;
case V_27 :
F_50 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_51 ( struct V_48 * V_7 )
{
F_40 ( V_7 -> V_2 ) ;
}
static void
F_52 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_71 :
if ( F_53 ( V_2 ) ) {
F_43 ( V_2 ) ;
F_4 ( V_7 , V_72 ) ;
} else {
F_31 ( 1 , V_2 -> V_62 . V_73 ) ;
F_45 ( V_2 ) ;
}
break;
case V_75 :
F_4 ( V_7 , V_76 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_43 :
F_46 ( V_2 ) ;
F_4 ( V_7 , V_79 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_54 ( struct V_48 * V_7 )
{
V_7 -> V_80 = 0 ;
F_55 ( V_7 -> V_2 , V_50 ) ;
}
static void
V_72 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_81 :
F_4 ( V_7 , V_82 ) ;
break;
case V_78 :
F_31 ( 1 , V_2 -> V_62 . V_73 ) ;
F_9 ( V_2 , V_16 ) ;
F_4 ( V_7 , V_83 ) ;
break;
case V_43 :
F_50 ( V_2 ) ;
F_56 ( V_2 ) ;
F_31 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_84 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_57 ( struct V_48 * V_7 )
{
F_49 ( V_7 -> V_2 ) ;
V_7 -> V_2 -> V_18 -> V_85 ( V_7 -> V_2 -> V_20 ) ;
F_58 ( V_7 -> V_2 ) ;
}
static void
V_82 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_86 :
F_50 ( V_2 ) ;
F_31 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_87 ) ;
break;
case V_23 :
F_50 ( V_2 ) ;
case V_78 :
F_31 ( 1 , V_2 -> V_62 . V_73 ) ;
if ( V_4 == V_78 )
F_9 ( V_2 , V_16 ) ;
F_4 ( V_7 , V_83 ) ;
break;
case V_43 :
F_50 ( V_2 ) ;
F_31 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_88 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_59 ( struct V_48 * V_7 )
{
F_9 ( V_7 -> V_2 , V_14 ) ;
}
static void
V_87 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_43 :
F_4 ( V_7 , V_88 ) ;
break;
case V_31 :
F_4 ( V_7 , V_83 ) ;
break;
case V_42 :
F_4 ( V_7 , V_89 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_60 ( struct V_48 * V_7 )
{
F_49 ( V_7 -> V_2 ) ;
F_61 ( V_7 -> V_2 ) ;
}
static void
V_88 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_90 :
F_50 ( V_2 ) ;
F_4 ( V_7 , V_79 ) ;
break;
case V_42 :
F_50 ( V_2 ) ;
case V_78 :
F_37 ( V_2 , V_91 ) ;
F_4 ( V_7 , V_79 ) ;
break;
case V_86 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_62 ( struct V_48 * V_7 )
{
F_40 ( V_7 -> V_2 ) ;
}
static void
V_79 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_71 :
F_56 ( V_2 ) ;
F_31 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_84 ) ;
break;
case V_75 :
F_4 ( V_7 , V_76 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_42 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_63 ( struct V_48 * V_7 )
{
F_64 ( V_7 -> V_2 ) ;
F_9 ( V_7 -> V_2 , V_45 ) ;
}
static void
V_84 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_13 :
F_4 ( V_7 , F_52 ) ;
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
F_65 ( struct V_48 * V_7 )
{
F_66 ( V_7 -> V_2 ) ;
F_40 ( V_7 -> V_2 ) ;
}
static void
V_83 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_71 :
F_67 ( V_2 ) ;
F_56 ( V_2 ) ;
F_37 ( V_2 , V_91 ) ;
F_31 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_92 ) ;
break;
case V_75 :
F_4 ( V_7 , V_76 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_43 :
F_46 ( V_2 ) ;
F_4 ( V_7 , V_79 ) ;
break;
case V_27 :
F_46 ( V_2 ) ;
F_44 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
case V_42 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_68 ( struct V_48 * V_7 )
{
F_3 ( V_7 -> V_2 , 0 ) ;
}
static void
V_92 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_43 :
F_4 ( V_7 , V_84 ) ;
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
F_69 ( struct V_48 * V_7 )
{
F_70 ( V_7 -> V_2 ) ;
F_64 ( V_7 -> V_2 ) ;
F_40 ( V_7 -> V_2 ) ;
}
static void
V_89 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_71 :
F_71 ( V_2 ) ;
F_67 ( V_2 ) ;
if ( ! V_7 -> V_40 ) {
F_56 ( V_2 ) ;
F_37 ( V_2 , V_91 ) ;
F_31 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_76 ) ;
} else {
if ( F_53 ( V_2 ) )
F_4 ( V_7 , V_72 ) ;
else {
F_31 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , F_52 ) ;
}
}
break;
case V_75 :
F_4 ( V_7 , V_76 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_43 :
F_46 ( V_2 ) ;
F_4 ( V_7 , V_79 ) ;
break;
case V_42 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_72 ( struct V_48 * V_7 )
{
F_3 ( V_7 -> V_2 , 0 ) ;
}
static void
V_76 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_43 :
F_4 ( V_7 , V_84 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_15 ( struct V_1 * V_2 , enum V_93 V_4 )
{
struct V_94 * V_95 ;
struct V_96 * V_97 ;
F_73 (qe, &ioc->notify_q) {
V_95 = (struct V_94 * ) V_97 ;
V_95 -> V_18 ( V_95 -> V_98 , V_4 ) ;
}
}
static void
F_7 ( struct V_1 * V_2 )
{
V_2 -> V_18 -> V_47 ( V_2 -> V_20 ) ;
F_15 ( V_2 , V_99 ) ;
}
T_2
F_74 ( void T_3 * V_100 )
{
T_1 V_56 ;
int V_101 = 0 ;
#define F_75 3000
V_56 = F_28 ( V_100 ) ;
while ( ( V_56 & 1 ) && ( V_101 < F_75 ) ) {
V_101 ++ ;
F_29 ( 2 ) ;
V_56 = F_28 ( V_100 ) ;
}
if ( ! ( V_56 & 1 ) )
return V_77 ;
return V_50 ;
}
static void
F_40 ( struct V_1 * V_2 )
{
T_1 V_56 ;
V_56 = F_28 ( V_2 -> V_62 . V_73 ) ;
if ( V_56 == ~ 0 ) {
F_76 ( V_56 == ~ 0 ) ;
F_9 ( & V_2 -> V_7 , V_75 ) ;
return;
}
if ( ! ( V_56 & 1 ) ) {
F_9 ( & V_2 -> V_7 , V_71 ) ;
return;
}
F_45 ( V_2 ) ;
}
static void
F_77 ( struct V_1 * V_2 )
{
T_1 V_102 ;
int V_61 ;
#define F_78 10000
V_102 = F_28 ( V_2 -> V_62 . V_103 ) ;
V_102 &= ~ V_104 ;
V_102 |= V_105 ;
V_102 |= F_79 ( 3UL ) ;
F_31 ( V_102 , V_2 -> V_62 . V_103 ) ;
V_61 = 0 ;
do {
V_102 = F_28 ( V_2 -> V_62 . V_103 ) ;
V_61 ++ ;
} while ( ! ( V_102 & V_106 ) && ( V_61 < F_78 ) );
F_76 ( ! ( V_102 & V_106 ) ) ;
F_3 ( V_2 , V_102 ) ;
V_102 &= ~ ( V_106 | V_105 ) ;
F_31 ( V_102 , V_2 -> V_62 . V_103 ) ;
}
static void
F_80 ( struct V_1 * V_2 )
{
T_1 V_102 ;
V_102 = F_28 ( V_2 -> V_62 . V_103 ) ;
V_102 &= ~ V_107 ;
F_31 ( V_102 , V_2 -> V_62 . V_103 ) ;
}
static void
F_70 ( struct V_1 * V_2 )
{
T_1 V_102 ;
V_102 = F_28 ( V_2 -> V_62 . V_103 ) ;
V_102 |= ( V_107 | V_108 ) ;
F_31 ( V_102 , V_2 -> V_62 . V_103 ) ;
}
void
F_32 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
T_1 V_58 , V_59 ;
T_1 V_60 = 0 ;
int V_61 ;
T_1 * V_109 = ( T_1 * ) V_55 ;
V_58 = F_34 ( V_2 -> V_62 . V_68 , V_60 ) ;
V_59 = F_35 ( V_60 ) ;
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
for ( V_61 = 0 ; V_61 < ( sizeof( struct V_54 ) / sizeof( T_1 ) ) ;
V_61 ++ ) {
V_109 [ V_61 ] =
F_81 ( V_2 -> V_62 . V_70 , V_60 ) ;
V_60 += sizeof( T_1 ) ;
}
}
T_2
F_82 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_54 * V_110 ;
int V_61 ;
V_110 = (struct V_54 * )
F_83 ( F_84 ( V_2 ) , 0 ) ;
for ( V_61 = 0 ; V_61 < V_111 ; V_61 ++ ) {
if ( V_55 -> V_112 [ V_61 ] != F_85 ( V_110 -> V_112 [ V_61 ] ) ) {
F_3 ( V_2 , V_61 ) ;
F_3 ( V_2 , V_55 -> V_112 [ V_61 ] ) ;
F_3 ( V_2 , V_110 -> V_112 [ V_61 ] ) ;
return V_50 ;
}
}
F_3 ( V_2 , V_55 -> V_112 [ 0 ] ) ;
return V_77 ;
}
static T_2
F_86 ( struct V_1 * V_2 , T_1 V_113 )
{
struct V_54 V_55 , * V_110 ;
F_32 ( V_2 , & V_55 ) ;
V_110 = (struct V_54 * )
F_83 ( F_84 ( V_2 ) , 0 ) ;
if ( V_55 . V_114 != F_85 ( V_110 -> V_114 ) ) {
F_3 ( V_2 , V_55 . V_114 ) ;
F_3 ( V_2 , V_110 -> V_114 ) ;
return V_50 ;
}
if ( F_33 ( V_55 . V_115 ) != V_113 ) {
F_3 ( V_2 , V_55 . V_115 ) ;
F_3 ( V_2 , V_113 ) ;
return V_50 ;
}
return F_82 ( V_2 , & V_55 ) ;
}
static void
F_87 ( struct V_1 * V_2 )
{
T_1 V_56 ;
V_56 = F_28 ( V_2 -> V_62 . V_116 ) ;
if ( V_56 )
F_31 ( 1 , V_2 -> V_62 . V_116 ) ;
}
static void
F_55 ( struct V_1 * V_2 , T_2 V_117 )
{
enum V_118 V_119 ;
T_2 V_120 ;
T_1 V_121 ;
T_1 V_113 ;
V_119 = F_30 ( V_2 ) ;
if ( V_117 )
V_119 = V_64 ;
F_3 ( V_2 , V_119 ) ;
V_121 = V_67 ;
V_113 = V_122 ;
V_120 = ( V_119 == V_64 ) ?
V_50 : F_86 ( V_2 , V_113 ) ;
if ( ! V_120 ) {
F_88 ( V_2 , V_121 , V_113 ) ;
F_89 ( V_2 ) ;
return;
}
if ( V_119 == V_123 ) {
F_89 ( V_2 ) ;
return;
}
if ( V_119 == V_124 || V_119 == V_125 ) {
F_87 ( V_2 ) ;
F_9 ( & V_2 -> V_7 , V_81 ) ;
return;
}
F_88 ( V_2 , V_121 , V_113 ) ;
F_89 ( V_2 ) ;
}
static void
F_90 ( void * V_126 )
{
struct V_1 * V_2 = (struct V_1 * ) V_126 ;
F_3 ( V_2 , 0 ) ;
F_9 ( V_2 , V_30 ) ;
}
void
F_91 ( struct V_1 * V_2 , void * V_127 , int V_128 )
{
T_1 * V_129 = ( T_1 * ) V_127 ;
T_1 V_61 ;
F_3 ( V_2 , V_129 [ 0 ] ) ;
F_3 ( V_2 , V_128 ) ;
F_76 ( V_128 > V_130 ) ;
for ( V_61 = 0 ; V_61 < V_128 / sizeof( T_1 ) ; V_61 ++ )
F_31 ( F_85 ( V_129 [ V_61 ] ) ,
V_2 -> V_62 . V_131 + V_61 * sizeof( T_1 ) ) ;
for (; V_61 < V_130 / sizeof( T_1 ) ; V_61 ++ )
F_31 ( 0 , V_2 -> V_62 . V_131 + V_61 * sizeof( T_1 ) ) ;
F_31 ( 1 , V_2 -> V_62 . V_132 ) ;
( void ) F_28 ( V_2 -> V_62 . V_132 ) ;
}
static void
F_58 ( struct V_1 * V_2 )
{
struct V_133 V_134 ;
struct V_135 V_136 ;
F_92 ( V_134 . V_137 , V_138 , V_139 ,
F_93 ( V_2 ) ) ;
V_134 . V_140 = F_94 ( V_2 -> V_140 ) ;
F_95 ( & V_136 ) ;
V_134 . V_141 = F_96 ( V_136 . V_141 ) ;
F_91 ( V_2 , & V_134 , sizeof( struct V_133 ) ) ;
}
static void
F_61 ( struct V_1 * V_2 )
{
struct V_133 V_142 ;
F_92 ( V_142 . V_137 , V_138 , V_143 ,
F_93 ( V_2 ) ) ;
F_91 ( V_2 , & V_142 , sizeof( struct V_133 ) ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
struct V_144 V_145 ;
F_92 ( V_145 . V_137 , V_138 , V_146 ,
F_93 ( V_2 ) ) ;
F_97 ( V_145 . V_147 , V_2 -> V_148 . V_149 ) ;
F_91 ( V_2 , & V_145 , sizeof( V_145 ) ) ;
}
static void
F_98 ( void * V_98 )
{
struct V_1 * V_2 = V_98 ;
T_1 V_150 ;
V_150 = F_28 ( V_2 -> V_62 . V_151 ) ;
if ( V_2 -> V_150 == V_150 ) {
F_99 ( V_2 ) ;
return;
} else {
V_2 -> V_150 = V_150 ;
}
F_100 ( V_2 ) ;
F_101 ( V_2 ) ;
}
static void
F_16 ( struct V_1 * V_2 )
{
V_2 -> V_150 = F_28 ( V_2 -> V_62 . V_151 ) ;
F_101 ( V_2 ) ;
}
static void
F_102 ( struct V_1 * V_2 , T_1 V_121 ,
T_1 V_113 )
{
T_1 * V_152 ;
T_1 V_58 , V_59 ;
T_1 V_60 = 0 ;
T_1 V_153 = 0 ;
T_1 V_61 ;
T_1 V_154 ;
F_3 ( V_2 , F_103 ( F_84 ( V_2 ) ) ) ;
V_152 = F_83 ( F_84 ( V_2 ) , V_153 ) ;
V_58 = F_34 ( V_2 -> V_62 . V_68 , V_60 ) ;
V_59 = F_35 ( V_60 ) ;
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
for ( V_61 = 0 ; V_61 < F_103 ( F_84 ( V_2 ) ) ; V_61 ++ ) {
if ( F_104 ( V_61 ) != V_153 ) {
V_153 = F_104 ( V_61 ) ;
V_152 = F_83 ( F_84 ( V_2 ) ,
F_105 ( V_153 ) ) ;
}
F_36 ( V_2 -> V_62 . V_70 , V_60 ,
F_85 ( V_152 [ F_106 ( V_61 ) ] ) ) ;
V_60 += sizeof( T_1 ) ;
V_60 = F_35 ( V_60 ) ;
if ( V_60 == 0 ) {
V_58 ++ ;
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
}
}
F_31 ( F_34 ( V_2 -> V_62 . V_68 , 0 ) ,
V_2 -> V_62 . V_69 ) ;
V_154 = F_107 ( V_2 -> V_155 , V_2 -> V_156 ,
V_2 -> V_157 , V_2 -> V_158 ) ;
F_36 ( V_2 -> V_62 . V_70 , V_159 ,
F_33 ( V_154 ) ) ;
F_36 ( V_2 -> V_62 . V_70 , V_160 ,
F_33 ( V_121 ) ) ;
F_36 ( V_2 -> V_62 . V_70 , V_161 ,
F_33 ( V_113 ) ) ;
}
static void
F_108 ( struct V_1 * V_2 )
{
struct V_162 * V_163 = V_2 -> V_163 ;
V_163 -> V_164 = F_96 ( V_163 -> V_164 ) ;
V_163 -> V_165 = F_96 ( V_163 -> V_165 ) ;
V_163 -> V_166 = F_109 ( V_163 -> V_166 ) ;
V_2 -> V_167 = ( V_163 -> V_168 == V_169 ) ;
V_163 -> V_170 = F_109 ( V_163 -> V_170 ) ;
F_9 ( V_2 , V_28 ) ;
}
static void
F_110 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
int V_174 ;
F_111 ( & V_172 -> V_175 ) ;
for ( V_174 = 0 ; V_174 < V_176 ; V_174 ++ ) {
V_172 -> V_177 [ V_174 ] . V_18 = NULL ;
V_172 -> V_177 [ V_174 ] . V_98 = V_2 -> V_20 ;
}
}
static void
F_100 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
struct V_178 * V_179 ;
T_1 V_180 ;
if ( F_112 ( & V_172 -> V_175 ) )
return;
V_180 = F_28 ( V_2 -> V_62 . V_132 ) ;
if ( V_180 )
return;
F_113 ( & V_172 -> V_175 , & V_179 ) ;
F_91 ( V_2 , V_179 -> V_181 , sizeof( V_179 -> V_181 ) ) ;
}
static void
F_64 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
struct V_178 * V_179 ;
while ( ! F_112 ( & V_172 -> V_175 ) )
F_113 ( & V_172 -> V_175 , & V_179 ) ;
}
static T_4
F_114 ( struct V_1 * V_2 , void * V_182 , T_1 V_183 , T_1 V_184 )
{
T_1 V_58 , V_60 ;
T_5 V_56 ;
int V_61 , V_128 ;
T_1 * V_185 = V_182 ;
V_58 = F_34 ( V_2 -> V_62 . V_68 , V_183 ) ;
V_60 = F_35 ( V_183 ) ;
F_3 ( V_2 , V_58 ) ;
F_3 ( V_2 , V_60 ) ;
F_3 ( V_2 , V_184 ) ;
if ( V_50 == F_74 ( V_2 -> V_62 . V_63 ) ) {
F_3 ( V_2 , 0 ) ;
return V_186 ;
}
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
V_128 = V_184 / sizeof( T_1 ) ;
F_3 ( V_2 , V_128 ) ;
for ( V_61 = 0 ; V_61 < V_128 ; V_61 ++ ) {
V_56 = F_81 ( V_2 -> V_62 . V_70 , V_60 ) ;
V_185 [ V_61 ] = F_33 ( V_56 ) ;
V_60 += sizeof( T_1 ) ;
V_60 = F_35 ( V_60 ) ;
if ( V_60 == 0 ) {
V_58 ++ ;
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
}
}
F_31 ( F_34 ( V_2 -> V_62 . V_68 , 0 ) ,
V_2 -> V_62 . V_69 ) ;
F_28 ( V_2 -> V_62 . V_63 ) ;
F_31 ( 1 , V_2 -> V_62 . V_63 ) ;
F_3 ( V_2 , V_58 ) ;
return V_34 ;
}
static T_4
F_115 ( struct V_1 * V_2 , T_1 V_183 , T_1 V_184 )
{
int V_61 , V_128 ;
T_1 V_58 , V_60 ;
V_58 = F_34 ( V_2 -> V_62 . V_68 , V_183 ) ;
V_60 = F_35 ( V_183 ) ;
F_3 ( V_2 , V_58 ) ;
F_3 ( V_2 , V_60 ) ;
F_3 ( V_2 , V_184 ) ;
if ( V_50 == F_74 ( V_2 -> V_62 . V_63 ) ) {
F_3 ( V_2 , 0 ) ;
return V_186 ;
}
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
V_128 = V_184 / sizeof( T_1 ) ;
F_3 ( V_2 , V_128 ) ;
for ( V_61 = 0 ; V_61 < V_128 ; V_61 ++ ) {
F_36 ( V_2 -> V_62 . V_70 , V_60 , 0 ) ;
V_60 += sizeof( T_1 ) ;
V_60 = F_35 ( V_60 ) ;
if ( V_60 == 0 ) {
V_58 ++ ;
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
}
}
F_31 ( F_34 ( V_2 -> V_62 . V_68 , 0 ) ,
V_2 -> V_62 . V_69 ) ;
F_28 ( V_2 -> V_62 . V_63 ) ;
F_31 ( 1 , V_2 -> V_62 . V_63 ) ;
F_3 ( V_2 , V_58 ) ;
return V_34 ;
}
static void
F_20 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 -> V_20 -> V_33 ;
V_2 -> V_18 -> V_187 ( V_2 -> V_20 ) ;
F_15 ( V_2 , V_188 ) ;
F_66 ( V_2 ) ;
F_17 ( V_189 , V_33 , V_37 ,
L_3 ) ;
F_18 ( V_2 , V_190 ) ;
}
static void
F_48 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 -> V_20 -> V_33 ;
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
F_17 ( V_191 , V_33 , V_37 ,
L_4
L_5 ) ;
F_18 ( V_2 , V_192 ) ;
}
T_4
F_116 ( struct V_1 * V_2 )
{
F_74 ( V_2 -> V_62 . V_63 ) ;
F_117 ( V_2 ) ;
V_2 -> V_193 = V_77 ;
F_77 ( V_2 ) ;
F_28 ( V_2 -> V_62 . V_63 ) ;
F_31 ( 1 , V_2 -> V_62 . V_63 ) ;
return V_34 ;
}
void
F_88 ( struct V_1 * V_2 , T_1 V_121 , T_1 V_113 )
{
F_118 ( V_2 , V_194 ) ;
if ( F_116 ( V_2 ) != V_34 )
return;
if ( V_121 == V_195 ) {
F_37 ( V_2 , V_196 ) ;
F_38 ( V_2 , V_196 ) ;
} else {
F_37 ( V_2 , V_123 ) ;
F_38 ( V_2 , V_123 ) ;
}
F_87 ( V_2 ) ;
F_102 ( V_2 , V_121 , V_113 ) ;
F_80 ( V_2 ) ;
}
void
F_119 ( T_2 V_40 )
{
V_51 = V_40 ;
}
T_2
F_120 ( struct V_1 * V_2 )
{
return F_121 ( V_2 , V_29 ) ;
}
T_2
F_122 ( struct V_1 * V_2 )
{
T_1 V_56 = F_30 ( V_2 ) ;
return ( ( V_56 != V_64 ) &&
( V_56 != V_123 ) &&
( V_56 != V_196 ) ) ;
}
T_2
F_123 ( struct V_1 * V_2 , void * V_197 )
{
T_5 * V_129 = V_197 ;
T_1 V_56 ;
int V_61 ;
V_56 = F_28 ( V_2 -> V_62 . V_116 ) ;
if ( ( V_56 & 1 ) == 0 )
return V_50 ;
for ( V_61 = 0 ; V_61 < ( sizeof( union V_198 ) / sizeof( T_1 ) ) ;
V_61 ++ ) {
V_56 = F_28 ( V_2 -> V_62 . V_199 +
V_61 * sizeof( T_1 ) ) ;
V_129 [ V_61 ] = F_124 ( V_56 ) ;
}
F_31 ( 1 , V_2 -> V_62 . V_116 ) ;
F_28 ( V_2 -> V_62 . V_116 ) ;
return V_77 ;
}
void
F_125 ( struct V_1 * V_2 , struct V_200 * V_201 )
{
union V_198 * V_181 ;
struct V_48 * V_7 = & V_2 -> V_7 ;
V_181 = (union V_198 * ) V_201 ;
F_118 ( V_2 , V_202 ) ;
switch ( V_181 -> V_137 . V_203 ) {
case V_204 :
break;
case V_205 :
V_2 -> V_168 = V_2 -> V_206 =
(enum V_207 ) V_181 -> V_208 . V_168 ;
V_2 -> V_209 = V_181 -> V_208 . V_210 ;
F_9 ( V_7 , V_86 ) ;
break;
case V_211 :
F_9 ( V_7 , V_90 ) ;
break;
case V_212 :
F_108 ( V_2 ) ;
break;
default:
F_3 ( V_2 , V_181 -> V_137 . V_203 ) ;
F_76 ( 1 ) ;
}
}
void
F_126 ( struct V_1 * V_2 , void * V_20 , struct V_213 * V_18 ,
struct V_214 * V_215 )
{
V_2 -> V_20 = V_20 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_215 = V_215 ;
V_2 -> V_167 = V_50 ;
V_2 -> V_193 = V_50 ;
V_2 -> V_216 = V_77 ;
V_2 -> V_7 . V_2 = V_2 ;
F_110 ( V_2 ) ;
F_111 ( & V_2 -> V_217 ) ;
F_4 ( V_2 , F_2 ) ;
F_9 ( V_2 , V_5 ) ;
}
void
F_127 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_12 ) ;
F_111 ( & V_2 -> V_217 ) ;
}
void
F_128 ( struct V_1 * V_2 , struct V_218 * V_219 ,
enum V_220 V_140 )
{
V_2 -> V_140 = V_140 ;
V_2 -> V_219 = * V_219 ;
V_2 -> V_157 = V_2 -> V_158 = V_169 ;
V_2 -> V_156 = V_221 ;
switch ( V_219 -> V_222 ) {
case V_223 :
case V_224 :
V_2 -> V_155 = V_225 ;
V_2 -> V_167 = V_77 ;
V_2 -> V_168 = V_2 -> V_206 = V_226 ;
V_2 -> V_209 = V_227 ;
break;
case V_228 :
V_2 -> V_155 = V_229 ;
V_2 -> V_157 = V_2 -> V_158 = V_230 ;
V_2 -> V_156 = V_231 ;
V_2 -> V_168 = V_2 -> V_206 = V_232 ;
V_2 -> V_209 = V_233 ;
break;
case V_234 :
V_2 -> V_155 = V_229 ;
V_2 -> V_167 = V_77 ;
V_2 -> V_168 = V_2 -> V_206 = V_226 ;
V_2 -> V_209 = V_227 ;
break;
case V_235 :
case V_236 :
V_2 -> V_155 = V_237 ;
if ( V_140 == V_238 &&
V_219 -> V_239 == V_240 ) {
V_2 -> V_156 = V_241 ;
V_2 -> V_167 = V_77 ;
V_2 -> V_168 = V_2 -> V_206 = V_226 ;
V_2 -> V_209 = V_227 ;
} else {
V_2 -> V_157 = V_2 -> V_158 = V_230 ;
V_2 -> V_156 = V_231 ;
if ( V_219 -> V_239 == V_242 ) {
V_2 -> V_168 =
V_2 -> V_206 = V_232 ;
V_2 -> V_209 = V_233 ;
} else {
V_2 -> V_168 =
V_2 -> V_206 = V_243 ;
V_2 -> V_209 = V_244 ;
}
}
break;
default:
F_76 ( 1 ) ;
}
if ( V_2 -> V_155 == V_225 )
F_129 ( V_2 ) ;
else if ( V_2 -> V_155 == V_229 )
F_130 ( V_2 ) ;
else {
F_76 ( V_2 -> V_155 != V_237 ) ;
F_131 ( V_2 ) ;
F_132 ( V_2 ) ;
}
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
}
void
F_135 ( struct V_1 * V_2 , T_6 * V_245 , T_7 V_246 )
{
V_2 -> V_148 . V_247 = V_245 ;
V_2 -> V_148 . V_149 = V_246 ;
V_2 -> V_163 = (struct V_162 * ) V_245 ;
}
void
F_136 ( struct V_1 * V_2 )
{
F_118 ( V_2 , V_248 ) ;
V_2 -> V_216 = V_77 ;
F_9 ( V_2 , V_9 ) ;
}
void
F_137 ( struct V_1 * V_2 )
{
F_118 ( V_2 , V_249 ) ;
F_9 ( V_2 , V_11 ) ;
}
void
F_138 ( struct V_1 * V_2 )
{
V_2 -> V_216 = V_77 ;
F_9 ( V_2 , V_17 ) ;
}
void
F_139 ( struct V_1 * V_2 , void * V_250 )
{
V_2 -> V_250 = V_250 ;
V_2 -> V_251 = V_252 ;
}
void
F_140 ( struct V_1 * V_2 , T_8 * V_253 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
int V_174 ;
for ( V_174 = 0 ; V_174 < V_176 ; V_174 ++ )
V_172 -> V_177 [ V_174 ] . V_18 = V_253 [ V_174 ] ;
}
void
F_141 ( struct V_1 * V_2 , enum V_254 V_174 ,
T_8 V_18 , void * V_98 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
V_172 -> V_177 [ V_174 ] . V_18 = V_18 ;
V_172 -> V_177 [ V_174 ] . V_98 = V_98 ;
}
void
F_142 ( struct V_1 * V_2 , struct V_178 * V_179 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
T_1 V_180 ;
if ( ! F_112 ( & V_172 -> V_175 ) ) {
F_143 ( & V_179 -> V_97 , & V_172 -> V_175 ) ;
return;
}
V_180 = F_28 ( V_2 -> V_62 . V_132 ) ;
if ( V_180 ) {
F_143 ( & V_179 -> V_97 , & V_172 -> V_175 ) ;
return;
}
F_91 ( V_2 , V_179 -> V_181 , sizeof( V_179 -> V_181 ) ) ;
}
void
F_144 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
struct V_200 V_201 ;
int V_174 ;
if ( F_123 ( V_2 , & V_201 ) ) {
V_174 = V_201 . V_137 . V_255 ;
if ( V_174 == V_138 ) {
F_125 ( V_2 , & V_201 ) ;
return;
}
if ( ( V_174 >= V_176 ) || ( V_172 -> V_177 [ V_174 ] . V_18 == NULL ) )
return;
V_172 -> V_177 [ V_174 ] . V_18 ( V_172 -> V_177 [ V_174 ] . V_98 , & V_201 ) ;
}
F_145 ( V_2 ) ;
F_100 ( V_2 ) ;
}
void
F_146 ( struct V_1 * V_2 )
{
F_118 ( V_2 , V_256 ) ;
V_2 -> V_257 . V_150 = V_2 -> V_150 ;
F_9 ( V_2 , V_17 ) ;
}
T_2
F_147 ( struct V_1 * V_2 )
{
return F_121 ( V_2 , V_26 ) ||
F_121 ( V_2 , V_46 ) ;
}
T_2
F_148 ( struct V_1 * V_2 )
{
return F_121 ( V_2 , V_6 ) ||
F_121 ( & V_2 -> V_7 , V_53 ) ||
F_121 ( & V_2 -> V_7 , V_74 ) ;
}
T_2
F_149 ( struct V_1 * V_2 )
{
T_1 V_258 ;
if ( ! F_121 ( V_2 , V_46 ) )
return V_50 ;
V_258 = F_30 ( V_2 ) ;
if ( ! F_150 ( V_258 ) )
return V_50 ;
if ( V_2 -> V_219 . V_222 != V_223 ) {
V_258 = F_30 ( V_2 ) ;
if ( ! F_150 ( V_258 ) )
return V_50 ;
}
return V_77 ;
}
void
F_151 ( struct V_1 * V_2 )
{
F_37 ( V_2 , V_64 ) ;
F_38 ( V_2 , V_64 ) ;
}
void
F_152 ( struct V_1 * V_2 ,
struct V_259 * V_260 )
{
struct V_162 * V_261 ;
V_261 = V_2 -> V_163 ;
F_153 ( V_2 , V_260 -> V_262 ) ;
F_154 ( V_2 , V_260 -> V_263 ) ;
F_155 ( V_2 , V_260 -> V_264 ) ;
F_156 ( V_2 , V_260 -> V_265 ) ;
memcpy ( & V_260 -> V_266 , & V_261 -> V_266 ,
sizeof( struct V_267 ) ) ;
V_260 -> V_268 = F_157 ( V_2 ) ;
V_260 -> V_269 = F_158 ( V_2 ) ;
F_159 ( V_2 , V_260 -> V_270 ) ;
F_159 ( V_2 , V_260 -> V_271 ) ;
V_260 -> V_165 = V_261 -> V_165 ;
V_260 -> V_272 = F_160 ( V_261 -> V_165 ) ;
if ( F_161 ( V_261 -> V_164 ) )
V_260 -> V_273 = 1 ;
else
V_260 -> V_273 = 0 ;
V_260 -> V_274 = V_2 -> V_163 -> V_274 ;
V_260 -> V_275 = F_162 ( V_2 ) ;
V_260 -> V_276 = V_261 -> V_276 ;
V_260 -> V_277 = V_261 -> V_277 ;
V_260 -> V_278 = V_261 -> V_278 ;
V_260 -> V_279 = V_261 -> V_279 ;
F_163 ( V_2 , V_260 -> V_280 ) ;
V_260 -> V_281 = F_164 ( V_2 ) ;
V_260 -> V_282 = ( V_260 -> V_268 > 1 ) &&
! F_164 ( V_2 ) && ! V_260 -> V_272 ;
V_260 -> V_283 = V_261 -> V_283 ;
V_260 -> V_284 = V_261 -> V_284 ;
V_260 -> V_170 = V_261 -> V_170 ;
memcpy ( V_260 -> V_285 , V_261 -> V_285 , V_286 ) ;
}
enum V_287
F_165 ( struct V_1 * V_2 )
{
if ( V_2 -> V_140 == V_288 )
return V_289 ;
F_76 ( V_2 -> V_140 != V_238 ) ;
return ( V_2 -> V_163 -> V_168 == V_169 )
? V_290 : V_291 ;
}
void
F_153 ( struct V_1 * V_2 , char * V_262 )
{
memset ( ( void * ) V_262 , 0 , V_292 ) ;
memcpy ( ( void * ) V_262 ,
( void * ) V_2 -> V_163 -> V_293 ,
V_292 ) ;
}
void
F_154 ( struct V_1 * V_2 , char * V_263 )
{
memset ( ( void * ) V_263 , 0 , V_294 ) ;
memcpy ( V_263 , V_2 -> V_163 -> V_295 , V_294 ) ;
}
void
F_163 ( struct V_1 * V_2 , char * V_296 )
{
F_76 ( ! V_296 ) ;
memset ( ( void * ) V_296 , 0 , V_297 ) ;
V_296 [ 0 ] = 'R' ;
V_296 [ 1 ] = 'e' ;
V_296 [ 2 ] = 'v' ;
V_296 [ 3 ] = '-' ;
V_296 [ 4 ] = V_2 -> V_163 -> V_279 ;
V_296 [ 5 ] = '\0' ;
}
void
F_155 ( struct V_1 * V_2 , char * V_264 )
{
memset ( ( void * ) V_264 , 0 , V_294 ) ;
memcpy ( V_264 , V_2 -> V_163 -> V_298 ,
V_294 ) ;
}
void
F_156 ( struct V_1 * V_2 , char * V_265 )
{
memset ( ( void * ) V_265 , 0 , V_299 ) ;
memcpy ( V_265 , V_300 , V_299 ) ;
}
void
F_159 ( struct V_1 * V_2 , char * V_270 )
{
struct V_162 * V_261 ;
T_6 V_268 = F_157 ( V_2 ) ;
F_76 ( ! V_270 ) ;
memset ( ( void * ) V_270 , 0 , V_301 ) ;
V_261 = V_2 -> V_163 ;
if ( F_166 ( V_2 -> V_219 . V_222 ) &&
( ! F_160 ( V_261 -> V_165 ) ) )
snprintf ( V_270 , V_301 , L_6 ,
V_300 , V_261 -> V_165 , V_268 , L_7 ) ;
else
snprintf ( V_270 , V_301 , L_8 ,
V_300 , V_261 -> V_165 ) ;
}
enum V_302
F_167 ( struct V_1 * V_2 )
{
enum V_303 V_304 ;
enum V_302 V_305 = F_168 ( V_306 , V_2 -> V_307 ) ;
if ( V_305 == V_308 ||
V_305 == V_309 || V_305 == V_310 ) {
V_304 = F_168 ( V_311 , V_2 -> V_7 . V_307 ) ;
switch ( V_304 ) {
case V_312 :
V_305 = V_313 ;
break;
case V_314 :
V_305 = V_315 ;
break;
case V_316 :
V_305 = V_317 ;
break;
case V_318 :
V_305 = V_309 ;
break;
case V_319 :
V_305 = V_310 ;
break;
default:
break;
}
}
return V_305 ;
}
void
F_169 ( struct V_1 * V_2 , struct V_320 * V_261 )
{
memset ( ( void * ) V_261 , 0 , sizeof( struct V_320 ) ) ;
V_261 -> V_321 = F_167 ( V_2 ) ;
V_261 -> V_322 = F_93 ( V_2 ) ;
V_261 -> V_168 = V_2 -> V_168 ;
V_261 -> V_206 = V_2 -> V_206 ;
V_261 -> V_210 = V_2 -> V_209 ;
V_261 -> V_323 = F_165 ( V_2 ) ;
F_152 ( V_2 , & V_261 -> V_324 ) ;
V_261 -> V_325 . V_222 = F_170 ( V_2 ) ;
V_261 -> V_325 . V_326 = F_171 ( V_2 ) ;
V_261 -> V_327 = ( F_171 ( V_2 ) == F_93 ( V_2 ) ) ;
F_163 ( V_2 , V_261 -> V_325 . V_296 ) ;
}
T_9
F_162 ( struct V_1 * V_2 )
{
if ( F_165 ( V_2 ) == V_291 )
return V_2 -> V_163 -> V_328 ;
else
return V_2 -> V_163 -> V_275 ;
}
T_9
F_172 ( struct V_1 * V_2 )
{
T_9 V_201 ;
V_201 = V_2 -> V_163 -> V_329 ;
if ( F_173 ( V_2 -> V_163 -> V_165 ) )
V_201 . V_275 [ V_330 - 1 ] += F_171 ( V_2 ) ;
else
F_174 ( & ( V_201 . V_275 [ V_330 - 3 ] ) ,
F_171 ( V_2 ) ) ;
return V_201 ;
}
void
F_18 ( struct V_1 * V_2 , enum V_331 V_4 )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 -> V_20 -> V_33 ;
struct V_332 * V_333 ;
enum V_287 V_323 ;
F_175 ( V_33 , V_333 ) ;
if ( ! V_333 )
return;
V_323 = F_165 ( V_2 ) ;
switch ( V_323 ) {
case V_290 :
V_333 -> V_334 . V_2 . V_274 = V_2 -> V_163 -> V_274 ;
break;
case V_291 :
V_333 -> V_334 . V_2 . V_274 = V_2 -> V_163 -> V_274 ;
V_333 -> V_334 . V_2 . V_275 = F_162 ( V_2 ) ;
break;
case V_289 :
V_333 -> V_334 . V_2 . V_275 = F_162 ( V_2 ) ;
break;
default:
F_76 ( V_323 != V_290 ) ;
break;
}
V_333 -> V_334 . V_2 . V_323 = V_323 ;
F_176 ( V_333 , V_33 , ++ V_2 -> V_335 ,
V_336 , V_4 ) ;
}
T_4
F_177 ( struct V_1 * V_2 , void * V_337 , int * V_338 )
{
int V_339 ;
if ( V_2 -> V_251 == 0 )
return V_340 ;
V_339 = * V_338 ;
if ( V_339 > V_2 -> V_251 )
V_339 = V_2 -> V_251 ;
memcpy ( V_337 , V_2 -> V_250 , V_339 ) ;
* V_338 = V_339 ;
return V_34 ;
}
T_4
F_178 ( struct V_1 * V_2 , void * V_337 , int * V_338 )
{
T_1 V_60 = F_179 ( F_93 ( V_2 ) ) ;
int V_339 ;
T_4 V_341 ;
F_3 ( V_2 , * V_338 ) ;
V_339 = * V_338 ;
if ( V_339 > V_252 )
V_339 = V_252 ;
V_341 = F_114 ( V_2 , V_337 , V_60 , V_339 ) ;
* V_338 = V_339 ;
return V_341 ;
}
static void
F_180 ( struct V_1 * V_2 )
{
struct V_178 V_179 ;
struct V_133 * V_342 = (struct V_133 * ) V_179 . V_181 ;
F_92 ( V_342 -> V_137 , V_138 , V_343 ,
F_93 ( V_2 ) ) ;
V_342 -> V_140 = F_94 ( V_2 -> V_140 ) ;
F_142 ( V_2 , & V_179 ) ;
}
static void
F_181 ( struct V_1 * V_2 )
{
T_1 V_344 = 1000 ;
F_180 ( V_2 ) ;
while ( F_182 ( V_2 ) && V_344 > 0 )
V_344 -- ;
}
T_4
F_183 ( struct V_1 * V_2 , void * V_185 ,
T_1 * V_345 , int * V_346 )
{
T_1 V_60 ;
int V_347 ;
T_4 V_341 ;
T_1 V_348 = F_184 ( V_2 ) ;
if ( * V_345 >= V_348 ) {
* V_345 = * V_346 = 0 ;
return V_349 ;
}
V_60 = * V_345 ;
V_347 = * V_346 ;
if ( V_60 == 0 )
F_181 ( V_2 ) ;
if ( ( V_60 + V_347 ) >= V_348 )
V_347 = V_348 - V_60 ;
V_341 = F_114 ( V_2 , V_185 , V_60 , V_347 ) ;
if ( V_341 != V_34 ) {
* V_345 = * V_346 = 0 ;
return V_341 ;
}
* V_345 += V_347 ;
if ( * V_345 >= V_348 )
* V_345 = 0 ;
* V_346 = V_347 ;
return V_341 ;
}
T_4
F_185 ( struct V_1 * V_2 , void * V_257 )
{
T_1 V_60 = V_350 + \
V_351 * ( F_93 ( V_2 ) ) ;
int V_339 ;
T_4 V_341 ;
if ( V_2 -> V_352 ) {
F_3 ( V_2 , V_2 -> V_352 ) ;
return V_353 ;
}
V_2 -> V_352 = V_77 ;
V_339 = sizeof( struct V_354 ) ;
V_341 = F_114 ( V_2 , V_257 , V_60 , V_339 ) ;
V_2 -> V_352 = V_50 ;
return V_341 ;
}
T_4
F_186 ( struct V_1 * V_2 )
{
T_1 V_60 = V_350 + \
V_351 * ( F_93 ( V_2 ) ) ;
int V_339 ;
T_4 V_341 ;
if ( V_2 -> V_352 ) {
F_3 ( V_2 , V_2 -> V_352 ) ;
return V_353 ;
}
V_2 -> V_352 = V_77 ;
V_339 = sizeof( struct V_354 ) ;
V_341 = F_115 ( V_2 , V_60 , V_339 ) ;
V_2 -> V_352 = V_50 ;
return V_341 ;
}
void
F_66 ( struct V_1 * V_2 )
{
int V_339 ;
if ( V_2 -> V_216 ) {
V_2 -> V_216 = V_50 ;
if ( V_2 -> V_251 ) {
V_339 = V_2 -> V_251 ;
F_178 ( V_2 , V_2 -> V_250 , & V_339 ) ;
}
}
}
static void
F_99 ( struct V_1 * V_2 )
{
F_118 ( V_2 , V_256 ) ;
V_2 -> V_257 . V_150 = V_2 -> V_150 ;
F_9 ( V_2 , V_39 ) ;
}
static void
F_187 ( void * V_126 )
{
struct V_1 * V_2 = (struct V_1 * ) V_126 ;
F_3 ( V_2 , 0 ) ;
F_9 ( & V_2 -> V_7 , V_78 ) ;
}
static void
F_188 ( void * V_126 )
{
struct V_1 * V_2 = (struct V_1 * ) V_126 ;
F_40 ( V_2 ) ;
}
static void
F_89 ( struct V_1 * V_2 )
{
T_1 V_57 = F_30 ( V_2 ) ;
F_3 ( V_2 , V_57 ) ;
if ( V_57 == V_124 ) {
F_9 ( & V_2 -> V_7 , V_81 ) ;
return;
}
if ( V_2 -> V_7 . V_80 >= ( 3 * V_355 ) )
F_187 ( V_2 ) ;
else {
V_2 -> V_7 . V_80 += V_356 ;
F_189 ( V_2 ) ;
}
}
static void
F_190 ( void * V_126 )
{
struct V_1 * V_2 = (struct V_1 * ) V_126 ;
F_89 ( V_2 ) ;
}
void
F_191 ( struct V_214 * V_172 )
{
struct V_96 * V_357 = & V_172 -> V_358 ;
struct V_96 * V_97 , * V_359 ;
struct V_360 * V_361 ;
struct V_96 V_362 ;
F_111 ( & V_362 ) ;
V_97 = F_192 ( V_357 ) ;
while ( V_97 != V_357 ) {
V_359 = F_192 ( V_97 ) ;
V_361 = (struct V_360 * ) V_97 ;
if ( V_361 -> V_363 <= V_364 ) {
V_361 -> V_363 = 0 ;
F_193 ( & V_361 -> V_97 ) ;
F_143 ( & V_361 -> V_97 , & V_362 ) ;
} else {
V_361 -> V_363 -= V_364 ;
}
V_97 = V_359 ;
}
while ( ! F_112 ( & V_362 ) ) {
F_113 ( & V_362 , & V_361 ) ;
V_361 -> V_365 ( V_361 -> V_366 ) ;
}
}
void
F_194 ( struct V_214 * V_172 , struct V_360 * V_367 ,
void (* V_365) ( void * ) , void * V_366 , unsigned int V_363 )
{
F_76 ( V_365 == NULL ) ;
F_76 ( F_195 ( & V_172 -> V_358 , V_367 ) ) ;
V_367 -> V_363 = V_363 ;
V_367 -> V_365 = V_365 ;
V_367 -> V_366 = V_366 ;
F_143 ( & V_367 -> V_97 , & V_172 -> V_358 ) ;
}
void
F_196 ( struct V_360 * V_367 )
{
F_76 ( F_112 ( & V_367 -> V_97 ) ) ;
F_193 ( & V_367 -> V_97 ) ;
}
static void
F_197 ( struct V_368 * V_369 )
{
struct V_370 * V_371 ;
int V_61 , V_372 ;
T_10 V_373 ;
for ( V_61 = 0 ; V_61 < V_374 ; V_61 ++ ) {
V_371 = & V_369 -> V_375 [ V_61 ] ;
for ( V_372 = 0 ; V_372 < V_376 ; V_372 ++ ) {
V_373 = V_371 -> V_377 [ V_372 ] . V_378 ;
V_371 -> V_377 [ V_372 ] . V_378 = F_109 ( V_373 ) ;
V_373 = V_371 -> V_377 [ V_372 ] . V_379 ;
V_371 -> V_377 [ V_372 ] . V_379 = F_109 ( V_373 ) ;
V_373 = V_371 -> V_377 [ V_372 ] . V_380 ;
V_371 -> V_377 [ V_372 ] . V_380 = F_109 ( V_373 ) ;
V_373 = V_371 -> V_377 [ V_372 ] . V_381 ;
V_371 -> V_377 [ V_372 ] . V_381 = F_109 ( V_373 ) ;
V_373 = V_371 -> V_377 [ V_372 ] . V_382 ;
V_371 -> V_377 [ V_372 ] . V_382 = F_109 ( V_373 ) ;
}
}
}
static void
F_198 ( void * V_98 , struct V_200 * V_181 )
{
struct V_383 * V_384 = (struct V_383 * ) V_98 ;
struct V_385 * V_386 = (struct V_385 * ) V_181 ;
T_11 V_18 ;
F_76 ( V_181 -> V_137 . V_255 != V_387 ) ;
F_3 ( V_384 -> V_2 , V_181 -> V_137 . V_203 ) ;
switch ( V_181 -> V_137 . V_203 ) {
case V_388 :
if ( V_386 -> V_341 == V_34 ) {
memcpy ( V_384 -> V_369 , V_384 -> V_389 . V_247 ,
sizeof( struct V_368 ) ) ;
F_197 ( V_384 -> V_369 ) ;
V_384 -> V_369 = NULL ;
}
break;
case V_390 :
case V_391 :
V_384 -> V_2 -> V_206 = V_386 -> V_168 ;
case V_392 :
case V_393 :
case V_394 :
case V_395 :
break;
case V_396 :
* ( V_384 -> V_326 ) = V_386 -> V_326 ;
V_384 -> V_326 = NULL ;
break;
default:
F_76 ( 1 ) ;
}
V_384 -> V_397 = V_50 ;
if ( V_384 -> V_18 ) {
V_18 = V_384 -> V_18 ;
V_384 -> V_18 = NULL ;
V_18 ( V_384 -> V_98 , V_386 -> V_341 ) ;
}
}
static void
F_199 ( void * V_98 , enum V_93 V_4 )
{
struct V_383 * V_384 = (struct V_383 * ) V_98 ;
F_3 ( V_384 -> V_2 , V_4 ) ;
switch ( V_4 ) {
case V_35 :
F_76 ( V_384 -> V_397 != V_50 ) ;
break;
case V_99 :
case V_188 :
V_384 -> V_326 = NULL ;
if ( V_384 -> V_397 ) {
if ( V_384 -> V_18 )
V_384 -> V_18 ( V_384 -> V_98 , V_186 ) ;
V_384 -> V_18 = NULL ;
V_384 -> V_397 = V_50 ;
}
break;
default:
F_76 ( 1 ) ;
break;
}
}
T_1
F_200 ( void )
{
return F_201 ( sizeof( struct V_368 ) , V_398 ) ;
}
void
F_202 ( struct V_383 * V_384 , T_6 * V_399 , T_7 V_400 )
{
V_384 -> V_389 . V_247 = V_399 ;
V_384 -> V_389 . V_149 = V_400 ;
}
void
F_203 ( struct V_383 * V_384 , struct V_1 * V_2 )
{
V_384 -> V_2 = V_2 ;
F_141 ( V_384 -> V_2 , V_387 , F_198 , V_384 ) ;
F_204 ( & V_384 -> V_401 ) ;
F_205 ( & V_384 -> V_401 , F_199 , V_384 ) ;
F_143 ( & V_384 -> V_401 . V_97 , & V_384 -> V_2 -> V_217 ) ;
}
T_4
F_206 ( struct V_383 * V_384 , struct V_368 * V_402 ,
T_11 V_18 , void * V_98 )
{
struct V_403 * V_201 ;
F_76 ( ! V_402 ) ;
if ( ! F_120 ( V_384 -> V_2 ) ) {
F_3 ( V_384 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_384 -> V_397 ) {
F_3 ( V_384 -> V_2 , V_353 ) ;
return V_353 ;
}
V_384 -> V_369 = V_402 ;
V_384 -> V_18 = V_18 ;
V_384 -> V_98 = V_98 ;
V_384 -> V_397 = V_77 ;
V_201 = (struct V_403 * ) V_384 -> V_404 . V_181 ;
F_92 ( V_201 -> V_137 , V_387 , V_405 ,
F_93 ( V_384 -> V_2 ) ) ;
F_97 ( V_201 -> V_406 , V_384 -> V_389 . V_149 ) ;
F_142 ( V_384 -> V_2 , & V_384 -> V_404 ) ;
return V_34 ;
}
T_4
F_207 ( struct V_383 * V_384 , T_10 * V_326 ,
T_6 V_407 , enum V_220 V_408 ,
T_10 V_381 , T_10 V_382 ,
T_11 V_18 , void * V_98 )
{
struct V_409 * V_201 ;
if ( ! F_120 ( V_384 -> V_2 ) ) {
F_3 ( V_384 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_384 -> V_397 ) {
F_3 ( V_384 -> V_2 , V_353 ) ;
return V_353 ;
}
V_384 -> V_326 = V_326 ;
V_384 -> V_18 = V_18 ;
V_384 -> V_98 = V_98 ;
V_384 -> V_397 = V_77 ;
V_201 = (struct V_409 * ) V_384 -> V_404 . V_181 ;
F_92 ( V_201 -> V_137 , V_387 , V_410 ,
F_93 ( V_384 -> V_2 ) ) ;
V_201 -> V_378 = F_94 ( ( T_10 ) V_408 ) ;
V_201 -> V_381 = F_94 ( V_381 ) ;
V_201 -> V_382 = F_94 ( V_382 ) ;
V_201 -> V_407 = V_407 ;
F_142 ( V_384 -> V_2 , & V_384 -> V_404 ) ;
return V_34 ;
}
T_4
F_208 ( struct V_383 * V_384 , int V_326 ,
T_11 V_18 , void * V_98 )
{
struct V_409 * V_201 ;
if ( ! F_120 ( V_384 -> V_2 ) ) {
F_3 ( V_384 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_384 -> V_397 ) {
F_3 ( V_384 -> V_2 , V_353 ) ;
return V_353 ;
}
V_384 -> V_18 = V_18 ;
V_384 -> V_98 = V_98 ;
V_384 -> V_397 = V_77 ;
V_201 = (struct V_409 * ) V_384 -> V_404 . V_181 ;
F_92 ( V_201 -> V_137 , V_387 , V_411 ,
F_93 ( V_384 -> V_2 ) ) ;
V_201 -> V_326 = ( T_6 ) V_326 ;
F_142 ( V_384 -> V_2 , & V_384 -> V_404 ) ;
return V_34 ;
}
T_4
F_209 ( struct V_383 * V_384 , enum V_207 V_412 ,
int V_413 , int V_414 , T_11 V_18 , void * V_98 )
{
struct V_415 * V_201 ;
if ( ! F_120 ( V_384 -> V_2 ) ) {
F_3 ( V_384 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_384 -> V_397 ) {
F_3 ( V_384 -> V_2 , V_353 ) ;
return V_353 ;
}
V_384 -> V_18 = V_18 ;
V_384 -> V_98 = V_98 ;
V_384 -> V_397 = V_77 ;
V_201 = (struct V_415 * ) V_384 -> V_404 . V_181 ;
F_92 ( V_201 -> V_137 , V_387 , V_416 ,
F_93 ( V_384 -> V_2 ) ) ;
V_201 -> V_412 = ( T_6 ) V_412 ;
V_201 -> V_413 = ( T_6 ) V_413 ;
V_201 -> V_414 = ( T_6 ) V_414 ;
F_142 ( V_384 -> V_2 , & V_384 -> V_404 ) ;
return V_34 ;
}
T_4
F_210 ( struct V_383 * V_384 , int V_407 , enum V_207 V_412 ,
int V_413 , int V_414 , T_11 V_18 , void * V_98 )
{
struct V_415 * V_201 ;
if ( ! F_120 ( V_384 -> V_2 ) ) {
F_3 ( V_384 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_384 -> V_397 ) {
F_3 ( V_384 -> V_2 , V_353 ) ;
return V_353 ;
}
V_384 -> V_18 = V_18 ;
V_384 -> V_98 = V_98 ;
V_384 -> V_397 = V_77 ;
V_201 = (struct V_415 * ) V_384 -> V_404 . V_181 ;
F_92 ( V_201 -> V_137 , V_387 , V_417 ,
F_93 ( V_384 -> V_2 ) ) ;
V_201 -> V_407 = ( T_6 ) V_407 ;
V_201 -> V_412 = ( T_6 ) V_412 ;
V_201 -> V_413 = ( T_6 ) V_413 ;
V_201 -> V_414 = ( T_6 ) V_414 ;
F_142 ( V_384 -> V_2 , & V_384 -> V_404 ) ;
return V_34 ;
}
T_4
F_211 ( struct V_383 * V_384 , int V_326 , T_10 V_381 ,
T_10 V_382 , T_11 V_18 , void * V_98 )
{
struct V_409 * V_201 ;
if ( ! F_120 ( V_384 -> V_2 ) ) {
F_3 ( V_384 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_384 -> V_397 ) {
F_3 ( V_384 -> V_2 , V_353 ) ;
return V_353 ;
}
V_384 -> V_18 = V_18 ;
V_384 -> V_98 = V_98 ;
V_384 -> V_397 = V_77 ;
V_201 = (struct V_409 * ) V_384 -> V_404 . V_181 ;
F_92 ( V_201 -> V_137 , V_387 , V_418 ,
F_93 ( V_384 -> V_2 ) ) ;
V_201 -> V_326 = ( T_6 ) V_326 ;
V_201 -> V_381 = F_94 ( V_381 ) ;
V_201 -> V_382 = F_94 ( V_382 ) ;
F_142 ( V_384 -> V_2 , & V_384 -> V_404 ) ;
return V_34 ;
}
T_4
F_212 ( struct V_383 * V_384 , T_11 V_18 , void * V_98 )
{
struct V_419 * V_201 ;
if ( ! F_120 ( V_384 -> V_2 ) ) {
F_3 ( V_384 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_384 -> V_397 ) {
F_3 ( V_384 -> V_2 , V_353 ) ;
return V_353 ;
}
V_384 -> V_18 = V_18 ;
V_384 -> V_98 = V_98 ;
V_384 -> V_397 = V_77 ;
V_201 = (struct V_419 * ) V_384 -> V_404 . V_181 ;
F_92 ( V_201 -> V_137 , V_387 , V_420 ,
F_93 ( V_384 -> V_2 ) ) ;
F_142 ( V_384 -> V_2 , & V_384 -> V_404 ) ;
return V_34 ;
}
T_4
F_213 ( struct V_383 * V_384 , T_11 V_18 , void * V_98 )
{
struct V_419 * V_201 ;
if ( ! F_120 ( V_384 -> V_2 ) ) {
F_3 ( V_384 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_384 -> V_397 ) {
F_3 ( V_384 -> V_2 , V_353 ) ;
return V_353 ;
}
V_384 -> V_18 = V_18 ;
V_384 -> V_98 = V_98 ;
V_384 -> V_397 = V_77 ;
V_201 = (struct V_419 * ) V_384 -> V_404 . V_181 ;
F_92 ( V_201 -> V_137 , V_387 , V_421 ,
F_93 ( V_384 -> V_2 ) ) ;
F_142 ( V_384 -> V_2 , & V_384 -> V_404 ) ;
return V_34 ;
}
static void
F_214 ( struct V_422 * V_423 )
{
F_3 ( V_423 , V_423 -> V_424 ) ;
if ( V_423 -> V_18 )
V_423 -> V_18 ( V_423 -> V_98 , V_423 -> V_341 ) ;
V_423 -> V_424 = 0 ;
V_423 -> V_18 = NULL ;
}
static void
F_215 ( struct V_422 * V_423 )
{
F_3 ( V_423 , V_423 -> V_425 ) ;
if ( V_423 -> V_426 ) {
F_216 ( V_423 ) ;
if ( V_423 -> V_427 )
V_423 -> V_427 ( V_423 -> V_428 ,
V_423 -> V_341 ) ;
V_423 -> V_426 = NULL ;
}
if ( V_423 -> V_425 ) {
V_423 -> V_341 = F_217 ( V_423 , V_423 -> V_425 ) ;
if ( V_423 -> V_427 )
V_423 -> V_427 ( V_423 -> V_428 ,
V_423 -> V_341 ) ;
V_423 -> V_425 = V_429 ;
}
V_423 -> V_430 = 0 ;
V_423 -> V_427 = NULL ;
}
static void
F_218 ( void * V_431 , enum V_93 V_4 )
{
struct V_422 * V_423 = V_431 ;
F_3 ( V_423 , V_4 ) ;
F_3 ( V_423 , V_423 -> V_424 ) ;
F_3 ( V_423 , V_423 -> V_430 ) ;
switch ( V_4 ) {
case V_99 :
case V_188 :
if ( V_423 -> V_424 ) {
V_423 -> V_341 = V_21 ;
F_214 ( V_423 ) ;
}
if ( V_423 -> V_430 ) {
V_423 -> V_341 = V_21 ;
F_215 ( V_423 ) ;
}
break;
default:
break;
}
}
static void
F_219 ( struct V_422 * V_423 , struct V_432 * V_386 )
{
struct V_32 * V_33 = (struct V_32 * ) V_423 -> V_2 -> V_20 -> V_33 ;
struct V_332 * V_333 ;
enum V_433 V_434 = 0 ;
F_3 ( V_423 , ( ( ( T_7 ) V_386 -> V_435 ) << 16 ) | ( ( ( T_7 ) V_386 -> V_436 ) << 8 ) |
( ( T_7 ) V_386 -> V_4 ) ) ;
F_175 ( V_33 , V_333 ) ;
if ( ! V_333 )
return;
V_333 -> V_334 . V_407 . V_323 = F_165 ( V_423 -> V_2 ) ;
V_333 -> V_334 . V_407 . V_274 = V_423 -> V_2 -> V_163 -> V_274 ;
V_333 -> V_334 . V_407 . V_275 = F_162 ( V_423 -> V_2 ) ;
switch ( V_386 -> V_4 ) {
case V_437 :
V_434 = V_438 ;
break;
case V_439 :
V_434 = V_440 ;
break;
case V_441 :
V_434 = V_442 ;
break;
case V_443 :
V_434 = V_444 ;
break;
case V_445 :
V_434 = V_446 ;
V_333 -> V_334 . V_407 . V_447 = V_386 -> V_435 ;
break;
default:
F_3 ( V_423 , V_386 -> V_4 ) ;
F_76 ( 1 ) ;
}
F_176 ( V_333 , V_33 , ++ V_423 -> V_2 -> V_335 ,
V_448 , V_434 ) ;
}
static void
F_220 ( struct V_422 * V_423 )
{
struct V_449 * V_342 = (struct V_449 * ) V_423 -> V_450 . V_181 ;
F_3 ( V_423 , V_342 -> V_451 ) ;
F_92 ( V_342 -> V_137 , V_452 , V_453 ,
F_93 ( V_423 -> V_2 ) ) ;
F_142 ( V_423 -> V_2 , & V_423 -> V_450 ) ;
}
static void
F_221 ( struct V_422 * V_423 , enum V_454 V_451 )
{
struct V_449 * V_342 = (struct V_449 * ) V_423 -> V_450 . V_181 ;
F_76 ( V_423 -> V_424 != 0 ) ;
F_3 ( V_423 , V_423 -> V_321 ) ;
V_423 -> V_424 = 1 ;
V_423 -> V_451 = V_451 ;
V_342 -> V_451 = V_451 ;
F_222 ( & V_342 -> V_455 , sizeof( struct V_456 ) , V_423 -> V_457 ) ;
F_220 ( V_423 ) ;
}
static void
F_223 ( struct V_422 * V_423 , struct V_200 * V_181 )
{
struct V_432 * V_386 = (struct V_432 * ) V_181 ;
switch ( V_386 -> V_4 ) {
case V_437 :
V_423 -> V_321 = V_458 ;
V_423 -> V_459 = 0 ;
F_219 ( V_423 , V_386 ) ;
break;
case V_439 :
V_423 -> V_321 = V_460 ;
V_423 -> V_459 = 0 ;
F_219 ( V_423 , V_386 ) ;
break;
case V_441 :
V_423 -> V_321 = V_461 ;
V_423 -> V_459 = 0 ;
F_219 ( V_423 , V_386 ) ;
break;
case V_443 :
V_423 -> V_321 = V_462 ;
F_219 ( V_423 , V_386 ) ;
if ( ! V_423 -> V_424 )
F_221 ( V_423 , V_463 ) ;
break;
case V_445 :
F_219 ( V_423 , V_386 ) ;
break;
case V_464 :
V_423 -> V_321 = V_465 ;
if ( ! V_423 -> V_424 )
F_221 ( V_423 , V_463 ) ;
break;
default:
F_3 ( V_423 , V_386 -> V_4 ) ;
F_76 ( 1 ) ;
}
}
static void
F_224 ( struct V_422 * V_423 , struct V_200 * V_181 )
{
struct V_466 * V_386 = (struct V_466 * ) V_181 ;
if ( ! V_423 -> V_424 ) {
F_3 ( V_423 , V_423 -> V_424 ) ;
return;
}
F_3 ( V_423 , V_386 -> V_341 ) ;
if ( V_386 -> V_341 == V_34 ) {
V_423 -> V_459 = 1 ;
if ( V_423 -> V_321 == V_465 )
V_423 -> V_341 = V_34 ;
else if ( V_423 -> V_321 == V_462 )
V_423 -> V_341 = V_467 ;
else
F_3 ( V_423 , V_423 -> V_321 ) ;
} else {
V_423 -> V_459 = 0 ;
V_423 -> V_341 = V_386 -> V_341 ;
}
F_3 ( V_423 , V_423 -> V_451 ) ;
if ( V_423 -> V_451 == V_468 ) {
F_3 ( V_423 , V_423 -> V_459 ) ;
if ( V_423 -> V_459 ) {
T_1 V_469 = sizeof( struct V_456 ) ;
T_6 * V_470 = ( T_6 * ) & ( V_423 -> V_471 -> V_472 ) ;
memcpy ( V_470 , V_423 -> V_473 , V_469 ) ;
}
F_214 ( V_423 ) ;
} else
V_423 -> V_424 = 0 ;
F_3 ( V_423 , V_423 -> V_430 ) ;
if ( V_423 -> V_430 ) {
V_423 -> V_321 = V_386 -> V_321 ;
F_215 ( V_423 ) ;
}
}
static void
F_225 ( struct V_422 * V_423 )
{
struct V_449 * V_342 = (struct V_449 * ) V_423 -> V_450 . V_181 ;
F_76 ( V_423 -> V_321 != V_474 ) ;
F_76 ( V_423 -> V_430 != 0 ) ;
F_3 ( V_423 , V_423 -> V_321 ) ;
V_423 -> V_430 = 1 ;
V_342 -> V_451 = 0 ;
if ( ! V_423 -> V_424 )
F_221 ( V_423 , V_463 ) ;
}
static void
F_216 ( struct V_422 * V_423 )
{
enum V_475 * V_426 = V_423 -> V_426 ;
* V_426 = V_476 ;
if ( V_423 -> V_321 == V_462 )
* V_426 = V_477 ;
else if ( V_423 -> V_321 == V_465 ) {
union V_478 V_479 ;
struct V_456 * V_471 = (struct V_456 * ) V_423 -> V_473 ;
T_10 V_480 = ( V_471 -> V_472 . V_481 [ 4 ] & 0x3 ) << 7 |
( V_471 -> V_472 . V_481 [ 5 ] >> 1 ) ;
V_479 . V_482 = V_471 -> V_472 . V_481 [ 0 ] ;
F_3 ( V_423 , V_479 . V_482 ) ;
F_3 ( V_423 , V_480 ) ;
if ( ( V_480 & V_483 ) ||
( V_480 & V_484 ) ||
( V_480 & V_485 ) )
* V_426 = V_486 ;
else if ( ( V_480 & V_487 ) ||
( V_480 & V_488 ) )
* V_426 = V_489 ;
else if ( ( V_480 & V_490 ) ||
( V_480 & V_491 ) )
* V_426 = V_492 ;
else if ( ( V_480 & V_493 ) ||
( V_480 & V_494 ) ||
( V_480 & V_495 ) )
* V_426 = V_496 ;
else if ( V_479 . V_497 . V_498 )
* V_426 = V_496 ;
else if ( V_479 . V_497 . V_499 && V_479 . V_497 . V_500 )
* V_426 = V_492 ;
else if ( V_479 . V_497 . V_501 )
* V_426 = V_476 ;
else
F_3 ( V_423 , 0 ) ;
} else
F_3 ( V_423 , V_423 -> V_321 ) ;
}
static T_4
F_217 ( struct V_422 * V_423 , enum V_502 V_425 )
{
struct V_456 * V_471 = (struct V_456 * ) V_423 -> V_473 ;
struct V_503 * V_481 = (struct V_503 * ) V_471 -> V_472 . V_481 ;
union V_504 V_505 = V_481 -> V_505 ;
union V_478 V_479 = V_481 -> V_479 ;
if ( V_425 == V_506 ) {
if ( V_479 . V_497 . V_498 || V_479 . V_497 . V_500 )
return V_34 ;
else {
F_3 ( V_423 , V_479 . V_482 ) ;
return V_507 ;
}
}
if ( ( ( V_425 & V_508 ) && V_505 . V_497 . V_509 ) ||
( ( V_425 & V_510 ) && V_505 . V_497 . V_511 ) ||
( ( V_425 & V_512 ) && V_505 . V_497 . V_513 ) ||
( ( V_425 & V_514 ) && V_505 . V_497 . V_515 ) ||
( ( V_425 & V_516 ) && V_505 . V_497 . V_517 ) )
return V_34 ;
else {
F_3 ( V_423 , V_425 ) ;
F_3 ( V_423 , V_505 . V_482 ) ;
F_3 ( V_423 , V_479 . V_482 ) ;
return V_507 ;
}
}
void
F_226 ( void * V_518 , struct V_200 * V_181 )
{
struct V_422 * V_423 = V_518 ;
switch ( V_181 -> V_137 . V_203 ) {
case V_519 :
F_224 ( V_423 , V_181 ) ;
break;
case V_520 :
F_223 ( V_423 , V_181 ) ;
break;
default:
F_3 ( V_423 , V_181 -> V_137 . V_203 ) ;
F_76 ( 1 ) ;
}
}
T_1
F_227 ( void )
{
return F_201 ( sizeof( struct V_456 ) , V_398 ) ;
}
void
F_228 ( struct V_422 * V_423 , struct V_1 * V_2 , void * V_521 ,
struct V_522 * V_523 )
{
V_423 -> V_521 = V_521 ;
V_423 -> V_2 = V_2 ;
V_423 -> V_523 = V_523 ;
V_423 -> V_18 = NULL ;
V_423 -> V_98 = NULL ;
V_423 -> V_471 = NULL ;
V_423 -> V_424 = 0 ;
V_423 -> V_459 = 0 ;
V_423 -> V_321 = V_474 ;
V_423 -> V_430 = 0 ;
V_423 -> V_427 = NULL ;
V_423 -> V_428 = NULL ;
V_423 -> V_426 = NULL ;
V_423 -> V_425 = V_429 ;
V_423 -> V_524 = V_50 ;
F_141 ( V_423 -> V_2 , V_452 , F_226 , V_423 ) ;
F_204 ( & V_423 -> V_401 ) ;
F_205 ( & V_423 -> V_401 , F_218 , V_423 ) ;
F_143 ( & V_423 -> V_401 . V_97 , & V_423 -> V_2 -> V_217 ) ;
}
void
F_229 ( struct V_422 * V_423 , T_6 * V_245 , T_7 V_246 )
{
V_423 -> V_473 = V_245 ;
V_423 -> V_457 = V_246 ;
memset ( V_423 -> V_473 , 0 , sizeof( struct V_456 ) ) ;
V_245 += F_201 ( sizeof( struct V_456 ) , V_398 ) ;
V_246 += F_201 ( sizeof( struct V_456 ) , V_398 ) ;
}
T_4
F_230 ( struct V_422 * V_423 , struct V_456 * V_471 ,
T_12 V_18 , void * V_98 )
{
if ( ! F_120 ( V_423 -> V_2 ) ) {
F_3 ( V_423 , 0 ) ;
return V_525 ;
}
if ( V_423 -> V_424 ) {
F_3 ( V_423 , 0 ) ;
return V_353 ;
}
V_423 -> V_18 = V_18 ;
V_423 -> V_98 = V_98 ;
V_423 -> V_471 = V_471 ;
F_221 ( V_423 , V_468 ) ;
return V_34 ;
}
T_4
F_231 ( struct V_422 * V_423 , enum V_475 * V_426 ,
T_12 V_18 , void * V_98 )
{
if ( ! F_120 ( V_423 -> V_2 ) ) {
F_3 ( V_423 , 0 ) ;
return V_525 ;
}
V_423 -> V_426 = V_426 ;
if ( V_423 -> V_321 == V_474 ) {
if ( V_423 -> V_430 ) {
F_3 ( V_423 , 0 ) ;
return V_353 ;
} else {
V_423 -> V_427 = V_18 ;
V_423 -> V_428 = V_98 ;
F_225 ( V_423 ) ;
return V_526 ;
}
}
F_216 ( V_423 ) ;
return V_34 ;
}
T_4
F_232 ( struct V_422 * V_423 , enum V_502 V_425 ,
T_12 V_18 , void * V_98 )
{
F_76 ( V_425 == V_429 ) ;
if ( ! F_120 ( V_423 -> V_2 ) )
return V_525 ;
if ( F_160 ( V_423 -> V_2 -> V_163 -> V_165 ) )
return V_34 ;
V_423 -> V_425 = V_425 ;
if ( V_423 -> V_321 == V_474 ) {
if ( V_423 -> V_430 ) {
F_3 ( V_423 , 0 ) ;
return V_353 ;
} else {
V_423 -> V_427 = V_18 ;
V_423 -> V_428 = V_98 ;
F_225 ( V_423 ) ;
return V_526 ;
}
}
if ( V_423 -> V_321 == V_460 ||
V_423 -> V_321 == V_461 ) {
F_3 ( V_423 , V_423 -> V_321 ) ;
return V_527 ;
}
if ( V_423 -> V_321 == V_458 ) {
F_3 ( V_423 , V_423 -> V_321 ) ;
return V_353 ;
}
if ( V_423 -> V_524 )
return V_34 ;
return F_217 ( V_423 , V_425 ) ;
}
static void
F_233 ( struct V_1 * V_2 , enum V_528 V_4 ,
int V_375 , int type )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 -> V_20 -> V_33 ;
struct V_332 * V_333 ;
F_175 ( V_33 , V_333 ) ;
if ( ! V_333 )
return;
V_333 -> V_334 . V_529 . V_274 = V_2 -> V_163 -> V_274 ;
V_333 -> V_334 . V_529 . V_530 = V_375 ;
V_333 -> V_334 . V_529 . V_531 = type ;
F_176 ( V_333 , V_33 , ++ V_2 -> V_335 ,
V_532 , V_4 ) ;
}
static void
F_234 ( struct V_533 * V_534 )
{
V_534 -> V_535 = 0 ;
if ( V_534 -> V_18 )
V_534 -> V_18 ( V_534 -> V_98 , V_534 -> V_341 ) ;
}
static void
F_235 ( void * V_98 , enum V_93 V_4 )
{
struct V_533 * V_534 = V_98 ;
F_3 ( V_534 , V_4 ) ;
switch ( V_4 ) {
case V_99 :
case V_188 :
if ( V_534 -> V_535 ) {
V_534 -> V_341 = V_21 ;
V_534 -> V_18 ( V_534 -> V_98 , V_534 -> V_341 ) ;
V_534 -> V_535 = 0 ;
}
break;
default:
break;
}
}
static void
F_236 ( void * V_98 )
{
struct V_533 * V_534 = V_98 ;
struct V_536 * V_181 =
(struct V_536 * ) V_534 -> V_404 . V_181 ;
F_92 ( V_181 -> V_137 , V_537 , V_538 ,
F_93 ( V_534 -> V_2 ) ) ;
F_222 ( & V_181 -> V_455 , sizeof( struct V_539 ) ,
V_534 -> V_457 ) ;
F_142 ( V_534 -> V_2 , & V_534 -> V_404 ) ;
}
static void
F_237 ( struct V_533 * V_534 )
{
struct V_540 * V_181 =
(struct V_540 * ) V_534 -> V_404 . V_181 ;
T_1 V_128 ;
V_181 -> type = F_96 ( V_534 -> type ) ;
V_181 -> V_541 = V_534 -> V_541 ;
V_181 -> V_345 = F_96 ( V_534 -> V_542 + V_534 -> V_345 ) ;
V_128 = ( V_534 -> V_543 < V_544 ) ?
V_534 -> V_543 : V_544 ;
V_181 -> V_545 = F_96 ( V_128 ) ;
V_181 -> V_546 = ( V_128 == V_534 -> V_543 ) ? 1 : 0 ;
F_92 ( V_181 -> V_137 , V_537 , V_547 ,
F_93 ( V_534 -> V_2 ) ) ;
F_222 ( & V_181 -> V_455 , V_128 , V_534 -> V_457 ) ;
memcpy ( V_534 -> V_473 , V_534 -> V_548 + V_534 -> V_345 , V_128 ) ;
F_142 ( V_534 -> V_2 , & V_534 -> V_404 ) ;
V_534 -> V_543 -= V_128 ;
V_534 -> V_345 += V_128 ;
}
static void
F_238 ( void * V_98 )
{
struct V_533 * V_534 = V_98 ;
struct V_549 * V_181 =
(struct V_549 * ) V_534 -> V_404 . V_181 ;
T_1 V_128 ;
V_181 -> type = F_96 ( V_534 -> type ) ;
V_181 -> V_541 = V_534 -> V_541 ;
V_181 -> V_345 = F_96 ( V_534 -> V_542 + V_534 -> V_345 ) ;
V_128 = ( V_534 -> V_543 < V_544 ) ?
V_534 -> V_543 : V_544 ;
V_181 -> V_545 = F_96 ( V_128 ) ;
F_92 ( V_181 -> V_137 , V_537 , V_550 ,
F_93 ( V_534 -> V_2 ) ) ;
F_222 ( & V_181 -> V_455 , V_128 , V_534 -> V_457 ) ;
F_142 ( V_534 -> V_2 , & V_534 -> V_404 ) ;
}
static void
F_239 ( void * V_98 )
{
struct V_533 * V_534 = V_98 ;
struct V_551 * V_181 =
(struct V_551 * ) V_534 -> V_404 . V_181 ;
V_181 -> type = F_96 ( V_534 -> type ) ;
V_181 -> V_541 = V_534 -> V_541 ;
F_92 ( V_181 -> V_137 , V_537 , V_552 ,
F_93 ( V_534 -> V_2 ) ) ;
F_142 ( V_534 -> V_2 , & V_534 -> V_404 ) ;
}
static void
F_240 ( void * V_553 , struct V_200 * V_181 )
{
struct V_533 * V_534 = V_553 ;
T_1 V_341 ;
union {
struct V_554 * V_555 ;
struct V_556 * V_557 ;
struct V_558 * V_559 ;
struct V_560 * V_561 ;
struct V_562 * V_4 ;
struct V_200 * V_181 ;
} V_201 ;
V_201 . V_181 = V_181 ;
F_3 ( V_534 , V_181 -> V_137 . V_203 ) ;
if ( ! V_534 -> V_535 && V_181 -> V_137 . V_203 != V_563 ) {
F_3 ( V_534 , 0x9999 ) ;
return;
}
switch ( V_181 -> V_137 . V_203 ) {
case V_564 :
V_341 = F_96 ( V_201 . V_555 -> V_341 ) ;
F_3 ( V_534 , V_341 ) ;
if ( V_341 == V_34 ) {
T_1 V_61 ;
struct V_539 * V_163 , * V_565 ;
V_163 = (struct V_539 * ) V_534 -> V_548 ;
V_565 = (struct V_539 * ) V_534 -> V_473 ;
V_163 -> V_341 = F_96 ( V_565 -> V_341 ) ;
V_163 -> V_566 = F_96 ( V_565 -> V_566 ) ;
F_3 ( V_534 , V_163 -> V_341 ) ;
F_3 ( V_534 , V_163 -> V_566 ) ;
for ( V_61 = 0 ; V_61 < V_163 -> V_566 ; V_61 ++ ) {
V_163 -> V_567 [ V_61 ] . V_568 =
F_96 ( V_565 -> V_567 [ V_61 ] . V_568 ) ;
V_163 -> V_567 [ V_61 ] . V_569 =
F_96 ( V_565 -> V_567 [ V_61 ] . V_569 ) ;
V_163 -> V_567 [ V_61 ] . V_570 =
F_96 ( V_565 -> V_567 [ V_61 ] . V_570 ) ;
V_163 -> V_567 [ V_61 ] . V_571 =
F_96 ( V_565 -> V_567 [ V_61 ] . V_571 ) ;
V_163 -> V_567 [ V_61 ] . V_572 =
F_96 ( V_565 -> V_567 [ V_61 ] . V_572 ) ;
V_163 -> V_567 [ V_61 ] . V_573 =
F_96 ( V_565 -> V_567 [ V_61 ] . V_573 ) ;
}
}
V_534 -> V_341 = V_341 ;
F_234 ( V_534 ) ;
break;
case V_574 :
V_341 = F_96 ( V_201 . V_557 -> V_341 ) ;
F_3 ( V_534 , V_341 ) ;
V_534 -> V_341 = V_341 ;
F_234 ( V_534 ) ;
break;
case V_575 :
V_341 = F_96 ( V_201 . V_559 -> V_341 ) ;
F_3 ( V_534 , V_341 ) ;
if ( V_341 != V_34 || V_534 -> V_543 == 0 ) {
V_534 -> V_341 = V_341 ;
F_234 ( V_534 ) ;
} else {
F_3 ( V_534 , V_534 -> V_345 ) ;
F_237 ( V_534 ) ;
}
break;
case V_576 :
V_341 = F_96 ( V_201 . V_561 -> V_341 ) ;
F_3 ( V_534 , V_341 ) ;
if ( V_341 != V_34 ) {
V_534 -> V_341 = V_341 ;
F_234 ( V_534 ) ;
} else {
T_1 V_128 = F_96 ( V_201 . V_561 -> V_545 ) ;
F_3 ( V_534 , V_534 -> V_345 ) ;
F_3 ( V_534 , V_128 ) ;
memcpy ( V_534 -> V_548 + V_534 -> V_345 ,
V_534 -> V_473 , V_128 ) ;
V_534 -> V_543 -= V_128 ;
V_534 -> V_345 += V_128 ;
if ( V_534 -> V_543 == 0 ) {
V_534 -> V_341 = V_341 ;
F_234 ( V_534 ) ;
} else
F_238 ( V_534 ) ;
}
break;
case V_577 :
break;
case V_563 :
V_341 = F_96 ( V_201 . V_4 -> V_341 ) ;
F_3 ( V_534 , V_341 ) ;
if ( V_341 == V_578 )
F_18 ( V_534 -> V_2 , V_579 ) ;
else if ( V_341 == V_580 ) {
T_1 V_581 ;
V_581 = F_96 ( V_201 . V_4 -> V_581 ) ;
F_3 ( V_534 , V_581 ) ;
F_18 ( V_534 -> V_2 ,
V_582 ) ;
}
break;
default:
F_76 ( 1 ) ;
}
}
T_1
F_241 ( T_2 V_583 )
{
if ( V_583 )
return 0 ;
return F_201 ( V_544 , V_398 ) ;
}
void
F_242 ( struct V_533 * V_534 , struct V_1 * V_2 , void * V_521 ,
struct V_522 * V_523 , T_2 V_583 )
{
V_534 -> V_2 = V_2 ;
V_534 -> V_523 = V_523 ;
V_534 -> V_18 = NULL ;
V_534 -> V_98 = NULL ;
V_534 -> V_535 = 0 ;
F_141 ( V_534 -> V_2 , V_537 , F_240 , V_534 ) ;
F_204 ( & V_534 -> V_401 ) ;
F_205 ( & V_534 -> V_401 , F_235 , V_534 ) ;
F_143 ( & V_534 -> V_401 . V_97 , & V_534 -> V_2 -> V_217 ) ;
if ( V_583 ) {
V_534 -> V_473 = NULL ;
V_534 -> V_457 = 0 ;
}
}
void
F_243 ( struct V_533 * V_534 , T_6 * V_245 , T_7 V_246 ,
T_2 V_583 )
{
if ( V_583 )
return;
V_534 -> V_473 = V_245 ;
V_534 -> V_457 = V_246 ;
memset ( V_534 -> V_473 , 0 , V_544 ) ;
V_245 += F_201 ( V_544 , V_398 ) ;
V_246 += F_201 ( V_544 , V_398 ) ;
}
T_4
F_244 ( struct V_533 * V_534 , struct V_539 * V_163 ,
T_13 V_18 , void * V_98 )
{
F_3 ( V_534 , V_538 ) ;
if ( ! F_120 ( V_534 -> V_2 ) )
return V_525 ;
if ( V_534 -> V_535 ) {
F_3 ( V_534 , V_534 -> V_535 ) ;
return V_353 ;
}
V_534 -> V_535 = 1 ;
V_534 -> V_18 = V_18 ;
V_534 -> V_98 = V_98 ;
V_534 -> V_548 = ( T_6 * ) V_163 ;
F_236 ( V_534 ) ;
return V_34 ;
}
T_4
F_245 ( struct V_533 * V_534 , enum V_584 type ,
T_6 V_541 , T_13 V_18 , void * V_98 )
{
F_3 ( V_534 , V_552 ) ;
F_3 ( V_534 , type ) ;
F_3 ( V_534 , V_541 ) ;
if ( ! F_120 ( V_534 -> V_2 ) )
return V_525 ;
if ( V_534 -> V_535 ) {
F_3 ( V_534 , V_534 -> V_535 ) ;
return V_353 ;
}
V_534 -> V_535 = 1 ;
V_534 -> V_18 = V_18 ;
V_534 -> V_98 = V_98 ;
V_534 -> type = type ;
V_534 -> V_541 = V_541 ;
F_239 ( V_534 ) ;
F_233 ( V_534 -> V_2 , V_585 ,
V_541 , type ) ;
return V_34 ;
}
T_4
F_246 ( struct V_533 * V_534 , enum V_584 type ,
T_6 V_541 , void * V_185 , T_1 V_128 , T_1 V_345 ,
T_13 V_18 , void * V_98 )
{
F_3 ( V_534 , V_547 ) ;
F_3 ( V_534 , type ) ;
F_3 ( V_534 , V_541 ) ;
F_3 ( V_534 , V_128 ) ;
F_3 ( V_534 , V_345 ) ;
if ( ! F_120 ( V_534 -> V_2 ) )
return V_525 ;
if ( ! V_128 || ( V_128 & 0x03 ) || ( V_345 & 0x00003FFF ) )
return V_586 ;
if ( type == V_587 )
return V_349 ;
if ( V_534 -> V_535 ) {
F_3 ( V_534 , V_534 -> V_535 ) ;
return V_353 ;
}
V_534 -> V_535 = 1 ;
V_534 -> V_18 = V_18 ;
V_534 -> V_98 = V_98 ;
V_534 -> type = type ;
V_534 -> V_541 = V_541 ;
V_534 -> V_543 = V_128 ;
V_534 -> V_345 = 0 ;
V_534 -> V_542 = V_345 ;
V_534 -> V_548 = V_185 ;
F_237 ( V_534 ) ;
return V_34 ;
}
T_4
F_247 ( struct V_533 * V_534 , enum V_584 type ,
T_6 V_541 , void * V_185 , T_1 V_128 , T_1 V_345 ,
T_13 V_18 , void * V_98 )
{
F_3 ( V_534 , V_550 ) ;
F_3 ( V_534 , type ) ;
F_3 ( V_534 , V_541 ) ;
F_3 ( V_534 , V_128 ) ;
F_3 ( V_534 , V_345 ) ;
if ( ! F_120 ( V_534 -> V_2 ) )
return V_525 ;
if ( ! V_128 || ( V_128 & 0x03 ) || ( V_345 & 0x00003FFF ) )
return V_586 ;
if ( V_534 -> V_535 ) {
F_3 ( V_534 , V_534 -> V_535 ) ;
return V_353 ;
}
V_534 -> V_535 = 1 ;
V_534 -> V_18 = V_18 ;
V_534 -> V_98 = V_98 ;
V_534 -> type = type ;
V_534 -> V_541 = V_541 ;
V_534 -> V_543 = V_128 ;
V_534 -> V_345 = 0 ;
V_534 -> V_542 = V_345 ;
V_534 -> V_548 = V_185 ;
F_238 ( V_534 ) ;
return V_34 ;
}
static void
F_248 ( void * V_588 , enum V_93 V_4 )
{
struct V_589 * V_590 = V_588 ;
F_3 ( V_590 , V_4 ) ;
F_3 ( V_590 , V_590 -> V_591 ) ;
F_3 ( V_590 , V_590 -> V_592 . V_424 ) ;
F_3 ( V_590 , V_590 -> V_593 . V_424 ) ;
switch ( V_4 ) {
case V_99 :
case V_188 :
if ( V_590 -> V_592 . V_424 ) {
V_590 -> V_592 . V_341 = V_21 ;
V_590 -> V_592 . V_18 ( V_590 -> V_592 . V_98 ,
V_590 -> V_592 . V_341 ) ;
V_590 -> V_592 . V_424 = 0 ;
}
if ( V_590 -> V_593 . V_424 ) {
V_590 -> V_593 . V_341 = V_21 ;
V_590 -> V_593 . V_18 ( V_590 -> V_593 . V_98 ,
V_590 -> V_593 . V_341 ) ;
V_590 -> V_593 . V_424 = 0 ;
}
if ( V_590 -> V_591 ) {
if ( V_590 -> V_594 ) {
F_196 ( & V_590 -> V_367 ) ;
V_590 -> V_594 = 0 ;
}
V_590 -> V_341 = V_21 ;
V_590 -> V_18 ( V_590 -> V_98 , V_590 -> V_341 ) ;
V_590 -> V_591 = 0 ;
}
break;
default:
break;
}
}
static void
F_249 ( void * V_98 )
{
struct V_589 * V_590 = V_98 ;
struct V_1 * V_2 = V_590 -> V_2 ;
struct V_595 * V_596 = V_590 -> V_597 ;
T_1 V_60 = V_598 ;
T_1 V_58 , V_59 , V_61 ;
V_58 = F_34 ( V_2 -> V_62 . V_68 , V_60 ) ;
V_59 = F_35 ( V_60 ) ;
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
for ( V_61 = 0 ; V_61 < ( sizeof( struct V_595 ) /
sizeof( T_1 ) ) ; V_61 ++ ) {
* ( ( T_1 * ) V_596 + V_61 ) =
F_81 ( V_2 -> V_62 . V_70 , V_60 ) ;
V_60 += sizeof( T_1 ) ;
}
F_151 ( V_2 ) ;
V_596 -> V_341 = F_33 ( V_596 -> V_341 ) ;
F_3 ( V_590 , V_596 -> V_341 ) ;
if ( V_596 -> V_341 == V_599 )
V_590 -> V_341 = V_34 ;
else {
V_590 -> V_341 = V_600 ;
V_596 -> V_406 = F_33 ( V_596 -> V_406 ) ;
V_596 -> exp = F_33 ( V_596 -> exp ) ;
V_596 -> V_601 = F_33 ( V_596 -> V_601 ) ;
V_596 -> V_602 = F_33 ( V_596 -> V_602 ) ;
V_596 -> V_603 = F_33 ( V_596 -> V_603 ) ;
V_596 -> V_604 = F_33 ( V_596 -> V_604 ) ;
F_3 ( V_590 , V_596 -> V_406 ) ;
F_3 ( V_590 , V_596 -> exp ) ;
F_3 ( V_590 , V_596 -> V_601 ) ;
F_3 ( V_590 , V_596 -> V_602 ) ;
F_3 ( V_590 , V_596 -> V_603 ) ;
F_3 ( V_590 , V_596 -> V_604 ) ;
}
V_590 -> V_594 = 0 ;
V_590 -> V_18 ( V_590 -> V_98 , V_590 -> V_341 ) ;
V_590 -> V_591 = 0 ;
}
static void
F_250 ( struct V_589 * V_590 )
{
struct V_605 * V_606 ;
T_1 V_61 ;
F_3 ( V_590 , V_590 -> V_592 . V_457 ) ;
for ( V_61 = 0 ; V_61 < ( V_607 >> 2 ) ; V_61 ++ )
* ( ( T_1 * ) V_590 -> V_592 . V_473 + V_61 ) = V_590 -> V_592 . V_608 ;
V_606 = (struct V_605 * ) V_590 -> V_592 . V_450 . V_181 ;
F_222 ( & V_606 -> V_455 , V_607 ,
V_590 -> V_592 . V_457 ) ;
V_606 -> V_609 = F_124 ( V_590 -> V_592 . V_609 ) ;
V_606 -> V_608 = V_590 -> V_592 . V_608 ;
F_92 ( V_606 -> V_137 , V_610 , V_611 ,
F_93 ( V_590 -> V_2 ) ) ;
F_142 ( V_590 -> V_2 , & V_590 -> V_592 . V_450 ) ;
}
static void
F_251 ( struct V_589 * V_590 ,
struct V_612 * V_613 )
{
T_1 V_614 = V_613 -> V_608 ;
T_6 V_615 = V_613 -> V_616 ;
F_3 ( V_590 , V_614 ) ;
F_3 ( V_590 , V_615 ) ;
if ( V_615 == V_34 ) {
T_1 V_61 , V_617 ;
V_617 = ( V_590 -> V_592 . V_609 & 0x1 ) ? ~ ( V_590 -> V_592 . V_608 ) :
V_590 -> V_592 . V_608 ;
if ( V_590 -> V_592 . V_608 != V_614 ) {
F_3 ( V_590 , V_614 ) ;
V_590 -> V_592 . V_597 -> V_618 =
V_619 ;
V_590 -> V_592 . V_341 = V_619 ;
V_590 -> V_592 . V_18 ( V_590 -> V_592 . V_98 ,
V_590 -> V_592 . V_341 ) ;
V_590 -> V_592 . V_424 = 0 ;
return;
}
for ( V_61 = 0 ; V_61 < ( V_607 >> 2 ) ; V_61 ++ ) {
if ( * ( ( T_1 * ) V_590 -> V_592 . V_473 + V_61 ) != V_617 ) {
F_3 ( V_590 , V_61 ) ;
F_3 ( V_590 , V_617 ) ;
F_3 ( V_590 ,
* ( ( T_1 * ) V_590 -> V_592 . V_473 + V_61 ) ) ;
V_590 -> V_592 . V_597 -> V_618 =
V_619 ;
V_590 -> V_592 . V_341 = V_619 ;
V_590 -> V_592 . V_18 ( V_590 -> V_592 . V_98 ,
V_590 -> V_592 . V_341 ) ;
V_590 -> V_592 . V_424 = 0 ;
return;
}
}
V_590 -> V_592 . V_597 -> V_618 = V_34 ;
V_590 -> V_592 . V_341 = V_34 ;
V_590 -> V_592 . V_18 ( V_590 -> V_592 . V_98 , V_590 -> V_592 . V_341 ) ;
V_590 -> V_592 . V_424 = 0 ;
} else {
V_590 -> V_592 . V_341 = V_620 ;
V_590 -> V_592 . V_18 ( V_590 -> V_592 . V_98 , V_590 -> V_592 . V_341 ) ;
V_590 -> V_592 . V_424 = 0 ;
}
}
static void
F_252 ( struct V_589 * V_590 )
{
struct V_621 * V_181 ;
V_181 = (struct V_621 * ) V_590 -> V_593 . V_450 . V_181 ;
F_3 ( V_590 , V_181 -> V_622 ) ;
F_92 ( V_181 -> V_137 , V_610 , V_623 ,
F_93 ( V_590 -> V_2 ) ) ;
F_142 ( V_590 -> V_2 , & V_590 -> V_593 . V_450 ) ;
}
static void
F_253 ( struct V_589 * V_590 , T_14 * V_386 )
{
if ( ! V_590 -> V_593 . V_424 ) {
F_3 ( V_590 , V_590 -> V_593 . V_424 ) ;
return;
}
V_590 -> V_593 . V_622 -> V_622 = F_109 ( V_386 -> V_622 ) ;
V_590 -> V_593 . V_622 -> V_624 = V_386 -> V_624 ;
V_590 -> V_593 . V_622 -> V_625 = V_386 -> V_625 ;
if ( V_386 -> V_625 ) {
V_590 -> V_593 . V_622 -> V_341 = V_386 -> V_341 ;
if ( V_386 -> V_341 == V_34 ) {
V_590 -> V_593 . V_622 -> V_626 =
F_109 ( V_386 -> V_626 ) ;
} else
V_590 -> V_593 . V_622 -> V_626 = 0 ;
}
F_3 ( V_590 , V_386 -> V_341 ) ;
F_3 ( V_590 , V_386 -> V_624 ) ;
F_3 ( V_590 , V_386 -> V_622 ) ;
F_3 ( V_590 , V_386 -> V_625 ) ;
F_3 ( V_590 , V_386 -> V_626 ) ;
V_590 -> V_593 . V_341 = V_34 ;
V_590 -> V_593 . V_18 ( V_590 -> V_593 . V_98 , V_590 -> V_593 . V_341 ) ;
V_590 -> V_593 . V_424 = 0 ;
}
static void
F_254 ( struct V_589 * V_590 , struct V_627 * V_628 )
{
struct V_629 * V_181 ;
V_181 = (struct V_629 * ) V_590 -> V_628 . V_450 . V_181 ;
F_92 ( V_181 -> V_137 , V_610 , V_630 ,
F_93 ( V_590 -> V_2 ) ) ;
if ( V_628 -> V_631 )
V_628 -> V_631 = 500 / V_628 -> V_631 ;
if ( V_628 -> V_631 == 0 )
V_628 -> V_631 = 1 ;
F_3 ( V_590 , V_628 -> V_631 ) ;
V_181 -> V_179 = ( T_6 ) V_628 -> V_179 ;
V_181 -> V_632 = ( T_6 ) V_628 -> V_632 ;
V_181 -> V_633 = F_93 ( V_590 -> V_2 ) ;
V_181 -> V_634 = V_628 -> V_634 ;
V_181 -> V_631 = F_94 ( V_628 -> V_631 ) ;
F_142 ( V_590 -> V_2 , & V_590 -> V_628 . V_450 ) ;
}
static void
F_255 ( struct V_589 * V_590 , struct V_635 * V_181 )
{
F_3 ( V_590 , V_590 -> V_628 . V_424 ) ;
V_590 -> V_628 . V_424 = V_50 ;
}
static void
F_256 ( struct V_589 * V_590 , T_2 V_636 , T_1 V_637 )
{
struct V_638 * V_181 ;
V_181 = (struct V_638 * ) V_590 -> V_636 . V_450 . V_181 ;
F_92 ( V_181 -> V_137 , V_610 , V_639 ,
F_93 ( V_590 -> V_2 ) ) ;
V_181 -> V_636 = V_636 ;
V_181 -> V_640 = F_124 ( V_637 ) ;
F_142 ( V_590 -> V_2 , & V_590 -> V_636 . V_450 ) ;
}
static void
F_257 ( struct V_589 * V_590 )
{
F_3 ( V_590 , V_590 -> V_636 . V_321 ) ;
V_590 -> V_636 . V_321 = V_50 ;
if ( V_590 -> V_641 )
V_590 -> V_641 ( V_590 -> V_521 , V_50 , V_590 -> V_636 . V_642 ) ;
}
void
F_258 ( void * V_643 , struct V_200 * V_181 )
{
struct V_589 * V_590 = V_643 ;
switch ( V_181 -> V_137 . V_203 ) {
case V_644 :
F_257 ( V_590 ) ;
break;
case V_645 :
F_251 ( V_590 , (struct V_612 * ) V_181 ) ;
break;
case V_646 :
F_253 ( V_590 , ( T_14 * ) V_181 ) ;
break;
case V_647 :
F_255 ( V_590 , (struct V_635 * ) V_181 ) ;
break;
default:
F_3 ( V_590 , V_181 -> V_137 . V_203 ) ;
F_76 ( 1 ) ;
}
}
T_4
F_259 ( struct V_589 * V_590 , struct V_648 * V_649 ,
T_1 V_650 , struct V_595 * V_597 ,
T_15 V_18 , void * V_98 )
{
T_1 V_651 ;
F_3 ( V_590 , V_650 ) ;
if ( ! F_149 ( V_590 -> V_2 ) )
return V_652 ;
if ( V_590 -> V_591 ) {
F_3 ( V_590 , V_590 -> V_591 ) ;
return V_353 ;
} else
V_590 -> V_591 = 1 ;
V_590 -> V_597 = V_597 ;
V_590 -> V_18 = V_18 ;
V_590 -> V_98 = V_98 ;
F_88 ( V_590 -> V_2 , V_195 , V_122 ) ;
V_651 = ( F_84 ( V_590 -> V_2 ) == V_237 ) ?
V_653 : V_654 ;
F_194 ( V_590 -> V_2 -> V_215 , & V_590 -> V_367 ,
F_249 , V_590 , V_651 ) ;
V_590 -> V_594 = 1 ;
return V_34 ;
}
T_4
F_260 ( struct V_589 * V_590 , T_1 V_101 , T_1 V_608 ,
struct V_655 * V_597 , T_15 V_18 ,
void * V_98 )
{
F_3 ( V_590 , V_101 ) ;
F_3 ( V_590 , V_608 ) ;
if ( ! F_120 ( V_590 -> V_2 ) )
return V_525 ;
if ( F_166 ( F_170 ( ( V_590 -> V_2 ) ) ) &&
( ( V_590 -> V_2 ) -> V_140 == V_288 ) )
return V_656 ;
if ( V_590 -> V_591 || V_590 -> V_592 . V_424 ) {
F_3 ( V_590 , V_590 -> V_591 ) ;
F_3 ( V_590 , V_590 -> V_592 . V_424 ) ;
return V_353 ;
}
V_590 -> V_592 . V_424 = 1 ;
V_590 -> V_592 . V_18 = V_18 ;
V_590 -> V_592 . V_98 = V_98 ;
V_590 -> V_592 . V_597 = V_597 ;
V_590 -> V_592 . V_608 = V_608 ;
V_590 -> V_592 . V_609 = V_101 ;
V_590 -> V_592 . V_597 -> V_608 = 0 ;
V_590 -> V_592 . V_597 -> V_341 = V_34 ;
F_250 ( V_590 ) ;
return V_34 ;
}
T_4
F_261 ( struct V_589 * V_590 ,
struct V_657 * V_597 ,
T_15 V_18 , void * V_98 )
{
if ( V_590 -> V_591 || V_590 -> V_593 . V_424 ) {
F_3 ( V_590 , V_590 -> V_591 ) ;
F_3 ( V_590 , V_590 -> V_593 . V_424 ) ;
return V_353 ;
}
if ( ! F_120 ( V_590 -> V_2 ) )
return V_525 ;
V_590 -> V_593 . V_424 = 1 ;
V_590 -> V_593 . V_622 = V_597 ;
V_590 -> V_593 . V_18 = V_18 ;
V_590 -> V_593 . V_98 = V_98 ;
V_590 -> V_593 . V_341 = V_34 ;
F_252 ( V_590 ) ;
return V_34 ;
}
T_4
F_262 ( struct V_589 * V_590 , struct V_627 * V_628 )
{
F_3 ( V_590 , V_628 -> V_179 ) ;
if ( ! F_120 ( V_590 -> V_2 ) )
return V_525 ;
if ( V_590 -> V_636 . V_321 )
return V_658 ;
if ( V_590 -> V_628 . V_424 )
return V_659 ;
V_590 -> V_628 . V_424 = V_77 ;
F_254 ( V_590 , V_628 ) ;
return V_34 ;
}
T_4
F_263 ( struct V_589 * V_590 , T_2 V_636 ,
T_2 V_660 , T_16 V_637 )
{
F_3 ( V_590 , V_636 ) ;
F_3 ( V_590 , V_660 ) ;
F_3 ( V_590 , V_637 ) ;
if ( ! F_120 ( V_590 -> V_2 ) )
return V_525 ;
if ( V_590 -> V_628 . V_424 )
return V_659 ;
if ( V_590 -> V_636 . V_321 && V_636 )
return V_658 ;
V_590 -> V_636 . V_321 = V_636 ;
V_590 -> V_636 . V_642 = V_660 ;
if ( V_590 -> V_641 )
V_590 -> V_641 ( V_590 -> V_521 , V_636 , V_660 ) ;
F_256 ( V_590 , V_636 , V_637 ) ;
return V_34 ;
}
T_1
F_264 ( void )
{
return F_201 ( V_607 , V_398 ) ;
}
void
F_265 ( struct V_589 * V_590 , struct V_1 * V_2 , void * V_521 ,
T_17 V_641 , struct V_522 * V_523 )
{
V_590 -> V_521 = V_521 ;
V_590 -> V_2 = V_2 ;
V_590 -> V_523 = V_523 ;
V_590 -> V_591 = 0 ;
V_590 -> V_18 = NULL ;
V_590 -> V_98 = NULL ;
V_590 -> V_597 = NULL ;
V_590 -> V_641 = V_641 ;
F_141 ( V_590 -> V_2 , V_610 , F_258 , V_590 ) ;
F_204 ( & V_590 -> V_401 ) ;
F_205 ( & V_590 -> V_401 , F_248 , V_590 ) ;
F_143 ( & V_590 -> V_401 . V_97 , & V_590 -> V_2 -> V_217 ) ;
}
void
F_266 ( struct V_589 * V_590 , T_6 * V_245 , T_7 V_246 )
{
V_590 -> V_592 . V_473 = V_245 ;
V_590 -> V_592 . V_457 = V_246 ;
memset ( V_590 -> V_592 . V_473 , 0 , V_607 ) ;
}
static void
F_267 ( T_1 * V_661 , T_1 * V_662 , int V_184 )
{
int V_61 , V_201 = V_184 >> 2 ;
for ( V_61 = 0 ; V_61 < V_201 ; V_61 ++ )
V_661 [ V_61 ] = F_96 ( V_662 [ V_61 ] ) ;
}
static T_2
F_268 ( struct V_663 * V_664 )
{
return ( V_664 -> V_2 -> V_163 -> V_165 == V_665 ) ;
}
static void
F_269 ( void * V_98 , enum V_93 V_4 )
{
struct V_663 * V_664 = V_98 ;
F_3 ( V_664 , V_4 ) ;
switch ( V_4 ) {
case V_99 :
case V_188 :
if ( V_664 -> V_535 ) {
V_664 -> V_341 = V_21 ;
V_664 -> V_18 ( V_664 -> V_98 , V_664 -> V_341 ) ;
V_664 -> V_535 = 0 ;
}
break;
default:
break;
}
}
static void
F_270 ( void * V_98 )
{
struct V_663 * V_664 = V_98 ;
struct V_666 * V_181 =
(struct V_666 * ) V_664 -> V_404 . V_181 ;
V_181 -> V_541 = V_664 -> V_541 ;
F_92 ( V_181 -> V_137 , V_667 , V_668 ,
F_93 ( V_664 -> V_2 ) ) ;
F_222 ( & V_181 -> V_455 , sizeof( struct V_669 ) , V_664 -> V_457 ) ;
F_142 ( V_664 -> V_2 , & V_664 -> V_404 ) ;
}
static void
F_271 ( void * V_98 )
{
struct V_663 * V_664 = V_98 ;
struct V_670 * V_181 =
(struct V_670 * ) V_664 -> V_404 . V_181 ;
T_1 V_128 ;
T_10 * V_185 , * V_671 ;
int V_61 , V_184 ;
V_181 -> V_541 = V_664 -> V_541 ;
V_181 -> V_345 = F_124 ( V_664 -> V_542 + V_664 -> V_345 ) ;
V_128 = ( V_664 -> V_543 < V_672 ) ?
V_664 -> V_543 : V_672 ;
V_181 -> V_545 = F_124 ( V_128 ) ;
V_181 -> V_546 = ( V_128 == V_664 -> V_543 ) ? 1 : 0 ;
F_92 ( V_181 -> V_137 , V_667 , V_673 ,
F_93 ( V_664 -> V_2 ) ) ;
F_222 ( & V_181 -> V_455 , V_128 , V_664 -> V_457 ) ;
V_185 = ( T_10 * ) ( V_664 -> V_548 + V_664 -> V_345 ) ;
V_671 = ( T_10 * ) V_664 -> V_473 ;
V_184 = V_128 >> 1 ;
for ( V_61 = 0 ; V_61 < V_184 ; V_61 ++ )
V_185 [ V_61 ] = F_94 ( V_671 [ V_61 ] ) ;
F_142 ( V_664 -> V_2 , & V_664 -> V_404 ) ;
V_664 -> V_543 -= V_128 ;
V_664 -> V_345 += V_128 ;
}
static void
F_272 ( void * V_98 )
{
struct V_663 * V_664 = V_98 ;
struct V_674 * V_181 =
(struct V_674 * ) V_664 -> V_404 . V_181 ;
T_1 V_128 ;
V_181 -> V_541 = V_664 -> V_541 ;
V_181 -> V_345 = F_124 ( V_664 -> V_542 + V_664 -> V_345 ) ;
V_128 = ( V_664 -> V_543 < V_672 ) ?
V_664 -> V_543 : V_672 ;
V_181 -> V_545 = F_124 ( V_128 ) ;
F_92 ( V_181 -> V_137 , V_667 , V_675 ,
F_93 ( V_664 -> V_2 ) ) ;
F_222 ( & V_181 -> V_455 , V_128 , V_664 -> V_457 ) ;
F_142 ( V_664 -> V_2 , & V_664 -> V_404 ) ;
}
static void
F_273 ( void * V_98 )
{
struct V_663 * V_664 = V_98 ;
struct V_676 * V_181 =
(struct V_676 * ) V_664 -> V_404 . V_181 ;
V_181 -> V_541 = V_664 -> V_541 ;
F_92 ( V_181 -> V_137 , V_667 , V_677 ,
F_93 ( V_664 -> V_2 ) ) ;
F_222 ( & V_181 -> V_455 , sizeof( struct V_678 ) , V_664 -> V_457 ) ;
F_142 ( V_664 -> V_2 , & V_664 -> V_404 ) ;
}
T_1
F_274 ( T_2 V_583 )
{
if ( V_583 )
return 0 ;
return F_201 ( V_672 , V_398 ) ;
}
void
F_275 ( struct V_663 * V_664 , struct V_1 * V_2 , void * V_521 ,
struct V_522 * V_523 , T_2 V_583 )
{
V_664 -> V_2 = V_2 ;
V_664 -> V_523 = V_523 ;
V_664 -> V_18 = NULL ;
V_664 -> V_98 = NULL ;
V_664 -> V_535 = 0 ;
F_141 ( V_664 -> V_2 , V_667 , V_679 , V_664 ) ;
F_204 ( & V_664 -> V_401 ) ;
F_205 ( & V_664 -> V_401 , F_269 , V_664 ) ;
F_143 ( & V_664 -> V_401 . V_97 , & V_664 -> V_2 -> V_217 ) ;
if ( V_583 ) {
V_664 -> V_473 = NULL ;
V_664 -> V_457 = 0 ;
}
}
void
F_276 ( struct V_663 * V_664 , T_6 * V_245 , T_7 V_246 ,
T_2 V_583 )
{
if ( V_583 )
return;
V_664 -> V_473 = V_245 ;
V_664 -> V_457 = V_246 ;
memset ( V_664 -> V_473 , 0 , V_672 ) ;
V_245 += F_201 ( V_672 , V_398 ) ;
V_246 += F_201 ( V_672 , V_398 ) ;
}
T_2
F_277 ( struct V_1 * V_2 )
{
void T_3 * V_680 ;
V_680 = F_278 ( V_2 ) ;
return F_28 ( V_680 + V_681 ) ;
}
T_4
F_279 ( struct V_663 * V_664 , T_6 V_541 ,
struct V_669 * V_163 , T_18 V_18 , void * V_98 )
{
F_3 ( V_664 , V_668 ) ;
F_3 ( V_664 , V_541 ) ;
if ( ! F_268 ( V_664 ) )
return V_682 ;
if ( ! F_120 ( V_664 -> V_2 ) )
return V_525 ;
if ( V_664 -> V_535 || F_277 ( V_664 -> V_2 ) ) {
F_3 ( V_664 , V_664 -> V_535 ) ;
return V_353 ;
}
V_664 -> V_535 = 1 ;
V_664 -> V_18 = V_18 ;
V_664 -> V_98 = V_98 ;
V_664 -> V_541 = V_541 ;
V_664 -> V_548 = ( V_683 * ) V_163 ;
F_270 ( V_664 ) ;
return V_34 ;
}
T_4
F_280 ( struct V_663 * V_664 , T_6 V_541 ,
struct V_678 * V_257 ,
T_18 V_18 , void * V_98 )
{
F_3 ( V_664 , V_677 ) ;
F_3 ( V_664 , V_541 ) ;
if ( ! F_268 ( V_664 ) )
return V_682 ;
if ( ! F_120 ( V_664 -> V_2 ) )
return V_525 ;
if ( V_664 -> V_535 || F_277 ( V_664 -> V_2 ) ) {
F_3 ( V_664 , V_664 -> V_535 ) ;
return V_353 ;
}
V_664 -> V_535 = 1 ;
V_664 -> V_18 = V_18 ;
V_664 -> V_98 = V_98 ;
V_664 -> V_541 = V_541 ;
V_664 -> V_548 = ( T_6 * ) V_257 ;
F_273 ( V_664 ) ;
return V_34 ;
}
T_4
F_281 ( struct V_663 * V_664 , T_6 V_541 ,
void * V_185 , T_1 V_128 , T_1 V_345 ,
T_18 V_18 , void * V_98 )
{
F_3 ( V_664 , V_673 ) ;
F_3 ( V_664 , V_541 ) ;
F_3 ( V_664 , V_128 ) ;
F_3 ( V_664 , V_345 ) ;
if ( ! F_268 ( V_664 ) )
return V_682 ;
if ( ! F_120 ( V_664 -> V_2 ) )
return V_525 ;
if ( ! V_128 || ( V_128 & 0x03 ) )
return V_186 ;
if ( V_664 -> V_535 || F_277 ( V_664 -> V_2 ) ) {
F_3 ( V_664 , V_664 -> V_535 ) ;
return V_353 ;
}
V_664 -> V_535 = 1 ;
V_664 -> V_18 = V_18 ;
V_664 -> V_98 = V_98 ;
V_664 -> V_541 = V_541 ;
V_664 -> V_543 = V_128 ;
V_664 -> V_345 = 0 ;
V_664 -> V_542 = V_345 ;
V_664 -> V_548 = V_185 ;
F_271 ( V_664 ) ;
return V_34 ;
}
T_4
F_282 ( struct V_663 * V_664 , T_6 V_541 ,
void * V_185 , T_1 V_128 , T_1 V_345 ,
T_18 V_18 , void * V_98 )
{
F_3 ( V_664 , V_675 ) ;
F_3 ( V_664 , V_541 ) ;
F_3 ( V_664 , V_128 ) ;
F_3 ( V_664 , V_345 ) ;
if ( ! F_268 ( V_664 ) )
return V_682 ;
if ( ! F_120 ( V_664 -> V_2 ) )
return V_525 ;
if ( ! V_128 || ( V_128 & 0x03 ) )
return V_186 ;
if ( V_664 -> V_535 || F_277 ( V_664 -> V_2 ) ) {
F_3 ( V_664 , V_664 -> V_535 ) ;
return V_353 ;
}
V_664 -> V_535 = 1 ;
V_664 -> V_18 = V_18 ;
V_664 -> V_98 = V_98 ;
V_664 -> V_541 = V_541 ;
V_664 -> V_543 = V_128 ;
V_664 -> V_345 = 0 ;
V_664 -> V_542 = V_345 ;
V_664 -> V_548 = V_185 ;
F_272 ( V_664 ) ;
return V_34 ;
}
void
V_679 ( void * V_684 , struct V_200 * V_181 )
{
struct V_663 * V_664 = V_684 ;
T_1 V_341 ;
union {
struct V_685 * V_555 ;
struct V_686 * V_257 ;
struct V_687 * V_559 ;
struct V_688 * V_561 ;
struct V_200 * V_181 ;
} V_201 ;
V_201 . V_181 = V_181 ;
F_3 ( V_664 , V_181 -> V_137 . V_203 ) ;
if ( ! V_664 -> V_535 ) {
F_3 ( V_664 , 0x9999 ) ;
return;
}
switch ( V_181 -> V_137 . V_203 ) {
case V_689 :
V_341 = F_96 ( V_201 . V_555 -> V_341 ) ;
F_3 ( V_664 , V_341 ) ;
if ( V_341 == V_34 ) {
struct V_669 * V_163 =
(struct V_669 * ) V_664 -> V_548 ;
F_267 ( ( T_1 * ) V_163 , ( T_1 * ) V_664 -> V_473 ,
sizeof( struct V_669 ) ) ;
F_3 ( V_664 , V_163 -> V_341 ) ;
F_3 ( V_664 , V_163 -> V_545 ) ;
}
V_664 -> V_341 = V_341 ;
V_664 -> V_535 = 0 ;
if ( V_664 -> V_18 )
V_664 -> V_18 ( V_664 -> V_98 , V_664 -> V_341 ) ;
break;
case V_690 :
V_341 = F_96 ( V_201 . V_257 -> V_341 ) ;
F_3 ( V_664 , V_341 ) ;
if ( V_341 == V_34 ) {
struct V_678 * V_257 =
(struct V_678 * ) V_664 -> V_548 ;
F_267 ( ( T_1 * ) V_257 , ( T_1 * ) V_664 -> V_473 ,
sizeof( struct V_678 ) ) ;
F_3 ( V_664 , V_257 -> V_341 ) ;
}
V_664 -> V_341 = V_341 ;
V_664 -> V_535 = 0 ;
if ( V_664 -> V_18 )
V_664 -> V_18 ( V_664 -> V_98 , V_664 -> V_341 ) ;
break;
case V_691 :
V_341 = F_96 ( V_201 . V_559 -> V_341 ) ;
F_3 ( V_664 , V_341 ) ;
if ( V_341 != V_34 || V_664 -> V_543 == 0 ) {
V_664 -> V_341 = V_341 ;
V_664 -> V_535 = 0 ;
if ( V_664 -> V_18 )
V_664 -> V_18 ( V_664 -> V_98 , V_664 -> V_341 ) ;
} else {
F_3 ( V_664 , V_664 -> V_345 ) ;
F_271 ( V_664 ) ;
}
break;
case V_692 :
V_341 = F_96 ( V_201 . V_561 -> V_341 ) ;
F_3 ( V_664 , V_341 ) ;
if ( V_341 != V_34 ) {
V_664 -> V_341 = V_341 ;
V_664 -> V_535 = 0 ;
if ( V_664 -> V_18 )
V_664 -> V_18 ( V_664 -> V_98 , V_664 -> V_341 ) ;
} else {
T_1 V_128 = F_96 ( V_201 . V_561 -> V_545 ) ;
T_10 * V_185 = ( T_10 * ) ( V_664 -> V_548 + V_664 -> V_345 ) ;
T_10 * V_671 = ( T_10 * ) V_664 -> V_473 ;
int V_61 , V_184 = V_128 >> 1 ;
F_3 ( V_664 , V_664 -> V_345 ) ;
F_3 ( V_664 , V_128 ) ;
for ( V_61 = 0 ; V_61 < V_184 ; V_61 ++ )
V_185 [ V_61 ] = F_109 ( V_671 [ V_61 ] ) ;
V_664 -> V_543 -= V_128 ;
V_664 -> V_345 += V_128 ;
if ( V_664 -> V_543 == 0 ) {
V_664 -> V_341 = V_341 ;
V_664 -> V_535 = 0 ;
if ( V_664 -> V_18 )
V_664 -> V_18 ( V_664 -> V_98 , V_664 -> V_341 ) ;
} else
F_272 ( V_664 ) ;
}
break;
default:
F_76 ( 1 ) ;
}
}
static void
F_283 ( struct V_693 * V_694 , enum V_695 V_4 )
{
T_4 V_696 ;
F_3 ( V_694 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_697 :
if ( V_694 -> V_698 ) {
F_3 ( V_694 -> V_20 , V_694 -> V_698 ) ;
F_9 ( & V_694 -> V_20 -> V_699 ,
V_700 ) ;
return;
}
F_284 ( V_694 , V_701 ) ;
F_285 ( V_694 -> V_20 , & V_694 -> V_367 ,
V_702 , V_694 , 2 * V_703 ) ;
V_696 = F_247 ( F_286 ( V_694 -> V_20 ) ,
V_704 , V_694 -> V_541 ,
V_694 -> V_694 ,
sizeof( struct V_705 ) , 0 ,
V_706 , V_694 -> V_20 ) ;
if ( V_696 != V_34 ) {
F_196 ( & V_694 -> V_367 ) ;
V_706 ( V_694 -> V_20 , V_186 ) ;
F_284 ( V_694 , F_283 ) ;
return;
}
break;
case V_707 :
F_9 ( & V_694 -> V_20 -> V_699 , V_700 ) ;
case V_708 :
case V_709 :
case V_710 :
break;
default:
F_5 ( V_694 -> V_20 , V_4 ) ;
}
}
static void
V_701 ( struct V_693 * V_694 ,
enum V_695 V_4 )
{
F_3 ( V_694 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_710 :
F_196 ( & V_694 -> V_367 ) ;
F_284 ( V_694 , V_711 ) ;
break;
case V_712 :
F_284 ( V_694 , V_711 ) ;
F_138 ( & V_694 -> V_20 -> V_2 ) ;
break;
case V_707 :
F_196 ( & V_694 -> V_367 ) ;
F_284 ( V_694 , F_283 ) ;
F_9 ( & V_694 -> V_20 -> V_699 , V_700 ) ;
break;
case V_708 :
F_196 ( & V_694 -> V_367 ) ;
F_284 ( V_694 , F_283 ) ;
break;
default:
F_5 ( V_694 -> V_20 , V_4 ) ;
}
}
static void
V_711 ( struct V_693 * V_694 , enum V_695 V_4 )
{
F_3 ( V_694 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_709 :
F_285 ( V_694 -> V_20 , & V_694 -> V_367 ,
V_702 , V_694 , V_703 ) ;
F_284 ( V_694 , V_713 ) ;
break;
case V_707 :
F_284 ( V_694 , F_283 ) ;
F_9 ( & V_694 -> V_20 -> V_699 , V_700 ) ;
break;
case V_697 :
case V_708 :
break;
default:
F_5 ( V_694 -> V_20 , V_4 ) ;
}
}
static void
V_713 ( struct V_693 * V_694 , enum V_695 V_4 )
{
F_3 ( V_694 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_712 :
F_284 ( V_694 , V_714 ) ;
F_287 ( V_694 ) ;
break;
case V_709 :
F_196 ( & V_694 -> V_367 ) ;
F_285 ( V_694 -> V_20 , & V_694 -> V_367 ,
V_702 , V_694 , V_703 ) ;
break;
case V_707 :
F_196 ( & V_694 -> V_367 ) ;
F_285 ( V_694 -> V_20 , & V_694 -> V_367 ,
V_702 , V_694 , V_703 ) ;
F_284 ( V_694 , V_715 ) ;
F_287 ( V_694 ) ;
break;
case V_710 :
break;
case V_708 :
F_196 ( & V_694 -> V_367 ) ;
F_284 ( V_694 , V_716 ) ;
break;
default:
F_5 ( V_694 -> V_20 , V_4 ) ;
}
}
static void
V_715 ( struct V_693 * V_694 ,
enum V_695 V_4 )
{
F_3 ( V_694 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_708 :
case V_710 :
F_196 ( & V_694 -> V_367 ) ;
case V_712 :
F_284 ( V_694 , F_283 ) ;
F_9 ( & V_694 -> V_20 -> V_699 , V_700 ) ;
break;
default:
F_5 ( V_694 -> V_20 , V_4 ) ;
}
}
static void
V_714 ( struct V_693 * V_694 , enum V_695 V_4 )
{
F_3 ( V_694 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_710 :
F_284 ( V_694 , V_711 ) ;
break;
case V_709 :
F_285 ( V_694 -> V_20 , & V_694 -> V_367 ,
V_702 , V_694 , V_703 ) ;
F_284 ( V_694 , V_713 ) ;
break;
case V_707 :
F_285 ( V_694 -> V_20 , & V_694 -> V_367 ,
V_702 , V_694 , V_703 ) ;
F_284 ( V_694 , V_715 ) ;
break;
case V_708 :
F_284 ( V_694 , V_716 ) ;
break;
default:
F_5 ( V_694 -> V_20 , V_4 ) ;
}
}
static void
V_716 ( struct V_693 * V_694 ,
enum V_695 V_4 )
{
F_3 ( V_694 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_697 :
F_285 ( V_694 -> V_20 , & V_694 -> V_367 ,
V_702 , V_694 , V_703 ) ;
F_284 ( V_694 , V_713 ) ;
break;
case V_707 :
F_284 ( V_694 , F_283 ) ;
F_9 ( & V_694 -> V_20 -> V_699 , V_700 ) ;
break;
case V_708 :
break;
default:
F_5 ( V_694 -> V_20 , V_4 ) ;
}
}
static void
F_288 ( struct V_717 * V_369 , struct V_718 * V_719 ,
struct V_720 * V_20 )
{
struct V_721 * V_722 = F_289 ( V_20 ) ;
if ( V_369 -> V_723 . V_698 )
F_290 ( V_719 , V_722 ,
sizeof( struct V_724 ) ) ;
else
F_290 ( V_719 , V_722 ,
sizeof( struct V_705 ) ) ;
}
static void
F_291 ( struct V_720 * V_20 , void * V_33 , struct V_717 * V_369 ,
struct V_218 * V_219 )
{
struct V_693 * V_694 = F_292 ( V_20 ) ;
V_694 -> V_33 = V_33 ;
V_694 -> V_20 = V_20 ;
V_694 -> V_541 = V_20 -> V_2 . V_322 ;
F_3 ( V_20 , V_694 -> V_541 ) ;
V_694 -> V_694 = (struct V_705 * ) F_293 ( V_694 ) ;
if ( V_369 -> V_723 . V_698 ) {
F_293 ( V_694 ) += sizeof( struct V_724 ) ;
V_694 -> V_698 = V_77 ;
} else {
V_694 -> V_698 = V_50 ;
F_293 ( V_694 ) += sizeof( struct V_705 ) ;
}
F_294 ( V_20 ) = V_50 ;
F_284 ( V_694 , F_283 ) ;
}
static void
V_706 ( void * V_366 , T_4 V_341 )
{
struct V_720 * V_20 = V_366 ;
struct V_693 * V_694 = F_292 ( V_20 ) ;
if ( V_341 == V_34 ) {
F_294 ( V_20 ) = V_77 ;
if ( V_694 -> V_694 -> V_725 . V_114 != V_726 )
V_694 -> V_694 -> V_725 . V_114 = V_726 ;
if ( V_694 -> V_694 -> V_725 . V_727 != V_728 )
V_694 -> V_694 -> V_725 . V_727 = V_728 ;
}
F_295 ( V_694 , V_710 ) ;
F_9 ( & V_20 -> V_699 , V_700 ) ;
}
void
F_296 ( struct V_720 * V_20 )
{
struct V_693 * V_694 = F_292 ( V_20 ) ;
F_295 ( V_694 , V_697 ) ;
}
static void
F_297 ( struct V_720 * V_20 )
{
}
static void
F_298 ( struct V_720 * V_20 )
{
}
static void V_702 ( void * V_98 )
{
struct V_693 * V_694 = V_98 ;
F_295 ( V_694 , V_712 ) ;
}
static void
F_299 ( struct V_720 * V_20 )
{
struct V_693 * V_694 = F_292 ( V_20 ) ;
F_295 ( V_694 , V_708 ) ;
}
static void
F_300 ( struct V_720 * V_20 )
{
}
static T_4
F_287 ( struct V_693 * V_694 )
{
T_4 V_696 ;
F_3 ( V_694 -> V_20 , 0 ) ;
V_696 = F_246 ( F_286 ( V_694 -> V_20 ) ,
V_704 , V_694 -> V_541 ,
V_694 -> V_694 , sizeof( struct V_705 ) , 0 ,
V_729 , V_694 ) ;
if ( V_696 != V_34 )
F_76 ( V_696 ) ;
F_3 ( V_694 -> V_20 , V_696 ) ;
return V_696 ;
}
T_4
F_301 ( struct V_720 * V_20 )
{
struct V_693 * V_694 = F_292 ( V_20 ) ;
F_3 ( V_694 -> V_20 , 0 ) ;
if ( F_302 ( V_694 , V_716 ) )
return V_186 ;
if ( V_694 -> V_698 ) {
F_3 ( V_694 -> V_20 , V_694 -> V_698 ) ;
return V_186 ;
}
F_295 ( V_694 , V_709 ) ;
return V_34 ;
}
static void
V_729 ( void * V_366 , T_4 V_341 )
{
struct V_693 * V_694 = V_366 ;
F_76 ( V_341 ) ;
F_295 ( V_694 , V_710 ) ;
}
void
F_303 ( struct V_720 * V_20 )
{
struct V_693 * V_694 = F_292 ( V_20 ) ;
F_295 ( V_694 , V_707 ) ;
}
static void
F_304 ( void * V_98 , enum V_93 V_4 )
{
struct V_730 * V_731 = V_98 ;
F_3 ( V_731 , V_4 ) ;
switch ( V_4 ) {
case V_99 :
case V_188 :
if ( V_731 -> V_535 ) {
V_731 -> V_341 = V_21 ;
V_731 -> V_18 ( V_731 -> V_98 , V_731 -> V_341 ) ;
V_731 -> V_535 = 0 ;
}
break;
default:
break;
}
}
static void
F_305 ( void * V_98 , enum V_732 V_733 )
{
struct V_730 * V_731 = V_98 ;
struct V_734 * V_181 =
(struct V_734 * ) V_731 -> V_404 . V_181 ;
T_1 V_128 ;
V_181 -> V_345 = F_124 ( V_731 -> V_542 + V_731 -> V_345 ) ;
V_128 = ( V_731 -> V_543 < V_735 ) ?
V_731 -> V_543 : V_735 ;
V_181 -> V_545 = F_124 ( V_128 ) ;
V_181 -> V_546 = ( V_128 == V_731 -> V_543 ) ? 1 : 0 ;
V_181 -> V_736 = ( V_128 == V_731 -> V_543 ) ? V_731 -> V_736 : 0 ;
F_92 ( V_181 -> V_137 , V_737 , V_733 , F_93 ( V_731 -> V_2 ) ) ;
F_222 ( & V_181 -> V_455 , V_128 , V_731 -> V_457 ) ;
memcpy ( V_731 -> V_473 , V_731 -> V_548 + V_731 -> V_345 , V_128 ) ;
F_142 ( V_731 -> V_2 , & V_731 -> V_404 ) ;
V_731 -> V_543 -= V_128 ;
V_731 -> V_345 += V_128 ;
}
static void
F_306 ( void * V_98 , enum V_732 V_733 )
{
struct V_730 * V_731 = V_98 ;
struct V_738 * V_181 =
(struct V_738 * ) V_731 -> V_404 . V_181 ;
T_1 V_128 ;
V_181 -> V_345 = F_124 ( V_731 -> V_542 + V_731 -> V_345 ) ;
V_128 = ( V_731 -> V_543 < V_735 ) ?
V_731 -> V_543 : V_735 ;
V_181 -> V_545 = F_124 ( V_128 ) ;
F_92 ( V_181 -> V_137 , V_737 , V_733 , F_93 ( V_731 -> V_2 ) ) ;
F_222 ( & V_181 -> V_455 , V_128 , V_731 -> V_457 ) ;
F_142 ( V_731 -> V_2 , & V_731 -> V_404 ) ;
}
T_1
F_307 ( T_2 V_583 )
{
if ( V_583 )
return 0 ;
return F_201 ( V_735 , V_398 ) ;
}
void
F_308 ( struct V_730 * V_731 , struct V_1 * V_2 , void * V_521 ,
struct V_522 * V_523 , T_2 V_583 )
{
V_731 -> V_2 = V_2 ;
V_731 -> V_523 = V_523 ;
V_731 -> V_18 = NULL ;
V_731 -> V_98 = NULL ;
V_731 -> V_535 = 0 ;
F_141 ( V_731 -> V_2 , V_737 , V_739 , V_731 ) ;
F_204 ( & V_731 -> V_401 ) ;
F_205 ( & V_731 -> V_401 , F_304 , V_731 ) ;
F_143 ( & V_731 -> V_401 . V_97 , & V_731 -> V_2 -> V_217 ) ;
if ( V_583 ) {
V_731 -> V_473 = NULL ;
V_731 -> V_457 = 0 ;
}
}
void
F_309 ( struct V_730 * V_731 , T_6 * V_245 , T_7 V_246 ,
T_2 V_583 )
{
if ( V_583 )
return;
V_731 -> V_473 = V_245 ;
V_731 -> V_457 = V_246 ;
memset ( V_731 -> V_473 , 0 , V_735 ) ;
V_245 += F_201 ( V_735 , V_398 ) ;
V_246 += F_201 ( V_735 , V_398 ) ;
}
T_4
F_310 ( struct V_730 * V_731 , void * V_185 , T_1 V_128 , T_1 V_345 ,
T_19 V_18 , void * V_98 , T_6 V_736 )
{
F_3 ( V_731 , V_740 ) ;
F_3 ( V_731 , V_128 ) ;
F_3 ( V_731 , V_345 ) ;
if ( V_731 -> V_2 -> V_155 != V_237 &&
V_731 -> V_2 -> V_163 -> V_165 != V_741 )
return V_742 ;
if ( V_731 -> V_2 -> V_163 -> V_165 != V_743 )
return V_656 ;
if ( ! F_120 ( V_731 -> V_2 ) )
return V_525 ;
if ( V_731 -> V_535 ) {
F_3 ( V_731 , V_731 -> V_535 ) ;
return V_353 ;
}
V_731 -> V_535 = 1 ;
V_731 -> V_18 = V_18 ;
V_731 -> V_98 = V_98 ;
V_731 -> V_543 = V_128 ;
V_731 -> V_345 = 0 ;
V_731 -> V_542 = V_345 ;
V_731 -> V_548 = V_185 ;
V_731 -> V_736 = V_736 ;
F_305 ( V_731 , V_740 ) ;
return V_34 ;
}
T_4
F_311 ( struct V_730 * V_731 , void * V_185 , T_1 V_128 , T_1 V_345 ,
T_19 V_18 , void * V_98 )
{
F_3 ( V_731 , V_744 ) ;
F_3 ( V_731 , V_128 ) ;
F_3 ( V_731 , V_345 ) ;
if ( V_731 -> V_2 -> V_155 != V_237 )
return V_742 ;
if ( V_731 -> V_2 -> V_163 -> V_165 != V_743 &&
V_731 -> V_2 -> V_163 -> V_165 != V_741 )
return V_656 ;
if ( ! F_120 ( V_731 -> V_2 ) )
return V_525 ;
if ( V_731 -> V_535 ) {
F_3 ( V_731 , V_731 -> V_535 ) ;
return V_353 ;
}
V_731 -> V_535 = 1 ;
V_731 -> V_18 = V_18 ;
V_731 -> V_98 = V_98 ;
V_731 -> V_543 = V_128 ;
V_731 -> V_345 = 0 ;
V_731 -> V_542 = V_345 ;
V_731 -> V_548 = V_185 ;
F_306 ( V_731 , V_744 ) ;
return V_34 ;
}
T_4
F_312 ( struct V_730 * V_731 , T_1 * V_745 )
{
if ( V_731 -> V_2 -> V_155 != V_237 )
return V_742 ;
if ( ! F_120 ( V_731 -> V_2 ) )
return V_525 ;
if ( V_731 -> V_2 -> V_163 -> V_165 == V_743 ||
V_731 -> V_2 -> V_163 -> V_165 == V_741 )
* V_745 = V_746 ;
else
return V_656 ;
return V_34 ;
}
T_4
F_313 ( struct V_730 * V_731 , void * V_185 , T_1 V_128 , T_1 V_345 ,
T_19 V_18 , void * V_98 )
{
F_3 ( V_731 , V_747 ) ;
F_3 ( V_731 , V_128 ) ;
F_3 ( V_731 , V_345 ) ;
F_3 ( V_731 , * ( ( T_6 * ) V_185 ) ) ;
if ( V_731 -> V_2 -> V_155 != V_237 )
return V_742 ;
if ( ! F_120 ( V_731 -> V_2 ) )
return V_525 ;
if ( V_731 -> V_535 ) {
F_3 ( V_731 , V_731 -> V_535 ) ;
return V_353 ;
}
V_731 -> V_535 = 1 ;
V_731 -> V_18 = V_18 ;
V_731 -> V_98 = V_98 ;
V_731 -> V_543 = V_128 ;
V_731 -> V_345 = 0 ;
V_731 -> V_542 = V_345 ;
V_731 -> V_548 = V_185 ;
F_305 ( V_731 , V_747 ) ;
return V_34 ;
}
T_4
F_314 ( struct V_730 * V_731 , void * V_185 , T_1 V_128 , T_1 V_345 ,
T_19 V_18 , void * V_98 )
{
F_3 ( V_731 , V_748 ) ;
F_3 ( V_731 , V_128 ) ;
F_3 ( V_731 , V_345 ) ;
if ( V_731 -> V_2 -> V_155 != V_237 )
return V_742 ;
if ( ! F_120 ( V_731 -> V_2 ) )
return V_525 ;
if ( V_731 -> V_535 ) {
F_3 ( V_731 , V_731 -> V_535 ) ;
return V_353 ;
}
V_731 -> V_535 = 1 ;
V_731 -> V_18 = V_18 ;
V_731 -> V_98 = V_98 ;
V_731 -> V_543 = V_128 ;
V_731 -> V_345 = 0 ;
V_731 -> V_542 = V_345 ;
V_731 -> V_548 = V_185 ;
F_306 ( V_731 , V_748 ) ;
return V_34 ;
}
void
V_739 ( void * V_749 , struct V_200 * V_181 )
{
struct V_730 * V_731 = V_749 ;
struct V_750 * V_386 = (struct V_750 * ) V_181 ;
T_1 V_341 ;
F_3 ( V_731 , V_181 -> V_137 . V_203 ) ;
if ( ! V_731 -> V_535 ) {
F_3 ( V_731 , 0x9999 ) ;
return;
}
switch ( V_181 -> V_137 . V_203 ) {
case V_751 :
case V_752 :
V_341 = F_96 ( V_386 -> V_341 ) ;
F_3 ( V_731 , V_341 ) ;
if ( V_341 != V_34 || V_731 -> V_543 == 0 ) {
V_731 -> V_341 = V_341 ;
V_731 -> V_535 = 0 ;
if ( V_731 -> V_18 )
V_731 -> V_18 ( V_731 -> V_98 , V_731 -> V_341 ) ;
} else {
F_3 ( V_731 , V_731 -> V_345 ) ;
if ( V_181 -> V_137 . V_203 == V_751 )
F_305 ( V_731 ,
V_740 ) ;
else
F_305 ( V_731 ,
V_747 ) ;
}
break;
case V_753 :
case V_754 :
V_341 = F_96 ( V_386 -> V_341 ) ;
F_3 ( V_731 , V_341 ) ;
if ( V_341 != V_34 ) {
V_731 -> V_341 = V_341 ;
V_731 -> V_535 = 0 ;
if ( V_731 -> V_18 )
V_731 -> V_18 ( V_731 -> V_98 , V_731 -> V_341 ) ;
} else {
T_1 V_128 = F_96 ( V_386 -> V_545 ) ;
F_3 ( V_731 , V_731 -> V_345 ) ;
F_3 ( V_731 , V_128 ) ;
memcpy ( V_731 -> V_548 + V_731 -> V_345 , V_731 -> V_473 , V_128 ) ;
V_731 -> V_543 -= V_128 ;
V_731 -> V_345 += V_128 ;
if ( V_731 -> V_543 == 0 ) {
V_731 -> V_341 = V_341 ;
V_731 -> V_535 = 0 ;
if ( V_731 -> V_18 )
V_731 -> V_18 ( V_731 -> V_98 , V_731 -> V_341 ) ;
} else {
if ( V_181 -> V_137 . V_203 == V_753 )
F_306 ( V_731 ,
V_744 ) ;
else
F_306 ( V_731 ,
V_748 ) ;
}
}
break;
default:
F_76 ( 1 ) ;
}
}
