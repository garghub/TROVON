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
F_82 ( struct V_1 * V_2 ,
struct V_54 * V_110 )
{
struct V_54 * V_111 ;
enum V_112 V_113 , V_114 ;
V_111 = (struct V_54 * )
F_83 ( F_84 ( V_2 ) , 0 ) ;
V_114 = F_85 ( V_111 , V_110 ) ;
if ( V_114 == V_115 ||
V_114 == V_116 ) {
return V_50 ;
}
V_113 = F_86 ( V_2 , V_110 ) ;
if ( V_113 == V_117 ) {
return V_50 ;
} else if ( V_113 == V_118 ) {
return V_77 ;
} else {
return ( V_114 == V_118 ) ?
V_77 : V_50 ;
}
}
static T_2
F_87 ( struct V_1 * V_2 , T_1 V_119 )
{
struct V_54 V_55 ;
F_32 ( V_2 , & V_55 ) ;
if ( F_33 ( V_55 . V_120 ) != V_119 ) {
F_3 ( V_2 , V_55 . V_120 ) ;
F_3 ( V_2 , V_119 ) ;
return V_50 ;
}
return F_82 ( V_2 , & V_55 ) ;
}
static T_2
F_88 ( struct V_54 * V_121 ,
struct V_54 * V_122 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_123 ; V_61 ++ )
if ( V_121 -> V_124 [ V_61 ] != V_122 -> V_124 [ V_61 ] )
return V_50 ;
return V_77 ;
}
static T_2
F_89 ( struct V_54 * V_111 ,
struct V_54 * V_125 )
{
if ( V_111 -> V_126 != V_125 -> V_126 )
return V_50 ;
if ( V_111 -> V_127 . V_128 != V_125 -> V_127 . V_128 )
return V_50 ;
if ( V_111 -> V_127 . V_129 != V_125 -> V_127 . V_129 )
return V_50 ;
if ( V_111 -> V_127 . V_130 != V_125 -> V_127 . V_130 )
return V_50 ;
if ( V_111 -> V_127 . V_131 == V_125 -> V_127 . V_131 &&
V_111 -> V_127 . V_132 == V_125 -> V_127 . V_132 &&
V_111 -> V_127 . V_133 == V_125 -> V_127 . V_133 ) {
return F_88 ( V_111 , V_125 ) ;
}
return V_77 ;
}
static T_2
F_90 ( struct V_54 * V_134 )
{
if ( V_134 -> V_127 . V_128 == 0 || V_134 -> V_127 . V_128 == 0xFF )
return V_50 ;
return V_77 ;
}
static T_2 F_91 ( struct V_54 * V_55 )
{
if ( V_55 -> V_127 . V_132 == 0 &&
V_55 -> V_127 . V_133 == 0 )
return V_77 ;
return V_50 ;
}
static enum V_112
F_85 ( struct V_54 * V_135 ,
struct V_54 * V_125 )
{
if ( F_89 ( V_135 , V_125 ) == V_50 )
return V_115 ;
if ( V_125 -> V_127 . V_131 > V_135 -> V_127 . V_131 )
return V_117 ;
else if ( V_125 -> V_127 . V_131 < V_135 -> V_127 . V_131 )
return V_116 ;
if ( F_91 ( V_135 ) == V_77 ) {
if ( F_91 ( V_125 ) )
return V_118 ;
else
return V_116 ;
} else {
if ( F_91 ( V_125 ) )
return V_117 ;
}
if ( V_125 -> V_127 . V_132 > V_135 -> V_127 . V_132 )
return V_117 ;
else if ( V_125 -> V_127 . V_132 < V_135 -> V_127 . V_132 )
return V_116 ;
if ( V_125 -> V_127 . V_133 > V_135 -> V_127 . V_133 )
return V_117 ;
else if ( V_125 -> V_127 . V_133 < V_135 -> V_127 . V_133 )
return V_116 ;
return V_118 ;
}
T_4
F_92 ( struct V_1 * V_2 , T_1 V_136 ,
T_1 * V_137 )
{
return F_93 ( V_2 -> V_138 . V_139 ,
V_140 + ( V_136 * sizeof( T_1 ) ) ,
( char * ) V_137 , V_141 ) ;
}
static enum V_112
F_86 ( struct V_1 * V_2 ,
struct V_54 * V_135 )
{
struct V_54 * V_134 ;
T_4 V_142 ;
T_1 V_137 [ V_143 ] ;
V_142 = F_92 ( V_2 , 0 , V_137 ) ;
if ( V_142 != V_34 )
return V_115 ;
V_134 = (struct V_54 * ) V_137 ;
if ( F_90 ( V_134 ) == V_77 )
return F_85 ( V_135 , V_134 ) ;
else
return V_115 ;
}
T_4
F_94 ( struct V_1 * V_2 )
{
T_1 V_58 , V_59 ;
T_1 V_60 = 0 ;
enum V_144 V_145 ;
V_145 = F_30 ( V_2 ) ;
if ( ! F_95 ( V_145 ) )
return V_146 ;
V_58 = F_34 ( V_2 -> V_62 . V_68 , V_60 ) ;
V_59 = F_35 ( V_60 ) ;
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
F_36 ( V_2 -> V_62 . V_70 , V_60 , V_147 ) ;
return V_34 ;
}
static void
F_96 ( struct V_1 * V_2 )
{
T_1 V_56 ;
V_56 = F_28 ( V_2 -> V_62 . V_148 ) ;
if ( V_56 )
F_31 ( 1 , V_2 -> V_62 . V_148 ) ;
}
static void
F_55 ( struct V_1 * V_2 , T_2 V_149 )
{
enum V_144 V_145 ;
T_2 V_150 ;
T_1 V_151 ;
T_1 V_119 ;
V_145 = F_30 ( V_2 ) ;
if ( V_149 )
V_145 = V_64 ;
F_3 ( V_2 , V_145 ) ;
V_151 = V_67 ;
V_119 = V_152 ;
V_150 = ( V_145 == V_64 ) ?
V_50 : F_87 ( V_2 , V_119 ) ;
if ( ! V_150 ) {
if ( F_97 ( V_2 , V_151 , V_119 ) == V_34 )
F_98 ( V_2 ) ;
return;
}
if ( V_145 == V_153 ) {
F_98 ( V_2 ) ;
return;
}
if ( V_145 == V_154 || V_145 == V_155 ) {
F_96 ( V_2 ) ;
F_9 ( & V_2 -> V_7 , V_81 ) ;
return;
}
if ( F_97 ( V_2 , V_151 , V_119 ) == V_34 )
F_98 ( V_2 ) ;
}
static void
F_99 ( void * V_156 )
{
struct V_1 * V_2 = (struct V_1 * ) V_156 ;
F_3 ( V_2 , 0 ) ;
F_9 ( V_2 , V_30 ) ;
}
void
F_100 ( struct V_1 * V_2 , void * V_157 , int V_158 )
{
T_1 * V_159 = ( T_1 * ) V_157 ;
T_1 V_61 ;
F_3 ( V_2 , V_159 [ 0 ] ) ;
F_3 ( V_2 , V_158 ) ;
F_76 ( V_158 > V_160 ) ;
for ( V_61 = 0 ; V_61 < V_158 / sizeof( T_1 ) ; V_61 ++ )
F_31 ( F_101 ( V_159 [ V_61 ] ) ,
V_2 -> V_62 . V_161 + V_61 * sizeof( T_1 ) ) ;
for (; V_61 < V_160 / sizeof( T_1 ) ; V_61 ++ )
F_31 ( 0 , V_2 -> V_62 . V_161 + V_61 * sizeof( T_1 ) ) ;
F_31 ( 1 , V_2 -> V_62 . V_162 ) ;
( void ) F_28 ( V_2 -> V_62 . V_162 ) ;
}
static void
F_58 ( struct V_1 * V_2 )
{
struct V_163 V_164 ;
struct V_165 V_166 ;
F_102 ( V_164 . V_167 , V_168 , V_169 ,
F_103 ( V_2 ) ) ;
V_164 . V_170 = F_104 ( V_2 -> V_170 ) ;
F_105 ( & V_166 ) ;
V_164 . V_171 = F_106 ( V_166 . V_171 ) ;
F_100 ( V_2 , & V_164 , sizeof( struct V_163 ) ) ;
}
static void
F_61 ( struct V_1 * V_2 )
{
struct V_163 V_172 ;
F_102 ( V_172 . V_167 , V_168 , V_173 ,
F_103 ( V_2 ) ) ;
F_100 ( V_2 , & V_172 , sizeof( struct V_163 ) ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
struct V_174 V_175 ;
F_102 ( V_175 . V_167 , V_168 , V_176 ,
F_103 ( V_2 ) ) ;
F_107 ( V_175 . V_177 , V_2 -> V_178 . V_179 ) ;
F_100 ( V_2 , & V_175 , sizeof( V_175 ) ) ;
}
static void
F_108 ( void * V_98 )
{
struct V_1 * V_2 = V_98 ;
T_1 V_180 ;
V_180 = F_28 ( V_2 -> V_62 . V_181 ) ;
if ( V_2 -> V_180 == V_180 ) {
F_109 ( V_2 ) ;
return;
} else {
V_2 -> V_180 = V_180 ;
}
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
}
static void
F_16 ( struct V_1 * V_2 )
{
V_2 -> V_180 = F_28 ( V_2 -> V_62 . V_181 ) ;
F_111 ( V_2 ) ;
}
static T_4
F_112 ( struct V_1 * V_2 , T_1 V_151 ,
T_1 V_119 )
{
T_1 * V_137 ;
T_1 V_58 , V_59 ;
T_1 V_60 = 0 ;
T_1 V_182 = 0 ;
T_1 V_61 ;
T_1 V_183 ;
T_1 V_184 ;
T_1 V_185 [ V_143 ] ;
T_4 V_142 ;
if ( V_119 == V_152 &&
V_151 == V_186 ) {
V_184 = V_187 / sizeof( T_1 ) ;
V_142 = F_92 ( V_2 ,
F_113 ( V_182 ) , V_185 ) ;
if ( V_142 != V_34 )
return V_142 ;
V_137 = V_185 ;
} else {
V_184 = F_114 ( F_84 ( V_2 ) ) ;
V_137 = F_83 ( F_84 ( V_2 ) ,
F_113 ( V_182 ) ) ;
}
F_3 ( V_2 , V_184 ) ;
V_58 = F_34 ( V_2 -> V_62 . V_68 , V_60 ) ;
V_59 = F_35 ( V_60 ) ;
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
for ( V_61 = 0 ; V_61 < V_184 ; V_61 ++ ) {
if ( F_115 ( V_61 ) != V_182 ) {
V_182 = F_115 ( V_61 ) ;
if ( V_119 == V_152 &&
V_151 == V_186 ) {
V_142 = F_92 ( V_2 ,
F_113 ( V_182 ) ,
V_185 ) ;
if ( V_142 != V_34 )
return V_142 ;
V_137 = V_185 ;
} else {
V_137 = F_83 (
F_84 ( V_2 ) ,
F_113 ( V_182 ) ) ;
}
}
F_36 ( V_2 -> V_62 . V_70 , V_60 ,
V_137 [ F_116 ( V_61 ) ] ) ;
V_60 += sizeof( T_1 ) ;
V_60 = F_35 ( V_60 ) ;
if ( V_60 == 0 ) {
V_58 ++ ;
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
}
}
F_31 ( F_34 ( V_2 -> V_62 . V_68 , 0 ) ,
V_2 -> V_62 . V_69 ) ;
if ( V_119 == V_152 &&
V_151 == V_186 ) {
V_151 = V_67 ;
}
V_183 = F_117 ( V_2 -> V_188 , V_2 -> V_189 ,
V_2 -> V_190 , V_2 -> V_191 ) ;
F_36 ( V_2 -> V_62 . V_70 , V_192 ,
F_33 ( V_183 ) ) ;
F_36 ( V_2 -> V_62 . V_70 , V_193 ,
F_33 ( V_151 ) ) ;
F_36 ( V_2 -> V_62 . V_70 , V_194 ,
F_33 ( V_119 ) ) ;
return V_34 ;
}
static void
F_118 ( struct V_1 * V_2 )
{
struct V_195 * V_196 = V_2 -> V_196 ;
V_196 -> V_197 = F_106 ( V_196 -> V_197 ) ;
V_196 -> V_198 = F_106 ( V_196 -> V_198 ) ;
V_196 -> V_199 = F_119 ( V_196 -> V_199 ) ;
V_2 -> V_200 = ( V_196 -> V_201 == V_202 ) ;
V_196 -> V_203 = F_119 ( V_196 -> V_203 ) ;
F_9 ( V_2 , V_28 ) ;
}
static void
F_120 ( struct V_1 * V_2 )
{
struct V_204 * V_205 = & V_2 -> V_206 ;
int V_207 ;
F_121 ( & V_205 -> V_208 ) ;
for ( V_207 = 0 ; V_207 < V_209 ; V_207 ++ ) {
V_205 -> V_210 [ V_207 ] . V_18 = NULL ;
V_205 -> V_210 [ V_207 ] . V_98 = V_2 -> V_20 ;
}
}
static void
F_110 ( struct V_1 * V_2 )
{
struct V_204 * V_205 = & V_2 -> V_206 ;
struct V_211 * V_212 ;
T_1 V_213 ;
if ( F_122 ( & V_205 -> V_208 ) )
return;
V_213 = F_28 ( V_2 -> V_62 . V_162 ) ;
if ( V_213 )
return;
F_123 ( & V_205 -> V_208 , & V_212 ) ;
F_100 ( V_2 , V_212 -> V_214 , sizeof( V_212 -> V_214 ) ) ;
}
static void
F_64 ( struct V_1 * V_2 )
{
struct V_204 * V_205 = & V_2 -> V_206 ;
struct V_211 * V_212 ;
while ( ! F_122 ( & V_205 -> V_208 ) )
F_123 ( & V_205 -> V_208 , & V_212 ) ;
}
static T_4
F_124 ( struct V_1 * V_2 , void * V_215 , T_1 V_216 , T_1 V_217 )
{
T_1 V_58 , V_60 ;
T_5 V_56 ;
int V_61 , V_158 ;
T_1 * V_218 = V_215 ;
V_58 = F_34 ( V_2 -> V_62 . V_68 , V_216 ) ;
V_60 = F_35 ( V_216 ) ;
F_3 ( V_2 , V_58 ) ;
F_3 ( V_2 , V_60 ) ;
F_3 ( V_2 , V_217 ) ;
if ( V_50 == F_74 ( V_2 -> V_62 . V_63 ) ) {
F_3 ( V_2 , 0 ) ;
return V_219 ;
}
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
V_158 = V_217 / sizeof( T_1 ) ;
F_3 ( V_2 , V_158 ) ;
for ( V_61 = 0 ; V_61 < V_158 ; V_61 ++ ) {
V_56 = F_81 ( V_2 -> V_62 . V_70 , V_60 ) ;
V_218 [ V_61 ] = F_33 ( V_56 ) ;
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
F_125 ( struct V_1 * V_2 , T_1 V_216 , T_1 V_217 )
{
int V_61 , V_158 ;
T_1 V_58 , V_60 ;
V_58 = F_34 ( V_2 -> V_62 . V_68 , V_216 ) ;
V_60 = F_35 ( V_216 ) ;
F_3 ( V_2 , V_58 ) ;
F_3 ( V_2 , V_60 ) ;
F_3 ( V_2 , V_217 ) ;
if ( V_50 == F_74 ( V_2 -> V_62 . V_63 ) ) {
F_3 ( V_2 , 0 ) ;
return V_219 ;
}
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
V_158 = V_217 / sizeof( T_1 ) ;
F_3 ( V_2 , V_158 ) ;
for ( V_61 = 0 ; V_61 < V_158 ; V_61 ++ ) {
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
V_2 -> V_18 -> V_220 ( V_2 -> V_20 ) ;
F_15 ( V_2 , V_221 ) ;
F_66 ( V_2 ) ;
F_17 ( V_222 , V_33 , V_37 ,
L_3 ) ;
F_18 ( V_2 , V_223 ) ;
}
static void
F_48 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 -> V_20 -> V_33 ;
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
F_17 ( V_224 , V_33 , V_37 ,
L_4
L_5 ) ;
F_18 ( V_2 , V_225 ) ;
}
T_4
F_126 ( struct V_1 * V_2 )
{
F_74 ( V_2 -> V_62 . V_63 ) ;
F_127 ( V_2 ) ;
V_2 -> V_226 = V_77 ;
F_77 ( V_2 ) ;
F_28 ( V_2 -> V_62 . V_63 ) ;
F_31 ( 1 , V_2 -> V_62 . V_63 ) ;
return V_34 ;
}
T_4
F_97 ( struct V_1 * V_2 , T_1 V_151 , T_1 V_119 )
{
struct V_54 * V_111 ;
T_4 V_142 ;
F_128 ( V_2 , V_227 ) ;
if ( F_126 ( V_2 ) != V_34 )
return V_219 ;
if ( V_119 == V_152 &&
V_151 == V_67 ) {
V_111 = (struct V_54 * )
F_83 ( F_84 ( V_2 ) , 0 ) ;
if ( F_86 ( V_2 , V_111 ) ==
V_117 )
V_151 = V_186 ;
}
if ( V_151 == V_228 ) {
F_37 ( V_2 , V_229 ) ;
F_38 ( V_2 , V_229 ) ;
} else {
F_37 ( V_2 , V_153 ) ;
F_38 ( V_2 , V_153 ) ;
}
F_96 ( V_2 ) ;
V_142 = F_112 ( V_2 , V_151 , V_119 ) ;
if ( V_142 == V_34 )
F_80 ( V_2 ) ;
else {
F_76 ( V_151 == V_228 ) ;
F_129 ( V_2 ) ;
}
return V_142 ;
}
void
F_130 ( T_2 V_40 )
{
V_51 = V_40 ;
}
T_2
F_131 ( struct V_1 * V_2 )
{
return F_132 ( V_2 , V_29 ) ;
}
T_2
F_133 ( struct V_1 * V_2 )
{
T_1 V_56 = F_30 ( V_2 ) ;
return ( ( V_56 != V_64 ) &&
( V_56 != V_153 ) &&
( V_56 != V_229 ) ) ;
}
T_2
F_134 ( struct V_1 * V_2 , void * V_230 )
{
T_5 * V_159 = V_230 ;
T_1 V_56 ;
int V_61 ;
V_56 = F_28 ( V_2 -> V_62 . V_148 ) ;
if ( ( V_56 & 1 ) == 0 )
return V_50 ;
for ( V_61 = 0 ; V_61 < ( sizeof( union V_231 ) / sizeof( T_1 ) ) ;
V_61 ++ ) {
V_56 = F_28 ( V_2 -> V_62 . V_232 +
V_61 * sizeof( T_1 ) ) ;
V_159 [ V_61 ] = F_135 ( V_56 ) ;
}
F_31 ( 1 , V_2 -> V_62 . V_148 ) ;
F_28 ( V_2 -> V_62 . V_148 ) ;
return V_77 ;
}
void
F_136 ( struct V_1 * V_2 , struct V_233 * V_234 )
{
union V_231 * V_214 ;
struct V_48 * V_7 = & V_2 -> V_7 ;
V_214 = (union V_231 * ) V_234 ;
F_128 ( V_2 , V_235 ) ;
switch ( V_214 -> V_167 . V_236 ) {
case V_237 :
break;
case V_238 :
V_2 -> V_201 = V_2 -> V_239 =
(enum V_240 ) V_214 -> V_241 . V_201 ;
V_2 -> V_242 = V_214 -> V_241 . V_243 ;
F_9 ( V_7 , V_86 ) ;
break;
case V_244 :
F_9 ( V_7 , V_90 ) ;
break;
case V_245 :
F_118 ( V_2 ) ;
break;
default:
F_3 ( V_2 , V_214 -> V_167 . V_236 ) ;
F_76 ( 1 ) ;
}
}
void
F_137 ( struct V_1 * V_2 , void * V_20 , struct V_246 * V_18 ,
struct V_247 * V_248 )
{
V_2 -> V_20 = V_20 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_248 = V_248 ;
V_2 -> V_200 = V_50 ;
V_2 -> V_226 = V_50 ;
V_2 -> V_249 = V_77 ;
V_2 -> V_7 . V_2 = V_2 ;
F_120 ( V_2 ) ;
F_121 ( & V_2 -> V_250 ) ;
F_4 ( V_2 , F_2 ) ;
F_9 ( V_2 , V_5 ) ;
}
void
F_138 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_12 ) ;
F_121 ( & V_2 -> V_250 ) ;
}
void
F_139 ( struct V_1 * V_2 , struct V_251 * V_138 ,
enum V_252 V_170 )
{
V_2 -> V_170 = V_170 ;
V_2 -> V_138 = * V_138 ;
V_2 -> V_190 = V_2 -> V_191 = V_202 ;
V_2 -> V_189 = V_253 ;
switch ( V_138 -> V_254 ) {
case V_255 :
case V_256 :
V_2 -> V_188 = V_257 ;
V_2 -> V_200 = V_77 ;
V_2 -> V_201 = V_2 -> V_239 = V_258 ;
V_2 -> V_242 = V_259 ;
break;
case V_260 :
V_2 -> V_188 = V_261 ;
V_2 -> V_190 = V_2 -> V_191 = V_262 ;
V_2 -> V_189 = V_263 ;
V_2 -> V_201 = V_2 -> V_239 = V_264 ;
V_2 -> V_242 = V_265 ;
break;
case V_266 :
V_2 -> V_188 = V_261 ;
V_2 -> V_200 = V_77 ;
V_2 -> V_201 = V_2 -> V_239 = V_258 ;
V_2 -> V_242 = V_259 ;
break;
case V_267 :
case V_268 :
V_2 -> V_188 = V_269 ;
if ( V_170 == V_270 &&
V_138 -> V_271 == V_272 ) {
V_2 -> V_189 = V_273 ;
V_2 -> V_200 = V_77 ;
V_2 -> V_201 = V_2 -> V_239 = V_258 ;
V_2 -> V_242 = V_259 ;
} else {
V_2 -> V_190 = V_2 -> V_191 = V_262 ;
V_2 -> V_189 = V_263 ;
if ( V_138 -> V_271 == V_274 ) {
V_2 -> V_201 =
V_2 -> V_239 = V_264 ;
V_2 -> V_242 = V_265 ;
} else {
V_2 -> V_201 =
V_2 -> V_239 = V_275 ;
V_2 -> V_242 = V_276 ;
}
}
break;
default:
F_76 ( 1 ) ;
}
if ( V_2 -> V_188 == V_257 )
F_140 ( V_2 ) ;
else if ( V_2 -> V_188 == V_261 )
F_141 ( V_2 ) ;
else {
F_76 ( V_2 -> V_188 != V_269 ) ;
F_142 ( V_2 ) ;
F_143 ( V_2 ) ;
}
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
}
void
F_146 ( struct V_1 * V_2 , T_6 * V_277 , T_7 V_278 )
{
V_2 -> V_178 . V_279 = V_277 ;
V_2 -> V_178 . V_179 = V_278 ;
V_2 -> V_196 = (struct V_195 * ) V_277 ;
}
void
F_147 ( struct V_1 * V_2 )
{
F_128 ( V_2 , V_280 ) ;
V_2 -> V_249 = V_77 ;
F_9 ( V_2 , V_9 ) ;
}
void
F_148 ( struct V_1 * V_2 )
{
F_128 ( V_2 , V_281 ) ;
F_9 ( V_2 , V_11 ) ;
}
void
F_149 ( struct V_1 * V_2 )
{
V_2 -> V_249 = V_77 ;
F_9 ( V_2 , V_17 ) ;
}
void
F_150 ( struct V_1 * V_2 , void * V_282 )
{
V_2 -> V_282 = V_282 ;
V_2 -> V_283 = V_284 ;
}
void
F_151 ( struct V_1 * V_2 , T_8 * V_285 )
{
struct V_204 * V_205 = & V_2 -> V_206 ;
int V_207 ;
for ( V_207 = 0 ; V_207 < V_209 ; V_207 ++ )
V_205 -> V_210 [ V_207 ] . V_18 = V_285 [ V_207 ] ;
}
void
F_152 ( struct V_1 * V_2 , enum V_286 V_207 ,
T_8 V_18 , void * V_98 )
{
struct V_204 * V_205 = & V_2 -> V_206 ;
V_205 -> V_210 [ V_207 ] . V_18 = V_18 ;
V_205 -> V_210 [ V_207 ] . V_98 = V_98 ;
}
void
F_153 ( struct V_1 * V_2 , struct V_211 * V_212 )
{
struct V_204 * V_205 = & V_2 -> V_206 ;
T_1 V_213 ;
if ( ! F_122 ( & V_205 -> V_208 ) ) {
F_154 ( & V_212 -> V_97 , & V_205 -> V_208 ) ;
return;
}
V_213 = F_28 ( V_2 -> V_62 . V_162 ) ;
if ( V_213 ) {
F_154 ( & V_212 -> V_97 , & V_205 -> V_208 ) ;
return;
}
F_100 ( V_2 , V_212 -> V_214 , sizeof( V_212 -> V_214 ) ) ;
}
void
F_155 ( struct V_1 * V_2 )
{
struct V_204 * V_205 = & V_2 -> V_206 ;
struct V_233 V_234 ;
int V_207 ;
if ( F_134 ( V_2 , & V_234 ) ) {
V_207 = V_234 . V_167 . V_287 ;
if ( V_207 == V_168 ) {
F_136 ( V_2 , & V_234 ) ;
return;
}
if ( ( V_207 >= V_209 ) || ( V_205 -> V_210 [ V_207 ] . V_18 == NULL ) )
return;
V_205 -> V_210 [ V_207 ] . V_18 ( V_205 -> V_210 [ V_207 ] . V_98 , & V_234 ) ;
}
F_156 ( V_2 ) ;
F_110 ( V_2 ) ;
}
void
F_157 ( struct V_1 * V_2 )
{
F_128 ( V_2 , V_288 ) ;
V_2 -> V_289 . V_180 = V_2 -> V_180 ;
F_9 ( V_2 , V_17 ) ;
}
T_2
F_158 ( struct V_1 * V_2 )
{
return F_132 ( V_2 , V_26 ) ||
F_132 ( V_2 , V_46 ) ;
}
T_2
F_159 ( struct V_1 * V_2 )
{
return F_132 ( V_2 , V_6 ) ||
F_132 ( & V_2 -> V_7 , V_53 ) ||
F_132 ( & V_2 -> V_7 , V_74 ) ;
}
T_2
F_160 ( struct V_1 * V_2 )
{
T_1 V_290 ;
if ( ! F_132 ( V_2 , V_46 ) )
return V_50 ;
V_290 = F_30 ( V_2 ) ;
if ( ! F_95 ( V_290 ) )
return V_50 ;
if ( V_2 -> V_138 . V_254 != V_255 ) {
V_290 = F_30 ( V_2 ) ;
if ( ! F_95 ( V_290 ) )
return V_50 ;
}
return V_77 ;
}
void
F_161 ( struct V_1 * V_2 )
{
F_37 ( V_2 , V_64 ) ;
F_38 ( V_2 , V_64 ) ;
}
void
F_162 ( struct V_1 * V_2 ,
struct V_291 * V_292 )
{
struct V_195 * V_293 ;
V_293 = V_2 -> V_196 ;
F_163 ( V_2 , V_292 -> V_294 ) ;
F_164 ( V_2 , V_292 -> V_295 ) ;
F_165 ( V_2 , V_292 -> V_296 ) ;
F_166 ( V_2 , V_292 -> V_297 ) ;
memcpy ( & V_292 -> V_298 , & V_293 -> V_298 ,
sizeof( struct V_299 ) ) ;
V_292 -> V_300 = F_167 ( V_2 ) ;
V_292 -> V_301 = F_168 ( V_2 ) ;
F_169 ( V_2 , V_292 -> V_302 ) ;
F_169 ( V_2 , V_292 -> V_303 ) ;
V_292 -> V_198 = V_293 -> V_198 ;
V_292 -> V_304 = F_170 ( V_293 -> V_198 ) ;
if ( F_171 ( V_293 -> V_197 ) )
V_292 -> V_305 = 1 ;
else
V_292 -> V_305 = 0 ;
V_292 -> V_306 = V_2 -> V_196 -> V_306 ;
V_292 -> V_307 = F_172 ( V_2 ) ;
V_292 -> V_308 = V_293 -> V_308 ;
V_292 -> V_309 = V_293 -> V_309 ;
V_292 -> V_310 = V_293 -> V_310 ;
V_292 -> V_311 = V_293 -> V_311 ;
F_173 ( V_2 , V_292 -> V_312 ) ;
V_292 -> V_313 = F_174 ( V_2 ) ;
V_292 -> V_314 = ( V_292 -> V_300 > 1 ) &&
! F_174 ( V_2 ) && ! V_292 -> V_304 ;
V_292 -> V_315 = V_293 -> V_315 ;
V_292 -> V_316 = V_293 -> V_316 ;
V_292 -> V_203 = V_293 -> V_203 ;
memcpy ( V_292 -> V_317 , V_293 -> V_317 , V_318 ) ;
}
enum V_319
F_175 ( struct V_1 * V_2 )
{
if ( V_2 -> V_170 == V_320 )
return V_321 ;
F_76 ( V_2 -> V_170 != V_270 ) ;
return ( V_2 -> V_196 -> V_201 == V_202 )
? V_322 : V_323 ;
}
void
F_163 ( struct V_1 * V_2 , char * V_294 )
{
memset ( ( void * ) V_294 , 0 , V_324 ) ;
memcpy ( ( void * ) V_294 ,
( void * ) V_2 -> V_196 -> V_325 ,
V_324 ) ;
}
void
F_164 ( struct V_1 * V_2 , char * V_295 )
{
memset ( ( void * ) V_295 , 0 , V_326 ) ;
memcpy ( V_295 , V_2 -> V_196 -> V_327 , V_326 ) ;
}
void
F_173 ( struct V_1 * V_2 , char * V_328 )
{
F_76 ( ! V_328 ) ;
memset ( ( void * ) V_328 , 0 , V_329 ) ;
V_328 [ 0 ] = 'R' ;
V_328 [ 1 ] = 'e' ;
V_328 [ 2 ] = 'v' ;
V_328 [ 3 ] = '-' ;
V_328 [ 4 ] = V_2 -> V_196 -> V_311 ;
V_328 [ 5 ] = '\0' ;
}
void
F_165 ( struct V_1 * V_2 , char * V_296 )
{
memset ( ( void * ) V_296 , 0 , V_326 ) ;
memcpy ( V_296 , V_2 -> V_196 -> V_330 ,
V_326 ) ;
}
void
F_166 ( struct V_1 * V_2 , char * V_297 )
{
memset ( ( void * ) V_297 , 0 , V_331 ) ;
memcpy ( V_297 , V_332 , V_331 ) ;
}
void
F_169 ( struct V_1 * V_2 , char * V_302 )
{
struct V_195 * V_293 ;
T_6 V_300 = F_167 ( V_2 ) ;
F_76 ( ! V_302 ) ;
memset ( ( void * ) V_302 , 0 , V_333 ) ;
V_293 = V_2 -> V_196 ;
if ( F_176 ( V_2 -> V_138 . V_254 ) &&
( ! F_170 ( V_293 -> V_198 ) ) )
snprintf ( V_302 , V_333 , L_6 ,
V_332 , V_293 -> V_198 , V_300 , L_7 ) ;
else
snprintf ( V_302 , V_333 , L_8 ,
V_332 , V_293 -> V_198 ) ;
}
enum V_334
F_177 ( struct V_1 * V_2 )
{
enum V_335 V_336 ;
enum V_334 V_337 = F_178 ( V_338 , V_2 -> V_339 ) ;
if ( V_337 == V_340 ||
V_337 == V_341 || V_337 == V_342 ) {
V_336 = F_178 ( V_343 , V_2 -> V_7 . V_339 ) ;
switch ( V_336 ) {
case V_344 :
V_337 = V_345 ;
break;
case V_346 :
V_337 = V_347 ;
break;
case V_348 :
V_337 = V_349 ;
break;
case V_350 :
V_337 = V_341 ;
break;
case V_351 :
V_337 = V_342 ;
break;
default:
break;
}
}
return V_337 ;
}
void
F_179 ( struct V_1 * V_2 , struct V_352 * V_293 )
{
memset ( ( void * ) V_293 , 0 , sizeof( struct V_352 ) ) ;
V_293 -> V_353 = F_177 ( V_2 ) ;
V_293 -> V_354 = F_103 ( V_2 ) ;
V_293 -> V_201 = V_2 -> V_201 ;
V_293 -> V_239 = V_2 -> V_239 ;
V_293 -> V_243 = V_2 -> V_242 ;
V_293 -> V_355 = F_175 ( V_2 ) ;
F_162 ( V_2 , & V_293 -> V_356 ) ;
V_293 -> V_357 . V_254 = F_180 ( V_2 ) ;
V_293 -> V_357 . V_358 = F_181 ( V_2 ) ;
V_293 -> V_359 = ( F_181 ( V_2 ) == F_103 ( V_2 ) ) ;
F_173 ( V_2 , V_293 -> V_357 . V_328 ) ;
}
T_9
F_172 ( struct V_1 * V_2 )
{
if ( F_175 ( V_2 ) == V_323 )
return V_2 -> V_196 -> V_360 ;
else
return V_2 -> V_196 -> V_307 ;
}
T_9
F_182 ( struct V_1 * V_2 )
{
T_9 V_234 ;
V_234 = V_2 -> V_196 -> V_361 ;
if ( F_183 ( V_2 -> V_196 -> V_198 ) )
V_234 . V_307 [ V_362 - 1 ] += F_181 ( V_2 ) ;
else
F_184 ( & ( V_234 . V_307 [ V_362 - 3 ] ) ,
F_181 ( V_2 ) ) ;
return V_234 ;
}
void
F_18 ( struct V_1 * V_2 , enum V_363 V_4 )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 -> V_20 -> V_33 ;
struct V_364 * V_365 ;
enum V_319 V_355 ;
F_185 ( V_33 , V_365 ) ;
if ( ! V_365 )
return;
V_355 = F_175 ( V_2 ) ;
switch ( V_355 ) {
case V_322 :
V_365 -> V_366 . V_2 . V_306 = V_2 -> V_196 -> V_306 ;
break;
case V_323 :
V_365 -> V_366 . V_2 . V_306 = V_2 -> V_196 -> V_306 ;
V_365 -> V_366 . V_2 . V_307 = F_172 ( V_2 ) ;
break;
case V_321 :
V_365 -> V_366 . V_2 . V_307 = F_172 ( V_2 ) ;
break;
default:
F_76 ( V_355 != V_322 ) ;
break;
}
V_365 -> V_366 . V_2 . V_355 = V_355 ;
F_186 ( V_365 , V_33 , ++ V_2 -> V_367 ,
V_368 , V_4 ) ;
}
T_4
F_187 ( struct V_1 * V_2 , void * V_369 , int * V_370 )
{
int V_371 ;
if ( V_2 -> V_283 == 0 )
return V_372 ;
V_371 = * V_370 ;
if ( V_371 > V_2 -> V_283 )
V_371 = V_2 -> V_283 ;
memcpy ( V_369 , V_2 -> V_282 , V_371 ) ;
* V_370 = V_371 ;
return V_34 ;
}
T_4
F_188 ( struct V_1 * V_2 , void * V_369 , int * V_370 )
{
T_1 V_60 = F_189 ( F_103 ( V_2 ) ) ;
int V_371 ;
T_4 V_142 ;
F_3 ( V_2 , * V_370 ) ;
V_371 = * V_370 ;
if ( V_371 > V_284 )
V_371 = V_284 ;
V_142 = F_124 ( V_2 , V_369 , V_60 , V_371 ) ;
* V_370 = V_371 ;
return V_142 ;
}
static void
F_190 ( struct V_1 * V_2 )
{
struct V_211 V_212 ;
struct V_163 * V_373 = (struct V_163 * ) V_212 . V_214 ;
F_102 ( V_373 -> V_167 , V_168 , V_374 ,
F_103 ( V_2 ) ) ;
V_373 -> V_170 = F_104 ( V_2 -> V_170 ) ;
F_153 ( V_2 , & V_212 ) ;
}
static void
F_191 ( struct V_1 * V_2 )
{
T_1 V_375 = 1000 ;
F_190 ( V_2 ) ;
while ( F_192 ( V_2 ) && V_375 > 0 )
V_375 -- ;
}
T_4
F_193 ( struct V_1 * V_2 , void * V_218 ,
T_1 * V_376 , int * V_377 )
{
T_1 V_60 ;
int V_378 ;
T_4 V_142 ;
T_1 V_379 = F_194 ( V_2 ) ;
if ( * V_376 >= V_379 ) {
* V_376 = * V_377 = 0 ;
return V_380 ;
}
V_60 = * V_376 ;
V_378 = * V_377 ;
if ( V_60 == 0 )
F_191 ( V_2 ) ;
if ( ( V_60 + V_378 ) >= V_379 )
V_378 = V_379 - V_60 ;
V_142 = F_124 ( V_2 , V_218 , V_60 , V_378 ) ;
if ( V_142 != V_34 ) {
* V_376 = * V_377 = 0 ;
return V_142 ;
}
* V_376 += V_378 ;
if ( * V_376 >= V_379 )
* V_376 = 0 ;
* V_377 = V_378 ;
return V_142 ;
}
T_4
F_195 ( struct V_1 * V_2 , void * V_289 )
{
T_1 V_60 = V_381 + \
V_382 * ( F_103 ( V_2 ) ) ;
int V_371 ;
T_4 V_142 ;
if ( V_2 -> V_383 ) {
F_3 ( V_2 , V_2 -> V_383 ) ;
return V_384 ;
}
V_2 -> V_383 = V_77 ;
V_371 = sizeof( struct V_385 ) ;
V_142 = F_124 ( V_2 , V_289 , V_60 , V_371 ) ;
V_2 -> V_383 = V_50 ;
return V_142 ;
}
T_4
F_196 ( struct V_1 * V_2 )
{
T_1 V_60 = V_381 + \
V_382 * ( F_103 ( V_2 ) ) ;
int V_371 ;
T_4 V_142 ;
if ( V_2 -> V_383 ) {
F_3 ( V_2 , V_2 -> V_383 ) ;
return V_384 ;
}
V_2 -> V_383 = V_77 ;
V_371 = sizeof( struct V_385 ) ;
V_142 = F_125 ( V_2 , V_60 , V_371 ) ;
V_2 -> V_383 = V_50 ;
return V_142 ;
}
void
F_66 ( struct V_1 * V_2 )
{
int V_371 ;
if ( V_2 -> V_249 ) {
V_2 -> V_249 = V_50 ;
if ( V_2 -> V_283 ) {
V_371 = V_2 -> V_283 ;
F_188 ( V_2 , V_2 -> V_282 , & V_371 ) ;
}
}
}
static void
F_109 ( struct V_1 * V_2 )
{
F_128 ( V_2 , V_288 ) ;
V_2 -> V_289 . V_180 = V_2 -> V_180 ;
F_9 ( V_2 , V_39 ) ;
}
static void
F_129 ( void * V_156 )
{
struct V_1 * V_2 = (struct V_1 * ) V_156 ;
F_3 ( V_2 , 0 ) ;
F_9 ( & V_2 -> V_7 , V_78 ) ;
}
static void
F_197 ( void * V_156 )
{
struct V_1 * V_2 = (struct V_1 * ) V_156 ;
F_40 ( V_2 ) ;
}
static void
F_98 ( struct V_1 * V_2 )
{
T_1 V_57 = F_30 ( V_2 ) ;
F_3 ( V_2 , V_57 ) ;
if ( V_57 == V_154 ) {
F_9 ( & V_2 -> V_7 , V_81 ) ;
return;
}
if ( V_2 -> V_7 . V_80 >= ( 3 * V_386 ) )
F_129 ( V_2 ) ;
else {
V_2 -> V_7 . V_80 += V_387 ;
F_198 ( V_2 ) ;
}
}
static void
F_199 ( void * V_156 )
{
struct V_1 * V_2 = (struct V_1 * ) V_156 ;
F_98 ( V_2 ) ;
}
void
F_200 ( struct V_247 * V_205 )
{
struct V_96 * V_388 = & V_205 -> V_389 ;
struct V_96 * V_97 , * V_390 ;
struct V_391 * V_392 ;
struct V_96 V_393 ;
F_121 ( & V_393 ) ;
V_97 = F_201 ( V_388 ) ;
while ( V_97 != V_388 ) {
V_390 = F_201 ( V_97 ) ;
V_392 = (struct V_391 * ) V_97 ;
if ( V_392 -> V_394 <= V_395 ) {
V_392 -> V_394 = 0 ;
F_202 ( & V_392 -> V_97 ) ;
F_154 ( & V_392 -> V_97 , & V_393 ) ;
} else {
V_392 -> V_394 -= V_395 ;
}
V_97 = V_390 ;
}
while ( ! F_122 ( & V_393 ) ) {
F_123 ( & V_393 , & V_392 ) ;
V_392 -> V_396 ( V_392 -> V_397 ) ;
}
}
void
F_203 ( struct V_247 * V_205 , struct V_391 * V_398 ,
void (* V_396) ( void * ) , void * V_397 , unsigned int V_394 )
{
F_76 ( V_396 == NULL ) ;
F_76 ( F_204 ( & V_205 -> V_389 , V_398 ) ) ;
V_398 -> V_394 = V_394 ;
V_398 -> V_396 = V_396 ;
V_398 -> V_397 = V_397 ;
F_154 ( & V_398 -> V_97 , & V_205 -> V_389 ) ;
}
void
F_205 ( struct V_391 * V_398 )
{
F_76 ( F_122 ( & V_398 -> V_97 ) ) ;
F_202 ( & V_398 -> V_97 ) ;
}
static void
F_206 ( struct V_399 * V_400 )
{
struct V_401 * V_402 ;
int V_61 , V_403 ;
T_10 V_404 ;
for ( V_61 = 0 ; V_61 < V_405 ; V_61 ++ ) {
V_402 = & V_400 -> V_406 [ V_61 ] ;
for ( V_403 = 0 ; V_403 < V_407 ; V_403 ++ ) {
V_404 = V_402 -> V_408 [ V_403 ] . V_409 ;
V_402 -> V_408 [ V_403 ] . V_409 = F_119 ( V_404 ) ;
V_404 = V_402 -> V_408 [ V_403 ] . V_410 ;
V_402 -> V_408 [ V_403 ] . V_410 = F_119 ( V_404 ) ;
V_404 = V_402 -> V_408 [ V_403 ] . V_411 ;
V_402 -> V_408 [ V_403 ] . V_411 = F_119 ( V_404 ) ;
V_404 = V_402 -> V_408 [ V_403 ] . V_412 ;
V_402 -> V_408 [ V_403 ] . V_412 = F_119 ( V_404 ) ;
V_404 = V_402 -> V_408 [ V_403 ] . V_413 ;
V_402 -> V_408 [ V_403 ] . V_413 = F_119 ( V_404 ) ;
}
}
}
static void
F_207 ( void * V_98 , struct V_233 * V_214 )
{
struct V_414 * V_415 = (struct V_414 * ) V_98 ;
struct V_416 * V_417 = (struct V_416 * ) V_214 ;
T_11 V_18 ;
F_76 ( V_214 -> V_167 . V_287 != V_418 ) ;
F_3 ( V_415 -> V_2 , V_214 -> V_167 . V_236 ) ;
switch ( V_214 -> V_167 . V_236 ) {
case V_419 :
if ( V_417 -> V_142 == V_34 ) {
memcpy ( V_415 -> V_400 , V_415 -> V_420 . V_279 ,
sizeof( struct V_399 ) ) ;
F_206 ( V_415 -> V_400 ) ;
V_415 -> V_400 = NULL ;
}
break;
case V_421 :
case V_422 :
V_415 -> V_2 -> V_239 = V_417 -> V_201 ;
case V_423 :
case V_424 :
case V_425 :
case V_426 :
break;
case V_427 :
* ( V_415 -> V_358 ) = V_417 -> V_358 ;
V_415 -> V_358 = NULL ;
break;
default:
F_76 ( 1 ) ;
}
V_415 -> V_428 = V_50 ;
if ( V_415 -> V_18 ) {
V_18 = V_415 -> V_18 ;
V_415 -> V_18 = NULL ;
V_18 ( V_415 -> V_98 , V_417 -> V_142 ) ;
}
}
static void
F_208 ( void * V_98 , enum V_93 V_4 )
{
struct V_414 * V_415 = (struct V_414 * ) V_98 ;
F_3 ( V_415 -> V_2 , V_4 ) ;
switch ( V_4 ) {
case V_35 :
F_76 ( V_415 -> V_428 != V_50 ) ;
break;
case V_99 :
case V_221 :
V_415 -> V_358 = NULL ;
if ( V_415 -> V_428 ) {
if ( V_415 -> V_18 )
V_415 -> V_18 ( V_415 -> V_98 , V_219 ) ;
V_415 -> V_18 = NULL ;
V_415 -> V_428 = V_50 ;
}
break;
default:
F_76 ( 1 ) ;
break;
}
}
T_1
F_209 ( void )
{
return F_210 ( sizeof( struct V_399 ) , V_429 ) ;
}
void
F_211 ( struct V_414 * V_415 , T_6 * V_430 , T_7 V_431 )
{
V_415 -> V_420 . V_279 = V_430 ;
V_415 -> V_420 . V_179 = V_431 ;
}
void
F_212 ( struct V_414 * V_415 , struct V_1 * V_2 )
{
V_415 -> V_2 = V_2 ;
F_152 ( V_415 -> V_2 , V_418 , F_207 , V_415 ) ;
F_213 ( & V_415 -> V_432 ) ;
F_214 ( & V_415 -> V_432 , F_208 , V_415 ) ;
F_154 ( & V_415 -> V_432 . V_97 , & V_415 -> V_2 -> V_250 ) ;
}
T_4
F_215 ( struct V_414 * V_415 , struct V_399 * V_433 ,
T_11 V_18 , void * V_98 )
{
struct V_434 * V_234 ;
F_76 ( ! V_433 ) ;
if ( ! F_131 ( V_415 -> V_2 ) ) {
F_3 ( V_415 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_415 -> V_428 ) {
F_3 ( V_415 -> V_2 , V_384 ) ;
return V_384 ;
}
V_415 -> V_400 = V_433 ;
V_415 -> V_18 = V_18 ;
V_415 -> V_98 = V_98 ;
V_415 -> V_428 = V_77 ;
V_234 = (struct V_434 * ) V_415 -> V_435 . V_214 ;
F_102 ( V_234 -> V_167 , V_418 , V_436 ,
F_103 ( V_415 -> V_2 ) ) ;
F_107 ( V_234 -> V_437 , V_415 -> V_420 . V_179 ) ;
F_153 ( V_415 -> V_2 , & V_415 -> V_435 ) ;
return V_34 ;
}
T_4
F_216 ( struct V_414 * V_415 , T_10 * V_358 ,
T_6 V_438 , enum V_252 V_439 ,
T_10 V_412 , T_10 V_413 ,
T_11 V_18 , void * V_98 )
{
struct V_440 * V_234 ;
if ( ! F_131 ( V_415 -> V_2 ) ) {
F_3 ( V_415 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_415 -> V_428 ) {
F_3 ( V_415 -> V_2 , V_384 ) ;
return V_384 ;
}
V_415 -> V_358 = V_358 ;
V_415 -> V_18 = V_18 ;
V_415 -> V_98 = V_98 ;
V_415 -> V_428 = V_77 ;
V_234 = (struct V_440 * ) V_415 -> V_435 . V_214 ;
F_102 ( V_234 -> V_167 , V_418 , V_441 ,
F_103 ( V_415 -> V_2 ) ) ;
V_234 -> V_409 = F_104 ( ( T_10 ) V_439 ) ;
V_234 -> V_412 = F_104 ( V_412 ) ;
V_234 -> V_413 = F_104 ( V_413 ) ;
V_234 -> V_438 = V_438 ;
F_153 ( V_415 -> V_2 , & V_415 -> V_435 ) ;
return V_34 ;
}
T_4
F_217 ( struct V_414 * V_415 , int V_358 ,
T_11 V_18 , void * V_98 )
{
struct V_440 * V_234 ;
if ( ! F_131 ( V_415 -> V_2 ) ) {
F_3 ( V_415 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_415 -> V_428 ) {
F_3 ( V_415 -> V_2 , V_384 ) ;
return V_384 ;
}
V_415 -> V_18 = V_18 ;
V_415 -> V_98 = V_98 ;
V_415 -> V_428 = V_77 ;
V_234 = (struct V_440 * ) V_415 -> V_435 . V_214 ;
F_102 ( V_234 -> V_167 , V_418 , V_442 ,
F_103 ( V_415 -> V_2 ) ) ;
V_234 -> V_358 = ( T_6 ) V_358 ;
F_153 ( V_415 -> V_2 , & V_415 -> V_435 ) ;
return V_34 ;
}
T_4
F_218 ( struct V_414 * V_415 , enum V_240 V_443 ,
int V_444 , int V_445 , T_11 V_18 , void * V_98 )
{
struct V_446 * V_234 ;
if ( ! F_131 ( V_415 -> V_2 ) ) {
F_3 ( V_415 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_415 -> V_428 ) {
F_3 ( V_415 -> V_2 , V_384 ) ;
return V_384 ;
}
V_415 -> V_18 = V_18 ;
V_415 -> V_98 = V_98 ;
V_415 -> V_428 = V_77 ;
V_234 = (struct V_446 * ) V_415 -> V_435 . V_214 ;
F_102 ( V_234 -> V_167 , V_418 , V_447 ,
F_103 ( V_415 -> V_2 ) ) ;
V_234 -> V_443 = ( T_6 ) V_443 ;
V_234 -> V_444 = ( T_6 ) V_444 ;
V_234 -> V_445 = ( T_6 ) V_445 ;
F_153 ( V_415 -> V_2 , & V_415 -> V_435 ) ;
return V_34 ;
}
T_4
F_219 ( struct V_414 * V_415 , int V_438 , enum V_240 V_443 ,
int V_444 , int V_445 , T_11 V_18 , void * V_98 )
{
struct V_446 * V_234 ;
if ( ! F_131 ( V_415 -> V_2 ) ) {
F_3 ( V_415 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_415 -> V_428 ) {
F_3 ( V_415 -> V_2 , V_384 ) ;
return V_384 ;
}
V_415 -> V_18 = V_18 ;
V_415 -> V_98 = V_98 ;
V_415 -> V_428 = V_77 ;
V_234 = (struct V_446 * ) V_415 -> V_435 . V_214 ;
F_102 ( V_234 -> V_167 , V_418 , V_448 ,
F_103 ( V_415 -> V_2 ) ) ;
V_234 -> V_438 = ( T_6 ) V_438 ;
V_234 -> V_443 = ( T_6 ) V_443 ;
V_234 -> V_444 = ( T_6 ) V_444 ;
V_234 -> V_445 = ( T_6 ) V_445 ;
F_153 ( V_415 -> V_2 , & V_415 -> V_435 ) ;
return V_34 ;
}
T_4
F_220 ( struct V_414 * V_415 , int V_358 , T_10 V_412 ,
T_10 V_413 , T_11 V_18 , void * V_98 )
{
struct V_440 * V_234 ;
if ( ! F_131 ( V_415 -> V_2 ) ) {
F_3 ( V_415 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_415 -> V_428 ) {
F_3 ( V_415 -> V_2 , V_384 ) ;
return V_384 ;
}
V_415 -> V_18 = V_18 ;
V_415 -> V_98 = V_98 ;
V_415 -> V_428 = V_77 ;
V_234 = (struct V_440 * ) V_415 -> V_435 . V_214 ;
F_102 ( V_234 -> V_167 , V_418 , V_449 ,
F_103 ( V_415 -> V_2 ) ) ;
V_234 -> V_358 = ( T_6 ) V_358 ;
V_234 -> V_412 = F_104 ( V_412 ) ;
V_234 -> V_413 = F_104 ( V_413 ) ;
F_153 ( V_415 -> V_2 , & V_415 -> V_435 ) ;
return V_34 ;
}
T_4
F_221 ( struct V_414 * V_415 , T_11 V_18 , void * V_98 )
{
struct V_450 * V_234 ;
if ( ! F_131 ( V_415 -> V_2 ) ) {
F_3 ( V_415 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_415 -> V_428 ) {
F_3 ( V_415 -> V_2 , V_384 ) ;
return V_384 ;
}
V_415 -> V_18 = V_18 ;
V_415 -> V_98 = V_98 ;
V_415 -> V_428 = V_77 ;
V_234 = (struct V_450 * ) V_415 -> V_435 . V_214 ;
F_102 ( V_234 -> V_167 , V_418 , V_451 ,
F_103 ( V_415 -> V_2 ) ) ;
F_153 ( V_415 -> V_2 , & V_415 -> V_435 ) ;
return V_34 ;
}
T_4
F_222 ( struct V_414 * V_415 , T_11 V_18 , void * V_98 )
{
struct V_450 * V_234 ;
if ( ! F_131 ( V_415 -> V_2 ) ) {
F_3 ( V_415 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_415 -> V_428 ) {
F_3 ( V_415 -> V_2 , V_384 ) ;
return V_384 ;
}
V_415 -> V_18 = V_18 ;
V_415 -> V_98 = V_98 ;
V_415 -> V_428 = V_77 ;
V_234 = (struct V_450 * ) V_415 -> V_435 . V_214 ;
F_102 ( V_234 -> V_167 , V_418 , V_452 ,
F_103 ( V_415 -> V_2 ) ) ;
F_153 ( V_415 -> V_2 , & V_415 -> V_435 ) ;
return V_34 ;
}
static void
F_223 ( struct V_453 * V_454 )
{
F_3 ( V_454 , V_454 -> V_455 ) ;
if ( V_454 -> V_18 )
V_454 -> V_18 ( V_454 -> V_98 , V_454 -> V_142 ) ;
V_454 -> V_455 = 0 ;
V_454 -> V_18 = NULL ;
}
static void
F_224 ( struct V_453 * V_454 )
{
F_3 ( V_454 , V_454 -> V_456 ) ;
if ( V_454 -> V_457 ) {
F_225 ( V_454 ) ;
if ( V_454 -> V_458 )
V_454 -> V_458 ( V_454 -> V_459 ,
V_454 -> V_142 ) ;
V_454 -> V_457 = NULL ;
}
if ( V_454 -> V_456 ) {
V_454 -> V_142 = F_226 ( V_454 , V_454 -> V_456 ) ;
if ( V_454 -> V_458 )
V_454 -> V_458 ( V_454 -> V_459 ,
V_454 -> V_142 ) ;
V_454 -> V_456 = V_460 ;
}
V_454 -> V_461 = 0 ;
V_454 -> V_458 = NULL ;
}
static void
F_227 ( void * V_462 , enum V_93 V_4 )
{
struct V_453 * V_454 = V_462 ;
F_3 ( V_454 , V_4 ) ;
F_3 ( V_454 , V_454 -> V_455 ) ;
F_3 ( V_454 , V_454 -> V_461 ) ;
switch ( V_4 ) {
case V_99 :
case V_221 :
if ( V_454 -> V_455 ) {
V_454 -> V_142 = V_21 ;
F_223 ( V_454 ) ;
}
if ( V_454 -> V_461 ) {
V_454 -> V_142 = V_21 ;
F_224 ( V_454 ) ;
}
break;
default:
break;
}
}
static void
F_228 ( struct V_453 * V_454 , struct V_463 * V_417 )
{
struct V_32 * V_33 = (struct V_32 * ) V_454 -> V_2 -> V_20 -> V_33 ;
struct V_364 * V_365 ;
enum V_464 V_465 = 0 ;
F_3 ( V_454 , ( ( ( T_7 ) V_417 -> V_466 ) << 16 ) | ( ( ( T_7 ) V_417 -> V_467 ) << 8 ) |
( ( T_7 ) V_417 -> V_4 ) ) ;
F_185 ( V_33 , V_365 ) ;
if ( ! V_365 )
return;
V_365 -> V_366 . V_438 . V_355 = F_175 ( V_454 -> V_2 ) ;
V_365 -> V_366 . V_438 . V_306 = V_454 -> V_2 -> V_196 -> V_306 ;
V_365 -> V_366 . V_438 . V_307 = F_172 ( V_454 -> V_2 ) ;
switch ( V_417 -> V_4 ) {
case V_468 :
V_465 = V_469 ;
break;
case V_470 :
V_465 = V_471 ;
break;
case V_472 :
V_465 = V_473 ;
break;
case V_474 :
V_465 = V_475 ;
break;
case V_476 :
V_465 = V_477 ;
V_365 -> V_366 . V_438 . V_478 = V_417 -> V_466 ;
break;
default:
F_3 ( V_454 , V_417 -> V_4 ) ;
F_76 ( 1 ) ;
}
F_186 ( V_365 , V_33 , ++ V_454 -> V_2 -> V_367 ,
V_479 , V_465 ) ;
}
static void
F_229 ( struct V_453 * V_454 )
{
struct V_480 * V_373 = (struct V_480 * ) V_454 -> V_481 . V_214 ;
F_3 ( V_454 , V_373 -> V_482 ) ;
F_102 ( V_373 -> V_167 , V_483 , V_484 ,
F_103 ( V_454 -> V_2 ) ) ;
F_153 ( V_454 -> V_2 , & V_454 -> V_481 ) ;
}
static void
F_230 ( struct V_453 * V_454 , enum V_485 V_482 )
{
struct V_480 * V_373 = (struct V_480 * ) V_454 -> V_481 . V_214 ;
F_76 ( V_454 -> V_455 != 0 ) ;
F_3 ( V_454 , V_454 -> V_353 ) ;
V_454 -> V_455 = 1 ;
V_454 -> V_482 = V_482 ;
V_373 -> V_482 = V_482 ;
F_231 ( & V_373 -> V_486 , sizeof( struct V_487 ) , V_454 -> V_488 ) ;
F_229 ( V_454 ) ;
}
static void
F_232 ( struct V_453 * V_454 , struct V_233 * V_214 )
{
struct V_463 * V_417 = (struct V_463 * ) V_214 ;
switch ( V_417 -> V_4 ) {
case V_468 :
V_454 -> V_353 = V_489 ;
V_454 -> V_490 = 0 ;
F_228 ( V_454 , V_417 ) ;
break;
case V_470 :
V_454 -> V_353 = V_491 ;
V_454 -> V_490 = 0 ;
F_228 ( V_454 , V_417 ) ;
break;
case V_472 :
V_454 -> V_353 = V_492 ;
V_454 -> V_490 = 0 ;
F_228 ( V_454 , V_417 ) ;
break;
case V_474 :
V_454 -> V_353 = V_493 ;
F_228 ( V_454 , V_417 ) ;
if ( ! V_454 -> V_455 )
F_230 ( V_454 , V_494 ) ;
break;
case V_476 :
F_228 ( V_454 , V_417 ) ;
break;
case V_495 :
V_454 -> V_353 = V_496 ;
if ( ! V_454 -> V_455 )
F_230 ( V_454 , V_494 ) ;
break;
default:
F_3 ( V_454 , V_417 -> V_4 ) ;
F_76 ( 1 ) ;
}
}
static void
F_233 ( struct V_453 * V_454 , struct V_233 * V_214 )
{
struct V_497 * V_417 = (struct V_497 * ) V_214 ;
if ( ! V_454 -> V_455 ) {
F_3 ( V_454 , V_454 -> V_455 ) ;
return;
}
F_3 ( V_454 , V_417 -> V_142 ) ;
if ( V_417 -> V_142 == V_34 ) {
V_454 -> V_490 = 1 ;
if ( V_454 -> V_353 == V_496 )
V_454 -> V_142 = V_34 ;
else if ( V_454 -> V_353 == V_493 )
V_454 -> V_142 = V_498 ;
else
F_3 ( V_454 , V_454 -> V_353 ) ;
} else {
V_454 -> V_490 = 0 ;
V_454 -> V_142 = V_417 -> V_142 ;
}
F_3 ( V_454 , V_454 -> V_482 ) ;
if ( V_454 -> V_482 == V_499 ) {
F_3 ( V_454 , V_454 -> V_490 ) ;
if ( V_454 -> V_490 ) {
T_1 V_500 = sizeof( struct V_487 ) ;
T_6 * V_501 = ( T_6 * ) & ( V_454 -> V_502 ) ;
memcpy ( V_501 , V_454 -> V_503 , V_500 ) ;
}
F_223 ( V_454 ) ;
} else
V_454 -> V_455 = 0 ;
F_3 ( V_454 , V_454 -> V_461 ) ;
if ( V_454 -> V_461 ) {
V_454 -> V_353 = V_417 -> V_353 ;
F_224 ( V_454 ) ;
}
}
static void
F_234 ( struct V_453 * V_454 )
{
struct V_480 * V_373 = (struct V_480 * ) V_454 -> V_481 . V_214 ;
F_76 ( V_454 -> V_353 != V_504 ) ;
F_76 ( V_454 -> V_461 != 0 ) ;
F_3 ( V_454 , V_454 -> V_353 ) ;
V_454 -> V_461 = 1 ;
V_373 -> V_482 = 0 ;
if ( ! V_454 -> V_455 )
F_230 ( V_454 , V_494 ) ;
}
static void
F_225 ( struct V_453 * V_454 )
{
enum V_505 * V_457 = V_454 -> V_457 ;
* V_457 = V_506 ;
if ( V_454 -> V_353 == V_493 )
* V_457 = V_507 ;
else if ( V_454 -> V_353 == V_496 ) {
union V_508 V_509 ;
struct V_487 * V_502 = (struct V_487 * ) V_454 -> V_503 ;
T_10 V_510 = ( V_502 -> V_511 . V_512 [ 4 ] & 0x3 ) << 7 |
( V_502 -> V_511 . V_512 [ 5 ] >> 1 ) ;
V_509 . V_513 = V_502 -> V_511 . V_512 [ 0 ] ;
F_3 ( V_454 , V_509 . V_513 ) ;
F_3 ( V_454 , V_510 ) ;
if ( ( V_510 & V_514 ) ||
( V_510 & V_515 ) ||
( V_510 & V_516 ) )
* V_457 = V_517 ;
else if ( ( V_510 & V_518 ) ||
( V_510 & V_519 ) )
* V_457 = V_520 ;
else if ( ( V_510 & V_521 ) ||
( V_510 & V_522 ) )
* V_457 = V_523 ;
else if ( ( V_510 & V_524 ) ||
( V_510 & V_525 ) ||
( V_510 & V_526 ) )
* V_457 = V_527 ;
else if ( V_509 . V_528 . V_529 )
* V_457 = V_527 ;
else if ( V_509 . V_528 . V_530 && V_509 . V_528 . V_531 )
* V_457 = V_523 ;
else if ( V_509 . V_528 . V_532 )
* V_457 = V_506 ;
else
F_3 ( V_454 , 0 ) ;
} else
F_3 ( V_454 , V_454 -> V_353 ) ;
}
static T_4
F_226 ( struct V_453 * V_454 , enum V_533 V_456 )
{
struct V_487 * V_502 = (struct V_487 * ) V_454 -> V_503 ;
struct V_534 * V_512 = (struct V_534 * ) V_502 -> V_511 . V_512 ;
union V_535 V_536 = V_512 -> V_536 ;
union V_508 V_509 = V_512 -> V_509 ;
if ( V_456 == V_537 ) {
if ( V_509 . V_528 . V_529 || V_509 . V_528 . V_531 )
return V_34 ;
else {
F_3 ( V_454 , V_509 . V_513 ) ;
return V_538 ;
}
}
if ( ( ( V_456 & V_539 ) && V_536 . V_528 . V_540 ) ||
( ( V_456 & V_541 ) && V_536 . V_528 . V_542 ) ||
( ( V_456 & V_543 ) && V_536 . V_528 . V_544 ) ||
( ( V_456 & V_545 ) && V_536 . V_528 . V_546 ) ||
( ( V_456 & V_547 ) && V_536 . V_528 . V_548 ) )
return V_34 ;
else {
F_3 ( V_454 , V_456 ) ;
F_3 ( V_454 , V_536 . V_513 ) ;
F_3 ( V_454 , V_509 . V_513 ) ;
return V_538 ;
}
}
void
F_235 ( void * V_549 , struct V_233 * V_214 )
{
struct V_453 * V_454 = V_549 ;
switch ( V_214 -> V_167 . V_236 ) {
case V_550 :
F_233 ( V_454 , V_214 ) ;
break;
case V_551 :
F_232 ( V_454 , V_214 ) ;
break;
default:
F_3 ( V_454 , V_214 -> V_167 . V_236 ) ;
F_76 ( 1 ) ;
}
}
T_1
F_236 ( void )
{
return F_210 ( sizeof( struct V_487 ) , V_429 ) ;
}
void
F_237 ( struct V_453 * V_454 , struct V_1 * V_2 , void * V_552 ,
struct V_553 * V_554 )
{
V_454 -> V_552 = V_552 ;
V_454 -> V_2 = V_2 ;
V_454 -> V_554 = V_554 ;
V_454 -> V_18 = NULL ;
V_454 -> V_98 = NULL ;
V_454 -> V_502 = NULL ;
V_454 -> V_455 = 0 ;
V_454 -> V_490 = 0 ;
V_454 -> V_353 = V_504 ;
V_454 -> V_461 = 0 ;
V_454 -> V_458 = NULL ;
V_454 -> V_459 = NULL ;
V_454 -> V_457 = NULL ;
V_454 -> V_456 = V_460 ;
V_454 -> V_555 = V_50 ;
F_152 ( V_454 -> V_2 , V_483 , F_235 , V_454 ) ;
F_213 ( & V_454 -> V_432 ) ;
F_214 ( & V_454 -> V_432 , F_227 , V_454 ) ;
F_154 ( & V_454 -> V_432 . V_97 , & V_454 -> V_2 -> V_250 ) ;
}
void
F_238 ( struct V_453 * V_454 , T_6 * V_277 , T_7 V_278 )
{
V_454 -> V_503 = V_277 ;
V_454 -> V_488 = V_278 ;
memset ( V_454 -> V_503 , 0 , sizeof( struct V_487 ) ) ;
V_277 += F_210 ( sizeof( struct V_487 ) , V_429 ) ;
V_278 += F_210 ( sizeof( struct V_487 ) , V_429 ) ;
}
T_4
F_239 ( struct V_453 * V_454 , struct V_487 * V_502 ,
T_12 V_18 , void * V_98 )
{
if ( ! F_131 ( V_454 -> V_2 ) ) {
F_3 ( V_454 , 0 ) ;
return V_556 ;
}
if ( V_454 -> V_455 ) {
F_3 ( V_454 , 0 ) ;
return V_384 ;
}
V_454 -> V_18 = V_18 ;
V_454 -> V_98 = V_98 ;
V_454 -> V_502 = V_502 ;
F_230 ( V_454 , V_499 ) ;
return V_34 ;
}
T_4
F_240 ( struct V_453 * V_454 , enum V_505 * V_457 ,
T_12 V_18 , void * V_98 )
{
if ( ! F_131 ( V_454 -> V_2 ) ) {
F_3 ( V_454 , 0 ) ;
return V_556 ;
}
V_454 -> V_457 = V_457 ;
if ( V_454 -> V_353 == V_504 ) {
if ( V_454 -> V_461 ) {
F_3 ( V_454 , 0 ) ;
return V_384 ;
} else {
V_454 -> V_458 = V_18 ;
V_454 -> V_459 = V_98 ;
F_234 ( V_454 ) ;
return V_557 ;
}
}
F_225 ( V_454 ) ;
return V_34 ;
}
T_4
F_241 ( struct V_453 * V_454 , enum V_533 V_456 ,
T_12 V_18 , void * V_98 )
{
F_76 ( V_456 == V_460 ) ;
if ( ! F_131 ( V_454 -> V_2 ) )
return V_556 ;
if ( F_170 ( V_454 -> V_2 -> V_196 -> V_198 ) )
return V_34 ;
V_454 -> V_456 = V_456 ;
if ( V_454 -> V_353 == V_504 ) {
if ( V_454 -> V_461 ) {
F_3 ( V_454 , 0 ) ;
return V_384 ;
} else {
V_454 -> V_458 = V_18 ;
V_454 -> V_459 = V_98 ;
F_234 ( V_454 ) ;
return V_557 ;
}
}
if ( V_454 -> V_353 == V_491 ||
V_454 -> V_353 == V_492 ) {
F_3 ( V_454 , V_454 -> V_353 ) ;
return V_558 ;
}
if ( V_454 -> V_353 == V_489 ) {
F_3 ( V_454 , V_454 -> V_353 ) ;
return V_384 ;
}
if ( V_454 -> V_555 )
return V_34 ;
return F_226 ( V_454 , V_456 ) ;
}
static void
F_242 ( struct V_1 * V_2 , enum V_559 V_4 ,
int V_406 , int type )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 -> V_20 -> V_33 ;
struct V_364 * V_365 ;
F_185 ( V_33 , V_365 ) ;
if ( ! V_365 )
return;
V_365 -> V_366 . V_560 . V_306 = V_2 -> V_196 -> V_306 ;
V_365 -> V_366 . V_560 . V_561 = V_406 ;
V_365 -> V_366 . V_560 . V_562 = type ;
F_186 ( V_365 , V_33 , ++ V_2 -> V_367 ,
V_563 , V_4 ) ;
}
static void
F_243 ( struct V_564 * V_565 )
{
V_565 -> V_566 = 0 ;
if ( V_565 -> V_18 )
V_565 -> V_18 ( V_565 -> V_98 , V_565 -> V_142 ) ;
}
static void
F_244 ( void * V_98 , enum V_93 V_4 )
{
struct V_564 * V_565 = V_98 ;
F_3 ( V_565 , V_4 ) ;
switch ( V_4 ) {
case V_99 :
case V_221 :
if ( V_565 -> V_566 ) {
V_565 -> V_142 = V_21 ;
V_565 -> V_18 ( V_565 -> V_98 , V_565 -> V_142 ) ;
V_565 -> V_566 = 0 ;
}
break;
default:
break;
}
}
static void
F_245 ( void * V_98 )
{
struct V_564 * V_565 = V_98 ;
struct V_567 * V_214 =
(struct V_567 * ) V_565 -> V_435 . V_214 ;
F_102 ( V_214 -> V_167 , V_568 , V_569 ,
F_103 ( V_565 -> V_2 ) ) ;
F_231 ( & V_214 -> V_486 , sizeof( struct V_570 ) ,
V_565 -> V_488 ) ;
F_153 ( V_565 -> V_2 , & V_565 -> V_435 ) ;
}
static void
F_246 ( struct V_564 * V_565 )
{
struct V_571 * V_214 =
(struct V_571 * ) V_565 -> V_435 . V_214 ;
T_1 V_158 ;
V_214 -> type = F_106 ( V_565 -> type ) ;
V_214 -> V_572 = V_565 -> V_572 ;
V_214 -> V_376 = F_106 ( V_565 -> V_573 + V_565 -> V_376 ) ;
V_158 = ( V_565 -> V_574 < V_575 ) ?
V_565 -> V_574 : V_575 ;
V_214 -> V_576 = F_106 ( V_158 ) ;
V_214 -> V_577 = ( V_158 == V_565 -> V_574 ) ? 1 : 0 ;
F_102 ( V_214 -> V_167 , V_568 , V_578 ,
F_103 ( V_565 -> V_2 ) ) ;
F_231 ( & V_214 -> V_486 , V_158 , V_565 -> V_488 ) ;
memcpy ( V_565 -> V_503 , V_565 -> V_579 + V_565 -> V_376 , V_158 ) ;
F_153 ( V_565 -> V_2 , & V_565 -> V_435 ) ;
V_565 -> V_574 -= V_158 ;
V_565 -> V_376 += V_158 ;
}
static void
F_247 ( void * V_98 )
{
struct V_564 * V_565 = V_98 ;
struct V_580 * V_214 =
(struct V_580 * ) V_565 -> V_435 . V_214 ;
T_1 V_158 ;
V_214 -> type = F_106 ( V_565 -> type ) ;
V_214 -> V_572 = V_565 -> V_572 ;
V_214 -> V_376 = F_106 ( V_565 -> V_573 + V_565 -> V_376 ) ;
V_158 = ( V_565 -> V_574 < V_575 ) ?
V_565 -> V_574 : V_575 ;
V_214 -> V_576 = F_106 ( V_158 ) ;
F_102 ( V_214 -> V_167 , V_568 , V_581 ,
F_103 ( V_565 -> V_2 ) ) ;
F_231 ( & V_214 -> V_486 , V_158 , V_565 -> V_488 ) ;
F_153 ( V_565 -> V_2 , & V_565 -> V_435 ) ;
}
static void
F_248 ( void * V_98 )
{
struct V_564 * V_565 = V_98 ;
struct V_582 * V_214 =
(struct V_582 * ) V_565 -> V_435 . V_214 ;
V_214 -> type = F_106 ( V_565 -> type ) ;
V_214 -> V_572 = V_565 -> V_572 ;
F_102 ( V_214 -> V_167 , V_568 , V_583 ,
F_103 ( V_565 -> V_2 ) ) ;
F_153 ( V_565 -> V_2 , & V_565 -> V_435 ) ;
}
static void
F_249 ( void * V_584 , struct V_233 * V_214 )
{
struct V_564 * V_565 = V_584 ;
T_1 V_142 ;
union {
struct V_585 * V_586 ;
struct V_587 * V_588 ;
struct V_589 * V_590 ;
struct V_591 * V_592 ;
struct V_593 * V_4 ;
struct V_233 * V_214 ;
} V_234 ;
V_234 . V_214 = V_214 ;
F_3 ( V_565 , V_214 -> V_167 . V_236 ) ;
if ( ! V_565 -> V_566 && V_214 -> V_167 . V_236 != V_594 ) {
F_3 ( V_565 , 0x9999 ) ;
return;
}
switch ( V_214 -> V_167 . V_236 ) {
case V_595 :
V_142 = F_106 ( V_234 . V_586 -> V_142 ) ;
F_3 ( V_565 , V_142 ) ;
if ( V_142 == V_34 ) {
T_1 V_61 ;
struct V_570 * V_196 , * V_596 ;
V_196 = (struct V_570 * ) V_565 -> V_579 ;
V_596 = (struct V_570 * ) V_565 -> V_503 ;
V_196 -> V_142 = F_106 ( V_596 -> V_142 ) ;
V_196 -> V_597 = F_106 ( V_596 -> V_597 ) ;
F_3 ( V_565 , V_196 -> V_142 ) ;
F_3 ( V_565 , V_196 -> V_597 ) ;
for ( V_61 = 0 ; V_61 < V_196 -> V_597 ; V_61 ++ ) {
V_196 -> V_598 [ V_61 ] . V_599 =
F_106 ( V_596 -> V_598 [ V_61 ] . V_599 ) ;
V_196 -> V_598 [ V_61 ] . V_600 =
F_106 ( V_596 -> V_598 [ V_61 ] . V_600 ) ;
V_196 -> V_598 [ V_61 ] . V_601 =
F_106 ( V_596 -> V_598 [ V_61 ] . V_601 ) ;
V_196 -> V_598 [ V_61 ] . V_602 =
F_106 ( V_596 -> V_598 [ V_61 ] . V_602 ) ;
V_196 -> V_598 [ V_61 ] . V_603 =
F_106 ( V_596 -> V_598 [ V_61 ] . V_603 ) ;
V_196 -> V_598 [ V_61 ] . V_604 =
F_106 ( V_596 -> V_598 [ V_61 ] . V_604 ) ;
}
}
V_565 -> V_142 = V_142 ;
F_243 ( V_565 ) ;
break;
case V_605 :
V_142 = F_106 ( V_234 . V_588 -> V_142 ) ;
F_3 ( V_565 , V_142 ) ;
V_565 -> V_142 = V_142 ;
F_243 ( V_565 ) ;
break;
case V_606 :
V_142 = F_106 ( V_234 . V_590 -> V_142 ) ;
F_3 ( V_565 , V_142 ) ;
if ( V_142 != V_34 || V_565 -> V_574 == 0 ) {
V_565 -> V_142 = V_142 ;
F_243 ( V_565 ) ;
} else {
F_3 ( V_565 , V_565 -> V_376 ) ;
F_246 ( V_565 ) ;
}
break;
case V_607 :
V_142 = F_106 ( V_234 . V_592 -> V_142 ) ;
F_3 ( V_565 , V_142 ) ;
if ( V_142 != V_34 ) {
V_565 -> V_142 = V_142 ;
F_243 ( V_565 ) ;
} else {
T_1 V_158 = F_106 ( V_234 . V_592 -> V_576 ) ;
F_3 ( V_565 , V_565 -> V_376 ) ;
F_3 ( V_565 , V_158 ) ;
memcpy ( V_565 -> V_579 + V_565 -> V_376 ,
V_565 -> V_503 , V_158 ) ;
V_565 -> V_574 -= V_158 ;
V_565 -> V_376 += V_158 ;
if ( V_565 -> V_574 == 0 ) {
V_565 -> V_142 = V_142 ;
F_243 ( V_565 ) ;
} else
F_247 ( V_565 ) ;
}
break;
case V_608 :
break;
case V_594 :
V_142 = F_106 ( V_234 . V_4 -> V_142 ) ;
F_3 ( V_565 , V_142 ) ;
if ( V_142 == V_609 )
F_18 ( V_565 -> V_2 , V_610 ) ;
else if ( V_142 == V_611 ) {
T_1 V_612 ;
V_612 = F_106 ( V_234 . V_4 -> V_612 ) ;
F_3 ( V_565 , V_612 ) ;
F_18 ( V_565 -> V_2 ,
V_613 ) ;
}
break;
default:
F_76 ( 1 ) ;
}
}
T_1
F_250 ( T_2 V_614 )
{
if ( V_614 )
return 0 ;
return F_210 ( V_575 , V_429 ) ;
}
void
F_251 ( struct V_564 * V_565 , struct V_1 * V_2 , void * V_552 ,
struct V_553 * V_554 , T_2 V_614 )
{
V_565 -> V_2 = V_2 ;
V_565 -> V_554 = V_554 ;
V_565 -> V_18 = NULL ;
V_565 -> V_98 = NULL ;
V_565 -> V_566 = 0 ;
F_152 ( V_565 -> V_2 , V_568 , F_249 , V_565 ) ;
F_213 ( & V_565 -> V_432 ) ;
F_214 ( & V_565 -> V_432 , F_244 , V_565 ) ;
F_154 ( & V_565 -> V_432 . V_97 , & V_565 -> V_2 -> V_250 ) ;
if ( V_614 ) {
V_565 -> V_503 = NULL ;
V_565 -> V_488 = 0 ;
}
}
void
F_252 ( struct V_564 * V_565 , T_6 * V_277 , T_7 V_278 ,
T_2 V_614 )
{
if ( V_614 )
return;
V_565 -> V_503 = V_277 ;
V_565 -> V_488 = V_278 ;
memset ( V_565 -> V_503 , 0 , V_575 ) ;
V_277 += F_210 ( V_575 , V_429 ) ;
V_278 += F_210 ( V_575 , V_429 ) ;
}
T_4
F_253 ( struct V_564 * V_565 , struct V_570 * V_196 ,
T_13 V_18 , void * V_98 )
{
F_3 ( V_565 , V_569 ) ;
if ( ! F_131 ( V_565 -> V_2 ) )
return V_556 ;
if ( V_565 -> V_566 ) {
F_3 ( V_565 , V_565 -> V_566 ) ;
return V_384 ;
}
V_565 -> V_566 = 1 ;
V_565 -> V_18 = V_18 ;
V_565 -> V_98 = V_98 ;
V_565 -> V_579 = ( T_6 * ) V_196 ;
F_245 ( V_565 ) ;
return V_34 ;
}
T_4
F_254 ( struct V_564 * V_565 , enum V_615 type ,
T_6 V_572 , T_13 V_18 , void * V_98 )
{
F_3 ( V_565 , V_583 ) ;
F_3 ( V_565 , type ) ;
F_3 ( V_565 , V_572 ) ;
if ( ! F_131 ( V_565 -> V_2 ) )
return V_556 ;
if ( V_565 -> V_566 ) {
F_3 ( V_565 , V_565 -> V_566 ) ;
return V_384 ;
}
V_565 -> V_566 = 1 ;
V_565 -> V_18 = V_18 ;
V_565 -> V_98 = V_98 ;
V_565 -> type = type ;
V_565 -> V_572 = V_572 ;
F_248 ( V_565 ) ;
F_242 ( V_565 -> V_2 , V_616 ,
V_572 , type ) ;
return V_34 ;
}
T_4
F_255 ( struct V_564 * V_565 , enum V_615 type ,
T_6 V_572 , void * V_218 , T_1 V_158 , T_1 V_376 ,
T_13 V_18 , void * V_98 )
{
F_3 ( V_565 , V_578 ) ;
F_3 ( V_565 , type ) ;
F_3 ( V_565 , V_572 ) ;
F_3 ( V_565 , V_158 ) ;
F_3 ( V_565 , V_376 ) ;
if ( ! F_131 ( V_565 -> V_2 ) )
return V_556 ;
if ( ! V_158 || ( V_158 & 0x03 ) || ( V_376 & 0x00003FFF ) )
return V_617 ;
if ( type == V_618 )
return V_380 ;
if ( V_565 -> V_566 ) {
F_3 ( V_565 , V_565 -> V_566 ) ;
return V_384 ;
}
V_565 -> V_566 = 1 ;
V_565 -> V_18 = V_18 ;
V_565 -> V_98 = V_98 ;
V_565 -> type = type ;
V_565 -> V_572 = V_572 ;
V_565 -> V_574 = V_158 ;
V_565 -> V_376 = 0 ;
V_565 -> V_573 = V_376 ;
V_565 -> V_579 = V_218 ;
F_246 ( V_565 ) ;
return V_34 ;
}
T_4
F_256 ( struct V_564 * V_565 , enum V_615 type ,
T_6 V_572 , void * V_218 , T_1 V_158 , T_1 V_376 ,
T_13 V_18 , void * V_98 )
{
F_3 ( V_565 , V_581 ) ;
F_3 ( V_565 , type ) ;
F_3 ( V_565 , V_572 ) ;
F_3 ( V_565 , V_158 ) ;
F_3 ( V_565 , V_376 ) ;
if ( ! F_131 ( V_565 -> V_2 ) )
return V_556 ;
if ( ! V_158 || ( V_158 & 0x03 ) || ( V_376 & 0x00003FFF ) )
return V_617 ;
if ( V_565 -> V_566 ) {
F_3 ( V_565 , V_565 -> V_566 ) ;
return V_384 ;
}
V_565 -> V_566 = 1 ;
V_565 -> V_18 = V_18 ;
V_565 -> V_98 = V_98 ;
V_565 -> type = type ;
V_565 -> V_572 = V_572 ;
V_565 -> V_574 = V_158 ;
V_565 -> V_376 = 0 ;
V_565 -> V_573 = V_376 ;
V_565 -> V_579 = V_218 ;
F_247 ( V_565 ) ;
return V_34 ;
}
static void
F_257 ( void * V_619 , enum V_93 V_4 )
{
struct V_620 * V_621 = V_619 ;
F_3 ( V_621 , V_4 ) ;
F_3 ( V_621 , V_621 -> V_622 ) ;
F_3 ( V_621 , V_621 -> V_623 . V_455 ) ;
F_3 ( V_621 , V_621 -> V_624 . V_455 ) ;
switch ( V_4 ) {
case V_99 :
case V_221 :
if ( V_621 -> V_623 . V_455 ) {
V_621 -> V_623 . V_142 = V_21 ;
V_621 -> V_623 . V_18 ( V_621 -> V_623 . V_98 ,
V_621 -> V_623 . V_142 ) ;
V_621 -> V_623 . V_455 = 0 ;
}
if ( V_621 -> V_624 . V_455 ) {
V_621 -> V_624 . V_142 = V_21 ;
V_621 -> V_624 . V_18 ( V_621 -> V_624 . V_98 ,
V_621 -> V_624 . V_142 ) ;
V_621 -> V_624 . V_455 = 0 ;
}
if ( V_621 -> V_622 ) {
if ( V_621 -> V_625 ) {
F_205 ( & V_621 -> V_398 ) ;
V_621 -> V_625 = 0 ;
}
V_621 -> V_142 = V_21 ;
V_621 -> V_18 ( V_621 -> V_98 , V_621 -> V_142 ) ;
V_621 -> V_622 = 0 ;
}
break;
default:
break;
}
}
static void
F_258 ( void * V_98 )
{
struct V_620 * V_621 = V_98 ;
struct V_1 * V_2 = V_621 -> V_2 ;
struct V_626 * V_627 = V_621 -> V_628 ;
T_1 V_60 = V_629 ;
T_1 V_58 , V_59 , V_61 ;
V_58 = F_34 ( V_2 -> V_62 . V_68 , V_60 ) ;
V_59 = F_35 ( V_60 ) ;
F_31 ( V_58 , V_2 -> V_62 . V_69 ) ;
for ( V_61 = 0 ; V_61 < ( sizeof( struct V_626 ) /
sizeof( T_1 ) ) ; V_61 ++ ) {
* ( ( T_1 * ) V_627 + V_61 ) =
F_81 ( V_2 -> V_62 . V_70 , V_60 ) ;
V_60 += sizeof( T_1 ) ;
}
F_161 ( V_2 ) ;
V_627 -> V_142 = F_33 ( V_627 -> V_142 ) ;
F_3 ( V_621 , V_627 -> V_142 ) ;
if ( V_627 -> V_142 == V_630 )
V_621 -> V_142 = V_34 ;
else {
V_621 -> V_142 = V_631 ;
V_627 -> V_437 = F_33 ( V_627 -> V_437 ) ;
V_627 -> exp = F_33 ( V_627 -> exp ) ;
V_627 -> V_632 = F_33 ( V_627 -> V_632 ) ;
V_627 -> V_633 = F_33 ( V_627 -> V_633 ) ;
V_627 -> V_634 = F_33 ( V_627 -> V_634 ) ;
V_627 -> V_635 = F_33 ( V_627 -> V_635 ) ;
F_3 ( V_621 , V_627 -> V_437 ) ;
F_3 ( V_621 , V_627 -> exp ) ;
F_3 ( V_621 , V_627 -> V_632 ) ;
F_3 ( V_621 , V_627 -> V_633 ) ;
F_3 ( V_621 , V_627 -> V_634 ) ;
F_3 ( V_621 , V_627 -> V_635 ) ;
}
V_621 -> V_625 = 0 ;
V_621 -> V_18 ( V_621 -> V_98 , V_621 -> V_142 ) ;
V_621 -> V_622 = 0 ;
}
static void
F_259 ( struct V_620 * V_621 )
{
struct V_636 * V_637 ;
T_1 V_61 ;
F_3 ( V_621 , V_621 -> V_623 . V_488 ) ;
for ( V_61 = 0 ; V_61 < ( V_638 >> 2 ) ; V_61 ++ )
* ( ( T_1 * ) V_621 -> V_623 . V_503 + V_61 ) = V_621 -> V_623 . V_639 ;
V_637 = (struct V_636 * ) V_621 -> V_623 . V_481 . V_214 ;
F_231 ( & V_637 -> V_486 , V_638 ,
V_621 -> V_623 . V_488 ) ;
V_637 -> V_640 = F_135 ( V_621 -> V_623 . V_640 ) ;
V_637 -> V_639 = V_621 -> V_623 . V_639 ;
F_102 ( V_637 -> V_167 , V_641 , V_642 ,
F_103 ( V_621 -> V_2 ) ) ;
F_153 ( V_621 -> V_2 , & V_621 -> V_623 . V_481 ) ;
}
static void
F_260 ( struct V_620 * V_621 ,
struct V_643 * V_644 )
{
T_1 V_645 = V_644 -> V_639 ;
T_6 V_646 = V_644 -> V_647 ;
F_3 ( V_621 , V_645 ) ;
F_3 ( V_621 , V_646 ) ;
if ( V_646 == V_34 ) {
T_1 V_61 , V_648 ;
V_648 = ( V_621 -> V_623 . V_640 & 0x1 ) ? ~ ( V_621 -> V_623 . V_639 ) :
V_621 -> V_623 . V_639 ;
if ( V_621 -> V_623 . V_639 != V_645 ) {
F_3 ( V_621 , V_645 ) ;
V_621 -> V_623 . V_628 -> V_649 =
V_650 ;
V_621 -> V_623 . V_142 = V_650 ;
V_621 -> V_623 . V_18 ( V_621 -> V_623 . V_98 ,
V_621 -> V_623 . V_142 ) ;
V_621 -> V_623 . V_455 = 0 ;
return;
}
for ( V_61 = 0 ; V_61 < ( V_638 >> 2 ) ; V_61 ++ ) {
if ( * ( ( T_1 * ) V_621 -> V_623 . V_503 + V_61 ) != V_648 ) {
F_3 ( V_621 , V_61 ) ;
F_3 ( V_621 , V_648 ) ;
F_3 ( V_621 ,
* ( ( T_1 * ) V_621 -> V_623 . V_503 + V_61 ) ) ;
V_621 -> V_623 . V_628 -> V_649 =
V_650 ;
V_621 -> V_623 . V_142 = V_650 ;
V_621 -> V_623 . V_18 ( V_621 -> V_623 . V_98 ,
V_621 -> V_623 . V_142 ) ;
V_621 -> V_623 . V_455 = 0 ;
return;
}
}
V_621 -> V_623 . V_628 -> V_649 = V_34 ;
V_621 -> V_623 . V_142 = V_34 ;
V_621 -> V_623 . V_18 ( V_621 -> V_623 . V_98 , V_621 -> V_623 . V_142 ) ;
V_621 -> V_623 . V_455 = 0 ;
} else {
V_621 -> V_623 . V_142 = V_651 ;
V_621 -> V_623 . V_18 ( V_621 -> V_623 . V_98 , V_621 -> V_623 . V_142 ) ;
V_621 -> V_623 . V_455 = 0 ;
}
}
static void
F_261 ( struct V_620 * V_621 )
{
struct V_652 * V_214 ;
V_214 = (struct V_652 * ) V_621 -> V_624 . V_481 . V_214 ;
F_3 ( V_621 , V_214 -> V_653 ) ;
F_102 ( V_214 -> V_167 , V_641 , V_654 ,
F_103 ( V_621 -> V_2 ) ) ;
F_153 ( V_621 -> V_2 , & V_621 -> V_624 . V_481 ) ;
}
static void
F_262 ( struct V_620 * V_621 , T_14 * V_417 )
{
if ( ! V_621 -> V_624 . V_455 ) {
F_3 ( V_621 , V_621 -> V_624 . V_455 ) ;
return;
}
V_621 -> V_624 . V_653 -> V_653 = F_119 ( V_417 -> V_653 ) ;
V_621 -> V_624 . V_653 -> V_655 = V_417 -> V_655 ;
V_621 -> V_624 . V_653 -> V_656 = V_417 -> V_656 ;
if ( V_417 -> V_656 ) {
V_621 -> V_624 . V_653 -> V_142 = V_417 -> V_142 ;
if ( V_417 -> V_142 == V_34 ) {
V_621 -> V_624 . V_653 -> V_657 =
F_119 ( V_417 -> V_657 ) ;
} else
V_621 -> V_624 . V_653 -> V_657 = 0 ;
}
F_3 ( V_621 , V_417 -> V_142 ) ;
F_3 ( V_621 , V_417 -> V_655 ) ;
F_3 ( V_621 , V_417 -> V_653 ) ;
F_3 ( V_621 , V_417 -> V_656 ) ;
F_3 ( V_621 , V_417 -> V_657 ) ;
V_621 -> V_624 . V_142 = V_34 ;
V_621 -> V_624 . V_18 ( V_621 -> V_624 . V_98 , V_621 -> V_624 . V_142 ) ;
V_621 -> V_624 . V_455 = 0 ;
}
static void
F_263 ( struct V_620 * V_621 , struct V_658 * V_659 )
{
struct V_660 * V_214 ;
V_214 = (struct V_660 * ) V_621 -> V_659 . V_481 . V_214 ;
F_102 ( V_214 -> V_167 , V_641 , V_661 ,
F_103 ( V_621 -> V_2 ) ) ;
if ( V_659 -> V_662 )
V_659 -> V_662 = 500 / V_659 -> V_662 ;
if ( V_659 -> V_662 == 0 )
V_659 -> V_662 = 1 ;
F_3 ( V_621 , V_659 -> V_662 ) ;
V_214 -> V_212 = ( T_6 ) V_659 -> V_212 ;
V_214 -> V_663 = ( T_6 ) V_659 -> V_663 ;
V_214 -> V_664 = F_103 ( V_621 -> V_2 ) ;
V_214 -> V_665 = V_659 -> V_665 ;
V_214 -> V_662 = F_104 ( V_659 -> V_662 ) ;
F_153 ( V_621 -> V_2 , & V_621 -> V_659 . V_481 ) ;
}
static void
F_264 ( struct V_620 * V_621 , struct V_666 * V_214 )
{
F_3 ( V_621 , V_621 -> V_659 . V_455 ) ;
V_621 -> V_659 . V_455 = V_50 ;
}
static void
F_265 ( struct V_620 * V_621 , T_2 V_667 , T_1 V_668 )
{
struct V_669 * V_214 ;
V_214 = (struct V_669 * ) V_621 -> V_667 . V_481 . V_214 ;
F_102 ( V_214 -> V_167 , V_641 , V_670 ,
F_103 ( V_621 -> V_2 ) ) ;
V_214 -> V_667 = V_667 ;
V_214 -> V_671 = F_135 ( V_668 ) ;
F_153 ( V_621 -> V_2 , & V_621 -> V_667 . V_481 ) ;
}
static void
F_266 ( struct V_620 * V_621 )
{
F_3 ( V_621 , V_621 -> V_667 . V_353 ) ;
V_621 -> V_667 . V_353 = V_50 ;
if ( V_621 -> V_672 )
V_621 -> V_672 ( V_621 -> V_552 , V_50 , V_621 -> V_667 . V_673 ) ;
}
void
F_267 ( void * V_674 , struct V_233 * V_214 )
{
struct V_620 * V_621 = V_674 ;
switch ( V_214 -> V_167 . V_236 ) {
case V_675 :
F_266 ( V_621 ) ;
break;
case V_676 :
F_260 ( V_621 , (struct V_643 * ) V_214 ) ;
break;
case V_677 :
F_262 ( V_621 , ( T_14 * ) V_214 ) ;
break;
case V_678 :
F_264 ( V_621 , (struct V_666 * ) V_214 ) ;
break;
default:
F_3 ( V_621 , V_214 -> V_167 . V_236 ) ;
F_76 ( 1 ) ;
}
}
T_4
F_268 ( struct V_620 * V_621 , struct V_679 * V_680 ,
T_1 V_681 , struct V_626 * V_628 ,
T_15 V_18 , void * V_98 )
{
T_1 V_682 ;
F_3 ( V_621 , V_681 ) ;
if ( ! F_160 ( V_621 -> V_2 ) )
return V_146 ;
if ( V_621 -> V_622 ) {
F_3 ( V_621 , V_621 -> V_622 ) ;
return V_384 ;
} else
V_621 -> V_622 = 1 ;
V_621 -> V_628 = V_628 ;
V_621 -> V_18 = V_18 ;
V_621 -> V_98 = V_98 ;
F_97 ( V_621 -> V_2 , V_228 , V_152 ) ;
V_682 = ( F_84 ( V_621 -> V_2 ) == V_269 ) ?
V_683 : V_684 ;
F_203 ( V_621 -> V_2 -> V_248 , & V_621 -> V_398 ,
F_258 , V_621 , V_682 ) ;
V_621 -> V_625 = 1 ;
return V_34 ;
}
T_4
F_269 ( struct V_620 * V_621 , T_1 V_101 , T_1 V_639 ,
struct V_685 * V_628 , T_15 V_18 ,
void * V_98 )
{
F_3 ( V_621 , V_101 ) ;
F_3 ( V_621 , V_639 ) ;
if ( ! F_131 ( V_621 -> V_2 ) )
return V_556 ;
if ( F_176 ( F_180 ( ( V_621 -> V_2 ) ) ) &&
( ( V_621 -> V_2 ) -> V_170 == V_320 ) )
return V_686 ;
if ( V_621 -> V_622 || V_621 -> V_623 . V_455 ) {
F_3 ( V_621 , V_621 -> V_622 ) ;
F_3 ( V_621 , V_621 -> V_623 . V_455 ) ;
return V_384 ;
}
V_621 -> V_623 . V_455 = 1 ;
V_621 -> V_623 . V_18 = V_18 ;
V_621 -> V_623 . V_98 = V_98 ;
V_621 -> V_623 . V_628 = V_628 ;
V_621 -> V_623 . V_639 = V_639 ;
V_621 -> V_623 . V_640 = V_101 ;
V_621 -> V_623 . V_628 -> V_639 = 0 ;
V_621 -> V_623 . V_628 -> V_142 = V_34 ;
F_259 ( V_621 ) ;
return V_34 ;
}
T_4
F_270 ( struct V_620 * V_621 ,
struct V_687 * V_628 ,
T_15 V_18 , void * V_98 )
{
if ( V_621 -> V_622 || V_621 -> V_624 . V_455 ) {
F_3 ( V_621 , V_621 -> V_622 ) ;
F_3 ( V_621 , V_621 -> V_624 . V_455 ) ;
return V_384 ;
}
if ( ! F_131 ( V_621 -> V_2 ) )
return V_556 ;
V_621 -> V_624 . V_455 = 1 ;
V_621 -> V_624 . V_653 = V_628 ;
V_621 -> V_624 . V_18 = V_18 ;
V_621 -> V_624 . V_98 = V_98 ;
V_621 -> V_624 . V_142 = V_34 ;
F_261 ( V_621 ) ;
return V_34 ;
}
T_4
F_271 ( struct V_620 * V_621 , struct V_658 * V_659 )
{
F_3 ( V_621 , V_659 -> V_212 ) ;
if ( ! F_131 ( V_621 -> V_2 ) )
return V_556 ;
if ( V_621 -> V_667 . V_353 )
return V_688 ;
if ( V_621 -> V_659 . V_455 )
return V_689 ;
V_621 -> V_659 . V_455 = V_77 ;
F_263 ( V_621 , V_659 ) ;
return V_34 ;
}
T_4
F_272 ( struct V_620 * V_621 , T_2 V_667 ,
T_2 V_690 , T_16 V_668 )
{
F_3 ( V_621 , V_667 ) ;
F_3 ( V_621 , V_690 ) ;
F_3 ( V_621 , V_668 ) ;
if ( ! F_131 ( V_621 -> V_2 ) )
return V_556 ;
if ( V_621 -> V_659 . V_455 )
return V_689 ;
if ( V_621 -> V_667 . V_353 && V_667 )
return V_688 ;
V_621 -> V_667 . V_353 = V_667 ;
V_621 -> V_667 . V_673 = V_690 ;
if ( V_621 -> V_672 )
V_621 -> V_672 ( V_621 -> V_552 , V_667 , V_690 ) ;
F_265 ( V_621 , V_667 , V_668 ) ;
return V_34 ;
}
T_1
F_273 ( void )
{
return F_210 ( V_638 , V_429 ) ;
}
void
F_274 ( struct V_620 * V_621 , struct V_1 * V_2 , void * V_552 ,
T_17 V_672 , struct V_553 * V_554 )
{
V_621 -> V_552 = V_552 ;
V_621 -> V_2 = V_2 ;
V_621 -> V_554 = V_554 ;
V_621 -> V_622 = 0 ;
V_621 -> V_18 = NULL ;
V_621 -> V_98 = NULL ;
V_621 -> V_628 = NULL ;
V_621 -> V_672 = V_672 ;
F_152 ( V_621 -> V_2 , V_641 , F_267 , V_621 ) ;
F_213 ( & V_621 -> V_432 ) ;
F_214 ( & V_621 -> V_432 , F_257 , V_621 ) ;
F_154 ( & V_621 -> V_432 . V_97 , & V_621 -> V_2 -> V_250 ) ;
}
void
F_275 ( struct V_620 * V_621 , T_6 * V_277 , T_7 V_278 )
{
V_621 -> V_623 . V_503 = V_277 ;
V_621 -> V_623 . V_488 = V_278 ;
memset ( V_621 -> V_623 . V_503 , 0 , V_638 ) ;
}
static void
F_276 ( T_1 * V_691 , T_1 * V_692 , int V_217 )
{
int V_61 , V_234 = V_217 >> 2 ;
for ( V_61 = 0 ; V_61 < V_234 ; V_61 ++ )
V_691 [ V_61 ] = F_106 ( V_692 [ V_61 ] ) ;
}
static T_2
F_277 ( struct V_693 * V_694 )
{
return ( V_694 -> V_2 -> V_196 -> V_198 == V_695 ) ;
}
static void
F_278 ( void * V_98 , enum V_93 V_4 )
{
struct V_693 * V_694 = V_98 ;
F_3 ( V_694 , V_4 ) ;
switch ( V_4 ) {
case V_99 :
case V_221 :
if ( V_694 -> V_566 ) {
V_694 -> V_142 = V_21 ;
V_694 -> V_18 ( V_694 -> V_98 , V_694 -> V_142 ) ;
V_694 -> V_566 = 0 ;
}
break;
default:
break;
}
}
static void
F_279 ( void * V_98 )
{
struct V_693 * V_694 = V_98 ;
struct V_696 * V_214 =
(struct V_696 * ) V_694 -> V_435 . V_214 ;
V_214 -> V_572 = V_694 -> V_572 ;
F_102 ( V_214 -> V_167 , V_697 , V_698 ,
F_103 ( V_694 -> V_2 ) ) ;
F_231 ( & V_214 -> V_486 , sizeof( struct V_699 ) , V_694 -> V_488 ) ;
F_153 ( V_694 -> V_2 , & V_694 -> V_435 ) ;
}
static void
F_280 ( void * V_98 )
{
struct V_693 * V_694 = V_98 ;
struct V_700 * V_214 =
(struct V_700 * ) V_694 -> V_435 . V_214 ;
T_1 V_158 ;
T_10 * V_218 , * V_701 ;
int V_61 , V_217 ;
V_214 -> V_572 = V_694 -> V_572 ;
V_214 -> V_376 = F_135 ( V_694 -> V_573 + V_694 -> V_376 ) ;
V_158 = ( V_694 -> V_574 < V_702 ) ?
V_694 -> V_574 : V_702 ;
V_214 -> V_576 = F_135 ( V_158 ) ;
V_214 -> V_577 = ( V_158 == V_694 -> V_574 ) ? 1 : 0 ;
F_102 ( V_214 -> V_167 , V_697 , V_703 ,
F_103 ( V_694 -> V_2 ) ) ;
F_231 ( & V_214 -> V_486 , V_158 , V_694 -> V_488 ) ;
V_218 = ( T_10 * ) ( V_694 -> V_579 + V_694 -> V_376 ) ;
V_701 = ( T_10 * ) V_694 -> V_503 ;
V_217 = V_158 >> 1 ;
for ( V_61 = 0 ; V_61 < V_217 ; V_61 ++ )
V_218 [ V_61 ] = F_104 ( V_701 [ V_61 ] ) ;
F_153 ( V_694 -> V_2 , & V_694 -> V_435 ) ;
V_694 -> V_574 -= V_158 ;
V_694 -> V_376 += V_158 ;
}
static void
F_281 ( void * V_98 )
{
struct V_693 * V_694 = V_98 ;
struct V_704 * V_214 =
(struct V_704 * ) V_694 -> V_435 . V_214 ;
T_1 V_158 ;
V_214 -> V_572 = V_694 -> V_572 ;
V_214 -> V_376 = F_135 ( V_694 -> V_573 + V_694 -> V_376 ) ;
V_158 = ( V_694 -> V_574 < V_702 ) ?
V_694 -> V_574 : V_702 ;
V_214 -> V_576 = F_135 ( V_158 ) ;
F_102 ( V_214 -> V_167 , V_697 , V_705 ,
F_103 ( V_694 -> V_2 ) ) ;
F_231 ( & V_214 -> V_486 , V_158 , V_694 -> V_488 ) ;
F_153 ( V_694 -> V_2 , & V_694 -> V_435 ) ;
}
static void
F_282 ( void * V_98 )
{
struct V_693 * V_694 = V_98 ;
struct V_706 * V_214 =
(struct V_706 * ) V_694 -> V_435 . V_214 ;
V_214 -> V_572 = V_694 -> V_572 ;
F_102 ( V_214 -> V_167 , V_697 , V_707 ,
F_103 ( V_694 -> V_2 ) ) ;
F_231 ( & V_214 -> V_486 , sizeof( struct V_708 ) , V_694 -> V_488 ) ;
F_153 ( V_694 -> V_2 , & V_694 -> V_435 ) ;
}
T_1
F_283 ( T_2 V_614 )
{
if ( V_614 )
return 0 ;
return F_210 ( V_702 , V_429 ) ;
}
void
F_284 ( struct V_693 * V_694 , struct V_1 * V_2 , void * V_552 ,
struct V_553 * V_554 , T_2 V_614 )
{
V_694 -> V_2 = V_2 ;
V_694 -> V_554 = V_554 ;
V_694 -> V_18 = NULL ;
V_694 -> V_98 = NULL ;
V_694 -> V_566 = 0 ;
F_152 ( V_694 -> V_2 , V_697 , V_709 , V_694 ) ;
F_213 ( & V_694 -> V_432 ) ;
F_214 ( & V_694 -> V_432 , F_278 , V_694 ) ;
F_154 ( & V_694 -> V_432 . V_97 , & V_694 -> V_2 -> V_250 ) ;
if ( V_614 ) {
V_694 -> V_503 = NULL ;
V_694 -> V_488 = 0 ;
}
}
void
F_285 ( struct V_693 * V_694 , T_6 * V_277 , T_7 V_278 ,
T_2 V_614 )
{
if ( V_614 )
return;
V_694 -> V_503 = V_277 ;
V_694 -> V_488 = V_278 ;
memset ( V_694 -> V_503 , 0 , V_702 ) ;
V_277 += F_210 ( V_702 , V_429 ) ;
V_278 += F_210 ( V_702 , V_429 ) ;
}
T_2
F_286 ( struct V_1 * V_2 )
{
void T_3 * V_710 ;
V_710 = F_287 ( V_2 ) ;
return F_28 ( V_710 + V_711 ) ;
}
T_4
F_288 ( struct V_693 * V_694 , T_6 V_572 ,
struct V_699 * V_196 , T_18 V_18 , void * V_98 )
{
F_3 ( V_694 , V_698 ) ;
F_3 ( V_694 , V_572 ) ;
if ( ! F_277 ( V_694 ) )
return V_712 ;
if ( ! F_131 ( V_694 -> V_2 ) )
return V_556 ;
if ( V_694 -> V_566 || F_286 ( V_694 -> V_2 ) ) {
F_3 ( V_694 , V_694 -> V_566 ) ;
return V_384 ;
}
V_694 -> V_566 = 1 ;
V_694 -> V_18 = V_18 ;
V_694 -> V_98 = V_98 ;
V_694 -> V_572 = V_572 ;
V_694 -> V_579 = ( V_713 * ) V_196 ;
F_279 ( V_694 ) ;
return V_34 ;
}
T_4
F_289 ( struct V_693 * V_694 , T_6 V_572 ,
struct V_708 * V_289 ,
T_18 V_18 , void * V_98 )
{
F_3 ( V_694 , V_707 ) ;
F_3 ( V_694 , V_572 ) ;
if ( ! F_277 ( V_694 ) )
return V_712 ;
if ( ! F_131 ( V_694 -> V_2 ) )
return V_556 ;
if ( V_694 -> V_566 || F_286 ( V_694 -> V_2 ) ) {
F_3 ( V_694 , V_694 -> V_566 ) ;
return V_384 ;
}
V_694 -> V_566 = 1 ;
V_694 -> V_18 = V_18 ;
V_694 -> V_98 = V_98 ;
V_694 -> V_572 = V_572 ;
V_694 -> V_579 = ( T_6 * ) V_289 ;
F_282 ( V_694 ) ;
return V_34 ;
}
T_4
F_290 ( struct V_693 * V_694 , T_6 V_572 ,
void * V_218 , T_1 V_158 , T_1 V_376 ,
T_18 V_18 , void * V_98 )
{
F_3 ( V_694 , V_703 ) ;
F_3 ( V_694 , V_572 ) ;
F_3 ( V_694 , V_158 ) ;
F_3 ( V_694 , V_376 ) ;
if ( ! F_277 ( V_694 ) )
return V_712 ;
if ( ! F_131 ( V_694 -> V_2 ) )
return V_556 ;
if ( ! V_158 || ( V_158 & 0x03 ) )
return V_219 ;
if ( V_694 -> V_566 || F_286 ( V_694 -> V_2 ) ) {
F_3 ( V_694 , V_694 -> V_566 ) ;
return V_384 ;
}
V_694 -> V_566 = 1 ;
V_694 -> V_18 = V_18 ;
V_694 -> V_98 = V_98 ;
V_694 -> V_572 = V_572 ;
V_694 -> V_574 = V_158 ;
V_694 -> V_376 = 0 ;
V_694 -> V_573 = V_376 ;
V_694 -> V_579 = V_218 ;
F_280 ( V_694 ) ;
return V_34 ;
}
T_4
F_291 ( struct V_693 * V_694 , T_6 V_572 ,
void * V_218 , T_1 V_158 , T_1 V_376 ,
T_18 V_18 , void * V_98 )
{
F_3 ( V_694 , V_705 ) ;
F_3 ( V_694 , V_572 ) ;
F_3 ( V_694 , V_158 ) ;
F_3 ( V_694 , V_376 ) ;
if ( ! F_277 ( V_694 ) )
return V_712 ;
if ( ! F_131 ( V_694 -> V_2 ) )
return V_556 ;
if ( ! V_158 || ( V_158 & 0x03 ) )
return V_219 ;
if ( V_694 -> V_566 || F_286 ( V_694 -> V_2 ) ) {
F_3 ( V_694 , V_694 -> V_566 ) ;
return V_384 ;
}
V_694 -> V_566 = 1 ;
V_694 -> V_18 = V_18 ;
V_694 -> V_98 = V_98 ;
V_694 -> V_572 = V_572 ;
V_694 -> V_574 = V_158 ;
V_694 -> V_376 = 0 ;
V_694 -> V_573 = V_376 ;
V_694 -> V_579 = V_218 ;
F_281 ( V_694 ) ;
return V_34 ;
}
void
V_709 ( void * V_714 , struct V_233 * V_214 )
{
struct V_693 * V_694 = V_714 ;
T_1 V_142 ;
union {
struct V_715 * V_586 ;
struct V_716 * V_289 ;
struct V_717 * V_590 ;
struct V_718 * V_592 ;
struct V_233 * V_214 ;
} V_234 ;
V_234 . V_214 = V_214 ;
F_3 ( V_694 , V_214 -> V_167 . V_236 ) ;
if ( ! V_694 -> V_566 ) {
F_3 ( V_694 , 0x9999 ) ;
return;
}
switch ( V_214 -> V_167 . V_236 ) {
case V_719 :
V_142 = F_106 ( V_234 . V_586 -> V_142 ) ;
F_3 ( V_694 , V_142 ) ;
if ( V_142 == V_34 ) {
struct V_699 * V_196 =
(struct V_699 * ) V_694 -> V_579 ;
F_276 ( ( T_1 * ) V_196 , ( T_1 * ) V_694 -> V_503 ,
sizeof( struct V_699 ) ) ;
F_3 ( V_694 , V_196 -> V_142 ) ;
F_3 ( V_694 , V_196 -> V_576 ) ;
}
V_694 -> V_142 = V_142 ;
V_694 -> V_566 = 0 ;
if ( V_694 -> V_18 )
V_694 -> V_18 ( V_694 -> V_98 , V_694 -> V_142 ) ;
break;
case V_720 :
V_142 = F_106 ( V_234 . V_289 -> V_142 ) ;
F_3 ( V_694 , V_142 ) ;
if ( V_142 == V_34 ) {
struct V_708 * V_289 =
(struct V_708 * ) V_694 -> V_579 ;
F_276 ( ( T_1 * ) V_289 , ( T_1 * ) V_694 -> V_503 ,
sizeof( struct V_708 ) ) ;
F_3 ( V_694 , V_289 -> V_142 ) ;
}
V_694 -> V_142 = V_142 ;
V_694 -> V_566 = 0 ;
if ( V_694 -> V_18 )
V_694 -> V_18 ( V_694 -> V_98 , V_694 -> V_142 ) ;
break;
case V_721 :
V_142 = F_106 ( V_234 . V_590 -> V_142 ) ;
F_3 ( V_694 , V_142 ) ;
if ( V_142 != V_34 || V_694 -> V_574 == 0 ) {
V_694 -> V_142 = V_142 ;
V_694 -> V_566 = 0 ;
if ( V_694 -> V_18 )
V_694 -> V_18 ( V_694 -> V_98 , V_694 -> V_142 ) ;
} else {
F_3 ( V_694 , V_694 -> V_376 ) ;
F_280 ( V_694 ) ;
}
break;
case V_722 :
V_142 = F_106 ( V_234 . V_592 -> V_142 ) ;
F_3 ( V_694 , V_142 ) ;
if ( V_142 != V_34 ) {
V_694 -> V_142 = V_142 ;
V_694 -> V_566 = 0 ;
if ( V_694 -> V_18 )
V_694 -> V_18 ( V_694 -> V_98 , V_694 -> V_142 ) ;
} else {
T_1 V_158 = F_106 ( V_234 . V_592 -> V_576 ) ;
T_10 * V_218 = ( T_10 * ) ( V_694 -> V_579 + V_694 -> V_376 ) ;
T_10 * V_701 = ( T_10 * ) V_694 -> V_503 ;
int V_61 , V_217 = V_158 >> 1 ;
F_3 ( V_694 , V_694 -> V_376 ) ;
F_3 ( V_694 , V_158 ) ;
for ( V_61 = 0 ; V_61 < V_217 ; V_61 ++ )
V_218 [ V_61 ] = F_119 ( V_701 [ V_61 ] ) ;
V_694 -> V_574 -= V_158 ;
V_694 -> V_376 += V_158 ;
if ( V_694 -> V_574 == 0 ) {
V_694 -> V_142 = V_142 ;
V_694 -> V_566 = 0 ;
if ( V_694 -> V_18 )
V_694 -> V_18 ( V_694 -> V_98 , V_694 -> V_142 ) ;
} else
F_281 ( V_694 ) ;
}
break;
default:
F_76 ( 1 ) ;
}
}
static void
F_292 ( struct V_723 * V_724 , enum V_725 V_4 )
{
T_4 V_726 ;
F_3 ( V_724 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_727 :
if ( V_724 -> V_728 ) {
F_3 ( V_724 -> V_20 , V_724 -> V_728 ) ;
F_9 ( & V_724 -> V_20 -> V_729 ,
V_730 ) ;
return;
}
F_293 ( V_724 , V_731 ) ;
F_294 ( V_724 -> V_20 , & V_724 -> V_398 ,
V_732 , V_724 , 2 * V_733 ) ;
V_726 = F_256 ( F_295 ( V_724 -> V_20 ) ,
V_734 , V_724 -> V_572 ,
V_724 -> V_724 ,
sizeof( struct V_735 ) , 0 ,
V_736 , V_724 -> V_20 ) ;
if ( V_726 != V_34 ) {
F_205 ( & V_724 -> V_398 ) ;
V_736 ( V_724 -> V_20 , V_219 ) ;
F_293 ( V_724 , F_292 ) ;
return;
}
break;
case V_737 :
F_9 ( & V_724 -> V_20 -> V_729 , V_730 ) ;
case V_738 :
case V_739 :
case V_740 :
break;
default:
F_5 ( V_724 -> V_20 , V_4 ) ;
}
}
static void
V_731 ( struct V_723 * V_724 ,
enum V_725 V_4 )
{
F_3 ( V_724 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_740 :
F_205 ( & V_724 -> V_398 ) ;
F_293 ( V_724 , V_741 ) ;
break;
case V_742 :
F_293 ( V_724 , V_741 ) ;
F_149 ( & V_724 -> V_20 -> V_2 ) ;
break;
case V_737 :
F_205 ( & V_724 -> V_398 ) ;
F_293 ( V_724 , F_292 ) ;
F_9 ( & V_724 -> V_20 -> V_729 , V_730 ) ;
break;
case V_738 :
F_205 ( & V_724 -> V_398 ) ;
F_293 ( V_724 , F_292 ) ;
break;
default:
F_5 ( V_724 -> V_20 , V_4 ) ;
}
}
static void
V_741 ( struct V_723 * V_724 , enum V_725 V_4 )
{
F_3 ( V_724 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_739 :
F_294 ( V_724 -> V_20 , & V_724 -> V_398 ,
V_732 , V_724 , V_733 ) ;
F_293 ( V_724 , V_743 ) ;
break;
case V_737 :
F_293 ( V_724 , F_292 ) ;
F_9 ( & V_724 -> V_20 -> V_729 , V_730 ) ;
break;
case V_727 :
case V_738 :
break;
default:
F_5 ( V_724 -> V_20 , V_4 ) ;
}
}
static void
V_743 ( struct V_723 * V_724 , enum V_725 V_4 )
{
F_3 ( V_724 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_742 :
F_293 ( V_724 , V_744 ) ;
F_296 ( V_724 ) ;
break;
case V_739 :
F_205 ( & V_724 -> V_398 ) ;
F_294 ( V_724 -> V_20 , & V_724 -> V_398 ,
V_732 , V_724 , V_733 ) ;
break;
case V_737 :
F_205 ( & V_724 -> V_398 ) ;
F_294 ( V_724 -> V_20 , & V_724 -> V_398 ,
V_732 , V_724 , V_733 ) ;
F_293 ( V_724 , V_745 ) ;
F_296 ( V_724 ) ;
break;
case V_740 :
break;
case V_738 :
F_205 ( & V_724 -> V_398 ) ;
F_293 ( V_724 , V_746 ) ;
break;
default:
F_5 ( V_724 -> V_20 , V_4 ) ;
}
}
static void
V_745 ( struct V_723 * V_724 ,
enum V_725 V_4 )
{
F_3 ( V_724 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_738 :
case V_740 :
F_205 ( & V_724 -> V_398 ) ;
case V_742 :
F_293 ( V_724 , F_292 ) ;
F_9 ( & V_724 -> V_20 -> V_729 , V_730 ) ;
break;
default:
F_5 ( V_724 -> V_20 , V_4 ) ;
}
}
static void
V_744 ( struct V_723 * V_724 , enum V_725 V_4 )
{
F_3 ( V_724 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_740 :
F_293 ( V_724 , V_741 ) ;
break;
case V_739 :
F_294 ( V_724 -> V_20 , & V_724 -> V_398 ,
V_732 , V_724 , V_733 ) ;
F_293 ( V_724 , V_743 ) ;
break;
case V_737 :
F_294 ( V_724 -> V_20 , & V_724 -> V_398 ,
V_732 , V_724 , V_733 ) ;
F_293 ( V_724 , V_745 ) ;
break;
case V_738 :
F_293 ( V_724 , V_746 ) ;
break;
default:
F_5 ( V_724 -> V_20 , V_4 ) ;
}
}
static void
V_746 ( struct V_723 * V_724 ,
enum V_725 V_4 )
{
F_3 ( V_724 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_727 :
F_294 ( V_724 -> V_20 , & V_724 -> V_398 ,
V_732 , V_724 , V_733 ) ;
F_293 ( V_724 , V_743 ) ;
break;
case V_737 :
F_293 ( V_724 , F_292 ) ;
F_9 ( & V_724 -> V_20 -> V_729 , V_730 ) ;
break;
case V_738 :
break;
default:
F_5 ( V_724 -> V_20 , V_4 ) ;
}
}
static void
F_297 ( struct V_747 * V_400 , struct V_748 * V_749 ,
struct V_750 * V_20 )
{
struct V_751 * V_752 = F_298 ( V_20 ) ;
if ( V_400 -> V_753 . V_728 )
F_299 ( V_749 , V_752 ,
sizeof( struct V_754 ) ) ;
else
F_299 ( V_749 , V_752 ,
sizeof( struct V_735 ) ) ;
}
static void
F_300 ( struct V_750 * V_20 , void * V_33 , struct V_747 * V_400 ,
struct V_251 * V_138 )
{
struct V_723 * V_724 = F_301 ( V_20 ) ;
V_724 -> V_33 = V_33 ;
V_724 -> V_20 = V_20 ;
V_724 -> V_572 = V_20 -> V_2 . V_354 ;
F_3 ( V_20 , V_724 -> V_572 ) ;
V_724 -> V_724 = (struct V_735 * ) F_302 ( V_724 ) ;
if ( V_400 -> V_753 . V_728 ) {
F_302 ( V_724 ) += sizeof( struct V_754 ) ;
V_724 -> V_728 = V_77 ;
} else {
V_724 -> V_728 = V_50 ;
F_302 ( V_724 ) += sizeof( struct V_735 ) ;
}
F_303 ( V_20 ) = V_50 ;
F_293 ( V_724 , F_292 ) ;
}
static void
V_736 ( void * V_397 , T_4 V_142 )
{
struct V_750 * V_20 = V_397 ;
struct V_723 * V_724 = F_301 ( V_20 ) ;
if ( V_142 == V_34 ) {
F_303 ( V_20 ) = V_77 ;
if ( V_724 -> V_724 -> V_755 . V_126 != V_756 )
V_724 -> V_724 -> V_755 . V_126 = V_756 ;
if ( V_724 -> V_724 -> V_755 . V_757 != V_758 )
V_724 -> V_724 -> V_755 . V_757 = V_758 ;
}
F_304 ( V_724 , V_740 ) ;
F_9 ( & V_20 -> V_729 , V_730 ) ;
}
void
F_305 ( struct V_750 * V_20 )
{
struct V_723 * V_724 = F_301 ( V_20 ) ;
F_304 ( V_724 , V_727 ) ;
}
static void
F_306 ( struct V_750 * V_20 )
{
}
static void
F_307 ( struct V_750 * V_20 )
{
}
static void V_732 ( void * V_98 )
{
struct V_723 * V_724 = V_98 ;
F_304 ( V_724 , V_742 ) ;
}
static void
F_308 ( struct V_750 * V_20 )
{
struct V_723 * V_724 = F_301 ( V_20 ) ;
F_304 ( V_724 , V_738 ) ;
}
static void
F_309 ( struct V_750 * V_20 )
{
}
static T_4
F_296 ( struct V_723 * V_724 )
{
T_4 V_726 ;
F_3 ( V_724 -> V_20 , 0 ) ;
V_726 = F_255 ( F_295 ( V_724 -> V_20 ) ,
V_734 , V_724 -> V_572 ,
V_724 -> V_724 , sizeof( struct V_735 ) , 0 ,
V_759 , V_724 ) ;
if ( V_726 != V_34 )
F_76 ( V_726 ) ;
F_3 ( V_724 -> V_20 , V_726 ) ;
return V_726 ;
}
T_4
F_310 ( struct V_750 * V_20 )
{
struct V_723 * V_724 = F_301 ( V_20 ) ;
F_3 ( V_724 -> V_20 , 0 ) ;
if ( F_311 ( V_724 , V_746 ) )
return V_219 ;
if ( V_724 -> V_728 ) {
F_3 ( V_724 -> V_20 , V_724 -> V_728 ) ;
return V_219 ;
}
F_304 ( V_724 , V_739 ) ;
return V_34 ;
}
static void
V_759 ( void * V_397 , T_4 V_142 )
{
struct V_723 * V_724 = V_397 ;
F_76 ( V_142 ) ;
F_304 ( V_724 , V_740 ) ;
}
void
F_312 ( struct V_750 * V_20 )
{
struct V_723 * V_724 = F_301 ( V_20 ) ;
F_304 ( V_724 , V_737 ) ;
}
static void
F_313 ( void * V_98 , enum V_93 V_4 )
{
struct V_760 * V_761 = V_98 ;
F_3 ( V_761 , V_4 ) ;
switch ( V_4 ) {
case V_99 :
case V_221 :
if ( V_761 -> V_566 ) {
V_761 -> V_142 = V_21 ;
V_761 -> V_18 ( V_761 -> V_98 , V_761 -> V_142 ) ;
V_761 -> V_566 = 0 ;
}
break;
default:
break;
}
}
static void
F_314 ( void * V_98 , enum V_762 V_763 )
{
struct V_760 * V_761 = V_98 ;
struct V_764 * V_214 =
(struct V_764 * ) V_761 -> V_435 . V_214 ;
T_1 V_158 ;
V_214 -> V_376 = F_135 ( V_761 -> V_573 + V_761 -> V_376 ) ;
V_158 = ( V_761 -> V_574 < V_765 ) ?
V_761 -> V_574 : V_765 ;
V_214 -> V_576 = F_135 ( V_158 ) ;
V_214 -> V_577 = ( V_158 == V_761 -> V_574 ) ? 1 : 0 ;
V_214 -> V_766 = ( V_158 == V_761 -> V_574 ) ? V_761 -> V_766 : 0 ;
F_102 ( V_214 -> V_167 , V_767 , V_763 , F_103 ( V_761 -> V_2 ) ) ;
F_231 ( & V_214 -> V_486 , V_158 , V_761 -> V_488 ) ;
memcpy ( V_761 -> V_503 , V_761 -> V_579 + V_761 -> V_376 , V_158 ) ;
F_153 ( V_761 -> V_2 , & V_761 -> V_435 ) ;
V_761 -> V_574 -= V_158 ;
V_761 -> V_376 += V_158 ;
}
static void
F_315 ( void * V_98 , enum V_762 V_763 )
{
struct V_760 * V_761 = V_98 ;
struct V_768 * V_214 =
(struct V_768 * ) V_761 -> V_435 . V_214 ;
T_1 V_158 ;
V_214 -> V_376 = F_135 ( V_761 -> V_573 + V_761 -> V_376 ) ;
V_158 = ( V_761 -> V_574 < V_765 ) ?
V_761 -> V_574 : V_765 ;
V_214 -> V_576 = F_135 ( V_158 ) ;
F_102 ( V_214 -> V_167 , V_767 , V_763 , F_103 ( V_761 -> V_2 ) ) ;
F_231 ( & V_214 -> V_486 , V_158 , V_761 -> V_488 ) ;
F_153 ( V_761 -> V_2 , & V_761 -> V_435 ) ;
}
T_1
F_316 ( T_2 V_614 )
{
if ( V_614 )
return 0 ;
return F_210 ( V_765 , V_429 ) ;
}
void
F_317 ( struct V_760 * V_761 , struct V_1 * V_2 , void * V_552 ,
struct V_553 * V_554 , T_2 V_614 )
{
V_761 -> V_2 = V_2 ;
V_761 -> V_554 = V_554 ;
V_761 -> V_18 = NULL ;
V_761 -> V_98 = NULL ;
V_761 -> V_566 = 0 ;
F_152 ( V_761 -> V_2 , V_767 , V_769 , V_761 ) ;
F_213 ( & V_761 -> V_432 ) ;
F_214 ( & V_761 -> V_432 , F_313 , V_761 ) ;
F_154 ( & V_761 -> V_432 . V_97 , & V_761 -> V_2 -> V_250 ) ;
if ( V_614 ) {
V_761 -> V_503 = NULL ;
V_761 -> V_488 = 0 ;
}
}
void
F_318 ( struct V_760 * V_761 , T_6 * V_277 , T_7 V_278 ,
T_2 V_614 )
{
if ( V_614 )
return;
V_761 -> V_503 = V_277 ;
V_761 -> V_488 = V_278 ;
memset ( V_761 -> V_503 , 0 , V_765 ) ;
V_277 += F_210 ( V_765 , V_429 ) ;
V_278 += F_210 ( V_765 , V_429 ) ;
}
T_4
F_319 ( struct V_760 * V_761 , void * V_218 , T_1 V_158 , T_1 V_376 ,
T_19 V_18 , void * V_98 , T_6 V_766 )
{
F_3 ( V_761 , V_770 ) ;
F_3 ( V_761 , V_158 ) ;
F_3 ( V_761 , V_376 ) ;
if ( V_761 -> V_2 -> V_188 != V_269 &&
V_761 -> V_2 -> V_196 -> V_198 != V_771 )
return V_772 ;
if ( V_761 -> V_2 -> V_196 -> V_198 != V_773 )
return V_686 ;
if ( ! F_131 ( V_761 -> V_2 ) )
return V_556 ;
if ( V_761 -> V_566 ) {
F_3 ( V_761 , V_761 -> V_566 ) ;
return V_384 ;
}
V_761 -> V_566 = 1 ;
V_761 -> V_18 = V_18 ;
V_761 -> V_98 = V_98 ;
V_761 -> V_574 = V_158 ;
V_761 -> V_376 = 0 ;
V_761 -> V_573 = V_376 ;
V_761 -> V_579 = V_218 ;
V_761 -> V_766 = V_766 ;
F_314 ( V_761 , V_770 ) ;
return V_34 ;
}
T_4
F_320 ( struct V_760 * V_761 , void * V_218 , T_1 V_158 , T_1 V_376 ,
T_19 V_18 , void * V_98 )
{
F_3 ( V_761 , V_774 ) ;
F_3 ( V_761 , V_158 ) ;
F_3 ( V_761 , V_376 ) ;
if ( V_761 -> V_2 -> V_188 != V_269 )
return V_772 ;
if ( V_761 -> V_2 -> V_196 -> V_198 != V_773 &&
V_761 -> V_2 -> V_196 -> V_198 != V_771 )
return V_686 ;
if ( ! F_131 ( V_761 -> V_2 ) )
return V_556 ;
if ( V_761 -> V_566 ) {
F_3 ( V_761 , V_761 -> V_566 ) ;
return V_384 ;
}
V_761 -> V_566 = 1 ;
V_761 -> V_18 = V_18 ;
V_761 -> V_98 = V_98 ;
V_761 -> V_574 = V_158 ;
V_761 -> V_376 = 0 ;
V_761 -> V_573 = V_376 ;
V_761 -> V_579 = V_218 ;
F_315 ( V_761 , V_774 ) ;
return V_34 ;
}
T_4
F_321 ( struct V_760 * V_761 , T_1 * V_775 )
{
if ( V_761 -> V_2 -> V_188 != V_269 )
return V_772 ;
if ( ! F_131 ( V_761 -> V_2 ) )
return V_556 ;
if ( V_761 -> V_2 -> V_196 -> V_198 == V_773 ||
V_761 -> V_2 -> V_196 -> V_198 == V_771 )
* V_775 = V_776 ;
else
return V_686 ;
return V_34 ;
}
T_4
F_322 ( struct V_760 * V_761 , void * V_218 , T_1 V_158 , T_1 V_376 ,
T_19 V_18 , void * V_98 )
{
F_3 ( V_761 , V_777 ) ;
F_3 ( V_761 , V_158 ) ;
F_3 ( V_761 , V_376 ) ;
F_3 ( V_761 , * ( ( T_6 * ) V_218 ) ) ;
if ( V_761 -> V_2 -> V_188 != V_269 )
return V_772 ;
if ( ! F_131 ( V_761 -> V_2 ) )
return V_556 ;
if ( V_761 -> V_566 ) {
F_3 ( V_761 , V_761 -> V_566 ) ;
return V_384 ;
}
V_761 -> V_566 = 1 ;
V_761 -> V_18 = V_18 ;
V_761 -> V_98 = V_98 ;
V_761 -> V_574 = V_158 ;
V_761 -> V_376 = 0 ;
V_761 -> V_573 = V_376 ;
V_761 -> V_579 = V_218 ;
F_314 ( V_761 , V_777 ) ;
return V_34 ;
}
T_4
F_323 ( struct V_760 * V_761 , void * V_218 , T_1 V_158 , T_1 V_376 ,
T_19 V_18 , void * V_98 )
{
F_3 ( V_761 , V_778 ) ;
F_3 ( V_761 , V_158 ) ;
F_3 ( V_761 , V_376 ) ;
if ( V_761 -> V_2 -> V_188 != V_269 )
return V_772 ;
if ( ! F_131 ( V_761 -> V_2 ) )
return V_556 ;
if ( V_761 -> V_566 ) {
F_3 ( V_761 , V_761 -> V_566 ) ;
return V_384 ;
}
V_761 -> V_566 = 1 ;
V_761 -> V_18 = V_18 ;
V_761 -> V_98 = V_98 ;
V_761 -> V_574 = V_158 ;
V_761 -> V_376 = 0 ;
V_761 -> V_573 = V_376 ;
V_761 -> V_579 = V_218 ;
F_315 ( V_761 , V_778 ) ;
return V_34 ;
}
void
V_769 ( void * V_779 , struct V_233 * V_214 )
{
struct V_760 * V_761 = V_779 ;
struct V_780 * V_417 = (struct V_780 * ) V_214 ;
T_1 V_142 ;
F_3 ( V_761 , V_214 -> V_167 . V_236 ) ;
if ( ! V_761 -> V_566 ) {
F_3 ( V_761 , 0x9999 ) ;
return;
}
switch ( V_214 -> V_167 . V_236 ) {
case V_781 :
case V_782 :
V_142 = F_106 ( V_417 -> V_142 ) ;
F_3 ( V_761 , V_142 ) ;
if ( V_142 != V_34 || V_761 -> V_574 == 0 ) {
V_761 -> V_142 = V_142 ;
V_761 -> V_566 = 0 ;
if ( V_761 -> V_18 )
V_761 -> V_18 ( V_761 -> V_98 , V_761 -> V_142 ) ;
} else {
F_3 ( V_761 , V_761 -> V_376 ) ;
if ( V_214 -> V_167 . V_236 == V_781 )
F_314 ( V_761 ,
V_770 ) ;
else
F_314 ( V_761 ,
V_777 ) ;
}
break;
case V_783 :
case V_784 :
V_142 = F_106 ( V_417 -> V_142 ) ;
F_3 ( V_761 , V_142 ) ;
if ( V_142 != V_34 ) {
V_761 -> V_142 = V_142 ;
V_761 -> V_566 = 0 ;
if ( V_761 -> V_18 )
V_761 -> V_18 ( V_761 -> V_98 , V_761 -> V_142 ) ;
} else {
T_1 V_158 = F_106 ( V_417 -> V_576 ) ;
F_3 ( V_761 , V_761 -> V_376 ) ;
F_3 ( V_761 , V_158 ) ;
memcpy ( V_761 -> V_579 + V_761 -> V_376 , V_761 -> V_503 , V_158 ) ;
V_761 -> V_574 -= V_158 ;
V_761 -> V_376 += V_158 ;
if ( V_761 -> V_574 == 0 ) {
V_761 -> V_142 = V_142 ;
V_761 -> V_566 = 0 ;
if ( V_761 -> V_18 )
V_761 -> V_18 ( V_761 -> V_98 , V_761 -> V_142 ) ;
} else {
if ( V_214 -> V_167 . V_236 == V_783 )
F_315 ( V_761 ,
V_774 ) ;
else
F_315 ( V_761 ,
V_778 ) ;
}
}
break;
default:
F_76 ( 1 ) ;
}
}
static void
F_324 ( void T_3 * V_785 , T_6 V_786 ,
T_6 V_787 , T_6 V_788 , T_6 V_789 )
{
union V_790 V_212 ;
V_212 . V_61 = 0 ;
V_212 . V_528 . V_632 = 1 ;
V_212 . V_528 . V_791 = V_786 ;
V_212 . V_528 . V_792 = V_787 ;
V_212 . V_528 . V_793 = V_788 ;
V_212 . V_528 . V_212 = V_789 ;
F_31 ( V_212 . V_61 , ( V_785 + V_794 ) ) ;
}
static void
F_325 ( void T_3 * V_785 , T_1 V_795 )
{
union V_796 V_437 ;
V_437 . V_528 . V_437 = V_795 & 0x00ffffff ;
V_437 . V_528 . V_797 = 0 ;
F_31 ( V_437 . V_61 , ( V_785 + V_798 ) ) ;
}
static int
F_326 ( void T_3 * V_785 )
{
union V_790 V_212 ;
V_212 . V_61 = F_28 ( V_785 + V_794 ) ;
if ( V_212 . V_528 . V_632 )
return V_799 ;
return 0 ;
}
static T_1
F_327 ( void T_3 * V_785 )
{
T_1 V_61 ;
T_1 V_800 ;
union V_801 V_802 ;
V_802 . V_61 = F_28 ( V_785 + V_803 ) ;
if ( ! V_802 . V_528 . V_804 )
return 0 ;
for ( V_61 = 0 ; V_61 < V_802 . V_528 . V_804 ; V_61 ++ )
V_800 = F_28 ( V_785 + V_805 ) ;
for ( V_61 = 0 ; V_61 < V_806 ; V_61 ++ ) {
V_802 . V_61 = F_28 ( V_785 + V_803 ) ;
if ( ! V_802 . V_528 . V_804 )
break;
}
if ( V_802 . V_528 . V_804 )
return V_807 ;
return 0 ;
}
static T_1
F_328 ( void T_3 * V_785 )
{
union V_801 V_802 ;
int V_142 ;
T_1 V_808 ;
int V_61 ;
V_142 = F_327 ( V_785 ) ;
if ( V_142 < 0 )
return V_142 ;
F_324 ( V_785 , 0 , 4 , 0 , V_809 ) ;
for ( V_61 = 0 ; V_61 < V_806 ; V_61 ++ ) {
V_142 = F_326 ( V_785 ) ;
if ( ! V_142 )
break;
}
if ( V_142 )
return V_142 ;
V_802 . V_61 = F_28 ( V_785 + V_803 ) ;
if ( ! V_802 . V_528 . V_804 )
return V_810 ;
V_808 = F_28 ( V_785 + V_805 ) ;
V_808 >>= 24 ;
V_142 = F_327 ( V_785 ) ;
if ( V_142 < 0 )
return V_142 ;
return V_808 ;
}
static T_1
F_329 ( void T_3 * V_785 , T_1 V_376 , T_1 V_158 ,
char * V_218 )
{
int V_142 ;
if ( V_158 == 0 || V_158 > V_811 || ( V_158 & 0x03 ) != 0 )
return V_812 ;
V_142 = F_328 ( V_785 ) ;
if ( V_142 == V_810 )
V_142 = F_328 ( V_785 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( V_142 & V_813 )
return V_814 ;
F_325 ( V_785 , V_376 ) ;
F_324 ( V_785 , 0 , ( T_6 ) V_158 , 4 , V_815 ) ;
return 0 ;
}
static T_1
F_330 ( void T_3 * V_785 )
{
if ( F_326 ( V_785 ) )
return 1 ;
return 0 ;
}
static void
F_331 ( void T_3 * V_785 , T_1 V_158 , char * V_218 )
{
T_1 V_61 ;
for ( V_61 = 0 ; V_61 < V_158 ; V_61 += 4 ) {
T_1 V_816 = F_28 ( V_785 + V_805 ) ;
* ( ( T_1 * ) ( V_218 + V_61 ) ) = F_33 ( V_816 ) ;
}
F_327 ( V_785 ) ;
}
static int
F_332 ( void T_3 * V_817 )
{
int V_818 ;
V_818 = F_28 ( ( V_817 + V_819 ) ) ;
return ! V_818 ;
}
T_4
F_333 ( void T_3 * V_817 )
{
T_1 V_820 = V_821 ;
while ( ! F_332 ( V_817 ) ) {
if ( -- V_820 <= 0 )
return V_822 ;
F_334 ( 10 ) ;
}
return V_34 ;
}
void
F_335 ( void T_3 * V_817 )
{
F_31 ( 0 , ( V_817 + V_819 ) ) ;
}
T_4
F_93 ( void T_3 * V_785 , T_1 V_376 , char * V_218 ,
T_1 V_158 )
{
T_1 V_820 ;
int V_142 ;
T_1 V_136 , V_823 , V_824 , V_574 , V_825 ;
V_574 = V_158 ;
V_136 = 0 ;
V_825 = V_811 ;
V_142 = F_333 ( V_785 ) ;
if ( V_142 != V_34 )
return V_142 ;
while ( V_574 ) {
V_824 = V_376 + V_136 ;
V_820 = V_824 / V_825 ;
V_823 = ( V_820 + 1 ) * V_825 - V_824 ;
if ( V_823 > V_574 )
V_823 = V_574 ;
V_142 = F_329 ( V_785 , V_376 + V_136 , V_823 ,
& V_218 [ V_136 ] ) ;
if ( V_142 < 0 ) {
F_335 ( V_785 ) ;
return V_219 ;
}
V_820 = V_826 ;
while ( F_330 ( V_785 ) ) {
if ( -- V_820 <= 0 ) {
F_335 ( V_785 ) ;
return V_219 ;
}
}
F_331 ( V_785 , V_823 , & V_218 [ V_136 ] ) ;
V_574 -= V_823 ;
V_136 += V_823 ;
}
F_335 ( V_785 ) ;
return V_34 ;
}
