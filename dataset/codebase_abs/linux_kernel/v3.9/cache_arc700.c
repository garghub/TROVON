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
char T_3 [ 256 ] ;
F_7 ( F_1 ( 0 , T_3 , sizeof( T_3 ) ) ) ;
if ( ! V_26 -> V_23 )
goto V_29;
#ifdef F_8
if ( ( V_26 -> V_20 != V_30 ) ||
( V_26 -> V_21 != V_31 ) ) {
F_9 ( L_3 ) ;
}
#if ( V_32 > 2 )
if ( V_26 -> V_23 != 3 ) {
if ( V_33 )
F_9 ( L_4 ) ;
F_10 ( L_5 ) ;
}
#endif
V_28 = V_26 -> V_22 / V_30 / V_34 ;
switch ( V_28 ) {
case 0 :
case 1 :
V_35 = V_36 ;
break;
case 2 :
V_35 = V_37 ;
break;
case 4 :
V_35 = V_38 ;
break;
default:
F_9 ( L_6 ) ;
}
#endif
V_25 = F_11 ( V_39 ) ;
#ifdef F_8
V_25 &= ~ V_40 ;
#else
V_25 |= V_40 ;
#endif
F_12 ( V_39 , V_25 ) ;
V_29:
if ( ! V_27 -> V_23 )
return;
#ifdef F_13
if ( ( V_27 -> V_20 != V_41 ) ||
( V_27 -> V_21 != V_42 ) ) {
F_9 ( L_3 ) ;
}
if ( ( V_27 -> V_22 / V_41 ) > V_34 )
F_9 ( L_7 ) ;
#endif
V_25 = F_11 ( V_43 ) ;
V_25 &= ~ V_44 ;
#ifdef F_13
F_12 ( V_43 , V_25 & ~ V_40 ) ;
#else
F_12 ( V_45 , 0x1 ) ;
F_12 ( V_43 , V_25 | V_40 ) ;
#endif
return;
}
static inline void F_14 ( void )
{
while ( F_11 ( V_43 ) & V_46 )
;
}
static inline void F_15 ( const int V_47 )
{
unsigned long V_48 , V_49 = V_49 ;
int V_50 ;
F_16 ( V_48 ) ;
if ( V_47 == V_51 ) {
V_49 = F_11 ( V_43 ) ;
F_12 ( V_43 , V_49 | V_44 ) ;
}
if ( V_47 & V_52 )
V_50 = V_53 ;
else
V_50 = V_45 ;
F_12 ( V_50 , 0x1 ) ;
if ( V_47 & V_54 )
F_14 () ;
if ( V_47 == V_51 )
F_12 ( V_43 , V_49 & ~ V_44 ) ;
F_17 ( V_48 ) ;
}
static inline void F_18 ( unsigned long V_55 , unsigned long V_22 ,
int V_56 )
{
int V_57 , V_58 ;
if ( ! ( F_19 ( V_22 ) && V_22 == V_34 ) ) {
V_58 = V_55 & ~ V_59 ;
V_22 += V_58 ;
V_55 -= V_58 ;
}
V_57 = F_20 ( V_22 , V_42 ) ;
while ( V_57 -- > 0 ) {
#if ( V_32 > 2 )
F_12 ( V_60 , V_55 ) ;
#endif
F_12 ( V_56 , V_55 ) ;
V_55 += V_42 ;
}
}
static inline void F_21 ( unsigned long V_55 , unsigned long V_22 ,
const int V_47 )
{
unsigned long V_48 , V_49 = V_49 ;
int V_50 ;
F_16 ( V_48 ) ;
if ( V_47 == V_51 ) {
V_49 = F_11 ( V_43 ) ;
F_12 ( V_43 , V_49 | V_44 ) ;
}
if ( V_47 & V_52 )
V_50 = V_61 ;
else
V_50 = V_62 ;
F_18 ( V_55 , V_22 , V_50 ) ;
if ( V_47 & V_54 )
F_14 () ;
if ( V_47 == V_51 )
F_12 ( V_43 , V_49 & ~ V_44 ) ;
F_17 ( V_48 ) ;
}
static void V_36 ( unsigned long V_55 , int V_57 )
{
while ( V_57 -- > 0 ) {
#if ( V_32 > 2 )
F_12 ( V_63 , V_55 ) ;
#endif
F_12 ( V_64 , V_55 ) ;
V_55 += V_31 ;
}
}
static void V_37 ( unsigned long V_55 , int V_57 )
{
while ( V_57 -- > 0 ) {
#if ( V_32 > 2 )
F_12 ( V_63 , V_55 ) ;
F_12 ( V_64 ,
V_55 & ~ ( 0x1 << V_65 ) ) ;
F_12 ( V_64 , V_55 | ( 0x1 << V_65 ) ) ;
#else
F_12 ( V_64 , V_55 ) ;
F_12 ( V_64 , V_55 | 0x01 ) ;
#endif
V_55 += V_31 ;
}
}
static void V_38 ( unsigned long V_55 , int V_57 )
{
while ( V_57 -- > 0 ) {
#if ( V_32 > 2 )
F_12 ( V_63 , V_55 ) ;
F_12 ( V_64 ,
V_55 & ~ ( 0x3 << V_65 ) ) ;
F_12 ( V_64 ,
V_55 & ~ ( 0x2 << V_65 ) ) ;
F_12 ( V_64 ,
V_55 & ~ ( 0x1 << V_65 ) ) ;
F_12 ( V_64 , V_55 | ( 0x3 << V_65 ) ) ;
#else
F_12 ( V_64 , V_55 ) ;
F_12 ( V_64 , V_55 | 0x01 ) ;
F_12 ( V_64 , V_55 | 0x02 ) ;
F_12 ( V_64 , V_55 | 0x03 ) ;
#endif
V_55 += V_31 ;
}
}
static void F_22 ( unsigned long V_55 , unsigned long V_22 )
{
unsigned long V_48 ;
int V_57 , V_58 ;
if ( ! ( F_19 ( V_22 ) && V_22 == V_34 ) ) {
V_58 = V_55 & ~ V_66 ;
V_22 += V_58 ;
V_55 -= V_58 ;
}
V_57 = F_20 ( V_22 , V_31 ) ;
F_16 ( V_48 ) ;
(* V_35) ( V_55 , V_57 ) ;
F_17 ( V_48 ) ;
}
static void F_23 ( unsigned long V_67 ,
unsigned long V_68 , unsigned long V_22 )
{
unsigned long V_48 ;
int V_57 , V_58 ;
unsigned int V_69 ;
V_58 = V_67 & ~ V_66 ;
V_22 += V_58 ;
V_67 -= V_58 ;
V_57 = F_20 ( V_22 , V_31 ) ;
#if ( V_32 > 2 )
V_68 &= ~ V_66 ;
V_69 = V_67 ;
#else
V_69 = V_67 | ( ( V_68 >> 13 ) & 0x1F ) ;
#endif
F_16 ( V_48 ) ;
while ( V_57 -- > 0 ) {
#if ( V_32 > 2 )
F_12 ( V_63 , V_69 ) ;
F_12 ( V_64 , V_68 ) ;
V_68 += V_31 ;
#else
F_12 ( V_64 , V_69 ) ;
#endif
V_69 += V_31 ;
}
F_17 ( V_48 ) ;
}
void F_24 ( struct V_70 * V_70 )
{
F_21 ( ( unsigned long ) F_25 ( V_70 ) , V_34 , V_54 ) ;
}
void F_26 ( unsigned long V_55 , unsigned long V_22 )
{
F_21 ( V_55 , V_22 , V_51 ) ;
}
void F_27 ( unsigned long V_55 , unsigned long V_22 )
{
F_21 ( V_55 , V_22 , V_52 ) ;
}
void F_28 ( unsigned long V_55 , unsigned long V_22 )
{
F_21 ( V_55 , V_22 , V_54 ) ;
}
void F_29 ( unsigned long V_71 , unsigned long V_72 )
{
unsigned int V_73 , V_74 , V_22 ;
unsigned long V_75 , V_76 ;
unsigned long V_48 ;
if ( V_71 < V_77 ) {
F_30 ( L_8 ) ;
return;
}
V_73 = V_72 - V_71 ;
if ( V_73 > V_34 ) {
F_31 () ;
return;
}
if ( F_32 ( V_71 > V_78 ) ) {
F_22 ( V_71 , V_72 - V_71 ) ;
F_21 ( V_71 , V_72 - V_71 , V_54 ) ;
return;
}
while ( V_73 > 0 ) {
V_74 = V_71 % V_34 ;
V_76 = F_33 ( ( void * ) V_71 ) ;
V_75 = ( V_76 << V_65 ) + V_74 ;
V_22 = F_34 (unsigned int, tot_sz, PAGE_SIZE - off) ;
F_16 ( V_48 ) ;
F_21 ( V_75 , V_22 , V_54 ) ;
F_22 ( V_75 , V_22 ) ;
F_17 ( V_48 ) ;
V_71 += V_22 ;
V_73 -= V_22 ;
}
}
void F_35 ( unsigned long V_79 , unsigned long V_80 ,
int V_3 )
{
F_23 ( V_79 , V_80 , V_3 ) ;
F_21 ( V_79 , V_3 , V_54 ) ;
}
void F_36 ( struct V_81 * V_82 , struct V_70 * V_70 )
{
if ( ! ( V_82 -> V_83 & V_84 ) )
return;
F_22 ( ( unsigned long ) F_25 ( V_70 ) , V_34 ) ;
}
void F_37 ( void )
{
unsigned long V_48 ;
F_16 ( V_48 ) ;
F_12 ( V_85 , 1 ) ;
F_11 ( V_39 ) ;
F_17 ( V_48 ) ;
}
T_5 void F_31 ( void )
{
unsigned long V_48 ;
F_16 ( V_48 ) ;
F_37 () ;
F_15 ( V_51 ) ;
F_17 ( V_48 ) ;
}
