static int T_1 F_1 ( char * V_1 )
{
if ( ! strcmp ( V_1 , L_1 ) )
V_2 &= ~ V_3 ;
else if ( ! strcmp ( V_1 , L_2 ) )
V_2 |= V_3 ;
return 1 ;
}
void F_2 ( unsigned long V_4 , unsigned long V_5 , int V_6 )
{
unsigned long V_7 ;
for ( V_7 = V_4 ; V_7 <= V_5 ; V_7 += V_8 ) {
const T_2 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_10 ;
if ( F_4 ( * V_9 ) && ! V_6 )
continue;
F_5 ( & V_11 ) ;
F_6 (page, &pgd_list, lru) {
T_2 * V_12 ;
T_3 * V_13 ;
V_12 = ( T_2 * ) F_7 ( V_10 ) + F_8 ( V_7 ) ;
V_13 = & F_9 ( V_10 ) -> V_14 ;
F_5 ( V_13 ) ;
if ( ! F_4 ( * V_9 ) && ! F_4 ( * V_12 ) )
F_10 ( F_11 ( * V_12 )
!= F_11 ( * V_9 ) ) ;
if ( V_6 ) {
if ( F_4 ( * V_9 ) && ! F_4 ( * V_12 ) )
F_12 ( V_12 ) ;
} else {
if ( F_4 ( * V_12 ) )
F_13 ( V_12 , * V_9 ) ;
}
F_14 ( V_13 ) ;
}
F_14 ( & V_11 ) ;
}
}
static T_4 void * F_15 ( void )
{
void * V_15 ;
if ( V_16 )
V_15 = ( void * ) F_16 ( V_17 | V_18 ) ;
else
V_15 = F_17 ( V_19 ) ;
if ( ! V_15 || ( ( unsigned long ) V_15 & ~ V_20 ) ) {
F_18 ( L_3 ,
V_16 ? L_4 : L_5 ) ;
}
F_19 ( L_6 , V_15 ) ;
return V_15 ;
}
static T_5 * F_20 ( T_2 * V_12 , unsigned long V_21 )
{
if ( F_4 ( * V_12 ) ) {
T_5 * V_22 = ( T_5 * ) F_15 () ;
F_21 ( & V_23 , V_12 , V_22 ) ;
if ( V_22 != F_22 ( V_12 , 0 ) )
F_23 ( V_24 L_7 ,
V_22 , F_22 ( V_12 , 0 ) ) ;
}
return F_22 ( V_12 , V_21 ) ;
}
static T_6 * F_24 ( T_5 * V_22 , unsigned long V_21 )
{
if ( F_25 ( * V_22 ) ) {
T_6 * V_25 = ( T_6 * ) F_15 () ;
F_26 ( & V_23 , V_22 , V_25 ) ;
if ( V_25 != F_27 ( V_22 , 0 ) )
F_23 ( V_24 L_8 ,
V_25 , F_27 ( V_22 , 0 ) ) ;
}
return F_27 ( V_22 , V_21 ) ;
}
static T_7 * F_28 ( T_6 * V_25 , unsigned long V_21 )
{
if ( F_29 ( * V_25 ) ) {
T_7 * V_26 = ( T_7 * ) F_15 () ;
F_30 ( & V_23 , V_25 , V_26 ) ;
if ( V_26 != F_31 ( V_25 , 0 ) )
F_23 ( V_24 L_9 ) ;
}
return F_31 ( V_25 , V_21 ) ;
}
void F_32 ( T_5 * V_27 , unsigned long V_21 , T_7 V_28 )
{
T_5 * V_22 ;
T_6 * V_25 ;
T_7 * V_26 ;
V_22 = V_27 + F_33 ( V_21 ) ;
V_25 = F_24 ( V_22 , V_21 ) ;
V_26 = F_28 ( V_25 , V_21 ) ;
F_34 ( V_26 , V_28 ) ;
F_35 ( V_21 ) ;
}
void F_36 ( unsigned long V_21 , T_7 V_29 )
{
T_2 * V_12 ;
T_5 * V_27 ;
F_19 ( L_10 , V_21 , F_37 ( V_29 ) ) ;
V_12 = F_3 ( V_21 ) ;
if ( F_4 ( * V_12 ) ) {
F_23 ( V_24
L_11 ) ;
return;
}
V_27 = ( T_5 * ) F_11 ( * V_12 ) ;
F_32 ( V_27 , V_21 , V_29 ) ;
}
T_6 * T_1 F_38 ( unsigned long V_21 )
{
T_2 * V_12 ;
T_5 * V_22 ;
V_12 = F_3 ( V_21 ) ;
V_22 = F_20 ( V_12 , V_21 ) ;
return F_24 ( V_22 , V_21 ) ;
}
T_7 * T_1 F_39 ( unsigned long V_21 )
{
T_6 * V_25 ;
V_25 = F_38 ( V_21 ) ;
return F_28 ( V_25 , V_21 ) ;
}
static void T_1 F_40 ( unsigned long V_30 , unsigned long V_31 ,
enum V_32 V_33 )
{
T_2 * V_12 ;
T_5 * V_22 ;
T_6 * V_25 ;
T_8 V_34 ;
F_41 ( V_34 ) = F_41 ( V_35 ) |
F_41 ( F_42 ( F_43 ( V_33 ) ) ) ;
F_10 ( ( V_30 & ~ V_36 ) || ( V_31 & ~ V_36 ) ) ;
for (; V_31 ; V_30 += V_37 , V_31 -= V_37 ) {
V_12 = F_3 ( ( unsigned long ) F_44 ( V_30 ) ) ;
if ( F_4 ( * V_12 ) ) {
V_22 = ( T_5 * ) F_15 () ;
F_13 ( V_12 , F_45 ( F_46 ( V_22 ) | V_38 |
V_39 ) ) ;
}
V_22 = F_22 ( V_12 , ( unsigned long ) F_44 ( V_30 ) ) ;
if ( F_25 ( * V_22 ) ) {
V_25 = ( T_6 * ) F_15 () ;
F_47 ( V_22 , F_48 ( F_46 ( V_25 ) | V_38 |
V_39 ) ) ;
}
V_25 = F_27 ( V_22 , V_30 ) ;
F_10 ( ! F_29 ( * V_25 ) ) ;
F_49 ( V_25 , F_50 ( V_30 | F_41 ( V_34 ) ) ) ;
}
}
void T_1 F_51 ( unsigned long V_30 , unsigned long V_31 )
{
F_40 ( V_30 , V_31 , V_40 ) ;
}
void T_1 F_52 ( unsigned long V_30 , unsigned long V_31 )
{
F_40 ( V_30 , V_31 , V_41 ) ;
}
void T_1 F_53 ( void )
{
unsigned long V_21 = V_42 ;
unsigned long V_43 = V_42 + V_44 ;
unsigned long V_5 = F_54 ( ( unsigned long ) V_45 , V_37 ) - 1 ;
T_6 * V_25 = V_46 ;
if ( V_47 )
V_43 = V_42 + ( V_47 << V_48 ) ;
for (; V_21 + V_37 - 1 < V_43 ; V_25 ++ , V_21 += V_37 ) {
if ( F_29 ( * V_25 ) )
continue;
if ( V_21 < ( unsigned long ) V_49 || V_21 > V_5 )
F_49 ( V_25 , F_50 ( 0 ) ) ;
}
}
static unsigned long T_9
F_55 ( T_7 * V_50 , unsigned long V_51 , unsigned long V_5 ,
T_8 V_34 )
{
unsigned long V_52 = 0 , V_53 ;
unsigned long V_54 = V_5 ;
int V_55 ;
T_7 * V_26 = V_50 + F_56 ( V_51 ) ;
for ( V_55 = F_56 ( V_51 ) ; V_55 < V_56 ; V_55 ++ , V_51 = V_53 , V_26 ++ ) {
V_53 = ( V_51 & V_20 ) + V_19 ;
if ( V_51 >= V_5 ) {
if ( ! V_16 &&
! F_57 ( V_51 & V_20 , V_53 , V_57 ) &&
! F_57 ( V_51 & V_20 , V_53 , V_58 ) )
F_34 ( V_26 , F_58 ( 0 ) ) ;
continue;
}
if ( F_59 ( * V_26 ) ) {
if ( ! V_16 )
V_52 ++ ;
continue;
}
if ( 0 )
F_23 ( L_12 ,
V_26 , V_51 , F_60 ( V_51 >> V_48 , V_59 ) . V_26 ) ;
V_52 ++ ;
F_34 ( V_26 , F_60 ( V_51 >> V_48 , V_34 ) ) ;
V_54 = ( V_51 & V_20 ) + V_19 ;
}
F_61 ( V_60 , V_52 ) ;
return V_54 ;
}
static unsigned long T_9
F_62 ( T_6 * V_61 , unsigned long V_7 , unsigned long V_5 ,
unsigned long V_62 , T_8 V_34 )
{
unsigned long V_52 = 0 , V_53 ;
unsigned long V_54 = V_5 ;
int V_55 = F_63 ( V_7 ) ;
for (; V_55 < V_63 ; V_55 ++ , V_7 = V_53 ) {
T_6 * V_25 = V_61 + F_63 ( V_7 ) ;
T_7 * V_26 ;
T_8 V_64 = V_34 ;
V_53 = ( V_7 & V_36 ) + V_37 ;
if ( V_7 >= V_5 ) {
if ( ! V_16 &&
! F_57 ( V_7 & V_36 , V_53 , V_57 ) &&
! F_57 ( V_7 & V_36 , V_53 , V_58 ) )
F_49 ( V_25 , F_50 ( 0 ) ) ;
continue;
}
if ( F_64 ( * V_25 ) ) {
if ( ! F_65 ( * V_25 ) ) {
F_5 ( & V_23 . V_14 ) ;
V_26 = ( T_7 * ) F_66 ( * V_25 ) ;
V_54 = F_55 ( V_26 , V_7 ,
V_5 , V_34 ) ;
F_14 ( & V_23 . V_14 ) ;
continue;
}
if ( V_62 & ( 1 << V_65 ) ) {
if ( ! V_16 )
V_52 ++ ;
V_54 = V_53 ;
continue;
}
V_64 = F_67 ( F_68 ( * ( T_7 * ) V_25 ) ) ;
}
if ( V_62 & ( 1 << V_65 ) ) {
V_52 ++ ;
F_5 ( & V_23 . V_14 ) ;
F_34 ( ( T_7 * ) V_25 ,
F_60 ( ( V_7 & V_36 ) >> V_48 ,
F_69 ( F_41 ( V_34 ) | V_66 ) ) ) ;
F_14 ( & V_23 . V_14 ) ;
V_54 = V_53 ;
continue;
}
V_26 = F_70 () ;
V_54 = F_55 ( V_26 , V_7 , V_5 , V_64 ) ;
F_5 ( & V_23 . V_14 ) ;
F_30 ( & V_23 , V_25 , V_26 ) ;
F_14 ( & V_23 . V_14 ) ;
}
F_61 ( V_65 , V_52 ) ;
return V_54 ;
}
static unsigned long T_9
F_71 ( T_5 * V_27 , unsigned long V_51 , unsigned long V_5 ,
unsigned long V_62 )
{
unsigned long V_52 = 0 , V_53 ;
unsigned long V_54 = V_5 ;
int V_55 = F_33 ( V_51 ) ;
for (; V_55 < V_67 ; V_55 ++ , V_51 = V_53 ) {
T_5 * V_22 = V_27 + F_33 ( V_51 ) ;
T_6 * V_25 ;
T_8 V_34 = V_59 ;
V_53 = ( V_51 & V_68 ) + V_69 ;
if ( V_51 >= V_5 ) {
if ( ! V_16 &&
! F_57 ( V_51 & V_68 , V_53 , V_57 ) &&
! F_57 ( V_51 & V_68 , V_53 , V_58 ) )
F_47 ( V_22 , F_48 ( 0 ) ) ;
continue;
}
if ( F_72 ( * V_22 ) ) {
if ( ! F_73 ( * V_22 ) ) {
V_25 = F_27 ( V_22 , 0 ) ;
V_54 = F_62 ( V_25 , V_51 , V_5 ,
V_62 , V_34 ) ;
F_74 () ;
continue;
}
if ( V_62 & ( 1 << V_70 ) ) {
if ( ! V_16 )
V_52 ++ ;
V_54 = V_53 ;
continue;
}
V_34 = F_67 ( F_68 ( * ( T_7 * ) V_22 ) ) ;
}
if ( V_62 & ( 1 << V_70 ) ) {
V_52 ++ ;
F_5 ( & V_23 . V_14 ) ;
F_34 ( ( T_7 * ) V_22 ,
F_60 ( ( V_51 & V_68 ) >> V_48 ,
V_35 ) ) ;
F_14 ( & V_23 . V_14 ) ;
V_54 = V_53 ;
continue;
}
V_25 = F_70 () ;
V_54 = F_62 ( V_25 , V_51 , V_5 , V_62 ,
V_34 ) ;
F_5 ( & V_23 . V_14 ) ;
F_26 ( & V_23 , V_22 , V_25 ) ;
F_14 ( & V_23 . V_14 ) ;
}
F_74 () ;
F_61 ( V_70 , V_52 ) ;
return V_54 ;
}
unsigned long T_9
F_75 ( unsigned long V_4 ,
unsigned long V_5 ,
unsigned long V_62 )
{
bool V_71 = false ;
unsigned long V_53 , V_54 = V_5 ;
unsigned long V_51 ;
V_4 = ( unsigned long ) F_44 ( V_4 ) ;
V_5 = ( unsigned long ) F_44 ( V_5 ) ;
V_51 = V_4 ;
for (; V_4 < V_5 ; V_4 = V_53 ) {
T_2 * V_12 = F_3 ( V_4 ) ;
T_5 * V_22 ;
V_53 = ( V_4 & V_72 ) + V_8 ;
if ( F_76 ( * V_12 ) ) {
V_22 = ( T_5 * ) F_11 ( * V_12 ) ;
V_54 = F_71 ( V_22 , F_46 ( V_4 ) ,
F_46 ( V_5 ) , V_62 ) ;
continue;
}
V_22 = F_70 () ;
V_54 = F_71 ( V_22 , F_46 ( V_4 ) , F_46 ( V_5 ) ,
V_62 ) ;
F_5 ( & V_23 . V_14 ) ;
F_21 ( & V_23 , V_12 , V_22 ) ;
F_14 ( & V_23 . V_14 ) ;
V_71 = true ;
}
if ( V_71 )
F_2 ( V_51 , V_5 - 1 , 0 ) ;
F_74 () ;
return V_54 ;
}
void T_1 F_77 ( void )
{
F_78 ( 0 , ( V_73 ) V_74 , & V_75 . V_76 , 0 ) ;
}
void T_1 F_79 ( void )
{
F_80 ( V_77 ) ;
F_81 () ;
F_82 ( 0 , V_78 ) ;
if ( V_78 != V_79 )
F_82 ( 0 , V_79 ) ;
F_83 () ;
}
static void F_84 ( T_10 V_4 , T_10 V_31 )
{
unsigned long V_80 = F_85 ( V_4 + V_31 ) ;
if ( V_80 > V_81 ) {
V_81 = V_80 ;
V_82 = V_80 ;
V_83 = ( void * ) F_44 ( V_81 * V_19 - 1 ) + 1 ;
}
}
int F_86 ( int V_84 , T_10 V_4 , T_10 V_31 , bool V_85 )
{
struct V_86 * V_87 = F_87 ( V_84 ) ;
struct V_88 * V_88 = V_87 -> V_89 +
F_88 ( V_84 , V_4 , V_31 , V_90 , V_85 ) ;
unsigned long V_91 = V_4 >> V_48 ;
unsigned long V_92 = V_31 >> V_48 ;
int V_93 ;
F_89 ( V_4 , V_4 + V_31 ) ;
V_93 = F_90 ( V_84 , V_88 , V_91 , V_92 ) ;
F_91 ( V_93 ) ;
F_84 ( V_4 , V_31 ) ;
return V_93 ;
}
static void T_9 F_92 ( struct V_10 * V_10 , int V_94 )
{
unsigned long V_95 ;
unsigned int V_92 = 1 << V_94 ;
struct V_96 * V_97 = F_93 ( ( unsigned long ) V_10 ) ;
if ( V_97 ) {
F_94 ( V_97 , V_92 ) ;
return;
}
if ( F_95 ( V_10 ) ) {
F_96 ( V_10 ) ;
V_95 = ( unsigned long ) V_10 -> V_98 . V_53 ;
if ( V_95 == V_99 || V_95 == V_100 ) {
while ( V_92 -- )
F_97 ( V_10 ++ ) ;
} else
while ( V_92 -- )
F_98 ( V_10 ++ ) ;
} else
F_99 ( ( unsigned long ) F_7 ( V_10 ) , V_94 ) ;
}
static void T_9 F_100 ( T_7 * V_101 , T_6 * V_25 )
{
T_7 * V_26 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
V_26 = V_101 + V_55 ;
if ( F_59 ( * V_26 ) )
return;
}
F_92 ( V_61 ( * V_25 ) , 0 ) ;
F_5 ( & V_23 . V_14 ) ;
F_101 ( V_25 ) ;
F_14 ( & V_23 . V_14 ) ;
}
static void T_9 F_102 ( T_6 * V_102 , T_5 * V_22 )
{
T_6 * V_25 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_63 ; V_55 ++ ) {
V_25 = V_102 + V_55 ;
if ( F_64 ( * V_25 ) )
return;
}
F_92 ( V_27 ( * V_22 ) , 0 ) ;
F_5 ( & V_23 . V_14 ) ;
F_103 ( V_22 ) ;
F_14 ( & V_23 . V_14 ) ;
}
static bool T_9 F_104 ( T_5 * V_103 , T_2 * V_12 )
{
T_5 * V_22 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_67 ; V_55 ++ ) {
V_22 = V_103 + V_55 ;
if ( F_72 ( * V_22 ) )
return false ;
}
F_92 ( F_105 ( * V_12 ) , 0 ) ;
F_5 ( & V_23 . V_14 ) ;
F_12 ( V_12 ) ;
F_14 ( & V_23 . V_14 ) ;
return true ;
}
static void T_9
F_106 ( T_7 * V_101 , unsigned long V_51 , unsigned long V_5 ,
bool V_104 )
{
unsigned long V_53 , V_52 = 0 ;
T_7 * V_26 ;
void * V_105 ;
V_73 V_106 ;
V_26 = V_101 + F_56 ( V_51 ) ;
for (; V_51 < V_5 ; V_51 = V_53 , V_26 ++ ) {
V_53 = ( V_51 + V_19 ) & V_20 ;
if ( V_53 > V_5 )
V_53 = V_5 ;
if ( ! F_107 ( * V_26 ) )
continue;
V_106 = F_59 ( * V_26 ) + ( V_51 & V_20 ) ;
if ( V_106 < ( V_73 ) 0x40000000 )
return;
if ( F_108 ( V_51 ) && F_108 ( V_53 ) ) {
if ( ! V_104 )
F_92 ( V_50 ( * V_26 ) , 0 ) ;
F_5 ( & V_23 . V_14 ) ;
F_109 ( & V_23 , V_51 , V_26 ) ;
F_14 ( & V_23 . V_14 ) ;
V_52 ++ ;
} else {
memset ( ( void * ) V_51 , V_107 , V_53 - V_51 ) ;
V_105 = F_7 ( V_50 ( * V_26 ) ) ;
if ( ! F_110 ( V_105 , V_107 , V_19 ) ) {
F_92 ( V_50 ( * V_26 ) , 0 ) ;
F_5 ( & V_23 . V_14 ) ;
F_109 ( & V_23 , V_51 , V_26 ) ;
F_14 ( & V_23 . V_14 ) ;
}
}
}
F_111 () ;
if ( V_104 )
F_61 ( V_60 , - V_52 ) ;
}
static void T_9
F_112 ( T_6 * V_102 , unsigned long V_51 , unsigned long V_5 ,
bool V_104 )
{
unsigned long V_53 , V_52 = 0 ;
T_7 * V_108 ;
T_6 * V_25 ;
void * V_105 ;
V_25 = V_102 + F_63 ( V_51 ) ;
for (; V_51 < V_5 ; V_51 = V_53 , V_25 ++ ) {
V_53 = F_113 ( V_51 , V_5 ) ;
if ( ! F_114 ( * V_25 ) )
continue;
if ( F_65 ( * V_25 ) ) {
if ( F_115 ( V_51 , V_37 ) &&
F_115 ( V_53 , V_37 ) ) {
if ( ! V_104 )
F_92 ( V_61 ( * V_25 ) ,
F_116 ( V_37 ) ) ;
F_5 ( & V_23 . V_14 ) ;
F_101 ( V_25 ) ;
F_14 ( & V_23 . V_14 ) ;
V_52 ++ ;
} else {
memset ( ( void * ) V_51 , V_107 , V_53 - V_51 ) ;
V_105 = F_7 ( V_61 ( * V_25 ) ) ;
if ( ! F_110 ( V_105 , V_107 ,
V_37 ) ) {
F_92 ( V_61 ( * V_25 ) ,
F_116 ( V_37 ) ) ;
F_5 ( & V_23 . V_14 ) ;
F_101 ( V_25 ) ;
F_14 ( & V_23 . V_14 ) ;
}
}
continue;
}
V_108 = ( T_7 * ) F_66 ( * V_25 ) ;
F_106 ( V_108 , V_51 , V_53 , V_104 ) ;
F_100 ( V_108 , V_25 ) ;
}
if ( V_104 )
F_61 ( V_65 , - V_52 ) ;
}
static void T_9
F_117 ( T_5 * V_103 , unsigned long V_51 , unsigned long V_5 ,
bool V_104 )
{
unsigned long V_53 , V_52 = 0 ;
T_6 * V_109 ;
T_5 * V_22 ;
void * V_105 ;
V_22 = V_103 + F_33 ( V_51 ) ;
for (; V_51 < V_5 ; V_51 = V_53 , V_22 ++ ) {
V_53 = F_118 ( V_51 , V_5 ) ;
if ( ! F_119 ( * V_22 ) )
continue;
if ( F_73 ( * V_22 ) ) {
if ( F_115 ( V_51 , V_69 ) &&
F_115 ( V_53 , V_69 ) ) {
if ( ! V_104 )
F_92 ( V_27 ( * V_22 ) ,
F_116 ( V_69 ) ) ;
F_5 ( & V_23 . V_14 ) ;
F_103 ( V_22 ) ;
F_14 ( & V_23 . V_14 ) ;
V_52 ++ ;
} else {
memset ( ( void * ) V_51 , V_107 , V_53 - V_51 ) ;
V_105 = F_7 ( V_27 ( * V_22 ) ) ;
if ( ! F_110 ( V_105 , V_107 ,
V_69 ) ) {
F_92 ( V_27 ( * V_22 ) ,
F_116 ( V_69 ) ) ;
F_5 ( & V_23 . V_14 ) ;
F_103 ( V_22 ) ;
F_14 ( & V_23 . V_14 ) ;
}
}
continue;
}
V_109 = ( T_6 * ) F_120 ( * V_22 ) ;
F_112 ( V_109 , V_51 , V_53 , V_104 ) ;
F_102 ( V_109 , V_22 ) ;
}
if ( V_104 )
F_61 ( V_70 , - V_52 ) ;
}
static void T_9
F_121 ( unsigned long V_4 , unsigned long V_5 , bool V_104 )
{
unsigned long V_53 ;
unsigned long V_51 ;
T_2 * V_12 ;
T_5 * V_22 ;
bool V_71 = false ;
for ( V_51 = V_4 ; V_51 < V_5 ; V_51 = V_53 ) {
V_53 = F_122 ( V_51 , V_5 ) ;
V_12 = F_3 ( V_51 ) ;
if ( ! F_123 ( * V_12 ) )
continue;
V_22 = ( T_5 * ) F_11 ( * V_12 ) ;
F_117 ( V_22 , V_51 , V_53 , V_104 ) ;
if ( F_104 ( V_22 , V_12 ) )
V_71 = true ;
}
if ( V_71 )
F_2 ( V_4 , V_5 - 1 , 1 ) ;
F_111 () ;
}
void T_4 F_124 ( unsigned long V_4 , unsigned long V_5 )
{
F_121 ( V_4 , V_5 , false ) ;
}
static void T_9
F_125 ( unsigned long V_4 , unsigned long V_5 )
{
V_4 = ( unsigned long ) F_44 ( V_4 ) ;
V_5 = ( unsigned long ) F_44 ( V_5 ) ;
F_121 ( V_4 , V_5 , true ) ;
}
int T_4 F_126 ( T_10 V_4 , T_10 V_31 )
{
unsigned long V_91 = V_4 >> V_48 ;
unsigned long V_92 = V_31 >> V_48 ;
struct V_10 * V_10 = F_127 ( V_91 ) ;
struct V_96 * V_97 ;
struct V_88 * V_88 ;
int V_93 ;
V_97 = F_93 ( ( unsigned long ) V_10 ) ;
if ( V_97 )
V_10 += F_128 ( V_97 ) ;
V_88 = F_129 ( V_10 ) ;
V_93 = F_130 ( V_88 , V_91 , V_92 ) ;
F_91 ( V_93 ) ;
F_125 ( V_4 , V_4 + V_31 ) ;
return V_93 ;
}
static void T_1 F_131 ( void )
{
#ifdef F_132
int V_55 ;
F_133 (i)
F_134 ( F_87 ( V_55 ) ) ;
#endif
}
void T_1 F_135 ( void )
{
F_136 () ;
F_131 () ;
F_137 () ;
V_16 = 1 ;
F_138 ( & V_110 , ( void * ) V_111 ,
V_19 , V_112 ) ;
F_139 ( NULL ) ;
}
void F_140 ( void )
{
unsigned long V_4 = F_141 ( V_49 ) ;
unsigned long V_5 = F_141 ( V_113 ) ;
if ( ! V_114 )
return;
F_19 ( L_13 ,
V_4 , V_5 ) ;
F_142 ( V_4 , ( V_5 - V_4 ) >> V_48 ) ;
}
void F_143 ( void )
{
unsigned long V_4 = F_141 ( V_49 ) ;
unsigned long V_5 = F_141 ( V_113 ) ;
if ( ! V_114 )
return;
F_19 ( L_14 ,
V_4 , V_5 ) ;
F_144 ( V_4 , ( V_5 - V_4 ) >> V_48 ) ;
}
void F_145 ( void )
{
unsigned long V_4 = F_141 ( V_49 ) ;
unsigned long V_115 = F_141 ( V_116 ) ;
unsigned long V_5 = ( unsigned long ) & V_117 ;
unsigned long V_118 = F_141 ( & V_113 ) ;
unsigned long V_119 = F_141 ( & V_120 ) ;
unsigned long V_121 ;
F_23 ( V_122 L_15 ,
( V_5 - V_4 ) >> 10 ) ;
F_144 ( V_4 , ( V_5 - V_4 ) >> V_48 ) ;
V_114 = 1 ;
V_121 = F_54 ( ( unsigned long ) V_45 , V_37 ) ;
F_146 ( V_118 , ( V_121 - V_118 ) >> V_48 ) ;
F_147 () ;
#ifdef F_148
F_23 ( V_122 L_16 , V_4 , V_5 ) ;
F_142 ( V_4 , ( V_5 - V_4 ) >> V_48 ) ;
F_23 ( V_122 L_17 ) ;
F_144 ( V_4 , ( V_5 - V_4 ) >> V_48 ) ;
#endif
F_149 ( L_18 ,
( unsigned long ) F_44 ( F_150 ( V_118 ) ) ,
( unsigned long ) F_44 ( F_150 ( V_115 ) ) ) ;
F_149 ( L_18 ,
( unsigned long ) F_44 ( F_150 ( V_119 ) ) ,
( unsigned long ) F_44 ( F_150 ( V_123 ) ) ) ;
F_151 () ;
}
int F_152 ( unsigned long V_51 )
{
unsigned long V_124 = ( ( long ) V_51 ) >> V_125 ;
T_2 * V_12 ;
T_5 * V_22 ;
T_6 * V_25 ;
T_7 * V_26 ;
if ( V_124 != 0 && V_124 != - 1UL )
return 0 ;
V_12 = F_3 ( V_51 ) ;
if ( F_4 ( * V_12 ) )
return 0 ;
V_22 = F_22 ( V_12 , V_51 ) ;
if ( F_25 ( * V_22 ) )
return 0 ;
if ( F_73 ( * V_22 ) )
return F_153 ( F_154 ( * V_22 ) ) ;
V_25 = F_27 ( V_22 , V_51 ) ;
if ( F_29 ( * V_25 ) )
return 0 ;
if ( F_65 ( * V_25 ) )
return F_153 ( F_155 ( * V_25 ) ) ;
V_26 = F_31 ( V_25 , V_51 ) ;
if ( F_156 ( * V_26 ) )
return 0 ;
return F_153 ( F_157 ( * V_26 ) ) ;
}
static unsigned long F_158 ( void )
{
unsigned long V_126 = V_127 ;
if ( F_159 () || ( ( V_81 << V_48 ) >= ( 64UL << 30 ) ) )
V_126 = 2UL << 30 ;
F_160 ( L_19 , V_126 >> 20 ) ;
return V_126 ;
}
unsigned long F_161 ( void )
{
if ( ! V_128 )
V_128 = F_158 () ;
return V_128 ;
}
static int T_9 F_162 ( unsigned long V_4 ,
unsigned long V_5 , int V_129 , struct V_96 * V_97 )
{
unsigned long V_51 ;
unsigned long V_53 ;
T_2 * V_12 ;
T_5 * V_22 ;
T_6 * V_25 ;
for ( V_51 = V_4 ; V_51 < V_5 ; V_51 = V_53 ) {
V_53 = F_113 ( V_51 , V_5 ) ;
V_12 = F_163 ( V_51 , V_129 ) ;
if ( ! V_12 )
return - V_130 ;
V_22 = F_164 ( V_12 , V_51 , V_129 ) ;
if ( ! V_22 )
return - V_130 ;
V_25 = F_27 ( V_22 , V_51 ) ;
if ( F_29 ( * V_25 ) ) {
void * V_131 ;
V_131 = F_165 ( V_37 , V_129 , V_97 ) ;
if ( V_131 ) {
T_7 V_132 ;
V_132 = F_60 ( F_46 ( V_131 ) >> V_48 ,
V_35 ) ;
F_49 ( V_25 , F_50 ( F_59 ( V_132 ) ) ) ;
if ( V_133 != V_131 || V_134 != V_129 ) {
if ( V_135 )
F_19 ( L_20 ,
V_136 , V_137 - 1 , V_135 , V_133 - 1 , V_134 ) ;
V_136 = V_51 ;
V_134 = V_129 ;
V_135 = V_131 ;
}
V_137 = V_51 + V_37 ;
V_133 = V_131 + V_37 ;
continue;
} else if ( V_97 )
return - V_130 ;
} else if ( F_65 ( * V_25 ) ) {
F_166 ( ( T_7 * ) V_25 , V_129 , V_51 , V_53 ) ;
continue;
}
F_167 ( L_21 ) ;
if ( F_168 ( V_51 , V_53 , V_129 ) )
return - V_130 ;
}
return 0 ;
}
int T_9 F_169 ( unsigned long V_4 , unsigned long V_5 , int V_129 )
{
struct V_96 * V_97 = F_93 ( V_4 ) ;
int V_138 ;
if ( F_170 ( V_139 ) )
V_138 = F_162 ( V_4 , V_5 , V_129 , V_97 ) ;
else if ( V_97 ) {
F_171 ( L_22 ,
V_140 ) ;
V_138 = - V_130 ;
} else
V_138 = F_168 ( V_4 , V_5 , V_129 ) ;
if ( ! V_138 )
F_2 ( V_4 , V_5 - 1 , 0 ) ;
return V_138 ;
}
void F_172 ( unsigned long V_141 ,
struct V_10 * V_142 , unsigned long V_31 )
{
unsigned long V_51 = ( unsigned long ) V_142 ;
unsigned long V_5 = ( unsigned long ) ( V_142 + V_31 ) ;
unsigned long V_53 ;
T_2 * V_12 ;
T_5 * V_22 ;
T_6 * V_25 ;
unsigned int V_92 ;
struct V_10 * V_10 ;
for (; V_51 < V_5 ; V_51 = V_53 ) {
T_7 * V_26 = NULL ;
V_12 = F_3 ( V_51 ) ;
if ( F_4 ( * V_12 ) ) {
V_53 = ( V_51 + V_19 ) & V_20 ;
continue;
}
F_173 ( V_141 , F_105 ( * V_12 ) , V_100 ) ;
V_22 = F_22 ( V_12 , V_51 ) ;
if ( F_25 ( * V_22 ) ) {
V_53 = ( V_51 + V_19 ) & V_20 ;
continue;
}
F_173 ( V_141 , V_27 ( * V_22 ) , V_100 ) ;
if ( ! F_170 ( V_139 ) ) {
V_53 = ( V_51 + V_19 ) & V_20 ;
V_25 = F_27 ( V_22 , V_51 ) ;
if ( F_29 ( * V_25 ) )
continue;
F_173 ( V_141 , V_61 ( * V_25 ) ,
V_100 ) ;
V_26 = F_31 ( V_25 , V_51 ) ;
if ( F_156 ( * V_26 ) )
continue;
F_173 ( V_141 , V_50 ( * V_26 ) ,
V_99 ) ;
} else {
V_53 = F_113 ( V_51 , V_5 ) ;
V_25 = F_27 ( V_22 , V_51 ) ;
if ( F_29 ( * V_25 ) )
continue;
V_92 = 1 << ( F_116 ( V_37 ) ) ;
V_10 = V_61 ( * V_25 ) ;
while ( V_92 -- )
F_173 ( V_141 , V_10 ++ ,
V_99 ) ;
}
}
}
void T_9 F_174 ( void )
{
if ( V_135 ) {
F_19 ( L_20 ,
V_136 , V_137 - 1 , V_135 , V_133 - 1 , V_134 ) ;
V_135 = NULL ;
V_133 = NULL ;
V_134 = 0 ;
}
}
