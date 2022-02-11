void F_1 ( struct V_1 * V_2 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 )
V_2 -> V_5 [ V_3 ] = NULL ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 )
V_2 -> V_7 [ V_3 ] = NULL ;
V_2 -> V_8 = NULL ;
}
void F_2 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_9 * V_11 ;
if ( ! V_10 )
return;
V_11 = V_2 -> V_7 [ V_10 -> V_12 ] ;
V_2 -> V_7 [ V_10 -> V_12 ] = F_3 ( V_10 , V_11 ) ;
if ( V_10 -> V_13 ) {
V_11 = V_2 -> V_8 ;
V_2 -> V_8 = F_3 ( V_10 , V_11 ) ;
}
}
int F_4 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_16 * V_17 ,
bool V_18 )
{
struct V_19 * V_20 ;
struct V_10 * V_21 ;
struct V_9 * V_10 ;
unsigned V_3 ;
int V_22 = 0 ;
V_21 = F_5 ( V_17 ) ;
V_10 = V_21 ? F_6 ( V_21 ) : NULL ;
if ( V_10 && V_10 -> V_15 == V_15 )
F_2 ( V_2 , V_10 ) ;
else if ( V_21 )
V_22 = F_7 ( V_21 , true ) ;
V_20 = F_8 ( V_17 ) ;
if ( V_18 || ! V_20 || V_22 )
return V_22 ;
for ( V_3 = 0 ; V_3 < V_20 -> V_23 ; ++ V_3 ) {
V_21 = F_9 ( V_20 -> V_18 [ V_3 ] ,
F_10 ( V_17 ) ) ;
V_10 = F_6 ( V_21 ) ;
if ( V_10 && V_10 -> V_15 == V_15 )
F_2 ( V_2 , V_10 ) ;
else
V_22 = F_7 ( V_21 , true ) ;
if ( V_22 )
break;
}
return V_22 ;
}
int F_11 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
int V_12 )
{
unsigned V_24 = 0 ;
int V_3 , V_22 ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 ) {
struct V_9 * V_10 = V_2 -> V_7 [ V_3 ] ;
struct V_25 * V_26 ;
if ( ! F_12 ( V_10 , V_12 ) )
continue;
if ( ! V_15 -> V_12 [ V_3 ] . V_27 ) {
F_13 ( V_15 -> V_28 , L_1 ) ;
return - V_29 ;
}
if ( V_24 >= V_4 ) {
V_22 = F_14 ( V_10 , false ) ;
if ( V_22 )
return V_22 ;
continue;
}
V_22 = F_15 ( V_15 , & V_26 ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_5 [ V_24 ++ ] = V_26 ;
V_22 = F_16 ( V_15 , & V_15 -> V_12 [ V_3 ] , 16 ) ;
if ( V_22 )
return V_22 ;
if ( ! F_17 ( V_15 , V_3 , V_26 ) ) {
F_18 ( & V_15 -> V_12 [ V_3 ] ) ;
V_22 = F_14 ( V_10 , false ) ;
if ( V_22 )
return V_22 ;
continue;
}
if ( ! F_19 ( V_15 , V_12 , V_26 ) ) {
F_18 ( & V_15 -> V_12 [ V_3 ] ) ;
V_22 = F_14 ( V_10 , false ) ;
if ( V_22 )
return V_22 ;
continue;
}
F_20 ( V_15 , & V_15 -> V_12 [ V_3 ] , false ) ;
F_21 ( V_10 , V_12 ) ;
}
return 0 ;
}
void F_22 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_9 * V_10 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 )
F_23 ( V_15 , & V_2 -> V_5 [ V_3 ] , V_10 ) ;
}
