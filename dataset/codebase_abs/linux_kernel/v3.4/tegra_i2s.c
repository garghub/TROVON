static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 , void * V_8 )
{
#define F_6 ( T_2 ) { r, #r }
static const struct {
int V_9 ;
const char * V_10 ;
} V_5 [] = {
F_6 ( V_11 ) ,
F_6 ( V_12 ) ,
F_6 ( V_13 ) ,
F_6 ( V_14 ) ,
F_6 ( V_15 ) ,
F_6 ( V_16 ) ,
F_6 ( V_17 ) ,
F_6 ( V_18 ) ,
} ;
#undef F_6
struct V_1 * V_2 = V_7 -> V_19 ;
int V_20 ;
F_7 ( V_2 -> V_21 ) ;
for ( V_20 = 0 ; V_20 < F_8 ( V_5 ) ; V_20 ++ ) {
T_1 V_4 = F_3 ( V_2 , V_5 [ V_20 ] . V_9 ) ;
F_9 ( V_7 , L_1 , V_5 [ V_20 ] . V_10 , V_4 ) ;
}
F_10 ( V_2 -> V_21 ) ;
return 0 ;
}
static int F_11 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
return F_12 ( V_23 , F_5 , V_22 -> V_24 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_25 = F_14 ( V_2 -> V_26 . V_10 , V_27 ,
V_28 , V_2 ,
& V_29 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 )
F_16 ( V_2 -> V_25 ) ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
}
static inline void F_15 ( struct V_1 * V_2 )
{
}
static int F_17 ( struct V_30 * V_26 ,
unsigned int V_31 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
switch ( V_31 & V_32 ) {
case V_33 :
break;
default:
return - V_34 ;
}
V_2 -> V_35 &= ~ V_36 ;
switch ( V_31 & V_37 ) {
case V_38 :
V_2 -> V_35 |= V_36 ;
break;
case V_39 :
break;
default:
return - V_34 ;
}
V_2 -> V_35 &= ~ ( V_40 |
V_41 ) ;
switch ( V_31 & V_42 ) {
case V_43 :
V_2 -> V_35 |= V_44 ;
V_2 -> V_35 |= V_45 ;
break;
case V_46 :
V_2 -> V_35 |= V_44 ;
V_2 -> V_35 |= V_47 ;
break;
case V_48 :
V_2 -> V_35 |= V_49 ;
V_2 -> V_35 |= V_45 ;
break;
case V_50 :
V_2 -> V_35 |= V_51 ;
V_2 -> V_35 |= V_45 ;
break;
case V_52 :
V_2 -> V_35 |= V_53 ;
V_2 -> V_35 |= V_45 ;
break;
default:
return - V_34 ;
}
return 0 ;
}
static int F_19 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_30 * V_26 )
{
struct V_58 * V_59 = V_55 -> V_60 -> V_61 -> V_59 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
T_1 V_3 ;
int V_62 , V_63 , V_64 , V_65 , V_66 ;
V_2 -> V_35 &= ~ V_67 ;
switch ( F_20 ( V_57 ) ) {
case V_68 :
V_2 -> V_35 |= V_69 ;
V_63 = 16 ;
break;
case V_70 :
V_2 -> V_35 |= V_71 ;
V_63 = 24 ;
break;
case V_72 :
V_2 -> V_35 |= V_73 ;
V_63 = 32 ;
break;
default:
return - V_34 ;
}
V_64 = F_21 ( V_57 ) ;
V_65 = V_64 * F_22 ( V_57 ) * V_63 * 2 ;
V_62 = F_23 ( V_2 -> V_21 , V_65 ) ;
if ( V_62 ) {
F_24 ( V_59 , L_2 , V_62 ) ;
return V_62 ;
}
V_66 = ( V_65 / ( 2 * V_64 ) ) - 1 ;
if ( V_66 < 0 || V_66 > V_74 )
return - V_34 ;
V_3 = V_66 << V_75 ;
if ( V_65 % ( 2 * V_64 ) )
V_3 |= V_76 ;
if ( ! V_2 -> V_77 )
F_7 ( V_2 -> V_21 ) ;
F_1 ( V_2 , V_13 , V_3 ) ;
F_1 ( V_2 , V_14 ,
V_78 |
V_79 ) ;
if ( ! V_2 -> V_77 )
F_10 ( V_2 -> V_21 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_35 |= V_80 ;
F_1 ( V_2 , V_11 , V_2 -> V_35 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
V_2 -> V_35 &= ~ V_80 ;
F_1 ( V_2 , V_11 , V_2 -> V_35 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_35 |= V_81 ;
F_1 ( V_2 , V_11 , V_2 -> V_35 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
V_2 -> V_35 &= ~ V_81 ;
F_1 ( V_2 , V_11 , V_2 -> V_35 ) ;
}
static int F_29 ( struct V_54 * V_55 , int V_82 ,
struct V_30 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
switch ( V_82 ) {
case V_83 :
case V_84 :
case V_85 :
if ( ! V_2 -> V_77 )
F_7 ( V_2 -> V_21 ) ;
V_2 -> V_77 ++ ;
if ( V_55 -> V_86 == V_87 )
F_25 ( V_2 ) ;
else
F_27 ( V_2 ) ;
break;
case V_88 :
case V_89 :
case V_90 :
if ( V_55 -> V_86 == V_87 )
F_26 ( V_2 ) ;
else
F_28 ( V_2 ) ;
V_2 -> V_77 -- ;
if ( ! V_2 -> V_77 )
F_10 ( V_2 -> V_21 ) ;
break;
default:
return - V_34 ;
}
return 0 ;
}
static int F_30 ( struct V_30 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_26 -> V_91 = & V_2 -> V_91 ;
V_26 -> V_92 = & V_2 -> V_92 ;
return 0 ;
}
static T_3 int F_31 ( struct V_93 * V_94 )
{
struct V_1 * V_2 ;
struct V_95 * V_96 , * V_97 , * V_98 ;
T_1 V_99 [ 2 ] ;
T_1 V_100 ;
int V_62 ;
V_2 = F_32 ( & V_94 -> V_59 , sizeof( struct V_1 ) , V_101 ) ;
if ( ! V_2 ) {
F_24 ( & V_94 -> V_59 , L_3 ) ;
V_62 = - V_102 ;
goto V_103;
}
F_33 ( & V_94 -> V_59 , V_2 ) ;
V_2 -> V_26 = V_104 ;
V_2 -> V_26 . V_10 = F_34 ( & V_94 -> V_59 ) ;
V_2 -> V_21 = F_35 ( & V_94 -> V_59 , NULL ) ;
if ( F_36 ( V_2 -> V_21 ) ) {
F_24 ( & V_94 -> V_59 , L_4 ) ;
V_62 = F_37 ( V_2 -> V_21 ) ;
goto V_103;
}
V_96 = F_38 ( V_94 , V_105 , 0 ) ;
if ( ! V_96 ) {
F_24 ( & V_94 -> V_59 , L_5 ) ;
V_62 = - V_106 ;
goto V_107;
}
V_98 = F_38 ( V_94 , V_108 , 0 ) ;
if ( ! V_98 ) {
if ( F_39 ( V_94 -> V_59 . V_109 ,
L_6 ,
V_99 , 2 ) < 0 ) {
F_24 ( & V_94 -> V_59 , L_7 ) ;
V_62 = - V_106 ;
goto V_107;
}
V_100 = V_99 [ 1 ] ;
} else {
V_100 = V_98 -> V_110 ;
}
V_97 = F_40 ( & V_94 -> V_59 , V_96 -> V_110 ,
F_41 ( V_96 ) , V_111 ) ;
if ( ! V_97 ) {
F_24 ( & V_94 -> V_59 , L_8 ) ;
V_62 = - V_112 ;
goto V_107;
}
V_2 -> V_5 = F_42 ( & V_94 -> V_59 , V_96 -> V_110 , F_41 ( V_96 ) ) ;
if ( ! V_2 -> V_5 ) {
F_24 ( & V_94 -> V_59 , L_9 ) ;
V_62 = - V_102 ;
goto V_107;
}
V_2 -> V_91 . V_113 = V_96 -> V_110 + V_114 ;
V_2 -> V_91 . V_115 = 4 ;
V_2 -> V_91 . V_116 = 32 ;
V_2 -> V_91 . V_117 = V_100 ;
V_2 -> V_92 . V_113 = V_96 -> V_110 + V_118 ;
V_2 -> V_92 . V_115 = 4 ;
V_2 -> V_92 . V_116 = 32 ;
V_2 -> V_92 . V_117 = V_100 ;
V_2 -> V_35 = V_119 ;
V_62 = F_43 ( & V_94 -> V_59 , & V_2 -> V_26 ) ;
if ( V_62 ) {
F_24 ( & V_94 -> V_59 , L_10 , V_62 ) ;
V_62 = - V_102 ;
goto V_107;
}
F_13 ( V_2 ) ;
return 0 ;
V_107:
F_44 ( V_2 -> V_21 ) ;
V_103:
return V_62 ;
}
static int T_4 F_45 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_46 ( & V_94 -> V_59 ) ;
F_47 ( & V_94 -> V_59 ) ;
F_15 ( V_2 ) ;
F_44 ( V_2 -> V_21 ) ;
return 0 ;
}
