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
if ( ! V_1 [ V_6 ] . V_5 )
continue;
V_7 = F_3 ( V_1 [ V_6 ] . V_4 , V_4 ) ;
V_8 = F_4 ( V_1 [ V_6 ] . V_5 , V_5 ) ;
if ( V_7 > V_8 )
continue;
V_4 = F_4 ( V_1 [ V_6 ] . V_4 , V_4 ) ;
V_5 = F_3 ( V_1 [ V_6 ] . V_5 , V_5 ) ;
memmove ( & V_1 [ V_6 ] , & V_1 [ V_6 + 1 ] ,
( V_3 - ( V_6 + 1 ) ) * sizeof( V_1 [ V_6 ] ) ) ;
V_1 [ V_3 - 1 ] . V_4 = 0 ;
V_1 [ V_3 - 1 ] . V_5 = 0 ;
V_3 -- ;
V_6 -- ;
}
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
}
void F_5 ( struct V_1 * V_1 , int V_2 , T_1 V_4 , T_1 V_5 )
{
int V_6 , V_9 ;
if ( V_4 >= V_5 )
return;
for ( V_9 = 0 ; V_9 < V_2 ; V_9 ++ ) {
if ( ! V_1 [ V_9 ] . V_5 )
continue;
if ( V_4 <= V_1 [ V_9 ] . V_4 && V_5 >= V_1 [ V_9 ] . V_5 ) {
V_1 [ V_9 ] . V_4 = 0 ;
V_1 [ V_9 ] . V_5 = 0 ;
continue;
}
if ( V_4 <= V_1 [ V_9 ] . V_4 && V_5 < V_1 [ V_9 ] . V_5 &&
V_1 [ V_9 ] . V_4 < V_5 ) {
V_1 [ V_9 ] . V_4 = V_5 ;
continue;
}
if ( V_4 > V_1 [ V_9 ] . V_4 && V_5 >= V_1 [ V_9 ] . V_5 &&
V_1 [ V_9 ] . V_5 > V_4 ) {
V_1 [ V_9 ] . V_5 = V_4 ;
continue;
}
if ( V_4 > V_1 [ V_9 ] . V_4 && V_5 < V_1 [ V_9 ] . V_5 ) {
for ( V_6 = 0 ; V_6 < V_2 ; V_6 ++ ) {
if ( V_1 [ V_6 ] . V_5 == 0 )
break;
}
if ( V_6 < V_2 ) {
V_1 [ V_6 ] . V_5 = V_1 [ V_9 ] . V_5 ;
V_1 [ V_6 ] . V_4 = V_5 ;
} else {
F_6 ( L_1 ,
V_10 ) ;
}
V_1 [ V_9 ] . V_5 = V_4 ;
continue;
}
}
}
static int F_7 ( const void * V_11 , const void * V_12 )
{
const struct V_1 * V_13 = V_11 ;
const struct V_1 * V_14 = V_12 ;
if ( V_13 -> V_4 < V_14 -> V_4 )
return - 1 ;
if ( V_13 -> V_4 > V_14 -> V_4 )
return 1 ;
return 0 ;
}
int F_8 ( struct V_1 * V_1 , int V_2 )
{
int V_6 , V_9 , V_15 = V_2 - 1 , V_3 = V_2 ;
for ( V_6 = 0 ; V_6 < V_15 ; V_6 ++ ) {
if ( V_1 [ V_6 ] . V_5 )
continue;
for ( V_9 = V_15 ; V_9 > V_6 ; V_9 -- ) {
if ( V_1 [ V_9 ] . V_5 ) {
V_15 = V_9 ;
break;
}
}
if ( V_9 == V_6 )
break;
V_1 [ V_6 ] . V_4 = V_1 [ V_15 ] . V_4 ;
V_1 [ V_6 ] . V_5 = V_1 [ V_15 ] . V_5 ;
V_1 [ V_15 ] . V_4 = 0 ;
V_1 [ V_15 ] . V_5 = 0 ;
V_15 -- ;
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
