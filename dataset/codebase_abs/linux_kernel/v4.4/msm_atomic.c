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
static void F_13 ( struct V_16 * V_13 ,
struct V_9 * V_17 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 = V_17 -> V_13 -> V_15 ;
struct V_20 * V_21 = V_2 -> V_21 ;
int V_22 = V_17 -> V_13 -> V_23 . V_24 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
V_19 = V_17 -> V_26 [ V_25 ] ;
if ( ! V_19 )
continue;
if ( ! V_19 -> V_10 -> V_27 )
continue;
if ( V_17 -> V_28 )
continue;
V_21 -> V_29 -> V_30 ( V_21 , V_19 ) ;
}
}
static void F_14 ( struct V_8 * V_11 )
{
struct V_9 * V_10 = V_11 -> V_10 ;
struct V_16 * V_13 = V_10 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_15 ;
struct V_20 * V_21 = V_2 -> V_21 ;
V_21 -> V_29 -> V_31 ( V_21 , V_10 ) ;
F_15 ( V_13 , V_10 ) ;
F_16 ( V_13 , V_10 , false ) ;
F_17 ( V_13 , V_10 ) ;
F_13 ( V_13 , V_10 ) ;
F_18 ( V_13 , V_10 ) ;
V_21 -> V_29 -> F_14 ( V_21 , V_10 ) ;
F_19 ( V_10 ) ;
F_11 ( V_11 ) ;
}
static void V_14 ( struct V_32 * V_33 )
{
struct V_8 * V_11 =
F_20 ( V_33 , struct V_8 , V_14 ) ;
F_14 ( V_11 ) ;
}
static void F_21 ( struct V_8 * V_11 , struct V_34 * V_35 )
{
struct V_36 * V_37 = F_22 ( V_35 , 0 ) ;
V_11 -> V_38 = F_23 ( V_11 -> V_38 , F_24 ( F_25 ( V_37 ) , V_39 ) ) ;
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
struct V_9 * V_10 , bool V_40 )
{
int V_41 = V_13 -> V_23 . V_42 ;
int V_22 = V_13 -> V_23 . V_24 ;
T_2 V_43 ;
struct V_8 * V_11 ;
int V_25 , V_4 ;
V_4 = F_30 ( V_13 , V_10 ) ;
if ( V_4 )
return V_4 ;
V_11 = F_8 ( V_10 ) ;
if ( ! V_11 ) {
V_4 = - V_44 ;
goto error;
}
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
struct V_18 * V_19 = V_10 -> V_26 [ V_25 ] ;
if ( ! V_19 )
continue;
V_11 -> V_3 |= ( 1 << F_31 ( V_19 ) ) ;
}
for ( V_25 = 0 ; V_25 < V_41 ; V_25 ++ ) {
struct V_45 * V_46 = V_10 -> V_47 [ V_25 ] ;
struct V_48 * V_49 = V_10 -> V_50 [ V_25 ] ;
if ( ! V_46 )
continue;
if ( ( V_46 -> V_10 -> V_35 != V_49 -> V_35 ) && V_49 -> V_35 )
F_21 ( V_11 , V_49 -> V_35 ) ;
}
V_4 = F_1 ( V_13 -> V_15 , V_11 -> V_3 ) ;
if ( V_4 ) {
F_12 ( V_11 ) ;
goto error;
}
F_32 ( V_13 , V_10 ) ;
if ( V_40 ) {
F_33 ( V_13 , & V_11 -> V_14 , V_11 -> V_38 ) ;
return 0 ;
}
V_43 = F_34 ( F_35 () , 1000 ) ;
F_36 ( V_13 , V_11 -> V_38 , & V_43 , false ) ;
F_14 ( V_11 ) ;
return 0 ;
error:
F_18 ( V_13 , V_10 ) ;
return V_4 ;
}
