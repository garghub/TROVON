static enum V_1 F_1 ( unsigned int V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_6 ;
#if F_2 ( V_7 )
if ( V_4 -> V_8 )
V_5 = F_3 ( (struct V_9 * ) V_4 -> V_8 ) ;
#endif
#if F_2 ( V_10 )
if ( V_4 -> V_11 &&
V_4 -> V_11 -> V_12 & V_13 )
return V_14 + V_5 ;
#endif
if ( V_2 == V_15 )
return V_16 + V_5 ;
else
return V_17 + V_5 ;
}
static unsigned int F_4 ( const struct V_18 * V_19 ,
struct V_3 * V_4 ,
const struct V_20 * V_21 ,
const struct V_20 * V_22 ,
int (* F_5)( struct V_3 * ) )
{
struct V_3 * V_23 ;
#if F_2 ( V_7 )
if ( V_4 -> V_8 && ! F_6 ( (struct V_9 * ) V_4 -> V_8 ) )
return V_24 ;
#endif
V_23 = F_7 ( V_4 , F_1 ( V_19 -> V_2 , V_4 ) ) ;
if ( V_23 == NULL )
return V_25 ;
if ( V_23 == V_4 )
return V_24 ;
F_8 ( V_23 ) ;
F_9 ( V_26 , V_19 -> V_2 , V_23 ,
(struct V_20 * ) V_21 , (struct V_20 * ) V_22 ,
F_5 , V_27 + 1 ) ;
return V_25 ;
}
static int T_2 F_10 ( void )
{
int V_28 = 0 ;
V_28 = F_11 () ;
if ( V_28 < 0 ) {
F_12 ( L_1 ) ;
return V_28 ;
}
V_28 = F_13 ( V_29 , F_14 ( V_29 ) ) ;
if ( V_28 < 0 ) {
F_12 ( L_2 ) ;
goto V_30;
}
return V_28 ;
V_30:
F_15 () ;
return V_28 ;
}
static void T_3 F_16 ( void )
{
F_17 ( V_29 , F_14 ( V_29 ) ) ;
F_15 () ;
}
void F_18 ( void )
{
}
