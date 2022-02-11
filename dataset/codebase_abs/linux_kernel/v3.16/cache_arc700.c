char * F_1 ( int V_1 , char * V_2 , int V_3 )
{
int V_4 = 0 ;
#define F_2 ( T_1 , T_2 , T_3 ) \
{ \
if (!(p)->ver) \
n += scnprintf(buf + n, len - n, str"\t\t: N/A\n"); \
else \
n += scnprintf(buf + n, len - n, \
str"\t\t: (%uK) VIPT, %dway set-asc, %ub Line %s\n", \
TO_KB((p)->sz), (p)->assoc, (p)->line_len, \
enb ? "" : "DISABLED (kernel-build)"); \
}
F_2 ( & V_5 [ V_1 ] . V_6 , F_3 ( V_7 ) ,
L_1 ) ;
F_2 ( & V_5 [ V_1 ] . V_8 , F_3 ( V_9 ) ,
L_2 ) ;
return V_2 ;
}
void F_4 ( void )
{
struct V_10 * V_11 , * V_12 ;
unsigned int V_13 = F_5 () ;
struct V_14 {
#ifdef F_6
unsigned int V_15 : 12 , V_16 : 4 , V_17 : 4 , V_18 : 4 , V_19 : 8 ;
#else
unsigned int V_19 : 8 , V_18 : 4 , V_17 : 4 , V_16 : 4 , V_15 : 12 ;
#endif
} V_20 , V_21 ;
V_11 = & V_5 [ V_13 ] . V_6 ;
F_7 ( V_22 , V_20 ) ;
F_8 ( V_20 . V_18 != 3 ) ;
V_11 -> V_23 = 2 ;
V_11 -> V_16 = 8 << V_20 . V_16 ;
V_11 -> V_17 = 0x200 << V_20 . V_17 ;
V_11 -> V_19 = V_20 . V_19 ;
V_12 = & V_5 [ V_13 ] . V_8 ;
F_7 ( V_24 , V_21 ) ;
F_8 ( V_21 . V_18 != 2 ) ;
V_12 -> V_23 = 4 ;
V_12 -> V_16 = 16 << V_21 . V_16 ;
V_12 -> V_17 = 0x200 << V_21 . V_17 ;
V_12 -> V_19 = V_21 . V_19 ;
}
void F_9 ( void )
{
unsigned int T_4 V_13 = F_5 () ;
struct V_10 T_4 * V_25 , T_4 * V_26 ;
char T_3 [ 256 ] ;
F_10 ( F_1 ( 0 , T_3 , sizeof( T_3 ) ) ) ;
#ifdef V_7
V_25 = & V_5 [ V_13 ] . V_6 ;
if ( V_25 -> V_19 ) {
if ( V_25 -> V_16 != V_27 )
F_11 ( L_3 ,
V_25 -> V_16 , V_27 ) ;
if ( V_25 -> V_19 != V_28 )
F_11 ( L_4 ,
V_25 -> V_19 , V_28 ) ;
}
#endif
#ifdef V_9
V_26 = & V_5 [ V_13 ] . V_8 ;
if ( V_26 -> V_19 ) {
unsigned int V_29 ;
if ( V_26 -> V_16 != V_27 )
F_11 ( L_5 ,
V_26 -> V_16 , V_27 ) ;
V_29 = ( V_26 -> V_17 / V_26 -> V_23 ) > V_30 ;
if ( V_29 && ! F_12 () )
F_11 ( L_6 ) ;
else if ( ! V_29 && F_12 () )
F_11 ( L_7 ) ;
}
#endif
}
static inline void F_13 ( unsigned long V_31 , unsigned long V_32 ,
unsigned long V_17 , const int V_33 )
{
unsigned int V_34 , V_35 ;
int V_36 ;
const int V_37 = F_14 ( V_17 ) && V_17 == V_30 ;
if ( V_33 == V_38 ) {
V_34 = V_39 ;
#if ( V_28 > 2 )
V_35 = V_40 ;
#endif
}
else {
V_34 = V_33 & V_41 ? V_42 : V_43 ;
#if ( V_28 > 2 )
V_35 = V_44 ;
#endif
}
if ( ! V_37 ) {
V_17 += V_31 & ~ V_45 ;
V_31 &= V_45 ;
V_32 &= V_45 ;
}
V_36 = F_15 ( V_17 , V_27 ) ;
#if ( V_28 <= 2 )
V_31 |= ( V_32 >> V_46 ) & 0x1F ;
#else
if ( V_37 )
F_16 ( V_35 , V_31 ) ;
#endif
while ( V_36 -- > 0 ) {
#if ( V_28 > 2 )
if ( ! V_37 ) {
F_16 ( V_35 , V_31 ) ;
V_31 += V_27 ;
}
F_16 ( V_34 , V_32 ) ;
V_32 += V_27 ;
#else
F_16 ( V_34 , V_31 ) ;
V_31 += V_27 ;
#endif
}
}
static inline void F_17 ( void )
{
while ( F_18 ( V_47 ) & V_48 )
;
}
static inline void F_19 ( const int V_33 )
{
unsigned int V_49 = V_49 ;
int V_50 ;
if ( V_33 == V_51 ) {
V_49 = F_18 ( V_47 ) ;
F_16 ( V_47 , V_49 | V_52 ) ;
}
if ( V_33 & V_41 )
V_50 = V_53 ;
else
V_50 = V_54 ;
F_16 ( V_50 , 0x1 ) ;
if ( V_33 & V_55 )
F_17 () ;
if ( V_33 == V_51 )
F_16 ( V_47 , V_49 & ~ V_52 ) ;
}
static inline void F_20 ( unsigned long V_31 , unsigned long V_32 ,
unsigned long V_17 , const int V_33 )
{
unsigned long V_56 , V_49 = V_49 ;
F_21 ( V_56 ) ;
if ( V_33 == V_51 ) {
V_49 = F_18 ( V_47 ) ;
F_16 ( V_47 , V_49 | V_52 ) ;
}
F_13 ( V_31 , V_32 , V_17 , V_33 ) ;
if ( V_33 & V_55 )
F_17 () ;
if ( V_33 == V_51 )
F_16 ( V_47 , V_49 & ~ V_52 ) ;
F_22 ( V_56 ) ;
}
static void F_23 ( unsigned long V_31 , unsigned long V_32 ,
unsigned long V_17 )
{
unsigned long V_56 ;
F_21 ( V_56 ) ;
F_13 ( V_31 , V_32 , V_17 , V_38 ) ;
F_22 ( V_56 ) ;
}
static inline void F_24 ( void )
{
F_16 ( V_57 , 1 ) ;
F_18 ( V_58 ) ;
}
static void F_25 ( void * V_59 )
{
struct V_60 * V_61 = (struct V_60 * ) V_59 ;
F_23 ( V_61 -> V_31 , V_61 -> V_32 , V_61 -> V_17 ) ;
}
static void F_26 ( unsigned long V_31 , unsigned long V_32 ,
unsigned long V_17 )
{
struct V_60 V_61 = { V_31 , V_32 , V_17 } ;
F_27 ( F_25 , & V_61 , 1 ) ;
}
void F_28 ( struct V_62 * V_62 )
{
struct V_63 * V_64 ;
if ( ! F_12 () ) {
F_29 ( V_65 , & V_62 -> V_56 ) ;
return;
}
V_64 = F_30 ( V_62 ) ;
if ( ! V_64 )
return;
if ( ! F_31 ( V_64 ) ) {
F_29 ( V_65 , & V_62 -> V_56 ) ;
} else if ( F_32 ( V_62 ) ) {
void * V_31 = F_33 ( V_62 ) ;
unsigned long V_32 = V_62 -> V_66 << V_67 ;
if ( F_34 ( V_31 , V_32 ) )
F_35 ( V_31 , V_32 ) ;
}
}
void F_36 ( unsigned long V_68 , unsigned long V_17 )
{
F_37 ( V_68 , V_17 , V_51 ) ;
}
void F_38 ( unsigned long V_68 , unsigned long V_17 )
{
F_37 ( V_68 , V_17 , V_41 ) ;
}
void F_39 ( unsigned long V_68 , unsigned long V_17 )
{
F_37 ( V_68 , V_17 , V_55 ) ;
}
void F_40 ( unsigned long V_69 , unsigned long V_70 )
{
unsigned int V_71 , V_72 , V_17 ;
unsigned long V_73 , V_74 ;
if ( V_69 < V_75 ) {
F_8 ( L_8 ) ;
return;
}
V_71 = V_70 - V_69 ;
if ( V_71 > V_30 ) {
F_41 () ;
return;
}
if ( F_42 ( V_69 > V_76 ) ) {
F_43 ( V_69 , V_69 , V_70 - V_69 ) ;
return;
}
while ( V_71 > 0 ) {
V_72 = V_69 % V_30 ;
V_74 = F_44 ( ( void * ) V_69 ) ;
V_73 = ( V_74 << V_46 ) + V_72 ;
V_17 = F_45 (unsigned int, tot_sz, PAGE_SIZE - off) ;
F_43 ( V_73 , V_69 , V_17 ) ;
V_69 += V_17 ;
V_71 -= V_17 ;
}
}
void F_43 ( unsigned long V_31 , unsigned long V_32 , int V_3 )
{
F_20 ( V_31 , V_32 , V_3 , V_51 ) ;
F_26 ( V_31 , V_32 , V_3 ) ;
}
void F_46 ( unsigned long V_31 , unsigned long V_32 )
{
F_26 ( V_31 , V_32 , V_30 ) ;
}
void F_47 ( unsigned long V_31 , unsigned long V_32 )
{
F_20 ( V_31 , V_32 & V_77 , V_30 , V_51 ) ;
}
T_5 void F_41 ( void )
{
unsigned long V_56 ;
F_21 ( V_56 ) ;
F_24 () ;
F_19 ( V_51 ) ;
F_22 ( V_56 ) ;
}
void F_48 ( struct V_78 * V_79 )
{
F_41 () ;
}
void F_49 ( struct V_80 * V_81 , unsigned long V_82 ,
unsigned long V_74 )
{
unsigned int V_31 = V_74 << V_46 ;
V_82 &= V_77 ;
F_47 ( V_31 , V_82 ) ;
if ( V_81 -> V_83 & V_84 )
F_46 ( V_31 , V_82 ) ;
}
void F_50 ( struct V_80 * V_81 , unsigned long V_68 ,
unsigned long V_85 )
{
F_41 () ;
}
void F_51 ( struct V_80 * V_81 , struct V_62 * V_62 ,
unsigned long V_82 )
{
F_35 ( F_33 ( V_62 ) , V_82 ) ;
F_35 ( F_33 ( V_62 ) , F_33 ( V_62 ) ) ;
}
void F_52 ( struct V_62 * V_86 , struct V_62 * V_87 ,
unsigned long V_82 , struct V_80 * V_81 )
{
void * V_88 = F_33 ( V_87 ) ;
void * V_89 = F_33 ( V_86 ) ;
int V_90 = 0 ;
if ( F_32 ( V_87 ) && F_34 ( V_88 , V_82 ) ) {
F_35 ( V_88 , V_82 ) ;
V_90 = 1 ;
}
F_53 ( V_89 , V_88 ) ;
F_29 ( V_65 , & V_86 -> V_56 ) ;
if ( V_90 ) {
F_35 ( V_88 , V_88 ) ;
F_54 ( V_65 , & V_87 -> V_56 ) ;
} else {
F_29 ( V_65 , & V_87 -> V_56 ) ;
}
}
void F_55 ( void * V_86 , unsigned long V_82 , struct V_62 * V_62 )
{
F_56 ( V_86 ) ;
F_29 ( V_65 , & V_62 -> V_56 ) ;
}
