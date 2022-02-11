static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 -> V_4 , 0 ) ;
F_3 ( 10000 , 15000 ) ;
F_2 ( V_3 -> V_4 , 1 ) ;
F_3 ( 80000 , 85000 ) ;
if ( V_3 -> V_5 -> V_6 == 0 && V_3 -> V_7 == 0 ) {
F_4 ( V_3 -> V_8 -> V_9 ) ;
V_3 -> V_7 = true ;
}
return 0 ;
}
static void F_5 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_6 ( V_3 -> V_8 -> V_9 ) ;
V_3 -> V_7 = false ;
}
static int F_7 ( void * V_1 , struct V_10 * V_11 )
{
int V_12 = - 1 ;
struct V_2 * V_3 = V_1 ;
struct V_13 * V_14 = V_3 -> V_8 ;
if ( V_3 -> V_5 -> V_15 != 0 )
return V_3 -> V_5 -> V_15 ;
V_12 = F_8 ( V_14 , V_11 -> V_16 , V_11 -> V_17 ) ;
if ( V_12 < 0 ) {
F_3 ( 1000 , 4000 ) ;
V_12 = F_8 ( V_14 , V_11 -> V_16 , V_11 -> V_17 ) ;
}
if ( V_12 >= 0 ) {
if ( V_12 != V_11 -> V_17 )
V_12 = - V_18 ;
else
V_12 = 0 ;
}
return V_12 ;
}
static int F_9 ( struct V_2 * V_3 ,
struct V_10 * * V_11 )
{
int V_12 ;
T_1 V_17 ;
T_1 V_19 [ V_20 ] ;
struct V_13 * V_14 = V_3 -> V_8 ;
V_12 = F_10 ( V_14 , V_19 , V_21 ) ;
if ( V_12 < 0 ) {
F_3 ( 1000 , 4000 ) ;
V_12 = F_10 ( V_14 , V_19 , V_21 ) ;
}
if ( V_12 != V_21 )
return - V_18 ;
V_17 = F_11 ( * ( V_22 * ) ( V_19 + 2 ) ) ;
if ( V_17 > V_20 ) {
F_12 ( & V_14 -> V_23 , L_1 ) ;
return - V_24 ;
}
* V_11 = F_13 ( V_21 + V_17 , V_25 ) ;
if ( * V_11 == NULL )
return - V_26 ;
F_14 ( * V_11 , V_21 ) ;
F_15 ( * V_11 , V_21 ) ;
memcpy ( ( * V_11 ) -> V_16 , V_19 , V_21 ) ;
if ( ! V_17 )
return 0 ;
V_12 = F_10 ( V_14 , V_19 , V_17 ) ;
if ( V_12 != V_17 ) {
F_16 ( * V_11 ) ;
return - V_18 ;
}
F_15 ( * V_11 , V_17 ) ;
memcpy ( ( * V_11 ) -> V_16 + V_21 , V_19 , V_17 ) ;
return 0 ;
}
static T_2 F_17 ( int V_9 , void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_13 * V_14 ;
struct V_10 * V_11 = NULL ;
int V_12 ;
if ( ! V_3 || ! V_3 -> V_5 || V_9 != V_3 -> V_8 -> V_9 ) {
F_18 ( 1 ) ;
return V_27 ;
}
V_14 = V_3 -> V_8 ;
F_19 ( & V_14 -> V_23 , L_2 ) ;
if ( V_3 -> V_5 -> V_15 )
return V_28 ;
if ( ! V_3 -> V_5 -> V_6 ) {
F_5 ( V_3 ) ;
return V_28 ;
}
V_12 = F_9 ( V_3 , & V_11 ) ;
if ( V_12 == - V_18 || V_12 == - V_26 || V_12 == - V_24 )
return V_28 ;
F_20 ( V_3 -> V_5 , V_11 ) ;
return V_28 ;
}
static int F_21 ( struct V_13 * V_14 ,
const struct V_29 * V_30 )
{
struct V_31 * V_23 = & V_14 -> V_23 ;
struct V_2 * V_3 ;
int V_12 ;
F_19 ( & V_14 -> V_23 , L_3 , V_32 ) ;
F_19 ( & V_14 -> V_23 , L_4 , V_14 -> V_9 ) ;
if ( ! F_22 ( V_14 -> V_33 , V_34 ) ) {
F_12 ( & V_14 -> V_23 , L_5 ) ;
return - V_35 ;
}
V_3 = F_23 ( V_23 , sizeof( struct V_2 ) , V_25 ) ;
if ( ! V_3 )
return - V_26 ;
V_3 -> V_8 = V_14 ;
F_24 ( V_14 , V_3 ) ;
V_12 = F_25 ( V_23 , V_36 ) ;
if ( V_12 )
F_19 ( V_23 , L_6 ) ;
V_3 -> V_4 = F_26 ( V_23 , L_7 , V_37 ) ;
if ( F_27 ( V_3 -> V_4 ) ) {
F_12 ( V_23 , L_8 ) ;
return - V_35 ;
}
V_3 -> V_38 . V_39 =
F_28 ( V_23 , L_9 ) ;
V_3 -> V_38 . V_40 =
F_28 ( V_23 , L_10 ) ;
V_12 = F_29 ( V_3 , & V_41 , & V_14 -> V_23 ,
V_42 , V_43 ,
& V_3 -> V_5 , & V_3 -> V_38 ) ;
if ( V_12 < 0 ) {
F_12 ( & V_14 -> V_23 , L_11 ) ;
return V_12 ;
}
V_3 -> V_7 = true ;
V_12 = F_30 ( & V_14 -> V_23 , V_14 -> V_9 , NULL ,
F_17 ,
V_44 ,
V_45 , V_3 ) ;
if ( V_12 < 0 )
F_12 ( & V_14 -> V_23 , L_12 ) ;
return V_12 ;
}
static int F_31 ( struct V_13 * V_14 )
{
struct V_2 * V_3 = F_32 ( V_14 ) ;
F_19 ( & V_14 -> V_23 , L_3 , V_32 ) ;
F_33 ( V_3 -> V_5 ) ;
return 0 ;
}
