static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , bool V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
T_2 V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_9 = F_2 ( V_7 -> V_12 + V_13 ) ;
if ( V_9 & V_14 )
break;
F_3 ( 1 ) ;
}
if ( V_10 == V_11 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_15 && V_10 < V_4 ; V_10 += 2 )
* ( V_16 * ) ( V_3 + V_10 ) =
F_2 ( V_7 -> V_12 + V_17 ) ;
return V_10 ;
}
static int F_4 ( struct V_18 * V_19 )
{
struct V_6 * V_7 ;
struct V_20 * V_21 ;
struct V_22 * V_22 ;
void T_3 * V_12 ;
int V_23 ;
V_7 = F_5 ( & V_19 -> V_24 , sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 )
return - V_26 ;
V_21 = F_6 ( V_19 , V_27 , 0 ) ;
V_12 = F_7 ( & V_19 -> V_24 , V_21 ) ;
if ( F_8 ( V_12 ) )
return F_9 ( V_12 ) ;
V_22 = F_10 ( & V_19 -> V_24 , NULL ) ;
if ( F_8 ( V_22 ) )
return F_9 ( V_22 ) ;
V_23 = F_11 ( V_22 ) ;
if ( V_23 )
return V_23 ;
V_7 -> V_28 . V_8 = ( unsigned long ) V_7 ;
V_7 -> V_28 . V_29 = F_1 ;
V_7 -> V_28 . V_30 = V_19 -> V_30 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_22 = V_22 ;
F_12 ( & V_19 -> V_24 , V_7 ) ;
V_23 = F_13 ( & V_7 -> V_28 ) ;
if ( V_23 ) {
F_14 ( & V_19 -> V_24 , L_1 ) ;
F_15 ( V_22 ) ;
return V_23 ;
}
F_16 ( & V_19 -> V_24 , L_2 ) ;
return 0 ;
}
static int F_17 ( struct V_18 * V_19 )
{
struct V_6 * V_7 = F_18 ( & V_19 -> V_24 ) ;
F_19 ( & V_7 -> V_28 ) ;
F_15 ( V_7 -> V_22 ) ;
return 0 ;
}
