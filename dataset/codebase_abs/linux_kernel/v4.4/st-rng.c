static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , bool V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
T_2 V_9 ;
int V_10 ;
if ( V_4 < sizeof( V_11 ) )
return - V_12 ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
V_9 = F_2 ( V_7 -> V_14 + V_15 ) ;
if ( V_9 & V_16 )
break;
F_3 ( 1 ) ;
}
if ( V_10 == V_13 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_17 && V_10 < V_4 ; V_10 += 2 )
* ( V_11 * ) ( V_3 + V_10 ) =
F_2 ( V_7 -> V_14 + V_18 ) ;
return V_10 ;
}
static int F_4 ( struct V_19 * V_20 )
{
struct V_6 * V_7 ;
struct V_21 * V_22 ;
struct V_23 * V_23 ;
void T_3 * V_14 ;
int V_24 ;
V_7 = F_5 ( & V_20 -> V_25 , sizeof( * V_7 ) , V_26 ) ;
if ( ! V_7 )
return - V_27 ;
V_22 = F_6 ( V_20 , V_28 , 0 ) ;
V_14 = F_7 ( & V_20 -> V_25 , V_22 ) ;
if ( F_8 ( V_14 ) )
return F_9 ( V_14 ) ;
V_23 = F_10 ( & V_20 -> V_25 , NULL ) ;
if ( F_8 ( V_23 ) )
return F_9 ( V_23 ) ;
V_24 = F_11 ( V_23 ) ;
if ( V_24 )
return V_24 ;
V_7 -> V_29 . V_8 = ( unsigned long ) V_7 ;
V_7 -> V_29 . V_30 = F_1 ;
V_7 -> V_29 . V_31 = V_20 -> V_31 ;
V_7 -> V_14 = V_14 ;
V_7 -> V_23 = V_23 ;
F_12 ( & V_20 -> V_25 , V_7 ) ;
V_24 = F_13 ( & V_7 -> V_29 ) ;
if ( V_24 ) {
F_14 ( & V_20 -> V_25 , L_1 ) ;
return V_24 ;
}
F_15 ( & V_20 -> V_25 , L_2 ) ;
return 0 ;
}
static int F_16 ( struct V_19 * V_20 )
{
struct V_6 * V_7 = F_17 ( & V_20 -> V_25 ) ;
F_18 ( & V_7 -> V_29 ) ;
F_19 ( V_7 -> V_23 ) ;
return 0 ;
}
