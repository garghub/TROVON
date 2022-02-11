static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
}
static void
F_4 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_2 , V_7 , false ) ;
F_6 ( V_7 ) ;
F_7 ( V_2 , V_7 ) ;
F_8 ( V_2 , V_7 , 0 ) ;
F_9 ( V_2 , V_7 ) ;
V_7 -> V_8 = false ;
F_10 ( V_7 ) ;
F_11 ( V_2 , V_7 ) ;
F_12 ( V_2 , V_7 ) ;
F_13 ( V_7 ) ;
F_14 ( V_7 ) ;
F_15 ( & V_4 -> V_9 ) ;
}
static void F_16 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_17 ( V_11 ,
struct V_6 ,
F_16 ) ;
F_4 ( V_7 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
bool V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_13 ;
V_13 = F_19 ( V_7 , V_12 ) ;
if ( V_13 )
return V_13 ;
F_20 ( & V_7 -> F_16 , F_16 ) ;
V_13 = F_21 ( & V_4 -> V_9 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_22 ( V_2 , V_7 ) ;
if ( V_13 ) {
F_15 ( & V_4 -> V_9 ) ;
return V_13 ;
}
if ( ! V_12 ) {
V_13 = F_5 ( V_2 , V_7 , true ) ;
if ( V_13 ) {
F_12 ( V_2 , V_7 ) ;
F_15 ( & V_4 -> V_9 ) ;
return V_13 ;
}
}
F_23 ( F_24 ( V_7 , false ) < 0 ) ;
F_25 ( V_7 ) ;
if ( V_12 )
F_26 ( V_14 , & V_7 -> F_16 ) ;
else
F_4 ( V_7 ) ;
return 0 ;
}
static struct V_15 * F_27 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
struct V_18 V_20 ;
if ( ! ( V_19 -> V_21 & V_22 ) ) {
struct V_23 * V_24 ;
struct V_25 * V_26 ;
V_24 = F_28 ( V_17 ,
V_19 -> V_27 [ 0 ] ) ;
if ( ! V_24 ) {
F_29 ( L_1 ,
V_19 -> V_27 [ 0 ] ) ;
return F_30 ( - V_28 ) ;
}
V_26 = F_31 ( V_24 ) ;
V_20 = * V_19 ;
if ( V_26 -> V_29 ) {
V_20 . V_30 [ 0 ] =
V_31 ;
} else {
V_20 . V_30 [ 0 ] = V_32 ;
}
F_32 ( V_24 ) ;
V_19 = & V_20 ;
}
return F_33 ( V_2 , V_17 , V_19 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_13 ;
F_35 ( & V_4 -> V_9 , 1 ) ;
V_2 -> V_33 = true ;
V_13 = F_36 ( V_2 , V_2 -> V_34 . V_35 ) ;
if ( V_13 < 0 ) {
F_37 ( V_2 -> V_2 , L_2 ) ;
return V_13 ;
}
V_2 -> V_34 . V_36 = 2048 ;
V_2 -> V_34 . V_37 = 2048 ;
V_2 -> V_34 . V_38 = & V_39 ;
V_2 -> V_34 . V_40 = 24 ;
V_2 -> V_34 . V_41 = true ;
F_38 ( V_2 ) ;
if ( V_2 -> V_34 . V_42 ) {
V_4 -> V_5 = F_39 ( V_2 , 32 ,
V_2 -> V_34 . V_42 ) ;
if ( F_40 ( V_4 -> V_5 ) )
V_4 -> V_5 = NULL ;
}
F_41 ( V_2 ) ;
return 0 ;
}
