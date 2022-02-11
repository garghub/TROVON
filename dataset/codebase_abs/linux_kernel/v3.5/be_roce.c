static void F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
int V_5 , V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! V_9 )
return;
if ( V_8 -> V_10 == V_11 ) {
if ( ! F_2 ( V_2 ) )
return;
V_4 . V_12 = F_3 ( V_8 , 2 ) ;
V_4 . V_13 = F_4 ( V_8 , 2 ) ;
} else {
V_4 . V_12 = 0 ;
V_4 . V_13 = 0 ;
}
V_4 . V_8 = V_2 -> V_8 ;
if ( V_2 -> V_14 == V_15 )
V_4 . V_16 = V_2 -> V_16 ;
else
V_4 . V_16 = V_2 -> V_17 . V_18 ;
V_4 . V_19 = V_2 -> V_17 . V_20 ;
V_4 . V_21 = V_2 -> V_17 . V_22 ;
V_4 . V_23 = V_2 -> V_17 . V_24 ;
V_4 . V_25 = V_2 -> V_25 ;
memcpy ( V_4 . V_26 , V_2 -> V_25 -> V_27 , V_28 ) ;
V_4 . V_29 = V_2 -> V_14 ;
if ( F_2 ( V_2 ) ) {
V_6 = V_2 -> V_30 + V_2 -> V_31 ;
V_4 . V_32 = V_33 ;
V_4 . V_34 . V_35 = F_5 ( V_6 , V_36 ) ;
V_4 . V_34 . V_37 = V_2 -> V_38 ;
for ( V_5 = 0 ; V_5 < V_4 . V_34 . V_35 ; V_5 ++ ) {
V_4 . V_34 . V_39 [ V_5 ] =
V_2 -> V_40 [ V_5 ] . V_41 ;
}
} else {
V_4 . V_34 . V_35 = 0 ;
V_4 . V_32 = V_42 ;
}
V_2 -> V_43 = V_9 -> V_44 ( & V_4 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) ) {
F_8 ( & V_2 -> V_45 ) ;
F_9 ( & V_46 ) ;
F_10 ( & V_2 -> V_45 , & V_47 ) ;
F_1 ( V_2 ) ;
F_11 ( & V_46 ) ;
}
}
void F_12 ( struct V_1 * V_2 )
{
if ( V_9 && V_9 -> remove && V_2 -> V_43 )
V_9 -> remove ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) ) {
F_9 ( & V_46 ) ;
F_12 ( V_2 ) ;
F_14 ( & V_2 -> V_45 ) ;
F_11 ( & V_46 ) ;
}
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_9 && V_2 -> V_43 &&
V_9 -> V_48 )
V_9 -> V_48 ( V_2 -> V_43 , 0 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) ) {
F_9 ( & V_46 ) ;
F_15 ( V_2 ) ;
F_11 ( & V_46 ) ;
}
}
void F_17 ( struct V_1 * V_2 )
{
if ( V_9 && V_2 -> V_43 &&
V_9 -> V_48 )
V_9 -> V_48 ( V_2 -> V_43 , 1 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) ) {
F_9 ( & V_46 ) ;
F_17 ( V_2 ) ;
F_11 ( & V_46 ) ;
}
}
int F_19 ( struct V_49 * V_50 )
{
struct V_1 * V_51 ;
F_9 ( & V_46 ) ;
if ( V_9 ) {
F_11 ( & V_46 ) ;
return - V_52 ;
}
V_9 = V_50 ;
F_20 (dev, &be_adapter_list, entry) {
struct V_53 * V_25 ;
F_1 ( V_51 ) ;
V_25 = V_51 -> V_25 ;
if ( F_21 ( V_25 ) && F_22 ( V_25 ) )
F_15 ( V_51 ) ;
}
F_11 ( & V_46 ) ;
return 0 ;
}
void F_23 ( struct V_49 * V_50 )
{
struct V_1 * V_51 ;
F_9 ( & V_46 ) ;
F_20 (dev, &be_adapter_list, entry) {
if ( V_51 -> V_43 )
F_12 ( V_51 ) ;
}
V_9 = NULL ;
F_11 ( & V_46 ) ;
}
