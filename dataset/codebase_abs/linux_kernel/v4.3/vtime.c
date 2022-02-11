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
static int F_13 ( struct V_22 * V_23 , int V_24 )
{
struct V_25 * V_26 = F_14 ( V_23 ) ;
T_1 V_1 , clock , V_27 , system , V_28 ;
T_1 V_29 , V_30 ;
V_1 = V_3 . V_5 ;
clock = V_3 . V_31 ;
asm volatile(
" stpt %0\n"
#ifdef F_15
" stckf %1"
#else
" stck %1"
#endif
: "=m" (S390_lowcore.last_update_timer),
"=m" (S390_lowcore.last_update_clock));
V_3 . V_4 += V_1 - V_3 . V_5 ;
V_3 . V_32 += V_3 . V_31 - clock ;
if ( V_16 &&
F_16 ( V_21 , F_17 ( V_20 ) ) )
F_9 () ;
V_27 = V_3 . V_33 - V_26 -> V_33 ;
V_3 . V_32 -= V_27 ;
V_26 -> V_33 = V_3 . V_33 ;
system = V_3 . V_4 - V_26 -> V_4 ;
V_3 . V_32 -= system ;
V_26 -> V_4 = V_3 . V_4 ;
V_29 = V_27 ;
V_30 = system ;
if ( V_16 ) {
T_1 V_14 = F_18 ( V_18 ) ;
T_1 div = F_18 ( V_19 ) ;
V_29 = ( V_29 * V_14 ) / div ;
V_30 = ( V_30 * V_14 ) / div ;
}
F_19 ( V_23 , V_27 , V_29 ) ;
F_20 ( V_23 , V_24 , system , V_30 ) ;
V_28 = V_3 . V_32 ;
if ( ( V_34 ) V_28 > 0 ) {
V_3 . V_32 = 0 ;
F_21 ( V_28 ) ;
}
return F_3 ( V_27 + system ) ;
}
void F_22 ( struct V_22 * V_35 )
{
struct V_25 * V_26 ;
F_13 ( V_35 , 0 ) ;
V_26 = F_14 ( V_35 ) ;
V_26 -> V_33 = V_3 . V_33 ;
V_26 -> V_4 = V_3 . V_4 ;
V_26 = F_14 ( V_36 ) ;
V_3 . V_33 = V_26 -> V_33 ;
V_3 . V_4 = V_26 -> V_4 ;
}
void F_23 ( struct V_22 * V_23 )
{
if ( F_13 ( V_23 , V_37 ) )
F_24 () ;
}
void F_25 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_14 ( V_23 ) ;
T_1 V_1 , system , V_30 ;
V_1 = V_3 . V_5 ;
V_3 . V_5 = F_1 () ;
V_3 . V_4 += V_1 - V_3 . V_5 ;
if ( V_16 &&
F_16 ( V_21 , F_17 ( V_20 ) ) )
F_9 () ;
system = V_3 . V_4 - V_26 -> V_4 ;
V_3 . V_32 -= system ;
V_26 -> V_4 = V_3 . V_4 ;
V_30 = system ;
if ( V_16 ) {
T_1 V_14 = F_18 ( V_18 ) ;
T_1 div = F_18 ( V_19 ) ;
V_30 = ( V_30 * V_14 ) / div ;
}
F_20 ( V_23 , 0 , system , V_30 ) ;
F_3 ( system ) ;
}
static void F_26 ( struct V_38 * V_1 , struct V_39 * V_40 )
{
struct V_38 * V_41 ;
F_27 (tmp, head, entry) {
if ( V_41 -> V_2 > V_1 -> V_2 ) {
F_28 ( & V_1 -> V_42 , & V_41 -> V_42 ) ;
return;
}
}
F_28 ( & V_1 -> V_42 , V_40 ) ;
}
static void F_24 ( void )
{
struct V_38 * V_1 , * V_41 ;
unsigned long V_6 ;
F_29 ( V_43 ) ;
F_30 ( & V_44 ) ;
V_6 = F_8 ( & V_8 ) ;
F_31 (timer, tmp, &virt_timer_list, entry) {
if ( V_1 -> V_2 < V_6 )
F_32 ( & V_1 -> V_42 , & V_43 ) ;
else
V_1 -> V_2 -= V_6 ;
}
if ( ! F_6 ( & V_7 ) ) {
V_1 = F_33 ( & V_7 ,
struct V_38 , V_42 ) ;
F_34 ( & V_9 , V_1 -> V_2 ) ;
}
F_35 ( V_6 , & V_8 ) ;
F_36 ( & V_44 ) ;
F_31 (timer, tmp, &cb_list, entry) {
F_37 ( & V_1 -> V_42 ) ;
V_1 -> V_45 ( V_1 -> V_46 ) ;
if ( V_1 -> V_47 ) {
V_1 -> V_2 = V_1 -> V_47 +
F_8 ( & V_8 ) ;
F_30 ( & V_44 ) ;
F_26 ( V_1 , & V_7 ) ;
F_36 ( & V_44 ) ;
}
}
}
void F_38 ( struct V_38 * V_1 )
{
V_1 -> V_45 = NULL ;
F_39 ( & V_1 -> V_42 ) ;
}
static inline int F_40 ( struct V_38 * V_1 )
{
return ! F_6 ( & V_1 -> V_42 ) ;
}
static void F_41 ( struct V_38 * V_1 )
{
if ( F_6 ( & V_7 ) ) {
F_34 ( & V_9 , V_1 -> V_2 ) ;
F_34 ( & V_8 , 0 ) ;
F_42 ( & V_1 -> V_42 , & V_7 ) ;
} else {
V_1 -> V_2 += F_8 ( & V_8 ) ;
if ( F_43 ( ( V_34 ) V_1 -> V_2 <
( V_34 ) F_8 ( & V_9 ) ) )
F_34 ( & V_9 , V_1 -> V_2 ) ;
F_26 ( V_1 , & V_7 ) ;
}
}
static void F_44 ( struct V_38 * V_1 , int V_48 )
{
unsigned long V_49 ;
V_1 -> V_47 = V_48 ? V_1 -> V_2 : 0 ;
F_45 ( & V_44 , V_49 ) ;
F_41 ( V_1 ) ;
F_46 ( & V_44 , V_49 ) ;
}
void F_47 ( struct V_38 * V_1 )
{
F_44 ( V_1 , 0 ) ;
}
void F_48 ( struct V_38 * V_1 )
{
F_44 ( V_1 , 1 ) ;
}
static int F_49 ( struct V_38 * V_1 , T_1 V_2 , int V_48 )
{
unsigned long V_49 ;
int V_50 ;
F_4 ( ! V_1 -> V_45 ) ;
if ( V_1 -> V_2 == V_2 && F_40 ( V_1 ) )
return 1 ;
F_45 ( & V_44 , V_49 ) ;
V_50 = F_40 ( V_1 ) ;
if ( V_50 )
F_37 ( & V_1 -> V_42 ) ;
V_1 -> V_47 = V_48 ? V_2 : 0 ;
V_1 -> V_2 = V_2 ;
F_41 ( V_1 ) ;
F_46 ( & V_44 , V_49 ) ;
return V_50 ;
}
int F_50 ( struct V_38 * V_1 , T_1 V_2 )
{
return F_49 ( V_1 , V_2 , 0 ) ;
}
int F_51 ( struct V_38 * V_1 , T_1 V_2 )
{
return F_49 ( V_1 , V_2 , 1 ) ;
}
int F_52 ( struct V_38 * V_1 )
{
unsigned long V_49 ;
if ( ! F_40 ( V_1 ) )
return 0 ;
F_45 ( & V_44 , V_49 ) ;
F_37 ( & V_1 -> V_42 ) ;
F_46 ( & V_44 , V_49 ) ;
return 1 ;
}
void F_53 ( void )
{
F_2 ( V_51 ) ;
if ( V_16 ) {
F_12 ( V_20 , V_52 ) ;
F_12 ( V_18 , 1 ) ;
F_12 ( V_19 , 1 ) ;
F_10 ( V_16 + 1 , F_11 ( V_17 ) ) ;
}
}
