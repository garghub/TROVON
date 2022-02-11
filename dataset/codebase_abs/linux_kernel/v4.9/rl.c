static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 = NULL ;
bool V_6 = false ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_8 ; V_7 ++ ) {
if ( V_3 -> V_9 [ V_7 ] . V_4 == V_4 )
return & V_3 -> V_9 [ V_7 ] ;
if ( ! V_6 && ! V_3 -> V_9 [ V_7 ] . V_4 ) {
V_6 = true ;
V_5 = & V_3 -> V_9 [ V_7 ] ;
}
}
return V_5 ;
}
static int F_2 ( struct V_10 * V_11 ,
T_1 V_4 , T_2 V_12 )
{
T_1 V_13 [ F_3 ( V_14 ) ] = { 0 } ;
T_1 V_15 [ F_3 ( V_16 ) ] = { 0 } ;
F_4 ( V_14 , V_13 , V_17 ,
V_18 ) ;
F_4 ( V_14 , V_13 , V_19 , V_12 ) ;
F_4 ( V_14 , V_13 , V_20 , V_4 ) ;
return F_5 ( V_11 , V_13 , sizeof( V_13 ) , V_15 , sizeof( V_15 ) ) ;
}
bool F_6 ( struct V_10 * V_11 , T_1 V_4 )
{
struct V_2 * V_3 = & V_11 -> V_21 . V_22 ;
return ( V_4 <= V_3 -> V_23 && V_4 >= V_3 -> V_24 ) ;
}
int F_7 ( struct V_10 * V_11 , T_1 V_4 , T_2 * V_12 )
{
struct V_2 * V_3 = & V_11 -> V_21 . V_22 ;
struct V_1 * V_25 ;
int V_26 = 0 ;
F_8 ( & V_3 -> V_27 ) ;
if ( ! V_4 || ! F_6 ( V_11 , V_4 ) ) {
F_9 ( V_11 , L_1 ,
V_4 , V_3 -> V_24 , V_3 -> V_23 ) ;
V_26 = - V_28 ;
goto V_15;
}
V_25 = F_1 ( V_3 , V_4 ) ;
if ( ! V_25 ) {
F_9 ( V_11 , L_2 ,
V_3 -> V_8 ) ;
V_26 = - V_29 ;
goto V_15;
}
if ( V_25 -> V_30 ) {
V_25 -> V_30 ++ ;
} else {
V_26 = F_2 ( V_11 , V_4 , V_25 -> V_12 ) ;
if ( V_26 ) {
F_9 ( V_11 , L_3 ,
V_4 , V_26 ) ;
goto V_15;
}
V_25 -> V_4 = V_4 ;
V_25 -> V_30 = 1 ;
}
* V_12 = V_25 -> V_12 ;
V_15:
F_10 ( & V_3 -> V_27 ) ;
return V_26 ;
}
void F_11 ( struct V_10 * V_11 , T_1 V_4 )
{
struct V_2 * V_3 = & V_11 -> V_21 . V_22 ;
struct V_1 * V_25 = NULL ;
if ( V_4 == 0 )
return;
F_8 ( & V_3 -> V_27 ) ;
V_25 = F_1 ( V_3 , V_4 ) ;
if ( ! V_25 || ! V_25 -> V_30 ) {
F_12 ( V_11 , L_4 , V_4 ) ;
goto V_15;
}
V_25 -> V_30 -- ;
if ( ! V_25 -> V_30 ) {
F_2 ( V_11 , 0 , V_25 -> V_12 ) ;
V_25 -> V_4 = 0 ;
}
V_15:
F_10 ( & V_3 -> V_27 ) ;
}
int F_13 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = & V_11 -> V_21 . V_22 ;
int V_7 ;
F_14 ( & V_3 -> V_27 ) ;
if ( ! F_15 ( V_11 , V_31 ) || ! F_16 ( V_11 , V_32 ) ) {
V_3 -> V_8 = 0 ;
return 0 ;
}
V_3 -> V_8 = F_16 ( V_11 , V_33 ) - 1 ;
V_3 -> V_23 = F_16 ( V_11 , V_34 ) ;
V_3 -> V_24 = F_16 ( V_11 , V_35 ) ;
V_3 -> V_9 = F_17 ( V_3 -> V_8 , sizeof( struct V_1 ) ,
V_36 ) ;
if ( ! V_3 -> V_9 )
return - V_37 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_8 ; V_7 ++ )
V_3 -> V_9 [ V_7 ] . V_12 = V_7 + 1 ;
F_18 ( V_11 , L_5 ,
V_3 -> V_8 ,
V_3 -> V_24 >> 10 ,
V_3 -> V_23 >> 10 ) ;
return 0 ;
}
void F_19 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = & V_11 -> V_21 . V_22 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_8 ; V_7 ++ )
if ( V_3 -> V_9 [ V_7 ] . V_4 )
F_2 ( V_11 , 0 ,
V_3 -> V_9 [ V_7 ] . V_12 ) ;
F_20 ( V_11 -> V_21 . V_22 . V_9 ) ;
}
