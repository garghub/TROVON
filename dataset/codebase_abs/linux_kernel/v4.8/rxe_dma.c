static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_3 == V_4 ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
void * V_5 , T_2 V_6 ,
enum V_7 V_8 )
{
F_3 ( ! F_4 ( V_8 ) ) ;
return ( V_9 ) V_5 ;
}
static void F_5 ( struct V_1 * V_2 ,
T_1 V_10 , T_2 V_6 ,
enum V_7 V_8 )
{
F_3 ( ! F_4 ( V_8 ) ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_11 * V_11 ,
unsigned long V_12 ,
T_2 V_6 , enum V_7 V_8 )
{
T_1 V_10 ;
F_3 ( ! F_4 ( V_8 ) ) ;
if ( V_12 + V_6 > V_13 ) {
V_10 = V_4 ;
goto V_14;
}
V_10 = ( V_9 ) F_7 ( V_11 ) ;
if ( V_10 )
V_10 += V_12 ;
V_14:
return V_10 ;
}
static void F_8 ( struct V_1 * V_2 ,
T_1 V_10 , T_2 V_6 ,
enum V_7 V_8 )
{
F_3 ( ! F_4 ( V_8 ) ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_17 , enum V_7 V_8 )
{
struct V_15 * V_18 ;
T_1 V_10 ;
int V_19 ;
int V_20 = V_17 ;
F_3 ( ! F_4 ( V_8 ) ) ;
F_10 (sgl, sg, nents, i) {
V_10 = ( V_9 ) F_7 ( F_11 ( V_18 ) ) ;
if ( ! V_10 ) {
V_20 = 0 ;
break;
}
V_18 -> V_21 = V_10 + V_18 -> V_12 ;
#ifdef F_12
V_18 -> V_22 = V_18 -> V_23 ;
#endif
}
return V_20 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_15 * V_18 , int V_17 ,
enum V_7 V_8 )
{
F_3 ( ! F_4 ( V_8 ) ) ;
}
static void F_14 ( struct V_1 * V_2 ,
T_1 V_10 ,
T_2 V_6 , enum V_7 V_24 )
{
}
static void F_15 ( struct V_1 * V_2 ,
T_1 V_10 ,
T_2 V_6 , enum V_7 V_24 )
{
}
static void * F_16 ( struct V_1 * V_2 , T_2 V_6 ,
T_1 * V_25 , T_3 V_26 )
{
struct V_11 * V_27 ;
void * V_10 = NULL ;
V_27 = F_17 ( V_26 , F_18 ( V_6 ) ) ;
if ( V_27 )
V_10 = F_7 ( V_27 ) ;
if ( V_25 )
* V_25 = ( V_9 ) V_10 ;
return V_10 ;
}
static void F_19 ( struct V_1 * V_2 , T_2 V_6 ,
void * V_5 , T_1 V_25 )
{
F_20 ( ( unsigned long ) V_5 , F_18 ( V_6 ) ) ;
}
