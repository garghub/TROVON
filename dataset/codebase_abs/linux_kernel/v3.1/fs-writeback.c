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
bool V_25 )
{
struct V_19 * V_20 ;
V_20 = F_15 ( sizeof( * V_20 ) , V_26 ) ;
if ( ! V_20 ) {
if ( V_2 -> V_16 . V_17 ) {
F_16 ( V_2 ) ;
F_7 ( V_2 -> V_16 . V_17 ) ;
}
return;
}
V_20 -> V_27 = V_28 ;
V_20 -> V_24 = V_24 ;
V_20 -> V_25 = V_25 ;
F_8 ( V_2 , V_20 ) ;
}
void F_17 ( struct V_1 * V_2 , long V_24 )
{
F_14 ( V_2 , V_24 , true ) ;
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
F_21 ( & V_2 -> V_16 . V_29 ) ;
F_22 ( & V_5 -> V_15 ) ;
F_23 ( & V_2 -> V_16 . V_29 ) ;
}
static void F_24 ( struct V_5 * V_5 , struct V_30 * V_16 )
{
F_25 ( & V_16 -> V_29 ) ;
if ( ! F_26 ( & V_16 -> V_31 ) ) {
struct V_5 * V_32 ;
V_32 = F_4 ( V_16 -> V_31 . V_33 ) ;
if ( F_27 ( V_5 -> V_34 , V_32 -> V_34 ) )
V_5 -> V_34 = V_35 ;
}
F_28 ( & V_5 -> V_15 , & V_16 -> V_31 ) ;
}
static void F_29 ( struct V_5 * V_5 , struct V_30 * V_16 )
{
F_25 ( & V_16 -> V_29 ) ;
F_28 ( & V_5 -> V_15 , & V_16 -> V_36 ) ;
}
static void F_30 ( struct V_5 * V_5 )
{
F_31 () ;
F_32 ( & V_5 -> V_37 , V_38 ) ;
}
static bool F_33 ( struct V_5 * V_5 , unsigned long V_39 )
{
bool V_40 = F_34 ( V_5 -> V_34 , V_39 ) ;
#ifndef F_35
V_40 = V_40 && F_36 ( V_5 -> V_34 , V_35 ) ;
#endif
return V_40 ;
}
static int F_37 ( struct V_13 * V_41 ,
struct V_13 * V_42 ,
unsigned long * V_43 )
{
F_38 ( V_44 ) ;
struct V_13 * V_45 , * V_46 ;
struct V_6 * V_7 = NULL ;
struct V_5 * V_5 ;
int V_47 = 0 ;
int V_48 = 0 ;
while ( ! F_26 ( V_41 ) ) {
V_5 = F_4 ( V_41 -> V_49 ) ;
if ( V_43 &&
F_33 ( V_5 , * V_43 ) )
break;
if ( V_7 && V_7 != V_5 -> V_8 )
V_47 = 1 ;
V_7 = V_5 -> V_8 ;
F_28 ( & V_5 -> V_15 , & V_44 ) ;
V_48 ++ ;
}
if ( ! V_47 ) {
F_39 ( & V_44 , V_42 ) ;
goto V_50;
}
while ( ! F_26 ( & V_44 ) ) {
V_7 = F_4 ( V_44 . V_49 ) -> V_8 ;
F_40 (pos, node, &tmp) {
V_5 = F_4 ( V_45 ) ;
if ( V_5 -> V_8 == V_7 )
F_28 ( & V_5 -> V_15 , V_42 ) ;
}
}
V_50:
return V_48 ;
}
static void F_41 ( struct V_30 * V_16 , unsigned long * V_43 )
{
int V_48 ;
F_25 ( & V_16 -> V_29 ) ;
F_42 ( & V_16 -> V_36 , & V_16 -> V_51 ) ;
V_48 = F_37 ( & V_16 -> V_31 , & V_16 -> V_51 , V_43 ) ;
F_43 ( V_16 , V_43 , V_48 ) ;
}
static int F_44 ( struct V_5 * V_5 , struct V_52 * V_53 )
{
if ( V_5 -> V_8 -> V_54 -> F_44 && ! F_45 ( V_5 ) )
return V_5 -> V_8 -> V_54 -> F_44 ( V_5 , V_53 ) ;
return 0 ;
}
static void F_46 ( struct V_5 * V_5 ,
struct V_30 * V_16 )
{
F_47 ( V_55 , & V_5 -> V_37 , V_38 ) ;
T_1 * V_56 ;
V_56 = F_48 ( & V_5 -> V_37 , V_38 ) ;
while ( V_5 -> V_37 & V_57 ) {
F_23 ( & V_5 -> V_58 ) ;
F_23 ( & V_16 -> V_29 ) ;
F_49 ( V_56 , & V_55 , V_59 , V_60 ) ;
F_21 ( & V_16 -> V_29 ) ;
F_21 ( & V_5 -> V_58 ) ;
}
}
static int
F_50 ( struct V_5 * V_5 , struct V_30 * V_16 ,
struct V_52 * V_53 )
{
struct V_61 * V_62 = V_5 -> V_11 ;
long V_63 = V_53 -> V_63 ;
unsigned V_64 ;
int V_40 ;
F_25 ( & V_16 -> V_29 ) ;
F_25 ( & V_5 -> V_58 ) ;
if ( ! F_51 ( & V_5 -> V_65 ) )
F_52 ( ! ( V_5 -> V_37 & ( V_66 | V_67 ) ) ) ;
else
F_52 ( V_5 -> V_37 & V_66 ) ;
if ( V_5 -> V_37 & V_57 ) {
if ( V_53 -> V_27 != V_68 ) {
F_29 ( V_5 , V_16 ) ;
F_53 ( V_5 , V_53 ,
V_63 ) ;
return 0 ;
}
F_46 ( V_5 , V_16 ) ;
}
F_54 ( V_5 -> V_37 & V_57 ) ;
V_5 -> V_37 |= V_57 ;
V_5 -> V_37 &= ~ V_69 ;
F_23 ( & V_5 -> V_58 ) ;
F_23 ( & V_16 -> V_29 ) ;
V_40 = F_55 ( V_62 , V_53 ) ;
if ( V_53 -> V_27 == V_68 ) {
int V_70 = F_56 ( V_62 ) ;
if ( V_40 == 0 )
V_40 = V_70 ;
}
F_21 ( & V_5 -> V_58 ) ;
V_64 = V_5 -> V_37 & V_71 ;
V_5 -> V_37 &= ~ ( V_72 | V_73 ) ;
F_23 ( & V_5 -> V_58 ) ;
if ( V_64 & ( V_72 | V_73 ) ) {
int V_70 = F_44 ( V_5 , V_53 ) ;
if ( V_40 == 0 )
V_40 = V_70 ;
}
F_21 ( & V_16 -> V_29 ) ;
F_21 ( & V_5 -> V_58 ) ;
V_5 -> V_37 &= ~ V_57 ;
if ( ! ( V_5 -> V_37 & V_67 ) ) {
if ( ( V_5 -> V_37 & V_71 ) &&
( V_53 -> V_27 == V_68 || V_53 -> V_74 ) )
V_5 -> V_34 = V_35 ;
if ( F_57 ( V_62 , V_75 ) ) {
V_5 -> V_37 |= V_69 ;
if ( V_53 -> V_63 <= 0 ) {
F_29 ( V_5 , V_16 ) ;
} else {
F_24 ( V_5 , V_16 ) ;
}
} else if ( V_5 -> V_37 & V_71 ) {
F_24 ( V_5 , V_16 ) ;
} else {
F_22 ( & V_5 -> V_15 ) ;
}
}
F_30 ( V_5 ) ;
F_58 ( V_5 , V_53 , V_63 ) ;
return V_40 ;
}
static long F_59 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
long V_76 ;
if ( V_20 -> V_27 == V_68 || V_20 -> V_74 )
V_76 = V_77 ;
else {
V_76 = F_60 ( V_2 -> V_78 / 2 ,
V_79 / V_80 ) ;
V_76 = F_60 ( V_76 , V_20 -> V_24 ) ;
V_76 = F_61 ( V_76 + V_81 ,
V_81 ) ;
}
return V_76 ;
}
static long F_62 ( struct V_6 * V_7 ,
struct V_30 * V_16 ,
struct V_19 * V_20 )
{
struct V_52 V_53 = {
. V_27 = V_20 -> V_27 ,
. V_74 = V_20 -> V_74 ,
. V_82 = V_20 -> V_82 ,
. V_83 = V_20 -> V_83 ,
. V_25 = V_20 -> V_25 ,
. V_84 = 0 ,
. V_85 = V_86 ,
} ;
unsigned long V_87 = V_35 ;
long V_88 ;
long V_89 = 0 ;
while ( ! F_26 ( & V_16 -> V_51 ) ) {
struct V_5 * V_5 = F_4 ( V_16 -> V_51 . V_49 ) ;
if ( V_5 -> V_8 != V_7 ) {
if ( V_20 -> V_7 ) {
F_24 ( V_5 , V_16 ) ;
continue;
}
break;
}
F_21 ( & V_5 -> V_58 ) ;
if ( V_5 -> V_37 & ( V_90 | V_67 | V_66 ) ) {
F_23 ( & V_5 -> V_58 ) ;
F_24 ( V_5 , V_16 ) ;
continue;
}
F_63 ( V_5 ) ;
V_88 = F_59 ( V_16 -> V_2 , V_20 ) ;
V_53 . V_63 = V_88 ;
V_53 . V_91 = 0 ;
F_50 ( V_5 , V_16 , & V_53 ) ;
V_20 -> V_24 -= V_88 - V_53 . V_63 ;
V_89 += V_88 - V_53 . V_63 ;
if ( ! ( V_5 -> V_37 & V_71 ) )
V_89 ++ ;
if ( V_53 . V_91 ) {
F_24 ( V_5 , V_16 ) ;
}
F_23 ( & V_5 -> V_58 ) ;
F_23 ( & V_16 -> V_29 ) ;
F_64 ( V_5 ) ;
F_65 () ;
F_21 ( & V_16 -> V_29 ) ;
if ( V_89 ) {
if ( F_66 ( V_87 + V_92 / 10UL ) )
break;
if ( V_20 -> V_24 <= 0 )
break;
}
}
return V_89 ;
}
static long F_67 ( struct V_30 * V_16 ,
struct V_19 * V_20 )
{
unsigned long V_87 = V_35 ;
long V_89 = 0 ;
while ( ! F_26 ( & V_16 -> V_51 ) ) {
struct V_5 * V_5 = F_4 ( V_16 -> V_51 . V_49 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! F_68 ( V_7 ) ) {
F_24 ( V_5 , V_16 ) ;
continue;
}
V_89 += F_62 ( V_7 , V_16 , V_20 ) ;
F_69 ( V_7 ) ;
if ( V_89 ) {
if ( F_66 ( V_87 + V_92 / 10UL ) )
break;
if ( V_20 -> V_24 <= 0 )
break;
}
}
return V_89 ;
}
long F_70 ( struct V_30 * V_16 , long V_24 )
{
struct V_19 V_20 = {
. V_24 = V_24 ,
. V_27 = V_28 ,
. V_25 = 1 ,
} ;
F_21 ( & V_16 -> V_29 ) ;
if ( F_26 ( & V_16 -> V_51 ) )
F_41 ( V_16 , NULL ) ;
F_67 ( V_16 , & V_20 ) ;
F_23 ( & V_16 -> V_29 ) ;
return V_24 - V_20 . V_24 ;
}
static inline bool F_71 ( void )
{
unsigned long V_93 , V_94 ;
F_72 ( & V_93 , & V_94 ) ;
return ( F_73 ( V_95 ) +
F_73 ( V_96 ) > V_93 ) ;
}
static void F_74 ( struct V_30 * V_16 ,
unsigned long V_87 )
{
F_75 ( V_16 -> V_2 , 0 , 0 , 0 , 0 , V_87 ) ;
}
static long F_76 ( struct V_30 * V_16 ,
struct V_19 * V_20 )
{
unsigned long V_97 = V_35 ;
long V_24 = V_20 -> V_24 ;
unsigned long V_98 ;
struct V_5 * V_5 ;
long V_99 ;
V_98 = V_35 ;
V_20 -> V_43 = & V_98 ;
F_21 ( & V_16 -> V_29 ) ;
for (; ; ) {
if ( V_20 -> V_24 <= 0 )
break;
if ( ( V_20 -> V_83 || V_20 -> V_82 ) &&
! F_26 ( & V_16 -> V_2 -> V_23 ) )
break;
if ( V_20 -> V_83 && ! F_71 () )
break;
if ( V_20 -> V_82 ) {
V_98 = V_35 -
F_77 ( V_100 * 10 ) ;
V_20 -> V_43 = & V_98 ;
}
F_78 ( V_16 -> V_2 , V_20 ) ;
if ( F_26 ( & V_16 -> V_51 ) )
F_41 ( V_16 , V_20 -> V_43 ) ;
if ( V_20 -> V_7 )
V_99 = F_62 ( V_20 -> V_7 , V_16 , V_20 ) ;
else
V_99 = F_67 ( V_16 , V_20 ) ;
F_79 ( V_16 -> V_2 , V_20 ) ;
F_74 ( V_16 , V_97 ) ;
if ( V_99 )
continue;
if ( F_26 ( & V_16 -> V_36 ) )
break;
if ( ! F_26 ( & V_16 -> V_36 ) ) {
F_80 ( V_16 -> V_2 , V_20 ) ;
V_5 = F_4 ( V_16 -> V_36 . V_49 ) ;
F_21 ( & V_5 -> V_58 ) ;
F_46 ( V_5 , V_16 ) ;
F_23 ( & V_5 -> V_58 ) ;
}
}
F_23 ( & V_16 -> V_29 ) ;
return V_24 - V_20 -> V_24 ;
}
static struct V_19 *
F_81 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = NULL ;
F_10 ( & V_2 -> V_21 ) ;
if ( ! F_26 ( & V_2 -> V_23 ) ) {
V_20 = F_5 ( V_2 -> V_23 . V_33 ,
struct V_19 , V_22 ) ;
F_22 ( & V_20 -> V_22 ) ;
}
F_13 ( & V_2 -> V_21 ) ;
return V_20 ;
}
static unsigned long F_82 ( void )
{
return F_73 ( V_95 ) +
F_73 ( V_96 ) +
F_83 () ;
}
static long F_84 ( struct V_30 * V_16 )
{
if ( F_71 () ) {
struct V_19 V_20 = {
. V_24 = V_77 ,
. V_27 = V_28 ,
. V_83 = 1 ,
. V_25 = 1 ,
} ;
return F_76 ( V_16 , & V_20 ) ;
}
return 0 ;
}
static long F_85 ( struct V_30 * V_16 )
{
unsigned long V_101 ;
long V_24 ;
if ( ! V_102 )
return 0 ;
V_101 = V_16 -> V_103 +
F_77 ( V_102 * 10 ) ;
if ( F_27 ( V_35 , V_101 ) )
return 0 ;
V_16 -> V_103 = V_35 ;
V_24 = F_82 () ;
if ( V_24 ) {
struct V_19 V_20 = {
. V_24 = V_24 ,
. V_27 = V_28 ,
. V_82 = 1 ,
. V_25 = 1 ,
} ;
return F_76 ( V_16 , & V_20 ) ;
}
return 0 ;
}
long F_86 ( struct V_30 * V_16 , int V_104 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_19 * V_20 ;
long V_89 = 0 ;
F_87 ( V_3 , & V_16 -> V_2 -> V_4 ) ;
while ( ( V_20 = F_81 ( V_2 ) ) != NULL ) {
if ( V_104 )
V_20 -> V_27 = V_68 ;
F_88 ( V_2 , V_20 ) ;
V_89 += F_76 ( V_16 , V_20 ) ;
if ( V_20 -> V_105 )
F_89 ( V_20 -> V_105 ) ;
else
F_90 ( V_20 ) ;
}
V_89 += F_85 ( V_16 ) ;
V_89 += F_84 ( V_16 ) ;
F_91 ( V_3 , & V_16 -> V_2 -> V_4 ) ;
return V_89 ;
}
int F_92 ( void * V_106 )
{
struct V_30 * V_16 = V_106 ;
struct V_1 * V_2 = V_16 -> V_2 ;
long V_107 ;
V_108 -> V_109 |= V_110 ;
F_93 () ;
V_16 -> V_111 = V_35 ;
F_94 ( V_108 , 0 ) ;
F_95 ( V_2 ) ;
while ( ! F_96 () ) {
F_97 ( & V_16 -> V_112 ) ;
V_107 = F_86 ( V_16 , 0 ) ;
F_98 ( V_107 ) ;
if ( V_107 )
V_16 -> V_111 = V_35 ;
F_99 ( V_113 ) ;
if ( ! F_26 ( & V_2 -> V_23 ) || F_96 () ) {
F_100 ( V_114 ) ;
continue;
}
if ( F_101 ( V_16 ) && V_102 )
F_102 ( F_77 ( V_102 * 10 ) ) ;
else {
F_103 () ;
}
F_104 () ;
}
if ( ! F_26 ( & V_2 -> V_23 ) )
F_86 ( V_16 , 1 ) ;
F_105 ( V_2 ) ;
return 0 ;
}
void F_106 ( long V_24 )
{
struct V_1 * V_2 ;
if ( ! V_24 ) {
V_24 = F_73 ( V_95 ) +
F_73 ( V_96 ) ;
}
F_107 () ;
F_108 (bdi, &bdi_list, bdi_list) {
if ( ! F_109 ( V_2 ) )
continue;
F_14 ( V_2 , V_24 , false ) ;
}
F_110 () ;
}
static T_2 void F_111 ( struct V_5 * V_5 )
{
if ( V_5 -> V_115 || strcmp ( V_5 -> V_8 -> V_116 , L_1 ) ) {
struct V_117 * V_117 ;
const char * V_10 = L_2 ;
V_117 = F_112 ( V_5 ) ;
if ( V_117 ) {
F_21 ( & V_117 -> V_118 ) ;
V_10 = ( const char * ) V_117 -> V_119 . V_10 ;
}
F_113 ( V_120
L_3 ,
V_108 -> V_121 , F_114 ( V_108 ) , V_5 -> V_115 ,
V_10 , V_5 -> V_8 -> V_116 ) ;
if ( V_117 ) {
F_23 ( & V_117 -> V_118 ) ;
F_115 ( V_117 ) ;
}
}
}
void F_116 ( struct V_5 * V_5 , int V_109 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_2 = NULL ;
if ( V_109 & ( V_72 | V_73 ) ) {
if ( V_7 -> V_54 -> V_122 )
V_7 -> V_54 -> V_122 ( V_5 , V_109 ) ;
}
F_31 () ;
if ( ( V_5 -> V_37 & V_109 ) == V_109 )
return;
if ( F_117 ( V_123 ) )
F_111 ( V_5 ) ;
F_21 ( & V_5 -> V_58 ) ;
if ( ( V_5 -> V_37 & V_109 ) != V_109 ) {
const int V_124 = V_5 -> V_37 & V_71 ;
V_5 -> V_37 |= V_109 ;
if ( V_5 -> V_37 & V_57 )
goto V_125;
if ( ! F_118 ( V_5 -> V_126 ) ) {
if ( F_119 ( V_5 ) )
goto V_125;
}
if ( V_5 -> V_37 & V_67 )
goto V_125;
if ( ! V_124 ) {
bool V_127 = false ;
V_2 = F_3 ( V_5 ) ;
if ( F_120 ( V_2 ) ) {
F_121 ( ! F_2 ( V_128 , & V_2 -> V_4 ) ,
L_4 , V_2 -> V_10 ) ;
if ( ! F_101 ( & V_2 -> V_16 ) )
V_127 = true ;
}
F_23 ( & V_5 -> V_58 ) ;
F_21 ( & V_2 -> V_16 . V_29 ) ;
V_5 -> V_34 = V_35 ;
F_28 ( & V_5 -> V_15 , & V_2 -> V_16 . V_31 ) ;
F_23 ( & V_2 -> V_16 . V_29 ) ;
if ( V_127 )
F_122 ( V_2 ) ;
return;
}
}
V_125:
F_23 ( & V_5 -> V_58 ) ;
}
static void F_123 ( struct V_6 * V_7 )
{
struct V_5 * V_5 , * V_129 = NULL ;
F_52 ( ! F_124 ( & V_7 -> V_130 ) ) ;
F_21 ( & V_131 ) ;
F_125 (inode, &sb->s_inodes, i_sb_list) {
struct V_61 * V_62 = V_5 -> V_11 ;
F_21 ( & V_5 -> V_58 ) ;
if ( ( V_5 -> V_37 & ( V_67 | V_66 | V_90 ) ) ||
( V_62 -> V_132 == 0 ) ) {
F_23 ( & V_5 -> V_58 ) ;
continue;
}
F_63 ( V_5 ) ;
F_23 ( & V_5 -> V_58 ) ;
F_23 ( & V_131 ) ;
F_64 ( V_129 ) ;
V_129 = V_5 ;
F_56 ( V_62 ) ;
F_65 () ;
F_21 ( & V_131 ) ;
}
F_23 ( & V_131 ) ;
F_64 ( V_129 ) ;
}
void F_126 ( struct V_6 * V_7 , unsigned long V_133 )
{
F_127 ( V_105 ) ;
struct V_19 V_20 = {
. V_7 = V_7 ,
. V_27 = V_28 ,
. V_74 = 1 ,
. V_105 = & V_105 ,
. V_24 = V_133 ,
} ;
F_52 ( ! F_124 ( & V_7 -> V_130 ) ) ;
F_8 ( V_7 -> V_12 , & V_20 ) ;
F_128 ( & V_105 ) ;
}
void F_129 ( struct V_6 * V_7 )
{
return F_126 ( V_7 , F_82 () ) ;
}
int F_130 ( struct V_6 * V_7 )
{
if ( ! F_1 ( V_7 -> V_12 ) ) {
F_131 ( & V_7 -> V_130 ) ;
F_129 ( V_7 ) ;
F_132 ( & V_7 -> V_130 ) ;
return 1 ;
} else
return 0 ;
}
int F_133 ( struct V_6 * V_7 ,
unsigned long V_133 )
{
if ( ! F_1 ( V_7 -> V_12 ) ) {
F_131 ( & V_7 -> V_130 ) ;
F_126 ( V_7 , V_133 ) ;
F_132 ( & V_7 -> V_130 ) ;
return 1 ;
} else
return 0 ;
}
void F_134 ( struct V_6 * V_7 )
{
F_127 ( V_105 ) ;
struct V_19 V_20 = {
. V_7 = V_7 ,
. V_27 = V_68 ,
. V_24 = V_77 ,
. V_25 = 0 ,
. V_105 = & V_105 ,
} ;
F_52 ( ! F_124 ( & V_7 -> V_130 ) ) ;
F_8 ( V_7 -> V_12 , & V_20 ) ;
F_128 ( & V_105 ) ;
F_123 ( V_7 ) ;
}
int F_135 ( struct V_5 * V_5 , int V_134 )
{
struct V_30 * V_16 = & F_3 ( V_5 ) -> V_16 ;
int V_40 ;
struct V_52 V_53 = {
. V_63 = V_77 ,
. V_27 = V_134 ? V_68 : V_28 ,
. V_84 = 0 ,
. V_85 = V_86 ,
} ;
if ( ! F_136 ( V_5 -> V_11 ) )
V_53 . V_63 = 0 ;
F_137 () ;
F_21 ( & V_16 -> V_29 ) ;
F_21 ( & V_5 -> V_58 ) ;
V_40 = F_50 ( V_5 , V_16 , & V_53 ) ;
F_23 ( & V_5 -> V_58 ) ;
F_23 ( & V_16 -> V_29 ) ;
if ( V_134 )
F_138 ( V_5 ) ;
return V_40 ;
}
int F_139 ( struct V_5 * V_5 , struct V_52 * V_53 )
{
struct V_30 * V_16 = & F_3 ( V_5 ) -> V_16 ;
int V_40 ;
F_21 ( & V_16 -> V_29 ) ;
F_21 ( & V_5 -> V_58 ) ;
V_40 = F_50 ( V_5 , V_16 , V_53 ) ;
F_23 ( & V_5 -> V_58 ) ;
F_23 ( & V_16 -> V_29 ) ;
return V_40 ;
}
int F_140 ( struct V_5 * V_5 , int V_135 )
{
struct V_52 V_53 = {
. V_27 = V_135 ? V_68 : V_28 ,
. V_63 = 0 ,
} ;
return F_139 ( V_5 , & V_53 ) ;
}
