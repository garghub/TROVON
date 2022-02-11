static int F_1 ( struct V_1 * V_1 , void * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 = V_1 -> V_6 ;
int V_7 ;
int V_8 ;
F_2 ( V_1 , L_1 ) ;
while ( V_5 -> V_9 ) {
V_8 = F_3 ( V_10 , V_11 ,
V_5 -> V_12 , & V_3 ) ;
if ( V_8 ) {
F_4 ( V_1 , L_2 ,
V_5 -> V_9 ) ;
} else {
V_7 = ( V_3 >> V_5 -> V_13 ) & 3 ;
F_4 ( V_1 , L_3 , V_5 -> V_9 ,
V_14 [ V_7 ] ) ;
}
V_5 ++ ;
}
return 0 ;
}
static int F_5 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
return F_6 ( V_16 , F_1 , V_15 -> V_17 ) ;
}
static int F_7 ( struct V_4 * V_4 )
{
static struct V_18 * V_19 ;
V_20 = F_8 ( L_4 , NULL ) ;
if ( ! V_20 )
return - V_21 ;
V_19 = F_9 ( L_5 , V_22 | V_23 ,
V_20 , V_4 ,
& V_24 ) ;
if ( ! V_19 ) {
F_10 ( L_6 ) ;
F_11 ( V_20 ) ;
return - V_21 ;
}
return 0 ;
}
static void F_12 ( void )
{
F_13 ( V_20 ) ;
}
static int T_2 F_14 ( void )
{
const struct V_25 * V_26 ;
int V_27 ;
V_26 = F_15 ( V_28 ) ;
if ( ! V_26 )
return - V_29 ;
V_27 = F_7 ( (struct V_4 * ) V_26 -> V_30 ) ;
if ( V_27 < 0 )
return V_27 ;
return 0 ;
}
static void T_3 F_16 ( void )
{
F_12 () ;
}
