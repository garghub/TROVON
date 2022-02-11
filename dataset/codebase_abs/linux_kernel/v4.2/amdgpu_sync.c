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
V_11 = V_2 -> V_7 [ V_10 -> V_12 -> V_13 ] ;
V_2 -> V_7 [ V_10 -> V_12 -> V_13 ] = F_3 (
F_4 ( V_10 , V_11 ) ) ;
F_5 ( & V_11 ) ;
if ( V_10 -> V_14 == V_15 ) {
V_11 = V_2 -> V_8 ;
V_2 -> V_8 = F_3 (
F_4 ( V_10 , V_11 ) ) ;
F_5 ( & V_11 ) ;
}
}
int F_6 ( struct V_16 * V_17 ,
struct V_1 * V_2 ,
struct V_18 * V_19 ,
void * V_14 )
{
struct V_20 * V_21 ;
struct V_10 * V_22 ;
struct V_9 * V_10 ;
unsigned V_3 ;
int V_23 = 0 ;
if ( V_19 == NULL )
return - V_24 ;
V_22 = F_7 ( V_19 ) ;
V_10 = V_22 ? F_8 ( V_22 ) : NULL ;
if ( V_10 && V_10 -> V_12 -> V_17 == V_17 )
F_2 ( V_2 , V_10 ) ;
else if ( V_22 )
V_23 = F_9 ( V_22 , true ) ;
V_21 = F_10 ( V_19 ) ;
if ( ! V_21 || V_23 )
return V_23 ;
for ( V_3 = 0 ; V_3 < V_21 -> V_25 ; ++ V_3 ) {
V_22 = F_11 ( V_21 -> V_26 [ V_3 ] ,
F_12 ( V_19 ) ) ;
V_10 = V_22 ? F_8 ( V_22 ) : NULL ;
if ( V_10 && V_10 -> V_12 -> V_17 == V_17 ) {
if ( V_10 -> V_14 != V_14 ||
V_10 -> V_14 == V_27 )
F_2 ( V_2 , V_10 ) ;
} else if ( V_22 ) {
V_23 = F_9 ( V_22 , true ) ;
if ( V_23 )
break;
}
}
return V_23 ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_28 * V_12 )
{
struct V_16 * V_17 = V_12 -> V_17 ;
unsigned V_29 = 0 ;
int V_3 , V_23 ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 ) {
struct V_9 * V_10 = V_2 -> V_7 [ V_3 ] ;
struct V_30 * V_31 ;
struct V_28 * V_11 = V_17 -> V_32 [ V_3 ] ;
if ( ! F_14 ( V_10 , V_12 ) )
continue;
if ( ! V_11 -> V_33 ) {
F_15 ( V_17 -> V_34 , L_1 ) ;
return - V_24 ;
}
if ( V_29 >= V_4 ) {
V_23 = F_16 ( V_10 , false ) ;
if ( V_23 )
return V_23 ;
continue;
}
V_23 = F_17 ( V_17 , & V_31 ) ;
if ( V_23 )
return V_23 ;
V_2 -> V_5 [ V_29 ++ ] = V_31 ;
V_23 = F_18 ( V_11 , 16 ) ;
if ( V_23 )
return V_23 ;
if ( ! F_19 ( V_11 , V_31 ) ) {
F_20 ( V_11 ) ;
V_23 = F_16 ( V_10 , false ) ;
if ( V_23 )
return V_23 ;
continue;
}
if ( ! F_21 ( V_12 , V_31 ) ) {
F_20 ( V_11 ) ;
V_23 = F_16 ( V_10 , false ) ;
if ( V_23 )
return V_23 ;
continue;
}
F_22 ( V_11 ) ;
F_23 ( V_10 , V_12 ) ;
}
return 0 ;
}
void F_24 ( struct V_16 * V_17 ,
struct V_1 * V_2 ,
struct V_9 * V_10 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 )
F_25 ( V_17 , & V_2 -> V_5 [ V_3 ] , V_10 ) ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 )
F_5 ( & V_2 -> V_7 [ V_3 ] ) ;
F_5 ( & V_2 -> V_8 ) ;
}
