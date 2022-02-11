static void F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
int V_5 , V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! V_9 )
return;
if ( V_9 -> V_10 != V_11 ) {
F_2 ( & V_8 -> V_12 , L_1 ) ;
return;
}
if ( V_8 -> V_13 == V_14 ) {
if ( ! F_3 ( V_2 ) )
return;
V_4 . V_15 = F_4 ( V_8 , 2 ) ;
V_4 . V_16 = F_5 ( V_8 , 2 ) ;
} else {
V_4 . V_15 = 0 ;
V_4 . V_16 = 0 ;
}
V_4 . V_8 = V_2 -> V_8 ;
V_4 . V_17 = V_2 -> V_17 ;
V_4 . V_18 = V_2 -> V_19 . V_20 ;
V_4 . V_21 = V_2 -> V_19 . V_22 ;
V_4 . V_23 = V_2 -> V_19 . V_24 ;
V_4 . V_25 = V_2 -> V_25 ;
memcpy ( V_4 . V_26 , V_2 -> V_25 -> V_27 , V_28 ) ;
V_4 . V_29 = V_2 -> V_30 ;
if ( F_3 ( V_2 ) ) {
V_6 = V_2 -> V_31 + V_2 -> V_32 ;
V_4 . V_33 = V_34 ;
V_4 . V_35 . V_36 = F_6 ( V_6 , V_37 ) ;
V_4 . V_35 . V_38 = V_2 -> V_39 ;
for ( V_5 = 0 ; V_5 < V_4 . V_35 . V_36 ; V_5 ++ ) {
V_4 . V_35 . V_40 [ V_5 ] =
V_2 -> V_41 [ V_5 ] . V_42 ;
}
} else {
V_4 . V_35 . V_36 = 0 ;
V_4 . V_33 = V_43 ;
}
V_2 -> V_44 = V_9 -> V_45 ( & V_4 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) ) {
F_9 ( & V_2 -> V_46 ) ;
F_10 ( & V_47 ) ;
F_11 ( & V_2 -> V_46 , & V_48 ) ;
F_1 ( V_2 ) ;
F_12 ( & V_47 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_9 && V_9 -> remove && V_2 -> V_44 )
V_9 -> remove ( V_2 -> V_44 ) ;
V_2 -> V_44 = NULL ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) ) {
F_10 ( & V_47 ) ;
F_13 ( V_2 ) ;
F_15 ( & V_2 -> V_46 ) ;
F_12 ( & V_47 ) ;
}
}
void F_16 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) ) {
F_10 ( & V_47 ) ;
if ( V_9 && V_2 -> V_44 &&
V_9 -> V_49 )
V_9 -> V_49 ( V_2 -> V_44 ,
V_50 ) ;
F_12 ( & V_47 ) ;
}
}
int F_17 ( struct V_51 * V_52 )
{
struct V_1 * V_12 ;
F_10 ( & V_47 ) ;
if ( V_9 ) {
F_12 ( & V_47 ) ;
return - V_53 ;
}
V_9 = V_52 ;
F_18 (dev, &be_adapter_list, entry) {
F_1 ( V_12 ) ;
}
F_12 ( & V_47 ) ;
return 0 ;
}
void F_19 ( struct V_51 * V_52 )
{
struct V_1 * V_12 ;
F_10 ( & V_47 ) ;
F_18 (dev, &be_adapter_list, entry) {
if ( V_12 -> V_44 )
F_13 ( V_12 ) ;
}
V_9 = NULL ;
F_12 ( & V_47 ) ;
}
