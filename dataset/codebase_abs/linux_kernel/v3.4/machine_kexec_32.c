static void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 V_4 ;
V_4 . V_5 = V_2 ;
V_4 . V_6 = ( unsigned long ) V_1 ;
F_2 ( & V_4 ) ;
}
static void F_3 ( void * V_7 , T_1 V_2 )
{
struct V_3 V_8 ;
V_8 . V_5 = V_2 ;
V_8 . V_6 = ( unsigned long ) V_7 ;
F_4 ( & V_8 ) ;
}
static void F_5 ( void )
{
#define F_6 ( T_2 ) #X
#define F_7 ( T_2 ) __STR(X)
__asm__ __volatile__ (
"\tljmp $"STR(__KERNEL_CS)",$1f\n"
"\t1:\n"
"\tmovl $"STR(__KERNEL_DS)",%%eax\n"
"\tmovl %%eax,%%ds\n"
"\tmovl %%eax,%%es\n"
"\tmovl %%eax,%%fs\n"
"\tmovl %%eax,%%gs\n"
"\tmovl %%eax,%%ss\n"
: : : "eax", "memory");
#undef F_7
#undef F_6
}
static void F_8 ( struct V_9 * V_10 )
{
F_9 ( ( unsigned long ) V_10 -> V_11 . V_12 ) ;
#ifdef F_10
F_9 ( ( unsigned long ) V_10 -> V_11 . V_13 ) ;
F_9 ( ( unsigned long ) V_10 -> V_11 . V_14 ) ;
#endif
F_9 ( ( unsigned long ) V_10 -> V_11 . V_15 ) ;
F_9 ( ( unsigned long ) V_10 -> V_11 . V_16 ) ;
}
static int F_11 ( struct V_9 * V_10 )
{
V_10 -> V_11 . V_12 = ( V_17 * ) F_12 ( V_18 ) ;
#ifdef F_10
V_10 -> V_11 . V_13 = ( V_19 * ) F_12 ( V_18 ) ;
V_10 -> V_11 . V_14 = ( V_19 * ) F_12 ( V_18 ) ;
#endif
V_10 -> V_11 . V_15 = ( V_20 * ) F_12 ( V_18 ) ;
V_10 -> V_11 . V_16 = ( V_20 * ) F_12 ( V_18 ) ;
if ( ! V_10 -> V_11 . V_12 ||
#ifdef F_10
! V_10 -> V_11 . V_13 || ! V_10 -> V_11 . V_14 ||
#endif
! V_10 -> V_11 . V_15 || ! V_10 -> V_11 . V_16 ) {
F_8 ( V_10 ) ;
return - V_21 ;
}
return 0 ;
}
static void F_13 (
V_17 * V_12 , V_19 * V_22 , V_20 * V_23 ,
unsigned long V_24 , unsigned long V_25 )
{
T_3 * V_26 ;
V_12 += F_14 ( V_24 ) ;
#ifdef F_10
if ( ! ( F_15 ( * V_12 ) & V_27 ) )
F_16 ( V_12 , F_17 ( F_18 ( V_22 ) | V_27 ) ) ;
#endif
V_26 = F_19 ( V_12 , V_24 ) ;
V_22 = F_20 ( V_26 , V_24 ) ;
if ( ! ( F_21 ( * V_22 ) & V_27 ) )
F_22 ( V_22 , F_23 ( F_18 ( V_23 ) | V_28 ) ) ;
V_23 = F_24 ( V_22 , V_24 ) ;
F_25 ( V_23 , F_26 ( V_25 >> V_29 , V_30 ) ) ;
}
static void F_27 ( struct V_9 * V_10 )
{
void * V_31 ;
V_19 * V_22 = NULL ;
V_31 = F_28 ( V_10 -> V_32 ) ;
#ifdef F_10
V_22 = V_10 -> V_11 . V_13 ;
#endif
F_13 (
V_10 -> V_11 . V_12 , V_22 , V_10 -> V_11 . V_15 ,
( unsigned long ) V_31 , F_18 ( V_31 ) ) ;
#ifdef F_10
V_22 = V_10 -> V_11 . V_14 ;
#endif
F_13 (
V_10 -> V_11 . V_12 , V_22 , V_10 -> V_11 . V_16 ,
F_18 ( V_31 ) , F_18 ( V_31 ) ) ;
}
int F_29 ( struct V_9 * V_10 )
{
int error ;
F_30 ( V_10 -> V_32 , 1 ) ;
error = F_11 ( V_10 ) ;
if ( error )
return error ;
F_27 ( V_10 ) ;
return 0 ;
}
void F_31 ( struct V_9 * V_10 )
{
F_32 ( V_10 -> V_32 , 1 ) ;
F_8 ( V_10 ) ;
}
void F_33 ( struct V_9 * V_10 )
{
unsigned long V_33 [ V_34 ] ;
void * V_31 ;
int V_35 ;
T_4 unsigned long
( * V_36 ) ( unsigned long V_37 ,
unsigned long V_31 ,
unsigned long V_38 ,
unsigned int V_39 ,
unsigned int V_40 ) ;
#ifdef F_34
if ( V_10 -> V_40 )
F_35 () ;
#endif
V_35 = F_36 () ;
F_37 () ;
F_38 () ;
if ( V_10 -> V_40 ) {
#ifdef F_39
F_40 () ;
#endif
}
V_31 = F_28 ( V_10 -> V_32 ) ;
memcpy ( V_31 , V_41 , V_42 ) ;
V_36 = V_31 ;
V_33 [ V_43 ] = F_18 ( V_31 ) ;
V_33 [ V_44 ] = ( unsigned long ) V_31 ;
V_33 [ V_45 ] = F_18 ( V_10 -> V_11 . V_12 ) ;
if ( V_10 -> type == V_46 )
V_33 [ V_47 ] = ( F_41 ( V_10 -> V_48 )
<< V_29 ) ;
F_5 () ;
F_3 ( F_42 ( 0 ) , 0 ) ;
F_1 ( F_42 ( 0 ) , 0 ) ;
V_10 -> V_49 = V_36 ( ( unsigned long ) V_10 -> V_50 ,
( unsigned long ) V_33 ,
V_10 -> V_49 , V_51 ,
V_10 -> V_40 ) ;
#ifdef F_34
if ( V_10 -> V_40 )
F_43 () ;
#endif
F_44 ( V_35 ) ;
}
void F_45 ( void )
{
#ifdef F_46
F_47 ( V_52 ) ;
F_48 ( V_52 , V_53 ) ;
#endif
#ifdef F_10
F_49 ( V_54 ) ;
#endif
}
