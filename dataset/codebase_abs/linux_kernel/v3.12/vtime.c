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
" stck %1"
: "=m" (S390_lowcore.last_update_timer),
"=m" (S390_lowcore.last_update_clock));
V_3 . V_4 += V_1 - V_3 . V_5 ;
V_3 . V_18 += V_3 . V_17 - clock ;
V_15 = V_3 . V_19 - V_14 -> V_19 ;
V_3 . V_18 -= V_15 ;
V_14 -> V_19 = V_3 . V_19 ;
F_11 ( V_11 , V_15 , V_15 ) ;
system = V_3 . V_4 - V_14 -> V_4 ;
V_3 . V_18 -= system ;
V_14 -> V_4 = V_3 . V_4 ;
F_12 ( V_11 , V_12 , system , system ) ;
V_16 = V_3 . V_18 ;
if ( ( V_20 ) V_16 > 0 ) {
V_3 . V_18 = 0 ;
F_13 ( V_16 ) ;
}
return F_3 ( V_15 + system ) ;
}
void F_14 ( struct V_10 * V_21 )
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
void F_15 ( struct V_10 * V_11 )
{
if ( F_9 ( V_11 , V_23 ) )
F_16 () ;
}
void F_17 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_10 ( V_11 ) ;
T_1 V_1 , system ;
F_18 ( ! F_5 () ) ;
V_1 = V_3 . V_5 ;
V_3 . V_5 = F_1 () ;
V_3 . V_4 += V_1 - V_3 . V_5 ;
system = V_3 . V_4 - V_14 -> V_4 ;
V_3 . V_18 -= system ;
V_14 -> V_4 = V_3 . V_4 ;
F_12 ( V_11 , 0 , system , system ) ;
F_3 ( system ) ;
}
void T_2 F_19 ( void )
{
struct V_24 * V_25 = & F_20 ( V_26 ) ;
unsigned long long V_27 ;
unsigned long V_28 ;
F_21 () ;
V_28 = V_29 | V_30 | V_31 |
V_32 | V_33 | V_34 ;
V_25 -> V_35 = 0 ;
F_22 ( V_25 , V_28 ) ;
V_25 -> V_36 ++ ;
F_23 () ;
V_27 = V_25 -> V_37 - V_25 -> V_38 ;
V_25 -> V_38 = V_25 -> V_37 = 0ULL ;
V_25 -> V_27 += V_27 ;
V_25 -> V_39 ++ ;
F_24 ( V_27 ) ;
F_23 () ;
V_25 -> V_36 ++ ;
}
T_3 F_25 ( int V_40 )
{
struct V_24 * V_25 = & F_26 ( V_26 , V_40 ) ;
unsigned long long V_41 , V_42 , V_43 ;
unsigned int V_36 ;
do {
V_41 = F_27 () ;
V_36 = F_28 ( V_25 -> V_36 ) ;
V_42 = F_28 ( V_25 -> V_38 ) ;
V_43 = F_28 ( V_25 -> V_37 ) ;
} while ( ( V_36 & 1 ) || ( V_25 -> V_36 != V_36 ) );
return V_42 ? ( ( V_43 ? : V_41 ) - V_42 ) : 0 ;
}
static void F_29 ( struct V_44 * V_1 , struct V_45 * V_46 )
{
struct V_44 * V_47 ;
F_30 (tmp, head, entry) {
if ( V_47 -> V_2 > V_1 -> V_2 ) {
F_31 ( & V_1 -> V_48 , & V_47 -> V_48 ) ;
return;
}
}
F_31 ( & V_1 -> V_48 , V_46 ) ;
}
static void F_16 ( void )
{
struct V_44 * V_1 , * V_47 ;
unsigned long V_6 ;
F_32 ( V_49 ) ;
F_33 ( & V_50 ) ;
V_6 = F_8 ( & V_8 ) ;
F_34 (timer, tmp, &virt_timer_list, entry) {
if ( V_1 -> V_2 < V_6 )
F_35 ( & V_1 -> V_48 , & V_49 ) ;
else
V_1 -> V_2 -= V_6 ;
}
if ( ! F_6 ( & V_7 ) ) {
V_1 = F_36 ( & V_7 ,
struct V_44 , V_48 ) ;
F_37 ( & V_9 , V_1 -> V_2 ) ;
}
F_38 ( V_6 , & V_8 ) ;
F_39 ( & V_50 ) ;
F_34 (timer, tmp, &cb_list, entry) {
F_40 ( & V_1 -> V_48 ) ;
V_1 -> V_51 ( V_1 -> V_52 ) ;
if ( V_1 -> V_53 ) {
V_1 -> V_2 = V_1 -> V_53 +
F_8 ( & V_8 ) ;
F_33 ( & V_50 ) ;
F_29 ( V_1 , & V_7 ) ;
F_39 ( & V_50 ) ;
}
}
}
void F_41 ( struct V_44 * V_1 )
{
V_1 -> V_51 = NULL ;
F_42 ( & V_1 -> V_48 ) ;
}
static inline int F_43 ( struct V_44 * V_1 )
{
return ! F_6 ( & V_1 -> V_48 ) ;
}
static void F_44 ( struct V_44 * V_1 )
{
if ( F_6 ( & V_7 ) ) {
F_37 ( & V_9 , V_1 -> V_2 ) ;
F_37 ( & V_8 , 0 ) ;
F_45 ( & V_1 -> V_48 , & V_7 ) ;
} else {
V_1 -> V_2 += F_8 ( & V_8 ) ;
if ( F_46 ( ( V_20 ) V_1 -> V_2 <
( V_20 ) F_8 ( & V_9 ) ) )
F_37 ( & V_9 , V_1 -> V_2 ) ;
F_29 ( V_1 , & V_7 ) ;
}
}
static void F_47 ( struct V_44 * V_1 , int V_54 )
{
unsigned long V_55 ;
V_1 -> V_53 = V_54 ? V_1 -> V_2 : 0 ;
F_48 ( & V_50 , V_55 ) ;
F_44 ( V_1 ) ;
F_49 ( & V_50 , V_55 ) ;
}
void F_50 ( struct V_44 * V_1 )
{
F_47 ( V_1 , 0 ) ;
}
void F_51 ( struct V_44 * V_1 )
{
F_47 ( V_1 , 1 ) ;
}
static int F_52 ( struct V_44 * V_1 , T_1 V_2 , int V_54 )
{
unsigned long V_55 ;
int V_56 ;
F_4 ( ! V_1 -> V_51 ) ;
if ( V_1 -> V_2 == V_2 && F_43 ( V_1 ) )
return 1 ;
F_48 ( & V_50 , V_55 ) ;
V_56 = F_43 ( V_1 ) ;
if ( V_56 )
F_40 ( & V_1 -> V_48 ) ;
V_1 -> V_53 = V_54 ? V_2 : 0 ;
V_1 -> V_2 = V_2 ;
F_44 ( V_1 ) ;
F_49 ( & V_50 , V_55 ) ;
return V_56 ;
}
int F_53 ( struct V_44 * V_1 , T_1 V_2 )
{
return F_52 ( V_1 , V_2 , 0 ) ;
}
int F_54 ( struct V_44 * V_1 , T_1 V_2 )
{
return F_52 ( V_1 , V_2 , 1 ) ;
}
int F_55 ( struct V_44 * V_1 )
{
unsigned long V_55 ;
if ( ! F_43 ( V_1 ) )
return 0 ;
F_48 ( & V_50 , V_55 ) ;
F_40 ( & V_1 -> V_48 ) ;
F_49 ( & V_50 , V_55 ) ;
return 1 ;
}
void F_56 ( void )
{
F_2 ( V_57 ) ;
}
static int F_57 ( struct V_58 * V_59 , unsigned long V_60 ,
void * V_61 )
{
struct V_24 * V_25 ;
long V_40 = ( long ) V_61 ;
V_25 = & F_26 ( V_26 , V_40 ) ;
switch ( V_60 & ~ V_62 ) {
case V_63 :
V_25 -> V_35 = 0 ;
default:
break;
}
return V_64 ;
}
void T_4 F_58 ( void )
{
F_56 () ;
F_59 ( F_57 , 0 ) ;
}
