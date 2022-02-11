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
static int
F_20 ( const struct V_5 * V_5 ,
const struct V_5 * V_22 ,
unsigned int * V_23 )
{
T_1 V_13 = 0 ;
T_2 V_24 ;
int V_15 ;
F_12 (i, cpumask, andmask) {
if ( ! F_21 ( V_15 , V_21 ) )
continue;
V_13 = F_4 ( V_4 , V_15 ) ;
V_24 = F_3 ( V_15 ) ;
break;
}
if ( ! V_13 )
return - V_25 ;
F_12 (i, cpumask, andmask) {
if ( ! F_21 ( V_15 , V_21 ) )
continue;
if ( V_24 != F_3 ( V_15 ) )
continue;
V_13 |= F_4 ( V_4 , V_15 ) ;
}
* V_23 = V_13 ;
return 0 ;
}
static void F_22 ( void )
{
unsigned int V_11 = F_8 () ;
unsigned int V_3 ;
F_4 ( V_4 , V_11 ) = F_23 ( V_26 ) ;
F_24 ( V_11 , F_4 ( V_16 , V_11 ) ) ;
F_25 (cpu) {
if ( F_3 ( V_11 ) != F_3 ( V_3 ) )
continue;
F_24 ( V_11 , F_4 ( V_16 , V_3 ) ) ;
F_24 ( V_3 , F_4 ( V_16 , V_11 ) ) ;
}
}
static int T_3
F_26 ( struct V_27 * V_28 , unsigned long V_29 , void * V_30 )
{
unsigned int V_11 = ( unsigned long ) V_30 ;
unsigned int V_3 ;
int V_31 = 0 ;
switch ( V_29 ) {
case V_32 :
if ( ! F_27 ( & F_4 ( V_16 , V_11 ) ,
V_33 ) ) {
V_31 = - V_34 ;
} else if ( ! F_27 ( & F_4 ( V_14 , V_11 ) ,
V_33 ) ) {
F_28 ( F_4 ( V_16 , V_11 ) ) ;
V_31 = - V_34 ;
}
break;
case V_35 :
case V_36 :
case V_37 :
F_25 (cpu) {
if ( F_3 ( V_11 ) != F_3 ( V_3 ) )
continue;
F_29 ( V_11 , F_4 ( V_16 , V_3 ) ) ;
F_29 ( V_3 , F_4 ( V_16 , V_11 ) ) ;
}
F_28 ( F_4 ( V_16 , V_11 ) ) ;
F_28 ( F_4 ( V_14 , V_11 ) ) ;
break;
}
return F_30 ( V_31 ) ;
}
static int F_31 ( void )
{
int V_3 = F_8 () ;
F_27 ( & F_4 ( V_16 , V_3 ) , V_33 ) ;
F_27 ( & F_4 ( V_14 , V_3 ) , V_33 ) ;
F_32 ( ! F_4 ( V_16 , V_3 ) || ! F_4 ( V_14 , V_3 ) ) ;
F_24 ( V_3 , F_4 ( V_16 , V_3 ) ) ;
F_33 ( & V_38 ) ;
return 1 ;
}
static int F_34 ( void )
{
if ( V_39 )
return F_31 () ;
else
return 0 ;
}
static const struct V_5 * F_35 ( void )
{
return V_40 ;
}
static void F_36 ( int V_3 , struct V_5 * V_41 ,
const struct V_5 * V_6 )
{
if ( V_6 == F_35 () )
F_10 ( V_41 , F_37 ( V_3 ) ) ;
else
F_38 ( V_41 , V_6 , F_4 ( V_16 , V_3 ) ) ;
}
