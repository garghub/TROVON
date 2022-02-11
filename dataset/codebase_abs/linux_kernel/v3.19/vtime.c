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
static int F_9 ( struct V_10 * V_11 , int V_12 )
{
struct V_13 * V_14 = F_10 ( V_11 ) ;
T_1 V_1 , clock , V_15 , system , V_16 ;
V_1 = V_3 . V_5 ;
clock = V_3 . V_17 ;
asm volatile(
" stpt %0\n"
#ifdef F_11
" stckf %1"
#else
" stck %1"
#endif
: "=m" (S390_lowcore.last_update_timer),
"=m" (S390_lowcore.last_update_clock));
V_3 . V_4 += V_1 - V_3 . V_5 ;
V_3 . V_18 += V_3 . V_17 - clock ;
V_15 = V_3 . V_19 - V_14 -> V_19 ;
V_3 . V_18 -= V_15 ;
V_14 -> V_19 = V_3 . V_19 ;
F_12 ( V_11 , V_15 , V_15 ) ;
system = V_3 . V_4 - V_14 -> V_4 ;
V_3 . V_18 -= system ;
V_14 -> V_4 = V_3 . V_4 ;
F_13 ( V_11 , V_12 , system , system ) ;
V_16 = V_3 . V_18 ;
if ( ( V_20 ) V_16 > 0 ) {
V_3 . V_18 = 0 ;
F_14 ( V_16 ) ;
}
return F_3 ( V_15 + system ) ;
}
void F_15 ( struct V_10 * V_21 )
{
struct V_13 * V_14 ;
F_9 ( V_21 , 0 ) ;
V_14 = F_10 ( V_21 ) ;
V_14 -> V_19 = V_3 . V_19 ;
V_14 -> V_4 = V_3 . V_4 ;
V_14 = F_10 ( V_22 ) ;
V_3 . V_19 = V_14 -> V_19 ;
V_3 . V_4 = V_14 -> V_4 ;
}
void F_16 ( struct V_10 * V_11 )
{
if ( F_9 ( V_11 , V_23 ) )
F_17 () ;
}
void F_18 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_10 ( V_11 ) ;
T_1 V_1 , system ;
V_1 = V_3 . V_5 ;
V_3 . V_5 = F_1 () ;
V_3 . V_4 += V_1 - V_3 . V_5 ;
system = V_3 . V_4 - V_14 -> V_4 ;
V_3 . V_18 -= system ;
V_14 -> V_4 = V_3 . V_4 ;
F_13 ( V_11 , 0 , system , system ) ;
F_3 ( system ) ;
}
static void F_19 ( struct V_24 * V_1 , struct V_25 * V_26 )
{
struct V_24 * V_27 ;
F_20 (tmp, head, entry) {
if ( V_27 -> V_2 > V_1 -> V_2 ) {
F_21 ( & V_1 -> V_28 , & V_27 -> V_28 ) ;
return;
}
}
F_21 ( & V_1 -> V_28 , V_26 ) ;
}
static void F_17 ( void )
{
struct V_24 * V_1 , * V_27 ;
unsigned long V_6 ;
F_22 ( V_29 ) ;
F_23 ( & V_30 ) ;
V_6 = F_8 ( & V_8 ) ;
F_24 (timer, tmp, &virt_timer_list, entry) {
if ( V_1 -> V_2 < V_6 )
F_25 ( & V_1 -> V_28 , & V_29 ) ;
else
V_1 -> V_2 -= V_6 ;
}
if ( ! F_6 ( & V_7 ) ) {
V_1 = F_26 ( & V_7 ,
struct V_24 , V_28 ) ;
F_27 ( & V_9 , V_1 -> V_2 ) ;
}
F_28 ( V_6 , & V_8 ) ;
F_29 ( & V_30 ) ;
F_24 (timer, tmp, &cb_list, entry) {
F_30 ( & V_1 -> V_28 ) ;
V_1 -> V_31 ( V_1 -> V_32 ) ;
if ( V_1 -> V_33 ) {
V_1 -> V_2 = V_1 -> V_33 +
F_8 ( & V_8 ) ;
F_23 ( & V_30 ) ;
F_19 ( V_1 , & V_7 ) ;
F_29 ( & V_30 ) ;
}
}
}
void F_31 ( struct V_24 * V_1 )
{
V_1 -> V_31 = NULL ;
F_32 ( & V_1 -> V_28 ) ;
}
static inline int F_33 ( struct V_24 * V_1 )
{
return ! F_6 ( & V_1 -> V_28 ) ;
}
static void F_34 ( struct V_24 * V_1 )
{
if ( F_6 ( & V_7 ) ) {
F_27 ( & V_9 , V_1 -> V_2 ) ;
F_27 ( & V_8 , 0 ) ;
F_35 ( & V_1 -> V_28 , & V_7 ) ;
} else {
V_1 -> V_2 += F_8 ( & V_8 ) ;
if ( F_36 ( ( V_20 ) V_1 -> V_2 <
( V_20 ) F_8 ( & V_9 ) ) )
F_27 ( & V_9 , V_1 -> V_2 ) ;
F_19 ( V_1 , & V_7 ) ;
}
}
static void F_37 ( struct V_24 * V_1 , int V_34 )
{
unsigned long V_35 ;
V_1 -> V_33 = V_34 ? V_1 -> V_2 : 0 ;
F_38 ( & V_30 , V_35 ) ;
F_34 ( V_1 ) ;
F_39 ( & V_30 , V_35 ) ;
}
void F_40 ( struct V_24 * V_1 )
{
F_37 ( V_1 , 0 ) ;
}
void F_41 ( struct V_24 * V_1 )
{
F_37 ( V_1 , 1 ) ;
}
static int F_42 ( struct V_24 * V_1 , T_1 V_2 , int V_34 )
{
unsigned long V_35 ;
int V_36 ;
F_4 ( ! V_1 -> V_31 ) ;
if ( V_1 -> V_2 == V_2 && F_33 ( V_1 ) )
return 1 ;
F_38 ( & V_30 , V_35 ) ;
V_36 = F_33 ( V_1 ) ;
if ( V_36 )
F_30 ( & V_1 -> V_28 ) ;
V_1 -> V_33 = V_34 ? V_2 : 0 ;
V_1 -> V_2 = V_2 ;
F_34 ( V_1 ) ;
F_39 ( & V_30 , V_35 ) ;
return V_36 ;
}
int F_43 ( struct V_24 * V_1 , T_1 V_2 )
{
return F_42 ( V_1 , V_2 , 0 ) ;
}
int F_44 ( struct V_24 * V_1 , T_1 V_2 )
{
return F_42 ( V_1 , V_2 , 1 ) ;
}
int F_45 ( struct V_24 * V_1 )
{
unsigned long V_35 ;
if ( ! F_33 ( V_1 ) )
return 0 ;
F_38 ( & V_30 , V_35 ) ;
F_30 ( & V_1 -> V_28 ) ;
F_39 ( & V_30 , V_35 ) ;
return 1 ;
}
void F_46 ( void )
{
F_2 ( V_37 ) ;
}
