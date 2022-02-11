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
V_4 . V_14 = V_2 -> V_14 ;
V_4 . V_15 = V_2 -> V_16 . V_17 ;
V_4 . V_18 = V_2 -> V_16 . V_19 ;
V_4 . V_20 = V_2 -> V_16 . V_21 ;
V_4 . V_22 = V_2 -> V_22 ;
memcpy ( V_4 . V_23 , V_2 -> V_22 -> V_24 , V_25 ) ;
V_4 . V_26 = V_2 -> V_27 ;
if ( F_2 ( V_2 ) ) {
V_6 = V_2 -> V_28 + V_2 -> V_29 ;
V_4 . V_30 = V_31 ;
V_4 . V_32 . V_33 = F_5 ( V_6 , V_34 ) ;
V_4 . V_32 . V_35 = V_2 -> V_36 ;
for ( V_5 = 0 ; V_5 < V_4 . V_32 . V_33 ; V_5 ++ ) {
V_4 . V_32 . V_37 [ V_5 ] =
V_2 -> V_38 [ V_5 ] . V_39 ;
}
} else {
V_4 . V_32 . V_33 = 0 ;
V_4 . V_30 = V_40 ;
}
V_2 -> V_41 = V_9 -> V_42 ( & V_4 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) ) {
F_8 ( & V_2 -> V_43 ) ;
F_9 ( & V_44 ) ;
F_10 ( & V_2 -> V_43 , & V_45 ) ;
F_1 ( V_2 ) ;
F_11 ( & V_44 ) ;
}
}
void F_12 ( struct V_1 * V_2 )
{
if ( V_9 && V_9 -> remove && V_2 -> V_41 )
V_9 -> remove ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) ) {
F_9 ( & V_44 ) ;
F_12 ( V_2 ) ;
F_14 ( & V_2 -> V_43 ) ;
F_11 ( & V_44 ) ;
}
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_9 && V_2 -> V_41 &&
V_9 -> V_46 )
V_9 -> V_46 ( V_2 -> V_41 , 0 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) ) {
F_9 ( & V_44 ) ;
F_15 ( V_2 ) ;
F_11 ( & V_44 ) ;
}
}
void F_17 ( struct V_1 * V_2 )
{
if ( V_9 && V_2 -> V_41 &&
V_9 -> V_46 )
V_9 -> V_46 ( V_2 -> V_41 , 1 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) ) {
F_9 ( & V_44 ) ;
F_17 ( V_2 ) ;
F_11 ( & V_44 ) ;
}
}
int F_19 ( struct V_47 * V_48 )
{
struct V_1 * V_49 ;
F_9 ( & V_44 ) ;
if ( V_9 ) {
F_11 ( & V_44 ) ;
return - V_50 ;
}
V_9 = V_48 ;
F_20 (dev, &be_adapter_list, entry) {
struct V_51 * V_22 ;
F_1 ( V_49 ) ;
V_22 = V_49 -> V_22 ;
if ( F_21 ( V_22 ) && F_22 ( V_22 ) )
F_15 ( V_49 ) ;
}
F_11 ( & V_44 ) ;
return 0 ;
}
void F_23 ( struct V_47 * V_48 )
{
struct V_1 * V_49 ;
F_9 ( & V_44 ) ;
F_20 (dev, &be_adapter_list, entry) {
if ( V_49 -> V_41 )
F_12 ( V_49 ) ;
}
V_9 = NULL ;
F_11 ( & V_44 ) ;
}
