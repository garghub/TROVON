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
}
V_45 = V_25 -> V_51 ? : V_52 ;
V_36 = true ;
} else {
if ( F_16 ( V_2 , V_53 , 0 , 0 ) ) {
F_10 ( V_25 , V_2 ) ;
F_24 ( V_2 ) ;
}
V_45 = V_54 ;
if ( F_26 ( V_2 , V_55 ) ) {
const int V_21 = ( V_25 -> V_56 < V_15 ) ;
V_45 = F_9 ( V_2 , V_21 ) ;
V_8 = V_21 ||
! F_16 ( V_2 , V_45 , 0 , 0 ) ;
if ( F_5 ( V_2 , V_8 ) )
return 1 ;
}
}
if ( F_16 ( V_2 , V_45 ,
V_36 ? 0 : V_25 -> V_57 , V_36 ) ) {
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
if ( V_2 -> V_46 == V_58 || ! ( V_25 -> V_59 . V_60 & V_61 ) )
goto V_62;
if ( F_29 ( V_25 -> V_59 . V_35 , V_63 ) ) {
F_30 ( V_2 , & V_25 -> V_64 , V_25 -> V_59 . V_35 ) ;
goto V_62;
}
V_25 -> V_59 . V_60 &= ~ V_61 ;
if ( ! F_31 ( & V_10 -> V_65 . V_66 ) ) {
struct V_67 * V_68 ;
F_3 ( F_4 ( V_2 ) , V_69 ) ;
while ( ( V_68 = F_32 ( & V_10 -> V_65 . V_66 ) ) != NULL )
F_33 ( V_2 , V_68 ) ;
V_10 -> V_65 . V_70 = 0 ;
}
if ( F_34 ( V_2 ) ) {
if ( ! V_25 -> V_59 . V_71 ) {
V_25 -> V_59 . V_72 = F_13 ( V_25 -> V_59 . V_72 << 1 , V_25 -> V_56 ) ;
} else {
V_25 -> V_59 . V_71 = 0 ;
V_25 -> V_59 . V_72 = V_73 ;
}
F_35 ( V_2 ) ;
F_3 ( F_4 ( V_2 ) , V_74 ) ;
}
V_62:
if ( F_36 ( V_2 ) )
F_37 ( V_2 ) ;
}
static void F_38 ( unsigned long V_75 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
F_39 ( V_2 ) ;
if ( ! F_40 ( V_2 ) ) {
F_27 ( V_2 ) ;
} else {
F_17 ( V_2 ) -> V_59 . V_76 = 1 ;
F_3 ( F_4 ( V_2 ) , V_77 ) ;
if ( ! F_41 ( V_78 , & F_6 ( V_2 ) -> V_79 ) )
F_42 ( V_2 ) ;
}
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_80 ;
if ( V_10 -> V_18 || ! F_46 ( V_2 ) ) {
V_25 -> V_81 = 0 ;
return;
}
V_80 = V_54 ;
if ( F_26 ( V_2 , V_55 ) ) {
const int V_21 = ( ( V_25 -> V_56 << V_25 -> V_82 ) < V_15 ) ;
V_80 = F_9 ( V_2 , V_21 ) ;
if ( F_5 ( V_2 , V_21 || V_25 -> V_81 <= V_80 ) )
return;
}
if ( V_25 -> V_81 > V_80 ) {
F_1 ( V_2 ) ;
} else {
F_47 ( V_2 ) ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
int V_83 = V_25 -> V_51 ? :
V_84 + 1 ;
struct V_85 * V_86 ;
V_86 = F_6 ( V_2 ) -> V_87 ;
V_86 -> V_88 -> V_89 ( V_2 , V_86 ) ;
if ( V_86 -> V_90 >= V_83 ) {
F_1 ( V_2 ) ;
return;
}
F_49 ( V_2 , V_86 ) ;
V_86 -> V_90 ++ ;
F_50 ( V_2 , V_91 ,
V_40 << V_86 -> V_90 , V_15 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
struct V_24 * V_25 = F_17 ( V_2 ) ;
if ( V_10 -> V_87 ) {
F_52 ( V_2 -> V_46 != V_92 &&
V_2 -> V_46 != V_93 ) ;
F_48 ( V_2 ) ;
return;
}
if ( ! V_10 -> V_18 )
goto V_62;
F_53 ( F_54 ( V_2 ) ) ;
V_10 -> V_94 = 0 ;
if ( ! V_10 -> V_17 && ! F_26 ( V_2 , V_55 ) &&
! ( ( 1 << V_2 -> V_46 ) & ( V_47 | V_48 ) ) ) {
struct V_95 * V_96 = F_55 ( V_2 ) ;
if ( V_2 -> V_97 == V_98 ) {
F_56 (KERN_DEBUG pr_fmt(L_1),
&inet->inet_daddr,
ntohs(inet->inet_dport), inet->inet_num,
tp->snd_una, tp->snd_nxt) ;
}
#if F_57 ( V_99 )
else if ( V_2 -> V_97 == V_100 ) {
F_56 (KERN_DEBUG pr_fmt(L_2),
&sk->sk_v6_daddr,
ntohs(inet->inet_dport), inet->inet_num,
tp->snd_una, tp->snd_nxt) ;
}
#endif
if ( V_13 - V_10 -> V_101 > V_15 ) {
F_1 ( V_2 ) ;
goto V_62;
}
F_58 ( V_2 , 0 ) ;
F_59 ( V_2 , F_20 ( V_2 ) ) ;
F_60 ( V_2 ) ;
goto V_102;
}
if ( F_23 ( V_2 ) )
goto V_62;
if ( V_25 -> V_42 == 0 ) {
int V_103 ;
if ( V_25 -> V_104 == V_105 ) {
if ( F_61 ( V_10 ) )
V_103 = V_106 ;
else
V_103 = V_107 ;
} else if ( V_25 -> V_104 == V_108 ) {
V_103 = V_109 ;
} else if ( ( V_25 -> V_104 == V_110 ) ||
V_10 -> V_111 ) {
if ( F_61 ( V_10 ) )
V_103 = V_112 ;
else
V_103 = V_113 ;
} else {
V_103 = V_114 ;
}
F_3 ( F_4 ( V_2 ) , V_103 ) ;
}
F_58 ( V_2 , 0 ) ;
if ( F_59 ( V_2 , F_20 ( V_2 ) ) > 0 ) {
if ( ! V_25 -> V_42 )
V_25 -> V_42 = 1 ;
F_50 ( V_2 , V_91 ,
F_13 ( V_25 -> V_56 , V_115 ) ,
V_15 ) ;
goto V_62;
}
V_25 -> V_82 ++ ;
V_25 -> V_42 ++ ;
V_102:
if ( V_2 -> V_46 == V_116 &&
( V_10 -> V_117 || V_118 ) &&
F_62 ( V_10 ) &&
V_25 -> V_42 <= V_119 ) {
V_25 -> V_82 = 0 ;
V_25 -> V_56 = F_13 ( F_63 ( V_10 ) , V_15 ) ;
} else {
V_25 -> V_56 = F_13 ( V_25 -> V_56 << 1 , V_15 ) ;
}
F_50 ( V_2 , V_91 , V_25 -> V_56 , V_15 ) ;
if ( F_16 ( V_2 , V_53 + 1 , 0 , 0 ) )
F_60 ( V_2 ) ;
V_62: ;
}
void F_64 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_17 ( V_2 ) ;
int V_120 ;
if ( V_2 -> V_46 == V_58 || ! V_25 -> V_121 )
goto V_62;
if ( F_29 ( V_25 -> V_122 , V_63 ) ) {
F_30 ( V_2 , & V_25 -> V_123 , V_25 -> V_122 ) ;
goto V_62;
}
V_120 = V_25 -> V_121 ;
switch ( V_120 ) {
case V_124 :
F_65 ( V_2 ) ;
break;
case V_125 :
F_66 ( V_2 ) ;
break;
case V_91 :
V_25 -> V_121 = 0 ;
F_51 ( V_2 ) ;
break;
case V_126 :
V_25 -> V_121 = 0 ;
F_45 ( V_2 ) ;
break;
}
V_62:
F_37 ( V_2 ) ;
}
static void F_67 ( unsigned long V_75 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
F_39 ( V_2 ) ;
if ( ! F_40 ( V_2 ) ) {
F_64 ( V_2 ) ;
} else {
if ( ! F_41 ( V_127 , & F_6 ( V_2 ) -> V_79 ) )
F_42 ( V_2 ) ;
}
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_69 ( V_2 , V_128 ,
V_40 , V_15 ) ;
}
void F_70 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
F_3 ( F_4 ( V_2 ) , V_114 ) ;
}
void F_71 ( struct V_1 * V_2 , int V_129 )
{
if ( ( 1 << V_2 -> V_46 ) & ( V_130 | V_131 ) )
return;
if ( V_129 && ! F_26 ( V_2 , V_132 ) )
F_72 ( V_2 , F_73 ( F_6 ( V_2 ) ) ) ;
else if ( ! V_129 )
F_74 ( V_2 ) ;
}
static void F_75 ( unsigned long V_75 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
struct V_24 * V_25 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_6 ( V_2 ) ;
T_1 V_133 ;
F_39 ( V_2 ) ;
if ( F_40 ( V_2 ) ) {
F_72 ( V_2 , V_134 / 20 ) ;
goto V_62;
}
if ( V_2 -> V_46 == V_135 ) {
F_68 ( V_2 ) ;
goto V_62;
}
if ( V_2 -> V_46 == V_136 && F_26 ( V_2 , V_55 ) ) {
if ( V_10 -> V_137 >= 0 ) {
const int V_138 = F_76 ( V_2 ) - V_16 ;
if ( V_138 > 0 ) {
F_77 ( V_2 , V_136 , V_138 ) ;
goto V_62;
}
}
F_8 ( V_2 , V_19 ) ;
goto V_139;
}
if ( ! F_26 ( V_2 , V_132 ) || V_2 -> V_46 == V_58 )
goto V_62;
V_133 = F_73 ( V_10 ) ;
if ( V_10 -> V_18 || F_46 ( V_2 ) )
goto V_140;
V_133 = F_78 ( V_10 ) ;
if ( V_133 >= F_73 ( V_10 ) ) {
if ( ( V_25 -> V_57 != 0 &&
V_133 >= V_25 -> V_57 &&
V_25 -> V_81 > 0 ) ||
( V_25 -> V_57 == 0 &&
V_25 -> V_81 >= F_79 ( V_10 ) ) ) {
F_8 ( V_2 , V_19 ) ;
F_1 ( V_2 ) ;
goto V_62;
}
if ( F_80 ( V_2 ) <= 0 ) {
V_25 -> V_81 ++ ;
V_133 = F_81 ( V_10 ) ;
} else {
V_133 = V_115 ;
}
} else {
V_133 = F_73 ( V_10 ) - V_133 ;
}
F_37 ( V_2 ) ;
V_140:
F_72 ( V_2 , V_133 ) ;
goto V_62;
V_139:
F_2 ( V_2 ) ;
V_62:
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
F_83 ( V_2 , & F_67 , & F_38 ,
& F_75 ) ;
}
