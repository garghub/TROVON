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
for ( V_6 = V_4 ; V_6 <= V_5 ; V_6 += V_7 ) {
const T_2 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_9 ;
if ( F_4 ( * V_8 ) )
continue;
F_5 ( & V_10 ) ;
F_6 (page, &pgd_list, lru) {
T_2 * V_11 ;
T_3 * V_12 ;
V_11 = ( T_2 * ) F_7 ( V_9 ) + F_8 ( V_6 ) ;
V_12 = & F_9 ( V_9 ) -> V_13 ;
F_5 ( V_12 ) ;
if ( ! F_4 ( * V_8 ) && ! F_4 ( * V_11 ) )
F_10 ( F_11 ( * V_11 )
!= F_11 ( * V_8 ) ) ;
if ( F_4 ( * V_11 ) )
F_12 ( V_11 , * V_8 ) ;
F_13 ( V_12 ) ;
}
F_13 ( & V_10 ) ;
}
}
static T_4 void * F_14 ( void )
{
void * V_14 ;
if ( V_15 )
V_14 = ( void * ) F_15 ( V_16 | V_17 ) ;
else
V_14 = F_16 ( V_18 ) ;
if ( ! V_14 || ( ( unsigned long ) V_14 & ~ V_19 ) ) {
F_17 ( L_3 ,
V_15 ? L_4 : L_5 ) ;
}
F_18 ( L_6 , V_14 ) ;
return V_14 ;
}
static T_5 * F_19 ( T_2 * V_11 , unsigned long V_20 )
{
if ( F_4 ( * V_11 ) ) {
T_5 * V_21 = ( T_5 * ) F_14 () ;
F_20 ( & V_22 , V_11 , V_21 ) ;
if ( V_21 != F_21 ( V_11 , 0 ) )
F_22 ( V_23 L_7 ,
V_21 , F_21 ( V_11 , 0 ) ) ;
}
return F_21 ( V_11 , V_20 ) ;
}
static T_6 * F_23 ( T_5 * V_21 , unsigned long V_20 )
{
if ( F_24 ( * V_21 ) ) {
T_6 * V_24 = ( T_6 * ) F_14 () ;
F_25 ( & V_22 , V_21 , V_24 ) ;
if ( V_24 != F_26 ( V_21 , 0 ) )
F_22 ( V_23 L_8 ,
V_24 , F_26 ( V_21 , 0 ) ) ;
}
return F_26 ( V_21 , V_20 ) ;
}
static T_7 * F_27 ( T_6 * V_24 , unsigned long V_20 )
{
if ( F_28 ( * V_24 ) ) {
T_7 * V_25 = ( T_7 * ) F_14 () ;
F_29 ( & V_22 , V_24 , V_25 ) ;
if ( V_25 != F_30 ( V_24 , 0 ) )
F_22 ( V_23 L_9 ) ;
}
return F_30 ( V_24 , V_20 ) ;
}
void F_31 ( T_5 * V_26 , unsigned long V_20 , T_7 V_27 )
{
T_5 * V_21 ;
T_6 * V_24 ;
T_7 * V_25 ;
V_21 = V_26 + F_32 ( V_20 ) ;
V_24 = F_23 ( V_21 , V_20 ) ;
V_25 = F_27 ( V_24 , V_20 ) ;
F_33 ( V_25 , V_27 ) ;
F_34 ( V_20 ) ;
}
void F_35 ( unsigned long V_20 , T_7 V_28 )
{
T_2 * V_11 ;
T_5 * V_26 ;
F_18 ( L_10 , V_20 , F_36 ( V_28 ) ) ;
V_11 = F_3 ( V_20 ) ;
if ( F_4 ( * V_11 ) ) {
F_22 ( V_23
L_11 ) ;
return;
}
V_26 = ( T_5 * ) F_11 ( * V_11 ) ;
F_31 ( V_26 , V_20 , V_28 ) ;
}
T_6 * T_1 F_37 ( unsigned long V_20 )
{
T_2 * V_11 ;
T_5 * V_21 ;
V_11 = F_3 ( V_20 ) ;
V_21 = F_19 ( V_11 , V_20 ) ;
return F_23 ( V_21 , V_20 ) ;
}
T_7 * T_1 F_38 ( unsigned long V_20 )
{
T_6 * V_24 ;
V_24 = F_37 ( V_20 ) ;
return F_27 ( V_24 , V_20 ) ;
}
static void T_1 F_39 ( unsigned long V_29 , unsigned long V_30 ,
enum V_31 V_32 )
{
T_2 * V_11 ;
T_5 * V_21 ;
T_6 * V_24 ;
T_8 V_33 ;
F_40 ( V_33 ) = F_40 ( V_34 ) |
F_40 ( F_41 ( F_42 ( V_32 ) ) ) ;
F_10 ( ( V_29 & ~ V_35 ) || ( V_30 & ~ V_35 ) ) ;
for (; V_30 ; V_29 += V_36 , V_30 -= V_36 ) {
V_11 = F_3 ( ( unsigned long ) F_43 ( V_29 ) ) ;
if ( F_4 ( * V_11 ) ) {
V_21 = ( T_5 * ) F_14 () ;
F_12 ( V_11 , F_44 ( F_45 ( V_21 ) | V_37 |
V_38 ) ) ;
}
V_21 = F_21 ( V_11 , ( unsigned long ) F_43 ( V_29 ) ) ;
if ( F_24 ( * V_21 ) ) {
V_24 = ( T_6 * ) F_14 () ;
F_46 ( V_21 , F_47 ( F_45 ( V_24 ) | V_37 |
V_38 ) ) ;
}
V_24 = F_26 ( V_21 , V_29 ) ;
F_10 ( ! F_28 ( * V_24 ) ) ;
F_48 ( V_24 , F_49 ( V_29 | F_40 ( V_33 ) ) ) ;
}
}
void T_1 F_50 ( unsigned long V_29 , unsigned long V_30 )
{
F_39 ( V_29 , V_30 , V_39 ) ;
}
void T_1 F_51 ( unsigned long V_29 , unsigned long V_30 )
{
F_39 ( V_29 , V_30 , V_40 ) ;
}
void T_1 F_52 ( void )
{
unsigned long V_20 = V_41 ;
unsigned long V_42 = V_41 + V_43 ;
unsigned long V_5 = F_53 ( ( unsigned long ) V_44 , V_36 ) - 1 ;
T_6 * V_24 = V_45 ;
if ( V_46 )
V_42 = V_41 + ( V_46 << V_47 ) ;
for (; V_20 + V_36 - 1 < V_42 ; V_24 ++ , V_20 += V_36 ) {
if ( F_28 ( * V_24 ) )
continue;
if ( V_20 < ( unsigned long ) V_48 || V_20 > V_5 )
F_48 ( V_24 , F_49 ( 0 ) ) ;
}
}
static unsigned long T_9
F_54 ( T_7 * V_49 , unsigned long V_50 , unsigned long V_51 ,
T_8 V_33 )
{
unsigned long V_52 = 0 , V_53 ;
unsigned long V_54 = V_51 ;
T_7 * V_25 ;
int V_55 ;
V_25 = V_49 + F_55 ( V_50 ) ;
V_55 = F_55 ( V_50 ) ;
for (; V_55 < V_56 ; V_55 ++ , V_50 = V_53 , V_25 ++ ) {
V_53 = ( V_50 & V_19 ) + V_18 ;
if ( V_50 >= V_51 ) {
if ( ! V_15 &&
! F_56 ( V_50 & V_19 , V_53 ,
V_57 ) &&
! F_56 ( V_50 & V_19 , V_53 ,
V_58 ) )
F_33 ( V_25 , F_57 ( 0 ) ) ;
continue;
}
if ( ! F_58 ( * V_25 ) ) {
if ( ! V_15 )
V_52 ++ ;
continue;
}
if ( 0 )
F_59 ( L_12 , V_25 , V_50 ,
F_60 ( V_50 >> V_47 , V_59 ) . V_25 ) ;
V_52 ++ ;
F_33 ( V_25 , F_60 ( V_50 >> V_47 , V_33 ) ) ;
V_54 = ( V_50 & V_19 ) + V_18 ;
}
F_61 ( V_60 , V_52 ) ;
return V_54 ;
}
static unsigned long T_9
F_62 ( T_6 * V_61 , unsigned long V_50 , unsigned long V_51 ,
unsigned long V_62 , T_8 V_33 )
{
unsigned long V_52 = 0 , V_53 ;
unsigned long V_54 = V_51 ;
int V_55 = F_63 ( V_50 ) ;
for (; V_55 < V_63 ; V_55 ++ , V_50 = V_53 ) {
T_6 * V_24 = V_61 + F_63 ( V_50 ) ;
T_7 * V_25 ;
T_8 V_64 = V_33 ;
V_53 = ( V_50 & V_35 ) + V_36 ;
if ( V_50 >= V_51 ) {
if ( ! V_15 &&
! F_56 ( V_50 & V_35 , V_53 ,
V_57 ) &&
! F_56 ( V_50 & V_35 , V_53 ,
V_58 ) )
F_48 ( V_24 , F_49 ( 0 ) ) ;
continue;
}
if ( ! F_28 ( * V_24 ) ) {
if ( ! F_64 ( * V_24 ) ) {
F_5 ( & V_22 . V_13 ) ;
V_25 = ( T_7 * ) F_65 ( * V_24 ) ;
V_54 = F_54 ( V_25 , V_50 ,
V_51 , V_33 ) ;
F_13 ( & V_22 . V_13 ) ;
continue;
}
if ( V_62 & ( 1 << V_65 ) ) {
if ( ! V_15 )
V_52 ++ ;
V_54 = V_53 ;
continue;
}
V_64 = F_66 ( F_67 ( * ( T_7 * ) V_24 ) ) ;
}
if ( V_62 & ( 1 << V_65 ) ) {
V_52 ++ ;
F_5 ( & V_22 . V_13 ) ;
F_33 ( ( T_7 * ) V_24 ,
F_60 ( ( V_50 & V_35 ) >> V_47 ,
F_68 ( F_40 ( V_33 ) | V_66 ) ) ) ;
F_13 ( & V_22 . V_13 ) ;
V_54 = V_53 ;
continue;
}
V_25 = F_69 () ;
V_54 = F_54 ( V_25 , V_50 , V_51 , V_64 ) ;
F_5 ( & V_22 . V_13 ) ;
F_29 ( & V_22 , V_24 , V_25 ) ;
F_13 ( & V_22 . V_13 ) ;
}
F_61 ( V_65 , V_52 ) ;
return V_54 ;
}
static unsigned long T_9
F_70 ( T_5 * V_26 , unsigned long V_50 , unsigned long V_51 ,
unsigned long V_62 )
{
unsigned long V_52 = 0 , V_53 ;
unsigned long V_54 = V_51 ;
unsigned long V_20 = ( unsigned long ) F_43 ( V_50 ) ;
int V_55 = F_32 ( V_20 ) ;
for (; V_55 < V_67 ; V_55 ++ , V_50 = V_53 ) {
T_5 * V_21 ;
T_6 * V_24 ;
T_8 V_33 = V_59 ;
V_20 = ( unsigned long ) F_43 ( V_50 ) ;
V_21 = V_26 + F_32 ( V_20 ) ;
V_53 = ( V_50 & V_68 ) + V_69 ;
if ( V_50 >= V_51 ) {
if ( ! V_15 &&
! F_56 ( V_50 & V_68 , V_53 ,
V_57 ) &&
! F_56 ( V_50 & V_68 , V_53 ,
V_58 ) )
F_46 ( V_21 , F_47 ( 0 ) ) ;
continue;
}
if ( ! F_24 ( * V_21 ) ) {
if ( ! F_71 ( * V_21 ) ) {
V_24 = F_26 ( V_21 , 0 ) ;
V_54 = F_62 ( V_24 , V_50 ,
V_51 ,
V_62 ,
V_33 ) ;
F_72 () ;
continue;
}
if ( V_62 & ( 1 << V_70 ) ) {
if ( ! V_15 )
V_52 ++ ;
V_54 = V_53 ;
continue;
}
V_33 = F_66 ( F_67 ( * ( T_7 * ) V_21 ) ) ;
}
if ( V_62 & ( 1 << V_70 ) ) {
V_52 ++ ;
F_5 ( & V_22 . V_13 ) ;
F_33 ( ( T_7 * ) V_21 ,
F_60 ( ( V_50 & V_68 ) >> V_47 ,
V_34 ) ) ;
F_13 ( & V_22 . V_13 ) ;
V_54 = V_53 ;
continue;
}
V_24 = F_69 () ;
V_54 = F_62 ( V_24 , V_50 , V_51 ,
V_62 , V_33 ) ;
F_5 ( & V_22 . V_13 ) ;
F_25 ( & V_22 , V_21 , V_24 ) ;
F_13 ( & V_22 . V_13 ) ;
}
F_72 () ;
F_61 ( V_70 , V_52 ) ;
return V_54 ;
}
unsigned long T_9
F_73 ( unsigned long V_71 ,
unsigned long V_51 ,
unsigned long V_62 )
{
bool V_72 = false ;
unsigned long V_20 , V_73 , V_42 , V_74 , V_54 ;
V_54 = V_51 ;
V_20 = ( unsigned long ) F_43 ( V_71 ) ;
V_42 = ( unsigned long ) F_43 ( V_51 ) ;
V_73 = V_20 ;
for (; V_20 < V_42 ; V_20 = V_74 ) {
T_2 * V_11 = F_3 ( V_20 ) ;
T_5 * V_21 ;
V_74 = ( V_20 & V_75 ) + V_7 ;
if ( F_74 ( * V_11 ) ) {
V_21 = ( T_5 * ) F_11 ( * V_11 ) ;
V_54 = F_70 ( V_21 , F_45 ( V_20 ) ,
F_45 ( V_42 ) ,
V_62 ) ;
continue;
}
V_21 = F_69 () ;
V_54 = F_70 ( V_21 , F_45 ( V_20 ) , F_45 ( V_42 ) ,
V_62 ) ;
F_5 ( & V_22 . V_13 ) ;
F_20 ( & V_22 , V_11 , V_21 ) ;
F_13 ( & V_22 . V_13 ) ;
V_72 = true ;
}
if ( V_72 )
F_2 ( V_73 , V_42 - 1 ) ;
F_72 () ;
return V_54 ;
}
void T_1 F_75 ( void )
{
F_76 ( 0 , ( V_76 ) V_77 , & V_78 . V_79 , 0 ) ;
}
void T_1 F_77 ( void )
{
F_78 ( V_80 ) ;
F_79 () ;
F_80 ( 0 , V_81 ) ;
if ( V_81 != V_82 )
F_80 ( 0 , V_82 ) ;
F_81 () ;
}
static void F_82 ( T_10 V_4 , T_10 V_30 )
{
unsigned long V_83 = F_83 ( V_4 + V_30 ) ;
if ( V_83 > V_84 ) {
V_84 = V_83 ;
V_85 = V_83 ;
V_86 = ( void * ) F_43 ( V_84 * V_18 - 1 ) + 1 ;
}
}
int F_84 ( int V_87 , T_10 V_4 , T_10 V_30 , bool V_88 )
{
struct V_89 * V_90 = F_85 ( V_87 ) ;
struct V_91 * V_91 = V_90 -> V_92 +
F_86 ( V_87 , V_4 , V_30 , V_93 , V_88 ) ;
unsigned long V_94 = V_4 >> V_47 ;
unsigned long V_95 = V_30 >> V_47 ;
int V_96 ;
F_87 ( V_4 , V_4 + V_30 ) ;
V_96 = F_88 ( V_87 , V_91 , V_94 , V_95 ) ;
F_89 ( V_96 ) ;
F_82 ( V_4 , V_30 ) ;
return V_96 ;
}
static void T_9 F_90 ( struct V_9 * V_9 , int V_97 )
{
unsigned long V_98 ;
unsigned int V_95 = 1 << V_97 ;
struct V_99 * V_100 = F_91 ( ( unsigned long ) V_9 ) ;
if ( V_100 ) {
F_92 ( V_100 , V_95 ) ;
return;
}
if ( F_93 ( V_9 ) ) {
F_94 ( V_9 ) ;
V_98 = ( unsigned long ) V_9 -> V_101 ;
if ( V_98 == V_102 || V_98 == V_103 ) {
while ( V_95 -- )
F_95 ( V_9 ++ ) ;
} else
while ( V_95 -- )
F_96 ( V_9 ++ ) ;
} else
F_97 ( ( unsigned long ) F_7 ( V_9 ) , V_97 ) ;
}
static void T_9 F_98 ( T_7 * V_104 , T_6 * V_24 )
{
T_7 * V_25 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
V_25 = V_104 + V_55 ;
if ( ! F_58 ( * V_25 ) )
return;
}
F_90 ( V_61 ( * V_24 ) , 0 ) ;
F_5 ( & V_22 . V_13 ) ;
F_99 ( V_24 ) ;
F_13 ( & V_22 . V_13 ) ;
}
static void T_9 F_100 ( T_6 * V_105 , T_5 * V_21 )
{
T_6 * V_24 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_63 ; V_55 ++ ) {
V_24 = V_105 + V_55 ;
if ( ! F_28 ( * V_24 ) )
return;
}
F_90 ( V_26 ( * V_21 ) , 0 ) ;
F_5 ( & V_22 . V_13 ) ;
F_101 ( V_21 ) ;
F_13 ( & V_22 . V_13 ) ;
}
static void T_9
F_102 ( T_7 * V_104 , unsigned long V_106 , unsigned long V_5 ,
bool V_107 )
{
unsigned long V_108 , V_52 = 0 ;
T_7 * V_25 ;
void * V_109 ;
V_76 V_110 ;
V_25 = V_104 + F_55 ( V_106 ) ;
for (; V_106 < V_5 ; V_106 = V_108 , V_25 ++ ) {
V_108 = ( V_106 + V_18 ) & V_19 ;
if ( V_108 > V_5 )
V_108 = V_5 ;
if ( ! F_103 ( * V_25 ) )
continue;
V_110 = F_104 ( * V_25 ) + ( V_106 & V_19 ) ;
if ( V_110 < ( V_76 ) 0x40000000 )
return;
if ( F_105 ( V_106 ) && F_105 ( V_108 ) ) {
if ( ! V_107 )
F_90 ( V_49 ( * V_25 ) , 0 ) ;
F_5 ( & V_22 . V_13 ) ;
F_106 ( & V_22 , V_106 , V_25 ) ;
F_13 ( & V_22 . V_13 ) ;
V_52 ++ ;
} else {
memset ( ( void * ) V_106 , V_111 , V_108 - V_106 ) ;
V_109 = F_7 ( V_49 ( * V_25 ) ) ;
if ( ! F_107 ( V_109 , V_111 , V_18 ) ) {
F_90 ( V_49 ( * V_25 ) , 0 ) ;
F_5 ( & V_22 . V_13 ) ;
F_106 ( & V_22 , V_106 , V_25 ) ;
F_13 ( & V_22 . V_13 ) ;
}
}
}
F_108 () ;
if ( V_107 )
F_61 ( V_60 , - V_52 ) ;
}
static void T_9
F_109 ( T_6 * V_105 , unsigned long V_106 , unsigned long V_5 ,
bool V_107 )
{
unsigned long V_108 , V_52 = 0 ;
T_7 * V_112 ;
T_6 * V_24 ;
void * V_109 ;
V_24 = V_105 + F_63 ( V_106 ) ;
for (; V_106 < V_5 ; V_106 = V_108 , V_24 ++ ) {
V_108 = F_110 ( V_106 , V_5 ) ;
if ( ! F_111 ( * V_24 ) )
continue;
if ( F_64 ( * V_24 ) ) {
if ( F_112 ( V_106 , V_36 ) &&
F_112 ( V_108 , V_36 ) ) {
if ( ! V_107 )
F_90 ( V_61 ( * V_24 ) ,
F_113 ( V_36 ) ) ;
F_5 ( & V_22 . V_13 ) ;
F_99 ( V_24 ) ;
F_13 ( & V_22 . V_13 ) ;
V_52 ++ ;
} else {
memset ( ( void * ) V_106 , V_111 , V_108 - V_106 ) ;
V_109 = F_7 ( V_61 ( * V_24 ) ) ;
if ( ! F_107 ( V_109 , V_111 ,
V_36 ) ) {
F_90 ( V_61 ( * V_24 ) ,
F_113 ( V_36 ) ) ;
F_5 ( & V_22 . V_13 ) ;
F_99 ( V_24 ) ;
F_13 ( & V_22 . V_13 ) ;
}
}
continue;
}
V_112 = ( T_7 * ) F_65 ( * V_24 ) ;
F_102 ( V_112 , V_106 , V_108 , V_107 ) ;
F_98 ( V_112 , V_24 ) ;
}
if ( V_107 )
F_61 ( V_65 , - V_52 ) ;
}
static void T_9
F_114 ( T_5 * V_113 , unsigned long V_106 , unsigned long V_5 ,
bool V_107 )
{
unsigned long V_108 , V_52 = 0 ;
T_6 * V_114 ;
T_5 * V_21 ;
void * V_109 ;
V_21 = V_113 + F_32 ( V_106 ) ;
for (; V_106 < V_5 ; V_106 = V_108 , V_21 ++ ) {
V_108 = F_115 ( V_106 , V_5 ) ;
if ( ! F_116 ( * V_21 ) )
continue;
if ( F_71 ( * V_21 ) ) {
if ( F_112 ( V_106 , V_69 ) &&
F_112 ( V_108 , V_69 ) ) {
if ( ! V_107 )
F_90 ( V_26 ( * V_21 ) ,
F_113 ( V_69 ) ) ;
F_5 ( & V_22 . V_13 ) ;
F_101 ( V_21 ) ;
F_13 ( & V_22 . V_13 ) ;
V_52 ++ ;
} else {
memset ( ( void * ) V_106 , V_111 , V_108 - V_106 ) ;
V_109 = F_7 ( V_26 ( * V_21 ) ) ;
if ( ! F_107 ( V_109 , V_111 ,
V_69 ) ) {
F_90 ( V_26 ( * V_21 ) ,
F_113 ( V_69 ) ) ;
F_5 ( & V_22 . V_13 ) ;
F_101 ( V_21 ) ;
F_13 ( & V_22 . V_13 ) ;
}
}
continue;
}
V_114 = ( T_6 * ) F_117 ( * V_21 ) ;
F_109 ( V_114 , V_106 , V_108 , V_107 ) ;
F_100 ( V_114 , V_21 ) ;
}
if ( V_107 )
F_61 ( V_70 , - V_52 ) ;
}
static void T_9
F_118 ( unsigned long V_4 , unsigned long V_5 , bool V_107 )
{
unsigned long V_108 ;
unsigned long V_106 ;
T_2 * V_11 ;
T_5 * V_21 ;
for ( V_106 = V_4 ; V_106 < V_5 ; V_106 = V_108 ) {
V_108 = F_119 ( V_106 , V_5 ) ;
V_11 = F_3 ( V_106 ) ;
if ( ! F_120 ( * V_11 ) )
continue;
V_21 = ( T_5 * ) F_11 ( * V_11 ) ;
F_114 ( V_21 , V_106 , V_108 , V_107 ) ;
}
F_108 () ;
}
void T_4 F_121 ( unsigned long V_4 , unsigned long V_5 )
{
F_118 ( V_4 , V_5 , false ) ;
}
static void T_9
F_122 ( unsigned long V_4 , unsigned long V_5 )
{
V_4 = ( unsigned long ) F_43 ( V_4 ) ;
V_5 = ( unsigned long ) F_43 ( V_5 ) ;
F_118 ( V_4 , V_5 , true ) ;
}
int T_4 F_123 ( T_10 V_4 , T_10 V_30 )
{
unsigned long V_94 = V_4 >> V_47 ;
unsigned long V_95 = V_30 >> V_47 ;
struct V_9 * V_9 = F_124 ( V_94 ) ;
struct V_99 * V_100 ;
struct V_91 * V_91 ;
int V_96 ;
V_100 = F_91 ( ( unsigned long ) V_9 ) ;
if ( V_100 )
V_9 += F_125 ( V_100 ) ;
V_91 = F_126 ( V_9 ) ;
V_96 = F_127 ( V_91 , V_94 , V_95 ) ;
F_89 ( V_96 ) ;
F_122 ( V_4 , V_4 + V_30 ) ;
return V_96 ;
}
static void T_1 F_128 ( void )
{
#ifdef F_129
int V_55 ;
F_130 (i)
F_131 ( F_85 ( V_55 ) ) ;
#endif
}
void T_1 F_132 ( void )
{
F_133 () ;
F_128 () ;
F_134 () ;
V_15 = 1 ;
F_135 ( & V_115 , ( void * ) V_116 ,
V_18 , V_117 ) ;
F_136 ( NULL ) ;
}
void F_137 ( void )
{
unsigned long V_4 = F_138 ( V_48 ) ;
unsigned long V_5 = F_138 ( V_118 ) ;
if ( ! V_119 )
return;
F_18 ( L_13 ,
V_4 , V_5 ) ;
F_139 ( V_4 , ( V_5 - V_4 ) >> V_47 ) ;
}
void F_140 ( void )
{
unsigned long V_4 = F_138 ( V_48 ) ;
unsigned long V_5 = F_138 ( V_118 ) ;
if ( ! V_119 )
return;
F_18 ( L_14 ,
V_4 , V_5 ) ;
F_141 ( V_4 , ( V_5 - V_4 ) >> V_47 ) ;
}
void F_142 ( void )
{
unsigned long V_4 = F_138 ( V_48 ) ;
unsigned long V_120 = F_138 ( V_121 ) ;
unsigned long V_5 = ( unsigned long ) & V_122 ;
unsigned long V_123 = F_138 ( & V_118 ) ;
unsigned long V_124 = F_138 ( & V_125 ) ;
unsigned long V_126 ;
F_22 ( V_127 L_15 ,
( V_5 - V_4 ) >> 10 ) ;
F_141 ( V_4 , ( V_5 - V_4 ) >> V_47 ) ;
V_119 = 1 ;
V_126 = F_53 ( ( unsigned long ) V_44 , V_36 ) ;
F_143 ( V_123 , ( V_126 - V_123 ) >> V_47 ) ;
#ifdef F_144
F_22 ( V_127 L_16 , V_4 , V_5 ) ;
F_139 ( V_4 , ( V_5 - V_4 ) >> V_47 ) ;
F_22 ( V_127 L_17 ) ;
F_141 ( V_4 , ( V_5 - V_4 ) >> V_47 ) ;
#endif
F_145 ( L_18 ,
( unsigned long ) F_43 ( F_146 ( V_123 ) ) ,
( unsigned long ) F_43 ( F_146 ( V_120 ) ) ) ;
F_145 ( L_18 ,
( unsigned long ) F_43 ( F_146 ( V_124 ) ) ,
( unsigned long ) F_43 ( F_146 ( V_128 ) ) ) ;
F_147 () ;
}
int F_148 ( unsigned long V_106 )
{
unsigned long V_129 = ( ( long ) V_106 ) >> V_130 ;
T_2 * V_11 ;
T_5 * V_21 ;
T_6 * V_24 ;
T_7 * V_25 ;
if ( V_129 != 0 && V_129 != - 1UL )
return 0 ;
V_11 = F_3 ( V_106 ) ;
if ( F_4 ( * V_11 ) )
return 0 ;
V_21 = F_21 ( V_11 , V_106 ) ;
if ( F_24 ( * V_21 ) )
return 0 ;
if ( F_71 ( * V_21 ) )
return F_149 ( F_150 ( * V_21 ) ) ;
V_24 = F_26 ( V_21 , V_106 ) ;
if ( F_28 ( * V_24 ) )
return 0 ;
if ( F_64 ( * V_24 ) )
return F_149 ( F_151 ( * V_24 ) ) ;
V_25 = F_30 ( V_24 , V_106 ) ;
if ( F_58 ( * V_25 ) )
return 0 ;
return F_149 ( F_152 ( * V_25 ) ) ;
}
static unsigned long F_153 ( void )
{
unsigned long V_131 = V_132 ;
if ( F_154 () || ( ( V_84 << V_47 ) >= ( 64UL << 30 ) ) )
V_131 = 2UL << 30 ;
F_59 ( L_19 , V_131 >> 20 ) ;
return V_131 ;
}
unsigned long F_155 ( void )
{
if ( ! V_133 )
V_133 = F_153 () ;
return V_133 ;
}
static int T_9 F_156 ( unsigned long V_4 ,
unsigned long V_5 , int V_134 , struct V_99 * V_100 )
{
unsigned long V_106 ;
unsigned long V_108 ;
T_2 * V_11 ;
T_5 * V_21 ;
T_6 * V_24 ;
for ( V_106 = V_4 ; V_106 < V_5 ; V_106 = V_108 ) {
V_108 = F_110 ( V_106 , V_5 ) ;
V_11 = F_157 ( V_106 , V_134 ) ;
if ( ! V_11 )
return - V_135 ;
V_21 = F_158 ( V_11 , V_106 , V_134 ) ;
if ( ! V_21 )
return - V_135 ;
V_24 = F_26 ( V_21 , V_106 ) ;
if ( F_28 ( * V_24 ) ) {
void * V_136 ;
V_136 = F_159 ( V_36 , V_134 , V_100 ) ;
if ( V_136 ) {
T_7 V_137 ;
V_137 = F_60 ( F_45 ( V_136 ) >> V_47 ,
V_34 ) ;
F_48 ( V_24 , F_49 ( F_104 ( V_137 ) ) ) ;
if ( V_138 != V_136 || V_139 != V_134 ) {
if ( V_140 )
F_18 ( L_20 ,
V_141 , V_142 - 1 , V_140 , V_138 - 1 , V_139 ) ;
V_141 = V_106 ;
V_139 = V_134 ;
V_140 = V_136 ;
}
V_142 = V_106 + V_36 ;
V_138 = V_136 + V_36 ;
continue;
} else if ( V_100 )
return - V_135 ;
} else if ( F_64 ( * V_24 ) ) {
F_160 ( ( T_7 * ) V_24 , V_134 , V_106 , V_108 ) ;
continue;
}
F_161 ( L_21 ) ;
if ( F_162 ( V_106 , V_108 , V_134 ) )
return - V_135 ;
}
return 0 ;
}
int T_9 F_163 ( unsigned long V_4 , unsigned long V_5 , int V_134 )
{
struct V_99 * V_100 = F_91 ( V_4 ) ;
int V_143 ;
if ( F_164 ( V_144 ) )
V_143 = F_156 ( V_4 , V_5 , V_134 , V_100 ) ;
else if ( V_100 ) {
F_165 ( L_22 ,
V_145 ) ;
V_143 = - V_135 ;
} else
V_143 = F_162 ( V_4 , V_5 , V_134 ) ;
if ( ! V_143 )
F_2 ( V_4 , V_5 - 1 ) ;
return V_143 ;
}
void F_166 ( unsigned long V_146 ,
struct V_9 * V_147 , unsigned long V_30 )
{
unsigned long V_106 = ( unsigned long ) V_147 ;
unsigned long V_5 = ( unsigned long ) ( V_147 + V_30 ) ;
unsigned long V_108 ;
T_2 * V_11 ;
T_5 * V_21 ;
T_6 * V_24 ;
unsigned int V_95 ;
struct V_9 * V_9 ;
for (; V_106 < V_5 ; V_106 = V_108 ) {
T_7 * V_25 = NULL ;
V_11 = F_3 ( V_106 ) ;
if ( F_4 ( * V_11 ) ) {
V_108 = ( V_106 + V_18 ) & V_19 ;
continue;
}
F_167 ( V_146 , F_168 ( * V_11 ) , V_103 ) ;
V_21 = F_21 ( V_11 , V_106 ) ;
if ( F_24 ( * V_21 ) ) {
V_108 = ( V_106 + V_18 ) & V_19 ;
continue;
}
F_167 ( V_146 , V_26 ( * V_21 ) , V_103 ) ;
if ( ! F_164 ( V_144 ) ) {
V_108 = ( V_106 + V_18 ) & V_19 ;
V_24 = F_26 ( V_21 , V_106 ) ;
if ( F_28 ( * V_24 ) )
continue;
F_167 ( V_146 , V_61 ( * V_24 ) ,
V_103 ) ;
V_25 = F_30 ( V_24 , V_106 ) ;
if ( F_58 ( * V_25 ) )
continue;
F_167 ( V_146 , V_49 ( * V_25 ) ,
V_102 ) ;
} else {
V_108 = F_110 ( V_106 , V_5 ) ;
V_24 = F_26 ( V_21 , V_106 ) ;
if ( F_28 ( * V_24 ) )
continue;
V_95 = 1 << ( F_113 ( V_36 ) ) ;
V_9 = V_61 ( * V_24 ) ;
while ( V_95 -- )
F_167 ( V_146 , V_9 ++ ,
V_102 ) ;
}
}
}
void T_9 F_169 ( void )
{
if ( V_140 ) {
F_18 ( L_20 ,
V_141 , V_142 - 1 , V_140 , V_138 - 1 , V_139 ) ;
V_140 = NULL ;
V_138 = NULL ;
V_139 = 0 ;
}
}
