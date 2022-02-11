static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return 1 ;
default:
return 0 ;
}
}
static int F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_4 , 0 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
F_5 ( V_7 , V_8 ,
F_6 ( V_8 ) ) ;
F_7 ( V_7 , V_9 , F_6 ( V_9 ) ) ;
return 0 ;
}
static int F_8 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
if ( ! V_15 -> V_16 ) {
F_10 ( V_2 -> V_17 ,
L_1 ) ;
return - V_18 ;
}
F_11 ( V_11 -> V_19 , 0 ,
V_20 ,
& V_15 -> V_21 ) ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 ,
struct V_22 * V_23 ,
struct V_12 * V_13 )
{
struct V_24 * V_25 = V_11 -> V_26 ;
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
int V_27 ;
T_1 V_28 = F_13 ( V_2 , V_29 ) ;
T_1 V_30 = F_13 ( V_2 , V_31 ) ;
for ( V_27 = 0 ; V_27 < F_6 ( V_32 ) ; V_27 ++ ) {
if ( V_15 -> V_16 / F_14 ( V_23 ) ==
V_32 [ V_27 ] . V_33 )
break;
}
if ( V_27 == F_6 ( V_32 ) ) {
F_10 ( V_2 -> V_17 , L_2 ,
V_15 -> V_16 / F_14 ( V_23 ) ) ;
return - V_18 ;
}
V_30 &= ~ V_34 ;
V_30 |= V_32 [ V_27 ] . V_35 ;
V_28 &= ~ V_36 ;
switch ( F_15 ( V_23 ) ) {
case V_37 :
break;
case V_38 :
V_28 |= 0x8 ;
break;
case V_39 :
V_28 |= 0x10 ;
break;
case V_40 :
V_28 |= 0x18 ;
break;
}
F_3 ( V_2 , V_29 , V_28 ) ;
F_3 ( V_2 , V_31 , V_30 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_41 ,
int V_42 , unsigned int V_43 , int V_44 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
unsigned int V_45 ;
int V_27 ;
V_15 -> V_16 = V_43 ;
V_15 -> V_21 . V_46 = 0 ;
for ( V_27 = 0 ; V_27 < F_6 ( V_32 ) ; V_27 ++ ) {
V_45 = V_43 / V_32 [ V_27 ] . V_33 ;
switch ( V_45 ) {
case 8000 :
case 11025 :
case 16000 :
case 22050 :
case 32000 :
case 44100 :
case 48000 :
case 64000 :
case 88200 :
case 96000 :
case 176400 :
case 192000 :
F_17 ( V_2 -> V_17 , L_3 ,
V_45 ) ;
V_15 -> V_47 [ V_27 ] = V_45 ;
V_15 -> V_21 . V_46 ++ ;
break;
default:
F_17 ( V_2 -> V_17 , L_4 ,
V_45 ) ;
}
}
if ( V_15 -> V_21 . V_46 == 0 )
return - V_18 ;
return 0 ;
}
static int F_18 ( struct V_12 * V_41 ,
unsigned int V_48 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
T_1 V_28 = F_13 ( V_2 , V_29 ) ;
V_28 &= ~ ( V_49 | V_50 |
V_51 | V_52 ) ;
switch ( V_48 & V_53 ) {
case V_54 :
V_28 |= V_55 ;
break;
case V_56 :
break;
default:
return - V_18 ;
}
switch ( V_48 & V_57 ) {
case V_58 :
V_28 |= 0x0002 ;
break;
case V_59 :
break;
case V_60 :
V_28 |= 0x0001 ;
break;
case V_61 :
V_28 |= 0x0003 ;
break;
case V_62 :
V_28 |= 0x0023 ;
break;
default:
return - V_18 ;
}
switch ( V_48 & V_63 ) {
case V_64 :
break;
case V_65 :
V_28 |= V_66 | V_67 ;
break;
case V_68 :
V_28 |= V_66 ;
break;
case V_69 :
V_28 |= V_67 ;
break;
default:
return - V_18 ;
}
F_3 ( V_2 , V_29 , V_28 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
enum V_70 V_71 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
T_1 * V_72 = V_2 -> V_72 ;
int V_73 , V_27 ;
switch ( V_71 ) {
case V_74 :
break;
case V_75 :
F_20 ( V_2 , V_76 ,
V_77 , 3 ) ;
break;
case V_78 :
if ( V_2 -> V_7 . V_79 == V_80 ) {
V_73 = F_21 ( F_6 ( V_15 -> V_81 ) ,
V_15 -> V_81 ) ;
if ( V_73 != 0 ) {
F_10 ( V_2 -> V_17 ,
L_5 ,
V_73 ) ;
return V_73 ;
}
F_20 ( V_2 , V_76 ,
V_77 , 1 ) ;
for ( V_27 = V_29 ;
V_27 < V_82 ; V_27 ++ )
F_3 ( V_2 , V_27 , V_72 [ V_27 ] ) ;
F_22 ( 100 ) ;
}
F_20 ( V_2 , V_76 ,
V_77 , 2 ) ;
break;
case V_80 :
F_20 ( V_2 , V_76 ,
V_77 , 0 ) ;
F_22 ( 100 ) ;
F_23 ( F_6 ( V_15 -> V_81 ) ,
V_15 -> V_81 ) ;
break;
}
V_2 -> V_7 . V_79 = V_71 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , T_2 V_83 )
{
F_19 ( V_2 , V_80 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_78 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
int V_73 , V_27 ;
V_2 -> V_84 = ( V_85 ) V_86 ;
V_15 -> V_21 . V_87 = & V_15 -> V_47 [ 0 ] ;
V_15 -> V_21 . V_46 =
F_6 ( V_15 -> V_47 ) ;
V_73 = F_27 ( V_2 , 8 , 16 , V_15 -> V_88 ) ;
if ( V_73 != 0 ) {
F_10 ( V_2 -> V_17 , L_6 , V_73 ) ;
return V_73 ;
}
for ( V_27 = 0 ; V_27 < F_6 ( V_15 -> V_81 ) ; V_27 ++ )
V_15 -> V_81 [ V_27 ] . V_89 = V_90 [ V_27 ] ;
V_73 = F_28 ( V_2 -> V_17 , F_6 ( V_15 -> V_81 ) ,
V_15 -> V_81 ) ;
if ( V_73 != 0 ) {
F_10 ( V_2 -> V_17 , L_7 , V_73 ) ;
return V_73 ;
}
V_73 = F_21 ( F_6 ( V_15 -> V_81 ) ,
V_15 -> V_81 ) ;
if ( V_73 != 0 ) {
F_10 ( V_2 -> V_17 , L_5 , V_73 ) ;
goto V_91;
}
V_73 = F_13 ( V_2 , V_4 ) ;
if ( V_73 < 0 ) {
F_10 ( V_2 -> V_17 , L_8 ) ;
goto V_92;
}
if ( V_73 != V_93 [ V_4 ] ) {
F_10 ( V_2 -> V_17 , L_9 , V_73 ) ;
V_73 = - V_18 ;
goto V_92;
}
V_73 = F_13 ( V_2 , V_5 ) ;
if ( V_73 < 0 ) {
F_10 ( V_2 -> V_17 , L_10 ) ;
goto V_92;
}
F_29 ( V_2 -> V_17 , L_11 ,
( V_73 & V_94 ) + 'A' ) ;
V_73 = F_2 ( V_2 ) ;
if ( V_73 < 0 ) {
F_10 ( V_2 -> V_17 , L_12 ) ;
goto V_92;
}
F_20 ( V_2 , V_95 ,
V_96 , V_96 ) ;
F_20 ( V_2 , V_97 , V_98 , V_98 ) ;
F_19 ( V_2 , V_78 ) ;
F_23 ( F_6 ( V_15 -> V_81 ) , V_15 -> V_81 ) ;
F_30 ( V_2 , V_99 ,
F_6 ( V_99 ) ) ;
F_4 ( V_2 ) ;
return 0 ;
V_92:
F_23 ( F_6 ( V_15 -> V_81 ) , V_15 -> V_81 ) ;
V_91:
F_31 ( F_6 ( V_15 -> V_81 ) , V_15 -> V_81 ) ;
return V_73 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
F_19 ( V_2 , V_80 ) ;
F_31 ( F_6 ( V_15 -> V_81 ) , V_15 -> V_81 ) ;
return 0 ;
}
static T_3 int F_33 ( struct V_100 * V_101 ,
const struct V_102 * V_103 )
{
struct V_14 * V_15 ;
int V_73 ;
V_15 = F_34 ( sizeof( struct V_14 ) , V_104 ) ;
if ( V_15 == NULL )
return - V_105 ;
F_35 ( V_101 , V_15 ) ;
V_15 -> V_88 = V_106 ;
V_73 = F_36 ( & V_101 -> V_17 ,
& V_107 , & V_108 , 1 ) ;
if ( V_73 < 0 )
F_37 ( V_15 ) ;
return V_73 ;
}
static T_4 int F_38 ( struct V_100 * V_109 )
{
F_39 ( & V_109 -> V_17 ) ;
F_37 ( F_40 ( V_109 ) ) ;
return 0 ;
}
static int T_5 F_41 ( void )
{
int V_73 ;
#if F_42 ( V_110 ) || F_42 ( V_111 )
V_73 = F_43 ( & V_112 ) ;
if ( V_73 != 0 ) {
F_44 ( V_113 L_13 ,
V_73 ) ;
}
#endif
return 0 ;
}
static void T_6 F_45 ( void )
{
#if F_42 ( V_110 ) || F_42 ( V_111 )
F_46 ( & V_112 ) ;
#endif
}
