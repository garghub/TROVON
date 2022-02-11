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
struct V_3 * V_20 ;
#if F_2 ( V_7 )
if ( V_4 -> V_8 && ! F_9 ( (struct V_11 * ) V_4 -> V_8 ) )
return V_21 ;
#endif
V_20 = F_10 ( V_19 -> V_22 , V_4 ,
F_1 ( V_19 -> V_23 , V_4 ) ) ;
if ( V_20 == NULL )
return V_24 ;
if ( V_20 == V_4 )
return V_21 ;
F_11 ( V_20 ) ;
F_12 ( V_25 , V_19 -> V_23 , V_19 -> V_22 , V_19 -> V_26 , V_20 ,
V_19 -> V_27 , V_19 -> V_28 ,
V_19 -> V_29 , V_30 + 1 ) ;
return V_24 ;
}
static int T_2 F_13 ( void )
{
int V_31 = 0 ;
V_31 = F_14 () ;
if ( V_31 < 0 ) {
F_15 ( L_1 ) ;
return V_31 ;
}
V_31 = F_16 ( V_32 , F_17 ( V_32 ) ) ;
if ( V_31 < 0 ) {
F_15 ( L_2 ) ;
goto V_33;
}
return V_31 ;
V_33:
F_18 () ;
return V_31 ;
}
static void T_3 F_19 ( void )
{
F_20 ( V_32 , F_17 ( V_32 ) ) ;
F_18 () ;
}
void F_21 ( void )
{
}
