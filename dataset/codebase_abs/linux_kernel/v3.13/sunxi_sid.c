static T_1 F_1 ( const struct V_1 * V_2 ,
const unsigned int V_3 )
{
T_2 V_4 ;
if ( V_3 >= V_2 -> V_5 )
return 0 ;
V_4 = F_2 ( V_2 -> V_6 + F_3 ( V_3 , 4 ) ) ;
V_4 >>= ( V_3 % 4 ) * 8 ;
return V_4 ;
}
static T_3 F_4 ( struct V_7 * V_8 , struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 ,
T_4 V_14 , T_5 V_15 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_18 ;
V_17 = F_5 ( F_6 ( V_10 ) ) ;
V_2 = F_7 ( V_17 ) ;
if ( V_14 < 0 || V_14 >= V_2 -> V_5 )
return 0 ;
if ( V_15 > V_2 -> V_5 - V_14 )
V_15 = V_2 -> V_5 - V_14 ;
for ( V_18 = 0 ; V_18 < V_15 ; V_18 ++ )
V_13 [ V_18 ] = F_1 ( V_2 , V_14 + V_18 ) ;
return V_18 ;
}
static int F_8 ( struct V_16 * V_17 )
{
F_9 ( & V_17 -> V_19 , & V_20 ) ;
F_10 ( & V_17 -> V_19 , L_1 ) ;
return 0 ;
}
static int F_11 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
const struct V_23 * V_24 ;
T_1 * V_25 ;
unsigned int V_18 ;
V_2 = F_12 ( & V_17 -> V_19 , sizeof( struct V_1 ) ,
V_26 ) ;
if ( ! V_2 )
return - V_27 ;
V_22 = F_13 ( V_17 , V_28 , 0 ) ;
V_2 -> V_6 = F_14 ( & V_17 -> V_19 , V_22 ) ;
if ( F_15 ( V_2 -> V_6 ) )
return F_16 ( V_2 -> V_6 ) ;
V_24 = F_17 ( V_29 , & V_17 -> V_19 ) ;
if ( ! V_24 )
return - V_30 ;
V_2 -> V_5 = ( int ) V_24 -> V_31 ;
F_18 ( V_17 , V_2 ) ;
V_20 . V_15 = V_2 -> V_5 ;
if ( F_19 ( & V_17 -> V_19 , & V_20 ) )
return - V_30 ;
V_25 = F_20 ( sizeof( T_1 ) * V_2 -> V_5 , V_26 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_5 ; V_18 ++ )
V_25 [ V_18 ] = F_1 ( V_2 , V_18 ) ;
F_21 ( V_25 , V_2 -> V_5 ) ;
F_22 ( V_25 ) ;
F_10 ( & V_17 -> V_19 , L_2 ) ;
return 0 ;
}
