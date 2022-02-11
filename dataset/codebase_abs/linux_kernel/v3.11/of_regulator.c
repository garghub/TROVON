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
if ( F_5 ( V_2 , L_9 ) )
V_12 -> V_14 |= V_21 ;
V_10 = F_2 ( V_2 , L_10 , NULL ) ;
if ( V_10 )
V_12 -> V_10 = F_3 ( * V_10 ) ;
}
struct V_3 * F_6 ( struct V_22 * V_23 ,
struct V_1 * V_24 )
{
struct V_3 * V_4 ;
if ( ! V_24 )
return NULL ;
V_4 = F_7 ( V_23 , sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 )
return NULL ;
F_1 ( V_24 , & V_4 ) ;
return V_4 ;
}
int F_8 ( struct V_22 * V_23 , struct V_1 * V_24 ,
struct F_8 * V_26 ,
unsigned int V_27 )
{
unsigned int V_28 = 0 ;
unsigned int V_29 ;
const char * V_13 ;
struct V_1 * V_30 ;
if ( ! V_23 || ! V_24 )
return - V_31 ;
for ( V_29 = 0 ; V_29 < V_27 ; V_29 ++ ) {
struct F_8 * V_32 = & V_26 [ V_29 ] ;
V_32 -> V_4 = NULL ;
V_32 -> V_33 = NULL ;
}
F_9 (node, child) {
V_13 = F_2 ( V_30 ,
L_11 , NULL ) ;
if ( ! V_13 )
V_13 = V_30 -> V_13 ;
for ( V_29 = 0 ; V_29 < V_27 ; V_29 ++ ) {
struct F_8 * V_32 = & V_26 [ V_29 ] ;
if ( V_32 -> V_33 )
continue;
if ( strcmp ( V_32 -> V_13 , V_13 ) )
continue;
V_32 -> V_4 =
F_6 ( V_23 , V_30 ) ;
if ( ! V_32 -> V_4 ) {
F_10 ( V_23 ,
L_12 ,
V_30 -> V_13 ) ;
return - V_31 ;
}
V_32 -> V_33 = V_30 ;
V_28 ++ ;
break;
}
}
return V_28 ;
}
