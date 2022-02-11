static int T_1 F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
F_2 ( V_3 + V_1 ) ;
return 0 ;
}
static unsigned long F_3 ( void * V_4 )
{
return ( unsigned long ) V_4 >> V_5 ;
}
static void * F_4 ( T_2 V_6 , unsigned long V_7 )
{
return ( void * ) ( V_8 | V_7 |
( ( unsigned long ) V_6 << V_5 ) |
V_9 ) ;
}
static unsigned int F_5 ( void * V_4 )
{
if ( ( unsigned long ) V_4 & V_10 )
return V_11 - V_12 ;
return 0 ;
}
static int F_6 ( void * V_4 )
{
return ( unsigned long ) V_4 & V_10 ;
}
static int F_7 ( void * V_4 )
{
return ! ( ( unsigned long ) V_4 & V_10 ) ;
}
static int F_8 ( void * V_4 )
{
return ( unsigned long ) V_4 & V_13 ;
}
static int F_9 ( void * V_4 )
{
return ( unsigned long ) V_4 & V_14 ;
}
static T_3 * F_10 ( struct V_15 * V_16 ,
T_4 V_17 , void * V_4 , struct V_18 * V_19 )
{
unsigned long V_20 ;
if ( F_6 ( V_4 ) )
V_17 &= ~ V_21 ;
V_19 -> V_16 = V_16 ;
V_19 -> V_22 = V_17 ;
V_20 = F_11 ( ( unsigned long ) V_16 ^ V_17 , V_23 ) ;
return V_3 + V_20 ;
}
static int F_12 ( T_5 * V_24 , unsigned int V_25 ,
int V_26 , void * V_27 )
{
struct V_18 * V_19 = V_27 ;
struct V_28 * V_29 =
F_13 ( V_24 , struct V_28 , V_24 ) ;
if ( V_19 -> V_16 != V_29 -> V_19 . V_16 ||
V_19 -> V_22 != V_29 -> V_19 . V_22 )
return 0 ;
return F_14 ( V_24 , V_25 , V_26 , NULL ) ;
}
static void F_15 ( struct V_15 * V_16 ,
T_4 V_17 , void * V_4 , bool V_30 )
{
struct V_18 V_19 ;
T_3 * V_31 ;
V_31 = F_10 ( V_16 , V_17 , V_4 , & V_19 ) ;
if ( F_16 ( V_31 ) )
F_17 ( V_31 , V_32 , V_30 ? 0 : 1 , & V_19 ) ;
}
static inline int F_18 ( struct V_15 * V_16 , void * * V_33 )
{
unsigned long V_4 = ( unsigned long )
F_19 ( V_33 , & V_16 -> V_34 ) ;
return V_4 & V_9 ;
}
static inline void * F_20 ( struct V_15 * V_16 , void * * V_33 )
{
unsigned long V_4 = ( unsigned long )
F_19 ( V_33 , & V_16 -> V_34 ) ;
V_4 |= V_9 ;
F_21 ( & V_16 -> V_35 , V_33 , ( void * ) V_4 ) ;
return ( void * ) V_4 ;
}
static inline void * F_22 ( struct V_15 * V_16 , void * * V_33 )
{
unsigned long V_4 = ( unsigned long )
F_19 ( V_33 , & V_16 -> V_34 ) ;
V_4 &= ~ ( unsigned long ) V_9 ;
F_21 ( & V_16 -> V_35 , V_33 , ( void * ) V_4 ) ;
return ( void * ) V_4 ;
}
static void * F_23 ( struct V_15 * V_16 ,
T_4 V_17 , void * * * V_36 )
{
void * V_4 , * * V_33 ;
struct V_28 V_29 ;
T_3 * V_31 ;
F_24 ( & V_29 . V_24 ) ;
V_29 . V_24 . V_37 = F_12 ;
for (; ; ) {
V_4 = F_25 ( & V_16 -> V_35 , V_17 , NULL ,
& V_33 ) ;
if ( ! V_4 ||
F_26 ( ! F_27 ( V_4 ) ) ||
! F_18 ( V_16 , V_33 ) ) {
if ( V_36 )
* V_36 = V_33 ;
return V_4 ;
}
V_31 = F_10 ( V_16 , V_17 , V_4 , & V_29 . V_19 ) ;
F_28 ( V_31 , & V_29 . V_24 ,
V_38 ) ;
F_29 ( & V_16 -> V_34 ) ;
F_30 () ;
F_31 ( V_31 , & V_29 . V_24 ) ;
F_32 ( & V_16 -> V_34 ) ;
}
}
static void F_33 ( struct V_15 * V_16 ,
T_4 V_17 )
{
void * V_4 , * * V_33 ;
F_32 ( & V_16 -> V_34 ) ;
V_4 = F_25 ( & V_16 -> V_35 , V_17 , NULL , & V_33 ) ;
if ( F_26 ( ! V_4 || ! F_27 ( V_4 ) ||
! F_18 ( V_16 , V_33 ) ) ) {
F_29 ( & V_16 -> V_34 ) ;
return;
}
F_22 ( V_16 , V_33 ) ;
F_29 ( & V_16 -> V_34 ) ;
F_15 ( V_16 , V_17 , V_4 , false ) ;
}
static void F_34 ( struct V_15 * V_16 ,
T_4 V_17 )
{
F_33 ( V_16 , V_17 ) ;
}
static void F_35 ( struct V_15 * V_16 ,
T_4 V_17 , void * V_4 )
{
if ( ! V_4 )
return;
F_15 ( V_16 , V_17 , V_4 , false ) ;
}
static void * F_36 ( struct V_15 * V_16 , T_4 V_17 ,
unsigned long V_39 )
{
bool V_40 = false ;
void * V_4 , * * V_33 ;
V_41:
F_32 ( & V_16 -> V_34 ) ;
V_4 = F_23 ( V_16 , V_17 , & V_33 ) ;
if ( F_26 ( V_4 && ! F_27 ( V_4 ) ) ) {
V_4 = F_37 ( - V_42 ) ;
goto V_43;
}
if ( V_4 ) {
if ( V_39 & V_10 ) {
if ( F_7 ( V_4 ) ) {
F_35 ( V_16 , V_17 ,
V_4 ) ;
V_4 = F_37 ( - V_44 ) ;
goto V_43;
}
} else {
if ( F_6 ( V_4 ) &&
( F_8 ( V_4 ) ||
F_9 ( V_4 ) ) ) {
V_40 = true ;
}
}
}
if ( ! V_4 || V_40 ) {
int V_45 ;
if ( V_40 ) {
V_4 = F_20 ( V_16 , V_33 ) ;
}
F_29 ( & V_16 -> V_34 ) ;
if ( V_40 && F_8 ( V_4 ) )
F_38 ( V_16 ,
( V_17 << V_12 ) & V_46 , V_47 , 0 ) ;
V_45 = F_39 (
F_40 ( V_16 ) & ~ V_48 ) ;
if ( V_45 ) {
if ( V_40 )
F_34 ( V_16 , V_17 ) ;
return F_37 ( V_45 ) ;
}
F_32 ( & V_16 -> V_34 ) ;
if ( ! V_4 ) {
V_4 = F_25 ( & V_16 -> V_35 , V_17 ,
NULL , & V_33 ) ;
if ( V_4 ) {
F_41 () ;
F_29 ( & V_16 -> V_34 ) ;
goto V_41;
}
}
if ( V_40 ) {
F_42 ( & V_16 -> V_35 , V_17 ) ;
V_16 -> V_49 -- ;
F_15 ( V_16 , V_17 , V_4 ,
true ) ;
}
V_4 = F_4 ( 0 , V_39 | V_14 ) ;
V_45 = F_43 ( & V_16 -> V_35 , V_17 ,
F_5 ( V_4 ) , V_4 ) ;
F_41 () ;
if ( V_45 ) {
F_29 ( & V_16 -> V_34 ) ;
return F_37 ( V_45 ) ;
}
V_16 -> V_49 ++ ;
F_29 ( & V_16 -> V_34 ) ;
return V_4 ;
}
V_4 = F_20 ( V_16 , V_33 ) ;
V_43:
F_29 ( & V_16 -> V_34 ) ;
return V_4 ;
}
static int F_44 ( struct V_15 * V_16 ,
T_4 V_17 , bool V_50 )
{
int V_51 = 0 ;
void * V_4 ;
struct V_52 * V_35 = & V_16 -> V_35 ;
F_32 ( & V_16 -> V_34 ) ;
V_4 = F_23 ( V_16 , V_17 , NULL ) ;
if ( ! V_4 || F_26 ( ! F_27 ( V_4 ) ) )
goto V_53;
if ( ! V_50 &&
( F_45 ( V_35 , V_17 , V_54 ) ||
F_45 ( V_35 , V_17 , V_55 ) ) )
goto V_53;
F_42 ( V_35 , V_17 ) ;
V_16 -> V_49 -- ;
V_51 = 1 ;
V_53:
F_35 ( V_16 , V_17 , V_4 ) ;
F_29 ( & V_16 -> V_34 ) ;
return V_51 ;
}
int F_46 ( struct V_15 * V_16 , T_4 V_17 )
{
int V_51 = F_44 ( V_16 , V_17 , true ) ;
F_26 ( ! V_51 ) ;
return V_51 ;
}
int F_47 ( struct V_15 * V_16 ,
T_4 V_17 )
{
return F_44 ( V_16 , V_17 , false ) ;
}
static int F_48 ( struct V_56 * V_57 , struct V_58 * V_59 ,
T_2 V_6 , T_6 V_60 , struct V_61 * V_62 ,
unsigned long V_63 )
{
void * V_64 , * V_65 ;
T_4 V_66 ;
T_7 V_67 ;
long V_68 ;
int V_69 ;
V_68 = F_49 ( V_57 , V_6 , V_60 , & V_66 ) ;
if ( V_68 )
return V_68 ;
V_69 = F_50 () ;
V_68 = F_51 ( V_59 , V_66 , F_52 ( V_60 ) , & V_65 , & V_67 ) ;
if ( V_68 < 0 ) {
F_53 ( V_69 ) ;
return V_68 ;
}
V_64 = F_54 ( V_62 ) ;
F_55 ( V_64 , ( void V_70 * ) V_65 , V_63 , V_62 ) ;
F_56 ( V_64 ) ;
F_53 ( V_69 ) ;
return 0 ;
}
static void * F_57 ( struct V_15 * V_16 ,
struct V_71 * V_72 ,
void * V_4 , T_2 V_6 ,
unsigned long V_7 )
{
struct V_52 * V_35 = & V_16 -> V_35 ;
void * V_73 ;
T_4 V_17 = V_72 -> V_66 ;
if ( V_72 -> V_7 & V_74 )
F_58 ( V_16 -> V_75 , V_76 ) ;
if ( F_8 ( V_4 ) && ! ( V_7 & V_13 ) ) {
if ( F_6 ( V_4 ) )
F_38 ( V_16 ,
( V_72 -> V_66 << V_12 ) & V_46 ,
V_47 , 0 ) ;
else
F_38 ( V_16 , V_72 -> V_66 << V_12 ,
V_77 , 0 ) ;
}
F_32 ( & V_16 -> V_34 ) ;
V_73 = F_4 ( V_6 , V_7 ) ;
if ( F_8 ( V_4 ) || F_9 ( V_4 ) ) {
struct V_78 * V_79 ;
void * * V_33 ;
void * V_51 ;
V_51 = F_25 ( V_35 , V_17 , & V_79 , & V_33 ) ;
F_26 ( V_51 != V_4 ) ;
F_59 ( V_35 , V_79 , V_33 ,
V_73 , NULL , NULL ) ;
V_4 = V_73 ;
}
if ( V_72 -> V_7 & V_74 )
F_60 ( V_35 , V_17 , V_54 ) ;
F_29 ( & V_16 -> V_34 ) ;
return V_4 ;
}
static inline unsigned long
F_61 ( T_4 V_66 , struct V_80 * V_81 )
{
unsigned long V_82 ;
V_82 = V_81 -> V_83 + ( ( V_66 - V_81 -> V_84 ) << V_12 ) ;
F_62 ( V_82 < V_81 -> V_83 || V_82 >= V_81 -> V_85 , V_81 ) ;
return V_82 ;
}
static void F_63 ( struct V_15 * V_16 ,
T_4 V_17 , unsigned long V_67 )
{
struct V_80 * V_81 ;
T_8 V_86 , * V_87 = NULL ;
T_9 * V_88 = NULL ;
T_10 * V_89 ;
F_64 ( V_16 ) ;
F_65 (vma, &mapping->i_mmap, index, index) {
unsigned long V_82 , V_90 , V_91 ;
F_66 () ;
if ( ! ( V_81 -> V_92 & V_93 ) )
continue;
V_82 = F_61 ( V_17 , V_81 ) ;
if ( F_67 ( V_81 -> V_94 , V_82 , & V_90 , & V_91 , & V_87 , & V_88 , & V_89 ) )
continue;
if ( V_88 ) {
#ifdef F_68
T_9 V_95 ;
if ( V_67 != F_69 ( * V_88 ) )
goto V_96;
if ( ! F_70 ( * V_88 ) && ! F_71 ( * V_88 ) )
goto V_96;
F_72 ( V_81 , V_82 , V_67 ) ;
V_95 = F_73 ( V_81 , V_82 , V_88 ) ;
V_95 = F_74 ( V_95 ) ;
V_95 = F_75 ( V_95 ) ;
F_76 ( V_81 -> V_94 , V_82 , V_88 , V_95 ) ;
F_77 ( V_81 -> V_94 , V_90 , V_91 ) ;
V_96:
F_78 ( V_89 ) ;
#endif
} else {
if ( V_67 != F_79 ( * V_87 ) )
goto V_97;
if ( ! F_80 ( * V_87 ) && ! F_81 ( * V_87 ) )
goto V_97;
F_72 ( V_81 , V_82 , V_67 ) ;
V_86 = F_82 ( V_81 , V_82 , V_87 ) ;
V_86 = F_83 ( V_86 ) ;
V_86 = F_84 ( V_86 ) ;
F_85 ( V_81 -> V_94 , V_82 , V_87 , V_86 ) ;
F_77 ( V_81 -> V_94 , V_90 , V_91 ) ;
V_97:
F_86 ( V_87 , V_89 ) ;
}
F_87 ( V_81 -> V_94 , V_90 , V_91 ) ;
}
F_88 ( V_16 ) ;
}
static int F_89 ( struct V_56 * V_57 ,
struct V_58 * V_59 , struct V_15 * V_16 ,
T_4 V_17 , void * V_4 )
{
struct V_52 * V_35 = & V_16 -> V_35 ;
void * V_98 , * * V_33 , * V_65 ;
long V_51 = 0 , V_69 ;
T_2 V_6 ;
T_4 V_66 ;
T_6 V_60 ;
T_7 V_67 ;
if ( F_90 ( ! F_27 ( V_4 ) ) )
return - V_42 ;
F_32 ( & V_16 -> V_34 ) ;
V_98 = F_23 ( V_16 , V_17 , & V_33 ) ;
if ( ! V_98 || F_26 ( ! F_27 ( V_98 ) ) )
goto V_99;
if ( F_3 ( V_98 ) != F_3 ( V_4 ) )
goto V_99;
if ( F_26 ( F_9 ( V_4 ) ||
F_8 ( V_4 ) ) ) {
V_51 = - V_42 ;
goto V_99;
}
if ( ! F_45 ( V_35 , V_17 , V_55 ) )
goto V_99;
V_4 = F_20 ( V_16 , V_33 ) ;
F_91 ( V_35 , V_17 , V_55 ) ;
F_29 ( & V_16 -> V_34 ) ;
V_6 = F_3 ( V_4 ) ;
V_60 = V_77 << F_5 ( V_4 ) ;
V_69 = F_50 () ;
V_51 = F_49 ( V_57 , V_6 , V_60 , & V_66 ) ;
if ( V_51 )
goto V_100;
V_51 = F_51 ( V_59 , V_66 , V_60 / V_77 , & V_65 , & V_67 ) ;
if ( V_51 < 0 )
goto V_100;
if ( F_26 ( V_51 < V_60 / V_77 ) ) {
V_51 = - V_42 ;
goto V_100;
}
F_63 ( V_16 , V_17 , F_92 ( V_67 ) ) ;
F_93 ( V_59 , V_65 , V_60 ) ;
F_32 ( & V_16 -> V_34 ) ;
F_91 ( V_35 , V_17 , V_54 ) ;
F_29 ( & V_16 -> V_34 ) ;
F_94 ( V_16 -> V_75 , V_17 , V_60 >> V_12 ) ;
V_100:
F_53 ( V_69 ) ;
F_34 ( V_16 , V_17 ) ;
return V_51 ;
V_99:
F_35 ( V_16 , V_17 , V_98 ) ;
F_29 ( & V_16 -> V_34 ) ;
return V_51 ;
}
int F_95 ( struct V_15 * V_16 ,
struct V_56 * V_57 , struct V_101 * V_102 )
{
struct V_103 * V_103 = V_16 -> V_75 ;
T_4 V_104 , V_105 ;
T_4 V_106 [ V_107 ] ;
struct V_58 * V_59 ;
struct V_108 V_109 ;
bool V_110 = false ;
int V_1 , V_51 = 0 ;
if ( F_26 ( V_103 -> V_111 != V_12 ) )
return - V_42 ;
if ( ! V_16 -> V_49 || V_102 -> V_112 != V_113 )
return 0 ;
V_59 = F_96 ( V_57 -> V_114 -> V_115 ) ;
if ( ! V_59 )
return - V_42 ;
V_104 = V_102 -> V_116 >> V_12 ;
V_105 = V_102 -> V_117 >> V_12 ;
F_97 ( V_103 , V_104 , V_105 ) ;
F_98 ( V_16 , V_104 , V_105 ) ;
F_99 ( & V_109 , 0 ) ;
while ( ! V_110 ) {
V_109 . V_118 = F_100 ( V_16 , V_104 ,
V_55 , V_107 ,
V_109 . V_119 , V_106 ) ;
if ( V_109 . V_118 == 0 )
break;
for ( V_1 = 0 ; V_1 < V_109 . V_118 ; V_1 ++ ) {
if ( V_106 [ V_1 ] > V_105 ) {
V_110 = true ;
break;
}
V_51 = F_89 ( V_57 , V_59 , V_16 ,
V_106 [ V_1 ] , V_109 . V_119 [ V_1 ] ) ;
if ( V_51 < 0 ) {
F_101 ( V_16 , V_51 ) ;
goto V_53;
}
}
V_104 = V_106 [ V_109 . V_118 - 1 ] + 1 ;
}
V_53:
F_102 ( V_59 ) ;
F_103 ( V_103 , V_104 , V_105 ) ;
return ( V_51 < 0 ? V_51 : 0 ) ;
}
static int F_104 ( struct V_15 * V_16 ,
struct V_56 * V_57 , struct V_58 * V_59 ,
T_2 V_6 , T_6 V_60 , void * V_4 ,
struct V_80 * V_81 , struct V_71 * V_72 )
{
unsigned long V_63 = V_72 -> V_82 ;
void * V_51 , * V_65 ;
T_4 V_66 ;
int V_69 , V_68 ;
T_7 V_67 ;
V_68 = F_49 ( V_57 , V_6 , V_60 , & V_66 ) ;
if ( V_68 )
return V_68 ;
V_69 = F_50 () ;
V_68 = F_51 ( V_59 , V_66 , F_52 ( V_60 ) , & V_65 , & V_67 ) ;
if ( V_68 < 0 ) {
F_53 ( V_69 ) ;
return V_68 ;
}
F_53 ( V_69 ) ;
V_51 = F_57 ( V_16 , V_72 , V_4 , V_6 , 0 ) ;
if ( F_105 ( V_51 ) )
return F_106 ( V_51 ) ;
F_107 ( V_16 -> V_75 , V_72 , V_51 ) ;
if ( V_72 -> V_7 & V_74 )
return F_108 ( V_81 , V_63 , V_67 ) ;
else
return F_109 ( V_81 , V_63 , V_67 ) ;
}
static int F_110 ( struct V_15 * V_16 , void * V_4 ,
struct V_71 * V_72 )
{
struct V_103 * V_103 = V_16 -> V_75 ;
unsigned long V_63 = V_72 -> V_82 ;
int V_51 = V_120 ;
struct V_61 * V_121 ;
void * V_98 ;
V_121 = F_111 ( 0 ) ;
if ( F_112 ( ! V_121 ) ) {
V_51 = V_122 ;
goto V_53;
}
V_98 = F_57 ( V_16 , V_72 , V_4 , 0 ,
V_13 ) ;
if ( F_105 ( V_98 ) ) {
V_51 = V_123 ;
goto V_53;
}
F_109 ( V_72 -> V_81 , V_63 , F_113 ( V_121 ) ) ;
V_53:
F_114 ( V_103 , V_72 , V_51 ) ;
return V_51 ;
}
static bool F_115 ( struct V_56 * V_57 ,
unsigned int V_124 , unsigned int V_125 )
{
unsigned short V_126 = F_116 ( V_57 ) ;
if ( ! F_117 ( V_124 , V_126 ) )
return false ;
if ( ! F_117 ( V_125 , V_126 ) )
return false ;
return true ;
}
int F_118 ( struct V_56 * V_57 ,
struct V_58 * V_59 , T_2 V_6 ,
unsigned int V_124 , unsigned int V_60 )
{
if ( F_115 ( V_57 , V_124 , V_60 ) ) {
T_2 V_127 = V_6 + ( V_124 >> 9 ) ;
return F_119 ( V_57 , V_127 ,
V_60 >> 9 , V_128 , 0 ) ;
} else {
T_4 V_66 ;
long V_68 , V_69 ;
void * V_65 ;
T_7 V_67 ;
V_68 = F_49 ( V_57 , V_6 , V_77 , & V_66 ) ;
if ( V_68 )
return V_68 ;
V_69 = F_50 () ;
V_68 = F_51 ( V_59 , V_66 , 1 , & V_65 ,
& V_67 ) ;
if ( V_68 < 0 ) {
F_53 ( V_69 ) ;
return V_68 ;
}
memset ( V_65 + V_124 , 0 , V_60 ) ;
F_93 ( V_59 , V_65 + V_124 , V_60 ) ;
F_53 ( V_69 ) ;
}
return 0 ;
}
static T_2 F_120 ( struct V_129 * V_129 , T_11 V_130 )
{
return V_129 -> V_131 + ( ( ( V_130 & V_132 ) - V_129 -> V_124 ) >> 9 ) ;
}
static T_11
F_121 ( struct V_103 * V_103 , T_11 V_130 , T_11 V_125 , void * V_133 ,
struct V_129 * V_129 )
{
struct V_56 * V_57 = V_129 -> V_57 ;
struct V_58 * V_59 = V_129 -> V_59 ;
struct V_134 * V_135 = V_133 ;
T_11 V_91 = V_130 + V_125 , V_110 = 0 ;
T_12 V_51 = 0 ;
int V_69 ;
if ( F_122 ( V_135 ) == V_136 ) {
V_91 = F_123 ( V_91 , F_124 ( V_103 ) ) ;
if ( V_130 >= V_91 )
return 0 ;
if ( V_129 -> type == V_137 || V_129 -> type == V_138 )
return F_125 ( F_123 ( V_125 , V_91 - V_130 ) , V_135 ) ;
}
if ( F_26 ( V_129 -> type != V_139 ) )
return - V_42 ;
if ( V_129 -> V_7 & V_140 ) {
F_126 ( V_103 -> V_141 ,
V_130 >> V_12 ,
( V_91 - 1 ) >> V_12 ) ;
}
V_69 = F_50 () ;
while ( V_130 < V_91 ) {
unsigned V_124 = V_130 & ( V_77 - 1 ) ;
const T_6 V_60 = F_127 ( V_125 + V_124 , V_77 ) ;
const T_2 V_6 = F_120 ( V_129 , V_130 ) ;
T_12 V_142 ;
T_4 V_66 ;
void * V_65 ;
T_7 V_67 ;
if ( F_128 ( V_143 ) ) {
V_51 = - V_144 ;
break;
}
V_51 = F_49 ( V_57 , V_6 , V_60 , & V_66 ) ;
if ( V_51 )
break;
V_142 = F_51 ( V_59 , V_66 , F_52 ( V_60 ) ,
& V_65 , & V_67 ) ;
if ( V_142 < 0 ) {
V_51 = V_142 ;
break;
}
V_142 = F_129 ( V_142 ) ;
V_65 += V_124 ;
V_142 -= V_124 ;
if ( V_142 > V_91 - V_130 )
V_142 = V_91 - V_130 ;
if ( F_122 ( V_135 ) == V_145 )
V_142 = F_130 ( V_59 , V_66 , V_65 ,
V_142 , V_135 ) ;
else
V_142 = F_131 ( V_65 , V_142 , V_135 ) ;
if ( V_142 <= 0 ) {
V_51 = V_142 ? V_142 : - V_146 ;
break;
}
V_130 += V_142 ;
V_125 -= V_142 ;
V_110 += V_142 ;
}
F_53 ( V_69 ) ;
return V_110 ? V_110 : V_51 ;
}
T_12
F_132 ( struct V_147 * V_148 , struct V_134 * V_135 ,
const struct V_149 * V_150 )
{
struct V_15 * V_16 = V_148 -> V_151 -> V_152 ;
struct V_103 * V_103 = V_16 -> V_75 ;
T_11 V_130 = V_148 -> V_153 , V_51 = 0 , V_110 = 0 ;
unsigned V_7 = 0 ;
if ( F_122 ( V_135 ) == V_145 ) {
F_133 ( & V_103 -> V_154 ) ;
V_7 |= V_155 ;
} else {
F_134 ( & V_103 -> V_154 ) ;
}
while ( F_135 ( V_135 ) ) {
V_51 = F_136 ( V_103 , V_130 , F_135 ( V_135 ) , V_7 , V_150 ,
V_135 , F_121 ) ;
if ( V_51 <= 0 )
break;
V_130 += V_51 ;
V_110 += V_51 ;
}
V_148 -> V_153 += V_110 ;
return V_110 ? V_110 : V_51 ;
}
static int F_137 ( int error )
{
if ( error == 0 )
return V_120 ;
if ( error == - V_156 )
return V_122 ;
return V_123 ;
}
static int F_138 ( struct V_71 * V_72 ,
const struct V_149 * V_150 )
{
struct V_15 * V_16 = V_72 -> V_81 -> V_157 -> V_152 ;
struct V_103 * V_103 = V_16 -> V_75 ;
unsigned long V_63 = V_72 -> V_82 ;
T_11 V_130 = ( T_11 ) V_72 -> V_66 << V_12 ;
T_2 V_6 ;
struct V_129 V_129 = { 0 } ;
unsigned V_7 = V_158 ;
int error , V_159 = 0 ;
int V_160 = 0 ;
void * V_4 ;
F_139 ( V_103 , V_72 , V_160 ) ;
if ( V_130 >= F_124 ( V_103 ) ) {
V_160 = V_123 ;
goto V_53;
}
if ( ( V_72 -> V_7 & V_74 ) && ! V_72 -> V_161 )
V_7 |= V_155 ;
V_4 = F_36 ( V_16 , V_72 -> V_66 , 0 ) ;
if ( F_105 ( V_4 ) ) {
V_160 = F_137 ( F_106 ( V_4 ) ) ;
goto V_53;
}
if ( F_140 ( * V_72 -> V_95 ) || F_141 ( * V_72 -> V_95 ) ) {
V_160 = V_120 ;
goto V_162;
}
error = V_150 -> V_163 ( V_103 , V_130 , V_77 , V_7 , & V_129 ) ;
if ( error ) {
V_160 = F_137 ( error ) ;
goto V_162;
}
if ( F_26 ( V_129 . V_124 + V_129 . V_125 < V_130 + V_77 ) ) {
error = - V_42 ;
goto V_164;
}
V_6 = F_120 ( & V_129 , V_130 ) ;
if ( V_72 -> V_161 ) {
switch ( V_129 . type ) {
case V_137 :
case V_138 :
F_142 ( V_72 -> V_161 , V_63 ) ;
break;
case V_139 :
error = F_48 ( V_129 . V_57 , V_129 . V_59 ,
V_6 , V_77 , V_72 -> V_161 , V_63 ) ;
break;
default:
F_26 ( 1 ) ;
error = - V_42 ;
break;
}
if ( error )
goto V_164;
F_143 ( V_72 -> V_161 ) ;
V_160 = F_144 ( V_72 ) ;
if ( ! V_160 )
V_160 = V_165 ;
goto V_166;
}
switch ( V_129 . type ) {
case V_139 :
if ( V_129 . V_7 & V_140 ) {
F_145 ( V_167 ) ;
F_146 ( V_72 -> V_81 -> V_94 , V_167 ) ;
V_159 = V_168 ;
}
error = F_104 ( V_16 , V_129 . V_57 , V_129 . V_59 ,
V_6 , V_77 , V_4 , V_72 -> V_81 , V_72 ) ;
if ( error == - V_169 )
error = 0 ;
break;
case V_138 :
case V_137 :
if ( ! ( V_72 -> V_7 & V_74 ) ) {
V_160 = F_110 ( V_16 , V_4 , V_72 ) ;
goto V_166;
}
default:
F_26 ( 1 ) ;
error = - V_42 ;
break;
}
V_164:
V_160 = F_137 ( error ) | V_159 ;
V_166:
if ( V_150 -> V_170 ) {
int V_171 = V_77 ;
if ( V_160 & V_172 )
V_171 = 0 ;
V_150 -> V_170 ( V_103 , V_130 , V_77 , V_171 , V_7 , & V_129 ) ;
}
V_162:
F_34 ( V_16 , V_72 -> V_66 ) ;
V_53:
F_147 ( V_103 , V_72 , V_160 ) ;
return V_160 ;
}
static int F_148 ( struct V_71 * V_72 , struct V_129 * V_129 ,
T_11 V_130 , void * V_4 )
{
struct V_15 * V_16 = V_72 -> V_81 -> V_157 -> V_152 ;
const T_2 V_6 = F_120 ( V_129 , V_130 ) ;
struct V_58 * V_59 = V_129 -> V_59 ;
struct V_56 * V_57 = V_129 -> V_57 ;
struct V_103 * V_103 = V_16 -> V_75 ;
const T_6 V_60 = V_47 ;
void * V_51 = NULL , * V_65 ;
long V_125 = 0 ;
T_4 V_66 ;
T_7 V_67 = {} ;
int V_69 ;
if ( F_49 ( V_57 , V_6 , V_60 , & V_66 ) != 0 )
goto V_173;
V_69 = F_50 () ;
V_125 = F_51 ( V_59 , V_66 , F_52 ( V_60 ) , & V_65 , & V_67 ) ;
if ( V_125 < 0 )
goto V_174;
V_125 = F_129 ( V_125 ) ;
if ( V_125 < V_60 )
goto V_174;
if ( F_92 ( V_67 ) & V_21 )
goto V_174;
if ( ! F_149 ( V_67 ) )
goto V_174;
F_53 ( V_69 ) ;
V_51 = F_57 ( V_16 , V_72 , V_4 , V_6 ,
V_10 ) ;
if ( F_105 ( V_51 ) )
goto V_173;
F_150 ( V_103 , V_72 , V_125 , V_67 , V_51 ) ;
return F_151 ( V_72 -> V_81 , V_72 -> V_82 , V_72 -> V_95 ,
V_67 , V_72 -> V_7 & V_74 ) ;
V_174:
F_53 ( V_69 ) ;
V_173:
F_152 ( V_103 , V_72 , V_125 , V_67 , V_51 ) ;
return V_175 ;
}
static int F_153 ( struct V_71 * V_72 , struct V_129 * V_129 ,
void * V_4 )
{
struct V_15 * V_16 = V_72 -> V_81 -> V_157 -> V_152 ;
unsigned long V_176 = V_72 -> V_82 & V_46 ;
struct V_103 * V_103 = V_16 -> V_75 ;
struct V_61 * V_121 ;
void * V_51 = NULL ;
T_10 * V_89 ;
T_9 V_177 ;
V_121 = F_154 ( V_72 -> V_81 -> V_94 ) ;
if ( F_112 ( ! V_121 ) )
goto V_173;
V_51 = F_57 ( V_16 , V_72 , V_4 , 0 ,
V_10 | V_13 ) ;
if ( F_105 ( V_51 ) )
goto V_173;
V_89 = F_155 ( V_72 -> V_81 -> V_94 , V_72 -> V_95 ) ;
if ( ! F_156 ( * ( V_72 -> V_95 ) ) ) {
F_78 ( V_89 ) ;
goto V_173;
}
V_177 = F_157 ( V_121 , V_72 -> V_81 -> V_178 ) ;
V_177 = F_158 ( V_177 ) ;
F_76 ( V_72 -> V_81 -> V_94 , V_176 , V_72 -> V_95 , V_177 ) ;
F_78 ( V_89 ) ;
F_159 ( V_103 , V_72 , V_121 , V_51 ) ;
return V_120 ;
V_173:
F_160 ( V_103 , V_72 , V_121 , V_51 ) ;
return V_175 ;
}
static int F_161 ( struct V_71 * V_72 ,
const struct V_149 * V_150 )
{
struct V_80 * V_81 = V_72 -> V_81 ;
struct V_15 * V_16 = V_81 -> V_157 -> V_152 ;
unsigned long V_176 = V_72 -> V_82 & V_46 ;
bool V_179 = V_72 -> V_7 & V_74 ;
unsigned int V_180 = ( V_179 ? V_155 : 0 ) | V_158 ;
struct V_103 * V_103 = V_16 -> V_75 ;
int V_181 = V_175 ;
struct V_129 V_129 = { 0 } ;
T_4 V_182 , V_66 ;
void * V_4 ;
T_11 V_130 ;
int error ;
V_66 = F_162 ( V_81 , V_176 ) ;
V_182 = ( F_124 ( V_103 ) - 1 ) >> V_12 ;
F_163 ( V_103 , V_72 , V_182 , 0 ) ;
if ( ( V_72 -> V_66 & V_21 ) !=
( ( V_72 -> V_82 >> V_12 ) & V_21 ) )
goto V_173;
if ( V_179 && ! ( V_81 -> V_92 & V_93 ) )
goto V_173;
if ( V_176 < V_81 -> V_83 )
goto V_173;
if ( ( V_176 + V_47 ) > V_81 -> V_85 )
goto V_173;
if ( V_66 > V_182 ) {
V_181 = V_123 ;
goto V_53;
}
if ( ( V_66 | V_21 ) > V_182 )
goto V_173;
V_4 = F_36 ( V_16 , V_66 , V_10 ) ;
if ( F_105 ( V_4 ) )
goto V_173;
if ( ! F_156 ( * V_72 -> V_95 ) && ! F_140 ( * V_72 -> V_95 ) &&
! F_141 ( * V_72 -> V_95 ) ) {
V_181 = 0 ;
goto V_162;
}
V_130 = ( T_11 ) V_66 << V_12 ;
error = V_150 -> V_163 ( V_103 , V_130 , V_47 , V_180 , & V_129 ) ;
if ( error )
goto V_162;
if ( V_129 . V_124 + V_129 . V_125 < V_130 + V_47 )
goto V_166;
switch ( V_129 . type ) {
case V_139 :
V_181 = F_148 ( V_72 , & V_129 , V_130 , V_4 ) ;
break;
case V_138 :
case V_137 :
if ( F_26 ( V_179 ) )
break;
V_181 = F_153 ( V_72 , & V_129 , V_4 ) ;
break;
default:
F_26 ( 1 ) ;
break;
}
V_166:
if ( V_150 -> V_170 ) {
int V_171 = V_47 ;
if ( V_181 == V_175 )
V_171 = 0 ;
V_150 -> V_170 ( V_103 , V_130 , V_47 , V_171 , V_180 ,
& V_129 ) ;
}
V_162:
F_34 ( V_16 , V_66 ) ;
V_173:
if ( V_181 == V_175 ) {
F_164 ( V_81 , V_72 -> V_95 , V_72 -> V_82 ) ;
F_145 ( V_183 ) ;
}
V_53:
F_165 ( V_103 , V_72 , V_182 , V_181 ) ;
return V_181 ;
}
static int F_161 ( struct V_71 * V_72 ,
const struct V_149 * V_150 )
{
return V_175 ;
}
int F_166 ( struct V_71 * V_72 , enum V_184 V_185 ,
const struct V_149 * V_150 )
{
switch ( V_185 ) {
case V_186 :
return F_138 ( V_72 , V_150 ) ;
case V_187 :
return F_161 ( V_72 , V_150 ) ;
default:
return V_175 ;
}
}
