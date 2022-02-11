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
if ( ! strcmp ( V_27 , L_1 ) )
V_28 &= ~ V_29 ;
else if ( ! strcmp ( V_27 , L_2 ) )
V_28 |= V_29 ;
return 1 ;
}
void F_20 ( unsigned long V_30 , unsigned long V_4 , int V_31 )
{
unsigned long V_32 ;
for ( V_32 = V_30 ; V_32 <= V_4 ; V_32 += V_26 ) {
const T_3 * V_33 = F_21 ( V_32 ) ;
struct V_34 * V_34 ;
if ( F_22 ( * V_33 ) && ! V_31 )
continue;
F_23 ( & V_35 ) ;
F_24 (page, &pgd_list, lru) {
T_3 * V_24 ;
T_5 * V_36 ;
V_24 = ( T_3 * ) F_25 ( V_34 ) + F_14 ( V_32 ) ;
V_36 = & F_26 ( V_34 ) -> V_37 ;
F_23 ( V_36 ) ;
if ( ! F_22 ( * V_33 ) && ! F_22 ( * V_24 ) )
F_27 ( F_28 ( * V_24 )
!= F_28 ( * V_33 ) ) ;
if ( V_31 ) {
if ( F_22 ( * V_33 ) && ! F_22 ( * V_24 ) )
F_29 ( V_24 ) ;
} else {
if ( F_22 ( * V_24 ) )
F_17 ( V_24 , * V_33 ) ;
}
F_30 ( V_36 ) ;
}
F_30 ( & V_35 ) ;
}
}
static T_6 void * F_31 ( void )
{
void * V_38 ;
if ( V_39 )
V_38 = ( void * ) F_32 ( V_40 | V_41 ) ;
else
V_38 = F_33 ( V_42 ) ;
if ( ! V_38 || ( ( unsigned long ) V_38 & ~ V_43 ) ) {
F_34 ( L_3 ,
V_39 ? L_4 : L_5 ) ;
}
F_35 ( L_6 , V_38 ) ;
return V_38 ;
}
static T_2 * F_36 ( T_3 * V_24 , unsigned long V_44 )
{
if ( F_22 ( * V_24 ) ) {
T_2 * V_12 = ( T_2 * ) F_31 () ;
F_37 ( & V_45 , V_24 , V_12 ) ;
if ( V_12 != F_16 ( V_24 , 0 ) )
F_38 ( V_46 L_7 ,
V_12 , F_16 ( V_24 , 0 ) ) ;
}
return F_16 ( V_24 , V_44 ) ;
}
static T_1 * F_39 ( T_2 * V_12 , unsigned long V_44 )
{
if ( F_40 ( * V_12 ) ) {
T_1 * V_7 = ( T_1 * ) F_31 () ;
F_41 ( & V_45 , V_12 , V_7 ) ;
if ( V_7 != F_9 ( V_12 , 0 ) )
F_38 ( V_46 L_8 ,
V_7 , F_9 ( V_12 , 0 ) ) ;
}
return F_9 ( V_12 , V_44 ) ;
}
static T_7 * F_42 ( T_1 * V_7 , unsigned long V_44 )
{
if ( F_43 ( * V_7 ) ) {
T_7 * V_47 = ( T_7 * ) F_31 () ;
F_44 ( & V_45 , V_7 , V_47 ) ;
if ( V_47 != F_45 ( V_7 , 0 ) )
F_38 ( V_46 L_9 ) ;
}
return F_45 ( V_7 , V_44 ) ;
}
void F_46 ( T_2 * V_10 , unsigned long V_44 , T_7 V_48 )
{
T_2 * V_12 ;
T_1 * V_7 ;
T_7 * V_47 ;
V_12 = V_10 + F_7 ( V_44 ) ;
V_7 = F_39 ( V_12 , V_44 ) ;
V_47 = F_42 ( V_7 , V_44 ) ;
F_47 ( V_47 , V_48 ) ;
F_48 ( V_44 ) ;
}
void F_49 ( unsigned long V_44 , T_7 V_49 )
{
T_3 * V_24 ;
T_2 * V_10 ;
F_35 ( L_10 , V_44 , F_50 ( V_49 ) ) ;
V_24 = F_21 ( V_44 ) ;
if ( F_22 ( * V_24 ) ) {
F_38 ( V_46
L_11 ) ;
return;
}
V_10 = ( T_2 * ) F_28 ( * V_24 ) ;
F_46 ( V_10 , V_44 , V_49 ) ;
}
T_1 * T_4 F_51 ( unsigned long V_44 )
{
T_3 * V_24 ;
T_2 * V_12 ;
V_24 = F_21 ( V_44 ) ;
V_12 = F_36 ( V_24 , V_44 ) ;
return F_39 ( V_12 , V_44 ) ;
}
T_7 * T_4 F_52 ( unsigned long V_44 )
{
T_1 * V_7 ;
V_7 = F_51 ( V_44 ) ;
return F_42 ( V_7 , V_44 ) ;
}
static void T_4 F_53 ( unsigned long V_50 , unsigned long V_51 ,
enum V_52 V_53 )
{
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
T_8 V_54 ;
F_54 ( V_54 ) = F_54 ( V_55 ) |
F_54 ( F_55 ( F_56 ( V_53 ) ) ) ;
F_27 ( ( V_50 & ~ V_5 ) || ( V_51 & ~ V_5 ) ) ;
for (; V_51 ; V_50 += V_6 , V_51 -= V_6 ) {
V_24 = F_21 ( ( unsigned long ) F_57 ( V_50 ) ) ;
if ( F_22 ( * V_24 ) ) {
V_12 = ( T_2 * ) F_31 () ;
F_17 ( V_24 , F_18 ( F_12 ( V_12 ) | V_18 |
V_56 ) ) ;
}
V_12 = F_16 ( V_24 , ( unsigned long ) F_57 ( V_50 ) ) ;
if ( F_40 ( * V_12 ) ) {
V_7 = ( T_1 * ) F_31 () ;
F_10 ( V_12 , F_11 ( F_12 ( V_7 ) | V_18 |
V_56 ) ) ;
}
V_7 = F_9 ( V_12 , V_50 ) ;
F_27 ( ! F_43 ( * V_7 ) ) ;
F_4 ( V_7 , F_5 ( V_50 | F_54 ( V_54 ) ) ) ;
}
}
void T_4 F_58 ( unsigned long V_50 , unsigned long V_51 )
{
F_53 ( V_50 , V_51 , V_57 ) ;
}
void T_4 F_59 ( unsigned long V_50 , unsigned long V_51 )
{
F_53 ( V_50 , V_51 , V_58 ) ;
}
void T_4 F_60 ( void )
{
unsigned long V_44 = V_59 ;
unsigned long V_60 = V_59 + V_61 ;
unsigned long V_4 = F_61 ( ( unsigned long ) V_62 , V_6 ) - 1 ;
T_1 * V_7 = V_63 ;
if ( V_64 )
V_60 = V_59 + ( V_64 << V_65 ) ;
for (; V_44 + V_6 - 1 < V_60 ; V_7 ++ , V_44 += V_6 ) {
if ( F_43 ( * V_7 ) )
continue;
if ( V_44 < ( unsigned long ) V_66 || V_44 > V_4 )
F_4 ( V_7 , F_5 ( 0 ) ) ;
}
}
static unsigned long T_9
F_62 ( T_7 * V_67 , unsigned long V_3 , unsigned long V_4 ,
T_8 V_54 )
{
unsigned long V_68 = 0 , V_11 ;
unsigned long V_69 = V_4 ;
int V_70 ;
T_7 * V_47 = V_67 + F_63 ( V_3 ) ;
for ( V_70 = F_63 ( V_3 ) ; V_70 < V_71 ; V_70 ++ , V_3 = V_11 , V_47 ++ ) {
V_11 = ( V_3 & V_43 ) + V_42 ;
if ( V_3 >= V_4 ) {
if ( ! V_39 &&
! F_64 ( V_3 & V_43 , V_11 , V_72 ) &&
! F_64 ( V_3 & V_43 , V_11 , V_73 ) )
F_47 ( V_47 , F_65 ( 0 ) ) ;
continue;
}
if ( F_66 ( * V_47 ) ) {
if ( ! V_39 )
V_68 ++ ;
continue;
}
if ( 0 )
F_38 ( L_12 ,
V_47 , V_3 , F_67 ( V_3 >> V_65 , V_74 ) . V_47 ) ;
V_68 ++ ;
F_47 ( V_47 , F_67 ( V_3 >> V_65 , V_54 ) ) ;
V_69 = ( V_3 & V_43 ) + V_42 ;
}
F_68 ( V_75 , V_68 ) ;
return V_69 ;
}
static unsigned long T_9
F_69 ( T_1 * V_2 , unsigned long V_32 , unsigned long V_4 ,
unsigned long V_76 , T_8 V_54 )
{
unsigned long V_68 = 0 , V_11 ;
unsigned long V_69 = V_4 ;
int V_70 = F_2 ( V_32 ) ;
for (; V_70 < V_77 ; V_70 ++ , V_32 = V_11 ) {
T_1 * V_7 = V_2 + F_2 ( V_32 ) ;
T_7 * V_47 ;
T_8 V_78 = V_54 ;
V_11 = ( V_32 & V_5 ) + V_6 ;
if ( V_32 >= V_4 ) {
if ( ! V_39 &&
! F_64 ( V_32 & V_5 , V_11 , V_72 ) &&
! F_64 ( V_32 & V_5 , V_11 , V_73 ) )
F_4 ( V_7 , F_5 ( 0 ) ) ;
continue;
}
if ( F_70 ( * V_7 ) ) {
if ( ! F_71 ( * V_7 ) ) {
F_23 ( & V_45 . V_37 ) ;
V_47 = ( T_7 * ) F_72 ( * V_7 ) ;
V_69 = F_62 ( V_47 , V_32 ,
V_4 , V_54 ) ;
F_30 ( & V_45 . V_37 ) ;
continue;
}
if ( V_76 & ( 1 << V_79 ) ) {
if ( ! V_39 )
V_68 ++ ;
V_69 = V_11 ;
continue;
}
V_78 = F_73 ( F_74 ( * ( T_7 * ) V_7 ) ) ;
}
if ( V_76 & ( 1 << V_79 ) ) {
V_68 ++ ;
F_23 ( & V_45 . V_37 ) ;
F_47 ( ( T_7 * ) V_7 ,
F_67 ( ( V_32 & V_5 ) >> V_65 ,
F_75 ( F_54 ( V_54 ) | V_80 ) ) ) ;
F_30 ( & V_45 . V_37 ) ;
V_69 = V_11 ;
continue;
}
V_47 = F_76 () ;
V_69 = F_62 ( V_47 , V_32 , V_4 , V_78 ) ;
F_23 ( & V_45 . V_37 ) ;
F_44 ( & V_45 , V_7 , V_47 ) ;
F_30 ( & V_45 . V_37 ) ;
}
F_68 ( V_79 , V_68 ) ;
return V_69 ;
}
static unsigned long T_9
F_77 ( T_2 * V_10 , unsigned long V_3 , unsigned long V_4 ,
unsigned long V_76 )
{
unsigned long V_68 = 0 , V_11 ;
unsigned long V_69 = V_4 ;
int V_70 = F_7 ( V_3 ) ;
for (; V_70 < V_81 ; V_70 ++ , V_3 = V_11 ) {
T_2 * V_12 = V_10 + F_7 ( V_3 ) ;
T_1 * V_7 ;
T_8 V_54 = V_74 ;
V_11 = ( V_3 & V_13 ) + V_14 ;
if ( V_3 >= V_4 ) {
if ( ! V_39 &&
! F_64 ( V_3 & V_13 , V_11 , V_72 ) &&
! F_64 ( V_3 & V_13 , V_11 , V_73 ) )
F_10 ( V_12 , F_11 ( 0 ) ) ;
continue;
}
if ( F_78 ( * V_12 ) ) {
if ( ! F_79 ( * V_12 ) ) {
V_7 = F_9 ( V_12 , 0 ) ;
V_69 = F_69 ( V_7 , V_3 , V_4 ,
V_76 , V_54 ) ;
F_80 () ;
continue;
}
if ( V_76 & ( 1 << V_82 ) ) {
if ( ! V_39 )
V_68 ++ ;
V_69 = V_11 ;
continue;
}
V_54 = F_73 ( F_74 ( * ( T_7 * ) V_12 ) ) ;
}
if ( V_76 & ( 1 << V_82 ) ) {
V_68 ++ ;
F_23 ( & V_45 . V_37 ) ;
F_47 ( ( T_7 * ) V_12 ,
F_67 ( ( V_3 & V_13 ) >> V_65 ,
V_55 ) ) ;
F_30 ( & V_45 . V_37 ) ;
V_69 = V_11 ;
continue;
}
V_7 = F_76 () ;
V_69 = F_69 ( V_7 , V_3 , V_4 , V_76 ,
V_54 ) ;
F_23 ( & V_45 . V_37 ) ;
F_41 ( & V_45 , V_12 , V_7 ) ;
F_30 ( & V_45 . V_37 ) ;
}
F_80 () ;
F_68 ( V_82 , V_68 ) ;
return V_69 ;
}
unsigned long T_9
F_81 ( unsigned long V_30 ,
unsigned long V_4 ,
unsigned long V_76 )
{
bool V_83 = false ;
unsigned long V_11 , V_69 = V_4 ;
unsigned long V_3 ;
V_30 = ( unsigned long ) F_57 ( V_30 ) ;
V_4 = ( unsigned long ) F_57 ( V_4 ) ;
V_3 = V_30 ;
for (; V_30 < V_4 ; V_30 = V_11 ) {
T_3 * V_24 = F_21 ( V_30 ) ;
T_2 * V_12 ;
V_11 = ( V_30 & V_25 ) + V_26 ;
if ( F_82 ( * V_24 ) ) {
V_12 = ( T_2 * ) F_28 ( * V_24 ) ;
V_69 = F_77 ( V_12 , F_12 ( V_30 ) ,
F_12 ( V_4 ) , V_76 ) ;
continue;
}
V_12 = F_76 () ;
V_69 = F_77 ( V_12 , F_12 ( V_30 ) , F_12 ( V_4 ) ,
V_76 ) ;
F_23 ( & V_45 . V_37 ) ;
F_37 ( & V_45 , V_24 , V_12 ) ;
F_30 ( & V_45 . V_37 ) ;
V_83 = true ;
}
if ( V_83 )
F_20 ( V_3 , V_4 - 1 , 0 ) ;
F_80 () ;
return V_69 ;
}
void T_4 F_83 ( void )
{
F_84 ( 0 , ( V_84 ) V_85 , & V_86 . V_87 , 0 ) ;
}
void T_4 F_85 ( void )
{
F_86 ( V_88 ) ;
F_87 () ;
F_88 ( 0 , V_89 ) ;
if ( V_89 != V_90 )
F_88 ( 0 , V_90 ) ;
F_89 () ;
}
static void F_90 ( T_10 V_30 , T_10 V_51 )
{
unsigned long V_91 = F_91 ( V_30 + V_51 ) ;
if ( V_91 > V_92 ) {
V_92 = V_91 ;
V_93 = V_91 ;
V_94 = ( void * ) F_57 ( V_92 * V_42 - 1 ) + 1 ;
}
}
int F_92 ( int V_95 , T_10 V_30 , T_10 V_51 , bool V_96 )
{
struct V_97 * V_98 = F_93 ( V_95 ) ;
struct V_99 * V_99 = V_98 -> V_100 +
F_94 ( V_95 , V_30 , V_51 , V_101 , V_96 ) ;
unsigned long V_102 = V_30 >> V_65 ;
unsigned long V_103 = V_51 >> V_65 ;
int V_104 ;
F_95 ( V_30 , V_30 + V_51 ) ;
V_104 = F_96 ( V_95 , V_99 , V_102 , V_103 ) ;
F_97 ( V_104 ) ;
F_90 ( V_30 , V_51 ) ;
return V_104 ;
}
static void T_9 F_98 ( struct V_34 * V_34 , int V_105 )
{
unsigned long V_106 ;
unsigned int V_103 = 1 << V_105 ;
if ( F_99 ( V_34 ) ) {
F_100 ( V_34 ) ;
V_106 = ( unsigned long ) V_34 -> V_107 . V_11 ;
if ( V_106 == V_108 || V_106 == V_109 ) {
while ( V_103 -- )
F_101 ( V_34 ++ ) ;
} else
while ( V_103 -- )
F_102 ( V_34 ++ ) ;
} else
F_103 ( ( unsigned long ) F_25 ( V_34 ) , V_105 ) ;
}
static void T_9 F_104 ( T_7 * V_110 , T_1 * V_7 )
{
T_7 * V_47 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
V_47 = V_110 + V_70 ;
if ( F_66 ( * V_47 ) )
return;
}
F_98 ( V_2 ( * V_7 ) , 0 ) ;
F_23 ( & V_45 . V_37 ) ;
F_105 ( V_7 ) ;
F_30 ( & V_45 . V_37 ) ;
}
static void T_9 F_106 ( T_1 * V_111 , T_2 * V_12 )
{
T_1 * V_7 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_77 ; V_70 ++ ) {
V_7 = V_111 + V_70 ;
if ( F_70 ( * V_7 ) )
return;
}
F_98 ( V_10 ( * V_12 ) , 0 ) ;
F_23 ( & V_45 . V_37 ) ;
F_107 ( V_12 ) ;
F_30 ( & V_45 . V_37 ) ;
}
static bool T_9 F_108 ( T_2 * V_112 , T_3 * V_24 )
{
T_2 * V_12 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_81 ; V_70 ++ ) {
V_12 = V_112 + V_70 ;
if ( F_78 ( * V_12 ) )
return false ;
}
F_98 ( V_19 ( * V_24 ) , 0 ) ;
F_23 ( & V_45 . V_37 ) ;
F_29 ( V_24 ) ;
F_30 ( & V_45 . V_37 ) ;
return true ;
}
static void T_9
F_109 ( T_7 * V_110 , unsigned long V_3 , unsigned long V_4 ,
bool V_113 )
{
unsigned long V_11 , V_68 = 0 ;
T_7 * V_47 ;
void * V_114 ;
V_84 V_115 ;
V_47 = V_110 + F_63 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_47 ++ ) {
V_11 = ( V_3 + V_42 ) & V_43 ;
if ( V_11 > V_4 )
V_11 = V_4 ;
if ( ! F_110 ( * V_47 ) )
continue;
V_115 = F_66 ( * V_47 ) + ( V_3 & V_43 ) ;
if ( V_115 < ( V_84 ) 0x40000000 )
return;
if ( F_111 ( V_3 , V_42 ) &&
F_111 ( V_11 , V_42 ) ) {
if ( ! V_113 )
F_98 ( V_67 ( * V_47 ) , 0 ) ;
F_23 ( & V_45 . V_37 ) ;
F_112 ( & V_45 , V_3 , V_47 ) ;
F_30 ( & V_45 . V_37 ) ;
V_68 ++ ;
} else {
memset ( ( void * ) V_3 , V_116 , V_11 - V_3 ) ;
V_114 = F_25 ( V_67 ( * V_47 ) ) ;
if ( ! F_113 ( V_114 , V_116 , V_42 ) ) {
F_98 ( V_67 ( * V_47 ) , 0 ) ;
F_23 ( & V_45 . V_37 ) ;
F_112 ( & V_45 , V_3 , V_47 ) ;
F_30 ( & V_45 . V_37 ) ;
}
}
}
F_114 () ;
if ( V_113 )
F_68 ( V_75 , - V_68 ) ;
}
static void T_9
F_115 ( T_1 * V_111 , unsigned long V_3 , unsigned long V_4 ,
bool V_113 )
{
unsigned long V_11 , V_68 = 0 ;
T_7 * V_117 ;
T_1 * V_7 ;
void * V_114 ;
V_7 = V_111 + F_2 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_7 ++ ) {
V_11 = F_116 ( V_3 , V_4 ) ;
if ( ! F_3 ( * V_7 ) )
continue;
if ( F_71 ( * V_7 ) ) {
if ( F_111 ( V_3 , V_6 ) &&
F_111 ( V_11 , V_6 ) ) {
if ( ! V_113 )
F_98 ( V_2 ( * V_7 ) ,
F_117 ( V_6 ) ) ;
F_23 ( & V_45 . V_37 ) ;
F_105 ( V_7 ) ;
F_30 ( & V_45 . V_37 ) ;
V_68 ++ ;
} else {
memset ( ( void * ) V_3 , V_116 , V_11 - V_3 ) ;
V_114 = F_25 ( V_2 ( * V_7 ) ) ;
if ( ! F_113 ( V_114 , V_116 ,
V_6 ) ) {
F_98 ( V_2 ( * V_7 ) ,
F_117 ( V_6 ) ) ;
F_23 ( & V_45 . V_37 ) ;
F_105 ( V_7 ) ;
F_30 ( & V_45 . V_37 ) ;
}
}
continue;
}
V_117 = ( T_7 * ) F_72 ( * V_7 ) ;
F_109 ( V_117 , V_3 , V_11 , V_113 ) ;
F_104 ( V_117 , V_7 ) ;
}
if ( V_113 )
F_68 ( V_79 , - V_68 ) ;
}
static void T_9
F_118 ( T_2 * V_112 , unsigned long V_3 , unsigned long V_4 ,
bool V_113 )
{
unsigned long V_11 , V_68 = 0 ;
T_1 * V_118 ;
T_2 * V_12 ;
void * V_114 ;
V_12 = V_112 + F_7 ( V_3 ) ;
for (; V_3 < V_4 ; V_3 = V_11 , V_12 ++ ) {
V_11 = F_119 ( V_3 , V_4 ) ;
if ( ! F_8 ( * V_12 ) )
continue;
if ( F_79 ( * V_12 ) ) {
if ( F_111 ( V_3 , V_14 ) &&
F_111 ( V_11 , V_14 ) ) {
if ( ! V_113 )
F_98 ( V_10 ( * V_12 ) ,
F_117 ( V_14 ) ) ;
F_23 ( & V_45 . V_37 ) ;
F_107 ( V_12 ) ;
F_30 ( & V_45 . V_37 ) ;
V_68 ++ ;
} else {
memset ( ( void * ) V_3 , V_116 , V_11 - V_3 ) ;
V_114 = F_25 ( V_10 ( * V_12 ) ) ;
if ( ! F_113 ( V_114 , V_116 ,
V_14 ) ) {
F_98 ( V_10 ( * V_12 ) ,
F_117 ( V_14 ) ) ;
F_23 ( & V_45 . V_37 ) ;
F_107 ( V_12 ) ;
F_30 ( & V_45 . V_37 ) ;
}
}
continue;
}
V_118 = ( T_1 * ) F_120 ( * V_12 ) ;
F_115 ( V_118 , V_3 , V_11 , V_113 ) ;
F_106 ( V_118 , V_12 ) ;
}
if ( V_113 )
F_68 ( V_82 , - V_68 ) ;
}
static void T_9
F_121 ( unsigned long V_30 , unsigned long V_4 , bool V_113 )
{
unsigned long V_11 ;
unsigned long V_3 ;
T_3 * V_24 ;
T_2 * V_12 ;
bool V_83 = false ;
for ( V_3 = V_30 ; V_3 < V_4 ; V_3 = V_11 ) {
V_11 = F_122 ( V_3 , V_4 ) ;
V_24 = F_21 ( V_3 ) ;
if ( ! F_15 ( * V_24 ) )
continue;
V_12 = ( T_2 * ) F_28 ( * V_24 ) ;
F_118 ( V_12 , V_3 , V_11 , V_113 ) ;
if ( F_108 ( V_12 , V_24 ) )
V_83 = true ;
}
if ( V_83 )
F_20 ( V_30 , V_4 - 1 , 1 ) ;
F_114 () ;
}
void T_6 F_123 ( unsigned long V_30 , unsigned long V_4 )
{
F_121 ( V_30 , V_4 , false ) ;
}
static void T_9
F_124 ( unsigned long V_30 , unsigned long V_4 )
{
V_30 = ( unsigned long ) F_57 ( V_30 ) ;
V_4 = ( unsigned long ) F_57 ( V_4 ) ;
F_121 ( V_30 , V_4 , true ) ;
}
int T_6 F_125 ( T_10 V_30 , T_10 V_51 )
{
unsigned long V_102 = V_30 >> V_65 ;
unsigned long V_103 = V_51 >> V_65 ;
struct V_99 * V_99 ;
int V_104 ;
V_99 = F_126 ( F_127 ( V_102 ) ) ;
F_124 ( V_30 , V_30 + V_51 ) ;
V_104 = F_128 ( V_99 , V_102 , V_103 ) ;
F_97 ( V_104 ) ;
return V_104 ;
}
static void T_4 F_129 ( void )
{
#ifdef F_130
int V_70 ;
F_131 (i)
F_132 ( F_93 ( V_70 ) ) ;
#endif
}
void T_4 F_133 ( void )
{
F_134 () ;
F_129 () ;
F_135 () ;
V_39 = 1 ;
F_136 ( & V_119 , ( void * ) V_120 ,
V_42 , V_121 ) ;
F_137 ( NULL ) ;
}
void F_138 ( void )
{
unsigned long V_30 = F_139 ( V_66 ) ;
unsigned long V_4 = F_139 ( V_122 ) ;
if ( ! V_123 )
return;
F_35 ( L_13 ,
V_30 , V_4 ) ;
F_140 ( V_30 , ( V_4 - V_30 ) >> V_65 ) ;
}
void F_141 ( void )
{
unsigned long V_30 = F_139 ( V_66 ) ;
unsigned long V_4 = F_139 ( V_122 ) ;
if ( ! V_123 )
return;
F_35 ( L_14 ,
V_30 , V_4 ) ;
F_142 ( V_30 , ( V_4 - V_30 ) >> V_65 ) ;
}
void F_143 ( void )
{
unsigned long V_30 = F_139 ( V_66 ) ;
unsigned long V_124 = F_139 ( V_125 ) ;
unsigned long V_4 = ( unsigned long ) & V_126 ;
unsigned long V_127 = F_139 ( & V_122 ) ;
unsigned long V_128 = F_139 ( & V_129 ) ;
unsigned long V_130 ;
F_38 ( V_131 L_15 ,
( V_4 - V_30 ) >> 10 ) ;
F_142 ( V_30 , ( V_4 - V_30 ) >> V_65 ) ;
V_123 = 1 ;
V_130 = F_61 ( ( unsigned long ) V_62 , V_6 ) ;
F_144 ( V_127 , ( V_130 - V_127 ) >> V_65 ) ;
F_145 () ;
#ifdef F_146
F_38 ( V_131 L_16 , V_30 , V_4 ) ;
F_140 ( V_30 , ( V_4 - V_30 ) >> V_65 ) ;
F_38 ( V_131 L_17 ) ;
F_142 ( V_30 , ( V_4 - V_30 ) >> V_65 ) ;
#endif
F_147 ( L_18 ,
( unsigned long ) F_57 ( F_148 ( V_127 ) ) ,
( unsigned long ) F_57 ( F_148 ( V_124 ) ) ) ;
F_147 ( L_18 ,
( unsigned long ) F_57 ( F_148 ( V_128 ) ) ,
( unsigned long ) F_57 ( F_148 ( V_132 ) ) ) ;
}
int F_149 ( unsigned long V_3 )
{
unsigned long V_133 = ( ( long ) V_3 ) >> V_134 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
T_7 * V_47 ;
if ( V_133 != 0 && V_133 != - 1UL )
return 0 ;
V_24 = F_21 ( V_3 ) ;
if ( F_22 ( * V_24 ) )
return 0 ;
V_12 = F_16 ( V_24 , V_3 ) ;
if ( F_40 ( * V_12 ) )
return 0 ;
if ( F_79 ( * V_12 ) )
return F_150 ( F_151 ( * V_12 ) ) ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_43 ( * V_7 ) )
return 0 ;
if ( F_71 ( * V_7 ) )
return F_150 ( F_152 ( * V_7 ) ) ;
V_47 = F_45 ( V_7 , V_3 ) ;
if ( F_153 ( * V_47 ) )
return 0 ;
return F_150 ( F_154 ( * V_47 ) ) ;
}
static unsigned long F_155 ( void )
{
unsigned long V_135 = 1UL << 31 ;
if ( V_136 >= ( 64ULL << ( 30 - V_65 ) ) ) {
F_156 ( L_19 ) ;
return 2UL * 1024 * 1024 * 1024 ;
}
if ( ( V_92 << V_65 ) < ( 16UL << 32 ) )
return V_137 ;
while ( V_135 > V_137 ) {
if ( ! ( ( V_92 << V_65 ) & ( V_135 - 1 ) ) )
break;
V_135 >>= 1 ;
}
F_38 ( V_138 L_20 , V_135 >> 20 ) ;
return V_135 ;
}
unsigned long F_157 ( void )
{
if ( ! V_139 )
V_139 = F_155 () ;
return V_139 ;
}
static int T_9 F_158 ( unsigned long V_30 ,
unsigned long V_4 , int V_140 )
{
unsigned long V_3 ;
unsigned long V_11 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
for ( V_3 = V_30 ; V_3 < V_4 ; V_3 = V_11 ) {
V_11 = F_116 ( V_3 , V_4 ) ;
V_24 = F_159 ( V_3 , V_140 ) ;
if ( ! V_24 )
return - V_17 ;
V_12 = F_160 ( V_24 , V_3 , V_140 ) ;
if ( ! V_12 )
return - V_17 ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_43 ( * V_7 ) ) {
void * V_141 ;
V_141 = F_161 ( V_6 , V_140 ) ;
if ( V_141 ) {
T_7 V_142 ;
V_142 = F_67 ( F_12 ( V_141 ) >> V_65 ,
V_55 ) ;
F_4 ( V_7 , F_5 ( F_66 ( V_142 ) ) ) ;
if ( V_143 != V_141 || V_144 != V_140 ) {
if ( V_145 )
F_38 ( V_138 L_21 ,
V_146 , V_147 - 1 , V_145 , V_143 - 1 , V_144 ) ;
V_146 = V_3 ;
V_144 = V_140 ;
V_145 = V_141 ;
}
V_147 = V_3 + V_6 ;
V_143 = V_141 + V_6 ;
continue;
}
} else if ( F_71 ( * V_7 ) ) {
F_162 ( ( T_7 * ) V_7 , V_140 , V_3 , V_11 ) ;
continue;
}
F_163 ( L_22 ) ;
if ( F_164 ( V_3 , V_11 , V_140 ) )
return - V_17 ;
}
return 0 ;
}
int T_9 F_165 ( unsigned long V_30 , unsigned long V_4 , int V_140 )
{
int V_148 ;
if ( V_149 )
V_148 = F_158 ( V_30 , V_4 , V_140 ) ;
else
V_148 = F_164 ( V_30 , V_4 , V_140 ) ;
if ( ! V_148 )
F_20 ( V_30 , V_4 - 1 , 0 ) ;
return V_148 ;
}
void F_166 ( unsigned long V_150 ,
struct V_34 * V_151 , unsigned long V_51 )
{
unsigned long V_3 = ( unsigned long ) V_151 ;
unsigned long V_4 = ( unsigned long ) ( V_151 + V_51 ) ;
unsigned long V_11 ;
T_3 * V_24 ;
T_2 * V_12 ;
T_1 * V_7 ;
unsigned int V_103 ;
struct V_34 * V_34 ;
for (; V_3 < V_4 ; V_3 = V_11 ) {
T_7 * V_47 = NULL ;
V_24 = F_21 ( V_3 ) ;
if ( F_22 ( * V_24 ) ) {
V_11 = ( V_3 + V_42 ) & V_43 ;
continue;
}
F_167 ( V_150 , V_19 ( * V_24 ) , V_109 ) ;
V_12 = F_16 ( V_24 , V_3 ) ;
if ( F_40 ( * V_12 ) ) {
V_11 = ( V_3 + V_42 ) & V_43 ;
continue;
}
F_167 ( V_150 , V_10 ( * V_12 ) , V_109 ) ;
if ( ! V_149 ) {
V_11 = ( V_3 + V_42 ) & V_43 ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_43 ( * V_7 ) )
continue;
F_167 ( V_150 , V_2 ( * V_7 ) ,
V_109 ) ;
V_47 = F_45 ( V_7 , V_3 ) ;
if ( F_153 ( * V_47 ) )
continue;
F_167 ( V_150 , V_67 ( * V_47 ) ,
V_108 ) ;
} else {
V_11 = F_116 ( V_3 , V_4 ) ;
V_7 = F_9 ( V_12 , V_3 ) ;
if ( F_43 ( * V_7 ) )
continue;
V_103 = 1 << ( F_117 ( V_6 ) ) ;
V_34 = V_2 ( * V_7 ) ;
while ( V_103 -- )
F_167 ( V_150 , V_34 ++ ,
V_108 ) ;
}
}
}
void T_9 F_168 ( void )
{
if ( V_145 ) {
F_38 ( V_138 L_21 ,
V_146 , V_147 - 1 , V_145 , V_143 - 1 , V_144 ) ;
V_145 = NULL ;
V_143 = NULL ;
V_144 = 0 ;
}
}
