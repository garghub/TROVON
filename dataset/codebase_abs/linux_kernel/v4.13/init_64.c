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
const T_2 * V_8 = F_4 ( V_6 ) ;
struct V_9 * V_9 ;
if ( V_6 < V_4 )
break;
if ( F_5 ( * V_8 ) )
continue;
F_6 ( & V_10 ) ;
F_7 (page, &pgd_list, lru) {
T_2 * V_11 ;
T_3 * V_12 ;
V_11 = ( T_2 * ) F_8 ( V_9 ) + F_9 ( V_6 ) ;
V_12 = & F_10 ( V_9 ) -> V_13 ;
F_6 ( V_12 ) ;
if ( ! F_5 ( * V_8 ) && ! F_5 ( * V_11 ) )
F_11 ( F_12 ( * V_11 ) != F_12 ( * V_8 ) ) ;
if ( F_5 ( * V_11 ) )
F_13 ( V_11 , * V_8 ) ;
F_14 ( V_12 ) ;
}
F_14 ( & V_10 ) ;
}
}
void F_2 ( unsigned long V_4 , unsigned long V_5 )
{
unsigned long V_6 ;
for ( V_6 = V_4 ; V_6 <= V_5 ; V_6 = F_3 ( V_6 + 1 , V_7 ) ) {
T_2 * V_8 = F_4 ( V_6 ) ;
const T_4 * V_14 ;
struct V_9 * V_9 ;
F_15 ( F_5 ( * V_8 ) ) ;
V_14 = F_16 ( V_8 , V_6 ) ;
if ( F_17 ( * V_14 ) )
continue;
F_6 ( & V_10 ) ;
F_7 (page, &pgd_list, lru) {
T_2 * V_11 ;
T_4 * V_15 ;
T_3 * V_12 ;
V_11 = ( T_2 * ) F_8 ( V_9 ) + F_9 ( V_6 ) ;
V_15 = F_16 ( V_11 , V_6 ) ;
V_12 = & F_10 ( V_9 ) -> V_13 ;
F_6 ( V_12 ) ;
if ( ! F_17 ( * V_14 ) && ! F_17 ( * V_15 ) )
F_11 ( F_18 ( * V_15 )
!= F_18 ( * V_14 ) ) ;
if ( F_17 ( * V_15 ) )
F_19 ( V_15 , * V_14 ) ;
F_14 ( V_12 ) ;
}
F_14 ( & V_10 ) ;
}
}
static T_5 void * F_20 ( void )
{
void * V_16 ;
if ( V_17 )
V_16 = ( void * ) F_21 ( V_18 | V_19 ) ;
else
V_16 = F_22 ( V_20 ) ;
if ( ! V_16 || ( ( unsigned long ) V_16 & ~ V_21 ) ) {
F_23 ( L_3 ,
V_17 ? L_4 : L_5 ) ;
}
F_24 ( L_6 , V_16 ) ;
return V_16 ;
}
static T_4 * F_25 ( T_2 * V_11 , unsigned long V_22 )
{
if ( F_5 ( * V_11 ) ) {
T_4 * V_15 = ( T_4 * ) F_20 () ;
F_26 ( & V_23 , V_11 , V_15 ) ;
if ( V_15 != F_16 ( V_11 , 0 ) )
F_27 ( V_24 L_7 ,
V_15 , F_16 ( V_11 , 0 ) ) ;
}
return F_16 ( V_11 , V_22 ) ;
}
static T_6 * F_28 ( T_4 * V_15 , unsigned long V_22 )
{
if ( F_17 ( * V_15 ) ) {
T_6 * V_25 = ( T_6 * ) F_20 () ;
F_29 ( & V_23 , V_15 , V_25 ) ;
if ( V_25 != F_30 ( V_15 , 0 ) )
F_27 ( V_24 L_8 ,
V_25 , F_30 ( V_15 , 0 ) ) ;
}
return F_30 ( V_15 , V_22 ) ;
}
static T_7 * F_31 ( T_6 * V_25 , unsigned long V_22 )
{
if ( F_32 ( * V_25 ) ) {
T_7 * V_26 = ( T_7 * ) F_20 () ;
F_33 ( & V_23 , V_25 , V_26 ) ;
if ( V_26 != F_34 ( V_25 , 0 ) )
F_27 ( V_24 L_9 ,
V_26 , F_34 ( V_25 , 0 ) ) ;
}
return F_34 ( V_25 , V_22 ) ;
}
static T_8 * F_35 ( T_7 * V_26 , unsigned long V_22 )
{
if ( F_36 ( * V_26 ) ) {
T_8 * V_27 = ( T_8 * ) F_20 () ;
F_37 ( & V_23 , V_26 , V_27 ) ;
if ( V_27 != F_38 ( V_26 , 0 ) )
F_27 ( V_24 L_10 ) ;
}
return F_38 ( V_26 , V_22 ) ;
}
static void F_39 ( T_6 * V_25 , unsigned long V_22 , T_8 V_28 )
{
T_7 * V_26 = F_31 ( V_25 , V_22 ) ;
T_8 * V_27 = F_35 ( V_26 , V_22 ) ;
F_40 ( V_27 , V_28 ) ;
F_41 ( V_22 ) ;
}
void F_42 ( T_4 * V_29 , unsigned long V_22 , T_8 V_28 )
{
T_4 * V_15 = V_29 + F_43 ( V_22 ) ;
T_6 * V_25 = F_28 ( V_15 , V_22 ) ;
F_39 ( V_25 , V_22 , V_28 ) ;
}
void F_44 ( T_6 * V_30 , unsigned long V_22 , T_8 V_28 )
{
T_6 * V_25 = V_30 + F_45 ( V_22 ) ;
F_39 ( V_25 , V_22 , V_28 ) ;
}
void F_46 ( unsigned long V_22 , T_8 V_31 )
{
T_2 * V_11 ;
T_4 * V_29 ;
F_24 ( L_11 , V_22 , F_47 ( V_31 ) ) ;
V_11 = F_4 ( V_22 ) ;
if ( F_5 ( * V_11 ) ) {
F_27 ( V_24
L_12 ) ;
return;
}
V_29 = F_16 ( V_11 , 0 ) ;
F_42 ( V_29 , V_22 , V_31 ) ;
}
T_7 * T_1 F_48 ( unsigned long V_22 )
{
T_2 * V_11 ;
T_4 * V_15 ;
T_6 * V_25 ;
V_11 = F_4 ( V_22 ) ;
V_15 = F_25 ( V_11 , V_22 ) ;
V_25 = F_28 ( V_15 , V_22 ) ;
return F_31 ( V_25 , V_22 ) ;
}
T_8 * T_1 F_49 ( unsigned long V_22 )
{
T_7 * V_26 ;
V_26 = F_48 ( V_22 ) ;
return F_35 ( V_26 , V_22 ) ;
}
static void T_1 F_50 ( unsigned long V_32 , unsigned long V_33 ,
enum V_34 V_35 )
{
T_2 * V_11 ;
T_4 * V_15 ;
T_6 * V_25 ;
T_7 * V_26 ;
T_9 V_36 ;
F_51 ( V_36 ) = F_51 ( V_37 ) |
F_51 ( F_52 ( F_53 ( V_35 ) ) ) ;
F_11 ( ( V_32 & ~ V_38 ) || ( V_33 & ~ V_38 ) ) ;
for (; V_33 ; V_32 += V_39 , V_33 -= V_39 ) {
V_11 = F_4 ( ( unsigned long ) F_54 ( V_32 ) ) ;
if ( F_5 ( * V_11 ) ) {
V_15 = ( T_4 * ) F_20 () ;
F_13 ( V_11 , F_55 ( F_56 ( V_15 ) | V_40 |
V_41 ) ) ;
}
V_15 = F_16 ( V_11 , ( unsigned long ) F_54 ( V_32 ) ) ;
if ( F_17 ( * V_15 ) ) {
V_25 = ( T_6 * ) F_20 () ;
F_19 ( V_15 , F_57 ( F_56 ( V_25 ) | V_40 |
V_41 ) ) ;
}
V_25 = F_30 ( V_15 , ( unsigned long ) F_54 ( V_32 ) ) ;
if ( F_32 ( * V_25 ) ) {
V_26 = ( T_7 * ) F_20 () ;
F_58 ( V_25 , F_59 ( F_56 ( V_26 ) | V_40 |
V_41 ) ) ;
}
V_26 = F_34 ( V_25 , V_32 ) ;
F_11 ( ! F_36 ( * V_26 ) ) ;
F_60 ( V_26 , F_61 ( V_32 | F_51 ( V_36 ) ) ) ;
}
}
void T_1 F_62 ( unsigned long V_32 , unsigned long V_33 )
{
F_50 ( V_32 , V_33 , V_42 ) ;
}
void T_1 F_63 ( unsigned long V_32 , unsigned long V_33 )
{
F_50 ( V_32 , V_33 , V_43 ) ;
}
void T_1 F_64 ( void )
{
unsigned long V_22 = V_44 ;
unsigned long V_45 = V_44 + V_46 ;
unsigned long V_5 = F_65 ( ( unsigned long ) V_47 , V_39 ) - 1 ;
T_7 * V_26 = V_48 ;
if ( V_49 )
V_45 = V_44 + ( V_49 << V_50 ) ;
for (; V_22 + V_39 - 1 < V_45 ; V_26 ++ , V_22 += V_39 ) {
if ( F_36 ( * V_26 ) )
continue;
if ( V_22 < ( unsigned long ) V_51 || V_22 > V_5 )
F_60 ( V_26 , F_61 ( 0 ) ) ;
}
}
static unsigned long T_10
F_66 ( T_8 * V_52 , unsigned long V_53 , unsigned long V_54 ,
T_9 V_36 )
{
unsigned long V_55 = 0 , V_56 ;
unsigned long V_57 = V_54 ;
T_8 * V_27 ;
int V_58 ;
V_27 = V_52 + F_67 ( V_53 ) ;
V_58 = F_67 ( V_53 ) ;
for (; V_58 < V_59 ; V_58 ++ , V_53 = V_56 , V_27 ++ ) {
V_56 = ( V_53 & V_21 ) + V_20 ;
if ( V_53 >= V_54 ) {
if ( ! V_17 &&
! F_68 ( V_53 & V_21 , V_56 ,
V_60 ) &&
! F_68 ( V_53 & V_21 , V_56 ,
V_61 ) )
F_40 ( V_27 , F_69 ( 0 ) ) ;
continue;
}
if ( ! F_70 ( * V_27 ) ) {
if ( ! V_17 )
V_55 ++ ;
continue;
}
if ( 0 )
F_71 ( L_13 , V_27 , V_53 ,
F_72 ( V_53 >> V_50 , V_62 ) . V_27 ) ;
V_55 ++ ;
F_40 ( V_27 , F_72 ( V_53 >> V_50 , V_36 ) ) ;
V_57 = ( V_53 & V_21 ) + V_20 ;
}
F_73 ( V_63 , V_55 ) ;
return V_57 ;
}
static unsigned long T_10
F_74 ( T_7 * V_64 , unsigned long V_53 , unsigned long V_54 ,
unsigned long V_65 , T_9 V_36 )
{
unsigned long V_55 = 0 , V_56 ;
unsigned long V_57 = V_54 ;
int V_58 = F_75 ( V_53 ) ;
for (; V_58 < V_66 ; V_58 ++ , V_53 = V_56 ) {
T_7 * V_26 = V_64 + F_75 ( V_53 ) ;
T_8 * V_27 ;
T_9 V_67 = V_36 ;
V_56 = ( V_53 & V_38 ) + V_39 ;
if ( V_53 >= V_54 ) {
if ( ! V_17 &&
! F_68 ( V_53 & V_38 , V_56 ,
V_60 ) &&
! F_68 ( V_53 & V_38 , V_56 ,
V_61 ) )
F_60 ( V_26 , F_61 ( 0 ) ) ;
continue;
}
if ( ! F_36 ( * V_26 ) ) {
if ( ! F_76 ( * V_26 ) ) {
F_6 ( & V_23 . V_13 ) ;
V_27 = ( T_8 * ) F_77 ( * V_26 ) ;
V_57 = F_66 ( V_27 , V_53 ,
V_54 , V_36 ) ;
F_14 ( & V_23 . V_13 ) ;
continue;
}
if ( V_65 & ( 1 << V_68 ) ) {
if ( ! V_17 )
V_55 ++ ;
V_57 = V_56 ;
continue;
}
V_67 = F_78 ( F_79 ( * ( T_8 * ) V_26 ) ) ;
}
if ( V_65 & ( 1 << V_68 ) ) {
V_55 ++ ;
F_6 ( & V_23 . V_13 ) ;
F_40 ( ( T_8 * ) V_26 ,
F_72 ( ( V_53 & V_38 ) >> V_50 ,
F_80 ( F_51 ( V_36 ) | V_69 ) ) ) ;
F_14 ( & V_23 . V_13 ) ;
V_57 = V_56 ;
continue;
}
V_27 = F_81 () ;
V_57 = F_66 ( V_27 , V_53 , V_54 , V_67 ) ;
F_6 ( & V_23 . V_13 ) ;
F_37 ( & V_23 , V_26 , V_27 ) ;
F_14 ( & V_23 . V_13 ) ;
}
F_73 ( V_68 , V_55 ) ;
return V_57 ;
}
static unsigned long T_10
F_82 ( T_6 * V_30 , unsigned long V_53 , unsigned long V_54 ,
unsigned long V_65 )
{
unsigned long V_55 = 0 , V_56 ;
unsigned long V_57 = V_54 ;
unsigned long V_22 = ( unsigned long ) F_54 ( V_53 ) ;
int V_58 = F_45 ( V_22 ) ;
for (; V_58 < V_70 ; V_58 ++ , V_53 = V_56 ) {
T_6 * V_25 ;
T_7 * V_26 ;
T_9 V_36 = V_62 ;
V_22 = ( unsigned long ) F_54 ( V_53 ) ;
V_25 = V_30 + F_45 ( V_22 ) ;
V_56 = ( V_53 & V_71 ) + V_72 ;
if ( V_53 >= V_54 ) {
if ( ! V_17 &&
! F_68 ( V_53 & V_71 , V_56 ,
V_60 ) &&
! F_68 ( V_53 & V_71 , V_56 ,
V_61 ) )
F_58 ( V_25 , F_59 ( 0 ) ) ;
continue;
}
if ( ! F_32 ( * V_25 ) ) {
if ( ! F_83 ( * V_25 ) ) {
V_26 = F_34 ( V_25 , 0 ) ;
V_57 = F_74 ( V_26 , V_53 ,
V_54 ,
V_65 ,
V_36 ) ;
F_84 () ;
continue;
}
if ( V_65 & ( 1 << V_73 ) ) {
if ( ! V_17 )
V_55 ++ ;
V_57 = V_56 ;
continue;
}
V_36 = F_78 ( F_79 ( * ( T_8 * ) V_25 ) ) ;
}
if ( V_65 & ( 1 << V_73 ) ) {
V_55 ++ ;
F_6 ( & V_23 . V_13 ) ;
F_40 ( ( T_8 * ) V_25 ,
F_72 ( ( V_53 & V_71 ) >> V_50 ,
V_37 ) ) ;
F_14 ( & V_23 . V_13 ) ;
V_57 = V_56 ;
continue;
}
V_26 = F_81 () ;
V_57 = F_74 ( V_26 , V_53 , V_54 ,
V_65 , V_36 ) ;
F_6 ( & V_23 . V_13 ) ;
F_33 ( & V_23 , V_25 , V_26 ) ;
F_14 ( & V_23 . V_13 ) ;
}
F_84 () ;
F_73 ( V_73 , V_55 ) ;
return V_57 ;
}
static unsigned long T_10
F_85 ( T_4 * V_29 , unsigned long V_53 , unsigned long V_54 ,
unsigned long V_65 )
{
unsigned long V_56 , V_57 = V_54 ;
unsigned long V_22 = ( unsigned long ) F_54 ( V_53 ) ;
int V_58 = F_43 ( V_22 ) ;
if ( ! F_86 ( V_74 ) )
return F_82 ( ( T_6 * ) V_29 , V_53 , V_54 , V_65 ) ;
for (; V_58 < V_75 ; V_58 ++ , V_53 = V_56 ) {
T_4 * V_15 ;
T_6 * V_25 ;
V_22 = ( unsigned long ) F_54 ( V_53 ) ;
V_15 = V_29 + F_43 ( V_22 ) ;
V_56 = ( V_53 & V_76 ) + V_77 ;
if ( V_53 >= V_54 ) {
if ( ! V_17 &&
! F_68 ( V_53 & V_76 , V_56 ,
V_60 ) &&
! F_68 ( V_53 & V_76 , V_56 ,
V_61 ) )
F_19 ( V_15 , F_57 ( 0 ) ) ;
continue;
}
if ( ! F_17 ( * V_15 ) ) {
V_25 = F_30 ( V_15 , 0 ) ;
V_57 = F_82 ( V_25 , V_53 ,
V_54 ,
V_65 ) ;
F_84 () ;
continue;
}
V_25 = F_81 () ;
V_57 = F_82 ( V_25 , V_53 , V_54 ,
V_65 ) ;
F_6 ( & V_23 . V_13 ) ;
F_29 ( & V_23 , V_15 , V_25 ) ;
F_14 ( & V_23 . V_13 ) ;
}
F_84 () ;
return V_57 ;
}
unsigned long T_10
F_87 ( unsigned long V_78 ,
unsigned long V_54 ,
unsigned long V_65 )
{
bool V_79 = false ;
unsigned long V_22 , V_80 , V_45 , V_81 , V_57 ;
V_57 = V_54 ;
V_22 = ( unsigned long ) F_54 ( V_78 ) ;
V_45 = ( unsigned long ) F_54 ( V_54 ) ;
V_80 = V_22 ;
for (; V_22 < V_45 ; V_22 = V_81 ) {
T_2 * V_11 = F_4 ( V_22 ) ;
T_4 * V_15 ;
V_81 = ( V_22 & V_82 ) + V_7 ;
if ( F_88 ( * V_11 ) ) {
V_15 = ( T_4 * ) F_12 ( * V_11 ) ;
V_57 = F_85 ( V_15 , F_56 ( V_22 ) ,
F_56 ( V_45 ) ,
V_65 ) ;
continue;
}
V_15 = F_81 () ;
V_57 = F_85 ( V_15 , F_56 ( V_22 ) , F_56 ( V_45 ) ,
V_65 ) ;
F_6 ( & V_23 . V_13 ) ;
if ( F_86 ( V_74 ) )
F_26 ( & V_23 , V_11 , V_15 ) ;
else
F_29 ( & V_23 , F_16 ( V_11 , V_22 ) , ( T_6 * ) V_15 ) ;
F_14 ( & V_23 . V_13 ) ;
V_79 = true ;
}
if ( V_79 )
F_2 ( V_80 , V_45 - 1 ) ;
F_84 () ;
return V_57 ;
}
void T_1 F_89 ( void )
{
F_90 ( 0 , ( V_83 ) V_84 , & V_85 . V_86 , 0 ) ;
}
void T_1 F_91 ( void )
{
F_92 ( V_87 ) ;
F_93 () ;
F_94 ( 0 , V_88 ) ;
if ( V_88 != V_89 )
F_94 ( 0 , V_89 ) ;
F_95 () ;
}
static void F_96 ( T_11 V_4 , T_11 V_33 )
{
unsigned long V_90 = F_97 ( V_4 + V_33 ) ;
if ( V_90 > V_91 ) {
V_91 = V_90 ;
V_92 = V_90 ;
V_93 = ( void * ) F_54 ( V_91 * V_20 - 1 ) + 1 ;
}
}
int F_98 ( int V_94 , T_11 V_4 , T_11 V_33 , bool V_95 )
{
unsigned long V_96 = V_4 >> V_50 ;
unsigned long V_97 = V_33 >> V_50 ;
int V_98 ;
F_99 ( V_4 , V_4 + V_33 ) ;
V_98 = F_100 ( V_94 , V_96 , V_97 , V_95 ) ;
F_101 ( V_98 ) ;
F_96 ( V_4 , V_33 ) ;
return V_98 ;
}
static void T_10 F_102 ( struct V_9 * V_9 , int V_99 )
{
unsigned long V_100 ;
unsigned int V_97 = 1 << V_99 ;
struct V_101 * V_102 = F_103 ( ( unsigned long ) V_9 ) ;
if ( V_102 ) {
F_104 ( V_102 , V_97 ) ;
return;
}
if ( F_105 ( V_9 ) ) {
F_106 ( V_9 ) ;
V_100 = ( unsigned long ) V_9 -> V_103 ;
if ( V_100 == V_104 || V_100 == V_105 ) {
while ( V_97 -- )
F_107 ( V_9 ++ ) ;
} else
while ( V_97 -- )
F_108 ( V_9 ++ ) ;
} else
F_109 ( ( unsigned long ) F_8 ( V_9 ) , V_99 ) ;
}
static void T_10 F_110 ( T_8 * V_106 , T_7 * V_26 )
{
T_8 * V_27 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
V_27 = V_106 + V_58 ;
if ( ! F_70 ( * V_27 ) )
return;
}
F_102 ( V_64 ( * V_26 ) , 0 ) ;
F_6 ( & V_23 . V_13 ) ;
F_111 ( V_26 ) ;
F_14 ( & V_23 . V_13 ) ;
}
static void T_10 F_112 ( T_7 * V_107 , T_6 * V_25 )
{
T_7 * V_26 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_66 ; V_58 ++ ) {
V_26 = V_107 + V_58 ;
if ( ! F_36 ( * V_26 ) )
return;
}
F_102 ( V_30 ( * V_25 ) , 0 ) ;
F_6 ( & V_23 . V_13 ) ;
F_113 ( V_25 ) ;
F_14 ( & V_23 . V_13 ) ;
}
static void T_10 F_114 ( T_6 * V_108 , T_4 * V_15 )
{
T_6 * V_25 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_70 ; V_58 ++ ) {
V_25 = V_108 + V_58 ;
if ( ! F_32 ( * V_25 ) )
return;
}
F_102 ( V_29 ( * V_15 ) , 0 ) ;
F_6 ( & V_23 . V_13 ) ;
F_115 ( V_15 ) ;
F_14 ( & V_23 . V_13 ) ;
}
static void T_10
F_116 ( T_8 * V_106 , unsigned long V_6 , unsigned long V_5 ,
bool V_109 )
{
unsigned long V_110 , V_55 = 0 ;
T_8 * V_27 ;
void * V_111 ;
V_83 V_112 ;
V_27 = V_106 + F_67 ( V_6 ) ;
for (; V_6 < V_5 ; V_6 = V_110 , V_27 ++ ) {
V_110 = ( V_6 + V_20 ) & V_21 ;
if ( V_110 > V_5 )
V_110 = V_5 ;
if ( ! F_117 ( * V_27 ) )
continue;
V_112 = F_118 ( * V_27 ) + ( V_6 & V_21 ) ;
if ( V_112 < ( V_83 ) 0x40000000 )
return;
if ( F_119 ( V_6 ) && F_119 ( V_110 ) ) {
if ( ! V_109 )
F_102 ( V_52 ( * V_27 ) , 0 ) ;
F_6 ( & V_23 . V_13 ) ;
F_120 ( & V_23 , V_6 , V_27 ) ;
F_14 ( & V_23 . V_13 ) ;
V_55 ++ ;
} else {
memset ( ( void * ) V_6 , V_113 , V_110 - V_6 ) ;
V_111 = F_8 ( V_52 ( * V_27 ) ) ;
if ( ! F_121 ( V_111 , V_113 , V_20 ) ) {
F_102 ( V_52 ( * V_27 ) , 0 ) ;
F_6 ( & V_23 . V_13 ) ;
F_120 ( & V_23 , V_6 , V_27 ) ;
F_14 ( & V_23 . V_13 ) ;
}
}
}
F_122 () ;
if ( V_109 )
F_73 ( V_63 , - V_55 ) ;
}
static void T_10
F_123 ( T_7 * V_107 , unsigned long V_6 , unsigned long V_5 ,
bool V_109 )
{
unsigned long V_110 , V_55 = 0 ;
T_8 * V_114 ;
T_7 * V_26 ;
void * V_111 ;
V_26 = V_107 + F_75 ( V_6 ) ;
for (; V_6 < V_5 ; V_6 = V_110 , V_26 ++ ) {
V_110 = F_124 ( V_6 , V_5 ) ;
if ( ! F_125 ( * V_26 ) )
continue;
if ( F_76 ( * V_26 ) ) {
if ( F_126 ( V_6 , V_39 ) &&
F_126 ( V_110 , V_39 ) ) {
if ( ! V_109 )
F_102 ( V_64 ( * V_26 ) ,
F_127 ( V_39 ) ) ;
F_6 ( & V_23 . V_13 ) ;
F_111 ( V_26 ) ;
F_14 ( & V_23 . V_13 ) ;
V_55 ++ ;
} else {
memset ( ( void * ) V_6 , V_113 , V_110 - V_6 ) ;
V_111 = F_8 ( V_64 ( * V_26 ) ) ;
if ( ! F_121 ( V_111 , V_113 ,
V_39 ) ) {
F_102 ( V_64 ( * V_26 ) ,
F_127 ( V_39 ) ) ;
F_6 ( & V_23 . V_13 ) ;
F_111 ( V_26 ) ;
F_14 ( & V_23 . V_13 ) ;
}
}
continue;
}
V_114 = ( T_8 * ) F_77 ( * V_26 ) ;
F_116 ( V_114 , V_6 , V_110 , V_109 ) ;
F_110 ( V_114 , V_26 ) ;
}
if ( V_109 )
F_73 ( V_68 , - V_55 ) ;
}
static void T_10
F_128 ( T_6 * V_108 , unsigned long V_6 , unsigned long V_5 ,
bool V_109 )
{
unsigned long V_110 , V_55 = 0 ;
T_7 * V_115 ;
T_6 * V_25 ;
void * V_111 ;
V_25 = V_108 + F_45 ( V_6 ) ;
for (; V_6 < V_5 ; V_6 = V_110 , V_25 ++ ) {
V_110 = F_129 ( V_6 , V_5 ) ;
if ( ! F_130 ( * V_25 ) )
continue;
if ( F_83 ( * V_25 ) ) {
if ( F_126 ( V_6 , V_72 ) &&
F_126 ( V_110 , V_72 ) ) {
if ( ! V_109 )
F_102 ( V_30 ( * V_25 ) ,
F_127 ( V_72 ) ) ;
F_6 ( & V_23 . V_13 ) ;
F_113 ( V_25 ) ;
F_14 ( & V_23 . V_13 ) ;
V_55 ++ ;
} else {
memset ( ( void * ) V_6 , V_113 , V_110 - V_6 ) ;
V_111 = F_8 ( V_30 ( * V_25 ) ) ;
if ( ! F_121 ( V_111 , V_113 ,
V_72 ) ) {
F_102 ( V_30 ( * V_25 ) ,
F_127 ( V_72 ) ) ;
F_6 ( & V_23 . V_13 ) ;
F_113 ( V_25 ) ;
F_14 ( & V_23 . V_13 ) ;
}
}
continue;
}
V_115 = F_34 ( V_25 , 0 ) ;
F_123 ( V_115 , V_6 , V_110 , V_109 ) ;
F_112 ( V_115 , V_25 ) ;
}
if ( V_109 )
F_73 ( V_73 , - V_55 ) ;
}
static void T_10
F_131 ( T_4 * V_116 , unsigned long V_6 , unsigned long V_5 ,
bool V_109 )
{
unsigned long V_110 , V_55 = 0 ;
T_6 * V_117 ;
T_4 * V_15 ;
V_15 = V_116 + F_43 ( V_6 ) ;
for (; V_6 < V_5 ; V_6 = V_110 , V_15 ++ ) {
V_110 = F_132 ( V_6 , V_5 ) ;
if ( ! F_133 ( * V_15 ) )
continue;
F_15 ( F_134 ( * V_15 ) ) ;
V_117 = F_30 ( V_15 , 0 ) ;
F_128 ( V_117 , V_6 , V_110 , V_109 ) ;
if ( V_118 == 5 )
F_114 ( V_117 , V_15 ) ;
}
if ( V_109 )
F_73 ( V_119 , - V_55 ) ;
}
static void T_10
F_135 ( unsigned long V_4 , unsigned long V_5 , bool V_109 )
{
unsigned long V_110 ;
unsigned long V_6 ;
T_2 * V_11 ;
T_4 * V_15 ;
for ( V_6 = V_4 ; V_6 < V_5 ; V_6 = V_110 ) {
V_110 = F_136 ( V_6 , V_5 ) ;
V_11 = F_4 ( V_6 ) ;
if ( ! F_137 ( * V_11 ) )
continue;
V_15 = F_16 ( V_11 , 0 ) ;
F_131 ( V_15 , V_6 , V_110 , V_109 ) ;
}
F_122 () ;
}
void T_5 F_138 ( unsigned long V_4 , unsigned long V_5 )
{
F_135 ( V_4 , V_5 , false ) ;
}
static void T_10
F_139 ( unsigned long V_4 , unsigned long V_5 )
{
V_4 = ( unsigned long ) F_54 ( V_4 ) ;
V_5 = ( unsigned long ) F_54 ( V_5 ) ;
F_135 ( V_4 , V_5 , true ) ;
}
int T_5 F_140 ( T_11 V_4 , T_11 V_33 )
{
unsigned long V_96 = V_4 >> V_50 ;
unsigned long V_97 = V_33 >> V_50 ;
struct V_9 * V_9 = F_141 ( V_96 ) ;
struct V_101 * V_102 ;
struct V_120 * V_120 ;
int V_98 ;
V_102 = F_103 ( ( unsigned long ) V_9 ) ;
if ( V_102 )
V_9 += F_142 ( V_102 ) ;
V_120 = F_143 ( V_9 ) ;
V_98 = F_144 ( V_120 , V_96 , V_97 ) ;
F_101 ( V_98 ) ;
F_139 ( V_4 , V_4 + V_33 ) ;
return V_98 ;
}
static void T_1 F_145 ( void )
{
#ifdef F_146
int V_58 ;
F_147 (i)
F_148 ( F_149 ( V_58 ) ) ;
#endif
}
void T_1 F_150 ( void )
{
F_151 () ;
F_145 () ;
F_152 () ;
V_17 = 1 ;
F_153 ( & V_121 , ( void * ) V_122 ,
V_20 , V_123 ) ;
F_154 ( NULL ) ;
}
void F_155 ( void )
{
unsigned long V_4 = F_156 ( V_51 ) ;
unsigned long V_5 = F_156 ( V_124 ) ;
if ( ! V_125 )
return;
F_24 ( L_14 ,
V_4 , V_5 ) ;
F_157 ( V_4 , ( V_5 - V_4 ) >> V_50 ) ;
}
void F_158 ( void )
{
unsigned long V_4 = F_156 ( V_51 ) ;
unsigned long V_5 = F_156 ( V_124 ) ;
if ( ! V_125 )
return;
F_24 ( L_15 ,
V_4 , V_5 ) ;
F_159 ( V_4 , ( V_5 - V_4 ) >> V_50 ) ;
}
void F_160 ( void )
{
unsigned long V_4 = F_156 ( V_51 ) ;
unsigned long V_126 = F_156 ( V_127 ) ;
unsigned long V_5 = ( unsigned long ) & V_128 ;
unsigned long V_129 = F_156 ( & V_124 ) ;
unsigned long V_130 = F_156 ( & V_131 ) ;
unsigned long V_132 ;
F_27 ( V_133 L_16 ,
( V_5 - V_4 ) >> 10 ) ;
F_159 ( V_4 , ( V_5 - V_4 ) >> V_50 ) ;
V_125 = 1 ;
V_132 = F_65 ( ( unsigned long ) V_47 , V_39 ) ;
F_161 ( V_129 , ( V_132 - V_129 ) >> V_50 ) ;
#ifdef F_162
F_27 ( V_133 L_17 , V_4 , V_5 ) ;
F_157 ( V_4 , ( V_5 - V_4 ) >> V_50 ) ;
F_27 ( V_133 L_18 ) ;
F_159 ( V_4 , ( V_5 - V_4 ) >> V_50 ) ;
#endif
F_163 ( L_19 ,
( unsigned long ) F_54 ( F_164 ( V_129 ) ) ,
( unsigned long ) F_54 ( F_164 ( V_126 ) ) ) ;
F_163 ( L_19 ,
( unsigned long ) F_54 ( F_164 ( V_130 ) ) ,
( unsigned long ) F_54 ( F_164 ( V_134 ) ) ) ;
F_165 () ;
}
int F_166 ( unsigned long V_6 )
{
unsigned long V_135 = ( ( long ) V_6 ) >> V_136 ;
T_2 * V_11 ;
T_4 * V_15 ;
T_6 * V_25 ;
T_7 * V_26 ;
T_8 * V_27 ;
if ( V_135 != 0 && V_135 != - 1UL )
return 0 ;
V_11 = F_4 ( V_6 ) ;
if ( F_5 ( * V_11 ) )
return 0 ;
V_15 = F_16 ( V_11 , V_6 ) ;
if ( F_17 ( * V_15 ) )
return 0 ;
V_25 = F_30 ( V_15 , V_6 ) ;
if ( F_32 ( * V_25 ) )
return 0 ;
if ( F_83 ( * V_25 ) )
return F_167 ( F_168 ( * V_25 ) ) ;
V_26 = F_34 ( V_25 , V_6 ) ;
if ( F_36 ( * V_26 ) )
return 0 ;
if ( F_76 ( * V_26 ) )
return F_167 ( F_169 ( * V_26 ) ) ;
V_27 = F_38 ( V_26 , V_6 ) ;
if ( F_70 ( * V_27 ) )
return 0 ;
return F_167 ( F_170 ( * V_27 ) ) ;
}
static unsigned long F_171 ( void )
{
unsigned long V_137 = V_138 ;
if ( F_172 () || ( ( V_91 << V_50 ) >= ( 64UL << 30 ) ) )
V_137 = 2UL << 30 ;
F_71 ( L_20 , V_137 >> 20 ) ;
return V_137 ;
}
unsigned long F_173 ( void )
{
if ( ! V_139 )
V_139 = F_171 () ;
return V_139 ;
}
static int T_10 F_174 ( unsigned long V_4 ,
unsigned long V_5 , int V_140 , struct V_101 * V_102 )
{
unsigned long V_6 ;
unsigned long V_110 ;
T_2 * V_11 ;
T_4 * V_15 ;
T_6 * V_25 ;
T_7 * V_26 ;
for ( V_6 = V_4 ; V_6 < V_5 ; V_6 = V_110 ) {
V_110 = F_124 ( V_6 , V_5 ) ;
V_11 = F_175 ( V_6 , V_140 ) ;
if ( ! V_11 )
return - V_141 ;
V_15 = F_176 ( V_11 , V_6 , V_140 ) ;
if ( ! V_15 )
return - V_141 ;
V_25 = F_177 ( V_15 , V_6 , V_140 ) ;
if ( ! V_25 )
return - V_141 ;
V_26 = F_34 ( V_25 , V_6 ) ;
if ( F_36 ( * V_26 ) ) {
void * V_142 ;
V_142 = F_178 ( V_39 , V_140 , V_102 ) ;
if ( V_142 ) {
T_8 V_143 ;
V_143 = F_72 ( F_56 ( V_142 ) >> V_50 ,
V_37 ) ;
F_60 ( V_26 , F_61 ( F_118 ( V_143 ) ) ) ;
if ( V_144 != V_142 || V_145 != V_140 ) {
if ( V_146 )
F_24 ( L_21 ,
V_147 , V_148 - 1 , V_146 , V_144 - 1 , V_145 ) ;
V_147 = V_6 ;
V_145 = V_140 ;
V_146 = V_142 ;
}
V_148 = V_6 + V_39 ;
V_144 = V_142 + V_39 ;
continue;
} else if ( V_102 )
return - V_141 ;
} else if ( F_76 ( * V_26 ) ) {
F_179 ( ( T_8 * ) V_26 , V_140 , V_6 , V_110 ) ;
continue;
}
F_180 ( L_22 ) ;
if ( F_181 ( V_6 , V_110 , V_140 ) )
return - V_141 ;
}
return 0 ;
}
int T_10 F_182 ( unsigned long V_4 , unsigned long V_5 , int V_140 )
{
struct V_101 * V_102 = F_103 ( V_4 ) ;
int V_149 ;
if ( F_183 ( V_150 ) )
V_149 = F_174 ( V_4 , V_5 , V_140 , V_102 ) ;
else if ( V_102 ) {
F_184 ( L_23 ,
V_151 ) ;
V_149 = - V_141 ;
} else
V_149 = F_181 ( V_4 , V_5 , V_140 ) ;
if ( ! V_149 )
F_2 ( V_4 , V_5 - 1 ) ;
return V_149 ;
}
void F_185 ( unsigned long V_152 ,
struct V_9 * V_153 , unsigned long V_33 )
{
unsigned long V_6 = ( unsigned long ) V_153 ;
unsigned long V_5 = ( unsigned long ) ( V_153 + V_33 ) ;
unsigned long V_110 ;
T_2 * V_11 ;
T_4 * V_15 ;
T_6 * V_25 ;
T_7 * V_26 ;
unsigned int V_97 ;
struct V_9 * V_9 ;
for (; V_6 < V_5 ; V_6 = V_110 ) {
T_8 * V_27 = NULL ;
V_11 = F_4 ( V_6 ) ;
if ( F_5 ( * V_11 ) ) {
V_110 = ( V_6 + V_20 ) & V_21 ;
continue;
}
F_186 ( V_152 , F_187 ( * V_11 ) , V_105 ) ;
V_15 = F_16 ( V_11 , V_6 ) ;
if ( F_17 ( * V_15 ) ) {
V_110 = ( V_6 + V_20 ) & V_21 ;
continue;
}
F_186 ( V_152 , V_29 ( * V_15 ) , V_105 ) ;
V_25 = F_30 ( V_15 , V_6 ) ;
if ( F_32 ( * V_25 ) ) {
V_110 = ( V_6 + V_20 ) & V_21 ;
continue;
}
F_186 ( V_152 , V_30 ( * V_25 ) , V_105 ) ;
if ( ! F_183 ( V_150 ) ) {
V_110 = ( V_6 + V_20 ) & V_21 ;
V_26 = F_34 ( V_25 , V_6 ) ;
if ( F_36 ( * V_26 ) )
continue;
F_186 ( V_152 , V_64 ( * V_26 ) ,
V_105 ) ;
V_27 = F_38 ( V_26 , V_6 ) ;
if ( F_70 ( * V_27 ) )
continue;
F_186 ( V_152 , V_52 ( * V_27 ) ,
V_104 ) ;
} else {
V_110 = F_124 ( V_6 , V_5 ) ;
V_26 = F_34 ( V_25 , V_6 ) ;
if ( F_36 ( * V_26 ) )
continue;
V_97 = 1 << ( F_127 ( V_39 ) ) ;
V_9 = V_64 ( * V_26 ) ;
while ( V_97 -- )
F_186 ( V_152 , V_9 ++ ,
V_104 ) ;
}
}
}
void T_10 F_188 ( void )
{
if ( V_146 ) {
F_24 ( L_21 ,
V_147 , V_148 - 1 , V_146 , V_144 - 1 , V_145 ) ;
V_146 = NULL ;
V_144 = NULL ;
V_145 = 0 ;
}
}
