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
static void F_16 ( struct V_25 * V_26 , T_1 V_27 ,
enum V_28 V_29 )
{
V_26 -> V_30 += F_17 ( F_14 ( V_27 ) ) ;
F_18 ( V_26 , F_17 ( V_27 ) , V_29 ) ;
}
static int F_19 ( struct V_25 * V_31 )
{
T_1 V_1 , clock , V_32 , V_33 , system , V_34 , V_35 , V_36 ;
V_1 = V_3 . V_5 ;
clock = V_3 . V_37 ;
asm volatile(
" stpt %0\n"
#ifdef F_20
" stckf %1"
#else
" stck %1"
#endif
: "=m" (S390_lowcore.last_update_timer),
"=m" (S390_lowcore.last_update_clock));
clock = V_3 . V_37 - clock ;
V_1 -= V_3 . V_5 ;
if ( F_21 () )
V_3 . V_38 += V_1 ;
else
V_3 . V_4 += V_1 ;
if ( V_16 &&
F_22 ( V_21 , F_23 ( V_20 ) ) )
F_9 () ;
V_32 = F_13 ( & V_31 -> V_39 . V_40 ,
F_24 ( V_3 . V_40 ) ) ;
V_33 = F_13 ( & V_31 -> V_39 . V_41 ,
F_24 ( V_3 . V_41 ) ) ;
system = F_13 ( & V_31 -> V_39 . V_4 ,
F_24 ( V_3 . V_4 ) ) ;
V_34 = F_13 ( & V_31 -> V_39 . V_38 ,
F_24 ( V_3 . V_38 ) ) ;
V_35 = F_13 ( & V_31 -> V_39 . V_42 ,
F_24 ( V_3 . V_42 ) ) ;
V_3 . V_43 +=
clock - V_32 - V_33 - system - V_34 - V_35 ;
if ( V_32 ) {
F_25 ( V_31 , F_17 ( V_32 ) ) ;
V_31 -> V_44 += F_17 ( F_14 ( V_32 ) ) ;
}
if ( V_33 ) {
F_26 ( V_31 , F_17 ( V_33 ) ) ;
V_31 -> V_44 += F_17 ( F_14 ( V_33 ) ) ;
}
if ( system )
F_16 ( V_31 , system , V_45 ) ;
if ( V_34 )
F_16 ( V_31 , V_34 , V_46 ) ;
if ( V_35 )
F_16 ( V_31 , V_35 , V_47 ) ;
V_36 = V_3 . V_43 ;
if ( ( V_48 ) V_36 > 0 ) {
V_3 . V_43 = 0 ;
F_27 ( F_17 ( V_36 ) ) ;
}
return F_3 ( V_32 + V_33 + system + V_34 + V_35 ) ;
}
void F_28 ( struct V_25 * V_49 )
{
F_19 ( V_49 ) ;
V_49 -> V_39 . V_40 = V_3 . V_40 ;
V_49 -> V_39 . V_41 = V_3 . V_41 ;
V_49 -> V_39 . V_4 = V_3 . V_4 ;
V_49 -> V_39 . V_38 = V_3 . V_38 ;
V_49 -> V_39 . V_42 = V_3 . V_42 ;
V_3 . V_40 = V_50 -> V_39 . V_40 ;
V_3 . V_41 = V_50 -> V_39 . V_41 ;
V_3 . V_4 = V_50 -> V_39 . V_4 ;
V_3 . V_38 = V_50 -> V_39 . V_38 ;
V_3 . V_42 = V_50 -> V_39 . V_42 ;
}
void F_29 ( struct V_25 * V_31 )
{
if ( F_19 ( V_31 ) )
F_30 () ;
}
void F_31 ( struct V_25 * V_31 )
{
T_1 V_1 ;
V_1 = V_3 . V_5 ;
V_3 . V_5 = F_1 () ;
V_1 -= V_3 . V_5 ;
if ( ( V_31 -> V_51 & V_52 ) && ( F_32 () == 0 ) )
V_3 . V_41 += V_1 ;
else if ( F_21 () )
V_3 . V_38 += V_1 ;
else if ( F_33 () )
V_3 . V_42 += V_1 ;
else
V_3 . V_4 += V_1 ;
F_3 ( V_1 ) ;
}
static void F_34 ( struct V_53 * V_1 , struct V_54 * V_55 )
{
struct V_53 * V_56 ;
F_35 (tmp, head, entry) {
if ( V_56 -> V_2 > V_1 -> V_2 ) {
F_36 ( & V_1 -> V_57 , & V_56 -> V_57 ) ;
return;
}
}
F_36 ( & V_1 -> V_57 , V_55 ) ;
}
static void F_30 ( void )
{
struct V_53 * V_1 , * V_56 ;
unsigned long V_6 ;
F_37 ( V_58 ) ;
F_38 ( & V_59 ) ;
V_6 = F_8 ( & V_8 ) ;
F_39 (timer, tmp, &virt_timer_list, entry) {
if ( V_1 -> V_2 < V_6 )
F_40 ( & V_1 -> V_57 , & V_58 ) ;
else
V_1 -> V_2 -= V_6 ;
}
if ( ! F_6 ( & V_7 ) ) {
V_1 = F_41 ( & V_7 ,
struct V_53 , V_57 ) ;
F_42 ( & V_9 , V_1 -> V_2 ) ;
}
F_43 ( V_6 , & V_8 ) ;
F_44 ( & V_59 ) ;
F_39 (timer, tmp, &cb_list, entry) {
F_45 ( & V_1 -> V_57 ) ;
V_1 -> V_60 ( V_1 -> V_61 ) ;
if ( V_1 -> V_62 ) {
V_1 -> V_2 = V_1 -> V_62 +
F_8 ( & V_8 ) ;
F_38 ( & V_59 ) ;
F_34 ( V_1 , & V_7 ) ;
F_44 ( & V_59 ) ;
}
}
}
void F_46 ( struct V_53 * V_1 )
{
V_1 -> V_60 = NULL ;
F_47 ( & V_1 -> V_57 ) ;
}
static inline int F_48 ( struct V_53 * V_1 )
{
return ! F_6 ( & V_1 -> V_57 ) ;
}
static void F_49 ( struct V_53 * V_1 )
{
if ( F_6 ( & V_7 ) ) {
F_42 ( & V_9 , V_1 -> V_2 ) ;
F_42 ( & V_8 , 0 ) ;
F_50 ( & V_1 -> V_57 , & V_7 ) ;
} else {
V_1 -> V_2 += F_8 ( & V_8 ) ;
if ( F_51 ( ( V_48 ) V_1 -> V_2 <
( V_48 ) F_8 ( & V_9 ) ) )
F_42 ( & V_9 , V_1 -> V_2 ) ;
F_34 ( V_1 , & V_7 ) ;
}
}
static void F_52 ( struct V_53 * V_1 , int V_63 )
{
unsigned long V_51 ;
V_1 -> V_62 = V_63 ? V_1 -> V_2 : 0 ;
F_53 ( & V_59 , V_51 ) ;
F_49 ( V_1 ) ;
F_54 ( & V_59 , V_51 ) ;
}
void F_55 ( struct V_53 * V_1 )
{
F_52 ( V_1 , 0 ) ;
}
void F_56 ( struct V_53 * V_1 )
{
F_52 ( V_1 , 1 ) ;
}
static int F_57 ( struct V_53 * V_1 , T_1 V_2 , int V_63 )
{
unsigned long V_51 ;
int V_64 ;
F_4 ( ! V_1 -> V_60 ) ;
if ( V_1 -> V_2 == V_2 && F_48 ( V_1 ) )
return 1 ;
F_53 ( & V_59 , V_51 ) ;
V_64 = F_48 ( V_1 ) ;
if ( V_64 )
F_45 ( & V_1 -> V_57 ) ;
V_1 -> V_62 = V_63 ? V_2 : 0 ;
V_1 -> V_2 = V_2 ;
F_49 ( V_1 ) ;
F_54 ( & V_59 , V_51 ) ;
return V_64 ;
}
int F_58 ( struct V_53 * V_1 , T_1 V_2 )
{
return F_57 ( V_1 , V_2 , 0 ) ;
}
int F_59 ( struct V_53 * V_1 , T_1 V_2 )
{
return F_57 ( V_1 , V_2 , 1 ) ;
}
int F_60 ( struct V_53 * V_1 )
{
unsigned long V_51 ;
if ( ! F_48 ( V_1 ) )
return 0 ;
F_53 ( & V_59 , V_51 ) ;
F_45 ( & V_1 -> V_57 ) ;
F_54 ( & V_59 , V_51 ) ;
return 1 ;
}
void F_61 ( void )
{
F_2 ( V_65 ) ;
if ( V_16 ) {
F_12 ( V_20 , V_66 ) ;
F_12 ( V_18 , 1 ) ;
F_12 ( V_19 , 1 ) ;
F_10 ( V_16 + 1 , F_11 ( V_17 ) ) ;
}
}
