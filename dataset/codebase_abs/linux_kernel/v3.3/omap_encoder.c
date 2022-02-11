static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_3 ( L_1 , V_3 -> V_4 -> V_5 ) ;
F_4 ( V_2 ) ;
F_5 ( V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_6 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_3 ( L_2 , V_3 -> V_4 -> V_5 , V_6 ) ;
}
static bool F_7 ( struct V_1 * V_2 ,
struct V_7 * V_6 ,
struct V_7 * V_8 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_3 ( L_1 , V_3 -> V_4 -> V_5 ) ;
return true ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_7 * V_6 ,
struct V_7 * V_8 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
int V_14 ;
V_6 = V_8 ;
F_3 ( L_3 , V_3 -> V_4 -> V_5 ,
V_6 -> V_15 , V_6 -> V_16 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
struct V_18 * V_19 = V_12 -> V_20 [ V_14 ] ;
if ( V_19 -> V_2 == V_2 ) {
F_9 ( V_19 , V_6 ) ;
}
}
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_21 * V_22 =
V_2 -> V_23 ;
F_3 ( L_1 , V_3 -> V_4 -> V_5 ) ;
V_22 -> V_24 ( V_2 , V_25 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_21 * V_22 =
V_2 -> V_23 ;
F_3 ( L_1 , V_3 -> V_4 -> V_5 ) ;
V_3 -> V_4 -> V_26 ( V_3 -> V_4 ) ;
V_22 -> V_24 ( V_2 , V_27 ) ;
}
struct V_28 * F_12 (
struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_4 ;
}
struct V_1 * F_13 ( struct V_9 * V_10 ,
struct V_28 * V_4 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
struct V_29 V_30 ;
int V_31 ;
F_3 ( L_1 , V_4 -> V_5 ) ;
V_3 = F_14 ( sizeof( * V_3 ) , V_32 ) ;
if ( ! V_3 ) {
F_15 ( V_10 -> V_10 , L_4 ) ;
goto V_33;
}
V_3 -> V_4 = V_4 ;
V_2 = & V_3 -> V_34 ;
F_16 ( V_10 , V_2 , & V_35 ,
V_36 ) ;
F_17 ( V_2 , & V_37 ) ;
V_4 -> V_38 ( V_4 , & V_30 ) ;
V_30 . V_39 = 0x00000000 ;
V_30 . V_40 = 0x00000000 ;
V_30 . V_41 = V_42 ;
V_30 . V_43 = false ;
V_31 = V_4 -> V_44 ( V_4 , & V_30 ) ;
if ( V_31 ) {
F_15 ( V_10 -> V_10 , L_5 ) ;
goto V_33;
}
V_31 = V_4 -> V_26 ( V_4 ) ;
if ( V_31 ) {
F_15 ( V_10 -> V_10 , L_6 ) ;
goto V_33;
}
return V_2 ;
V_33:
if ( V_2 ) {
F_1 ( V_2 ) ;
}
return NULL ;
}
