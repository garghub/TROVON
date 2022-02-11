static int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
int V_3 ;
if ( V_4 )
V_3 = F_2 ( V_1 , V_2 ) ;
else
V_3 = F_3 ( V_1 , V_2 ) ;
F_4 ( L_1 , F_5 ( V_1 ) ) ;
return V_3 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
const T_1 * V_9 ;
T_1 V_10 ;
int V_11 ;
struct V_12 * V_1 ;
V_1 = F_7 ( V_6 -> V_1 , NULL ) ;
if ( ! V_1 )
return - V_13 ;
F_4 ( L_2 , V_6 -> V_1 ) ;
if ( ! F_8 ( V_6 -> V_1 ) ||
! F_9 ( V_6 -> V_1 ) ) {
F_10 ( L_3 ) ;
return - V_14 ;
}
V_9 = F_11 ( V_1 , L_4 , NULL ) ;
F_12 ( V_1 ) ;
if ( ! V_9 )
return - V_14 ;
V_10 = * V_9 / 1000 ;
F_4 ( L_5 , V_10 ) ;
F_4 ( L_6 ) ;
F_13 (pos, cbe_freqs) {
V_8 -> V_15 = V_10 / V_8 -> V_16 ;
F_4 ( L_7 , ( int ) ( V_8 - V_17 ) , V_8 -> V_15 ) ;
}
V_6 -> V_18 . V_19 = 25000 ;
V_11 = F_5 ( V_6 -> V_1 ) ;
F_4 ( L_8 , V_11 ) ;
V_6 -> V_20 = V_17 [ V_11 ] . V_15 ;
#ifdef F_14
F_15 ( V_6 -> V_21 , F_16 ( V_6 -> V_1 ) ) ;
#endif
return F_17 ( V_6 , V_17 ) ;
}
static int F_18 ( struct V_5 * V_6 ,
unsigned int V_22 )
{
F_4 ( L_9 \
L_10 ,
V_6 -> V_1 ,
V_17 [ V_22 ] . V_15 ,
V_17 [ V_22 ] . V_16 ) ;
return F_1 ( V_6 -> V_1 , V_22 ) ;
}
static int T_2 F_19 ( void )
{
if ( ! F_20 ( V_23 ) )
return - V_13 ;
return F_21 ( & V_24 ) ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_24 ) ;
}
