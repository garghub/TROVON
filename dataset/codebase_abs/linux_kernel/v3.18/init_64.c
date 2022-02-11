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
T_8 V_54 )
{
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
F_29 ( ( V_52 & ~ V_5 ) || ( V_53 & ~ V_5 ) ) ;
for (; V_53 ; V_52 += V_6 , V_53 -= V_6 ) {
V_24 = F_23 ( ( unsigned long ) F_56 ( V_52 ) ) ;
if ( F_24 ( * V_24 ) ) {
V_12 = ( T_2 * ) F_33 () ;
F_17 ( V_24 , F_18 ( F_12 ( V_12 ) | V_18 |
V_55 ) ) ;
}
V_12 = F_16 ( V_24 , ( unsigned long ) F_56 ( V_52 ) ) ;
if ( F_42 ( * V_12 ) ) {
V_7 = ( T_1 * ) F_33 () ;
F_10 ( V_12 , F_11 ( F_12 ( V_7 ) | V_18 |
V_55 ) ) ;
}
V_7 = F_9 ( V_12 , V_52 ) ;
F_29 ( ! F_45 ( * V_7 ) ) ;
F_4 ( V_7 , F_5 ( V_52 | F_57 ( V_54 ) ) ) ;
}
}
void T_4 F_58 ( unsigned long V_52 , unsigned long V_53 )
{
F_55 ( V_52 , V_53 , V_56 ) ;
}
void T_4 F_59 ( unsigned long V_52 , unsigned long V_53 )
{
F_55 ( V_52 , V_53 , V_57 ) ;
}
void T_4 F_60 ( void )
{
unsigned long V_46 = V_58 ;
unsigned long V_59 = V_58 + V_60 ;
unsigned long V_4 = F_61 ( ( unsigned long ) V_61 , V_6 ) - 1 ;
T_1 * V_7 = V_62 ;
if ( V_63 )
V_59 = V_58 + ( V_63 << V_64 ) ;
for (; V_46 + V_6 - 1 < V_59 ; V_7 ++ , V_46 += V_6 ) {
if ( F_45 ( * V_7 ) )
continue;
if ( V_46 < ( unsigned long ) V_65 || V_46 > V_4 )
F_4 ( V_7 , F_5 ( 0 ) ) ;
}
}
static unsigned long T_9
F_62 ( T_7 * V_66 , unsigned long V_3 , unsigned long V_4 ,
T_8 V_54 )
{
unsigned long V_67 = 0 , V_11 ;
unsigned long V_68 = V_4 ;
int V_69 ;
T_7 * V_49 = V_66 + F_63 ( V_3 ) ;
for ( V_69 = F_63 ( V_3 ) ; V_69 < V_70 ; V_69 ++ , V_3 = V_11 , V_49 ++ ) {
V_11 = ( V_3 & V_45 ) + V_44 ;
if ( V_3 >= V_4 ) {
if ( ! V_41 &&
! F_64 ( V_3 & V_45 , V_11 , V_71 ) &&
! F_64 ( V_3 & V_45 , V_11 , V_72 ) )
F_49 ( V_49 , F_65 ( 0 ) ) ;
continue;
}
if ( F_66 ( * V_49 ) ) {
if ( ! V_41 )
V_67 ++ ;
continue;
}
if ( 0 )
F_40 ( L_12 ,
V_49 , V_3 , F_67 ( V_3 >> V_64 , V_73 ) . V_49 ) ;
V_67 ++ ;
F_49 ( V_49 , F_67 ( V_3 >> V_64 , V_54 ) ) ;
V_68 = ( V_3 & V_45 ) + V_44 ;
}
F_68 ( V_74 , V_67 ) ;
return V_68 ;
}
static unsigned long T_9
F_69 ( T_1 * V_2 , unsigned long V_34 , unsigned long V_4 ,
unsigned long V_75 , T_8 V_54 )
{
unsigned long V_67 = 0 , V_11 ;
unsigned long V_68 = V_4 ;
int V_69 = F_2 ( V_34 ) ;
for (; V_69 < V_76 ; V_69 ++ , V_34 = V_11 ) {
T_1 * V_7 = V_2 + F_2 ( V_34 ) ;
T_7 * V_49 ;
T_8 V_77 = V_54 ;
V_11 = ( V_34 & V_5 ) + V_6 ;
if ( V_34 >= V_4 ) {
if ( ! V_41 &&
! F_64 ( V_34 & V_5 , V_11 , V_71 ) &&
! F_64 ( V_34 & V_5 , V_11 , V_72 ) )
F_4 ( V_7 , F_5 ( 0 ) ) ;
continue;
}
if ( F_70 ( * V_7 ) ) {
if ( ! F_71 ( * V_7 ) ) {
F_25 ( & V_47 . V_39 ) ;
V_49 = ( T_7 * ) F_72 ( * V_7 ) ;
V_68 = F_62 ( V_49 , V_34 ,
V_4 , V_54 ) ;
F_32 ( & V_47 . V_39 ) ;
continue;
}
if ( V_75 & ( 1 << V_78 ) ) {
if ( ! V_41 )
V_67 ++ ;
V_68 = V_11 ;
continue;
}
V_77 = F_73 ( F_74 ( * ( T_7 * ) V_7 ) ) ;
}
if ( V_75 & ( 1 << V_78 ) ) {
V_67 ++ ;
F_25 ( & V_47 . V_39 ) ;
F_49 ( ( T_7 * ) V_7 ,
F_67 ( ( V_34 & V_5 ) >> V_64 ,
F_75 ( F_57 ( V_54 ) | V_79 ) ) ) ;
F_32 ( & V_47 . V_39 ) ;
V_68 = V_11 ;
continue;
}
V_49 = F_76 () ;
V_68 = F_62 ( V_49 , V_34 , V_4 , V_77 ) ;
F_25 ( & V_47 . V_39 ) ;
F_46 ( & V_47 , V_7 , V_49 ) ;
F_32 ( & V_47 . V_39 ) ;
}
F_68 ( V_78 , V_67 ) ;
return V_68 ;
}
static unsigned long T_9
F_77 ( T_2 * V_10 , unsigned long V_3 , unsigned long V_4 ,
unsigned long V_75 )
{
unsigned long V_67 = 0 , V_11 ;
unsigned long V_68 = V_4 ;
int V_69 = F_7 ( V_3 ) ;
for (; V_69 < V_80 ; V_69 ++ , V_3 = V_11 ) {
T_2 * V_12 = V_10 + F_7 ( V_3 ) ;
T_1 * V_7 ;
T_8 V_54 = V_73 ;
V_11 = ( V_3 & V_13 ) + V_14 ;
if ( V_3 >= V_4 ) {
if ( ! V_41 &&
! F_64 ( V_3 & V_13 , V_11 , V_71 ) &&
! F_64 ( V_3 & V_13 , V_11 , V_72 ) )
F_10 ( V_12 , F_11 ( 0 ) ) ;
continue;
}
if ( F_78 ( * V_12 ) ) {
if ( ! F_79 ( * V_12 ) ) {
V_7 = F_9 ( V_12 , 0 ) ;
V_68 = F_69 ( V_7 , V_3 , V_4 ,
V_75 , V_54 ) ;
F_80 () ;
continue;
}
if ( V_75 & ( 1 << V_81 ) ) {
if ( ! V_41 )
V_67 ++ ;
V_68 = V_11 ;
continue;
}
V_54 = F_73 ( F_74 ( * ( T_7 * ) V_12 ) ) ;
}
if ( V_75 & ( 1 << V_81 ) ) {
V_67 ++ ;
F_25 ( & V_47 . V_39 ) ;
F_49 ( ( T_7 * ) V_12 ,
F_67 ( ( V_3 & V_13 ) >> V_64 ,
V_56 ) ) ;
F_32 ( & V_47 . V_39 ) ;
V_68 = V_11 ;
continue;
}
V_7 = F_76 () ;
V_68 = F_69 ( V_7 , V_3 , V_4 , V_75 ,
V_54 ) ;
F_25 ( & V_47 . V_39 ) ;
F_43 ( & V_47 , V_12 , V_7 ) ;
F_32 ( & V_47 . V_39 ) ;
}
F_80 () ;
F_68 ( V_81 , V_67 ) ;
return V_68 ;
}
unsigned long T_9
F_81 ( unsigned long V_32 ,
unsigned long V_4 ,
unsigned long V_75 )
{
bool V_82 = false ;
unsigned long V_11 , V_68 = V_4 ;
unsigned long V_3 ;
V_32 = ( unsigned long ) F_56 ( V_32 ) ;
V_4 = ( unsigned long ) F_56 ( V_4 ) ;
V_3 = V_32 ;
for (; V_32 < V_4 ; V_32 = V_11 ) {
T_3 * V_24 = F_23 ( V_32 ) ;
T_2 * V_12 ;
V_11 = ( V_32 & V_25 ) + V_26 ;
if ( F_82 ( * V_24 ) ) {
V_12 = ( T_2 * ) F_30 ( * V_24 ) ;
V_68 = F_77 ( V_12 , F_12 ( V_32 ) ,
F_12 ( V_4 ) , V_75 ) ;
continue;
}
V_12 = F_76 () ;
V_68 = F_77 ( V_12 , F_12 ( V_32 ) , F_12 ( V_4 ) ,
V_75 ) ;
F_25 ( & V_47 . V_39 ) ;
F_39 ( & V_47 , V_24 , V_12 ) ;
F_32 ( & V_47 . V_39 ) ;
V_82 = true ;
}
if ( V_82 )
F_22 ( V_3 , V_4 - 1 , 0 ) ;
F_80 () ;
return V_68 ;
}
void T_4 F_83 ( void )
{
F_84 ( 0 , ( V_83 ) V_84 , & V_85 . V_86 , 0 ) ;
}
void T_4 F_85 ( void )
{
F_86 ( V_87 ) ;
F_87 () ;
F_88 ( 0 , V_88 ) ;
if ( V_88 != V_89 )
F_88 ( 0 , V_89 ) ;
F_89 () ;
}
static void F_90 ( T_10 V_32 , T_10 V_53 )
{
unsigned long V_90 = F_91 ( V_32 + V_53 ) ;
if ( V_90 > V_91 ) {
V_91 = V_90 ;
V_92 = V_90 ;
V_93 = ( void * ) F_56 ( V_91 * V_44 - 1 ) + 1 ;
}
}
int F_92 ( int V_94 , T_10 V_32 , T_10 V_53 )
{
struct V_95 * V_96 = F_93 ( V_94 ) ;
struct V_97 * V_97 = V_96 -> V_98 +
F_94 ( V_94 , V_32 , V_53 , V_99 ) ;
unsigned long V_100 = V_32 >> V_64 ;
unsigned long V_101 = V_53 >> V_64 ;
int V_102 ;
F_95 ( V_32 , V_32 + V_53 ) ;
V_102 = F_96 ( V_94 , V_97 , V_100 , V_101 ) ;
F_97 ( V_102 ) ;
F_90 ( V_32 , V_53 ) ;
return V_102 ;
}
static void T_9 F_98 ( struct V_36 * V_36 , int V_103 )
{
unsigned long V_104 ;
unsigned int V_101 = 1 << V_103 ;
if ( F_99 ( V_36 ) ) {
F_100 ( V_36 ) ;
V_104 = ( unsigned long ) V_36 -> V_105 . V_11 ;
if ( V_104 == V_106 || V_104 == V_107 ) {
while ( V_101 -- )
F_101 ( V_36 ++ ) ;
} else
while ( V_101 -- )
F_102 ( V_36 ++ ) ;
} else
F_103 ( ( unsigned long ) F_27 ( V_36 ) , V_103 ) ;
}
static void T_9 F_104 ( T_7 * V_108 , T_1 * V_7 )
{
T_7 * V_49 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
V_49 = V_108 + V_69 ;
if ( F_66 ( * V_49 ) )
return;
}
F_98 ( V_2 ( * V_7 ) , 0 ) ;
F_25 ( & V_47 . V_39 ) ;
F_105 ( V_7 ) ;
F_32 ( & V_47 . V_39 ) ;
}
static void T_9 F_106 ( T_1 * V_109 , T_2 * V_12 )
{
T_1 * V_7 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_76 ; V_69 ++ ) {
V_7 = V_109 + V_69 ;
if ( F_70 ( * V_7 ) )
return;
}
F_98 ( V_10 ( * V_12 ) , 0 ) ;
F_25 ( & V_47 . V_39 ) ;
F_107 ( V_12 ) ;
F_32 ( & V_47 . V_39 ) ;
}
static bool T_9 F_108 ( T_2 * V_110 , T_3 * V_24 )
{
T_2 * V_12 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_80 ; V_69 ++ ) {
V_12 = V_110 + V_69 ;
if ( F_78 ( * V_12 ) )
return false ;
}
F_98 ( V_19 ( * V_24 ) , 0 ) ;
F_25 ( & V_47 . V_39 ) ;
F_31 ( V_24 ) ;
F_32 ( & V_47 . V_39 ) ;
return true ;
}
static void T_9
F_109 ( T_7 * V_108 , unsigned long V_3 , unsigned long V_4 ,
bool V_111 )
{
unsigned long V_11 , V_67 = 0 ;
T_7 * V_49 ;
void * V_112 ;
V_83 V_113 ;
V_49 = V_108 + F_63 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_49 ++ ) {
V_11 = ( V_3 + V_44 ) & V_45 ;
if ( V_11 > V_4 )
V_11 = V_4 ;
if ( ! F_110 ( * V_49 ) )
continue;
V_113 = F_66 ( * V_49 ) + ( V_3 & V_45 ) ;
if ( V_113 < ( V_83 ) 0x40000000 )
return;
if ( F_111 ( V_3 , V_44 ) &&
F_111 ( V_11 , V_44 ) ) {
if ( ! V_111 )
F_98 ( V_66 ( * V_49 ) , 0 ) ;
F_25 ( & V_47 . V_39 ) ;
F_112 ( & V_47 , V_3 , V_49 ) ;
F_32 ( & V_47 . V_39 ) ;
V_67 ++ ;
} else {
memset ( ( void * ) V_3 , V_114 , V_11 - V_3 ) ;
V_112 = F_27 ( V_66 ( * V_49 ) ) ;
if ( ! F_113 ( V_112 , V_114 , V_44 ) ) {
F_98 ( V_66 ( * V_49 ) , 0 ) ;
F_25 ( & V_47 . V_39 ) ;
F_112 ( & V_47 , V_3 , V_49 ) ;
F_32 ( & V_47 . V_39 ) ;
}
}
}
F_114 () ;
if ( V_111 )
F_68 ( V_74 , - V_67 ) ;
}
static void T_9
F_115 ( T_1 * V_109 , unsigned long V_3 , unsigned long V_4 ,
bool V_111 )
{
unsigned long V_11 , V_67 = 0 ;
T_7 * V_115 ;
T_1 * V_7 ;
void * V_112 ;
V_7 = V_109 + F_2 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_7 ++ ) {
V_11 = F_116 ( V_3 , V_4 ) ;
if ( ! F_3 ( * V_7 ) )
continue;
if ( F_71 ( * V_7 ) ) {
if ( F_111 ( V_3 , V_6 ) &&
F_111 ( V_11 , V_6 ) ) {
if ( ! V_111 )
F_98 ( V_2 ( * V_7 ) ,
F_117 ( V_6 ) ) ;
F_25 ( & V_47 . V_39 ) ;
F_105 ( V_7 ) ;
F_32 ( & V_47 . V_39 ) ;
V_67 ++ ;
} else {
memset ( ( void * ) V_3 , V_114 , V_11 - V_3 ) ;
V_112 = F_27 ( V_2 ( * V_7 ) ) ;
if ( ! F_113 ( V_112 , V_114 ,
V_6 ) ) {
F_98 ( V_2 ( * V_7 ) ,
F_117 ( V_6 ) ) ;
F_25 ( & V_47 . V_39 ) ;
F_105 ( V_7 ) ;
F_32 ( & V_47 . V_39 ) ;
}
}
continue;
}
V_115 = ( T_7 * ) F_72 ( * V_7 ) ;
F_109 ( V_115 , V_3 , V_11 , V_111 ) ;
F_104 ( V_115 , V_7 ) ;
}
if ( V_111 )
F_68 ( V_78 , - V_67 ) ;
}
static void T_9
F_118 ( T_2 * V_110 , unsigned long V_3 , unsigned long V_4 ,
bool V_111 )
{
unsigned long V_11 , V_67 = 0 ;
T_1 * V_116 ;
T_2 * V_12 ;
void * V_112 ;
V_12 = V_110 + F_7 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_12 ++ ) {
V_11 = F_119 ( V_3 , V_4 ) ;
if ( ! F_8 ( * V_12 ) )
continue;
if ( F_79 ( * V_12 ) ) {
if ( F_111 ( V_3 , V_14 ) &&
F_111 ( V_11 , V_14 ) ) {
if ( ! V_111 )
F_98 ( V_10 ( * V_12 ) ,
F_117 ( V_14 ) ) ;
F_25 ( & V_47 . V_39 ) ;
F_107 ( V_12 ) ;
F_32 ( & V_47 . V_39 ) ;
V_67 ++ ;
} else {
memset ( ( void * ) V_3 , V_114 , V_11 - V_3 ) ;
V_112 = F_27 ( V_10 ( * V_12 ) ) ;
if ( ! F_113 ( V_112 , V_114 ,
V_14 ) ) {
F_98 ( V_10 ( * V_12 ) ,
F_117 ( V_14 ) ) ;
F_25 ( & V_47 . V_39 ) ;
F_107 ( V_12 ) ;
F_32 ( & V_47 . V_39 ) ;
}
}
continue;
}
V_116 = ( T_1 * ) F_120 ( * V_12 ) ;
F_115 ( V_116 , V_3 , V_11 , V_111 ) ;
F_106 ( V_116 , V_12 ) ;
}
if ( V_111 )
F_68 ( V_81 , - V_67 ) ;
}
static void T_9
F_121 ( unsigned long V_32 , unsigned long V_4 , bool V_111 )
{
unsigned long V_11 ;
unsigned long V_3 ;
T_3 * V_24 ;
T_2 * V_12 ;
bool V_82 = false ;
for ( V_3 = V_32 ; V_3 < V_4 ; V_3 = V_11 ) {
V_11 = F_122 ( V_3 , V_4 ) ;
V_24 = F_23 ( V_3 ) ;
if ( ! F_15 ( * V_24 ) )
continue;
V_12 = ( T_2 * ) F_30 ( * V_24 ) ;
F_118 ( V_12 , V_3 , V_11 , V_111 ) ;
if ( F_108 ( V_12 , V_24 ) )
V_82 = true ;
}
if ( V_82 )
F_22 ( V_32 , V_4 - 1 , 1 ) ;
F_114 () ;
}
void T_6 F_123 ( unsigned long V_32 , unsigned long V_4 )
{
F_121 ( V_32 , V_4 , false ) ;
}
static void T_9
F_124 ( unsigned long V_32 , unsigned long V_4 )
{
V_32 = ( unsigned long ) F_56 ( V_32 ) ;
V_4 = ( unsigned long ) F_56 ( V_4 ) ;
F_121 ( V_32 , V_4 , true ) ;
}
int T_6 F_125 ( T_10 V_32 , T_10 V_53 )
{
unsigned long V_100 = V_32 >> V_64 ;
unsigned long V_101 = V_53 >> V_64 ;
struct V_97 * V_97 ;
int V_102 ;
V_97 = F_126 ( F_127 ( V_100 ) ) ;
F_124 ( V_32 , V_32 + V_53 ) ;
V_102 = F_128 ( V_97 , V_100 , V_101 ) ;
F_97 ( V_102 ) ;
return V_102 ;
}
static void T_4 F_129 ( void )
{
#ifdef F_130
int V_69 ;
F_131 (i)
F_132 ( F_93 ( V_69 ) ) ;
#endif
}
void T_4 F_133 ( void )
{
F_134 () ;
F_129 () ;
F_135 () ;
V_41 = 1 ;
F_136 ( & V_117 , ( void * ) V_118 ,
V_44 , V_119 ) ;
F_137 ( NULL ) ;
}
void F_138 ( void )
{
unsigned long V_32 = F_139 ( V_65 ) ;
unsigned long V_4 = F_139 ( V_120 ) ;
if ( ! V_121 )
return;
F_37 ( L_13 ,
V_32 , V_4 ) ;
F_140 ( V_32 , ( V_4 - V_32 ) >> V_64 ) ;
}
void F_141 ( void )
{
unsigned long V_32 = F_139 ( V_65 ) ;
unsigned long V_4 = F_139 ( V_120 ) ;
if ( ! V_121 )
return;
F_37 ( L_14 ,
V_32 , V_4 ) ;
F_142 ( V_32 , ( V_4 - V_32 ) >> V_64 ) ;
}
void F_143 ( void )
{
unsigned long V_32 = F_139 ( V_65 ) ;
unsigned long V_122 = F_139 ( V_123 ) ;
unsigned long V_4 = ( unsigned long ) & V_124 ;
unsigned long V_125 = F_139 ( & V_120 ) ;
unsigned long V_126 = F_139 ( & V_127 ) ;
unsigned long V_128 ;
F_40 ( V_129 L_15 ,
( V_4 - V_32 ) >> 10 ) ;
F_142 ( V_32 , ( V_4 - V_32 ) >> V_64 ) ;
V_121 = 1 ;
V_128 = F_61 ( ( unsigned long ) V_61 , V_6 ) ;
F_144 ( V_122 , ( V_128 - V_122 ) >> V_64 ) ;
F_145 () ;
#ifdef F_146
F_40 ( V_129 L_16 , V_32 , V_4 ) ;
F_140 ( V_32 , ( V_4 - V_32 ) >> V_64 ) ;
F_40 ( V_129 L_17 ) ;
F_142 ( V_32 , ( V_4 - V_32 ) >> V_64 ) ;
#endif
F_147 ( L_18 ,
( unsigned long ) F_56 ( F_148 ( V_125 ) ) ,
( unsigned long ) F_56 ( F_148 ( V_122 ) ) ) ;
F_147 ( L_18 ,
( unsigned long ) F_56 ( F_148 ( V_126 ) ) ,
( unsigned long ) F_56 ( F_148 ( V_130 ) ) ) ;
}
int F_149 ( unsigned long V_3 )
{
unsigned long V_131 = ( ( long ) V_3 ) >> V_132 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
T_7 * V_49 ;
if ( V_131 != 0 && V_131 != - 1UL )
return 0 ;
V_24 = F_23 ( V_3 ) ;
if ( F_24 ( * V_24 ) )
return 0 ;
V_12 = F_16 ( V_24 , V_3 ) ;
if ( F_42 ( * V_12 ) )
return 0 ;
if ( F_79 ( * V_12 ) )
return F_150 ( F_151 ( * V_12 ) ) ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_45 ( * V_7 ) )
return 0 ;
if ( F_71 ( * V_7 ) )
return F_150 ( F_152 ( * V_7 ) ) ;
V_49 = F_47 ( V_7 , V_3 ) ;
if ( F_153 ( * V_49 ) )
return 0 ;
return F_150 ( F_154 ( * V_49 ) ) ;
}
static const char * F_155 ( struct V_133 * V_134 )
{
return L_19 ;
}
struct V_133 * F_156 ( struct V_135 * V_136 )
{
#ifdef F_157
if ( ! V_136 || V_136 -> V_16 . V_137 )
return NULL ;
#endif
return & V_138 ;
}
int F_158 ( struct V_135 * V_136 , unsigned long V_3 )
{
struct V_133 * V_134 = F_156 ( V_136 ) ;
if ( ! V_134 )
return 0 ;
return ( V_3 >= V_134 -> V_139 ) && ( V_3 < V_134 -> V_140 ) ;
}
int F_159 ( unsigned long V_3 )
{
return ( V_3 & V_45 ) == V_118 ;
}
static unsigned long F_160 ( void )
{
unsigned long V_141 = 1UL << 31 ;
#ifdef F_161
if ( F_162 () ) {
F_40 ( V_129 L_20 ) ;
return 2UL * 1024 * 1024 * 1024 ;
}
#endif
if ( ( V_91 << V_64 ) < ( 16UL << 32 ) )
return V_142 ;
while ( V_141 > V_142 ) {
if ( ! ( ( V_91 << V_64 ) & ( V_141 - 1 ) ) )
break;
V_141 >>= 1 ;
}
F_40 ( V_143 L_21 , V_141 >> 20 ) ;
return V_141 ;
}
unsigned long F_163 ( void )
{
if ( ! V_144 )
V_144 = F_160 () ;
return V_144 ;
}
static int T_9 F_164 ( unsigned long V_32 ,
unsigned long V_4 , int V_145 )
{
unsigned long V_3 ;
unsigned long V_11 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
for ( V_3 = V_32 ; V_3 < V_4 ; V_3 = V_11 ) {
V_11 = F_116 ( V_3 , V_4 ) ;
V_24 = F_165 ( V_3 , V_145 ) ;
if ( ! V_24 )
return - V_17 ;
V_12 = F_166 ( V_24 , V_3 , V_145 ) ;
if ( ! V_12 )
return - V_17 ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_45 ( * V_7 ) ) {
void * V_146 ;
V_146 = F_167 ( V_6 , V_145 ) ;
if ( V_146 ) {
T_7 V_147 ;
V_147 = F_67 ( F_12 ( V_146 ) >> V_64 ,
V_56 ) ;
F_4 ( V_7 , F_5 ( F_66 ( V_147 ) ) ) ;
if ( V_148 != V_146 || V_149 != V_145 ) {
if ( V_150 )
F_40 ( V_143 L_22 ,
V_151 , V_152 - 1 , V_150 , V_148 - 1 , V_149 ) ;
V_151 = V_3 ;
V_149 = V_145 ;
V_150 = V_146 ;
}
V_152 = V_3 + V_6 ;
V_148 = V_146 + V_6 ;
continue;
}
} else if ( F_71 ( * V_7 ) ) {
F_168 ( ( T_7 * ) V_7 , V_145 , V_3 , V_11 ) ;
continue;
}
F_169 ( L_23 ) ;
if ( F_170 ( V_3 , V_11 , V_145 ) )
return - V_17 ;
}
return 0 ;
}
int T_9 F_171 ( unsigned long V_32 , unsigned long V_4 , int V_145 )
{
int V_153 ;
if ( V_154 )
V_153 = F_164 ( V_32 , V_4 , V_145 ) ;
else
V_153 = F_170 ( V_32 , V_4 , V_145 ) ;
if ( ! V_153 )
F_22 ( V_32 , V_4 - 1 , 0 ) ;
return V_153 ;
}
void F_172 ( unsigned long V_155 ,
struct V_36 * V_156 , unsigned long V_53 )
{
unsigned long V_3 = ( unsigned long ) V_156 ;
unsigned long V_4 = ( unsigned long ) ( V_156 + V_53 ) ;
unsigned long V_11 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
unsigned int V_101 ;
struct V_36 * V_36 ;
for (; V_3 < V_4 ; V_3 = V_11 ) {
T_7 * V_49 = NULL ;
V_24 = F_23 ( V_3 ) ;
if ( F_24 ( * V_24 ) ) {
V_11 = ( V_3 + V_44 ) & V_45 ;
continue;
}
F_173 ( V_155 , V_19 ( * V_24 ) , V_107 ) ;
V_12 = F_16 ( V_24 , V_3 ) ;
if ( F_42 ( * V_12 ) ) {
V_11 = ( V_3 + V_44 ) & V_45 ;
continue;
}
F_173 ( V_155 , V_10 ( * V_12 ) , V_107 ) ;
if ( ! V_154 ) {
V_11 = ( V_3 + V_44 ) & V_45 ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_45 ( * V_7 ) )
continue;
F_173 ( V_155 , V_2 ( * V_7 ) ,
V_107 ) ;
V_49 = F_47 ( V_7 , V_3 ) ;
if ( F_153 ( * V_49 ) )
continue;
F_173 ( V_155 , V_66 ( * V_49 ) ,
V_106 ) ;
} else {
V_11 = F_116 ( V_3 , V_4 ) ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_45 ( * V_7 ) )
continue;
V_101 = 1 << ( F_117 ( V_6 ) ) ;
V_36 = V_2 ( * V_7 ) ;
while ( V_101 -- )
F_173 ( V_155 , V_36 ++ ,
V_106 ) ;
}
}
}
void T_9 F_174 ( void )
{
if ( V_150 ) {
F_40 ( V_143 L_22 ,
V_151 , V_152 - 1 , V_150 , V_148 - 1 , V_149 ) ;
V_150 = NULL ;
V_148 = NULL ;
V_149 = 0 ;
}
}
