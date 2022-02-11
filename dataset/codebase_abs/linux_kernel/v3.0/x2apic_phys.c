static int F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static int F_2 ( char * V_3 , char * V_4 )
{
if ( V_2 )
return F_3 () ;
else
return 0 ;
}
static void
F_4 ( const struct V_5 * V_6 , int V_7 , int V_8 )
{
unsigned long V_9 ;
unsigned long V_10 ;
unsigned long V_11 ;
F_5 () ;
F_6 ( V_11 ) ;
V_10 = F_7 () ;
F_8 (query_cpu, mask) {
if ( V_8 == V_12 && V_10 == V_9 )
continue;
F_9 ( F_10 ( V_13 , V_9 ) ,
V_7 , V_14 ) ;
}
F_11 ( V_11 ) ;
}
static void F_12 ( const struct V_5 * V_6 , int V_7 )
{
F_4 ( V_6 , V_7 , V_15 ) ;
}
static void
F_13 ( const struct V_5 * V_6 , int V_7 )
{
F_4 ( V_6 , V_7 , V_12 ) ;
}
static void F_14 ( int V_7 )
{
F_4 ( V_16 , V_7 , V_12 ) ;
}
static void F_15 ( int V_7 )
{
F_4 ( V_16 , V_7 , V_15 ) ;
}
static unsigned int F_16 ( const struct V_5 * V_5 )
{
int V_17 = F_17 ( V_5 ) ;
if ( ( unsigned ) V_17 < V_18 )
return F_10 ( V_13 , V_17 ) ;
else
return V_19 ;
}
static unsigned int
F_18 ( const struct V_5 * V_5 ,
const struct V_5 * V_20 )
{
int V_17 ;
F_19 (cpu, cpumask, andmask) {
if ( F_20 ( V_17 , V_16 ) )
break;
}
return F_10 ( V_13 , V_17 ) ;
}
static void F_21 ( void )
{
}
static int F_22 ( void )
{
if ( V_21 && V_2 )
return 1 ;
return V_22 == & V_23 ;
}
