static int F_1 ( char * V_1 , char * V_2 )
{
return F_2 () ;
}
static inline T_1 F_3 ( int V_3 )
{
return F_4 ( V_4 , V_3 ) >> 16 ;
}
static void F_5 ( int V_3 , int V_5 )
{
T_1 V_6 = F_4 ( V_4 , V_3 ) ;
F_6 () ;
F_7 ( V_6 , V_5 , V_7 ) ;
}
static void
F_8 ( const struct V_8 * V_9 , int V_5 , int V_10 )
{
struct V_8 * V_11 ;
struct V_8 * V_12 ;
unsigned int V_3 , V_13 ;
unsigned long V_14 ;
T_1 V_6 ;
F_6 () ;
F_9 ( V_14 ) ;
V_13 = F_10 () ;
V_12 = F_11 ( V_15 ) ;
F_12 ( V_12 , V_9 ) ;
F_13 (cpu, ipi_mask_ptr) {
unsigned long V_16 ;
V_11 = F_4 ( V_17 , V_3 ) ;
V_6 = 0 ;
F_14 (i, ipi_mask_ptr, cpus_in_cluster_ptr) {
if ( V_10 == V_18 || V_16 != V_13 )
V_6 |= F_4 ( V_4 , V_16 ) ;
}
if ( ! V_6 )
continue;
F_7 ( V_6 , V_5 , V_19 -> V_20 ) ;
F_15 ( V_12 , V_12 , V_11 ) ;
}
F_16 ( V_14 ) ;
}
static void F_17 ( const struct V_8 * V_9 , int V_5 )
{
F_8 ( V_9 , V_5 , V_18 ) ;
}
static void
F_18 ( const struct V_8 * V_9 , int V_5 )
{
F_8 ( V_9 , V_5 , V_21 ) ;
}
static void F_19 ( int V_5 )
{
F_8 ( V_22 , V_5 , V_21 ) ;
}
static void F_20 ( int V_5 )
{
F_8 ( V_22 , V_5 , V_18 ) ;
}
static int
F_21 ( const struct V_8 * V_8 ,
const struct V_8 * V_23 ,
unsigned int * V_24 )
{
T_1 V_6 = 0 ;
T_2 V_25 ;
int V_16 ;
F_14 (i, cpumask, andmask) {
if ( ! F_22 ( V_16 , V_22 ) )
continue;
V_6 = F_4 ( V_4 , V_16 ) ;
V_25 = F_3 ( V_16 ) ;
break;
}
if ( ! V_6 )
return - V_26 ;
F_14 (i, cpumask, andmask) {
if ( ! F_22 ( V_16 , V_22 ) )
continue;
if ( V_25 != F_3 ( V_16 ) )
continue;
V_6 |= F_4 ( V_4 , V_16 ) ;
}
* V_24 = V_6 ;
return 0 ;
}
static void F_23 ( void )
{
unsigned int V_13 = F_10 () ;
unsigned int V_3 ;
F_4 ( V_4 , V_13 ) = F_24 ( V_27 ) ;
F_25 ( V_13 , F_4 ( V_17 , V_13 ) ) ;
F_26 (cpu) {
if ( F_3 ( V_13 ) != F_3 ( V_3 ) )
continue;
F_25 ( V_13 , F_4 ( V_17 , V_3 ) ) ;
F_25 ( V_3 , F_4 ( V_17 , V_13 ) ) ;
}
}
static int
F_27 ( struct V_28 * V_29 , unsigned long V_30 , void * V_31 )
{
unsigned int V_13 = ( unsigned long ) V_31 ;
unsigned int V_3 ;
int V_32 = 0 ;
switch ( V_30 ) {
case V_33 :
if ( ! F_28 ( & F_4 ( V_17 , V_13 ) ,
V_34 ) ) {
V_32 = - V_35 ;
} else if ( ! F_28 ( & F_4 ( V_15 , V_13 ) ,
V_34 ) ) {
F_29 ( F_4 ( V_17 , V_13 ) ) ;
V_32 = - V_35 ;
}
break;
case V_36 :
case V_37 :
case V_38 :
F_26 (cpu) {
if ( F_3 ( V_13 ) != F_3 ( V_3 ) )
continue;
F_30 ( V_13 , F_4 ( V_17 , V_3 ) ) ;
F_30 ( V_3 , F_4 ( V_17 , V_13 ) ) ;
}
F_29 ( F_4 ( V_17 , V_13 ) ) ;
F_29 ( F_4 ( V_15 , V_13 ) ) ;
break;
}
return F_31 ( V_32 ) ;
}
static int F_32 ( void )
{
int V_3 = F_10 () ;
F_28 ( & F_4 ( V_17 , V_3 ) , V_34 ) ;
F_28 ( & F_4 ( V_15 , V_3 ) , V_34 ) ;
F_33 ( ! F_4 ( V_17 , V_3 ) || ! F_4 ( V_15 , V_3 ) ) ;
F_25 ( V_3 , F_4 ( V_17 , V_3 ) ) ;
F_34 ( & V_39 ) ;
return 1 ;
}
static int F_35 ( void )
{
if ( V_40 )
return F_32 () ;
else
return 0 ;
}
static const struct V_8 * F_36 ( void )
{
return V_41 ;
}
static void F_37 ( int V_3 , struct V_8 * V_42 ,
const struct V_8 * V_9 )
{
if ( V_9 == F_36 () )
F_12 ( V_42 , F_38 ( V_3 ) ) ;
else
F_39 ( V_42 , V_9 , F_4 ( V_17 , V_3 ) ) ;
}
