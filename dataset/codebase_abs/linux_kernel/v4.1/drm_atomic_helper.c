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
static struct V_12 *
F_4 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_14 -> V_19 ;
struct V_20 * V_21 ;
F_3 ( ! F_5 ( & V_18 -> V_22 ) ) ;
F_6 (connector, &config->connector_list, head) {
if ( V_21 -> V_2 -> V_23 != V_16 )
continue;
return V_21 -> V_2 -> V_9 ;
}
return NULL ;
}
static int
F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_12 * V_24 )
{
struct V_17 * V_18 = & V_2 -> V_14 -> V_19 ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_25 * V_26 ;
int V_27 ;
F_3 ( ! F_5 ( & V_18 -> V_22 ) ) ;
F_8 ( L_1 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ,
V_24 -> V_28 . V_29 ) ;
V_8 = F_9 ( V_2 , V_24 ) ;
if ( F_10 ( V_8 ) )
return F_11 ( V_8 ) ;
V_8 -> V_31 = true ;
F_6 (connector, &config->connector_list, head) {
if ( V_21 -> V_2 -> V_23 != V_16 )
continue;
F_8 ( L_2 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ) ;
V_26 = F_12 ( V_2 ,
V_21 ) ;
if ( F_10 ( V_26 ) )
return F_11 ( V_26 ) ;
V_27 = F_13 ( V_26 , NULL ) ;
if ( V_27 )
return V_27 ;
V_26 -> V_23 = NULL ;
}
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , int V_32 )
{
const struct V_33 * V_34 ;
struct V_15 * V_35 ;
struct V_12 * V_24 ;
struct V_20 * V_21 ;
struct V_25 * V_26 ;
struct V_7 * V_8 ;
int V_36 , V_27 ;
V_21 = V_2 -> V_37 [ V_32 ] ;
V_26 = V_2 -> V_38 [ V_32 ] ;
if ( ! V_21 )
return 0 ;
F_8 ( L_3 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ) ;
if ( V_21 -> V_2 -> V_9 != V_26 -> V_9 ) {
if ( V_21 -> V_2 -> V_9 ) {
V_36 = F_2 ( V_21 -> V_2 -> V_9 ) ;
V_8 = V_2 -> V_10 [ V_36 ] ;
V_8 -> V_31 = true ;
}
if ( V_26 -> V_9 ) {
V_36 = F_2 ( V_26 -> V_9 ) ;
V_8 = V_2 -> V_10 [ V_36 ] ;
V_8 -> V_31 = true ;
}
}
if ( ! V_26 -> V_9 ) {
F_8 ( L_4 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ) ;
V_26 -> V_23 = NULL ;
return 0 ;
}
V_34 = V_21 -> V_39 ;
V_35 = V_34 -> V_23 ( V_21 ) ;
if ( ! V_35 ) {
F_8 ( L_5 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ) ;
return - V_40 ;
}
if ( V_35 == V_26 -> V_23 ) {
F_8 ( L_6 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ,
V_35 -> V_28 . V_29 ,
V_35 -> V_30 ,
V_26 -> V_9 -> V_28 . V_29 ) ;
return 0 ;
}
V_24 = F_4 ( V_2 -> V_14 ,
V_35 ) ;
if ( V_24 ) {
V_27 = F_7 ( V_2 , V_35 , V_24 ) ;
if ( V_27 ) {
F_8 ( L_7 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ) ;
return V_27 ;
}
}
V_26 -> V_23 = V_35 ;
V_36 = F_2 ( V_26 -> V_9 ) ;
V_8 = V_2 -> V_10 [ V_36 ] ;
V_8 -> V_31 = true ;
F_8 ( L_8 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ,
V_35 -> V_28 . V_29 ,
V_35 -> V_30 ,
V_26 -> V_9 -> V_28 . V_29 ) ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 )
{
struct V_12 * V_9 ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_25 * V_41 ;
int V_42 ;
bool V_27 ;
F_16 (state, crtc, crtc_state, i) {
if ( ! V_8 -> V_31 )
continue;
F_17 ( & V_8 -> V_43 , & V_8 -> V_44 ) ;
}
F_18 (state, connector, conn_state, i) {
const struct V_45 * V_34 ;
struct V_15 * V_16 ;
F_3 ( ! ! V_41 -> V_23 != ! ! V_41 -> V_9 ) ;
if ( ! V_41 -> V_9 || ! V_41 -> V_23 )
continue;
V_8 =
V_2 -> V_10 [ F_2 ( V_41 -> V_9 ) ] ;
V_16 = V_41 -> V_23 ;
V_34 = V_16 -> V_39 ;
if ( V_16 -> V_46 && V_16 -> V_46 -> V_34 -> F_15 ) {
V_27 = V_16 -> V_46 -> V_34 -> F_15 (
V_16 -> V_46 , & V_8 -> V_44 ,
& V_8 -> V_43 ) ;
if ( ! V_27 ) {
F_8 ( L_9 ) ;
return - V_40 ;
}
}
if ( V_34 -> V_47 ) {
V_27 = V_34 -> V_47 ( V_16 , V_8 ,
V_41 ) ;
if ( V_27 ) {
F_8 ( L_10 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
return V_27 ;
}
} else {
V_27 = V_34 -> F_15 ( V_16 , & V_8 -> V_44 ,
& V_8 -> V_43 ) ;
if ( ! V_27 ) {
F_8 ( L_11 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
return - V_40 ;
}
}
}
F_16 (state, crtc, crtc_state, i) {
const struct V_48 * V_34 ;
if ( ! V_8 -> V_31 )
continue;
V_34 = V_9 -> V_39 ;
V_27 = V_34 -> F_15 ( V_9 , & V_8 -> V_44 ,
& V_8 -> V_43 ) ;
if ( ! V_27 ) {
F_8 ( L_12 ,
V_9 -> V_28 . V_29 ) ;
return - V_40 ;
}
}
return 0 ;
}
static bool
F_19 ( struct V_7 * V_2 )
{
return V_2 -> V_31 || V_2 -> V_49 ;
}
int
F_20 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_12 * V_9 ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_25 * V_26 ;
int V_42 , V_27 ;
F_16 (state, crtc, crtc_state, i) {
if ( ! F_21 ( & V_9 -> V_2 -> V_44 , & V_8 -> V_44 ) ) {
F_8 ( L_13 ,
V_9 -> V_28 . V_29 ) ;
V_8 -> V_31 = true ;
}
if ( V_9 -> V_2 -> V_50 != V_8 -> V_50 ) {
F_8 ( L_14 ,
V_9 -> V_28 . V_29 ) ;
V_8 -> V_31 = true ;
}
}
F_18 (state, connector, connector_state, i) {
V_27 = F_14 ( V_2 , V_42 ) ;
if ( V_27 )
return V_27 ;
}
F_16 (state, crtc, crtc_state, i) {
int V_51 ;
if ( V_9 -> V_2 -> V_52 != V_8 -> V_52 ) {
F_8 ( L_15 ,
V_9 -> V_28 . V_29 ) ;
V_8 -> V_49 = true ;
}
if ( ! F_19 ( V_8 ) )
continue;
F_8 ( L_16 ,
V_9 -> V_28 . V_29 ,
V_8 -> V_50 ? 'y' : 'n' ,
V_8 -> V_52 ? 'y' : 'n' ) ;
V_27 = F_22 ( V_2 , V_9 ) ;
if ( V_27 != 0 )
return V_27 ;
V_51 = F_23 ( V_2 ,
V_9 ) ;
if ( V_8 -> V_50 != ! ! V_51 ) {
F_8 ( L_17 ,
V_9 -> V_28 . V_29 ) ;
return - V_40 ;
}
}
return F_15 ( V_2 ) ;
}
int
F_24 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_12 * V_9 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_42 , V_27 = 0 ;
F_25 (state, plane, plane_state, i) {
const struct V_53 * V_34 ;
V_34 = V_6 -> V_39 ;
F_1 ( V_2 , V_4 , V_6 ) ;
if ( ! V_34 || ! V_34 -> V_47 )
continue;
V_27 = V_34 -> V_47 ( V_6 , V_4 ) ;
if ( V_27 ) {
F_8 ( L_18 ,
V_6 -> V_28 . V_29 ) ;
return V_27 ;
}
}
F_16 (state, crtc, crtc_state, i) {
const struct V_48 * V_34 ;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_47 )
continue;
V_27 = V_34 -> V_47 ( V_9 , V_2 -> V_10 [ V_42 ] ) ;
if ( V_27 ) {
F_8 ( L_19 ,
V_9 -> V_28 . V_29 ) ;
return V_27 ;
}
}
return V_27 ;
}
int F_26 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_27 ;
V_27 = F_20 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_24 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
return V_27 ;
}
static void
F_27 ( struct V_13 * V_14 , struct V_1 * V_54 )
{
struct V_20 * V_21 ;
struct V_25 * V_55 ;
struct V_12 * V_9 ;
struct V_7 * V_56 ;
int V_42 ;
F_18 (old_state, connector, old_conn_state, i) {
const struct V_45 * V_34 ;
struct V_15 * V_16 ;
struct V_7 * V_56 ;
if ( ! V_55 -> V_9 )
continue;
V_56 = V_54 -> V_10 [ F_2 ( V_55 -> V_9 ) ] ;
if ( ! V_56 -> V_52 ||
! F_19 ( V_55 -> V_9 -> V_2 ) )
continue;
V_16 = V_55 -> V_23 ;
if ( F_3 ( ! V_16 ) )
continue;
V_34 = V_16 -> V_39 ;
F_8 ( L_20 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
if ( V_16 -> V_46 )
V_16 -> V_46 -> V_34 -> V_57 ( V_16 -> V_46 ) ;
if ( V_21 -> V_2 -> V_9 && V_34 -> V_58 )
V_34 -> V_58 ( V_16 ) ;
else if ( V_34 -> V_57 )
V_34 -> V_57 ( V_16 ) ;
else
V_34 -> V_59 ( V_16 , V_60 ) ;
if ( V_16 -> V_46 )
V_16 -> V_46 -> V_34 -> V_61 ( V_16 -> V_46 ) ;
}
F_16 (old_state, crtc, old_crtc_state, i) {
const struct V_48 * V_34 ;
if ( ! F_19 ( V_9 -> V_2 ) )
continue;
if ( ! V_56 -> V_52 )
continue;
V_34 = V_9 -> V_39 ;
F_8 ( L_21 ,
V_9 -> V_28 . V_29 ) ;
if ( V_9 -> V_2 -> V_50 && V_34 -> V_58 )
V_34 -> V_58 ( V_9 ) ;
else if ( V_34 -> V_57 )
V_34 -> V_57 ( V_9 ) ;
else
V_34 -> V_59 ( V_9 , V_60 ) ;
}
}
static void
F_28 ( struct V_13 * V_14 , struct V_1 * V_54 )
{
struct V_20 * V_21 ;
struct V_25 * V_55 ;
struct V_12 * V_9 ;
struct V_7 * V_56 ;
int V_42 ;
F_18 (old_state, connector, old_conn_state, i) {
if ( ! V_21 -> V_16 )
continue;
F_3 ( ! V_21 -> V_16 -> V_9 ) ;
V_21 -> V_16 -> V_9 = NULL ;
V_21 -> V_16 = NULL ;
}
F_18 (old_state, connector, old_conn_state, i) {
if ( ! V_21 -> V_2 -> V_9 )
continue;
if ( F_3 ( ! V_21 -> V_2 -> V_23 ) )
continue;
V_21 -> V_16 = V_21 -> V_2 -> V_23 ;
V_21 -> V_16 -> V_9 = V_21 -> V_2 -> V_9 ;
}
F_16 (old_state, crtc, old_crtc_state, i) {
V_9 -> V_44 = V_9 -> V_2 -> V_44 ;
V_9 -> V_62 = V_9 -> V_2 -> V_50 ;
V_9 -> V_63 = V_9 -> V_64 -> V_2 -> V_65 >> 16 ;
V_9 -> V_66 = V_9 -> V_64 -> V_2 -> V_67 >> 16 ;
}
}
static void
F_29 ( struct V_13 * V_14 , struct V_1 * V_54 )
{
struct V_12 * V_9 ;
struct V_7 * V_56 ;
struct V_20 * V_21 ;
struct V_25 * V_55 ;
int V_42 ;
F_16 (old_state, crtc, old_crtc_state, i) {
const struct V_48 * V_34 ;
if ( ! V_9 -> V_2 -> V_31 )
continue;
V_34 = V_9 -> V_39 ;
if ( V_9 -> V_2 -> V_50 && V_34 -> V_68 ) {
F_8 ( L_22 ,
V_9 -> V_28 . V_29 ) ;
V_34 -> V_68 ( V_9 ) ;
}
}
F_18 (old_state, connector, old_conn_state, i) {
const struct V_45 * V_34 ;
struct V_7 * V_69 ;
struct V_15 * V_16 ;
struct V_70 * V_44 , * V_43 ;
if ( ! V_21 -> V_2 -> V_23 )
continue;
V_16 = V_21 -> V_2 -> V_23 ;
V_34 = V_16 -> V_39 ;
V_69 = V_21 -> V_2 -> V_9 -> V_2 ;
V_44 = & V_69 -> V_44 ;
V_43 = & V_69 -> V_43 ;
if ( ! V_69 -> V_31 )
continue;
F_8 ( L_23 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
if ( V_34 -> V_71 )
V_34 -> V_71 ( V_16 , V_44 , V_43 ) ;
if ( V_16 -> V_46 && V_16 -> V_46 -> V_34 -> V_71 )
V_16 -> V_46 -> V_34 -> V_71 ( V_16 -> V_46 ,
V_44 , V_43 ) ;
}
}
void F_30 ( struct V_13 * V_14 ,
struct V_1 * V_54 )
{
F_27 ( V_14 , V_54 ) ;
F_28 ( V_14 , V_54 ) ;
F_29 ( V_14 , V_54 ) ;
}
void F_31 ( struct V_13 * V_14 ,
struct V_1 * V_54 )
{
struct V_12 * V_9 ;
struct V_7 * V_56 ;
struct V_20 * V_21 ;
struct V_25 * V_55 ;
int V_42 ;
F_16 (old_state, crtc, old_crtc_state, i) {
const struct V_48 * V_34 ;
if ( ! F_19 ( V_9 -> V_2 ) )
continue;
if ( ! V_9 -> V_2 -> V_52 )
continue;
V_34 = V_9 -> V_39 ;
if ( V_9 -> V_2 -> V_50 ) {
F_8 ( L_24 ,
V_9 -> V_28 . V_29 ) ;
if ( V_34 -> V_50 )
V_34 -> V_50 ( V_9 ) ;
else
V_34 -> V_72 ( V_9 ) ;
}
}
F_18 (old_state, connector, old_conn_state, i) {
const struct V_45 * V_34 ;
struct V_15 * V_16 ;
if ( ! V_21 -> V_2 -> V_23 )
continue;
if ( ! V_21 -> V_2 -> V_9 -> V_2 -> V_52 ||
! F_19 ( V_21 -> V_2 -> V_9 -> V_2 ) )
continue;
V_16 = V_21 -> V_2 -> V_23 ;
V_34 = V_16 -> V_39 ;
F_8 ( L_25 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
if ( V_16 -> V_46 )
V_16 -> V_46 -> V_34 -> V_73 ( V_16 -> V_46 ) ;
if ( V_34 -> V_50 )
V_34 -> V_50 ( V_16 ) ;
else
V_34 -> V_72 ( V_16 ) ;
if ( V_16 -> V_46 )
V_16 -> V_46 -> V_34 -> V_50 ( V_16 -> V_46 ) ;
}
}
static void F_32 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_42 ;
F_25 (state, plane, plane_state, i) {
if ( ! V_6 -> V_2 -> V_74 )
continue;
F_3 ( ! V_6 -> V_2 -> V_75 ) ;
F_33 ( V_6 -> V_2 -> V_74 , false ) ;
F_34 ( V_6 -> V_2 -> V_74 ) ;
V_6 -> V_2 -> V_74 = NULL ;
}
}
static bool F_35 ( struct V_13 * V_14 ,
struct V_1 * V_54 ,
struct V_12 * V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_76 ;
int V_42 ;
F_25 (old_state, plane, old_plane_state, i) {
if ( V_6 -> V_2 -> V_9 != V_9 &&
V_76 -> V_9 != V_9 )
continue;
if ( V_6 -> V_2 -> V_75 != V_76 -> V_75 )
return true ;
}
return false ;
}
void
F_36 ( struct V_13 * V_14 ,
struct V_1 * V_54 )
{
struct V_12 * V_9 ;
struct V_7 * V_56 ;
int V_42 , V_27 ;
F_16 (old_state, crtc, old_crtc_state, i) {
V_56 -> V_50 = false ;
if ( ! V_9 -> V_2 -> V_50 )
continue;
if ( V_54 -> V_77 )
continue;
if ( ! F_35 ( V_14 , V_54 , V_9 ) )
continue;
V_27 = F_37 ( V_9 ) ;
if ( V_27 != 0 )
continue;
V_56 -> V_50 = true ;
V_56 -> V_78 = F_38 ( V_14 , V_42 ) ;
}
F_16 (old_state, crtc, old_crtc_state, i) {
if ( ! V_56 -> V_50 )
continue;
V_27 = F_39 ( V_14 -> V_79 [ V_42 ] . V_80 ,
V_56 -> V_78 !=
F_38 ( V_14 , V_42 ) ,
F_40 ( 50 ) ) ;
F_41 ( V_9 ) ;
}
}
int F_42 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
bool V_81 )
{
int V_27 ;
if ( V_81 )
return - V_82 ;
V_27 = F_43 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
F_44 ( V_14 , V_2 ) ;
F_32 ( V_14 , V_2 ) ;
F_30 ( V_14 , V_2 ) ;
F_45 ( V_14 , V_2 ) ;
F_31 ( V_14 , V_2 ) ;
F_36 ( V_14 , V_2 ) ;
F_46 ( V_14 , V_2 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
int F_43 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_83 = V_14 -> V_19 . V_84 ;
int V_27 , V_42 ;
for ( V_42 = 0 ; V_42 < V_83 ; V_42 ++ ) {
const struct V_53 * V_34 ;
struct V_5 * V_6 = V_2 -> V_85 [ V_42 ] ;
struct V_3 * V_4 = V_2 -> V_86 [ V_42 ] ;
struct V_87 * V_75 ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
V_75 = V_4 -> V_75 ;
if ( V_75 && V_34 -> V_88 ) {
V_27 = V_34 -> V_88 ( V_6 , V_75 , V_4 ) ;
if ( V_27 )
goto V_89;
}
}
return 0 ;
V_89:
for ( V_42 -- ; V_42 >= 0 ; V_42 -- ) {
const struct V_53 * V_34 ;
struct V_5 * V_6 = V_2 -> V_85 [ V_42 ] ;
struct V_3 * V_4 = V_2 -> V_86 [ V_42 ] ;
struct V_87 * V_75 ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
V_75 = V_2 -> V_86 [ V_42 ] -> V_75 ;
if ( V_75 && V_34 -> V_90 )
V_34 -> V_90 ( V_6 , V_75 , V_4 ) ;
}
return V_27 ;
}
void F_45 ( struct V_13 * V_14 ,
struct V_1 * V_54 )
{
struct V_12 * V_9 ;
struct V_7 * V_56 ;
struct V_5 * V_6 ;
struct V_3 * V_76 ;
int V_42 ;
F_16 (old_state, crtc, old_crtc_state, i) {
const struct V_48 * V_34 ;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_91 )
continue;
V_34 -> V_91 ( V_9 ) ;
}
F_25 (old_state, plane, old_plane_state, i) {
const struct V_53 * V_34 ;
V_34 = V_6 -> V_39 ;
if ( ! V_34 )
continue;
V_76 = V_54 -> V_86 [ V_42 ] ;
if ( F_48 ( V_6 , V_76 ) &&
V_34 -> V_92 )
V_34 -> V_92 ( V_6 , V_76 ) ;
else
V_34 -> V_93 ( V_6 , V_76 ) ;
}
F_16 (old_state, crtc, old_crtc_state, i) {
const struct V_48 * V_34 ;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_94 )
continue;
V_34 -> V_94 ( V_9 ) ;
}
}
void F_46 ( struct V_13 * V_14 ,
struct V_1 * V_54 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_42 ;
F_25 (old_state, plane, plane_state, i) {
const struct V_53 * V_34 ;
struct V_87 * V_95 ;
V_34 = V_6 -> V_39 ;
V_95 = V_4 -> V_75 ;
if ( V_95 && V_34 -> V_90 )
V_34 -> V_90 ( V_6 , V_95 , V_4 ) ;
}
}
void F_44 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_14 -> V_19 . V_96 ; V_42 ++ ) {
struct V_20 * V_21 = V_2 -> V_37 [ V_42 ] ;
if ( ! V_21 )
continue;
V_21 -> V_2 -> V_2 = V_2 ;
F_49 ( V_2 -> V_38 [ V_42 ] , V_21 -> V_2 ) ;
V_21 -> V_2 -> V_2 = NULL ;
}
for ( V_42 = 0 ; V_42 < V_14 -> V_19 . V_97 ; V_42 ++ ) {
struct V_12 * V_9 = V_2 -> V_98 [ V_42 ] ;
if ( ! V_9 )
continue;
V_9 -> V_2 -> V_2 = V_2 ;
F_49 ( V_2 -> V_10 [ V_42 ] , V_9 -> V_2 ) ;
V_9 -> V_2 -> V_2 = NULL ;
}
for ( V_42 = 0 ; V_42 < V_14 -> V_19 . V_84 ; V_42 ++ ) {
struct V_5 * V_6 = V_2 -> V_85 [ V_42 ] ;
if ( ! V_6 )
continue;
V_6 -> V_2 -> V_2 = V_2 ;
F_49 ( V_2 -> V_86 [ V_42 ] , V_6 -> V_2 ) ;
V_6 -> V_2 -> V_2 = NULL ;
}
}
int F_50 ( struct V_5 * V_6 ,
struct V_12 * V_9 ,
struct V_87 * V_75 ,
int V_99 , int V_100 ,
unsigned int V_101 , unsigned int V_102 ,
T_1 V_65 , T_1 V_67 ,
T_1 V_103 , T_1 V_104 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
V_2 = F_51 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_105 ;
V_2 -> V_106 = F_52 ( V_9 ) ;
V_107:
V_4 = F_53 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_89;
}
V_27 = F_54 ( V_4 , V_9 ) ;
if ( V_27 != 0 )
goto V_89;
F_55 ( V_4 , V_75 ) ;
V_4 -> V_99 = V_99 ;
V_4 -> V_100 = V_100 ;
V_4 -> V_102 = V_102 ;
V_4 -> V_101 = V_101 ;
V_4 -> V_65 = V_65 ;
V_4 -> V_67 = V_67 ;
V_4 -> V_104 = V_104 ;
V_4 -> V_103 = V_103 ;
V_27 = F_56 ( V_2 ) ;
if ( V_27 != 0 )
goto V_89;
if ( V_6 == V_9 -> V_108 )
V_2 -> V_77 = true ;
return 0 ;
V_89:
if ( V_27 == - V_109 )
goto V_110;
F_47 ( V_2 ) ;
return V_27 ;
V_110:
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
V_6 -> V_95 = V_6 -> V_75 ;
goto V_107;
}
int F_59 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
if ( ! V_6 -> V_9 )
return 0 ;
V_2 = F_51 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_105 ;
V_2 -> V_106 = F_52 ( V_6 -> V_9 ) ;
V_107:
V_4 = F_53 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_89;
}
V_27 = F_54 ( V_4 , NULL ) ;
if ( V_27 != 0 )
goto V_89;
F_55 ( V_4 , NULL ) ;
V_4 -> V_99 = 0 ;
V_4 -> V_100 = 0 ;
V_4 -> V_102 = 0 ;
V_4 -> V_101 = 0 ;
V_4 -> V_65 = 0 ;
V_4 -> V_67 = 0 ;
V_4 -> V_104 = 0 ;
V_4 -> V_103 = 0 ;
if ( V_6 == V_6 -> V_9 -> V_108 )
V_2 -> V_77 = true ;
V_27 = F_56 ( V_2 ) ;
if ( V_27 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_27 == - V_109 )
goto V_110;
F_47 ( V_2 ) ;
return V_27 ;
V_110:
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
V_6 -> V_95 = V_6 -> V_75 ;
goto V_107;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
struct V_13 * V_14 = V_112 -> V_9 -> V_14 ;
struct V_12 * V_9 ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_25 * V_41 ;
int V_27 , V_42 , V_113 ;
V_27 = F_61 ( & V_14 -> V_19 . V_22 ,
V_2 -> V_106 ) ;
if ( V_27 )
return V_27 ;
for ( V_42 = 0 ; V_42 < V_112 -> V_51 ; V_42 ++ ) {
V_41 = F_12 ( V_2 ,
V_112 -> V_37 [ V_42 ] ) ;
if ( F_10 ( V_41 ) )
return F_11 ( V_41 ) ;
}
F_16 (state, crtc, crtc_state, i) {
V_27 = F_22 ( V_2 , V_9 ) ;
if ( V_27 )
return V_27 ;
}
F_18 (state, connector, conn_state, i) {
if ( V_41 -> V_9 == V_112 -> V_9 ) {
V_27 = F_13 ( V_41 ,
NULL ) ;
if ( V_27 )
return V_27 ;
}
for ( V_113 = 0 ; V_113 < V_112 -> V_51 ; V_113 ++ ) {
if ( V_112 -> V_37 [ V_113 ] == V_21 ) {
V_27 = F_13 ( V_41 ,
V_112 -> V_9 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
}
F_16 (state, crtc, crtc_state, i) {
if ( V_9 == V_112 -> V_9 )
continue;
V_8 -> V_50 =
F_23 ( V_2 , V_9 ) ;
}
return 0 ;
}
int F_62 ( struct V_111 * V_112 )
{
struct V_1 * V_2 ;
struct V_12 * V_9 = V_112 -> V_9 ;
struct V_7 * V_8 ;
struct V_3 * V_114 ;
int V_27 = 0 ;
V_2 = F_51 ( V_9 -> V_14 ) ;
if ( ! V_2 )
return - V_105 ;
V_2 -> V_106 = F_52 ( V_9 ) ;
V_107:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_89;
}
V_114 = F_53 ( V_2 , V_9 -> V_64 ) ;
if ( F_10 ( V_114 ) ) {
V_27 = F_11 ( V_114 ) ;
goto V_89;
}
if ( ! V_112 -> V_44 ) {
F_3 ( V_112 -> V_75 ) ;
F_3 ( V_112 -> V_51 ) ;
V_8 -> V_50 = false ;
V_8 -> V_52 = false ;
V_27 = F_54 ( V_114 , NULL ) ;
if ( V_27 != 0 )
goto V_89;
F_55 ( V_114 , NULL ) ;
goto V_72;
}
F_3 ( ! V_112 -> V_75 ) ;
F_3 ( ! V_112 -> V_51 ) ;
V_8 -> V_50 = true ;
V_8 -> V_52 = true ;
F_17 ( & V_8 -> V_44 , V_112 -> V_44 ) ;
V_27 = F_54 ( V_114 , V_9 ) ;
if ( V_27 != 0 )
goto V_89;
F_55 ( V_114 , V_112 -> V_75 ) ;
V_114 -> V_99 = 0 ;
V_114 -> V_100 = 0 ;
V_114 -> V_102 = V_112 -> V_44 -> V_115 ;
V_114 -> V_101 = V_112 -> V_44 -> V_116 ;
V_114 -> V_65 = V_112 -> V_63 << 16 ;
V_114 -> V_67 = V_112 -> V_66 << 16 ;
V_114 -> V_104 = V_112 -> V_44 -> V_115 << 16 ;
V_114 -> V_103 = V_112 -> V_44 -> V_116 << 16 ;
V_72:
V_27 = F_60 ( V_2 , V_112 ) ;
if ( V_27 )
goto V_89;
V_27 = F_56 ( V_2 ) ;
if ( V_27 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_27 == - V_109 )
goto V_110;
F_47 ( V_2 ) ;
return V_27 ;
V_110:
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
V_9 -> V_64 -> V_95 = V_9 -> V_64 -> V_75 ;
goto V_107;
}
int
F_63 ( struct V_12 * V_9 ,
struct V_117 * V_118 ,
T_2 V_119 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_27 = 0 ;
V_2 = F_51 ( V_9 -> V_14 ) ;
if ( ! V_2 )
return - V_105 ;
V_2 -> V_106 = V_9 -> V_14 -> V_19 . V_106 ;
V_107:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_89;
}
V_27 = F_64 ( V_9 , V_8 ,
V_118 , V_119 ) ;
if ( V_27 )
goto V_89;
V_27 = F_56 ( V_2 ) ;
if ( V_27 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_27 == - V_109 )
goto V_110;
F_47 ( V_2 ) ;
return V_27 ;
V_110:
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
goto V_107;
}
int
F_65 ( struct V_5 * V_6 ,
struct V_117 * V_118 ,
T_2 V_119 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
V_2 = F_51 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_105 ;
V_2 -> V_106 = V_6 -> V_14 -> V_19 . V_106 ;
V_107:
V_4 = F_53 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_89;
}
V_27 = F_66 ( V_6 , V_4 ,
V_118 , V_119 ) ;
if ( V_27 )
goto V_89;
V_27 = F_56 ( V_2 ) ;
if ( V_27 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_27 == - V_109 )
goto V_110;
F_47 ( V_2 ) ;
return V_27 ;
V_110:
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
goto V_107;
}
int
F_67 ( struct V_20 * V_21 ,
struct V_117 * V_118 ,
T_2 V_119 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
int V_27 = 0 ;
V_2 = F_51 ( V_21 -> V_14 ) ;
if ( ! V_2 )
return - V_105 ;
V_2 -> V_106 = V_21 -> V_14 -> V_19 . V_106 ;
V_107:
V_26 = F_12 ( V_2 , V_21 ) ;
if ( F_10 ( V_26 ) ) {
V_27 = F_11 ( V_26 ) ;
goto V_89;
}
V_27 = F_68 ( V_21 , V_26 ,
V_118 , V_119 ) ;
if ( V_27 )
goto V_89;
V_27 = F_56 ( V_2 ) ;
if ( V_27 != 0 )
goto V_89;
return 0 ;
V_89:
if ( V_27 == - V_109 )
goto V_110;
F_47 ( V_2 ) ;
return V_27 ;
V_110:
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
goto V_107;
}
int F_69 ( struct V_12 * V_9 ,
struct V_87 * V_75 ,
struct V_120 * V_121 ,
T_1 V_122 )
{
struct V_5 * V_6 = V_9 -> V_64 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_7 * V_8 ;
int V_27 = 0 ;
if ( V_122 & V_123 )
return - V_40 ;
V_2 = F_51 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_105 ;
V_2 -> V_106 = F_52 ( V_9 ) ;
V_107:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_89;
}
V_8 -> V_121 = V_121 ;
V_4 = F_53 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_89;
}
V_27 = F_54 ( V_4 , V_9 ) ;
if ( V_27 != 0 )
goto V_89;
F_55 ( V_4 , V_75 ) ;
V_27 = F_70 ( V_2 ) ;
if ( V_27 != 0 )
goto V_89;
V_6 -> V_75 = V_6 -> V_2 -> V_75 ;
return 0 ;
V_89:
if ( V_27 == - V_109 )
goto V_110;
F_47 ( V_2 ) ;
return V_27 ;
V_110:
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
V_6 -> V_95 = V_6 -> V_75 ;
goto V_107;
}
void F_71 ( struct V_20 * V_21 ,
int V_44 )
{
struct V_17 * V_18 = & V_21 -> V_14 -> V_19 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_12 * V_9 ;
struct V_20 * V_124 ;
int V_27 ;
bool V_52 = false ;
if ( V_44 != V_125 )
V_44 = V_60 ;
V_21 -> V_59 = V_44 ;
V_9 = V_21 -> V_2 -> V_9 ;
if ( ! V_9 )
return;
V_2 = F_51 ( V_21 -> V_14 ) ;
if ( ! V_2 )
return;
V_2 -> V_106 = F_52 ( V_9 ) ;
V_107:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) )
return;
F_3 ( ! F_5 ( & V_18 -> V_22 ) ) ;
F_6 (tmp_connector, &config->connector_list, head) {
if ( V_124 -> V_2 -> V_9 != V_9 )
continue;
if ( V_124 -> V_59 == V_125 ) {
V_52 = true ;
break;
}
}
V_8 -> V_52 = V_52 ;
V_27 = F_56 ( V_2 ) ;
if ( V_27 != 0 )
goto V_89;
return;
V_89:
if ( V_27 == - V_109 )
goto V_110;
F_47 ( V_2 ) ;
F_72 ( 1 , L_26 , V_27 ) ;
return;
V_110:
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
goto V_107;
}
void F_73 ( struct V_12 * V_9 )
{
F_74 ( V_9 -> V_2 ) ;
V_9 -> V_2 = F_75 ( sizeof( * V_9 -> V_2 ) , V_126 ) ;
if ( V_9 -> V_2 )
V_9 -> V_2 -> V_9 = V_9 ;
}
void F_76 ( struct V_12 * V_9 ,
struct V_7 * V_2 )
{
memcpy ( V_2 , V_9 -> V_2 , sizeof( * V_2 ) ) ;
V_2 -> V_31 = false ;
V_2 -> V_49 = false ;
V_2 -> V_11 = false ;
V_2 -> V_121 = NULL ;
}
struct V_7 *
F_77 ( struct V_12 * V_9 )
{
struct V_7 * V_2 ;
if ( F_3 ( ! V_9 -> V_2 ) )
return NULL ;
V_2 = F_78 ( sizeof( * V_2 ) , V_126 ) ;
if ( V_2 )
F_76 ( V_9 , V_2 ) ;
return V_2 ;
}
void F_79 ( struct V_12 * V_9 ,
struct V_7 * V_2 )
{
}
void F_80 ( struct V_12 * V_9 ,
struct V_7 * V_2 )
{
F_79 ( V_9 , V_2 ) ;
F_74 ( V_2 ) ;
}
void F_81 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 && V_6 -> V_2 -> V_75 )
F_82 ( V_6 -> V_2 -> V_75 ) ;
F_74 ( V_6 -> V_2 ) ;
V_6 -> V_2 = F_75 ( sizeof( * V_6 -> V_2 ) , V_126 ) ;
if ( V_6 -> V_2 )
V_6 -> V_2 -> V_6 = V_6 ;
}
void F_83 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
memcpy ( V_2 , V_6 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_75 )
F_84 ( V_2 -> V_75 ) ;
}
struct V_3 *
F_85 ( struct V_5 * V_6 )
{
struct V_3 * V_2 ;
if ( F_3 ( ! V_6 -> V_2 ) )
return NULL ;
V_2 = F_78 ( sizeof( * V_2 ) , V_126 ) ;
if ( V_2 )
F_83 ( V_6 , V_2 ) ;
return V_2 ;
}
void F_86 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
if ( V_2 -> V_75 )
F_82 ( V_2 -> V_75 ) ;
}
void F_87 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
F_86 ( V_6 , V_2 ) ;
F_74 ( V_2 ) ;
}
void F_88 ( struct V_20 * V_21 )
{
F_74 ( V_21 -> V_2 ) ;
V_21 -> V_2 = F_75 ( sizeof( * V_21 -> V_2 ) , V_126 ) ;
if ( V_21 -> V_2 )
V_21 -> V_2 -> V_21 = V_21 ;
}
void
F_89 ( struct V_20 * V_21 ,
struct V_25 * V_2 )
{
memcpy ( V_2 , V_21 -> V_2 , sizeof( * V_2 ) ) ;
}
struct V_25 *
F_90 ( struct V_20 * V_21 )
{
struct V_25 * V_2 ;
if ( F_3 ( ! V_21 -> V_2 ) )
return NULL ;
V_2 = F_78 ( sizeof( * V_2 ) , V_126 ) ;
if ( V_2 )
F_89 ( V_21 , V_2 ) ;
return V_2 ;
}
void
F_91 ( struct V_20 * V_21 ,
struct V_25 * V_2 )
{
}
void F_92 ( struct V_20 * V_21 ,
struct V_25 * V_2 )
{
F_91 ( V_21 , V_2 ) ;
F_74 ( V_2 ) ;
}
