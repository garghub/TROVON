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
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_14 ) ;
if ( F_2 ( V_15 , & V_2 -> V_4 ) )
F_9 ( V_16 , & V_2 -> V_17 . V_18 , 0 ) ;
F_10 ( & V_2 -> V_14 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
F_12 ( V_2 , V_20 ) ;
F_8 ( & V_2 -> V_14 ) ;
if ( ! F_2 ( V_15 , & V_2 -> V_4 ) ) {
if ( V_20 -> V_21 )
F_13 ( V_20 -> V_21 ) ;
goto V_22;
}
F_14 ( & V_20 -> V_23 , & V_2 -> V_24 ) ;
F_9 ( V_16 , & V_2 -> V_17 . V_18 , 0 ) ;
V_22:
F_10 ( & V_2 -> V_14 ) ;
}
static void
F_15 ( struct V_1 * V_2 , long V_25 ,
bool V_26 , enum V_27 V_28 )
{
struct V_19 * V_20 ;
V_20 = F_16 ( sizeof( * V_20 ) , V_29 ) ;
if ( ! V_20 ) {
F_17 ( V_2 ) ;
F_7 ( V_2 ) ;
return;
}
V_20 -> V_30 = V_31 ;
V_20 -> V_25 = V_25 ;
V_20 -> V_26 = V_26 ;
V_20 -> V_28 = V_28 ;
F_11 ( V_2 , V_20 ) ;
}
void F_18 ( struct V_1 * V_2 , long V_25 ,
enum V_27 V_28 )
{
F_15 ( V_2 , V_25 , true , V_28 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
F_7 ( V_2 ) ;
}
void F_21 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
F_22 ( & V_2 -> V_17 . V_32 ) ;
F_23 ( & V_5 -> V_13 ) ;
F_24 ( & V_2 -> V_17 . V_32 ) ;
}
static void F_25 ( struct V_5 * V_5 , struct V_33 * V_17 )
{
F_26 ( & V_17 -> V_32 ) ;
if ( ! F_27 ( & V_17 -> V_34 ) ) {
struct V_5 * V_35 ;
V_35 = F_5 ( V_17 -> V_34 . V_36 ) ;
if ( F_28 ( V_5 -> V_37 , V_35 -> V_37 ) )
V_5 -> V_37 = V_38 ;
}
F_29 ( & V_5 -> V_13 , & V_17 -> V_34 ) ;
}
static void F_30 ( struct V_5 * V_5 , struct V_33 * V_17 )
{
F_26 ( & V_17 -> V_32 ) ;
F_29 ( & V_5 -> V_13 , & V_17 -> V_39 ) ;
}
static void F_31 ( struct V_5 * V_5 )
{
V_5 -> V_40 &= ~ V_41 ;
F_32 ( V_5 ) ;
F_33 () ;
F_34 ( & V_5 -> V_40 , V_42 ) ;
}
static bool F_35 ( struct V_5 * V_5 , unsigned long V_43 )
{
bool V_44 = F_36 ( V_5 -> V_37 , V_43 ) ;
#ifndef F_37
V_44 = V_44 && F_38 ( V_5 -> V_37 , V_38 ) ;
#endif
return V_44 ;
}
static int F_39 ( struct V_11 * V_45 ,
struct V_11 * V_46 ,
struct V_19 * V_20 )
{
F_40 ( V_47 ) ;
struct V_11 * V_48 , * V_49 ;
struct V_6 * V_7 = NULL ;
struct V_5 * V_5 ;
int V_50 = 0 ;
int V_51 = 0 ;
while ( ! F_27 ( V_45 ) ) {
V_5 = F_5 ( V_45 -> V_52 ) ;
if ( V_20 -> V_53 &&
F_35 ( V_5 , * V_20 -> V_53 ) )
break;
F_29 ( & V_5 -> V_13 , & V_47 ) ;
V_51 ++ ;
if ( F_4 ( V_5 -> V_8 ) )
continue;
if ( V_7 && V_7 != V_5 -> V_8 )
V_50 = 1 ;
V_7 = V_5 -> V_8 ;
}
if ( ! V_50 ) {
F_41 ( & V_47 , V_46 ) ;
goto V_54;
}
while ( ! F_27 ( & V_47 ) ) {
V_7 = F_5 ( V_47 . V_52 ) -> V_8 ;
F_42 (pos, node, &tmp) {
V_5 = F_5 ( V_48 ) ;
if ( V_5 -> V_8 == V_7 )
F_29 ( & V_5 -> V_13 , V_46 ) ;
}
}
V_54:
return V_51 ;
}
static void F_43 ( struct V_33 * V_17 , struct V_19 * V_20 )
{
int V_51 ;
F_26 ( & V_17 -> V_32 ) ;
F_44 ( & V_17 -> V_39 , & V_17 -> V_55 ) ;
V_51 = F_39 ( & V_17 -> V_34 , & V_17 -> V_55 , V_20 ) ;
F_45 ( V_17 , V_20 , V_51 ) ;
}
static int F_46 ( struct V_5 * V_5 , struct V_56 * V_57 )
{
int V_44 ;
if ( V_5 -> V_8 -> V_58 -> F_46 && ! F_47 ( V_5 ) ) {
F_48 ( V_5 , V_57 ) ;
V_44 = V_5 -> V_8 -> V_58 -> F_46 ( V_5 , V_57 ) ;
F_49 ( V_5 , V_57 ) ;
return V_44 ;
}
return 0 ;
}
static void F_50 ( struct V_5 * V_5 )
__releases( V_5 -> V_59 )
__acquires( V_5 -> V_59 )
{
F_51 ( V_60 , & V_5 -> V_40 , V_42 ) ;
T_1 * V_61 ;
V_61 = F_52 ( & V_5 -> V_40 , V_42 ) ;
while ( V_5 -> V_40 & V_41 ) {
F_24 ( & V_5 -> V_59 ) ;
F_53 ( V_61 , & V_60 , V_62 , V_63 ) ;
F_22 ( & V_5 -> V_59 ) ;
}
}
void F_54 ( struct V_5 * V_5 )
{
F_22 ( & V_5 -> V_59 ) ;
F_50 ( V_5 ) ;
F_24 ( & V_5 -> V_59 ) ;
}
static void F_55 ( struct V_5 * V_5 )
__releases( V_5 -> V_59 )
{
F_56 ( V_64 ) ;
T_1 * V_61 = F_52 ( & V_5 -> V_40 , V_42 ) ;
int V_65 ;
F_57 ( V_61 , & V_64 , V_63 ) ;
V_65 = V_5 -> V_40 & V_41 ;
F_24 ( & V_5 -> V_59 ) ;
if ( V_65 )
F_58 () ;
F_59 ( V_61 , & V_64 ) ;
}
static void F_60 ( struct V_5 * V_5 , struct V_33 * V_17 ,
struct V_56 * V_57 )
{
if ( V_5 -> V_40 & V_66 )
return;
if ( ( V_5 -> V_40 & V_67 ) &&
( V_57 -> V_30 == V_68 || V_57 -> V_69 ) )
V_5 -> V_37 = V_38 ;
if ( V_57 -> V_70 ) {
F_25 ( V_5 , V_17 ) ;
return;
}
if ( F_61 ( V_5 -> V_9 , V_71 ) ) {
if ( V_57 -> V_72 <= 0 ) {
F_30 ( V_5 , V_17 ) ;
} else {
F_25 ( V_5 , V_17 ) ;
}
} else if ( V_5 -> V_40 & V_67 ) {
F_25 ( V_5 , V_17 ) ;
} else {
F_23 ( & V_5 -> V_13 ) ;
}
}
static int
F_62 ( struct V_5 * V_5 , struct V_56 * V_57 )
{
struct V_73 * V_74 = V_5 -> V_9 ;
long V_72 = V_57 -> V_72 ;
unsigned V_75 ;
int V_44 ;
F_63 ( ! ( V_5 -> V_40 & V_41 ) ) ;
F_64 ( V_5 , V_57 , V_72 ) ;
V_44 = F_65 ( V_74 , V_57 ) ;
if ( V_57 -> V_30 == V_68 && ! V_57 -> V_76 ) {
int V_77 = F_66 ( V_74 ) ;
if ( V_44 == 0 )
V_44 = V_77 ;
}
F_22 ( & V_5 -> V_59 ) ;
if ( ! F_61 ( V_74 , V_71 ) )
V_5 -> V_40 &= ~ V_78 ;
V_75 = V_5 -> V_40 & V_67 ;
V_5 -> V_40 &= ~ ( V_79 | V_80 ) ;
F_24 ( & V_5 -> V_59 ) ;
if ( V_75 & ( V_79 | V_80 ) ) {
int V_77 = F_46 ( V_5 , V_57 ) ;
if ( V_44 == 0 )
V_44 = V_77 ;
}
F_67 ( V_5 , V_57 , V_72 ) ;
return V_44 ;
}
static int
F_68 ( struct V_5 * V_5 , struct V_33 * V_17 ,
struct V_56 * V_57 )
{
int V_44 = 0 ;
F_22 ( & V_5 -> V_59 ) ;
if ( ! F_69 ( & V_5 -> V_81 ) )
F_63 ( ! ( V_5 -> V_40 & ( V_82 | V_66 ) ) ) ;
else
F_63 ( V_5 -> V_40 & V_82 ) ;
if ( V_5 -> V_40 & V_41 ) {
if ( V_57 -> V_30 != V_68 )
goto V_54;
F_50 ( V_5 ) ;
}
F_63 ( V_5 -> V_40 & V_41 ) ;
if ( ! ( V_5 -> V_40 & V_67 ) &&
( V_57 -> V_30 != V_68 ||
! F_61 ( V_5 -> V_9 , V_83 ) ) )
goto V_54;
V_5 -> V_40 |= V_41 ;
F_24 ( & V_5 -> V_59 ) ;
V_44 = F_62 ( V_5 , V_57 ) ;
F_22 ( & V_17 -> V_32 ) ;
F_22 ( & V_5 -> V_59 ) ;
if ( ! ( V_5 -> V_40 & V_67 ) )
F_23 ( & V_5 -> V_13 ) ;
F_24 ( & V_17 -> V_32 ) ;
F_31 ( V_5 ) ;
V_54:
F_24 ( & V_5 -> V_59 ) ;
return V_44 ;
}
static long F_70 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
long V_84 ;
if ( V_20 -> V_30 == V_68 || V_20 -> V_69 )
V_84 = V_85 ;
else {
V_84 = F_71 ( V_2 -> V_86 / 2 ,
V_87 / V_88 ) ;
V_84 = F_71 ( V_84 , V_20 -> V_25 ) ;
V_84 = F_72 ( V_84 + V_89 ,
V_89 ) ;
}
return V_84 ;
}
static long F_73 ( struct V_6 * V_7 ,
struct V_33 * V_17 ,
struct V_19 * V_20 )
{
struct V_56 V_57 = {
. V_30 = V_20 -> V_30 ,
. V_69 = V_20 -> V_69 ,
. V_90 = V_20 -> V_90 ,
. V_91 = V_20 -> V_91 ,
. V_76 = V_20 -> V_76 ,
. V_26 = V_20 -> V_26 ,
. V_92 = 0 ,
. V_93 = V_94 ,
} ;
unsigned long V_95 = V_38 ;
long V_96 ;
long V_97 = 0 ;
while ( ! F_27 ( & V_17 -> V_55 ) ) {
struct V_5 * V_5 = F_5 ( V_17 -> V_55 . V_52 ) ;
if ( V_5 -> V_8 != V_7 ) {
if ( V_20 -> V_7 ) {
F_25 ( V_5 , V_17 ) ;
continue;
}
break;
}
F_22 ( & V_5 -> V_59 ) ;
if ( V_5 -> V_40 & ( V_98 | V_66 | V_82 ) ) {
F_24 ( & V_5 -> V_59 ) ;
F_25 ( V_5 , V_17 ) ;
continue;
}
if ( ( V_5 -> V_40 & V_41 ) && V_57 . V_30 != V_68 ) {
F_24 ( & V_5 -> V_59 ) ;
F_30 ( V_5 , V_17 ) ;
F_74 ( V_5 ) ;
continue;
}
F_24 ( & V_17 -> V_32 ) ;
if ( V_5 -> V_40 & V_41 ) {
F_55 ( V_5 ) ;
F_22 ( & V_17 -> V_32 ) ;
continue;
}
V_5 -> V_40 |= V_41 ;
F_24 ( & V_5 -> V_59 ) ;
V_96 = F_70 ( V_17 -> V_2 , V_20 ) ;
V_57 . V_72 = V_96 ;
V_57 . V_70 = 0 ;
F_62 ( V_5 , & V_57 ) ;
V_20 -> V_25 -= V_96 - V_57 . V_72 ;
V_97 += V_96 - V_57 . V_72 ;
F_22 ( & V_17 -> V_32 ) ;
F_22 ( & V_5 -> V_59 ) ;
if ( ! ( V_5 -> V_40 & V_67 ) )
V_97 ++ ;
F_60 ( V_5 , V_17 , & V_57 ) ;
F_31 ( V_5 ) ;
F_24 ( & V_5 -> V_59 ) ;
F_75 ( & V_17 -> V_32 ) ;
if ( V_97 ) {
if ( F_76 ( V_95 + V_99 / 10UL ) )
break;
if ( V_20 -> V_25 <= 0 )
break;
}
}
return V_97 ;
}
static long F_77 ( struct V_33 * V_17 ,
struct V_19 * V_20 )
{
unsigned long V_95 = V_38 ;
long V_97 = 0 ;
while ( ! F_27 ( & V_17 -> V_55 ) ) {
struct V_5 * V_5 = F_5 ( V_17 -> V_55 . V_52 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! F_78 ( V_7 ) ) {
F_25 ( V_5 , V_17 ) ;
continue;
}
V_97 += F_73 ( V_7 , V_17 , V_20 ) ;
F_79 ( V_7 ) ;
if ( V_97 ) {
if ( F_76 ( V_95 + V_99 / 10UL ) )
break;
if ( V_20 -> V_25 <= 0 )
break;
}
}
return V_97 ;
}
static long F_80 ( struct V_33 * V_17 , long V_25 ,
enum V_27 V_28 )
{
struct V_19 V_20 = {
. V_25 = V_25 ,
. V_30 = V_31 ,
. V_26 = 1 ,
. V_28 = V_28 ,
} ;
F_22 ( & V_17 -> V_32 ) ;
if ( F_27 ( & V_17 -> V_55 ) )
F_43 ( V_17 , & V_20 ) ;
F_77 ( V_17 , & V_20 ) ;
F_24 ( & V_17 -> V_32 ) ;
return V_25 - V_20 . V_25 ;
}
static bool F_81 ( struct V_1 * V_2 )
{
unsigned long V_100 , V_101 ;
F_82 ( & V_100 , & V_101 ) ;
if ( F_83 ( V_102 ) +
F_83 ( V_103 ) > V_100 )
return true ;
if ( F_84 ( V_2 , V_104 ) >
F_85 ( V_2 , V_100 ) )
return true ;
return false ;
}
static void F_86 ( struct V_33 * V_17 ,
unsigned long V_95 )
{
F_87 ( V_17 -> V_2 , 0 , 0 , 0 , 0 , 0 , V_95 ) ;
}
static long F_88 ( struct V_33 * V_17 ,
struct V_19 * V_20 )
{
unsigned long V_105 = V_38 ;
long V_25 = V_20 -> V_25 ;
unsigned long V_106 ;
struct V_5 * V_5 ;
long V_107 ;
V_106 = V_38 ;
V_20 -> V_53 = & V_106 ;
F_22 ( & V_17 -> V_32 ) ;
for (; ; ) {
if ( V_20 -> V_25 <= 0 )
break;
if ( ( V_20 -> V_91 || V_20 -> V_90 ) &&
! F_27 ( & V_17 -> V_2 -> V_24 ) )
break;
if ( V_20 -> V_91 && ! F_81 ( V_17 -> V_2 ) )
break;
if ( V_20 -> V_90 ) {
V_106 = V_38 -
F_89 ( V_108 * 10 ) ;
} else if ( V_20 -> V_91 )
V_106 = V_38 ;
F_90 ( V_17 -> V_2 , V_20 ) ;
if ( F_27 ( & V_17 -> V_55 ) )
F_43 ( V_17 , V_20 ) ;
if ( V_20 -> V_7 )
V_107 = F_73 ( V_20 -> V_7 , V_17 , V_20 ) ;
else
V_107 = F_77 ( V_17 , V_20 ) ;
F_91 ( V_17 -> V_2 , V_20 ) ;
F_86 ( V_17 , V_105 ) ;
if ( V_107 )
continue;
if ( F_27 ( & V_17 -> V_39 ) )
break;
if ( ! F_27 ( & V_17 -> V_39 ) ) {
F_92 ( V_17 -> V_2 , V_20 ) ;
V_5 = F_5 ( V_17 -> V_39 . V_52 ) ;
F_22 ( & V_5 -> V_59 ) ;
F_24 ( & V_17 -> V_32 ) ;
F_55 ( V_5 ) ;
F_22 ( & V_17 -> V_32 ) ;
}
}
F_24 ( & V_17 -> V_32 ) ;
return V_25 - V_20 -> V_25 ;
}
static struct V_19 *
F_93 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = NULL ;
F_8 ( & V_2 -> V_14 ) ;
if ( ! F_27 ( & V_2 -> V_24 ) ) {
V_20 = F_6 ( V_2 -> V_24 . V_36 ,
struct V_19 , V_23 ) ;
F_23 ( & V_20 -> V_23 ) ;
}
F_10 ( & V_2 -> V_14 ) ;
return V_20 ;
}
static unsigned long F_94 ( void )
{
return F_83 ( V_102 ) +
F_83 ( V_103 ) +
F_95 () ;
}
static long F_96 ( struct V_33 * V_17 )
{
if ( F_81 ( V_17 -> V_2 ) ) {
struct V_19 V_20 = {
. V_25 = V_85 ,
. V_30 = V_31 ,
. V_91 = 1 ,
. V_26 = 1 ,
. V_28 = V_109 ,
} ;
return F_88 ( V_17 , & V_20 ) ;
}
return 0 ;
}
static long F_97 ( struct V_33 * V_17 )
{
unsigned long V_110 ;
long V_25 ;
if ( ! V_111 )
return 0 ;
V_110 = V_17 -> V_112 +
F_89 ( V_111 * 10 ) ;
if ( F_28 ( V_38 , V_110 ) )
return 0 ;
V_17 -> V_112 = V_38 ;
V_25 = F_94 () ;
if ( V_25 ) {
struct V_19 V_20 = {
. V_25 = V_25 ,
. V_30 = V_31 ,
. V_90 = 1 ,
. V_26 = 1 ,
. V_28 = V_113 ,
} ;
return F_88 ( V_17 , & V_20 ) ;
}
return 0 ;
}
static long F_98 ( struct V_33 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_19 * V_20 ;
long V_97 = 0 ;
F_99 ( V_3 , & V_17 -> V_2 -> V_4 ) ;
while ( ( V_20 = F_93 ( V_2 ) ) != NULL ) {
F_100 ( V_2 , V_20 ) ;
V_97 += F_88 ( V_17 , V_20 ) ;
if ( V_20 -> V_21 )
F_13 ( V_20 -> V_21 ) ;
else
F_101 ( V_20 ) ;
}
V_97 += F_97 ( V_17 ) ;
V_97 += F_96 ( V_17 ) ;
F_102 ( V_3 , & V_17 -> V_2 -> V_4 ) ;
return V_97 ;
}
void F_103 ( struct V_114 * V_20 )
{
struct V_33 * V_17 = F_104 ( F_105 ( V_20 ) ,
struct V_33 , V_18 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
long V_115 ;
F_106 ( L_1 , F_107 ( V_2 -> V_116 ) ) ;
V_117 -> V_118 |= V_119 ;
if ( F_108 ( ! F_109 () ||
! F_2 ( V_15 , & V_2 -> V_4 ) ) ) {
do {
V_115 = F_98 ( V_17 ) ;
F_110 ( V_115 ) ;
} while ( ! F_27 ( & V_2 -> V_24 ) );
} else {
V_115 = F_80 ( & V_2 -> V_17 , 1024 ,
V_120 ) ;
F_110 ( V_115 ) ;
}
if ( ! F_27 ( & V_2 -> V_24 ) )
F_9 ( V_16 , & V_17 -> V_18 , 0 ) ;
else if ( F_111 ( V_17 ) && V_111 )
F_112 ( V_2 ) ;
V_117 -> V_118 &= ~ V_119 ;
}
void F_113 ( long V_25 , enum V_27 V_28 )
{
struct V_1 * V_2 ;
if ( ! V_25 )
V_25 = F_94 () ;
F_114 () ;
F_115 (bdi, &bdi_list, bdi_list) {
if ( ! F_116 ( V_2 ) )
continue;
F_15 ( V_2 , V_25 , false , V_28 ) ;
}
F_117 () ;
}
static T_2 void F_118 ( struct V_5 * V_5 )
{
if ( V_5 -> V_121 || strcmp ( V_5 -> V_8 -> V_122 , L_2 ) ) {
struct V_123 * V_123 ;
const char * V_124 = L_3 ;
V_123 = F_119 ( V_5 ) ;
if ( V_123 ) {
F_22 ( & V_123 -> V_125 ) ;
V_124 = ( const char * ) V_123 -> V_126 . V_124 ;
}
F_120 ( V_127
L_4 ,
V_117 -> V_128 , F_121 ( V_117 ) , V_5 -> V_121 ,
V_124 , V_5 -> V_8 -> V_122 ) ;
if ( V_123 ) {
F_24 ( & V_123 -> V_125 ) ;
F_122 ( V_123 ) ;
}
}
}
void F_123 ( struct V_5 * V_5 , int V_118 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_2 = NULL ;
if ( V_118 & ( V_79 | V_80 ) ) {
F_124 ( V_5 , V_118 ) ;
if ( V_7 -> V_58 -> V_129 )
V_7 -> V_58 -> V_129 ( V_5 , V_118 ) ;
F_125 ( V_5 , V_118 ) ;
}
F_33 () ;
if ( ( V_5 -> V_40 & V_118 ) == V_118 )
return;
if ( F_126 ( V_130 ) )
F_118 ( V_5 ) ;
F_22 ( & V_5 -> V_59 ) ;
if ( ( V_5 -> V_40 & V_118 ) != V_118 ) {
const int V_131 = V_5 -> V_40 & V_67 ;
V_5 -> V_40 |= V_118 ;
if ( V_5 -> V_40 & V_41 )
goto V_132;
if ( ! F_127 ( V_5 -> V_133 ) ) {
if ( F_128 ( V_5 ) )
goto V_132;
}
if ( V_5 -> V_40 & V_66 )
goto V_132;
if ( ! V_131 ) {
bool V_134 = false ;
V_2 = F_3 ( V_5 ) ;
F_24 ( & V_5 -> V_59 ) ;
F_22 ( & V_2 -> V_17 . V_32 ) ;
if ( F_129 ( V_2 ) ) {
F_130 ( ! F_2 ( V_15 , & V_2 -> V_4 ) ,
L_5 , V_2 -> V_124 ) ;
if ( ! F_111 ( & V_2 -> V_17 ) )
V_134 = true ;
}
V_5 -> V_37 = V_38 ;
F_29 ( & V_5 -> V_13 , & V_2 -> V_17 . V_34 ) ;
F_24 ( & V_2 -> V_17 . V_32 ) ;
if ( V_134 )
F_112 ( V_2 ) ;
return;
}
}
V_132:
F_24 ( & V_5 -> V_59 ) ;
}
static void F_131 ( struct V_6 * V_7 )
{
struct V_5 * V_5 , * V_135 = NULL ;
F_63 ( ! F_132 ( & V_7 -> V_136 ) ) ;
F_22 ( & V_137 ) ;
F_133 (inode, &sb->s_inodes, i_sb_list) {
struct V_73 * V_74 = V_5 -> V_9 ;
F_22 ( & V_5 -> V_59 ) ;
if ( ( V_5 -> V_40 & ( V_66 | V_82 | V_98 ) ) ||
( V_74 -> V_138 == 0 ) ) {
F_24 ( & V_5 -> V_59 ) ;
continue;
}
F_134 ( V_5 ) ;
F_24 ( & V_5 -> V_59 ) ;
F_24 ( & V_137 ) ;
F_135 ( V_135 ) ;
V_135 = V_5 ;
F_66 ( V_74 ) ;
F_136 () ;
F_22 ( & V_137 ) ;
}
F_24 ( & V_137 ) ;
F_135 ( V_135 ) ;
}
void F_137 ( struct V_6 * V_7 ,
unsigned long V_139 ,
enum V_27 V_28 )
{
F_138 ( V_21 ) ;
struct V_19 V_20 = {
. V_7 = V_7 ,
. V_30 = V_31 ,
. V_69 = 1 ,
. V_21 = & V_21 ,
. V_25 = V_139 ,
. V_28 = V_28 ,
} ;
if ( V_7 -> V_10 == & V_140 )
return;
F_63 ( ! F_132 ( & V_7 -> V_136 ) ) ;
F_11 ( V_7 -> V_10 , & V_20 ) ;
F_139 ( & V_21 ) ;
}
void F_140 ( struct V_6 * V_7 , enum V_27 V_28 )
{
return F_137 ( V_7 , F_94 () , V_28 ) ;
}
int F_141 ( struct V_6 * V_7 ,
unsigned long V_139 ,
enum V_27 V_28 )
{
if ( F_1 ( V_7 -> V_10 ) )
return 1 ;
if ( ! F_142 ( & V_7 -> V_136 ) )
return 0 ;
F_137 ( V_7 , V_139 , V_28 ) ;
F_143 ( & V_7 -> V_136 ) ;
return 1 ;
}
int F_144 ( struct V_6 * V_7 , enum V_27 V_28 )
{
return F_141 ( V_7 , F_94 () , V_28 ) ;
}
void F_145 ( struct V_6 * V_7 )
{
F_138 ( V_21 ) ;
struct V_19 V_20 = {
. V_7 = V_7 ,
. V_30 = V_68 ,
. V_25 = V_85 ,
. V_26 = 0 ,
. V_21 = & V_21 ,
. V_28 = V_141 ,
. V_76 = 1 ,
} ;
if ( V_7 -> V_10 == & V_140 )
return;
F_63 ( ! F_132 ( & V_7 -> V_136 ) ) ;
F_11 ( V_7 -> V_10 , & V_20 ) ;
F_139 ( & V_21 ) ;
F_131 ( V_7 ) ;
}
int F_146 ( struct V_5 * V_5 , int V_142 )
{
struct V_33 * V_17 = & F_3 ( V_5 ) -> V_17 ;
struct V_56 V_57 = {
. V_72 = V_85 ,
. V_30 = V_142 ? V_68 : V_31 ,
. V_92 = 0 ,
. V_93 = V_94 ,
} ;
if ( ! F_147 ( V_5 -> V_9 ) )
V_57 . V_72 = 0 ;
F_148 () ;
return F_68 ( V_5 , V_17 , & V_57 ) ;
}
int F_149 ( struct V_5 * V_5 , struct V_56 * V_57 )
{
return F_68 ( V_5 , & F_3 ( V_5 ) -> V_17 , V_57 ) ;
}
int F_150 ( struct V_5 * V_5 , int V_64 )
{
struct V_56 V_57 = {
. V_30 = V_64 ? V_68 : V_31 ,
. V_72 = 0 ,
} ;
return F_149 ( V_5 , & V_57 ) ;
}
