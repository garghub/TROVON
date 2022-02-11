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
void F_22 ( unsigned long V_32 , unsigned long V_4 )
{
unsigned long V_33 ;
for ( V_33 = V_32 ; V_33 <= V_4 ; V_33 += V_26 ) {
const T_3 * V_34 = F_23 ( V_33 ) ;
struct V_35 * V_35 ;
if ( F_24 ( * V_34 ) )
continue;
F_25 ( & V_36 ) ;
F_26 (page, &pgd_list, lru) {
T_3 * V_24 ;
T_5 * V_37 ;
V_24 = ( T_3 * ) F_27 ( V_35 ) + F_14 ( V_33 ) ;
V_37 = & F_28 ( V_35 ) -> V_38 ;
F_25 ( V_37 ) ;
if ( F_24 ( * V_24 ) )
F_17 ( V_24 , * V_34 ) ;
else
F_29 ( F_30 ( * V_24 )
!= F_30 ( * V_34 ) ) ;
F_31 ( V_37 ) ;
}
F_31 ( & V_36 ) ;
}
}
static T_6 void * F_32 ( void )
{
void * V_39 ;
if ( V_40 )
V_39 = ( void * ) F_33 ( V_41 | V_42 ) ;
else
V_39 = F_34 ( V_43 ) ;
if ( ! V_39 || ( ( unsigned long ) V_39 & ~ V_44 ) ) {
F_35 ( L_3 ,
V_40 ? L_4 : L_5 ) ;
}
F_36 ( L_6 , V_39 ) ;
return V_39 ;
}
static T_2 * F_37 ( T_3 * V_24 , unsigned long V_45 )
{
if ( F_24 ( * V_24 ) ) {
T_2 * V_12 = ( T_2 * ) F_32 () ;
F_38 ( & V_46 , V_24 , V_12 ) ;
if ( V_12 != F_16 ( V_24 , 0 ) )
F_39 ( V_47 L_7 ,
V_12 , F_16 ( V_24 , 0 ) ) ;
}
return F_16 ( V_24 , V_45 ) ;
}
static T_1 * F_40 ( T_2 * V_12 , unsigned long V_45 )
{
if ( F_41 ( * V_12 ) ) {
T_1 * V_7 = ( T_1 * ) F_32 () ;
F_42 ( & V_46 , V_12 , V_7 ) ;
if ( V_7 != F_9 ( V_12 , 0 ) )
F_39 ( V_47 L_8 ,
V_7 , F_9 ( V_12 , 0 ) ) ;
}
return F_9 ( V_12 , V_45 ) ;
}
static T_7 * F_43 ( T_1 * V_7 , unsigned long V_45 )
{
if ( F_44 ( * V_7 ) ) {
T_7 * V_48 = ( T_7 * ) F_32 () ;
F_45 ( & V_46 , V_7 , V_48 ) ;
if ( V_48 != F_46 ( V_7 , 0 ) )
F_39 ( V_47 L_9 ) ;
}
return F_46 ( V_7 , V_45 ) ;
}
void F_47 ( T_2 * V_10 , unsigned long V_45 , T_7 V_49 )
{
T_2 * V_12 ;
T_1 * V_7 ;
T_7 * V_48 ;
V_12 = V_10 + F_7 ( V_45 ) ;
V_7 = F_40 ( V_12 , V_45 ) ;
V_48 = F_43 ( V_7 , V_45 ) ;
F_48 ( V_48 , V_49 ) ;
F_49 ( V_45 ) ;
}
void F_50 ( unsigned long V_45 , T_7 V_50 )
{
T_3 * V_24 ;
T_2 * V_10 ;
F_36 ( L_10 , V_45 , F_51 ( V_50 ) ) ;
V_24 = F_23 ( V_45 ) ;
if ( F_24 ( * V_24 ) ) {
F_39 ( V_47
L_11 ) ;
return;
}
V_10 = ( T_2 * ) F_30 ( * V_24 ) ;
F_47 ( V_10 , V_45 , V_50 ) ;
}
T_1 * T_4 F_52 ( unsigned long V_45 )
{
T_3 * V_24 ;
T_2 * V_12 ;
V_24 = F_23 ( V_45 ) ;
V_12 = F_37 ( V_24 , V_45 ) ;
return F_40 ( V_12 , V_45 ) ;
}
T_7 * T_4 F_53 ( unsigned long V_45 )
{
T_1 * V_7 ;
V_7 = F_52 ( V_45 ) ;
return F_43 ( V_7 , V_45 ) ;
}
static void T_4 F_54 ( unsigned long V_51 , unsigned long V_52 ,
T_8 V_53 )
{
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
F_29 ( ( V_51 & ~ V_5 ) || ( V_52 & ~ V_5 ) ) ;
for (; V_52 ; V_51 += V_6 , V_52 -= V_6 ) {
V_24 = F_23 ( ( unsigned long ) F_55 ( V_51 ) ) ;
if ( F_24 ( * V_24 ) ) {
V_12 = ( T_2 * ) F_32 () ;
F_17 ( V_24 , F_18 ( F_12 ( V_12 ) | V_18 |
V_54 ) ) ;
}
V_12 = F_16 ( V_24 , ( unsigned long ) F_55 ( V_51 ) ) ;
if ( F_41 ( * V_12 ) ) {
V_7 = ( T_1 * ) F_32 () ;
F_10 ( V_12 , F_11 ( F_12 ( V_7 ) | V_18 |
V_54 ) ) ;
}
V_7 = F_9 ( V_12 , V_51 ) ;
F_29 ( ! F_44 ( * V_7 ) ) ;
F_4 ( V_7 , F_5 ( V_51 | F_56 ( V_53 ) ) ) ;
}
}
void T_4 F_57 ( unsigned long V_51 , unsigned long V_52 )
{
F_54 ( V_51 , V_52 , V_55 ) ;
}
void T_4 F_58 ( unsigned long V_51 , unsigned long V_52 )
{
F_54 ( V_51 , V_52 , V_56 ) ;
}
void T_4 F_59 ( void )
{
unsigned long V_45 = V_57 ;
unsigned long V_58 = V_57 + V_59 ;
unsigned long V_4 = F_60 ( ( unsigned long ) V_60 , V_6 ) - 1 ;
T_1 * V_7 = V_61 ;
if ( V_62 )
V_58 = V_57 + ( V_62 << V_63 ) ;
for (; V_45 + V_6 - 1 < V_58 ; V_7 ++ , V_45 += V_6 ) {
if ( F_44 ( * V_7 ) )
continue;
if ( V_45 < ( unsigned long ) V_64 || V_45 > V_4 )
F_4 ( V_7 , F_5 ( 0 ) ) ;
}
}
static unsigned long T_9
F_61 ( T_7 * V_65 , unsigned long V_3 , unsigned long V_4 ,
T_8 V_53 )
{
unsigned long V_66 = 0 , V_11 ;
unsigned long V_67 = V_4 ;
int V_68 ;
T_7 * V_48 = V_65 + F_62 ( V_3 ) ;
for ( V_68 = F_62 ( V_3 ) ; V_68 < V_69 ; V_68 ++ , V_3 = V_11 , V_48 ++ ) {
V_11 = ( V_3 & V_44 ) + V_43 ;
if ( V_3 >= V_4 ) {
if ( ! V_40 &&
! F_63 ( V_3 & V_44 , V_11 , V_70 ) &&
! F_63 ( V_3 & V_44 , V_11 , V_71 ) )
F_48 ( V_48 , F_64 ( 0 ) ) ;
continue;
}
if ( F_65 ( * V_48 ) ) {
if ( ! V_40 )
V_66 ++ ;
continue;
}
if ( 0 )
F_39 ( L_12 ,
V_48 , V_3 , F_66 ( V_3 >> V_63 , V_72 ) . V_48 ) ;
V_66 ++ ;
F_48 ( V_48 , F_66 ( V_3 >> V_63 , V_53 ) ) ;
V_67 = ( V_3 & V_44 ) + V_43 ;
}
F_67 ( V_73 , V_66 ) ;
return V_67 ;
}
static unsigned long T_9
F_68 ( T_1 * V_2 , unsigned long V_33 , unsigned long V_4 ,
unsigned long V_74 , T_8 V_53 )
{
unsigned long V_66 = 0 , V_11 ;
unsigned long V_67 = V_4 ;
int V_68 = F_2 ( V_33 ) ;
for (; V_68 < V_75 ; V_68 ++ , V_33 = V_11 ) {
T_1 * V_7 = V_2 + F_2 ( V_33 ) ;
T_7 * V_48 ;
T_8 V_76 = V_53 ;
V_11 = ( V_33 & V_5 ) + V_6 ;
if ( V_33 >= V_4 ) {
if ( ! V_40 &&
! F_63 ( V_33 & V_5 , V_11 , V_70 ) &&
! F_63 ( V_33 & V_5 , V_11 , V_71 ) )
F_4 ( V_7 , F_5 ( 0 ) ) ;
continue;
}
if ( F_69 ( * V_7 ) ) {
if ( ! F_70 ( * V_7 ) ) {
F_25 ( & V_46 . V_38 ) ;
V_48 = ( T_7 * ) F_71 ( * V_7 ) ;
V_67 = F_61 ( V_48 , V_33 ,
V_4 , V_53 ) ;
F_31 ( & V_46 . V_38 ) ;
continue;
}
if ( V_74 & ( 1 << V_77 ) ) {
if ( ! V_40 )
V_66 ++ ;
V_67 = V_11 ;
continue;
}
V_76 = F_72 ( F_73 ( * ( T_7 * ) V_7 ) ) ;
}
if ( V_74 & ( 1 << V_77 ) ) {
V_66 ++ ;
F_25 ( & V_46 . V_38 ) ;
F_48 ( ( T_7 * ) V_7 ,
F_66 ( ( V_33 & V_5 ) >> V_63 ,
F_74 ( F_56 ( V_53 ) | V_78 ) ) ) ;
F_31 ( & V_46 . V_38 ) ;
V_67 = V_11 ;
continue;
}
V_48 = F_75 () ;
V_67 = F_61 ( V_48 , V_33 , V_4 , V_76 ) ;
F_25 ( & V_46 . V_38 ) ;
F_45 ( & V_46 , V_7 , V_48 ) ;
F_31 ( & V_46 . V_38 ) ;
}
F_67 ( V_77 , V_66 ) ;
return V_67 ;
}
static unsigned long T_9
F_76 ( T_2 * V_10 , unsigned long V_3 , unsigned long V_4 ,
unsigned long V_74 )
{
unsigned long V_66 = 0 , V_11 ;
unsigned long V_67 = V_4 ;
int V_68 = F_7 ( V_3 ) ;
for (; V_68 < V_79 ; V_68 ++ , V_3 = V_11 ) {
T_2 * V_12 = V_10 + F_7 ( V_3 ) ;
T_1 * V_7 ;
T_8 V_53 = V_72 ;
V_11 = ( V_3 & V_13 ) + V_14 ;
if ( V_3 >= V_4 ) {
if ( ! V_40 &&
! F_63 ( V_3 & V_13 , V_11 , V_70 ) &&
! F_63 ( V_3 & V_13 , V_11 , V_71 ) )
F_10 ( V_12 , F_11 ( 0 ) ) ;
continue;
}
if ( F_77 ( * V_12 ) ) {
if ( ! F_78 ( * V_12 ) ) {
V_7 = F_9 ( V_12 , 0 ) ;
V_67 = F_68 ( V_7 , V_3 , V_4 ,
V_74 , V_53 ) ;
F_79 () ;
continue;
}
if ( V_74 & ( 1 << V_80 ) ) {
if ( ! V_40 )
V_66 ++ ;
V_67 = V_11 ;
continue;
}
V_53 = F_72 ( F_73 ( * ( T_7 * ) V_12 ) ) ;
}
if ( V_74 & ( 1 << V_80 ) ) {
V_66 ++ ;
F_25 ( & V_46 . V_38 ) ;
F_48 ( ( T_7 * ) V_12 ,
F_66 ( ( V_3 & V_13 ) >> V_63 ,
V_55 ) ) ;
F_31 ( & V_46 . V_38 ) ;
V_67 = V_11 ;
continue;
}
V_7 = F_75 () ;
V_67 = F_68 ( V_7 , V_3 , V_4 , V_74 ,
V_53 ) ;
F_25 ( & V_46 . V_38 ) ;
F_42 ( & V_46 , V_12 , V_7 ) ;
F_31 ( & V_46 . V_38 ) ;
}
F_79 () ;
F_67 ( V_80 , V_66 ) ;
return V_67 ;
}
unsigned long T_9
F_80 ( unsigned long V_32 ,
unsigned long V_4 ,
unsigned long V_74 )
{
bool V_81 = false ;
unsigned long V_11 , V_67 = V_4 ;
unsigned long V_3 ;
V_32 = ( unsigned long ) F_55 ( V_32 ) ;
V_4 = ( unsigned long ) F_55 ( V_4 ) ;
V_3 = V_32 ;
for (; V_32 < V_4 ; V_32 = V_11 ) {
T_3 * V_24 = F_23 ( V_32 ) ;
T_2 * V_12 ;
V_11 = ( V_32 & V_25 ) + V_26 ;
if ( F_81 ( * V_24 ) ) {
V_12 = ( T_2 * ) F_30 ( * V_24 ) ;
V_67 = F_76 ( V_12 , F_12 ( V_32 ) ,
F_12 ( V_4 ) , V_74 ) ;
continue;
}
V_12 = F_75 () ;
V_67 = F_76 ( V_12 , F_12 ( V_32 ) , F_12 ( V_4 ) ,
V_74 ) ;
F_25 ( & V_46 . V_38 ) ;
F_38 ( & V_46 , V_24 , V_12 ) ;
F_31 ( & V_46 . V_38 ) ;
V_81 = true ;
}
if ( V_81 )
F_22 ( V_3 , V_4 - 1 ) ;
F_79 () ;
return V_67 ;
}
void T_4 F_82 ( void )
{
F_83 ( 0 , ( V_82 ) V_83 , 0 ) ;
}
void T_4 F_84 ( void )
{
F_85 ( V_84 ) ;
F_86 () ;
F_87 ( 0 , V_85 ) ;
if ( V_85 != V_86 )
F_87 ( 0 , V_86 ) ;
F_88 () ;
}
static void F_89 ( T_10 V_32 , T_10 V_52 )
{
unsigned long V_87 = F_90 ( V_32 + V_52 ) ;
if ( V_87 > V_88 ) {
V_88 = V_87 ;
V_89 = V_87 ;
V_90 = ( void * ) F_55 ( V_88 * V_43 - 1 ) + 1 ;
}
}
int F_91 ( int V_91 , T_10 V_32 , T_10 V_52 )
{
struct V_92 * V_93 = F_92 ( V_91 ) ;
struct V_94 * V_94 = V_93 -> V_95 + V_96 ;
unsigned long V_97 = V_32 >> V_63 ;
unsigned long V_98 = V_52 >> V_63 ;
int V_99 ;
F_93 ( V_32 , V_32 + V_52 ) ;
V_99 = F_94 ( V_91 , V_94 , V_97 , V_98 ) ;
F_95 ( V_99 ) ;
F_89 ( V_32 , V_52 ) ;
return V_99 ;
}
static void T_9 F_96 ( struct V_35 * V_35 , int V_100 )
{
unsigned long V_101 ;
unsigned int V_98 = 1 << V_100 ;
if ( F_97 ( V_35 ) ) {
F_98 ( V_35 ) ;
V_101 = ( unsigned long ) V_35 -> V_102 . V_11 ;
if ( V_101 == V_103 || V_101 == V_104 ) {
while ( V_98 -- )
F_99 ( V_35 ++ ) ;
} else
while ( V_98 -- )
F_100 ( V_35 ++ ) ;
} else
F_101 ( ( unsigned long ) F_27 ( V_35 ) , V_100 ) ;
}
static void T_9 F_102 ( T_7 * V_105 , T_1 * V_7 )
{
T_7 * V_48 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
V_48 = V_105 + V_68 ;
if ( F_65 ( * V_48 ) )
return;
}
F_96 ( V_2 ( * V_7 ) , 0 ) ;
F_25 ( & V_46 . V_38 ) ;
F_103 ( V_7 ) ;
F_31 ( & V_46 . V_38 ) ;
}
static void T_9 F_104 ( T_1 * V_106 , T_2 * V_12 )
{
T_1 * V_7 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_75 ; V_68 ++ ) {
V_7 = V_106 + V_68 ;
if ( F_69 ( * V_7 ) )
return;
}
F_96 ( V_10 ( * V_12 ) , 0 ) ;
F_25 ( & V_46 . V_38 ) ;
F_105 ( V_12 ) ;
F_31 ( & V_46 . V_38 ) ;
}
static bool T_9 F_106 ( T_2 * V_107 , T_3 * V_24 )
{
T_2 * V_12 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_79 ; V_68 ++ ) {
V_12 = V_107 + V_68 ;
if ( F_77 ( * V_12 ) )
return false ;
}
F_96 ( V_19 ( * V_24 ) , 0 ) ;
F_25 ( & V_46 . V_38 ) ;
F_107 ( V_24 ) ;
F_31 ( & V_46 . V_38 ) ;
return true ;
}
static void T_9
F_108 ( T_7 * V_105 , unsigned long V_3 , unsigned long V_4 ,
bool V_108 )
{
unsigned long V_11 , V_66 = 0 ;
T_7 * V_48 ;
void * V_109 ;
V_82 V_110 ;
V_48 = V_105 + F_62 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_48 ++ ) {
V_11 = ( V_3 + V_43 ) & V_44 ;
if ( V_11 > V_4 )
V_11 = V_4 ;
if ( ! F_109 ( * V_48 ) )
continue;
V_110 = F_65 ( * V_48 ) + ( V_3 & V_44 ) ;
if ( V_110 < ( V_82 ) 0x40000000 )
return;
if ( F_110 ( V_3 , V_43 ) &&
F_110 ( V_11 , V_43 ) ) {
if ( ! V_108 )
F_96 ( V_65 ( * V_48 ) , 0 ) ;
F_25 ( & V_46 . V_38 ) ;
F_111 ( & V_46 , V_3 , V_48 ) ;
F_31 ( & V_46 . V_38 ) ;
V_66 ++ ;
} else {
memset ( ( void * ) V_3 , V_111 , V_11 - V_3 ) ;
V_109 = F_27 ( V_65 ( * V_48 ) ) ;
if ( ! F_112 ( V_109 , V_111 , V_43 ) ) {
F_96 ( V_65 ( * V_48 ) , 0 ) ;
F_25 ( & V_46 . V_38 ) ;
F_111 ( & V_46 , V_3 , V_48 ) ;
F_31 ( & V_46 . V_38 ) ;
}
}
}
F_113 () ;
if ( V_108 )
F_67 ( V_73 , - V_66 ) ;
}
static void T_9
F_114 ( T_1 * V_106 , unsigned long V_3 , unsigned long V_4 ,
bool V_108 )
{
unsigned long V_11 , V_66 = 0 ;
T_7 * V_112 ;
T_1 * V_7 ;
void * V_109 ;
V_7 = V_106 + F_2 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_7 ++ ) {
V_11 = F_115 ( V_3 , V_4 ) ;
if ( ! F_3 ( * V_7 ) )
continue;
if ( F_70 ( * V_7 ) ) {
if ( F_110 ( V_3 , V_6 ) &&
F_110 ( V_11 , V_6 ) ) {
if ( ! V_108 )
F_96 ( V_2 ( * V_7 ) ,
F_116 ( V_6 ) ) ;
F_25 ( & V_46 . V_38 ) ;
F_103 ( V_7 ) ;
F_31 ( & V_46 . V_38 ) ;
V_66 ++ ;
} else {
memset ( ( void * ) V_3 , V_111 , V_11 - V_3 ) ;
V_109 = F_27 ( V_2 ( * V_7 ) ) ;
if ( ! F_112 ( V_109 , V_111 ,
V_6 ) ) {
F_96 ( V_2 ( * V_7 ) ,
F_116 ( V_6 ) ) ;
F_25 ( & V_46 . V_38 ) ;
F_103 ( V_7 ) ;
F_31 ( & V_46 . V_38 ) ;
}
}
continue;
}
V_112 = ( T_7 * ) F_71 ( * V_7 ) ;
F_108 ( V_112 , V_3 , V_11 , V_108 ) ;
F_102 ( V_112 , V_7 ) ;
}
if ( V_108 )
F_67 ( V_77 , - V_66 ) ;
}
static void T_9
F_117 ( T_2 * V_107 , unsigned long V_3 , unsigned long V_4 ,
bool V_108 )
{
unsigned long V_11 , V_66 = 0 ;
T_1 * V_113 ;
T_2 * V_12 ;
void * V_109 ;
V_12 = V_107 + F_7 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_12 ++ ) {
V_11 = F_118 ( V_3 , V_4 ) ;
if ( ! F_8 ( * V_12 ) )
continue;
if ( F_78 ( * V_12 ) ) {
if ( F_110 ( V_3 , V_14 ) &&
F_110 ( V_11 , V_14 ) ) {
if ( ! V_108 )
F_96 ( V_10 ( * V_12 ) ,
F_116 ( V_14 ) ) ;
F_25 ( & V_46 . V_38 ) ;
F_105 ( V_12 ) ;
F_31 ( & V_46 . V_38 ) ;
V_66 ++ ;
} else {
memset ( ( void * ) V_3 , V_111 , V_11 - V_3 ) ;
V_109 = F_27 ( V_10 ( * V_12 ) ) ;
if ( ! F_112 ( V_109 , V_111 ,
V_14 ) ) {
F_96 ( V_10 ( * V_12 ) ,
F_116 ( V_14 ) ) ;
F_25 ( & V_46 . V_38 ) ;
F_105 ( V_12 ) ;
F_31 ( & V_46 . V_38 ) ;
}
}
continue;
}
V_113 = ( T_1 * ) F_119 ( * V_12 ) ;
F_114 ( V_113 , V_3 , V_11 , V_108 ) ;
F_104 ( V_113 , V_12 ) ;
}
if ( V_108 )
F_67 ( V_80 , - V_66 ) ;
}
static void T_9
F_120 ( unsigned long V_32 , unsigned long V_4 , bool V_108 )
{
unsigned long V_11 ;
T_3 * V_24 ;
T_2 * V_12 ;
bool V_81 = false ;
for (; V_32 < V_4 ; V_32 = V_11 ) {
V_11 = F_121 ( V_32 , V_4 ) ;
V_24 = F_23 ( V_32 ) ;
if ( ! F_15 ( * V_24 ) )
continue;
V_12 = ( T_2 * ) F_30 ( * V_24 ) ;
F_117 ( V_12 , V_32 , V_11 , V_108 ) ;
if ( F_106 ( V_12 , V_24 ) )
V_81 = true ;
}
if ( V_81 )
F_22 ( V_32 , V_4 - 1 ) ;
F_113 () ;
}
void T_6 F_122 ( unsigned long V_32 , unsigned long V_4 )
{
F_120 ( V_32 , V_4 , false ) ;
}
static void T_9
F_123 ( unsigned long V_32 , unsigned long V_4 )
{
V_32 = ( unsigned long ) F_55 ( V_32 ) ;
V_4 = ( unsigned long ) F_55 ( V_4 ) ;
F_120 ( V_32 , V_4 , true ) ;
}
int T_6 F_124 ( T_10 V_32 , T_10 V_52 )
{
unsigned long V_97 = V_32 >> V_63 ;
unsigned long V_98 = V_52 >> V_63 ;
struct V_94 * V_94 ;
int V_99 ;
V_94 = F_125 ( F_126 ( V_97 ) ) ;
F_123 ( V_32 , V_32 + V_52 ) ;
V_99 = F_127 ( V_94 , V_97 , V_98 ) ;
F_95 ( V_99 ) ;
return V_99 ;
}
static void T_4 F_128 ( void )
{
#ifdef F_129
int V_68 ;
F_130 (i)
F_131 ( F_92 ( V_68 ) ) ;
#endif
}
void T_4 F_132 ( void )
{
F_133 () ;
F_128 () ;
F_134 () ;
V_40 = 1 ;
F_135 ( & V_114 , ( void * ) V_115 ,
V_116 - V_115 , V_117 ) ;
F_136 ( NULL ) ;
}
void F_137 ( void )
{
unsigned long V_32 = F_138 ( V_64 ) ;
unsigned long V_4 = F_138 ( V_118 ) ;
if ( ! V_119 )
return;
F_36 ( L_13 ,
V_32 , V_4 ) ;
F_139 ( V_32 , ( V_4 - V_32 ) >> V_63 ) ;
}
void F_140 ( void )
{
unsigned long V_32 = F_138 ( V_64 ) ;
unsigned long V_4 = F_138 ( V_118 ) ;
if ( ! V_119 )
return;
F_36 ( L_14 ,
V_32 , V_4 ) ;
F_141 ( V_32 , ( V_4 - V_32 ) >> V_63 ) ;
}
void F_142 ( void )
{
unsigned long V_32 = F_138 ( V_64 ) ;
unsigned long V_120 = F_138 ( V_121 ) ;
unsigned long V_4 = ( unsigned long ) & V_122 ;
unsigned long V_123 = F_138 ( & V_118 ) ;
unsigned long V_124 = F_138 ( & V_125 ) ;
unsigned long V_126 = F_138 ( & V_127 ) ;
F_39 ( V_128 L_15 ,
( V_4 - V_32 ) >> 10 ) ;
F_141 ( V_32 , ( V_4 - V_32 ) >> V_63 ) ;
V_119 = 1 ;
F_143 ( V_120 , ( V_126 - V_120 ) >> V_63 ) ;
F_144 () ;
#ifdef F_145
F_39 ( V_128 L_16 , V_32 , V_4 ) ;
F_139 ( V_32 , ( V_4 - V_32 ) >> V_63 ) ;
F_39 ( V_128 L_17 ) ;
F_141 ( V_32 , ( V_4 - V_32 ) >> V_63 ) ;
#endif
F_146 ( L_18 ,
( unsigned long ) F_55 ( F_147 ( V_123 ) ) ,
( unsigned long ) F_55 ( F_147 ( V_120 ) ) ) ;
F_146 ( L_18 ,
( unsigned long ) F_55 ( F_147 ( V_124 ) ) ,
( unsigned long ) F_55 ( F_147 ( V_129 ) ) ) ;
}
int F_148 ( unsigned long V_3 )
{
unsigned long V_130 = ( ( long ) V_3 ) >> V_131 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
T_7 * V_48 ;
if ( V_130 != 0 && V_130 != - 1UL )
return 0 ;
V_24 = F_23 ( V_3 ) ;
if ( F_24 ( * V_24 ) )
return 0 ;
V_12 = F_16 ( V_24 , V_3 ) ;
if ( F_41 ( * V_12 ) )
return 0 ;
if ( F_78 ( * V_12 ) )
return F_149 ( F_150 ( * V_12 ) ) ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_44 ( * V_7 ) )
return 0 ;
if ( F_70 ( * V_7 ) )
return F_149 ( F_151 ( * V_7 ) ) ;
V_48 = F_46 ( V_7 , V_3 ) ;
if ( F_152 ( * V_48 ) )
return 0 ;
return F_149 ( F_153 ( * V_48 ) ) ;
}
struct V_132 * F_154 ( struct V_133 * V_134 )
{
#ifdef F_155
if ( ! V_134 || V_134 -> V_16 . V_135 )
return NULL ;
#endif
return & V_136 ;
}
int F_156 ( struct V_133 * V_134 , unsigned long V_3 )
{
struct V_132 * V_137 = F_154 ( V_134 ) ;
if ( ! V_137 )
return 0 ;
return ( V_3 >= V_137 -> V_138 ) && ( V_3 < V_137 -> V_139 ) ;
}
int F_157 ( unsigned long V_3 )
{
return ( V_3 >= V_115 ) && ( V_3 < V_116 ) ;
}
const char * F_158 ( struct V_132 * V_137 )
{
if ( V_137 -> V_140 && V_137 -> V_138 == ( long ) V_137 -> V_140 -> V_16 . V_141 )
return L_19 ;
if ( V_137 == & V_136 )
return L_20 ;
return NULL ;
}
unsigned long F_159 ( void )
{
if ( F_160 () ) {
F_39 ( V_128 L_21 ) ;
return 2UL * 1024 * 1024 * 1024 ;
}
return V_142 ;
}
static int T_9 F_161 ( unsigned long V_32 ,
unsigned long V_4 , int V_143 )
{
unsigned long V_3 ;
unsigned long V_11 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
for ( V_3 = V_32 ; V_3 < V_4 ; V_3 = V_11 ) {
V_11 = F_115 ( V_3 , V_4 ) ;
V_24 = F_162 ( V_3 , V_143 ) ;
if ( ! V_24 )
return - V_17 ;
V_12 = F_163 ( V_24 , V_3 , V_143 ) ;
if ( ! V_12 )
return - V_17 ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_44 ( * V_7 ) ) {
void * V_144 ;
V_144 = F_164 ( V_6 , V_143 ) ;
if ( V_144 ) {
T_7 V_145 ;
V_145 = F_66 ( F_12 ( V_144 ) >> V_63 ,
V_55 ) ;
F_4 ( V_7 , F_5 ( F_65 ( V_145 ) ) ) ;
if ( V_146 != V_144 || V_147 != V_143 ) {
if ( V_148 )
F_39 ( V_149 L_22 ,
V_150 , V_151 - 1 , V_148 , V_146 - 1 , V_147 ) ;
V_150 = V_3 ;
V_147 = V_143 ;
V_148 = V_144 ;
}
V_151 = V_3 + V_6 ;
V_146 = V_144 + V_6 ;
continue;
}
} else if ( F_70 ( * V_7 ) ) {
F_165 ( ( T_7 * ) V_7 , V_143 , V_3 , V_11 ) ;
continue;
}
F_166 ( L_23 ) ;
if ( F_167 ( V_3 , V_11 , V_143 ) )
return - V_17 ;
}
return 0 ;
}
int T_9 F_168 ( unsigned long V_32 , unsigned long V_4 , int V_143 )
{
int V_152 ;
if ( V_153 )
V_152 = F_161 ( V_32 , V_4 , V_143 ) ;
else
V_152 = F_167 ( V_32 , V_4 , V_143 ) ;
if ( ! V_152 )
F_22 ( V_32 , V_4 - 1 ) ;
return V_152 ;
}
void F_169 ( unsigned long V_154 ,
struct V_35 * V_155 , unsigned long V_52 )
{
unsigned long V_3 = ( unsigned long ) V_155 ;
unsigned long V_4 = ( unsigned long ) ( V_155 + V_52 ) ;
unsigned long V_11 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
unsigned int V_98 ;
struct V_35 * V_35 ;
for (; V_3 < V_4 ; V_3 = V_11 ) {
T_7 * V_48 = NULL ;
V_24 = F_23 ( V_3 ) ;
if ( F_24 ( * V_24 ) ) {
V_11 = ( V_3 + V_43 ) & V_44 ;
continue;
}
F_170 ( V_154 , V_19 ( * V_24 ) , V_104 ) ;
V_12 = F_16 ( V_24 , V_3 ) ;
if ( F_41 ( * V_12 ) ) {
V_11 = ( V_3 + V_43 ) & V_44 ;
continue;
}
F_170 ( V_154 , V_10 ( * V_12 ) , V_104 ) ;
if ( ! V_153 ) {
V_11 = ( V_3 + V_43 ) & V_44 ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_44 ( * V_7 ) )
continue;
F_170 ( V_154 , V_2 ( * V_7 ) ,
V_104 ) ;
V_48 = F_46 ( V_7 , V_3 ) ;
if ( F_152 ( * V_48 ) )
continue;
F_170 ( V_154 , V_65 ( * V_48 ) ,
V_103 ) ;
} else {
V_11 = F_115 ( V_3 , V_4 ) ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_44 ( * V_7 ) )
continue;
V_98 = 1 << ( F_116 ( V_6 ) ) ;
V_35 = V_2 ( * V_7 ) ;
while ( V_98 -- )
F_170 ( V_154 , V_35 ++ ,
V_103 ) ;
}
}
}
void T_9 F_171 ( void )
{
if ( V_148 ) {
F_39 ( V_149 L_22 ,
V_150 , V_151 - 1 , V_148 , V_146 - 1 , V_147 ) ;
V_148 = NULL ;
V_146 = NULL ;
V_147 = 0 ;
}
}
