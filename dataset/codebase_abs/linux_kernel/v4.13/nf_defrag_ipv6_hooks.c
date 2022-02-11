static enum V_1 F_1 ( unsigned int V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_6 ;
#if F_2 ( V_7 )
if ( F_3 ( V_4 ) ) {
enum V_8 V_9 ;
const struct V_10 * V_11 = F_4 ( V_4 , & V_9 ) ;
V_5 = F_5 ( F_6 ( V_11 ) , F_7 ( V_9 ) ) ;
}
#endif
if ( F_8 ( V_4 ) )
return V_12 + V_5 ;
if ( V_2 == V_13 )
return V_14 + V_5 ;
else
return V_15 + V_5 ;
}
static unsigned int F_9 ( void * V_16 ,
struct V_3 * V_4 ,
const struct V_17 * V_18 )
{
int V_19 ;
#if F_2 ( V_7 )
if ( F_3 ( V_4 ) && ! F_10 ( (struct V_10 * ) F_3 ( V_4 ) ) )
return V_20 ;
#endif
V_19 = F_11 ( V_18 -> V_21 , V_4 ,
F_1 ( V_18 -> V_22 , V_4 ) ) ;
if ( V_19 == - V_23 )
return V_24 ;
return V_19 == 0 ? V_20 : V_25 ;
}
static void T_2 F_12 ( struct V_21 * V_21 )
{
if ( V_21 -> V_26 . V_27 ) {
F_13 ( V_21 , V_28 ,
F_14 ( V_28 ) ) ;
V_21 -> V_26 . V_27 = false ;
}
}
static int T_3 F_15 ( void )
{
int V_29 = 0 ;
V_29 = F_16 () ;
if ( V_29 < 0 ) {
F_17 ( L_1 ) ;
return V_29 ;
}
V_29 = F_18 ( & V_30 ) ;
if ( V_29 < 0 ) {
F_17 ( L_2 ) ;
goto V_31;
}
return V_29 ;
V_31:
F_19 () ;
return V_29 ;
}
static void T_4 F_20 ( void )
{
F_21 ( & V_30 ) ;
F_19 () ;
}
int F_22 ( struct V_21 * V_21 )
{
int V_19 = 0 ;
F_23 () ;
if ( V_21 -> V_26 . V_27 )
return 0 ;
F_24 ( & V_32 ) ;
if ( V_21 -> V_26 . V_27 )
goto V_33;
V_19 = F_25 ( V_21 , V_28 ,
F_14 ( V_28 ) ) ;
if ( V_19 == 0 )
V_21 -> V_26 . V_27 = true ;
V_33:
F_26 ( & V_32 ) ;
return V_19 ;
}
