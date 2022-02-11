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
F_72 ( V_9 ) ;
F_73 (vma, &mapping->i_mmap, index, index) {
unsigned long V_88 , V_96 , V_97 ;
F_74 () ;
if ( ! ( V_87 -> V_98 & V_99 ) )
continue;
V_88 = F_69 ( V_10 , V_87 ) ;
if ( F_75 ( V_87 -> V_100 , V_88 , & V_96 , & V_97 , & V_93 , & V_94 , & V_95 ) )
continue;
if ( V_94 ) {
#ifdef F_76
T_9 V_101 ;
if ( V_71 != F_77 ( * V_94 ) )
goto V_102;
if ( ! F_78 ( * V_94 ) && ! F_79 ( * V_94 ) )
goto V_102;
F_80 ( V_87 , V_88 , V_71 ) ;
V_101 = F_81 ( V_87 , V_88 , V_94 ) ;
V_101 = F_82 ( V_101 ) ;
V_101 = F_83 ( V_101 ) ;
F_84 ( V_87 -> V_100 , V_88 , V_94 , V_101 ) ;
F_85 ( V_87 -> V_100 , V_96 , V_97 ) ;
V_102:
F_86 ( V_95 ) ;
#endif
} else {
if ( V_71 != F_87 ( * V_93 ) )
goto V_103;
if ( ! F_88 ( * V_93 ) && ! F_89 ( * V_93 ) )
goto V_103;
F_80 ( V_87 , V_88 , V_71 ) ;
V_92 = F_90 ( V_87 , V_88 , V_93 ) ;
V_92 = F_91 ( V_92 ) ;
V_92 = F_92 ( V_92 ) ;
F_93 ( V_87 -> V_100 , V_88 , V_93 , V_92 ) ;
F_85 ( V_87 -> V_100 , V_96 , V_97 ) ;
V_103:
F_94 ( V_93 , V_95 ) ;
}
F_95 ( V_87 -> V_100 , V_96 , V_97 ) ;
}
F_96 ( V_9 ) ;
}
static int F_97 ( struct V_61 * V_62 ,
struct V_63 * V_64 , struct V_8 * V_9 ,
T_3 V_10 , void * V_4 )
{
struct V_47 * V_27 = & V_9 -> V_27 ;
void * V_104 , * * V_24 , * V_70 ;
long V_46 = 0 , V_73 ;
T_5 V_65 ;
T_3 V_56 ;
T_6 V_66 ;
T_7 V_71 ;
if ( F_98 ( ! F_20 ( V_4 ) ) )
return - V_105 ;
F_25 ( & V_9 -> V_25 ) ;
V_104 = F_17 ( V_9 , V_10 , & V_24 ) ;
if ( ! V_104 || ! F_20 ( V_104 ) )
goto V_106;
if ( F_99 ( V_104 ) != F_99 ( V_4 ) )
goto V_106;
if ( F_27 ( F_6 ( V_4 ) ||
F_5 ( V_4 ) ) ) {
V_46 = - V_105 ;
goto V_106;
}
if ( ! F_49 ( V_27 , V_10 , V_50 ) )
goto V_106;
V_4 = F_14 ( V_9 , V_24 ) ;
F_100 ( V_27 , V_10 , V_50 ) ;
F_22 ( & V_9 -> V_25 ) ;
V_65 = F_99 ( V_4 ) ;
V_66 = V_80 << F_42 ( V_4 ) ;
V_73 = F_57 () ;
V_46 = F_56 ( V_62 , V_65 , V_66 , & V_56 ) ;
if ( V_46 )
goto V_107;
V_46 = F_58 ( V_64 , V_56 , V_66 / V_80 , & V_70 , & V_71 ) ;
if ( V_46 < 0 )
goto V_107;
if ( F_27 ( V_46 < V_66 / V_80 ) ) {
V_46 = - V_105 ;
goto V_107;
}
F_71 ( V_9 , V_10 , F_101 ( V_71 ) ) ;
F_102 ( V_64 , V_56 , V_70 , V_66 ) ;
F_25 ( & V_9 -> V_25 ) ;
F_100 ( V_27 , V_10 , V_49 ) ;
F_22 ( & V_9 -> V_25 ) ;
F_103 ( V_9 -> V_54 , V_10 , V_66 >> V_15 ) ;
V_107:
F_60 ( V_73 ) ;
F_29 ( V_9 , V_10 , V_4 ) ;
return V_46 ;
V_106:
F_32 ( V_9 , V_10 , V_104 ) ;
F_22 ( & V_9 -> V_25 ) ;
return V_46 ;
}
int F_104 ( struct V_8 * V_9 ,
struct V_61 * V_62 , struct V_108 * V_109 )
{
struct V_53 * V_53 = V_9 -> V_54 ;
T_3 V_110 , V_111 ;
T_3 V_112 [ V_113 ] ;
struct V_63 * V_64 ;
struct V_114 V_115 ;
bool V_116 = false ;
int V_1 , V_46 = 0 ;
if ( F_27 ( V_53 -> V_117 != V_15 ) )
return - V_105 ;
if ( ! V_9 -> V_41 || V_109 -> V_118 != V_119 )
return 0 ;
V_64 = F_105 ( V_62 -> V_120 -> V_121 ) ;
if ( ! V_64 )
return - V_105 ;
V_110 = V_109 -> V_122 >> V_15 ;
V_111 = V_109 -> V_123 >> V_15 ;
F_106 ( V_53 , V_110 , V_111 ) ;
F_107 ( V_9 , V_110 , V_111 ) ;
F_108 ( & V_115 , 0 ) ;
while ( ! V_116 ) {
V_115 . V_124 = F_109 ( V_9 , V_110 ,
V_50 , V_113 ,
V_115 . V_125 , V_112 ) ;
if ( V_115 . V_124 == 0 )
break;
for ( V_1 = 0 ; V_1 < V_115 . V_124 ; V_1 ++ ) {
if ( V_112 [ V_1 ] > V_111 ) {
V_116 = true ;
break;
}
V_46 = F_97 ( V_62 , V_64 , V_9 ,
V_112 [ V_1 ] , V_115 . V_125 [ V_1 ] ) ;
if ( V_46 < 0 ) {
F_110 ( V_9 , V_46 ) ;
goto V_48;
}
}
V_110 = V_112 [ V_115 . V_124 - 1 ] + 1 ;
}
V_48:
F_111 ( V_64 ) ;
F_112 ( V_53 , V_110 , V_111 ) ;
return ( V_46 < 0 ? V_46 : 0 ) ;
}
static int F_113 ( struct V_8 * V_9 ,
struct V_61 * V_62 , struct V_63 * V_64 ,
T_5 V_65 , T_6 V_66 , void * * V_126 ,
struct V_86 * V_87 , struct V_51 * V_52 )
{
unsigned long V_68 = V_52 -> V_88 ;
void * V_4 = * V_126 ;
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
if ( F_114 ( V_46 ) )
return F_115 ( V_46 ) ;
* V_126 = V_46 ;
F_116 ( V_9 -> V_54 , V_52 , V_46 ) ;
return F_117 ( V_87 , V_68 , V_71 ) ;
}
int F_118 ( struct V_51 * V_52 )
{
struct V_127 * V_127 = V_52 -> V_87 -> V_128 ;
struct V_8 * V_9 = V_127 -> V_129 ;
struct V_53 * V_53 = V_9 -> V_54 ;
void * V_4 , * * V_24 ;
T_3 V_10 = V_52 -> V_56 ;
F_25 ( & V_9 -> V_25 ) ;
V_4 = F_17 ( V_9 , V_10 , & V_24 ) ;
if ( ! V_4 || ! F_20 ( V_4 ) ) {
if ( V_4 )
F_32 ( V_9 , V_10 , V_4 ) ;
F_22 ( & V_9 -> V_25 ) ;
F_119 ( V_53 , V_52 , V_60 ) ;
return V_60 ;
}
F_68 ( & V_9 -> V_27 , V_10 , V_49 ) ;
V_4 = F_14 ( V_9 , V_24 ) ;
F_22 ( & V_9 -> V_25 ) ;
F_120 ( V_52 ) ;
F_29 ( V_9 , V_10 , V_4 ) ;
F_121 ( V_53 , V_52 , V_60 ) ;
return V_60 ;
}
static bool F_122 ( struct V_61 * V_62 ,
unsigned int V_130 , unsigned int V_131 )
{
unsigned short V_132 = F_123 ( V_62 ) ;
if ( ! F_124 ( V_130 , V_132 ) )
return false ;
if ( ! F_124 ( V_131 , V_132 ) )
return false ;
return true ;
}
int F_125 ( struct V_61 * V_62 ,
struct V_63 * V_64 , T_5 V_65 ,
unsigned int V_130 , unsigned int V_66 )
{
if ( F_122 ( V_62 , V_130 , V_66 ) ) {
T_5 V_133 = V_65 + ( V_130 >> 9 ) ;
return F_126 ( V_62 , V_133 ,
V_66 >> 9 , V_134 , 0 ) ;
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
memset ( V_70 + V_130 , 0 , V_66 ) ;
F_102 ( V_64 , V_56 , V_70 + V_130 , V_66 ) ;
F_60 ( V_73 ) ;
}
return 0 ;
}
static T_5 F_127 ( struct V_135 * V_135 , T_11 V_136 )
{
return V_135 -> V_137 + ( ( ( V_136 & V_138 ) - V_135 -> V_130 ) >> 9 ) ;
}
static T_11
F_128 ( struct V_53 * V_53 , T_11 V_136 , T_11 V_131 , void * V_139 ,
struct V_135 * V_135 )
{
struct V_61 * V_62 = V_135 -> V_62 ;
struct V_63 * V_64 = V_135 -> V_64 ;
struct V_140 * V_141 = V_139 ;
T_11 V_97 = V_136 + V_131 , V_116 = 0 ;
T_12 V_46 = 0 ;
int V_73 ;
if ( F_129 ( V_141 ) == V_142 ) {
V_97 = F_130 ( V_97 , F_131 ( V_53 ) ) ;
if ( V_136 >= V_97 )
return 0 ;
if ( V_135 -> type == V_143 || V_135 -> type == V_144 )
return F_132 ( F_130 ( V_131 , V_97 - V_136 ) , V_141 ) ;
}
if ( F_27 ( V_135 -> type != V_145 ) )
return - V_105 ;
if ( V_135 -> V_75 & V_146 ) {
F_133 ( V_53 -> V_147 ,
V_136 >> V_15 ,
( V_97 - 1 ) >> V_15 ) ;
}
V_73 = F_57 () ;
while ( V_136 < V_97 ) {
unsigned V_130 = V_136 & ( V_80 - 1 ) ;
const T_6 V_66 = F_134 ( V_131 + V_130 , V_80 ) ;
const T_5 V_65 = F_127 ( V_135 , V_136 ) ;
T_12 V_148 ;
T_3 V_56 ;
void * V_70 ;
T_7 V_71 ;
if ( F_135 ( V_149 ) ) {
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
V_148 = F_136 ( V_148 ) ;
V_70 += V_130 ;
V_148 -= V_130 ;
if ( V_148 > V_97 - V_136 )
V_148 = V_97 - V_136 ;
if ( F_129 ( V_141 ) == V_151 )
V_148 = F_137 ( V_64 , V_56 , V_70 ,
V_148 , V_141 ) ;
else
V_148 = F_138 ( V_70 , V_148 , V_141 ) ;
if ( V_148 <= 0 ) {
V_46 = V_148 ? V_148 : - V_152 ;
break;
}
V_136 += V_148 ;
V_131 -= V_148 ;
V_116 += V_148 ;
}
F_60 ( V_73 ) ;
return V_116 ? V_116 : V_46 ;
}
T_12
F_139 ( struct V_153 * V_154 , struct V_140 * V_141 ,
const struct V_155 * V_156 )
{
struct V_8 * V_9 = V_154 -> V_157 -> V_129 ;
struct V_53 * V_53 = V_9 -> V_54 ;
T_11 V_136 = V_154 -> V_158 , V_46 = 0 , V_116 = 0 ;
unsigned V_75 = 0 ;
if ( F_129 ( V_141 ) == V_151 ) {
F_140 ( & V_53 -> V_159 ) ;
V_75 |= V_160 ;
} else {
F_141 ( & V_53 -> V_159 ) ;
}
while ( F_142 ( V_141 ) ) {
V_46 = F_143 ( V_53 , V_136 , F_142 ( V_141 ) , V_75 , V_156 ,
V_141 , F_128 ) ;
if ( V_46 <= 0 )
break;
V_136 += V_46 ;
V_116 += V_46 ;
}
V_154 -> V_158 += V_116 ;
return V_116 ? V_116 : V_46 ;
}
static int F_144 ( int error )
{
if ( error == 0 )
return V_60 ;
if ( error == - V_161 )
return V_59 ;
return V_162 ;
}
static int F_145 ( struct V_51 * V_52 ,
const struct V_155 * V_156 )
{
struct V_8 * V_9 = V_52 -> V_87 -> V_128 -> V_129 ;
struct V_53 * V_53 = V_9 -> V_54 ;
unsigned long V_68 = V_52 -> V_88 ;
T_11 V_136 = ( T_11 ) V_52 -> V_56 << V_15 ;
T_5 V_65 ;
struct V_135 V_135 = { 0 } ;
unsigned V_75 = V_163 ;
int error , V_164 = 0 ;
int V_165 = 0 ;
void * V_4 ;
F_146 ( V_53 , V_52 , V_165 ) ;
if ( V_136 >= F_131 ( V_53 ) ) {
V_165 = V_162 ;
goto V_48;
}
if ( ( V_52 -> V_75 & V_78 ) && ! V_52 -> V_166 )
V_75 |= V_160 ;
V_4 = F_33 ( V_9 , V_52 -> V_56 , 0 ) ;
if ( F_114 ( V_4 ) ) {
V_165 = F_144 ( F_115 ( V_4 ) ) ;
goto V_48;
}
if ( F_147 ( * V_52 -> V_101 ) || F_148 ( * V_52 -> V_101 ) ) {
V_165 = V_60 ;
goto V_167;
}
error = V_156 -> V_168 ( V_53 , V_136 , V_80 , V_75 , & V_135 ) ;
if ( error ) {
V_165 = F_144 ( error ) ;
goto V_167;
}
if ( F_27 ( V_135 . V_130 + V_135 . V_131 < V_136 + V_80 ) ) {
error = - V_105 ;
goto V_169;
}
V_65 = F_127 ( & V_135 , V_136 ) ;
if ( V_52 -> V_166 ) {
switch ( V_135 . type ) {
case V_143 :
case V_144 :
F_149 ( V_52 -> V_166 , V_68 ) ;
break;
case V_145 :
error = F_55 ( V_135 . V_62 , V_135 . V_64 ,
V_65 , V_80 , V_52 -> V_166 , V_68 ) ;
break;
default:
F_27 ( 1 ) ;
error = - V_105 ;
break;
}
if ( error )
goto V_169;
F_150 ( V_52 -> V_166 ) ;
V_165 = V_55 ( V_52 ) ;
if ( ! V_165 )
V_165 = V_170 ;
goto V_171;
}
switch ( V_135 . type ) {
case V_145 :
if ( V_135 . V_75 & V_146 ) {
F_151 ( V_172 ) ;
F_152 ( V_52 -> V_87 -> V_100 , V_172 ) ;
V_164 = V_173 ;
}
error = F_113 ( V_9 , V_135 . V_62 , V_135 . V_64 ,
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
error = - V_105 ;
break;
}
V_169:
V_165 = F_144 ( error ) | V_164 ;
V_171:
if ( V_156 -> V_175 ) {
int V_176 = V_80 ;
if ( V_165 & V_177 )
V_176 = 0 ;
V_156 -> V_175 ( V_53 , V_136 , V_80 , V_176 , V_75 , & V_135 ) ;
}
V_167:
F_29 ( V_9 , V_52 -> V_56 , V_4 ) ;
V_48:
F_153 ( V_53 , V_52 , V_165 ) ;
return V_165 ;
}
static int F_154 ( struct V_51 * V_52 , struct V_135 * V_135 ,
T_11 V_136 , void * * V_126 )
{
struct V_8 * V_9 = V_52 -> V_87 -> V_128 -> V_129 ;
const T_5 V_65 = F_127 ( V_135 , V_136 ) ;
struct V_63 * V_64 = V_135 -> V_64 ;
struct V_61 * V_62 = V_135 -> V_62 ;
struct V_53 * V_53 = V_9 -> V_54 ;
const T_6 V_66 = V_39 ;
void * V_46 = NULL , * V_70 ;
long V_131 = 0 ;
T_3 V_56 ;
T_7 V_71 ;
int V_73 ;
if ( F_56 ( V_62 , V_65 , V_66 , & V_56 ) != 0 )
goto V_178;
V_73 = F_57 () ;
V_131 = F_58 ( V_64 , V_56 , F_59 ( V_66 ) , & V_70 , & V_71 ) ;
if ( V_131 < 0 )
goto V_179;
V_131 = F_136 ( V_131 ) ;
if ( V_131 < V_66 )
goto V_179;
if ( F_101 ( V_71 ) & V_180 )
goto V_179;
if ( ! F_155 ( V_71 ) )
goto V_179;
F_60 ( V_73 ) ;
V_46 = F_64 ( V_9 , V_52 , * V_126 , V_65 ,
V_5 ) ;
if ( F_114 ( V_46 ) )
goto V_178;
* V_126 = V_46 ;
F_156 ( V_53 , V_52 , V_131 , V_71 , V_46 ) ;
return F_157 ( V_52 -> V_87 , V_52 -> V_88 , V_52 -> V_101 ,
V_71 , V_52 -> V_75 & V_78 ) ;
V_179:
F_60 ( V_73 ) ;
V_178:
F_158 ( V_53 , V_52 , V_131 , V_71 , V_46 ) ;
return V_181 ;
}
static int F_159 ( struct V_51 * V_52 , struct V_135 * V_135 ,
void * * V_126 )
{
struct V_8 * V_9 = V_52 -> V_87 -> V_128 -> V_129 ;
unsigned long V_182 = V_52 -> V_88 & V_38 ;
struct V_53 * V_53 = V_9 -> V_54 ;
struct V_42 * V_183 ;
void * V_46 = NULL ;
T_10 * V_95 ;
T_9 V_184 ;
V_183 = F_160 ( V_52 -> V_87 -> V_100 ) ;
if ( F_45 ( ! V_183 ) )
goto V_178;
V_46 = F_64 ( V_9 , V_52 , * V_126 , 0 ,
V_5 | V_6 ) ;
if ( F_114 ( V_46 ) )
goto V_178;
* V_126 = V_46 ;
V_95 = F_161 ( V_52 -> V_87 -> V_100 , V_52 -> V_101 ) ;
if ( ! F_162 ( * ( V_52 -> V_101 ) ) ) {
F_86 ( V_95 ) ;
goto V_178;
}
V_184 = F_163 ( V_183 , V_52 -> V_87 -> V_185 ) ;
V_184 = F_164 ( V_184 ) ;
F_84 ( V_52 -> V_87 -> V_100 , V_182 , V_52 -> V_101 , V_184 ) ;
F_86 ( V_95 ) ;
F_165 ( V_53 , V_52 , V_183 , V_46 ) ;
return V_60 ;
V_178:
F_166 ( V_53 , V_52 , V_183 , V_46 ) ;
return V_181 ;
}
static int F_167 ( struct V_51 * V_52 ,
const struct V_155 * V_156 )
{
struct V_86 * V_87 = V_52 -> V_87 ;
struct V_8 * V_9 = V_87 -> V_128 -> V_129 ;
unsigned long V_182 = V_52 -> V_88 & V_38 ;
bool V_186 = V_52 -> V_75 & V_78 ;
unsigned int V_187 = ( V_186 ? V_160 : 0 ) | V_163 ;
struct V_53 * V_53 = V_9 -> V_54 ;
int V_188 = V_181 ;
struct V_135 V_135 = { 0 } ;
T_3 V_189 , V_56 ;
void * V_4 ;
T_11 V_136 ;
int error ;
V_56 = F_168 ( V_87 , V_182 ) ;
V_189 = ( F_131 ( V_53 ) - 1 ) >> V_15 ;
F_169 ( V_53 , V_52 , V_189 , 0 ) ;
if ( ( V_52 -> V_56 & V_180 ) !=
( ( V_52 -> V_88 >> V_15 ) & V_180 ) )
goto V_178;
if ( V_186 && ! ( V_87 -> V_98 & V_99 ) )
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
if ( F_114 ( V_4 ) )
goto V_178;
if ( ! F_162 ( * V_52 -> V_101 ) && ! F_147 ( * V_52 -> V_101 ) &&
! F_148 ( * V_52 -> V_101 ) ) {
V_188 = 0 ;
goto V_167;
}
V_136 = ( T_11 ) V_56 << V_15 ;
error = V_156 -> V_168 ( V_53 , V_136 , V_39 , V_187 , & V_135 ) ;
if ( error )
goto V_167;
if ( V_135 . V_130 + V_135 . V_131 < V_136 + V_39 )
goto V_171;
switch ( V_135 . type ) {
case V_145 :
V_188 = F_154 ( V_52 , & V_135 , V_136 , & V_4 ) ;
break;
case V_144 :
case V_143 :
if ( F_27 ( V_186 ) )
break;
V_188 = F_159 ( V_52 , & V_135 , & V_4 ) ;
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
V_156 -> V_175 ( V_53 , V_136 , V_39 , V_176 , V_187 ,
& V_135 ) ;
}
V_167:
F_29 ( V_9 , V_56 , V_4 ) ;
V_178:
if ( V_188 == V_181 ) {
F_170 ( V_87 , V_52 -> V_101 , V_52 -> V_88 ) ;
F_151 ( V_190 ) ;
}
V_48:
F_171 ( V_53 , V_52 , V_189 , V_188 ) ;
return V_188 ;
}
static int F_167 ( struct V_51 * V_52 ,
const struct V_155 * V_156 )
{
return V_181 ;
}
int F_172 ( struct V_51 * V_52 , enum V_191 V_192 ,
const struct V_155 * V_156 )
{
switch ( V_192 ) {
case V_193 :
return F_145 ( V_52 , V_156 ) ;
case V_194 :
return F_167 ( V_52 , V_156 ) ;
default:
return V_181 ;
}
}
