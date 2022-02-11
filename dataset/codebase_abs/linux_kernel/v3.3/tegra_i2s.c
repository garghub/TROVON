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
for ( V_20 = 0 ; V_20 < F_7 ( V_5 ) ; V_20 ++ ) {
T_1 V_4 = F_3 ( V_2 , V_5 [ V_20 ] . V_9 ) ;
F_8 ( V_7 , L_1 , V_5 [ V_20 ] . V_10 , V_4 ) ;
}
return 0 ;
}
static int F_9 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_10 ( V_22 , F_5 , V_21 -> V_23 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_24 = F_12 ( V_2 -> V_25 . V_10 , V_26 ,
V_27 , V_2 ,
& V_28 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 )
F_14 ( V_2 -> V_24 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , int V_29 )
{
}
static inline void F_13 ( struct V_1 * V_2 )
{
}
static int F_15 ( struct V_30 * V_25 ,
unsigned int V_31 )
{
struct V_1 * V_2 = F_16 ( V_25 ) ;
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
static int F_17 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_30 * V_25 )
{
struct V_58 * V_59 = V_55 -> V_60 -> V_61 -> V_59 ;
struct V_1 * V_2 = F_16 ( V_25 ) ;
T_1 V_3 ;
int V_62 , V_63 , V_64 , V_65 , V_66 ;
V_2 -> V_35 &= ~ V_67 ;
switch ( F_18 ( V_57 ) ) {
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
V_64 = F_19 ( V_57 ) ;
V_65 = V_64 * F_20 ( V_57 ) * V_63 * 2 ;
V_62 = F_21 ( V_2 -> V_74 , V_65 ) ;
if ( V_62 ) {
F_22 ( V_59 , L_2 , V_62 ) ;
return V_62 ;
}
V_66 = ( V_65 / ( 2 * V_64 ) ) - 1 ;
if ( V_66 < 0 || V_66 > V_75 )
return - V_34 ;
V_3 = V_66 << V_76 ;
if ( V_65 % ( 2 * V_64 ) )
V_3 |= V_77 ;
if ( ! V_2 -> V_78 )
F_23 ( V_2 -> V_74 ) ;
F_1 ( V_2 , V_13 , V_3 ) ;
F_1 ( V_2 , V_14 ,
V_79 |
V_80 ) ;
if ( ! V_2 -> V_78 )
F_24 ( V_2 -> V_74 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_35 |= V_81 ;
F_1 ( V_2 , V_11 , V_2 -> V_35 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
V_2 -> V_35 &= ~ V_81 ;
F_1 ( V_2 , V_11 , V_2 -> V_35 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_35 |= V_82 ;
F_1 ( V_2 , V_11 , V_2 -> V_35 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
V_2 -> V_35 &= ~ V_82 ;
F_1 ( V_2 , V_11 , V_2 -> V_35 ) ;
}
static int F_29 ( struct V_54 * V_55 , int V_83 ,
struct V_30 * V_25 )
{
struct V_1 * V_2 = F_16 ( V_25 ) ;
switch ( V_83 ) {
case V_84 :
case V_85 :
case V_86 :
if ( ! V_2 -> V_78 )
F_23 ( V_2 -> V_74 ) ;
V_2 -> V_78 ++ ;
if ( V_55 -> V_87 == V_88 )
F_25 ( V_2 ) ;
else
F_27 ( V_2 ) ;
break;
case V_89 :
case V_90 :
case V_91 :
if ( V_55 -> V_87 == V_88 )
F_26 ( V_2 ) ;
else
F_28 ( V_2 ) ;
V_2 -> V_78 -- ;
if ( ! V_2 -> V_78 )
F_24 ( V_2 -> V_74 ) ;
break;
default:
return - V_34 ;
}
return 0 ;
}
static int F_30 ( struct V_30 * V_25 )
{
struct V_1 * V_2 = F_16 ( V_25 ) ;
V_25 -> V_92 = & V_2 -> V_92 ;
V_25 -> V_93 = & V_2 -> V_93 ;
return 0 ;
}
static T_3 int F_31 ( struct V_94 * V_95 )
{
struct V_1 * V_2 ;
struct V_96 * V_97 , * V_98 , * V_99 ;
T_1 V_100 [ 2 ] ;
T_1 V_101 ;
int V_62 ;
V_2 = F_32 ( & V_95 -> V_59 , sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_2 ) {
F_22 ( & V_95 -> V_59 , L_3 ) ;
V_62 = - V_103 ;
goto V_104;
}
F_33 ( & V_95 -> V_59 , V_2 ) ;
V_2 -> V_25 = V_105 ;
V_2 -> V_25 . V_10 = F_34 ( & V_95 -> V_59 ) ;
V_2 -> V_74 = F_35 ( & V_95 -> V_59 , NULL ) ;
if ( F_36 ( V_2 -> V_74 ) ) {
F_22 ( & V_95 -> V_59 , L_4 ) ;
V_62 = F_37 ( V_2 -> V_74 ) ;
goto V_104;
}
V_97 = F_38 ( V_95 , V_106 , 0 ) ;
if ( ! V_97 ) {
F_22 ( & V_95 -> V_59 , L_5 ) ;
V_62 = - V_107 ;
goto V_108;
}
V_99 = F_38 ( V_95 , V_109 , 0 ) ;
if ( ! V_99 ) {
if ( F_39 ( V_95 -> V_59 . V_110 ,
L_6 ,
V_100 , 2 ) < 0 ) {
F_22 ( & V_95 -> V_59 , L_7 ) ;
V_62 = - V_107 ;
goto V_108;
}
V_101 = V_100 [ 1 ] ;
} else {
V_101 = V_99 -> V_111 ;
}
V_98 = F_40 ( & V_95 -> V_59 , V_97 -> V_111 ,
F_41 ( V_97 ) , V_112 ) ;
if ( ! V_98 ) {
F_22 ( & V_95 -> V_59 , L_8 ) ;
V_62 = - V_113 ;
goto V_108;
}
V_2 -> V_5 = F_42 ( & V_95 -> V_59 , V_97 -> V_111 , F_41 ( V_97 ) ) ;
if ( ! V_2 -> V_5 ) {
F_22 ( & V_95 -> V_59 , L_9 ) ;
V_62 = - V_103 ;
goto V_108;
}
V_2 -> V_92 . V_114 = V_97 -> V_111 + V_115 ;
V_2 -> V_92 . V_116 = 4 ;
V_2 -> V_92 . V_117 = 32 ;
V_2 -> V_92 . V_118 = V_101 ;
V_2 -> V_93 . V_114 = V_97 -> V_111 + V_119 ;
V_2 -> V_93 . V_116 = 4 ;
V_2 -> V_93 . V_117 = 32 ;
V_2 -> V_93 . V_118 = V_101 ;
V_2 -> V_35 = V_120 ;
V_62 = F_43 ( & V_95 -> V_59 , & V_2 -> V_25 ) ;
if ( V_62 ) {
F_22 ( & V_95 -> V_59 , L_10 , V_62 ) ;
V_62 = - V_103 ;
goto V_108;
}
F_11 ( V_2 ) ;
return 0 ;
V_108:
F_44 ( V_2 -> V_74 ) ;
V_104:
return V_62 ;
}
static int T_4 F_45 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_46 ( & V_95 -> V_59 ) ;
F_47 ( & V_95 -> V_59 ) ;
F_13 ( V_2 ) ;
F_44 ( V_2 -> V_74 ) ;
return 0 ;
}
