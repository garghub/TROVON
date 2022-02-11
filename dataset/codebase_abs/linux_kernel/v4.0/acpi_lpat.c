int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
int V_4 , V_5 , V_6 , V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_10 - 1 ; V_4 ++ ) {
if ( ( V_3 >= V_9 [ V_4 ] . V_3 && V_3 <= V_9 [ V_4 + 1 ] . V_3 ) ||
( V_3 <= V_9 [ V_4 ] . V_3 && V_3 >= V_9 [ V_4 + 1 ] . V_3 ) )
break;
}
if ( V_4 == V_2 -> V_10 - 1 )
return - V_11 ;
V_5 = V_9 [ V_4 + 1 ] . V_7 - V_9 [ V_4 ] . V_7 ;
V_6 = V_9 [ V_4 + 1 ] . V_3 - V_9 [ V_4 ] . V_3 ;
V_7 = V_9 [ V_4 ] . V_7 + ( V_3 - V_9 [ V_4 ] . V_3 ) * V_5 / V_6 ;
return V_7 ;
}
int F_2 ( struct V_1 * V_2 ,
int V_7 )
{
int V_4 , V_5 , V_6 , V_3 ;
struct V_8 * V_9 = V_2 -> V_9 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_10 - 1 ; V_4 ++ ) {
if ( V_7 >= V_9 [ V_4 ] . V_7 && V_7 <= V_9 [ V_4 + 1 ] . V_7 )
break;
}
if ( V_4 == V_2 -> V_10 - 1 )
return - V_11 ;
V_5 = V_9 [ V_4 + 1 ] . V_7 - V_9 [ V_4 ] . V_7 ;
V_6 = V_9 [ V_4 + 1 ] . V_3 - V_9 [ V_4 ] . V_3 ;
V_3 = V_9 [ V_4 ] . V_3 + ( V_7 - V_9 [ V_4 ] . V_7 ) * V_6 / V_5 ;
return V_3 ;
}
struct V_1 * F_3 ( T_1
V_12 )
{
struct V_1 * V_2 = NULL ;
struct V_13 V_14 = { V_15 , NULL } ;
union V_16 * V_17 , * V_18 ;
int * V_9 , V_4 ;
T_2 V_19 ;
V_19 = F_4 ( V_12 , L_1 , NULL , & V_14 ) ;
if ( F_5 ( V_19 ) )
return NULL ;
V_17 = (union V_16 * ) V_14 . V_20 ;
if ( ! V_17 || ( V_17 -> type != V_21 ) ||
( V_17 -> V_22 . V_23 % 2 ) || ( V_17 -> V_22 . V_23 < 4 ) )
goto V_24;
V_9 = F_6 ( V_17 -> V_22 . V_23 , sizeof( int ) , V_25 ) ;
if ( ! V_9 )
goto V_24;
for ( V_4 = 0 ; V_4 < V_17 -> V_22 . V_23 ; V_4 ++ ) {
V_18 = & V_17 -> V_22 . V_26 [ V_4 ] ;
if ( V_18 -> type != V_27 ) {
F_7 ( V_9 ) ;
goto V_24;
}
V_9 [ V_4 ] = ( V_28 ) V_18 -> integer . V_29 ;
}
V_2 = F_8 ( sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 ) {
F_7 ( V_9 ) ;
goto V_24;
}
V_2 -> V_9 = (struct V_8 * ) V_9 ;
V_2 -> V_10 = V_17 -> V_22 . V_23 / 2 ;
V_24:
F_7 ( V_14 . V_20 ) ;
return V_2 ;
}
void F_9 ( struct V_1
* V_2 )
{
if ( V_2 ) {
F_7 ( V_2 -> V_9 ) ;
F_7 ( V_2 ) ;
}
}
