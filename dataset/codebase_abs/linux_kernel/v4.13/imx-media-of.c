static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_5 * V_7 ,
int V_8 , int V_9 )
{
F_2 ( V_2 -> V_10 . V_11 , L_1 , V_12 ,
V_6 -> V_13 , V_8 ,
V_7 -> V_13 , V_9 ) ;
return F_3 ( V_2 , V_4 , V_7 , NULL ,
V_8 , V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_5 * V_16 )
{
struct V_5 * V_17 ;
V_17 = F_5 ( V_16 , NULL ) ;
if ( V_17 ) {
F_6 ( F_7 ( V_17 ) ,
& V_15 -> V_18 ) ;
F_8 ( V_17 ) ;
}
}
static int F_9 ( const struct V_5 * V_19 )
{
struct V_5 * V_20 , * V_21 ;
int V_22 = 0 ;
V_20 = F_10 ( V_19 , L_2 ) ;
if ( V_20 )
V_19 = V_20 ;
F_11 (np, child)
if ( F_12 ( V_21 -> V_13 , L_3 ) == 0 )
V_22 ++ ;
F_8 ( V_20 ) ;
return V_22 ;
}
static void F_13 ( struct V_5 * V_23 ,
struct V_5 * * V_24 ,
int * V_9 )
{
struct V_5 * V_25 , * V_26 ;
struct V_5 * V_27 ;
V_25 = F_14 ( V_23 ) ;
V_26 = F_15 ( V_23 ) ;
if ( F_16 ( V_26 , L_4 ) ) {
V_27 = V_25 ;
* V_9 = 0 ;
F_8 ( V_26 ) ;
} else {
V_27 = V_26 ;
if ( F_17 ( V_25 , L_5 , V_9 ) )
* V_9 = 0 ;
F_8 ( V_25 ) ;
}
if ( ! F_18 ( V_27 ) ) {
F_8 ( V_27 ) ;
* V_24 = NULL ;
} else {
* V_24 = V_27 ;
}
}
static struct V_14 *
F_19 ( struct V_1 * V_2 , struct V_5 * V_28 ,
bool V_29 )
{
struct V_14 * V_30 ;
int V_31 , V_32 , V_33 ;
if ( ! F_18 ( V_28 ) ) {
F_2 ( V_2 -> V_10 . V_11 , L_6 , V_12 ,
V_28 -> V_13 ) ;
return NULL ;
}
V_30 = F_20 ( V_2 , V_28 , NULL ) ;
if ( F_21 ( V_30 ) )
return V_30 ;
if ( V_29 ) {
V_32 = V_34 ;
V_30 -> V_35 = V_36 ;
} else if ( F_16 ( V_28 , L_7 ) ) {
V_32 = F_9 ( V_28 ) ;
V_30 -> V_35 = 1 ;
} else if ( F_16 ( V_28 , L_8 ) ) {
V_32 = F_9 ( V_28 ) ;
V_30 -> V_35 = V_32 - 1 ;
} else {
V_32 = F_9 ( V_28 ) ;
if ( V_32 != 1 ) {
F_22 ( V_2 -> V_10 . V_11 ,
L_9 ,
V_12 , V_28 -> V_13 , V_32 ) ;
return NULL ;
}
V_30 -> V_35 = 0 ;
}
if ( V_30 -> V_35 >= V_32 )
return F_23 ( - V_37 ) ;
V_30 -> V_38 = V_32 - V_30 -> V_35 ;
F_2 ( V_2 -> V_10 . V_11 , L_10 ,
V_12 , V_28 -> V_13 , V_32 ,
V_30 -> V_35 , V_30 -> V_38 ) ;
if ( V_30 -> V_35 == 0 )
F_4 ( V_2 , V_30 , V_28 ) ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
struct V_5 * V_23 = NULL , * V_39 , * V_40 ;
struct V_14 * V_41 ;
struct V_3 * V_4 ;
int V_9 ;
V_4 = & V_30 -> V_4 [ V_31 ] ;
V_4 -> V_4 . V_42 = ( V_31 < V_30 -> V_35 ) ?
V_43 : V_44 ;
if ( V_29 )
V_39 = ( V_31 < V_30 -> V_35 ) ? V_28 : NULL ;
else
V_39 = F_24 ( V_28 , V_31 ) ;
if ( ! V_39 )
continue;
F_11 (port, epnode) {
F_13 ( V_23 , & V_40 , & V_9 ) ;
if ( ! V_40 )
continue;
V_33 = F_1 ( V_2 , V_4 , V_28 , V_40 ,
V_31 , V_9 ) ;
if ( V_33 ) {
V_30 = F_23 ( V_33 ) ;
break;
}
if ( V_31 < V_30 -> V_35 ) {
V_41 = F_19 ( V_2 ,
V_40 ,
false ) ;
if ( F_25 ( V_41 ) ) {
V_30 = V_41 ;
break;
}
}
F_8 ( V_40 ) ;
}
if ( V_39 != V_28 )
F_8 ( V_39 ) ;
if ( F_25 ( V_30 ) ) {
F_8 ( V_40 ) ;
F_8 ( V_23 ) ;
break;
}
}
return V_30 ;
}
