static enum V_1 F_1 ( unsigned int V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_6 ;
#if F_2 ( V_7 ) || F_2 ( V_8 )
if ( V_4 -> V_9 )
V_5 = F_3 ( (struct V_10 * ) V_4 -> V_9 ) ;
#endif
#ifdef F_4
if ( V_4 -> V_11 &&
V_4 -> V_11 -> V_12 & V_13 )
return V_14 + V_5 ;
#endif
if ( V_2 == V_15 )
return V_16 + V_5 ;
else
return V_17 + V_5 ;
}
static unsigned int F_5 ( unsigned int V_2 ,
struct V_3 * V_4 ,
const struct V_18 * V_19 ,
const struct V_18 * V_20 ,
int (* F_6)( struct V_3 * ) )
{
struct V_3 * V_21 ;
#if F_2 ( V_7 ) || F_2 ( V_8 )
if ( V_4 -> V_9 && ! F_7 ( (struct V_10 * ) V_4 -> V_9 ) )
return V_22 ;
#endif
V_21 = F_8 ( V_4 , F_1 ( V_2 , V_4 ) ) ;
if ( V_21 == NULL )
return V_23 ;
if ( V_21 == V_4 )
return V_22 ;
F_9 ( V_2 , V_21 , (struct V_18 * ) V_19 ,
(struct V_18 * ) V_20 , F_6 ) ;
return V_23 ;
}
static int T_2 F_10 ( void )
{
int V_24 = 0 ;
V_24 = F_11 () ;
if ( V_24 < 0 ) {
F_12 ( L_1 ) ;
return V_24 ;
}
V_24 = F_13 ( V_25 , F_14 ( V_25 ) ) ;
if ( V_24 < 0 ) {
F_12 ( L_2 ) ;
goto V_26;
}
return V_24 ;
V_26:
F_15 () ;
return V_24 ;
}
static void T_3 F_16 ( void )
{
F_17 ( V_25 , F_14 ( V_25 ) ) ;
F_15 () ;
}
void F_18 ( void )
{
}
