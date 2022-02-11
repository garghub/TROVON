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
V_20 = F_30 ( V_46 , V_2 ) ;
if ( V_20 )
return V_20 ;
F_31 (state, plane, plane_state, i) {
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
int F_32 ( struct V_45 * V_46 ,
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
F_33 ( struct V_45 * V_46 , struct V_1 * V_51 )
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
F_34 ( V_17 -> V_41 ) ;
if ( V_22 ) {
if ( V_15 -> V_2 -> V_9 && V_22 -> V_54 )
V_22 -> V_54 ( V_17 ) ;
else if ( V_22 -> V_55 )
V_22 -> V_55 ( V_17 ) ;
else if ( V_22 -> V_56 )
V_22 -> V_56 ( V_17 , V_57 ) ;
}
F_35 ( V_17 -> V_41 ) ;
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
else if ( V_22 -> V_55 )
V_22 -> V_55 ( V_9 ) ;
else
V_22 -> V_56 ( V_9 , V_57 ) ;
}
}
void
F_36 ( struct V_45 * V_46 ,
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
struct V_58 * V_59 =
V_46 -> V_60 . V_61 ;
int V_39 = V_57 ;
if ( V_9 && V_9 -> V_2 -> V_32 )
V_39 = V_62 ;
V_15 -> V_56 = V_39 ;
F_37 ( & V_15 -> V_27 ,
V_59 , V_39 ) ;
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
struct V_5 * V_63 = V_9 -> V_63 ;
V_9 -> V_39 = V_9 -> V_2 -> V_39 ;
V_9 -> V_64 = V_9 -> V_2 -> V_44 ;
if ( F_38 ( V_51 , V_63 ) &&
V_63 -> V_2 -> V_9 == V_9 ) {
V_9 -> V_65 = V_63 -> V_2 -> V_66 >> 16 ;
V_9 -> V_67 = V_63 -> V_2 -> V_68 >> 16 ;
}
if ( V_9 -> V_2 -> V_44 )
F_39 ( V_9 ,
& V_9 -> V_2 -> V_38 ) ;
}
}
static void
F_40 ( struct V_45 * V_46 , struct V_1 * V_51 )
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
if ( V_9 -> V_2 -> V_44 && V_22 -> V_69 ) {
F_8 ( L_24 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
V_22 -> V_69 ( V_9 ) ;
}
}
F_5 (old_state, connector, old_conn_state, i) {
const struct V_40 * V_22 ;
struct V_7 * V_70 ;
struct V_16 * V_17 ;
struct V_71 * V_39 , * V_38 ;
if ( ! V_15 -> V_2 -> V_26 )
continue;
V_17 = V_15 -> V_2 -> V_26 ;
V_22 = V_17 -> V_23 ;
V_70 = V_15 -> V_2 -> V_9 -> V_2 ;
V_39 = & V_70 -> V_39 ;
V_38 = & V_70 -> V_38 ;
if ( ! V_70 -> V_37 )
continue;
F_8 ( L_25 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ) ;
if ( V_22 && V_22 -> V_72 )
V_22 -> V_72 ( V_17 , V_39 , V_38 ) ;
F_41 ( V_17 -> V_41 , V_39 , V_38 ) ;
}
}
void F_42 ( struct V_45 * V_46 ,
struct V_1 * V_51 )
{
F_33 ( V_46 , V_51 ) ;
F_36 ( V_46 , V_51 ) ;
F_40 ( V_46 , V_51 ) ;
}
void F_43 ( struct V_45 * V_46 ,
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
V_22 -> V_73 ( V_9 ) ;
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
F_44 ( V_17 -> V_41 ) ;
if ( V_22 ) {
if ( V_22 -> V_44 )
V_22 -> V_44 ( V_17 ) ;
else if ( V_22 -> V_73 )
V_22 -> V_73 ( V_17 ) ;
}
F_45 ( V_17 -> V_41 ) ;
}
}
void F_46 ( struct V_45 * V_46 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_19 ;
F_31 (state, plane, plane_state, i) {
if ( ! V_6 -> V_2 -> V_74 )
continue;
F_3 ( ! V_6 -> V_2 -> V_75 ) ;
F_47 ( V_6 -> V_2 -> V_74 , false ) ;
F_48 ( V_6 -> V_2 -> V_74 ) ;
V_6 -> V_2 -> V_74 = NULL ;
}
}
bool F_49 ( struct V_45 * V_46 ,
struct V_1 * V_51 ,
struct V_33 * V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_76 ;
int V_19 ;
F_31 (old_state, plane, old_plane_state, i) {
if ( V_6 -> V_2 -> V_9 != V_9 &&
V_76 -> V_9 != V_9 )
continue;
if ( V_6 -> V_2 -> V_75 != V_76 -> V_75 )
return true ;
}
return false ;
}
void
F_50 ( struct V_45 * V_46 ,
struct V_1 * V_51 )
{
struct V_33 * V_9 ;
struct V_7 * V_53 ;
int V_19 , V_20 ;
F_21 (old_state, crtc, old_crtc_state, i) {
V_53 -> V_44 = false ;
if ( ! V_9 -> V_2 -> V_44 )
continue;
if ( V_51 -> V_77 )
continue;
if ( ! F_49 ( V_46 ,
V_51 , V_9 ) )
continue;
V_20 = F_51 ( V_9 ) ;
if ( V_20 != 0 )
continue;
V_53 -> V_44 = true ;
V_53 -> V_78 = F_52 ( V_9 ) ;
}
F_21 (old_state, crtc, old_crtc_state, i) {
if ( ! V_53 -> V_44 )
continue;
V_20 = F_53 ( V_46 -> V_79 [ V_19 ] . V_80 ,
V_53 -> V_78 !=
F_52 ( V_9 ) ,
F_54 ( 50 ) ) ;
F_55 ( ! V_20 , L_28 , V_9 -> V_27 . V_28 ) ;
F_56 ( V_9 ) ;
}
}
void F_57 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
F_42 ( V_46 , V_2 ) ;
F_58 ( V_46 , V_2 , false ) ;
F_43 ( V_46 , V_2 ) ;
F_59 ( V_2 ) ;
F_50 ( V_46 , V_2 ) ;
F_60 ( V_46 , V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_81 * V_22 ;
V_22 = V_46 -> V_60 . V_23 ;
F_46 ( V_46 , V_2 ) ;
F_62 ( V_2 ) ;
if ( V_22 && V_22 -> V_82 )
V_22 -> V_82 ( V_2 ) ;
else
F_57 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
}
static void F_65 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_66 ( V_84 ,
struct V_1 ,
F_65 ) ;
F_61 ( V_2 ) ;
}
int F_67 ( struct V_45 * V_46 ,
struct V_1 * V_2 ,
bool V_85 )
{
int V_20 ;
V_20 = F_68 ( V_2 , V_85 ) ;
if ( V_20 )
return V_20 ;
F_69 ( & V_2 -> F_65 , F_65 ) ;
V_20 = F_70 ( V_46 , V_2 ) ;
if ( V_20 )
return V_20 ;
F_71 ( V_2 , true ) ;
if ( V_85 )
F_72 ( V_86 , & V_2 -> F_65 ) ;
else
F_61 ( V_2 ) ;
return 0 ;
}
static int F_73 ( struct V_33 * V_9 , bool V_85 )
{
struct V_87 * V_73 , * V_88 = NULL ;
bool V_89 = true ;
int V_19 ;
long V_20 = 0 ;
F_74 ( & V_9 -> V_90 ) ;
V_19 = 0 ;
F_75 (commit, &crtc->commit_list, commit_entry) {
if ( V_19 == 0 ) {
V_89 = F_76 ( & V_73 -> V_91 ) ;
if ( ! V_89 && V_85 ) {
F_77 ( & V_9 -> V_90 ) ;
return - V_92 ;
}
} else if ( V_19 == 1 ) {
V_88 = V_73 ;
F_78 ( V_88 ) ;
break;
}
V_19 ++ ;
}
F_77 ( & V_9 -> V_90 ) ;
if ( ! V_88 )
return 0 ;
V_20 = F_79 ( & V_88 -> V_93 ,
10 * V_94 ) ;
if ( V_20 == 0 )
F_80 ( L_29 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
F_81 ( V_88 ) ;
return V_20 < 0 ? V_20 : 0 ;
}
int F_68 ( struct V_1 * V_2 ,
bool V_85 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_87 * V_73 ;
int V_19 , V_20 ;
F_21 (state, crtc, crtc_state, i) {
V_73 = F_82 ( sizeof( * V_73 ) , V_95 ) ;
if ( ! V_73 )
return - V_96 ;
F_83 ( & V_73 -> V_91 ) ;
F_83 ( & V_73 -> V_97 ) ;
F_83 ( & V_73 -> V_93 ) ;
F_84 ( & V_73 -> V_98 ) ;
F_85 ( & V_73 -> V_99 ) ;
V_73 -> V_9 = V_9 ;
V_2 -> V_100 [ V_19 ] . V_73 = V_73 ;
V_20 = F_73 ( V_9 , V_85 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_9 -> V_2 -> V_32 && ! V_8 -> V_32 ) {
F_86 ( & V_73 -> V_91 ) ;
continue;
}
if ( V_2 -> V_77 ) {
F_86 ( & V_73 -> V_91 ) ;
continue;
}
if ( ! V_8 -> V_101 ) {
V_73 -> V_101 = F_82 ( sizeof( * V_73 -> V_101 ) ,
V_95 ) ;
if ( ! V_73 -> V_101 )
return - V_96 ;
V_8 -> V_101 = V_73 -> V_101 ;
}
V_8 -> V_101 -> V_27 . V_102 = & V_73 -> V_91 ;
}
return 0 ;
}
static struct V_87 * F_87 ( struct V_33 * V_9 )
{
struct V_87 * V_73 ;
int V_19 = 0 ;
F_75 (commit, &crtc->commit_list, commit_entry) {
if ( V_19 == 1 )
return V_73 ;
V_19 ++ ;
}
return NULL ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_87 * V_73 ;
int V_19 ;
long V_20 ;
F_21 (state, crtc, crtc_state, i) {
F_74 ( & V_9 -> V_90 ) ;
V_73 = F_87 ( V_9 ) ;
if ( V_73 )
F_78 ( V_73 ) ;
F_77 ( & V_9 -> V_90 ) ;
if ( ! V_73 )
continue;
V_20 = F_88 ( & V_73 -> V_97 ,
10 * V_94 ) ;
if ( V_20 == 0 )
F_80 ( L_30 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
V_20 = F_88 ( & V_73 -> V_91 ,
10 * V_94 ) ;
if ( V_20 == 0 )
F_80 ( L_31 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
F_81 ( V_73 ) ;
}
}
void F_59 ( struct V_1 * V_2 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_87 * V_73 ;
int V_19 ;
F_21 (state, crtc, crtc_state, i) {
V_73 = V_2 -> V_100 [ V_19 ] . V_73 ;
if ( ! V_73 )
continue;
F_3 ( V_9 -> V_2 -> V_101 ) ;
F_74 ( & V_9 -> V_90 ) ;
F_86 ( & V_73 -> V_97 ) ;
F_77 ( & V_9 -> V_90 ) ;
}
}
void F_63 ( struct V_1 * V_2 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_87 * V_73 ;
int V_19 ;
long V_20 ;
F_21 (state, crtc, crtc_state, i) {
V_73 = V_2 -> V_100 [ V_19 ] . V_73 ;
if ( F_3 ( ! V_73 ) )
continue;
F_74 ( & V_9 -> V_90 ) ;
F_86 ( & V_73 -> V_93 ) ;
F_3 ( ! F_76 ( & V_73 -> V_97 ) ) ;
if ( F_76 ( & V_73 -> V_91 ) )
goto V_103;
F_77 ( & V_9 -> V_90 ) ;
V_20 = F_88 ( & V_73 -> V_91 ,
10 * V_94 ) ;
if ( V_20 == 0 )
F_80 ( L_31 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
F_74 ( & V_9 -> V_90 ) ;
V_103:
F_89 ( & V_73 -> V_98 ) ;
F_77 ( & V_9 -> V_90 ) ;
}
}
int F_70 ( struct V_45 * V_46 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_20 , V_19 , V_104 ;
F_31 (state, plane, plane_state, i) {
const struct V_50 * V_22 ;
V_22 = V_6 -> V_23 ;
if ( V_22 -> V_105 ) {
V_20 = V_22 -> V_105 ( V_6 , V_4 ) ;
if ( V_20 )
goto V_106;
}
}
return 0 ;
V_106:
F_31 (state, plane, plane_state, j) {
const struct V_50 * V_22 ;
if ( V_104 >= V_19 )
continue;
V_22 = V_6 -> V_23 ;
if ( V_22 -> V_107 )
V_22 -> V_107 ( V_6 , V_4 ) ;
}
return V_20 ;
}
bool F_90 ( struct V_3 * V_2 )
{
return V_2 -> V_9 && V_2 -> V_9 -> V_2 -> V_32 ;
}
void F_58 ( struct V_45 * V_46 ,
struct V_1 * V_51 ,
bool V_108 )
{
struct V_33 * V_9 ;
struct V_7 * V_53 ;
struct V_5 * V_6 ;
struct V_3 * V_76 ;
int V_19 ;
F_21 (old_state, crtc, old_crtc_state, i) {
const struct V_43 * V_22 ;
V_22 = V_9 -> V_23 ;
if ( ! V_22 || ! V_22 -> V_109 )
continue;
if ( V_108 && ! V_9 -> V_2 -> V_32 )
continue;
V_22 -> V_109 ( V_9 , V_53 ) ;
}
F_31 (old_state, plane, old_plane_state, i) {
const struct V_50 * V_22 ;
bool V_110 ;
V_22 = V_6 -> V_23 ;
if ( ! V_22 )
continue;
V_110 = F_91 ( V_6 , V_76 ) ;
if ( V_108 ) {
if ( ! V_110 && ! F_90 ( V_6 -> V_2 ) )
continue;
if ( V_110 && ! F_90 ( V_76 ) )
continue;
}
if ( V_110 && V_22 -> V_111 )
V_22 -> V_111 ( V_6 , V_76 ) ;
else if ( V_6 -> V_2 -> V_9 || V_110 )
V_22 -> V_112 ( V_6 , V_76 ) ;
}
F_21 (old_state, crtc, old_crtc_state, i) {
const struct V_43 * V_22 ;
V_22 = V_9 -> V_23 ;
if ( ! V_22 || ! V_22 -> V_113 )
continue;
if ( V_108 && ! V_9 -> V_2 -> V_32 )
continue;
V_22 -> V_113 ( V_9 , V_53 ) ;
}
}
void
F_92 ( struct V_7 * V_53 )
{
const struct V_43 * V_114 ;
struct V_33 * V_9 = V_53 -> V_9 ;
struct V_1 * V_51 = V_53 -> V_2 ;
struct V_5 * V_6 ;
unsigned V_115 ;
V_115 = V_53 -> V_115 ;
V_115 |= V_9 -> V_2 -> V_115 ;
V_114 = V_9 -> V_23 ;
if ( V_114 && V_114 -> V_109 )
V_114 -> V_109 ( V_9 , V_53 ) ;
F_93 (plane, crtc->dev, plane_mask) {
struct V_3 * V_76 =
F_38 ( V_51 , V_6 ) ;
const struct V_50 * V_116 ;
V_116 = V_6 -> V_23 ;
if ( ! V_76 || ! V_116 )
continue;
F_3 ( V_6 -> V_2 -> V_9 && V_6 -> V_2 -> V_9 != V_9 ) ;
if ( F_91 ( V_6 , V_76 ) &&
V_116 -> V_111 )
V_116 -> V_111 ( V_6 , V_76 ) ;
else if ( V_6 -> V_2 -> V_9 ||
F_91 ( V_6 , V_76 ) )
V_116 -> V_112 ( V_6 , V_76 ) ;
}
if ( V_114 && V_114 -> V_113 )
V_114 -> V_113 ( V_9 , V_53 ) ;
}
void F_94 ( struct V_33 * V_9 ,
bool V_117 )
{
const struct V_43 * V_114 =
V_9 -> V_23 ;
struct V_5 * V_6 ;
if ( V_117 && V_114 && V_114 -> V_109 )
V_114 -> V_109 ( V_9 , NULL ) ;
F_95 (plane, crtc->dev) {
const struct V_50 * V_116 =
V_6 -> V_23 ;
if ( V_6 -> V_2 -> V_9 != V_9 || ! V_116 )
continue;
F_3 ( ! V_116 -> V_111 ) ;
if ( V_116 -> V_111 )
V_116 -> V_111 ( V_6 , NULL ) ;
}
if ( V_117 && V_114 && V_114 -> V_113 )
V_114 -> V_113 ( V_9 , NULL ) ;
}
void F_60 ( struct V_45 * V_46 ,
struct V_1 * V_51 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_19 ;
F_31 (old_state, plane, plane_state, i) {
const struct V_50 * V_22 ;
V_22 = V_6 -> V_23 ;
if ( V_22 -> V_107 )
V_22 -> V_107 ( V_6 , V_4 ) ;
}
}
void F_71 ( struct V_1 * V_2 ,
bool V_118 )
{
int V_19 ;
long V_20 ;
struct V_14 * V_15 ;
struct V_12 * V_13 ;
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_87 * V_73 ;
if ( V_118 ) {
F_21 (state, crtc, crtc_state, i) {
F_74 ( & V_9 -> V_90 ) ;
V_73 = F_96 ( & V_9 -> V_119 ,
struct V_87 , V_98 ) ;
if ( V_73 )
F_78 ( V_73 ) ;
F_77 ( & V_9 -> V_90 ) ;
if ( ! V_73 )
continue;
V_20 = F_88 ( & V_73 -> V_97 ,
10 * V_94 ) ;
if ( V_20 == 0 )
F_80 ( L_30 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
F_81 ( V_73 ) ;
}
}
F_5 (state, connector, conn_state, i) {
V_15 -> V_2 -> V_2 = V_2 ;
F_97 ( V_2 -> V_120 [ V_19 ] . V_2 , V_15 -> V_2 ) ;
V_15 -> V_2 -> V_2 = NULL ;
}
F_21 (state, crtc, crtc_state, i) {
V_9 -> V_2 -> V_2 = V_2 ;
F_97 ( V_2 -> V_100 [ V_19 ] . V_2 , V_9 -> V_2 ) ;
V_9 -> V_2 -> V_2 = NULL ;
if ( V_2 -> V_100 [ V_19 ] . V_73 ) {
F_74 ( & V_9 -> V_90 ) ;
F_98 ( & V_2 -> V_100 [ V_19 ] . V_73 -> V_98 ,
& V_9 -> V_119 ) ;
F_77 ( & V_9 -> V_90 ) ;
V_2 -> V_100 [ V_19 ] . V_73 -> V_101 = NULL ;
}
}
F_31 (state, plane, plane_state, i) {
V_6 -> V_2 -> V_2 = V_2 ;
F_97 ( V_2 -> V_121 [ V_19 ] . V_2 , V_6 -> V_2 ) ;
V_6 -> V_2 -> V_2 = NULL ;
}
}
int F_99 ( struct V_5 * V_6 ,
struct V_33 * V_9 ,
struct V_122 * V_75 ,
int V_123 , int V_124 ,
unsigned int V_125 , unsigned int V_126 ,
T_1 V_66 , T_1 V_68 ,
T_1 V_127 , T_1 V_128 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_20 = 0 ;
V_2 = F_100 ( V_6 -> V_46 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_129 = F_101 ( V_9 ) ;
V_130:
V_4 = F_102 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_20 = F_13 ( V_4 ) ;
goto V_106;
}
V_20 = F_103 ( V_4 , V_9 ) ;
if ( V_20 != 0 )
goto V_106;
F_104 ( V_4 , V_75 ) ;
V_4 -> V_123 = V_123 ;
V_4 -> V_124 = V_124 ;
V_4 -> V_125 = V_125 ;
V_4 -> V_126 = V_126 ;
V_4 -> V_66 = V_66 ;
V_4 -> V_68 = V_68 ;
V_4 -> V_127 = V_127 ;
V_4 -> V_128 = V_128 ;
if ( V_6 == V_9 -> V_131 )
V_2 -> V_77 = true ;
V_20 = F_105 ( V_2 ) ;
if ( V_20 != 0 )
goto V_106;
return 0 ;
V_106:
if ( V_20 == - V_132 )
goto V_133;
F_64 ( V_2 ) ;
return V_20 ;
V_133:
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
V_6 -> V_134 = V_6 -> V_75 ;
goto V_130;
}
int F_108 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_20 = 0 ;
if ( ! V_6 -> V_9 )
return 0 ;
V_2 = F_100 ( V_6 -> V_46 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_129 = F_101 ( V_6 -> V_9 ) ;
V_130:
V_4 = F_102 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_20 = F_13 ( V_4 ) ;
goto V_106;
}
if ( V_4 -> V_9 && ( V_6 == V_6 -> V_9 -> V_131 ) )
V_4 -> V_2 -> V_77 = true ;
V_20 = F_109 ( V_6 , V_4 ) ;
if ( V_20 != 0 )
goto V_106;
V_20 = F_105 ( V_2 ) ;
if ( V_20 != 0 )
goto V_106;
return 0 ;
V_106:
if ( V_20 == - V_132 )
goto V_133;
F_64 ( V_2 ) ;
return V_20 ;
V_133:
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
V_6 -> V_134 = V_6 -> V_75 ;
goto V_130;
}
int F_109 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
int V_20 ;
V_20 = F_103 ( V_4 , NULL ) ;
if ( V_20 != 0 )
return V_20 ;
F_104 ( V_4 , NULL ) ;
V_4 -> V_123 = 0 ;
V_4 -> V_124 = 0 ;
V_4 -> V_125 = 0 ;
V_4 -> V_126 = 0 ;
V_4 -> V_66 = 0 ;
V_4 -> V_68 = 0 ;
V_4 -> V_127 = 0 ;
V_4 -> V_128 = 0 ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
struct V_45 * V_46 = V_136 -> V_9 -> V_46 ;
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_12 * V_13 ;
int V_20 , V_19 ;
V_20 = F_111 ( & V_46 -> V_60 . V_137 ,
V_2 -> V_129 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_27 ( V_2 , V_136 -> V_9 ) ;
if ( V_20 )
return V_20 ;
F_5 (state, connector, conn_state, i) {
if ( V_13 -> V_9 == V_136 -> V_9 ) {
V_20 = F_14 ( V_13 ,
NULL ) ;
if ( V_20 )
return V_20 ;
}
}
for ( V_19 = 0 ; V_19 < V_136 -> V_138 ; V_19 ++ ) {
V_13 = F_11 ( V_2 ,
V_136 -> V_120 [ V_19 ] ) ;
if ( F_12 ( V_13 ) )
return F_13 ( V_13 ) ;
V_20 = F_14 ( V_13 ,
V_136 -> V_9 ) ;
if ( V_20 )
return V_20 ;
}
F_21 (state, crtc, crtc_state, i) {
if ( V_9 == V_136 -> V_9 )
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
int F_112 ( struct V_135 * V_136 )
{
struct V_1 * V_2 ;
struct V_33 * V_9 = V_136 -> V_9 ;
int V_20 = 0 ;
V_2 = F_100 ( V_9 -> V_46 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_47 = true ;
V_2 -> V_129 = F_101 ( V_9 ) ;
V_130:
V_20 = F_113 ( V_136 , V_2 ) ;
if ( V_20 != 0 )
goto V_106;
V_20 = F_105 ( V_2 ) ;
if ( V_20 != 0 )
goto V_106;
return 0 ;
V_106:
if ( V_20 == - V_132 )
goto V_133;
F_64 ( V_2 ) ;
return V_20 ;
V_133:
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
V_9 -> V_63 -> V_134 = V_9 -> V_63 -> V_75 ;
goto V_130;
}
int F_113 ( struct V_135 * V_136 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_3 * V_139 ;
struct V_33 * V_9 = V_136 -> V_9 ;
int V_140 , V_141 ;
int V_20 ;
V_8 = F_114 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) )
return F_13 ( V_8 ) ;
V_139 = F_102 ( V_2 , V_9 -> V_63 ) ;
if ( F_12 ( V_139 ) )
return F_13 ( V_139 ) ;
if ( ! V_136 -> V_39 ) {
F_3 ( V_136 -> V_75 ) ;
F_3 ( V_136 -> V_138 ) ;
V_20 = F_115 ( V_8 , NULL ) ;
if ( V_20 != 0 )
return V_20 ;
V_8 -> V_32 = false ;
V_20 = F_103 ( V_139 , NULL ) ;
if ( V_20 != 0 )
return V_20 ;
F_104 ( V_139 , NULL ) ;
goto V_73;
}
F_3 ( ! V_136 -> V_75 ) ;
F_3 ( ! V_136 -> V_138 ) ;
V_20 = F_115 ( V_8 , V_136 -> V_39 ) ;
if ( V_20 != 0 )
return V_20 ;
V_8 -> V_32 = true ;
V_20 = F_103 ( V_139 , V_9 ) ;
if ( V_20 != 0 )
return V_20 ;
F_116 ( V_136 -> V_39 , & V_140 , & V_141 ) ;
F_104 ( V_139 , V_136 -> V_75 ) ;
V_139 -> V_123 = 0 ;
V_139 -> V_124 = 0 ;
V_139 -> V_125 = V_140 ;
V_139 -> V_126 = V_141 ;
V_139 -> V_66 = V_136 -> V_65 << 16 ;
V_139 -> V_68 = V_136 -> V_67 << 16 ;
if ( V_139 -> V_142 & ( F_117 ( V_143 ) | F_117 ( V_144 ) ) ) {
V_139 -> V_127 = V_141 << 16 ;
V_139 -> V_128 = V_140 << 16 ;
} else {
V_139 -> V_127 = V_140 << 16 ;
V_139 -> V_128 = V_141 << 16 ;
}
V_73:
V_20 = F_110 ( V_2 , V_136 ) ;
if ( V_20 )
return V_20 ;
return 0 ;
}
int F_118 ( struct V_45 * V_46 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 ;
struct V_14 * V_147 ;
int V_148 ;
V_2 = F_100 ( V_46 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_129 = V_146 ;
F_9 (conn, dev) {
struct V_33 * V_9 = V_147 -> V_2 -> V_9 ;
struct V_7 * V_8 ;
if ( ! V_9 || V_147 -> V_56 != V_62 )
continue;
V_8 = F_114 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_148 = F_13 ( V_8 ) ;
goto free;
}
V_8 -> V_32 = false ;
}
V_148 = F_105 ( V_2 ) ;
free:
if ( V_148 < 0 )
F_64 ( V_2 ) ;
return V_148 ;
}
struct V_1 * F_119 ( struct V_45 * V_46 )
{
struct V_145 V_146 ;
struct V_1 * V_2 ;
int V_148 ;
F_120 ( & V_146 , 0 ) ;
V_130:
V_148 = F_121 ( V_46 , & V_146 ) ;
if ( V_148 < 0 ) {
V_2 = F_122 ( V_148 ) ;
goto V_149;
}
V_2 = F_123 ( V_46 , & V_146 ) ;
if ( F_12 ( V_2 ) )
goto V_149;
V_148 = F_118 ( V_46 , & V_146 ) ;
if ( V_148 < 0 ) {
F_64 ( V_2 ) ;
V_2 = F_122 ( V_148 ) ;
goto V_149;
}
V_149:
if ( F_13 ( V_2 ) == - V_132 ) {
F_124 ( & V_146 ) ;
goto V_130;
}
F_125 ( & V_146 ) ;
F_126 ( & V_146 ) ;
return V_2 ;
}
int F_127 ( struct V_45 * V_46 ,
struct V_1 * V_2 )
{
struct V_150 * V_151 = & V_46 -> V_60 ;
int V_148 ;
F_128 ( V_46 ) ;
F_129 ( V_46 ) ;
V_2 -> V_129 = V_151 -> V_129 ;
V_148 = F_105 ( V_2 ) ;
F_130 ( V_46 ) ;
return V_148 ;
}
int
F_131 ( struct V_33 * V_9 ,
struct V_58 * V_152 ,
T_2 V_153 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_20 = 0 ;
V_2 = F_100 ( V_9 -> V_46 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_129 = V_9 -> V_46 -> V_60 . V_129 ;
V_130:
V_8 = F_114 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_20 = F_13 ( V_8 ) ;
goto V_106;
}
V_20 = F_132 ( V_9 , V_8 ,
V_152 , V_153 ) ;
if ( V_20 )
goto V_106;
V_20 = F_105 ( V_2 ) ;
if ( V_20 != 0 )
goto V_106;
return 0 ;
V_106:
if ( V_20 == - V_132 )
goto V_133;
F_64 ( V_2 ) ;
return V_20 ;
V_133:
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
goto V_130;
}
int
F_133 ( struct V_5 * V_6 ,
struct V_58 * V_152 ,
T_2 V_153 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_20 = 0 ;
V_2 = F_100 ( V_6 -> V_46 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_129 = V_6 -> V_46 -> V_60 . V_129 ;
V_130:
V_4 = F_102 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_20 = F_13 ( V_4 ) ;
goto V_106;
}
V_20 = F_134 ( V_6 , V_4 ,
V_152 , V_153 ) ;
if ( V_20 )
goto V_106;
V_20 = F_105 ( V_2 ) ;
if ( V_20 != 0 )
goto V_106;
return 0 ;
V_106:
if ( V_20 == - V_132 )
goto V_133;
F_64 ( V_2 ) ;
return V_20 ;
V_133:
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
goto V_130;
}
int
F_135 ( struct V_14 * V_15 ,
struct V_58 * V_152 ,
T_2 V_153 )
{
struct V_1 * V_2 ;
struct V_12 * V_34 ;
int V_20 = 0 ;
V_2 = F_100 ( V_15 -> V_46 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_129 = V_15 -> V_46 -> V_60 . V_129 ;
V_130:
V_34 = F_11 ( V_2 , V_15 ) ;
if ( F_12 ( V_34 ) ) {
V_20 = F_13 ( V_34 ) ;
goto V_106;
}
V_20 = F_136 ( V_15 , V_34 ,
V_152 , V_153 ) ;
if ( V_20 )
goto V_106;
V_20 = F_105 ( V_2 ) ;
if ( V_20 != 0 )
goto V_106;
return 0 ;
V_106:
if ( V_20 == - V_132 )
goto V_133;
F_64 ( V_2 ) ;
return V_20 ;
V_133:
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
goto V_130;
}
int F_137 ( struct V_33 * V_9 ,
struct V_122 * V_75 ,
struct V_154 * V_101 ,
T_1 V_155 )
{
struct V_5 * V_6 = V_9 -> V_63 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_7 * V_8 ;
int V_20 = 0 ;
if ( V_155 & V_156 )
return - V_30 ;
V_2 = F_100 ( V_6 -> V_46 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_129 = F_101 ( V_9 ) ;
V_130:
V_8 = F_114 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_20 = F_13 ( V_8 ) ;
goto V_106;
}
V_8 -> V_101 = V_101 ;
V_4 = F_102 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_20 = F_13 ( V_4 ) ;
goto V_106;
}
V_20 = F_103 ( V_4 , V_9 ) ;
if ( V_20 != 0 )
goto V_106;
F_104 ( V_4 , V_75 ) ;
V_2 -> V_157 = false ;
if ( ! V_8 -> V_32 ) {
F_8 ( L_32 ,
V_9 -> V_27 . V_28 ) ;
V_20 = - V_30 ;
goto V_106;
}
V_20 = F_138 ( V_2 ) ;
if ( V_20 != 0 )
goto V_106;
return 0 ;
V_106:
if ( V_20 == - V_132 )
goto V_133;
F_64 ( V_2 ) ;
return V_20 ;
V_133:
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
V_6 -> V_134 = V_6 -> V_75 ;
goto V_130;
}
int F_139 ( struct V_14 * V_15 ,
int V_39 )
{
struct V_150 * V_151 = & V_15 -> V_46 -> V_60 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_33 * V_9 ;
struct V_14 * V_158 ;
int V_20 ;
bool V_32 = false ;
int V_159 = V_15 -> V_56 ;
if ( V_39 != V_62 )
V_39 = V_57 ;
V_15 -> V_56 = V_39 ;
V_9 = V_15 -> V_2 -> V_9 ;
if ( ! V_9 )
return 0 ;
V_2 = F_100 ( V_15 -> V_46 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_129 = F_101 ( V_9 ) ;
V_130:
V_8 = F_114 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_20 = F_13 ( V_8 ) ;
goto V_106;
}
F_3 ( ! F_140 ( & V_151 -> V_137 ) ) ;
F_9 (tmp_connector, connector->dev) {
if ( V_158 -> V_2 -> V_9 != V_9 )
continue;
if ( V_158 -> V_56 == V_62 ) {
V_32 = true ;
break;
}
}
V_8 -> V_32 = V_32 ;
V_20 = F_105 ( V_2 ) ;
if ( V_20 != 0 )
goto V_106;
return 0 ;
V_106:
if ( V_20 == - V_132 )
goto V_133;
V_15 -> V_56 = V_159 ;
F_64 ( V_2 ) ;
return V_20 ;
V_133:
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
goto V_130;
}
struct V_16 *
F_6 ( struct V_14 * V_15 )
{
F_3 ( V_15 -> V_160 [ 1 ] ) ;
return F_141 ( V_15 -> V_46 , V_15 -> V_160 [ 0 ] ) ;
}
void F_142 ( struct V_33 * V_9 )
{
if ( V_9 -> V_2 )
F_143 ( V_9 -> V_2 ) ;
F_144 ( V_9 -> V_2 ) ;
V_9 -> V_2 = F_82 ( sizeof( * V_9 -> V_2 ) , V_95 ) ;
if ( V_9 -> V_2 )
V_9 -> V_2 -> V_9 = V_9 ;
}
void F_145 ( struct V_33 * V_9 ,
struct V_7 * V_2 )
{
memcpy ( V_2 , V_9 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_161 )
F_146 ( V_2 -> V_161 ) ;
if ( V_2 -> V_162 )
F_146 ( V_2 -> V_162 ) ;
if ( V_2 -> V_163 )
F_146 ( V_2 -> V_163 ) ;
if ( V_2 -> V_164 )
F_146 ( V_2 -> V_164 ) ;
V_2 -> V_37 = false ;
V_2 -> V_49 = false ;
V_2 -> V_10 = false ;
V_2 -> V_36 = false ;
V_2 -> V_165 = false ;
V_2 -> V_166 = false ;
V_2 -> V_101 = NULL ;
}
struct V_7 *
F_147 ( struct V_33 * V_9 )
{
struct V_7 * V_2 ;
if ( F_3 ( ! V_9 -> V_2 ) )
return NULL ;
V_2 = F_148 ( sizeof( * V_2 ) , V_95 ) ;
if ( V_2 )
F_145 ( V_9 , V_2 ) ;
return V_2 ;
}
void F_143 ( struct V_7 * V_2 )
{
F_149 ( V_2 -> V_161 ) ;
F_149 ( V_2 -> V_162 ) ;
F_149 ( V_2 -> V_163 ) ;
F_149 ( V_2 -> V_164 ) ;
}
void F_150 ( struct V_33 * V_9 ,
struct V_7 * V_2 )
{
F_143 ( V_2 ) ;
F_144 ( V_2 ) ;
}
void F_151 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 )
F_152 ( V_6 -> V_2 ) ;
F_144 ( V_6 -> V_2 ) ;
V_6 -> V_2 = F_82 ( sizeof( * V_6 -> V_2 ) , V_95 ) ;
if ( V_6 -> V_2 ) {
V_6 -> V_2 -> V_6 = V_6 ;
V_6 -> V_2 -> V_142 = F_117 ( V_167 ) ;
}
}
void F_153 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
memcpy ( V_2 , V_6 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_75 )
F_154 ( V_2 -> V_75 ) ;
}
struct V_3 *
F_155 ( struct V_5 * V_6 )
{
struct V_3 * V_2 ;
if ( F_3 ( ! V_6 -> V_2 ) )
return NULL ;
V_2 = F_148 ( sizeof( * V_2 ) , V_95 ) ;
if ( V_2 )
F_153 ( V_6 , V_2 ) ;
return V_2 ;
}
void F_152 ( struct V_3 * V_2 )
{
if ( V_2 -> V_75 )
F_156 ( V_2 -> V_75 ) ;
}
void F_157 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
F_152 ( V_2 ) ;
F_144 ( V_2 ) ;
}
void
F_158 ( struct V_14 * V_15 ,
struct V_12 * V_13 )
{
if ( V_13 )
V_13 -> V_15 = V_15 ;
V_15 -> V_2 = V_13 ;
}
void F_159 ( struct V_14 * V_15 )
{
struct V_12 * V_13 =
F_82 ( sizeof( * V_13 ) , V_95 ) ;
if ( V_15 -> V_2 )
F_160 ( V_15 -> V_2 ) ;
F_144 ( V_15 -> V_2 ) ;
F_158 ( V_15 , V_13 ) ;
}
void
F_161 ( struct V_14 * V_15 ,
struct V_12 * V_2 )
{
memcpy ( V_2 , V_15 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_9 )
F_162 ( V_15 ) ;
}
struct V_12 *
F_163 ( struct V_14 * V_15 )
{
struct V_12 * V_2 ;
if ( F_3 ( ! V_15 -> V_2 ) )
return NULL ;
V_2 = F_148 ( sizeof( * V_2 ) , V_95 ) ;
if ( V_2 )
F_161 ( V_15 , V_2 ) ;
return V_2 ;
}
struct V_1 *
F_123 ( struct V_45 * V_46 ,
struct V_145 * V_146 )
{
struct V_1 * V_2 ;
struct V_14 * V_147 ;
struct V_5 * V_6 ;
struct V_33 * V_9 ;
int V_148 = 0 ;
V_2 = F_100 ( V_46 ) ;
if ( ! V_2 )
return F_122 ( - V_96 ) ;
V_2 -> V_129 = V_146 ;
F_164 (crtc, dev) {
struct V_7 * V_8 ;
V_8 = F_114 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_148 = F_13 ( V_8 ) ;
goto free;
}
}
F_95 (plane, dev) {
struct V_3 * V_4 ;
V_4 = F_102 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_148 = F_13 ( V_4 ) ;
goto free;
}
}
F_9 (conn, dev) {
struct V_12 * V_13 ;
V_13 = F_11 ( V_2 , V_147 ) ;
if ( F_12 ( V_13 ) ) {
V_148 = F_13 ( V_13 ) ;
goto free;
}
}
V_2 -> V_129 = NULL ;
free:
if ( V_148 < 0 ) {
F_64 ( V_2 ) ;
V_2 = F_122 ( V_148 ) ;
}
return V_2 ;
}
void
F_160 ( struct V_12 * V_2 )
{
if ( V_2 -> V_9 )
F_165 ( V_2 -> V_15 ) ;
}
void F_166 ( struct V_14 * V_15 ,
struct V_12 * V_2 )
{
F_160 ( V_2 ) ;
F_144 ( V_2 ) ;
}
int F_167 ( struct V_33 * V_9 ,
T_3 * V_168 , T_3 * V_169 , T_3 * V_170 ,
T_1 V_171 )
{
struct V_45 * V_46 = V_9 -> V_46 ;
struct V_150 * V_151 = & V_46 -> V_60 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_172 * V_173 = NULL ;
struct V_174 * V_175 ;
int V_19 , V_20 = 0 ;
V_2 = F_100 ( V_9 -> V_46 ) ;
if ( ! V_2 )
return - V_96 ;
V_173 = F_168 ( V_46 ,
sizeof( struct V_174 ) * V_171 ,
NULL ) ;
if ( F_12 ( V_173 ) ) {
V_20 = F_13 ( V_173 ) ;
V_173 = NULL ;
goto V_106;
}
V_175 = (struct V_174 * ) V_173 -> V_176 ;
for ( V_19 = 0 ; V_19 < V_171 ; V_19 ++ ) {
V_175 [ V_19 ] . V_168 = V_168 [ V_19 ] ;
V_175 [ V_19 ] . V_169 = V_169 [ V_19 ] ;
V_175 [ V_19 ] . V_170 = V_170 [ V_19 ] ;
}
V_2 -> V_129 = V_9 -> V_46 -> V_60 . V_129 ;
V_130:
V_8 = F_114 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_20 = F_13 ( V_8 ) ;
goto V_106;
}
V_20 = F_132 ( V_9 , V_8 ,
V_151 -> V_177 , 0 ) ;
if ( V_20 )
goto V_106;
V_20 = F_132 ( V_9 , V_8 ,
V_151 -> V_178 , 0 ) ;
if ( V_20 )
goto V_106;
V_20 = F_132 ( V_9 , V_8 ,
V_151 -> V_179 , V_173 -> V_27 . V_28 ) ;
if ( V_20 )
goto V_106;
V_20 = F_105 ( V_2 ) ;
if ( V_20 )
goto V_106;
F_149 ( V_173 ) ;
return 0 ;
V_106:
if ( V_20 == - V_132 )
goto V_133;
F_64 ( V_2 ) ;
F_149 ( V_173 ) ;
return V_20 ;
V_133:
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
goto V_130;
}
