static enum V_1 F_1 ( unsigned int V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_6 ;
#if F_2 ( V_7 )
if ( V_4 -> V_8 )
V_5 = F_3 ( (struct V_9 * ) V_4 -> V_8 ) ;
#endif
#ifdef F_4
if ( V_4 -> V_10 &&
V_4 -> V_10 -> V_11 & V_12 )
return V_13 + V_5 ;
#endif
if ( V_2 == V_14 )
return V_15 + V_5 ;
else
return V_16 + V_5 ;
}
static unsigned int F_5 ( unsigned int V_2 ,
struct V_3 * V_4 ,
const struct V_17 * V_18 ,
const struct V_17 * V_19 ,
int (* F_6)( struct V_3 * ) )
{
struct V_3 * V_20 ;
#if F_2 ( V_7 )
if ( V_4 -> V_8 && ! F_7 ( (struct V_9 * ) V_4 -> V_8 ) )
return V_21 ;
#endif
V_20 = F_8 ( V_4 , F_1 ( V_2 , V_4 ) ) ;
if ( V_20 == NULL )
return V_22 ;
if ( V_20 == V_4 )
return V_21 ;
F_9 ( V_2 , V_20 , (struct V_17 * ) V_18 ,
(struct V_17 * ) V_19 , F_6 ) ;
return V_22 ;
}
static int T_2 F_10 ( void )
{
int V_23 = 0 ;
V_23 = F_11 () ;
if ( V_23 < 0 ) {
F_12 ( L_1 ) ;
return V_23 ;
}
V_23 = F_13 ( V_24 , F_14 ( V_24 ) ) ;
if ( V_23 < 0 ) {
F_12 ( L_2 ) ;
goto V_25;
}
return V_23 ;
V_25:
F_15 () ;
return V_23 ;
}
static void T_3 F_16 ( void )
{
F_17 ( V_24 , F_14 ( V_24 ) ) ;
F_15 () ;
}
void F_18 ( void )
{
}
