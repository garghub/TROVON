static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_14 * V_15 )
{
return F_3 ( V_15 , V_16 , 0 ) ;
}
static int F_4 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_14 * V_15 = V_20 -> V_15 ;
struct V_21 * V_22 = F_5 ( V_15 ) ;
if ( ! V_22 -> V_23 ) {
F_6 ( V_15 -> V_2 ,
L_1 ) ;
return - V_24 ;
}
F_7 ( V_18 -> V_25 , 0 ,
V_26 ,
V_22 -> V_27 ) ;
return 0 ;
}
static int F_8 ( struct V_17 * V_18 ,
struct V_28 * V_29 ,
struct V_19 * V_20 )
{
struct V_14 * V_15 = V_20 -> V_15 ;
struct V_21 * V_22 = F_5 ( V_15 ) ;
T_1 V_30 = F_9 ( V_15 , V_9 ) & 0x1FC ;
int V_31 ;
for ( V_31 = 0 ; V_31 < F_10 ( V_32 ) ; V_31 ++ ) {
if ( V_22 -> V_23 / F_11 ( V_29 ) ==
V_32 [ V_31 ] . V_33 )
break;
}
if ( V_31 == F_10 ( V_32 ) ) {
F_6 ( V_15 -> V_2 , L_2 ,
V_22 -> V_23 / F_11 ( V_29 ) ) ;
return - V_24 ;
}
switch ( F_12 ( V_29 ) ) {
case V_34 :
break;
case V_35 :
V_30 |= 0x0001 ;
break;
case V_36 :
V_30 |= 0x0002 ;
break;
case V_37 :
V_30 |= 0x0003 ;
break;
default:
F_13 ( V_15 -> V_2 , L_3 ,
F_12 ( V_29 ) ) ;
return - V_24 ;
}
F_13 ( V_15 -> V_2 , L_4 ,
F_12 ( V_29 ) ) ;
F_3 ( V_15 , V_9 , V_30 ) ;
return 0 ;
}
static int F_14 ( struct V_19 * V_38 ,
int V_39 , unsigned int V_40 , int V_41 )
{
struct V_14 * V_15 = V_38 -> V_15 ;
struct V_21 * V_22 = F_5 ( V_15 ) ;
F_13 ( V_15 -> V_2 , L_5 , V_40 ) ;
switch ( V_40 ) {
case 11289600 :
V_22 -> V_27 = & V_42 ;
V_22 -> V_23 = V_40 ;
return 0 ;
case 12288000 :
V_22 -> V_27 = & V_43 ;
V_22 -> V_23 = V_40 ;
return 0 ;
case 16384000 :
V_22 -> V_27 = & V_44 ;
V_22 -> V_23 = V_40 ;
return 0 ;
case 16934400 :
V_22 -> V_27 = & V_45 ;
V_22 -> V_23 = V_40 ;
return 0 ;
case 18432000 :
V_22 -> V_27 = & V_46 ;
V_22 -> V_23 = V_40 ;
return 0 ;
case 22579200 :
case 33868800 :
V_22 -> V_27 = & V_47 ;
V_22 -> V_23 = V_40 ;
return 0 ;
case 24576000 :
V_22 -> V_27 = & V_48 ;
V_22 -> V_23 = V_40 ;
return 0 ;
case 36864000 :
V_22 -> V_27 = & V_49 ;
V_22 -> V_23 = V_40 ;
return 0 ;
}
return - V_24 ;
}
static int F_15 ( struct V_19 * V_38 ,
unsigned int V_50 )
{
struct V_14 * V_15 = V_38 -> V_15 ;
T_1 V_30 = F_9 ( V_15 , V_9 ) & 0x1C3 ;
switch ( V_50 & V_51 ) {
case V_52 :
break;
default:
return - V_24 ;
}
switch ( V_50 & V_53 ) {
case V_54 :
V_30 |= 0x0008 ;
break;
case V_55 :
break;
case V_56 :
V_30 |= 0x0004 ;
break;
case V_57 :
V_30 |= 0x000C ;
break;
case V_58 :
V_30 |= 0x001C ;
break;
default:
return - V_24 ;
}
switch ( V_50 & V_59 ) {
case V_60 :
break;
case V_61 :
V_30 |= 0x0010 ;
break;
case V_62 :
V_30 |= 0x0020 ;
break;
case V_63 :
V_30 |= 0x0030 ;
break;
default:
return - V_24 ;
}
F_13 ( V_15 -> V_2 , L_6 ,
V_50 & V_53 ,
( ( V_50 & V_59 ) ) ) ;
F_3 ( V_15 , V_9 , V_30 ) ;
return 0 ;
}
static int F_16 ( struct V_14 * V_15 )
{
F_17 ( V_15 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 )
{
struct V_21 * V_22 = F_5 ( V_15 ) ;
int V_64 = 0 ;
V_64 = F_19 ( F_10 ( V_22 -> V_65 ) ,
V_22 -> V_65 ) ;
if ( V_64 != 0 ) {
F_6 ( V_15 -> V_2 , L_7 , V_64 ) ;
goto V_66;
}
V_64 = F_2 ( V_15 ) ;
if ( V_64 < 0 ) {
F_6 ( V_15 -> V_2 , L_8 ) ;
goto V_67;
}
F_20 ( V_15 , V_4 ,
V_68 , V_68 ) ;
F_20 ( V_15 , V_5 ,
V_69 , V_69 ) ;
F_20 ( V_15 , V_6 ,
V_70 , V_70 ) ;
F_20 ( V_15 , V_7 ,
V_71 , V_71 ) ;
F_13 ( V_15 -> V_2 , L_9 ) ;
return V_64 ;
V_67:
F_21 ( F_10 ( V_22 -> V_65 ) , V_22 -> V_65 ) ;
V_66:
return V_64 ;
}
static int F_22 ( struct V_14 * V_15 )
{
struct V_21 * V_22 = F_5 ( V_15 ) ;
F_21 ( F_10 ( V_22 -> V_65 ) , V_22 -> V_65 ) ;
return 0 ;
}
static int F_23 ( struct V_72 * V_73 ,
const struct V_74 * V_75 )
{
struct V_21 * V_22 ;
int V_64 , V_31 ;
V_22 = F_24 ( & V_73 -> V_2 , sizeof( struct V_21 ) ,
V_76 ) ;
if ( V_22 == NULL )
return - V_77 ;
for ( V_31 = 0 ; V_31 < F_10 ( V_22 -> V_65 ) ; V_31 ++ )
V_22 -> V_65 [ V_31 ] . V_78 = V_79 [ V_31 ] ;
V_64 = F_25 ( & V_73 -> V_2 , F_10 ( V_22 -> V_65 ) ,
V_22 -> V_65 ) ;
if ( V_64 != 0 ) {
F_6 ( & V_73 -> V_2 , L_10 , V_64 ) ;
return V_64 ;
}
V_22 -> V_80 = F_26 ( V_73 , & V_81 ) ;
if ( F_27 ( V_22 -> V_80 ) ) {
V_64 = F_28 ( V_22 -> V_80 ) ;
F_6 ( & V_73 -> V_2 , L_11 , V_64 ) ;
return V_64 ;
}
F_29 ( V_73 , V_22 ) ;
V_64 = F_30 ( & V_73 -> V_2 ,
& V_82 , & V_83 , 1 ) ;
return V_64 ;
}
static int F_31 ( struct V_72 * V_84 )
{
F_32 ( & V_84 -> V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_85 * V_86 )
{
struct V_21 * V_22 ;
int V_64 , V_31 ;
V_22 = F_24 ( & V_86 -> V_2 , sizeof( struct V_21 ) ,
V_76 ) ;
if ( V_22 == NULL )
return - V_77 ;
for ( V_31 = 0 ; V_31 < F_10 ( V_22 -> V_65 ) ; V_31 ++ )
V_22 -> V_65 [ V_31 ] . V_78 = V_79 [ V_31 ] ;
V_64 = F_25 ( & V_86 -> V_2 , F_10 ( V_22 -> V_65 ) ,
V_22 -> V_65 ) ;
if ( V_64 != 0 ) {
F_6 ( & V_86 -> V_2 , L_10 , V_64 ) ;
return V_64 ;
}
V_22 -> V_80 = F_34 ( V_86 , & V_81 ) ;
if ( F_27 ( V_22 -> V_80 ) ) {
V_64 = F_28 ( V_22 -> V_80 ) ;
F_6 ( & V_86 -> V_2 , L_11 , V_64 ) ;
return V_64 ;
}
F_35 ( V_86 , V_22 ) ;
V_64 = F_30 ( & V_86 -> V_2 ,
& V_82 , & V_83 , 1 ) ;
return V_64 ;
}
static int F_36 ( struct V_85 * V_86 )
{
F_32 ( & V_86 -> V_2 ) ;
return 0 ;
}
static int T_2 F_37 ( void )
{
int V_64 = 0 ;
#if F_38 ( V_87 )
V_64 = F_39 ( & V_88 ) ;
if ( V_64 != 0 )
F_40 ( L_12 , V_64 ) ;
#endif
#if F_41 ( V_89 )
V_64 = F_42 ( & V_90 ) ;
if ( V_64 != 0 ) {
F_43 ( V_91 L_13 ,
V_64 ) ;
}
#endif
return V_64 ;
}
static void T_3 F_44 ( void )
{
#if F_41 ( V_89 )
F_45 ( & V_90 ) ;
#endif
#if F_38 ( V_87 )
F_46 ( & V_88 ) ;
#endif
}
