static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
T_1 V_4 )
{
int V_5 ;
F_2 () ;
V_5 = F_3 ( V_1 , V_3 , V_4 ) ;
F_4 () ;
if ( ! V_5 )
V_3 -> V_6 = 1 ;
return V_5 ;
}
static enum V_7 F_5 ( unsigned int V_8 ,
struct V_2 * V_3 )
{
T_2 V_9 = V_10 ;
#if F_6 ( V_11 )
if ( F_7 ( V_3 ) ) {
enum V_12 V_13 ;
const struct V_14 * V_15 = F_8 ( V_3 , & V_13 ) ;
V_9 = F_9 ( F_10 ( V_15 ) , F_11 ( V_13 ) ) ;
}
#endif
if ( F_12 ( V_3 ) )
return V_16 + V_9 ;
if ( V_8 == V_17 )
return V_18 + V_9 ;
else
return V_19 + V_9 ;
}
static unsigned int F_13 ( void * V_20 ,
struct V_2 * V_3 ,
const struct V_21 * V_22 )
{
struct V_23 * V_24 = V_3 -> V_24 ;
if ( V_24 && F_14 ( V_24 ) && ( V_24 -> V_25 == V_26 ) &&
F_15 ( V_24 ) -> V_27 )
return V_28 ;
#if F_6 ( V_11 )
#if ! F_6 ( V_29 )
if ( F_7 ( V_3 ) && ! F_16 ( (struct V_14 * ) F_7 ( V_3 ) ) )
return V_28 ;
#endif
#endif
if ( F_17 ( F_18 ( V_3 ) ) ) {
enum V_7 V_4 =
F_5 ( V_22 -> V_30 , V_3 ) ;
if ( F_1 ( V_22 -> V_1 , V_3 , V_4 ) )
return V_31 ;
}
return V_28 ;
}
static void T_3 F_19 ( struct V_1 * V_1 )
{
if ( V_1 -> V_32 . V_33 ) {
F_20 ( V_1 , V_34 ,
F_21 ( V_34 ) ) ;
V_1 -> V_32 . V_33 = false ;
}
}
static int T_4 F_22 ( void )
{
return F_23 ( & V_35 ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_35 ) ;
}
int F_26 ( struct V_1 * V_1 )
{
int V_5 = 0 ;
F_27 () ;
if ( V_1 -> V_32 . V_33 )
return 0 ;
F_28 ( & V_36 ) ;
if ( V_1 -> V_32 . V_33 )
goto V_37;
V_5 = F_29 ( V_1 , V_34 ,
F_21 ( V_34 ) ) ;
if ( V_5 == 0 )
V_1 -> V_32 . V_33 = true ;
V_37:
F_30 ( & V_36 ) ;
return V_5 ;
}
