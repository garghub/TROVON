static void F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
const T_1 * V_5 , * V_6 , * V_7 ;
const T_1 * V_8 , * V_9 , * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = & ( * V_4 ) -> V_14 ;
V_14 -> V_15 = F_2 ( V_2 , L_1 , NULL ) ;
V_5 = F_2 ( V_2 , L_2 , NULL ) ;
if ( V_5 )
V_14 -> V_5 = F_3 ( * V_5 ) ;
V_6 = F_2 ( V_2 , L_3 , NULL ) ;
if ( V_6 )
V_14 -> V_6 = F_3 ( * V_6 ) ;
if ( V_14 -> V_5 != V_14 -> V_6 )
V_14 -> V_16 |= V_17 ;
if ( V_5 && V_6 && V_14 -> V_5 == V_14 -> V_6 )
V_14 -> V_18 = true ;
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
V_14 -> V_16 |= V_19 ;
if ( F_4 ( V_2 , L_7 , NULL ) )
V_14 -> V_20 = true ;
if ( F_4 ( V_2 , L_8 , NULL ) )
V_14 -> V_21 = true ;
else
V_14 -> V_16 |= V_22 ;
if ( F_5 ( V_2 , L_9 ) )
V_14 -> V_16 |= V_23 ;
V_12 = F_4 ( V_2 , L_10 , NULL ) ;
if ( V_12 && V_12 -> V_24 ) {
V_10 = V_12 -> V_24 ;
if ( * V_10 )
V_14 -> V_10 = F_3 ( * V_10 ) ;
else
V_14 -> V_25 = true ;
}
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
int F_8 ( struct V_26 * V_27 , struct V_1 * V_28 ,
struct F_8 * V_30 ,
unsigned int V_31 )
{
unsigned int V_32 = 0 ;
unsigned int V_33 ;
const char * V_15 ;
struct V_1 * V_34 ;
if ( ! V_27 || ! V_28 )
return - V_35 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
struct F_8 * V_36 = & V_30 [ V_33 ] ;
V_36 -> V_4 = NULL ;
V_36 -> V_37 = NULL ;
}
F_9 (node, child) {
V_15 = F_2 ( V_34 ,
L_11 , NULL ) ;
if ( ! V_15 )
V_15 = V_34 -> V_15 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
struct F_8 * V_36 = & V_30 [ V_33 ] ;
if ( V_36 -> V_37 )
continue;
if ( strcmp ( V_36 -> V_15 , V_15 ) )
continue;
V_36 -> V_4 =
F_6 ( V_27 , V_34 ) ;
if ( ! V_36 -> V_4 ) {
F_10 ( V_27 ,
L_12 ,
V_34 -> V_15 ) ;
return - V_35 ;
}
V_36 -> V_37 = V_34 ;
V_32 ++ ;
break;
}
}
return V_32 ;
}
