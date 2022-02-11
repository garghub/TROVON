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
case V_11 :
F_4 ( V_2 , V_24 ) ;
break;
case V_12 :
F_4 ( V_2 , F_2 ) ;
F_9 ( & V_2 -> V_7 , V_25 ) ;
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
case V_26 :
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_4 ( V_2 , V_27 ) ;
break;
break;
case V_16 :
case V_17 :
F_13 ( V_2 ) ;
case V_28 :
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
F_4 ( V_2 , V_22 ) ;
if ( V_4 != V_16 )
F_9 ( & V_2 -> V_7 , V_29 ) ;
break;
case V_11 :
F_13 ( V_2 ) ;
F_4 ( V_2 , V_24 ) ;
break;
case V_9 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_15 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = (struct V_30 * ) V_2 -> V_20 -> V_31 ;
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_32 ) ;
F_16 ( V_2 ) ;
F_17 ( V_33 , V_31 , V_34 , L_1 ) ;
}
static void
V_27 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_9 :
break;
case V_11 :
F_18 ( V_2 ) ;
F_4 ( V_2 , V_24 ) ;
break;
case V_16 :
case V_17 :
F_18 ( V_2 ) ;
case V_35 :
F_19 ( V_2 ) ;
if ( V_2 -> V_7 . V_36 )
F_4 ( V_2 , V_22 ) ;
else
F_4 ( V_2 , V_37 ) ;
if ( V_4 != V_16 )
F_9 ( & V_2 -> V_7 , V_38 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_20 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = (struct V_30 * ) V_2 -> V_20 -> V_31 ;
F_9 ( & V_2 -> V_7 , V_39 ) ;
F_17 ( V_33 , V_31 , V_34 , L_2 ) ;
}
static void
V_24 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_40 :
F_4 ( V_2 , V_41 ) ;
break;
case V_17 :
F_9 ( & V_2 -> V_7 , V_38 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_21 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
static void
V_41 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_9 :
F_4 ( V_2 , V_10 ) ;
break;
case V_11 :
V_2 -> V_18 -> V_42 ( V_2 -> V_20 ) ;
break;
case V_12 :
F_4 ( V_2 , F_2 ) ;
F_9 ( & V_2 -> V_7 , V_25 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_22 ( struct V_1 * V_2 )
{
F_3 ( V_2 , 0 ) ;
}
static void
V_22 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_14 :
F_4 ( V_2 , V_15 ) ;
break;
case V_16 :
case V_17 :
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
if ( V_4 != V_16 )
F_9 ( & V_2 -> V_7 , V_23 ) ;
break;
case V_43 :
F_4 ( V_2 , V_37 ) ;
break;
case V_9 :
break;
case V_11 :
F_4 ( V_2 , V_24 ) ;
break;
case V_12 :
F_4 ( V_2 , F_2 ) ;
F_9 ( & V_2 -> V_7 , V_25 ) ;
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
V_37 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_9 :
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
break;
case V_11 :
F_4 ( V_2 , V_24 ) ;
break;
case V_12 :
F_4 ( V_2 , F_2 ) ;
F_9 ( & V_2 -> V_7 , V_25 ) ;
break;
case V_17 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_24 ( struct V_44 * V_7 )
{
V_7 -> V_45 = 0 ;
V_7 -> V_36 = V_46 ;
}
static void
V_8 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_13 :
F_4 ( V_7 , V_48 ) ;
break;
case V_25 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_25 ( struct V_44 * V_7 )
{
F_26 ( V_7 -> V_2 ) ;
}
static void
V_48 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_49 :
if ( F_27 ( V_2 ) ) {
if ( F_28 ( V_2 ) ) {
V_7 -> V_45 = 0 ;
F_29 ( V_2 ) ;
F_4 ( V_7 , V_50 ) ;
} else {
F_30 ( V_2 ) ;
F_31 ( 1 , V_2 -> V_51 . V_52 ) ;
F_32 ( V_2 ) ;
}
} else {
F_31 ( 1 , V_2 -> V_51 . V_52 ) ;
F_4 ( V_7 , V_53 ) ;
}
break;
case V_39 :
F_33 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
F_9 ( V_2 , V_40 ) ;
break;
case V_25 :
F_33 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_34 ( struct V_44 * V_7 )
{
if ( V_7 -> V_45 == 0 )
F_35 ( V_7 -> V_2 ) ;
V_7 -> V_45 ++ ;
F_36 ( V_7 -> V_2 ) ;
}
static void
V_53 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_54 :
F_4 ( V_7 , V_48 ) ;
break;
case V_39 :
F_37 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
F_9 ( V_2 , V_40 ) ;
break;
case V_25 :
F_37 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_38 ( struct V_44 * V_7 )
{
F_26 ( V_7 -> V_2 ) ;
}
static void
F_39 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_49 :
if ( F_40 ( V_2 ) ) {
F_29 ( V_2 ) ;
F_4 ( V_7 , V_50 ) ;
} else {
F_31 ( 1 , V_2 -> V_51 . V_52 ) ;
F_32 ( V_2 ) ;
}
break;
case V_39 :
F_33 ( V_2 ) ;
F_4 ( V_7 , V_55 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_41 ( struct V_44 * V_7 )
{
F_36 ( V_7 -> V_2 ) ;
F_42 ( V_7 -> V_2 , V_56 ) ;
}
static void
V_50 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_57 :
F_37 ( V_2 ) ;
F_4 ( V_7 , V_58 ) ;
break;
case V_23 :
F_37 ( V_2 ) ;
case V_54 :
F_31 ( 1 , V_2 -> V_51 . V_52 ) ;
if ( V_4 == V_54 )
F_9 ( V_2 , V_16 ) ;
F_4 ( V_7 , V_59 ) ;
break;
case V_39 :
F_37 ( V_2 ) ;
F_43 ( V_2 ) ;
F_31 ( 1 , V_2 -> V_51 . V_52 ) ;
F_4 ( V_7 , V_60 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_44 ( struct V_44 * V_7 )
{
F_36 ( V_7 -> V_2 ) ;
F_45 ( V_7 -> V_2 ) ;
}
static void
V_58 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_61 :
F_37 ( V_2 ) ;
F_31 ( 1 , V_2 -> V_51 . V_52 ) ;
F_4 ( V_7 , V_62 ) ;
break;
case V_23 :
F_37 ( V_2 ) ;
case V_54 :
F_31 ( 1 , V_2 -> V_51 . V_52 ) ;
if ( V_4 == V_54 )
F_9 ( V_2 , V_16 ) ;
F_4 ( V_7 , V_59 ) ;
break;
case V_39 :
F_37 ( V_2 ) ;
F_31 ( 1 , V_2 -> V_51 . V_52 ) ;
F_4 ( V_7 , V_63 ) ;
break;
case V_57 :
F_45 ( V_2 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_46 ( struct V_44 * V_7 )
{
F_9 ( V_7 -> V_2 , V_14 ) ;
}
static void
V_62 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_39 :
F_4 ( V_7 , V_63 ) ;
break;
case V_29 :
F_4 ( V_7 , V_59 ) ;
break;
case V_38 :
F_4 ( V_7 , V_64 ) ;
break;
case V_57 :
if ( F_47 ( V_2 ) ) {
F_9 ( V_2 , V_16 ) ;
F_4 ( V_7 , V_64 ) ;
} else {
F_9 ( V_2 , V_16 ) ;
F_4 ( V_7 , V_59 ) ;
}
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_48 ( struct V_44 * V_7 )
{
F_36 ( V_7 -> V_2 ) ;
F_49 ( V_7 -> V_2 ) ;
}
static void
V_63 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_65 :
case V_57 :
F_37 ( V_2 ) ;
F_4 ( V_7 , V_55 ) ;
break;
case V_38 :
F_37 ( V_2 ) ;
case V_54 :
F_31 ( V_66 , V_2 -> V_51 . V_67 ) ;
F_4 ( V_7 , V_55 ) ;
break;
case V_61 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_50 ( struct V_44 * V_7 )
{
F_26 ( V_7 -> V_2 ) ;
}
static void
V_55 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_49 :
F_43 ( V_2 ) ;
F_31 ( 1 , V_2 -> V_51 . V_52 ) ;
F_4 ( V_7 , V_60 ) ;
break;
case V_38 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_51 ( struct V_44 * V_7 )
{
F_9 ( V_7 -> V_2 , V_40 ) ;
}
static void
V_60 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_13 :
V_7 -> V_45 = 0 ;
F_4 ( V_7 , F_39 ) ;
break;
case V_25 :
F_30 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_52 ( struct V_44 * V_7 )
{
F_26 ( V_7 -> V_2 ) ;
}
static void
V_59 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_49 :
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
V_7 -> V_45 ++ ;
if ( V_7 -> V_45 >= V_68 ) {
F_43 ( V_2 ) ;
F_31 ( 1 , V_2 -> V_51 . V_52 ) ;
F_4 ( V_7 , V_69 ) ;
} else {
if ( F_40 ( V_2 ) )
F_4 ( V_7 , V_50 ) ;
else {
F_31 ( 1 , V_2 -> V_51 . V_52 ) ;
F_4 ( V_7 , F_39 ) ;
}
}
break;
case V_39 :
F_33 ( V_2 ) ;
F_4 ( V_7 , V_55 ) ;
break;
case V_25 :
F_33 ( V_2 ) ;
F_30 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
case V_38 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_55 ( struct V_44 * V_7 )
{
F_9 ( V_7 -> V_2 , V_43 ) ;
}
static void
V_69 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_39 :
F_4 ( V_7 , V_60 ) ;
break;
case V_25 :
F_30 ( V_2 ) ;
F_4 ( V_7 , V_8 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_56 ( struct V_44 * V_7 )
{
F_57 ( V_7 -> V_2 ) ;
F_58 ( V_7 -> V_2 ) ;
F_26 ( V_7 -> V_2 ) ;
}
static void
V_64 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_49 :
V_7 -> V_45 = 0 ;
F_54 ( V_2 ) ;
F_53 ( V_2 ) ;
if ( ! V_7 -> V_36 ) {
F_43 ( V_2 ) ;
F_31 ( 1 , V_2 -> V_51 . V_52 ) ;
F_4 ( V_7 , V_70 ) ;
} else {
if ( F_40 ( V_2 ) )
F_4 ( V_7 , V_50 ) ;
else {
F_31 ( 1 , V_2 -> V_51 . V_52 ) ;
F_4 ( V_7 , F_39 ) ;
}
}
break;
case V_39 :
F_33 ( V_2 ) ;
F_4 ( V_7 , V_55 ) ;
break;
case V_38 :
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_59 ( struct V_44 * V_7 )
{
}
static void
V_70 ( struct V_44 * V_7 , enum V_47 V_4 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_39 :
F_4 ( V_7 , V_60 ) ;
break;
default:
F_5 ( V_2 , V_4 ) ;
}
}
static void
F_7 ( struct V_1 * V_2 )
{
struct V_71 * V_72 ;
struct V_73 * V_74 ;
V_2 -> V_18 -> V_42 ( V_2 -> V_20 ) ;
F_60 (qe, &ioc->hb_notify_q) {
V_74 = (struct V_73 * ) V_72 ;
V_74 -> V_18 ( V_74 -> V_75 ) ;
}
}
T_1
F_61 ( void T_2 * V_76 )
{
T_3 V_77 ;
int V_78 = 0 ;
#define F_62 3000
V_77 = F_63 ( V_76 ) ;
while ( V_77 && ( V_78 < F_62 ) ) {
V_78 ++ ;
F_64 ( 2 ) ;
V_77 = F_63 ( V_76 ) ;
}
if ( V_77 == 0 )
return V_79 ;
F_65 ( V_78 >= F_62 ) ;
return V_56 ;
}
static void
F_26 ( struct V_1 * V_2 )
{
T_3 V_77 ;
V_77 = F_63 ( V_2 -> V_51 . V_52 ) ;
if ( V_77 == 0 ) {
F_9 ( & V_2 -> V_7 , V_49 ) ;
return;
}
F_32 ( V_2 ) ;
}
static void
F_66 ( struct V_1 * V_2 )
{
T_3 V_80 ;
int V_81 ;
#define F_67 10000
V_80 = F_63 ( V_2 -> V_51 . V_82 ) ;
V_80 &= ~ V_83 ;
V_80 |= V_84 ;
V_80 |= F_68 ( 3UL ) ;
F_31 ( V_80 , V_2 -> V_51 . V_82 ) ;
V_81 = 0 ;
do {
V_80 = F_63 ( V_2 -> V_51 . V_82 ) ;
V_81 ++ ;
} while ( ! ( V_80 & V_85 ) && ( V_81 < F_67 ) );
F_65 ( ! ( V_80 & V_85 ) ) ;
F_3 ( V_2 , V_80 ) ;
V_80 &= ~ ( V_85 | V_84 ) ;
F_31 ( V_80 , V_2 -> V_51 . V_82 ) ;
}
static void
F_69 ( struct V_1 * V_2 )
{
T_3 V_80 ;
V_80 = F_63 ( V_2 -> V_51 . V_82 ) ;
V_80 &= ~ V_86 ;
F_31 ( V_80 , V_2 -> V_51 . V_82 ) ;
}
static void
F_57 ( struct V_1 * V_2 )
{
T_3 V_80 ;
V_80 = F_63 ( V_2 -> V_51 . V_82 ) ;
V_80 |= ( V_86 | V_87 ) ;
F_31 ( V_80 , V_2 -> V_51 . V_82 ) ;
}
void
F_70 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
T_3 V_90 , V_91 ;
T_3 V_92 = 0 ;
int V_81 ;
T_3 * V_93 = ( T_3 * ) V_89 ;
V_90 = F_71 ( V_2 -> V_51 . V_94 , V_92 ) ;
V_91 = F_72 ( V_92 ) ;
F_31 ( V_90 , V_2 -> V_51 . V_95 ) ;
for ( V_81 = 0 ; V_81 < ( sizeof( struct V_88 ) / sizeof( T_3 ) ) ;
V_81 ++ ) {
V_93 [ V_81 ] =
F_73 ( V_2 -> V_51 . V_96 , V_92 ) ;
V_92 += sizeof( T_3 ) ;
}
}
T_1
F_74 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_88 * V_97 ;
int V_81 ;
V_97 = (struct V_88 * )
F_75 ( F_76 ( V_2 ) , 0 ) ;
for ( V_81 = 0 ; V_81 < V_98 ; V_81 ++ ) {
if ( V_89 -> V_99 [ V_81 ] != V_97 -> V_99 [ V_81 ] ) {
F_3 ( V_2 , V_81 ) ;
F_3 ( V_2 , V_89 -> V_99 [ V_81 ] ) ;
F_3 ( V_2 , V_97 -> V_99 [ V_81 ] ) ;
return V_56 ;
}
}
F_3 ( V_2 , V_89 -> V_99 [ 0 ] ) ;
return V_79 ;
}
static T_1
F_77 ( struct V_1 * V_2 , T_3 V_100 )
{
struct V_88 V_89 , * V_97 ;
F_70 ( V_2 , & V_89 ) ;
V_97 = (struct V_88 * )
F_75 ( F_76 ( V_2 ) , 0 ) ;
if ( V_89 . V_101 != V_97 -> V_101 ) {
F_3 ( V_2 , V_89 . V_101 ) ;
F_3 ( V_2 , V_97 -> V_101 ) ;
return V_56 ;
}
if ( F_78 ( V_89 . V_102 ) != V_100 ) {
F_3 ( V_2 , V_89 . V_102 ) ;
F_3 ( V_2 , V_100 ) ;
return V_56 ;
}
return F_74 ( V_2 , & V_89 ) ;
}
static void
F_79 ( struct V_1 * V_2 )
{
T_3 V_77 ;
V_77 = F_63 ( V_2 -> V_51 . V_103 ) ;
if ( V_77 )
F_31 ( 1 , V_2 -> V_51 . V_103 ) ;
}
static void
F_42 ( struct V_1 * V_2 , T_1 V_104 )
{
enum V_105 V_67 ;
T_1 V_106 ;
T_3 V_107 ;
T_3 V_100 ;
V_67 = F_63 ( V_2 -> V_51 . V_67 ) ;
if ( V_104 )
V_67 = V_108 ;
F_3 ( V_2 , V_67 ) ;
V_107 = V_109 ;
V_100 = V_110 ;
V_106 = ( V_67 == V_108 ) ?
V_56 : F_77 ( V_2 , V_100 ) ;
if ( ! V_106 ) {
F_80 ( V_2 , V_107 , V_100 ) ;
return;
}
if ( V_67 == V_111 ) {
V_2 -> V_18 -> V_112 ( V_2 -> V_20 ) ;
return;
}
if ( V_67 == V_113 || V_67 == V_114 ) {
F_79 ( V_2 ) ;
V_2 -> V_18 -> V_112 ( V_2 -> V_20 ) ;
F_9 ( & V_2 -> V_7 , V_57 ) ;
return;
}
F_80 ( V_2 , V_107 , V_100 ) ;
}
static void
F_81 ( void * V_115 )
{
struct V_1 * V_2 = (struct V_1 * ) V_115 ;
F_3 ( V_2 , 0 ) ;
F_9 ( V_2 , V_28 ) ;
}
void
F_82 ( struct V_1 * V_2 , void * V_116 , int V_117 )
{
T_3 * V_118 = ( T_3 * ) V_116 ;
T_3 V_81 ;
F_3 ( V_2 , V_118 [ 0 ] ) ;
F_3 ( V_2 , V_117 ) ;
F_65 ( V_117 > V_119 ) ;
for ( V_81 = 0 ; V_81 < V_117 / sizeof( T_3 ) ; V_81 ++ )
F_31 ( F_83 ( V_118 [ V_81 ] ) ,
V_2 -> V_51 . V_120 + V_81 * sizeof( T_3 ) ) ;
for (; V_81 < V_119 / sizeof( T_3 ) ; V_81 ++ )
F_31 ( 0 , V_2 -> V_51 . V_120 + V_81 * sizeof( T_3 ) ) ;
F_31 ( 1 , V_2 -> V_51 . V_121 ) ;
( void ) F_63 ( V_2 -> V_51 . V_121 ) ;
}
static void
F_45 ( struct V_1 * V_2 )
{
struct V_122 V_123 ;
struct V_124 V_125 ;
F_84 ( V_123 . V_126 , V_127 , V_128 ,
F_85 ( V_2 ) ) ;
V_123 . V_129 = V_2 -> V_130 ;
F_86 ( & V_125 ) ;
V_123 . V_131 = F_87 ( V_125 . V_131 ) ;
F_82 ( V_2 , & V_123 , sizeof( struct V_122 ) ) ;
}
static void
F_49 ( struct V_1 * V_2 )
{
struct V_122 V_132 ;
F_84 ( V_132 . V_126 , V_127 , V_133 ,
F_85 ( V_2 ) ) ;
F_82 ( V_2 , & V_132 , sizeof( struct V_122 ) ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
struct V_134 V_135 ;
F_84 ( V_135 . V_126 , V_127 , V_136 ,
F_85 ( V_2 ) ) ;
F_88 ( V_135 . V_137 , V_2 -> V_138 . V_139 ) ;
F_82 ( V_2 , & V_135 , sizeof( V_135 ) ) ;
}
static void
F_89 ( void * V_75 )
{
struct V_1 * V_2 = V_75 ;
T_3 V_140 ;
V_140 = F_63 ( V_2 -> V_51 . V_141 ) ;
if ( V_2 -> V_140 == V_140 ) {
F_90 ( V_2 ) ;
return;
} else {
V_2 -> V_140 = V_140 ;
}
F_91 ( V_2 ) ;
F_92 ( V_2 ) ;
}
static void
F_16 ( struct V_1 * V_2 )
{
V_2 -> V_140 = F_63 ( V_2 -> V_51 . V_141 ) ;
F_92 ( V_2 ) ;
}
static void
F_93 ( struct V_1 * V_2 , T_3 V_107 ,
T_3 V_100 )
{
T_3 * V_142 ;
T_3 V_90 , V_91 ;
T_3 V_92 = 0 ;
T_3 V_143 = 0 ;
T_3 V_81 ;
F_66 ( V_2 ) ;
F_3 ( V_2 , F_94 ( F_76 ( V_2 ) ) ) ;
V_142 = F_75 ( F_76 ( V_2 ) , V_143 ) ;
V_90 = F_71 ( V_2 -> V_51 . V_94 , V_92 ) ;
V_91 = F_72 ( V_92 ) ;
F_31 ( V_90 , V_2 -> V_51 . V_95 ) ;
for ( V_81 = 0 ; V_81 < F_94 ( F_76 ( V_2 ) ) ; V_81 ++ ) {
if ( F_95 ( V_81 ) != V_143 ) {
V_143 = F_95 ( V_81 ) ;
V_142 = F_75 ( F_76 ( V_2 ) ,
F_96 ( V_143 ) ) ;
}
F_97 ( V_2 -> V_51 . V_96 , V_92 ,
V_142 [ F_98 ( V_81 ) ] ) ;
V_92 += sizeof( T_3 ) ;
V_92 = F_72 ( V_92 ) ;
if ( V_92 == 0 ) {
V_90 ++ ;
F_31 ( V_90 , V_2 -> V_51 . V_95 ) ;
}
}
F_31 ( F_71 ( V_2 -> V_51 . V_94 , 0 ) ,
V_2 -> V_51 . V_95 ) ;
F_97 ( V_2 -> V_51 . V_96 , V_144 ,
F_78 ( V_107 ) ) ;
F_97 ( V_2 -> V_51 . V_96 , V_145 ,
F_78 ( V_100 ) ) ;
}
static void
F_99 ( struct V_1 * V_2 )
{
struct V_146 * V_147 = V_2 -> V_147 ;
V_147 -> V_148 = F_87 ( V_147 -> V_148 ) ;
V_147 -> V_149 = F_87 ( V_147 -> V_149 ) ;
V_147 -> V_150 = F_100 ( V_147 -> V_150 ) ;
F_9 ( V_2 , V_26 ) ;
}
static void
F_101 ( struct V_1 * V_2 )
{
struct V_151 * V_152 = & V_2 -> V_153 ;
int V_154 ;
F_102 ( & V_152 -> V_155 ) ;
for ( V_154 = 0 ; V_154 < V_156 ; V_154 ++ ) {
V_152 -> V_157 [ V_154 ] . V_18 = NULL ;
V_152 -> V_157 [ V_154 ] . V_75 = V_2 -> V_20 ;
}
}
static void
F_91 ( struct V_1 * V_2 )
{
struct V_151 * V_152 = & V_2 -> V_153 ;
struct V_158 * V_159 ;
T_3 V_160 ;
if ( F_103 ( & V_152 -> V_155 ) )
return;
V_160 = F_63 ( V_2 -> V_51 . V_121 ) ;
if ( V_160 )
return;
F_104 ( & V_152 -> V_155 , & V_159 ) ;
F_82 ( V_2 , V_159 -> V_161 , sizeof( V_159 -> V_161 ) ) ;
}
static void
F_58 ( struct V_1 * V_2 )
{
struct V_151 * V_152 = & V_2 -> V_153 ;
struct V_158 * V_159 ;
while ( ! F_103 ( & V_152 -> V_155 ) )
F_104 ( & V_152 -> V_155 , & V_159 ) ;
}
static T_4
F_105 ( struct V_1 * V_2 , void * V_162 , T_3 V_163 , T_3 V_164 )
{
T_3 V_90 , V_92 ;
T_5 V_77 ;
int V_81 , V_117 ;
T_3 * V_165 = V_162 ;
V_90 = F_71 ( V_2 -> V_51 . V_94 , V_163 ) ;
V_92 = F_72 ( V_163 ) ;
F_3 ( V_2 , V_90 ) ;
F_3 ( V_2 , V_92 ) ;
F_3 ( V_2 , V_164 ) ;
if ( V_56 == F_61 ( V_2 -> V_51 . V_166 ) ) {
F_3 ( V_2 , 0 ) ;
return V_167 ;
}
F_31 ( V_90 , V_2 -> V_51 . V_95 ) ;
V_117 = V_164 / sizeof( T_3 ) ;
F_3 ( V_2 , V_117 ) ;
for ( V_81 = 0 ; V_81 < V_117 ; V_81 ++ ) {
V_77 = F_73 ( V_2 -> V_51 . V_96 , V_92 ) ;
V_165 [ V_81 ] = F_87 ( V_77 ) ;
V_92 += sizeof( T_3 ) ;
V_92 = F_72 ( V_92 ) ;
if ( V_92 == 0 ) {
V_90 ++ ;
F_31 ( V_90 , V_2 -> V_51 . V_95 ) ;
}
}
F_31 ( F_71 ( V_2 -> V_51 . V_94 , 0 ) ,
V_2 -> V_51 . V_95 ) ;
F_31 ( 1 , V_2 -> V_51 . V_166 ) ;
F_3 ( V_2 , V_90 ) ;
return V_32 ;
}
static T_4
F_106 ( struct V_1 * V_2 , T_3 V_163 , T_3 V_164 )
{
int V_81 , V_117 ;
T_3 V_90 , V_92 ;
V_90 = F_71 ( V_2 -> V_51 . V_94 , V_163 ) ;
V_92 = F_72 ( V_163 ) ;
F_3 ( V_2 , V_90 ) ;
F_3 ( V_2 , V_92 ) ;
F_3 ( V_2 , V_164 ) ;
if ( V_56 == F_61 ( V_2 -> V_51 . V_166 ) ) {
F_3 ( V_2 , 0 ) ;
return V_167 ;
}
F_31 ( V_90 , V_2 -> V_51 . V_95 ) ;
V_117 = V_164 / sizeof( T_3 ) ;
F_3 ( V_2 , V_117 ) ;
for ( V_81 = 0 ; V_81 < V_117 ; V_81 ++ ) {
F_97 ( V_2 -> V_51 . V_96 , V_92 , 0 ) ;
V_92 += sizeof( T_3 ) ;
V_92 = F_72 ( V_92 ) ;
if ( V_92 == 0 ) {
V_90 ++ ;
F_31 ( V_90 , V_2 -> V_51 . V_95 ) ;
}
}
F_31 ( F_71 ( V_2 -> V_51 . V_94 , 0 ) ,
V_2 -> V_51 . V_95 ) ;
F_31 ( 1 , V_2 -> V_51 . V_166 ) ;
F_3 ( V_2 , V_90 ) ;
return V_32 ;
}
static void
F_19 ( struct V_1 * V_2 )
{
struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_30 * V_31 = (struct V_30 * ) V_2 -> V_20 -> V_31 ;
V_2 -> V_18 -> V_168 ( V_2 -> V_20 ) ;
F_60 (qe, &ioc->hb_notify_q) {
V_74 = (struct V_73 * ) V_72 ;
V_74 -> V_18 ( V_74 -> V_75 ) ;
}
F_107 ( V_2 ) ;
F_17 ( V_169 , V_31 , V_34 ,
L_3 ) ;
}
static void
F_35 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = (struct V_30 * ) V_2 -> V_20 -> V_31 ;
V_2 -> V_18 -> V_19 ( V_2 -> V_20 , V_21 ) ;
F_17 ( V_170 , V_31 , V_34 ,
L_4
L_5 ) ;
}
T_4
F_108 ( struct V_1 * V_2 )
{
F_61 ( V_2 -> V_51 . V_166 ) ;
F_109 ( V_2 ) ;
V_2 -> V_171 = V_79 ;
F_31 ( 1 , V_2 -> V_51 . V_166 ) ;
return V_32 ;
}
void
F_80 ( struct V_1 * V_2 , T_3 V_107 , T_3 V_100 )
{
void T_2 * V_172 ;
F_110 ( V_2 , V_173 ) ;
if ( F_108 ( V_2 ) != V_32 )
return;
V_172 = V_2 -> V_174 . V_175 ;
if ( V_107 == V_176 ) {
F_31 ( V_177 , ( V_172 + V_178 ) ) ;
F_31 ( V_177 , ( V_172 + V_179 ) ) ;
} else {
F_31 ( V_111 , ( V_172 + V_178 ) ) ;
F_31 ( V_111 , ( V_172 + V_179 ) ) ;
}
F_79 ( V_2 ) ;
F_93 ( V_2 , V_107 , V_100 ) ;
V_2 -> V_18 -> V_112 ( V_2 -> V_20 ) ;
F_69 ( V_2 ) ;
}
void
F_111 ( T_1 V_36 )
{
V_46 = V_36 ;
}
T_1
F_47 ( struct V_1 * V_2 )
{
return F_112 ( V_2 , V_27 ) ;
}
T_1
F_113 ( struct V_1 * V_2 )
{
T_3 V_77 = F_63 ( V_2 -> V_51 . V_67 ) ;
return ( ( V_77 != V_108 ) &&
( V_77 != V_111 ) &&
( V_77 != V_177 ) ) ;
}
void
F_114 ( struct V_1 * V_2 , void * V_180 )
{
T_5 * V_118 = V_180 ;
T_3 V_77 ;
int V_81 ;
for ( V_81 = 0 ; V_81 < ( sizeof( union V_181 ) / sizeof( T_3 ) ) ;
V_81 ++ ) {
V_77 = F_63 ( V_2 -> V_51 . V_182 +
V_81 * sizeof( T_3 ) ) ;
V_118 [ V_81 ] = F_115 ( V_77 ) ;
}
F_31 ( 1 , V_2 -> V_51 . V_103 ) ;
F_63 ( V_2 -> V_51 . V_103 ) ;
}
void
F_116 ( struct V_1 * V_2 , struct V_183 * V_184 )
{
union V_181 * V_161 ;
struct V_44 * V_7 = & V_2 -> V_7 ;
V_161 = (union V_181 * ) V_184 ;
F_110 ( V_2 , V_185 ) ;
switch ( V_161 -> V_126 . V_186 ) {
case V_187 :
break;
case V_188 :
F_9 ( V_7 , V_57 ) ;
break;
case V_189 :
F_9 ( V_7 , V_61 ) ;
break;
case V_190 :
F_9 ( V_7 , V_65 ) ;
break;
case V_191 :
F_99 ( V_2 ) ;
break;
default:
F_3 ( V_2 , V_161 -> V_126 . V_186 ) ;
F_65 ( 1 ) ;
}
}
void
F_117 ( struct V_1 * V_2 , void * V_20 , struct V_192 * V_18 ,
struct V_193 * V_194 )
{
V_2 -> V_20 = V_20 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_194 = V_194 ;
V_2 -> V_195 = V_56 ;
V_2 -> V_171 = V_56 ;
V_2 -> V_196 = V_79 ;
V_2 -> V_7 . V_2 = V_2 ;
F_101 ( V_2 ) ;
F_102 ( & V_2 -> V_197 ) ;
F_4 ( V_2 , F_2 ) ;
F_9 ( V_2 , V_5 ) ;
}
void
F_118 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_12 ) ;
}
void
F_119 ( struct V_1 * V_2 , struct V_198 * V_174 ,
enum V_199 V_154 )
{
V_2 -> V_130 = V_154 ;
V_2 -> V_174 = * V_174 ;
V_2 -> V_200 = F_120 ( V_2 -> V_174 . V_201 ) ;
V_2 -> V_202 = V_2 -> V_200 && ! V_2 -> V_195 ;
if ( V_2 -> V_200 )
F_121 ( V_2 ) ;
else
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_124 ( V_2 ) ;
}
void
F_125 ( struct V_1 * V_2 , T_6 * V_203 , T_7 V_204 )
{
V_2 -> V_138 . V_205 = V_203 ;
V_2 -> V_138 . V_139 = V_204 ;
V_2 -> V_147 = (struct V_146 * ) V_203 ;
}
void
F_126 ( struct V_1 * V_2 )
{
F_110 ( V_2 , V_206 ) ;
V_2 -> V_196 = V_79 ;
F_9 ( V_2 , V_9 ) ;
}
void
F_127 ( struct V_1 * V_2 )
{
F_110 ( V_2 , V_207 ) ;
F_9 ( V_2 , V_11 ) ;
}
void
F_128 ( struct V_1 * V_2 , void * V_208 )
{
V_2 -> V_208 = V_208 ;
V_2 -> V_209 = ( V_2 -> V_7 . V_36 ) ? V_210 : 0 ;
}
void
F_129 ( struct V_1 * V_2 , T_8 * V_211 )
{
struct V_151 * V_152 = & V_2 -> V_153 ;
int V_154 ;
for ( V_154 = 0 ; V_154 < V_156 ; V_154 ++ )
V_152 -> V_157 [ V_154 ] . V_18 = V_211 [ V_154 ] ;
}
void
F_130 ( struct V_1 * V_2 , enum V_199 V_154 ,
T_8 V_18 , void * V_75 )
{
struct V_151 * V_152 = & V_2 -> V_153 ;
V_152 -> V_157 [ V_154 ] . V_18 = V_18 ;
V_152 -> V_157 [ V_154 ] . V_75 = V_75 ;
}
void
F_131 ( struct V_1 * V_2 , struct V_158 * V_159 )
{
struct V_151 * V_152 = & V_2 -> V_153 ;
T_3 V_160 ;
if ( ! F_103 ( & V_152 -> V_155 ) ) {
F_132 ( & V_159 -> V_72 , & V_152 -> V_155 ) ;
return;
}
V_160 = F_63 ( V_2 -> V_51 . V_121 ) ;
if ( V_160 ) {
F_132 ( & V_159 -> V_72 , & V_152 -> V_155 ) ;
return;
}
F_82 ( V_2 , V_159 -> V_161 , sizeof( V_159 -> V_161 ) ) ;
}
void
F_133 ( struct V_1 * V_2 )
{
struct V_151 * V_152 = & V_2 -> V_153 ;
struct V_183 V_184 ;
int V_154 ;
F_114 ( V_2 , & V_184 ) ;
V_154 = V_184 . V_126 . V_212 ;
if ( V_154 == V_127 ) {
F_116 ( V_2 , & V_184 ) ;
return;
}
if ( ( V_154 > V_156 ) || ( V_152 -> V_157 [ V_154 ] . V_18 == NULL ) )
return;
V_152 -> V_157 [ V_154 ] . V_18 ( V_152 -> V_157 [ V_154 ] . V_75 , & V_184 ) ;
}
void
F_134 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_17 ) ;
}
void
F_135 ( struct V_1 * V_2 )
{
V_2 -> V_195 = V_79 ;
V_2 -> V_213 = F_136 ( V_2 ) ;
}
T_1
F_137 ( struct V_1 * V_2 )
{
return F_112 ( V_2 , V_24 ) ||
F_112 ( V_2 , V_41 ) ;
}
T_1
F_138 ( struct V_1 * V_2 )
{
return F_112 ( V_2 , V_6 ) ||
F_112 ( & V_2 -> V_7 , V_48 ) ||
F_112 ( & V_2 -> V_7 , V_53 ) ;
}
T_1
F_139 ( struct V_1 * V_2 )
{
T_3 V_214 ;
void T_2 * V_172 = V_2 -> V_174 . V_175 ;
if ( ! F_112 ( V_2 , V_41 ) )
return V_56 ;
V_214 = F_63 ( V_172 + V_178 ) ;
if ( ! F_140 ( V_214 ) )
return V_56 ;
if ( V_2 -> V_174 . V_201 != V_215 ) {
V_214 = F_63 ( V_172 + V_179 ) ;
if ( ! F_140 ( V_214 ) )
return V_56 ;
}
return V_79 ;
}
void
F_141 ( struct V_1 * V_2 )
{
F_31 ( V_108 , V_2 -> V_51 . V_67 ) ;
F_31 ( V_108 , V_2 -> V_51 . V_216 ) ;
}
void
F_142 ( struct V_1 * V_2 ,
struct V_217 * V_218 )
{
struct V_146 * V_219 ;
V_219 = V_2 -> V_147 ;
F_143 ( V_2 , V_218 -> V_220 ) ;
F_144 ( V_2 , V_218 -> V_221 ) ;
F_145 ( V_2 , V_218 -> V_222 ) ;
F_146 ( V_2 , V_218 -> V_223 ) ;
memcpy ( & V_218 -> V_224 , & V_219 -> V_224 ,
sizeof( struct V_225 ) ) ;
V_218 -> V_226 = F_147 ( V_2 ) ;
V_218 -> V_227 = F_148 ( V_2 ) ;
F_149 ( V_2 , V_218 -> V_228 ) ;
F_149 ( V_2 , V_218 -> V_229 ) ;
V_218 -> V_149 = V_219 -> V_149 ;
V_218 -> V_230 = F_150 ( V_219 -> V_149 ) ;
if ( F_151 ( V_219 -> V_148 ) )
V_218 -> V_231 = 1 ;
else
V_218 -> V_231 = 0 ;
V_218 -> V_232 = V_2 -> V_147 -> V_232 ;
V_218 -> V_233 = F_152 ( V_2 ) ;
V_218 -> V_234 = V_219 -> V_234 ;
V_218 -> V_235 = V_219 -> V_235 ;
V_218 -> V_236 = V_219 -> V_236 ;
V_218 -> V_237 = V_219 -> V_237 ;
F_153 ( V_2 , V_218 -> V_238 ) ;
V_218 -> V_239 = V_2 -> V_202 ;
V_218 -> V_240 = ( V_218 -> V_226 > 1 ) && ! V_2 -> V_202 &&
! V_218 -> V_230 ;
}
enum V_241
F_154 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_200 || V_2 -> V_195 )
return V_242 ;
else if ( V_2 -> V_130 == V_243 )
return V_244 ;
else if ( V_2 -> V_130 == V_245 )
return V_246 ;
else {
F_65 ( V_2 -> V_130 != V_245 ) ;
return V_246 ;
}
}
void
F_143 ( struct V_1 * V_2 , char * V_220 )
{
memset ( ( void * ) V_220 , 0 , V_247 ) ;
memcpy ( ( void * ) V_220 ,
( void * ) V_2 -> V_147 -> V_248 ,
V_247 ) ;
}
void
F_144 ( struct V_1 * V_2 , char * V_221 )
{
memset ( ( void * ) V_221 , 0 , V_249 ) ;
memcpy ( V_221 , V_2 -> V_147 -> V_250 , V_249 ) ;
}
void
F_153 ( struct V_1 * V_2 , char * V_251 )
{
F_65 ( ! V_251 ) ;
memset ( ( void * ) V_251 , 0 , V_252 ) ;
V_251 [ 0 ] = 'R' ;
V_251 [ 1 ] = 'e' ;
V_251 [ 2 ] = 'v' ;
V_251 [ 3 ] = '-' ;
V_251 [ 4 ] = V_2 -> V_147 -> V_237 ;
V_251 [ 5 ] = '\0' ;
}
void
F_145 ( struct V_1 * V_2 , char * V_222 )
{
memset ( ( void * ) V_222 , 0 , V_249 ) ;
memcpy ( V_222 , V_2 -> V_147 -> V_253 ,
V_249 ) ;
}
void
F_146 ( struct V_1 * V_2 , char * V_223 )
{
memset ( ( void * ) V_223 , 0 , V_254 ) ;
memcpy ( V_223 , V_255 , V_254 ) ;
}
void
F_149 ( struct V_1 * V_2 , char * V_228 )
{
struct V_146 * V_219 ;
F_65 ( ! V_228 ) ;
memset ( ( void * ) V_228 , 0 , V_256 ) ;
V_219 = V_2 -> V_147 ;
snprintf ( V_228 , V_256 , L_6 ,
V_255 , V_219 -> V_149 ) ;
}
enum V_257
F_155 ( struct V_1 * V_2 )
{
enum V_258 V_259 ;
enum V_257 V_260 = F_156 ( V_261 , V_2 -> V_262 ) ;
if ( V_260 == V_263 ||
V_260 == V_264 || V_260 == V_265 ) {
V_259 = F_156 ( V_266 , V_2 -> V_7 . V_262 ) ;
switch ( V_259 ) {
case V_267 :
V_260 = V_268 ;
break;
case V_269 :
V_260 = V_270 ;
break;
case V_271 :
V_260 = V_272 ;
break;
case V_273 :
V_260 = V_264 ;
break;
case V_274 :
V_260 = V_265 ;
break;
default:
break;
}
}
return V_260 ;
}
void
F_157 ( struct V_1 * V_2 , struct V_275 * V_219 )
{
memset ( ( void * ) V_219 , 0 , sizeof( struct V_275 ) ) ;
V_219 -> V_276 = F_155 ( V_2 ) ;
V_219 -> V_213 = V_2 -> V_213 ;
V_219 -> V_277 = F_154 ( V_2 ) ;
F_142 ( V_2 , & V_219 -> V_278 ) ;
V_219 -> V_279 . V_201 = V_2 -> V_174 . V_201 ;
V_219 -> V_279 . V_280 = V_2 -> V_174 . V_281 ;
F_153 ( V_2 , V_219 -> V_279 . V_251 ) ;
}
T_9
F_152 ( struct V_1 * V_2 )
{
if ( F_154 ( V_2 ) == V_244 )
return V_2 -> V_147 -> V_282 ;
else
return V_2 -> V_147 -> V_233 ;
}
T_9
F_158 ( struct V_1 * V_2 )
{
T_9 V_184 ;
V_184 = V_2 -> V_147 -> V_283 ;
if ( F_159 ( V_2 -> V_147 -> V_149 ) )
V_184 . V_233 [ V_284 - 1 ] += F_136 ( V_2 ) ;
else
F_160 ( & ( V_184 . V_233 [ V_284 - 3 ] ) ,
F_136 ( V_2 ) ) ;
return V_184 ;
}
T_1
F_161 ( struct V_1 * V_2 )
{
return V_2 -> V_195 || ! F_120 ( V_2 -> V_174 . V_201 ) ;
}
T_4
F_162 ( struct V_1 * V_2 , void * V_285 , int * V_286 )
{
int V_287 ;
if ( V_2 -> V_209 == 0 )
return V_288 ;
V_287 = * V_286 ;
if ( V_287 > V_2 -> V_209 )
V_287 = V_2 -> V_209 ;
memcpy ( V_285 , V_2 -> V_208 , V_287 ) ;
* V_286 = V_287 ;
return V_32 ;
}
T_4
F_163 ( struct V_1 * V_2 , void * V_285 , int * V_286 )
{
T_3 V_92 = F_164 ( F_85 ( V_2 ) ) ;
int V_287 ;
T_4 V_289 ;
F_3 ( V_2 , * V_286 ) ;
V_287 = * V_286 ;
if ( V_287 > V_210 )
V_287 = V_210 ;
V_289 = F_105 ( V_2 , V_285 , V_92 , V_287 ) ;
* V_286 = V_287 ;
return V_289 ;
}
static void
F_165 ( struct V_1 * V_2 )
{
struct V_158 V_159 ;
struct V_122 * V_290 = (struct V_122 * ) V_159 . V_161 ;
F_84 ( V_290 -> V_126 , V_127 , V_291 ,
F_85 ( V_2 ) ) ;
V_290 -> V_129 = V_2 -> V_130 ;
F_131 ( V_2 , & V_159 ) ;
}
static void
F_166 ( struct V_1 * V_2 )
{
T_3 V_292 = 1000 ;
F_165 ( V_2 ) ;
while ( F_167 ( V_2 ) && V_292 > 0 )
V_292 -- ;
}
T_4
F_168 ( struct V_1 * V_2 , void * V_165 ,
T_3 * V_293 , int * V_294 )
{
T_3 V_92 ;
int V_295 ;
T_4 V_289 ;
T_3 V_296 = F_169 ( V_2 ) ;
if ( * V_293 >= V_296 ) {
* V_293 = * V_294 = 0 ;
return V_297 ;
}
V_92 = * V_293 ;
V_295 = * V_294 ;
if ( V_92 == 0 )
F_166 ( V_2 ) ;
if ( ( V_92 + V_295 ) >= V_296 )
V_295 = V_296 - V_92 ;
V_289 = F_105 ( V_2 , V_165 , V_92 , V_295 ) ;
if ( V_289 != V_32 ) {
* V_293 = * V_294 = 0 ;
return V_289 ;
}
* V_293 += V_295 ;
if ( * V_293 >= V_296 )
* V_293 = 0 ;
* V_294 = V_295 ;
return V_289 ;
}
T_4
F_170 ( struct V_1 * V_2 , void * V_298 )
{
T_3 V_92 = V_299 + \
V_300 * ( F_85 ( V_2 ) ) ;
int V_287 ;
T_4 V_289 ;
if ( V_2 -> V_301 ) {
F_3 ( V_2 , V_2 -> V_301 ) ;
return V_302 ;
}
V_2 -> V_301 = V_79 ;
V_287 = sizeof( struct V_303 ) ;
V_289 = F_105 ( V_2 , V_298 , V_92 , V_287 ) ;
V_2 -> V_301 = V_56 ;
return V_289 ;
}
T_4
F_171 ( struct V_1 * V_2 )
{
T_3 V_92 = V_299 + \
V_300 * ( F_85 ( V_2 ) ) ;
int V_287 ;
T_4 V_289 ;
if ( V_2 -> V_301 ) {
F_3 ( V_2 , V_2 -> V_301 ) ;
return V_302 ;
}
V_2 -> V_301 = V_79 ;
V_287 = sizeof( struct V_303 ) ;
V_289 = F_106 ( V_2 , V_92 , V_287 ) ;
V_2 -> V_301 = V_56 ;
return V_289 ;
}
static void
F_107 ( struct V_1 * V_2 )
{
int V_287 ;
if ( V_2 -> V_196 ) {
V_2 -> V_196 = V_56 ;
if ( V_2 -> V_209 ) {
V_287 = V_2 -> V_209 ;
F_163 ( V_2 , V_2 -> V_208 , & V_287 ) ;
}
}
}
static void
F_90 ( struct V_1 * V_2 )
{
F_110 ( V_2 , V_304 ) ;
F_9 ( V_2 , V_35 ) ;
}
static void
F_14 ( struct V_1 * V_2 )
{
if ( F_154 ( V_2 ) == V_246 )
return;
}
static void
F_172 ( void * V_115 )
{
struct V_1 * V_2 = (struct V_1 * ) V_115 ;
F_3 ( V_2 , 0 ) ;
F_9 ( & V_2 -> V_7 , V_54 ) ;
}
static void
F_173 ( void * V_115 )
{
struct V_1 * V_2 = (struct V_1 * ) V_115 ;
F_26 ( V_2 ) ;
}
void
F_174 ( struct V_193 * V_152 )
{
struct V_71 * V_305 = & V_152 -> V_306 ;
struct V_71 * V_72 , * V_307 ;
struct V_308 * V_309 ;
struct V_71 V_310 ;
F_102 ( & V_310 ) ;
V_72 = F_175 ( V_305 ) ;
while ( V_72 != V_305 ) {
V_307 = F_175 ( V_72 ) ;
V_309 = (struct V_308 * ) V_72 ;
if ( V_309 -> V_311 <= V_312 ) {
V_309 -> V_311 = 0 ;
F_176 ( & V_309 -> V_72 ) ;
F_132 ( & V_309 -> V_72 , & V_310 ) ;
} else {
V_309 -> V_311 -= V_312 ;
}
V_72 = V_307 ;
}
while ( ! F_103 ( & V_310 ) ) {
F_104 ( & V_310 , & V_309 ) ;
V_309 -> V_313 ( V_309 -> V_314 ) ;
}
}
void
F_177 ( struct V_193 * V_152 , struct V_308 * V_315 ,
void (* V_313) ( void * ) , void * V_314 , unsigned int V_311 )
{
F_65 ( V_313 == NULL ) ;
F_65 ( F_178 ( & V_152 -> V_306 , V_315 ) ) ;
V_315 -> V_311 = V_311 ;
V_315 -> V_313 = V_313 ;
V_315 -> V_314 = V_314 ;
F_132 ( & V_315 -> V_72 , & V_152 -> V_306 ) ;
}
void
F_179 ( struct V_308 * V_315 )
{
F_65 ( F_103 ( & V_315 -> V_72 ) ) ;
F_176 ( & V_315 -> V_72 ) ;
}
