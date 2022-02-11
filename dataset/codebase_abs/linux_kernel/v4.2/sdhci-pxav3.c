static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
void T_1 * V_6 ;
struct V_7 * V_8 ;
if ( ! V_4 ) {
F_2 ( & V_2 -> V_9 , L_1 ) ;
return - V_10 ;
}
V_8 = F_3 ( V_2 , V_11 , 1 ) ;
if ( ! V_8 ) {
F_2 ( & V_2 -> V_9 , L_2 ) ;
return - V_10 ;
}
V_6 = F_4 ( V_8 -> V_12 , F_5 ( V_8 ) ) ;
if ( ! V_6 ) {
F_2 ( & V_2 -> V_9 , L_3 ) ;
return - V_13 ;
}
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
F_6 ( 0 , V_6 + F_7 ( V_5 ) ) ;
F_6 ( 0 , V_6 + F_8 ( V_5 ) ) ;
}
for ( V_5 = 0 ; V_5 < V_4 -> V_15 ; V_5 ++ ) {
const struct V_16 * V_17 = V_4 -> V_17 + V_5 ;
F_6 ( ( ( V_17 -> V_18 - 1 ) & 0xffff0000 ) |
( V_17 -> V_19 << 8 ) |
( V_4 -> V_20 << 4 ) | 1 ,
V_6 + F_7 ( V_5 ) ) ;
F_6 ( V_17 -> V_21 , V_6 + F_8 ( V_5 ) ) ;
}
F_9 ( V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = V_2 -> V_9 . V_26 ;
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = V_28 -> V_31 ;
struct V_7 * V_8 ;
V_23 -> V_32 |= V_33 ;
V_8 = F_12 ( V_2 , V_11 ,
L_4 ) ;
if ( V_8 ) {
V_30 -> V_34 = F_13 ( & V_2 -> V_9 , V_8 ) ;
if ( F_14 ( V_30 -> V_34 ) )
return F_15 ( V_30 -> V_34 ) ;
} else {
V_23 -> V_35 = F_16 ( V_23 , V_36 ) ;
V_23 -> V_35 &= ~ ( V_37 | V_38 ) ;
F_17 ( & V_2 -> V_9 , L_5 ) ;
}
V_23 -> V_39 = F_16 ( V_23 , V_40 ) ;
if ( F_18 ( V_25 , L_6 ) ) {
V_23 -> V_39 &= ~ V_41 ;
V_23 -> V_42 -> V_39 &= ~ V_43 ;
} else {
V_23 -> V_39 &= ~ V_44 ;
}
V_23 -> V_35 &= ~ ( V_45 | V_46 ) ;
return 0 ;
}
static void F_19 ( struct V_22 * V_23 , T_2 V_47 )
{
struct V_1 * V_2 = F_20 ( F_21 ( V_23 -> V_42 ) ) ;
struct V_48 * V_49 = V_2 -> V_9 . V_50 ;
F_22 ( V_23 , V_47 ) ;
if ( V_47 == V_51 ) {
if ( V_49 && 0 != V_49 -> V_52 ) {
T_3 V_53 ;
V_53 = F_23 ( V_23 -> V_54 + V_55 ) ;
V_53 |= ( V_49 -> V_52 & V_56 )
<< V_57 ;
V_53 |= V_58 ;
F_24 ( V_53 , V_23 -> V_54 + V_55 ) ;
}
}
}
static void F_25 ( struct V_22 * V_23 , T_2 V_59 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = V_28 -> V_31 ;
T_3 V_53 ;
int V_60 ;
if ( V_30 -> V_59 == V_61
&& V_59 == V_62 ) {
F_26 ( F_21 ( V_23 -> V_42 ) ,
L_7
L_8 ,
V_63 ,
V_30 -> V_59 ,
V_59 ) ;
V_53 = F_23 ( V_23 -> V_54 + V_64 ) ;
V_53 |= V_65 ;
F_24 ( V_53 , V_23 -> V_54 + V_64 ) ;
V_53 = F_23 ( V_23 -> V_54 + V_66 ) ;
V_53 |= V_67 ;
F_24 ( V_53 , V_23 -> V_54 + V_66 ) ;
F_27 ( 740 ) ;
V_60 = 0 ;
while ( V_60 ++ < V_68 ) {
if ( ( F_23 ( V_23 -> V_54 + V_64 )
& V_69 ) == 0 )
break;
F_27 ( 10 ) ;
}
if ( V_60 == V_68 )
F_17 ( F_21 ( V_23 -> V_42 ) , L_9 ) ;
V_53 = F_23 ( V_23 -> V_54 + V_64 ) ;
V_53 |= V_69 ;
F_24 ( V_53 , V_23 -> V_54 + V_64 ) ;
}
V_30 -> V_59 = V_59 ;
}
static void F_28 ( struct V_22 * V_23 , unsigned int V_70 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = V_28 -> V_31 ;
T_3 V_71 ;
V_71 = F_29 ( V_23 , V_72 ) ;
V_71 &= ~ V_73 ;
switch ( V_70 ) {
case V_74 :
V_71 |= V_75 ;
break;
case V_76 :
V_71 |= V_77 ;
break;
case V_78 :
V_71 |= V_79 | V_80 ;
break;
case V_81 :
V_71 |= V_82 | V_80 ;
break;
case V_83 :
case V_84 :
V_71 |= V_85 | V_80 ;
break;
}
if ( V_30 -> V_34 ) {
T_2 V_86 = F_30 ( V_30 -> V_34 ) ;
if ( V_70 == V_78 ||
V_70 == V_84 ) {
V_86 &= ~ V_87 ;
V_86 |= V_88 ;
} else {
V_86 |= V_87 ;
V_86 &= ~ V_88 ;
}
F_31 ( V_86 , V_30 -> V_34 ) ;
}
F_32 ( V_23 , V_71 , V_72 ) ;
F_26 ( F_21 ( V_23 -> V_42 ) ,
L_10 ,
V_63 , V_70 , V_71 ) ;
}
static struct V_48 * F_33 ( struct V_89 * V_9 )
{
struct V_48 * V_49 ;
struct V_24 * V_25 = V_9 -> V_26 ;
T_4 V_52 ;
V_49 = F_34 ( V_9 , sizeof( * V_49 ) , V_90 ) ;
if ( ! V_49 )
return NULL ;
if ( ! F_35 ( V_25 , L_11 ,
& V_52 ) )
V_49 -> V_52 = V_52 ;
return V_49 ;
}
static inline struct V_48 * F_33 ( struct V_89 * V_9 )
{
return NULL ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
struct V_48 * V_49 = V_2 -> V_9 . V_50 ;
struct V_89 * V_9 = & V_2 -> V_9 ;
struct V_24 * V_25 = V_2 -> V_9 . V_26 ;
struct V_22 * V_23 = NULL ;
struct V_29 * V_30 = NULL ;
const struct V_91 * V_92 ;
int V_93 ;
V_30 = F_34 ( & V_2 -> V_9 , sizeof( struct V_29 ) , V_90 ) ;
if ( ! V_30 )
return - V_13 ;
V_23 = F_37 ( V_2 , & V_94 , 0 ) ;
if ( F_14 ( V_23 ) )
return F_15 ( V_23 ) ;
V_28 = F_11 ( V_23 ) ;
V_28 -> V_31 = V_30 ;
V_30 -> V_95 = F_38 ( V_9 , L_12 ) ;
if ( F_14 ( V_30 -> V_95 ) )
V_30 -> V_95 = F_38 ( V_9 , NULL ) ;
if ( F_14 ( V_30 -> V_95 ) ) {
F_2 ( V_9 , L_13 ) ;
V_93 = F_15 ( V_30 -> V_95 ) ;
goto V_96;
}
V_28 -> V_97 = V_30 -> V_95 ;
F_39 ( V_30 -> V_95 ) ;
V_30 -> V_98 = F_38 ( V_9 , L_14 ) ;
if ( ! F_14 ( V_30 -> V_98 ) )
F_39 ( V_30 -> V_98 ) ;
V_23 -> V_42 -> V_39 |= V_43 ;
if ( F_40 ( V_25 , L_15 ) ) {
V_93 = F_10 ( V_2 , V_23 ) ;
if ( V_93 < 0 )
goto V_96;
V_93 = F_1 ( V_2 , F_41 () ) ;
if ( V_93 < 0 )
goto V_99;
}
V_92 = F_42 ( F_43 ( V_100 ) , & V_2 -> V_9 ) ;
if ( V_92 ) {
V_93 = F_44 ( V_23 -> V_42 ) ;
if ( V_93 )
goto V_101;
F_45 ( V_2 ) ;
V_49 = F_33 ( V_9 ) ;
V_2 -> V_9 . V_50 = V_49 ;
} else if ( V_49 ) {
if ( V_49 -> V_102 & V_103 )
V_23 -> V_42 -> V_39 |= V_104 ;
if ( V_49 -> V_102 & V_105 )
V_23 -> V_42 -> V_39 |= V_106 ;
if ( V_49 -> V_32 )
V_23 -> V_32 |= V_49 -> V_32 ;
if ( V_49 -> V_107 )
V_23 -> V_107 |= V_49 -> V_107 ;
if ( V_49 -> V_108 )
V_23 -> V_42 -> V_39 |= V_49 -> V_108 ;
if ( V_49 -> V_109 )
V_23 -> V_42 -> V_110 |= V_49 -> V_109 ;
if ( V_49 -> V_111 )
V_23 -> V_42 -> V_111 |= V_49 -> V_111 ;
if ( F_46 ( V_49 -> V_112 ) ) {
V_93 = F_47 ( V_23 -> V_42 , V_49 -> V_112 ,
0 ) ;
if ( V_93 ) {
F_2 ( F_21 ( V_23 -> V_42 ) ,
L_16 ) ;
goto V_113;
}
}
}
F_48 ( & V_2 -> V_9 ) ;
F_49 ( & V_2 -> V_9 ) ;
F_50 ( & V_2 -> V_9 , V_114 ) ;
F_51 ( & V_2 -> V_9 ) ;
F_52 ( & V_2 -> V_9 ) ;
F_53 ( & V_2 -> V_9 , 1 ) ;
V_93 = F_54 ( V_23 ) ;
if ( V_93 ) {
F_2 ( & V_2 -> V_9 , L_17 ) ;
goto V_115;
}
F_55 ( V_2 , V_23 ) ;
if ( V_23 -> V_42 -> V_111 & V_116 )
F_56 ( & V_2 -> V_9 , 1 ) ;
F_57 ( & V_2 -> V_9 ) ;
return 0 ;
V_115:
F_58 ( & V_2 -> V_9 ) ;
F_59 ( & V_2 -> V_9 ) ;
V_101:
V_113:
V_99:
F_60 ( V_30 -> V_95 ) ;
F_60 ( V_30 -> V_98 ) ;
V_96:
F_61 ( V_2 ) ;
return V_93 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_63 ( V_2 ) ;
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = V_28 -> V_31 ;
F_64 ( & V_2 -> V_9 ) ;
F_58 ( & V_2 -> V_9 ) ;
F_59 ( & V_2 -> V_9 ) ;
F_65 ( V_23 , 1 ) ;
F_60 ( V_30 -> V_95 ) ;
F_60 ( V_30 -> V_98 ) ;
F_61 ( V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_89 * V_9 )
{
int V_93 ;
struct V_22 * V_23 = F_67 ( V_9 ) ;
F_64 ( V_9 ) ;
V_93 = F_68 ( V_23 ) ;
F_69 ( V_9 ) ;
F_57 ( V_9 ) ;
return V_93 ;
}
static int F_70 ( struct V_89 * V_9 )
{
int V_93 ;
struct V_22 * V_23 = F_67 ( V_9 ) ;
F_64 ( V_9 ) ;
V_93 = F_71 ( V_23 ) ;
F_69 ( V_9 ) ;
F_57 ( V_9 ) ;
return V_93 ;
}
static int F_72 ( struct V_89 * V_9 )
{
struct V_22 * V_23 = F_67 ( V_9 ) ;
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = V_28 -> V_31 ;
int V_93 ;
V_93 = F_73 ( V_23 ) ;
if ( V_93 )
return V_93 ;
F_60 ( V_30 -> V_95 ) ;
if ( ! F_14 ( V_30 -> V_98 ) )
F_60 ( V_30 -> V_98 ) ;
return 0 ;
}
static int F_74 ( struct V_89 * V_9 )
{
struct V_22 * V_23 = F_67 ( V_9 ) ;
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = V_28 -> V_31 ;
F_39 ( V_30 -> V_95 ) ;
if ( ! F_14 ( V_30 -> V_98 ) )
F_39 ( V_30 -> V_98 ) ;
return F_75 ( V_23 ) ;
}
