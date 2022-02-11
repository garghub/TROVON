int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 , & V_2 -> V_4 ) ;
}
struct V_1 * F_3 ( struct V_5 * V_5 )
{
struct V_6 * V_7 ;
if ( ! V_5 )
return & V_8 ;
V_7 = V_5 -> V_9 ;
#ifdef F_4
if ( F_5 ( V_7 ) )
return F_6 ( F_7 ( V_5 ) ) ;
#endif
return V_7 -> V_10 ;
}
static inline struct V_5 * F_8 ( struct V_11 * V_12 )
{
return F_9 ( V_12 , struct V_5 , V_13 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_14 ) ;
if ( F_2 ( V_15 , & V_2 -> V_4 ) )
F_12 ( V_16 , & V_2 -> V_17 . V_18 , 0 ) ;
F_13 ( & V_2 -> V_14 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
F_15 ( V_2 , V_20 ) ;
F_11 ( & V_2 -> V_14 ) ;
if ( ! F_2 ( V_15 , & V_2 -> V_4 ) ) {
if ( V_20 -> V_21 )
F_16 ( V_20 -> V_21 ) ;
goto V_22;
}
F_17 ( & V_20 -> V_23 , & V_2 -> V_24 ) ;
F_12 ( V_16 , & V_2 -> V_17 . V_18 , 0 ) ;
V_22:
F_13 ( & V_2 -> V_14 ) ;
}
static void
F_18 ( struct V_1 * V_2 , long V_25 ,
bool V_26 , enum V_27 V_28 )
{
struct V_19 * V_20 ;
V_20 = F_19 ( sizeof( * V_20 ) , V_29 ) ;
if ( ! V_20 ) {
F_20 ( V_2 ) ;
F_10 ( V_2 ) ;
return;
}
V_20 -> V_30 = V_31 ;
V_20 -> V_25 = V_25 ;
V_20 -> V_26 = V_26 ;
V_20 -> V_28 = V_28 ;
F_14 ( V_2 , V_20 ) ;
}
void F_21 ( struct V_1 * V_2 , long V_25 ,
enum V_27 V_28 )
{
F_18 ( V_2 , V_25 , true , V_28 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_10 ( V_2 ) ;
}
void F_24 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
F_25 ( & V_2 -> V_17 . V_32 ) ;
F_26 ( & V_5 -> V_13 ) ;
F_27 ( & V_2 -> V_17 . V_32 ) ;
}
static void F_28 ( struct V_5 * V_5 , struct V_33 * V_17 )
{
F_29 ( & V_17 -> V_32 ) ;
if ( ! F_30 ( & V_17 -> V_34 ) ) {
struct V_5 * V_35 ;
V_35 = F_8 ( V_17 -> V_34 . V_36 ) ;
if ( F_31 ( V_5 -> V_37 , V_35 -> V_37 ) )
V_5 -> V_37 = V_38 ;
}
F_32 ( & V_5 -> V_13 , & V_17 -> V_34 ) ;
}
static void F_33 ( struct V_5 * V_5 , struct V_33 * V_17 )
{
F_29 ( & V_17 -> V_32 ) ;
F_32 ( & V_5 -> V_13 , & V_17 -> V_39 ) ;
}
static void F_34 ( struct V_5 * V_5 )
{
V_5 -> V_40 &= ~ V_41 ;
F_35 ( V_5 ) ;
F_36 () ;
F_37 ( & V_5 -> V_40 , V_42 ) ;
}
static bool F_38 ( struct V_5 * V_5 , unsigned long V_43 )
{
bool V_44 = F_39 ( V_5 -> V_37 , V_43 ) ;
#ifndef F_40
V_44 = V_44 && F_41 ( V_5 -> V_37 , V_38 ) ;
#endif
return V_44 ;
}
static int F_42 ( struct V_11 * V_45 ,
struct V_11 * V_46 ,
int V_47 ,
struct V_19 * V_20 )
{
unsigned long * V_48 = NULL ;
unsigned long V_49 ;
F_43 ( V_50 ) ;
struct V_11 * V_51 , * V_52 ;
struct V_6 * V_7 = NULL ;
struct V_5 * V_5 ;
int V_53 = 0 ;
int V_54 = 0 ;
if ( ( V_47 & V_55 ) == 0 )
V_48 = V_20 -> V_48 ;
else if ( ! V_20 -> V_56 ) {
V_49 = V_38 - ( V_57 * V_58 ) ;
V_48 = & V_49 ;
}
while ( ! F_30 ( V_45 ) ) {
V_5 = F_8 ( V_45 -> V_59 ) ;
if ( V_48 &&
F_38 ( V_5 , * V_48 ) )
break;
F_32 ( & V_5 -> V_13 , & V_50 ) ;
V_54 ++ ;
if ( V_47 & V_55 )
F_44 ( V_60 , & V_5 -> V_40 ) ;
if ( F_5 ( V_5 -> V_9 ) )
continue;
if ( V_7 && V_7 != V_5 -> V_9 )
V_53 = 1 ;
V_7 = V_5 -> V_9 ;
}
if ( ! V_53 ) {
F_45 ( & V_50 , V_46 ) ;
goto V_61;
}
while ( ! F_30 ( & V_50 ) ) {
V_7 = F_8 ( V_50 . V_59 ) -> V_9 ;
F_46 (pos, node, &tmp) {
V_5 = F_8 ( V_51 ) ;
if ( V_5 -> V_9 == V_7 )
F_32 ( & V_5 -> V_13 , V_46 ) ;
}
}
V_61:
return V_54 ;
}
static void F_47 ( struct V_33 * V_17 , struct V_19 * V_20 )
{
int V_54 ;
F_29 ( & V_17 -> V_32 ) ;
F_48 ( & V_17 -> V_39 , & V_17 -> V_62 ) ;
V_54 = F_42 ( & V_17 -> V_34 , & V_17 -> V_62 , 0 , V_20 ) ;
V_54 += F_42 ( & V_17 -> V_63 , & V_17 -> V_62 ,
V_55 , V_20 ) ;
F_49 ( V_17 , V_20 , V_54 ) ;
}
static int F_50 ( struct V_5 * V_5 , struct V_64 * V_65 )
{
int V_44 ;
if ( V_5 -> V_9 -> V_66 -> F_50 && ! F_51 ( V_5 ) ) {
F_52 ( V_5 , V_65 ) ;
V_44 = V_5 -> V_9 -> V_66 -> F_50 ( V_5 , V_65 ) ;
F_53 ( V_5 , V_65 ) ;
return V_44 ;
}
return 0 ;
}
static void F_54 ( struct V_5 * V_5 )
__releases( V_5 -> V_67 )
__acquires( V_5 -> V_67 )
{
F_55 ( V_68 , & V_5 -> V_40 , V_42 ) ;
T_1 * V_69 ;
V_69 = F_56 ( & V_5 -> V_40 , V_42 ) ;
while ( V_5 -> V_40 & V_41 ) {
F_27 ( & V_5 -> V_67 ) ;
F_57 ( V_69 , & V_68 , V_70 ,
V_71 ) ;
F_25 ( & V_5 -> V_67 ) ;
}
}
void F_58 ( struct V_5 * V_5 )
{
F_25 ( & V_5 -> V_67 ) ;
F_54 ( V_5 ) ;
F_27 ( & V_5 -> V_67 ) ;
}
static void F_59 ( struct V_5 * V_5 )
__releases( V_5 -> V_67 )
{
F_60 ( V_72 ) ;
T_1 * V_69 = F_56 ( & V_5 -> V_40 , V_42 ) ;
int V_73 ;
F_61 ( V_69 , & V_72 , V_71 ) ;
V_73 = V_5 -> V_40 & V_41 ;
F_27 ( & V_5 -> V_67 ) ;
if ( V_73 )
F_62 () ;
F_63 ( V_69 , & V_72 ) ;
}
static void F_64 ( struct V_5 * V_5 , struct V_33 * V_17 ,
struct V_64 * V_65 )
{
if ( V_5 -> V_40 & V_74 )
return;
if ( ( V_5 -> V_40 & V_75 ) &&
( V_65 -> V_30 == V_76 || V_65 -> V_77 ) )
V_5 -> V_37 = V_38 ;
if ( V_65 -> V_78 ) {
F_28 ( V_5 , V_17 ) ;
return;
}
if ( F_65 ( V_5 -> V_79 , V_80 ) ) {
if ( V_65 -> V_81 <= 0 ) {
F_33 ( V_5 , V_17 ) ;
} else {
F_28 ( V_5 , V_17 ) ;
}
} else if ( V_5 -> V_40 & V_75 ) {
F_28 ( V_5 , V_17 ) ;
} else if ( V_5 -> V_40 & V_82 ) {
V_5 -> V_37 = V_38 ;
F_32 ( & V_5 -> V_13 , & V_17 -> V_63 ) ;
} else {
F_26 ( & V_5 -> V_13 ) ;
}
}
static int
F_66 ( struct V_5 * V_5 , struct V_64 * V_65 )
{
struct V_83 * V_84 = V_5 -> V_79 ;
long V_81 = V_65 -> V_81 ;
unsigned V_85 ;
int V_44 ;
F_67 ( ! ( V_5 -> V_40 & V_41 ) ) ;
F_68 ( V_5 , V_65 , V_81 ) ;
V_44 = F_69 ( V_84 , V_65 ) ;
if ( V_65 -> V_30 == V_76 && ! V_65 -> V_56 ) {
int V_86 = F_70 ( V_84 ) ;
if ( V_44 == 0 )
V_44 = V_86 ;
}
F_25 ( & V_5 -> V_67 ) ;
V_85 = V_5 -> V_40 & V_75 ;
if ( V_5 -> V_40 & V_82 ) {
if ( ( V_85 & ( V_87 | V_88 ) ) ||
F_71 ( V_5 -> V_40 & V_89 ) ||
F_71 ( F_39 ( V_38 ,
( V_5 -> V_90 +
V_57 * V_58 ) ) ) ) {
V_85 |= V_82 | V_89 ;
F_72 ( V_5 ) ;
}
} else
V_5 -> V_40 &= ~ V_89 ;
V_5 -> V_40 &= ~ V_85 ;
F_36 () ;
if ( F_65 ( V_84 , V_80 ) )
V_5 -> V_40 |= V_91 ;
F_27 ( & V_5 -> V_67 ) ;
if ( V_85 & V_82 )
F_73 ( V_5 ) ;
if ( V_85 & ~ V_91 ) {
int V_86 = F_50 ( V_5 , V_65 ) ;
if ( V_44 == 0 )
V_44 = V_86 ;
}
F_74 ( V_5 , V_65 , V_81 ) ;
return V_44 ;
}
static int
F_75 ( struct V_5 * V_5 , struct V_33 * V_17 ,
struct V_64 * V_65 )
{
int V_44 = 0 ;
F_25 ( & V_5 -> V_67 ) ;
if ( ! F_76 ( & V_5 -> V_92 ) )
F_67 ( ! ( V_5 -> V_40 & ( V_93 | V_74 ) ) ) ;
else
F_67 ( V_5 -> V_40 & V_93 ) ;
if ( V_5 -> V_40 & V_41 ) {
if ( V_65 -> V_30 != V_76 )
goto V_61;
F_54 ( V_5 ) ;
}
F_67 ( V_5 -> V_40 & V_41 ) ;
if ( ! ( V_5 -> V_40 & V_94 ) &&
( V_65 -> V_30 != V_76 ||
! F_65 ( V_5 -> V_79 , V_95 ) ) )
goto V_61;
V_5 -> V_40 |= V_41 ;
F_27 ( & V_5 -> V_67 ) ;
V_44 = F_66 ( V_5 , V_65 ) ;
F_25 ( & V_17 -> V_32 ) ;
F_25 ( & V_5 -> V_67 ) ;
if ( ! ( V_5 -> V_40 & V_94 ) )
F_26 ( & V_5 -> V_13 ) ;
F_27 ( & V_17 -> V_32 ) ;
F_34 ( V_5 ) ;
V_61:
F_27 ( & V_5 -> V_67 ) ;
return V_44 ;
}
static long F_77 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
long V_96 ;
if ( V_20 -> V_30 == V_76 || V_20 -> V_77 )
V_96 = V_97 ;
else {
V_96 = F_78 ( V_2 -> V_98 / 2 ,
V_99 / V_100 ) ;
V_96 = F_78 ( V_96 , V_20 -> V_25 ) ;
V_96 = F_79 ( V_96 + V_101 ,
V_101 ) ;
}
return V_96 ;
}
static long F_80 ( struct V_6 * V_7 ,
struct V_33 * V_17 ,
struct V_19 * V_20 )
{
struct V_64 V_65 = {
. V_30 = V_20 -> V_30 ,
. V_77 = V_20 -> V_77 ,
. V_102 = V_20 -> V_102 ,
. V_103 = V_20 -> V_103 ,
. V_56 = V_20 -> V_56 ,
. V_26 = V_20 -> V_26 ,
. V_104 = 0 ,
. V_105 = V_106 ,
} ;
unsigned long V_107 = V_38 ;
long V_108 ;
long V_109 = 0 ;
while ( ! F_30 ( & V_17 -> V_62 ) ) {
struct V_5 * V_5 = F_8 ( V_17 -> V_62 . V_59 ) ;
if ( V_5 -> V_9 != V_7 ) {
if ( V_20 -> V_7 ) {
F_28 ( V_5 , V_17 ) ;
continue;
}
break;
}
F_25 ( & V_5 -> V_67 ) ;
if ( V_5 -> V_40 & ( V_110 | V_74 | V_93 ) ) {
F_27 ( & V_5 -> V_67 ) ;
F_28 ( V_5 , V_17 ) ;
continue;
}
if ( ( V_5 -> V_40 & V_41 ) && V_65 . V_30 != V_76 ) {
F_27 ( & V_5 -> V_67 ) ;
F_33 ( V_5 , V_17 ) ;
F_81 ( V_5 ) ;
continue;
}
F_27 ( & V_17 -> V_32 ) ;
if ( V_5 -> V_40 & V_41 ) {
F_59 ( V_5 ) ;
F_25 ( & V_17 -> V_32 ) ;
continue;
}
V_5 -> V_40 |= V_41 ;
F_27 ( & V_5 -> V_67 ) ;
V_108 = F_77 ( V_17 -> V_2 , V_20 ) ;
V_65 . V_81 = V_108 ;
V_65 . V_78 = 0 ;
F_66 ( V_5 , & V_65 ) ;
V_20 -> V_25 -= V_108 - V_65 . V_81 ;
V_109 += V_108 - V_65 . V_81 ;
F_25 ( & V_17 -> V_32 ) ;
F_25 ( & V_5 -> V_67 ) ;
if ( ! ( V_5 -> V_40 & V_94 ) )
V_109 ++ ;
F_64 ( V_5 , V_17 , & V_65 ) ;
F_34 ( V_5 ) ;
F_27 ( & V_5 -> V_67 ) ;
F_82 ( & V_17 -> V_32 ) ;
if ( V_109 ) {
if ( F_83 ( V_107 + V_58 / 10UL ) )
break;
if ( V_20 -> V_25 <= 0 )
break;
}
}
return V_109 ;
}
static long F_84 ( struct V_33 * V_17 ,
struct V_19 * V_20 )
{
unsigned long V_107 = V_38 ;
long V_109 = 0 ;
while ( ! F_30 ( & V_17 -> V_62 ) ) {
struct V_5 * V_5 = F_8 ( V_17 -> V_62 . V_59 ) ;
struct V_6 * V_7 = V_5 -> V_9 ;
if ( ! F_85 ( V_7 ) ) {
F_28 ( V_5 , V_17 ) ;
continue;
}
V_109 += F_80 ( V_7 , V_17 , V_20 ) ;
F_86 ( & V_7 -> V_111 ) ;
if ( V_109 ) {
if ( F_83 ( V_107 + V_58 / 10UL ) )
break;
if ( V_20 -> V_25 <= 0 )
break;
}
}
return V_109 ;
}
static long F_87 ( struct V_33 * V_17 , long V_25 ,
enum V_27 V_28 )
{
struct V_19 V_20 = {
. V_25 = V_25 ,
. V_30 = V_31 ,
. V_26 = 1 ,
. V_28 = V_28 ,
} ;
F_25 ( & V_17 -> V_32 ) ;
if ( F_30 ( & V_17 -> V_62 ) )
F_47 ( V_17 , & V_20 ) ;
F_84 ( V_17 , & V_20 ) ;
F_27 ( & V_17 -> V_32 ) ;
return V_25 - V_20 . V_25 ;
}
static bool F_88 ( struct V_1 * V_2 )
{
unsigned long V_112 , V_113 ;
F_89 ( & V_112 , & V_113 ) ;
if ( F_90 ( V_114 ) +
F_90 ( V_115 ) > V_112 )
return true ;
if ( F_91 ( V_2 , V_116 ) >
F_92 ( V_2 , V_112 ) )
return true ;
return false ;
}
static void F_93 ( struct V_33 * V_17 ,
unsigned long V_107 )
{
F_94 ( V_17 -> V_2 , 0 , 0 , 0 , 0 , 0 , V_107 ) ;
}
static long F_95 ( struct V_33 * V_17 ,
struct V_19 * V_20 )
{
unsigned long V_117 = V_38 ;
long V_25 = V_20 -> V_25 ;
unsigned long V_118 ;
struct V_5 * V_5 ;
long V_119 ;
V_118 = V_38 ;
V_20 -> V_48 = & V_118 ;
F_25 ( & V_17 -> V_32 ) ;
for (; ; ) {
if ( V_20 -> V_25 <= 0 )
break;
if ( ( V_20 -> V_103 || V_20 -> V_102 ) &&
! F_30 ( & V_17 -> V_2 -> V_24 ) )
break;
if ( V_20 -> V_103 && ! F_88 ( V_17 -> V_2 ) )
break;
if ( V_20 -> V_102 ) {
V_118 = V_38 -
F_96 ( V_120 * 10 ) ;
} else if ( V_20 -> V_103 )
V_118 = V_38 ;
F_97 ( V_17 -> V_2 , V_20 ) ;
if ( F_30 ( & V_17 -> V_62 ) )
F_47 ( V_17 , V_20 ) ;
if ( V_20 -> V_7 )
V_119 = F_80 ( V_20 -> V_7 , V_17 , V_20 ) ;
else
V_119 = F_84 ( V_17 , V_20 ) ;
F_98 ( V_17 -> V_2 , V_20 ) ;
F_93 ( V_17 , V_117 ) ;
if ( V_119 )
continue;
if ( F_30 ( & V_17 -> V_39 ) )
break;
if ( ! F_30 ( & V_17 -> V_39 ) ) {
F_99 ( V_17 -> V_2 , V_20 ) ;
V_5 = F_8 ( V_17 -> V_39 . V_59 ) ;
F_25 ( & V_5 -> V_67 ) ;
F_27 ( & V_17 -> V_32 ) ;
F_59 ( V_5 ) ;
F_25 ( & V_17 -> V_32 ) ;
}
}
F_27 ( & V_17 -> V_32 ) ;
return V_25 - V_20 -> V_25 ;
}
static struct V_19 *
F_100 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = NULL ;
F_11 ( & V_2 -> V_14 ) ;
if ( ! F_30 ( & V_2 -> V_24 ) ) {
V_20 = F_9 ( V_2 -> V_24 . V_36 ,
struct V_19 , V_23 ) ;
F_26 ( & V_20 -> V_23 ) ;
}
F_13 ( & V_2 -> V_14 ) ;
return V_20 ;
}
static unsigned long F_101 ( void )
{
return F_90 ( V_114 ) +
F_90 ( V_115 ) +
F_102 () ;
}
static long F_103 ( struct V_33 * V_17 )
{
if ( F_88 ( V_17 -> V_2 ) ) {
struct V_19 V_20 = {
. V_25 = V_97 ,
. V_30 = V_31 ,
. V_103 = 1 ,
. V_26 = 1 ,
. V_28 = V_121 ,
} ;
return F_95 ( V_17 , & V_20 ) ;
}
return 0 ;
}
static long F_104 ( struct V_33 * V_17 )
{
unsigned long V_122 ;
long V_25 ;
if ( ! V_123 )
return 0 ;
V_122 = V_17 -> V_124 +
F_96 ( V_123 * 10 ) ;
if ( F_31 ( V_38 , V_122 ) )
return 0 ;
V_17 -> V_124 = V_38 ;
V_25 = F_101 () ;
if ( V_25 ) {
struct V_19 V_20 = {
. V_25 = V_25 ,
. V_30 = V_31 ,
. V_102 = 1 ,
. V_26 = 1 ,
. V_28 = V_125 ,
} ;
return F_95 ( V_17 , & V_20 ) ;
}
return 0 ;
}
static long F_105 ( struct V_33 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_19 * V_20 ;
long V_109 = 0 ;
F_44 ( V_3 , & V_17 -> V_2 -> V_4 ) ;
while ( ( V_20 = F_100 ( V_2 ) ) != NULL ) {
F_106 ( V_2 , V_20 ) ;
V_109 += F_95 ( V_17 , V_20 ) ;
if ( V_20 -> V_21 )
F_16 ( V_20 -> V_21 ) ;
else
F_107 ( V_20 ) ;
}
V_109 += F_104 ( V_17 ) ;
V_109 += F_103 ( V_17 ) ;
F_108 ( V_3 , & V_17 -> V_2 -> V_4 ) ;
return V_109 ;
}
void F_109 ( struct V_126 * V_20 )
{
struct V_33 * V_17 = F_110 ( F_111 ( V_20 ) ,
struct V_33 , V_18 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
long V_127 ;
F_112 ( L_1 , F_113 ( V_2 -> V_128 ) ) ;
V_129 -> V_47 |= V_130 ;
if ( F_114 ( ! F_115 () ||
! F_2 ( V_15 , & V_2 -> V_4 ) ) ) {
do {
V_127 = F_105 ( V_17 ) ;
F_116 ( V_127 ) ;
} while ( ! F_30 ( & V_2 -> V_24 ) );
} else {
V_127 = F_87 ( & V_2 -> V_17 , 1024 ,
V_131 ) ;
F_116 ( V_127 ) ;
}
if ( ! F_30 ( & V_2 -> V_24 ) )
F_12 ( V_16 , & V_17 -> V_18 , 0 ) ;
else if ( F_117 ( V_17 ) && V_123 )
F_118 ( V_2 ) ;
V_129 -> V_47 &= ~ V_130 ;
}
void F_119 ( long V_25 , enum V_27 V_28 )
{
struct V_1 * V_2 ;
if ( ! V_25 )
V_25 = F_101 () ;
F_120 () ;
F_121 (bdi, &bdi_list, bdi_list) {
if ( ! F_122 ( V_2 ) )
continue;
F_18 ( V_2 , V_25 , false , V_28 ) ;
}
F_123 () ;
}
static void F_124 ( struct V_126 * V_132 )
{
struct V_1 * V_2 ;
F_120 () ;
F_121 (bdi, &bdi_list, bdi_list) {
if ( F_30 ( & V_2 -> V_17 . V_63 ) )
continue;
F_10 ( V_2 ) ;
}
F_123 () ;
F_125 ( & V_133 , V_57 * V_58 ) ;
}
static int T_2 F_126 ( void )
{
F_125 ( & V_133 , V_57 * V_58 ) ;
return 0 ;
}
int F_127 ( struct V_134 * V_135 , int V_136 ,
void T_3 * V_137 , T_4 * V_138 , T_5 * V_139 )
{
int V_44 ;
V_44 = F_128 ( V_135 , V_136 , V_137 , V_138 , V_139 ) ;
if ( V_44 == 0 && V_136 )
F_12 ( V_140 , & V_133 , 0 ) ;
return V_44 ;
}
static T_6 void F_129 ( struct V_5 * V_5 )
{
if ( V_5 -> V_141 || strcmp ( V_5 -> V_9 -> V_142 , L_2 ) ) {
struct V_143 * V_143 ;
const char * V_144 = L_3 ;
V_143 = F_130 ( V_5 ) ;
if ( V_143 ) {
F_25 ( & V_143 -> V_145 ) ;
V_144 = ( const char * ) V_143 -> V_146 . V_144 ;
}
F_131 ( V_147
L_4 ,
V_129 -> V_148 , F_132 ( V_129 ) , V_5 -> V_141 ,
V_144 , V_5 -> V_9 -> V_142 ) ;
if ( V_143 ) {
F_27 ( & V_143 -> V_145 ) ;
F_133 ( V_143 ) ;
}
}
}
void F_134 ( struct V_5 * V_5 , int V_47 )
{
struct V_6 * V_7 = V_5 -> V_9 ;
struct V_1 * V_2 = NULL ;
int V_149 ;
F_135 ( V_5 , V_47 ) ;
if ( V_47 & ( V_87 | V_88 | V_82 ) ) {
F_136 ( V_5 , V_47 ) ;
if ( V_7 -> V_66 -> V_150 )
V_7 -> V_66 -> V_150 ( V_5 , V_47 ) ;
F_137 ( V_5 , V_47 ) ;
}
if ( V_47 & V_151 )
V_47 &= ~ V_82 ;
V_149 = V_47 & V_82 ;
F_36 () ;
if ( ( ( V_5 -> V_40 & V_47 ) == V_47 ) ||
( V_149 && ( V_5 -> V_40 & V_151 ) ) )
return;
if ( F_71 ( V_152 ) )
F_129 ( V_5 ) ;
F_25 ( & V_5 -> V_67 ) ;
if ( V_149 && ( V_5 -> V_40 & V_151 ) )
goto V_153;
if ( ( V_5 -> V_40 & V_47 ) != V_47 ) {
const int V_154 = V_5 -> V_40 & V_75 ;
if ( V_47 & V_151 )
V_5 -> V_40 &= ~ V_82 ;
V_5 -> V_40 |= V_47 ;
if ( V_5 -> V_40 & V_41 )
goto V_153;
if ( ! F_138 ( V_5 -> V_155 ) ) {
if ( F_139 ( V_5 ) )
goto V_153;
}
if ( V_5 -> V_40 & V_74 )
goto V_153;
if ( ! V_154 ) {
bool V_156 = false ;
V_2 = F_3 ( V_5 ) ;
F_27 ( & V_5 -> V_67 ) ;
F_25 ( & V_2 -> V_17 . V_32 ) ;
if ( F_140 ( V_2 ) ) {
F_141 ( ! F_2 ( V_15 , & V_2 -> V_4 ) ,
L_5 , V_2 -> V_144 ) ;
if ( ! F_117 ( & V_2 -> V_17 ) )
V_156 = true ;
}
V_5 -> V_37 = V_38 ;
if ( V_149 )
V_5 -> V_90 = V_38 ;
if ( V_5 -> V_40 & ( V_151 | V_91 ) )
F_32 ( & V_5 -> V_13 , & V_2 -> V_17 . V_34 ) ;
else
F_32 ( & V_5 -> V_13 ,
& V_2 -> V_17 . V_63 ) ;
F_27 ( & V_2 -> V_17 . V_32 ) ;
F_142 ( V_5 ) ;
if ( V_156 )
F_118 ( V_2 ) ;
return;
}
}
V_153:
F_27 ( & V_5 -> V_67 ) ;
}
static void F_143 ( struct V_6 * V_7 )
{
struct V_5 * V_5 , * V_157 = NULL ;
F_67 ( ! F_144 ( & V_7 -> V_111 ) ) ;
F_25 ( & V_158 ) ;
F_145 (inode, &sb->s_inodes, i_sb_list) {
struct V_83 * V_84 = V_5 -> V_79 ;
F_25 ( & V_5 -> V_67 ) ;
if ( ( V_5 -> V_40 & ( V_74 | V_93 | V_110 ) ) ||
( V_84 -> V_159 == 0 ) ) {
F_27 ( & V_5 -> V_67 ) ;
continue;
}
F_146 ( V_5 ) ;
F_27 ( & V_5 -> V_67 ) ;
F_27 ( & V_158 ) ;
F_147 ( V_157 ) ;
V_157 = V_5 ;
F_70 ( V_84 ) ;
F_148 () ;
F_25 ( & V_158 ) ;
}
F_27 ( & V_158 ) ;
F_147 ( V_157 ) ;
}
void F_149 ( struct V_6 * V_7 ,
unsigned long V_160 ,
enum V_27 V_28 )
{
F_150 ( V_21 ) ;
struct V_19 V_20 = {
. V_7 = V_7 ,
. V_30 = V_31 ,
. V_77 = 1 ,
. V_21 = & V_21 ,
. V_25 = V_160 ,
. V_28 = V_28 ,
} ;
if ( V_7 -> V_10 == & V_8 )
return;
F_67 ( ! F_144 ( & V_7 -> V_111 ) ) ;
F_14 ( V_7 -> V_10 , & V_20 ) ;
F_151 ( & V_21 ) ;
}
void F_152 ( struct V_6 * V_7 , enum V_27 V_28 )
{
return F_149 ( V_7 , F_101 () , V_28 ) ;
}
int F_153 ( struct V_6 * V_7 ,
unsigned long V_160 ,
enum V_27 V_28 )
{
if ( F_1 ( V_7 -> V_10 ) )
return 1 ;
if ( ! F_154 ( & V_7 -> V_111 ) )
return 0 ;
F_149 ( V_7 , V_160 , V_28 ) ;
F_86 ( & V_7 -> V_111 ) ;
return 1 ;
}
int F_155 ( struct V_6 * V_7 , enum V_27 V_28 )
{
return F_153 ( V_7 , F_101 () , V_28 ) ;
}
void F_156 ( struct V_6 * V_7 )
{
F_150 ( V_21 ) ;
struct V_19 V_20 = {
. V_7 = V_7 ,
. V_30 = V_76 ,
. V_25 = V_97 ,
. V_26 = 0 ,
. V_21 = & V_21 ,
. V_28 = V_161 ,
. V_56 = 1 ,
} ;
if ( V_7 -> V_10 == & V_8 )
return;
F_67 ( ! F_144 ( & V_7 -> V_111 ) ) ;
F_14 ( V_7 -> V_10 , & V_20 ) ;
F_151 ( & V_21 ) ;
F_143 ( V_7 ) ;
}
int F_157 ( struct V_5 * V_5 , int V_162 )
{
struct V_33 * V_17 = & F_3 ( V_5 ) -> V_17 ;
struct V_64 V_65 = {
. V_81 = V_97 ,
. V_30 = V_162 ? V_76 : V_31 ,
. V_104 = 0 ,
. V_105 = V_106 ,
} ;
if ( ! F_158 ( V_5 -> V_79 ) )
V_65 . V_81 = 0 ;
F_159 () ;
return F_75 ( V_5 , V_17 , & V_65 ) ;
}
int F_160 ( struct V_5 * V_5 , struct V_64 * V_65 )
{
return F_75 ( V_5 , & F_3 ( V_5 ) -> V_17 , V_65 ) ;
}
int F_161 ( struct V_5 * V_5 , int V_72 )
{
struct V_64 V_65 = {
. V_30 = V_72 ? V_76 : V_31 ,
. V_81 = 0 ,
} ;
return F_160 ( V_5 , & V_65 ) ;
}
