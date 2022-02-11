static unsigned long
F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
unsigned long V_8 , V_9 , V_10 , V_11 ;
T_1 V_12 ;
F_4 ( V_5 -> V_13 , V_7 -> V_14 , & V_12 ) ;
V_11 = ( ( V_12 >> 0 ) & 0xf ) + 1 ;
V_9 = ( ( V_12 >> 4 ) & 0xfff ) + 3 ;
V_10 = ( ( V_12 >> 16 ) & 0x1f ) + 1 ;
V_8 = ( V_3 / ( V_10 * V_11 ) ) * V_9 ;
return V_8 ;
}
static unsigned long
F_5 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_5 ) ;
T_1 V_17 , div ;
F_4 ( V_5 -> V_13 , V_16 -> V_14 , & V_17 ) ;
div = 1 + ( ( V_17 >> V_16 -> V_18 ) & ( ( 1 << V_16 -> V_19 ) - 1 ) ) ;
return V_3 / div ;
}
static T_2 F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_20 * V_21 = F_8 ( V_5 ) ;
T_1 V_17 , V_22 ;
F_4 ( V_5 -> V_13 , V_21 -> V_14 , & V_17 ) ;
V_22 = ( V_17 >> V_21 -> V_18 ) & ( ( 1 << V_21 -> V_19 ) - 1 ) ;
return ( T_2 ) V_22 ;
}
static int F_9 ( struct V_23 * V_24 )
{
void T_3 * V_25 ;
struct V_26 * V_27 ;
int V_28 , V_29 ;
struct V_30 * V_31 = & V_24 -> V_31 ;
struct V_32 * V_32 ;
struct V_13 * V_13 ;
T_4 V_33 ;
struct V_34 * V_35 ;
V_27 = F_10 ( V_24 , V_36 , 0 ) ;
V_25 = F_11 ( V_31 , V_27 ) ;
if ( F_12 ( V_25 ) )
return F_13 ( V_25 ) ;
V_13 = F_14 ( V_31 , V_25 , & V_37 ) ;
if ( F_12 ( V_13 ) )
return F_13 ( V_13 ) ;
V_33 = F_15 ( V_38 ) ;
F_16 ( L_1 , V_33 ) ;
V_35 = F_17 ( V_31 , sizeof( * V_35 ) + sizeof( * V_35 -> V_39 ) * V_33 ,
V_40 ) ;
if ( ! V_35 )
return - V_41 ;
V_35 -> V_42 . V_39 = V_35 -> V_39 ;
V_35 -> V_42 . V_43 = V_33 ;
for ( V_28 = 0 ; V_28 < V_33 ; V_28 ++ ) {
V_38 [ V_28 ] -> V_13 = V_13 ;
V_32 = F_18 ( V_31 , & V_38 [ V_28 ] -> V_2 ) ;
if ( F_12 ( V_32 ) )
return F_13 ( V_32 ) ;
V_35 -> V_39 [ V_28 ] = V_32 ;
}
V_29 = F_19 ( V_31 -> V_44 ,
V_45 , & V_35 -> V_42 ) ;
return V_29 ;
}
static int F_20 ( struct V_23 * V_24 )
{
F_21 ( V_24 -> V_31 . V_44 ) ;
return 0 ;
}
static int T_5 F_22 ( void )
{
return F_23 ( & V_46 ) ;
}
static void T_6 F_24 ( void )
{
F_25 ( & V_46 ) ;
}
