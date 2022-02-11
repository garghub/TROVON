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
unsigned int V_13 = F_5 () ;
struct V_10 * V_25 = & V_5 [ V_13 ] . V_6 ;
struct V_10 * V_26 = & V_5 [ V_13 ] . V_8 ;
unsigned int V_27 , V_28 ;
char T_3 [ 256 ] ;
F_10 ( F_1 ( 0 , T_3 , sizeof( T_3 ) ) ) ;
if ( ! V_25 -> V_19 )
goto V_29;
#ifdef V_7
if ( V_25 -> V_16 != V_30 )
F_11 ( L_3 ) ;
if ( V_25 -> V_19 != V_31 )
F_11 ( L_4 ) ;
#endif
V_28 = F_12 ( V_32 ) ;
#ifdef V_7
V_28 &= ~ V_33 ;
#else
V_28 |= V_33 ;
#endif
F_13 ( V_32 , V_28 ) ;
V_29:
if ( ! V_26 -> V_19 )
return;
#ifdef V_9
if ( V_26 -> V_16 != V_30 )
F_11 ( L_3 ) ;
V_27 = ( V_26 -> V_17 / V_26 -> V_23 ) > V_34 ;
if ( V_27 && ! F_14 () )
F_11 ( L_5 ) ;
else if ( ! V_27 && F_14 () )
F_11 ( L_6 ) ;
#endif
V_28 = F_12 ( V_35 ) ;
V_28 &= ~ V_36 ;
#ifdef V_9
F_13 ( V_35 , V_28 & ~ V_33 ) ;
#else
F_13 ( V_37 , 0x1 ) ;
F_13 ( V_35 , V_28 | V_33 ) ;
#endif
return;
}
static inline void F_15 ( unsigned long V_38 , unsigned long V_39 ,
unsigned long V_17 , const int V_40 )
{
unsigned int V_41 , V_42 ;
int V_43 ;
const int V_44 = F_16 ( V_17 ) && V_17 == V_34 ;
if ( V_40 == V_45 ) {
V_41 = V_46 ;
V_42 = V_47 ;
}
else {
V_41 = V_40 & V_48 ? V_49 : V_50 ;
V_42 = V_51 ;
}
if ( ! V_44 ) {
V_17 += V_38 & ~ V_52 ;
V_38 &= V_52 ;
V_39 &= V_52 ;
}
V_43 = F_17 ( V_17 , V_30 ) ;
#if ( V_31 <= 2 )
V_38 |= ( V_39 >> V_53 ) & 0x1F ;
#else
if ( V_44 )
F_13 ( V_42 , V_38 ) ;
#endif
while ( V_43 -- > 0 ) {
#if ( V_31 > 2 )
if ( ! V_44 ) {
F_13 ( V_42 , V_38 ) ;
V_38 += V_30 ;
}
F_13 ( V_41 , V_39 ) ;
V_39 += V_30 ;
#else
F_13 ( V_41 , V_38 ) ;
V_38 += V_30 ;
#endif
}
}
static inline void F_18 ( void )
{
while ( F_12 ( V_35 ) & V_54 )
;
}
static inline void F_19 ( const int V_40 )
{
unsigned int V_55 = V_55 ;
int V_56 ;
if ( V_40 == V_57 ) {
V_55 = F_12 ( V_35 ) ;
F_13 ( V_35 , V_55 | V_36 ) ;
}
if ( V_40 & V_48 )
V_56 = V_58 ;
else
V_56 = V_37 ;
F_13 ( V_56 , 0x1 ) ;
if ( V_40 & V_59 )
F_18 () ;
if ( V_40 == V_57 )
F_13 ( V_35 , V_55 & ~ V_36 ) ;
}
static inline void F_20 ( unsigned long V_38 , unsigned long V_39 ,
unsigned long V_17 , const int V_40 )
{
unsigned long V_60 , V_55 = V_55 ;
F_21 ( V_60 ) ;
if ( V_40 == V_57 ) {
V_55 = F_12 ( V_35 ) ;
F_13 ( V_35 , V_55 | V_36 ) ;
}
F_15 ( V_38 , V_39 , V_17 , V_40 ) ;
if ( V_40 & V_59 )
F_18 () ;
if ( V_40 == V_57 )
F_13 ( V_35 , V_55 & ~ V_36 ) ;
F_22 ( V_60 ) ;
}
static void F_23 ( unsigned long V_38 , unsigned long V_39 ,
unsigned long V_17 )
{
unsigned long V_60 ;
F_21 ( V_60 ) ;
F_15 ( V_38 , V_39 , V_17 , V_45 ) ;
F_22 ( V_60 ) ;
}
static inline void F_24 ( void )
{
F_13 ( V_61 , 1 ) ;
F_12 ( V_32 ) ;
}
void F_25 ( struct V_62 * V_62 )
{
struct V_63 * V_64 ;
if ( ! F_14 () ) {
F_26 ( V_65 , & V_62 -> V_60 ) ;
return;
}
V_64 = F_27 ( V_62 ) ;
if ( ! V_64 )
return;
if ( ! F_28 ( V_64 ) ) {
F_26 ( V_65 , & V_62 -> V_60 ) ;
} else if ( F_29 ( V_62 ) ) {
void * V_38 = F_30 ( V_62 ) ;
unsigned long V_39 = V_62 -> V_66 << V_67 ;
if ( F_31 ( V_38 , V_39 ) )
F_32 ( V_38 , V_39 ) ;
}
}
void F_33 ( unsigned long V_68 , unsigned long V_17 )
{
F_34 ( V_68 , V_17 , V_57 ) ;
}
void F_35 ( unsigned long V_68 , unsigned long V_17 )
{
F_34 ( V_68 , V_17 , V_48 ) ;
}
void F_36 ( unsigned long V_68 , unsigned long V_17 )
{
F_34 ( V_68 , V_17 , V_59 ) ;
}
void F_37 ( unsigned long V_69 , unsigned long V_70 )
{
unsigned int V_71 , V_72 , V_17 ;
unsigned long V_73 , V_74 ;
if ( V_69 < V_75 ) {
F_8 ( L_7 ) ;
return;
}
V_71 = V_70 - V_69 ;
if ( V_71 > V_34 ) {
F_38 () ;
return;
}
if ( F_39 ( V_69 > V_76 ) ) {
F_40 ( V_69 , V_69 , V_70 - V_69 ) ;
return;
}
while ( V_71 > 0 ) {
V_72 = V_69 % V_34 ;
V_74 = F_41 ( ( void * ) V_69 ) ;
V_73 = ( V_74 << V_53 ) + V_72 ;
V_17 = F_42 (unsigned int, tot_sz, PAGE_SIZE - off) ;
F_40 ( V_73 , V_69 , V_17 ) ;
V_69 += V_17 ;
V_71 -= V_17 ;
}
}
void F_40 ( unsigned long V_38 , unsigned long V_39 , int V_3 )
{
unsigned long V_60 ;
F_21 ( V_60 ) ;
F_23 ( V_38 , V_39 , V_3 ) ;
F_20 ( V_38 , V_39 , V_3 , V_57 ) ;
F_22 ( V_60 ) ;
}
void F_43 ( unsigned long V_38 , unsigned long V_39 )
{
F_23 ( V_38 , V_39 , V_34 ) ;
}
void F_44 ( unsigned long V_38 , unsigned long V_39 )
{
F_20 ( V_38 , V_39 & V_77 , V_34 , V_57 ) ;
}
T_4 void F_38 ( void )
{
unsigned long V_60 ;
F_21 ( V_60 ) ;
F_24 () ;
F_19 ( V_57 ) ;
F_22 ( V_60 ) ;
}
void F_45 ( struct V_78 * V_79 )
{
F_38 () ;
}
void F_46 ( struct V_80 * V_81 , unsigned long V_82 ,
unsigned long V_74 )
{
unsigned int V_38 = V_74 << V_53 ;
V_82 &= V_77 ;
F_44 ( V_38 , V_82 ) ;
if ( V_81 -> V_83 & V_84 )
F_43 ( V_38 , V_82 ) ;
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
F_26 ( V_65 , & V_86 -> V_60 ) ;
if ( V_90 ) {
F_32 ( V_88 , V_88 ) ;
F_51 ( V_65 , & V_87 -> V_60 ) ;
} else {
F_26 ( V_65 , & V_87 -> V_60 ) ;
}
}
void F_52 ( void * V_86 , unsigned long V_82 , struct V_62 * V_62 )
{
F_53 ( V_86 ) ;
F_26 ( V_65 , & V_62 -> V_60 ) ;
}
