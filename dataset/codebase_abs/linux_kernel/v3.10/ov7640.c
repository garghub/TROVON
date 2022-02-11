static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_3 [ V_4 ] != 0xFF ; V_4 += 2 )
if ( F_2 ( V_2 , V_3 [ V_4 ] , V_3 [ V_4 + 1 ] ) < 0 )
return - 1 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 ;
if ( ! F_4 ( V_8 , V_11 ) )
return - V_12 ;
V_10 = F_5 ( sizeof( struct V_9 ) , V_13 ) ;
if ( V_10 == NULL )
return - V_14 ;
F_6 ( V_10 , V_2 , & V_15 ) ;
V_2 -> V_16 = V_17 ;
F_7 ( V_2 , L_1 ,
V_2 -> V_18 << 1 , V_2 -> V_8 -> V_19 ) ;
if ( F_1 ( V_2 , V_20 ) < 0 ) {
F_8 ( V_2 , L_2 ) ;
F_9 ( V_10 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_11 ( V_2 ) ;
F_12 ( V_10 ) ;
F_9 ( V_10 ) ;
return 0 ;
}
