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
if ( ( V_10 -> V_50 -> V_51 == V_57 ||
V_10 -> V_50 -> V_51 == V_58 ) &&
( V_19 -> V_41 & V_42 ) )
V_12 |= V_59 ;
if ( F_5 ( V_19 ) ) {
T_1 V_60 = F_8 ( V_10 -> V_15 + V_61 ) ;
V_60 = V_19 -> V_55 | ( V_60 & 0xffff0000 ) ;
F_7 ( V_60 , V_10 -> V_15 + V_61 ) ;
F_7 ( V_12 << 16 ,
V_10 -> V_15 + V_49 ) ;
} else {
F_7 ( V_12 << 16 | V_19 -> V_55 ,
V_10 -> V_15 + V_49 ) ;
}
return;
case V_62 :
V_12 &= ~ F_18 ( 0x7 , 0 ) ;
break;
}
F_6 ( V_10 , 0xffff , V_12 , V_13 ) ;
}
static void F_19 ( struct V_9 * V_10 , T_4 V_12 , int V_13 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
T_1 V_63 ;
switch ( V_13 ) {
case V_64 :
return;
case V_39 :
V_63 = V_12 & ( V_65 | \
V_66 | \
V_40 ) ;
V_63 |= V_67 ;
if ( ! F_1 ( V_19 ) ) {
V_63 |= ( V_12 & V_68 ) << 5 ;
}
F_6 ( V_10 , 0xffff , V_63 , V_13 ) ;
return;
}
F_6 ( V_10 , 0xff , V_12 , V_13 ) ;
if ( ( V_13 == V_69 ) && ( V_12 & 1 ) )
F_6 ( V_10 , 0x7 , 0x7 , V_70 ) ;
}
static unsigned int F_20 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
return F_21 ( V_18 -> V_71 ) ;
}
static unsigned int F_22 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
return F_21 ( V_18 -> V_71 ) / 256 / 16 ;
}
static unsigned int F_23 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_21 * V_22 = & V_19 -> V_22 ;
switch ( V_22 -> V_72 ) {
case V_73 :
if ( F_12 ( V_22 -> V_74 ) )
return F_13 ( V_22 -> V_74 ) ;
case V_75 :
return ! ( F_8 ( V_10 -> V_15 + V_23 ) &
V_76 ) ;
case V_77 :
break;
}
return - V_78 ;
}
static T_5 F_24 ( int V_79 , void * V_2 )
{
struct V_9 * V_80 = (struct V_9 * ) V_2 ;
F_25 ( & V_80 -> V_81 ) ;
return V_82 ;
}
static int
F_26 ( struct V_83 * V_84 ,
struct V_21 * V_22 )
{
struct V_85 * V_86 = V_84 -> V_87 . V_88 ;
if ( ! V_86 )
return - V_89 ;
if ( F_27 ( V_86 , L_1 , NULL ) )
V_22 -> V_34 = V_90 ;
if ( F_27 ( V_86 , L_2 , NULL ) )
V_22 -> V_34 = V_91 ;
if ( F_27 ( V_86 , L_3 , NULL ) )
V_22 -> V_72 = V_75 ;
V_22 -> V_24 = F_28 ( V_86 , L_4 , 0 ) ;
if ( F_12 ( V_22 -> V_24 ) )
V_22 -> V_34 = V_35 ;
V_22 -> V_74 = F_28 ( V_86 , L_5 , 0 ) ;
if ( F_12 ( V_22 -> V_74 ) )
V_22 -> V_72 = V_73 ;
return 0 ;
}
static inline int
F_26 ( struct V_83 * V_84 ,
struct V_21 * V_22 )
{
return - V_89 ;
}
static int F_29 ( struct V_83 * V_84 )
{
const struct V_92 * V_93 =
F_30 ( V_94 , & V_84 -> V_87 ) ;
struct V_17 * V_18 ;
struct V_9 * V_10 ;
struct V_21 * V_22 ;
int V_95 ;
struct V_1 * V_19 ;
V_10 = F_31 ( V_84 , & V_96 ) ;
if ( F_32 ( V_10 ) )
return F_33 ( V_10 ) ;
V_18 = F_10 ( V_10 ) ;
V_19 = F_34 ( & V_84 -> V_87 , sizeof( * V_19 ) , V_97 ) ;
if ( ! V_19 ) {
V_95 = - V_98 ;
goto V_99;
}
if ( V_93 )
V_84 -> V_100 = V_93 -> V_2 ;
V_19 -> V_3 = V_84 -> V_100 -> V_101 ;
V_18 -> V_20 = V_19 ;
V_19 -> V_102 = F_35 ( & V_84 -> V_87 , L_6 ) ;
if ( F_32 ( V_19 -> V_102 ) ) {
V_95 = F_33 ( V_19 -> V_102 ) ;
goto V_99;
}
V_19 -> V_103 = F_35 ( & V_84 -> V_87 , L_7 ) ;
if ( F_32 ( V_19 -> V_103 ) ) {
V_95 = F_33 ( V_19 -> V_103 ) ;
goto V_99;
}
V_19 -> V_104 = F_35 ( & V_84 -> V_87 , L_8 ) ;
if ( F_32 ( V_19 -> V_104 ) ) {
V_95 = F_33 ( V_19 -> V_104 ) ;
goto V_99;
}
V_18 -> V_71 = V_19 -> V_104 ;
F_36 ( V_19 -> V_104 ) ;
F_36 ( V_19 -> V_102 ) ;
F_36 ( V_19 -> V_103 ) ;
V_19 -> V_105 = F_37 ( & V_84 -> V_87 ) ;
if ( F_32 ( V_19 -> V_105 ) ) {
V_95 = F_33 ( V_19 -> V_105 ) ;
goto V_106;
}
V_10 -> V_107 |= V_108 ;
if ( F_1 ( V_19 ) || F_2 ( V_19 ) )
V_10 -> V_107 |= V_109
| V_110 ;
if ( F_4 ( V_19 ) )
V_19 -> V_41 |= V_42 ;
if ( F_5 ( V_19 ) )
F_7 ( 0x08100810 , V_10 -> V_15 + V_111 ) ;
V_22 = & V_19 -> V_22 ;
if ( F_26 ( V_84 , V_22 ) < 0 ) {
if ( ! V_10 -> V_112 -> V_113 -> V_114 ) {
F_38 ( F_39 ( V_10 -> V_112 ) , L_9 ) ;
V_95 = - V_115 ;
goto V_106;
}
V_19 -> V_22 = * ( (struct V_21 * )
V_10 -> V_112 -> V_113 -> V_114 ) ;
}
if ( V_22 -> V_72 == V_73 ) {
V_95 = F_40 ( & V_84 -> V_87 , V_22 -> V_74 ,
V_116 , L_10 ) ;
if ( V_95 ) {
F_41 ( F_39 ( V_10 -> V_112 ) ,
L_11 ) ;
V_22 -> V_74 = - V_115 ;
}
} else {
V_22 -> V_74 = - V_115 ;
}
if ( V_22 -> V_34 != V_35 )
V_22 -> V_24 = - V_115 ;
switch ( V_22 -> V_34 ) {
case V_35 :
V_95 = F_40 ( & V_84 -> V_87 , V_22 -> V_24 ,
V_116 , L_12 ) ;
if ( V_95 ) {
F_38 ( F_39 ( V_10 -> V_112 ) ,
L_13 ) ;
goto V_106;
}
V_95 = F_42 ( & V_84 -> V_87 ,
F_43 ( V_22 -> V_24 ) , F_24 ,
V_117 | V_118 ,
F_44 ( V_10 -> V_112 ) , V_10 ) ;
if ( V_95 ) {
F_38 ( F_39 ( V_10 -> V_112 ) , L_14 ) ;
goto V_106;
}
case V_91 :
V_10 -> V_107 &= ~ V_119 ;
break;
case V_90 :
V_10 -> V_112 -> V_120 = V_121 ;
break;
case V_122 :
break;
}
V_95 = F_45 ( V_10 ) ;
if ( V_95 )
goto V_106;
return 0 ;
V_106:
F_46 ( V_19 -> V_104 ) ;
F_46 ( V_19 -> V_102 ) ;
F_46 ( V_19 -> V_103 ) ;
V_99:
F_47 ( V_84 ) ;
return V_95 ;
}
static int F_48 ( struct V_83 * V_84 )
{
struct V_9 * V_10 = F_49 ( V_84 ) ;
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
int V_123 = ( F_8 ( V_10 -> V_15 + V_29 ) == 0xffffffff ) ;
F_50 ( V_10 , V_123 ) ;
F_46 ( V_19 -> V_104 ) ;
F_46 ( V_19 -> V_102 ) ;
F_46 ( V_19 -> V_103 ) ;
F_47 ( V_84 ) ;
return 0 ;
}
