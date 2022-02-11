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
struct V_31 * V_23 = & V_14 -> V_23 ;
T_1 V_32 ;
V_30 = F_23 ( V_23 , V_33 , 1 ,
V_34 ) ;
if ( F_24 ( V_30 ) ) {
F_12 ( V_23 , L_3 ) ;
return - V_35 ;
}
V_3 -> V_4 = F_25 ( V_30 ) ;
V_3 -> V_36 = F_26 ( V_14 -> V_9 ) ;
V_3 -> V_37 . V_38 = false ;
V_3 -> V_37 . V_39 = false ;
if ( F_27 ( V_23 , L_4 ) ) {
F_28 ( V_23 , L_4 , & V_32 ) ;
V_3 -> V_37 . V_38 = V_32 ;
}
if ( F_27 ( V_23 , L_5 ) ) {
F_28 ( V_23 , L_5 , & V_32 ) ;
V_3 -> V_37 . V_39 = V_32 ;
}
return 0 ;
}
static int F_29 ( struct V_13 * V_14 )
{
struct V_2 * V_3 = F_22 ( V_14 ) ;
struct V_40 * V_41 ;
int V_42 ;
int V_12 ;
V_41 = V_14 -> V_23 . V_43 ;
if ( ! V_41 )
return - V_35 ;
V_42 = F_30 ( V_41 , L_6 , 0 ) ;
if ( V_42 < 0 ) {
F_12 ( & V_14 -> V_23 ,
L_7 ) ;
return V_42 ;
}
V_12 = F_31 ( & V_14 -> V_23 , V_42 ,
V_44 , V_33 ) ;
if ( V_12 ) {
F_12 ( & V_14 -> V_23 , L_8 ) ;
return V_12 ;
}
V_3 -> V_4 = V_42 ;
V_3 -> V_36 = F_26 ( V_14 -> V_9 ) ;
V_3 -> V_37 . V_38 =
F_32 ( V_41 , L_4 ) ;
V_3 -> V_37 . V_39 =
F_32 ( V_41 , L_5 ) ;
return 0 ;
}
static int F_33 ( struct V_13 * V_14 )
{
struct V_45 * V_46 ;
struct V_2 * V_3 = F_22 ( V_14 ) ;
int V_12 ;
V_46 = V_14 -> V_23 . V_47 ;
if ( V_46 == NULL ) {
F_12 ( & V_14 -> V_23 , L_9 ) ;
return - V_48 ;
}
V_3 -> V_4 = V_46 -> V_4 ;
V_3 -> V_36 = V_46 -> V_36 ;
V_12 = F_31 ( & V_14 -> V_23 ,
V_3 -> V_4 , V_44 ,
V_33 ) ;
if ( V_12 ) {
F_34 ( L_10 , __FILE__ ) ;
return V_12 ;
}
V_3 -> V_37 . V_38 = V_46 -> V_38 ;
V_3 -> V_37 . V_39 = V_46 -> V_39 ;
return 0 ;
}
static int F_35 ( struct V_13 * V_14 ,
const struct V_49 * V_50 )
{
struct V_2 * V_3 ;
struct V_45 * V_46 ;
int V_12 ;
F_19 ( & V_14 -> V_23 , L_11 , V_51 ) ;
F_19 ( & V_14 -> V_23 , L_12 , V_14 -> V_9 ) ;
if ( ! F_36 ( V_14 -> V_52 , V_53 ) ) {
F_12 ( & V_14 -> V_23 , L_13 ) ;
return - V_35 ;
}
V_3 = F_37 ( & V_14 -> V_23 , sizeof( struct V_2 ) ,
V_25 ) ;
if ( ! V_3 )
return - V_26 ;
V_3 -> V_8 = V_14 ;
F_38 ( V_14 , V_3 ) ;
V_46 = V_14 -> V_23 . V_47 ;
if ( ! V_46 && V_14 -> V_23 . V_43 ) {
V_12 = F_29 ( V_14 ) ;
if ( V_12 ) {
F_12 ( & V_14 -> V_23 , L_9 ) ;
return V_12 ;
}
} else if ( V_46 ) {
V_12 = F_33 ( V_14 ) ;
if ( V_12 ) {
F_12 ( & V_14 -> V_23 ,
L_14 ) ;
return V_12 ;
}
} else if ( F_39 ( & V_14 -> V_23 ) ) {
V_12 = F_21 ( V_14 ) ;
if ( V_12 ) {
F_12 ( & V_14 -> V_23 , L_15 ) ;
return V_12 ;
}
} else {
F_12 ( & V_14 -> V_23 ,
L_16 ) ;
return - V_35 ;
}
V_12 = F_40 ( V_3 , & V_54 , & V_14 -> V_23 ,
V_55 , V_56 ,
& V_3 -> V_5 , & V_3 -> V_37 ) ;
if ( V_12 < 0 ) {
F_12 ( & V_14 -> V_23 , L_17 ) ;
return V_12 ;
}
V_3 -> V_7 = true ;
V_12 = F_41 ( & V_14 -> V_23 , V_14 -> V_9 , NULL ,
F_17 ,
V_3 -> V_36 | V_57 ,
V_58 , V_3 ) ;
if ( V_12 < 0 )
F_12 ( & V_14 -> V_23 , L_18 ) ;
return V_12 ;
}
static int F_42 ( struct V_13 * V_14 )
{
struct V_2 * V_3 = F_22 ( V_14 ) ;
F_19 ( & V_14 -> V_23 , L_11 , V_51 ) ;
F_43 ( V_3 -> V_5 ) ;
return 0 ;
}
