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
V_14 -> V_15 = V_15 ;
V_14 -> V_16 = V_16 ;
}
static void F_12 ( struct V_12 * V_13 , struct V_14 * V_14 )
{
V_14 -> V_15 = V_13 -> V_15 ;
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
! ( V_14 -> V_102 & ( V_103 | V_104 ) ) &&
F_85 ( V_14 ) != V_105 ) {
V_89 -> V_90 = true ;
V_17 -> V_101 = false ;
}
F_7 ( & V_17 -> V_3 , V_10 ) ;
}
static void F_86 ( struct V_17 * V_17 , struct V_14 * V_14 ,
T_3 V_48 )
{
F_84 ( V_17 , V_14 ) ;
F_81 ( V_17 , V_14 ) ;
if ( F_87 ( V_14 ) == V_106 )
F_62 ( V_17 , F_56 ( V_17 , V_48 ) ) ;
}
static void F_88 ( struct V_17 * V_17 , struct V_14 * V_14 ,
T_3 V_48 , T_5 V_52 )
{
F_84 ( V_17 , V_14 ) ;
F_82 ( V_17 , V_14 , V_52 ) ;
if ( F_87 ( V_14 ) == V_106 ) {
F_44 ( V_17 , V_48 , V_52 ) ;
F_62 ( V_17 , F_56 ( V_17 , V_48 ) ) ;
}
}
static T_3 F_89 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
T_1 V_107 = V_14 -> V_97 . V_96 ;
if ( ! F_52 ( V_17 ) )
( void ) F_83 ( V_107 , V_17 -> V_61 ) ;
else
V_107 >>= V_17 -> V_57 ;
return F_38 ( V_107 ) ;
}
static int F_90 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
return V_14 -> V_102 & ( V_104 | V_103 ) ;
}
static void F_91 ( struct V_17 * V_17 , struct V_14 * V_14 ,
struct V_20 * V_23 )
{
T_10 V_100 = F_76 ( V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
F_29 ( ! V_23 ) ;
F_29 ( V_89 -> V_92 ) ;
V_89 -> V_92 = F_92 ( V_17 -> V_108 ) ;
}
static bool F_93 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
return ( ( V_14 -> V_93 == V_17 -> V_94 -> V_95 ) &&
F_85 ( V_14 ) != V_105 ) ;
}
static void F_94 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
T_10 V_100 = F_76 ( V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
if ( F_93 ( V_17 , V_14 ) ) {
V_89 -> V_11 = F_95 ( V_14 ) ;
F_8 ( & V_17 -> V_109 , V_89 -> V_11 ) ;
}
}
static void F_96 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
T_10 V_100 = F_76 ( V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
F_10 ( & V_17 -> V_109 , V_89 -> V_11 ) ;
}
static void F_97 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
F_94 ( V_17 , V_14 ) ;
F_98 ( V_14 ) ;
}
static void F_99 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
unsigned long V_10 ;
if ( ! F_90 ( V_17 , V_14 ) ) {
F_97 ( V_17 , V_14 ) ;
return;
}
F_6 ( & V_17 -> V_3 , V_10 ) ;
V_17 -> V_110 = true ;
F_100 ( & V_17 -> V_111 , V_14 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
}
static void F_101 ( struct V_17 * V_17 , struct V_14 * V_14 , struct V_20 * V_23 )
{
F_91 ( V_17 , V_14 , V_23 ) ;
F_99 ( V_17 , V_14 ) ;
}
static void F_102 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
unsigned long V_10 ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_100 ( & V_17 -> V_112 , V_14 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_103 ( struct V_14 * V_14 )
{
struct V_87 * V_89 = F_77 ( V_14 , V_85 ) ;
F_12 ( & V_89 -> V_113 , V_14 ) ;
if ( V_14 -> V_114 ) {
F_104 ( V_14 ) ;
return;
}
F_105 ( & V_89 -> V_115 , V_14 ) ;
F_82 ( V_89 -> V_17 , V_14 , V_89 -> V_52 ) ;
F_102 ( V_89 -> V_17 , V_14 ) ;
}
static void F_106 ( struct V_17 * V_17 , struct V_14 * V_14 ,
T_3 V_48 , T_5 V_52 )
{
struct V_87 * V_89 = F_77 ( V_14 , V_85 ) ;
V_89 -> V_17 = V_17 ;
V_89 -> V_52 = V_52 ;
F_11 ( & V_89 -> V_113 , V_14 , F_103 , NULL ) ;
F_107 ( & V_89 -> V_115 , V_14 ) ;
F_86 ( V_89 -> V_17 , V_14 , V_48 ) ;
}
static enum V_116 F_70 ( struct V_17 * V_17 )
{
return V_17 -> V_84 . V_117 ;
}
static const char * F_108 ( struct V_17 * V_17 )
{
return F_109 ( F_110 ( V_17 -> V_55 -> V_56 ) ) ;
}
static void F_111 ( struct V_17 * V_17 , enum V_116 V_117 )
{
const char * V_118 [] = {
L_1 ,
L_2 ,
L_3
} ;
F_51 ( V_17 -> V_55 -> V_56 ) ;
F_112 ( L_4 ,
F_108 ( V_17 ) , V_118 [ ( int ) V_117 ] ) ;
}
static void F_113 ( struct V_17 * V_17 , enum V_116 V_119 )
{
bool V_120 ;
enum V_116 V_121 = F_70 ( V_17 ) ;
if ( F_114 ( V_17 -> V_68 , & V_120 ) ) {
F_115 ( L_5 ,
F_108 ( V_17 ) ) ;
V_119 = V_122 ;
}
if ( V_119 == V_123 && V_120 ) {
F_115 ( L_6 ,
F_108 ( V_17 ) ) ;
if ( V_121 != V_119 )
V_119 = V_121 ;
else
V_119 = V_77 ;
}
if ( V_121 == V_122 )
V_119 = V_122 ;
switch ( V_119 ) {
case V_122 :
case V_77 :
F_116 ( V_17 -> V_68 ) ;
break;
case V_123 :
F_117 ( V_17 -> V_68 ) ;
break;
}
V_17 -> V_84 . V_117 = V_119 ;
if ( V_119 != V_121 )
F_111 ( V_17 , V_119 ) ;
}
static void F_118 ( struct V_17 * V_17 )
{
const char * V_124 = F_108 ( V_17 ) ;
if ( F_70 ( V_17 ) >= V_77 )
return;
if ( F_119 ( V_17 -> V_68 ) ) {
F_115 ( L_7 , V_124 ) ;
F_113 ( V_17 , V_122 ) ;
}
F_120 ( L_8 , V_124 ) ;
if ( F_121 ( V_17 -> V_68 ) ) {
F_115 ( L_9 , V_124 ) ;
F_113 ( V_17 , V_122 ) ;
}
}
static void F_122 ( struct V_17 * V_17 , const char * V_125 , int V_9 )
{
F_120 ( L_10 ,
F_108 ( V_17 ) , V_125 , V_9 ) ;
F_118 ( V_17 ) ;
F_113 ( V_17 , V_77 ) ;
}
static void F_123 ( struct V_17 * V_17 )
{
F_21 ( & V_17 -> V_126 ) ;
}
static void F_124 ( struct V_17 * V_17 )
{
F_125 ( & V_17 -> V_126 ) ;
}
static bool F_126 ( struct V_14 * V_14 )
{
return F_85 ( V_14 ) == V_105 ||
V_14 -> V_102 & ( V_104 | V_103 ) ;
}
static void F_127 ( struct V_17 * V_17 , struct V_20 * V_23 )
{
if ( F_126 ( V_23 -> V_127 ) ) {
F_128 ( V_17 -> V_21 , V_23 , & V_17 -> V_128 ) ;
F_17 ( V_17 , V_23 ) ;
} else
F_129 ( & V_23 -> V_129 , & V_17 -> V_130 ) ;
}
static void F_130 ( struct V_17 * V_17 , struct V_20 * V_23 , bool V_127 )
{
unsigned long V_10 ;
if ( ! V_127 && F_131 ( V_17 -> V_21 , V_23 ) ) {
F_17 ( V_17 , V_23 ) ;
return;
}
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_127 ( V_17 , V_23 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_132 ( struct V_17 * V_17 , struct V_20 * V_23 , int V_131 )
{
F_133 ( V_17 -> V_21 , V_23 , V_131 ) ;
F_17 ( V_17 , V_23 ) ;
}
static void F_134 ( struct V_17 * V_17 , struct V_20 * V_23 )
{
F_132 ( V_17 , V_23 , V_132 ) ;
}
static void F_135 ( struct V_24 * V_25 )
{
struct V_17 * V_17 = V_25 -> V_17 ;
F_124 ( V_17 ) ;
F_22 ( V_25 ) ;
F_13 ( V_17 ) ;
}
static void F_136 ( struct V_24 * V_25 )
{
struct V_17 * V_17 = V_25 -> V_17 ;
const char * V_124 = F_108 ( V_17 ) ;
if ( V_25 -> V_133 ) {
F_120 ( L_11 , V_124 ) ;
F_44 ( V_17 , V_25 -> V_134 , V_25 -> V_52 ) ;
F_130 ( V_17 , V_25 -> V_135 , false ) ;
} else if ( V_25 -> V_136 ) {
F_120 ( L_12 , V_124 ) ;
F_137 ( V_17 -> V_54 , V_25 -> V_137 , V_25 -> V_134 ) ;
F_130 ( V_17 , V_25 -> V_135 , V_25 -> V_138 ? false : true ) ;
if ( V_25 -> V_138 )
F_130 ( V_17 , V_25 -> V_139 , true ) ;
} else {
F_120 ( L_13 , V_124 ) ;
F_138 ( V_17 -> V_54 , V_25 -> V_137 ) ;
F_130 ( V_17 , V_25 -> V_139 , true ) ;
}
F_135 ( V_25 ) ;
}
static void F_139 ( struct V_24 * V_25 )
{
int V_9 ;
unsigned long V_10 ;
struct V_17 * V_17 = V_25 -> V_17 ;
if ( V_25 -> V_133 ) {
F_47 ( V_17 , V_25 -> V_134 , V_25 -> V_52 ) ;
F_130 ( V_17 , V_25 -> V_135 , false ) ;
F_135 ( V_25 ) ;
return;
} else if ( V_25 -> V_136 ) {
V_9 = F_140 ( V_17 -> V_68 , V_25 -> V_52 ) ;
if ( V_9 ) {
F_120 ( L_14 ,
F_108 ( V_17 ) ) ;
F_122 ( V_17 , L_15 , V_9 ) ;
F_137 ( V_17 -> V_54 , V_25 -> V_137 ,
V_25 -> V_134 ) ;
if ( V_25 -> V_138 )
F_130 ( V_17 , V_25 -> V_139 , true ) ;
F_135 ( V_25 ) ;
return;
}
} else {
V_9 = F_141 ( V_17 -> V_68 , V_25 -> V_52 , V_25 -> V_137 ) ;
if ( V_9 ) {
F_120 ( L_16 ,
F_108 ( V_17 ) ) ;
F_122 ( V_17 , L_17 , V_9 ) ;
F_138 ( V_17 -> V_54 , V_25 -> V_137 ) ;
F_135 ( V_25 ) ;
return;
}
}
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_129 ( & V_25 -> V_140 , & V_17 -> V_141 ) ;
V_17 -> V_110 = true ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
}
static void F_142 ( struct V_24 * V_25 )
{
unsigned long V_10 ;
struct V_17 * V_17 = V_25 -> V_17 ;
if ( V_25 -> V_133 ) {
F_143 ( L_18 ,
F_108 ( V_17 ) ) ;
return;
} else if ( V_25 -> V_136 ) {
F_130 ( V_17 , V_25 -> V_135 , V_25 -> V_138 ? false : true ) ;
if ( V_25 -> V_138 ) {
V_25 -> V_136 = false ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_129 ( & V_25 -> V_140 , & V_17 -> V_142 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
} else {
if ( V_25 -> V_143 )
F_138 ( V_17 -> V_54 , V_25 -> V_134 ) ;
F_135 ( V_25 ) ;
}
} else {
if ( V_25 -> V_144 ) {
F_47 ( V_17 , V_25 -> V_137 , V_25 -> V_52 ) ;
F_130 ( V_17 , V_25 -> V_139 , true ) ;
} else {
F_44 ( V_17 , V_25 -> V_137 , V_25 -> V_52 ) ;
F_104 ( V_25 -> V_139 -> V_127 ) ;
F_130 ( V_17 , V_25 -> V_139 , false ) ;
}
F_135 ( V_25 ) ;
}
}
static void F_144 ( int V_145 , unsigned long V_146 , void * V_147 )
{
unsigned long V_10 ;
struct V_24 * V_25 = (struct V_24 * ) V_147 ;
struct V_17 * V_17 = V_25 -> V_17 ;
if ( V_145 || V_146 )
V_25 -> V_131 = true ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_129 ( & V_25 -> V_140 , & V_17 -> V_148 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_145 ( struct V_24 * V_25 )
{
int V_9 ;
struct V_149 V_150 , V_151 ;
struct V_17 * V_17 = V_25 -> V_17 ;
T_1 V_52 = F_43 ( V_25 -> V_52 ) ;
V_150 . V_95 = V_17 -> V_94 -> V_95 ;
V_150 . V_152 = V_17 -> V_61 ;
V_151 . V_95 = V_17 -> V_99 -> V_95 ;
V_151 . V_153 = V_52 * V_17 -> V_61 ;
V_151 . V_152 = V_17 -> V_61 ;
if ( V_25 -> V_133 || V_25 -> V_136 ) {
V_150 . V_153 = F_34 ( V_25 -> V_134 ) * V_17 -> V_61 ;
V_9 = F_146 ( V_17 -> V_154 , & V_151 , 1 , & V_150 , 0 , F_144 , V_25 ) ;
} else {
V_150 . V_153 = F_34 ( V_25 -> V_137 ) * V_17 -> V_61 ;
V_9 = F_146 ( V_17 -> V_154 , & V_150 , 1 , & V_151 , 0 , F_144 , V_25 ) ;
}
if ( V_9 < 0 ) {
F_120 ( L_19 , F_108 ( V_17 ) ) ;
F_136 ( V_25 ) ;
}
}
static void F_147 ( struct V_14 * V_14 )
{
struct V_24 * V_25 = V_14 -> V_16 ;
struct V_17 * V_17 = V_25 -> V_17 ;
T_10 V_100 = F_76 ( V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
unsigned long V_10 ;
F_12 ( & V_89 -> V_113 , V_14 ) ;
if ( V_14 -> V_114 )
V_25 -> V_131 = true ;
V_25 -> V_144 = false ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_129 ( & V_25 -> V_140 , & V_17 -> V_148 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_148 ( struct V_24 * V_25 , struct V_14 * V_14 )
{
T_10 V_100 = F_76 ( V_25 -> V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
F_11 ( & V_89 -> V_113 , V_14 , F_147 , V_25 ) ;
F_88 ( V_25 -> V_17 , V_14 , V_25 -> V_137 , V_25 -> V_52 ) ;
F_97 ( V_25 -> V_17 , V_14 ) ;
}
static bool F_149 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
return ( F_87 ( V_14 ) == V_106 ) &&
( V_14 -> V_97 . V_155 == ( V_17 -> V_61 << V_156 ) ) ;
}
static void F_150 ( struct V_24 * V_25 )
{
F_21 ( & V_25 -> V_17 -> V_64 . V_157 ) ;
F_139 ( V_25 ) ;
}
static void F_151 ( struct V_17 * V_17 , struct V_14 * V_14 ,
T_9 * V_50 , T_9 * V_158 )
{
T_1 V_159 = V_14 -> V_97 . V_96 ;
T_1 V_160 = F_152 ( V_14 ) ;
* V_50 = F_57 ( F_153 ( V_159 , V_17 -> V_60 ) ) ;
if ( V_160 - V_159 < V_17 -> V_60 )
* V_158 = * V_50 ;
else
* V_158 = F_57 ( F_53 ( V_160 , V_17 -> V_60 ) ) ;
}
static void F_154 ( struct V_24 * V_25 )
{
T_9 V_50 , V_158 ;
struct V_14 * V_14 = V_25 -> V_139 -> V_127 ;
struct V_17 * V_17 = V_25 -> V_17 ;
F_151 ( V_17 , V_14 , & V_50 , & V_158 ) ;
while ( V_50 != V_158 ) {
F_60 ( V_17 , V_50 ) ;
V_50 = F_57 ( F_59 ( V_50 ) + 1 ) ;
}
F_104 ( V_14 ) ;
F_130 ( V_17 , V_25 -> V_139 , false ) ;
F_22 ( V_25 ) ;
F_13 ( V_17 ) ;
}
static void F_155 ( struct V_24 * V_25 )
{
bool V_161 ;
struct V_17 * V_17 = V_25 -> V_17 ;
if ( V_25 -> V_162 ) {
F_154 ( V_25 ) ;
return;
}
if ( V_25 -> V_133 || V_25 -> V_136 )
V_161 = ! F_41 ( V_17 , V_25 -> V_52 ) ||
F_65 ( V_17 , V_25 -> V_134 ) ;
else {
struct V_14 * V_14 = V_25 -> V_139 -> V_127 ;
V_161 = F_65 ( V_17 , V_25 -> V_137 ) ;
if ( F_74 ( & V_17 -> V_84 ) &&
! V_161 && F_149 ( V_17 , V_14 ) ) {
F_148 ( V_25 , V_14 ) ;
return;
}
}
V_161 ? F_150 ( V_25 ) : F_145 ( V_25 ) ;
}
static void F_156 ( struct V_24 * V_25 )
{
if ( V_25 -> V_131 )
F_136 ( V_25 ) ;
else
F_139 ( V_25 ) ;
}
static void F_157 ( struct V_17 * V_17 , struct V_163 * V_164 ,
void (* F_158)( struct V_24 * ) )
{
unsigned long V_10 ;
struct V_163 V_140 ;
struct V_24 * V_25 , * V_165 ;
F_159 ( & V_140 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_160 ( V_164 , & V_140 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_161 (mg, tmp, &list, list)
F_158 ( V_25 ) ;
}
static void F_162 ( struct V_24 * V_25 )
{
F_129 ( & V_25 -> V_140 , & V_25 -> V_17 -> V_142 ) ;
}
static void F_163 ( struct V_24 * V_25 )
{
unsigned long V_10 ;
struct V_17 * V_17 = V_25 -> V_17 ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_162 ( V_25 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_164 ( struct V_17 * V_17 , struct V_163 * V_166 )
{
unsigned long V_10 ;
struct V_24 * V_25 , * V_165 ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_161 (mg, tmp, work, list)
F_162 ( V_25 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_165 ( struct V_17 * V_17 ,
struct V_87 * V_89 )
{
struct V_163 V_166 ;
if ( ! V_89 -> V_92 )
return;
F_159 ( & V_166 ) ;
F_166 ( V_89 -> V_92 , & V_166 ) ;
if ( ! F_167 ( & V_166 ) )
F_164 ( V_17 , & V_166 ) ;
}
static void F_168 ( struct V_24 * V_25 )
{
if ( ! F_169 ( V_25 -> V_17 -> V_108 , & V_25 -> V_140 ) )
F_163 ( V_25 ) ;
}
static void V_138 ( struct V_17 * V_17 , struct V_29 * V_49 ,
T_3 V_48 , T_5 V_52 ,
struct V_20 * V_23 )
{
struct V_24 * V_25 = F_28 ( V_49 ) ;
V_25 -> V_131 = false ;
V_25 -> V_162 = false ;
V_25 -> V_133 = false ;
V_25 -> V_136 = false ;
V_25 -> V_138 = true ;
V_25 -> V_144 = true ;
V_25 -> V_143 = false ;
V_25 -> V_17 = V_17 ;
V_25 -> V_137 = V_48 ;
V_25 -> V_52 = V_52 ;
V_25 -> V_135 = NULL ;
V_25 -> V_139 = V_23 ;
V_25 -> V_167 = V_7 ;
F_123 ( V_17 ) ;
F_168 ( V_25 ) ;
}
static void V_133 ( struct V_17 * V_17 , struct V_29 * V_49 ,
T_3 V_48 , T_5 V_52 ,
struct V_20 * V_23 )
{
struct V_24 * V_25 = F_28 ( V_49 ) ;
V_25 -> V_131 = false ;
V_25 -> V_162 = false ;
V_25 -> V_133 = true ;
V_25 -> V_136 = false ;
V_25 -> V_138 = false ;
V_25 -> V_144 = true ;
V_25 -> V_143 = false ;
V_25 -> V_17 = V_17 ;
V_25 -> V_134 = V_48 ;
V_25 -> V_52 = V_52 ;
V_25 -> V_135 = V_23 ;
V_25 -> V_139 = NULL ;
V_25 -> V_167 = V_7 ;
F_123 ( V_17 ) ;
F_168 ( V_25 ) ;
}
static void F_170 ( struct V_17 * V_17 , struct V_29 * V_49 ,
T_3 V_134 , T_3 V_137 ,
T_5 V_52 ,
struct V_20 * V_135 ,
struct V_20 * V_139 )
{
struct V_24 * V_25 = F_28 ( V_49 ) ;
V_25 -> V_131 = false ;
V_25 -> V_162 = false ;
V_25 -> V_133 = false ;
V_25 -> V_136 = true ;
V_25 -> V_138 = true ;
V_25 -> V_144 = true ;
V_25 -> V_143 = false ;
V_25 -> V_17 = V_17 ;
V_25 -> V_134 = V_134 ;
V_25 -> V_137 = V_137 ;
V_25 -> V_52 = V_52 ;
V_25 -> V_135 = V_135 ;
V_25 -> V_139 = V_139 ;
V_25 -> V_167 = V_7 ;
F_123 ( V_17 ) ;
F_168 ( V_25 ) ;
}
static void V_143 ( struct V_17 * V_17 , struct V_29 * V_49 ,
T_3 V_48 , T_5 V_52 ,
struct V_20 * V_23 )
{
struct V_24 * V_25 = F_28 ( V_49 ) ;
V_25 -> V_131 = false ;
V_25 -> V_162 = false ;
V_25 -> V_133 = false ;
V_25 -> V_136 = true ;
V_25 -> V_138 = false ;
V_25 -> V_144 = true ;
V_25 -> V_143 = true ;
V_25 -> V_17 = V_17 ;
V_25 -> V_134 = V_48 ;
V_25 -> V_52 = V_52 ;
V_25 -> V_135 = V_23 ;
V_25 -> V_139 = NULL ;
V_25 -> V_167 = V_7 ;
F_123 ( V_17 ) ;
F_168 ( V_25 ) ;
}
static void V_162 ( struct V_17 * V_17 , struct V_29 * V_49 ,
struct V_20 * V_23 )
{
struct V_24 * V_25 = F_28 ( V_49 ) ;
V_25 -> V_131 = false ;
V_25 -> V_162 = true ;
V_25 -> V_133 = false ;
V_25 -> V_136 = false ;
V_25 -> V_138 = false ;
V_25 -> V_144 = false ;
V_25 -> V_143 = false ;
V_25 -> V_17 = V_17 ;
V_25 -> V_135 = NULL ;
V_25 -> V_139 = V_23 ;
V_25 -> V_167 = V_7 ;
F_168 ( V_25 ) ;
}
static void F_171 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
unsigned long V_10 ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_100 ( & V_17 -> V_128 , V_14 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_13 ( V_17 ) ;
}
static void F_172 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
T_10 V_100 = F_76 ( V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
F_29 ( V_14 -> V_97 . V_155 ) ;
if ( ! V_89 -> V_91 )
F_81 ( V_17 , V_14 ) ;
else
F_82 ( V_17 , V_14 , 0 ) ;
F_99 ( V_17 , V_14 ) ;
}
static void F_173 ( struct V_17 * V_17 , struct V_29 * V_49 ,
struct V_14 * V_14 )
{
int V_9 ;
T_9 V_50 , V_158 ;
struct V_20 * V_44 , * V_139 ;
F_151 ( V_17 , V_14 , & V_50 , & V_158 ) ;
if ( V_50 == V_158 ) {
F_104 ( V_14 ) ;
return;
}
V_44 = F_30 ( V_49 ) ;
V_9 = F_35 ( V_17 , F_58 ( V_17 , V_50 ) , F_58 ( V_17 , V_158 ) , V_14 , V_44 ,
( T_4 ) F_32 ,
V_49 , & V_139 ) ;
if ( V_9 > 0 )
return;
V_162 ( V_17 , V_49 , V_139 ) ;
}
static bool F_174 ( struct V_17 * V_17 )
{
T_1 V_168 = ( F_71 ( & V_17 -> V_126 ) + 1 ) *
V_17 -> V_61 ;
return V_168 < V_17 -> V_169 ;
}
static void F_175 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
F_21 ( F_87 ( V_14 ) == V_170 ?
& V_17 -> V_64 . V_69 : & V_17 -> V_64 . V_73 ) ;
}
static void F_176 ( struct V_17 * V_17 , struct V_14 * V_14 )
{
F_21 ( F_87 ( V_14 ) == V_170 ?
& V_17 -> V_64 . V_71 : & V_17 -> V_64 . V_75 ) ;
}
static void F_177 ( void * V_147 , struct V_20 * V_23 )
{
struct V_14 * V_14 ;
struct V_171 * V_172 = V_147 ;
struct V_17 * V_17 = V_172 -> V_17 ;
F_91 ( V_17 , V_23 -> V_127 , V_23 ) ;
if ( F_87 ( V_23 -> V_127 ) == V_106 )
V_172 -> V_173 = true ;
while ( ( V_14 = F_178 ( & V_23 -> V_174 ) ) ) {
if ( F_126 ( V_14 ) ) {
F_100 ( & V_172 -> V_175 , V_14 ) ;
continue;
}
if ( F_87 ( V_14 ) == V_106 )
V_172 -> V_173 = true ;
F_100 ( & V_172 -> V_176 , V_14 ) ;
F_91 ( V_17 , V_14 , V_23 ) ;
}
}
static void F_179 ( struct V_17 * V_17 ,
struct V_20 * V_23 ,
T_3 V_48 , bool V_177 )
{
struct V_14 * V_14 ;
unsigned long V_10 ;
struct V_171 V_172 ;
V_172 . V_17 = V_17 ;
F_180 ( & V_172 . V_176 ) ;
F_180 ( & V_172 . V_175 ) ;
V_172 . V_173 = false ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_181 ( V_17 -> V_21 , F_177 , & V_172 , V_23 ) ;
F_182 ( & V_17 -> V_128 , & V_172 . V_175 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_81 ( V_17 , V_23 -> V_127 ) ;
if ( V_177 )
F_99 ( V_17 , V_23 -> V_127 ) ;
else
F_94 ( V_17 , V_23 -> V_127 ) ;
if ( V_172 . V_173 )
F_62 ( V_17 , F_56 ( V_17 , V_48 ) ) ;
while ( ( V_14 = F_178 ( & V_172 . V_176 ) ) ) {
F_81 ( V_17 , V_14 ) ;
F_99 ( V_17 , V_14 ) ;
}
F_17 ( V_17 , V_23 ) ;
}
static void F_183 ( struct V_17 * V_17 , struct V_20 * V_23 ,
T_3 V_48 , T_5 V_52 , bool V_177 )
{
struct V_14 * V_14 ;
unsigned long V_10 ;
struct V_171 V_172 ;
V_172 . V_17 = V_17 ;
F_180 ( & V_172 . V_176 ) ;
F_180 ( & V_172 . V_175 ) ;
V_172 . V_173 = false ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_181 ( V_17 -> V_21 , F_177 , & V_172 , V_23 ) ;
F_182 ( & V_17 -> V_128 , & V_172 . V_175 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_82 ( V_17 , V_23 -> V_127 , V_52 ) ;
if ( V_177 )
F_99 ( V_17 , V_23 -> V_127 ) ;
else
F_94 ( V_17 , V_23 -> V_127 ) ;
if ( V_172 . V_173 ) {
F_44 ( V_17 , V_48 , V_52 ) ;
F_62 ( V_17 , F_56 ( V_17 , V_48 ) ) ;
}
while ( ( V_14 = F_178 ( & V_172 . V_176 ) ) ) {
F_82 ( V_17 , V_14 , V_52 ) ;
F_99 ( V_17 , V_14 ) ;
}
F_17 ( V_17 , V_23 ) ;
}
static int F_184 ( struct V_178 * V_179 , T_3 V_50 )
{
F_31 () ;
return 0 ;
}
static int F_185 ( struct V_178 * V_179 , T_3 V_50 )
{
struct V_180 * V_181 = F_186 ( V_179 , struct V_180 , V_179 ) ;
struct V_20 * V_44 = F_30 ( V_181 -> V_49 ) ;
return F_37 ( V_181 -> V_17 , V_50 , NULL , V_44 ,
( T_4 ) F_32 ,
V_181 -> V_49 , & V_181 -> V_23 ) ;
}
static void F_187 ( struct V_17 * V_17 , struct V_29 * V_49 ,
struct V_20 * V_139 )
{
int V_9 ;
bool V_182 = true ;
struct V_14 * V_14 = V_139 -> V_127 ;
T_3 V_98 = F_89 ( V_17 , V_14 ) ;
struct V_183 V_184 ;
bool V_185 = F_75 ( & V_17 -> V_84 ) ;
bool V_186 , V_187 ;
struct V_180 V_188 ;
V_186 = F_65 ( V_17 , V_98 ) || F_149 ( V_17 , V_14 ) ;
V_187 = ! V_185 && ( V_186 || F_174 ( V_17 ) ) ;
V_188 . V_179 . F_158 = F_185 ;
V_188 . V_17 = V_17 ;
V_188 . V_49 = V_49 ;
V_188 . V_23 = NULL ;
V_9 = F_188 ( V_17 -> V_54 , V_98 , true , V_187 , V_186 ,
V_14 , & V_188 . V_179 , & V_184 ) ;
if ( V_9 == - V_189 )
V_184 . V_125 = V_190 ;
switch ( V_184 . V_125 ) {
case V_191 :
if ( V_185 ) {
F_176 ( V_17 , V_14 ) ;
if ( F_87 ( V_14 ) == V_106 ) {
F_21 ( & V_17 -> V_64 . V_192 ) ;
V_143 ( V_17 , V_49 , V_98 , V_184 . V_52 , V_139 ) ;
V_182 = false ;
} else {
F_86 ( V_17 , V_14 , V_98 ) ;
F_101 ( V_17 , V_14 , V_139 ) ;
}
} else {
F_175 ( V_17 , V_14 ) ;
if ( F_87 ( V_14 ) == V_106 &&
F_73 ( & V_17 -> V_84 ) &&
! F_41 ( V_17 , V_184 . V_52 ) ) {
F_106 ( V_17 , V_14 , V_98 , V_184 . V_52 ) ;
F_101 ( V_17 , V_14 , V_139 ) ;
} else {
F_183 ( V_17 , V_139 , V_98 , V_184 . V_52 , true ) ;
V_182 = false ;
}
}
break;
case V_190 :
F_176 ( V_17 , V_14 ) ;
F_179 ( V_17 , V_139 , V_98 , true ) ;
V_182 = false ;
break;
case V_193 :
F_21 ( & V_17 -> V_64 . V_194 ) ;
V_138 ( V_17 , V_49 , V_98 , V_184 . V_52 , V_139 ) ;
V_182 = false ;
break;
case V_195 :
F_21 ( & V_17 -> V_64 . V_192 ) ;
F_21 ( & V_17 -> V_64 . V_194 ) ;
F_170 ( V_17 , V_49 , V_184 . V_134 ,
V_98 , V_184 . V_52 ,
V_188 . V_23 , V_139 ) ;
V_182 = false ;
break;
default:
F_120 ( L_20 ,
F_108 ( V_17 ) , V_196 ,
( unsigned ) V_184 . V_125 ) ;
F_189 ( V_14 ) ;
}
if ( V_182 )
F_130 ( V_17 , V_139 , false ) ;
}
static void F_190 ( struct V_17 * V_17 , struct V_29 * V_49 ,
struct V_14 * V_14 )
{
int V_9 ;
T_3 V_98 = F_89 ( V_17 , V_14 ) ;
struct V_20 * V_44 , * V_139 ;
V_44 = F_30 ( V_49 ) ;
V_9 = F_37 ( V_17 , V_98 , V_14 , V_44 ,
( T_4 ) F_32 ,
V_49 , & V_139 ) ;
if ( V_9 > 0 )
return;
F_187 ( V_17 , V_49 , V_139 ) ;
}
static int F_191 ( struct V_17 * V_17 )
{
return V_7 < V_17 -> V_197 ||
V_7 > V_17 -> V_197 + V_198 ;
}
static int F_192 ( struct V_17 * V_17 , bool V_199 )
{
int V_9 ;
if ( F_70 ( V_17 ) >= V_77 )
return - V_200 ;
F_21 ( & V_17 -> V_64 . V_201 ) ;
V_9 = F_193 ( V_17 -> V_68 , V_199 ) ;
if ( V_9 )
F_122 ( V_17 , L_21 , V_9 ) ;
return V_9 ;
}
static int F_194 ( struct V_17 * V_17 )
{
int V_9 = 0 ;
if ( ( V_17 -> V_110 || F_191 ( V_17 ) ) &&
F_195 ( V_17 -> V_68 ) ) {
V_9 = F_192 ( V_17 , false ) ;
V_17 -> V_110 = false ;
V_17 -> V_197 = V_7 ;
}
return V_9 ;
}
static void F_196 ( struct V_17 * V_17 )
{
bool V_202 = false ;
unsigned long V_10 ;
struct V_203 V_174 ;
struct V_14 * V_14 ;
struct V_29 V_49 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
F_180 ( & V_174 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_182 ( & V_174 , & V_17 -> V_128 ) ;
F_180 ( & V_17 -> V_128 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
while ( ! F_197 ( & V_174 ) ) {
V_202 = true ;
if ( F_26 ( V_17 , & V_49 ) ) {
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_182 ( & V_17 -> V_128 , & V_174 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
break;
}
V_14 = F_178 ( & V_174 ) ;
if ( V_14 -> V_102 & V_104 )
F_172 ( V_17 , V_14 ) ;
else if ( F_85 ( V_14 ) == V_105 )
F_173 ( V_17 , & V_49 , V_14 ) ;
else
F_190 ( V_17 , & V_49 , V_14 ) ;
}
if ( V_202 )
F_27 ( V_17 , & V_49 ) ;
}
static void F_198 ( struct V_17 * V_17 )
{
bool V_202 = false ;
unsigned long V_10 ;
struct V_20 * V_23 , * V_165 ;
struct V_163 V_204 ;
struct V_29 V_49 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
F_159 ( & V_204 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_160 ( & V_17 -> V_130 , & V_204 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_161 (cell, tmp, &cells, user_list) {
V_202 = true ;
if ( F_26 ( V_17 , & V_49 ) ) {
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_199 ( & V_204 , & V_17 -> V_130 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
break;
}
F_187 ( V_17 , & V_49 , V_23 ) ;
}
if ( V_202 )
F_27 ( V_17 , & V_49 ) ;
}
static void F_200 ( struct V_17 * V_17 , bool V_205 )
{
unsigned long V_10 ;
struct V_203 V_174 ;
struct V_14 * V_14 ;
F_180 ( & V_174 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_182 ( & V_174 , & V_17 -> V_111 ) ;
F_180 ( & V_17 -> V_111 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
while ( ( V_14 = F_178 ( & V_174 ) ) )
V_205 ? F_97 ( V_17 , V_14 ) : F_189 ( V_14 ) ;
}
static void F_201 ( struct V_17 * V_17 )
{
unsigned long V_10 ;
struct V_203 V_174 ;
struct V_14 * V_14 ;
F_180 ( & V_174 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_182 ( & V_174 , & V_17 -> V_112 ) ;
F_180 ( & V_17 -> V_112 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
while ( ( V_14 = F_178 ( & V_174 ) ) )
F_97 ( V_17 , V_14 ) ;
}
static void F_202 ( struct V_17 * V_17 )
{
bool V_202 = false ;
T_3 V_48 ;
T_5 V_52 ;
struct V_29 V_49 ;
struct V_20 * V_135 ;
bool V_206 = ! F_5 ( & V_17 -> V_109 , V_207 ) ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
while ( F_174 ( V_17 ) ) {
if ( F_203 ( V_17 -> V_54 , & V_48 , & V_52 , V_206 ) )
break;
V_202 = true ;
if ( F_26 ( V_17 , & V_49 ) ||
F_39 ( V_17 , V_48 , & V_49 , & V_135 ) ) {
F_46 ( V_17 -> V_54 , V_48 ) ;
break;
}
V_133 ( V_17 , & V_49 , V_48 , V_52 , V_135 ) ;
}
if ( V_202 )
F_27 ( V_17 , & V_49 ) ;
}
static void F_204 ( struct V_17 * V_17 , struct V_208 * V_209 )
{
int V_9 = 0 ;
T_11 V_34 = F_43 ( V_209 -> V_210 -> V_34 ) ;
T_11 V_35 = F_43 ( V_209 -> V_210 -> V_35 ) ;
while ( V_34 != V_35 ) {
V_9 = F_205 ( V_17 -> V_54 , F_206 ( V_34 ) ) ;
if ( ! V_9 ) {
V_9 = F_140 ( V_17 -> V_68 , F_206 ( V_34 ) ) ;
if ( V_9 ) {
F_122 ( V_17 , L_15 , V_9 ) ;
break;
}
} else if ( V_9 == - V_211 ) {
V_9 = 0 ;
} else {
F_115 ( L_22 , F_108 ( V_17 ) ) ;
break;
}
V_34 ++ ;
}
V_17 -> V_110 = true ;
V_209 -> V_131 = V_9 ;
F_68 ( & V_209 -> V_212 , 1 ) ;
F_24 ( & V_209 -> V_213 ) ;
}
static void F_207 ( struct V_17 * V_17 )
{
struct V_163 V_140 ;
struct V_208 * V_209 , * V_165 ;
F_159 ( & V_140 ) ;
F_208 ( & V_17 -> V_214 ) ;
F_160 ( & V_17 -> V_215 , & V_140 ) ;
F_209 ( & V_17 -> V_214 ) ;
F_161 (req, tmp, &list, list)
F_204 ( V_17 , V_209 ) ;
}
static bool F_210 ( struct V_17 * V_17 )
{
return F_71 ( & V_17 -> V_216 ) ;
}
static void F_211 ( struct V_17 * V_17 )
{
if ( F_210 ( V_17 ) ) {
F_21 ( & V_17 -> V_217 ) ;
F_24 ( & V_17 -> V_218 ) ;
}
}
static void F_212 ( struct V_17 * V_17 )
{
F_213 ( V_17 -> V_218 , F_71 ( & V_17 -> V_217 ) ) ;
}
static void F_214 ( struct V_17 * V_17 )
{
F_21 ( & V_17 -> V_216 ) ;
F_212 ( V_17 ) ;
}
static void F_215 ( struct V_17 * V_17 )
{
F_68 ( & V_17 -> V_216 , 0 ) ;
F_68 ( & V_17 -> V_217 , 0 ) ;
}
static void F_216 ( struct V_17 * V_17 )
{
F_213 ( V_17 -> V_28 , ! F_71 ( & V_17 -> V_27 ) ) ;
}
static void F_217 ( struct V_17 * V_17 )
{
F_218 ( & V_17 -> V_219 ) ;
F_219 ( V_17 -> V_18 ) ;
}
static void F_220 ( struct V_17 * V_17 )
{
unsigned long V_10 ;
struct V_163 V_204 ;
struct V_20 * V_23 , * V_165 ;
F_159 ( & V_204 ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
F_160 ( & V_17 -> V_130 , & V_204 ) ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
F_161 (cell, tmp, &cells, user_list)
F_134 ( V_17 , V_23 ) ;
}
static void F_221 ( struct V_17 * V_17 )
{
struct V_14 * V_14 ;
struct V_203 V_174 ;
F_180 ( & V_174 ) ;
F_182 ( & V_174 , & V_17 -> V_128 ) ;
F_180 ( & V_17 -> V_128 ) ;
while ( ( V_14 = F_178 ( & V_174 ) ) ) {
V_14 -> V_114 = V_132 ;
F_104 ( V_14 ) ;
}
}
static int F_222 ( struct V_17 * V_17 )
{
if ( F_210 ( V_17 ) )
return ! F_167 ( & V_17 -> V_142 ) ||
! F_167 ( & V_17 -> V_148 ) ||
! F_167 ( & V_17 -> V_141 ) ;
else
return ! F_197 ( & V_17 -> V_128 ) ||
! F_167 ( & V_17 -> V_130 ) ||
! F_197 ( & V_17 -> V_111 ) ||
! F_197 ( & V_17 -> V_112 ) ||
! F_167 ( & V_17 -> V_142 ) ||
! F_167 ( & V_17 -> V_148 ) ||
! F_167 ( & V_17 -> V_141 ) ||
V_17 -> V_143 ;
}
static void F_223 ( struct V_220 * V_221 )
{
struct V_17 * V_17 = F_186 ( V_221 , struct V_17 , V_19 ) ;
do {
if ( ! F_210 ( V_17 ) ) {
F_202 ( V_17 ) ;
F_201 ( V_17 ) ;
F_196 ( V_17 ) ;
F_198 ( V_17 ) ;
F_207 ( V_17 ) ;
}
F_157 ( V_17 , & V_17 -> V_142 , F_155 ) ;
F_157 ( V_17 , & V_17 -> V_148 , F_156 ) ;
if ( F_194 ( V_17 ) ) {
F_200 ( V_17 , false ) ;
F_157 ( V_17 , & V_17 -> V_141 , F_136 ) ;
} else {
F_200 ( V_17 , true ) ;
F_157 ( V_17 , & V_17 -> V_141 ,
F_142 ) ;
}
F_211 ( V_17 ) ;
} while ( F_222 ( V_17 ) );
}
static void F_224 ( struct V_220 * V_221 )
{
struct V_17 * V_17 = F_186 ( F_225 ( V_221 ) , struct V_17 , V_219 ) ;
F_226 ( V_17 -> V_54 , true ) ;
F_13 ( V_17 ) ;
F_227 ( V_17 -> V_18 , & V_17 -> V_219 , V_198 ) ;
}
static int F_228 ( struct V_222 * V_39 , int V_223 )
{
struct V_224 * V_225 = F_229 ( V_39 -> V_95 ) ;
return F_230 ( & V_225 -> V_226 , V_223 ) ;
}
static int F_231 ( struct V_227 * V_228 , int V_223 )
{
struct V_17 * V_17 = F_186 ( V_228 , struct V_17 , V_229 ) ;
return F_228 ( V_17 -> V_94 , V_223 ) ||
F_228 ( V_17 -> V_99 , V_223 ) ;
}
static void F_232 ( struct V_17 * V_17 )
{
unsigned V_230 ;
F_233 ( V_17 -> V_26 ) ;
if ( V_17 -> V_108 )
F_234 ( V_17 -> V_108 ) ;
if ( V_17 -> V_21 )
F_235 ( V_17 -> V_21 ) ;
if ( V_17 -> V_18 )
F_236 ( V_17 -> V_18 ) ;
if ( V_17 -> V_51 )
F_237 ( V_17 -> V_51 ) ;
if ( V_17 -> V_66 )
F_237 ( V_17 -> V_66 ) ;
if ( V_17 -> V_154 )
F_238 ( V_17 -> V_154 ) ;
if ( V_17 -> V_68 )
F_239 ( V_17 -> V_68 ) ;
if ( V_17 -> V_231 )
F_240 ( V_17 -> V_55 , V_17 -> V_231 ) ;
if ( V_17 -> V_94 )
F_240 ( V_17 -> V_55 , V_17 -> V_94 ) ;
if ( V_17 -> V_99 )
F_240 ( V_17 -> V_55 , V_17 -> V_99 ) ;
if ( V_17 -> V_54 )
F_241 ( V_17 -> V_54 ) ;
for ( V_230 = 0 ; V_230 < V_17 -> V_232 ; V_230 ++ )
F_242 ( V_17 -> V_233 [ V_230 ] ) ;
F_242 ( V_17 -> V_233 ) ;
F_242 ( V_17 ) ;
}
static void F_243 ( struct V_234 * V_55 )
{
struct V_17 * V_17 = V_55 -> V_235 ;
F_232 ( V_17 ) ;
}
static T_1 F_244 ( struct V_222 * V_39 )
{
return F_245 ( V_39 -> V_95 -> V_236 ) >> V_156 ;
}
static void F_246 ( struct V_237 * V_238 )
{
if ( V_238 -> V_231 )
F_240 ( V_238 -> V_55 , V_238 -> V_231 ) ;
if ( V_238 -> V_99 )
F_240 ( V_238 -> V_55 , V_238 -> V_99 ) ;
if ( V_238 -> V_94 )
F_240 ( V_238 -> V_55 , V_238 -> V_94 ) ;
F_242 ( V_238 ) ;
}
static bool F_247 ( struct V_239 * V_240 , char * * error )
{
if ( ! V_240 -> V_241 ) {
* error = L_23 ;
return false ;
}
return true ;
}
static int F_248 ( struct V_237 * V_238 , struct V_239 * V_240 ,
char * * error )
{
int V_9 ;
T_1 V_242 ;
char V_50 [ V_243 ] ;
if ( ! F_247 ( V_240 , error ) )
return - V_200 ;
V_9 = F_249 ( V_238 -> V_55 , F_250 ( V_240 ) , V_244 | V_245 ,
& V_238 -> V_231 ) ;
if ( V_9 ) {
* error = L_24 ;
return V_9 ;
}
V_242 = F_244 ( V_238 -> V_231 ) ;
if ( V_242 > V_246 )
F_251 ( L_25 ,
F_252 ( V_238 -> V_231 -> V_95 , V_50 ) , V_247 ) ;
return 0 ;
}
static int F_253 ( struct V_237 * V_238 , struct V_239 * V_240 ,
char * * error )
{
int V_9 ;
if ( ! F_247 ( V_240 , error ) )
return - V_200 ;
V_9 = F_249 ( V_238 -> V_55 , F_250 ( V_240 ) , V_244 | V_245 ,
& V_238 -> V_99 ) ;
if ( V_9 ) {
* error = L_26 ;
return V_9 ;
}
V_238 -> V_248 = F_244 ( V_238 -> V_99 ) ;
return 0 ;
}
static int F_254 ( struct V_237 * V_238 , struct V_239 * V_240 ,
char * * error )
{
int V_9 ;
if ( ! F_247 ( V_240 , error ) )
return - V_200 ;
V_9 = F_249 ( V_238 -> V_55 , F_250 ( V_240 ) , V_244 | V_245 ,
& V_238 -> V_94 ) ;
if ( V_9 ) {
* error = L_27 ;
return V_9 ;
}
V_238 -> V_249 = F_244 ( V_238 -> V_94 ) ;
if ( V_238 -> V_55 -> V_11 > V_238 -> V_249 ) {
* error = L_28 ;
return - V_200 ;
}
return 0 ;
}
static int F_255 ( struct V_237 * V_238 , struct V_239 * V_240 ,
char * * error )
{
unsigned long V_250 ;
if ( ! F_247 ( V_240 , error ) )
return - V_200 ;
if ( F_256 ( F_250 ( V_240 ) , 10 , & V_250 ) || ! V_250 ||
V_250 < V_251 ||
V_250 > V_252 ||
V_250 & ( V_251 - 1 ) ) {
* error = L_29 ;
return - V_200 ;
}
if ( V_250 > V_238 -> V_248 ) {
* error = L_30 ;
return - V_200 ;
}
V_238 -> V_250 = V_250 ;
return 0 ;
}
static void F_257 ( struct V_78 * V_253 )
{
V_253 -> V_117 = V_123 ;
V_253 -> V_80 = V_82 ;
}
static int F_258 ( struct V_237 * V_238 , struct V_239 * V_240 ,
char * * error )
{
static struct V_254 V_255 [] = {
{ 0 , 1 , L_31 } ,
} ;
int V_9 ;
unsigned V_241 ;
const char * V_256 ;
struct V_78 * V_253 = & V_238 -> V_84 ;
F_257 ( V_253 ) ;
V_9 = F_259 ( V_255 , V_240 , & V_241 , error ) ;
if ( V_9 )
return - V_200 ;
while ( V_241 -- ) {
V_256 = F_250 ( V_240 ) ;
if ( ! strcasecmp ( V_256 , L_32 ) )
V_253 -> V_80 = V_82 ;
else if ( ! strcasecmp ( V_256 , L_33 ) )
V_253 -> V_80 = V_81 ;
else if ( ! strcasecmp ( V_256 , L_34 ) )
V_253 -> V_80 = V_83 ;
else {
* error = L_35 ;
return - V_200 ;
}
}
return 0 ;
}
static int F_260 ( struct V_237 * V_238 , struct V_239 * V_240 ,
char * * error )
{
static struct V_254 V_255 [] = {
{ 0 , 1024 , L_36 } ,
} ;
int V_9 ;
if ( ! F_247 ( V_240 , error ) )
return - V_200 ;
V_238 -> V_257 = F_250 ( V_240 ) ;
V_9 = F_259 ( V_255 , V_240 , & V_238 -> V_258 , error ) ;
if ( V_9 )
return - V_200 ;
V_238 -> V_259 = ( const char * * ) V_240 -> V_260 ;
F_261 ( V_240 , V_238 -> V_258 ) ;
return 0 ;
}
static int F_262 ( struct V_237 * V_238 , int V_241 , char * * V_260 ,
char * * error )
{
int V_9 ;
struct V_239 V_240 ;
V_240 . V_241 = V_241 ;
V_240 . V_260 = V_260 ;
V_9 = F_248 ( V_238 , & V_240 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_253 ( V_238 , & V_240 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_254 ( V_238 , & V_240 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_255 ( V_238 , & V_240 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_258 ( V_238 , & V_240 , error ) ;
if ( V_9 )
return V_9 ;
V_9 = F_260 ( V_238 , & V_240 , error ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_263 ( struct V_17 * V_17 , const char * V_37 , const char * V_261 )
{
unsigned long V_165 ;
if ( ! strcasecmp ( V_37 , L_37 ) ) {
if ( F_256 ( V_261 , 10 , & V_165 ) )
return - V_200 ;
V_17 -> V_169 = V_165 ;
return 0 ;
}
return V_262 ;
}
static int F_264 ( struct V_17 * V_17 , const char * V_37 , const char * V_261 )
{
int V_9 = F_263 ( V_17 , V_37 , V_261 ) ;
if ( V_9 == V_262 )
V_9 = F_265 ( V_17 -> V_54 , V_37 , V_261 ) ;
if ( V_9 )
F_251 ( L_38 , V_37 , V_261 ) ;
return V_9 ;
}
static int F_266 ( struct V_17 * V_17 , int V_241 , const char * * V_260 )
{
int V_9 = 0 ;
if ( V_241 & 1 ) {
F_251 ( L_39 ) ;
return - V_200 ;
}
while ( V_241 ) {
V_9 = F_264 ( V_17 , V_260 [ 0 ] , V_260 [ 1 ] ) ;
if ( V_9 )
break;
V_241 -= 2 ;
V_260 += 2 ;
}
return V_9 ;
}
static int F_267 ( struct V_17 * V_17 , struct V_237 * V_238 ,
char * * error )
{
struct V_263 * V_30 = F_268 ( V_238 -> V_257 ,
V_17 -> V_264 ,
V_17 -> V_249 ,
V_17 -> V_61 ) ;
if ( F_269 ( V_30 ) ) {
* error = L_40 ;
return F_270 ( V_30 ) ;
}
V_17 -> V_54 = V_30 ;
return 0 ;
}
static bool F_271 ( T_1 V_60 ,
T_1 V_265 )
{
( void ) F_83 ( V_265 , V_60 ) ;
return V_265 > V_266 ;
}
static T_1 F_272 ( T_1 V_267 ,
T_1 V_265 )
{
T_1 V_60 = V_267 ;
if ( V_265 )
while ( F_271 ( V_60 , V_265 ) )
V_60 *= 2 ;
return V_60 ;
}
static void F_273 ( struct V_17 * V_17 , T_5 V_268 )
{
T_7 V_269 = F_43 ( V_268 ) ;
if ( V_269 > ( 1 << 20 ) && V_17 -> V_264 != V_268 )
F_143 ( L_41
L_42
L_43 ,
( unsigned long long ) V_269 ) ;
V_17 -> V_264 = V_268 ;
}
static int F_274 ( struct V_237 * V_238 , struct V_17 * * V_270 )
{
int V_9 = 0 ;
char * * error = & V_238 -> V_55 -> error ;
struct V_17 * V_17 ;
struct V_234 * V_55 = V_238 -> V_55 ;
T_7 V_271 ;
struct V_272 * V_68 ;
bool V_273 = V_238 -> V_84 . V_117 == V_123 ;
V_17 = F_275 ( sizeof( * V_17 ) , V_274 ) ;
if ( ! V_17 )
return - V_31 ;
V_17 -> V_55 = V_238 -> V_55 ;
V_55 -> V_235 = V_17 ;
V_55 -> V_275 = 2 ;
V_55 -> V_276 = true ;
V_55 -> V_277 = 1 ;
V_55 -> V_278 = true ;
V_55 -> V_279 = true ;
V_55 -> V_280 = false ;
V_17 -> V_84 = V_238 -> V_84 ;
V_55 -> V_281 = F_76 ( V_17 ) ;
V_17 -> V_229 . V_282 = F_231 ;
F_276 ( V_55 -> V_56 , & V_17 -> V_229 ) ;
V_17 -> V_231 = V_238 -> V_231 ;
V_17 -> V_94 = V_238 -> V_94 ;
V_17 -> V_99 = V_238 -> V_99 ;
V_238 -> V_231 = V_238 -> V_94 = V_238 -> V_99 = NULL ;
V_271 = V_17 -> V_249 = V_238 -> V_249 ;
V_271 = F_53 ( V_271 , V_238 -> V_250 ) ;
V_17 -> V_271 = F_38 ( V_271 ) ;
V_17 -> V_61 = V_238 -> V_250 ;
if ( F_277 ( V_55 , V_17 -> V_61 ) ) {
V_9 = - V_200 ;
goto V_283;
}
if ( V_238 -> V_250 & ( V_238 -> V_250 - 1 ) ) {
T_7 V_264 = V_238 -> V_248 ;
V_17 -> V_57 = - 1 ;
V_264 = F_53 ( V_264 , V_238 -> V_250 ) ;
F_273 ( V_17 , F_206 ( V_264 ) ) ;
} else {
V_17 -> V_57 = F_278 ( V_238 -> V_250 ) ;
F_273 ( V_17 , F_206 ( V_238 -> V_248 >> V_17 -> V_57 ) ) ;
}
V_9 = F_267 ( V_17 , V_238 , error ) ;
if ( V_9 )
goto V_283;
V_17 -> V_284 = V_238 -> V_258 ;
V_17 -> V_169 = V_285 ;
V_9 = F_266 ( V_17 , V_238 -> V_258 , V_238 -> V_259 ) ;
if ( V_9 ) {
* error = L_44 ;
goto V_283;
}
V_68 = F_279 ( V_17 -> V_231 -> V_95 ,
V_238 -> V_250 , V_273 ,
F_280 ( V_17 -> V_54 ) ) ;
if ( F_269 ( V_68 ) ) {
* error = L_45 ;
V_9 = F_270 ( V_68 ) ;
goto V_283;
}
V_17 -> V_68 = V_68 ;
F_113 ( V_17 , V_123 ) ;
if ( F_70 ( V_17 ) != V_123 ) {
* error = L_46 ;
V_9 = - V_200 ;
goto V_283;
}
if ( F_75 ( & V_17 -> V_84 ) ) {
bool V_286 ;
V_9 = F_281 ( V_17 -> V_68 , & V_286 ) ;
if ( V_9 ) {
* error = L_47 ;
goto V_283;
}
if ( ! V_286 ) {
* error = L_48 ;
V_9 = - V_200 ;
goto V_283;
}
}
F_2 ( & V_17 -> V_3 ) ;
F_159 ( & V_17 -> V_130 ) ;
F_180 ( & V_17 -> V_128 ) ;
F_180 ( & V_17 -> V_111 ) ;
F_180 ( & V_17 -> V_112 ) ;
F_159 ( & V_17 -> V_142 ) ;
F_159 ( & V_17 -> V_148 ) ;
F_159 ( & V_17 -> V_141 ) ;
F_68 ( & V_17 -> V_27 , 0 ) ;
F_68 ( & V_17 -> V_126 , 0 ) ;
F_282 ( & V_17 -> V_28 ) ;
F_282 ( & V_17 -> V_218 ) ;
F_68 ( & V_17 -> V_216 , 0 ) ;
F_68 ( & V_17 -> V_217 , 0 ) ;
V_9 = - V_31 ;
F_68 ( & V_17 -> V_53 , 0 ) ;
V_17 -> V_51 = F_283 ( F_43 ( V_17 -> V_264 ) ) ;
if ( ! V_17 -> V_51 ) {
* error = L_49 ;
goto V_283;
}
F_284 ( V_17 -> V_51 , F_43 ( V_17 -> V_264 ) ) ;
V_17 -> V_60 =
F_272 ( V_17 -> V_61 ,
V_17 -> V_249 ) ;
V_17 -> V_63 = F_57 ( F_153 ( V_17 -> V_249 ,
V_17 -> V_60 ) ) ;
V_17 -> V_66 = F_283 ( F_59 ( V_17 -> V_63 ) ) ;
if ( ! V_17 -> V_66 ) {
* error = L_50 ;
goto V_283;
}
F_284 ( V_17 -> V_66 , F_59 ( V_17 -> V_63 ) ) ;
V_17 -> V_154 = F_285 ( & V_287 ) ;
if ( F_269 ( V_17 -> V_154 ) ) {
* error = L_51 ;
V_9 = F_270 ( V_17 -> V_154 ) ;
goto V_283;
}
V_17 -> V_18 = F_286 ( L_52 V_288 , V_289 ) ;
if ( ! V_17 -> V_18 ) {
* error = L_53 ;
goto V_283;
}
F_287 ( & V_17 -> V_19 , F_223 ) ;
F_288 ( & V_17 -> V_219 , F_224 ) ;
V_17 -> V_197 = V_7 ;
V_17 -> V_21 = F_289 () ;
if ( ! V_17 -> V_21 ) {
* error = L_54 ;
goto V_283;
}
V_17 -> V_108 = F_290 () ;
if ( ! V_17 -> V_108 ) {
* error = L_55 ;
goto V_283;
}
V_17 -> V_26 = F_291 ( V_290 ,
V_291 ) ;
if ( ! V_17 -> V_26 ) {
* error = L_56 ;
goto V_283;
}
V_17 -> V_101 = true ;
V_17 -> V_292 = false ;
V_17 -> V_143 = false ;
V_17 -> V_110 = false ;
V_17 -> V_293 = false ;
V_17 -> V_294 = false ;
F_66 ( V_17 ) ;
F_68 ( & V_17 -> V_64 . V_192 , 0 ) ;
F_68 ( & V_17 -> V_64 . V_194 , 0 ) ;
F_68 ( & V_17 -> V_64 . V_157 , 0 ) ;
F_68 ( & V_17 -> V_64 . V_295 , 0 ) ;
F_68 ( & V_17 -> V_64 . V_201 , 0 ) ;
F_68 ( & V_17 -> V_64 . V_65 , 0 ) ;
F_2 ( & V_17 -> V_214 ) ;
F_159 ( & V_17 -> V_215 ) ;
F_1 ( & V_17 -> V_109 ) ;
* V_270 = V_17 ;
return 0 ;
V_283:
F_232 ( V_17 ) ;
return V_9 ;
}
static int F_292 ( struct V_17 * V_17 , int V_241 , const char * * V_260 )
{
unsigned V_230 ;
const char * * V_296 ;
V_296 = F_293 ( V_241 , sizeof( * V_296 ) , V_274 ) ;
if ( ! V_296 )
return - V_31 ;
for ( V_230 = 0 ; V_230 < V_241 ; V_230 ++ ) {
V_296 [ V_230 ] = F_294 ( V_260 [ V_230 ] , V_274 ) ;
if ( ! V_296 [ V_230 ] ) {
while ( V_230 -- )
F_242 ( V_296 [ V_230 ] ) ;
F_242 ( V_296 ) ;
return - V_31 ;
}
}
V_17 -> V_232 = V_241 ;
V_17 -> V_233 = V_296 ;
return 0 ;
}
static int F_295 ( struct V_234 * V_55 , unsigned V_241 , char * * V_260 )
{
int V_9 = - V_200 ;
struct V_237 * V_238 ;
struct V_17 * V_17 = NULL ;
V_238 = F_275 ( sizeof( * V_238 ) , V_274 ) ;
if ( ! V_238 ) {
V_55 -> error = L_57 ;
return - V_31 ;
}
V_238 -> V_55 = V_55 ;
V_9 = F_262 ( V_238 , V_241 , V_260 , & V_55 -> error ) ;
if ( V_9 )
goto V_297;
V_9 = F_274 ( V_238 , & V_17 ) ;
if ( V_9 )
goto V_297;
V_9 = F_292 ( V_17 , V_241 - 3 , ( const char * * ) V_260 + 3 ) ;
if ( V_9 ) {
F_232 ( V_17 ) ;
goto V_297;
}
V_55 -> V_235 = V_17 ;
V_297:
F_246 ( V_238 ) ;
return V_9 ;
}
static int F_296 ( struct V_234 * V_55 , struct V_14 * V_14 )
{
struct V_17 * V_17 = V_55 -> V_235 ;
int V_9 ;
struct V_20 * V_23 = NULL ;
T_3 V_98 = F_89 ( V_17 , V_14 ) ;
T_10 V_100 = F_76 ( V_17 ) ;
bool V_187 = false ;
bool V_186 ;
struct V_183 V_184 ;
struct V_87 * V_89 = F_79 ( V_14 , V_100 ) ;
struct V_180 V_188 ;
V_188 . V_179 . F_158 = F_184 ;
if ( F_297 ( F_34 ( V_98 ) >= F_34 ( V_17 -> V_271 ) ) ) {
F_81 ( V_17 , V_14 ) ;
F_94 ( V_17 , V_14 ) ;
return V_298 ;
}
if ( F_126 ( V_14 ) ) {
F_171 ( V_17 , V_14 ) ;
return V_299 ;
}
V_23 = F_15 ( V_17 ) ;
if ( ! V_23 ) {
F_171 ( V_17 , V_14 ) ;
return V_299 ;
}
V_9 = F_37 ( V_17 , V_98 , V_14 , V_23 ,
( T_4 ) F_17 ,
V_17 , & V_23 ) ;
if ( V_9 ) {
if ( V_9 < 0 )
F_171 ( V_17 , V_14 ) ;
return V_299 ;
}
V_186 = F_65 ( V_17 , V_98 ) || F_149 ( V_17 , V_14 ) ;
V_9 = F_188 ( V_17 -> V_54 , V_98 , false , V_187 , V_186 ,
V_14 , & V_188 . V_179 , & V_184 ) ;
if ( V_9 == - V_189 ) {
F_130 ( V_17 , V_23 , true ) ;
return V_299 ;
} else if ( V_9 ) {
F_120 ( L_58 ,
F_108 ( V_17 ) , V_9 ) ;
F_130 ( V_17 , V_23 , false ) ;
F_189 ( V_14 ) ;
return V_299 ;
}
V_9 = V_298 ;
switch ( V_184 . V_125 ) {
case V_191 :
if ( F_75 ( & V_17 -> V_84 ) ) {
if ( F_87 ( V_14 ) == V_106 ) {
F_130 ( V_17 , V_23 , true ) ;
V_9 = V_299 ;
} else {
F_176 ( V_17 , V_14 ) ;
F_86 ( V_17 , V_14 , V_98 ) ;
F_94 ( V_17 , V_14 ) ;
F_91 ( V_17 , V_14 , V_23 ) ;
F_130 ( V_17 , V_23 , false ) ;
}
} else {
F_175 ( V_17 , V_14 ) ;
if ( F_87 ( V_14 ) == V_106 && F_73 ( & V_17 -> V_84 ) &&
! F_41 ( V_17 , V_184 . V_52 ) ) {
F_106 ( V_17 , V_14 , V_98 , V_184 . V_52 ) ;
F_94 ( V_17 , V_14 ) ;
F_91 ( V_17 , V_14 , V_23 ) ;
F_130 ( V_17 , V_23 , false ) ;
} else
F_183 ( V_17 , V_23 , V_98 , V_184 . V_52 , false ) ;
}
break;
case V_190 :
F_176 ( V_17 , V_14 ) ;
if ( V_89 -> V_91 != 0 ) {
F_104 ( V_14 ) ;
F_130 ( V_17 , V_23 , false ) ;
V_9 = V_299 ;
} else
F_179 ( V_17 , V_23 , V_98 , false ) ;
break;
default:
F_120 ( L_59 ,
F_108 ( V_17 ) , V_196 ,
( unsigned ) V_184 . V_125 ) ;
F_130 ( V_17 , V_23 , false ) ;
F_189 ( V_14 ) ;
V_9 = V_299 ;
}
return V_9 ;
}
static int F_298 ( struct V_234 * V_55 , struct V_14 * V_14 , int error )
{
struct V_17 * V_17 = V_55 -> V_235 ;
unsigned long V_10 ;
T_10 V_100 = F_76 ( V_17 ) ;
struct V_87 * V_89 = F_77 ( V_14 , V_100 ) ;
if ( V_89 -> V_90 ) {
F_226 ( V_17 -> V_54 , false ) ;
F_6 ( & V_17 -> V_3 , V_10 ) ;
V_17 -> V_101 = true ;
F_7 ( & V_17 -> V_3 , V_10 ) ;
}
F_165 ( V_17 , V_89 ) ;
F_96 ( V_17 , V_14 ) ;
return 0 ;
}
static int F_299 ( struct V_17 * V_17 )
{
unsigned V_230 , V_9 ;
if ( F_70 ( V_17 ) >= V_77 )
return - V_200 ;
for ( V_230 = 0 ; V_230 < F_43 ( V_17 -> V_264 ) ; V_230 ++ ) {
V_9 = F_300 ( V_17 -> V_68 , F_206 ( V_230 ) ,
F_41 ( V_17 , F_206 ( V_230 ) ) ) ;
if ( V_9 ) {
F_122 ( V_17 , L_60 , V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
static int F_301 ( struct V_17 * V_17 )
{
unsigned V_230 , V_9 ;
if ( F_70 ( V_17 ) >= V_77 )
return - V_200 ;
V_9 = F_302 ( V_17 -> V_68 , V_17 -> V_60 ,
V_17 -> V_63 ) ;
if ( V_9 ) {
F_115 ( L_61 , F_108 ( V_17 ) ) ;
F_122 ( V_17 , L_62 , V_9 ) ;
return V_9 ;
}
for ( V_230 = 0 ; V_230 < F_59 ( V_17 -> V_63 ) ; V_230 ++ ) {
V_9 = F_303 ( V_17 -> V_68 , F_57 ( V_230 ) ,
F_64 ( V_17 , F_57 ( V_230 ) ) ) ;
if ( V_9 ) {
F_122 ( V_17 , L_63 , V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
static int F_304 ( struct V_17 * V_17 )
{
int V_9 ;
if ( F_70 ( V_17 ) >= V_77 )
return - V_200 ;
V_9 = F_305 ( V_17 -> V_68 , V_17 -> V_54 ) ;
if ( V_9 ) {
F_122 ( V_17 , L_64 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static bool F_306 ( struct V_17 * V_17 )
{
int V_300 , V_301 , V_302 , V_303 ;
V_300 = F_299 ( V_17 ) ;
if ( V_300 )
F_115 ( L_65 , F_108 ( V_17 ) ) ;
V_301 = F_301 ( V_17 ) ;
if ( V_301 )
F_115 ( L_66 , F_108 ( V_17 ) ) ;
F_69 ( V_17 ) ;
V_302 = F_304 ( V_17 ) ;
if ( V_302 )
F_115 ( L_67 , F_108 ( V_17 ) ) ;
V_303 = F_192 ( V_17 , ! V_300 && ! V_301 && ! V_302 ) ;
if ( V_303 )
F_115 ( L_68 , F_108 ( V_17 ) ) ;
return ! V_300 && ! V_301 && ! V_302 && ! V_303 ;
}
static void F_307 ( struct V_234 * V_55 )
{
struct V_17 * V_17 = V_55 -> V_235 ;
F_214 ( V_17 ) ;
F_216 ( V_17 ) ;
F_217 ( V_17 ) ;
F_221 ( V_17 ) ;
F_220 ( V_17 ) ;
F_215 ( V_17 ) ;
if ( F_70 ( V_17 ) == V_123 )
( void ) F_306 ( V_17 ) ;
}
static int F_308 ( void * V_147 , T_3 V_48 , T_5 V_52 ,
bool V_304 , T_8 V_305 , bool V_306 )
{
int V_9 ;
struct V_17 * V_17 = V_147 ;
V_9 = F_309 ( V_17 -> V_54 , V_48 , V_52 , V_305 , V_306 ) ;
if ( V_9 )
return V_9 ;
if ( V_304 )
F_44 ( V_17 , V_48 , V_52 ) ;
else
F_47 ( V_17 , V_48 , V_52 ) ;
return 0 ;
}
static void F_310 ( struct V_17 * V_17 ,
struct V_307 * V_308 )
{
V_308 -> V_17 = V_17 ;
V_308 -> V_309 = V_308 -> V_310 = 0 ;
}
static void F_311 ( struct V_307 * V_308 )
{
T_1 V_50 , V_158 ;
if ( V_308 -> V_309 == V_308 -> V_310 )
return;
V_50 = V_308 -> V_309 * V_308 -> V_250 ;
V_158 = V_308 -> V_310 * V_308 -> V_250 ;
V_50 = F_153 ( V_50 , V_308 -> V_17 -> V_60 ) ;
F_83 ( V_158 , V_308 -> V_17 -> V_60 ) ;
if ( V_158 > F_59 ( V_308 -> V_17 -> V_63 ) )
V_158 = F_59 ( V_308 -> V_17 -> V_63 ) ;
for (; V_50 < V_158 ; V_50 ++ )
F_60 ( V_308 -> V_17 , F_57 ( V_50 ) ) ;
}
static int F_312 ( void * V_147 , T_1 V_60 ,
T_9 V_62 , bool V_162 )
{
struct V_307 * V_308 = V_147 ;
V_308 -> V_250 = V_60 ;
if ( V_162 ) {
if ( F_59 ( V_62 ) == V_308 -> V_310 )
V_308 -> V_310 = V_308 -> V_310 + 1ULL ;
else {
F_311 ( V_308 ) ;
V_308 -> V_309 = F_59 ( V_62 ) ;
V_308 -> V_310 = V_308 -> V_309 + 1ULL ;
}
} else {
F_311 ( V_308 ) ;
V_308 -> V_309 = V_308 -> V_310 = 0 ;
}
return 0 ;
}
static T_5 F_313 ( struct V_17 * V_17 )
{
T_1 V_268 = F_244 ( V_17 -> V_99 ) ;
( void ) F_83 ( V_268 , V_17 -> V_61 ) ;
return F_206 ( V_268 ) ;
}
static bool F_314 ( struct V_17 * V_17 , T_5 V_311 )
{
if ( F_43 ( V_311 ) > F_43 ( V_17 -> V_264 ) )
return true ;
while ( F_43 ( V_311 ) < F_43 ( V_17 -> V_264 ) ) {
V_311 = F_206 ( F_43 ( V_311 ) + 1 ) ;
if ( F_41 ( V_17 , V_311 ) ) {
F_115 ( L_69 ,
F_108 ( V_17 ) ,
( unsigned long long ) F_43 ( V_311 ) ) ;
return false ;
}
}
return true ;
}
static int F_315 ( struct V_17 * V_17 , T_5 V_311 )
{
int V_9 ;
V_9 = F_316 ( V_17 -> V_68 , V_311 ) ;
if ( V_9 ) {
F_115 ( L_70 , F_108 ( V_17 ) ) ;
F_122 ( V_17 , L_71 , V_9 ) ;
return V_9 ;
}
F_273 ( V_17 , V_311 ) ;
return 0 ;
}
static int F_317 ( struct V_234 * V_55 )
{
int V_9 = 0 ;
struct V_17 * V_17 = V_55 -> V_235 ;
T_5 V_312 = F_313 ( V_17 ) ;
if ( ! V_17 -> V_292 ) {
V_9 = F_315 ( V_17 , V_312 ) ;
if ( V_9 )
return V_9 ;
V_17 -> V_292 = true ;
} else if ( V_312 != V_17 -> V_264 ) {
if ( ! F_314 ( V_17 , V_312 ) )
return - V_200 ;
V_9 = F_315 ( V_17 , V_312 ) ;
if ( V_9 )
return V_9 ;
}
if ( ! V_17 -> V_293 ) {
V_9 = F_318 ( V_17 -> V_68 , V_17 -> V_54 ,
F_308 , V_17 ) ;
if ( V_9 ) {
F_115 ( L_72 , F_108 ( V_17 ) ) ;
F_122 ( V_17 , L_73 , V_9 ) ;
return V_9 ;
}
V_17 -> V_293 = true ;
}
if ( ! V_17 -> V_294 ) {
struct V_307 V_308 ;
F_284 ( V_17 -> V_66 , F_59 ( V_17 -> V_63 ) ) ;
F_310 ( V_17 , & V_308 ) ;
V_9 = F_319 ( V_17 -> V_68 , F_312 , & V_308 ) ;
if ( V_9 ) {
F_115 ( L_74 , F_108 ( V_17 ) ) ;
F_122 ( V_17 , L_75 , V_9 ) ;
return V_9 ;
}
F_311 ( & V_308 ) ;
V_17 -> V_294 = true ;
}
return V_9 ;
}
static void F_320 ( struct V_234 * V_55 )
{
struct V_17 * V_17 = V_55 -> V_235 ;
V_17 -> V_101 = true ;
F_224 ( & V_17 -> V_219 . V_166 ) ;
}
static void F_321 ( struct V_234 * V_55 , T_12 type ,
unsigned V_313 , char * V_270 , unsigned V_314 )
{
int V_9 = 0 ;
unsigned V_230 ;
T_13 V_315 = 0 ;
T_7 V_316 = 0 ;
T_7 V_317 = 0 ;
char V_318 [ V_243 ] ;
struct V_17 * V_17 = V_55 -> V_235 ;
T_5 V_319 ;
bool V_120 ;
switch ( type ) {
case V_320 :
if ( F_70 ( V_17 ) == V_122 ) {
F_322 ( L_76 ) ;
break;
}
if ( ! ( V_313 & V_321 ) && ! F_323 ( V_55 ) )
( void ) F_192 ( V_17 , false ) ;
V_9 = F_324 ( V_17 -> V_68 , & V_316 ) ;
if ( V_9 ) {
F_115 ( L_77 ,
F_108 ( V_17 ) , V_9 ) ;
goto V_131;
}
V_9 = F_325 ( V_17 -> V_68 , & V_317 ) ;
if ( V_9 ) {
F_115 ( L_78 ,
F_108 ( V_17 ) , V_9 ) ;
goto V_131;
}
V_319 = F_326 ( V_17 -> V_54 ) ;
F_322 ( L_79 ,
( unsigned ) V_322 ,
( unsigned long long ) ( V_317 - V_316 ) ,
( unsigned long long ) V_317 ,
V_17 -> V_61 ,
( unsigned long long ) F_43 ( V_319 ) ,
( unsigned long long ) F_43 ( V_17 -> V_264 ) ,
( unsigned ) F_71 ( & V_17 -> V_64 . V_69 ) ,
( unsigned ) F_71 ( & V_17 -> V_64 . V_71 ) ,
( unsigned ) F_71 ( & V_17 -> V_64 . V_73 ) ,
( unsigned ) F_71 ( & V_17 -> V_64 . V_75 ) ,
( unsigned ) F_71 ( & V_17 -> V_64 . V_192 ) ,
( unsigned ) F_71 ( & V_17 -> V_64 . V_194 ) ,
( unsigned long ) F_71 ( & V_17 -> V_53 ) ) ;
if ( F_73 ( & V_17 -> V_84 ) )
F_322 ( L_80 ) ;
else if ( F_75 ( & V_17 -> V_84 ) )
F_322 ( L_81 ) ;
else if ( F_74 ( & V_17 -> V_84 ) )
F_322 ( L_82 ) ;
else {
F_115 ( L_83 ,
F_108 ( V_17 ) , ( int ) V_17 -> V_84 . V_80 ) ;
goto V_131;
}
F_322 ( L_84 , ( unsigned long long ) V_17 -> V_169 ) ;
F_322 ( L_85 , F_327 ( V_17 -> V_54 ) ) ;
if ( V_315 < V_314 ) {
V_9 = F_328 ( V_17 -> V_54 , V_270 , V_314 , & V_315 ) ;
if ( V_9 )
F_115 ( L_86 ,
F_108 ( V_17 ) , V_9 ) ;
}
if ( F_70 ( V_17 ) == V_77 )
F_322 ( L_87 ) ;
else
F_322 ( L_88 ) ;
V_9 = F_114 ( V_17 -> V_68 , & V_120 ) ;
if ( V_9 || V_120 )
F_322 ( L_89 ) ;
else
F_322 ( L_90 ) ;
break;
case V_323 :
F_329 ( V_318 , V_17 -> V_231 -> V_95 -> V_324 ) ;
F_322 ( L_85 , V_318 ) ;
F_329 ( V_318 , V_17 -> V_99 -> V_95 -> V_324 ) ;
F_322 ( L_85 , V_318 ) ;
F_329 ( V_318 , V_17 -> V_94 -> V_95 -> V_324 ) ;
F_322 ( L_91 , V_318 ) ;
for ( V_230 = 0 ; V_230 < V_17 -> V_232 - 1 ; V_230 ++ )
F_322 ( L_92 , V_17 -> V_233 [ V_230 ] ) ;
if ( V_17 -> V_232 )
F_322 ( L_92 , V_17 -> V_233 [ V_17 -> V_232 - 1 ] ) ;
}
return;
V_131:
F_322 ( L_93 ) ;
}
static int F_330 ( struct V_17 * V_17 , const char * V_325 ,
struct V_326 * V_270 )
{
char V_327 ;
T_11 V_50 , V_158 ;
int V_9 ;
V_9 = sscanf ( V_325 , L_94 , & V_50 , & V_158 , & V_327 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 2 ) {
V_270 -> V_34 = F_206 ( V_50 ) ;
V_270 -> V_35 = F_206 ( V_158 ) ;
return 0 ;
}
V_9 = sscanf ( V_325 , L_95 , & V_50 , & V_327 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == 1 ) {
V_270 -> V_34 = F_206 ( V_50 ) ;
V_270 -> V_35 = F_206 ( F_43 ( V_270 -> V_34 ) + 1u ) ;
return 0 ;
}
F_115 ( L_96 , F_108 ( V_17 ) , V_325 ) ;
return - V_200 ;
}
static int F_331 ( struct V_17 * V_17 , struct V_326 * V_328 )
{
T_11 V_50 = F_43 ( V_328 -> V_34 ) ;
T_11 V_158 = F_43 ( V_328 -> V_35 ) ;
T_11 V_58 = F_43 ( V_17 -> V_264 ) ;
if ( V_50 >= V_58 ) {
F_115 ( L_97 ,
F_108 ( V_17 ) , V_50 , V_58 ) ;
return - V_200 ;
}
if ( V_158 > V_58 ) {
F_115 ( L_98 ,
F_108 ( V_17 ) , V_158 , V_58 ) ;
return - V_200 ;
}
if ( V_50 >= V_158 ) {
F_115 ( L_99 ,
F_108 ( V_17 ) , V_50 , V_158 ) ;
return - V_200 ;
}
return 0 ;
}
static int F_332 ( struct V_17 * V_17 , struct V_326 * V_328 )
{
struct V_208 V_209 ;
F_159 ( & V_209 . V_140 ) ;
V_209 . V_210 = V_328 ;
F_68 ( & V_209 . V_212 , 0 ) ;
V_209 . V_131 = 0 ;
F_282 ( & V_209 . V_213 ) ;
F_208 ( & V_17 -> V_214 ) ;
F_333 ( & V_209 . V_140 , & V_17 -> V_215 ) ;
F_209 ( & V_17 -> V_214 ) ;
F_13 ( V_17 ) ;
F_213 ( V_209 . V_213 , F_71 ( & V_209 . V_212 ) ) ;
return V_209 . V_131 ;
}
static int F_334 ( struct V_17 * V_17 , unsigned V_152 ,
const char * * V_329 )
{
int V_9 = 0 ;
unsigned V_230 ;
struct V_326 V_328 ;
if ( ! F_75 ( & V_17 -> V_84 ) ) {
F_115 ( L_100 ,
F_108 ( V_17 ) ) ;
return - V_330 ;
}
for ( V_230 = 0 ; V_230 < V_152 ; V_230 ++ ) {
V_9 = F_330 ( V_17 , V_329 [ V_230 ] , & V_328 ) ;
if ( V_9 )
break;
V_9 = F_331 ( V_17 , & V_328 ) ;
if ( V_9 )
break;
V_9 = F_332 ( V_17 , & V_328 ) ;
if ( V_9 )
break;
}
return V_9 ;
}
static int F_335 ( struct V_234 * V_55 , unsigned V_241 , char * * V_260 )
{
struct V_17 * V_17 = V_55 -> V_235 ;
if ( ! V_241 )
return - V_200 ;
if ( F_70 ( V_17 ) >= V_77 ) {
F_115 ( L_101 ,
F_108 ( V_17 ) ) ;
return - V_331 ;
}
if ( ! strcasecmp ( V_260 [ 0 ] , L_102 ) )
return F_334 ( V_17 , V_241 - 1 , ( const char * * ) V_260 + 1 ) ;
if ( V_241 != 2 )
return - V_200 ;
return F_264 ( V_17 , V_260 [ 0 ] , V_260 [ 1 ] ) ;
}
static int F_336 ( struct V_234 * V_55 ,
T_14 F_158 , void * V_332 )
{
int V_9 = 0 ;
struct V_17 * V_17 = V_55 -> V_235 ;
V_9 = F_158 ( V_55 , V_17 -> V_99 , 0 , F_244 ( V_17 -> V_99 ) , V_332 ) ;
if ( ! V_9 )
V_9 = F_158 ( V_55 , V_17 -> V_94 , 0 , V_55 -> V_11 , V_332 ) ;
return V_9 ;
}
static void F_337 ( struct V_17 * V_17 , struct V_333 * V_334 )
{
V_334 -> V_335 = F_338 ( T_1 , V_17 -> V_60 * 1024 ,
V_17 -> V_249 ) ;
V_334 -> V_336 = V_17 -> V_60 << V_156 ;
}
static void F_339 ( struct V_234 * V_55 , struct V_333 * V_334 )
{
struct V_17 * V_17 = V_55 -> V_235 ;
T_11 V_337 = V_334 -> V_338 >> V_156 ;
if ( V_337 < V_17 -> V_61 ||
F_54 ( V_337 , V_17 -> V_61 ) ) {
F_340 ( V_334 , V_17 -> V_61 << V_156 ) ;
F_341 ( V_334 , V_17 -> V_61 << V_156 ) ;
}
F_337 ( V_17 , V_334 ) ;
}
static int T_15 F_342 ( void )
{
int V_9 ;
V_9 = F_343 ( & V_339 ) ;
if ( V_9 ) {
F_115 ( L_103 , V_9 ) ;
return V_9 ;
}
V_291 = F_344 ( V_24 , 0 ) ;
if ( ! V_291 ) {
F_345 ( & V_339 ) ;
return - V_31 ;
}
return 0 ;
}
static void T_16 F_346 ( void )
{
F_345 ( & V_339 ) ;
F_347 ( V_291 ) ;
}
