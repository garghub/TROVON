int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_2 -> V_6 = 2 << F_2 ( V_2 -> V_7 ) ;
if ( V_2 -> V_6 > 0x20000 )
V_2 -> V_6 = 0x20000 ;
V_5 = F_3 ( sizeof( struct V_8 ) * V_2 -> V_6 ) ;
V_4 = F_4 ( V_9 | V_10 , V_5 ) ;
if ( ! V_4 ) {
F_5 ( L_1 ,
V_2 -> V_11 ) ;
return - V_12 ;
}
V_2 -> V_13 = F_6 ( V_4 ) ;
F_7 ( L_2 , V_2 -> V_11 , V_5 ) ;
if ( F_8 ( V_2 -> V_7 ) ) {
F_9 ( sizeof( struct V_8 ) != sizeof( struct V_14 ) ) ;
V_4 = F_4 ( V_9 | V_10 , V_5 ) ;
if ( V_4 )
V_2 -> V_15 = F_6 ( V_4 ) ;
else
F_5 ( L_3 ,
V_2 -> V_11 ) ;
}
F_10 ( & V_2 -> V_16 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_5 = F_3 ( sizeof( struct V_8 ) * V_2 -> V_6 ) ;
if ( V_2 -> V_13 ) {
F_12 ( ( unsigned long ) V_2 -> V_13 , V_5 ) ;
V_2 -> V_13 = NULL ;
}
if ( V_2 -> V_15 ) {
F_12 ( ( unsigned long ) V_2 -> V_15 , V_5 ) ;
V_2 -> V_15 = NULL ;
}
F_13 ( & V_2 -> V_16 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_17 , V_18 ;
V_4 = F_4 ( V_9 | V_10 , V_19 ) ;
if ( ! V_4 ) {
F_5 ( L_4 ,
V_2 -> V_11 ) ;
return - V_12 ;
}
V_2 -> V_20 = F_6 ( V_4 ) ;
V_17 = F_15 ( V_21 + V_2 -> V_22 , V_2 -> V_23 , V_2 ) ;
if ( V_17 <= 0 ) {
F_16 ( L_5 ,
V_2 -> V_11 ) ;
V_18 = - V_24 ;
V_25:
F_12 ( ( unsigned long ) V_2 -> V_20 , V_19 ) ;
V_2 -> V_20 = NULL ;
return V_18 ;
}
V_2 -> V_26 = V_17 ;
snprintf ( V_2 -> V_27 , sizeof( V_2 -> V_27 ) , L_6 , V_2 -> V_22 ) ;
V_18 = F_17 ( V_17 , NULL , V_28 , V_29 ,
V_2 -> V_27 , V_2 ) ;
if ( V_18 ) {
F_16 ( L_7 ,
V_2 -> V_11 ) ;
F_18 ( V_17 ) ;
goto V_25;
}
F_19 ( V_2 -> V_30 + V_31 , 0ULL ) ;
F_19 ( V_2 -> V_30 + V_32 , 0ULL ) ;
F_19 ( V_2 -> V_30 + V_33 , F_20 ( V_2 -> V_20 ) | V_19 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> V_30 + V_31 , 0ULL ) ;
F_19 ( V_2 -> V_30 + V_32 , 0ULL ) ;
F_19 ( V_2 -> V_30 + V_33 , 0ULL ) ;
F_22 ( V_2 -> V_26 , V_2 ) ;
F_18 ( V_2 -> V_26 ) ;
V_2 -> V_26 = 0 ;
F_12 ( ( unsigned long ) V_2 -> V_20 , V_19 ) ;
V_2 -> V_20 = NULL ;
return 0 ;
}
static void F_23 ( struct V_34 * V_35 , struct V_36 * V_37 ,
unsigned long V_38 , unsigned long V_4 , int V_39 , int V_40 )
{
struct V_41 V_42 ;
if ( V_4 == - 1 ) {
if ( V_40 )
V_42 . V_43 = F_24 ( V_35 -> V_44 ) | F_25 ( V_37 -> V_45 ) |
F_26 ( V_46 ) | V_47 ;
else
V_42 . V_43 = F_24 ( V_35 -> V_44 ) | F_25 ( V_37 -> V_45 ) |
F_26 ( V_48 ) | V_47 ;
V_42 . V_49 = 0 ;
} else {
int V_50 = F_27 ( F_28 ( V_4 ) ) ;
V_42 . V_43 = F_24 ( V_35 -> V_44 ) | F_25 ( V_37 -> V_45 ) |
F_26 ( V_51 ) | V_47 ;
V_42 . V_49 = F_29 ( V_38 ) | F_30 ( V_40 ) |
F_31 ( V_39 ) | F_32 ( V_50 ) ;
}
F_33 ( & V_42 , V_35 -> V_2 ) ;
if ( V_37 -> V_52 ) {
V_42 . V_43 = F_34 ( V_35 -> V_44 ) | F_35 ( V_37 -> V_53 ) |
F_36 ( V_37 -> V_54 ) | V_55 ;
if ( V_4 == - 1 ) {
V_42 . V_49 = F_37 ( - 1ULL >> 1 ) | V_56 ;
} else if ( V_4 > 1 ) {
unsigned long V_57 = V_38 + ( ( unsigned long ) ( V_4 - 1 ) << V_58 ) ;
unsigned long V_50 = F_38 ( V_38 ^ V_57 ) ; ;
V_42 . V_49 = F_37 ( ( V_38 & ~ V_50 ) | ( V_50 - 1 ) ) | V_56 ;
} else {
V_42 . V_49 = F_37 ( V_38 ) ;
}
F_33 ( & V_42 , V_35 -> V_2 ) ;
}
}
static void F_39 ( struct V_34 * V_35 , unsigned long V_38 ,
unsigned long V_4 , int V_39 , int V_40 )
{
struct V_36 * V_37 ;
if ( V_35 -> V_2 -> V_15 &&
! F_40 ( & V_35 -> V_2 -> V_15 [ V_35 -> V_44 ] . V_59 , 0 , 1ULL << 63 ) )
return;
F_41 () ;
F_42 (sdev, &svm->devs, list)
F_23 ( V_35 , V_37 , V_38 , V_4 , V_39 , V_40 ) ;
F_43 () ;
}
static void F_44 ( struct V_60 * V_61 , struct V_62 * V_63 ,
unsigned long V_38 , T_1 V_64 )
{
struct V_34 * V_35 = F_45 ( V_61 , struct V_34 , V_65 ) ;
F_39 ( V_35 , V_38 , 1 , 1 , 0 ) ;
}
static void F_46 ( struct V_60 * V_61 , struct V_62 * V_63 ,
unsigned long V_38 )
{
struct V_34 * V_35 = F_45 ( V_61 , struct V_34 , V_65 ) ;
F_39 ( V_35 , V_38 , 1 , 1 , 0 ) ;
}
static void F_47 ( struct V_60 * V_61 ,
struct V_62 * V_63 ,
unsigned long V_66 , unsigned long V_67 )
{
struct V_34 * V_35 = F_45 ( V_61 , struct V_34 , V_65 ) ;
F_39 ( V_35 , V_66 ,
( V_67 - V_66 + V_68 - 1 ) >> V_58 , 0 , 0 ) ;
}
static void F_48 ( struct V_34 * V_35 , struct V_36 * V_37 , int V_44 )
{
struct V_41 V_42 ;
V_42 . V_49 = 0 ;
V_42 . V_43 = V_69 | F_49 ( V_37 -> V_45 ) | V_70 | F_50 ( V_44 ) ;
F_33 ( & V_42 , V_35 -> V_2 ) ;
}
static void F_51 ( struct V_60 * V_61 , struct V_62 * V_63 )
{
struct V_34 * V_35 = F_45 ( V_61 , struct V_34 , V_65 ) ;
struct V_36 * V_37 ;
V_35 -> V_2 -> V_13 [ V_35 -> V_44 ] . V_59 = 0 ;
F_52 () ;
F_41 () ;
F_42 (sdev, &svm->devs, list) {
F_48 ( V_35 , V_37 , V_35 -> V_44 ) ;
F_23 ( V_35 , V_37 , 0 , - 1 , 0 , ! V_35 -> V_63 ) ;
}
F_43 () ;
}
int F_53 ( struct V_71 * V_72 , int * V_44 , int V_73 , struct V_74 * V_75 )
{
struct V_1 * V_2 = F_54 ( V_72 ) ;
struct V_36 * V_37 ;
struct V_34 * V_35 = NULL ;
struct V_62 * V_63 = NULL ;
int V_6 ;
int V_18 ;
if ( F_55 ( ! V_2 ) )
return - V_24 ;
if ( F_56 ( V_72 ) ) {
V_6 = F_57 ( F_58 ( V_72 ) ) ;
if ( V_6 < 0 )
return - V_24 ;
} else
V_6 = 1 << 20 ;
if ( ( V_73 & V_76 ) ) {
if ( ! F_59 ( V_2 -> V_7 ) )
return - V_24 ;
} else if ( V_44 ) {
V_63 = F_60 ( V_77 ) ;
F_61 ( ! V_63 ) ;
}
F_62 ( & V_78 ) ;
if ( V_44 && ! ( V_73 & V_79 ) ) {
int V_80 ;
F_63 (&iommu->pasid_idr, svm, i) {
if ( V_35 -> V_63 != V_63 ||
( V_35 -> V_73 & V_79 ) )
continue;
if ( V_35 -> V_44 >= V_6 ) {
F_64 ( V_72 ,
L_8 ,
V_35 -> V_44 ) ;
V_18 = - V_81 ;
goto V_82;
}
F_65 (sdev, &svm->devs, list) {
if ( V_72 == V_37 -> V_72 ) {
if ( V_37 -> V_75 != V_75 ) {
V_18 = - V_83 ;
goto V_82;
}
V_37 -> V_84 ++ ;
goto V_85;
}
}
break;
}
}
V_37 = F_66 ( sizeof( * V_37 ) , V_9 ) ;
if ( ! V_37 ) {
V_18 = - V_12 ;
goto V_82;
}
V_37 -> V_72 = V_72 ;
V_18 = F_67 ( V_2 , V_37 ) ;
if ( V_18 || ! V_44 ) {
F_68 ( V_37 ) ;
goto V_82;
}
V_37 -> V_84 = 1 ;
V_37 -> V_75 = V_75 ;
F_69 ( & V_37 -> V_86 ) ;
if ( ! V_35 ) {
V_35 = F_66 ( sizeof( * V_35 ) , V_9 ) ;
if ( ! V_35 ) {
V_18 = - V_12 ;
F_68 ( V_37 ) ;
goto V_82;
}
V_35 -> V_2 = V_2 ;
if ( V_6 > V_2 -> V_6 )
V_6 = V_2 -> V_6 ;
V_18 = F_70 ( & V_2 -> V_16 , V_35 ,
! ! F_71 ( V_2 -> V_87 ) ,
V_6 - 1 , V_9 ) ;
if ( V_18 < 0 ) {
F_68 ( V_35 ) ;
goto V_82;
}
V_35 -> V_44 = V_18 ;
V_35 -> V_65 . V_75 = & V_88 ;
V_35 -> V_63 = V_63 ;
V_35 -> V_73 = V_73 ;
F_72 ( & V_35 -> V_89 ) ;
V_18 = - V_12 ;
if ( V_63 ) {
V_18 = F_73 ( & V_35 -> V_65 , V_63 ) ;
if ( V_18 ) {
F_74 ( & V_35 -> V_2 -> V_16 , V_35 -> V_44 ) ;
F_68 ( V_35 ) ;
F_68 ( V_37 ) ;
goto V_82;
}
V_2 -> V_13 [ V_35 -> V_44 ] . V_59 = ( V_90 ) F_75 ( V_63 -> V_91 ) | 1 ;
} else
V_2 -> V_13 [ V_35 -> V_44 ] . V_59 = ( V_90 ) F_75 ( V_92 . V_91 ) | 1 | ( 1ULL << 11 ) ;
F_52 () ;
if ( F_71 ( V_2 -> V_87 ) )
F_48 ( V_35 , V_37 , 0 ) ;
}
F_76 ( & V_37 -> V_93 , & V_35 -> V_89 ) ;
V_85:
* V_44 = V_35 -> V_44 ;
V_18 = 0 ;
V_82:
F_77 ( & V_78 ) ;
if ( V_63 )
F_78 ( V_63 ) ;
return V_18 ;
}
int F_79 ( struct V_71 * V_72 , int V_44 )
{
struct V_36 * V_37 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_18 = - V_24 ;
F_62 ( & V_78 ) ;
V_2 = F_54 ( V_72 ) ;
if ( ! V_2 || ! V_2 -> V_13 )
goto V_82;
V_35 = F_80 ( & V_2 -> V_16 , V_44 ) ;
if ( ! V_35 )
goto V_82;
F_65 (sdev, &svm->devs, list) {
if ( V_72 == V_37 -> V_72 ) {
V_18 = 0 ;
V_37 -> V_84 -- ;
if ( ! V_37 -> V_84 ) {
F_81 ( & V_37 -> V_93 ) ;
F_48 ( V_35 , V_37 , V_35 -> V_44 ) ;
F_23 ( V_35 , V_37 , 0 , - 1 , 0 , ! V_35 -> V_63 ) ;
F_82 ( V_37 , V_86 ) ;
if ( F_83 ( & V_35 -> V_89 ) ) {
F_74 ( & V_35 -> V_2 -> V_16 , V_35 -> V_44 ) ;
if ( V_35 -> V_63 )
F_84 ( & V_35 -> V_65 , V_35 -> V_63 ) ;
memset ( V_35 , 0x6b , sizeof( * V_35 ) ) ;
F_68 ( V_35 ) ;
}
}
break;
}
}
V_82:
F_77 ( & V_78 ) ;
return V_18 ;
}
static bool F_85 ( struct V_94 * V_95 , struct V_96 * V_97 )
{
unsigned long V_98 = 0 ;
if ( V_97 -> V_99 )
V_98 |= V_100 ;
if ( V_97 -> V_101 )
V_98 |= V_102 ;
if ( V_97 -> V_103 )
V_98 |= V_104 ;
return ( V_98 & ~ V_95 -> V_105 ) != 0 ;
}
static T_2 V_28 ( int V_17 , void * V_106 )
{
struct V_1 * V_2 = V_106 ;
struct V_34 * V_35 = NULL ;
int V_107 , V_108 , V_109 = 0 ;
F_86 ( V_110 , V_2 -> V_30 + V_111 ) ;
V_108 = F_87 ( V_2 -> V_30 + V_32 ) & V_112 ;
V_107 = F_87 ( V_2 -> V_30 + V_31 ) & V_112 ;
while ( V_107 != V_108 ) {
struct V_36 * V_37 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_41 V_113 ;
int V_18 , V_114 ;
V_90 V_38 ;
V_109 = 1 ;
V_97 = & V_2 -> V_20 [ V_107 / sizeof( * V_97 ) ] ;
V_114 = V_115 ;
V_38 = ( V_90 ) V_97 -> V_116 << V_58 ;
if ( ! V_97 -> V_117 ) {
F_16 ( L_9 ,
V_2 -> V_11 , ( ( unsigned long long * ) V_97 ) [ 0 ] ,
( ( unsigned long long * ) V_97 ) [ 1 ] ) ;
goto V_118;
}
if ( ! V_35 || V_35 -> V_44 != V_97 -> V_44 ) {
F_41 () ;
V_35 = F_80 ( & V_2 -> V_16 , V_97 -> V_44 ) ;
F_43 () ;
if ( ! V_35 ) {
F_16 ( L_10 ,
V_2 -> V_11 , V_97 -> V_44 , ( ( unsigned long long * ) V_97 ) [ 0 ] ,
( ( unsigned long long * ) V_97 ) [ 1 ] ) ;
goto V_119;
}
}
V_114 = V_120 ;
if ( ! V_35 -> V_63 )
goto V_118;
if ( ! F_88 ( V_35 -> V_63 ) )
goto V_118;
F_89 ( & V_35 -> V_63 -> V_121 ) ;
V_95 = F_90 ( V_35 -> V_63 , V_38 ) ;
if ( ! V_95 || V_38 < V_95 -> V_122 )
goto V_123;
if ( F_85 ( V_95 , V_97 ) )
goto V_123;
V_18 = F_91 ( V_95 , V_38 ,
V_97 -> V_103 ? V_124 : 0 ) ;
if ( V_18 & V_125 )
goto V_123;
V_114 = V_126 ;
V_123:
F_92 ( & V_35 -> V_63 -> V_121 ) ;
F_78 ( V_35 -> V_63 ) ;
V_118:
F_41 () ;
F_42 (sdev, &svm->devs, list) {
if ( V_37 -> V_53 == F_93 ( V_97 -> V_127 , V_97 -> V_128 ) )
break;
}
F_43 () ;
if ( F_55 ( & V_37 -> V_93 == & V_35 -> V_89 ) )
V_37 = NULL ;
if ( V_37 && V_37 -> V_75 && V_37 -> V_75 -> V_129 ) {
int V_130 = ( V_97 -> V_101 << 3 ) | ( V_97 -> V_103 << 2 ) |
( V_97 -> V_99 << 1 ) | ( V_97 -> V_131 ) ;
V_37 -> V_75 -> V_129 ( V_37 -> V_72 , V_97 -> V_44 , V_97 -> V_116 , V_97 -> V_132 , V_130 , V_114 ) ;
}
V_37 = NULL ;
V_35 = NULL ;
V_119:
if ( V_97 -> V_133 ) {
V_113 . V_43 = F_94 ( V_97 -> V_44 ) |
F_95 ( ( V_97 -> V_127 << 8 ) | V_97 -> V_128 ) |
F_96 ( V_97 -> V_117 ) |
V_134 ;
V_113 . V_49 = F_97 ( V_97 -> V_135 ) |
F_98 ( V_97 -> V_132 ) | F_99 ( V_114 ) ;
F_33 ( & V_113 , V_2 ) ;
} else if ( V_97 -> V_136 ) {
V_113 . V_43 = F_100 ( V_97 -> V_135 ) |
F_101 ( V_97 -> V_132 ) | F_102 ( V_97 -> V_127 ) |
F_103 ( V_97 -> V_44 ) | V_137 ;
V_113 . V_49 = F_104 ( V_38 ) | F_105 ( V_97 -> V_128 ) |
F_106 ( V_114 ) ;
F_33 ( & V_113 , V_2 ) ;
}
V_107 = ( V_107 + sizeof( * V_97 ) ) & V_112 ;
}
F_19 ( V_2 -> V_30 + V_31 , V_108 ) ;
return F_107 ( V_109 ) ;
}
