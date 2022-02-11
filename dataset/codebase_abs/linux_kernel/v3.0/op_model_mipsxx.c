static inline unsigned int F_1 ( void )
{
if ( F_2 () > 1 )
return 1 ;
return 0 ;
}
static inline unsigned int F_1 ( void )
{
return 0 ;
}
static inline unsigned int F_3 ( unsigned int V_1 )
{
return V_1 >> F_1 () ;
}
static inline unsigned int F_4 ( unsigned int V_1 )
{
return V_1 << F_1 () ;
}
static void F_5 ( struct V_2 * V_3 )
{
unsigned int V_1 = V_4 . V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_1 ; V_6 ++ ) {
V_7 . V_8 [ V_6 ] = 0 ;
V_7 . V_9 [ V_6 ] = 0 ;
if ( ! V_3 [ V_6 ] . V_10 )
continue;
V_7 . V_8 [ V_6 ] = F_6 ( V_3 [ V_6 ] . V_11 ) |
V_12 ;
if ( V_3 [ V_6 ] . V_13 )
V_7 . V_8 [ V_6 ] |= V_14 ;
if ( V_3 [ V_6 ] . V_15 )
V_7 . V_8 [ V_6 ] |= V_16 ;
if ( V_3 [ V_6 ] . V_17 )
V_7 . V_8 [ V_6 ] |= V_18 ;
V_7 . V_9 [ V_6 ] = 0x80000000 - V_3 [ V_6 ] . V_19 ;
}
}
static void F_7 ( void * args )
{
unsigned int V_1 = V_4 . V_5 ;
switch ( V_1 ) {
case 4 :
F_8 ( 0 ) ;
F_9 ( V_7 . V_9 [ 3 ] ) ;
case 3 :
F_10 ( 0 ) ;
F_11 ( V_7 . V_9 [ 2 ] ) ;
case 2 :
F_12 ( 0 ) ;
F_13 ( V_7 . V_9 [ 1 ] ) ;
case 1 :
F_14 ( 0 ) ;
F_15 ( V_7 . V_9 [ 0 ] ) ;
}
}
static void F_16 ( void * args )
{
unsigned int V_1 = V_4 . V_5 ;
switch ( V_1 ) {
case 4 :
F_8 ( V_20 | V_7 . V_8 [ 3 ] ) ;
case 3 :
F_10 ( V_20 | V_7 . V_8 [ 2 ] ) ;
case 2 :
F_12 ( V_20 | V_7 . V_8 [ 1 ] ) ;
case 1 :
F_14 ( V_20 | V_7 . V_8 [ 0 ] ) ;
}
}
static void F_17 ( void * args )
{
unsigned int V_1 = V_4 . V_5 ;
switch ( V_1 ) {
case 4 :
F_8 ( 0 ) ;
case 3 :
F_10 ( 0 ) ;
case 2 :
F_12 ( 0 ) ;
case 1 :
F_14 ( 0 ) ;
}
}
static int F_18 ( void )
{
unsigned int V_1 = V_4 . V_5 ;
unsigned int V_8 ;
unsigned int V_9 ;
int V_21 = V_22 ;
if ( V_23 && ! ( F_19 () & ( 1 << 26 ) ) )
return V_21 ;
switch ( V_1 ) {
#define F_20 ( T_1 ) \
case n + 1: \
control = r_c0_perfctrl ## n(); \
counter = r_c0_perfcntr ## n(); \
if ((control & M_PERFCTL_INTERRUPT_ENABLE) && \
(counter & M_COUNTER_OVERFLOW)) { \
oprofile_add_sample(get_irq_regs(), n); \
w_c0_perfcntr ## n(reg.counter[n]); \
handled = IRQ_HANDLED; \
}
F_20 ( 3 )
F_20 ( 2 )
F_20 ( 1 )
F_20 ( 0 )
}
return V_21 ;
}
static inline int F_21 ( void )
{
if ( ! ( F_22 () & V_24 ) )
return 0 ;
if ( ! ( F_23 () & V_25 ) )
return 1 ;
if ( ! ( F_24 () & V_25 ) )
return 2 ;
if ( ! ( F_25 () & V_25 ) )
return 3 ;
return 4 ;
}
static inline int F_26 ( void )
{
int V_1 ;
switch ( F_27 () ) {
case V_26 :
V_1 = 2 ;
break;
case V_27 :
case V_28 :
V_1 = 4 ;
break;
default:
V_1 = F_21 () ;
}
return V_1 ;
}
static void F_28 ( void * V_29 )
{
int V_1 = ( int ) ( long ) V_29 ;
switch ( V_1 ) {
case 4 :
F_8 ( 0 ) ;
F_9 ( 0 ) ;
case 3 :
F_10 ( 0 ) ;
F_11 ( 0 ) ;
case 2 :
F_12 ( 0 ) ;
F_13 ( 0 ) ;
case 1 :
F_14 ( 0 ) ;
F_15 ( 0 ) ;
}
}
static int T_2 F_29 ( void )
{
int V_1 ;
V_1 = F_26 () ;
if ( V_1 == 0 ) {
F_30 ( V_30 L_1 ) ;
return - V_31 ;
}
#ifdef F_31
V_32 = F_32 () & ( 1 << 19 ) ;
if ( ! V_32 )
V_1 = F_3 ( V_1 ) ;
#endif
F_33 ( F_28 , ( void * ) ( long ) V_1 , 1 ) ;
V_4 . V_5 = V_1 ;
switch ( F_27 () ) {
case V_33 :
V_4 . V_34 = L_2 ;
break;
case V_35 :
V_4 . V_34 = L_3 ;
break;
case V_36 :
V_4 . V_34 = L_4 ;
break;
case V_37 :
#if 0
op_model_mipsxx_ops.cpu_type = "mips/1004K";
break;
#endif
case V_38 :
V_4 . V_34 = L_5 ;
break;
case V_39 :
V_4 . V_34 = L_6 ;
break;
case V_40 :
V_4 . V_34 = L_7 ;
break;
case V_26 :
if ( ( V_41 . V_42 & 0xff ) == 0x20 )
V_4 . V_34 = L_8 ;
else
V_4 . V_34 = L_9 ;
break;
case V_27 :
case V_28 :
V_4 . V_34 = L_10 ;
break;
case V_43 :
case V_44 :
V_4 . V_34 = L_11 ;
break;
default:
F_30 ( V_30 L_12 ) ;
return - V_31 ;
}
V_45 = V_46 ;
V_46 = F_18 ;
return 0 ;
}
static void F_34 ( void )
{
int V_1 = V_4 . V_5 ;
V_1 = F_4 ( V_1 ) ;
F_33 ( F_28 , ( void * ) ( long ) V_1 , 1 ) ;
V_46 = V_45 ;
}
