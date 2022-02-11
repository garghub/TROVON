static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
int V_9 , V_10 ;
V_9 = F_2 ( V_6 -> V_11 , V_4 ) ;
if ( V_9 != V_12 )
return V_9 ;
for ( V_10 = 0 ; V_10 < V_6 -> V_13 &&
V_6 -> V_14 [ V_10 ] != V_2 ; V_10 ++ )
;
F_3 ( V_6 -> V_14 [ V_10 ] != V_2 ) ;
F_3 ( ! V_6 -> V_15 [ V_10 ] ) ;
if ( ! F_4 ( V_6 -> V_15 [ V_10 ] ) &&
V_6 -> V_15 [ V_10 ] -> V_16 )
return V_6 -> V_15 [ V_10 ] -> V_16 ( V_2 , V_4 ) ;
return V_12 ;
}
static int F_5 ( struct V_17 * V_7 , int * V_18 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_19 * V_15 ;
V_6 -> V_14 [ V_6 -> V_13 ] = V_2 ;
V_6 -> V_20 [ V_6 -> V_21 ++ ] = V_2 -> V_22 ;
F_6 ( V_6 -> V_11 , true ) ;
F_7 ( V_6 -> V_11 , & V_23 ) ;
* V_18 = V_23 . V_18 ;
V_15 = F_8 ( V_7 -> V_7 , sizeof( * V_15 ) ,
V_24 ) ;
if ( ! V_15 )
return - V_25 ;
if ( V_2 -> V_26 ) {
V_6 -> V_15 [ V_6 -> V_13 ] =
V_2 -> V_26 ;
* V_15 = * V_6 -> V_15 [ V_6 -> V_13 ] ;
} else {
V_6 -> V_15 [ V_6 -> V_13 ] = F_9 ( - V_27 ) ;
}
V_15 -> V_16 = F_1 ;
F_10 ( V_2 , V_15 ) ;
V_6 -> V_13 ++ ;
F_11 ( V_7 -> V_7 , L_1 ,
V_2 -> V_22 -> V_28 ) ;
return 0 ;
}
int F_12 ( struct V_17 * V_7 , int * V_18 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_1 * V_2 ;
int V_29 = V_6 -> V_13 ;
F_13 (connector, &dev->mode_config.connector_list, head) {
bool V_30 = false ;
int V_10 , V_9 ;
for ( V_10 = 0 ; V_10 < V_29 ; V_10 ++ )
if ( V_2 == V_6 -> V_14 [ V_10 ] )
V_30 = true ;
if ( ! V_30 ) {
V_9 = F_5 ( V_7 , V_18 , V_2 ) ;
if ( V_9 )
return V_9 ;
}
}
return 0 ;
}
void F_14 ( struct V_17 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_6 -> V_13 ; V_10 ++ )
if ( F_4 ( V_6 -> V_15 [ V_10 ] ) )
F_10 ( V_6 -> V_14 [ V_10 ] , NULL ) ;
else if ( V_6 -> V_15 [ V_10 ] )
F_10 ( V_6 -> V_14 [ V_10 ] ,
V_6 -> V_15 [ V_10 ] ) ;
}
static int F_15 ( struct V_31 * V_7 , void * V_32 )
{
return V_7 -> V_33 == V_32 ;
}
int F_16 ( struct V_31 * V_7 ,
struct V_34 * * V_35 )
{
struct V_36 * V_37 = NULL ;
int V_38 = 0 ;
while ( ( V_37 = F_17 ( V_7 -> V_33 , V_37 ) ) ) {
struct V_36 * V_39 ;
V_39 = F_18 ( V_37 ) ;
if ( ! V_39 && ! F_19 ( V_39 ) ) {
F_20 ( V_39 ) ;
continue;
}
F_11 ( V_7 , L_2 , V_39 -> V_28 ) ;
if ( V_35 )
F_21 ( V_7 , V_35 , F_15 , V_39 ) ;
F_20 ( V_39 ) ;
V_38 ++ ;
}
if ( V_38 > 1 ) {
F_22 ( V_7 , L_3 ) ;
return - V_40 ;
}
return V_38 ;
}
