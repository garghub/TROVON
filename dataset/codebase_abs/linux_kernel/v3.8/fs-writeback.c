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
static void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 . V_17 ) {
F_7 ( V_2 -> V_16 . V_17 ) ;
} else {
F_7 ( V_18 . V_16 . V_17 ) ;
}
}
static void F_8 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
F_9 ( V_2 , V_20 ) ;
F_10 ( & V_2 -> V_21 ) ;
F_11 ( & V_20 -> V_22 , & V_2 -> V_23 ) ;
if ( ! V_2 -> V_16 . V_17 )
F_12 ( V_2 , V_20 ) ;
F_6 ( V_2 ) ;
F_13 ( & V_2 -> V_21 ) ;
}
static void
F_14 ( struct V_1 * V_2 , long V_24 ,
bool V_25 , enum V_26 V_27 )
{
struct V_19 * V_20 ;
V_20 = F_15 ( sizeof( * V_20 ) , V_28 ) ;
if ( ! V_20 ) {
if ( V_2 -> V_16 . V_17 ) {
F_16 ( V_2 ) ;
F_7 ( V_2 -> V_16 . V_17 ) ;
}
return;
}
V_20 -> V_29 = V_30 ;
V_20 -> V_24 = V_24 ;
V_20 -> V_25 = V_25 ;
V_20 -> V_27 = V_27 ;
F_8 ( V_2 , V_20 ) ;
}
void F_17 ( struct V_1 * V_2 , long V_24 ,
enum V_26 V_27 )
{
F_14 ( V_2 , V_24 , true , V_27 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_10 ( & V_2 -> V_21 ) ;
F_6 ( V_2 ) ;
F_13 ( & V_2 -> V_21 ) ;
}
void F_20 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_3 ( V_5 ) ;
F_21 ( & V_2 -> V_16 . V_31 ) ;
F_22 ( & V_5 -> V_15 ) ;
F_23 ( & V_2 -> V_16 . V_31 ) ;
}
static void F_24 ( struct V_5 * V_5 , struct V_32 * V_16 )
{
F_25 ( & V_16 -> V_31 ) ;
if ( ! F_26 ( & V_16 -> V_33 ) ) {
struct V_5 * V_34 ;
V_34 = F_4 ( V_16 -> V_33 . V_35 ) ;
if ( F_27 ( V_5 -> V_36 , V_34 -> V_36 ) )
V_5 -> V_36 = V_37 ;
}
F_28 ( & V_5 -> V_15 , & V_16 -> V_33 ) ;
}
static void F_29 ( struct V_5 * V_5 , struct V_32 * V_16 )
{
F_25 ( & V_16 -> V_31 ) ;
F_28 ( & V_5 -> V_15 , & V_16 -> V_38 ) ;
}
static void F_30 ( struct V_5 * V_5 )
{
V_5 -> V_39 &= ~ V_40 ;
F_31 ( V_5 ) ;
F_32 () ;
F_33 ( & V_5 -> V_39 , V_41 ) ;
}
static bool F_34 ( struct V_5 * V_5 , unsigned long V_42 )
{
bool V_43 = F_35 ( V_5 -> V_36 , V_42 ) ;
#ifndef F_36
V_43 = V_43 && F_37 ( V_5 -> V_36 , V_37 ) ;
#endif
return V_43 ;
}
static int F_38 ( struct V_13 * V_44 ,
struct V_13 * V_45 ,
struct V_19 * V_20 )
{
F_39 ( V_46 ) ;
struct V_13 * V_47 , * V_48 ;
struct V_6 * V_7 = NULL ;
struct V_5 * V_5 ;
int V_49 = 0 ;
int V_50 = 0 ;
while ( ! F_26 ( V_44 ) ) {
V_5 = F_4 ( V_44 -> V_51 ) ;
if ( V_20 -> V_52 &&
F_34 ( V_5 , * V_20 -> V_52 ) )
break;
if ( V_7 && V_7 != V_5 -> V_8 )
V_49 = 1 ;
V_7 = V_5 -> V_8 ;
F_28 ( & V_5 -> V_15 , & V_46 ) ;
V_50 ++ ;
}
if ( ! V_49 ) {
F_40 ( & V_46 , V_45 ) ;
goto V_53;
}
while ( ! F_26 ( & V_46 ) ) {
V_7 = F_4 ( V_46 . V_51 ) -> V_8 ;
F_41 (pos, node, &tmp) {
V_5 = F_4 ( V_47 ) ;
if ( V_5 -> V_8 == V_7 )
F_28 ( & V_5 -> V_15 , V_45 ) ;
}
}
V_53:
return V_50 ;
}
static void F_42 ( struct V_32 * V_16 , struct V_19 * V_20 )
{
int V_50 ;
F_25 ( & V_16 -> V_31 ) ;
F_43 ( & V_16 -> V_38 , & V_16 -> V_54 ) ;
V_50 = F_38 ( & V_16 -> V_33 , & V_16 -> V_54 , V_20 ) ;
F_44 ( V_16 , V_20 , V_50 ) ;
}
static int F_45 ( struct V_5 * V_5 , struct V_55 * V_56 )
{
if ( V_5 -> V_8 -> V_57 -> F_45 && ! F_46 ( V_5 ) )
return V_5 -> V_8 -> V_57 -> F_45 ( V_5 , V_56 ) ;
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
F_23 ( & V_5 -> V_58 ) ;
F_50 ( V_60 , & V_59 , V_61 , V_62 ) ;
F_21 ( & V_5 -> V_58 ) ;
}
}
void F_51 ( struct V_5 * V_5 )
{
F_21 ( & V_5 -> V_58 ) ;
F_47 ( V_5 ) ;
F_23 ( & V_5 -> V_58 ) ;
}
static void F_52 ( struct V_5 * V_5 )
__releases( V_5 -> V_58 )
{
F_53 ( V_63 ) ;
T_1 * V_60 = F_49 ( & V_5 -> V_39 , V_41 ) ;
int V_64 ;
F_54 ( V_60 , & V_63 , V_62 ) ;
V_64 = V_5 -> V_39 & V_40 ;
F_23 ( & V_5 -> V_58 ) ;
if ( V_64 )
F_55 () ;
F_56 ( V_60 , & V_63 ) ;
}
static void F_57 ( struct V_5 * V_5 , struct V_32 * V_16 ,
struct V_55 * V_56 )
{
if ( V_5 -> V_39 & V_65 )
return;
if ( ( V_5 -> V_39 & V_66 ) &&
( V_56 -> V_29 == V_67 || V_56 -> V_68 ) )
V_5 -> V_36 = V_37 ;
if ( V_56 -> V_69 ) {
F_24 ( V_5 , V_16 ) ;
return;
}
if ( F_58 ( V_5 -> V_11 , V_70 ) ) {
if ( V_56 -> V_71 <= 0 ) {
F_29 ( V_5 , V_16 ) ;
} else {
F_24 ( V_5 , V_16 ) ;
}
} else if ( V_5 -> V_39 & V_66 ) {
F_24 ( V_5 , V_16 ) ;
} else {
F_22 ( & V_5 -> V_15 ) ;
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
V_43 = F_61 ( V_73 , V_56 ) ;
if ( V_56 -> V_29 == V_67 ) {
int V_75 = F_62 ( V_73 ) ;
if ( V_43 == 0 )
V_43 = V_75 ;
}
F_21 ( & V_5 -> V_58 ) ;
if ( ! F_58 ( V_73 , V_70 ) )
V_5 -> V_39 &= ~ V_76 ;
V_74 = V_5 -> V_39 & V_66 ;
V_5 -> V_39 &= ~ ( V_77 | V_78 ) ;
F_23 ( & V_5 -> V_58 ) ;
if ( V_74 & ( V_77 | V_78 ) ) {
int V_75 = F_45 ( V_5 , V_56 ) ;
if ( V_43 == 0 )
V_43 = V_75 ;
}
F_63 ( V_5 , V_56 , V_71 ) ;
return V_43 ;
}
static int
F_64 ( struct V_5 * V_5 , struct V_32 * V_16 ,
struct V_55 * V_56 )
{
int V_43 = 0 ;
F_21 ( & V_5 -> V_58 ) ;
if ( ! F_65 ( & V_5 -> V_79 ) )
F_60 ( ! ( V_5 -> V_39 & ( V_80 | V_65 ) ) ) ;
else
F_60 ( V_5 -> V_39 & V_80 ) ;
if ( V_5 -> V_39 & V_40 ) {
if ( V_56 -> V_29 != V_67 )
goto V_53;
F_47 ( V_5 ) ;
}
F_60 ( V_5 -> V_39 & V_40 ) ;
if ( ! ( V_5 -> V_39 & V_66 ) )
goto V_53;
V_5 -> V_39 |= V_40 ;
F_23 ( & V_5 -> V_58 ) ;
V_43 = F_59 ( V_5 , V_56 ) ;
F_21 ( & V_16 -> V_31 ) ;
F_21 ( & V_5 -> V_58 ) ;
if ( ! ( V_5 -> V_39 & V_66 ) )
F_22 ( & V_5 -> V_15 ) ;
F_23 ( & V_16 -> V_31 ) ;
F_30 ( V_5 ) ;
V_53:
F_23 ( & V_5 -> V_58 ) ;
return V_43 ;
}
static long F_66 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
long V_81 ;
if ( V_20 -> V_29 == V_67 || V_20 -> V_68 )
V_81 = V_82 ;
else {
V_81 = F_67 ( V_2 -> V_83 / 2 ,
V_84 / V_85 ) ;
V_81 = F_67 ( V_81 , V_20 -> V_24 ) ;
V_81 = F_68 ( V_81 + V_86 ,
V_86 ) ;
}
return V_81 ;
}
static long F_69 ( struct V_6 * V_7 ,
struct V_32 * V_16 ,
struct V_19 * V_20 )
{
struct V_55 V_56 = {
. V_29 = V_20 -> V_29 ,
. V_68 = V_20 -> V_68 ,
. V_87 = V_20 -> V_87 ,
. V_88 = V_20 -> V_88 ,
. V_25 = V_20 -> V_25 ,
. V_89 = 0 ,
. V_90 = V_91 ,
} ;
unsigned long V_92 = V_37 ;
long V_93 ;
long V_94 = 0 ;
while ( ! F_26 ( & V_16 -> V_54 ) ) {
struct V_5 * V_5 = F_4 ( V_16 -> V_54 . V_51 ) ;
if ( V_5 -> V_8 != V_7 ) {
if ( V_20 -> V_7 ) {
F_24 ( V_5 , V_16 ) ;
continue;
}
break;
}
F_21 ( & V_5 -> V_58 ) ;
if ( V_5 -> V_39 & ( V_95 | V_65 | V_80 ) ) {
F_23 ( & V_5 -> V_58 ) ;
F_24 ( V_5 , V_16 ) ;
continue;
}
if ( ( V_5 -> V_39 & V_40 ) && V_56 . V_29 != V_67 ) {
F_23 ( & V_5 -> V_58 ) ;
F_29 ( V_5 , V_16 ) ;
F_70 ( V_5 ) ;
continue;
}
F_23 ( & V_16 -> V_31 ) ;
if ( V_5 -> V_39 & V_40 ) {
F_52 ( V_5 ) ;
F_21 ( & V_16 -> V_31 ) ;
continue;
}
V_5 -> V_39 |= V_40 ;
F_23 ( & V_5 -> V_58 ) ;
V_93 = F_66 ( V_16 -> V_2 , V_20 ) ;
V_56 . V_71 = V_93 ;
V_56 . V_69 = 0 ;
F_59 ( V_5 , & V_56 ) ;
V_20 -> V_24 -= V_93 - V_56 . V_71 ;
V_94 += V_93 - V_56 . V_71 ;
F_21 ( & V_16 -> V_31 ) ;
F_21 ( & V_5 -> V_58 ) ;
if ( ! ( V_5 -> V_39 & V_66 ) )
V_94 ++ ;
F_57 ( V_5 , V_16 , & V_56 ) ;
F_30 ( V_5 ) ;
F_23 ( & V_5 -> V_58 ) ;
F_71 ( & V_16 -> V_31 ) ;
if ( V_94 ) {
if ( F_72 ( V_92 + V_96 / 10UL ) )
break;
if ( V_20 -> V_24 <= 0 )
break;
}
}
return V_94 ;
}
static long F_73 ( struct V_32 * V_16 ,
struct V_19 * V_20 )
{
unsigned long V_92 = V_37 ;
long V_94 = 0 ;
while ( ! F_26 ( & V_16 -> V_54 ) ) {
struct V_5 * V_5 = F_4 ( V_16 -> V_54 . V_51 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! F_74 ( V_7 ) ) {
F_24 ( V_5 , V_16 ) ;
continue;
}
V_94 += F_69 ( V_7 , V_16 , V_20 ) ;
F_75 ( V_7 ) ;
if ( V_94 ) {
if ( F_72 ( V_92 + V_96 / 10UL ) )
break;
if ( V_20 -> V_24 <= 0 )
break;
}
}
return V_94 ;
}
long F_76 ( struct V_32 * V_16 , long V_24 ,
enum V_26 V_27 )
{
struct V_19 V_20 = {
. V_24 = V_24 ,
. V_29 = V_30 ,
. V_25 = 1 ,
. V_27 = V_27 ,
} ;
F_21 ( & V_16 -> V_31 ) ;
if ( F_26 ( & V_16 -> V_54 ) )
F_42 ( V_16 , & V_20 ) ;
F_73 ( V_16 , & V_20 ) ;
F_23 ( & V_16 -> V_31 ) ;
return V_24 - V_20 . V_24 ;
}
static bool F_77 ( struct V_1 * V_2 )
{
unsigned long V_97 , V_98 ;
F_78 ( & V_97 , & V_98 ) ;
if ( F_79 ( V_99 ) +
F_79 ( V_100 ) > V_97 )
return true ;
if ( F_80 ( V_2 , V_101 ) >
F_81 ( V_2 , V_97 ) )
return true ;
return false ;
}
static void F_82 ( struct V_32 * V_16 ,
unsigned long V_92 )
{
F_83 ( V_16 -> V_2 , 0 , 0 , 0 , 0 , 0 , V_92 ) ;
}
static long F_84 ( struct V_32 * V_16 ,
struct V_19 * V_20 )
{
unsigned long V_102 = V_37 ;
long V_24 = V_20 -> V_24 ;
unsigned long V_103 ;
struct V_5 * V_5 ;
long V_104 ;
V_103 = V_37 ;
V_20 -> V_52 = & V_103 ;
F_21 ( & V_16 -> V_31 ) ;
for (; ; ) {
if ( V_20 -> V_24 <= 0 )
break;
if ( ( V_20 -> V_88 || V_20 -> V_87 ) &&
! F_26 ( & V_16 -> V_2 -> V_23 ) )
break;
if ( V_20 -> V_88 && ! F_77 ( V_16 -> V_2 ) )
break;
if ( V_20 -> V_87 ) {
V_103 = V_37 -
F_85 ( V_105 * 10 ) ;
} else if ( V_20 -> V_88 )
V_103 = V_37 ;
F_86 ( V_16 -> V_2 , V_20 ) ;
if ( F_26 ( & V_16 -> V_54 ) )
F_42 ( V_16 , V_20 ) ;
if ( V_20 -> V_7 )
V_104 = F_69 ( V_20 -> V_7 , V_16 , V_20 ) ;
else
V_104 = F_73 ( V_16 , V_20 ) ;
F_87 ( V_16 -> V_2 , V_20 ) ;
F_82 ( V_16 , V_102 ) ;
if ( V_104 )
continue;
if ( F_26 ( & V_16 -> V_38 ) )
break;
if ( ! F_26 ( & V_16 -> V_38 ) ) {
F_88 ( V_16 -> V_2 , V_20 ) ;
V_5 = F_4 ( V_16 -> V_38 . V_51 ) ;
F_21 ( & V_5 -> V_58 ) ;
F_23 ( & V_16 -> V_31 ) ;
F_52 ( V_5 ) ;
F_21 ( & V_16 -> V_31 ) ;
}
}
F_23 ( & V_16 -> V_31 ) ;
return V_24 - V_20 -> V_24 ;
}
static struct V_19 *
F_89 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = NULL ;
F_10 ( & V_2 -> V_21 ) ;
if ( ! F_26 ( & V_2 -> V_23 ) ) {
V_20 = F_5 ( V_2 -> V_23 . V_35 ,
struct V_19 , V_22 ) ;
F_22 ( & V_20 -> V_22 ) ;
}
F_13 ( & V_2 -> V_21 ) ;
return V_20 ;
}
static unsigned long F_90 ( void )
{
return F_79 ( V_99 ) +
F_79 ( V_100 ) +
F_91 () ;
}
static long F_92 ( struct V_32 * V_16 )
{
if ( F_77 ( V_16 -> V_2 ) ) {
struct V_19 V_20 = {
. V_24 = V_82 ,
. V_29 = V_30 ,
. V_88 = 1 ,
. V_25 = 1 ,
. V_27 = V_106 ,
} ;
return F_84 ( V_16 , & V_20 ) ;
}
return 0 ;
}
static long F_93 ( struct V_32 * V_16 )
{
unsigned long V_107 ;
long V_24 ;
if ( ! V_108 )
return 0 ;
V_107 = V_16 -> V_109 +
F_85 ( V_108 * 10 ) ;
if ( F_27 ( V_37 , V_107 ) )
return 0 ;
V_16 -> V_109 = V_37 ;
V_24 = F_90 () ;
if ( V_24 ) {
struct V_19 V_20 = {
. V_24 = V_24 ,
. V_29 = V_30 ,
. V_87 = 1 ,
. V_25 = 1 ,
. V_27 = V_110 ,
} ;
return F_84 ( V_16 , & V_20 ) ;
}
return 0 ;
}
long F_94 ( struct V_32 * V_16 , int V_111 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_19 * V_20 ;
long V_94 = 0 ;
F_95 ( V_3 , & V_16 -> V_2 -> V_4 ) ;
while ( ( V_20 = F_89 ( V_2 ) ) != NULL ) {
if ( V_111 )
V_20 -> V_29 = V_67 ;
F_96 ( V_2 , V_20 ) ;
V_94 += F_84 ( V_16 , V_20 ) ;
if ( V_20 -> V_112 )
F_97 ( V_20 -> V_112 ) ;
else
F_98 ( V_20 ) ;
}
V_94 += F_93 ( V_16 ) ;
V_94 += F_92 ( V_16 ) ;
F_99 ( V_3 , & V_16 -> V_2 -> V_4 ) ;
return V_94 ;
}
int F_100 ( void * V_113 )
{
struct V_32 * V_16 = V_113 ;
struct V_1 * V_2 = V_16 -> V_2 ;
long V_114 ;
V_115 -> V_116 |= V_117 ;
F_101 () ;
V_16 -> V_118 = V_37 ;
F_102 ( V_115 , 0 ) ;
F_103 ( V_2 ) ;
while ( ! F_104 ( NULL ) ) {
F_105 ( & V_16 -> V_119 ) ;
V_114 = F_94 ( V_16 , 0 ) ;
F_106 ( V_114 ) ;
if ( V_114 )
V_16 -> V_118 = V_37 ;
F_107 ( V_120 ) ;
if ( ! F_26 ( & V_2 -> V_23 ) || F_108 () ) {
F_109 ( V_121 ) ;
continue;
}
if ( F_110 ( V_16 ) && V_108 )
F_111 ( F_85 ( V_108 * 10 ) ) ;
else {
F_55 () ;
}
}
if ( ! F_26 ( & V_2 -> V_23 ) )
F_94 ( V_16 , 1 ) ;
F_112 ( V_2 ) ;
return 0 ;
}
void F_113 ( long V_24 , enum V_26 V_27 )
{
struct V_1 * V_2 ;
if ( ! V_24 ) {
V_24 = F_79 ( V_99 ) +
F_79 ( V_100 ) ;
}
F_114 () ;
F_115 (bdi, &bdi_list, bdi_list) {
if ( ! F_116 ( V_2 ) )
continue;
F_14 ( V_2 , V_24 , false , V_27 ) ;
}
F_117 () ;
}
static T_2 void F_118 ( struct V_5 * V_5 )
{
if ( V_5 -> V_122 || strcmp ( V_5 -> V_8 -> V_123 , L_1 ) ) {
struct V_124 * V_124 ;
const char * V_10 = L_2 ;
V_124 = F_119 ( V_5 ) ;
if ( V_124 ) {
F_21 ( & V_124 -> V_125 ) ;
V_10 = ( const char * ) V_124 -> V_126 . V_10 ;
}
F_120 ( V_127
L_3 ,
V_115 -> V_128 , F_121 ( V_115 ) , V_5 -> V_122 ,
V_10 , V_5 -> V_8 -> V_123 ) ;
if ( V_124 ) {
F_23 ( & V_124 -> V_125 ) ;
F_122 ( V_124 ) ;
}
}
}
void F_123 ( struct V_5 * V_5 , int V_116 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_2 = NULL ;
if ( V_116 & ( V_77 | V_78 ) ) {
if ( V_7 -> V_57 -> V_129 )
V_7 -> V_57 -> V_129 ( V_5 , V_116 ) ;
}
F_32 () ;
if ( ( V_5 -> V_39 & V_116 ) == V_116 )
return;
if ( F_124 ( V_130 ) )
F_118 ( V_5 ) ;
F_21 ( & V_5 -> V_58 ) ;
if ( ( V_5 -> V_39 & V_116 ) != V_116 ) {
const int V_131 = V_5 -> V_39 & V_66 ;
V_5 -> V_39 |= V_116 ;
if ( V_5 -> V_39 & V_40 )
goto V_132;
if ( ! F_125 ( V_5 -> V_133 ) ) {
if ( F_126 ( V_5 ) )
goto V_132;
}
if ( V_5 -> V_39 & V_65 )
goto V_132;
if ( ! V_131 ) {
bool V_134 = false ;
V_2 = F_3 ( V_5 ) ;
if ( F_127 ( V_2 ) ) {
F_128 ( ! F_2 ( V_135 , & V_2 -> V_4 ) ,
L_4 , V_2 -> V_10 ) ;
if ( ! F_110 ( & V_2 -> V_16 ) )
V_134 = true ;
}
F_23 ( & V_5 -> V_58 ) ;
F_21 ( & V_2 -> V_16 . V_31 ) ;
V_5 -> V_36 = V_37 ;
F_28 ( & V_5 -> V_15 , & V_2 -> V_16 . V_33 ) ;
F_23 ( & V_2 -> V_16 . V_31 ) ;
if ( V_134 )
F_129 ( V_2 ) ;
return;
}
}
V_132:
F_23 ( & V_5 -> V_58 ) ;
}
static void F_130 ( struct V_6 * V_7 )
{
struct V_5 * V_5 , * V_136 = NULL ;
F_60 ( ! F_131 ( & V_7 -> V_137 ) ) ;
F_21 ( & V_138 ) ;
F_132 (inode, &sb->s_inodes, i_sb_list) {
struct V_72 * V_73 = V_5 -> V_11 ;
F_21 ( & V_5 -> V_58 ) ;
if ( ( V_5 -> V_39 & ( V_65 | V_80 | V_95 ) ) ||
( V_73 -> V_139 == 0 ) ) {
F_23 ( & V_5 -> V_58 ) ;
continue;
}
F_133 ( V_5 ) ;
F_23 ( & V_5 -> V_58 ) ;
F_23 ( & V_138 ) ;
F_134 ( V_136 ) ;
V_136 = V_5 ;
F_62 ( V_73 ) ;
F_135 () ;
F_21 ( & V_138 ) ;
}
F_23 ( & V_138 ) ;
F_134 ( V_136 ) ;
}
void F_136 ( struct V_6 * V_7 ,
unsigned long V_140 ,
enum V_26 V_27 )
{
F_137 ( V_112 ) ;
struct V_19 V_20 = {
. V_7 = V_7 ,
. V_29 = V_30 ,
. V_68 = 1 ,
. V_112 = & V_112 ,
. V_24 = V_140 ,
. V_27 = V_27 ,
} ;
if ( V_7 -> V_12 == & V_141 )
return;
F_60 ( ! F_131 ( & V_7 -> V_137 ) ) ;
F_8 ( V_7 -> V_12 , & V_20 ) ;
F_138 ( & V_112 ) ;
}
void F_139 ( struct V_6 * V_7 , enum V_26 V_27 )
{
return F_136 ( V_7 , F_90 () , V_27 ) ;
}
int F_140 ( struct V_6 * V_7 , enum V_26 V_27 )
{
if ( ! F_1 ( V_7 -> V_12 ) ) {
F_141 ( & V_7 -> V_137 ) ;
F_139 ( V_7 , V_27 ) ;
F_142 ( & V_7 -> V_137 ) ;
return 1 ;
} else
return 0 ;
}
int F_143 ( struct V_6 * V_7 ,
unsigned long V_140 ,
enum V_26 V_27 )
{
if ( ! F_1 ( V_7 -> V_12 ) ) {
F_141 ( & V_7 -> V_137 ) ;
F_136 ( V_7 , V_140 , V_27 ) ;
F_142 ( & V_7 -> V_137 ) ;
return 1 ;
} else
return 0 ;
}
void F_144 ( struct V_6 * V_7 )
{
F_137 ( V_112 ) ;
struct V_19 V_20 = {
. V_7 = V_7 ,
. V_29 = V_67 ,
. V_24 = V_82 ,
. V_25 = 0 ,
. V_112 = & V_112 ,
. V_27 = V_142 ,
} ;
if ( V_7 -> V_12 == & V_141 )
return;
F_60 ( ! F_131 ( & V_7 -> V_137 ) ) ;
F_8 ( V_7 -> V_12 , & V_20 ) ;
F_138 ( & V_112 ) ;
F_130 ( V_7 ) ;
}
int F_145 ( struct V_5 * V_5 , int V_143 )
{
struct V_32 * V_16 = & F_3 ( V_5 ) -> V_16 ;
struct V_55 V_56 = {
. V_71 = V_82 ,
. V_29 = V_143 ? V_67 : V_30 ,
. V_89 = 0 ,
. V_90 = V_91 ,
} ;
if ( ! F_146 ( V_5 -> V_11 ) )
V_56 . V_71 = 0 ;
F_147 () ;
return F_64 ( V_5 , V_16 , & V_56 ) ;
}
int F_148 ( struct V_5 * V_5 , struct V_55 * V_56 )
{
return F_64 ( V_5 , & F_3 ( V_5 ) -> V_16 , V_56 ) ;
}
int F_149 ( struct V_5 * V_5 , int V_63 )
{
struct V_55 V_56 = {
. V_29 = V_63 ? V_67 : V_30 ,
. V_71 = 0 ,
} ;
return F_148 ( V_5 , & V_56 ) ;
}
