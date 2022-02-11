static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 = 0ul ;
V_2 -> V_5 = 0ul ;
V_2 -> V_6 = V_7 ;
}
static bool F_3 ( struct V_1 * V_2 , unsigned long V_8 )
{
if ( V_2 -> V_4 )
return false ;
return F_4 ( V_7 , V_2 -> V_5 + V_8 ) ;
}
static bool F_5 ( struct V_1 * V_2 , unsigned long V_8 )
{
bool V_9 ;
unsigned long V_10 ;
F_6 ( & V_2 -> V_3 , V_10 ) ;
V_9 = F_3 ( V_2 , V_8 ) ;
F_7 ( & V_2 -> V_3 , V_10 ) ;
return V_9 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_11 )
{
unsigned long V_10 ;
F_6 ( & V_2 -> V_3 , V_10 ) ;
V_2 -> V_4 += V_11 ;
F_7 ( & V_2 -> V_3 , V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_11 )
{
if ( ! V_11 )
return;
V_2 -> V_4 -= V_11 ;
if ( ! V_2 -> V_4 )
V_2 -> V_5 = V_7 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_11 )
{
unsigned long V_10 ;
F_6 ( & V_2 -> V_3 , V_10 ) ;
F_9 ( V_2 , V_11 ) ;
F_7 ( & V_2 -> V_3 , V_10 ) ;
}
static inline void F_11 ( struct V_12 * V_13 ,
void (* F_12)( struct V_14 * ) )
{
F_13 ( & V_13 -> V_15 , F_12 ) ;
V_13 -> V_16 = 0 ;
}
static inline void F_14 ( struct V_17 * V_18 ,
struct V_12 * V_13 )
{
F_15 ( V_18 , & V_13 -> V_15 ) ;
}
static void F_16 ( struct V_14 * V_19 )
{
struct V_20 * V_21 = F_17 ( V_19 , struct V_20 , V_22 ) ;
int V_9 ;
unsigned long V_10 ;
struct V_23 V_24 ;
struct V_14 * V_15 , * V_25 ;
struct V_12 * V_13 ;
struct V_26 * V_26 ;
struct V_27 V_28 ;
F_18 ( & V_24 ) ;
F_19 ( & V_28 ) ;
F_6 ( & V_21 -> V_3 , V_10 ) ;
F_20 ( & V_21 -> V_24 , & V_24 ) ;
F_21 ( & V_28 , & V_21 -> V_28 ) ;
F_19 ( & V_21 -> V_28 ) ;
V_21 -> V_29 = false ;
F_7 ( & V_21 -> V_3 , V_10 ) ;
V_9 = V_21 -> V_30 ( V_21 -> V_31 ) ;
F_22 (ws, tmp, &work_items, entry) {
V_13 = F_17 ( V_15 , struct V_12 , V_15 ) ;
V_13 -> V_16 = V_9 ;
F_18 ( & V_15 -> V_32 ) ;
F_15 ( V_21 -> V_18 , V_15 ) ;
}
while ( ( V_26 = F_23 ( & V_28 ) ) ) {
if ( V_9 ) {
V_26 -> V_33 = V_9 ;
F_24 ( V_26 ) ;
} else
V_21 -> V_34 ( V_26 , V_21 -> V_35 ) ;
}
}
static void F_25 ( struct V_20 * V_21 ,
int (* V_30)( void * ) ,
void * V_31 ,
void (* V_34)( struct V_26 * V_26 , void * ) ,
void * V_35 ,
struct V_17 * V_18 )
{
V_21 -> V_30 = V_30 ;
V_21 -> V_31 = V_31 ;
V_21 -> V_34 = V_34 ;
V_21 -> V_35 = V_35 ;
V_21 -> V_18 = V_18 ;
F_2 ( & V_21 -> V_3 ) ;
F_18 ( & V_21 -> V_24 ) ;
F_19 ( & V_21 -> V_28 ) ;
F_13 ( & V_21 -> V_22 , F_16 ) ;
V_21 -> V_29 = false ;
}
static void F_26 ( struct V_20 * V_21 )
{
F_15 ( V_21 -> V_18 , & V_21 -> V_22 ) ;
}
static void F_27 ( struct V_20 * V_21 , struct V_12 * V_13 )
{
unsigned long V_10 ;
bool V_29 ;
F_6 ( & V_21 -> V_3 , V_10 ) ;
V_29 = V_21 -> V_29 ;
F_28 ( & V_13 -> V_15 . V_32 , & V_21 -> V_24 ) ;
F_7 ( & V_21 -> V_3 , V_10 ) ;
if ( V_29 )
F_26 ( V_21 ) ;
}
static void F_29 ( struct V_20 * V_21 , struct V_26 * V_26 )
{
unsigned long V_10 ;
bool V_29 ;
F_6 ( & V_21 -> V_3 , V_10 ) ;
V_29 = V_21 -> V_29 ;
F_30 ( & V_21 -> V_28 , V_26 ) ;
F_7 ( & V_21 -> V_3 , V_10 ) ;
if ( V_29 )
F_26 ( V_21 ) ;
}
static void F_31 ( struct V_20 * V_21 )
{
bool V_36 ;
unsigned long V_10 ;
F_6 ( & V_21 -> V_3 , V_10 ) ;
V_36 = ! F_32 ( & V_21 -> V_24 ) || ! F_33 ( & V_21 -> V_28 ) ;
V_21 -> V_29 = true ;
F_7 ( & V_21 -> V_3 , V_10 ) ;
if ( V_36 )
F_26 ( V_21 ) ;
}
static void F_34 ( struct V_37 * V_38 , struct V_26 * V_26 ,
T_2 * V_39 , void * V_40 )
{
V_38 -> V_39 = V_26 -> V_39 ;
V_26 -> V_39 = V_39 ;
V_26 -> V_40 = V_40 ;
}
static void F_35 ( struct V_37 * V_38 , struct V_26 * V_26 )
{
V_26 -> V_39 = V_38 -> V_39 ;
}
static bool F_36 ( struct V_41 * V_42 )
{
return V_42 -> V_43 == V_44 ;
}
static bool F_37 ( struct V_41 * V_42 )
{
return V_42 -> V_43 == V_45 ;
}
static inline bool F_38 ( struct V_41 * V_42 )
{
return F_39 ( V_42 -> V_43 == V_46 ) ;
}
static void F_40 ( struct V_47 * V_47 )
{
F_15 ( V_47 -> V_18 , & V_47 -> V_48 ) ;
}
static void F_41 ( struct V_47 * V_47 )
{
F_15 ( V_47 -> V_18 , & V_47 -> V_49 ) ;
}
static void F_42 ( struct V_47 * V_47 )
{
if ( F_38 ( & V_47 -> V_50 ) )
return;
F_15 ( V_47 -> V_18 , & V_47 -> V_51 ) ;
}
static struct V_52 * F_43 ( struct V_47 * V_47 )
{
return F_44 ( V_47 -> V_53 , V_54 ) ;
}
static void F_45 ( struct V_47 * V_47 , struct V_52 * V_55 )
{
F_46 ( V_47 -> V_53 , V_55 ) ;
}
static struct V_56 * F_47 ( struct V_47 * V_47 )
{
struct V_56 * V_57 ;
V_57 = F_48 ( V_47 -> V_58 , V_54 ) ;
if ( V_57 ) {
V_57 -> V_47 = V_47 ;
F_49 ( & V_57 -> V_47 -> V_59 ) ;
}
return V_57 ;
}
static void F_50 ( struct V_56 * V_57 )
{
struct V_47 * V_47 = V_57 -> V_47 ;
if ( F_51 ( & V_47 -> V_59 ) )
F_52 ( & V_47 -> V_60 ) ;
F_53 ( V_57 , V_47 -> V_58 ) ;
}
static inline T_3 F_54 ( T_3 V_21 )
{
return F_55 ( F_56 ( V_21 ) + 1ull ) ;
}
static void F_57 ( T_3 V_61 , T_3 V_62 , struct V_63 * V_64 )
{
V_64 -> V_65 = 0 ;
V_64 -> V_66 = 0 ;
V_64 -> V_67 = F_56 ( V_61 ) ;
V_64 -> V_68 = F_56 ( V_62 ) ;
}
static unsigned F_58 ( struct V_26 * V_26 )
{
return F_59 ( V_26 ) == V_69 ?
V_70 :
V_71 ;
}
static T_4 F_60 ( struct V_47 * V_47 )
{
return F_36 ( & V_47 -> V_50 ) ? V_72 : V_73 ;
}
static struct V_74 * F_61 ( struct V_26 * V_26 , T_4 V_75 )
{
struct V_74 * V_76 = F_62 ( V_26 , V_75 ) ;
F_63 ( ! V_76 ) ;
return V_76 ;
}
static struct V_74 * F_64 ( struct V_26 * V_26 , T_4 V_75 )
{
struct V_74 * V_76 = F_61 ( V_26 , V_75 ) ;
V_76 -> V_77 = false ;
V_76 -> V_78 = F_65 ( V_26 ) ;
V_76 -> V_55 = NULL ;
V_76 -> V_11 = 0 ;
return V_76 ;
}
static void F_66 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
unsigned long V_10 ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
F_30 ( & V_47 -> V_79 , V_26 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
F_40 ( V_47 ) ;
}
static void F_67 ( struct V_47 * V_47 , struct V_27 * V_28 )
{
unsigned long V_10 ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
F_21 ( & V_47 -> V_79 , V_28 ) ;
F_19 ( V_28 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
F_40 ( V_47 ) ;
}
static bool F_68 ( struct V_47 * V_47 , T_3 V_80 , struct V_26 * V_26 )
{
bool V_9 ;
T_4 V_81 ;
struct V_74 * V_76 ;
struct V_63 V_64 ;
T_3 V_62 = F_55 ( F_56 ( V_80 ) + 1ULL ) ;
struct V_52 * V_82 , * V_55 ;
V_82 = F_43 ( V_47 ) ;
if ( ! V_82 ) {
F_66 ( V_47 , V_26 ) ;
return false ;
}
F_57 ( V_80 , V_62 , & V_64 ) ;
V_9 = F_69 ( V_47 -> V_53 , & V_64 , F_58 ( V_26 ) , V_26 , V_82 , & V_55 ) ;
if ( ! V_9 ) {
F_45 ( V_47 , V_82 ) ;
return V_9 ;
}
if ( V_55 != V_82 )
F_45 ( V_47 , V_82 ) ;
V_81 = F_60 ( V_47 ) ;
V_76 = F_61 ( V_26 , V_81 ) ;
V_76 -> V_55 = V_55 ;
return V_9 ;
}
static bool F_70 ( struct V_47 * V_47 , T_5 V_21 )
{
return F_71 ( F_72 ( V_21 ) , V_47 -> V_83 ) ;
}
static void F_73 ( struct V_47 * V_47 , T_5 V_84 )
{
if ( ! F_74 ( F_72 ( V_84 ) , V_47 -> V_83 ) ) {
F_49 ( & V_47 -> V_85 ) ;
F_75 ( V_47 -> V_86 , V_84 ) ;
}
}
static void F_76 ( struct V_47 * V_47 , T_5 V_84 )
{
if ( ! F_74 ( F_72 ( V_84 ) , V_47 -> V_83 ) )
F_49 ( & V_47 -> V_85 ) ;
F_75 ( V_47 -> V_86 , V_84 ) ;
}
static void F_77 ( struct V_47 * V_47 , T_5 V_84 )
{
if ( F_78 ( F_72 ( V_84 ) , V_47 -> V_83 ) ) {
if ( F_79 ( & V_47 -> V_85 ) == 0 )
F_80 ( V_47 -> V_87 -> V_88 ) ;
}
F_81 ( V_47 -> V_86 , V_84 ) ;
}
static bool F_82 ( struct V_47 * V_47 )
{
return V_47 -> V_89 >= 0 ;
}
T_6
#endif
static T_7 F_83 ( T_7 V_21 , T_8 V_90 )
{
F_84 ( V_21 , V_90 ) ;
return V_21 ;
}
static T_7 F_85 ( struct V_47 * V_47 )
{
T_7 V_91 = V_47 -> V_92 ;
if ( F_82 ( V_47 ) )
V_91 >>= V_47 -> V_89 ;
else
V_91 = F_83 ( V_91 , V_47 -> V_93 ) ;
return V_91 ;
}
static T_9 F_86 ( struct V_47 * V_47 , T_3 V_80 )
{
return F_87 ( F_83 ( F_56 ( V_80 ) ,
F_85 ( V_47 ) ) ) ;
}
static void F_88 ( struct V_47 * V_47 , T_9 V_21 )
{
unsigned long V_10 ;
F_63 ( F_89 ( V_21 ) >= F_89 ( V_47 -> V_94 ) ) ;
F_49 ( & V_47 -> V_95 . V_96 ) ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
F_90 ( F_89 ( V_21 ) , V_47 -> V_97 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
}
static void F_91 ( struct V_47 * V_47 , T_9 V_21 )
{
unsigned long V_10 ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
F_92 ( F_89 ( V_21 ) , V_47 -> V_97 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
}
static bool F_93 ( struct V_47 * V_47 , T_9 V_21 )
{
int V_9 ;
unsigned long V_10 ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
V_9 = F_71 ( F_89 ( V_21 ) , V_47 -> V_97 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
return V_9 ;
}
static bool F_94 ( struct V_47 * V_47 , T_3 V_21 )
{
int V_9 ;
unsigned long V_10 ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
V_9 = F_71 ( F_89 ( F_86 ( V_47 , V_21 ) ) ,
V_47 -> V_97 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
return V_9 ;
}
static void F_95 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
V_26 -> V_98 = V_47 -> V_99 -> V_100 ;
}
static void F_96 ( struct V_47 * V_47 , struct V_26 * V_26 ,
T_5 V_84 )
{
T_1 V_101 = V_26 -> V_102 . V_101 ;
T_1 V_103 = F_72 ( V_84 ) ;
V_26 -> V_98 = V_47 -> V_104 -> V_100 ;
if ( ! F_82 ( V_47 ) )
V_26 -> V_102 . V_101 =
( V_103 * V_47 -> V_93 ) +
F_97 ( V_101 , V_47 -> V_93 ) ;
else
V_26 -> V_102 . V_101 =
( V_103 << V_47 -> V_89 ) |
( V_101 & ( V_47 -> V_93 - 1 ) ) ;
}
static void F_98 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
unsigned long V_10 ;
T_4 V_105 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_105 ) ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
if ( V_47 -> V_106 && ! F_99 ( V_26 -> V_107 ) &&
F_100 ( V_26 ) != V_108 ) {
V_76 -> V_77 = true ;
V_47 -> V_106 = false ;
}
F_7 ( & V_47 -> V_3 , V_10 ) ;
}
static void F_101 ( struct V_47 * V_47 , struct V_26 * V_26 ,
T_3 V_80 )
{
F_98 ( V_47 , V_26 ) ;
F_95 ( V_47 , V_26 ) ;
if ( F_59 ( V_26 ) == V_69 )
F_91 ( V_47 , F_86 ( V_47 , V_80 ) ) ;
}
static void F_102 ( struct V_47 * V_47 , struct V_26 * V_26 ,
T_3 V_80 , T_5 V_84 )
{
F_98 ( V_47 , V_26 ) ;
F_96 ( V_47 , V_26 , V_84 ) ;
if ( F_59 ( V_26 ) == V_69 ) {
F_73 ( V_47 , V_84 ) ;
F_91 ( V_47 , F_86 ( V_47 , V_80 ) ) ;
}
}
static T_3 F_103 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
T_1 V_109 = V_26 -> V_102 . V_101 ;
if ( ! F_82 ( V_47 ) )
( void ) F_97 ( V_109 , V_47 -> V_93 ) ;
else
V_109 >>= V_47 -> V_89 ;
return F_55 ( V_109 ) ;
}
static bool F_104 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
return F_100 ( V_26 ) != V_108 ;
}
static void F_105 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
T_4 V_105 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_105 ) ;
if ( F_104 ( V_47 , V_26 ) ) {
V_76 -> V_11 = F_106 ( V_26 ) ;
F_8 ( & V_47 -> V_110 , V_76 -> V_11 ) ;
}
}
static void F_107 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
T_4 V_105 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_105 ) ;
F_10 ( & V_47 -> V_110 , V_76 -> V_11 ) ;
}
static void F_108 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
F_105 ( V_47 , V_26 ) ;
F_109 ( V_26 ) ;
}
static void V_34 ( struct V_26 * V_26 , void * V_111 )
{
struct V_47 * V_47 = V_111 ;
F_108 ( V_47 , V_26 ) ;
}
static void F_110 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
unsigned long V_10 ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
F_30 ( & V_47 -> V_112 , V_26 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
F_41 ( V_47 ) ;
}
static void F_111 ( struct V_26 * V_26 )
{
struct V_74 * V_76 = F_61 ( V_26 , V_72 ) ;
F_35 ( & V_76 -> V_113 , V_26 ) ;
if ( V_26 -> V_33 ) {
F_24 ( V_26 ) ;
return;
}
F_112 ( & V_76 -> V_114 , V_26 ) ;
F_96 ( V_76 -> V_47 , V_26 , V_76 -> V_84 ) ;
F_110 ( V_76 -> V_47 , V_26 ) ;
}
static void F_113 ( struct V_47 * V_47 , struct V_26 * V_26 ,
T_3 V_80 , T_5 V_84 )
{
struct V_74 * V_76 = F_61 ( V_26 , V_72 ) ;
V_76 -> V_47 = V_47 ;
V_76 -> V_84 = V_84 ;
F_34 ( & V_76 -> V_113 , V_26 , F_111 , NULL ) ;
F_114 ( & V_76 -> V_114 , V_26 ) ;
F_101 ( V_76 -> V_47 , V_26 , V_80 ) ;
}
static enum V_115 F_115 ( struct V_47 * V_47 )
{
return V_47 -> V_50 . V_116 ;
}
static const char * F_116 ( struct V_47 * V_47 )
{
return F_117 ( F_118 ( V_47 -> V_87 -> V_88 ) ) ;
}
static void F_119 ( struct V_47 * V_47 , enum V_115 V_116 )
{
const char * V_117 [] = {
L_1 ,
L_2 ,
L_3
} ;
F_80 ( V_47 -> V_87 -> V_88 ) ;
F_120 ( L_4 ,
F_116 ( V_47 ) , V_117 [ ( int ) V_116 ] ) ;
}
static void F_121 ( struct V_47 * V_47 , enum V_115 V_118 )
{
bool V_119 ;
enum V_115 V_120 = F_115 ( V_47 ) ;
if ( F_122 ( V_47 -> V_121 , & V_119 ) ) {
F_123 ( L_5 ,
F_116 ( V_47 ) ) ;
V_118 = V_122 ;
}
if ( V_118 == V_123 && V_119 ) {
F_123 ( L_6 ,
F_116 ( V_47 ) ) ;
if ( V_120 != V_118 )
V_118 = V_120 ;
else
V_118 = V_124 ;
}
if ( V_120 == V_122 )
V_118 = V_122 ;
switch ( V_118 ) {
case V_122 :
case V_124 :
F_124 ( V_47 -> V_121 ) ;
break;
case V_123 :
F_125 ( V_47 -> V_121 ) ;
break;
}
V_47 -> V_50 . V_116 = V_118 ;
if ( V_118 != V_120 )
F_119 ( V_47 , V_118 ) ;
}
static void F_126 ( struct V_47 * V_47 )
{
const char * V_125 = F_116 ( V_47 ) ;
if ( F_115 ( V_47 ) >= V_124 )
return;
if ( F_127 ( V_47 -> V_121 ) ) {
F_123 ( L_7 , V_125 ) ;
F_121 ( V_47 , V_122 ) ;
}
F_128 ( L_8 , V_125 ) ;
if ( F_129 ( V_47 -> V_121 ) ) {
F_123 ( L_9 , V_125 ) ;
F_121 ( V_47 , V_122 ) ;
}
}
static void F_130 ( struct V_47 * V_47 , const char * V_126 , int V_9 )
{
F_128 ( L_10 ,
F_116 ( V_47 ) , V_126 , V_9 ) ;
F_126 ( V_47 ) ;
F_121 ( V_47 , V_124 ) ;
}
static void F_131 ( struct V_47 * V_47 )
{
struct V_127 V_95 ;
F_132 ( V_47 -> V_121 , & V_95 ) ;
F_133 ( & V_47 -> V_95 . V_128 , V_95 . V_129 ) ;
F_133 ( & V_47 -> V_95 . V_130 , V_95 . V_131 ) ;
F_133 ( & V_47 -> V_95 . V_132 , V_95 . V_133 ) ;
F_133 ( & V_47 -> V_95 . V_134 , V_95 . V_135 ) ;
}
static void F_134 ( struct V_47 * V_47 )
{
struct V_127 V_95 ;
if ( F_115 ( V_47 ) >= V_124 )
return;
V_95 . V_129 = F_135 ( & V_47 -> V_95 . V_128 ) ;
V_95 . V_131 = F_135 ( & V_47 -> V_95 . V_130 ) ;
V_95 . V_133 = F_135 ( & V_47 -> V_95 . V_132 ) ;
V_95 . V_135 = F_135 ( & V_47 -> V_95 . V_134 ) ;
F_136 ( V_47 -> V_121 , & V_95 ) ;
}
static void F_137 ( struct V_136 * V_95 , enum V_137 V_126 )
{
switch ( V_126 ) {
case V_138 :
F_49 ( & V_95 -> V_139 ) ;
break;
case V_140 :
F_49 ( & V_95 -> V_141 ) ;
break;
case V_142 :
F_49 ( & V_95 -> V_143 ) ;
break;
}
}
static void F_138 ( struct V_47 * V_47 )
{
F_49 ( & V_47 -> V_144 ) ;
}
static void F_139 ( struct V_47 * V_47 )
{
F_140 ( & V_47 -> V_144 ) ;
}
static bool F_141 ( struct V_26 * V_26 )
{
return F_100 ( V_26 ) == V_108 || F_99 ( V_26 -> V_107 ) ;
}
static void F_142 ( struct V_47 * V_47 , struct V_26 * V_26 ,
T_9 * V_21 , T_9 * V_145 )
{
T_1 V_146 = V_26 -> V_102 . V_101 ;
T_1 V_147 = F_143 ( V_26 ) ;
* V_21 = F_87 ( F_144 ( V_146 , V_47 -> V_92 ) ) ;
if ( V_147 - V_146 < V_47 -> V_92 )
* V_145 = * V_21 ;
else
* V_145 = F_87 ( F_83 ( V_147 , V_47 -> V_92 ) ) ;
}
static void F_145 ( struct V_47 * V_47 )
{
F_146 () ;
F_147 ( & V_47 -> V_148 ) ;
F_148 () ;
}
static void F_149 ( struct V_47 * V_47 )
{
F_146 () ;
F_150 ( & V_47 -> V_148 ) ;
F_148 () ;
}
static bool F_151 ( struct V_47 * V_47 )
{
bool V_9 ;
F_146 () ;
V_9 = F_152 ( & V_47 -> V_148 ) ;
F_148 () ;
return V_9 ;
}
static void F_153 ( struct V_47 * V_47 )
{
F_146 () ;
F_154 ( & V_47 -> V_148 ) ;
F_148 () ;
}
static void F_155 ( struct V_56 * V_57 ,
void (* V_12)( struct V_14 * ) )
{
F_11 ( & V_57 -> V_13 , V_12 ) ;
F_156 ( V_57 -> V_47 -> V_53 , V_57 -> V_55 , & V_57 -> V_13 . V_15 ) ;
}
static struct V_56 * F_157 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_17 ( V_15 , struct V_12 , V_15 ) ;
return F_17 ( V_13 , struct V_56 , V_13 ) ;
}
static void F_158 ( int V_149 , unsigned long V_150 , void * V_111 )
{
struct V_56 * V_57 = F_17 ( V_111 , struct V_56 , V_13 ) ;
if ( V_149 || V_150 )
V_57 -> V_13 . V_16 = - V_151 ;
F_14 ( V_57 -> V_47 -> V_18 , & V_57 -> V_13 ) ;
}
static int F_159 ( struct V_56 * V_57 , bool V_152 )
{
int V_9 ;
struct V_153 V_154 , V_155 ;
struct V_47 * V_47 = V_57 -> V_47 ;
V_154 . V_100 = V_47 -> V_99 -> V_100 ;
V_154 . V_156 = F_56 ( V_57 -> V_126 -> V_80 ) * V_47 -> V_93 ;
V_154 . V_157 = V_47 -> V_93 ;
V_155 . V_100 = V_47 -> V_104 -> V_100 ;
V_155 . V_156 = F_72 ( V_57 -> V_126 -> V_84 ) * V_47 -> V_93 ;
V_155 . V_157 = V_47 -> V_93 ;
if ( V_152 )
V_9 = F_160 ( V_47 -> V_158 , & V_154 , 1 , & V_155 , 0 , F_158 , & V_57 -> V_13 ) ;
else
V_9 = F_160 ( V_47 -> V_158 , & V_155 , 1 , & V_154 , 0 , F_158 , & V_57 -> V_13 ) ;
return V_9 ;
}
static void F_161 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
T_4 V_105 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_105 ) ;
if ( V_76 -> V_55 && F_162 ( V_47 -> V_53 , V_76 -> V_55 ) )
F_45 ( V_47 , V_76 -> V_55 ) ;
V_76 -> V_55 = NULL ;
}
static void F_163 ( struct V_26 * V_26 )
{
struct V_56 * V_57 = V_26 -> V_40 ;
struct V_47 * V_47 = V_57 -> V_47 ;
T_4 V_105 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_105 ) ;
F_35 ( & V_76 -> V_113 , V_26 ) ;
if ( V_26 -> V_33 )
V_57 -> V_13 . V_16 = V_26 -> V_33 ;
F_14 ( V_57 -> V_47 -> V_18 , & V_57 -> V_13 ) ;
}
static void F_164 ( struct V_56 * V_57 ,
void (* V_12)( struct V_14 * ) )
{
struct V_26 * V_26 = V_57 -> V_159 ;
T_4 V_105 = F_60 ( V_57 -> V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_105 ) ;
F_34 ( & V_76 -> V_113 , V_26 , F_163 , V_57 ) ;
if ( V_57 -> V_126 -> V_126 == V_138 )
F_96 ( V_57 -> V_47 , V_26 , V_57 -> V_126 -> V_84 ) ;
else
F_95 ( V_57 -> V_47 , V_26 ) ;
F_11 ( & V_57 -> V_13 , V_12 ) ;
F_108 ( V_57 -> V_47 , V_26 ) ;
}
static void F_165 ( struct V_56 * V_57 , bool V_160 )
{
struct V_27 V_28 ;
struct V_47 * V_47 = V_57 -> V_47 ;
struct V_161 * V_126 = V_57 -> V_126 ;
T_5 V_84 = V_126 -> V_84 ;
if ( V_160 )
F_137 ( & V_47 -> V_95 , V_126 -> V_126 ) ;
switch ( V_126 -> V_126 ) {
case V_138 :
F_91 ( V_47 , F_86 ( V_47 , V_126 -> V_80 ) ) ;
F_166 ( V_47 -> V_86 , V_126 , V_160 ) ;
if ( V_57 -> V_159 ) {
if ( V_160 )
F_76 ( V_47 , V_84 ) ;
else
V_57 -> V_159 -> V_33 = ( V_57 -> V_13 . V_16 ? : - V_151 ) ;
F_24 ( V_57 -> V_159 ) ;
} else {
if ( V_160 )
F_77 ( V_47 , V_84 ) ;
F_139 ( V_47 ) ;
}
break;
case V_140 :
if ( V_160 )
F_77 ( V_47 , V_84 ) ;
F_166 ( V_47 -> V_86 , V_126 , V_160 ) ;
F_139 ( V_47 ) ;
break;
case V_142 :
if ( V_160 )
F_77 ( V_47 , V_84 ) ;
F_166 ( V_47 -> V_86 , V_126 , V_160 ) ;
F_139 ( V_47 ) ;
break;
}
F_19 ( & V_28 ) ;
if ( V_57 -> V_55 ) {
if ( F_167 ( V_47 -> V_53 , V_57 -> V_55 , & V_28 ) )
F_45 ( V_47 , V_57 -> V_55 ) ;
}
F_50 ( V_57 ) ;
F_67 ( V_47 , & V_28 ) ;
F_42 ( V_47 ) ;
F_153 ( V_47 ) ;
}
static void F_168 ( struct V_14 * V_15 )
{
struct V_56 * V_57 = F_157 ( V_15 ) ;
F_165 ( V_57 , V_57 -> V_13 . V_16 == 0 ) ;
}
static void F_169 ( struct V_14 * V_15 )
{
int V_9 ;
struct V_56 * V_57 = F_157 ( V_15 ) ;
struct V_47 * V_47 = V_57 -> V_47 ;
struct V_161 * V_126 = V_57 -> V_126 ;
switch ( V_126 -> V_126 ) {
case V_138 :
V_9 = F_170 ( V_47 -> V_121 , V_126 -> V_84 , V_126 -> V_80 ) ;
if ( V_9 ) {
F_128 ( L_11 ,
F_116 ( V_47 ) ) ;
F_130 ( V_47 , L_12 , V_9 ) ;
F_165 ( V_57 , false ) ;
return;
}
F_165 ( V_57 , true ) ;
break;
case V_140 :
V_9 = F_171 ( V_47 -> V_121 , V_126 -> V_84 ) ;
if ( V_9 ) {
F_128 ( L_13 ,
F_116 ( V_47 ) ) ;
F_130 ( V_47 , L_14 , V_9 ) ;
F_165 ( V_57 , false ) ;
return;
}
F_11 ( & V_57 -> V_13 , F_168 ) ;
F_27 ( & V_47 -> V_162 , & V_57 -> V_13 ) ;
F_31 ( & V_47 -> V_162 ) ;
break;
case V_142 :
F_165 ( V_57 , true ) ;
break;
}
}
static void F_172 ( struct V_14 * V_15 )
{
struct V_56 * V_57 = F_157 ( V_15 ) ;
if ( V_57 -> V_13 . V_16 )
F_165 ( V_57 , false ) ;
else
F_169 ( V_15 ) ;
}
static void F_173 ( struct V_14 * V_15 )
{
int V_9 ;
struct V_56 * V_57 = F_157 ( V_15 ) ;
if ( V_57 -> V_13 . V_16 )
F_165 ( V_57 , false ) ;
else {
V_9 = F_174 ( V_57 -> V_47 -> V_53 , V_57 -> V_55 ,
V_71 ) ;
if ( V_9 < 0 )
F_165 ( V_57 , false ) ;
else if ( V_9 )
F_155 ( V_57 , F_169 ) ;
else
F_169 ( V_15 ) ;
}
}
static void F_175 ( struct V_14 * V_15 )
{
int V_9 ;
struct V_56 * V_57 = F_157 ( V_15 ) ;
if ( V_57 -> V_159 ) {
F_164 ( V_57 , F_172 ) ;
} else {
struct V_47 * V_47 = V_57 -> V_47 ;
struct V_161 * V_126 = V_57 -> V_126 ;
bool V_163 = ( V_126 -> V_126 == V_138 ) ;
if ( ( ! V_163 && ! F_70 ( V_47 , V_126 -> V_84 ) ) ||
F_94 ( V_47 , V_126 -> V_80 ) ) {
F_173 ( V_15 ) ;
return;
}
F_11 ( & V_57 -> V_13 , F_173 ) ;
V_9 = F_159 ( V_57 , V_163 ) ;
if ( V_9 ) {
F_128 ( L_15 , F_116 ( V_47 ) ) ;
V_57 -> V_13 . V_16 = - V_151 ;
F_165 ( V_57 , false ) ;
}
}
}
static int F_176 ( struct V_56 * V_57 )
{
int V_9 ;
struct V_63 V_64 ;
struct V_47 * V_47 = V_57 -> V_47 ;
struct V_52 * V_164 ;
V_164 = F_43 ( V_47 ) ;
if ( ! V_164 ) {
F_128 ( L_16 , F_116 ( V_47 ) ) ;
F_165 ( V_57 , false ) ;
return - V_165 ;
}
F_57 ( V_57 -> V_126 -> V_80 , F_54 ( V_57 -> V_126 -> V_80 ) , & V_64 ) ;
V_9 = F_177 ( V_47 -> V_53 , & V_64 ,
V_57 -> V_159 ? V_71 : V_70 ,
V_164 , & V_57 -> V_55 ) ;
if ( V_9 < 0 ) {
F_45 ( V_47 , V_164 ) ;
F_165 ( V_57 , false ) ;
return V_9 ;
}
if ( V_57 -> V_55 != V_164 )
F_45 ( V_47 , V_164 ) ;
if ( V_9 == 0 )
F_175 ( & V_57 -> V_13 . V_15 ) ;
else
F_155 ( V_57 , F_175 ) ;
return 0 ;
}
static int F_178 ( struct V_47 * V_47 , struct V_161 * V_126 , struct V_26 * V_26 )
{
struct V_56 * V_57 ;
if ( ! F_151 ( V_47 ) ) {
F_166 ( V_47 -> V_86 , V_126 , false ) ;
return - V_166 ;
}
V_57 = F_47 ( V_47 ) ;
if ( ! V_57 ) {
F_166 ( V_47 -> V_86 , V_126 , false ) ;
F_153 ( V_47 ) ;
return - V_165 ;
}
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_57 -> V_47 = V_47 ;
V_57 -> V_126 = V_126 ;
V_57 -> V_159 = V_26 ;
if ( ! V_26 )
F_138 ( V_47 ) ;
return F_176 ( V_57 ) ;
}
static void F_179 ( struct V_56 * V_57 , bool V_160 )
{
struct V_27 V_28 ;
struct V_47 * V_47 = V_57 -> V_47 ;
F_19 ( & V_28 ) ;
if ( F_167 ( V_47 -> V_53 , V_57 -> V_55 , & V_28 ) )
F_45 ( V_47 , V_57 -> V_55 ) ;
if ( ! V_160 && V_57 -> V_159 )
F_180 ( V_57 -> V_159 ) ;
F_50 ( V_57 ) ;
F_67 ( V_47 , & V_28 ) ;
F_153 ( V_47 ) ;
}
static void F_181 ( struct V_14 * V_15 )
{
struct V_56 * V_57 = F_157 ( V_15 ) ;
F_179 ( V_57 , ! V_57 -> V_13 . V_16 ) ;
}
static int F_182 ( struct V_47 * V_47 , T_5 V_84 )
{
int V_9 = F_183 ( V_47 -> V_86 , V_84 ) ;
if ( ! V_9 ) {
V_9 = F_171 ( V_47 -> V_121 , V_84 ) ;
if ( V_9 ) {
F_128 ( L_17 ,
F_116 ( V_47 ) ) ;
F_130 ( V_47 , L_14 , V_9 ) ;
}
} else if ( V_9 == - V_167 ) {
V_9 = 0 ;
} else
F_123 ( L_18 , F_116 ( V_47 ) ) ;
return V_9 ;
}
static void F_184 ( struct V_14 * V_15 )
{
int V_9 ;
struct V_56 * V_57 = F_157 ( V_15 ) ;
struct V_47 * V_47 = V_57 -> V_47 ;
V_9 = F_182 ( V_47 , V_57 -> F_182 ) ;
if ( V_9 ) {
F_179 ( V_57 , false ) ;
return;
}
F_11 ( & V_57 -> V_13 , F_181 ) ;
F_27 ( & V_47 -> V_162 , & V_57 -> V_13 ) ;
F_101 ( V_47 , V_57 -> V_159 , V_57 -> V_168 ) ;
V_57 -> V_159 = NULL ;
F_31 ( & V_47 -> V_162 ) ;
}
static int F_185 ( struct V_56 * V_57 )
{
int V_9 ;
struct V_63 V_64 ;
struct V_47 * V_47 = V_57 -> V_47 ;
struct V_52 * V_164 ;
V_164 = F_43 ( V_47 ) ;
if ( ! V_164 ) {
F_179 ( V_57 , false ) ;
return - V_165 ;
}
F_57 ( V_57 -> V_168 , F_54 ( V_57 -> V_168 ) , & V_64 ) ;
V_9 = F_177 ( V_47 -> V_53 , & V_64 ,
V_71 , V_164 , & V_57 -> V_55 ) ;
if ( V_9 < 0 ) {
F_45 ( V_47 , V_164 ) ;
F_179 ( V_57 , false ) ;
return V_9 ;
}
if ( V_57 -> V_55 != V_164 )
F_45 ( V_47 , V_164 ) ;
if ( V_9 )
F_155 ( V_57 , F_184 ) ;
else {
F_11 ( & V_57 -> V_13 , F_184 ) ;
F_15 ( V_47 -> V_18 , & V_57 -> V_13 . V_15 ) ;
}
return 0 ;
}
static int F_186 ( struct V_47 * V_47 , T_5 V_84 ,
T_3 V_80 , struct V_26 * V_26 )
{
struct V_56 * V_57 ;
if ( ! F_151 ( V_47 ) )
return - V_166 ;
V_57 = F_47 ( V_47 ) ;
if ( ! V_57 ) {
F_153 ( V_47 ) ;
return - V_165 ;
}
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_57 -> V_47 = V_47 ;
V_57 -> V_159 = V_26 ;
V_57 -> F_182 = V_84 ;
V_57 -> V_168 = V_80 ;
return F_185 ( V_57 ) ;
}
static enum V_169 F_187 ( struct V_47 * V_47 )
{
bool V_170 = F_5 ( & V_47 -> V_110 , V_171 ) ;
T_1 V_172 = ( F_135 ( & V_47 -> V_144 ) + 1 ) *
V_47 -> V_93 ;
if ( V_170 && V_172 <= V_47 -> V_173 )
return V_174 ;
else
return V_175 ;
}
static void F_188 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
F_49 ( F_59 ( V_26 ) == V_176 ?
& V_47 -> V_95 . V_128 : & V_47 -> V_95 . V_132 ) ;
}
static void F_189 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
F_49 ( F_59 ( V_26 ) == V_176 ?
& V_47 -> V_95 . V_130 : & V_47 -> V_95 . V_134 ) ;
}
static bool F_190 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
return ( F_59 ( V_26 ) == V_69 ) &&
( V_26 -> V_102 . V_177 == ( V_47 -> V_93 << V_178 ) ) ;
}
static bool F_191 ( struct V_47 * V_47 , struct V_26 * V_26 , T_3 V_103 )
{
return F_37 ( & V_47 -> V_50 ) &&
( F_94 ( V_47 , V_103 ) || F_190 ( V_47 , V_26 ) ) ;
}
static int F_192 ( struct V_47 * V_47 , struct V_26 * V_26 , T_3 V_103 ,
bool * V_179 )
{
int V_9 , V_180 ;
bool V_181 , V_182 ;
T_5 V_84 ;
T_4 V_105 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_105 ) ;
* V_179 = false ;
V_181 = F_68 ( V_47 , V_103 , V_26 ) ;
if ( ! V_181 ) {
* V_179 = true ;
return V_183 ;
}
V_180 = F_59 ( V_26 ) ;
if ( F_191 ( V_47 , V_26 , V_103 ) ) {
struct V_161 * V_126 = NULL ;
V_9 = F_193 ( V_47 -> V_86 , V_103 , & V_84 , V_180 , true , & V_126 ) ;
if ( F_39 ( V_9 && V_9 != - V_184 ) ) {
F_128 ( L_19 ,
F_116 ( V_47 ) , V_9 ) ;
F_180 ( V_26 ) ;
return V_183 ;
}
if ( V_9 == - V_184 && V_126 ) {
F_161 ( V_47 , V_26 ) ;
F_63 ( V_126 -> V_126 != V_138 ) ;
F_178 ( V_47 , V_126 , V_26 ) ;
return V_183 ;
}
} else {
V_9 = F_194 ( V_47 -> V_86 , V_103 , & V_84 , V_180 , false , & V_182 ) ;
if ( F_39 ( V_9 && V_9 != - V_184 ) ) {
F_128 ( L_20 ,
F_116 ( V_47 ) , V_9 ) ;
F_180 ( V_26 ) ;
return V_183 ;
}
if ( V_182 )
F_42 ( V_47 ) ;
}
if ( V_9 == - V_184 ) {
F_189 ( V_47 , V_26 ) ;
if ( V_76 -> V_78 == 0 ) {
F_105 ( V_47 , V_26 ) ;
F_101 ( V_47 , V_26 , V_103 ) ;
} else {
F_24 ( V_26 ) ;
return V_183 ;
}
} else {
F_188 ( V_47 , V_26 ) ;
if ( F_38 ( & V_47 -> V_50 ) ) {
if ( F_59 ( V_26 ) == V_69 ) {
F_161 ( V_47 , V_26 ) ;
F_49 ( & V_47 -> V_95 . V_141 ) ;
F_186 ( V_47 , V_84 , V_103 , V_26 ) ;
} else
F_101 ( V_47 , V_26 , V_103 ) ;
} else {
if ( F_59 ( V_26 ) == V_69 && F_36 ( & V_47 -> V_50 ) &&
! F_70 ( V_47 , V_84 ) ) {
F_113 ( V_47 , V_26 , V_103 , V_84 ) ;
F_105 ( V_47 , V_26 ) ;
} else
F_102 ( V_47 , V_26 , V_103 , V_84 ) ;
}
}
if ( V_26 -> V_107 & V_185 ) {
F_107 ( V_47 , V_26 ) ;
F_29 ( & V_47 -> V_162 , V_26 ) ;
* V_179 = true ;
return V_183 ;
}
return V_186 ;
}
static bool F_195 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
bool V_179 ;
if ( F_192 ( V_47 , V_26 , F_103 ( V_47 , V_26 ) , & V_179 ) == V_186 )
F_109 ( V_26 ) ;
return V_179 ;
}
static int F_196 ( struct V_47 * V_47 , bool V_187 )
{
int V_9 ;
if ( F_115 ( V_47 ) >= V_124 )
return - V_188 ;
F_49 ( & V_47 -> V_95 . V_189 ) ;
V_9 = F_197 ( V_47 -> V_121 , V_187 ) ;
if ( V_9 )
F_130 ( V_47 , L_21 , V_9 ) ;
return V_9 ;
}
static int V_30 ( void * V_111 )
{
struct V_47 * V_47 = V_111 ;
if ( F_198 ( V_47 -> V_121 ) )
return F_196 ( V_47 , false ) ;
return 0 ;
}
static bool F_199 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
T_4 V_105 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_105 ) ;
if ( ! V_76 -> V_78 )
F_95 ( V_47 , V_26 ) ;
else
F_96 ( V_47 , V_26 , 0 ) ;
F_29 ( & V_47 -> V_162 , V_26 ) ;
return true ;
}
static bool F_200 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
T_9 V_21 , V_145 ;
F_142 ( V_47 , V_26 , & V_21 , & V_145 ) ;
while ( V_21 != V_145 ) {
F_88 ( V_47 , V_21 ) ;
V_21 = F_87 ( F_89 ( V_21 ) + 1 ) ;
}
F_24 ( V_26 ) ;
return false ;
}
static void F_201 ( struct V_14 * V_15 )
{
struct V_47 * V_47 = F_17 ( V_15 , struct V_47 , V_48 ) ;
unsigned long V_10 ;
bool V_179 = false ;
struct V_27 V_28 ;
struct V_26 * V_26 ;
F_19 ( & V_28 ) ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
F_21 ( & V_28 , & V_47 -> V_79 ) ;
F_19 ( & V_47 -> V_79 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
while ( ( V_26 = F_23 ( & V_28 ) ) ) {
if ( V_26 -> V_107 & V_190 )
V_179 = F_199 ( V_47 , V_26 ) || V_179 ;
else if ( F_100 ( V_26 ) == V_108 )
V_179 = F_200 ( V_47 , V_26 ) || V_179 ;
else
V_179 = F_195 ( V_47 , V_26 ) || V_179 ;
}
if ( V_179 )
F_31 ( & V_47 -> V_162 ) ;
}
static void F_202 ( struct V_14 * V_15 )
{
struct V_47 * V_47 = F_17 ( V_15 , struct V_47 , V_49 ) ;
unsigned long V_10 ;
struct V_27 V_28 ;
struct V_26 * V_26 ;
F_19 ( & V_28 ) ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
F_21 ( & V_28 , & V_47 -> V_112 ) ;
F_19 ( & V_47 -> V_112 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
while ( ( V_26 = F_23 ( & V_28 ) ) )
F_109 ( V_26 ) ;
}
static void F_203 ( struct V_47 * V_47 )
{
struct V_26 * V_26 ;
struct V_27 V_28 ;
F_19 ( & V_28 ) ;
F_21 ( & V_28 , & V_47 -> V_79 ) ;
F_19 ( & V_47 -> V_79 ) ;
while ( ( V_26 = F_23 ( & V_28 ) ) ) {
V_26 -> V_33 = V_191 ;
F_24 ( V_26 ) ;
}
}
static void F_204 ( struct V_14 * V_15 )
{
struct V_47 * V_47 = F_17 ( F_205 ( V_15 ) , struct V_47 , V_192 ) ;
F_206 ( V_47 -> V_86 , true ) ;
F_42 ( V_47 ) ;
F_31 ( & V_47 -> V_162 ) ;
F_207 ( V_47 -> V_18 , & V_47 -> V_192 , V_193 ) ;
}
static void F_208 ( struct V_14 * V_15 )
{
int V_9 ;
struct V_161 * V_126 ;
struct V_47 * V_47 = F_17 ( V_15 , struct V_47 , V_51 ) ;
enum V_169 V_21 ;
for (; ; ) {
V_21 = F_187 ( V_47 ) ;
V_9 = F_209 ( V_47 -> V_86 , V_21 == V_174 , & V_126 ) ;
if ( V_9 == - V_167 )
break;
if ( V_9 ) {
F_128 ( L_22 ,
F_116 ( V_47 ) ) ;
break;
}
V_9 = F_178 ( V_47 , V_126 , NULL ) ;
if ( V_9 )
break;
}
}
static void F_210 ( struct V_47 * V_47 )
{
unsigned V_194 ;
F_211 ( V_47 -> V_58 ) ;
if ( V_47 -> V_53 )
F_212 ( V_47 -> V_53 ) ;
if ( V_47 -> V_18 )
F_213 ( V_47 -> V_18 ) ;
if ( V_47 -> V_83 )
F_214 ( V_47 -> V_83 ) ;
if ( V_47 -> V_97 )
F_214 ( V_47 -> V_97 ) ;
if ( V_47 -> V_158 )
F_215 ( V_47 -> V_158 ) ;
if ( V_47 -> V_121 )
F_216 ( V_47 -> V_121 ) ;
if ( V_47 -> V_195 )
F_217 ( V_47 -> V_87 , V_47 -> V_195 ) ;
if ( V_47 -> V_99 )
F_217 ( V_47 -> V_87 , V_47 -> V_99 ) ;
if ( V_47 -> V_104 )
F_217 ( V_47 -> V_87 , V_47 -> V_104 ) ;
if ( V_47 -> V_86 )
F_218 ( V_47 -> V_86 ) ;
for ( V_194 = 0 ; V_194 < V_47 -> V_196 ; V_194 ++ )
F_219 ( V_47 -> V_197 [ V_194 ] ) ;
F_219 ( V_47 -> V_197 ) ;
F_219 ( V_47 ) ;
}
static void F_220 ( struct V_198 * V_87 )
{
struct V_47 * V_47 = V_87 -> V_199 ;
F_210 ( V_47 ) ;
}
static T_1 F_221 ( struct V_200 * V_66 )
{
return F_222 ( V_66 -> V_100 -> V_201 ) >> V_178 ;
}
static void F_223 ( struct V_202 * V_203 )
{
if ( V_203 -> V_195 )
F_217 ( V_203 -> V_87 , V_203 -> V_195 ) ;
if ( V_203 -> V_104 )
F_217 ( V_203 -> V_87 , V_203 -> V_104 ) ;
if ( V_203 -> V_99 )
F_217 ( V_203 -> V_87 , V_203 -> V_99 ) ;
F_219 ( V_203 ) ;
}
static bool F_224 ( struct V_204 * V_205 , char * * error )
{
if ( ! V_205 -> V_206 ) {
* error = L_23 ;
return false ;
}
return true ;
}
static int F_225 ( struct V_202 * V_203 , struct V_204 * V_205 ,
char * * error )
{
int V_9 ;
T_1 V_207 ;
char V_21 [ V_208 ] ;
if ( ! F_224 ( V_205 , error ) )
return - V_188 ;
V_9 = F_226 ( V_203 -> V_87 , F_227 ( V_205 ) , V_209 | V_210 ,
& V_203 -> V_195 ) ;
if ( V_9 ) {
* error = L_24 ;
return V_9 ;
}
V_207 = F_221 ( V_203 -> V_195 ) ;
if ( V_207 > V_211 )
F_228 ( L_25 ,
F_229 ( V_203 -> V_195 -> V_100 , V_21 ) , V_212 ) ;
return 0 ;
}
static int F_230 ( struct V_202 * V_203 , struct V_204 * V_205 ,
char * * error )
{
int V_9 ;
if ( ! F_224 ( V_205 , error ) )
return - V_188 ;
V_9 = F_226 ( V_203 -> V_87 , F_227 ( V_205 ) , V_209 | V_210 ,
& V_203 -> V_104 ) ;
if ( V_9 ) {
* error = L_26 ;
return V_9 ;
}
V_203 -> V_213 = F_221 ( V_203 -> V_104 ) ;
return 0 ;
}
static int F_231 ( struct V_202 * V_203 , struct V_204 * V_205 ,
char * * error )
{
int V_9 ;
if ( ! F_224 ( V_205 , error ) )
return - V_188 ;
V_9 = F_226 ( V_203 -> V_87 , F_227 ( V_205 ) , V_209 | V_210 ,
& V_203 -> V_99 ) ;
if ( V_9 ) {
* error = L_27 ;
return V_9 ;
}
V_203 -> V_214 = F_221 ( V_203 -> V_99 ) ;
if ( V_203 -> V_87 -> V_11 > V_203 -> V_214 ) {
* error = L_28 ;
return - V_188 ;
}
return 0 ;
}
static int F_232 ( struct V_202 * V_203 , struct V_204 * V_205 ,
char * * error )
{
unsigned long V_215 ;
if ( ! F_224 ( V_205 , error ) )
return - V_188 ;
if ( F_233 ( F_227 ( V_205 ) , 10 , & V_215 ) || ! V_215 ||
V_215 < V_216 ||
V_215 > V_217 ||
V_215 & ( V_216 - 1 ) ) {
* error = L_29 ;
return - V_188 ;
}
if ( V_215 > V_203 -> V_213 ) {
* error = L_30 ;
return - V_188 ;
}
V_203 -> V_215 = V_215 ;
return 0 ;
}
static void F_234 ( struct V_41 * V_218 )
{
V_218 -> V_116 = V_123 ;
V_218 -> V_43 = V_45 ;
V_218 -> V_219 = 1 ;
}
static int F_235 ( struct V_202 * V_203 , struct V_204 * V_205 ,
char * * error )
{
static struct V_220 V_221 [] = {
{ 0 , 2 , L_31 } ,
} ;
int V_9 ;
unsigned V_206 ;
const char * V_222 ;
struct V_41 * V_218 = & V_203 -> V_50 ;
F_234 ( V_218 ) ;
V_9 = F_236 ( V_221 , V_205 , & V_206 , error ) ;
if ( V_9 )
return - V_188 ;
while ( V_206 -- ) {
V_222 = F_227 ( V_205 ) ;
if ( ! strcasecmp ( V_222 , L_32 ) )
V_218 -> V_43 = V_45 ;
else if ( ! strcasecmp ( V_222 , L_33 ) )
V_218 -> V_43 = V_44 ;
else if ( ! strcasecmp ( V_222 , L_34 ) )
V_218 -> V_43 = V_46 ;
else if ( ! strcasecmp ( V_222 , L_35 ) )
V_218 -> V_219 = 2 ;
else {
* error = L_36 ;
return - V_188 ;
}
}
return 0 ;
}
static int F_237 ( struct V_202 * V_203 , struct V_204 * V_205 ,
char * * error )
{
static struct V_220 V_221 [] = {
{ 0 , 1024 , L_37 } ,
} ;
int V_9 ;
if ( ! F_224 ( V_205 , error ) )
return - V_188 ;
V_203 -> V_223 = F_227 ( V_205 ) ;
V_9 = F_236 ( V_221 , V_205 , & V_203 -> V_224 , error ) ;
if ( V_9 )
return - V_188 ;
V_203 -> V_225 = ( const char * * ) V_205 -> V_226 ;
F_238 ( V_205 , V_203 -> V_224 ) ;
return 0 ;
}
static int F_239 ( struct V_202 * V_203 , int V_206 , char * * V_226 ,
char * * error )
{
int V_9 ;
struct V_204 V_205 ;
V_205 . V_206 = V_206 ;
V_205 . V_226 = V_226 ;
V_9 = F_225 ( V_203 , & V_205 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_230 ( V_203 , & V_205 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_231 ( V_203 , & V_205 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_232 ( V_203 , & V_205 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_235 ( V_203 , & V_205 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_237 ( V_203 , & V_205 , error ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_240 ( struct V_47 * V_47 , const char * V_64 , const char * V_227 )
{
unsigned long V_25 ;
if ( ! strcasecmp ( V_64 , L_38 ) ) {
if ( F_233 ( V_227 , 10 , & V_25 ) )
return - V_188 ;
V_47 -> V_173 = V_25 ;
return 0 ;
}
return V_228 ;
}
static int F_241 ( struct V_47 * V_47 , const char * V_64 , const char * V_227 )
{
int V_9 = F_240 ( V_47 , V_64 , V_227 ) ;
if ( V_9 == V_228 )
V_9 = F_242 ( V_47 -> V_86 , V_64 , V_227 ) ;
if ( V_9 )
F_228 ( L_39 , V_64 , V_227 ) ;
return V_9 ;
}
static int F_243 ( struct V_47 * V_47 , int V_206 , const char * * V_226 )
{
int V_9 = 0 ;
if ( V_206 & 1 ) {
F_228 ( L_40 ) ;
return - V_188 ;
}
while ( V_206 ) {
V_9 = F_241 ( V_47 , V_226 [ 0 ] , V_226 [ 1 ] ) ;
if ( V_9 )
break;
V_206 -= 2 ;
V_226 += 2 ;
}
return V_9 ;
}
static int F_244 ( struct V_47 * V_47 , struct V_202 * V_203 ,
char * * error )
{
struct V_229 * V_230 = F_245 ( V_203 -> V_223 ,
V_47 -> V_231 ,
V_47 -> V_214 ,
V_47 -> V_93 ) ;
if ( F_246 ( V_230 ) ) {
* error = L_41 ;
return F_247 ( V_230 ) ;
}
V_47 -> V_86 = V_230 ;
F_63 ( ! V_47 -> V_86 ) ;
return 0 ;
}
static bool F_248 ( T_1 V_92 ,
T_1 V_232 )
{
( void ) F_97 ( V_232 , V_92 ) ;
return V_232 > V_233 ;
}
static T_1 F_249 ( T_1 V_234 ,
T_1 V_232 )
{
T_1 V_92 = V_234 ;
if ( V_232 )
while ( F_248 ( V_92 , V_232 ) )
V_92 *= 2 ;
return V_92 ;
}
static void F_250 ( struct V_47 * V_47 , T_5 V_235 )
{
T_7 V_236 = F_72 ( V_235 ) ;
if ( V_236 > ( 1 << 20 ) && V_47 -> V_231 != V_235 )
F_251 ( L_42
L_43
L_44 ,
( unsigned long long ) V_236 ) ;
V_47 -> V_231 = V_235 ;
}
static int F_252 ( struct V_200 * V_66 , int V_237 )
{
struct V_238 * V_239 = F_253 ( V_66 -> V_100 ) ;
return F_254 ( V_239 -> V_240 , V_237 ) ;
}
static int F_255 ( struct V_241 * V_242 , int V_237 )
{
struct V_47 * V_47 = F_17 ( V_242 , struct V_47 , V_243 ) ;
return F_252 ( V_47 -> V_99 , V_237 ) ||
F_252 ( V_47 -> V_104 , V_237 ) ;
}
static int F_256 ( struct V_202 * V_203 , struct V_47 * * V_244 )
{
int V_9 = 0 ;
char * * error = & V_203 -> V_87 -> error ;
struct V_47 * V_47 ;
struct V_198 * V_87 = V_203 -> V_87 ;
T_7 V_245 ;
struct V_246 * V_121 ;
bool V_247 = V_203 -> V_50 . V_116 == V_123 ;
V_47 = F_257 ( sizeof( * V_47 ) , V_248 ) ;
if ( ! V_47 )
return - V_165 ;
V_47 -> V_87 = V_203 -> V_87 ;
V_87 -> V_199 = V_47 ;
V_87 -> V_249 = 2 ;
V_87 -> V_250 = true ;
V_87 -> V_251 = 1 ;
V_87 -> V_252 = true ;
V_87 -> V_253 = false ;
V_47 -> V_50 = V_203 -> V_50 ;
V_87 -> V_254 = F_60 ( V_47 ) ;
V_47 -> V_243 . V_255 = F_255 ;
F_258 ( V_87 -> V_88 , & V_47 -> V_243 ) ;
V_47 -> V_195 = V_203 -> V_195 ;
V_47 -> V_99 = V_203 -> V_99 ;
V_47 -> V_104 = V_203 -> V_104 ;
V_203 -> V_195 = V_203 -> V_99 = V_203 -> V_104 = NULL ;
V_245 = V_47 -> V_214 = V_203 -> V_214 ;
V_245 = F_83 ( V_245 , V_203 -> V_215 ) ;
V_47 -> V_245 = F_55 ( V_245 ) ;
V_47 -> V_93 = V_203 -> V_215 ;
if ( F_259 ( V_87 , V_47 -> V_93 ) ) {
V_9 = - V_188 ;
goto V_256;
}
if ( V_203 -> V_215 & ( V_203 -> V_215 - 1 ) ) {
T_7 V_231 = V_203 -> V_213 ;
V_47 -> V_89 = - 1 ;
V_231 = F_83 ( V_231 , V_203 -> V_215 ) ;
F_250 ( V_47 , F_260 ( V_231 ) ) ;
} else {
V_47 -> V_89 = F_261 ( V_203 -> V_215 ) ;
F_250 ( V_47 , F_260 ( V_203 -> V_213 >> V_47 -> V_89 ) ) ;
}
V_9 = F_244 ( V_47 , V_203 , error ) ;
if ( V_9 )
goto V_256;
V_47 -> V_257 = V_203 -> V_224 ;
V_47 -> V_173 = V_258 ;
V_9 = F_243 ( V_47 , V_203 -> V_224 , V_203 -> V_225 ) ;
if ( V_9 ) {
* error = L_45 ;
goto V_256;
}
V_121 = F_262 ( V_47 -> V_195 -> V_100 ,
V_203 -> V_215 , V_247 ,
F_263 ( V_47 -> V_86 ) ,
V_203 -> V_50 . V_219 ) ;
if ( F_246 ( V_121 ) ) {
* error = L_46 ;
V_9 = F_247 ( V_121 ) ;
goto V_256;
}
V_47 -> V_121 = V_121 ;
F_121 ( V_47 , V_123 ) ;
if ( F_115 ( V_47 ) != V_123 ) {
* error = L_47 ;
V_9 = - V_188 ;
goto V_256;
}
if ( F_38 ( & V_47 -> V_50 ) ) {
bool V_259 ;
V_9 = F_264 ( V_47 -> V_121 , & V_259 ) ;
if ( V_9 ) {
* error = L_48 ;
goto V_256;
}
if ( ! V_259 ) {
* error = L_49 ;
V_9 = - V_188 ;
goto V_256;
}
F_265 ( V_47 -> V_86 , false ) ;
}
F_2 ( & V_47 -> V_3 ) ;
F_18 ( & V_47 -> V_260 ) ;
F_19 ( & V_47 -> V_79 ) ;
F_19 ( & V_47 -> V_112 ) ;
F_133 ( & V_47 -> V_59 , 0 ) ;
F_133 ( & V_47 -> V_144 , 0 ) ;
F_266 ( & V_47 -> V_60 ) ;
V_9 = - V_165 ;
F_133 ( & V_47 -> V_85 , 0 ) ;
V_47 -> V_83 = F_267 ( F_72 ( V_47 -> V_231 ) ) ;
if ( ! V_47 -> V_83 ) {
* error = L_50 ;
goto V_256;
}
F_268 ( V_47 -> V_83 , F_72 ( V_47 -> V_231 ) ) ;
V_47 -> V_92 =
F_249 ( V_47 -> V_93 ,
V_47 -> V_214 ) ;
V_47 -> V_94 = F_87 ( F_144 ( V_47 -> V_214 ,
V_47 -> V_92 ) ) ;
V_47 -> V_97 = F_267 ( F_89 ( V_47 -> V_94 ) ) ;
if ( ! V_47 -> V_97 ) {
* error = L_51 ;
goto V_256;
}
F_268 ( V_47 -> V_97 , F_89 ( V_47 -> V_94 ) ) ;
V_47 -> V_158 = F_269 ( & V_261 ) ;
if ( F_246 ( V_47 -> V_158 ) ) {
* error = L_52 ;
V_9 = F_247 ( V_47 -> V_158 ) ;
goto V_256;
}
V_47 -> V_18 = F_270 ( L_53 V_262 , V_263 , 0 ) ;
if ( ! V_47 -> V_18 ) {
* error = L_54 ;
goto V_256;
}
F_13 ( & V_47 -> V_48 , F_201 ) ;
F_13 ( & V_47 -> V_49 ,
F_202 ) ;
F_13 ( & V_47 -> V_51 , F_208 ) ;
F_271 ( & V_47 -> V_192 , F_204 ) ;
V_47 -> V_53 = F_272 ( V_47 -> V_18 ) ;
if ( ! V_47 -> V_53 ) {
* error = L_55 ;
goto V_256;
}
V_47 -> V_58 = F_273 ( V_264 ,
V_265 ) ;
if ( ! V_47 -> V_58 ) {
* error = L_56 ;
goto V_256;
}
V_47 -> V_106 = true ;
V_47 -> V_266 = false ;
V_47 -> V_267 = false ;
V_47 -> V_268 = false ;
V_47 -> V_269 = false ;
V_47 -> V_270 = false ;
F_131 ( V_47 ) ;
F_133 ( & V_47 -> V_95 . V_141 , 0 ) ;
F_133 ( & V_47 -> V_95 . V_139 , 0 ) ;
F_133 ( & V_47 -> V_95 . V_271 , 0 ) ;
F_133 ( & V_47 -> V_95 . V_272 , 0 ) ;
F_133 ( & V_47 -> V_95 . V_189 , 0 ) ;
F_133 ( & V_47 -> V_95 . V_96 , 0 ) ;
F_2 ( & V_47 -> V_273 ) ;
F_18 ( & V_47 -> V_274 ) ;
F_25 ( & V_47 -> V_162 , V_30 , V_47 ,
V_34 , V_47 , V_47 -> V_18 ) ;
F_1 ( & V_47 -> V_110 ) ;
F_274 ( & V_47 -> V_148 ) ;
F_145 ( V_47 ) ;
* V_244 = V_47 ;
return 0 ;
V_256:
F_210 ( V_47 ) ;
return V_9 ;
}
static int F_275 ( struct V_47 * V_47 , int V_206 , const char * * V_226 )
{
unsigned V_194 ;
const char * * F_159 ;
F_159 = F_276 ( V_206 , sizeof( * F_159 ) , V_248 ) ;
if ( ! F_159 )
return - V_165 ;
for ( V_194 = 0 ; V_194 < V_206 ; V_194 ++ ) {
F_159 [ V_194 ] = F_277 ( V_226 [ V_194 ] , V_248 ) ;
if ( ! F_159 [ V_194 ] ) {
while ( V_194 -- )
F_219 ( F_159 [ V_194 ] ) ;
F_219 ( F_159 ) ;
return - V_165 ;
}
}
V_47 -> V_196 = V_206 ;
V_47 -> V_197 = F_159 ;
return 0 ;
}
static int F_278 ( struct V_198 * V_87 , unsigned V_206 , char * * V_226 )
{
int V_9 = - V_188 ;
struct V_202 * V_203 ;
struct V_47 * V_47 = NULL ;
V_203 = F_257 ( sizeof( * V_203 ) , V_248 ) ;
if ( ! V_203 ) {
V_87 -> error = L_57 ;
return - V_165 ;
}
V_203 -> V_87 = V_87 ;
V_9 = F_239 ( V_203 , V_206 , V_226 , & V_87 -> error ) ;
if ( V_9 )
goto V_275;
V_9 = F_256 ( V_203 , & V_47 ) ;
if ( V_9 )
goto V_275;
V_9 = F_275 ( V_47 , V_206 - 3 , ( const char * * ) V_226 + 3 ) ;
if ( V_9 ) {
F_210 ( V_47 ) ;
goto V_275;
}
V_87 -> V_199 = V_47 ;
V_275:
F_223 ( V_203 ) ;
return V_9 ;
}
static int F_279 ( struct V_198 * V_87 , struct V_26 * V_26 )
{
struct V_47 * V_47 = V_87 -> V_199 ;
int V_9 ;
bool V_179 ;
T_3 V_103 = F_103 ( V_47 , V_26 ) ;
T_4 V_105 = F_60 ( V_47 ) ;
F_64 ( V_26 , V_105 ) ;
if ( F_39 ( F_56 ( V_103 ) >= F_56 ( V_47 -> V_245 ) ) ) {
F_95 ( V_47 , V_26 ) ;
F_105 ( V_47 , V_26 ) ;
return V_186 ;
}
if ( F_141 ( V_26 ) ) {
F_66 ( V_47 , V_26 ) ;
return V_183 ;
}
V_9 = F_192 ( V_47 , V_26 , V_103 , & V_179 ) ;
if ( V_179 )
F_31 ( & V_47 -> V_162 ) ;
return V_9 ;
}
static int F_280 ( struct V_198 * V_87 , struct V_26 * V_26 , int error )
{
struct V_47 * V_47 = V_87 -> V_199 ;
unsigned long V_10 ;
T_4 V_105 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_105 ) ;
if ( V_76 -> V_77 ) {
F_206 ( V_47 -> V_86 , false ) ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
V_47 -> V_106 = true ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
}
F_161 ( V_47 , V_26 ) ;
F_107 ( V_47 , V_26 ) ;
return 0 ;
}
static int F_281 ( struct V_47 * V_47 )
{
int V_9 ;
if ( F_115 ( V_47 ) >= V_124 )
return - V_188 ;
V_9 = F_282 ( V_47 -> V_121 , F_72 ( V_47 -> V_231 ) , V_47 -> V_83 ) ;
if ( V_9 )
F_130 ( V_47 , L_58 , V_9 ) ;
return V_9 ;
}
static int F_283 ( struct V_47 * V_47 )
{
unsigned V_194 , V_9 ;
if ( F_115 ( V_47 ) >= V_124 )
return - V_188 ;
V_9 = F_284 ( V_47 -> V_121 , V_47 -> V_92 ,
V_47 -> V_94 ) ;
if ( V_9 ) {
F_123 ( L_59 , F_116 ( V_47 ) ) ;
F_130 ( V_47 , L_60 , V_9 ) ;
return V_9 ;
}
for ( V_194 = 0 ; V_194 < F_89 ( V_47 -> V_94 ) ; V_194 ++ ) {
V_9 = F_285 ( V_47 -> V_121 , F_87 ( V_194 ) ,
F_93 ( V_47 , F_87 ( V_194 ) ) ) ;
if ( V_9 ) {
F_130 ( V_47 , L_61 , V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
static int F_286 ( struct V_47 * V_47 )
{
int V_9 ;
if ( F_115 ( V_47 ) >= V_124 )
return - V_188 ;
V_9 = F_287 ( V_47 -> V_121 , V_47 -> V_86 ) ;
if ( V_9 ) {
F_130 ( V_47 , L_62 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static bool F_288 ( struct V_47 * V_47 )
{
int V_276 , V_277 , V_278 , V_279 ;
V_276 = F_281 ( V_47 ) ;
if ( V_276 )
F_123 ( L_63 , F_116 ( V_47 ) ) ;
V_277 = F_283 ( V_47 ) ;
if ( V_277 )
F_123 ( L_64 , F_116 ( V_47 ) ) ;
F_134 ( V_47 ) ;
V_278 = F_286 ( V_47 ) ;
if ( V_278 )
F_123 ( L_65 , F_116 ( V_47 ) ) ;
V_279 = F_196 ( V_47 , ! V_276 && ! V_277 && ! V_278 ) ;
if ( V_279 )
F_123 ( L_66 , F_116 ( V_47 ) ) ;
return ! V_276 && ! V_277 && ! V_278 && ! V_279 ;
}
static void F_289 ( struct V_198 * V_87 )
{
struct V_47 * V_47 = V_87 -> V_199 ;
F_145 ( V_47 ) ;
F_63 ( F_135 ( & V_47 -> V_144 ) ) ;
F_290 ( & V_47 -> V_192 ) ;
F_291 ( V_47 -> V_18 ) ;
F_292 ( V_47 -> V_110 . V_4 ) ;
F_203 ( V_47 ) ;
if ( F_115 ( V_47 ) == V_123 )
( void ) F_288 ( V_47 ) ;
}
static int F_293 ( void * V_111 , T_3 V_80 , T_5 V_84 ,
bool V_280 , T_8 V_281 , bool V_282 )
{
int V_9 ;
struct V_47 * V_47 = V_111 ;
if ( V_280 ) {
F_90 ( F_72 ( V_84 ) , V_47 -> V_83 ) ;
F_49 ( & V_47 -> V_85 ) ;
} else
F_92 ( F_72 ( V_84 ) , V_47 -> V_83 ) ;
V_9 = F_294 ( V_47 -> V_86 , V_80 , V_84 , V_280 , V_281 , V_282 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static void F_295 ( struct V_47 * V_47 ,
struct V_283 * V_284 )
{
V_284 -> V_47 = V_47 ;
V_284 -> V_285 = V_284 -> V_286 = 0 ;
}
static void F_296 ( struct V_283 * V_284 )
{
T_1 V_21 , V_145 ;
if ( V_284 -> V_285 == V_284 -> V_286 )
return;
V_21 = V_284 -> V_285 * V_284 -> V_215 ;
V_145 = V_284 -> V_286 * V_284 -> V_215 ;
V_21 = F_144 ( V_21 , V_284 -> V_47 -> V_92 ) ;
F_97 ( V_145 , V_284 -> V_47 -> V_92 ) ;
if ( V_145 > F_89 ( V_284 -> V_47 -> V_94 ) )
V_145 = F_89 ( V_284 -> V_47 -> V_94 ) ;
for (; V_21 < V_145 ; V_21 ++ )
F_88 ( V_284 -> V_47 , F_87 ( V_21 ) ) ;
}
static int F_297 ( void * V_111 , T_1 V_92 ,
T_9 V_287 , bool V_288 )
{
struct V_283 * V_284 = V_111 ;
V_284 -> V_215 = V_92 ;
if ( V_288 ) {
if ( F_89 ( V_287 ) == V_284 -> V_286 )
V_284 -> V_286 = V_284 -> V_286 + 1ULL ;
else {
F_296 ( V_284 ) ;
V_284 -> V_285 = F_89 ( V_287 ) ;
V_284 -> V_286 = V_284 -> V_285 + 1ULL ;
}
} else {
F_296 ( V_284 ) ;
V_284 -> V_285 = V_284 -> V_286 = 0 ;
}
return 0 ;
}
static T_5 F_298 ( struct V_47 * V_47 )
{
T_1 V_235 = F_221 ( V_47 -> V_104 ) ;
( void ) F_97 ( V_235 , V_47 -> V_93 ) ;
return F_260 ( V_235 ) ;
}
static bool F_299 ( struct V_47 * V_47 , T_5 V_289 )
{
if ( F_72 ( V_289 ) > F_72 ( V_47 -> V_231 ) )
return true ;
while ( F_72 ( V_289 ) < F_72 ( V_47 -> V_231 ) ) {
V_289 = F_260 ( F_72 ( V_289 ) + 1 ) ;
if ( F_70 ( V_47 , V_289 ) ) {
F_123 ( L_67 ,
F_116 ( V_47 ) ,
( unsigned long long ) F_72 ( V_289 ) ) ;
return false ;
}
}
return true ;
}
static int F_300 ( struct V_47 * V_47 , T_5 V_289 )
{
int V_9 ;
V_9 = F_301 ( V_47 -> V_121 , V_289 ) ;
if ( V_9 ) {
F_123 ( L_68 , F_116 ( V_47 ) ) ;
F_130 ( V_47 , L_69 , V_9 ) ;
return V_9 ;
}
F_250 ( V_47 , V_289 ) ;
return 0 ;
}
static int F_302 ( struct V_198 * V_87 )
{
int V_9 = 0 ;
struct V_47 * V_47 = V_87 -> V_199 ;
T_5 V_290 = F_298 ( V_47 ) ;
if ( ! V_47 -> V_266 ) {
V_9 = F_300 ( V_47 , V_290 ) ;
if ( V_9 )
return V_9 ;
V_47 -> V_266 = true ;
} else if ( V_290 != V_47 -> V_231 ) {
if ( ! F_299 ( V_47 , V_290 ) )
return - V_188 ;
V_9 = F_300 ( V_47 , V_290 ) ;
if ( V_9 )
return V_9 ;
}
if ( ! V_47 -> V_269 ) {
V_9 = F_303 ( V_47 -> V_121 , V_47 -> V_86 ,
F_293 , V_47 ) ;
if ( V_9 ) {
F_123 ( L_70 , F_116 ( V_47 ) ) ;
F_130 ( V_47 , L_71 , V_9 ) ;
return V_9 ;
}
V_47 -> V_269 = true ;
}
if ( ! V_47 -> V_270 ) {
struct V_283 V_284 ;
F_268 ( V_47 -> V_97 , F_89 ( V_47 -> V_94 ) ) ;
F_295 ( V_47 , & V_284 ) ;
V_9 = F_304 ( V_47 -> V_121 , F_297 , & V_284 ) ;
if ( V_9 ) {
F_123 ( L_72 , F_116 ( V_47 ) ) ;
F_130 ( V_47 , L_73 , V_9 ) ;
return V_9 ;
}
F_296 ( & V_284 ) ;
V_47 -> V_270 = true ;
}
return V_9 ;
}
static void F_305 ( struct V_198 * V_87 )
{
struct V_47 * V_47 = V_87 -> V_199 ;
V_47 -> V_106 = true ;
F_149 ( V_47 ) ;
F_204 ( & V_47 -> V_192 . V_291 ) ;
}
static void F_306 ( struct V_198 * V_87 , T_10 type ,
unsigned V_292 , char * V_244 , unsigned V_293 )
{
int V_9 = 0 ;
unsigned V_194 ;
T_11 V_294 = 0 ;
T_7 V_295 = 0 ;
T_7 V_296 = 0 ;
char V_297 [ V_208 ] ;
struct V_47 * V_47 = V_87 -> V_199 ;
T_5 V_298 ;
bool V_119 ;
switch ( type ) {
case V_299 :
if ( F_115 ( V_47 ) == V_122 ) {
F_307 ( L_74 ) ;
break;
}
if ( ! ( V_292 & V_300 ) && ! F_308 ( V_87 ) )
( void ) F_196 ( V_47 , false ) ;
V_9 = F_309 ( V_47 -> V_121 , & V_295 ) ;
if ( V_9 ) {
F_123 ( L_75 ,
F_116 ( V_47 ) , V_9 ) ;
goto V_301;
}
V_9 = F_310 ( V_47 -> V_121 , & V_296 ) ;
if ( V_9 ) {
F_123 ( L_76 ,
F_116 ( V_47 ) , V_9 ) ;
goto V_301;
}
V_298 = F_311 ( V_47 -> V_86 ) ;
F_307 ( L_77 ,
( unsigned ) V_302 ,
( unsigned long long ) ( V_296 - V_295 ) ,
( unsigned long long ) V_296 ,
( unsigned long long ) V_47 -> V_93 ,
( unsigned long long ) F_72 ( V_298 ) ,
( unsigned long long ) F_72 ( V_47 -> V_231 ) ,
( unsigned ) F_135 ( & V_47 -> V_95 . V_128 ) ,
( unsigned ) F_135 ( & V_47 -> V_95 . V_130 ) ,
( unsigned ) F_135 ( & V_47 -> V_95 . V_132 ) ,
( unsigned ) F_135 ( & V_47 -> V_95 . V_134 ) ,
( unsigned ) F_135 ( & V_47 -> V_95 . V_141 ) ,
( unsigned ) F_135 ( & V_47 -> V_95 . V_139 ) ,
( unsigned long ) F_135 ( & V_47 -> V_85 ) ) ;
if ( V_47 -> V_50 . V_219 == 2 )
F_307 ( L_78 ) ;
else
F_307 ( L_79 ) ;
if ( F_36 ( & V_47 -> V_50 ) )
F_307 ( L_80 ) ;
else if ( F_38 ( & V_47 -> V_50 ) )
F_307 ( L_81 ) ;
else if ( F_37 ( & V_47 -> V_50 ) )
F_307 ( L_82 ) ;
else {
F_123 ( L_83 ,
F_116 ( V_47 ) , ( int ) V_47 -> V_50 . V_43 ) ;
goto V_301;
}
F_307 ( L_84 , ( unsigned long long ) V_47 -> V_173 ) ;
F_307 ( L_85 , F_312 ( V_47 -> V_86 ) ) ;
if ( V_294 < V_293 ) {
V_9 = F_313 ( V_47 -> V_86 , V_244 , V_293 , & V_294 ) ;
if ( V_9 )
F_123 ( L_86 ,
F_116 ( V_47 ) , V_9 ) ;
}
if ( F_115 ( V_47 ) == V_124 )
F_307 ( L_87 ) ;
else
F_307 ( L_88 ) ;
V_9 = F_122 ( V_47 -> V_121 , & V_119 ) ;
if ( V_9 || V_119 )
F_307 ( L_89 ) ;
else
F_307 ( L_90 ) ;
break;
case V_303 :
F_314 ( V_297 , V_47 -> V_195 -> V_100 -> V_304 ) ;
F_307 ( L_85 , V_297 ) ;
F_314 ( V_297 , V_47 -> V_104 -> V_100 -> V_304 ) ;
F_307 ( L_85 , V_297 ) ;
F_314 ( V_297 , V_47 -> V_99 -> V_100 -> V_304 ) ;
F_307 ( L_91 , V_297 ) ;
for ( V_194 = 0 ; V_194 < V_47 -> V_196 - 1 ; V_194 ++ )
F_307 ( L_92 , V_47 -> V_197 [ V_194 ] ) ;
if ( V_47 -> V_196 )
F_307 ( L_92 , V_47 -> V_197 [ V_47 -> V_196 - 1 ] ) ;
}
return;
V_301:
F_307 ( L_93 ) ;
}
static int F_315 ( struct V_47 * V_47 , const char * V_305 ,
struct V_306 * V_244 )
{
char V_307 ;
T_12 V_21 , V_145 ;
int V_9 ;
V_9 = sscanf ( V_305 , L_94 , & V_21 , & V_145 , & V_307 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 2 ) {
V_244 -> V_61 = F_260 ( V_21 ) ;
V_244 -> V_62 = F_260 ( V_145 ) ;
return 0 ;
}
V_9 = sscanf ( V_305 , L_95 , & V_21 , & V_307 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 1 ) {
V_244 -> V_61 = F_260 ( V_21 ) ;
V_244 -> V_62 = F_260 ( F_72 ( V_244 -> V_61 ) + 1u ) ;
return 0 ;
}
F_123 ( L_96 , F_116 ( V_47 ) , V_305 ) ;
return - V_188 ;
}
static int F_316 ( struct V_47 * V_47 , struct V_306 * V_308 )
{
T_12 V_21 = F_72 ( V_308 -> V_61 ) ;
T_12 V_145 = F_72 ( V_308 -> V_62 ) ;
T_12 V_90 = F_72 ( V_47 -> V_231 ) ;
if ( V_21 >= V_90 ) {
F_123 ( L_97 ,
F_116 ( V_47 ) , V_21 , V_90 ) ;
return - V_188 ;
}
if ( V_145 > V_90 ) {
F_123 ( L_98 ,
F_116 ( V_47 ) , V_145 , V_90 ) ;
return - V_188 ;
}
if ( V_21 >= V_145 ) {
F_123 ( L_99 ,
F_116 ( V_47 ) , V_21 , V_145 ) ;
return - V_188 ;
}
return 0 ;
}
static inline T_5 F_317 ( T_5 V_21 )
{
return F_260 ( F_72 ( V_21 ) + 1 ) ;
}
static int F_318 ( struct V_47 * V_47 , struct V_306 * V_308 )
{
int V_9 = 0 ;
while ( V_308 -> V_61 != V_308 -> V_62 ) {
V_9 = F_182 ( V_47 , V_308 -> V_61 ) ;
if ( V_9 )
return V_9 ;
V_308 -> V_61 = F_317 ( V_308 -> V_61 ) ;
}
V_47 -> V_268 = true ;
return V_9 ;
}
static int F_319 ( struct V_47 * V_47 , unsigned V_157 ,
const char * * V_309 )
{
int V_9 = 0 ;
unsigned V_194 ;
struct V_306 V_308 ;
if ( ! F_38 ( & V_47 -> V_50 ) ) {
F_123 ( L_100 ,
F_116 ( V_47 ) ) ;
return - V_166 ;
}
for ( V_194 = 0 ; V_194 < V_157 ; V_194 ++ ) {
V_9 = F_315 ( V_47 , V_309 [ V_194 ] , & V_308 ) ;
if ( V_9 )
break;
V_9 = F_316 ( V_47 , & V_308 ) ;
if ( V_9 )
break;
V_9 = F_318 ( V_47 , & V_308 ) ;
if ( V_9 )
break;
}
return V_9 ;
}
static int F_320 ( struct V_198 * V_87 , unsigned V_206 , char * * V_226 )
{
struct V_47 * V_47 = V_87 -> V_199 ;
if ( ! V_206 )
return - V_188 ;
if ( F_115 ( V_47 ) >= V_124 ) {
F_123 ( L_101 ,
F_116 ( V_47 ) ) ;
return - V_310 ;
}
if ( ! strcasecmp ( V_226 [ 0 ] , L_102 ) )
return F_319 ( V_47 , V_206 - 1 , ( const char * * ) V_226 + 1 ) ;
if ( V_206 != 2 )
return - V_188 ;
return F_241 ( V_47 , V_226 [ 0 ] , V_226 [ 1 ] ) ;
}
static int F_321 ( struct V_198 * V_87 ,
T_13 F_12 , void * V_311 )
{
int V_9 = 0 ;
struct V_47 * V_47 = V_87 -> V_199 ;
V_9 = F_12 ( V_87 , V_47 -> V_104 , 0 , F_221 ( V_47 -> V_104 ) , V_311 ) ;
if ( ! V_9 )
V_9 = F_12 ( V_87 , V_47 -> V_99 , 0 , V_87 -> V_11 , V_311 ) ;
return V_9 ;
}
static void F_322 ( struct V_47 * V_47 , struct V_312 * V_313 )
{
V_313 -> V_314 = F_323 ( T_1 , V_47 -> V_92 * 1024 ,
V_47 -> V_214 ) ;
V_313 -> V_315 = V_47 -> V_92 << V_178 ;
}
static void F_324 ( struct V_198 * V_87 , struct V_312 * V_313 )
{
struct V_47 * V_47 = V_87 -> V_199 ;
T_12 V_316 = V_313 -> V_317 >> V_178 ;
if ( V_316 < V_47 -> V_93 ||
F_84 ( V_316 , V_47 -> V_93 ) ) {
F_325 ( V_313 , V_47 -> V_93 << V_178 ) ;
F_326 ( V_313 , V_47 -> V_93 << V_178 ) ;
}
F_322 ( V_47 , V_313 ) ;
}
static int T_14 F_327 ( void )
{
int V_9 ;
V_9 = F_328 ( & V_318 ) ;
if ( V_9 ) {
F_123 ( L_103 , V_9 ) ;
return V_9 ;
}
V_265 = F_329 ( V_56 , 0 ) ;
if ( ! V_265 ) {
F_330 ( & V_318 ) ;
return - V_165 ;
}
return 0 ;
}
static void T_15 F_331 ( void )
{
F_330 ( & V_318 ) ;
F_332 ( V_265 ) ;
}
