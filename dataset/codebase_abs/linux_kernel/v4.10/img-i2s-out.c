static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_5 )
F_3 ( V_4 -> V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
if ( ! V_4 -> V_5 ) {
V_7 = F_5 ( V_4 -> V_6 ) ;
if ( V_7 ) {
F_6 ( V_2 , L_1 , V_7 ) ;
return V_7 ;
}
}
return 0 ;
}
static inline void F_7 ( struct V_3 * V_4 , T_1 V_8 ,
T_1 V_9 )
{
F_8 ( V_8 , V_4 -> V_10 + V_9 ) ;
}
static inline T_1 F_9 ( struct V_3 * V_4 , T_1 V_9 )
{
return F_10 ( V_4 -> V_10 + V_9 ) ;
}
static inline void F_11 ( struct V_3 * V_4 ,
T_1 V_11 , T_1 V_8 , T_1 V_9 )
{
F_8 ( V_8 , V_4 -> V_12 + ( V_11 * V_13 ) + V_9 ) ;
}
static inline T_1 F_12 ( struct V_3 * V_4 , T_1 V_11 ,
T_1 V_9 )
{
return F_10 ( V_4 -> V_12 + ( V_11 * V_13 ) + V_9 ) ;
}
static inline void F_13 ( struct V_3 * V_4 , T_1 V_11 )
{
T_1 V_9 ;
V_9 = F_12 ( V_4 , V_11 , V_14 ) ;
V_9 &= ~ V_15 ;
F_11 ( V_4 , V_11 , V_9 , V_14 ) ;
}
static inline void F_14 ( struct V_3 * V_4 , T_1 V_11 )
{
T_1 V_9 ;
V_9 = F_12 ( V_4 , V_11 , V_14 ) ;
V_9 |= V_15 ;
F_11 ( V_4 , V_11 , V_9 , V_14 ) ;
}
static inline void F_15 ( struct V_3 * V_4 )
{
T_1 V_9 ;
V_9 = F_9 ( V_4 , V_16 ) ;
V_9 &= ~ V_17 ;
F_7 ( V_4 , V_9 , V_16 ) ;
}
static inline void F_16 ( struct V_3 * V_4 )
{
T_1 V_9 ;
V_9 = F_9 ( V_4 , V_16 ) ;
V_9 |= V_17 ;
F_7 ( V_4 , V_9 , V_16 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
int V_18 ;
T_1 V_19 , V_20 ;
V_19 = F_9 ( V_4 , V_16 ) &
~ V_17 &
~ V_21 ;
if ( ! V_4 -> V_5 )
V_19 &= ~ V_22 ;
V_20 = F_12 ( V_4 , 0 , V_14 ) &
~ V_15 ;
F_18 ( V_4 -> V_23 ) ;
F_19 ( V_4 -> V_23 ) ;
for ( V_18 = 0 ; V_18 < V_4 -> V_24 ; V_18 ++ )
F_11 ( V_4 , V_18 , V_20 , V_14 ) ;
for ( V_18 = 0 ; V_18 < V_4 -> V_25 ; V_18 ++ )
F_14 ( V_4 , V_18 ) ;
F_7 ( V_4 , V_19 , V_16 ) ;
F_16 ( V_4 ) ;
}
static int F_20 ( struct V_26 * V_27 , int V_28 ,
struct V_29 * V_30 )
{
struct V_3 * V_4 = F_21 ( V_30 ) ;
T_1 V_9 ;
switch ( V_28 ) {
case V_31 :
case V_32 :
case V_33 :
V_9 = F_9 ( V_4 , V_16 ) ;
if ( ! V_4 -> V_5 )
V_9 |= V_22 ;
V_9 |= V_21 ;
F_7 ( V_4 , V_9 , V_16 ) ;
break;
case V_34 :
case V_35 :
case V_36 :
F_17 ( V_4 ) ;
break;
default:
return - V_37 ;
}
return 0 ;
}
static int F_22 ( struct V_26 * V_27 ,
struct V_38 * V_39 , struct V_29 * V_30 )
{
struct V_3 * V_4 = F_21 ( V_30 ) ;
unsigned int V_40 , V_41 ;
long V_42 , V_43 , V_44 , V_45 , V_46 , V_47 ;
int V_18 ;
T_1 V_9 , V_48 , V_49 = 0 ;
T_2 V_50 ;
V_46 = F_23 ( V_39 ) ;
V_50 = F_24 ( V_39 ) ;
V_40 = F_25 ( V_39 ) ;
V_41 = V_40 / 2 ;
if ( V_50 != V_51 )
return - V_37 ;
if ( ( V_40 < 2 ) ||
( V_40 > ( V_4 -> V_24 * 2 ) ) ||
( V_40 % 2 ) )
return - V_37 ;
V_42 = F_26 ( V_4 -> V_6 , V_46 * 256 ) ;
if ( V_42 < 0 )
return V_42 ;
V_43 = F_26 ( V_4 -> V_6 , V_46 * 384 ) ;
if ( V_43 < 0 )
return V_43 ;
V_44 = abs ( ( V_42 / 256 ) - V_46 ) ;
V_45 = abs ( ( V_43 / 384 ) - V_46 ) ;
if ( V_44 > V_45 )
F_27 ( V_4 -> V_6 , V_43 ) ;
else
F_27 ( V_4 -> V_6 , V_42 ) ;
V_47 = F_28 ( V_4 -> V_6 ) ;
V_44 = abs ( ( V_47 / 256 ) - V_46 ) ;
V_45 = abs ( ( V_47 / 384 ) - V_46 ) ;
if ( V_44 > V_45 )
V_49 |= V_52 ;
V_49 |= ( ( V_41 - 1 ) <<
V_53 ) &
V_54 ;
V_48 = V_52 |
V_54 ;
F_15 ( V_4 ) ;
V_9 = F_9 ( V_4 , V_16 ) ;
V_9 = ( V_9 & ~ V_48 ) | V_49 ;
F_7 ( V_4 , V_9 , V_16 ) ;
for ( V_18 = 0 ; V_18 < V_41 ; V_18 ++ )
F_14 ( V_4 , V_18 ) ;
for (; V_18 < V_4 -> V_24 ; V_18 ++ )
F_13 ( V_4 , V_18 ) ;
F_16 ( V_4 ) ;
V_4 -> V_25 = V_41 ;
return 0 ;
}
static int F_29 ( struct V_29 * V_30 , unsigned int V_55 )
{
struct V_3 * V_4 = F_21 ( V_30 ) ;
int V_18 ;
bool V_5 ;
T_1 V_56 , V_48 , V_57 = 0 ;
T_1 V_9 , V_49 = 0 ;
V_5 = ( ( V_55 & V_58 ) ==
V_59 ) ;
if ( V_5 )
V_49 |= V_22 ;
switch ( V_55 & V_60 ) {
case V_61 :
break;
case V_62 :
V_49 |= V_63 ;
break;
default:
return - V_37 ;
}
switch ( V_55 & V_64 ) {
case V_65 :
V_49 |= V_66 ;
break;
case V_67 :
V_49 |= V_66 ;
V_49 |= V_68 ;
break;
case V_69 :
break;
case V_70 :
V_49 |= V_68 ;
break;
default:
return - V_37 ;
}
switch ( V_55 & V_71 ) {
case V_72 :
V_57 |= V_73 ;
break;
case V_74 :
break;
default:
return - V_37 ;
}
V_48 = V_22 |
V_63 |
V_66 |
V_68 ;
V_56 = V_73 ;
F_15 ( V_4 ) ;
V_9 = F_9 ( V_4 , V_16 ) ;
V_9 = ( V_9 & ~ V_48 ) | V_49 ;
F_7 ( V_4 , V_9 , V_16 ) ;
for ( V_18 = 0 ; V_18 < V_4 -> V_25 ; V_18 ++ )
F_13 ( V_4 , V_18 ) ;
for ( V_18 = 0 ; V_18 < V_4 -> V_24 ; V_18 ++ ) {
V_9 = F_12 ( V_4 , V_18 , V_14 ) ;
V_9 = ( V_9 & ~ V_56 ) | V_57 ;
F_11 ( V_4 , V_18 , V_9 , V_14 ) ;
}
for ( V_18 = 0 ; V_18 < V_4 -> V_25 ; V_18 ++ )
F_14 ( V_4 , V_18 ) ;
F_16 ( V_4 ) ;
V_4 -> V_5 = V_5 ;
return 0 ;
}
static int F_30 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = F_21 ( V_30 ) ;
F_31 ( V_30 , & V_4 -> V_75 , NULL ) ;
return 0 ;
}
static int F_32 ( struct V_26 * V_76 ,
struct V_38 * V_39 , struct V_77 * V_78 )
{
unsigned int V_41 = F_25 ( V_39 ) / 2 ;
struct V_79 * V_80 = V_76 -> V_81 ;
struct V_82 * V_75 ;
int V_7 ;
V_75 = F_33 ( V_80 -> V_83 , V_76 ) ;
V_7 = F_34 ( V_76 , V_39 , V_78 ) ;
if ( V_7 )
return V_7 ;
V_78 -> V_84 = V_75 -> V_85 ;
V_78 -> V_86 = V_75 -> V_87 ;
V_78 -> V_88 = 4 * V_41 ;
return 0 ;
}
static int F_35 ( struct V_89 * V_90 )
{
struct V_3 * V_4 ;
struct V_91 * V_92 ;
void T_3 * V_10 ;
int V_18 , V_7 ;
unsigned int V_93 ;
T_1 V_9 ;
struct V_1 * V_2 = & V_90 -> V_2 ;
V_4 = F_36 ( & V_90 -> V_2 , sizeof( * V_4 ) , V_94 ) ;
if ( ! V_4 )
return - V_95 ;
F_37 ( V_90 , V_4 ) ;
V_4 -> V_2 = & V_90 -> V_2 ;
V_92 = F_38 ( V_90 , V_96 , 0 ) ;
V_10 = F_39 ( & V_90 -> V_2 , V_92 ) ;
if ( F_40 ( V_10 ) )
return F_41 ( V_10 ) ;
V_4 -> V_10 = V_10 ;
if ( F_42 ( V_90 -> V_2 . V_97 , L_2 ,
& V_4 -> V_24 ) ) {
F_6 ( & V_90 -> V_2 , L_3 ) ;
return - V_37 ;
}
V_93 = 1 << F_43 ( V_4 -> V_24 ) ;
V_4 -> V_12 = V_10 + ( V_93 * 0x20 ) ;
V_4 -> V_23 = F_44 ( & V_90 -> V_2 , L_4 ) ;
if ( F_40 ( V_4 -> V_23 ) ) {
if ( F_41 ( V_4 -> V_23 ) != - V_98 )
F_6 ( & V_90 -> V_2 , L_5 ) ;
return F_41 ( V_4 -> V_23 ) ;
}
V_4 -> V_99 = F_45 ( & V_90 -> V_2 , L_6 ) ;
if ( F_40 ( V_4 -> V_99 ) ) {
if ( F_41 ( V_4 -> V_99 ) != - V_98 )
F_6 ( V_2 , L_7 ) ;
return F_41 ( V_4 -> V_99 ) ;
}
V_4 -> V_6 = F_45 ( & V_90 -> V_2 , L_8 ) ;
if ( F_40 ( V_4 -> V_6 ) ) {
if ( F_41 ( V_4 -> V_6 ) != - V_98 )
F_6 ( V_2 , L_9 ) ;
return F_41 ( V_4 -> V_6 ) ;
}
V_7 = F_5 ( V_4 -> V_99 ) ;
if ( V_7 )
return V_7 ;
V_9 = V_100 ;
F_7 ( V_4 , V_9 , V_16 ) ;
V_9 = V_101 |
V_102 |
V_103 |
( 8 << V_104 ) ;
for ( V_18 = 0 ; V_18 < V_4 -> V_24 ; V_18 ++ )
F_11 ( V_4 , V_18 , V_9 , V_14 ) ;
F_17 ( V_4 ) ;
F_46 ( & V_90 -> V_2 ) ;
if ( ! F_47 ( & V_90 -> V_2 ) ) {
V_7 = F_4 ( & V_90 -> V_2 ) ;
if ( V_7 )
goto V_105;
}
V_4 -> V_25 = 1 ;
V_4 -> V_75 . V_85 = V_92 -> V_106 + V_107 ;
V_4 -> V_75 . V_87 = 4 ;
V_4 -> V_75 . V_108 = 4 ;
V_4 -> V_109 . V_110 = F_30 ;
V_4 -> V_109 . V_111 . V_112 = 2 ;
V_4 -> V_109 . V_111 . V_113 = V_4 -> V_24 * 2 ;
V_4 -> V_109 . V_111 . V_114 = V_115 ;
V_4 -> V_109 . V_111 . V_116 = V_117 ;
V_4 -> V_109 . V_118 = & V_119 ;
V_7 = F_48 ( & V_90 -> V_2 ,
& V_120 , & V_4 -> V_109 , 1 ) ;
if ( V_7 )
goto V_121;
V_7 = F_49 ( & V_90 -> V_2 ,
& V_122 , 0 ) ;
if ( V_7 )
goto V_121;
return 0 ;
V_121:
if ( ! F_50 ( & V_90 -> V_2 ) )
F_1 ( & V_90 -> V_2 ) ;
V_105:
F_51 ( & V_90 -> V_2 ) ;
F_3 ( V_4 -> V_99 ) ;
return V_7 ;
}
static int F_52 ( struct V_89 * V_90 )
{
struct V_3 * V_4 = F_53 ( V_90 ) ;
F_51 ( & V_90 -> V_2 ) ;
if ( ! F_50 ( & V_90 -> V_2 ) )
F_1 ( & V_90 -> V_2 ) ;
F_3 ( V_4 -> V_99 ) ;
return 0 ;
}
