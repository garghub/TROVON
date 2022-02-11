void T_1 * F_1 ( T_2 V_1 , void * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
unsigned long V_5 ;
if ( ( V_4 & V_6 ) == 0 )
V_4 |= F_2 ( V_7 ) ;
if ( V_4 & V_8 )
return NULL ;
F_3 ( V_1 & ~ V_9 ) ;
F_3 ( ( ( unsigned long ) V_2 ) & ~ V_9 ) ;
F_3 ( V_3 & ~ V_9 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 += V_10 )
if ( F_4 ( ( unsigned long ) V_2 + V_5 , V_1 + V_5 , V_4 ) )
return NULL ;
return ( void T_1 * ) V_2 ;
}
void F_5 ( void * V_2 , unsigned long V_3 )
{
F_3 ( ( ( unsigned long ) V_2 ) & ~ V_9 ) ;
F_3 ( V_3 & ~ V_9 ) ;
F_6 ( ( unsigned long ) V_2 , V_3 ) ;
}
void T_1 * F_7 ( T_2 V_11 , unsigned long V_3 ,
unsigned long V_4 , void * V_12 )
{
T_2 V_13 ;
void T_1 * V_14 ;
V_13 = V_11 & V_9 ;
V_3 = F_8 ( V_11 + V_3 ) - V_13 ;
if ( ( V_3 == 0 ) || ( V_13 == 0 ) )
return NULL ;
if ( F_9 () ) {
struct V_15 * V_16 ;
V_16 = F_10 ( V_3 , V_17 ,
V_18 , V_19 ,
V_12 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_20 = V_13 ;
V_14 = F_1 ( V_13 , V_16 -> V_11 , V_3 , V_4 ) ;
if ( ! V_14 )
F_11 ( V_16 -> V_11 ) ;
} else {
V_14 = F_1 ( V_13 , ( void * ) V_18 , V_3 , V_4 ) ;
if ( V_14 )
V_18 += V_3 ;
}
if ( V_14 )
V_14 += V_11 & ~ V_9 ;
return V_14 ;
}
void T_1 * F_12 ( T_2 V_11 , unsigned long V_3 ,
unsigned long V_4 )
{
return F_7 ( V_11 , V_3 , V_4 , F_13 ( 0 ) ) ;
}
void T_1 * F_14 ( T_2 V_11 , unsigned long V_3 )
{
unsigned long V_4 = F_2 ( F_15 ( F_16 ( 0 ) ) ) ;
void * V_12 = F_13 ( 0 ) ;
if ( V_21 . F_14 )
return V_21 . F_14 ( V_11 , V_3 , V_4 , V_12 ) ;
return F_7 ( V_11 , V_3 , V_4 , V_12 ) ;
}
void T_1 * F_17 ( T_2 V_11 , unsigned long V_3 )
{
unsigned long V_4 = F_2 ( F_18 ( F_16 ( 0 ) ) ) ;
void * V_12 = F_13 ( 0 ) ;
if ( V_21 . F_14 )
return V_21 . F_14 ( V_11 , V_3 , V_4 , V_12 ) ;
return F_7 ( V_11 , V_3 , V_4 , V_12 ) ;
}
void T_1 * F_19 ( T_2 V_11 , unsigned long V_3 ,
unsigned long V_4 )
{
void * V_12 = F_13 ( 0 ) ;
if ( V_4 & V_22 )
V_4 |= V_23 ;
V_4 &= ~ V_24 ;
#if F_20 ( V_25 )
V_4 |= V_26 ;
#else
V_4 &= ~ V_27 ;
#endif
#ifdef F_21
V_4 |= F_21 ;
#endif
if ( V_21 . F_14 )
return V_21 . F_14 ( V_11 , V_3 , V_4 , V_12 ) ;
return F_7 ( V_11 , V_3 , V_4 , V_12 ) ;
}
void F_22 ( volatile void T_1 * V_28 )
{
void * V_11 ;
if ( ! F_9 () )
return;
V_11 = ( void * ) ( ( unsigned long V_29 )
F_23 ( V_28 ) & V_9 ) ;
if ( ( unsigned long ) V_11 < V_18 ) {
F_24 ( V_30 L_1
L_2 , V_11 ) ;
return;
}
F_11 ( V_11 ) ;
}
void F_25 ( volatile void T_1 * V_28 )
{
if ( V_21 . F_25 )
V_21 . F_25 ( V_28 ) ;
else
F_22 ( V_28 ) ;
}
struct V_31 * F_26 ( T_3 V_32 )
{
if ( F_27 ( V_32 ) )
return F_28 ( F_29 ( V_32 ) ) ;
return F_30 ( F_31 ( V_32 ) ) ;
}
struct V_31 * F_32 ( T_4 V_33 )
{
if ( F_33 ( V_33 ) )
return F_28 ( F_34 ( V_33 ) ) ;
return F_30 ( F_35 ( V_33 ) ) ;
}
struct V_31 * F_36 ( T_5 V_34 )
{
if ( F_37 ( V_34 ) || F_38 ( V_34 ) || F_39 ( V_34 ) )
return F_28 ( F_40 ( V_34 ) ) ;
return F_30 ( F_41 ( V_34 ) ) ;
}
static T_6 * F_42 ( struct V_35 * V_36 )
{
void * V_37 , * V_14 ;
F_43 ( & V_36 -> V_38 ) ;
V_14 = V_36 -> V_39 . V_37 ;
if ( V_14 ) {
V_37 = V_14 + V_40 ;
if ( ( ( unsigned long ) V_37 & ~ V_9 ) == 0 )
V_37 = NULL ;
V_36 -> V_39 . V_37 = V_37 ;
}
F_44 ( & V_36 -> V_38 ) ;
return ( T_6 * ) V_14 ;
}
static T_6 * F_45 ( struct V_35 * V_36 , int V_41 )
{
void * V_14 = NULL ;
struct V_31 * V_31 ;
if ( ! V_41 ) {
V_31 = F_46 ( V_42 | V_43 ) ;
if ( ! V_31 )
return NULL ;
if ( ! F_47 ( V_31 ) ) {
F_48 ( V_31 ) ;
return NULL ;
}
} else {
V_31 = F_46 ( V_42 ) ;
if ( ! V_31 )
return NULL ;
}
V_14 = F_49 ( V_31 ) ;
F_43 ( & V_36 -> V_38 ) ;
if ( F_50 ( ! V_36 -> V_39 . V_37 ) ) {
F_51 ( V_31 , V_44 ) ;
V_36 -> V_39 . V_37 = V_14 + V_40 ;
}
F_44 ( & V_36 -> V_38 ) ;
return ( T_6 * ) V_14 ;
}
T_6 * F_52 ( struct V_35 * V_36 , unsigned long V_45 , int V_41 )
{
T_6 * V_46 ;
V_46 = F_42 ( V_36 ) ;
if ( V_46 )
return V_46 ;
return F_45 ( V_36 , V_41 ) ;
}
void F_53 ( unsigned long * V_47 , int V_41 )
{
struct V_31 * V_31 = F_30 ( V_47 ) ;
if ( F_54 ( V_31 ) ) {
if ( ! V_41 )
F_55 ( V_31 ) ;
F_56 ( V_31 , 0 ) ;
}
}
void F_57 ( struct V_48 * V_49 , void * V_47 , int V_50 )
{
unsigned long V_51 = ( unsigned long ) V_47 ;
F_58 ( V_50 > V_52 ) ;
V_51 |= V_50 ;
F_59 ( V_49 , ( void * ) V_51 ) ;
}
void F_60 ( void * V_53 )
{
void * V_47 = ( void * ) ( ( unsigned long ) V_53 & ~ V_52 ) ;
unsigned V_50 = ( unsigned long ) V_53 & V_52 ;
if ( ! V_50 )
F_53 ( V_47 , 0 ) ;
else {
F_58 ( V_50 > V_52 ) ;
F_61 ( F_62 ( V_50 ) , V_47 ) ;
}
}
void F_57 ( struct V_48 * V_49 , void * V_47 , int V_50 )
{
if ( ! V_50 ) {
F_53 ( V_47 , 0 ) ;
} else {
F_58 ( V_50 > V_52 ) ;
F_61 ( F_62 ( V_50 ) , V_47 ) ;
}
}
void T_7 F_63 ( void )
{
unsigned long V_54 = 1UL << V_55 ;
unsigned long V_56 ;
F_64 ( ( V_55 > 36 ) , L_3 ) ;
V_57 = F_65 ( F_66 ( V_54 , V_54 ,
V_58 ) ) ;
memset ( ( void * ) V_57 , 0 , V_54 ) ;
V_56 = F_67 ( V_57 ) | ( V_55 - 12 ) ;
F_68 ( V_59 , V_56 ) ;
F_69 ( V_56 ) ;
}
void F_70 ( unsigned int V_60 , unsigned long V_61 ,
unsigned long V_62 )
{
unsigned long V_63 = F_71 ( V_57 [ V_60 ] . V_64 ) ;
V_57 [ V_60 ] . V_64 = F_72 ( V_61 ) ;
V_57 [ V_60 ] . V_65 = F_72 ( V_62 ) ;
asm volatile("ptesync" : : : "memory");
if ( V_63 & V_66 ) {
asm volatile(PPC_TLBIE_5(%0,%1,2,0,1) : :
"r" (TLBIEL_INVAL_SET_LPID), "r" (lpid));
F_73 ( V_60 , 0 , V_67 , V_60 , 2 , 0 , 1 ) ;
} else {
asm volatile(PPC_TLBIE_5(%0,%1,2,0,0) : :
"r" (TLBIEL_INVAL_SET_LPID), "r" (lpid));
F_73 ( V_60 , 0 , V_67 , V_60 , 2 , 0 , 0 ) ;
}
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
}
void F_74 ( void )
{
if ( ! F_75 ( V_68 ) ) {
F_76 ( L_4 ) ;
return;
}
if ( F_77 () )
F_78 () ;
else
F_79 () ;
}
void F_80 ( void )
{
if ( F_77 () )
F_81 () ;
else
F_82 () ;
}
