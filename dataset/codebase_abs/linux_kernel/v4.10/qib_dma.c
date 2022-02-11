static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_3 == V_4 ;
}
static T_1 F_2 ( struct V_1 * V_2 , void * V_5 ,
T_2 V_6 , enum V_7 V_8 )
{
F_3 ( ! F_4 ( V_8 ) ) ;
return ( T_1 ) V_5 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_9 , T_2 V_6 ,
enum V_7 V_8 )
{
F_3 ( ! F_4 ( V_8 ) ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_10 * V_10 ,
unsigned long V_11 , T_2 V_6 ,
enum V_7 V_8 )
{
T_1 V_9 ;
F_3 ( ! F_4 ( V_8 ) ) ;
if ( V_11 + V_6 > V_12 ) {
V_9 = V_4 ;
goto V_13;
}
V_9 = ( T_1 ) F_7 ( V_10 ) ;
if ( V_9 )
V_9 += V_11 ;
V_13:
return V_9 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_9 , T_2 V_6 ,
enum V_7 V_8 )
{
F_3 ( ! F_4 ( V_8 ) ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_14 * V_15 ,
int V_16 , enum V_7 V_8 )
{
struct V_14 * V_17 ;
T_1 V_9 ;
int V_18 ;
int V_19 = V_16 ;
F_3 ( ! F_4 ( V_8 ) ) ;
F_10 (sgl, sg, nents, i) {
V_9 = ( T_1 ) F_7 ( F_11 ( V_17 ) ) ;
if ( ! V_9 ) {
V_19 = 0 ;
break;
}
V_17 -> V_20 = V_9 + V_17 -> V_11 ;
#ifdef F_12
V_17 -> V_21 = V_17 -> V_22 ;
#endif
}
return V_19 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_14 * V_17 , int V_16 ,
enum V_7 V_8 )
{
F_3 ( ! F_4 ( V_8 ) ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_9 ,
T_2 V_6 , enum V_7 V_23 )
{
}
static void F_15 ( struct V_1 * V_2 , T_1 V_9 ,
T_2 V_6 ,
enum V_7 V_23 )
{
}
static void * F_16 ( struct V_1 * V_2 , T_2 V_6 ,
T_1 * V_24 , T_3 V_25 )
{
struct V_10 * V_26 ;
void * V_9 = NULL ;
V_26 = F_17 ( V_25 , F_18 ( V_6 ) ) ;
if ( V_26 )
V_9 = F_7 ( V_26 ) ;
if ( V_24 )
* V_24 = ( T_1 ) V_9 ;
return V_9 ;
}
static void F_19 ( struct V_1 * V_2 , T_2 V_6 ,
void * V_5 , T_1 V_24 )
{
F_20 ( ( unsigned long ) V_5 , F_18 ( V_6 ) ) ;
}
