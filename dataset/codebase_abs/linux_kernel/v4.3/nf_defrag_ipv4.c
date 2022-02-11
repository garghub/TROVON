static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
F_2 ( V_2 ) ;
F_3 () ;
V_4 = F_4 ( V_2 , V_3 ) ;
F_5 () ;
if ( ! V_4 ) {
F_6 ( F_7 ( V_2 ) ) ;
V_2 -> V_5 = 1 ;
}
return V_4 ;
}
static enum V_6 F_8 ( unsigned int V_7 ,
struct V_1 * V_2 )
{
T_2 V_8 = V_9 ;
#if F_9 ( V_10 )
if ( V_2 -> V_11 ) {
enum V_12 V_13 ;
const struct V_14 * V_15 = F_10 ( V_2 , & V_13 ) ;
V_8 = F_11 ( F_12 ( V_15 ) , F_13 ( V_13 ) ) ;
}
#endif
if ( F_14 ( V_2 ) )
return V_16 + V_8 ;
if ( V_7 == V_17 )
return V_18 + V_8 ;
else
return V_19 + V_8 ;
}
static unsigned int F_15 ( const struct V_20 * V_21 ,
struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_26 * V_27 = F_16 ( V_2 -> V_25 ) ;
if ( V_25 && ( V_25 -> V_28 == V_29 ) &&
V_27 -> V_30 )
return V_31 ;
#if F_9 ( V_10 )
#if ! F_9 ( V_32 )
if ( V_2 -> V_11 && ! F_17 ( (struct V_14 * ) V_2 -> V_11 ) )
return V_31 ;
#endif
#endif
if ( F_18 ( F_7 ( V_2 ) ) ) {
enum V_6 V_3 =
F_8 ( V_21 -> V_7 , V_2 ) ;
if ( F_1 ( V_2 , V_3 ) )
return V_33 ;
}
return V_31 ;
}
static int T_3 F_19 ( void )
{
return F_20 ( V_34 , F_21 ( V_34 ) ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( V_34 , F_21 ( V_34 ) ) ;
}
void F_24 ( void )
{
}
