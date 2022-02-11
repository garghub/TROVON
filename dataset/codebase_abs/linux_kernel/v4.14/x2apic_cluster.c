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
F_21 ( const struct V_8 * V_9 , struct V_23 * V_24 ,
unsigned int * V_25 )
{
struct V_8 * V_26 = F_22 ( V_24 ) ;
unsigned int V_3 ;
T_1 V_6 = 0 ;
T_2 V_27 ;
V_3 = F_23 ( V_9 ) ;
if ( V_3 >= V_28 )
return - V_29 ;
V_6 = F_4 ( V_4 , V_3 ) ;
V_27 = F_3 ( V_3 ) ;
F_24 ( V_26 ) ;
F_13 (cpu, mask) {
if ( V_27 != F_3 ( V_3 ) )
continue;
V_6 |= F_4 ( V_4 , V_3 ) ;
F_25 ( V_3 , V_26 ) ;
}
* V_25 = V_6 ;
return 0 ;
}
static void F_26 ( void )
{
unsigned int V_13 = F_10 () ;
unsigned int V_3 ;
F_4 ( V_4 , V_13 ) = F_27 ( V_30 ) ;
F_25 ( V_13 , F_4 ( V_17 , V_13 ) ) ;
F_28 (cpu) {
if ( F_3 ( V_13 ) != F_3 ( V_3 ) )
continue;
F_25 ( V_13 , F_4 ( V_17 , V_3 ) ) ;
F_25 ( V_3 , F_4 ( V_17 , V_13 ) ) ;
}
}
static int F_29 ( unsigned int V_3 )
{
if ( ! F_30 ( & F_4 ( V_17 , V_3 ) , V_31 ) )
return - V_32 ;
if ( ! F_30 ( & F_4 ( V_15 , V_3 ) , V_31 ) ) {
F_31 ( F_4 ( V_17 , V_3 ) ) ;
return - V_32 ;
}
return 0 ;
}
static int F_32 ( unsigned int V_13 )
{
int V_3 ;
F_28 (cpu) {
if ( F_3 ( V_13 ) != F_3 ( V_3 ) )
continue;
F_33 ( V_13 , F_4 ( V_17 , V_3 ) ) ;
F_33 ( V_3 , F_4 ( V_17 , V_13 ) ) ;
}
F_31 ( F_4 ( V_17 , V_13 ) ) ;
F_31 ( F_4 ( V_15 , V_13 ) ) ;
return 0 ;
}
static int F_34 ( void )
{
int V_3 = F_10 () ;
int V_33 ;
if ( ! V_34 )
return 0 ;
V_33 = F_35 ( V_35 , L_1 ,
F_29 , F_32 ) ;
if ( V_33 < 0 ) {
F_36 ( L_2 ) ;
return 0 ;
}
F_25 ( V_3 , F_4 ( V_17 , V_3 ) ) ;
return 1 ;
}
static const struct V_8 * F_37 ( void )
{
return V_36 ;
}
static void F_38 ( int V_3 , struct V_8 * V_37 ,
const struct V_8 * V_9 )
{
if ( V_9 == F_37 () )
F_12 ( V_37 , F_39 ( V_3 ) ) ;
else
F_40 ( V_37 , V_9 , F_4 ( V_17 , V_3 ) ) ;
}
