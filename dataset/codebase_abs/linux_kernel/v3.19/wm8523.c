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
V_22 &= ~ V_30 ;
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
static int F_12 ( struct V_8 * V_31 ,
int V_32 , unsigned int V_33 , int V_34 )
{
struct V_10 * V_11 = V_31 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
unsigned int V_35 ;
int V_21 ;
V_13 -> V_14 = V_33 ;
V_13 -> V_18 . V_36 = 0 ;
for ( V_21 = 0 ; V_21 < F_8 ( V_26 ) ; V_21 ++ ) {
V_35 = V_33 / V_26 [ V_21 ] . V_27 ;
switch ( V_35 ) {
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
F_13 ( V_11 -> V_2 , L_3 ,
V_35 ) ;
V_13 -> V_37 [ V_21 ] = V_35 ;
V_13 -> V_18 . V_36 ++ ;
break;
default:
F_13 ( V_11 -> V_2 , L_4 ,
V_35 ) ;
}
}
if ( V_13 -> V_18 . V_36 == 0 )
return - V_15 ;
return 0 ;
}
static int F_14 ( struct V_8 * V_31 ,
unsigned int V_38 )
{
struct V_10 * V_11 = V_31 -> V_11 ;
T_1 V_22 = F_7 ( V_11 , V_23 ) ;
V_22 &= ~ ( V_39 | V_40 |
V_41 | V_42 ) ;
switch ( V_38 & V_43 ) {
case V_44 :
V_22 |= V_45 ;
break;
case V_46 :
break;
default:
return - V_15 ;
}
switch ( V_38 & V_47 ) {
case V_48 :
V_22 |= 0x0002 ;
break;
case V_49 :
break;
case V_50 :
V_22 |= 0x0001 ;
break;
case V_51 :
V_22 |= 0x0003 ;
break;
case V_52 :
V_22 |= 0x0023 ;
break;
default:
return - V_15 ;
}
switch ( V_38 & V_53 ) {
case V_54 :
break;
case V_55 :
V_22 |= V_56 | V_57 ;
break;
case V_58 :
V_22 |= V_56 ;
break;
case V_59 :
V_22 |= V_57 ;
break;
default:
return - V_15 ;
}
F_11 ( V_11 , V_23 , V_22 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 ,
enum V_60 V_61 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
int V_62 ;
switch ( V_61 ) {
case V_63 :
break;
case V_64 :
F_16 ( V_11 , V_65 ,
V_66 , 3 ) ;
break;
case V_67 :
if ( V_11 -> V_68 . V_69 == V_70 ) {
V_62 = F_17 ( F_8 ( V_13 -> V_71 ) ,
V_13 -> V_71 ) ;
if ( V_62 != 0 ) {
F_4 ( V_11 -> V_2 ,
L_5 ,
V_62 ) ;
return V_62 ;
}
F_18 ( V_13 -> V_72 ) ;
F_16 ( V_11 , V_65 ,
V_66 , 1 ) ;
F_19 ( 100 ) ;
}
F_16 ( V_11 , V_65 ,
V_66 , 2 ) ;
break;
case V_70 :
F_16 ( V_11 , V_65 ,
V_66 , 0 ) ;
F_19 ( 100 ) ;
F_20 ( F_8 ( V_13 -> V_71 ) ,
V_13 -> V_71 ) ;
break;
}
V_11 -> V_68 . V_69 = V_61 ;
return 0 ;
}
static int F_21 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
V_13 -> V_18 . V_73 = & V_13 -> V_37 [ 0 ] ;
V_13 -> V_18 . V_36 =
F_8 ( V_13 -> V_37 ) ;
F_16 ( V_11 , V_74 ,
V_75 , V_75 ) ;
F_16 ( V_11 , V_76 , V_77 , V_77 ) ;
return 0 ;
}
static int F_22 ( struct V_78 * V_79 ,
const struct V_80 * V_81 )
{
struct V_12 * V_13 ;
unsigned int V_35 ;
int V_62 , V_21 ;
V_13 = F_23 ( & V_79 -> V_2 , sizeof( struct V_12 ) ,
V_82 ) ;
if ( V_13 == NULL )
return - V_83 ;
V_13 -> V_72 = F_24 ( V_79 , & V_84 ) ;
if ( F_25 ( V_13 -> V_72 ) ) {
V_62 = F_26 ( V_13 -> V_72 ) ;
F_4 ( & V_79 -> V_2 , L_6 , V_62 ) ;
return V_62 ;
}
for ( V_21 = 0 ; V_21 < F_8 ( V_13 -> V_71 ) ; V_21 ++ )
V_13 -> V_71 [ V_21 ] . V_85 = V_86 [ V_21 ] ;
V_62 = F_27 ( & V_79 -> V_2 , F_8 ( V_13 -> V_71 ) ,
V_13 -> V_71 ) ;
if ( V_62 != 0 ) {
F_4 ( & V_79 -> V_2 , L_7 , V_62 ) ;
return V_62 ;
}
V_62 = F_17 ( F_8 ( V_13 -> V_71 ) ,
V_13 -> V_71 ) ;
if ( V_62 != 0 ) {
F_4 ( & V_79 -> V_2 , L_5 , V_62 ) ;
return V_62 ;
}
V_62 = F_28 ( V_13 -> V_72 , V_4 , & V_35 ) ;
if ( V_62 < 0 ) {
F_4 ( & V_79 -> V_2 , L_8 ) ;
goto V_87;
}
if ( V_35 != 0x8523 ) {
F_4 ( & V_79 -> V_2 , L_9 , V_62 ) ;
V_62 = - V_15 ;
goto V_87;
}
V_62 = F_28 ( V_13 -> V_72 , V_5 , & V_35 ) ;
if ( V_62 < 0 ) {
F_4 ( & V_79 -> V_2 , L_10 ) ;
goto V_87;
}
F_29 ( & V_79 -> V_2 , L_11 ,
( V_35 & V_88 ) + 'A' ) ;
V_62 = F_30 ( V_13 -> V_72 , V_4 , 0x8523 ) ;
if ( V_62 != 0 ) {
F_4 ( & V_79 -> V_2 , L_12 , V_62 ) ;
goto V_87;
}
F_20 ( F_8 ( V_13 -> V_71 ) , V_13 -> V_71 ) ;
F_31 ( V_79 , V_13 ) ;
V_62 = F_32 ( & V_79 -> V_2 ,
& V_89 , & V_90 , 1 ) ;
return V_62 ;
V_87:
F_20 ( F_8 ( V_13 -> V_71 ) , V_13 -> V_71 ) ;
return V_62 ;
}
static int F_33 ( struct V_78 * V_91 )
{
F_34 ( & V_91 -> V_2 ) ;
return 0 ;
}
static int T_2 F_35 ( void )
{
int V_62 ;
#if F_36 ( V_92 )
V_62 = F_37 ( & V_93 ) ;
if ( V_62 != 0 ) {
F_38 ( V_94 L_13 ,
V_62 ) ;
}
#endif
return 0 ;
}
static void T_3 F_39 ( void )
{
#if F_36 ( V_92 )
F_40 ( & V_93 ) ;
#endif
}
