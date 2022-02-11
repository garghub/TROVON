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
else
V_24 = V_22 -> V_26 ( V_15 ) ;
if ( V_24 ) {
if ( V_18 & ( 1 << F_6 ( V_24 ) ) ) {
F_7 ( L_1 ,
V_24 -> V_27 . V_28 , V_24 -> V_29 ,
V_15 -> V_27 . V_28 , V_15 -> V_29 ) ;
return - V_30 ;
}
V_18 |= 1 << F_6 ( V_24 ) ;
}
}
if ( ! V_18 )
return 0 ;
F_8 (connector, state->dev) {
struct V_7 * V_8 ;
if ( F_9 ( V_2 , V_15 ) )
continue;
V_17 = V_15 -> V_2 -> V_26 ;
if ( ! V_17 || ! ( V_18 & ( 1 << F_6 ( V_17 ) ) ) )
continue;
if ( ! V_11 ) {
F_7 ( L_2 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ,
V_15 -> V_2 -> V_9 -> V_27 . V_28 ,
V_15 -> V_2 -> V_9 -> V_29 ,
V_15 -> V_27 . V_28 , V_15 -> V_29 ) ;
return - V_30 ;
}
V_13 = F_10 ( V_2 , V_15 ) ;
if ( F_11 ( V_13 ) )
return F_12 ( V_13 ) ;
F_7 ( L_3 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ,
V_13 -> V_9 -> V_27 . V_28 , V_13 -> V_9 -> V_29 ,
V_15 -> V_27 . V_28 , V_15 -> V_29 ) ;
V_8 = F_2 ( V_2 , V_13 -> V_9 ) ;
V_20 = F_13 ( V_13 , NULL ) ;
if ( V_20 )
return V_20 ;
if ( ! V_8 -> V_31 ) {
V_20 = F_14 ( V_8 ,
NULL ) ;
if ( V_20 < 0 )
return V_20 ;
V_8 -> V_32 = false ;
}
}
return 0 ;
}
static void
F_15 ( struct V_1 * V_2 ,
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
~ ( 1 << F_6 ( V_13 -> V_26 ) ) ;
}
}
if ( V_17 ) {
V_9 = V_13 -> V_9 ;
F_3 ( ! V_9 ) ;
if ( V_9 ) {
V_8 = F_2 ( V_2 , V_9 ) ;
V_8 -> V_18 |=
1 << F_6 ( V_17 ) ;
}
}
V_13 -> V_26 = V_17 ;
}
static void
F_16 ( struct V_1 * V_2 ,
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
F_7 ( L_4 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ,
V_35 -> V_27 . V_28 , V_35 -> V_29 ) ;
F_15 ( V_2 , V_34 , NULL ) ;
V_8 = F_2 ( V_2 , V_35 ) ;
V_8 -> V_36 = true ;
return;
}
}
static int
F_17 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_12 * V_34 )
{
const struct V_21 * V_22 ;
struct V_16 * V_24 ;
struct V_7 * V_8 ;
F_7 ( L_5 ,
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
F_7 ( L_6 ,
V_15 -> V_27 . V_28 ,
V_15 -> V_29 ) ;
F_15 ( V_2 , V_34 , NULL ) ;
return 0 ;
}
V_22 = V_15 -> V_23 ;
if ( V_22 -> V_25 )
V_24 = V_22 -> V_25 ( V_15 ,
V_34 ) ;
else
V_24 = V_22 -> V_26 ( V_15 ) ;
if ( ! V_24 ) {
F_7 ( L_7 ,
V_15 -> V_27 . V_28 ,
V_15 -> V_29 ) ;
return - V_30 ;
}
if ( ! F_18 ( V_24 , V_34 -> V_9 ) ) {
F_7 ( L_8 ,
V_24 -> V_27 . V_28 ,
V_24 -> V_29 ,
V_34 -> V_9 -> V_27 . V_28 ) ;
return - V_30 ;
}
if ( V_24 == V_34 -> V_26 ) {
F_15 ( V_2 , V_34 , V_24 ) ;
F_7 ( L_9 ,
V_15 -> V_27 . V_28 ,
V_15 -> V_29 ,
V_24 -> V_27 . V_28 ,
V_24 -> V_29 ,
V_34 -> V_9 -> V_27 . V_28 ,
V_34 -> V_9 -> V_29 ) ;
return 0 ;
}
F_16 ( V_2 , V_24 ) ;
F_15 ( V_2 , V_34 , V_24 ) ;
V_8 = F_2 ( V_2 , V_34 -> V_9 ) ;
V_8 -> V_36 = true ;
F_7 ( L_10 ,
V_15 -> V_27 . V_28 ,
V_15 -> V_29 ,
V_24 -> V_27 . V_28 ,
V_24 -> V_29 ,
V_34 -> V_9 -> V_27 . V_28 ,
V_34 -> V_9 -> V_29 ) ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_12 * V_13 ;
int V_19 ;
bool V_20 ;
F_20 (state, crtc, crtc_state, i) {
if ( ! V_8 -> V_37 &&
! V_8 -> V_36 )
continue;
F_21 ( & V_8 -> V_38 , & V_8 -> V_39 ) ;
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
if ( ! V_22 )
continue;
V_20 = F_22 ( V_17 -> V_41 , & V_8 -> V_39 ,
& V_8 -> V_38 ) ;
if ( ! V_20 ) {
F_7 ( L_11 ) ;
return - V_30 ;
}
if ( V_22 -> V_42 ) {
V_20 = V_22 -> V_42 ( V_17 , V_8 ,
V_13 ) ;
if ( V_20 ) {
F_7 ( L_12 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ) ;
return V_20 ;
}
} else if ( V_22 -> F_19 ) {
V_20 = V_22 -> F_19 ( V_17 , & V_8 -> V_39 ,
& V_8 -> V_38 ) ;
if ( ! V_20 ) {
F_7 ( L_13 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ) ;
return - V_30 ;
}
}
}
F_20 (state, crtc, crtc_state, i) {
const struct V_43 * V_22 ;
if ( ! V_8 -> V_37 &&
! V_8 -> V_36 )
continue;
V_22 = V_9 -> V_23 ;
if ( ! V_22 -> F_19 )
continue;
V_20 = V_22 -> F_19 ( V_9 , & V_8 -> V_39 ,
& V_8 -> V_38 ) ;
if ( ! V_20 ) {
F_7 ( L_14 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
return - V_30 ;
}
}
return 0 ;
}
int
F_23 ( struct V_44 * V_45 ,
struct V_1 * V_2 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_12 * V_34 ;
int V_19 , V_20 ;
F_20 (state, crtc, crtc_state, i) {
if ( ! F_24 ( & V_9 -> V_2 -> V_39 , & V_8 -> V_39 ) ) {
F_7 ( L_15 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
V_8 -> V_37 = true ;
}
if ( V_9 -> V_2 -> V_46 != V_8 -> V_46 ) {
F_7 ( L_16 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
V_8 -> V_37 = true ;
V_8 -> V_36 = true ;
}
}
V_20 = F_4 ( V_2 , V_2 -> V_47 ) ;
if ( V_20 )
return V_20 ;
F_5 (state, connector, connector_state, i) {
V_20 = F_17 ( V_2 , V_15 ,
V_34 ) ;
if ( V_20 )
return V_20 ;
}
F_20 (state, crtc, crtc_state, i) {
bool V_48 =
! ! V_8 -> V_31 ;
if ( V_9 -> V_2 -> V_32 != V_8 -> V_32 ) {
F_7 ( L_17 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
V_8 -> V_49 = true ;
}
if ( ! F_25 ( V_8 ) )
continue;
F_7 ( L_18 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ,
V_8 -> V_46 ? 'y' : 'n' ,
V_8 -> V_32 ? 'y' : 'n' ) ;
V_20 = F_26 ( V_2 , V_9 ) ;
if ( V_20 != 0 )
return V_20 ;
V_20 = F_27 ( V_2 , V_9 ) ;
if ( V_20 != 0 )
return V_20 ;
if ( V_8 -> V_46 != V_48 ) {
F_7 ( L_19 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
return - V_30 ;
}
}
return F_19 ( V_2 ) ;
}
int
F_28 ( struct V_44 * V_45 ,
struct V_1 * V_2 )
{
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_19 , V_20 = 0 ;
F_29 (state, plane, plane_state, i) {
const struct V_50 * V_22 ;
V_22 = V_6 -> V_23 ;
F_1 ( V_2 , V_4 , V_6 ) ;
if ( ! V_22 || ! V_22 -> V_42 )
continue;
V_20 = V_22 -> V_42 ( V_6 , V_4 ) ;
if ( V_20 ) {
F_7 ( L_20 ,
V_6 -> V_27 . V_28 , V_6 -> V_29 ) ;
return V_20 ;
}
}
F_20 (state, crtc, crtc_state, i) {
const struct V_43 * V_22 ;
V_22 = V_9 -> V_23 ;
if ( ! V_22 || ! V_22 -> V_42 )
continue;
V_20 = V_22 -> V_42 ( V_9 , V_2 -> V_51 [ V_19 ] ) ;
if ( V_20 ) {
F_7 ( L_21 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
return V_20 ;
}
}
return V_20 ;
}
int F_30 ( struct V_44 * V_45 ,
struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_23 ( V_45 , V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_28 ( V_45 , V_2 ) ;
if ( V_20 )
return V_20 ;
return V_20 ;
}
static void
F_31 ( struct V_44 * V_45 , struct V_1 * V_52 )
{
struct V_14 * V_15 ;
struct V_12 * V_53 ;
struct V_33 * V_9 ;
struct V_7 * V_54 ;
int V_19 ;
F_5 (old_state, connector, old_conn_state, i) {
const struct V_40 * V_22 ;
struct V_16 * V_17 ;
if ( ! V_53 -> V_9 )
continue;
V_54 = F_2 ( V_52 ,
V_53 -> V_9 ) ;
if ( ! V_54 -> V_32 ||
! F_25 ( V_53 -> V_9 -> V_2 ) )
continue;
V_17 = V_53 -> V_26 ;
if ( F_3 ( ! V_17 ) )
continue;
V_22 = V_17 -> V_23 ;
F_7 ( L_22 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ) ;
F_32 ( V_17 -> V_41 ) ;
if ( V_15 -> V_2 -> V_9 && V_22 -> V_55 )
V_22 -> V_55 ( V_17 ) ;
else if ( V_22 -> V_56 )
V_22 -> V_56 ( V_17 ) ;
else
V_22 -> V_57 ( V_17 , V_58 ) ;
F_33 ( V_17 -> V_41 ) ;
}
F_20 (old_state, crtc, old_crtc_state, i) {
const struct V_43 * V_22 ;
if ( ! F_25 ( V_9 -> V_2 ) )
continue;
if ( ! V_54 -> V_32 )
continue;
V_22 = V_9 -> V_23 ;
F_7 ( L_23 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
if ( V_9 -> V_2 -> V_46 && V_22 -> V_55 )
V_22 -> V_55 ( V_9 ) ;
else if ( V_22 -> V_56 )
V_22 -> V_56 ( V_9 ) ;
else
V_22 -> V_57 ( V_9 , V_58 ) ;
}
}
void
F_34 ( struct V_44 * V_45 ,
struct V_1 * V_52 )
{
struct V_14 * V_15 ;
struct V_12 * V_53 ;
struct V_33 * V_9 ;
struct V_7 * V_54 ;
int V_19 ;
F_5 (old_state, connector, old_conn_state, i) {
if ( V_15 -> V_17 ) {
F_3 ( ! V_15 -> V_17 -> V_9 ) ;
V_15 -> V_17 -> V_9 = NULL ;
V_15 -> V_17 = NULL ;
}
V_9 = V_15 -> V_2 -> V_9 ;
if ( ( ! V_9 && V_53 -> V_9 ) ||
( V_9 && F_25 ( V_9 -> V_2 ) ) ) {
struct V_59 * V_60 =
V_45 -> V_61 . V_62 ;
int V_39 = V_58 ;
if ( V_9 && V_9 -> V_2 -> V_32 )
V_39 = V_63 ;
V_15 -> V_57 = V_39 ;
F_35 ( & V_15 -> V_27 ,
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
F_20 (old_state, crtc, old_crtc_state, i) {
struct V_5 * V_64 = V_9 -> V_64 ;
V_9 -> V_39 = V_9 -> V_2 -> V_39 ;
V_9 -> V_65 = V_9 -> V_2 -> V_46 ;
if ( F_36 ( V_52 , V_64 ) &&
V_64 -> V_2 -> V_9 == V_9 ) {
V_9 -> V_66 = V_64 -> V_2 -> V_67 >> 16 ;
V_9 -> V_68 = V_64 -> V_2 -> V_69 >> 16 ;
}
if ( V_9 -> V_2 -> V_46 )
F_37 ( V_9 ,
& V_9 -> V_2 -> V_38 ) ;
}
}
static void
F_38 ( struct V_44 * V_45 , struct V_1 * V_52 )
{
struct V_33 * V_9 ;
struct V_7 * V_54 ;
struct V_14 * V_15 ;
struct V_12 * V_53 ;
int V_19 ;
F_20 (old_state, crtc, old_crtc_state, i) {
const struct V_43 * V_22 ;
if ( ! V_9 -> V_2 -> V_37 )
continue;
V_22 = V_9 -> V_23 ;
if ( V_9 -> V_2 -> V_46 && V_22 -> V_70 ) {
F_7 ( L_24 ,
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
F_7 ( L_25 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ) ;
if ( V_22 -> V_73 )
V_22 -> V_73 ( V_17 , V_39 , V_38 ) ;
F_39 ( V_17 -> V_41 , V_39 , V_38 ) ;
}
}
void F_40 ( struct V_44 * V_45 ,
struct V_1 * V_52 )
{
F_31 ( V_45 , V_52 ) ;
F_34 ( V_45 , V_52 ) ;
F_38 ( V_45 , V_52 ) ;
}
void F_41 ( struct V_44 * V_45 ,
struct V_1 * V_52 )
{
struct V_33 * V_9 ;
struct V_7 * V_54 ;
struct V_14 * V_15 ;
struct V_12 * V_53 ;
int V_19 ;
F_20 (old_state, crtc, old_crtc_state, i) {
const struct V_43 * V_22 ;
if ( ! F_25 ( V_9 -> V_2 ) )
continue;
if ( ! V_9 -> V_2 -> V_32 )
continue;
V_22 = V_9 -> V_23 ;
if ( V_9 -> V_2 -> V_46 ) {
F_7 ( L_26 ,
V_9 -> V_27 . V_28 , V_9 -> V_29 ) ;
if ( V_22 -> V_46 )
V_22 -> V_46 ( V_9 ) ;
else
V_22 -> V_74 ( V_9 ) ;
}
}
F_5 (old_state, connector, old_conn_state, i) {
const struct V_40 * V_22 ;
struct V_16 * V_17 ;
if ( ! V_15 -> V_2 -> V_26 )
continue;
if ( ! V_15 -> V_2 -> V_9 -> V_2 -> V_32 ||
! F_25 ( V_15 -> V_2 -> V_9 -> V_2 ) )
continue;
V_17 = V_15 -> V_2 -> V_26 ;
V_22 = V_17 -> V_23 ;
F_7 ( L_27 ,
V_17 -> V_27 . V_28 , V_17 -> V_29 ) ;
F_42 ( V_17 -> V_41 ) ;
if ( V_22 -> V_46 )
V_22 -> V_46 ( V_17 ) ;
else
V_22 -> V_74 ( V_17 ) ;
F_43 ( V_17 -> V_41 ) ;
}
}
static void F_44 ( struct V_44 * V_45 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_19 ;
F_29 (state, plane, plane_state, i) {
if ( ! V_6 -> V_2 -> V_75 )
continue;
F_3 ( ! V_6 -> V_2 -> V_76 ) ;
F_45 ( V_6 -> V_2 -> V_75 , false ) ;
F_46 ( V_6 -> V_2 -> V_75 ) ;
V_6 -> V_2 -> V_75 = NULL ;
}
}
bool F_47 ( struct V_44 * V_45 ,
struct V_1 * V_52 ,
struct V_33 * V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_77 ;
int V_19 ;
F_29 (old_state, plane, old_plane_state, i) {
if ( V_6 -> V_2 -> V_9 != V_9 &&
V_77 -> V_9 != V_9 )
continue;
if ( V_6 -> V_2 -> V_76 != V_77 -> V_76 )
return true ;
}
return false ;
}
void
F_48 ( struct V_44 * V_45 ,
struct V_1 * V_52 )
{
struct V_33 * V_9 ;
struct V_7 * V_54 ;
int V_19 , V_20 ;
F_20 (old_state, crtc, old_crtc_state, i) {
V_54 -> V_46 = false ;
if ( ! V_9 -> V_2 -> V_46 )
continue;
if ( V_52 -> V_78 )
continue;
if ( ! F_47 ( V_45 ,
V_52 , V_9 ) )
continue;
V_20 = F_49 ( V_9 ) ;
if ( V_20 != 0 )
continue;
V_54 -> V_46 = true ;
V_54 -> V_79 = F_50 ( V_9 ) ;
}
F_20 (old_state, crtc, old_crtc_state, i) {
if ( ! V_54 -> V_46 )
continue;
V_20 = F_51 ( V_45 -> V_80 [ V_19 ] . V_81 ,
V_54 -> V_79 !=
F_50 ( V_9 ) ,
F_52 ( 50 ) ) ;
F_53 ( V_9 ) ;
}
}
int F_54 ( struct V_44 * V_45 ,
struct V_1 * V_2 ,
bool V_82 )
{
int V_20 ;
if ( V_82 )
return - V_83 ;
V_20 = F_55 ( V_45 , V_2 ) ;
if ( V_20 )
return V_20 ;
F_56 ( V_45 , V_2 ) ;
F_44 ( V_45 , V_2 ) ;
F_40 ( V_45 , V_2 ) ;
F_57 ( V_45 , V_2 , false ) ;
F_41 ( V_45 , V_2 ) ;
F_48 ( V_45 , V_2 ) ;
F_58 ( V_45 , V_2 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
int F_55 ( struct V_44 * V_45 ,
struct V_1 * V_2 )
{
int V_84 = V_45 -> V_61 . V_85 ;
int V_20 , V_19 ;
for ( V_19 = 0 ; V_19 < V_84 ; V_19 ++ ) {
const struct V_50 * V_22 ;
struct V_5 * V_6 = V_2 -> V_86 [ V_19 ] ;
struct V_3 * V_4 = V_2 -> V_87 [ V_19 ] ;
if ( ! V_6 )
continue;
V_22 = V_6 -> V_23 ;
if ( V_22 -> V_88 ) {
V_20 = V_22 -> V_88 ( V_6 , V_4 ) ;
if ( V_20 )
goto V_89;
}
}
return 0 ;
V_89:
for ( V_19 -- ; V_19 >= 0 ; V_19 -- ) {
const struct V_50 * V_22 ;
struct V_5 * V_6 = V_2 -> V_86 [ V_19 ] ;
struct V_3 * V_4 = V_2 -> V_87 [ V_19 ] ;
if ( ! V_6 )
continue;
V_22 = V_6 -> V_23 ;
if ( V_22 -> V_90 )
V_22 -> V_90 ( V_6 , V_4 ) ;
}
return V_20 ;
}
bool F_60 ( struct V_3 * V_2 )
{
return V_2 -> V_9 && V_2 -> V_9 -> V_2 -> V_32 ;
}
void F_57 ( struct V_44 * V_45 ,
struct V_1 * V_52 ,
bool V_91 )
{
struct V_33 * V_9 ;
struct V_7 * V_54 ;
struct V_5 * V_6 ;
struct V_3 * V_77 ;
int V_19 ;
F_20 (old_state, crtc, old_crtc_state, i) {
const struct V_43 * V_22 ;
V_22 = V_9 -> V_23 ;
if ( ! V_22 || ! V_22 -> V_92 )
continue;
if ( V_91 && ! V_9 -> V_2 -> V_32 )
continue;
V_22 -> V_92 ( V_9 , V_54 ) ;
}
F_29 (old_state, plane, old_plane_state, i) {
const struct V_50 * V_22 ;
bool V_93 ;
V_22 = V_6 -> V_23 ;
if ( ! V_22 )
continue;
V_93 = F_61 ( V_6 , V_77 ) ;
if ( V_91 ) {
if ( ! V_93 && ! F_60 ( V_6 -> V_2 ) )
continue;
if ( V_93 && ! F_60 ( V_77 ) )
continue;
}
if ( V_93 && V_22 -> V_94 )
V_22 -> V_94 ( V_6 , V_77 ) ;
else if ( V_6 -> V_2 -> V_9 || V_93 )
V_22 -> V_95 ( V_6 , V_77 ) ;
}
F_20 (old_state, crtc, old_crtc_state, i) {
const struct V_43 * V_22 ;
V_22 = V_9 -> V_23 ;
if ( ! V_22 || ! V_22 -> V_96 )
continue;
if ( V_91 && ! V_9 -> V_2 -> V_32 )
continue;
V_22 -> V_96 ( V_9 , V_54 ) ;
}
}
void
F_62 ( struct V_7 * V_54 )
{
const struct V_43 * V_97 ;
struct V_33 * V_9 = V_54 -> V_9 ;
struct V_1 * V_52 = V_54 -> V_2 ;
struct V_5 * V_6 ;
unsigned V_98 ;
V_98 = V_54 -> V_98 ;
V_98 |= V_9 -> V_2 -> V_98 ;
V_97 = V_9 -> V_23 ;
if ( V_97 && V_97 -> V_92 )
V_97 -> V_92 ( V_9 , V_54 ) ;
F_63 (plane, crtc->dev, plane_mask) {
struct V_3 * V_77 =
F_36 ( V_52 , V_6 ) ;
const struct V_50 * V_99 ;
V_99 = V_6 -> V_23 ;
if ( ! V_77 || ! V_99 )
continue;
F_3 ( V_6 -> V_2 -> V_9 && V_6 -> V_2 -> V_9 != V_9 ) ;
if ( F_61 ( V_6 , V_77 ) &&
V_99 -> V_94 )
V_99 -> V_94 ( V_6 , V_77 ) ;
else if ( V_6 -> V_2 -> V_9 ||
F_61 ( V_6 , V_77 ) )
V_99 -> V_95 ( V_6 , V_77 ) ;
}
if ( V_97 && V_97 -> V_96 )
V_97 -> V_96 ( V_9 , V_54 ) ;
}
void F_64 ( struct V_33 * V_9 ,
bool V_100 )
{
const struct V_43 * V_97 =
V_9 -> V_23 ;
struct V_5 * V_6 ;
if ( V_100 && V_97 && V_97 -> V_92 )
V_97 -> V_92 ( V_9 , NULL ) ;
F_65 (plane, crtc->dev) {
const struct V_50 * V_99 =
V_6 -> V_23 ;
if ( V_6 -> V_2 -> V_9 != V_9 || ! V_99 )
continue;
F_3 ( ! V_99 -> V_94 ) ;
if ( V_99 -> V_94 )
V_99 -> V_94 ( V_6 , NULL ) ;
}
if ( V_100 && V_97 && V_97 -> V_96 )
V_97 -> V_96 ( V_9 , NULL ) ;
}
void F_58 ( struct V_44 * V_45 ,
struct V_1 * V_52 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_19 ;
F_29 (old_state, plane, plane_state, i) {
const struct V_50 * V_22 ;
V_22 = V_6 -> V_23 ;
if ( V_22 -> V_90 )
V_22 -> V_90 ( V_6 , V_4 ) ;
}
}
void F_56 ( struct V_44 * V_45 ,
struct V_1 * V_2 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_101 ; V_19 ++ ) {
struct V_14 * V_15 = V_2 -> V_102 [ V_19 ] ;
if ( ! V_15 )
continue;
V_15 -> V_2 -> V_2 = V_2 ;
F_66 ( V_2 -> V_103 [ V_19 ] , V_15 -> V_2 ) ;
V_15 -> V_2 -> V_2 = NULL ;
}
for ( V_19 = 0 ; V_19 < V_45 -> V_61 . V_104 ; V_19 ++ ) {
struct V_33 * V_9 = V_2 -> V_105 [ V_19 ] ;
if ( ! V_9 )
continue;
V_9 -> V_2 -> V_2 = V_2 ;
F_66 ( V_2 -> V_51 [ V_19 ] , V_9 -> V_2 ) ;
V_9 -> V_2 -> V_2 = NULL ;
}
for ( V_19 = 0 ; V_19 < V_45 -> V_61 . V_85 ; V_19 ++ ) {
struct V_5 * V_6 = V_2 -> V_86 [ V_19 ] ;
if ( ! V_6 )
continue;
V_6 -> V_2 -> V_2 = V_2 ;
F_66 ( V_2 -> V_87 [ V_19 ] , V_6 -> V_2 ) ;
V_6 -> V_2 -> V_2 = NULL ;
}
}
int F_67 ( struct V_5 * V_6 ,
struct V_33 * V_9 ,
struct V_106 * V_76 ,
int V_107 , int V_108 ,
unsigned int V_109 , unsigned int V_110 ,
T_1 V_67 , T_1 V_69 ,
T_1 V_111 , T_1 V_112 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_20 = 0 ;
V_2 = F_68 ( V_6 -> V_45 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = F_69 ( V_9 ) ;
V_115:
V_4 = F_70 ( V_2 , V_6 ) ;
if ( F_11 ( V_4 ) ) {
V_20 = F_12 ( V_4 ) ;
goto V_89;
}
V_20 = F_71 ( V_4 , V_9 ) ;
if ( V_20 != 0 )
goto V_89;
F_72 ( V_4 , V_76 ) ;
V_4 -> V_107 = V_107 ;
V_4 -> V_108 = V_108 ;
V_4 -> V_109 = V_109 ;
V_4 -> V_110 = V_110 ;
V_4 -> V_67 = V_67 ;
V_4 -> V_69 = V_69 ;
V_4 -> V_111 = V_111 ;
V_4 -> V_112 = V_112 ;
if ( V_6 == V_9 -> V_116 )
V_2 -> V_78 = true ;
V_20 = F_73 ( V_2 ) ;
if ( V_20 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_20 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_20 ;
V_118:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
V_6 -> V_119 = V_6 -> V_76 ;
goto V_115;
}
int F_76 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_20 = 0 ;
if ( ! V_6 -> V_9 )
return 0 ;
V_2 = F_68 ( V_6 -> V_45 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = F_69 ( V_6 -> V_9 ) ;
V_115:
V_4 = F_70 ( V_2 , V_6 ) ;
if ( F_11 ( V_4 ) ) {
V_20 = F_12 ( V_4 ) ;
goto V_89;
}
if ( V_4 -> V_9 && ( V_6 == V_6 -> V_9 -> V_116 ) )
V_4 -> V_2 -> V_78 = true ;
V_20 = F_77 ( V_6 , V_4 ) ;
if ( V_20 != 0 )
goto V_89;
V_20 = F_73 ( V_2 ) ;
if ( V_20 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_20 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_20 ;
V_118:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
V_6 -> V_119 = V_6 -> V_76 ;
goto V_115;
}
int F_77 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
int V_20 ;
V_20 = F_71 ( V_4 , NULL ) ;
if ( V_20 != 0 )
return V_20 ;
F_72 ( V_4 , NULL ) ;
V_4 -> V_107 = 0 ;
V_4 -> V_108 = 0 ;
V_4 -> V_109 = 0 ;
V_4 -> V_110 = 0 ;
V_4 -> V_67 = 0 ;
V_4 -> V_69 = 0 ;
V_4 -> V_111 = 0 ;
V_4 -> V_112 = 0 ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
struct V_44 * V_45 = V_121 -> V_9 -> V_45 ;
struct V_33 * V_9 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_12 * V_13 ;
int V_20 , V_19 ;
V_20 = F_79 ( & V_45 -> V_61 . V_122 ,
V_2 -> V_114 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_26 ( V_2 , V_121 -> V_9 ) ;
if ( V_20 )
return V_20 ;
F_5 (state, connector, conn_state, i) {
if ( V_13 -> V_9 == V_121 -> V_9 ) {
V_20 = F_13 ( V_13 ,
NULL ) ;
if ( V_20 )
return V_20 ;
}
}
for ( V_19 = 0 ; V_19 < V_121 -> V_123 ; V_19 ++ ) {
V_13 = F_10 ( V_2 ,
V_121 -> V_102 [ V_19 ] ) ;
if ( F_11 ( V_13 ) )
return F_12 ( V_13 ) ;
V_20 = F_13 ( V_13 ,
V_121 -> V_9 ) ;
if ( V_20 )
return V_20 ;
}
F_20 (state, crtc, crtc_state, i) {
if ( V_9 == V_121 -> V_9 )
continue;
if ( ! V_8 -> V_31 ) {
V_20 = F_14 ( V_8 ,
NULL ) ;
if ( V_20 < 0 )
return V_20 ;
V_8 -> V_32 = false ;
}
}
return 0 ;
}
int F_80 ( struct V_120 * V_121 )
{
struct V_1 * V_2 ;
struct V_33 * V_9 = V_121 -> V_9 ;
int V_20 = 0 ;
V_2 = F_68 ( V_9 -> V_45 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_47 = true ;
V_2 -> V_114 = F_69 ( V_9 ) ;
V_115:
V_20 = F_81 ( V_121 , V_2 ) ;
if ( V_20 != 0 )
goto V_89;
V_20 = F_73 ( V_2 ) ;
if ( V_20 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_20 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_20 ;
V_118:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
V_9 -> V_64 -> V_119 = V_9 -> V_64 -> V_76 ;
goto V_115;
}
int F_81 ( struct V_120 * V_121 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_3 * V_124 ;
struct V_33 * V_9 = V_121 -> V_9 ;
int V_125 , V_126 ;
int V_20 ;
V_8 = F_82 ( V_2 , V_9 ) ;
if ( F_11 ( V_8 ) )
return F_12 ( V_8 ) ;
V_124 = F_70 ( V_2 , V_9 -> V_64 ) ;
if ( F_11 ( V_124 ) )
return F_12 ( V_124 ) ;
if ( ! V_121 -> V_39 ) {
F_3 ( V_121 -> V_76 ) ;
F_3 ( V_121 -> V_123 ) ;
V_20 = F_83 ( V_8 , NULL ) ;
if ( V_20 != 0 )
return V_20 ;
V_8 -> V_32 = false ;
V_20 = F_71 ( V_124 , NULL ) ;
if ( V_20 != 0 )
return V_20 ;
F_72 ( V_124 , NULL ) ;
goto V_74;
}
F_3 ( ! V_121 -> V_76 ) ;
F_3 ( ! V_121 -> V_123 ) ;
V_20 = F_83 ( V_8 , V_121 -> V_39 ) ;
if ( V_20 != 0 )
return V_20 ;
V_8 -> V_32 = true ;
V_20 = F_71 ( V_124 , V_9 ) ;
if ( V_20 != 0 )
return V_20 ;
F_84 ( V_121 -> V_39 , & V_125 , & V_126 ) ;
F_72 ( V_124 , V_121 -> V_76 ) ;
V_124 -> V_107 = 0 ;
V_124 -> V_108 = 0 ;
V_124 -> V_109 = V_125 ;
V_124 -> V_110 = V_126 ;
V_124 -> V_67 = V_121 -> V_66 << 16 ;
V_124 -> V_69 = V_121 -> V_68 << 16 ;
if ( V_124 -> V_127 & ( F_85 ( V_128 ) | F_85 ( V_129 ) ) ) {
V_124 -> V_111 = V_126 << 16 ;
V_124 -> V_112 = V_125 << 16 ;
} else {
V_124 -> V_111 = V_125 << 16 ;
V_124 -> V_112 = V_126 << 16 ;
}
V_74:
V_20 = F_78 ( V_2 , V_121 ) ;
if ( V_20 )
return V_20 ;
return 0 ;
}
int F_86 ( struct V_44 * V_45 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 ;
struct V_14 * V_132 ;
int V_133 ;
V_2 = F_68 ( V_45 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = V_131 ;
F_8 (conn, dev) {
struct V_33 * V_9 = V_132 -> V_2 -> V_9 ;
struct V_7 * V_8 ;
if ( ! V_9 || V_132 -> V_57 != V_63 )
continue;
V_8 = F_82 ( V_2 , V_9 ) ;
if ( F_11 ( V_8 ) ) {
V_133 = F_12 ( V_8 ) ;
goto free;
}
V_8 -> V_32 = false ;
}
V_133 = F_73 ( V_2 ) ;
free:
if ( V_133 < 0 )
F_59 ( V_2 ) ;
return V_133 ;
}
struct V_1 * F_87 ( struct V_44 * V_45 )
{
struct V_130 V_131 ;
struct V_1 * V_2 ;
int V_133 ;
F_88 ( & V_131 , 0 ) ;
V_115:
V_133 = F_89 ( V_45 , & V_131 ) ;
if ( V_133 < 0 ) {
V_2 = F_90 ( V_133 ) ;
goto V_134;
}
V_2 = F_91 ( V_45 , & V_131 ) ;
if ( F_11 ( V_2 ) )
goto V_134;
V_133 = F_86 ( V_45 , & V_131 ) ;
if ( V_133 < 0 ) {
F_59 ( V_2 ) ;
V_2 = F_90 ( V_133 ) ;
goto V_134;
}
V_134:
if ( F_12 ( V_2 ) == - V_117 ) {
F_92 ( & V_131 ) ;
goto V_115;
}
F_93 ( & V_131 ) ;
F_94 ( & V_131 ) ;
return V_2 ;
}
int F_95 ( struct V_44 * V_45 ,
struct V_1 * V_2 )
{
struct V_135 * V_136 = & V_45 -> V_61 ;
int V_133 ;
F_96 ( V_45 ) ;
F_97 ( V_45 ) ;
V_2 -> V_114 = V_136 -> V_114 ;
V_133 = F_73 ( V_2 ) ;
F_98 ( V_45 ) ;
return V_133 ;
}
int
F_99 ( struct V_33 * V_9 ,
struct V_59 * V_137 ,
T_2 V_138 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_20 = 0 ;
V_2 = F_68 ( V_9 -> V_45 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = V_9 -> V_45 -> V_61 . V_114 ;
V_115:
V_8 = F_82 ( V_2 , V_9 ) ;
if ( F_11 ( V_8 ) ) {
V_20 = F_12 ( V_8 ) ;
goto V_89;
}
V_20 = F_100 ( V_9 , V_8 ,
V_137 , V_138 ) ;
if ( V_20 )
goto V_89;
V_20 = F_73 ( V_2 ) ;
if ( V_20 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_20 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_20 ;
V_118:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
goto V_115;
}
int
F_101 ( struct V_5 * V_6 ,
struct V_59 * V_137 ,
T_2 V_138 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_20 = 0 ;
V_2 = F_68 ( V_6 -> V_45 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = V_6 -> V_45 -> V_61 . V_114 ;
V_115:
V_4 = F_70 ( V_2 , V_6 ) ;
if ( F_11 ( V_4 ) ) {
V_20 = F_12 ( V_4 ) ;
goto V_89;
}
V_20 = F_102 ( V_6 , V_4 ,
V_137 , V_138 ) ;
if ( V_20 )
goto V_89;
V_20 = F_73 ( V_2 ) ;
if ( V_20 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_20 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_20 ;
V_118:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
goto V_115;
}
int
F_103 ( struct V_14 * V_15 ,
struct V_59 * V_137 ,
T_2 V_138 )
{
struct V_1 * V_2 ;
struct V_12 * V_34 ;
int V_20 = 0 ;
V_2 = F_68 ( V_15 -> V_45 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = V_15 -> V_45 -> V_61 . V_114 ;
V_115:
V_34 = F_10 ( V_2 , V_15 ) ;
if ( F_11 ( V_34 ) ) {
V_20 = F_12 ( V_34 ) ;
goto V_89;
}
V_20 = F_104 ( V_15 , V_34 ,
V_137 , V_138 ) ;
if ( V_20 )
goto V_89;
V_20 = F_73 ( V_2 ) ;
if ( V_20 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_20 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_20 ;
V_118:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
goto V_115;
}
int F_105 ( struct V_33 * V_9 ,
struct V_106 * V_76 ,
struct V_139 * V_140 ,
T_1 V_141 )
{
struct V_5 * V_6 = V_9 -> V_64 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_7 * V_8 ;
int V_20 = 0 ;
if ( V_141 & V_142 )
return - V_30 ;
V_2 = F_68 ( V_6 -> V_45 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = F_69 ( V_9 ) ;
V_115:
V_8 = F_82 ( V_2 , V_9 ) ;
if ( F_11 ( V_8 ) ) {
V_20 = F_12 ( V_8 ) ;
goto V_89;
}
V_8 -> V_140 = V_140 ;
V_4 = F_70 ( V_2 , V_6 ) ;
if ( F_11 ( V_4 ) ) {
V_20 = F_12 ( V_4 ) ;
goto V_89;
}
V_20 = F_71 ( V_4 , V_9 ) ;
if ( V_20 != 0 )
goto V_89;
F_72 ( V_4 , V_76 ) ;
V_2 -> V_143 = false ;
if ( ! V_8 -> V_32 ) {
F_7 ( L_28 ,
V_9 -> V_27 . V_28 ) ;
V_20 = - V_30 ;
goto V_89;
}
V_20 = F_106 ( V_2 ) ;
if ( V_20 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_20 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_20 ;
V_118:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
V_6 -> V_119 = V_6 -> V_76 ;
goto V_115;
}
int F_107 ( struct V_14 * V_15 ,
int V_39 )
{
struct V_135 * V_136 = & V_15 -> V_45 -> V_61 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_33 * V_9 ;
struct V_14 * V_144 ;
int V_20 ;
bool V_32 = false ;
int V_145 = V_15 -> V_57 ;
if ( V_39 != V_63 )
V_39 = V_58 ;
V_15 -> V_57 = V_39 ;
V_9 = V_15 -> V_2 -> V_9 ;
if ( ! V_9 )
return 0 ;
V_2 = F_68 ( V_15 -> V_45 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = F_69 ( V_9 ) ;
V_115:
V_8 = F_82 ( V_2 , V_9 ) ;
if ( F_11 ( V_8 ) ) {
V_20 = F_12 ( V_8 ) ;
goto V_89;
}
F_3 ( ! F_108 ( & V_136 -> V_122 ) ) ;
F_8 (tmp_connector, connector->dev) {
if ( V_144 -> V_2 -> V_9 != V_9 )
continue;
if ( V_144 -> V_57 == V_63 ) {
V_32 = true ;
break;
}
}
V_8 -> V_32 = V_32 ;
V_20 = F_73 ( V_2 ) ;
if ( V_20 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_20 == - V_117 )
goto V_118;
V_15 -> V_57 = V_145 ;
F_59 ( V_2 ) ;
return V_20 ;
V_118:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
goto V_115;
}
void F_109 ( struct V_33 * V_9 )
{
if ( V_9 -> V_2 ) {
F_110 ( V_9 -> V_2 -> V_146 ) ;
F_110 ( V_9 -> V_2 -> V_147 ) ;
F_110 ( V_9 -> V_2 -> V_148 ) ;
F_110 ( V_9 -> V_2 -> V_149 ) ;
}
F_111 ( V_9 -> V_2 ) ;
V_9 -> V_2 = F_112 ( sizeof( * V_9 -> V_2 ) , V_150 ) ;
if ( V_9 -> V_2 )
V_9 -> V_2 -> V_9 = V_9 ;
}
void F_113 ( struct V_33 * V_9 ,
struct V_7 * V_2 )
{
memcpy ( V_2 , V_9 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_146 )
F_114 ( V_2 -> V_146 ) ;
if ( V_2 -> V_147 )
F_114 ( V_2 -> V_147 ) ;
if ( V_2 -> V_148 )
F_114 ( V_2 -> V_148 ) ;
if ( V_2 -> V_149 )
F_114 ( V_2 -> V_149 ) ;
V_2 -> V_37 = false ;
V_2 -> V_49 = false ;
V_2 -> V_10 = false ;
V_2 -> V_36 = false ;
V_2 -> V_151 = false ;
V_2 -> V_140 = NULL ;
}
struct V_7 *
F_115 ( struct V_33 * V_9 )
{
struct V_7 * V_2 ;
if ( F_3 ( ! V_9 -> V_2 ) )
return NULL ;
V_2 = F_116 ( sizeof( * V_2 ) , V_150 ) ;
if ( V_2 )
F_113 ( V_9 , V_2 ) ;
return V_2 ;
}
void F_117 ( struct V_33 * V_9 ,
struct V_7 * V_2 )
{
F_110 ( V_2 -> V_146 ) ;
F_110 ( V_2 -> V_147 ) ;
F_110 ( V_2 -> V_148 ) ;
F_110 ( V_2 -> V_149 ) ;
}
void F_118 ( struct V_33 * V_9 ,
struct V_7 * V_2 )
{
F_117 ( V_9 , V_2 ) ;
F_111 ( V_2 ) ;
}
void F_119 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 && V_6 -> V_2 -> V_76 )
F_120 ( V_6 -> V_2 -> V_76 ) ;
F_111 ( V_6 -> V_2 ) ;
V_6 -> V_2 = F_112 ( sizeof( * V_6 -> V_2 ) , V_150 ) ;
if ( V_6 -> V_2 ) {
V_6 -> V_2 -> V_6 = V_6 ;
V_6 -> V_2 -> V_127 = F_85 ( V_152 ) ;
}
}
void F_121 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
memcpy ( V_2 , V_6 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_76 )
F_122 ( V_2 -> V_76 ) ;
}
struct V_3 *
F_123 ( struct V_5 * V_6 )
{
struct V_3 * V_2 ;
if ( F_3 ( ! V_6 -> V_2 ) )
return NULL ;
V_2 = F_116 ( sizeof( * V_2 ) , V_150 ) ;
if ( V_2 )
F_121 ( V_6 , V_2 ) ;
return V_2 ;
}
void F_124 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
if ( V_2 -> V_76 )
F_120 ( V_2 -> V_76 ) ;
}
void F_125 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
F_124 ( V_6 , V_2 ) ;
F_111 ( V_2 ) ;
}
void
F_126 ( struct V_14 * V_15 ,
struct V_12 * V_13 )
{
if ( V_13 )
V_13 -> V_15 = V_15 ;
V_15 -> V_2 = V_13 ;
}
void F_127 ( struct V_14 * V_15 )
{
struct V_12 * V_13 =
F_112 ( sizeof( * V_13 ) , V_150 ) ;
F_111 ( V_15 -> V_2 ) ;
F_126 ( V_15 , V_13 ) ;
}
void
F_128 ( struct V_14 * V_15 ,
struct V_12 * V_2 )
{
memcpy ( V_2 , V_15 -> V_2 , sizeof( * V_2 ) ) ;
}
struct V_12 *
F_129 ( struct V_14 * V_15 )
{
struct V_12 * V_2 ;
if ( F_3 ( ! V_15 -> V_2 ) )
return NULL ;
V_2 = F_116 ( sizeof( * V_2 ) , V_150 ) ;
if ( V_2 )
F_128 ( V_15 , V_2 ) ;
return V_2 ;
}
struct V_1 *
F_91 ( struct V_44 * V_45 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 ;
struct V_14 * V_132 ;
struct V_5 * V_6 ;
struct V_33 * V_9 ;
int V_133 = 0 ;
V_2 = F_68 ( V_45 ) ;
if ( ! V_2 )
return F_90 ( - V_113 ) ;
V_2 -> V_114 = V_131 ;
F_130 (crtc, dev) {
struct V_7 * V_8 ;
V_8 = F_82 ( V_2 , V_9 ) ;
if ( F_11 ( V_8 ) ) {
V_133 = F_12 ( V_8 ) ;
goto free;
}
}
F_65 (plane, dev) {
struct V_3 * V_4 ;
V_4 = F_70 ( V_2 , V_6 ) ;
if ( F_11 ( V_4 ) ) {
V_133 = F_12 ( V_4 ) ;
goto free;
}
}
F_8 (conn, dev) {
struct V_12 * V_13 ;
V_13 = F_10 ( V_2 , V_132 ) ;
if ( F_11 ( V_13 ) ) {
V_133 = F_12 ( V_13 ) ;
goto free;
}
}
V_2 -> V_114 = NULL ;
free:
if ( V_133 < 0 ) {
F_59 ( V_2 ) ;
V_2 = F_90 ( V_133 ) ;
}
return V_2 ;
}
void
F_131 ( struct V_14 * V_15 ,
struct V_12 * V_2 )
{
}
void F_132 ( struct V_14 * V_15 ,
struct V_12 * V_2 )
{
F_131 ( V_15 , V_2 ) ;
F_111 ( V_2 ) ;
}
void F_133 ( struct V_33 * V_9 ,
T_3 * V_153 , T_3 * V_154 , T_3 * V_155 ,
T_1 V_156 , T_1 V_157 )
{
struct V_44 * V_45 = V_9 -> V_45 ;
struct V_135 * V_136 = & V_45 -> V_61 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_158 * V_159 = NULL ;
struct V_160 * V_161 ;
int V_19 , V_20 = 0 ;
V_2 = F_68 ( V_9 -> V_45 ) ;
if ( ! V_2 )
return;
V_159 = F_134 ( V_45 ,
sizeof( struct V_160 ) * V_157 ,
NULL ) ;
if ( F_11 ( V_159 ) ) {
V_20 = F_12 ( V_159 ) ;
V_159 = NULL ;
goto V_89;
}
V_161 = (struct V_160 * ) V_159 -> V_162 ;
for ( V_19 = 0 ; V_19 < V_157 ; V_19 ++ ) {
V_161 [ V_19 ] . V_153 = V_153 [ V_19 ] ;
V_161 [ V_19 ] . V_154 = V_154 [ V_19 ] ;
V_161 [ V_19 ] . V_155 = V_155 [ V_19 ] ;
}
V_2 -> V_114 = V_9 -> V_45 -> V_61 . V_114 ;
V_115:
V_8 = F_82 ( V_2 , V_9 ) ;
if ( F_11 ( V_8 ) ) {
V_20 = F_12 ( V_8 ) ;
goto V_89;
}
V_20 = F_100 ( V_9 , V_8 ,
V_136 -> V_163 , 0 ) ;
if ( V_20 )
goto V_89;
V_20 = F_100 ( V_9 , V_8 ,
V_136 -> V_164 , 0 ) ;
if ( V_20 )
goto V_89;
V_20 = F_100 ( V_9 , V_8 ,
V_136 -> V_165 , V_159 -> V_27 . V_28 ) ;
if ( V_20 )
goto V_89;
V_20 = F_73 ( V_2 ) ;
if ( V_20 )
goto V_89;
F_110 ( V_159 ) ;
return;
V_89:
if ( V_20 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
F_110 ( V_159 ) ;
return;
V_118:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
goto V_115;
}
