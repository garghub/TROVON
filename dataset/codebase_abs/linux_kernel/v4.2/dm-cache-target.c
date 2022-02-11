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
static void F_11 ( struct V_12 * V_13 , struct V_14 * V_14 ,
T_2 * V_15 , void * V_16 )
{
V_13 -> V_15 = V_14 -> V_15 ;
V_13 -> V_16 = V_14 -> V_16 ;
V_14 -> V_15 = V_15 ;
V_14 -> V_16 = V_16 ;
}
static void F_12 ( struct V_12 * V_13 , struct V_14 * V_14 )
{
V_14 -> V_15 = V_13 -> V_15 ;
V_14 -> V_16 = V_13 -> V_16 ;
}
static void F_13 ( struct V_17 * V_17 )
{
F_14 ( V_17 -> V_18 , & V_17 -> V_19 ) ;
}
static struct V_20 * F_15 ( struct V_17 * V_17 )
{
return F_16 ( V_17 -> V_21 , V_22 ) ;
}
static void F_17 ( struct V_17 * V_17 , struct V_20 * V_23 )
{
F_18 ( V_17 -> V_21 , V_23 ) ;
}
static struct V_24 * F_19 ( struct V_17 * V_17 )
{
struct V_24 * V_25 ;
V_25 = F_20 ( V_17 -> V_26 , V_22 ) ;
if ( V_25 ) {
V_25 -> V_17 = V_17 ;
F_21 ( & V_25 -> V_17 -> V_27 ) ;
}
return V_25 ;
}
static void F_22 ( struct V_24 * V_25 )
{
struct V_17 * V_17 = V_25 -> V_17 ;
if ( F_23 ( & V_17 -> V_27 ) )
F_24 ( & V_17 -> V_28 ) ;
F_25 ( V_25 , V_17 -> V_26 ) ;
F_13 ( V_17 ) ;
}
static int F_26 ( struct V_17 * V_17 , struct V_29 * V_30 )
{
if ( ! V_30 -> V_25 ) {
V_30 -> V_25 = F_19 ( V_17 ) ;
if ( ! V_30 -> V_25 )
return - V_31 ;
}
if ( ! V_30 -> V_32 ) {
V_30 -> V_32 = F_15 ( V_17 ) ;
if ( ! V_30 -> V_32 )
return - V_31 ;
}
if ( ! V_30 -> V_33 ) {
V_30 -> V_33 = F_15 ( V_17 ) ;
if ( ! V_30 -> V_33 )
return - V_31 ;
}
return 0 ;
}
static void F_27 ( struct V_17 * V_17 , struct V_29 * V_30 )
{
if ( V_30 -> V_33 )
F_17 ( V_17 , V_30 -> V_33 ) ;
if ( V_30 -> V_32 )
F_17 ( V_17 , V_30 -> V_32 ) ;
if ( V_30 -> V_25 )
F_22 ( V_30 -> V_25 ) ;
}
static struct V_24 * F_28 ( struct V_29 * V_30 )
{
struct V_24 * V_25 = V_30 -> V_25 ;
F_29 ( ! V_25 ) ;
V_30 -> V_25 = NULL ;
return V_25 ;
}
static struct V_20 * F_30 ( struct V_29 * V_30 )
{
struct V_20 * V_9 = NULL ;
if ( V_30 -> V_32 ) {
V_9 = V_30 -> V_32 ;
V_30 -> V_32 = NULL ;
} else if ( V_30 -> V_33 ) {
V_9 = V_30 -> V_33 ;
V_30 -> V_33 = NULL ;
} else
F_31 () ;
return V_9 ;
}
static void F_32 ( struct V_29 * V_30 , struct V_20 * V_23 )
{
if ( ! V_30 -> V_33 )
V_30 -> V_33 = V_23 ;
else if ( ! V_30 -> V_32 )
V_30 -> V_32 = V_23 ;
else
F_31 () ;
}
static void F_33 ( T_3 V_34 , T_3 V_35 , struct V_36 * V_37 )
{
V_37 -> V_38 = 0 ;
V_37 -> V_39 = 0 ;
V_37 -> V_40 = F_34 ( V_34 ) ;
V_37 -> V_41 = F_34 ( V_35 ) ;
}
static int F_35 ( struct V_17 * V_17 , T_3 V_42 , T_3 V_43 ,
struct V_14 * V_14 , struct V_20 * V_44 ,
T_4 V_45 , void * V_46 ,
struct V_20 * * V_47 )
{
int V_9 ;
struct V_36 V_37 ;
F_33 ( V_42 , V_43 , & V_37 ) ;
V_9 = F_36 ( V_17 -> V_21 , & V_37 , V_14 , V_44 , V_47 ) ;
if ( V_9 )
V_45 ( V_46 , V_44 ) ;
return V_9 ;
}
static int F_37 ( struct V_17 * V_17 , T_3 V_48 ,
struct V_14 * V_14 , struct V_20 * V_44 ,
T_4 V_45 , void * V_46 ,
struct V_20 * * V_47 )
{
T_3 V_35 = F_38 ( F_34 ( V_48 ) + 1ULL ) ;
return F_35 ( V_17 , V_48 , V_35 , V_14 ,
V_44 , V_45 , V_46 , V_47 ) ;
}
static int F_39 ( struct V_17 * V_17 ,
T_3 V_48 ,
struct V_29 * V_49 ,
struct V_20 * * V_47 )
{
int V_9 ;
struct V_36 V_37 ;
struct V_20 * V_44 ;
V_44 = F_30 ( V_49 ) ;
F_33 ( V_48 , F_38 ( F_34 ( V_48 ) + 1ULL ) , & V_37 ) ;
V_9 = F_40 ( V_17 -> V_21 , & V_37 , V_44 , V_47 ) ;
if ( V_9 )
F_32 ( V_49 , V_44 ) ;
return V_9 ;
}
static bool F_41 ( struct V_17 * V_17 , T_5 V_50 )
{
return F_42 ( F_43 ( V_50 ) , V_17 -> V_51 ) ;
}
static void F_44 ( struct V_17 * V_17 , T_3 V_48 , T_5 V_52 )
{
if ( ! F_45 ( F_43 ( V_52 ) , V_17 -> V_51 ) ) {
F_21 ( & V_17 -> V_53 ) ;
F_46 ( V_17 -> V_54 , V_48 ) ;
}
}
static void F_47 ( struct V_17 * V_17 , T_3 V_48 , T_5 V_52 )
{
if ( F_48 ( F_43 ( V_52 ) , V_17 -> V_51 ) ) {
F_49 ( V_17 -> V_54 , V_48 ) ;
if ( F_50 ( & V_17 -> V_53 ) == 0 )
F_51 ( V_17 -> V_55 -> V_56 ) ;
}
}
static bool F_52 ( struct V_17 * V_17 )
{
return V_17 -> V_57 >= 0 ;
}
T_6
#endif
static T_7 F_53 ( T_7 V_50 , T_8 V_58 )
{
F_54 ( V_50 , V_58 ) ;
return V_50 ;
}
static T_7 F_55 ( struct V_17 * V_17 )
{
T_7 V_59 = V_17 -> V_60 ;
if ( F_52 ( V_17 ) )
V_59 >>= V_17 -> V_57 ;
else
V_59 = F_53 ( V_59 , V_17 -> V_61 ) ;
return V_59 ;
}
static T_9 F_56 ( struct V_17 * V_17 , T_3 V_48 )
{
return F_57 ( F_53 ( F_34 ( V_48 ) ,
F_55 ( V_17 ) ) ) ;
}
static T_3 F_58 ( struct V_17 * V_17 , T_9 V_62 )
{
return F_38 ( F_59 ( V_62 ) * F_55 ( V_17 ) ) ;
}
static void F_60 ( struct V_17 * V_17 , T_9 V_50 )
{
unsigned long V_10 ;
F_29 ( F_59 ( V_50 ) >= F_59 ( V_17 -> V_63 ) ) ;
F_21 ( & V_17 -> V_64 . V_65 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_61 ( F_59 ( V_50 ) , V_17 -> V_66 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
}
static void F_62 ( struct V_17 * V_17 , T_9 V_50 )
{
unsigned long V_10 ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_63 ( F_59 ( V_50 ) , V_17 -> V_66 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
}
static bool F_64 ( struct V_17 * V_17 , T_9 V_50 )
{
int V_9 ;
unsigned long V_10 ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
V_9 = F_42 ( F_59 ( V_50 ) , V_17 -> V_66 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
return V_9 ;
}
static bool F_65 ( struct V_17 * V_17 , T_3 V_50 )
{
int V_9 ;
unsigned long V_10 ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
V_9 = F_42 ( F_59 ( F_56 ( V_17 , V_50 ) ) ,
V_17 -> V_66 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
return V_9 ;
}
static void F_66 ( struct V_17 * V_17 )
{
struct V_67 V_64 ;
F_67 ( V_17 -> V_68 , & V_64 ) ;
F_68 ( & V_17 -> V_64 . V_69 , V_64 . V_70 ) ;
F_68 ( & V_17 -> V_64 . V_71 , V_64 . V_72 ) ;
F_68 ( & V_17 -> V_64 . V_73 , V_64 . V_74 ) ;
F_68 ( & V_17 -> V_64 . V_75 , V_64 . V_76 ) ;
}
static void F_69 ( struct V_17 * V_17 )
{
struct V_67 V_64 ;
if ( F_70 ( V_17 ) >= V_77 )
return;
V_64 . V_70 = F_71 ( & V_17 -> V_64 . V_69 ) ;
V_64 . V_72 = F_71 ( & V_17 -> V_64 . V_71 ) ;
V_64 . V_74 = F_71 ( & V_17 -> V_64 . V_73 ) ;
V_64 . V_76 = F_71 ( & V_17 -> V_64 . V_75 ) ;
F_72 ( V_17 -> V_68 , & V_64 ) ;
}
static bool F_73 ( struct V_78 * V_79 )
{
return V_79 -> V_80 == V_81 ;
}
static bool F_74 ( struct V_78 * V_79 )
{
return V_79 -> V_80 == V_82 ;
}
static bool F_75 ( struct V_78 * V_79 )
{
return V_79 -> V_80 == V_83 ;
}
static T_10 F_76 ( struct V_17 * V_17 )
{
return F_73 ( & V_17 -> V_84 ) ? V_85 : V_86 ;
}
static struct V_87 * F_77 ( struct V_14 * V_14 , T_10 V_88 )
{
struct V_87 * V_89 = F_78 ( V_14 , V_88 ) ;
F_29 ( ! V_89 ) ;
return V_89 ;
}
static struct V_87 * F_79 ( struct V_14 * V_14 , T_10 V_88 )
{
struct V_87 * V_89 = F_77 ( V_14 , V_88 ) ;
V_89 -> V_90 = false ;
V_89 -> V_91 = F_80 ( V_14 ) ;
V_89 -> V_92 = NULL ;
V_89 -> V_11 = 0 ;
return V_89 ;
}
static void F_81 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
V_14 -> V_93 = V_17 -> V_94 -> V_95 ;
}
static void F_82 ( struct V_17 * V_17 , struct V_14 * V_14 ,
T_5 V_52 )
{
T_1 V_96 = V_14 -> V_97 . V_96 ;
T_1 V_98 = F_43 ( V_52 ) ;
V_14 -> V_93 = V_17 -> V_99 -> V_95 ;
if ( ! F_52 ( V_17 ) )
V_14 -> V_97 . V_96 =
( V_98 * V_17 -> V_61 ) +
F_83 ( V_96 , V_17 -> V_61 ) ;
else
V_14 -> V_97 . V_96 =
( V_98 << V_17 -> V_57 ) |
( V_96 & ( V_17 -> V_61 - 1 ) ) ;
}
static void F_84 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
unsigned long V_10 ;
T_10 V_100 = F_76 ( V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
if ( V_17 -> V_101 &&
! ( V_14 -> V_102 & ( V_103 | V_104 | V_105 ) ) ) {
V_89 -> V_90 = true ;
V_17 -> V_101 = false ;
}
F_7 ( & V_17 -> V_3 , V_10 ) ;
}
static void F_85 ( struct V_17 * V_17 , struct V_14 * V_14 ,
T_3 V_48 )
{
F_84 ( V_17 , V_14 ) ;
F_81 ( V_17 , V_14 ) ;
if ( F_86 ( V_14 ) == V_106 )
F_62 ( V_17 , F_56 ( V_17 , V_48 ) ) ;
}
static void F_87 ( struct V_17 * V_17 , struct V_14 * V_14 ,
T_3 V_48 , T_5 V_52 )
{
F_84 ( V_17 , V_14 ) ;
F_82 ( V_17 , V_14 , V_52 ) ;
if ( F_86 ( V_14 ) == V_106 ) {
F_44 ( V_17 , V_48 , V_52 ) ;
F_62 ( V_17 , F_56 ( V_17 , V_48 ) ) ;
}
}
static T_3 F_88 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
T_1 V_107 = V_14 -> V_97 . V_96 ;
if ( ! F_52 ( V_17 ) )
( void ) F_83 ( V_107 , V_17 -> V_61 ) ;
else
V_107 >>= V_17 -> V_57 ;
return F_38 ( V_107 ) ;
}
static int F_89 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
return V_14 -> V_102 & ( V_104 | V_103 ) ;
}
static void F_90 ( struct V_17 * V_17 , struct V_14 * V_14 ,
struct V_20 * V_23 )
{
T_10 V_100 = F_76 ( V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
F_29 ( ! V_23 ) ;
F_29 ( V_89 -> V_92 ) ;
V_89 -> V_92 = F_91 ( V_17 -> V_108 ) ;
}
static bool F_92 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
return ( ( V_14 -> V_93 == V_17 -> V_94 -> V_95 ) &&
! ( V_14 -> V_102 & V_105 ) ) ;
}
static void F_93 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
T_10 V_100 = F_76 ( V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
if ( F_92 ( V_17 , V_14 ) ) {
V_89 -> V_11 = F_94 ( V_14 ) ;
F_8 ( & V_17 -> V_109 , V_89 -> V_11 ) ;
}
}
static void F_95 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
T_10 V_100 = F_76 ( V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
F_10 ( & V_17 -> V_109 , V_89 -> V_11 ) ;
}
static void F_96 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
F_93 ( V_17 , V_14 ) ;
F_97 ( V_14 ) ;
}
static void F_98 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
unsigned long V_10 ;
if ( ! F_89 ( V_17 , V_14 ) ) {
F_96 ( V_17 , V_14 ) ;
return;
}
F_6 ( & V_17 -> V_3 , V_10 ) ;
V_17 -> V_110 = true ;
F_99 ( & V_17 -> V_111 , V_14 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
}
static void F_100 ( struct V_17 * V_17 , struct V_14 * V_14 , struct V_20 * V_23 )
{
F_90 ( V_17 , V_14 , V_23 ) ;
F_98 ( V_17 , V_14 ) ;
}
static void F_101 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
unsigned long V_10 ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_99 ( & V_17 -> V_112 , V_14 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_102 ( struct V_14 * V_14 , int V_113 )
{
struct V_87 * V_89 = F_77 ( V_14 , V_85 ) ;
F_12 ( & V_89 -> V_114 , V_14 ) ;
if ( V_113 ) {
F_103 ( V_14 , V_113 ) ;
return;
}
F_104 ( & V_89 -> V_115 , V_14 ) ;
F_82 ( V_89 -> V_17 , V_14 , V_89 -> V_52 ) ;
F_101 ( V_89 -> V_17 , V_14 ) ;
}
static void F_105 ( struct V_17 * V_17 , struct V_14 * V_14 ,
T_3 V_48 , T_5 V_52 )
{
struct V_87 * V_89 = F_77 ( V_14 , V_85 ) ;
V_89 -> V_17 = V_17 ;
V_89 -> V_52 = V_52 ;
F_11 ( & V_89 -> V_114 , V_14 , F_102 , NULL ) ;
F_106 ( & V_89 -> V_115 , V_14 ) ;
F_85 ( V_89 -> V_17 , V_14 , V_48 ) ;
}
static enum V_116 F_70 ( struct V_17 * V_17 )
{
return V_17 -> V_84 . V_117 ;
}
static const char * F_107 ( struct V_17 * V_17 )
{
return F_108 ( F_109 ( V_17 -> V_55 -> V_56 ) ) ;
}
static void F_110 ( struct V_17 * V_17 , enum V_116 V_117 )
{
const char * V_118 [] = {
L_1 ,
L_2 ,
L_3
} ;
F_51 ( V_17 -> V_55 -> V_56 ) ;
F_111 ( L_4 ,
F_107 ( V_17 ) , V_118 [ ( int ) V_117 ] ) ;
}
static void F_112 ( struct V_17 * V_17 , enum V_116 V_119 )
{
bool V_120 = F_113 ( V_17 -> V_68 ) ;
enum V_116 V_121 = F_70 ( V_17 ) ;
if ( V_119 == V_122 && V_120 ) {
F_114 ( L_5 ,
F_107 ( V_17 ) ) ;
if ( V_121 != V_119 )
V_119 = V_121 ;
else
V_119 = V_77 ;
}
if ( V_121 == V_123 )
V_119 = V_123 ;
switch ( V_119 ) {
case V_123 :
case V_77 :
F_115 ( V_17 -> V_68 ) ;
break;
case V_122 :
F_116 ( V_17 -> V_68 ) ;
break;
}
V_17 -> V_84 . V_117 = V_119 ;
if ( V_119 != V_121 )
F_110 ( V_17 , V_119 ) ;
}
static void F_117 ( struct V_17 * V_17 )
{
const char * V_124 = F_107 ( V_17 ) ;
if ( F_70 ( V_17 ) >= V_77 )
return;
if ( F_118 ( V_17 -> V_68 ) ) {
F_114 ( L_6 , V_124 ) ;
F_112 ( V_17 , V_123 ) ;
}
F_119 ( L_7 , V_124 ) ;
if ( F_120 ( V_17 -> V_68 ) ) {
F_114 ( L_8 , V_124 ) ;
F_112 ( V_17 , V_123 ) ;
}
}
static void F_121 ( struct V_17 * V_17 , const char * V_125 , int V_9 )
{
F_119 ( L_9 ,
F_107 ( V_17 ) , V_125 , V_9 ) ;
F_117 ( V_17 ) ;
F_112 ( V_17 , V_77 ) ;
}
static void F_122 ( struct V_17 * V_17 )
{
F_21 ( & V_17 -> V_126 ) ;
}
static void F_123 ( struct V_17 * V_17 )
{
F_124 ( & V_17 -> V_126 ) ;
}
static void F_125 ( struct V_17 * V_17 , struct V_20 * V_23 ,
bool V_127 , struct V_128 * V_129 )
{
( V_127 ? V_130 : V_131 )
( V_17 -> V_21 , V_23 , V_129 ) ;
F_17 ( V_17 , V_23 ) ;
}
static bool F_126 ( struct V_14 * V_14 )
{
return V_14 -> V_102 & ( V_104 | V_103 | V_105 ) ;
}
static void F_127 ( struct V_17 * V_17 , struct V_20 * V_23 )
{
if ( F_126 ( V_23 -> V_127 ) )
F_125 ( V_17 , V_23 , true , & V_17 -> V_132 ) ;
else
F_128 ( & V_23 -> V_133 , & V_17 -> V_134 ) ;
}
static void F_129 ( struct V_17 * V_17 , struct V_20 * V_23 , bool V_127 )
{
unsigned long V_10 ;
if ( ! V_127 && F_130 ( V_17 -> V_21 , V_23 ) ) {
F_17 ( V_17 , V_23 ) ;
return;
}
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_127 ( V_17 , V_23 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_131 ( struct V_17 * V_17 , struct V_20 * V_23 , int V_113 )
{
F_132 ( V_17 -> V_21 , V_23 , V_113 ) ;
F_18 ( V_17 -> V_21 , V_23 ) ;
}
static void F_133 ( struct V_17 * V_17 , struct V_20 * V_23 )
{
F_131 ( V_17 , V_23 , V_135 ) ;
}
static void F_134 ( struct V_24 * V_25 )
{
F_123 ( V_25 -> V_17 ) ;
F_22 ( V_25 ) ;
}
static void F_135 ( struct V_24 * V_25 )
{
struct V_17 * V_17 = V_25 -> V_17 ;
const char * V_124 = F_107 ( V_17 ) ;
if ( V_25 -> V_136 ) {
F_119 ( L_10 , V_124 ) ;
F_44 ( V_17 , V_25 -> V_137 , V_25 -> V_52 ) ;
F_129 ( V_17 , V_25 -> V_138 , false ) ;
} else if ( V_25 -> V_139 ) {
F_119 ( L_11 , V_124 ) ;
F_136 ( V_17 -> V_54 , V_25 -> V_140 , V_25 -> V_137 ) ;
F_129 ( V_17 , V_25 -> V_138 , V_25 -> V_141 ? false : true ) ;
if ( V_25 -> V_141 )
F_129 ( V_17 , V_25 -> V_142 , true ) ;
} else {
F_119 ( L_12 , V_124 ) ;
F_137 ( V_17 -> V_54 , V_25 -> V_140 ) ;
F_129 ( V_17 , V_25 -> V_142 , true ) ;
}
F_134 ( V_25 ) ;
}
static void F_138 ( struct V_24 * V_25 )
{
int V_9 ;
unsigned long V_10 ;
struct V_17 * V_17 = V_25 -> V_17 ;
if ( V_25 -> V_136 ) {
F_47 ( V_17 , V_25 -> V_137 , V_25 -> V_52 ) ;
F_129 ( V_17 , V_25 -> V_138 , false ) ;
F_134 ( V_25 ) ;
return;
} else if ( V_25 -> V_139 ) {
V_9 = F_139 ( V_17 -> V_68 , V_25 -> V_52 ) ;
if ( V_9 ) {
F_119 ( L_13 ,
F_107 ( V_17 ) ) ;
F_121 ( V_17 , L_14 , V_9 ) ;
F_136 ( V_17 -> V_54 , V_25 -> V_140 ,
V_25 -> V_137 ) ;
if ( V_25 -> V_141 )
F_129 ( V_17 , V_25 -> V_142 , true ) ;
F_134 ( V_25 ) ;
return;
}
} else {
V_9 = F_140 ( V_17 -> V_68 , V_25 -> V_52 , V_25 -> V_140 ) ;
if ( V_9 ) {
F_119 ( L_15 ,
F_107 ( V_17 ) ) ;
F_121 ( V_17 , L_16 , V_9 ) ;
F_137 ( V_17 -> V_54 , V_25 -> V_140 ) ;
F_134 ( V_25 ) ;
return;
}
}
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_128 ( & V_25 -> V_143 , & V_17 -> V_144 ) ;
V_17 -> V_110 = true ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
}
static void F_141 ( struct V_24 * V_25 )
{
unsigned long V_10 ;
struct V_17 * V_17 = V_25 -> V_17 ;
if ( V_25 -> V_136 ) {
F_142 ( L_17 ,
F_107 ( V_17 ) ) ;
return;
} else if ( V_25 -> V_139 ) {
F_129 ( V_17 , V_25 -> V_138 , V_25 -> V_141 ? false : true ) ;
if ( V_25 -> V_141 ) {
V_25 -> V_139 = false ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_128 ( & V_25 -> V_143 , & V_17 -> V_145 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
} else {
if ( V_25 -> V_146 )
F_137 ( V_17 -> V_54 , V_25 -> V_137 ) ;
F_134 ( V_25 ) ;
}
} else {
if ( V_25 -> V_147 ) {
F_47 ( V_17 , V_25 -> V_140 , V_25 -> V_52 ) ;
F_129 ( V_17 , V_25 -> V_142 , true ) ;
} else {
F_44 ( V_17 , V_25 -> V_140 , V_25 -> V_52 ) ;
F_103 ( V_25 -> V_142 -> V_127 , 0 ) ;
F_129 ( V_17 , V_25 -> V_142 , false ) ;
}
F_134 ( V_25 ) ;
}
}
static void F_143 ( int V_148 , unsigned long V_149 , void * V_150 )
{
unsigned long V_10 ;
struct V_24 * V_25 = (struct V_24 * ) V_150 ;
struct V_17 * V_17 = V_25 -> V_17 ;
if ( V_148 || V_149 )
V_25 -> V_113 = true ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_128 ( & V_25 -> V_143 , & V_17 -> V_151 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_144 ( struct V_24 * V_25 )
{
int V_9 ;
struct V_152 V_153 , V_154 ;
struct V_17 * V_17 = V_25 -> V_17 ;
T_1 V_52 = F_43 ( V_25 -> V_52 ) ;
V_153 . V_95 = V_17 -> V_94 -> V_95 ;
V_153 . V_155 = V_17 -> V_61 ;
V_154 . V_95 = V_17 -> V_99 -> V_95 ;
V_154 . V_156 = V_52 * V_17 -> V_61 ;
V_154 . V_155 = V_17 -> V_61 ;
if ( V_25 -> V_136 || V_25 -> V_139 ) {
V_153 . V_156 = F_34 ( V_25 -> V_137 ) * V_17 -> V_61 ;
V_9 = F_145 ( V_17 -> V_157 , & V_154 , 1 , & V_153 , 0 , F_143 , V_25 ) ;
} else {
V_153 . V_156 = F_34 ( V_25 -> V_140 ) * V_17 -> V_61 ;
V_9 = F_145 ( V_17 -> V_157 , & V_153 , 1 , & V_154 , 0 , F_143 , V_25 ) ;
}
if ( V_9 < 0 ) {
F_119 ( L_18 , F_107 ( V_17 ) ) ;
F_135 ( V_25 ) ;
}
}
static void F_146 ( struct V_14 * V_14 , int V_113 )
{
struct V_24 * V_25 = V_14 -> V_16 ;
struct V_17 * V_17 = V_25 -> V_17 ;
T_10 V_100 = F_76 ( V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
unsigned long V_10 ;
F_12 ( & V_89 -> V_114 , V_14 ) ;
if ( V_113 )
V_25 -> V_113 = true ;
V_25 -> V_147 = false ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_128 ( & V_25 -> V_143 , & V_17 -> V_151 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_147 ( struct V_24 * V_25 , struct V_14 * V_14 )
{
T_10 V_100 = F_76 ( V_25 -> V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
F_11 ( & V_89 -> V_114 , V_14 , F_146 , V_25 ) ;
F_87 ( V_25 -> V_17 , V_14 , V_25 -> V_140 , V_25 -> V_52 ) ;
F_96 ( V_25 -> V_17 , V_14 ) ;
}
static bool F_148 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
return ( F_86 ( V_14 ) == V_106 ) &&
( V_14 -> V_97 . V_158 == ( V_17 -> V_61 << V_159 ) ) ;
}
static void F_149 ( struct V_24 * V_25 )
{
F_21 ( & V_25 -> V_17 -> V_64 . V_160 ) ;
F_138 ( V_25 ) ;
}
static void F_150 ( struct V_17 * V_17 , struct V_14 * V_14 ,
T_9 * V_50 , T_9 * V_161 )
{
T_1 V_162 = V_14 -> V_97 . V_96 ;
T_1 V_163 = F_151 ( V_14 ) ;
* V_50 = F_57 ( F_152 ( V_162 , V_17 -> V_60 ) ) ;
if ( V_163 - V_162 < V_17 -> V_60 )
* V_161 = * V_50 ;
else
* V_161 = F_57 ( F_53 ( V_163 , V_17 -> V_60 ) ) ;
}
static void F_153 ( struct V_24 * V_25 )
{
T_9 V_50 , V_161 ;
struct V_14 * V_14 = V_25 -> V_142 -> V_127 ;
F_150 ( V_25 -> V_17 , V_14 , & V_50 , & V_161 ) ;
while ( V_50 != V_161 ) {
F_60 ( V_25 -> V_17 , V_50 ) ;
V_50 = F_57 ( F_59 ( V_50 ) + 1 ) ;
}
F_103 ( V_14 , 0 ) ;
F_129 ( V_25 -> V_17 , V_25 -> V_142 , false ) ;
F_22 ( V_25 ) ;
}
static void F_154 ( struct V_24 * V_25 )
{
bool V_164 ;
struct V_17 * V_17 = V_25 -> V_17 ;
if ( V_25 -> V_165 ) {
F_153 ( V_25 ) ;
return;
}
if ( V_25 -> V_136 || V_25 -> V_139 )
V_164 = ! F_41 ( V_17 , V_25 -> V_52 ) ||
F_65 ( V_17 , V_25 -> V_137 ) ;
else {
struct V_14 * V_14 = V_25 -> V_142 -> V_127 ;
V_164 = F_65 ( V_17 , V_25 -> V_140 ) ;
if ( F_74 ( & V_17 -> V_84 ) &&
! V_164 && F_148 ( V_17 , V_14 ) ) {
F_147 ( V_25 , V_14 ) ;
return;
}
}
V_164 ? F_149 ( V_25 ) : F_144 ( V_25 ) ;
}
static void F_155 ( struct V_24 * V_25 )
{
if ( V_25 -> V_113 )
F_135 ( V_25 ) ;
else
F_138 ( V_25 ) ;
}
static void F_156 ( struct V_17 * V_17 , struct V_166 * V_167 ,
void (* F_157)( struct V_24 * ) )
{
unsigned long V_10 ;
struct V_166 V_143 ;
struct V_24 * V_25 , * V_168 ;
F_158 ( & V_143 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_159 ( V_167 , & V_143 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_160 (mg, tmp, &list, list)
F_157 ( V_25 ) ;
}
static void F_161 ( struct V_24 * V_25 )
{
F_128 ( & V_25 -> V_143 , & V_25 -> V_17 -> V_145 ) ;
}
static void F_162 ( struct V_24 * V_25 )
{
unsigned long V_10 ;
struct V_17 * V_17 = V_25 -> V_17 ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_161 ( V_25 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_163 ( struct V_17 * V_17 , struct V_166 * V_169 )
{
unsigned long V_10 ;
struct V_24 * V_25 , * V_168 ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_160 (mg, tmp, work, list)
F_161 ( V_25 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_164 ( struct V_17 * V_17 ,
struct V_87 * V_89 )
{
struct V_166 V_169 ;
if ( ! V_89 -> V_92 )
return;
F_158 ( & V_169 ) ;
F_165 ( V_89 -> V_92 , & V_169 ) ;
if ( ! F_166 ( & V_169 ) )
F_163 ( V_17 , & V_169 ) ;
}
static void F_167 ( struct V_24 * V_25 )
{
if ( ! F_168 ( V_25 -> V_17 -> V_108 , & V_25 -> V_143 ) )
F_162 ( V_25 ) ;
}
static void V_141 ( struct V_17 * V_17 , struct V_29 * V_49 ,
T_3 V_48 , T_5 V_52 ,
struct V_20 * V_23 )
{
struct V_24 * V_25 = F_28 ( V_49 ) ;
V_25 -> V_113 = false ;
V_25 -> V_165 = false ;
V_25 -> V_136 = false ;
V_25 -> V_139 = false ;
V_25 -> V_141 = true ;
V_25 -> V_147 = true ;
V_25 -> V_146 = false ;
V_25 -> V_17 = V_17 ;
V_25 -> V_140 = V_48 ;
V_25 -> V_52 = V_52 ;
V_25 -> V_138 = NULL ;
V_25 -> V_142 = V_23 ;
V_25 -> V_170 = V_7 ;
F_122 ( V_17 ) ;
F_167 ( V_25 ) ;
}
static void V_136 ( struct V_17 * V_17 , struct V_29 * V_49 ,
T_3 V_48 , T_5 V_52 ,
struct V_20 * V_23 )
{
struct V_24 * V_25 = F_28 ( V_49 ) ;
V_25 -> V_113 = false ;
V_25 -> V_165 = false ;
V_25 -> V_136 = true ;
V_25 -> V_139 = false ;
V_25 -> V_141 = false ;
V_25 -> V_147 = true ;
V_25 -> V_146 = false ;
V_25 -> V_17 = V_17 ;
V_25 -> V_137 = V_48 ;
V_25 -> V_52 = V_52 ;
V_25 -> V_138 = V_23 ;
V_25 -> V_142 = NULL ;
V_25 -> V_170 = V_7 ;
F_122 ( V_17 ) ;
F_167 ( V_25 ) ;
}
static void F_169 ( struct V_17 * V_17 , struct V_29 * V_49 ,
T_3 V_137 , T_3 V_140 ,
T_5 V_52 ,
struct V_20 * V_138 ,
struct V_20 * V_142 )
{
struct V_24 * V_25 = F_28 ( V_49 ) ;
V_25 -> V_113 = false ;
V_25 -> V_165 = false ;
V_25 -> V_136 = false ;
V_25 -> V_139 = true ;
V_25 -> V_141 = true ;
V_25 -> V_147 = true ;
V_25 -> V_146 = false ;
V_25 -> V_17 = V_17 ;
V_25 -> V_137 = V_137 ;
V_25 -> V_140 = V_140 ;
V_25 -> V_52 = V_52 ;
V_25 -> V_138 = V_138 ;
V_25 -> V_142 = V_142 ;
V_25 -> V_170 = V_7 ;
F_122 ( V_17 ) ;
F_167 ( V_25 ) ;
}
static void V_146 ( struct V_17 * V_17 , struct V_29 * V_49 ,
T_3 V_48 , T_5 V_52 ,
struct V_20 * V_23 )
{
struct V_24 * V_25 = F_28 ( V_49 ) ;
V_25 -> V_113 = false ;
V_25 -> V_165 = false ;
V_25 -> V_136 = false ;
V_25 -> V_139 = true ;
V_25 -> V_141 = false ;
V_25 -> V_147 = true ;
V_25 -> V_146 = true ;
V_25 -> V_17 = V_17 ;
V_25 -> V_137 = V_48 ;
V_25 -> V_52 = V_52 ;
V_25 -> V_138 = V_23 ;
V_25 -> V_142 = NULL ;
V_25 -> V_170 = V_7 ;
F_122 ( V_17 ) ;
F_167 ( V_25 ) ;
}
static void V_165 ( struct V_17 * V_17 , struct V_29 * V_49 ,
struct V_20 * V_23 )
{
struct V_24 * V_25 = F_28 ( V_49 ) ;
V_25 -> V_113 = false ;
V_25 -> V_165 = true ;
V_25 -> V_136 = false ;
V_25 -> V_139 = false ;
V_25 -> V_141 = false ;
V_25 -> V_147 = false ;
V_25 -> V_146 = false ;
V_25 -> V_17 = V_17 ;
V_25 -> V_138 = NULL ;
V_25 -> V_142 = V_23 ;
V_25 -> V_170 = V_7 ;
F_167 ( V_25 ) ;
}
static void F_170 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
unsigned long V_10 ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_99 ( & V_17 -> V_132 , V_14 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_171 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
T_10 V_100 = F_76 ( V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
F_29 ( V_14 -> V_97 . V_158 ) ;
if ( ! V_89 -> V_91 )
F_81 ( V_17 , V_14 ) ;
else
F_82 ( V_17 , V_14 , 0 ) ;
F_98 ( V_17 , V_14 ) ;
}
static void F_172 ( struct V_17 * V_17 , struct V_29 * V_49 ,
struct V_14 * V_14 )
{
int V_9 ;
T_9 V_50 , V_161 ;
struct V_20 * V_44 , * V_142 ;
F_150 ( V_17 , V_14 , & V_50 , & V_161 ) ;
if ( V_50 == V_161 ) {
F_103 ( V_14 , 0 ) ;
return;
}
V_44 = F_30 ( V_49 ) ;
V_9 = F_35 ( V_17 , F_58 ( V_17 , V_50 ) , F_58 ( V_17 , V_161 ) , V_14 , V_44 ,
( T_4 ) F_32 ,
V_49 , & V_142 ) ;
if ( V_9 > 0 )
return;
V_165 ( V_17 , V_49 , V_142 ) ;
}
static bool F_173 ( struct V_17 * V_17 )
{
T_1 V_171 = ( F_71 ( & V_17 -> V_126 ) + 1 ) *
V_17 -> V_61 ;
return V_171 < V_17 -> V_172 ;
}
static void F_174 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
F_21 ( F_86 ( V_14 ) == V_173 ?
& V_17 -> V_64 . V_69 : & V_17 -> V_64 . V_73 ) ;
}
static void F_175 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
F_21 ( F_86 ( V_14 ) == V_173 ?
& V_17 -> V_64 . V_71 : & V_17 -> V_64 . V_75 ) ;
}
static void F_176 ( void * V_150 , struct V_20 * V_23 )
{
struct V_14 * V_14 ;
struct V_174 * V_175 = V_150 ;
struct V_17 * V_17 = V_175 -> V_17 ;
F_90 ( V_17 , V_23 -> V_127 , V_23 ) ;
if ( F_86 ( V_23 -> V_127 ) == V_106 )
V_175 -> V_176 = true ;
while ( ( V_14 = F_177 ( & V_23 -> V_129 ) ) ) {
if ( F_126 ( V_14 ) ) {
F_99 ( & V_175 -> V_177 , V_14 ) ;
continue;
}
if ( F_86 ( V_14 ) == V_106 )
V_175 -> V_176 = true ;
F_99 ( & V_175 -> V_178 , V_14 ) ;
F_90 ( V_17 , V_14 , V_23 ) ;
}
}
static void F_178 ( struct V_17 * V_17 ,
struct V_20 * V_23 ,
T_3 V_48 , bool V_179 )
{
struct V_14 * V_14 ;
unsigned long V_10 ;
struct V_174 V_175 ;
V_175 . V_17 = V_17 ;
F_179 ( & V_175 . V_178 ) ;
F_179 ( & V_175 . V_177 ) ;
V_175 . V_176 = false ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_180 ( V_17 -> V_21 , F_176 , & V_175 , V_23 ) ;
F_181 ( & V_17 -> V_132 , & V_175 . V_177 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_81 ( V_17 , V_23 -> V_127 ) ;
if ( V_179 )
F_98 ( V_17 , V_23 -> V_127 ) ;
else
F_93 ( V_17 , V_23 -> V_127 ) ;
if ( V_175 . V_176 )
F_62 ( V_17 , F_56 ( V_17 , V_48 ) ) ;
while ( ( V_14 = F_177 ( & V_175 . V_178 ) ) ) {
F_81 ( V_17 , V_14 ) ;
F_98 ( V_17 , V_14 ) ;
}
}
static void F_182 ( struct V_17 * V_17 , struct V_20 * V_23 ,
T_3 V_48 , T_5 V_52 , bool V_179 )
{
struct V_14 * V_14 ;
unsigned long V_10 ;
struct V_174 V_175 ;
V_175 . V_17 = V_17 ;
F_179 ( & V_175 . V_178 ) ;
F_179 ( & V_175 . V_177 ) ;
V_175 . V_176 = false ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_180 ( V_17 -> V_21 , F_176 , & V_175 , V_23 ) ;
F_181 ( & V_17 -> V_132 , & V_175 . V_177 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_82 ( V_17 , V_23 -> V_127 , V_52 ) ;
if ( V_179 )
F_98 ( V_17 , V_23 -> V_127 ) ;
else
F_93 ( V_17 , V_23 -> V_127 ) ;
if ( V_175 . V_176 ) {
F_44 ( V_17 , V_48 , V_52 ) ;
F_62 ( V_17 , F_56 ( V_17 , V_48 ) ) ;
}
while ( ( V_14 = F_177 ( & V_175 . V_178 ) ) ) {
F_82 ( V_17 , V_14 , V_52 ) ;
F_98 ( V_17 , V_14 ) ;
}
}
static int F_183 ( struct V_180 * V_181 , T_3 V_50 )
{
F_31 () ;
return 0 ;
}
static int F_184 ( struct V_180 * V_181 , T_3 V_50 )
{
struct V_182 * V_183 = F_185 ( V_181 , struct V_182 , V_181 ) ;
struct V_20 * V_44 = F_30 ( V_183 -> V_49 ) ;
return F_37 ( V_183 -> V_17 , V_50 , NULL , V_44 ,
( T_4 ) F_32 ,
V_183 -> V_49 , & V_183 -> V_23 ) ;
}
static void F_186 ( struct V_17 * V_17 , struct V_29 * V_49 ,
struct V_20 * V_142 )
{
int V_9 ;
bool V_184 = true ;
struct V_14 * V_14 = V_142 -> V_127 ;
T_3 V_98 = F_88 ( V_17 , V_14 ) ;
struct V_185 V_186 ;
bool V_187 = F_75 ( & V_17 -> V_84 ) ;
bool V_188 , V_189 ;
struct V_182 V_190 ;
V_188 = F_65 ( V_17 , V_98 ) || F_148 ( V_17 , V_14 ) ;
V_189 = ! V_187 && ( V_188 || F_173 ( V_17 ) ) ;
V_190 . V_181 . F_157 = F_184 ;
V_190 . V_17 = V_17 ;
V_190 . V_49 = V_49 ;
V_190 . V_23 = NULL ;
V_9 = F_187 ( V_17 -> V_54 , V_98 , true , V_189 , V_188 ,
V_14 , & V_190 . V_181 , & V_186 ) ;
if ( V_9 == - V_191 )
V_186 . V_125 = V_192 ;
switch ( V_186 . V_125 ) {
case V_193 :
if ( V_187 ) {
F_175 ( V_17 , V_14 ) ;
if ( F_86 ( V_14 ) == V_106 ) {
F_21 ( & V_17 -> V_64 . V_194 ) ;
V_146 ( V_17 , V_49 , V_98 , V_186 . V_52 , V_142 ) ;
V_184 = false ;
} else {
F_85 ( V_17 , V_14 , V_98 ) ;
F_100 ( V_17 , V_14 , V_142 ) ;
}
} else {
F_174 ( V_17 , V_14 ) ;
if ( F_86 ( V_14 ) == V_106 &&
F_73 ( & V_17 -> V_84 ) &&
! F_41 ( V_17 , V_186 . V_52 ) ) {
F_105 ( V_17 , V_14 , V_98 , V_186 . V_52 ) ;
F_100 ( V_17 , V_14 , V_142 ) ;
} else {
F_182 ( V_17 , V_142 , V_98 , V_186 . V_52 , true ) ;
V_184 = false ;
}
}
break;
case V_192 :
F_175 ( V_17 , V_14 ) ;
F_178 ( V_17 , V_142 , V_98 , true ) ;
V_184 = false ;
break;
case V_195 :
F_21 ( & V_17 -> V_64 . V_196 ) ;
V_141 ( V_17 , V_49 , V_98 , V_186 . V_52 , V_142 ) ;
V_184 = false ;
break;
case V_197 :
F_21 ( & V_17 -> V_64 . V_194 ) ;
F_21 ( & V_17 -> V_64 . V_196 ) ;
F_169 ( V_17 , V_49 , V_186 . V_137 ,
V_98 , V_186 . V_52 ,
V_190 . V_23 , V_142 ) ;
V_184 = false ;
break;
default:
F_119 ( L_19 ,
F_107 ( V_17 ) , V_198 ,
( unsigned ) V_186 . V_125 ) ;
F_188 ( V_14 ) ;
}
if ( V_184 )
F_129 ( V_17 , V_142 , false ) ;
}
static void F_189 ( struct V_17 * V_17 , struct V_29 * V_49 ,
struct V_14 * V_14 )
{
int V_9 ;
T_3 V_98 = F_88 ( V_17 , V_14 ) ;
struct V_20 * V_44 , * V_142 ;
V_44 = F_30 ( V_49 ) ;
V_9 = F_37 ( V_17 , V_98 , V_14 , V_44 ,
( T_4 ) F_32 ,
V_49 , & V_142 ) ;
if ( V_9 > 0 )
return;
F_186 ( V_17 , V_49 , V_142 ) ;
}
static int F_190 ( struct V_17 * V_17 )
{
return V_7 < V_17 -> V_199 ||
V_7 > V_17 -> V_199 + V_200 ;
}
static int F_191 ( struct V_17 * V_17 , bool V_201 )
{
int V_9 ;
if ( F_70 ( V_17 ) >= V_77 )
return - V_202 ;
F_21 ( & V_17 -> V_64 . V_203 ) ;
V_9 = F_192 ( V_17 -> V_68 , V_201 ) ;
if ( V_9 )
F_121 ( V_17 , L_20 , V_9 ) ;
return V_9 ;
}
static int F_193 ( struct V_17 * V_17 )
{
int V_9 = 0 ;
if ( ( V_17 -> V_110 || F_190 ( V_17 ) ) &&
F_194 ( V_17 -> V_68 ) ) {
V_9 = F_191 ( V_17 , false ) ;
V_17 -> V_110 = false ;
V_17 -> V_199 = V_7 ;
}
return V_9 ;
}
static void F_195 ( struct V_17 * V_17 )
{
bool V_204 = false ;
unsigned long V_10 ;
struct V_128 V_129 ;
struct V_14 * V_14 ;
struct V_29 V_49 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
F_179 ( & V_129 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_181 ( & V_129 , & V_17 -> V_132 ) ;
F_179 ( & V_17 -> V_132 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
while ( ! F_196 ( & V_129 ) ) {
V_204 = true ;
if ( F_26 ( V_17 , & V_49 ) ) {
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_181 ( & V_17 -> V_132 , & V_129 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
break;
}
V_14 = F_177 ( & V_129 ) ;
if ( V_14 -> V_102 & V_104 )
F_171 ( V_17 , V_14 ) ;
else if ( V_14 -> V_102 & V_105 )
F_172 ( V_17 , & V_49 , V_14 ) ;
else
F_189 ( V_17 , & V_49 , V_14 ) ;
}
if ( V_204 )
F_27 ( V_17 , & V_49 ) ;
}
static void F_197 ( struct V_17 * V_17 )
{
bool V_204 = false ;
unsigned long V_10 ;
struct V_20 * V_23 , * V_168 ;
struct V_166 V_205 ;
struct V_29 V_49 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
F_158 ( & V_205 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_159 ( & V_17 -> V_134 , & V_205 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_160 (cell, tmp, &cells, user_list) {
V_204 = true ;
if ( F_26 ( V_17 , & V_49 ) ) {
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_198 ( & V_205 , & V_17 -> V_134 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
break;
}
F_186 ( V_17 , & V_49 , V_23 ) ;
}
if ( V_204 )
F_27 ( V_17 , & V_49 ) ;
}
static void F_199 ( struct V_17 * V_17 , bool V_206 )
{
unsigned long V_10 ;
struct V_128 V_129 ;
struct V_14 * V_14 ;
F_179 ( & V_129 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_181 ( & V_129 , & V_17 -> V_111 ) ;
F_179 ( & V_17 -> V_111 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
while ( ( V_14 = F_177 ( & V_129 ) ) )
V_206 ? F_96 ( V_17 , V_14 ) : F_188 ( V_14 ) ;
}
static void F_200 ( struct V_17 * V_17 )
{
unsigned long V_10 ;
struct V_128 V_129 ;
struct V_14 * V_14 ;
F_179 ( & V_129 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_181 ( & V_129 , & V_17 -> V_112 ) ;
F_179 ( & V_17 -> V_112 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
while ( ( V_14 = F_177 ( & V_129 ) ) )
F_96 ( V_17 , V_14 ) ;
}
static void F_201 ( struct V_17 * V_17 )
{
bool V_204 = false ;
T_3 V_48 ;
T_5 V_52 ;
struct V_29 V_49 ;
struct V_20 * V_138 ;
bool V_207 = ! F_5 ( & V_17 -> V_109 , V_208 ) ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
while ( F_173 ( V_17 ) ) {
if ( F_202 ( V_17 -> V_54 , & V_48 , & V_52 , V_207 ) )
break;
V_204 = true ;
if ( F_26 ( V_17 , & V_49 ) ||
F_39 ( V_17 , V_48 , & V_49 , & V_138 ) ) {
F_46 ( V_17 -> V_54 , V_48 ) ;
break;
}
V_136 ( V_17 , & V_49 , V_48 , V_52 , V_138 ) ;
}
if ( V_204 )
F_27 ( V_17 , & V_49 ) ;
}
static void F_203 ( struct V_17 * V_17 , struct V_209 * V_210 )
{
int V_9 = 0 ;
T_11 V_34 = F_43 ( V_210 -> V_211 -> V_34 ) ;
T_11 V_35 = F_43 ( V_210 -> V_211 -> V_35 ) ;
while ( V_34 != V_35 ) {
V_9 = F_204 ( V_17 -> V_54 , F_205 ( V_34 ) ) ;
if ( ! V_9 ) {
V_9 = F_139 ( V_17 -> V_68 , F_205 ( V_34 ) ) ;
if ( V_9 ) {
F_121 ( V_17 , L_14 , V_9 ) ;
break;
}
} else if ( V_9 == - V_212 ) {
V_9 = 0 ;
} else {
F_114 ( L_21 , F_107 ( V_17 ) ) ;
break;
}
V_34 ++ ;
}
V_17 -> V_110 = true ;
V_210 -> V_113 = V_9 ;
F_68 ( & V_210 -> V_213 , 1 ) ;
F_24 ( & V_210 -> V_214 ) ;
}
static void F_206 ( struct V_17 * V_17 )
{
struct V_166 V_143 ;
struct V_209 * V_210 , * V_168 ;
F_158 ( & V_143 ) ;
F_207 ( & V_17 -> V_215 ) ;
F_159 ( & V_17 -> V_216 , & V_143 ) ;
F_208 ( & V_17 -> V_215 ) ;
F_160 (req, tmp, &list, list)
F_203 ( V_17 , V_210 ) ;
}
static bool F_209 ( struct V_17 * V_17 )
{
return F_71 ( & V_17 -> V_217 ) ;
}
static void F_210 ( struct V_17 * V_17 )
{
if ( F_209 ( V_17 ) ) {
F_21 ( & V_17 -> V_218 ) ;
F_24 ( & V_17 -> V_219 ) ;
}
}
static void F_211 ( struct V_17 * V_17 )
{
F_212 ( V_17 -> V_219 , F_71 ( & V_17 -> V_218 ) ) ;
}
static void F_213 ( struct V_17 * V_17 )
{
F_21 ( & V_17 -> V_217 ) ;
F_211 ( V_17 ) ;
}
static void F_214 ( struct V_17 * V_17 )
{
F_68 ( & V_17 -> V_217 , 0 ) ;
F_68 ( & V_17 -> V_218 , 0 ) ;
}
static void F_215 ( struct V_17 * V_17 )
{
F_212 ( V_17 -> V_28 , ! F_71 ( & V_17 -> V_27 ) ) ;
}
static void F_216 ( struct V_17 * V_17 )
{
F_217 ( & V_17 -> V_220 ) ;
F_218 ( V_17 -> V_18 ) ;
}
static void F_219 ( struct V_17 * V_17 )
{
unsigned long V_10 ;
struct V_166 V_205 ;
struct V_20 * V_23 , * V_168 ;
F_158 ( & V_205 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_159 ( & V_17 -> V_134 , & V_205 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_160 (cell, tmp, &cells, user_list)
F_133 ( V_17 , V_23 ) ;
}
static void F_220 ( struct V_17 * V_17 )
{
struct V_14 * V_14 ;
struct V_128 V_129 ;
F_179 ( & V_129 ) ;
F_181 ( & V_129 , & V_17 -> V_132 ) ;
F_179 ( & V_17 -> V_132 ) ;
while ( ( V_14 = F_177 ( & V_129 ) ) )
F_103 ( V_14 , V_135 ) ;
}
static int F_221 ( struct V_17 * V_17 )
{
if ( F_209 ( V_17 ) )
return ! F_166 ( & V_17 -> V_145 ) ||
! F_166 ( & V_17 -> V_151 ) ||
! F_166 ( & V_17 -> V_144 ) ;
else
return ! F_196 ( & V_17 -> V_132 ) ||
! F_166 ( & V_17 -> V_134 ) ||
! F_196 ( & V_17 -> V_111 ) ||
! F_196 ( & V_17 -> V_112 ) ||
! F_166 ( & V_17 -> V_145 ) ||
! F_166 ( & V_17 -> V_151 ) ||
! F_166 ( & V_17 -> V_144 ) ||
V_17 -> V_146 ;
}
static void F_222 ( struct V_221 * V_222 )
{
struct V_17 * V_17 = F_185 ( V_222 , struct V_17 , V_19 ) ;
do {
if ( ! F_209 ( V_17 ) ) {
F_201 ( V_17 ) ;
F_200 ( V_17 ) ;
F_195 ( V_17 ) ;
F_197 ( V_17 ) ;
F_206 ( V_17 ) ;
}
F_156 ( V_17 , & V_17 -> V_145 , F_154 ) ;
F_156 ( V_17 , & V_17 -> V_151 , F_155 ) ;
if ( F_193 ( V_17 ) ) {
F_199 ( V_17 , false ) ;
F_156 ( V_17 , & V_17 -> V_144 , F_135 ) ;
} else {
F_199 ( V_17 , true ) ;
F_156 ( V_17 , & V_17 -> V_144 ,
F_141 ) ;
}
F_210 ( V_17 ) ;
} while ( F_221 ( V_17 ) );
}
static void F_223 ( struct V_221 * V_222 )
{
struct V_17 * V_17 = F_185 ( F_224 ( V_222 ) , struct V_17 , V_220 ) ;
F_225 ( V_17 -> V_54 , true ) ;
F_13 ( V_17 ) ;
F_226 ( V_17 -> V_18 , & V_17 -> V_220 , V_200 ) ;
}
static int F_227 ( struct V_223 * V_39 , int V_224 )
{
struct V_225 * V_226 = F_228 ( V_39 -> V_95 ) ;
return F_229 ( & V_226 -> V_227 , V_224 ) ;
}
static int F_230 ( struct V_228 * V_229 , int V_224 )
{
struct V_17 * V_17 = F_185 ( V_229 , struct V_17 , V_230 ) ;
return F_227 ( V_17 -> V_94 , V_224 ) ||
F_227 ( V_17 -> V_99 , V_224 ) ;
}
static void F_231 ( struct V_17 * V_17 )
{
unsigned V_231 ;
if ( V_17 -> V_26 )
F_232 ( V_17 -> V_26 ) ;
if ( V_17 -> V_108 )
F_233 ( V_17 -> V_108 ) ;
if ( V_17 -> V_21 )
F_234 ( V_17 -> V_21 ) ;
if ( V_17 -> V_18 )
F_235 ( V_17 -> V_18 ) ;
if ( V_17 -> V_51 )
F_236 ( V_17 -> V_51 ) ;
if ( V_17 -> V_66 )
F_236 ( V_17 -> V_66 ) ;
if ( V_17 -> V_157 )
F_237 ( V_17 -> V_157 ) ;
if ( V_17 -> V_68 )
F_238 ( V_17 -> V_68 ) ;
if ( V_17 -> V_232 )
F_239 ( V_17 -> V_55 , V_17 -> V_232 ) ;
if ( V_17 -> V_94 )
F_239 ( V_17 -> V_55 , V_17 -> V_94 ) ;
if ( V_17 -> V_99 )
F_239 ( V_17 -> V_55 , V_17 -> V_99 ) ;
if ( V_17 -> V_54 )
F_240 ( V_17 -> V_54 ) ;
for ( V_231 = 0 ; V_231 < V_17 -> V_233 ; V_231 ++ )
F_241 ( V_17 -> V_234 [ V_231 ] ) ;
F_241 ( V_17 -> V_234 ) ;
F_241 ( V_17 ) ;
}
static void F_242 ( struct V_235 * V_55 )
{
struct V_17 * V_17 = V_55 -> V_236 ;
F_231 ( V_17 ) ;
}
static T_1 F_243 ( struct V_223 * V_39 )
{
return F_244 ( V_39 -> V_95 -> V_237 ) >> V_159 ;
}
static void F_245 ( struct V_238 * V_239 )
{
if ( V_239 -> V_232 )
F_239 ( V_239 -> V_55 , V_239 -> V_232 ) ;
if ( V_239 -> V_99 )
F_239 ( V_239 -> V_55 , V_239 -> V_99 ) ;
if ( V_239 -> V_94 )
F_239 ( V_239 -> V_55 , V_239 -> V_94 ) ;
F_241 ( V_239 ) ;
}
static bool F_246 ( struct V_240 * V_241 , char * * error )
{
if ( ! V_241 -> V_242 ) {
* error = L_22 ;
return false ;
}
return true ;
}
static int F_247 ( struct V_238 * V_239 , struct V_240 * V_241 ,
char * * error )
{
int V_9 ;
T_1 V_243 ;
char V_50 [ V_244 ] ;
if ( ! F_246 ( V_241 , error ) )
return - V_202 ;
V_9 = F_248 ( V_239 -> V_55 , F_249 ( V_241 ) , V_245 | V_246 ,
& V_239 -> V_232 ) ;
if ( V_9 ) {
* error = L_23 ;
return V_9 ;
}
V_243 = F_243 ( V_239 -> V_232 ) ;
if ( V_243 > V_247 )
F_250 ( L_24 ,
F_251 ( V_239 -> V_232 -> V_95 , V_50 ) , V_248 ) ;
return 0 ;
}
static int F_252 ( struct V_238 * V_239 , struct V_240 * V_241 ,
char * * error )
{
int V_9 ;
if ( ! F_246 ( V_241 , error ) )
return - V_202 ;
V_9 = F_248 ( V_239 -> V_55 , F_249 ( V_241 ) , V_245 | V_246 ,
& V_239 -> V_99 ) ;
if ( V_9 ) {
* error = L_25 ;
return V_9 ;
}
V_239 -> V_249 = F_243 ( V_239 -> V_99 ) ;
return 0 ;
}
static int F_253 ( struct V_238 * V_239 , struct V_240 * V_241 ,
char * * error )
{
int V_9 ;
if ( ! F_246 ( V_241 , error ) )
return - V_202 ;
V_9 = F_248 ( V_239 -> V_55 , F_249 ( V_241 ) , V_245 | V_246 ,
& V_239 -> V_94 ) ;
if ( V_9 ) {
* error = L_26 ;
return V_9 ;
}
V_239 -> V_250 = F_243 ( V_239 -> V_94 ) ;
if ( V_239 -> V_55 -> V_11 > V_239 -> V_250 ) {
* error = L_27 ;
return - V_202 ;
}
return 0 ;
}
static int F_254 ( struct V_238 * V_239 , struct V_240 * V_241 ,
char * * error )
{
unsigned long V_251 ;
if ( ! F_246 ( V_241 , error ) )
return - V_202 ;
if ( F_255 ( F_249 ( V_241 ) , 10 , & V_251 ) || ! V_251 ||
V_251 < V_252 ||
V_251 > V_253 ||
V_251 & ( V_252 - 1 ) ) {
* error = L_28 ;
return - V_202 ;
}
if ( V_251 > V_239 -> V_249 ) {
* error = L_29 ;
return - V_202 ;
}
V_239 -> V_251 = V_251 ;
return 0 ;
}
static void F_256 ( struct V_78 * V_254 )
{
V_254 -> V_117 = V_122 ;
V_254 -> V_80 = V_82 ;
}
static int F_257 ( struct V_238 * V_239 , struct V_240 * V_241 ,
char * * error )
{
static struct V_255 V_256 [] = {
{ 0 , 1 , L_30 } ,
} ;
int V_9 ;
unsigned V_242 ;
const char * V_257 ;
struct V_78 * V_254 = & V_239 -> V_84 ;
F_256 ( V_254 ) ;
V_9 = F_258 ( V_256 , V_241 , & V_242 , error ) ;
if ( V_9 )
return - V_202 ;
while ( V_242 -- ) {
V_257 = F_249 ( V_241 ) ;
if ( ! strcasecmp ( V_257 , L_31 ) )
V_254 -> V_80 = V_82 ;
else if ( ! strcasecmp ( V_257 , L_32 ) )
V_254 -> V_80 = V_81 ;
else if ( ! strcasecmp ( V_257 , L_33 ) )
V_254 -> V_80 = V_83 ;
else {
* error = L_34 ;
return - V_202 ;
}
}
return 0 ;
}
static int F_259 ( struct V_238 * V_239 , struct V_240 * V_241 ,
char * * error )
{
static struct V_255 V_256 [] = {
{ 0 , 1024 , L_35 } ,
} ;
int V_9 ;
if ( ! F_246 ( V_241 , error ) )
return - V_202 ;
V_239 -> V_258 = F_249 ( V_241 ) ;
V_9 = F_258 ( V_256 , V_241 , & V_239 -> V_259 , error ) ;
if ( V_9 )
return - V_202 ;
V_239 -> V_260 = ( const char * * ) V_241 -> V_261 ;
F_260 ( V_241 , V_239 -> V_259 ) ;
return 0 ;
}
static int F_261 ( struct V_238 * V_239 , int V_242 , char * * V_261 ,
char * * error )
{
int V_9 ;
struct V_240 V_241 ;
V_241 . V_242 = V_242 ;
V_241 . V_261 = V_261 ;
V_9 = F_247 ( V_239 , & V_241 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_252 ( V_239 , & V_241 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_253 ( V_239 , & V_241 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_254 ( V_239 , & V_241 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_257 ( V_239 , & V_241 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_259 ( V_239 , & V_241 , error ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_262 ( struct V_17 * V_17 , const char * V_37 , const char * V_262 )
{
unsigned long V_168 ;
if ( ! strcasecmp ( V_37 , L_36 ) ) {
if ( F_255 ( V_262 , 10 , & V_168 ) )
return - V_202 ;
V_17 -> V_172 = V_168 ;
return 0 ;
}
return V_263 ;
}
static int F_263 ( struct V_17 * V_17 , const char * V_37 , const char * V_262 )
{
int V_9 = F_262 ( V_17 , V_37 , V_262 ) ;
if ( V_9 == V_263 )
V_9 = F_264 ( V_17 -> V_54 , V_37 , V_262 ) ;
if ( V_9 )
F_250 ( L_37 , V_37 , V_262 ) ;
return V_9 ;
}
static int F_265 ( struct V_17 * V_17 , int V_242 , const char * * V_261 )
{
int V_9 = 0 ;
if ( V_242 & 1 ) {
F_250 ( L_38 ) ;
return - V_202 ;
}
while ( V_242 ) {
V_9 = F_263 ( V_17 , V_261 [ 0 ] , V_261 [ 1 ] ) ;
if ( V_9 )
break;
V_242 -= 2 ;
V_261 += 2 ;
}
return V_9 ;
}
static int F_266 ( struct V_17 * V_17 , struct V_238 * V_239 ,
char * * error )
{
struct V_264 * V_30 = F_267 ( V_239 -> V_258 ,
V_17 -> V_265 ,
V_17 -> V_250 ,
V_17 -> V_61 ) ;
if ( F_268 ( V_30 ) ) {
* error = L_39 ;
return F_269 ( V_30 ) ;
}
V_17 -> V_54 = V_30 ;
return 0 ;
}
static bool F_270 ( T_1 V_60 ,
T_1 V_266 )
{
( void ) F_83 ( V_266 , V_60 ) ;
return V_266 > V_267 ;
}
static T_1 F_271 ( T_1 V_268 ,
T_1 V_266 )
{
T_1 V_60 = V_268 ;
if ( V_266 )
while ( F_270 ( V_60 , V_266 ) )
V_60 *= 2 ;
return V_60 ;
}
static void F_272 ( struct V_17 * V_17 , T_5 V_269 )
{
T_7 V_270 = F_43 ( V_269 ) ;
if ( V_270 > ( 1 << 20 ) && V_17 -> V_265 != V_269 )
F_142 ( L_40
L_41
L_42 ,
( unsigned long long ) V_270 ) ;
V_17 -> V_265 = V_269 ;
}
static int F_273 ( struct V_238 * V_239 , struct V_17 * * V_271 )
{
int V_9 = 0 ;
char * * error = & V_239 -> V_55 -> error ;
struct V_17 * V_17 ;
struct V_235 * V_55 = V_239 -> V_55 ;
T_7 V_272 ;
struct V_273 * V_68 ;
bool V_274 = V_239 -> V_84 . V_117 == V_122 ;
V_17 = F_274 ( sizeof( * V_17 ) , V_275 ) ;
if ( ! V_17 )
return - V_31 ;
V_17 -> V_55 = V_239 -> V_55 ;
V_55 -> V_236 = V_17 ;
V_55 -> V_276 = 2 ;
V_55 -> V_277 = true ;
V_55 -> V_278 = 1 ;
V_55 -> V_279 = true ;
V_55 -> V_280 = true ;
V_55 -> V_281 = false ;
V_17 -> V_84 = V_239 -> V_84 ;
V_55 -> V_282 = F_76 ( V_17 ) ;
V_17 -> V_230 . V_283 = F_230 ;
F_275 ( V_55 -> V_56 , & V_17 -> V_230 ) ;
V_17 -> V_232 = V_239 -> V_232 ;
V_17 -> V_94 = V_239 -> V_94 ;
V_17 -> V_99 = V_239 -> V_99 ;
V_239 -> V_232 = V_239 -> V_94 = V_239 -> V_99 = NULL ;
V_272 = V_17 -> V_250 = V_239 -> V_250 ;
V_272 = F_53 ( V_272 , V_239 -> V_251 ) ;
V_17 -> V_272 = F_38 ( V_272 ) ;
V_17 -> V_61 = V_239 -> V_251 ;
if ( F_276 ( V_55 , V_17 -> V_61 ) ) {
V_9 = - V_202 ;
goto V_284;
}
if ( V_239 -> V_251 & ( V_239 -> V_251 - 1 ) ) {
T_7 V_265 = V_239 -> V_249 ;
V_17 -> V_57 = - 1 ;
V_265 = F_53 ( V_265 , V_239 -> V_251 ) ;
F_272 ( V_17 , F_205 ( V_265 ) ) ;
} else {
V_17 -> V_57 = F_277 ( V_239 -> V_251 ) ;
F_272 ( V_17 , F_205 ( V_239 -> V_249 >> V_17 -> V_57 ) ) ;
}
V_9 = F_266 ( V_17 , V_239 , error ) ;
if ( V_9 )
goto V_284;
V_17 -> V_285 = V_239 -> V_259 ;
V_17 -> V_172 = V_286 ;
V_9 = F_265 ( V_17 , V_239 -> V_259 , V_239 -> V_260 ) ;
if ( V_9 ) {
* error = L_43 ;
goto V_284;
}
V_68 = F_278 ( V_17 -> V_232 -> V_95 ,
V_239 -> V_251 , V_274 ,
F_279 ( V_17 -> V_54 ) ) ;
if ( F_268 ( V_68 ) ) {
* error = L_44 ;
V_9 = F_269 ( V_68 ) ;
goto V_284;
}
V_17 -> V_68 = V_68 ;
F_112 ( V_17 , V_122 ) ;
if ( F_70 ( V_17 ) != V_122 ) {
* error = L_45 ;
V_9 = - V_202 ;
goto V_284;
}
if ( F_75 ( & V_17 -> V_84 ) ) {
bool V_287 ;
V_9 = F_280 ( V_17 -> V_68 , & V_287 ) ;
if ( V_9 ) {
* error = L_46 ;
goto V_284;
}
if ( ! V_287 ) {
* error = L_47 ;
V_9 = - V_202 ;
goto V_284;
}
}
F_2 ( & V_17 -> V_3 ) ;
F_158 ( & V_17 -> V_134 ) ;
F_179 ( & V_17 -> V_132 ) ;
F_179 ( & V_17 -> V_111 ) ;
F_179 ( & V_17 -> V_112 ) ;
F_158 ( & V_17 -> V_145 ) ;
F_158 ( & V_17 -> V_151 ) ;
F_158 ( & V_17 -> V_144 ) ;
F_68 ( & V_17 -> V_27 , 0 ) ;
F_68 ( & V_17 -> V_126 , 0 ) ;
F_281 ( & V_17 -> V_28 ) ;
F_281 ( & V_17 -> V_219 ) ;
F_68 ( & V_17 -> V_217 , 0 ) ;
F_68 ( & V_17 -> V_218 , 0 ) ;
V_9 = - V_31 ;
F_68 ( & V_17 -> V_53 , 0 ) ;
V_17 -> V_51 = F_282 ( F_43 ( V_17 -> V_265 ) ) ;
if ( ! V_17 -> V_51 ) {
* error = L_48 ;
goto V_284;
}
F_283 ( V_17 -> V_51 , F_43 ( V_17 -> V_265 ) ) ;
V_17 -> V_60 =
F_271 ( V_17 -> V_61 ,
V_17 -> V_250 ) ;
V_17 -> V_63 = F_57 ( F_152 ( V_17 -> V_250 ,
V_17 -> V_60 ) ) ;
V_17 -> V_66 = F_282 ( F_59 ( V_17 -> V_63 ) ) ;
if ( ! V_17 -> V_66 ) {
* error = L_49 ;
goto V_284;
}
F_283 ( V_17 -> V_66 , F_59 ( V_17 -> V_63 ) ) ;
V_17 -> V_157 = F_284 ( & V_288 ) ;
if ( F_268 ( V_17 -> V_157 ) ) {
* error = L_50 ;
V_9 = F_269 ( V_17 -> V_157 ) ;
goto V_284;
}
V_17 -> V_18 = F_285 ( L_51 V_289 , V_290 ) ;
if ( ! V_17 -> V_18 ) {
* error = L_52 ;
goto V_284;
}
F_286 ( & V_17 -> V_19 , F_222 ) ;
F_287 ( & V_17 -> V_220 , F_223 ) ;
V_17 -> V_199 = V_7 ;
V_17 -> V_21 = F_288 () ;
if ( ! V_17 -> V_21 ) {
* error = L_53 ;
goto V_284;
}
V_17 -> V_108 = F_289 () ;
if ( ! V_17 -> V_108 ) {
* error = L_54 ;
goto V_284;
}
V_17 -> V_26 = F_290 ( V_291 ,
V_292 ) ;
if ( ! V_17 -> V_26 ) {
* error = L_55 ;
goto V_284;
}
V_17 -> V_101 = true ;
V_17 -> V_293 = false ;
V_17 -> V_146 = false ;
V_17 -> V_110 = false ;
V_17 -> V_294 = false ;
V_17 -> V_295 = false ;
F_66 ( V_17 ) ;
F_68 ( & V_17 -> V_64 . V_194 , 0 ) ;
F_68 ( & V_17 -> V_64 . V_196 , 0 ) ;
F_68 ( & V_17 -> V_64 . V_160 , 0 ) ;
F_68 ( & V_17 -> V_64 . V_296 , 0 ) ;
F_68 ( & V_17 -> V_64 . V_203 , 0 ) ;
F_68 ( & V_17 -> V_64 . V_65 , 0 ) ;
F_2 ( & V_17 -> V_215 ) ;
F_158 ( & V_17 -> V_216 ) ;
F_1 ( & V_17 -> V_109 ) ;
* V_271 = V_17 ;
return 0 ;
V_284:
F_231 ( V_17 ) ;
return V_9 ;
}
static int F_291 ( struct V_17 * V_17 , int V_242 , const char * * V_261 )
{
unsigned V_231 ;
const char * * V_297 ;
V_297 = F_292 ( V_242 , sizeof( * V_297 ) , V_275 ) ;
if ( ! V_297 )
return - V_31 ;
for ( V_231 = 0 ; V_231 < V_242 ; V_231 ++ ) {
V_297 [ V_231 ] = F_293 ( V_261 [ V_231 ] , V_275 ) ;
if ( ! V_297 [ V_231 ] ) {
while ( V_231 -- )
F_241 ( V_297 [ V_231 ] ) ;
F_241 ( V_297 ) ;
return - V_31 ;
}
}
V_17 -> V_233 = V_242 ;
V_17 -> V_234 = V_297 ;
return 0 ;
}
static int F_294 ( struct V_235 * V_55 , unsigned V_242 , char * * V_261 )
{
int V_9 = - V_202 ;
struct V_238 * V_239 ;
struct V_17 * V_17 = NULL ;
V_239 = F_274 ( sizeof( * V_239 ) , V_275 ) ;
if ( ! V_239 ) {
V_55 -> error = L_56 ;
return - V_31 ;
}
V_239 -> V_55 = V_55 ;
V_9 = F_261 ( V_239 , V_242 , V_261 , & V_55 -> error ) ;
if ( V_9 )
goto V_298;
V_9 = F_273 ( V_239 , & V_17 ) ;
if ( V_9 )
goto V_298;
V_9 = F_291 ( V_17 , V_242 - 3 , ( const char * * ) V_261 + 3 ) ;
if ( V_9 ) {
F_231 ( V_17 ) ;
goto V_298;
}
V_55 -> V_236 = V_17 ;
V_298:
F_245 ( V_239 ) ;
return V_9 ;
}
static int F_295 ( struct V_235 * V_55 , struct V_14 * V_14 )
{
struct V_17 * V_17 = V_55 -> V_236 ;
int V_9 ;
struct V_20 * V_23 = NULL ;
T_3 V_98 = F_88 ( V_17 , V_14 ) ;
T_10 V_100 = F_76 ( V_17 ) ;
bool V_189 = false ;
bool V_188 ;
struct V_185 V_186 ;
struct V_87 * V_89 = F_79 ( V_14 , V_100 ) ;
struct V_182 V_190 ;
V_190 . V_181 . F_157 = F_183 ;
if ( F_296 ( F_34 ( V_98 ) >= F_34 ( V_17 -> V_272 ) ) ) {
F_81 ( V_17 , V_14 ) ;
F_93 ( V_17 , V_14 ) ;
return V_299 ;
}
if ( F_126 ( V_14 ) ) {
F_170 ( V_17 , V_14 ) ;
return V_300 ;
}
V_23 = F_15 ( V_17 ) ;
if ( ! V_23 ) {
F_170 ( V_17 , V_14 ) ;
return V_300 ;
}
V_9 = F_37 ( V_17 , V_98 , V_14 , V_23 ,
( T_4 ) F_17 ,
V_17 , & V_23 ) ;
if ( V_9 ) {
if ( V_9 < 0 )
F_170 ( V_17 , V_14 ) ;
return V_300 ;
}
V_188 = F_65 ( V_17 , V_98 ) || F_148 ( V_17 , V_14 ) ;
V_9 = F_187 ( V_17 -> V_54 , V_98 , false , V_189 , V_188 ,
V_14 , & V_190 . V_181 , & V_186 ) ;
if ( V_9 == - V_191 ) {
F_129 ( V_17 , V_23 , true ) ;
return V_300 ;
} else if ( V_9 ) {
F_119 ( L_57 ,
F_107 ( V_17 ) , V_9 ) ;
F_129 ( V_17 , V_23 , false ) ;
F_188 ( V_14 ) ;
return V_300 ;
}
V_9 = V_299 ;
switch ( V_186 . V_125 ) {
case V_193 :
if ( F_75 ( & V_17 -> V_84 ) ) {
if ( F_86 ( V_14 ) == V_106 ) {
F_129 ( V_17 , V_23 , true ) ;
V_9 = V_300 ;
} else {
F_175 ( V_17 , V_14 ) ;
F_85 ( V_17 , V_14 , V_98 ) ;
F_93 ( V_17 , V_14 ) ;
F_90 ( V_17 , V_14 , V_23 ) ;
F_129 ( V_17 , V_23 , false ) ;
}
} else {
F_174 ( V_17 , V_14 ) ;
if ( F_86 ( V_14 ) == V_106 && F_73 ( & V_17 -> V_84 ) &&
! F_41 ( V_17 , V_186 . V_52 ) ) {
F_105 ( V_17 , V_14 , V_98 , V_186 . V_52 ) ;
F_93 ( V_17 , V_14 ) ;
F_90 ( V_17 , V_14 , V_23 ) ;
F_129 ( V_17 , V_23 , false ) ;
} else
F_182 ( V_17 , V_23 , V_98 , V_186 . V_52 , false ) ;
}
break;
case V_192 :
F_175 ( V_17 , V_14 ) ;
if ( V_89 -> V_91 != 0 ) {
F_103 ( V_14 , 0 ) ;
F_129 ( V_17 , V_23 , false ) ;
V_9 = V_300 ;
} else
F_178 ( V_17 , V_23 , V_98 , false ) ;
break;
default:
F_119 ( L_58 ,
F_107 ( V_17 ) , V_198 ,
( unsigned ) V_186 . V_125 ) ;
F_129 ( V_17 , V_23 , false ) ;
F_188 ( V_14 ) ;
V_9 = V_300 ;
}
return V_9 ;
}
static int F_297 ( struct V_235 * V_55 , struct V_14 * V_14 , int error )
{
struct V_17 * V_17 = V_55 -> V_236 ;
unsigned long V_10 ;
T_10 V_100 = F_76 ( V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
if ( V_89 -> V_90 ) {
F_225 ( V_17 -> V_54 , false ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
V_17 -> V_101 = true ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
}
F_164 ( V_17 , V_89 ) ;
F_95 ( V_17 , V_14 ) ;
return 0 ;
}
static int F_298 ( struct V_17 * V_17 )
{
unsigned V_231 , V_9 ;
if ( F_70 ( V_17 ) >= V_77 )
return - V_202 ;
for ( V_231 = 0 ; V_231 < F_43 ( V_17 -> V_265 ) ; V_231 ++ ) {
V_9 = F_299 ( V_17 -> V_68 , F_205 ( V_231 ) ,
F_41 ( V_17 , F_205 ( V_231 ) ) ) ;
if ( V_9 ) {
F_121 ( V_17 , L_59 , V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
static int F_300 ( struct V_17 * V_17 )
{
unsigned V_231 , V_9 ;
if ( F_70 ( V_17 ) >= V_77 )
return - V_202 ;
V_9 = F_301 ( V_17 -> V_68 , V_17 -> V_60 ,
V_17 -> V_63 ) ;
if ( V_9 ) {
F_114 ( L_60 , F_107 ( V_17 ) ) ;
F_121 ( V_17 , L_61 , V_9 ) ;
return V_9 ;
}
for ( V_231 = 0 ; V_231 < F_59 ( V_17 -> V_63 ) ; V_231 ++ ) {
V_9 = F_302 ( V_17 -> V_68 , F_57 ( V_231 ) ,
F_64 ( V_17 , F_57 ( V_231 ) ) ) ;
if ( V_9 ) {
F_121 ( V_17 , L_62 , V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
static int F_303 ( struct V_17 * V_17 )
{
int V_9 ;
if ( F_70 ( V_17 ) >= V_77 )
return - V_202 ;
V_9 = F_304 ( V_17 -> V_68 , V_17 -> V_54 ) ;
if ( V_9 ) {
F_121 ( V_17 , L_63 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static bool F_305 ( struct V_17 * V_17 )
{
int V_301 , V_302 , V_303 , V_304 ;
V_301 = F_298 ( V_17 ) ;
if ( V_301 )
F_114 ( L_64 , F_107 ( V_17 ) ) ;
V_302 = F_300 ( V_17 ) ;
if ( V_302 )
F_114 ( L_65 , F_107 ( V_17 ) ) ;
F_69 ( V_17 ) ;
V_303 = F_303 ( V_17 ) ;
if ( V_303 )
F_114 ( L_66 , F_107 ( V_17 ) ) ;
V_304 = F_191 ( V_17 , ! V_301 && ! V_302 && ! V_303 ) ;
if ( V_304 )
F_114 ( L_67 , F_107 ( V_17 ) ) ;
return ! V_301 && ! V_302 && ! V_303 && ! V_304 ;
}
static void F_306 ( struct V_235 * V_55 )
{
struct V_17 * V_17 = V_55 -> V_236 ;
F_213 ( V_17 ) ;
F_215 ( V_17 ) ;
F_216 ( V_17 ) ;
F_220 ( V_17 ) ;
F_219 ( V_17 ) ;
F_214 ( V_17 ) ;
if ( F_70 ( V_17 ) == V_122 )
( void ) F_305 ( V_17 ) ;
}
static int F_307 ( void * V_150 , T_3 V_48 , T_5 V_52 ,
bool V_305 , T_8 V_306 , bool V_307 )
{
int V_9 ;
struct V_17 * V_17 = V_150 ;
V_9 = F_308 ( V_17 -> V_54 , V_48 , V_52 , V_306 , V_307 ) ;
if ( V_9 )
return V_9 ;
if ( V_305 )
F_44 ( V_17 , V_48 , V_52 ) ;
else
F_47 ( V_17 , V_48 , V_52 ) ;
return 0 ;
}
static void F_309 ( struct V_17 * V_17 ,
struct V_308 * V_309 )
{
V_309 -> V_17 = V_17 ;
V_309 -> V_310 = V_309 -> V_311 = 0 ;
}
static void F_310 ( struct V_308 * V_309 )
{
T_1 V_50 , V_161 ;
if ( V_309 -> V_310 == V_309 -> V_311 )
return;
V_50 = V_309 -> V_310 * V_309 -> V_251 ;
V_161 = V_309 -> V_311 * V_309 -> V_251 ;
V_50 = F_152 ( V_50 , V_309 -> V_17 -> V_60 ) ;
F_83 ( V_161 , V_309 -> V_17 -> V_60 ) ;
if ( V_161 > F_59 ( V_309 -> V_17 -> V_63 ) )
V_161 = F_59 ( V_309 -> V_17 -> V_63 ) ;
for (; V_50 < V_161 ; V_50 ++ )
F_60 ( V_309 -> V_17 , F_57 ( V_50 ) ) ;
}
static int F_311 ( void * V_150 , T_1 V_60 ,
T_9 V_62 , bool V_165 )
{
struct V_308 * V_309 = V_150 ;
V_309 -> V_251 = V_60 ;
if ( V_165 ) {
if ( F_59 ( V_62 ) == V_309 -> V_311 )
V_309 -> V_311 = V_309 -> V_311 + 1ULL ;
else {
F_310 ( V_309 ) ;
V_309 -> V_310 = F_59 ( V_62 ) ;
V_309 -> V_311 = V_309 -> V_310 + 1ULL ;
}
} else {
F_310 ( V_309 ) ;
V_309 -> V_310 = V_309 -> V_311 = 0 ;
}
return 0 ;
}
static T_5 F_312 ( struct V_17 * V_17 )
{
T_1 V_269 = F_243 ( V_17 -> V_99 ) ;
( void ) F_83 ( V_269 , V_17 -> V_61 ) ;
return F_205 ( V_269 ) ;
}
static bool F_313 ( struct V_17 * V_17 , T_5 V_312 )
{
if ( F_43 ( V_312 ) > F_43 ( V_17 -> V_265 ) )
return true ;
while ( F_43 ( V_312 ) < F_43 ( V_17 -> V_265 ) ) {
V_312 = F_205 ( F_43 ( V_312 ) + 1 ) ;
if ( F_41 ( V_17 , V_312 ) ) {
F_114 ( L_68 ,
F_107 ( V_17 ) ,
( unsigned long long ) F_43 ( V_312 ) ) ;
return false ;
}
}
return true ;
}
static int F_314 ( struct V_17 * V_17 , T_5 V_312 )
{
int V_9 ;
V_9 = F_315 ( V_17 -> V_68 , V_312 ) ;
if ( V_9 ) {
F_114 ( L_69 , F_107 ( V_17 ) ) ;
F_121 ( V_17 , L_70 , V_9 ) ;
return V_9 ;
}
F_272 ( V_17 , V_312 ) ;
return 0 ;
}
static int F_316 ( struct V_235 * V_55 )
{
int V_9 = 0 ;
struct V_17 * V_17 = V_55 -> V_236 ;
T_5 V_313 = F_312 ( V_17 ) ;
if ( ! V_17 -> V_293 ) {
V_9 = F_314 ( V_17 , V_313 ) ;
if ( V_9 )
return V_9 ;
V_17 -> V_293 = true ;
} else if ( V_313 != V_17 -> V_265 ) {
if ( ! F_313 ( V_17 , V_313 ) )
return - V_202 ;
V_9 = F_314 ( V_17 , V_313 ) ;
if ( V_9 )
return V_9 ;
}
if ( ! V_17 -> V_294 ) {
V_9 = F_317 ( V_17 -> V_68 , V_17 -> V_54 ,
F_307 , V_17 ) ;
if ( V_9 ) {
F_114 ( L_71 , F_107 ( V_17 ) ) ;
F_121 ( V_17 , L_72 , V_9 ) ;
return V_9 ;
}
V_17 -> V_294 = true ;
}
if ( ! V_17 -> V_295 ) {
struct V_308 V_309 ;
F_283 ( V_17 -> V_66 , F_59 ( V_17 -> V_63 ) ) ;
F_309 ( V_17 , & V_309 ) ;
V_9 = F_318 ( V_17 -> V_68 , F_311 , & V_309 ) ;
if ( V_9 ) {
F_114 ( L_73 , F_107 ( V_17 ) ) ;
F_121 ( V_17 , L_74 , V_9 ) ;
return V_9 ;
}
F_310 ( & V_309 ) ;
V_17 -> V_295 = true ;
}
return V_9 ;
}
static void F_319 ( struct V_235 * V_55 )
{
struct V_17 * V_17 = V_55 -> V_236 ;
V_17 -> V_101 = true ;
F_223 ( & V_17 -> V_220 . V_169 ) ;
}
static void F_320 ( struct V_235 * V_55 , T_12 type ,
unsigned V_314 , char * V_271 , unsigned V_315 )
{
int V_9 = 0 ;
unsigned V_231 ;
T_13 V_316 = 0 ;
T_7 V_317 = 0 ;
T_7 V_318 = 0 ;
char V_319 [ V_244 ] ;
struct V_17 * V_17 = V_55 -> V_236 ;
T_5 V_320 ;
switch ( type ) {
case V_321 :
if ( F_70 ( V_17 ) == V_123 ) {
F_321 ( L_75 ) ;
break;
}
if ( ! ( V_314 & V_322 ) && ! F_322 ( V_55 ) )
( void ) F_191 ( V_17 , false ) ;
V_9 = F_323 ( V_17 -> V_68 , & V_317 ) ;
if ( V_9 ) {
F_114 ( L_76 ,
F_107 ( V_17 ) , V_9 ) ;
goto V_113;
}
V_9 = F_324 ( V_17 -> V_68 , & V_318 ) ;
if ( V_9 ) {
F_114 ( L_77 ,
F_107 ( V_17 ) , V_9 ) ;
goto V_113;
}
V_320 = F_325 ( V_17 -> V_54 ) ;
F_321 ( L_78 ,
( unsigned ) V_323 ,
( unsigned long long ) ( V_318 - V_317 ) ,
( unsigned long long ) V_318 ,
V_17 -> V_61 ,
( unsigned long long ) F_43 ( V_320 ) ,
( unsigned long long ) F_43 ( V_17 -> V_265 ) ,
( unsigned ) F_71 ( & V_17 -> V_64 . V_69 ) ,
( unsigned ) F_71 ( & V_17 -> V_64 . V_71 ) ,
( unsigned ) F_71 ( & V_17 -> V_64 . V_73 ) ,
( unsigned ) F_71 ( & V_17 -> V_64 . V_75 ) ,
( unsigned ) F_71 ( & V_17 -> V_64 . V_194 ) ,
( unsigned ) F_71 ( & V_17 -> V_64 . V_196 ) ,
( unsigned long ) F_71 ( & V_17 -> V_53 ) ) ;
if ( F_73 ( & V_17 -> V_84 ) )
F_321 ( L_79 ) ;
else if ( F_75 ( & V_17 -> V_84 ) )
F_321 ( L_80 ) ;
else if ( F_74 ( & V_17 -> V_84 ) )
F_321 ( L_81 ) ;
else {
F_114 ( L_82 ,
F_107 ( V_17 ) , ( int ) V_17 -> V_84 . V_80 ) ;
goto V_113;
}
F_321 ( L_83 , ( unsigned long long ) V_17 -> V_172 ) ;
F_321 ( L_84 , F_326 ( V_17 -> V_54 ) ) ;
if ( V_316 < V_315 ) {
V_9 = F_327 ( V_17 -> V_54 , V_271 , V_315 , & V_316 ) ;
if ( V_9 )
F_114 ( L_85 ,
F_107 ( V_17 ) , V_9 ) ;
}
if ( F_70 ( V_17 ) == V_77 )
F_321 ( L_86 ) ;
else
F_321 ( L_87 ) ;
if ( F_113 ( V_17 -> V_68 ) )
F_321 ( L_88 ) ;
else
F_321 ( L_89 ) ;
break;
case V_324 :
F_328 ( V_319 , V_17 -> V_232 -> V_95 -> V_325 ) ;
F_321 ( L_84 , V_319 ) ;
F_328 ( V_319 , V_17 -> V_99 -> V_95 -> V_325 ) ;
F_321 ( L_84 , V_319 ) ;
F_328 ( V_319 , V_17 -> V_94 -> V_95 -> V_325 ) ;
F_321 ( L_90 , V_319 ) ;
for ( V_231 = 0 ; V_231 < V_17 -> V_233 - 1 ; V_231 ++ )
F_321 ( L_91 , V_17 -> V_234 [ V_231 ] ) ;
if ( V_17 -> V_233 )
F_321 ( L_91 , V_17 -> V_234 [ V_17 -> V_233 - 1 ] ) ;
}
return;
V_113:
F_321 ( L_92 ) ;
}
static int F_329 ( struct V_17 * V_17 , const char * V_326 ,
struct V_327 * V_271 )
{
char V_328 ;
T_11 V_50 , V_161 ;
int V_9 ;
V_9 = sscanf ( V_326 , L_93 , & V_50 , & V_161 , & V_328 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 2 ) {
V_271 -> V_34 = F_205 ( V_50 ) ;
V_271 -> V_35 = F_205 ( V_161 ) ;
return 0 ;
}
V_9 = sscanf ( V_326 , L_94 , & V_50 , & V_328 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 1 ) {
V_271 -> V_34 = F_205 ( V_50 ) ;
V_271 -> V_35 = F_205 ( F_43 ( V_271 -> V_34 ) + 1u ) ;
return 0 ;
}
F_114 ( L_95 , F_107 ( V_17 ) , V_326 ) ;
return - V_202 ;
}
static int F_330 ( struct V_17 * V_17 , struct V_327 * V_329 )
{
T_11 V_50 = F_43 ( V_329 -> V_34 ) ;
T_11 V_161 = F_43 ( V_329 -> V_35 ) ;
T_11 V_58 = F_43 ( V_17 -> V_265 ) ;
if ( V_50 >= V_58 ) {
F_114 ( L_96 ,
F_107 ( V_17 ) , V_50 , V_58 ) ;
return - V_202 ;
}
if ( V_161 > V_58 ) {
F_114 ( L_97 ,
F_107 ( V_17 ) , V_161 , V_58 ) ;
return - V_202 ;
}
if ( V_50 >= V_161 ) {
F_114 ( L_98 ,
F_107 ( V_17 ) , V_50 , V_161 ) ;
return - V_202 ;
}
return 0 ;
}
static int F_331 ( struct V_17 * V_17 , struct V_327 * V_329 )
{
struct V_209 V_210 ;
F_158 ( & V_210 . V_143 ) ;
V_210 . V_211 = V_329 ;
F_68 ( & V_210 . V_213 , 0 ) ;
V_210 . V_113 = 0 ;
F_281 ( & V_210 . V_214 ) ;
F_207 ( & V_17 -> V_215 ) ;
F_332 ( & V_210 . V_143 , & V_17 -> V_216 ) ;
F_208 ( & V_17 -> V_215 ) ;
F_13 ( V_17 ) ;
F_212 ( V_210 . V_214 , F_71 ( & V_210 . V_213 ) ) ;
return V_210 . V_113 ;
}
static int F_333 ( struct V_17 * V_17 , unsigned V_155 ,
const char * * V_330 )
{
int V_9 = 0 ;
unsigned V_231 ;
struct V_327 V_329 ;
if ( ! F_75 ( & V_17 -> V_84 ) ) {
F_114 ( L_99 ,
F_107 ( V_17 ) ) ;
return - V_331 ;
}
for ( V_231 = 0 ; V_231 < V_155 ; V_231 ++ ) {
V_9 = F_329 ( V_17 , V_330 [ V_231 ] , & V_329 ) ;
if ( V_9 )
break;
V_9 = F_330 ( V_17 , & V_329 ) ;
if ( V_9 )
break;
V_9 = F_331 ( V_17 , & V_329 ) ;
if ( V_9 )
break;
}
return V_9 ;
}
static int F_334 ( struct V_235 * V_55 , unsigned V_242 , char * * V_261 )
{
struct V_17 * V_17 = V_55 -> V_236 ;
if ( ! V_242 )
return - V_202 ;
if ( F_70 ( V_17 ) >= V_77 ) {
F_114 ( L_100 ,
F_107 ( V_17 ) ) ;
return - V_332 ;
}
if ( ! strcasecmp ( V_261 [ 0 ] , L_101 ) )
return F_333 ( V_17 , V_242 - 1 , ( const char * * ) V_261 + 1 ) ;
if ( V_242 != 2 )
return - V_202 ;
return F_263 ( V_17 , V_261 [ 0 ] , V_261 [ 1 ] ) ;
}
static int F_335 ( struct V_235 * V_55 ,
T_14 F_157 , void * V_333 )
{
int V_9 = 0 ;
struct V_17 * V_17 = V_55 -> V_236 ;
V_9 = F_157 ( V_55 , V_17 -> V_99 , 0 , F_243 ( V_17 -> V_99 ) , V_333 ) ;
if ( ! V_9 )
V_9 = F_157 ( V_55 , V_17 -> V_94 , 0 , V_55 -> V_11 , V_333 ) ;
return V_9 ;
}
static int F_336 ( struct V_235 * V_55 ,
struct V_334 * V_335 ,
struct V_336 * V_337 , int V_338 )
{
struct V_17 * V_17 = V_55 -> V_236 ;
struct V_225 * V_226 = F_228 ( V_17 -> V_94 -> V_95 ) ;
if ( ! V_226 -> V_339 )
return V_338 ;
V_335 -> V_93 = V_17 -> V_94 -> V_95 ;
return F_337 ( V_338 , V_226 -> V_339 ( V_226 , V_335 , V_337 ) ) ;
}
static void F_338 ( struct V_17 * V_17 , struct V_340 * V_341 )
{
V_341 -> V_342 = F_339 ( T_1 , V_17 -> V_60 * 1024 ,
V_17 -> V_250 ) ;
V_341 -> V_343 = V_17 -> V_60 << V_159 ;
}
static void F_340 ( struct V_235 * V_55 , struct V_340 * V_341 )
{
struct V_17 * V_17 = V_55 -> V_236 ;
T_11 V_344 = V_341 -> V_345 >> V_159 ;
if ( V_344 < V_17 -> V_61 ||
F_54 ( V_344 , V_17 -> V_61 ) ) {
F_341 ( V_341 , V_17 -> V_61 << V_159 ) ;
F_342 ( V_341 , V_17 -> V_61 << V_159 ) ;
}
F_338 ( V_17 , V_341 ) ;
}
static int T_15 F_343 ( void )
{
int V_9 ;
V_9 = F_344 ( & V_346 ) ;
if ( V_9 ) {
F_114 ( L_102 , V_9 ) ;
return V_9 ;
}
V_292 = F_345 ( V_24 , 0 ) ;
if ( ! V_292 ) {
F_346 ( & V_346 ) ;
return - V_31 ;
}
return 0 ;
}
static void T_16 F_347 ( void )
{
F_346 ( & V_346 ) ;
F_348 ( V_292 ) ;
}
