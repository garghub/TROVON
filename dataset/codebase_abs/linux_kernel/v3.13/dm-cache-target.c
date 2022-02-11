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
}
static void F_10 ( struct V_11 * V_11 )
{
F_11 ( V_11 -> V_12 , & V_11 -> V_13 ) ;
}
static struct V_14 * F_12 ( struct V_11 * V_11 )
{
return F_13 ( V_11 -> V_15 , V_16 ) ;
}
static void F_14 ( struct V_11 * V_11 , struct V_14 * V_17 )
{
F_15 ( V_11 -> V_15 , V_17 ) ;
}
static int F_16 ( struct V_11 * V_11 , struct V_18 * V_19 )
{
if ( ! V_19 -> V_20 ) {
V_19 -> V_20 = F_17 ( V_11 -> V_21 , V_16 ) ;
if ( ! V_19 -> V_20 )
return - V_22 ;
}
if ( ! V_19 -> V_23 ) {
V_19 -> V_23 = F_12 ( V_11 ) ;
if ( ! V_19 -> V_23 )
return - V_22 ;
}
if ( ! V_19 -> V_24 ) {
V_19 -> V_24 = F_12 ( V_11 ) ;
if ( ! V_19 -> V_24 )
return - V_22 ;
}
return 0 ;
}
static void F_18 ( struct V_11 * V_11 , struct V_18 * V_19 )
{
if ( V_19 -> V_24 )
F_14 ( V_11 , V_19 -> V_24 ) ;
if ( V_19 -> V_23 )
F_14 ( V_11 , V_19 -> V_23 ) ;
if ( V_19 -> V_20 )
F_19 ( V_19 -> V_20 , V_11 -> V_21 ) ;
}
static struct V_25 * F_20 ( struct V_18 * V_19 )
{
struct V_25 * V_20 = V_19 -> V_20 ;
F_21 ( ! V_20 ) ;
V_19 -> V_20 = NULL ;
return V_20 ;
}
static struct V_14 * F_22 ( struct V_18 * V_19 )
{
struct V_14 * V_26 = NULL ;
if ( V_19 -> V_23 ) {
V_26 = V_19 -> V_23 ;
V_19 -> V_23 = NULL ;
} else if ( V_19 -> V_24 ) {
V_26 = V_19 -> V_24 ;
V_19 -> V_24 = NULL ;
} else
F_23 () ;
return V_26 ;
}
static void F_24 ( struct V_18 * V_19 , struct V_14 * V_17 )
{
if ( ! V_19 -> V_24 )
V_19 -> V_24 = V_17 ;
else if ( ! V_19 -> V_23 )
V_19 -> V_23 = V_17 ;
else
F_23 () ;
}
static void F_25 ( T_3 V_27 , struct V_28 * V_29 )
{
V_29 -> V_30 = 0 ;
V_29 -> V_31 = 0 ;
V_29 -> V_32 = F_26 ( V_27 ) ;
}
static int F_27 ( struct V_11 * V_11 , T_3 V_27 ,
struct V_8 * V_8 , struct V_14 * V_33 ,
T_4 V_34 , void * V_35 ,
struct V_14 * * V_36 )
{
int V_26 ;
struct V_28 V_29 ;
F_25 ( V_27 , & V_29 ) ;
V_26 = F_28 ( V_11 -> V_15 , & V_29 , V_8 , V_33 , V_36 ) ;
if ( V_26 )
V_34 ( V_35 , V_33 ) ;
return V_26 ;
}
static int F_29 ( struct V_11 * V_11 ,
T_3 V_27 ,
struct V_18 * V_37 ,
struct V_14 * * V_36 )
{
int V_26 ;
struct V_28 V_29 ;
struct V_14 * V_33 ;
V_33 = F_22 ( V_37 ) ;
F_25 ( V_27 , & V_29 ) ;
V_26 = F_30 ( V_11 -> V_15 , & V_29 , V_33 , V_36 ) ;
if ( V_26 )
F_24 ( V_37 , V_33 ) ;
return V_26 ;
}
static bool F_31 ( struct V_11 * V_11 , T_5 V_38 )
{
return F_32 ( F_33 ( V_38 ) , V_11 -> V_39 ) ;
}
static void F_34 ( struct V_11 * V_11 , T_3 V_27 , T_5 V_40 )
{
if ( ! F_35 ( F_33 ( V_40 ) , V_11 -> V_39 ) ) {
V_11 -> V_41 = F_36 ( F_33 ( V_11 -> V_41 ) + 1 ) ;
F_37 ( V_11 -> V_42 , V_27 ) ;
}
}
static void F_38 ( struct V_11 * V_11 , T_3 V_27 , T_5 V_40 )
{
if ( F_39 ( F_33 ( V_40 ) , V_11 -> V_39 ) ) {
F_40 ( V_11 -> V_42 , V_27 ) ;
V_11 -> V_41 = F_36 ( F_33 ( V_11 -> V_41 ) - 1 ) ;
if ( ! F_33 ( V_11 -> V_41 ) )
F_41 ( V_11 -> V_43 -> V_44 ) ;
}
}
static bool F_42 ( struct V_11 * V_11 )
{
return V_11 -> V_45 >= 0 ;
}
T_6
#endif
static T_7 F_43 ( T_7 V_38 , T_8 V_46 )
{
F_44 ( V_38 , V_46 ) ;
return V_38 ;
}
static T_9 F_45 ( struct V_11 * V_11 , T_3 V_27 )
{
T_8 V_47 = V_11 -> V_48 ;
T_7 V_38 = F_26 ( V_27 ) ;
if ( ! F_42 ( V_11 ) )
V_47 = V_47 / V_11 -> V_49 ;
else
V_47 >>= V_11 -> V_45 ;
V_38 = F_43 ( V_38 , V_47 ) ;
return F_46 ( V_38 ) ;
}
static void F_47 ( struct V_11 * V_11 , T_9 V_38 )
{
unsigned long V_50 ;
F_48 ( & V_11 -> V_51 . V_52 ) ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_50 ( F_51 ( V_38 ) , V_11 -> V_54 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
}
static void F_53 ( struct V_11 * V_11 , T_9 V_38 )
{
unsigned long V_50 ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_54 ( F_51 ( V_38 ) , V_11 -> V_54 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
}
static bool F_55 ( struct V_11 * V_11 , T_9 V_38 )
{
int V_26 ;
unsigned long V_50 ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
V_26 = F_32 ( F_51 ( V_38 ) , V_11 -> V_54 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
return V_26 ;
}
static bool F_56 ( struct V_11 * V_11 , T_3 V_38 )
{
int V_26 ;
unsigned long V_50 ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
V_26 = F_32 ( F_51 ( F_45 ( V_11 , V_38 ) ) ,
V_11 -> V_54 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
return V_26 ;
}
static void F_57 ( struct V_11 * V_11 )
{
struct V_55 V_51 ;
F_58 ( V_11 -> V_56 , & V_51 ) ;
F_59 ( & V_11 -> V_51 . V_57 , V_51 . V_58 ) ;
F_59 ( & V_11 -> V_51 . V_59 , V_51 . V_60 ) ;
F_59 ( & V_11 -> V_51 . V_61 , V_51 . V_62 ) ;
F_59 ( & V_11 -> V_51 . V_63 , V_51 . V_64 ) ;
}
static void F_60 ( struct V_11 * V_11 )
{
struct V_55 V_51 ;
V_51 . V_58 = F_61 ( & V_11 -> V_51 . V_57 ) ;
V_51 . V_60 = F_61 ( & V_11 -> V_51 . V_59 ) ;
V_51 . V_62 = F_61 ( & V_11 -> V_51 . V_61 ) ;
V_51 . V_64 = F_61 ( & V_11 -> V_51 . V_63 ) ;
F_62 ( V_11 -> V_56 , & V_51 ) ;
}
static bool F_63 ( struct V_65 * V_66 )
{
return V_66 -> V_67 == V_68 ;
}
static bool F_64 ( struct V_65 * V_66 )
{
return V_66 -> V_67 == V_69 ;
}
static bool F_65 ( struct V_65 * V_66 )
{
return V_66 -> V_67 == V_70 ;
}
static T_1 F_66 ( struct V_11 * V_11 )
{
return F_63 ( & V_11 -> V_71 ) ? V_72 : V_73 ;
}
static struct V_74 * F_67 ( struct V_8 * V_8 , T_1 V_75 )
{
struct V_74 * V_76 = F_68 ( V_8 , V_75 ) ;
F_21 ( ! V_76 ) ;
return V_76 ;
}
static struct V_74 * F_69 ( struct V_8 * V_8 , T_1 V_75 )
{
struct V_74 * V_76 = F_67 ( V_8 , V_75 ) ;
V_76 -> V_77 = false ;
V_76 -> V_78 = F_70 ( V_8 ) ;
V_76 -> V_79 = NULL ;
return V_76 ;
}
static void F_71 ( struct V_11 * V_11 , struct V_8 * V_8 )
{
V_8 -> V_80 = V_11 -> V_81 -> V_82 ;
}
static void F_72 ( struct V_11 * V_11 , struct V_8 * V_8 ,
T_5 V_40 )
{
T_10 V_83 = V_8 -> V_83 ;
V_8 -> V_80 = V_11 -> V_84 -> V_82 ;
if ( ! F_42 ( V_11 ) )
V_8 -> V_83 = ( F_33 ( V_40 ) * V_11 -> V_49 ) +
F_73 ( V_83 , V_11 -> V_49 ) ;
else
V_8 -> V_83 = ( F_33 ( V_40 ) << V_11 -> V_45 ) |
( V_83 & ( V_11 -> V_49 - 1 ) ) ;
}
static void F_74 ( struct V_11 * V_11 , struct V_8 * V_8 )
{
unsigned long V_50 ;
T_1 V_85 = F_66 ( V_11 ) ;
struct V_74 * V_76 = F_67 ( V_8 , V_85 ) ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
if ( V_11 -> V_86 &&
! ( V_8 -> V_87 & ( V_88 | V_89 | V_90 ) ) ) {
V_76 -> V_77 = true ;
V_11 -> V_86 = false ;
}
F_52 ( & V_11 -> V_53 , V_50 ) ;
}
static void F_75 ( struct V_11 * V_11 , struct V_8 * V_8 ,
T_3 V_27 )
{
F_74 ( V_11 , V_8 ) ;
F_71 ( V_11 , V_8 ) ;
if ( F_76 ( V_8 ) == V_91 )
F_53 ( V_11 , F_45 ( V_11 , V_27 ) ) ;
}
static void F_77 ( struct V_11 * V_11 , struct V_8 * V_8 ,
T_3 V_27 , T_5 V_40 )
{
F_74 ( V_11 , V_8 ) ;
F_72 ( V_11 , V_8 , V_40 ) ;
if ( F_76 ( V_8 ) == V_91 ) {
F_34 ( V_11 , V_27 , V_40 ) ;
F_53 ( V_11 , F_45 ( V_11 , V_27 ) ) ;
}
}
static T_3 F_78 ( struct V_11 * V_11 , struct V_8 * V_8 )
{
T_10 V_92 = V_8 -> V_83 ;
if ( ! F_42 ( V_11 ) )
( void ) F_73 ( V_92 , V_11 -> V_49 ) ;
else
V_92 >>= V_11 -> V_45 ;
return F_79 ( V_92 ) ;
}
static int F_80 ( struct V_11 * V_11 , struct V_8 * V_8 )
{
return V_8 -> V_87 & ( V_89 | V_88 ) ;
}
static void F_81 ( struct V_11 * V_11 , struct V_8 * V_8 )
{
unsigned long V_50 ;
if ( ! F_80 ( V_11 , V_8 ) ) {
F_82 ( V_8 ) ;
return;
}
F_49 ( & V_11 -> V_53 , V_50 ) ;
V_11 -> V_93 = true ;
F_83 ( & V_11 -> V_94 , V_8 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
}
static void F_84 ( struct V_11 * V_11 , struct V_8 * V_8 )
{
unsigned long V_50 ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_83 ( & V_11 -> V_95 , V_8 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
F_10 ( V_11 ) ;
}
static void F_85 ( struct V_8 * V_8 , int V_96 )
{
struct V_74 * V_76 = F_67 ( V_8 , V_72 ) ;
F_9 ( & V_76 -> V_97 , V_8 ) ;
if ( V_96 ) {
F_86 ( V_8 , V_96 ) ;
return;
}
F_87 ( & V_76 -> V_98 , V_8 ) ;
F_72 ( V_76 -> V_11 , V_8 , V_76 -> V_40 ) ;
F_84 ( V_76 -> V_11 , V_8 ) ;
}
static void F_88 ( struct V_11 * V_11 , struct V_8 * V_8 ,
T_3 V_27 , T_5 V_40 )
{
struct V_74 * V_76 = F_67 ( V_8 , V_72 ) ;
V_76 -> V_11 = V_11 ;
V_76 -> V_40 = V_40 ;
F_8 ( & V_76 -> V_97 , V_8 , F_85 , NULL ) ;
F_89 ( & V_76 -> V_98 , V_8 ) ;
F_75 ( V_76 -> V_11 , V_8 , V_27 ) ;
}
static void F_90 ( struct V_25 * V_20 )
{
F_19 ( V_20 , V_20 -> V_11 -> V_21 ) ;
}
static void F_91 ( struct V_11 * V_11 )
{
F_48 ( & V_11 -> V_99 ) ;
}
static void F_92 ( struct V_11 * V_11 )
{
F_93 ( & V_11 -> V_99 ) ;
F_94 ( & V_11 -> V_100 ) ;
}
static void F_95 ( struct V_11 * V_11 , struct V_14 * V_17 ,
bool V_101 )
{
( V_101 ? V_102 : V_103 )
( V_11 -> V_15 , V_17 , & V_11 -> V_104 ) ;
F_14 ( V_11 , V_17 ) ;
}
static void F_96 ( struct V_11 * V_11 , struct V_14 * V_17 ,
bool V_101 )
{
unsigned long V_50 ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_95 ( V_11 , V_17 , V_101 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
F_10 ( V_11 ) ;
}
static void F_97 ( struct V_25 * V_20 )
{
struct V_11 * V_11 = V_20 -> V_11 ;
F_90 ( V_20 ) ;
F_92 ( V_11 ) ;
}
static void F_98 ( struct V_25 * V_20 )
{
struct V_11 * V_11 = V_20 -> V_11 ;
if ( V_20 -> V_105 ) {
F_99 ( L_1 ) ;
F_34 ( V_11 , V_20 -> V_106 , V_20 -> V_40 ) ;
F_96 ( V_11 , V_20 -> V_107 , false ) ;
} else if ( V_20 -> V_108 ) {
F_99 ( L_2 ) ;
F_100 ( V_11 -> V_42 , V_20 -> V_109 , V_20 -> V_106 ) ;
F_96 ( V_11 , V_20 -> V_107 , V_20 -> V_110 ? false : true ) ;
if ( V_20 -> V_110 )
F_96 ( V_11 , V_20 -> V_111 , true ) ;
} else {
F_99 ( L_3 ) ;
F_101 ( V_11 -> V_42 , V_20 -> V_109 ) ;
F_96 ( V_11 , V_20 -> V_111 , true ) ;
}
F_97 ( V_20 ) ;
}
static void F_102 ( struct V_25 * V_20 )
{
unsigned long V_50 ;
struct V_11 * V_11 = V_20 -> V_11 ;
if ( V_20 -> V_105 ) {
F_96 ( V_11 , V_20 -> V_107 , false ) ;
F_38 ( V_11 , V_20 -> V_106 , V_20 -> V_40 ) ;
F_97 ( V_20 ) ;
return;
} else if ( V_20 -> V_108 ) {
if ( F_103 ( V_11 -> V_56 , V_20 -> V_40 ) ) {
F_99 ( L_4 ) ;
F_100 ( V_11 -> V_42 , V_20 -> V_109 ,
V_20 -> V_106 ) ;
if ( V_20 -> V_110 )
F_96 ( V_11 , V_20 -> V_111 , true ) ;
F_97 ( V_20 ) ;
return;
}
} else {
if ( F_104 ( V_11 -> V_56 , V_20 -> V_40 , V_20 -> V_109 ) ) {
F_99 ( L_5 ) ;
F_101 ( V_11 -> V_42 , V_20 -> V_109 ) ;
F_97 ( V_20 ) ;
return;
}
}
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_105 ( & V_20 -> V_112 , & V_11 -> V_113 ) ;
V_11 -> V_93 = true ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
}
static void F_106 ( struct V_25 * V_20 )
{
unsigned long V_50 ;
struct V_11 * V_11 = V_20 -> V_11 ;
if ( V_20 -> V_105 ) {
F_107 ( L_6 ) ;
return;
} else if ( V_20 -> V_108 ) {
F_96 ( V_11 , V_20 -> V_107 , V_20 -> V_110 ? false : true ) ;
if ( V_20 -> V_110 ) {
V_20 -> V_108 = false ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_105 ( & V_20 -> V_112 , & V_11 -> V_114 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
} else {
if ( V_20 -> V_115 )
F_101 ( V_11 -> V_42 , V_20 -> V_106 ) ;
F_97 ( V_20 ) ;
}
} else {
if ( V_20 -> V_116 )
F_96 ( V_11 , V_20 -> V_111 , true ) ;
else {
F_86 ( V_20 -> V_111 -> V_101 , 0 ) ;
F_96 ( V_11 , V_20 -> V_111 , false ) ;
}
F_38 ( V_11 , V_20 -> V_109 , V_20 -> V_40 ) ;
F_97 ( V_20 ) ;
}
}
static void F_108 ( int V_117 , unsigned long V_118 , void * V_119 )
{
unsigned long V_50 ;
struct V_25 * V_20 = (struct V_25 * ) V_119 ;
struct V_11 * V_11 = V_20 -> V_11 ;
if ( V_117 || V_118 )
V_20 -> V_96 = true ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_105 ( & V_20 -> V_112 , & V_11 -> V_120 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
F_10 ( V_11 ) ;
}
static void F_109 ( struct V_25 * V_20 )
{
int V_26 ;
struct V_121 V_122 , V_123 ;
struct V_11 * V_11 = V_20 -> V_11 ;
V_122 . V_82 = V_11 -> V_81 -> V_82 ;
V_122 . V_124 = V_11 -> V_49 ;
V_123 . V_82 = V_11 -> V_84 -> V_82 ;
V_123 . V_125 = F_33 ( V_20 -> V_40 ) * V_11 -> V_49 ;
V_123 . V_124 = V_11 -> V_49 ;
if ( V_20 -> V_105 || V_20 -> V_108 ) {
V_122 . V_125 = F_26 ( V_20 -> V_106 ) * V_11 -> V_49 ;
V_26 = F_110 ( V_11 -> V_126 , & V_123 , 1 , & V_122 , 0 , F_108 , V_20 ) ;
} else {
V_122 . V_125 = F_26 ( V_20 -> V_109 ) * V_11 -> V_49 ;
V_26 = F_110 ( V_11 -> V_126 , & V_122 , 1 , & V_123 , 0 , F_108 , V_20 ) ;
}
if ( V_26 < 0 ) {
F_111 ( L_7 ) ;
F_98 ( V_20 ) ;
}
}
static void F_112 ( struct V_8 * V_8 , int V_96 )
{
struct V_25 * V_20 = V_8 -> V_10 ;
struct V_11 * V_11 = V_20 -> V_11 ;
T_1 V_85 = F_66 ( V_11 ) ;
struct V_74 * V_76 = F_67 ( V_8 , V_85 ) ;
unsigned long V_50 ;
if ( V_96 )
V_20 -> V_96 = true ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_105 ( & V_20 -> V_112 , & V_11 -> V_120 ) ;
F_9 ( & V_76 -> V_97 , V_8 ) ;
V_20 -> V_116 = false ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
F_10 ( V_11 ) ;
}
static void F_113 ( struct V_25 * V_20 , struct V_8 * V_8 )
{
T_1 V_85 = F_66 ( V_20 -> V_11 ) ;
struct V_74 * V_76 = F_67 ( V_8 , V_85 ) ;
F_8 ( & V_76 -> V_97 , V_8 , F_112 , V_20 ) ;
F_77 ( V_20 -> V_11 , V_8 , V_20 -> V_109 , V_20 -> V_40 ) ;
F_82 ( V_8 ) ;
}
static bool F_114 ( struct V_11 * V_11 , struct V_8 * V_8 )
{
return ( F_76 ( V_8 ) == V_91 ) &&
( V_8 -> V_127 == ( V_11 -> V_49 << V_128 ) ) ;
}
static void F_115 ( struct V_25 * V_20 )
{
F_48 ( & V_20 -> V_11 -> V_51 . V_129 ) ;
F_102 ( V_20 ) ;
}
static void F_116 ( struct V_25 * V_20 )
{
bool V_130 ;
struct V_11 * V_11 = V_20 -> V_11 ;
if ( V_20 -> V_105 || V_20 -> V_108 )
V_130 = ! F_31 ( V_11 , V_20 -> V_40 ) ||
F_56 ( V_11 , V_20 -> V_106 ) ;
else {
struct V_8 * V_8 = V_20 -> V_111 -> V_101 ;
V_130 = F_56 ( V_11 , V_20 -> V_109 ) ;
if ( ! V_130 && F_114 ( V_11 , V_8 ) ) {
F_113 ( V_20 , V_8 ) ;
return;
}
}
V_130 ? F_115 ( V_20 ) : F_109 ( V_20 ) ;
}
static void F_117 ( struct V_25 * V_20 )
{
if ( V_20 -> V_96 )
F_98 ( V_20 ) ;
else
F_102 ( V_20 ) ;
}
static void F_118 ( struct V_11 * V_11 , struct V_131 * V_132 ,
void (* F_119)( struct V_25 * ) )
{
unsigned long V_50 ;
struct V_131 V_112 ;
struct V_25 * V_20 , * V_133 ;
F_120 ( & V_112 ) ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_121 ( V_132 , & V_112 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
F_122 (mg, tmp, &list, list)
F_119 ( V_20 ) ;
}
static void F_123 ( struct V_25 * V_20 )
{
F_105 ( & V_20 -> V_112 , & V_20 -> V_11 -> V_114 ) ;
}
static void F_124 ( struct V_25 * V_20 )
{
unsigned long V_50 ;
struct V_11 * V_11 = V_20 -> V_11 ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_123 ( V_20 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
F_10 ( V_11 ) ;
}
static void F_125 ( struct V_11 * V_11 , struct V_131 * V_134 )
{
unsigned long V_50 ;
struct V_25 * V_20 , * V_133 ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_122 (mg, tmp, work, list)
F_123 ( V_20 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
F_10 ( V_11 ) ;
}
static void F_126 ( struct V_11 * V_11 ,
struct V_74 * V_76 )
{
struct V_131 V_134 ;
if ( ! V_76 -> V_79 )
return;
F_120 ( & V_134 ) ;
if ( V_76 -> V_79 )
F_127 ( V_76 -> V_79 , & V_134 ) ;
if ( ! F_128 ( & V_134 ) )
F_125 ( V_11 , & V_134 ) ;
}
static void F_129 ( struct V_25 * V_20 )
{
if ( ! F_130 ( V_20 -> V_11 -> V_135 , & V_20 -> V_112 ) )
F_124 ( V_20 ) ;
}
static void V_110 ( struct V_11 * V_11 , struct V_18 * V_37 ,
T_3 V_27 , T_5 V_40 ,
struct V_14 * V_17 )
{
struct V_25 * V_20 = F_20 ( V_37 ) ;
V_20 -> V_96 = false ;
V_20 -> V_105 = false ;
V_20 -> V_108 = false ;
V_20 -> V_110 = true ;
V_20 -> V_116 = true ;
V_20 -> V_115 = false ;
V_20 -> V_11 = V_11 ;
V_20 -> V_109 = V_27 ;
V_20 -> V_40 = V_40 ;
V_20 -> V_107 = NULL ;
V_20 -> V_111 = V_17 ;
V_20 -> V_136 = V_137 ;
F_91 ( V_11 ) ;
F_129 ( V_20 ) ;
}
static void V_105 ( struct V_11 * V_11 , struct V_18 * V_37 ,
T_3 V_27 , T_5 V_40 ,
struct V_14 * V_17 )
{
struct V_25 * V_20 = F_20 ( V_37 ) ;
V_20 -> V_96 = false ;
V_20 -> V_105 = true ;
V_20 -> V_108 = false ;
V_20 -> V_110 = false ;
V_20 -> V_116 = true ;
V_20 -> V_115 = false ;
V_20 -> V_11 = V_11 ;
V_20 -> V_106 = V_27 ;
V_20 -> V_40 = V_40 ;
V_20 -> V_107 = V_17 ;
V_20 -> V_111 = NULL ;
V_20 -> V_136 = V_137 ;
F_91 ( V_11 ) ;
F_129 ( V_20 ) ;
}
static void F_131 ( struct V_11 * V_11 , struct V_18 * V_37 ,
T_3 V_106 , T_3 V_109 ,
T_5 V_40 ,
struct V_14 * V_107 ,
struct V_14 * V_111 )
{
struct V_25 * V_20 = F_20 ( V_37 ) ;
V_20 -> V_96 = false ;
V_20 -> V_105 = false ;
V_20 -> V_108 = true ;
V_20 -> V_110 = true ;
V_20 -> V_116 = true ;
V_20 -> V_115 = false ;
V_20 -> V_11 = V_11 ;
V_20 -> V_106 = V_106 ;
V_20 -> V_109 = V_109 ;
V_20 -> V_40 = V_40 ;
V_20 -> V_107 = V_107 ;
V_20 -> V_111 = V_111 ;
V_20 -> V_136 = V_137 ;
F_91 ( V_11 ) ;
F_129 ( V_20 ) ;
}
static void V_115 ( struct V_11 * V_11 , struct V_18 * V_37 ,
T_3 V_27 , T_5 V_40 ,
struct V_14 * V_17 )
{
struct V_25 * V_20 = F_20 ( V_37 ) ;
V_20 -> V_96 = false ;
V_20 -> V_105 = false ;
V_20 -> V_108 = true ;
V_20 -> V_110 = false ;
V_20 -> V_116 = true ;
V_20 -> V_115 = true ;
V_20 -> V_11 = V_11 ;
V_20 -> V_106 = V_27 ;
V_20 -> V_40 = V_40 ;
V_20 -> V_107 = V_17 ;
V_20 -> V_111 = NULL ;
V_20 -> V_136 = V_137 ;
F_91 ( V_11 ) ;
F_129 ( V_20 ) ;
}
static void F_132 ( struct V_11 * V_11 , struct V_8 * V_8 )
{
unsigned long V_50 ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_83 ( & V_11 -> V_104 , V_8 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
F_10 ( V_11 ) ;
}
static void F_133 ( struct V_11 * V_11 , struct V_8 * V_8 )
{
T_1 V_85 = F_66 ( V_11 ) ;
struct V_74 * V_76 = F_67 ( V_8 , V_85 ) ;
F_21 ( V_8 -> V_127 ) ;
if ( ! V_76 -> V_78 )
F_71 ( V_11 , V_8 ) ;
else
F_72 ( V_11 , V_8 , 0 ) ;
F_81 ( V_11 , V_8 ) ;
}
static void F_134 ( struct V_11 * V_11 , struct V_8 * V_8 )
{
T_7 V_138 = F_135 ( V_8 -> V_83 ,
V_11 -> V_48 ) ;
T_7 V_139 = V_8 -> V_83 + F_136 ( V_8 ) ;
T_7 V_38 ;
V_139 = F_43 ( V_139 , V_11 -> V_48 ) ;
for ( V_38 = V_138 ; V_38 < V_139 ; V_38 ++ )
F_47 ( V_11 , F_46 ( V_38 ) ) ;
F_86 ( V_8 , 0 ) ;
}
static bool F_137 ( struct V_11 * V_11 )
{
T_10 V_140 = ( F_61 ( & V_11 -> V_99 ) + 1 ) *
V_11 -> V_49 ;
return V_140 < V_11 -> V_141 ;
}
static void F_138 ( struct V_11 * V_11 , struct V_8 * V_8 )
{
F_48 ( F_76 ( V_8 ) == V_142 ?
& V_11 -> V_51 . V_57 : & V_11 -> V_51 . V_61 ) ;
}
static void F_139 ( struct V_11 * V_11 , struct V_8 * V_8 )
{
F_48 ( F_76 ( V_8 ) == V_142 ?
& V_11 -> V_51 . V_59 : & V_11 -> V_51 . V_63 ) ;
}
static void F_140 ( struct V_11 * V_11 , struct V_8 * V_8 ,
struct V_74 * V_76 ,
T_3 V_27 , T_5 V_40 )
{
V_76 -> V_79 = F_141 ( V_11 -> V_135 ) ;
F_77 ( V_11 , V_8 , V_27 , V_40 ) ;
F_81 ( V_11 , V_8 ) ;
}
static void F_142 ( struct V_11 * V_11 , struct V_18 * V_37 ,
struct V_8 * V_8 )
{
int V_26 ;
bool V_143 = true ;
T_3 V_32 = F_78 ( V_11 , V_8 ) ;
struct V_14 * V_33 , * V_107 , * V_111 ;
struct V_144 V_145 ;
T_1 V_85 = F_66 ( V_11 ) ;
struct V_74 * V_76 = F_67 ( V_8 , V_85 ) ;
bool V_146 = F_56 ( V_11 , V_32 ) ;
bool V_147 = F_65 ( & V_11 -> V_71 ) ;
bool V_148 = ! V_147 && ( V_146 || F_137 ( V_11 ) ) ;
V_33 = F_22 ( V_37 ) ;
V_26 = F_27 ( V_11 , V_32 , V_8 , V_33 ,
( T_4 ) F_24 ,
V_37 , & V_111 ) ;
if ( V_26 > 0 )
return;
V_26 = F_143 ( V_11 -> V_42 , V_32 , true , V_148 , V_146 ,
V_8 , & V_145 ) ;
if ( V_26 == - V_149 )
V_145 . V_150 = V_151 ;
switch ( V_145 . V_150 ) {
case V_152 :
if ( V_147 ) {
F_139 ( V_11 , V_8 ) ;
if ( F_76 ( V_8 ) == V_91 ) {
F_48 ( & V_11 -> V_51 . V_153 ) ;
V_115 ( V_11 , V_37 , V_32 , V_145 . V_40 , V_111 ) ;
V_143 = false ;
} else {
V_76 -> V_79 = F_141 ( V_11 -> V_135 ) ;
F_75 ( V_11 , V_8 , V_32 ) ;
F_81 ( V_11 , V_8 ) ;
}
} else {
F_138 ( V_11 , V_8 ) ;
if ( F_76 ( V_8 ) == V_91 &&
F_63 ( & V_11 -> V_71 ) &&
! F_31 ( V_11 , V_145 . V_40 ) ) {
V_76 -> V_79 = F_141 ( V_11 -> V_135 ) ;
F_88 ( V_11 , V_8 , V_32 , V_145 . V_40 ) ;
F_81 ( V_11 , V_8 ) ;
} else
F_140 ( V_11 , V_8 , V_76 , V_32 , V_145 . V_40 ) ;
}
break;
case V_151 :
F_139 ( V_11 , V_8 ) ;
V_76 -> V_79 = F_141 ( V_11 -> V_135 ) ;
F_75 ( V_11 , V_8 , V_32 ) ;
F_81 ( V_11 , V_8 ) ;
break;
case V_154 :
F_48 ( & V_11 -> V_51 . V_155 ) ;
V_110 ( V_11 , V_37 , V_32 , V_145 . V_40 , V_111 ) ;
V_143 = false ;
break;
case V_156 :
V_33 = F_22 ( V_37 ) ;
V_26 = F_27 ( V_11 , V_145 . V_106 , V_8 , V_33 ,
( T_4 ) F_24 ,
V_37 , & V_107 ) ;
if ( V_26 > 0 ) {
F_100 ( V_11 -> V_42 , V_32 ,
V_145 . V_106 ) ;
F_48 ( & V_11 -> V_51 . V_157 ) ;
break;
}
F_48 ( & V_11 -> V_51 . V_153 ) ;
F_48 ( & V_11 -> V_51 . V_155 ) ;
F_131 ( V_11 , V_37 , V_145 . V_106 ,
V_32 , V_145 . V_40 ,
V_107 , V_111 ) ;
V_143 = false ;
break;
default:
F_111 ( L_8 , V_158 ,
( unsigned ) V_145 . V_150 ) ;
F_144 ( V_8 ) ;
}
if ( V_143 )
F_96 ( V_11 , V_111 , false ) ;
}
static int F_145 ( struct V_11 * V_11 )
{
return V_137 < V_11 -> V_159 ||
V_137 > V_11 -> V_159 + V_160 ;
}
static int F_146 ( struct V_11 * V_11 )
{
int V_26 = 0 ;
if ( ( V_11 -> V_93 || F_145 ( V_11 ) ) &&
F_147 ( V_11 -> V_56 ) ) {
F_48 ( & V_11 -> V_51 . V_161 ) ;
V_11 -> V_93 = false ;
V_26 = F_148 ( V_11 -> V_56 , false ) ;
V_11 -> V_159 = V_137 ;
}
return V_26 ;
}
static void F_149 ( struct V_11 * V_11 )
{
unsigned long V_50 ;
struct V_162 V_163 ;
struct V_8 * V_8 ;
struct V_18 V_37 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
F_150 ( & V_163 ) ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_151 ( & V_163 , & V_11 -> V_104 ) ;
F_150 ( & V_11 -> V_104 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
while ( ! F_152 ( & V_163 ) ) {
if ( F_16 ( V_11 , & V_37 ) ) {
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_151 ( & V_11 -> V_104 , & V_163 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
break;
}
V_8 = F_153 ( & V_163 ) ;
if ( V_8 -> V_87 & V_89 )
F_133 ( V_11 , V_8 ) ;
else if ( V_8 -> V_87 & V_90 )
F_134 ( V_11 , V_8 ) ;
else
F_142 ( V_11 , & V_37 , V_8 ) ;
}
F_18 ( V_11 , & V_37 ) ;
}
static void F_154 ( struct V_11 * V_11 , bool V_164 )
{
unsigned long V_50 ;
struct V_162 V_163 ;
struct V_8 * V_8 ;
F_150 ( & V_163 ) ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_151 ( & V_163 , & V_11 -> V_94 ) ;
F_150 ( & V_11 -> V_94 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
while ( ( V_8 = F_153 ( & V_163 ) ) )
V_164 ? F_82 ( V_8 ) : F_144 ( V_8 ) ;
}
static void F_155 ( struct V_11 * V_11 )
{
unsigned long V_50 ;
struct V_162 V_163 ;
struct V_8 * V_8 ;
F_150 ( & V_163 ) ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
F_151 ( & V_163 , & V_11 -> V_95 ) ;
F_150 ( & V_11 -> V_95 ) ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
while ( ( V_8 = F_153 ( & V_163 ) ) )
F_82 ( V_8 ) ;
}
static void F_156 ( struct V_11 * V_11 )
{
int V_26 = 0 ;
T_3 V_27 ;
T_5 V_40 ;
struct V_18 V_37 ;
struct V_14 * V_107 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
while ( F_137 ( V_11 ) ) {
if ( F_16 ( V_11 , & V_37 ) )
break;
V_26 = F_157 ( V_11 -> V_42 , & V_27 , & V_40 ) ;
if ( V_26 )
break;
V_26 = F_29 ( V_11 , V_27 , & V_37 , & V_107 ) ;
if ( V_26 ) {
F_37 ( V_11 -> V_42 , V_27 ) ;
break;
}
V_105 ( V_11 , & V_37 , V_27 , V_40 , V_107 ) ;
}
F_18 ( V_11 , & V_37 ) ;
}
static void F_158 ( struct V_11 * V_11 , struct V_165 * V_166 )
{
int V_26 = 0 ;
T_11 V_167 = F_33 ( V_166 -> V_168 -> V_167 ) ;
T_11 V_169 = F_33 ( V_166 -> V_168 -> V_169 ) ;
while ( V_167 != V_169 ) {
V_26 = F_159 ( V_11 -> V_42 , F_36 ( V_167 ) ) ;
if ( ! V_26 ) {
V_26 = F_103 ( V_11 -> V_56 , F_36 ( V_167 ) ) ;
if ( V_26 )
break;
} else if ( V_26 == - V_170 ) {
V_26 = 0 ;
} else {
F_160 ( L_9 ) ;
break;
}
V_167 ++ ;
}
V_11 -> V_93 = true ;
V_166 -> V_96 = V_26 ;
F_59 ( & V_166 -> V_171 , 1 ) ;
F_94 ( & V_166 -> V_172 ) ;
}
static void F_161 ( struct V_11 * V_11 )
{
struct V_131 V_112 ;
struct V_165 * V_166 , * V_133 ;
F_120 ( & V_112 ) ;
F_162 ( & V_11 -> V_173 ) ;
F_121 ( & V_11 -> V_174 , & V_112 ) ;
F_163 ( & V_11 -> V_173 ) ;
F_122 (req, tmp, &list, list)
F_158 ( V_11 , V_166 ) ;
}
static bool F_164 ( struct V_11 * V_11 )
{
return F_61 ( & V_11 -> V_175 ) ;
}
static void F_165 ( struct V_11 * V_11 )
{
if ( F_164 ( V_11 ) ) {
F_48 ( & V_11 -> V_176 ) ;
F_94 ( & V_11 -> V_177 ) ;
}
}
static void F_166 ( struct V_11 * V_11 )
{
F_167 ( V_11 -> V_177 , F_61 ( & V_11 -> V_176 ) ) ;
}
static void F_168 ( struct V_11 * V_11 )
{
F_48 ( & V_11 -> V_175 ) ;
F_166 ( V_11 ) ;
}
static void F_169 ( struct V_11 * V_11 )
{
F_59 ( & V_11 -> V_175 , 0 ) ;
F_59 ( & V_11 -> V_176 , 0 ) ;
}
static void F_170 ( struct V_11 * V_11 )
{
F_167 ( V_11 -> V_100 , ! F_61 ( & V_11 -> V_99 ) ) ;
}
static void F_171 ( struct V_11 * V_11 )
{
F_172 ( & V_11 -> V_178 ) ;
F_173 ( V_11 -> V_12 ) ;
}
static void F_174 ( struct V_11 * V_11 )
{
struct V_8 * V_8 ;
struct V_162 V_163 ;
F_150 ( & V_163 ) ;
F_151 ( & V_163 , & V_11 -> V_104 ) ;
F_150 ( & V_11 -> V_104 ) ;
while ( ( V_8 = F_153 ( & V_163 ) ) )
F_86 ( V_8 , V_179 ) ;
}
static int F_175 ( struct V_11 * V_11 )
{
if ( F_164 ( V_11 ) )
return ! F_128 ( & V_11 -> V_114 ) ||
! F_128 ( & V_11 -> V_120 ) ||
! F_128 ( & V_11 -> V_113 ) ;
else
return ! F_152 ( & V_11 -> V_104 ) ||
! F_152 ( & V_11 -> V_94 ) ||
! F_152 ( & V_11 -> V_95 ) ||
! F_128 ( & V_11 -> V_114 ) ||
! F_128 ( & V_11 -> V_120 ) ||
! F_128 ( & V_11 -> V_113 ) ||
V_11 -> V_115 ;
}
static void F_176 ( struct V_180 * V_181 )
{
struct V_11 * V_11 = F_177 ( V_181 , struct V_11 , V_13 ) ;
do {
if ( ! F_164 ( V_11 ) ) {
F_156 ( V_11 ) ;
F_155 ( V_11 ) ;
F_149 ( V_11 ) ;
F_161 ( V_11 ) ;
}
F_118 ( V_11 , & V_11 -> V_114 , F_116 ) ;
F_118 ( V_11 , & V_11 -> V_120 , F_117 ) ;
if ( F_146 ( V_11 ) ) {
F_154 ( V_11 , false ) ;
} else {
F_154 ( V_11 , true ) ;
F_118 ( V_11 , & V_11 -> V_113 ,
F_106 ) ;
}
F_165 ( V_11 ) ;
} while ( F_175 ( V_11 ) );
}
static void F_178 ( struct V_180 * V_181 )
{
struct V_11 * V_11 = F_177 ( F_179 ( V_181 ) , struct V_11 , V_178 ) ;
F_180 ( V_11 -> V_42 ) ;
F_10 ( V_11 ) ;
F_181 ( V_11 -> V_12 , & V_11 -> V_178 , V_160 ) ;
}
static int F_182 ( struct V_182 * V_31 , int V_183 )
{
struct V_184 * V_185 = F_183 ( V_31 -> V_82 ) ;
return F_184 ( & V_185 -> V_186 , V_183 ) ;
}
static int F_185 ( struct V_187 * V_188 , int V_183 )
{
struct V_11 * V_11 = F_177 ( V_188 , struct V_11 , V_189 ) ;
return F_182 ( V_11 -> V_81 , V_183 ) ||
F_182 ( V_11 -> V_84 , V_183 ) ;
}
static void F_186 ( struct V_11 * V_11 )
{
unsigned V_190 ;
if ( V_11 -> V_191 )
F_19 ( V_11 -> V_191 , V_11 -> V_21 ) ;
if ( V_11 -> V_21 )
F_187 ( V_11 -> V_21 ) ;
if ( V_11 -> V_135 )
F_188 ( V_11 -> V_135 ) ;
if ( V_11 -> V_15 )
F_189 ( V_11 -> V_15 ) ;
if ( V_11 -> V_12 )
F_190 ( V_11 -> V_12 ) ;
if ( V_11 -> V_39 )
F_6 ( V_11 -> V_39 ) ;
if ( V_11 -> V_54 )
F_6 ( V_11 -> V_54 ) ;
if ( V_11 -> V_126 )
F_191 ( V_11 -> V_126 ) ;
if ( V_11 -> V_56 )
F_192 ( V_11 -> V_56 ) ;
if ( V_11 -> V_192 )
F_193 ( V_11 -> V_43 , V_11 -> V_192 ) ;
if ( V_11 -> V_81 )
F_193 ( V_11 -> V_43 , V_11 -> V_81 ) ;
if ( V_11 -> V_84 )
F_193 ( V_11 -> V_43 , V_11 -> V_84 ) ;
if ( V_11 -> V_42 )
F_194 ( V_11 -> V_42 ) ;
for ( V_190 = 0 ; V_190 < V_11 -> V_193 ; V_190 ++ )
F_195 ( V_11 -> V_194 [ V_190 ] ) ;
F_195 ( V_11 -> V_194 ) ;
F_195 ( V_11 ) ;
}
static void F_196 ( struct V_195 * V_43 )
{
struct V_11 * V_11 = V_43 -> V_196 ;
F_186 ( V_11 ) ;
}
static T_10 F_197 ( struct V_182 * V_31 )
{
return F_198 ( V_31 -> V_82 -> V_197 ) >> V_128 ;
}
static void F_199 ( struct V_198 * V_199 )
{
if ( V_199 -> V_192 )
F_193 ( V_199 -> V_43 , V_199 -> V_192 ) ;
if ( V_199 -> V_84 )
F_193 ( V_199 -> V_43 , V_199 -> V_84 ) ;
if ( V_199 -> V_81 )
F_193 ( V_199 -> V_43 , V_199 -> V_81 ) ;
F_195 ( V_199 ) ;
}
static bool F_200 ( struct V_200 * V_201 , char * * error )
{
if ( ! V_201 -> V_202 ) {
* error = L_10 ;
return false ;
}
return true ;
}
static int F_201 ( struct V_198 * V_199 , struct V_200 * V_201 ,
char * * error )
{
int V_26 ;
T_10 V_203 ;
char V_38 [ V_204 ] ;
if ( ! F_200 ( V_201 , error ) )
return - V_205 ;
V_26 = F_202 ( V_199 -> V_43 , F_203 ( V_201 ) , V_206 | V_207 ,
& V_199 -> V_192 ) ;
if ( V_26 ) {
* error = L_11 ;
return V_26 ;
}
V_203 = F_197 ( V_199 -> V_192 ) ;
if ( V_203 > V_208 )
F_107 ( L_12 ,
F_204 ( V_199 -> V_192 -> V_82 , V_38 ) , V_209 ) ;
return 0 ;
}
static int F_205 ( struct V_198 * V_199 , struct V_200 * V_201 ,
char * * error )
{
int V_26 ;
if ( ! F_200 ( V_201 , error ) )
return - V_205 ;
V_26 = F_202 ( V_199 -> V_43 , F_203 ( V_201 ) , V_206 | V_207 ,
& V_199 -> V_84 ) ;
if ( V_26 ) {
* error = L_13 ;
return V_26 ;
}
V_199 -> V_210 = F_197 ( V_199 -> V_84 ) ;
return 0 ;
}
static int F_206 ( struct V_198 * V_199 , struct V_200 * V_201 ,
char * * error )
{
int V_26 ;
if ( ! F_200 ( V_201 , error ) )
return - V_205 ;
V_26 = F_202 ( V_199 -> V_43 , F_203 ( V_201 ) , V_206 | V_207 ,
& V_199 -> V_81 ) ;
if ( V_26 ) {
* error = L_14 ;
return V_26 ;
}
V_199 -> V_211 = F_197 ( V_199 -> V_81 ) ;
if ( V_199 -> V_43 -> V_212 > V_199 -> V_211 ) {
* error = L_15 ;
return - V_205 ;
}
return 0 ;
}
static int F_207 ( struct V_198 * V_199 , struct V_200 * V_201 ,
char * * error )
{
unsigned long V_213 ;
if ( ! F_200 ( V_201 , error ) )
return - V_205 ;
if ( F_208 ( F_203 ( V_201 ) , 10 , & V_213 ) || ! V_213 ||
V_213 < V_214 ||
V_213 > V_215 ||
V_213 & ( V_214 - 1 ) ) {
* error = L_16 ;
return - V_205 ;
}
if ( V_213 > V_199 -> V_210 ) {
* error = L_17 ;
return - V_205 ;
}
V_199 -> V_213 = V_213 ;
return 0 ;
}
static void F_209 ( struct V_65 * V_216 )
{
V_216 -> V_217 = V_218 ;
V_216 -> V_67 = V_69 ;
}
static int F_210 ( struct V_198 * V_199 , struct V_200 * V_201 ,
char * * error )
{
static struct V_219 V_220 [] = {
{ 0 , 1 , L_18 } ,
} ;
int V_26 ;
unsigned V_202 ;
const char * V_221 ;
struct V_65 * V_216 = & V_199 -> V_71 ;
F_209 ( V_216 ) ;
V_26 = F_211 ( V_220 , V_201 , & V_202 , error ) ;
if ( V_26 )
return - V_205 ;
while ( V_202 -- ) {
V_221 = F_203 ( V_201 ) ;
if ( ! strcasecmp ( V_221 , L_19 ) )
V_216 -> V_67 = V_69 ;
else if ( ! strcasecmp ( V_221 , L_20 ) )
V_216 -> V_67 = V_68 ;
else if ( ! strcasecmp ( V_221 , L_21 ) )
V_216 -> V_67 = V_70 ;
else {
* error = L_22 ;
return - V_205 ;
}
}
return 0 ;
}
static int F_212 ( struct V_198 * V_199 , struct V_200 * V_201 ,
char * * error )
{
static struct V_219 V_220 [] = {
{ 0 , 1024 , L_23 } ,
} ;
int V_26 ;
if ( ! F_200 ( V_201 , error ) )
return - V_205 ;
V_199 -> V_222 = F_203 ( V_201 ) ;
V_26 = F_211 ( V_220 , V_201 , & V_199 -> V_223 , error ) ;
if ( V_26 )
return - V_205 ;
V_199 -> V_224 = ( const char * * ) V_201 -> V_225 ;
F_213 ( V_201 , V_199 -> V_223 ) ;
return 0 ;
}
static int F_214 ( struct V_198 * V_199 , int V_202 , char * * V_225 ,
char * * error )
{
int V_26 ;
struct V_200 V_201 ;
V_201 . V_202 = V_202 ;
V_201 . V_225 = V_225 ;
V_26 = F_201 ( V_199 , & V_201 , error ) ;
if ( V_26 )
return V_26 ;
V_26 = F_205 ( V_199 , & V_201 , error ) ;
if ( V_26 )
return V_26 ;
V_26 = F_206 ( V_199 , & V_201 , error ) ;
if ( V_26 )
return V_26 ;
V_26 = F_207 ( V_199 , & V_201 , error ) ;
if ( V_26 )
return V_26 ;
V_26 = F_210 ( V_199 , & V_201 , error ) ;
if ( V_26 )
return V_26 ;
V_26 = F_212 ( V_199 , & V_201 , error ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_215 ( struct V_11 * V_11 , const char * V_29 , const char * V_226 )
{
unsigned long V_133 ;
if ( ! strcasecmp ( V_29 , L_24 ) ) {
if ( F_208 ( V_226 , 10 , & V_133 ) )
return - V_205 ;
V_11 -> V_141 = V_133 ;
return 0 ;
}
return V_227 ;
}
static int F_216 ( struct V_11 * V_11 , const char * V_29 , const char * V_226 )
{
int V_26 = F_215 ( V_11 , V_29 , V_226 ) ;
if ( V_26 == V_227 )
V_26 = F_217 ( V_11 -> V_42 , V_29 , V_226 ) ;
if ( V_26 )
F_107 ( L_25 , V_29 , V_226 ) ;
return V_26 ;
}
static int F_218 ( struct V_11 * V_11 , int V_202 , const char * * V_225 )
{
int V_26 = 0 ;
if ( V_202 & 1 ) {
F_107 ( L_26 ) ;
return - V_205 ;
}
while ( V_202 ) {
V_26 = F_216 ( V_11 , V_225 [ 0 ] , V_225 [ 1 ] ) ;
if ( V_26 )
break;
V_202 -= 2 ;
V_225 += 2 ;
}
return V_26 ;
}
static int F_219 ( struct V_11 * V_11 , struct V_198 * V_199 ,
char * * error )
{
struct V_228 * V_19 = F_220 ( V_199 -> V_222 ,
V_11 -> V_229 ,
V_11 -> V_211 ,
V_11 -> V_49 ) ;
if ( F_221 ( V_19 ) ) {
* error = L_27 ;
return F_222 ( V_19 ) ;
}
V_11 -> V_42 = V_19 ;
return 0 ;
}
static bool F_223 ( T_10 V_48 ,
T_10 V_230 )
{
( void ) F_73 ( V_230 , V_48 ) ;
return V_230 > V_231 ;
}
static T_10 F_224 ( T_10 V_232 ,
T_10 V_230 )
{
T_10 V_48 ;
V_48 = F_225 ( V_232 ) ;
if ( V_230 )
while ( F_223 ( V_48 , V_230 ) )
V_48 *= 2 ;
return V_48 ;
}
static int F_226 ( struct V_198 * V_199 , struct V_11 * * V_233 )
{
int V_26 = 0 ;
char * * error = & V_199 -> V_43 -> error ;
struct V_11 * V_11 ;
struct V_195 * V_43 = V_199 -> V_43 ;
T_7 V_234 ;
struct V_235 * V_56 ;
bool V_236 = V_199 -> V_71 . V_217 == V_218 ;
V_11 = F_227 ( sizeof( * V_11 ) , V_237 ) ;
if ( ! V_11 )
return - V_22 ;
V_11 -> V_43 = V_199 -> V_43 ;
V_43 -> V_196 = V_11 ;
V_43 -> V_238 = 2 ;
V_43 -> V_239 = true ;
V_43 -> V_240 = 1 ;
V_43 -> V_241 = true ;
V_43 -> V_242 = true ;
V_11 -> V_71 = V_199 -> V_71 ;
V_43 -> V_243 = F_66 ( V_11 ) ;
V_11 -> V_189 . V_244 = F_185 ;
F_228 ( V_43 -> V_44 , & V_11 -> V_189 ) ;
V_11 -> V_192 = V_199 -> V_192 ;
V_11 -> V_81 = V_199 -> V_81 ;
V_11 -> V_84 = V_199 -> V_84 ;
V_199 -> V_192 = V_199 -> V_81 = V_199 -> V_84 = NULL ;
V_234 = V_11 -> V_211 = V_199 -> V_211 ;
V_234 = F_43 ( V_234 , V_199 -> V_213 ) ;
V_11 -> V_234 = F_79 ( V_234 ) ;
V_11 -> V_49 = V_199 -> V_213 ;
if ( F_229 ( V_43 , V_11 -> V_49 ) ) {
V_26 = - V_205 ;
goto V_245;
}
if ( V_199 -> V_213 & ( V_199 -> V_213 - 1 ) ) {
T_7 V_229 = V_199 -> V_210 ;
V_11 -> V_45 = - 1 ;
V_229 = F_43 ( V_229 , V_199 -> V_213 ) ;
V_11 -> V_229 = F_36 ( V_229 ) ;
} else {
V_11 -> V_45 = F_230 ( V_199 -> V_213 ) ;
V_11 -> V_229 = F_36 ( V_199 -> V_210 >> V_11 -> V_45 ) ;
}
V_26 = F_219 ( V_11 , V_199 , error ) ;
if ( V_26 )
goto V_245;
V_11 -> V_246 = V_199 -> V_223 ;
V_11 -> V_141 = V_247 ;
V_26 = F_218 ( V_11 , V_199 -> V_223 , V_199 -> V_224 ) ;
if ( V_26 ) {
* error = L_28 ;
goto V_245;
}
V_56 = F_231 ( V_11 -> V_192 -> V_82 ,
V_199 -> V_213 , V_236 ,
F_232 ( V_11 -> V_42 ) ) ;
if ( F_221 ( V_56 ) ) {
* error = L_29 ;
V_26 = F_222 ( V_56 ) ;
goto V_245;
}
V_11 -> V_56 = V_56 ;
if ( F_65 ( & V_11 -> V_71 ) ) {
bool V_248 ;
V_26 = F_233 ( V_11 -> V_56 , & V_248 ) ;
if ( V_26 ) {
* error = L_30 ;
goto V_245;
}
if ( ! V_248 ) {
* error = L_31 ;
V_26 = - V_205 ;
goto V_245;
}
}
F_234 ( & V_11 -> V_53 ) ;
F_150 ( & V_11 -> V_104 ) ;
F_150 ( & V_11 -> V_94 ) ;
F_150 ( & V_11 -> V_95 ) ;
F_120 ( & V_11 -> V_114 ) ;
F_120 ( & V_11 -> V_120 ) ;
F_120 ( & V_11 -> V_113 ) ;
F_59 ( & V_11 -> V_99 , 0 ) ;
F_235 ( & V_11 -> V_100 ) ;
F_235 ( & V_11 -> V_177 ) ;
F_59 ( & V_11 -> V_175 , 0 ) ;
F_59 ( & V_11 -> V_176 , 0 ) ;
V_26 = - V_22 ;
V_11 -> V_41 = 0 ;
V_11 -> V_39 = F_3 ( F_33 ( V_11 -> V_229 ) ) ;
if ( ! V_11 -> V_39 ) {
* error = L_32 ;
goto V_245;
}
F_5 ( V_11 -> V_39 , F_33 ( V_11 -> V_229 ) ) ;
V_11 -> V_48 =
F_224 ( V_11 -> V_49 ,
V_11 -> V_211 ) ;
V_11 -> V_249 = F_45 ( V_11 , V_11 -> V_234 ) ;
V_11 -> V_54 = F_3 ( F_51 ( V_11 -> V_249 ) ) ;
if ( ! V_11 -> V_54 ) {
* error = L_33 ;
goto V_245;
}
F_5 ( V_11 -> V_54 , F_51 ( V_11 -> V_249 ) ) ;
V_11 -> V_126 = F_236 ( & V_250 ) ;
if ( F_221 ( V_11 -> V_126 ) ) {
* error = L_34 ;
V_26 = F_222 ( V_11 -> V_126 ) ;
goto V_245;
}
V_11 -> V_12 = F_237 ( L_35 V_251 , V_252 ) ;
if ( ! V_11 -> V_12 ) {
* error = L_36 ;
goto V_245;
}
F_238 ( & V_11 -> V_13 , F_176 ) ;
F_239 ( & V_11 -> V_178 , F_178 ) ;
V_11 -> V_159 = V_137 ;
V_11 -> V_15 = F_240 ( V_253 ) ;
if ( ! V_11 -> V_15 ) {
* error = L_37 ;
goto V_245;
}
V_11 -> V_135 = F_241 () ;
if ( ! V_11 -> V_135 ) {
* error = L_38 ;
goto V_245;
}
V_11 -> V_21 = F_242 ( V_254 ,
V_255 ) ;
if ( ! V_11 -> V_21 ) {
* error = L_39 ;
goto V_245;
}
V_11 -> V_191 = NULL ;
V_11 -> V_86 = true ;
V_11 -> V_256 = false ;
V_11 -> V_115 = false ;
V_11 -> V_93 = false ;
V_11 -> V_257 = false ;
V_11 -> V_258 = false ;
F_57 ( V_11 ) ;
F_59 ( & V_11 -> V_51 . V_153 , 0 ) ;
F_59 ( & V_11 -> V_51 . V_155 , 0 ) ;
F_59 ( & V_11 -> V_51 . V_129 , 0 ) ;
F_59 ( & V_11 -> V_51 . V_157 , 0 ) ;
F_59 ( & V_11 -> V_51 . V_161 , 0 ) ;
F_59 ( & V_11 -> V_51 . V_52 , 0 ) ;
F_234 ( & V_11 -> V_173 ) ;
F_120 ( & V_11 -> V_174 ) ;
* V_233 = V_11 ;
return 0 ;
V_245:
F_186 ( V_11 ) ;
return V_26 ;
}
static int F_243 ( struct V_11 * V_11 , int V_202 , const char * * V_225 )
{
unsigned V_190 ;
const char * * V_259 ;
V_259 = F_244 ( V_202 , sizeof( * V_259 ) , V_237 ) ;
if ( ! V_259 )
return - V_22 ;
for ( V_190 = 0 ; V_190 < V_202 ; V_190 ++ ) {
V_259 [ V_190 ] = F_245 ( V_225 [ V_190 ] , V_237 ) ;
if ( ! V_259 [ V_190 ] ) {
while ( V_190 -- )
F_195 ( V_259 [ V_190 ] ) ;
F_195 ( V_259 ) ;
return - V_22 ;
}
}
V_11 -> V_193 = V_202 ;
V_11 -> V_194 = V_259 ;
return 0 ;
}
static int F_246 ( struct V_195 * V_43 , unsigned V_202 , char * * V_225 )
{
int V_26 = - V_205 ;
struct V_198 * V_199 ;
struct V_11 * V_11 = NULL ;
V_199 = F_227 ( sizeof( * V_199 ) , V_237 ) ;
if ( ! V_199 ) {
V_43 -> error = L_40 ;
return - V_22 ;
}
V_199 -> V_43 = V_43 ;
V_26 = F_214 ( V_199 , V_202 , V_225 , & V_43 -> error ) ;
if ( V_26 )
goto V_260;
V_26 = F_226 ( V_199 , & V_11 ) ;
if ( V_26 )
goto V_260;
V_26 = F_243 ( V_11 , V_202 - 3 , ( const char * * ) V_225 + 3 ) ;
if ( V_26 ) {
F_186 ( V_11 ) ;
goto V_260;
}
V_43 -> V_196 = V_11 ;
V_260:
F_199 ( V_199 ) ;
return V_26 ;
}
static int F_247 ( struct V_195 * V_43 , struct V_8 * V_8 )
{
struct V_11 * V_11 = V_43 -> V_196 ;
int V_26 ;
T_3 V_32 = F_78 ( V_11 , V_8 ) ;
T_1 V_85 = F_66 ( V_11 ) ;
bool V_148 = false ;
bool V_146 ;
struct V_14 * V_17 ;
struct V_144 V_145 ;
struct V_74 * V_76 ;
if ( F_26 ( V_32 ) > F_26 ( V_11 -> V_234 ) ) {
F_75 ( V_11 , V_8 , V_32 ) ;
return V_261 ;
}
V_76 = F_69 ( V_8 , V_85 ) ;
if ( V_8 -> V_87 & ( V_89 | V_88 | V_90 ) ) {
F_132 ( V_11 , V_8 ) ;
return V_262 ;
}
V_17 = F_12 ( V_11 ) ;
if ( ! V_17 ) {
F_132 ( V_11 , V_8 ) ;
return V_262 ;
}
V_26 = F_27 ( V_11 , V_32 , V_8 , V_17 ,
( T_4 ) F_14 ,
V_11 , & V_17 ) ;
if ( V_26 ) {
if ( V_26 < 0 )
F_132 ( V_11 , V_8 ) ;
return V_262 ;
}
V_146 = F_56 ( V_11 , V_32 ) ;
V_26 = F_143 ( V_11 -> V_42 , V_32 , false , V_148 , V_146 ,
V_8 , & V_145 ) ;
if ( V_26 == - V_149 ) {
F_96 ( V_11 , V_17 , true ) ;
return V_262 ;
} else if ( V_26 ) {
F_111 ( L_41 , V_26 ) ;
F_144 ( V_8 ) ;
return V_262 ;
}
V_26 = V_261 ;
switch ( V_145 . V_150 ) {
case V_152 :
if ( F_65 ( & V_11 -> V_71 ) ) {
if ( F_76 ( V_8 ) == V_91 ) {
F_96 ( V_11 , V_17 , true ) ;
V_26 = V_262 ;
} else {
V_76 -> V_79 = F_141 ( V_11 -> V_135 ) ;
F_139 ( V_11 , V_8 ) ;
F_75 ( V_11 , V_8 , V_32 ) ;
F_96 ( V_11 , V_17 , false ) ;
}
} else {
F_138 ( V_11 , V_8 ) ;
if ( F_76 ( V_8 ) == V_91 && F_63 ( & V_11 -> V_71 ) &&
! F_31 ( V_11 , V_145 . V_40 ) )
F_88 ( V_11 , V_8 , V_32 , V_145 . V_40 ) ;
else
F_77 ( V_11 , V_8 , V_32 , V_145 . V_40 ) ;
F_96 ( V_11 , V_17 , false ) ;
}
break;
case V_151 :
F_139 ( V_11 , V_8 ) ;
V_76 -> V_79 = F_141 ( V_11 -> V_135 ) ;
if ( V_76 -> V_78 != 0 ) {
F_86 ( V_8 , 0 ) ;
F_96 ( V_11 , V_17 , false ) ;
return V_262 ;
} else {
F_75 ( V_11 , V_8 , V_32 ) ;
F_96 ( V_11 , V_17 , false ) ;
}
break;
default:
F_111 ( L_42 , V_158 ,
( unsigned ) V_145 . V_150 ) ;
F_144 ( V_8 ) ;
V_26 = V_262 ;
}
return V_26 ;
}
static int F_248 ( struct V_195 * V_43 , struct V_8 * V_8 , int error )
{
struct V_11 * V_11 = V_43 -> V_196 ;
unsigned long V_50 ;
T_1 V_85 = F_66 ( V_11 ) ;
struct V_74 * V_76 = F_67 ( V_8 , V_85 ) ;
if ( V_76 -> V_77 ) {
F_180 ( V_11 -> V_42 ) ;
F_49 ( & V_11 -> V_53 , V_50 ) ;
V_11 -> V_86 = true ;
F_52 ( & V_11 -> V_53 , V_50 ) ;
}
F_126 ( V_11 , V_76 ) ;
return 0 ;
}
static int F_249 ( struct V_11 * V_11 )
{
unsigned V_190 , V_26 ;
for ( V_190 = 0 ; V_190 < F_33 ( V_11 -> V_229 ) ; V_190 ++ ) {
V_26 = F_250 ( V_11 -> V_56 , F_36 ( V_190 ) ,
F_31 ( V_11 , F_36 ( V_190 ) ) ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_251 ( struct V_11 * V_11 )
{
unsigned V_190 , V_26 ;
V_26 = F_252 ( V_11 -> V_56 , V_11 -> V_48 ,
V_11 -> V_249 ) ;
if ( V_26 ) {
F_160 ( L_43 ) ;
return V_26 ;
}
for ( V_190 = 0 ; V_190 < F_51 ( V_11 -> V_249 ) ; V_190 ++ ) {
V_26 = F_253 ( V_11 -> V_56 , F_46 ( V_190 ) ,
F_55 ( V_11 , F_46 ( V_190 ) ) ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_254 ( void * V_119 , T_5 V_40 , T_3 V_27 ,
T_8 V_263 )
{
struct V_11 * V_11 = V_119 ;
return F_255 ( V_11 -> V_56 , V_40 , V_263 ) ;
}
static int F_256 ( struct V_11 * V_11 )
{
int V_26 ;
V_26 = F_257 ( V_11 -> V_56 , V_11 -> V_42 ) ;
if ( V_26 ) {
F_160 ( L_44 ) ;
return V_26 ;
}
V_26 = F_258 ( V_11 -> V_42 , F_254 , V_11 ) ;
if ( V_26 )
F_160 ( L_45 ) ;
return V_26 ;
}
static bool F_259 ( struct V_11 * V_11 )
{
int V_264 , V_265 , V_266 , V_267 ;
V_264 = F_249 ( V_11 ) ;
if ( V_264 )
F_160 ( L_46 ) ;
V_265 = F_251 ( V_11 ) ;
if ( V_265 )
F_160 ( L_47 ) ;
F_60 ( V_11 ) ;
V_266 = F_256 ( V_11 ) ;
if ( V_266 )
F_160 ( L_48 ) ;
V_267 = F_148 ( V_11 -> V_56 , ! V_264 && ! V_265 && ! V_266 ) ;
if ( V_267 )
F_160 ( L_49 ) ;
return ! V_264 && ! V_265 && ! V_266 && ! V_267 ;
}
static void F_260 ( struct V_195 * V_43 )
{
struct V_11 * V_11 = V_43 -> V_196 ;
F_168 ( V_11 ) ;
F_170 ( V_11 ) ;
F_171 ( V_11 ) ;
F_174 ( V_11 ) ;
F_169 ( V_11 ) ;
( void ) F_259 ( V_11 ) ;
}
static int F_261 ( void * V_119 , T_3 V_27 , T_5 V_40 ,
bool V_268 , T_8 V_263 , bool V_269 )
{
int V_26 ;
struct V_11 * V_11 = V_119 ;
V_26 = F_262 ( V_11 -> V_42 , V_27 , V_40 , V_263 , V_269 ) ;
if ( V_26 )
return V_26 ;
if ( V_268 )
F_34 ( V_11 , V_27 , V_40 ) ;
else
F_38 ( V_11 , V_27 , V_40 ) ;
return 0 ;
}
static int F_263 ( void * V_119 , T_10 V_48 ,
T_9 V_270 , bool V_271 )
{
struct V_11 * V_11 = V_119 ;
if ( V_271 )
F_47 ( V_11 , V_270 ) ;
else
F_53 ( V_11 , V_270 ) ;
return 0 ;
}
static T_5 F_264 ( struct V_11 * V_11 )
{
T_10 V_272 = F_197 ( V_11 -> V_84 ) ;
( void ) F_73 ( V_272 , V_11 -> V_49 ) ;
return F_36 ( V_272 ) ;
}
static bool F_265 ( struct V_11 * V_11 , T_5 V_273 )
{
if ( F_33 ( V_273 ) > F_33 ( V_11 -> V_229 ) )
return true ;
while ( F_33 ( V_273 ) < F_33 ( V_11 -> V_229 ) ) {
V_273 = F_36 ( F_33 ( V_273 ) + 1 ) ;
if ( F_31 ( V_11 , V_273 ) ) {
F_160 ( L_50 ,
( unsigned long long ) F_33 ( V_273 ) ) ;
return false ;
}
}
return true ;
}
static int F_266 ( struct V_11 * V_11 , T_5 V_273 )
{
int V_26 ;
V_26 = F_267 ( V_11 -> V_56 , V_273 ) ;
if ( V_26 ) {
F_160 ( L_51 ) ;
return V_26 ;
}
V_11 -> V_229 = V_273 ;
return 0 ;
}
static int F_268 ( struct V_195 * V_43 )
{
int V_26 = 0 ;
struct V_11 * V_11 = V_43 -> V_196 ;
T_5 V_274 = F_264 ( V_11 ) ;
if ( ! V_11 -> V_256 ) {
V_26 = F_266 ( V_11 , V_274 ) ;
if ( V_26 )
return V_26 ;
V_11 -> V_256 = true ;
} else if ( V_274 != V_11 -> V_229 ) {
if ( ! F_265 ( V_11 , V_274 ) )
return - V_205 ;
V_26 = F_266 ( V_11 , V_274 ) ;
if ( V_26 )
return V_26 ;
}
if ( ! V_11 -> V_257 ) {
V_26 = F_269 ( V_11 -> V_56 , V_11 -> V_42 ,
F_261 , V_11 ) ;
if ( V_26 ) {
F_160 ( L_52 ) ;
return V_26 ;
}
V_11 -> V_257 = true ;
}
if ( ! V_11 -> V_258 ) {
V_26 = F_270 ( V_11 -> V_56 , F_263 , V_11 ) ;
if ( V_26 ) {
F_160 ( L_53 ) ;
return V_26 ;
}
V_11 -> V_258 = true ;
}
return V_26 ;
}
static void F_271 ( struct V_195 * V_43 )
{
struct V_11 * V_11 = V_43 -> V_196 ;
V_11 -> V_86 = true ;
F_178 ( & V_11 -> V_178 . V_134 ) ;
}
static void F_272 ( struct V_195 * V_43 , T_12 type ,
unsigned V_275 , char * V_233 , unsigned V_276 )
{
int V_26 = 0 ;
unsigned V_190 ;
T_13 V_277 = 0 ;
T_7 V_278 = 0 ;
T_7 V_279 = 0 ;
char V_280 [ V_204 ] ;
struct V_11 * V_11 = V_43 -> V_196 ;
T_5 V_281 ;
switch ( type ) {
case V_282 :
if ( ! ( V_275 & V_283 ) && ! F_273 ( V_43 ) ) {
V_26 = F_148 ( V_11 -> V_56 , false ) ;
if ( V_26 )
F_160 ( L_54 ) ;
}
V_26 = F_274 ( V_11 -> V_56 ,
& V_278 ) ;
if ( V_26 ) {
F_160 ( L_55 ) ;
goto V_96;
}
V_26 = F_275 ( V_11 -> V_56 , & V_279 ) ;
if ( V_26 ) {
F_160 ( L_56 ) ;
goto V_96;
}
V_281 = F_276 ( V_11 -> V_42 ) ;
F_277 ( L_57 ,
( unsigned long long ) ( V_279 - V_278 ) ,
( unsigned long long ) V_279 ,
( unsigned ) F_61 ( & V_11 -> V_51 . V_57 ) ,
( unsigned ) F_61 ( & V_11 -> V_51 . V_59 ) ,
( unsigned ) F_61 ( & V_11 -> V_51 . V_61 ) ,
( unsigned ) F_61 ( & V_11 -> V_51 . V_63 ) ,
( unsigned ) F_61 ( & V_11 -> V_51 . V_153 ) ,
( unsigned ) F_61 ( & V_11 -> V_51 . V_155 ) ,
( unsigned long long ) F_33 ( V_281 ) ,
V_11 -> V_41 ) ;
if ( F_63 ( & V_11 -> V_71 ) )
F_277 ( L_58 ) ;
else if ( F_65 ( & V_11 -> V_71 ) )
F_277 ( L_59 ) ;
else if ( F_64 ( & V_11 -> V_71 ) )
F_277 ( L_60 ) ;
else {
F_160 ( L_61 , ( int ) V_11 -> V_71 . V_67 ) ;
goto V_96;
}
F_277 ( L_62 , ( unsigned long long ) V_11 -> V_141 ) ;
if ( V_277 < V_276 ) {
V_26 = F_278 ( V_11 -> V_42 , V_233 + V_277 , V_276 - V_277 ) ;
if ( V_26 )
F_160 ( L_63 , V_26 ) ;
}
break;
case V_284 :
F_279 ( V_280 , V_11 -> V_192 -> V_82 -> V_285 ) ;
F_277 ( L_64 , V_280 ) ;
F_279 ( V_280 , V_11 -> V_84 -> V_82 -> V_285 ) ;
F_277 ( L_64 , V_280 ) ;
F_279 ( V_280 , V_11 -> V_81 -> V_82 -> V_285 ) ;
F_277 ( L_65 , V_280 ) ;
for ( V_190 = 0 ; V_190 < V_11 -> V_193 - 1 ; V_190 ++ )
F_277 ( L_66 , V_11 -> V_194 [ V_190 ] ) ;
if ( V_11 -> V_193 )
F_277 ( L_66 , V_11 -> V_194 [ V_11 -> V_193 - 1 ] ) ;
}
return;
V_96:
F_277 ( L_67 ) ;
}
static int F_280 ( struct V_11 * V_11 , const char * V_286 ,
struct V_287 * V_233 )
{
char V_288 ;
T_11 V_38 , V_289 ;
int V_26 ;
V_26 = sscanf ( V_286 , L_68 , & V_38 , & V_289 , & V_288 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 == 2 ) {
V_233 -> V_167 = F_36 ( V_38 ) ;
V_233 -> V_169 = F_36 ( V_289 ) ;
return 0 ;
}
V_26 = sscanf ( V_286 , L_69 , & V_38 , & V_288 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 == 1 ) {
V_233 -> V_167 = F_36 ( V_38 ) ;
V_233 -> V_169 = F_36 ( F_33 ( V_233 -> V_167 ) + 1u ) ;
return 0 ;
}
F_160 ( L_70 , V_286 ) ;
return - V_205 ;
}
static int F_281 ( struct V_11 * V_11 , struct V_287 * V_290 )
{
T_11 V_38 = F_33 ( V_290 -> V_167 ) ;
T_11 V_289 = F_33 ( V_290 -> V_169 ) ;
T_11 V_46 = F_33 ( V_11 -> V_229 ) ;
if ( V_38 >= V_46 ) {
F_160 ( L_71 , V_38 , V_46 ) ;
return - V_205 ;
}
if ( V_289 > V_46 ) {
F_160 ( L_72 , V_289 , V_46 ) ;
return - V_205 ;
}
if ( V_38 >= V_289 ) {
F_160 ( L_73 , V_38 , V_289 ) ;
return - V_205 ;
}
return 0 ;
}
static int F_282 ( struct V_11 * V_11 , struct V_287 * V_290 )
{
struct V_165 V_166 ;
F_120 ( & V_166 . V_112 ) ;
V_166 . V_168 = V_290 ;
F_59 ( & V_166 . V_171 , 0 ) ;
V_166 . V_96 = 0 ;
F_235 ( & V_166 . V_172 ) ;
F_162 ( & V_11 -> V_173 ) ;
F_283 ( & V_166 . V_112 , & V_11 -> V_174 ) ;
F_163 ( & V_11 -> V_173 ) ;
F_10 ( V_11 ) ;
F_167 ( V_166 . V_172 , F_61 ( & V_166 . V_171 ) ) ;
return V_166 . V_96 ;
}
static int F_284 ( struct V_11 * V_11 , unsigned V_124 ,
const char * * V_291 )
{
int V_26 = 0 ;
unsigned V_190 ;
struct V_287 V_290 ;
if ( ! F_65 ( & V_11 -> V_71 ) ) {
F_160 ( L_74 ) ;
return - V_292 ;
}
for ( V_190 = 0 ; V_190 < V_124 ; V_190 ++ ) {
V_26 = F_280 ( V_11 , V_291 [ V_190 ] , & V_290 ) ;
if ( V_26 )
break;
V_26 = F_281 ( V_11 , & V_290 ) ;
if ( V_26 )
break;
V_26 = F_282 ( V_11 , & V_290 ) ;
if ( V_26 )
break;
}
return V_26 ;
}
static int F_285 ( struct V_195 * V_43 , unsigned V_202 , char * * V_225 )
{
struct V_11 * V_11 = V_43 -> V_196 ;
if ( ! V_202 )
return - V_205 ;
if ( ! strcasecmp ( V_225 [ 0 ] , L_75 ) )
return F_284 ( V_11 , V_202 - 1 , ( const char * * ) V_225 + 1 ) ;
if ( V_202 != 2 )
return - V_205 ;
return F_216 ( V_11 , V_225 [ 0 ] , V_225 [ 1 ] ) ;
}
static int F_286 ( struct V_195 * V_43 ,
T_14 F_119 , void * V_293 )
{
int V_26 = 0 ;
struct V_11 * V_11 = V_43 -> V_196 ;
V_26 = F_119 ( V_43 , V_11 -> V_84 , 0 , F_197 ( V_11 -> V_84 ) , V_293 ) ;
if ( ! V_26 )
V_26 = F_119 ( V_43 , V_11 -> V_81 , 0 , V_43 -> V_212 , V_293 ) ;
return V_26 ;
}
static int F_287 ( struct V_195 * V_43 ,
struct V_294 * V_295 ,
struct V_296 * V_297 , int V_298 )
{
struct V_11 * V_11 = V_43 -> V_196 ;
struct V_184 * V_185 = F_183 ( V_11 -> V_81 -> V_82 ) ;
if ( ! V_185 -> V_299 )
return V_298 ;
V_295 -> V_80 = V_11 -> V_81 -> V_82 ;
return F_288 ( V_298 , V_185 -> V_299 ( V_185 , V_295 , V_297 ) ) ;
}
static void F_289 ( struct V_11 * V_11 , struct V_300 * V_301 )
{
V_301 -> V_302 = V_11 -> V_48 * 1024 ;
V_301 -> V_303 = V_11 -> V_48 << V_128 ;
}
static void F_290 ( struct V_195 * V_43 , struct V_300 * V_301 )
{
struct V_11 * V_11 = V_43 -> V_196 ;
T_11 V_304 = V_301 -> V_305 >> V_128 ;
if ( V_304 < V_11 -> V_49 ||
F_44 ( V_304 , V_11 -> V_49 ) ) {
F_291 ( V_301 , 0 ) ;
F_292 ( V_301 , V_11 -> V_49 << V_128 ) ;
}
F_289 ( V_11 , V_301 ) ;
}
static int T_15 F_293 ( void )
{
int V_26 ;
V_26 = F_294 ( & V_306 ) ;
if ( V_26 ) {
F_160 ( L_76 , V_26 ) ;
return V_26 ;
}
V_255 = F_295 ( V_25 , 0 ) ;
if ( ! V_255 ) {
F_296 ( & V_306 ) ;
return - V_22 ;
}
return 0 ;
}
static void T_16 F_297 ( void )
{
F_296 ( & V_306 ) ;
F_298 ( V_255 ) ;
}
