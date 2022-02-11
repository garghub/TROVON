static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
F_2 ( V_2 ) ;
F_3 () ;
V_4 = F_4 ( V_2 , V_3 ) ;
F_5 () ;
if ( ! V_4 )
F_6 ( F_7 ( V_2 ) ) ;
return V_4 ;
}
static enum V_5 F_8 ( unsigned int V_6 ,
struct V_1 * V_2 )
{
T_2 V_7 = V_8 ;
#if F_9 ( V_9 ) || F_9 ( V_10 )
if ( V_2 -> V_11 )
V_7 = F_10 ( (struct V_12 * ) V_2 -> V_11 ) ;
#endif
#ifdef F_11
if ( V_2 -> V_13 &&
V_2 -> V_13 -> V_14 & V_15 )
return V_16 + V_7 ;
#endif
if ( V_6 == V_17 )
return V_18 + V_7 ;
else
return V_19 + V_7 ;
}
static unsigned int F_12 ( const struct V_20 * V_21 ,
struct V_1 * V_2 ,
const struct V_22 * V_23 ,
const struct V_22 * V_24 ,
int (* F_13)( struct V_1 * ) )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_27 * V_28 = F_14 ( V_2 -> V_26 ) ;
if ( V_26 && ( V_26 -> V_29 == V_30 ) &&
V_28 -> V_31 )
return V_32 ;
#if F_9 ( V_9 ) || F_9 ( V_10 )
#if ! F_9 ( V_33 ) && ! F_9 ( V_34 )
if ( V_2 -> V_11 && ! F_15 ( (struct V_12 * ) V_2 -> V_11 ) )
return V_32 ;
#endif
#endif
if ( F_16 ( F_7 ( V_2 ) ) ) {
enum V_5 V_3 =
F_8 ( V_21 -> V_6 , V_2 ) ;
if ( F_1 ( V_2 , V_3 ) )
return V_35 ;
}
return V_32 ;
}
static int T_3 F_17 ( void )
{
return F_18 ( V_36 , F_19 ( V_36 ) ) ;
}
static void T_4 F_20 ( void )
{
F_21 ( V_36 , F_19 ( V_36 ) ) ;
}
void F_22 ( void )
{
}
