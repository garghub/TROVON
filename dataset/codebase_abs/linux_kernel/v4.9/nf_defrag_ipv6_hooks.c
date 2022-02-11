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
static unsigned int F_8 ( void * V_17 ,
struct V_3 * V_4 ,
const struct V_18 * V_19 )
{
int V_20 ;
#if F_2 ( V_7 )
if ( V_4 -> V_8 && ! F_9 ( (struct V_11 * ) V_4 -> V_8 ) )
return V_21 ;
#endif
V_20 = F_10 ( V_19 -> V_22 , V_4 ,
F_1 ( V_19 -> V_23 , V_4 ) ) ;
if ( V_20 == - V_24 )
return V_25 ;
return V_20 == 0 ? V_21 : V_26 ;
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
