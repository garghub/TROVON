static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
V_4 = F_3 ( V_2 -> V_5 ,
! ( V_2 -> V_7 & V_3 ) ) ;
if ( V_4 == 0 ) {
F_4 ( L_1 , V_3 ) ;
V_2 -> V_7 |= V_3 ;
}
F_5 ( & V_2 -> V_5 . V_6 ) ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( & V_2 -> V_5 . V_6 ) ;
F_4 ( L_2 , V_3 ) ;
V_2 -> V_7 &= ~ V_3 ;
F_7 ( & V_2 -> V_5 ) ;
F_5 ( & V_2 -> V_5 . V_6 ) ;
}
static struct V_8 * F_8 ( struct V_9 * V_10 )
{
struct V_8 * V_11 = F_9 ( sizeof( * V_11 ) , V_12 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_10 = V_10 ;
F_10 ( & V_11 -> V_13 , V_13 ) ;
return V_11 ;
}
static void F_11 ( struct V_8 * V_11 )
{
struct V_9 * V_10 = V_11 -> V_10 ;
struct V_14 * V_15 = V_10 -> V_15 ;
F_12 ( V_15 , V_10 ) ;
F_13 ( V_15 , V_10 ) ;
F_14 ( V_15 , V_10 ) ;
F_15 ( V_15 , V_10 ) ;
F_16 ( V_15 , V_10 ) ;
F_17 ( V_10 ) ;
F_6 ( V_15 -> V_16 , V_11 -> V_3 ) ;
F_18 ( V_11 ) ;
}
static void V_13 ( struct V_17 * V_18 )
{
struct V_8 * V_11 =
F_19 ( V_18 , struct V_8 , V_13 ) ;
F_11 ( V_11 ) ;
}
static void F_20 ( struct V_8 * V_11 , struct V_19 * V_20 )
{
struct V_21 * V_22 = F_21 ( V_20 , 0 ) ;
V_11 -> V_23 = F_22 ( V_11 -> V_23 , F_23 ( F_24 ( V_22 ) , V_24 ) ) ;
}
int F_25 ( struct V_14 * V_15 ,
struct V_9 * V_10 , bool V_25 )
{
int V_26 = V_15 -> V_27 . V_28 ;
int V_29 = V_15 -> V_27 . V_30 ;
struct V_8 * V_11 ;
int V_31 , V_4 ;
V_4 = F_26 ( V_15 , V_10 ) ;
if ( V_4 )
return V_4 ;
V_11 = F_8 ( V_10 ) ;
if ( ! V_11 )
return - V_32 ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ ) {
struct V_33 * V_34 = V_10 -> V_35 [ V_31 ] ;
if ( ! V_34 )
continue;
V_11 -> V_3 |= ( 1 << F_27 ( V_34 ) ) ;
}
for ( V_31 = 0 ; V_31 < V_26 ; V_31 ++ ) {
struct V_36 * V_37 = V_10 -> V_38 [ V_31 ] ;
struct V_39 * V_40 = V_10 -> V_41 [ V_31 ] ;
if ( ! V_37 )
continue;
if ( ( V_37 -> V_10 -> V_20 != V_40 -> V_20 ) && V_40 -> V_20 )
F_20 ( V_11 , V_40 -> V_20 ) ;
}
V_4 = F_1 ( V_15 -> V_16 , V_11 -> V_3 ) ;
if ( V_4 )
return V_4 ;
F_28 ( V_15 , V_10 ) ;
if ( V_25 ) {
F_29 ( V_15 , & V_11 -> V_13 , V_11 -> V_23 ) ;
return 0 ;
}
V_4 = F_30 ( V_15 , V_11 -> V_23 , NULL ) ;
if ( V_4 ) {
F_31 ( V_4 ) ;
F_18 ( V_11 ) ;
return V_4 ;
}
F_11 ( V_11 ) ;
return 0 ;
}
