static int T_1 F_1 ( char * V_1 )
{
if ( ! strcmp ( V_1 , L_1 ) )
V_2 &= ~ V_3 ;
else if ( ! strcmp ( V_1 , L_2 ) )
V_2 |= V_3 ;
return 1 ;
}
void F_2 ( unsigned long V_4 , unsigned long V_5 )
{
unsigned long V_6 ;
for ( V_6 = V_4 ; V_6 <= V_5 ; V_6 = F_3 ( V_6 + 1 , V_7 ) ) {
T_2 * V_8 = F_4 ( V_6 ) ;
const T_3 * V_9 ;
struct V_10 * V_10 ;
F_5 ( F_6 ( * V_8 ) ) ;
V_9 = F_7 ( V_8 , V_6 ) ;
if ( F_8 ( * V_9 ) )
continue;
F_9 ( & V_11 ) ;
F_10 (page, &pgd_list, lru) {
T_2 * V_12 ;
T_3 * V_13 ;
T_4 * V_14 ;
V_12 = ( T_2 * ) F_11 ( V_10 ) + F_12 ( V_6 ) ;
V_13 = F_7 ( V_12 , V_6 ) ;
V_14 = & F_13 ( V_10 ) -> V_15 ;
F_9 ( V_14 ) ;
if ( ! F_8 ( * V_9 ) && ! F_8 ( * V_13 ) )
F_14 ( F_15 ( * V_13 )
!= F_15 ( * V_9 ) ) ;
if ( F_8 ( * V_13 ) )
F_16 ( V_13 , * V_9 ) ;
F_17 ( V_14 ) ;
}
F_17 ( & V_11 ) ;
}
}
static T_5 void * F_18 ( void )
{
void * V_16 ;
if ( V_17 )
V_16 = ( void * ) F_19 ( V_18 | V_19 ) ;
else
V_16 = F_20 ( V_20 ) ;
if ( ! V_16 || ( ( unsigned long ) V_16 & ~ V_21 ) ) {
F_21 ( L_3 ,
V_17 ? L_4 : L_5 ) ;
}
F_22 ( L_6 , V_16 ) ;
return V_16 ;
}
static T_3 * F_23 ( T_2 * V_12 , unsigned long V_22 )
{
if ( F_6 ( * V_12 ) ) {
T_3 * V_13 = ( T_3 * ) F_18 () ;
F_24 ( & V_23 , V_12 , V_13 ) ;
if ( V_13 != F_7 ( V_12 , 0 ) )
F_25 ( V_24 L_7 ,
V_13 , F_7 ( V_12 , 0 ) ) ;
}
return F_7 ( V_12 , V_22 ) ;
}
static T_6 * F_26 ( T_3 * V_13 , unsigned long V_22 )
{
if ( F_8 ( * V_13 ) ) {
T_6 * V_25 = ( T_6 * ) F_18 () ;
F_27 ( & V_23 , V_13 , V_25 ) ;
if ( V_25 != F_28 ( V_13 , 0 ) )
F_25 ( V_24 L_8 ,
V_25 , F_28 ( V_13 , 0 ) ) ;
}
return F_28 ( V_13 , V_22 ) ;
}
static T_7 * F_29 ( T_6 * V_25 , unsigned long V_22 )
{
if ( F_30 ( * V_25 ) ) {
T_7 * V_26 = ( T_7 * ) F_18 () ;
F_31 ( & V_23 , V_25 , V_26 ) ;
if ( V_26 != F_32 ( V_25 , 0 ) )
F_25 ( V_24 L_9 ,
V_26 , F_32 ( V_25 , 0 ) ) ;
}
return F_32 ( V_25 , V_22 ) ;
}
static T_8 * F_33 ( T_7 * V_26 , unsigned long V_22 )
{
if ( F_34 ( * V_26 ) ) {
T_8 * V_27 = ( T_8 * ) F_18 () ;
F_35 ( & V_23 , V_26 , V_27 ) ;
if ( V_27 != F_36 ( V_26 , 0 ) )
F_25 ( V_24 L_10 ) ;
}
return F_36 ( V_26 , V_22 ) ;
}
static void F_37 ( T_6 * V_25 , unsigned long V_22 , T_8 V_28 )
{
T_7 * V_26 = F_29 ( V_25 , V_22 ) ;
T_8 * V_27 = F_33 ( V_26 , V_22 ) ;
F_38 ( V_27 , V_28 ) ;
F_39 ( V_22 ) ;
}
void F_40 ( T_3 * V_29 , unsigned long V_22 , T_8 V_28 )
{
T_3 * V_13 = V_29 + F_41 ( V_22 ) ;
T_6 * V_25 = F_26 ( V_13 , V_22 ) ;
F_37 ( V_25 , V_22 , V_28 ) ;
}
void F_42 ( T_6 * V_30 , unsigned long V_22 , T_8 V_28 )
{
T_6 * V_25 = V_30 + F_43 ( V_22 ) ;
F_37 ( V_25 , V_22 , V_28 ) ;
}
void F_44 ( unsigned long V_22 , T_8 V_31 )
{
T_2 * V_12 ;
T_3 * V_29 ;
F_22 ( L_11 , V_22 , F_45 ( V_31 ) ) ;
V_12 = F_4 ( V_22 ) ;
if ( F_6 ( * V_12 ) ) {
F_25 ( V_24
L_12 ) ;
return;
}
V_29 = F_7 ( V_12 , 0 ) ;
F_40 ( V_29 , V_22 , V_31 ) ;
}
T_7 * T_1 F_46 ( unsigned long V_22 )
{
T_2 * V_12 ;
T_3 * V_13 ;
T_6 * V_25 ;
V_12 = F_4 ( V_22 ) ;
V_13 = F_23 ( V_12 , V_22 ) ;
V_25 = F_26 ( V_13 , V_22 ) ;
return F_29 ( V_25 , V_22 ) ;
}
T_8 * T_1 F_47 ( unsigned long V_22 )
{
T_7 * V_26 ;
V_26 = F_46 ( V_22 ) ;
return F_33 ( V_26 , V_22 ) ;
}
static void T_1 F_48 ( unsigned long V_32 , unsigned long V_33 ,
enum V_34 V_35 )
{
T_2 * V_12 ;
T_3 * V_13 ;
T_6 * V_25 ;
T_7 * V_26 ;
T_9 V_36 ;
F_49 ( V_36 ) = F_49 ( V_37 ) |
F_49 ( F_50 ( F_51 ( V_35 ) ) ) ;
F_14 ( ( V_32 & ~ V_38 ) || ( V_33 & ~ V_38 ) ) ;
for (; V_33 ; V_32 += V_39 , V_33 -= V_39 ) {
V_12 = F_4 ( ( unsigned long ) F_52 ( V_32 ) ) ;
if ( F_6 ( * V_12 ) ) {
V_13 = ( T_3 * ) F_18 () ;
F_53 ( V_12 , F_54 ( F_55 ( V_13 ) | V_40 |
V_41 ) ) ;
}
V_13 = F_7 ( V_12 , ( unsigned long ) F_52 ( V_32 ) ) ;
if ( F_8 ( * V_13 ) ) {
V_25 = ( T_6 * ) F_18 () ;
F_16 ( V_13 , F_56 ( F_55 ( V_25 ) | V_40 |
V_41 ) ) ;
}
V_25 = F_28 ( V_13 , ( unsigned long ) F_52 ( V_32 ) ) ;
if ( F_30 ( * V_25 ) ) {
V_26 = ( T_7 * ) F_18 () ;
F_57 ( V_25 , F_58 ( F_55 ( V_26 ) | V_40 |
V_41 ) ) ;
}
V_26 = F_32 ( V_25 , V_32 ) ;
F_14 ( ! F_34 ( * V_26 ) ) ;
F_59 ( V_26 , F_60 ( V_32 | F_49 ( V_36 ) ) ) ;
}
}
void T_1 F_61 ( unsigned long V_32 , unsigned long V_33 )
{
F_48 ( V_32 , V_33 , V_42 ) ;
}
void T_1 F_62 ( unsigned long V_32 , unsigned long V_33 )
{
F_48 ( V_32 , V_33 , V_43 ) ;
}
void T_1 F_63 ( void )
{
unsigned long V_22 = V_44 ;
unsigned long V_45 = V_44 + V_46 ;
unsigned long V_5 = F_64 ( ( unsigned long ) V_47 , V_39 ) - 1 ;
T_7 * V_26 = V_48 ;
if ( V_49 )
V_45 = V_44 + ( V_49 << V_50 ) ;
for (; V_22 + V_39 - 1 < V_45 ; V_26 ++ , V_22 += V_39 ) {
if ( F_34 ( * V_26 ) )
continue;
if ( V_22 < ( unsigned long ) V_51 || V_22 > V_5 )
F_59 ( V_26 , F_60 ( 0 ) ) ;
}
}
static unsigned long T_10
F_65 ( T_8 * V_52 , unsigned long V_53 , unsigned long V_54 ,
T_9 V_36 )
{
unsigned long V_55 = 0 , V_56 ;
unsigned long V_57 = V_54 ;
T_8 * V_27 ;
int V_58 ;
V_27 = V_52 + F_66 ( V_53 ) ;
V_58 = F_66 ( V_53 ) ;
for (; V_58 < V_59 ; V_58 ++ , V_53 = V_56 , V_27 ++ ) {
V_56 = ( V_53 & V_21 ) + V_20 ;
if ( V_53 >= V_54 ) {
if ( ! V_17 &&
! F_67 ( V_53 & V_21 , V_56 ,
V_60 ) &&
! F_67 ( V_53 & V_21 , V_56 ,
V_61 ) )
F_38 ( V_27 , F_68 ( 0 ) ) ;
continue;
}
if ( ! F_69 ( * V_27 ) ) {
if ( ! V_17 )
V_55 ++ ;
continue;
}
if ( 0 )
F_70 ( L_13 , V_27 , V_53 ,
F_71 ( V_53 >> V_50 , V_62 ) . V_27 ) ;
V_55 ++ ;
F_38 ( V_27 , F_71 ( V_53 >> V_50 , V_36 ) ) ;
V_57 = ( V_53 & V_21 ) + V_20 ;
}
F_72 ( V_63 , V_55 ) ;
return V_57 ;
}
static unsigned long T_10
F_73 ( T_7 * V_64 , unsigned long V_53 , unsigned long V_54 ,
unsigned long V_65 , T_9 V_36 )
{
unsigned long V_55 = 0 , V_56 ;
unsigned long V_57 = V_54 ;
int V_58 = F_74 ( V_53 ) ;
for (; V_58 < V_66 ; V_58 ++ , V_53 = V_56 ) {
T_7 * V_26 = V_64 + F_74 ( V_53 ) ;
T_8 * V_27 ;
T_9 V_67 = V_36 ;
V_56 = ( V_53 & V_38 ) + V_39 ;
if ( V_53 >= V_54 ) {
if ( ! V_17 &&
! F_67 ( V_53 & V_38 , V_56 ,
V_60 ) &&
! F_67 ( V_53 & V_38 , V_56 ,
V_61 ) )
F_59 ( V_26 , F_60 ( 0 ) ) ;
continue;
}
if ( ! F_34 ( * V_26 ) ) {
if ( ! F_75 ( * V_26 ) ) {
F_9 ( & V_23 . V_15 ) ;
V_27 = ( T_8 * ) F_76 ( * V_26 ) ;
V_57 = F_65 ( V_27 , V_53 ,
V_54 , V_36 ) ;
F_17 ( & V_23 . V_15 ) ;
continue;
}
if ( V_65 & ( 1 << V_68 ) ) {
if ( ! V_17 )
V_55 ++ ;
V_57 = V_56 ;
continue;
}
V_67 = F_77 ( F_78 ( * ( T_8 * ) V_26 ) ) ;
}
if ( V_65 & ( 1 << V_68 ) ) {
V_55 ++ ;
F_9 ( & V_23 . V_15 ) ;
F_38 ( ( T_8 * ) V_26 ,
F_71 ( ( V_53 & V_38 ) >> V_50 ,
F_79 ( F_49 ( V_36 ) | V_69 ) ) ) ;
F_17 ( & V_23 . V_15 ) ;
V_57 = V_56 ;
continue;
}
V_27 = F_80 () ;
V_57 = F_65 ( V_27 , V_53 , V_54 , V_67 ) ;
F_9 ( & V_23 . V_15 ) ;
F_35 ( & V_23 , V_26 , V_27 ) ;
F_17 ( & V_23 . V_15 ) ;
}
F_72 ( V_68 , V_55 ) ;
return V_57 ;
}
static unsigned long T_10
F_81 ( T_6 * V_30 , unsigned long V_53 , unsigned long V_54 ,
unsigned long V_65 )
{
unsigned long V_55 = 0 , V_56 ;
unsigned long V_57 = V_54 ;
unsigned long V_22 = ( unsigned long ) F_52 ( V_53 ) ;
int V_58 = F_43 ( V_22 ) ;
for (; V_58 < V_70 ; V_58 ++ , V_53 = V_56 ) {
T_6 * V_25 ;
T_7 * V_26 ;
T_9 V_36 = V_62 ;
V_22 = ( unsigned long ) F_52 ( V_53 ) ;
V_25 = V_30 + F_43 ( V_22 ) ;
V_56 = ( V_53 & V_71 ) + V_72 ;
if ( V_53 >= V_54 ) {
if ( ! V_17 &&
! F_67 ( V_53 & V_71 , V_56 ,
V_60 ) &&
! F_67 ( V_53 & V_71 , V_56 ,
V_61 ) )
F_57 ( V_25 , F_58 ( 0 ) ) ;
continue;
}
if ( ! F_30 ( * V_25 ) ) {
if ( ! F_82 ( * V_25 ) ) {
V_26 = F_32 ( V_25 , 0 ) ;
V_57 = F_73 ( V_26 , V_53 ,
V_54 ,
V_65 ,
V_36 ) ;
F_83 () ;
continue;
}
if ( V_65 & ( 1 << V_73 ) ) {
if ( ! V_17 )
V_55 ++ ;
V_57 = V_56 ;
continue;
}
V_36 = F_77 ( F_78 ( * ( T_8 * ) V_25 ) ) ;
}
if ( V_65 & ( 1 << V_73 ) ) {
V_55 ++ ;
F_9 ( & V_23 . V_15 ) ;
F_38 ( ( T_8 * ) V_25 ,
F_71 ( ( V_53 & V_71 ) >> V_50 ,
V_37 ) ) ;
F_17 ( & V_23 . V_15 ) ;
V_57 = V_56 ;
continue;
}
V_26 = F_80 () ;
V_57 = F_73 ( V_26 , V_53 , V_54 ,
V_65 , V_36 ) ;
F_9 ( & V_23 . V_15 ) ;
F_31 ( & V_23 , V_25 , V_26 ) ;
F_17 ( & V_23 . V_15 ) ;
}
F_83 () ;
F_72 ( V_73 , V_55 ) ;
return V_57 ;
}
unsigned long T_10
F_84 ( unsigned long V_74 ,
unsigned long V_54 ,
unsigned long V_65 )
{
bool V_75 = false ;
unsigned long V_22 , V_76 , V_45 , V_77 , V_57 ;
V_57 = V_54 ;
V_22 = ( unsigned long ) F_52 ( V_74 ) ;
V_45 = ( unsigned long ) F_52 ( V_54 ) ;
V_76 = V_22 ;
for (; V_22 < V_45 ; V_22 = V_77 ) {
T_2 * V_12 = F_4 ( V_22 ) ;
T_3 * V_13 ;
T_6 * V_25 ;
V_77 = ( V_22 & V_78 ) + V_7 ;
F_5 ( F_6 ( * V_12 ) ) ;
V_13 = F_7 ( V_12 , V_22 ) ;
if ( F_85 ( * V_13 ) ) {
V_25 = ( T_6 * ) F_15 ( * V_13 ) ;
V_57 = F_81 ( V_25 , F_55 ( V_22 ) ,
F_55 ( V_45 ) ,
V_65 ) ;
continue;
}
V_25 = F_80 () ;
V_57 = F_81 ( V_25 , F_55 ( V_22 ) , F_55 ( V_45 ) ,
V_65 ) ;
F_9 ( & V_23 . V_15 ) ;
F_27 ( & V_23 , V_13 , V_25 ) ;
F_17 ( & V_23 . V_15 ) ;
V_75 = true ;
}
if ( V_75 )
F_2 ( V_76 , V_45 - 1 ) ;
F_83 () ;
return V_57 ;
}
void T_1 F_86 ( void )
{
F_87 ( 0 , ( V_79 ) V_80 , & V_81 . V_82 , 0 ) ;
}
void T_1 F_88 ( void )
{
F_89 ( V_83 ) ;
F_90 () ;
F_91 ( 0 , V_84 ) ;
if ( V_84 != V_85 )
F_91 ( 0 , V_85 ) ;
F_92 () ;
}
static void F_93 ( T_11 V_4 , T_11 V_33 )
{
unsigned long V_86 = F_94 ( V_4 + V_33 ) ;
if ( V_86 > V_87 ) {
V_87 = V_86 ;
V_88 = V_86 ;
V_89 = ( void * ) F_52 ( V_87 * V_20 - 1 ) + 1 ;
}
}
int F_95 ( int V_90 , T_11 V_4 , T_11 V_33 , bool V_91 )
{
struct V_92 * V_93 = F_96 ( V_90 ) ;
struct V_94 * V_94 = V_93 -> V_95 +
F_97 ( V_90 , V_4 , V_33 , V_96 , V_91 ) ;
unsigned long V_97 = V_4 >> V_50 ;
unsigned long V_98 = V_33 >> V_50 ;
int V_99 ;
F_98 ( V_4 , V_4 + V_33 ) ;
V_99 = F_99 ( V_90 , V_94 , V_97 , V_98 ) ;
F_100 ( V_99 ) ;
F_93 ( V_4 , V_33 ) ;
return V_99 ;
}
static void T_10 F_101 ( struct V_10 * V_10 , int V_100 )
{
unsigned long V_101 ;
unsigned int V_98 = 1 << V_100 ;
struct V_102 * V_103 = F_102 ( ( unsigned long ) V_10 ) ;
if ( V_103 ) {
F_103 ( V_103 , V_98 ) ;
return;
}
if ( F_104 ( V_10 ) ) {
F_105 ( V_10 ) ;
V_101 = ( unsigned long ) V_10 -> V_104 ;
if ( V_101 == V_105 || V_101 == V_106 ) {
while ( V_98 -- )
F_106 ( V_10 ++ ) ;
} else
while ( V_98 -- )
F_107 ( V_10 ++ ) ;
} else
F_108 ( ( unsigned long ) F_11 ( V_10 ) , V_100 ) ;
}
static void T_10 F_109 ( T_8 * V_107 , T_7 * V_26 )
{
T_8 * V_27 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
V_27 = V_107 + V_58 ;
if ( ! F_69 ( * V_27 ) )
return;
}
F_101 ( V_64 ( * V_26 ) , 0 ) ;
F_9 ( & V_23 . V_15 ) ;
F_110 ( V_26 ) ;
F_17 ( & V_23 . V_15 ) ;
}
static void T_10 F_111 ( T_7 * V_108 , T_6 * V_25 )
{
T_7 * V_26 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_66 ; V_58 ++ ) {
V_26 = V_108 + V_58 ;
if ( ! F_34 ( * V_26 ) )
return;
}
F_101 ( V_30 ( * V_25 ) , 0 ) ;
F_9 ( & V_23 . V_15 ) ;
F_112 ( V_25 ) ;
F_17 ( & V_23 . V_15 ) ;
}
static void T_10 F_113 ( T_6 * V_109 , T_3 * V_13 )
{
T_6 * V_25 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_70 ; V_58 ++ ) {
V_25 = V_109 + V_58 ;
if ( ! F_30 ( * V_25 ) )
return;
}
F_101 ( V_29 ( * V_13 ) , 0 ) ;
F_9 ( & V_23 . V_15 ) ;
F_114 ( V_13 ) ;
F_17 ( & V_23 . V_15 ) ;
}
static void T_10
F_115 ( T_8 * V_107 , unsigned long V_6 , unsigned long V_5 ,
bool V_110 )
{
unsigned long V_111 , V_55 = 0 ;
T_8 * V_27 ;
void * V_112 ;
V_79 V_113 ;
V_27 = V_107 + F_66 ( V_6 ) ;
for (; V_6 < V_5 ; V_6 = V_111 , V_27 ++ ) {
V_111 = ( V_6 + V_20 ) & V_21 ;
if ( V_111 > V_5 )
V_111 = V_5 ;
if ( ! F_116 ( * V_27 ) )
continue;
V_113 = F_117 ( * V_27 ) + ( V_6 & V_21 ) ;
if ( V_113 < ( V_79 ) 0x40000000 )
return;
if ( F_118 ( V_6 ) && F_118 ( V_111 ) ) {
if ( ! V_110 )
F_101 ( V_52 ( * V_27 ) , 0 ) ;
F_9 ( & V_23 . V_15 ) ;
F_119 ( & V_23 , V_6 , V_27 ) ;
F_17 ( & V_23 . V_15 ) ;
V_55 ++ ;
} else {
memset ( ( void * ) V_6 , V_114 , V_111 - V_6 ) ;
V_112 = F_11 ( V_52 ( * V_27 ) ) ;
if ( ! F_120 ( V_112 , V_114 , V_20 ) ) {
F_101 ( V_52 ( * V_27 ) , 0 ) ;
F_9 ( & V_23 . V_15 ) ;
F_119 ( & V_23 , V_6 , V_27 ) ;
F_17 ( & V_23 . V_15 ) ;
}
}
}
F_121 () ;
if ( V_110 )
F_72 ( V_63 , - V_55 ) ;
}
static void T_10
F_122 ( T_7 * V_108 , unsigned long V_6 , unsigned long V_5 ,
bool V_110 )
{
unsigned long V_111 , V_55 = 0 ;
T_8 * V_115 ;
T_7 * V_26 ;
void * V_112 ;
V_26 = V_108 + F_74 ( V_6 ) ;
for (; V_6 < V_5 ; V_6 = V_111 , V_26 ++ ) {
V_111 = F_123 ( V_6 , V_5 ) ;
if ( ! F_124 ( * V_26 ) )
continue;
if ( F_75 ( * V_26 ) ) {
if ( F_125 ( V_6 , V_39 ) &&
F_125 ( V_111 , V_39 ) ) {
if ( ! V_110 )
F_101 ( V_64 ( * V_26 ) ,
F_126 ( V_39 ) ) ;
F_9 ( & V_23 . V_15 ) ;
F_110 ( V_26 ) ;
F_17 ( & V_23 . V_15 ) ;
V_55 ++ ;
} else {
memset ( ( void * ) V_6 , V_114 , V_111 - V_6 ) ;
V_112 = F_11 ( V_64 ( * V_26 ) ) ;
if ( ! F_120 ( V_112 , V_114 ,
V_39 ) ) {
F_101 ( V_64 ( * V_26 ) ,
F_126 ( V_39 ) ) ;
F_9 ( & V_23 . V_15 ) ;
F_110 ( V_26 ) ;
F_17 ( & V_23 . V_15 ) ;
}
}
continue;
}
V_115 = ( T_8 * ) F_76 ( * V_26 ) ;
F_115 ( V_115 , V_6 , V_111 , V_110 ) ;
F_109 ( V_115 , V_26 ) ;
}
if ( V_110 )
F_72 ( V_68 , - V_55 ) ;
}
static void T_10
F_127 ( T_6 * V_109 , unsigned long V_6 , unsigned long V_5 ,
bool V_110 )
{
unsigned long V_111 , V_55 = 0 ;
T_7 * V_116 ;
T_6 * V_25 ;
void * V_112 ;
V_25 = V_109 + F_43 ( V_6 ) ;
for (; V_6 < V_5 ; V_6 = V_111 , V_25 ++ ) {
V_111 = F_128 ( V_6 , V_5 ) ;
if ( ! F_129 ( * V_25 ) )
continue;
if ( F_82 ( * V_25 ) ) {
if ( F_125 ( V_6 , V_72 ) &&
F_125 ( V_111 , V_72 ) ) {
if ( ! V_110 )
F_101 ( V_30 ( * V_25 ) ,
F_126 ( V_72 ) ) ;
F_9 ( & V_23 . V_15 ) ;
F_112 ( V_25 ) ;
F_17 ( & V_23 . V_15 ) ;
V_55 ++ ;
} else {
memset ( ( void * ) V_6 , V_114 , V_111 - V_6 ) ;
V_112 = F_11 ( V_30 ( * V_25 ) ) ;
if ( ! F_120 ( V_112 , V_114 ,
V_72 ) ) {
F_101 ( V_30 ( * V_25 ) ,
F_126 ( V_72 ) ) ;
F_9 ( & V_23 . V_15 ) ;
F_112 ( V_25 ) ;
F_17 ( & V_23 . V_15 ) ;
}
}
continue;
}
V_116 = F_32 ( V_25 , 0 ) ;
F_122 ( V_116 , V_6 , V_111 , V_110 ) ;
F_111 ( V_116 , V_25 ) ;
}
if ( V_110 )
F_72 ( V_73 , - V_55 ) ;
}
static void T_10
F_130 ( T_3 * V_117 , unsigned long V_6 , unsigned long V_5 ,
bool V_110 )
{
unsigned long V_111 , V_55 = 0 ;
T_6 * V_118 ;
T_3 * V_13 ;
V_13 = V_117 + F_41 ( V_6 ) ;
for (; V_6 < V_5 ; V_6 = V_111 , V_13 ++ ) {
V_111 = F_131 ( V_6 , V_5 ) ;
if ( ! F_132 ( * V_13 ) )
continue;
F_5 ( F_133 ( * V_13 ) ) ;
V_118 = F_28 ( V_13 , 0 ) ;
F_127 ( V_118 , V_6 , V_111 , V_110 ) ;
if ( V_119 == 5 )
F_113 ( V_118 , V_13 ) ;
}
if ( V_110 )
F_72 ( V_120 , - V_55 ) ;
}
static void T_10
F_134 ( unsigned long V_4 , unsigned long V_5 , bool V_110 )
{
unsigned long V_111 ;
unsigned long V_6 ;
T_2 * V_12 ;
T_3 * V_13 ;
for ( V_6 = V_4 ; V_6 < V_5 ; V_6 = V_111 ) {
V_111 = F_135 ( V_6 , V_5 ) ;
V_12 = F_4 ( V_6 ) ;
if ( ! F_136 ( * V_12 ) )
continue;
V_13 = F_7 ( V_12 , 0 ) ;
F_130 ( V_13 , V_6 , V_111 , V_110 ) ;
}
F_121 () ;
}
void T_5 F_137 ( unsigned long V_4 , unsigned long V_5 )
{
F_134 ( V_4 , V_5 , false ) ;
}
static void T_10
F_138 ( unsigned long V_4 , unsigned long V_5 )
{
V_4 = ( unsigned long ) F_52 ( V_4 ) ;
V_5 = ( unsigned long ) F_52 ( V_5 ) ;
F_134 ( V_4 , V_5 , true ) ;
}
int T_5 F_139 ( T_11 V_4 , T_11 V_33 )
{
unsigned long V_97 = V_4 >> V_50 ;
unsigned long V_98 = V_33 >> V_50 ;
struct V_10 * V_10 = F_140 ( V_97 ) ;
struct V_102 * V_103 ;
struct V_94 * V_94 ;
int V_99 ;
V_103 = F_102 ( ( unsigned long ) V_10 ) ;
if ( V_103 )
V_10 += F_141 ( V_103 ) ;
V_94 = F_142 ( V_10 ) ;
V_99 = F_143 ( V_94 , V_97 , V_98 ) ;
F_100 ( V_99 ) ;
F_138 ( V_4 , V_4 + V_33 ) ;
return V_99 ;
}
static void T_1 F_144 ( void )
{
#ifdef F_145
int V_58 ;
F_146 (i)
F_147 ( F_96 ( V_58 ) ) ;
#endif
}
void T_1 F_148 ( void )
{
F_149 () ;
F_144 () ;
F_150 () ;
V_17 = 1 ;
F_151 ( & V_121 , ( void * ) V_122 ,
V_20 , V_123 ) ;
F_152 ( NULL ) ;
}
void F_153 ( void )
{
unsigned long V_4 = F_154 ( V_51 ) ;
unsigned long V_5 = F_154 ( V_124 ) ;
if ( ! V_125 )
return;
F_22 ( L_14 ,
V_4 , V_5 ) ;
F_155 ( V_4 , ( V_5 - V_4 ) >> V_50 ) ;
}
void F_156 ( void )
{
unsigned long V_4 = F_154 ( V_51 ) ;
unsigned long V_5 = F_154 ( V_124 ) ;
if ( ! V_125 )
return;
F_22 ( L_15 ,
V_4 , V_5 ) ;
F_157 ( V_4 , ( V_5 - V_4 ) >> V_50 ) ;
}
void F_158 ( void )
{
unsigned long V_4 = F_154 ( V_51 ) ;
unsigned long V_126 = F_154 ( V_127 ) ;
unsigned long V_5 = ( unsigned long ) & V_128 ;
unsigned long V_129 = F_154 ( & V_124 ) ;
unsigned long V_130 = F_154 ( & V_131 ) ;
unsigned long V_132 ;
F_25 ( V_133 L_16 ,
( V_5 - V_4 ) >> 10 ) ;
F_157 ( V_4 , ( V_5 - V_4 ) >> V_50 ) ;
V_125 = 1 ;
V_132 = F_64 ( ( unsigned long ) V_47 , V_39 ) ;
F_159 ( V_129 , ( V_132 - V_129 ) >> V_50 ) ;
#ifdef F_160
F_25 ( V_133 L_17 , V_4 , V_5 ) ;
F_155 ( V_4 , ( V_5 - V_4 ) >> V_50 ) ;
F_25 ( V_133 L_18 ) ;
F_157 ( V_4 , ( V_5 - V_4 ) >> V_50 ) ;
#endif
F_161 ( L_19 ,
( unsigned long ) F_52 ( F_162 ( V_129 ) ) ,
( unsigned long ) F_52 ( F_162 ( V_126 ) ) ) ;
F_161 ( L_19 ,
( unsigned long ) F_52 ( F_162 ( V_130 ) ) ,
( unsigned long ) F_52 ( F_162 ( V_134 ) ) ) ;
F_163 () ;
}
int F_164 ( unsigned long V_6 )
{
unsigned long V_135 = ( ( long ) V_6 ) >> V_136 ;
T_2 * V_12 ;
T_3 * V_13 ;
T_6 * V_25 ;
T_7 * V_26 ;
T_8 * V_27 ;
if ( V_135 != 0 && V_135 != - 1UL )
return 0 ;
V_12 = F_4 ( V_6 ) ;
if ( F_6 ( * V_12 ) )
return 0 ;
V_13 = F_7 ( V_12 , V_6 ) ;
if ( F_8 ( * V_13 ) )
return 0 ;
V_25 = F_28 ( V_13 , V_6 ) ;
if ( F_30 ( * V_25 ) )
return 0 ;
if ( F_82 ( * V_25 ) )
return F_165 ( F_166 ( * V_25 ) ) ;
V_26 = F_32 ( V_25 , V_6 ) ;
if ( F_34 ( * V_26 ) )
return 0 ;
if ( F_75 ( * V_26 ) )
return F_165 ( F_167 ( * V_26 ) ) ;
V_27 = F_36 ( V_26 , V_6 ) ;
if ( F_69 ( * V_27 ) )
return 0 ;
return F_165 ( F_168 ( * V_27 ) ) ;
}
static unsigned long F_169 ( void )
{
unsigned long V_137 = V_138 ;
if ( F_170 () || ( ( V_87 << V_50 ) >= ( 64UL << 30 ) ) )
V_137 = 2UL << 30 ;
F_70 ( L_20 , V_137 >> 20 ) ;
return V_137 ;
}
unsigned long F_171 ( void )
{
if ( ! V_139 )
V_139 = F_169 () ;
return V_139 ;
}
static int T_10 F_172 ( unsigned long V_4 ,
unsigned long V_5 , int V_140 , struct V_102 * V_103 )
{
unsigned long V_6 ;
unsigned long V_111 ;
T_2 * V_12 ;
T_3 * V_13 ;
T_6 * V_25 ;
T_7 * V_26 ;
for ( V_6 = V_4 ; V_6 < V_5 ; V_6 = V_111 ) {
V_111 = F_123 ( V_6 , V_5 ) ;
V_12 = F_173 ( V_6 , V_140 ) ;
if ( ! V_12 )
return - V_141 ;
V_13 = F_174 ( V_12 , V_6 , V_140 ) ;
if ( ! V_13 )
return - V_141 ;
V_25 = F_175 ( V_13 , V_6 , V_140 ) ;
if ( ! V_25 )
return - V_141 ;
V_26 = F_32 ( V_25 , V_6 ) ;
if ( F_34 ( * V_26 ) ) {
void * V_142 ;
V_142 = F_176 ( V_39 , V_140 , V_103 ) ;
if ( V_142 ) {
T_8 V_143 ;
V_143 = F_71 ( F_55 ( V_142 ) >> V_50 ,
V_37 ) ;
F_59 ( V_26 , F_60 ( F_117 ( V_143 ) ) ) ;
if ( V_144 != V_142 || V_145 != V_140 ) {
if ( V_146 )
F_22 ( L_21 ,
V_147 , V_148 - 1 , V_146 , V_144 - 1 , V_145 ) ;
V_147 = V_6 ;
V_145 = V_140 ;
V_146 = V_142 ;
}
V_148 = V_6 + V_39 ;
V_144 = V_142 + V_39 ;
continue;
} else if ( V_103 )
return - V_141 ;
} else if ( F_75 ( * V_26 ) ) {
F_177 ( ( T_8 * ) V_26 , V_140 , V_6 , V_111 ) ;
continue;
}
F_178 ( L_22 ) ;
if ( F_179 ( V_6 , V_111 , V_140 ) )
return - V_141 ;
}
return 0 ;
}
int T_10 F_180 ( unsigned long V_4 , unsigned long V_5 , int V_140 )
{
struct V_102 * V_103 = F_102 ( V_4 ) ;
int V_149 ;
if ( F_181 ( V_150 ) )
V_149 = F_172 ( V_4 , V_5 , V_140 , V_103 ) ;
else if ( V_103 ) {
F_182 ( L_23 ,
V_151 ) ;
V_149 = - V_141 ;
} else
V_149 = F_179 ( V_4 , V_5 , V_140 ) ;
if ( ! V_149 )
F_2 ( V_4 , V_5 - 1 ) ;
return V_149 ;
}
void F_183 ( unsigned long V_152 ,
struct V_10 * V_153 , unsigned long V_33 )
{
unsigned long V_6 = ( unsigned long ) V_153 ;
unsigned long V_5 = ( unsigned long ) ( V_153 + V_33 ) ;
unsigned long V_111 ;
T_2 * V_12 ;
T_3 * V_13 ;
T_6 * V_25 ;
T_7 * V_26 ;
unsigned int V_98 ;
struct V_10 * V_10 ;
for (; V_6 < V_5 ; V_6 = V_111 ) {
T_8 * V_27 = NULL ;
V_12 = F_4 ( V_6 ) ;
if ( F_6 ( * V_12 ) ) {
V_111 = ( V_6 + V_20 ) & V_21 ;
continue;
}
F_184 ( V_152 , F_185 ( * V_12 ) , V_106 ) ;
V_13 = F_7 ( V_12 , V_6 ) ;
if ( F_8 ( * V_13 ) ) {
V_111 = ( V_6 + V_20 ) & V_21 ;
continue;
}
F_184 ( V_152 , V_29 ( * V_13 ) , V_106 ) ;
V_25 = F_28 ( V_13 , V_6 ) ;
if ( F_30 ( * V_25 ) ) {
V_111 = ( V_6 + V_20 ) & V_21 ;
continue;
}
F_184 ( V_152 , V_30 ( * V_25 ) , V_106 ) ;
if ( ! F_181 ( V_150 ) ) {
V_111 = ( V_6 + V_20 ) & V_21 ;
V_26 = F_32 ( V_25 , V_6 ) ;
if ( F_34 ( * V_26 ) )
continue;
F_184 ( V_152 , V_64 ( * V_26 ) ,
V_106 ) ;
V_27 = F_36 ( V_26 , V_6 ) ;
if ( F_69 ( * V_27 ) )
continue;
F_184 ( V_152 , V_52 ( * V_27 ) ,
V_105 ) ;
} else {
V_111 = F_123 ( V_6 , V_5 ) ;
V_26 = F_32 ( V_25 , V_6 ) ;
if ( F_34 ( * V_26 ) )
continue;
V_98 = 1 << ( F_126 ( V_39 ) ) ;
V_10 = V_64 ( * V_26 ) ;
while ( V_98 -- )
F_184 ( V_152 , V_10 ++ ,
V_105 ) ;
}
}
}
void T_10 F_186 ( void )
{
if ( V_146 ) {
F_22 ( L_21 ,
V_147 , V_148 - 1 , V_146 , V_144 - 1 , V_145 ) ;
V_146 = NULL ;
V_144 = NULL ;
V_145 = 0 ;
}
}
