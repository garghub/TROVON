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
F_3 ( & V_6 [ V_5 ] . V_7 , F_4 ( V_8 ) ,
L_1 ) ;
F_3 ( & V_6 [ V_5 ] . V_9 , F_4 ( V_10 ) ,
L_2 ) ;
return V_2 ;
}
void F_5 ( void )
{
struct V_11 * V_12 , * V_13 ;
unsigned int V_14 = F_2 () ;
struct V_15 {
#ifdef F_6
unsigned int V_16 : 12 , V_17 : 4 , V_18 : 4 , V_19 : 4 , V_20 : 8 ;
#else
unsigned int V_20 : 8 , V_19 : 4 , V_18 : 4 , V_17 : 4 , V_16 : 12 ;
#endif
} V_21 , V_22 ;
V_12 = & V_6 [ V_14 ] . V_7 ;
F_7 ( V_23 , V_21 ) ;
F_8 ( V_21 . V_19 != 3 ) ;
V_12 -> V_24 = 2 ;
V_12 -> V_17 = 8 << V_21 . V_17 ;
V_12 -> V_18 = 0x200 << V_21 . V_18 ;
V_12 -> V_20 = V_21 . V_20 ;
V_13 = & V_6 [ V_14 ] . V_9 ;
F_7 ( V_25 , V_22 ) ;
F_8 ( V_22 . V_19 != 2 ) ;
V_13 -> V_24 = 4 ;
V_13 -> V_17 = 16 << V_22 . V_17 ;
V_13 -> V_18 = 0x200 << V_22 . V_18 ;
V_13 -> V_20 = V_22 . V_20 ;
}
void F_9 ( void )
{
unsigned int V_14 = F_2 () ;
struct V_11 * V_26 = & V_6 [ V_14 ] . V_7 ;
struct V_11 * V_27 = & V_6 [ V_14 ] . V_9 ;
unsigned int V_28 , V_29 ;
char T_3 [ 256 ] ;
F_10 ( F_1 ( 0 , T_3 , sizeof( T_3 ) ) ) ;
if ( ! V_26 -> V_20 )
goto V_30;
#ifdef V_8
if ( V_26 -> V_17 != V_31 )
F_11 ( L_3 ) ;
if ( V_26 -> V_20 != V_32 )
F_11 ( L_4 ) ;
#endif
V_29 = F_12 ( V_33 ) ;
#ifdef V_8
V_29 &= ~ V_34 ;
#else
V_29 |= V_34 ;
#endif
F_13 ( V_33 , V_29 ) ;
V_30:
if ( ! V_27 -> V_20 )
return;
#ifdef V_10
if ( V_27 -> V_17 != V_35 )
F_11 ( L_3 ) ;
V_28 = ( V_27 -> V_18 / V_27 -> V_24 ) > V_36 ;
if ( V_28 && ! F_14 () )
F_11 ( L_5 ) ;
else if ( ! V_28 && F_14 () )
F_11 ( L_6 ) ;
#endif
V_29 = F_12 ( V_37 ) ;
V_29 &= ~ V_38 ;
#ifdef V_10
F_13 ( V_37 , V_29 & ~ V_34 ) ;
#else
F_13 ( V_39 , 0x1 ) ;
F_13 ( V_37 , V_29 | V_34 ) ;
#endif
return;
}
static inline void F_15 ( void )
{
while ( F_12 ( V_37 ) & V_40 )
;
}
static inline void F_16 ( const int V_41 )
{
unsigned int V_42 = V_42 ;
int V_43 ;
if ( V_41 == V_44 ) {
V_42 = F_12 ( V_37 ) ;
F_13 ( V_37 , V_42 | V_38 ) ;
}
if ( V_41 & V_45 )
V_43 = V_46 ;
else
V_43 = V_39 ;
F_13 ( V_43 , 0x1 ) ;
if ( V_41 & V_47 )
F_15 () ;
if ( V_41 == V_44 )
F_13 ( V_37 , V_42 & ~ V_38 ) ;
}
static inline void F_17 ( unsigned long V_48 , unsigned long V_49 ,
unsigned long V_18 , const int V_50 )
{
int V_51 ;
if ( ! ( F_18 ( V_18 ) && V_18 == V_36 ) ) {
V_18 += V_48 & ~ V_52 ;
V_48 &= V_52 ;
V_49 &= V_52 ;
}
V_51 = F_19 ( V_18 , V_35 ) ;
#if ( V_32 <= 2 )
V_48 |= ( V_49 >> V_53 ) & 0x1F ;
#endif
while ( V_51 -- > 0 ) {
#if ( V_32 > 2 )
F_13 ( V_54 , V_48 ) ;
F_13 ( V_50 , V_49 ) ;
V_49 += V_35 ;
#else
F_13 ( V_50 , V_48 ) ;
#endif
V_48 += V_35 ;
}
}
static inline void F_20 ( unsigned long V_48 , unsigned long V_49 ,
unsigned long V_18 , const int V_41 )
{
unsigned long V_55 , V_42 = V_42 ;
int V_43 ;
F_21 ( V_55 ) ;
if ( V_41 == V_44 ) {
V_42 = F_12 ( V_37 ) ;
F_13 ( V_37 , V_42 | V_38 ) ;
}
if ( V_41 & V_45 )
V_43 = V_56 ;
else
V_43 = V_57 ;
F_17 ( V_48 , V_49 , V_18 , V_43 ) ;
if ( V_41 & V_47 )
F_15 () ;
if ( V_41 == V_44 )
F_13 ( V_37 , V_42 & ~ V_38 ) ;
F_22 ( V_55 ) ;
}
static void F_23 ( unsigned long V_48 , unsigned long V_49 ,
unsigned long V_18 )
{
unsigned long V_55 ;
int V_51 ;
if ( ! ( F_18 ( V_18 ) && V_18 == V_36 ) ) {
V_18 += V_48 & ~ V_58 ;
V_48 &= V_58 ;
V_49 &= V_58 ;
}
V_51 = F_19 ( V_18 , V_31 ) ;
#if ( V_32 <= 2 )
V_48 |= ( V_49 >> V_53 ) & 0x1F ;
#endif
F_21 ( V_55 ) ;
while ( V_51 -- > 0 ) {
#if ( V_32 > 2 )
F_13 ( V_59 , V_48 ) ;
F_13 ( V_60 , V_49 ) ;
V_49 += V_31 ;
#else
F_13 ( V_60 , V_48 ) ;
#endif
V_48 += V_31 ;
}
F_22 ( V_55 ) ;
}
static inline void F_24 ( void )
{
F_13 ( V_61 , 1 ) ;
F_12 ( V_33 ) ;
}
void F_25 ( struct V_62 * V_62 )
{
struct V_63 * V_64 ;
if ( ! F_14 () ) {
F_26 ( V_65 , & V_62 -> V_55 ) ;
return;
}
V_64 = F_27 ( V_62 ) ;
if ( ! V_64 )
return;
if ( ! F_28 ( V_64 ) ) {
F_26 ( V_65 , & V_62 -> V_55 ) ;
} else if ( F_29 ( V_62 ) ) {
void * V_48 = F_30 ( V_62 ) ;
unsigned long V_49 = V_62 -> V_66 << V_67 ;
if ( F_31 ( V_48 , V_49 ) )
F_32 ( V_48 , V_49 ) ;
}
}
void F_33 ( unsigned long V_68 , unsigned long V_18 )
{
F_34 ( V_68 , V_18 , V_44 ) ;
}
void F_35 ( unsigned long V_68 , unsigned long V_18 )
{
F_34 ( V_68 , V_18 , V_45 ) ;
}
void F_36 ( unsigned long V_68 , unsigned long V_18 )
{
F_34 ( V_68 , V_18 , V_47 ) ;
}
void F_37 ( unsigned long V_69 , unsigned long V_70 )
{
unsigned int V_71 , V_72 , V_18 ;
unsigned long V_73 , V_74 ;
if ( V_69 < V_75 ) {
F_8 ( L_7 ) ;
return;
}
V_71 = V_70 - V_69 ;
if ( V_71 > V_36 ) {
F_38 () ;
return;
}
if ( F_39 ( V_69 > V_76 ) ) {
F_40 ( V_69 , V_69 , V_70 - V_69 ) ;
return;
}
while ( V_71 > 0 ) {
V_72 = V_69 % V_36 ;
V_74 = F_41 ( ( void * ) V_69 ) ;
V_73 = ( V_74 << V_53 ) + V_72 ;
V_18 = F_42 (unsigned int, tot_sz, PAGE_SIZE - off) ;
F_40 ( V_73 , V_69 , V_18 ) ;
V_69 += V_18 ;
V_71 -= V_18 ;
}
}
void F_40 ( unsigned long V_48 , unsigned long V_49 , int V_3 )
{
unsigned long V_55 ;
F_21 ( V_55 ) ;
F_23 ( V_48 , V_49 , V_3 ) ;
F_20 ( V_48 , V_49 , V_3 , V_44 ) ;
F_22 ( V_55 ) ;
}
void F_43 ( unsigned long V_48 , unsigned long V_49 )
{
F_23 ( V_48 , V_49 , V_36 ) ;
}
void F_44 ( unsigned long V_48 , unsigned long V_49 )
{
F_20 ( V_48 , V_49 & V_77 , V_36 , V_44 ) ;
}
T_4 void F_38 ( void )
{
unsigned long V_55 ;
F_21 ( V_55 ) ;
F_24 () ;
F_16 ( V_44 ) ;
F_22 ( V_55 ) ;
}
void F_45 ( struct V_78 * V_79 )
{
F_38 () ;
}
void F_46 ( struct V_80 * V_81 , unsigned long V_82 ,
unsigned long V_74 )
{
unsigned int V_48 = V_74 << V_53 ;
V_82 &= V_77 ;
F_44 ( V_48 , V_82 ) ;
if ( V_81 -> V_83 & V_84 )
F_43 ( V_48 , V_82 ) ;
}
void F_47 ( struct V_80 * V_81 , unsigned long V_68 ,
unsigned long V_85 )
{
F_38 () ;
}
void F_48 ( struct V_80 * V_81 , struct V_62 * V_62 ,
unsigned long V_82 )
{
F_32 ( F_30 ( V_62 ) , V_82 ) ;
F_32 ( F_30 ( V_62 ) , F_30 ( V_62 ) ) ;
}
void F_49 ( struct V_62 * V_86 , struct V_62 * V_87 ,
unsigned long V_82 , struct V_80 * V_81 )
{
void * V_88 = F_30 ( V_87 ) ;
void * V_89 = F_30 ( V_86 ) ;
int V_90 = 0 ;
if ( F_29 ( V_87 ) && F_31 ( V_88 , V_82 ) ) {
F_32 ( V_88 , V_82 ) ;
V_90 = 1 ;
}
F_50 ( V_89 , V_88 ) ;
F_26 ( V_65 , & V_86 -> V_55 ) ;
if ( V_90 ) {
F_32 ( V_88 , V_88 ) ;
F_51 ( V_65 , & V_87 -> V_55 ) ;
} else {
F_26 ( V_65 , & V_87 -> V_55 ) ;
}
}
void F_52 ( void * V_86 , unsigned long V_82 , struct V_62 * V_62 )
{
F_53 ( V_86 ) ;
F_26 ( V_65 , & V_62 -> V_55 ) ;
}
