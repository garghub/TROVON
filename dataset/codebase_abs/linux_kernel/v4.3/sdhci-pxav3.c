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
V_23 -> V_32 &= ~ V_33 ;
V_23 -> V_32 |= V_34 ;
V_8 = F_12 ( V_2 , V_11 ,
L_4 ) ;
if ( V_8 ) {
V_30 -> V_35 = F_13 ( & V_2 -> V_9 , V_8 ) ;
if ( F_14 ( V_30 -> V_35 ) )
return F_15 ( V_30 -> V_35 ) ;
} else {
V_23 -> V_36 = F_16 ( V_23 , V_37 ) ;
V_23 -> V_36 &= ~ ( V_38 | V_39 ) ;
F_17 ( & V_2 -> V_9 , L_5 ) ;
}
V_23 -> V_40 = F_16 ( V_23 , V_41 ) ;
if ( F_18 ( V_25 , L_6 ) ) {
V_23 -> V_40 &= ~ V_42 ;
V_23 -> V_43 -> V_40 &= ~ V_44 ;
} else {
V_23 -> V_40 &= ~ V_45 ;
}
V_23 -> V_36 &= ~ ( V_46 | V_47 ) ;
return 0 ;
}
static void F_19 ( struct V_22 * V_23 , T_2 V_48 )
{
struct V_1 * V_2 = F_20 ( F_21 ( V_23 -> V_43 ) ) ;
struct V_49 * V_50 = V_2 -> V_9 . V_51 ;
F_22 ( V_23 , V_48 ) ;
if ( V_48 == V_52 ) {
if ( V_50 && 0 != V_50 -> V_53 ) {
T_3 V_54 ;
V_54 = F_23 ( V_23 -> V_55 + V_56 ) ;
V_54 |= ( V_50 -> V_53 & V_57 )
<< V_58 ;
V_54 |= V_59 ;
F_24 ( V_54 , V_23 -> V_55 + V_56 ) ;
}
}
}
static void F_25 ( struct V_22 * V_23 , T_2 V_60 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = V_28 -> V_31 ;
T_3 V_54 ;
int V_61 ;
if ( V_30 -> V_60 == V_62
&& V_60 == V_63 ) {
F_26 ( F_21 ( V_23 -> V_43 ) ,
L_7
L_8 ,
V_64 ,
V_30 -> V_60 ,
V_60 ) ;
V_54 = F_23 ( V_23 -> V_55 + V_65 ) ;
V_54 |= V_66 ;
F_24 ( V_54 , V_23 -> V_55 + V_65 ) ;
V_54 = F_23 ( V_23 -> V_55 + V_67 ) ;
V_54 |= V_68 ;
F_24 ( V_54 , V_23 -> V_55 + V_67 ) ;
F_27 ( 740 ) ;
V_61 = 0 ;
while ( V_61 ++ < V_69 ) {
if ( ( F_23 ( V_23 -> V_55 + V_65 )
& V_70 ) == 0 )
break;
F_27 ( 10 ) ;
}
if ( V_61 == V_69 )
F_17 ( F_21 ( V_23 -> V_43 ) , L_9 ) ;
V_54 = F_23 ( V_23 -> V_55 + V_65 ) ;
V_54 |= V_70 ;
F_24 ( V_54 , V_23 -> V_55 + V_65 ) ;
}
V_30 -> V_60 = V_60 ;
}
static void F_28 ( struct V_22 * V_23 , unsigned int V_71 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = V_28 -> V_31 ;
T_3 V_72 ;
V_72 = F_29 ( V_23 , V_73 ) ;
V_72 &= ~ V_74 ;
switch ( V_71 ) {
case V_75 :
V_72 |= V_76 ;
break;
case V_77 :
V_72 |= V_78 ;
break;
case V_79 :
V_72 |= V_80 | V_81 ;
break;
case V_82 :
V_72 |= V_83 | V_81 ;
break;
case V_84 :
case V_85 :
V_72 |= V_86 | V_81 ;
break;
}
if ( V_30 -> V_35 ) {
T_2 V_87 = F_30 ( V_30 -> V_35 ) ;
if ( V_71 == V_79 ||
V_71 == V_85 ) {
V_87 &= ~ V_88 ;
V_87 |= V_89 ;
} else if ( V_71 == V_90 ) {
V_87 &= ~ V_88 ;
V_87 &= ~ V_89 ;
} else {
V_87 |= V_88 ;
V_87 &= ~ V_89 ;
}
F_31 ( V_87 , V_30 -> V_35 ) ;
}
F_32 ( V_23 , V_72 , V_73 ) ;
F_26 ( F_21 ( V_23 -> V_43 ) ,
L_10 ,
V_64 , V_71 , V_72 ) ;
}
static struct V_49 * F_33 ( struct V_91 * V_9 )
{
struct V_49 * V_50 ;
struct V_24 * V_25 = V_9 -> V_26 ;
T_4 V_53 ;
V_50 = F_34 ( V_9 , sizeof( * V_50 ) , V_92 ) ;
if ( ! V_50 )
return NULL ;
if ( ! F_35 ( V_25 , L_11 ,
& V_53 ) )
V_50 -> V_53 = V_53 ;
return V_50 ;
}
static inline struct V_49 * F_33 ( struct V_91 * V_9 )
{
return NULL ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
struct V_49 * V_50 = V_2 -> V_9 . V_51 ;
struct V_91 * V_9 = & V_2 -> V_9 ;
struct V_24 * V_25 = V_2 -> V_9 . V_26 ;
struct V_22 * V_23 = NULL ;
struct V_29 * V_30 = NULL ;
const struct V_93 * V_94 ;
int V_95 ;
V_30 = F_34 ( & V_2 -> V_9 , sizeof( struct V_29 ) , V_92 ) ;
if ( ! V_30 )
return - V_13 ;
V_23 = F_37 ( V_2 , & V_96 , 0 ) ;
if ( F_14 ( V_23 ) )
return F_15 ( V_23 ) ;
V_28 = F_11 ( V_23 ) ;
V_28 -> V_31 = V_30 ;
V_30 -> V_97 = F_38 ( V_9 , L_12 ) ;
if ( F_14 ( V_30 -> V_97 ) )
V_30 -> V_97 = F_38 ( V_9 , NULL ) ;
if ( F_14 ( V_30 -> V_97 ) ) {
F_2 ( V_9 , L_13 ) ;
V_95 = F_15 ( V_30 -> V_97 ) ;
goto V_98;
}
V_28 -> V_99 = V_30 -> V_97 ;
F_39 ( V_30 -> V_97 ) ;
V_30 -> V_100 = F_38 ( V_9 , L_14 ) ;
if ( ! F_14 ( V_30 -> V_100 ) )
F_39 ( V_30 -> V_100 ) ;
V_23 -> V_43 -> V_40 |= V_44 ;
if ( F_40 ( V_25 , L_15 ) ) {
V_95 = F_10 ( V_2 , V_23 ) ;
if ( V_95 < 0 )
goto V_101;
V_95 = F_1 ( V_2 , F_41 () ) ;
if ( V_95 < 0 )
goto V_101;
}
V_94 = F_42 ( F_43 ( V_102 ) , & V_2 -> V_9 ) ;
if ( V_94 ) {
V_95 = F_44 ( V_23 -> V_43 ) ;
if ( V_95 )
goto V_103;
F_45 ( V_2 ) ;
V_50 = F_33 ( V_9 ) ;
V_2 -> V_9 . V_51 = V_50 ;
} else if ( V_50 ) {
if ( V_50 -> V_104 & V_105 )
V_23 -> V_43 -> V_40 |= V_106 ;
if ( V_50 -> V_104 & V_107 )
V_23 -> V_43 -> V_40 |= V_108 ;
if ( V_50 -> V_32 )
V_23 -> V_32 |= V_50 -> V_32 ;
if ( V_50 -> V_109 )
V_23 -> V_109 |= V_50 -> V_109 ;
if ( V_50 -> V_110 )
V_23 -> V_43 -> V_40 |= V_50 -> V_110 ;
if ( V_50 -> V_111 )
V_23 -> V_43 -> V_112 |= V_50 -> V_111 ;
if ( V_50 -> V_113 )
V_23 -> V_43 -> V_113 |= V_50 -> V_113 ;
if ( F_46 ( V_50 -> V_114 ) ) {
V_95 = F_47 ( V_23 -> V_43 , V_50 -> V_114 ,
0 ) ;
if ( V_95 ) {
F_2 ( F_21 ( V_23 -> V_43 ) ,
L_16 ) ;
goto V_115;
}
}
}
F_48 ( & V_2 -> V_9 ) ;
F_49 ( & V_2 -> V_9 ) ;
F_50 ( & V_2 -> V_9 , V_116 ) ;
F_51 ( & V_2 -> V_9 ) ;
F_52 ( & V_2 -> V_9 ) ;
F_53 ( & V_2 -> V_9 , 1 ) ;
V_95 = F_54 ( V_23 ) ;
if ( V_95 ) {
F_2 ( & V_2 -> V_9 , L_17 ) ;
goto V_117;
}
F_55 ( V_2 , V_23 ) ;
if ( V_23 -> V_43 -> V_113 & V_118 )
F_56 ( & V_2 -> V_9 , 1 ) ;
F_57 ( & V_2 -> V_9 ) ;
return 0 ;
V_117:
F_58 ( & V_2 -> V_9 ) ;
F_59 ( & V_2 -> V_9 ) ;
V_103:
V_115:
V_101:
F_60 ( V_30 -> V_97 ) ;
F_60 ( V_30 -> V_100 ) ;
V_98:
F_61 ( V_2 ) ;
return V_95 ;
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
F_60 ( V_30 -> V_97 ) ;
F_60 ( V_30 -> V_100 ) ;
F_61 ( V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_91 * V_9 )
{
int V_95 ;
struct V_22 * V_23 = F_67 ( V_9 ) ;
F_64 ( V_9 ) ;
V_95 = F_68 ( V_23 ) ;
F_69 ( V_9 ) ;
F_57 ( V_9 ) ;
return V_95 ;
}
static int F_70 ( struct V_91 * V_9 )
{
int V_95 ;
struct V_22 * V_23 = F_67 ( V_9 ) ;
F_64 ( V_9 ) ;
V_95 = F_71 ( V_23 ) ;
F_69 ( V_9 ) ;
F_57 ( V_9 ) ;
return V_95 ;
}
static int F_72 ( struct V_91 * V_9 )
{
struct V_22 * V_23 = F_67 ( V_9 ) ;
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = V_28 -> V_31 ;
int V_95 ;
V_95 = F_73 ( V_23 ) ;
if ( V_95 )
return V_95 ;
F_60 ( V_30 -> V_97 ) ;
if ( ! F_14 ( V_30 -> V_100 ) )
F_60 ( V_30 -> V_100 ) ;
return 0 ;
}
static int F_74 ( struct V_91 * V_9 )
{
struct V_22 * V_23 = F_67 ( V_9 ) ;
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = V_28 -> V_31 ;
F_39 ( V_30 -> V_97 ) ;
if ( ! F_14 ( V_30 -> V_100 ) )
F_39 ( V_30 -> V_100 ) ;
return F_75 ( V_23 ) ;
}
