void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , & V_3 , & V_4 ,
& V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_6 = V_2 -> V_7 ? : V_8 ;
V_2 -> V_9 ( V_2 ) ;
F_4 ( V_2 ) ;
F_5 ( F_6 ( V_2 ) , V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_11 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
int V_14 = 0 ;
if ( ( V_15 ) ( V_16 - V_13 -> V_17 ) > 2 * V_18 || ! V_11 )
V_14 ++ ;
if ( V_2 -> V_7 )
V_14 ++ ;
if ( F_9 ( V_2 , V_14 ) ) {
if ( ( V_15 ) ( V_16 - V_13 -> V_17 ) <= V_19 ||
( ! V_13 -> V_20 && ! V_13 -> V_21 ) )
V_11 = 1 ;
if ( V_11 )
F_10 ( V_2 , V_22 ) ;
F_4 ( V_2 ) ;
F_5 ( F_6 ( V_2 ) , V_23 ) ;
return 1 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_24 )
{
int V_25 = V_26 ;
if ( V_2 -> V_7 && ! V_24 )
V_25 = 0 ;
if ( V_25 == 0 && V_24 )
V_25 = 8 ;
return V_25 ;
}
static void F_12 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
if ( V_29 ) {
if ( ! V_28 -> V_30 . V_31 ) {
V_28 -> V_30 . V_31 = 1 ;
F_13 ( V_2 , V_28 -> V_32 ) ;
} else {
struct V_12 * V_13 = F_8 ( V_2 ) ;
int V_33 ;
V_33 = F_14 ( V_2 , V_28 -> V_30 . V_34 ) >> 1 ;
V_33 = F_15 ( V_35 , V_33 ) ;
V_33 = F_16 ( V_33 , 68 - V_13 -> V_36 ) ;
V_28 -> V_30 . V_34 = F_17 ( V_2 , V_33 ) ;
F_13 ( V_2 , V_28 -> V_32 ) ;
}
}
}
static bool F_18 ( struct V_1 * V_2 ,
unsigned int V_37 ,
unsigned int V_38 ,
bool V_39 )
{
unsigned int V_40 , V_41 ;
unsigned int V_42 = V_39 ? V_43 : V_44 ;
if ( ! F_19 ( V_2 ) -> V_45 )
return false ;
if ( F_20 ( ! F_8 ( V_2 ) -> V_46 ) )
V_41 = F_21 ( F_22 ( V_2 ) ) -> V_47 ;
else
V_41 = F_8 ( V_2 ) -> V_46 ;
if ( F_23 ( V_38 == 0 ) ) {
V_40 = F_24 ( V_18 / V_42 ) ;
if ( V_37 <= V_40 )
V_38 = ( ( 2 << V_37 ) - 1 ) * V_42 ;
else
V_38 = ( ( 2 << V_40 ) - 1 ) * V_42 +
( V_37 - V_40 ) * V_18 ;
}
return ( V_16 - V_41 ) >= V_38 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_19 ( V_2 ) ;
int V_48 ;
bool V_11 , V_39 = false ;
if ( ( 1 << V_2 -> V_49 ) & ( V_50 | V_51 ) ) {
if ( V_28 -> V_45 )
F_26 ( V_2 ) ;
V_48 = V_28 -> V_52 ? : V_53 ;
V_39 = true ;
} else {
if ( F_18 ( V_2 , V_54 , 0 , 0 ) ) {
F_12 ( V_28 , V_2 ) ;
F_26 ( V_2 ) ;
}
V_48 = V_55 ;
if ( F_27 ( V_2 , V_56 ) ) {
const int V_24 = ( V_28 -> V_57 < V_18 ) ;
V_48 = F_11 ( V_2 , V_24 ) ;
V_11 = V_24 ||
! F_18 ( V_2 , V_48 , 0 , 0 ) ;
if ( F_7 ( V_2 , V_11 ) )
return 1 ;
}
}
if ( F_18 ( V_2 , V_48 ,
V_39 ? 0 : V_28 -> V_58 , V_39 ) ) {
F_3 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static void V_4 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_27 * V_28 = F_19 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( F_29 ( V_2 ) ) {
V_28 -> V_60 . V_61 = 1 ;
F_5 ( F_6 ( V_2 ) , V_62 ) ;
F_30 ( V_2 , & V_28 -> V_63 , V_64 + V_65 ) ;
goto V_66;
}
F_31 ( V_2 ) ;
if ( V_2 -> V_49 == V_67 || ! ( V_28 -> V_60 . V_68 & V_69 ) )
goto V_70;
if ( F_32 ( V_28 -> V_60 . V_38 , V_64 ) ) {
F_30 ( V_2 , & V_28 -> V_63 , V_28 -> V_60 . V_38 ) ;
goto V_70;
}
V_28 -> V_60 . V_68 &= ~ V_69 ;
if ( ! F_33 ( & V_13 -> V_71 . V_72 ) ) {
struct V_73 * V_74 ;
F_5 ( F_6 ( V_2 ) , V_75 ) ;
while ( ( V_74 = F_34 ( & V_13 -> V_71 . V_72 ) ) != NULL )
F_35 ( V_2 , V_74 ) ;
V_13 -> V_71 . V_76 = 0 ;
}
if ( F_36 ( V_2 ) ) {
if ( ! V_28 -> V_60 . V_77 ) {
V_28 -> V_60 . V_78 = F_15 ( V_28 -> V_60 . V_78 << 1 , V_28 -> V_57 ) ;
} else {
V_28 -> V_60 . V_77 = 0 ;
V_28 -> V_60 . V_78 = V_79 ;
}
F_37 ( V_2 ) ;
F_5 ( F_6 ( V_2 ) , V_80 ) ;
}
V_70:
if ( F_38 ( V_2 ) )
F_39 ( V_2 ) ;
V_66:
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_19 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
int V_81 ;
if ( V_13 -> V_21 || ! F_43 ( V_2 ) ) {
V_28 -> V_82 = 0 ;
return;
}
V_81 = V_55 ;
if ( F_27 ( V_2 , V_56 ) ) {
const int V_24 = ( ( V_28 -> V_57 << V_28 -> V_83 ) < V_18 ) ;
V_81 = F_11 ( V_2 , V_24 ) ;
if ( F_7 ( V_2 , V_24 || V_28 -> V_82 <= V_81 ) )
return;
}
if ( V_28 -> V_82 > V_81 ) {
F_3 ( V_2 ) ;
} else {
F_44 ( V_2 ) ;
}
}
void F_45 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_27 * V_28 = F_19 ( V_2 ) ;
if ( V_13 -> V_84 ) {
F_46 ( V_2 ) ;
return;
}
if ( ! V_13 -> V_21 )
goto V_70;
F_47 ( F_48 ( V_2 ) ) ;
if ( ! V_13 -> V_20 && ! F_27 ( V_2 , V_56 ) &&
! ( ( 1 << V_2 -> V_49 ) & ( V_50 | V_51 ) ) ) {
struct V_85 * V_86 = F_49 ( V_2 ) ;
if ( V_2 -> V_87 == V_88 ) {
F_50 (KERN_DEBUG pr_fmt(L_1),
&inet->inet_daddr,
ntohs(inet->inet_dport), inet->inet_num,
tp->snd_una, tp->snd_nxt) ;
}
#if F_51 ( V_89 )
else if ( V_2 -> V_87 == V_90 ) {
struct V_91 * V_92 = F_52 ( V_2 ) ;
F_50 (KERN_DEBUG pr_fmt(L_2),
&np->daddr,
ntohs(inet->inet_dport), inet->inet_num,
tp->snd_una, tp->snd_nxt) ;
}
#endif
if ( V_16 - V_13 -> V_93 > V_18 ) {
F_3 ( V_2 ) ;
goto V_70;
}
F_53 ( V_2 , 0 ) ;
F_54 ( V_2 , F_22 ( V_2 ) ) ;
F_55 ( V_2 ) ;
goto V_94;
}
if ( F_25 ( V_2 ) )
goto V_70;
if ( V_28 -> V_45 == 0 ) {
int V_95 ;
if ( V_28 -> V_96 == V_97 ) {
if ( F_56 ( V_13 ) )
V_95 = V_98 ;
else
V_95 = V_99 ;
} else if ( V_28 -> V_96 == V_100 ) {
V_95 = V_101 ;
} else if ( ( V_28 -> V_96 == V_102 ) ||
V_13 -> V_103 ) {
if ( F_56 ( V_13 ) )
V_95 = V_104 ;
else
V_95 = V_105 ;
} else {
V_95 = V_106 ;
}
F_5 ( F_6 ( V_2 ) , V_95 ) ;
}
if ( F_57 ( V_2 ) ) {
F_58 ( V_2 ) ;
} else {
F_53 ( V_2 , 0 ) ;
}
if ( F_54 ( V_2 , F_22 ( V_2 ) ) > 0 ) {
if ( ! V_28 -> V_45 )
V_28 -> V_45 = 1 ;
F_59 ( V_2 , V_107 ,
F_15 ( V_28 -> V_57 , V_108 ) ,
V_18 ) ;
goto V_70;
}
V_28 -> V_83 ++ ;
V_28 -> V_45 ++ ;
V_94:
if ( V_2 -> V_49 == V_109 &&
( V_13 -> V_110 || V_111 ) &&
F_60 ( V_13 ) &&
V_28 -> V_45 <= V_112 ) {
V_28 -> V_83 = 0 ;
V_28 -> V_57 = F_15 ( F_61 ( V_13 ) , V_18 ) ;
} else {
V_28 -> V_57 = F_15 ( V_28 -> V_57 << 1 , V_18 ) ;
}
F_59 ( V_2 , V_107 , V_28 -> V_57 , V_18 ) ;
if ( F_18 ( V_2 , V_54 + 1 , 0 , 0 ) )
F_55 ( V_2 ) ;
V_70: ;
}
static void V_3 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
struct V_27 * V_28 = F_19 ( V_2 ) ;
int V_113 ;
F_28 ( V_2 ) ;
if ( F_29 ( V_2 ) ) {
F_30 ( V_2 , & V_28 -> V_114 , V_64 + ( V_115 / 20 ) ) ;
goto V_66;
}
if ( V_2 -> V_49 == V_67 || ! V_28 -> V_116 )
goto V_70;
if ( F_32 ( V_28 -> V_117 , V_64 ) ) {
F_30 ( V_2 , & V_28 -> V_114 , V_28 -> V_117 ) ;
goto V_70;
}
V_113 = V_28 -> V_116 ;
V_28 -> V_116 = 0 ;
switch ( V_113 ) {
case V_107 :
F_45 ( V_2 ) ;
break;
case V_118 :
F_42 ( V_2 ) ;
break;
}
V_70:
F_39 ( V_2 ) ;
V_66:
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 , V_119 ,
V_43 , V_18 ) ;
}
void F_64 ( struct V_1 * V_2 , struct V_120 * V_121 )
{
F_5 ( F_6 ( V_2 ) , V_106 ) ;
}
void F_65 ( struct V_1 * V_2 , int V_122 )
{
if ( ( 1 << V_2 -> V_49 ) & ( V_123 | V_124 ) )
return;
if ( V_122 && ! F_27 ( V_2 , V_125 ) )
F_66 ( V_2 , F_67 ( F_8 ( V_2 ) ) ) ;
else if ( ! V_122 )
F_68 ( V_2 ) ;
}
static void V_5 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
struct V_27 * V_28 = F_19 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
T_1 V_126 ;
F_28 ( V_2 ) ;
if ( F_29 ( V_2 ) ) {
F_66 ( V_2 , V_115 / 20 ) ;
goto V_70;
}
if ( V_2 -> V_49 == V_127 ) {
F_62 ( V_2 ) ;
goto V_70;
}
if ( V_2 -> V_49 == V_128 && F_27 ( V_2 , V_56 ) ) {
if ( V_13 -> V_129 >= 0 ) {
const int V_130 = F_69 ( V_2 ) - V_19 ;
if ( V_130 > 0 ) {
F_70 ( V_2 , V_128 , V_130 ) ;
goto V_70;
}
}
F_10 ( V_2 , V_22 ) ;
goto V_131;
}
if ( ! F_27 ( V_2 , V_125 ) || V_2 -> V_49 == V_67 )
goto V_70;
V_126 = F_67 ( V_13 ) ;
if ( V_13 -> V_21 || F_43 ( V_2 ) )
goto V_132;
V_126 = F_71 ( V_13 ) ;
if ( V_126 >= F_67 ( V_13 ) ) {
if ( ( V_28 -> V_58 != 0 &&
V_126 >= V_28 -> V_58 &&
V_28 -> V_82 > 0 ) ||
( V_28 -> V_58 == 0 &&
V_28 -> V_82 >= F_72 ( V_13 ) ) ) {
F_10 ( V_2 , V_22 ) ;
F_3 ( V_2 ) ;
goto V_70;
}
if ( F_73 ( V_2 ) <= 0 ) {
V_28 -> V_82 ++ ;
V_126 = F_74 ( V_13 ) ;
} else {
V_126 = V_108 ;
}
} else {
V_126 = F_67 ( V_13 ) - V_126 ;
}
F_39 ( V_2 ) ;
V_132:
F_66 ( V_2 , V_126 ) ;
goto V_70;
V_131:
F_4 ( V_2 ) ;
V_70:
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
}
