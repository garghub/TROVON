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
const T_1 * V_7 ;
T_1 V_8 ;
int V_9 , V_10 ;
struct V_11 * V_1 ;
V_1 = F_7 ( V_6 -> V_1 , NULL ) ;
if ( ! V_1 )
return - V_12 ;
F_4 ( L_2 , V_6 -> V_1 ) ;
if ( ! F_8 ( V_6 -> V_1 ) ||
! F_9 ( V_6 -> V_1 ) ) {
F_10 ( L_3 ) ;
return - V_13 ;
}
V_7 = F_11 ( V_1 , L_4 , NULL ) ;
F_12 ( V_1 ) ;
if ( ! V_7 )
return - V_13 ;
V_8 = * V_7 / 1000 ;
F_4 ( L_5 , V_8 ) ;
F_4 ( L_6 ) ;
for ( V_9 = 0 ; V_14 [ V_9 ] . V_15 != V_16 ; V_9 ++ ) {
V_14 [ V_9 ] . V_15 = V_8 / V_14 [ V_9 ] . V_17 ;
F_4 ( L_7 , V_9 , V_14 [ V_9 ] . V_15 ) ;
}
V_6 -> V_18 . V_19 = 25000 ;
V_10 = F_5 ( V_6 -> V_1 ) ;
F_4 ( L_8 , V_10 ) ;
V_6 -> V_20 = V_14 [ V_10 ] . V_15 ;
#ifdef F_13
F_14 ( V_6 -> V_21 , F_15 ( V_6 -> V_1 ) ) ;
#endif
return F_16 ( V_6 , V_14 ) ;
}
static int F_17 ( struct V_5 * V_6 ,
unsigned int V_22 )
{
F_4 ( L_9 \
L_10 ,
V_6 -> V_1 ,
V_14 [ V_22 ] . V_15 ,
V_14 [ V_22 ] . V_17 ) ;
return F_1 ( V_6 -> V_1 , V_22 ) ;
}
static int T_2 F_18 ( void )
{
if ( ! F_19 ( V_23 ) )
return - V_12 ;
return F_20 ( & V_24 ) ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_24 ) ;
}
