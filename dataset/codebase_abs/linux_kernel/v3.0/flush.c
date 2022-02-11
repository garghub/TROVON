static void F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 = V_4 + ( F_2 ( V_2 ) << V_5 ) ;
const int V_6 = 0 ;
F_3 ( F_4 ( V_3 ) , F_5 ( V_1 , V_7 ) , 0 ) ;
F_6 ( V_3 ) ;
asm( "mcrr p15, 0, %1, %0, c14\n"
" mcr p15, 0, %2, c7, c10, 4"
:
: "r" (to), "r" (to + PAGE_SIZE - L1_CACHE_BYTES), "r" (zero)
: "cc");
}
static void F_7 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_8 )
{
unsigned long V_9 = F_2 ( V_2 ) ;
unsigned long V_10 = V_2 & ( V_11 - 1 ) ;
unsigned long V_3 ;
F_3 ( F_4 ( V_4 ) + V_9 , F_5 ( V_1 , V_7 ) , 0 ) ;
V_3 = V_4 + ( V_9 << V_5 ) + V_10 ;
F_6 ( V_3 ) ;
F_8 ( V_3 , V_3 + V_8 ) ;
}
void F_9 ( struct V_12 * V_13 )
{
if ( F_10 () ) {
F_11 ( V_13 ) ;
return;
}
if ( F_12 () ) {
asm( "mcr p15, 0, %0, c7, c14, 0\n"
" mcr p15, 0, %0, c7, c10, 4"
:
: "r" (0)
: "cc");
}
}
void F_13 ( struct V_14 * V_15 , unsigned long V_16 , unsigned long V_17 )
{
if ( F_10 () ) {
F_14 ( V_15 , V_16 , V_17 ) ;
return;
}
if ( F_12 () ) {
asm( "mcr p15, 0, %0, c7, c14, 0\n"
" mcr p15, 0, %0, c7, c10, 4"
:
: "r" (0)
: "cc");
}
if ( V_15 -> V_18 & V_19 )
F_15 () ;
}
void F_16 ( struct V_14 * V_15 , unsigned long V_20 , unsigned long V_1 )
{
if ( F_10 () ) {
F_17 ( V_15 , V_20 , V_1 ) ;
return;
}
if ( F_12 () ) {
F_1 ( V_1 , V_20 ) ;
F_15 () ;
}
if ( V_15 -> V_18 & V_19 && F_18 () )
F_15 () ;
}
static void F_19 ( void * args )
{
F_15 () ;
}
static
void F_20 ( struct V_14 * V_15 , struct V_21 * V_21 ,
unsigned long V_22 , void * V_23 , unsigned long V_8 )
{
if ( F_10 () ) {
if ( F_21 ( F_22 () , F_23 ( V_15 -> V_24 ) ) ) {
unsigned long V_25 = ( unsigned long ) V_23 ;
F_24 ( V_25 , V_25 + V_8 ) ;
}
return;
}
if ( F_12 () ) {
F_1 ( F_25 ( V_21 ) , V_22 ) ;
F_15 () ;
return;
}
if ( V_15 -> V_18 & V_19 ) {
unsigned long V_25 = ( unsigned long ) V_23 ;
if ( F_26 () )
F_7 ( F_25 ( V_21 ) , V_22 , V_8 ) ;
else
F_24 ( V_25 , V_25 + V_8 ) ;
if ( F_27 () )
F_28 ( F_19 ,
NULL , 1 ) ;
}
}
void F_29 ( struct V_14 * V_15 , struct V_21 * V_21 ,
unsigned long V_22 , void * V_26 , const void * V_27 ,
unsigned long V_8 )
{
#ifdef F_30
F_31 () ;
#endif
memcpy ( V_26 , V_27 , V_8 ) ;
F_20 ( V_15 , V_21 , V_22 , V_26 , V_8 ) ;
#ifdef F_30
F_32 () ;
#endif
}
void F_33 ( struct V_28 * V_29 , struct V_21 * V_21 )
{
if ( ! F_34 ( V_21 ) ) {
F_35 ( F_36 ( V_21 ) , V_11 ) ;
} else {
void * V_25 = F_37 ( V_21 ) ;
if ( V_25 ) {
F_35 ( V_25 , V_11 ) ;
F_38 ( V_21 ) ;
} else if ( F_39 () ) {
V_25 = F_40 ( V_21 ) ;
F_35 ( V_25 , V_11 ) ;
F_41 ( V_25 ) ;
}
}
if ( V_29 && F_12 () )
F_1 ( F_25 ( V_21 ) ,
V_21 -> V_30 << V_31 ) ;
}
static void F_42 ( struct V_28 * V_29 , struct V_21 * V_21 )
{
struct V_12 * V_13 = V_32 -> V_33 ;
struct V_14 * V_34 ;
struct V_35 V_36 ;
T_1 V_37 ;
V_37 = V_21 -> V_30 << ( V_31 - V_5 ) ;
F_43 ( V_29 ) ;
F_44 (mpnt, &iter, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_10 ;
if ( V_34 -> V_24 != V_13 )
continue;
if ( ! ( V_34 -> V_18 & V_38 ) )
continue;
V_10 = ( V_37 - V_34 -> V_39 ) << V_5 ;
F_16 ( V_34 , V_34 -> V_40 + V_10 , F_25 ( V_21 ) ) ;
}
F_45 ( V_29 ) ;
}
void F_46 ( T_2 V_41 )
{
unsigned long V_1 ;
struct V_21 * V_21 ;
struct V_28 * V_29 ;
if ( ! F_47 ( V_41 ) )
return;
if ( F_48 () && ! F_49 ( V_41 ) )
return;
V_1 = F_50 ( V_41 ) ;
if ( ! F_51 ( V_1 ) )
return;
V_21 = F_52 ( V_1 ) ;
if ( F_12 () )
V_29 = F_53 ( V_21 ) ;
else
V_29 = NULL ;
if ( ! F_54 ( V_42 , & V_21 -> V_43 ) )
F_33 ( V_29 , V_21 ) ;
if ( F_49 ( V_41 ) )
F_15 () ;
}
void F_55 ( struct V_21 * V_21 )
{
struct V_28 * V_29 ;
if ( V_21 == F_56 ( 0 ) )
return;
V_29 = F_53 ( V_21 ) ;
if ( ! F_27 () &&
V_29 && ! F_57 ( V_29 ) )
F_58 ( V_42 , & V_21 -> V_43 ) ;
else {
F_33 ( V_29 , V_21 ) ;
if ( V_29 && F_10 () )
F_42 ( V_29 , V_21 ) ;
else if ( V_29 )
F_15 () ;
F_59 ( V_42 , & V_21 -> V_43 ) ;
}
}
void F_60 ( struct V_14 * V_15 , struct V_21 * V_21 , unsigned long V_44 )
{
unsigned long V_1 ;
if ( F_48 () )
return;
V_1 = F_25 ( V_21 ) ;
if ( F_10 () ) {
F_16 ( V_15 , V_44 , V_1 ) ;
} else {
F_1 ( V_1 , V_44 ) ;
F_15 () ;
}
F_35 ( F_36 ( V_21 ) , V_11 ) ;
}
