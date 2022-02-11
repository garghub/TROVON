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
static int F_5 ( struct V_17 * V_7 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_18 * V_15 ;
V_6 -> V_14 [ V_6 -> V_13 ] = V_2 ;
V_6 -> V_19 [ V_6 -> V_20 ++ ] = V_2 -> V_21 ;
F_6 ( V_6 -> V_11 , true ) ;
F_7 ( V_6 -> V_11 , & V_22 ) ;
V_15 = F_8 ( V_7 -> V_7 , sizeof( * V_15 ) ,
V_23 ) ;
if ( ! V_15 )
return - V_24 ;
if ( V_2 -> V_25 ) {
V_6 -> V_15 [ V_6 -> V_13 ] =
V_2 -> V_25 ;
* V_15 = * V_6 -> V_15 [ V_6 -> V_13 ] ;
} else {
V_6 -> V_15 [ V_6 -> V_13 ] = F_9 ( - V_26 ) ;
}
V_15 -> V_16 = F_1 ;
F_10 ( V_2 , V_15 ) ;
V_6 -> V_13 ++ ;
F_11 ( V_7 -> V_7 , L_1 ,
V_2 -> V_21 -> V_27 ) ;
return 0 ;
}
int F_12 ( struct V_17 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_1 * V_2 ;
int V_28 = V_6 -> V_13 ;
F_13 (connector, &dev->mode_config.connector_list, head) {
bool V_29 = false ;
int V_10 , V_9 ;
for ( V_10 = 0 ; V_10 < V_28 ; V_10 ++ )
if ( V_2 == V_6 -> V_14 [ V_10 ] )
V_29 = true ;
if ( ! V_29 ) {
V_9 = F_5 ( V_7 , V_2 ) ;
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
static int F_15 ( struct V_30 * V_7 , void * V_31 )
{
return V_7 -> V_32 == V_31 ;
}
int F_16 ( struct V_30 * V_7 ,
struct V_33 * * V_34 )
{
struct V_35 * V_36 ;
struct V_35 * V_37 = NULL ;
int V_38 = 0 ;
V_36 = F_17 ( V_7 -> V_32 , L_2 ) ;
if ( ! V_36 )
V_36 = F_17 ( V_7 -> V_32 , L_3 ) ;
if ( ! V_36 )
return 0 ;
F_18 ( V_36 ) ;
while ( ( V_37 = F_19 ( V_7 -> V_32 , V_37 ) ) ) {
V_36 = F_20 ( V_37 ) ;
if ( ! V_36 || ! F_21 ( V_36 ) ) {
F_18 ( V_36 ) ;
continue;
}
F_11 ( V_7 , L_4 , V_36 -> V_27 ) ;
if ( V_34 )
F_22 ( V_7 , V_34 , F_15 , V_36 ) ;
F_18 ( V_36 ) ;
V_38 ++ ;
}
if ( V_38 > 1 ) {
F_23 ( V_7 , L_5 ) ;
return - V_39 ;
}
return V_38 ;
}
