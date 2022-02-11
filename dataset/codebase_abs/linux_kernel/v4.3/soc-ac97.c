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
struct V_3 * F_9 ( struct V_4 * V_5 ,
unsigned int V_20 , unsigned int V_21 )
{
struct V_3 * V_6 ;
int V_22 ;
V_6 = F_4 ( V_5 ) ;
if ( F_10 ( V_6 ) )
return V_6 ;
if ( V_20 ) {
V_22 = F_11 ( V_6 , false , V_20 , V_21 ) ;
if ( V_22 < 0 ) {
F_12 ( V_5 -> V_2 , L_2 ,
V_22 ) ;
goto V_23;
}
}
V_22 = F_13 ( & V_6 -> V_2 ) ;
if ( V_22 )
goto V_23;
return V_6 ;
V_23:
F_14 ( & V_6 -> V_2 ) ;
return F_6 ( V_22 ) ;
}
void F_15 ( struct V_3 * V_6 )
{
F_16 ( & V_6 -> V_2 ) ;
V_6 -> V_9 = NULL ;
F_14 ( & V_6 -> V_2 ) ;
}
static void F_17 ( struct V_3 * V_6 )
{
struct V_24 * V_25 = V_26 . V_25 ;
F_18 ( V_25 , V_26 . V_27 ) ;
F_19 ( V_26 . V_28 , 1 ) ;
F_20 ( 10 ) ;
F_19 ( V_26 . V_28 , 0 ) ;
F_18 ( V_25 , V_26 . V_29 ) ;
F_21 ( 2 ) ;
}
static void F_22 ( struct V_3 * V_6 )
{
struct V_24 * V_25 = V_26 . V_25 ;
F_18 ( V_25 , V_26 . V_30 ) ;
F_19 ( V_26 . V_28 , 0 ) ;
F_19 ( V_26 . V_31 , 0 ) ;
F_19 ( V_26 . V_32 , 0 ) ;
F_20 ( 10 ) ;
F_19 ( V_26 . V_32 , 1 ) ;
F_18 ( V_25 , V_26 . V_29 ) ;
F_21 ( 2 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_24 * V_35 ;
struct V_36 * V_37 ;
int V_38 ;
int V_22 ;
V_35 = F_24 ( V_2 ) ;
if ( F_10 ( V_35 ) ) {
F_12 ( V_2 , L_3 ) ;
return F_25 ( V_35 ) ;
}
V_34 -> V_25 = V_35 ;
V_37 = F_26 ( V_35 , L_4 ) ;
if ( F_10 ( V_37 ) ) {
F_12 ( V_2 , L_5 ) ;
return F_25 ( V_37 ) ;
}
V_34 -> V_30 = V_37 ;
V_37 = F_26 ( V_35 , L_6 ) ;
if ( F_10 ( V_37 ) ) {
F_12 ( V_2 , L_7 ) ;
return F_25 ( V_37 ) ;
}
V_34 -> V_27 = V_37 ;
V_37 = F_26 ( V_35 , L_8 ) ;
if ( F_10 ( V_37 ) ) {
F_12 ( V_2 , L_9 ) ;
return F_25 ( V_37 ) ;
}
V_34 -> V_29 = V_37 ;
V_38 = F_27 ( V_2 -> V_39 , L_10 , 0 ) ;
if ( V_38 < 0 ) {
F_12 ( V_2 , L_11 ) ;
return V_38 ;
}
V_22 = F_28 ( V_2 , V_38 , L_12 ) ;
if ( V_22 ) {
F_12 ( V_2 , L_13 ) ;
return V_22 ;
}
V_34 -> V_28 = V_38 ;
V_38 = F_27 ( V_2 -> V_39 , L_10 , 1 ) ;
if ( V_38 < 0 ) {
F_12 ( V_2 , L_14 , V_38 ) ;
return V_38 ;
}
V_22 = F_28 ( V_2 , V_38 , L_15 ) ;
if ( V_22 ) {
F_12 ( V_2 , L_16 ) ;
return V_22 ;
}
V_34 -> V_31 = V_38 ;
V_38 = F_27 ( V_2 -> V_39 , L_10 , 2 ) ;
if ( V_38 < 0 ) {
F_12 ( V_2 , L_17 ) ;
return V_38 ;
}
V_22 = F_28 ( V_2 , V_38 , L_18 ) ;
if ( V_22 ) {
F_12 ( V_2 , L_19 ) ;
return V_22 ;
}
V_34 -> V_32 = V_38 ;
return 0 ;
}
int F_29 ( struct V_40 * V_41 )
{
if ( V_41 == V_42 )
return 0 ;
if ( V_42 && V_41 )
return - V_43 ;
V_42 = V_41 ;
V_10 . V_41 = V_41 ;
return 0 ;
}
int F_30 ( struct V_40 * V_41 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = & V_45 -> V_2 ;
struct V_33 V_34 ;
int V_22 ;
V_22 = F_23 ( V_2 , & V_34 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_29 ( V_41 ) ;
if ( V_22 )
return V_22 ;
V_41 -> V_46 = F_17 ;
V_41 -> V_47 = F_22 ;
V_26 = V_34 ;
return 0 ;
}
