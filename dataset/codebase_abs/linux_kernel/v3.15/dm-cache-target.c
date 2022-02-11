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
static void F_46 ( struct V_12 * V_12 , T_3 V_39 )
{
unsigned long V_48 ;
F_10 ( & V_12 -> V_49 . V_50 ) ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_48 ( F_27 ( V_39 ) , V_12 -> V_52 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
}
static void F_50 ( struct V_12 * V_12 , T_3 V_39 )
{
unsigned long V_48 ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_51 ( F_27 ( V_39 ) , V_12 -> V_52 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
}
static bool F_52 ( struct V_12 * V_12 , T_3 V_39 )
{
int V_27 ;
unsigned long V_48 ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
V_27 = F_33 ( F_27 ( V_39 ) , V_12 -> V_52 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
return V_27 ;
}
static bool F_53 ( struct V_12 * V_12 , T_3 V_39 )
{
int V_27 ;
unsigned long V_48 ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
V_27 = F_33 ( F_27 ( V_39 ) , V_12 -> V_52 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
return V_27 ;
}
static void F_54 ( struct V_12 * V_12 )
{
struct V_53 V_49 ;
F_55 ( V_12 -> V_54 , & V_49 ) ;
F_56 ( & V_12 -> V_49 . V_55 , V_49 . V_56 ) ;
F_56 ( & V_12 -> V_49 . V_57 , V_49 . V_58 ) ;
F_56 ( & V_12 -> V_49 . V_59 , V_49 . V_60 ) ;
F_56 ( & V_12 -> V_49 . V_61 , V_49 . V_62 ) ;
}
static void F_57 ( struct V_12 * V_12 )
{
struct V_53 V_49 ;
V_49 . V_56 = F_58 ( & V_12 -> V_49 . V_55 ) ;
V_49 . V_58 = F_58 ( & V_12 -> V_49 . V_57 ) ;
V_49 . V_60 = F_58 ( & V_12 -> V_49 . V_59 ) ;
V_49 . V_62 = F_58 ( & V_12 -> V_49 . V_61 ) ;
F_59 ( V_12 -> V_54 , & V_49 ) ;
}
static bool F_60 ( struct V_63 * V_64 )
{
return V_64 -> V_65 == V_66 ;
}
static bool F_61 ( struct V_63 * V_64 )
{
return V_64 -> V_65 == V_67 ;
}
static bool F_62 ( struct V_63 * V_64 )
{
return V_64 -> V_65 == V_68 ;
}
static T_1 F_63 ( struct V_12 * V_12 )
{
return F_60 ( & V_12 -> V_69 ) ? V_70 : V_71 ;
}
static struct V_72 * F_64 ( struct V_8 * V_8 , T_1 V_73 )
{
struct V_72 * V_74 = F_65 ( V_8 , V_73 ) ;
F_22 ( ! V_74 ) ;
return V_74 ;
}
static struct V_72 * F_66 ( struct V_8 * V_8 , T_1 V_73 )
{
struct V_72 * V_74 = F_64 ( V_8 , V_73 ) ;
V_74 -> V_75 = false ;
V_74 -> V_76 = F_67 ( V_8 ) ;
V_74 -> V_77 = NULL ;
return V_74 ;
}
static void F_68 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
V_8 -> V_78 = V_12 -> V_79 -> V_80 ;
}
static void F_69 ( struct V_12 * V_12 , struct V_8 * V_8 ,
T_5 V_41 )
{
T_9 V_81 = V_8 -> V_82 . V_81 ;
T_9 V_33 = F_34 ( V_41 ) ;
V_8 -> V_78 = V_12 -> V_83 -> V_80 ;
if ( ! F_43 ( V_12 ) )
V_8 -> V_82 . V_81 =
( V_33 * V_12 -> V_84 ) +
F_70 ( V_81 , V_12 -> V_84 ) ;
else
V_8 -> V_82 . V_81 =
( V_33 << V_12 -> V_46 ) |
( V_81 & ( V_12 -> V_84 - 1 ) ) ;
}
static void F_71 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
unsigned long V_48 ;
T_1 V_85 = F_63 ( V_12 ) ;
struct V_72 * V_74 = F_64 ( V_8 , V_85 ) ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
if ( V_12 -> V_86 &&
! ( V_8 -> V_87 & ( V_88 | V_89 | V_90 ) ) ) {
V_74 -> V_75 = true ;
V_12 -> V_86 = false ;
}
F_49 ( & V_12 -> V_51 , V_48 ) ;
}
static void F_72 ( struct V_12 * V_12 , struct V_8 * V_8 ,
T_3 V_28 )
{
F_71 ( V_12 , V_8 ) ;
F_68 ( V_12 , V_8 ) ;
if ( F_73 ( V_8 ) == V_91 )
F_50 ( V_12 , V_28 ) ;
}
static void F_74 ( struct V_12 * V_12 , struct V_8 * V_8 ,
T_3 V_28 , T_5 V_41 )
{
F_71 ( V_12 , V_8 ) ;
F_69 ( V_12 , V_8 , V_41 ) ;
if ( F_73 ( V_8 ) == V_91 ) {
F_35 ( V_12 , V_28 , V_41 ) ;
F_50 ( V_12 , V_28 ) ;
}
}
static T_3 F_75 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
T_9 V_92 = V_8 -> V_82 . V_81 ;
if ( ! F_43 ( V_12 ) )
( void ) F_70 ( V_92 , V_12 -> V_84 ) ;
else
V_92 >>= V_12 -> V_46 ;
return F_76 ( V_92 ) ;
}
static int F_77 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
return V_8 -> V_87 & ( V_89 | V_88 ) ;
}
static void F_78 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
unsigned long V_48 ;
if ( ! F_77 ( V_12 , V_8 ) ) {
F_79 ( V_8 ) ;
return;
}
F_47 ( & V_12 -> V_51 , V_48 ) ;
V_12 -> V_93 = true ;
F_80 ( & V_12 -> V_94 , V_8 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
}
static void F_81 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
unsigned long V_48 ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_80 ( & V_12 -> V_95 , V_8 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
F_11 ( V_12 ) ;
}
static void F_82 ( struct V_8 * V_8 , int V_96 )
{
struct V_72 * V_74 = F_64 ( V_8 , V_70 ) ;
F_9 ( & V_74 -> V_97 , V_8 ) ;
if ( V_96 ) {
F_83 ( V_8 , V_96 ) ;
return;
}
F_84 ( & V_74 -> V_98 , V_8 ) ;
F_69 ( V_74 -> V_12 , V_8 , V_74 -> V_41 ) ;
F_81 ( V_74 -> V_12 , V_8 ) ;
}
static void F_85 ( struct V_12 * V_12 , struct V_8 * V_8 ,
T_3 V_28 , T_5 V_41 )
{
struct V_72 * V_74 = F_64 ( V_8 , V_70 ) ;
V_74 -> V_12 = V_12 ;
V_74 -> V_41 = V_41 ;
F_8 ( & V_74 -> V_97 , V_8 , F_82 , NULL ) ;
F_86 ( & V_74 -> V_98 , V_8 ) ;
F_72 ( V_74 -> V_12 , V_8 , V_28 ) ;
}
static void F_87 ( struct V_26 * V_21 )
{
F_20 ( V_21 , V_21 -> V_12 -> V_22 ) ;
}
static void F_88 ( struct V_12 * V_12 )
{
F_10 ( & V_12 -> V_99 ) ;
}
static void F_89 ( struct V_12 * V_12 )
{
F_90 ( & V_12 -> V_99 ) ;
F_91 ( & V_12 -> V_100 ) ;
}
static void F_92 ( struct V_12 * V_12 , struct V_15 * V_18 ,
bool V_101 )
{
( V_101 ? V_102 : V_103 )
( V_12 -> V_16 , V_18 , & V_12 -> V_104 ) ;
F_15 ( V_12 , V_18 ) ;
}
static void F_93 ( struct V_12 * V_12 , struct V_15 * V_18 ,
bool V_101 )
{
unsigned long V_48 ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_92 ( V_12 , V_18 , V_101 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
F_11 ( V_12 ) ;
}
static void F_94 ( struct V_26 * V_21 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
F_87 ( V_21 ) ;
F_89 ( V_12 ) ;
}
static void F_95 ( struct V_26 * V_21 )
{
struct V_12 * V_12 = V_21 -> V_12 ;
if ( V_21 -> V_105 ) {
F_96 ( L_1 ) ;
F_35 ( V_12 , V_21 -> V_106 , V_21 -> V_41 ) ;
F_93 ( V_12 , V_21 -> V_107 , false ) ;
} else if ( V_21 -> V_108 ) {
F_96 ( L_2 ) ;
F_97 ( V_12 -> V_43 , V_21 -> V_109 , V_21 -> V_106 ) ;
F_93 ( V_12 , V_21 -> V_107 , V_21 -> V_110 ? false : true ) ;
if ( V_21 -> V_110 )
F_93 ( V_12 , V_21 -> V_111 , true ) ;
} else {
F_96 ( L_3 ) ;
F_98 ( V_12 -> V_43 , V_21 -> V_109 ) ;
F_93 ( V_12 , V_21 -> V_111 , true ) ;
}
F_94 ( V_21 ) ;
}
static void F_99 ( struct V_26 * V_21 )
{
unsigned long V_48 ;
struct V_12 * V_12 = V_21 -> V_12 ;
if ( V_21 -> V_105 ) {
F_93 ( V_12 , V_21 -> V_107 , false ) ;
F_39 ( V_12 , V_21 -> V_106 , V_21 -> V_41 ) ;
F_94 ( V_21 ) ;
return;
} else if ( V_21 -> V_108 ) {
if ( F_100 ( V_12 -> V_54 , V_21 -> V_41 ) ) {
F_96 ( L_4 ) ;
F_97 ( V_12 -> V_43 , V_21 -> V_109 ,
V_21 -> V_106 ) ;
if ( V_21 -> V_110 )
F_93 ( V_12 , V_21 -> V_111 , true ) ;
F_94 ( V_21 ) ;
return;
}
} else {
if ( F_101 ( V_12 -> V_54 , V_21 -> V_41 , V_21 -> V_109 ) ) {
F_96 ( L_5 ) ;
F_98 ( V_12 -> V_43 , V_21 -> V_109 ) ;
F_94 ( V_21 ) ;
return;
}
}
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_102 ( & V_21 -> V_112 , & V_12 -> V_113 ) ;
V_12 -> V_93 = true ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
}
static void F_103 ( struct V_26 * V_21 )
{
unsigned long V_48 ;
struct V_12 * V_12 = V_21 -> V_12 ;
if ( V_21 -> V_105 ) {
F_104 ( L_6 ) ;
return;
} else if ( V_21 -> V_108 ) {
F_93 ( V_12 , V_21 -> V_107 , V_21 -> V_110 ? false : true ) ;
if ( V_21 -> V_110 ) {
V_21 -> V_108 = false ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_102 ( & V_21 -> V_112 , & V_12 -> V_114 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
} else {
if ( V_21 -> V_115 )
F_98 ( V_12 -> V_43 , V_21 -> V_106 ) ;
F_94 ( V_21 ) ;
}
} else {
if ( V_21 -> V_116 )
F_93 ( V_12 , V_21 -> V_111 , true ) ;
else {
F_83 ( V_21 -> V_111 -> V_101 , 0 ) ;
F_93 ( V_12 , V_21 -> V_111 , false ) ;
}
F_39 ( V_12 , V_21 -> V_109 , V_21 -> V_41 ) ;
F_94 ( V_21 ) ;
}
}
static void F_105 ( int V_117 , unsigned long V_118 , void * V_119 )
{
unsigned long V_48 ;
struct V_26 * V_21 = (struct V_26 * ) V_119 ;
struct V_12 * V_12 = V_21 -> V_12 ;
if ( V_117 || V_118 )
V_21 -> V_96 = true ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_102 ( & V_21 -> V_112 , & V_12 -> V_120 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
F_11 ( V_12 ) ;
}
static void F_106 ( struct V_26 * V_21 )
{
int V_27 ;
struct V_121 V_122 , V_123 ;
struct V_12 * V_12 = V_21 -> V_12 ;
T_9 V_41 = F_34 ( V_21 -> V_41 ) ;
V_122 . V_80 = V_12 -> V_79 -> V_80 ;
V_122 . V_124 = V_12 -> V_84 ;
V_123 . V_80 = V_12 -> V_83 -> V_80 ;
V_123 . V_125 = V_41 * V_12 -> V_84 ;
V_123 . V_124 = V_12 -> V_84 ;
if ( V_21 -> V_105 || V_21 -> V_108 ) {
V_122 . V_125 = F_27 ( V_21 -> V_106 ) * V_12 -> V_84 ;
V_27 = F_107 ( V_12 -> V_126 , & V_123 , 1 , & V_122 , 0 , F_105 , V_21 ) ;
} else {
V_122 . V_125 = F_27 ( V_21 -> V_109 ) * V_12 -> V_84 ;
V_27 = F_107 ( V_12 -> V_126 , & V_122 , 1 , & V_123 , 0 , F_105 , V_21 ) ;
}
if ( V_27 < 0 ) {
F_108 ( L_7 ) ;
F_95 ( V_21 ) ;
}
}
static void F_109 ( struct V_8 * V_8 , int V_96 )
{
struct V_26 * V_21 = V_8 -> V_10 ;
struct V_12 * V_12 = V_21 -> V_12 ;
T_1 V_85 = F_63 ( V_12 ) ;
struct V_72 * V_74 = F_64 ( V_8 , V_85 ) ;
unsigned long V_48 ;
F_9 ( & V_74 -> V_97 , V_8 ) ;
if ( V_96 )
V_21 -> V_96 = true ;
V_21 -> V_116 = false ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_102 ( & V_21 -> V_112 , & V_12 -> V_120 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
F_11 ( V_12 ) ;
}
static void F_110 ( struct V_26 * V_21 , struct V_8 * V_8 )
{
T_1 V_85 = F_63 ( V_21 -> V_12 ) ;
struct V_72 * V_74 = F_64 ( V_8 , V_85 ) ;
F_8 ( & V_74 -> V_97 , V_8 , F_109 , V_21 ) ;
F_74 ( V_21 -> V_12 , V_8 , V_21 -> V_109 , V_21 -> V_41 ) ;
F_79 ( V_8 ) ;
}
static bool F_111 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
return ( F_73 ( V_8 ) == V_91 ) &&
( V_8 -> V_82 . V_127 == ( V_12 -> V_84 << V_128 ) ) ;
}
static void F_112 ( struct V_26 * V_21 )
{
F_10 ( & V_21 -> V_12 -> V_49 . V_129 ) ;
F_99 ( V_21 ) ;
}
static void F_113 ( struct V_26 * V_21 )
{
bool V_130 ;
struct V_12 * V_12 = V_21 -> V_12 ;
if ( V_21 -> V_105 || V_21 -> V_108 )
V_130 = ! F_32 ( V_12 , V_21 -> V_41 ) ||
F_53 ( V_12 , V_21 -> V_106 ) ;
else {
struct V_8 * V_8 = V_21 -> V_111 -> V_101 ;
V_130 = F_53 ( V_12 , V_21 -> V_109 ) ;
if ( ! V_130 && F_111 ( V_12 , V_8 ) ) {
F_110 ( V_21 , V_8 ) ;
return;
}
}
V_130 ? F_112 ( V_21 ) : F_106 ( V_21 ) ;
}
static void F_114 ( struct V_26 * V_21 )
{
if ( V_21 -> V_96 )
F_95 ( V_21 ) ;
else
F_99 ( V_21 ) ;
}
static void F_115 ( struct V_12 * V_12 , struct V_131 * V_132 ,
void (* F_116)( struct V_26 * ) )
{
unsigned long V_48 ;
struct V_131 V_112 ;
struct V_26 * V_21 , * V_133 ;
F_117 ( & V_112 ) ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_118 ( V_132 , & V_112 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
F_119 (mg, tmp, &list, list)
F_116 ( V_21 ) ;
}
static void F_120 ( struct V_26 * V_21 )
{
F_102 ( & V_21 -> V_112 , & V_21 -> V_12 -> V_114 ) ;
}
static void F_121 ( struct V_26 * V_21 )
{
unsigned long V_48 ;
struct V_12 * V_12 = V_21 -> V_12 ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_120 ( V_21 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
F_11 ( V_12 ) ;
}
static void F_122 ( struct V_12 * V_12 , struct V_131 * V_134 )
{
unsigned long V_48 ;
struct V_26 * V_21 , * V_133 ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_119 (mg, tmp, work, list)
F_120 ( V_21 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
F_11 ( V_12 ) ;
}
static void F_123 ( struct V_12 * V_12 ,
struct V_72 * V_74 )
{
struct V_131 V_134 ;
if ( ! V_74 -> V_77 )
return;
F_117 ( & V_134 ) ;
if ( V_74 -> V_77 )
F_124 ( V_74 -> V_77 , & V_134 ) ;
if ( ! F_125 ( & V_134 ) )
F_122 ( V_12 , & V_134 ) ;
}
static void F_126 ( struct V_26 * V_21 )
{
if ( ! F_127 ( V_21 -> V_12 -> V_135 , & V_21 -> V_112 ) )
F_121 ( V_21 ) ;
}
static void V_110 ( struct V_12 * V_12 , struct V_19 * V_38 ,
T_3 V_28 , T_5 V_41 ,
struct V_15 * V_18 )
{
struct V_26 * V_21 = F_21 ( V_38 ) ;
V_21 -> V_96 = false ;
V_21 -> V_105 = false ;
V_21 -> V_108 = false ;
V_21 -> V_110 = true ;
V_21 -> V_116 = true ;
V_21 -> V_115 = false ;
V_21 -> V_12 = V_12 ;
V_21 -> V_109 = V_28 ;
V_21 -> V_41 = V_41 ;
V_21 -> V_107 = NULL ;
V_21 -> V_111 = V_18 ;
V_21 -> V_136 = V_137 ;
F_88 ( V_12 ) ;
F_126 ( V_21 ) ;
}
static void V_105 ( struct V_12 * V_12 , struct V_19 * V_38 ,
T_3 V_28 , T_5 V_41 ,
struct V_15 * V_18 )
{
struct V_26 * V_21 = F_21 ( V_38 ) ;
V_21 -> V_96 = false ;
V_21 -> V_105 = true ;
V_21 -> V_108 = false ;
V_21 -> V_110 = false ;
V_21 -> V_116 = true ;
V_21 -> V_115 = false ;
V_21 -> V_12 = V_12 ;
V_21 -> V_106 = V_28 ;
V_21 -> V_41 = V_41 ;
V_21 -> V_107 = V_18 ;
V_21 -> V_111 = NULL ;
V_21 -> V_136 = V_137 ;
F_88 ( V_12 ) ;
F_126 ( V_21 ) ;
}
static void F_128 ( struct V_12 * V_12 , struct V_19 * V_38 ,
T_3 V_106 , T_3 V_109 ,
T_5 V_41 ,
struct V_15 * V_107 ,
struct V_15 * V_111 )
{
struct V_26 * V_21 = F_21 ( V_38 ) ;
V_21 -> V_96 = false ;
V_21 -> V_105 = false ;
V_21 -> V_108 = true ;
V_21 -> V_110 = true ;
V_21 -> V_116 = true ;
V_21 -> V_115 = false ;
V_21 -> V_12 = V_12 ;
V_21 -> V_106 = V_106 ;
V_21 -> V_109 = V_109 ;
V_21 -> V_41 = V_41 ;
V_21 -> V_107 = V_107 ;
V_21 -> V_111 = V_111 ;
V_21 -> V_136 = V_137 ;
F_88 ( V_12 ) ;
F_126 ( V_21 ) ;
}
static void V_115 ( struct V_12 * V_12 , struct V_19 * V_38 ,
T_3 V_28 , T_5 V_41 ,
struct V_15 * V_18 )
{
struct V_26 * V_21 = F_21 ( V_38 ) ;
V_21 -> V_96 = false ;
V_21 -> V_105 = false ;
V_21 -> V_108 = true ;
V_21 -> V_110 = false ;
V_21 -> V_116 = true ;
V_21 -> V_115 = true ;
V_21 -> V_12 = V_12 ;
V_21 -> V_106 = V_28 ;
V_21 -> V_41 = V_41 ;
V_21 -> V_107 = V_18 ;
V_21 -> V_111 = NULL ;
V_21 -> V_136 = V_137 ;
F_88 ( V_12 ) ;
F_126 ( V_21 ) ;
}
static void F_129 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
unsigned long V_48 ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_80 ( & V_12 -> V_104 , V_8 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
F_11 ( V_12 ) ;
}
static void F_130 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
T_1 V_85 = F_63 ( V_12 ) ;
struct V_72 * V_74 = F_64 ( V_8 , V_85 ) ;
F_22 ( V_8 -> V_82 . V_127 ) ;
if ( ! V_74 -> V_76 )
F_68 ( V_12 , V_8 ) ;
else
F_69 ( V_12 , V_8 , 0 ) ;
F_78 ( V_12 , V_8 ) ;
}
static void F_131 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
T_7 V_138 = F_132 ( V_8 -> V_82 . V_81 ,
V_12 -> V_84 ) ;
T_7 V_139 = F_133 ( V_8 ) ;
T_7 V_39 ;
V_139 = F_44 ( V_139 , V_12 -> V_84 ) ;
for ( V_39 = V_138 ; V_39 < V_139 ; V_39 ++ )
F_46 ( V_12 , F_76 ( V_39 ) ) ;
F_83 ( V_8 , 0 ) ;
}
static bool F_134 ( struct V_12 * V_12 )
{
T_9 V_140 = ( F_58 ( & V_12 -> V_99 ) + 1 ) *
V_12 -> V_84 ;
return V_140 < V_12 -> V_141 ;
}
static void F_135 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
F_10 ( F_73 ( V_8 ) == V_142 ?
& V_12 -> V_49 . V_55 : & V_12 -> V_49 . V_59 ) ;
}
static void F_136 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
F_10 ( F_73 ( V_8 ) == V_142 ?
& V_12 -> V_49 . V_57 : & V_12 -> V_49 . V_61 ) ;
}
static void F_137 ( struct V_12 * V_12 , struct V_8 * V_8 ,
struct V_72 * V_74 ,
T_3 V_28 , T_5 V_41 )
{
V_74 -> V_77 = F_138 ( V_12 -> V_135 ) ;
F_74 ( V_12 , V_8 , V_28 , V_41 ) ;
F_78 ( V_12 , V_8 ) ;
}
static void F_139 ( struct V_12 * V_12 , struct V_19 * V_38 ,
struct V_8 * V_8 )
{
int V_27 ;
bool V_143 = true ;
T_3 V_33 = F_75 ( V_12 , V_8 ) ;
struct V_15 * V_34 , * V_107 , * V_111 ;
struct V_144 V_145 ;
T_1 V_85 = F_63 ( V_12 ) ;
struct V_72 * V_74 = F_64 ( V_8 , V_85 ) ;
bool V_146 = F_53 ( V_12 , V_33 ) ;
bool V_147 = F_62 ( & V_12 -> V_69 ) ;
bool V_148 = ! V_147 && ( V_146 || F_134 ( V_12 ) ) ;
V_34 = F_23 ( V_38 ) ;
V_27 = F_28 ( V_12 , V_33 , V_8 , V_34 ,
( T_4 ) F_25 ,
V_38 , & V_111 ) ;
if ( V_27 > 0 )
return;
V_27 = F_140 ( V_12 -> V_43 , V_33 , true , V_148 , V_146 ,
V_8 , & V_145 ) ;
if ( V_27 == - V_149 )
V_145 . V_150 = V_151 ;
switch ( V_145 . V_150 ) {
case V_152 :
if ( V_147 ) {
F_136 ( V_12 , V_8 ) ;
if ( F_73 ( V_8 ) == V_91 ) {
F_10 ( & V_12 -> V_49 . V_153 ) ;
V_115 ( V_12 , V_38 , V_33 , V_145 . V_41 , V_111 ) ;
V_143 = false ;
} else {
V_74 -> V_77 = F_138 ( V_12 -> V_135 ) ;
F_72 ( V_12 , V_8 , V_33 ) ;
F_78 ( V_12 , V_8 ) ;
}
} else {
F_135 ( V_12 , V_8 ) ;
if ( F_73 ( V_8 ) == V_91 &&
F_60 ( & V_12 -> V_69 ) &&
! F_32 ( V_12 , V_145 . V_41 ) ) {
V_74 -> V_77 = F_138 ( V_12 -> V_135 ) ;
F_85 ( V_12 , V_8 , V_33 , V_145 . V_41 ) ;
F_78 ( V_12 , V_8 ) ;
} else
F_137 ( V_12 , V_8 , V_74 , V_33 , V_145 . V_41 ) ;
}
break;
case V_151 :
F_136 ( V_12 , V_8 ) ;
V_74 -> V_77 = F_138 ( V_12 -> V_135 ) ;
F_72 ( V_12 , V_8 , V_33 ) ;
F_78 ( V_12 , V_8 ) ;
break;
case V_154 :
F_10 ( & V_12 -> V_49 . V_155 ) ;
V_110 ( V_12 , V_38 , V_33 , V_145 . V_41 , V_111 ) ;
V_143 = false ;
break;
case V_156 :
V_34 = F_23 ( V_38 ) ;
V_27 = F_28 ( V_12 , V_145 . V_106 , V_8 , V_34 ,
( T_4 ) F_25 ,
V_38 , & V_107 ) ;
if ( V_27 > 0 ) {
F_97 ( V_12 -> V_43 , V_33 ,
V_145 . V_106 ) ;
F_10 ( & V_12 -> V_49 . V_157 ) ;
break;
}
F_10 ( & V_12 -> V_49 . V_153 ) ;
F_10 ( & V_12 -> V_49 . V_155 ) ;
F_128 ( V_12 , V_38 , V_145 . V_106 ,
V_33 , V_145 . V_41 ,
V_107 , V_111 ) ;
V_143 = false ;
break;
default:
F_108 ( L_8 , V_158 ,
( unsigned ) V_145 . V_150 ) ;
F_141 ( V_8 ) ;
}
if ( V_143 )
F_93 ( V_12 , V_111 , false ) ;
}
static int F_142 ( struct V_12 * V_12 )
{
return V_137 < V_12 -> V_159 ||
V_137 > V_12 -> V_159 + V_160 ;
}
static int F_143 ( struct V_12 * V_12 )
{
int V_27 = 0 ;
if ( ( V_12 -> V_93 || F_142 ( V_12 ) ) &&
F_144 ( V_12 -> V_54 ) ) {
F_10 ( & V_12 -> V_49 . V_161 ) ;
V_12 -> V_93 = false ;
V_27 = F_145 ( V_12 -> V_54 , false ) ;
V_12 -> V_159 = V_137 ;
}
return V_27 ;
}
static void F_146 ( struct V_12 * V_12 )
{
unsigned long V_48 ;
struct V_162 V_163 ;
struct V_8 * V_8 ;
struct V_19 V_38 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
F_147 ( & V_163 ) ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_148 ( & V_163 , & V_12 -> V_104 ) ;
F_147 ( & V_12 -> V_104 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
while ( ! F_149 ( & V_163 ) ) {
if ( F_17 ( V_12 , & V_38 ) ) {
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_148 ( & V_12 -> V_104 , & V_163 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
break;
}
V_8 = F_150 ( & V_163 ) ;
if ( V_8 -> V_87 & V_89 )
F_130 ( V_12 , V_8 ) ;
else if ( V_8 -> V_87 & V_90 )
F_131 ( V_12 , V_8 ) ;
else
F_139 ( V_12 , & V_38 , V_8 ) ;
}
F_19 ( V_12 , & V_38 ) ;
}
static void F_151 ( struct V_12 * V_12 , bool V_164 )
{
unsigned long V_48 ;
struct V_162 V_163 ;
struct V_8 * V_8 ;
F_147 ( & V_163 ) ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_148 ( & V_163 , & V_12 -> V_94 ) ;
F_147 ( & V_12 -> V_94 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
while ( ( V_8 = F_150 ( & V_163 ) ) )
V_164 ? F_79 ( V_8 ) : F_141 ( V_8 ) ;
}
static void F_152 ( struct V_12 * V_12 )
{
unsigned long V_48 ;
struct V_162 V_163 ;
struct V_8 * V_8 ;
F_147 ( & V_163 ) ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
F_148 ( & V_163 , & V_12 -> V_95 ) ;
F_147 ( & V_12 -> V_95 ) ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
while ( ( V_8 = F_150 ( & V_163 ) ) )
F_79 ( V_8 ) ;
}
static void F_153 ( struct V_12 * V_12 )
{
int V_27 = 0 ;
T_3 V_28 ;
T_5 V_41 ;
struct V_19 V_38 ;
struct V_15 * V_107 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
while ( F_134 ( V_12 ) ) {
if ( F_17 ( V_12 , & V_38 ) )
break;
V_27 = F_154 ( V_12 -> V_43 , & V_28 , & V_41 ) ;
if ( V_27 )
break;
V_27 = F_30 ( V_12 , V_28 , & V_38 , & V_107 ) ;
if ( V_27 ) {
F_38 ( V_12 -> V_43 , V_28 ) ;
break;
}
V_105 ( V_12 , & V_38 , V_28 , V_41 , V_107 ) ;
}
F_19 ( V_12 , & V_38 ) ;
}
static void F_155 ( struct V_12 * V_12 , struct V_165 * V_166 )
{
int V_27 = 0 ;
T_10 V_167 = F_34 ( V_166 -> V_168 -> V_167 ) ;
T_10 V_169 = F_34 ( V_166 -> V_168 -> V_169 ) ;
while ( V_167 != V_169 ) {
V_27 = F_156 ( V_12 -> V_43 , F_37 ( V_167 ) ) ;
if ( ! V_27 ) {
V_27 = F_100 ( V_12 -> V_54 , F_37 ( V_167 ) ) ;
if ( V_27 )
break;
} else if ( V_27 == - V_170 ) {
V_27 = 0 ;
} else {
F_157 ( L_9 ) ;
break;
}
V_167 ++ ;
}
V_12 -> V_93 = true ;
V_166 -> V_96 = V_27 ;
F_56 ( & V_166 -> V_171 , 1 ) ;
F_91 ( & V_166 -> V_172 ) ;
}
static void F_158 ( struct V_12 * V_12 )
{
struct V_131 V_112 ;
struct V_165 * V_166 , * V_133 ;
F_117 ( & V_112 ) ;
F_159 ( & V_12 -> V_173 ) ;
F_118 ( & V_12 -> V_174 , & V_112 ) ;
F_160 ( & V_12 -> V_173 ) ;
F_119 (req, tmp, &list, list)
F_155 ( V_12 , V_166 ) ;
}
static bool F_161 ( struct V_12 * V_12 )
{
return F_58 ( & V_12 -> V_175 ) ;
}
static void F_162 ( struct V_12 * V_12 )
{
if ( F_161 ( V_12 ) ) {
F_10 ( & V_12 -> V_176 ) ;
F_91 ( & V_12 -> V_177 ) ;
}
}
static void F_163 ( struct V_12 * V_12 )
{
F_164 ( V_12 -> V_177 , F_58 ( & V_12 -> V_176 ) ) ;
}
static void F_165 ( struct V_12 * V_12 )
{
F_10 ( & V_12 -> V_175 ) ;
F_163 ( V_12 ) ;
}
static void F_166 ( struct V_12 * V_12 )
{
F_56 ( & V_12 -> V_175 , 0 ) ;
F_56 ( & V_12 -> V_176 , 0 ) ;
}
static void F_167 ( struct V_12 * V_12 )
{
F_164 ( V_12 -> V_100 , ! F_58 ( & V_12 -> V_99 ) ) ;
}
static void F_168 ( struct V_12 * V_12 )
{
F_169 ( & V_12 -> V_178 ) ;
F_170 ( V_12 -> V_13 ) ;
}
static void F_171 ( struct V_12 * V_12 )
{
struct V_8 * V_8 ;
struct V_162 V_163 ;
F_147 ( & V_163 ) ;
F_148 ( & V_163 , & V_12 -> V_104 ) ;
F_147 ( & V_12 -> V_104 ) ;
while ( ( V_8 = F_150 ( & V_163 ) ) )
F_83 ( V_8 , V_179 ) ;
}
static int F_172 ( struct V_12 * V_12 )
{
if ( F_161 ( V_12 ) )
return ! F_125 ( & V_12 -> V_114 ) ||
! F_125 ( & V_12 -> V_120 ) ||
! F_125 ( & V_12 -> V_113 ) ;
else
return ! F_149 ( & V_12 -> V_104 ) ||
! F_149 ( & V_12 -> V_94 ) ||
! F_149 ( & V_12 -> V_95 ) ||
! F_125 ( & V_12 -> V_114 ) ||
! F_125 ( & V_12 -> V_120 ) ||
! F_125 ( & V_12 -> V_113 ) ||
V_12 -> V_115 ;
}
static void F_173 ( struct V_180 * V_181 )
{
struct V_12 * V_12 = F_174 ( V_181 , struct V_12 , V_14 ) ;
do {
if ( ! F_161 ( V_12 ) ) {
F_153 ( V_12 ) ;
F_152 ( V_12 ) ;
F_146 ( V_12 ) ;
F_158 ( V_12 ) ;
}
F_115 ( V_12 , & V_12 -> V_114 , F_113 ) ;
F_115 ( V_12 , & V_12 -> V_120 , F_114 ) ;
if ( F_143 ( V_12 ) ) {
F_151 ( V_12 , false ) ;
} else {
F_151 ( V_12 , true ) ;
F_115 ( V_12 , & V_12 -> V_113 ,
F_103 ) ;
}
F_162 ( V_12 ) ;
} while ( F_172 ( V_12 ) );
}
static void F_175 ( struct V_180 * V_181 )
{
struct V_12 * V_12 = F_174 ( F_176 ( V_181 ) , struct V_12 , V_178 ) ;
F_177 ( V_12 -> V_43 ) ;
F_11 ( V_12 ) ;
F_178 ( V_12 -> V_13 , & V_12 -> V_178 , V_160 ) ;
}
static int F_179 ( struct V_182 * V_32 , int V_183 )
{
struct V_184 * V_185 = F_180 ( V_32 -> V_80 ) ;
return F_181 ( & V_185 -> V_186 , V_183 ) ;
}
static int F_182 ( struct V_187 * V_188 , int V_183 )
{
struct V_12 * V_12 = F_174 ( V_188 , struct V_12 , V_189 ) ;
return F_179 ( V_12 -> V_79 , V_183 ) ||
F_179 ( V_12 -> V_83 , V_183 ) ;
}
static void F_183 ( struct V_12 * V_12 )
{
unsigned V_190 ;
if ( V_12 -> V_191 )
F_20 ( V_12 -> V_191 , V_12 -> V_22 ) ;
if ( V_12 -> V_22 )
F_184 ( V_12 -> V_22 ) ;
if ( V_12 -> V_135 )
F_185 ( V_12 -> V_135 ) ;
if ( V_12 -> V_16 )
F_186 ( V_12 -> V_16 ) ;
if ( V_12 -> V_13 )
F_187 ( V_12 -> V_13 ) ;
if ( V_12 -> V_40 )
F_6 ( V_12 -> V_40 ) ;
if ( V_12 -> V_52 )
F_6 ( V_12 -> V_52 ) ;
if ( V_12 -> V_126 )
F_188 ( V_12 -> V_126 ) ;
if ( V_12 -> V_54 )
F_189 ( V_12 -> V_54 ) ;
if ( V_12 -> V_192 )
F_190 ( V_12 -> V_44 , V_12 -> V_192 ) ;
if ( V_12 -> V_79 )
F_190 ( V_12 -> V_44 , V_12 -> V_79 ) ;
if ( V_12 -> V_83 )
F_190 ( V_12 -> V_44 , V_12 -> V_83 ) ;
if ( V_12 -> V_43 )
F_191 ( V_12 -> V_43 ) ;
for ( V_190 = 0 ; V_190 < V_12 -> V_193 ; V_190 ++ )
F_192 ( V_12 -> V_194 [ V_190 ] ) ;
F_192 ( V_12 -> V_194 ) ;
F_192 ( V_12 ) ;
}
static void F_193 ( struct V_195 * V_44 )
{
struct V_12 * V_12 = V_44 -> V_196 ;
F_183 ( V_12 ) ;
}
static T_9 F_194 ( struct V_182 * V_32 )
{
return F_195 ( V_32 -> V_80 -> V_197 ) >> V_128 ;
}
static void F_196 ( struct V_198 * V_199 )
{
if ( V_199 -> V_192 )
F_190 ( V_199 -> V_44 , V_199 -> V_192 ) ;
if ( V_199 -> V_83 )
F_190 ( V_199 -> V_44 , V_199 -> V_83 ) ;
if ( V_199 -> V_79 )
F_190 ( V_199 -> V_44 , V_199 -> V_79 ) ;
F_192 ( V_199 ) ;
}
static bool F_197 ( struct V_200 * V_201 , char * * error )
{
if ( ! V_201 -> V_202 ) {
* error = L_10 ;
return false ;
}
return true ;
}
static int F_198 ( struct V_198 * V_199 , struct V_200 * V_201 ,
char * * error )
{
int V_27 ;
T_9 V_203 ;
char V_39 [ V_204 ] ;
if ( ! F_197 ( V_201 , error ) )
return - V_205 ;
V_27 = F_199 ( V_199 -> V_44 , F_200 ( V_201 ) , V_206 | V_207 ,
& V_199 -> V_192 ) ;
if ( V_27 ) {
* error = L_11 ;
return V_27 ;
}
V_203 = F_194 ( V_199 -> V_192 ) ;
if ( V_203 > V_208 )
F_104 ( L_12 ,
F_201 ( V_199 -> V_192 -> V_80 , V_39 ) , V_209 ) ;
return 0 ;
}
static int F_202 ( struct V_198 * V_199 , struct V_200 * V_201 ,
char * * error )
{
int V_27 ;
if ( ! F_197 ( V_201 , error ) )
return - V_205 ;
V_27 = F_199 ( V_199 -> V_44 , F_200 ( V_201 ) , V_206 | V_207 ,
& V_199 -> V_83 ) ;
if ( V_27 ) {
* error = L_13 ;
return V_27 ;
}
V_199 -> V_210 = F_194 ( V_199 -> V_83 ) ;
return 0 ;
}
static int F_203 ( struct V_198 * V_199 , struct V_200 * V_201 ,
char * * error )
{
int V_27 ;
if ( ! F_197 ( V_201 , error ) )
return - V_205 ;
V_27 = F_199 ( V_199 -> V_44 , F_200 ( V_201 ) , V_206 | V_207 ,
& V_199 -> V_79 ) ;
if ( V_27 ) {
* error = L_14 ;
return V_27 ;
}
V_199 -> V_211 = F_194 ( V_199 -> V_79 ) ;
if ( V_199 -> V_44 -> V_212 > V_199 -> V_211 ) {
* error = L_15 ;
return - V_205 ;
}
return 0 ;
}
static int F_204 ( struct V_198 * V_199 , struct V_200 * V_201 ,
char * * error )
{
unsigned long V_213 ;
if ( ! F_197 ( V_201 , error ) )
return - V_205 ;
if ( F_205 ( F_200 ( V_201 ) , 10 , & V_213 ) || ! V_213 ||
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
static void F_206 ( struct V_63 * V_216 )
{
V_216 -> V_217 = V_218 ;
V_216 -> V_65 = V_67 ;
}
static int F_207 ( struct V_198 * V_199 , struct V_200 * V_201 ,
char * * error )
{
static struct V_219 V_220 [] = {
{ 0 , 1 , L_18 } ,
} ;
int V_27 ;
unsigned V_202 ;
const char * V_221 ;
struct V_63 * V_216 = & V_199 -> V_69 ;
F_206 ( V_216 ) ;
V_27 = F_208 ( V_220 , V_201 , & V_202 , error ) ;
if ( V_27 )
return - V_205 ;
while ( V_202 -- ) {
V_221 = F_200 ( V_201 ) ;
if ( ! strcasecmp ( V_221 , L_19 ) )
V_216 -> V_65 = V_67 ;
else if ( ! strcasecmp ( V_221 , L_20 ) )
V_216 -> V_65 = V_66 ;
else if ( ! strcasecmp ( V_221 , L_21 ) )
V_216 -> V_65 = V_68 ;
else {
* error = L_22 ;
return - V_205 ;
}
}
return 0 ;
}
static int F_209 ( struct V_198 * V_199 , struct V_200 * V_201 ,
char * * error )
{
static struct V_219 V_220 [] = {
{ 0 , 1024 , L_23 } ,
} ;
int V_27 ;
if ( ! F_197 ( V_201 , error ) )
return - V_205 ;
V_199 -> V_222 = F_200 ( V_201 ) ;
V_27 = F_208 ( V_220 , V_201 , & V_199 -> V_223 , error ) ;
if ( V_27 )
return - V_205 ;
V_199 -> V_224 = ( const char * * ) V_201 -> V_225 ;
F_210 ( V_201 , V_199 -> V_223 ) ;
return 0 ;
}
static int F_211 ( struct V_198 * V_199 , int V_202 , char * * V_225 ,
char * * error )
{
int V_27 ;
struct V_200 V_201 ;
V_201 . V_202 = V_202 ;
V_201 . V_225 = V_225 ;
V_27 = F_198 ( V_199 , & V_201 , error ) ;
if ( V_27 )
return V_27 ;
V_27 = F_202 ( V_199 , & V_201 , error ) ;
if ( V_27 )
return V_27 ;
V_27 = F_203 ( V_199 , & V_201 , error ) ;
if ( V_27 )
return V_27 ;
V_27 = F_204 ( V_199 , & V_201 , error ) ;
if ( V_27 )
return V_27 ;
V_27 = F_207 ( V_199 , & V_201 , error ) ;
if ( V_27 )
return V_27 ;
V_27 = F_209 ( V_199 , & V_201 , error ) ;
if ( V_27 )
return V_27 ;
return 0 ;
}
static int F_212 ( struct V_12 * V_12 , const char * V_30 , const char * V_226 )
{
unsigned long V_133 ;
if ( ! strcasecmp ( V_30 , L_24 ) ) {
if ( F_205 ( V_226 , 10 , & V_133 ) )
return - V_205 ;
V_12 -> V_141 = V_133 ;
return 0 ;
}
return V_227 ;
}
static int F_213 ( struct V_12 * V_12 , const char * V_30 , const char * V_226 )
{
int V_27 = F_212 ( V_12 , V_30 , V_226 ) ;
if ( V_27 == V_227 )
V_27 = F_214 ( V_12 -> V_43 , V_30 , V_226 ) ;
if ( V_27 )
F_104 ( L_25 , V_30 , V_226 ) ;
return V_27 ;
}
static int F_215 ( struct V_12 * V_12 , int V_202 , const char * * V_225 )
{
int V_27 = 0 ;
if ( V_202 & 1 ) {
F_104 ( L_26 ) ;
return - V_205 ;
}
while ( V_202 ) {
V_27 = F_213 ( V_12 , V_225 [ 0 ] , V_225 [ 1 ] ) ;
if ( V_27 )
break;
V_202 -= 2 ;
V_225 += 2 ;
}
return V_27 ;
}
static int F_216 ( struct V_12 * V_12 , struct V_198 * V_199 ,
char * * error )
{
struct V_228 * V_20 = F_217 ( V_199 -> V_222 ,
V_12 -> V_229 ,
V_12 -> V_211 ,
V_12 -> V_84 ) ;
if ( F_218 ( V_20 ) ) {
* error = L_27 ;
return F_219 ( V_20 ) ;
}
V_12 -> V_43 = V_20 ;
return 0 ;
}
static int F_220 ( struct V_198 * V_199 , struct V_12 * * V_230 )
{
int V_27 = 0 ;
char * * error = & V_199 -> V_44 -> error ;
struct V_12 * V_12 ;
struct V_195 * V_44 = V_199 -> V_44 ;
T_7 V_231 ;
struct V_232 * V_54 ;
bool V_233 = V_199 -> V_69 . V_217 == V_218 ;
V_12 = F_221 ( sizeof( * V_12 ) , V_234 ) ;
if ( ! V_12 )
return - V_23 ;
V_12 -> V_44 = V_199 -> V_44 ;
V_44 -> V_196 = V_12 ;
V_44 -> V_235 = 2 ;
V_44 -> V_236 = true ;
V_44 -> V_237 = 1 ;
V_44 -> V_238 = true ;
V_44 -> V_239 = true ;
V_44 -> V_240 = true ;
V_12 -> V_69 = V_199 -> V_69 ;
V_44 -> V_241 = F_63 ( V_12 ) ;
V_12 -> V_189 . V_242 = F_182 ;
F_222 ( V_44 -> V_45 , & V_12 -> V_189 ) ;
V_12 -> V_192 = V_199 -> V_192 ;
V_12 -> V_79 = V_199 -> V_79 ;
V_12 -> V_83 = V_199 -> V_83 ;
V_199 -> V_192 = V_199 -> V_79 = V_199 -> V_83 = NULL ;
V_231 = V_12 -> V_211 = V_199 -> V_211 ;
V_231 = F_44 ( V_231 , V_199 -> V_213 ) ;
V_12 -> V_231 = F_76 ( V_231 ) ;
V_12 -> V_84 = V_199 -> V_213 ;
if ( F_223 ( V_44 , V_12 -> V_84 ) ) {
V_27 = - V_205 ;
goto V_243;
}
if ( V_199 -> V_213 & ( V_199 -> V_213 - 1 ) ) {
T_7 V_229 = V_199 -> V_210 ;
V_12 -> V_46 = - 1 ;
V_229 = F_44 ( V_229 , V_199 -> V_213 ) ;
V_12 -> V_229 = F_37 ( V_229 ) ;
} else {
V_12 -> V_46 = F_224 ( V_199 -> V_213 ) ;
V_12 -> V_229 = F_37 ( V_199 -> V_210 >> V_12 -> V_46 ) ;
}
V_27 = F_216 ( V_12 , V_199 , error ) ;
if ( V_27 )
goto V_243;
V_12 -> V_244 = V_199 -> V_223 ;
V_12 -> V_141 = V_245 ;
V_27 = F_215 ( V_12 , V_199 -> V_223 , V_199 -> V_224 ) ;
if ( V_27 ) {
* error = L_28 ;
goto V_243;
}
V_54 = F_225 ( V_12 -> V_192 -> V_80 ,
V_199 -> V_213 , V_233 ,
F_226 ( V_12 -> V_43 ) ) ;
if ( F_218 ( V_54 ) ) {
* error = L_29 ;
V_27 = F_219 ( V_54 ) ;
goto V_243;
}
V_12 -> V_54 = V_54 ;
if ( F_62 ( & V_12 -> V_69 ) ) {
bool V_246 ;
V_27 = F_227 ( V_12 -> V_54 , & V_246 ) ;
if ( V_27 ) {
* error = L_30 ;
goto V_243;
}
if ( ! V_246 ) {
* error = L_31 ;
V_27 = - V_205 ;
goto V_243;
}
}
F_228 ( & V_12 -> V_51 ) ;
F_147 ( & V_12 -> V_104 ) ;
F_147 ( & V_12 -> V_94 ) ;
F_147 ( & V_12 -> V_95 ) ;
F_117 ( & V_12 -> V_114 ) ;
F_117 ( & V_12 -> V_120 ) ;
F_117 ( & V_12 -> V_113 ) ;
F_56 ( & V_12 -> V_99 , 0 ) ;
F_229 ( & V_12 -> V_100 ) ;
F_229 ( & V_12 -> V_177 ) ;
F_56 ( & V_12 -> V_175 , 0 ) ;
F_56 ( & V_12 -> V_176 , 0 ) ;
V_27 = - V_23 ;
V_12 -> V_42 = 0 ;
V_12 -> V_40 = F_3 ( F_34 ( V_12 -> V_229 ) ) ;
if ( ! V_12 -> V_40 ) {
* error = L_32 ;
goto V_243;
}
F_5 ( V_12 -> V_40 , F_34 ( V_12 -> V_229 ) ) ;
V_12 -> V_247 = V_12 -> V_231 ;
V_12 -> V_52 = F_3 ( F_27 ( V_12 -> V_247 ) ) ;
if ( ! V_12 -> V_52 ) {
* error = L_33 ;
goto V_243;
}
F_5 ( V_12 -> V_52 , F_27 ( V_12 -> V_247 ) ) ;
V_12 -> V_126 = F_230 ( & V_248 ) ;
if ( F_218 ( V_12 -> V_126 ) ) {
* error = L_34 ;
V_27 = F_219 ( V_12 -> V_126 ) ;
goto V_243;
}
V_12 -> V_13 = F_231 ( L_35 V_249 , V_250 ) ;
if ( ! V_12 -> V_13 ) {
* error = L_36 ;
goto V_243;
}
F_232 ( & V_12 -> V_14 , F_173 ) ;
F_233 ( & V_12 -> V_178 , F_175 ) ;
V_12 -> V_159 = V_137 ;
V_12 -> V_16 = F_234 ( V_251 ) ;
if ( ! V_12 -> V_16 ) {
* error = L_37 ;
goto V_243;
}
V_12 -> V_135 = F_235 () ;
if ( ! V_12 -> V_135 ) {
* error = L_38 ;
goto V_243;
}
V_12 -> V_22 = F_236 ( V_252 ,
V_253 ) ;
if ( ! V_12 -> V_22 ) {
* error = L_39 ;
goto V_243;
}
V_12 -> V_191 = NULL ;
V_12 -> V_86 = true ;
V_12 -> V_254 = false ;
V_12 -> V_115 = false ;
V_12 -> V_93 = false ;
V_12 -> V_255 = false ;
V_12 -> V_256 = false ;
F_54 ( V_12 ) ;
F_56 ( & V_12 -> V_49 . V_153 , 0 ) ;
F_56 ( & V_12 -> V_49 . V_155 , 0 ) ;
F_56 ( & V_12 -> V_49 . V_129 , 0 ) ;
F_56 ( & V_12 -> V_49 . V_157 , 0 ) ;
F_56 ( & V_12 -> V_49 . V_161 , 0 ) ;
F_56 ( & V_12 -> V_49 . V_50 , 0 ) ;
F_228 ( & V_12 -> V_173 ) ;
F_117 ( & V_12 -> V_174 ) ;
* V_230 = V_12 ;
return 0 ;
V_243:
F_183 ( V_12 ) ;
return V_27 ;
}
static int F_237 ( struct V_12 * V_12 , int V_202 , const char * * V_225 )
{
unsigned V_190 ;
const char * * V_257 ;
V_257 = F_238 ( V_202 , sizeof( * V_257 ) , V_234 ) ;
if ( ! V_257 )
return - V_23 ;
for ( V_190 = 0 ; V_190 < V_202 ; V_190 ++ ) {
V_257 [ V_190 ] = F_239 ( V_225 [ V_190 ] , V_234 ) ;
if ( ! V_257 [ V_190 ] ) {
while ( V_190 -- )
F_192 ( V_257 [ V_190 ] ) ;
F_192 ( V_257 ) ;
return - V_23 ;
}
}
V_12 -> V_193 = V_202 ;
V_12 -> V_194 = V_257 ;
return 0 ;
}
static int F_240 ( struct V_195 * V_44 , unsigned V_202 , char * * V_225 )
{
int V_27 = - V_205 ;
struct V_198 * V_199 ;
struct V_12 * V_12 = NULL ;
V_199 = F_221 ( sizeof( * V_199 ) , V_234 ) ;
if ( ! V_199 ) {
V_44 -> error = L_40 ;
return - V_23 ;
}
V_199 -> V_44 = V_44 ;
V_27 = F_211 ( V_199 , V_202 , V_225 , & V_44 -> error ) ;
if ( V_27 )
goto V_258;
V_27 = F_220 ( V_199 , & V_12 ) ;
if ( V_27 )
goto V_258;
V_27 = F_237 ( V_12 , V_202 - 3 , ( const char * * ) V_225 + 3 ) ;
if ( V_27 ) {
F_183 ( V_12 ) ;
goto V_258;
}
V_44 -> V_196 = V_12 ;
V_258:
F_196 ( V_199 ) ;
return V_27 ;
}
static int F_241 ( struct V_195 * V_44 , struct V_8 * V_8 )
{
struct V_12 * V_12 = V_44 -> V_196 ;
int V_27 ;
T_3 V_33 = F_75 ( V_12 , V_8 ) ;
T_1 V_85 = F_63 ( V_12 ) ;
bool V_148 = false ;
bool V_146 ;
struct V_15 * V_18 ;
struct V_144 V_145 ;
struct V_72 * V_74 = F_66 ( V_8 , V_85 ) ;
if ( F_242 ( F_27 ( V_33 ) >= F_27 ( V_12 -> V_231 ) ) ) {
F_68 ( V_12 , V_8 ) ;
return V_259 ;
}
if ( V_8 -> V_87 & ( V_89 | V_88 | V_90 ) ) {
F_129 ( V_12 , V_8 ) ;
return V_260 ;
}
V_18 = F_13 ( V_12 ) ;
if ( ! V_18 ) {
F_129 ( V_12 , V_8 ) ;
return V_260 ;
}
V_27 = F_28 ( V_12 , V_33 , V_8 , V_18 ,
( T_4 ) F_15 ,
V_12 , & V_18 ) ;
if ( V_27 ) {
if ( V_27 < 0 )
F_129 ( V_12 , V_8 ) ;
return V_260 ;
}
V_146 = F_53 ( V_12 , V_33 ) ;
V_27 = F_140 ( V_12 -> V_43 , V_33 , false , V_148 , V_146 ,
V_8 , & V_145 ) ;
if ( V_27 == - V_149 ) {
F_93 ( V_12 , V_18 , true ) ;
return V_260 ;
} else if ( V_27 ) {
F_108 ( L_41 , V_27 ) ;
F_141 ( V_8 ) ;
return V_260 ;
}
V_27 = V_259 ;
switch ( V_145 . V_150 ) {
case V_152 :
if ( F_62 ( & V_12 -> V_69 ) ) {
if ( F_73 ( V_8 ) == V_91 ) {
F_93 ( V_12 , V_18 , true ) ;
V_27 = V_260 ;
} else {
V_74 -> V_77 = F_138 ( V_12 -> V_135 ) ;
F_136 ( V_12 , V_8 ) ;
F_72 ( V_12 , V_8 , V_33 ) ;
F_93 ( V_12 , V_18 , false ) ;
}
} else {
F_135 ( V_12 , V_8 ) ;
V_74 -> V_77 = F_138 ( V_12 -> V_135 ) ;
if ( F_73 ( V_8 ) == V_91 && F_60 ( & V_12 -> V_69 ) &&
! F_32 ( V_12 , V_145 . V_41 ) )
F_85 ( V_12 , V_8 , V_33 , V_145 . V_41 ) ;
else
F_74 ( V_12 , V_8 , V_33 , V_145 . V_41 ) ;
F_93 ( V_12 , V_18 , false ) ;
}
break;
case V_151 :
F_136 ( V_12 , V_8 ) ;
V_74 -> V_77 = F_138 ( V_12 -> V_135 ) ;
if ( V_74 -> V_76 != 0 ) {
F_83 ( V_8 , 0 ) ;
F_93 ( V_12 , V_18 , false ) ;
return V_260 ;
} else {
F_72 ( V_12 , V_8 , V_33 ) ;
F_93 ( V_12 , V_18 , false ) ;
}
break;
default:
F_108 ( L_42 , V_158 ,
( unsigned ) V_145 . V_150 ) ;
F_141 ( V_8 ) ;
V_27 = V_260 ;
}
return V_27 ;
}
static int F_243 ( struct V_195 * V_44 , struct V_8 * V_8 , int error )
{
struct V_12 * V_12 = V_44 -> V_196 ;
unsigned long V_48 ;
T_1 V_85 = F_63 ( V_12 ) ;
struct V_72 * V_74 = F_64 ( V_8 , V_85 ) ;
if ( V_74 -> V_75 ) {
F_177 ( V_12 -> V_43 ) ;
F_47 ( & V_12 -> V_51 , V_48 ) ;
V_12 -> V_86 = true ;
F_49 ( & V_12 -> V_51 , V_48 ) ;
}
F_123 ( V_12 , V_74 ) ;
return 0 ;
}
static int F_244 ( struct V_12 * V_12 )
{
unsigned V_190 , V_27 ;
for ( V_190 = 0 ; V_190 < F_34 ( V_12 -> V_229 ) ; V_190 ++ ) {
V_27 = F_245 ( V_12 -> V_54 , F_37 ( V_190 ) ,
F_32 ( V_12 , F_37 ( V_190 ) ) ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_246 ( struct V_12 * V_12 )
{
unsigned V_190 , V_27 ;
V_27 = F_247 ( V_12 -> V_54 , V_12 -> V_84 ,
V_12 -> V_231 ) ;
if ( V_27 ) {
F_157 ( L_43 ) ;
return V_27 ;
}
for ( V_190 = 0 ; V_190 < F_27 ( V_12 -> V_247 ) ; V_190 ++ ) {
V_27 = F_248 ( V_12 -> V_54 , F_76 ( V_190 ) ,
F_52 ( V_12 , F_76 ( V_190 ) ) ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static bool F_249 ( struct V_12 * V_12 )
{
int V_261 , V_262 , V_263 , V_264 ;
V_261 = F_244 ( V_12 ) ;
if ( V_261 )
F_157 ( L_44 ) ;
V_262 = F_246 ( V_12 ) ;
if ( V_262 )
F_157 ( L_45 ) ;
F_57 ( V_12 ) ;
V_263 = F_250 ( V_12 -> V_54 , V_12 -> V_43 ) ;
if ( V_263 )
F_157 ( L_46 ) ;
V_264 = F_145 ( V_12 -> V_54 , ! V_261 && ! V_262 && ! V_263 ) ;
if ( V_264 )
F_157 ( L_47 ) ;
return ! V_261 && ! V_262 && ! V_263 && ! V_264 ;
}
static void F_251 ( struct V_195 * V_44 )
{
struct V_12 * V_12 = V_44 -> V_196 ;
F_165 ( V_12 ) ;
F_167 ( V_12 ) ;
F_168 ( V_12 ) ;
F_171 ( V_12 ) ;
F_166 ( V_12 ) ;
( void ) F_249 ( V_12 ) ;
}
static int F_252 ( void * V_119 , T_3 V_28 , T_5 V_41 ,
bool V_265 , T_8 V_266 , bool V_267 )
{
int V_27 ;
struct V_12 * V_12 = V_119 ;
V_27 = F_253 ( V_12 -> V_43 , V_28 , V_41 , V_266 , V_267 ) ;
if ( V_27 )
return V_27 ;
if ( V_265 )
F_35 ( V_12 , V_28 , V_41 ) ;
else
F_39 ( V_12 , V_28 , V_41 ) ;
return 0 ;
}
static int F_254 ( void * V_119 , T_9 V_268 ,
T_3 V_28 , bool V_269 )
{
struct V_12 * V_12 = V_119 ;
if ( V_269 )
F_46 ( V_12 , V_28 ) ;
else
F_50 ( V_12 , V_28 ) ;
return 0 ;
}
static T_5 F_255 ( struct V_12 * V_12 )
{
T_9 V_270 = F_194 ( V_12 -> V_83 ) ;
( void ) F_70 ( V_270 , V_12 -> V_84 ) ;
return F_37 ( V_270 ) ;
}
static bool F_256 ( struct V_12 * V_12 , T_5 V_271 )
{
if ( F_34 ( V_271 ) > F_34 ( V_12 -> V_229 ) )
return true ;
while ( F_34 ( V_271 ) < F_34 ( V_12 -> V_229 ) ) {
V_271 = F_37 ( F_34 ( V_271 ) + 1 ) ;
if ( F_32 ( V_12 , V_271 ) ) {
F_157 ( L_48 ,
( unsigned long long ) F_34 ( V_271 ) ) ;
return false ;
}
}
return true ;
}
static int F_257 ( struct V_12 * V_12 , T_5 V_271 )
{
int V_27 ;
V_27 = F_258 ( V_12 -> V_54 , V_271 ) ;
if ( V_27 ) {
F_157 ( L_49 ) ;
return V_27 ;
}
V_12 -> V_229 = V_271 ;
return 0 ;
}
static int F_259 ( struct V_195 * V_44 )
{
int V_27 = 0 ;
struct V_12 * V_12 = V_44 -> V_196 ;
T_5 V_272 = F_255 ( V_12 ) ;
if ( ! V_12 -> V_254 ) {
V_27 = F_257 ( V_12 , V_272 ) ;
if ( V_27 )
return V_27 ;
V_12 -> V_254 = true ;
} else if ( V_272 != V_12 -> V_229 ) {
if ( ! F_256 ( V_12 , V_272 ) )
return - V_205 ;
V_27 = F_257 ( V_12 , V_272 ) ;
if ( V_27 )
return V_27 ;
}
if ( ! V_12 -> V_255 ) {
V_27 = F_260 ( V_12 -> V_54 , V_12 -> V_43 ,
F_252 , V_12 ) ;
if ( V_27 ) {
F_157 ( L_50 ) ;
return V_27 ;
}
V_12 -> V_255 = true ;
}
if ( ! V_12 -> V_256 ) {
V_27 = F_261 ( V_12 -> V_54 , F_254 , V_12 ) ;
if ( V_27 ) {
F_157 ( L_51 ) ;
return V_27 ;
}
V_12 -> V_256 = true ;
}
return V_27 ;
}
static void F_262 ( struct V_195 * V_44 )
{
struct V_12 * V_12 = V_44 -> V_196 ;
V_12 -> V_86 = true ;
F_175 ( & V_12 -> V_178 . V_134 ) ;
}
static void F_263 ( struct V_195 * V_44 , T_11 type ,
unsigned V_273 , char * V_230 , unsigned V_274 )
{
int V_27 = 0 ;
unsigned V_190 ;
T_12 V_275 = 0 ;
T_7 V_276 = 0 ;
T_7 V_277 = 0 ;
char V_278 [ V_204 ] ;
struct V_12 * V_12 = V_44 -> V_196 ;
T_5 V_279 ;
switch ( type ) {
case V_280 :
if ( ! ( V_273 & V_281 ) && ! F_264 ( V_44 ) ) {
V_27 = F_145 ( V_12 -> V_54 , false ) ;
if ( V_27 )
F_157 ( L_52 ) ;
}
V_27 = F_265 ( V_12 -> V_54 ,
& V_276 ) ;
if ( V_27 ) {
F_157 ( L_53 ) ;
goto V_96;
}
V_27 = F_266 ( V_12 -> V_54 , & V_277 ) ;
if ( V_27 ) {
F_157 ( L_54 ) ;
goto V_96;
}
V_279 = F_267 ( V_12 -> V_43 ) ;
F_268 ( L_55 ,
( unsigned ) ( V_282 >> V_128 ) ,
( unsigned long long ) ( V_277 - V_276 ) ,
( unsigned long long ) V_277 ,
V_12 -> V_84 ,
( unsigned long long ) F_34 ( V_279 ) ,
( unsigned long long ) F_34 ( V_12 -> V_229 ) ,
( unsigned ) F_58 ( & V_12 -> V_49 . V_55 ) ,
( unsigned ) F_58 ( & V_12 -> V_49 . V_57 ) ,
( unsigned ) F_58 ( & V_12 -> V_49 . V_59 ) ,
( unsigned ) F_58 ( & V_12 -> V_49 . V_61 ) ,
( unsigned ) F_58 ( & V_12 -> V_49 . V_153 ) ,
( unsigned ) F_58 ( & V_12 -> V_49 . V_155 ) ,
( unsigned long long ) F_34 ( V_12 -> V_42 ) ) ;
if ( F_60 ( & V_12 -> V_69 ) )
F_268 ( L_56 ) ;
else if ( F_62 ( & V_12 -> V_69 ) )
F_268 ( L_57 ) ;
else if ( F_61 ( & V_12 -> V_69 ) )
F_268 ( L_58 ) ;
else {
F_157 ( L_59 , ( int ) V_12 -> V_69 . V_65 ) ;
goto V_96;
}
F_268 ( L_60 , ( unsigned long long ) V_12 -> V_141 ) ;
F_268 ( L_61 , F_269 ( V_12 -> V_43 ) ) ;
if ( V_275 < V_274 ) {
V_27 = F_270 ( V_12 -> V_43 , V_230 + V_275 , V_274 - V_275 ) ;
if ( V_27 )
F_157 ( L_62 , V_27 ) ;
}
break;
case V_283 :
F_271 ( V_278 , V_12 -> V_192 -> V_80 -> V_284 ) ;
F_268 ( L_61 , V_278 ) ;
F_271 ( V_278 , V_12 -> V_83 -> V_80 -> V_284 ) ;
F_268 ( L_61 , V_278 ) ;
F_271 ( V_278 , V_12 -> V_79 -> V_80 -> V_284 ) ;
F_268 ( L_63 , V_278 ) ;
for ( V_190 = 0 ; V_190 < V_12 -> V_193 - 1 ; V_190 ++ )
F_268 ( L_64 , V_12 -> V_194 [ V_190 ] ) ;
if ( V_12 -> V_193 )
F_268 ( L_64 , V_12 -> V_194 [ V_12 -> V_193 - 1 ] ) ;
}
return;
V_96:
F_268 ( L_65 ) ;
}
static int F_272 ( struct V_12 * V_12 , const char * V_285 ,
struct V_286 * V_230 )
{
char V_287 ;
T_10 V_39 , V_288 ;
int V_27 ;
V_27 = sscanf ( V_285 , L_66 , & V_39 , & V_288 , & V_287 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_27 == 2 ) {
V_230 -> V_167 = F_37 ( V_39 ) ;
V_230 -> V_169 = F_37 ( V_288 ) ;
return 0 ;
}
V_27 = sscanf ( V_285 , L_67 , & V_39 , & V_287 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_27 == 1 ) {
V_230 -> V_167 = F_37 ( V_39 ) ;
V_230 -> V_169 = F_37 ( F_34 ( V_230 -> V_167 ) + 1u ) ;
return 0 ;
}
F_157 ( L_68 , V_285 ) ;
return - V_205 ;
}
static int F_273 ( struct V_12 * V_12 , struct V_286 * V_289 )
{
T_10 V_39 = F_34 ( V_289 -> V_167 ) ;
T_10 V_288 = F_34 ( V_289 -> V_169 ) ;
T_10 V_47 = F_34 ( V_12 -> V_229 ) ;
if ( V_39 >= V_47 ) {
F_157 ( L_69 , V_39 , V_47 ) ;
return - V_205 ;
}
if ( V_288 > V_47 ) {
F_157 ( L_70 , V_288 , V_47 ) ;
return - V_205 ;
}
if ( V_39 >= V_288 ) {
F_157 ( L_71 , V_39 , V_288 ) ;
return - V_205 ;
}
return 0 ;
}
static int F_274 ( struct V_12 * V_12 , struct V_286 * V_289 )
{
struct V_165 V_166 ;
F_117 ( & V_166 . V_112 ) ;
V_166 . V_168 = V_289 ;
F_56 ( & V_166 . V_171 , 0 ) ;
V_166 . V_96 = 0 ;
F_229 ( & V_166 . V_172 ) ;
F_159 ( & V_12 -> V_173 ) ;
F_275 ( & V_166 . V_112 , & V_12 -> V_174 ) ;
F_160 ( & V_12 -> V_173 ) ;
F_11 ( V_12 ) ;
F_164 ( V_166 . V_172 , F_58 ( & V_166 . V_171 ) ) ;
return V_166 . V_96 ;
}
static int F_276 ( struct V_12 * V_12 , unsigned V_124 ,
const char * * V_290 )
{
int V_27 = 0 ;
unsigned V_190 ;
struct V_286 V_289 ;
if ( ! F_62 ( & V_12 -> V_69 ) ) {
F_157 ( L_72 ) ;
return - V_291 ;
}
for ( V_190 = 0 ; V_190 < V_124 ; V_190 ++ ) {
V_27 = F_272 ( V_12 , V_290 [ V_190 ] , & V_289 ) ;
if ( V_27 )
break;
V_27 = F_273 ( V_12 , & V_289 ) ;
if ( V_27 )
break;
V_27 = F_274 ( V_12 , & V_289 ) ;
if ( V_27 )
break;
}
return V_27 ;
}
static int F_277 ( struct V_195 * V_44 , unsigned V_202 , char * * V_225 )
{
struct V_12 * V_12 = V_44 -> V_196 ;
if ( ! V_202 )
return - V_205 ;
if ( ! strcasecmp ( V_225 [ 0 ] , L_73 ) )
return F_276 ( V_12 , V_202 - 1 , ( const char * * ) V_225 + 1 ) ;
if ( V_202 != 2 )
return - V_205 ;
return F_213 ( V_12 , V_225 [ 0 ] , V_225 [ 1 ] ) ;
}
static int F_278 ( struct V_195 * V_44 ,
T_13 F_116 , void * V_292 )
{
int V_27 = 0 ;
struct V_12 * V_12 = V_44 -> V_196 ;
V_27 = F_116 ( V_44 , V_12 -> V_83 , 0 , F_194 ( V_12 -> V_83 ) , V_292 ) ;
if ( ! V_27 )
V_27 = F_116 ( V_44 , V_12 -> V_79 , 0 , V_44 -> V_212 , V_292 ) ;
return V_27 ;
}
static int F_279 ( struct V_195 * V_44 ,
struct V_293 * V_294 ,
struct V_295 * V_296 , int V_297 )
{
struct V_12 * V_12 = V_44 -> V_196 ;
struct V_184 * V_185 = F_180 ( V_12 -> V_79 -> V_80 ) ;
if ( ! V_185 -> V_298 )
return V_297 ;
V_294 -> V_78 = V_12 -> V_79 -> V_80 ;
return F_280 ( V_297 , V_185 -> V_298 ( V_185 , V_294 , V_296 ) ) ;
}
static void F_281 ( struct V_12 * V_12 , struct V_299 * V_300 )
{
V_300 -> V_301 = V_12 -> V_84 ;
V_300 -> V_302 = V_12 -> V_84 << V_128 ;
}
static void F_282 ( struct V_195 * V_44 , struct V_299 * V_300 )
{
struct V_12 * V_12 = V_44 -> V_196 ;
T_10 V_303 = V_300 -> V_304 >> V_128 ;
if ( V_303 < V_12 -> V_84 ||
F_45 ( V_303 , V_12 -> V_84 ) ) {
F_283 ( V_300 , 0 ) ;
F_284 ( V_300 , V_12 -> V_84 << V_128 ) ;
}
F_281 ( V_12 , V_300 ) ;
}
static int T_14 F_285 ( void )
{
int V_27 ;
V_27 = F_286 ( & V_305 ) ;
if ( V_27 ) {
F_157 ( L_74 , V_27 ) ;
return V_27 ;
}
V_253 = F_287 ( V_26 , 0 ) ;
if ( ! V_253 ) {
F_288 ( & V_305 ) ;
return - V_23 ;
}
return 0 ;
}
static void T_15 F_289 ( void )
{
F_288 ( & V_305 ) ;
F_290 ( V_253 ) ;
}
