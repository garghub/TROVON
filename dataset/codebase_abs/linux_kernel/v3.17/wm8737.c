static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_5 * V_6 )
{
return F_3 ( V_6 , V_4 , 0 ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
F_5 ( V_8 , V_9 ,
F_6 ( V_9 ) ) ;
F_7 ( V_8 , V_10 , F_6 ( V_10 ) ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = V_16 -> V_6 ;
struct V_17 * V_18 = F_9 ( V_6 ) ;
int V_19 ;
T_1 V_20 = 0 ;
T_1 V_21 = 0 ;
for ( V_19 = 0 ; V_19 < F_6 ( V_22 ) ; V_19 ++ ) {
if ( V_22 [ V_19 ] . V_23 != F_10 ( V_14 ) )
continue;
if ( V_22 [ V_19 ] . V_24 == V_18 -> V_24 )
break;
if ( V_22 [ V_19 ] . V_24 == V_18 -> V_24 * 2 ) {
V_20 |= V_25 ;
break;
}
}
if ( V_19 == F_6 ( V_22 ) ) {
F_11 ( V_6 -> V_2 , L_1 ,
V_18 -> V_24 , F_10 ( V_14 ) ) ;
return - V_26 ;
}
V_20 |= V_22 [ V_19 ] . V_27 | ( V_22 [ V_19 ] . V_28 << V_29 ) ;
switch ( F_12 ( V_14 ) ) {
case 16 :
break;
case 20 :
V_21 |= 0x8 ;
break;
case 24 :
V_21 |= 0x10 ;
break;
case 32 :
V_21 |= 0x18 ;
break;
default:
return - V_26 ;
}
F_13 ( V_6 , V_30 , V_31 , V_21 ) ;
F_13 ( V_6 , V_32 ,
V_33 | V_25 | V_34 ,
V_20 ) ;
return 0 ;
}
static int F_14 ( struct V_15 * V_35 ,
int V_36 , unsigned int V_37 , int V_38 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
struct V_17 * V_18 = F_9 ( V_6 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_6 ( V_22 ) ; V_19 ++ ) {
if ( V_37 == V_22 [ V_19 ] . V_24 ||
V_37 == V_22 [ V_19 ] . V_24 * 2 ) {
V_18 -> V_24 = V_37 ;
return 0 ;
}
}
F_11 ( V_6 -> V_2 , L_2 , V_37 ) ;
return - V_26 ;
}
static int F_15 ( struct V_15 * V_35 ,
unsigned int V_39 )
{
struct V_5 * V_6 = V_35 -> V_6 ;
T_1 V_21 = 0 ;
switch ( V_39 & V_40 ) {
case V_41 :
V_21 |= V_42 ;
break;
case V_43 :
break;
default:
return - V_26 ;
}
switch ( V_39 & V_44 ) {
case V_45 :
V_21 |= 0x2 ;
break;
case V_46 :
break;
case V_47 :
V_21 |= 0x1 ;
break;
case V_48 :
V_21 |= 0x3 ;
break;
case V_49 :
V_21 |= 0x13 ;
break;
default:
return - V_26 ;
}
switch ( V_39 & V_50 ) {
case V_51 :
break;
case V_52 :
V_21 |= V_53 ;
break;
default:
return - V_26 ;
}
F_13 ( V_6 , V_30 ,
V_54 | V_53 | V_42 , V_21 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
enum V_55 V_56 )
{
struct V_17 * V_18 = F_9 ( V_6 ) ;
int V_57 ;
switch ( V_56 ) {
case V_58 :
break;
case V_59 :
F_13 ( V_6 , V_60 ,
V_61 , 0 ) ;
break;
case V_62 :
if ( V_6 -> V_8 . V_63 == V_64 ) {
V_57 = F_17 ( F_6 ( V_18 -> V_65 ) ,
V_18 -> V_65 ) ;
if ( V_57 != 0 ) {
F_11 ( V_6 -> V_2 ,
L_3 ,
V_57 ) ;
return V_57 ;
}
F_18 ( V_18 -> V_66 ) ;
F_13 ( V_6 , V_60 ,
V_61 , 0x4 ) ;
F_13 ( V_6 , V_67 ,
V_68 |
V_69 ,
V_68 |
V_69 ) ;
F_19 ( 500 ) ;
}
F_13 ( V_6 , V_60 ,
V_61 , 2 ) ;
break;
case V_64 :
F_13 ( V_6 , V_67 ,
V_68 | V_69 , 0 ) ;
F_20 ( F_6 ( V_18 -> V_65 ) ,
V_18 -> V_65 ) ;
break;
}
V_6 -> V_8 . V_63 = V_56 ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 )
{
F_16 ( V_6 , V_64 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 )
{
F_16 ( V_6 , V_62 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 )
{
struct V_17 * V_18 = F_9 ( V_6 ) ;
int V_57 ;
V_57 = F_17 ( F_6 ( V_18 -> V_65 ) ,
V_18 -> V_65 ) ;
if ( V_57 != 0 ) {
F_11 ( V_6 -> V_2 , L_3 , V_57 ) ;
goto V_70;
}
V_57 = F_2 ( V_6 ) ;
if ( V_57 < 0 ) {
F_11 ( V_6 -> V_2 , L_4 ) ;
goto V_71;
}
F_13 ( V_6 , V_72 , V_73 ,
V_73 ) ;
F_13 ( V_6 , V_74 , V_75 ,
V_75 ) ;
F_16 ( V_6 , V_62 ) ;
F_20 ( F_6 ( V_18 -> V_65 ) , V_18 -> V_65 ) ;
F_24 ( V_6 , V_76 ,
F_6 ( V_76 ) ) ;
F_4 ( V_6 ) ;
return 0 ;
V_71:
F_20 ( F_6 ( V_18 -> V_65 ) , V_18 -> V_65 ) ;
V_70:
return V_57 ;
}
static int F_25 ( struct V_5 * V_6 )
{
F_16 ( V_6 , V_64 ) ;
return 0 ;
}
static int F_26 ( struct V_77 * V_78 ,
const struct V_79 * V_80 )
{
struct V_17 * V_18 ;
int V_57 , V_19 ;
V_18 = F_27 ( & V_78 -> V_2 , sizeof( struct V_17 ) ,
V_81 ) ;
if ( V_18 == NULL )
return - V_82 ;
for ( V_19 = 0 ; V_19 < F_6 ( V_18 -> V_65 ) ; V_19 ++ )
V_18 -> V_65 [ V_19 ] . V_83 = V_84 [ V_19 ] ;
V_57 = F_28 ( & V_78 -> V_2 , F_6 ( V_18 -> V_65 ) ,
V_18 -> V_65 ) ;
if ( V_57 != 0 ) {
F_11 ( & V_78 -> V_2 , L_5 , V_57 ) ;
return V_57 ;
}
V_18 -> V_66 = F_29 ( V_78 , & V_85 ) ;
if ( F_30 ( V_18 -> V_66 ) )
return F_31 ( V_18 -> V_66 ) ;
F_32 ( V_78 , V_18 ) ;
V_57 = F_33 ( & V_78 -> V_2 ,
& V_86 , & V_87 , 1 ) ;
return V_57 ;
}
static int F_34 ( struct V_77 * V_88 )
{
F_35 ( & V_88 -> V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_89 * V_90 )
{
struct V_17 * V_18 ;
int V_57 , V_19 ;
V_18 = F_27 ( & V_90 -> V_2 , sizeof( struct V_17 ) ,
V_81 ) ;
if ( V_18 == NULL )
return - V_82 ;
for ( V_19 = 0 ; V_19 < F_6 ( V_18 -> V_65 ) ; V_19 ++ )
V_18 -> V_65 [ V_19 ] . V_83 = V_84 [ V_19 ] ;
V_57 = F_28 ( & V_90 -> V_2 , F_6 ( V_18 -> V_65 ) ,
V_18 -> V_65 ) ;
if ( V_57 != 0 ) {
F_11 ( & V_90 -> V_2 , L_5 , V_57 ) ;
return V_57 ;
}
V_18 -> V_66 = F_37 ( V_90 , & V_85 ) ;
if ( F_30 ( V_18 -> V_66 ) )
return F_31 ( V_18 -> V_66 ) ;
F_38 ( V_90 , V_18 ) ;
V_57 = F_33 ( & V_90 -> V_2 ,
& V_86 , & V_87 , 1 ) ;
return V_57 ;
}
static int F_39 ( struct V_89 * V_90 )
{
F_35 ( & V_90 -> V_2 ) ;
return 0 ;
}
static int T_2 F_40 ( void )
{
int V_57 ;
#if F_41 ( V_91 )
V_57 = F_42 ( & V_92 ) ;
if ( V_57 != 0 ) {
F_43 ( V_93 L_6 ,
V_57 ) ;
}
#endif
#if F_44 ( V_94 )
V_57 = F_45 ( & V_95 ) ;
if ( V_57 != 0 ) {
F_43 ( V_93 L_7 ,
V_57 ) ;
}
#endif
return 0 ;
}
static void T_3 F_46 ( void )
{
#if F_44 ( V_94 )
F_47 ( & V_95 ) ;
#endif
#if F_41 ( V_91 )
F_48 ( & V_92 ) ;
#endif
}
