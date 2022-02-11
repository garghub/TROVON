static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_4 ? : V_5 ;
V_2 -> V_6 ( V_2 ) ;
F_2 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_8 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_11 = 0 ;
if ( ( V_12 ) ( V_13 - V_10 -> V_14 ) > 2 * V_15 || ! V_8 )
V_11 ++ ;
if ( V_2 -> V_4 )
V_11 ++ ;
if ( F_7 ( V_2 , V_11 ) ) {
if ( ( V_12 ) ( V_13 - V_10 -> V_14 ) <= V_16 ||
( ! V_10 -> V_17 && ! V_10 -> V_18 ) )
V_8 = 1 ;
if ( V_8 )
F_8 ( V_2 , V_19 ) ;
F_2 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , V_20 ) ;
return 1 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_21 )
{
int V_22 = V_23 ;
if ( V_2 -> V_4 && ! V_21 )
V_22 = 0 ;
if ( V_22 == 0 && V_21 )
V_22 = 8 ;
return V_22 ;
}
static void F_10 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
if ( V_26 ) {
if ( ! V_25 -> V_27 . V_28 ) {
V_25 -> V_27 . V_28 = 1 ;
F_11 ( V_2 , V_25 -> V_29 ) ;
} else {
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_30 ;
V_30 = F_12 ( V_2 , V_25 -> V_27 . V_31 ) >> 1 ;
V_30 = F_13 ( V_32 , V_30 ) ;
V_30 = F_14 ( V_30 , 68 - V_10 -> V_33 ) ;
V_25 -> V_27 . V_31 = F_15 ( V_2 , V_30 ) ;
F_11 ( V_2 , V_25 -> V_29 ) ;
}
}
}
static bool F_16 ( struct V_1 * V_2 ,
unsigned int V_34 ,
unsigned int V_35 ,
bool V_36 )
{
unsigned int V_37 , V_38 ;
unsigned int V_39 = V_36 ? V_40 : V_41 ;
if ( ! F_17 ( V_2 ) -> V_42 )
return false ;
if ( F_18 ( ! F_6 ( V_2 ) -> V_43 ) )
V_38 = F_19 ( F_20 ( V_2 ) ) -> V_44 ;
else
V_38 = F_6 ( V_2 ) -> V_43 ;
if ( F_21 ( V_35 == 0 ) ) {
V_37 = F_22 ( V_15 / V_39 ) ;
if ( V_34 <= V_37 )
V_35 = ( ( 2 << V_34 ) - 1 ) * V_39 ;
else
V_35 = ( ( 2 << V_37 ) - 1 ) * V_39 +
( V_34 - V_37 ) * V_15 ;
}
return ( V_13 - V_38 ) >= V_35 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_45 ;
bool V_8 , V_36 = false ;
if ( ( 1 << V_2 -> V_46 ) & ( V_47 | V_48 ) ) {
if ( V_25 -> V_42 ) {
F_24 ( V_2 ) ;
if ( V_10 -> V_49 || V_10 -> V_50 )
F_25 ( V_2 , 0 , NULL , true ) ;
if ( V_10 -> V_50 )
F_3 ( F_4 ( V_2 ) ,
V_51 ) ;
}
V_45 = V_25 -> V_52 ? : V_53 ;
V_36 = true ;
} else {
if ( F_16 ( V_2 , V_54 , 0 , 0 ) ) {
F_10 ( V_25 , V_2 ) ;
F_24 ( V_2 ) ;
}
V_45 = V_55 ;
if ( F_26 ( V_2 , V_56 ) ) {
const int V_21 = ( V_25 -> V_57 < V_15 ) ;
V_45 = F_9 ( V_2 , V_21 ) ;
V_8 = V_21 ||
! F_16 ( V_2 , V_45 , 0 , 0 ) ;
if ( F_5 ( V_2 , V_8 ) )
return 1 ;
}
}
if ( F_16 ( V_2 , V_45 ,
V_36 ? 0 : V_25 -> V_58 , V_36 ) ) {
F_1 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_24 * V_25 = F_17 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( V_2 -> V_46 == V_59 || ! ( V_25 -> V_60 . V_61 & V_62 ) )
goto V_63;
if ( F_29 ( V_25 -> V_60 . V_35 , V_64 ) ) {
F_30 ( V_2 , & V_25 -> V_65 , V_25 -> V_60 . V_35 ) ;
goto V_63;
}
V_25 -> V_60 . V_61 &= ~ V_62 ;
if ( ! F_31 ( & V_10 -> V_66 . V_67 ) ) {
struct V_68 * V_69 ;
F_3 ( F_4 ( V_2 ) , V_70 ) ;
while ( ( V_69 = F_32 ( & V_10 -> V_66 . V_67 ) ) != NULL )
F_33 ( V_2 , V_69 ) ;
V_10 -> V_66 . V_71 = 0 ;
}
if ( F_34 ( V_2 ) ) {
if ( ! V_25 -> V_60 . V_72 ) {
V_25 -> V_60 . V_73 = F_13 ( V_25 -> V_60 . V_73 << 1 , V_25 -> V_57 ) ;
} else {
V_25 -> V_60 . V_72 = 0 ;
V_25 -> V_60 . V_73 = V_74 ;
}
F_35 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , V_75 ) ;
}
V_63:
if ( F_36 ( V_2 ) )
F_37 ( V_2 ) ;
}
static void F_38 ( unsigned long V_76 )
{
struct V_1 * V_2 = (struct V_1 * ) V_76 ;
F_39 ( V_2 ) ;
if ( ! F_40 ( V_2 ) ) {
F_27 ( V_2 ) ;
} else {
F_17 ( V_2 ) -> V_60 . V_77 = 1 ;
F_3 ( F_4 ( V_2 ) , V_78 ) ;
if ( ! F_41 ( V_79 , & F_6 ( V_2 ) -> V_80 ) )
F_42 ( V_2 ) ;
}
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_81 ;
if ( V_10 -> V_18 || ! F_46 ( V_2 ) ) {
V_25 -> V_82 = 0 ;
return;
}
V_81 = V_55 ;
if ( F_26 ( V_2 , V_56 ) ) {
const int V_21 = ( ( V_25 -> V_57 << V_25 -> V_83 ) < V_15 ) ;
V_81 = F_9 ( V_2 , V_21 ) ;
if ( F_5 ( V_2 , V_21 || V_25 -> V_82 <= V_81 ) )
return;
}
if ( V_25 -> V_82 > V_81 ) {
F_1 ( V_2 ) ;
} else {
F_47 ( V_2 ) ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
int V_84 = V_25 -> V_52 ? :
V_85 + 1 ;
struct V_86 * V_87 ;
V_87 = F_6 ( V_2 ) -> V_88 ;
V_87 -> V_89 -> V_90 ( V_2 , V_87 ) ;
if ( V_87 -> V_91 >= V_84 ) {
F_1 ( V_2 ) ;
return;
}
F_49 ( V_2 , V_87 ) ;
V_87 -> V_91 ++ ;
F_50 ( V_2 , V_92 ,
V_40 << V_87 -> V_91 , V_15 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_24 * V_25 = F_17 ( V_2 ) ;
if ( V_10 -> V_88 ) {
F_52 ( V_2 -> V_46 != V_93 &&
V_2 -> V_46 != V_94 ) ;
F_48 ( V_2 ) ;
return;
}
if ( ! V_10 -> V_18 )
goto V_63;
F_53 ( F_54 ( V_2 ) ) ;
V_10 -> V_95 = 0 ;
if ( ! V_10 -> V_17 && ! F_26 ( V_2 , V_56 ) &&
! ( ( 1 << V_2 -> V_46 ) & ( V_47 | V_48 ) ) ) {
struct V_96 * V_97 = F_55 ( V_2 ) ;
if ( V_2 -> V_98 == V_99 ) {
F_56 (KERN_DEBUG pr_fmt(L_1),
&inet->inet_daddr,
ntohs(inet->inet_dport), inet->inet_num,
tp->snd_una, tp->snd_nxt) ;
}
#if F_57 ( V_100 )
else if ( V_2 -> V_98 == V_101 ) {
F_56 (KERN_DEBUG pr_fmt(L_2),
&sk->sk_v6_daddr,
ntohs(inet->inet_dport), inet->inet_num,
tp->snd_una, tp->snd_nxt) ;
}
#endif
if ( V_13 - V_10 -> V_102 > V_15 ) {
F_1 ( V_2 ) ;
goto V_63;
}
F_58 ( V_2 , 0 ) ;
F_59 ( V_2 , F_20 ( V_2 ) ) ;
F_60 ( V_2 ) ;
goto V_103;
}
if ( F_23 ( V_2 ) )
goto V_63;
if ( V_25 -> V_42 == 0 ) {
int V_104 ;
if ( V_25 -> V_105 == V_106 ) {
if ( F_61 ( V_10 ) )
V_104 = V_107 ;
else
V_104 = V_108 ;
} else if ( V_25 -> V_105 == V_109 ) {
V_104 = V_110 ;
} else if ( ( V_25 -> V_105 == V_111 ) ||
V_10 -> V_112 ) {
if ( F_61 ( V_10 ) )
V_104 = V_113 ;
else
V_104 = V_114 ;
} else {
V_104 = V_115 ;
}
F_3 ( F_4 ( V_2 ) , V_104 ) ;
}
F_58 ( V_2 , 0 ) ;
if ( F_59 ( V_2 , F_20 ( V_2 ) ) > 0 ) {
if ( ! V_25 -> V_42 )
V_25 -> V_42 = 1 ;
F_50 ( V_2 , V_92 ,
F_13 ( V_25 -> V_57 , V_116 ) ,
V_15 ) ;
goto V_63;
}
V_25 -> V_83 ++ ;
V_25 -> V_42 ++ ;
V_103:
if ( V_2 -> V_46 == V_117 &&
( V_10 -> V_118 || V_119 ) &&
F_62 ( V_10 ) &&
V_25 -> V_42 <= V_120 ) {
V_25 -> V_83 = 0 ;
V_25 -> V_57 = F_13 ( F_63 ( V_10 ) , V_15 ) ;
} else {
V_25 -> V_57 = F_13 ( V_25 -> V_57 << 1 , V_15 ) ;
}
F_50 ( V_2 , V_92 , V_25 -> V_57 , V_15 ) ;
if ( F_16 ( V_2 , V_54 + 1 , 0 , 0 ) )
F_60 ( V_2 ) ;
V_63: ;
}
void F_64 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
int V_121 ;
if ( V_2 -> V_46 == V_59 || ! V_25 -> V_122 )
goto V_63;
if ( F_29 ( V_25 -> V_123 , V_64 ) ) {
F_30 ( V_2 , & V_25 -> V_124 , V_25 -> V_123 ) ;
goto V_63;
}
V_121 = V_25 -> V_122 ;
switch ( V_121 ) {
case V_125 :
F_65 ( V_2 ) ;
break;
case V_126 :
F_66 ( V_2 ) ;
break;
case V_92 :
V_25 -> V_122 = 0 ;
F_51 ( V_2 ) ;
break;
case V_127 :
V_25 -> V_122 = 0 ;
F_45 ( V_2 ) ;
break;
}
V_63:
F_37 ( V_2 ) ;
}
static void F_67 ( unsigned long V_76 )
{
struct V_1 * V_2 = (struct V_1 * ) V_76 ;
F_39 ( V_2 ) ;
if ( ! F_40 ( V_2 ) ) {
F_64 ( V_2 ) ;
} else {
if ( ! F_41 ( V_128 , & F_6 ( V_2 ) -> V_80 ) )
F_42 ( V_2 ) ;
}
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_69 ( V_2 , V_129 ,
V_40 , V_15 ) ;
}
void F_70 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
F_3 ( F_4 ( V_2 ) , V_115 ) ;
}
void F_71 ( struct V_1 * V_2 , int V_130 )
{
if ( ( 1 << V_2 -> V_46 ) & ( V_131 | V_132 ) )
return;
if ( V_130 && ! F_26 ( V_2 , V_133 ) )
F_72 ( V_2 , F_73 ( F_6 ( V_2 ) ) ) ;
else if ( ! V_130 )
F_74 ( V_2 ) ;
}
static void F_75 ( unsigned long V_76 )
{
struct V_1 * V_2 = (struct V_1 * ) V_76 ;
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_1 V_134 ;
F_39 ( V_2 ) ;
if ( F_40 ( V_2 ) ) {
F_72 ( V_2 , V_135 / 20 ) ;
goto V_63;
}
if ( V_2 -> V_46 == V_136 ) {
F_68 ( V_2 ) ;
goto V_63;
}
if ( V_2 -> V_46 == V_137 && F_26 ( V_2 , V_56 ) ) {
if ( V_10 -> V_138 >= 0 ) {
const int V_139 = F_76 ( V_2 ) - V_16 ;
if ( V_139 > 0 ) {
F_77 ( V_2 , V_137 , V_139 ) ;
goto V_63;
}
}
F_8 ( V_2 , V_19 ) ;
goto V_140;
}
if ( ! F_26 ( V_2 , V_133 ) || V_2 -> V_46 == V_59 )
goto V_63;
V_134 = F_73 ( V_10 ) ;
if ( V_10 -> V_18 || F_46 ( V_2 ) )
goto V_141;
V_134 = F_78 ( V_10 ) ;
if ( V_134 >= F_73 ( V_10 ) ) {
if ( ( V_25 -> V_58 != 0 &&
V_134 >= V_25 -> V_58 &&
V_25 -> V_82 > 0 ) ||
( V_25 -> V_58 == 0 &&
V_25 -> V_82 >= F_79 ( V_10 ) ) ) {
F_8 ( V_2 , V_19 ) ;
F_1 ( V_2 ) ;
goto V_63;
}
if ( F_80 ( V_2 ) <= 0 ) {
V_25 -> V_82 ++ ;
V_134 = F_81 ( V_10 ) ;
} else {
V_134 = V_116 ;
}
} else {
V_134 = F_73 ( V_10 ) - V_134 ;
}
F_37 ( V_2 ) ;
V_141:
F_72 ( V_2 , V_134 ) ;
goto V_63;
V_140:
F_2 ( V_2 ) ;
V_63:
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
F_83 ( V_2 , & F_67 , & F_38 ,
& F_75 ) ;
}
