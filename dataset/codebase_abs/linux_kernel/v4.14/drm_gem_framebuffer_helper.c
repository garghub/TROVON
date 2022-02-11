struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
if ( V_4 >= 4 )
return NULL ;
return V_3 -> V_5 [ V_4 ] ;
}
static struct V_2 *
F_2 ( struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_1 * * V_5 , unsigned int V_10 ,
const struct V_11 * V_12 )
{
struct V_2 * V_3 ;
int V_13 , V_14 ;
V_3 = F_3 ( sizeof( * V_3 ) , V_15 ) ;
if ( ! V_3 )
return F_4 ( - V_16 ) ;
F_5 ( V_7 , V_3 , V_9 ) ;
for ( V_14 = 0 ; V_14 < V_10 ; V_14 ++ )
V_3 -> V_5 [ V_14 ] = V_5 [ V_14 ] ;
V_13 = F_6 ( V_7 , V_3 , V_12 ) ;
if ( V_13 ) {
F_7 ( V_7 -> V_7 , L_1 ,
V_13 ) ;
F_8 ( V_3 ) ;
return F_4 ( V_13 ) ;
}
return V_3 ;
}
void F_9 ( struct V_2 * V_3 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ )
F_10 ( V_3 -> V_5 [ V_14 ] ) ;
F_11 ( V_3 ) ;
F_8 ( V_3 ) ;
}
int F_12 ( struct V_2 * V_3 , struct V_17 * V_18 ,
unsigned int * V_19 )
{
return F_13 ( V_18 , V_3 -> V_5 [ 0 ] , V_19 ) ;
}
struct V_2 *
F_14 ( struct V_6 * V_7 , struct V_17 * V_18 ,
const struct V_8 * V_9 ,
const struct V_11 * V_12 )
{
const struct V_20 * V_21 ;
struct V_1 * V_22 [ 4 ] ;
struct V_2 * V_3 ;
int V_13 , V_14 ;
V_21 = F_15 ( V_7 , V_9 ) ;
if ( ! V_21 )
return F_4 ( - V_23 ) ;
for ( V_14 = 0 ; V_14 < V_21 -> V_10 ; V_14 ++ ) {
unsigned int V_24 = V_9 -> V_24 / ( V_14 ? V_21 -> V_25 : 1 ) ;
unsigned int V_26 = V_9 -> V_26 / ( V_14 ? V_21 -> V_27 : 1 ) ;
unsigned int V_28 ;
V_22 [ V_14 ] = F_16 ( V_18 , V_9 -> V_29 [ V_14 ] ) ;
if ( ! V_22 [ V_14 ] ) {
F_7 ( V_7 -> V_7 , L_2 ) ;
V_13 = - V_30 ;
goto V_31;
}
V_28 = ( V_26 - 1 ) * V_9 -> V_32 [ V_14 ]
+ V_24 * V_21 -> V_33 [ V_14 ]
+ V_9 -> V_34 [ V_14 ] ;
if ( V_22 [ V_14 ] -> V_35 < V_28 ) {
F_10 ( V_22 [ V_14 ] ) ;
V_13 = - V_23 ;
goto V_31;
}
}
V_3 = F_2 ( V_7 , V_9 , V_22 , V_14 , V_12 ) ;
if ( F_17 ( V_3 ) ) {
V_13 = F_18 ( V_3 ) ;
goto V_31;
}
return V_3 ;
V_31:
for ( V_14 -- ; V_14 >= 0 ; V_14 -- )
F_10 ( V_22 [ V_14 ] ) ;
return F_4 ( V_13 ) ;
}
struct V_2 *
F_19 ( struct V_6 * V_7 , struct V_17 * V_18 ,
const struct V_8 * V_9 )
{
return F_14 ( V_7 , V_18 , V_9 ,
& V_36 ) ;
}
int F_20 ( struct V_37 * V_4 ,
struct V_38 * V_39 )
{
struct V_40 * V_40 ;
struct V_41 * V_42 ;
if ( ( V_4 -> V_39 -> V_3 == V_39 -> V_3 ) || ! V_39 -> V_3 )
return 0 ;
V_40 = F_1 ( V_39 -> V_3 , 0 ) -> V_40 ;
if ( V_40 ) {
V_42 = F_21 ( V_40 -> V_43 ) ;
F_22 ( V_39 , V_42 ) ;
}
return 0 ;
}
struct V_2 *
F_23 ( struct V_6 * V_7 ,
struct V_44 * V_45 ,
unsigned int V_46 , struct V_1 * V_5 ,
const struct V_11 * V_12 )
{
struct V_8 V_9 = { 0 } ;
V_9 . V_24 = V_45 -> V_47 ;
V_9 . V_26 = V_45 -> V_48 ;
V_9 . V_32 [ 0 ] = V_45 -> V_47 *
F_24 ( V_45 -> V_49 , 8 ) ;
if ( V_46 )
V_9 . V_32 [ 0 ] = F_25 ( V_9 . V_32 [ 0 ] ,
V_46 ) ;
V_9 . V_50 = F_26 ( V_45 -> V_49 ,
V_45 -> V_51 ) ;
if ( V_5 -> V_35 < V_9 . V_32 [ 0 ] * V_9 . V_26 )
return F_4 ( - V_23 ) ;
return F_2 ( V_7 , & V_9 , & V_5 , 1 , V_12 ) ;
}
