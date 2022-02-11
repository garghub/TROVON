static inline void
F_1 ( struct V_1 * V_1 , unsigned int V_2 , T_1 V_3 )
{
unsigned long V_4 ;
F_2 ( & V_1 -> V_5 , V_4 ) ;
F_3 ( V_1 -> V_6 , V_2 , V_3 ) ;
F_4 ( & V_1 -> V_5 , V_4 ) ;
}
static inline int
F_5 ( unsigned int V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
if ( ( unsigned ) ( V_7 - V_10 [ V_8 ] . V_11 ) <
V_10 [ V_8 ] . V_12 )
return V_8 ;
}
return - 1 ;
}
static inline int F_6 ( unsigned int V_7 )
{
int V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ ) {
V_15 = & V_14 [ V_13 ] ;
F_7 (rte, &info->rtes, rte_list)
if ( V_17 -> V_1 -> V_11 + V_17 -> V_19 == V_7 )
return V_13 ;
}
return - 1 ;
}
int
F_8 ( unsigned int V_7 )
{
unsigned long V_4 ;
int V_13 ;
F_2 ( & V_20 , V_4 ) ;
V_13 = F_6 ( V_7 ) ;
F_4 ( & V_20 , V_4 ) ;
return V_13 ;
}
static struct V_16 * F_9 ( unsigned int V_13 , unsigned int V_7 )
{
struct V_16 * V_17 ;
F_7 (rte, &iosapic_intr_info[irq].rtes, rte_list)
if ( V_17 -> V_1 -> V_11 + V_17 -> V_19 == V_7 )
return V_17 ;
return NULL ;
}
static void
F_10 ( unsigned int V_7 , unsigned int V_13 , unsigned int V_21 , int V_22 )
{
unsigned long V_23 , V_24 , V_25 ;
T_1 V_26 , V_27 ;
int V_19 ;
char V_28 ;
struct V_16 * V_17 ;
T_2 V_29 = F_11 ( V_13 ) ;
F_12 ( V_30 L_1 , V_29 , V_21 ) ;
V_17 = F_9 ( V_13 , V_7 ) ;
if ( ! V_17 )
return;
V_19 = V_17 -> V_19 ;
V_23 = V_14 [ V_13 ] . V_31 ;
V_24 = V_14 [ V_13 ] . V_24 ;
V_25 = V_14 [ V_13 ] . V_25 ;
V_28 = ( V_25 == V_32 ) ? 1 : 0 ;
#ifdef F_13
F_14 ( V_13 , ( int ) ( V_21 & 0xffff ) , V_28 ) ;
#endif
V_26 = ( ( V_23 << V_33 ) |
( V_24 << V_34 ) |
( V_25 << V_35 ) |
( ( V_22 ? 1 : 0 ) << V_36 ) |
V_29 ) ;
V_27 = ( V_21 << V_37 ) ;
F_1 ( V_17 -> V_1 , F_15 ( V_19 ) , V_27 ) ;
F_1 ( V_17 -> V_1 , F_16 ( V_19 ) , V_26 ) ;
V_14 [ V_13 ] . V_26 = V_26 ;
V_14 [ V_13 ] . V_21 = V_21 ;
}
static void
F_17 ( struct V_38 * V_39 )
{
}
void
F_18 ( void )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
T_2 V_40 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ ) {
V_15 = & V_14 [ V_13 ] ;
V_40 = F_11 ( V_13 ) ;
F_7 (rte, &info->rtes,
rte_list) {
F_1 ( V_17 -> V_1 ,
F_16 ( V_17 -> V_19 ) ,
V_41 | V_40 ) ;
F_19 ( V_17 -> V_1 -> V_6 , V_40 ) ;
}
}
}
static void
F_20 ( struct V_38 * V_39 )
{
unsigned int V_13 = V_39 -> V_13 ;
T_1 V_26 ;
int V_19 ;
struct V_16 * V_17 ;
if ( ! V_14 [ V_13 ] . V_42 )
return;
V_26 = V_14 [ V_13 ] . V_26 |= V_41 ;
F_7 (rte, &iosapic_intr_info[irq].rtes, rte_list) {
V_19 = V_17 -> V_19 ;
F_1 ( V_17 -> V_1 , F_16 ( V_19 ) , V_26 ) ;
}
}
static void
F_21 ( struct V_38 * V_39 )
{
unsigned int V_13 = V_39 -> V_13 ;
T_1 V_26 ;
int V_19 ;
struct V_16 * V_17 ;
if ( ! V_14 [ V_13 ] . V_42 )
return;
V_26 = V_14 [ V_13 ] . V_26 &= ~ V_41 ;
F_7 (rte, &iosapic_intr_info[irq].rtes, rte_list) {
V_19 = V_17 -> V_19 ;
F_1 ( V_17 -> V_1 , F_16 ( V_19 ) , V_26 ) ;
}
}
static int
F_22 ( struct V_38 * V_39 , const struct V_43 * V_22 ,
bool V_44 )
{
#ifdef F_13
unsigned int V_13 = V_39 -> V_13 ;
T_1 V_27 , V_26 ;
int V_45 , V_21 , V_19 ;
int V_28 = ( V_13 & V_46 ) ? 1 : 0 ;
struct V_16 * V_17 ;
struct V_1 * V_1 ;
V_13 &= ( ~ V_46 ) ;
V_45 = F_23 ( V_47 , V_22 ) ;
if ( V_45 >= V_48 )
return - 1 ;
if ( F_24 ( V_13 , V_45 ) )
return - 1 ;
V_21 = F_25 ( V_45 ) ;
if ( ! V_14 [ V_13 ] . V_42 )
return - 1 ;
F_14 ( V_13 , V_21 , V_28 ) ;
V_27 = V_21 << V_37 ;
V_26 = V_14 [ V_13 ] . V_26 & ~ ( 7 << V_35 ) ;
if ( V_28 )
V_26 |= ( V_32 << V_35 ) ;
else
V_26 |= ( V_49 << V_35 ) ;
V_26 &= V_50 ;
V_26 |= F_11 ( V_13 ) ;
V_14 [ V_13 ] . V_26 = V_26 ;
V_14 [ V_13 ] . V_21 = V_21 ;
F_7 (rte, &iosapic_intr_info[irq].rtes, rte_list) {
V_1 = V_17 -> V_1 ;
V_19 = V_17 -> V_19 ;
F_1 ( V_1 , F_15 ( V_19 ) , V_27 ) ;
F_1 ( V_1 , F_16 ( V_19 ) , V_26 ) ;
}
#endif
return 0 ;
}
static unsigned int
F_26 ( struct V_38 * V_39 )
{
F_21 ( V_39 ) ;
return 0 ;
}
static void
F_27 ( struct V_38 * V_39 )
{
unsigned int V_13 = V_39 -> V_13 ;
T_2 V_40 = F_11 ( V_13 ) ;
struct V_16 * V_17 ;
int V_51 = 0 ;
F_28 ( V_13 ) ;
if ( F_29 ( F_30 ( V_39 ) ) ) {
V_51 = 1 ;
F_20 ( V_39 ) ;
} else
F_21 ( V_39 ) ;
F_7 (rte, &iosapic_intr_info[irq].rtes, rte_list)
F_19 ( V_17 -> V_1 -> V_6 , V_40 ) ;
if ( F_29 ( V_51 ) ) {
F_31 ( V_39 ) ;
F_21 ( V_39 ) ;
}
}
static unsigned int
F_32 ( struct V_38 * V_39 )
{
F_21 ( V_39 ) ;
return 0 ;
}
static void
F_33 ( struct V_38 * V_39 )
{
F_28 ( V_39 -> V_13 ) ;
F_34 ( V_39 ) ;
}
static unsigned int
F_35 ( char T_3 * V_6 )
{
return F_36 ( V_6 , V_52 ) ;
}
static int F_37 ( unsigned long V_24 , unsigned long V_23 )
{
int V_8 , V_13 = - V_53 , V_54 = - 1 ;
struct V_14 * V_15 ;
if ( V_24 == V_55 )
return - V_56 ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ ) {
V_15 = & V_14 [ V_8 ] ;
if ( V_15 -> V_24 == V_24 && V_15 -> V_31 == V_23 &&
( V_15 -> V_25 == V_49 ||
V_15 -> V_25 == V_32 ) &&
F_38 ( V_8 , V_57 ) ) {
if ( V_54 == - 1 || V_15 -> V_42 < V_54 ) {
V_13 = V_8 ;
V_54 = V_15 -> V_42 ;
}
}
}
return V_13 ;
}
static void T_4
F_39 ( int V_13 )
{
int V_58 ;
if ( V_14 [ V_13 ] . V_42 ) {
V_58 = F_40 () ;
if ( V_58 < 0 )
F_41 ( L_2 , V_59 ) ;
F_42 ( V_60 L_3 ,
F_11 ( V_13 ) , F_11 ( V_58 ) ) ;
memcpy ( & V_14 [ V_58 ] , & V_14 [ V_13 ] ,
sizeof( struct V_14 ) ) ;
F_43 ( & V_14 [ V_58 ] . V_61 ) ;
F_44 ( V_14 [ V_13 ] . V_61 . V_62 ,
& V_14 [ V_58 ] . V_61 ) ;
memset ( & V_14 [ V_13 ] , 0 ,
sizeof( struct V_14 ) ) ;
V_14 [ V_13 ] . V_26 = V_41 ;
F_43 ( & V_14 [ V_13 ] . V_61 ) ;
}
}
static inline int F_45 ( int V_13 )
{
return ( V_14 [ V_13 ] . V_42 > 1 ) ;
}
struct V_63 *
F_46 ( unsigned long V_24 )
{
if ( V_24 == V_55 )
return & V_64 ;
else
return & V_65 ;
}
static int
F_47 ( unsigned int V_7 , int V_13 , unsigned char V_66 ,
unsigned long V_31 , unsigned long V_24 )
{
struct V_63 * V_67 , * V_68 ;
int V_69 ;
struct V_16 * V_17 ;
V_69 = F_5 ( V_7 ) ;
if ( V_69 < 0 ) {
F_42 ( V_70 L_4 ,
V_59 , V_7 ) ;
return - V_71 ;
}
V_17 = F_9 ( V_13 , V_7 ) ;
if ( ! V_17 ) {
V_17 = F_48 ( sizeof ( * V_17 ) , V_72 ) ;
if ( ! V_17 ) {
F_42 ( V_70 L_5 ,
V_59 ) ;
return - V_73 ;
}
V_17 -> V_1 = & V_10 [ V_69 ] ;
V_17 -> V_19 = V_7 - V_17 -> V_1 -> V_11 ;
V_17 -> V_74 ++ ;
F_49 ( & V_17 -> V_75 , & V_14 [ V_13 ] . V_61 ) ;
V_14 [ V_13 ] . V_42 ++ ;
V_10 [ V_69 ] . V_76 ++ ;
}
else if ( V_17 -> V_74 == V_77 ) {
struct V_14 * V_15 = & V_14 [ V_13 ] ;
if ( V_15 -> V_42 > 0 &&
( V_15 -> V_24 != V_24 || V_15 -> V_31 != V_31 ) ) {
F_42 ( V_70
L_6 ,
V_59 ) ;
return - V_56 ;
}
V_17 -> V_74 ++ ;
V_14 [ V_13 ] . V_42 ++ ;
V_10 [ V_69 ] . V_76 ++ ;
}
V_14 [ V_13 ] . V_31 = V_31 ;
V_14 [ V_13 ] . V_25 = V_66 ;
V_14 [ V_13 ] . V_24 = V_24 ;
V_68 = F_50 ( V_24 ) ;
V_67 = F_51 ( V_13 ) ;
if ( V_68 != NULL && V_67 != V_68 ) {
if ( V_67 != & V_78 )
F_42 ( V_70
L_7 ,
V_59 , F_11 ( V_13 ) ,
V_67 -> V_79 , V_68 -> V_79 ) ;
V_67 = V_68 ;
}
F_52 ( F_53 ( V_13 ) , V_67 ,
V_24 == V_55 ? V_80 : V_81 ,
NULL ) ;
return 0 ;
}
static unsigned int
F_54 ( unsigned int V_7 , int V_13 )
{
#ifdef F_13
static int V_45 = - 1 ;
extern int V_82 ;
T_5 V_83 = F_55 ( V_13 ) ;
if ( V_14 [ V_13 ] . V_42 )
return V_14 [ V_13 ] . V_21 ;
if ( V_84 & V_85 )
return F_25 ( F_56 () ) ;
if ( ! F_57 ( F_56 () ) )
return F_25 ( F_56 () ) ;
#ifdef F_58
if ( V_82 > 0 && F_11 ( V_13 ) == V_86 )
return F_59 () ;
#endif
#ifdef F_60
{
int V_87 , V_88 , V_89 , V_90 , V_8 = 0 ;
const struct V_43 * V_91 ;
V_89 = F_5 ( V_7 ) ;
if ( V_89 < 0 ||
V_10 [ V_89 ] . V_92 == V_93 )
goto V_94;
V_91 = F_61 ( V_10 [ V_89 ] . V_92 ) ;
V_87 = 0 ;
F_62 (numa_cpu, cpu_mask, &domain) {
if ( F_57 ( V_90 ) )
V_87 ++ ;
}
if ( ! V_87 )
goto V_94;
V_88 = V_13 % V_87 ;
F_62 (numa_cpu, cpu_mask, &domain)
if ( F_57 ( V_90 ) && V_8 ++ >= V_88 )
break;
if ( V_90 < V_48 )
return F_25 ( V_90 ) ;
}
V_94:
#endif
do {
if ( ++ V_45 >= V_48 )
V_45 = 0 ;
} while ( ! F_57 ( V_45 ) || ! F_63 ( V_45 , & V_83 ) );
return F_25 ( V_45 ) ;
#else
return F_25 ( F_56 () ) ;
#endif
}
static inline unsigned char F_64 ( void )
{
#ifdef F_13
if ( V_84 & V_85 )
return V_32 ;
#endif
return V_49 ;
}
int
F_65 ( unsigned int V_7 ,
unsigned long V_31 , unsigned long V_24 )
{
int V_13 , V_22 = 1 , V_95 ;
unsigned int V_21 ;
unsigned long V_4 ;
struct V_16 * V_17 ;
T_1 V_26 ;
unsigned char V_25 ;
struct V_96 * V_97 ;
F_2 ( & V_20 , V_4 ) ;
V_13 = F_6 ( V_7 ) ;
if ( V_13 > 0 ) {
V_17 = F_9 ( V_13 , V_7 ) ;
if( V_14 [ V_13 ] . V_42 == 0 ) {
F_66 ( V_13 ) ;
F_67 ( V_13 ) ;
} else if ( V_17 -> V_74 != V_77 ) {
V_17 -> V_74 ++ ;
goto V_98;
}
} else
V_13 = F_40 () ;
if ( V_13 < 0 ) {
V_13 = F_37 ( V_24 , V_31 ) ;
if ( V_13 < 0 )
goto V_98;
}
V_97 = F_68 ( V_13 ) ;
F_69 ( & V_97 -> V_5 ) ;
V_21 = F_54 ( V_7 , V_13 ) ;
V_25 = F_64 () ;
V_95 = F_47 ( V_7 , V_13 , V_25 , V_31 , V_24 ) ;
if ( V_95 < 0 ) {
F_70 ( & V_97 -> V_5 ) ;
V_13 = V_95 ;
goto V_98;
}
V_26 = V_14 [ V_13 ] . V_26 ;
if ( F_45 ( V_13 ) && ! ( V_26 & V_41 ) )
V_22 = 0 ;
F_10 ( V_7 , V_13 , V_21 , V_22 ) ;
F_42 ( V_60 L_8 ,
V_7 , ( V_24 == V_55 ? L_9 : L_10 ) ,
( V_31 == V_99 ? L_11 : L_12 ) ,
F_71 ( V_21 ) , V_21 , F_11 ( V_13 ) ) ;
F_70 ( & V_97 -> V_5 ) ;
V_98:
F_4 ( & V_20 , V_4 ) ;
return V_13 ;
}
void
F_72 ( unsigned int V_7 )
{
unsigned long V_4 ;
int V_13 , V_69 ;
T_1 V_26 ;
unsigned long V_24 , V_31 ;
unsigned int V_21 ;
struct V_16 * V_17 ;
V_13 = F_8 ( V_7 ) ;
if ( V_13 < 0 ) {
F_42 ( V_100 L_13 ,
V_7 ) ;
F_73 ( 1 ) ;
return;
}
F_2 ( & V_20 , V_4 ) ;
if ( ( V_17 = F_9 ( V_13 , V_7 ) ) == NULL ) {
F_42 ( V_100 L_13 ,
V_7 ) ;
F_73 ( 1 ) ;
goto V_101;
}
if ( -- V_17 -> V_74 > 0 )
goto V_101;
V_17 -> V_74 = V_77 ;
V_26 = V_14 [ V_13 ] . V_26 | V_41 ;
F_1 ( V_17 -> V_1 , F_16 ( V_17 -> V_19 ) , V_26 ) ;
V_14 [ V_13 ] . V_42 -- ;
V_69 = F_5 ( V_7 ) ;
V_10 [ V_69 ] . V_76 -- ;
F_73 ( V_10 [ V_69 ] . V_76 < 0 ) ;
V_24 = V_14 [ V_13 ] . V_24 ;
V_31 = V_14 [ V_13 ] . V_31 ;
V_21 = V_14 [ V_13 ] . V_21 ;
F_42 ( V_60
L_14 ,
V_7 , ( V_24 == V_55 ? L_9 : L_10 ) ,
( V_31 == V_99 ? L_11 : L_12 ) ,
F_71 ( V_21 ) , V_21 , F_11 ( V_13 ) ) ;
if ( V_14 [ V_13 ] . V_42 == 0 ) {
#ifdef F_13
F_74 ( F_75 ( V_13 ) ) ;
#endif
V_14 [ V_13 ] . V_21 = 0 ;
V_14 [ V_13 ] . V_25 = 0 ;
V_14 [ V_13 ] . V_31 = 0 ;
V_14 [ V_13 ] . V_24 = 0 ;
V_14 [ V_13 ] . V_26 |= V_41 ;
F_76 ( V_13 ) ;
}
V_101:
F_4 ( & V_20 , V_4 ) ;
}
int T_4
F_77 ( T_1 V_102 , unsigned int V_7 ,
int V_103 , T_6 V_104 , T_6 V_105 ,
unsigned long V_31 , unsigned long V_24 )
{
static const char * const V_79 [] = { L_15 , L_16 , L_17 , L_18 } ;
unsigned char V_66 ;
int V_13 , V_29 , V_22 = 0 ;
unsigned int V_21 = ( ( V_105 << 8 ) | V_104 ) & 0xffff ;
switch ( V_102 ) {
case V_106 :
V_13 = V_29 = V_103 ;
F_78 ( V_13 , V_29 , V_107 ) ;
F_39 ( V_13 ) ;
V_66 = V_108 ;
break;
case V_109 :
V_13 = F_40 () ;
if ( V_13 < 0 )
F_41 ( L_2 , V_59 ) ;
V_29 = F_11 ( V_13 ) ;
V_66 = V_110 ;
break;
case V_111 :
V_13 = V_29 = V_112 ;
F_79 ( F_78 ( V_13 , V_29 , V_107 ) ) ;
V_66 = V_49 ;
V_22 = 1 ;
break;
default:
F_42 ( V_100 L_19 , V_59 ,
V_102 ) ;
return - 1 ;
}
F_47 ( V_7 , V_13 , V_66 , V_31 , V_24 ) ;
F_42 ( V_60
L_20
L_21 ,
V_102 < F_80 ( V_79 ) ? V_79 [ V_102 ] : L_15 ,
V_102 , V_7 , ( V_24 == V_55 ? L_9 : L_10 ) ,
( V_31 == V_99 ? L_11 : L_12 ) ,
F_71 ( V_21 ) , V_21 , V_29 ) ;
F_10 ( V_7 , V_13 , V_21 , V_22 ) ;
return V_29 ;
}
void F_81 ( unsigned int V_113 , unsigned int V_7 ,
unsigned long V_31 , unsigned long V_24 )
{
int V_29 , V_13 ;
unsigned int V_21 = F_25 ( F_56 () ) ;
unsigned char V_25 ;
V_13 = V_29 = F_82 ( V_113 ) ;
F_79 ( F_78 ( V_13 , V_29 , V_107 ) ) ;
V_25 = F_64 () ;
F_47 ( V_7 , V_13 , V_25 , V_31 , V_24 ) ;
F_12 ( L_22 ,
V_113 , V_7 , V_24 == V_55 ? L_9 : L_10 ,
V_31 == V_99 ? L_11 : L_12 ,
F_71 ( V_21 ) , V_21 , V_29 ) ;
F_10 ( V_7 , V_13 , V_21 , 1 ) ;
}
void T_4
F_83 ( void )
{
if ( V_114 ) {
F_42 ( V_60
L_23 ,
V_59 ) ;
F_84 ( 0xff , 0xA1 ) ;
F_84 ( 0xff , 0x21 ) ;
}
}
void T_4
F_85 ( int V_115 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_18 ; ++ V_13 ) {
V_14 [ V_13 ] . V_26 = V_41 ;
F_43 ( & V_14 [ V_13 ] . V_61 ) ;
V_14 [ V_13 ] . V_42 = 0 ;
}
V_114 = V_115 ;
if ( V_114 )
F_86 () ;
}
static inline int
F_87 ( void )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_9 ; V_69 ++ )
if ( ! V_10 [ V_69 ] . V_6 )
return V_69 ;
F_42 ( V_70 L_24 , V_59 ) ;
return - 1 ;
}
static inline void
F_88 ( int V_69 )
{
memset ( & V_10 [ V_69 ] , 0 , sizeof( V_10 [ 0 ] ) ) ;
}
static inline int
F_89 ( unsigned int V_11 , unsigned int V_116 )
{
int V_69 ;
unsigned int V_117 , V_118 , V_119 ;
V_117 = V_11 + ( ( V_116 >> 16 ) & 0xff ) ;
for ( V_69 = 0 ; V_69 < V_9 ; V_69 ++ ) {
if ( ! V_10 [ V_69 ] . V_6 )
continue;
V_118 = V_10 [ V_69 ] . V_11 ;
V_119 = V_118 + V_10 [ V_69 ] . V_12 - 1 ;
if ( V_117 < V_118 || V_119 < V_11 )
continue;
return - V_120 ;
}
return 0 ;
}
static int
F_90 ( unsigned int V_13 , unsigned int V_7 )
{
struct V_16 * V_17 , * V_121 ;
F_91 (rte, temp, &iosapic_intr_info[irq].rtes,
rte_list) {
if ( V_17 -> V_1 -> V_11 + V_17 -> V_19 == V_7 ) {
if ( V_17 -> V_74 )
return - V_120 ;
F_92 ( & V_17 -> V_75 ) ;
F_93 ( V_17 ) ;
return 0 ;
}
}
return - V_56 ;
}
int F_94 ( unsigned long V_122 , unsigned int V_11 )
{
int V_12 , V_95 , V_69 ;
unsigned int V_113 , V_116 ;
char T_3 * V_6 ;
unsigned long V_4 ;
F_2 ( & V_20 , V_4 ) ;
V_69 = F_5 ( V_11 ) ;
if ( V_69 >= 0 ) {
F_4 ( & V_20 , V_4 ) ;
return - V_120 ;
}
V_6 = F_95 ( V_122 , 0 ) ;
if ( V_6 == NULL ) {
F_4 ( & V_20 , V_4 ) ;
return - V_73 ;
}
V_116 = F_35 ( V_6 ) ;
if ( ( V_95 = F_89 ( V_11 , V_116 ) ) ) {
F_96 ( V_6 ) ;
F_4 ( & V_20 , V_4 ) ;
return V_95 ;
}
V_12 = ( ( V_116 >> 16 ) & 0xff ) + 1 ;
V_69 = F_87 () ;
V_10 [ V_69 ] . V_6 = V_6 ;
V_10 [ V_69 ] . V_11 = V_11 ;
V_10 [ V_69 ] . V_12 = V_12 ;
#ifdef F_60
V_10 [ V_69 ] . V_92 = V_93 ;
#endif
F_97 ( & V_10 [ V_69 ] . V_5 ) ;
F_4 ( & V_20 , V_4 ) ;
if ( ( V_11 == 0 ) && V_114 ) {
for ( V_113 = 0 ; V_113 < 16 ; ++ V_113 )
F_81 ( V_113 , V_113 ,
V_99 ,
V_55 ) ;
}
return 0 ;
}
int F_98 ( unsigned int V_11 )
{
int V_8 , V_13 , V_69 , V_95 = 0 ;
unsigned long V_4 ;
F_2 ( & V_20 , V_4 ) ;
V_69 = F_5 ( V_11 ) ;
if ( V_69 < 0 ) {
F_42 ( V_70 L_25 ,
V_59 , V_11 ) ;
goto V_101;
}
if ( V_10 [ V_69 ] . V_76 ) {
V_95 = - V_120 ;
F_42 ( V_70 L_26 ,
V_59 , V_11 ) ;
goto V_101;
}
for ( V_8 = V_11 ; V_8 < V_11 + V_10 [ V_69 ] . V_12 ; V_8 ++ ) {
V_13 = F_6 ( V_8 ) ;
if ( V_13 < 0 )
continue;
V_95 = F_90 ( V_13 , V_8 ) ;
if ( V_95 )
goto V_101;
}
F_96 ( V_10 [ V_69 ] . V_6 ) ;
F_88 ( V_69 ) ;
V_101:
F_4 ( & V_20 , V_4 ) ;
return V_95 ;
}
void F_99 ( unsigned int V_11 , int V_92 )
{
int V_69 ;
V_69 = F_5 ( V_11 ) ;
if ( V_69 < 0 ) {
F_42 ( V_70 L_4 ,
V_59 , V_11 ) ;
return;
}
V_10 [ V_69 ] . V_92 = V_92 ;
return;
}
