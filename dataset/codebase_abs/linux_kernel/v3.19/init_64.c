static void F_1 ( unsigned long V_1 , T_1 * V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
V_3 &= V_5 ;
for (; V_3 < V_4 ; V_3 += V_6 ) {
T_1 * V_7 = V_2 + F_2 ( V_3 ) ;
if ( ! F_3 ( * V_7 ) )
F_4 ( V_7 , F_5 ( V_3 | V_1 ) ) ;
}
}
static int F_6 ( struct V_8 * V_9 , T_2 * V_10 ,
unsigned long V_3 , unsigned long V_4 )
{
unsigned long V_11 ;
for (; V_3 < V_4 ; V_3 = V_11 ) {
T_2 * V_12 = V_10 + F_7 ( V_3 ) ;
T_1 * V_7 ;
V_11 = ( V_3 & V_13 ) + V_14 ;
if ( V_11 > V_4 )
V_11 = V_4 ;
if ( F_8 ( * V_12 ) ) {
V_7 = F_9 ( V_12 , 0 ) ;
F_1 ( V_9 -> V_1 , V_7 , V_3 , V_11 ) ;
continue;
}
V_7 = ( T_1 * ) V_9 -> V_15 ( V_9 -> V_16 ) ;
if ( ! V_7 )
return - V_17 ;
F_1 ( V_9 -> V_1 , V_7 , V_3 , V_11 ) ;
F_10 ( V_12 , F_11 ( F_12 ( V_7 ) | V_18 ) ) ;
}
return 0 ;
}
int F_13 ( struct V_8 * V_9 , T_3 * V_19 ,
unsigned long V_3 , unsigned long V_4 )
{
unsigned long V_11 ;
int V_20 ;
int V_21 = V_9 -> V_22 ? F_14 ( V_23 ) : 0 ;
for (; V_3 < V_4 ; V_3 = V_11 ) {
T_3 * V_24 = V_19 + F_14 ( V_3 ) + V_21 ;
T_2 * V_12 ;
V_11 = ( V_3 & V_25 ) + V_26 ;
if ( V_11 > V_4 )
V_11 = V_4 ;
if ( F_15 ( * V_24 ) ) {
V_12 = F_16 ( V_24 , 0 ) ;
V_20 = F_6 ( V_9 , V_12 , V_3 , V_11 ) ;
if ( V_20 )
return V_20 ;
continue;
}
V_12 = ( T_2 * ) V_9 -> V_15 ( V_9 -> V_16 ) ;
if ( ! V_12 )
return - V_17 ;
V_20 = F_6 ( V_9 , V_12 , V_3 , V_11 ) ;
if ( V_20 )
return V_20 ;
F_17 ( V_24 , F_18 ( F_12 ( V_12 ) | V_18 ) ) ;
}
return 0 ;
}
static int T_4 F_19 ( char * V_27 )
{
V_28 = 0 ;
return 0 ;
}
static int T_4 F_20 ( char * V_27 )
{
V_28 = 1 ;
return 0 ;
}
static int T_4 F_21 ( char * V_29 )
{
if ( ! strcmp ( V_29 , L_1 ) )
V_30 &= ~ V_31 ;
else if ( ! strcmp ( V_29 , L_2 ) )
V_30 |= V_31 ;
return 1 ;
}
void F_22 ( unsigned long V_32 , unsigned long V_4 , int V_33 )
{
unsigned long V_34 ;
for ( V_34 = V_32 ; V_34 <= V_4 ; V_34 += V_26 ) {
const T_3 * V_35 = F_23 ( V_34 ) ;
struct V_36 * V_36 ;
if ( F_24 ( * V_35 ) && ! V_33 )
continue;
F_25 ( & V_37 ) ;
F_26 (page, &pgd_list, lru) {
T_3 * V_24 ;
T_5 * V_38 ;
V_24 = ( T_3 * ) F_27 ( V_36 ) + F_14 ( V_34 ) ;
V_38 = & F_28 ( V_36 ) -> V_39 ;
F_25 ( V_38 ) ;
if ( ! F_24 ( * V_35 ) && ! F_24 ( * V_24 ) )
F_29 ( F_30 ( * V_24 )
!= F_30 ( * V_35 ) ) ;
if ( V_33 ) {
if ( F_24 ( * V_35 ) && ! F_24 ( * V_24 ) )
F_31 ( V_24 ) ;
} else {
if ( F_24 ( * V_24 ) )
F_17 ( V_24 , * V_35 ) ;
}
F_32 ( V_38 ) ;
}
F_32 ( & V_37 ) ;
}
}
static T_6 void * F_33 ( void )
{
void * V_40 ;
if ( V_41 )
V_40 = ( void * ) F_34 ( V_42 | V_43 ) ;
else
V_40 = F_35 ( V_44 ) ;
if ( ! V_40 || ( ( unsigned long ) V_40 & ~ V_45 ) ) {
F_36 ( L_3 ,
V_41 ? L_4 : L_5 ) ;
}
F_37 ( L_6 , V_40 ) ;
return V_40 ;
}
static T_2 * F_38 ( T_3 * V_24 , unsigned long V_46 )
{
if ( F_24 ( * V_24 ) ) {
T_2 * V_12 = ( T_2 * ) F_33 () ;
F_39 ( & V_47 , V_24 , V_12 ) ;
if ( V_12 != F_16 ( V_24 , 0 ) )
F_40 ( V_48 L_7 ,
V_12 , F_16 ( V_24 , 0 ) ) ;
}
return F_16 ( V_24 , V_46 ) ;
}
static T_1 * F_41 ( T_2 * V_12 , unsigned long V_46 )
{
if ( F_42 ( * V_12 ) ) {
T_1 * V_7 = ( T_1 * ) F_33 () ;
F_43 ( & V_47 , V_12 , V_7 ) ;
if ( V_7 != F_9 ( V_12 , 0 ) )
F_40 ( V_48 L_8 ,
V_7 , F_9 ( V_12 , 0 ) ) ;
}
return F_9 ( V_12 , V_46 ) ;
}
static T_7 * F_44 ( T_1 * V_7 , unsigned long V_46 )
{
if ( F_45 ( * V_7 ) ) {
T_7 * V_49 = ( T_7 * ) F_33 () ;
F_46 ( & V_47 , V_7 , V_49 ) ;
if ( V_49 != F_47 ( V_7 , 0 ) )
F_40 ( V_48 L_9 ) ;
}
return F_47 ( V_7 , V_46 ) ;
}
void F_48 ( T_2 * V_10 , unsigned long V_46 , T_7 V_50 )
{
T_2 * V_12 ;
T_1 * V_7 ;
T_7 * V_49 ;
V_12 = V_10 + F_7 ( V_46 ) ;
V_7 = F_41 ( V_12 , V_46 ) ;
V_49 = F_44 ( V_7 , V_46 ) ;
F_49 ( V_49 , V_50 ) ;
F_50 ( V_46 ) ;
}
void F_51 ( unsigned long V_46 , T_7 V_51 )
{
T_3 * V_24 ;
T_2 * V_10 ;
F_37 ( L_10 , V_46 , F_52 ( V_51 ) ) ;
V_24 = F_23 ( V_46 ) ;
if ( F_24 ( * V_24 ) ) {
F_40 ( V_48
L_11 ) ;
return;
}
V_10 = ( T_2 * ) F_30 ( * V_24 ) ;
F_48 ( V_10 , V_46 , V_51 ) ;
}
T_1 * T_4 F_53 ( unsigned long V_46 )
{
T_3 * V_24 ;
T_2 * V_12 ;
V_24 = F_23 ( V_46 ) ;
V_12 = F_38 ( V_24 , V_46 ) ;
return F_41 ( V_12 , V_46 ) ;
}
T_7 * T_4 F_54 ( unsigned long V_46 )
{
T_1 * V_7 ;
V_7 = F_53 ( V_46 ) ;
return F_44 ( V_7 , V_46 ) ;
}
static void T_4 F_55 ( unsigned long V_52 , unsigned long V_53 ,
enum V_54 V_55 )
{
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
T_8 V_56 ;
F_56 ( V_56 ) = F_56 ( V_57 ) |
F_56 ( F_57 ( F_58 ( V_55 ) ) ) ;
F_29 ( ( V_52 & ~ V_5 ) || ( V_53 & ~ V_5 ) ) ;
for (; V_53 ; V_52 += V_6 , V_53 -= V_6 ) {
V_24 = F_23 ( ( unsigned long ) F_59 ( V_52 ) ) ;
if ( F_24 ( * V_24 ) ) {
V_12 = ( T_2 * ) F_33 () ;
F_17 ( V_24 , F_18 ( F_12 ( V_12 ) | V_18 |
V_58 ) ) ;
}
V_12 = F_16 ( V_24 , ( unsigned long ) F_59 ( V_52 ) ) ;
if ( F_42 ( * V_12 ) ) {
V_7 = ( T_1 * ) F_33 () ;
F_10 ( V_12 , F_11 ( F_12 ( V_7 ) | V_18 |
V_58 ) ) ;
}
V_7 = F_9 ( V_12 , V_52 ) ;
F_29 ( ! F_45 ( * V_7 ) ) ;
F_4 ( V_7 , F_5 ( V_52 | F_56 ( V_56 ) ) ) ;
}
}
void T_4 F_60 ( unsigned long V_52 , unsigned long V_53 )
{
F_55 ( V_52 , V_53 , V_59 ) ;
}
void T_4 F_61 ( unsigned long V_52 , unsigned long V_53 )
{
F_55 ( V_52 , V_53 , V_60 ) ;
}
void T_4 F_62 ( void )
{
unsigned long V_46 = V_61 ;
unsigned long V_62 = V_61 + V_63 ;
unsigned long V_4 = F_63 ( ( unsigned long ) V_64 , V_6 ) - 1 ;
T_1 * V_7 = V_65 ;
if ( V_66 )
V_62 = V_61 + ( V_66 << V_67 ) ;
for (; V_46 + V_6 - 1 < V_62 ; V_7 ++ , V_46 += V_6 ) {
if ( F_45 ( * V_7 ) )
continue;
if ( V_46 < ( unsigned long ) V_68 || V_46 > V_4 )
F_4 ( V_7 , F_5 ( 0 ) ) ;
}
}
static unsigned long T_9
F_64 ( T_7 * V_69 , unsigned long V_3 , unsigned long V_4 ,
T_8 V_56 )
{
unsigned long V_70 = 0 , V_11 ;
unsigned long V_71 = V_4 ;
int V_72 ;
T_7 * V_49 = V_69 + F_65 ( V_3 ) ;
for ( V_72 = F_65 ( V_3 ) ; V_72 < V_73 ; V_72 ++ , V_3 = V_11 , V_49 ++ ) {
V_11 = ( V_3 & V_45 ) + V_44 ;
if ( V_3 >= V_4 ) {
if ( ! V_41 &&
! F_66 ( V_3 & V_45 , V_11 , V_74 ) &&
! F_66 ( V_3 & V_45 , V_11 , V_75 ) )
F_49 ( V_49 , F_67 ( 0 ) ) ;
continue;
}
if ( F_68 ( * V_49 ) ) {
if ( ! V_41 )
V_70 ++ ;
continue;
}
if ( 0 )
F_40 ( L_12 ,
V_49 , V_3 , F_69 ( V_3 >> V_67 , V_76 ) . V_49 ) ;
V_70 ++ ;
F_49 ( V_49 , F_69 ( V_3 >> V_67 , V_56 ) ) ;
V_71 = ( V_3 & V_45 ) + V_44 ;
}
F_70 ( V_77 , V_70 ) ;
return V_71 ;
}
static unsigned long T_9
F_71 ( T_1 * V_2 , unsigned long V_34 , unsigned long V_4 ,
unsigned long V_78 , T_8 V_56 )
{
unsigned long V_70 = 0 , V_11 ;
unsigned long V_71 = V_4 ;
int V_72 = F_2 ( V_34 ) ;
for (; V_72 < V_79 ; V_72 ++ , V_34 = V_11 ) {
T_1 * V_7 = V_2 + F_2 ( V_34 ) ;
T_7 * V_49 ;
T_8 V_80 = V_56 ;
V_11 = ( V_34 & V_5 ) + V_6 ;
if ( V_34 >= V_4 ) {
if ( ! V_41 &&
! F_66 ( V_34 & V_5 , V_11 , V_74 ) &&
! F_66 ( V_34 & V_5 , V_11 , V_75 ) )
F_4 ( V_7 , F_5 ( 0 ) ) ;
continue;
}
if ( F_72 ( * V_7 ) ) {
if ( ! F_73 ( * V_7 ) ) {
F_25 ( & V_47 . V_39 ) ;
V_49 = ( T_7 * ) F_74 ( * V_7 ) ;
V_71 = F_64 ( V_49 , V_34 ,
V_4 , V_56 ) ;
F_32 ( & V_47 . V_39 ) ;
continue;
}
if ( V_78 & ( 1 << V_81 ) ) {
if ( ! V_41 )
V_70 ++ ;
V_71 = V_11 ;
continue;
}
V_80 = F_75 ( F_76 ( * ( T_7 * ) V_7 ) ) ;
}
if ( V_78 & ( 1 << V_81 ) ) {
V_70 ++ ;
F_25 ( & V_47 . V_39 ) ;
F_49 ( ( T_7 * ) V_7 ,
F_69 ( ( V_34 & V_5 ) >> V_67 ,
F_77 ( F_56 ( V_56 ) | V_82 ) ) ) ;
F_32 ( & V_47 . V_39 ) ;
V_71 = V_11 ;
continue;
}
V_49 = F_78 () ;
V_71 = F_64 ( V_49 , V_34 , V_4 , V_80 ) ;
F_25 ( & V_47 . V_39 ) ;
F_46 ( & V_47 , V_7 , V_49 ) ;
F_32 ( & V_47 . V_39 ) ;
}
F_70 ( V_81 , V_70 ) ;
return V_71 ;
}
static unsigned long T_9
F_79 ( T_2 * V_10 , unsigned long V_3 , unsigned long V_4 ,
unsigned long V_78 )
{
unsigned long V_70 = 0 , V_11 ;
unsigned long V_71 = V_4 ;
int V_72 = F_7 ( V_3 ) ;
for (; V_72 < V_83 ; V_72 ++ , V_3 = V_11 ) {
T_2 * V_12 = V_10 + F_7 ( V_3 ) ;
T_1 * V_7 ;
T_8 V_56 = V_76 ;
V_11 = ( V_3 & V_13 ) + V_14 ;
if ( V_3 >= V_4 ) {
if ( ! V_41 &&
! F_66 ( V_3 & V_13 , V_11 , V_74 ) &&
! F_66 ( V_3 & V_13 , V_11 , V_75 ) )
F_10 ( V_12 , F_11 ( 0 ) ) ;
continue;
}
if ( F_80 ( * V_12 ) ) {
if ( ! F_81 ( * V_12 ) ) {
V_7 = F_9 ( V_12 , 0 ) ;
V_71 = F_71 ( V_7 , V_3 , V_4 ,
V_78 , V_56 ) ;
F_82 () ;
continue;
}
if ( V_78 & ( 1 << V_84 ) ) {
if ( ! V_41 )
V_70 ++ ;
V_71 = V_11 ;
continue;
}
V_56 = F_75 ( F_76 ( * ( T_7 * ) V_12 ) ) ;
}
if ( V_78 & ( 1 << V_84 ) ) {
V_70 ++ ;
F_25 ( & V_47 . V_39 ) ;
F_49 ( ( T_7 * ) V_12 ,
F_69 ( ( V_3 & V_13 ) >> V_67 ,
V_57 ) ) ;
F_32 ( & V_47 . V_39 ) ;
V_71 = V_11 ;
continue;
}
V_7 = F_78 () ;
V_71 = F_71 ( V_7 , V_3 , V_4 , V_78 ,
V_56 ) ;
F_25 ( & V_47 . V_39 ) ;
F_43 ( & V_47 , V_12 , V_7 ) ;
F_32 ( & V_47 . V_39 ) ;
}
F_82 () ;
F_70 ( V_84 , V_70 ) ;
return V_71 ;
}
unsigned long T_9
F_83 ( unsigned long V_32 ,
unsigned long V_4 ,
unsigned long V_78 )
{
bool V_85 = false ;
unsigned long V_11 , V_71 = V_4 ;
unsigned long V_3 ;
V_32 = ( unsigned long ) F_59 ( V_32 ) ;
V_4 = ( unsigned long ) F_59 ( V_4 ) ;
V_3 = V_32 ;
for (; V_32 < V_4 ; V_32 = V_11 ) {
T_3 * V_24 = F_23 ( V_32 ) ;
T_2 * V_12 ;
V_11 = ( V_32 & V_25 ) + V_26 ;
if ( F_84 ( * V_24 ) ) {
V_12 = ( T_2 * ) F_30 ( * V_24 ) ;
V_71 = F_79 ( V_12 , F_12 ( V_32 ) ,
F_12 ( V_4 ) , V_78 ) ;
continue;
}
V_12 = F_78 () ;
V_71 = F_79 ( V_12 , F_12 ( V_32 ) , F_12 ( V_4 ) ,
V_78 ) ;
F_25 ( & V_47 . V_39 ) ;
F_39 ( & V_47 , V_24 , V_12 ) ;
F_32 ( & V_47 . V_39 ) ;
V_85 = true ;
}
if ( V_85 )
F_22 ( V_3 , V_4 - 1 , 0 ) ;
F_82 () ;
return V_71 ;
}
void T_4 F_85 ( void )
{
F_86 ( 0 , ( V_86 ) V_87 , & V_88 . V_89 , 0 ) ;
}
void T_4 F_87 ( void )
{
F_88 ( V_90 ) ;
F_89 () ;
F_90 ( 0 , V_91 ) ;
if ( V_91 != V_92 )
F_90 ( 0 , V_92 ) ;
F_91 () ;
}
static void F_92 ( T_10 V_32 , T_10 V_53 )
{
unsigned long V_93 = F_93 ( V_32 + V_53 ) ;
if ( V_93 > V_94 ) {
V_94 = V_93 ;
V_95 = V_93 ;
V_96 = ( void * ) F_59 ( V_94 * V_44 - 1 ) + 1 ;
}
}
int F_94 ( int V_97 , T_10 V_32 , T_10 V_53 )
{
struct V_98 * V_99 = F_95 ( V_97 ) ;
struct V_100 * V_100 = V_99 -> V_101 +
F_96 ( V_97 , V_32 , V_53 , V_102 ) ;
unsigned long V_103 = V_32 >> V_67 ;
unsigned long V_104 = V_53 >> V_67 ;
int V_105 ;
F_97 ( V_32 , V_32 + V_53 ) ;
V_105 = F_98 ( V_97 , V_100 , V_103 , V_104 ) ;
F_99 ( V_105 ) ;
F_92 ( V_32 , V_53 ) ;
return V_105 ;
}
static void T_9 F_100 ( struct V_36 * V_36 , int V_106 )
{
unsigned long V_107 ;
unsigned int V_104 = 1 << V_106 ;
if ( F_101 ( V_36 ) ) {
F_102 ( V_36 ) ;
V_107 = ( unsigned long ) V_36 -> V_108 . V_11 ;
if ( V_107 == V_109 || V_107 == V_110 ) {
while ( V_104 -- )
F_103 ( V_36 ++ ) ;
} else
while ( V_104 -- )
F_104 ( V_36 ++ ) ;
} else
F_105 ( ( unsigned long ) F_27 ( V_36 ) , V_106 ) ;
}
static void T_9 F_106 ( T_7 * V_111 , T_1 * V_7 )
{
T_7 * V_49 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
V_49 = V_111 + V_72 ;
if ( F_68 ( * V_49 ) )
return;
}
F_100 ( V_2 ( * V_7 ) , 0 ) ;
F_25 ( & V_47 . V_39 ) ;
F_107 ( V_7 ) ;
F_32 ( & V_47 . V_39 ) ;
}
static void T_9 F_108 ( T_1 * V_112 , T_2 * V_12 )
{
T_1 * V_7 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_79 ; V_72 ++ ) {
V_7 = V_112 + V_72 ;
if ( F_72 ( * V_7 ) )
return;
}
F_100 ( V_10 ( * V_12 ) , 0 ) ;
F_25 ( & V_47 . V_39 ) ;
F_109 ( V_12 ) ;
F_32 ( & V_47 . V_39 ) ;
}
static bool T_9 F_110 ( T_2 * V_113 , T_3 * V_24 )
{
T_2 * V_12 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_83 ; V_72 ++ ) {
V_12 = V_113 + V_72 ;
if ( F_80 ( * V_12 ) )
return false ;
}
F_100 ( V_19 ( * V_24 ) , 0 ) ;
F_25 ( & V_47 . V_39 ) ;
F_31 ( V_24 ) ;
F_32 ( & V_47 . V_39 ) ;
return true ;
}
static void T_9
F_111 ( T_7 * V_111 , unsigned long V_3 , unsigned long V_4 ,
bool V_114 )
{
unsigned long V_11 , V_70 = 0 ;
T_7 * V_49 ;
void * V_115 ;
V_86 V_116 ;
V_49 = V_111 + F_65 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_49 ++ ) {
V_11 = ( V_3 + V_44 ) & V_45 ;
if ( V_11 > V_4 )
V_11 = V_4 ;
if ( ! F_112 ( * V_49 ) )
continue;
V_116 = F_68 ( * V_49 ) + ( V_3 & V_45 ) ;
if ( V_116 < ( V_86 ) 0x40000000 )
return;
if ( F_113 ( V_3 , V_44 ) &&
F_113 ( V_11 , V_44 ) ) {
if ( ! V_114 )
F_100 ( V_69 ( * V_49 ) , 0 ) ;
F_25 ( & V_47 . V_39 ) ;
F_114 ( & V_47 , V_3 , V_49 ) ;
F_32 ( & V_47 . V_39 ) ;
V_70 ++ ;
} else {
memset ( ( void * ) V_3 , V_117 , V_11 - V_3 ) ;
V_115 = F_27 ( V_69 ( * V_49 ) ) ;
if ( ! F_115 ( V_115 , V_117 , V_44 ) ) {
F_100 ( V_69 ( * V_49 ) , 0 ) ;
F_25 ( & V_47 . V_39 ) ;
F_114 ( & V_47 , V_3 , V_49 ) ;
F_32 ( & V_47 . V_39 ) ;
}
}
}
F_116 () ;
if ( V_114 )
F_70 ( V_77 , - V_70 ) ;
}
static void T_9
F_117 ( T_1 * V_112 , unsigned long V_3 , unsigned long V_4 ,
bool V_114 )
{
unsigned long V_11 , V_70 = 0 ;
T_7 * V_118 ;
T_1 * V_7 ;
void * V_115 ;
V_7 = V_112 + F_2 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_7 ++ ) {
V_11 = F_118 ( V_3 , V_4 ) ;
if ( ! F_3 ( * V_7 ) )
continue;
if ( F_73 ( * V_7 ) ) {
if ( F_113 ( V_3 , V_6 ) &&
F_113 ( V_11 , V_6 ) ) {
if ( ! V_114 )
F_100 ( V_2 ( * V_7 ) ,
F_119 ( V_6 ) ) ;
F_25 ( & V_47 . V_39 ) ;
F_107 ( V_7 ) ;
F_32 ( & V_47 . V_39 ) ;
V_70 ++ ;
} else {
memset ( ( void * ) V_3 , V_117 , V_11 - V_3 ) ;
V_115 = F_27 ( V_2 ( * V_7 ) ) ;
if ( ! F_115 ( V_115 , V_117 ,
V_6 ) ) {
F_100 ( V_2 ( * V_7 ) ,
F_119 ( V_6 ) ) ;
F_25 ( & V_47 . V_39 ) ;
F_107 ( V_7 ) ;
F_32 ( & V_47 . V_39 ) ;
}
}
continue;
}
V_118 = ( T_7 * ) F_74 ( * V_7 ) ;
F_111 ( V_118 , V_3 , V_11 , V_114 ) ;
F_106 ( V_118 , V_7 ) ;
}
if ( V_114 )
F_70 ( V_81 , - V_70 ) ;
}
static void T_9
F_120 ( T_2 * V_113 , unsigned long V_3 , unsigned long V_4 ,
bool V_114 )
{
unsigned long V_11 , V_70 = 0 ;
T_1 * V_119 ;
T_2 * V_12 ;
void * V_115 ;
V_12 = V_113 + F_7 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_12 ++ ) {
V_11 = F_121 ( V_3 , V_4 ) ;
if ( ! F_8 ( * V_12 ) )
continue;
if ( F_81 ( * V_12 ) ) {
if ( F_113 ( V_3 , V_14 ) &&
F_113 ( V_11 , V_14 ) ) {
if ( ! V_114 )
F_100 ( V_10 ( * V_12 ) ,
F_119 ( V_14 ) ) ;
F_25 ( & V_47 . V_39 ) ;
F_109 ( V_12 ) ;
F_32 ( & V_47 . V_39 ) ;
V_70 ++ ;
} else {
memset ( ( void * ) V_3 , V_117 , V_11 - V_3 ) ;
V_115 = F_27 ( V_10 ( * V_12 ) ) ;
if ( ! F_115 ( V_115 , V_117 ,
V_14 ) ) {
F_100 ( V_10 ( * V_12 ) ,
F_119 ( V_14 ) ) ;
F_25 ( & V_47 . V_39 ) ;
F_109 ( V_12 ) ;
F_32 ( & V_47 . V_39 ) ;
}
}
continue;
}
V_119 = ( T_1 * ) F_122 ( * V_12 ) ;
F_117 ( V_119 , V_3 , V_11 , V_114 ) ;
F_108 ( V_119 , V_12 ) ;
}
if ( V_114 )
F_70 ( V_84 , - V_70 ) ;
}
static void T_9
F_123 ( unsigned long V_32 , unsigned long V_4 , bool V_114 )
{
unsigned long V_11 ;
unsigned long V_3 ;
T_3 * V_24 ;
T_2 * V_12 ;
bool V_85 = false ;
for ( V_3 = V_32 ; V_3 < V_4 ; V_3 = V_11 ) {
V_11 = F_124 ( V_3 , V_4 ) ;
V_24 = F_23 ( V_3 ) ;
if ( ! F_15 ( * V_24 ) )
continue;
V_12 = ( T_2 * ) F_30 ( * V_24 ) ;
F_120 ( V_12 , V_3 , V_11 , V_114 ) ;
if ( F_110 ( V_12 , V_24 ) )
V_85 = true ;
}
if ( V_85 )
F_22 ( V_32 , V_4 - 1 , 1 ) ;
F_116 () ;
}
void T_6 F_125 ( unsigned long V_32 , unsigned long V_4 )
{
F_123 ( V_32 , V_4 , false ) ;
}
static void T_9
F_126 ( unsigned long V_32 , unsigned long V_4 )
{
V_32 = ( unsigned long ) F_59 ( V_32 ) ;
V_4 = ( unsigned long ) F_59 ( V_4 ) ;
F_123 ( V_32 , V_4 , true ) ;
}
int T_6 F_127 ( T_10 V_32 , T_10 V_53 )
{
unsigned long V_103 = V_32 >> V_67 ;
unsigned long V_104 = V_53 >> V_67 ;
struct V_100 * V_100 ;
int V_105 ;
V_100 = F_128 ( F_129 ( V_103 ) ) ;
F_126 ( V_32 , V_32 + V_53 ) ;
V_105 = F_130 ( V_100 , V_103 , V_104 ) ;
F_99 ( V_105 ) ;
return V_105 ;
}
static void T_4 F_131 ( void )
{
#ifdef F_132
int V_72 ;
F_133 (i)
F_134 ( F_95 ( V_72 ) ) ;
#endif
}
void T_4 F_135 ( void )
{
F_136 () ;
F_131 () ;
F_137 () ;
V_41 = 1 ;
F_138 ( & V_120 , ( void * ) V_121 ,
V_44 , V_122 ) ;
F_139 ( NULL ) ;
}
void F_140 ( void )
{
unsigned long V_32 = F_141 ( V_68 ) ;
unsigned long V_4 = F_141 ( V_123 ) ;
if ( ! V_124 )
return;
F_37 ( L_13 ,
V_32 , V_4 ) ;
F_142 ( V_32 , ( V_4 - V_32 ) >> V_67 ) ;
}
void F_143 ( void )
{
unsigned long V_32 = F_141 ( V_68 ) ;
unsigned long V_4 = F_141 ( V_123 ) ;
if ( ! V_124 )
return;
F_37 ( L_14 ,
V_32 , V_4 ) ;
F_144 ( V_32 , ( V_4 - V_32 ) >> V_67 ) ;
}
void F_145 ( void )
{
unsigned long V_32 = F_141 ( V_68 ) ;
unsigned long V_125 = F_141 ( V_126 ) ;
unsigned long V_4 = ( unsigned long ) & V_127 ;
unsigned long V_128 = F_141 ( & V_123 ) ;
unsigned long V_129 = F_141 ( & V_130 ) ;
unsigned long V_131 ;
F_40 ( V_132 L_15 ,
( V_4 - V_32 ) >> 10 ) ;
F_144 ( V_32 , ( V_4 - V_32 ) >> V_67 ) ;
V_124 = 1 ;
V_131 = F_63 ( ( unsigned long ) V_64 , V_6 ) ;
F_146 ( V_125 , ( V_131 - V_125 ) >> V_67 ) ;
F_147 () ;
#ifdef F_148
F_40 ( V_132 L_16 , V_32 , V_4 ) ;
F_142 ( V_32 , ( V_4 - V_32 ) >> V_67 ) ;
F_40 ( V_132 L_17 ) ;
F_144 ( V_32 , ( V_4 - V_32 ) >> V_67 ) ;
#endif
F_149 ( L_18 ,
( unsigned long ) F_59 ( F_150 ( V_128 ) ) ,
( unsigned long ) F_59 ( F_150 ( V_125 ) ) ) ;
F_149 ( L_18 ,
( unsigned long ) F_59 ( F_150 ( V_129 ) ) ,
( unsigned long ) F_59 ( F_150 ( V_133 ) ) ) ;
}
int F_151 ( unsigned long V_3 )
{
unsigned long V_134 = ( ( long ) V_3 ) >> V_135 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
T_7 * V_49 ;
if ( V_134 != 0 && V_134 != - 1UL )
return 0 ;
V_24 = F_23 ( V_3 ) ;
if ( F_24 ( * V_24 ) )
return 0 ;
V_12 = F_16 ( V_24 , V_3 ) ;
if ( F_42 ( * V_12 ) )
return 0 ;
if ( F_81 ( * V_12 ) )
return F_152 ( F_153 ( * V_12 ) ) ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_45 ( * V_7 ) )
return 0 ;
if ( F_73 ( * V_7 ) )
return F_152 ( F_154 ( * V_7 ) ) ;
V_49 = F_47 ( V_7 , V_3 ) ;
if ( F_155 ( * V_49 ) )
return 0 ;
return F_152 ( F_156 ( * V_49 ) ) ;
}
static unsigned long F_157 ( void )
{
unsigned long V_136 = 1UL << 31 ;
if ( V_137 >= ( 64ULL << ( 30 - V_67 ) ) ) {
F_158 ( L_19 ) ;
return 2UL * 1024 * 1024 * 1024 ;
}
if ( ( V_94 << V_67 ) < ( 16UL << 32 ) )
return V_138 ;
while ( V_136 > V_138 ) {
if ( ! ( ( V_94 << V_67 ) & ( V_136 - 1 ) ) )
break;
V_136 >>= 1 ;
}
F_40 ( V_139 L_20 , V_136 >> 20 ) ;
return V_136 ;
}
unsigned long F_159 ( void )
{
if ( ! V_140 )
V_140 = F_157 () ;
return V_140 ;
}
static int T_9 F_160 ( unsigned long V_32 ,
unsigned long V_4 , int V_141 )
{
unsigned long V_3 ;
unsigned long V_11 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
for ( V_3 = V_32 ; V_3 < V_4 ; V_3 = V_11 ) {
V_11 = F_118 ( V_3 , V_4 ) ;
V_24 = F_161 ( V_3 , V_141 ) ;
if ( ! V_24 )
return - V_17 ;
V_12 = F_162 ( V_24 , V_3 , V_141 ) ;
if ( ! V_12 )
return - V_17 ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_45 ( * V_7 ) ) {
void * V_142 ;
V_142 = F_163 ( V_6 , V_141 ) ;
if ( V_142 ) {
T_7 V_143 ;
V_143 = F_69 ( F_12 ( V_142 ) >> V_67 ,
V_57 ) ;
F_4 ( V_7 , F_5 ( F_68 ( V_143 ) ) ) ;
if ( V_144 != V_142 || V_145 != V_141 ) {
if ( V_146 )
F_40 ( V_139 L_21 ,
V_147 , V_148 - 1 , V_146 , V_144 - 1 , V_145 ) ;
V_147 = V_3 ;
V_145 = V_141 ;
V_146 = V_142 ;
}
V_148 = V_3 + V_6 ;
V_144 = V_142 + V_6 ;
continue;
}
} else if ( F_73 ( * V_7 ) ) {
F_164 ( ( T_7 * ) V_7 , V_141 , V_3 , V_11 ) ;
continue;
}
F_165 ( L_22 ) ;
if ( F_166 ( V_3 , V_11 , V_141 ) )
return - V_17 ;
}
return 0 ;
}
int T_9 F_167 ( unsigned long V_32 , unsigned long V_4 , int V_141 )
{
int V_149 ;
if ( V_150 )
V_149 = F_160 ( V_32 , V_4 , V_141 ) ;
else
V_149 = F_166 ( V_32 , V_4 , V_141 ) ;
if ( ! V_149 )
F_22 ( V_32 , V_4 - 1 , 0 ) ;
return V_149 ;
}
void F_168 ( unsigned long V_151 ,
struct V_36 * V_152 , unsigned long V_53 )
{
unsigned long V_3 = ( unsigned long ) V_152 ;
unsigned long V_4 = ( unsigned long ) ( V_152 + V_53 ) ;
unsigned long V_11 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
unsigned int V_104 ;
struct V_36 * V_36 ;
for (; V_3 < V_4 ; V_3 = V_11 ) {
T_7 * V_49 = NULL ;
V_24 = F_23 ( V_3 ) ;
if ( F_24 ( * V_24 ) ) {
V_11 = ( V_3 + V_44 ) & V_45 ;
continue;
}
F_169 ( V_151 , V_19 ( * V_24 ) , V_110 ) ;
V_12 = F_16 ( V_24 , V_3 ) ;
if ( F_42 ( * V_12 ) ) {
V_11 = ( V_3 + V_44 ) & V_45 ;
continue;
}
F_169 ( V_151 , V_10 ( * V_12 ) , V_110 ) ;
if ( ! V_150 ) {
V_11 = ( V_3 + V_44 ) & V_45 ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_45 ( * V_7 ) )
continue;
F_169 ( V_151 , V_2 ( * V_7 ) ,
V_110 ) ;
V_49 = F_47 ( V_7 , V_3 ) ;
if ( F_155 ( * V_49 ) )
continue;
F_169 ( V_151 , V_69 ( * V_49 ) ,
V_109 ) ;
} else {
V_11 = F_118 ( V_3 , V_4 ) ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_45 ( * V_7 ) )
continue;
V_104 = 1 << ( F_119 ( V_6 ) ) ;
V_36 = V_2 ( * V_7 ) ;
while ( V_104 -- )
F_169 ( V_151 , V_36 ++ ,
V_109 ) ;
}
}
}
void T_9 F_170 ( void )
{
if ( V_146 ) {
F_40 ( V_139 L_21 ,
V_147 , V_148 - 1 , V_146 , V_144 - 1 , V_145 ) ;
V_146 = NULL ;
V_144 = NULL ;
V_145 = 0 ;
}
}
