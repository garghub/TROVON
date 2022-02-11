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
F_6 (connector, dev) {
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
F_12 (connector, &config->connector_list, head) {
if ( V_21 -> V_2 -> V_23 != V_16 )
continue;
F_8 ( L_2 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ) ;
V_26 = F_13 ( V_2 ,
V_21 ) ;
if ( F_10 ( V_26 ) )
return F_11 ( V_26 ) ;
V_27 = F_14 ( V_26 , NULL ) ;
if ( V_27 )
return V_27 ;
V_26 -> V_23 = NULL ;
}
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 , int V_32 )
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
if ( ! F_16 ( V_35 , V_26 -> V_9 ) ) {
F_8 ( L_6 ,
V_35 -> V_28 . V_29 ,
V_35 -> V_30 ,
V_26 -> V_9 -> V_28 . V_29 ) ;
return - V_41 ;
}
if ( V_35 == V_26 -> V_23 ) {
F_8 ( L_7 ,
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
F_8 ( L_8 ,
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
F_8 ( L_9 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ,
V_35 -> V_28 . V_29 ,
V_35 -> V_30 ,
V_26 -> V_9 -> V_28 . V_29 ) ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
struct V_12 * V_9 ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_25 * V_42 ;
int V_43 ;
bool V_27 ;
F_18 (state, crtc, crtc_state, i) {
if ( ! V_8 -> V_44 &&
! V_8 -> V_31 )
continue;
F_19 ( & V_8 -> V_45 , & V_8 -> V_46 ) ;
}
F_20 (state, connector, conn_state, i) {
const struct V_47 * V_34 ;
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
V_27 = F_21 ( V_16 -> V_48 , & V_8 -> V_46 ,
& V_8 -> V_45 ) ;
if ( ! V_27 ) {
F_8 ( L_10 ) ;
return - V_41 ;
}
if ( V_34 -> V_49 ) {
V_27 = V_34 -> V_49 ( V_16 , V_8 ,
V_42 ) ;
if ( V_27 ) {
F_8 ( L_11 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
return V_27 ;
}
} else if ( V_34 -> F_17 ) {
V_27 = V_34 -> F_17 ( V_16 , & V_8 -> V_46 ,
& V_8 -> V_45 ) ;
if ( ! V_27 ) {
F_8 ( L_12 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
return - V_41 ;
}
}
}
F_18 (state, crtc, crtc_state, i) {
const struct V_50 * V_34 ;
if ( ! V_8 -> V_44 &&
! V_8 -> V_31 )
continue;
V_34 = V_9 -> V_39 ;
if ( ! V_34 -> F_17 )
continue;
V_27 = V_34 -> F_17 ( V_9 , & V_8 -> V_46 ,
& V_8 -> V_45 ) ;
if ( ! V_27 ) {
F_8 ( L_13 ,
V_9 -> V_28 . V_29 ) ;
return - V_41 ;
}
}
return 0 ;
}
int
F_22 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_12 * V_9 ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_25 * V_26 ;
int V_43 , V_27 ;
F_18 (state, crtc, crtc_state, i) {
if ( ! F_23 ( & V_9 -> V_2 -> V_46 , & V_8 -> V_46 ) ) {
F_8 ( L_14 ,
V_9 -> V_28 . V_29 ) ;
V_8 -> V_44 = true ;
}
if ( V_9 -> V_2 -> V_51 != V_8 -> V_51 ) {
F_8 ( L_15 ,
V_9 -> V_28 . V_29 ) ;
V_8 -> V_44 = true ;
V_8 -> V_31 = true ;
}
}
F_20 (state, connector, connector_state, i) {
V_27 = F_15 ( V_2 , V_43 ) ;
if ( V_27 )
return V_27 ;
}
F_18 (state, crtc, crtc_state, i) {
int V_52 ;
if ( V_9 -> V_2 -> V_53 != V_8 -> V_53 ) {
F_8 ( L_16 ,
V_9 -> V_28 . V_29 ) ;
V_8 -> V_54 = true ;
}
if ( ! F_24 ( V_8 ) )
continue;
F_8 ( L_17 ,
V_9 -> V_28 . V_29 ,
V_8 -> V_51 ? 'y' : 'n' ,
V_8 -> V_53 ? 'y' : 'n' ) ;
V_27 = F_25 ( V_2 , V_9 ) ;
if ( V_27 != 0 )
return V_27 ;
V_27 = F_26 ( V_2 , V_9 ) ;
if ( V_27 != 0 )
return V_27 ;
V_52 = F_27 ( V_2 ,
V_9 ) ;
if ( V_8 -> V_51 != ! ! V_52 ) {
F_8 ( L_18 ,
V_9 -> V_28 . V_29 ) ;
return - V_41 ;
}
}
return F_17 ( V_2 ) ;
}
int
F_28 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_12 * V_9 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_43 , V_27 = 0 ;
F_29 (state, plane, plane_state, i) {
const struct V_55 * V_34 ;
V_34 = V_6 -> V_39 ;
F_1 ( V_2 , V_4 , V_6 ) ;
if ( ! V_34 || ! V_34 -> V_49 )
continue;
V_27 = V_34 -> V_49 ( V_6 , V_4 ) ;
if ( V_27 ) {
F_8 ( L_19 ,
V_6 -> V_28 . V_29 ) ;
return V_27 ;
}
}
F_18 (state, crtc, crtc_state, i) {
const struct V_50 * V_34 ;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_49 )
continue;
V_27 = V_34 -> V_49 ( V_9 , V_2 -> V_10 [ V_43 ] ) ;
if ( V_27 ) {
F_8 ( L_20 ,
V_9 -> V_28 . V_29 ) ;
return V_27 ;
}
}
return V_27 ;
}
int F_30 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_27 ;
V_27 = F_22 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_28 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
return V_27 ;
}
static void
F_31 ( struct V_13 * V_14 , struct V_1 * V_56 )
{
struct V_20 * V_21 ;
struct V_25 * V_57 ;
struct V_12 * V_9 ;
struct V_7 * V_58 ;
int V_43 ;
F_20 (old_state, connector, old_conn_state, i) {
const struct V_47 * V_34 ;
struct V_15 * V_16 ;
struct V_7 * V_58 ;
if ( ! V_57 -> V_9 )
continue;
V_58 = V_56 -> V_10 [ F_2 ( V_57 -> V_9 ) ] ;
if ( ! V_58 -> V_53 ||
! F_24 ( V_57 -> V_9 -> V_2 ) )
continue;
V_16 = V_57 -> V_23 ;
if ( F_3 ( ! V_16 ) )
continue;
V_34 = V_16 -> V_39 ;
F_8 ( L_21 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
F_32 ( V_16 -> V_48 ) ;
if ( V_21 -> V_2 -> V_9 && V_34 -> V_59 )
V_34 -> V_59 ( V_16 ) ;
else if ( V_34 -> V_60 )
V_34 -> V_60 ( V_16 ) ;
else
V_34 -> V_61 ( V_16 , V_62 ) ;
F_33 ( V_16 -> V_48 ) ;
}
F_18 (old_state, crtc, old_crtc_state, i) {
const struct V_50 * V_34 ;
if ( ! F_24 ( V_9 -> V_2 ) )
continue;
if ( ! V_58 -> V_53 )
continue;
V_34 = V_9 -> V_39 ;
F_8 ( L_22 ,
V_9 -> V_28 . V_29 ) ;
if ( V_9 -> V_2 -> V_51 && V_34 -> V_59 )
V_34 -> V_59 ( V_9 ) ;
else if ( V_34 -> V_60 )
V_34 -> V_60 ( V_9 ) ;
else
V_34 -> V_61 ( V_9 , V_62 ) ;
}
}
void
F_34 ( struct V_13 * V_14 ,
struct V_1 * V_56 )
{
struct V_20 * V_21 ;
struct V_25 * V_57 ;
struct V_12 * V_9 ;
struct V_7 * V_58 ;
int V_43 ;
F_20 (old_state, connector, old_conn_state, i) {
if ( V_21 -> V_16 ) {
F_3 ( ! V_21 -> V_16 -> V_9 ) ;
V_21 -> V_16 -> V_9 = NULL ;
V_21 -> V_16 = NULL ;
}
V_9 = V_21 -> V_2 -> V_9 ;
if ( ( ! V_9 && V_57 -> V_9 ) ||
( V_9 && F_24 ( V_9 -> V_2 ) ) ) {
struct V_63 * V_64 =
V_14 -> V_19 . V_65 ;
int V_46 = V_62 ;
if ( V_9 && V_9 -> V_2 -> V_53 )
V_46 = V_66 ;
V_21 -> V_61 = V_46 ;
F_35 ( & V_21 -> V_28 ,
V_64 , V_46 ) ;
}
}
F_20 (old_state, connector, old_conn_state, i) {
if ( ! V_21 -> V_2 -> V_9 )
continue;
if ( F_3 ( ! V_21 -> V_2 -> V_23 ) )
continue;
V_21 -> V_16 = V_21 -> V_2 -> V_23 ;
V_21 -> V_16 -> V_9 = V_21 -> V_2 -> V_9 ;
}
F_18 (old_state, crtc, old_crtc_state, i) {
struct V_5 * V_67 = V_9 -> V_67 ;
V_9 -> V_46 = V_9 -> V_2 -> V_46 ;
V_9 -> V_68 = V_9 -> V_2 -> V_51 ;
if ( F_36 ( V_56 , V_67 ) &&
V_67 -> V_2 -> V_9 == V_9 ) {
V_9 -> V_69 = V_67 -> V_2 -> V_70 >> 16 ;
V_9 -> V_71 = V_67 -> V_2 -> V_72 >> 16 ;
}
if ( V_9 -> V_2 -> V_51 )
F_37 ( V_9 ,
& V_9 -> V_2 -> V_45 ) ;
}
}
static void
F_38 ( struct V_13 * V_14 , struct V_1 * V_56 )
{
struct V_12 * V_9 ;
struct V_7 * V_58 ;
struct V_20 * V_21 ;
struct V_25 * V_57 ;
int V_43 ;
F_18 (old_state, crtc, old_crtc_state, i) {
const struct V_50 * V_34 ;
if ( ! V_9 -> V_2 -> V_44 )
continue;
V_34 = V_9 -> V_39 ;
if ( V_9 -> V_2 -> V_51 && V_34 -> V_73 ) {
F_8 ( L_23 ,
V_9 -> V_28 . V_29 ) ;
V_34 -> V_73 ( V_9 ) ;
}
}
F_20 (old_state, connector, old_conn_state, i) {
const struct V_47 * V_34 ;
struct V_7 * V_74 ;
struct V_15 * V_16 ;
struct V_75 * V_46 , * V_45 ;
if ( ! V_21 -> V_2 -> V_23 )
continue;
V_16 = V_21 -> V_2 -> V_23 ;
V_34 = V_16 -> V_39 ;
V_74 = V_21 -> V_2 -> V_9 -> V_2 ;
V_46 = & V_74 -> V_46 ;
V_45 = & V_74 -> V_45 ;
if ( ! V_74 -> V_44 )
continue;
F_8 ( L_24 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
if ( V_34 -> V_76 )
V_34 -> V_76 ( V_16 , V_46 , V_45 ) ;
F_39 ( V_16 -> V_48 , V_46 , V_45 ) ;
}
}
void F_40 ( struct V_13 * V_14 ,
struct V_1 * V_56 )
{
F_31 ( V_14 , V_56 ) ;
F_34 ( V_14 , V_56 ) ;
F_38 ( V_14 , V_56 ) ;
}
void F_41 ( struct V_13 * V_14 ,
struct V_1 * V_56 )
{
struct V_12 * V_9 ;
struct V_7 * V_58 ;
struct V_20 * V_21 ;
struct V_25 * V_57 ;
int V_43 ;
F_18 (old_state, crtc, old_crtc_state, i) {
const struct V_50 * V_34 ;
if ( ! F_24 ( V_9 -> V_2 ) )
continue;
if ( ! V_9 -> V_2 -> V_53 )
continue;
V_34 = V_9 -> V_39 ;
if ( V_9 -> V_2 -> V_51 ) {
F_8 ( L_25 ,
V_9 -> V_28 . V_29 ) ;
if ( V_34 -> V_51 )
V_34 -> V_51 ( V_9 ) ;
else
V_34 -> V_77 ( V_9 ) ;
}
}
F_20 (old_state, connector, old_conn_state, i) {
const struct V_47 * V_34 ;
struct V_15 * V_16 ;
if ( ! V_21 -> V_2 -> V_23 )
continue;
if ( ! V_21 -> V_2 -> V_9 -> V_2 -> V_53 ||
! F_24 ( V_21 -> V_2 -> V_9 -> V_2 ) )
continue;
V_16 = V_21 -> V_2 -> V_23 ;
V_34 = V_16 -> V_39 ;
F_8 ( L_26 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
F_42 ( V_16 -> V_48 ) ;
if ( V_34 -> V_51 )
V_34 -> V_51 ( V_16 ) ;
else
V_34 -> V_77 ( V_16 ) ;
F_43 ( V_16 -> V_48 ) ;
}
}
static void F_44 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_43 ;
F_29 (state, plane, plane_state, i) {
if ( ! V_6 -> V_2 -> V_78 )
continue;
F_3 ( ! V_6 -> V_2 -> V_79 ) ;
F_45 ( V_6 -> V_2 -> V_78 , false ) ;
F_46 ( V_6 -> V_2 -> V_78 ) ;
V_6 -> V_2 -> V_78 = NULL ;
}
}
static bool F_47 ( struct V_13 * V_14 ,
struct V_1 * V_56 ,
struct V_12 * V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_80 ;
int V_43 ;
F_29 (old_state, plane, old_plane_state, i) {
if ( V_6 -> V_2 -> V_9 != V_9 &&
V_80 -> V_9 != V_9 )
continue;
if ( V_6 -> V_2 -> V_79 != V_80 -> V_79 )
return true ;
}
return false ;
}
void
F_48 ( struct V_13 * V_14 ,
struct V_1 * V_56 )
{
struct V_12 * V_9 ;
struct V_7 * V_58 ;
int V_43 , V_27 ;
F_18 (old_state, crtc, old_crtc_state, i) {
V_58 -> V_51 = false ;
if ( ! V_9 -> V_2 -> V_51 )
continue;
if ( V_56 -> V_81 )
continue;
if ( ! F_47 ( V_14 , V_56 , V_9 ) )
continue;
V_27 = F_49 ( V_9 ) ;
if ( V_27 != 0 )
continue;
V_58 -> V_51 = true ;
V_58 -> V_82 = F_50 ( V_9 ) ;
}
F_18 (old_state, crtc, old_crtc_state, i) {
if ( ! V_58 -> V_51 )
continue;
V_27 = F_51 ( V_14 -> V_83 [ V_43 ] . V_84 ,
V_58 -> V_82 !=
F_50 ( V_9 ) ,
F_52 ( 50 ) ) ;
F_53 ( V_9 ) ;
}
}
int F_54 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
bool V_85 )
{
int V_27 ;
if ( V_85 )
return - V_86 ;
V_27 = F_55 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
F_56 ( V_14 , V_2 ) ;
F_44 ( V_14 , V_2 ) ;
F_40 ( V_14 , V_2 ) ;
F_57 ( V_14 , V_2 , false ) ;
F_41 ( V_14 , V_2 ) ;
F_48 ( V_14 , V_2 ) ;
F_58 ( V_14 , V_2 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
int F_55 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_87 = V_14 -> V_19 . V_88 ;
int V_27 , V_43 ;
for ( V_43 = 0 ; V_43 < V_87 ; V_43 ++ ) {
const struct V_55 * V_34 ;
struct V_5 * V_6 = V_2 -> V_89 [ V_43 ] ;
struct V_3 * V_4 = V_2 -> V_90 [ V_43 ] ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
if ( V_34 -> V_91 ) {
V_27 = V_34 -> V_91 ( V_6 , V_4 ) ;
if ( V_27 )
goto V_92;
}
}
return 0 ;
V_92:
for ( V_43 -- ; V_43 >= 0 ; V_43 -- ) {
const struct V_55 * V_34 ;
struct V_5 * V_6 = V_2 -> V_89 [ V_43 ] ;
struct V_3 * V_4 = V_2 -> V_90 [ V_43 ] ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
if ( V_34 -> V_93 )
V_34 -> V_93 ( V_6 , V_4 ) ;
}
return V_27 ;
}
bool F_60 ( struct V_3 * V_2 )
{
return V_2 -> V_9 && V_2 -> V_9 -> V_2 -> V_53 ;
}
void F_57 ( struct V_13 * V_14 ,
struct V_1 * V_56 ,
bool V_94 )
{
struct V_12 * V_9 ;
struct V_7 * V_58 ;
struct V_5 * V_6 ;
struct V_3 * V_80 ;
int V_43 ;
F_18 (old_state, crtc, old_crtc_state, i) {
const struct V_50 * V_34 ;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_95 )
continue;
if ( V_94 && ! V_9 -> V_2 -> V_53 )
continue;
V_34 -> V_95 ( V_9 , V_58 ) ;
}
F_29 (old_state, plane, old_plane_state, i) {
const struct V_55 * V_34 ;
bool V_96 ;
V_34 = V_6 -> V_39 ;
if ( ! V_34 )
continue;
V_96 = F_61 ( V_6 , V_80 ) ;
if ( V_94 ) {
if ( ! V_96 && ! F_60 ( V_6 -> V_2 ) )
continue;
if ( V_96 && ! F_60 ( V_80 ) )
continue;
}
if ( V_96 && V_34 -> V_97 )
V_34 -> V_97 ( V_6 , V_80 ) ;
else if ( V_6 -> V_2 -> V_9 || V_96 )
V_34 -> V_98 ( V_6 , V_80 ) ;
}
F_18 (old_state, crtc, old_crtc_state, i) {
const struct V_50 * V_34 ;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_99 )
continue;
if ( V_94 && ! V_9 -> V_2 -> V_53 )
continue;
V_34 -> V_99 ( V_9 , V_58 ) ;
}
}
void
F_62 ( struct V_7 * V_58 )
{
const struct V_50 * V_100 ;
struct V_12 * V_9 = V_58 -> V_9 ;
struct V_1 * V_56 = V_58 -> V_2 ;
struct V_5 * V_6 ;
unsigned V_101 ;
V_101 = V_58 -> V_101 ;
V_101 |= V_9 -> V_2 -> V_101 ;
V_100 = V_9 -> V_39 ;
if ( V_100 && V_100 -> V_95 )
V_100 -> V_95 ( V_9 , V_58 ) ;
F_63 (plane, crtc->dev, plane_mask) {
struct V_3 * V_80 =
F_36 ( V_56 , V_6 ) ;
const struct V_55 * V_102 ;
V_102 = V_6 -> V_39 ;
if ( ! V_80 || ! V_102 )
continue;
F_3 ( V_6 -> V_2 -> V_9 && V_6 -> V_2 -> V_9 != V_9 ) ;
if ( F_61 ( V_6 , V_80 ) &&
V_102 -> V_97 )
V_102 -> V_97 ( V_6 , V_80 ) ;
else if ( V_6 -> V_2 -> V_9 ||
F_61 ( V_6 , V_80 ) )
V_102 -> V_98 ( V_6 , V_80 ) ;
}
if ( V_100 && V_100 -> V_99 )
V_100 -> V_99 ( V_9 , V_58 ) ;
}
void F_58 ( struct V_13 * V_14 ,
struct V_1 * V_56 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_43 ;
F_29 (old_state, plane, plane_state, i) {
const struct V_55 * V_34 ;
V_34 = V_6 -> V_39 ;
if ( V_34 -> V_93 )
V_34 -> V_93 ( V_6 , V_4 ) ;
}
}
void F_56 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_14 -> V_19 . V_103 ; V_43 ++ ) {
struct V_20 * V_21 = V_2 -> V_37 [ V_43 ] ;
if ( ! V_21 )
continue;
V_21 -> V_2 -> V_2 = V_2 ;
F_64 ( V_2 -> V_38 [ V_43 ] , V_21 -> V_2 ) ;
V_21 -> V_2 -> V_2 = NULL ;
}
for ( V_43 = 0 ; V_43 < V_14 -> V_19 . V_104 ; V_43 ++ ) {
struct V_12 * V_9 = V_2 -> V_105 [ V_43 ] ;
if ( ! V_9 )
continue;
V_9 -> V_2 -> V_2 = V_2 ;
F_64 ( V_2 -> V_10 [ V_43 ] , V_9 -> V_2 ) ;
V_9 -> V_2 -> V_2 = NULL ;
}
for ( V_43 = 0 ; V_43 < V_14 -> V_19 . V_88 ; V_43 ++ ) {
struct V_5 * V_6 = V_2 -> V_89 [ V_43 ] ;
if ( ! V_6 )
continue;
V_6 -> V_2 -> V_2 = V_2 ;
F_64 ( V_2 -> V_90 [ V_43 ] , V_6 -> V_2 ) ;
V_6 -> V_2 -> V_2 = NULL ;
}
}
int F_65 ( struct V_5 * V_6 ,
struct V_12 * V_9 ,
struct V_106 * V_79 ,
int V_107 , int V_108 ,
unsigned int V_109 , unsigned int V_110 ,
T_1 V_70 , T_1 V_72 ,
T_1 V_111 , T_1 V_112 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
V_2 = F_66 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = F_67 ( V_9 ) ;
V_115:
V_4 = F_68 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_92;
}
V_27 = F_69 ( V_4 , V_9 ) ;
if ( V_27 != 0 )
goto V_92;
F_70 ( V_4 , V_79 ) ;
V_4 -> V_107 = V_107 ;
V_4 -> V_108 = V_108 ;
V_4 -> V_110 = V_110 ;
V_4 -> V_109 = V_109 ;
V_4 -> V_70 = V_70 ;
V_4 -> V_72 = V_72 ;
V_4 -> V_112 = V_112 ;
V_4 -> V_111 = V_111 ;
if ( V_6 == V_9 -> V_116 )
V_2 -> V_81 = true ;
V_27 = F_71 ( V_2 ) ;
if ( V_27 != 0 )
goto V_92;
return 0 ;
V_92:
if ( V_27 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_27 ;
V_118:
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
V_6 -> V_119 = V_6 -> V_79 ;
goto V_115;
}
int F_74 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
if ( ! V_6 -> V_9 )
return 0 ;
V_2 = F_66 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = F_67 ( V_6 -> V_9 ) ;
V_115:
V_4 = F_68 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_92;
}
if ( V_4 -> V_9 && ( V_6 == V_6 -> V_9 -> V_116 ) )
V_4 -> V_2 -> V_81 = true ;
V_27 = F_75 ( V_6 , V_4 ) ;
if ( V_27 != 0 )
goto V_92;
V_27 = F_71 ( V_2 ) ;
if ( V_27 != 0 )
goto V_92;
return 0 ;
V_92:
if ( V_27 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_27 ;
V_118:
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
V_6 -> V_119 = V_6 -> V_79 ;
goto V_115;
}
int F_75 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
int V_27 ;
V_27 = F_69 ( V_4 , NULL ) ;
if ( V_27 != 0 )
return V_27 ;
F_70 ( V_4 , NULL ) ;
V_4 -> V_107 = 0 ;
V_4 -> V_108 = 0 ;
V_4 -> V_110 = 0 ;
V_4 -> V_109 = 0 ;
V_4 -> V_70 = 0 ;
V_4 -> V_72 = 0 ;
V_4 -> V_112 = 0 ;
V_4 -> V_111 = 0 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
struct V_13 * V_14 = V_121 -> V_9 -> V_14 ;
struct V_12 * V_9 ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_25 * V_42 ;
int V_27 , V_43 , V_122 ;
V_27 = F_77 ( & V_14 -> V_19 . V_22 ,
V_2 -> V_114 ) ;
if ( V_27 )
return V_27 ;
for ( V_43 = 0 ; V_43 < V_121 -> V_52 ; V_43 ++ ) {
V_42 = F_13 ( V_2 ,
V_121 -> V_37 [ V_43 ] ) ;
if ( F_10 ( V_42 ) )
return F_11 ( V_42 ) ;
}
F_18 (state, crtc, crtc_state, i) {
V_27 = F_25 ( V_2 , V_9 ) ;
if ( V_27 )
return V_27 ;
}
F_20 (state, connector, conn_state, i) {
if ( V_42 -> V_9 == V_121 -> V_9 ) {
V_27 = F_14 ( V_42 ,
NULL ) ;
if ( V_27 )
return V_27 ;
}
for ( V_122 = 0 ; V_122 < V_121 -> V_52 ; V_122 ++ ) {
if ( V_121 -> V_37 [ V_122 ] == V_21 ) {
V_27 = F_14 ( V_42 ,
V_121 -> V_9 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
}
F_18 (state, crtc, crtc_state, i) {
if ( V_9 == V_121 -> V_9 )
continue;
if ( ! F_27 ( V_2 , V_9 ) ) {
V_27 = F_78 ( V_8 ,
NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_8 -> V_53 = false ;
}
}
return 0 ;
}
int F_79 ( struct V_120 * V_121 )
{
struct V_1 * V_2 ;
struct V_12 * V_9 = V_121 -> V_9 ;
int V_27 = 0 ;
V_2 = F_66 ( V_9 -> V_14 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = F_67 ( V_9 ) ;
V_115:
V_27 = F_80 ( V_121 , V_2 ) ;
if ( V_27 != 0 )
goto V_92;
V_27 = F_71 ( V_2 ) ;
if ( V_27 != 0 )
goto V_92;
return 0 ;
V_92:
if ( V_27 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_27 ;
V_118:
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
V_9 -> V_67 -> V_119 = V_9 -> V_67 -> V_79 ;
goto V_115;
}
int F_80 ( struct V_120 * V_121 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_3 * V_123 ;
struct V_12 * V_9 = V_121 -> V_9 ;
int V_124 , V_125 ;
int V_27 ;
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) )
return F_11 ( V_8 ) ;
V_123 = F_68 ( V_2 , V_9 -> V_67 ) ;
if ( F_10 ( V_123 ) )
return F_11 ( V_123 ) ;
if ( ! V_121 -> V_46 ) {
F_3 ( V_121 -> V_79 ) ;
F_3 ( V_121 -> V_52 ) ;
V_27 = F_81 ( V_8 , NULL ) ;
if ( V_27 != 0 )
return V_27 ;
V_8 -> V_53 = false ;
V_27 = F_69 ( V_123 , NULL ) ;
if ( V_27 != 0 )
return V_27 ;
F_70 ( V_123 , NULL ) ;
goto V_77;
}
F_3 ( ! V_121 -> V_79 ) ;
F_3 ( ! V_121 -> V_52 ) ;
V_27 = F_81 ( V_8 , V_121 -> V_46 ) ;
if ( V_27 != 0 )
return V_27 ;
V_8 -> V_53 = true ;
V_27 = F_69 ( V_123 , V_9 ) ;
if ( V_27 != 0 )
return V_27 ;
F_82 ( V_121 -> V_46 , & V_124 , & V_125 ) ;
F_70 ( V_123 , V_121 -> V_79 ) ;
V_123 -> V_107 = 0 ;
V_123 -> V_108 = 0 ;
V_123 -> V_110 = V_125 ;
V_123 -> V_109 = V_124 ;
V_123 -> V_70 = V_121 -> V_69 << 16 ;
V_123 -> V_72 = V_121 -> V_71 << 16 ;
if ( V_123 -> V_126 & ( F_83 ( V_127 ) | F_83 ( V_128 ) ) ) {
V_123 -> V_112 = V_124 << 16 ;
V_123 -> V_111 = V_125 << 16 ;
} else {
V_123 -> V_112 = V_125 << 16 ;
V_123 -> V_111 = V_124 << 16 ;
}
V_77:
V_27 = F_76 ( V_2 , V_121 ) ;
if ( V_27 )
return V_27 ;
return 0 ;
}
int
F_84 ( struct V_12 * V_9 ,
struct V_63 * V_129 ,
T_2 V_130 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_27 = 0 ;
V_2 = F_66 ( V_9 -> V_14 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = V_9 -> V_14 -> V_19 . V_114 ;
V_115:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_92;
}
V_27 = F_85 ( V_9 , V_8 ,
V_129 , V_130 ) ;
if ( V_27 )
goto V_92;
V_27 = F_71 ( V_2 ) ;
if ( V_27 != 0 )
goto V_92;
return 0 ;
V_92:
if ( V_27 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_27 ;
V_118:
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
goto V_115;
}
int
F_86 ( struct V_5 * V_6 ,
struct V_63 * V_129 ,
T_2 V_130 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
V_2 = F_66 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = V_6 -> V_14 -> V_19 . V_114 ;
V_115:
V_4 = F_68 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_92;
}
V_27 = F_87 ( V_6 , V_4 ,
V_129 , V_130 ) ;
if ( V_27 )
goto V_92;
V_27 = F_71 ( V_2 ) ;
if ( V_27 != 0 )
goto V_92;
return 0 ;
V_92:
if ( V_27 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_27 ;
V_118:
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
goto V_115;
}
int
F_88 ( struct V_20 * V_21 ,
struct V_63 * V_129 ,
T_2 V_130 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
int V_27 = 0 ;
V_2 = F_66 ( V_21 -> V_14 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = V_21 -> V_14 -> V_19 . V_114 ;
V_115:
V_26 = F_13 ( V_2 , V_21 ) ;
if ( F_10 ( V_26 ) ) {
V_27 = F_11 ( V_26 ) ;
goto V_92;
}
V_27 = F_89 ( V_21 , V_26 ,
V_129 , V_130 ) ;
if ( V_27 )
goto V_92;
V_27 = F_71 ( V_2 ) ;
if ( V_27 != 0 )
goto V_92;
return 0 ;
V_92:
if ( V_27 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_27 ;
V_118:
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
goto V_115;
}
int F_90 ( struct V_12 * V_9 ,
struct V_106 * V_79 ,
struct V_131 * V_132 ,
T_1 V_133 )
{
struct V_5 * V_6 = V_9 -> V_67 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_7 * V_8 ;
int V_27 = 0 ;
if ( V_133 & V_134 )
return - V_41 ;
V_2 = F_66 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = F_67 ( V_9 ) ;
V_115:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_92;
}
V_8 -> V_132 = V_132 ;
V_4 = F_68 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_92;
}
V_27 = F_69 ( V_4 , V_9 ) ;
if ( V_27 != 0 )
goto V_92;
F_70 ( V_4 , V_79 ) ;
V_27 = F_91 ( V_2 ) ;
if ( V_27 != 0 )
goto V_92;
return 0 ;
V_92:
if ( V_27 == - V_117 )
goto V_118;
F_59 ( V_2 ) ;
return V_27 ;
V_118:
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
V_6 -> V_119 = V_6 -> V_79 ;
goto V_115;
}
int F_92 ( struct V_20 * V_21 ,
int V_46 )
{
struct V_17 * V_18 = & V_21 -> V_14 -> V_19 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_12 * V_9 ;
struct V_20 * V_135 ;
int V_27 ;
bool V_53 = false ;
int V_136 = V_21 -> V_61 ;
if ( V_46 != V_66 )
V_46 = V_62 ;
V_21 -> V_61 = V_46 ;
V_9 = V_21 -> V_2 -> V_9 ;
if ( ! V_9 )
return 0 ;
V_2 = F_66 ( V_21 -> V_14 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_114 = F_67 ( V_9 ) ;
V_115:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_92;
}
F_3 ( ! F_5 ( & V_18 -> V_22 ) ) ;
F_6 (tmp_connector, connector->dev) {
if ( V_135 -> V_2 -> V_9 != V_9 )
continue;
if ( V_135 -> V_61 == V_66 ) {
V_53 = true ;
break;
}
}
V_8 -> V_53 = V_53 ;
V_27 = F_71 ( V_2 ) ;
if ( V_27 != 0 )
goto V_92;
return 0 ;
V_92:
if ( V_27 == - V_117 )
goto V_118;
V_21 -> V_61 = V_136 ;
F_59 ( V_2 ) ;
return V_27 ;
V_118:
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
goto V_115;
}
void F_93 ( struct V_12 * V_9 )
{
if ( V_9 -> V_2 && V_9 -> V_2 -> V_137 )
F_94 ( V_9 -> V_2 -> V_137 ) ;
F_95 ( V_9 -> V_2 ) ;
V_9 -> V_2 = F_96 ( sizeof( * V_9 -> V_2 ) , V_138 ) ;
if ( V_9 -> V_2 )
V_9 -> V_2 -> V_9 = V_9 ;
}
void F_97 ( struct V_12 * V_9 ,
struct V_7 * V_2 )
{
memcpy ( V_2 , V_9 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_137 )
F_98 ( V_2 -> V_137 ) ;
V_2 -> V_44 = false ;
V_2 -> V_54 = false ;
V_2 -> V_11 = false ;
V_2 -> V_31 = false ;
V_2 -> V_132 = NULL ;
}
struct V_7 *
F_99 ( struct V_12 * V_9 )
{
struct V_7 * V_2 ;
if ( F_3 ( ! V_9 -> V_2 ) )
return NULL ;
V_2 = F_100 ( sizeof( * V_2 ) , V_138 ) ;
if ( V_2 )
F_97 ( V_9 , V_2 ) ;
return V_2 ;
}
void F_101 ( struct V_12 * V_9 ,
struct V_7 * V_2 )
{
if ( V_2 -> V_137 )
F_94 ( V_2 -> V_137 ) ;
}
void F_102 ( struct V_12 * V_9 ,
struct V_7 * V_2 )
{
F_101 ( V_9 , V_2 ) ;
F_95 ( V_2 ) ;
}
void F_103 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 && V_6 -> V_2 -> V_79 )
F_104 ( V_6 -> V_2 -> V_79 ) ;
F_95 ( V_6 -> V_2 ) ;
V_6 -> V_2 = F_96 ( sizeof( * V_6 -> V_2 ) , V_138 ) ;
if ( V_6 -> V_2 )
V_6 -> V_2 -> V_6 = V_6 ;
}
void F_105 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
memcpy ( V_2 , V_6 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_79 )
F_106 ( V_2 -> V_79 ) ;
}
struct V_3 *
F_107 ( struct V_5 * V_6 )
{
struct V_3 * V_2 ;
if ( F_3 ( ! V_6 -> V_2 ) )
return NULL ;
V_2 = F_100 ( sizeof( * V_2 ) , V_138 ) ;
if ( V_2 )
F_105 ( V_6 , V_2 ) ;
return V_2 ;
}
void F_108 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
if ( V_2 -> V_79 )
F_104 ( V_2 -> V_79 ) ;
}
void F_109 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
F_108 ( V_6 , V_2 ) ;
F_95 ( V_2 ) ;
}
void F_110 ( struct V_20 * V_21 )
{
F_95 ( V_21 -> V_2 ) ;
V_21 -> V_2 = F_96 ( sizeof( * V_21 -> V_2 ) , V_138 ) ;
if ( V_21 -> V_2 )
V_21 -> V_2 -> V_21 = V_21 ;
}
void
F_111 ( struct V_20 * V_21 ,
struct V_25 * V_2 )
{
memcpy ( V_2 , V_21 -> V_2 , sizeof( * V_2 ) ) ;
}
struct V_25 *
F_112 ( struct V_20 * V_21 )
{
struct V_25 * V_2 ;
if ( F_3 ( ! V_21 -> V_2 ) )
return NULL ;
V_2 = F_100 ( sizeof( * V_2 ) , V_138 ) ;
if ( V_2 )
F_111 ( V_21 , V_2 ) ;
return V_2 ;
}
struct V_1 *
F_113 ( struct V_13 * V_14 ,
struct V_139 * V_140 )
{
struct V_1 * V_2 ;
struct V_20 * V_141 ;
struct V_5 * V_6 ;
struct V_12 * V_9 ;
int V_142 = 0 ;
V_2 = F_66 ( V_14 ) ;
if ( ! V_2 )
return F_114 ( - V_113 ) ;
V_2 -> V_114 = V_140 ;
F_115 (crtc, dev) {
struct V_7 * V_8 ;
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_142 = F_11 ( V_8 ) ;
goto free;
}
}
F_116 (plane, dev) {
struct V_3 * V_4 ;
V_4 = F_68 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_142 = F_11 ( V_4 ) ;
goto free;
}
}
F_6 (conn, dev) {
struct V_25 * V_42 ;
V_42 = F_13 ( V_2 , V_141 ) ;
if ( F_10 ( V_42 ) ) {
V_142 = F_11 ( V_42 ) ;
goto free;
}
}
V_2 -> V_114 = NULL ;
free:
if ( V_142 < 0 ) {
F_59 ( V_2 ) ;
V_2 = F_114 ( V_142 ) ;
}
return V_2 ;
}
void
F_117 ( struct V_20 * V_21 ,
struct V_25 * V_2 )
{
}
void F_118 ( struct V_20 * V_21 ,
struct V_25 * V_2 )
{
F_117 ( V_21 , V_2 ) ;
F_95 ( V_2 ) ;
}
