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
struct V_21 * V_22 ;
struct V_1 * V_2 = V_18 -> V_13 -> V_16 ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_25 ;
F_14 (old_state, crtc, new_crtc_state, i) {
if ( ! V_22 -> V_26 )
continue;
V_24 -> V_27 -> V_28 ( V_24 , V_20 ) ;
}
}
static void F_15 ( struct V_8 * V_11 , bool V_29 )
{
struct V_9 * V_10 = V_11 -> V_10 ;
struct V_17 * V_13 = V_10 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_16 ;
struct V_23 * V_24 = V_2 -> V_24 ;
F_16 ( V_13 , V_10 , false ) ;
V_24 -> V_27 -> V_30 ( V_24 , V_10 ) ;
F_17 ( V_13 , V_10 ) ;
F_18 ( V_13 , V_10 , 0 ) ;
F_19 ( V_13 , V_10 ) ;
F_13 ( V_13 , V_10 ) ;
F_20 ( V_13 , V_10 ) ;
V_24 -> V_27 -> F_15 ( V_24 , V_10 ) ;
F_21 ( V_10 ) ;
F_11 ( V_11 ) ;
}
static void V_15 ( struct V_31 * V_14 )
{
F_15 ( F_22 ( V_14 , struct V_8 , V_14 ) , true ) ;
}
int F_23 ( struct V_17 * V_13 ,
struct V_9 * V_10 )
{
int V_4 ;
V_4 = F_24 ( V_13 , V_10 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_25 ( V_13 , V_10 ) ;
if ( V_4 )
return V_4 ;
return V_4 ;
}
int F_26 ( struct V_17 * V_13 ,
struct V_9 * V_10 , bool V_32 )
{
struct V_1 * V_2 = V_13 -> V_16 ;
struct V_8 * V_11 ;
struct V_19 * V_20 ;
struct V_21 * V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 , * V_38 ;
int V_25 , V_4 ;
V_4 = F_27 ( V_13 , V_10 ) ;
if ( V_4 )
return V_4 ;
V_11 = F_8 ( V_10 ) ;
if ( ! V_11 ) {
V_4 = - V_39 ;
goto error;
}
F_14 (state, crtc, crtc_state, i)
V_11 -> V_3 |= F_28 ( V_20 ) ;
F_29 (state, plane, old_plane_state, new_plane_state, i) {
if ( ( V_38 -> V_40 != V_37 -> V_40 ) && V_38 -> V_40 ) {
struct V_41 * V_42 = F_30 ( V_38 -> V_40 , 0 ) ;
struct V_43 * V_44 = F_31 ( V_42 ) ;
struct V_45 * V_46 = F_32 ( V_44 -> V_47 ) ;
F_33 ( V_38 , V_46 ) ;
}
}
V_4 = F_1 ( V_13 -> V_16 , V_11 -> V_3 ) ;
if ( V_4 )
goto V_48;
F_34 ( F_35 ( V_10 , false ) < 0 ) ;
if ( F_36 ( V_10 ) -> V_10 )
V_2 -> V_24 -> V_27 -> V_49 ( V_2 -> V_24 , V_10 ) ;
F_37 ( V_10 ) ;
if ( V_32 ) {
F_38 ( V_2 -> V_50 , & V_11 -> V_14 ) ;
return 0 ;
}
F_15 ( V_11 , false ) ;
return 0 ;
V_48:
F_12 ( V_11 ) ;
error:
F_20 ( V_13 , V_10 ) ;
return V_4 ;
}
struct V_9 * F_39 ( struct V_17 * V_13 )
{
struct V_51 * V_10 = F_9 ( sizeof( * V_10 ) , V_12 ) ;
if ( ! V_10 || F_40 ( V_13 , & V_10 -> V_52 ) < 0 ) {
F_12 ( V_10 ) ;
return NULL ;
}
return & V_10 -> V_52 ;
}
void F_41 ( struct V_9 * V_53 )
{
struct V_51 * V_10 = F_36 ( V_53 ) ;
F_42 ( & V_10 -> V_52 ) ;
F_12 ( V_10 -> V_10 ) ;
V_10 -> V_10 = NULL ;
}
void F_43 ( struct V_9 * V_10 )
{
F_12 ( F_36 ( V_10 ) -> V_10 ) ;
F_44 ( V_10 ) ;
F_12 ( V_10 ) ;
}
