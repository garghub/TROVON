static inline void F_1 ( void )
{
if ( F_2 ( V_1 ) ) {
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_1 = 0 ;
}
}
static inline T_1 F_3 ( void )
{
return F_4 () ;
}
static void F_5 ( T_1 V_3 , T_2 * V_4 )
{
unsigned V_5 = F_6 ( V_3 ) ;
F_1 () ;
if ( V_5 < V_6 )
V_4 [ V_5 ] ++ ;
else
V_4 [ V_6 ] ++ ;
}
static inline void F_7 ( T_1 V_7 )
{
T_2 V_3 = F_4 () - V_7 ;
F_5 ( V_3 , V_2 . V_8 ) ;
V_2 . V_9 += V_3 ;
}
static inline void F_8 ( T_1 V_7 )
{
T_2 V_3 = F_4 () - V_7 ;
F_5 ( V_3 , V_2 . V_10 ) ;
V_2 . V_11 += V_3 ;
}
static inline void F_9 ( T_1 V_7 )
{
T_2 V_3 = F_4 () - V_7 ;
F_5 ( V_3 , V_2 . V_12 ) ;
V_2 . V_13 += V_3 ;
}
static inline T_1 F_3 ( void )
{
return 0 ;
}
static inline void F_8 ( T_1 V_7 )
{
}
static inline void F_7 ( T_1 V_7 )
{
}
static inline void F_9 ( T_1 V_7 )
{
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
return V_17 -> V_15 != 0 ;
}
static int F_11 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
return V_17 -> V_18 != 0 ;
}
static int F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
T_3 V_19 = 1 ;
asm("xchgb %b0,%1"
: "+q" (old), "+m" (xl->lock) : : "memory");
return V_19 == 0 ;
}
static inline struct V_16 * F_13 ( struct V_16 * V_17 )
{
struct V_16 * V_20 ;
V_20 = F_14 ( V_21 ) ;
F_15 ( V_21 , V_17 ) ;
F_16 () ;
asm(LOCK_PREFIX " incw %0"
: "+m" (xl->spinners) : : "memory");
return V_20 ;
}
static inline void F_17 ( struct V_16 * V_17 , struct V_16 * V_20 )
{
asm(LOCK_PREFIX " decw %0"
: "+m" (xl->spinners) : : "memory");
F_16 () ;
F_15 ( V_21 , V_20 ) ;
}
static T_4 int F_18 ( struct V_14 * V_15 , bool V_22 )
{
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
struct V_16 * V_20 ;
int V_23 = F_14 ( V_24 ) ;
int V_25 ;
T_1 V_7 ;
if ( V_23 == - 1 )
return 0 ;
V_7 = F_3 () ;
V_20 = F_13 ( V_17 ) ;
F_19 ( V_26 , 1 ) ;
F_19 ( V_27 , V_20 != NULL ) ;
do {
unsigned long V_28 ;
F_20 ( V_23 ) ;
V_25 = F_12 ( V_15 ) ;
if ( V_25 ) {
F_19 ( V_29 , 1 ) ;
if ( V_20 != NULL )
F_21 ( V_23 ) ;
goto V_30;
}
V_28 = F_22 () ;
if ( V_22 ) {
F_19 ( V_31 , 1 ) ;
F_23 () ;
}
F_24 ( V_23 ) ;
F_25 ( V_28 ) ;
F_19 ( V_32 , ! F_26 ( V_23 ) ) ;
} while ( ! F_26 ( V_23 ) );
F_27 ( V_23 , F_28 ( V_23 ) ) ;
V_30:
F_17 ( V_17 , V_20 ) ;
F_9 ( V_7 ) ;
return V_25 ;
}
static inline void F_29 ( struct V_14 * V_15 , bool V_22 )
{
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
unsigned V_33 ;
T_3 V_34 ;
T_1 V_35 ;
F_19 ( V_36 , 1 ) ;
V_35 = F_3 () ;
do {
T_1 V_37 = F_3 () ;
V_33 = V_38 ;
asm("1: xchgb %1,%0\n"
" testb %1,%1\n"
" jz 3f\n"
"2: rep;nop\n"
" cmpb $0,%0\n"
" je 1b\n"
" dec %2\n"
" jnz 2b\n"
"3:\n"
: "+m" (xl->lock), "=q" (oldval), "+r" (timeout)
: "1" (1)
: "memory");
F_7 ( V_37 ) ;
} while ( F_2 ( V_34 != 0 &&
( V_38 == ~ 0 || ! F_18 ( V_15 , V_22 ) ) ) );
F_8 ( V_35 ) ;
}
static void F_30 ( struct V_14 * V_15 )
{
F_29 ( V_15 , false ) ;
}
static void F_31 ( struct V_14 * V_15 , unsigned long V_28 )
{
F_29 ( V_15 , ! F_32 ( V_28 ) ) ;
}
static T_4 void F_33 ( struct V_16 * V_17 )
{
int V_39 ;
F_19 ( V_40 , 1 ) ;
F_34 (cpu) {
if ( F_35 ( V_21 , V_39 ) == V_17 ) {
F_19 ( V_41 , 1 ) ;
F_36 ( V_39 , V_42 ) ;
break;
}
}
}
static void F_37 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = (struct V_16 * ) V_15 ;
F_19 ( V_43 , 1 ) ;
F_38 () ;
V_17 -> V_15 = 0 ;
F_39 () ;
if ( F_2 ( V_17 -> V_18 ) )
F_33 ( V_17 ) ;
}
static T_5 F_40 ( int V_23 , void * V_44 )
{
F_41 () ;
return V_45 ;
}
void T_6 F_42 ( int V_39 )
{
int V_23 ;
const char * V_46 ;
V_46 = F_43 ( V_47 , L_1 , V_39 ) ;
V_23 = F_44 ( V_42 ,
V_39 ,
F_40 ,
V_48 | V_49 | V_50 ,
V_46 ,
NULL ) ;
if ( V_23 >= 0 ) {
F_45 ( V_23 ) ;
F_35 ( V_24 , V_39 ) = V_23 ;
}
F_46 ( L_2 , V_39 , V_23 ) ;
}
void F_47 ( int V_39 )
{
F_48 ( F_35 ( V_24 , V_39 ) , NULL ) ;
}
void T_7 F_49 ( void )
{
V_51 . V_52 = F_10 ;
V_51 . V_53 = F_11 ;
V_51 . V_54 = F_30 ;
V_51 . V_55 = F_31 ;
V_51 . V_56 = F_12 ;
V_51 . V_57 = F_37 ;
}
static int T_7 F_50 ( void )
{
struct V_58 * V_59 = F_51 () ;
if ( V_59 == NULL )
return - V_60 ;
V_61 = F_52 ( L_3 , V_59 ) ;
F_53 ( L_4 , 0644 , V_61 , & V_1 ) ;
F_54 ( L_5 , 0644 , V_61 , & V_62 ) ;
F_55 ( L_6 , 0444 , V_61 , & V_2 . V_36 ) ;
F_54 ( L_7 , 0444 , V_61 ,
& V_2 . V_26 ) ;
F_54 ( L_8 , 0444 , V_61 ,
& V_2 . V_27 ) ;
F_54 ( L_9 , 0444 , V_61 ,
& V_2 . V_29 ) ;
F_54 ( L_10 , 0444 , V_61 ,
& V_2 . V_32 ) ;
F_54 ( L_11 , 0444 , V_61 ,
& V_2 . V_31 ) ;
F_55 ( L_12 , 0444 , V_61 , & V_2 . V_43 ) ;
F_54 ( L_13 , 0444 , V_61 ,
& V_2 . V_40 ) ;
F_54 ( L_14 , 0444 , V_61 ,
& V_2 . V_41 ) ;
F_55 ( L_15 , 0444 , V_61 ,
& V_2 . V_9 ) ;
F_55 ( L_16 , 0444 , V_61 ,
& V_2 . V_13 ) ;
F_55 ( L_17 , 0444 , V_61 ,
& V_2 . V_11 ) ;
F_56 ( L_18 , 0444 , V_61 ,
V_2 . V_10 , V_6 + 1 ) ;
F_56 ( L_19 , 0444 , V_61 ,
V_2 . V_8 , V_6 + 1 ) ;
F_56 ( L_20 , 0444 , V_61 ,
V_2 . V_12 , V_6 + 1 ) ;
return 0 ;
}
