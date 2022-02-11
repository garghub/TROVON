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
F_10 ( & V_11 -> V_14 , V_15 ) ;
return V_11 ;
}
static void F_11 ( struct V_8 * V_11 )
{
F_6 ( V_11 -> V_13 -> V_16 , V_11 -> V_3 ) ;
F_12 ( V_11 ) ;
}
static void F_13 ( struct V_17 * V_13 ,
struct V_9 * V_18 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 = V_18 -> V_13 -> V_16 ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_23 = V_18 -> V_13 -> V_24 . V_25 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_23 ; V_26 ++ ) {
V_20 = V_18 -> V_27 [ V_26 ] ;
if ( ! V_20 )
continue;
if ( ! V_20 -> V_10 -> V_28 )
continue;
if ( V_18 -> V_29 )
continue;
V_22 -> V_30 -> V_31 ( V_22 , V_20 ) ;
}
}
static void F_14 ( struct V_8 * V_11 , bool V_32 )
{
struct V_9 * V_10 = V_11 -> V_10 ;
struct V_17 * V_13 = V_10 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_16 ;
struct V_21 * V_22 = V_2 -> V_22 ;
F_15 ( V_13 , V_10 ) ;
V_22 -> V_30 -> V_33 ( V_22 , V_10 ) ;
F_16 ( V_13 , V_10 ) ;
F_17 ( V_13 , V_10 , false ) ;
F_18 ( V_13 , V_10 ) ;
F_13 ( V_13 , V_10 ) ;
F_19 ( V_13 , V_10 ) ;
V_22 -> V_30 -> F_14 ( V_22 , V_10 ) ;
F_20 ( V_10 ) ;
F_11 ( V_11 ) ;
}
static void V_15 ( struct V_34 * V_14 )
{
F_14 ( F_21 ( V_14 , struct V_8 , V_14 ) , true ) ;
}
int F_22 ( struct V_17 * V_13 ,
struct V_9 * V_10 )
{
int V_4 ;
V_4 = F_23 ( V_13 , V_10 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_24 ( V_13 , V_10 ) ;
if ( V_4 )
return V_4 ;
return V_4 ;
}
int F_25 ( struct V_17 * V_13 ,
struct V_9 * V_10 , bool V_35 )
{
struct V_1 * V_2 = V_13 -> V_16 ;
int V_36 = V_13 -> V_24 . V_37 ;
int V_23 = V_13 -> V_24 . V_25 ;
struct V_8 * V_11 ;
int V_26 , V_4 ;
V_4 = F_26 ( V_13 , V_10 ) ;
if ( V_4 )
return V_4 ;
V_11 = F_8 ( V_10 ) ;
if ( ! V_11 ) {
V_4 = - V_38 ;
goto error;
}
for ( V_26 = 0 ; V_26 < V_23 ; V_26 ++ ) {
struct V_19 * V_20 = V_10 -> V_27 [ V_26 ] ;
if ( ! V_20 )
continue;
V_11 -> V_3 |= ( 1 << F_27 ( V_20 ) ) ;
}
for ( V_26 = 0 ; V_26 < V_36 ; V_26 ++ ) {
struct V_39 * V_40 = V_10 -> V_41 [ V_26 ] ;
struct V_42 * V_43 = V_10 -> V_44 [ V_26 ] ;
if ( ! V_40 )
continue;
if ( ( V_40 -> V_10 -> V_45 != V_43 -> V_45 ) && V_43 -> V_45 ) {
struct V_46 * V_47 = F_28 ( V_43 -> V_45 , 0 ) ;
struct V_48 * V_49 = F_29 ( V_47 ) ;
V_43 -> V_50 = F_30 ( V_49 -> V_51 ) ;
}
}
V_4 = F_1 ( V_13 -> V_16 , V_11 -> V_3 ) ;
if ( V_4 ) {
F_12 ( V_11 ) ;
goto error;
}
F_31 ( V_13 , V_10 ) ;
if ( V_35 ) {
F_32 ( V_2 -> V_52 , & V_11 -> V_14 ) ;
return 0 ;
}
F_14 ( V_11 , false ) ;
return 0 ;
error:
F_19 ( V_13 , V_10 ) ;
return V_4 ;
}
