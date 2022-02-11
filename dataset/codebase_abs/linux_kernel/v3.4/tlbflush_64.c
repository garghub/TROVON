static inline void F_1 ( T_1 V_1 )
{
F_2 ( L_1 , F_3 ( V_1 ) ) ;
F_2 ( L_2 , F_4 ( V_2 ) , F_4 ( V_3 ) ,
F_4 ( V_4 ) , F_4 ( V_5 ) , F_4 ( V_6 ) ) ;
}
static inline void F_5 ( struct V_7 * V_8 )
{
F_2 ( L_3 , V_8 -> V_9 ) ;
F_2 ( L_4 , V_8 -> V_10 ) ;
F_1 ( V_8 -> V_11 ) ;
F_2 ( L_5 , V_8 -> V_12 ) ;
}
static inline void F_6 ( struct V_13 * V_14 )
{
F_2 ( L_6 , F_7 ( V_14 ) ) ;
}
static T_2 * F_8 ( struct V_15 * V_16 , unsigned long V_17 )
{
T_3 * V_18 ;
T_4 * V_19 ;
T_5 * V_20 ;
T_2 * V_21 ;
T_2 V_22 ;
V_18 = F_9 ( V_16 , V_17 ) ;
if ( F_10 ( * V_18 ) )
return NULL ;
V_19 = F_11 ( V_18 , V_17 ) ;
if ( F_12 ( * V_19 ) )
return NULL ;
V_20 = F_13 ( V_19 , V_17 ) ;
if ( F_14 ( * V_20 ) )
return NULL ;
V_21 = F_15 ( V_20 , V_17 ) ;
V_22 = * V_21 ;
if ( F_16 ( V_22 ) || ! F_17 ( V_22 ) )
return NULL ;
return V_21 ;
}
T_6 void F_18 ( struct V_23 * V_24 , unsigned long V_25 ,
unsigned long V_26 , unsigned long V_17 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_7 * V_8 ;
const struct V_27 * V_28 ;
T_2 * V_21 ;
int V_29 ;
V_14 = V_30 ;
V_16 = V_14 -> V_16 ;
F_19 () ;
F_20 ( V_31 , 1 , V_24 , V_17 ) ;
if ( F_21 () || ! V_16 )
goto V_32;
F_22 ( & V_16 -> V_33 ) ;
V_8 = F_23 ( V_16 , V_17 ) ;
if ( ! V_8 ) {
#ifdef F_24
F_6 ( V_14 ) ;
F_2 ( L_7 ,
V_34 , __LINE__ ,
V_17 , V_24 -> V_35 , V_26 , V_25 ) ;
F_25 ( V_24 ) ;
#endif
goto V_36;
}
if ( V_8 -> V_9 <= V_17 ) {
goto V_37;
}
if ( ! ( V_8 -> V_12 & V_38 ) ) {
#ifdef F_24
F_6 ( V_14 ) ;
F_2 ( L_7 ,
V_34 , __LINE__ ,
V_17 , V_24 -> V_35 , V_26 , V_25 ) ;
F_25 ( V_24 ) ;
F_5 ( V_8 ) ;
#endif
goto V_36;
}
if ( F_26 ( V_8 , V_17 ) ) {
#ifdef F_24
F_6 ( V_14 ) ;
F_2 ( L_7 ,
V_34 , __LINE__ ,
V_17 , V_24 -> V_35 , V_26 , V_25 ) ;
F_25 ( V_24 ) ;
#endif
goto V_36;
}
V_37:
if ( V_26 ) {
if ( ! ( V_8 -> V_12 & V_39 ) )
goto V_36;
} else {
if ( V_25 ) {
if ( ! ( V_8 -> V_12 & V_40 ) )
goto V_36;
} else {
if ( ! ( V_8 -> V_12 & V_41 ) )
goto V_36;
}
}
V_29 = F_27 ( V_16 , V_8 , V_17 , V_25 ? V_42 : 0 ) ;
if ( F_28 ( V_29 & V_43 ) ) {
if ( V_29 & V_44 )
goto V_45;
else if ( V_29 & V_46 )
goto V_47;
F_29 () ;
}
if ( V_29 & V_48 ) {
V_14 -> V_49 ++ ;
F_20 ( V_50 , 1 ,
V_24 , V_17 ) ;
} else {
V_14 -> V_51 ++ ;
F_20 ( V_52 , 1 ,
V_24 , V_17 ) ;
}
V_21 = F_8 ( V_16 , V_17 ) ;
if ( ! V_21 ) {
goto V_53;
}
F_30 ( V_17 , V_26 , V_21 ) ;
V_53:
F_31 ( & V_16 -> V_33 ) ;
return;
V_36:
#ifdef F_24
F_2 ( L_8 ) ;
#endif
F_31 ( & V_16 -> V_33 ) ;
if ( F_32 ( V_24 ) ) {
static int V_54 = 0 ;
T_7 V_55 ;
if ( V_54 < 4 ) {
V_54 ++ ;
F_2 ( L_9 ,
V_17 , F_7 ( V_30 ) , V_30 -> V_56 ,
( unsigned long ) V_24 -> V_35 ) ;
#if 0
show_regs(regs);
#endif
}
if ( F_33 ( V_14 ) ) {
F_34 ( L_10 ) ;
}
V_14 -> V_57 . V_17 = V_17 ;
V_14 -> V_57 . V_58 = V_25 ;
V_55 . V_59 = V_60 ;
V_55 . V_61 = 0 ;
V_55 . V_62 = ( void * ) V_17 ;
F_35 ( V_60 , & V_55 , V_14 ) ;
return;
}
V_32:
#ifdef F_24
F_2 ( L_11 ) ;
#endif
V_28 = F_36 ( V_24 -> V_35 ) ;
if ( V_28 ) {
V_24 -> V_35 = V_28 -> V_28 ;
return;
}
if ( V_17 < V_63 )
F_2 ( V_64 L_12 ) ;
else
F_2 ( V_64 L_13 ) ;
F_2 ( L_14 , V_17 ) ;
F_2 ( V_64 L_15 , V_24 -> V_35 >> 32 , V_24 -> V_35 & 0xffffffff ) ;
F_37 ( L_16 , V_24 , V_25 ) ;
F_38 ( V_65 ) ;
V_45:
F_31 ( & V_16 -> V_33 ) ;
if ( ! F_32 ( V_24 ) )
goto V_32;
F_39 () ;
return;
V_47:
F_2 ( L_17 ) ;
F_31 ( & V_16 -> V_33 ) ;
V_14 -> V_57 . V_17 = V_17 ;
V_14 -> V_57 . V_58 = V_25 ;
V_14 -> V_57 . V_66 = 14 ;
F_40 ( V_67 , V_14 ) ;
if ( ! F_32 ( V_24 ) )
goto V_32;
}
void F_41 ( unsigned long V_68 , unsigned long V_69 )
{
unsigned long long V_70 , V_71 = 0 , V_72 ;
unsigned long V_73 ;
V_72 = F_42 ( V_69 ) ;
V_70 = ( V_68 << V_74 ) | V_75 ;
V_70 |= V_72 ;
F_43 (tlb) {
asm volatile ("getcfg %1, 0, %0"
: "=r" (pteh)
: "r" (tlb) );
if ( V_71 == V_70 ) {
F_44 ( V_73 ) ;
break;
}
}
F_45 (tlb) {
asm volatile ("getcfg %1, 0, %0"
: "=r" (pteh)
: "r" (tlb) );
if ( V_71 == V_70 ) {
F_44 ( V_73 ) ;
break;
}
}
}
void F_46 ( struct V_7 * V_8 , unsigned long V_69 )
{
unsigned long V_76 ;
if ( V_8 -> V_77 ) {
V_69 &= V_78 ;
F_47 ( V_76 ) ;
F_41 ( F_48 () , V_69 ) ;
F_49 ( V_76 ) ;
}
}
void F_50 ( struct V_7 * V_8 , unsigned long V_79 ,
unsigned long V_80 )
{
unsigned long V_76 ;
unsigned long long V_70 , V_71 = 0 , V_81 , V_82 ;
unsigned long V_73 ;
unsigned int V_83 = F_51 () ;
struct V_15 * V_16 ;
V_16 = V_8 -> V_77 ;
if ( F_52 ( V_83 , V_16 ) == V_84 )
return;
F_47 ( V_76 ) ;
V_79 &= V_78 ;
V_80 &= V_78 ;
V_70 = ( F_53 ( V_83 , V_16 ) << V_74 ) | V_75 ;
F_43 (tlb) {
asm volatile ("getcfg %1, 0, %0"
: "=r" (pteh)
: "r" (tlb) );
V_81 = V_71 & V_78 ;
V_82 = V_71 & ~ V_78 ;
if ( V_82 == V_70 && V_81 >= V_79 && V_81 <= V_80 )
F_44 ( V_73 ) ;
}
F_45 (tlb) {
asm volatile ("getcfg %1, 0, %0"
: "=r" (pteh)
: "r" (tlb) );
V_81 = V_71 & V_78 ;
V_82 = V_71 & ~ V_78 ;
if ( V_82 == V_70 && V_81 >= V_79 && V_81 <= V_80 )
F_44 ( V_73 ) ;
}
F_49 ( V_76 ) ;
}
void F_54 ( struct V_15 * V_16 )
{
unsigned long V_76 ;
unsigned int V_83 = F_51 () ;
if ( F_52 ( V_83 , V_16 ) == V_84 )
return;
F_47 ( V_76 ) ;
F_52 ( V_83 , V_16 ) = V_84 ;
if ( V_16 == V_30 -> V_16 )
F_55 ( V_16 , V_83 ) ;
F_49 ( V_76 ) ;
}
void F_56 ( void )
{
unsigned long V_76 , V_73 ;
F_47 ( V_76 ) ;
F_43 (tlb)
F_44 ( V_73 ) ;
F_45 (tlb)
F_44 ( V_73 ) ;
F_49 ( V_76 ) ;
}
void F_57 ( unsigned long V_79 , unsigned long V_80 )
{
F_58 () ;
}
void F_59 ( void )
{
F_58 () ;
}
void F_60 ( struct V_7 * V_8 , unsigned long V_17 , T_2 V_21 )
{
}
