char * F_1 ( int V_1 , char * V_2 , int V_3 )
{
int V_4 = 0 ;
#define F_2 ( T_1 , T_2 , T_3 ) \
if (!(p)->ver) \
n += scnprintf(buf + n, len - n, str"\t\t: N/A\n"); \
else \
n += scnprintf(buf + n, len - n, \
str"\t\t: %uK, %dway/set, %uB Line, %s%s%s\n", \
(p)->sz_k, (p)->assoc, (p)->line_len, \
(p)->vipt ? "VIPT" : "PIPT", \
(p)->alias ? " aliasing" : "", \
IS_ENABLED(cfg) ? "" : " (not used)");
F_2 ( & V_5 [ V_1 ] . V_6 , V_7 , L_1 ) ;
F_2 ( & V_5 [ V_1 ] . V_8 , V_9 , L_2 ) ;
return V_2 ;
}
void F_3 ( void )
{
struct V_10 * V_11 , * V_12 ;
unsigned int V_13 = F_4 () ;
struct V_14 {
#ifdef F_5
unsigned int V_15 : 12 , V_16 : 4 , V_17 : 4 , V_18 : 4 , V_19 : 8 ;
#else
unsigned int V_19 : 8 , V_18 : 4 , V_17 : 4 , V_16 : 4 , V_15 : 12 ;
#endif
} V_20 , V_21 ;
V_11 = & V_5 [ V_13 ] . V_6 ;
F_6 ( V_22 , V_20 ) ;
if ( ! V_20 . V_19 )
goto V_23;
F_7 ( V_20 . V_18 != 3 ) ;
V_11 -> V_24 = 2 ;
V_11 -> V_16 = 8 << V_20 . V_16 ;
V_11 -> V_25 = 1 << ( V_20 . V_17 - 1 ) ;
V_11 -> V_19 = V_20 . V_19 ;
V_11 -> V_26 = 1 ;
V_11 -> V_27 = V_11 -> V_25 / V_11 -> V_24 / F_8 ( V_28 ) > 1 ;
V_23:
V_12 = & V_5 [ V_13 ] . V_8 ;
F_6 ( V_29 , V_21 ) ;
if ( ! V_21 . V_19 )
return;
F_7 ( V_21 . V_18 != 2 ) ;
V_12 -> V_24 = 4 ;
V_12 -> V_16 = 16 << V_21 . V_16 ;
V_12 -> V_25 = 1 << ( V_21 . V_17 - 1 ) ;
V_12 -> V_19 = V_21 . V_19 ;
V_12 -> V_26 = 1 ;
V_12 -> V_27 = V_12 -> V_25 / V_12 -> V_24 / F_8 ( V_28 ) > 1 ;
}
void F_9 ( void )
{
unsigned int T_4 V_13 = F_4 () ;
char T_3 [ 256 ] ;
F_10 ( F_1 ( 0 , T_3 , sizeof( T_3 ) ) ) ;
if ( F_11 ( V_7 ) ) {
struct V_10 * V_30 = & V_5 [ V_13 ] . V_6 ;
if ( ! V_30 -> V_19 )
F_12 ( L_3 ) ;
if ( V_30 -> V_16 != V_31 )
F_12 ( L_4 ,
V_30 -> V_16 , V_31 ) ;
if ( V_30 -> V_19 != V_32 )
F_12 ( L_5 ,
V_30 -> V_19 , V_32 ) ;
}
if ( F_11 ( V_9 ) ) {
struct V_10 * V_33 = & V_5 [ V_13 ] . V_8 ;
int V_34 ;
if ( ! V_33 -> V_19 )
F_12 ( L_3 ) ;
if ( V_33 -> V_16 != V_31 )
F_12 ( L_6 ,
V_33 -> V_16 , V_31 ) ;
V_34 = F_11 ( V_35 ) ;
if ( V_33 -> V_27 && ! V_34 )
F_12 ( L_7 ) ;
else if ( ! V_33 -> V_27 && V_34 )
F_12 ( L_8 ) ;
}
}
static inline void F_13 ( unsigned long V_36 , unsigned long V_37 ,
unsigned long V_17 , const int V_38 )
{
unsigned int V_39 , V_40 ;
int V_41 ;
const int V_42 = F_14 ( V_17 ) && V_17 == V_28 ;
if ( V_38 == V_43 ) {
V_39 = V_44 ;
#if ( V_32 > 2 )
V_40 = V_45 ;
#endif
}
else {
V_39 = V_38 & V_46 ? V_47 : V_48 ;
#if ( V_32 > 2 )
V_40 = V_49 ;
#endif
}
if ( ! V_42 ) {
V_17 += V_36 & ~ V_50 ;
V_36 &= V_50 ;
V_37 &= V_50 ;
}
V_41 = F_15 ( V_17 , V_31 ) ;
#if ( V_32 <= 2 )
V_36 |= ( V_37 >> V_51 ) & 0x1F ;
#else
if ( V_42 )
F_16 ( V_40 , V_36 ) ;
#endif
while ( V_41 -- > 0 ) {
#if ( V_32 > 2 )
if ( ! V_42 ) {
F_16 ( V_40 , V_36 ) ;
V_36 += V_31 ;
}
F_16 ( V_39 , V_37 ) ;
V_37 += V_31 ;
#else
F_16 ( V_39 , V_36 ) ;
V_36 += V_31 ;
#endif
}
}
static inline unsigned int F_17 ( const int V_52 )
{
unsigned int V_53 = V_53 ;
if ( V_52 == V_54 ) {
V_53 = F_18 ( V_55 ) ;
F_16 ( V_55 , V_53 | V_56 )
;
}
return V_53 ;
}
static inline void F_19 ( const int V_52 , unsigned int V_53 )
{
if ( V_52 & V_57 )
while ( F_18 ( V_55 ) & V_58 ) ;
if ( V_52 == V_54 )
F_16 ( V_55 , V_53 & ~ V_56 ) ;
}
static inline void F_20 ( const int V_38 )
{
unsigned int V_59 ;
int V_60 ;
V_59 = F_17 ( V_38 ) ;
if ( V_38 & V_46 )
V_60 = V_61 ;
else
V_60 = V_62 ;
F_16 ( V_60 , 0x1 ) ;
F_19 ( V_38 , V_59 ) ;
}
static inline void F_21 ( unsigned long V_36 , unsigned long V_37 ,
unsigned long V_17 , const int V_38 )
{
unsigned long V_63 ;
unsigned int V_59 ;
F_22 ( V_63 ) ;
V_59 = F_17 ( V_38 ) ;
F_13 ( V_36 , V_37 , V_17 , V_38 ) ;
F_19 ( V_38 , V_59 ) ;
F_23 ( V_63 ) ;
}
static inline void F_24 ( void )
{
F_16 ( V_64 , 1 ) ;
F_18 ( V_65 ) ;
}
static inline void
F_25 ( unsigned long V_36 , unsigned long V_37 ,
unsigned long V_17 )
{
unsigned long V_63 ;
F_22 ( V_63 ) ;
F_13 ( V_36 , V_37 , V_17 , V_43 ) ;
F_23 ( V_63 ) ;
}
static void F_26 ( void * V_66 )
{
struct V_67 * V_68 = V_66 ;
F_25 ( V_68 -> V_36 , V_68 -> V_37 , V_68 -> V_17 ) ;
}
static void F_27 ( unsigned long V_36 , unsigned long V_37 ,
unsigned long V_17 )
{
struct V_67 V_68 = {
. V_36 = V_36 ,
. V_37 = V_37 ,
. V_17 = V_17
} ;
F_28 ( F_26 , & V_68 , 1 ) ;
}
void F_29 ( struct V_69 * V_69 )
{
struct V_70 * V_71 ;
if ( ! F_30 () ) {
F_31 ( V_72 , & V_69 -> V_63 ) ;
return;
}
V_71 = F_32 ( V_69 ) ;
if ( ! V_71 )
return;
if ( ! F_33 ( V_71 ) ) {
F_31 ( V_72 , & V_69 -> V_63 ) ;
} else if ( F_34 ( V_69 ) ) {
void * V_36 = F_35 ( V_69 ) ;
unsigned long V_37 = V_69 -> V_73 << V_74 ;
if ( F_36 ( V_36 , V_37 ) )
F_37 ( V_36 , V_37 ) ;
}
}
void F_38 ( unsigned long V_75 , unsigned long V_17 )
{
F_39 ( V_75 , V_17 , V_54 ) ;
}
void F_40 ( unsigned long V_75 , unsigned long V_17 )
{
F_39 ( V_75 , V_17 , V_46 ) ;
}
void F_41 ( unsigned long V_75 , unsigned long V_17 )
{
F_39 ( V_75 , V_17 , V_57 ) ;
}
void F_42 ( unsigned long V_76 , unsigned long V_77 )
{
unsigned int V_78 ;
F_43 ( V_76 < V_79 , L_9 , V_80 ) ;
V_78 = V_77 - V_76 ;
if ( V_78 > V_28 ) {
F_44 () ;
return;
}
if ( F_45 ( V_76 > V_81 ) ) {
F_46 ( V_76 , V_76 , V_77 - V_76 ) ;
return;
}
while ( V_78 > 0 ) {
unsigned int V_82 , V_17 ;
unsigned long V_83 , V_84 ;
V_82 = V_76 % V_28 ;
V_84 = F_47 ( ( void * ) V_76 ) ;
V_83 = ( V_84 << V_51 ) + V_82 ;
V_17 = F_48 (unsigned int, tot_sz, PAGE_SIZE - off) ;
F_46 ( V_83 , V_76 , V_17 ) ;
V_76 += V_17 ;
V_78 -= V_17 ;
}
}
void F_46 ( unsigned long V_36 , unsigned long V_37 , int V_3 )
{
F_21 ( V_36 , V_37 , V_3 , V_54 ) ;
F_27 ( V_36 , V_37 , V_3 ) ;
}
void F_49 ( unsigned long V_36 , unsigned long V_37 )
{
F_27 ( V_36 , V_37 , V_28 ) ;
}
void F_50 ( unsigned long V_36 , unsigned long V_37 )
{
F_21 ( V_36 , V_37 & V_85 , V_28 , V_54 ) ;
}
T_5 void F_44 ( void )
{
unsigned long V_63 ;
F_22 ( V_63 ) ;
F_24 () ;
F_20 ( V_54 ) ;
F_23 ( V_63 ) ;
}
void F_51 ( struct V_86 * V_87 )
{
F_44 () ;
}
void F_52 ( struct V_88 * V_89 , unsigned long V_90 ,
unsigned long V_84 )
{
unsigned int V_36 = V_84 << V_51 ;
V_90 &= V_85 ;
F_50 ( V_36 , V_90 ) ;
if ( V_89 -> V_91 & V_92 )
F_49 ( V_36 , V_90 ) ;
}
void F_53 ( struct V_88 * V_89 , unsigned long V_75 ,
unsigned long V_93 )
{
F_44 () ;
}
void F_54 ( struct V_88 * V_89 , struct V_69 * V_69 ,
unsigned long V_90 )
{
F_37 ( F_35 ( V_69 ) , V_90 ) ;
F_37 ( F_35 ( V_69 ) , F_35 ( V_69 ) ) ;
}
void F_55 ( struct V_69 * V_94 , struct V_69 * V_95 ,
unsigned long V_90 , struct V_88 * V_89 )
{
void * V_96 = F_35 ( V_95 ) ;
void * V_97 = F_35 ( V_94 ) ;
int V_98 = 0 ;
if ( F_34 ( V_95 ) && F_36 ( V_96 , V_90 ) ) {
F_37 ( V_96 , V_90 ) ;
V_98 = 1 ;
}
F_56 ( V_97 , V_96 ) ;
F_31 ( V_72 , & V_94 -> V_63 ) ;
if ( V_98 ) {
F_37 ( V_96 , V_96 ) ;
F_57 ( V_72 , & V_95 -> V_63 ) ;
} else {
F_31 ( V_72 , & V_95 -> V_63 ) ;
}
}
void F_58 ( void * V_94 , unsigned long V_90 , struct V_69 * V_69 )
{
F_59 ( V_94 ) ;
F_31 ( V_72 , & V_69 -> V_63 ) ;
}
