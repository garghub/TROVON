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
struct V_20 * V_21 = V_7 -> V_22 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_10 * V_11 = F_5 ( V_2 ) ;
int V_23 ;
T_1 V_24 = F_9 ( V_2 , V_25 ) ;
T_1 V_26 = F_9 ( V_2 , V_27 ) ;
for ( V_23 = 0 ; V_23 < F_10 ( V_28 ) ; V_23 ++ ) {
if ( V_11 -> V_12 / F_11 ( V_19 ) ==
V_28 [ V_23 ] . V_29 )
break;
}
if ( V_23 == F_10 ( V_28 ) ) {
F_6 ( V_2 -> V_13 , L_2 ,
V_11 -> V_12 / F_11 ( V_19 ) ) ;
return - V_14 ;
}
V_26 &= ~ V_30 ;
V_26 |= V_28 [ V_23 ] . V_31 ;
V_24 &= ~ V_32 ;
switch ( F_12 ( V_19 ) ) {
case V_33 :
break;
case V_34 :
V_24 |= 0x8 ;
break;
case V_35 :
V_24 |= 0x10 ;
break;
case V_36 :
V_24 |= 0x18 ;
break;
}
F_3 ( V_2 , V_25 , V_24 ) ;
F_3 ( V_2 , V_27 , V_26 ) ;
return 0 ;
}
static int F_13 ( struct V_8 * V_37 ,
int V_38 , unsigned int V_39 , int V_40 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_10 * V_11 = F_5 ( V_2 ) ;
unsigned int V_41 ;
int V_23 ;
V_11 -> V_12 = V_39 ;
V_11 -> V_17 . V_42 = 0 ;
for ( V_23 = 0 ; V_23 < F_10 ( V_28 ) ; V_23 ++ ) {
V_41 = V_39 / V_28 [ V_23 ] . V_29 ;
switch ( V_41 ) {
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
V_41 ) ;
V_11 -> V_43 [ V_23 ] = V_41 ;
V_11 -> V_17 . V_42 ++ ;
break;
default:
F_14 ( V_2 -> V_13 , L_4 ,
V_41 ) ;
}
}
if ( V_11 -> V_17 . V_42 == 0 )
return - V_14 ;
return 0 ;
}
static int F_15 ( struct V_8 * V_37 ,
unsigned int V_44 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
T_1 V_24 = F_9 ( V_2 , V_25 ) ;
V_24 &= ~ ( V_45 | V_46 |
V_47 | V_48 ) ;
switch ( V_44 & V_49 ) {
case V_50 :
V_24 |= V_51 ;
break;
case V_52 :
break;
default:
return - V_14 ;
}
switch ( V_44 & V_53 ) {
case V_54 :
V_24 |= 0x0002 ;
break;
case V_55 :
break;
case V_56 :
V_24 |= 0x0001 ;
break;
case V_57 :
V_24 |= 0x0003 ;
break;
case V_58 :
V_24 |= 0x0023 ;
break;
default:
return - V_14 ;
}
switch ( V_44 & V_59 ) {
case V_60 :
break;
case V_61 :
V_24 |= V_62 | V_63 ;
break;
case V_64 :
V_24 |= V_62 ;
break;
case V_65 :
V_24 |= V_63 ;
break;
default:
return - V_14 ;
}
F_3 ( V_2 , V_25 , V_24 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
enum V_66 V_67 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
T_1 * V_68 = V_2 -> V_68 ;
int V_69 , V_23 ;
switch ( V_67 ) {
case V_70 :
break;
case V_71 :
F_17 ( V_2 , V_72 ,
V_73 , 3 ) ;
break;
case V_74 :
if ( V_2 -> V_75 . V_76 == V_77 ) {
V_69 = F_18 ( F_10 ( V_11 -> V_78 ) ,
V_11 -> V_78 ) ;
if ( V_69 != 0 ) {
F_6 ( V_2 -> V_13 ,
L_5 ,
V_69 ) ;
return V_69 ;
}
F_17 ( V_2 , V_72 ,
V_73 , 1 ) ;
for ( V_23 = V_25 ;
V_23 < V_79 ; V_23 ++ )
F_3 ( V_2 , V_23 , V_68 [ V_23 ] ) ;
F_19 ( 100 ) ;
}
F_17 ( V_2 , V_72 ,
V_73 , 2 ) ;
break;
case V_77 :
F_17 ( V_2 , V_72 ,
V_73 , 0 ) ;
F_19 ( 100 ) ;
F_20 ( F_10 ( V_11 -> V_78 ) ,
V_11 -> V_78 ) ;
break;
}
V_2 -> V_75 . V_76 = V_67 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_80 )
{
F_16 ( V_2 , V_77 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_74 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
int V_69 , V_23 ;
V_11 -> V_17 . V_81 = & V_11 -> V_43 [ 0 ] ;
V_11 -> V_17 . V_42 =
F_10 ( V_11 -> V_43 ) ;
V_69 = F_24 ( V_2 , 8 , 16 , V_11 -> V_82 ) ;
if ( V_69 != 0 ) {
F_6 ( V_2 -> V_13 , L_6 , V_69 ) ;
return V_69 ;
}
for ( V_23 = 0 ; V_23 < F_10 ( V_11 -> V_78 ) ; V_23 ++ )
V_11 -> V_78 [ V_23 ] . V_83 = V_84 [ V_23 ] ;
V_69 = F_25 ( V_2 -> V_13 , F_10 ( V_11 -> V_78 ) ,
V_11 -> V_78 ) ;
if ( V_69 != 0 ) {
F_6 ( V_2 -> V_13 , L_7 , V_69 ) ;
return V_69 ;
}
V_69 = F_18 ( F_10 ( V_11 -> V_78 ) ,
V_11 -> V_78 ) ;
if ( V_69 != 0 ) {
F_6 ( V_2 -> V_13 , L_5 , V_69 ) ;
goto V_85;
}
V_69 = F_9 ( V_2 , V_4 ) ;
if ( V_69 < 0 ) {
F_6 ( V_2 -> V_13 , L_8 ) ;
goto V_86;
}
if ( V_69 != V_87 [ V_4 ] ) {
F_6 ( V_2 -> V_13 , L_9 , V_69 ) ;
V_69 = - V_14 ;
goto V_86;
}
V_69 = F_9 ( V_2 , V_5 ) ;
if ( V_69 < 0 ) {
F_6 ( V_2 -> V_13 , L_10 ) ;
goto V_86;
}
F_26 ( V_2 -> V_13 , L_11 ,
( V_69 & V_88 ) + 'A' ) ;
V_69 = F_2 ( V_2 ) ;
if ( V_69 < 0 ) {
F_6 ( V_2 -> V_13 , L_12 ) ;
goto V_86;
}
F_17 ( V_2 , V_89 ,
V_90 , V_90 ) ;
F_17 ( V_2 , V_91 , V_92 , V_92 ) ;
F_16 ( V_2 , V_74 ) ;
F_20 ( F_10 ( V_11 -> V_78 ) , V_11 -> V_78 ) ;
return 0 ;
V_86:
F_20 ( F_10 ( V_11 -> V_78 ) , V_11 -> V_78 ) ;
V_85:
F_27 ( F_10 ( V_11 -> V_78 ) , V_11 -> V_78 ) ;
return V_69 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
F_16 ( V_2 , V_77 ) ;
F_27 ( F_10 ( V_11 -> V_78 ) , V_11 -> V_78 ) ;
return 0 ;
}
static T_3 int F_29 ( struct V_93 * V_94 ,
const struct V_95 * V_96 )
{
struct V_10 * V_11 ;
int V_69 ;
V_11 = F_30 ( sizeof( struct V_10 ) , V_97 ) ;
if ( V_11 == NULL )
return - V_98 ;
F_31 ( V_94 , V_11 ) ;
V_11 -> V_82 = V_99 ;
V_69 = F_32 ( & V_94 -> V_13 ,
& V_100 , & V_101 , 1 ) ;
if ( V_69 < 0 )
F_33 ( V_11 ) ;
return V_69 ;
}
static T_4 int F_34 ( struct V_93 * V_102 )
{
F_35 ( & V_102 -> V_13 ) ;
F_33 ( F_36 ( V_102 ) ) ;
return 0 ;
}
static int T_5 F_37 ( void )
{
int V_69 ;
#if F_38 ( V_103 ) || F_38 ( V_104 )
V_69 = F_39 ( & V_105 ) ;
if ( V_69 != 0 ) {
F_40 ( V_106 L_13 ,
V_69 ) ;
}
#endif
return 0 ;
}
static void T_6 F_41 ( void )
{
#if F_38 ( V_103 ) || F_38 ( V_104 )
F_42 ( & V_105 ) ;
#endif
}
