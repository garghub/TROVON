static int F_1 ( char * V_1 , char * V_2 )
{
return F_2 () ;
}
static inline T_1 F_3 ( int V_3 )
{
return F_4 ( V_4 , V_3 ) >> 16 ;
}
static void
F_5 ( const struct V_5 * V_6 , int V_7 , int V_8 )
{
struct V_5 * V_9 ;
struct V_5 * V_10 ;
unsigned int V_3 , V_11 ;
unsigned long V_12 ;
T_1 V_13 ;
F_6 () ;
F_7 ( V_12 ) ;
V_11 = F_8 () ;
V_10 = F_9 ( V_14 ) ;
F_10 ( V_10 , V_6 ) ;
F_11 (cpu, ipi_mask_ptr) {
unsigned long V_15 ;
V_9 = F_4 ( V_16 , V_3 ) ;
V_13 = 0 ;
F_12 (i, ipi_mask_ptr, cpus_in_cluster_ptr) {
if ( V_8 == V_17 || V_15 != V_11 )
V_13 |= F_4 ( V_4 , V_15 ) ;
}
if ( ! V_13 )
continue;
F_13 ( V_13 , V_7 , V_18 -> V_19 ) ;
F_14 ( V_10 , V_10 , V_9 ) ;
}
F_15 ( V_12 ) ;
}
static void F_16 ( const struct V_5 * V_6 , int V_7 )
{
F_5 ( V_6 , V_7 , V_17 ) ;
}
static void
F_17 ( const struct V_5 * V_6 , int V_7 )
{
F_5 ( V_6 , V_7 , V_20 ) ;
}
static void F_18 ( int V_7 )
{
F_5 ( V_21 , V_7 , V_20 ) ;
}
static void F_19 ( int V_7 )
{
F_5 ( V_21 , V_7 , V_17 ) ;
}
static unsigned int F_20 ( const struct V_5 * V_5 )
{
int V_3 = F_21 ( V_5 ) ;
if ( ( unsigned ) V_3 < V_22 )
return F_4 ( V_4 , V_3 ) ;
else
return V_23 ;
}
static unsigned int
F_22 ( const struct V_5 * V_5 ,
const struct V_5 * V_24 )
{
int V_3 ;
F_12 (cpu, cpumask, andmask) {
if ( F_23 ( V_3 , V_21 ) )
break;
}
return F_4 ( V_4 , V_3 ) ;
}
static void F_24 ( void )
{
unsigned int V_11 = F_8 () ;
unsigned int V_3 ;
F_4 ( V_4 , V_11 ) = F_25 ( V_25 ) ;
F_26 ( V_11 , F_4 ( V_16 , V_11 ) ) ;
F_27 (cpu) {
if ( F_3 ( V_11 ) != F_3 ( V_3 ) )
continue;
F_26 ( V_11 , F_4 ( V_16 , V_3 ) ) ;
F_26 ( V_3 , F_4 ( V_16 , V_11 ) ) ;
}
}
static int T_2
F_28 ( struct V_26 * V_27 , unsigned long V_28 , void * V_29 )
{
unsigned int V_11 = ( unsigned long ) V_29 ;
unsigned int V_3 ;
int V_30 = 0 ;
switch ( V_28 ) {
case V_31 :
if ( ! F_29 ( & F_4 ( V_16 , V_11 ) ,
V_32 ) ) {
V_30 = - V_33 ;
} else if ( ! F_29 ( & F_4 ( V_14 , V_11 ) ,
V_32 ) ) {
F_30 ( F_4 ( V_16 , V_11 ) ) ;
V_30 = - V_33 ;
}
break;
case V_34 :
case V_35 :
case V_36 :
F_27 (cpu) {
if ( F_3 ( V_11 ) != F_3 ( V_3 ) )
continue;
F_31 ( V_11 , F_4 ( V_16 , V_3 ) ) ;
F_31 ( V_3 , F_4 ( V_16 , V_11 ) ) ;
}
F_30 ( F_4 ( V_16 , V_11 ) ) ;
F_30 ( F_4 ( V_14 , V_11 ) ) ;
break;
}
return F_32 ( V_30 ) ;
}
static int F_33 ( void )
{
int V_3 = F_8 () ;
F_29 ( & F_4 ( V_16 , V_3 ) , V_32 ) ;
F_29 ( & F_4 ( V_14 , V_3 ) , V_32 ) ;
F_34 ( ! F_4 ( V_16 , V_3 ) || ! F_4 ( V_14 , V_3 ) ) ;
F_26 ( V_3 , F_4 ( V_16 , V_3 ) ) ;
F_35 ( & V_37 ) ;
return 1 ;
}
static int F_36 ( void )
{
if ( V_38 )
return F_33 () ;
else
return 0 ;
}
