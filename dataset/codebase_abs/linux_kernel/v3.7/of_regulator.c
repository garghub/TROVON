static void F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
const T_1 * V_5 , * V_6 , * V_7 ;
const T_1 * V_8 , * V_9 , * V_10 ;
struct V_11 * V_12 = & ( * V_4 ) -> V_12 ;
V_12 -> V_13 = F_2 ( V_2 , L_1 , NULL ) ;
V_5 = F_2 ( V_2 , L_2 , NULL ) ;
if ( V_5 )
V_12 -> V_5 = F_3 ( * V_5 ) ;
V_6 = F_2 ( V_2 , L_3 , NULL ) ;
if ( V_6 )
V_12 -> V_6 = F_3 ( * V_6 ) ;
if ( V_12 -> V_5 != V_12 -> V_6 )
V_12 -> V_14 |= V_15 ;
if ( V_5 && V_6 && V_12 -> V_5 == V_12 -> V_6 )
V_12 -> V_16 = true ;
V_7 = F_2 ( V_2 , L_4 , NULL ) ;
if ( V_7 )
V_12 -> V_7 = F_3 ( * V_7 ) ;
V_8 = F_2 ( V_2 , L_5 , NULL ) ;
if ( V_8 )
V_12 -> V_8 = F_3 ( * V_8 ) ;
V_9 = F_2 ( V_2 , L_6 , NULL ) ;
if ( V_9 )
V_12 -> V_9 = F_3 ( * V_9 ) ;
if ( V_12 -> V_8 != V_12 -> V_9 )
V_12 -> V_14 |= V_17 ;
if ( F_4 ( V_2 , L_7 , NULL ) )
V_12 -> V_18 = true ;
if ( F_4 ( V_2 , L_8 , NULL ) )
V_12 -> V_19 = true ;
else
V_12 -> V_14 |= V_20 ;
V_10 = F_2 ( V_2 , L_9 , NULL ) ;
if ( V_10 )
V_12 -> V_10 = F_3 ( * V_10 ) ;
}
struct V_3 * F_5 ( struct V_21 * V_22 ,
struct V_1 * V_23 )
{
struct V_3 * V_4 ;
if ( ! V_23 )
return NULL ;
V_4 = F_6 ( V_22 , sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 )
return NULL ;
F_1 ( V_23 , & V_4 ) ;
return V_4 ;
}
int F_7 ( struct V_21 * V_22 , struct V_1 * V_23 ,
struct F_7 * V_25 ,
unsigned int V_26 )
{
unsigned int V_27 = 0 ;
unsigned int V_28 ;
const char * V_13 ;
struct V_1 * V_29 ;
if ( ! V_22 || ! V_23 )
return - V_30 ;
F_8 (node, child) {
V_13 = F_2 ( V_29 ,
L_10 , NULL ) ;
if ( ! V_13 )
V_13 = V_29 -> V_13 ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
struct F_7 * V_31 = & V_25 [ V_28 ] ;
if ( V_31 -> V_32 )
continue;
if ( strcmp ( V_31 -> V_13 , V_13 ) )
continue;
V_31 -> V_4 =
F_5 ( V_22 , V_29 ) ;
if ( ! V_31 -> V_4 ) {
F_9 ( V_22 ,
L_11 ,
V_29 -> V_13 ) ;
return - V_30 ;
}
V_31 -> V_32 = V_29 ;
V_27 ++ ;
break;
}
}
return V_27 ;
}
