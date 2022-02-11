static int F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static int F_2 ( char * V_3 , char * V_4 )
{
if ( V_2 )
return F_3 () ;
else if ( ( V_5 . V_6 . V_7 >= V_8 ) &&
( V_5 . V_9 & V_10 ) &&
F_3 () ) {
F_4 ( V_11 L_1 ) ;
return 1 ;
}
else
return 0 ;
}
static void
F_5 ( const struct V_12 * V_13 , int V_14 , int V_15 )
{
unsigned long V_16 ;
unsigned long V_17 ;
unsigned long V_9 ;
F_6 () ;
F_7 ( V_9 ) ;
V_17 = F_8 () ;
F_9 (query_cpu, mask) {
if ( V_15 == V_18 && V_17 == V_16 )
continue;
F_10 ( F_11 ( V_19 , V_16 ) ,
V_14 , V_20 ) ;
}
F_12 ( V_9 ) ;
}
static void F_13 ( const struct V_12 * V_13 , int V_14 )
{
F_5 ( V_13 , V_14 , V_21 ) ;
}
static void
F_14 ( const struct V_12 * V_13 , int V_14 )
{
F_5 ( V_13 , V_14 , V_18 ) ;
}
static void F_15 ( int V_14 )
{
F_5 ( V_22 , V_14 , V_18 ) ;
}
static void F_16 ( int V_14 )
{
F_5 ( V_22 , V_14 , V_21 ) ;
}
static unsigned int F_17 ( const struct V_12 * V_12 )
{
int V_23 = F_18 ( V_12 ) ;
if ( ( unsigned ) V_23 < V_24 )
return F_11 ( V_19 , V_23 ) ;
else
return V_25 ;
}
static unsigned int
F_19 ( const struct V_12 * V_12 ,
const struct V_12 * V_26 )
{
int V_23 ;
F_20 (cpu, cpumask, andmask) {
if ( F_21 ( V_23 , V_22 ) )
break;
}
return F_11 ( V_19 , V_23 ) ;
}
static void F_22 ( void )
{
}
static int F_23 ( void )
{
if ( V_27 && V_2 )
return 1 ;
return V_28 == & V_29 ;
}
