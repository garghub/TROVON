static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_6 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_7 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_8 ;
}
static inline void F_6 ( struct V_9 * V_10 , T_1 V_11 , T_1 V_12 , int V_13 )
{
void T_2 * V_14 = V_10 -> V_15 + ( V_13 & ~ 0x3 ) ;
T_1 V_16 = ( V_13 & 0x3 ) * 8 ;
F_7 ( ( ( F_8 ( V_14 ) & ~ ( V_11 << V_16 ) ) | ( V_12 << V_16 ) ) , V_14 ) ;
}
static T_1 F_9 ( struct V_9 * V_10 , int V_13 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_21 * V_22 = & V_19 -> V_22 ;
T_1 V_12 = F_8 ( V_10 -> V_15 + V_13 ) ;
if ( F_11 ( ( V_13 == V_23 )
&& F_12 ( V_22 -> V_24 ) ) ) {
if ( F_13 ( V_22 -> V_24 ) )
V_12 &= ~ V_25 ;
else
V_12 |= V_25 ;
}
if ( F_11 ( V_13 == V_26 ) ) {
if ( V_12 & V_27 ) {
V_12 &= ~ V_27 ;
V_12 |= V_28 ;
}
}
if ( F_11 ( V_13 == V_29 ) ) {
if ( V_12 & V_30 ) {
V_12 &= ~ V_30 ;
V_12 |= V_31 ;
}
}
return V_12 ;
}
static void F_14 ( struct V_9 * V_10 , T_1 V_12 , int V_13 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_21 * V_22 = & V_19 -> V_22 ;
T_1 V_2 ;
if ( F_11 ( V_13 == V_32 || V_13 == V_33 ) ) {
if ( V_22 -> V_34 == V_35 )
V_12 &= ~ ( V_36 | V_37 ) ;
if ( V_12 & V_38 ) {
V_2 = F_8 ( V_10 -> V_15 + V_39 ) ;
V_2 &= ~ V_40 ;
F_7 ( V_2 , V_10 -> V_15 + V_39 ) ;
V_2 |= V_40 ;
F_7 ( V_2 , V_10 -> V_15 + V_39 ) ;
}
}
if ( F_11 ( ( V_19 -> V_41 & V_42 )
&& ( V_13 == V_29 )
&& ( V_12 & V_43 ) ) ) {
T_1 V_44 ;
V_44 = F_8 ( V_10 -> V_15 + V_45 ) ;
V_44 &= ~ V_46 ;
F_7 ( V_44 , V_10 -> V_15 + V_45 ) ;
}
if ( F_11 ( V_13 == V_32 || V_13 == V_33 ) ) {
if ( V_12 & V_31 ) {
V_12 &= ~ V_31 ;
V_12 |= V_30 ;
}
}
F_7 ( V_12 , V_10 -> V_15 + V_13 ) ;
}
static T_3 F_15 ( struct V_9 * V_10 , int V_13 )
{
if ( F_11 ( V_13 == V_47 ) ) {
T_3 V_12 = F_16 ( V_10 -> V_15 + ( V_13 ^ 2 ) ) ;
if ( ( V_12 & V_48 ) == 3 )
return -- V_12 ;
}
return F_16 ( V_10 -> V_15 + V_13 ) ;
}
static void F_17 ( struct V_9 * V_10 , T_3 V_12 , int V_13 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
switch ( V_13 ) {
case V_49 :
if ( ( V_19 -> V_41 & V_42 )
&& ( V_10 -> V_50 -> V_51 == V_52 )
&& ( V_10 -> V_50 -> V_2 -> V_53 > 1 )
&& ( V_10 -> V_50 -> V_2 -> V_41 & V_54 ) ) {
T_1 V_44 ;
V_44 = F_8 ( V_10 -> V_15 + V_45 ) ;
V_44 |= V_46 ;
F_7 ( V_44 , V_10 -> V_15 + V_45 ) ;
}
V_19 -> V_55 = V_12 ;
return;
case V_56 :
if ( ( V_10 -> V_50 -> V_51 == V_57 )
&& ( V_19 -> V_41 & V_42 ) )
V_12 |= V_58 ;
if ( F_5 ( V_19 ) ) {
T_1 V_59 = F_8 ( V_10 -> V_15 + V_60 ) ;
V_59 = V_19 -> V_55 | ( V_59 & 0xffff0000 ) ;
F_7 ( V_59 , V_10 -> V_15 + V_60 ) ;
F_7 ( V_12 << 16 ,
V_10 -> V_15 + V_49 ) ;
} else {
F_7 ( V_12 << 16 | V_19 -> V_55 ,
V_10 -> V_15 + V_49 ) ;
}
return;
case V_61 :
V_12 &= ~ F_18 ( 0x7 , 0 ) ;
break;
}
F_6 ( V_10 , 0xffff , V_12 , V_13 ) ;
}
static void F_19 ( struct V_9 * V_10 , T_4 V_12 , int V_13 )
{
T_1 V_62 ;
switch ( V_13 ) {
case V_63 :
return;
case V_39 :
V_62 = V_12 & ( V_64 | \
V_65 | \
V_40 ) ;
V_62 |= V_66 ;
V_62 |= ( V_12 & V_67 ) << 5 ;
F_6 ( V_10 , 0xffff , V_62 , V_13 ) ;
return;
}
F_6 ( V_10 , 0xff , V_12 , V_13 ) ;
if ( ( V_13 == V_68 ) && ( V_12 & 1 ) )
F_6 ( V_10 , 0x7 , 0x7 , V_69 ) ;
}
static unsigned int F_20 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
return F_21 ( V_18 -> V_70 ) ;
}
static unsigned int F_22 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
return F_21 ( V_18 -> V_70 ) / 256 / 16 ;
}
static unsigned int F_23 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_21 * V_22 = & V_19 -> V_22 ;
switch ( V_22 -> V_71 ) {
case V_72 :
if ( F_12 ( V_22 -> V_73 ) )
return F_13 ( V_22 -> V_73 ) ;
case V_74 :
return ! ( F_8 ( V_10 -> V_15 + V_23 ) &
V_75 ) ;
case V_76 :
break;
}
return - V_77 ;
}
static T_5 F_24 ( int V_78 , void * V_2 )
{
struct V_9 * V_79 = (struct V_9 * ) V_2 ;
F_25 ( & V_79 -> V_80 ) ;
return V_81 ;
}
static int T_6
F_26 ( struct V_82 * V_83 ,
struct V_21 * V_22 )
{
struct V_84 * V_85 = V_83 -> V_86 . V_87 ;
if ( ! V_85 )
return - V_88 ;
if ( F_27 ( V_85 , L_1 , NULL ) )
V_22 -> V_34 = V_89 ;
if ( F_27 ( V_85 , L_2 , NULL ) )
V_22 -> V_34 = V_90 ;
if ( F_27 ( V_85 , L_3 , NULL ) )
V_22 -> V_71 = V_74 ;
V_22 -> V_24 = F_28 ( V_85 , L_4 , 0 ) ;
if ( F_12 ( V_22 -> V_24 ) )
V_22 -> V_34 = V_35 ;
V_22 -> V_73 = F_28 ( V_85 , L_5 , 0 ) ;
if ( F_12 ( V_22 -> V_73 ) )
V_22 -> V_71 = V_72 ;
return 0 ;
}
static inline int
F_26 ( struct V_82 * V_83 ,
struct V_21 * V_22 )
{
return - V_88 ;
}
static int T_6 F_29 ( struct V_82 * V_83 )
{
const struct V_91 * V_92 =
F_30 ( V_93 , & V_83 -> V_86 ) ;
struct V_17 * V_18 ;
struct V_9 * V_10 ;
struct V_21 * V_22 ;
struct V_70 * V_70 ;
int V_94 ;
struct V_1 * V_19 ;
V_10 = F_31 ( V_83 , & V_95 ) ;
if ( F_32 ( V_10 ) )
return F_33 ( V_10 ) ;
V_18 = F_10 ( V_10 ) ;
V_19 = F_34 ( sizeof( struct V_1 ) , V_96 ) ;
if ( ! V_19 ) {
V_94 = - V_97 ;
goto V_98;
}
if ( V_92 )
V_83 -> V_99 = V_92 -> V_2 ;
V_19 -> V_3 = V_83 -> V_99 -> V_100 ;
V_18 -> V_20 = V_19 ;
V_70 = F_35 ( F_36 ( V_10 -> V_101 ) , NULL ) ;
if ( F_32 ( V_70 ) ) {
F_37 ( F_36 ( V_10 -> V_101 ) , L_6 ) ;
V_94 = F_33 ( V_70 ) ;
goto V_102;
}
F_38 ( V_70 ) ;
V_18 -> V_70 = V_70 ;
if ( ! F_1 ( V_19 ) )
V_10 -> V_103 |= V_104 ;
if ( F_1 ( V_19 ) || F_2 ( V_19 ) )
V_10 -> V_103 |= V_105
| V_106 ;
if ( F_4 ( V_19 ) )
V_19 -> V_41 |= V_42 ;
if ( F_5 ( V_19 ) )
F_7 ( 0x08100810 , V_10 -> V_15 + V_107 ) ;
V_22 = & V_19 -> V_22 ;
if ( F_26 ( V_83 , V_22 ) < 0 ) {
if ( ! V_10 -> V_101 -> V_108 -> V_109 ) {
F_37 ( F_36 ( V_10 -> V_101 ) , L_7 ) ;
V_94 = - V_110 ;
goto V_111;
}
V_19 -> V_22 = * ( (struct V_21 * )
V_10 -> V_101 -> V_108 -> V_109 ) ;
}
if ( V_22 -> V_71 == V_72 ) {
V_94 = F_39 ( V_22 -> V_73 , V_112 , L_8 ) ;
if ( V_94 ) {
F_40 ( F_36 ( V_10 -> V_101 ) ,
L_9 ) ;
V_22 -> V_73 = - V_110 ;
}
} else {
V_22 -> V_73 = - V_110 ;
}
if ( V_22 -> V_34 != V_35 )
V_22 -> V_24 = - V_110 ;
switch ( V_22 -> V_34 ) {
case V_35 :
V_94 = F_39 ( V_22 -> V_24 , V_112 , L_10 ) ;
if ( V_94 ) {
F_37 ( F_36 ( V_10 -> V_101 ) ,
L_11 ) ;
goto V_113;
}
V_94 = F_41 ( F_42 ( V_22 -> V_24 ) , F_24 ,
V_114 | V_115 ,
F_43 ( V_10 -> V_101 ) , V_10 ) ;
if ( V_94 ) {
F_37 ( F_36 ( V_10 -> V_101 ) , L_12 ) ;
goto V_116;
}
case V_90 :
V_10 -> V_103 &= ~ V_117 ;
break;
case V_89 :
V_10 -> V_101 -> V_118 = V_119 ;
break;
case V_120 :
break;
}
V_94 = F_44 ( V_10 ) ;
if ( V_94 )
goto V_121;
return 0 ;
V_121:
if ( F_12 ( V_22 -> V_24 ) )
F_45 ( F_42 ( V_22 -> V_24 ) , V_10 ) ;
V_116:
if ( F_12 ( V_22 -> V_24 ) )
F_46 ( V_22 -> V_24 ) ;
if ( F_12 ( V_22 -> V_73 ) )
F_46 ( V_22 -> V_73 ) ;
V_113:
V_111:
F_47 ( V_18 -> V_70 ) ;
F_48 ( V_18 -> V_70 ) ;
V_102:
F_49 ( V_19 ) ;
V_98:
F_50 ( V_83 ) ;
return V_94 ;
}
static int T_7 F_51 ( struct V_82 * V_83 )
{
struct V_9 * V_10 = F_52 ( V_83 ) ;
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_21 * V_22 = & V_19 -> V_22 ;
int V_122 = ( F_8 ( V_10 -> V_15 + V_29 ) == 0xffffffff ) ;
F_53 ( V_10 , V_122 ) ;
if ( F_12 ( V_22 -> V_73 ) )
F_46 ( V_22 -> V_73 ) ;
if ( F_12 ( V_22 -> V_24 ) ) {
F_45 ( F_42 ( V_22 -> V_24 ) , V_10 ) ;
F_46 ( V_22 -> V_24 ) ;
}
F_47 ( V_18 -> V_70 ) ;
F_48 ( V_18 -> V_70 ) ;
F_49 ( V_19 ) ;
F_50 ( V_83 ) ;
return 0 ;
}
static int T_8 F_54 ( void )
{
return F_55 ( & V_123 ) ;
}
static void T_9 F_56 ( void )
{
F_57 ( & V_123 ) ;
}
