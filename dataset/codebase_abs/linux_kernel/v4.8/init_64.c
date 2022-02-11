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
F_55 ( T_7 * V_50 , unsigned long V_51 , unsigned long V_52 ,
T_8 V_34 )
{
unsigned long V_53 = 0 , V_54 ;
unsigned long V_55 = V_52 ;
T_7 * V_26 ;
int V_56 ;
V_26 = V_50 + F_56 ( V_51 ) ;
V_56 = F_56 ( V_51 ) ;
for (; V_56 < V_57 ; V_56 ++ , V_51 = V_54 , V_26 ++ ) {
V_54 = ( V_51 & V_20 ) + V_19 ;
if ( V_51 >= V_52 ) {
if ( ! V_16 &&
! F_57 ( V_51 & V_20 , V_54 ,
V_58 ) &&
! F_57 ( V_51 & V_20 , V_54 ,
V_59 ) )
F_34 ( V_26 , F_58 ( 0 ) ) ;
continue;
}
if ( ! F_59 ( * V_26 ) ) {
if ( ! V_16 )
V_53 ++ ;
continue;
}
if ( 0 )
F_60 ( L_12 , V_26 , V_51 ,
F_61 ( V_51 >> V_48 , V_60 ) . V_26 ) ;
V_53 ++ ;
F_34 ( V_26 , F_61 ( V_51 >> V_48 , V_34 ) ) ;
V_55 = ( V_51 & V_20 ) + V_19 ;
}
F_62 ( V_61 , V_53 ) ;
return V_55 ;
}
static unsigned long T_9
F_63 ( T_6 * V_62 , unsigned long V_51 , unsigned long V_52 ,
unsigned long V_63 , T_8 V_34 )
{
unsigned long V_53 = 0 , V_54 ;
unsigned long V_55 = V_52 ;
int V_56 = F_64 ( V_51 ) ;
for (; V_56 < V_64 ; V_56 ++ , V_51 = V_54 ) {
T_6 * V_25 = V_62 + F_64 ( V_51 ) ;
T_7 * V_26 ;
T_8 V_65 = V_34 ;
V_54 = ( V_51 & V_36 ) + V_37 ;
if ( V_51 >= V_52 ) {
if ( ! V_16 &&
! F_57 ( V_51 & V_36 , V_54 ,
V_58 ) &&
! F_57 ( V_51 & V_36 , V_54 ,
V_59 ) )
F_49 ( V_25 , F_50 ( 0 ) ) ;
continue;
}
if ( ! F_29 ( * V_25 ) ) {
if ( ! F_65 ( * V_25 ) ) {
F_5 ( & V_23 . V_14 ) ;
V_26 = ( T_7 * ) F_66 ( * V_25 ) ;
V_55 = F_55 ( V_26 , V_51 ,
V_52 , V_34 ) ;
F_14 ( & V_23 . V_14 ) ;
continue;
}
if ( V_63 & ( 1 << V_66 ) ) {
if ( ! V_16 )
V_53 ++ ;
V_55 = V_54 ;
continue;
}
V_65 = F_67 ( F_68 ( * ( T_7 * ) V_25 ) ) ;
}
if ( V_63 & ( 1 << V_66 ) ) {
V_53 ++ ;
F_5 ( & V_23 . V_14 ) ;
F_34 ( ( T_7 * ) V_25 ,
F_61 ( ( V_51 & V_36 ) >> V_48 ,
F_69 ( F_41 ( V_34 ) | V_67 ) ) ) ;
F_14 ( & V_23 . V_14 ) ;
V_55 = V_54 ;
continue;
}
V_26 = F_70 () ;
V_55 = F_55 ( V_26 , V_51 , V_52 , V_65 ) ;
F_5 ( & V_23 . V_14 ) ;
F_30 ( & V_23 , V_25 , V_26 ) ;
F_14 ( & V_23 . V_14 ) ;
}
F_62 ( V_66 , V_53 ) ;
return V_55 ;
}
static unsigned long T_9
F_71 ( T_5 * V_27 , unsigned long V_51 , unsigned long V_52 ,
unsigned long V_63 )
{
unsigned long V_53 = 0 , V_54 ;
unsigned long V_55 = V_52 ;
unsigned long V_21 = ( unsigned long ) F_44 ( V_51 ) ;
int V_56 = F_33 ( V_21 ) ;
for (; V_56 < V_68 ; V_56 ++ , V_51 = V_54 ) {
T_5 * V_22 ;
T_6 * V_25 ;
T_8 V_34 = V_60 ;
V_21 = ( unsigned long ) F_44 ( V_51 ) ;
V_22 = V_27 + F_33 ( V_21 ) ;
V_54 = ( V_51 & V_69 ) + V_70 ;
if ( V_51 >= V_52 ) {
if ( ! V_16 &&
! F_57 ( V_51 & V_69 , V_54 ,
V_58 ) &&
! F_57 ( V_51 & V_69 , V_54 ,
V_59 ) )
F_47 ( V_22 , F_48 ( 0 ) ) ;
continue;
}
if ( ! F_25 ( * V_22 ) ) {
if ( ! F_72 ( * V_22 ) ) {
V_25 = F_27 ( V_22 , 0 ) ;
V_55 = F_63 ( V_25 , V_51 ,
V_52 ,
V_63 ,
V_34 ) ;
F_73 () ;
continue;
}
if ( V_63 & ( 1 << V_71 ) ) {
if ( ! V_16 )
V_53 ++ ;
V_55 = V_54 ;
continue;
}
V_34 = F_67 ( F_68 ( * ( T_7 * ) V_22 ) ) ;
}
if ( V_63 & ( 1 << V_71 ) ) {
V_53 ++ ;
F_5 ( & V_23 . V_14 ) ;
F_34 ( ( T_7 * ) V_22 ,
F_61 ( ( V_51 & V_69 ) >> V_48 ,
V_35 ) ) ;
F_14 ( & V_23 . V_14 ) ;
V_55 = V_54 ;
continue;
}
V_25 = F_70 () ;
V_55 = F_63 ( V_25 , V_51 , V_52 ,
V_63 , V_34 ) ;
F_5 ( & V_23 . V_14 ) ;
F_26 ( & V_23 , V_22 , V_25 ) ;
F_14 ( & V_23 . V_14 ) ;
}
F_73 () ;
F_62 ( V_71 , V_53 ) ;
return V_55 ;
}
unsigned long T_9
F_74 ( unsigned long V_72 ,
unsigned long V_52 ,
unsigned long V_63 )
{
bool V_73 = false ;
unsigned long V_21 , V_74 , V_43 , V_75 , V_55 ;
V_55 = V_52 ;
V_21 = ( unsigned long ) F_44 ( V_72 ) ;
V_43 = ( unsigned long ) F_44 ( V_52 ) ;
V_74 = V_21 ;
for (; V_21 < V_43 ; V_21 = V_75 ) {
T_2 * V_12 = F_3 ( V_21 ) ;
T_5 * V_22 ;
V_75 = ( V_21 & V_76 ) + V_8 ;
if ( F_75 ( * V_12 ) ) {
V_22 = ( T_5 * ) F_11 ( * V_12 ) ;
V_55 = F_71 ( V_22 , F_46 ( V_21 ) ,
F_46 ( V_43 ) ,
V_63 ) ;
continue;
}
V_22 = F_70 () ;
V_55 = F_71 ( V_22 , F_46 ( V_21 ) , F_46 ( V_43 ) ,
V_63 ) ;
F_5 ( & V_23 . V_14 ) ;
F_21 ( & V_23 , V_12 , V_22 ) ;
F_14 ( & V_23 . V_14 ) ;
V_73 = true ;
}
if ( V_73 )
F_2 ( V_74 , V_43 - 1 , 0 ) ;
F_73 () ;
return V_55 ;
}
void T_1 F_76 ( void )
{
F_77 ( 0 , ( V_77 ) V_78 , & V_79 . V_80 , 0 ) ;
}
void T_1 F_78 ( void )
{
F_79 ( V_81 ) ;
F_80 () ;
F_81 ( 0 , V_82 ) ;
if ( V_82 != V_83 )
F_81 ( 0 , V_83 ) ;
F_82 () ;
}
static void F_83 ( T_10 V_4 , T_10 V_31 )
{
unsigned long V_84 = F_84 ( V_4 + V_31 ) ;
if ( V_84 > V_85 ) {
V_85 = V_84 ;
V_86 = V_84 ;
V_87 = ( void * ) F_44 ( V_85 * V_19 - 1 ) + 1 ;
}
}
int F_85 ( int V_88 , T_10 V_4 , T_10 V_31 , bool V_89 )
{
struct V_90 * V_91 = F_86 ( V_88 ) ;
struct V_92 * V_92 = V_91 -> V_93 +
F_87 ( V_88 , V_4 , V_31 , V_94 , V_89 ) ;
unsigned long V_95 = V_4 >> V_48 ;
unsigned long V_96 = V_31 >> V_48 ;
int V_97 ;
F_88 ( V_4 , V_4 + V_31 ) ;
V_97 = F_89 ( V_88 , V_92 , V_95 , V_96 ) ;
F_90 ( V_97 ) ;
F_83 ( V_4 , V_31 ) ;
return V_97 ;
}
static void T_9 F_91 ( struct V_10 * V_10 , int V_98 )
{
unsigned long V_99 ;
unsigned int V_96 = 1 << V_98 ;
struct V_100 * V_101 = F_92 ( ( unsigned long ) V_10 ) ;
if ( V_101 ) {
F_93 ( V_101 , V_96 ) ;
return;
}
if ( F_94 ( V_10 ) ) {
F_95 ( V_10 ) ;
V_99 = ( unsigned long ) V_10 -> V_102 . V_103 ;
if ( V_99 == V_104 || V_99 == V_105 ) {
while ( V_96 -- )
F_96 ( V_10 ++ ) ;
} else
while ( V_96 -- )
F_97 ( V_10 ++ ) ;
} else
F_98 ( ( unsigned long ) F_7 ( V_10 ) , V_98 ) ;
}
static void T_9 F_99 ( T_7 * V_106 , T_6 * V_25 )
{
T_7 * V_26 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
V_26 = V_106 + V_56 ;
if ( ! F_59 ( * V_26 ) )
return;
}
F_91 ( V_62 ( * V_25 ) , 0 ) ;
F_5 ( & V_23 . V_14 ) ;
F_100 ( V_25 ) ;
F_14 ( & V_23 . V_14 ) ;
}
static void T_9 F_101 ( T_6 * V_107 , T_5 * V_22 )
{
T_6 * V_25 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_64 ; V_56 ++ ) {
V_25 = V_107 + V_56 ;
if ( ! F_29 ( * V_25 ) )
return;
}
F_91 ( V_27 ( * V_22 ) , 0 ) ;
F_5 ( & V_23 . V_14 ) ;
F_102 ( V_22 ) ;
F_14 ( & V_23 . V_14 ) ;
}
static void T_9
F_103 ( T_7 * V_106 , unsigned long V_108 , unsigned long V_5 ,
bool V_109 )
{
unsigned long V_103 , V_53 = 0 ;
T_7 * V_26 ;
void * V_110 ;
V_77 V_111 ;
V_26 = V_106 + F_56 ( V_108 ) ;
for (; V_108 < V_5 ; V_108 = V_103 , V_26 ++ ) {
V_103 = ( V_108 + V_19 ) & V_20 ;
if ( V_103 > V_5 )
V_103 = V_5 ;
if ( ! F_104 ( * V_26 ) )
continue;
V_111 = F_105 ( * V_26 ) + ( V_108 & V_20 ) ;
if ( V_111 < ( V_77 ) 0x40000000 )
return;
if ( F_106 ( V_108 ) && F_106 ( V_103 ) ) {
if ( ! V_109 )
F_91 ( V_50 ( * V_26 ) , 0 ) ;
F_5 ( & V_23 . V_14 ) ;
F_107 ( & V_23 , V_108 , V_26 ) ;
F_14 ( & V_23 . V_14 ) ;
V_53 ++ ;
} else {
memset ( ( void * ) V_108 , V_112 , V_103 - V_108 ) ;
V_110 = F_7 ( V_50 ( * V_26 ) ) ;
if ( ! F_108 ( V_110 , V_112 , V_19 ) ) {
F_91 ( V_50 ( * V_26 ) , 0 ) ;
F_5 ( & V_23 . V_14 ) ;
F_107 ( & V_23 , V_108 , V_26 ) ;
F_14 ( & V_23 . V_14 ) ;
}
}
}
F_109 () ;
if ( V_109 )
F_62 ( V_61 , - V_53 ) ;
}
static void T_9
F_110 ( T_6 * V_107 , unsigned long V_108 , unsigned long V_5 ,
bool V_109 )
{
unsigned long V_103 , V_53 = 0 ;
T_7 * V_113 ;
T_6 * V_25 ;
void * V_110 ;
V_25 = V_107 + F_64 ( V_108 ) ;
for (; V_108 < V_5 ; V_108 = V_103 , V_25 ++ ) {
V_103 = F_111 ( V_108 , V_5 ) ;
if ( ! F_112 ( * V_25 ) )
continue;
if ( F_65 ( * V_25 ) ) {
if ( F_113 ( V_108 , V_37 ) &&
F_113 ( V_103 , V_37 ) ) {
if ( ! V_109 )
F_91 ( V_62 ( * V_25 ) ,
F_114 ( V_37 ) ) ;
F_5 ( & V_23 . V_14 ) ;
F_100 ( V_25 ) ;
F_14 ( & V_23 . V_14 ) ;
V_53 ++ ;
} else {
memset ( ( void * ) V_108 , V_112 , V_103 - V_108 ) ;
V_110 = F_7 ( V_62 ( * V_25 ) ) ;
if ( ! F_108 ( V_110 , V_112 ,
V_37 ) ) {
F_91 ( V_62 ( * V_25 ) ,
F_114 ( V_37 ) ) ;
F_5 ( & V_23 . V_14 ) ;
F_100 ( V_25 ) ;
F_14 ( & V_23 . V_14 ) ;
}
}
continue;
}
V_113 = ( T_7 * ) F_66 ( * V_25 ) ;
F_103 ( V_113 , V_108 , V_103 , V_109 ) ;
F_99 ( V_113 , V_25 ) ;
}
if ( V_109 )
F_62 ( V_66 , - V_53 ) ;
}
static void T_9
F_115 ( T_5 * V_114 , unsigned long V_108 , unsigned long V_5 ,
bool V_109 )
{
unsigned long V_103 , V_53 = 0 ;
T_6 * V_115 ;
T_5 * V_22 ;
void * V_110 ;
V_22 = V_114 + F_33 ( V_108 ) ;
for (; V_108 < V_5 ; V_108 = V_103 , V_22 ++ ) {
V_103 = F_116 ( V_108 , V_5 ) ;
if ( ! F_117 ( * V_22 ) )
continue;
if ( F_72 ( * V_22 ) ) {
if ( F_113 ( V_108 , V_70 ) &&
F_113 ( V_103 , V_70 ) ) {
if ( ! V_109 )
F_91 ( V_27 ( * V_22 ) ,
F_114 ( V_70 ) ) ;
F_5 ( & V_23 . V_14 ) ;
F_102 ( V_22 ) ;
F_14 ( & V_23 . V_14 ) ;
V_53 ++ ;
} else {
memset ( ( void * ) V_108 , V_112 , V_103 - V_108 ) ;
V_110 = F_7 ( V_27 ( * V_22 ) ) ;
if ( ! F_108 ( V_110 , V_112 ,
V_70 ) ) {
F_91 ( V_27 ( * V_22 ) ,
F_114 ( V_70 ) ) ;
F_5 ( & V_23 . V_14 ) ;
F_102 ( V_22 ) ;
F_14 ( & V_23 . V_14 ) ;
}
}
continue;
}
V_115 = ( T_6 * ) F_118 ( * V_22 ) ;
F_110 ( V_115 , V_108 , V_103 , V_109 ) ;
F_101 ( V_115 , V_22 ) ;
}
if ( V_109 )
F_62 ( V_71 , - V_53 ) ;
}
static void T_9
F_119 ( unsigned long V_4 , unsigned long V_5 , bool V_109 )
{
unsigned long V_103 ;
unsigned long V_108 ;
T_2 * V_12 ;
T_5 * V_22 ;
for ( V_108 = V_4 ; V_108 < V_5 ; V_108 = V_103 ) {
V_103 = F_120 ( V_108 , V_5 ) ;
V_12 = F_3 ( V_108 ) ;
if ( ! F_121 ( * V_12 ) )
continue;
V_22 = ( T_5 * ) F_11 ( * V_12 ) ;
F_115 ( V_22 , V_108 , V_103 , V_109 ) ;
}
F_109 () ;
}
void T_4 F_122 ( unsigned long V_4 , unsigned long V_5 )
{
F_119 ( V_4 , V_5 , false ) ;
}
static void T_9
F_123 ( unsigned long V_4 , unsigned long V_5 )
{
V_4 = ( unsigned long ) F_44 ( V_4 ) ;
V_5 = ( unsigned long ) F_44 ( V_5 ) ;
F_119 ( V_4 , V_5 , true ) ;
}
int T_4 F_124 ( T_10 V_4 , T_10 V_31 )
{
unsigned long V_95 = V_4 >> V_48 ;
unsigned long V_96 = V_31 >> V_48 ;
struct V_10 * V_10 = F_125 ( V_95 ) ;
struct V_100 * V_101 ;
struct V_92 * V_92 ;
int V_97 ;
V_101 = F_92 ( ( unsigned long ) V_10 ) ;
if ( V_101 )
V_10 += F_126 ( V_101 ) ;
V_92 = F_127 ( V_10 ) ;
V_97 = F_128 ( V_92 , V_95 , V_96 ) ;
F_90 ( V_97 ) ;
F_123 ( V_4 , V_4 + V_31 ) ;
return V_97 ;
}
static void T_1 F_129 ( void )
{
#ifdef F_130
int V_56 ;
F_131 (i)
F_132 ( F_86 ( V_56 ) ) ;
#endif
}
void T_1 F_133 ( void )
{
F_134 () ;
F_129 () ;
F_135 () ;
V_16 = 1 ;
F_136 ( & V_116 , ( void * ) V_117 ,
V_19 , V_118 ) ;
F_137 ( NULL ) ;
}
void F_138 ( void )
{
unsigned long V_4 = F_139 ( V_49 ) ;
unsigned long V_5 = F_139 ( V_119 ) ;
if ( ! V_120 )
return;
F_19 ( L_13 ,
V_4 , V_5 ) ;
F_140 ( V_4 , ( V_5 - V_4 ) >> V_48 ) ;
}
void F_141 ( void )
{
unsigned long V_4 = F_139 ( V_49 ) ;
unsigned long V_5 = F_139 ( V_119 ) ;
if ( ! V_120 )
return;
F_19 ( L_14 ,
V_4 , V_5 ) ;
F_142 ( V_4 , ( V_5 - V_4 ) >> V_48 ) ;
}
void F_143 ( void )
{
unsigned long V_4 = F_139 ( V_49 ) ;
unsigned long V_121 = F_139 ( V_122 ) ;
unsigned long V_5 = ( unsigned long ) & V_123 ;
unsigned long V_124 = F_139 ( & V_119 ) ;
unsigned long V_125 = F_139 ( & V_126 ) ;
unsigned long V_127 ;
F_23 ( V_128 L_15 ,
( V_5 - V_4 ) >> 10 ) ;
F_142 ( V_4 , ( V_5 - V_4 ) >> V_48 ) ;
V_120 = 1 ;
V_127 = F_54 ( ( unsigned long ) V_45 , V_37 ) ;
F_144 ( V_124 , ( V_127 - V_124 ) >> V_48 ) ;
F_145 () ;
#ifdef F_146
F_23 ( V_128 L_16 , V_4 , V_5 ) ;
F_140 ( V_4 , ( V_5 - V_4 ) >> V_48 ) ;
F_23 ( V_128 L_17 ) ;
F_142 ( V_4 , ( V_5 - V_4 ) >> V_48 ) ;
#endif
F_147 ( L_18 ,
( unsigned long ) F_44 ( F_148 ( V_124 ) ) ,
( unsigned long ) F_44 ( F_148 ( V_121 ) ) ) ;
F_147 ( L_18 ,
( unsigned long ) F_44 ( F_148 ( V_125 ) ) ,
( unsigned long ) F_44 ( F_148 ( V_129 ) ) ) ;
F_149 () ;
}
int F_150 ( unsigned long V_108 )
{
unsigned long V_130 = ( ( long ) V_108 ) >> V_131 ;
T_2 * V_12 ;
T_5 * V_22 ;
T_6 * V_25 ;
T_7 * V_26 ;
if ( V_130 != 0 && V_130 != - 1UL )
return 0 ;
V_12 = F_3 ( V_108 ) ;
if ( F_4 ( * V_12 ) )
return 0 ;
V_22 = F_22 ( V_12 , V_108 ) ;
if ( F_25 ( * V_22 ) )
return 0 ;
if ( F_72 ( * V_22 ) )
return F_151 ( F_152 ( * V_22 ) ) ;
V_25 = F_27 ( V_22 , V_108 ) ;
if ( F_29 ( * V_25 ) )
return 0 ;
if ( F_65 ( * V_25 ) )
return F_151 ( F_153 ( * V_25 ) ) ;
V_26 = F_31 ( V_25 , V_108 ) ;
if ( F_59 ( * V_26 ) )
return 0 ;
return F_151 ( F_154 ( * V_26 ) ) ;
}
static unsigned long F_155 ( void )
{
unsigned long V_132 = V_133 ;
if ( F_156 () || ( ( V_85 << V_48 ) >= ( 64UL << 30 ) ) )
V_132 = 2UL << 30 ;
F_60 ( L_19 , V_132 >> 20 ) ;
return V_132 ;
}
unsigned long F_157 ( void )
{
if ( ! V_134 )
V_134 = F_155 () ;
return V_134 ;
}
static int T_9 F_158 ( unsigned long V_4 ,
unsigned long V_5 , int V_135 , struct V_100 * V_101 )
{
unsigned long V_108 ;
unsigned long V_103 ;
T_2 * V_12 ;
T_5 * V_22 ;
T_6 * V_25 ;
for ( V_108 = V_4 ; V_108 < V_5 ; V_108 = V_103 ) {
V_103 = F_111 ( V_108 , V_5 ) ;
V_12 = F_159 ( V_108 , V_135 ) ;
if ( ! V_12 )
return - V_136 ;
V_22 = F_160 ( V_12 , V_108 , V_135 ) ;
if ( ! V_22 )
return - V_136 ;
V_25 = F_27 ( V_22 , V_108 ) ;
if ( F_29 ( * V_25 ) ) {
void * V_137 ;
V_137 = F_161 ( V_37 , V_135 , V_101 ) ;
if ( V_137 ) {
T_7 V_138 ;
V_138 = F_61 ( F_46 ( V_137 ) >> V_48 ,
V_35 ) ;
F_49 ( V_25 , F_50 ( F_105 ( V_138 ) ) ) ;
if ( V_139 != V_137 || V_140 != V_135 ) {
if ( V_141 )
F_19 ( L_20 ,
V_142 , V_143 - 1 , V_141 , V_139 - 1 , V_140 ) ;
V_142 = V_108 ;
V_140 = V_135 ;
V_141 = V_137 ;
}
V_143 = V_108 + V_37 ;
V_139 = V_137 + V_37 ;
continue;
} else if ( V_101 )
return - V_136 ;
} else if ( F_65 ( * V_25 ) ) {
F_162 ( ( T_7 * ) V_25 , V_135 , V_108 , V_103 ) ;
continue;
}
F_163 ( L_21 ) ;
if ( F_164 ( V_108 , V_103 , V_135 ) )
return - V_136 ;
}
return 0 ;
}
int T_9 F_165 ( unsigned long V_4 , unsigned long V_5 , int V_135 )
{
struct V_100 * V_101 = F_92 ( V_4 ) ;
int V_144 ;
if ( F_166 ( V_145 ) )
V_144 = F_158 ( V_4 , V_5 , V_135 , V_101 ) ;
else if ( V_101 ) {
F_167 ( L_22 ,
V_146 ) ;
V_144 = - V_136 ;
} else
V_144 = F_164 ( V_4 , V_5 , V_135 ) ;
if ( ! V_144 )
F_2 ( V_4 , V_5 - 1 , 0 ) ;
return V_144 ;
}
void F_168 ( unsigned long V_147 ,
struct V_10 * V_148 , unsigned long V_31 )
{
unsigned long V_108 = ( unsigned long ) V_148 ;
unsigned long V_5 = ( unsigned long ) ( V_148 + V_31 ) ;
unsigned long V_103 ;
T_2 * V_12 ;
T_5 * V_22 ;
T_6 * V_25 ;
unsigned int V_96 ;
struct V_10 * V_10 ;
for (; V_108 < V_5 ; V_108 = V_103 ) {
T_7 * V_26 = NULL ;
V_12 = F_3 ( V_108 ) ;
if ( F_4 ( * V_12 ) ) {
V_103 = ( V_108 + V_19 ) & V_20 ;
continue;
}
F_169 ( V_147 , F_170 ( * V_12 ) , V_105 ) ;
V_22 = F_22 ( V_12 , V_108 ) ;
if ( F_25 ( * V_22 ) ) {
V_103 = ( V_108 + V_19 ) & V_20 ;
continue;
}
F_169 ( V_147 , V_27 ( * V_22 ) , V_105 ) ;
if ( ! F_166 ( V_145 ) ) {
V_103 = ( V_108 + V_19 ) & V_20 ;
V_25 = F_27 ( V_22 , V_108 ) ;
if ( F_29 ( * V_25 ) )
continue;
F_169 ( V_147 , V_62 ( * V_25 ) ,
V_105 ) ;
V_26 = F_31 ( V_25 , V_108 ) ;
if ( F_59 ( * V_26 ) )
continue;
F_169 ( V_147 , V_50 ( * V_26 ) ,
V_104 ) ;
} else {
V_103 = F_111 ( V_108 , V_5 ) ;
V_25 = F_27 ( V_22 , V_108 ) ;
if ( F_29 ( * V_25 ) )
continue;
V_96 = 1 << ( F_114 ( V_37 ) ) ;
V_10 = V_62 ( * V_25 ) ;
while ( V_96 -- )
F_169 ( V_147 , V_10 ++ ,
V_104 ) ;
}
}
}
void T_9 F_171 ( void )
{
if ( V_141 ) {
F_19 ( L_20 ,
V_142 , V_143 - 1 , V_141 , V_139 - 1 , V_140 ) ;
V_141 = NULL ;
V_139 = NULL ;
V_140 = 0 ;
}
}
