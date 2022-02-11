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
static int F_17 ( struct V_12 * V_12 , struct V_19 * V_20 )
{
if ( ! V_20 -> V_21 ) {
V_20 -> V_21 = F_18 ( V_12 -> V_22 , V_17 ) ;
if ( ! V_20 -> V_21 )
return - V_23 ;
}
if ( ! V_20 -> V_24 ) {
V_20 -> V_24 = F_13 ( V_12 ) ;
if ( ! V_20 -> V_24 )
return - V_23 ;
}
if ( ! V_20 -> V_25 ) {
V_20 -> V_25 = F_13 ( V_12 ) ;
if ( ! V_20 -> V_25 )
return - V_23 ;
}
return 0 ;
}
static void F_19 ( struct V_12 * V_12 , struct V_19 * V_20 )
{
if ( V_20 -> V_25 )
F_15 ( V_12 , V_20 -> V_25 ) ;
if ( V_20 -> V_24 )
F_15 ( V_12 , V_20 -> V_24 ) ;
if ( V_20 -> V_21 )
F_20 ( V_20 -> V_21 , V_12 -> V_22 ) ;
}
static struct V_26 * F_21 ( struct V_19 * V_20 )
{
struct V_26 * V_21 = V_20 -> V_21 ;
F_22 ( ! V_21 ) ;
V_20 -> V_21 = NULL ;
return V_21 ;
}
static struct V_15 * F_23 ( struct V_19 * V_20 )
{
struct V_15 * V_27 = NULL ;
if ( V_20 -> V_24 ) {
V_27 = V_20 -> V_24 ;
V_20 -> V_24 = NULL ;
} else if ( V_20 -> V_25 ) {
V_27 = V_20 -> V_25 ;
V_20 -> V_25 = NULL ;
} else
F_24 () ;
return V_27 ;
}
static void F_25 ( struct V_19 * V_20 , struct V_15 * V_18 )
{
if ( ! V_20 -> V_25 )
V_20 -> V_25 = V_18 ;
else if ( ! V_20 -> V_24 )
V_20 -> V_24 = V_18 ;
else
F_24 () ;
}
static void F_26 ( T_3 V_28 , struct V_29 * V_30 )
{
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0 ;
V_30 -> V_33 = F_27 ( V_28 ) ;
}
static int F_28 ( struct V_12 * V_12 , T_3 V_28 ,
struct V_8 * V_8 , struct V_15 * V_34 ,
T_4 V_35 , void * V_36 ,
struct V_15 * * V_37 )
{
int V_27 ;
struct V_29 V_30 ;
F_26 ( V_28 , & V_30 ) ;
V_27 = F_29 ( V_12 -> V_16 , & V_30 , V_8 , V_34 , V_37 ) ;
if ( V_27 )
V_35 ( V_36 , V_34 ) ;
return V_27 ;
}
static int F_30 ( struct V_12 * V_12 ,
T_3 V_28 ,
struct V_19 * V_38 ,
struct V_15 * * V_37 )
{
int V_27 ;
struct V_29 V_30 ;
struct V_15 * V_34 ;
V_34 = F_23 ( V_38 ) ;
F_26 ( V_28 , & V_30 ) ;
V_27 = F_31 ( V_12 -> V_16 , & V_30 , V_34 , V_37 ) ;
if ( V_27 )
F_25 ( V_38 , V_34 ) ;
return V_27 ;
}
static bool F_32 ( struct V_12 * V_12 , T_5 V_39 )
{
return F_33 ( F_34 ( V_39 ) , V_12 -> V_40 ) ;
}
static void F_35 ( struct V_12 * V_12 , T_3 V_28 , T_5 V_41 )
{
if ( ! F_36 ( F_34 ( V_41 ) , V_12 -> V_40 ) ) {
V_12 -> V_42 = F_37 ( F_34 ( V_12 -> V_42 ) + 1 ) ;
F_38 ( V_12 -> V_43 , V_28 ) ;
}
}
static void F_39 ( struct V_12 * V_12 , T_3 V_28 , T_5 V_41 )
{
if ( F_40 ( F_34 ( V_41 ) , V_12 -> V_40 ) ) {
F_41 ( V_12 -> V_43 , V_28 ) ;
V_12 -> V_42 = F_37 ( F_34 ( V_12 -> V_42 ) - 1 ) ;
if ( ! F_34 ( V_12 -> V_42 ) )
F_42 ( V_12 -> V_44 -> V_45 ) ;
}
}
static bool F_43 ( struct V_12 * V_12 )
{
return V_12 -> V_46 >= 0 ;
}
T_6
#endif
static T_7 F_44 ( T_7 V_39 , T_8 V_47 )
{
F_45 ( V_39 , V_47 ) ;
return V_39 ;
}
static T_9 F_46 ( struct V_12 * V_12 , T_3 V_28 )
{
T_8 V_48 = V_12 -> V_49 ;
T_7 V_39 = F_27 ( V_28 ) ;
if ( ! F_43 ( V_12 ) )
V_48 = V_48 / V_12 -> V_50 ;
else
V_48 >>= V_12 -> V_46 ;
V_39 = F_44 ( V_39 , V_48 ) ;
return F_47 ( V_39 ) ;
}
static void F_48 ( struct V_12 * V_12 , T_9 V_39 )
{
unsigned long V_51 ;
F_10 ( & V_12 -> V_52 . V_53 ) ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_50 ( F_51 ( V_39 ) , V_12 -> V_55 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
}
static void F_53 ( struct V_12 * V_12 , T_9 V_39 )
{
unsigned long V_51 ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_54 ( F_51 ( V_39 ) , V_12 -> V_55 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
}
static bool F_55 ( struct V_12 * V_12 , T_9 V_39 )
{
int V_27 ;
unsigned long V_51 ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
V_27 = F_33 ( F_51 ( V_39 ) , V_12 -> V_55 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
return V_27 ;
}
static bool F_56 ( struct V_12 * V_12 , T_3 V_39 )
{
int V_27 ;
unsigned long V_51 ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
V_27 = F_33 ( F_51 ( F_46 ( V_12 , V_39 ) ) ,
V_12 -> V_55 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
return V_27 ;
}
static void F_57 ( struct V_12 * V_12 )
{
struct V_56 V_52 ;
F_58 ( V_12 -> V_57 , & V_52 ) ;
F_59 ( & V_12 -> V_52 . V_58 , V_52 . V_59 ) ;
F_59 ( & V_12 -> V_52 . V_60 , V_52 . V_61 ) ;
F_59 ( & V_12 -> V_52 . V_62 , V_52 . V_63 ) ;
F_59 ( & V_12 -> V_52 . V_64 , V_52 . V_65 ) ;
}
static void F_60 ( struct V_12 * V_12 )
{
struct V_56 V_52 ;
V_52 . V_59 = F_61 ( & V_12 -> V_52 . V_58 ) ;
V_52 . V_61 = F_61 ( & V_12 -> V_52 . V_60 ) ;
V_52 . V_63 = F_61 ( & V_12 -> V_52 . V_62 ) ;
V_52 . V_65 = F_61 ( & V_12 -> V_52 . V_64 ) ;
F_62 ( V_12 -> V_57 , & V_52 ) ;
}
static bool F_63 ( struct V_66 * V_67 )
{
return V_67 -> V_68 == V_69 ;
}
static bool F_64 ( struct V_66 * V_67 )
{
return V_67 -> V_68 == V_70 ;
}
static bool F_65 ( struct V_66 * V_67 )
{
return V_67 -> V_68 == V_71 ;
}
static T_1 F_66 ( struct V_12 * V_12 )
{
return F_63 ( & V_12 -> V_72 ) ? V_73 : V_74 ;
}
static struct V_75 * F_67 ( struct V_8 * V_8 , T_1 V_76 )
{
struct V_75 * V_77 = F_68 ( V_8 , V_76 ) ;
F_22 ( ! V_77 ) ;
return V_77 ;
}
static struct V_75 * F_69 ( struct V_8 * V_8 , T_1 V_76 )
{
struct V_75 * V_77 = F_67 ( V_8 , V_76 ) ;
V_77 -> V_78 = false ;
V_77 -> V_79 = F_70 ( V_8 ) ;
V_77 -> V_80 = NULL ;
return V_77 ;
}
static void F_71 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
V_8 -> V_81 = V_12 -> V_82 -> V_83 ;
}
static void F_72 ( struct V_12 * V_12 , struct V_8 * V_8 ,
T_5 V_41 )
{
T_10 V_84 = V_8 -> V_85 . V_84 ;
T_10 V_33 = F_34 ( V_41 ) ;
V_8 -> V_81 = V_12 -> V_86 -> V_83 ;
if ( ! F_43 ( V_12 ) )
V_8 -> V_85 . V_84 =
( V_33 * V_12 -> V_50 ) +
F_73 ( V_84 , V_12 -> V_50 ) ;
else
V_8 -> V_85 . V_84 =
( V_33 << V_12 -> V_46 ) |
( V_84 & ( V_12 -> V_50 - 1 ) ) ;
}
static void F_74 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
unsigned long V_51 ;
T_1 V_87 = F_66 ( V_12 ) ;
struct V_75 * V_77 = F_67 ( V_8 , V_87 ) ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
if ( V_12 -> V_88 &&
! ( V_8 -> V_89 & ( V_90 | V_91 | V_92 ) ) ) {
V_77 -> V_78 = true ;
V_12 -> V_88 = false ;
}
F_52 ( & V_12 -> V_54 , V_51 ) ;
}
static void F_75 ( struct V_12 * V_12 , struct V_8 * V_8 ,
T_3 V_28 )
{
F_74 ( V_12 , V_8 ) ;
F_71 ( V_12 , V_8 ) ;
if ( F_76 ( V_8 ) == V_93 )
F_53 ( V_12 , F_46 ( V_12 , V_28 ) ) ;
}
static void F_77 ( struct V_12 * V_12 , struct V_8 * V_8 ,
T_3 V_28 , T_5 V_41 )
{
F_74 ( V_12 , V_8 ) ;
F_72 ( V_12 , V_8 , V_41 ) ;
if ( F_76 ( V_8 ) == V_93 ) {
F_35 ( V_12 , V_28 , V_41 ) ;
F_53 ( V_12 , F_46 ( V_12 , V_28 ) ) ;
}
}
static T_3 F_78 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
T_10 V_94 = V_8 -> V_85 . V_84 ;
if ( ! F_43 ( V_12 ) )
( void ) F_73 ( V_94 , V_12 -> V_50 ) ;
else
V_94 >>= V_12 -> V_46 ;
return F_79 ( V_94 ) ;
}
static int F_80 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
return V_8 -> V_89 & ( V_91 | V_90 ) ;
}
static void F_81 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
unsigned long V_51 ;
if ( ! F_80 ( V_12 , V_8 ) ) {
F_82 ( V_8 ) ;
return;
}
F_49 ( & V_12 -> V_54 , V_51 ) ;
V_12 -> V_95 = true ;
F_83 ( & V_12 -> V_96 , V_8 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
}
static void F_84 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
unsigned long V_51 ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_83 ( & V_12 -> V_97 , V_8 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
F_11 ( V_12 ) ;
}
static void F_85 ( struct V_8 * V_8 , int V_98 )
{
struct V_75 * V_77 = F_67 ( V_8 , V_73 ) ;
F_9 ( & V_77 -> V_99 , V_8 ) ;
if ( V_98 ) {
F_86 ( V_8 , V_98 ) ;
return;
}
F_87 ( & V_77 -> V_100 , V_8 ) ;
F_72 ( V_77 -> V_12 , V_8 , V_77 -> V_41 ) ;
F_84 ( V_77 -> V_12 , V_8 ) ;
}
static void F_88 ( struct V_12 * V_12 , struct V_8 * V_8 ,
T_3 V_28 , T_5 V_41 )
{
struct V_75 * V_77 = F_67 ( V_8 , V_73 ) ;
V_77 -> V_12 = V_12 ;
V_77 -> V_41 = V_41 ;
F_8 ( & V_77 -> V_99 , V_8 , F_85 , NULL ) ;
F_89 ( & V_77 -> V_100 , V_8 ) ;
F_75 ( V_77 -> V_12 , V_8 , V_28 ) ;
}
static void F_90 ( struct V_26 * V_21 )
{
F_20 ( V_21 , V_21 -> V_12 -> V_22 ) ;
}
static void F_91 ( struct V_12 * V_12 )
{
F_10 ( & V_12 -> V_101 ) ;
}
static void F_92 ( struct V_12 * V_12 )
{
F_93 ( & V_12 -> V_101 ) ;
F_94 ( & V_12 -> V_102 ) ;
}
static void F_95 ( struct V_12 * V_12 , struct V_15 * V_18 ,
bool V_103 )
{
( V_103 ? V_104 : V_105 )
( V_12 -> V_16 , V_18 , & V_12 -> V_106 ) ;
F_15 ( V_12 , V_18 ) ;
}
static void F_96 ( struct V_12 * V_12 , struct V_15 * V_18 ,
bool V_103 )
{
unsigned long V_51 ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_95 ( V_12 , V_18 , V_103 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
F_11 ( V_12 ) ;
}
static void F_97 ( struct V_26 * V_21 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
F_90 ( V_21 ) ;
F_92 ( V_12 ) ;
}
static void F_98 ( struct V_26 * V_21 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
if ( V_21 -> V_107 ) {
F_99 ( L_1 ) ;
F_35 ( V_12 , V_21 -> V_108 , V_21 -> V_41 ) ;
F_96 ( V_12 , V_21 -> V_109 , false ) ;
} else if ( V_21 -> V_110 ) {
F_99 ( L_2 ) ;
F_100 ( V_12 -> V_43 , V_21 -> V_111 , V_21 -> V_108 ) ;
F_96 ( V_12 , V_21 -> V_109 , V_21 -> V_112 ? false : true ) ;
if ( V_21 -> V_112 )
F_96 ( V_12 , V_21 -> V_113 , true ) ;
} else {
F_99 ( L_3 ) ;
F_101 ( V_12 -> V_43 , V_21 -> V_111 ) ;
F_96 ( V_12 , V_21 -> V_113 , true ) ;
}
F_97 ( V_21 ) ;
}
static void F_102 ( struct V_26 * V_21 )
{
unsigned long V_51 ;
struct V_12 * V_12 = V_21 -> V_12 ;
if ( V_21 -> V_107 ) {
F_96 ( V_12 , V_21 -> V_109 , false ) ;
F_39 ( V_12 , V_21 -> V_108 , V_21 -> V_41 ) ;
F_97 ( V_21 ) ;
return;
} else if ( V_21 -> V_110 ) {
if ( F_103 ( V_12 -> V_57 , V_21 -> V_41 ) ) {
F_99 ( L_4 ) ;
F_100 ( V_12 -> V_43 , V_21 -> V_111 ,
V_21 -> V_108 ) ;
if ( V_21 -> V_112 )
F_96 ( V_12 , V_21 -> V_113 , true ) ;
F_97 ( V_21 ) ;
return;
}
} else {
if ( F_104 ( V_12 -> V_57 , V_21 -> V_41 , V_21 -> V_111 ) ) {
F_99 ( L_5 ) ;
F_101 ( V_12 -> V_43 , V_21 -> V_111 ) ;
F_97 ( V_21 ) ;
return;
}
}
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_105 ( & V_21 -> V_114 , & V_12 -> V_115 ) ;
V_12 -> V_95 = true ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
}
static void F_106 ( struct V_26 * V_21 )
{
unsigned long V_51 ;
struct V_12 * V_12 = V_21 -> V_12 ;
if ( V_21 -> V_107 ) {
F_107 ( L_6 ) ;
return;
} else if ( V_21 -> V_110 ) {
F_96 ( V_12 , V_21 -> V_109 , V_21 -> V_112 ? false : true ) ;
if ( V_21 -> V_112 ) {
V_21 -> V_110 = false ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_105 ( & V_21 -> V_114 , & V_12 -> V_116 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
} else {
if ( V_21 -> V_117 )
F_101 ( V_12 -> V_43 , V_21 -> V_108 ) ;
F_97 ( V_21 ) ;
}
} else {
if ( V_21 -> V_118 )
F_96 ( V_12 , V_21 -> V_113 , true ) ;
else {
F_86 ( V_21 -> V_113 -> V_103 , 0 ) ;
F_96 ( V_12 , V_21 -> V_113 , false ) ;
}
F_39 ( V_12 , V_21 -> V_111 , V_21 -> V_41 ) ;
F_97 ( V_21 ) ;
}
}
static void F_108 ( int V_119 , unsigned long V_120 , void * V_121 )
{
unsigned long V_51 ;
struct V_26 * V_21 = (struct V_26 * ) V_121 ;
struct V_12 * V_12 = V_21 -> V_12 ;
if ( V_119 || V_120 )
V_21 -> V_98 = true ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_105 ( & V_21 -> V_114 , & V_12 -> V_122 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
F_11 ( V_12 ) ;
}
static void F_109 ( struct V_26 * V_21 )
{
int V_27 ;
struct V_123 V_124 , V_125 ;
struct V_12 * V_12 = V_21 -> V_12 ;
T_10 V_41 = F_34 ( V_21 -> V_41 ) ;
V_124 . V_83 = V_12 -> V_82 -> V_83 ;
V_124 . V_126 = V_12 -> V_50 ;
V_125 . V_83 = V_12 -> V_86 -> V_83 ;
V_125 . V_127 = V_41 * V_12 -> V_50 ;
V_125 . V_126 = V_12 -> V_50 ;
if ( V_21 -> V_107 || V_21 -> V_110 ) {
V_124 . V_127 = F_27 ( V_21 -> V_108 ) * V_12 -> V_50 ;
V_27 = F_110 ( V_12 -> V_128 , & V_125 , 1 , & V_124 , 0 , F_108 , V_21 ) ;
} else {
V_124 . V_127 = F_27 ( V_21 -> V_111 ) * V_12 -> V_50 ;
V_27 = F_110 ( V_12 -> V_128 , & V_124 , 1 , & V_125 , 0 , F_108 , V_21 ) ;
}
if ( V_27 < 0 ) {
F_111 ( L_7 ) ;
F_98 ( V_21 ) ;
}
}
static void F_112 ( struct V_8 * V_8 , int V_98 )
{
struct V_26 * V_21 = V_8 -> V_10 ;
struct V_12 * V_12 = V_21 -> V_12 ;
T_1 V_87 = F_66 ( V_12 ) ;
struct V_75 * V_77 = F_67 ( V_8 , V_87 ) ;
unsigned long V_51 ;
F_9 ( & V_77 -> V_99 , V_8 ) ;
if ( V_98 )
V_21 -> V_98 = true ;
V_21 -> V_118 = false ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_105 ( & V_21 -> V_114 , & V_12 -> V_122 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
F_11 ( V_12 ) ;
}
static void F_113 ( struct V_26 * V_21 , struct V_8 * V_8 )
{
T_1 V_87 = F_66 ( V_21 -> V_12 ) ;
struct V_75 * V_77 = F_67 ( V_8 , V_87 ) ;
F_8 ( & V_77 -> V_99 , V_8 , F_112 , V_21 ) ;
F_77 ( V_21 -> V_12 , V_8 , V_21 -> V_111 , V_21 -> V_41 ) ;
F_82 ( V_8 ) ;
}
static bool F_114 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
return ( F_76 ( V_8 ) == V_93 ) &&
( V_8 -> V_85 . V_129 == ( V_12 -> V_50 << V_130 ) ) ;
}
static void F_115 ( struct V_26 * V_21 )
{
F_10 ( & V_21 -> V_12 -> V_52 . V_131 ) ;
F_102 ( V_21 ) ;
}
static void F_116 ( struct V_26 * V_21 )
{
bool V_132 ;
struct V_12 * V_12 = V_21 -> V_12 ;
if ( V_21 -> V_107 || V_21 -> V_110 )
V_132 = ! F_32 ( V_12 , V_21 -> V_41 ) ||
F_56 ( V_12 , V_21 -> V_108 ) ;
else {
struct V_8 * V_8 = V_21 -> V_113 -> V_103 ;
V_132 = F_56 ( V_12 , V_21 -> V_111 ) ;
if ( ! V_132 && F_114 ( V_12 , V_8 ) ) {
F_113 ( V_21 , V_8 ) ;
return;
}
}
V_132 ? F_115 ( V_21 ) : F_109 ( V_21 ) ;
}
static void F_117 ( struct V_26 * V_21 )
{
if ( V_21 -> V_98 )
F_98 ( V_21 ) ;
else
F_102 ( V_21 ) ;
}
static void F_118 ( struct V_12 * V_12 , struct V_133 * V_134 ,
void (* F_119)( struct V_26 * ) )
{
unsigned long V_51 ;
struct V_133 V_114 ;
struct V_26 * V_21 , * V_135 ;
F_120 ( & V_114 ) ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_121 ( V_134 , & V_114 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
F_122 (mg, tmp, &list, list)
F_119 ( V_21 ) ;
}
static void F_123 ( struct V_26 * V_21 )
{
F_105 ( & V_21 -> V_114 , & V_21 -> V_12 -> V_116 ) ;
}
static void F_124 ( struct V_26 * V_21 )
{
unsigned long V_51 ;
struct V_12 * V_12 = V_21 -> V_12 ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_123 ( V_21 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
F_11 ( V_12 ) ;
}
static void F_125 ( struct V_12 * V_12 , struct V_133 * V_136 )
{
unsigned long V_51 ;
struct V_26 * V_21 , * V_135 ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_122 (mg, tmp, work, list)
F_123 ( V_21 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
F_11 ( V_12 ) ;
}
static void F_126 ( struct V_12 * V_12 ,
struct V_75 * V_77 )
{
struct V_133 V_136 ;
if ( ! V_77 -> V_80 )
return;
F_120 ( & V_136 ) ;
if ( V_77 -> V_80 )
F_127 ( V_77 -> V_80 , & V_136 ) ;
if ( ! F_128 ( & V_136 ) )
F_125 ( V_12 , & V_136 ) ;
}
static void F_129 ( struct V_26 * V_21 )
{
if ( ! F_130 ( V_21 -> V_12 -> V_137 , & V_21 -> V_114 ) )
F_124 ( V_21 ) ;
}
static void V_112 ( struct V_12 * V_12 , struct V_19 * V_38 ,
T_3 V_28 , T_5 V_41 ,
struct V_15 * V_18 )
{
struct V_26 * V_21 = F_21 ( V_38 ) ;
V_21 -> V_98 = false ;
V_21 -> V_107 = false ;
V_21 -> V_110 = false ;
V_21 -> V_112 = true ;
V_21 -> V_118 = true ;
V_21 -> V_117 = false ;
V_21 -> V_12 = V_12 ;
V_21 -> V_111 = V_28 ;
V_21 -> V_41 = V_41 ;
V_21 -> V_109 = NULL ;
V_21 -> V_113 = V_18 ;
V_21 -> V_138 = V_139 ;
F_91 ( V_12 ) ;
F_129 ( V_21 ) ;
}
static void V_107 ( struct V_12 * V_12 , struct V_19 * V_38 ,
T_3 V_28 , T_5 V_41 ,
struct V_15 * V_18 )
{
struct V_26 * V_21 = F_21 ( V_38 ) ;
V_21 -> V_98 = false ;
V_21 -> V_107 = true ;
V_21 -> V_110 = false ;
V_21 -> V_112 = false ;
V_21 -> V_118 = true ;
V_21 -> V_117 = false ;
V_21 -> V_12 = V_12 ;
V_21 -> V_108 = V_28 ;
V_21 -> V_41 = V_41 ;
V_21 -> V_109 = V_18 ;
V_21 -> V_113 = NULL ;
V_21 -> V_138 = V_139 ;
F_91 ( V_12 ) ;
F_129 ( V_21 ) ;
}
static void F_131 ( struct V_12 * V_12 , struct V_19 * V_38 ,
T_3 V_108 , T_3 V_111 ,
T_5 V_41 ,
struct V_15 * V_109 ,
struct V_15 * V_113 )
{
struct V_26 * V_21 = F_21 ( V_38 ) ;
V_21 -> V_98 = false ;
V_21 -> V_107 = false ;
V_21 -> V_110 = true ;
V_21 -> V_112 = true ;
V_21 -> V_118 = true ;
V_21 -> V_117 = false ;
V_21 -> V_12 = V_12 ;
V_21 -> V_108 = V_108 ;
V_21 -> V_111 = V_111 ;
V_21 -> V_41 = V_41 ;
V_21 -> V_109 = V_109 ;
V_21 -> V_113 = V_113 ;
V_21 -> V_138 = V_139 ;
F_91 ( V_12 ) ;
F_129 ( V_21 ) ;
}
static void V_117 ( struct V_12 * V_12 , struct V_19 * V_38 ,
T_3 V_28 , T_5 V_41 ,
struct V_15 * V_18 )
{
struct V_26 * V_21 = F_21 ( V_38 ) ;
V_21 -> V_98 = false ;
V_21 -> V_107 = false ;
V_21 -> V_110 = true ;
V_21 -> V_112 = false ;
V_21 -> V_118 = true ;
V_21 -> V_117 = true ;
V_21 -> V_12 = V_12 ;
V_21 -> V_108 = V_28 ;
V_21 -> V_41 = V_41 ;
V_21 -> V_109 = V_18 ;
V_21 -> V_113 = NULL ;
V_21 -> V_138 = V_139 ;
F_91 ( V_12 ) ;
F_129 ( V_21 ) ;
}
static void F_132 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
unsigned long V_51 ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_83 ( & V_12 -> V_106 , V_8 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
F_11 ( V_12 ) ;
}
static void F_133 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
T_1 V_87 = F_66 ( V_12 ) ;
struct V_75 * V_77 = F_67 ( V_8 , V_87 ) ;
F_22 ( V_8 -> V_85 . V_129 ) ;
if ( ! V_77 -> V_79 )
F_71 ( V_12 , V_8 ) ;
else
F_72 ( V_12 , V_8 , 0 ) ;
F_81 ( V_12 , V_8 ) ;
}
static void F_134 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
T_7 V_140 = F_135 ( V_8 -> V_85 . V_84 ,
V_12 -> V_49 ) ;
T_7 V_141 = F_136 ( V_8 ) ;
T_7 V_39 ;
V_141 = F_44 ( V_141 , V_12 -> V_49 ) ;
for ( V_39 = V_140 ; V_39 < V_141 ; V_39 ++ )
F_48 ( V_12 , F_47 ( V_39 ) ) ;
F_86 ( V_8 , 0 ) ;
}
static bool F_137 ( struct V_12 * V_12 )
{
T_10 V_142 = ( F_61 ( & V_12 -> V_101 ) + 1 ) *
V_12 -> V_50 ;
return V_142 < V_12 -> V_143 ;
}
static void F_138 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
F_10 ( F_76 ( V_8 ) == V_144 ?
& V_12 -> V_52 . V_58 : & V_12 -> V_52 . V_62 ) ;
}
static void F_139 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
F_10 ( F_76 ( V_8 ) == V_144 ?
& V_12 -> V_52 . V_60 : & V_12 -> V_52 . V_64 ) ;
}
static void F_140 ( struct V_12 * V_12 , struct V_8 * V_8 ,
struct V_75 * V_77 ,
T_3 V_28 , T_5 V_41 )
{
V_77 -> V_80 = F_141 ( V_12 -> V_137 ) ;
F_77 ( V_12 , V_8 , V_28 , V_41 ) ;
F_81 ( V_12 , V_8 ) ;
}
static void F_142 ( struct V_12 * V_12 , struct V_19 * V_38 ,
struct V_8 * V_8 )
{
int V_27 ;
bool V_145 = true ;
T_3 V_33 = F_78 ( V_12 , V_8 ) ;
struct V_15 * V_34 , * V_109 , * V_113 ;
struct V_146 V_147 ;
T_1 V_87 = F_66 ( V_12 ) ;
struct V_75 * V_77 = F_67 ( V_8 , V_87 ) ;
bool V_148 = F_56 ( V_12 , V_33 ) ;
bool V_149 = F_65 ( & V_12 -> V_72 ) ;
bool V_150 = ! V_149 && ( V_148 || F_137 ( V_12 ) ) ;
V_34 = F_23 ( V_38 ) ;
V_27 = F_28 ( V_12 , V_33 , V_8 , V_34 ,
( T_4 ) F_25 ,
V_38 , & V_113 ) ;
if ( V_27 > 0 )
return;
V_27 = F_143 ( V_12 -> V_43 , V_33 , true , V_150 , V_148 ,
V_8 , & V_147 ) ;
if ( V_27 == - V_151 )
V_147 . V_152 = V_153 ;
switch ( V_147 . V_152 ) {
case V_154 :
if ( V_149 ) {
F_139 ( V_12 , V_8 ) ;
if ( F_76 ( V_8 ) == V_93 ) {
F_10 ( & V_12 -> V_52 . V_155 ) ;
V_117 ( V_12 , V_38 , V_33 , V_147 . V_41 , V_113 ) ;
V_145 = false ;
} else {
V_77 -> V_80 = F_141 ( V_12 -> V_137 ) ;
F_75 ( V_12 , V_8 , V_33 ) ;
F_81 ( V_12 , V_8 ) ;
}
} else {
F_138 ( V_12 , V_8 ) ;
if ( F_76 ( V_8 ) == V_93 &&
F_63 ( & V_12 -> V_72 ) &&
! F_32 ( V_12 , V_147 . V_41 ) ) {
V_77 -> V_80 = F_141 ( V_12 -> V_137 ) ;
F_88 ( V_12 , V_8 , V_33 , V_147 . V_41 ) ;
F_81 ( V_12 , V_8 ) ;
} else
F_140 ( V_12 , V_8 , V_77 , V_33 , V_147 . V_41 ) ;
}
break;
case V_153 :
F_139 ( V_12 , V_8 ) ;
V_77 -> V_80 = F_141 ( V_12 -> V_137 ) ;
F_75 ( V_12 , V_8 , V_33 ) ;
F_81 ( V_12 , V_8 ) ;
break;
case V_156 :
F_10 ( & V_12 -> V_52 . V_157 ) ;
V_112 ( V_12 , V_38 , V_33 , V_147 . V_41 , V_113 ) ;
V_145 = false ;
break;
case V_158 :
V_34 = F_23 ( V_38 ) ;
V_27 = F_28 ( V_12 , V_147 . V_108 , V_8 , V_34 ,
( T_4 ) F_25 ,
V_38 , & V_109 ) ;
if ( V_27 > 0 ) {
F_100 ( V_12 -> V_43 , V_33 ,
V_147 . V_108 ) ;
F_10 ( & V_12 -> V_52 . V_159 ) ;
break;
}
F_10 ( & V_12 -> V_52 . V_155 ) ;
F_10 ( & V_12 -> V_52 . V_157 ) ;
F_131 ( V_12 , V_38 , V_147 . V_108 ,
V_33 , V_147 . V_41 ,
V_109 , V_113 ) ;
V_145 = false ;
break;
default:
F_111 ( L_8 , V_160 ,
( unsigned ) V_147 . V_152 ) ;
F_144 ( V_8 ) ;
}
if ( V_145 )
F_96 ( V_12 , V_113 , false ) ;
}
static int F_145 ( struct V_12 * V_12 )
{
return V_139 < V_12 -> V_161 ||
V_139 > V_12 -> V_161 + V_162 ;
}
static int F_146 ( struct V_12 * V_12 )
{
int V_27 = 0 ;
if ( ( V_12 -> V_95 || F_145 ( V_12 ) ) &&
F_147 ( V_12 -> V_57 ) ) {
F_10 ( & V_12 -> V_52 . V_163 ) ;
V_12 -> V_95 = false ;
V_27 = F_148 ( V_12 -> V_57 , false ) ;
V_12 -> V_161 = V_139 ;
}
return V_27 ;
}
static void F_149 ( struct V_12 * V_12 )
{
unsigned long V_51 ;
struct V_164 V_165 ;
struct V_8 * V_8 ;
struct V_19 V_38 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
F_150 ( & V_165 ) ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_151 ( & V_165 , & V_12 -> V_106 ) ;
F_150 ( & V_12 -> V_106 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
while ( ! F_152 ( & V_165 ) ) {
if ( F_17 ( V_12 , & V_38 ) ) {
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_151 ( & V_12 -> V_106 , & V_165 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
break;
}
V_8 = F_153 ( & V_165 ) ;
if ( V_8 -> V_89 & V_91 )
F_133 ( V_12 , V_8 ) ;
else if ( V_8 -> V_89 & V_92 )
F_134 ( V_12 , V_8 ) ;
else
F_142 ( V_12 , & V_38 , V_8 ) ;
}
F_19 ( V_12 , & V_38 ) ;
}
static void F_154 ( struct V_12 * V_12 , bool V_166 )
{
unsigned long V_51 ;
struct V_164 V_165 ;
struct V_8 * V_8 ;
F_150 ( & V_165 ) ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_151 ( & V_165 , & V_12 -> V_96 ) ;
F_150 ( & V_12 -> V_96 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
while ( ( V_8 = F_153 ( & V_165 ) ) )
V_166 ? F_82 ( V_8 ) : F_144 ( V_8 ) ;
}
static void F_155 ( struct V_12 * V_12 )
{
unsigned long V_51 ;
struct V_164 V_165 ;
struct V_8 * V_8 ;
F_150 ( & V_165 ) ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
F_151 ( & V_165 , & V_12 -> V_97 ) ;
F_150 ( & V_12 -> V_97 ) ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
while ( ( V_8 = F_153 ( & V_165 ) ) )
F_82 ( V_8 ) ;
}
static void F_156 ( struct V_12 * V_12 )
{
int V_27 = 0 ;
T_3 V_28 ;
T_5 V_41 ;
struct V_19 V_38 ;
struct V_15 * V_109 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
while ( F_137 ( V_12 ) ) {
if ( F_17 ( V_12 , & V_38 ) )
break;
V_27 = F_157 ( V_12 -> V_43 , & V_28 , & V_41 ) ;
if ( V_27 )
break;
V_27 = F_30 ( V_12 , V_28 , & V_38 , & V_109 ) ;
if ( V_27 ) {
F_38 ( V_12 -> V_43 , V_28 ) ;
break;
}
V_107 ( V_12 , & V_38 , V_28 , V_41 , V_109 ) ;
}
F_19 ( V_12 , & V_38 ) ;
}
static void F_158 ( struct V_12 * V_12 , struct V_167 * V_168 )
{
int V_27 = 0 ;
T_11 V_169 = F_34 ( V_168 -> V_170 -> V_169 ) ;
T_11 V_171 = F_34 ( V_168 -> V_170 -> V_171 ) ;
while ( V_169 != V_171 ) {
V_27 = F_159 ( V_12 -> V_43 , F_37 ( V_169 ) ) ;
if ( ! V_27 ) {
V_27 = F_103 ( V_12 -> V_57 , F_37 ( V_169 ) ) ;
if ( V_27 )
break;
} else if ( V_27 == - V_172 ) {
V_27 = 0 ;
} else {
F_160 ( L_9 ) ;
break;
}
V_169 ++ ;
}
V_12 -> V_95 = true ;
V_168 -> V_98 = V_27 ;
F_59 ( & V_168 -> V_173 , 1 ) ;
F_94 ( & V_168 -> V_174 ) ;
}
static void F_161 ( struct V_12 * V_12 )
{
struct V_133 V_114 ;
struct V_167 * V_168 , * V_135 ;
F_120 ( & V_114 ) ;
F_162 ( & V_12 -> V_175 ) ;
F_121 ( & V_12 -> V_176 , & V_114 ) ;
F_163 ( & V_12 -> V_175 ) ;
F_122 (req, tmp, &list, list)
F_158 ( V_12 , V_168 ) ;
}
static bool F_164 ( struct V_12 * V_12 )
{
return F_61 ( & V_12 -> V_177 ) ;
}
static void F_165 ( struct V_12 * V_12 )
{
if ( F_164 ( V_12 ) ) {
F_10 ( & V_12 -> V_178 ) ;
F_94 ( & V_12 -> V_179 ) ;
}
}
static void F_166 ( struct V_12 * V_12 )
{
F_167 ( V_12 -> V_179 , F_61 ( & V_12 -> V_178 ) ) ;
}
static void F_168 ( struct V_12 * V_12 )
{
F_10 ( & V_12 -> V_177 ) ;
F_166 ( V_12 ) ;
}
static void F_169 ( struct V_12 * V_12 )
{
F_59 ( & V_12 -> V_177 , 0 ) ;
F_59 ( & V_12 -> V_178 , 0 ) ;
}
static void F_170 ( struct V_12 * V_12 )
{
F_167 ( V_12 -> V_102 , ! F_61 ( & V_12 -> V_101 ) ) ;
}
static void F_171 ( struct V_12 * V_12 )
{
F_172 ( & V_12 -> V_180 ) ;
F_173 ( V_12 -> V_13 ) ;
}
static void F_174 ( struct V_12 * V_12 )
{
struct V_8 * V_8 ;
struct V_164 V_165 ;
F_150 ( & V_165 ) ;
F_151 ( & V_165 , & V_12 -> V_106 ) ;
F_150 ( & V_12 -> V_106 ) ;
while ( ( V_8 = F_153 ( & V_165 ) ) )
F_86 ( V_8 , V_181 ) ;
}
static int F_175 ( struct V_12 * V_12 )
{
if ( F_164 ( V_12 ) )
return ! F_128 ( & V_12 -> V_116 ) ||
! F_128 ( & V_12 -> V_122 ) ||
! F_128 ( & V_12 -> V_115 ) ;
else
return ! F_152 ( & V_12 -> V_106 ) ||
! F_152 ( & V_12 -> V_96 ) ||
! F_152 ( & V_12 -> V_97 ) ||
! F_128 ( & V_12 -> V_116 ) ||
! F_128 ( & V_12 -> V_122 ) ||
! F_128 ( & V_12 -> V_115 ) ||
V_12 -> V_117 ;
}
static void F_176 ( struct V_182 * V_183 )
{
struct V_12 * V_12 = F_177 ( V_183 , struct V_12 , V_14 ) ;
do {
if ( ! F_164 ( V_12 ) ) {
F_156 ( V_12 ) ;
F_155 ( V_12 ) ;
F_149 ( V_12 ) ;
F_161 ( V_12 ) ;
}
F_118 ( V_12 , & V_12 -> V_116 , F_116 ) ;
F_118 ( V_12 , & V_12 -> V_122 , F_117 ) ;
if ( F_146 ( V_12 ) ) {
F_154 ( V_12 , false ) ;
} else {
F_154 ( V_12 , true ) ;
F_118 ( V_12 , & V_12 -> V_115 ,
F_106 ) ;
}
F_165 ( V_12 ) ;
} while ( F_175 ( V_12 ) );
}
static void F_178 ( struct V_182 * V_183 )
{
struct V_12 * V_12 = F_177 ( F_179 ( V_183 ) , struct V_12 , V_180 ) ;
F_180 ( V_12 -> V_43 ) ;
F_11 ( V_12 ) ;
F_181 ( V_12 -> V_13 , & V_12 -> V_180 , V_162 ) ;
}
static int F_182 ( struct V_184 * V_32 , int V_185 )
{
struct V_186 * V_187 = F_183 ( V_32 -> V_83 ) ;
return F_184 ( & V_187 -> V_188 , V_185 ) ;
}
static int F_185 ( struct V_189 * V_190 , int V_185 )
{
struct V_12 * V_12 = F_177 ( V_190 , struct V_12 , V_191 ) ;
return F_182 ( V_12 -> V_82 , V_185 ) ||
F_182 ( V_12 -> V_86 , V_185 ) ;
}
static void F_186 ( struct V_12 * V_12 )
{
unsigned V_192 ;
if ( V_12 -> V_193 )
F_20 ( V_12 -> V_193 , V_12 -> V_22 ) ;
if ( V_12 -> V_22 )
F_187 ( V_12 -> V_22 ) ;
if ( V_12 -> V_137 )
F_188 ( V_12 -> V_137 ) ;
if ( V_12 -> V_16 )
F_189 ( V_12 -> V_16 ) ;
if ( V_12 -> V_13 )
F_190 ( V_12 -> V_13 ) ;
if ( V_12 -> V_40 )
F_6 ( V_12 -> V_40 ) ;
if ( V_12 -> V_55 )
F_6 ( V_12 -> V_55 ) ;
if ( V_12 -> V_128 )
F_191 ( V_12 -> V_128 ) ;
if ( V_12 -> V_57 )
F_192 ( V_12 -> V_57 ) ;
if ( V_12 -> V_194 )
F_193 ( V_12 -> V_44 , V_12 -> V_194 ) ;
if ( V_12 -> V_82 )
F_193 ( V_12 -> V_44 , V_12 -> V_82 ) ;
if ( V_12 -> V_86 )
F_193 ( V_12 -> V_44 , V_12 -> V_86 ) ;
if ( V_12 -> V_43 )
F_194 ( V_12 -> V_43 ) ;
for ( V_192 = 0 ; V_192 < V_12 -> V_195 ; V_192 ++ )
F_195 ( V_12 -> V_196 [ V_192 ] ) ;
F_195 ( V_12 -> V_196 ) ;
F_195 ( V_12 ) ;
}
static void F_196 ( struct V_197 * V_44 )
{
struct V_12 * V_12 = V_44 -> V_198 ;
F_186 ( V_12 ) ;
}
static T_10 F_197 ( struct V_184 * V_32 )
{
return F_198 ( V_32 -> V_83 -> V_199 ) >> V_130 ;
}
static void F_199 ( struct V_200 * V_201 )
{
if ( V_201 -> V_194 )
F_193 ( V_201 -> V_44 , V_201 -> V_194 ) ;
if ( V_201 -> V_86 )
F_193 ( V_201 -> V_44 , V_201 -> V_86 ) ;
if ( V_201 -> V_82 )
F_193 ( V_201 -> V_44 , V_201 -> V_82 ) ;
F_195 ( V_201 ) ;
}
static bool F_200 ( struct V_202 * V_203 , char * * error )
{
if ( ! V_203 -> V_204 ) {
* error = L_10 ;
return false ;
}
return true ;
}
static int F_201 ( struct V_200 * V_201 , struct V_202 * V_203 ,
char * * error )
{
int V_27 ;
T_10 V_205 ;
char V_39 [ V_206 ] ;
if ( ! F_200 ( V_203 , error ) )
return - V_207 ;
V_27 = F_202 ( V_201 -> V_44 , F_203 ( V_203 ) , V_208 | V_209 ,
& V_201 -> V_194 ) ;
if ( V_27 ) {
* error = L_11 ;
return V_27 ;
}
V_205 = F_197 ( V_201 -> V_194 ) ;
if ( V_205 > V_210 )
F_107 ( L_12 ,
F_204 ( V_201 -> V_194 -> V_83 , V_39 ) , V_211 ) ;
return 0 ;
}
static int F_205 ( struct V_200 * V_201 , struct V_202 * V_203 ,
char * * error )
{
int V_27 ;
if ( ! F_200 ( V_203 , error ) )
return - V_207 ;
V_27 = F_202 ( V_201 -> V_44 , F_203 ( V_203 ) , V_208 | V_209 ,
& V_201 -> V_86 ) ;
if ( V_27 ) {
* error = L_13 ;
return V_27 ;
}
V_201 -> V_212 = F_197 ( V_201 -> V_86 ) ;
return 0 ;
}
static int F_206 ( struct V_200 * V_201 , struct V_202 * V_203 ,
char * * error )
{
int V_27 ;
if ( ! F_200 ( V_203 , error ) )
return - V_207 ;
V_27 = F_202 ( V_201 -> V_44 , F_203 ( V_203 ) , V_208 | V_209 ,
& V_201 -> V_82 ) ;
if ( V_27 ) {
* error = L_14 ;
return V_27 ;
}
V_201 -> V_213 = F_197 ( V_201 -> V_82 ) ;
if ( V_201 -> V_44 -> V_214 > V_201 -> V_213 ) {
* error = L_15 ;
return - V_207 ;
}
return 0 ;
}
static int F_207 ( struct V_200 * V_201 , struct V_202 * V_203 ,
char * * error )
{
unsigned long V_215 ;
if ( ! F_200 ( V_203 , error ) )
return - V_207 ;
if ( F_208 ( F_203 ( V_203 ) , 10 , & V_215 ) || ! V_215 ||
V_215 < V_216 ||
V_215 > V_217 ||
V_215 & ( V_216 - 1 ) ) {
* error = L_16 ;
return - V_207 ;
}
if ( V_215 > V_201 -> V_212 ) {
* error = L_17 ;
return - V_207 ;
}
V_201 -> V_215 = V_215 ;
return 0 ;
}
static void F_209 ( struct V_66 * V_218 )
{
V_218 -> V_219 = V_220 ;
V_218 -> V_68 = V_70 ;
}
static int F_210 ( struct V_200 * V_201 , struct V_202 * V_203 ,
char * * error )
{
static struct V_221 V_222 [] = {
{ 0 , 1 , L_18 } ,
} ;
int V_27 ;
unsigned V_204 ;
const char * V_223 ;
struct V_66 * V_218 = & V_201 -> V_72 ;
F_209 ( V_218 ) ;
V_27 = F_211 ( V_222 , V_203 , & V_204 , error ) ;
if ( V_27 )
return - V_207 ;
while ( V_204 -- ) {
V_223 = F_203 ( V_203 ) ;
if ( ! strcasecmp ( V_223 , L_19 ) )
V_218 -> V_68 = V_70 ;
else if ( ! strcasecmp ( V_223 , L_20 ) )
V_218 -> V_68 = V_69 ;
else if ( ! strcasecmp ( V_223 , L_21 ) )
V_218 -> V_68 = V_71 ;
else {
* error = L_22 ;
return - V_207 ;
}
}
return 0 ;
}
static int F_212 ( struct V_200 * V_201 , struct V_202 * V_203 ,
char * * error )
{
static struct V_221 V_222 [] = {
{ 0 , 1024 , L_23 } ,
} ;
int V_27 ;
if ( ! F_200 ( V_203 , error ) )
return - V_207 ;
V_201 -> V_224 = F_203 ( V_203 ) ;
V_27 = F_211 ( V_222 , V_203 , & V_201 -> V_225 , error ) ;
if ( V_27 )
return - V_207 ;
V_201 -> V_226 = ( const char * * ) V_203 -> V_227 ;
F_213 ( V_203 , V_201 -> V_225 ) ;
return 0 ;
}
static int F_214 ( struct V_200 * V_201 , int V_204 , char * * V_227 ,
char * * error )
{
int V_27 ;
struct V_202 V_203 ;
V_203 . V_204 = V_204 ;
V_203 . V_227 = V_227 ;
V_27 = F_201 ( V_201 , & V_203 , error ) ;
if ( V_27 )
return V_27 ;
V_27 = F_205 ( V_201 , & V_203 , error ) ;
if ( V_27 )
return V_27 ;
V_27 = F_206 ( V_201 , & V_203 , error ) ;
if ( V_27 )
return V_27 ;
V_27 = F_207 ( V_201 , & V_203 , error ) ;
if ( V_27 )
return V_27 ;
V_27 = F_210 ( V_201 , & V_203 , error ) ;
if ( V_27 )
return V_27 ;
V_27 = F_212 ( V_201 , & V_203 , error ) ;
if ( V_27 )
return V_27 ;
return 0 ;
}
static int F_215 ( struct V_12 * V_12 , const char * V_30 , const char * V_228 )
{
unsigned long V_135 ;
if ( ! strcasecmp ( V_30 , L_24 ) ) {
if ( F_208 ( V_228 , 10 , & V_135 ) )
return - V_207 ;
V_12 -> V_143 = V_135 ;
return 0 ;
}
return V_229 ;
}
static int F_216 ( struct V_12 * V_12 , const char * V_30 , const char * V_228 )
{
int V_27 = F_215 ( V_12 , V_30 , V_228 ) ;
if ( V_27 == V_229 )
V_27 = F_217 ( V_12 -> V_43 , V_30 , V_228 ) ;
if ( V_27 )
F_107 ( L_25 , V_30 , V_228 ) ;
return V_27 ;
}
static int F_218 ( struct V_12 * V_12 , int V_204 , const char * * V_227 )
{
int V_27 = 0 ;
if ( V_204 & 1 ) {
F_107 ( L_26 ) ;
return - V_207 ;
}
while ( V_204 ) {
V_27 = F_216 ( V_12 , V_227 [ 0 ] , V_227 [ 1 ] ) ;
if ( V_27 )
break;
V_204 -= 2 ;
V_227 += 2 ;
}
return V_27 ;
}
static int F_219 ( struct V_12 * V_12 , struct V_200 * V_201 ,
char * * error )
{
struct V_230 * V_20 = F_220 ( V_201 -> V_224 ,
V_12 -> V_231 ,
V_12 -> V_213 ,
V_12 -> V_50 ) ;
if ( F_221 ( V_20 ) ) {
* error = L_27 ;
return F_222 ( V_20 ) ;
}
V_12 -> V_43 = V_20 ;
return 0 ;
}
static bool F_223 ( T_10 V_49 ,
T_10 V_232 )
{
( void ) F_73 ( V_232 , V_49 ) ;
return V_232 > V_233 ;
}
static T_10 F_224 ( T_10 V_234 ,
T_10 V_232 )
{
T_10 V_49 ;
V_49 = F_225 ( V_234 ) ;
if ( V_232 )
while ( F_223 ( V_49 , V_232 ) )
V_49 *= 2 ;
return V_49 ;
}
static int F_226 ( struct V_200 * V_201 , struct V_12 * * V_235 )
{
int V_27 = 0 ;
char * * error = & V_201 -> V_44 -> error ;
struct V_12 * V_12 ;
struct V_197 * V_44 = V_201 -> V_44 ;
T_7 V_236 ;
struct V_237 * V_57 ;
bool V_238 = V_201 -> V_72 . V_219 == V_220 ;
V_12 = F_227 ( sizeof( * V_12 ) , V_239 ) ;
if ( ! V_12 )
return - V_23 ;
V_12 -> V_44 = V_201 -> V_44 ;
V_44 -> V_198 = V_12 ;
V_44 -> V_240 = 2 ;
V_44 -> V_241 = true ;
V_44 -> V_242 = 1 ;
V_44 -> V_243 = true ;
V_44 -> V_244 = true ;
V_12 -> V_72 = V_201 -> V_72 ;
V_44 -> V_245 = F_66 ( V_12 ) ;
V_12 -> V_191 . V_246 = F_185 ;
F_228 ( V_44 -> V_45 , & V_12 -> V_191 ) ;
V_12 -> V_194 = V_201 -> V_194 ;
V_12 -> V_82 = V_201 -> V_82 ;
V_12 -> V_86 = V_201 -> V_86 ;
V_201 -> V_194 = V_201 -> V_82 = V_201 -> V_86 = NULL ;
V_236 = V_12 -> V_213 = V_201 -> V_213 ;
V_236 = F_44 ( V_236 , V_201 -> V_215 ) ;
V_12 -> V_236 = F_79 ( V_236 ) ;
V_12 -> V_50 = V_201 -> V_215 ;
if ( F_229 ( V_44 , V_12 -> V_50 ) ) {
V_27 = - V_207 ;
goto V_247;
}
if ( V_201 -> V_215 & ( V_201 -> V_215 - 1 ) ) {
T_7 V_231 = V_201 -> V_212 ;
V_12 -> V_46 = - 1 ;
V_231 = F_44 ( V_231 , V_201 -> V_215 ) ;
V_12 -> V_231 = F_37 ( V_231 ) ;
} else {
V_12 -> V_46 = F_230 ( V_201 -> V_215 ) ;
V_12 -> V_231 = F_37 ( V_201 -> V_212 >> V_12 -> V_46 ) ;
}
V_27 = F_219 ( V_12 , V_201 , error ) ;
if ( V_27 )
goto V_247;
V_12 -> V_248 = V_201 -> V_225 ;
V_12 -> V_143 = V_249 ;
V_27 = F_218 ( V_12 , V_201 -> V_225 , V_201 -> V_226 ) ;
if ( V_27 ) {
* error = L_28 ;
goto V_247;
}
V_57 = F_231 ( V_12 -> V_194 -> V_83 ,
V_201 -> V_215 , V_238 ,
F_232 ( V_12 -> V_43 ) ) ;
if ( F_221 ( V_57 ) ) {
* error = L_29 ;
V_27 = F_222 ( V_57 ) ;
goto V_247;
}
V_12 -> V_57 = V_57 ;
if ( F_65 ( & V_12 -> V_72 ) ) {
bool V_250 ;
V_27 = F_233 ( V_12 -> V_57 , & V_250 ) ;
if ( V_27 ) {
* error = L_30 ;
goto V_247;
}
if ( ! V_250 ) {
* error = L_31 ;
V_27 = - V_207 ;
goto V_247;
}
}
F_234 ( & V_12 -> V_54 ) ;
F_150 ( & V_12 -> V_106 ) ;
F_150 ( & V_12 -> V_96 ) ;
F_150 ( & V_12 -> V_97 ) ;
F_120 ( & V_12 -> V_116 ) ;
F_120 ( & V_12 -> V_122 ) ;
F_120 ( & V_12 -> V_115 ) ;
F_59 ( & V_12 -> V_101 , 0 ) ;
F_235 ( & V_12 -> V_102 ) ;
F_235 ( & V_12 -> V_179 ) ;
F_59 ( & V_12 -> V_177 , 0 ) ;
F_59 ( & V_12 -> V_178 , 0 ) ;
V_27 = - V_23 ;
V_12 -> V_42 = 0 ;
V_12 -> V_40 = F_3 ( F_34 ( V_12 -> V_231 ) ) ;
if ( ! V_12 -> V_40 ) {
* error = L_32 ;
goto V_247;
}
F_5 ( V_12 -> V_40 , F_34 ( V_12 -> V_231 ) ) ;
V_12 -> V_49 =
F_224 ( V_12 -> V_50 ,
V_12 -> V_213 ) ;
V_12 -> V_251 = F_46 ( V_12 , V_12 -> V_236 ) ;
V_12 -> V_55 = F_3 ( F_51 ( V_12 -> V_251 ) ) ;
if ( ! V_12 -> V_55 ) {
* error = L_33 ;
goto V_247;
}
F_5 ( V_12 -> V_55 , F_51 ( V_12 -> V_251 ) ) ;
V_12 -> V_128 = F_236 ( & V_252 ) ;
if ( F_221 ( V_12 -> V_128 ) ) {
* error = L_34 ;
V_27 = F_222 ( V_12 -> V_128 ) ;
goto V_247;
}
V_12 -> V_13 = F_237 ( L_35 V_253 , V_254 ) ;
if ( ! V_12 -> V_13 ) {
* error = L_36 ;
goto V_247;
}
F_238 ( & V_12 -> V_14 , F_176 ) ;
F_239 ( & V_12 -> V_180 , F_178 ) ;
V_12 -> V_161 = V_139 ;
V_12 -> V_16 = F_240 ( V_255 ) ;
if ( ! V_12 -> V_16 ) {
* error = L_37 ;
goto V_247;
}
V_12 -> V_137 = F_241 () ;
if ( ! V_12 -> V_137 ) {
* error = L_38 ;
goto V_247;
}
V_12 -> V_22 = F_242 ( V_256 ,
V_257 ) ;
if ( ! V_12 -> V_22 ) {
* error = L_39 ;
goto V_247;
}
V_12 -> V_193 = NULL ;
V_12 -> V_88 = true ;
V_12 -> V_258 = false ;
V_12 -> V_117 = false ;
V_12 -> V_95 = false ;
V_12 -> V_259 = false ;
V_12 -> V_260 = false ;
F_57 ( V_12 ) ;
F_59 ( & V_12 -> V_52 . V_155 , 0 ) ;
F_59 ( & V_12 -> V_52 . V_157 , 0 ) ;
F_59 ( & V_12 -> V_52 . V_131 , 0 ) ;
F_59 ( & V_12 -> V_52 . V_159 , 0 ) ;
F_59 ( & V_12 -> V_52 . V_163 , 0 ) ;
F_59 ( & V_12 -> V_52 . V_53 , 0 ) ;
F_234 ( & V_12 -> V_175 ) ;
F_120 ( & V_12 -> V_176 ) ;
* V_235 = V_12 ;
return 0 ;
V_247:
F_186 ( V_12 ) ;
return V_27 ;
}
static int F_243 ( struct V_12 * V_12 , int V_204 , const char * * V_227 )
{
unsigned V_192 ;
const char * * V_261 ;
V_261 = F_244 ( V_204 , sizeof( * V_261 ) , V_239 ) ;
if ( ! V_261 )
return - V_23 ;
for ( V_192 = 0 ; V_192 < V_204 ; V_192 ++ ) {
V_261 [ V_192 ] = F_245 ( V_227 [ V_192 ] , V_239 ) ;
if ( ! V_261 [ V_192 ] ) {
while ( V_192 -- )
F_195 ( V_261 [ V_192 ] ) ;
F_195 ( V_261 ) ;
return - V_23 ;
}
}
V_12 -> V_195 = V_204 ;
V_12 -> V_196 = V_261 ;
return 0 ;
}
static int F_246 ( struct V_197 * V_44 , unsigned V_204 , char * * V_227 )
{
int V_27 = - V_207 ;
struct V_200 * V_201 ;
struct V_12 * V_12 = NULL ;
V_201 = F_227 ( sizeof( * V_201 ) , V_239 ) ;
if ( ! V_201 ) {
V_44 -> error = L_40 ;
return - V_23 ;
}
V_201 -> V_44 = V_44 ;
V_27 = F_214 ( V_201 , V_204 , V_227 , & V_44 -> error ) ;
if ( V_27 )
goto V_262;
V_27 = F_226 ( V_201 , & V_12 ) ;
if ( V_27 )
goto V_262;
V_27 = F_243 ( V_12 , V_204 - 3 , ( const char * * ) V_227 + 3 ) ;
if ( V_27 ) {
F_186 ( V_12 ) ;
goto V_262;
}
V_44 -> V_198 = V_12 ;
V_262:
F_199 ( V_201 ) ;
return V_27 ;
}
static int F_247 ( struct V_197 * V_44 , struct V_8 * V_8 )
{
struct V_12 * V_12 = V_44 -> V_198 ;
int V_27 ;
T_3 V_33 = F_78 ( V_12 , V_8 ) ;
T_1 V_87 = F_66 ( V_12 ) ;
bool V_150 = false ;
bool V_148 ;
struct V_15 * V_18 ;
struct V_146 V_147 ;
struct V_75 * V_77 = F_69 ( V_8 , V_87 ) ;
if ( F_248 ( F_27 ( V_33 ) >= F_27 ( V_12 -> V_236 ) ) ) {
F_71 ( V_12 , V_8 ) ;
return V_263 ;
}
if ( V_8 -> V_89 & ( V_91 | V_90 | V_92 ) ) {
F_132 ( V_12 , V_8 ) ;
return V_264 ;
}
V_18 = F_13 ( V_12 ) ;
if ( ! V_18 ) {
F_132 ( V_12 , V_8 ) ;
return V_264 ;
}
V_27 = F_28 ( V_12 , V_33 , V_8 , V_18 ,
( T_4 ) F_15 ,
V_12 , & V_18 ) ;
if ( V_27 ) {
if ( V_27 < 0 )
F_132 ( V_12 , V_8 ) ;
return V_264 ;
}
V_148 = F_56 ( V_12 , V_33 ) ;
V_27 = F_143 ( V_12 -> V_43 , V_33 , false , V_150 , V_148 ,
V_8 , & V_147 ) ;
if ( V_27 == - V_151 ) {
F_96 ( V_12 , V_18 , true ) ;
return V_264 ;
} else if ( V_27 ) {
F_111 ( L_41 , V_27 ) ;
F_144 ( V_8 ) ;
return V_264 ;
}
V_27 = V_263 ;
switch ( V_147 . V_152 ) {
case V_154 :
if ( F_65 ( & V_12 -> V_72 ) ) {
if ( F_76 ( V_8 ) == V_93 ) {
F_96 ( V_12 , V_18 , true ) ;
V_27 = V_264 ;
} else {
V_77 -> V_80 = F_141 ( V_12 -> V_137 ) ;
F_139 ( V_12 , V_8 ) ;
F_75 ( V_12 , V_8 , V_33 ) ;
F_96 ( V_12 , V_18 , false ) ;
}
} else {
F_138 ( V_12 , V_8 ) ;
if ( F_76 ( V_8 ) == V_93 && F_63 ( & V_12 -> V_72 ) &&
! F_32 ( V_12 , V_147 . V_41 ) )
F_88 ( V_12 , V_8 , V_33 , V_147 . V_41 ) ;
else
F_77 ( V_12 , V_8 , V_33 , V_147 . V_41 ) ;
F_96 ( V_12 , V_18 , false ) ;
}
break;
case V_153 :
F_139 ( V_12 , V_8 ) ;
V_77 -> V_80 = F_141 ( V_12 -> V_137 ) ;
if ( V_77 -> V_79 != 0 ) {
F_86 ( V_8 , 0 ) ;
F_96 ( V_12 , V_18 , false ) ;
return V_264 ;
} else {
F_75 ( V_12 , V_8 , V_33 ) ;
F_96 ( V_12 , V_18 , false ) ;
}
break;
default:
F_111 ( L_42 , V_160 ,
( unsigned ) V_147 . V_152 ) ;
F_144 ( V_8 ) ;
V_27 = V_264 ;
}
return V_27 ;
}
static int F_249 ( struct V_197 * V_44 , struct V_8 * V_8 , int error )
{
struct V_12 * V_12 = V_44 -> V_198 ;
unsigned long V_51 ;
T_1 V_87 = F_66 ( V_12 ) ;
struct V_75 * V_77 = F_67 ( V_8 , V_87 ) ;
if ( V_77 -> V_78 ) {
F_180 ( V_12 -> V_43 ) ;
F_49 ( & V_12 -> V_54 , V_51 ) ;
V_12 -> V_88 = true ;
F_52 ( & V_12 -> V_54 , V_51 ) ;
}
F_126 ( V_12 , V_77 ) ;
return 0 ;
}
static int F_250 ( struct V_12 * V_12 )
{
unsigned V_192 , V_27 ;
for ( V_192 = 0 ; V_192 < F_34 ( V_12 -> V_231 ) ; V_192 ++ ) {
V_27 = F_251 ( V_12 -> V_57 , F_37 ( V_192 ) ,
F_32 ( V_12 , F_37 ( V_192 ) ) ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_252 ( struct V_12 * V_12 )
{
unsigned V_192 , V_27 ;
V_27 = F_253 ( V_12 -> V_57 , V_12 -> V_49 ,
V_12 -> V_251 ) ;
if ( V_27 ) {
F_160 ( L_43 ) ;
return V_27 ;
}
for ( V_192 = 0 ; V_192 < F_51 ( V_12 -> V_251 ) ; V_192 ++ ) {
V_27 = F_254 ( V_12 -> V_57 , F_47 ( V_192 ) ,
F_55 ( V_12 , F_47 ( V_192 ) ) ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_255 ( void * V_121 , T_5 V_41 , T_3 V_28 ,
T_8 V_265 )
{
struct V_12 * V_12 = V_121 ;
return F_256 ( V_12 -> V_57 , V_41 , V_265 ) ;
}
static int F_257 ( struct V_12 * V_12 )
{
int V_27 ;
V_27 = F_258 ( V_12 -> V_57 , V_12 -> V_43 ) ;
if ( V_27 ) {
F_160 ( L_44 ) ;
return V_27 ;
}
V_27 = F_259 ( V_12 -> V_43 , F_255 , V_12 ) ;
if ( V_27 )
F_160 ( L_45 ) ;
return V_27 ;
}
static bool F_260 ( struct V_12 * V_12 )
{
int V_266 , V_267 , V_268 , V_269 ;
V_266 = F_250 ( V_12 ) ;
if ( V_266 )
F_160 ( L_46 ) ;
V_267 = F_252 ( V_12 ) ;
if ( V_267 )
F_160 ( L_47 ) ;
F_60 ( V_12 ) ;
V_268 = F_257 ( V_12 ) ;
if ( V_268 )
F_160 ( L_48 ) ;
V_269 = F_148 ( V_12 -> V_57 , ! V_266 && ! V_267 && ! V_268 ) ;
if ( V_269 )
F_160 ( L_49 ) ;
return ! V_266 && ! V_267 && ! V_268 && ! V_269 ;
}
static void F_261 ( struct V_197 * V_44 )
{
struct V_12 * V_12 = V_44 -> V_198 ;
F_168 ( V_12 ) ;
F_170 ( V_12 ) ;
F_171 ( V_12 ) ;
F_174 ( V_12 ) ;
F_169 ( V_12 ) ;
( void ) F_260 ( V_12 ) ;
}
static int F_262 ( void * V_121 , T_3 V_28 , T_5 V_41 ,
bool V_270 , T_8 V_265 , bool V_271 )
{
int V_27 ;
struct V_12 * V_12 = V_121 ;
V_27 = F_263 ( V_12 -> V_43 , V_28 , V_41 , V_265 , V_271 ) ;
if ( V_27 )
return V_27 ;
if ( V_270 )
F_35 ( V_12 , V_28 , V_41 ) ;
else
F_39 ( V_12 , V_28 , V_41 ) ;
return 0 ;
}
static int F_264 ( void * V_121 , T_10 V_49 ,
T_9 V_272 , bool V_273 )
{
struct V_12 * V_12 = V_121 ;
if ( V_273 )
F_48 ( V_12 , V_272 ) ;
else
F_53 ( V_12 , V_272 ) ;
return 0 ;
}
static T_5 F_265 ( struct V_12 * V_12 )
{
T_10 V_274 = F_197 ( V_12 -> V_86 ) ;
( void ) F_73 ( V_274 , V_12 -> V_50 ) ;
return F_37 ( V_274 ) ;
}
static bool F_266 ( struct V_12 * V_12 , T_5 V_275 )
{
if ( F_34 ( V_275 ) > F_34 ( V_12 -> V_231 ) )
return true ;
while ( F_34 ( V_275 ) < F_34 ( V_12 -> V_231 ) ) {
V_275 = F_37 ( F_34 ( V_275 ) + 1 ) ;
if ( F_32 ( V_12 , V_275 ) ) {
F_160 ( L_50 ,
( unsigned long long ) F_34 ( V_275 ) ) ;
return false ;
}
}
return true ;
}
static int F_267 ( struct V_12 * V_12 , T_5 V_275 )
{
int V_27 ;
V_27 = F_268 ( V_12 -> V_57 , V_275 ) ;
if ( V_27 ) {
F_160 ( L_51 ) ;
return V_27 ;
}
V_12 -> V_231 = V_275 ;
return 0 ;
}
static int F_269 ( struct V_197 * V_44 )
{
int V_27 = 0 ;
struct V_12 * V_12 = V_44 -> V_198 ;
T_5 V_276 = F_265 ( V_12 ) ;
if ( ! V_12 -> V_258 ) {
V_27 = F_267 ( V_12 , V_276 ) ;
if ( V_27 )
return V_27 ;
V_12 -> V_258 = true ;
} else if ( V_276 != V_12 -> V_231 ) {
if ( ! F_266 ( V_12 , V_276 ) )
return - V_207 ;
V_27 = F_267 ( V_12 , V_276 ) ;
if ( V_27 )
return V_27 ;
}
if ( ! V_12 -> V_259 ) {
V_27 = F_270 ( V_12 -> V_57 , V_12 -> V_43 ,
F_262 , V_12 ) ;
if ( V_27 ) {
F_160 ( L_52 ) ;
return V_27 ;
}
V_12 -> V_259 = true ;
}
if ( ! V_12 -> V_260 ) {
V_27 = F_271 ( V_12 -> V_57 , F_264 , V_12 ) ;
if ( V_27 ) {
F_160 ( L_53 ) ;
return V_27 ;
}
V_12 -> V_260 = true ;
}
return V_27 ;
}
static void F_272 ( struct V_197 * V_44 )
{
struct V_12 * V_12 = V_44 -> V_198 ;
V_12 -> V_88 = true ;
F_178 ( & V_12 -> V_180 . V_136 ) ;
}
static void F_273 ( struct V_197 * V_44 , T_12 type ,
unsigned V_277 , char * V_235 , unsigned V_278 )
{
int V_27 = 0 ;
unsigned V_192 ;
T_13 V_279 = 0 ;
T_7 V_280 = 0 ;
T_7 V_281 = 0 ;
char V_282 [ V_206 ] ;
struct V_12 * V_12 = V_44 -> V_198 ;
T_5 V_283 ;
switch ( type ) {
case V_284 :
if ( ! ( V_277 & V_285 ) && ! F_274 ( V_44 ) ) {
V_27 = F_148 ( V_12 -> V_57 , false ) ;
if ( V_27 )
F_160 ( L_54 ) ;
}
V_27 = F_275 ( V_12 -> V_57 ,
& V_280 ) ;
if ( V_27 ) {
F_160 ( L_55 ) ;
goto V_98;
}
V_27 = F_276 ( V_12 -> V_57 , & V_281 ) ;
if ( V_27 ) {
F_160 ( L_56 ) ;
goto V_98;
}
V_283 = F_277 ( V_12 -> V_43 ) ;
F_278 ( L_57 ,
( unsigned ) ( V_286 >> V_130 ) ,
( unsigned long long ) ( V_281 - V_280 ) ,
( unsigned long long ) V_281 ,
V_12 -> V_50 ,
( unsigned long long ) F_34 ( V_283 ) ,
( unsigned long long ) F_34 ( V_12 -> V_231 ) ,
( unsigned ) F_61 ( & V_12 -> V_52 . V_58 ) ,
( unsigned ) F_61 ( & V_12 -> V_52 . V_60 ) ,
( unsigned ) F_61 ( & V_12 -> V_52 . V_62 ) ,
( unsigned ) F_61 ( & V_12 -> V_52 . V_64 ) ,
( unsigned ) F_61 ( & V_12 -> V_52 . V_155 ) ,
( unsigned ) F_61 ( & V_12 -> V_52 . V_157 ) ,
( unsigned long long ) F_34 ( V_12 -> V_42 ) ) ;
if ( F_63 ( & V_12 -> V_72 ) )
F_278 ( L_58 ) ;
else if ( F_65 ( & V_12 -> V_72 ) )
F_278 ( L_59 ) ;
else if ( F_64 ( & V_12 -> V_72 ) )
F_278 ( L_60 ) ;
else {
F_160 ( L_61 , ( int ) V_12 -> V_72 . V_68 ) ;
goto V_98;
}
F_278 ( L_62 , ( unsigned long long ) V_12 -> V_143 ) ;
F_278 ( L_63 , F_279 ( V_12 -> V_43 ) ) ;
if ( V_279 < V_278 ) {
V_27 = F_280 ( V_12 -> V_43 , V_235 + V_279 , V_278 - V_279 ) ;
if ( V_27 )
F_160 ( L_64 , V_27 ) ;
}
break;
case V_287 :
F_281 ( V_282 , V_12 -> V_194 -> V_83 -> V_288 ) ;
F_278 ( L_63 , V_282 ) ;
F_281 ( V_282 , V_12 -> V_86 -> V_83 -> V_288 ) ;
F_278 ( L_63 , V_282 ) ;
F_281 ( V_282 , V_12 -> V_82 -> V_83 -> V_288 ) ;
F_278 ( L_65 , V_282 ) ;
for ( V_192 = 0 ; V_192 < V_12 -> V_195 - 1 ; V_192 ++ )
F_278 ( L_66 , V_12 -> V_196 [ V_192 ] ) ;
if ( V_12 -> V_195 )
F_278 ( L_66 , V_12 -> V_196 [ V_12 -> V_195 - 1 ] ) ;
}
return;
V_98:
F_278 ( L_67 ) ;
}
static int F_282 ( struct V_12 * V_12 , const char * V_289 ,
struct V_290 * V_235 )
{
char V_291 ;
T_11 V_39 , V_292 ;
int V_27 ;
V_27 = sscanf ( V_289 , L_68 , & V_39 , & V_292 , & V_291 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_27 == 2 ) {
V_235 -> V_169 = F_37 ( V_39 ) ;
V_235 -> V_171 = F_37 ( V_292 ) ;
return 0 ;
}
V_27 = sscanf ( V_289 , L_69 , & V_39 , & V_291 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_27 == 1 ) {
V_235 -> V_169 = F_37 ( V_39 ) ;
V_235 -> V_171 = F_37 ( F_34 ( V_235 -> V_169 ) + 1u ) ;
return 0 ;
}
F_160 ( L_70 , V_289 ) ;
return - V_207 ;
}
static int F_283 ( struct V_12 * V_12 , struct V_290 * V_293 )
{
T_11 V_39 = F_34 ( V_293 -> V_169 ) ;
T_11 V_292 = F_34 ( V_293 -> V_171 ) ;
T_11 V_47 = F_34 ( V_12 -> V_231 ) ;
if ( V_39 >= V_47 ) {
F_160 ( L_71 , V_39 , V_47 ) ;
return - V_207 ;
}
if ( V_292 > V_47 ) {
F_160 ( L_72 , V_292 , V_47 ) ;
return - V_207 ;
}
if ( V_39 >= V_292 ) {
F_160 ( L_73 , V_39 , V_292 ) ;
return - V_207 ;
}
return 0 ;
}
static int F_284 ( struct V_12 * V_12 , struct V_290 * V_293 )
{
struct V_167 V_168 ;
F_120 ( & V_168 . V_114 ) ;
V_168 . V_170 = V_293 ;
F_59 ( & V_168 . V_173 , 0 ) ;
V_168 . V_98 = 0 ;
F_235 ( & V_168 . V_174 ) ;
F_162 ( & V_12 -> V_175 ) ;
F_285 ( & V_168 . V_114 , & V_12 -> V_176 ) ;
F_163 ( & V_12 -> V_175 ) ;
F_11 ( V_12 ) ;
F_167 ( V_168 . V_174 , F_61 ( & V_168 . V_173 ) ) ;
return V_168 . V_98 ;
}
static int F_286 ( struct V_12 * V_12 , unsigned V_126 ,
const char * * V_294 )
{
int V_27 = 0 ;
unsigned V_192 ;
struct V_290 V_293 ;
if ( ! F_65 ( & V_12 -> V_72 ) ) {
F_160 ( L_74 ) ;
return - V_295 ;
}
for ( V_192 = 0 ; V_192 < V_126 ; V_192 ++ ) {
V_27 = F_282 ( V_12 , V_294 [ V_192 ] , & V_293 ) ;
if ( V_27 )
break;
V_27 = F_283 ( V_12 , & V_293 ) ;
if ( V_27 )
break;
V_27 = F_284 ( V_12 , & V_293 ) ;
if ( V_27 )
break;
}
return V_27 ;
}
static int F_287 ( struct V_197 * V_44 , unsigned V_204 , char * * V_227 )
{
struct V_12 * V_12 = V_44 -> V_198 ;
if ( ! V_204 )
return - V_207 ;
if ( ! strcasecmp ( V_227 [ 0 ] , L_75 ) )
return F_286 ( V_12 , V_204 - 1 , ( const char * * ) V_227 + 1 ) ;
if ( V_204 != 2 )
return - V_207 ;
return F_216 ( V_12 , V_227 [ 0 ] , V_227 [ 1 ] ) ;
}
static int F_288 ( struct V_197 * V_44 ,
T_14 F_119 , void * V_296 )
{
int V_27 = 0 ;
struct V_12 * V_12 = V_44 -> V_198 ;
V_27 = F_119 ( V_44 , V_12 -> V_86 , 0 , F_197 ( V_12 -> V_86 ) , V_296 ) ;
if ( ! V_27 )
V_27 = F_119 ( V_44 , V_12 -> V_82 , 0 , V_44 -> V_214 , V_296 ) ;
return V_27 ;
}
static int F_289 ( struct V_197 * V_44 ,
struct V_297 * V_298 ,
struct V_299 * V_300 , int V_301 )
{
struct V_12 * V_12 = V_44 -> V_198 ;
struct V_186 * V_187 = F_183 ( V_12 -> V_82 -> V_83 ) ;
if ( ! V_187 -> V_302 )
return V_301 ;
V_298 -> V_81 = V_12 -> V_82 -> V_83 ;
return F_290 ( V_301 , V_187 -> V_302 ( V_187 , V_298 , V_300 ) ) ;
}
static void F_291 ( struct V_12 * V_12 , struct V_303 * V_304 )
{
V_304 -> V_305 = V_12 -> V_49 * 1024 ;
V_304 -> V_306 = V_12 -> V_49 << V_130 ;
}
static void F_292 ( struct V_197 * V_44 , struct V_303 * V_304 )
{
struct V_12 * V_12 = V_44 -> V_198 ;
T_11 V_307 = V_304 -> V_308 >> V_130 ;
if ( V_307 < V_12 -> V_50 ||
F_45 ( V_307 , V_12 -> V_50 ) ) {
F_293 ( V_304 , 0 ) ;
F_294 ( V_304 , V_12 -> V_50 << V_130 ) ;
}
F_291 ( V_12 , V_304 ) ;
}
static int T_15 F_295 ( void )
{
int V_27 ;
V_27 = F_296 ( & V_309 ) ;
if ( V_27 ) {
F_160 ( L_76 , V_27 ) ;
return V_27 ;
}
V_257 = F_297 ( V_26 , 0 ) ;
if ( ! V_257 ) {
F_298 ( & V_309 ) ;
return - V_23 ;
}
return 0 ;
}
static void T_16 F_299 ( void )
{
F_298 ( & V_309 ) ;
F_300 ( V_257 ) ;
}
