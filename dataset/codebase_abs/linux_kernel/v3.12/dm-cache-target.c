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
static void F_8 ( struct V_6 * V_6 )
{
F_9 ( V_6 -> V_7 , & V_6 -> V_8 ) ;
}
static struct V_9 * F_10 ( struct V_6 * V_6 )
{
return F_11 ( V_6 -> V_10 , V_11 ) ;
}
static void F_12 ( struct V_6 * V_6 , struct V_9 * V_12 )
{
F_13 ( V_6 -> V_10 , V_12 ) ;
}
static int F_14 ( struct V_6 * V_6 , struct V_13 * V_14 )
{
if ( ! V_14 -> V_15 ) {
V_14 -> V_15 = F_15 ( V_6 -> V_16 , V_11 ) ;
if ( ! V_14 -> V_15 )
return - V_17 ;
}
if ( ! V_14 -> V_18 ) {
V_14 -> V_18 = F_10 ( V_6 ) ;
if ( ! V_14 -> V_18 )
return - V_17 ;
}
if ( ! V_14 -> V_19 ) {
V_14 -> V_19 = F_10 ( V_6 ) ;
if ( ! V_14 -> V_19 )
return - V_17 ;
}
return 0 ;
}
static void F_16 ( struct V_6 * V_6 , struct V_13 * V_14 )
{
if ( V_14 -> V_19 )
F_12 ( V_6 , V_14 -> V_19 ) ;
if ( V_14 -> V_18 )
F_12 ( V_6 , V_14 -> V_18 ) ;
if ( V_14 -> V_15 )
F_17 ( V_14 -> V_15 , V_6 -> V_16 ) ;
}
static struct V_20 * F_18 ( struct V_13 * V_14 )
{
struct V_20 * V_15 = V_14 -> V_15 ;
F_19 ( ! V_15 ) ;
V_14 -> V_15 = NULL ;
return V_15 ;
}
static struct V_9 * F_20 ( struct V_13 * V_14 )
{
struct V_9 * V_21 = NULL ;
if ( V_14 -> V_18 ) {
V_21 = V_14 -> V_18 ;
V_14 -> V_18 = NULL ;
} else if ( V_14 -> V_19 ) {
V_21 = V_14 -> V_19 ;
V_14 -> V_19 = NULL ;
} else
F_21 () ;
return V_21 ;
}
static void F_22 ( struct V_13 * V_14 , struct V_9 * V_12 )
{
if ( ! V_14 -> V_19 )
V_14 -> V_19 = V_12 ;
else if ( ! V_14 -> V_18 )
V_14 -> V_18 = V_12 ;
else
F_21 () ;
}
static void F_23 ( T_2 V_22 , struct V_23 * V_24 )
{
V_24 -> V_25 = 0 ;
V_24 -> V_26 = 0 ;
V_24 -> V_27 = F_24 ( V_22 ) ;
}
static int F_25 ( struct V_6 * V_6 , T_2 V_22 ,
struct V_28 * V_28 , struct V_9 * V_29 ,
T_3 V_30 , void * V_31 ,
struct V_9 * * V_32 )
{
int V_21 ;
struct V_23 V_24 ;
F_23 ( V_22 , & V_24 ) ;
V_21 = F_26 ( V_6 -> V_10 , & V_24 , V_28 , V_29 , V_32 ) ;
if ( V_21 )
V_30 ( V_31 , V_29 ) ;
return V_21 ;
}
static int F_27 ( struct V_6 * V_6 ,
T_2 V_22 ,
struct V_13 * V_33 ,
struct V_9 * * V_32 )
{
int V_21 ;
struct V_23 V_24 ;
struct V_9 * V_29 ;
V_29 = F_20 ( V_33 ) ;
F_23 ( V_22 , & V_24 ) ;
V_21 = F_28 ( V_6 -> V_10 , & V_24 , V_29 , V_32 ) ;
if ( V_21 )
F_22 ( V_33 , V_29 ) ;
return V_21 ;
}
static bool F_29 ( struct V_6 * V_6 , T_4 V_34 )
{
return F_30 ( F_31 ( V_34 ) , V_6 -> V_35 ) ;
}
static void F_32 ( struct V_6 * V_6 , T_2 V_22 , T_4 V_36 )
{
if ( ! F_33 ( F_31 ( V_36 ) , V_6 -> V_35 ) ) {
V_6 -> V_37 = F_34 ( F_31 ( V_6 -> V_37 ) + 1 ) ;
F_35 ( V_6 -> V_38 , V_22 ) ;
}
}
static void F_36 ( struct V_6 * V_6 , T_2 V_22 , T_4 V_36 )
{
if ( F_37 ( F_31 ( V_36 ) , V_6 -> V_35 ) ) {
F_38 ( V_6 -> V_38 , V_22 ) ;
V_6 -> V_37 = F_34 ( F_31 ( V_6 -> V_37 ) - 1 ) ;
if ( ! F_31 ( V_6 -> V_37 ) )
F_39 ( V_6 -> V_39 -> V_40 ) ;
}
}
static bool F_40 ( struct V_6 * V_6 )
{
return V_6 -> V_41 >= 0 ;
}
T_5
#endif
static T_6 F_41 ( T_6 V_34 , T_7 V_42 )
{
F_42 ( V_34 , V_42 ) ;
return V_34 ;
}
static T_8 F_43 ( struct V_6 * V_6 , T_2 V_22 )
{
T_7 V_43 = V_6 -> V_44 ;
T_6 V_34 = F_24 ( V_22 ) ;
if ( ! F_40 ( V_6 ) )
V_43 = V_43 / V_6 -> V_45 ;
else
V_43 >>= V_6 -> V_41 ;
V_34 = F_41 ( V_34 , V_43 ) ;
return F_44 ( V_34 ) ;
}
static void F_45 ( struct V_6 * V_6 , T_8 V_34 )
{
unsigned long V_46 ;
F_46 ( & V_6 -> V_47 . V_48 ) ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_48 ( F_49 ( V_34 ) , V_6 -> V_50 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
}
static void F_51 ( struct V_6 * V_6 , T_8 V_34 )
{
unsigned long V_46 ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_52 ( F_49 ( V_34 ) , V_6 -> V_50 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
}
static bool F_53 ( struct V_6 * V_6 , T_8 V_34 )
{
int V_21 ;
unsigned long V_46 ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
V_21 = F_30 ( F_49 ( V_34 ) , V_6 -> V_50 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
return V_21 ;
}
static bool F_54 ( struct V_6 * V_6 , T_2 V_34 )
{
int V_21 ;
unsigned long V_46 ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
V_21 = F_30 ( F_49 ( F_43 ( V_6 , V_34 ) ) ,
V_6 -> V_50 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
return V_21 ;
}
static void F_55 ( struct V_6 * V_6 )
{
struct V_51 V_47 ;
F_56 ( V_6 -> V_52 , & V_47 ) ;
F_57 ( & V_6 -> V_47 . V_53 , V_47 . V_54 ) ;
F_57 ( & V_6 -> V_47 . V_55 , V_47 . V_56 ) ;
F_57 ( & V_6 -> V_47 . V_57 , V_47 . V_58 ) ;
F_57 ( & V_6 -> V_47 . V_59 , V_47 . V_60 ) ;
}
static void F_58 ( struct V_6 * V_6 )
{
struct V_51 V_47 ;
V_47 . V_54 = F_59 ( & V_6 -> V_47 . V_53 ) ;
V_47 . V_56 = F_59 ( & V_6 -> V_47 . V_55 ) ;
V_47 . V_58 = F_59 ( & V_6 -> V_47 . V_57 ) ;
V_47 . V_60 = F_59 ( & V_6 -> V_47 . V_59 ) ;
F_60 ( V_6 -> V_52 , & V_47 ) ;
}
static T_1 F_61 ( struct V_6 * V_6 )
{
return V_6 -> V_61 . V_62 ? V_63 : V_64 ;
}
static struct V_65 * F_62 ( struct V_28 * V_28 , T_1 V_66 )
{
struct V_65 * V_67 = F_63 ( V_28 , V_66 ) ;
F_19 ( ! V_67 ) ;
return V_67 ;
}
static struct V_65 * F_64 ( struct V_28 * V_28 , T_1 V_66 )
{
struct V_65 * V_67 = F_62 ( V_28 , V_66 ) ;
V_67 -> V_68 = false ;
V_67 -> V_69 = F_65 ( V_28 ) ;
V_67 -> V_70 = NULL ;
return V_67 ;
}
static void F_66 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
V_28 -> V_71 = V_6 -> V_72 -> V_73 ;
}
static void F_67 ( struct V_6 * V_6 , struct V_28 * V_28 ,
T_4 V_36 )
{
T_9 V_74 = V_28 -> V_74 ;
V_28 -> V_71 = V_6 -> V_75 -> V_73 ;
if ( ! F_40 ( V_6 ) )
V_28 -> V_74 = ( F_31 ( V_36 ) * V_6 -> V_45 ) +
F_68 ( V_74 , V_6 -> V_45 ) ;
else
V_28 -> V_74 = ( F_31 ( V_36 ) << V_6 -> V_41 ) |
( V_74 & ( V_6 -> V_45 - 1 ) ) ;
}
static void F_69 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
unsigned long V_46 ;
T_1 V_76 = F_61 ( V_6 ) ;
struct V_65 * V_67 = F_62 ( V_28 , V_76 ) ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
if ( V_6 -> V_77 &&
! ( V_28 -> V_78 & ( V_79 | V_80 | V_81 ) ) ) {
V_67 -> V_68 = true ;
V_6 -> V_77 = false ;
}
F_50 ( & V_6 -> V_49 , V_46 ) ;
}
static void F_70 ( struct V_6 * V_6 , struct V_28 * V_28 ,
T_2 V_22 )
{
F_69 ( V_6 , V_28 ) ;
F_66 ( V_6 , V_28 ) ;
if ( F_71 ( V_28 ) == V_82 )
F_51 ( V_6 , F_43 ( V_6 , V_22 ) ) ;
}
static void F_72 ( struct V_6 * V_6 , struct V_28 * V_28 ,
T_2 V_22 , T_4 V_36 )
{
F_67 ( V_6 , V_28 , V_36 ) ;
if ( F_71 ( V_28 ) == V_82 ) {
F_32 ( V_6 , V_22 , V_36 ) ;
F_51 ( V_6 , F_43 ( V_6 , V_22 ) ) ;
}
}
static T_2 F_73 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
T_9 V_83 = V_28 -> V_74 ;
if ( ! F_40 ( V_6 ) )
( void ) F_68 ( V_83 , V_6 -> V_45 ) ;
else
V_83 >>= V_6 -> V_41 ;
return F_74 ( V_83 ) ;
}
static int F_75 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
return V_28 -> V_78 & ( V_80 | V_79 ) ;
}
static void F_76 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
unsigned long V_46 ;
if ( ! F_75 ( V_6 , V_28 ) ) {
F_77 ( V_28 ) ;
return;
}
F_47 ( & V_6 -> V_49 , V_46 ) ;
V_6 -> V_84 = true ;
F_78 ( & V_6 -> V_85 , V_28 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
}
static void F_79 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
unsigned long V_46 ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_78 ( & V_6 -> V_86 , V_28 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
F_8 ( V_6 ) ;
}
static void F_80 ( struct V_28 * V_28 , int V_87 )
{
struct V_65 * V_67 = F_62 ( V_28 , V_63 ) ;
V_28 -> V_88 = V_67 -> V_89 ;
if ( V_87 ) {
F_81 ( V_28 , V_87 ) ;
return;
}
F_82 ( & V_67 -> V_90 , V_28 ) ;
F_67 ( V_67 -> V_6 , V_28 , V_67 -> V_36 ) ;
F_79 ( V_67 -> V_6 , V_28 ) ;
}
static void F_83 ( struct V_6 * V_6 , struct V_28 * V_28 ,
T_2 V_22 , T_4 V_36 )
{
struct V_65 * V_67 = F_62 ( V_28 , V_63 ) ;
V_67 -> V_6 = V_6 ;
V_67 -> V_36 = V_36 ;
V_67 -> V_89 = V_28 -> V_88 ;
F_84 ( & V_67 -> V_90 , V_28 ) ;
V_28 -> V_88 = F_80 ;
F_70 ( V_67 -> V_6 , V_28 , V_22 ) ;
}
static void F_85 ( struct V_20 * V_15 )
{
F_17 ( V_15 , V_15 -> V_6 -> V_16 ) ;
}
static void F_86 ( struct V_6 * V_6 )
{
F_46 ( & V_6 -> V_91 ) ;
}
static void F_87 ( struct V_6 * V_6 )
{
F_88 ( & V_6 -> V_91 ) ;
F_89 ( & V_6 -> V_92 ) ;
}
static void F_90 ( struct V_6 * V_6 , struct V_9 * V_12 ,
bool V_93 )
{
( V_93 ? V_94 : V_95 )
( V_6 -> V_10 , V_12 , & V_6 -> V_96 ) ;
F_12 ( V_6 , V_12 ) ;
}
static void F_91 ( struct V_6 * V_6 , struct V_9 * V_12 ,
bool V_93 )
{
unsigned long V_46 ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_90 ( V_6 , V_12 , V_93 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
F_8 ( V_6 ) ;
}
static void F_92 ( struct V_20 * V_15 )
{
F_87 ( V_15 -> V_6 ) ;
F_85 ( V_15 ) ;
}
static void F_93 ( struct V_20 * V_15 )
{
struct V_6 * V_6 = V_15 -> V_6 ;
if ( V_15 -> V_97 ) {
F_94 ( L_1 ) ;
F_32 ( V_6 , V_15 -> V_98 , V_15 -> V_36 ) ;
F_91 ( V_6 , V_15 -> V_99 , false ) ;
} else if ( V_15 -> V_100 ) {
F_94 ( L_2 ) ;
F_95 ( V_6 -> V_38 , V_15 -> V_101 , V_15 -> V_98 ) ;
F_91 ( V_6 , V_15 -> V_99 , V_15 -> V_102 ? 0 : 1 ) ;
if ( V_15 -> V_102 )
F_91 ( V_6 , V_15 -> V_103 , 1 ) ;
} else {
F_94 ( L_3 ) ;
F_96 ( V_6 -> V_38 , V_15 -> V_101 ) ;
F_91 ( V_6 , V_15 -> V_103 , 1 ) ;
}
F_92 ( V_15 ) ;
}
static void F_97 ( struct V_20 * V_15 )
{
unsigned long V_46 ;
struct V_6 * V_6 = V_15 -> V_6 ;
if ( V_15 -> V_97 ) {
F_91 ( V_6 , V_15 -> V_99 , false ) ;
F_36 ( V_6 , V_15 -> V_98 , V_15 -> V_36 ) ;
F_92 ( V_15 ) ;
return;
} else if ( V_15 -> V_100 ) {
if ( F_98 ( V_6 -> V_52 , V_15 -> V_36 ) ) {
F_94 ( L_4 ) ;
F_95 ( V_6 -> V_38 , V_15 -> V_101 ,
V_15 -> V_98 ) ;
if ( V_15 -> V_102 )
F_91 ( V_6 , V_15 -> V_103 , true ) ;
F_92 ( V_15 ) ;
return;
}
} else {
if ( F_99 ( V_6 -> V_52 , V_15 -> V_36 , V_15 -> V_101 ) ) {
F_94 ( L_5 ) ;
F_96 ( V_6 -> V_38 , V_15 -> V_101 ) ;
F_92 ( V_15 ) ;
return;
}
}
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_100 ( & V_15 -> V_104 , & V_6 -> V_105 ) ;
V_6 -> V_84 = true ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
}
static void F_101 ( struct V_20 * V_15 )
{
unsigned long V_46 ;
struct V_6 * V_6 = V_15 -> V_6 ;
if ( V_15 -> V_97 ) {
F_102 ( L_6 ) ;
return;
} else if ( V_15 -> V_100 ) {
F_91 ( V_6 , V_15 -> V_99 , V_15 -> V_102 ? 0 : 1 ) ;
if ( V_15 -> V_102 ) {
V_15 -> V_100 = false ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_100 ( & V_15 -> V_104 , & V_6 -> V_106 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
} else
F_92 ( V_15 ) ;
} else {
F_91 ( V_6 , V_15 -> V_103 , true ) ;
F_36 ( V_6 , V_15 -> V_101 , V_15 -> V_36 ) ;
F_92 ( V_15 ) ;
}
}
static void F_103 ( int V_107 , unsigned long V_108 , void * V_109 )
{
unsigned long V_46 ;
struct V_20 * V_15 = (struct V_20 * ) V_109 ;
struct V_6 * V_6 = V_15 -> V_6 ;
if ( V_107 || V_108 )
V_15 -> V_87 = true ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_100 ( & V_15 -> V_104 , & V_6 -> V_110 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
F_8 ( V_6 ) ;
}
static void F_104 ( struct V_20 * V_15 )
{
int V_21 ;
struct V_111 V_112 , V_113 ;
struct V_6 * V_6 = V_15 -> V_6 ;
V_112 . V_73 = V_6 -> V_72 -> V_73 ;
V_112 . V_114 = V_6 -> V_45 ;
V_113 . V_73 = V_6 -> V_75 -> V_73 ;
V_113 . V_115 = F_31 ( V_15 -> V_36 ) * V_6 -> V_45 ;
V_113 . V_114 = V_6 -> V_45 ;
if ( V_15 -> V_97 || V_15 -> V_100 ) {
V_112 . V_115 = F_24 ( V_15 -> V_98 ) * V_6 -> V_45 ;
V_21 = F_105 ( V_6 -> V_116 , & V_113 , 1 , & V_112 , 0 , F_103 , V_15 ) ;
} else {
V_112 . V_115 = F_24 ( V_15 -> V_101 ) * V_6 -> V_45 ;
V_21 = F_105 ( V_6 -> V_116 , & V_112 , 1 , & V_113 , 0 , F_103 , V_15 ) ;
}
if ( V_21 < 0 )
F_93 ( V_15 ) ;
}
static void F_106 ( struct V_20 * V_15 )
{
F_46 ( & V_15 -> V_6 -> V_47 . V_117 ) ;
F_97 ( V_15 ) ;
}
static void F_107 ( struct V_20 * V_15 )
{
bool V_118 ;
struct V_6 * V_6 = V_15 -> V_6 ;
if ( V_15 -> V_97 || V_15 -> V_100 )
V_118 = ! F_29 ( V_6 , V_15 -> V_36 ) ||
F_54 ( V_6 , V_15 -> V_98 ) ;
else
V_118 = F_54 ( V_6 , V_15 -> V_101 ) ;
V_118 ? F_106 ( V_15 ) : F_104 ( V_15 ) ;
}
static void F_108 ( struct V_20 * V_15 )
{
if ( V_15 -> V_87 )
F_93 ( V_15 ) ;
else
F_97 ( V_15 ) ;
}
static void F_109 ( struct V_6 * V_6 , struct V_119 * V_120 ,
void (* F_110)( struct V_20 * ) )
{
unsigned long V_46 ;
struct V_119 V_104 ;
struct V_20 * V_15 , * V_121 ;
F_111 ( & V_104 ) ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_112 ( V_120 , & V_104 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
F_113 (mg, tmp, &list, list)
F_110 ( V_15 ) ;
}
static void F_114 ( struct V_20 * V_15 )
{
F_100 ( & V_15 -> V_104 , & V_15 -> V_6 -> V_106 ) ;
}
static void F_115 ( struct V_20 * V_15 )
{
unsigned long V_46 ;
struct V_6 * V_6 = V_15 -> V_6 ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_114 ( V_15 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
F_8 ( V_6 ) ;
}
static void F_116 ( struct V_6 * V_6 , struct V_119 * V_122 )
{
unsigned long V_46 ;
struct V_20 * V_15 , * V_121 ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_113 (mg, tmp, work, list)
F_114 ( V_15 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
F_8 ( V_6 ) ;
}
static void F_117 ( struct V_6 * V_6 ,
struct V_65 * V_67 )
{
struct V_119 V_122 ;
if ( ! V_67 -> V_70 )
return;
F_111 ( & V_122 ) ;
if ( V_67 -> V_70 )
F_118 ( V_67 -> V_70 , & V_122 ) ;
if ( ! F_119 ( & V_122 ) )
F_116 ( V_6 , & V_122 ) ;
}
static void F_120 ( struct V_20 * V_15 )
{
if ( ! F_121 ( V_15 -> V_6 -> V_123 , & V_15 -> V_104 ) )
F_115 ( V_15 ) ;
}
static void V_102 ( struct V_6 * V_6 , struct V_13 * V_33 ,
T_2 V_22 , T_4 V_36 ,
struct V_9 * V_12 )
{
struct V_20 * V_15 = F_18 ( V_33 ) ;
V_15 -> V_87 = false ;
V_15 -> V_97 = false ;
V_15 -> V_100 = false ;
V_15 -> V_102 = true ;
V_15 -> V_6 = V_6 ;
V_15 -> V_101 = V_22 ;
V_15 -> V_36 = V_36 ;
V_15 -> V_99 = NULL ;
V_15 -> V_103 = V_12 ;
V_15 -> V_124 = V_125 ;
F_86 ( V_6 ) ;
F_120 ( V_15 ) ;
}
static void V_97 ( struct V_6 * V_6 , struct V_13 * V_33 ,
T_2 V_22 , T_4 V_36 ,
struct V_9 * V_12 )
{
struct V_20 * V_15 = F_18 ( V_33 ) ;
V_15 -> V_87 = false ;
V_15 -> V_97 = true ;
V_15 -> V_100 = false ;
V_15 -> V_102 = false ;
V_15 -> V_6 = V_6 ;
V_15 -> V_98 = V_22 ;
V_15 -> V_36 = V_36 ;
V_15 -> V_99 = V_12 ;
V_15 -> V_103 = NULL ;
V_15 -> V_124 = V_125 ;
F_86 ( V_6 ) ;
F_120 ( V_15 ) ;
}
static void F_122 ( struct V_6 * V_6 , struct V_13 * V_33 ,
T_2 V_98 , T_2 V_101 ,
T_4 V_36 ,
struct V_9 * V_99 ,
struct V_9 * V_103 )
{
struct V_20 * V_15 = F_18 ( V_33 ) ;
V_15 -> V_87 = false ;
V_15 -> V_97 = false ;
V_15 -> V_100 = true ;
V_15 -> V_102 = true ;
V_15 -> V_6 = V_6 ;
V_15 -> V_98 = V_98 ;
V_15 -> V_101 = V_101 ;
V_15 -> V_36 = V_36 ;
V_15 -> V_99 = V_99 ;
V_15 -> V_103 = V_103 ;
V_15 -> V_124 = V_125 ;
F_86 ( V_6 ) ;
F_120 ( V_15 ) ;
}
static void F_123 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
unsigned long V_46 ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_78 ( & V_6 -> V_96 , V_28 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
F_8 ( V_6 ) ;
}
static void F_124 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
T_1 V_76 = F_61 ( V_6 ) ;
struct V_65 * V_67 = F_62 ( V_28 , V_76 ) ;
F_19 ( V_28 -> V_126 ) ;
if ( ! V_67 -> V_69 )
F_66 ( V_6 , V_28 ) ;
else
F_67 ( V_6 , V_28 , 0 ) ;
F_76 ( V_6 , V_28 ) ;
}
static void F_125 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
T_6 V_127 = F_126 ( V_28 -> V_74 ,
V_6 -> V_44 ) ;
T_6 V_128 = V_28 -> V_74 + F_127 ( V_28 ) ;
T_6 V_34 ;
V_128 = F_41 ( V_128 , V_6 -> V_44 ) ;
for ( V_34 = V_127 ; V_34 < V_128 ; V_34 ++ )
F_45 ( V_6 , F_44 ( V_34 ) ) ;
F_81 ( V_28 , 0 ) ;
}
static bool F_128 ( struct V_6 * V_6 )
{
T_9 V_129 = ( F_59 ( & V_6 -> V_91 ) + 1 ) *
V_6 -> V_45 ;
return V_129 < V_6 -> V_130 ;
}
static bool F_129 ( struct V_6 * V_6 , struct V_28 * V_28 ,
T_4 V_36 )
{
return F_71 ( V_28 ) == V_82 &&
V_6 -> V_61 . V_62 && ! F_29 ( V_6 , V_36 ) ;
}
static void F_130 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
F_46 ( F_71 ( V_28 ) == V_131 ?
& V_6 -> V_47 . V_53 : & V_6 -> V_47 . V_57 ) ;
}
static void F_131 ( struct V_6 * V_6 , struct V_28 * V_28 )
{
F_46 ( F_71 ( V_28 ) == V_131 ?
& V_6 -> V_47 . V_55 : & V_6 -> V_47 . V_59 ) ;
}
static void F_132 ( struct V_6 * V_6 , struct V_13 * V_33 ,
struct V_28 * V_28 )
{
int V_21 ;
bool V_132 = true ;
T_2 V_27 = F_73 ( V_6 , V_28 ) ;
struct V_9 * V_29 , * V_99 , * V_103 ;
struct V_133 V_134 ;
T_1 V_76 = F_61 ( V_6 ) ;
struct V_65 * V_67 = F_62 ( V_28 , V_76 ) ;
bool V_135 = F_54 ( V_6 , V_27 ) ;
bool V_136 = V_135 || F_128 ( V_6 ) ;
V_29 = F_20 ( V_33 ) ;
V_21 = F_25 ( V_6 , V_27 , V_28 , V_29 ,
( T_3 ) F_22 ,
V_33 , & V_103 ) ;
if ( V_21 > 0 )
return;
V_21 = F_133 ( V_6 -> V_38 , V_27 , true , V_136 , V_135 ,
V_28 , & V_134 ) ;
if ( V_21 == - V_137 )
V_134 . V_138 = V_139 ;
switch ( V_134 . V_138 ) {
case V_140 :
F_130 ( V_6 , V_28 ) ;
V_67 -> V_70 = F_134 ( V_6 -> V_123 ) ;
if ( F_129 ( V_6 , V_28 , V_134 . V_36 ) )
F_83 ( V_6 , V_28 , V_27 , V_134 . V_36 ) ;
else
F_72 ( V_6 , V_28 , V_27 , V_134 . V_36 ) ;
F_76 ( V_6 , V_28 ) ;
break;
case V_139 :
F_131 ( V_6 , V_28 ) ;
V_67 -> V_70 = F_134 ( V_6 -> V_123 ) ;
F_70 ( V_6 , V_28 , V_27 ) ;
F_76 ( V_6 , V_28 ) ;
break;
case V_141 :
F_46 ( & V_6 -> V_47 . V_142 ) ;
V_102 ( V_6 , V_33 , V_27 , V_134 . V_36 , V_103 ) ;
V_132 = false ;
break;
case V_143 :
V_29 = F_20 ( V_33 ) ;
V_21 = F_25 ( V_6 , V_134 . V_98 , V_28 , V_29 ,
( T_3 ) F_22 ,
V_33 , & V_99 ) ;
if ( V_21 > 0 ) {
F_95 ( V_6 -> V_38 , V_27 ,
V_134 . V_98 ) ;
F_46 ( & V_6 -> V_47 . V_144 ) ;
break;
}
F_46 ( & V_6 -> V_47 . V_145 ) ;
F_46 ( & V_6 -> V_47 . V_142 ) ;
F_122 ( V_6 , V_33 , V_134 . V_98 ,
V_27 , V_134 . V_36 ,
V_99 , V_103 ) ;
V_132 = false ;
break;
default:
F_135 ( L_7 , V_146 ,
( unsigned ) V_134 . V_138 ) ;
F_136 ( V_28 ) ;
}
if ( V_132 )
F_91 ( V_6 , V_103 , false ) ;
}
static int F_137 ( struct V_6 * V_6 )
{
return V_125 < V_6 -> V_147 ||
V_125 > V_6 -> V_147 + V_148 ;
}
static int F_138 ( struct V_6 * V_6 )
{
if ( F_139 ( V_6 -> V_52 ) &&
( V_6 -> V_84 || F_137 ( V_6 ) ) ) {
F_46 ( & V_6 -> V_47 . V_149 ) ;
V_6 -> V_147 = V_125 ;
V_6 -> V_84 = false ;
return F_140 ( V_6 -> V_52 , false ) ;
}
return 0 ;
}
static void F_141 ( struct V_6 * V_6 )
{
unsigned long V_46 ;
struct V_150 V_151 ;
struct V_28 * V_28 ;
struct V_13 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
F_142 ( & V_151 ) ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_143 ( & V_151 , & V_6 -> V_96 ) ;
F_142 ( & V_6 -> V_96 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
while ( ! F_144 ( & V_151 ) ) {
if ( F_14 ( V_6 , & V_33 ) ) {
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_143 ( & V_6 -> V_96 , & V_151 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
break;
}
V_28 = F_145 ( & V_151 ) ;
if ( V_28 -> V_78 & V_80 )
F_124 ( V_6 , V_28 ) ;
else if ( V_28 -> V_78 & V_81 )
F_125 ( V_6 , V_28 ) ;
else
F_132 ( V_6 , & V_33 , V_28 ) ;
}
F_16 ( V_6 , & V_33 ) ;
}
static void F_146 ( struct V_6 * V_6 , bool V_152 )
{
unsigned long V_46 ;
struct V_150 V_151 ;
struct V_28 * V_28 ;
F_142 ( & V_151 ) ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_143 ( & V_151 , & V_6 -> V_85 ) ;
F_142 ( & V_6 -> V_85 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
while ( ( V_28 = F_145 ( & V_151 ) ) )
V_152 ? F_77 ( V_28 ) : F_136 ( V_28 ) ;
}
static void F_147 ( struct V_6 * V_6 )
{
unsigned long V_46 ;
struct V_150 V_151 ;
struct V_28 * V_28 ;
F_142 ( & V_151 ) ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
F_143 ( & V_151 , & V_6 -> V_86 ) ;
F_142 ( & V_6 -> V_86 ) ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
while ( ( V_28 = F_145 ( & V_151 ) ) )
F_77 ( V_28 ) ;
}
static void F_148 ( struct V_6 * V_6 )
{
int V_21 = 0 ;
T_2 V_22 ;
T_4 V_36 ;
struct V_13 V_33 ;
struct V_9 * V_99 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
while ( F_128 ( V_6 ) ) {
if ( F_14 ( V_6 , & V_33 ) )
break;
V_21 = F_149 ( V_6 -> V_38 , & V_22 , & V_36 ) ;
if ( V_21 )
break;
V_21 = F_27 ( V_6 , V_22 , & V_33 , & V_99 ) ;
if ( V_21 ) {
F_35 ( V_6 -> V_38 , V_22 ) ;
break;
}
V_97 ( V_6 , & V_33 , V_22 , V_36 , V_99 ) ;
}
F_16 ( V_6 , & V_33 ) ;
}
static void F_150 ( struct V_6 * V_6 )
{
unsigned long V_46 ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
V_6 -> V_153 = 1 ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
}
static void F_151 ( struct V_6 * V_6 )
{
unsigned long V_46 ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
V_6 -> V_153 = 0 ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
}
static bool F_152 ( struct V_6 * V_6 )
{
int V_21 ;
unsigned long V_46 ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
V_21 = V_6 -> V_153 ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
return V_21 ;
}
static void F_153 ( struct V_6 * V_6 )
{
F_154 ( V_6 -> V_92 , ! F_59 ( & V_6 -> V_91 ) ) ;
}
static void F_155 ( struct V_6 * V_6 )
{
F_156 ( & V_6 -> V_154 ) ;
F_157 ( V_6 -> V_7 ) ;
}
static void F_158 ( struct V_6 * V_6 )
{
struct V_28 * V_28 ;
struct V_150 V_151 ;
F_142 ( & V_151 ) ;
F_143 ( & V_151 , & V_6 -> V_96 ) ;
F_142 ( & V_6 -> V_96 ) ;
while ( ( V_28 = F_145 ( & V_151 ) ) )
F_81 ( V_28 , V_155 ) ;
}
static int F_159 ( struct V_6 * V_6 )
{
if ( F_152 ( V_6 ) )
return ! F_119 ( & V_6 -> V_106 ) ||
! F_119 ( & V_6 -> V_110 ) ||
! F_119 ( & V_6 -> V_105 ) ;
else
return ! F_144 ( & V_6 -> V_96 ) ||
! F_144 ( & V_6 -> V_85 ) ||
! F_144 ( & V_6 -> V_86 ) ||
! F_119 ( & V_6 -> V_106 ) ||
! F_119 ( & V_6 -> V_110 ) ||
! F_119 ( & V_6 -> V_105 ) ;
}
static void F_160 ( struct V_156 * V_157 )
{
struct V_6 * V_6 = F_161 ( V_157 , struct V_6 , V_8 ) ;
do {
if ( ! F_152 ( V_6 ) )
F_141 ( V_6 ) ;
F_109 ( V_6 , & V_6 -> V_106 , F_107 ) ;
F_109 ( V_6 , & V_6 -> V_110 , F_108 ) ;
F_148 ( V_6 ) ;
F_147 ( V_6 ) ;
if ( F_138 ( V_6 ) ) {
F_146 ( V_6 , false ) ;
} else {
F_146 ( V_6 , true ) ;
F_109 ( V_6 , & V_6 -> V_105 ,
F_101 ) ;
}
} while ( F_159 ( V_6 ) );
}
static void F_162 ( struct V_156 * V_157 )
{
struct V_6 * V_6 = F_161 ( F_163 ( V_157 ) , struct V_6 , V_154 ) ;
F_164 ( V_6 -> V_38 ) ;
F_8 ( V_6 ) ;
F_165 ( V_6 -> V_7 , & V_6 -> V_154 , V_148 ) ;
}
static int F_166 ( struct V_158 * V_26 , int V_159 )
{
struct V_160 * V_161 = F_167 ( V_26 -> V_73 ) ;
return F_168 ( & V_161 -> V_162 , V_159 ) ;
}
static int F_169 ( struct V_163 * V_164 , int V_159 )
{
struct V_6 * V_6 = F_161 ( V_164 , struct V_6 , V_165 ) ;
return F_166 ( V_6 -> V_72 , V_159 ) ||
F_166 ( V_6 -> V_75 , V_159 ) ;
}
static void F_170 ( struct V_6 * V_6 )
{
unsigned V_166 ;
if ( V_6 -> V_167 )
F_17 ( V_6 -> V_167 , V_6 -> V_16 ) ;
if ( V_6 -> V_16 )
F_171 ( V_6 -> V_16 ) ;
if ( V_6 -> V_123 )
F_172 ( V_6 -> V_123 ) ;
if ( V_6 -> V_10 )
F_173 ( V_6 -> V_10 ) ;
if ( V_6 -> V_7 )
F_174 ( V_6 -> V_7 ) ;
if ( V_6 -> V_35 )
F_6 ( V_6 -> V_35 ) ;
if ( V_6 -> V_50 )
F_6 ( V_6 -> V_50 ) ;
if ( V_6 -> V_116 )
F_175 ( V_6 -> V_116 ) ;
if ( V_6 -> V_52 )
F_176 ( V_6 -> V_52 ) ;
if ( V_6 -> V_168 )
F_177 ( V_6 -> V_39 , V_6 -> V_168 ) ;
if ( V_6 -> V_72 )
F_177 ( V_6 -> V_39 , V_6 -> V_72 ) ;
if ( V_6 -> V_75 )
F_177 ( V_6 -> V_39 , V_6 -> V_75 ) ;
if ( V_6 -> V_38 )
F_178 ( V_6 -> V_38 ) ;
for ( V_166 = 0 ; V_166 < V_6 -> V_169 ; V_166 ++ )
F_179 ( V_6 -> V_170 [ V_166 ] ) ;
F_179 ( V_6 -> V_170 ) ;
F_179 ( V_6 ) ;
}
static void F_180 ( struct V_171 * V_39 )
{
struct V_6 * V_6 = V_39 -> V_172 ;
F_170 ( V_6 ) ;
}
static T_9 F_181 ( struct V_158 * V_26 )
{
return F_182 ( V_26 -> V_73 -> V_173 ) >> V_174 ;
}
static void F_183 ( struct V_175 * V_176 )
{
if ( V_176 -> V_168 )
F_177 ( V_176 -> V_39 , V_176 -> V_168 ) ;
if ( V_176 -> V_75 )
F_177 ( V_176 -> V_39 , V_176 -> V_75 ) ;
if ( V_176 -> V_72 )
F_177 ( V_176 -> V_39 , V_176 -> V_72 ) ;
F_179 ( V_176 ) ;
}
static bool F_184 ( struct V_177 * V_178 , char * * error )
{
if ( ! V_178 -> V_179 ) {
* error = L_8 ;
return false ;
}
return true ;
}
static int F_185 ( struct V_175 * V_176 , struct V_177 * V_178 ,
char * * error )
{
int V_21 ;
T_9 V_180 ;
char V_34 [ V_181 ] ;
if ( ! F_184 ( V_178 , error ) )
return - V_182 ;
V_21 = F_186 ( V_176 -> V_39 , F_187 ( V_178 ) , V_183 | V_184 ,
& V_176 -> V_168 ) ;
if ( V_21 ) {
* error = L_9 ;
return V_21 ;
}
V_180 = F_181 ( V_176 -> V_168 ) ;
if ( V_180 > V_185 )
F_102 ( L_10 ,
F_188 ( V_176 -> V_168 -> V_73 , V_34 ) , V_186 ) ;
return 0 ;
}
static int F_189 ( struct V_175 * V_176 , struct V_177 * V_178 ,
char * * error )
{
int V_21 ;
if ( ! F_184 ( V_178 , error ) )
return - V_182 ;
V_21 = F_186 ( V_176 -> V_39 , F_187 ( V_178 ) , V_183 | V_184 ,
& V_176 -> V_75 ) ;
if ( V_21 ) {
* error = L_11 ;
return V_21 ;
}
V_176 -> V_187 = F_181 ( V_176 -> V_75 ) ;
return 0 ;
}
static int F_190 ( struct V_175 * V_176 , struct V_177 * V_178 ,
char * * error )
{
int V_21 ;
if ( ! F_184 ( V_178 , error ) )
return - V_182 ;
V_21 = F_186 ( V_176 -> V_39 , F_187 ( V_178 ) , V_183 | V_184 ,
& V_176 -> V_72 ) ;
if ( V_21 ) {
* error = L_12 ;
return V_21 ;
}
V_176 -> V_188 = F_181 ( V_176 -> V_72 ) ;
if ( V_176 -> V_39 -> V_189 > V_176 -> V_188 ) {
* error = L_13 ;
return - V_182 ;
}
return 0 ;
}
static int F_191 ( struct V_175 * V_176 , struct V_177 * V_178 ,
char * * error )
{
unsigned long V_190 ;
if ( ! F_184 ( V_178 , error ) )
return - V_182 ;
if ( F_192 ( F_187 ( V_178 ) , 10 , & V_190 ) || ! V_190 ||
V_190 < V_191 ||
V_190 > V_192 ||
V_190 & ( V_191 - 1 ) ) {
* error = L_14 ;
return - V_182 ;
}
if ( V_190 > V_176 -> V_187 ) {
* error = L_15 ;
return - V_182 ;
}
V_176 -> V_190 = V_190 ;
return 0 ;
}
static void F_193 ( struct V_193 * V_194 )
{
V_194 -> V_195 = V_196 ;
V_194 -> V_62 = false ;
}
static int F_194 ( struct V_175 * V_176 , struct V_177 * V_178 ,
char * * error )
{
static struct V_197 V_198 [] = {
{ 0 , 1 , L_16 } ,
} ;
int V_21 ;
unsigned V_179 ;
const char * V_199 ;
struct V_193 * V_194 = & V_176 -> V_61 ;
F_193 ( V_194 ) ;
V_21 = F_195 ( V_198 , V_178 , & V_179 , error ) ;
if ( V_21 )
return - V_182 ;
while ( V_179 -- ) {
V_199 = F_187 ( V_178 ) ;
if ( ! strcasecmp ( V_199 , L_17 ) )
V_194 -> V_62 = false ;
else if ( ! strcasecmp ( V_199 , L_18 ) )
V_194 -> V_62 = true ;
else {
* error = L_19 ;
return - V_182 ;
}
}
return 0 ;
}
static int F_196 ( struct V_175 * V_176 , struct V_177 * V_178 ,
char * * error )
{
static struct V_197 V_198 [] = {
{ 0 , 1024 , L_20 } ,
} ;
int V_21 ;
if ( ! F_184 ( V_178 , error ) )
return - V_182 ;
V_176 -> V_200 = F_187 ( V_178 ) ;
V_21 = F_195 ( V_198 , V_178 , & V_176 -> V_201 , error ) ;
if ( V_21 )
return - V_182 ;
V_176 -> V_202 = ( const char * * ) V_178 -> V_203 ;
F_197 ( V_178 , V_176 -> V_201 ) ;
return 0 ;
}
static int F_198 ( struct V_175 * V_176 , int V_179 , char * * V_203 ,
char * * error )
{
int V_21 ;
struct V_177 V_178 ;
V_178 . V_179 = V_179 ;
V_178 . V_203 = V_203 ;
V_21 = F_185 ( V_176 , & V_178 , error ) ;
if ( V_21 )
return V_21 ;
V_21 = F_189 ( V_176 , & V_178 , error ) ;
if ( V_21 )
return V_21 ;
V_21 = F_190 ( V_176 , & V_178 , error ) ;
if ( V_21 )
return V_21 ;
V_21 = F_191 ( V_176 , & V_178 , error ) ;
if ( V_21 )
return V_21 ;
V_21 = F_194 ( V_176 , & V_178 , error ) ;
if ( V_21 )
return V_21 ;
V_21 = F_196 ( V_176 , & V_178 , error ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
static int F_199 ( struct V_6 * V_6 , const char * V_24 , const char * V_204 )
{
unsigned long V_121 ;
if ( ! strcasecmp ( V_24 , L_21 ) ) {
if ( F_192 ( V_204 , 10 , & V_121 ) )
return - V_182 ;
V_6 -> V_130 = V_121 ;
return 0 ;
}
return V_205 ;
}
static int F_200 ( struct V_6 * V_6 , const char * V_24 , const char * V_204 )
{
int V_21 = F_199 ( V_6 , V_24 , V_204 ) ;
if ( V_21 == V_205 )
V_21 = F_201 ( V_6 -> V_38 , V_24 , V_204 ) ;
if ( V_21 )
F_102 ( L_22 , V_24 , V_204 ) ;
return V_21 ;
}
static int F_202 ( struct V_6 * V_6 , int V_179 , const char * * V_203 )
{
int V_21 = 0 ;
if ( V_179 & 1 ) {
F_102 ( L_23 ) ;
return - V_182 ;
}
while ( V_179 ) {
V_21 = F_200 ( V_6 , V_203 [ 0 ] , V_203 [ 1 ] ) ;
if ( V_21 )
break;
V_179 -= 2 ;
V_203 += 2 ;
}
return V_21 ;
}
static int F_203 ( struct V_6 * V_6 , struct V_175 * V_176 ,
char * * error )
{
V_6 -> V_38 = F_204 ( V_176 -> V_200 ,
V_6 -> V_206 ,
V_6 -> V_188 ,
V_6 -> V_45 ) ;
if ( ! V_6 -> V_38 ) {
* error = L_24 ;
return - V_17 ;
}
return 0 ;
}
static bool F_205 ( T_9 V_44 ,
T_9 V_207 )
{
( void ) F_68 ( V_207 , V_44 ) ;
return V_207 > V_208 ;
}
static T_9 F_206 ( T_9 V_209 ,
T_9 V_207 )
{
T_9 V_44 ;
V_44 = F_207 ( V_209 ) ;
if ( V_207 )
while ( F_205 ( V_44 , V_207 ) )
V_44 *= 2 ;
return V_44 ;
}
static int F_208 ( struct V_175 * V_176 , struct V_6 * * V_210 )
{
int V_21 = 0 ;
char * * error = & V_176 -> V_39 -> error ;
struct V_6 * V_6 ;
struct V_171 * V_39 = V_176 -> V_39 ;
T_6 V_211 ;
struct V_212 * V_52 ;
bool V_213 = V_176 -> V_61 . V_195 == V_196 ;
V_6 = F_209 ( sizeof( * V_6 ) , V_214 ) ;
if ( ! V_6 )
return - V_17 ;
V_6 -> V_39 = V_176 -> V_39 ;
V_39 -> V_172 = V_6 ;
V_39 -> V_215 = 2 ;
V_39 -> V_216 = true ;
V_39 -> V_217 = 1 ;
V_39 -> V_218 = true ;
V_39 -> V_219 = true ;
V_6 -> V_61 = V_176 -> V_61 ;
V_39 -> V_220 = F_61 ( V_6 ) ;
V_6 -> V_165 . V_221 = F_169 ;
F_210 ( V_39 -> V_40 , & V_6 -> V_165 ) ;
V_6 -> V_168 = V_176 -> V_168 ;
V_6 -> V_72 = V_176 -> V_72 ;
V_6 -> V_75 = V_176 -> V_75 ;
V_176 -> V_168 = V_176 -> V_72 = V_176 -> V_75 = NULL ;
V_211 = V_6 -> V_188 = V_176 -> V_188 ;
V_211 = F_41 ( V_211 , V_176 -> V_190 ) ;
V_6 -> V_211 = F_74 ( V_211 ) ;
V_6 -> V_45 = V_176 -> V_190 ;
if ( F_211 ( V_39 , V_6 -> V_45 ) ) {
V_21 = - V_182 ;
goto V_222;
}
if ( V_176 -> V_190 & ( V_176 -> V_190 - 1 ) ) {
T_6 V_206 = V_176 -> V_187 ;
V_6 -> V_41 = - 1 ;
V_206 = F_41 ( V_206 , V_176 -> V_190 ) ;
V_6 -> V_206 = F_34 ( V_206 ) ;
} else {
V_6 -> V_41 = F_212 ( V_176 -> V_190 ) ;
V_6 -> V_206 = F_34 ( V_176 -> V_187 >> V_6 -> V_41 ) ;
}
V_21 = F_203 ( V_6 , V_176 , error ) ;
if ( V_21 )
goto V_222;
V_6 -> V_223 = V_176 -> V_201 ;
V_6 -> V_130 = V_224 ;
V_21 = F_202 ( V_6 , V_176 -> V_201 , V_176 -> V_202 ) ;
if ( V_21 ) {
* error = L_25 ;
goto V_222;
}
V_52 = F_213 ( V_6 -> V_168 -> V_73 ,
V_176 -> V_190 , V_213 ,
F_214 ( V_6 -> V_38 ) ) ;
if ( F_215 ( V_52 ) ) {
* error = L_26 ;
V_21 = F_216 ( V_52 ) ;
goto V_222;
}
V_6 -> V_52 = V_52 ;
F_217 ( & V_6 -> V_49 ) ;
F_142 ( & V_6 -> V_96 ) ;
F_142 ( & V_6 -> V_85 ) ;
F_142 ( & V_6 -> V_86 ) ;
F_111 ( & V_6 -> V_106 ) ;
F_111 ( & V_6 -> V_110 ) ;
F_111 ( & V_6 -> V_105 ) ;
F_57 ( & V_6 -> V_91 , 0 ) ;
F_218 ( & V_6 -> V_92 ) ;
V_21 = - V_17 ;
V_6 -> V_37 = 0 ;
V_6 -> V_35 = F_3 ( F_31 ( V_6 -> V_206 ) ) ;
if ( ! V_6 -> V_35 ) {
* error = L_27 ;
goto V_222;
}
F_5 ( V_6 -> V_35 , F_31 ( V_6 -> V_206 ) ) ;
V_6 -> V_44 =
F_206 ( V_6 -> V_45 ,
V_6 -> V_188 ) ;
V_6 -> V_225 = F_43 ( V_6 , V_6 -> V_211 ) ;
V_6 -> V_50 = F_3 ( F_49 ( V_6 -> V_225 ) ) ;
if ( ! V_6 -> V_50 ) {
* error = L_28 ;
goto V_222;
}
F_5 ( V_6 -> V_50 , F_49 ( V_6 -> V_225 ) ) ;
V_6 -> V_116 = F_219 ( & V_226 ) ;
if ( F_215 ( V_6 -> V_116 ) ) {
* error = L_29 ;
V_21 = F_216 ( V_6 -> V_116 ) ;
goto V_222;
}
V_6 -> V_7 = F_220 ( L_30 V_227 , V_228 ) ;
if ( ! V_6 -> V_7 ) {
* error = L_31 ;
goto V_222;
}
F_221 ( & V_6 -> V_8 , F_160 ) ;
F_222 ( & V_6 -> V_154 , F_162 ) ;
V_6 -> V_147 = V_125 ;
V_6 -> V_10 = F_223 ( V_229 ) ;
if ( ! V_6 -> V_10 ) {
* error = L_32 ;
goto V_222;
}
V_6 -> V_123 = F_224 () ;
if ( ! V_6 -> V_123 ) {
* error = L_33 ;
goto V_222;
}
V_6 -> V_16 = F_225 ( V_230 ,
V_231 ) ;
if ( ! V_6 -> V_16 ) {
* error = L_34 ;
goto V_222;
}
V_6 -> V_167 = NULL ;
V_6 -> V_77 = true ;
V_6 -> V_232 = false ;
V_6 -> V_153 = false ;
V_6 -> V_84 = false ;
V_6 -> V_233 = false ;
V_6 -> V_234 = false ;
F_55 ( V_6 ) ;
F_57 ( & V_6 -> V_47 . V_145 , 0 ) ;
F_57 ( & V_6 -> V_47 . V_142 , 0 ) ;
F_57 ( & V_6 -> V_47 . V_117 , 0 ) ;
F_57 ( & V_6 -> V_47 . V_144 , 0 ) ;
F_57 ( & V_6 -> V_47 . V_149 , 0 ) ;
F_57 ( & V_6 -> V_47 . V_48 , 0 ) ;
* V_210 = V_6 ;
return 0 ;
V_222:
F_170 ( V_6 ) ;
return V_21 ;
}
static int F_226 ( struct V_6 * V_6 , int V_179 , const char * * V_203 )
{
unsigned V_166 ;
const char * * V_235 ;
V_235 = F_227 ( V_179 , sizeof( * V_235 ) , V_214 ) ;
if ( ! V_235 )
return - V_17 ;
for ( V_166 = 0 ; V_166 < V_179 ; V_166 ++ ) {
V_235 [ V_166 ] = F_228 ( V_203 [ V_166 ] , V_214 ) ;
if ( ! V_235 [ V_166 ] ) {
while ( V_166 -- )
F_179 ( V_235 [ V_166 ] ) ;
F_179 ( V_235 ) ;
return - V_17 ;
}
}
V_6 -> V_169 = V_179 ;
V_6 -> V_170 = V_235 ;
return 0 ;
}
static int F_229 ( struct V_171 * V_39 , unsigned V_179 , char * * V_203 )
{
int V_21 = - V_182 ;
struct V_175 * V_176 ;
struct V_6 * V_6 = NULL ;
V_176 = F_209 ( sizeof( * V_176 ) , V_214 ) ;
if ( ! V_176 ) {
V_39 -> error = L_35 ;
return - V_17 ;
}
V_176 -> V_39 = V_39 ;
V_21 = F_198 ( V_176 , V_179 , V_203 , & V_39 -> error ) ;
if ( V_21 )
goto V_236;
V_21 = F_208 ( V_176 , & V_6 ) ;
if ( V_21 )
goto V_236;
V_21 = F_226 ( V_6 , V_179 - 3 , ( const char * * ) V_203 + 3 ) ;
if ( V_21 ) {
F_170 ( V_6 ) ;
goto V_236;
}
V_39 -> V_172 = V_6 ;
V_236:
F_183 ( V_176 ) ;
return V_21 ;
}
static int F_230 ( struct V_171 * V_39 , struct V_28 * V_28 )
{
struct V_6 * V_6 = V_39 -> V_172 ;
int V_21 ;
T_2 V_27 = F_73 ( V_6 , V_28 ) ;
T_1 V_76 = F_61 ( V_6 ) ;
bool V_136 = false ;
bool V_135 ;
struct V_9 * V_12 ;
struct V_133 V_134 ;
struct V_65 * V_67 ;
if ( F_24 ( V_27 ) > F_24 ( V_6 -> V_211 ) ) {
F_70 ( V_6 , V_28 , V_27 ) ;
return V_237 ;
}
V_67 = F_64 ( V_28 , V_76 ) ;
if ( V_28 -> V_78 & ( V_80 | V_79 | V_81 ) ) {
F_123 ( V_6 , V_28 ) ;
return V_238 ;
}
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_123 ( V_6 , V_28 ) ;
return V_238 ;
}
V_21 = F_25 ( V_6 , V_27 , V_28 , V_12 ,
( T_3 ) F_12 ,
V_6 , & V_12 ) ;
if ( V_21 ) {
if ( V_21 < 0 )
F_123 ( V_6 , V_28 ) ;
return V_238 ;
}
V_135 = F_54 ( V_6 , V_27 ) ;
V_21 = F_133 ( V_6 -> V_38 , V_27 , false , V_136 , V_135 ,
V_28 , & V_134 ) ;
if ( V_21 == - V_137 ) {
F_91 ( V_6 , V_12 , true ) ;
return V_238 ;
} else if ( V_21 ) {
F_135 ( L_36 , V_21 ) ;
F_136 ( V_28 ) ;
return V_238 ;
}
switch ( V_134 . V_138 ) {
case V_140 :
F_130 ( V_6 , V_28 ) ;
V_67 -> V_70 = F_134 ( V_6 -> V_123 ) ;
if ( F_129 ( V_6 , V_28 , V_134 . V_36 ) )
F_83 ( V_6 , V_28 , V_27 , V_134 . V_36 ) ;
else
F_72 ( V_6 , V_28 , V_27 , V_134 . V_36 ) ;
F_91 ( V_6 , V_12 , false ) ;
break;
case V_139 :
F_131 ( V_6 , V_28 ) ;
V_67 -> V_70 = F_134 ( V_6 -> V_123 ) ;
if ( V_67 -> V_69 != 0 ) {
F_81 ( V_28 , 0 ) ;
F_91 ( V_6 , V_12 , false ) ;
return V_238 ;
} else {
F_70 ( V_6 , V_28 , V_27 ) ;
F_91 ( V_6 , V_12 , false ) ;
}
break;
default:
F_135 ( L_37 , V_146 ,
( unsigned ) V_134 . V_138 ) ;
F_136 ( V_28 ) ;
return V_238 ;
}
return V_237 ;
}
static int F_231 ( struct V_171 * V_39 , struct V_28 * V_28 , int error )
{
struct V_6 * V_6 = V_39 -> V_172 ;
unsigned long V_46 ;
T_1 V_76 = F_61 ( V_6 ) ;
struct V_65 * V_67 = F_62 ( V_28 , V_76 ) ;
if ( V_67 -> V_68 ) {
F_164 ( V_6 -> V_38 ) ;
F_47 ( & V_6 -> V_49 , V_46 ) ;
V_6 -> V_77 = true ;
F_50 ( & V_6 -> V_49 , V_46 ) ;
}
F_117 ( V_6 , V_67 ) ;
return 0 ;
}
static int F_232 ( struct V_6 * V_6 )
{
unsigned V_166 , V_21 ;
for ( V_166 = 0 ; V_166 < F_31 ( V_6 -> V_206 ) ; V_166 ++ ) {
V_21 = F_233 ( V_6 -> V_52 , F_34 ( V_166 ) ,
F_29 ( V_6 , F_34 ( V_166 ) ) ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_234 ( struct V_6 * V_6 )
{
unsigned V_166 , V_21 ;
V_21 = F_235 ( V_6 -> V_52 , V_6 -> V_44 ,
V_6 -> V_225 ) ;
if ( V_21 ) {
F_236 ( L_38 ) ;
return V_21 ;
}
for ( V_166 = 0 ; V_166 < F_49 ( V_6 -> V_225 ) ; V_166 ++ ) {
V_21 = F_237 ( V_6 -> V_52 , F_44 ( V_166 ) ,
F_53 ( V_6 , F_44 ( V_166 ) ) ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_238 ( void * V_109 , T_4 V_36 , T_2 V_22 ,
T_7 V_239 )
{
struct V_6 * V_6 = V_109 ;
return F_239 ( V_6 -> V_52 , V_36 , V_239 ) ;
}
static int F_240 ( struct V_6 * V_6 )
{
int V_21 ;
V_21 = F_241 ( V_6 -> V_52 , V_6 -> V_38 ) ;
if ( V_21 ) {
F_236 ( L_39 ) ;
return V_21 ;
}
V_21 = F_242 ( V_6 -> V_38 , F_238 , V_6 ) ;
if ( V_21 )
F_236 ( L_40 ) ;
return V_21 ;
}
static bool F_243 ( struct V_6 * V_6 )
{
int V_240 , V_241 , V_242 , V_243 ;
V_240 = F_232 ( V_6 ) ;
if ( V_240 )
F_236 ( L_41 ) ;
V_241 = F_234 ( V_6 ) ;
if ( V_241 )
F_236 ( L_42 ) ;
F_58 ( V_6 ) ;
V_242 = F_240 ( V_6 ) ;
if ( V_242 )
F_236 ( L_43 ) ;
V_243 = F_140 ( V_6 -> V_52 , ! V_240 && ! V_241 && ! V_242 ) ;
if ( V_243 )
F_236 ( L_44 ) ;
return ! V_240 && ! V_241 && ! V_242 && ! V_243 ;
}
static void F_244 ( struct V_171 * V_39 )
{
struct V_6 * V_6 = V_39 -> V_172 ;
F_150 ( V_6 ) ;
F_153 ( V_6 ) ;
F_155 ( V_6 ) ;
F_158 ( V_6 ) ;
F_151 ( V_6 ) ;
( void ) F_243 ( V_6 ) ;
}
static int F_245 ( void * V_109 , T_2 V_22 , T_4 V_36 ,
bool V_244 , T_7 V_239 , bool V_245 )
{
int V_21 ;
struct V_6 * V_6 = V_109 ;
V_21 = F_246 ( V_6 -> V_38 , V_22 , V_36 , V_239 , V_245 ) ;
if ( V_21 )
return V_21 ;
if ( V_244 )
F_32 ( V_6 , V_22 , V_36 ) ;
else
F_36 ( V_6 , V_22 , V_36 ) ;
return 0 ;
}
static int F_247 ( void * V_109 , T_9 V_44 ,
T_8 V_246 , bool V_247 )
{
struct V_6 * V_6 = V_109 ;
if ( V_247 )
F_45 ( V_6 , V_246 ) ;
else
F_51 ( V_6 , V_246 ) ;
return 0 ;
}
static int F_248 ( struct V_171 * V_39 )
{
int V_21 = 0 ;
struct V_6 * V_6 = V_39 -> V_172 ;
T_9 V_248 = F_181 ( V_6 -> V_75 ) ;
( void ) F_68 ( V_248 , V_6 -> V_45 ) ;
if ( F_31 ( V_6 -> V_206 ) != V_248 || ! V_6 -> V_232 ) {
V_6 -> V_206 = F_34 ( V_248 ) ;
V_21 = F_249 ( V_6 -> V_52 , V_6 -> V_206 ) ;
if ( V_21 ) {
F_236 ( L_45 ) ;
return V_21 ;
}
V_6 -> V_232 = true ;
}
if ( ! V_6 -> V_233 ) {
V_21 = F_250 ( V_6 -> V_52 , V_6 -> V_38 ,
F_245 , V_6 ) ;
if ( V_21 ) {
F_236 ( L_46 ) ;
return V_21 ;
}
V_6 -> V_233 = true ;
}
if ( ! V_6 -> V_234 ) {
V_21 = F_251 ( V_6 -> V_52 , F_247 , V_6 ) ;
if ( V_21 ) {
F_236 ( L_47 ) ;
return V_21 ;
}
V_6 -> V_234 = true ;
}
return V_21 ;
}
static void F_252 ( struct V_171 * V_39 )
{
struct V_6 * V_6 = V_39 -> V_172 ;
V_6 -> V_77 = true ;
F_162 ( & V_6 -> V_154 . V_122 ) ;
}
static void F_253 ( struct V_171 * V_39 , T_10 type ,
unsigned V_249 , char * V_210 , unsigned V_250 )
{
int V_21 = 0 ;
unsigned V_166 ;
T_11 V_251 = 0 ;
T_6 V_252 = 0 ;
T_6 V_253 = 0 ;
char V_254 [ V_181 ] ;
struct V_6 * V_6 = V_39 -> V_172 ;
T_4 V_255 ;
switch ( type ) {
case V_256 :
if ( ! ( V_249 & V_257 ) && ! F_254 ( V_39 ) ) {
V_21 = F_140 ( V_6 -> V_52 , false ) ;
if ( V_21 )
F_236 ( L_48 ) ;
}
V_21 = F_255 ( V_6 -> V_52 ,
& V_252 ) ;
if ( V_21 ) {
F_236 ( L_49 ) ;
goto V_87;
}
V_21 = F_256 ( V_6 -> V_52 , & V_253 ) ;
if ( V_21 ) {
F_236 ( L_50 ) ;
goto V_87;
}
V_255 = F_257 ( V_6 -> V_38 ) ;
F_258 ( L_51 ,
( unsigned long long ) ( V_253 - V_252 ) ,
( unsigned long long ) V_253 ,
( unsigned ) F_59 ( & V_6 -> V_47 . V_53 ) ,
( unsigned ) F_59 ( & V_6 -> V_47 . V_55 ) ,
( unsigned ) F_59 ( & V_6 -> V_47 . V_57 ) ,
( unsigned ) F_59 ( & V_6 -> V_47 . V_59 ) ,
( unsigned ) F_59 ( & V_6 -> V_47 . V_145 ) ,
( unsigned ) F_59 ( & V_6 -> V_47 . V_142 ) ,
( unsigned long long ) F_31 ( V_255 ) ,
V_6 -> V_37 ) ;
if ( V_6 -> V_61 . V_62 )
F_258 ( L_52 ) ;
else
F_258 ( L_53 ) ;
F_258 ( L_54 , ( unsigned long long ) V_6 -> V_130 ) ;
if ( V_251 < V_250 ) {
V_21 = F_259 ( V_6 -> V_38 , V_210 + V_251 , V_250 - V_251 ) ;
if ( V_21 )
F_236 ( L_55 , V_21 ) ;
}
break;
case V_258 :
F_260 ( V_254 , V_6 -> V_168 -> V_73 -> V_259 ) ;
F_258 ( L_56 , V_254 ) ;
F_260 ( V_254 , V_6 -> V_75 -> V_73 -> V_259 ) ;
F_258 ( L_56 , V_254 ) ;
F_260 ( V_254 , V_6 -> V_72 -> V_73 -> V_259 ) ;
F_258 ( L_57 , V_254 ) ;
for ( V_166 = 0 ; V_166 < V_6 -> V_169 - 1 ; V_166 ++ )
F_258 ( L_58 , V_6 -> V_170 [ V_166 ] ) ;
if ( V_6 -> V_169 )
F_258 ( L_58 , V_6 -> V_170 [ V_6 -> V_169 - 1 ] ) ;
}
return;
V_87:
F_258 ( L_59 ) ;
}
static int F_261 ( struct V_171 * V_39 , unsigned V_179 , char * * V_203 )
{
struct V_6 * V_6 = V_39 -> V_172 ;
if ( V_179 != 2 )
return - V_182 ;
return F_200 ( V_6 , V_203 [ 0 ] , V_203 [ 1 ] ) ;
}
static int F_262 ( struct V_171 * V_39 ,
T_12 F_110 , void * V_260 )
{
int V_21 = 0 ;
struct V_6 * V_6 = V_39 -> V_172 ;
V_21 = F_110 ( V_39 , V_6 -> V_75 , 0 , F_181 ( V_6 -> V_75 ) , V_260 ) ;
if ( ! V_21 )
V_21 = F_110 ( V_39 , V_6 -> V_72 , 0 , V_39 -> V_189 , V_260 ) ;
return V_21 ;
}
static int F_263 ( struct V_171 * V_39 ,
struct V_261 * V_262 ,
struct V_263 * V_264 , int V_265 )
{
struct V_6 * V_6 = V_39 -> V_172 ;
struct V_160 * V_161 = F_167 ( V_6 -> V_72 -> V_73 ) ;
if ( ! V_161 -> V_266 )
return V_265 ;
V_262 -> V_71 = V_6 -> V_72 -> V_73 ;
return F_264 ( V_265 , V_161 -> V_266 ( V_161 , V_262 , V_264 ) ) ;
}
static void F_265 ( struct V_6 * V_6 , struct V_267 * V_268 )
{
V_268 -> V_269 = V_6 -> V_44 * 1024 ;
V_268 -> V_270 = V_6 -> V_44 << V_174 ;
}
static void F_266 ( struct V_171 * V_39 , struct V_267 * V_268 )
{
struct V_6 * V_6 = V_39 -> V_172 ;
T_13 V_271 = V_268 -> V_272 >> V_174 ;
if ( V_271 < V_6 -> V_45 ||
F_42 ( V_271 , V_6 -> V_45 ) ) {
F_267 ( V_268 , 0 ) ;
F_268 ( V_268 , V_6 -> V_45 << V_174 ) ;
}
F_265 ( V_6 , V_268 ) ;
}
static int T_14 F_269 ( void )
{
int V_21 ;
V_21 = F_270 ( & V_273 ) ;
if ( V_21 ) {
F_236 ( L_60 , V_21 ) ;
return V_21 ;
}
V_231 = F_271 ( V_20 , 0 ) ;
if ( ! V_231 ) {
F_272 ( & V_273 ) ;
return - V_17 ;
}
return 0 ;
}
static void T_15 F_273 ( void )
{
F_272 ( & V_273 ) ;
F_274 ( V_231 ) ;
}
