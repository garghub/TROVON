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
static unsigned int F_5 ( const struct V_17 * V_18 ,
struct V_3 * V_4 ,
const struct V_19 * V_20 ,
const struct V_19 * V_21 ,
int (* F_6)( struct V_3 * ) )
{
struct V_3 * V_22 ;
#if F_2 ( V_7 )
if ( V_4 -> V_8 && ! F_7 ( (struct V_9 * ) V_4 -> V_8 ) )
return V_23 ;
#endif
V_22 = F_8 ( V_4 , F_1 ( V_18 -> V_2 , V_4 ) ) ;
if ( V_22 == NULL )
return V_24 ;
if ( V_22 == V_4 )
return V_23 ;
F_9 ( V_22 ) ;
F_10 ( V_25 , V_18 -> V_2 , V_22 ,
(struct V_19 * ) V_20 , (struct V_19 * ) V_21 ,
F_6 , V_26 + 1 ) ;
return V_24 ;
}
static int T_2 F_11 ( void )
{
int V_27 = 0 ;
V_27 = F_12 () ;
if ( V_27 < 0 ) {
F_13 ( L_1 ) ;
return V_27 ;
}
V_27 = F_14 ( V_28 , F_15 ( V_28 ) ) ;
if ( V_27 < 0 ) {
F_13 ( L_2 ) ;
goto V_29;
}
return V_27 ;
V_29:
F_16 () ;
return V_27 ;
}
static void T_3 F_17 ( void )
{
F_18 ( V_28 , F_15 ( V_28 ) ) ;
F_16 () ;
}
void F_19 ( void )
{
}
