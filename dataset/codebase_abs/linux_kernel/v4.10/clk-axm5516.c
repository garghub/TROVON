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
static struct V_1 *
F_9 ( struct V_23 * V_24 , void * V_25 )
{
unsigned int V_26 = V_24 -> args [ 0 ] ;
if ( V_26 >= F_10 ( V_27 ) ) {
F_11 ( L_1 , V_28 , V_26 ) ;
return F_12 ( - V_29 ) ;
}
return & V_27 [ V_26 ] -> V_2 ;
}
static int F_13 ( struct V_30 * V_31 )
{
void T_3 * V_32 ;
struct V_33 * V_34 ;
int V_35 , V_36 ;
struct V_37 * V_38 = & V_31 -> V_38 ;
struct V_13 * V_13 ;
T_4 V_39 ;
V_34 = F_14 ( V_31 , V_40 , 0 ) ;
V_32 = F_15 ( V_38 , V_34 ) ;
if ( F_16 ( V_32 ) )
return F_17 ( V_32 ) ;
V_13 = F_18 ( V_38 , V_32 , & V_41 ) ;
if ( F_16 ( V_13 ) )
return F_17 ( V_13 ) ;
V_39 = F_10 ( V_27 ) ;
F_19 ( L_2 , V_39 ) ;
for ( V_35 = 0 ; V_35 < V_39 ; V_35 ++ ) {
V_27 [ V_35 ] -> V_13 = V_13 ;
V_36 = F_20 ( V_38 , & V_27 [ V_35 ] -> V_2 ) ;
if ( V_36 )
return V_36 ;
}
return F_21 ( V_38 -> V_42 , F_9 , NULL ) ;
}
static int F_22 ( struct V_30 * V_31 )
{
F_23 ( V_31 -> V_38 . V_42 ) ;
return 0 ;
}
static int T_5 F_24 ( void )
{
return F_25 ( & V_43 ) ;
}
static void T_6 F_26 ( void )
{
F_27 ( & V_43 ) ;
}
