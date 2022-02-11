static inline void
F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
F_2 () ;
F_3 ( V_4 , V_1 , V_2 , V_3 ) ;
}
static inline void F_4 ( void )
{
F_5 ( V_4 ) ;
F_6 () ;
}
static inline void F_7 ( void )
{
unsigned long long V_5 , V_6 , V_7 ;
unsigned long V_8 ;
V_5 = V_9 ;
V_6 = V_10 ;
V_7 = 0 ;
F_8 ( V_8 ) ;
__asm__ __volatile__ (
"getcfg %3, 0, %0\n\t"
"or %0, %2, %0\n\t"
"putcfg %3, 0, %0\n\t"
"synci"
: "=&r" (data)
: "0" (data), "r" (flag), "r" (addr));
F_9 ( V_8 ) ;
}
static void F_10 ( unsigned long V_11 , unsigned long V_12 )
{
unsigned long long V_13 , V_5 , V_14 ;
V_14 = ( unsigned long long ) ( signed long long ) ( signed long ) V_11 ;
V_5 = F_11 ( V_14 ) ;
V_13 = ( unsigned long long ) ( signed long long ) ( signed long ) V_12 ;
while ( V_5 <= V_13 ) {
__asm__ __volatile__ ("icbi %0, 0" : : "r" (addr));
V_5 += V_15 ;
}
}
static void F_12 ( struct V_16 * V_17 , unsigned long V_1 )
{
unsigned int V_18 = F_13 () ;
unsigned long long V_5 , V_19 ;
unsigned long V_8 = 0 ;
unsigned long V_20 , V_21 ;
V_5 = V_1 ;
V_19 = V_5 + V_22 ;
V_20 = F_14 () ;
V_21 = F_15 ( V_18 , V_17 -> V_23 ) ;
if ( V_20 != V_21 ) {
F_8 ( V_8 ) ;
F_16 ( V_21 ) ;
}
while ( V_5 < V_19 ) {
__asm__ __volatile__("icbi %0, 0" : : "r" (addr));
__asm__ __volatile__("icbi %0, 32" : : "r" (addr));
__asm__ __volatile__("icbi %0, 64" : : "r" (addr));
__asm__ __volatile__("icbi %0, 96" : : "r" (addr));
V_5 += 128 ;
}
if ( V_20 != V_21 ) {
F_16 ( V_20 ) ;
F_9 ( V_8 ) ;
}
}
static void F_17 ( struct V_24 * V_25 ,
unsigned long V_11 , unsigned long V_12 )
{
int V_26 ;
if ( ! V_25 )
return;
V_26 = ( ( V_12 - V_11 ) >> V_27 ) ;
if ( V_26 >= 64 ) {
F_7 () ;
} else {
unsigned long V_14 ;
unsigned long V_1 ;
unsigned long V_28 ;
unsigned long V_29 , V_30 ;
unsigned long V_8 = 0 ;
V_29 = F_15 ( F_13 () , V_25 ) ;
V_30 = F_14 () ;
if ( V_29 != V_30 ) {
F_8 ( V_8 ) ;
F_16 ( V_29 ) ;
}
V_14 = V_11 & V_31 ;
V_28 = V_22 + ( ( V_12 - 1 ) & V_31 ) ;
while ( V_14 < V_28 ) {
struct V_16 * V_17 ;
unsigned long V_32 ;
V_17 = F_18 ( V_25 , V_14 ) ;
if ( ! V_17 || ( V_14 <= V_17 -> V_33 ) ) {
V_14 += V_22 ;
continue;
}
V_32 = V_17 -> V_33 ;
if ( V_17 -> V_34 & V_35 ) {
V_1 = V_14 ;
while ( V_1 < V_32 ) {
F_12 ( V_17 , V_1 ) ;
V_1 += V_22 ;
}
}
V_14 = V_17 -> V_33 ;
}
if ( V_29 != V_30 ) {
F_16 ( V_30 ) ;
F_9 ( V_8 ) ;
}
}
}
static void F_19 ( unsigned long V_11 , unsigned long V_12 )
{
unsigned long long V_14 ;
unsigned long long V_36 ;
unsigned long long V_5 ;
V_36 = V_12 ;
V_14 = F_11 ( V_11 ) ;
V_5 = V_14 ;
while ( V_5 < V_36 ) {
__asm__ __volatile__ ("icbi %0, 0" : : "r" (addr));
__asm__ __volatile__ ("nop");
__asm__ __volatile__ ("nop");
V_5 += V_15 ;
}
}
static inline void F_20 ( int V_37 , int V_38 )
{
int V_39 ;
unsigned long long V_1 , V_40 , V_41 ;
int V_42 ;
int V_43 ;
V_39 = ( ( int ) & V_44 &
V_45 -> V_46 . V_47 ) >>
V_45 -> V_46 . V_48 ;
V_43 = V_37 - V_39 ;
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ , V_43 ++ ) {
V_43 &= ( V_45 -> V_46 . V_49 - 1 ) ;
V_40 = ( unsigned long long ) V_44 +
( V_43 << V_45 -> V_46 . V_48 ) ;
V_41 = V_40 + V_45 -> V_46 . V_50 *
V_45 -> V_46 . V_51 ;
for ( V_1 = V_40 ; V_1 < V_41 ;
V_1 += V_45 -> V_46 . V_50 ) {
__asm__ __volatile__ ("alloco %0, 0" : : "r" (eaddr));
__asm__ __volatile__ ("synco");
}
V_41 = V_40 + V_45 -> V_46 . V_50 *
V_45 -> V_46 . V_51 ;
for ( V_1 = V_40 ; V_1 < V_41 ;
V_1 += V_45 -> V_46 . V_50 ) {
if ( F_21 ( V_52 , & ( V_45 -> V_46 . V_8 ) ) )
F_22 ( ( unsigned long ) V_1 ) ;
}
}
}
static void F_23 ( void )
{
F_20 ( 0 , V_45 -> V_46 . V_49 ) ;
}
static void F_24 ( unsigned long V_3 ,
unsigned long V_1 )
{
unsigned long long V_53 ;
unsigned long long V_54 , V_55 ;
V_53 = V_56 + ( V_1 & V_57 ) ;
F_1 ( V_53 , F_14 () , V_3 ) ;
V_54 = V_53 ;
V_55 = V_54 + V_22 ;
while ( V_54 < V_55 ) {
__asm__ __volatile__ ("ocbp %0, 0" : : "r" (magic_eaddr));
V_54 += V_15 ;
}
F_4 () ;
}
static void F_25 ( unsigned long V_3 )
{
unsigned long long V_58 , V_1 , V_59 ;
int V_60 ;
V_58 = V_56 ;
for ( V_60 = 0 ; V_60 < ( 1 << V_61 ) ; V_60 ++ ) {
F_1 ( V_58 , F_14 () , V_3 ) ;
V_1 = V_58 ;
V_59 = V_1 + V_22 ;
while ( V_1 < V_59 ) {
__asm__ __volatile__ ("ocbp %0, 0" : : "r" (eaddr));
V_1 += V_15 ;
}
F_4 () ;
V_58 += V_22 ;
}
}
static void F_26 ( struct V_24 * V_25 ,
unsigned long V_5 , unsigned long V_12 )
{
T_1 * V_62 ;
T_2 * V_63 ;
T_3 * V_64 ;
T_4 * V_65 ;
T_4 V_66 ;
T_5 * V_67 ;
unsigned long V_3 ;
if ( ! V_25 )
return;
V_62 = F_27 ( V_25 , V_5 ) ;
if ( F_28 ( * V_62 ) )
return;
V_63 = F_29 ( V_62 , V_5 ) ;
if ( F_30 ( * V_63 ) || F_31 ( * V_63 ) )
return;
V_64 = F_32 ( V_63 , V_5 ) ;
if ( F_33 ( * V_64 ) || F_34 ( * V_64 ) )
return;
V_65 = F_35 ( V_25 , V_64 , V_5 , & V_67 ) ;
do {
V_66 = * V_65 ;
if ( F_36 ( V_66 ) || ! F_37 ( V_66 ) )
continue;
V_3 = F_38 ( V_66 ) & V_31 ;
F_24 ( V_3 , V_5 ) ;
} while ( V_65 ++ , V_5 += V_22 , V_5 != V_12 );
F_39 ( V_65 - 1 , V_67 ) ;
}
static void F_40 ( struct V_24 * V_25 ,
unsigned long V_11 , unsigned long V_12 )
{
int V_26 = ( ( V_12 - V_11 ) >> V_27 ) ;
if ( V_26 >= 64 || ( ( V_11 ^ ( V_12 - 1 ) ) & V_68 ) ) {
F_23 () ;
} else {
V_11 &= V_31 ;
V_12 = F_41 ( V_12 ) ;
F_26 ( V_25 , V_11 , V_12 ) ;
}
}
static void F_42 ( void * V_69 )
{
F_23 () ;
F_7 () ;
}
static void F_43 ( void * V_69 )
{
F_23 () ;
}
static void F_44 ( void * args )
{
struct V_70 * V_7 = args ;
struct V_16 * V_17 ;
unsigned long V_11 , V_12 ;
V_17 = V_7 -> V_17 ;
V_11 = V_7 -> V_71 ;
V_12 = V_7 -> V_72 ;
F_40 ( V_17 -> V_23 , V_11 , V_12 ) ;
F_17 ( V_17 -> V_23 , V_11 , V_12 ) ;
}
static void F_45 ( void * args )
{
struct V_70 * V_7 = args ;
struct V_16 * V_17 ;
unsigned long V_1 , V_73 ;
V_17 = V_7 -> V_17 ;
V_1 = V_7 -> V_71 ;
V_73 = V_7 -> V_72 ;
F_25 ( V_73 << V_27 ) ;
if ( V_17 -> V_34 & V_35 )
F_12 ( V_17 , V_1 ) ;
}
static void F_46 ( void * V_74 )
{
F_25 ( F_47 ( (struct V_74 * ) V_74 ) ) ;
F_48 () ;
}
static void F_49 ( void * args )
{
struct V_70 * V_7 = args ;
unsigned long V_11 , V_12 ;
V_11 = V_7 -> V_71 ;
V_12 = V_7 -> V_72 ;
F_50 ( ( void * ) V_11 , V_12 ) ;
F_48 () ;
F_10 ( V_11 , V_12 ) ;
}
static void F_51 ( void * V_75 )
{
unsigned long V_12 = ( unsigned long ) V_75 + V_15 ;
F_52 ( V_75 , V_15 ) ;
F_48 () ;
F_19 ( ( unsigned long ) V_75 , V_12 ) ;
}
void T_6 F_53 ( void )
{
V_76 = F_42 ;
V_77 = F_43 ;
V_78 = F_43 ;
V_79 = F_45 ;
V_80 = F_44 ;
V_81 = F_46 ;
V_82 = F_49 ;
V_83 = F_51 ;
V_4 = F_54 () ;
F_55 () ;
}
