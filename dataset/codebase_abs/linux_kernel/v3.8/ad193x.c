static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
if ( V_3 )
F_3 ( V_5 -> V_7 , V_8 ,
V_9 ,
V_9 ) ;
else
F_3 ( V_5 -> V_7 , V_8 ,
V_9 , 0 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_10 ,
unsigned int V_11 , int V_12 , int V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_14 ;
switch ( V_12 ) {
case 2 :
V_14 = V_15 ;
break;
case 4 :
V_14 = V_16 ;
break;
case 8 :
V_14 = V_17 ;
break;
case 16 :
V_14 = V_18 ;
break;
default:
return - V_19 ;
}
F_3 ( V_5 -> V_7 , V_20 ,
V_21 , V_14 << V_22 ) ;
F_3 ( V_5 -> V_7 , V_23 ,
V_24 , V_14 << V_25 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_26 ,
unsigned int V_27 )
{
struct V_4 * V_5 = F_2 ( V_26 -> V_6 ) ;
unsigned int V_28 = 0 ;
unsigned int V_29 = 0 ;
unsigned int V_30 = 0 ;
switch ( V_27 & V_31 ) {
case V_32 :
V_28 |= V_33 ;
break;
case V_34 :
V_28 |= V_35 ;
break;
default:
return - V_19 ;
}
switch ( V_27 & V_36 ) {
case V_37 :
break;
case V_38 :
V_29 |= V_39 ;
V_30 |= V_40 ;
break;
case V_41 :
V_29 |= V_42 ;
V_30 |= V_43 ;
break;
case V_44 :
V_29 |= V_39 ;
V_29 |= V_42 ;
V_30 |= V_40 ;
V_30 |= V_43 ;
break;
default:
return - V_19 ;
}
switch ( V_27 & V_45 ) {
case V_46 :
V_29 |= V_47 ;
V_29 |= V_48 ;
V_30 |= V_49 ;
V_30 |= V_50 ;
break;
case V_51 :
V_29 |= V_47 ;
V_30 |= V_49 ;
break;
case V_52 :
V_29 |= V_48 ;
V_30 |= V_50 ;
break;
case V_53 :
break;
default:
return - V_19 ;
}
F_3 ( V_5 -> V_7 , V_54 ,
V_55 , V_28 ) ;
F_3 ( V_5 -> V_7 , V_23 ,
V_56 , V_29 ) ;
F_3 ( V_5 -> V_7 , V_20 ,
V_57 , V_30 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_26 ,
int V_58 , unsigned int V_59 , int V_60 )
{
struct V_61 * V_6 = V_26 -> V_6 ;
struct V_4 * V_5 = F_2 ( V_6 ) ;
switch ( V_59 ) {
case 12288000 :
case 18432000 :
case 24576000 :
case 36864000 :
V_5 -> V_62 = V_59 ;
return 0 ;
}
return - V_19 ;
}
static int F_7 ( struct V_63 * V_64 ,
struct V_65 * V_66 ,
struct V_1 * V_2 )
{
int V_67 = 0 , V_68 = 0 ;
struct V_61 * V_6 = V_2 -> V_6 ;
struct V_4 * V_5 = F_2 ( V_6 ) ;
switch ( F_8 ( V_66 ) ) {
case V_69 :
V_67 = 3 ;
break;
case V_70 :
V_67 = 1 ;
break;
case V_71 :
case V_72 :
V_67 = 0 ;
break;
}
switch ( V_5 -> V_62 ) {
case 12288000 :
V_68 = V_73 ;
break;
case 18432000 :
V_68 = V_74 ;
break;
case 24576000 :
V_68 = V_75 ;
break;
case 36864000 :
V_68 = V_76 ;
break;
}
F_3 ( V_5 -> V_7 , V_77 ,
V_78 , V_68 ) ;
F_3 ( V_5 -> V_7 , V_8 ,
V_79 ,
V_67 << V_80 ) ;
F_3 ( V_5 -> V_7 , V_54 ,
V_81 , V_67 ) ;
return 0 ;
}
static int F_9 ( struct V_61 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
int V_82 ;
V_6 -> V_83 = V_5 -> V_7 ;
V_82 = F_10 ( V_6 , 0 , 0 , V_84 ) ;
if ( V_82 < 0 ) {
F_11 ( V_6 -> V_85 , L_1 , V_82 ) ;
return V_82 ;
}
F_12 ( V_5 -> V_7 , V_86 , 0x0 ) ;
F_12 ( V_5 -> V_7 , V_8 , 0x1A ) ;
F_12 ( V_5 -> V_7 , V_87 , 0x41 ) ;
F_12 ( V_5 -> V_7 , V_88 , 0x3 ) ;
F_12 ( V_5 -> V_7 , V_54 , 0x43 ) ;
F_12 ( V_5 -> V_7 , V_77 , 0x99 ) ;
F_12 ( V_5 -> V_7 , V_89 , 0x04 ) ;
return V_82 ;
}
static bool F_13 ( struct V_90 * V_85 , unsigned int V_91 )
{
return false ;
}
static int F_14 ( struct V_92 * V_93 )
{
struct V_4 * V_5 ;
V_5 = F_15 ( & V_93 -> V_85 , sizeof( struct V_4 ) ,
V_94 ) ;
if ( V_5 == NULL )
return - V_95 ;
V_5 -> V_7 = F_16 ( V_93 , & V_96 ) ;
if ( F_17 ( V_5 -> V_7 ) )
return F_18 ( V_5 -> V_7 ) ;
F_19 ( V_93 , V_5 ) ;
return F_20 ( & V_93 -> V_85 , & V_97 ,
& V_98 , 1 ) ;
}
static int F_21 ( struct V_92 * V_93 )
{
F_22 ( & V_93 -> V_85 ) ;
return 0 ;
}
static int F_23 ( struct V_99 * V_100 ,
const struct V_101 * V_102 )
{
struct V_4 * V_5 ;
V_5 = F_15 ( & V_100 -> V_85 , sizeof( struct V_4 ) ,
V_94 ) ;
if ( V_5 == NULL )
return - V_95 ;
V_5 -> V_7 = F_24 ( V_100 , & V_103 ) ;
if ( F_17 ( V_5 -> V_7 ) )
return F_18 ( V_5 -> V_7 ) ;
F_25 ( V_100 , V_5 ) ;
return F_20 ( & V_100 -> V_85 , & V_97 ,
& V_98 , 1 ) ;
}
static int F_26 ( struct V_99 * V_100 )
{
F_22 ( & V_100 -> V_85 ) ;
return 0 ;
}
static int T_1 F_27 ( void )
{
int V_82 ;
#if F_28 ( V_104 ) || F_28 ( V_105 )
V_82 = F_29 ( & V_106 ) ;
if ( V_82 != 0 ) {
F_30 ( V_107 L_2 ,
V_82 ) ;
}
#endif
#if F_28 ( V_108 )
V_82 = F_31 ( & V_109 ) ;
if ( V_82 != 0 ) {
F_30 ( V_107 L_3 ,
V_82 ) ;
}
#endif
return V_82 ;
}
static void T_2 F_32 ( void )
{
#if F_28 ( V_108 )
F_33 ( & V_109 ) ;
#endif
#if F_28 ( V_104 ) || F_28 ( V_105 )
F_34 ( & V_106 ) ;
#endif
}
