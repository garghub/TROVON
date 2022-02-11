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
V_57 = F_28 ( V_7 -> V_2 -> V_62 . V_64 ) ;
if ( V_57 == V_65 ) {
F_30 ( 1 , V_7 -> V_2 -> V_62 . V_63 ) ;
goto V_66;
}
F_31 ( V_7 -> V_2 , & V_55 ) ;
if ( F_32 ( V_55 . V_67 ) == V_68 ) {
F_30 ( 1 , V_7 -> V_2 -> V_62 . V_63 ) ;
goto V_66;
}
V_58 = F_33 ( V_7 -> V_2 -> V_62 . V_69 , V_60 ) ;
V_59 = F_34 ( V_60 ) ;
F_30 ( V_58 , V_7 -> V_2 -> V_62 . V_70 ) ;
for ( V_61 = 0 ; V_61 < sizeof( struct V_54 ) / sizeof( T_1 ) ; V_61 ++ ) {
F_35 ( V_7 -> V_2 -> V_62 . V_71 , V_60 , 0 ) ;
V_60 += sizeof( T_1 ) ;
}
F_3 ( V_7 -> V_2 , V_57 ) ;
F_3 ( V_7 -> V_2 , F_32 ( V_55 . V_67 ) ) ;
F_30 ( V_65 , V_7 -> V_2 -> V_62 . V_64 ) ;
F_30 ( V_65 , V_7 -> V_2 -> V_62 . V_72 ) ;
F_28 ( V_7 -> V_2 -> V_62 . V_73 ) ;
F_30 ( 1 , V_7 -> V_2 -> V_62 . V_73 ) ;
F_30 ( 1 , V_7 -> V_2 -> V_62 . V_63 ) ;
V_66:
F_36 ( V_7 -> V_2 ) ;
}
static void
V_53 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_74 :
if ( F_37 ( V_2 ) ) {
if ( F_38 ( V_2 ) ) {
F_39 ( V_2 ) ;
F_4 ( V_7 , V_75 ) ;
} else {
F_40 ( V_2 ) ;
F_30 ( 1 , V_2 -> V_62 . V_73 ) ;
F_41 ( V_2 ) ;
}
} else {
F_30 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_76 ) ;
}
break;
case V_77 :
F_4 ( V_7 , V_78 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_43 :
F_42 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
F_9 ( V_2 , V_45 ) ;
break;
case V_27 :
F_42 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_43 ( struct V_48 * V_7 )
{
if ( V_7 -> V_49 == V_50 )
F_44 ( V_7 -> V_2 ) ;
V_7 -> V_49 = V_79 ;
F_45 ( V_7 -> V_2 ) ;
}
static void
V_76 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_80 :
F_4 ( V_7 , V_53 ) ;
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
F_36 ( V_7 -> V_2 ) ;
}
static void
F_48 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_74 :
if ( F_49 ( V_2 ) ) {
F_39 ( V_2 ) ;
F_4 ( V_7 , V_75 ) ;
} else {
F_30 ( 1 , V_2 -> V_62 . V_73 ) ;
F_41 ( V_2 ) ;
}
break;
case V_77 :
F_4 ( V_7 , V_78 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_43 :
F_42 ( V_2 ) ;
F_4 ( V_7 , V_81 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_50 ( struct V_48 * V_7 )
{
V_7 -> V_82 = 0 ;
F_51 ( V_7 -> V_2 , V_50 ) ;
}
static void
V_75 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_83 :
F_4 ( V_7 , V_84 ) ;
break;
case V_80 :
F_30 ( 1 , V_2 -> V_62 . V_73 ) ;
F_9 ( V_2 , V_16 ) ;
F_4 ( V_7 , V_85 ) ;
break;
case V_43 :
F_46 ( V_2 ) ;
F_52 ( V_2 ) ;
F_30 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_86 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_53 ( struct V_48 * V_7 )
{
F_45 ( V_7 -> V_2 ) ;
V_7 -> V_2 -> V_18 -> V_87 ( V_7 -> V_2 -> V_20 ) ;
F_54 ( V_7 -> V_2 ) ;
}
static void
V_84 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_88 :
F_46 ( V_2 ) ;
F_30 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_89 ) ;
break;
case V_23 :
F_46 ( V_2 ) ;
case V_80 :
F_30 ( 1 , V_2 -> V_62 . V_73 ) ;
if ( V_4 == V_80 )
F_9 ( V_2 , V_16 ) ;
F_4 ( V_7 , V_85 ) ;
break;
case V_43 :
F_46 ( V_2 ) ;
F_30 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_90 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_55 ( struct V_48 * V_7 )
{
F_9 ( V_7 -> V_2 , V_14 ) ;
}
static void
V_89 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_43 :
F_4 ( V_7 , V_90 ) ;
break;
case V_31 :
F_4 ( V_7 , V_85 ) ;
break;
case V_42 :
F_4 ( V_7 , V_91 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_56 ( struct V_48 * V_7 )
{
F_45 ( V_7 -> V_2 ) ;
F_57 ( V_7 -> V_2 ) ;
}
static void
V_90 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_92 :
F_46 ( V_2 ) ;
F_4 ( V_7 , V_81 ) ;
break;
case V_42 :
F_46 ( V_2 ) ;
case V_80 :
F_30 ( V_93 , V_2 -> V_62 . V_64 ) ;
F_4 ( V_7 , V_81 ) ;
break;
case V_88 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_58 ( struct V_48 * V_7 )
{
F_36 ( V_7 -> V_2 ) ;
}
static void
V_81 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_74 :
F_52 ( V_2 ) ;
F_30 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_86 ) ;
break;
case V_77 :
F_4 ( V_7 , V_78 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_42 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_59 ( struct V_48 * V_7 )
{
F_60 ( V_7 -> V_2 ) ;
F_9 ( V_7 -> V_2 , V_45 ) ;
}
static void
V_86 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_13 :
F_4 ( V_7 , F_48 ) ;
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
F_61 ( struct V_48 * V_7 )
{
F_62 ( V_7 -> V_2 ) ;
F_36 ( V_7 -> V_2 ) ;
}
static void
V_85 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_74 :
F_63 ( V_2 ) ;
F_52 ( V_2 ) ;
F_30 ( V_93 , V_2 -> V_62 . V_64 ) ;
F_30 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_94 ) ;
break;
case V_77 :
F_4 ( V_7 , V_78 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_43 :
F_42 ( V_2 ) ;
F_4 ( V_7 , V_81 ) ;
break;
case V_27 :
F_42 ( V_2 ) ;
F_40 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
case V_42 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_64 ( struct V_48 * V_7 )
{
F_3 ( V_7 -> V_2 , 0 ) ;
}
static void
V_94 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_43 :
F_4 ( V_7 , V_86 ) ;
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
F_65 ( struct V_48 * V_7 )
{
F_66 ( V_7 -> V_2 ) ;
F_60 ( V_7 -> V_2 ) ;
F_36 ( V_7 -> V_2 ) ;
}
static void
V_91 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_74 :
F_67 ( V_2 ) ;
F_63 ( V_2 ) ;
if ( ! V_7 -> V_40 ) {
F_52 ( V_2 ) ;
F_30 ( V_93 , V_2 -> V_62 . V_64 ) ;
F_30 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , V_78 ) ;
} else {
if ( F_49 ( V_2 ) )
F_4 ( V_7 , V_75 ) ;
else {
F_30 ( 1 , V_2 -> V_62 . V_73 ) ;
F_4 ( V_7 , F_48 ) ;
}
}
break;
case V_77 :
F_4 ( V_7 , V_78 ) ;
F_9 ( V_2 , V_24 ) ;
break;
case V_43 :
F_42 ( V_2 ) ;
F_4 ( V_7 , V_81 ) ;
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
V_78 ( struct V_48 * V_7 , enum V_52 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_43 :
F_4 ( V_7 , V_86 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_15 ( struct V_1 * V_2 , enum V_95 V_4 )
{
struct V_96 * V_97 ;
struct V_98 * V_99 ;
F_69 (qe, &ioc->notify_q) {
V_97 = (struct V_96 * ) V_99 ;
V_97 -> V_18 ( V_97 -> V_100 , V_4 ) ;
}
}
static void
F_7 ( struct V_1 * V_2 )
{
V_2 -> V_18 -> V_47 ( V_2 -> V_20 ) ;
F_15 ( V_2 , V_101 ) ;
}
T_2
F_70 ( void T_3 * V_102 )
{
T_1 V_56 ;
int V_103 = 0 ;
#define F_71 3000
V_56 = F_28 ( V_102 ) ;
while ( ( V_56 & 1 ) && ( V_103 < F_71 ) ) {
V_103 ++ ;
F_29 ( 2 ) ;
V_56 = F_28 ( V_102 ) ;
}
if ( ! ( V_56 & 1 ) )
return V_79 ;
return V_50 ;
}
static void
F_36 ( struct V_1 * V_2 )
{
T_1 V_56 ;
V_56 = F_28 ( V_2 -> V_62 . V_73 ) ;
if ( V_56 == ~ 0 ) {
F_72 ( V_56 == ~ 0 ) ;
F_9 ( & V_2 -> V_7 , V_77 ) ;
return;
}
if ( ! ( V_56 & 1 ) ) {
F_9 ( & V_2 -> V_7 , V_74 ) ;
return;
}
F_41 ( V_2 ) ;
}
static void
F_73 ( struct V_1 * V_2 )
{
T_1 V_104 ;
int V_61 ;
#define F_74 10000
V_104 = F_28 ( V_2 -> V_62 . V_105 ) ;
V_104 &= ~ V_106 ;
V_104 |= V_107 ;
V_104 |= F_75 ( 3UL ) ;
F_30 ( V_104 , V_2 -> V_62 . V_105 ) ;
V_61 = 0 ;
do {
V_104 = F_28 ( V_2 -> V_62 . V_105 ) ;
V_61 ++ ;
} while ( ! ( V_104 & V_108 ) && ( V_61 < F_74 ) );
F_72 ( ! ( V_104 & V_108 ) ) ;
F_3 ( V_2 , V_104 ) ;
V_104 &= ~ ( V_108 | V_107 ) ;
F_30 ( V_104 , V_2 -> V_62 . V_105 ) ;
}
static void
F_76 ( struct V_1 * V_2 )
{
T_1 V_104 ;
V_104 = F_28 ( V_2 -> V_62 . V_105 ) ;
V_104 &= ~ V_109 ;
F_30 ( V_104 , V_2 -> V_62 . V_105 ) ;
}
static void
F_66 ( struct V_1 * V_2 )
{
T_1 V_104 ;
V_104 = F_28 ( V_2 -> V_62 . V_105 ) ;
V_104 |= ( V_109 | V_110 ) ;
F_30 ( V_104 , V_2 -> V_62 . V_105 ) ;
}
void
F_31 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
T_1 V_58 , V_59 ;
T_1 V_60 = 0 ;
int V_61 ;
T_1 * V_111 = ( T_1 * ) V_55 ;
V_58 = F_33 ( V_2 -> V_62 . V_69 , V_60 ) ;
V_59 = F_34 ( V_60 ) ;
F_30 ( V_58 , V_2 -> V_62 . V_70 ) ;
for ( V_61 = 0 ; V_61 < ( sizeof( struct V_54 ) / sizeof( T_1 ) ) ;
V_61 ++ ) {
V_111 [ V_61 ] =
F_77 ( V_2 -> V_62 . V_71 , V_60 ) ;
V_60 += sizeof( T_1 ) ;
}
}
T_2
F_78 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_54 * V_112 ;
int V_61 ;
V_112 = (struct V_54 * )
F_79 ( F_80 ( V_2 ) , 0 ) ;
for ( V_61 = 0 ; V_61 < V_113 ; V_61 ++ ) {
if ( V_55 -> V_114 [ V_61 ] != V_112 -> V_114 [ V_61 ] ) {
F_3 ( V_2 , V_61 ) ;
F_3 ( V_2 , V_55 -> V_114 [ V_61 ] ) ;
F_3 ( V_2 , V_112 -> V_114 [ V_61 ] ) ;
return V_50 ;
}
}
F_3 ( V_2 , V_55 -> V_114 [ 0 ] ) ;
return V_79 ;
}
static T_2
F_81 ( struct V_1 * V_2 , T_1 V_115 )
{
struct V_54 V_55 , * V_112 ;
F_31 ( V_2 , & V_55 ) ;
V_112 = (struct V_54 * )
F_79 ( F_80 ( V_2 ) , 0 ) ;
if ( V_55 . V_116 != V_112 -> V_116 ) {
F_3 ( V_2 , V_55 . V_116 ) ;
F_3 ( V_2 , V_112 -> V_116 ) ;
return V_50 ;
}
if ( F_32 ( V_55 . V_117 ) != V_115 ) {
F_3 ( V_2 , V_55 . V_117 ) ;
F_3 ( V_2 , V_115 ) ;
return V_50 ;
}
return F_78 ( V_2 , & V_55 ) ;
}
static void
F_82 ( struct V_1 * V_2 )
{
T_1 V_56 ;
V_56 = F_28 ( V_2 -> V_62 . V_118 ) ;
if ( V_56 )
F_30 ( 1 , V_2 -> V_62 . V_118 ) ;
}
static void
F_51 ( struct V_1 * V_2 , T_2 V_119 )
{
enum V_120 V_64 ;
T_2 V_121 ;
T_1 V_122 ;
T_1 V_115 ;
V_64 = F_28 ( V_2 -> V_62 . V_64 ) ;
if ( V_119 )
V_64 = V_65 ;
F_3 ( V_2 , V_64 ) ;
V_122 = V_68 ;
V_115 = V_123 ;
V_121 = ( V_64 == V_65 ) ?
V_50 : F_81 ( V_2 , V_115 ) ;
if ( ! V_121 ) {
F_83 ( V_2 , V_122 , V_115 ) ;
F_84 ( V_2 ) ;
return;
}
if ( V_64 == V_124 ) {
F_84 ( V_2 ) ;
return;
}
if ( V_64 == V_125 || V_64 == V_126 ) {
F_82 ( V_2 ) ;
F_9 ( & V_2 -> V_7 , V_83 ) ;
return;
}
F_83 ( V_2 , V_122 , V_115 ) ;
F_84 ( V_2 ) ;
}
static void
F_85 ( void * V_127 )
{
struct V_1 * V_2 = (struct V_1 * ) V_127 ;
F_3 ( V_2 , 0 ) ;
F_9 ( V_2 , V_30 ) ;
}
void
F_86 ( struct V_1 * V_2 , void * V_128 , int V_129 )
{
T_1 * V_130 = ( T_1 * ) V_128 ;
T_1 V_61 ;
F_3 ( V_2 , V_130 [ 0 ] ) ;
F_3 ( V_2 , V_129 ) ;
F_72 ( V_129 > V_131 ) ;
for ( V_61 = 0 ; V_61 < V_129 / sizeof( T_1 ) ; V_61 ++ )
F_30 ( F_87 ( V_130 [ V_61 ] ) ,
V_2 -> V_62 . V_132 + V_61 * sizeof( T_1 ) ) ;
for (; V_61 < V_131 / sizeof( T_1 ) ; V_61 ++ )
F_30 ( 0 , V_2 -> V_62 . V_132 + V_61 * sizeof( T_1 ) ) ;
F_30 ( 1 , V_2 -> V_62 . V_133 ) ;
( void ) F_28 ( V_2 -> V_62 . V_133 ) ;
}
static void
F_54 ( struct V_1 * V_2 )
{
struct V_134 V_135 ;
struct V_136 V_137 ;
F_88 ( V_135 . V_138 , V_139 , V_140 ,
F_89 ( V_2 ) ) ;
V_135 . V_141 = F_90 ( V_2 -> V_141 ) ;
F_91 ( & V_137 ) ;
V_135 . V_142 = F_92 ( V_137 . V_142 ) ;
F_86 ( V_2 , & V_135 , sizeof( struct V_134 ) ) ;
}
static void
F_57 ( struct V_1 * V_2 )
{
struct V_134 V_143 ;
F_88 ( V_143 . V_138 , V_139 , V_144 ,
F_89 ( V_2 ) ) ;
F_86 ( V_2 , & V_143 , sizeof( struct V_134 ) ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
struct V_145 V_146 ;
F_88 ( V_146 . V_138 , V_139 , V_147 ,
F_89 ( V_2 ) ) ;
F_93 ( V_146 . V_148 , V_2 -> V_149 . V_150 ) ;
F_86 ( V_2 , & V_146 , sizeof( V_146 ) ) ;
}
static void
F_94 ( void * V_100 )
{
struct V_1 * V_2 = V_100 ;
T_1 V_151 ;
V_151 = F_28 ( V_2 -> V_62 . V_152 ) ;
if ( V_2 -> V_151 == V_151 ) {
F_95 ( V_2 ) ;
return;
} else {
V_2 -> V_151 = V_151 ;
}
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
}
static void
F_16 ( struct V_1 * V_2 )
{
V_2 -> V_151 = F_28 ( V_2 -> V_62 . V_152 ) ;
F_97 ( V_2 ) ;
}
static void
F_98 ( struct V_1 * V_2 , T_1 V_122 ,
T_1 V_115 )
{
T_1 * V_153 ;
T_1 V_58 , V_59 ;
T_1 V_60 = 0 ;
T_1 V_154 = 0 ;
T_1 V_61 ;
T_1 V_155 ;
F_3 ( V_2 , F_99 ( F_80 ( V_2 ) ) ) ;
V_153 = F_79 ( F_80 ( V_2 ) , V_154 ) ;
V_58 = F_33 ( V_2 -> V_62 . V_69 , V_60 ) ;
V_59 = F_34 ( V_60 ) ;
F_30 ( V_58 , V_2 -> V_62 . V_70 ) ;
for ( V_61 = 0 ; V_61 < F_99 ( F_80 ( V_2 ) ) ; V_61 ++ ) {
if ( F_100 ( V_61 ) != V_154 ) {
V_154 = F_100 ( V_61 ) ;
V_153 = F_79 ( F_80 ( V_2 ) ,
F_101 ( V_154 ) ) ;
}
F_35 ( V_2 -> V_62 . V_71 , V_60 ,
V_153 [ F_102 ( V_61 ) ] ) ;
V_60 += sizeof( T_1 ) ;
V_60 = F_34 ( V_60 ) ;
if ( V_60 == 0 ) {
V_58 ++ ;
F_30 ( V_58 , V_2 -> V_62 . V_70 ) ;
}
}
F_30 ( F_33 ( V_2 -> V_62 . V_69 , 0 ) ,
V_2 -> V_62 . V_70 ) ;
V_155 = F_103 ( V_2 -> V_156 , V_2 -> V_157 ,
V_2 -> V_158 , V_2 -> V_159 ) ;
F_35 ( V_2 -> V_62 . V_71 , V_160 ,
F_32 ( V_155 ) ) ;
F_35 ( V_2 -> V_62 . V_71 , V_161 ,
F_32 ( V_122 ) ) ;
F_35 ( V_2 -> V_62 . V_71 , V_162 ,
F_32 ( V_115 ) ) ;
}
static void
F_104 ( struct V_1 * V_2 )
{
struct V_163 * V_164 = V_2 -> V_164 ;
V_164 -> V_165 = F_92 ( V_164 -> V_165 ) ;
V_164 -> V_166 = F_92 ( V_164 -> V_166 ) ;
V_164 -> V_167 = F_105 ( V_164 -> V_167 ) ;
V_2 -> V_168 = ( V_164 -> V_169 == V_170 ) ;
F_9 ( V_2 , V_28 ) ;
}
static void
F_106 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
int V_174 ;
F_107 ( & V_172 -> V_175 ) ;
for ( V_174 = 0 ; V_174 < V_176 ; V_174 ++ ) {
V_172 -> V_177 [ V_174 ] . V_18 = NULL ;
V_172 -> V_177 [ V_174 ] . V_100 = V_2 -> V_20 ;
}
}
static void
F_96 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
struct V_178 * V_179 ;
T_1 V_180 ;
if ( F_108 ( & V_172 -> V_175 ) )
return;
V_180 = F_28 ( V_2 -> V_62 . V_133 ) ;
if ( V_180 )
return;
F_109 ( & V_172 -> V_175 , & V_179 ) ;
F_86 ( V_2 , V_179 -> V_181 , sizeof( V_179 -> V_181 ) ) ;
}
static void
F_60 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
struct V_178 * V_179 ;
while ( ! F_108 ( & V_172 -> V_175 ) )
F_109 ( & V_172 -> V_175 , & V_179 ) ;
}
static T_4
F_110 ( struct V_1 * V_2 , void * V_182 , T_1 V_183 , T_1 V_184 )
{
T_1 V_58 , V_60 ;
T_5 V_56 ;
int V_61 , V_129 ;
T_1 * V_185 = V_182 ;
V_58 = F_33 ( V_2 -> V_62 . V_69 , V_183 ) ;
V_60 = F_34 ( V_183 ) ;
F_3 ( V_2 , V_58 ) ;
F_3 ( V_2 , V_60 ) ;
F_3 ( V_2 , V_184 ) ;
if ( V_50 == F_70 ( V_2 -> V_62 . V_63 ) ) {
F_3 ( V_2 , 0 ) ;
return V_186 ;
}
F_30 ( V_58 , V_2 -> V_62 . V_70 ) ;
V_129 = V_184 / sizeof( T_1 ) ;
F_3 ( V_2 , V_129 ) ;
for ( V_61 = 0 ; V_61 < V_129 ; V_61 ++ ) {
V_56 = F_77 ( V_2 -> V_62 . V_71 , V_60 ) ;
V_185 [ V_61 ] = F_92 ( V_56 ) ;
V_60 += sizeof( T_1 ) ;
V_60 = F_34 ( V_60 ) ;
if ( V_60 == 0 ) {
V_58 ++ ;
F_30 ( V_58 , V_2 -> V_62 . V_70 ) ;
}
}
F_30 ( F_33 ( V_2 -> V_62 . V_69 , 0 ) ,
V_2 -> V_62 . V_70 ) ;
F_28 ( V_2 -> V_62 . V_63 ) ;
F_30 ( 1 , V_2 -> V_62 . V_63 ) ;
F_3 ( V_2 , V_58 ) ;
return V_34 ;
}
static T_4
F_111 ( struct V_1 * V_2 , T_1 V_183 , T_1 V_184 )
{
int V_61 , V_129 ;
T_1 V_58 , V_60 ;
V_58 = F_33 ( V_2 -> V_62 . V_69 , V_183 ) ;
V_60 = F_34 ( V_183 ) ;
F_3 ( V_2 , V_58 ) ;
F_3 ( V_2 , V_60 ) ;
F_3 ( V_2 , V_184 ) ;
if ( V_50 == F_70 ( V_2 -> V_62 . V_63 ) ) {
F_3 ( V_2 , 0 ) ;
return V_186 ;
}
F_30 ( V_58 , V_2 -> V_62 . V_70 ) ;
V_129 = V_184 / sizeof( T_1 ) ;
F_3 ( V_2 , V_129 ) ;
for ( V_61 = 0 ; V_61 < V_129 ; V_61 ++ ) {
F_35 ( V_2 -> V_62 . V_71 , V_60 , 0 ) ;
V_60 += sizeof( T_1 ) ;
V_60 = F_34 ( V_60 ) ;
if ( V_60 == 0 ) {
V_58 ++ ;
F_30 ( V_58 , V_2 -> V_62 . V_70 ) ;
}
}
F_30 ( F_33 ( V_2 -> V_62 . V_69 , 0 ) ,
V_2 -> V_62 . V_70 ) ;
F_28 ( V_2 -> V_62 . V_63 ) ;
F_30 ( 1 , V_2 -> V_62 . V_63 ) ;
F_3 ( V_2 , V_58 ) ;
return V_34 ;
}
static void
F_20 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 -> V_20 -> V_33 ;
V_2 -> V_18 -> V_187 ( V_2 -> V_20 ) ;
F_15 ( V_2 , V_188 ) ;
F_62 ( V_2 ) ;
F_17 ( V_189 , V_33 , V_37 ,
L_3 ) ;
F_18 ( V_2 , V_190 ) ;
}
static void
F_44 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 -> V_20 -> V_33 ;
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
F_17 ( V_191 , V_33 , V_37 ,
L_4
L_5 ) ;
F_18 ( V_2 , V_192 ) ;
}
T_4
F_112 ( struct V_1 * V_2 )
{
F_70 ( V_2 -> V_62 . V_63 ) ;
F_113 ( V_2 ) ;
V_2 -> V_193 = V_79 ;
F_73 ( V_2 ) ;
F_28 ( V_2 -> V_62 . V_63 ) ;
F_30 ( 1 , V_2 -> V_62 . V_63 ) ;
return V_34 ;
}
void
F_83 ( struct V_1 * V_2 , T_1 V_122 , T_1 V_115 )
{
F_114 ( V_2 , V_194 ) ;
if ( F_112 ( V_2 ) != V_34 )
return;
if ( V_122 == V_195 ) {
F_30 ( V_196 , V_2 -> V_62 . V_64 ) ;
F_30 ( V_196 , V_2 -> V_62 . V_72 ) ;
} else {
F_30 ( V_124 , V_2 -> V_62 . V_64 ) ;
F_30 ( V_124 , V_2 -> V_62 . V_72 ) ;
}
F_82 ( V_2 ) ;
F_98 ( V_2 , V_122 , V_115 ) ;
F_76 ( V_2 ) ;
}
void
F_115 ( T_2 V_40 )
{
V_51 = V_40 ;
}
T_2
F_116 ( struct V_1 * V_2 )
{
return F_117 ( V_2 , V_29 ) ;
}
T_2
F_118 ( struct V_1 * V_2 )
{
T_1 V_56 = F_28 ( V_2 -> V_62 . V_64 ) ;
return ( ( V_56 != V_65 ) &&
( V_56 != V_124 ) &&
( V_56 != V_196 ) ) ;
}
T_2
F_119 ( struct V_1 * V_2 , void * V_197 )
{
T_5 * V_130 = V_197 ;
T_1 V_56 ;
int V_61 ;
V_56 = F_28 ( V_2 -> V_62 . V_118 ) ;
if ( ( V_56 & 1 ) == 0 )
return V_50 ;
for ( V_61 = 0 ; V_61 < ( sizeof( union V_198 ) / sizeof( T_1 ) ) ;
V_61 ++ ) {
V_56 = F_28 ( V_2 -> V_62 . V_199 +
V_61 * sizeof( T_1 ) ) ;
V_130 [ V_61 ] = F_120 ( V_56 ) ;
}
F_30 ( 1 , V_2 -> V_62 . V_118 ) ;
F_28 ( V_2 -> V_62 . V_118 ) ;
return V_79 ;
}
void
F_121 ( struct V_1 * V_2 , struct V_200 * V_201 )
{
union V_198 * V_181 ;
struct V_48 * V_7 = & V_2 -> V_7 ;
V_181 = (union V_198 * ) V_201 ;
F_114 ( V_2 , V_202 ) ;
switch ( V_181 -> V_138 . V_203 ) {
case V_204 :
break;
case V_205 :
V_2 -> V_169 = V_2 -> V_206 =
(enum V_207 ) V_181 -> V_208 . V_169 ;
V_2 -> V_209 = V_181 -> V_208 . V_210 ;
F_9 ( V_7 , V_88 ) ;
break;
case V_211 :
F_9 ( V_7 , V_92 ) ;
break;
case V_212 :
F_104 ( V_2 ) ;
break;
default:
F_3 ( V_2 , V_181 -> V_138 . V_203 ) ;
F_72 ( 1 ) ;
}
}
void
F_122 ( struct V_1 * V_2 , void * V_20 , struct V_213 * V_18 ,
struct V_214 * V_215 )
{
V_2 -> V_20 = V_20 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_215 = V_215 ;
V_2 -> V_168 = V_50 ;
V_2 -> V_193 = V_50 ;
V_2 -> V_216 = V_79 ;
V_2 -> V_7 . V_2 = V_2 ;
F_106 ( V_2 ) ;
F_107 ( & V_2 -> V_217 ) ;
F_4 ( V_2 , F_2 ) ;
F_9 ( V_2 , V_5 ) ;
}
void
F_123 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_12 ) ;
F_107 ( & V_2 -> V_217 ) ;
}
void
F_124 ( struct V_1 * V_2 , struct V_218 * V_219 ,
enum V_220 V_141 )
{
V_2 -> V_141 = V_141 ;
V_2 -> V_219 = * V_219 ;
V_2 -> V_158 = V_2 -> V_159 = V_170 ;
V_2 -> V_157 = V_221 ;
switch ( V_219 -> V_222 ) {
case V_223 :
case V_224 :
V_2 -> V_156 = V_225 ;
V_2 -> V_168 = V_79 ;
V_2 -> V_169 = V_2 -> V_206 = V_226 ;
V_2 -> V_209 = V_227 ;
break;
case V_228 :
V_2 -> V_156 = V_229 ;
V_2 -> V_158 = V_2 -> V_159 = V_230 ;
V_2 -> V_157 = V_231 ;
V_2 -> V_169 = V_2 -> V_206 = V_232 ;
V_2 -> V_209 = V_233 ;
break;
case V_234 :
V_2 -> V_156 = V_229 ;
V_2 -> V_168 = V_79 ;
V_2 -> V_169 = V_2 -> V_206 = V_226 ;
V_2 -> V_209 = V_227 ;
break;
case V_235 :
V_2 -> V_156 = V_236 ;
if ( V_141 == V_237 &&
V_219 -> V_238 == V_239 ) {
V_2 -> V_157 = V_240 ;
V_2 -> V_168 = V_79 ;
V_2 -> V_169 = V_2 -> V_206 = V_226 ;
V_2 -> V_209 = V_227 ;
} else {
V_2 -> V_158 = V_2 -> V_159 = V_230 ;
V_2 -> V_157 = V_231 ;
if ( V_219 -> V_238 == V_241 ) {
V_2 -> V_169 =
V_2 -> V_206 = V_232 ;
V_2 -> V_209 = V_233 ;
} else {
V_2 -> V_169 =
V_2 -> V_206 = V_242 ;
V_2 -> V_209 = V_243 ;
}
}
break;
default:
F_72 ( 1 ) ;
}
if ( V_2 -> V_156 == V_225 )
F_125 ( V_2 ) ;
else if ( V_2 -> V_156 == V_229 )
F_126 ( V_2 ) ;
else {
F_72 ( V_2 -> V_156 != V_236 ) ;
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
}
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
}
void
F_131 ( struct V_1 * V_2 , T_6 * V_244 , T_7 V_245 )
{
V_2 -> V_149 . V_246 = V_244 ;
V_2 -> V_149 . V_150 = V_245 ;
V_2 -> V_164 = (struct V_163 * ) V_244 ;
}
void
F_132 ( struct V_1 * V_2 )
{
F_114 ( V_2 , V_247 ) ;
V_2 -> V_216 = V_79 ;
F_9 ( V_2 , V_9 ) ;
}
void
F_133 ( struct V_1 * V_2 )
{
F_114 ( V_2 , V_248 ) ;
F_9 ( V_2 , V_11 ) ;
}
void
F_134 ( struct V_1 * V_2 , void * V_249 )
{
V_2 -> V_249 = V_249 ;
V_2 -> V_250 = ( V_2 -> V_7 . V_40 ) ? V_251 : 0 ;
}
void
F_135 ( struct V_1 * V_2 , T_8 * V_252 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
int V_174 ;
for ( V_174 = 0 ; V_174 < V_176 ; V_174 ++ )
V_172 -> V_177 [ V_174 ] . V_18 = V_252 [ V_174 ] ;
}
void
F_136 ( struct V_1 * V_2 , enum V_253 V_174 ,
T_8 V_18 , void * V_100 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
V_172 -> V_177 [ V_174 ] . V_18 = V_18 ;
V_172 -> V_177 [ V_174 ] . V_100 = V_100 ;
}
void
F_137 ( struct V_1 * V_2 , struct V_178 * V_179 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
T_1 V_180 ;
if ( ! F_108 ( & V_172 -> V_175 ) ) {
F_138 ( & V_179 -> V_99 , & V_172 -> V_175 ) ;
return;
}
V_180 = F_28 ( V_2 -> V_62 . V_133 ) ;
if ( V_180 ) {
F_138 ( & V_179 -> V_99 , & V_172 -> V_175 ) ;
return;
}
F_86 ( V_2 , V_179 -> V_181 , sizeof( V_179 -> V_181 ) ) ;
}
void
F_139 ( struct V_1 * V_2 )
{
struct V_171 * V_172 = & V_2 -> V_173 ;
struct V_200 V_201 ;
int V_174 ;
if ( F_119 ( V_2 , & V_201 ) ) {
V_174 = V_201 . V_138 . V_254 ;
if ( V_174 == V_139 ) {
F_121 ( V_2 , & V_201 ) ;
return;
}
if ( ( V_174 > V_176 ) || ( V_172 -> V_177 [ V_174 ] . V_18 == NULL ) )
return;
V_172 -> V_177 [ V_174 ] . V_18 ( V_172 -> V_177 [ V_174 ] . V_100 , & V_201 ) ;
}
F_140 ( V_2 ) ;
F_96 ( V_2 ) ;
}
void
F_141 ( struct V_1 * V_2 )
{
F_114 ( V_2 , V_255 ) ;
V_2 -> V_256 . V_151 = V_2 -> V_151 ;
F_9 ( V_2 , V_17 ) ;
}
T_2
F_142 ( struct V_1 * V_2 )
{
return F_117 ( V_2 , V_26 ) ||
F_117 ( V_2 , V_46 ) ;
}
T_2
F_143 ( struct V_1 * V_2 )
{
return F_117 ( V_2 , V_6 ) ||
F_117 ( & V_2 -> V_7 , V_53 ) ||
F_117 ( & V_2 -> V_7 , V_76 ) ;
}
T_2
F_144 ( struct V_1 * V_2 )
{
T_1 V_257 ;
if ( ! F_117 ( V_2 , V_46 ) )
return V_50 ;
V_257 = F_28 ( V_2 -> V_62 . V_64 ) ;
if ( ! F_145 ( V_257 ) )
return V_50 ;
if ( V_2 -> V_219 . V_222 != V_223 ) {
V_257 = F_28 ( V_2 -> V_62 . V_72 ) ;
if ( ! F_145 ( V_257 ) )
return V_50 ;
}
return V_79 ;
}
void
F_146 ( struct V_1 * V_2 )
{
F_30 ( V_65 , V_2 -> V_62 . V_64 ) ;
F_30 ( V_65 , V_2 -> V_62 . V_72 ) ;
}
void
F_147 ( struct V_1 * V_2 ,
struct V_258 * V_259 )
{
struct V_163 * V_260 ;
V_260 = V_2 -> V_164 ;
F_148 ( V_2 , V_259 -> V_261 ) ;
F_149 ( V_2 , V_259 -> V_262 ) ;
F_150 ( V_2 , V_259 -> V_263 ) ;
F_151 ( V_2 , V_259 -> V_264 ) ;
memcpy ( & V_259 -> V_265 , & V_260 -> V_265 ,
sizeof( struct V_266 ) ) ;
V_259 -> V_267 = F_152 ( V_2 ) ;
V_259 -> V_268 = F_153 ( V_2 ) ;
F_154 ( V_2 , V_259 -> V_269 ) ;
F_154 ( V_2 , V_259 -> V_270 ) ;
V_259 -> V_166 = V_260 -> V_166 ;
V_259 -> V_271 = F_155 ( V_260 -> V_166 ) ;
if ( F_156 ( V_260 -> V_165 ) )
V_259 -> V_272 = 1 ;
else
V_259 -> V_272 = 0 ;
V_259 -> V_273 = V_2 -> V_164 -> V_273 ;
V_259 -> V_274 = F_157 ( V_2 ) ;
V_259 -> V_275 = V_260 -> V_275 ;
V_259 -> V_276 = V_260 -> V_276 ;
V_259 -> V_277 = V_260 -> V_277 ;
V_259 -> V_278 = V_260 -> V_278 ;
F_158 ( V_2 , V_259 -> V_279 ) ;
V_259 -> V_280 = F_159 ( V_2 ) ;
V_259 -> V_281 = ( V_259 -> V_267 > 1 ) &&
! F_159 ( V_2 ) && ! V_259 -> V_271 ;
}
enum V_282
F_160 ( struct V_1 * V_2 )
{
if ( V_2 -> V_141 == V_283 )
return V_284 ;
F_72 ( V_2 -> V_141 != V_237 ) ;
return ( V_2 -> V_164 -> V_169 == V_170 )
? V_285 : V_286 ;
}
void
F_148 ( struct V_1 * V_2 , char * V_261 )
{
memset ( ( void * ) V_261 , 0 , V_287 ) ;
memcpy ( ( void * ) V_261 ,
( void * ) V_2 -> V_164 -> V_288 ,
V_287 ) ;
}
void
F_149 ( struct V_1 * V_2 , char * V_262 )
{
memset ( ( void * ) V_262 , 0 , V_289 ) ;
memcpy ( V_262 , V_2 -> V_164 -> V_290 , V_289 ) ;
}
void
F_158 ( struct V_1 * V_2 , char * V_291 )
{
F_72 ( ! V_291 ) ;
memset ( ( void * ) V_291 , 0 , V_292 ) ;
V_291 [ 0 ] = 'R' ;
V_291 [ 1 ] = 'e' ;
V_291 [ 2 ] = 'v' ;
V_291 [ 3 ] = '-' ;
V_291 [ 4 ] = V_2 -> V_164 -> V_278 ;
V_291 [ 5 ] = '\0' ;
}
void
F_150 ( struct V_1 * V_2 , char * V_263 )
{
memset ( ( void * ) V_263 , 0 , V_289 ) ;
memcpy ( V_263 , V_2 -> V_164 -> V_293 ,
V_289 ) ;
}
void
F_151 ( struct V_1 * V_2 , char * V_264 )
{
memset ( ( void * ) V_264 , 0 , V_294 ) ;
memcpy ( V_264 , V_295 , V_294 ) ;
}
void
F_154 ( struct V_1 * V_2 , char * V_269 )
{
struct V_163 * V_260 ;
F_72 ( ! V_269 ) ;
memset ( ( void * ) V_269 , 0 , V_296 ) ;
V_260 = V_2 -> V_164 ;
snprintf ( V_269 , V_296 , L_6 ,
V_295 , V_260 -> V_166 ) ;
}
enum V_297
F_161 ( struct V_1 * V_2 )
{
enum V_298 V_299 ;
enum V_297 V_300 = F_162 ( V_301 , V_2 -> V_302 ) ;
if ( V_300 == V_303 ||
V_300 == V_304 || V_300 == V_305 ) {
V_299 = F_162 ( V_306 , V_2 -> V_7 . V_302 ) ;
switch ( V_299 ) {
case V_307 :
V_300 = V_308 ;
break;
case V_309 :
V_300 = V_310 ;
break;
case V_311 :
V_300 = V_312 ;
break;
case V_313 :
V_300 = V_304 ;
break;
case V_314 :
V_300 = V_305 ;
break;
default:
break;
}
}
return V_300 ;
}
void
F_163 ( struct V_1 * V_2 , struct V_315 * V_260 )
{
memset ( ( void * ) V_260 , 0 , sizeof( struct V_315 ) ) ;
V_260 -> V_316 = F_161 ( V_2 ) ;
V_260 -> V_317 = V_2 -> V_317 ;
V_260 -> V_169 = V_2 -> V_169 ;
V_260 -> V_206 = V_2 -> V_206 ;
V_260 -> V_210 = V_2 -> V_209 ;
V_260 -> V_318 = F_160 ( V_2 ) ;
F_147 ( V_2 , & V_260 -> V_319 ) ;
V_260 -> V_320 . V_222 = V_2 -> V_219 . V_222 ;
V_260 -> V_320 . V_321 = V_2 -> V_219 . V_322 ;
F_158 ( V_2 , V_260 -> V_320 . V_291 ) ;
}
T_9
F_157 ( struct V_1 * V_2 )
{
if ( F_160 ( V_2 ) == V_286 )
return V_2 -> V_164 -> V_323 ;
else
return V_2 -> V_164 -> V_274 ;
}
T_9
F_164 ( struct V_1 * V_2 )
{
T_9 V_201 ;
V_201 = V_2 -> V_164 -> V_324 ;
if ( F_165 ( V_2 -> V_164 -> V_166 ) )
V_201 . V_274 [ V_325 - 1 ] += F_166 ( V_2 ) ;
else
F_167 ( & ( V_201 . V_274 [ V_325 - 3 ] ) ,
F_166 ( V_2 ) ) ;
return V_201 ;
}
void
F_18 ( struct V_1 * V_2 , enum V_326 V_4 )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 -> V_20 -> V_33 ;
struct V_327 * V_328 ;
enum V_282 V_318 ;
F_168 ( V_33 , V_328 ) ;
if ( ! V_328 )
return;
V_318 = F_160 ( V_2 ) ;
switch ( V_318 ) {
case V_285 :
V_328 -> V_329 . V_2 . V_273 = V_2 -> V_164 -> V_273 ;
break;
case V_286 :
V_328 -> V_329 . V_2 . V_273 = V_2 -> V_164 -> V_273 ;
V_328 -> V_329 . V_2 . V_274 = F_157 ( V_2 ) ;
break;
case V_284 :
V_328 -> V_329 . V_2 . V_274 = F_157 ( V_2 ) ;
break;
default:
F_72 ( V_318 != V_285 ) ;
break;
}
V_328 -> V_329 . V_2 . V_318 = V_318 ;
F_169 ( V_328 , V_33 , ++ V_2 -> V_330 ,
V_331 , V_4 ) ;
}
T_4
F_170 ( struct V_1 * V_2 , void * V_332 , int * V_333 )
{
int V_334 ;
if ( V_2 -> V_250 == 0 )
return V_335 ;
V_334 = * V_333 ;
if ( V_334 > V_2 -> V_250 )
V_334 = V_2 -> V_250 ;
memcpy ( V_332 , V_2 -> V_249 , V_334 ) ;
* V_333 = V_334 ;
return V_34 ;
}
T_4
F_171 ( struct V_1 * V_2 , void * V_332 , int * V_333 )
{
T_1 V_60 = F_172 ( F_89 ( V_2 ) ) ;
int V_334 ;
T_4 V_336 ;
F_3 ( V_2 , * V_333 ) ;
V_334 = * V_333 ;
if ( V_334 > V_251 )
V_334 = V_251 ;
V_336 = F_110 ( V_2 , V_332 , V_60 , V_334 ) ;
* V_333 = V_334 ;
return V_336 ;
}
static void
F_173 ( struct V_1 * V_2 )
{
struct V_178 V_179 ;
struct V_134 * V_337 = (struct V_134 * ) V_179 . V_181 ;
F_88 ( V_337 -> V_138 , V_139 , V_338 ,
F_89 ( V_2 ) ) ;
V_337 -> V_141 = F_90 ( V_2 -> V_141 ) ;
F_137 ( V_2 , & V_179 ) ;
}
static void
F_174 ( struct V_1 * V_2 )
{
T_1 V_339 = 1000 ;
F_173 ( V_2 ) ;
while ( F_175 ( V_2 ) && V_339 > 0 )
V_339 -- ;
}
T_4
F_176 ( struct V_1 * V_2 , void * V_185 ,
T_1 * V_340 , int * V_341 )
{
T_1 V_60 ;
int V_342 ;
T_4 V_336 ;
T_1 V_343 = F_177 ( V_2 ) ;
if ( * V_340 >= V_343 ) {
* V_340 = * V_341 = 0 ;
return V_344 ;
}
V_60 = * V_340 ;
V_342 = * V_341 ;
if ( V_60 == 0 )
F_174 ( V_2 ) ;
if ( ( V_60 + V_342 ) >= V_343 )
V_342 = V_343 - V_60 ;
V_336 = F_110 ( V_2 , V_185 , V_60 , V_342 ) ;
if ( V_336 != V_34 ) {
* V_340 = * V_341 = 0 ;
return V_336 ;
}
* V_340 += V_342 ;
if ( * V_340 >= V_343 )
* V_340 = 0 ;
* V_341 = V_342 ;
return V_336 ;
}
T_4
F_178 ( struct V_1 * V_2 , void * V_256 )
{
T_1 V_60 = V_345 + \
V_346 * ( F_89 ( V_2 ) ) ;
int V_334 ;
T_4 V_336 ;
if ( V_2 -> V_347 ) {
F_3 ( V_2 , V_2 -> V_347 ) ;
return V_348 ;
}
V_2 -> V_347 = V_79 ;
V_334 = sizeof( struct V_349 ) ;
V_336 = F_110 ( V_2 , V_256 , V_60 , V_334 ) ;
V_2 -> V_347 = V_50 ;
return V_336 ;
}
T_4
F_179 ( struct V_1 * V_2 )
{
T_1 V_60 = V_345 + \
V_346 * ( F_89 ( V_2 ) ) ;
int V_334 ;
T_4 V_336 ;
if ( V_2 -> V_347 ) {
F_3 ( V_2 , V_2 -> V_347 ) ;
return V_348 ;
}
V_2 -> V_347 = V_79 ;
V_334 = sizeof( struct V_349 ) ;
V_336 = F_111 ( V_2 , V_60 , V_334 ) ;
V_2 -> V_347 = V_50 ;
return V_336 ;
}
static void
F_62 ( struct V_1 * V_2 )
{
int V_334 ;
if ( V_2 -> V_216 ) {
V_2 -> V_216 = V_50 ;
if ( V_2 -> V_250 ) {
V_334 = V_2 -> V_250 ;
F_171 ( V_2 , V_2 -> V_249 , & V_334 ) ;
}
}
}
static void
F_95 ( struct V_1 * V_2 )
{
F_114 ( V_2 , V_255 ) ;
V_2 -> V_256 . V_151 = V_2 -> V_151 ;
F_9 ( V_2 , V_39 ) ;
}
static void
F_180 ( void * V_127 )
{
struct V_1 * V_2 = (struct V_1 * ) V_127 ;
F_3 ( V_2 , 0 ) ;
F_9 ( & V_2 -> V_7 , V_80 ) ;
}
static void
F_181 ( void * V_127 )
{
struct V_1 * V_2 = (struct V_1 * ) V_127 ;
F_36 ( V_2 ) ;
}
static void
F_84 ( struct V_1 * V_2 )
{
T_1 V_57 = F_28 ( V_2 -> V_62 . V_64 ) ;
F_3 ( V_2 , V_57 ) ;
if ( V_57 == V_125 ) {
F_9 ( & V_2 -> V_7 , V_83 ) ;
return;
}
if ( V_2 -> V_7 . V_82 >= V_350 )
F_180 ( V_2 ) ;
else {
V_2 -> V_7 . V_82 += V_351 ;
F_182 ( V_2 ) ;
}
}
static void
F_183 ( void * V_127 )
{
struct V_1 * V_2 = (struct V_1 * ) V_127 ;
F_84 ( V_2 ) ;
}
void
F_184 ( struct V_214 * V_172 )
{
struct V_98 * V_352 = & V_172 -> V_353 ;
struct V_98 * V_99 , * V_354 ;
struct V_355 * V_356 ;
struct V_98 V_357 ;
F_107 ( & V_357 ) ;
V_99 = F_185 ( V_352 ) ;
while ( V_99 != V_352 ) {
V_354 = F_185 ( V_99 ) ;
V_356 = (struct V_355 * ) V_99 ;
if ( V_356 -> V_358 <= V_359 ) {
V_356 -> V_358 = 0 ;
F_186 ( & V_356 -> V_99 ) ;
F_138 ( & V_356 -> V_99 , & V_357 ) ;
} else {
V_356 -> V_358 -= V_359 ;
}
V_99 = V_354 ;
}
while ( ! F_108 ( & V_357 ) ) {
F_109 ( & V_357 , & V_356 ) ;
V_356 -> V_360 ( V_356 -> V_361 ) ;
}
}
void
F_187 ( struct V_214 * V_172 , struct V_355 * V_362 ,
void (* V_360) ( void * ) , void * V_361 , unsigned int V_358 )
{
F_72 ( V_360 == NULL ) ;
F_72 ( F_188 ( & V_172 -> V_353 , V_362 ) ) ;
V_362 -> V_358 = V_358 ;
V_362 -> V_360 = V_360 ;
V_362 -> V_361 = V_361 ;
F_138 ( & V_362 -> V_99 , & V_172 -> V_353 ) ;
}
void
F_189 ( struct V_355 * V_362 )
{
F_72 ( F_108 ( & V_362 -> V_99 ) ) ;
F_186 ( & V_362 -> V_99 ) ;
}
static void
F_190 ( struct V_363 * V_364 )
{
struct V_365 * V_366 ;
int V_61 , V_367 ;
T_10 V_368 ;
T_1 V_369 ;
for ( V_61 = 0 ; V_61 < V_370 ; V_61 ++ ) {
V_366 = & V_364 -> V_371 [ V_61 ] ;
for ( V_367 = 0 ; V_367 < V_372 ; V_367 ++ ) {
V_368 = V_366 -> V_373 [ V_367 ] . V_374 ;
V_366 -> V_373 [ V_367 ] . V_374 = F_105 ( V_368 ) ;
V_368 = V_366 -> V_373 [ V_367 ] . V_375 ;
V_366 -> V_373 [ V_367 ] . V_375 = F_105 ( V_368 ) ;
V_368 = V_366 -> V_373 [ V_367 ] . V_376 ;
V_366 -> V_373 [ V_367 ] . V_376 = F_105 ( V_368 ) ;
V_369 = V_366 -> V_373 [ V_367 ] . V_377 ;
V_366 -> V_373 [ V_367 ] . V_377 = F_105 ( V_369 ) ;
}
}
}
static void
F_191 ( void * V_100 , struct V_200 * V_181 )
{
struct V_378 * V_379 = (struct V_378 * ) V_100 ;
struct V_380 * V_381 = (struct V_380 * ) V_181 ;
T_11 V_18 ;
F_72 ( V_181 -> V_138 . V_254 != V_382 ) ;
F_3 ( V_379 -> V_2 , V_181 -> V_138 . V_203 ) ;
switch ( V_181 -> V_138 . V_203 ) {
case V_383 :
if ( V_381 -> V_336 == V_34 ) {
memcpy ( V_379 -> V_364 , V_379 -> V_384 . V_246 ,
sizeof( struct V_363 ) ) ;
F_190 ( V_379 -> V_364 ) ;
V_379 -> V_364 = NULL ;
}
break;
case V_385 :
case V_386 :
V_379 -> V_2 -> V_206 = V_381 -> V_169 ;
case V_387 :
case V_388 :
case V_389 :
case V_390 :
break;
case V_391 :
* ( V_379 -> V_321 ) = V_381 -> V_321 ;
V_379 -> V_321 = NULL ;
break;
default:
F_72 ( 1 ) ;
}
V_379 -> V_392 = V_50 ;
if ( V_379 -> V_18 ) {
V_18 = V_379 -> V_18 ;
V_379 -> V_18 = NULL ;
V_18 ( V_379 -> V_100 , V_381 -> V_336 ) ;
}
}
static void
F_192 ( void * V_100 , enum V_95 V_4 )
{
struct V_378 * V_379 = (struct V_378 * ) V_100 ;
F_3 ( V_379 -> V_2 , V_4 ) ;
switch ( V_4 ) {
case V_35 :
F_72 ( V_379 -> V_392 != V_50 ) ;
break;
case V_101 :
case V_188 :
V_379 -> V_321 = NULL ;
if ( V_379 -> V_392 ) {
if ( V_379 -> V_18 )
V_379 -> V_18 ( V_379 -> V_100 , V_186 ) ;
V_379 -> V_18 = NULL ;
V_379 -> V_392 = V_50 ;
}
break;
default:
F_72 ( 1 ) ;
break;
}
}
T_1
F_193 ( void )
{
return F_194 ( sizeof( struct V_363 ) , V_393 ) ;
}
void
F_195 ( struct V_378 * V_379 , T_6 * V_394 , T_7 V_395 )
{
V_379 -> V_384 . V_246 = V_394 ;
V_379 -> V_384 . V_150 = V_395 ;
}
void
F_196 ( struct V_378 * V_379 , struct V_1 * V_2 )
{
V_379 -> V_2 = V_2 ;
F_136 ( V_379 -> V_2 , V_382 , F_191 , V_379 ) ;
F_197 ( & V_379 -> V_396 ) ;
F_198 ( & V_379 -> V_396 , F_192 , V_379 ) ;
F_138 ( & V_379 -> V_396 . V_99 , & V_379 -> V_2 -> V_217 ) ;
}
T_4
F_199 ( struct V_378 * V_379 , struct V_363 * V_397 ,
T_11 V_18 , void * V_100 )
{
struct V_398 * V_201 ;
F_72 ( ! V_397 ) ;
if ( ! F_116 ( V_379 -> V_2 ) ) {
F_3 ( V_379 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_379 -> V_392 ) {
F_3 ( V_379 -> V_2 , V_348 ) ;
return V_348 ;
}
V_379 -> V_364 = V_397 ;
V_379 -> V_18 = V_18 ;
V_379 -> V_100 = V_100 ;
V_379 -> V_392 = V_79 ;
V_201 = (struct V_398 * ) V_379 -> V_399 . V_181 ;
F_88 ( V_201 -> V_138 , V_382 , V_400 ,
F_89 ( V_379 -> V_2 ) ) ;
F_93 ( V_201 -> V_401 , V_379 -> V_384 . V_150 ) ;
F_137 ( V_379 -> V_2 , & V_379 -> V_399 ) ;
return V_34 ;
}
T_4
F_200 ( struct V_378 * V_379 , T_10 * V_321 ,
T_6 V_402 , enum V_220 V_403 , int V_377 ,
T_11 V_18 , void * V_100 )
{
struct V_404 * V_201 ;
if ( ! F_116 ( V_379 -> V_2 ) ) {
F_3 ( V_379 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_379 -> V_392 ) {
F_3 ( V_379 -> V_2 , V_348 ) ;
return V_348 ;
}
V_379 -> V_321 = V_321 ;
V_379 -> V_18 = V_18 ;
V_379 -> V_100 = V_100 ;
V_379 -> V_392 = V_79 ;
V_201 = (struct V_404 * ) V_379 -> V_399 . V_181 ;
F_88 ( V_201 -> V_138 , V_382 , V_405 ,
F_89 ( V_379 -> V_2 ) ) ;
V_201 -> V_374 = F_90 ( ( T_10 ) V_403 ) ;
V_201 -> V_377 = F_120 ( V_377 ) ;
V_201 -> V_402 = V_402 ;
F_137 ( V_379 -> V_2 , & V_379 -> V_399 ) ;
return V_34 ;
}
T_4
F_201 ( struct V_378 * V_379 , int V_321 ,
T_11 V_18 , void * V_100 )
{
struct V_404 * V_201 ;
if ( ! F_116 ( V_379 -> V_2 ) ) {
F_3 ( V_379 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_379 -> V_392 ) {
F_3 ( V_379 -> V_2 , V_348 ) ;
return V_348 ;
}
V_379 -> V_18 = V_18 ;
V_379 -> V_100 = V_100 ;
V_379 -> V_392 = V_79 ;
V_201 = (struct V_404 * ) V_379 -> V_399 . V_181 ;
F_88 ( V_201 -> V_138 , V_382 , V_406 ,
F_89 ( V_379 -> V_2 ) ) ;
V_201 -> V_321 = ( T_6 ) V_321 ;
F_137 ( V_379 -> V_2 , & V_379 -> V_399 ) ;
return V_34 ;
}
T_4
F_202 ( struct V_378 * V_379 , enum V_207 V_407 ,
int V_408 , int V_409 , T_11 V_18 , void * V_100 )
{
struct V_410 * V_201 ;
if ( ! F_116 ( V_379 -> V_2 ) ) {
F_3 ( V_379 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_379 -> V_392 ) {
F_3 ( V_379 -> V_2 , V_348 ) ;
return V_348 ;
}
V_379 -> V_18 = V_18 ;
V_379 -> V_100 = V_100 ;
V_379 -> V_392 = V_79 ;
V_201 = (struct V_410 * ) V_379 -> V_399 . V_181 ;
F_88 ( V_201 -> V_138 , V_382 , V_411 ,
F_89 ( V_379 -> V_2 ) ) ;
V_201 -> V_407 = ( T_6 ) V_407 ;
V_201 -> V_408 = ( T_6 ) V_408 ;
V_201 -> V_409 = ( T_6 ) V_409 ;
F_137 ( V_379 -> V_2 , & V_379 -> V_399 ) ;
return V_34 ;
}
T_4
F_203 ( struct V_378 * V_379 , int V_402 , enum V_207 V_407 ,
int V_408 , int V_409 , T_11 V_18 , void * V_100 )
{
struct V_410 * V_201 ;
if ( ! F_116 ( V_379 -> V_2 ) ) {
F_3 ( V_379 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_379 -> V_392 ) {
F_3 ( V_379 -> V_2 , V_348 ) ;
return V_348 ;
}
V_379 -> V_18 = V_18 ;
V_379 -> V_100 = V_100 ;
V_379 -> V_392 = V_79 ;
V_201 = (struct V_410 * ) V_379 -> V_399 . V_181 ;
F_88 ( V_201 -> V_138 , V_382 , V_412 ,
F_89 ( V_379 -> V_2 ) ) ;
V_201 -> V_402 = ( T_6 ) V_402 ;
V_201 -> V_407 = ( T_6 ) V_407 ;
V_201 -> V_408 = ( T_6 ) V_408 ;
V_201 -> V_409 = ( T_6 ) V_409 ;
F_137 ( V_379 -> V_2 , & V_379 -> V_399 ) ;
return V_34 ;
}
T_4
F_204 ( struct V_378 * V_379 , int V_321 , int V_377 ,
T_11 V_18 , void * V_100 )
{
struct V_404 * V_201 ;
if ( ! F_116 ( V_379 -> V_2 ) ) {
F_3 ( V_379 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_379 -> V_392 ) {
F_3 ( V_379 -> V_2 , V_348 ) ;
return V_348 ;
}
V_379 -> V_18 = V_18 ;
V_379 -> V_100 = V_100 ;
V_379 -> V_392 = V_79 ;
V_201 = (struct V_404 * ) V_379 -> V_399 . V_181 ;
F_88 ( V_201 -> V_138 , V_382 , V_413 ,
F_89 ( V_379 -> V_2 ) ) ;
V_201 -> V_321 = ( T_6 ) V_321 ;
V_201 -> V_377 = F_120 ( V_377 ) ;
F_137 ( V_379 -> V_2 , & V_379 -> V_399 ) ;
return V_34 ;
}
T_4
F_205 ( struct V_378 * V_379 , T_11 V_18 , void * V_100 )
{
struct V_414 * V_201 ;
if ( ! F_116 ( V_379 -> V_2 ) ) {
F_3 ( V_379 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_379 -> V_392 ) {
F_3 ( V_379 -> V_2 , V_348 ) ;
return V_348 ;
}
V_379 -> V_18 = V_18 ;
V_379 -> V_100 = V_100 ;
V_379 -> V_392 = V_79 ;
V_201 = (struct V_414 * ) V_379 -> V_399 . V_181 ;
F_88 ( V_201 -> V_138 , V_382 , V_415 ,
F_89 ( V_379 -> V_2 ) ) ;
F_137 ( V_379 -> V_2 , & V_379 -> V_399 ) ;
return V_34 ;
}
T_4
F_206 ( struct V_378 * V_379 , T_11 V_18 , void * V_100 )
{
struct V_414 * V_201 ;
if ( ! F_116 ( V_379 -> V_2 ) ) {
F_3 ( V_379 -> V_2 , V_21 ) ;
return V_21 ;
}
if ( V_379 -> V_392 ) {
F_3 ( V_379 -> V_2 , V_348 ) ;
return V_348 ;
}
V_379 -> V_18 = V_18 ;
V_379 -> V_100 = V_100 ;
V_379 -> V_392 = V_79 ;
V_201 = (struct V_414 * ) V_379 -> V_399 . V_181 ;
F_88 ( V_201 -> V_138 , V_382 , V_416 ,
F_89 ( V_379 -> V_2 ) ) ;
F_137 ( V_379 -> V_2 , & V_379 -> V_399 ) ;
return V_34 ;
}
static void
F_207 ( struct V_417 * V_418 )
{
F_3 ( V_418 , V_418 -> V_419 ) ;
if ( V_418 -> V_18 )
V_418 -> V_18 ( V_418 -> V_100 , V_418 -> V_336 ) ;
V_418 -> V_419 = 0 ;
V_418 -> V_18 = NULL ;
}
static void
F_208 ( struct V_417 * V_418 )
{
F_3 ( V_418 , V_418 -> V_420 ) ;
if ( V_418 -> V_421 ) {
F_209 ( V_418 ) ;
if ( V_418 -> V_422 )
V_418 -> V_422 ( V_418 -> V_423 ,
V_418 -> V_336 ) ;
V_418 -> V_421 = NULL ;
}
if ( V_418 -> V_420 ) {
V_418 -> V_336 = F_210 ( V_418 , V_418 -> V_420 ) ;
if ( V_418 -> V_422 )
V_418 -> V_422 ( V_418 -> V_423 ,
V_418 -> V_336 ) ;
V_418 -> V_420 = V_424 ;
}
V_418 -> V_425 = 0 ;
V_418 -> V_422 = NULL ;
}
static void
F_211 ( void * V_426 , enum V_95 V_4 )
{
struct V_417 * V_418 = V_426 ;
F_3 ( V_418 , V_4 ) ;
F_3 ( V_418 , V_418 -> V_419 ) ;
F_3 ( V_418 , V_418 -> V_425 ) ;
switch ( V_4 ) {
case V_101 :
case V_188 :
if ( V_418 -> V_419 ) {
V_418 -> V_336 = V_21 ;
F_207 ( V_418 ) ;
}
if ( V_418 -> V_425 ) {
V_418 -> V_336 = V_21 ;
F_208 ( V_418 ) ;
}
break;
default:
break;
}
}
static void
F_212 ( struct V_417 * V_418 , struct V_427 * V_381 )
{
struct V_32 * V_33 = (struct V_32 * ) V_418 -> V_2 -> V_20 -> V_33 ;
struct V_327 * V_328 ;
enum V_428 V_429 = 0 ;
F_3 ( V_418 , ( ( ( T_7 ) V_381 -> V_430 ) << 16 ) | ( ( ( T_7 ) V_381 -> V_431 ) << 8 ) |
( ( T_7 ) V_381 -> V_4 ) ) ;
F_168 ( V_33 , V_328 ) ;
if ( ! V_328 )
return;
V_328 -> V_329 . V_402 . V_318 = F_160 ( V_418 -> V_2 ) ;
V_328 -> V_329 . V_402 . V_273 = V_418 -> V_2 -> V_164 -> V_273 ;
V_328 -> V_329 . V_402 . V_274 = F_157 ( V_418 -> V_2 ) ;
switch ( V_381 -> V_4 ) {
case V_432 :
V_429 = V_433 ;
break;
case V_434 :
V_429 = V_435 ;
break;
case V_436 :
V_429 = V_437 ;
break;
case V_438 :
V_429 = V_439 ;
break;
case V_440 :
V_429 = V_441 ;
V_328 -> V_329 . V_402 . V_442 = V_381 -> V_430 ;
break;
default:
F_3 ( V_418 , V_381 -> V_4 ) ;
F_72 ( 1 ) ;
}
F_169 ( V_328 , V_33 , ++ V_418 -> V_2 -> V_330 ,
V_443 , V_429 ) ;
}
static void
F_213 ( struct V_417 * V_418 )
{
struct V_444 * V_337 = (struct V_444 * ) V_418 -> V_445 . V_181 ;
F_3 ( V_418 , V_337 -> V_446 ) ;
F_88 ( V_337 -> V_138 , V_447 , V_448 ,
F_89 ( V_418 -> V_2 ) ) ;
F_137 ( V_418 -> V_2 , & V_418 -> V_445 ) ;
}
static void
F_214 ( struct V_417 * V_418 , enum V_449 V_446 )
{
struct V_444 * V_337 = (struct V_444 * ) V_418 -> V_445 . V_181 ;
F_72 ( V_418 -> V_419 != 0 ) ;
F_3 ( V_418 , V_418 -> V_316 ) ;
V_418 -> V_419 = 1 ;
V_418 -> V_446 = V_446 ;
V_337 -> V_446 = V_446 ;
F_215 ( & V_337 -> V_450 , sizeof( struct V_451 ) , V_418 -> V_452 ) ;
F_213 ( V_418 ) ;
}
static void
F_216 ( struct V_417 * V_418 , struct V_200 * V_181 )
{
struct V_427 * V_381 = (struct V_427 * ) V_181 ;
switch ( V_381 -> V_4 ) {
case V_432 :
V_418 -> V_316 = V_453 ;
V_418 -> V_454 = 0 ;
F_212 ( V_418 , V_381 ) ;
break;
case V_434 :
V_418 -> V_316 = V_455 ;
V_418 -> V_454 = 0 ;
F_212 ( V_418 , V_381 ) ;
break;
case V_436 :
V_418 -> V_316 = V_456 ;
V_418 -> V_454 = 0 ;
F_212 ( V_418 , V_381 ) ;
break;
case V_438 :
V_418 -> V_316 = V_457 ;
F_212 ( V_418 , V_381 ) ;
if ( ! V_418 -> V_419 )
F_214 ( V_418 , V_458 ) ;
break;
case V_440 :
F_212 ( V_418 , V_381 ) ;
break;
case V_459 :
V_418 -> V_316 = V_460 ;
if ( ! V_418 -> V_419 )
F_214 ( V_418 , V_458 ) ;
break;
default:
F_3 ( V_418 , V_381 -> V_4 ) ;
F_72 ( 1 ) ;
}
}
static void
F_217 ( struct V_417 * V_418 , struct V_200 * V_181 )
{
struct V_461 * V_381 = (struct V_461 * ) V_181 ;
if ( ! V_418 -> V_419 ) {
F_3 ( V_418 , V_418 -> V_419 ) ;
return;
}
F_3 ( V_418 , V_381 -> V_336 ) ;
if ( V_381 -> V_336 == V_34 ) {
V_418 -> V_454 = 1 ;
if ( V_418 -> V_316 == V_460 )
V_418 -> V_336 = V_34 ;
else if ( V_418 -> V_316 == V_457 )
V_418 -> V_336 = V_462 ;
else
F_3 ( V_418 , V_418 -> V_316 ) ;
} else {
V_418 -> V_454 = 0 ;
V_418 -> V_336 = V_381 -> V_336 ;
}
F_3 ( V_418 , V_418 -> V_446 ) ;
if ( V_418 -> V_446 == V_463 ) {
F_3 ( V_418 , V_418 -> V_454 ) ;
if ( V_418 -> V_454 ) {
T_1 V_464 = sizeof( struct V_451 ) ;
T_6 * V_465 = ( T_6 * ) & ( V_418 -> V_466 -> V_467 ) ;
memcpy ( V_465 , V_418 -> V_468 , V_464 ) ;
}
F_207 ( V_418 ) ;
} else
V_418 -> V_419 = 0 ;
F_3 ( V_418 , V_418 -> V_425 ) ;
if ( V_418 -> V_425 ) {
V_418 -> V_316 = V_381 -> V_316 ;
F_208 ( V_418 ) ;
}
}
static void
F_218 ( struct V_417 * V_418 )
{
struct V_444 * V_337 = (struct V_444 * ) V_418 -> V_445 . V_181 ;
F_72 ( V_418 -> V_316 != V_469 ) ;
F_72 ( V_418 -> V_425 != 0 ) ;
F_3 ( V_418 , V_418 -> V_316 ) ;
V_418 -> V_425 = 1 ;
V_337 -> V_446 = 0 ;
if ( ! V_418 -> V_419 )
F_214 ( V_418 , V_458 ) ;
}
static void
F_209 ( struct V_417 * V_418 )
{
enum V_470 * V_421 = V_418 -> V_421 ;
* V_421 = V_471 ;
if ( V_418 -> V_316 == V_457 )
* V_421 = V_472 ;
else if ( V_418 -> V_316 == V_460 ) {
union V_473 V_474 ;
struct V_451 * V_466 = (struct V_451 * ) V_418 -> V_468 ;
T_10 V_475 = ( V_466 -> V_467 . V_476 [ 4 ] & 0x3 ) << 7 |
( V_466 -> V_467 . V_476 [ 5 ] >> 1 ) ;
V_474 . V_477 = V_466 -> V_467 . V_476 [ 0 ] ;
F_3 ( V_418 , V_474 . V_477 ) ;
F_3 ( V_418 , V_475 ) ;
if ( ( V_475 & V_478 ) ||
( V_475 & V_479 ) ||
( V_475 & V_480 ) )
* V_421 = V_481 ;
else if ( ( V_475 & V_482 ) ||
( V_475 & V_483 ) )
* V_421 = V_484 ;
else if ( ( V_475 & V_485 ) ||
( V_475 & V_486 ) )
* V_421 = V_487 ;
else if ( ( V_475 & V_488 ) ||
( V_475 & V_489 ) ||
( V_475 & V_490 ) )
* V_421 = V_491 ;
else if ( V_474 . V_492 . V_493 )
* V_421 = V_491 ;
else if ( V_474 . V_492 . V_494 && V_474 . V_492 . V_495 )
* V_421 = V_487 ;
else if ( V_474 . V_492 . V_496 )
* V_421 = V_471 ;
else
F_3 ( V_418 , 0 ) ;
} else
F_3 ( V_418 , V_418 -> V_316 ) ;
}
static T_4
F_210 ( struct V_417 * V_418 , enum V_497 V_420 )
{
struct V_451 * V_466 = (struct V_451 * ) V_418 -> V_468 ;
struct V_498 * V_476 = (struct V_498 * ) V_466 -> V_467 . V_476 ;
union V_499 V_500 = V_476 -> V_500 ;
union V_473 V_474 = V_476 -> V_474 ;
if ( V_420 == V_501 ) {
if ( V_474 . V_492 . V_493 || V_474 . V_492 . V_495 )
return V_34 ;
else {
F_3 ( V_418 , V_474 . V_477 ) ;
return V_502 ;
}
}
if ( ( ( V_420 & V_503 ) && V_500 . V_492 . V_504 ) ||
( ( V_420 & V_505 ) && V_500 . V_492 . V_506 ) ||
( ( V_420 & V_507 ) && V_500 . V_492 . V_508 ) ||
( ( V_420 & V_509 ) && V_500 . V_492 . V_510 ) ||
( ( V_420 & V_511 ) && V_500 . V_492 . V_512 ) )
return V_34 ;
else {
F_3 ( V_418 , V_420 ) ;
F_3 ( V_418 , V_500 . V_477 ) ;
F_3 ( V_418 , V_474 . V_477 ) ;
return V_502 ;
}
}
void
F_219 ( void * V_513 , struct V_200 * V_181 )
{
struct V_417 * V_418 = V_513 ;
switch ( V_181 -> V_138 . V_203 ) {
case V_514 :
F_217 ( V_418 , V_181 ) ;
break;
case V_515 :
F_216 ( V_418 , V_181 ) ;
break;
default:
F_3 ( V_418 , V_181 -> V_138 . V_203 ) ;
F_72 ( 1 ) ;
}
}
T_1
F_220 ( void )
{
return F_194 ( sizeof( struct V_451 ) , V_393 ) ;
}
void
F_221 ( struct V_417 * V_418 , struct V_1 * V_2 , void * V_516 ,
struct V_517 * V_518 )
{
V_418 -> V_516 = V_516 ;
V_418 -> V_2 = V_2 ;
V_418 -> V_518 = V_518 ;
V_418 -> V_18 = NULL ;
V_418 -> V_100 = NULL ;
V_418 -> V_466 = NULL ;
V_418 -> V_419 = 0 ;
V_418 -> V_454 = 0 ;
V_418 -> V_316 = V_469 ;
V_418 -> V_425 = 0 ;
V_418 -> V_422 = NULL ;
V_418 -> V_423 = NULL ;
V_418 -> V_421 = NULL ;
V_418 -> V_420 = V_424 ;
V_418 -> V_519 = V_50 ;
F_136 ( V_418 -> V_2 , V_447 , F_219 , V_418 ) ;
F_197 ( & V_418 -> V_396 ) ;
F_198 ( & V_418 -> V_396 , F_211 , V_418 ) ;
F_138 ( & V_418 -> V_396 . V_99 , & V_418 -> V_2 -> V_217 ) ;
}
void
F_222 ( struct V_417 * V_418 , T_6 * V_244 , T_7 V_245 )
{
V_418 -> V_468 = V_244 ;
V_418 -> V_452 = V_245 ;
memset ( V_418 -> V_468 , 0 , sizeof( struct V_451 ) ) ;
V_244 += F_194 ( sizeof( struct V_451 ) , V_393 ) ;
V_245 += F_194 ( sizeof( struct V_451 ) , V_393 ) ;
}
T_4
F_223 ( struct V_417 * V_418 , struct V_451 * V_466 ,
T_12 V_18 , void * V_100 )
{
if ( ! F_116 ( V_418 -> V_2 ) ) {
F_3 ( V_418 , 0 ) ;
return V_520 ;
}
if ( V_418 -> V_419 ) {
F_3 ( V_418 , 0 ) ;
return V_348 ;
}
V_418 -> V_18 = V_18 ;
V_418 -> V_100 = V_100 ;
V_418 -> V_466 = V_466 ;
F_214 ( V_418 , V_463 ) ;
return V_34 ;
}
T_4
F_224 ( struct V_417 * V_418 , enum V_470 * V_421 ,
T_12 V_18 , void * V_100 )
{
if ( ! F_116 ( V_418 -> V_2 ) ) {
F_3 ( V_418 , 0 ) ;
return V_520 ;
}
V_418 -> V_421 = V_421 ;
if ( V_418 -> V_316 == V_469 ) {
if ( V_418 -> V_425 ) {
F_3 ( V_418 , 0 ) ;
return V_348 ;
} else {
V_418 -> V_422 = V_18 ;
V_418 -> V_423 = V_100 ;
F_218 ( V_418 ) ;
return V_521 ;
}
}
F_209 ( V_418 ) ;
return V_34 ;
}
T_4
F_225 ( struct V_417 * V_418 , enum V_497 V_420 ,
T_12 V_18 , void * V_100 )
{
F_72 ( V_420 == V_424 ) ;
if ( ! F_116 ( V_418 -> V_2 ) )
return V_520 ;
if ( F_155 ( V_418 -> V_2 -> V_164 -> V_166 ) )
return V_34 ;
V_418 -> V_420 = V_420 ;
if ( V_418 -> V_316 == V_469 ) {
if ( V_418 -> V_425 ) {
F_3 ( V_418 , 0 ) ;
return V_348 ;
} else {
V_418 -> V_422 = V_18 ;
V_418 -> V_423 = V_100 ;
F_218 ( V_418 ) ;
return V_521 ;
}
}
if ( V_418 -> V_316 == V_455 ||
V_418 -> V_316 == V_456 ) {
F_3 ( V_418 , V_418 -> V_316 ) ;
return V_522 ;
}
if ( V_418 -> V_316 == V_453 ) {
F_3 ( V_418 , V_418 -> V_316 ) ;
return V_348 ;
}
if ( V_418 -> V_519 )
return V_34 ;
return F_210 ( V_418 , V_420 ) ;
}
static void
F_226 ( struct V_1 * V_2 , enum V_523 V_4 ,
int V_371 , int type )
{
struct V_32 * V_33 = (struct V_32 * ) V_2 -> V_20 -> V_33 ;
struct V_327 * V_328 ;
F_168 ( V_33 , V_328 ) ;
if ( ! V_328 )
return;
V_328 -> V_329 . V_524 . V_273 = V_2 -> V_164 -> V_273 ;
V_328 -> V_329 . V_524 . V_525 = V_371 ;
V_328 -> V_329 . V_524 . V_526 = type ;
F_169 ( V_328 , V_33 , ++ V_2 -> V_330 ,
V_527 , V_4 ) ;
}
static void
F_227 ( struct V_528 * V_529 )
{
V_529 -> V_530 = 0 ;
if ( V_529 -> V_18 )
V_529 -> V_18 ( V_529 -> V_100 , V_529 -> V_336 ) ;
}
static void
F_228 ( void * V_100 , enum V_95 V_4 )
{
struct V_528 * V_529 = V_100 ;
F_3 ( V_529 , V_4 ) ;
switch ( V_4 ) {
case V_101 :
case V_188 :
if ( V_529 -> V_530 ) {
V_529 -> V_336 = V_21 ;
V_529 -> V_18 ( V_529 -> V_100 , V_529 -> V_336 ) ;
V_529 -> V_530 = 0 ;
}
break;
default:
break;
}
}
static void
F_229 ( void * V_100 )
{
struct V_528 * V_529 = V_100 ;
struct V_531 * V_181 =
(struct V_531 * ) V_529 -> V_399 . V_181 ;
F_88 ( V_181 -> V_138 , V_532 , V_533 ,
F_89 ( V_529 -> V_2 ) ) ;
F_215 ( & V_181 -> V_450 , sizeof( struct V_534 ) ,
V_529 -> V_452 ) ;
F_137 ( V_529 -> V_2 , & V_529 -> V_399 ) ;
}
static void
F_230 ( struct V_528 * V_529 )
{
struct V_535 * V_181 =
(struct V_535 * ) V_529 -> V_399 . V_181 ;
T_1 V_129 ;
V_181 -> type = F_92 ( V_529 -> type ) ;
V_181 -> V_536 = V_529 -> V_536 ;
V_181 -> V_340 = F_92 ( V_529 -> V_537 + V_529 -> V_340 ) ;
V_129 = ( V_529 -> V_538 < V_539 ) ?
V_529 -> V_538 : V_539 ;
V_181 -> V_540 = F_92 ( V_129 ) ;
V_181 -> V_541 = ( V_129 == V_529 -> V_538 ) ? 1 : 0 ;
F_88 ( V_181 -> V_138 , V_532 , V_542 ,
F_89 ( V_529 -> V_2 ) ) ;
F_215 ( & V_181 -> V_450 , V_129 , V_529 -> V_452 ) ;
memcpy ( V_529 -> V_468 , V_529 -> V_543 + V_529 -> V_340 , V_129 ) ;
F_137 ( V_529 -> V_2 , & V_529 -> V_399 ) ;
V_529 -> V_538 -= V_129 ;
V_529 -> V_340 += V_129 ;
}
static void
F_231 ( void * V_100 )
{
struct V_528 * V_529 = V_100 ;
struct V_544 * V_181 =
(struct V_544 * ) V_529 -> V_399 . V_181 ;
T_1 V_129 ;
V_181 -> type = F_92 ( V_529 -> type ) ;
V_181 -> V_536 = V_529 -> V_536 ;
V_181 -> V_340 = F_92 ( V_529 -> V_537 + V_529 -> V_340 ) ;
V_129 = ( V_529 -> V_538 < V_539 ) ?
V_529 -> V_538 : V_539 ;
V_181 -> V_540 = F_92 ( V_129 ) ;
F_88 ( V_181 -> V_138 , V_532 , V_545 ,
F_89 ( V_529 -> V_2 ) ) ;
F_215 ( & V_181 -> V_450 , V_129 , V_529 -> V_452 ) ;
F_137 ( V_529 -> V_2 , & V_529 -> V_399 ) ;
}
static void
F_232 ( void * V_100 )
{
struct V_528 * V_529 = V_100 ;
struct V_546 * V_181 =
(struct V_546 * ) V_529 -> V_399 . V_181 ;
V_181 -> type = F_92 ( V_529 -> type ) ;
V_181 -> V_536 = V_529 -> V_536 ;
F_88 ( V_181 -> V_138 , V_532 , V_547 ,
F_89 ( V_529 -> V_2 ) ) ;
F_137 ( V_529 -> V_2 , & V_529 -> V_399 ) ;
}
static void
F_233 ( void * V_548 , struct V_200 * V_181 )
{
struct V_528 * V_529 = V_548 ;
T_1 V_336 ;
union {
struct V_549 * V_550 ;
struct V_551 * V_552 ;
struct V_553 * V_554 ;
struct V_555 * V_556 ;
struct V_557 * V_4 ;
struct V_200 * V_181 ;
} V_201 ;
V_201 . V_181 = V_181 ;
F_3 ( V_529 , V_181 -> V_138 . V_203 ) ;
if ( ! V_529 -> V_530 && V_181 -> V_138 . V_203 != V_558 ) {
F_3 ( V_529 , 0x9999 ) ;
return;
}
switch ( V_181 -> V_138 . V_203 ) {
case V_559 :
V_336 = F_92 ( V_201 . V_550 -> V_336 ) ;
F_3 ( V_529 , V_336 ) ;
if ( V_336 == V_34 ) {
T_1 V_61 ;
struct V_534 * V_164 , * V_560 ;
V_164 = (struct V_534 * ) V_529 -> V_543 ;
V_560 = (struct V_534 * ) V_529 -> V_468 ;
V_164 -> V_336 = F_92 ( V_560 -> V_336 ) ;
V_164 -> V_561 = F_92 ( V_560 -> V_561 ) ;
F_3 ( V_529 , V_164 -> V_336 ) ;
F_3 ( V_529 , V_164 -> V_561 ) ;
for ( V_61 = 0 ; V_61 < V_164 -> V_561 ; V_61 ++ ) {
V_164 -> V_562 [ V_61 ] . V_563 =
F_92 ( V_560 -> V_562 [ V_61 ] . V_563 ) ;
V_164 -> V_562 [ V_61 ] . V_564 =
F_92 ( V_560 -> V_562 [ V_61 ] . V_564 ) ;
V_164 -> V_562 [ V_61 ] . V_565 =
F_92 ( V_560 -> V_562 [ V_61 ] . V_565 ) ;
V_164 -> V_562 [ V_61 ] . V_566 =
F_92 ( V_560 -> V_562 [ V_61 ] . V_566 ) ;
V_164 -> V_562 [ V_61 ] . V_567 =
F_92 ( V_560 -> V_562 [ V_61 ] . V_567 ) ;
V_164 -> V_562 [ V_61 ] . V_568 =
F_92 ( V_560 -> V_562 [ V_61 ] . V_568 ) ;
}
}
V_529 -> V_336 = V_336 ;
F_227 ( V_529 ) ;
break;
case V_569 :
V_336 = F_92 ( V_201 . V_552 -> V_336 ) ;
F_3 ( V_529 , V_336 ) ;
V_529 -> V_336 = V_336 ;
F_227 ( V_529 ) ;
break;
case V_570 :
V_336 = F_92 ( V_201 . V_554 -> V_336 ) ;
F_3 ( V_529 , V_336 ) ;
if ( V_336 != V_34 || V_529 -> V_538 == 0 ) {
V_529 -> V_336 = V_336 ;
F_227 ( V_529 ) ;
} else {
F_3 ( V_529 , V_529 -> V_340 ) ;
F_230 ( V_529 ) ;
}
break;
case V_571 :
V_336 = F_92 ( V_201 . V_556 -> V_336 ) ;
F_3 ( V_529 , V_336 ) ;
if ( V_336 != V_34 ) {
V_529 -> V_336 = V_336 ;
F_227 ( V_529 ) ;
} else {
T_1 V_129 = F_92 ( V_201 . V_556 -> V_540 ) ;
F_3 ( V_529 , V_529 -> V_340 ) ;
F_3 ( V_529 , V_129 ) ;
memcpy ( V_529 -> V_543 + V_529 -> V_340 ,
V_529 -> V_468 , V_129 ) ;
V_529 -> V_538 -= V_129 ;
V_529 -> V_340 += V_129 ;
if ( V_529 -> V_538 == 0 ) {
V_529 -> V_336 = V_336 ;
F_227 ( V_529 ) ;
} else
F_231 ( V_529 ) ;
}
break;
case V_572 :
break;
case V_558 :
V_336 = F_92 ( V_201 . V_4 -> V_336 ) ;
F_3 ( V_529 , V_336 ) ;
if ( V_336 == V_573 )
F_18 ( V_529 -> V_2 , V_574 ) ;
else if ( V_336 == V_575 ) {
T_1 V_576 ;
V_576 = F_92 ( V_201 . V_4 -> V_576 ) ;
F_3 ( V_529 , V_576 ) ;
F_18 ( V_529 -> V_2 ,
V_577 ) ;
}
break;
default:
F_72 ( 1 ) ;
}
}
T_1
F_234 ( T_2 V_578 )
{
if ( V_578 )
return 0 ;
return F_194 ( V_539 , V_393 ) ;
}
void
F_235 ( struct V_528 * V_529 , struct V_1 * V_2 , void * V_516 ,
struct V_517 * V_518 , T_2 V_578 )
{
V_529 -> V_2 = V_2 ;
V_529 -> V_518 = V_518 ;
V_529 -> V_18 = NULL ;
V_529 -> V_100 = NULL ;
V_529 -> V_530 = 0 ;
F_136 ( V_529 -> V_2 , V_532 , F_233 , V_529 ) ;
F_197 ( & V_529 -> V_396 ) ;
F_198 ( & V_529 -> V_396 , F_228 , V_529 ) ;
F_138 ( & V_529 -> V_396 . V_99 , & V_529 -> V_2 -> V_217 ) ;
if ( V_578 ) {
V_529 -> V_468 = NULL ;
V_529 -> V_452 = 0 ;
}
}
void
F_236 ( struct V_528 * V_529 , T_6 * V_244 , T_7 V_245 ,
T_2 V_578 )
{
if ( V_578 )
return;
V_529 -> V_468 = V_244 ;
V_529 -> V_452 = V_245 ;
memset ( V_529 -> V_468 , 0 , V_539 ) ;
V_244 += F_194 ( V_539 , V_393 ) ;
V_245 += F_194 ( V_539 , V_393 ) ;
}
T_4
F_237 ( struct V_528 * V_529 , struct V_534 * V_164 ,
T_13 V_18 , void * V_100 )
{
F_3 ( V_529 , V_533 ) ;
if ( ! F_116 ( V_529 -> V_2 ) )
return V_520 ;
if ( V_529 -> V_530 ) {
F_3 ( V_529 , V_529 -> V_530 ) ;
return V_348 ;
}
V_529 -> V_530 = 1 ;
V_529 -> V_18 = V_18 ;
V_529 -> V_100 = V_100 ;
V_529 -> V_543 = ( T_6 * ) V_164 ;
F_229 ( V_529 ) ;
return V_34 ;
}
T_4
F_238 ( struct V_528 * V_529 , enum V_579 type ,
T_6 V_536 , T_13 V_18 , void * V_100 )
{
F_3 ( V_529 , V_547 ) ;
F_3 ( V_529 , type ) ;
F_3 ( V_529 , V_536 ) ;
if ( ! F_116 ( V_529 -> V_2 ) )
return V_520 ;
if ( V_529 -> V_530 ) {
F_3 ( V_529 , V_529 -> V_530 ) ;
return V_348 ;
}
V_529 -> V_530 = 1 ;
V_529 -> V_18 = V_18 ;
V_529 -> V_100 = V_100 ;
V_529 -> type = type ;
V_529 -> V_536 = V_536 ;
F_232 ( V_529 ) ;
F_226 ( V_529 -> V_2 , V_580 ,
V_536 , type ) ;
return V_34 ;
}
T_4
F_239 ( struct V_528 * V_529 , enum V_579 type ,
T_6 V_536 , void * V_185 , T_1 V_129 , T_1 V_340 ,
T_13 V_18 , void * V_100 )
{
F_3 ( V_529 , V_542 ) ;
F_3 ( V_529 , type ) ;
F_3 ( V_529 , V_536 ) ;
F_3 ( V_529 , V_129 ) ;
F_3 ( V_529 , V_340 ) ;
if ( ! F_116 ( V_529 -> V_2 ) )
return V_520 ;
if ( ! V_129 || ( V_129 & 0x03 ) || ( V_340 & 0x00003FFF ) )
return V_581 ;
if ( type == V_582 )
return V_344 ;
if ( V_529 -> V_530 ) {
F_3 ( V_529 , V_529 -> V_530 ) ;
return V_348 ;
}
V_529 -> V_530 = 1 ;
V_529 -> V_18 = V_18 ;
V_529 -> V_100 = V_100 ;
V_529 -> type = type ;
V_529 -> V_536 = V_536 ;
V_529 -> V_538 = V_129 ;
V_529 -> V_340 = 0 ;
V_529 -> V_537 = V_340 ;
V_529 -> V_543 = V_185 ;
F_230 ( V_529 ) ;
return V_34 ;
}
T_4
F_240 ( struct V_528 * V_529 , enum V_579 type ,
T_6 V_536 , void * V_185 , T_1 V_129 , T_1 V_340 ,
T_13 V_18 , void * V_100 )
{
F_3 ( V_529 , V_545 ) ;
F_3 ( V_529 , type ) ;
F_3 ( V_529 , V_536 ) ;
F_3 ( V_529 , V_129 ) ;
F_3 ( V_529 , V_340 ) ;
if ( ! F_116 ( V_529 -> V_2 ) )
return V_520 ;
if ( ! V_129 || ( V_129 & 0x03 ) || ( V_340 & 0x00003FFF ) )
return V_581 ;
if ( V_529 -> V_530 ) {
F_3 ( V_529 , V_529 -> V_530 ) ;
return V_348 ;
}
V_529 -> V_530 = 1 ;
V_529 -> V_18 = V_18 ;
V_529 -> V_100 = V_100 ;
V_529 -> type = type ;
V_529 -> V_536 = V_536 ;
V_529 -> V_538 = V_129 ;
V_529 -> V_340 = 0 ;
V_529 -> V_537 = V_340 ;
V_529 -> V_543 = V_185 ;
F_231 ( V_529 ) ;
return V_34 ;
}
static void
F_241 ( void * V_583 , enum V_95 V_4 )
{
struct V_584 * V_585 = V_583 ;
F_3 ( V_585 , V_4 ) ;
F_3 ( V_585 , V_585 -> V_586 ) ;
F_3 ( V_585 , V_585 -> V_587 . V_419 ) ;
F_3 ( V_585 , V_585 -> V_588 . V_419 ) ;
switch ( V_4 ) {
case V_101 :
case V_188 :
if ( V_585 -> V_587 . V_419 ) {
V_585 -> V_587 . V_336 = V_21 ;
V_585 -> V_587 . V_18 ( V_585 -> V_587 . V_100 ,
V_585 -> V_587 . V_336 ) ;
V_585 -> V_587 . V_419 = 0 ;
}
if ( V_585 -> V_588 . V_419 ) {
V_585 -> V_588 . V_336 = V_21 ;
V_585 -> V_588 . V_18 ( V_585 -> V_588 . V_100 ,
V_585 -> V_588 . V_336 ) ;
V_585 -> V_588 . V_419 = 0 ;
}
if ( V_585 -> V_586 ) {
if ( V_585 -> V_589 ) {
F_189 ( & V_585 -> V_362 ) ;
V_585 -> V_589 = 0 ;
}
V_585 -> V_336 = V_21 ;
V_585 -> V_18 ( V_585 -> V_100 , V_585 -> V_336 ) ;
V_585 -> V_586 = 0 ;
}
break;
default:
break;
}
}
static void
F_242 ( void * V_100 )
{
struct V_584 * V_585 = V_100 ;
struct V_1 * V_2 = V_585 -> V_2 ;
struct V_590 * V_591 = V_585 -> V_592 ;
T_1 V_60 = V_593 ;
T_1 V_58 , V_59 , V_61 ;
V_58 = F_33 ( V_2 -> V_62 . V_69 , V_60 ) ;
V_59 = F_34 ( V_60 ) ;
F_30 ( V_58 , V_2 -> V_62 . V_70 ) ;
for ( V_61 = 0 ; V_61 < ( sizeof( struct V_590 ) /
sizeof( T_1 ) ) ; V_61 ++ ) {
* ( ( T_1 * ) V_591 + V_61 ) =
F_77 ( V_2 -> V_62 . V_71 , V_60 ) ;
V_60 += sizeof( T_1 ) ;
}
F_146 ( V_2 ) ;
V_591 -> V_336 = F_32 ( V_591 -> V_336 ) ;
F_3 ( V_585 , V_591 -> V_336 ) ;
if ( V_591 -> V_336 == V_594 )
V_585 -> V_336 = V_34 ;
else {
V_585 -> V_336 = V_595 ;
V_591 -> V_401 = F_32 ( V_591 -> V_401 ) ;
V_591 -> exp = F_32 ( V_591 -> exp ) ;
V_591 -> V_596 = F_32 ( V_591 -> V_596 ) ;
V_591 -> V_597 = F_32 ( V_591 -> V_597 ) ;
V_591 -> V_598 = F_32 ( V_591 -> V_598 ) ;
V_591 -> V_599 = F_32 ( V_591 -> V_599 ) ;
F_3 ( V_585 , V_591 -> V_401 ) ;
F_3 ( V_585 , V_591 -> exp ) ;
F_3 ( V_585 , V_591 -> V_596 ) ;
F_3 ( V_585 , V_591 -> V_597 ) ;
F_3 ( V_585 , V_591 -> V_598 ) ;
F_3 ( V_585 , V_591 -> V_599 ) ;
}
V_585 -> V_589 = 0 ;
V_585 -> V_18 ( V_585 -> V_100 , V_585 -> V_336 ) ;
V_585 -> V_586 = 0 ;
}
static void
F_243 ( struct V_584 * V_585 )
{
struct V_600 * V_601 ;
T_1 V_61 ;
F_3 ( V_585 , V_585 -> V_587 . V_452 ) ;
for ( V_61 = 0 ; V_61 < ( V_602 >> 2 ) ; V_61 ++ )
* ( ( T_1 * ) V_585 -> V_587 . V_468 + V_61 ) = V_585 -> V_587 . V_603 ;
V_601 = (struct V_600 * ) V_585 -> V_587 . V_445 . V_181 ;
F_215 ( & V_601 -> V_450 , V_602 ,
V_585 -> V_587 . V_452 ) ;
V_601 -> V_604 = F_120 ( V_585 -> V_587 . V_604 ) ;
V_601 -> V_603 = V_585 -> V_587 . V_603 ;
F_88 ( V_601 -> V_138 , V_605 , V_606 ,
F_89 ( V_585 -> V_2 ) ) ;
F_137 ( V_585 -> V_2 , & V_585 -> V_587 . V_445 ) ;
}
static void
F_244 ( struct V_584 * V_585 ,
struct V_607 * V_608 )
{
T_1 V_609 = V_608 -> V_603 ;
T_6 V_610 = V_608 -> V_611 ;
F_3 ( V_585 , V_609 ) ;
F_3 ( V_585 , V_610 ) ;
if ( V_610 == V_34 ) {
T_1 V_61 , V_612 ;
V_612 = ( V_585 -> V_587 . V_604 & 0x1 ) ? ~ ( V_585 -> V_587 . V_603 ) :
V_585 -> V_587 . V_603 ;
if ( V_585 -> V_587 . V_603 != V_609 ) {
F_3 ( V_585 , V_609 ) ;
V_585 -> V_587 . V_592 -> V_613 =
V_614 ;
V_585 -> V_587 . V_336 = V_614 ;
V_585 -> V_587 . V_18 ( V_585 -> V_587 . V_100 ,
V_585 -> V_587 . V_336 ) ;
V_585 -> V_587 . V_419 = 0 ;
return;
}
for ( V_61 = 0 ; V_61 < ( V_602 >> 2 ) ; V_61 ++ ) {
if ( * ( ( T_1 * ) V_585 -> V_587 . V_468 + V_61 ) != V_612 ) {
F_3 ( V_585 , V_61 ) ;
F_3 ( V_585 , V_612 ) ;
F_3 ( V_585 ,
* ( ( T_1 * ) V_585 -> V_587 . V_468 + V_61 ) ) ;
V_585 -> V_587 . V_592 -> V_613 =
V_614 ;
V_585 -> V_587 . V_336 = V_614 ;
V_585 -> V_587 . V_18 ( V_585 -> V_587 . V_100 ,
V_585 -> V_587 . V_336 ) ;
V_585 -> V_587 . V_419 = 0 ;
return;
}
}
V_585 -> V_587 . V_592 -> V_613 = V_34 ;
V_585 -> V_587 . V_336 = V_34 ;
V_585 -> V_587 . V_18 ( V_585 -> V_587 . V_100 , V_585 -> V_587 . V_336 ) ;
V_585 -> V_587 . V_419 = 0 ;
} else {
V_585 -> V_587 . V_336 = V_615 ;
V_585 -> V_587 . V_18 ( V_585 -> V_587 . V_100 , V_585 -> V_587 . V_336 ) ;
V_585 -> V_587 . V_419 = 0 ;
}
}
static void
F_245 ( struct V_584 * V_585 )
{
struct V_616 * V_181 ;
V_181 = (struct V_616 * ) V_585 -> V_588 . V_445 . V_181 ;
F_3 ( V_585 , V_181 -> V_617 ) ;
F_88 ( V_181 -> V_138 , V_605 , V_618 ,
F_89 ( V_585 -> V_2 ) ) ;
F_137 ( V_585 -> V_2 , & V_585 -> V_588 . V_445 ) ;
}
static void
F_246 ( struct V_584 * V_585 , T_14 * V_381 )
{
if ( ! V_585 -> V_588 . V_419 ) {
F_3 ( V_585 , V_585 -> V_588 . V_419 ) ;
return;
}
V_585 -> V_588 . V_617 -> V_617 = F_105 ( V_381 -> V_617 ) ;
V_585 -> V_588 . V_617 -> V_619 = V_381 -> V_619 ;
V_585 -> V_588 . V_617 -> V_620 = V_381 -> V_620 ;
V_585 -> V_588 . V_617 -> V_336 = V_34 ;
if ( V_381 -> V_620 ) {
if ( V_381 -> V_336 == V_34 ) {
V_585 -> V_588 . V_617 -> V_621 =
F_105 ( V_381 -> V_621 ) ;
} else {
F_3 ( V_585 , V_381 -> V_336 ) ;
V_585 -> V_588 . V_617 -> V_621 = 0 ;
V_585 -> V_588 . V_617 -> V_336 = V_348 ;
}
}
F_3 ( V_585 , V_381 -> V_619 ) ;
F_3 ( V_585 , V_381 -> V_617 ) ;
F_3 ( V_585 , V_381 -> V_620 ) ;
F_3 ( V_585 , V_381 -> V_621 ) ;
V_585 -> V_588 . V_18 ( V_585 -> V_588 . V_100 , V_585 -> V_588 . V_336 ) ;
V_585 -> V_588 . V_419 = 0 ;
}
static void
F_247 ( struct V_584 * V_585 , struct V_622 * V_623 )
{
struct V_624 * V_181 ;
V_181 = (struct V_624 * ) V_585 -> V_623 . V_445 . V_181 ;
F_88 ( V_181 -> V_138 , V_605 , V_625 ,
F_89 ( V_585 -> V_2 ) ) ;
if ( V_623 -> V_626 )
V_623 -> V_626 = 500 / V_623 -> V_626 ;
if ( V_623 -> V_626 == 0 )
V_623 -> V_626 = 1 ;
F_3 ( V_585 , V_623 -> V_626 ) ;
V_181 -> V_179 = ( T_6 ) V_623 -> V_179 ;
V_181 -> V_627 = ( T_6 ) V_623 -> V_627 ;
V_181 -> V_628 = F_89 ( V_585 -> V_2 ) ;
V_181 -> V_629 = V_623 -> V_629 ;
V_181 -> V_626 = F_90 ( V_623 -> V_626 ) ;
F_137 ( V_585 -> V_2 , & V_585 -> V_623 . V_445 ) ;
}
static void
F_248 ( struct V_584 * V_585 , struct V_630 * V_181 )
{
F_3 ( V_585 , V_585 -> V_623 . V_419 ) ;
V_585 -> V_623 . V_419 = V_50 ;
}
static void
F_249 ( struct V_584 * V_585 , T_2 V_631 , T_1 V_632 )
{
struct V_633 * V_181 ;
V_181 = (struct V_633 * ) V_585 -> V_631 . V_445 . V_181 ;
F_88 ( V_181 -> V_138 , V_605 , V_634 ,
F_89 ( V_585 -> V_2 ) ) ;
V_181 -> V_631 = V_631 ;
V_181 -> V_635 = F_120 ( V_632 ) ;
F_137 ( V_585 -> V_2 , & V_585 -> V_631 . V_445 ) ;
}
static void
F_250 ( struct V_584 * V_585 )
{
F_3 ( V_585 , V_585 -> V_631 . V_316 ) ;
V_585 -> V_631 . V_316 = V_50 ;
if ( V_585 -> V_636 )
V_585 -> V_636 ( V_585 -> V_516 , V_50 , V_585 -> V_631 . V_637 ) ;
}
void
F_251 ( void * V_638 , struct V_200 * V_181 )
{
struct V_584 * V_585 = V_638 ;
switch ( V_181 -> V_138 . V_203 ) {
case V_639 :
F_250 ( V_585 ) ;
break;
case V_640 :
F_244 ( V_585 , (struct V_607 * ) V_181 ) ;
break;
case V_641 :
F_246 ( V_585 , ( T_14 * ) V_181 ) ;
break;
case V_642 :
F_248 ( V_585 , (struct V_630 * ) V_181 ) ;
break;
default:
F_3 ( V_585 , V_181 -> V_138 . V_203 ) ;
F_72 ( 1 ) ;
}
}
T_4
F_252 ( struct V_584 * V_585 , struct V_643 * V_644 ,
T_1 V_645 , struct V_590 * V_592 ,
T_15 V_18 , void * V_100 )
{
T_1 V_646 ;
F_3 ( V_585 , V_645 ) ;
if ( ! F_144 ( V_585 -> V_2 ) )
return V_647 ;
if ( V_585 -> V_586 ) {
F_3 ( V_585 , V_585 -> V_586 ) ;
return V_348 ;
} else
V_585 -> V_586 = 1 ;
V_585 -> V_592 = V_592 ;
V_585 -> V_18 = V_18 ;
V_585 -> V_100 = V_100 ;
F_83 ( V_585 -> V_2 , V_195 , V_123 ) ;
V_646 = ( F_80 ( V_585 -> V_2 ) == V_236 ) ?
V_648 : V_649 ;
F_187 ( V_585 -> V_2 -> V_215 , & V_585 -> V_362 ,
F_242 , V_585 , V_646 ) ;
V_585 -> V_589 = 1 ;
return V_34 ;
}
T_4
F_253 ( struct V_584 * V_585 , T_1 V_103 , T_1 V_603 ,
struct V_650 * V_592 , T_15 V_18 ,
void * V_100 )
{
F_3 ( V_585 , V_103 ) ;
F_3 ( V_585 , V_603 ) ;
if ( ! F_116 ( V_585 -> V_2 ) )
return V_520 ;
if ( F_254 ( F_255 ( ( V_585 -> V_2 ) ) ) &&
( ( V_585 -> V_2 ) -> V_141 == V_283 ) )
return V_651 ;
if ( V_585 -> V_586 || V_585 -> V_587 . V_419 ) {
F_3 ( V_585 , V_585 -> V_586 ) ;
F_3 ( V_585 , V_585 -> V_587 . V_419 ) ;
return V_348 ;
}
V_585 -> V_587 . V_419 = 1 ;
V_585 -> V_587 . V_18 = V_18 ;
V_585 -> V_587 . V_100 = V_100 ;
V_585 -> V_587 . V_592 = V_592 ;
V_585 -> V_587 . V_603 = V_603 ;
V_585 -> V_587 . V_604 = V_103 ;
V_585 -> V_587 . V_592 -> V_603 = 0 ;
V_585 -> V_587 . V_592 -> V_336 = V_34 ;
F_243 ( V_585 ) ;
return V_34 ;
}
T_4
F_256 ( struct V_584 * V_585 ,
struct V_652 * V_592 ,
T_15 V_18 , void * V_100 )
{
if ( V_585 -> V_586 || V_585 -> V_588 . V_419 ) {
F_3 ( V_585 , V_585 -> V_586 ) ;
F_3 ( V_585 , V_585 -> V_588 . V_419 ) ;
return V_348 ;
}
if ( ! F_116 ( V_585 -> V_2 ) )
return V_520 ;
V_585 -> V_588 . V_419 = 1 ;
V_585 -> V_588 . V_617 = V_592 ;
V_585 -> V_588 . V_18 = V_18 ;
V_585 -> V_588 . V_100 = V_100 ;
F_245 ( V_585 ) ;
return V_34 ;
}
T_4
F_257 ( struct V_584 * V_585 , struct V_622 * V_623 )
{
F_3 ( V_585 , V_623 -> V_179 ) ;
if ( ! F_116 ( V_585 -> V_2 ) )
return V_520 ;
if ( V_585 -> V_631 . V_316 )
return V_653 ;
if ( V_585 -> V_623 . V_419 )
return V_654 ;
V_585 -> V_623 . V_419 = V_79 ;
F_247 ( V_585 , V_623 ) ;
return V_34 ;
}
T_4
F_258 ( struct V_584 * V_585 , T_2 V_631 ,
T_2 V_655 , T_16 V_632 )
{
F_3 ( V_585 , V_631 ) ;
F_3 ( V_585 , V_655 ) ;
F_3 ( V_585 , V_632 ) ;
if ( ! F_116 ( V_585 -> V_2 ) )
return V_520 ;
if ( V_585 -> V_623 . V_419 )
return V_654 ;
if ( V_585 -> V_631 . V_316 && V_631 )
return V_653 ;
V_585 -> V_631 . V_316 = V_631 ;
V_585 -> V_631 . V_637 = V_655 ;
if ( V_585 -> V_636 )
V_585 -> V_636 ( V_585 -> V_516 , V_631 , V_655 ) ;
F_249 ( V_585 , V_631 , V_632 ) ;
return V_34 ;
}
T_1
F_259 ( void )
{
return F_194 ( V_602 , V_393 ) ;
}
void
F_260 ( struct V_584 * V_585 , struct V_1 * V_2 , void * V_516 ,
T_17 V_636 , struct V_517 * V_518 )
{
V_585 -> V_516 = V_516 ;
V_585 -> V_2 = V_2 ;
V_585 -> V_518 = V_518 ;
V_585 -> V_586 = 0 ;
V_585 -> V_18 = NULL ;
V_585 -> V_100 = NULL ;
V_585 -> V_592 = NULL ;
V_585 -> V_636 = V_636 ;
F_136 ( V_585 -> V_2 , V_605 , F_251 , V_585 ) ;
F_197 ( & V_585 -> V_396 ) ;
F_198 ( & V_585 -> V_396 , F_241 , V_585 ) ;
F_138 ( & V_585 -> V_396 . V_99 , & V_585 -> V_2 -> V_217 ) ;
}
void
F_261 ( struct V_584 * V_585 , T_6 * V_244 , T_7 V_245 )
{
V_585 -> V_587 . V_468 = V_244 ;
V_585 -> V_587 . V_452 = V_245 ;
memset ( V_585 -> V_587 . V_468 , 0 , V_602 ) ;
}
static void
F_262 ( T_1 * V_656 , T_1 * V_657 , int V_184 )
{
int V_61 , V_201 = V_184 >> 2 ;
for ( V_61 = 0 ; V_61 < V_201 ; V_61 ++ )
V_656 [ V_61 ] = F_92 ( V_657 [ V_61 ] ) ;
}
static T_2
F_263 ( struct V_658 * V_659 )
{
return ( V_659 -> V_2 -> V_164 -> V_166 == V_660 ) ;
}
static void
F_264 ( void * V_100 , enum V_95 V_4 )
{
struct V_658 * V_659 = V_100 ;
F_3 ( V_659 , V_4 ) ;
switch ( V_4 ) {
case V_101 :
case V_188 :
if ( V_659 -> V_530 ) {
V_659 -> V_336 = V_21 ;
V_659 -> V_18 ( V_659 -> V_100 , V_659 -> V_336 ) ;
V_659 -> V_530 = 0 ;
}
break;
default:
break;
}
}
static void
F_265 ( void * V_100 )
{
struct V_658 * V_659 = V_100 ;
struct V_661 * V_181 =
(struct V_661 * ) V_659 -> V_399 . V_181 ;
V_181 -> V_536 = V_659 -> V_536 ;
F_88 ( V_181 -> V_138 , V_662 , V_663 ,
F_89 ( V_659 -> V_2 ) ) ;
F_215 ( & V_181 -> V_450 , sizeof( struct V_664 ) , V_659 -> V_452 ) ;
F_137 ( V_659 -> V_2 , & V_659 -> V_399 ) ;
}
static void
F_266 ( void * V_100 )
{
struct V_658 * V_659 = V_100 ;
struct V_665 * V_181 =
(struct V_665 * ) V_659 -> V_399 . V_181 ;
T_1 V_129 ;
T_10 * V_185 , * V_666 ;
int V_61 , V_184 ;
V_181 -> V_536 = V_659 -> V_536 ;
V_181 -> V_340 = F_120 ( V_659 -> V_537 + V_659 -> V_340 ) ;
V_129 = ( V_659 -> V_538 < V_667 ) ?
V_659 -> V_538 : V_667 ;
V_181 -> V_540 = F_120 ( V_129 ) ;
V_181 -> V_541 = ( V_129 == V_659 -> V_538 ) ? 1 : 0 ;
F_88 ( V_181 -> V_138 , V_662 , V_668 ,
F_89 ( V_659 -> V_2 ) ) ;
F_215 ( & V_181 -> V_450 , V_129 , V_659 -> V_452 ) ;
V_185 = ( T_10 * ) ( V_659 -> V_543 + V_659 -> V_340 ) ;
V_666 = ( T_10 * ) V_659 -> V_468 ;
V_184 = V_129 >> 1 ;
for ( V_61 = 0 ; V_61 < V_184 ; V_61 ++ )
V_185 [ V_61 ] = F_90 ( V_666 [ V_61 ] ) ;
F_137 ( V_659 -> V_2 , & V_659 -> V_399 ) ;
V_659 -> V_538 -= V_129 ;
V_659 -> V_340 += V_129 ;
}
static void
F_267 ( void * V_100 )
{
struct V_658 * V_659 = V_100 ;
struct V_669 * V_181 =
(struct V_669 * ) V_659 -> V_399 . V_181 ;
T_1 V_129 ;
V_181 -> V_536 = V_659 -> V_536 ;
V_181 -> V_340 = F_120 ( V_659 -> V_537 + V_659 -> V_340 ) ;
V_129 = ( V_659 -> V_538 < V_667 ) ?
V_659 -> V_538 : V_667 ;
V_181 -> V_540 = F_120 ( V_129 ) ;
F_88 ( V_181 -> V_138 , V_662 , V_670 ,
F_89 ( V_659 -> V_2 ) ) ;
F_215 ( & V_181 -> V_450 , V_129 , V_659 -> V_452 ) ;
F_137 ( V_659 -> V_2 , & V_659 -> V_399 ) ;
}
static void
F_268 ( void * V_100 )
{
struct V_658 * V_659 = V_100 ;
struct V_671 * V_181 =
(struct V_671 * ) V_659 -> V_399 . V_181 ;
V_181 -> V_536 = V_659 -> V_536 ;
F_88 ( V_181 -> V_138 , V_662 , V_672 ,
F_89 ( V_659 -> V_2 ) ) ;
F_215 ( & V_181 -> V_450 , sizeof( struct V_673 ) , V_659 -> V_452 ) ;
F_137 ( V_659 -> V_2 , & V_659 -> V_399 ) ;
}
T_1
F_269 ( T_2 V_578 )
{
if ( V_578 )
return 0 ;
return F_194 ( V_667 , V_393 ) ;
}
void
F_270 ( struct V_658 * V_659 , struct V_1 * V_2 , void * V_516 ,
struct V_517 * V_518 , T_2 V_578 )
{
V_659 -> V_2 = V_2 ;
V_659 -> V_518 = V_518 ;
V_659 -> V_18 = NULL ;
V_659 -> V_100 = NULL ;
V_659 -> V_530 = 0 ;
F_136 ( V_659 -> V_2 , V_662 , V_674 , V_659 ) ;
F_197 ( & V_659 -> V_396 ) ;
F_198 ( & V_659 -> V_396 , F_264 , V_659 ) ;
F_138 ( & V_659 -> V_396 . V_99 , & V_659 -> V_2 -> V_217 ) ;
if ( V_578 ) {
V_659 -> V_468 = NULL ;
V_659 -> V_452 = 0 ;
}
}
void
F_271 ( struct V_658 * V_659 , T_6 * V_244 , T_7 V_245 ,
T_2 V_578 )
{
if ( V_578 )
return;
V_659 -> V_468 = V_244 ;
V_659 -> V_452 = V_245 ;
memset ( V_659 -> V_468 , 0 , V_667 ) ;
V_244 += F_194 ( V_667 , V_393 ) ;
V_245 += F_194 ( V_667 , V_393 ) ;
}
T_2
F_272 ( struct V_1 * V_2 )
{
void T_3 * V_675 ;
V_675 = F_273 ( V_2 ) ;
return F_28 ( V_675 + V_676 ) ;
}
T_4
F_274 ( struct V_658 * V_659 , T_6 V_536 ,
struct V_664 * V_164 , T_18 V_18 , void * V_100 )
{
F_3 ( V_659 , V_663 ) ;
F_3 ( V_659 , V_536 ) ;
if ( ! F_263 ( V_659 ) )
return V_677 ;
if ( ! F_116 ( V_659 -> V_2 ) )
return V_520 ;
if ( V_659 -> V_530 || F_272 ( V_659 -> V_2 ) ) {
F_3 ( V_659 , V_659 -> V_530 ) ;
return V_348 ;
}
V_659 -> V_530 = 1 ;
V_659 -> V_18 = V_18 ;
V_659 -> V_100 = V_100 ;
V_659 -> V_536 = V_536 ;
V_659 -> V_543 = ( V_678 * ) V_164 ;
F_265 ( V_659 ) ;
return V_34 ;
}
T_4
F_275 ( struct V_658 * V_659 , T_6 V_536 ,
struct V_673 * V_256 ,
T_18 V_18 , void * V_100 )
{
F_3 ( V_659 , V_672 ) ;
F_3 ( V_659 , V_536 ) ;
if ( ! F_263 ( V_659 ) )
return V_677 ;
if ( ! F_116 ( V_659 -> V_2 ) )
return V_520 ;
if ( V_659 -> V_530 || F_272 ( V_659 -> V_2 ) ) {
F_3 ( V_659 , V_659 -> V_530 ) ;
return V_348 ;
}
V_659 -> V_530 = 1 ;
V_659 -> V_18 = V_18 ;
V_659 -> V_100 = V_100 ;
V_659 -> V_536 = V_536 ;
V_659 -> V_543 = ( T_6 * ) V_256 ;
F_268 ( V_659 ) ;
return V_34 ;
}
T_4
F_276 ( struct V_658 * V_659 , T_6 V_536 ,
void * V_185 , T_1 V_129 , T_1 V_340 ,
T_18 V_18 , void * V_100 )
{
F_3 ( V_659 , V_668 ) ;
F_3 ( V_659 , V_536 ) ;
F_3 ( V_659 , V_129 ) ;
F_3 ( V_659 , V_340 ) ;
if ( ! F_263 ( V_659 ) )
return V_677 ;
if ( ! F_116 ( V_659 -> V_2 ) )
return V_520 ;
if ( ! V_129 || ( V_129 & 0x03 ) )
return V_186 ;
if ( V_659 -> V_530 || F_272 ( V_659 -> V_2 ) ) {
F_3 ( V_659 , V_659 -> V_530 ) ;
return V_348 ;
}
V_659 -> V_530 = 1 ;
V_659 -> V_18 = V_18 ;
V_659 -> V_100 = V_100 ;
V_659 -> V_536 = V_536 ;
V_659 -> V_538 = V_129 ;
V_659 -> V_340 = 0 ;
V_659 -> V_537 = V_340 ;
V_659 -> V_543 = V_185 ;
F_266 ( V_659 ) ;
return V_34 ;
}
T_4
F_277 ( struct V_658 * V_659 , T_6 V_536 ,
void * V_185 , T_1 V_129 , T_1 V_340 ,
T_18 V_18 , void * V_100 )
{
F_3 ( V_659 , V_670 ) ;
F_3 ( V_659 , V_536 ) ;
F_3 ( V_659 , V_129 ) ;
F_3 ( V_659 , V_340 ) ;
if ( ! F_263 ( V_659 ) )
return V_677 ;
if ( ! F_116 ( V_659 -> V_2 ) )
return V_520 ;
if ( ! V_129 || ( V_129 & 0x03 ) )
return V_186 ;
if ( V_659 -> V_530 || F_272 ( V_659 -> V_2 ) ) {
F_3 ( V_659 , V_659 -> V_530 ) ;
return V_348 ;
}
V_659 -> V_530 = 1 ;
V_659 -> V_18 = V_18 ;
V_659 -> V_100 = V_100 ;
V_659 -> V_536 = V_536 ;
V_659 -> V_538 = V_129 ;
V_659 -> V_340 = 0 ;
V_659 -> V_537 = V_340 ;
V_659 -> V_543 = V_185 ;
F_267 ( V_659 ) ;
return V_34 ;
}
void
V_674 ( void * V_679 , struct V_200 * V_181 )
{
struct V_658 * V_659 = V_679 ;
T_1 V_336 ;
union {
struct V_680 * V_550 ;
struct V_681 * V_256 ;
struct V_682 * V_554 ;
struct V_683 * V_556 ;
struct V_200 * V_181 ;
} V_201 ;
V_201 . V_181 = V_181 ;
F_3 ( V_659 , V_181 -> V_138 . V_203 ) ;
if ( ! V_659 -> V_530 ) {
F_3 ( V_659 , 0x9999 ) ;
return;
}
switch ( V_181 -> V_138 . V_203 ) {
case V_684 :
V_336 = F_92 ( V_201 . V_550 -> V_336 ) ;
F_3 ( V_659 , V_336 ) ;
if ( V_336 == V_34 ) {
struct V_664 * V_164 =
(struct V_664 * ) V_659 -> V_543 ;
F_262 ( ( T_1 * ) V_164 , ( T_1 * ) V_659 -> V_468 ,
sizeof( struct V_664 ) ) ;
F_3 ( V_659 , V_164 -> V_336 ) ;
F_3 ( V_659 , V_164 -> V_540 ) ;
}
V_659 -> V_336 = V_336 ;
V_659 -> V_530 = 0 ;
if ( V_659 -> V_18 )
V_659 -> V_18 ( V_659 -> V_100 , V_659 -> V_336 ) ;
break;
case V_685 :
V_336 = F_92 ( V_201 . V_256 -> V_336 ) ;
F_3 ( V_659 , V_336 ) ;
if ( V_336 == V_34 ) {
struct V_673 * V_256 =
(struct V_673 * ) V_659 -> V_543 ;
F_262 ( ( T_1 * ) V_256 , ( T_1 * ) V_659 -> V_468 ,
sizeof( struct V_673 ) ) ;
F_3 ( V_659 , V_256 -> V_336 ) ;
}
V_659 -> V_336 = V_336 ;
V_659 -> V_530 = 0 ;
if ( V_659 -> V_18 )
V_659 -> V_18 ( V_659 -> V_100 , V_659 -> V_336 ) ;
break;
case V_686 :
V_336 = F_92 ( V_201 . V_554 -> V_336 ) ;
F_3 ( V_659 , V_336 ) ;
if ( V_336 != V_34 || V_659 -> V_538 == 0 ) {
V_659 -> V_336 = V_336 ;
V_659 -> V_530 = 0 ;
if ( V_659 -> V_18 )
V_659 -> V_18 ( V_659 -> V_100 , V_659 -> V_336 ) ;
} else {
F_3 ( V_659 , V_659 -> V_340 ) ;
F_266 ( V_659 ) ;
}
break;
case V_687 :
V_336 = F_92 ( V_201 . V_556 -> V_336 ) ;
F_3 ( V_659 , V_336 ) ;
if ( V_336 != V_34 ) {
V_659 -> V_336 = V_336 ;
V_659 -> V_530 = 0 ;
if ( V_659 -> V_18 )
V_659 -> V_18 ( V_659 -> V_100 , V_659 -> V_336 ) ;
} else {
T_1 V_129 = F_92 ( V_201 . V_556 -> V_540 ) ;
T_10 * V_185 = ( T_10 * ) ( V_659 -> V_543 + V_659 -> V_340 ) ;
T_10 * V_666 = ( T_10 * ) V_659 -> V_468 ;
int V_61 , V_184 = V_129 >> 1 ;
F_3 ( V_659 , V_659 -> V_340 ) ;
F_3 ( V_659 , V_129 ) ;
for ( V_61 = 0 ; V_61 < V_184 ; V_61 ++ )
V_185 [ V_61 ] = F_105 ( V_666 [ V_61 ] ) ;
V_659 -> V_538 -= V_129 ;
V_659 -> V_340 += V_129 ;
if ( V_659 -> V_538 == 0 ) {
V_659 -> V_336 = V_336 ;
V_659 -> V_530 = 0 ;
if ( V_659 -> V_18 )
V_659 -> V_18 ( V_659 -> V_100 , V_659 -> V_336 ) ;
} else
F_267 ( V_659 ) ;
}
break;
default:
F_72 ( 1 ) ;
}
}
static void
F_278 ( struct V_688 * V_689 , enum V_690 V_4 )
{
T_4 V_691 ;
F_3 ( V_689 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_692 :
if ( V_689 -> V_693 ) {
F_3 ( V_689 -> V_20 , V_689 -> V_693 ) ;
F_9 ( & V_689 -> V_20 -> V_694 ,
V_695 ) ;
return;
}
F_279 ( V_689 , V_696 ) ;
F_280 ( V_689 -> V_20 , & V_689 -> V_362 ,
V_697 , V_689 , V_698 ) ;
V_691 = F_240 ( F_281 ( V_689 -> V_20 ) ,
V_699 , V_689 -> V_536 ,
V_689 -> V_689 ,
sizeof( struct V_700 ) , 0 ,
V_701 , V_689 -> V_20 ) ;
if ( V_691 != V_34 ) {
F_189 ( & V_689 -> V_362 ) ;
V_701 ( V_689 -> V_20 , V_186 ) ;
F_279 ( V_689 , F_278 ) ;
return;
}
break;
case V_702 :
F_9 ( & V_689 -> V_20 -> V_694 , V_695 ) ;
case V_703 :
case V_704 :
case V_705 :
break;
default:
F_5 ( V_689 -> V_20 , V_4 ) ;
}
}
static void
V_696 ( struct V_688 * V_689 ,
enum V_690 V_4 )
{
F_3 ( V_689 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_705 :
F_189 ( & V_689 -> V_362 ) ;
F_279 ( V_689 , V_706 ) ;
break;
case V_707 :
F_279 ( V_689 , V_706 ) ;
F_9 ( & V_689 -> V_20 -> V_694 , V_708 ) ;
break;
case V_702 :
F_189 ( & V_689 -> V_362 ) ;
F_279 ( V_689 , F_278 ) ;
F_9 ( & V_689 -> V_20 -> V_694 , V_695 ) ;
break;
case V_703 :
F_189 ( & V_689 -> V_362 ) ;
F_279 ( V_689 , F_278 ) ;
break;
default:
F_5 ( V_689 -> V_20 , V_4 ) ;
}
}
static void
V_706 ( struct V_688 * V_689 , enum V_690 V_4 )
{
F_3 ( V_689 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_704 :
F_280 ( V_689 -> V_20 , & V_689 -> V_362 ,
V_697 , V_689 , V_698 ) ;
F_279 ( V_689 , V_709 ) ;
break;
case V_702 :
F_279 ( V_689 , F_278 ) ;
F_9 ( & V_689 -> V_20 -> V_694 , V_695 ) ;
break;
case V_692 :
case V_703 :
break;
default:
F_5 ( V_689 -> V_20 , V_4 ) ;
}
}
static void
V_709 ( struct V_688 * V_689 , enum V_690 V_4 )
{
F_3 ( V_689 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_707 :
F_279 ( V_689 , V_710 ) ;
F_282 ( V_689 ) ;
break;
case V_704 :
F_189 ( & V_689 -> V_362 ) ;
F_280 ( V_689 -> V_20 , & V_689 -> V_362 ,
V_697 , V_689 , V_698 ) ;
break;
case V_702 :
F_189 ( & V_689 -> V_362 ) ;
F_280 ( V_689 -> V_20 , & V_689 -> V_362 ,
V_697 , V_689 , V_698 ) ;
F_279 ( V_689 , V_711 ) ;
F_282 ( V_689 ) ;
break;
case V_705 :
break;
case V_703 :
F_189 ( & V_689 -> V_362 ) ;
F_279 ( V_689 , V_712 ) ;
break;
default:
F_5 ( V_689 -> V_20 , V_4 ) ;
}
}
static void
V_711 ( struct V_688 * V_689 ,
enum V_690 V_4 )
{
F_3 ( V_689 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_703 :
case V_705 :
F_189 ( & V_689 -> V_362 ) ;
case V_707 :
F_279 ( V_689 , F_278 ) ;
F_9 ( & V_689 -> V_20 -> V_694 , V_695 ) ;
break;
default:
F_5 ( V_689 -> V_20 , V_4 ) ;
}
}
static void
V_710 ( struct V_688 * V_689 , enum V_690 V_4 )
{
F_3 ( V_689 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_705 :
F_279 ( V_689 , V_706 ) ;
break;
case V_704 :
F_280 ( V_689 -> V_20 , & V_689 -> V_362 ,
V_697 , V_689 , V_698 ) ;
F_279 ( V_689 , V_709 ) ;
break;
case V_702 :
F_280 ( V_689 -> V_20 , & V_689 -> V_362 ,
V_697 , V_689 , V_698 ) ;
F_279 ( V_689 , V_711 ) ;
break;
case V_703 :
F_279 ( V_689 , V_712 ) ;
break;
default:
F_5 ( V_689 -> V_20 , V_4 ) ;
}
}
static void
V_712 ( struct V_688 * V_689 ,
enum V_690 V_4 )
{
F_3 ( V_689 -> V_20 , V_4 ) ;
switch ( V_4 ) {
case V_692 :
F_280 ( V_689 -> V_20 , & V_689 -> V_362 ,
V_697 , V_689 , V_698 ) ;
F_279 ( V_689 , V_709 ) ;
break;
case V_702 :
F_279 ( V_689 , F_278 ) ;
F_9 ( & V_689 -> V_20 -> V_694 , V_695 ) ;
break;
case V_703 :
break;
default:
F_5 ( V_689 -> V_20 , V_4 ) ;
}
}
static void
F_283 ( struct V_713 * V_364 , struct V_714 * V_715 ,
struct V_716 * V_20 )
{
struct V_717 * V_718 = F_284 ( V_20 ) ;
if ( V_364 -> V_719 . V_693 )
F_285 ( V_715 , V_718 ,
sizeof( struct V_720 ) ) ;
else
F_285 ( V_715 , V_718 ,
sizeof( struct V_700 ) ) ;
}
static void
F_286 ( struct V_716 * V_20 , void * V_33 , struct V_713 * V_364 ,
struct V_218 * V_219 )
{
struct V_688 * V_689 = F_287 ( V_20 ) ;
V_689 -> V_33 = V_33 ;
V_689 -> V_20 = V_20 ;
V_689 -> V_536 = V_20 -> V_2 . V_317 ;
F_3 ( V_20 , V_689 -> V_536 ) ;
V_689 -> V_689 = (struct V_700 * ) F_288 ( V_689 ) ;
if ( V_364 -> V_719 . V_693 ) {
F_288 ( V_689 ) += sizeof( struct V_720 ) ;
V_689 -> V_693 = V_79 ;
} else {
V_689 -> V_693 = V_50 ;
F_288 ( V_689 ) += sizeof( struct V_700 ) ;
}
F_289 ( V_20 ) = V_50 ;
F_279 ( V_689 , F_278 ) ;
}
static void
V_701 ( void * V_361 , T_4 V_336 )
{
struct V_716 * V_20 = V_361 ;
struct V_688 * V_689 = F_287 ( V_20 ) ;
F_290 ( V_689 , V_705 ) ;
if ( V_336 == V_34 ) {
F_289 ( V_20 ) = V_79 ;
if ( V_689 -> V_689 -> V_721 . V_116 != V_722 )
V_689 -> V_689 -> V_721 . V_116 = V_722 ;
if ( V_689 -> V_689 -> V_721 . V_723 != V_724 )
V_689 -> V_689 -> V_721 . V_723 = V_724 ;
}
F_9 ( & V_20 -> V_694 , V_695 ) ;
}
void
F_291 ( struct V_716 * V_20 )
{
struct V_688 * V_689 = F_287 ( V_20 ) ;
F_290 ( V_689 , V_692 ) ;
}
static void
F_292 ( struct V_716 * V_20 )
{
}
static void
F_293 ( struct V_716 * V_20 )
{
}
static void V_697 ( void * V_100 )
{
struct V_688 * V_689 = V_100 ;
F_290 ( V_689 , V_707 ) ;
}
static void
F_294 ( struct V_716 * V_20 )
{
struct V_688 * V_689 = F_287 ( V_20 ) ;
F_290 ( V_689 , V_703 ) ;
}
static void
F_295 ( struct V_716 * V_20 )
{
}
static T_4
F_282 ( struct V_688 * V_689 )
{
T_4 V_691 ;
F_3 ( V_689 -> V_20 , 0 ) ;
V_691 = F_239 ( F_281 ( V_689 -> V_20 ) ,
V_699 , V_689 -> V_536 ,
V_689 -> V_689 , sizeof( struct V_700 ) , 0 ,
V_725 , V_689 ) ;
if ( V_691 != V_34 )
F_72 ( V_691 ) ;
F_3 ( V_689 -> V_20 , V_691 ) ;
return V_691 ;
}
T_4
F_296 ( struct V_716 * V_20 )
{
struct V_688 * V_689 = F_287 ( V_20 ) ;
F_3 ( V_689 -> V_20 , 0 ) ;
if ( F_297 ( V_689 , V_712 ) )
return V_186 ;
if ( V_689 -> V_693 ) {
F_3 ( V_689 -> V_20 , V_689 -> V_693 ) ;
return V_186 ;
}
F_290 ( V_689 , V_704 ) ;
return V_34 ;
}
static void
V_725 ( void * V_361 , T_4 V_336 )
{
struct V_688 * V_689 = V_361 ;
F_72 ( V_336 ) ;
F_290 ( V_689 , V_705 ) ;
}
void
F_298 ( struct V_716 * V_20 )
{
struct V_688 * V_689 = F_287 ( V_20 ) ;
F_290 ( V_689 , V_702 ) ;
}
