static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
T_1 V_4 )
{
int V_5 ;
F_2 ( V_3 ) ;
F_3 () ;
V_5 = F_4 ( V_1 , V_3 , V_4 ) ;
F_5 () ;
if ( ! V_5 ) {
F_6 ( F_7 ( V_3 ) ) ;
V_3 -> V_6 = 1 ;
}
return V_5 ;
}
static enum V_7 F_8 ( unsigned int V_8 ,
struct V_2 * V_3 )
{
T_2 V_9 = V_10 ;
#if F_9 ( V_11 )
if ( V_3 -> V_12 ) {
enum V_13 V_14 ;
const struct V_15 * V_16 = F_10 ( V_3 , & V_14 ) ;
V_9 = F_11 ( F_12 ( V_16 ) , F_13 ( V_14 ) ) ;
}
#endif
if ( F_14 ( V_3 ) )
return V_17 + V_9 ;
if ( V_8 == V_18 )
return V_19 + V_9 ;
else
return V_20 + V_9 ;
}
static unsigned int F_15 ( void * V_21 ,
struct V_2 * V_3 ,
const struct V_22 * V_23 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
if ( V_25 && F_16 ( V_25 ) && ( V_25 -> V_26 == V_27 ) &&
F_17 ( V_25 ) -> V_28 )
return V_29 ;
#if F_9 ( V_11 )
#if ! F_9 ( V_30 )
if ( V_3 -> V_12 && ! F_18 ( (struct V_15 * ) V_3 -> V_12 ) )
return V_29 ;
#endif
#endif
if ( F_19 ( F_7 ( V_3 ) ) ) {
enum V_7 V_4 =
F_8 ( V_23 -> V_31 , V_3 ) ;
if ( F_1 ( V_23 -> V_1 , V_3 , V_4 ) )
return V_32 ;
}
return V_29 ;
}
static int T_3 F_20 ( void )
{
return F_21 ( V_33 , F_22 ( V_33 ) ) ;
}
static void T_4 F_23 ( void )
{
F_24 ( V_33 , F_22 ( V_33 ) ) ;
}
void F_25 ( void )
{
}
