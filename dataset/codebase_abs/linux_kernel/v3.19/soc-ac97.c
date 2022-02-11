static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) ) ;
}
struct V_3 * F_4 ( struct V_4 * V_5 )
{
struct V_3 * V_6 ;
V_6 = F_5 ( sizeof( struct V_3 ) , V_7 ) ;
if ( V_6 == NULL )
return F_6 ( - V_8 ) ;
V_6 -> V_9 = & V_10 ;
V_6 -> V_11 = 0 ;
V_6 -> V_2 . V_9 = & V_12 ;
V_6 -> V_2 . V_13 = V_5 -> V_14 . V_15 -> V_2 ;
V_6 -> V_2 . V_16 = F_1 ;
F_7 ( & V_6 -> V_2 , L_1 ,
V_5 -> V_14 . V_15 -> V_17 -> V_18 , 0 ,
V_5 -> V_14 . V_19 ) ;
F_8 ( & V_6 -> V_2 ) ;
return V_6 ;
}
struct V_3 * F_9 ( struct V_4 * V_5 )
{
struct V_3 * V_6 ;
int V_20 ;
V_6 = F_4 ( V_5 ) ;
if ( F_10 ( V_6 ) )
return V_6 ;
V_20 = F_11 ( & V_6 -> V_2 ) ;
if ( V_20 ) {
F_12 ( & V_6 -> V_2 ) ;
return F_6 ( V_20 ) ;
}
return V_6 ;
}
void F_13 ( struct V_3 * V_6 )
{
F_14 ( & V_6 -> V_2 ) ;
V_6 -> V_9 = NULL ;
F_12 ( & V_6 -> V_2 ) ;
}
static void F_15 ( struct V_3 * V_6 )
{
struct V_21 * V_22 = V_23 . V_22 ;
F_16 ( V_22 , V_23 . V_24 ) ;
F_17 ( V_23 . V_25 , 1 ) ;
F_18 ( 10 ) ;
F_17 ( V_23 . V_25 , 0 ) ;
F_16 ( V_22 , V_23 . V_26 ) ;
F_19 ( 2 ) ;
}
static void F_20 ( struct V_3 * V_6 )
{
struct V_21 * V_22 = V_23 . V_22 ;
F_16 ( V_22 , V_23 . V_27 ) ;
F_17 ( V_23 . V_25 , 0 ) ;
F_17 ( V_23 . V_28 , 0 ) ;
F_17 ( V_23 . V_29 , 0 ) ;
F_18 ( 10 ) ;
F_17 ( V_23 . V_29 , 1 ) ;
F_16 ( V_22 , V_23 . V_26 ) ;
F_19 ( 2 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_21 * V_32 ;
struct V_33 * V_34 ;
int V_35 ;
int V_20 ;
V_32 = F_22 ( V_2 ) ;
if ( F_10 ( V_32 ) ) {
F_23 ( V_2 , L_2 ) ;
return F_24 ( V_32 ) ;
}
V_31 -> V_22 = V_32 ;
V_34 = F_25 ( V_32 , L_3 ) ;
if ( F_10 ( V_34 ) ) {
F_23 ( V_2 , L_4 ) ;
return F_24 ( V_34 ) ;
}
V_31 -> V_27 = V_34 ;
V_34 = F_25 ( V_32 , L_5 ) ;
if ( F_10 ( V_34 ) ) {
F_23 ( V_2 , L_6 ) ;
return F_24 ( V_34 ) ;
}
V_31 -> V_24 = V_34 ;
V_34 = F_25 ( V_32 , L_7 ) ;
if ( F_10 ( V_34 ) ) {
F_23 ( V_2 , L_8 ) ;
return F_24 ( V_34 ) ;
}
V_31 -> V_26 = V_34 ;
V_35 = F_26 ( V_2 -> V_36 , L_9 , 0 ) ;
if ( V_35 < 0 ) {
F_23 ( V_2 , L_10 ) ;
return V_35 ;
}
V_20 = F_27 ( V_2 , V_35 , L_11 ) ;
if ( V_20 ) {
F_23 ( V_2 , L_12 ) ;
return V_20 ;
}
V_31 -> V_25 = V_35 ;
V_35 = F_26 ( V_2 -> V_36 , L_9 , 1 ) ;
if ( V_35 < 0 ) {
F_23 ( V_2 , L_13 , V_35 ) ;
return V_35 ;
}
V_20 = F_27 ( V_2 , V_35 , L_14 ) ;
if ( V_20 ) {
F_23 ( V_2 , L_15 ) ;
return V_20 ;
}
V_31 -> V_28 = V_35 ;
V_35 = F_26 ( V_2 -> V_36 , L_9 , 2 ) ;
if ( V_35 < 0 ) {
F_23 ( V_2 , L_16 ) ;
return V_35 ;
}
V_20 = F_27 ( V_2 , V_35 , L_17 ) ;
if ( V_20 ) {
F_23 ( V_2 , L_18 ) ;
return V_20 ;
}
V_31 -> V_29 = V_35 ;
return 0 ;
}
int F_28 ( struct V_37 * V_38 )
{
if ( V_38 == V_39 )
return 0 ;
if ( V_39 && V_38 )
return - V_40 ;
V_39 = V_38 ;
V_10 . V_38 = V_38 ;
return 0 ;
}
int F_29 ( struct V_37 * V_38 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = & V_42 -> V_2 ;
struct V_30 V_31 ;
int V_20 ;
V_20 = F_21 ( V_2 , & V_31 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_28 ( V_38 ) ;
if ( V_20 )
return V_20 ;
V_38 -> V_43 = F_15 ;
V_38 -> V_44 = F_20 ;
V_23 = V_31 ;
return 0 ;
}
