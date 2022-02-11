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
V_11 -> V_13 = V_10 -> V_13 ;
V_11 -> V_10 = V_10 ;
F_10 ( & V_11 -> V_14 , V_14 ) ;
return V_11 ;
}
static void F_11 ( struct V_8 * V_11 )
{
F_6 ( V_11 -> V_13 -> V_15 , V_11 -> V_3 ) ;
F_12 ( V_11 ) ;
}
static void F_13 ( struct V_8 * V_11 )
{
struct V_9 * V_10 = V_11 -> V_10 ;
struct V_16 * V_13 = V_10 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_15 ;
struct V_17 * V_18 = V_2 -> V_18 ;
V_18 -> V_19 -> V_20 ( V_18 , V_10 ) ;
F_14 ( V_13 , V_10 ) ;
F_15 ( V_13 , V_10 ) ;
F_16 ( V_13 , V_10 ) ;
F_17 ( V_13 , V_10 ) ;
F_18 ( V_13 , V_10 ) ;
V_18 -> V_19 -> F_13 ( V_18 , V_10 ) ;
F_19 ( V_10 ) ;
F_11 ( V_11 ) ;
}
static void V_14 ( struct V_21 * V_22 )
{
struct V_8 * V_11 =
F_20 ( V_22 , struct V_8 , V_14 ) ;
F_13 ( V_11 ) ;
}
static void F_21 ( struct V_8 * V_11 , struct V_23 * V_24 )
{
struct V_25 * V_26 = F_22 ( V_24 , 0 ) ;
V_11 -> V_27 = F_23 ( V_11 -> V_27 , F_24 ( F_25 ( V_26 ) , V_28 ) ) ;
}
int F_26 ( struct V_16 * V_13 ,
struct V_9 * V_10 )
{
int V_4 ;
V_4 = F_27 ( V_13 , V_10 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_28 ( V_13 , V_10 ) ;
if ( V_4 )
return V_4 ;
return V_4 ;
}
int F_29 ( struct V_16 * V_13 ,
struct V_9 * V_10 , bool V_29 )
{
int V_30 = V_13 -> V_31 . V_32 ;
int V_33 = V_13 -> V_31 . V_34 ;
struct V_35 V_36 ;
struct V_8 * V_11 ;
int V_37 , V_4 ;
V_4 = F_30 ( V_13 , V_10 ) ;
if ( V_4 )
return V_4 ;
V_11 = F_8 ( V_10 ) ;
if ( ! V_11 )
return - V_38 ;
for ( V_37 = 0 ; V_37 < V_33 ; V_37 ++ ) {
struct V_39 * V_40 = V_10 -> V_41 [ V_37 ] ;
if ( ! V_40 )
continue;
V_11 -> V_3 |= ( 1 << F_31 ( V_40 ) ) ;
}
for ( V_37 = 0 ; V_37 < V_30 ; V_37 ++ ) {
struct V_42 * V_43 = V_10 -> V_44 [ V_37 ] ;
struct V_45 * V_46 = V_10 -> V_47 [ V_37 ] ;
if ( ! V_43 )
continue;
if ( ( V_43 -> V_10 -> V_24 != V_46 -> V_24 ) && V_46 -> V_24 )
F_21 ( V_11 , V_46 -> V_24 ) ;
}
V_4 = F_1 ( V_13 -> V_15 , V_11 -> V_3 ) ;
if ( V_4 ) {
F_12 ( V_11 ) ;
return V_4 ;
}
F_32 ( V_13 , V_10 ) ;
if ( V_29 ) {
F_33 ( V_13 , & V_11 -> V_14 , V_11 -> V_27 ) ;
return 0 ;
}
F_34 ( V_48 + F_35 ( 1000 ) , & V_36 ) ;
V_4 = F_36 ( V_13 , V_11 -> V_27 , & V_36 ) ;
if ( V_4 ) {
F_37 ( V_4 ) ;
F_11 ( V_11 ) ;
return V_4 ;
}
F_13 ( V_11 ) ;
return 0 ;
}
