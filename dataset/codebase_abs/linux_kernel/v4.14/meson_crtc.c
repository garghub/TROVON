static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_3 ( V_5 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_5 ( V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_8 = V_2 -> V_9 ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_7 ( L_1 ) ;
if ( ! V_8 ) {
F_8 ( L_2 ) ;
return;
}
F_9 ( V_8 -> V_10 . V_11 ,
V_5 -> V_12 + F_10 ( V_13 ) ) ;
F_11 ( V_14 , V_14 ,
V_5 -> V_12 + F_10 ( V_15 ) ) ;
V_5 -> V_16 . V_17 = true ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
V_5 -> V_16 . V_17 = false ;
V_5 -> V_16 . V_18 = false ;
F_11 ( V_14 , 0 ,
V_5 -> V_12 + F_10 ( V_15 ) ) ;
if ( V_2 -> V_9 -> V_19 && ! V_2 -> V_9 -> V_20 ) {
F_13 ( & V_2 -> V_21 -> V_22 ) ;
F_14 ( V_2 , V_2 -> V_9 -> V_19 ) ;
F_15 ( & V_2 -> V_21 -> V_22 ) ;
V_2 -> V_9 -> V_19 = NULL ;
}
}
static void F_16 ( struct V_1 * V_2 ,
struct V_6 * V_9 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned long V_23 ;
if ( V_2 -> V_9 -> V_19 ) {
F_17 ( F_18 ( V_2 ) != 0 ) ;
F_19 ( & V_2 -> V_21 -> V_22 , V_23 ) ;
V_3 -> V_19 = V_2 -> V_9 -> V_19 ;
F_20 ( & V_2 -> V_21 -> V_22 , V_23 ) ;
V_2 -> V_9 -> V_19 = NULL ;
}
}
static void F_21 ( struct V_1 * V_2 ,
struct V_6 * V_24 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
V_5 -> V_16 . V_18 = true ;
}
void F_22 ( struct V_4 * V_5 )
{
struct V_3 * V_3 = F_2 ( V_5 -> V_2 ) ;
unsigned long V_23 ;
if ( V_5 -> V_16 . V_17 && V_5 -> V_16 . V_18 ) {
F_23 ( V_5 -> V_16 . V_25 ,
V_5 -> V_12 + F_10 ( V_26 ) ) ;
F_23 ( V_5 -> V_16 . V_27 [ 0 ] ,
V_5 -> V_12 + F_10 ( V_28 ) ) ;
F_23 ( V_5 -> V_16 . V_27 [ 1 ] ,
V_5 -> V_12 + F_10 ( V_29 ) ) ;
F_23 ( V_5 -> V_16 . V_27 [ 2 ] ,
V_5 -> V_12 + F_10 ( V_30 ) ) ;
F_23 ( V_5 -> V_16 . V_27 [ 3 ] ,
V_5 -> V_12 + F_10 ( V_31 ) ) ;
F_23 ( V_5 -> V_16 . V_27 [ 4 ] ,
V_5 -> V_12 + F_10 ( V_32 ) ) ;
if ( V_5 -> V_16 . V_33 ) {
struct V_34 * V_35 = V_5 -> V_36 ;
struct V_37 * V_9 = V_35 -> V_9 ;
struct V_38 V_39 = {
. V_40 = V_9 -> V_41 ,
. y1 = V_9 -> V_42 ,
. V_43 = V_9 -> V_41 + V_9 -> V_44 ,
. V_45 = V_9 -> V_42 + V_9 -> V_46 ,
} ;
F_24 ( V_5 , & V_39 ) ;
} else
F_25 ( V_5 ) ;
F_11 ( V_47 , V_47 ,
V_5 -> V_12 + F_10 ( V_15 ) ) ;
V_5 -> V_16 . V_18 = false ;
}
F_26 ( V_5 -> V_2 ) ;
F_19 ( & V_5 -> V_48 -> V_22 , V_23 ) ;
if ( V_3 -> V_19 ) {
F_14 ( V_5 -> V_2 , V_3 -> V_19 ) ;
F_27 ( V_5 -> V_2 ) ;
V_3 -> V_19 = NULL ;
}
F_20 ( & V_5 -> V_48 -> V_22 , V_23 ) ;
}
int F_28 ( struct V_4 * V_5 )
{
struct V_3 * V_3 ;
struct V_1 * V_2 ;
int V_49 ;
V_3 = F_29 ( V_5 -> V_48 -> V_21 , sizeof( * V_3 ) ,
V_50 ) ;
if ( ! V_3 )
return - V_51 ;
V_3 -> V_5 = V_5 ;
V_2 = & V_3 -> V_52 ;
V_49 = F_30 ( V_5 -> V_48 , V_2 ,
V_5 -> V_36 , NULL ,
& V_53 , L_3 ) ;
if ( V_49 ) {
F_31 ( V_5 -> V_48 -> V_21 , L_4 ) ;
return V_49 ;
}
F_32 ( V_2 , & V_54 ) ;
V_5 -> V_2 = V_2 ;
return 0 ;
}
