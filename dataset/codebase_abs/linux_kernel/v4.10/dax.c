static int T_1 F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
F_2 ( V_3 + V_1 ) ;
return 0 ;
}
static long F_3 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
long V_11 = - V_12 ;
V_7 -> V_13 = F_4 ( - V_12 ) ;
if ( F_5 ( V_9 , true ) != 0 )
return V_11 ;
V_11 = F_6 ( V_5 , V_7 ) ;
if ( V_11 < 0 ) {
V_7 -> V_13 = F_4 ( V_11 ) ;
F_7 ( V_9 ) ;
return V_11 ;
}
return V_11 ;
}
static void F_8 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
if ( F_9 ( V_7 -> V_13 ) )
return;
F_7 ( V_5 -> V_10 ) ;
}
static int F_10 ( void * V_14 )
{
return ( unsigned long ) V_14 & V_15 ;
}
static int F_11 ( void * V_14 )
{
return ! ( ( unsigned long ) V_14 & V_15 ) ;
}
static int F_12 ( void * V_14 )
{
return ( unsigned long ) V_14 & V_16 ;
}
static int F_13 ( void * V_14 )
{
return ( unsigned long ) V_14 & V_17 ;
}
struct V_18 * F_14 ( struct V_4 * V_5 , T_2 V_19 )
{
struct V_18 * V_18 = F_15 ( V_20 , 0 ) ;
struct V_6 V_7 = {
. V_21 = V_22 ,
. V_23 = V_19 & ~ ( ( ( ( int ) V_22 ) / 512 ) - 1 ) ,
} ;
long V_11 ;
if ( ! V_18 )
return F_4 ( - V_24 ) ;
V_11 = F_3 ( V_5 , & V_7 ) ;
if ( V_11 < 0 )
return F_4 ( V_11 ) ;
F_16 ( F_17 ( V_18 ) , V_7 . V_13 , V_22 ) ;
F_8 ( V_5 , & V_7 ) ;
return V_18 ;
}
static T_3 * F_18 ( struct V_25 * V_26 ,
T_4 V_27 , void * V_14 , struct V_28 * V_29 )
{
unsigned long V_30 ;
if ( F_10 ( V_14 ) )
V_27 &= ~ ( ( 1UL << ( V_31 - V_32 ) ) - 1 ) ;
V_29 -> V_26 = V_26 ;
V_29 -> V_33 = V_27 ;
V_30 = F_19 ( ( unsigned long ) V_26 ^ V_27 , V_34 ) ;
return V_3 + V_30 ;
}
static int F_20 ( T_5 * V_35 , unsigned int V_36 ,
int V_37 , void * V_38 )
{
struct V_28 * V_29 = V_38 ;
struct V_39 * V_40 =
F_21 ( V_35 , struct V_39 , V_35 ) ;
if ( V_29 -> V_26 != V_40 -> V_29 . V_26 ||
V_29 -> V_33 != V_40 -> V_29 . V_33 )
return 0 ;
return F_22 ( V_35 , V_36 , V_37 , NULL ) ;
}
static inline int F_23 ( struct V_25 * V_26 , void * * V_41 )
{
unsigned long V_14 = ( unsigned long )
F_24 ( V_41 , & V_26 -> V_42 ) ;
return V_14 & V_43 ;
}
static inline void * F_25 ( struct V_25 * V_26 , void * * V_41 )
{
unsigned long V_14 = ( unsigned long )
F_24 ( V_41 , & V_26 -> V_42 ) ;
V_14 |= V_43 ;
F_26 ( & V_26 -> V_44 , V_41 , ( void * ) V_14 ) ;
return ( void * ) V_14 ;
}
static inline void * F_27 ( struct V_25 * V_26 , void * * V_41 )
{
unsigned long V_14 = ( unsigned long )
F_24 ( V_41 , & V_26 -> V_42 ) ;
V_14 &= ~ ( unsigned long ) V_43 ;
F_26 ( & V_26 -> V_44 , V_41 , ( void * ) V_14 ) ;
return ( void * ) V_14 ;
}
static void * F_28 ( struct V_25 * V_26 ,
T_4 V_27 , void * * * V_45 )
{
void * V_14 , * * V_41 ;
struct V_39 V_40 ;
T_3 * V_46 ;
F_29 ( & V_40 . V_35 ) ;
V_40 . V_35 . V_47 = F_20 ;
for (; ; ) {
V_14 = F_30 ( & V_26 -> V_44 , V_27 , NULL ,
& V_41 ) ;
if ( ! V_14 || ! F_31 ( V_14 ) ||
! F_23 ( V_26 , V_41 ) ) {
if ( V_45 )
* V_45 = V_41 ;
return V_14 ;
}
V_46 = F_18 ( V_26 , V_27 , V_14 , & V_40 . V_29 ) ;
F_32 ( V_46 , & V_40 . V_35 ,
V_48 ) ;
F_33 ( & V_26 -> V_42 ) ;
F_34 () ;
F_35 ( V_46 , & V_40 . V_35 ) ;
F_36 ( & V_26 -> V_42 ) ;
}
}
static void F_37 ( struct V_25 * V_26 ,
T_4 V_27 )
{
void * V_14 , * * V_41 ;
F_36 ( & V_26 -> V_42 ) ;
V_14 = F_30 ( & V_26 -> V_44 , V_27 , NULL , & V_41 ) ;
if ( F_38 ( ! V_14 || ! F_31 ( V_14 ) ||
! F_23 ( V_26 , V_41 ) ) ) {
F_33 ( & V_26 -> V_42 ) ;
return;
}
F_27 ( V_26 , V_41 ) ;
F_33 ( & V_26 -> V_42 ) ;
F_39 ( V_26 , V_27 , V_14 , false ) ;
}
static void F_40 ( struct V_25 * V_26 ,
T_4 V_27 , void * V_14 )
{
if ( ! F_31 ( V_14 ) ) {
F_41 ( V_14 ) ;
F_42 ( V_14 ) ;
} else {
F_37 ( V_26 , V_27 ) ;
}
}
static void F_43 ( struct V_25 * V_26 ,
T_4 V_27 , void * V_14 )
{
if ( ! F_31 ( V_14 ) )
return;
F_39 ( V_26 , V_27 , V_14 , false ) ;
}
static void * F_44 ( struct V_25 * V_26 , T_4 V_27 ,
unsigned long V_49 )
{
bool V_50 = false ;
void * V_14 , * * V_41 ;
V_51:
F_36 ( & V_26 -> V_42 ) ;
V_14 = F_28 ( V_26 , V_27 , & V_41 ) ;
if ( V_14 ) {
if ( V_49 & V_15 ) {
if ( ! F_31 ( V_14 ) ||
F_11 ( V_14 ) ) {
F_43 ( V_26 , V_27 ,
V_14 ) ;
V_14 = F_4 ( - V_52 ) ;
goto V_53;
}
} else {
if ( F_31 ( V_14 ) &&
F_10 ( V_14 ) &&
( F_12 ( V_14 ) ||
F_13 ( V_14 ) ) ) {
V_50 = true ;
}
}
}
if ( ! V_14 || V_50 ) {
int V_54 ;
if ( V_50 ) {
V_14 = F_25 ( V_26 , V_41 ) ;
}
F_33 ( & V_26 -> V_42 ) ;
if ( V_50 && F_12 ( V_14 ) )
F_45 ( V_26 ,
( V_27 << V_32 ) & V_55 , V_56 , 0 ) ;
V_54 = F_46 (
F_47 ( V_26 ) & ~ V_57 ) ;
if ( V_54 ) {
if ( V_50 )
F_40 ( V_26 , V_27 , V_14 ) ;
return F_4 ( V_54 ) ;
}
F_36 ( & V_26 -> V_42 ) ;
if ( V_50 ) {
F_48 ( & V_26 -> V_44 , V_27 ) ;
V_26 -> V_58 -- ;
F_39 ( V_26 , V_27 , V_14 ,
true ) ;
}
V_14 = F_49 ( 0 , V_49 | V_17 ) ;
V_54 = F_50 ( & V_26 -> V_44 , V_27 ,
F_51 ( V_14 ) , V_14 ) ;
F_52 () ;
if ( V_54 ) {
F_33 ( & V_26 -> V_42 ) ;
if ( V_54 == - V_52 && ! ( V_49 & V_15 ) )
goto V_51;
return F_4 ( V_54 ) ;
}
V_26 -> V_58 ++ ;
F_33 ( & V_26 -> V_42 ) ;
return V_14 ;
}
if ( ! F_31 ( V_14 ) ) {
struct V_18 * V_18 = V_14 ;
F_53 ( V_18 ) ;
F_33 ( & V_26 -> V_42 ) ;
F_54 ( V_18 ) ;
if ( F_55 ( V_18 -> V_26 != V_26 ) ) {
F_41 ( V_18 ) ;
F_42 ( V_18 ) ;
goto V_51;
}
return V_18 ;
}
V_14 = F_25 ( V_26 , V_41 ) ;
V_53:
F_33 ( & V_26 -> V_42 ) ;
return V_14 ;
}
void F_39 ( struct V_25 * V_26 ,
T_4 V_27 , void * V_14 , bool V_59 )
{
struct V_28 V_29 ;
T_3 * V_46 ;
V_46 = F_18 ( V_26 , V_27 , V_14 , & V_29 ) ;
if ( F_56 ( V_46 ) )
F_57 ( V_46 , V_60 , V_59 ? 0 : 1 , & V_29 ) ;
}
static int F_58 ( struct V_25 * V_26 ,
T_4 V_27 , bool V_61 )
{
int V_62 = 0 ;
void * V_14 ;
struct V_63 * V_44 = & V_26 -> V_44 ;
F_36 ( & V_26 -> V_42 ) ;
V_14 = F_28 ( V_26 , V_27 , NULL ) ;
if ( ! V_14 || ! F_31 ( V_14 ) )
goto V_64;
if ( ! V_61 &&
( F_59 ( V_44 , V_27 , V_65 ) ||
F_59 ( V_44 , V_27 , V_66 ) ) )
goto V_64;
F_48 ( V_44 , V_27 ) ;
V_26 -> V_58 -- ;
V_62 = 1 ;
V_64:
F_43 ( V_26 , V_27 , V_14 ) ;
F_33 ( & V_26 -> V_42 ) ;
return V_62 ;
}
int F_60 ( struct V_25 * V_26 , T_4 V_27 )
{
int V_62 = F_58 ( V_26 , V_27 , true ) ;
F_38 ( ! V_62 ) ;
return V_62 ;
}
int F_61 ( struct V_25 * V_26 , T_4 V_27 )
{
int V_62 = 0 ;
void * V_14 , * * V_41 ;
struct V_63 * V_44 = & V_26 -> V_44 ;
F_36 ( & V_26 -> V_42 ) ;
V_14 = F_30 ( V_44 , V_27 , NULL , & V_41 ) ;
if ( ! V_14 || ! F_31 ( V_14 ) ||
F_23 ( V_26 , V_41 ) )
goto V_64;
if ( F_59 ( V_44 , V_27 , V_65 ) ||
F_59 ( V_44 , V_27 , V_66 ) )
goto V_64;
F_48 ( V_44 , V_27 ) ;
V_26 -> V_58 -- ;
V_62 = 1 ;
V_64:
F_33 ( & V_26 -> V_42 ) ;
if ( V_62 )
F_39 ( V_26 , V_27 , V_14 , true ) ;
return V_62 ;
}
int F_62 ( struct V_25 * V_26 ,
T_4 V_27 )
{
return F_58 ( V_26 , V_27 , false ) ;
}
static int F_63 ( struct V_25 * V_26 , void * * V_14 ,
struct V_67 * V_68 )
{
struct V_18 * V_18 ;
int V_62 ;
if ( ! F_31 ( * V_14 ) ) {
V_18 = * V_14 ;
goto V_64;
}
V_18 = F_64 ( V_26 , V_68 -> V_69 ,
V_68 -> V_70 | V_71 ) ;
if ( ! V_18 )
return V_72 ;
V_64:
V_68 -> V_18 = V_18 ;
V_62 = F_65 ( V_68 ) ;
V_68 -> V_18 = NULL ;
* V_14 = V_18 ;
if ( ! V_62 ) {
F_53 ( V_18 ) ;
return V_73 ;
}
return V_62 ;
}
static int F_66 ( struct V_4 * V_5 , T_2 V_23 , T_6 V_21 ,
struct V_18 * V_74 , unsigned long V_75 )
{
struct V_6 V_7 = {
. V_23 = V_23 ,
. V_21 = V_21 ,
} ;
void * V_76 ;
if ( F_3 ( V_5 , & V_7 ) < 0 )
return F_67 ( V_7 . V_13 ) ;
V_76 = F_68 ( V_74 ) ;
F_69 ( V_76 , ( void V_77 * ) V_7 . V_13 , V_75 , V_74 ) ;
F_70 ( V_76 ) ;
F_8 ( V_5 , & V_7 ) ;
return 0 ;
}
static void * F_71 ( struct V_25 * V_26 ,
struct V_67 * V_68 ,
void * V_14 , T_2 V_23 ,
unsigned long V_78 )
{
struct V_63 * V_44 = & V_26 -> V_44 ;
int error = 0 ;
bool V_79 = false ;
void * V_80 ;
T_4 V_27 = V_68 -> V_69 ;
if ( V_68 -> V_78 & V_81 )
F_72 ( V_26 -> V_82 , V_83 ) ;
if ( ! F_31 ( V_14 ) ) {
V_79 = true ;
F_45 ( V_26 , V_68 -> V_69 << V_32 ,
V_22 , 0 ) ;
error = F_46 ( V_68 -> V_70 & ~ V_57 ) ;
if ( error )
return F_4 ( error ) ;
} else if ( F_12 ( V_14 ) && ! ( V_78 & V_16 ) ) {
F_45 ( V_26 ,
( V_68 -> V_69 << V_32 ) & V_55 , V_56 , 0 ) ;
}
F_36 ( & V_26 -> V_42 ) ;
V_80 = F_49 ( V_23 , V_78 ) ;
if ( V_79 ) {
F_73 ( V_14 , NULL ) ;
F_42 ( V_14 ) ;
error = F_50 ( V_44 , V_27 ,
F_51 ( V_80 ) , V_80 ) ;
if ( error ) {
V_80 = F_4 ( error ) ;
goto V_84;
}
V_26 -> V_58 ++ ;
} else if ( F_12 ( V_14 ) || F_13 ( V_14 ) ) {
struct V_85 * V_86 ;
void * * V_41 ;
void * V_62 ;
V_62 = F_30 ( V_44 , V_27 , & V_86 , & V_41 ) ;
F_38 ( V_62 != V_14 ) ;
F_74 ( V_44 , V_86 , V_41 ,
V_80 , NULL , NULL ) ;
}
if ( V_68 -> V_78 & V_81 )
F_75 ( V_44 , V_27 , V_65 ) ;
V_84:
F_33 ( & V_26 -> V_42 ) ;
if ( V_79 ) {
F_52 () ;
if ( V_26 -> V_87 -> V_88 )
V_26 -> V_87 -> V_88 ( V_14 ) ;
F_41 ( V_14 ) ;
F_42 ( V_14 ) ;
}
return V_80 ;
}
static inline unsigned long
F_76 ( T_4 V_69 , struct V_89 * V_90 )
{
unsigned long V_91 ;
V_91 = V_90 -> V_92 + ( ( V_69 - V_90 -> V_93 ) << V_32 ) ;
F_77 ( V_91 < V_90 -> V_92 || V_91 >= V_90 -> V_94 , V_90 ) ;
return V_91 ;
}
static void F_78 ( struct V_25 * V_26 ,
T_4 V_27 , unsigned long V_95 )
{
struct V_89 * V_90 ;
T_7 V_96 , * V_97 = NULL ;
T_8 * V_98 = NULL ;
T_9 * V_99 ;
bool V_100 ;
F_79 ( V_26 ) ;
F_80 (vma, &mapping->i_mmap, index, index) {
unsigned long V_91 ;
F_81 () ;
if ( ! ( V_90 -> V_101 & V_102 ) )
continue;
V_91 = F_76 ( V_27 , V_90 ) ;
V_100 = false ;
if ( F_82 ( V_90 -> V_103 , V_91 , & V_97 , & V_98 , & V_99 ) )
continue;
if ( V_98 ) {
#ifdef F_83
T_8 V_104 ;
if ( V_95 != F_84 ( * V_98 ) )
goto V_105;
if ( ! F_85 ( * V_98 ) && ! F_86 ( * V_98 ) )
goto V_105;
F_87 ( V_90 , V_91 , V_95 ) ;
V_104 = F_88 ( V_90 , V_91 , V_98 ) ;
V_104 = F_89 ( V_104 ) ;
V_104 = F_90 ( V_104 ) ;
F_91 ( V_90 -> V_103 , V_91 , V_98 , V_104 ) ;
V_100 = true ;
V_105:
F_92 ( V_99 ) ;
#endif
} else {
if ( V_95 != F_93 ( * V_97 ) )
goto V_106;
if ( ! F_94 ( * V_97 ) && ! F_95 ( * V_97 ) )
goto V_106;
F_87 ( V_90 , V_91 , V_95 ) ;
V_96 = F_96 ( V_90 , V_91 , V_97 ) ;
V_96 = F_97 ( V_96 ) ;
V_96 = F_98 ( V_96 ) ;
F_99 ( V_90 -> V_103 , V_91 , V_97 , V_96 ) ;
V_100 = true ;
V_106:
F_100 ( V_97 , V_99 ) ;
}
if ( V_100 )
F_101 ( V_90 -> V_103 , V_91 ) ;
}
F_102 ( V_26 ) ;
}
static int F_103 ( struct V_4 * V_5 ,
struct V_25 * V_26 , T_4 V_27 , void * V_14 )
{
struct V_63 * V_44 = & V_26 -> V_44 ;
struct V_6 V_7 ;
void * V_107 , * * V_41 ;
int V_62 = 0 ;
if ( F_104 ( ! F_31 ( V_14 ) ) )
return - V_12 ;
F_36 ( & V_26 -> V_42 ) ;
V_107 = F_28 ( V_26 , V_27 , & V_41 ) ;
if ( ! V_107 || ! F_31 ( V_107 ) )
goto V_108;
if ( F_105 ( V_107 ) != F_105 ( V_14 ) )
goto V_108;
if ( F_38 ( F_13 ( V_14 ) ||
F_12 ( V_14 ) ) ) {
V_62 = - V_12 ;
goto V_108;
}
if ( ! F_59 ( V_44 , V_27 , V_66 ) )
goto V_108;
V_14 = F_25 ( V_26 , V_41 ) ;
F_106 ( V_44 , V_27 , V_66 ) ;
F_33 ( & V_26 -> V_42 ) ;
V_7 . V_23 = F_105 ( V_14 ) ;
V_7 . V_21 = V_22 << F_51 ( V_14 ) ;
V_62 = F_3 ( V_5 , & V_7 ) ;
if ( V_62 < 0 ) {
F_40 ( V_26 , V_27 , V_14 ) ;
return V_62 ;
}
if ( F_38 ( V_62 < V_7 . V_21 ) ) {
V_62 = - V_12 ;
goto V_109;
}
F_78 ( V_26 , V_27 , F_107 ( V_7 . V_95 ) ) ;
F_108 ( V_7 . V_13 , V_7 . V_21 ) ;
F_36 ( & V_26 -> V_42 ) ;
F_106 ( V_44 , V_27 , V_65 ) ;
F_33 ( & V_26 -> V_42 ) ;
V_109:
F_8 ( V_5 , & V_7 ) ;
F_40 ( V_26 , V_27 , V_14 ) ;
return V_62 ;
V_108:
F_43 ( V_26 , V_27 , V_107 ) ;
F_33 ( & V_26 -> V_42 ) ;
return V_62 ;
}
int F_109 ( struct V_25 * V_26 ,
struct V_4 * V_5 , struct V_110 * V_111 )
{
struct V_112 * V_112 = V_26 -> V_82 ;
T_4 V_113 , V_114 ;
T_4 V_115 [ V_116 ] ;
struct V_117 V_118 ;
bool V_119 = false ;
int V_1 , V_62 = 0 ;
if ( F_38 ( V_112 -> V_120 != V_32 ) )
return - V_12 ;
if ( ! V_26 -> V_58 || V_111 -> V_121 != V_122 )
return 0 ;
V_113 = V_111 -> V_123 >> V_32 ;
V_114 = V_111 -> V_124 >> V_32 ;
F_110 ( V_26 , V_113 , V_114 ) ;
F_111 ( & V_118 , 0 ) ;
while ( ! V_119 ) {
V_118 . V_125 = F_112 ( V_26 , V_113 ,
V_66 , V_116 ,
V_118 . V_126 , V_115 ) ;
if ( V_118 . V_125 == 0 )
break;
for ( V_1 = 0 ; V_1 < V_118 . V_125 ; V_1 ++ ) {
if ( V_115 [ V_1 ] > V_114 ) {
V_119 = true ;
break;
}
V_62 = F_103 ( V_5 , V_26 , V_115 [ V_1 ] ,
V_118 . V_126 [ V_1 ] ) ;
if ( V_62 < 0 )
return V_62 ;
}
}
return 0 ;
}
static int F_113 ( struct V_25 * V_26 ,
struct V_4 * V_5 , T_2 V_23 , T_6 V_21 ,
void * * V_127 , struct V_89 * V_90 , struct V_67 * V_68 )
{
unsigned long V_75 = V_68 -> V_91 ;
struct V_6 V_7 = {
. V_23 = V_23 ,
. V_21 = V_21 ,
} ;
void * V_62 ;
void * V_14 = * V_127 ;
if ( F_3 ( V_5 , & V_7 ) < 0 )
return F_67 ( V_7 . V_13 ) ;
F_8 ( V_5 , & V_7 ) ;
V_62 = F_71 ( V_26 , V_68 , V_14 , V_7 . V_23 , 0 ) ;
if ( F_9 ( V_62 ) )
return F_67 ( V_62 ) ;
* V_127 = V_62 ;
return F_114 ( V_90 , V_75 , V_7 . V_95 ) ;
}
int F_115 ( struct V_89 * V_90 , struct V_67 * V_68 )
{
struct V_128 * V_128 = V_90 -> V_129 ;
struct V_25 * V_26 = V_128 -> V_130 ;
void * V_14 , * * V_41 ;
T_4 V_27 = V_68 -> V_69 ;
F_36 ( & V_26 -> V_42 ) ;
V_14 = F_28 ( V_26 , V_27 , & V_41 ) ;
if ( ! V_14 || ! F_31 ( V_14 ) ) {
if ( V_14 )
F_43 ( V_26 , V_27 , V_14 ) ;
F_33 ( & V_26 -> V_42 ) ;
return V_73 ;
}
F_75 ( & V_26 -> V_44 , V_27 , V_65 ) ;
V_14 = F_25 ( V_26 , V_41 ) ;
F_33 ( & V_26 -> V_42 ) ;
F_116 ( V_68 ) ;
F_40 ( V_26 , V_27 , V_14 ) ;
return V_73 ;
}
static bool F_117 ( struct V_4 * V_5 ,
unsigned int V_131 , unsigned int V_132 )
{
unsigned short V_133 = F_118 ( V_5 ) ;
if ( ! F_119 ( V_131 , V_133 ) )
return false ;
if ( ! F_119 ( V_132 , V_133 ) )
return false ;
return true ;
}
int F_120 ( struct V_4 * V_5 , T_2 V_23 ,
unsigned int V_131 , unsigned int V_132 )
{
struct V_6 V_7 = {
. V_23 = V_23 ,
. V_21 = V_22 ,
} ;
if ( F_117 ( V_5 , V_131 , V_132 ) ) {
T_2 V_134 = V_7 . V_23 + ( V_131 >> 9 ) ;
return F_121 ( V_5 , V_134 ,
V_132 >> 9 , V_135 , true ) ;
} else {
if ( F_3 ( V_5 , & V_7 ) < 0 )
return F_67 ( V_7 . V_13 ) ;
F_122 ( V_7 . V_13 + V_131 , V_132 ) ;
F_8 ( V_5 , & V_7 ) ;
}
return 0 ;
}
static T_2 F_123 ( struct V_136 * V_136 , T_10 V_137 )
{
return V_136 -> V_138 + ( ( ( V_137 & V_139 ) - V_136 -> V_131 ) >> 9 ) ;
}
static T_10
F_124 ( struct V_112 * V_112 , T_10 V_137 , T_10 V_132 , void * V_140 ,
struct V_136 * V_136 )
{
struct V_141 * V_142 = V_140 ;
T_10 V_143 = V_137 + V_132 , V_119 = 0 ;
T_11 V_62 = 0 ;
if ( F_125 ( V_142 ) == V_144 ) {
V_143 = F_126 ( V_143 , F_127 ( V_112 ) ) ;
if ( V_137 >= V_143 )
return 0 ;
if ( V_136 -> type == V_145 || V_136 -> type == V_146 )
return F_128 ( F_126 ( V_132 , V_143 - V_137 ) , V_142 ) ;
}
if ( F_38 ( V_136 -> type != V_147 ) )
return - V_12 ;
if ( ( V_136 -> V_78 & V_148 ) && V_112 -> V_149 -> V_150 ) {
F_129 ( V_112 -> V_149 ,
V_137 >> V_32 ,
( V_143 - 1 ) >> V_32 ) ;
}
while ( V_137 < V_143 ) {
unsigned V_131 = V_137 & ( V_22 - 1 ) ;
struct V_6 V_7 = { 0 } ;
T_11 V_151 ;
if ( F_130 ( V_152 ) ) {
V_62 = - V_153 ;
break;
}
V_7 . V_23 = F_123 ( V_136 , V_137 ) ;
V_7 . V_21 = ( V_132 + V_131 + V_22 - 1 ) & V_139 ;
V_151 = F_3 ( V_136 -> V_5 , & V_7 ) ;
if ( V_151 < 0 ) {
V_62 = V_151 ;
break;
}
V_7 . V_13 += V_131 ;
V_151 -= V_131 ;
if ( V_151 > V_143 - V_137 )
V_151 = V_143 - V_137 ;
if ( F_125 ( V_142 ) == V_154 )
V_151 = F_131 ( V_7 . V_13 , V_151 , V_142 ) ;
else
V_151 = F_132 ( V_7 . V_13 , V_151 , V_142 ) ;
F_8 ( V_136 -> V_5 , & V_7 ) ;
if ( V_151 <= 0 ) {
V_62 = V_151 ? V_151 : - V_155 ;
break;
}
V_137 += V_151 ;
V_132 -= V_151 ;
V_119 += V_151 ;
}
return V_119 ? V_119 : V_62 ;
}
T_11
F_133 ( struct V_156 * V_157 , struct V_141 * V_142 ,
struct V_158 * V_159 )
{
struct V_25 * V_26 = V_157 -> V_160 -> V_130 ;
struct V_112 * V_112 = V_26 -> V_82 ;
T_10 V_137 = V_157 -> V_161 , V_62 = 0 , V_119 = 0 ;
unsigned V_78 = 0 ;
if ( F_125 ( V_142 ) == V_154 )
V_78 |= V_162 ;
while ( F_134 ( V_142 ) ) {
V_62 = F_135 ( V_112 , V_137 , F_134 ( V_142 ) , V_78 , V_159 ,
V_142 , F_124 ) ;
if ( V_62 <= 0 )
break;
V_137 += V_62 ;
V_119 += V_62 ;
}
V_157 -> V_161 += V_119 ;
return V_119 ? V_119 : V_62 ;
}
static int F_136 ( int error )
{
if ( error == 0 )
return V_73 ;
if ( error == - V_24 )
return V_72 ;
return V_163 ;
}
int F_137 ( struct V_89 * V_90 , struct V_67 * V_68 ,
struct V_158 * V_159 )
{
struct V_25 * V_26 = V_90 -> V_129 -> V_130 ;
struct V_112 * V_112 = V_26 -> V_82 ;
unsigned long V_75 = V_68 -> V_91 ;
T_10 V_137 = ( T_10 ) V_68 -> V_69 << V_32 ;
T_2 V_23 ;
struct V_136 V_136 = { 0 } ;
unsigned V_78 = V_164 ;
int error , V_165 = 0 ;
int V_166 = 0 ;
void * V_14 ;
if ( V_137 >= F_127 ( V_112 ) )
return V_163 ;
if ( ( V_68 -> V_78 & V_81 ) && ! V_68 -> V_167 )
V_78 |= V_162 ;
error = V_159 -> V_168 ( V_112 , V_137 , V_22 , V_78 , & V_136 ) ;
if ( error )
return F_136 ( error ) ;
if ( F_38 ( V_136 . V_131 + V_136 . V_132 < V_137 + V_22 ) ) {
V_166 = F_136 ( - V_12 ) ;
goto V_169;
}
V_14 = F_44 ( V_26 , V_68 -> V_69 , 0 ) ;
if ( F_9 ( V_14 ) ) {
V_166 = F_136 ( F_67 ( V_14 ) ) ;
goto V_169;
}
V_23 = F_123 ( & V_136 , V_137 ) ;
if ( V_68 -> V_167 ) {
switch ( V_136 . type ) {
case V_145 :
case V_146 :
F_138 ( V_68 -> V_167 , V_75 ) ;
break;
case V_147 :
error = F_66 ( V_136 . V_5 , V_23 , V_22 ,
V_68 -> V_167 , V_75 ) ;
break;
default:
F_38 ( 1 ) ;
error = - V_12 ;
break;
}
if ( error )
goto V_170;
F_139 ( V_68 -> V_167 ) ;
V_166 = F_65 ( V_68 ) ;
if ( ! V_166 )
V_166 = V_171 ;
goto V_172;
}
switch ( V_136 . type ) {
case V_147 :
if ( V_136 . V_78 & V_148 ) {
F_140 ( V_173 ) ;
F_141 ( V_90 -> V_103 , V_173 ) ;
V_165 = V_174 ;
}
error = F_113 ( V_26 , V_136 . V_5 , V_23 ,
V_22 , & V_14 , V_90 , V_68 ) ;
if ( error == - V_175 )
error = 0 ;
break;
case V_146 :
case V_145 :
if ( ! ( V_68 -> V_78 & V_81 ) ) {
V_166 = F_63 ( V_26 , & V_14 , V_68 ) ;
goto V_172;
}
default:
F_38 ( 1 ) ;
error = - V_12 ;
break;
}
V_170:
V_166 = F_136 ( error ) | V_165 ;
V_172:
F_40 ( V_26 , V_68 -> V_69 , V_14 ) ;
V_169:
if ( V_159 -> V_176 ) {
int V_177 = V_22 ;
if ( V_166 & V_178 )
V_177 = 0 ;
V_159 -> V_176 ( V_112 , V_137 , V_22 , V_177 , V_78 , & V_136 ) ;
}
return V_166 ;
}
static int F_142 ( struct V_89 * V_90 , T_8 * V_104 ,
struct V_67 * V_68 , unsigned long V_91 ,
struct V_136 * V_136 , T_10 V_137 , bool V_179 , void * * V_127 )
{
struct V_25 * V_26 = V_90 -> V_129 -> V_130 ;
struct V_4 * V_5 = V_136 -> V_5 ;
struct V_6 V_7 = {
. V_23 = F_123 ( V_136 , V_137 ) ,
. V_21 = V_56 ,
} ;
long V_132 = F_3 ( V_5 , & V_7 ) ;
void * V_62 ;
if ( V_132 < 0 )
return V_180 ;
if ( V_132 < V_56 )
goto V_181;
if ( F_107 ( V_7 . V_95 ) & V_182 )
goto V_181;
if ( ! F_143 ( V_7 . V_95 ) )
goto V_181;
F_8 ( V_5 , & V_7 ) ;
V_62 = F_71 ( V_26 , V_68 , * V_127 , V_7 . V_23 ,
V_15 ) ;
if ( F_9 ( V_62 ) )
return V_180 ;
* V_127 = V_62 ;
return F_144 ( V_90 , V_91 , V_104 , V_7 . V_95 , V_179 ) ;
V_181:
F_8 ( V_5 , & V_7 ) ;
return V_180 ;
}
static int F_145 ( struct V_89 * V_90 , T_8 * V_104 ,
struct V_67 * V_68 , unsigned long V_91 ,
struct V_136 * V_136 , void * * V_127 )
{
struct V_25 * V_26 = V_90 -> V_129 -> V_130 ;
unsigned long V_183 = V_91 & V_55 ;
struct V_18 * V_184 ;
T_9 * V_99 ;
T_8 V_185 ;
void * V_62 ;
V_184 = F_146 ( V_90 -> V_103 ) ;
if ( F_55 ( ! V_184 ) )
return V_180 ;
V_62 = F_71 ( V_26 , V_68 , * V_127 , 0 ,
V_15 | V_16 ) ;
if ( F_9 ( V_62 ) )
return V_180 ;
* V_127 = V_62 ;
V_99 = F_147 ( V_90 -> V_103 , V_104 ) ;
if ( ! F_148 ( * V_104 ) ) {
F_92 ( V_99 ) ;
return V_180 ;
}
V_185 = F_149 ( V_184 , V_90 -> V_186 ) ;
V_185 = F_150 ( V_185 ) ;
F_91 ( V_90 -> V_103 , V_183 , V_104 , V_185 ) ;
F_92 ( V_99 ) ;
return V_73 ;
}
int F_151 ( struct V_89 * V_90 , unsigned long V_91 ,
T_8 * V_104 , unsigned int V_78 , struct V_158 * V_159 )
{
struct V_25 * V_26 = V_90 -> V_129 -> V_130 ;
unsigned long V_183 = V_91 & V_55 ;
bool V_179 = V_78 & V_81 ;
unsigned int V_187 = ( V_179 ? V_162 : 0 ) | V_164 ;
struct V_112 * V_112 = V_26 -> V_82 ;
int V_188 = V_180 ;
struct V_136 V_136 = { 0 } ;
T_4 V_189 , V_69 ;
struct V_67 V_68 ;
void * V_14 ;
T_10 V_137 ;
int error ;
if ( V_179 && ! ( V_90 -> V_101 & V_102 ) )
goto V_190;
if ( V_183 < V_90 -> V_92 )
goto V_190;
if ( ( V_183 + V_56 ) > V_90 -> V_94 )
goto V_190;
V_69 = F_152 ( V_90 , V_183 ) ;
V_189 = ( F_127 ( V_112 ) - 1 ) >> V_32 ;
if ( V_69 > V_189 )
return V_163 ;
if ( ( V_69 | V_182 ) > V_189 )
goto V_190;
V_137 = ( T_10 ) V_69 << V_32 ;
error = V_159 -> V_168 ( V_112 , V_137 , V_56 , V_187 , & V_136 ) ;
if ( error )
goto V_190;
if ( V_136 . V_131 + V_136 . V_132 < V_137 + V_56 )
goto V_169;
V_14 = F_44 ( V_26 , V_69 , V_15 ) ;
if ( F_9 ( V_14 ) )
goto V_169;
V_68 . V_69 = V_69 ;
V_68 . V_78 = V_78 ;
V_68 . V_70 = F_47 ( V_26 ) | V_191 ;
switch ( V_136 . type ) {
case V_147 :
V_188 = F_142 ( V_90 , V_104 , & V_68 , V_91 ,
& V_136 , V_137 , V_179 , & V_14 ) ;
break;
case V_146 :
case V_145 :
if ( F_38 ( V_179 ) )
goto V_172;
V_188 = F_145 ( V_90 , V_104 , & V_68 , V_91 , & V_136 ,
& V_14 ) ;
break;
default:
F_38 ( 1 ) ;
break;
}
V_172:
F_40 ( V_26 , V_69 , V_14 ) ;
V_169:
if ( V_159 -> V_176 ) {
int V_177 = V_56 ;
if ( V_188 == V_180 )
V_177 = 0 ;
V_159 -> V_176 ( V_112 , V_137 , V_56 , V_177 , V_187 ,
& V_136 ) ;
}
V_190:
if ( V_188 == V_180 ) {
F_153 ( V_90 , V_104 , V_91 ) ;
F_140 ( V_192 ) ;
}
return V_188 ;
}
