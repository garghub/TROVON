int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 ) + 7 - V_7 ;
if ( V_5 < 0 )
V_5 = 0 ;
V_4 = F_3 ( V_8 | V_9 , V_5 ) ;
if ( ! V_4 ) {
F_4 ( L_1 ,
V_2 -> V_10 ) ;
return - V_11 ;
}
V_2 -> V_12 = F_5 ( V_4 ) ;
F_6 ( L_2 , V_2 -> V_10 , V_5 ) ;
if ( F_7 ( V_2 -> V_6 ) ) {
V_4 = F_3 ( V_8 | V_9 , V_5 ) ;
if ( V_4 )
V_2 -> V_13 = F_5 ( V_4 ) ;
else
F_4 ( L_3 ,
V_2 -> V_10 ) ;
}
F_8 ( & V_2 -> V_14 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 ) + 7 - V_7 ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_2 -> V_12 ) {
F_10 ( ( unsigned long ) V_2 -> V_12 , V_5 ) ;
V_2 -> V_12 = NULL ;
}
if ( V_2 -> V_13 ) {
F_10 ( ( unsigned long ) V_2 -> V_13 , V_5 ) ;
V_2 -> V_13 = NULL ;
}
F_11 ( & V_2 -> V_14 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_15 , V_16 ;
V_4 = F_3 ( V_8 | V_9 , V_17 ) ;
if ( ! V_4 ) {
F_4 ( L_4 ,
V_2 -> V_10 ) ;
return - V_11 ;
}
V_2 -> V_18 = F_5 ( V_4 ) ;
V_15 = F_13 ( V_19 + V_2 -> V_20 , V_2 -> V_21 , V_2 ) ;
if ( V_15 <= 0 ) {
F_14 ( L_5 ,
V_2 -> V_10 ) ;
V_16 = - V_22 ;
V_23:
F_10 ( ( unsigned long ) V_2 -> V_18 , V_17 ) ;
V_2 -> V_18 = NULL ;
return V_16 ;
}
V_2 -> V_24 = V_15 ;
snprintf ( V_2 -> V_25 , sizeof( V_2 -> V_25 ) , L_6 , V_2 -> V_20 ) ;
V_16 = F_15 ( V_15 , NULL , V_26 , V_27 ,
V_2 -> V_25 , V_2 ) ;
if ( V_16 ) {
F_14 ( L_7 ,
V_2 -> V_10 ) ;
F_16 ( V_15 ) ;
goto V_23;
}
F_17 ( V_2 -> V_28 + V_29 , 0ULL ) ;
F_17 ( V_2 -> V_28 + V_30 , 0ULL ) ;
F_17 ( V_2 -> V_28 + V_31 , F_18 ( V_2 -> V_18 ) | V_17 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_28 + V_29 , 0ULL ) ;
F_17 ( V_2 -> V_28 + V_30 , 0ULL ) ;
F_17 ( V_2 -> V_28 + V_31 , 0ULL ) ;
F_20 ( V_2 -> V_24 , V_2 ) ;
F_16 ( V_2 -> V_24 ) ;
V_2 -> V_24 = 0 ;
F_10 ( ( unsigned long ) V_2 -> V_18 , V_17 ) ;
V_2 -> V_18 = NULL ;
return 0 ;
}
static void F_21 ( struct V_32 * V_33 , struct V_34 * V_35 ,
unsigned long V_36 , unsigned long V_4 , int V_37 , int V_38 )
{
struct V_39 V_40 ;
if ( V_4 == - 1 ) {
if ( V_38 )
V_40 . V_41 = F_22 ( V_33 -> V_42 ) | F_23 ( V_35 -> V_43 ) |
F_24 ( V_44 ) | V_45 ;
else
V_40 . V_41 = F_22 ( V_33 -> V_42 ) | F_23 ( V_35 -> V_43 ) |
F_24 ( V_46 ) | V_45 ;
V_40 . V_47 = 0 ;
} else {
int V_48 = F_25 ( F_26 ( V_4 ) ) ;
V_40 . V_41 = F_22 ( V_33 -> V_42 ) | F_23 ( V_35 -> V_43 ) |
F_24 ( V_49 ) | V_45 ;
V_40 . V_47 = F_27 ( V_36 ) | F_28 ( V_38 ) |
F_29 ( V_37 ) | F_30 ( V_48 ) ;
}
F_31 ( & V_40 , V_33 -> V_2 ) ;
if ( V_35 -> V_50 ) {
V_40 . V_41 = F_32 ( V_33 -> V_42 ) | F_33 ( V_35 -> V_51 ) |
F_34 ( V_35 -> V_52 ) | V_53 ;
if ( V_4 == - 1 ) {
V_40 . V_47 = F_35 ( - 1ULL >> 1 ) | V_54 ;
} else if ( V_4 > 1 ) {
unsigned long V_55 = V_36 + ( ( unsigned long ) ( V_4 - 1 ) << V_56 ) ;
unsigned long V_48 = F_36 ( V_36 ^ V_55 ) ; ;
V_40 . V_47 = F_35 ( ( V_36 & ~ V_48 ) | ( V_48 - 1 ) ) | V_54 ;
} else {
V_40 . V_47 = F_35 ( V_36 ) ;
}
F_31 ( & V_40 , V_33 -> V_2 ) ;
}
}
static void F_37 ( struct V_32 * V_33 , unsigned long V_36 ,
unsigned long V_4 , int V_37 , int V_38 )
{
struct V_34 * V_35 ;
if ( V_33 -> V_2 -> V_13 &&
! F_38 ( & V_33 -> V_2 -> V_13 [ V_33 -> V_42 ] . V_57 , 0 , 1ULL << 63 ) )
return;
F_39 () ;
F_40 (sdev, &svm->devs, list)
F_21 ( V_33 , V_35 , V_36 , V_4 , V_37 , V_38 ) ;
F_41 () ;
}
static void F_42 ( struct V_58 * V_59 , struct V_60 * V_61 ,
unsigned long V_36 , T_1 V_62 )
{
struct V_32 * V_33 = F_43 ( V_59 , struct V_32 , V_63 ) ;
F_37 ( V_33 , V_36 , 1 , 1 , 0 ) ;
}
static void F_44 ( struct V_58 * V_59 , struct V_60 * V_61 ,
unsigned long V_36 )
{
struct V_32 * V_33 = F_43 ( V_59 , struct V_32 , V_63 ) ;
F_37 ( V_33 , V_36 , 1 , 1 , 0 ) ;
}
static void F_45 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
unsigned long V_64 , unsigned long V_65 )
{
struct V_32 * V_33 = F_43 ( V_59 , struct V_32 , V_63 ) ;
F_37 ( V_33 , V_64 ,
( V_65 - V_64 + V_66 - 1 ) >> V_56 , 0 , 0 ) ;
}
static void F_46 ( struct V_32 * V_33 , struct V_34 * V_35 , int V_42 )
{
struct V_39 V_40 ;
V_40 . V_47 = 0 ;
V_40 . V_41 = V_67 | F_47 ( V_35 -> V_43 ) | V_68 | F_48 ( V_42 ) ;
F_31 ( & V_40 , V_33 -> V_2 ) ;
}
static void F_49 ( struct V_58 * V_59 , struct V_60 * V_61 )
{
struct V_32 * V_33 = F_43 ( V_59 , struct V_32 , V_63 ) ;
V_33 -> V_2 -> V_12 [ V_33 -> V_42 ] . V_57 = 0 ;
F_50 ( ! F_51 ( & V_33 -> V_69 ) ) ;
}
int F_52 ( struct V_70 * V_71 , int * V_42 , int V_72 , struct V_73 * V_74 )
{
struct V_1 * V_2 = F_53 ( V_71 ) ;
struct V_34 * V_35 ;
struct V_32 * V_33 = NULL ;
struct V_60 * V_61 = NULL ;
int V_75 ;
int V_16 ;
if ( F_50 ( ! V_2 ) )
return - V_22 ;
if ( F_54 ( V_71 ) ) {
V_75 = F_55 ( F_56 ( V_71 ) ) ;
if ( V_75 < 0 )
return - V_22 ;
} else
V_75 = 1 << 20 ;
if ( ( V_72 & V_76 ) ) {
if ( ! F_57 ( V_2 -> V_6 ) )
return - V_22 ;
} else if ( V_42 ) {
V_61 = F_58 ( V_77 ) ;
F_59 ( ! V_61 ) ;
}
F_60 ( & V_78 ) ;
if ( V_42 && ! ( V_72 & V_79 ) ) {
int V_80 ;
F_61 (&iommu->pasid_idr, svm, i) {
if ( V_33 -> V_61 != V_61 ||
( V_33 -> V_72 & V_79 ) )
continue;
if ( V_33 -> V_42 >= V_75 ) {
F_62 ( V_71 ,
L_8 ,
V_33 -> V_42 ) ;
V_16 = - V_81 ;
goto V_82;
}
F_63 (sdev, &svm->devs, list) {
if ( V_71 == V_35 -> V_71 ) {
if ( V_35 -> V_74 != V_74 ) {
V_16 = - V_83 ;
goto V_82;
}
V_35 -> V_84 ++ ;
goto V_85;
}
}
break;
}
}
V_35 = F_64 ( sizeof( * V_35 ) , V_8 ) ;
if ( ! V_35 ) {
V_16 = - V_11 ;
goto V_82;
}
V_35 -> V_71 = V_71 ;
V_16 = F_65 ( V_2 , V_35 ) ;
if ( V_16 || ! V_42 ) {
F_66 ( V_35 ) ;
goto V_82;
}
V_35 -> V_84 = 1 ;
V_35 -> V_74 = V_74 ;
F_67 ( & V_35 -> V_86 ) ;
if ( ! V_33 ) {
V_33 = F_64 ( sizeof( * V_33 ) , V_8 ) ;
if ( ! V_33 ) {
V_16 = - V_11 ;
F_66 ( V_35 ) ;
goto V_82;
}
V_33 -> V_2 = V_2 ;
if ( V_75 > 2 << F_2 ( V_2 -> V_6 ) )
V_75 = 2 << F_2 ( V_2 -> V_6 ) ;
V_16 = F_68 ( & V_2 -> V_14 , V_33 ,
! ! F_69 ( V_2 -> V_87 ) ,
V_75 - 1 , V_8 ) ;
if ( V_16 < 0 ) {
F_66 ( V_33 ) ;
goto V_82;
}
V_33 -> V_42 = V_16 ;
V_33 -> V_63 . V_74 = & V_88 ;
V_33 -> V_61 = V_61 ;
V_33 -> V_72 = V_72 ;
F_70 ( & V_33 -> V_69 ) ;
V_16 = - V_11 ;
if ( V_61 ) {
V_16 = F_71 ( & V_33 -> V_63 , V_61 ) ;
if ( V_16 ) {
F_72 ( & V_33 -> V_2 -> V_14 , V_33 -> V_42 ) ;
F_66 ( V_33 ) ;
F_66 ( V_35 ) ;
goto V_82;
}
V_2 -> V_12 [ V_33 -> V_42 ] . V_57 = ( V_89 ) F_73 ( V_61 -> V_90 ) | 1 ;
V_61 = NULL ;
} else
V_2 -> V_12 [ V_33 -> V_42 ] . V_57 = ( V_89 ) F_73 ( V_91 . V_90 ) | 1 | ( 1ULL << 11 ) ;
F_74 () ;
if ( F_69 ( V_2 -> V_87 ) )
F_46 ( V_33 , V_35 , 0 ) ;
}
F_75 ( & V_35 -> V_92 , & V_33 -> V_69 ) ;
V_85:
* V_42 = V_33 -> V_42 ;
V_16 = 0 ;
V_82:
F_76 ( & V_78 ) ;
if ( V_61 )
F_77 ( V_61 ) ;
return V_16 ;
}
int F_78 ( struct V_70 * V_71 , int V_42 )
{
struct V_34 * V_35 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
int V_16 = - V_22 ;
F_60 ( & V_78 ) ;
V_2 = F_53 ( V_71 ) ;
if ( ! V_2 || ! V_2 -> V_12 )
goto V_82;
V_33 = F_79 ( & V_2 -> V_14 , V_42 ) ;
if ( ! V_33 )
goto V_82;
F_63 (sdev, &svm->devs, list) {
if ( V_71 == V_35 -> V_71 ) {
V_16 = 0 ;
V_35 -> V_84 -- ;
if ( ! V_35 -> V_84 ) {
F_80 ( & V_35 -> V_92 ) ;
F_46 ( V_33 , V_35 , V_33 -> V_42 ) ;
F_21 ( V_33 , V_35 , 0 , - 1 , 0 , ! V_33 -> V_61 ) ;
F_81 ( V_35 , V_86 ) ;
if ( F_51 ( & V_33 -> V_69 ) ) {
F_82 ( & V_33 -> V_63 , V_33 -> V_61 ) ;
F_72 ( & V_33 -> V_2 -> V_14 , V_33 -> V_42 ) ;
if ( V_33 -> V_61 )
F_77 ( V_33 -> V_61 ) ;
memset ( V_33 , 0x6b , sizeof( * V_33 ) ) ;
F_66 ( V_33 ) ;
}
}
break;
}
}
V_82:
F_76 ( & V_78 ) ;
return V_16 ;
}
static bool F_83 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
unsigned long V_97 = 0 ;
if ( V_96 -> V_98 )
V_97 |= V_99 ;
if ( V_96 -> V_100 )
V_97 |= V_101 ;
if ( V_96 -> V_102 )
V_97 |= V_103 ;
return ( V_97 & ~ V_94 -> V_104 ) != 0 ;
}
static T_2 V_26 ( int V_15 , void * V_105 )
{
struct V_1 * V_2 = V_105 ;
struct V_32 * V_33 = NULL ;
int V_106 , V_107 , V_108 = 0 ;
V_107 = F_84 ( V_2 -> V_28 + V_30 ) & V_109 ;
V_106 = F_84 ( V_2 -> V_28 + V_29 ) & V_109 ;
while ( V_106 != V_107 ) {
struct V_34 * V_35 ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
struct V_39 V_110 ;
int V_16 , V_111 ;
V_89 V_36 ;
V_108 = 1 ;
V_96 = & V_2 -> V_18 [ V_106 / sizeof( * V_96 ) ] ;
V_111 = V_112 ;
V_36 = ( V_89 ) V_96 -> V_113 << V_56 ;
if ( ! V_96 -> V_114 ) {
F_14 ( L_9 ,
V_2 -> V_10 , ( ( unsigned long long * ) V_96 ) [ 0 ] ,
( ( unsigned long long * ) V_96 ) [ 1 ] ) ;
goto V_115;
}
if ( ! V_33 || V_33 -> V_42 != V_96 -> V_42 ) {
F_39 () ;
V_33 = F_79 ( & V_2 -> V_14 , V_96 -> V_42 ) ;
F_41 () ;
if ( ! V_33 ) {
F_14 ( L_10 ,
V_2 -> V_10 , V_96 -> V_42 , ( ( unsigned long long * ) V_96 ) [ 0 ] ,
( ( unsigned long long * ) V_96 ) [ 1 ] ) ;
goto V_116;
}
}
V_111 = V_117 ;
if ( ! V_33 -> V_61 )
goto V_115;
F_85 ( & V_33 -> V_61 -> V_118 ) ;
V_94 = F_86 ( V_33 -> V_61 , V_36 ) ;
if ( ! V_94 || V_36 < V_94 -> V_119 )
goto V_120;
if ( F_83 ( V_94 , V_96 ) )
goto V_120;
V_16 = F_87 ( V_33 -> V_61 , V_94 , V_36 ,
V_96 -> V_102 ? V_121 : 0 ) ;
if ( V_16 & V_122 )
goto V_120;
V_111 = V_123 ;
V_120:
F_88 ( & V_33 -> V_61 -> V_118 ) ;
V_115:
F_39 () ;
F_40 (sdev, &svm->devs, list) {
if ( V_35 -> V_51 == F_89 ( V_96 -> V_124 , V_96 -> V_125 ) )
break;
}
F_41 () ;
if ( F_50 ( & V_35 -> V_92 == & V_33 -> V_69 ) )
V_35 = NULL ;
if ( V_35 && V_35 -> V_74 && V_35 -> V_74 -> V_126 ) {
int V_127 = ( V_96 -> V_100 << 3 ) | ( V_96 -> V_102 << 2 ) |
( V_96 -> V_98 << 1 ) | ( V_96 -> V_128 ) ;
V_35 -> V_74 -> V_126 ( V_35 -> V_71 , V_96 -> V_42 , V_96 -> V_113 , V_96 -> V_129 , V_127 , V_111 ) ;
}
V_35 = NULL ;
V_33 = NULL ;
V_116:
if ( V_96 -> V_130 ) {
V_110 . V_41 = F_90 ( V_96 -> V_42 ) |
F_91 ( ( V_96 -> V_124 << 8 ) | V_96 -> V_125 ) |
F_92 ( V_96 -> V_114 ) |
V_131 ;
V_110 . V_47 = F_93 ( V_96 -> V_132 ) |
F_94 ( V_96 -> V_129 ) | F_95 ( V_111 ) ;
F_31 ( & V_110 , V_2 ) ;
} else if ( V_96 -> V_133 ) {
V_110 . V_41 = F_96 ( V_96 -> V_132 ) |
F_97 ( V_96 -> V_129 ) | F_98 ( V_96 -> V_124 ) |
F_99 ( V_96 -> V_42 ) | V_134 ;
V_110 . V_47 = F_100 ( V_36 ) | F_101 ( V_96 -> V_125 ) |
F_102 ( V_111 ) ;
F_31 ( & V_110 , V_2 ) ;
}
V_106 = ( V_106 + sizeof( * V_96 ) ) & V_109 ;
}
F_17 ( V_2 -> V_28 + V_29 , V_107 ) ;
return F_103 ( V_108 ) ;
}
