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
void T_2 F_11 ( T_1 V_21 , T_1 V_22 )
{
struct V_23 * V_24 = & F_12 ( V_25 ) ;
struct V_26 * V_27 = & F_12 ( V_28 ) ;
T_1 V_29 , V_2 ;
if ( V_24 -> V_30 == 0ULL )
return;
V_29 = V_21 - V_24 -> V_30 ;
F_13 ( V_29 ) ;
V_3 . V_14 +=
V_24 -> V_30 - V_3 . V_13 ;
V_3 . V_13 = V_21 ;
V_3 . V_4 += V_3 . V_5 - V_27 -> V_24 ;
V_3 . V_5 = V_22 ;
if ( V_27 -> V_31 ) {
V_2 = V_27 -> V_24 - V_22 ;
V_2 += F_1 () ;
F_2 ( V_2 ) ;
} else {
V_27 -> V_32 -= V_27 -> V_24 - V_22 ;
}
V_24 -> V_33 ++ ;
F_14 () ;
V_24 -> V_29 += V_29 ;
V_24 -> V_30 = 0ULL ;
V_24 -> V_34 ++ ;
F_14 () ;
V_24 -> V_33 ++ ;
}
void T_2 F_15 ( void )
{
struct V_23 * V_24 = & F_12 ( V_25 ) ;
struct V_26 * V_27 = & F_12 ( V_28 ) ;
T_3 V_35 ;
V_35 . V_36 = V_37 | V_38 | V_39 | V_40 ;
V_24 -> V_41 = 0 ;
if ( V_27 -> V_31 ) {
T_1 V_42 = V_43 ;
asm volatile(
#ifndef F_16
" basr 1,0\n"
"0: ahi 1,1f-0b\n"
" st 1,4(%2)\n"
#else
" larl 1,1f\n"
" stg 1,8(%2)\n"
#endif
" stpt 0(%4)\n"
" spt 0(%5)\n"
" stck 0(%3)\n"
#ifndef F_16
" lpsw 0(%2)\n"
#else
" lpswe 0(%2)\n"
#endif
"1:"
: "=m" (idle->idle_enter), "=m" (vq->idle)
: "a" (&psw), "a" (&idle->idle_enter),
"a" (&vq->idle), "a" (&vmax), "m" (vmax), "m" (psw)
: "memory", "cc", "1");
} else {
asm volatile(
#ifndef F_16
" basr 1,0\n"
"0: ahi 1,1f-0b\n"
" st 1,4(%2)\n"
#else
" larl 1,1f\n"
" stg 1,8(%2)\n"
#endif
" stpt 0(%4)\n"
" stck 0(%3)\n"
#ifndef F_16
" lpsw 0(%2)\n"
#else
" lpswe 0(%2)\n"
#endif
"1:"
: "=m" (idle->idle_enter), "=m" (vq->idle)
: "a" (&psw), "a" (&idle->idle_enter),
"a" (&vq->idle), "m" (psw)
: "memory", "cc", "1");
}
}
T_4 F_17 ( int V_44 )
{
struct V_23 * V_24 ;
unsigned long long V_45 , V_29 , V_30 ;
unsigned int V_33 ;
V_24 = & F_18 ( V_25 , V_44 ) ;
V_45 = F_19 () ;
V_46:
V_33 = V_24 -> V_33 ;
F_20 () ;
if ( V_33 & 1 )
goto V_46;
V_29 = 0 ;
V_30 = V_24 -> V_30 ;
if ( V_30 != 0ULL && V_30 < V_45 )
V_29 = V_45 - V_30 ;
F_20 () ;
if ( V_24 -> V_33 != V_33 )
goto V_46;
return V_29 ;
}
static void F_21 ( struct V_47 * V_1 , struct V_48 * V_49 )
{
struct V_47 * V_50 ;
F_22 (event, head, entry) {
if ( V_50 -> V_2 > V_1 -> V_2 ) {
F_23 ( & V_1 -> V_51 , & V_50 -> V_51 ) ;
return;
}
}
F_23 ( & V_1 -> V_51 , V_49 ) ;
}
static void F_24 ( struct V_48 * V_52 )
{
struct V_26 * V_27 ;
struct V_47 * V_50 , * V_53 ;
if ( F_25 ( V_52 ) )
return;
V_27 = & F_12 ( V_28 ) ;
F_26 (event, tmp, cb_list, entry) {
F_27 ( & V_50 -> V_51 ) ;
( V_50 -> V_54 ) ( V_50 -> V_55 ) ;
if ( V_50 -> V_56 ) {
V_50 -> V_2 = V_50 -> V_56 + V_27 -> V_32 ;
F_28 ( & V_27 -> V_57 ) ;
F_21 ( V_50 , & V_27 -> V_58 ) ;
F_29 ( & V_27 -> V_57 ) ;
}
}
}
static void F_30 ( unsigned int V_59 ,
unsigned int V_60 , unsigned long V_61 )
{
struct V_26 * V_27 ;
struct V_47 * V_50 , * V_53 ;
struct V_48 V_52 ;
T_1 V_32 , V_18 ;
F_31 ( F_32 () ) . V_62 [ V_63 ] ++ ;
F_33 ( & V_52 ) ;
V_27 = & F_12 ( V_28 ) ;
F_28 ( & V_27 -> V_57 ) ;
V_32 = V_27 -> V_32 + ( V_27 -> V_1 - V_3 . V_64 ) ;
F_34 ( ( V_16 ) V_32 < 0 ) ;
V_27 -> V_32 = 0 ;
F_26 (event, tmp, &vq->list, entry) {
if ( V_50 -> V_2 < V_32 )
F_35 ( & V_50 -> V_51 , & V_52 ) ;
else
V_50 -> V_2 -= V_32 ;
}
F_29 ( & V_27 -> V_57 ) ;
V_27 -> V_31 = F_25 ( & V_52 ) ;
F_24 ( & V_52 ) ;
V_18 = V_43 ;
F_28 ( & V_27 -> V_57 ) ;
if ( ! F_25 ( & V_27 -> V_58 ) ) {
V_50 = F_36 ( & V_27 -> V_58 , struct V_47 , V_51 ) ;
V_18 = V_50 -> V_2 ;
} else
V_27 -> V_31 = 0 ;
F_29 ( & V_27 -> V_57 ) ;
V_32 = V_3 . V_64 - F_1 () ;
F_2 ( V_18 - V_32 ) ;
V_27 -> V_1 = V_18 - V_32 ;
V_27 -> V_32 = V_32 ;
}
void F_37 ( struct V_47 * V_1 )
{
V_1 -> V_54 = NULL ;
F_33 ( & V_1 -> V_51 ) ;
}
static inline int F_38 ( struct V_47 * V_1 )
{
return ( ! F_25 ( & V_1 -> V_51 ) ) ;
}
static void F_39 ( struct V_47 * V_1 )
{
struct V_26 * V_27 ;
unsigned long V_65 ;
T_1 V_66 , V_2 ;
V_27 = & F_18 ( V_28 , V_1 -> V_44 ) ;
F_40 ( & V_27 -> V_57 , V_65 ) ;
F_34 ( V_1 -> V_44 != F_32 () ) ;
if ( F_25 ( & V_27 -> V_58 ) ) {
F_41 ( & V_1 -> V_51 , & V_27 -> V_58 ) ;
F_2 ( V_1 -> V_2 ) ;
V_27 -> V_1 = V_1 -> V_2 ;
V_27 -> V_32 = 0 ;
} else {
V_2 = V_1 -> V_2 ;
V_66 = F_1 () ;
if ( F_42 ( ( V_16 ) V_2 < ( V_16 ) V_66 ) ) {
F_2 ( V_2 ) ;
V_27 -> V_32 += V_27 -> V_1 - V_66 ;
V_27 -> V_1 = V_2 ;
} else {
V_27 -> V_32 += V_27 -> V_1 - V_66 ;
V_27 -> V_1 = V_66 ;
}
V_1 -> V_2 += V_27 -> V_32 ;
F_21 ( V_1 , & V_27 -> V_58 ) ;
}
F_43 ( & V_27 -> V_57 , V_65 ) ;
F_44 () ;
}
static inline void F_45 ( struct V_47 * V_1 )
{
F_34 ( ! V_1 -> V_54 ) ;
F_34 ( ! V_1 -> V_2 || V_1 -> V_2 > V_43 ) ;
F_34 ( F_38 ( V_1 ) ) ;
V_1 -> V_44 = F_46 () ;
}
void F_47 ( void * V_67 )
{
struct V_47 * V_1 ;
V_1 = (struct V_47 * ) V_67 ;
F_45 ( V_1 ) ;
V_1 -> V_56 = 0 ;
F_39 ( V_1 ) ;
}
void F_48 ( void * V_67 )
{
struct V_47 * V_1 ;
V_1 = (struct V_47 * ) V_67 ;
F_45 ( V_1 ) ;
V_1 -> V_56 = V_1 -> V_2 ;
F_39 ( V_1 ) ;
}
int F_49 ( struct V_47 * V_1 , T_1 V_2 , int V_68 )
{
struct V_26 * V_27 ;
unsigned long V_65 ;
int V_44 ;
F_34 ( ! V_1 -> V_54 ) ;
F_34 ( ! V_2 || V_2 > V_43 ) ;
if ( V_1 -> V_2 == V_2 && F_38 ( V_1 ) )
return 1 ;
V_44 = F_46 () ;
V_27 = & F_18 ( V_28 , V_44 ) ;
F_40 ( & V_27 -> V_57 , V_65 ) ;
if ( ! F_38 ( V_1 ) ) {
F_43 ( & V_27 -> V_57 , V_65 ) ;
if ( V_68 )
V_1 -> V_56 = V_2 ;
else
V_1 -> V_56 = 0 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_44 = V_44 ;
F_39 ( V_1 ) ;
return 0 ;
}
F_34 ( V_1 -> V_44 != V_44 ) ;
F_27 ( & V_1 -> V_51 ) ;
V_1 -> V_2 = V_2 ;
if ( V_68 )
V_1 -> V_56 = V_2 ;
F_43 ( & V_27 -> V_57 , V_65 ) ;
F_39 ( V_1 ) ;
return 1 ;
}
int F_50 ( struct V_47 * V_1 , T_1 V_2 )
{
return F_49 ( V_1 , V_2 , 0 ) ;
}
int F_51 ( struct V_47 * V_1 , T_1 V_2 )
{
return F_49 ( V_1 , V_2 , 1 ) ;
}
int F_52 ( struct V_47 * V_1 )
{
unsigned long V_65 ;
struct V_26 * V_27 ;
if ( ! F_38 ( V_1 ) )
return 0 ;
V_27 = & F_18 ( V_28 , V_1 -> V_44 ) ;
F_40 ( & V_27 -> V_57 , V_65 ) ;
F_27 ( & V_1 -> V_51 ) ;
F_43 ( & V_27 -> V_57 , V_65 ) ;
return 1 ;
}
void F_53 ( void )
{
struct V_26 * V_27 ;
V_27 = & F_12 ( V_28 ) ;
F_33 ( & V_27 -> V_58 ) ;
F_54 ( & V_27 -> V_57 ) ;
F_55 ( 0 , 10 ) ;
}
static int T_5 F_56 ( struct V_69 * V_70 ,
unsigned long V_71 , void * V_72 )
{
struct V_23 * V_24 ;
long V_44 = ( long ) V_72 ;
V_24 = & F_18 ( V_25 , V_44 ) ;
switch ( V_71 ) {
case V_73 :
case V_74 :
V_24 -> V_41 = 0 ;
default:
break;
}
return V_75 ;
}
void T_6 F_57 ( void )
{
if ( F_58 ( 0x1005 , F_30 ) )
F_59 ( L_1 ) ;
F_53 () ;
F_60 ( F_56 , 0 ) ;
}
