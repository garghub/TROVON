int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 , & V_2 -> V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( strcmp ( V_7 -> V_9 -> V_10 , L_1 ) == 0 )
return V_5 -> V_11 -> V_1 ;
return V_7 -> V_12 ;
}
static inline struct V_5 * F_4 ( struct V_13 * V_14 )
{
return F_5 ( V_14 , struct V_5 , V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
F_7 ( V_2 , V_17 ) ;
F_8 ( & V_2 -> V_18 ) ;
F_9 ( & V_17 -> V_19 , & V_2 -> V_20 ) ;
F_10 ( & V_2 -> V_18 ) ;
F_11 ( V_21 , & V_2 -> V_22 . V_23 , 0 ) ;
}
static void
F_12 ( struct V_1 * V_2 , long V_24 ,
bool V_25 , enum V_26 V_27 )
{
struct V_16 * V_17 ;
V_17 = F_13 ( sizeof( * V_17 ) , V_28 ) ;
if ( ! V_17 ) {
F_14 ( V_2 ) ;
F_11 ( V_21 , & V_2 -> V_22 . V_23 , 0 ) ;
return;
}
V_17 -> V_29 = V_30 ;
V_17 -> V_24 = V_24 ;
V_17 -> V_25 = V_25 ;
V_17 -> V_27 = V_27 ;
F_6 ( V_2 , V_17 ) ;
}
void F_15 ( struct V_1 * V_2 , long V_24 ,
enum V_26 V_27 )
{
F_12 ( V_2 , V_24 , true , V_27 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
F_11 ( V_21 , & V_2 -> V_22 . V_23 , 0 ) ;
}
void F_18 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
F_19 ( & V_2 -> V_22 . V_31 ) ;
F_20 ( & V_5 -> V_15 ) ;
F_21 ( & V_2 -> V_22 . V_31 ) ;
}
static void F_22 ( struct V_5 * V_5 , struct V_32 * V_22 )
{
F_23 ( & V_22 -> V_31 ) ;
if ( ! F_24 ( & V_22 -> V_33 ) ) {
struct V_5 * V_34 ;
V_34 = F_4 ( V_22 -> V_33 . V_35 ) ;
if ( F_25 ( V_5 -> V_36 , V_34 -> V_36 ) )
V_5 -> V_36 = V_37 ;
}
F_26 ( & V_5 -> V_15 , & V_22 -> V_33 ) ;
}
static void F_27 ( struct V_5 * V_5 , struct V_32 * V_22 )
{
F_23 ( & V_22 -> V_31 ) ;
F_26 ( & V_5 -> V_15 , & V_22 -> V_38 ) ;
}
static void F_28 ( struct V_5 * V_5 )
{
V_5 -> V_39 &= ~ V_40 ;
F_29 ( V_5 ) ;
F_30 () ;
F_31 ( & V_5 -> V_39 , V_41 ) ;
}
static bool F_32 ( struct V_5 * V_5 , unsigned long V_42 )
{
bool V_43 = F_33 ( V_5 -> V_36 , V_42 ) ;
#ifndef F_34
V_43 = V_43 && F_35 ( V_5 -> V_36 , V_37 ) ;
#endif
return V_43 ;
}
static int F_36 ( struct V_13 * V_44 ,
struct V_13 * V_45 ,
struct V_16 * V_17 )
{
F_37 ( V_46 ) ;
struct V_13 * V_47 , * V_48 ;
struct V_6 * V_7 = NULL ;
struct V_5 * V_5 ;
int V_49 = 0 ;
int V_50 = 0 ;
while ( ! F_24 ( V_44 ) ) {
V_5 = F_4 ( V_44 -> V_51 ) ;
if ( V_17 -> V_52 &&
F_32 ( V_5 , * V_17 -> V_52 ) )
break;
if ( V_7 && V_7 != V_5 -> V_8 )
V_49 = 1 ;
V_7 = V_5 -> V_8 ;
F_26 ( & V_5 -> V_15 , & V_46 ) ;
V_50 ++ ;
}
if ( ! V_49 ) {
F_38 ( & V_46 , V_45 ) ;
goto V_53;
}
while ( ! F_24 ( & V_46 ) ) {
V_7 = F_4 ( V_46 . V_51 ) -> V_8 ;
F_39 (pos, node, &tmp) {
V_5 = F_4 ( V_47 ) ;
if ( V_5 -> V_8 == V_7 )
F_26 ( & V_5 -> V_15 , V_45 ) ;
}
}
V_53:
return V_50 ;
}
static void F_40 ( struct V_32 * V_22 , struct V_16 * V_17 )
{
int V_50 ;
F_23 ( & V_22 -> V_31 ) ;
F_41 ( & V_22 -> V_38 , & V_22 -> V_54 ) ;
V_50 = F_36 ( & V_22 -> V_33 , & V_22 -> V_54 , V_17 ) ;
F_42 ( V_22 , V_17 , V_50 ) ;
}
static int F_43 ( struct V_5 * V_5 , struct V_55 * V_56 )
{
int V_43 ;
if ( V_5 -> V_8 -> V_57 -> F_43 && ! F_44 ( V_5 ) ) {
F_45 ( V_5 , V_56 ) ;
V_43 = V_5 -> V_8 -> V_57 -> F_43 ( V_5 , V_56 ) ;
F_46 ( V_5 , V_56 ) ;
return V_43 ;
}
return 0 ;
}
static void F_47 ( struct V_5 * V_5 )
__releases( V_5 -> V_58 )
__acquires( V_5 -> V_58 )
{
F_48 ( V_59 , & V_5 -> V_39 , V_41 ) ;
T_1 * V_60 ;
V_60 = F_49 ( & V_5 -> V_39 , V_41 ) ;
while ( V_5 -> V_39 & V_40 ) {
F_21 ( & V_5 -> V_58 ) ;
F_50 ( V_60 , & V_59 , V_61 , V_62 ) ;
F_19 ( & V_5 -> V_58 ) ;
}
}
void F_51 ( struct V_5 * V_5 )
{
F_19 ( & V_5 -> V_58 ) ;
F_47 ( V_5 ) ;
F_21 ( & V_5 -> V_58 ) ;
}
static void F_52 ( struct V_5 * V_5 )
__releases( V_5 -> V_58 )
{
F_53 ( V_63 ) ;
T_1 * V_60 = F_49 ( & V_5 -> V_39 , V_41 ) ;
int V_64 ;
F_54 ( V_60 , & V_63 , V_62 ) ;
V_64 = V_5 -> V_39 & V_40 ;
F_21 ( & V_5 -> V_58 ) ;
if ( V_64 )
F_55 () ;
F_56 ( V_60 , & V_63 ) ;
}
static void F_57 ( struct V_5 * V_5 , struct V_32 * V_22 ,
struct V_55 * V_56 )
{
if ( V_5 -> V_39 & V_65 )
return;
if ( ( V_5 -> V_39 & V_66 ) &&
( V_56 -> V_29 == V_67 || V_56 -> V_68 ) )
V_5 -> V_36 = V_37 ;
if ( V_56 -> V_69 ) {
F_22 ( V_5 , V_22 ) ;
return;
}
if ( F_58 ( V_5 -> V_11 , V_70 ) ) {
if ( V_56 -> V_71 <= 0 ) {
F_27 ( V_5 , V_22 ) ;
} else {
F_22 ( V_5 , V_22 ) ;
}
} else if ( V_5 -> V_39 & V_66 ) {
F_22 ( V_5 , V_22 ) ;
} else {
F_20 ( & V_5 -> V_15 ) ;
}
}
static int
F_59 ( struct V_5 * V_5 , struct V_55 * V_56 )
{
struct V_72 * V_73 = V_5 -> V_11 ;
long V_71 = V_56 -> V_71 ;
unsigned V_74 ;
int V_43 ;
F_60 ( ! ( V_5 -> V_39 & V_40 ) ) ;
F_61 ( V_5 , V_56 , V_71 ) ;
V_43 = F_62 ( V_73 , V_56 ) ;
if ( V_56 -> V_29 == V_67 && ! V_56 -> V_75 ) {
int V_76 = F_63 ( V_73 ) ;
if ( V_43 == 0 )
V_43 = V_76 ;
}
F_19 ( & V_5 -> V_58 ) ;
if ( ! F_58 ( V_73 , V_70 ) )
V_5 -> V_39 &= ~ V_77 ;
V_74 = V_5 -> V_39 & V_66 ;
V_5 -> V_39 &= ~ ( V_78 | V_79 ) ;
F_21 ( & V_5 -> V_58 ) ;
if ( V_74 & ( V_78 | V_79 ) ) {
int V_76 = F_43 ( V_5 , V_56 ) ;
if ( V_43 == 0 )
V_43 = V_76 ;
}
F_64 ( V_5 , V_56 , V_71 ) ;
return V_43 ;
}
static int
F_65 ( struct V_5 * V_5 , struct V_32 * V_22 ,
struct V_55 * V_56 )
{
int V_43 = 0 ;
F_19 ( & V_5 -> V_58 ) ;
if ( ! F_66 ( & V_5 -> V_80 ) )
F_60 ( ! ( V_5 -> V_39 & ( V_81 | V_65 ) ) ) ;
else
F_60 ( V_5 -> V_39 & V_81 ) ;
if ( V_5 -> V_39 & V_40 ) {
if ( V_56 -> V_29 != V_67 )
goto V_53;
F_47 ( V_5 ) ;
}
F_60 ( V_5 -> V_39 & V_40 ) ;
if ( ! ( V_5 -> V_39 & V_66 ) )
goto V_53;
V_5 -> V_39 |= V_40 ;
F_21 ( & V_5 -> V_58 ) ;
V_43 = F_59 ( V_5 , V_56 ) ;
F_19 ( & V_22 -> V_31 ) ;
F_19 ( & V_5 -> V_58 ) ;
if ( ! ( V_5 -> V_39 & V_66 ) )
F_20 ( & V_5 -> V_15 ) ;
F_21 ( & V_22 -> V_31 ) ;
F_28 ( V_5 ) ;
V_53:
F_21 ( & V_5 -> V_58 ) ;
return V_43 ;
}
static long F_67 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
long V_82 ;
if ( V_17 -> V_29 == V_67 || V_17 -> V_68 )
V_82 = V_83 ;
else {
V_82 = F_68 ( V_2 -> V_84 / 2 ,
V_85 / V_86 ) ;
V_82 = F_68 ( V_82 , V_17 -> V_24 ) ;
V_82 = F_69 ( V_82 + V_87 ,
V_87 ) ;
}
return V_82 ;
}
static long F_70 ( struct V_6 * V_7 ,
struct V_32 * V_22 ,
struct V_16 * V_17 )
{
struct V_55 V_56 = {
. V_29 = V_17 -> V_29 ,
. V_68 = V_17 -> V_68 ,
. V_88 = V_17 -> V_88 ,
. V_89 = V_17 -> V_89 ,
. V_75 = V_17 -> V_75 ,
. V_25 = V_17 -> V_25 ,
. V_90 = 0 ,
. V_91 = V_92 ,
} ;
unsigned long V_93 = V_37 ;
long V_94 ;
long V_95 = 0 ;
while ( ! F_24 ( & V_22 -> V_54 ) ) {
struct V_5 * V_5 = F_4 ( V_22 -> V_54 . V_51 ) ;
if ( V_5 -> V_8 != V_7 ) {
if ( V_17 -> V_7 ) {
F_22 ( V_5 , V_22 ) ;
continue;
}
break;
}
F_19 ( & V_5 -> V_58 ) ;
if ( V_5 -> V_39 & ( V_96 | V_65 | V_81 ) ) {
F_21 ( & V_5 -> V_58 ) ;
F_22 ( V_5 , V_22 ) ;
continue;
}
if ( ( V_5 -> V_39 & V_40 ) && V_56 . V_29 != V_67 ) {
F_21 ( & V_5 -> V_58 ) ;
F_27 ( V_5 , V_22 ) ;
F_71 ( V_5 ) ;
continue;
}
F_21 ( & V_22 -> V_31 ) ;
if ( V_5 -> V_39 & V_40 ) {
F_52 ( V_5 ) ;
F_19 ( & V_22 -> V_31 ) ;
continue;
}
V_5 -> V_39 |= V_40 ;
F_21 ( & V_5 -> V_58 ) ;
V_94 = F_67 ( V_22 -> V_2 , V_17 ) ;
V_56 . V_71 = V_94 ;
V_56 . V_69 = 0 ;
F_59 ( V_5 , & V_56 ) ;
V_17 -> V_24 -= V_94 - V_56 . V_71 ;
V_95 += V_94 - V_56 . V_71 ;
F_19 ( & V_22 -> V_31 ) ;
F_19 ( & V_5 -> V_58 ) ;
if ( ! ( V_5 -> V_39 & V_66 ) )
V_95 ++ ;
F_57 ( V_5 , V_22 , & V_56 ) ;
F_28 ( V_5 ) ;
F_21 ( & V_5 -> V_58 ) ;
F_72 ( & V_22 -> V_31 ) ;
if ( V_95 ) {
if ( F_73 ( V_93 + V_97 / 10UL ) )
break;
if ( V_17 -> V_24 <= 0 )
break;
}
}
return V_95 ;
}
static long F_74 ( struct V_32 * V_22 ,
struct V_16 * V_17 )
{
unsigned long V_93 = V_37 ;
long V_95 = 0 ;
while ( ! F_24 ( & V_22 -> V_54 ) ) {
struct V_5 * V_5 = F_4 ( V_22 -> V_54 . V_51 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! F_75 ( V_7 ) ) {
F_22 ( V_5 , V_22 ) ;
continue;
}
V_95 += F_70 ( V_7 , V_22 , V_17 ) ;
F_76 ( V_7 ) ;
if ( V_95 ) {
if ( F_73 ( V_93 + V_97 / 10UL ) )
break;
if ( V_17 -> V_24 <= 0 )
break;
}
}
return V_95 ;
}
long F_77 ( struct V_32 * V_22 , long V_24 ,
enum V_26 V_27 )
{
struct V_16 V_17 = {
. V_24 = V_24 ,
. V_29 = V_30 ,
. V_25 = 1 ,
. V_27 = V_27 ,
} ;
F_19 ( & V_22 -> V_31 ) ;
if ( F_24 ( & V_22 -> V_54 ) )
F_40 ( V_22 , & V_17 ) ;
F_74 ( V_22 , & V_17 ) ;
F_21 ( & V_22 -> V_31 ) ;
return V_24 - V_17 . V_24 ;
}
static bool F_78 ( struct V_1 * V_2 )
{
unsigned long V_98 , V_99 ;
F_79 ( & V_98 , & V_99 ) ;
if ( F_80 ( V_100 ) +
F_80 ( V_101 ) > V_98 )
return true ;
if ( F_81 ( V_2 , V_102 ) >
F_82 ( V_2 , V_98 ) )
return true ;
return false ;
}
static void F_83 ( struct V_32 * V_22 ,
unsigned long V_93 )
{
F_84 ( V_22 -> V_2 , 0 , 0 , 0 , 0 , 0 , V_93 ) ;
}
static long F_85 ( struct V_32 * V_22 ,
struct V_16 * V_17 )
{
unsigned long V_103 = V_37 ;
long V_24 = V_17 -> V_24 ;
unsigned long V_104 ;
struct V_5 * V_5 ;
long V_105 ;
V_104 = V_37 ;
V_17 -> V_52 = & V_104 ;
F_19 ( & V_22 -> V_31 ) ;
for (; ; ) {
if ( V_17 -> V_24 <= 0 )
break;
if ( ( V_17 -> V_89 || V_17 -> V_88 ) &&
! F_24 ( & V_22 -> V_2 -> V_20 ) )
break;
if ( V_17 -> V_89 && ! F_78 ( V_22 -> V_2 ) )
break;
if ( V_17 -> V_88 ) {
V_104 = V_37 -
F_86 ( V_106 * 10 ) ;
} else if ( V_17 -> V_89 )
V_104 = V_37 ;
F_87 ( V_22 -> V_2 , V_17 ) ;
if ( F_24 ( & V_22 -> V_54 ) )
F_40 ( V_22 , V_17 ) ;
if ( V_17 -> V_7 )
V_105 = F_70 ( V_17 -> V_7 , V_22 , V_17 ) ;
else
V_105 = F_74 ( V_22 , V_17 ) ;
F_88 ( V_22 -> V_2 , V_17 ) ;
F_83 ( V_22 , V_103 ) ;
if ( V_105 )
continue;
if ( F_24 ( & V_22 -> V_38 ) )
break;
if ( ! F_24 ( & V_22 -> V_38 ) ) {
F_89 ( V_22 -> V_2 , V_17 ) ;
V_5 = F_4 ( V_22 -> V_38 . V_51 ) ;
F_19 ( & V_5 -> V_58 ) ;
F_21 ( & V_22 -> V_31 ) ;
F_52 ( V_5 ) ;
F_19 ( & V_22 -> V_31 ) ;
}
}
F_21 ( & V_22 -> V_31 ) ;
return V_24 - V_17 -> V_24 ;
}
static struct V_16 *
F_90 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = NULL ;
F_8 ( & V_2 -> V_18 ) ;
if ( ! F_24 ( & V_2 -> V_20 ) ) {
V_17 = F_5 ( V_2 -> V_20 . V_35 ,
struct V_16 , V_19 ) ;
F_20 ( & V_17 -> V_19 ) ;
}
F_10 ( & V_2 -> V_18 ) ;
return V_17 ;
}
static unsigned long F_91 ( void )
{
return F_80 ( V_100 ) +
F_80 ( V_101 ) +
F_92 () ;
}
static long F_93 ( struct V_32 * V_22 )
{
if ( F_78 ( V_22 -> V_2 ) ) {
struct V_16 V_17 = {
. V_24 = V_83 ,
. V_29 = V_30 ,
. V_89 = 1 ,
. V_25 = 1 ,
. V_27 = V_107 ,
} ;
return F_85 ( V_22 , & V_17 ) ;
}
return 0 ;
}
static long F_94 ( struct V_32 * V_22 )
{
unsigned long V_108 ;
long V_24 ;
if ( ! V_109 )
return 0 ;
V_108 = V_22 -> V_110 +
F_86 ( V_109 * 10 ) ;
if ( F_25 ( V_37 , V_108 ) )
return 0 ;
V_22 -> V_110 = V_37 ;
V_24 = F_91 () ;
if ( V_24 ) {
struct V_16 V_17 = {
. V_24 = V_24 ,
. V_29 = V_30 ,
. V_88 = 1 ,
. V_25 = 1 ,
. V_27 = V_111 ,
} ;
return F_85 ( V_22 , & V_17 ) ;
}
return 0 ;
}
static long F_95 ( struct V_32 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_16 * V_17 ;
long V_95 = 0 ;
F_96 ( V_3 , & V_22 -> V_2 -> V_4 ) ;
while ( ( V_17 = F_90 ( V_2 ) ) != NULL ) {
F_97 ( V_2 , V_17 ) ;
V_95 += F_85 ( V_22 , V_17 ) ;
if ( V_17 -> V_112 )
F_98 ( V_17 -> V_112 ) ;
else
F_99 ( V_17 ) ;
}
V_95 += F_94 ( V_22 ) ;
V_95 += F_93 ( V_22 ) ;
F_100 ( V_3 , & V_22 -> V_2 -> V_4 ) ;
return V_95 ;
}
void F_101 ( struct V_113 * V_17 )
{
struct V_32 * V_22 = F_102 ( F_103 ( V_17 ) ,
struct V_32 , V_23 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
long V_114 ;
F_104 ( L_2 , F_105 ( V_2 -> V_115 ) ) ;
V_116 -> V_117 |= V_118 ;
if ( F_106 ( ! F_107 () ||
F_24 ( & V_2 -> V_119 ) ) ) {
do {
V_114 = F_95 ( V_22 ) ;
F_108 ( V_114 ) ;
} while ( ! F_24 ( & V_2 -> V_20 ) );
} else {
V_114 = F_77 ( & V_2 -> V_22 , 1024 ,
V_120 ) ;
F_108 ( V_114 ) ;
}
if ( ! F_24 ( & V_2 -> V_20 ) ||
( F_109 ( V_22 ) && V_109 ) )
F_110 ( V_21 , & V_22 -> V_23 ,
F_86 ( V_109 * 10 ) ) ;
V_116 -> V_117 &= ~ V_118 ;
}
void F_111 ( long V_24 , enum V_26 V_27 )
{
struct V_1 * V_2 ;
if ( ! V_24 ) {
V_24 = F_80 ( V_100 ) +
F_80 ( V_101 ) ;
}
F_112 () ;
F_113 (bdi, &bdi_list, bdi_list) {
if ( ! F_114 ( V_2 ) )
continue;
F_12 ( V_2 , V_24 , false , V_27 ) ;
}
F_115 () ;
}
static T_2 void F_116 ( struct V_5 * V_5 )
{
if ( V_5 -> V_121 || strcmp ( V_5 -> V_8 -> V_122 , L_1 ) ) {
struct V_123 * V_123 ;
const char * V_10 = L_3 ;
V_123 = F_117 ( V_5 ) ;
if ( V_123 ) {
F_19 ( & V_123 -> V_124 ) ;
V_10 = ( const char * ) V_123 -> V_125 . V_10 ;
}
F_118 ( V_126
L_4 ,
V_116 -> V_127 , F_119 ( V_116 ) , V_5 -> V_121 ,
V_10 , V_5 -> V_8 -> V_122 ) ;
if ( V_123 ) {
F_21 ( & V_123 -> V_124 ) ;
F_120 ( V_123 ) ;
}
}
}
void F_121 ( struct V_5 * V_5 , int V_117 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_2 = NULL ;
if ( V_117 & ( V_78 | V_79 ) ) {
F_122 ( V_5 , V_117 ) ;
if ( V_7 -> V_57 -> V_128 )
V_7 -> V_57 -> V_128 ( V_5 , V_117 ) ;
F_123 ( V_5 , V_117 ) ;
}
F_30 () ;
if ( ( V_5 -> V_39 & V_117 ) == V_117 )
return;
if ( F_124 ( V_129 ) )
F_116 ( V_5 ) ;
F_19 ( & V_5 -> V_58 ) ;
if ( ( V_5 -> V_39 & V_117 ) != V_117 ) {
const int V_130 = V_5 -> V_39 & V_66 ;
V_5 -> V_39 |= V_117 ;
if ( V_5 -> V_39 & V_40 )
goto V_131;
if ( ! F_125 ( V_5 -> V_132 ) ) {
if ( F_126 ( V_5 ) )
goto V_131;
}
if ( V_5 -> V_39 & V_65 )
goto V_131;
if ( ! V_130 ) {
bool V_133 = false ;
V_2 = F_3 ( V_5 ) ;
if ( F_127 ( V_2 ) ) {
F_128 ( ! F_2 ( V_134 , & V_2 -> V_4 ) ,
L_5 , V_2 -> V_10 ) ;
if ( ! F_109 ( & V_2 -> V_22 ) )
V_133 = true ;
}
F_21 ( & V_5 -> V_58 ) ;
F_19 ( & V_2 -> V_22 . V_31 ) ;
V_5 -> V_36 = V_37 ;
F_26 ( & V_5 -> V_15 , & V_2 -> V_22 . V_33 ) ;
F_21 ( & V_2 -> V_22 . V_31 ) ;
if ( V_133 )
F_129 ( V_2 ) ;
return;
}
}
V_131:
F_21 ( & V_5 -> V_58 ) ;
}
static void F_130 ( struct V_6 * V_7 )
{
struct V_5 * V_5 , * V_135 = NULL ;
F_60 ( ! F_131 ( & V_7 -> V_136 ) ) ;
F_19 ( & V_137 ) ;
F_132 (inode, &sb->s_inodes, i_sb_list) {
struct V_72 * V_73 = V_5 -> V_11 ;
F_19 ( & V_5 -> V_58 ) ;
if ( ( V_5 -> V_39 & ( V_65 | V_81 | V_96 ) ) ||
( V_73 -> V_138 == 0 ) ) {
F_21 ( & V_5 -> V_58 ) ;
continue;
}
F_133 ( V_5 ) ;
F_21 ( & V_5 -> V_58 ) ;
F_21 ( & V_137 ) ;
F_134 ( V_135 ) ;
V_135 = V_5 ;
F_63 ( V_73 ) ;
F_135 () ;
F_19 ( & V_137 ) ;
}
F_21 ( & V_137 ) ;
F_134 ( V_135 ) ;
}
void F_136 ( struct V_6 * V_7 ,
unsigned long V_139 ,
enum V_26 V_27 )
{
F_137 ( V_112 ) ;
struct V_16 V_17 = {
. V_7 = V_7 ,
. V_29 = V_30 ,
. V_68 = 1 ,
. V_112 = & V_112 ,
. V_24 = V_139 ,
. V_27 = V_27 ,
} ;
if ( V_7 -> V_12 == & V_140 )
return;
F_60 ( ! F_131 ( & V_7 -> V_136 ) ) ;
F_6 ( V_7 -> V_12 , & V_17 ) ;
F_138 ( & V_112 ) ;
}
void F_139 ( struct V_6 * V_7 , enum V_26 V_27 )
{
return F_136 ( V_7 , F_91 () , V_27 ) ;
}
int F_140 ( struct V_6 * V_7 ,
unsigned long V_139 ,
enum V_26 V_27 )
{
if ( F_1 ( V_7 -> V_12 ) )
return 1 ;
if ( ! F_141 ( & V_7 -> V_136 ) )
return 0 ;
F_136 ( V_7 , V_139 , V_27 ) ;
F_142 ( & V_7 -> V_136 ) ;
return 1 ;
}
int F_143 ( struct V_6 * V_7 , enum V_26 V_27 )
{
return F_140 ( V_7 , F_91 () , V_27 ) ;
}
void F_144 ( struct V_6 * V_7 )
{
F_137 ( V_112 ) ;
struct V_16 V_17 = {
. V_7 = V_7 ,
. V_29 = V_67 ,
. V_24 = V_83 ,
. V_25 = 0 ,
. V_112 = & V_112 ,
. V_27 = V_141 ,
. V_75 = 1 ,
} ;
if ( V_7 -> V_12 == & V_140 )
return;
F_60 ( ! F_131 ( & V_7 -> V_136 ) ) ;
F_6 ( V_7 -> V_12 , & V_17 ) ;
F_138 ( & V_112 ) ;
F_130 ( V_7 ) ;
}
int F_145 ( struct V_5 * V_5 , int V_142 )
{
struct V_32 * V_22 = & F_3 ( V_5 ) -> V_22 ;
struct V_55 V_56 = {
. V_71 = V_83 ,
. V_29 = V_142 ? V_67 : V_30 ,
. V_90 = 0 ,
. V_91 = V_92 ,
} ;
if ( ! F_146 ( V_5 -> V_11 ) )
V_56 . V_71 = 0 ;
F_147 () ;
return F_65 ( V_5 , V_22 , & V_56 ) ;
}
int F_148 ( struct V_5 * V_5 , struct V_55 * V_56 )
{
return F_65 ( V_5 , & F_3 ( V_5 ) -> V_22 , V_56 ) ;
}
int F_149 ( struct V_5 * V_5 , int V_63 )
{
struct V_55 V_56 = {
. V_29 = V_63 ? V_67 : V_30 ,
. V_71 = 0 ,
} ;
return F_148 ( V_5 , & V_56 ) ;
}
