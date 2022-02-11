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
void F_15 ( struct V_10 * V_11 , int V_23 )
{
if ( F_9 ( V_11 , V_24 ) )
F_16 () ;
}
void F_17 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_10 ( V_11 ) ;
T_1 V_1 , system ;
V_1 = V_3 . V_5 ;
V_3 . V_5 = F_1 () ;
V_3 . V_4 += V_1 - V_3 . V_5 ;
system = V_3 . V_4 - V_14 -> V_4 ;
V_3 . V_18 -= system ;
V_14 -> V_4 = V_3 . V_4 ;
F_12 ( V_11 , 0 , system , system ) ;
F_3 ( system ) ;
}
void T_2 F_18 ( void )
{
struct V_25 * V_26 = & F_19 ( V_27 ) ;
unsigned long long V_28 ;
unsigned long V_29 ;
F_20 () ;
F_21 () ;
V_29 = V_30 | V_31 | V_32 |
V_33 | V_34 | V_35 ;
V_26 -> V_36 = 0 ;
F_22 ( V_26 , V_29 ) ;
F_23 () ;
V_26 -> V_37 ++ ;
F_24 () ;
V_28 = V_26 -> V_38 - V_26 -> V_39 ;
V_26 -> V_39 = V_26 -> V_38 = 0ULL ;
V_26 -> V_28 += V_28 ;
V_26 -> V_40 ++ ;
F_25 ( V_28 ) ;
F_24 () ;
V_26 -> V_37 ++ ;
}
T_3 F_26 ( int V_41 )
{
struct V_25 * V_26 = & F_27 ( V_27 , V_41 ) ;
unsigned long long V_42 , V_43 , V_44 ;
unsigned int V_37 ;
do {
V_42 = F_28 () ;
V_37 = F_29 ( V_26 -> V_37 ) ;
V_43 = F_29 ( V_26 -> V_39 ) ;
V_44 = F_29 ( V_26 -> V_38 ) ;
} while ( ( V_37 & 1 ) || ( V_26 -> V_37 != V_37 ) );
return V_43 ? ( ( V_44 ? : V_42 ) - V_43 ) : 0 ;
}
static void F_30 ( struct V_45 * V_1 , struct V_46 * V_47 )
{
struct V_45 * V_48 ;
F_31 (tmp, head, entry) {
if ( V_48 -> V_2 > V_1 -> V_2 ) {
F_32 ( & V_1 -> V_49 , & V_48 -> V_49 ) ;
return;
}
}
F_32 ( & V_1 -> V_49 , V_47 ) ;
}
static void F_16 ( void )
{
struct V_45 * V_1 , * V_48 ;
unsigned long V_6 ;
F_33 ( V_50 ) ;
F_34 ( & V_51 ) ;
V_6 = F_8 ( & V_8 ) ;
F_35 (timer, tmp, &virt_timer_list, entry) {
if ( V_1 -> V_2 < V_6 )
F_36 ( & V_1 -> V_49 , & V_50 ) ;
else
V_1 -> V_2 -= V_6 ;
}
if ( ! F_6 ( & V_7 ) ) {
V_1 = F_37 ( & V_7 ,
struct V_45 , V_49 ) ;
F_38 ( & V_9 , V_1 -> V_2 ) ;
}
F_39 ( V_6 , & V_8 ) ;
F_40 ( & V_51 ) ;
F_35 (timer, tmp, &cb_list, entry) {
F_41 ( & V_1 -> V_49 ) ;
V_1 -> V_52 ( V_1 -> V_53 ) ;
if ( V_1 -> V_54 ) {
V_1 -> V_2 = V_1 -> V_54 +
F_8 ( & V_8 ) ;
F_34 ( & V_51 ) ;
F_30 ( V_1 , & V_7 ) ;
F_40 ( & V_51 ) ;
}
}
}
void F_42 ( struct V_45 * V_1 )
{
V_1 -> V_52 = NULL ;
F_43 ( & V_1 -> V_49 ) ;
}
static inline int F_44 ( struct V_45 * V_1 )
{
return ! F_6 ( & V_1 -> V_49 ) ;
}
static void F_45 ( struct V_45 * V_1 )
{
if ( F_6 ( & V_7 ) ) {
F_38 ( & V_9 , V_1 -> V_2 ) ;
F_38 ( & V_8 , 0 ) ;
F_46 ( & V_1 -> V_49 , & V_7 ) ;
} else {
V_1 -> V_2 += F_8 ( & V_8 ) ;
if ( F_47 ( ( V_20 ) V_1 -> V_2 <
( V_20 ) F_8 ( & V_9 ) ) )
F_38 ( & V_9 , V_1 -> V_2 ) ;
F_30 ( V_1 , & V_7 ) ;
}
}
static void F_48 ( struct V_45 * V_1 , int V_55 )
{
unsigned long V_56 ;
V_1 -> V_54 = V_55 ? V_1 -> V_2 : 0 ;
F_49 ( & V_51 , V_56 ) ;
F_45 ( V_1 ) ;
F_50 ( & V_51 , V_56 ) ;
}
void F_51 ( struct V_45 * V_1 )
{
F_48 ( V_1 , 0 ) ;
}
void F_52 ( struct V_45 * V_1 )
{
F_48 ( V_1 , 1 ) ;
}
static int F_53 ( struct V_45 * V_1 , T_1 V_2 , int V_55 )
{
unsigned long V_56 ;
int V_57 ;
F_4 ( ! V_1 -> V_52 ) ;
if ( V_1 -> V_2 == V_2 && F_44 ( V_1 ) )
return 1 ;
F_49 ( & V_51 , V_56 ) ;
V_57 = F_44 ( V_1 ) ;
if ( V_57 )
F_41 ( & V_1 -> V_49 ) ;
V_1 -> V_54 = V_55 ? V_2 : 0 ;
V_1 -> V_2 = V_2 ;
F_45 ( V_1 ) ;
F_50 ( & V_51 , V_56 ) ;
return V_57 ;
}
int F_54 ( struct V_45 * V_1 , T_1 V_2 )
{
return F_53 ( V_1 , V_2 , 0 ) ;
}
int F_55 ( struct V_45 * V_1 , T_1 V_2 )
{
return F_53 ( V_1 , V_2 , 1 ) ;
}
int F_56 ( struct V_45 * V_1 )
{
unsigned long V_56 ;
if ( ! F_44 ( V_1 ) )
return 0 ;
F_49 ( & V_51 , V_56 ) ;
F_41 ( & V_1 -> V_49 ) ;
F_50 ( & V_51 , V_56 ) ;
return 1 ;
}
void T_4 F_57 ( void )
{
F_2 ( V_58 ) ;
}
static int T_4 F_58 ( struct V_59 * V_60 ,
unsigned long V_61 , void * V_62 )
{
struct V_25 * V_26 ;
long V_41 = ( long ) V_62 ;
V_26 = & F_27 ( V_27 , V_41 ) ;
switch ( V_61 & ~ V_63 ) {
case V_64 :
V_26 -> V_36 = 0 ;
default:
break;
}
return V_65 ;
}
void T_5 F_59 ( void )
{
F_57 () ;
F_60 ( F_58 , 0 ) ;
}
