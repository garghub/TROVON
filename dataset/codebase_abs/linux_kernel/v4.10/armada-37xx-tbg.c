static unsigned int F_1 ( void T_1 * V_1 , const struct V_2 * V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + V_5 ) ;
return ( ( V_4 >> V_3 -> V_6 ) & V_7 ) << 2 ;
}
static unsigned int F_3 ( void T_1 * V_1 , const struct V_2 * V_3 )
{
T_2 V_4 ;
unsigned int div ;
V_4 = F_2 ( V_1 + V_8 ) ;
div = ( V_4 >> V_3 -> V_9 ) & V_7 ;
if ( div == 0 )
div = 1 ;
V_4 = F_2 ( V_1 + V_3 -> V_10 ) ;
div *= 1 << ( ( V_4 >> V_3 -> V_11 ) & V_7 ) ;
return div ;
}
static int F_4 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 . V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_16 = & V_13 -> V_16 ;
const char * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
void T_1 * V_1 ;
int V_26 , V_27 ;
V_19 = F_5 ( & V_13 -> V_16 , sizeof( * V_19 )
+ sizeof( * V_19 -> V_28 ) * V_29 ,
V_30 ) ;
if ( ! V_19 )
return - V_31 ;
V_19 -> V_32 = V_29 ;
F_6 ( V_13 , V_19 ) ;
V_25 = F_7 ( V_16 , NULL ) ;
if ( F_8 ( V_25 ) ) {
F_9 ( V_16 , L_1 ) ;
return - V_33 ;
}
V_21 = F_10 ( V_25 ) ;
V_23 = F_11 ( V_13 , V_34 , 0 ) ;
V_1 = F_12 ( V_16 , V_23 ) ;
if ( F_8 ( V_1 ) )
return F_13 ( V_1 ) ;
for ( V_26 = 0 ; V_26 < V_29 ; V_26 ++ ) {
const char * V_35 ;
unsigned int V_36 , div ;
V_35 = V_37 [ V_26 ] . V_35 ;
V_36 = F_1 ( V_1 , & V_37 [ V_26 ] ) ;
div = F_3 ( V_1 , & V_37 [ V_26 ] ) ;
V_19 -> V_28 [ V_26 ] = F_14 ( NULL , V_35 ,
V_21 , 0 , V_36 , div ) ;
if ( F_8 ( V_19 -> V_28 [ V_26 ] ) )
F_9 ( V_16 , L_2 , V_35 ) ;
}
V_27 = F_15 ( V_15 , V_38 , V_19 ) ;
return V_27 ;
}
static int F_16 ( struct V_12 * V_13 )
{
int V_26 ;
struct V_18 * V_19 = F_17 ( V_13 ) ;
F_18 ( V_13 -> V_16 . V_17 ) ;
for ( V_26 = 0 ; V_26 < V_19 -> V_32 ; V_26 ++ )
F_19 ( V_19 -> V_28 [ V_26 ] ) ;
return 0 ;
}
