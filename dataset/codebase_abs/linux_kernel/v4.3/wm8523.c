static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
if ( ! V_13 -> V_14 ) {
F_4 ( V_11 -> V_2 ,
L_1 ) ;
return - V_15 ;
}
F_5 ( V_7 -> V_16 , 0 ,
V_17 ,
& V_13 -> V_18 ) ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_19 * V_20 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
int V_21 ;
T_1 V_22 = F_7 ( V_11 , V_23 ) ;
T_1 V_24 = F_7 ( V_11 , V_25 ) ;
for ( V_21 = 0 ; V_21 < F_8 ( V_26 ) ; V_21 ++ ) {
if ( V_13 -> V_14 / F_9 ( V_20 ) ==
V_26 [ V_21 ] . V_27 )
break;
}
if ( V_21 == F_8 ( V_26 ) ) {
F_4 ( V_11 -> V_2 , L_2 ,
V_13 -> V_14 / F_9 ( V_20 ) ) ;
return - V_15 ;
}
V_24 &= ~ V_28 ;
V_24 |= V_26 [ V_21 ] . V_29 ;
if ( V_22 & V_30 ) {
for ( V_21 = 0 ; V_21 < F_8 ( V_31 ) ; V_21 ++ )
if ( F_10 ( V_20 ) * 2 <= V_31 [ V_21 ] . V_27 )
break;
if ( V_21 == F_8 ( V_31 ) ) {
F_4 ( V_11 -> V_2 ,
L_3 ,
F_10 ( V_20 ) ) ;
return - V_15 ;
}
V_24 &= ~ V_32 ;
V_24 |= V_31 [ V_21 ] . V_29 << V_33 ;
}
V_22 &= ~ V_34 ;
switch ( F_10 ( V_20 ) ) {
case 16 :
break;
case 20 :
V_22 |= 0x8 ;
break;
case 24 :
V_22 |= 0x10 ;
break;
case 32 :
V_22 |= 0x18 ;
break;
}
F_11 ( V_11 , V_23 , V_22 ) ;
F_11 ( V_11 , V_25 , V_24 ) ;
return 0 ;
}
static int F_12 ( struct V_8 * V_35 ,
int V_36 , unsigned int V_37 , int V_38 )
{
struct V_10 * V_11 = V_35 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
unsigned int V_39 ;
int V_21 ;
V_13 -> V_14 = V_37 ;
V_13 -> V_18 . V_40 = 0 ;
for ( V_21 = 0 ; V_21 < F_8 ( V_26 ) ; V_21 ++ ) {
V_39 = V_37 / V_26 [ V_21 ] . V_27 ;
switch ( V_39 ) {
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
F_13 ( V_11 -> V_2 , L_4 ,
V_39 ) ;
V_13 -> V_41 [ V_21 ] = V_39 ;
V_13 -> V_18 . V_40 ++ ;
break;
default:
F_13 ( V_11 -> V_2 , L_5 ,
V_39 ) ;
}
}
if ( V_13 -> V_18 . V_40 == 0 )
return - V_15 ;
return 0 ;
}
static int F_14 ( struct V_8 * V_35 ,
unsigned int V_42 )
{
struct V_10 * V_11 = V_35 -> V_11 ;
T_1 V_22 = F_7 ( V_11 , V_23 ) ;
V_22 &= ~ ( V_43 | V_44 |
V_45 | V_46 ) ;
switch ( V_42 & V_47 ) {
case V_48 :
V_22 |= V_30 ;
break;
case V_49 :
break;
default:
return - V_15 ;
}
switch ( V_42 & V_50 ) {
case V_51 :
V_22 |= 0x0002 ;
break;
case V_52 :
break;
case V_53 :
V_22 |= 0x0001 ;
break;
case V_54 :
V_22 |= 0x0003 ;
break;
case V_55 :
V_22 |= 0x0023 ;
break;
default:
return - V_15 ;
}
switch ( V_42 & V_56 ) {
case V_57 :
break;
case V_58 :
V_22 |= V_59 | V_60 ;
break;
case V_61 :
V_22 |= V_59 ;
break;
case V_62 :
V_22 |= V_60 ;
break;
default:
return - V_15 ;
}
F_11 ( V_11 , V_23 , V_22 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 ,
enum V_63 V_64 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
int V_65 ;
switch ( V_64 ) {
case V_66 :
break;
case V_67 :
F_16 ( V_11 , V_68 ,
V_69 , 3 ) ;
break;
case V_70 :
if ( F_17 ( V_11 ) == V_71 ) {
V_65 = F_18 ( F_8 ( V_13 -> V_72 ) ,
V_13 -> V_72 ) ;
if ( V_65 != 0 ) {
F_4 ( V_11 -> V_2 ,
L_6 ,
V_65 ) ;
return V_65 ;
}
F_19 ( V_13 -> V_73 ) ;
F_16 ( V_11 , V_68 ,
V_69 , 1 ) ;
F_20 ( 100 ) ;
}
F_16 ( V_11 , V_68 ,
V_69 , 2 ) ;
break;
case V_71 :
F_16 ( V_11 , V_68 ,
V_69 , 0 ) ;
F_20 ( 100 ) ;
F_21 ( F_8 ( V_13 -> V_72 ) ,
V_13 -> V_72 ) ;
break;
}
return 0 ;
}
static int F_22 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
V_13 -> V_18 . V_74 = & V_13 -> V_41 [ 0 ] ;
V_13 -> V_18 . V_40 =
F_8 ( V_13 -> V_41 ) ;
F_16 ( V_11 , V_75 ,
V_76 , V_76 ) ;
F_16 ( V_11 , V_77 , V_78 , V_78 ) ;
return 0 ;
}
static int F_23 ( struct V_79 * V_80 ,
const struct V_81 * V_82 )
{
struct V_12 * V_13 ;
unsigned int V_39 ;
int V_65 , V_21 ;
V_13 = F_24 ( & V_80 -> V_2 , sizeof( struct V_12 ) ,
V_83 ) ;
if ( V_13 == NULL )
return - V_84 ;
V_13 -> V_73 = F_25 ( V_80 , & V_85 ) ;
if ( F_26 ( V_13 -> V_73 ) ) {
V_65 = F_27 ( V_13 -> V_73 ) ;
F_4 ( & V_80 -> V_2 , L_7 , V_65 ) ;
return V_65 ;
}
for ( V_21 = 0 ; V_21 < F_8 ( V_13 -> V_72 ) ; V_21 ++ )
V_13 -> V_72 [ V_21 ] . V_86 = V_87 [ V_21 ] ;
V_65 = F_28 ( & V_80 -> V_2 , F_8 ( V_13 -> V_72 ) ,
V_13 -> V_72 ) ;
if ( V_65 != 0 ) {
F_4 ( & V_80 -> V_2 , L_8 , V_65 ) ;
return V_65 ;
}
V_65 = F_18 ( F_8 ( V_13 -> V_72 ) ,
V_13 -> V_72 ) ;
if ( V_65 != 0 ) {
F_4 ( & V_80 -> V_2 , L_6 , V_65 ) ;
return V_65 ;
}
V_65 = F_29 ( V_13 -> V_73 , V_4 , & V_39 ) ;
if ( V_65 < 0 ) {
F_4 ( & V_80 -> V_2 , L_9 ) ;
goto V_88;
}
if ( V_39 != 0x8523 ) {
F_4 ( & V_80 -> V_2 , L_10 , V_65 ) ;
V_65 = - V_15 ;
goto V_88;
}
V_65 = F_29 ( V_13 -> V_73 , V_5 , & V_39 ) ;
if ( V_65 < 0 ) {
F_4 ( & V_80 -> V_2 , L_11 ) ;
goto V_88;
}
F_30 ( & V_80 -> V_2 , L_12 ,
( V_39 & V_89 ) + 'A' ) ;
V_65 = F_31 ( V_13 -> V_73 , V_4 , 0x8523 ) ;
if ( V_65 != 0 ) {
F_4 ( & V_80 -> V_2 , L_13 , V_65 ) ;
goto V_88;
}
F_21 ( F_8 ( V_13 -> V_72 ) , V_13 -> V_72 ) ;
F_32 ( V_80 , V_13 ) ;
V_65 = F_33 ( & V_80 -> V_2 ,
& V_90 , & V_91 , 1 ) ;
return V_65 ;
V_88:
F_21 ( F_8 ( V_13 -> V_72 ) , V_13 -> V_72 ) ;
return V_65 ;
}
static int F_34 ( struct V_79 * V_92 )
{
F_35 ( & V_92 -> V_2 ) ;
return 0 ;
}
static int T_2 F_36 ( void )
{
int V_65 ;
#if F_37 ( V_93 )
V_65 = F_38 ( & V_94 ) ;
if ( V_65 != 0 ) {
F_39 ( V_95 L_14 ,
V_65 ) ;
}
#endif
return 0 ;
}
static void T_3 F_40 ( void )
{
#if F_37 ( V_93 )
F_41 ( & V_94 ) ;
#endif
}
