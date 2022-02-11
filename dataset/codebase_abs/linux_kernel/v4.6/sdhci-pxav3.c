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
struct V_29 * V_30 = F_12 ( V_28 ) ;
struct V_7 * V_8 ;
V_23 -> V_31 &= ~ V_32 ;
V_23 -> V_31 |= V_33 ;
V_23 -> V_34 = F_13 ( V_23 , V_35 ) ;
V_23 -> V_36 = F_13 ( V_23 , V_37 ) ;
V_8 = F_14 ( V_2 , V_11 ,
L_4 ) ;
if ( V_8 ) {
V_30 -> V_38 = F_15 ( & V_2 -> V_9 , V_8 ) ;
if ( F_16 ( V_30 -> V_38 ) )
return F_17 ( V_30 -> V_38 ) ;
} else {
V_23 -> V_36 &= ~ ( V_39 | V_40 ) ;
F_18 ( & V_2 -> V_9 , L_5 ) ;
}
if ( F_19 ( V_25 , L_6 ) ) {
V_23 -> V_34 &= ~ V_41 ;
V_23 -> V_42 -> V_34 &= ~ V_43 ;
} else {
V_23 -> V_34 &= ~ V_44 ;
}
V_23 -> V_36 &= ~ ( V_45 | V_46 ) ;
return 0 ;
}
static void F_20 ( struct V_22 * V_23 , T_2 V_47 )
{
struct V_1 * V_2 = F_21 ( F_22 ( V_23 -> V_42 ) ) ;
struct V_48 * V_49 = V_2 -> V_9 . V_50 ;
F_23 ( V_23 , V_47 ) ;
if ( V_47 == V_51 ) {
if ( V_49 && 0 != V_49 -> V_52 ) {
T_3 V_53 ;
V_53 = F_24 ( V_23 -> V_54 + V_55 ) ;
V_53 |= ( V_49 -> V_52 & V_56 )
<< V_57 ;
V_53 |= V_58 ;
F_25 ( V_53 , V_23 -> V_54 + V_55 ) ;
}
}
}
static void F_26 ( struct V_22 * V_23 , T_2 V_59 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
T_3 V_53 ;
int V_60 ;
if ( V_30 -> V_59 == V_61
&& V_59 == V_62 ) {
F_27 ( F_22 ( V_23 -> V_42 ) ,
L_7
L_8 ,
V_63 ,
V_30 -> V_59 ,
V_59 ) ;
V_53 = F_24 ( V_23 -> V_54 + V_64 ) ;
V_53 |= V_65 ;
F_25 ( V_53 , V_23 -> V_54 + V_64 ) ;
V_53 = F_24 ( V_23 -> V_54 + V_66 ) ;
V_53 |= V_67 ;
F_25 ( V_53 , V_23 -> V_54 + V_66 ) ;
F_28 ( 740 ) ;
V_60 = 0 ;
while ( V_60 ++ < V_68 ) {
if ( ( F_24 ( V_23 -> V_54 + V_64 )
& V_69 ) == 0 )
break;
F_28 ( 10 ) ;
}
if ( V_60 == V_68 )
F_18 ( F_22 ( V_23 -> V_42 ) , L_9 ) ;
V_53 = F_24 ( V_23 -> V_54 + V_64 ) ;
V_53 |= V_69 ;
F_25 ( V_53 , V_23 -> V_54 + V_64 ) ;
}
V_30 -> V_59 = V_59 ;
}
static void F_29 ( struct V_22 * V_23 , unsigned int V_70 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
T_3 V_71 ;
V_71 = F_30 ( V_23 , V_72 ) ;
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
if ( V_30 -> V_38 ) {
T_2 V_86 = F_31 ( V_30 -> V_38 ) ;
if ( V_70 == V_78 ||
V_70 == V_84 ) {
V_86 &= ~ V_87 ;
V_86 |= V_88 ;
} else if ( V_70 == V_89 ) {
V_86 &= ~ V_87 ;
V_86 &= ~ V_88 ;
} else {
V_86 |= V_87 ;
V_86 &= ~ V_88 ;
}
F_32 ( V_86 , V_30 -> V_38 ) ;
}
F_33 ( V_23 , V_71 , V_72 ) ;
F_27 ( F_22 ( V_23 -> V_42 ) ,
L_10 ,
V_63 , V_70 , V_71 ) ;
}
static void F_34 ( struct V_22 * V_23 , unsigned char V_90 ,
unsigned short V_91 )
{
struct V_92 * V_42 = V_23 -> V_42 ;
T_2 V_93 = V_23 -> V_93 ;
F_35 ( V_23 , V_90 , V_91 ) ;
if ( V_23 -> V_93 == V_93 )
return;
if ( V_23 -> V_93 == 0 )
V_91 = 0 ;
if ( ! F_16 ( V_42 -> V_94 . V_95 ) ) {
F_36 ( & V_23 -> V_96 ) ;
F_37 ( V_42 , V_42 -> V_94 . V_95 , V_91 ) ;
F_38 ( & V_23 -> V_96 ) ;
}
}
static struct V_48 * F_39 ( struct V_97 * V_9 )
{
struct V_48 * V_49 ;
struct V_24 * V_25 = V_9 -> V_26 ;
T_4 V_52 ;
V_49 = F_40 ( V_9 , sizeof( * V_49 ) , V_98 ) ;
if ( ! V_49 )
return NULL ;
if ( ! F_41 ( V_25 , L_11 ,
& V_52 ) )
V_49 -> V_52 = V_52 ;
return V_49 ;
}
static inline struct V_48 * F_39 ( struct V_97 * V_9 )
{
return NULL ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
struct V_48 * V_49 = V_2 -> V_9 . V_50 ;
struct V_97 * V_9 = & V_2 -> V_9 ;
struct V_24 * V_25 = V_2 -> V_9 . V_26 ;
struct V_22 * V_23 = NULL ;
struct V_29 * V_30 = NULL ;
const struct V_99 * V_100 ;
int V_101 ;
V_23 = F_43 ( V_2 , & V_102 , sizeof( * V_30 ) ) ;
if ( F_16 ( V_23 ) )
return F_17 ( V_23 ) ;
V_28 = F_11 ( V_23 ) ;
V_30 = F_12 ( V_28 ) ;
V_30 -> V_103 = F_44 ( V_9 , L_12 ) ;
if ( F_16 ( V_30 -> V_103 ) )
V_30 -> V_103 = F_44 ( V_9 , NULL ) ;
if ( F_16 ( V_30 -> V_103 ) ) {
F_2 ( V_9 , L_13 ) ;
V_101 = F_17 ( V_30 -> V_103 ) ;
goto V_104;
}
V_28 -> V_105 = V_30 -> V_103 ;
F_45 ( V_30 -> V_103 ) ;
V_30 -> V_106 = F_44 ( V_9 , L_14 ) ;
if ( ! F_16 ( V_30 -> V_106 ) )
F_45 ( V_30 -> V_106 ) ;
V_23 -> V_42 -> V_34 |= V_43 ;
if ( F_46 ( V_25 , L_15 ) ) {
V_101 = F_10 ( V_2 , V_23 ) ;
if ( V_101 < 0 )
goto V_107;
V_101 = F_1 ( V_2 , F_47 () ) ;
if ( V_101 < 0 )
goto V_107;
}
V_100 = F_48 ( F_49 ( V_108 ) , & V_2 -> V_9 ) ;
if ( V_100 ) {
V_101 = F_50 ( V_23 -> V_42 ) ;
if ( V_101 )
goto V_109;
F_51 ( V_2 ) ;
V_49 = F_39 ( V_9 ) ;
V_2 -> V_9 . V_50 = V_49 ;
} else if ( V_49 ) {
if ( V_49 -> V_110 & V_111 )
V_23 -> V_42 -> V_34 |= V_112 ;
if ( V_49 -> V_110 & V_113 )
V_23 -> V_42 -> V_34 |= V_114 ;
if ( V_49 -> V_31 )
V_23 -> V_31 |= V_49 -> V_31 ;
if ( V_49 -> V_115 )
V_23 -> V_115 |= V_49 -> V_115 ;
if ( V_49 -> V_116 )
V_23 -> V_42 -> V_34 |= V_49 -> V_116 ;
if ( V_49 -> V_117 )
V_23 -> V_42 -> V_118 |= V_49 -> V_117 ;
if ( V_49 -> V_119 )
V_23 -> V_42 -> V_119 |= V_49 -> V_119 ;
if ( F_52 ( V_49 -> V_120 ) ) {
V_101 = F_53 ( V_23 -> V_42 , V_49 -> V_120 ,
0 ) ;
if ( V_101 ) {
F_2 ( F_22 ( V_23 -> V_42 ) ,
L_16 ) ;
goto V_121;
}
}
}
F_54 ( & V_2 -> V_9 ) ;
F_55 ( & V_2 -> V_9 ) ;
F_56 ( & V_2 -> V_9 , V_122 ) ;
F_57 ( & V_2 -> V_9 ) ;
F_58 ( & V_2 -> V_9 ) ;
F_59 ( & V_2 -> V_9 , 1 ) ;
V_101 = F_60 ( V_23 ) ;
if ( V_101 ) {
F_2 ( & V_2 -> V_9 , L_17 ) ;
goto V_123;
}
F_61 ( V_2 , V_23 ) ;
if ( V_23 -> V_42 -> V_119 & V_124 )
F_62 ( & V_2 -> V_9 , 1 ) ;
F_63 ( & V_2 -> V_9 ) ;
return 0 ;
V_123:
F_64 ( & V_2 -> V_9 ) ;
F_65 ( & V_2 -> V_9 ) ;
V_109:
V_121:
V_107:
F_66 ( V_30 -> V_103 ) ;
F_66 ( V_30 -> V_106 ) ;
V_104:
F_67 ( V_2 ) ;
return V_101 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_69 ( V_2 ) ;
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
F_70 ( & V_2 -> V_9 ) ;
F_64 ( & V_2 -> V_9 ) ;
F_65 ( & V_2 -> V_9 ) ;
F_71 ( V_23 , 1 ) ;
F_66 ( V_30 -> V_103 ) ;
F_66 ( V_30 -> V_106 ) ;
F_67 ( V_2 ) ;
return 0 ;
}
static int F_72 ( struct V_97 * V_9 )
{
int V_101 ;
struct V_22 * V_23 = F_73 ( V_9 ) ;
F_70 ( V_9 ) ;
V_101 = F_74 ( V_23 ) ;
F_75 ( V_9 ) ;
F_63 ( V_9 ) ;
return V_101 ;
}
static int F_76 ( struct V_97 * V_9 )
{
int V_101 ;
struct V_22 * V_23 = F_73 ( V_9 ) ;
F_70 ( V_9 ) ;
V_101 = F_77 ( V_23 ) ;
F_75 ( V_9 ) ;
F_63 ( V_9 ) ;
return V_101 ;
}
static int F_78 ( struct V_97 * V_9 )
{
struct V_22 * V_23 = F_73 ( V_9 ) ;
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
int V_101 ;
V_101 = F_79 ( V_23 ) ;
if ( V_101 )
return V_101 ;
F_66 ( V_30 -> V_103 ) ;
if ( ! F_16 ( V_30 -> V_106 ) )
F_66 ( V_30 -> V_106 ) ;
return 0 ;
}
static int F_80 ( struct V_97 * V_9 )
{
struct V_22 * V_23 = F_73 ( V_9 ) ;
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
F_45 ( V_30 -> V_103 ) ;
if ( ! F_16 ( V_30 -> V_106 ) )
F_45 ( V_30 -> V_106 ) ;
return F_81 ( V_23 ) ;
}
