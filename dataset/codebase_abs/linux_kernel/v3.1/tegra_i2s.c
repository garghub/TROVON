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
static void F_11 ( struct V_1 * V_2 , int V_24 )
{
char V_10 [] = V_25 L_2 ;
snprintf ( V_10 , sizeof( V_10 ) , V_25 L_3 , V_24 ) ;
V_2 -> V_26 = F_12 ( V_10 , V_27 , V_28 ,
V_2 , & V_29 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 )
F_14 ( V_2 -> V_26 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , int V_24 )
{
}
static inline void F_13 ( struct V_1 * V_2 )
{
}
static int F_15 ( struct V_30 * V_31 ,
unsigned int V_32 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
switch ( V_32 & V_33 ) {
case V_34 :
break;
default:
return - V_35 ;
}
V_2 -> V_36 &= ~ V_37 ;
switch ( V_32 & V_38 ) {
case V_39 :
V_2 -> V_36 |= V_37 ;
break;
case V_40 :
break;
default:
return - V_35 ;
}
V_2 -> V_36 &= ~ ( V_41 |
V_42 ) ;
switch ( V_32 & V_43 ) {
case V_44 :
V_2 -> V_36 |= V_45 ;
V_2 -> V_36 |= V_46 ;
break;
case V_47 :
V_2 -> V_36 |= V_45 ;
V_2 -> V_36 |= V_48 ;
break;
case V_49 :
V_2 -> V_36 |= V_50 ;
V_2 -> V_36 |= V_46 ;
break;
case V_51 :
V_2 -> V_36 |= V_52 ;
V_2 -> V_36 |= V_46 ;
break;
case V_53 :
V_2 -> V_36 |= V_54 ;
V_2 -> V_36 |= V_46 ;
break;
default:
return - V_35 ;
}
return 0 ;
}
static int F_17 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
struct V_30 * V_31 )
{
struct V_59 * V_60 = V_56 -> V_61 -> V_62 -> V_60 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_1 V_3 ;
int V_63 , V_64 , V_65 , V_66 , V_67 ;
V_2 -> V_36 &= ~ V_68 ;
switch ( F_18 ( V_58 ) ) {
case V_69 :
V_2 -> V_36 |= V_70 ;
V_64 = 16 ;
break;
case V_71 :
V_2 -> V_36 |= V_72 ;
V_64 = 24 ;
break;
case V_73 :
V_2 -> V_36 |= V_74 ;
V_64 = 32 ;
break;
default:
return - V_35 ;
}
V_65 = F_19 ( V_58 ) ;
V_66 = V_65 * F_20 ( V_58 ) * V_64 * 2 ;
V_63 = F_21 ( V_2 -> V_75 , V_66 ) ;
if ( V_63 ) {
F_22 ( V_60 , L_4 , V_63 ) ;
return V_63 ;
}
V_67 = ( V_66 / ( 2 * V_65 ) ) - 1 ;
if ( V_67 < 0 || V_67 > V_76 )
return - V_35 ;
V_3 = V_67 << V_77 ;
if ( V_66 % ( 2 * V_65 ) )
V_3 |= V_78 ;
if ( ! V_2 -> V_79 )
F_23 ( V_2 -> V_75 ) ;
F_1 ( V_2 , V_13 , V_3 ) ;
F_1 ( V_2 , V_14 ,
V_80 |
V_81 ) ;
if ( ! V_2 -> V_79 )
F_24 ( V_2 -> V_75 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_36 |= V_82 ;
F_1 ( V_2 , V_11 , V_2 -> V_36 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
V_2 -> V_36 &= ~ V_82 ;
F_1 ( V_2 , V_11 , V_2 -> V_36 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_36 |= V_83 ;
F_1 ( V_2 , V_11 , V_2 -> V_36 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
V_2 -> V_36 &= ~ V_83 ;
F_1 ( V_2 , V_11 , V_2 -> V_36 ) ;
}
static int F_29 ( struct V_55 * V_56 , int V_84 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
switch ( V_84 ) {
case V_85 :
case V_86 :
case V_87 :
if ( ! V_2 -> V_79 )
F_23 ( V_2 -> V_75 ) ;
V_2 -> V_79 ++ ;
if ( V_56 -> V_88 == V_89 )
F_25 ( V_2 ) ;
else
F_27 ( V_2 ) ;
break;
case V_90 :
case V_91 :
case V_92 :
if ( V_56 -> V_88 == V_89 )
F_26 ( V_2 ) ;
else
F_28 ( V_2 ) ;
V_2 -> V_79 -- ;
if ( ! V_2 -> V_79 )
F_24 ( V_2 -> V_75 ) ;
break;
default:
return - V_35 ;
}
return 0 ;
}
static int F_30 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
V_31 -> V_93 = & V_2 -> V_93 ;
V_31 -> V_94 = & V_2 -> V_94 ;
return 0 ;
}
static T_3 int F_31 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
struct V_97 * V_98 , * V_99 , * V_100 ;
int V_63 ;
if ( ( V_96 -> V_24 < 0 ) ||
( V_96 -> V_24 >= F_7 ( V_101 ) ) ) {
F_22 ( & V_96 -> V_60 , L_5 , V_96 -> V_24 ) ;
return - V_35 ;
}
V_63 = F_32 ( V_102 + V_96 -> V_24 ,
V_103 + V_96 -> V_24 ) ;
if ( V_63 ) {
F_22 ( & V_96 -> V_60 , L_6 ) ;
return V_63 ;
}
V_63 = F_33 ( V_104 + V_96 -> V_24 ,
V_105 + V_96 -> V_24 ) ;
if ( V_63 ) {
F_22 ( & V_96 -> V_60 , L_7 ) ;
return V_63 ;
}
V_2 = F_34 ( sizeof( struct V_1 ) , V_106 ) ;
if ( ! V_2 ) {
F_22 ( & V_96 -> V_60 , L_8 ) ;
V_63 = - V_107 ;
goto exit;
}
F_35 ( & V_96 -> V_60 , V_2 ) ;
V_2 -> V_75 = F_36 ( & V_96 -> V_60 , NULL ) ;
if ( F_37 ( V_2 -> V_75 ) ) {
F_22 ( & V_96 -> V_60 , L_9 ) ;
V_63 = F_38 ( V_2 -> V_75 ) ;
goto V_108;
}
V_98 = F_39 ( V_96 , V_109 , 0 ) ;
if ( ! V_98 ) {
F_22 ( & V_96 -> V_60 , L_10 ) ;
V_63 = - V_110 ;
goto V_111;
}
V_100 = F_39 ( V_96 , V_112 , 0 ) ;
if ( ! V_100 ) {
F_22 ( & V_96 -> V_60 , L_11 ) ;
V_63 = - V_110 ;
goto V_111;
}
V_99 = F_40 ( V_98 -> V_113 , F_41 ( V_98 ) ,
V_25 ) ;
if ( ! V_99 ) {
F_22 ( & V_96 -> V_60 , L_12 ) ;
V_63 = - V_114 ;
goto V_111;
}
V_2 -> V_5 = F_42 ( V_98 -> V_113 , F_41 ( V_98 ) ) ;
if ( ! V_2 -> V_5 ) {
F_22 ( & V_96 -> V_60 , L_13 ) ;
V_63 = - V_107 ;
goto V_115;
}
V_2 -> V_93 . V_116 = V_98 -> V_113 + V_117 ;
V_2 -> V_93 . V_118 = 4 ;
V_2 -> V_93 . V_119 = 32 ;
V_2 -> V_93 . V_120 = V_100 -> V_113 ;
V_2 -> V_94 . V_116 = V_98 -> V_113 + V_121 ;
V_2 -> V_94 . V_118 = 4 ;
V_2 -> V_94 . V_119 = 32 ;
V_2 -> V_94 . V_120 = V_100 -> V_113 ;
V_2 -> V_36 = V_122 ;
V_63 = F_43 ( & V_96 -> V_60 , & V_101 [ V_96 -> V_24 ] ) ;
if ( V_63 ) {
F_22 ( & V_96 -> V_60 , L_14 , V_63 ) ;
V_63 = - V_107 ;
goto V_123;
}
F_11 ( V_2 , V_96 -> V_24 ) ;
return 0 ;
V_123:
F_44 ( V_2 -> V_5 ) ;
V_115:
F_45 ( V_98 -> V_113 , F_41 ( V_98 ) ) ;
V_111:
F_46 ( V_2 -> V_75 ) ;
V_108:
F_47 ( V_2 ) ;
exit:
return V_63 ;
}
static int T_4 F_48 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_49 ( & V_96 -> V_60 ) ;
struct V_97 * V_124 ;
F_50 ( & V_96 -> V_60 ) ;
F_13 ( V_2 ) ;
F_44 ( V_2 -> V_5 ) ;
V_124 = F_39 ( V_96 , V_109 , 0 ) ;
F_45 ( V_124 -> V_113 , F_41 ( V_124 ) ) ;
F_46 ( V_2 -> V_75 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int T_5 F_51 ( void )
{
return F_52 ( & V_125 ) ;
}
static void T_6 F_53 ( void )
{
F_54 ( & V_125 ) ;
}
