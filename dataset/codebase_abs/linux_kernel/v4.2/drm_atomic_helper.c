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
if ( V_34 -> V_40 )
V_35 = V_34 -> V_40 ( V_21 ,
V_26 ) ;
else
V_35 = V_34 -> V_23 ( V_21 ) ;
if ( ! V_35 ) {
F_8 ( L_5 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ) ;
return - V_41 ;
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
if ( F_3 ( ! V_26 -> V_9 ) )
return - V_41 ;
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
struct V_25 * V_42 ;
int V_43 ;
bool V_27 ;
F_16 (state, crtc, crtc_state, i) {
if ( ! V_8 -> V_31 )
continue;
F_17 ( & V_8 -> V_44 , & V_8 -> V_45 ) ;
}
F_18 (state, connector, conn_state, i) {
const struct V_46 * V_34 ;
struct V_15 * V_16 ;
F_3 ( ! ! V_42 -> V_23 != ! ! V_42 -> V_9 ) ;
if ( ! V_42 -> V_9 || ! V_42 -> V_23 )
continue;
V_8 =
V_2 -> V_10 [ F_2 ( V_42 -> V_9 ) ] ;
V_16 = V_42 -> V_23 ;
V_34 = V_16 -> V_39 ;
if ( ! V_34 )
continue;
V_27 = F_19 ( V_16 -> V_47 , & V_8 -> V_45 ,
& V_8 -> V_44 ) ;
if ( ! V_27 ) {
F_8 ( L_9 ) ;
return - V_41 ;
}
if ( V_34 -> V_48 ) {
V_27 = V_34 -> V_48 ( V_16 , V_8 ,
V_42 ) ;
if ( V_27 ) {
F_8 ( L_10 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
return V_27 ;
}
} else {
V_27 = V_34 -> F_15 ( V_16 , & V_8 -> V_45 ,
& V_8 -> V_44 ) ;
if ( ! V_27 ) {
F_8 ( L_11 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
return - V_41 ;
}
}
}
F_16 (state, crtc, crtc_state, i) {
const struct V_49 * V_34 ;
if ( ! V_8 -> V_31 )
continue;
V_34 = V_9 -> V_39 ;
if ( ! V_34 -> F_15 )
continue;
V_27 = V_34 -> F_15 ( V_9 , & V_8 -> V_45 ,
& V_8 -> V_44 ) ;
if ( ! V_27 ) {
F_8 ( L_12 ,
V_9 -> V_28 . V_29 ) ;
return - V_41 ;
}
}
return 0 ;
}
int
F_20 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_12 * V_9 ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_25 * V_26 ;
int V_43 , V_27 ;
F_16 (state, crtc, crtc_state, i) {
if ( ! F_21 ( & V_9 -> V_2 -> V_45 , & V_8 -> V_45 ) ) {
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
V_27 = F_14 ( V_2 , V_43 ) ;
if ( V_27 )
return V_27 ;
}
F_16 (state, crtc, crtc_state, i) {
int V_51 ;
if ( V_9 -> V_2 -> V_52 != V_8 -> V_52 ) {
F_8 ( L_15 ,
V_9 -> V_28 . V_29 ) ;
V_8 -> V_53 = true ;
}
if ( ! F_22 ( V_8 ) )
continue;
F_8 ( L_16 ,
V_9 -> V_28 . V_29 ,
V_8 -> V_50 ? 'y' : 'n' ,
V_8 -> V_52 ? 'y' : 'n' ) ;
V_27 = F_23 ( V_2 , V_9 ) ;
if ( V_27 != 0 )
return V_27 ;
V_27 = F_24 ( V_2 , V_9 ) ;
if ( V_27 != 0 )
return V_27 ;
V_51 = F_25 ( V_2 ,
V_9 ) ;
if ( V_8 -> V_50 != ! ! V_51 ) {
F_8 ( L_17 ,
V_9 -> V_28 . V_29 ) ;
return - V_41 ;
}
}
return F_15 ( V_2 ) ;
}
int
F_26 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_12 * V_9 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_43 , V_27 = 0 ;
F_27 (state, plane, plane_state, i) {
const struct V_54 * V_34 ;
V_34 = V_6 -> V_39 ;
F_1 ( V_2 , V_4 , V_6 ) ;
if ( ! V_34 || ! V_34 -> V_48 )
continue;
V_27 = V_34 -> V_48 ( V_6 , V_4 ) ;
if ( V_27 ) {
F_8 ( L_18 ,
V_6 -> V_28 . V_29 ) ;
return V_27 ;
}
}
F_16 (state, crtc, crtc_state, i) {
const struct V_49 * V_34 ;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_48 )
continue;
V_27 = V_34 -> V_48 ( V_9 , V_2 -> V_10 [ V_43 ] ) ;
if ( V_27 ) {
F_8 ( L_19 ,
V_9 -> V_28 . V_29 ) ;
return V_27 ;
}
}
return V_27 ;
}
int F_28 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_27 ;
V_27 = F_20 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_26 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
return V_27 ;
}
static void
F_29 ( struct V_13 * V_14 , struct V_1 * V_55 )
{
struct V_20 * V_21 ;
struct V_25 * V_56 ;
struct V_12 * V_9 ;
struct V_7 * V_57 ;
int V_43 ;
F_18 (old_state, connector, old_conn_state, i) {
const struct V_46 * V_34 ;
struct V_15 * V_16 ;
struct V_7 * V_57 ;
if ( ! V_56 -> V_9 )
continue;
V_57 = V_55 -> V_10 [ F_2 ( V_56 -> V_9 ) ] ;
if ( ! V_57 -> V_52 ||
! F_22 ( V_56 -> V_9 -> V_2 ) )
continue;
V_16 = V_56 -> V_23 ;
if ( F_3 ( ! V_16 ) )
continue;
V_34 = V_16 -> V_39 ;
F_8 ( L_20 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
F_30 ( V_16 -> V_47 ) ;
if ( V_21 -> V_2 -> V_9 && V_34 -> V_58 )
V_34 -> V_58 ( V_16 ) ;
else if ( V_34 -> V_59 )
V_34 -> V_59 ( V_16 ) ;
else
V_34 -> V_60 ( V_16 , V_61 ) ;
F_31 ( V_16 -> V_47 ) ;
}
F_16 (old_state, crtc, old_crtc_state, i) {
const struct V_49 * V_34 ;
if ( ! F_22 ( V_9 -> V_2 ) )
continue;
if ( ! V_57 -> V_52 )
continue;
V_34 = V_9 -> V_39 ;
F_8 ( L_21 ,
V_9 -> V_28 . V_29 ) ;
if ( V_9 -> V_2 -> V_50 && V_34 -> V_58 )
V_34 -> V_58 ( V_9 ) ;
else if ( V_34 -> V_59 )
V_34 -> V_59 ( V_9 ) ;
else
V_34 -> V_60 ( V_9 , V_61 ) ;
}
}
void
F_32 ( struct V_13 * V_14 ,
struct V_1 * V_55 )
{
struct V_20 * V_21 ;
struct V_25 * V_56 ;
struct V_12 * V_9 ;
struct V_7 * V_57 ;
int V_43 ;
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
V_9 -> V_45 = V_9 -> V_2 -> V_45 ;
V_9 -> V_62 = V_9 -> V_2 -> V_50 ;
V_9 -> V_63 = V_9 -> V_64 -> V_2 -> V_65 >> 16 ;
V_9 -> V_66 = V_9 -> V_64 -> V_2 -> V_67 >> 16 ;
if ( V_9 -> V_2 -> V_50 )
F_33 ( V_9 ,
& V_9 -> V_2 -> V_44 ) ;
}
}
static void
F_34 ( struct V_13 * V_14 , struct V_1 * V_55 )
{
struct V_12 * V_9 ;
struct V_7 * V_57 ;
struct V_20 * V_21 ;
struct V_25 * V_56 ;
int V_43 ;
F_16 (old_state, crtc, old_crtc_state, i) {
const struct V_49 * V_34 ;
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
const struct V_46 * V_34 ;
struct V_7 * V_69 ;
struct V_15 * V_16 ;
struct V_70 * V_45 , * V_44 ;
if ( ! V_21 -> V_2 -> V_23 )
continue;
V_16 = V_21 -> V_2 -> V_23 ;
V_34 = V_16 -> V_39 ;
V_69 = V_21 -> V_2 -> V_9 -> V_2 ;
V_45 = & V_69 -> V_45 ;
V_44 = & V_69 -> V_44 ;
if ( ! V_69 -> V_31 )
continue;
F_8 ( L_23 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
if ( V_34 -> V_71 )
V_34 -> V_71 ( V_16 , V_45 , V_44 ) ;
F_35 ( V_16 -> V_47 , V_45 , V_44 ) ;
}
}
void F_36 ( struct V_13 * V_14 ,
struct V_1 * V_55 )
{
F_29 ( V_14 , V_55 ) ;
F_32 ( V_14 , V_55 ) ;
F_34 ( V_14 , V_55 ) ;
}
void F_37 ( struct V_13 * V_14 ,
struct V_1 * V_55 )
{
struct V_12 * V_9 ;
struct V_7 * V_57 ;
struct V_20 * V_21 ;
struct V_25 * V_56 ;
int V_43 ;
F_16 (old_state, crtc, old_crtc_state, i) {
const struct V_49 * V_34 ;
if ( ! F_22 ( V_9 -> V_2 ) )
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
const struct V_46 * V_34 ;
struct V_15 * V_16 ;
if ( ! V_21 -> V_2 -> V_23 )
continue;
if ( ! V_21 -> V_2 -> V_9 -> V_2 -> V_52 ||
! F_22 ( V_21 -> V_2 -> V_9 -> V_2 ) )
continue;
V_16 = V_21 -> V_2 -> V_23 ;
V_34 = V_16 -> V_39 ;
F_8 ( L_25 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
F_38 ( V_16 -> V_47 ) ;
if ( V_34 -> V_50 )
V_34 -> V_50 ( V_16 ) ;
else
V_34 -> V_72 ( V_16 ) ;
F_39 ( V_16 -> V_47 ) ;
}
}
static void F_40 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_43 ;
F_27 (state, plane, plane_state, i) {
if ( ! V_6 -> V_2 -> V_73 )
continue;
F_3 ( ! V_6 -> V_2 -> V_74 ) ;
F_41 ( V_6 -> V_2 -> V_73 , false ) ;
F_42 ( V_6 -> V_2 -> V_73 ) ;
V_6 -> V_2 -> V_73 = NULL ;
}
}
static bool F_43 ( struct V_13 * V_14 ,
struct V_1 * V_55 ,
struct V_12 * V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_75 ;
int V_43 ;
F_27 (old_state, plane, old_plane_state, i) {
if ( V_6 -> V_2 -> V_9 != V_9 &&
V_75 -> V_9 != V_9 )
continue;
if ( V_6 -> V_2 -> V_74 != V_75 -> V_74 )
return true ;
}
return false ;
}
void
F_44 ( struct V_13 * V_14 ,
struct V_1 * V_55 )
{
struct V_12 * V_9 ;
struct V_7 * V_57 ;
int V_43 , V_27 ;
F_16 (old_state, crtc, old_crtc_state, i) {
V_57 -> V_50 = false ;
if ( ! V_9 -> V_2 -> V_50 )
continue;
if ( V_55 -> V_76 )
continue;
if ( ! F_43 ( V_14 , V_55 , V_9 ) )
continue;
V_27 = F_45 ( V_9 ) ;
if ( V_27 != 0 )
continue;
V_57 -> V_50 = true ;
V_57 -> V_77 = F_46 ( V_14 , V_43 ) ;
}
F_16 (old_state, crtc, old_crtc_state, i) {
if ( ! V_57 -> V_50 )
continue;
V_27 = F_47 ( V_14 -> V_78 [ V_43 ] . V_79 ,
V_57 -> V_77 !=
F_46 ( V_14 , V_43 ) ,
F_48 ( 50 ) ) ;
F_49 ( V_9 ) ;
}
}
int F_50 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
bool V_80 )
{
int V_27 ;
if ( V_80 )
return - V_81 ;
V_27 = F_51 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
F_52 ( V_14 , V_2 ) ;
F_40 ( V_14 , V_2 ) ;
F_36 ( V_14 , V_2 ) ;
F_53 ( V_14 , V_2 ) ;
F_37 ( V_14 , V_2 ) ;
F_44 ( V_14 , V_2 ) ;
F_54 ( V_14 , V_2 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
int F_51 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_82 = V_14 -> V_19 . V_83 ;
int V_27 , V_43 ;
for ( V_43 = 0 ; V_43 < V_82 ; V_43 ++ ) {
const struct V_54 * V_34 ;
struct V_5 * V_6 = V_2 -> V_84 [ V_43 ] ;
struct V_3 * V_4 = V_2 -> V_85 [ V_43 ] ;
struct V_86 * V_74 ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
V_74 = V_4 -> V_74 ;
if ( V_74 && V_34 -> V_87 ) {
V_27 = V_34 -> V_87 ( V_6 , V_74 , V_4 ) ;
if ( V_27 )
goto V_88;
}
}
return 0 ;
V_88:
for ( V_43 -- ; V_43 >= 0 ; V_43 -- ) {
const struct V_54 * V_34 ;
struct V_5 * V_6 = V_2 -> V_84 [ V_43 ] ;
struct V_3 * V_4 = V_2 -> V_85 [ V_43 ] ;
struct V_86 * V_74 ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
V_74 = V_2 -> V_85 [ V_43 ] -> V_74 ;
if ( V_74 && V_34 -> V_89 )
V_34 -> V_89 ( V_6 , V_74 , V_4 ) ;
}
return V_27 ;
}
void F_53 ( struct V_13 * V_14 ,
struct V_1 * V_55 )
{
struct V_12 * V_9 ;
struct V_7 * V_57 ;
struct V_5 * V_6 ;
struct V_3 * V_75 ;
int V_43 ;
F_16 (old_state, crtc, old_crtc_state, i) {
const struct V_49 * V_34 ;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_90 )
continue;
V_34 -> V_90 ( V_9 ) ;
}
F_27 (old_state, plane, old_plane_state, i) {
const struct V_54 * V_34 ;
V_34 = V_6 -> V_39 ;
if ( ! V_34 )
continue;
if ( F_56 ( V_6 , V_75 ) &&
V_34 -> V_91 )
V_34 -> V_91 ( V_6 , V_75 ) ;
else if ( V_6 -> V_2 -> V_9 ||
F_56 ( V_6 , V_75 ) )
V_34 -> V_92 ( V_6 , V_75 ) ;
}
F_16 (old_state, crtc, old_crtc_state, i) {
const struct V_49 * V_34 ;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_93 )
continue;
V_34 -> V_93 ( V_9 ) ;
}
}
void
F_57 ( struct V_7 * V_57 )
{
const struct V_49 * V_94 ;
struct V_12 * V_9 = V_57 -> V_9 ;
struct V_1 * V_55 = V_57 -> V_2 ;
struct V_5 * V_6 ;
unsigned V_95 ;
V_95 = V_57 -> V_95 ;
V_95 |= V_9 -> V_2 -> V_95 ;
V_94 = V_9 -> V_39 ;
if ( V_94 && V_94 -> V_90 )
V_94 -> V_90 ( V_9 ) ;
F_58 (plane, crtc->dev, plane_mask) {
struct V_3 * V_75 =
F_59 ( V_55 , V_6 ) ;
const struct V_54 * V_96 ;
V_96 = V_6 -> V_39 ;
if ( ! V_75 || ! V_96 )
continue;
F_3 ( V_6 -> V_2 -> V_9 && V_6 -> V_2 -> V_9 != V_9 ) ;
if ( F_56 ( V_6 , V_75 ) &&
V_96 -> V_91 )
V_96 -> V_91 ( V_6 , V_75 ) ;
else if ( V_6 -> V_2 -> V_9 ||
F_56 ( V_6 , V_75 ) )
V_96 -> V_92 ( V_6 , V_75 ) ;
}
if ( V_94 && V_94 -> V_93 )
V_94 -> V_93 ( V_9 ) ;
}
void F_54 ( struct V_13 * V_14 ,
struct V_1 * V_55 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_43 ;
F_27 (old_state, plane, plane_state, i) {
const struct V_54 * V_34 ;
struct V_86 * V_97 ;
V_34 = V_6 -> V_39 ;
V_97 = V_4 -> V_74 ;
if ( V_97 && V_34 -> V_89 )
V_34 -> V_89 ( V_6 , V_97 , V_4 ) ;
}
}
void F_52 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_14 -> V_19 . V_98 ; V_43 ++ ) {
struct V_20 * V_21 = V_2 -> V_37 [ V_43 ] ;
if ( ! V_21 )
continue;
V_21 -> V_2 -> V_2 = V_2 ;
F_60 ( V_2 -> V_38 [ V_43 ] , V_21 -> V_2 ) ;
V_21 -> V_2 -> V_2 = NULL ;
}
for ( V_43 = 0 ; V_43 < V_14 -> V_19 . V_99 ; V_43 ++ ) {
struct V_12 * V_9 = V_2 -> V_100 [ V_43 ] ;
if ( ! V_9 )
continue;
V_9 -> V_2 -> V_2 = V_2 ;
F_60 ( V_2 -> V_10 [ V_43 ] , V_9 -> V_2 ) ;
V_9 -> V_2 -> V_2 = NULL ;
}
for ( V_43 = 0 ; V_43 < V_14 -> V_19 . V_83 ; V_43 ++ ) {
struct V_5 * V_6 = V_2 -> V_84 [ V_43 ] ;
if ( ! V_6 )
continue;
V_6 -> V_2 -> V_2 = V_2 ;
F_60 ( V_2 -> V_85 [ V_43 ] , V_6 -> V_2 ) ;
V_6 -> V_2 -> V_2 = NULL ;
}
}
int F_61 ( struct V_5 * V_6 ,
struct V_12 * V_9 ,
struct V_86 * V_74 ,
int V_101 , int V_102 ,
unsigned int V_103 , unsigned int V_104 ,
T_1 V_65 , T_1 V_67 ,
T_1 V_105 , T_1 V_106 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
V_2 = F_62 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_107 ;
V_2 -> V_108 = F_63 ( V_9 ) ;
V_109:
V_4 = F_64 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_88;
}
V_27 = F_65 ( V_4 , V_9 ) ;
if ( V_27 != 0 )
goto V_88;
F_66 ( V_4 , V_74 ) ;
V_4 -> V_101 = V_101 ;
V_4 -> V_102 = V_102 ;
V_4 -> V_104 = V_104 ;
V_4 -> V_103 = V_103 ;
V_4 -> V_65 = V_65 ;
V_4 -> V_67 = V_67 ;
V_4 -> V_106 = V_106 ;
V_4 -> V_105 = V_105 ;
if ( V_6 == V_9 -> V_110 )
V_2 -> V_76 = true ;
V_27 = F_67 ( V_2 ) ;
if ( V_27 != 0 )
goto V_88;
return 0 ;
V_88:
if ( V_27 == - V_111 )
goto V_112;
F_55 ( V_2 ) ;
return V_27 ;
V_112:
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
V_6 -> V_97 = V_6 -> V_74 ;
goto V_109;
}
int F_70 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
if ( ! V_6 -> V_9 )
return 0 ;
V_2 = F_62 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_107 ;
V_2 -> V_108 = F_63 ( V_6 -> V_9 ) ;
V_109:
V_4 = F_64 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_88;
}
V_27 = F_65 ( V_4 , NULL ) ;
if ( V_27 != 0 )
goto V_88;
F_66 ( V_4 , NULL ) ;
V_4 -> V_101 = 0 ;
V_4 -> V_102 = 0 ;
V_4 -> V_104 = 0 ;
V_4 -> V_103 = 0 ;
V_4 -> V_65 = 0 ;
V_4 -> V_67 = 0 ;
V_4 -> V_106 = 0 ;
V_4 -> V_105 = 0 ;
if ( V_6 == V_6 -> V_9 -> V_110 )
V_2 -> V_76 = true ;
V_27 = F_67 ( V_2 ) ;
if ( V_27 != 0 )
goto V_88;
return 0 ;
V_88:
if ( V_27 == - V_111 )
goto V_112;
F_55 ( V_2 ) ;
return V_27 ;
V_112:
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
V_6 -> V_97 = V_6 -> V_74 ;
goto V_109;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_113 * V_114 )
{
struct V_13 * V_14 = V_114 -> V_9 -> V_14 ;
struct V_12 * V_9 ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_25 * V_42 ;
int V_27 , V_43 , V_115 ;
V_27 = F_72 ( & V_14 -> V_19 . V_22 ,
V_2 -> V_108 ) ;
if ( V_27 )
return V_27 ;
for ( V_43 = 0 ; V_43 < V_114 -> V_51 ; V_43 ++ ) {
V_42 = F_12 ( V_2 ,
V_114 -> V_37 [ V_43 ] ) ;
if ( F_10 ( V_42 ) )
return F_11 ( V_42 ) ;
}
F_16 (state, crtc, crtc_state, i) {
V_27 = F_23 ( V_2 , V_9 ) ;
if ( V_27 )
return V_27 ;
}
F_18 (state, connector, conn_state, i) {
if ( V_42 -> V_9 == V_114 -> V_9 ) {
V_27 = F_13 ( V_42 ,
NULL ) ;
if ( V_27 )
return V_27 ;
}
for ( V_115 = 0 ; V_115 < V_114 -> V_51 ; V_115 ++ ) {
if ( V_114 -> V_37 [ V_115 ] == V_21 ) {
V_27 = F_13 ( V_42 ,
V_114 -> V_9 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
}
F_16 (state, crtc, crtc_state, i) {
if ( V_9 == V_114 -> V_9 )
continue;
if ( ! F_25 ( V_2 , V_9 ) ) {
V_27 = F_73 ( V_8 ,
NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_8 -> V_52 = false ;
}
}
return 0 ;
}
int F_74 ( struct V_113 * V_114 )
{
struct V_1 * V_2 ;
struct V_12 * V_9 = V_114 -> V_9 ;
struct V_7 * V_8 ;
struct V_3 * V_116 ;
int V_27 = 0 ;
V_2 = F_62 ( V_9 -> V_14 ) ;
if ( ! V_2 )
return - V_107 ;
V_2 -> V_108 = F_63 ( V_9 ) ;
V_109:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_88;
}
V_116 = F_64 ( V_2 , V_9 -> V_64 ) ;
if ( F_10 ( V_116 ) ) {
V_27 = F_11 ( V_116 ) ;
goto V_88;
}
if ( ! V_114 -> V_45 ) {
F_3 ( V_114 -> V_74 ) ;
F_3 ( V_114 -> V_51 ) ;
V_27 = F_75 ( V_8 , NULL ) ;
if ( V_27 != 0 )
goto V_88;
V_8 -> V_52 = false ;
V_27 = F_65 ( V_116 , NULL ) ;
if ( V_27 != 0 )
goto V_88;
F_66 ( V_116 , NULL ) ;
goto V_72;
}
F_3 ( ! V_114 -> V_74 ) ;
F_3 ( ! V_114 -> V_51 ) ;
V_27 = F_75 ( V_8 , V_114 -> V_45 ) ;
if ( V_27 != 0 )
goto V_88;
V_8 -> V_52 = true ;
V_27 = F_65 ( V_116 , V_9 ) ;
if ( V_27 != 0 )
goto V_88;
F_66 ( V_116 , V_114 -> V_74 ) ;
V_116 -> V_101 = 0 ;
V_116 -> V_102 = 0 ;
V_116 -> V_104 = V_114 -> V_45 -> V_117 ;
V_116 -> V_103 = V_114 -> V_45 -> V_118 ;
V_116 -> V_65 = V_114 -> V_63 << 16 ;
V_116 -> V_67 = V_114 -> V_66 << 16 ;
V_116 -> V_106 = V_114 -> V_45 -> V_117 << 16 ;
V_116 -> V_105 = V_114 -> V_45 -> V_118 << 16 ;
V_72:
V_27 = F_71 ( V_2 , V_114 ) ;
if ( V_27 )
goto V_88;
V_27 = F_67 ( V_2 ) ;
if ( V_27 != 0 )
goto V_88;
return 0 ;
V_88:
if ( V_27 == - V_111 )
goto V_112;
F_55 ( V_2 ) ;
return V_27 ;
V_112:
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
V_9 -> V_64 -> V_97 = V_9 -> V_64 -> V_74 ;
goto V_109;
}
int
F_76 ( struct V_12 * V_9 ,
struct V_119 * V_120 ,
T_2 V_121 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_27 = 0 ;
V_2 = F_62 ( V_9 -> V_14 ) ;
if ( ! V_2 )
return - V_107 ;
V_2 -> V_108 = V_9 -> V_14 -> V_19 . V_108 ;
V_109:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_88;
}
V_27 = F_77 ( V_9 , V_8 ,
V_120 , V_121 ) ;
if ( V_27 )
goto V_88;
V_27 = F_67 ( V_2 ) ;
if ( V_27 != 0 )
goto V_88;
return 0 ;
V_88:
if ( V_27 == - V_111 )
goto V_112;
F_55 ( V_2 ) ;
return V_27 ;
V_112:
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
goto V_109;
}
int
F_78 ( struct V_5 * V_6 ,
struct V_119 * V_120 ,
T_2 V_121 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
V_2 = F_62 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_107 ;
V_2 -> V_108 = V_6 -> V_14 -> V_19 . V_108 ;
V_109:
V_4 = F_64 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_88;
}
V_27 = F_79 ( V_6 , V_4 ,
V_120 , V_121 ) ;
if ( V_27 )
goto V_88;
V_27 = F_67 ( V_2 ) ;
if ( V_27 != 0 )
goto V_88;
return 0 ;
V_88:
if ( V_27 == - V_111 )
goto V_112;
F_55 ( V_2 ) ;
return V_27 ;
V_112:
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
goto V_109;
}
int
F_80 ( struct V_20 * V_21 ,
struct V_119 * V_120 ,
T_2 V_121 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
int V_27 = 0 ;
V_2 = F_62 ( V_21 -> V_14 ) ;
if ( ! V_2 )
return - V_107 ;
V_2 -> V_108 = V_21 -> V_14 -> V_19 . V_108 ;
V_109:
V_26 = F_12 ( V_2 , V_21 ) ;
if ( F_10 ( V_26 ) ) {
V_27 = F_11 ( V_26 ) ;
goto V_88;
}
V_27 = F_81 ( V_21 , V_26 ,
V_120 , V_121 ) ;
if ( V_27 )
goto V_88;
V_27 = F_67 ( V_2 ) ;
if ( V_27 != 0 )
goto V_88;
return 0 ;
V_88:
if ( V_27 == - V_111 )
goto V_112;
F_55 ( V_2 ) ;
return V_27 ;
V_112:
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
goto V_109;
}
int F_82 ( struct V_12 * V_9 ,
struct V_86 * V_74 ,
struct V_122 * V_123 ,
T_1 V_124 )
{
struct V_5 * V_6 = V_9 -> V_64 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_7 * V_8 ;
int V_27 = 0 ;
if ( V_124 & V_125 )
return - V_41 ;
V_2 = F_62 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_107 ;
V_2 -> V_108 = F_63 ( V_9 ) ;
V_109:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_88;
}
V_8 -> V_123 = V_123 ;
V_4 = F_64 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_88;
}
V_27 = F_65 ( V_4 , V_9 ) ;
if ( V_27 != 0 )
goto V_88;
F_66 ( V_4 , V_74 ) ;
V_27 = F_83 ( V_2 ) ;
if ( V_27 != 0 )
goto V_88;
V_6 -> V_74 = V_6 -> V_2 -> V_74 ;
return 0 ;
V_88:
if ( V_27 == - V_111 )
goto V_112;
F_55 ( V_2 ) ;
return V_27 ;
V_112:
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
V_6 -> V_97 = V_6 -> V_74 ;
goto V_109;
}
void F_84 ( struct V_20 * V_21 ,
int V_45 )
{
struct V_17 * V_18 = & V_21 -> V_14 -> V_19 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_12 * V_9 ;
struct V_20 * V_126 ;
int V_27 ;
bool V_52 = false ;
if ( V_45 != V_127 )
V_45 = V_61 ;
V_21 -> V_60 = V_45 ;
V_9 = V_21 -> V_2 -> V_9 ;
if ( ! V_9 )
return;
V_2 = F_62 ( V_21 -> V_14 ) ;
if ( ! V_2 )
return;
V_2 -> V_108 = F_63 ( V_9 ) ;
V_109:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) )
return;
F_3 ( ! F_5 ( & V_18 -> V_22 ) ) ;
F_6 (tmp_connector, &config->connector_list, head) {
if ( V_126 -> V_2 -> V_9 != V_9 )
continue;
if ( V_126 -> V_60 == V_127 ) {
V_52 = true ;
break;
}
}
V_8 -> V_52 = V_52 ;
V_27 = F_67 ( V_2 ) ;
if ( V_27 != 0 )
goto V_88;
return;
V_88:
if ( V_27 == - V_111 )
goto V_112;
F_55 ( V_2 ) ;
F_85 ( 1 , L_26 , V_27 ) ;
return;
V_112:
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
goto V_109;
}
void F_86 ( struct V_12 * V_9 )
{
if ( V_9 -> V_2 && V_9 -> V_2 -> V_128 )
F_87 ( V_9 -> V_2 -> V_128 ) ;
F_88 ( V_9 -> V_2 ) ;
V_9 -> V_2 = F_89 ( sizeof( * V_9 -> V_2 ) , V_129 ) ;
if ( V_9 -> V_2 )
V_9 -> V_2 -> V_9 = V_9 ;
}
void F_90 ( struct V_12 * V_9 ,
struct V_7 * V_2 )
{
memcpy ( V_2 , V_9 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_128 )
F_91 ( V_2 -> V_128 ) ;
V_2 -> V_31 = false ;
V_2 -> V_53 = false ;
V_2 -> V_11 = false ;
V_2 -> V_123 = NULL ;
}
struct V_7 *
F_92 ( struct V_12 * V_9 )
{
struct V_7 * V_2 ;
if ( F_3 ( ! V_9 -> V_2 ) )
return NULL ;
V_2 = F_93 ( sizeof( * V_2 ) , V_129 ) ;
if ( V_2 )
F_90 ( V_9 , V_2 ) ;
return V_2 ;
}
void F_94 ( struct V_12 * V_9 ,
struct V_7 * V_2 )
{
if ( V_2 -> V_128 )
F_87 ( V_2 -> V_128 ) ;
}
void F_95 ( struct V_12 * V_9 ,
struct V_7 * V_2 )
{
F_94 ( V_9 , V_2 ) ;
F_88 ( V_2 ) ;
}
void F_96 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 && V_6 -> V_2 -> V_74 )
F_97 ( V_6 -> V_2 -> V_74 ) ;
F_88 ( V_6 -> V_2 ) ;
V_6 -> V_2 = F_89 ( sizeof( * V_6 -> V_2 ) , V_129 ) ;
if ( V_6 -> V_2 )
V_6 -> V_2 -> V_6 = V_6 ;
}
void F_98 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
memcpy ( V_2 , V_6 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_74 )
F_99 ( V_2 -> V_74 ) ;
}
struct V_3 *
F_100 ( struct V_5 * V_6 )
{
struct V_3 * V_2 ;
if ( F_3 ( ! V_6 -> V_2 ) )
return NULL ;
V_2 = F_93 ( sizeof( * V_2 ) , V_129 ) ;
if ( V_2 )
F_98 ( V_6 , V_2 ) ;
return V_2 ;
}
void F_101 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
if ( V_2 -> V_74 )
F_97 ( V_2 -> V_74 ) ;
}
void F_102 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
F_101 ( V_6 , V_2 ) ;
F_88 ( V_2 ) ;
}
void F_103 ( struct V_20 * V_21 )
{
F_88 ( V_21 -> V_2 ) ;
V_21 -> V_2 = F_89 ( sizeof( * V_21 -> V_2 ) , V_129 ) ;
if ( V_21 -> V_2 )
V_21 -> V_2 -> V_21 = V_21 ;
}
void
F_104 ( struct V_20 * V_21 ,
struct V_25 * V_2 )
{
memcpy ( V_2 , V_21 -> V_2 , sizeof( * V_2 ) ) ;
}
struct V_25 *
F_105 ( struct V_20 * V_21 )
{
struct V_25 * V_2 ;
if ( F_3 ( ! V_21 -> V_2 ) )
return NULL ;
V_2 = F_93 ( sizeof( * V_2 ) , V_129 ) ;
if ( V_2 )
F_104 ( V_21 , V_2 ) ;
return V_2 ;
}
void
F_106 ( struct V_20 * V_21 ,
struct V_25 * V_2 )
{
}
void F_107 ( struct V_20 * V_21 ,
struct V_25 * V_2 )
{
F_106 ( V_21 , V_2 ) ;
F_88 ( V_2 ) ;
}
