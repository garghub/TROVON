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
if ( V_27 -> V_17 != V_31 )
F_11 ( L_3 ) ;
V_28 = ( V_27 -> V_18 / V_27 -> V_24 ) > V_35 ;
if ( V_28 && ! F_14 () )
F_11 ( L_5 ) ;
else if ( ! V_28 && F_14 () )
F_11 ( L_6 ) ;
#endif
V_29 = F_12 ( V_36 ) ;
V_29 &= ~ V_37 ;
#ifdef V_10
F_13 ( V_36 , V_29 & ~ V_34 ) ;
#else
F_13 ( V_38 , 0x1 ) ;
F_13 ( V_36 , V_29 | V_34 ) ;
#endif
return;
}
static inline void F_15 ( unsigned long V_39 , unsigned long V_40 ,
unsigned long V_18 , const int V_41 )
{
unsigned int V_42 , V_43 ;
int V_44 ;
const int V_45 = F_16 ( V_18 ) && V_18 == V_35 ;
if ( V_41 == V_46 ) {
V_42 = V_47 ;
V_43 = V_48 ;
}
else {
V_42 = V_41 & V_49 ? V_50 : V_51 ;
V_43 = V_52 ;
}
if ( ! V_45 ) {
V_18 += V_39 & ~ V_53 ;
V_39 &= V_53 ;
V_40 &= V_53 ;
}
V_44 = F_17 ( V_18 , V_31 ) ;
#if ( V_32 <= 2 )
V_39 |= ( V_40 >> V_54 ) & 0x1F ;
#else
if ( V_45 )
F_13 ( V_43 , V_39 ) ;
#endif
while ( V_44 -- > 0 ) {
#if ( V_32 > 2 )
if ( ! V_45 ) {
F_13 ( V_43 , V_39 ) ;
V_39 += V_31 ;
}
F_13 ( V_42 , V_40 ) ;
V_40 += V_31 ;
#else
F_13 ( V_42 , V_39 ) ;
V_39 += V_31 ;
#endif
}
}
static inline void F_18 ( void )
{
while ( F_12 ( V_36 ) & V_55 )
;
}
static inline void F_19 ( const int V_41 )
{
unsigned int V_56 = V_56 ;
int V_57 ;
if ( V_41 == V_58 ) {
V_56 = F_12 ( V_36 ) ;
F_13 ( V_36 , V_56 | V_37 ) ;
}
if ( V_41 & V_49 )
V_57 = V_59 ;
else
V_57 = V_38 ;
F_13 ( V_57 , 0x1 ) ;
if ( V_41 & V_60 )
F_18 () ;
if ( V_41 == V_58 )
F_13 ( V_36 , V_56 & ~ V_37 ) ;
}
static inline void F_20 ( unsigned long V_39 , unsigned long V_40 ,
unsigned long V_18 , const int V_41 )
{
unsigned long V_61 , V_56 = V_56 ;
F_21 ( V_61 ) ;
if ( V_41 == V_58 ) {
V_56 = F_12 ( V_36 ) ;
F_13 ( V_36 , V_56 | V_37 ) ;
}
F_15 ( V_39 , V_40 , V_18 , V_41 ) ;
if ( V_41 & V_60 )
F_18 () ;
if ( V_41 == V_58 )
F_13 ( V_36 , V_56 & ~ V_37 ) ;
F_22 ( V_61 ) ;
}
static void F_23 ( unsigned long V_39 , unsigned long V_40 ,
unsigned long V_18 )
{
unsigned long V_61 ;
F_21 ( V_61 ) ;
F_15 ( V_39 , V_40 , V_18 , V_46 ) ;
F_22 ( V_61 ) ;
}
static inline void F_24 ( void )
{
F_13 ( V_62 , 1 ) ;
F_12 ( V_33 ) ;
}
void F_25 ( struct V_63 * V_63 )
{
struct V_64 * V_65 ;
if ( ! F_14 () ) {
F_26 ( V_66 , & V_63 -> V_61 ) ;
return;
}
V_65 = F_27 ( V_63 ) ;
if ( ! V_65 )
return;
if ( ! F_28 ( V_65 ) ) {
F_26 ( V_66 , & V_63 -> V_61 ) ;
} else if ( F_29 ( V_63 ) ) {
void * V_39 = F_30 ( V_63 ) ;
unsigned long V_40 = V_63 -> V_67 << V_68 ;
if ( F_31 ( V_39 , V_40 ) )
F_32 ( V_39 , V_40 ) ;
}
}
void F_33 ( unsigned long V_69 , unsigned long V_18 )
{
F_34 ( V_69 , V_18 , V_58 ) ;
}
void F_35 ( unsigned long V_69 , unsigned long V_18 )
{
F_34 ( V_69 , V_18 , V_49 ) ;
}
void F_36 ( unsigned long V_69 , unsigned long V_18 )
{
F_34 ( V_69 , V_18 , V_60 ) ;
}
void F_37 ( unsigned long V_70 , unsigned long V_71 )
{
unsigned int V_72 , V_73 , V_18 ;
unsigned long V_74 , V_75 ;
if ( V_70 < V_76 ) {
F_8 ( L_7 ) ;
return;
}
V_72 = V_71 - V_70 ;
if ( V_72 > V_35 ) {
F_38 () ;
return;
}
if ( F_39 ( V_70 > V_77 ) ) {
F_40 ( V_70 , V_70 , V_71 - V_70 ) ;
return;
}
while ( V_72 > 0 ) {
V_73 = V_70 % V_35 ;
V_75 = F_41 ( ( void * ) V_70 ) ;
V_74 = ( V_75 << V_54 ) + V_73 ;
V_18 = F_42 (unsigned int, tot_sz, PAGE_SIZE - off) ;
F_40 ( V_74 , V_70 , V_18 ) ;
V_70 += V_18 ;
V_72 -= V_18 ;
}
}
void F_40 ( unsigned long V_39 , unsigned long V_40 , int V_3 )
{
unsigned long V_61 ;
F_21 ( V_61 ) ;
F_23 ( V_39 , V_40 , V_3 ) ;
F_20 ( V_39 , V_40 , V_3 , V_58 ) ;
F_22 ( V_61 ) ;
}
void F_43 ( unsigned long V_39 , unsigned long V_40 )
{
F_23 ( V_39 , V_40 , V_35 ) ;
}
void F_44 ( unsigned long V_39 , unsigned long V_40 )
{
F_20 ( V_39 , V_40 & V_78 , V_35 , V_58 ) ;
}
T_4 void F_38 ( void )
{
unsigned long V_61 ;
F_21 ( V_61 ) ;
F_24 () ;
F_19 ( V_58 ) ;
F_22 ( V_61 ) ;
}
void F_45 ( struct V_79 * V_80 )
{
F_38 () ;
}
void F_46 ( struct V_81 * V_82 , unsigned long V_83 ,
unsigned long V_75 )
{
unsigned int V_39 = V_75 << V_54 ;
V_83 &= V_78 ;
F_44 ( V_39 , V_83 ) ;
if ( V_82 -> V_84 & V_85 )
F_43 ( V_39 , V_83 ) ;
}
void F_47 ( struct V_81 * V_82 , unsigned long V_69 ,
unsigned long V_86 )
{
F_38 () ;
}
void F_48 ( struct V_81 * V_82 , struct V_63 * V_63 ,
unsigned long V_83 )
{
F_32 ( F_30 ( V_63 ) , V_83 ) ;
F_32 ( F_30 ( V_63 ) , F_30 ( V_63 ) ) ;
}
void F_49 ( struct V_63 * V_87 , struct V_63 * V_88 ,
unsigned long V_83 , struct V_81 * V_82 )
{
void * V_89 = F_30 ( V_88 ) ;
void * V_90 = F_30 ( V_87 ) ;
int V_91 = 0 ;
if ( F_29 ( V_88 ) && F_31 ( V_89 , V_83 ) ) {
F_32 ( V_89 , V_83 ) ;
V_91 = 1 ;
}
F_50 ( V_90 , V_89 ) ;
F_26 ( V_66 , & V_87 -> V_61 ) ;
if ( V_91 ) {
F_32 ( V_89 , V_89 ) ;
F_51 ( V_66 , & V_88 -> V_61 ) ;
} else {
F_26 ( V_66 , & V_88 -> V_61 ) ;
}
}
void F_52 ( void * V_87 , unsigned long V_83 , struct V_63 * V_63 )
{
F_53 ( V_87 ) ;
F_26 ( V_66 , & V_63 -> V_61 ) ;
}
