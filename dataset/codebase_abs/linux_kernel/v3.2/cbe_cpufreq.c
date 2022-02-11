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
F_16 ( V_14 , V_6 -> V_1 ) ;
return F_17 ( V_6 , V_14 ) ;
}
static int F_18 ( struct V_5 * V_6 )
{
F_19 ( V_6 -> V_1 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 )
{
return F_21 ( V_6 , V_14 ) ;
}
static int F_22 ( struct V_5 * V_6 ,
unsigned int V_22 ,
unsigned int V_23 )
{
int V_3 ;
struct V_24 V_25 ;
unsigned int V_26 ;
F_23 ( V_6 ,
V_14 ,
V_22 ,
V_23 ,
& V_26 ) ;
V_25 . V_27 = V_6 -> V_20 ;
V_25 . V_28 = V_14 [ V_26 ] . V_15 ;
V_25 . V_1 = V_6 -> V_1 ;
F_24 ( & V_29 ) ;
F_25 ( & V_25 , V_30 ) ;
F_4 ( L_9 \
L_10 ,
V_6 -> V_1 ,
V_14 [ V_26 ] . V_15 ,
V_14 [ V_26 ] . V_17 ) ;
V_3 = F_1 ( V_6 -> V_1 , V_26 ) ;
F_25 ( & V_25 , V_31 ) ;
F_26 ( & V_29 ) ;
return V_3 ;
}
static int T_2 F_27 ( void )
{
if ( ! F_28 ( V_32 ) )
return - V_12 ;
return F_29 ( & V_33 ) ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_33 ) ;
}
