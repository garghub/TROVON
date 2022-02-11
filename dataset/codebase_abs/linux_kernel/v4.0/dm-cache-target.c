static T_1 F_1 ( unsigned V_1 )
{
return sizeof( unsigned long ) * F_2 ( V_1 , V_2 ) ;
}
static unsigned long * F_3 ( unsigned V_1 )
{
T_1 V_3 = F_1 ( V_1 ) ;
return F_4 ( V_3 ) ;
}
static void F_5 ( void * V_4 , unsigned V_1 )
{
T_1 V_3 = F_1 ( V_1 ) ;
memset ( V_4 , 0 , V_3 ) ;
}
static void F_6 ( unsigned long * V_5 )
{
F_7 ( V_5 ) ;
}
static void F_8 ( struct V_6 * V_7 , struct V_8 * V_8 ,
T_2 * V_9 , void * V_10 )
{
V_7 -> V_9 = V_8 -> V_9 ;
V_7 -> V_10 = V_8 -> V_10 ;
V_8 -> V_9 = V_9 ;
V_8 -> V_10 = V_10 ;
}
static void F_9 ( struct V_6 * V_7 , struct V_8 * V_8 )
{
V_8 -> V_9 = V_7 -> V_9 ;
V_8 -> V_10 = V_7 -> V_10 ;
F_10 ( & V_8 -> V_11 ) ;
}
static void F_11 ( struct V_12 * V_12 )
{
F_12 ( V_12 -> V_13 , & V_12 -> V_14 ) ;
}
static struct V_15 * F_13 ( struct V_12 * V_12 )
{
return F_14 ( V_12 -> V_16 , V_17 ) ;
}
static void F_15 ( struct V_12 * V_12 , struct V_15 * V_18 )
{
F_16 ( V_12 -> V_16 , V_18 ) ;
}
static struct V_19 * F_17 ( struct V_12 * V_12 )
{
struct V_19 * V_20 ;
V_20 = F_18 ( V_12 -> V_21 , V_17 ) ;
if ( V_20 ) {
V_20 -> V_12 = V_12 ;
F_10 ( & V_20 -> V_12 -> V_22 ) ;
}
return V_20 ;
}
static void F_19 ( struct V_19 * V_20 )
{
if ( F_20 ( & V_20 -> V_12 -> V_22 ) )
F_21 ( & V_20 -> V_12 -> V_23 ) ;
F_22 ( V_20 , V_20 -> V_12 -> V_21 ) ;
}
static int F_23 ( struct V_12 * V_12 , struct V_24 * V_25 )
{
if ( ! V_25 -> V_20 ) {
V_25 -> V_20 = F_17 ( V_12 ) ;
if ( ! V_25 -> V_20 )
return - V_26 ;
}
if ( ! V_25 -> V_27 ) {
V_25 -> V_27 = F_13 ( V_12 ) ;
if ( ! V_25 -> V_27 )
return - V_26 ;
}
if ( ! V_25 -> V_28 ) {
V_25 -> V_28 = F_13 ( V_12 ) ;
if ( ! V_25 -> V_28 )
return - V_26 ;
}
return 0 ;
}
static void F_24 ( struct V_12 * V_12 , struct V_24 * V_25 )
{
if ( V_25 -> V_28 )
F_15 ( V_12 , V_25 -> V_28 ) ;
if ( V_25 -> V_27 )
F_15 ( V_12 , V_25 -> V_27 ) ;
if ( V_25 -> V_20 )
F_19 ( V_25 -> V_20 ) ;
}
static struct V_19 * F_25 ( struct V_24 * V_25 )
{
struct V_19 * V_20 = V_25 -> V_20 ;
F_26 ( ! V_20 ) ;
V_25 -> V_20 = NULL ;
return V_20 ;
}
static struct V_15 * F_27 ( struct V_24 * V_25 )
{
struct V_15 * V_29 = NULL ;
if ( V_25 -> V_27 ) {
V_29 = V_25 -> V_27 ;
V_25 -> V_27 = NULL ;
} else if ( V_25 -> V_28 ) {
V_29 = V_25 -> V_28 ;
V_25 -> V_28 = NULL ;
} else
F_28 () ;
return V_29 ;
}
static void F_29 ( struct V_24 * V_25 , struct V_15 * V_18 )
{
if ( ! V_25 -> V_28 )
V_25 -> V_28 = V_18 ;
else if ( ! V_25 -> V_27 )
V_25 -> V_27 = V_18 ;
else
F_28 () ;
}
static void F_30 ( T_3 V_30 , T_3 V_31 , struct V_32 * V_33 )
{
V_33 -> V_34 = 0 ;
V_33 -> V_35 = 0 ;
V_33 -> V_36 = F_31 ( V_30 ) ;
V_33 -> V_37 = F_31 ( V_31 ) ;
}
static int F_32 ( struct V_12 * V_12 , T_3 V_38 , T_3 V_39 ,
struct V_8 * V_8 , struct V_15 * V_40 ,
T_4 V_41 , void * V_42 ,
struct V_15 * * V_43 )
{
int V_29 ;
struct V_32 V_33 ;
F_30 ( V_38 , V_39 , & V_33 ) ;
V_29 = F_33 ( V_12 -> V_16 , & V_33 , V_8 , V_40 , V_43 ) ;
if ( V_29 )
V_41 ( V_42 , V_40 ) ;
return V_29 ;
}
static int F_34 ( struct V_12 * V_12 , T_3 V_44 ,
struct V_8 * V_8 , struct V_15 * V_40 ,
T_4 V_41 , void * V_42 ,
struct V_15 * * V_43 )
{
T_3 V_31 = F_35 ( F_31 ( V_44 ) + 1ULL ) ;
return F_32 ( V_12 , V_44 , V_31 , V_8 ,
V_40 , V_41 , V_42 , V_43 ) ;
}
static int F_36 ( struct V_12 * V_12 ,
T_3 V_44 ,
struct V_24 * V_45 ,
struct V_15 * * V_43 )
{
int V_29 ;
struct V_32 V_33 ;
struct V_15 * V_40 ;
V_40 = F_27 ( V_45 ) ;
F_30 ( V_44 , F_35 ( F_31 ( V_44 ) + 1ULL ) , & V_33 ) ;
V_29 = F_37 ( V_12 -> V_16 , & V_33 , V_40 , V_43 ) ;
if ( V_29 )
F_29 ( V_45 , V_40 ) ;
return V_29 ;
}
static bool F_38 ( struct V_12 * V_12 , T_5 V_46 )
{
return F_39 ( F_40 ( V_46 ) , V_12 -> V_47 ) ;
}
static void F_41 ( struct V_12 * V_12 , T_3 V_44 , T_5 V_48 )
{
if ( ! F_42 ( F_40 ( V_48 ) , V_12 -> V_47 ) ) {
F_10 ( & V_12 -> V_49 ) ;
F_43 ( V_12 -> V_50 , V_44 ) ;
}
}
static void F_44 ( struct V_12 * V_12 , T_3 V_44 , T_5 V_48 )
{
if ( F_45 ( F_40 ( V_48 ) , V_12 -> V_47 ) ) {
F_46 ( V_12 -> V_50 , V_44 ) ;
if ( F_47 ( & V_12 -> V_49 ) == 0 )
F_48 ( V_12 -> V_51 -> V_52 ) ;
}
}
static bool F_49 ( struct V_12 * V_12 )
{
return V_12 -> V_53 >= 0 ;
}
T_6
#endif
static T_7 F_50 ( T_7 V_46 , T_8 V_54 )
{
F_51 ( V_46 , V_54 ) ;
return V_46 ;
}
static T_7 F_52 ( struct V_12 * V_12 )
{
T_7 V_55 = V_12 -> V_56 ;
if ( F_49 ( V_12 ) )
V_55 >>= V_12 -> V_53 ;
else
V_55 = F_50 ( V_55 , V_12 -> V_57 ) ;
return V_55 ;
}
static T_9 F_53 ( struct V_12 * V_12 , T_3 V_44 )
{
return F_54 ( F_50 ( F_31 ( V_44 ) ,
F_52 ( V_12 ) ) ) ;
}
static T_3 F_55 ( struct V_12 * V_12 , T_9 V_58 )
{
return F_35 ( F_56 ( V_58 ) * F_52 ( V_12 ) ) ;
}
static void F_57 ( struct V_12 * V_12 , T_9 V_46 )
{
unsigned long V_59 ;
F_26 ( F_56 ( V_46 ) >= F_56 ( V_12 -> V_60 ) ) ;
F_10 ( & V_12 -> V_61 . V_62 ) ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_59 ( F_56 ( V_46 ) , V_12 -> V_64 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
}
static void F_61 ( struct V_12 * V_12 , T_9 V_46 )
{
unsigned long V_59 ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_62 ( F_56 ( V_46 ) , V_12 -> V_64 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
}
static bool F_63 ( struct V_12 * V_12 , T_9 V_46 )
{
int V_29 ;
unsigned long V_59 ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
V_29 = F_39 ( F_56 ( V_46 ) , V_12 -> V_64 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
return V_29 ;
}
static bool F_64 ( struct V_12 * V_12 , T_3 V_46 )
{
int V_29 ;
unsigned long V_59 ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
V_29 = F_39 ( F_56 ( F_53 ( V_12 , V_46 ) ) ,
V_12 -> V_64 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
return V_29 ;
}
static void F_65 ( struct V_12 * V_12 )
{
struct V_65 V_61 ;
F_66 ( V_12 -> V_66 , & V_61 ) ;
F_67 ( & V_12 -> V_61 . V_67 , V_61 . V_68 ) ;
F_67 ( & V_12 -> V_61 . V_69 , V_61 . V_70 ) ;
F_67 ( & V_12 -> V_61 . V_71 , V_61 . V_72 ) ;
F_67 ( & V_12 -> V_61 . V_73 , V_61 . V_74 ) ;
}
static void F_68 ( struct V_12 * V_12 )
{
struct V_65 V_61 ;
V_61 . V_68 = F_69 ( & V_12 -> V_61 . V_67 ) ;
V_61 . V_70 = F_69 ( & V_12 -> V_61 . V_69 ) ;
V_61 . V_72 = F_69 ( & V_12 -> V_61 . V_71 ) ;
V_61 . V_74 = F_69 ( & V_12 -> V_61 . V_73 ) ;
F_70 ( V_12 -> V_66 , & V_61 ) ;
}
static bool F_71 ( struct V_75 * V_76 )
{
return V_76 -> V_77 == V_78 ;
}
static bool F_72 ( struct V_75 * V_76 )
{
return V_76 -> V_77 == V_79 ;
}
static bool F_73 ( struct V_75 * V_76 )
{
return V_76 -> V_77 == V_80 ;
}
static T_1 F_74 ( struct V_12 * V_12 )
{
return F_71 ( & V_12 -> V_81 ) ? V_82 : V_83 ;
}
static struct V_84 * F_75 ( struct V_8 * V_8 , T_1 V_85 )
{
struct V_84 * V_86 = F_76 ( V_8 , V_85 ) ;
F_26 ( ! V_86 ) ;
return V_86 ;
}
static struct V_84 * F_77 ( struct V_8 * V_8 , T_1 V_85 )
{
struct V_84 * V_86 = F_75 ( V_8 , V_85 ) ;
V_86 -> V_87 = false ;
V_86 -> V_88 = F_78 ( V_8 ) ;
V_86 -> V_89 = NULL ;
return V_86 ;
}
static void F_79 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
V_8 -> V_90 = V_12 -> V_91 -> V_92 ;
}
static void F_80 ( struct V_12 * V_12 , struct V_8 * V_8 ,
T_5 V_48 )
{
T_10 V_93 = V_8 -> V_94 . V_93 ;
T_10 V_95 = F_40 ( V_48 ) ;
V_8 -> V_90 = V_12 -> V_96 -> V_92 ;
if ( ! F_49 ( V_12 ) )
V_8 -> V_94 . V_93 =
( V_95 * V_12 -> V_57 ) +
F_81 ( V_93 , V_12 -> V_57 ) ;
else
V_8 -> V_94 . V_93 =
( V_95 << V_12 -> V_53 ) |
( V_93 & ( V_12 -> V_57 - 1 ) ) ;
}
static void F_82 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
unsigned long V_59 ;
T_1 V_97 = F_74 ( V_12 ) ;
struct V_84 * V_86 = F_75 ( V_8 , V_97 ) ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
if ( V_12 -> V_98 &&
! ( V_8 -> V_99 & ( V_100 | V_101 | V_102 ) ) ) {
V_86 -> V_87 = true ;
V_12 -> V_98 = false ;
}
F_60 ( & V_12 -> V_63 , V_59 ) ;
}
static void F_83 ( struct V_12 * V_12 , struct V_8 * V_8 ,
T_3 V_44 )
{
F_82 ( V_12 , V_8 ) ;
F_79 ( V_12 , V_8 ) ;
if ( F_84 ( V_8 ) == V_103 )
F_61 ( V_12 , F_53 ( V_12 , V_44 ) ) ;
}
static void F_85 ( struct V_12 * V_12 , struct V_8 * V_8 ,
T_3 V_44 , T_5 V_48 )
{
F_82 ( V_12 , V_8 ) ;
F_80 ( V_12 , V_8 , V_48 ) ;
if ( F_84 ( V_8 ) == V_103 ) {
F_41 ( V_12 , V_44 , V_48 ) ;
F_61 ( V_12 , F_53 ( V_12 , V_44 ) ) ;
}
}
static T_3 F_86 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
T_10 V_104 = V_8 -> V_94 . V_93 ;
if ( ! F_49 ( V_12 ) )
( void ) F_81 ( V_104 , V_12 -> V_57 ) ;
else
V_104 >>= V_12 -> V_53 ;
return F_35 ( V_104 ) ;
}
static int F_87 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
return V_8 -> V_99 & ( V_101 | V_100 ) ;
}
static void F_88 ( struct V_12 * V_12 , struct V_8 * V_8 ,
struct V_15 * V_18 )
{
T_1 V_97 = F_74 ( V_12 ) ;
struct V_84 * V_86 = F_75 ( V_8 , V_97 ) ;
F_26 ( ! V_18 ) ;
F_26 ( V_86 -> V_89 ) ;
V_86 -> V_89 = F_89 ( V_12 -> V_105 ) ;
}
static void F_90 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
unsigned long V_59 ;
if ( ! F_87 ( V_12 , V_8 ) ) {
F_91 ( V_8 ) ;
return;
}
F_58 ( & V_12 -> V_63 , V_59 ) ;
V_12 -> V_106 = true ;
F_92 ( & V_12 -> V_107 , V_8 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
}
static void F_93 ( struct V_12 * V_12 , struct V_8 * V_8 , struct V_15 * V_18 )
{
F_88 ( V_12 , V_8 , V_18 ) ;
F_90 ( V_12 , V_8 ) ;
}
static void F_94 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
unsigned long V_59 ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_92 ( & V_12 -> V_108 , V_8 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
F_11 ( V_12 ) ;
}
static void F_95 ( struct V_8 * V_8 , int V_109 )
{
struct V_84 * V_86 = F_75 ( V_8 , V_82 ) ;
F_9 ( & V_86 -> V_110 , V_8 ) ;
if ( V_109 ) {
F_96 ( V_8 , V_109 ) ;
return;
}
F_97 ( & V_86 -> V_111 , V_8 ) ;
F_80 ( V_86 -> V_12 , V_8 , V_86 -> V_48 ) ;
F_94 ( V_86 -> V_12 , V_8 ) ;
}
static void F_98 ( struct V_12 * V_12 , struct V_8 * V_8 ,
T_3 V_44 , T_5 V_48 )
{
struct V_84 * V_86 = F_75 ( V_8 , V_82 ) ;
V_86 -> V_12 = V_12 ;
V_86 -> V_48 = V_48 ;
F_8 ( & V_86 -> V_110 , V_8 , F_95 , NULL ) ;
F_99 ( & V_86 -> V_111 , V_8 ) ;
F_83 ( V_86 -> V_12 , V_8 , V_44 ) ;
}
static void F_100 ( struct V_12 * V_12 )
{
F_10 ( & V_12 -> V_112 ) ;
}
static void F_101 ( struct V_12 * V_12 )
{
F_102 ( & V_12 -> V_112 ) ;
}
static void F_103 ( struct V_12 * V_12 , struct V_15 * V_18 ,
bool V_113 )
{
( V_113 ? V_114 : V_115 )
( V_12 -> V_16 , V_18 , & V_12 -> V_116 ) ;
F_15 ( V_12 , V_18 ) ;
}
static void F_104 ( struct V_12 * V_12 , struct V_15 * V_18 ,
bool V_113 )
{
unsigned long V_59 ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_103 ( V_12 , V_18 , V_113 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
F_11 ( V_12 ) ;
}
static void F_105 ( struct V_19 * V_20 )
{
F_101 ( V_20 -> V_12 ) ;
F_19 ( V_20 ) ;
}
static void F_106 ( struct V_19 * V_20 )
{
struct V_12 * V_12 = V_20 -> V_12 ;
if ( V_20 -> V_117 ) {
F_107 ( L_1 ) ;
F_41 ( V_12 , V_20 -> V_118 , V_20 -> V_48 ) ;
F_104 ( V_12 , V_20 -> V_119 , false ) ;
} else if ( V_20 -> V_120 ) {
F_107 ( L_2 ) ;
F_108 ( V_12 -> V_50 , V_20 -> V_121 , V_20 -> V_118 ) ;
F_104 ( V_12 , V_20 -> V_119 , V_20 -> V_122 ? false : true ) ;
if ( V_20 -> V_122 )
F_104 ( V_12 , V_20 -> V_123 , true ) ;
} else {
F_107 ( L_3 ) ;
F_109 ( V_12 -> V_50 , V_20 -> V_121 ) ;
F_104 ( V_12 , V_20 -> V_123 , true ) ;
}
F_105 ( V_20 ) ;
}
static void F_110 ( struct V_19 * V_20 )
{
unsigned long V_59 ;
struct V_12 * V_12 = V_20 -> V_12 ;
if ( V_20 -> V_117 ) {
F_44 ( V_12 , V_20 -> V_118 , V_20 -> V_48 ) ;
F_104 ( V_12 , V_20 -> V_119 , false ) ;
F_105 ( V_20 ) ;
return;
} else if ( V_20 -> V_120 ) {
if ( F_111 ( V_12 -> V_66 , V_20 -> V_48 ) ) {
F_107 ( L_4 ) ;
F_108 ( V_12 -> V_50 , V_20 -> V_121 ,
V_20 -> V_118 ) ;
if ( V_20 -> V_122 )
F_104 ( V_12 , V_20 -> V_123 , true ) ;
F_105 ( V_20 ) ;
return;
}
} else {
if ( F_112 ( V_12 -> V_66 , V_20 -> V_48 , V_20 -> V_121 ) ) {
F_107 ( L_5 ) ;
F_109 ( V_12 -> V_50 , V_20 -> V_121 ) ;
F_105 ( V_20 ) ;
return;
}
}
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_113 ( & V_20 -> V_124 , & V_12 -> V_125 ) ;
V_12 -> V_106 = true ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
}
static void F_114 ( struct V_19 * V_20 )
{
unsigned long V_59 ;
struct V_12 * V_12 = V_20 -> V_12 ;
if ( V_20 -> V_117 ) {
F_115 ( L_6 ) ;
return;
} else if ( V_20 -> V_120 ) {
F_104 ( V_12 , V_20 -> V_119 , V_20 -> V_122 ? false : true ) ;
if ( V_20 -> V_122 ) {
V_20 -> V_120 = false ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_113 ( & V_20 -> V_124 , & V_12 -> V_126 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
} else {
if ( V_20 -> V_127 )
F_109 ( V_12 -> V_50 , V_20 -> V_118 ) ;
F_105 ( V_20 ) ;
}
} else {
if ( V_20 -> V_128 ) {
F_44 ( V_12 , V_20 -> V_121 , V_20 -> V_48 ) ;
F_104 ( V_12 , V_20 -> V_123 , true ) ;
} else {
F_41 ( V_12 , V_20 -> V_121 , V_20 -> V_48 ) ;
F_96 ( V_20 -> V_123 -> V_113 , 0 ) ;
F_104 ( V_12 , V_20 -> V_123 , false ) ;
}
F_105 ( V_20 ) ;
}
}
static void F_116 ( int V_129 , unsigned long V_130 , void * V_131 )
{
unsigned long V_59 ;
struct V_19 * V_20 = (struct V_19 * ) V_131 ;
struct V_12 * V_12 = V_20 -> V_12 ;
if ( V_129 || V_130 )
V_20 -> V_109 = true ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_113 ( & V_20 -> V_124 , & V_12 -> V_132 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
F_11 ( V_12 ) ;
}
static void F_117 ( struct V_19 * V_20 )
{
int V_29 ;
struct V_133 V_134 , V_135 ;
struct V_12 * V_12 = V_20 -> V_12 ;
T_10 V_48 = F_40 ( V_20 -> V_48 ) ;
V_134 . V_92 = V_12 -> V_91 -> V_92 ;
V_134 . V_136 = V_12 -> V_57 ;
V_135 . V_92 = V_12 -> V_96 -> V_92 ;
V_135 . V_137 = V_48 * V_12 -> V_57 ;
V_135 . V_136 = V_12 -> V_57 ;
if ( V_20 -> V_117 || V_20 -> V_120 ) {
V_134 . V_137 = F_31 ( V_20 -> V_118 ) * V_12 -> V_57 ;
V_29 = F_118 ( V_12 -> V_138 , & V_135 , 1 , & V_134 , 0 , F_116 , V_20 ) ;
} else {
V_134 . V_137 = F_31 ( V_20 -> V_121 ) * V_12 -> V_57 ;
V_29 = F_118 ( V_12 -> V_138 , & V_134 , 1 , & V_135 , 0 , F_116 , V_20 ) ;
}
if ( V_29 < 0 ) {
F_119 ( L_7 ) ;
F_106 ( V_20 ) ;
}
}
static void F_120 ( struct V_8 * V_8 , int V_109 )
{
struct V_19 * V_20 = V_8 -> V_10 ;
struct V_12 * V_12 = V_20 -> V_12 ;
T_1 V_97 = F_74 ( V_12 ) ;
struct V_84 * V_86 = F_75 ( V_8 , V_97 ) ;
unsigned long V_59 ;
F_9 ( & V_86 -> V_110 , V_8 ) ;
if ( V_109 )
V_20 -> V_109 = true ;
V_20 -> V_128 = false ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_113 ( & V_20 -> V_124 , & V_12 -> V_132 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
F_11 ( V_12 ) ;
}
static void F_121 ( struct V_19 * V_20 , struct V_8 * V_8 )
{
T_1 V_97 = F_74 ( V_20 -> V_12 ) ;
struct V_84 * V_86 = F_75 ( V_8 , V_97 ) ;
F_8 ( & V_86 -> V_110 , V_8 , F_120 , V_20 ) ;
F_85 ( V_20 -> V_12 , V_8 , V_20 -> V_121 , V_20 -> V_48 ) ;
F_91 ( V_8 ) ;
}
static bool F_122 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
return ( F_84 ( V_8 ) == V_103 ) &&
( V_8 -> V_94 . V_139 == ( V_12 -> V_57 << V_140 ) ) ;
}
static void F_123 ( struct V_19 * V_20 )
{
F_10 ( & V_20 -> V_12 -> V_61 . V_141 ) ;
F_110 ( V_20 ) ;
}
static void F_124 ( struct V_12 * V_12 , struct V_8 * V_8 ,
T_9 * V_46 , T_9 * V_142 )
{
T_10 V_143 = V_8 -> V_94 . V_93 ;
T_10 V_144 = F_125 ( V_8 ) ;
* V_46 = F_54 ( F_126 ( V_143 , V_12 -> V_56 ) ) ;
if ( V_144 - V_143 < V_12 -> V_56 )
* V_142 = * V_46 ;
else
* V_142 = F_54 ( F_50 ( V_144 , V_12 -> V_56 ) ) ;
}
static void F_127 ( struct V_19 * V_20 )
{
T_9 V_46 , V_142 ;
struct V_8 * V_8 = V_20 -> V_123 -> V_113 ;
F_124 ( V_20 -> V_12 , V_8 , & V_46 , & V_142 ) ;
while ( V_46 != V_142 ) {
F_57 ( V_20 -> V_12 , V_46 ) ;
V_46 = F_54 ( F_56 ( V_46 ) + 1 ) ;
}
F_96 ( V_8 , 0 ) ;
F_104 ( V_20 -> V_12 , V_20 -> V_123 , false ) ;
F_19 ( V_20 ) ;
}
static void F_128 ( struct V_19 * V_20 )
{
bool V_145 ;
struct V_12 * V_12 = V_20 -> V_12 ;
if ( V_20 -> V_146 ) {
F_127 ( V_20 ) ;
return;
}
if ( V_20 -> V_117 || V_20 -> V_120 )
V_145 = ! F_38 ( V_12 , V_20 -> V_48 ) ||
F_64 ( V_12 , V_20 -> V_118 ) ;
else {
struct V_8 * V_8 = V_20 -> V_123 -> V_113 ;
V_145 = F_64 ( V_12 , V_20 -> V_121 ) ;
if ( F_72 ( & V_12 -> V_81 ) &&
! V_145 && F_122 ( V_12 , V_8 ) ) {
F_121 ( V_20 , V_8 ) ;
return;
}
}
V_145 ? F_123 ( V_20 ) : F_117 ( V_20 ) ;
}
static void F_129 ( struct V_19 * V_20 )
{
if ( V_20 -> V_109 )
F_106 ( V_20 ) ;
else
F_110 ( V_20 ) ;
}
static void F_130 ( struct V_12 * V_12 , struct V_147 * V_148 ,
void (* F_131)( struct V_19 * ) )
{
unsigned long V_59 ;
struct V_147 V_124 ;
struct V_19 * V_20 , * V_149 ;
F_132 ( & V_124 ) ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_133 ( V_148 , & V_124 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
F_134 (mg, tmp, &list, list)
F_131 ( V_20 ) ;
}
static void F_135 ( struct V_19 * V_20 )
{
F_113 ( & V_20 -> V_124 , & V_20 -> V_12 -> V_126 ) ;
}
static void F_136 ( struct V_19 * V_20 )
{
unsigned long V_59 ;
struct V_12 * V_12 = V_20 -> V_12 ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_135 ( V_20 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
F_11 ( V_12 ) ;
}
static void F_137 ( struct V_12 * V_12 , struct V_147 * V_150 )
{
unsigned long V_59 ;
struct V_19 * V_20 , * V_149 ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_134 (mg, tmp, work, list)
F_135 ( V_20 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
F_11 ( V_12 ) ;
}
static void F_138 ( struct V_12 * V_12 ,
struct V_84 * V_86 )
{
struct V_147 V_150 ;
if ( ! V_86 -> V_89 )
return;
F_132 ( & V_150 ) ;
F_139 ( V_86 -> V_89 , & V_150 ) ;
if ( ! F_140 ( & V_150 ) )
F_137 ( V_12 , & V_150 ) ;
}
static void F_141 ( struct V_19 * V_20 )
{
if ( ! F_142 ( V_20 -> V_12 -> V_105 , & V_20 -> V_124 ) )
F_136 ( V_20 ) ;
}
static void V_122 ( struct V_12 * V_12 , struct V_24 * V_45 ,
T_3 V_44 , T_5 V_48 ,
struct V_15 * V_18 )
{
struct V_19 * V_20 = F_25 ( V_45 ) ;
V_20 -> V_109 = false ;
V_20 -> V_146 = false ;
V_20 -> V_117 = false ;
V_20 -> V_120 = false ;
V_20 -> V_122 = true ;
V_20 -> V_128 = true ;
V_20 -> V_127 = false ;
V_20 -> V_12 = V_12 ;
V_20 -> V_121 = V_44 ;
V_20 -> V_48 = V_48 ;
V_20 -> V_119 = NULL ;
V_20 -> V_123 = V_18 ;
V_20 -> V_151 = V_152 ;
F_100 ( V_12 ) ;
F_141 ( V_20 ) ;
}
static void V_117 ( struct V_12 * V_12 , struct V_24 * V_45 ,
T_3 V_44 , T_5 V_48 ,
struct V_15 * V_18 )
{
struct V_19 * V_20 = F_25 ( V_45 ) ;
V_20 -> V_109 = false ;
V_20 -> V_146 = false ;
V_20 -> V_117 = true ;
V_20 -> V_120 = false ;
V_20 -> V_122 = false ;
V_20 -> V_128 = true ;
V_20 -> V_127 = false ;
V_20 -> V_12 = V_12 ;
V_20 -> V_118 = V_44 ;
V_20 -> V_48 = V_48 ;
V_20 -> V_119 = V_18 ;
V_20 -> V_123 = NULL ;
V_20 -> V_151 = V_152 ;
F_100 ( V_12 ) ;
F_141 ( V_20 ) ;
}
static void F_143 ( struct V_12 * V_12 , struct V_24 * V_45 ,
T_3 V_118 , T_3 V_121 ,
T_5 V_48 ,
struct V_15 * V_119 ,
struct V_15 * V_123 )
{
struct V_19 * V_20 = F_25 ( V_45 ) ;
V_20 -> V_109 = false ;
V_20 -> V_146 = false ;
V_20 -> V_117 = false ;
V_20 -> V_120 = true ;
V_20 -> V_122 = true ;
V_20 -> V_128 = true ;
V_20 -> V_127 = false ;
V_20 -> V_12 = V_12 ;
V_20 -> V_118 = V_118 ;
V_20 -> V_121 = V_121 ;
V_20 -> V_48 = V_48 ;
V_20 -> V_119 = V_119 ;
V_20 -> V_123 = V_123 ;
V_20 -> V_151 = V_152 ;
F_100 ( V_12 ) ;
F_141 ( V_20 ) ;
}
static void V_127 ( struct V_12 * V_12 , struct V_24 * V_45 ,
T_3 V_44 , T_5 V_48 ,
struct V_15 * V_18 )
{
struct V_19 * V_20 = F_25 ( V_45 ) ;
V_20 -> V_109 = false ;
V_20 -> V_146 = false ;
V_20 -> V_117 = false ;
V_20 -> V_120 = true ;
V_20 -> V_122 = false ;
V_20 -> V_128 = true ;
V_20 -> V_127 = true ;
V_20 -> V_12 = V_12 ;
V_20 -> V_118 = V_44 ;
V_20 -> V_48 = V_48 ;
V_20 -> V_119 = V_18 ;
V_20 -> V_123 = NULL ;
V_20 -> V_151 = V_152 ;
F_100 ( V_12 ) ;
F_141 ( V_20 ) ;
}
static void V_146 ( struct V_12 * V_12 , struct V_24 * V_45 ,
struct V_15 * V_18 )
{
struct V_19 * V_20 = F_25 ( V_45 ) ;
V_20 -> V_109 = false ;
V_20 -> V_146 = true ;
V_20 -> V_117 = false ;
V_20 -> V_120 = false ;
V_20 -> V_122 = false ;
V_20 -> V_128 = false ;
V_20 -> V_127 = false ;
V_20 -> V_12 = V_12 ;
V_20 -> V_119 = NULL ;
V_20 -> V_123 = V_18 ;
V_20 -> V_151 = V_152 ;
F_141 ( V_20 ) ;
}
static void F_144 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
unsigned long V_59 ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_92 ( & V_12 -> V_116 , V_8 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
F_11 ( V_12 ) ;
}
static void F_145 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
T_1 V_97 = F_74 ( V_12 ) ;
struct V_84 * V_86 = F_75 ( V_8 , V_97 ) ;
F_26 ( V_8 -> V_94 . V_139 ) ;
if ( ! V_86 -> V_88 )
F_79 ( V_12 , V_8 ) ;
else
F_80 ( V_12 , V_8 , 0 ) ;
F_90 ( V_12 , V_8 ) ;
}
static void F_146 ( struct V_12 * V_12 , struct V_24 * V_45 ,
struct V_8 * V_8 )
{
int V_29 ;
T_9 V_46 , V_142 ;
struct V_15 * V_40 , * V_123 ;
F_124 ( V_12 , V_8 , & V_46 , & V_142 ) ;
if ( V_46 == V_142 ) {
F_96 ( V_8 , 0 ) ;
return;
}
V_40 = F_27 ( V_45 ) ;
V_29 = F_32 ( V_12 , F_55 ( V_12 , V_46 ) , F_55 ( V_12 , V_142 ) , V_8 , V_40 ,
( T_4 ) F_29 ,
V_45 , & V_123 ) ;
if ( V_29 > 0 )
return;
V_146 ( V_12 , V_45 , V_123 ) ;
}
static bool F_147 ( struct V_12 * V_12 )
{
T_10 V_153 = ( F_69 ( & V_12 -> V_112 ) + 1 ) *
V_12 -> V_57 ;
return V_153 < V_12 -> V_154 ;
}
static void F_148 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
F_10 ( F_84 ( V_8 ) == V_155 ?
& V_12 -> V_61 . V_67 : & V_12 -> V_61 . V_71 ) ;
}
static void F_149 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
F_10 ( F_84 ( V_8 ) == V_155 ?
& V_12 -> V_61 . V_69 : & V_12 -> V_61 . V_73 ) ;
}
static void F_150 ( struct V_12 * V_12 , struct V_24 * V_45 ,
struct V_8 * V_8 )
{
int V_29 ;
bool V_156 = true ;
T_3 V_95 = F_86 ( V_12 , V_8 ) ;
struct V_15 * V_40 , * V_119 , * V_123 ;
struct V_157 V_158 ;
bool V_159 = F_73 ( & V_12 -> V_81 ) ;
bool V_160 , V_161 ;
V_40 = F_27 ( V_45 ) ;
V_29 = F_34 ( V_12 , V_95 , V_8 , V_40 ,
( T_4 ) F_29 ,
V_45 , & V_123 ) ;
if ( V_29 > 0 )
return;
V_160 = F_64 ( V_12 , V_95 ) ;
V_161 = ! V_159 && ( V_160 || F_147 ( V_12 ) ) ;
V_29 = F_151 ( V_12 -> V_50 , V_95 , true , V_161 , V_160 ,
V_8 , & V_158 ) ;
if ( V_29 == - V_162 )
V_158 . V_163 = V_164 ;
switch ( V_158 . V_163 ) {
case V_165 :
if ( V_159 ) {
F_149 ( V_12 , V_8 ) ;
if ( F_84 ( V_8 ) == V_103 ) {
F_10 ( & V_12 -> V_61 . V_166 ) ;
V_127 ( V_12 , V_45 , V_95 , V_158 . V_48 , V_123 ) ;
V_156 = false ;
} else {
F_83 ( V_12 , V_8 , V_95 ) ;
F_93 ( V_12 , V_8 , V_123 ) ;
}
} else {
F_148 ( V_12 , V_8 ) ;
if ( F_84 ( V_8 ) == V_103 &&
F_71 ( & V_12 -> V_81 ) &&
! F_38 ( V_12 , V_158 . V_48 ) ) {
F_98 ( V_12 , V_8 , V_95 , V_158 . V_48 ) ;
F_93 ( V_12 , V_8 , V_123 ) ;
} else {
F_85 ( V_12 , V_8 , V_95 , V_158 . V_48 ) ;
F_93 ( V_12 , V_8 , V_123 ) ;
}
}
break;
case V_164 :
F_149 ( V_12 , V_8 ) ;
F_83 ( V_12 , V_8 , V_95 ) ;
F_93 ( V_12 , V_8 , V_123 ) ;
break;
case V_167 :
F_10 ( & V_12 -> V_61 . V_168 ) ;
V_122 ( V_12 , V_45 , V_95 , V_158 . V_48 , V_123 ) ;
V_156 = false ;
break;
case V_169 :
V_40 = F_27 ( V_45 ) ;
V_29 = F_34 ( V_12 , V_158 . V_118 , V_8 , V_40 ,
( T_4 ) F_29 ,
V_45 , & V_119 ) ;
if ( V_29 > 0 ) {
F_108 ( V_12 -> V_50 , V_95 ,
V_158 . V_118 ) ;
F_10 ( & V_12 -> V_61 . V_170 ) ;
break;
}
F_10 ( & V_12 -> V_61 . V_166 ) ;
F_10 ( & V_12 -> V_61 . V_168 ) ;
F_143 ( V_12 , V_45 , V_158 . V_118 ,
V_95 , V_158 . V_48 ,
V_119 , V_123 ) ;
V_156 = false ;
break;
default:
F_119 ( L_8 , V_171 ,
( unsigned ) V_158 . V_163 ) ;
F_152 ( V_8 ) ;
}
if ( V_156 )
F_104 ( V_12 , V_123 , false ) ;
}
static int F_153 ( struct V_12 * V_12 )
{
return ! F_154 ( V_152 , V_12 -> V_172 ,
V_12 -> V_172 + V_173 ) ;
}
static int F_155 ( struct V_12 * V_12 )
{
int V_29 = 0 ;
if ( ( V_12 -> V_106 || F_153 ( V_12 ) ) &&
F_156 ( V_12 -> V_66 ) ) {
F_10 ( & V_12 -> V_61 . V_174 ) ;
V_12 -> V_106 = false ;
V_29 = F_157 ( V_12 -> V_66 , false ) ;
V_12 -> V_172 = V_152 ;
}
return V_29 ;
}
static void F_158 ( struct V_12 * V_12 )
{
unsigned long V_59 ;
struct V_175 V_176 ;
struct V_8 * V_8 ;
struct V_24 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
F_159 ( & V_176 ) ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_160 ( & V_176 , & V_12 -> V_116 ) ;
F_159 ( & V_12 -> V_116 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
while ( ! F_161 ( & V_176 ) ) {
if ( F_23 ( V_12 , & V_45 ) ) {
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_160 ( & V_12 -> V_116 , & V_176 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
break;
}
V_8 = F_162 ( & V_176 ) ;
if ( V_8 -> V_99 & V_101 )
F_145 ( V_12 , V_8 ) ;
else if ( V_8 -> V_99 & V_102 )
F_146 ( V_12 , & V_45 , V_8 ) ;
else
F_150 ( V_12 , & V_45 , V_8 ) ;
}
F_24 ( V_12 , & V_45 ) ;
}
static void F_163 ( struct V_12 * V_12 , bool V_177 )
{
unsigned long V_59 ;
struct V_175 V_176 ;
struct V_8 * V_8 ;
F_159 ( & V_176 ) ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_160 ( & V_176 , & V_12 -> V_107 ) ;
F_159 ( & V_12 -> V_107 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
while ( ( V_8 = F_162 ( & V_176 ) ) )
V_177 ? F_91 ( V_8 ) : F_152 ( V_8 ) ;
}
static void F_164 ( struct V_12 * V_12 )
{
unsigned long V_59 ;
struct V_175 V_176 ;
struct V_8 * V_8 ;
F_159 ( & V_176 ) ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
F_160 ( & V_176 , & V_12 -> V_108 ) ;
F_159 ( & V_12 -> V_108 ) ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
while ( ( V_8 = F_162 ( & V_176 ) ) )
F_91 ( V_8 ) ;
}
static void F_165 ( struct V_12 * V_12 )
{
int V_29 = 0 ;
T_3 V_44 ;
T_5 V_48 ;
struct V_24 V_45 ;
struct V_15 * V_119 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
while ( F_147 ( V_12 ) ) {
if ( F_23 ( V_12 , & V_45 ) )
break;
V_29 = F_166 ( V_12 -> V_50 , & V_44 , & V_48 ) ;
if ( V_29 )
break;
V_29 = F_36 ( V_12 , V_44 , & V_45 , & V_119 ) ;
if ( V_29 ) {
F_43 ( V_12 -> V_50 , V_44 ) ;
break;
}
V_117 ( V_12 , & V_45 , V_44 , V_48 , V_119 ) ;
}
F_24 ( V_12 , & V_45 ) ;
}
static void F_167 ( struct V_12 * V_12 , struct V_178 * V_179 )
{
int V_29 = 0 ;
T_11 V_30 = F_40 ( V_179 -> V_180 -> V_30 ) ;
T_11 V_31 = F_40 ( V_179 -> V_180 -> V_31 ) ;
while ( V_30 != V_31 ) {
V_29 = F_168 ( V_12 -> V_50 , F_169 ( V_30 ) ) ;
if ( ! V_29 ) {
V_29 = F_111 ( V_12 -> V_66 , F_169 ( V_30 ) ) ;
if ( V_29 )
break;
} else if ( V_29 == - V_181 ) {
V_29 = 0 ;
} else {
F_170 ( L_9 ) ;
break;
}
V_30 ++ ;
}
V_12 -> V_106 = true ;
V_179 -> V_109 = V_29 ;
F_67 ( & V_179 -> V_182 , 1 ) ;
F_21 ( & V_179 -> V_183 ) ;
}
static void F_171 ( struct V_12 * V_12 )
{
struct V_147 V_124 ;
struct V_178 * V_179 , * V_149 ;
F_132 ( & V_124 ) ;
F_172 ( & V_12 -> V_184 ) ;
F_133 ( & V_12 -> V_185 , & V_124 ) ;
F_173 ( & V_12 -> V_184 ) ;
F_134 (req, tmp, &list, list)
F_167 ( V_12 , V_179 ) ;
}
static bool F_174 ( struct V_12 * V_12 )
{
return F_69 ( & V_12 -> V_186 ) ;
}
static void F_175 ( struct V_12 * V_12 )
{
if ( F_174 ( V_12 ) ) {
F_10 ( & V_12 -> V_187 ) ;
F_21 ( & V_12 -> V_188 ) ;
}
}
static void F_176 ( struct V_12 * V_12 )
{
F_177 ( V_12 -> V_188 , F_69 ( & V_12 -> V_187 ) ) ;
}
static void F_178 ( struct V_12 * V_12 )
{
F_10 ( & V_12 -> V_186 ) ;
F_176 ( V_12 ) ;
}
static void F_179 ( struct V_12 * V_12 )
{
F_67 ( & V_12 -> V_186 , 0 ) ;
F_67 ( & V_12 -> V_187 , 0 ) ;
}
static void F_180 ( struct V_12 * V_12 )
{
F_177 ( V_12 -> V_23 , ! F_69 ( & V_12 -> V_22 ) ) ;
}
static void F_181 ( struct V_12 * V_12 )
{
F_182 ( & V_12 -> V_189 ) ;
F_183 ( V_12 -> V_13 ) ;
}
static void F_184 ( struct V_12 * V_12 )
{
struct V_8 * V_8 ;
struct V_175 V_176 ;
F_159 ( & V_176 ) ;
F_160 ( & V_176 , & V_12 -> V_116 ) ;
F_159 ( & V_12 -> V_116 ) ;
while ( ( V_8 = F_162 ( & V_176 ) ) )
F_96 ( V_8 , V_190 ) ;
}
static int F_185 ( struct V_12 * V_12 )
{
if ( F_174 ( V_12 ) )
return ! F_140 ( & V_12 -> V_126 ) ||
! F_140 ( & V_12 -> V_132 ) ||
! F_140 ( & V_12 -> V_125 ) ;
else
return ! F_161 ( & V_12 -> V_116 ) ||
! F_161 ( & V_12 -> V_107 ) ||
! F_161 ( & V_12 -> V_108 ) ||
! F_140 ( & V_12 -> V_126 ) ||
! F_140 ( & V_12 -> V_132 ) ||
! F_140 ( & V_12 -> V_125 ) ||
V_12 -> V_127 ;
}
static void F_186 ( struct V_191 * V_192 )
{
struct V_12 * V_12 = F_187 ( V_192 , struct V_12 , V_14 ) ;
do {
if ( ! F_174 ( V_12 ) ) {
F_165 ( V_12 ) ;
F_164 ( V_12 ) ;
F_158 ( V_12 ) ;
F_171 ( V_12 ) ;
}
F_130 ( V_12 , & V_12 -> V_126 , F_128 ) ;
F_130 ( V_12 , & V_12 -> V_132 , F_129 ) ;
if ( F_155 ( V_12 ) ) {
F_163 ( V_12 , false ) ;
F_130 ( V_12 , & V_12 -> V_125 , F_106 ) ;
} else {
F_163 ( V_12 , true ) ;
F_130 ( V_12 , & V_12 -> V_125 ,
F_114 ) ;
}
F_175 ( V_12 ) ;
} while ( F_185 ( V_12 ) );
}
static void F_188 ( struct V_191 * V_192 )
{
struct V_12 * V_12 = F_187 ( F_189 ( V_192 ) , struct V_12 , V_189 ) ;
F_190 ( V_12 -> V_50 ) ;
F_11 ( V_12 ) ;
F_191 ( V_12 -> V_13 , & V_12 -> V_189 , V_173 ) ;
}
static int F_192 ( struct V_193 * V_35 , int V_194 )
{
struct V_195 * V_196 = F_193 ( V_35 -> V_92 ) ;
return F_194 ( & V_196 -> V_197 , V_194 ) ;
}
static int F_195 ( struct V_198 * V_199 , int V_194 )
{
struct V_12 * V_12 = F_187 ( V_199 , struct V_12 , V_200 ) ;
return F_192 ( V_12 -> V_91 , V_194 ) ||
F_192 ( V_12 -> V_96 , V_194 ) ;
}
static void F_196 ( struct V_12 * V_12 )
{
unsigned V_201 ;
if ( V_12 -> V_21 )
F_197 ( V_12 -> V_21 ) ;
if ( V_12 -> V_105 )
F_198 ( V_12 -> V_105 ) ;
if ( V_12 -> V_16 )
F_199 ( V_12 -> V_16 ) ;
if ( V_12 -> V_13 )
F_200 ( V_12 -> V_13 ) ;
if ( V_12 -> V_47 )
F_6 ( V_12 -> V_47 ) ;
if ( V_12 -> V_64 )
F_6 ( V_12 -> V_64 ) ;
if ( V_12 -> V_138 )
F_201 ( V_12 -> V_138 ) ;
if ( V_12 -> V_66 )
F_202 ( V_12 -> V_66 ) ;
if ( V_12 -> V_202 )
F_203 ( V_12 -> V_51 , V_12 -> V_202 ) ;
if ( V_12 -> V_91 )
F_203 ( V_12 -> V_51 , V_12 -> V_91 ) ;
if ( V_12 -> V_96 )
F_203 ( V_12 -> V_51 , V_12 -> V_96 ) ;
if ( V_12 -> V_50 )
F_204 ( V_12 -> V_50 ) ;
for ( V_201 = 0 ; V_201 < V_12 -> V_203 ; V_201 ++ )
F_205 ( V_12 -> V_204 [ V_201 ] ) ;
F_205 ( V_12 -> V_204 ) ;
F_205 ( V_12 ) ;
}
static void F_206 ( struct V_205 * V_51 )
{
struct V_12 * V_12 = V_51 -> V_206 ;
F_196 ( V_12 ) ;
}
static T_10 F_207 ( struct V_193 * V_35 )
{
return F_208 ( V_35 -> V_92 -> V_207 ) >> V_140 ;
}
static void F_209 ( struct V_208 * V_209 )
{
if ( V_209 -> V_202 )
F_203 ( V_209 -> V_51 , V_209 -> V_202 ) ;
if ( V_209 -> V_96 )
F_203 ( V_209 -> V_51 , V_209 -> V_96 ) ;
if ( V_209 -> V_91 )
F_203 ( V_209 -> V_51 , V_209 -> V_91 ) ;
F_205 ( V_209 ) ;
}
static bool F_210 ( struct V_210 * V_211 , char * * error )
{
if ( ! V_211 -> V_212 ) {
* error = L_10 ;
return false ;
}
return true ;
}
static int F_211 ( struct V_208 * V_209 , struct V_210 * V_211 ,
char * * error )
{
int V_29 ;
T_10 V_213 ;
char V_46 [ V_214 ] ;
if ( ! F_210 ( V_211 , error ) )
return - V_215 ;
V_29 = F_212 ( V_209 -> V_51 , F_213 ( V_211 ) , V_216 | V_217 ,
& V_209 -> V_202 ) ;
if ( V_29 ) {
* error = L_11 ;
return V_29 ;
}
V_213 = F_207 ( V_209 -> V_202 ) ;
if ( V_213 > V_218 )
F_115 ( L_12 ,
F_214 ( V_209 -> V_202 -> V_92 , V_46 ) , V_219 ) ;
return 0 ;
}
static int F_215 ( struct V_208 * V_209 , struct V_210 * V_211 ,
char * * error )
{
int V_29 ;
if ( ! F_210 ( V_211 , error ) )
return - V_215 ;
V_29 = F_212 ( V_209 -> V_51 , F_213 ( V_211 ) , V_216 | V_217 ,
& V_209 -> V_96 ) ;
if ( V_29 ) {
* error = L_13 ;
return V_29 ;
}
V_209 -> V_220 = F_207 ( V_209 -> V_96 ) ;
return 0 ;
}
static int F_216 ( struct V_208 * V_209 , struct V_210 * V_211 ,
char * * error )
{
int V_29 ;
if ( ! F_210 ( V_211 , error ) )
return - V_215 ;
V_29 = F_212 ( V_209 -> V_51 , F_213 ( V_211 ) , V_216 | V_217 ,
& V_209 -> V_91 ) ;
if ( V_29 ) {
* error = L_14 ;
return V_29 ;
}
V_209 -> V_221 = F_207 ( V_209 -> V_91 ) ;
if ( V_209 -> V_51 -> V_222 > V_209 -> V_221 ) {
* error = L_15 ;
return - V_215 ;
}
return 0 ;
}
static int F_217 ( struct V_208 * V_209 , struct V_210 * V_211 ,
char * * error )
{
unsigned long V_223 ;
if ( ! F_210 ( V_211 , error ) )
return - V_215 ;
if ( F_218 ( F_213 ( V_211 ) , 10 , & V_223 ) || ! V_223 ||
V_223 < V_224 ||
V_223 > V_225 ||
V_223 & ( V_224 - 1 ) ) {
* error = L_16 ;
return - V_215 ;
}
if ( V_223 > V_209 -> V_220 ) {
* error = L_17 ;
return - V_215 ;
}
V_209 -> V_223 = V_223 ;
return 0 ;
}
static void F_219 ( struct V_75 * V_226 )
{
V_226 -> V_227 = V_228 ;
V_226 -> V_77 = V_79 ;
}
static int F_220 ( struct V_208 * V_209 , struct V_210 * V_211 ,
char * * error )
{
static struct V_229 V_230 [] = {
{ 0 , 1 , L_18 } ,
} ;
int V_29 ;
unsigned V_212 ;
const char * V_231 ;
struct V_75 * V_226 = & V_209 -> V_81 ;
F_219 ( V_226 ) ;
V_29 = F_221 ( V_230 , V_211 , & V_212 , error ) ;
if ( V_29 )
return - V_215 ;
while ( V_212 -- ) {
V_231 = F_213 ( V_211 ) ;
if ( ! strcasecmp ( V_231 , L_19 ) )
V_226 -> V_77 = V_79 ;
else if ( ! strcasecmp ( V_231 , L_20 ) )
V_226 -> V_77 = V_78 ;
else if ( ! strcasecmp ( V_231 , L_21 ) )
V_226 -> V_77 = V_80 ;
else {
* error = L_22 ;
return - V_215 ;
}
}
return 0 ;
}
static int F_222 ( struct V_208 * V_209 , struct V_210 * V_211 ,
char * * error )
{
static struct V_229 V_230 [] = {
{ 0 , 1024 , L_23 } ,
} ;
int V_29 ;
if ( ! F_210 ( V_211 , error ) )
return - V_215 ;
V_209 -> V_232 = F_213 ( V_211 ) ;
V_29 = F_221 ( V_230 , V_211 , & V_209 -> V_233 , error ) ;
if ( V_29 )
return - V_215 ;
V_209 -> V_234 = ( const char * * ) V_211 -> V_235 ;
F_223 ( V_211 , V_209 -> V_233 ) ;
return 0 ;
}
static int F_224 ( struct V_208 * V_209 , int V_212 , char * * V_235 ,
char * * error )
{
int V_29 ;
struct V_210 V_211 ;
V_211 . V_212 = V_212 ;
V_211 . V_235 = V_235 ;
V_29 = F_211 ( V_209 , & V_211 , error ) ;
if ( V_29 )
return V_29 ;
V_29 = F_215 ( V_209 , & V_211 , error ) ;
if ( V_29 )
return V_29 ;
V_29 = F_216 ( V_209 , & V_211 , error ) ;
if ( V_29 )
return V_29 ;
V_29 = F_217 ( V_209 , & V_211 , error ) ;
if ( V_29 )
return V_29 ;
V_29 = F_220 ( V_209 , & V_211 , error ) ;
if ( V_29 )
return V_29 ;
V_29 = F_222 ( V_209 , & V_211 , error ) ;
if ( V_29 )
return V_29 ;
return 0 ;
}
static int F_225 ( struct V_12 * V_12 , const char * V_33 , const char * V_236 )
{
unsigned long V_149 ;
if ( ! strcasecmp ( V_33 , L_24 ) ) {
if ( F_218 ( V_236 , 10 , & V_149 ) )
return - V_215 ;
V_12 -> V_154 = V_149 ;
return 0 ;
}
return V_237 ;
}
static int F_226 ( struct V_12 * V_12 , const char * V_33 , const char * V_236 )
{
int V_29 = F_225 ( V_12 , V_33 , V_236 ) ;
if ( V_29 == V_237 )
V_29 = F_227 ( V_12 -> V_50 , V_33 , V_236 ) ;
if ( V_29 )
F_115 ( L_25 , V_33 , V_236 ) ;
return V_29 ;
}
static int F_228 ( struct V_12 * V_12 , int V_212 , const char * * V_235 )
{
int V_29 = 0 ;
if ( V_212 & 1 ) {
F_115 ( L_26 ) ;
return - V_215 ;
}
while ( V_212 ) {
V_29 = F_226 ( V_12 , V_235 [ 0 ] , V_235 [ 1 ] ) ;
if ( V_29 )
break;
V_212 -= 2 ;
V_235 += 2 ;
}
return V_29 ;
}
static int F_229 ( struct V_12 * V_12 , struct V_208 * V_209 ,
char * * error )
{
struct V_238 * V_25 = F_230 ( V_209 -> V_232 ,
V_12 -> V_239 ,
V_12 -> V_221 ,
V_12 -> V_57 ) ;
if ( F_231 ( V_25 ) ) {
* error = L_27 ;
return F_232 ( V_25 ) ;
}
V_12 -> V_50 = V_25 ;
return 0 ;
}
static bool F_233 ( T_10 V_56 ,
T_10 V_240 )
{
( void ) F_81 ( V_240 , V_56 ) ;
return V_240 > V_241 ;
}
static T_10 F_234 ( T_10 V_242 ,
T_10 V_240 )
{
T_10 V_56 = V_242 ;
if ( V_240 )
while ( F_233 ( V_56 , V_240 ) )
V_56 *= 2 ;
return V_56 ;
}
static void F_235 ( struct V_12 * V_12 , T_5 V_243 )
{
T_7 V_244 = F_40 ( V_243 ) ;
if ( V_244 > ( 1 << 20 ) && V_12 -> V_239 != V_243 )
F_107 ( L_28
L_29
L_30 ,
( unsigned long long ) V_244 ) ;
V_12 -> V_239 = V_243 ;
}
static int F_236 ( struct V_208 * V_209 , struct V_12 * * V_245 )
{
int V_29 = 0 ;
char * * error = & V_209 -> V_51 -> error ;
struct V_12 * V_12 ;
struct V_205 * V_51 = V_209 -> V_51 ;
T_7 V_246 ;
struct V_247 * V_66 ;
bool V_248 = V_209 -> V_81 . V_227 == V_228 ;
V_12 = F_237 ( sizeof( * V_12 ) , V_249 ) ;
if ( ! V_12 )
return - V_26 ;
V_12 -> V_51 = V_209 -> V_51 ;
V_51 -> V_206 = V_12 ;
V_51 -> V_250 = 2 ;
V_51 -> V_251 = true ;
V_51 -> V_252 = 1 ;
V_51 -> V_253 = true ;
V_51 -> V_254 = true ;
V_51 -> V_255 = false ;
V_12 -> V_81 = V_209 -> V_81 ;
V_51 -> V_256 = F_74 ( V_12 ) ;
V_12 -> V_200 . V_257 = F_195 ;
F_238 ( V_51 -> V_52 , & V_12 -> V_200 ) ;
V_12 -> V_202 = V_209 -> V_202 ;
V_12 -> V_91 = V_209 -> V_91 ;
V_12 -> V_96 = V_209 -> V_96 ;
V_209 -> V_202 = V_209 -> V_91 = V_209 -> V_96 = NULL ;
V_246 = V_12 -> V_221 = V_209 -> V_221 ;
V_246 = F_50 ( V_246 , V_209 -> V_223 ) ;
V_12 -> V_246 = F_35 ( V_246 ) ;
V_12 -> V_57 = V_209 -> V_223 ;
if ( F_239 ( V_51 , V_12 -> V_57 ) ) {
V_29 = - V_215 ;
goto V_258;
}
if ( V_209 -> V_223 & ( V_209 -> V_223 - 1 ) ) {
T_7 V_239 = V_209 -> V_220 ;
V_12 -> V_53 = - 1 ;
V_239 = F_50 ( V_239 , V_209 -> V_223 ) ;
F_235 ( V_12 , F_169 ( V_239 ) ) ;
} else {
V_12 -> V_53 = F_240 ( V_209 -> V_223 ) ;
F_235 ( V_12 , F_169 ( V_209 -> V_220 >> V_12 -> V_53 ) ) ;
}
V_29 = F_229 ( V_12 , V_209 , error ) ;
if ( V_29 )
goto V_258;
V_12 -> V_259 = V_209 -> V_233 ;
V_12 -> V_154 = V_260 ;
V_29 = F_228 ( V_12 , V_209 -> V_233 , V_209 -> V_234 ) ;
if ( V_29 ) {
* error = L_31 ;
goto V_258;
}
V_66 = F_241 ( V_12 -> V_202 -> V_92 ,
V_209 -> V_223 , V_248 ,
F_242 ( V_12 -> V_50 ) ) ;
if ( F_231 ( V_66 ) ) {
* error = L_32 ;
V_29 = F_232 ( V_66 ) ;
goto V_258;
}
V_12 -> V_66 = V_66 ;
if ( F_73 ( & V_12 -> V_81 ) ) {
bool V_261 ;
V_29 = F_243 ( V_12 -> V_66 , & V_261 ) ;
if ( V_29 ) {
* error = L_33 ;
goto V_258;
}
if ( ! V_261 ) {
* error = L_34 ;
V_29 = - V_215 ;
goto V_258;
}
}
F_244 ( & V_12 -> V_63 ) ;
F_159 ( & V_12 -> V_116 ) ;
F_159 ( & V_12 -> V_107 ) ;
F_159 ( & V_12 -> V_108 ) ;
F_132 ( & V_12 -> V_126 ) ;
F_132 ( & V_12 -> V_132 ) ;
F_132 ( & V_12 -> V_125 ) ;
F_67 ( & V_12 -> V_22 , 0 ) ;
F_67 ( & V_12 -> V_112 , 0 ) ;
F_245 ( & V_12 -> V_23 ) ;
F_245 ( & V_12 -> V_188 ) ;
F_67 ( & V_12 -> V_186 , 0 ) ;
F_67 ( & V_12 -> V_187 , 0 ) ;
V_29 = - V_26 ;
F_67 ( & V_12 -> V_49 , 0 ) ;
V_12 -> V_47 = F_3 ( F_40 ( V_12 -> V_239 ) ) ;
if ( ! V_12 -> V_47 ) {
* error = L_35 ;
goto V_258;
}
F_5 ( V_12 -> V_47 , F_40 ( V_12 -> V_239 ) ) ;
V_12 -> V_56 =
F_234 ( V_12 -> V_57 ,
V_12 -> V_221 ) ;
V_12 -> V_60 = F_54 ( F_126 ( V_12 -> V_221 ,
V_12 -> V_56 ) ) ;
V_12 -> V_64 = F_3 ( F_56 ( V_12 -> V_60 ) ) ;
if ( ! V_12 -> V_64 ) {
* error = L_36 ;
goto V_258;
}
F_5 ( V_12 -> V_64 , F_56 ( V_12 -> V_60 ) ) ;
V_12 -> V_138 = F_246 ( & V_262 ) ;
if ( F_231 ( V_12 -> V_138 ) ) {
* error = L_37 ;
V_29 = F_232 ( V_12 -> V_138 ) ;
goto V_258;
}
V_12 -> V_13 = F_247 ( L_38 V_263 , V_264 ) ;
if ( ! V_12 -> V_13 ) {
* error = L_39 ;
goto V_258;
}
F_248 ( & V_12 -> V_14 , F_186 ) ;
F_249 ( & V_12 -> V_189 , F_188 ) ;
V_12 -> V_172 = V_152 ;
V_12 -> V_16 = F_250 () ;
if ( ! V_12 -> V_16 ) {
* error = L_40 ;
goto V_258;
}
V_12 -> V_105 = F_251 () ;
if ( ! V_12 -> V_105 ) {
* error = L_41 ;
goto V_258;
}
V_12 -> V_21 = F_252 ( V_265 ,
V_266 ) ;
if ( ! V_12 -> V_21 ) {
* error = L_42 ;
goto V_258;
}
V_12 -> V_98 = true ;
V_12 -> V_267 = false ;
V_12 -> V_127 = false ;
V_12 -> V_106 = false ;
V_12 -> V_268 = false ;
V_12 -> V_269 = false ;
F_65 ( V_12 ) ;
F_67 ( & V_12 -> V_61 . V_166 , 0 ) ;
F_67 ( & V_12 -> V_61 . V_168 , 0 ) ;
F_67 ( & V_12 -> V_61 . V_141 , 0 ) ;
F_67 ( & V_12 -> V_61 . V_170 , 0 ) ;
F_67 ( & V_12 -> V_61 . V_174 , 0 ) ;
F_67 ( & V_12 -> V_61 . V_62 , 0 ) ;
F_244 ( & V_12 -> V_184 ) ;
F_132 ( & V_12 -> V_185 ) ;
* V_245 = V_12 ;
return 0 ;
V_258:
F_196 ( V_12 ) ;
return V_29 ;
}
static int F_253 ( struct V_12 * V_12 , int V_212 , const char * * V_235 )
{
unsigned V_201 ;
const char * * V_270 ;
V_270 = F_254 ( V_212 , sizeof( * V_270 ) , V_249 ) ;
if ( ! V_270 )
return - V_26 ;
for ( V_201 = 0 ; V_201 < V_212 ; V_201 ++ ) {
V_270 [ V_201 ] = F_255 ( V_235 [ V_201 ] , V_249 ) ;
if ( ! V_270 [ V_201 ] ) {
while ( V_201 -- )
F_205 ( V_270 [ V_201 ] ) ;
F_205 ( V_270 ) ;
return - V_26 ;
}
}
V_12 -> V_203 = V_212 ;
V_12 -> V_204 = V_270 ;
return 0 ;
}
static int F_256 ( struct V_205 * V_51 , unsigned V_212 , char * * V_235 )
{
int V_29 = - V_215 ;
struct V_208 * V_209 ;
struct V_12 * V_12 = NULL ;
V_209 = F_237 ( sizeof( * V_209 ) , V_249 ) ;
if ( ! V_209 ) {
V_51 -> error = L_43 ;
return - V_26 ;
}
V_209 -> V_51 = V_51 ;
V_29 = F_224 ( V_209 , V_212 , V_235 , & V_51 -> error ) ;
if ( V_29 )
goto V_271;
V_29 = F_236 ( V_209 , & V_12 ) ;
if ( V_29 )
goto V_271;
V_29 = F_253 ( V_12 , V_212 - 3 , ( const char * * ) V_235 + 3 ) ;
if ( V_29 ) {
F_196 ( V_12 ) ;
goto V_271;
}
V_51 -> V_206 = V_12 ;
V_271:
F_209 ( V_209 ) ;
return V_29 ;
}
static int F_257 ( struct V_12 * V_12 , struct V_8 * V_8 , struct V_15 * * V_18 )
{
int V_29 ;
T_3 V_95 = F_86 ( V_12 , V_8 ) ;
T_1 V_97 = F_74 ( V_12 ) ;
bool V_161 = false ;
bool V_160 ;
struct V_157 V_158 ;
struct V_84 * V_86 = F_77 ( V_8 , V_97 ) ;
if ( F_258 ( F_31 ( V_95 ) >= F_31 ( V_12 -> V_246 ) ) ) {
F_79 ( V_12 , V_8 ) ;
return V_272 ;
}
if ( V_8 -> V_99 & ( V_101 | V_100 | V_102 ) ) {
F_144 ( V_12 , V_8 ) ;
return V_273 ;
}
* V_18 = F_13 ( V_12 ) ;
if ( ! * V_18 ) {
F_144 ( V_12 , V_8 ) ;
return V_273 ;
}
V_29 = F_34 ( V_12 , V_95 , V_8 , * V_18 ,
( T_4 ) F_15 ,
V_12 , V_18 ) ;
if ( V_29 ) {
if ( V_29 < 0 )
F_144 ( V_12 , V_8 ) ;
return V_273 ;
}
V_160 = F_64 ( V_12 , V_95 ) ;
V_29 = F_151 ( V_12 -> V_50 , V_95 , false , V_161 , V_160 ,
V_8 , & V_158 ) ;
if ( V_29 == - V_162 ) {
F_104 ( V_12 , * V_18 , true ) ;
return V_273 ;
} else if ( V_29 ) {
F_119 ( L_44 , V_29 ) ;
F_104 ( V_12 , * V_18 , false ) ;
F_152 ( V_8 ) ;
return V_273 ;
}
V_29 = V_272 ;
switch ( V_158 . V_163 ) {
case V_165 :
if ( F_73 ( & V_12 -> V_81 ) ) {
if ( F_84 ( V_8 ) == V_103 ) {
F_104 ( V_12 , * V_18 , true ) ;
V_29 = V_273 ;
} else {
F_149 ( V_12 , V_8 ) ;
F_83 ( V_12 , V_8 , V_95 ) ;
}
} else {
F_148 ( V_12 , V_8 ) ;
if ( F_84 ( V_8 ) == V_103 && F_71 ( & V_12 -> V_81 ) &&
! F_38 ( V_12 , V_158 . V_48 ) )
F_98 ( V_12 , V_8 , V_95 , V_158 . V_48 ) ;
else
F_85 ( V_12 , V_8 , V_95 , V_158 . V_48 ) ;
}
break;
case V_164 :
F_149 ( V_12 , V_8 ) ;
if ( V_86 -> V_88 != 0 ) {
F_96 ( V_8 , 0 ) ;
F_104 ( V_12 , * V_18 , false ) ;
V_29 = V_273 ;
} else
F_83 ( V_12 , V_8 , V_95 ) ;
break;
default:
F_119 ( L_45 , V_171 ,
( unsigned ) V_158 . V_163 ) ;
F_104 ( V_12 , * V_18 , false ) ;
F_152 ( V_8 ) ;
V_29 = V_273 ;
}
return V_29 ;
}
static int F_259 ( struct V_205 * V_51 , struct V_8 * V_8 )
{
int V_29 ;
struct V_15 * V_18 = NULL ;
struct V_12 * V_12 = V_51 -> V_206 ;
V_29 = F_257 ( V_12 , V_8 , & V_18 ) ;
if ( V_29 == V_272 && V_18 ) {
F_88 ( V_12 , V_8 , V_18 ) ;
F_104 ( V_12 , V_18 , false ) ;
}
return V_29 ;
}
static int F_260 ( struct V_205 * V_51 , struct V_8 * V_8 , int error )
{
struct V_12 * V_12 = V_51 -> V_206 ;
unsigned long V_59 ;
T_1 V_97 = F_74 ( V_12 ) ;
struct V_84 * V_86 = F_75 ( V_8 , V_97 ) ;
if ( V_86 -> V_87 ) {
F_190 ( V_12 -> V_50 ) ;
F_58 ( & V_12 -> V_63 , V_59 ) ;
V_12 -> V_98 = true ;
F_60 ( & V_12 -> V_63 , V_59 ) ;
}
F_138 ( V_12 , V_86 ) ;
return 0 ;
}
static int F_261 ( struct V_12 * V_12 )
{
unsigned V_201 , V_29 ;
for ( V_201 = 0 ; V_201 < F_40 ( V_12 -> V_239 ) ; V_201 ++ ) {
V_29 = F_262 ( V_12 -> V_66 , F_169 ( V_201 ) ,
F_38 ( V_12 , F_169 ( V_201 ) ) ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_263 ( struct V_12 * V_12 )
{
unsigned V_201 , V_29 ;
V_29 = F_264 ( V_12 -> V_66 , V_12 -> V_56 ,
V_12 -> V_60 ) ;
if ( V_29 ) {
F_170 ( L_46 ) ;
return V_29 ;
}
for ( V_201 = 0 ; V_201 < F_56 ( V_12 -> V_60 ) ; V_201 ++ ) {
V_29 = F_265 ( V_12 -> V_66 , F_54 ( V_201 ) ,
F_63 ( V_12 , F_54 ( V_201 ) ) ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static bool F_266 ( struct V_12 * V_12 )
{
int V_274 , V_275 , V_276 , V_277 ;
V_274 = F_261 ( V_12 ) ;
if ( V_274 )
F_170 ( L_47 ) ;
V_275 = F_263 ( V_12 ) ;
if ( V_275 )
F_170 ( L_48 ) ;
F_68 ( V_12 ) ;
V_276 = F_267 ( V_12 -> V_66 , V_12 -> V_50 ) ;
if ( V_276 )
F_170 ( L_49 ) ;
V_277 = F_157 ( V_12 -> V_66 , ! V_274 && ! V_275 && ! V_276 ) ;
if ( V_277 )
F_170 ( L_50 ) ;
return ! V_274 && ! V_275 && ! V_276 && ! V_277 ;
}
static void F_268 ( struct V_205 * V_51 )
{
struct V_12 * V_12 = V_51 -> V_206 ;
F_178 ( V_12 ) ;
F_180 ( V_12 ) ;
F_181 ( V_12 ) ;
F_184 ( V_12 ) ;
F_179 ( V_12 ) ;
( void ) F_266 ( V_12 ) ;
}
static int F_269 ( void * V_131 , T_3 V_44 , T_5 V_48 ,
bool V_278 , T_8 V_279 , bool V_280 )
{
int V_29 ;
struct V_12 * V_12 = V_131 ;
V_29 = F_270 ( V_12 -> V_50 , V_44 , V_48 , V_279 , V_280 ) ;
if ( V_29 )
return V_29 ;
if ( V_278 )
F_41 ( V_12 , V_44 , V_48 ) ;
else
F_44 ( V_12 , V_44 , V_48 ) ;
return 0 ;
}
static void F_271 ( struct V_12 * V_12 ,
struct V_281 * V_282 )
{
V_282 -> V_12 = V_12 ;
V_282 -> V_283 = V_282 -> V_284 = 0 ;
}
static void F_272 ( struct V_281 * V_282 )
{
T_10 V_46 , V_142 ;
if ( V_282 -> V_283 == V_282 -> V_284 )
return;
V_46 = V_282 -> V_283 * V_282 -> V_223 ;
V_142 = V_282 -> V_284 * V_282 -> V_223 ;
V_46 = F_126 ( V_46 , V_282 -> V_12 -> V_56 ) ;
F_81 ( V_142 , V_282 -> V_12 -> V_56 ) ;
if ( V_142 > F_56 ( V_282 -> V_12 -> V_60 ) )
V_142 = F_56 ( V_282 -> V_12 -> V_60 ) ;
for (; V_46 < V_142 ; V_46 ++ )
F_57 ( V_282 -> V_12 , F_54 ( V_46 ) ) ;
}
static int F_273 ( void * V_131 , T_10 V_56 ,
T_9 V_58 , bool V_146 )
{
struct V_281 * V_282 = V_131 ;
V_282 -> V_223 = V_56 ;
if ( V_146 ) {
if ( F_56 ( V_58 ) == V_282 -> V_284 )
V_282 -> V_284 = V_282 -> V_284 + 1ULL ;
else {
F_272 ( V_282 ) ;
V_282 -> V_283 = F_56 ( V_58 ) ;
V_282 -> V_284 = V_282 -> V_283 + 1ULL ;
}
} else {
F_272 ( V_282 ) ;
V_282 -> V_283 = V_282 -> V_284 = 0 ;
}
return 0 ;
}
static T_5 F_274 ( struct V_12 * V_12 )
{
T_10 V_243 = F_207 ( V_12 -> V_96 ) ;
( void ) F_81 ( V_243 , V_12 -> V_57 ) ;
return F_169 ( V_243 ) ;
}
static bool F_275 ( struct V_12 * V_12 , T_5 V_285 )
{
if ( F_40 ( V_285 ) > F_40 ( V_12 -> V_239 ) )
return true ;
while ( F_40 ( V_285 ) < F_40 ( V_12 -> V_239 ) ) {
V_285 = F_169 ( F_40 ( V_285 ) + 1 ) ;
if ( F_38 ( V_12 , V_285 ) ) {
F_170 ( L_51 ,
( unsigned long long ) F_40 ( V_285 ) ) ;
return false ;
}
}
return true ;
}
static int F_276 ( struct V_12 * V_12 , T_5 V_285 )
{
int V_29 ;
V_29 = F_277 ( V_12 -> V_66 , V_285 ) ;
if ( V_29 ) {
F_170 ( L_52 ) ;
return V_29 ;
}
F_235 ( V_12 , V_285 ) ;
return 0 ;
}
static int F_278 ( struct V_205 * V_51 )
{
int V_29 = 0 ;
struct V_12 * V_12 = V_51 -> V_206 ;
T_5 V_286 = F_274 ( V_12 ) ;
if ( ! V_12 -> V_267 ) {
V_29 = F_276 ( V_12 , V_286 ) ;
if ( V_29 )
return V_29 ;
V_12 -> V_267 = true ;
} else if ( V_286 != V_12 -> V_239 ) {
if ( ! F_275 ( V_12 , V_286 ) )
return - V_215 ;
V_29 = F_276 ( V_12 , V_286 ) ;
if ( V_29 )
return V_29 ;
}
if ( ! V_12 -> V_268 ) {
V_29 = F_279 ( V_12 -> V_66 , V_12 -> V_50 ,
F_269 , V_12 ) ;
if ( V_29 ) {
F_170 ( L_53 ) ;
return V_29 ;
}
V_12 -> V_268 = true ;
}
if ( ! V_12 -> V_269 ) {
struct V_281 V_282 ;
F_5 ( V_12 -> V_64 , F_56 ( V_12 -> V_60 ) ) ;
F_271 ( V_12 , & V_282 ) ;
V_29 = F_280 ( V_12 -> V_66 , F_273 , & V_282 ) ;
if ( V_29 ) {
F_170 ( L_54 ) ;
return V_29 ;
}
F_272 ( & V_282 ) ;
V_12 -> V_269 = true ;
}
return V_29 ;
}
static void F_281 ( struct V_205 * V_51 )
{
struct V_12 * V_12 = V_51 -> V_206 ;
V_12 -> V_98 = true ;
F_188 ( & V_12 -> V_189 . V_150 ) ;
}
static void F_282 ( struct V_205 * V_51 , T_12 type ,
unsigned V_287 , char * V_245 , unsigned V_288 )
{
int V_29 = 0 ;
unsigned V_201 ;
T_13 V_289 = 0 ;
T_7 V_290 = 0 ;
T_7 V_291 = 0 ;
char V_292 [ V_214 ] ;
struct V_12 * V_12 = V_51 -> V_206 ;
T_5 V_293 ;
switch ( type ) {
case V_294 :
if ( ! ( V_287 & V_295 ) && ! F_283 ( V_51 ) ) {
V_29 = F_157 ( V_12 -> V_66 , false ) ;
if ( V_29 )
F_170 ( L_55 ) ;
}
V_29 = F_284 ( V_12 -> V_66 ,
& V_290 ) ;
if ( V_29 ) {
F_170 ( L_56 ) ;
goto V_109;
}
V_29 = F_285 ( V_12 -> V_66 , & V_291 ) ;
if ( V_29 ) {
F_170 ( L_57 ) ;
goto V_109;
}
V_293 = F_286 ( V_12 -> V_50 ) ;
F_287 ( L_58 ,
( unsigned ) V_296 ,
( unsigned long long ) ( V_291 - V_290 ) ,
( unsigned long long ) V_291 ,
V_12 -> V_57 ,
( unsigned long long ) F_40 ( V_293 ) ,
( unsigned long long ) F_40 ( V_12 -> V_239 ) ,
( unsigned ) F_69 ( & V_12 -> V_61 . V_67 ) ,
( unsigned ) F_69 ( & V_12 -> V_61 . V_69 ) ,
( unsigned ) F_69 ( & V_12 -> V_61 . V_71 ) ,
( unsigned ) F_69 ( & V_12 -> V_61 . V_73 ) ,
( unsigned ) F_69 ( & V_12 -> V_61 . V_166 ) ,
( unsigned ) F_69 ( & V_12 -> V_61 . V_168 ) ,
( unsigned long ) F_69 ( & V_12 -> V_49 ) ) ;
if ( F_71 ( & V_12 -> V_81 ) )
F_287 ( L_59 ) ;
else if ( F_73 ( & V_12 -> V_81 ) )
F_287 ( L_60 ) ;
else if ( F_72 ( & V_12 -> V_81 ) )
F_287 ( L_61 ) ;
else {
F_170 ( L_62 , ( int ) V_12 -> V_81 . V_77 ) ;
goto V_109;
}
F_287 ( L_63 , ( unsigned long long ) V_12 -> V_154 ) ;
F_287 ( L_64 , F_288 ( V_12 -> V_50 ) ) ;
if ( V_289 < V_288 ) {
V_29 = F_289 ( V_12 -> V_50 , V_245 + V_289 , V_288 - V_289 ) ;
if ( V_29 )
F_170 ( L_65 , V_29 ) ;
}
break;
case V_297 :
F_290 ( V_292 , V_12 -> V_202 -> V_92 -> V_298 ) ;
F_287 ( L_64 , V_292 ) ;
F_290 ( V_292 , V_12 -> V_96 -> V_92 -> V_298 ) ;
F_287 ( L_64 , V_292 ) ;
F_290 ( V_292 , V_12 -> V_91 -> V_92 -> V_298 ) ;
F_287 ( L_66 , V_292 ) ;
for ( V_201 = 0 ; V_201 < V_12 -> V_203 - 1 ; V_201 ++ )
F_287 ( L_67 , V_12 -> V_204 [ V_201 ] ) ;
if ( V_12 -> V_203 )
F_287 ( L_67 , V_12 -> V_204 [ V_12 -> V_203 - 1 ] ) ;
}
return;
V_109:
F_287 ( L_68 ) ;
}
static int F_291 ( struct V_12 * V_12 , const char * V_299 ,
struct V_300 * V_245 )
{
char V_301 ;
T_11 V_46 , V_142 ;
int V_29 ;
V_29 = sscanf ( V_299 , L_69 , & V_46 , & V_142 , & V_301 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_29 == 2 ) {
V_245 -> V_30 = F_169 ( V_46 ) ;
V_245 -> V_31 = F_169 ( V_142 ) ;
return 0 ;
}
V_29 = sscanf ( V_299 , L_70 , & V_46 , & V_301 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_29 == 1 ) {
V_245 -> V_30 = F_169 ( V_46 ) ;
V_245 -> V_31 = F_169 ( F_40 ( V_245 -> V_30 ) + 1u ) ;
return 0 ;
}
F_170 ( L_71 , V_299 ) ;
return - V_215 ;
}
static int F_292 ( struct V_12 * V_12 , struct V_300 * V_302 )
{
T_11 V_46 = F_40 ( V_302 -> V_30 ) ;
T_11 V_142 = F_40 ( V_302 -> V_31 ) ;
T_11 V_54 = F_40 ( V_12 -> V_239 ) ;
if ( V_46 >= V_54 ) {
F_170 ( L_72 , V_46 , V_54 ) ;
return - V_215 ;
}
if ( V_142 > V_54 ) {
F_170 ( L_73 , V_142 , V_54 ) ;
return - V_215 ;
}
if ( V_46 >= V_142 ) {
F_170 ( L_74 , V_46 , V_142 ) ;
return - V_215 ;
}
return 0 ;
}
static int F_293 ( struct V_12 * V_12 , struct V_300 * V_302 )
{
struct V_178 V_179 ;
F_132 ( & V_179 . V_124 ) ;
V_179 . V_180 = V_302 ;
F_67 ( & V_179 . V_182 , 0 ) ;
V_179 . V_109 = 0 ;
F_245 ( & V_179 . V_183 ) ;
F_172 ( & V_12 -> V_184 ) ;
F_294 ( & V_179 . V_124 , & V_12 -> V_185 ) ;
F_173 ( & V_12 -> V_184 ) ;
F_11 ( V_12 ) ;
F_177 ( V_179 . V_183 , F_69 ( & V_179 . V_182 ) ) ;
return V_179 . V_109 ;
}
static int F_295 ( struct V_12 * V_12 , unsigned V_136 ,
const char * * V_303 )
{
int V_29 = 0 ;
unsigned V_201 ;
struct V_300 V_302 ;
if ( ! F_73 ( & V_12 -> V_81 ) ) {
F_170 ( L_75 ) ;
return - V_304 ;
}
for ( V_201 = 0 ; V_201 < V_136 ; V_201 ++ ) {
V_29 = F_291 ( V_12 , V_303 [ V_201 ] , & V_302 ) ;
if ( V_29 )
break;
V_29 = F_292 ( V_12 , & V_302 ) ;
if ( V_29 )
break;
V_29 = F_293 ( V_12 , & V_302 ) ;
if ( V_29 )
break;
}
return V_29 ;
}
static int F_296 ( struct V_205 * V_51 , unsigned V_212 , char * * V_235 )
{
struct V_12 * V_12 = V_51 -> V_206 ;
if ( ! V_212 )
return - V_215 ;
if ( ! strcasecmp ( V_235 [ 0 ] , L_76 ) )
return F_295 ( V_12 , V_212 - 1 , ( const char * * ) V_235 + 1 ) ;
if ( V_212 != 2 )
return - V_215 ;
return F_226 ( V_12 , V_235 [ 0 ] , V_235 [ 1 ] ) ;
}
static int F_297 ( struct V_205 * V_51 ,
T_14 F_131 , void * V_305 )
{
int V_29 = 0 ;
struct V_12 * V_12 = V_51 -> V_206 ;
V_29 = F_131 ( V_51 , V_12 -> V_96 , 0 , F_207 ( V_12 -> V_96 ) , V_305 ) ;
if ( ! V_29 )
V_29 = F_131 ( V_51 , V_12 -> V_91 , 0 , V_51 -> V_222 , V_305 ) ;
return V_29 ;
}
static int F_298 ( struct V_205 * V_51 ,
struct V_306 * V_307 ,
struct V_308 * V_309 , int V_310 )
{
struct V_12 * V_12 = V_51 -> V_206 ;
struct V_195 * V_196 = F_193 ( V_12 -> V_91 -> V_92 ) ;
if ( ! V_196 -> V_311 )
return V_310 ;
V_307 -> V_90 = V_12 -> V_91 -> V_92 ;
return F_299 ( V_310 , V_196 -> V_311 ( V_196 , V_307 , V_309 ) ) ;
}
static void F_300 ( struct V_12 * V_12 , struct V_312 * V_313 )
{
V_313 -> V_314 = F_301 ( T_10 , V_12 -> V_56 * 1024 ,
V_12 -> V_221 ) ;
V_313 -> V_315 = V_12 -> V_56 << V_140 ;
}
static void F_302 ( struct V_205 * V_51 , struct V_312 * V_313 )
{
struct V_12 * V_12 = V_51 -> V_206 ;
T_11 V_316 = V_313 -> V_317 >> V_140 ;
if ( V_316 < V_12 -> V_57 ||
F_51 ( V_316 , V_12 -> V_57 ) ) {
F_303 ( V_313 , V_12 -> V_57 << V_140 ) ;
F_304 ( V_313 , V_12 -> V_57 << V_140 ) ;
}
F_300 ( V_12 , V_313 ) ;
}
static int T_15 F_305 ( void )
{
int V_29 ;
V_29 = F_306 ( & V_318 ) ;
if ( V_29 ) {
F_170 ( L_77 , V_29 ) ;
return V_29 ;
}
V_266 = F_307 ( V_19 , 0 ) ;
if ( ! V_266 ) {
F_308 ( & V_318 ) ;
return - V_26 ;
}
return 0 ;
}
static void T_16 F_309 ( void )
{
F_308 ( & V_318 ) ;
F_310 ( V_266 ) ;
}
