static int F_1 ( struct V_1 * V_1 )
{
int V_2 , V_3 ;
V_3 = F_2 ( V_1 -> V_4 , V_5 , & V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 & V_6 ) {
V_2 &= ~ V_6 ;
V_3 = F_3 ( V_1 -> V_4 , V_5 ,
V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return 0 ;
}
static int T_1 F_4 ( struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
struct V_1 * V_1 ;
int V_3 ;
V_1 = F_5 ( & V_8 -> V_11 , sizeof( struct V_1 ) , V_12 ) ;
if ( ! V_1 )
return - V_13 ;
if ( ! F_6 ( V_8 -> V_14 ,
V_15 ) ) {
F_7 ( & V_8 -> V_11 , L_1 ,
V_16 ) ;
return - V_17 ;
}
V_1 -> V_11 = & V_8 -> V_11 ;
V_1 -> V_18 = V_8 -> V_19 ;
F_8 ( V_8 , V_1 ) ;
V_1 -> V_4 = F_9 ( V_8 , & V_20 ) ;
if ( F_10 ( V_1 -> V_4 ) ) {
V_3 = F_11 ( V_1 -> V_4 ) ;
F_12 ( & V_8 -> V_11 , L_2 ,
V_3 ) ;
return V_3 ;
}
V_3 = F_1 ( V_1 ) ;
if ( V_3 < 0 )
return V_3 ;
#ifdef F_13
if ( ! V_10 ) {
struct V_21 * V_22 = V_8 -> V_11 . V_23 ;
const struct V_24 * V_25 ;
V_25 = F_14 ( V_26 , V_22 ) ;
V_10 = V_25 -> V_27 ;
}
#endif
if ( ! V_10 ) {
V_3 = - V_17 ;
F_12 ( & V_8 -> V_11 , L_3 ) ;
return V_3 ;
}
V_3 = F_15 ( V_1 , V_10 -> V_28 ) ;
if ( V_3 != 0 )
return V_3 ;
return 0 ;
}
static int T_2 F_16 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_17 ( V_8 ) ;
F_18 ( V_1 ) ;
return 0 ;
}
static int T_3 F_19 ( void )
{
int V_3 ;
V_3 = F_20 ( & V_29 ) ;
if ( V_3 != 0 ) {
F_21 ( L_4 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_29 ) ;
}
