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
static int F_21 ( struct V_13 * V_14 )
{
struct V_2 * V_3 = F_22 ( V_14 ) ;
struct V_29 * V_30 ;
int V_31 ;
int V_12 ;
V_30 = V_14 -> V_23 . V_32 ;
if ( ! V_30 )
return - V_33 ;
V_31 = F_23 ( V_30 , L_3 , 0 ) ;
if ( V_31 < 0 ) {
F_12 ( & V_14 -> V_23 ,
L_4 ) ;
return V_31 ;
}
V_12 = F_24 ( & V_14 -> V_23 , V_31 ,
V_34 , L_5 ) ;
if ( V_12 ) {
F_12 ( & V_14 -> V_23 , L_6 ) ;
return V_12 ;
}
V_3 -> V_4 = V_31 ;
V_3 -> V_35 = F_25 ( V_14 -> V_9 ) ;
V_3 -> V_36 . V_37 =
F_26 ( V_30 , L_7 ) ;
V_3 -> V_36 . V_38 =
F_26 ( V_30 , L_8 ) ;
return 0 ;
}
static int F_21 ( struct V_13 * V_14 )
{
return - V_33 ;
}
static int F_27 ( struct V_13 * V_14 )
{
struct V_39 * V_40 ;
struct V_2 * V_3 = F_22 ( V_14 ) ;
int V_12 ;
V_40 = V_14 -> V_23 . V_41 ;
if ( V_40 == NULL ) {
F_12 ( & V_14 -> V_23 , L_9 ) ;
return - V_42 ;
}
V_3 -> V_4 = V_40 -> V_4 ;
V_3 -> V_35 = V_40 -> V_35 ;
V_12 = F_24 ( & V_14 -> V_23 ,
V_3 -> V_4 , V_34 , L_5 ) ;
if ( V_12 ) {
F_28 ( L_10 , __FILE__ ) ;
return V_12 ;
}
V_3 -> V_36 . V_37 = V_40 -> V_37 ;
V_3 -> V_36 . V_38 = V_40 -> V_38 ;
return 0 ;
}
static int F_29 ( struct V_13 * V_14 ,
const struct V_43 * V_44 )
{
struct V_2 * V_3 ;
struct V_39 * V_40 ;
int V_12 ;
F_19 ( & V_14 -> V_23 , L_11 , V_45 ) ;
F_19 ( & V_14 -> V_23 , L_12 , V_14 -> V_9 ) ;
if ( ! F_30 ( V_14 -> V_46 , V_47 ) ) {
F_12 ( & V_14 -> V_23 , L_13 ) ;
return - V_33 ;
}
V_3 = F_31 ( & V_14 -> V_23 , sizeof( struct V_2 ) ,
V_25 ) ;
if ( ! V_3 )
return - V_26 ;
V_3 -> V_8 = V_14 ;
F_32 ( V_14 , V_3 ) ;
V_40 = V_14 -> V_23 . V_41 ;
if ( ! V_40 && V_14 -> V_23 . V_32 ) {
V_12 = F_21 ( V_14 ) ;
if ( V_12 ) {
F_12 ( & V_14 -> V_23 , L_9 ) ;
return V_12 ;
}
} else if ( V_40 ) {
V_12 = F_27 ( V_14 ) ;
if ( V_12 ) {
F_12 ( & V_14 -> V_23 ,
L_14 ) ;
return V_12 ;
}
} else {
F_12 ( & V_14 -> V_23 ,
L_15 ) ;
return - V_33 ;
}
V_12 = F_33 ( V_3 , & V_48 , & V_14 -> V_23 ,
V_49 , V_50 ,
& V_3 -> V_5 , & V_3 -> V_36 ) ;
if ( V_12 < 0 ) {
F_12 ( & V_14 -> V_23 , L_16 ) ;
return V_12 ;
}
V_3 -> V_7 = true ;
V_12 = F_34 ( & V_14 -> V_23 , V_14 -> V_9 , NULL ,
F_17 ,
V_3 -> V_35 | V_51 ,
V_52 , V_3 ) ;
if ( V_12 < 0 )
F_12 ( & V_14 -> V_23 , L_17 ) ;
return V_12 ;
}
static int F_35 ( struct V_13 * V_14 )
{
struct V_2 * V_3 = F_22 ( V_14 ) ;
F_19 ( & V_14 -> V_23 , L_11 , V_45 ) ;
F_36 ( V_3 -> V_5 ) ;
return 0 ;
}
