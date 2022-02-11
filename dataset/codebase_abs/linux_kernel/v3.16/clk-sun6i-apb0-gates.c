static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
const char * V_9 ;
const char * V_10 ;
struct V_11 * V_12 ;
void T_1 * V_13 ;
int V_14 ;
int V_15 ;
int V_16 ;
V_12 = F_2 ( V_2 , V_17 , 0 ) ;
V_13 = F_3 ( & V_2 -> V_5 , V_12 ) ;
if ( F_4 ( V_13 ) )
return F_5 ( V_13 ) ;
V_9 = F_6 ( V_4 , 0 ) ;
if ( ! V_9 )
return - V_18 ;
V_15 = F_7 ( V_4 , L_1 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( ! V_15 || V_15 > V_19 )
return - V_18 ;
V_8 = F_8 ( & V_2 -> V_5 , sizeof( struct V_7 ) ,
V_20 ) ;
if ( ! V_8 )
return - V_21 ;
V_8 -> V_22 = F_8 ( & V_2 -> V_5 ,
V_19 *
sizeof( struct V_23 * ) ,
V_20 ) ;
if ( ! V_8 -> V_22 )
return - V_21 ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ ) {
F_9 ( V_4 , L_1 ,
V_16 , & V_10 ) ;
V_14 = V_16 ;
F_10 ( V_4 , L_2 , V_16 , & V_14 ) ;
F_11 ( V_14 >= V_19 ) ;
if ( V_14 >= V_19 )
continue;
V_8 -> V_22 [ V_14 ] = F_12 ( & V_2 -> V_5 ,
V_10 ,
V_9 , 0 ,
V_13 , V_14 ,
0 , NULL ) ;
F_11 ( F_4 ( V_8 -> V_22 [ V_14 ] ) ) ;
}
V_8 -> V_24 = V_15 ;
return F_13 ( V_4 , V_25 , V_8 ) ;
}
