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
if ( V_2 -> V_11 )
V_8 = F_10 ( (struct V_12 * ) V_2 -> V_11 ) ;
#endif
#if F_9 ( V_13 )
if ( V_2 -> V_14 &&
V_2 -> V_14 -> V_15 & V_16 )
return V_17 + V_8 ;
#endif
if ( V_7 == V_18 )
return V_19 + V_8 ;
else
return V_20 + V_8 ;
}
static unsigned int F_11 ( const struct V_21 * V_22 ,
struct V_1 * V_2 ,
const struct V_23 * V_24 ,
const struct V_23 * V_25 ,
int (* F_12)( struct V_1 * ) )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_28 * V_29 = F_13 ( V_2 -> V_27 ) ;
if ( V_27 && ( V_27 -> V_30 == V_31 ) &&
V_29 -> V_32 )
return V_33 ;
#if F_9 ( V_10 )
#if ! F_9 ( V_34 )
if ( V_2 -> V_11 && ! F_14 ( (struct V_12 * ) V_2 -> V_11 ) )
return V_33 ;
#endif
#endif
if ( F_15 ( F_7 ( V_2 ) ) ) {
enum V_6 V_3 =
F_8 ( V_22 -> V_7 , V_2 ) ;
if ( F_1 ( V_2 , V_3 ) )
return V_35 ;
}
return V_33 ;
}
static int T_3 F_16 ( void )
{
return F_17 ( V_36 , F_18 ( V_36 ) ) ;
}
static void T_4 F_19 ( void )
{
F_20 ( V_36 , F_18 ( V_36 ) ) ;
}
void F_21 ( void )
{
}
