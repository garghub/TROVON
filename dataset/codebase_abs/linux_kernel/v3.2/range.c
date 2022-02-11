int F_1 ( struct V_1 * V_1 , int V_2 , int V_3 , T_1 V_4 , T_1 V_5 )
{
if ( V_4 >= V_5 )
return V_3 ;
if ( V_3 >= V_2 )
return V_3 ;
V_1 [ V_3 ] . V_4 = V_4 ;
V_1 [ V_3 ] . V_5 = V_5 ;
V_3 ++ ;
return V_3 ;
}
int F_2 ( struct V_1 * V_1 , int V_2 , int V_3 ,
T_1 V_4 , T_1 V_5 )
{
int V_6 ;
if ( V_4 >= V_5 )
return V_3 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ ) {
T_1 V_7 , V_8 ;
T_1 V_9 , V_10 ;
if ( ! V_1 [ V_6 ] . V_5 )
continue;
V_9 = F_3 ( V_1 [ V_6 ] . V_4 , V_4 ) ;
V_10 = F_4 ( V_1 [ V_6 ] . V_5 , V_5 ) ;
if ( V_9 > V_10 )
continue;
V_7 = F_4 ( V_1 [ V_6 ] . V_4 , V_4 ) ;
V_8 = F_3 ( V_1 [ V_6 ] . V_5 , V_5 ) ;
V_1 [ V_6 ] . V_4 = V_7 ;
V_1 [ V_6 ] . V_5 = V_8 ;
return V_3 ;
}
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
}
void F_5 ( struct V_1 * V_1 , int V_2 , T_1 V_4 , T_1 V_5 )
{
int V_6 , V_11 ;
if ( V_4 >= V_5 )
return;
for ( V_11 = 0 ; V_11 < V_2 ; V_11 ++ ) {
if ( ! V_1 [ V_11 ] . V_5 )
continue;
if ( V_4 <= V_1 [ V_11 ] . V_4 && V_5 >= V_1 [ V_11 ] . V_5 ) {
V_1 [ V_11 ] . V_4 = 0 ;
V_1 [ V_11 ] . V_5 = 0 ;
continue;
}
if ( V_4 <= V_1 [ V_11 ] . V_4 && V_5 < V_1 [ V_11 ] . V_5 &&
V_1 [ V_11 ] . V_4 < V_5 ) {
V_1 [ V_11 ] . V_4 = V_5 ;
continue;
}
if ( V_4 > V_1 [ V_11 ] . V_4 && V_5 >= V_1 [ V_11 ] . V_5 &&
V_1 [ V_11 ] . V_5 > V_4 ) {
V_1 [ V_11 ] . V_5 = V_4 ;
continue;
}
if ( V_4 > V_1 [ V_11 ] . V_4 && V_5 < V_1 [ V_11 ] . V_5 ) {
for ( V_6 = 0 ; V_6 < V_2 ; V_6 ++ ) {
if ( V_1 [ V_6 ] . V_5 == 0 )
break;
}
if ( V_6 < V_2 ) {
V_1 [ V_6 ] . V_5 = V_1 [ V_11 ] . V_5 ;
V_1 [ V_6 ] . V_4 = V_5 ;
} else {
F_6 ( V_12 L_1 ) ;
}
V_1 [ V_11 ] . V_5 = V_4 ;
continue;
}
}
}
static int F_7 ( const void * V_13 , const void * V_14 )
{
const struct V_1 * V_15 = V_13 ;
const struct V_1 * V_16 = V_14 ;
T_2 V_17 , V_18 ;
V_17 = V_15 -> V_4 ;
V_18 = V_16 -> V_4 ;
return V_17 - V_18 ;
}
int F_8 ( struct V_1 * V_1 , int V_2 )
{
int V_6 , V_11 , V_19 = V_2 - 1 , V_3 = V_2 ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
if ( V_1 [ V_6 ] . V_5 )
continue;
for ( V_11 = V_19 ; V_11 > V_6 ; V_11 -- ) {
if ( V_1 [ V_11 ] . V_5 ) {
V_19 = V_11 ;
break;
}
}
if ( V_11 == V_6 )
break;
V_1 [ V_6 ] . V_4 = V_1 [ V_19 ] . V_4 ;
V_1 [ V_6 ] . V_5 = V_1 [ V_19 ] . V_5 ;
V_1 [ V_19 ] . V_4 = 0 ;
V_1 [ V_19 ] . V_5 = 0 ;
V_19 -- ;
}
for ( V_6 = 0 ; V_6 < V_2 ; V_6 ++ ) {
if ( ! V_1 [ V_6 ] . V_5 ) {
V_3 = V_6 ;
break;
}
}
F_9 ( V_1 , V_3 , sizeof( struct V_1 ) , F_7 , NULL ) ;
return V_3 ;
}
void F_10 ( struct V_1 * V_1 , int V_3 )
{
F_9 ( V_1 , V_3 , sizeof( struct V_1 ) , F_7 , NULL ) ;
}
