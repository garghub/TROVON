static void F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
const T_1 * V_5 , * V_6 , * V_7 ;
const T_1 * V_8 , * V_9 , * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = & ( * V_4 ) -> V_14 ;
int V_15 ;
T_2 V_16 ;
V_14 -> V_17 = F_2 ( V_2 , L_1 , NULL ) ;
V_5 = F_2 ( V_2 , L_2 , NULL ) ;
if ( V_5 )
V_14 -> V_5 = F_3 ( * V_5 ) ;
V_6 = F_2 ( V_2 , L_3 , NULL ) ;
if ( V_6 )
V_14 -> V_6 = F_3 ( * V_6 ) ;
if ( V_14 -> V_5 != V_14 -> V_6 )
V_14 -> V_18 |= V_19 ;
if ( V_5 && V_6 && V_14 -> V_5 == V_14 -> V_6 )
V_14 -> V_20 = true ;
V_7 = F_2 ( V_2 , L_4 , NULL ) ;
if ( V_7 )
V_14 -> V_7 = F_3 ( * V_7 ) ;
V_8 = F_2 ( V_2 , L_5 , NULL ) ;
if ( V_8 )
V_14 -> V_8 = F_3 ( * V_8 ) ;
V_9 = F_2 ( V_2 , L_6 , NULL ) ;
if ( V_9 )
V_14 -> V_9 = F_3 ( * V_9 ) ;
if ( V_14 -> V_8 != V_14 -> V_9 )
V_14 -> V_18 |= V_21 ;
if ( F_4 ( V_2 , L_7 , NULL ) )
V_14 -> V_22 = true ;
if ( F_4 ( V_2 , L_8 , NULL ) )
V_14 -> V_23 = true ;
else
V_14 -> V_18 |= V_24 ;
if ( F_5 ( V_2 , L_9 ) )
V_14 -> V_18 |= V_25 ;
V_12 = F_4 ( V_2 , L_10 , NULL ) ;
if ( V_12 && V_12 -> V_26 ) {
V_10 = V_12 -> V_26 ;
if ( * V_10 )
V_14 -> V_10 = F_3 ( * V_10 ) ;
else
V_14 -> V_27 = true ;
}
V_15 = F_6 ( V_2 , L_11 , & V_16 ) ;
if ( ! V_15 )
V_14 -> V_28 = V_16 ;
}
struct V_3 * F_7 ( struct V_29 * V_30 ,
struct V_1 * V_31 )
{
struct V_3 * V_4 ;
if ( ! V_31 )
return NULL ;
V_4 = F_8 ( V_30 , sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return NULL ;
F_1 ( V_31 , & V_4 ) ;
return V_4 ;
}
int F_9 ( struct V_29 * V_30 , struct V_1 * V_31 ,
struct F_9 * V_33 ,
unsigned int V_34 )
{
unsigned int V_35 = 0 ;
unsigned int V_36 ;
const char * V_17 ;
struct V_1 * V_37 ;
if ( ! V_30 || ! V_31 )
return - V_38 ;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ ) {
struct F_9 * V_39 = & V_33 [ V_36 ] ;
V_39 -> V_4 = NULL ;
V_39 -> V_40 = NULL ;
}
F_10 (node, child) {
V_17 = F_2 ( V_37 ,
L_12 , NULL ) ;
if ( ! V_17 )
V_17 = V_37 -> V_17 ;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ ) {
struct F_9 * V_39 = & V_33 [ V_36 ] ;
if ( V_39 -> V_40 )
continue;
if ( strcmp ( V_39 -> V_17 , V_17 ) )
continue;
V_39 -> V_4 =
F_7 ( V_30 , V_37 ) ;
if ( ! V_39 -> V_4 ) {
F_11 ( V_30 ,
L_13 ,
V_37 -> V_17 ) ;
return - V_38 ;
}
V_39 -> V_40 = V_37 ;
V_35 ++ ;
break;
}
}
return V_35 ;
}
