static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
struct V_8 * V_6 = V_3 -> V_6 ;
F_3 ( V_5 -> V_9 -> V_10 ,
V_6 -> V_11 + F_4 ( V_12 ) ) ;
F_5 ( V_13 , V_13 ,
V_6 -> V_11 + F_4 ( V_14 ) ) ;
V_6 -> V_15 . V_16 = true ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_8 * V_6 = V_3 -> V_6 ;
V_6 -> V_15 . V_16 = false ;
F_5 ( V_13 , 0 ,
V_6 -> V_11 + F_4 ( V_14 ) ) ;
if ( V_2 -> V_9 -> V_17 && ! V_2 -> V_9 -> V_18 ) {
F_7 ( & V_2 -> V_19 -> V_20 ) ;
F_8 ( V_2 , V_2 -> V_9 -> V_17 ) ;
F_9 ( & V_2 -> V_19 -> V_20 ) ;
V_2 -> V_9 -> V_17 = NULL ;
}
}
static void F_10 ( struct V_1 * V_2 ,
struct V_21 * V_9 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned long V_22 ;
if ( V_2 -> V_9 -> V_17 ) {
F_11 ( F_12 ( V_2 ) != 0 ) ;
F_13 ( & V_2 -> V_19 -> V_20 , V_22 ) ;
V_3 -> V_17 = V_2 -> V_9 -> V_17 ;
F_14 ( & V_2 -> V_19 -> V_20 , V_22 ) ;
V_2 -> V_9 -> V_17 = NULL ;
}
}
static void F_15 ( struct V_1 * V_2 ,
struct V_21 * V_23 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_8 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_15 . V_16 )
V_6 -> V_15 . V_24 = true ;
}
void F_16 ( struct V_8 * V_6 )
{
struct V_3 * V_3 = F_2 ( V_6 -> V_2 ) ;
unsigned long V_22 ;
if ( V_6 -> V_15 . V_16 && V_6 -> V_15 . V_24 ) {
F_17 ( V_6 -> V_15 . V_25 ,
V_6 -> V_11 + F_4 ( V_26 ) ) ;
F_17 ( V_6 -> V_15 . V_27 [ 0 ] ,
V_6 -> V_11 + F_4 ( V_28 ) ) ;
F_17 ( V_6 -> V_15 . V_27 [ 1 ] ,
V_6 -> V_11 + F_4 ( V_29 ) ) ;
F_17 ( V_6 -> V_15 . V_27 [ 2 ] ,
V_6 -> V_11 + F_4 ( V_30 ) ) ;
F_17 ( V_6 -> V_15 . V_27 [ 3 ] ,
V_6 -> V_11 + F_4 ( V_31 ) ) ;
F_17 ( V_6 -> V_15 . V_27 [ 4 ] ,
V_6 -> V_11 + F_4 ( V_32 ) ) ;
if ( V_6 -> V_15 . V_33 ) {
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_34 * V_9 = V_5 -> V_9 ;
struct V_35 V_36 = {
. V_37 = V_9 -> V_38 ,
. y1 = V_9 -> V_39 ,
. V_40 = V_9 -> V_38 + V_9 -> V_10 ,
. V_41 = V_9 -> V_39 + V_9 -> V_42 ,
} ;
F_18 ( V_6 , & V_36 ) ;
} else
F_19 ( V_6 ) ;
F_5 ( V_43 , V_43 ,
V_6 -> V_11 + F_4 ( V_14 ) ) ;
V_6 -> V_15 . V_24 = false ;
}
F_20 ( V_6 -> V_2 ) ;
F_13 ( & V_6 -> V_44 -> V_20 , V_22 ) ;
if ( V_3 -> V_17 ) {
F_8 ( V_6 -> V_2 , V_3 -> V_17 ) ;
F_21 ( V_6 -> V_2 ) ;
V_3 -> V_17 = NULL ;
}
F_14 ( & V_6 -> V_44 -> V_20 , V_22 ) ;
}
int F_22 ( struct V_8 * V_6 )
{
struct V_3 * V_3 ;
struct V_1 * V_2 ;
int V_45 ;
V_3 = F_23 ( V_6 -> V_44 -> V_19 , sizeof( * V_3 ) ,
V_46 ) ;
if ( ! V_3 )
return - V_47 ;
V_3 -> V_6 = V_6 ;
V_2 = & V_3 -> V_48 ;
V_45 = F_24 ( V_6 -> V_44 , V_2 ,
V_6 -> V_7 , NULL ,
& V_49 , L_1 ) ;
if ( V_45 ) {
F_25 ( V_6 -> V_44 -> V_19 , L_2 ) ;
return V_45 ;
}
F_26 ( V_2 , & V_50 ) ;
V_6 -> V_2 = V_2 ;
return 0 ;
}
