static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 -> V_4 , 0 ) ;
F_3 ( 10000 , 15000 ) ;
F_2 ( V_3 -> V_4 , 1 ) ;
F_3 ( 80000 , 85000 ) ;
if ( V_3 -> V_5 -> V_6 == 0 )
F_4 ( V_3 -> V_7 -> V_8 ) ;
return 0 ;
}
static void F_5 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_6 ( V_3 -> V_7 -> V_8 ) ;
}
static int F_7 ( void * V_1 , struct V_9 * V_10 )
{
int V_11 = - 1 ;
struct V_2 * V_3 = V_1 ;
struct V_12 * V_13 = V_3 -> V_7 ;
F_8 ( L_1 , V_10 ) ;
if ( V_3 -> V_5 -> V_14 != 0 )
return V_3 -> V_5 -> V_14 ;
V_11 = F_9 ( V_13 , V_10 -> V_15 , V_10 -> V_16 ) ;
if ( V_11 < 0 ) {
F_3 ( 1000 , 4000 ) ;
V_11 = F_9 ( V_13 , V_10 -> V_15 , V_10 -> V_16 ) ;
}
if ( V_11 >= 0 ) {
if ( V_11 != V_10 -> V_16 )
V_11 = - V_17 ;
else
V_11 = 0 ;
}
return V_11 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_9 * * V_10 )
{
int V_11 ;
T_1 V_16 ;
T_1 V_18 [ V_19 ] ;
struct V_12 * V_13 = V_3 -> V_7 ;
V_11 = F_11 ( V_13 , V_18 , V_20 ) ;
if ( V_11 < 0 ) {
F_3 ( 1000 , 4000 ) ;
V_11 = F_11 ( V_13 , V_18 , V_20 ) ;
}
if ( V_11 != V_20 )
return - V_17 ;
V_16 = F_12 ( * ( V_21 * ) ( V_18 + 2 ) ) ;
if ( V_16 > V_19 ) {
F_13 ( & V_13 -> V_22 , L_2 ) ;
return - V_23 ;
}
* V_10 = F_14 ( V_20 + V_16 , V_24 ) ;
if ( * V_10 == NULL )
return - V_25 ;
F_15 ( * V_10 , V_20 ) ;
F_16 ( * V_10 , V_20 ) ;
memcpy ( ( * V_10 ) -> V_15 , V_18 , V_20 ) ;
if ( ! V_16 )
return 0 ;
V_11 = F_11 ( V_13 , V_18 , V_16 ) ;
if ( V_11 != V_16 ) {
F_17 ( * V_10 ) ;
return - V_17 ;
}
F_16 ( * V_10 , V_16 ) ;
memcpy ( ( * V_10 ) -> V_15 + V_20 , V_18 , V_16 ) ;
F_8 ( L_3 , * V_10 ) ;
return 0 ;
}
static T_2 F_18 ( int V_8 , void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_12 * V_13 ;
struct V_9 * V_10 = NULL ;
int V_11 ;
if ( ! V_3 || ! V_3 -> V_5 || V_8 != V_3 -> V_7 -> V_8 ) {
F_19 ( 1 ) ;
return V_26 ;
}
V_13 = V_3 -> V_7 ;
F_20 ( & V_13 -> V_22 , L_4 ) ;
if ( V_3 -> V_5 -> V_14 )
return V_27 ;
if ( ! V_3 -> V_5 -> V_6 ) {
F_5 ( V_3 ) ;
return V_27 ;
}
V_11 = F_10 ( V_3 , & V_10 ) ;
if ( V_11 == - V_17 || V_11 == - V_25 || V_11 == - V_23 )
return V_27 ;
F_21 ( V_3 -> V_5 , V_10 ) ;
return V_27 ;
}
static int F_22 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_23 ( V_13 ) ;
struct V_28 * V_29 ;
int V_30 ;
int V_11 ;
V_29 = V_13 -> V_22 . V_31 ;
if ( ! V_29 )
return - V_32 ;
V_30 = F_24 ( V_29 , L_5 , 0 ) ;
if ( V_30 < 0 ) {
F_13 ( & V_13 -> V_22 ,
L_6 ) ;
return V_30 ;
}
V_11 = F_25 ( & V_13 -> V_22 , V_30 ,
V_33 , L_7 ) ;
if ( V_11 ) {
F_13 ( & V_13 -> V_22 , L_8 ) ;
return V_11 ;
}
V_3 -> V_4 = V_30 ;
V_3 -> V_34 = F_26 ( V_13 -> V_8 ) ;
return 0 ;
}
static int F_22 ( struct V_12 * V_13 )
{
return - V_32 ;
}
static int F_27 ( struct V_12 * V_13 )
{
struct V_35 * V_36 ;
struct V_2 * V_3 = F_23 ( V_13 ) ;
int V_11 ;
V_36 = V_13 -> V_22 . V_37 ;
if ( V_36 == NULL ) {
F_13 ( & V_13 -> V_22 , L_9 ) ;
return - V_38 ;
}
V_3 -> V_4 = V_36 -> V_4 ;
V_3 -> V_34 = V_36 -> V_34 ;
V_11 = F_25 ( & V_13 -> V_22 ,
V_3 -> V_4 , V_33 , L_7 ) ;
if ( V_11 ) {
F_28 ( L_10 , __FILE__ ) ;
return V_11 ;
}
return 0 ;
}
static int F_29 ( struct V_12 * V_13 ,
const struct V_39 * V_40 )
{
struct V_2 * V_3 ;
struct V_35 * V_36 ;
int V_11 ;
F_20 ( & V_13 -> V_22 , L_11 , V_41 ) ;
F_20 ( & V_13 -> V_22 , L_12 , V_13 -> V_8 ) ;
if ( ! F_30 ( V_13 -> V_42 , V_43 ) ) {
F_13 ( & V_13 -> V_22 , L_13 ) ;
return - V_32 ;
}
V_3 = F_31 ( & V_13 -> V_22 , sizeof( struct V_2 ) ,
V_24 ) ;
if ( ! V_3 )
return - V_25 ;
V_3 -> V_7 = V_13 ;
F_32 ( V_13 , V_3 ) ;
V_36 = V_13 -> V_22 . V_37 ;
if ( ! V_36 && V_13 -> V_22 . V_31 ) {
V_11 = F_22 ( V_13 ) ;
if ( V_11 ) {
F_13 ( & V_13 -> V_22 , L_9 ) ;
return V_11 ;
}
} else if ( V_36 ) {
V_11 = F_27 ( V_13 ) ;
if ( V_11 ) {
F_13 ( & V_13 -> V_22 ,
L_14 ) ;
return V_11 ;
}
} else {
F_13 ( & V_13 -> V_22 ,
L_15 ) ;
return - V_32 ;
}
V_11 = F_33 ( V_3 , & V_44 , & V_13 -> V_22 ,
V_45 , V_46 ,
& V_3 -> V_5 ) ;
if ( V_11 < 0 ) {
F_13 ( & V_13 -> V_22 , L_16 ) ;
return V_11 ;
}
V_11 = F_34 ( & V_13 -> V_22 , V_13 -> V_8 , NULL ,
F_18 ,
V_3 -> V_34 | V_47 ,
V_48 , V_3 ) ;
if ( V_11 < 0 )
F_13 ( & V_13 -> V_22 , L_17 ) ;
return V_11 ;
}
static int F_35 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_23 ( V_13 ) ;
F_20 ( & V_13 -> V_22 , L_11 , V_41 ) ;
F_36 ( V_3 -> V_5 ) ;
return 0 ;
}
