static inline T_1 F_1 ( void )
{
T_1 V_1 ;
asm volatile("stpt %0" : "=m" (timer));
return V_1 ;
}
static inline void F_2 ( T_1 V_2 )
{
T_1 V_1 ;
asm volatile(
" stpt %0\n"
" spt %1"
: "=m" (timer) : "m" (expires));
V_3 . V_4 += V_3 . V_5 - V_1 ;
V_3 . V_5 = V_2 ;
}
static inline int F_3 ( T_1 V_6 )
{
F_4 ( ! F_5 () ) ;
if ( F_6 ( & V_7 ) )
return 0 ;
V_6 = F_7 ( V_6 , & V_8 ) ;
return V_6 >= F_8 ( & V_9 ) ;
}
static void F_9 ( void )
{
T_1 V_10 [ 8 ] , * V_11 ;
T_1 V_12 , V_13 , V_14 , div ;
int V_15 ;
F_10 ( V_16 + 1 , V_10 ) ;
V_11 = F_11 ( V_17 ) ;
V_13 = 1 ;
V_14 = div = 0 ;
for ( V_15 = 0 ; V_15 <= V_16 ; V_15 ++ ) {
V_12 = V_10 [ V_15 ] - V_11 [ V_15 ] ;
div += V_12 ;
V_14 *= V_15 + 1 ;
V_14 += V_12 * V_13 ;
V_13 *= V_15 + 1 ;
}
div *= V_13 ;
if ( div > 0 ) {
F_12 ( V_18 , V_14 ) ;
F_12 ( V_19 , div ) ;
memcpy ( V_11 , V_10 ,
sizeof( T_1 ) * ( V_16 + 1 ) ) ;
}
F_12 ( V_20 , V_21 ) ;
}
static inline T_1 F_13 ( unsigned long * V_22 , T_1 V_23 )
{
T_1 V_12 ;
V_12 = V_23 - * V_22 ;
* V_22 = V_23 ;
return V_12 ;
}
static inline T_1 F_14 ( T_1 V_24 )
{
T_1 V_14 = F_15 ( V_18 ) ;
T_1 div = F_15 ( V_19 ) ;
if ( V_16 )
return V_24 * V_14 / div ;
return V_24 ;
}
static void F_16 ( struct V_25 * V_26 ,
T_1 V_27 , T_1 V_28 ,
enum V_29 V_30 )
{
V_26 -> V_31 += F_17 ( V_28 ) ;
F_18 ( V_26 , F_17 ( V_27 ) , V_30 ) ;
}
static int F_19 ( struct V_25 * V_32 )
{
T_1 V_1 , clock , V_33 , V_34 , system , V_35 , V_36 , V_37 ;
V_1 = V_3 . V_5 ;
clock = V_3 . V_38 ;
asm volatile(
" stpt %0\n"
#ifdef F_20
" stckf %1"
#else
" stck %1"
#endif
: "=m" (S390_lowcore.last_update_timer),
"=m" (S390_lowcore.last_update_clock));
clock = V_3 . V_38 - clock ;
V_1 -= V_3 . V_5 ;
if ( F_21 () )
V_3 . V_39 += V_1 ;
else
V_3 . V_4 += V_1 ;
if ( V_16 &&
F_22 ( V_21 , F_23 ( V_20 ) ) )
F_9 () ;
V_33 = F_13 ( & V_32 -> V_40 . V_41 ,
F_24 ( V_3 . V_41 ) ) ;
V_34 = F_13 ( & V_32 -> V_40 . V_42 ,
F_24 ( V_3 . V_42 ) ) ;
system = F_13 ( & V_32 -> V_40 . V_4 ,
F_24 ( V_3 . V_4 ) ) ;
V_35 = F_13 ( & V_32 -> V_40 . V_39 ,
F_24 ( V_3 . V_39 ) ) ;
V_36 = F_13 ( & V_32 -> V_40 . V_43 ,
F_24 ( V_3 . V_43 ) ) ;
V_3 . V_44 +=
clock - V_33 - V_34 - system - V_35 - V_36 ;
if ( V_33 ) {
F_25 ( V_32 , F_17 ( V_33 ) ) ;
V_32 -> V_45 += F_17 ( F_14 ( V_33 ) ) ;
}
if ( V_34 ) {
F_26 ( V_32 , F_17 ( V_34 ) ) ;
V_32 -> V_45 += F_17 ( F_14 ( V_34 ) ) ;
}
if ( system )
F_16 ( V_32 , system , F_14 ( system ) ,
V_46 ) ;
if ( V_35 )
F_16 ( V_32 , V_35 , F_14 ( V_35 ) ,
V_47 ) ;
if ( V_36 )
F_16 ( V_32 , V_36 , F_14 ( V_36 ) ,
V_48 ) ;
V_37 = V_3 . V_44 ;
if ( ( V_49 ) V_37 > 0 ) {
V_3 . V_44 = 0 ;
F_27 ( F_17 ( V_37 ) ) ;
}
return F_3 ( V_33 + V_34 + system + V_35 + V_36 ) ;
}
void F_28 ( struct V_25 * V_50 )
{
F_19 ( V_50 ) ;
V_50 -> V_40 . V_41 = V_3 . V_41 ;
V_50 -> V_40 . V_42 = V_3 . V_42 ;
V_50 -> V_40 . V_4 = V_3 . V_4 ;
V_50 -> V_40 . V_39 = V_3 . V_39 ;
V_50 -> V_40 . V_43 = V_3 . V_43 ;
V_3 . V_41 = V_51 -> V_40 . V_41 ;
V_3 . V_42 = V_51 -> V_40 . V_42 ;
V_3 . V_4 = V_51 -> V_40 . V_4 ;
V_3 . V_39 = V_51 -> V_40 . V_39 ;
V_3 . V_43 = V_51 -> V_40 . V_43 ;
}
void F_29 ( struct V_25 * V_32 )
{
if ( F_19 ( V_32 ) )
F_30 () ;
}
void F_31 ( struct V_25 * V_32 )
{
T_1 V_1 ;
V_1 = V_3 . V_5 ;
V_3 . V_5 = F_1 () ;
V_1 -= V_3 . V_5 ;
if ( ( V_32 -> V_52 & V_53 ) && ( F_32 () == 0 ) )
V_3 . V_42 += V_1 ;
else if ( F_21 () )
V_3 . V_39 += V_1 ;
else if ( F_33 () )
V_3 . V_43 += V_1 ;
else
V_3 . V_4 += V_1 ;
F_3 ( V_1 ) ;
}
static void F_34 ( struct V_54 * V_1 , struct V_55 * V_56 )
{
struct V_54 * V_57 ;
F_35 (tmp, head, entry) {
if ( V_57 -> V_2 > V_1 -> V_2 ) {
F_36 ( & V_1 -> V_58 , & V_57 -> V_58 ) ;
return;
}
}
F_36 ( & V_1 -> V_58 , V_56 ) ;
}
static void F_30 ( void )
{
struct V_54 * V_1 , * V_57 ;
unsigned long V_6 ;
F_37 ( V_59 ) ;
F_38 ( & V_60 ) ;
V_6 = F_8 ( & V_8 ) ;
F_39 (timer, tmp, &virt_timer_list, entry) {
if ( V_1 -> V_2 < V_6 )
F_40 ( & V_1 -> V_58 , & V_59 ) ;
else
V_1 -> V_2 -= V_6 ;
}
if ( ! F_6 ( & V_7 ) ) {
V_1 = F_41 ( & V_7 ,
struct V_54 , V_58 ) ;
F_42 ( & V_9 , V_1 -> V_2 ) ;
}
F_43 ( V_6 , & V_8 ) ;
F_44 ( & V_60 ) ;
F_39 (timer, tmp, &cb_list, entry) {
F_45 ( & V_1 -> V_58 ) ;
V_1 -> V_61 ( V_1 -> V_62 ) ;
if ( V_1 -> V_63 ) {
V_1 -> V_2 = V_1 -> V_63 +
F_8 ( & V_8 ) ;
F_38 ( & V_60 ) ;
F_34 ( V_1 , & V_7 ) ;
F_44 ( & V_60 ) ;
}
}
}
void F_46 ( struct V_54 * V_1 )
{
V_1 -> V_61 = NULL ;
F_47 ( & V_1 -> V_58 ) ;
}
static inline int F_48 ( struct V_54 * V_1 )
{
return ! F_6 ( & V_1 -> V_58 ) ;
}
static void F_49 ( struct V_54 * V_1 )
{
if ( F_6 ( & V_7 ) ) {
F_42 ( & V_9 , V_1 -> V_2 ) ;
F_42 ( & V_8 , 0 ) ;
F_50 ( & V_1 -> V_58 , & V_7 ) ;
} else {
V_1 -> V_2 += F_8 ( & V_8 ) ;
if ( F_51 ( ( V_49 ) V_1 -> V_2 <
( V_49 ) F_8 ( & V_9 ) ) )
F_42 ( & V_9 , V_1 -> V_2 ) ;
F_34 ( V_1 , & V_7 ) ;
}
}
static void F_52 ( struct V_54 * V_1 , int V_64 )
{
unsigned long V_52 ;
V_1 -> V_63 = V_64 ? V_1 -> V_2 : 0 ;
F_53 ( & V_60 , V_52 ) ;
F_49 ( V_1 ) ;
F_54 ( & V_60 , V_52 ) ;
}
void F_55 ( struct V_54 * V_1 )
{
F_52 ( V_1 , 0 ) ;
}
void F_56 ( struct V_54 * V_1 )
{
F_52 ( V_1 , 1 ) ;
}
static int F_57 ( struct V_54 * V_1 , T_1 V_2 , int V_64 )
{
unsigned long V_52 ;
int V_65 ;
F_4 ( ! V_1 -> V_61 ) ;
if ( V_1 -> V_2 == V_2 && F_48 ( V_1 ) )
return 1 ;
F_53 ( & V_60 , V_52 ) ;
V_65 = F_48 ( V_1 ) ;
if ( V_65 )
F_45 ( & V_1 -> V_58 ) ;
V_1 -> V_63 = V_64 ? V_2 : 0 ;
V_1 -> V_2 = V_2 ;
F_49 ( V_1 ) ;
F_54 ( & V_60 , V_52 ) ;
return V_65 ;
}
int F_58 ( struct V_54 * V_1 , T_1 V_2 )
{
return F_57 ( V_1 , V_2 , 0 ) ;
}
int F_59 ( struct V_54 * V_1 , T_1 V_2 )
{
return F_57 ( V_1 , V_2 , 1 ) ;
}
int F_60 ( struct V_54 * V_1 )
{
unsigned long V_52 ;
if ( ! F_48 ( V_1 ) )
return 0 ;
F_53 ( & V_60 , V_52 ) ;
F_45 ( & V_1 -> V_58 ) ;
F_54 ( & V_60 , V_52 ) ;
return 1 ;
}
void F_61 ( void )
{
F_2 ( V_66 ) ;
if ( V_16 ) {
F_12 ( V_20 , V_67 ) ;
F_12 ( V_18 , 1 ) ;
F_12 ( V_19 , 1 ) ;
F_10 ( V_16 + 1 , F_11 ( V_17 ) ) ;
}
}
