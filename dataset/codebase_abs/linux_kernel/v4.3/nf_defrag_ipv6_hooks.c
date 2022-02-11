static enum V_1 F_1 ( unsigned int V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_6 ;
#if F_2 ( V_7 )
if ( V_4 -> V_8 ) {
enum V_9 V_10 ;
const struct V_11 * V_12 = F_3 ( V_4 , & V_10 ) ;
V_5 = F_4 ( F_5 ( V_12 ) , F_6 ( V_10 ) ) ;
}
#endif
if ( F_7 ( V_4 ) )
return V_13 + V_5 ;
if ( V_2 == V_14 )
return V_15 + V_5 ;
else
return V_16 + V_5 ;
}
static unsigned int F_8 ( const struct V_17 * V_18 ,
struct V_3 * V_4 ,
const struct V_19 * V_20 )
{
struct V_3 * V_21 ;
#if F_2 ( V_7 )
if ( V_4 -> V_8 && ! F_9 ( (struct V_11 * ) V_4 -> V_8 ) )
return V_22 ;
#endif
V_21 = F_10 ( V_4 , F_1 ( V_18 -> V_2 , V_4 ) ) ;
if ( V_21 == NULL )
return V_23 ;
if ( V_21 == V_4 )
return V_22 ;
F_11 ( V_21 ) ;
F_12 ( V_24 , V_18 -> V_2 , V_20 -> V_25 , V_21 ,
V_20 -> V_26 , V_20 -> V_27 ,
V_20 -> V_28 , V_29 + 1 ) ;
return V_23 ;
}
static int T_2 F_13 ( void )
{
int V_30 = 0 ;
V_30 = F_14 () ;
if ( V_30 < 0 ) {
F_15 ( L_1 ) ;
return V_30 ;
}
V_30 = F_16 ( V_31 , F_17 ( V_31 ) ) ;
if ( V_30 < 0 ) {
F_15 ( L_2 ) ;
goto V_32;
}
return V_30 ;
V_32:
F_18 () ;
return V_30 ;
}
static void T_3 F_19 ( void )
{
F_20 ( V_31 , F_17 ( V_31 ) ) ;
F_18 () ;
}
void F_21 ( void )
{
}
