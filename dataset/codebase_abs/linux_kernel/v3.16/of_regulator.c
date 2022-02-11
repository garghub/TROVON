static void F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
const T_1 * V_5 , * V_6 ;
struct V_7 * V_8 = & ( * V_4 ) -> V_8 ;
int V_9 ;
T_2 V_10 ;
V_8 -> V_11 = F_2 ( V_2 , L_1 , NULL ) ;
V_5 = F_2 ( V_2 , L_2 , NULL ) ;
if ( V_5 )
V_8 -> V_5 = F_3 ( * V_5 ) ;
V_6 = F_2 ( V_2 , L_3 , NULL ) ;
if ( V_6 )
V_8 -> V_6 = F_3 ( * V_6 ) ;
if ( V_8 -> V_5 != V_8 -> V_6 )
V_8 -> V_12 |= V_13 ;
if ( V_5 && V_6 && V_8 -> V_5 == V_8 -> V_6 )
V_8 -> V_14 = true ;
if ( ! F_4 ( V_2 , L_4 , & V_10 ) )
V_8 -> V_15 = V_10 ;
if ( ! F_4 ( V_2 , L_5 , & V_10 ) )
V_8 -> V_16 = V_10 ;
if ( ! F_4 ( V_2 , L_6 , & V_10 ) )
V_8 -> V_17 = V_10 ;
if ( V_8 -> V_16 != V_8 -> V_17 )
V_8 -> V_12 |= V_18 ;
V_8 -> V_19 = F_5 ( V_2 , L_7 ) ;
V_8 -> V_20 = F_5 ( V_2 , L_8 ) ;
if ( ! V_8 -> V_20 )
V_8 -> V_12 |= V_21 ;
if ( F_5 ( V_2 , L_9 ) )
V_8 -> V_12 |= V_22 ;
V_9 = F_4 ( V_2 , L_10 , & V_10 ) ;
if ( ! V_9 ) {
if ( V_10 )
V_8 -> V_23 = V_10 ;
else
V_8 -> V_24 = true ;
}
V_9 = F_4 ( V_2 , L_11 , & V_10 ) ;
if ( ! V_9 )
V_8 -> V_25 = V_10 ;
}
struct V_3 * F_6 ( struct V_26 * V_27 ,
struct V_1 * V_28 )
{
struct V_3 * V_4 ;
if ( ! V_28 )
return NULL ;
V_4 = F_7 ( V_27 , sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
return NULL ;
F_1 ( V_28 , & V_4 ) ;
return V_4 ;
}
static void F_8 ( struct V_26 * V_27 , void * V_30 )
{
struct V_31 * V_32 = V_30 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_32 -> V_34 ; V_33 ++ )
F_9 ( V_32 -> V_35 [ V_33 ] . V_36 ) ;
}
int F_10 ( struct V_26 * V_27 , struct V_1 * V_28 ,
struct F_10 * V_35 ,
unsigned int V_34 )
{
unsigned int V_37 = 0 ;
unsigned int V_33 ;
const char * V_11 ;
struct V_1 * V_38 ;
struct V_31 * V_32 ;
if ( ! V_27 || ! V_28 )
return - V_39 ;
V_32 = F_11 ( F_8 ,
sizeof( struct V_31 ) ,
V_29 ) ;
if ( ! V_32 )
return - V_40 ;
V_32 -> V_35 = V_35 ;
V_32 -> V_34 = V_34 ;
F_12 ( V_27 , V_32 ) ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
struct F_10 * V_41 = & V_35 [ V_33 ] ;
V_41 -> V_4 = NULL ;
V_41 -> V_36 = NULL ;
}
F_13 (node, child) {
V_11 = F_2 ( V_38 ,
L_12 , NULL ) ;
if ( ! V_11 )
V_11 = V_38 -> V_11 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
struct F_10 * V_41 = & V_35 [ V_33 ] ;
if ( V_41 -> V_36 )
continue;
if ( strcmp ( V_41 -> V_11 , V_11 ) )
continue;
V_41 -> V_4 =
F_6 ( V_27 , V_38 ) ;
if ( ! V_41 -> V_4 ) {
F_14 ( V_27 ,
L_13 ,
V_38 -> V_11 ) ;
return - V_39 ;
}
V_41 -> V_36 = F_15 ( V_38 ) ;
V_37 ++ ;
break;
}
}
return V_37 ;
}
