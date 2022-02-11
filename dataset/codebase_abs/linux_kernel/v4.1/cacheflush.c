static void F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
V_1 &= ~ ( V_4 . V_5 - 1 ) ;
V_2 += ( V_4 . V_5 - 1 ) ;
V_2 &= ~ ( V_4 . V_5 - 1 ) ;
for ( V_3 = V_1 ; V_3 < V_2 ; V_3 += V_4 . V_5 ) {
__asm__ __volatile__ (" flushda 0(%0)\n"
:
: "r"(addr)
);
}
}
static void F_2 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
V_1 &= ~ ( V_4 . V_5 - 1 ) ;
V_2 += ( V_4 . V_5 - 1 ) ;
V_2 &= ~ ( V_4 . V_5 - 1 ) ;
if ( V_2 > V_1 + V_4 . V_6 )
V_2 = V_1 + V_4 . V_6 ;
for ( V_3 = V_1 ; V_3 < V_2 ; V_3 += V_4 . V_5 ) {
__asm__ __volatile__ (" flushd 0(%0)\n"
:
: "r"(addr)
);
}
}
static void F_3 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
V_1 &= ~ ( V_4 . V_5 - 1 ) ;
V_2 += ( V_4 . V_5 - 1 ) ;
V_2 &= ~ ( V_4 . V_5 - 1 ) ;
for ( V_3 = V_1 ; V_3 < V_2 ; V_3 += V_4 . V_5 ) {
__asm__ __volatile__ (" initda 0(%0)\n"
:
: "r"(addr)
);
}
}
static void F_4 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
V_1 &= ~ ( V_4 . V_7 - 1 ) ;
V_2 += ( V_4 . V_7 - 1 ) ;
V_2 &= ~ ( V_4 . V_7 - 1 ) ;
if ( V_2 > V_1 + V_4 . V_8 )
V_2 = V_1 + V_4 . V_8 ;
for ( V_3 = V_1 ; V_3 < V_2 ; V_3 += V_4 . V_7 ) {
__asm__ __volatile__ (" flushi %0\n"
:
: "r"(addr)
);
}
T_1 V_9 ( L_1 ) ;
}
static void F_5 ( struct V_10 * V_11 , struct V_12 * V_12 )
{
struct V_13 * V_14 = V_15 -> V_16 ;
struct V_17 * V_18 ;
T_2 V_19 ;
V_19 = V_12 -> V_20 ;
F_6 ( V_11 ) ;
F_7 (mpnt, &mapping->i_mmap, pgoff, pgoff) {
unsigned long V_21 ;
if ( V_18 -> V_22 != V_14 )
continue;
if ( ! ( V_18 -> V_23 & V_24 ) )
continue;
V_21 = ( V_19 - V_18 -> V_25 ) << V_26 ;
F_8 ( V_18 , V_18 -> V_27 + V_21 ,
F_9 ( V_12 ) ) ;
}
F_10 ( V_11 ) ;
}
void F_11 ( void )
{
F_2 ( 0 , V_4 . V_6 ) ;
F_4 ( 0 , V_4 . V_8 ) ;
}
void F_12 ( struct V_13 * V_14 )
{
F_11 () ;
}
void F_13 ( struct V_13 * V_14 )
{
F_11 () ;
}
void F_14 ( unsigned long V_1 , unsigned long V_2 )
{
F_1 ( V_1 , V_2 ) ;
F_4 ( V_1 , V_2 ) ;
}
void F_15 ( unsigned long V_1 , unsigned long V_2 )
{
F_1 ( V_1 , V_2 ) ;
F_4 ( V_1 , V_2 ) ;
}
void F_16 ( unsigned long V_1 , unsigned long V_2 )
{
F_3 ( V_1 , V_2 ) ;
}
void F_17 ( struct V_17 * V_28 , unsigned long V_1 ,
unsigned long V_2 )
{
F_1 ( V_1 , V_2 ) ;
if ( V_28 == NULL || ( V_28 -> V_23 & V_29 ) )
F_4 ( V_1 , V_2 ) ;
}
void F_18 ( struct V_17 * V_28 , struct V_12 * V_12 )
{
unsigned long V_1 = ( unsigned long ) F_19 ( V_12 ) ;
unsigned long V_2 = V_1 + V_30 ;
F_1 ( V_1 , V_2 ) ;
F_4 ( V_1 , V_2 ) ;
}
void F_8 ( struct V_17 * V_28 , unsigned long V_31 ,
unsigned long V_32 )
{
unsigned long V_1 = V_31 ;
unsigned long V_2 = V_1 + V_30 ;
F_1 ( V_1 , V_2 ) ;
if ( V_28 -> V_23 & V_29 )
F_4 ( V_1 , V_2 ) ;
}
void F_20 ( struct V_10 * V_11 , struct V_12 * V_12 )
{
unsigned long V_1 = ( unsigned long ) F_19 ( V_12 ) ;
F_2 ( V_1 , V_1 + V_30 ) ;
}
void F_21 ( struct V_12 * V_12 )
{
struct V_10 * V_11 ;
if ( V_12 == F_22 ( 0 ) )
return;
V_11 = F_23 ( V_12 ) ;
if ( V_11 && ! F_24 ( V_11 ) ) {
F_25 ( V_33 , & V_12 -> V_34 ) ;
} else {
F_20 ( V_11 , V_12 ) ;
if ( V_11 ) {
unsigned long V_1 = ( unsigned long ) F_19 ( V_12 ) ;
F_5 ( V_11 , V_12 ) ;
F_14 ( V_1 , V_1 + V_30 ) ;
}
F_26 ( V_33 , & V_12 -> V_34 ) ;
}
}
void F_27 ( struct V_17 * V_28 ,
unsigned long V_35 , T_3 * V_36 )
{
unsigned long V_32 = F_28 ( * V_36 ) ;
struct V_12 * V_12 ;
struct V_10 * V_11 ;
if ( ! F_29 ( V_32 ) )
return;
V_12 = F_30 ( V_32 ) ;
if ( V_12 == F_22 ( 0 ) )
return;
V_11 = F_23 ( V_12 ) ;
if ( ! F_31 ( V_33 , & V_12 -> V_34 ) )
F_20 ( V_11 , V_12 ) ;
if( V_11 )
{
F_5 ( V_11 , V_12 ) ;
if ( V_28 -> V_23 & V_29 )
F_18 ( V_28 , V_12 ) ;
}
}
void F_32 ( void * V_37 , void * V_38 , unsigned long V_39 ,
struct V_12 * V_40 )
{
F_1 ( V_39 , V_39 + V_30 ) ;
F_4 ( V_39 , V_39 + V_30 ) ;
F_33 ( V_37 , V_38 ) ;
F_1 ( ( unsigned long ) V_37 , ( unsigned long ) V_37 + V_30 ) ;
F_4 ( ( unsigned long ) V_37 , ( unsigned long ) V_37 + V_30 ) ;
}
void F_34 ( void * V_3 , unsigned long V_39 , struct V_12 * V_12 )
{
F_1 ( V_39 , V_39 + V_30 ) ;
F_4 ( V_39 , V_39 + V_30 ) ;
F_35 ( V_3 ) ;
F_1 ( ( unsigned long ) V_3 , ( unsigned long ) V_3 + V_30 ) ;
F_4 ( ( unsigned long ) V_3 , ( unsigned long ) V_3 + V_30 ) ;
}
void F_36 ( struct V_17 * V_28 , struct V_12 * V_12 ,
unsigned long V_41 ,
void * V_42 , void * V_43 , int V_44 )
{
F_8 ( V_28 , V_41 , F_9 ( V_12 ) ) ;
memcpy ( V_42 , V_43 , V_44 ) ;
F_2 ( ( unsigned long ) V_43 , ( unsigned long ) V_43 + V_44 ) ;
if ( V_28 -> V_23 & V_29 )
F_4 ( ( unsigned long ) V_43 , ( unsigned long ) V_43 + V_44 ) ;
}
void F_37 ( struct V_17 * V_28 , struct V_12 * V_12 ,
unsigned long V_41 ,
void * V_42 , void * V_43 , int V_44 )
{
F_8 ( V_28 , V_41 , F_9 ( V_12 ) ) ;
memcpy ( V_42 , V_43 , V_44 ) ;
F_2 ( ( unsigned long ) V_42 , ( unsigned long ) V_42 + V_44 ) ;
if ( V_28 -> V_23 & V_29 )
F_4 ( ( unsigned long ) V_42 , ( unsigned long ) V_42 + V_44 ) ;
}
