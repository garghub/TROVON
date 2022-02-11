static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
if ( V_6 -> V_2 -> V_9 ) {
V_8 = V_2 -> V_10 [ F_2 ( V_6 -> V_2 -> V_9 ) ] ;
if ( F_3 ( ! V_8 ) )
return;
V_8 -> V_11 = true ;
}
if ( V_4 -> V_9 ) {
V_8 =
V_2 -> V_10 [ F_2 ( V_4 -> V_9 ) ] ;
if ( F_3 ( ! V_8 ) )
return;
V_8 -> V_11 = true ;
}
}
static bool
F_4 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
F_5 (state, connector, conn_state, i) {
if ( V_17 -> V_19 != V_13 )
continue;
if ( V_15 -> V_2 -> V_19 != V_17 -> V_19 )
return false ;
}
return true ;
}
static struct V_20 *
F_6 ( struct V_21 * V_22 ,
struct V_12 * V_23 )
{
struct V_24 * V_25 = & V_22 -> V_26 ;
struct V_14 * V_15 ;
F_3 ( ! F_7 ( & V_25 -> V_27 ) ) ;
F_8 (connector, dev) {
if ( V_15 -> V_2 -> V_19 != V_23 )
continue;
return V_15 -> V_2 -> V_9 ;
}
return NULL ;
}
static int
F_9 ( struct V_1 * V_2 ,
struct V_12 * V_23 ,
struct V_20 * V_28 )
{
struct V_24 * V_25 = & V_2 -> V_22 -> V_26 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_16 * V_29 ;
int V_30 ;
F_3 ( ! F_7 ( & V_25 -> V_27 ) ) ;
F_10 ( L_1 ,
V_23 -> V_31 . V_32 , V_23 -> V_33 ,
V_28 -> V_31 . V_32 , V_28 -> V_33 ) ;
V_8 = F_11 ( V_2 , V_28 ) ;
if ( F_12 ( V_8 ) )
return F_13 ( V_8 ) ;
V_8 -> V_34 = true ;
F_14 (connector, &config->connector_list, head) {
if ( V_15 -> V_2 -> V_19 != V_23 )
continue;
F_10 ( L_2 ,
V_15 -> V_31 . V_32 ,
V_15 -> V_33 ) ;
V_29 = F_15 ( V_2 ,
V_15 ) ;
if ( F_12 ( V_29 ) )
return F_13 ( V_29 ) ;
V_30 = F_16 ( V_29 , NULL ) ;
if ( V_30 )
return V_30 ;
V_29 -> V_19 = NULL ;
}
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , int V_35 )
{
const struct V_36 * V_37 ;
struct V_12 * V_13 ;
struct V_20 * V_28 ;
struct V_14 * V_15 ;
struct V_16 * V_29 ;
struct V_7 * V_8 ;
int V_38 , V_30 ;
V_15 = V_2 -> V_39 [ V_35 ] ;
V_29 = V_2 -> V_40 [ V_35 ] ;
if ( ! V_15 )
return 0 ;
F_10 ( L_3 ,
V_15 -> V_31 . V_32 ,
V_15 -> V_33 ) ;
if ( V_15 -> V_2 -> V_9 != V_29 -> V_9 ) {
if ( V_15 -> V_2 -> V_9 ) {
V_38 = F_2 ( V_15 -> V_2 -> V_9 ) ;
V_8 = V_2 -> V_10 [ V_38 ] ;
V_8 -> V_34 = true ;
}
if ( V_29 -> V_9 ) {
V_38 = F_2 ( V_29 -> V_9 ) ;
V_8 = V_2 -> V_10 [ V_38 ] ;
V_8 -> V_34 = true ;
}
}
if ( ! V_29 -> V_9 ) {
F_10 ( L_4 ,
V_15 -> V_31 . V_32 ,
V_15 -> V_33 ) ;
V_29 -> V_19 = NULL ;
return 0 ;
}
V_37 = V_15 -> V_41 ;
if ( V_37 -> V_42 )
V_13 = V_37 -> V_42 ( V_15 ,
V_29 ) ;
else
V_13 = V_37 -> V_19 ( V_15 ) ;
if ( ! V_13 ) {
F_10 ( L_5 ,
V_15 -> V_31 . V_32 ,
V_15 -> V_33 ) ;
return - V_43 ;
}
if ( ! F_18 ( V_13 , V_29 -> V_9 ) ) {
F_10 ( L_6 ,
V_13 -> V_31 . V_32 ,
V_13 -> V_33 ,
V_29 -> V_9 -> V_31 . V_32 ) ;
return - V_43 ;
}
if ( V_13 == V_29 -> V_19 ) {
F_10 ( L_7 ,
V_15 -> V_31 . V_32 ,
V_15 -> V_33 ,
V_13 -> V_31 . V_32 ,
V_13 -> V_33 ,
V_29 -> V_9 -> V_31 . V_32 ,
V_29 -> V_9 -> V_33 ) ;
return 0 ;
}
if ( ! F_4 ( V_2 , V_13 ) ) {
F_10 ( L_8 ,
V_15 -> V_31 . V_32 ,
V_15 -> V_33 ) ;
return - V_43 ;
}
V_28 = F_6 ( V_2 -> V_22 ,
V_13 ) ;
if ( V_28 ) {
V_30 = F_9 ( V_2 , V_13 , V_28 ) ;
if ( V_30 ) {
F_10 ( L_9 ,
V_15 -> V_31 . V_32 ,
V_15 -> V_33 ) ;
return V_30 ;
}
}
if ( F_3 ( ! V_29 -> V_9 ) )
return - V_43 ;
V_29 -> V_19 = V_13 ;
V_38 = F_2 ( V_29 -> V_9 ) ;
V_8 = V_2 -> V_10 [ V_38 ] ;
V_8 -> V_34 = true ;
F_10 ( L_10 ,
V_15 -> V_31 . V_32 ,
V_15 -> V_33 ,
V_13 -> V_31 . V_32 ,
V_13 -> V_33 ,
V_29 -> V_9 -> V_31 . V_32 ,
V_29 -> V_9 -> V_33 ) ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 )
{
struct V_20 * V_9 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
bool V_30 ;
F_20 (state, crtc, crtc_state, i) {
if ( ! V_8 -> V_44 &&
! V_8 -> V_34 )
continue;
F_21 ( & V_8 -> V_45 , & V_8 -> V_46 ) ;
}
F_5 (state, connector, conn_state, i) {
const struct V_47 * V_37 ;
struct V_12 * V_23 ;
F_3 ( ! ! V_17 -> V_19 != ! ! V_17 -> V_9 ) ;
if ( ! V_17 -> V_9 || ! V_17 -> V_19 )
continue;
V_8 =
V_2 -> V_10 [ F_2 ( V_17 -> V_9 ) ] ;
V_23 = V_17 -> V_19 ;
V_37 = V_23 -> V_41 ;
if ( ! V_37 )
continue;
V_30 = F_22 ( V_23 -> V_48 , & V_8 -> V_46 ,
& V_8 -> V_45 ) ;
if ( ! V_30 ) {
F_10 ( L_11 ) ;
return - V_43 ;
}
if ( V_37 -> V_49 ) {
V_30 = V_37 -> V_49 ( V_23 , V_8 ,
V_17 ) ;
if ( V_30 ) {
F_10 ( L_12 ,
V_23 -> V_31 . V_32 , V_23 -> V_33 ) ;
return V_30 ;
}
} else if ( V_37 -> F_19 ) {
V_30 = V_37 -> F_19 ( V_23 , & V_8 -> V_46 ,
& V_8 -> V_45 ) ;
if ( ! V_30 ) {
F_10 ( L_13 ,
V_23 -> V_31 . V_32 , V_23 -> V_33 ) ;
return - V_43 ;
}
}
}
F_20 (state, crtc, crtc_state, i) {
const struct V_50 * V_37 ;
if ( ! V_8 -> V_44 &&
! V_8 -> V_34 )
continue;
V_37 = V_9 -> V_41 ;
if ( ! V_37 -> F_19 )
continue;
V_30 = V_37 -> F_19 ( V_9 , & V_8 -> V_46 ,
& V_8 -> V_45 ) ;
if ( ! V_30 ) {
F_10 ( L_14 ,
V_9 -> V_31 . V_32 , V_9 -> V_33 ) ;
return - V_43 ;
}
}
return 0 ;
}
int
F_23 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_20 * V_9 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_16 * V_29 ;
int V_18 , V_30 ;
F_20 (state, crtc, crtc_state, i) {
if ( ! F_24 ( & V_9 -> V_2 -> V_46 , & V_8 -> V_46 ) ) {
F_10 ( L_15 ,
V_9 -> V_31 . V_32 , V_9 -> V_33 ) ;
V_8 -> V_44 = true ;
}
if ( V_9 -> V_2 -> V_51 != V_8 -> V_51 ) {
F_10 ( L_16 ,
V_9 -> V_31 . V_32 , V_9 -> V_33 ) ;
V_8 -> V_44 = true ;
V_8 -> V_34 = true ;
}
}
F_5 (state, connector, connector_state, i) {
V_30 = F_17 ( V_2 , V_18 ) ;
if ( V_30 )
return V_30 ;
}
F_20 (state, crtc, crtc_state, i) {
bool V_52 =
! ! V_8 -> V_53 ;
if ( V_9 -> V_2 -> V_54 != V_8 -> V_54 ) {
F_10 ( L_17 ,
V_9 -> V_31 . V_32 , V_9 -> V_33 ) ;
V_8 -> V_55 = true ;
}
if ( ! F_25 ( V_8 ) )
continue;
F_10 ( L_18 ,
V_9 -> V_31 . V_32 , V_9 -> V_33 ,
V_8 -> V_51 ? 'y' : 'n' ,
V_8 -> V_54 ? 'y' : 'n' ) ;
V_30 = F_26 ( V_2 , V_9 ) ;
if ( V_30 != 0 )
return V_30 ;
V_30 = F_27 ( V_2 , V_9 ) ;
if ( V_30 != 0 )
return V_30 ;
if ( V_8 -> V_51 != V_52 ) {
F_10 ( L_19 ,
V_9 -> V_31 . V_32 , V_9 -> V_33 ) ;
return - V_43 ;
}
}
return F_19 ( V_2 ) ;
}
int
F_28 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_20 * V_9 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_18 , V_30 = 0 ;
F_29 (state, plane, plane_state, i) {
const struct V_56 * V_37 ;
V_37 = V_6 -> V_41 ;
F_1 ( V_2 , V_4 , V_6 ) ;
if ( ! V_37 || ! V_37 -> V_49 )
continue;
V_30 = V_37 -> V_49 ( V_6 , V_4 ) ;
if ( V_30 ) {
F_10 ( L_20 ,
V_6 -> V_31 . V_32 , V_6 -> V_33 ) ;
return V_30 ;
}
}
F_20 (state, crtc, crtc_state, i) {
const struct V_50 * V_37 ;
V_37 = V_9 -> V_41 ;
if ( ! V_37 || ! V_37 -> V_49 )
continue;
V_30 = V_37 -> V_49 ( V_9 , V_2 -> V_10 [ V_18 ] ) ;
if ( V_30 ) {
F_10 ( L_21 ,
V_9 -> V_31 . V_32 , V_9 -> V_33 ) ;
return V_30 ;
}
}
return V_30 ;
}
int F_30 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
int V_30 ;
V_30 = F_23 ( V_22 , V_2 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_28 ( V_22 , V_2 ) ;
if ( V_30 )
return V_30 ;
return V_30 ;
}
static void
F_31 ( struct V_21 * V_22 , struct V_1 * V_57 )
{
struct V_14 * V_15 ;
struct V_16 * V_58 ;
struct V_20 * V_9 ;
struct V_7 * V_59 ;
int V_18 ;
F_5 (old_state, connector, old_conn_state, i) {
const struct V_47 * V_37 ;
struct V_12 * V_23 ;
struct V_7 * V_59 ;
if ( ! V_58 -> V_9 )
continue;
V_59 = V_57 -> V_10 [ F_2 ( V_58 -> V_9 ) ] ;
if ( ! V_59 -> V_54 ||
! F_25 ( V_58 -> V_9 -> V_2 ) )
continue;
V_23 = V_58 -> V_19 ;
if ( F_3 ( ! V_23 ) )
continue;
V_37 = V_23 -> V_41 ;
F_10 ( L_22 ,
V_23 -> V_31 . V_32 , V_23 -> V_33 ) ;
F_32 ( V_23 -> V_48 ) ;
if ( V_15 -> V_2 -> V_9 && V_37 -> V_60 )
V_37 -> V_60 ( V_23 ) ;
else if ( V_37 -> V_61 )
V_37 -> V_61 ( V_23 ) ;
else
V_37 -> V_62 ( V_23 , V_63 ) ;
F_33 ( V_23 -> V_48 ) ;
}
F_20 (old_state, crtc, old_crtc_state, i) {
const struct V_50 * V_37 ;
if ( ! F_25 ( V_9 -> V_2 ) )
continue;
if ( ! V_59 -> V_54 )
continue;
V_37 = V_9 -> V_41 ;
F_10 ( L_23 ,
V_9 -> V_31 . V_32 , V_9 -> V_33 ) ;
if ( V_9 -> V_2 -> V_51 && V_37 -> V_60 )
V_37 -> V_60 ( V_9 ) ;
else if ( V_37 -> V_61 )
V_37 -> V_61 ( V_9 ) ;
else
V_37 -> V_62 ( V_9 , V_63 ) ;
}
}
void
F_34 ( struct V_21 * V_22 ,
struct V_1 * V_57 )
{
struct V_14 * V_15 ;
struct V_16 * V_58 ;
struct V_20 * V_9 ;
struct V_7 * V_59 ;
int V_18 ;
F_5 (old_state, connector, old_conn_state, i) {
if ( V_15 -> V_23 ) {
F_3 ( ! V_15 -> V_23 -> V_9 ) ;
V_15 -> V_23 -> V_9 = NULL ;
V_15 -> V_23 = NULL ;
}
V_9 = V_15 -> V_2 -> V_9 ;
if ( ( ! V_9 && V_58 -> V_9 ) ||
( V_9 && F_25 ( V_9 -> V_2 ) ) ) {
struct V_64 * V_65 =
V_22 -> V_26 . V_66 ;
int V_46 = V_63 ;
if ( V_9 && V_9 -> V_2 -> V_54 )
V_46 = V_67 ;
V_15 -> V_62 = V_46 ;
F_35 ( & V_15 -> V_31 ,
V_65 , V_46 ) ;
}
}
F_5 (old_state, connector, old_conn_state, i) {
if ( ! V_15 -> V_2 -> V_9 )
continue;
if ( F_3 ( ! V_15 -> V_2 -> V_19 ) )
continue;
V_15 -> V_23 = V_15 -> V_2 -> V_19 ;
V_15 -> V_23 -> V_9 = V_15 -> V_2 -> V_9 ;
}
F_20 (old_state, crtc, old_crtc_state, i) {
struct V_5 * V_68 = V_9 -> V_68 ;
V_9 -> V_46 = V_9 -> V_2 -> V_46 ;
V_9 -> V_69 = V_9 -> V_2 -> V_51 ;
if ( F_36 ( V_57 , V_68 ) &&
V_68 -> V_2 -> V_9 == V_9 ) {
V_9 -> V_70 = V_68 -> V_2 -> V_71 >> 16 ;
V_9 -> V_72 = V_68 -> V_2 -> V_73 >> 16 ;
}
if ( V_9 -> V_2 -> V_51 )
F_37 ( V_9 ,
& V_9 -> V_2 -> V_45 ) ;
}
}
static void
F_38 ( struct V_21 * V_22 , struct V_1 * V_57 )
{
struct V_20 * V_9 ;
struct V_7 * V_59 ;
struct V_14 * V_15 ;
struct V_16 * V_58 ;
int V_18 ;
F_20 (old_state, crtc, old_crtc_state, i) {
const struct V_50 * V_37 ;
if ( ! V_9 -> V_2 -> V_44 )
continue;
V_37 = V_9 -> V_41 ;
if ( V_9 -> V_2 -> V_51 && V_37 -> V_74 ) {
F_10 ( L_24 ,
V_9 -> V_31 . V_32 , V_9 -> V_33 ) ;
V_37 -> V_74 ( V_9 ) ;
}
}
F_5 (old_state, connector, old_conn_state, i) {
const struct V_47 * V_37 ;
struct V_7 * V_75 ;
struct V_12 * V_23 ;
struct V_76 * V_46 , * V_45 ;
if ( ! V_15 -> V_2 -> V_19 )
continue;
V_23 = V_15 -> V_2 -> V_19 ;
V_37 = V_23 -> V_41 ;
V_75 = V_15 -> V_2 -> V_9 -> V_2 ;
V_46 = & V_75 -> V_46 ;
V_45 = & V_75 -> V_45 ;
if ( ! V_75 -> V_44 )
continue;
F_10 ( L_25 ,
V_23 -> V_31 . V_32 , V_23 -> V_33 ) ;
if ( V_37 -> V_77 )
V_37 -> V_77 ( V_23 , V_46 , V_45 ) ;
F_39 ( V_23 -> V_48 , V_46 , V_45 ) ;
}
}
void F_40 ( struct V_21 * V_22 ,
struct V_1 * V_57 )
{
F_31 ( V_22 , V_57 ) ;
F_34 ( V_22 , V_57 ) ;
F_38 ( V_22 , V_57 ) ;
}
void F_41 ( struct V_21 * V_22 ,
struct V_1 * V_57 )
{
struct V_20 * V_9 ;
struct V_7 * V_59 ;
struct V_14 * V_15 ;
struct V_16 * V_58 ;
int V_18 ;
F_20 (old_state, crtc, old_crtc_state, i) {
const struct V_50 * V_37 ;
if ( ! F_25 ( V_9 -> V_2 ) )
continue;
if ( ! V_9 -> V_2 -> V_54 )
continue;
V_37 = V_9 -> V_41 ;
if ( V_9 -> V_2 -> V_51 ) {
F_10 ( L_26 ,
V_9 -> V_31 . V_32 , V_9 -> V_33 ) ;
if ( V_37 -> V_51 )
V_37 -> V_51 ( V_9 ) ;
else
V_37 -> V_78 ( V_9 ) ;
}
}
F_5 (old_state, connector, old_conn_state, i) {
const struct V_47 * V_37 ;
struct V_12 * V_23 ;
if ( ! V_15 -> V_2 -> V_19 )
continue;
if ( ! V_15 -> V_2 -> V_9 -> V_2 -> V_54 ||
! F_25 ( V_15 -> V_2 -> V_9 -> V_2 ) )
continue;
V_23 = V_15 -> V_2 -> V_19 ;
V_37 = V_23 -> V_41 ;
F_10 ( L_27 ,
V_23 -> V_31 . V_32 , V_23 -> V_33 ) ;
F_42 ( V_23 -> V_48 ) ;
if ( V_37 -> V_51 )
V_37 -> V_51 ( V_23 ) ;
else
V_37 -> V_78 ( V_23 ) ;
F_43 ( V_23 -> V_48 ) ;
}
}
static void F_44 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_18 ;
F_29 (state, plane, plane_state, i) {
if ( ! V_6 -> V_2 -> V_79 )
continue;
F_3 ( ! V_6 -> V_2 -> V_80 ) ;
F_45 ( V_6 -> V_2 -> V_79 , false ) ;
F_46 ( V_6 -> V_2 -> V_79 ) ;
V_6 -> V_2 -> V_79 = NULL ;
}
}
bool F_47 ( struct V_21 * V_22 ,
struct V_1 * V_57 ,
struct V_20 * V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_81 ;
int V_18 ;
F_29 (old_state, plane, old_plane_state, i) {
if ( V_6 -> V_2 -> V_9 != V_9 &&
V_81 -> V_9 != V_9 )
continue;
if ( V_6 -> V_2 -> V_80 != V_81 -> V_80 )
return true ;
}
return false ;
}
void
F_48 ( struct V_21 * V_22 ,
struct V_1 * V_57 )
{
struct V_20 * V_9 ;
struct V_7 * V_59 ;
int V_18 , V_30 ;
F_20 (old_state, crtc, old_crtc_state, i) {
V_59 -> V_51 = false ;
if ( ! V_9 -> V_2 -> V_51 )
continue;
if ( V_57 -> V_82 )
continue;
if ( ! F_47 ( V_22 ,
V_57 , V_9 ) )
continue;
V_30 = F_49 ( V_9 ) ;
if ( V_30 != 0 )
continue;
V_59 -> V_51 = true ;
V_59 -> V_83 = F_50 ( V_9 ) ;
}
F_20 (old_state, crtc, old_crtc_state, i) {
if ( ! V_59 -> V_51 )
continue;
V_30 = F_51 ( V_22 -> V_84 [ V_18 ] . V_85 ,
V_59 -> V_83 !=
F_50 ( V_9 ) ,
F_52 ( 50 ) ) ;
F_53 ( V_9 ) ;
}
}
int F_54 ( struct V_21 * V_22 ,
struct V_1 * V_2 ,
bool V_86 )
{
int V_30 ;
if ( V_86 )
return - V_87 ;
V_30 = F_55 ( V_22 , V_2 ) ;
if ( V_30 )
return V_30 ;
F_56 ( V_22 , V_2 ) ;
F_44 ( V_22 , V_2 ) ;
F_40 ( V_22 , V_2 ) ;
F_57 ( V_22 , V_2 , false ) ;
F_41 ( V_22 , V_2 ) ;
F_48 ( V_22 , V_2 ) ;
F_58 ( V_22 , V_2 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
int F_55 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
int V_88 = V_22 -> V_26 . V_89 ;
int V_30 , V_18 ;
for ( V_18 = 0 ; V_18 < V_88 ; V_18 ++ ) {
const struct V_56 * V_37 ;
struct V_5 * V_6 = V_2 -> V_90 [ V_18 ] ;
struct V_3 * V_4 = V_2 -> V_91 [ V_18 ] ;
if ( ! V_6 )
continue;
V_37 = V_6 -> V_41 ;
if ( V_37 -> V_92 ) {
V_30 = V_37 -> V_92 ( V_6 , V_4 ) ;
if ( V_30 )
goto V_93;
}
}
return 0 ;
V_93:
for ( V_18 -- ; V_18 >= 0 ; V_18 -- ) {
const struct V_56 * V_37 ;
struct V_5 * V_6 = V_2 -> V_90 [ V_18 ] ;
struct V_3 * V_4 = V_2 -> V_91 [ V_18 ] ;
if ( ! V_6 )
continue;
V_37 = V_6 -> V_41 ;
if ( V_37 -> V_94 )
V_37 -> V_94 ( V_6 , V_4 ) ;
}
return V_30 ;
}
bool F_60 ( struct V_3 * V_2 )
{
return V_2 -> V_9 && V_2 -> V_9 -> V_2 -> V_54 ;
}
void F_57 ( struct V_21 * V_22 ,
struct V_1 * V_57 ,
bool V_95 )
{
struct V_20 * V_9 ;
struct V_7 * V_59 ;
struct V_5 * V_6 ;
struct V_3 * V_81 ;
int V_18 ;
F_20 (old_state, crtc, old_crtc_state, i) {
const struct V_50 * V_37 ;
V_37 = V_9 -> V_41 ;
if ( ! V_37 || ! V_37 -> V_96 )
continue;
if ( V_95 && ! V_9 -> V_2 -> V_54 )
continue;
V_37 -> V_96 ( V_9 , V_59 ) ;
}
F_29 (old_state, plane, old_plane_state, i) {
const struct V_56 * V_37 ;
bool V_97 ;
V_37 = V_6 -> V_41 ;
if ( ! V_37 )
continue;
V_97 = F_61 ( V_6 , V_81 ) ;
if ( V_95 ) {
if ( ! V_97 && ! F_60 ( V_6 -> V_2 ) )
continue;
if ( V_97 && ! F_60 ( V_81 ) )
continue;
}
if ( V_97 && V_37 -> V_98 )
V_37 -> V_98 ( V_6 , V_81 ) ;
else if ( V_6 -> V_2 -> V_9 || V_97 )
V_37 -> V_99 ( V_6 , V_81 ) ;
}
F_20 (old_state, crtc, old_crtc_state, i) {
const struct V_50 * V_37 ;
V_37 = V_9 -> V_41 ;
if ( ! V_37 || ! V_37 -> V_100 )
continue;
if ( V_95 && ! V_9 -> V_2 -> V_54 )
continue;
V_37 -> V_100 ( V_9 , V_59 ) ;
}
}
void
F_62 ( struct V_7 * V_59 )
{
const struct V_50 * V_101 ;
struct V_20 * V_9 = V_59 -> V_9 ;
struct V_1 * V_57 = V_59 -> V_2 ;
struct V_5 * V_6 ;
unsigned V_102 ;
V_102 = V_59 -> V_102 ;
V_102 |= V_9 -> V_2 -> V_102 ;
V_101 = V_9 -> V_41 ;
if ( V_101 && V_101 -> V_96 )
V_101 -> V_96 ( V_9 , V_59 ) ;
F_63 (plane, crtc->dev, plane_mask) {
struct V_3 * V_81 =
F_36 ( V_57 , V_6 ) ;
const struct V_56 * V_103 ;
V_103 = V_6 -> V_41 ;
if ( ! V_81 || ! V_103 )
continue;
F_3 ( V_6 -> V_2 -> V_9 && V_6 -> V_2 -> V_9 != V_9 ) ;
if ( F_61 ( V_6 , V_81 ) &&
V_103 -> V_98 )
V_103 -> V_98 ( V_6 , V_81 ) ;
else if ( V_6 -> V_2 -> V_9 ||
F_61 ( V_6 , V_81 ) )
V_103 -> V_99 ( V_6 , V_81 ) ;
}
if ( V_101 && V_101 -> V_100 )
V_101 -> V_100 ( V_9 , V_59 ) ;
}
void F_64 ( struct V_20 * V_9 ,
bool V_104 )
{
const struct V_50 * V_101 =
V_9 -> V_41 ;
struct V_5 * V_6 ;
if ( V_104 && V_101 && V_101 -> V_96 )
V_101 -> V_96 ( V_9 , NULL ) ;
F_65 (plane, crtc->dev) {
const struct V_56 * V_103 =
V_6 -> V_41 ;
if ( V_6 -> V_2 -> V_9 != V_9 || ! V_103 )
continue;
F_3 ( ! V_103 -> V_98 ) ;
if ( V_103 -> V_98 )
V_103 -> V_98 ( V_6 , NULL ) ;
}
if ( V_104 && V_101 && V_101 -> V_100 )
V_101 -> V_100 ( V_9 , NULL ) ;
}
void F_58 ( struct V_21 * V_22 ,
struct V_1 * V_57 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_18 ;
F_29 (old_state, plane, plane_state, i) {
const struct V_56 * V_37 ;
V_37 = V_6 -> V_41 ;
if ( V_37 -> V_94 )
V_37 -> V_94 ( V_6 , V_4 ) ;
}
}
void F_56 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_105 ; V_18 ++ ) {
struct V_14 * V_15 = V_2 -> V_39 [ V_18 ] ;
if ( ! V_15 )
continue;
V_15 -> V_2 -> V_2 = V_2 ;
F_66 ( V_2 -> V_40 [ V_18 ] , V_15 -> V_2 ) ;
V_15 -> V_2 -> V_2 = NULL ;
}
for ( V_18 = 0 ; V_18 < V_22 -> V_26 . V_106 ; V_18 ++ ) {
struct V_20 * V_9 = V_2 -> V_107 [ V_18 ] ;
if ( ! V_9 )
continue;
V_9 -> V_2 -> V_2 = V_2 ;
F_66 ( V_2 -> V_10 [ V_18 ] , V_9 -> V_2 ) ;
V_9 -> V_2 -> V_2 = NULL ;
}
for ( V_18 = 0 ; V_18 < V_22 -> V_26 . V_89 ; V_18 ++ ) {
struct V_5 * V_6 = V_2 -> V_90 [ V_18 ] ;
if ( ! V_6 )
continue;
V_6 -> V_2 -> V_2 = V_2 ;
F_66 ( V_2 -> V_91 [ V_18 ] , V_6 -> V_2 ) ;
V_6 -> V_2 -> V_2 = NULL ;
}
}
int F_67 ( struct V_5 * V_6 ,
struct V_20 * V_9 ,
struct V_108 * V_80 ,
int V_109 , int V_110 ,
unsigned int V_111 , unsigned int V_112 ,
T_1 V_71 , T_1 V_73 ,
T_1 V_113 , T_1 V_114 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_30 = 0 ;
V_2 = F_68 ( V_6 -> V_22 ) ;
if ( ! V_2 )
return - V_115 ;
V_2 -> V_116 = F_69 ( V_9 ) ;
V_117:
V_4 = F_70 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_30 = F_13 ( V_4 ) ;
goto V_93;
}
V_30 = F_71 ( V_4 , V_9 ) ;
if ( V_30 != 0 )
goto V_93;
F_72 ( V_4 , V_80 ) ;
V_4 -> V_109 = V_109 ;
V_4 -> V_110 = V_110 ;
V_4 -> V_111 = V_111 ;
V_4 -> V_112 = V_112 ;
V_4 -> V_71 = V_71 ;
V_4 -> V_73 = V_73 ;
V_4 -> V_113 = V_113 ;
V_4 -> V_114 = V_114 ;
if ( V_6 == V_9 -> V_118 )
V_2 -> V_82 = true ;
V_30 = F_73 ( V_2 ) ;
if ( V_30 != 0 )
goto V_93;
return 0 ;
V_93:
if ( V_30 == - V_119 )
goto V_120;
F_59 ( V_2 ) ;
return V_30 ;
V_120:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
V_6 -> V_121 = V_6 -> V_80 ;
goto V_117;
}
int F_76 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_30 = 0 ;
if ( ! V_6 -> V_9 )
return 0 ;
V_2 = F_68 ( V_6 -> V_22 ) ;
if ( ! V_2 )
return - V_115 ;
V_2 -> V_116 = F_69 ( V_6 -> V_9 ) ;
V_117:
V_4 = F_70 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_30 = F_13 ( V_4 ) ;
goto V_93;
}
if ( V_4 -> V_9 && ( V_6 == V_6 -> V_9 -> V_118 ) )
V_4 -> V_2 -> V_82 = true ;
V_30 = F_77 ( V_6 , V_4 ) ;
if ( V_30 != 0 )
goto V_93;
V_30 = F_73 ( V_2 ) ;
if ( V_30 != 0 )
goto V_93;
return 0 ;
V_93:
if ( V_30 == - V_119 )
goto V_120;
F_59 ( V_2 ) ;
return V_30 ;
V_120:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
V_6 -> V_121 = V_6 -> V_80 ;
goto V_117;
}
int F_77 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
int V_30 ;
V_30 = F_71 ( V_4 , NULL ) ;
if ( V_30 != 0 )
return V_30 ;
F_72 ( V_4 , NULL ) ;
V_4 -> V_109 = 0 ;
V_4 -> V_110 = 0 ;
V_4 -> V_111 = 0 ;
V_4 -> V_112 = 0 ;
V_4 -> V_71 = 0 ;
V_4 -> V_73 = 0 ;
V_4 -> V_113 = 0 ;
V_4 -> V_114 = 0 ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_122 * V_123 )
{
struct V_21 * V_22 = V_123 -> V_9 -> V_22 ;
struct V_20 * V_9 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_30 , V_18 , V_124 ;
V_30 = F_79 ( & V_22 -> V_26 . V_27 ,
V_2 -> V_116 ) ;
if ( V_30 )
return V_30 ;
for ( V_18 = 0 ; V_18 < V_123 -> V_125 ; V_18 ++ ) {
V_17 = F_15 ( V_2 ,
V_123 -> V_39 [ V_18 ] ) ;
if ( F_12 ( V_17 ) )
return F_13 ( V_17 ) ;
}
F_20 (state, crtc, crtc_state, i) {
V_30 = F_26 ( V_2 , V_9 ) ;
if ( V_30 )
return V_30 ;
}
F_5 (state, connector, conn_state, i) {
if ( V_17 -> V_9 == V_123 -> V_9 ) {
V_30 = F_16 ( V_17 ,
NULL ) ;
if ( V_30 )
return V_30 ;
}
for ( V_124 = 0 ; V_124 < V_123 -> V_125 ; V_124 ++ ) {
if ( V_123 -> V_39 [ V_124 ] == V_15 ) {
V_30 = F_16 ( V_17 ,
V_123 -> V_9 ) ;
if ( V_30 )
return V_30 ;
break;
}
}
}
F_20 (state, crtc, crtc_state, i) {
if ( V_9 == V_123 -> V_9 )
continue;
if ( ! V_8 -> V_53 ) {
V_30 = F_80 ( V_8 ,
NULL ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 -> V_54 = false ;
}
}
return 0 ;
}
int F_81 ( struct V_122 * V_123 )
{
struct V_1 * V_2 ;
struct V_20 * V_9 = V_123 -> V_9 ;
int V_30 = 0 ;
V_2 = F_68 ( V_9 -> V_22 ) ;
if ( ! V_2 )
return - V_115 ;
V_2 -> V_116 = F_69 ( V_9 ) ;
V_117:
V_30 = F_82 ( V_123 , V_2 ) ;
if ( V_30 != 0 )
goto V_93;
V_30 = F_73 ( V_2 ) ;
if ( V_30 != 0 )
goto V_93;
return 0 ;
V_93:
if ( V_30 == - V_119 )
goto V_120;
F_59 ( V_2 ) ;
return V_30 ;
V_120:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
V_9 -> V_68 -> V_121 = V_9 -> V_68 -> V_80 ;
goto V_117;
}
int F_82 ( struct V_122 * V_123 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_3 * V_126 ;
struct V_20 * V_9 = V_123 -> V_9 ;
int V_127 , V_128 ;
int V_30 ;
V_8 = F_11 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) )
return F_13 ( V_8 ) ;
V_126 = F_70 ( V_2 , V_9 -> V_68 ) ;
if ( F_12 ( V_126 ) )
return F_13 ( V_126 ) ;
if ( ! V_123 -> V_46 ) {
F_3 ( V_123 -> V_80 ) ;
F_3 ( V_123 -> V_125 ) ;
V_30 = F_83 ( V_8 , NULL ) ;
if ( V_30 != 0 )
return V_30 ;
V_8 -> V_54 = false ;
V_30 = F_71 ( V_126 , NULL ) ;
if ( V_30 != 0 )
return V_30 ;
F_72 ( V_126 , NULL ) ;
goto V_78;
}
F_3 ( ! V_123 -> V_80 ) ;
F_3 ( ! V_123 -> V_125 ) ;
V_30 = F_83 ( V_8 , V_123 -> V_46 ) ;
if ( V_30 != 0 )
return V_30 ;
V_8 -> V_54 = true ;
V_30 = F_71 ( V_126 , V_9 ) ;
if ( V_30 != 0 )
return V_30 ;
F_84 ( V_123 -> V_46 , & V_127 , & V_128 ) ;
F_72 ( V_126 , V_123 -> V_80 ) ;
V_126 -> V_109 = 0 ;
V_126 -> V_110 = 0 ;
V_126 -> V_111 = V_127 ;
V_126 -> V_112 = V_128 ;
V_126 -> V_71 = V_123 -> V_70 << 16 ;
V_126 -> V_73 = V_123 -> V_72 << 16 ;
if ( V_126 -> V_129 & ( F_85 ( V_130 ) | F_85 ( V_131 ) ) ) {
V_126 -> V_113 = V_128 << 16 ;
V_126 -> V_114 = V_127 << 16 ;
} else {
V_126 -> V_113 = V_127 << 16 ;
V_126 -> V_114 = V_128 << 16 ;
}
V_78:
V_30 = F_78 ( V_2 , V_123 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
}
int F_86 ( struct V_21 * V_22 ,
struct V_132 * V_133 )
{
struct V_1 * V_2 ;
struct V_14 * V_134 ;
int V_135 ;
V_2 = F_68 ( V_22 ) ;
if ( ! V_2 )
return - V_115 ;
V_2 -> V_116 = V_133 ;
F_8 (conn, dev) {
struct V_20 * V_9 = V_134 -> V_2 -> V_9 ;
struct V_7 * V_8 ;
if ( ! V_9 || V_134 -> V_62 != V_67 )
continue;
V_8 = F_11 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_135 = F_13 ( V_8 ) ;
goto free;
}
V_8 -> V_54 = false ;
}
V_135 = F_73 ( V_2 ) ;
free:
if ( V_135 < 0 )
F_59 ( V_2 ) ;
return V_135 ;
}
struct V_1 * F_87 ( struct V_21 * V_22 )
{
struct V_132 V_133 ;
struct V_1 * V_2 ;
int V_135 ;
F_88 ( & V_133 , 0 ) ;
V_117:
V_135 = F_89 ( V_22 , & V_133 ) ;
if ( V_135 < 0 ) {
V_2 = F_90 ( V_135 ) ;
goto V_136;
}
V_2 = F_91 ( V_22 , & V_133 ) ;
if ( F_12 ( V_2 ) )
goto V_136;
V_135 = F_86 ( V_22 , & V_133 ) ;
if ( V_135 < 0 ) {
F_59 ( V_2 ) ;
V_2 = F_90 ( V_135 ) ;
goto V_136;
}
V_136:
if ( F_13 ( V_2 ) == - V_119 ) {
F_92 ( & V_133 ) ;
goto V_117;
}
F_93 ( & V_133 ) ;
F_94 ( & V_133 ) ;
return V_2 ;
}
int F_95 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 = & V_22 -> V_26 ;
int V_135 ;
F_96 ( V_22 ) ;
F_97 ( V_22 ) ;
V_2 -> V_116 = V_25 -> V_116 ;
V_135 = F_73 ( V_2 ) ;
F_98 ( V_22 ) ;
return V_135 ;
}
int
F_99 ( struct V_20 * V_9 ,
struct V_64 * V_137 ,
T_2 V_138 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_30 = 0 ;
V_2 = F_68 ( V_9 -> V_22 ) ;
if ( ! V_2 )
return - V_115 ;
V_2 -> V_116 = V_9 -> V_22 -> V_26 . V_116 ;
V_117:
V_8 = F_11 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_30 = F_13 ( V_8 ) ;
goto V_93;
}
V_30 = F_100 ( V_9 , V_8 ,
V_137 , V_138 ) ;
if ( V_30 )
goto V_93;
V_30 = F_73 ( V_2 ) ;
if ( V_30 != 0 )
goto V_93;
return 0 ;
V_93:
if ( V_30 == - V_119 )
goto V_120;
F_59 ( V_2 ) ;
return V_30 ;
V_120:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
goto V_117;
}
int
F_101 ( struct V_5 * V_6 ,
struct V_64 * V_137 ,
T_2 V_138 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_30 = 0 ;
V_2 = F_68 ( V_6 -> V_22 ) ;
if ( ! V_2 )
return - V_115 ;
V_2 -> V_116 = V_6 -> V_22 -> V_26 . V_116 ;
V_117:
V_4 = F_70 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_30 = F_13 ( V_4 ) ;
goto V_93;
}
V_30 = F_102 ( V_6 , V_4 ,
V_137 , V_138 ) ;
if ( V_30 )
goto V_93;
V_30 = F_73 ( V_2 ) ;
if ( V_30 != 0 )
goto V_93;
return 0 ;
V_93:
if ( V_30 == - V_119 )
goto V_120;
F_59 ( V_2 ) ;
return V_30 ;
V_120:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
goto V_117;
}
int
F_103 ( struct V_14 * V_15 ,
struct V_64 * V_137 ,
T_2 V_138 )
{
struct V_1 * V_2 ;
struct V_16 * V_29 ;
int V_30 = 0 ;
V_2 = F_68 ( V_15 -> V_22 ) ;
if ( ! V_2 )
return - V_115 ;
V_2 -> V_116 = V_15 -> V_22 -> V_26 . V_116 ;
V_117:
V_29 = F_15 ( V_2 , V_15 ) ;
if ( F_12 ( V_29 ) ) {
V_30 = F_13 ( V_29 ) ;
goto V_93;
}
V_30 = F_104 ( V_15 , V_29 ,
V_137 , V_138 ) ;
if ( V_30 )
goto V_93;
V_30 = F_73 ( V_2 ) ;
if ( V_30 != 0 )
goto V_93;
return 0 ;
V_93:
if ( V_30 == - V_119 )
goto V_120;
F_59 ( V_2 ) ;
return V_30 ;
V_120:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
goto V_117;
}
int F_105 ( struct V_20 * V_9 ,
struct V_108 * V_80 ,
struct V_139 * V_140 ,
T_1 V_141 )
{
struct V_5 * V_6 = V_9 -> V_68 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_7 * V_8 ;
int V_30 = 0 ;
if ( V_141 & V_142 )
return - V_43 ;
V_2 = F_68 ( V_6 -> V_22 ) ;
if ( ! V_2 )
return - V_115 ;
V_2 -> V_116 = F_69 ( V_9 ) ;
V_117:
V_8 = F_11 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_30 = F_13 ( V_8 ) ;
goto V_93;
}
V_8 -> V_140 = V_140 ;
V_4 = F_70 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_30 = F_13 ( V_4 ) ;
goto V_93;
}
V_30 = F_71 ( V_4 , V_9 ) ;
if ( V_30 != 0 )
goto V_93;
F_72 ( V_4 , V_80 ) ;
V_2 -> V_143 = false ;
if ( ! V_8 -> V_54 ) {
F_10 ( L_28 ,
V_9 -> V_31 . V_32 ) ;
V_30 = - V_43 ;
goto V_93;
}
V_30 = F_106 ( V_2 ) ;
if ( V_30 != 0 )
goto V_93;
return 0 ;
V_93:
if ( V_30 == - V_119 )
goto V_120;
F_59 ( V_2 ) ;
return V_30 ;
V_120:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
V_6 -> V_121 = V_6 -> V_80 ;
goto V_117;
}
int F_107 ( struct V_14 * V_15 ,
int V_46 )
{
struct V_24 * V_25 = & V_15 -> V_22 -> V_26 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_20 * V_9 ;
struct V_14 * V_144 ;
int V_30 ;
bool V_54 = false ;
int V_145 = V_15 -> V_62 ;
if ( V_46 != V_67 )
V_46 = V_63 ;
V_15 -> V_62 = V_46 ;
V_9 = V_15 -> V_2 -> V_9 ;
if ( ! V_9 )
return 0 ;
V_2 = F_68 ( V_15 -> V_22 ) ;
if ( ! V_2 )
return - V_115 ;
V_2 -> V_116 = F_69 ( V_9 ) ;
V_117:
V_8 = F_11 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_30 = F_13 ( V_8 ) ;
goto V_93;
}
F_3 ( ! F_7 ( & V_25 -> V_27 ) ) ;
F_8 (tmp_connector, connector->dev) {
if ( V_144 -> V_2 -> V_9 != V_9 )
continue;
if ( V_144 -> V_62 == V_67 ) {
V_54 = true ;
break;
}
}
V_8 -> V_54 = V_54 ;
V_30 = F_73 ( V_2 ) ;
if ( V_30 != 0 )
goto V_93;
return 0 ;
V_93:
if ( V_30 == - V_119 )
goto V_120;
V_15 -> V_62 = V_145 ;
F_59 ( V_2 ) ;
return V_30 ;
V_120:
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
goto V_117;
}
void F_108 ( struct V_20 * V_9 )
{
if ( V_9 -> V_2 )
F_109 ( V_9 -> V_2 -> V_146 ) ;
F_110 ( V_9 -> V_2 ) ;
V_9 -> V_2 = F_111 ( sizeof( * V_9 -> V_2 ) , V_147 ) ;
if ( V_9 -> V_2 )
V_9 -> V_2 -> V_9 = V_9 ;
}
void F_112 ( struct V_20 * V_9 ,
struct V_7 * V_2 )
{
memcpy ( V_2 , V_9 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_146 )
F_113 ( V_2 -> V_146 ) ;
V_2 -> V_44 = false ;
V_2 -> V_55 = false ;
V_2 -> V_11 = false ;
V_2 -> V_34 = false ;
V_2 -> V_140 = NULL ;
}
struct V_7 *
F_114 ( struct V_20 * V_9 )
{
struct V_7 * V_2 ;
if ( F_3 ( ! V_9 -> V_2 ) )
return NULL ;
V_2 = F_115 ( sizeof( * V_2 ) , V_147 ) ;
if ( V_2 )
F_112 ( V_9 , V_2 ) ;
return V_2 ;
}
void F_116 ( struct V_20 * V_9 ,
struct V_7 * V_2 )
{
F_109 ( V_2 -> V_146 ) ;
}
void F_117 ( struct V_20 * V_9 ,
struct V_7 * V_2 )
{
F_116 ( V_9 , V_2 ) ;
F_110 ( V_2 ) ;
}
void F_118 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 && V_6 -> V_2 -> V_80 )
F_119 ( V_6 -> V_2 -> V_80 ) ;
F_110 ( V_6 -> V_2 ) ;
V_6 -> V_2 = F_111 ( sizeof( * V_6 -> V_2 ) , V_147 ) ;
if ( V_6 -> V_2 )
V_6 -> V_2 -> V_6 = V_6 ;
}
void F_120 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
memcpy ( V_2 , V_6 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_80 )
F_121 ( V_2 -> V_80 ) ;
}
struct V_3 *
F_122 ( struct V_5 * V_6 )
{
struct V_3 * V_2 ;
if ( F_3 ( ! V_6 -> V_2 ) )
return NULL ;
V_2 = F_115 ( sizeof( * V_2 ) , V_147 ) ;
if ( V_2 )
F_120 ( V_6 , V_2 ) ;
return V_2 ;
}
void F_123 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
if ( V_2 -> V_80 )
F_119 ( V_2 -> V_80 ) ;
}
void F_124 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
F_123 ( V_6 , V_2 ) ;
F_110 ( V_2 ) ;
}
void
F_125 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
if ( V_17 )
V_17 -> V_15 = V_15 ;
V_15 -> V_2 = V_17 ;
}
void F_126 ( struct V_14 * V_15 )
{
struct V_16 * V_17 =
F_111 ( sizeof( * V_17 ) , V_147 ) ;
F_110 ( V_15 -> V_2 ) ;
F_125 ( V_15 , V_17 ) ;
}
void
F_127 ( struct V_14 * V_15 ,
struct V_16 * V_2 )
{
memcpy ( V_2 , V_15 -> V_2 , sizeof( * V_2 ) ) ;
}
struct V_16 *
F_128 ( struct V_14 * V_15 )
{
struct V_16 * V_2 ;
if ( F_3 ( ! V_15 -> V_2 ) )
return NULL ;
V_2 = F_115 ( sizeof( * V_2 ) , V_147 ) ;
if ( V_2 )
F_127 ( V_15 , V_2 ) ;
return V_2 ;
}
struct V_1 *
F_91 ( struct V_21 * V_22 ,
struct V_132 * V_133 )
{
struct V_1 * V_2 ;
struct V_14 * V_134 ;
struct V_5 * V_6 ;
struct V_20 * V_9 ;
int V_135 = 0 ;
V_2 = F_68 ( V_22 ) ;
if ( ! V_2 )
return F_90 ( - V_115 ) ;
V_2 -> V_116 = V_133 ;
F_129 (crtc, dev) {
struct V_7 * V_8 ;
V_8 = F_11 ( V_2 , V_9 ) ;
if ( F_12 ( V_8 ) ) {
V_135 = F_13 ( V_8 ) ;
goto free;
}
}
F_65 (plane, dev) {
struct V_3 * V_4 ;
V_4 = F_70 ( V_2 , V_6 ) ;
if ( F_12 ( V_4 ) ) {
V_135 = F_13 ( V_4 ) ;
goto free;
}
}
F_8 (conn, dev) {
struct V_16 * V_17 ;
V_17 = F_15 ( V_2 , V_134 ) ;
if ( F_12 ( V_17 ) ) {
V_135 = F_13 ( V_17 ) ;
goto free;
}
}
V_2 -> V_116 = NULL ;
free:
if ( V_135 < 0 ) {
F_59 ( V_2 ) ;
V_2 = F_90 ( V_135 ) ;
}
return V_2 ;
}
void
F_130 ( struct V_14 * V_15 ,
struct V_16 * V_2 )
{
}
void F_131 ( struct V_14 * V_15 ,
struct V_16 * V_2 )
{
F_130 ( V_15 , V_2 ) ;
F_110 ( V_2 ) ;
}
