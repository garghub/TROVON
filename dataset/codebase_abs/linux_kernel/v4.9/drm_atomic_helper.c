static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
if ( V_6 -> V_2 -> V_9 ) {
V_8 = F_2 ( V_2 ,
V_6 -> V_2 -> V_9 ) ;
if ( F_3 ( ! V_8 ) )
return;
V_8 -> V_10 = true ;
}
if ( V_4 -> V_9 ) {
V_8 = F_2 ( V_2 ,
V_4 -> V_9 ) ;
if ( F_3 ( ! V_8 ) )
return;
V_8 -> V_10 = true ;
}
}
static int F_4 ( struct V_1 * V_2 ,
bool V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
unsigned V_18 = 0 ;
int V_19 , V_20 ;
F_5 (state, connector, conn_state, i) {
const struct V_21 * V_22 = V_15 -> V_23 ;
struct V_16 * V_24 ;
if ( ! V_13 -> V_9 )
continue;
if ( V_22 -> V_25 )
V_24 = V_22 -> V_25 ( V_15 , V_13 ) ;
else if ( V_22 -> V_26 )
V_24 = V_22 -> V_26 ( V_15 ) ;
else
V_24 = F_6 ( V_15 ) ;
if ( V_24 ) {
if ( V_18 & ( 1 << F_7 ( V_24 ) ) ) {
F_8 ( L_1 ,
V_24 -> V_27 . V_28 , V_24 -> V_29 ,
V_15 -> V_27 . V_28 , V_15 -> V_29 ) ;
return - V_30 ;
}
V_18 |= 1 << F_7 ( V_24 ) ;
}
}
if ( ! V_18 )
return 0 ;
F_9 (connector, state->dev) {
struct V_7 * V_8 ;
if ( F_10 ( V_2 , V_15 ) )
continue;
V_17 = V_15 -> V_2 -> V_26 ;
if ( ! V_17 || ! ( V_18 & ( 1 << F_7 ( V_17 ) ) ) )
continue;
if ( ! V_11 ) {
F_8 ( L_2 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ,
V_15 -> V_2 -> V_9 -> V_27 . V_28 ,
V_15 -> V_2 -> V_9 -> V_29 ,
V_15 -> V_27 . V_28 , V_15 -> V_29 ) ;
return - V_30 ;
}
V_13 = F_11 ( V_2 , V_15 ) ;
if ( F_12 ( V_13 ) )
return F_13 ( V_13 ) ;
F_8 ( L_3 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ,
V_13 -> V_9 -> V_27 . V_28 , V_13 -> V_9 -> V_29 ,
V_15 -> V_27 . V_28 , V_15 -> V_29 ) ;
V_8 = F_2 ( V_2 , V_13 -> V_9 ) ;
V_20 = F_14 ( V_13 , NULL ) ;
if ( V_20 )
return V_20 ;
if ( ! V_8 -> V_31 ) {
V_20 = F_15 ( V_8 ,
NULL ) ;
if ( V_20 < 0 )
return V_20 ;
V_8 -> V_32 = false ;
}
}
return 0 ;
}
static void
F_16 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_16 * V_17 )
{
struct V_7 * V_8 ;
struct V_33 * V_9 ;
if ( V_13 -> V_26 ) {
V_9 = V_13 -> V_15 -> V_2 -> V_9 ;
F_3 ( ! V_9 && V_17 != V_13 -> V_26 ) ;
if ( V_9 ) {
V_8 = F_2 ( V_2 , V_9 ) ;
V_8 -> V_18 &=
~ ( 1 << F_7 ( V_13 -> V_26 ) ) ;
}
}
if ( V_17 ) {
V_9 = V_13 -> V_9 ;
F_3 ( ! V_9 ) ;
if ( V_9 ) {
V_8 = F_2 ( V_2 , V_9 ) ;
V_8 -> V_18 |=
1 << F_7 ( V_17 ) ;
}
}
V_13 -> V_26 = V_17 ;
}
static void
F_17 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_12 * V_34 ;
int V_19 ;
F_5 (state, connector, connector_state, i) {
struct V_33 * V_35 ;
if ( V_34 -> V_26 != V_17 )
continue;
V_35 = V_15 -> V_2 -> V_9 ;
F_8 ( L_4 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ,
V_35 -> V_27 . V_28 , V_35 -> V_29 ) ;
F_16 ( V_2 , V_34 , NULL ) ;
V_8 = F_2 ( V_2 , V_35 ) ;
V_8 -> V_36 = true ;
return;
}
}
static int
F_18 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_12 * V_34 )
{
const struct V_21 * V_22 ;
struct V_16 * V_24 ;
struct V_7 * V_8 ;
F_8 ( L_5 ,
V_15 -> V_27 . V_28 ,
V_15 -> V_29 ) ;
if ( V_15 -> V_2 -> V_9 != V_34 -> V_9 ) {
if ( V_15 -> V_2 -> V_9 ) {
V_8 = F_2 ( V_2 , V_15 -> V_2 -> V_9 ) ;
V_8 -> V_36 = true ;
}
if ( V_34 -> V_9 ) {
V_8 = F_2 ( V_2 , V_34 -> V_9 ) ;
V_8 -> V_36 = true ;
}
}
if ( ! V_34 -> V_9 ) {
F_8 ( L_6 ,
V_15 -> V_27 . V_28 ,
V_15 -> V_29 ) ;
F_16 ( V_2 , V_34 , NULL ) ;
return 0 ;
}
V_22 = V_15 -> V_23 ;
if ( V_22 -> V_25 )
V_24 = V_22 -> V_25 ( V_15 ,
V_34 ) ;
else if ( V_22 -> V_26 )
V_24 = V_22 -> V_26 ( V_15 ) ;
else
V_24 = F_6 ( V_15 ) ;
if ( ! V_24 ) {
F_8 ( L_7 ,
V_15 -> V_27 . V_28 ,
V_15 -> V_29 ) ;
return - V_30 ;
}
if ( ! F_19 ( V_24 , V_34 -> V_9 ) ) {
F_8 ( L_8 ,
V_24 -> V_27 . V_28 ,
V_24 -> V_29 ,
V_34 -> V_9 -> V_27 . V_28 ) ;
return - V_30 ;
}
if ( V_24 == V_34 -> V_26 ) {
F_16 ( V_2 , V_34 , V_24 ) ;
F_8 ( L_9 ,
V_15 -> V_27 . V_28 ,
V_15 -> V_29 ,
V_24 -> V_27 . V_28 ,
V_24 -> V_29 ,
V_34 -> V_9 -> V_27 . V_28 ,
V_34 -> V_9 -> V_29 ) ;
return 0 ;
}
F_17 ( V_2 , V_24 ) ;
F_16 ( V_2 , V_34 , V_24 ) ;
V_8 = F_2 ( V_2 , V_34 -> V_9 ) ;
V_8 -> V_36 = true ;
F_8 ( L_10 ,
V_15 -> V_27 . V_28 ,
V_15 -> V_29 ,
V_24 -> V_27 . V_28 ,
V_24 -> V_29 ,
V_34 -> V_9 -> V_27 . V_28 ,
V_34 -> V_9 -> V_29 ) ;
return 0 ;
}
static int
F_20 ( struct V_1 * V_2 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_12 * V_13 ;
int V_19 ;
bool V_20 ;
F_21 (state, crtc, crtc_state, i) {
if ( ! V_8 -> V_37 &&
! V_8 -> V_36 )
continue;
F_22 ( & V_8 -> V_38 , & V_8 -> V_39 ) ;
}
F_5 (state, connector, conn_state, i) {
const struct V_40 * V_22 ;
struct V_16 * V_17 ;
F_3 ( ! ! V_13 -> V_26 != ! ! V_13 -> V_9 ) ;
if ( ! V_13 -> V_9 || ! V_13 -> V_26 )
continue;
V_8 = F_2 ( V_2 ,
V_13 -> V_9 ) ;
V_17 = V_13 -> V_26 ;
V_22 = V_17 -> V_23 ;
V_20 = F_23 ( V_17 -> V_41 , & V_8 -> V_39 ,
& V_8 -> V_38 ) ;
if ( ! V_20 ) {
F_8 ( L_11 ) ;
return - V_30 ;
}
if ( V_22 && V_22 -> V_42 ) {
V_20 = V_22 -> V_42 ( V_17 , V_8 ,
V_13 ) ;
if ( V_20 ) {
F_8 ( L_12 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ) ;
return V_20 ;
}
} else if ( V_22 && V_22 -> F_20 ) {
V_20 = V_22 -> F_20 ( V_17 , & V_8 -> V_39 ,
& V_8 -> V_38 ) ;
if ( ! V_20 ) {
F_8 ( L_13 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ) ;
return - V_30 ;
}
}
}
F_21 (state, crtc, crtc_state, i) {
const struct V_43 * V_22 ;
if ( ! V_8 -> V_44 )
continue;
if ( ! V_8 -> V_37 &&
! V_8 -> V_36 )
continue;
V_22 = V_9 -> V_23 ;
if ( ! V_22 -> F_20 )
continue;
V_20 = V_22 -> F_20 ( V_9 , & V_8 -> V_39 ,
& V_8 -> V_38 ) ;
if ( ! V_20 ) {
F_8 ( L_14 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
return - V_30 ;
}
}
return 0 ;
}
int
F_24 ( struct V_45 * V_46 ,
struct V_1 * V_2 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_12 * V_34 ;
int V_19 , V_20 ;
F_21 (state, crtc, crtc_state, i) {
if ( ! F_25 ( & V_9 -> V_2 -> V_39 , & V_8 -> V_39 ) ) {
F_8 ( L_15 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
V_8 -> V_37 = true ;
}
if ( V_9 -> V_2 -> V_44 != V_8 -> V_44 ) {
F_8 ( L_16 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
V_8 -> V_37 = true ;
V_8 -> V_36 = true ;
}
}
V_20 = F_4 ( V_2 , V_2 -> V_47 ) ;
if ( V_20 )
return V_20 ;
F_5 (state, connector, connector_state, i) {
V_20 = F_18 ( V_2 , V_15 ,
V_34 ) ;
if ( V_20 )
return V_20 ;
}
F_21 (state, crtc, crtc_state, i) {
bool V_48 =
! ! V_8 -> V_31 ;
if ( V_9 -> V_2 -> V_32 != V_8 -> V_32 ) {
F_8 ( L_17 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
V_8 -> V_49 = true ;
}
if ( ! F_26 ( V_8 ) )
continue;
F_8 ( L_18 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ,
V_8 -> V_44 ? 'y' : 'n' ,
V_8 -> V_32 ? 'y' : 'n' ) ;
V_20 = F_27 ( V_2 , V_9 ) ;
if ( V_20 != 0 )
return V_20 ;
V_20 = F_28 ( V_2 , V_9 ) ;
if ( V_20 != 0 )
return V_20 ;
if ( V_8 -> V_44 != V_48 ) {
F_8 ( L_19 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
return - V_30 ;
}
}
return F_20 ( V_2 ) ;
}
int
F_29 ( struct V_45 * V_46 ,
struct V_1 * V_2 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_19 , V_20 = 0 ;
F_30 (state, plane, plane_state, i) {
const struct V_50 * V_22 ;
V_22 = V_6 -> V_23 ;
F_1 ( V_2 , V_4 , V_6 ) ;
if ( ! V_22 || ! V_22 -> V_42 )
continue;
V_20 = V_22 -> V_42 ( V_6 , V_4 ) ;
if ( V_20 ) {
F_8 ( L_20 ,
V_6 -> V_27 . V_28 , V_6 -> V_29 ) ;
return V_20 ;
}
}
F_21 (state, crtc, crtc_state, i) {
const struct V_43 * V_22 ;
V_22 = V_9 -> V_23 ;
if ( ! V_22 || ! V_22 -> V_42 )
continue;
V_20 = V_22 -> V_42 ( V_9 , V_8 ) ;
if ( V_20 ) {
F_8 ( L_21 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
return V_20 ;
}
}
return V_20 ;
}
int F_31 ( struct V_45 * V_46 ,
struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_24 ( V_46 , V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_29 ( V_46 , V_2 ) ;
if ( V_20 )
return V_20 ;
return V_20 ;
}
static void
F_32 ( struct V_45 * V_46 , struct V_1 * V_51 )
{
struct V_14 * V_15 ;
struct V_12 * V_52 ;
struct V_33 * V_9 ;
struct V_7 * V_53 ;
int V_19 ;
F_5 (old_state, connector, old_conn_state, i) {
const struct V_40 * V_22 ;
struct V_16 * V_17 ;
if ( ! V_52 -> V_9 )
continue;
V_53 = F_2 ( V_51 ,
V_52 -> V_9 ) ;
if ( ! V_53 -> V_32 ||
! F_26 ( V_52 -> V_9 -> V_2 ) )
continue;
V_17 = V_52 -> V_26 ;
if ( F_3 ( ! V_17 ) )
continue;
V_22 = V_17 -> V_23 ;
F_8 ( L_22 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ) ;
F_33 ( V_17 -> V_41 ) ;
if ( V_22 ) {
if ( V_15 -> V_2 -> V_9 && V_22 -> V_54 )
V_22 -> V_54 ( V_17 ) ;
else if ( V_22 -> V_55 )
V_22 -> V_55 ( V_17 ) ;
else if ( V_22 -> V_56 )
V_22 -> V_56 ( V_17 , V_57 ) ;
}
F_34 ( V_17 -> V_41 ) ;
}
F_21 (old_state, crtc, old_crtc_state, i) {
const struct V_43 * V_22 ;
if ( ! F_26 ( V_9 -> V_2 ) )
continue;
if ( ! V_53 -> V_32 )
continue;
V_22 = V_9 -> V_23 ;
F_8 ( L_23 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
if ( V_9 -> V_2 -> V_44 && V_22 -> V_54 )
V_22 -> V_54 ( V_9 ) ;
else if ( V_22 -> V_58 )
V_22 -> V_58 ( V_9 , V_53 ) ;
else if ( V_22 -> V_55 )
V_22 -> V_55 ( V_9 ) ;
else
V_22 -> V_56 ( V_9 , V_57 ) ;
}
}
void
F_35 ( struct V_45 * V_46 ,
struct V_1 * V_51 )
{
struct V_14 * V_15 ;
struct V_12 * V_52 ;
struct V_33 * V_9 ;
struct V_7 * V_53 ;
int V_19 ;
F_5 (old_state, connector, old_conn_state, i) {
if ( V_15 -> V_17 ) {
F_3 ( ! V_15 -> V_17 -> V_9 ) ;
V_15 -> V_17 -> V_9 = NULL ;
V_15 -> V_17 = NULL ;
}
V_9 = V_15 -> V_2 -> V_9 ;
if ( ( ! V_9 && V_52 -> V_9 ) ||
( V_9 && F_26 ( V_9 -> V_2 ) ) ) {
struct V_59 * V_60 =
V_46 -> V_61 . V_62 ;
int V_39 = V_57 ;
if ( V_9 && V_9 -> V_2 -> V_32 )
V_39 = V_63 ;
V_15 -> V_56 = V_39 ;
F_36 ( & V_15 -> V_27 ,
V_60 , V_39 ) ;
}
}
F_5 (old_state, connector, old_conn_state, i) {
if ( ! V_15 -> V_2 -> V_9 )
continue;
if ( F_3 ( ! V_15 -> V_2 -> V_26 ) )
continue;
V_15 -> V_17 = V_15 -> V_2 -> V_26 ;
V_15 -> V_17 -> V_9 = V_15 -> V_2 -> V_9 ;
}
F_21 (old_state, crtc, old_crtc_state, i) {
struct V_5 * V_64 = V_9 -> V_64 ;
V_9 -> V_39 = V_9 -> V_2 -> V_39 ;
V_9 -> V_65 = V_9 -> V_2 -> V_44 ;
if ( F_37 ( V_51 , V_64 ) &&
V_64 -> V_2 -> V_9 == V_9 ) {
V_9 -> V_66 = V_64 -> V_2 -> V_67 >> 16 ;
V_9 -> V_68 = V_64 -> V_2 -> V_69 >> 16 ;
}
if ( V_9 -> V_2 -> V_44 )
F_38 ( V_9 ,
& V_9 -> V_2 -> V_38 ) ;
}
}
static void
F_39 ( struct V_45 * V_46 , struct V_1 * V_51 )
{
struct V_33 * V_9 ;
struct V_7 * V_53 ;
struct V_14 * V_15 ;
struct V_12 * V_52 ;
int V_19 ;
F_21 (old_state, crtc, old_crtc_state, i) {
const struct V_43 * V_22 ;
if ( ! V_9 -> V_2 -> V_37 )
continue;
V_22 = V_9 -> V_23 ;
if ( V_9 -> V_2 -> V_44 && V_22 -> V_70 ) {
F_8 ( L_24 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
V_22 -> V_70 ( V_9 ) ;
}
}
F_5 (old_state, connector, old_conn_state, i) {
const struct V_40 * V_22 ;
struct V_7 * V_71 ;
struct V_16 * V_17 ;
struct V_72 * V_39 , * V_38 ;
if ( ! V_15 -> V_2 -> V_26 )
continue;
V_17 = V_15 -> V_2 -> V_26 ;
V_22 = V_17 -> V_23 ;
V_71 = V_15 -> V_2 -> V_9 -> V_2 ;
V_39 = & V_71 -> V_39 ;
V_38 = & V_71 -> V_38 ;
if ( ! V_71 -> V_37 )
continue;
F_8 ( L_25 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ) ;
if ( V_22 && V_22 -> V_73 ) {
V_22 -> V_73 ( V_17 , V_71 ,
V_15 -> V_2 ) ;
} else if ( V_22 && V_22 -> V_74 ) {
V_22 -> V_74 ( V_17 , V_39 , V_38 ) ;
}
F_40 ( V_17 -> V_41 , V_39 , V_38 ) ;
}
}
void F_41 ( struct V_45 * V_46 ,
struct V_1 * V_51 )
{
F_32 ( V_46 , V_51 ) ;
F_35 ( V_46 , V_51 ) ;
F_39 ( V_46 , V_51 ) ;
}
void F_42 ( struct V_45 * V_46 ,
struct V_1 * V_51 )
{
struct V_33 * V_9 ;
struct V_7 * V_53 ;
struct V_14 * V_15 ;
struct V_12 * V_52 ;
int V_19 ;
F_21 (old_state, crtc, old_crtc_state, i) {
const struct V_43 * V_22 ;
if ( ! F_26 ( V_9 -> V_2 ) )
continue;
if ( ! V_9 -> V_2 -> V_32 )
continue;
V_22 = V_9 -> V_23 ;
if ( V_9 -> V_2 -> V_44 ) {
F_8 ( L_26 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
if ( V_22 -> V_44 )
V_22 -> V_44 ( V_9 ) ;
else
V_22 -> V_75 ( V_9 ) ;
}
}
F_5 (old_state, connector, old_conn_state, i) {
const struct V_40 * V_22 ;
struct V_16 * V_17 ;
if ( ! V_15 -> V_2 -> V_26 )
continue;
if ( ! V_15 -> V_2 -> V_9 -> V_2 -> V_32 ||
! F_26 ( V_15 -> V_2 -> V_9 -> V_2 ) )
continue;
V_17 = V_15 -> V_2 -> V_26 ;
V_22 = V_17 -> V_23 ;
F_8 ( L_27 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ) ;
F_43 ( V_17 -> V_41 ) ;
if ( V_22 ) {
if ( V_22 -> V_44 )
V_22 -> V_44 ( V_17 ) ;
else if ( V_22 -> V_75 )
V_22 -> V_75 ( V_17 ) ;
}
F_44 ( V_17 -> V_41 ) ;
}
}
int F_45 ( struct V_45 * V_46 ,
struct V_1 * V_2 ,
bool V_76 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_19 , V_20 ;
F_30 (state, plane, plane_state, i) {
if ( ! V_76 )
V_4 = V_6 -> V_2 ;
if ( ! V_4 -> V_77 )
continue;
F_3 ( ! V_4 -> V_78 ) ;
V_20 = F_46 ( V_4 -> V_77 , V_76 ) ;
if ( V_20 )
return V_20 ;
F_47 ( V_4 -> V_77 ) ;
V_4 -> V_77 = NULL ;
}
return 0 ;
}
bool F_48 ( struct V_45 * V_46 ,
struct V_1 * V_51 ,
struct V_33 * V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_79 ;
int V_19 ;
F_30 (old_state, plane, old_plane_state, i) {
if ( V_6 -> V_2 -> V_9 != V_9 &&
V_79 -> V_9 != V_9 )
continue;
if ( V_6 -> V_2 -> V_78 != V_79 -> V_78 )
return true ;
}
return false ;
}
void
F_49 ( struct V_45 * V_46 ,
struct V_1 * V_51 )
{
struct V_33 * V_9 ;
struct V_7 * V_53 ;
int V_19 , V_20 ;
F_21 (old_state, crtc, old_crtc_state, i) {
V_53 -> V_44 = false ;
if ( ! V_9 -> V_2 -> V_44 )
continue;
if ( V_51 -> V_80 )
continue;
if ( ! F_48 ( V_46 ,
V_51 , V_9 ) )
continue;
V_20 = F_50 ( V_9 ) ;
if ( V_20 != 0 )
continue;
V_53 -> V_44 = true ;
V_53 -> V_81 = F_51 ( V_9 ) ;
}
F_21 (old_state, crtc, old_crtc_state, i) {
if ( ! V_53 -> V_44 )
continue;
V_20 = F_52 ( V_46 -> V_82 [ V_19 ] . V_83 ,
V_53 -> V_81 !=
F_51 ( V_9 ) ,
F_53 ( 50 ) ) ;
F_54 ( ! V_20 , L_28 , V_9 -> V_27 . V_28 ) ;
F_55 ( V_9 ) ;
}
}
void F_56 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
F_41 ( V_46 , V_2 ) ;
F_57 ( V_46 , V_2 , 0 ) ;
F_42 ( V_46 , V_2 ) ;
F_58 ( V_2 ) ;
F_49 ( V_46 , V_2 ) ;
F_59 ( V_46 , V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_84 * V_22 ;
V_22 = V_46 -> V_61 . V_23 ;
F_45 ( V_46 , V_2 , false ) ;
F_61 ( V_2 ) ;
if ( V_22 && V_22 -> V_85 )
V_22 -> V_85 ( V_2 ) ;
else
F_56 ( V_2 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
}
static void F_64 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_65 ( V_87 ,
struct V_1 ,
F_64 ) ;
F_60 ( V_2 ) ;
}
int F_66 ( struct V_45 * V_46 ,
struct V_1 * V_2 ,
bool V_88 )
{
int V_20 ;
V_20 = F_67 ( V_2 , V_88 ) ;
if ( V_20 )
return V_20 ;
F_68 ( & V_2 -> F_64 , F_64 ) ;
V_20 = F_69 ( V_46 , V_2 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_88 ) {
V_20 = F_45 ( V_46 , V_2 , true ) ;
if ( V_20 )
return V_20 ;
}
F_70 ( V_2 , true ) ;
if ( V_88 )
F_71 ( V_89 , & V_2 -> F_64 ) ;
else
F_60 ( V_2 ) ;
return 0 ;
}
static int F_72 ( struct V_33 * V_9 , bool V_88 )
{
struct V_90 * V_75 , * V_91 = NULL ;
bool V_92 = true ;
int V_19 ;
long V_20 = 0 ;
F_73 ( & V_9 -> V_93 ) ;
V_19 = 0 ;
F_74 (commit, &crtc->commit_list, commit_entry) {
if ( V_19 == 0 ) {
V_92 = F_75 ( & V_75 -> V_94 ) ;
if ( ! V_92 && V_88 ) {
F_76 ( & V_9 -> V_93 ) ;
return - V_95 ;
}
} else if ( V_19 == 1 ) {
V_91 = V_75 ;
F_77 ( V_91 ) ;
break;
}
V_19 ++ ;
}
F_76 ( & V_9 -> V_93 ) ;
if ( ! V_91 )
return 0 ;
V_20 = F_78 ( & V_91 -> V_96 ,
10 * V_97 ) ;
if ( V_20 == 0 )
F_79 ( L_29 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
F_80 ( V_91 ) ;
return V_20 < 0 ? V_20 : 0 ;
}
int F_67 ( struct V_1 * V_2 ,
bool V_88 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_90 * V_75 ;
int V_19 , V_20 ;
F_21 (state, crtc, crtc_state, i) {
V_75 = F_81 ( sizeof( * V_75 ) , V_98 ) ;
if ( ! V_75 )
return - V_99 ;
F_82 ( & V_75 -> V_94 ) ;
F_82 ( & V_75 -> V_100 ) ;
F_82 ( & V_75 -> V_96 ) ;
F_83 ( & V_75 -> V_101 ) ;
F_84 ( & V_75 -> V_102 ) ;
V_75 -> V_9 = V_9 ;
V_2 -> V_103 [ V_19 ] . V_75 = V_75 ;
V_20 = F_72 ( V_9 , V_88 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_9 -> V_2 -> V_32 && ! V_8 -> V_32 ) {
F_85 ( & V_75 -> V_94 ) ;
continue;
}
if ( V_2 -> V_80 ) {
F_85 ( & V_75 -> V_94 ) ;
continue;
}
if ( ! V_8 -> V_104 ) {
V_75 -> V_104 = F_81 ( sizeof( * V_75 -> V_104 ) ,
V_98 ) ;
if ( ! V_75 -> V_104 )
return - V_99 ;
V_8 -> V_104 = V_75 -> V_104 ;
}
V_8 -> V_104 -> V_27 . V_105 = & V_75 -> V_94 ;
}
return 0 ;
}
static struct V_90 * F_86 ( struct V_33 * V_9 )
{
struct V_90 * V_75 ;
int V_19 = 0 ;
F_74 (commit, &crtc->commit_list, commit_entry) {
if ( V_19 == 1 )
return V_75 ;
V_19 ++ ;
}
return NULL ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_90 * V_75 ;
int V_19 ;
long V_20 ;
F_21 (state, crtc, crtc_state, i) {
F_73 ( & V_9 -> V_93 ) ;
V_75 = F_86 ( V_9 ) ;
if ( V_75 )
F_77 ( V_75 ) ;
F_76 ( & V_9 -> V_93 ) ;
if ( ! V_75 )
continue;
V_20 = F_87 ( & V_75 -> V_100 ,
10 * V_97 ) ;
if ( V_20 == 0 )
F_79 ( L_30 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
V_20 = F_87 ( & V_75 -> V_94 ,
10 * V_97 ) ;
if ( V_20 == 0 )
F_79 ( L_31 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
F_80 ( V_75 ) ;
}
}
void F_58 ( struct V_1 * V_2 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_90 * V_75 ;
int V_19 ;
F_21 (state, crtc, crtc_state, i) {
V_75 = V_2 -> V_103 [ V_19 ] . V_75 ;
if ( ! V_75 )
continue;
F_3 ( V_9 -> V_2 -> V_104 ) ;
F_73 ( & V_9 -> V_93 ) ;
F_85 ( & V_75 -> V_100 ) ;
F_76 ( & V_9 -> V_93 ) ;
}
}
void F_62 ( struct V_1 * V_2 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_90 * V_75 ;
int V_19 ;
long V_20 ;
F_21 (state, crtc, crtc_state, i) {
V_75 = V_2 -> V_103 [ V_19 ] . V_75 ;
if ( F_3 ( ! V_75 ) )
continue;
F_73 ( & V_9 -> V_93 ) ;
F_85 ( & V_75 -> V_96 ) ;
F_3 ( ! F_75 ( & V_75 -> V_100 ) ) ;
if ( F_75 ( & V_75 -> V_94 ) )
goto V_106;
F_76 ( & V_9 -> V_93 ) ;
V_20 = F_87 ( & V_75 -> V_94 ,
10 * V_97 ) ;
if ( V_20 == 0 )
F_79 ( L_31 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
F_73 ( & V_9 -> V_93 ) ;
V_106:
F_88 ( & V_75 -> V_101 ) ;
F_76 ( & V_9 -> V_93 ) ;
}
}
int F_69 ( struct V_45 * V_46 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_20 , V_19 , V_107 ;
F_30 (state, plane, plane_state, i) {
const struct V_50 * V_22 ;
V_22 = V_6 -> V_23 ;
if ( ! F_48 ( V_46 , V_2 , V_4 -> V_9 ) )
continue;
if ( V_22 -> V_108 ) {
V_20 = V_22 -> V_108 ( V_6 , V_4 ) ;
if ( V_20 )
goto V_109;
}
}
return 0 ;
V_109:
F_30 (state, plane, plane_state, j) {
const struct V_50 * V_22 ;
if ( V_107 >= V_19 )
continue;
if ( ! F_48 ( V_46 , V_2 , V_4 -> V_9 ) )
continue;
V_22 = V_6 -> V_23 ;
if ( V_22 -> V_110 )
V_22 -> V_110 ( V_6 , V_4 ) ;
}
return V_20 ;
}
static bool F_89 ( const struct V_3 * V_2 )
{
return V_2 -> V_9 && V_2 -> V_9 -> V_2 -> V_32 ;
}
void F_57 ( struct V_45 * V_46 ,
struct V_1 * V_51 ,
T_1 V_111 )
{
struct V_33 * V_9 ;
struct V_7 * V_53 ;
struct V_5 * V_6 ;
struct V_3 * V_79 ;
int V_19 ;
bool V_112 = V_111 & V_113 ;
bool V_114 = V_111 & V_115 ;
F_21 (old_state, crtc, old_crtc_state, i) {
const struct V_43 * V_22 ;
V_22 = V_9 -> V_23 ;
if ( ! V_22 || ! V_22 -> V_116 )
continue;
if ( V_112 && ! V_9 -> V_2 -> V_32 )
continue;
V_22 -> V_116 ( V_9 , V_53 ) ;
}
F_30 (old_state, plane, old_plane_state, i) {
const struct V_50 * V_22 ;
bool V_117 ;
V_22 = V_6 -> V_23 ;
if ( ! V_22 )
continue;
V_117 = F_90 ( V_6 , V_79 ) ;
if ( V_112 ) {
if ( ! V_117 && ! F_89 ( V_6 -> V_2 ) )
continue;
if ( V_117 && ! F_89 ( V_79 ) )
continue;
}
if ( V_117 && V_22 -> V_58 ) {
struct V_7 * V_8 ;
V_8 = V_79 -> V_9 -> V_2 ;
if ( F_26 ( V_8 ) &&
V_114 )
continue;
V_22 -> V_58 ( V_6 , V_79 ) ;
} else if ( V_6 -> V_2 -> V_9 || V_117 ) {
V_22 -> V_118 ( V_6 , V_79 ) ;
}
}
F_21 (old_state, crtc, old_crtc_state, i) {
const struct V_43 * V_22 ;
V_22 = V_9 -> V_23 ;
if ( ! V_22 || ! V_22 -> V_119 )
continue;
if ( V_112 && ! V_9 -> V_2 -> V_32 )
continue;
V_22 -> V_119 ( V_9 , V_53 ) ;
}
}
void
F_91 ( struct V_7 * V_53 )
{
const struct V_43 * V_120 ;
struct V_33 * V_9 = V_53 -> V_9 ;
struct V_1 * V_51 = V_53 -> V_2 ;
struct V_5 * V_6 ;
unsigned V_121 ;
V_121 = V_53 -> V_121 ;
V_121 |= V_9 -> V_2 -> V_121 ;
V_120 = V_9 -> V_23 ;
if ( V_120 && V_120 -> V_116 )
V_120 -> V_116 ( V_9 , V_53 ) ;
F_92 (plane, crtc->dev, plane_mask) {
struct V_3 * V_79 =
F_37 ( V_51 , V_6 ) ;
const struct V_50 * V_122 ;
V_122 = V_6 -> V_23 ;
if ( ! V_79 || ! V_122 )
continue;
F_3 ( V_6 -> V_2 -> V_9 && V_6 -> V_2 -> V_9 != V_9 ) ;
if ( F_90 ( V_6 , V_79 ) &&
V_122 -> V_58 )
V_122 -> V_58 ( V_6 , V_79 ) ;
else if ( V_6 -> V_2 -> V_9 ||
F_90 ( V_6 , V_79 ) )
V_122 -> V_118 ( V_6 , V_79 ) ;
}
if ( V_120 && V_120 -> V_119 )
V_120 -> V_119 ( V_9 , V_53 ) ;
}
void
F_93 ( struct V_7 * V_53 ,
bool V_123 )
{
struct V_33 * V_9 = V_53 -> V_9 ;
const struct V_43 * V_120 =
V_9 -> V_23 ;
struct V_5 * V_6 ;
if ( V_123 && V_120 && V_120 -> V_116 )
V_120 -> V_116 ( V_9 , NULL ) ;
F_94 (plane, old_crtc_state) {
const struct V_50 * V_122 =
V_6 -> V_23 ;
if ( ! V_122 )
continue;
F_3 ( ! V_122 -> V_58 ) ;
if ( V_122 -> V_58 )
V_122 -> V_58 ( V_6 , NULL ) ;
}
if ( V_123 && V_120 && V_120 -> V_119 )
V_120 -> V_119 ( V_9 , NULL ) ;
}
void F_59 ( struct V_45 * V_46 ,
struct V_1 * V_51 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_19 ;
F_30 (old_state, plane, plane_state, i) {
const struct V_50 * V_22 ;
if ( ! F_48 ( V_46 , V_51 , V_4 -> V_9 ) )
continue;
V_22 = V_6 -> V_23 ;
if ( V_22 -> V_110 )
V_22 -> V_110 ( V_6 , V_4 ) ;
}
}
void F_70 ( struct V_1 * V_2 ,
bool V_124 )
{
int V_19 ;
long V_20 ;
struct V_14 * V_15 ;
struct V_12 * V_13 ;
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_90 * V_75 ;
if ( V_124 ) {
F_21 (state, crtc, crtc_state, i) {
F_73 ( & V_9 -> V_93 ) ;
V_75 = F_95 ( & V_9 -> V_125 ,
struct V_90 , V_101 ) ;
if ( V_75 )
F_77 ( V_75 ) ;
F_76 ( & V_9 -> V_93 ) ;
if ( ! V_75 )
continue;
V_20 = F_87 ( & V_75 -> V_100 ,
10 * V_97 ) ;
if ( V_20 == 0 )
F_79 ( L_30 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
F_80 ( V_75 ) ;
}
}
F_5 (state, connector, conn_state, i) {
V_15 -> V_2 -> V_2 = V_2 ;
F_96 ( V_2 -> V_126 [ V_19 ] . V_2 , V_15 -> V_2 ) ;
V_15 -> V_2 -> V_2 = NULL ;
}
F_21 (state, crtc, crtc_state, i) {
V_9 -> V_2 -> V_2 = V_2 ;
F_96 ( V_2 -> V_103 [ V_19 ] . V_2 , V_9 -> V_2 ) ;
V_9 -> V_2 -> V_2 = NULL ;
if ( V_2 -> V_103 [ V_19 ] . V_75 ) {
F_73 ( & V_9 -> V_93 ) ;
F_97 ( & V_2 -> V_103 [ V_19 ] . V_75 -> V_101 ,
& V_9 -> V_125 ) ;
F_76 ( & V_9 -> V_93 ) ;
V_2 -> V_103 [ V_19 ] . V_75 -> V_104 = NULL ;
}
}
F_30 (state, plane, plane_state, i) {
V_6 -> V_2 -> V_2 = V_2 ;
F_96 ( V_2 -> V_127 [ V_19 ] . V_2 , V_6 -> V_2 ) ;
V_6 -> V_2 -> V_2 = NULL ;
}
}
int F_98 ( struct V_5 * V_6 ,
struct V_33 * V_9 ,
struct V_128 * V_78 ,
int V_129 , int V_130 ,
unsigned int V_131 , unsigned int V_132 ,
T_1 V_67 , T_1 V_69 ,
T_1 V_133 , T_1 V_134 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_20 = 0 ;
V_2 = F_99 ( V_6 -> V_46 ) ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_135 = F_100 ( V_9 ) ;
V_136:
V_4 = F_101 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_20 = F_13 ( V_4 ) ;
goto V_109;
}
V_20 = F_102 ( V_4 , V_9 ) ;
if ( V_20 != 0 )
goto V_109;
F_103 ( V_4 , V_78 ) ;
V_4 -> V_129 = V_129 ;
V_4 -> V_130 = V_130 ;
V_4 -> V_131 = V_131 ;
V_4 -> V_132 = V_132 ;
V_4 -> V_67 = V_67 ;
V_4 -> V_69 = V_69 ;
V_4 -> V_133 = V_133 ;
V_4 -> V_134 = V_134 ;
if ( V_6 == V_9 -> V_137 )
V_2 -> V_80 = true ;
V_20 = F_104 ( V_2 ) ;
if ( V_20 != 0 )
goto V_109;
return 0 ;
V_109:
if ( V_20 == - V_138 )
goto V_139;
F_63 ( V_2 ) ;
return V_20 ;
V_139:
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
V_6 -> V_140 = V_6 -> V_78 ;
goto V_136;
}
int F_107 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_20 = 0 ;
if ( ! V_6 -> V_9 )
return 0 ;
V_2 = F_99 ( V_6 -> V_46 ) ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_135 = F_100 ( V_6 -> V_9 ) ;
V_136:
V_4 = F_101 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_20 = F_13 ( V_4 ) ;
goto V_109;
}
if ( V_4 -> V_9 && ( V_6 == V_6 -> V_9 -> V_137 ) )
V_4 -> V_2 -> V_80 = true ;
V_20 = F_108 ( V_6 , V_4 ) ;
if ( V_20 != 0 )
goto V_109;
V_20 = F_104 ( V_2 ) ;
if ( V_20 != 0 )
goto V_109;
return 0 ;
V_109:
if ( V_20 == - V_138 )
goto V_139;
F_63 ( V_2 ) ;
return V_20 ;
V_139:
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
V_6 -> V_140 = V_6 -> V_78 ;
goto V_136;
}
int F_108 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
int V_20 ;
V_20 = F_102 ( V_4 , NULL ) ;
if ( V_20 != 0 )
return V_20 ;
F_103 ( V_4 , NULL ) ;
V_4 -> V_129 = 0 ;
V_4 -> V_130 = 0 ;
V_4 -> V_131 = 0 ;
V_4 -> V_132 = 0 ;
V_4 -> V_67 = 0 ;
V_4 -> V_69 = 0 ;
V_4 -> V_133 = 0 ;
V_4 -> V_134 = 0 ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_141 * V_142 )
{
struct V_45 * V_46 = V_142 -> V_9 -> V_46 ;
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_12 * V_13 ;
int V_20 , V_19 ;
V_20 = F_110 ( & V_46 -> V_61 . V_143 ,
V_2 -> V_135 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_27 ( V_2 , V_142 -> V_9 ) ;
if ( V_20 )
return V_20 ;
F_5 (state, connector, conn_state, i) {
if ( V_13 -> V_9 == V_142 -> V_9 ) {
V_20 = F_14 ( V_13 ,
NULL ) ;
if ( V_20 )
return V_20 ;
}
}
for ( V_19 = 0 ; V_19 < V_142 -> V_144 ; V_19 ++ ) {
V_13 = F_11 ( V_2 ,
V_142 -> V_126 [ V_19 ] ) ;
if ( F_12 ( V_13 ) )
return F_13 ( V_13 ) ;
V_20 = F_14 ( V_13 ,
V_142 -> V_9 ) ;
if ( V_20 )
return V_20 ;
}
F_21 (state, crtc, crtc_state, i) {
if ( V_9 == V_142 -> V_9 )
continue;
if ( ! V_8 -> V_31 ) {
V_20 = F_15 ( V_8 ,
NULL ) ;
if ( V_20 < 0 )
return V_20 ;
V_8 -> V_32 = false ;
}
}
return 0 ;
}
int F_111 ( struct V_141 * V_142 )
{
struct V_1 * V_2 ;
struct V_33 * V_9 = V_142 -> V_9 ;
int V_20 = 0 ;
V_2 = F_99 ( V_9 -> V_46 ) ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_47 = true ;
V_2 -> V_135 = F_100 ( V_9 ) ;
V_136:
V_20 = F_112 ( V_142 , V_2 ) ;
if ( V_20 != 0 )
goto V_109;
V_20 = F_104 ( V_2 ) ;
if ( V_20 != 0 )
goto V_109;
return 0 ;
V_109:
if ( V_20 == - V_138 )
goto V_139;
F_63 ( V_2 ) ;
return V_20 ;
V_139:
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
V_9 -> V_64 -> V_140 = V_9 -> V_64 -> V_78 ;
goto V_136;
}
int F_112 ( struct V_141 * V_142 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_3 * V_145 ;
struct V_33 * V_9 = V_142 -> V_9 ;
int V_146 , V_147 ;
int V_20 ;
V_8 = F_113 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) )
return F_13 ( V_8 ) ;
V_145 = F_101 ( V_2 , V_9 -> V_64 ) ;
if ( F_12 ( V_145 ) )
return F_13 ( V_145 ) ;
if ( ! V_142 -> V_39 ) {
F_3 ( V_142 -> V_78 ) ;
F_3 ( V_142 -> V_144 ) ;
V_20 = F_114 ( V_8 , NULL ) ;
if ( V_20 != 0 )
return V_20 ;
V_8 -> V_32 = false ;
V_20 = F_102 ( V_145 , NULL ) ;
if ( V_20 != 0 )
return V_20 ;
F_103 ( V_145 , NULL ) ;
goto V_75;
}
F_3 ( ! V_142 -> V_78 ) ;
F_3 ( ! V_142 -> V_144 ) ;
V_20 = F_114 ( V_8 , V_142 -> V_39 ) ;
if ( V_20 != 0 )
return V_20 ;
V_8 -> V_32 = true ;
V_20 = F_102 ( V_145 , V_9 ) ;
if ( V_20 != 0 )
return V_20 ;
F_115 ( V_142 -> V_39 , & V_146 , & V_147 ) ;
F_103 ( V_145 , V_142 -> V_78 ) ;
V_145 -> V_129 = 0 ;
V_145 -> V_130 = 0 ;
V_145 -> V_131 = V_146 ;
V_145 -> V_132 = V_147 ;
V_145 -> V_67 = V_142 -> V_66 << 16 ;
V_145 -> V_69 = V_142 -> V_68 << 16 ;
if ( V_145 -> V_148 & ( V_149 | V_150 ) ) {
V_145 -> V_133 = V_147 << 16 ;
V_145 -> V_134 = V_146 << 16 ;
} else {
V_145 -> V_133 = V_146 << 16 ;
V_145 -> V_134 = V_147 << 16 ;
}
V_75:
V_20 = F_109 ( V_2 , V_142 ) ;
if ( V_20 )
return V_20 ;
return 0 ;
}
int F_116 ( struct V_45 * V_46 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 ;
struct V_14 * V_153 ;
int V_154 ;
V_2 = F_99 ( V_46 ) ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_135 = V_152 ;
F_9 (conn, dev) {
struct V_33 * V_9 = V_153 -> V_2 -> V_9 ;
struct V_7 * V_8 ;
if ( ! V_9 || V_153 -> V_56 != V_63 )
continue;
V_8 = F_113 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_154 = F_13 ( V_8 ) ;
goto free;
}
V_8 -> V_32 = false ;
}
V_154 = F_104 ( V_2 ) ;
free:
if ( V_154 < 0 )
F_63 ( V_2 ) ;
return V_154 ;
}
struct V_1 * F_117 ( struct V_45 * V_46 )
{
struct V_151 V_152 ;
struct V_1 * V_2 ;
int V_154 ;
F_118 ( & V_152 , 0 ) ;
V_136:
V_154 = F_119 ( V_46 , & V_152 ) ;
if ( V_154 < 0 ) {
V_2 = F_120 ( V_154 ) ;
goto V_155;
}
V_2 = F_121 ( V_46 , & V_152 ) ;
if ( F_12 ( V_2 ) )
goto V_155;
V_154 = F_116 ( V_46 , & V_152 ) ;
if ( V_154 < 0 ) {
F_63 ( V_2 ) ;
V_2 = F_120 ( V_154 ) ;
goto V_155;
}
V_155:
if ( F_13 ( V_2 ) == - V_138 ) {
F_122 ( & V_152 ) ;
goto V_136;
}
F_123 ( & V_152 ) ;
F_124 ( & V_152 ) ;
return V_2 ;
}
int F_125 ( struct V_45 * V_46 ,
struct V_1 * V_2 )
{
struct V_156 * V_157 = & V_46 -> V_61 ;
int V_154 ;
F_126 ( V_46 ) ;
F_127 ( V_46 ) ;
V_2 -> V_135 = V_157 -> V_135 ;
V_154 = F_104 ( V_2 ) ;
F_128 ( V_46 ) ;
return V_154 ;
}
int
F_129 ( struct V_33 * V_9 ,
struct V_59 * V_158 ,
T_2 V_159 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_20 = 0 ;
V_2 = F_99 ( V_9 -> V_46 ) ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_135 = V_9 -> V_46 -> V_61 . V_135 ;
V_136:
V_8 = F_113 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_20 = F_13 ( V_8 ) ;
goto V_109;
}
V_20 = F_130 ( V_9 , V_8 ,
V_158 , V_159 ) ;
if ( V_20 )
goto V_109;
V_20 = F_104 ( V_2 ) ;
if ( V_20 != 0 )
goto V_109;
return 0 ;
V_109:
if ( V_20 == - V_138 )
goto V_139;
F_63 ( V_2 ) ;
return V_20 ;
V_139:
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
goto V_136;
}
int
F_131 ( struct V_5 * V_6 ,
struct V_59 * V_158 ,
T_2 V_159 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_20 = 0 ;
V_2 = F_99 ( V_6 -> V_46 ) ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_135 = V_6 -> V_46 -> V_61 . V_135 ;
V_136:
V_4 = F_101 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_20 = F_13 ( V_4 ) ;
goto V_109;
}
V_20 = F_132 ( V_6 , V_4 ,
V_158 , V_159 ) ;
if ( V_20 )
goto V_109;
V_20 = F_104 ( V_2 ) ;
if ( V_20 != 0 )
goto V_109;
return 0 ;
V_109:
if ( V_20 == - V_138 )
goto V_139;
F_63 ( V_2 ) ;
return V_20 ;
V_139:
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
goto V_136;
}
int
F_133 ( struct V_14 * V_15 ,
struct V_59 * V_158 ,
T_2 V_159 )
{
struct V_1 * V_2 ;
struct V_12 * V_34 ;
int V_20 = 0 ;
V_2 = F_99 ( V_15 -> V_46 ) ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_135 = V_15 -> V_46 -> V_61 . V_135 ;
V_136:
V_34 = F_11 ( V_2 , V_15 ) ;
if ( F_12 ( V_34 ) ) {
V_20 = F_13 ( V_34 ) ;
goto V_109;
}
V_20 = F_134 ( V_15 , V_34 ,
V_158 , V_159 ) ;
if ( V_20 )
goto V_109;
V_20 = F_104 ( V_2 ) ;
if ( V_20 != 0 )
goto V_109;
return 0 ;
V_109:
if ( V_20 == - V_138 )
goto V_139;
F_63 ( V_2 ) ;
return V_20 ;
V_139:
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
goto V_136;
}
int F_135 ( struct V_33 * V_9 ,
struct V_128 * V_78 ,
struct V_160 * V_104 ,
T_1 V_111 )
{
struct V_5 * V_6 = V_9 -> V_64 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_7 * V_8 ;
int V_20 = 0 ;
if ( V_111 & V_161 )
return - V_30 ;
V_2 = F_99 ( V_6 -> V_46 ) ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_135 = F_100 ( V_9 ) ;
V_136:
V_8 = F_113 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_20 = F_13 ( V_8 ) ;
goto V_109;
}
V_8 -> V_104 = V_104 ;
V_4 = F_101 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_20 = F_13 ( V_4 ) ;
goto V_109;
}
V_20 = F_102 ( V_4 , V_9 ) ;
if ( V_20 != 0 )
goto V_109;
F_103 ( V_4 , V_78 ) ;
V_2 -> V_162 = false ;
if ( ! V_8 -> V_32 ) {
F_8 ( L_32 ,
V_9 -> V_27 . V_28 ) ;
V_20 = - V_30 ;
goto V_109;
}
V_20 = F_136 ( V_2 ) ;
if ( V_20 != 0 )
goto V_109;
return 0 ;
V_109:
if ( V_20 == - V_138 )
goto V_139;
F_63 ( V_2 ) ;
return V_20 ;
V_139:
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
V_6 -> V_140 = V_6 -> V_78 ;
goto V_136;
}
int F_137 ( struct V_14 * V_15 ,
int V_39 )
{
struct V_156 * V_157 = & V_15 -> V_46 -> V_61 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_33 * V_9 ;
struct V_14 * V_163 ;
int V_20 ;
bool V_32 = false ;
int V_164 = V_15 -> V_56 ;
if ( V_39 != V_63 )
V_39 = V_57 ;
V_15 -> V_56 = V_39 ;
V_9 = V_15 -> V_2 -> V_9 ;
if ( ! V_9 )
return 0 ;
V_2 = F_99 ( V_15 -> V_46 ) ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_135 = F_100 ( V_9 ) ;
V_136:
V_8 = F_113 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_20 = F_13 ( V_8 ) ;
goto V_109;
}
F_3 ( ! F_138 ( & V_157 -> V_143 ) ) ;
F_9 (tmp_connector, connector->dev) {
if ( V_163 -> V_2 -> V_9 != V_9 )
continue;
if ( V_163 -> V_56 == V_63 ) {
V_32 = true ;
break;
}
}
V_8 -> V_32 = V_32 ;
V_20 = F_104 ( V_2 ) ;
if ( V_20 != 0 )
goto V_109;
return 0 ;
V_109:
if ( V_20 == - V_138 )
goto V_139;
V_15 -> V_56 = V_164 ;
F_63 ( V_2 ) ;
return V_20 ;
V_139:
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
goto V_136;
}
struct V_16 *
F_6 ( struct V_14 * V_15 )
{
F_3 ( V_15 -> V_165 [ 1 ] ) ;
return F_139 ( V_15 -> V_46 , V_15 -> V_165 [ 0 ] ) ;
}
void F_140 ( struct V_33 * V_9 )
{
if ( V_9 -> V_2 )
F_141 ( V_9 -> V_2 ) ;
F_142 ( V_9 -> V_2 ) ;
V_9 -> V_2 = F_81 ( sizeof( * V_9 -> V_2 ) , V_98 ) ;
if ( V_9 -> V_2 )
V_9 -> V_2 -> V_9 = V_9 ;
}
void F_143 ( struct V_33 * V_9 ,
struct V_7 * V_2 )
{
memcpy ( V_2 , V_9 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_166 )
F_144 ( V_2 -> V_166 ) ;
if ( V_2 -> V_167 )
F_144 ( V_2 -> V_167 ) ;
if ( V_2 -> V_168 )
F_144 ( V_2 -> V_168 ) ;
if ( V_2 -> V_169 )
F_144 ( V_2 -> V_169 ) ;
V_2 -> V_37 = false ;
V_2 -> V_49 = false ;
V_2 -> V_10 = false ;
V_2 -> V_36 = false ;
V_2 -> V_170 = false ;
V_2 -> V_171 = false ;
V_2 -> V_104 = NULL ;
}
struct V_7 *
F_145 ( struct V_33 * V_9 )
{
struct V_7 * V_2 ;
if ( F_3 ( ! V_9 -> V_2 ) )
return NULL ;
V_2 = F_146 ( sizeof( * V_2 ) , V_98 ) ;
if ( V_2 )
F_143 ( V_9 , V_2 ) ;
return V_2 ;
}
void F_141 ( struct V_7 * V_2 )
{
F_147 ( V_2 -> V_166 ) ;
F_147 ( V_2 -> V_167 ) ;
F_147 ( V_2 -> V_168 ) ;
F_147 ( V_2 -> V_169 ) ;
}
void F_148 ( struct V_33 * V_9 ,
struct V_7 * V_2 )
{
F_141 ( V_2 ) ;
F_142 ( V_2 ) ;
}
void F_149 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 )
F_150 ( V_6 -> V_2 ) ;
F_142 ( V_6 -> V_2 ) ;
V_6 -> V_2 = F_81 ( sizeof( * V_6 -> V_2 ) , V_98 ) ;
if ( V_6 -> V_2 ) {
V_6 -> V_2 -> V_6 = V_6 ;
V_6 -> V_2 -> V_148 = V_172 ;
}
}
void F_151 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
memcpy ( V_2 , V_6 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_78 )
F_152 ( V_2 -> V_78 ) ;
}
struct V_3 *
F_153 ( struct V_5 * V_6 )
{
struct V_3 * V_2 ;
if ( F_3 ( ! V_6 -> V_2 ) )
return NULL ;
V_2 = F_146 ( sizeof( * V_2 ) , V_98 ) ;
if ( V_2 )
F_151 ( V_6 , V_2 ) ;
return V_2 ;
}
void F_150 ( struct V_3 * V_2 )
{
if ( V_2 -> V_78 )
F_154 ( V_2 -> V_78 ) ;
}
void F_155 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
F_150 ( V_2 ) ;
F_142 ( V_2 ) ;
}
void
F_156 ( struct V_14 * V_15 ,
struct V_12 * V_13 )
{
if ( V_13 )
V_13 -> V_15 = V_15 ;
V_15 -> V_2 = V_13 ;
}
void F_157 ( struct V_14 * V_15 )
{
struct V_12 * V_13 =
F_81 ( sizeof( * V_13 ) , V_98 ) ;
if ( V_15 -> V_2 )
F_158 ( V_15 -> V_2 ) ;
F_142 ( V_15 -> V_2 ) ;
F_156 ( V_15 , V_13 ) ;
}
void
F_159 ( struct V_14 * V_15 ,
struct V_12 * V_2 )
{
memcpy ( V_2 , V_15 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_9 )
F_160 ( V_15 ) ;
}
struct V_12 *
F_161 ( struct V_14 * V_15 )
{
struct V_12 * V_2 ;
if ( F_3 ( ! V_15 -> V_2 ) )
return NULL ;
V_2 = F_146 ( sizeof( * V_2 ) , V_98 ) ;
if ( V_2 )
F_159 ( V_15 , V_2 ) ;
return V_2 ;
}
struct V_1 *
F_121 ( struct V_45 * V_46 ,
struct V_151 * V_152 )
{
struct V_1 * V_2 ;
struct V_14 * V_153 ;
struct V_5 * V_6 ;
struct V_33 * V_9 ;
int V_154 = 0 ;
V_2 = F_99 ( V_46 ) ;
if ( ! V_2 )
return F_120 ( - V_99 ) ;
V_2 -> V_135 = V_152 ;
F_162 (crtc, dev) {
struct V_7 * V_8 ;
V_8 = F_113 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_154 = F_13 ( V_8 ) ;
goto free;
}
}
F_163 (plane, dev) {
struct V_3 * V_4 ;
V_4 = F_101 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_154 = F_13 ( V_4 ) ;
goto free;
}
}
F_9 (conn, dev) {
struct V_12 * V_13 ;
V_13 = F_11 ( V_2 , V_153 ) ;
if ( F_12 ( V_13 ) ) {
V_154 = F_13 ( V_13 ) ;
goto free;
}
}
V_2 -> V_135 = NULL ;
free:
if ( V_154 < 0 ) {
F_63 ( V_2 ) ;
V_2 = F_120 ( V_154 ) ;
}
return V_2 ;
}
void
F_158 ( struct V_12 * V_2 )
{
if ( V_2 -> V_9 )
F_164 ( V_2 -> V_15 ) ;
}
void F_165 ( struct V_14 * V_15 ,
struct V_12 * V_2 )
{
F_158 ( V_2 ) ;
F_142 ( V_2 ) ;
}
int F_166 ( struct V_33 * V_9 ,
T_3 * V_173 , T_3 * V_174 , T_3 * V_175 ,
T_1 V_176 )
{
struct V_45 * V_46 = V_9 -> V_46 ;
struct V_156 * V_157 = & V_46 -> V_61 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_177 * V_178 = NULL ;
struct V_179 * V_180 ;
int V_19 , V_20 = 0 ;
V_2 = F_99 ( V_9 -> V_46 ) ;
if ( ! V_2 )
return - V_99 ;
V_178 = F_167 ( V_46 ,
sizeof( struct V_179 ) * V_176 ,
NULL ) ;
if ( F_12 ( V_178 ) ) {
V_20 = F_13 ( V_178 ) ;
V_178 = NULL ;
goto V_109;
}
V_180 = (struct V_179 * ) V_178 -> V_181 ;
for ( V_19 = 0 ; V_19 < V_176 ; V_19 ++ ) {
V_180 [ V_19 ] . V_173 = V_173 [ V_19 ] ;
V_180 [ V_19 ] . V_174 = V_174 [ V_19 ] ;
V_180 [ V_19 ] . V_175 = V_175 [ V_19 ] ;
}
V_2 -> V_135 = V_9 -> V_46 -> V_61 . V_135 ;
V_136:
V_8 = F_113 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_20 = F_13 ( V_8 ) ;
goto V_109;
}
V_20 = F_130 ( V_9 , V_8 ,
V_157 -> V_182 , 0 ) ;
if ( V_20 )
goto V_109;
V_20 = F_130 ( V_9 , V_8 ,
V_157 -> V_183 , 0 ) ;
if ( V_20 )
goto V_109;
V_20 = F_130 ( V_9 , V_8 ,
V_157 -> V_184 , V_178 -> V_27 . V_28 ) ;
if ( V_20 )
goto V_109;
V_20 = F_104 ( V_2 ) ;
if ( V_20 )
goto V_109;
F_147 ( V_178 ) ;
return 0 ;
V_109:
if ( V_20 == - V_138 )
goto V_139;
F_63 ( V_2 ) ;
F_147 ( V_178 ) ;
return V_20 ;
V_139:
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
goto V_136;
}
