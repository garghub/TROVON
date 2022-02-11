static void F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 = V_4 + ( F_2 ( V_2 ) << V_5 ) ;
const int V_6 = 0 ;
F_3 ( V_3 , F_4 ( V_1 , V_7 ) ) ;
asm( "mcrr p15, 0, %1, %0, c14\n"
" mcr p15, 0, %2, c7, c10, 4"
:
: "r" (to), "r" (to + PAGE_SIZE - L1_CACHE_BYTES), "r" (zero)
: "cc");
}
static void F_5 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_8 )
{
unsigned long V_9 = V_4 + ( F_2 ( V_2 ) << V_5 ) ;
unsigned long V_10 = V_2 & ( V_11 - 1 ) ;
unsigned long V_3 ;
F_3 ( V_9 , F_4 ( V_1 , V_7 ) ) ;
V_3 = V_9 + V_10 ;
F_6 ( V_3 , V_3 + V_8 ) ;
}
void F_7 ( struct V_12 * V_13 )
{
if ( F_8 () ) {
F_9 ( V_13 ) ;
return;
}
if ( F_10 () ) {
asm( "mcr p15, 0, %0, c7, c14, 0\n"
" mcr p15, 0, %0, c7, c10, 4"
:
: "r" (0)
: "cc");
}
}
void F_11 ( struct V_14 * V_15 , unsigned long V_16 , unsigned long V_17 )
{
if ( F_8 () ) {
F_12 ( V_15 , V_16 , V_17 ) ;
return;
}
if ( F_10 () ) {
asm( "mcr p15, 0, %0, c7, c14, 0\n"
" mcr p15, 0, %0, c7, c10, 4"
:
: "r" (0)
: "cc");
}
if ( V_15 -> V_18 & V_19 )
F_13 () ;
}
void F_14 ( struct V_14 * V_15 , unsigned long V_20 , unsigned long V_1 )
{
if ( F_8 () ) {
F_15 ( V_15 , V_20 , V_1 ) ;
return;
}
if ( F_10 () ) {
F_1 ( V_1 , V_20 ) ;
F_13 () ;
}
if ( V_15 -> V_18 & V_19 && F_16 () )
F_13 () ;
}
static void F_17 ( void * args )
{
F_13 () ;
}
static
void F_18 ( struct V_14 * V_15 , struct V_21 * V_21 ,
unsigned long V_22 , void * V_23 , unsigned long V_8 )
{
if ( F_8 () ) {
if ( F_19 ( F_20 () , F_21 ( V_15 -> V_24 ) ) ) {
unsigned long V_25 = ( unsigned long ) V_23 ;
F_22 ( V_25 , V_25 + V_8 ) ;
}
return;
}
if ( F_10 () ) {
F_1 ( F_23 ( V_21 ) , V_22 ) ;
F_13 () ;
return;
}
if ( V_15 -> V_18 & V_19 ) {
unsigned long V_25 = ( unsigned long ) V_23 ;
if ( F_24 () )
F_5 ( F_23 ( V_21 ) , V_22 , V_8 ) ;
else
F_22 ( V_25 , V_25 + V_8 ) ;
if ( F_25 () )
F_26 ( F_17 ,
NULL , 1 ) ;
}
}
void F_27 ( struct V_14 * V_15 , struct V_21 * V_21 ,
unsigned long V_22 , void * V_26 , const void * V_27 ,
unsigned long V_8 )
{
#ifdef F_28
F_29 () ;
#endif
memcpy ( V_26 , V_27 , V_8 ) ;
F_18 ( V_15 , V_21 , V_22 , V_26 , V_8 ) ;
#ifdef F_28
F_30 () ;
#endif
}
void F_31 ( struct V_28 * V_29 , struct V_21 * V_21 )
{
if ( ! F_32 ( V_21 ) ) {
F_33 ( F_34 ( V_21 ) , V_11 ) ;
} else {
void * V_25 = F_35 ( V_21 ) ;
if ( V_25 ) {
F_33 ( V_25 , V_11 ) ;
F_36 ( V_21 ) ;
} else if ( F_37 () ) {
V_25 = F_38 ( V_21 ) ;
F_33 ( V_25 , V_11 ) ;
F_39 ( V_25 ) ;
}
}
if ( V_29 && F_10 () )
F_1 ( F_23 ( V_21 ) ,
V_21 -> V_30 << V_31 ) ;
}
static void F_40 ( struct V_28 * V_29 , struct V_21 * V_21 )
{
struct V_12 * V_13 = V_32 -> V_33 ;
struct V_14 * V_34 ;
struct V_35 V_36 ;
T_1 V_37 ;
V_37 = V_21 -> V_30 << ( V_31 - V_5 ) ;
F_41 ( V_29 ) ;
F_42 (mpnt, &iter, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_10 ;
if ( V_34 -> V_24 != V_13 )
continue;
if ( ! ( V_34 -> V_18 & V_38 ) )
continue;
V_10 = ( V_37 - V_34 -> V_39 ) << V_5 ;
F_14 ( V_34 , V_34 -> V_40 + V_10 , F_23 ( V_21 ) ) ;
}
F_43 ( V_29 ) ;
}
void F_44 ( T_2 V_41 )
{
unsigned long V_1 ;
struct V_21 * V_21 ;
struct V_28 * V_29 ;
if ( F_45 () && ! F_46 ( V_41 ) )
return;
V_1 = F_47 ( V_41 ) ;
if ( ! F_48 ( V_1 ) )
return;
V_21 = F_49 ( V_1 ) ;
if ( F_10 () )
V_29 = F_50 ( V_21 ) ;
else
V_29 = NULL ;
if ( ! F_51 ( V_42 , & V_21 -> V_43 ) )
F_31 ( V_29 , V_21 ) ;
if ( F_46 ( V_41 ) )
F_13 () ;
}
void F_52 ( struct V_21 * V_21 )
{
struct V_28 * V_29 ;
if ( V_21 == F_53 ( 0 ) )
return;
V_29 = F_50 ( V_21 ) ;
if ( ! F_25 () &&
V_29 && ! F_54 ( V_29 ) )
F_55 ( V_42 , & V_21 -> V_43 ) ;
else {
F_31 ( V_29 , V_21 ) ;
if ( V_29 && F_8 () )
F_40 ( V_29 , V_21 ) ;
else if ( V_29 )
F_13 () ;
F_56 ( V_42 , & V_21 -> V_43 ) ;
}
}
void F_57 ( struct V_14 * V_15 , struct V_21 * V_21 , unsigned long V_44 )
{
unsigned long V_1 ;
if ( F_45 () )
return;
V_1 = F_23 ( V_21 ) ;
if ( F_8 () ) {
F_14 ( V_15 , V_44 , V_1 ) ;
} else {
F_1 ( V_1 , V_44 ) ;
F_13 () ;
}
F_33 ( F_34 ( V_21 ) , V_11 ) ;
}
