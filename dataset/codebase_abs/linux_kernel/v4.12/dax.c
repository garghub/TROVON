static int T_1 F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
F_2 ( V_3 + V_1 ) ;
return 0 ;
}
static int F_3 ( void * V_4 )
{
return ( unsigned long ) V_4 & V_5 ;
}
static int F_4 ( void * V_4 )
{
return ! ( ( unsigned long ) V_4 & V_5 ) ;
}
static int F_5 ( void * V_4 )
{
return ( unsigned long ) V_4 & V_6 ;
}
static int F_6 ( void * V_4 )
{
return ( unsigned long ) V_4 & V_7 ;
}
static T_2 * F_7 ( struct V_8 * V_9 ,
T_3 V_10 , void * V_4 , struct V_11 * V_12 )
{
unsigned long V_13 ;
if ( F_3 ( V_4 ) )
V_10 &= ~ ( ( 1UL << ( V_14 - V_15 ) ) - 1 ) ;
V_12 -> V_9 = V_9 ;
V_12 -> V_16 = V_10 ;
V_13 = F_8 ( ( unsigned long ) V_9 ^ V_10 , V_17 ) ;
return V_3 + V_13 ;
}
static int F_9 ( T_4 * V_18 , unsigned int V_19 ,
int V_20 , void * V_21 )
{
struct V_11 * V_12 = V_21 ;
struct V_22 * V_23 =
F_10 ( V_18 , struct V_22 , V_18 ) ;
if ( V_12 -> V_9 != V_23 -> V_12 . V_9 ||
V_12 -> V_16 != V_23 -> V_12 . V_16 )
return 0 ;
return F_11 ( V_18 , V_19 , V_20 , NULL ) ;
}
static inline int F_12 ( struct V_8 * V_9 , void * * V_24 )
{
unsigned long V_4 = ( unsigned long )
F_13 ( V_24 , & V_9 -> V_25 ) ;
return V_4 & V_26 ;
}
static inline void * F_14 ( struct V_8 * V_9 , void * * V_24 )
{
unsigned long V_4 = ( unsigned long )
F_13 ( V_24 , & V_9 -> V_25 ) ;
V_4 |= V_26 ;
F_15 ( & V_9 -> V_27 , V_24 , ( void * ) V_4 ) ;
return ( void * ) V_4 ;
}
static inline void * F_16 ( struct V_8 * V_9 , void * * V_24 )
{
unsigned long V_4 = ( unsigned long )
F_13 ( V_24 , & V_9 -> V_25 ) ;
V_4 &= ~ ( unsigned long ) V_26 ;
F_15 ( & V_9 -> V_27 , V_24 , ( void * ) V_4 ) ;
return ( void * ) V_4 ;
}
static void * F_17 ( struct V_8 * V_9 ,
T_3 V_10 , void * * * V_28 )
{
void * V_4 , * * V_24 ;
struct V_22 V_23 ;
T_2 * V_29 ;
F_18 ( & V_23 . V_18 ) ;
V_23 . V_18 . V_30 = F_9 ;
for (; ; ) {
V_4 = F_19 ( & V_9 -> V_27 , V_10 , NULL ,
& V_24 ) ;
if ( ! V_4 || ! F_20 ( V_4 ) ||
! F_12 ( V_9 , V_24 ) ) {
if ( V_28 )
* V_28 = V_24 ;
return V_4 ;
}
V_29 = F_7 ( V_9 , V_10 , V_4 , & V_23 . V_12 ) ;
F_21 ( V_29 , & V_23 . V_18 ,
V_31 ) ;
F_22 ( & V_9 -> V_25 ) ;
F_23 () ;
F_24 ( V_29 , & V_23 . V_18 ) ;
F_25 ( & V_9 -> V_25 ) ;
}
}
static void F_26 ( struct V_8 * V_9 ,
T_3 V_10 )
{
void * V_4 , * * V_24 ;
F_25 ( & V_9 -> V_25 ) ;
V_4 = F_19 ( & V_9 -> V_27 , V_10 , NULL , & V_24 ) ;
if ( F_27 ( ! V_4 || ! F_20 ( V_4 ) ||
! F_12 ( V_9 , V_24 ) ) ) {
F_22 ( & V_9 -> V_25 ) ;
return;
}
F_16 ( V_9 , V_24 ) ;
F_22 ( & V_9 -> V_25 ) ;
F_28 ( V_9 , V_10 , V_4 , false ) ;
}
static void F_29 ( struct V_8 * V_9 ,
T_3 V_10 , void * V_4 )
{
if ( ! F_20 ( V_4 ) ) {
F_30 ( V_4 ) ;
F_31 ( V_4 ) ;
} else {
F_26 ( V_9 , V_10 ) ;
}
}
static void F_32 ( struct V_8 * V_9 ,
T_3 V_10 , void * V_4 )
{
if ( ! F_20 ( V_4 ) )
return;
F_28 ( V_9 , V_10 , V_4 , false ) ;
}
static void * F_33 ( struct V_8 * V_9 , T_3 V_10 ,
unsigned long V_32 )
{
bool V_33 = false ;
void * V_4 , * * V_24 ;
V_34:
F_25 ( & V_9 -> V_25 ) ;
V_4 = F_17 ( V_9 , V_10 , & V_24 ) ;
if ( V_4 ) {
if ( V_32 & V_5 ) {
if ( ! F_20 ( V_4 ) ||
F_4 ( V_4 ) ) {
F_32 ( V_9 , V_10 ,
V_4 ) ;
V_4 = F_34 ( - V_35 ) ;
goto V_36;
}
} else {
if ( F_20 ( V_4 ) &&
F_3 ( V_4 ) &&
( F_5 ( V_4 ) ||
F_6 ( V_4 ) ) ) {
V_33 = true ;
}
}
}
if ( ! V_4 || V_33 ) {
int V_37 ;
if ( V_33 ) {
V_4 = F_14 ( V_9 , V_24 ) ;
}
F_22 ( & V_9 -> V_25 ) ;
if ( V_33 && F_5 ( V_4 ) )
F_35 ( V_9 ,
( V_10 << V_15 ) & V_38 , V_39 , 0 ) ;
V_37 = F_36 (
F_37 ( V_9 ) & ~ V_40 ) ;
if ( V_37 ) {
if ( V_33 )
F_29 ( V_9 , V_10 , V_4 ) ;
return F_34 ( V_37 ) ;
}
F_25 ( & V_9 -> V_25 ) ;
if ( ! V_4 ) {
V_4 = F_19 ( & V_9 -> V_27 , V_10 ,
NULL , & V_24 ) ;
if ( V_4 ) {
F_38 () ;
F_22 ( & V_9 -> V_25 ) ;
goto V_34;
}
}
if ( V_33 ) {
F_39 ( & V_9 -> V_27 , V_10 ) ;
V_9 -> V_41 -- ;
F_28 ( V_9 , V_10 , V_4 ,
true ) ;
}
V_4 = F_40 ( 0 , V_32 | V_7 ) ;
V_37 = F_41 ( & V_9 -> V_27 , V_10 ,
F_42 ( V_4 ) , V_4 ) ;
F_38 () ;
if ( V_37 ) {
F_22 ( & V_9 -> V_25 ) ;
return F_34 ( V_37 ) ;
}
V_9 -> V_41 ++ ;
F_22 ( & V_9 -> V_25 ) ;
return V_4 ;
}
if ( ! F_20 ( V_4 ) ) {
struct V_42 * V_42 = V_4 ;
F_43 ( V_42 ) ;
F_22 ( & V_9 -> V_25 ) ;
F_44 ( V_42 ) ;
if ( F_45 ( V_42 -> V_9 != V_9 ) ) {
F_30 ( V_42 ) ;
F_31 ( V_42 ) ;
goto V_34;
}
return V_42 ;
}
V_4 = F_14 ( V_9 , V_24 ) ;
V_36:
F_22 ( & V_9 -> V_25 ) ;
return V_4 ;
}
void F_28 ( struct V_8 * V_9 ,
T_3 V_10 , void * V_4 , bool V_43 )
{
struct V_11 V_12 ;
T_2 * V_29 ;
V_29 = F_7 ( V_9 , V_10 , V_4 , & V_12 ) ;
if ( F_46 ( V_29 ) )
F_47 ( V_29 , V_44 , V_43 ? 0 : 1 , & V_12 ) ;
}
static int F_48 ( struct V_8 * V_9 ,
T_3 V_10 , bool V_45 )
{
int V_46 = 0 ;
void * V_4 ;
struct V_47 * V_27 = & V_9 -> V_27 ;
F_25 ( & V_9 -> V_25 ) ;
V_4 = F_17 ( V_9 , V_10 , NULL ) ;
if ( ! V_4 || ! F_20 ( V_4 ) )
goto V_48;
if ( ! V_45 &&
( F_49 ( V_27 , V_10 , V_49 ) ||
F_49 ( V_27 , V_10 , V_50 ) ) )
goto V_48;
F_39 ( V_27 , V_10 ) ;
V_9 -> V_41 -- ;
V_46 = 1 ;
V_48:
F_32 ( V_9 , V_10 , V_4 ) ;
F_22 ( & V_9 -> V_25 ) ;
return V_46 ;
}
int F_50 ( struct V_8 * V_9 , T_3 V_10 )
{
int V_46 = F_48 ( V_9 , V_10 , true ) ;
F_27 ( ! V_46 ) ;
return V_46 ;
}
int F_51 ( struct V_8 * V_9 ,
T_3 V_10 )
{
return F_48 ( V_9 , V_10 , false ) ;
}
static int F_52 ( struct V_8 * V_9 , void * * V_4 ,
struct V_51 * V_52 )
{
struct V_53 * V_53 = V_9 -> V_54 ;
struct V_42 * V_42 ;
int V_46 ;
if ( ! F_20 ( * V_4 ) ) {
V_42 = * V_4 ;
goto V_55;
}
V_42 = F_53 ( V_9 , V_52 -> V_56 ,
V_52 -> V_57 | V_58 ) ;
if ( ! V_42 ) {
V_46 = V_59 ;
goto V_48;
}
V_55:
V_52 -> V_42 = V_42 ;
V_46 = V_55 ( V_52 ) ;
V_52 -> V_42 = NULL ;
* V_4 = V_42 ;
if ( ! V_46 ) {
F_43 ( V_42 ) ;
V_46 = V_60 ;
}
V_48:
F_54 ( V_53 , V_52 , V_46 ) ;
return V_46 ;
}
static int F_55 ( struct V_61 * V_62 , struct V_63 * V_64 ,
T_5 V_65 , T_6 V_66 , struct V_42 * V_67 ,
unsigned long V_68 )
{
void * V_69 , * V_70 ;
T_3 V_56 ;
T_7 V_71 ;
long V_72 ;
int V_73 ;
V_72 = F_56 ( V_62 , V_65 , V_66 , & V_56 ) ;
if ( V_72 )
return V_72 ;
V_73 = F_57 () ;
V_72 = F_58 ( V_64 , V_56 , F_59 ( V_66 ) , & V_70 , & V_71 ) ;
if ( V_72 < 0 ) {
F_60 ( V_73 ) ;
return V_72 ;
}
V_69 = F_61 ( V_67 ) ;
F_62 ( V_69 , ( void V_74 * ) V_70 , V_68 , V_67 ) ;
F_63 ( V_69 ) ;
F_60 ( V_73 ) ;
return 0 ;
}
static void * F_64 ( struct V_8 * V_9 ,
struct V_51 * V_52 ,
void * V_4 , T_5 V_65 ,
unsigned long V_75 )
{
struct V_47 * V_27 = & V_9 -> V_27 ;
int error = 0 ;
bool V_76 = false ;
void * V_77 ;
T_3 V_10 = V_52 -> V_56 ;
if ( V_52 -> V_75 & V_78 )
F_65 ( V_9 -> V_54 , V_79 ) ;
if ( ! F_20 ( V_4 ) ) {
V_76 = true ;
F_35 ( V_9 , V_52 -> V_56 << V_15 ,
V_80 , 0 ) ;
error = F_36 ( V_52 -> V_57 & ~ V_40 ) ;
if ( error )
return F_34 ( error ) ;
} else if ( F_5 ( V_4 ) && ! ( V_75 & V_6 ) ) {
F_35 ( V_9 ,
( V_52 -> V_56 << V_15 ) & V_38 , V_39 , 0 ) ;
}
F_25 ( & V_9 -> V_25 ) ;
V_77 = F_40 ( V_65 , V_75 ) ;
if ( V_76 ) {
F_66 ( V_4 , NULL ) ;
F_31 ( V_4 ) ;
error = F_41 ( V_27 , V_10 ,
F_42 ( V_77 ) , V_77 ) ;
if ( error ) {
V_77 = F_34 ( error ) ;
goto V_81;
}
V_9 -> V_41 ++ ;
} else if ( F_5 ( V_4 ) || F_6 ( V_4 ) ) {
struct V_82 * V_83 ;
void * * V_24 ;
void * V_46 ;
V_46 = F_19 ( V_27 , V_10 , & V_83 , & V_24 ) ;
F_27 ( V_46 != V_4 ) ;
F_67 ( V_27 , V_83 , V_24 ,
V_77 , NULL , NULL ) ;
}
if ( V_52 -> V_75 & V_78 )
F_68 ( V_27 , V_10 , V_49 ) ;
V_81:
F_22 ( & V_9 -> V_25 ) ;
if ( V_76 ) {
F_38 () ;
if ( V_9 -> V_84 -> V_85 )
V_9 -> V_84 -> V_85 ( V_4 ) ;
F_30 ( V_4 ) ;
F_31 ( V_4 ) ;
}
return V_77 ;
}
static inline unsigned long
F_69 ( T_3 V_56 , struct V_86 * V_87 )
{
unsigned long V_88 ;
V_88 = V_87 -> V_89 + ( ( V_56 - V_87 -> V_90 ) << V_15 ) ;
F_70 ( V_88 < V_87 -> V_89 || V_88 >= V_87 -> V_91 , V_87 ) ;
return V_88 ;
}
static void F_71 ( struct V_8 * V_9 ,
T_3 V_10 , unsigned long V_71 )
{
struct V_86 * V_87 ;
T_8 V_92 , * V_93 = NULL ;
T_9 * V_94 = NULL ;
T_10 * V_95 ;
bool V_96 ;
F_72 ( V_9 ) ;
F_73 (vma, &mapping->i_mmap, index, index) {
unsigned long V_88 ;
F_74 () ;
if ( ! ( V_87 -> V_97 & V_98 ) )
continue;
V_88 = F_69 ( V_10 , V_87 ) ;
V_96 = false ;
if ( F_75 ( V_87 -> V_99 , V_88 , & V_93 , & V_94 , & V_95 ) )
continue;
if ( V_94 ) {
#ifdef F_76
T_9 V_100 ;
if ( V_71 != F_77 ( * V_94 ) )
goto V_101;
if ( ! F_78 ( * V_94 ) && ! F_79 ( * V_94 ) )
goto V_101;
F_80 ( V_87 , V_88 , V_71 ) ;
V_100 = F_81 ( V_87 , V_88 , V_94 ) ;
V_100 = F_82 ( V_100 ) ;
V_100 = F_83 ( V_100 ) ;
F_84 ( V_87 -> V_99 , V_88 , V_94 , V_100 ) ;
V_96 = true ;
V_101:
F_85 ( V_95 ) ;
#endif
} else {
if ( V_71 != F_86 ( * V_93 ) )
goto V_102;
if ( ! F_87 ( * V_93 ) && ! F_88 ( * V_93 ) )
goto V_102;
F_80 ( V_87 , V_88 , V_71 ) ;
V_92 = F_89 ( V_87 , V_88 , V_93 ) ;
V_92 = F_90 ( V_92 ) ;
V_92 = F_91 ( V_92 ) ;
F_92 ( V_87 -> V_99 , V_88 , V_93 , V_92 ) ;
V_96 = true ;
V_102:
F_93 ( V_93 , V_95 ) ;
}
if ( V_96 )
F_94 ( V_87 -> V_99 , V_88 ) ;
}
F_95 ( V_9 ) ;
}
static int F_96 ( struct V_61 * V_62 ,
struct V_63 * V_64 , struct V_8 * V_9 ,
T_3 V_10 , void * V_4 )
{
struct V_47 * V_27 = & V_9 -> V_27 ;
void * V_103 , * * V_24 , * V_70 ;
long V_46 = 0 , V_73 ;
T_5 V_65 ;
T_3 V_56 ;
T_6 V_66 ;
T_7 V_71 ;
if ( F_97 ( ! F_20 ( V_4 ) ) )
return - V_104 ;
F_25 ( & V_9 -> V_25 ) ;
V_103 = F_17 ( V_9 , V_10 , & V_24 ) ;
if ( ! V_103 || ! F_20 ( V_103 ) )
goto V_105;
if ( F_98 ( V_103 ) != F_98 ( V_4 ) )
goto V_105;
if ( F_27 ( F_6 ( V_4 ) ||
F_5 ( V_4 ) ) ) {
V_46 = - V_104 ;
goto V_105;
}
if ( ! F_49 ( V_27 , V_10 , V_50 ) )
goto V_105;
V_4 = F_14 ( V_9 , V_24 ) ;
F_99 ( V_27 , V_10 , V_50 ) ;
F_22 ( & V_9 -> V_25 ) ;
V_65 = F_98 ( V_4 ) ;
V_66 = V_80 << F_42 ( V_4 ) ;
V_73 = F_57 () ;
V_46 = F_56 ( V_62 , V_65 , V_66 , & V_56 ) ;
if ( V_46 )
goto V_106;
V_46 = F_58 ( V_64 , V_56 , V_66 / V_80 , & V_70 , & V_71 ) ;
if ( V_46 < 0 )
goto V_106;
if ( F_27 ( V_46 < V_66 / V_80 ) ) {
V_46 = - V_104 ;
goto V_106;
}
F_71 ( V_9 , V_10 , F_100 ( V_71 ) ) ;
F_101 ( V_70 , V_66 ) ;
F_25 ( & V_9 -> V_25 ) ;
F_99 ( V_27 , V_10 , V_49 ) ;
F_22 ( & V_9 -> V_25 ) ;
F_102 ( V_9 -> V_54 , V_10 , V_66 >> V_15 ) ;
V_106:
F_60 ( V_73 ) ;
F_29 ( V_9 , V_10 , V_4 ) ;
return V_46 ;
V_105:
F_32 ( V_9 , V_10 , V_103 ) ;
F_22 ( & V_9 -> V_25 ) ;
return V_46 ;
}
int F_103 ( struct V_8 * V_9 ,
struct V_61 * V_62 , struct V_107 * V_108 )
{
struct V_53 * V_53 = V_9 -> V_54 ;
T_3 V_109 , V_110 ;
T_3 V_111 [ V_112 ] ;
struct V_63 * V_64 ;
struct V_113 V_114 ;
bool V_115 = false ;
int V_1 , V_46 = 0 ;
if ( F_27 ( V_53 -> V_116 != V_15 ) )
return - V_104 ;
if ( ! V_9 -> V_41 || V_108 -> V_117 != V_118 )
return 0 ;
V_64 = F_104 ( V_62 -> V_119 -> V_120 ) ;
if ( ! V_64 )
return - V_104 ;
V_109 = V_108 -> V_121 >> V_15 ;
V_110 = V_108 -> V_122 >> V_15 ;
F_105 ( V_53 , V_109 , V_110 ) ;
F_106 ( V_9 , V_109 , V_110 ) ;
F_107 ( & V_114 , 0 ) ;
while ( ! V_115 ) {
V_114 . V_123 = F_108 ( V_9 , V_109 ,
V_50 , V_112 ,
V_114 . V_124 , V_111 ) ;
if ( V_114 . V_123 == 0 )
break;
for ( V_1 = 0 ; V_1 < V_114 . V_123 ; V_1 ++ ) {
if ( V_111 [ V_1 ] > V_110 ) {
V_115 = true ;
break;
}
V_46 = F_96 ( V_62 , V_64 , V_9 ,
V_111 [ V_1 ] , V_114 . V_124 [ V_1 ] ) ;
if ( V_46 < 0 )
goto V_48;
}
V_109 = V_111 [ V_114 . V_123 - 1 ] + 1 ;
}
V_48:
F_109 ( V_64 ) ;
F_110 ( V_53 , V_109 , V_110 ) ;
return ( V_46 < 0 ? V_46 : 0 ) ;
}
static int F_111 ( struct V_8 * V_9 ,
struct V_61 * V_62 , struct V_63 * V_64 ,
T_5 V_65 , T_6 V_66 , void * * V_125 ,
struct V_86 * V_87 , struct V_51 * V_52 )
{
unsigned long V_68 = V_52 -> V_88 ;
void * V_4 = * V_125 ;
void * V_46 , * V_70 ;
T_3 V_56 ;
int V_73 , V_72 ;
T_7 V_71 ;
V_72 = F_56 ( V_62 , V_65 , V_66 , & V_56 ) ;
if ( V_72 )
return V_72 ;
V_73 = F_57 () ;
V_72 = F_58 ( V_64 , V_56 , F_59 ( V_66 ) , & V_70 , & V_71 ) ;
if ( V_72 < 0 ) {
F_60 ( V_73 ) ;
return V_72 ;
}
F_60 ( V_73 ) ;
V_46 = F_64 ( V_9 , V_52 , V_4 , V_65 , 0 ) ;
if ( F_112 ( V_46 ) )
return F_113 ( V_46 ) ;
* V_125 = V_46 ;
F_114 ( V_9 -> V_54 , V_52 , V_46 ) ;
return F_115 ( V_87 , V_68 , V_71 ) ;
}
int F_116 ( struct V_51 * V_52 )
{
struct V_126 * V_126 = V_52 -> V_87 -> V_127 ;
struct V_8 * V_9 = V_126 -> V_128 ;
struct V_53 * V_53 = V_9 -> V_54 ;
void * V_4 , * * V_24 ;
T_3 V_10 = V_52 -> V_56 ;
F_25 ( & V_9 -> V_25 ) ;
V_4 = F_17 ( V_9 , V_10 , & V_24 ) ;
if ( ! V_4 || ! F_20 ( V_4 ) ) {
if ( V_4 )
F_32 ( V_9 , V_10 , V_4 ) ;
F_22 ( & V_9 -> V_25 ) ;
F_117 ( V_53 , V_52 , V_60 ) ;
return V_60 ;
}
F_68 ( & V_9 -> V_27 , V_10 , V_49 ) ;
V_4 = F_14 ( V_9 , V_24 ) ;
F_22 ( & V_9 -> V_25 ) ;
F_118 ( V_52 ) ;
F_29 ( V_9 , V_10 , V_4 ) ;
F_119 ( V_53 , V_52 , V_60 ) ;
return V_60 ;
}
static bool F_120 ( struct V_61 * V_62 ,
unsigned int V_129 , unsigned int V_130 )
{
unsigned short V_131 = F_121 ( V_62 ) ;
if ( ! F_122 ( V_129 , V_131 ) )
return false ;
if ( ! F_122 ( V_130 , V_131 ) )
return false ;
return true ;
}
int F_123 ( struct V_61 * V_62 ,
struct V_63 * V_64 , T_5 V_65 ,
unsigned int V_129 , unsigned int V_66 )
{
if ( F_120 ( V_62 , V_129 , V_66 ) ) {
T_5 V_132 = V_65 + ( V_129 >> 9 ) ;
return F_124 ( V_62 , V_132 ,
V_66 >> 9 , V_133 , 0 ) ;
} else {
T_3 V_56 ;
long V_72 , V_73 ;
void * V_70 ;
T_7 V_71 ;
V_72 = F_56 ( V_62 , V_65 , V_80 , & V_56 ) ;
if ( V_72 )
return V_72 ;
V_73 = F_57 () ;
V_72 = F_58 ( V_64 , V_56 , 1 , & V_70 ,
& V_71 ) ;
if ( V_72 < 0 ) {
F_60 ( V_73 ) ;
return V_72 ;
}
F_125 ( V_70 + V_129 , V_66 ) ;
F_60 ( V_73 ) ;
}
return 0 ;
}
static T_5 F_126 ( struct V_134 * V_134 , T_11 V_135 )
{
return V_134 -> V_136 + ( ( ( V_135 & V_137 ) - V_134 -> V_129 ) >> 9 ) ;
}
static T_11
F_127 ( struct V_53 * V_53 , T_11 V_135 , T_11 V_130 , void * V_138 ,
struct V_134 * V_134 )
{
struct V_61 * V_62 = V_134 -> V_62 ;
struct V_63 * V_64 = V_134 -> V_64 ;
struct V_139 * V_140 = V_138 ;
T_11 V_141 = V_135 + V_130 , V_115 = 0 ;
T_12 V_46 = 0 ;
int V_73 ;
if ( F_128 ( V_140 ) == V_142 ) {
V_141 = F_129 ( V_141 , F_130 ( V_53 ) ) ;
if ( V_135 >= V_141 )
return 0 ;
if ( V_134 -> type == V_143 || V_134 -> type == V_144 )
return F_131 ( F_129 ( V_130 , V_141 - V_135 ) , V_140 ) ;
}
if ( F_27 ( V_134 -> type != V_145 ) )
return - V_104 ;
if ( V_134 -> V_75 & V_146 ) {
F_132 ( V_53 -> V_147 ,
V_135 >> V_15 ,
( V_141 - 1 ) >> V_15 ) ;
}
V_73 = F_57 () ;
while ( V_135 < V_141 ) {
unsigned V_129 = V_135 & ( V_80 - 1 ) ;
const T_6 V_66 = F_133 ( V_130 + V_129 , V_80 ) ;
const T_5 V_65 = F_126 ( V_134 , V_135 ) ;
T_12 V_148 ;
T_3 V_56 ;
void * V_70 ;
T_7 V_71 ;
if ( F_134 ( V_149 ) ) {
V_46 = - V_150 ;
break;
}
V_46 = F_56 ( V_62 , V_65 , V_66 , & V_56 ) ;
if ( V_46 )
break;
V_148 = F_58 ( V_64 , V_56 , F_59 ( V_66 ) ,
& V_70 , & V_71 ) ;
if ( V_148 < 0 ) {
V_46 = V_148 ;
break;
}
V_148 = F_135 ( V_148 ) ;
V_70 += V_129 ;
V_148 -= V_129 ;
if ( V_148 > V_141 - V_135 )
V_148 = V_141 - V_135 ;
if ( F_128 ( V_140 ) == V_151 )
V_148 = F_136 ( V_70 , V_148 , V_140 ) ;
else
V_148 = F_137 ( V_70 , V_148 , V_140 ) ;
if ( V_148 <= 0 ) {
V_46 = V_148 ? V_148 : - V_152 ;
break;
}
V_135 += V_148 ;
V_130 -= V_148 ;
V_115 += V_148 ;
}
F_60 ( V_73 ) ;
return V_115 ? V_115 : V_46 ;
}
T_12
F_138 ( struct V_153 * V_154 , struct V_139 * V_140 ,
const struct V_155 * V_156 )
{
struct V_8 * V_9 = V_154 -> V_157 -> V_128 ;
struct V_53 * V_53 = V_9 -> V_54 ;
T_11 V_135 = V_154 -> V_158 , V_46 = 0 , V_115 = 0 ;
unsigned V_75 = 0 ;
if ( F_128 ( V_140 ) == V_151 ) {
F_139 ( & V_53 -> V_159 ) ;
V_75 |= V_160 ;
} else {
F_140 ( & V_53 -> V_159 ) ;
}
while ( F_141 ( V_140 ) ) {
V_46 = F_142 ( V_53 , V_135 , F_141 ( V_140 ) , V_75 , V_156 ,
V_140 , F_127 ) ;
if ( V_46 <= 0 )
break;
V_135 += V_46 ;
V_115 += V_46 ;
}
V_154 -> V_158 += V_115 ;
return V_115 ? V_115 : V_46 ;
}
static int F_143 ( int error )
{
if ( error == 0 )
return V_60 ;
if ( error == - V_161 )
return V_59 ;
return V_162 ;
}
static int F_144 ( struct V_51 * V_52 ,
const struct V_155 * V_156 )
{
struct V_8 * V_9 = V_52 -> V_87 -> V_127 -> V_128 ;
struct V_53 * V_53 = V_9 -> V_54 ;
unsigned long V_68 = V_52 -> V_88 ;
T_11 V_135 = ( T_11 ) V_52 -> V_56 << V_15 ;
T_5 V_65 ;
struct V_134 V_134 = { 0 } ;
unsigned V_75 = V_163 ;
int error , V_164 = 0 ;
int V_165 = 0 ;
void * V_4 ;
F_145 ( V_53 , V_52 , V_165 ) ;
if ( V_135 >= F_130 ( V_53 ) ) {
V_165 = V_162 ;
goto V_48;
}
if ( ( V_52 -> V_75 & V_78 ) && ! V_52 -> V_166 )
V_75 |= V_160 ;
V_4 = F_33 ( V_9 , V_52 -> V_56 , 0 ) ;
if ( F_112 ( V_4 ) ) {
V_165 = F_143 ( F_113 ( V_4 ) ) ;
goto V_48;
}
if ( F_146 ( * V_52 -> V_100 ) || F_147 ( * V_52 -> V_100 ) ) {
V_165 = V_60 ;
goto V_167;
}
error = V_156 -> V_168 ( V_53 , V_135 , V_80 , V_75 , & V_134 ) ;
if ( error ) {
V_165 = F_143 ( error ) ;
goto V_167;
}
if ( F_27 ( V_134 . V_129 + V_134 . V_130 < V_135 + V_80 ) ) {
error = - V_104 ;
goto V_169;
}
V_65 = F_126 ( & V_134 , V_135 ) ;
if ( V_52 -> V_166 ) {
switch ( V_134 . type ) {
case V_143 :
case V_144 :
F_148 ( V_52 -> V_166 , V_68 ) ;
break;
case V_145 :
error = F_55 ( V_134 . V_62 , V_134 . V_64 ,
V_65 , V_80 , V_52 -> V_166 , V_68 ) ;
break;
default:
F_27 ( 1 ) ;
error = - V_104 ;
break;
}
if ( error )
goto V_169;
F_149 ( V_52 -> V_166 ) ;
V_165 = V_55 ( V_52 ) ;
if ( ! V_165 )
V_165 = V_170 ;
goto V_171;
}
switch ( V_134 . type ) {
case V_145 :
if ( V_134 . V_75 & V_146 ) {
F_150 ( V_172 ) ;
F_151 ( V_52 -> V_87 -> V_99 , V_172 ) ;
V_164 = V_173 ;
}
error = F_111 ( V_9 , V_134 . V_62 , V_134 . V_64 ,
V_65 , V_80 , & V_4 , V_52 -> V_87 , V_52 ) ;
if ( error == - V_174 )
error = 0 ;
break;
case V_144 :
case V_143 :
if ( ! ( V_52 -> V_75 & V_78 ) ) {
V_165 = F_52 ( V_9 , & V_4 , V_52 ) ;
goto V_171;
}
default:
F_27 ( 1 ) ;
error = - V_104 ;
break;
}
V_169:
V_165 = F_143 ( error ) | V_164 ;
V_171:
if ( V_156 -> V_175 ) {
int V_176 = V_80 ;
if ( V_165 & V_177 )
V_176 = 0 ;
V_156 -> V_175 ( V_53 , V_135 , V_80 , V_176 , V_75 , & V_134 ) ;
}
V_167:
F_29 ( V_9 , V_52 -> V_56 , V_4 ) ;
V_48:
F_152 ( V_53 , V_52 , V_165 ) ;
return V_165 ;
}
static int F_153 ( struct V_51 * V_52 , struct V_134 * V_134 ,
T_11 V_135 , void * * V_125 )
{
struct V_8 * V_9 = V_52 -> V_87 -> V_127 -> V_128 ;
const T_5 V_65 = F_126 ( V_134 , V_135 ) ;
struct V_63 * V_64 = V_134 -> V_64 ;
struct V_61 * V_62 = V_134 -> V_62 ;
struct V_53 * V_53 = V_9 -> V_54 ;
const T_6 V_66 = V_39 ;
void * V_46 = NULL , * V_70 ;
long V_130 = 0 ;
T_3 V_56 ;
T_7 V_71 ;
int V_73 ;
if ( F_56 ( V_62 , V_65 , V_66 , & V_56 ) != 0 )
goto V_178;
V_73 = F_57 () ;
V_130 = F_58 ( V_64 , V_56 , F_59 ( V_66 ) , & V_70 , & V_71 ) ;
if ( V_130 < 0 )
goto V_179;
V_130 = F_135 ( V_130 ) ;
if ( V_130 < V_66 )
goto V_179;
if ( F_100 ( V_71 ) & V_180 )
goto V_179;
if ( ! F_154 ( V_71 ) )
goto V_179;
F_60 ( V_73 ) ;
V_46 = F_64 ( V_9 , V_52 , * V_125 , V_65 ,
V_5 ) ;
if ( F_112 ( V_46 ) )
goto V_178;
* V_125 = V_46 ;
F_155 ( V_53 , V_52 , V_130 , V_71 , V_46 ) ;
return F_156 ( V_52 -> V_87 , V_52 -> V_88 , V_52 -> V_100 ,
V_71 , V_52 -> V_75 & V_78 ) ;
V_179:
F_60 ( V_73 ) ;
V_178:
F_157 ( V_53 , V_52 , V_130 , V_71 , V_46 ) ;
return V_181 ;
}
static int F_158 ( struct V_51 * V_52 , struct V_134 * V_134 ,
void * * V_125 )
{
struct V_8 * V_9 = V_52 -> V_87 -> V_127 -> V_128 ;
unsigned long V_182 = V_52 -> V_88 & V_38 ;
struct V_53 * V_53 = V_9 -> V_54 ;
struct V_42 * V_183 ;
void * V_46 = NULL ;
T_10 * V_95 ;
T_9 V_184 ;
V_183 = F_159 ( V_52 -> V_87 -> V_99 ) ;
if ( F_45 ( ! V_183 ) )
goto V_178;
V_46 = F_64 ( V_9 , V_52 , * V_125 , 0 ,
V_5 | V_6 ) ;
if ( F_112 ( V_46 ) )
goto V_178;
* V_125 = V_46 ;
V_95 = F_160 ( V_52 -> V_87 -> V_99 , V_52 -> V_100 ) ;
if ( ! F_161 ( * ( V_52 -> V_100 ) ) ) {
F_85 ( V_95 ) ;
goto V_178;
}
V_184 = F_162 ( V_183 , V_52 -> V_87 -> V_185 ) ;
V_184 = F_163 ( V_184 ) ;
F_84 ( V_52 -> V_87 -> V_99 , V_182 , V_52 -> V_100 , V_184 ) ;
F_85 ( V_95 ) ;
F_164 ( V_53 , V_52 , V_183 , V_46 ) ;
return V_60 ;
V_178:
F_165 ( V_53 , V_52 , V_183 , V_46 ) ;
return V_181 ;
}
static int F_166 ( struct V_51 * V_52 ,
const struct V_155 * V_156 )
{
struct V_86 * V_87 = V_52 -> V_87 ;
struct V_8 * V_9 = V_87 -> V_127 -> V_128 ;
unsigned long V_182 = V_52 -> V_88 & V_38 ;
bool V_186 = V_52 -> V_75 & V_78 ;
unsigned int V_187 = ( V_186 ? V_160 : 0 ) | V_163 ;
struct V_53 * V_53 = V_9 -> V_54 ;
int V_188 = V_181 ;
struct V_134 V_134 = { 0 } ;
T_3 V_189 , V_56 ;
void * V_4 ;
T_11 V_135 ;
int error ;
V_56 = F_167 ( V_87 , V_182 ) ;
V_189 = ( F_130 ( V_53 ) - 1 ) >> V_15 ;
F_168 ( V_53 , V_52 , V_189 , 0 ) ;
if ( V_186 && ! ( V_87 -> V_97 & V_98 ) )
goto V_178;
if ( V_182 < V_87 -> V_89 )
goto V_178;
if ( ( V_182 + V_39 ) > V_87 -> V_91 )
goto V_178;
if ( V_56 > V_189 ) {
V_188 = V_162 ;
goto V_48;
}
if ( ( V_56 | V_180 ) > V_189 )
goto V_178;
V_4 = F_33 ( V_9 , V_56 , V_5 ) ;
if ( F_112 ( V_4 ) )
goto V_178;
if ( ! F_161 ( * V_52 -> V_100 ) && ! F_146 ( * V_52 -> V_100 ) &&
! F_147 ( * V_52 -> V_100 ) ) {
V_188 = 0 ;
goto V_167;
}
V_135 = ( T_11 ) V_56 << V_15 ;
error = V_156 -> V_168 ( V_53 , V_135 , V_39 , V_187 , & V_134 ) ;
if ( error )
goto V_167;
if ( V_134 . V_129 + V_134 . V_130 < V_135 + V_39 )
goto V_171;
switch ( V_134 . type ) {
case V_145 :
V_188 = F_153 ( V_52 , & V_134 , V_135 , & V_4 ) ;
break;
case V_144 :
case V_143 :
if ( F_27 ( V_186 ) )
break;
V_188 = F_158 ( V_52 , & V_134 , & V_4 ) ;
break;
default:
F_27 ( 1 ) ;
break;
}
V_171:
if ( V_156 -> V_175 ) {
int V_176 = V_39 ;
if ( V_188 == V_181 )
V_176 = 0 ;
V_156 -> V_175 ( V_53 , V_135 , V_39 , V_176 , V_187 ,
& V_134 ) ;
}
V_167:
F_29 ( V_9 , V_56 , V_4 ) ;
V_178:
if ( V_188 == V_181 ) {
F_169 ( V_87 , V_52 -> V_100 , V_52 -> V_88 ) ;
F_150 ( V_190 ) ;
}
V_48:
F_170 ( V_53 , V_52 , V_189 , V_188 ) ;
return V_188 ;
}
static int F_166 ( struct V_51 * V_52 ,
const struct V_155 * V_156 )
{
return V_181 ;
}
int F_171 ( struct V_51 * V_52 , enum V_191 V_192 ,
const struct V_155 * V_156 )
{
switch ( V_192 ) {
case V_193 :
return F_144 ( V_52 , V_156 ) ;
case V_194 :
return F_166 ( V_52 , V_156 ) ;
default:
return V_181 ;
}
}
