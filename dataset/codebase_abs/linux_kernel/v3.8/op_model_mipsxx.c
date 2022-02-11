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
if ( F_7 () == V_19 )
V_7 . V_8 [ V_6 ] |= V_20 ;
V_7 . V_9 [ V_6 ] = 0x80000000 - V_3 [ V_6 ] . V_21 ;
}
}
static void F_8 ( void * args )
{
unsigned int V_1 = V_4 . V_5 ;
if ( F_9 ( F_10 () ) )
return;
switch ( V_1 ) {
case 4 :
F_11 ( 0 ) ;
F_12 ( V_7 . V_9 [ 3 ] ) ;
case 3 :
F_13 ( 0 ) ;
F_14 ( V_7 . V_9 [ 2 ] ) ;
case 2 :
F_15 ( 0 ) ;
F_16 ( V_7 . V_9 [ 1 ] ) ;
case 1 :
F_17 ( 0 ) ;
F_18 ( V_7 . V_9 [ 0 ] ) ;
}
}
static void F_19 ( void * args )
{
unsigned int V_1 = V_4 . V_5 ;
if ( F_9 ( F_10 () ) )
return;
switch ( V_1 ) {
case 4 :
F_11 ( V_22 | V_7 . V_8 [ 3 ] ) ;
case 3 :
F_13 ( V_22 | V_7 . V_8 [ 2 ] ) ;
case 2 :
F_15 ( V_22 | V_7 . V_8 [ 1 ] ) ;
case 1 :
F_17 ( V_22 | V_7 . V_8 [ 0 ] ) ;
}
}
static void F_20 ( void * args )
{
unsigned int V_1 = V_4 . V_5 ;
if ( F_9 ( F_10 () ) )
return;
switch ( V_1 ) {
case 4 :
F_11 ( 0 ) ;
case 3 :
F_13 ( 0 ) ;
case 2 :
F_15 ( 0 ) ;
case 1 :
F_17 ( 0 ) ;
}
}
static int F_21 ( void )
{
unsigned int V_1 = V_4 . V_5 ;
unsigned int V_8 ;
unsigned int V_9 ;
int V_23 = V_24 ;
if ( V_25 && ! ( F_22 () & ( 1 << 26 ) ) )
return V_23 ;
switch ( V_1 ) {
#define F_23 ( T_1 ) \
case n + 1: \
control = r_c0_perfctrl ## n(); \
counter = r_c0_perfcntr ## n(); \
if ((control & M_PERFCTL_INTERRUPT_ENABLE) && \
(counter & M_COUNTER_OVERFLOW)) { \
oprofile_add_sample(get_irq_regs(), n); \
w_c0_perfcntr ## n(reg.counter[n]); \
handled = IRQ_HANDLED; \
}
F_23 ( 3 )
F_23 ( 2 )
F_23 ( 1 )
F_23 ( 0 )
}
return V_23 ;
}
static inline int F_24 ( void )
{
if ( ! ( F_25 () & V_26 ) )
return 0 ;
if ( ! ( F_26 () & V_27 ) )
return 1 ;
if ( ! ( F_27 () & V_27 ) )
return 2 ;
if ( ! ( F_28 () & V_27 ) )
return 3 ;
return 4 ;
}
static inline int F_29 ( void )
{
int V_1 ;
switch ( F_7 () ) {
case V_28 :
V_1 = 2 ;
break;
case V_29 :
case V_30 :
V_1 = 4 ;
break;
default:
V_1 = F_24 () ;
}
return V_1 ;
}
static void F_30 ( void * V_31 )
{
int V_1 = ( int ) ( long ) V_31 ;
switch ( V_1 ) {
case 4 :
F_11 ( 0 ) ;
F_12 ( 0 ) ;
case 3 :
F_13 ( 0 ) ;
F_14 ( 0 ) ;
case 2 :
F_15 ( 0 ) ;
F_16 ( 0 ) ;
case 1 :
F_17 ( 0 ) ;
F_18 ( 0 ) ;
}
}
static T_2 F_31 ( int V_32 , void * V_33 )
{
return F_21 () ;
}
static int T_3 F_32 ( void )
{
int V_1 ;
V_1 = F_29 () ;
if ( V_1 == 0 ) {
F_33 ( V_34 L_1 ) ;
return - V_35 ;
}
#ifdef F_34
V_36 = F_35 () & ( 1 << 19 ) ;
if ( ! V_36 )
V_1 = F_3 ( V_1 ) ;
#endif
F_36 ( F_30 , ( void * ) ( long ) V_1 , 1 ) ;
V_4 . V_5 = V_1 ;
switch ( F_7 () ) {
case V_37 :
V_4 . V_38 = L_2 ;
break;
case V_39 :
V_4 . V_38 = L_3 ;
break;
case V_40 :
V_4 . V_38 = L_4 ;
break;
case V_41 :
V_4 . V_38 = L_5 ;
break;
case V_42 :
case V_43 :
V_4 . V_38 = L_6 ;
break;
case V_44 :
V_4 . V_38 = L_7 ;
break;
case V_45 :
V_4 . V_38 = L_8 ;
break;
case V_28 :
if ( ( V_46 . V_47 & 0xff ) == 0x20 )
V_4 . V_38 = L_9 ;
else
V_4 . V_38 = L_10 ;
break;
case V_29 :
case V_30 :
V_4 . V_38 = L_11 ;
break;
case V_48 :
case V_49 :
V_4 . V_38 = L_12 ;
break;
case V_50 :
V_4 . V_38 = L_13 ;
break;
case V_19 :
V_4 . V_38 = L_14 ;
break;
default:
F_33 ( V_34 L_15 ) ;
return - V_35 ;
}
V_51 = V_52 ;
V_52 = F_21 ;
if ( ( V_53 >= 0 ) && ( V_54 != V_53 ) )
return F_37 ( V_53 , F_31 ,
0 , L_16 , V_51 ) ;
return 0 ;
}
static void F_38 ( void )
{
int V_1 = V_4 . V_5 ;
if ( ( V_53 >= 0 ) && ( V_54 != V_53 ) )
F_39 ( V_53 , V_51 ) ;
V_1 = F_4 ( V_1 ) ;
F_36 ( F_30 , ( void * ) ( long ) V_1 , 1 ) ;
V_52 = V_51 ;
}
