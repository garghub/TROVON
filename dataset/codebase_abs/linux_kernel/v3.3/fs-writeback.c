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
F_31 () ;
F_32 ( & V_5 -> V_39 , V_40 ) ;
}
static bool F_33 ( struct V_5 * V_5 , unsigned long V_41 )
{
bool V_42 = F_34 ( V_5 -> V_36 , V_41 ) ;
#ifndef F_35
V_42 = V_42 && F_36 ( V_5 -> V_36 , V_37 ) ;
#endif
return V_42 ;
}
static int F_37 ( struct V_13 * V_43 ,
struct V_13 * V_44 ,
struct V_19 * V_20 )
{
F_38 ( V_45 ) ;
struct V_13 * V_46 , * V_47 ;
struct V_6 * V_7 = NULL ;
struct V_5 * V_5 ;
int V_48 = 0 ;
int V_49 = 0 ;
while ( ! F_26 ( V_43 ) ) {
V_5 = F_4 ( V_43 -> V_50 ) ;
if ( V_20 -> V_51 &&
F_33 ( V_5 , * V_20 -> V_51 ) )
break;
if ( V_7 && V_7 != V_5 -> V_8 )
V_48 = 1 ;
V_7 = V_5 -> V_8 ;
F_28 ( & V_5 -> V_15 , & V_45 ) ;
V_49 ++ ;
}
if ( ! V_48 ) {
F_39 ( & V_45 , V_44 ) ;
goto V_52;
}
while ( ! F_26 ( & V_45 ) ) {
V_7 = F_4 ( V_45 . V_50 ) -> V_8 ;
F_40 (pos, node, &tmp) {
V_5 = F_4 ( V_46 ) ;
if ( V_5 -> V_8 == V_7 )
F_28 ( & V_5 -> V_15 , V_44 ) ;
}
}
V_52:
return V_49 ;
}
static void F_41 ( struct V_32 * V_16 , struct V_19 * V_20 )
{
int V_49 ;
F_25 ( & V_16 -> V_31 ) ;
F_42 ( & V_16 -> V_38 , & V_16 -> V_53 ) ;
V_49 = F_37 ( & V_16 -> V_33 , & V_16 -> V_53 , V_20 ) ;
F_43 ( V_16 , V_20 , V_49 ) ;
}
static int F_44 ( struct V_5 * V_5 , struct V_54 * V_55 )
{
if ( V_5 -> V_8 -> V_56 -> F_44 && ! F_45 ( V_5 ) )
return V_5 -> V_8 -> V_56 -> F_44 ( V_5 , V_55 ) ;
return 0 ;
}
static void F_46 ( struct V_5 * V_5 ,
struct V_32 * V_16 )
{
F_47 ( V_57 , & V_5 -> V_39 , V_40 ) ;
T_1 * V_58 ;
V_58 = F_48 ( & V_5 -> V_39 , V_40 ) ;
while ( V_5 -> V_39 & V_59 ) {
F_23 ( & V_5 -> V_60 ) ;
F_23 ( & V_16 -> V_31 ) ;
F_49 ( V_58 , & V_57 , V_61 , V_62 ) ;
F_21 ( & V_16 -> V_31 ) ;
F_21 ( & V_5 -> V_60 ) ;
}
}
static int
F_50 ( struct V_5 * V_5 , struct V_32 * V_16 ,
struct V_54 * V_55 )
{
struct V_63 * V_64 = V_5 -> V_11 ;
long V_65 = V_55 -> V_65 ;
unsigned V_66 ;
int V_42 ;
F_25 ( & V_16 -> V_31 ) ;
F_25 ( & V_5 -> V_60 ) ;
if ( ! F_51 ( & V_5 -> V_67 ) )
F_52 ( ! ( V_5 -> V_39 & ( V_68 | V_69 ) ) ) ;
else
F_52 ( V_5 -> V_39 & V_68 ) ;
if ( V_5 -> V_39 & V_59 ) {
if ( V_55 -> V_29 != V_70 ) {
F_29 ( V_5 , V_16 ) ;
F_53 ( V_5 , V_55 ,
V_65 ) ;
return 0 ;
}
F_46 ( V_5 , V_16 ) ;
}
F_54 ( V_5 -> V_39 & V_59 ) ;
V_5 -> V_39 |= V_59 ;
V_5 -> V_39 &= ~ V_71 ;
F_23 ( & V_5 -> V_60 ) ;
F_23 ( & V_16 -> V_31 ) ;
V_42 = F_55 ( V_64 , V_55 ) ;
if ( V_55 -> V_29 == V_70 ) {
int V_72 = F_56 ( V_64 ) ;
if ( V_42 == 0 )
V_42 = V_72 ;
}
F_21 ( & V_5 -> V_60 ) ;
V_66 = V_5 -> V_39 & V_73 ;
V_5 -> V_39 &= ~ ( V_74 | V_75 ) ;
F_23 ( & V_5 -> V_60 ) ;
if ( V_66 & ( V_74 | V_75 ) ) {
int V_72 = F_44 ( V_5 , V_55 ) ;
if ( V_42 == 0 )
V_42 = V_72 ;
}
F_21 ( & V_16 -> V_31 ) ;
F_21 ( & V_5 -> V_60 ) ;
V_5 -> V_39 &= ~ V_59 ;
if ( ! ( V_5 -> V_39 & V_69 ) ) {
if ( ( V_5 -> V_39 & V_73 ) &&
( V_55 -> V_29 == V_70 || V_55 -> V_76 ) )
V_5 -> V_36 = V_37 ;
if ( F_57 ( V_64 , V_77 ) ) {
V_5 -> V_39 |= V_71 ;
if ( V_55 -> V_65 <= 0 ) {
F_29 ( V_5 , V_16 ) ;
} else {
F_24 ( V_5 , V_16 ) ;
}
} else if ( V_5 -> V_39 & V_73 ) {
F_24 ( V_5 , V_16 ) ;
} else {
F_22 ( & V_5 -> V_15 ) ;
}
}
F_30 ( V_5 ) ;
F_58 ( V_5 , V_55 , V_65 ) ;
return V_42 ;
}
static long F_59 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
long V_78 ;
if ( V_20 -> V_29 == V_70 || V_20 -> V_76 )
V_78 = V_79 ;
else {
V_78 = F_60 ( V_2 -> V_80 / 2 ,
V_81 / V_82 ) ;
V_78 = F_60 ( V_78 , V_20 -> V_24 ) ;
V_78 = F_61 ( V_78 + V_83 ,
V_83 ) ;
}
return V_78 ;
}
static long F_62 ( struct V_6 * V_7 ,
struct V_32 * V_16 ,
struct V_19 * V_20 )
{
struct V_54 V_55 = {
. V_29 = V_20 -> V_29 ,
. V_76 = V_20 -> V_76 ,
. V_84 = V_20 -> V_84 ,
. V_85 = V_20 -> V_85 ,
. V_25 = V_20 -> V_25 ,
. V_86 = 0 ,
. V_87 = V_88 ,
} ;
unsigned long V_89 = V_37 ;
long V_90 ;
long V_91 = 0 ;
while ( ! F_26 ( & V_16 -> V_53 ) ) {
struct V_5 * V_5 = F_4 ( V_16 -> V_53 . V_50 ) ;
if ( V_5 -> V_8 != V_7 ) {
if ( V_20 -> V_7 ) {
F_24 ( V_5 , V_16 ) ;
continue;
}
break;
}
F_21 ( & V_5 -> V_60 ) ;
if ( V_5 -> V_39 & ( V_92 | V_69 | V_68 ) ) {
F_23 ( & V_5 -> V_60 ) ;
F_24 ( V_5 , V_16 ) ;
continue;
}
F_63 ( V_5 ) ;
V_90 = F_59 ( V_16 -> V_2 , V_20 ) ;
V_55 . V_65 = V_90 ;
V_55 . V_93 = 0 ;
F_50 ( V_5 , V_16 , & V_55 ) ;
V_20 -> V_24 -= V_90 - V_55 . V_65 ;
V_91 += V_90 - V_55 . V_65 ;
if ( ! ( V_5 -> V_39 & V_73 ) )
V_91 ++ ;
if ( V_55 . V_93 ) {
F_24 ( V_5 , V_16 ) ;
}
F_23 ( & V_5 -> V_60 ) ;
F_23 ( & V_16 -> V_31 ) ;
F_64 ( V_5 ) ;
F_65 () ;
F_21 ( & V_16 -> V_31 ) ;
if ( V_91 ) {
if ( F_66 ( V_89 + V_94 / 10UL ) )
break;
if ( V_20 -> V_24 <= 0 )
break;
}
}
return V_91 ;
}
static long F_67 ( struct V_32 * V_16 ,
struct V_19 * V_20 )
{
unsigned long V_89 = V_37 ;
long V_91 = 0 ;
while ( ! F_26 ( & V_16 -> V_53 ) ) {
struct V_5 * V_5 = F_4 ( V_16 -> V_53 . V_50 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! F_68 ( V_7 ) ) {
F_24 ( V_5 , V_16 ) ;
continue;
}
V_91 += F_62 ( V_7 , V_16 , V_20 ) ;
F_69 ( V_7 ) ;
if ( V_91 ) {
if ( F_66 ( V_89 + V_94 / 10UL ) )
break;
if ( V_20 -> V_24 <= 0 )
break;
}
}
return V_91 ;
}
long F_70 ( struct V_32 * V_16 , long V_24 ,
enum V_26 V_27 )
{
struct V_19 V_20 = {
. V_24 = V_24 ,
. V_29 = V_30 ,
. V_25 = 1 ,
. V_27 = V_27 ,
} ;
F_21 ( & V_16 -> V_31 ) ;
if ( F_26 ( & V_16 -> V_53 ) )
F_41 ( V_16 , & V_20 ) ;
F_67 ( V_16 , & V_20 ) ;
F_23 ( & V_16 -> V_31 ) ;
return V_24 - V_20 . V_24 ;
}
static bool F_71 ( struct V_1 * V_2 )
{
unsigned long V_95 , V_96 ;
F_72 ( & V_95 , & V_96 ) ;
if ( F_73 ( V_97 ) +
F_73 ( V_98 ) > V_95 )
return true ;
if ( F_74 ( V_2 , V_99 ) >
F_75 ( V_2 , V_95 ) )
return true ;
return false ;
}
static void F_76 ( struct V_32 * V_16 ,
unsigned long V_89 )
{
F_77 ( V_16 -> V_2 , 0 , 0 , 0 , 0 , 0 , V_89 ) ;
}
static long F_78 ( struct V_32 * V_16 ,
struct V_19 * V_20 )
{
unsigned long V_100 = V_37 ;
long V_24 = V_20 -> V_24 ;
unsigned long V_101 ;
struct V_5 * V_5 ;
long V_102 ;
V_101 = V_37 ;
V_20 -> V_51 = & V_101 ;
F_21 ( & V_16 -> V_31 ) ;
for (; ; ) {
if ( V_20 -> V_24 <= 0 )
break;
if ( ( V_20 -> V_85 || V_20 -> V_84 ) &&
! F_26 ( & V_16 -> V_2 -> V_23 ) )
break;
if ( V_20 -> V_85 && ! F_71 ( V_16 -> V_2 ) )
break;
if ( V_20 -> V_84 ) {
V_101 = V_37 -
F_79 ( V_103 * 10 ) ;
} else if ( V_20 -> V_85 )
V_101 = V_37 ;
F_80 ( V_16 -> V_2 , V_20 ) ;
if ( F_26 ( & V_16 -> V_53 ) )
F_41 ( V_16 , V_20 ) ;
if ( V_20 -> V_7 )
V_102 = F_62 ( V_20 -> V_7 , V_16 , V_20 ) ;
else
V_102 = F_67 ( V_16 , V_20 ) ;
F_81 ( V_16 -> V_2 , V_20 ) ;
F_76 ( V_16 , V_100 ) ;
if ( V_102 )
continue;
if ( F_26 ( & V_16 -> V_38 ) )
break;
if ( ! F_26 ( & V_16 -> V_38 ) ) {
F_82 ( V_16 -> V_2 , V_20 ) ;
V_5 = F_4 ( V_16 -> V_38 . V_50 ) ;
F_21 ( & V_5 -> V_60 ) ;
F_46 ( V_5 , V_16 ) ;
F_23 ( & V_5 -> V_60 ) ;
}
}
F_23 ( & V_16 -> V_31 ) ;
return V_24 - V_20 -> V_24 ;
}
static struct V_19 *
F_83 ( struct V_1 * V_2 )
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
static unsigned long F_84 ( void )
{
return F_73 ( V_97 ) +
F_73 ( V_98 ) +
F_85 () ;
}
static long F_86 ( struct V_32 * V_16 )
{
if ( F_71 ( V_16 -> V_2 ) ) {
struct V_19 V_20 = {
. V_24 = V_79 ,
. V_29 = V_30 ,
. V_85 = 1 ,
. V_25 = 1 ,
. V_27 = V_104 ,
} ;
return F_78 ( V_16 , & V_20 ) ;
}
return 0 ;
}
static long F_87 ( struct V_32 * V_16 )
{
unsigned long V_105 ;
long V_24 ;
if ( ! V_106 )
return 0 ;
V_105 = V_16 -> V_107 +
F_79 ( V_106 * 10 ) ;
if ( F_27 ( V_37 , V_105 ) )
return 0 ;
V_16 -> V_107 = V_37 ;
V_24 = F_84 () ;
if ( V_24 ) {
struct V_19 V_20 = {
. V_24 = V_24 ,
. V_29 = V_30 ,
. V_84 = 1 ,
. V_25 = 1 ,
. V_27 = V_108 ,
} ;
return F_78 ( V_16 , & V_20 ) ;
}
return 0 ;
}
long F_88 ( struct V_32 * V_16 , int V_109 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_19 * V_20 ;
long V_91 = 0 ;
F_89 ( V_3 , & V_16 -> V_2 -> V_4 ) ;
while ( ( V_20 = F_83 ( V_2 ) ) != NULL ) {
if ( V_109 )
V_20 -> V_29 = V_70 ;
F_90 ( V_2 , V_20 ) ;
V_91 += F_78 ( V_16 , V_20 ) ;
if ( V_20 -> V_110 )
F_91 ( V_20 -> V_110 ) ;
else
F_92 ( V_20 ) ;
}
V_91 += F_87 ( V_16 ) ;
V_91 += F_86 ( V_16 ) ;
F_93 ( V_3 , & V_16 -> V_2 -> V_4 ) ;
return V_91 ;
}
int F_94 ( void * V_111 )
{
struct V_32 * V_16 = V_111 ;
struct V_1 * V_2 = V_16 -> V_2 ;
long V_112 ;
V_113 -> V_114 |= V_115 ;
F_95 () ;
V_16 -> V_116 = V_37 ;
F_96 ( V_113 , 0 ) ;
F_97 ( V_2 ) ;
while ( ! F_98 ( NULL ) ) {
F_99 ( & V_16 -> V_117 ) ;
V_112 = F_88 ( V_16 , 0 ) ;
F_100 ( V_112 ) ;
if ( V_112 )
V_16 -> V_116 = V_37 ;
F_101 ( V_118 ) ;
if ( ! F_26 ( & V_2 -> V_23 ) || F_102 () ) {
F_103 ( V_119 ) ;
continue;
}
if ( F_104 ( V_16 ) && V_106 )
F_105 ( F_79 ( V_106 * 10 ) ) ;
else {
F_106 () ;
}
}
if ( ! F_26 ( & V_2 -> V_23 ) )
F_88 ( V_16 , 1 ) ;
F_107 ( V_2 ) ;
return 0 ;
}
void F_108 ( long V_24 , enum V_26 V_27 )
{
struct V_1 * V_2 ;
if ( ! V_24 ) {
V_24 = F_73 ( V_97 ) +
F_73 ( V_98 ) ;
}
F_109 () ;
F_110 (bdi, &bdi_list, bdi_list) {
if ( ! F_111 ( V_2 ) )
continue;
F_14 ( V_2 , V_24 , false , V_27 ) ;
}
F_112 () ;
}
static T_2 void F_113 ( struct V_5 * V_5 )
{
if ( V_5 -> V_120 || strcmp ( V_5 -> V_8 -> V_121 , L_1 ) ) {
struct V_122 * V_122 ;
const char * V_10 = L_2 ;
V_122 = F_114 ( V_5 ) ;
if ( V_122 ) {
F_21 ( & V_122 -> V_123 ) ;
V_10 = ( const char * ) V_122 -> V_124 . V_10 ;
}
F_115 ( V_125
L_3 ,
V_113 -> V_126 , F_116 ( V_113 ) , V_5 -> V_120 ,
V_10 , V_5 -> V_8 -> V_121 ) ;
if ( V_122 ) {
F_23 ( & V_122 -> V_123 ) ;
F_117 ( V_122 ) ;
}
}
}
void F_118 ( struct V_5 * V_5 , int V_114 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_1 * V_2 = NULL ;
if ( V_114 & ( V_74 | V_75 ) ) {
if ( V_7 -> V_56 -> V_127 )
V_7 -> V_56 -> V_127 ( V_5 , V_114 ) ;
}
F_31 () ;
if ( ( V_5 -> V_39 & V_114 ) == V_114 )
return;
if ( F_119 ( V_128 ) )
F_113 ( V_5 ) ;
F_21 ( & V_5 -> V_60 ) ;
if ( ( V_5 -> V_39 & V_114 ) != V_114 ) {
const int V_129 = V_5 -> V_39 & V_73 ;
V_5 -> V_39 |= V_114 ;
if ( V_5 -> V_39 & V_59 )
goto V_130;
if ( ! F_120 ( V_5 -> V_131 ) ) {
if ( F_121 ( V_5 ) )
goto V_130;
}
if ( V_5 -> V_39 & V_69 )
goto V_130;
if ( ! V_129 ) {
bool V_132 = false ;
V_2 = F_3 ( V_5 ) ;
if ( F_122 ( V_2 ) ) {
F_123 ( ! F_2 ( V_133 , & V_2 -> V_4 ) ,
L_4 , V_2 -> V_10 ) ;
if ( ! F_104 ( & V_2 -> V_16 ) )
V_132 = true ;
}
F_23 ( & V_5 -> V_60 ) ;
F_21 ( & V_2 -> V_16 . V_31 ) ;
V_5 -> V_36 = V_37 ;
F_28 ( & V_5 -> V_15 , & V_2 -> V_16 . V_33 ) ;
F_23 ( & V_2 -> V_16 . V_31 ) ;
if ( V_132 )
F_124 ( V_2 ) ;
return;
}
}
V_130:
F_23 ( & V_5 -> V_60 ) ;
}
static void F_125 ( struct V_6 * V_7 )
{
struct V_5 * V_5 , * V_134 = NULL ;
F_52 ( ! F_126 ( & V_7 -> V_135 ) ) ;
F_21 ( & V_136 ) ;
F_127 (inode, &sb->s_inodes, i_sb_list) {
struct V_63 * V_64 = V_5 -> V_11 ;
F_21 ( & V_5 -> V_60 ) ;
if ( ( V_5 -> V_39 & ( V_69 | V_68 | V_92 ) ) ||
( V_64 -> V_137 == 0 ) ) {
F_23 ( & V_5 -> V_60 ) ;
continue;
}
F_63 ( V_5 ) ;
F_23 ( & V_5 -> V_60 ) ;
F_23 ( & V_136 ) ;
F_64 ( V_134 ) ;
V_134 = V_5 ;
F_56 ( V_64 ) ;
F_65 () ;
F_21 ( & V_136 ) ;
}
F_23 ( & V_136 ) ;
F_64 ( V_134 ) ;
}
void F_128 ( struct V_6 * V_7 ,
unsigned long V_138 ,
enum V_26 V_27 )
{
F_129 ( V_110 ) ;
struct V_19 V_20 = {
. V_7 = V_7 ,
. V_29 = V_30 ,
. V_76 = 1 ,
. V_110 = & V_110 ,
. V_24 = V_138 ,
. V_27 = V_27 ,
} ;
F_52 ( ! F_126 ( & V_7 -> V_135 ) ) ;
F_8 ( V_7 -> V_12 , & V_20 ) ;
F_130 ( & V_110 ) ;
}
void F_131 ( struct V_6 * V_7 , enum V_26 V_27 )
{
return F_128 ( V_7 , F_84 () , V_27 ) ;
}
int F_132 ( struct V_6 * V_7 , enum V_26 V_27 )
{
if ( ! F_1 ( V_7 -> V_12 ) ) {
F_133 ( & V_7 -> V_135 ) ;
F_131 ( V_7 , V_27 ) ;
F_134 ( & V_7 -> V_135 ) ;
return 1 ;
} else
return 0 ;
}
int F_135 ( struct V_6 * V_7 ,
unsigned long V_138 ,
enum V_26 V_27 )
{
if ( ! F_1 ( V_7 -> V_12 ) ) {
F_133 ( & V_7 -> V_135 ) ;
F_128 ( V_7 , V_138 , V_27 ) ;
F_134 ( & V_7 -> V_135 ) ;
return 1 ;
} else
return 0 ;
}
void F_136 ( struct V_6 * V_7 )
{
F_129 ( V_110 ) ;
struct V_19 V_20 = {
. V_7 = V_7 ,
. V_29 = V_70 ,
. V_24 = V_79 ,
. V_25 = 0 ,
. V_110 = & V_110 ,
. V_27 = V_139 ,
} ;
F_52 ( ! F_126 ( & V_7 -> V_135 ) ) ;
F_8 ( V_7 -> V_12 , & V_20 ) ;
F_130 ( & V_110 ) ;
F_125 ( V_7 ) ;
}
int F_137 ( struct V_5 * V_5 , int V_140 )
{
struct V_32 * V_16 = & F_3 ( V_5 ) -> V_16 ;
int V_42 ;
struct V_54 V_55 = {
. V_65 = V_79 ,
. V_29 = V_140 ? V_70 : V_30 ,
. V_86 = 0 ,
. V_87 = V_88 ,
} ;
if ( ! F_138 ( V_5 -> V_11 ) )
V_55 . V_65 = 0 ;
F_139 () ;
F_21 ( & V_16 -> V_31 ) ;
F_21 ( & V_5 -> V_60 ) ;
V_42 = F_50 ( V_5 , V_16 , & V_55 ) ;
F_23 ( & V_5 -> V_60 ) ;
F_23 ( & V_16 -> V_31 ) ;
if ( V_140 )
F_140 ( V_5 ) ;
return V_42 ;
}
int F_141 ( struct V_5 * V_5 , struct V_54 * V_55 )
{
struct V_32 * V_16 = & F_3 ( V_5 ) -> V_16 ;
int V_42 ;
F_21 ( & V_16 -> V_31 ) ;
F_21 ( & V_5 -> V_60 ) ;
V_42 = F_50 ( V_5 , V_16 , V_55 ) ;
F_23 ( & V_5 -> V_60 ) ;
F_23 ( & V_16 -> V_31 ) ;
return V_42 ;
}
int F_142 ( struct V_5 * V_5 , int V_141 )
{
struct V_54 V_55 = {
. V_29 = V_141 ? V_70 : V_30 ,
. V_65 = 0 ,
} ;
return F_141 ( V_5 , & V_55 ) ;
}
