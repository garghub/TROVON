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
static inline void F_5 ( struct V_8 * V_9 , T_1 V_10 , T_1 V_11 , int V_12 )
{
void T_2 * V_13 = V_9 -> V_14 + ( V_12 & ~ 0x3 ) ;
T_1 V_15 = ( V_12 & 0x3 ) * 8 ;
F_6 ( ( ( F_7 ( V_13 ) & ~ ( V_10 << V_15 ) ) | ( V_11 << V_15 ) ) , V_13 ) ;
}
static T_1 F_8 ( struct V_8 * V_9 , int V_12 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_18 = V_17 -> V_19 ;
struct V_20 * V_21 = & V_18 -> V_21 ;
T_1 V_11 = F_7 ( V_9 -> V_14 + V_12 ) ;
if ( F_10 ( ( V_12 == V_22 )
&& F_11 ( V_21 -> V_23 ) ) ) {
if ( F_12 ( V_21 -> V_23 ) )
V_11 &= ~ V_24 ;
else
V_11 |= V_24 ;
}
return V_11 ;
}
static void F_13 ( struct V_8 * V_9 , T_1 V_11 , int V_12 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_18 = V_17 -> V_19 ;
struct V_20 * V_21 = & V_18 -> V_21 ;
T_1 V_2 ;
if ( F_10 ( V_12 == V_25 || V_12 == V_26 ) ) {
if ( V_21 -> V_27 == V_28 )
V_11 &= ~ ( V_29 | V_30 ) ;
if ( V_11 & V_31 ) {
V_2 = F_7 ( V_9 -> V_14 + V_32 ) ;
V_2 &= ~ V_33 ;
F_6 ( V_2 , V_9 -> V_14 + V_32 ) ;
V_2 |= V_33 ;
F_6 ( V_2 , V_9 -> V_14 + V_32 ) ;
}
}
if ( F_10 ( ( V_18 -> V_34 & V_35 )
&& ( V_12 == V_36 )
&& ( V_11 & V_37 ) ) ) {
T_1 V_38 ;
V_38 = F_7 ( V_9 -> V_14 + V_39 ) ;
V_38 &= ~ V_40 ;
F_6 ( V_38 , V_9 -> V_14 + V_39 ) ;
}
F_6 ( V_11 , V_9 -> V_14 + V_12 ) ;
}
static T_3 F_14 ( struct V_8 * V_9 , int V_12 )
{
if ( F_10 ( V_12 == V_41 ) )
V_12 ^= 2 ;
return F_15 ( V_9 -> V_14 + V_12 ) ;
}
static void F_16 ( struct V_8 * V_9 , T_3 V_11 , int V_12 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_18 = V_17 -> V_19 ;
switch ( V_12 ) {
case V_42 :
if ( ( V_18 -> V_34 & V_35 )
&& ( V_9 -> V_43 -> V_44 == V_45 )
&& ( V_9 -> V_43 -> V_2 -> V_46 > 1 )
&& ( V_9 -> V_43 -> V_2 -> V_34 & V_47 ) ) {
T_1 V_38 ;
V_38 = F_7 ( V_9 -> V_14 + V_39 ) ;
V_38 |= V_40 ;
F_6 ( V_38 , V_9 -> V_14 + V_39 ) ;
}
V_18 -> V_48 = V_11 ;
return;
case V_49 :
if ( ( V_9 -> V_43 -> V_44 == V_50 )
&& ( V_18 -> V_34 & V_35 ) )
V_11 |= V_51 ;
F_6 ( V_11 << 16 | V_18 -> V_48 ,
V_9 -> V_14 + V_42 ) ;
return;
case V_52 :
V_11 &= ~ F_17 ( 0x7 , 0 ) ;
break;
}
F_5 ( V_9 , 0xffff , V_11 , V_12 ) ;
}
static void F_18 ( struct V_8 * V_9 , T_4 V_11 , int V_12 )
{
T_1 V_53 ;
switch ( V_12 ) {
case V_54 :
return;
case V_32 :
V_53 = V_11 & ( V_55 | \
V_56 | \
V_33 ) ;
V_53 |= V_57 ;
V_53 |= ( V_11 & V_58 ) << 5 ;
F_5 ( V_9 , 0xffff , V_53 , V_12 ) ;
return;
}
F_5 ( V_9 , 0xff , V_11 , V_12 ) ;
if ( ( V_12 == V_59 ) && ( V_11 & 1 ) )
F_5 ( V_9 , 0x7 , 0x7 , V_60 ) ;
}
static unsigned int F_19 ( struct V_8 * V_9 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
return F_20 ( V_17 -> V_61 ) ;
}
static unsigned int F_21 ( struct V_8 * V_9 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
return F_20 ( V_17 -> V_61 ) / 256 / 16 ;
}
static unsigned int F_22 ( struct V_8 * V_9 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_18 = V_17 -> V_19 ;
struct V_20 * V_21 = & V_18 -> V_21 ;
switch ( V_21 -> V_62 ) {
case V_63 :
if ( F_11 ( V_21 -> V_64 ) )
return F_12 ( V_21 -> V_64 ) ;
case V_65 :
return ! ( F_7 ( V_9 -> V_14 + V_22 ) &
V_66 ) ;
case V_67 :
break;
}
return - V_68 ;
}
static T_5 F_23 ( int V_69 , void * V_2 )
{
struct V_8 * V_70 = (struct V_8 * ) V_2 ;
F_24 ( & V_70 -> V_71 ) ;
return V_72 ;
}
static int T_6
F_25 ( struct V_73 * V_74 ,
struct V_20 * V_21 )
{
struct V_75 * V_76 = V_74 -> V_77 . V_78 ;
if ( ! V_76 )
return - V_79 ;
if ( F_26 ( V_76 , L_1 , NULL ) )
V_21 -> V_27 = V_80 ;
if ( F_26 ( V_76 , L_2 , NULL ) )
V_21 -> V_27 = V_81 ;
if ( F_26 ( V_76 , L_3 , NULL ) )
V_21 -> V_62 = V_65 ;
V_21 -> V_23 = F_27 ( V_76 , L_4 , 0 ) ;
if ( F_11 ( V_21 -> V_23 ) )
V_21 -> V_27 = V_28 ;
V_21 -> V_64 = F_27 ( V_76 , L_5 , 0 ) ;
if ( F_11 ( V_21 -> V_64 ) )
V_21 -> V_62 = V_63 ;
return 0 ;
}
static inline int
F_25 ( struct V_73 * V_74 ,
struct V_20 * V_21 )
{
return - V_79 ;
}
static int T_6 F_28 ( struct V_73 * V_74 )
{
const struct V_82 * V_83 =
F_29 ( V_84 , & V_74 -> V_77 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
struct V_20 * V_21 ;
struct V_61 * V_61 ;
int V_85 ;
struct V_1 * V_18 ;
V_9 = F_30 ( V_74 , & V_86 ) ;
if ( F_31 ( V_9 ) )
return F_32 ( V_9 ) ;
V_17 = F_9 ( V_9 ) ;
V_18 = F_33 ( sizeof( struct V_1 ) , V_87 ) ;
if ( ! V_18 ) {
V_85 = - V_88 ;
goto V_89;
}
if ( V_83 )
V_74 -> V_90 = V_83 -> V_2 ;
V_18 -> V_3 = V_74 -> V_90 -> V_91 ;
V_17 -> V_19 = V_18 ;
V_61 = F_34 ( F_35 ( V_9 -> V_92 ) , NULL ) ;
if ( F_31 ( V_61 ) ) {
F_36 ( F_35 ( V_9 -> V_92 ) , L_6 ) ;
V_85 = F_32 ( V_61 ) ;
goto V_93;
}
F_37 ( V_61 ) ;
V_17 -> V_61 = V_61 ;
if ( ! F_1 ( V_18 ) )
V_9 -> V_94 |= V_95 ;
if ( F_1 ( V_18 ) || F_2 ( V_18 ) )
V_9 -> V_94 |= V_96 ;
if ( F_4 ( V_18 ) )
V_18 -> V_34 |= V_35 ;
V_21 = & V_18 -> V_21 ;
if ( F_25 ( V_74 , V_21 ) < 0 ) {
if ( ! V_9 -> V_92 -> V_97 -> V_98 ) {
F_36 ( F_35 ( V_9 -> V_92 ) , L_7 ) ;
V_85 = - V_99 ;
goto V_100;
}
V_18 -> V_21 = * ( (struct V_20 * )
V_9 -> V_92 -> V_97 -> V_98 ) ;
}
if ( V_21 -> V_62 == V_63 ) {
V_85 = F_38 ( V_21 -> V_64 , V_101 , L_8 ) ;
if ( V_85 ) {
F_39 ( F_35 ( V_9 -> V_92 ) ,
L_9 ) ;
V_21 -> V_64 = - V_99 ;
}
} else {
V_21 -> V_64 = - V_99 ;
}
if ( V_21 -> V_27 != V_28 )
V_21 -> V_23 = - V_99 ;
switch ( V_21 -> V_27 ) {
case V_28 :
V_85 = F_38 ( V_21 -> V_23 , V_101 , L_10 ) ;
if ( V_85 ) {
F_36 ( F_35 ( V_9 -> V_92 ) ,
L_11 ) ;
goto V_102;
}
V_85 = F_40 ( F_41 ( V_21 -> V_23 ) , F_23 ,
V_103 | V_104 ,
F_42 ( V_9 -> V_92 ) , V_9 ) ;
if ( V_85 ) {
F_36 ( F_35 ( V_9 -> V_92 ) , L_12 ) ;
goto V_105;
}
case V_81 :
V_9 -> V_94 &= ~ V_106 ;
break;
case V_80 :
V_9 -> V_92 -> V_107 = V_108 ;
break;
case V_109 :
break;
}
V_85 = F_43 ( V_9 ) ;
if ( V_85 )
goto V_110;
return 0 ;
V_110:
if ( F_11 ( V_21 -> V_23 ) )
F_44 ( F_41 ( V_21 -> V_23 ) , V_9 ) ;
V_105:
if ( F_11 ( V_21 -> V_23 ) )
F_45 ( V_21 -> V_23 ) ;
if ( F_11 ( V_21 -> V_64 ) )
F_45 ( V_21 -> V_64 ) ;
V_102:
V_100:
F_46 ( V_17 -> V_61 ) ;
F_47 ( V_17 -> V_61 ) ;
V_93:
F_48 ( V_18 ) ;
V_89:
F_49 ( V_74 ) ;
return V_85 ;
}
static int T_7 F_50 ( struct V_73 * V_74 )
{
struct V_8 * V_9 = F_51 ( V_74 ) ;
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_18 = V_17 -> V_19 ;
struct V_20 * V_21 = & V_18 -> V_21 ;
int V_111 = ( F_7 ( V_9 -> V_14 + V_36 ) == 0xffffffff ) ;
F_52 ( V_9 , V_111 ) ;
if ( F_11 ( V_21 -> V_64 ) )
F_45 ( V_21 -> V_64 ) ;
if ( F_11 ( V_21 -> V_23 ) ) {
F_44 ( F_41 ( V_21 -> V_23 ) , V_9 ) ;
F_45 ( V_21 -> V_23 ) ;
}
F_46 ( V_17 -> V_61 ) ;
F_47 ( V_17 -> V_61 ) ;
F_48 ( V_18 ) ;
F_49 ( V_74 ) ;
return 0 ;
}
static int T_8 F_53 ( void )
{
return F_54 ( & V_112 ) ;
}
static void T_9 F_55 ( void )
{
F_56 ( & V_112 ) ;
}
