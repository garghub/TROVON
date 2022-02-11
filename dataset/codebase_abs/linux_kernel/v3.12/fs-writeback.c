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
if ( ! ( V_5 -> V_37 & V_64 ) )
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
long V_80 ;
if ( V_15 -> V_27 == V_65 || V_15 -> V_66 )
V_80 = V_81 ;
else {
V_80 = F_69 ( V_2 -> V_82 / 2 ,
V_83 / V_84 ) ;
V_80 = F_69 ( V_80 , V_15 -> V_22 ) ;
V_80 = F_70 ( V_80 + V_85 ,
V_85 ) ;
}
return V_80 ;
}
static long F_71 ( struct V_6 * V_7 ,
struct V_30 * V_20 ,
struct V_14 * V_15 )
{
struct V_53 V_54 = {
. V_27 = V_15 -> V_27 ,
. V_66 = V_15 -> V_66 ,
. V_86 = V_15 -> V_86 ,
. V_87 = V_15 -> V_87 ,
. V_73 = V_15 -> V_73 ,
. V_23 = V_15 -> V_23 ,
. V_88 = 0 ,
. V_89 = V_90 ,
} ;
unsigned long V_91 = V_35 ;
long V_92 ;
long V_93 = 0 ;
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
if ( V_5 -> V_37 & ( V_94 | V_63 | V_79 ) ) {
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
V_92 = F_68 ( V_20 -> V_2 , V_15 ) ;
V_54 . V_69 = V_92 ;
V_54 . V_67 = 0 ;
F_60 ( V_5 , & V_54 ) ;
V_15 -> V_22 -= V_92 - V_54 . V_69 ;
V_93 += V_92 - V_54 . V_69 ;
F_20 ( & V_20 -> V_29 ) ;
F_20 ( & V_5 -> V_56 ) ;
if ( ! ( V_5 -> V_37 & V_64 ) )
V_93 ++ ;
F_58 ( V_5 , V_20 , & V_54 ) ;
F_29 ( V_5 ) ;
F_22 ( & V_5 -> V_56 ) ;
F_73 ( & V_20 -> V_29 ) ;
if ( V_93 ) {
if ( F_74 ( V_91 + V_95 / 10UL ) )
break;
if ( V_15 -> V_22 <= 0 )
break;
}
}
return V_93 ;
}
static long F_75 ( struct V_30 * V_20 ,
struct V_14 * V_15 )
{
unsigned long V_91 = V_35 ;
long V_93 = 0 ;
while ( ! F_25 ( & V_20 -> V_52 ) ) {
struct V_5 * V_5 = F_5 ( V_20 -> V_52 . V_49 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! F_76 ( V_7 ) ) {
F_23 ( V_5 , V_20 ) ;
continue;
}
V_93 += F_71 ( V_7 , V_20 , V_15 ) ;
F_77 ( V_7 ) ;
if ( V_93 ) {
if ( F_74 ( V_91 + V_95 / 10UL ) )
break;
if ( V_15 -> V_22 <= 0 )
break;
}
}
return V_93 ;
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
unsigned long V_96 , V_97 ;
F_80 ( & V_96 , & V_97 ) ;
if ( F_81 ( V_98 ) +
F_81 ( V_99 ) > V_96 )
return true ;
if ( F_82 ( V_2 , V_100 ) >
F_83 ( V_2 , V_96 ) )
return true ;
return false ;
}
static void F_84 ( struct V_30 * V_20 ,
unsigned long V_91 )
{
F_85 ( V_20 -> V_2 , 0 , 0 , 0 , 0 , 0 , V_91 ) ;
}
static long F_86 ( struct V_30 * V_20 ,
struct V_14 * V_15 )
{
unsigned long V_101 = V_35 ;
long V_22 = V_15 -> V_22 ;
unsigned long V_102 ;
struct V_5 * V_5 ;
long V_103 ;
V_102 = V_35 ;
V_15 -> V_50 = & V_102 ;
F_20 ( & V_20 -> V_29 ) ;
for (; ; ) {
if ( V_15 -> V_22 <= 0 )
break;
if ( ( V_15 -> V_87 || V_15 -> V_86 ) &&
! F_25 ( & V_20 -> V_2 -> V_18 ) )
break;
if ( V_15 -> V_87 && ! F_79 ( V_20 -> V_2 ) )
break;
if ( V_15 -> V_86 ) {
V_102 = V_35 -
F_87 ( V_104 * 10 ) ;
} else if ( V_15 -> V_87 )
V_102 = V_35 ;
F_88 ( V_20 -> V_2 , V_15 ) ;
if ( F_25 ( & V_20 -> V_52 ) )
F_41 ( V_20 , V_15 ) ;
if ( V_15 -> V_7 )
V_103 = F_71 ( V_15 -> V_7 , V_20 , V_15 ) ;
else
V_103 = F_75 ( V_20 , V_15 ) ;
F_89 ( V_20 -> V_2 , V_15 ) ;
F_84 ( V_20 , V_101 ) ;
if ( V_103 )
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
return F_81 ( V_98 ) +
F_81 ( V_99 ) +
F_93 () ;
}
static long F_94 ( struct V_30 * V_20 )
{
if ( F_79 ( V_20 -> V_2 ) ) {
struct V_14 V_15 = {
. V_22 = V_81 ,
. V_27 = V_28 ,
. V_87 = 1 ,
. V_23 = 1 ,
. V_25 = V_105 ,
} ;
return F_86 ( V_20 , & V_15 ) ;
}
return 0 ;
}
static long F_95 ( struct V_30 * V_20 )
{
unsigned long V_106 ;
long V_22 ;
if ( ! V_107 )
return 0 ;
V_106 = V_20 -> V_108 +
F_87 ( V_107 * 10 ) ;
if ( F_26 ( V_35 , V_106 ) )
return 0 ;
V_20 -> V_108 = V_35 ;
V_22 = F_92 () ;
if ( V_22 ) {
struct V_14 V_15 = {
. V_22 = V_22 ,
. V_27 = V_28 ,
. V_86 = 1 ,
. V_23 = 1 ,
. V_25 = V_109 ,
} ;
return F_86 ( V_20 , & V_15 ) ;
}
return 0 ;
}
static long F_96 ( struct V_30 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_14 * V_15 ;
long V_93 = 0 ;
F_97 ( V_3 , & V_20 -> V_2 -> V_4 ) ;
while ( ( V_15 = F_91 ( V_2 ) ) != NULL ) {
F_98 ( V_2 , V_15 ) ;
V_93 += F_86 ( V_20 , V_15 ) ;
if ( V_15 -> V_110 )
F_99 ( V_15 -> V_110 ) ;
else
F_100 ( V_15 ) ;
}
V_93 += F_95 ( V_20 ) ;
V_93 += F_94 ( V_20 ) ;
F_101 ( V_3 , & V_20 -> V_2 -> V_4 ) ;
return V_93 ;
}
void F_102 ( struct V_111 * V_15 )
{
struct V_30 * V_20 = F_103 ( F_104 ( V_15 ) ,
struct V_30 , V_21 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
long V_112 ;
F_105 ( L_1 , F_106 ( V_2 -> V_113 ) ) ;
V_114 -> V_115 |= V_116 ;
if ( F_107 ( ! F_108 () ||
F_25 ( & V_2 -> V_117 ) ) ) {
do {
V_112 = F_96 ( V_20 ) ;
F_109 ( V_112 ) ;
} while ( ! F_25 ( & V_2 -> V_18 ) );
} else {
V_112 = F_78 ( & V_2 -> V_20 , 1024 ,
V_118 ) ;
F_109 ( V_112 ) ;
}
if ( ! F_25 ( & V_2 -> V_18 ) ||
( F_110 ( V_20 ) && V_107 ) )
F_111 ( V_19 , & V_20 -> V_21 ,
F_87 ( V_107 * 10 ) ) ;
V_114 -> V_115 &= ~ V_116 ;
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
if ( V_5 -> V_119 || strcmp ( V_5 -> V_8 -> V_120 , L_2 ) ) {
struct V_121 * V_121 ;
const char * V_122 = L_3 ;
V_121 = F_118 ( V_5 ) ;
if ( V_121 ) {
F_20 ( & V_121 -> V_123 ) ;
V_122 = ( const char * ) V_121 -> V_124 . V_122 ;
}
F_119 ( V_125
L_4 ,
V_114 -> V_126 , F_120 ( V_114 ) , V_5 -> V_119 ,
V_122 , V_5 -> V_8 -> V_120 ) ;
if ( V_121 ) {
F_22 ( & V_121 -> V_123 ) ;
F_121 ( V_121 ) ;
}
}
}
void F_122 ( struct V_5 * V_5 , int V_115 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_2 = NULL ;
if ( V_115 & ( V_76 | V_77 ) ) {
F_123 ( V_5 , V_115 ) ;
if ( V_7 -> V_55 -> V_127 )
V_7 -> V_55 -> V_127 ( V_5 , V_115 ) ;
F_124 ( V_5 , V_115 ) ;
}
F_31 () ;
if ( ( V_5 -> V_37 & V_115 ) == V_115 )
return;
if ( F_125 ( V_128 ) )
F_117 ( V_5 ) ;
F_20 ( & V_5 -> V_56 ) ;
if ( ( V_5 -> V_37 & V_115 ) != V_115 ) {
const int V_129 = V_5 -> V_37 & V_64 ;
V_5 -> V_37 |= V_115 ;
if ( V_5 -> V_37 & V_38 )
goto V_130;
if ( ! F_126 ( V_5 -> V_131 ) ) {
if ( F_127 ( V_5 ) )
goto V_130;
}
if ( V_5 -> V_37 & V_63 )
goto V_130;
if ( ! V_129 ) {
bool V_132 = false ;
V_2 = F_3 ( V_5 ) ;
F_22 ( & V_5 -> V_56 ) ;
F_20 ( & V_2 -> V_20 . V_29 ) ;
if ( F_128 ( V_2 ) ) {
F_129 ( ! F_2 ( V_133 , & V_2 -> V_4 ) ,
L_5 , V_2 -> V_122 ) ;
if ( ! F_110 ( & V_2 -> V_20 ) )
V_132 = true ;
}
V_5 -> V_34 = V_35 ;
F_27 ( & V_5 -> V_13 , & V_2 -> V_20 . V_31 ) ;
F_22 ( & V_2 -> V_20 . V_29 ) ;
if ( V_132 )
F_130 ( V_2 ) ;
return;
}
}
V_130:
F_22 ( & V_5 -> V_56 ) ;
}
static void F_131 ( struct V_6 * V_7 )
{
struct V_5 * V_5 , * V_134 = NULL ;
F_61 ( ! F_132 ( & V_7 -> V_135 ) ) ;
F_20 ( & V_136 ) ;
F_133 (inode, &sb->s_inodes, i_sb_list) {
struct V_70 * V_71 = V_5 -> V_9 ;
F_20 ( & V_5 -> V_56 ) ;
if ( ( V_5 -> V_37 & ( V_63 | V_79 | V_94 ) ) ||
( V_71 -> V_137 == 0 ) ) {
F_22 ( & V_5 -> V_56 ) ;
continue;
}
F_134 ( V_5 ) ;
F_22 ( & V_5 -> V_56 ) ;
F_22 ( & V_136 ) ;
F_135 ( V_134 ) ;
V_134 = V_5 ;
F_64 ( V_71 ) ;
F_136 () ;
F_20 ( & V_136 ) ;
}
F_22 ( & V_136 ) ;
F_135 ( V_134 ) ;
}
void F_137 ( struct V_6 * V_7 ,
unsigned long V_138 ,
enum V_24 V_25 )
{
F_138 ( V_110 ) ;
struct V_14 V_15 = {
. V_7 = V_7 ,
. V_27 = V_28 ,
. V_66 = 1 ,
. V_110 = & V_110 ,
. V_22 = V_138 ,
. V_25 = V_25 ,
} ;
if ( V_7 -> V_10 == & V_139 )
return;
F_61 ( ! F_132 ( & V_7 -> V_135 ) ) ;
F_7 ( V_7 -> V_10 , & V_15 ) ;
F_139 ( & V_110 ) ;
}
void F_140 ( struct V_6 * V_7 , enum V_24 V_25 )
{
return F_137 ( V_7 , F_92 () , V_25 ) ;
}
int F_141 ( struct V_6 * V_7 ,
unsigned long V_138 ,
enum V_24 V_25 )
{
if ( F_1 ( V_7 -> V_10 ) )
return 1 ;
if ( ! F_142 ( & V_7 -> V_135 ) )
return 0 ;
F_137 ( V_7 , V_138 , V_25 ) ;
F_143 ( & V_7 -> V_135 ) ;
return 1 ;
}
int F_144 ( struct V_6 * V_7 , enum V_24 V_25 )
{
return F_141 ( V_7 , F_92 () , V_25 ) ;
}
void F_145 ( struct V_6 * V_7 )
{
F_138 ( V_110 ) ;
struct V_14 V_15 = {
. V_7 = V_7 ,
. V_27 = V_65 ,
. V_22 = V_81 ,
. V_23 = 0 ,
. V_110 = & V_110 ,
. V_25 = V_140 ,
. V_73 = 1 ,
} ;
if ( V_7 -> V_10 == & V_139 )
return;
F_61 ( ! F_132 ( & V_7 -> V_135 ) ) ;
F_7 ( V_7 -> V_10 , & V_15 ) ;
F_139 ( & V_110 ) ;
F_131 ( V_7 ) ;
}
int F_146 ( struct V_5 * V_5 , int V_141 )
{
struct V_30 * V_20 = & F_3 ( V_5 ) -> V_20 ;
struct V_53 V_54 = {
. V_69 = V_81 ,
. V_27 = V_141 ? V_65 : V_28 ,
. V_88 = 0 ,
. V_89 = V_90 ,
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
