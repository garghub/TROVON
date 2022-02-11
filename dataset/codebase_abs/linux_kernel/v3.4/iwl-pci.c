static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = (struct V_5 * ) ( V_4 -> V_7 ) ;
struct V_8 * V_9 ;
struct V_10 * V_10 ;
int V_11 ;
V_9 = F_2 ( sizeof( * V_10 -> V_9 ) , V_12 ) ;
if ( ! V_9 ) {
F_3 ( V_13 , & V_2 -> V_14 ,
L_1 ) ;
V_11 = - V_15 ;
goto V_16;
}
#ifdef F_4
V_10 = F_5 ( V_9 , V_2 , V_4 ) ;
#else
V_10 = F_6 ( V_9 , V_2 , V_4 ) ;
#endif
if ( V_10 == NULL ) {
V_11 = - V_15 ;
goto V_16;
}
V_9 -> V_17 = V_10 ;
F_7 ( V_2 , V_10 ) ;
V_11 = F_8 ( V_9 , V_10 , V_6 ) ;
if ( V_11 )
goto V_18;
return 0 ;
V_18:
F_9 ( V_10 ) ;
F_7 ( V_2 , NULL ) ;
V_16:
F_10 ( V_9 ) ;
return V_11 ;
}
static void T_1 F_11 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = F_12 ( V_2 ) ;
struct V_8 * V_9 = V_10 -> V_9 ;
F_13 ( V_9 ) ;
F_9 ( V_9 -> V_17 ) ;
F_7 ( V_2 , NULL ) ;
F_10 ( V_9 ) ;
}
static int F_14 ( struct V_19 * V_19 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
struct V_10 * V_10 = F_12 ( V_2 ) ;
return F_16 ( V_10 ) ;
}
static int F_17 ( struct V_19 * V_19 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
struct V_10 * V_10 = F_12 ( V_2 ) ;
F_18 ( V_2 , V_20 , 0x00 ) ;
return F_19 ( V_10 ) ;
}
int T_2 F_20 ( void )
{
int V_21 ;
V_21 = F_21 ( & V_22 ) ;
if ( V_21 )
F_22 ( L_2 ) ;
return V_21 ;
}
void F_23 ( void )
{
F_24 ( & V_22 ) ;
}
