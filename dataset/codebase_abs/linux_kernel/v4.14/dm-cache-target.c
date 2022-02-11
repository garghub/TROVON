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
T_2 V_9 ;
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
T_2 (* V_30)( void * ) ,
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
T_3 * V_39 , void * V_40 )
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
static inline T_4 F_54 ( T_4 V_21 )
{
return F_55 ( F_56 ( V_21 ) + 1ull ) ;
}
static void F_57 ( T_4 V_61 , T_4 V_62 , struct V_63 * V_64 )
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
static T_5 F_60 ( struct V_47 * V_47 )
{
return F_36 ( & V_47 -> V_50 ) ? V_72 : V_73 ;
}
static struct V_74 * F_61 ( struct V_26 * V_26 , T_5 V_75 )
{
struct V_74 * V_76 = F_62 ( V_26 , V_75 ) ;
F_63 ( ! V_76 ) ;
return V_76 ;
}
static struct V_74 * F_64 ( struct V_26 * V_26 , T_5 V_75 )
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
static bool F_68 ( struct V_47 * V_47 , T_4 V_80 , struct V_26 * V_26 )
{
bool V_9 ;
T_5 V_81 ;
struct V_74 * V_76 ;
struct V_63 V_64 ;
T_4 V_62 = F_55 ( F_56 ( V_80 ) + 1ULL ) ;
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
static bool F_70 ( struct V_47 * V_47 , T_6 V_21 )
{
return F_71 ( F_72 ( V_21 ) , V_47 -> V_83 ) ;
}
static void F_73 ( struct V_47 * V_47 , T_6 V_84 )
{
if ( ! F_74 ( F_72 ( V_84 ) , V_47 -> V_83 ) ) {
F_49 ( & V_47 -> V_85 ) ;
F_75 ( V_47 -> V_86 , V_84 ) ;
}
}
static void F_76 ( struct V_47 * V_47 , T_6 V_84 )
{
if ( ! F_74 ( F_72 ( V_84 ) , V_47 -> V_83 ) )
F_49 ( & V_47 -> V_85 ) ;
F_75 ( V_47 -> V_86 , V_84 ) ;
}
static void F_77 ( struct V_47 * V_47 , T_6 V_84 )
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
T_7
#endif
static T_8 F_83 ( T_8 V_21 , T_9 V_90 )
{
F_84 ( V_21 , V_90 ) ;
return V_21 ;
}
static T_8 F_85 ( struct V_47 * V_47 )
{
T_8 V_91 = V_47 -> V_92 ;
if ( F_82 ( V_47 ) )
V_91 >>= V_47 -> V_89 ;
else
V_91 = F_83 ( V_91 , V_47 -> V_93 ) ;
return V_91 ;
}
static T_10 F_86 ( struct V_47 * V_47 , T_4 V_80 )
{
return F_87 ( F_83 ( F_56 ( V_80 ) ,
F_85 ( V_47 ) ) ) ;
}
static void F_88 ( struct V_47 * V_47 , T_10 V_21 )
{
unsigned long V_10 ;
F_63 ( F_89 ( V_21 ) >= F_89 ( V_47 -> V_94 ) ) ;
F_49 ( & V_47 -> V_95 . V_96 ) ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
F_90 ( F_89 ( V_21 ) , V_47 -> V_97 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
}
static void F_91 ( struct V_47 * V_47 , T_10 V_21 )
{
unsigned long V_10 ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
F_92 ( F_89 ( V_21 ) , V_47 -> V_97 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
}
static bool F_93 ( struct V_47 * V_47 , T_10 V_21 )
{
int V_9 ;
unsigned long V_10 ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
V_9 = F_71 ( F_89 ( V_21 ) , V_47 -> V_97 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
return V_9 ;
}
static bool F_94 ( struct V_47 * V_47 , T_4 V_21 )
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
F_96 ( V_26 , V_47 -> V_98 -> V_99 ) ;
}
static void F_97 ( struct V_47 * V_47 , struct V_26 * V_26 ,
T_6 V_84 )
{
T_1 V_100 = V_26 -> V_101 . V_100 ;
T_1 V_102 = F_72 ( V_84 ) ;
F_96 ( V_26 , V_47 -> V_103 -> V_99 ) ;
if ( ! F_82 ( V_47 ) )
V_26 -> V_101 . V_100 =
( V_102 * V_47 -> V_93 ) +
F_98 ( V_100 , V_47 -> V_93 ) ;
else
V_26 -> V_101 . V_100 =
( V_102 << V_47 -> V_89 ) |
( V_100 & ( V_47 -> V_93 - 1 ) ) ;
}
static void F_99 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
unsigned long V_10 ;
T_5 V_104 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_104 ) ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
if ( V_47 -> V_105 && ! F_100 ( V_26 -> V_106 ) &&
F_101 ( V_26 ) != V_107 ) {
V_76 -> V_77 = true ;
V_47 -> V_105 = false ;
}
F_7 ( & V_47 -> V_3 , V_10 ) ;
}
static void F_102 ( struct V_47 * V_47 , struct V_26 * V_26 ,
T_4 V_80 )
{
F_99 ( V_47 , V_26 ) ;
F_95 ( V_47 , V_26 ) ;
if ( F_59 ( V_26 ) == V_69 )
F_91 ( V_47 , F_86 ( V_47 , V_80 ) ) ;
}
static void F_103 ( struct V_47 * V_47 , struct V_26 * V_26 ,
T_4 V_80 , T_6 V_84 )
{
F_99 ( V_47 , V_26 ) ;
F_97 ( V_47 , V_26 , V_84 ) ;
if ( F_59 ( V_26 ) == V_69 ) {
F_73 ( V_47 , V_84 ) ;
F_91 ( V_47 , F_86 ( V_47 , V_80 ) ) ;
}
}
static T_4 F_104 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
T_1 V_108 = V_26 -> V_101 . V_100 ;
if ( ! F_82 ( V_47 ) )
( void ) F_98 ( V_108 , V_47 -> V_93 ) ;
else
V_108 >>= V_47 -> V_89 ;
return F_55 ( V_108 ) ;
}
static bool F_105 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
return F_101 ( V_26 ) != V_107 ;
}
static void F_106 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
T_5 V_104 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_104 ) ;
if ( F_105 ( V_47 , V_26 ) ) {
V_76 -> V_11 = F_107 ( V_26 ) ;
F_8 ( & V_47 -> V_109 , V_76 -> V_11 ) ;
}
}
static void F_108 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
T_5 V_104 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_104 ) ;
F_10 ( & V_47 -> V_109 , V_76 -> V_11 ) ;
}
static void F_109 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
F_106 ( V_47 , V_26 ) ;
F_110 ( V_26 ) ;
}
static void V_34 ( struct V_26 * V_26 , void * V_110 )
{
struct V_47 * V_47 = V_110 ;
F_109 ( V_47 , V_26 ) ;
}
static void F_111 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
unsigned long V_10 ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
F_30 ( & V_47 -> V_111 , V_26 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
F_41 ( V_47 ) ;
}
static void F_112 ( struct V_26 * V_26 )
{
struct V_74 * V_76 = F_61 ( V_26 , V_72 ) ;
F_35 ( & V_76 -> V_112 , V_26 ) ;
if ( V_26 -> V_33 ) {
F_24 ( V_26 ) ;
return;
}
F_113 ( & V_76 -> V_113 , V_26 ) ;
F_97 ( V_76 -> V_47 , V_26 , V_76 -> V_84 ) ;
F_111 ( V_76 -> V_47 , V_26 ) ;
}
static void F_114 ( struct V_47 * V_47 , struct V_26 * V_26 ,
T_4 V_80 , T_6 V_84 )
{
struct V_74 * V_76 = F_61 ( V_26 , V_72 ) ;
V_76 -> V_47 = V_47 ;
V_76 -> V_84 = V_84 ;
F_34 ( & V_76 -> V_112 , V_26 , F_112 , NULL ) ;
F_115 ( & V_76 -> V_113 , V_26 ) ;
F_102 ( V_76 -> V_47 , V_26 , V_80 ) ;
}
static enum V_114 F_116 ( struct V_47 * V_47 )
{
return V_47 -> V_50 . V_115 ;
}
static const char * F_117 ( struct V_47 * V_47 )
{
return F_118 ( F_119 ( V_47 -> V_87 -> V_88 ) ) ;
}
static void F_120 ( struct V_47 * V_47 , enum V_114 V_115 )
{
const char * V_116 [] = {
L_1 ,
L_2 ,
L_3
} ;
F_80 ( V_47 -> V_87 -> V_88 ) ;
F_121 ( L_4 ,
F_117 ( V_47 ) , V_116 [ ( int ) V_115 ] ) ;
}
static void F_122 ( struct V_47 * V_47 , enum V_114 V_117 )
{
bool V_118 ;
enum V_114 V_119 = F_116 ( V_47 ) ;
if ( F_123 ( V_47 -> V_120 , & V_118 ) ) {
F_124 ( L_5 ,
F_117 ( V_47 ) ) ;
V_117 = V_121 ;
}
if ( V_117 == V_122 && V_118 ) {
F_124 ( L_6 ,
F_117 ( V_47 ) ) ;
if ( V_119 != V_117 )
V_117 = V_119 ;
else
V_117 = V_123 ;
}
if ( V_119 == V_121 )
V_117 = V_121 ;
switch ( V_117 ) {
case V_121 :
case V_123 :
F_125 ( V_47 -> V_120 ) ;
break;
case V_122 :
F_126 ( V_47 -> V_120 ) ;
break;
}
V_47 -> V_50 . V_115 = V_117 ;
if ( V_117 != V_119 )
F_120 ( V_47 , V_117 ) ;
}
static void F_127 ( struct V_47 * V_47 )
{
const char * V_124 = F_117 ( V_47 ) ;
if ( F_116 ( V_47 ) >= V_123 )
return;
if ( F_128 ( V_47 -> V_120 ) ) {
F_124 ( L_7 , V_124 ) ;
F_122 ( V_47 , V_121 ) ;
}
F_129 ( L_8 , V_124 ) ;
if ( F_130 ( V_47 -> V_120 ) ) {
F_124 ( L_9 , V_124 ) ;
F_122 ( V_47 , V_121 ) ;
}
}
static void F_131 ( struct V_47 * V_47 , const char * V_125 , int V_9 )
{
F_129 ( L_10 ,
F_117 ( V_47 ) , V_125 , V_9 ) ;
F_127 ( V_47 ) ;
F_122 ( V_47 , V_123 ) ;
}
static void F_132 ( struct V_47 * V_47 )
{
struct V_126 V_95 ;
F_133 ( V_47 -> V_120 , & V_95 ) ;
F_134 ( & V_47 -> V_95 . V_127 , V_95 . V_128 ) ;
F_134 ( & V_47 -> V_95 . V_129 , V_95 . V_130 ) ;
F_134 ( & V_47 -> V_95 . V_131 , V_95 . V_132 ) ;
F_134 ( & V_47 -> V_95 . V_133 , V_95 . V_134 ) ;
}
static void F_135 ( struct V_47 * V_47 )
{
struct V_126 V_95 ;
if ( F_116 ( V_47 ) >= V_123 )
return;
V_95 . V_128 = F_136 ( & V_47 -> V_95 . V_127 ) ;
V_95 . V_130 = F_136 ( & V_47 -> V_95 . V_129 ) ;
V_95 . V_132 = F_136 ( & V_47 -> V_95 . V_131 ) ;
V_95 . V_134 = F_136 ( & V_47 -> V_95 . V_133 ) ;
F_137 ( V_47 -> V_120 , & V_95 ) ;
}
static void F_138 ( struct V_135 * V_95 , enum V_136 V_125 )
{
switch ( V_125 ) {
case V_137 :
F_49 ( & V_95 -> V_138 ) ;
break;
case V_139 :
F_49 ( & V_95 -> V_140 ) ;
break;
case V_141 :
F_49 ( & V_95 -> V_142 ) ;
break;
}
}
static void F_139 ( struct V_47 * V_47 )
{
F_49 ( & V_47 -> V_143 ) ;
}
static void F_140 ( struct V_47 * V_47 )
{
F_141 ( & V_47 -> V_143 ) ;
}
static bool F_142 ( struct V_26 * V_26 )
{
return F_101 ( V_26 ) == V_107 || F_100 ( V_26 -> V_106 ) ;
}
static void F_143 ( struct V_47 * V_47 , struct V_26 * V_26 ,
T_10 * V_21 , T_10 * V_144 )
{
T_1 V_145 = V_26 -> V_101 . V_100 ;
T_1 V_146 = F_144 ( V_26 ) ;
* V_21 = F_87 ( F_145 ( V_145 , V_47 -> V_92 ) ) ;
if ( V_146 - V_145 < V_47 -> V_92 )
* V_144 = * V_21 ;
else
* V_144 = F_87 ( F_83 ( V_146 , V_47 -> V_92 ) ) ;
}
static void F_146 ( struct V_47 * V_47 )
{
F_147 () ;
F_148 ( & V_47 -> V_147 ) ;
F_149 () ;
}
static void F_150 ( struct V_47 * V_47 )
{
F_147 () ;
F_151 ( & V_47 -> V_147 ) ;
F_149 () ;
}
static bool F_152 ( struct V_47 * V_47 )
{
bool V_9 ;
F_147 () ;
V_9 = F_153 ( & V_47 -> V_147 ) ;
F_149 () ;
return V_9 ;
}
static void F_154 ( struct V_47 * V_47 )
{
F_147 () ;
F_155 ( & V_47 -> V_147 ) ;
F_149 () ;
}
static void F_156 ( struct V_56 * V_57 ,
void (* V_12)( struct V_14 * ) )
{
F_11 ( & V_57 -> V_13 , V_12 ) ;
F_157 ( V_57 -> V_47 -> V_53 , V_57 -> V_55 , & V_57 -> V_13 . V_15 ) ;
}
static struct V_56 * F_158 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = F_17 ( V_15 , struct V_12 , V_15 ) ;
return F_17 ( V_13 , struct V_56 , V_13 ) ;
}
static void F_159 ( int V_148 , unsigned long V_149 , void * V_110 )
{
struct V_56 * V_57 = F_17 ( V_110 , struct V_56 , V_13 ) ;
if ( V_148 || V_149 )
V_57 -> V_13 . V_16 = V_150 ;
F_14 ( V_57 -> V_47 -> V_18 , & V_57 -> V_13 ) ;
}
static int F_160 ( struct V_56 * V_57 , bool V_151 )
{
int V_9 ;
struct V_152 V_153 , V_154 ;
struct V_47 * V_47 = V_57 -> V_47 ;
V_153 . V_99 = V_47 -> V_98 -> V_99 ;
V_153 . V_155 = F_56 ( V_57 -> V_125 -> V_80 ) * V_47 -> V_93 ;
V_153 . V_156 = V_47 -> V_93 ;
V_154 . V_99 = V_47 -> V_103 -> V_99 ;
V_154 . V_155 = F_72 ( V_57 -> V_125 -> V_84 ) * V_47 -> V_93 ;
V_154 . V_156 = V_47 -> V_93 ;
if ( V_151 )
V_9 = F_161 ( V_47 -> V_157 , & V_153 , 1 , & V_154 , 0 , F_159 , & V_57 -> V_13 ) ;
else
V_9 = F_161 ( V_47 -> V_157 , & V_154 , 1 , & V_153 , 0 , F_159 , & V_57 -> V_13 ) ;
return V_9 ;
}
static void F_162 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
T_5 V_104 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_104 ) ;
if ( V_76 -> V_55 && F_163 ( V_47 -> V_53 , V_76 -> V_55 ) )
F_45 ( V_47 , V_76 -> V_55 ) ;
V_76 -> V_55 = NULL ;
}
static void F_164 ( struct V_26 * V_26 )
{
struct V_56 * V_57 = V_26 -> V_40 ;
struct V_47 * V_47 = V_57 -> V_47 ;
T_5 V_104 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_104 ) ;
F_35 ( & V_76 -> V_112 , V_26 ) ;
if ( V_26 -> V_33 )
V_57 -> V_13 . V_16 = V_26 -> V_33 ;
F_14 ( V_57 -> V_47 -> V_18 , & V_57 -> V_13 ) ;
}
static void F_165 ( struct V_56 * V_57 ,
void (* V_12)( struct V_14 * ) )
{
struct V_26 * V_26 = V_57 -> V_158 ;
T_5 V_104 = F_60 ( V_57 -> V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_104 ) ;
F_34 ( & V_76 -> V_112 , V_26 , F_164 , V_57 ) ;
if ( V_57 -> V_125 -> V_125 == V_137 )
F_97 ( V_57 -> V_47 , V_26 , V_57 -> V_125 -> V_84 ) ;
else
F_95 ( V_57 -> V_47 , V_26 ) ;
F_11 ( & V_57 -> V_13 , V_12 ) ;
F_109 ( V_57 -> V_47 , V_26 ) ;
}
static void F_166 ( struct V_56 * V_57 , bool V_159 )
{
struct V_27 V_28 ;
struct V_47 * V_47 = V_57 -> V_47 ;
struct V_160 * V_125 = V_57 -> V_125 ;
T_6 V_84 = V_125 -> V_84 ;
if ( V_159 )
F_138 ( & V_47 -> V_95 , V_125 -> V_125 ) ;
switch ( V_125 -> V_125 ) {
case V_137 :
F_91 ( V_47 , F_86 ( V_47 , V_125 -> V_80 ) ) ;
F_167 ( V_47 -> V_86 , V_125 , V_159 ) ;
if ( V_57 -> V_158 ) {
if ( V_159 )
F_76 ( V_47 , V_84 ) ;
else if ( V_57 -> V_13 . V_16 )
V_57 -> V_158 -> V_33 = V_57 -> V_13 . V_16 ;
else
V_57 -> V_158 -> V_33 = V_150 ;
F_24 ( V_57 -> V_158 ) ;
} else {
if ( V_159 )
F_77 ( V_47 , V_84 ) ;
F_140 ( V_47 ) ;
}
break;
case V_139 :
if ( V_159 )
F_77 ( V_47 , V_84 ) ;
F_167 ( V_47 -> V_86 , V_125 , V_159 ) ;
F_140 ( V_47 ) ;
break;
case V_141 :
if ( V_159 )
F_77 ( V_47 , V_84 ) ;
F_167 ( V_47 -> V_86 , V_125 , V_159 ) ;
F_140 ( V_47 ) ;
break;
}
F_19 ( & V_28 ) ;
if ( V_57 -> V_55 ) {
if ( F_168 ( V_47 -> V_53 , V_57 -> V_55 , & V_28 ) )
F_45 ( V_47 , V_57 -> V_55 ) ;
}
F_50 ( V_57 ) ;
F_67 ( V_47 , & V_28 ) ;
F_42 ( V_47 ) ;
F_154 ( V_47 ) ;
}
static void F_169 ( struct V_14 * V_15 )
{
struct V_56 * V_57 = F_158 ( V_15 ) ;
F_166 ( V_57 , V_57 -> V_13 . V_16 == 0 ) ;
}
static void F_170 ( struct V_14 * V_15 )
{
int V_9 ;
struct V_56 * V_57 = F_158 ( V_15 ) ;
struct V_47 * V_47 = V_57 -> V_47 ;
struct V_160 * V_125 = V_57 -> V_125 ;
switch ( V_125 -> V_125 ) {
case V_137 :
V_9 = F_171 ( V_47 -> V_120 , V_125 -> V_84 , V_125 -> V_80 ) ;
if ( V_9 ) {
F_129 ( L_11 ,
F_117 ( V_47 ) ) ;
F_131 ( V_47 , L_12 , V_9 ) ;
F_166 ( V_57 , false ) ;
return;
}
F_166 ( V_57 , true ) ;
break;
case V_139 :
V_9 = F_172 ( V_47 -> V_120 , V_125 -> V_84 ) ;
if ( V_9 ) {
F_129 ( L_13 ,
F_117 ( V_47 ) ) ;
F_131 ( V_47 , L_14 , V_9 ) ;
F_166 ( V_57 , false ) ;
return;
}
F_11 ( & V_57 -> V_13 , F_169 ) ;
F_27 ( & V_47 -> V_161 , & V_57 -> V_13 ) ;
F_31 ( & V_47 -> V_161 ) ;
break;
case V_141 :
F_166 ( V_57 , true ) ;
break;
}
}
static void F_173 ( struct V_14 * V_15 )
{
struct V_56 * V_57 = F_158 ( V_15 ) ;
if ( V_57 -> V_13 . V_16 )
F_166 ( V_57 , false ) ;
else
F_170 ( V_15 ) ;
}
static void F_174 ( struct V_14 * V_15 )
{
int V_9 ;
struct V_56 * V_57 = F_158 ( V_15 ) ;
if ( V_57 -> V_13 . V_16 )
F_166 ( V_57 , false ) ;
else {
V_9 = F_175 ( V_57 -> V_47 -> V_53 , V_57 -> V_55 ,
V_71 ) ;
if ( V_9 < 0 )
F_166 ( V_57 , false ) ;
else if ( V_9 )
F_156 ( V_57 , F_170 ) ;
else
F_170 ( V_15 ) ;
}
}
static void F_176 ( struct V_14 * V_15 )
{
int V_9 ;
struct V_56 * V_57 = F_158 ( V_15 ) ;
if ( V_57 -> V_158 ) {
F_165 ( V_57 , F_173 ) ;
} else {
struct V_47 * V_47 = V_57 -> V_47 ;
struct V_160 * V_125 = V_57 -> V_125 ;
bool V_162 = ( V_125 -> V_125 == V_137 ) ;
if ( ( ! V_162 && ! F_70 ( V_47 , V_125 -> V_84 ) ) ||
F_94 ( V_47 , V_125 -> V_80 ) ) {
F_174 ( V_15 ) ;
return;
}
F_11 ( & V_57 -> V_13 , F_174 ) ;
V_9 = F_160 ( V_57 , V_162 ) ;
if ( V_9 ) {
F_129 ( L_15 , F_117 ( V_47 ) ) ;
V_57 -> V_13 . V_16 = V_150 ;
F_166 ( V_57 , false ) ;
}
}
}
static int F_177 ( struct V_56 * V_57 )
{
int V_9 ;
struct V_63 V_64 ;
struct V_47 * V_47 = V_57 -> V_47 ;
struct V_52 * V_163 ;
V_163 = F_43 ( V_47 ) ;
if ( ! V_163 ) {
F_129 ( L_16 , F_117 ( V_47 ) ) ;
F_166 ( V_57 , false ) ;
return - V_164 ;
}
F_57 ( V_57 -> V_125 -> V_80 , F_54 ( V_57 -> V_125 -> V_80 ) , & V_64 ) ;
V_9 = F_178 ( V_47 -> V_53 , & V_64 ,
V_57 -> V_158 ? V_71 : V_70 ,
V_163 , & V_57 -> V_55 ) ;
if ( V_9 < 0 ) {
F_45 ( V_47 , V_163 ) ;
F_166 ( V_57 , false ) ;
return V_9 ;
}
if ( V_57 -> V_55 != V_163 )
F_45 ( V_47 , V_163 ) ;
if ( V_9 == 0 )
F_176 ( & V_57 -> V_13 . V_15 ) ;
else
F_156 ( V_57 , F_176 ) ;
return 0 ;
}
static int F_179 ( struct V_47 * V_47 , struct V_160 * V_125 , struct V_26 * V_26 )
{
struct V_56 * V_57 ;
if ( ! F_152 ( V_47 ) ) {
F_167 ( V_47 -> V_86 , V_125 , false ) ;
return - V_165 ;
}
V_57 = F_47 ( V_47 ) ;
if ( ! V_57 ) {
F_167 ( V_47 -> V_86 , V_125 , false ) ;
F_154 ( V_47 ) ;
return - V_164 ;
}
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_57 -> V_47 = V_47 ;
V_57 -> V_125 = V_125 ;
V_57 -> V_158 = V_26 ;
if ( ! V_26 )
F_139 ( V_47 ) ;
return F_177 ( V_57 ) ;
}
static void F_180 ( struct V_56 * V_57 , bool V_159 )
{
struct V_27 V_28 ;
struct V_47 * V_47 = V_57 -> V_47 ;
F_19 ( & V_28 ) ;
if ( F_168 ( V_47 -> V_53 , V_57 -> V_55 , & V_28 ) )
F_45 ( V_47 , V_57 -> V_55 ) ;
if ( ! V_159 && V_57 -> V_158 )
F_181 ( V_57 -> V_158 ) ;
F_50 ( V_57 ) ;
F_67 ( V_47 , & V_28 ) ;
F_154 ( V_47 ) ;
}
static void F_182 ( struct V_14 * V_15 )
{
struct V_56 * V_57 = F_158 ( V_15 ) ;
F_180 ( V_57 , ! V_57 -> V_13 . V_16 ) ;
}
static int F_183 ( struct V_47 * V_47 , T_6 V_84 )
{
int V_9 = F_184 ( V_47 -> V_86 , V_84 ) ;
if ( ! V_9 ) {
V_9 = F_172 ( V_47 -> V_120 , V_84 ) ;
if ( V_9 ) {
F_129 ( L_17 ,
F_117 ( V_47 ) ) ;
F_131 ( V_47 , L_14 , V_9 ) ;
}
} else if ( V_9 == - V_166 ) {
V_9 = 0 ;
} else
F_124 ( L_18 , F_117 ( V_47 ) ) ;
return V_9 ;
}
static void F_185 ( struct V_14 * V_15 )
{
int V_9 ;
struct V_56 * V_57 = F_158 ( V_15 ) ;
struct V_47 * V_47 = V_57 -> V_47 ;
V_9 = F_183 ( V_47 , V_57 -> F_183 ) ;
if ( V_9 ) {
F_180 ( V_57 , false ) ;
return;
}
F_11 ( & V_57 -> V_13 , F_182 ) ;
F_27 ( & V_47 -> V_161 , & V_57 -> V_13 ) ;
F_102 ( V_47 , V_57 -> V_158 , V_57 -> V_167 ) ;
V_57 -> V_158 = NULL ;
F_31 ( & V_47 -> V_161 ) ;
}
static int F_186 ( struct V_56 * V_57 )
{
int V_9 ;
struct V_63 V_64 ;
struct V_47 * V_47 = V_57 -> V_47 ;
struct V_52 * V_163 ;
V_163 = F_43 ( V_47 ) ;
if ( ! V_163 ) {
F_180 ( V_57 , false ) ;
return - V_164 ;
}
F_57 ( V_57 -> V_167 , F_54 ( V_57 -> V_167 ) , & V_64 ) ;
V_9 = F_178 ( V_47 -> V_53 , & V_64 ,
V_71 , V_163 , & V_57 -> V_55 ) ;
if ( V_9 < 0 ) {
F_45 ( V_47 , V_163 ) ;
F_180 ( V_57 , false ) ;
return V_9 ;
}
if ( V_57 -> V_55 != V_163 )
F_45 ( V_47 , V_163 ) ;
if ( V_9 )
F_156 ( V_57 , F_185 ) ;
else {
F_11 ( & V_57 -> V_13 , F_185 ) ;
F_15 ( V_47 -> V_18 , & V_57 -> V_13 . V_15 ) ;
}
return 0 ;
}
static int F_187 ( struct V_47 * V_47 , T_6 V_84 ,
T_4 V_80 , struct V_26 * V_26 )
{
struct V_56 * V_57 ;
if ( ! F_152 ( V_47 ) )
return - V_165 ;
V_57 = F_47 ( V_47 ) ;
if ( ! V_57 ) {
F_154 ( V_47 ) ;
return - V_164 ;
}
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_57 -> V_47 = V_47 ;
V_57 -> V_158 = V_26 ;
V_57 -> F_183 = V_84 ;
V_57 -> V_167 = V_80 ;
return F_186 ( V_57 ) ;
}
static enum V_168 F_188 ( struct V_47 * V_47 )
{
bool V_169 = F_5 ( & V_47 -> V_109 , V_170 ) ;
T_1 V_171 = ( F_136 ( & V_47 -> V_143 ) + 1 ) *
V_47 -> V_93 ;
if ( V_169 && V_171 <= V_47 -> V_172 )
return V_173 ;
else
return V_174 ;
}
static void F_189 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
F_49 ( F_59 ( V_26 ) == V_175 ?
& V_47 -> V_95 . V_127 : & V_47 -> V_95 . V_131 ) ;
}
static void F_190 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
F_49 ( F_59 ( V_26 ) == V_175 ?
& V_47 -> V_95 . V_129 : & V_47 -> V_95 . V_133 ) ;
}
static bool F_191 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
return ( F_59 ( V_26 ) == V_69 ) &&
( V_26 -> V_101 . V_176 == ( V_47 -> V_93 << V_177 ) ) ;
}
static bool F_192 ( struct V_47 * V_47 , struct V_26 * V_26 , T_4 V_102 )
{
return F_37 ( & V_47 -> V_50 ) &&
( F_94 ( V_47 , V_102 ) || F_191 ( V_47 , V_26 ) ) ;
}
static int F_193 ( struct V_47 * V_47 , struct V_26 * V_26 , T_4 V_102 ,
bool * V_178 )
{
int V_9 , V_179 ;
bool V_180 , V_181 ;
T_6 V_84 ;
T_5 V_104 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_104 ) ;
* V_178 = false ;
V_180 = F_68 ( V_47 , V_102 , V_26 ) ;
if ( ! V_180 ) {
* V_178 = true ;
return V_182 ;
}
V_179 = F_59 ( V_26 ) ;
if ( F_192 ( V_47 , V_26 , V_102 ) ) {
struct V_160 * V_125 = NULL ;
V_9 = F_194 ( V_47 -> V_86 , V_102 , & V_84 , V_179 , true , & V_125 ) ;
if ( F_39 ( V_9 && V_9 != - V_183 ) ) {
F_129 ( L_19 ,
F_117 ( V_47 ) , V_9 ) ;
F_181 ( V_26 ) ;
return V_182 ;
}
if ( V_9 == - V_183 && V_125 ) {
F_162 ( V_47 , V_26 ) ;
F_63 ( V_125 -> V_125 != V_137 ) ;
F_179 ( V_47 , V_125 , V_26 ) ;
return V_182 ;
}
} else {
V_9 = F_195 ( V_47 -> V_86 , V_102 , & V_84 , V_179 , false , & V_181 ) ;
if ( F_39 ( V_9 && V_9 != - V_183 ) ) {
F_129 ( L_20 ,
F_117 ( V_47 ) , V_9 ) ;
F_181 ( V_26 ) ;
return V_182 ;
}
if ( V_181 )
F_42 ( V_47 ) ;
}
if ( V_9 == - V_183 ) {
F_190 ( V_47 , V_26 ) ;
if ( V_76 -> V_78 == 0 ) {
F_106 ( V_47 , V_26 ) ;
F_102 ( V_47 , V_26 , V_102 ) ;
} else {
F_24 ( V_26 ) ;
return V_182 ;
}
} else {
F_189 ( V_47 , V_26 ) ;
if ( F_38 ( & V_47 -> V_50 ) ) {
if ( F_59 ( V_26 ) == V_69 ) {
F_162 ( V_47 , V_26 ) ;
F_49 ( & V_47 -> V_95 . V_140 ) ;
F_187 ( V_47 , V_84 , V_102 , V_26 ) ;
} else
F_102 ( V_47 , V_26 , V_102 ) ;
} else {
if ( F_59 ( V_26 ) == V_69 && F_36 ( & V_47 -> V_50 ) &&
! F_70 ( V_47 , V_84 ) ) {
F_114 ( V_47 , V_26 , V_102 , V_84 ) ;
F_106 ( V_47 , V_26 ) ;
} else
F_103 ( V_47 , V_26 , V_102 , V_84 ) ;
}
}
if ( V_26 -> V_106 & V_184 ) {
F_108 ( V_47 , V_26 ) ;
F_29 ( & V_47 -> V_161 , V_26 ) ;
* V_178 = true ;
return V_182 ;
}
return V_185 ;
}
static bool F_196 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
bool V_178 ;
if ( F_193 ( V_47 , V_26 , F_104 ( V_47 , V_26 ) , & V_178 ) == V_185 )
F_110 ( V_26 ) ;
return V_178 ;
}
static int F_197 ( struct V_47 * V_47 , bool V_186 )
{
int V_9 ;
if ( F_116 ( V_47 ) >= V_123 )
return - V_187 ;
F_49 ( & V_47 -> V_95 . V_188 ) ;
V_9 = F_198 ( V_47 -> V_120 , V_186 ) ;
if ( V_9 )
F_131 ( V_47 , L_21 , V_9 ) ;
return V_9 ;
}
static T_2 V_30 ( void * V_110 )
{
struct V_47 * V_47 = V_110 ;
if ( F_199 ( V_47 -> V_120 ) )
return F_200 ( F_197 ( V_47 , false ) ) ;
return 0 ;
}
static bool F_201 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
T_5 V_104 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_104 ) ;
if ( ! V_76 -> V_78 )
F_95 ( V_47 , V_26 ) ;
else
F_97 ( V_47 , V_26 , 0 ) ;
F_29 ( & V_47 -> V_161 , V_26 ) ;
return true ;
}
static bool F_202 ( struct V_47 * V_47 , struct V_26 * V_26 )
{
T_10 V_21 , V_144 ;
F_143 ( V_47 , V_26 , & V_21 , & V_144 ) ;
while ( V_21 != V_144 ) {
F_88 ( V_47 , V_21 ) ;
V_21 = F_87 ( F_89 ( V_21 ) + 1 ) ;
}
F_24 ( V_26 ) ;
return false ;
}
static void F_203 ( struct V_14 * V_15 )
{
struct V_47 * V_47 = F_17 ( V_15 , struct V_47 , V_48 ) ;
unsigned long V_10 ;
bool V_178 = false ;
struct V_27 V_28 ;
struct V_26 * V_26 ;
F_19 ( & V_28 ) ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
F_21 ( & V_28 , & V_47 -> V_79 ) ;
F_19 ( & V_47 -> V_79 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
while ( ( V_26 = F_23 ( & V_28 ) ) ) {
if ( V_26 -> V_106 & V_189 )
V_178 = F_201 ( V_47 , V_26 ) || V_178 ;
else if ( F_101 ( V_26 ) == V_107 )
V_178 = F_202 ( V_47 , V_26 ) || V_178 ;
else
V_178 = F_196 ( V_47 , V_26 ) || V_178 ;
}
if ( V_178 )
F_31 ( & V_47 -> V_161 ) ;
}
static void F_204 ( struct V_14 * V_15 )
{
struct V_47 * V_47 = F_17 ( V_15 , struct V_47 , V_49 ) ;
unsigned long V_10 ;
struct V_27 V_28 ;
struct V_26 * V_26 ;
F_19 ( & V_28 ) ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
F_21 ( & V_28 , & V_47 -> V_111 ) ;
F_19 ( & V_47 -> V_111 ) ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
while ( ( V_26 = F_23 ( & V_28 ) ) )
F_110 ( V_26 ) ;
}
static void F_205 ( struct V_47 * V_47 )
{
struct V_26 * V_26 ;
struct V_27 V_28 ;
F_19 ( & V_28 ) ;
F_21 ( & V_28 , & V_47 -> V_79 ) ;
F_19 ( & V_47 -> V_79 ) ;
while ( ( V_26 = F_23 ( & V_28 ) ) ) {
V_26 -> V_33 = V_190 ;
F_24 ( V_26 ) ;
}
}
static void F_206 ( struct V_14 * V_15 )
{
struct V_47 * V_47 = F_17 ( F_207 ( V_15 ) , struct V_47 , V_191 ) ;
F_208 ( V_47 -> V_86 , true ) ;
F_42 ( V_47 ) ;
F_31 ( & V_47 -> V_161 ) ;
F_209 ( V_47 -> V_18 , & V_47 -> V_191 , V_192 ) ;
}
static void F_210 ( struct V_14 * V_15 )
{
int V_9 ;
struct V_160 * V_125 ;
struct V_47 * V_47 = F_17 ( V_15 , struct V_47 , V_51 ) ;
enum V_168 V_21 ;
for (; ; ) {
V_21 = F_188 ( V_47 ) ;
V_9 = F_211 ( V_47 -> V_86 , V_21 == V_173 , & V_125 ) ;
if ( V_9 == - V_166 )
break;
if ( V_9 ) {
F_129 ( L_22 ,
F_117 ( V_47 ) ) ;
break;
}
V_9 = F_179 ( V_47 , V_125 , NULL ) ;
if ( V_9 )
break;
}
}
static void F_212 ( struct V_47 * V_47 )
{
unsigned V_193 ;
F_213 ( V_47 -> V_58 ) ;
if ( V_47 -> V_53 )
F_214 ( V_47 -> V_53 ) ;
if ( V_47 -> V_18 )
F_215 ( V_47 -> V_18 ) ;
if ( V_47 -> V_83 )
F_216 ( V_47 -> V_83 ) ;
if ( V_47 -> V_97 )
F_216 ( V_47 -> V_97 ) ;
if ( V_47 -> V_157 )
F_217 ( V_47 -> V_157 ) ;
if ( V_47 -> V_120 )
F_218 ( V_47 -> V_120 ) ;
if ( V_47 -> V_194 )
F_219 ( V_47 -> V_87 , V_47 -> V_194 ) ;
if ( V_47 -> V_98 )
F_219 ( V_47 -> V_87 , V_47 -> V_98 ) ;
if ( V_47 -> V_103 )
F_219 ( V_47 -> V_87 , V_47 -> V_103 ) ;
if ( V_47 -> V_86 )
F_220 ( V_47 -> V_86 ) ;
for ( V_193 = 0 ; V_193 < V_47 -> V_195 ; V_193 ++ )
F_221 ( V_47 -> V_196 [ V_193 ] ) ;
F_221 ( V_47 -> V_196 ) ;
F_221 ( V_47 ) ;
}
static void F_222 ( struct V_197 * V_87 )
{
struct V_47 * V_47 = V_87 -> V_198 ;
F_212 ( V_47 ) ;
}
static T_1 F_223 ( struct V_199 * V_66 )
{
return F_224 ( V_66 -> V_99 -> V_200 ) >> V_177 ;
}
static void F_225 ( struct V_201 * V_202 )
{
if ( V_202 -> V_194 )
F_219 ( V_202 -> V_87 , V_202 -> V_194 ) ;
if ( V_202 -> V_103 )
F_219 ( V_202 -> V_87 , V_202 -> V_103 ) ;
if ( V_202 -> V_98 )
F_219 ( V_202 -> V_87 , V_202 -> V_98 ) ;
F_221 ( V_202 ) ;
}
static bool F_226 ( struct V_203 * V_204 , char * * error )
{
if ( ! V_204 -> V_205 ) {
* error = L_23 ;
return false ;
}
return true ;
}
static int F_227 ( struct V_201 * V_202 , struct V_203 * V_204 ,
char * * error )
{
int V_9 ;
T_1 V_206 ;
char V_21 [ V_207 ] ;
if ( ! F_226 ( V_204 , error ) )
return - V_187 ;
V_9 = F_228 ( V_202 -> V_87 , F_229 ( V_204 ) , V_208 | V_209 ,
& V_202 -> V_194 ) ;
if ( V_9 ) {
* error = L_24 ;
return V_9 ;
}
V_206 = F_223 ( V_202 -> V_194 ) ;
if ( V_206 > V_210 )
F_230 ( L_25 ,
F_231 ( V_202 -> V_194 -> V_99 , V_21 ) , V_211 ) ;
return 0 ;
}
static int F_232 ( struct V_201 * V_202 , struct V_203 * V_204 ,
char * * error )
{
int V_9 ;
if ( ! F_226 ( V_204 , error ) )
return - V_187 ;
V_9 = F_228 ( V_202 -> V_87 , F_229 ( V_204 ) , V_208 | V_209 ,
& V_202 -> V_103 ) ;
if ( V_9 ) {
* error = L_26 ;
return V_9 ;
}
V_202 -> V_212 = F_223 ( V_202 -> V_103 ) ;
return 0 ;
}
static int F_233 ( struct V_201 * V_202 , struct V_203 * V_204 ,
char * * error )
{
int V_9 ;
if ( ! F_226 ( V_204 , error ) )
return - V_187 ;
V_9 = F_228 ( V_202 -> V_87 , F_229 ( V_204 ) , V_208 | V_209 ,
& V_202 -> V_98 ) ;
if ( V_9 ) {
* error = L_27 ;
return V_9 ;
}
V_202 -> V_213 = F_223 ( V_202 -> V_98 ) ;
if ( V_202 -> V_87 -> V_11 > V_202 -> V_213 ) {
* error = L_28 ;
return - V_187 ;
}
return 0 ;
}
static int F_234 ( struct V_201 * V_202 , struct V_203 * V_204 ,
char * * error )
{
unsigned long V_214 ;
if ( ! F_226 ( V_204 , error ) )
return - V_187 ;
if ( F_235 ( F_229 ( V_204 ) , 10 , & V_214 ) || ! V_214 ||
V_214 < V_215 ||
V_214 > V_216 ||
V_214 & ( V_215 - 1 ) ) {
* error = L_29 ;
return - V_187 ;
}
if ( V_214 > V_202 -> V_212 ) {
* error = L_30 ;
return - V_187 ;
}
V_202 -> V_214 = V_214 ;
return 0 ;
}
static void F_236 ( struct V_41 * V_217 )
{
V_217 -> V_115 = V_122 ;
V_217 -> V_43 = V_45 ;
V_217 -> V_218 = 1 ;
}
static int F_237 ( struct V_201 * V_202 , struct V_203 * V_204 ,
char * * error )
{
static const struct V_219 V_220 [] = {
{ 0 , 2 , L_31 } ,
} ;
int V_9 ;
unsigned V_205 ;
const char * V_221 ;
struct V_41 * V_217 = & V_202 -> V_50 ;
F_236 ( V_217 ) ;
V_9 = F_238 ( V_220 , V_204 , & V_205 , error ) ;
if ( V_9 )
return - V_187 ;
while ( V_205 -- ) {
V_221 = F_229 ( V_204 ) ;
if ( ! strcasecmp ( V_221 , L_32 ) )
V_217 -> V_43 = V_45 ;
else if ( ! strcasecmp ( V_221 , L_33 ) )
V_217 -> V_43 = V_44 ;
else if ( ! strcasecmp ( V_221 , L_34 ) )
V_217 -> V_43 = V_46 ;
else if ( ! strcasecmp ( V_221 , L_35 ) )
V_217 -> V_218 = 2 ;
else {
* error = L_36 ;
return - V_187 ;
}
}
return 0 ;
}
static int F_239 ( struct V_201 * V_202 , struct V_203 * V_204 ,
char * * error )
{
static const struct V_219 V_220 [] = {
{ 0 , 1024 , L_37 } ,
} ;
int V_9 ;
if ( ! F_226 ( V_204 , error ) )
return - V_187 ;
V_202 -> V_222 = F_229 ( V_204 ) ;
V_9 = F_238 ( V_220 , V_204 , & V_202 -> V_223 , error ) ;
if ( V_9 )
return - V_187 ;
V_202 -> V_224 = ( const char * * ) V_204 -> V_225 ;
F_240 ( V_204 , V_202 -> V_223 ) ;
return 0 ;
}
static int F_241 ( struct V_201 * V_202 , int V_205 , char * * V_225 ,
char * * error )
{
int V_9 ;
struct V_203 V_204 ;
V_204 . V_205 = V_205 ;
V_204 . V_225 = V_225 ;
V_9 = F_227 ( V_202 , & V_204 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_232 ( V_202 , & V_204 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_233 ( V_202 , & V_204 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_234 ( V_202 , & V_204 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_237 ( V_202 , & V_204 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_239 ( V_202 , & V_204 , error ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_242 ( struct V_47 * V_47 , const char * V_64 , const char * V_226 )
{
unsigned long V_25 ;
if ( ! strcasecmp ( V_64 , L_38 ) ) {
if ( F_235 ( V_226 , 10 , & V_25 ) )
return - V_187 ;
V_47 -> V_172 = V_25 ;
return 0 ;
}
return V_227 ;
}
static int F_243 ( struct V_47 * V_47 , const char * V_64 , const char * V_226 )
{
int V_9 = F_242 ( V_47 , V_64 , V_226 ) ;
if ( V_9 == V_227 )
V_9 = F_244 ( V_47 -> V_86 , V_64 , V_226 ) ;
if ( V_9 )
F_230 ( L_39 , V_64 , V_226 ) ;
return V_9 ;
}
static int F_245 ( struct V_47 * V_47 , int V_205 , const char * * V_225 )
{
int V_9 = 0 ;
if ( V_205 & 1 ) {
F_230 ( L_40 ) ;
return - V_187 ;
}
while ( V_205 ) {
V_9 = F_243 ( V_47 , V_225 [ 0 ] , V_225 [ 1 ] ) ;
if ( V_9 )
break;
V_205 -= 2 ;
V_225 += 2 ;
}
return V_9 ;
}
static int F_246 ( struct V_47 * V_47 , struct V_201 * V_202 ,
char * * error )
{
struct V_228 * V_229 = F_247 ( V_202 -> V_222 ,
V_47 -> V_230 ,
V_47 -> V_213 ,
V_47 -> V_93 ) ;
if ( F_248 ( V_229 ) ) {
* error = L_41 ;
return F_249 ( V_229 ) ;
}
V_47 -> V_86 = V_229 ;
F_63 ( ! V_47 -> V_86 ) ;
return 0 ;
}
static bool F_250 ( T_1 V_92 ,
T_1 V_231 )
{
( void ) F_98 ( V_231 , V_92 ) ;
return V_231 > V_232 ;
}
static T_1 F_251 ( T_1 V_233 ,
T_1 V_231 )
{
T_1 V_92 = V_233 ;
if ( V_231 )
while ( F_250 ( V_92 , V_231 ) )
V_92 *= 2 ;
return V_92 ;
}
static void F_252 ( struct V_47 * V_47 , T_6 V_234 )
{
T_8 V_235 = F_72 ( V_234 ) ;
if ( V_235 > ( 1 << 20 ) && V_47 -> V_230 != V_234 )
F_253 ( L_42
L_43
L_44 ,
( unsigned long long ) V_235 ) ;
V_47 -> V_230 = V_234 ;
}
static int F_254 ( struct V_199 * V_66 , int V_236 )
{
struct V_237 * V_238 = F_255 ( V_66 -> V_99 ) ;
return F_256 ( V_238 -> V_239 , V_236 ) ;
}
static int F_257 ( struct V_240 * V_241 , int V_236 )
{
struct V_47 * V_47 = F_17 ( V_241 , struct V_47 , V_242 ) ;
return F_254 ( V_47 -> V_98 , V_236 ) ||
F_254 ( V_47 -> V_103 , V_236 ) ;
}
static int F_258 ( struct V_201 * V_202 , struct V_47 * * V_243 )
{
int V_9 = 0 ;
char * * error = & V_202 -> V_87 -> error ;
struct V_47 * V_47 ;
struct V_197 * V_87 = V_202 -> V_87 ;
T_8 V_244 ;
struct V_245 * V_120 ;
bool V_246 = V_202 -> V_50 . V_115 == V_122 ;
V_47 = F_259 ( sizeof( * V_47 ) , V_247 ) ;
if ( ! V_47 )
return - V_164 ;
V_47 -> V_87 = V_202 -> V_87 ;
V_87 -> V_198 = V_47 ;
V_87 -> V_248 = 2 ;
V_87 -> V_249 = true ;
V_87 -> V_250 = 1 ;
V_87 -> V_251 = true ;
V_87 -> V_252 = false ;
V_47 -> V_50 = V_202 -> V_50 ;
V_87 -> V_253 = F_60 ( V_47 ) ;
V_47 -> V_242 . V_254 = F_257 ;
F_260 ( V_87 -> V_88 , & V_47 -> V_242 ) ;
V_47 -> V_194 = V_202 -> V_194 ;
V_47 -> V_98 = V_202 -> V_98 ;
V_47 -> V_103 = V_202 -> V_103 ;
V_202 -> V_194 = V_202 -> V_98 = V_202 -> V_103 = NULL ;
V_244 = V_47 -> V_213 = V_202 -> V_213 ;
V_244 = F_83 ( V_244 , V_202 -> V_214 ) ;
V_47 -> V_244 = F_55 ( V_244 ) ;
V_47 -> V_93 = V_202 -> V_214 ;
if ( F_261 ( V_87 , V_47 -> V_93 ) ) {
V_9 = - V_187 ;
goto V_255;
}
if ( V_202 -> V_214 & ( V_202 -> V_214 - 1 ) ) {
T_8 V_230 = V_202 -> V_212 ;
V_47 -> V_89 = - 1 ;
V_230 = F_83 ( V_230 , V_202 -> V_214 ) ;
F_252 ( V_47 , F_262 ( V_230 ) ) ;
} else {
V_47 -> V_89 = F_263 ( V_202 -> V_214 ) ;
F_252 ( V_47 , F_262 ( V_202 -> V_212 >> V_47 -> V_89 ) ) ;
}
V_9 = F_246 ( V_47 , V_202 , error ) ;
if ( V_9 )
goto V_255;
V_47 -> V_256 = V_202 -> V_223 ;
V_47 -> V_172 = V_257 ;
V_9 = F_245 ( V_47 , V_202 -> V_223 , V_202 -> V_224 ) ;
if ( V_9 ) {
* error = L_45 ;
goto V_255;
}
V_120 = F_264 ( V_47 -> V_194 -> V_99 ,
V_202 -> V_214 , V_246 ,
F_265 ( V_47 -> V_86 ) ,
V_202 -> V_50 . V_218 ) ;
if ( F_248 ( V_120 ) ) {
* error = L_46 ;
V_9 = F_249 ( V_120 ) ;
goto V_255;
}
V_47 -> V_120 = V_120 ;
F_122 ( V_47 , V_122 ) ;
if ( F_116 ( V_47 ) != V_122 ) {
* error = L_47 ;
V_9 = - V_187 ;
goto V_255;
}
if ( F_38 ( & V_47 -> V_50 ) ) {
bool V_258 ;
V_9 = F_266 ( V_47 -> V_120 , & V_258 ) ;
if ( V_9 ) {
* error = L_48 ;
goto V_255;
}
if ( ! V_258 ) {
* error = L_49 ;
V_9 = - V_187 ;
goto V_255;
}
F_267 ( V_47 -> V_86 , false ) ;
}
F_2 ( & V_47 -> V_3 ) ;
F_18 ( & V_47 -> V_259 ) ;
F_19 ( & V_47 -> V_79 ) ;
F_19 ( & V_47 -> V_111 ) ;
F_134 ( & V_47 -> V_59 , 0 ) ;
F_134 ( & V_47 -> V_143 , 0 ) ;
F_268 ( & V_47 -> V_60 ) ;
V_9 = - V_164 ;
F_134 ( & V_47 -> V_85 , 0 ) ;
V_47 -> V_83 = F_269 ( F_72 ( V_47 -> V_230 ) ) ;
if ( ! V_47 -> V_83 ) {
* error = L_50 ;
goto V_255;
}
F_270 ( V_47 -> V_83 , F_72 ( V_47 -> V_230 ) ) ;
V_47 -> V_92 =
F_251 ( V_47 -> V_93 ,
V_47 -> V_213 ) ;
V_47 -> V_94 = F_87 ( F_145 ( V_47 -> V_213 ,
V_47 -> V_92 ) ) ;
V_47 -> V_97 = F_269 ( F_89 ( V_47 -> V_94 ) ) ;
if ( ! V_47 -> V_97 ) {
* error = L_51 ;
goto V_255;
}
F_270 ( V_47 -> V_97 , F_89 ( V_47 -> V_94 ) ) ;
V_47 -> V_157 = F_271 ( & V_260 ) ;
if ( F_248 ( V_47 -> V_157 ) ) {
* error = L_52 ;
V_9 = F_249 ( V_47 -> V_157 ) ;
goto V_255;
}
V_47 -> V_18 = F_272 ( L_53 V_261 , V_262 , 0 ) ;
if ( ! V_47 -> V_18 ) {
* error = L_54 ;
goto V_255;
}
F_13 ( & V_47 -> V_48 , F_203 ) ;
F_13 ( & V_47 -> V_49 ,
F_204 ) ;
F_13 ( & V_47 -> V_51 , F_210 ) ;
F_273 ( & V_47 -> V_191 , F_206 ) ;
V_47 -> V_53 = F_274 ( V_47 -> V_18 ) ;
if ( ! V_47 -> V_53 ) {
* error = L_55 ;
goto V_255;
}
V_47 -> V_58 = F_275 ( V_263 ,
V_264 ) ;
if ( ! V_47 -> V_58 ) {
* error = L_56 ;
goto V_255;
}
V_47 -> V_105 = true ;
V_47 -> V_265 = false ;
V_47 -> V_266 = false ;
V_47 -> V_267 = false ;
V_47 -> V_268 = false ;
V_47 -> V_269 = false ;
F_132 ( V_47 ) ;
F_134 ( & V_47 -> V_95 . V_140 , 0 ) ;
F_134 ( & V_47 -> V_95 . V_138 , 0 ) ;
F_134 ( & V_47 -> V_95 . V_270 , 0 ) ;
F_134 ( & V_47 -> V_95 . V_271 , 0 ) ;
F_134 ( & V_47 -> V_95 . V_188 , 0 ) ;
F_134 ( & V_47 -> V_95 . V_96 , 0 ) ;
F_2 ( & V_47 -> V_272 ) ;
F_18 ( & V_47 -> V_273 ) ;
F_25 ( & V_47 -> V_161 , V_30 , V_47 ,
V_34 , V_47 , V_47 -> V_18 ) ;
F_1 ( & V_47 -> V_109 ) ;
F_276 ( & V_47 -> V_147 ) ;
F_146 ( V_47 ) ;
* V_243 = V_47 ;
return 0 ;
V_255:
F_212 ( V_47 ) ;
return V_9 ;
}
static int F_277 ( struct V_47 * V_47 , int V_205 , const char * * V_225 )
{
unsigned V_193 ;
const char * * F_160 ;
F_160 = F_278 ( V_205 , sizeof( * F_160 ) , V_247 ) ;
if ( ! F_160 )
return - V_164 ;
for ( V_193 = 0 ; V_193 < V_205 ; V_193 ++ ) {
F_160 [ V_193 ] = F_279 ( V_225 [ V_193 ] , V_247 ) ;
if ( ! F_160 [ V_193 ] ) {
while ( V_193 -- )
F_221 ( F_160 [ V_193 ] ) ;
F_221 ( F_160 ) ;
return - V_164 ;
}
}
V_47 -> V_195 = V_205 ;
V_47 -> V_196 = F_160 ;
return 0 ;
}
static int F_280 ( struct V_197 * V_87 , unsigned V_205 , char * * V_225 )
{
int V_9 = - V_187 ;
struct V_201 * V_202 ;
struct V_47 * V_47 = NULL ;
V_202 = F_259 ( sizeof( * V_202 ) , V_247 ) ;
if ( ! V_202 ) {
V_87 -> error = L_57 ;
return - V_164 ;
}
V_202 -> V_87 = V_87 ;
V_9 = F_241 ( V_202 , V_205 , V_225 , & V_87 -> error ) ;
if ( V_9 )
goto V_274;
V_9 = F_258 ( V_202 , & V_47 ) ;
if ( V_9 )
goto V_274;
V_9 = F_277 ( V_47 , V_205 - 3 , ( const char * * ) V_225 + 3 ) ;
if ( V_9 ) {
F_212 ( V_47 ) ;
goto V_274;
}
V_87 -> V_198 = V_47 ;
V_274:
F_225 ( V_202 ) ;
return V_9 ;
}
static int F_281 ( struct V_197 * V_87 , struct V_26 * V_26 )
{
struct V_47 * V_47 = V_87 -> V_198 ;
int V_9 ;
bool V_178 ;
T_4 V_102 = F_104 ( V_47 , V_26 ) ;
T_5 V_104 = F_60 ( V_47 ) ;
F_64 ( V_26 , V_104 ) ;
if ( F_39 ( F_56 ( V_102 ) >= F_56 ( V_47 -> V_244 ) ) ) {
F_95 ( V_47 , V_26 ) ;
F_106 ( V_47 , V_26 ) ;
return V_185 ;
}
if ( F_142 ( V_26 ) ) {
F_66 ( V_47 , V_26 ) ;
return V_182 ;
}
V_9 = F_193 ( V_47 , V_26 , V_102 , & V_178 ) ;
if ( V_178 )
F_31 ( & V_47 -> V_161 ) ;
return V_9 ;
}
static int F_282 ( struct V_197 * V_87 , struct V_26 * V_26 ,
T_2 * error )
{
struct V_47 * V_47 = V_87 -> V_198 ;
unsigned long V_10 ;
T_5 V_104 = F_60 ( V_47 ) ;
struct V_74 * V_76 = F_61 ( V_26 , V_104 ) ;
if ( V_76 -> V_77 ) {
F_208 ( V_47 -> V_86 , false ) ;
F_6 ( & V_47 -> V_3 , V_10 ) ;
V_47 -> V_105 = true ;
F_7 ( & V_47 -> V_3 , V_10 ) ;
}
F_162 ( V_47 , V_26 ) ;
F_108 ( V_47 , V_26 ) ;
return V_275 ;
}
static int F_283 ( struct V_47 * V_47 )
{
int V_9 ;
if ( F_116 ( V_47 ) >= V_123 )
return - V_187 ;
V_9 = F_284 ( V_47 -> V_120 , F_72 ( V_47 -> V_230 ) , V_47 -> V_83 ) ;
if ( V_9 )
F_131 ( V_47 , L_58 , V_9 ) ;
return V_9 ;
}
static int F_285 ( struct V_47 * V_47 )
{
unsigned V_193 , V_9 ;
if ( F_116 ( V_47 ) >= V_123 )
return - V_187 ;
V_9 = F_286 ( V_47 -> V_120 , V_47 -> V_92 ,
V_47 -> V_94 ) ;
if ( V_9 ) {
F_124 ( L_59 , F_117 ( V_47 ) ) ;
F_131 ( V_47 , L_60 , V_9 ) ;
return V_9 ;
}
for ( V_193 = 0 ; V_193 < F_89 ( V_47 -> V_94 ) ; V_193 ++ ) {
V_9 = F_287 ( V_47 -> V_120 , F_87 ( V_193 ) ,
F_93 ( V_47 , F_87 ( V_193 ) ) ) ;
if ( V_9 ) {
F_131 ( V_47 , L_61 , V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
static int F_288 ( struct V_47 * V_47 )
{
int V_9 ;
if ( F_116 ( V_47 ) >= V_123 )
return - V_187 ;
V_9 = F_289 ( V_47 -> V_120 , V_47 -> V_86 ) ;
if ( V_9 ) {
F_131 ( V_47 , L_62 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static bool F_290 ( struct V_47 * V_47 )
{
int V_276 , V_277 , V_278 , V_279 ;
V_276 = F_283 ( V_47 ) ;
if ( V_276 )
F_124 ( L_63 , F_117 ( V_47 ) ) ;
V_277 = F_285 ( V_47 ) ;
if ( V_277 )
F_124 ( L_64 , F_117 ( V_47 ) ) ;
F_135 ( V_47 ) ;
V_278 = F_288 ( V_47 ) ;
if ( V_278 )
F_124 ( L_65 , F_117 ( V_47 ) ) ;
V_279 = F_197 ( V_47 , ! V_276 && ! V_277 && ! V_278 ) ;
if ( V_279 )
F_124 ( L_66 , F_117 ( V_47 ) ) ;
return ! V_276 && ! V_277 && ! V_278 && ! V_279 ;
}
static void F_291 ( struct V_197 * V_87 )
{
struct V_47 * V_47 = V_87 -> V_198 ;
F_146 ( V_47 ) ;
F_63 ( F_136 ( & V_47 -> V_143 ) ) ;
F_292 ( & V_47 -> V_191 ) ;
F_293 ( V_47 -> V_18 ) ;
F_294 ( V_47 -> V_109 . V_4 ) ;
F_205 ( V_47 ) ;
if ( F_116 ( V_47 ) == V_122 )
( void ) F_290 ( V_47 ) ;
}
static int F_295 ( void * V_110 , T_4 V_80 , T_6 V_84 ,
bool V_280 , T_9 V_281 , bool V_282 )
{
int V_9 ;
struct V_47 * V_47 = V_110 ;
if ( V_280 ) {
F_90 ( F_72 ( V_84 ) , V_47 -> V_83 ) ;
F_49 ( & V_47 -> V_85 ) ;
} else
F_92 ( F_72 ( V_84 ) , V_47 -> V_83 ) ;
V_9 = F_296 ( V_47 -> V_86 , V_80 , V_84 , V_280 , V_281 , V_282 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static void F_297 ( struct V_47 * V_47 ,
struct V_283 * V_284 )
{
V_284 -> V_47 = V_47 ;
V_284 -> V_285 = V_284 -> V_286 = 0 ;
}
static void F_298 ( struct V_283 * V_284 )
{
T_1 V_21 , V_144 ;
if ( V_284 -> V_285 == V_284 -> V_286 )
return;
V_21 = V_284 -> V_285 * V_284 -> V_214 ;
V_144 = V_284 -> V_286 * V_284 -> V_214 ;
V_21 = F_145 ( V_21 , V_284 -> V_47 -> V_92 ) ;
F_98 ( V_144 , V_284 -> V_47 -> V_92 ) ;
if ( V_144 > F_89 ( V_284 -> V_47 -> V_94 ) )
V_144 = F_89 ( V_284 -> V_47 -> V_94 ) ;
for (; V_21 < V_144 ; V_21 ++ )
F_88 ( V_284 -> V_47 , F_87 ( V_21 ) ) ;
}
static int F_299 ( void * V_110 , T_1 V_92 ,
T_10 V_287 , bool V_288 )
{
struct V_283 * V_284 = V_110 ;
V_284 -> V_214 = V_92 ;
if ( V_288 ) {
if ( F_89 ( V_287 ) == V_284 -> V_286 )
V_284 -> V_286 = V_284 -> V_286 + 1ULL ;
else {
F_298 ( V_284 ) ;
V_284 -> V_285 = F_89 ( V_287 ) ;
V_284 -> V_286 = V_284 -> V_285 + 1ULL ;
}
} else {
F_298 ( V_284 ) ;
V_284 -> V_285 = V_284 -> V_286 = 0 ;
}
return 0 ;
}
static T_6 F_300 ( struct V_47 * V_47 )
{
T_1 V_234 = F_223 ( V_47 -> V_103 ) ;
( void ) F_98 ( V_234 , V_47 -> V_93 ) ;
return F_262 ( V_234 ) ;
}
static bool F_301 ( struct V_47 * V_47 , T_6 V_289 )
{
if ( F_72 ( V_289 ) > F_72 ( V_47 -> V_230 ) )
return true ;
while ( F_72 ( V_289 ) < F_72 ( V_47 -> V_230 ) ) {
V_289 = F_262 ( F_72 ( V_289 ) + 1 ) ;
if ( F_70 ( V_47 , V_289 ) ) {
F_124 ( L_67 ,
F_117 ( V_47 ) ,
( unsigned long long ) F_72 ( V_289 ) ) ;
return false ;
}
}
return true ;
}
static int F_302 ( struct V_47 * V_47 , T_6 V_289 )
{
int V_9 ;
V_9 = F_303 ( V_47 -> V_120 , V_289 ) ;
if ( V_9 ) {
F_124 ( L_68 , F_117 ( V_47 ) ) ;
F_131 ( V_47 , L_69 , V_9 ) ;
return V_9 ;
}
F_252 ( V_47 , V_289 ) ;
return 0 ;
}
static int F_304 ( struct V_197 * V_87 )
{
int V_9 = 0 ;
struct V_47 * V_47 = V_87 -> V_198 ;
T_6 V_290 = F_300 ( V_47 ) ;
if ( ! V_47 -> V_265 ) {
V_9 = F_302 ( V_47 , V_290 ) ;
if ( V_9 )
return V_9 ;
V_47 -> V_265 = true ;
} else if ( V_290 != V_47 -> V_230 ) {
if ( ! F_301 ( V_47 , V_290 ) )
return - V_187 ;
V_9 = F_302 ( V_47 , V_290 ) ;
if ( V_9 )
return V_9 ;
}
if ( ! V_47 -> V_268 ) {
V_9 = F_305 ( V_47 -> V_120 , V_47 -> V_86 ,
F_295 , V_47 ) ;
if ( V_9 ) {
F_124 ( L_70 , F_117 ( V_47 ) ) ;
F_131 ( V_47 , L_71 , V_9 ) ;
return V_9 ;
}
V_47 -> V_268 = true ;
}
if ( ! V_47 -> V_269 ) {
struct V_283 V_284 ;
F_270 ( V_47 -> V_97 , F_89 ( V_47 -> V_94 ) ) ;
F_297 ( V_47 , & V_284 ) ;
V_9 = F_306 ( V_47 -> V_120 , F_299 , & V_284 ) ;
if ( V_9 ) {
F_124 ( L_72 , F_117 ( V_47 ) ) ;
F_131 ( V_47 , L_73 , V_9 ) ;
return V_9 ;
}
F_298 ( & V_284 ) ;
V_47 -> V_269 = true ;
}
return V_9 ;
}
static void F_307 ( struct V_197 * V_87 )
{
struct V_47 * V_47 = V_87 -> V_198 ;
V_47 -> V_105 = true ;
F_150 ( V_47 ) ;
F_206 ( & V_47 -> V_191 . V_291 ) ;
}
static void F_308 ( struct V_197 * V_87 , T_11 type ,
unsigned V_292 , char * V_243 , unsigned V_293 )
{
int V_9 = 0 ;
unsigned V_193 ;
T_12 V_294 = 0 ;
T_8 V_295 = 0 ;
T_8 V_296 = 0 ;
char V_297 [ V_207 ] ;
struct V_47 * V_47 = V_87 -> V_198 ;
T_6 V_298 ;
bool V_118 ;
switch ( type ) {
case V_299 :
if ( F_116 ( V_47 ) == V_121 ) {
F_309 ( L_74 ) ;
break;
}
if ( ! ( V_292 & V_300 ) && ! F_310 ( V_87 ) )
( void ) F_197 ( V_47 , false ) ;
V_9 = F_311 ( V_47 -> V_120 , & V_295 ) ;
if ( V_9 ) {
F_124 ( L_75 ,
F_117 ( V_47 ) , V_9 ) ;
goto V_301;
}
V_9 = F_312 ( V_47 -> V_120 , & V_296 ) ;
if ( V_9 ) {
F_124 ( L_76 ,
F_117 ( V_47 ) , V_9 ) ;
goto V_301;
}
V_298 = F_313 ( V_47 -> V_86 ) ;
F_309 ( L_77 ,
( unsigned ) V_302 ,
( unsigned long long ) ( V_296 - V_295 ) ,
( unsigned long long ) V_296 ,
( unsigned long long ) V_47 -> V_93 ,
( unsigned long long ) F_72 ( V_298 ) ,
( unsigned long long ) F_72 ( V_47 -> V_230 ) ,
( unsigned ) F_136 ( & V_47 -> V_95 . V_127 ) ,
( unsigned ) F_136 ( & V_47 -> V_95 . V_129 ) ,
( unsigned ) F_136 ( & V_47 -> V_95 . V_131 ) ,
( unsigned ) F_136 ( & V_47 -> V_95 . V_133 ) ,
( unsigned ) F_136 ( & V_47 -> V_95 . V_140 ) ,
( unsigned ) F_136 ( & V_47 -> V_95 . V_138 ) ,
( unsigned long ) F_136 ( & V_47 -> V_85 ) ) ;
if ( V_47 -> V_50 . V_218 == 2 )
F_309 ( L_78 ) ;
else
F_309 ( L_79 ) ;
if ( F_36 ( & V_47 -> V_50 ) )
F_309 ( L_80 ) ;
else if ( F_38 ( & V_47 -> V_50 ) )
F_309 ( L_81 ) ;
else if ( F_37 ( & V_47 -> V_50 ) )
F_309 ( L_82 ) ;
else {
F_124 ( L_83 ,
F_117 ( V_47 ) , ( int ) V_47 -> V_50 . V_43 ) ;
goto V_301;
}
F_309 ( L_84 , ( unsigned long long ) V_47 -> V_172 ) ;
F_309 ( L_85 , F_314 ( V_47 -> V_86 ) ) ;
if ( V_294 < V_293 ) {
V_9 = F_315 ( V_47 -> V_86 , V_243 , V_293 , & V_294 ) ;
if ( V_9 )
F_124 ( L_86 ,
F_117 ( V_47 ) , V_9 ) ;
}
if ( F_116 ( V_47 ) == V_123 )
F_309 ( L_87 ) ;
else
F_309 ( L_88 ) ;
V_9 = F_123 ( V_47 -> V_120 , & V_118 ) ;
if ( V_9 || V_118 )
F_309 ( L_89 ) ;
else
F_309 ( L_90 ) ;
break;
case V_303 :
F_316 ( V_297 , V_47 -> V_194 -> V_99 -> V_304 ) ;
F_309 ( L_85 , V_297 ) ;
F_316 ( V_297 , V_47 -> V_103 -> V_99 -> V_304 ) ;
F_309 ( L_85 , V_297 ) ;
F_316 ( V_297 , V_47 -> V_98 -> V_99 -> V_304 ) ;
F_309 ( L_91 , V_297 ) ;
for ( V_193 = 0 ; V_193 < V_47 -> V_195 - 1 ; V_193 ++ )
F_309 ( L_92 , V_47 -> V_196 [ V_193 ] ) ;
if ( V_47 -> V_195 )
F_309 ( L_92 , V_47 -> V_196 [ V_47 -> V_195 - 1 ] ) ;
}
return;
V_301:
F_309 ( L_93 ) ;
}
static int F_317 ( struct V_47 * V_47 , const char * V_305 ,
struct V_306 * V_243 )
{
char V_307 ;
T_13 V_21 , V_144 ;
int V_9 ;
V_9 = sscanf ( V_305 , L_94 , & V_21 , & V_144 , & V_307 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 2 ) {
V_243 -> V_61 = F_262 ( V_21 ) ;
V_243 -> V_62 = F_262 ( V_144 ) ;
return 0 ;
}
V_9 = sscanf ( V_305 , L_95 , & V_21 , & V_307 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 1 ) {
V_243 -> V_61 = F_262 ( V_21 ) ;
V_243 -> V_62 = F_262 ( F_72 ( V_243 -> V_61 ) + 1u ) ;
return 0 ;
}
F_124 ( L_96 , F_117 ( V_47 ) , V_305 ) ;
return - V_187 ;
}
static int F_318 ( struct V_47 * V_47 , struct V_306 * V_308 )
{
T_13 V_21 = F_72 ( V_308 -> V_61 ) ;
T_13 V_144 = F_72 ( V_308 -> V_62 ) ;
T_13 V_90 = F_72 ( V_47 -> V_230 ) ;
if ( V_21 >= V_90 ) {
F_124 ( L_97 ,
F_117 ( V_47 ) , V_21 , V_90 ) ;
return - V_187 ;
}
if ( V_144 > V_90 ) {
F_124 ( L_98 ,
F_117 ( V_47 ) , V_144 , V_90 ) ;
return - V_187 ;
}
if ( V_21 >= V_144 ) {
F_124 ( L_99 ,
F_117 ( V_47 ) , V_21 , V_144 ) ;
return - V_187 ;
}
return 0 ;
}
static inline T_6 F_319 ( T_6 V_21 )
{
return F_262 ( F_72 ( V_21 ) + 1 ) ;
}
static int F_320 ( struct V_47 * V_47 , struct V_306 * V_308 )
{
int V_9 = 0 ;
while ( V_308 -> V_61 != V_308 -> V_62 ) {
V_9 = F_183 ( V_47 , V_308 -> V_61 ) ;
if ( V_9 )
return V_9 ;
V_308 -> V_61 = F_319 ( V_308 -> V_61 ) ;
}
V_47 -> V_267 = true ;
return V_9 ;
}
static int F_321 ( struct V_47 * V_47 , unsigned V_156 ,
const char * * V_309 )
{
int V_9 = 0 ;
unsigned V_193 ;
struct V_306 V_308 ;
if ( ! F_38 ( & V_47 -> V_50 ) ) {
F_124 ( L_100 ,
F_117 ( V_47 ) ) ;
return - V_165 ;
}
for ( V_193 = 0 ; V_193 < V_156 ; V_193 ++ ) {
V_9 = F_317 ( V_47 , V_309 [ V_193 ] , & V_308 ) ;
if ( V_9 )
break;
V_9 = F_318 ( V_47 , & V_308 ) ;
if ( V_9 )
break;
V_9 = F_320 ( V_47 , & V_308 ) ;
if ( V_9 )
break;
}
return V_9 ;
}
static int F_322 ( struct V_197 * V_87 , unsigned V_205 , char * * V_225 )
{
struct V_47 * V_47 = V_87 -> V_198 ;
if ( ! V_205 )
return - V_187 ;
if ( F_116 ( V_47 ) >= V_123 ) {
F_124 ( L_101 ,
F_117 ( V_47 ) ) ;
return - V_310 ;
}
if ( ! strcasecmp ( V_225 [ 0 ] , L_102 ) )
return F_321 ( V_47 , V_205 - 1 , ( const char * * ) V_225 + 1 ) ;
if ( V_205 != 2 )
return - V_187 ;
return F_243 ( V_47 , V_225 [ 0 ] , V_225 [ 1 ] ) ;
}
static int F_323 ( struct V_197 * V_87 ,
T_14 F_12 , void * V_311 )
{
int V_9 = 0 ;
struct V_47 * V_47 = V_87 -> V_198 ;
V_9 = F_12 ( V_87 , V_47 -> V_103 , 0 , F_223 ( V_47 -> V_103 ) , V_311 ) ;
if ( ! V_9 )
V_9 = F_12 ( V_87 , V_47 -> V_98 , 0 , V_87 -> V_11 , V_311 ) ;
return V_9 ;
}
static void F_324 ( struct V_47 * V_47 , struct V_312 * V_313 )
{
V_313 -> V_314 = F_325 ( T_1 , V_47 -> V_92 * 1024 ,
V_47 -> V_213 ) ;
V_313 -> V_315 = V_47 -> V_92 << V_177 ;
}
static void F_326 ( struct V_197 * V_87 , struct V_312 * V_313 )
{
struct V_47 * V_47 = V_87 -> V_198 ;
T_13 V_316 = V_313 -> V_317 >> V_177 ;
if ( V_316 < V_47 -> V_93 ||
F_84 ( V_316 , V_47 -> V_93 ) ) {
F_327 ( V_313 , V_47 -> V_93 << V_177 ) ;
F_328 ( V_313 , V_47 -> V_93 << V_177 ) ;
}
F_324 ( V_47 , V_313 ) ;
}
static int T_15 F_329 ( void )
{
int V_9 ;
V_9 = F_330 ( & V_318 ) ;
if ( V_9 ) {
F_124 ( L_103 , V_9 ) ;
return V_9 ;
}
V_264 = F_331 ( V_56 , 0 ) ;
if ( ! V_264 ) {
F_332 ( & V_318 ) ;
return - V_164 ;
}
return 0 ;
}
static void T_16 F_333 ( void )
{
F_332 ( & V_318 ) ;
F_334 ( V_264 ) ;
}
