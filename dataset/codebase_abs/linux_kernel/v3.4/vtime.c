static inline T_1 F_1 ( void )
{
T_1 V_1 ;
asm volatile("STPT %0" : "=m" (timer));
return V_1 ;
}
static inline void F_2 ( T_1 V_2 )
{
T_1 V_1 ;
asm volatile (" STPT %0\n"
" SPT %1"
: "=m" (timer) : "m" (expires) );
V_3 . V_4 += V_3 . V_5 - V_1 ;
V_3 . V_5 = V_2 ;
}
static void F_3 ( struct V_6 * V_7 , int V_8 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
T_1 V_1 , clock , V_11 , system , V_12 ;
V_1 = V_3 . V_5 ;
clock = V_3 . V_13 ;
asm volatile (" STPT %0\n"
" STCK %1"
: "=m" (S390_lowcore.last_update_timer),
"=m" (S390_lowcore.last_update_clock) );
V_3 . V_4 += V_1 - V_3 . V_5 ;
V_3 . V_14 += V_3 . V_13 - clock ;
V_11 = V_3 . V_15 - V_10 -> V_15 ;
V_3 . V_14 -= V_11 ;
V_10 -> V_15 = V_3 . V_15 ;
F_5 ( V_7 , V_11 , V_11 ) ;
system = V_3 . V_4 - V_10 -> V_4 ;
V_3 . V_14 -= system ;
V_10 -> V_4 = V_3 . V_4 ;
F_6 ( V_7 , V_8 , system , system ) ;
V_12 = V_3 . V_14 ;
if ( ( V_16 ) V_12 > 0 ) {
V_3 . V_14 = 0 ;
F_7 ( V_12 ) ;
}
}
void F_8 ( struct V_6 * V_17 , struct V_6 * V_18 )
{
struct V_9 * V_10 ;
F_3 ( V_17 , 0 ) ;
V_10 = F_4 ( V_17 ) ;
V_10 -> V_15 = V_3 . V_15 ;
V_10 -> V_4 = V_3 . V_4 ;
V_10 = F_4 ( V_18 ) ;
V_3 . V_15 = V_10 -> V_15 ;
V_3 . V_4 = V_10 -> V_4 ;
}
void F_9 ( struct V_6 * V_7 , int V_19 )
{
F_3 ( V_7 , V_20 ) ;
}
void F_10 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
T_1 V_1 , system ;
V_1 = V_3 . V_5 ;
V_3 . V_5 = F_1 () ;
V_3 . V_4 += V_1 - V_3 . V_5 ;
system = V_3 . V_4 - V_10 -> V_4 ;
V_3 . V_14 -= system ;
V_10 -> V_4 = V_3 . V_4 ;
F_6 ( V_7 , 0 , system , system ) ;
}
void T_2 F_11 ( void )
{
struct V_21 * V_22 = & F_12 ( V_23 ) ;
struct V_24 * V_25 = & F_12 ( V_26 ) ;
unsigned long long V_27 ;
unsigned long V_28 ;
F_13 () ;
F_14 () ;
V_28 = V_29 | V_30 | V_31 |
V_32 | V_33 | V_34 ;
V_22 -> V_35 = 0 ;
F_15 ( V_22 , V_25 , V_28 , ! F_16 ( & V_25 -> V_36 ) ) ;
F_17 () ;
V_22 -> V_37 ++ ;
F_18 () ;
V_27 = V_22 -> V_38 - V_22 -> V_39 ;
V_22 -> V_27 += V_27 ;
V_22 -> V_39 = V_22 -> V_38 = 0ULL ;
V_22 -> V_40 ++ ;
F_19 ( V_27 ) ;
F_18 () ;
V_22 -> V_37 ++ ;
}
T_3 F_20 ( int V_41 )
{
struct V_21 * V_22 = & F_21 ( V_23 , V_41 ) ;
unsigned long long V_42 , V_39 , V_38 ;
unsigned int V_37 ;
do {
V_42 = F_22 () ;
V_37 = F_23 ( V_22 -> V_37 ) ;
V_39 = F_23 ( V_22 -> V_39 ) ;
V_38 = F_23 ( V_22 -> V_38 ) ;
} while ( ( V_37 & 1 ) || ( V_22 -> V_37 != V_37 ) );
return V_39 ? ( ( V_38 ? : V_42 ) - V_39 ) : 0 ;
}
static void F_24 ( struct V_43 * V_1 , struct V_44 * V_45 )
{
struct V_43 * V_46 ;
F_25 (event, head, entry) {
if ( V_46 -> V_2 > V_1 -> V_2 ) {
F_26 ( & V_1 -> V_47 , & V_46 -> V_47 ) ;
return;
}
}
F_26 ( & V_1 -> V_47 , V_45 ) ;
}
static void F_27 ( struct V_44 * V_48 )
{
struct V_24 * V_25 ;
struct V_43 * V_46 , * V_49 ;
if ( F_16 ( V_48 ) )
return;
V_25 = & F_12 ( V_26 ) ;
F_28 (event, tmp, cb_list, entry) {
F_29 ( & V_46 -> V_47 ) ;
( V_46 -> V_50 ) ( V_46 -> V_51 ) ;
if ( V_46 -> V_52 ) {
V_46 -> V_2 = V_46 -> V_52 + V_25 -> V_53 ;
F_30 ( & V_25 -> V_54 ) ;
F_24 ( V_46 , & V_25 -> V_36 ) ;
F_31 ( & V_25 -> V_54 ) ;
}
}
}
static void F_32 ( struct V_55 V_55 ,
unsigned int V_56 , unsigned long V_57 )
{
struct V_24 * V_25 ;
struct V_43 * V_46 , * V_49 ;
struct V_44 V_48 ;
T_1 V_53 , V_18 ;
F_33 ( F_34 () ) . V_58 [ V_59 ] ++ ;
F_35 ( & V_48 ) ;
V_25 = & F_12 ( V_26 ) ;
F_30 ( & V_25 -> V_54 ) ;
V_53 = V_25 -> V_53 + ( V_25 -> V_1 - V_3 . V_60 ) ;
F_36 ( ( V_16 ) V_53 < 0 ) ;
V_25 -> V_53 = 0 ;
F_28 (event, tmp, &vq->list, entry) {
if ( V_46 -> V_2 < V_53 )
F_37 ( & V_46 -> V_47 , & V_48 ) ;
else
V_46 -> V_2 -= V_53 ;
}
F_31 ( & V_25 -> V_54 ) ;
F_27 ( & V_48 ) ;
V_18 = V_61 ;
F_30 ( & V_25 -> V_54 ) ;
if ( ! F_16 ( & V_25 -> V_36 ) ) {
V_46 = F_38 ( & V_25 -> V_36 , struct V_43 , V_47 ) ;
V_18 = V_46 -> V_2 ;
}
F_31 ( & V_25 -> V_54 ) ;
V_53 = V_3 . V_60 - F_1 () ;
F_2 ( V_18 - V_53 ) ;
V_25 -> V_1 = V_18 - V_53 ;
V_25 -> V_53 = V_53 ;
}
void F_39 ( struct V_43 * V_1 )
{
V_1 -> V_50 = NULL ;
F_35 ( & V_1 -> V_47 ) ;
}
static inline int F_40 ( struct V_43 * V_1 )
{
return ( ! F_16 ( & V_1 -> V_47 ) ) ;
}
static void F_41 ( struct V_43 * V_1 )
{
struct V_24 * V_25 ;
unsigned long V_62 ;
T_1 V_63 , V_2 ;
V_25 = & F_21 ( V_26 , V_1 -> V_41 ) ;
F_42 ( & V_25 -> V_54 , V_62 ) ;
F_36 ( V_1 -> V_41 != F_34 () ) ;
if ( F_16 ( & V_25 -> V_36 ) ) {
F_43 ( & V_1 -> V_47 , & V_25 -> V_36 ) ;
F_2 ( V_1 -> V_2 ) ;
V_25 -> V_1 = V_1 -> V_2 ;
V_25 -> V_53 = 0 ;
} else {
V_2 = V_1 -> V_2 ;
V_63 = F_1 () ;
if ( F_44 ( ( V_16 ) V_2 < ( V_16 ) V_63 ) ) {
F_2 ( V_2 ) ;
V_25 -> V_53 += V_25 -> V_1 - V_63 ;
V_25 -> V_1 = V_2 ;
} else {
V_25 -> V_53 += V_25 -> V_1 - V_63 ;
V_25 -> V_1 = V_63 ;
}
V_1 -> V_2 += V_25 -> V_53 ;
F_24 ( V_1 , & V_25 -> V_36 ) ;
}
F_45 ( & V_25 -> V_54 , V_62 ) ;
F_46 () ;
}
static inline void F_47 ( struct V_43 * V_1 )
{
F_36 ( ! V_1 -> V_50 ) ;
F_36 ( ! V_1 -> V_2 || V_1 -> V_2 > V_61 ) ;
F_36 ( F_40 ( V_1 ) ) ;
V_1 -> V_41 = F_48 () ;
}
void F_49 ( void * V_64 )
{
struct V_43 * V_1 ;
V_1 = (struct V_43 * ) V_64 ;
F_47 ( V_1 ) ;
V_1 -> V_52 = 0 ;
F_41 ( V_1 ) ;
}
void F_50 ( void * V_64 )
{
struct V_43 * V_1 ;
V_1 = (struct V_43 * ) V_64 ;
F_47 ( V_1 ) ;
V_1 -> V_52 = V_1 -> V_2 ;
F_41 ( V_1 ) ;
}
static int F_51 ( struct V_43 * V_1 , T_1 V_2 , int V_65 )
{
struct V_24 * V_25 ;
unsigned long V_62 ;
int V_41 ;
F_36 ( ! V_1 -> V_50 ) ;
F_36 ( ! V_2 || V_2 > V_61 ) ;
if ( V_1 -> V_2 == V_2 && F_40 ( V_1 ) )
return 1 ;
V_41 = F_48 () ;
V_25 = & F_21 ( V_26 , V_41 ) ;
F_42 ( & V_25 -> V_54 , V_62 ) ;
if ( ! F_40 ( V_1 ) ) {
F_45 ( & V_25 -> V_54 , V_62 ) ;
if ( V_65 )
V_1 -> V_52 = V_2 ;
else
V_1 -> V_52 = 0 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_41 = V_41 ;
F_41 ( V_1 ) ;
return 0 ;
}
F_36 ( V_1 -> V_41 != V_41 ) ;
F_29 ( & V_1 -> V_47 ) ;
V_1 -> V_2 = V_2 ;
if ( V_65 )
V_1 -> V_52 = V_2 ;
F_45 ( & V_25 -> V_54 , V_62 ) ;
F_41 ( V_1 ) ;
return 1 ;
}
int F_52 ( struct V_43 * V_1 , T_1 V_2 )
{
return F_51 ( V_1 , V_2 , 0 ) ;
}
int F_53 ( struct V_43 * V_1 , T_1 V_2 )
{
return F_51 ( V_1 , V_2 , 1 ) ;
}
int F_54 ( struct V_43 * V_1 )
{
unsigned long V_62 ;
struct V_24 * V_25 ;
if ( ! F_40 ( V_1 ) )
return 0 ;
V_25 = & F_21 ( V_26 , V_1 -> V_41 ) ;
F_42 ( & V_25 -> V_54 , V_62 ) ;
F_29 ( & V_1 -> V_47 ) ;
F_45 ( & V_25 -> V_54 , V_62 ) ;
return 1 ;
}
void F_55 ( void )
{
struct V_24 * V_25 ;
V_25 = & F_12 ( V_26 ) ;
F_35 ( & V_25 -> V_36 ) ;
F_56 ( & V_25 -> V_54 ) ;
F_57 ( 0 , 10 ) ;
F_2 ( 0x7fffffffffffffffULL ) ;
}
static int T_4 F_58 ( struct V_66 * V_67 ,
unsigned long V_68 , void * V_69 )
{
struct V_21 * V_22 ;
long V_41 = ( long ) V_69 ;
V_22 = & F_21 ( V_23 , V_41 ) ;
switch ( V_68 ) {
case V_70 :
case V_71 :
V_22 -> V_35 = 0 ;
default:
break;
}
return V_72 ;
}
void T_5 F_59 ( void )
{
if ( F_60 ( 0x1005 , F_32 ) )
F_61 ( L_1 ) ;
F_55 () ;
F_62 ( F_58 , 0 ) ;
}
