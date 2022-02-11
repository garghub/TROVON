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
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_7 ( L_1 ) ;
if ( ! V_7 ) {
F_8 ( L_2 ) ;
return;
}
F_9 ( V_7 -> V_9 . V_10 ,
V_5 -> V_11 + F_10 ( V_12 ) ) ;
F_11 ( V_13 , V_13 ,
V_5 -> V_11 + F_10 ( V_14 ) ) ;
V_5 -> V_15 . V_16 = true ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
V_5 -> V_15 . V_16 = false ;
V_5 -> V_15 . V_17 = false ;
F_11 ( V_13 , 0 ,
V_5 -> V_11 + F_10 ( V_14 ) ) ;
if ( V_2 -> V_8 -> V_18 && ! V_2 -> V_8 -> V_19 ) {
F_13 ( & V_2 -> V_20 -> V_21 ) ;
F_14 ( V_2 , V_2 -> V_8 -> V_18 ) ;
F_15 ( & V_2 -> V_20 -> V_21 ) ;
V_2 -> V_8 -> V_18 = NULL ;
}
}
static void F_16 ( struct V_1 * V_2 ,
struct V_6 * V_8 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned long V_22 ;
if ( V_2 -> V_8 -> V_18 ) {
F_17 ( F_18 ( V_2 ) != 0 ) ;
F_19 ( & V_2 -> V_20 -> V_21 , V_22 ) ;
V_3 -> V_18 = V_2 -> V_8 -> V_18 ;
F_20 ( & V_2 -> V_20 -> V_21 , V_22 ) ;
V_2 -> V_8 -> V_18 = NULL ;
}
}
static void F_21 ( struct V_1 * V_2 ,
struct V_6 * V_23 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
V_5 -> V_15 . V_17 = true ;
}
void F_22 ( struct V_4 * V_5 )
{
struct V_3 * V_3 = F_2 ( V_5 -> V_2 ) ;
unsigned long V_22 ;
if ( V_5 -> V_15 . V_16 && V_5 -> V_15 . V_17 ) {
F_23 ( V_5 -> V_15 . V_24 ,
V_5 -> V_11 + F_10 ( V_25 ) ) ;
F_23 ( V_5 -> V_15 . V_26 [ 0 ] ,
V_5 -> V_11 + F_10 ( V_27 ) ) ;
F_23 ( V_5 -> V_15 . V_26 [ 1 ] ,
V_5 -> V_11 + F_10 ( V_28 ) ) ;
F_23 ( V_5 -> V_15 . V_26 [ 2 ] ,
V_5 -> V_11 + F_10 ( V_29 ) ) ;
F_23 ( V_5 -> V_15 . V_26 [ 3 ] ,
V_5 -> V_11 + F_10 ( V_30 ) ) ;
F_23 ( V_5 -> V_15 . V_26 [ 4 ] ,
V_5 -> V_11 + F_10 ( V_31 ) ) ;
if ( V_5 -> V_15 . V_32 ) {
struct V_33 * V_34 = V_5 -> V_35 ;
struct V_36 * V_8 = V_34 -> V_8 ;
struct V_37 V_38 = {
. V_39 = V_8 -> V_40 ,
. y1 = V_8 -> V_41 ,
. V_42 = V_8 -> V_40 + V_8 -> V_43 ,
. V_44 = V_8 -> V_41 + V_8 -> V_45 ,
} ;
F_24 ( V_5 , & V_38 ) ;
} else
F_25 ( V_5 ) ;
F_11 ( V_46 , V_46 ,
V_5 -> V_11 + F_10 ( V_14 ) ) ;
V_5 -> V_15 . V_17 = false ;
}
F_26 ( V_5 -> V_2 ) ;
F_19 ( & V_5 -> V_47 -> V_21 , V_22 ) ;
if ( V_3 -> V_18 ) {
F_14 ( V_5 -> V_2 , V_3 -> V_18 ) ;
F_27 ( V_5 -> V_2 ) ;
V_3 -> V_18 = NULL ;
}
F_20 ( & V_5 -> V_47 -> V_21 , V_22 ) ;
}
int F_28 ( struct V_4 * V_5 )
{
struct V_3 * V_3 ;
struct V_1 * V_2 ;
int V_48 ;
V_3 = F_29 ( V_5 -> V_47 -> V_20 , sizeof( * V_3 ) ,
V_49 ) ;
if ( ! V_3 )
return - V_50 ;
V_3 -> V_5 = V_5 ;
V_2 = & V_3 -> V_51 ;
V_48 = F_30 ( V_5 -> V_47 , V_2 ,
V_5 -> V_35 , NULL ,
& V_52 , L_3 ) ;
if ( V_48 ) {
F_31 ( V_5 -> V_47 -> V_20 , L_4 ) ;
return V_48 ;
}
F_32 ( V_2 , & V_53 ) ;
V_5 -> V_2 = V_2 ;
return 0 ;
}
