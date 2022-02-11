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
F_83 ( 0 , ( V_82 ) V_83 , & V_84 . V_85 , 0 ) ;
}
void T_4 F_84 ( void )
{
F_85 ( V_86 ) ;
F_86 () ;
F_87 ( 0 , V_87 ) ;
if ( V_87 != V_88 )
F_87 ( 0 , V_88 ) ;
F_88 () ;
}
static void F_89 ( T_10 V_32 , T_10 V_52 )
{
unsigned long V_89 = F_90 ( V_32 + V_52 ) ;
if ( V_89 > V_90 ) {
V_90 = V_89 ;
V_91 = V_89 ;
V_92 = ( void * ) F_55 ( V_90 * V_43 - 1 ) + 1 ;
}
}
int F_91 ( int V_93 , T_10 V_32 , T_10 V_52 )
{
struct V_94 * V_95 = F_92 ( V_93 ) ;
struct V_96 * V_96 = V_95 -> V_97 + V_98 ;
unsigned long V_99 = V_32 >> V_63 ;
unsigned long V_100 = V_52 >> V_63 ;
int V_101 ;
F_93 ( V_32 , V_32 + V_52 ) ;
V_101 = F_94 ( V_93 , V_96 , V_99 , V_100 ) ;
F_95 ( V_101 ) ;
F_89 ( V_32 , V_52 ) ;
return V_101 ;
}
static void T_9 F_96 ( struct V_35 * V_35 , int V_102 )
{
unsigned long V_103 ;
unsigned int V_100 = 1 << V_102 ;
if ( F_97 ( V_35 ) ) {
F_98 ( V_35 ) ;
V_103 = ( unsigned long ) V_35 -> V_104 . V_11 ;
if ( V_103 == V_105 || V_103 == V_106 ) {
while ( V_100 -- )
F_99 ( V_35 ++ ) ;
} else
while ( V_100 -- )
F_100 ( V_35 ++ ) ;
} else
F_101 ( ( unsigned long ) F_27 ( V_35 ) , V_102 ) ;
}
static void T_9 F_102 ( T_7 * V_107 , T_1 * V_7 )
{
T_7 * V_48 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ ) {
V_48 = V_107 + V_68 ;
if ( F_65 ( * V_48 ) )
return;
}
F_96 ( V_2 ( * V_7 ) , 0 ) ;
F_25 ( & V_46 . V_38 ) ;
F_103 ( V_7 ) ;
F_31 ( & V_46 . V_38 ) ;
}
static void T_9 F_104 ( T_1 * V_108 , T_2 * V_12 )
{
T_1 * V_7 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_75 ; V_68 ++ ) {
V_7 = V_108 + V_68 ;
if ( F_69 ( * V_7 ) )
return;
}
F_96 ( V_10 ( * V_12 ) , 0 ) ;
F_25 ( & V_46 . V_38 ) ;
F_105 ( V_12 ) ;
F_31 ( & V_46 . V_38 ) ;
}
static bool T_9 F_106 ( T_2 * V_109 , T_3 * V_24 )
{
T_2 * V_12 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_79 ; V_68 ++ ) {
V_12 = V_109 + V_68 ;
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
F_108 ( T_7 * V_107 , unsigned long V_3 , unsigned long V_4 ,
bool V_110 )
{
unsigned long V_11 , V_66 = 0 ;
T_7 * V_48 ;
void * V_111 ;
V_82 V_112 ;
V_48 = V_107 + F_62 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_48 ++ ) {
V_11 = ( V_3 + V_43 ) & V_44 ;
if ( V_11 > V_4 )
V_11 = V_4 ;
if ( ! F_109 ( * V_48 ) )
continue;
V_112 = F_65 ( * V_48 ) + ( V_3 & V_44 ) ;
if ( V_112 < ( V_82 ) 0x40000000 )
return;
if ( F_110 ( V_3 , V_43 ) &&
F_110 ( V_11 , V_43 ) ) {
if ( ! V_110 )
F_96 ( V_65 ( * V_48 ) , 0 ) ;
F_25 ( & V_46 . V_38 ) ;
F_111 ( & V_46 , V_3 , V_48 ) ;
F_31 ( & V_46 . V_38 ) ;
V_66 ++ ;
} else {
memset ( ( void * ) V_3 , V_113 , V_11 - V_3 ) ;
V_111 = F_27 ( V_65 ( * V_48 ) ) ;
if ( ! F_112 ( V_111 , V_113 , V_43 ) ) {
F_96 ( V_65 ( * V_48 ) , 0 ) ;
F_25 ( & V_46 . V_38 ) ;
F_111 ( & V_46 , V_3 , V_48 ) ;
F_31 ( & V_46 . V_38 ) ;
}
}
}
F_113 () ;
if ( V_110 )
F_67 ( V_73 , - V_66 ) ;
}
static void T_9
F_114 ( T_1 * V_108 , unsigned long V_3 , unsigned long V_4 ,
bool V_110 )
{
unsigned long V_11 , V_66 = 0 ;
T_7 * V_114 ;
T_1 * V_7 ;
void * V_111 ;
V_7 = V_108 + F_2 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_7 ++ ) {
V_11 = F_115 ( V_3 , V_4 ) ;
if ( ! F_3 ( * V_7 ) )
continue;
if ( F_70 ( * V_7 ) ) {
if ( F_110 ( V_3 , V_6 ) &&
F_110 ( V_11 , V_6 ) ) {
if ( ! V_110 )
F_96 ( V_2 ( * V_7 ) ,
F_116 ( V_6 ) ) ;
F_25 ( & V_46 . V_38 ) ;
F_103 ( V_7 ) ;
F_31 ( & V_46 . V_38 ) ;
V_66 ++ ;
} else {
memset ( ( void * ) V_3 , V_113 , V_11 - V_3 ) ;
V_111 = F_27 ( V_2 ( * V_7 ) ) ;
if ( ! F_112 ( V_111 , V_113 ,
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
V_114 = ( T_7 * ) F_71 ( * V_7 ) ;
F_108 ( V_114 , V_3 , V_11 , V_110 ) ;
F_102 ( V_114 , V_7 ) ;
}
if ( V_110 )
F_67 ( V_77 , - V_66 ) ;
}
static void T_9
F_117 ( T_2 * V_109 , unsigned long V_3 , unsigned long V_4 ,
bool V_110 )
{
unsigned long V_11 , V_66 = 0 ;
T_1 * V_115 ;
T_2 * V_12 ;
void * V_111 ;
V_12 = V_109 + F_7 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_12 ++ ) {
V_11 = F_118 ( V_3 , V_4 ) ;
if ( ! F_8 ( * V_12 ) )
continue;
if ( F_78 ( * V_12 ) ) {
if ( F_110 ( V_3 , V_14 ) &&
F_110 ( V_11 , V_14 ) ) {
if ( ! V_110 )
F_96 ( V_10 ( * V_12 ) ,
F_116 ( V_14 ) ) ;
F_25 ( & V_46 . V_38 ) ;
F_105 ( V_12 ) ;
F_31 ( & V_46 . V_38 ) ;
V_66 ++ ;
} else {
memset ( ( void * ) V_3 , V_113 , V_11 - V_3 ) ;
V_111 = F_27 ( V_10 ( * V_12 ) ) ;
if ( ! F_112 ( V_111 , V_113 ,
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
V_115 = ( T_1 * ) F_119 ( * V_12 ) ;
F_114 ( V_115 , V_3 , V_11 , V_110 ) ;
F_104 ( V_115 , V_12 ) ;
}
if ( V_110 )
F_67 ( V_80 , - V_66 ) ;
}
static void T_9
F_120 ( unsigned long V_32 , unsigned long V_4 , bool V_110 )
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
F_117 ( V_12 , V_32 , V_11 , V_110 ) ;
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
unsigned long V_99 = V_32 >> V_63 ;
unsigned long V_100 = V_52 >> V_63 ;
struct V_96 * V_96 ;
int V_101 ;
V_96 = F_125 ( F_126 ( V_99 ) ) ;
F_123 ( V_32 , V_32 + V_52 ) ;
V_101 = F_127 ( V_96 , V_99 , V_100 ) ;
F_95 ( V_101 ) ;
return V_101 ;
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
F_135 ( & V_116 , ( void * ) V_117 ,
V_118 - V_117 , V_119 ) ;
F_136 ( NULL ) ;
}
void F_137 ( void )
{
unsigned long V_32 = F_138 ( V_64 ) ;
unsigned long V_4 = F_138 ( V_120 ) ;
if ( ! V_121 )
return;
F_36 ( L_13 ,
V_32 , V_4 ) ;
F_139 ( V_32 , ( V_4 - V_32 ) >> V_63 ) ;
}
void F_140 ( void )
{
unsigned long V_32 = F_138 ( V_64 ) ;
unsigned long V_4 = F_138 ( V_120 ) ;
if ( ! V_121 )
return;
F_36 ( L_14 ,
V_32 , V_4 ) ;
F_141 ( V_32 , ( V_4 - V_32 ) >> V_63 ) ;
}
void F_142 ( void )
{
unsigned long V_32 = F_138 ( V_64 ) ;
unsigned long V_122 = F_138 ( V_123 ) ;
unsigned long V_4 = ( unsigned long ) & V_124 ;
unsigned long V_125 = F_138 ( & V_120 ) ;
unsigned long V_126 = F_138 ( & V_127 ) ;
unsigned long V_128 = F_138 ( & V_129 ) ;
F_39 ( V_130 L_15 ,
( V_4 - V_32 ) >> 10 ) ;
F_141 ( V_32 , ( V_4 - V_32 ) >> V_63 ) ;
V_121 = 1 ;
F_143 ( V_122 , ( V_128 - V_122 ) >> V_63 ) ;
F_144 () ;
#ifdef F_145
F_39 ( V_130 L_16 , V_32 , V_4 ) ;
F_139 ( V_32 , ( V_4 - V_32 ) >> V_63 ) ;
F_39 ( V_130 L_17 ) ;
F_141 ( V_32 , ( V_4 - V_32 ) >> V_63 ) ;
#endif
F_146 ( L_18 ,
( unsigned long ) F_55 ( F_147 ( V_125 ) ) ,
( unsigned long ) F_55 ( F_147 ( V_122 ) ) ) ;
F_146 ( L_18 ,
( unsigned long ) F_55 ( F_147 ( V_126 ) ) ,
( unsigned long ) F_55 ( F_147 ( V_131 ) ) ) ;
}
int F_148 ( unsigned long V_3 )
{
unsigned long V_132 = ( ( long ) V_3 ) >> V_133 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
T_7 * V_48 ;
if ( V_132 != 0 && V_132 != - 1UL )
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
struct V_134 * F_154 ( struct V_135 * V_136 )
{
#ifdef F_155
if ( ! V_136 || V_136 -> V_16 . V_137 )
return NULL ;
#endif
return & V_138 ;
}
int F_156 ( struct V_135 * V_136 , unsigned long V_3 )
{
struct V_134 * V_139 = F_154 ( V_136 ) ;
if ( ! V_139 )
return 0 ;
return ( V_3 >= V_139 -> V_140 ) && ( V_3 < V_139 -> V_141 ) ;
}
int F_157 ( unsigned long V_3 )
{
return ( V_3 >= V_117 ) && ( V_3 < V_118 ) ;
}
const char * F_158 ( struct V_134 * V_139 )
{
if ( V_139 -> V_142 && V_139 -> V_140 == ( long ) V_139 -> V_142 -> V_16 . V_143 )
return L_19 ;
if ( V_139 == & V_138 )
return L_20 ;
return NULL ;
}
unsigned long F_159 ( void )
{
if ( F_160 () ) {
F_39 ( V_130 L_21 ) ;
return 2UL * 1024 * 1024 * 1024 ;
}
return V_144 ;
}
static int T_9 F_161 ( unsigned long V_32 ,
unsigned long V_4 , int V_145 )
{
unsigned long V_3 ;
unsigned long V_11 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
for ( V_3 = V_32 ; V_3 < V_4 ; V_3 = V_11 ) {
V_11 = F_115 ( V_3 , V_4 ) ;
V_24 = F_162 ( V_3 , V_145 ) ;
if ( ! V_24 )
return - V_17 ;
V_12 = F_163 ( V_24 , V_3 , V_145 ) ;
if ( ! V_12 )
return - V_17 ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_44 ( * V_7 ) ) {
void * V_146 ;
V_146 = F_164 ( V_6 , V_145 ) ;
if ( V_146 ) {
T_7 V_147 ;
V_147 = F_66 ( F_12 ( V_146 ) >> V_63 ,
V_55 ) ;
F_4 ( V_7 , F_5 ( F_65 ( V_147 ) ) ) ;
if ( V_148 != V_146 || V_149 != V_145 ) {
if ( V_150 )
F_39 ( V_151 L_22 ,
V_152 , V_153 - 1 , V_150 , V_148 - 1 , V_149 ) ;
V_152 = V_3 ;
V_149 = V_145 ;
V_150 = V_146 ;
}
V_153 = V_3 + V_6 ;
V_148 = V_146 + V_6 ;
continue;
}
} else if ( F_70 ( * V_7 ) ) {
F_165 ( ( T_7 * ) V_7 , V_145 , V_3 , V_11 ) ;
continue;
}
F_166 ( L_23 ) ;
if ( F_167 ( V_3 , V_11 , V_145 ) )
return - V_17 ;
}
return 0 ;
}
int T_9 F_168 ( unsigned long V_32 , unsigned long V_4 , int V_145 )
{
int V_154 ;
if ( V_155 )
V_154 = F_161 ( V_32 , V_4 , V_145 ) ;
else
V_154 = F_167 ( V_32 , V_4 , V_145 ) ;
if ( ! V_154 )
F_22 ( V_32 , V_4 - 1 ) ;
return V_154 ;
}
void F_169 ( unsigned long V_156 ,
struct V_35 * V_157 , unsigned long V_52 )
{
unsigned long V_3 = ( unsigned long ) V_157 ;
unsigned long V_4 = ( unsigned long ) ( V_157 + V_52 ) ;
unsigned long V_11 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
unsigned int V_100 ;
struct V_35 * V_35 ;
for (; V_3 < V_4 ; V_3 = V_11 ) {
T_7 * V_48 = NULL ;
V_24 = F_23 ( V_3 ) ;
if ( F_24 ( * V_24 ) ) {
V_11 = ( V_3 + V_43 ) & V_44 ;
continue;
}
F_170 ( V_156 , V_19 ( * V_24 ) , V_106 ) ;
V_12 = F_16 ( V_24 , V_3 ) ;
if ( F_41 ( * V_12 ) ) {
V_11 = ( V_3 + V_43 ) & V_44 ;
continue;
}
F_170 ( V_156 , V_10 ( * V_12 ) , V_106 ) ;
if ( ! V_155 ) {
V_11 = ( V_3 + V_43 ) & V_44 ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_44 ( * V_7 ) )
continue;
F_170 ( V_156 , V_2 ( * V_7 ) ,
V_106 ) ;
V_48 = F_46 ( V_7 , V_3 ) ;
if ( F_152 ( * V_48 ) )
continue;
F_170 ( V_156 , V_65 ( * V_48 ) ,
V_105 ) ;
} else {
V_11 = F_115 ( V_3 , V_4 ) ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_44 ( * V_7 ) )
continue;
V_100 = 1 << ( F_116 ( V_6 ) ) ;
V_35 = V_2 ( * V_7 ) ;
while ( V_100 -- )
F_170 ( V_156 , V_35 ++ ,
V_105 ) ;
}
}
}
void T_9 F_171 ( void )
{
if ( V_150 ) {
F_39 ( V_151 L_22 ,
V_152 , V_153 - 1 , V_150 , V_148 - 1 , V_149 ) ;
V_150 = NULL ;
V_148 = NULL ;
V_149 = 0 ;
}
}
