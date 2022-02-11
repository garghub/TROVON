static T_1 F_1 ( int V_1 , void * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( V_5 -> V_6 [ V_3 ] . V_6 & 0x20000000 ) {
unsigned int V_7 = F_2 ( V_3 ) ;
if ( F_3 ( V_7 == 0 ) ) {
struct V_8 * V_9 = V_2 ;
struct V_10 * V_11 = V_9 -> V_12 + V_3 ;
F_4 ( & V_11 -> V_13 ) ;
return V_14 ;
}
}
}
return V_15 ;
}
static int F_5 ( struct V_10 * V_11 )
{
unsigned int V_16 = V_11 -> V_11 ;
V_5 -> V_17 [ V_16 ] . V_18 = 1 ;
V_5 -> V_17 [ V_16 ] . V_19 = 1 ;
return 0 ;
}
static int F_6 ( struct V_10 * V_11 )
{
unsigned int V_16 = V_11 -> V_11 ;
V_5 -> V_17 [ V_16 ] . V_18 = 0 ;
V_5 -> V_17 [ V_16 ] . V_19 = 0 ;
return 0 ;
}
static int F_7 ( struct V_10 * V_11 )
{
unsigned int V_16 = V_11 -> V_11 ;
if ( V_11 -> V_20 & 31 ) {
F_8 ( L_1 , V_11 -> V_20 ) ;
return - V_21 ;
}
if ( V_11 -> V_22 & 31 ) {
F_8 ( L_2 , V_11 -> V_22 ) ;
return - V_21 ;
}
if ( V_11 -> V_23 & 31 )
V_11 -> V_23 = ( V_11 -> V_23 + ( 32 - 1 ) ) & ~ ( 32 - 1 ) ;
V_11 -> V_22 += 0xa0800000 ;
V_11 -> V_24 = ! V_11 -> V_24 ;
F_9 ( ( unsigned long ) V_11 -> V_20 , V_11 -> V_23 ) ;
F_6 ( V_11 ) ;
V_5 -> V_17 [ V_16 ] . V_25 = V_11 -> V_22 & 0x1fffffe0 ;
V_5 -> V_17 [ V_16 ] . V_26 = V_11 -> V_20 & 0x1fffffe0 ;
V_5 -> V_17 [ V_16 ] . V_27 = ( V_11 -> V_23 & ~ 31 ) | 0x80000000 ;
V_5 -> V_17 [ V_16 ] . V_28 = V_11 -> V_24 ;
V_5 -> V_17 [ V_16 ] . V_29 = 5 ;
F_5 ( V_11 ) ;
F_10 ( L_3
L_4 ,
V_5 -> V_17 [ V_16 ] . V_27 ,
V_5 -> V_17 [ V_16 ] . V_26 ,
V_5 -> V_17 [ V_16 ] . V_25 ,
V_5 -> V_17 [ V_16 ] . V_28 ,
V_5 -> V_17 [ V_16 ] . V_29 ,
V_5 -> V_17 [ V_16 ] . V_18 ,
V_5 -> V_17 [ V_16 ] . V_19 ) ;
return 0 ;
}
static int F_11 ( struct V_10 * V_11 )
{
return F_2 ( V_11 -> V_11 ) ;
}
static int T_2 F_12 ( void )
{
int V_30 ;
V_30 = F_13 ( V_31 , F_1 , V_32 ,
L_5 , & V_33 ) ;
if ( F_14 ( V_30 ) )
return - V_21 ;
V_5 -> V_34 = 27 ;
V_5 -> V_35 = 0x4659404f ;
V_30 = F_15 ( & V_33 ) ;
if ( F_14 ( V_30 != 0 ) )
F_16 ( V_31 , 0 ) ;
return V_30 ;
}
static void T_3 F_17 ( void )
{
F_16 ( V_31 , 0 ) ;
F_18 ( & V_33 ) ;
}
