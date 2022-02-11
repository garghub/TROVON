char * F_1 ( int V_1 , char * V_2 , int V_3 )
{
int V_4 = 0 ;
unsigned int V_5 = F_2 () ;
#define F_3 ( T_1 , T_2 , T_3 ) \
{ \
if (!(p)->ver) \
n += scnprintf(buf + n, len - n, str"\t\t: N/A\n"); \
else \
n += scnprintf(buf + n, len - n, \
str"\t\t: (%uK) VIPT, %dway set-asc, %ub Line %s\n", \
TO_KB((p)->sz), (p)->assoc, (p)->line_len, \
enb ? "" : "DISABLED (kernel-build)"); \
}
F_3 ( & V_6 [ V_5 ] . V_7 , V_8 , L_1 ) ;
F_3 ( & V_6 [ V_5 ] . V_9 , V_10 , L_2 ) ;
return V_2 ;
}
void T_4 F_4 ( void )
{
struct V_11 V_12 , V_13 ;
struct V_14 * V_15 , * V_16 ;
unsigned int V_17 = F_2 () ;
V_15 = & V_6 [ V_17 ] . V_7 ;
F_5 ( V_18 , V_12 ) ;
if ( V_12 . V_19 == 0x3 )
V_15 -> V_20 = 2 ;
V_15 -> V_21 = 8 << V_12 . V_21 ;
V_15 -> V_22 = 0x200 << V_12 . V_22 ;
V_15 -> V_23 = V_12 . V_23 ;
V_16 = & V_6 [ V_17 ] . V_9 ;
F_5 ( V_24 , V_13 ) ;
if ( V_13 . V_19 == 0x2 )
V_16 -> V_20 = 4 ;
V_16 -> V_21 = 16 << V_13 . V_21 ;
V_16 -> V_22 = 0x200 << V_13 . V_22 ;
V_16 -> V_23 = V_13 . V_23 ;
}
void T_4 F_6 ( void )
{
unsigned int V_25 ;
unsigned int V_17 = F_2 () ;
struct V_14 * V_26 = & V_6 [ V_17 ] . V_7 ;
struct V_14 * V_27 = & V_6 [ V_17 ] . V_9 ;
int V_28 = V_28 ;
int V_29 ;
char T_3 [ 256 ] ;
F_7 ( F_1 ( 0 , T_3 , sizeof( T_3 ) ) ) ;
if ( ! V_26 -> V_23 )
goto V_30;
#ifdef F_8
if ( ( V_26 -> V_20 != V_31 ) ||
( V_26 -> V_21 != V_32 ) ) {
F_9 ( L_3 ) ;
}
#if ( V_33 > 2 )
if ( V_26 -> V_23 != 3 ) {
if ( V_34 )
F_9 ( L_4 ) ;
F_10 ( L_5 ) ;
}
#endif
#endif
V_25 = F_11 ( V_35 ) ;
#ifdef F_8
V_25 &= ~ V_36 ;
#else
V_25 |= V_36 ;
#endif
F_12 ( V_35 , V_25 ) ;
V_30:
if ( ! V_27 -> V_23 )
return;
#ifdef F_13
if ( ( V_27 -> V_20 != V_37 ) ||
( V_27 -> V_21 != V_38 ) ) {
F_9 ( L_3 ) ;
}
V_29 = ( V_27 -> V_22 / V_37 ) > V_39 ;
if ( V_29 && ! F_14 () )
F_9 ( L_6 ) ;
else if ( ! V_29 && F_14 () )
F_9 ( L_7 ) ;
#endif
V_25 = F_11 ( V_40 ) ;
V_25 &= ~ V_41 ;
#ifdef F_13
F_12 ( V_40 , V_25 & ~ V_36 ) ;
#else
F_12 ( V_42 , 0x1 ) ;
F_12 ( V_40 , V_25 | V_36 ) ;
#endif
return;
}
static inline void F_15 ( void )
{
while ( F_11 ( V_40 ) & V_43 )
;
}
static inline void F_16 ( const int V_44 )
{
unsigned long V_45 , V_46 = V_46 ;
int V_47 ;
F_17 ( V_45 ) ;
if ( V_44 == V_48 ) {
V_46 = F_11 ( V_40 ) ;
F_12 ( V_40 , V_46 | V_41 ) ;
}
if ( V_44 & V_49 )
V_47 = V_50 ;
else
V_47 = V_42 ;
F_12 ( V_47 , 0x1 ) ;
if ( V_44 & V_51 )
F_15 () ;
if ( V_44 == V_48 )
F_12 ( V_40 , V_46 & ~ V_41 ) ;
F_18 ( V_45 ) ;
}
static inline void F_19 ( unsigned long V_52 , unsigned long V_53 ,
unsigned long V_22 , const int V_54 )
{
int V_55 ;
if ( ! ( F_20 ( V_22 ) && V_22 == V_39 ) ) {
V_22 += V_52 & ~ V_56 ;
V_52 &= V_56 ;
V_53 &= V_56 ;
}
V_55 = F_21 ( V_22 , V_38 ) ;
#if ( V_33 <= 2 )
V_52 |= ( V_53 >> V_57 ) & 0x1F ;
#endif
while ( V_55 -- > 0 ) {
#if ( V_33 > 2 )
F_12 ( V_58 , V_52 ) ;
F_12 ( V_54 , V_53 ) ;
V_53 += V_38 ;
#else
F_12 ( V_54 , V_52 ) ;
#endif
V_52 += V_38 ;
}
}
static inline void F_22 ( unsigned long V_52 , unsigned long V_53 ,
unsigned long V_22 , const int V_44 )
{
unsigned long V_45 , V_46 = V_46 ;
int V_47 ;
F_17 ( V_45 ) ;
if ( V_44 == V_48 ) {
V_46 = F_11 ( V_40 ) ;
F_12 ( V_40 , V_46 | V_41 ) ;
}
if ( V_44 & V_49 )
V_47 = V_59 ;
else
V_47 = V_60 ;
F_19 ( V_52 , V_53 , V_22 , V_47 ) ;
if ( V_44 & V_51 )
F_15 () ;
if ( V_44 == V_48 )
F_12 ( V_40 , V_46 & ~ V_41 ) ;
F_18 ( V_45 ) ;
}
static void F_23 ( unsigned long V_52 , unsigned long V_53 ,
unsigned long V_22 )
{
unsigned long V_45 ;
int V_55 ;
if ( ! ( F_20 ( V_22 ) && V_22 == V_39 ) ) {
V_22 += V_52 & ~ V_61 ;
V_52 &= V_61 ;
V_53 &= V_61 ;
}
V_55 = F_21 ( V_22 , V_32 ) ;
#if ( V_33 <= 2 )
V_52 |= ( V_53 >> V_57 ) & 0x1F ;
#endif
F_17 ( V_45 ) ;
while ( V_55 -- > 0 ) {
#if ( V_33 > 2 )
F_12 ( V_62 , V_52 ) ;
F_12 ( V_63 , V_53 ) ;
V_53 += V_32 ;
#else
F_12 ( V_63 , V_52 ) ;
#endif
V_52 += V_32 ;
}
F_18 ( V_45 ) ;
}
void F_24 ( struct V_64 * V_64 )
{
struct V_65 * V_66 ;
if ( ! F_14 () ) {
F_25 ( V_67 , & V_64 -> V_45 ) ;
return;
}
V_66 = F_26 ( V_64 ) ;
if ( ! V_66 )
return;
if ( ! F_27 ( V_66 ) ) {
F_25 ( V_67 , & V_64 -> V_45 ) ;
} else if ( F_28 ( V_64 ) ) {
void * V_52 = F_29 ( V_64 ) ;
unsigned long V_53 = V_64 -> V_68 << V_69 ;
if ( F_30 ( V_52 , V_53 ) )
F_31 ( V_52 , V_53 ) ;
}
}
void F_32 ( unsigned long V_70 , unsigned long V_22 )
{
F_33 ( V_70 , V_22 , V_48 ) ;
}
void F_34 ( unsigned long V_70 , unsigned long V_22 )
{
F_33 ( V_70 , V_22 , V_49 ) ;
}
void F_35 ( unsigned long V_70 , unsigned long V_22 )
{
F_33 ( V_70 , V_22 , V_51 ) ;
}
void F_36 ( unsigned long V_71 , unsigned long V_72 )
{
unsigned int V_73 , V_74 , V_22 ;
unsigned long V_75 , V_76 ;
if ( V_71 < V_77 ) {
F_37 ( L_8 ) ;
return;
}
V_73 = V_72 - V_71 ;
if ( V_73 > V_39 ) {
F_38 () ;
return;
}
if ( F_39 ( V_71 > V_78 ) ) {
F_40 ( V_71 , V_71 , V_72 - V_71 ) ;
return;
}
while ( V_73 > 0 ) {
V_74 = V_71 % V_39 ;
V_76 = F_41 ( ( void * ) V_71 ) ;
V_75 = ( V_76 << V_57 ) + V_74 ;
V_22 = F_42 (unsigned int, tot_sz, PAGE_SIZE - off) ;
F_40 ( V_75 , V_71 , V_22 ) ;
V_71 += V_22 ;
V_73 -= V_22 ;
}
}
void F_40 ( unsigned long V_52 , unsigned long V_53 , int V_3 )
{
unsigned long V_45 ;
F_17 ( V_45 ) ;
F_23 ( V_52 , V_53 , V_3 ) ;
F_22 ( V_52 , V_53 , V_3 , V_48 ) ;
F_18 ( V_45 ) ;
}
void F_43 ( unsigned long V_52 , unsigned long V_53 )
{
F_23 ( V_52 , V_53 , V_39 ) ;
}
void F_44 ( unsigned long V_52 , unsigned long V_53 )
{
F_22 ( V_52 , V_53 & V_79 , V_39 , V_48 ) ;
}
void F_45 ( void )
{
unsigned long V_45 ;
F_17 ( V_45 ) ;
F_12 ( V_80 , 1 ) ;
F_11 ( V_35 ) ;
F_18 ( V_45 ) ;
}
T_5 void F_38 ( void )
{
unsigned long V_45 ;
F_17 ( V_45 ) ;
F_45 () ;
F_16 ( V_48 ) ;
F_18 ( V_45 ) ;
}
void F_46 ( struct V_81 * V_82 )
{
F_38 () ;
}
void F_47 ( struct V_83 * V_84 , unsigned long V_85 ,
unsigned long V_76 )
{
unsigned int V_52 = V_76 << V_57 ;
F_40 ( V_52 , V_85 , V_39 ) ;
}
void F_48 ( struct V_83 * V_84 , unsigned long V_70 ,
unsigned long V_86 )
{
F_38 () ;
}
void F_49 ( struct V_83 * V_84 , struct V_64 * V_64 ,
unsigned long V_85 )
{
F_31 ( F_29 ( V_64 ) , V_85 ) ;
F_31 ( F_29 ( V_64 ) , F_29 ( V_64 ) ) ;
}
void F_50 ( struct V_64 * V_87 , struct V_64 * V_88 ,
unsigned long V_85 , struct V_83 * V_84 )
{
void * V_89 = F_29 ( V_88 ) ;
void * V_90 = F_29 ( V_87 ) ;
int V_91 = 0 ;
if ( F_28 ( V_88 ) && F_30 ( V_89 , V_85 ) ) {
F_31 ( V_89 , V_85 ) ;
V_91 = 1 ;
}
F_51 ( V_90 , V_89 ) ;
F_25 ( V_67 , & V_87 -> V_45 ) ;
if ( V_91 ) {
F_31 ( V_89 , V_89 ) ;
} else {
F_25 ( V_67 , & V_88 -> V_45 ) ;
}
}
void F_52 ( void * V_87 , unsigned long V_85 , struct V_64 * V_64 )
{
F_53 ( V_87 ) ;
F_25 ( V_67 , & V_64 -> V_45 ) ;
}
