int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 , & V_2 -> V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_4 ( V_7 ) )
return V_5 -> V_9 -> V_1 ;
return V_7 -> V_10 ;
}
static inline struct V_5 * F_5 ( struct V_11 * V_12 )
{
return F_6 ( V_12 , struct V_5 , V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
F_8 ( V_2 , V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
F_10 ( & V_15 -> V_17 , & V_2 -> V_18 ) ;
F_11 ( & V_2 -> V_16 ) ;
F_12 ( V_19 , & V_2 -> V_20 . V_21 , 0 ) ;
}
static void
F_13 ( struct V_1 * V_2 , long V_22 ,
bool V_23 , enum V_24 V_25 )
{
struct V_14 * V_15 ;
V_15 = F_14 ( sizeof( * V_15 ) , V_26 ) ;
if ( ! V_15 ) {
F_15 ( V_2 ) ;
F_12 ( V_19 , & V_2 -> V_20 . V_21 , 0 ) ;
return;
}
V_15 -> V_27 = V_28 ;
V_15 -> V_22 = V_22 ;
V_15 -> V_23 = V_23 ;
V_15 -> V_25 = V_25 ;
F_7 ( V_2 , V_15 ) ;
}
void F_16 ( struct V_1 * V_2 , long V_22 ,
enum V_24 V_25 )
{
F_13 ( V_2 , V_22 , true , V_25 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
F_12 ( V_19 , & V_2 -> V_20 . V_21 , 0 ) ;
}
void F_19 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
F_20 ( & V_2 -> V_20 . V_29 ) ;
F_21 ( & V_5 -> V_13 ) ;
F_22 ( & V_2 -> V_20 . V_29 ) ;
}
static void F_23 ( struct V_5 * V_5 , struct V_30 * V_20 )
{
F_24 ( & V_20 -> V_29 ) ;
if ( ! F_25 ( & V_20 -> V_31 ) ) {
struct V_5 * V_32 ;
V_32 = F_5 ( V_20 -> V_31 . V_33 ) ;
if ( F_26 ( V_5 -> V_34 , V_32 -> V_34 ) )
V_5 -> V_34 = V_35 ;
}
F_27 ( & V_5 -> V_13 , & V_20 -> V_31 ) ;
}
static void F_28 ( struct V_5 * V_5 , struct V_30 * V_20 )
{
F_24 ( & V_20 -> V_29 ) ;
F_27 ( & V_5 -> V_13 , & V_20 -> V_36 ) ;
}
static void F_29 ( struct V_5 * V_5 )
{
V_5 -> V_37 &= ~ V_38 ;
F_30 ( V_5 ) ;
F_31 () ;
F_32 ( & V_5 -> V_37 , V_39 ) ;
}
static bool F_33 ( struct V_5 * V_5 , unsigned long V_40 )
{
bool V_41 = F_34 ( V_5 -> V_34 , V_40 ) ;
#ifndef F_35
V_41 = V_41 && F_36 ( V_5 -> V_34 , V_35 ) ;
#endif
return V_41 ;
}
static int F_37 ( struct V_11 * V_42 ,
struct V_11 * V_43 ,
struct V_14 * V_15 )
{
F_38 ( V_44 ) ;
struct V_11 * V_45 , * V_46 ;
struct V_6 * V_7 = NULL ;
struct V_5 * V_5 ;
int V_47 = 0 ;
int V_48 = 0 ;
while ( ! F_25 ( V_42 ) ) {
V_5 = F_5 ( V_42 -> V_49 ) ;
if ( V_15 -> V_50 &&
F_33 ( V_5 , * V_15 -> V_50 ) )
break;
F_27 ( & V_5 -> V_13 , & V_44 ) ;
V_48 ++ ;
if ( F_4 ( V_5 -> V_8 ) )
continue;
if ( V_7 && V_7 != V_5 -> V_8 )
V_47 = 1 ;
V_7 = V_5 -> V_8 ;
}
if ( ! V_47 ) {
F_39 ( & V_44 , V_43 ) ;
goto V_51;
}
while ( ! F_25 ( & V_44 ) ) {
V_7 = F_5 ( V_44 . V_49 ) -> V_8 ;
F_40 (pos, node, &tmp) {
V_5 = F_5 ( V_45 ) ;
if ( V_5 -> V_8 == V_7 )
F_27 ( & V_5 -> V_13 , V_43 ) ;
}
}
V_51:
return V_48 ;
}
static void F_41 ( struct V_30 * V_20 , struct V_14 * V_15 )
{
int V_48 ;
F_24 ( & V_20 -> V_29 ) ;
F_42 ( & V_20 -> V_36 , & V_20 -> V_52 ) ;
V_48 = F_37 ( & V_20 -> V_31 , & V_20 -> V_52 , V_15 ) ;
F_43 ( V_20 , V_15 , V_48 ) ;
}
static int F_44 ( struct V_5 * V_5 , struct V_53 * V_54 )
{
int V_41 ;
if ( V_5 -> V_8 -> V_55 -> F_44 && ! F_45 ( V_5 ) ) {
F_46 ( V_5 , V_54 ) ;
V_41 = V_5 -> V_8 -> V_55 -> F_44 ( V_5 , V_54 ) ;
F_47 ( V_5 , V_54 ) ;
return V_41 ;
}
return 0 ;
}
static void F_48 ( struct V_5 * V_5 )
__releases( V_5 -> V_56 )
__acquires( V_5 -> V_56 )
{
F_49 ( V_57 , & V_5 -> V_37 , V_39 ) ;
T_1 * V_58 ;
V_58 = F_50 ( & V_5 -> V_37 , V_39 ) ;
while ( V_5 -> V_37 & V_38 ) {
F_22 ( & V_5 -> V_56 ) ;
F_51 ( V_58 , & V_57 , V_59 , V_60 ) ;
F_20 ( & V_5 -> V_56 ) ;
}
}
void F_52 ( struct V_5 * V_5 )
{
F_20 ( & V_5 -> V_56 ) ;
F_48 ( V_5 ) ;
F_22 ( & V_5 -> V_56 ) ;
}
static void F_53 ( struct V_5 * V_5 )
__releases( V_5 -> V_56 )
{
F_54 ( V_61 ) ;
T_1 * V_58 = F_50 ( & V_5 -> V_37 , V_39 ) ;
int V_62 ;
F_55 ( V_58 , & V_61 , V_60 ) ;
V_62 = V_5 -> V_37 & V_38 ;
F_22 ( & V_5 -> V_56 ) ;
if ( V_62 )
F_56 () ;
F_57 ( V_58 , & V_61 ) ;
}
static void F_58 ( struct V_5 * V_5 , struct V_30 * V_20 ,
struct V_53 * V_54 )
{
if ( V_5 -> V_37 & V_63 )
return;
if ( ( V_5 -> V_37 & V_64 ) &&
( V_54 -> V_27 == V_65 || V_54 -> V_66 ) )
V_5 -> V_34 = V_35 ;
if ( V_54 -> V_67 ) {
F_23 ( V_5 , V_20 ) ;
return;
}
if ( F_59 ( V_5 -> V_9 , V_68 ) ) {
if ( V_54 -> V_69 <= 0 ) {
F_28 ( V_5 , V_20 ) ;
} else {
F_23 ( V_5 , V_20 ) ;
}
} else if ( V_5 -> V_37 & V_64 ) {
F_23 ( V_5 , V_20 ) ;
} else {
F_21 ( & V_5 -> V_13 ) ;
}
}
static int
F_60 ( struct V_5 * V_5 , struct V_53 * V_54 )
{
struct V_70 * V_71 = V_5 -> V_9 ;
long V_69 = V_54 -> V_69 ;
unsigned V_72 ;
int V_41 ;
F_61 ( ! ( V_5 -> V_37 & V_38 ) ) ;
F_62 ( V_5 , V_54 , V_69 ) ;
V_41 = F_63 ( V_71 , V_54 ) ;
if ( V_54 -> V_27 == V_65 && ! V_54 -> V_73 ) {
int V_74 = F_64 ( V_71 ) ;
if ( V_41 == 0 )
V_41 = V_74 ;
}
F_20 ( & V_5 -> V_56 ) ;
if ( ! F_59 ( V_71 , V_68 ) )
V_5 -> V_37 &= ~ V_75 ;
V_72 = V_5 -> V_37 & V_64 ;
V_5 -> V_37 &= ~ ( V_76 | V_77 ) ;
F_22 ( & V_5 -> V_56 ) ;
if ( V_72 & ( V_76 | V_77 ) ) {
int V_74 = F_44 ( V_5 , V_54 ) ;
if ( V_41 == 0 )
V_41 = V_74 ;
}
F_65 ( V_5 , V_54 , V_69 ) ;
return V_41 ;
}
static int
F_66 ( struct V_5 * V_5 , struct V_30 * V_20 ,
struct V_53 * V_54 )
{
int V_41 = 0 ;
F_20 ( & V_5 -> V_56 ) ;
if ( ! F_67 ( & V_5 -> V_78 ) )
F_61 ( ! ( V_5 -> V_37 & ( V_79 | V_63 ) ) ) ;
else
F_61 ( V_5 -> V_37 & V_79 ) ;
if ( V_5 -> V_37 & V_38 ) {
if ( V_54 -> V_27 != V_65 )
goto V_51;
F_48 ( V_5 ) ;
}
F_61 ( V_5 -> V_37 & V_38 ) ;
if ( ! ( V_5 -> V_37 & V_64 ) &&
( V_54 -> V_27 != V_65 ||
! F_59 ( V_5 -> V_9 , V_80 ) ) )
goto V_51;
V_5 -> V_37 |= V_38 ;
F_22 ( & V_5 -> V_56 ) ;
V_41 = F_60 ( V_5 , V_54 ) ;
F_20 ( & V_20 -> V_29 ) ;
F_20 ( & V_5 -> V_56 ) ;
if ( ! ( V_5 -> V_37 & V_64 ) )
F_21 ( & V_5 -> V_13 ) ;
F_22 ( & V_20 -> V_29 ) ;
F_29 ( V_5 ) ;
V_51:
F_22 ( & V_5 -> V_56 ) ;
return V_41 ;
}
static long F_68 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
long V_81 ;
if ( V_15 -> V_27 == V_65 || V_15 -> V_66 )
V_81 = V_82 ;
else {
V_81 = F_69 ( V_2 -> V_83 / 2 ,
V_84 / V_85 ) ;
V_81 = F_69 ( V_81 , V_15 -> V_22 ) ;
V_81 = F_70 ( V_81 + V_86 ,
V_86 ) ;
}
return V_81 ;
}
static long F_71 ( struct V_6 * V_7 ,
struct V_30 * V_20 ,
struct V_14 * V_15 )
{
struct V_53 V_54 = {
. V_27 = V_15 -> V_27 ,
. V_66 = V_15 -> V_66 ,
. V_87 = V_15 -> V_87 ,
. V_88 = V_15 -> V_88 ,
. V_73 = V_15 -> V_73 ,
. V_23 = V_15 -> V_23 ,
. V_89 = 0 ,
. V_90 = V_91 ,
} ;
unsigned long V_92 = V_35 ;
long V_93 ;
long V_94 = 0 ;
while ( ! F_25 ( & V_20 -> V_52 ) ) {
struct V_5 * V_5 = F_5 ( V_20 -> V_52 . V_49 ) ;
if ( V_5 -> V_8 != V_7 ) {
if ( V_15 -> V_7 ) {
F_23 ( V_5 , V_20 ) ;
continue;
}
break;
}
F_20 ( & V_5 -> V_56 ) ;
if ( V_5 -> V_37 & ( V_95 | V_63 | V_79 ) ) {
F_22 ( & V_5 -> V_56 ) ;
F_23 ( V_5 , V_20 ) ;
continue;
}
if ( ( V_5 -> V_37 & V_38 ) && V_54 . V_27 != V_65 ) {
F_22 ( & V_5 -> V_56 ) ;
F_28 ( V_5 , V_20 ) ;
F_72 ( V_5 ) ;
continue;
}
F_22 ( & V_20 -> V_29 ) ;
if ( V_5 -> V_37 & V_38 ) {
F_53 ( V_5 ) ;
F_20 ( & V_20 -> V_29 ) ;
continue;
}
V_5 -> V_37 |= V_38 ;
F_22 ( & V_5 -> V_56 ) ;
V_93 = F_68 ( V_20 -> V_2 , V_15 ) ;
V_54 . V_69 = V_93 ;
V_54 . V_67 = 0 ;
F_60 ( V_5 , & V_54 ) ;
V_15 -> V_22 -= V_93 - V_54 . V_69 ;
V_94 += V_93 - V_54 . V_69 ;
F_20 ( & V_20 -> V_29 ) ;
F_20 ( & V_5 -> V_56 ) ;
if ( ! ( V_5 -> V_37 & V_64 ) )
V_94 ++ ;
F_58 ( V_5 , V_20 , & V_54 ) ;
F_29 ( V_5 ) ;
F_22 ( & V_5 -> V_56 ) ;
F_73 ( & V_20 -> V_29 ) ;
if ( V_94 ) {
if ( F_74 ( V_92 + V_96 / 10UL ) )
break;
if ( V_15 -> V_22 <= 0 )
break;
}
}
return V_94 ;
}
static long F_75 ( struct V_30 * V_20 ,
struct V_14 * V_15 )
{
unsigned long V_92 = V_35 ;
long V_94 = 0 ;
while ( ! F_25 ( & V_20 -> V_52 ) ) {
struct V_5 * V_5 = F_5 ( V_20 -> V_52 . V_49 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! F_76 ( V_7 ) ) {
F_23 ( V_5 , V_20 ) ;
continue;
}
V_94 += F_71 ( V_7 , V_20 , V_15 ) ;
F_77 ( V_7 ) ;
if ( V_94 ) {
if ( F_74 ( V_92 + V_96 / 10UL ) )
break;
if ( V_15 -> V_22 <= 0 )
break;
}
}
return V_94 ;
}
static long F_78 ( struct V_30 * V_20 , long V_22 ,
enum V_24 V_25 )
{
struct V_14 V_15 = {
. V_22 = V_22 ,
. V_27 = V_28 ,
. V_23 = 1 ,
. V_25 = V_25 ,
} ;
F_20 ( & V_20 -> V_29 ) ;
if ( F_25 ( & V_20 -> V_52 ) )
F_41 ( V_20 , & V_15 ) ;
F_75 ( V_20 , & V_15 ) ;
F_22 ( & V_20 -> V_29 ) ;
return V_22 - V_15 . V_22 ;
}
static bool F_79 ( struct V_1 * V_2 )
{
unsigned long V_97 , V_98 ;
F_80 ( & V_97 , & V_98 ) ;
if ( F_81 ( V_99 ) +
F_81 ( V_100 ) > V_97 )
return true ;
if ( F_82 ( V_2 , V_101 ) >
F_83 ( V_2 , V_97 ) )
return true ;
return false ;
}
static void F_84 ( struct V_30 * V_20 ,
unsigned long V_92 )
{
F_85 ( V_20 -> V_2 , 0 , 0 , 0 , 0 , 0 , V_92 ) ;
}
static long F_86 ( struct V_30 * V_20 ,
struct V_14 * V_15 )
{
unsigned long V_102 = V_35 ;
long V_22 = V_15 -> V_22 ;
unsigned long V_103 ;
struct V_5 * V_5 ;
long V_104 ;
V_103 = V_35 ;
V_15 -> V_50 = & V_103 ;
F_20 ( & V_20 -> V_29 ) ;
for (; ; ) {
if ( V_15 -> V_22 <= 0 )
break;
if ( ( V_15 -> V_88 || V_15 -> V_87 ) &&
! F_25 ( & V_20 -> V_2 -> V_18 ) )
break;
if ( V_15 -> V_88 && ! F_79 ( V_20 -> V_2 ) )
break;
if ( V_15 -> V_87 ) {
V_103 = V_35 -
F_87 ( V_105 * 10 ) ;
} else if ( V_15 -> V_88 )
V_103 = V_35 ;
F_88 ( V_20 -> V_2 , V_15 ) ;
if ( F_25 ( & V_20 -> V_52 ) )
F_41 ( V_20 , V_15 ) ;
if ( V_15 -> V_7 )
V_104 = F_71 ( V_15 -> V_7 , V_20 , V_15 ) ;
else
V_104 = F_75 ( V_20 , V_15 ) ;
F_89 ( V_20 -> V_2 , V_15 ) ;
F_84 ( V_20 , V_102 ) ;
if ( V_104 )
continue;
if ( F_25 ( & V_20 -> V_36 ) )
break;
if ( ! F_25 ( & V_20 -> V_36 ) ) {
F_90 ( V_20 -> V_2 , V_15 ) ;
V_5 = F_5 ( V_20 -> V_36 . V_49 ) ;
F_20 ( & V_5 -> V_56 ) ;
F_22 ( & V_20 -> V_29 ) ;
F_53 ( V_5 ) ;
F_20 ( & V_20 -> V_29 ) ;
}
}
F_22 ( & V_20 -> V_29 ) ;
return V_22 - V_15 -> V_22 ;
}
static struct V_14 *
F_91 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = NULL ;
F_9 ( & V_2 -> V_16 ) ;
if ( ! F_25 ( & V_2 -> V_18 ) ) {
V_15 = F_6 ( V_2 -> V_18 . V_33 ,
struct V_14 , V_17 ) ;
F_21 ( & V_15 -> V_17 ) ;
}
F_11 ( & V_2 -> V_16 ) ;
return V_15 ;
}
static unsigned long F_92 ( void )
{
return F_81 ( V_99 ) +
F_81 ( V_100 ) +
F_93 () ;
}
static long F_94 ( struct V_30 * V_20 )
{
if ( F_79 ( V_20 -> V_2 ) ) {
struct V_14 V_15 = {
. V_22 = V_82 ,
. V_27 = V_28 ,
. V_88 = 1 ,
. V_23 = 1 ,
. V_25 = V_106 ,
} ;
return F_86 ( V_20 , & V_15 ) ;
}
return 0 ;
}
static long F_95 ( struct V_30 * V_20 )
{
unsigned long V_107 ;
long V_22 ;
if ( ! V_108 )
return 0 ;
V_107 = V_20 -> V_109 +
F_87 ( V_108 * 10 ) ;
if ( F_26 ( V_35 , V_107 ) )
return 0 ;
V_20 -> V_109 = V_35 ;
V_22 = F_92 () ;
if ( V_22 ) {
struct V_14 V_15 = {
. V_22 = V_22 ,
. V_27 = V_28 ,
. V_87 = 1 ,
. V_23 = 1 ,
. V_25 = V_110 ,
} ;
return F_86 ( V_20 , & V_15 ) ;
}
return 0 ;
}
static long F_96 ( struct V_30 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_14 * V_15 ;
long V_94 = 0 ;
F_97 ( V_3 , & V_20 -> V_2 -> V_4 ) ;
while ( ( V_15 = F_91 ( V_2 ) ) != NULL ) {
F_98 ( V_2 , V_15 ) ;
V_94 += F_86 ( V_20 , V_15 ) ;
if ( V_15 -> V_111 )
F_99 ( V_15 -> V_111 ) ;
else
F_100 ( V_15 ) ;
}
V_94 += F_95 ( V_20 ) ;
V_94 += F_94 ( V_20 ) ;
F_101 ( V_3 , & V_20 -> V_2 -> V_4 ) ;
return V_94 ;
}
void F_102 ( struct V_112 * V_15 )
{
struct V_30 * V_20 = F_103 ( F_104 ( V_15 ) ,
struct V_30 , V_21 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
long V_113 ;
F_105 ( L_1 , F_106 ( V_2 -> V_114 ) ) ;
V_115 -> V_116 |= V_117 ;
if ( F_107 ( ! F_108 () ||
F_25 ( & V_2 -> V_118 ) ) ) {
do {
V_113 = F_96 ( V_20 ) ;
F_109 ( V_113 ) ;
} while ( ! F_25 ( & V_2 -> V_18 ) );
} else {
V_113 = F_78 ( & V_2 -> V_20 , 1024 ,
V_119 ) ;
F_109 ( V_113 ) ;
}
if ( ! F_25 ( & V_2 -> V_18 ) ||
( F_110 ( V_20 ) && V_108 ) )
F_111 ( V_19 , & V_20 -> V_21 ,
F_87 ( V_108 * 10 ) ) ;
V_115 -> V_116 &= ~ V_117 ;
}
void F_112 ( long V_22 , enum V_24 V_25 )
{
struct V_1 * V_2 ;
if ( ! V_22 )
V_22 = F_92 () ;
F_113 () ;
F_114 (bdi, &bdi_list, bdi_list) {
if ( ! F_115 ( V_2 ) )
continue;
F_13 ( V_2 , V_22 , false , V_25 ) ;
}
F_116 () ;
}
static T_2 void F_117 ( struct V_5 * V_5 )
{
if ( V_5 -> V_120 || strcmp ( V_5 -> V_8 -> V_121 , L_2 ) ) {
struct V_122 * V_122 ;
const char * V_123 = L_3 ;
V_122 = F_118 ( V_5 ) ;
if ( V_122 ) {
F_20 ( & V_122 -> V_124 ) ;
V_123 = ( const char * ) V_122 -> V_125 . V_123 ;
}
F_119 ( V_126
L_4 ,
V_115 -> V_127 , F_120 ( V_115 ) , V_5 -> V_120 ,
V_123 , V_5 -> V_8 -> V_121 ) ;
if ( V_122 ) {
F_22 ( & V_122 -> V_124 ) ;
F_121 ( V_122 ) ;
}
}
}
void F_122 ( struct V_5 * V_5 , int V_116 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_2 = NULL ;
if ( V_116 & ( V_76 | V_77 ) ) {
F_123 ( V_5 , V_116 ) ;
if ( V_7 -> V_55 -> V_128 )
V_7 -> V_55 -> V_128 ( V_5 , V_116 ) ;
F_124 ( V_5 , V_116 ) ;
}
F_31 () ;
if ( ( V_5 -> V_37 & V_116 ) == V_116 )
return;
if ( F_125 ( V_129 ) )
F_117 ( V_5 ) ;
F_20 ( & V_5 -> V_56 ) ;
if ( ( V_5 -> V_37 & V_116 ) != V_116 ) {
const int V_130 = V_5 -> V_37 & V_64 ;
V_5 -> V_37 |= V_116 ;
if ( V_5 -> V_37 & V_38 )
goto V_131;
if ( ! F_126 ( V_5 -> V_132 ) ) {
if ( F_127 ( V_5 ) )
goto V_131;
}
if ( V_5 -> V_37 & V_63 )
goto V_131;
if ( ! V_130 ) {
bool V_133 = false ;
V_2 = F_3 ( V_5 ) ;
F_22 ( & V_5 -> V_56 ) ;
F_20 ( & V_2 -> V_20 . V_29 ) ;
if ( F_128 ( V_2 ) ) {
F_129 ( ! F_2 ( V_134 , & V_2 -> V_4 ) ,
L_5 , V_2 -> V_123 ) ;
if ( ! F_110 ( & V_2 -> V_20 ) )
V_133 = true ;
}
V_5 -> V_34 = V_35 ;
F_27 ( & V_5 -> V_13 , & V_2 -> V_20 . V_31 ) ;
F_22 ( & V_2 -> V_20 . V_29 ) ;
if ( V_133 )
F_130 ( V_2 ) ;
return;
}
}
V_131:
F_22 ( & V_5 -> V_56 ) ;
}
static void F_131 ( struct V_6 * V_7 )
{
struct V_5 * V_5 , * V_135 = NULL ;
F_61 ( ! F_132 ( & V_7 -> V_136 ) ) ;
F_20 ( & V_137 ) ;
F_133 (inode, &sb->s_inodes, i_sb_list) {
struct V_70 * V_71 = V_5 -> V_9 ;
F_20 ( & V_5 -> V_56 ) ;
if ( ( V_5 -> V_37 & ( V_63 | V_79 | V_95 ) ) ||
( V_71 -> V_138 == 0 ) ) {
F_22 ( & V_5 -> V_56 ) ;
continue;
}
F_134 ( V_5 ) ;
F_22 ( & V_5 -> V_56 ) ;
F_22 ( & V_137 ) ;
F_135 ( V_135 ) ;
V_135 = V_5 ;
F_64 ( V_71 ) ;
F_136 () ;
F_20 ( & V_137 ) ;
}
F_22 ( & V_137 ) ;
F_135 ( V_135 ) ;
}
void F_137 ( struct V_6 * V_7 ,
unsigned long V_139 ,
enum V_24 V_25 )
{
F_138 ( V_111 ) ;
struct V_14 V_15 = {
. V_7 = V_7 ,
. V_27 = V_28 ,
. V_66 = 1 ,
. V_111 = & V_111 ,
. V_22 = V_139 ,
. V_25 = V_25 ,
} ;
if ( V_7 -> V_10 == & V_140 )
return;
F_61 ( ! F_132 ( & V_7 -> V_136 ) ) ;
F_7 ( V_7 -> V_10 , & V_15 ) ;
F_139 ( & V_111 ) ;
}
void F_140 ( struct V_6 * V_7 , enum V_24 V_25 )
{
return F_137 ( V_7 , F_92 () , V_25 ) ;
}
int F_141 ( struct V_6 * V_7 ,
unsigned long V_139 ,
enum V_24 V_25 )
{
if ( F_1 ( V_7 -> V_10 ) )
return 1 ;
if ( ! F_142 ( & V_7 -> V_136 ) )
return 0 ;
F_137 ( V_7 , V_139 , V_25 ) ;
F_143 ( & V_7 -> V_136 ) ;
return 1 ;
}
int F_144 ( struct V_6 * V_7 , enum V_24 V_25 )
{
return F_141 ( V_7 , F_92 () , V_25 ) ;
}
void F_145 ( struct V_6 * V_7 )
{
F_138 ( V_111 ) ;
struct V_14 V_15 = {
. V_7 = V_7 ,
. V_27 = V_65 ,
. V_22 = V_82 ,
. V_23 = 0 ,
. V_111 = & V_111 ,
. V_25 = V_141 ,
. V_73 = 1 ,
} ;
if ( V_7 -> V_10 == & V_140 )
return;
F_61 ( ! F_132 ( & V_7 -> V_136 ) ) ;
F_7 ( V_7 -> V_10 , & V_15 ) ;
F_139 ( & V_111 ) ;
F_131 ( V_7 ) ;
}
int F_146 ( struct V_5 * V_5 , int V_142 )
{
struct V_30 * V_20 = & F_3 ( V_5 ) -> V_20 ;
struct V_53 V_54 = {
. V_69 = V_82 ,
. V_27 = V_142 ? V_65 : V_28 ,
. V_89 = 0 ,
. V_90 = V_91 ,
} ;
if ( ! F_147 ( V_5 -> V_9 ) )
V_54 . V_69 = 0 ;
F_148 () ;
return F_66 ( V_5 , V_20 , & V_54 ) ;
}
int F_149 ( struct V_5 * V_5 , struct V_53 * V_54 )
{
return F_66 ( V_5 , & F_3 ( V_5 ) -> V_20 , V_54 ) ;
}
int F_150 ( struct V_5 * V_5 , int V_61 )
{
struct V_53 V_54 = {
. V_27 = V_61 ? V_65 : V_28 ,
. V_69 = 0 ,
} ;
return F_149 ( V_5 , & V_54 ) ;
}
