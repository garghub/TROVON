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
static int F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_5 ( V_2 ) ;
if ( ! V_11 -> V_12 ) {
F_6 ( V_2 -> V_13 ,
L_1 ) ;
return - V_14 ;
}
F_7 ( V_7 -> V_15 , 0 ,
V_16 ,
& V_11 -> V_17 ) ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_18 * V_19 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = F_5 ( V_2 ) ;
int V_20 ;
T_1 V_21 = F_9 ( V_2 , V_22 ) ;
T_1 V_23 = F_9 ( V_2 , V_24 ) ;
for ( V_20 = 0 ; V_20 < F_10 ( V_25 ) ; V_20 ++ ) {
if ( V_11 -> V_12 / F_11 ( V_19 ) ==
V_25 [ V_20 ] . V_26 )
break;
}
if ( V_20 == F_10 ( V_25 ) ) {
F_6 ( V_2 -> V_13 , L_2 ,
V_11 -> V_12 / F_11 ( V_19 ) ) ;
return - V_14 ;
}
V_23 &= ~ V_27 ;
V_23 |= V_25 [ V_20 ] . V_28 ;
V_21 &= ~ V_29 ;
switch ( F_12 ( V_19 ) ) {
case V_30 :
break;
case V_31 :
V_21 |= 0x8 ;
break;
case V_32 :
V_21 |= 0x10 ;
break;
case V_33 :
V_21 |= 0x18 ;
break;
}
F_3 ( V_2 , V_22 , V_21 ) ;
F_3 ( V_2 , V_24 , V_23 ) ;
return 0 ;
}
static int F_13 ( struct V_8 * V_34 ,
int V_35 , unsigned int V_36 , int V_37 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_10 * V_11 = F_5 ( V_2 ) ;
unsigned int V_38 ;
int V_20 ;
V_11 -> V_12 = V_36 ;
V_11 -> V_17 . V_39 = 0 ;
for ( V_20 = 0 ; V_20 < F_10 ( V_25 ) ; V_20 ++ ) {
V_38 = V_36 / V_25 [ V_20 ] . V_26 ;
switch ( V_38 ) {
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
F_14 ( V_2 -> V_13 , L_3 ,
V_38 ) ;
V_11 -> V_40 [ V_20 ] = V_38 ;
V_11 -> V_17 . V_39 ++ ;
break;
default:
F_14 ( V_2 -> V_13 , L_4 ,
V_38 ) ;
}
}
if ( V_11 -> V_17 . V_39 == 0 )
return - V_14 ;
return 0 ;
}
static int F_15 ( struct V_8 * V_34 ,
unsigned int V_41 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
T_1 V_21 = F_9 ( V_2 , V_22 ) ;
V_21 &= ~ ( V_42 | V_43 |
V_44 | V_45 ) ;
switch ( V_41 & V_46 ) {
case V_47 :
V_21 |= V_48 ;
break;
case V_49 :
break;
default:
return - V_14 ;
}
switch ( V_41 & V_50 ) {
case V_51 :
V_21 |= 0x0002 ;
break;
case V_52 :
break;
case V_53 :
V_21 |= 0x0001 ;
break;
case V_54 :
V_21 |= 0x0003 ;
break;
case V_55 :
V_21 |= 0x0023 ;
break;
default:
return - V_14 ;
}
switch ( V_41 & V_56 ) {
case V_57 :
break;
case V_58 :
V_21 |= V_59 | V_60 ;
break;
case V_61 :
V_21 |= V_59 ;
break;
case V_62 :
V_21 |= V_60 ;
break;
default:
return - V_14 ;
}
F_3 ( V_2 , V_22 , V_21 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
enum V_63 V_64 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
T_1 * V_65 = V_2 -> V_65 ;
int V_66 , V_20 ;
switch ( V_64 ) {
case V_67 :
break;
case V_68 :
F_17 ( V_2 , V_69 ,
V_70 , 3 ) ;
break;
case V_71 :
if ( V_2 -> V_72 . V_73 == V_74 ) {
V_66 = F_18 ( F_10 ( V_11 -> V_75 ) ,
V_11 -> V_75 ) ;
if ( V_66 != 0 ) {
F_6 ( V_2 -> V_13 ,
L_5 ,
V_66 ) ;
return V_66 ;
}
F_17 ( V_2 , V_69 ,
V_70 , 1 ) ;
for ( V_20 = V_22 ;
V_20 < V_76 ; V_20 ++ )
F_3 ( V_2 , V_20 , V_65 [ V_20 ] ) ;
F_19 ( 100 ) ;
}
F_17 ( V_2 , V_69 ,
V_70 , 2 ) ;
break;
case V_74 :
F_17 ( V_2 , V_69 ,
V_70 , 0 ) ;
F_19 ( 100 ) ;
F_20 ( F_10 ( V_11 -> V_75 ) ,
V_11 -> V_75 ) ;
break;
}
V_2 -> V_72 . V_73 = V_64 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_74 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_71 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
int V_66 , V_20 ;
V_11 -> V_17 . V_77 = & V_11 -> V_40 [ 0 ] ;
V_11 -> V_17 . V_39 =
F_10 ( V_11 -> V_40 ) ;
V_66 = F_24 ( V_2 , 8 , 16 , V_11 -> V_78 ) ;
if ( V_66 != 0 ) {
F_6 ( V_2 -> V_13 , L_6 , V_66 ) ;
return V_66 ;
}
for ( V_20 = 0 ; V_20 < F_10 ( V_11 -> V_75 ) ; V_20 ++ )
V_11 -> V_75 [ V_20 ] . V_79 = V_80 [ V_20 ] ;
V_66 = F_25 ( V_2 -> V_13 , F_10 ( V_11 -> V_75 ) ,
V_11 -> V_75 ) ;
if ( V_66 != 0 ) {
F_6 ( V_2 -> V_13 , L_7 , V_66 ) ;
return V_66 ;
}
V_66 = F_18 ( F_10 ( V_11 -> V_75 ) ,
V_11 -> V_75 ) ;
if ( V_66 != 0 ) {
F_6 ( V_2 -> V_13 , L_5 , V_66 ) ;
goto V_81;
}
V_66 = F_9 ( V_2 , V_4 ) ;
if ( V_66 < 0 ) {
F_6 ( V_2 -> V_13 , L_8 ) ;
goto V_82;
}
if ( V_66 != V_83 [ V_4 ] ) {
F_6 ( V_2 -> V_13 , L_9 , V_66 ) ;
V_66 = - V_14 ;
goto V_82;
}
V_66 = F_9 ( V_2 , V_5 ) ;
if ( V_66 < 0 ) {
F_6 ( V_2 -> V_13 , L_10 ) ;
goto V_82;
}
F_26 ( V_2 -> V_13 , L_11 ,
( V_66 & V_84 ) + 'A' ) ;
V_66 = F_2 ( V_2 ) ;
if ( V_66 < 0 ) {
F_6 ( V_2 -> V_13 , L_12 ) ;
goto V_82;
}
F_17 ( V_2 , V_85 ,
V_86 , V_86 ) ;
F_17 ( V_2 , V_87 , V_88 , V_88 ) ;
F_16 ( V_2 , V_71 ) ;
F_20 ( F_10 ( V_11 -> V_75 ) , V_11 -> V_75 ) ;
return 0 ;
V_82:
F_20 ( F_10 ( V_11 -> V_75 ) , V_11 -> V_75 ) ;
V_81:
F_27 ( F_10 ( V_11 -> V_75 ) , V_11 -> V_75 ) ;
return V_66 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
F_16 ( V_2 , V_74 ) ;
F_27 ( F_10 ( V_11 -> V_75 ) , V_11 -> V_75 ) ;
return 0 ;
}
static T_2 int F_29 ( struct V_89 * V_90 ,
const struct V_91 * V_92 )
{
struct V_10 * V_11 ;
int V_66 ;
V_11 = F_30 ( sizeof( struct V_10 ) , V_93 ) ;
if ( V_11 == NULL )
return - V_94 ;
F_31 ( V_90 , V_11 ) ;
V_11 -> V_78 = V_95 ;
V_66 = F_32 ( & V_90 -> V_13 ,
& V_96 , & V_97 , 1 ) ;
if ( V_66 < 0 )
F_33 ( V_11 ) ;
return V_66 ;
}
static T_3 int F_34 ( struct V_89 * V_98 )
{
F_35 ( & V_98 -> V_13 ) ;
F_33 ( F_36 ( V_98 ) ) ;
return 0 ;
}
static int T_4 F_37 ( void )
{
int V_66 ;
#if F_38 ( V_99 ) || F_38 ( V_100 )
V_66 = F_39 ( & V_101 ) ;
if ( V_66 != 0 ) {
F_40 ( V_102 L_13 ,
V_66 ) ;
}
#endif
return 0 ;
}
static void T_5 F_41 ( void )
{
#if F_38 ( V_99 ) || F_38 ( V_100 )
F_42 ( & V_101 ) ;
#endif
}
