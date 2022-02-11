static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
if ( V_4 -> V_10 ) {
V_9 = F_2 ( V_2 ,
V_4 -> V_10 ) ;
if ( F_3 ( ! V_9 ) )
return;
V_9 -> V_11 = true ;
}
if ( V_5 -> V_10 ) {
V_9 = F_2 ( V_2 , V_5 -> V_10 ) ;
if ( F_3 ( ! V_9 ) )
return;
V_9 -> V_11 = true ;
}
}
static int F_4 ( struct V_1 * V_2 ,
bool V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 V_18 ;
struct V_19 * V_20 ;
unsigned V_21 = 0 ;
int V_22 , V_23 = 0 ;
F_5 (state, connector, new_conn_state, i) {
const struct V_24 * V_25 = V_16 -> V_26 ;
struct V_19 * V_27 ;
if ( ! V_14 -> V_10 )
continue;
if ( V_25 -> V_28 )
V_27 = V_25 -> V_28 ( V_16 , V_14 ) ;
else if ( V_25 -> V_29 )
V_27 = V_25 -> V_29 ( V_16 ) ;
else
V_27 = F_6 ( V_16 ) ;
if ( V_27 ) {
if ( V_21 & ( 1 << F_7 ( V_27 ) ) ) {
F_8 ( L_1 ,
V_27 -> V_30 . V_31 , V_27 -> V_32 ,
V_16 -> V_30 . V_31 , V_16 -> V_32 ) ;
return - V_33 ;
}
V_21 |= 1 << F_7 ( V_27 ) ;
}
}
if ( ! V_21 )
return 0 ;
F_9 ( V_2 -> V_34 , & V_18 ) ;
F_10 (connector, &conn_iter) {
struct V_8 * V_9 ;
if ( F_11 ( V_2 , V_16 ) )
continue;
V_20 = V_16 -> V_2 -> V_29 ;
if ( ! V_20 || ! ( V_21 & ( 1 << F_7 ( V_20 ) ) ) )
continue;
if ( ! V_12 ) {
F_8 ( L_2 ,
V_20 -> V_30 . V_31 , V_20 -> V_32 ,
V_16 -> V_2 -> V_10 -> V_30 . V_31 ,
V_16 -> V_2 -> V_10 -> V_32 ,
V_16 -> V_30 . V_31 , V_16 -> V_32 ) ;
V_23 = - V_33 ;
goto V_35;
}
V_14 = F_12 ( V_2 , V_16 ) ;
if ( F_13 ( V_14 ) ) {
V_23 = F_14 ( V_14 ) ;
goto V_35;
}
F_8 ( L_3 ,
V_20 -> V_30 . V_31 , V_20 -> V_32 ,
V_14 -> V_10 -> V_30 . V_31 , V_14 -> V_10 -> V_32 ,
V_16 -> V_30 . V_31 , V_16 -> V_32 ) ;
V_9 = F_2 ( V_2 , V_14 -> V_10 ) ;
V_23 = F_15 ( V_14 , NULL ) ;
if ( V_23 )
goto V_35;
if ( ! V_9 -> V_36 ) {
V_23 = F_16 ( V_9 ,
NULL ) ;
if ( V_23 < 0 )
goto V_35;
V_9 -> V_37 = false ;
}
}
V_35:
F_17 ( & V_18 ) ;
return V_23 ;
}
static void
F_18 ( struct V_1 * V_2 ,
struct V_13 * V_38 ,
struct V_19 * V_20 )
{
struct V_8 * V_9 ;
struct V_39 * V_10 ;
if ( V_38 -> V_29 ) {
V_10 = V_38 -> V_16 -> V_2 -> V_10 ;
F_3 ( ! V_10 && V_20 != V_38 -> V_29 ) ;
if ( V_10 ) {
V_9 = F_2 ( V_2 , V_10 ) ;
V_9 -> V_21 &=
~ ( 1 << F_7 ( V_38 -> V_29 ) ) ;
}
}
if ( V_20 ) {
V_10 = V_38 -> V_10 ;
F_3 ( ! V_10 ) ;
if ( V_10 ) {
V_9 = F_2 ( V_2 , V_10 ) ;
V_9 -> V_21 |=
1 << F_7 ( V_20 ) ;
}
}
V_38 -> V_29 = V_20 ;
}
static void
F_19 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_8 * V_9 ;
struct V_15 * V_16 ;
struct V_13 * V_40 , * V_41 ;
int V_22 ;
F_20 (state, connector, old_connector_state, new_connector_state, i) {
struct V_39 * V_42 ;
if ( V_41 -> V_29 != V_20 )
continue;
V_42 = V_40 -> V_10 ;
F_8 ( L_4 ,
V_20 -> V_30 . V_31 , V_20 -> V_32 ,
V_42 -> V_30 . V_31 , V_42 -> V_32 ) ;
F_18 ( V_2 , V_41 , NULL ) ;
V_9 = F_2 ( V_2 , V_42 ) ;
V_9 -> V_43 = true ;
return;
}
}
static int
F_21 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_13 * V_40 ,
struct V_13 * V_41 )
{
const struct V_24 * V_25 ;
struct V_19 * V_27 ;
struct V_8 * V_9 ;
F_8 ( L_5 ,
V_16 -> V_30 . V_31 ,
V_16 -> V_32 ) ;
if ( V_40 -> V_10 != V_41 -> V_10 ) {
if ( V_40 -> V_10 ) {
V_9 = F_2 ( V_2 , V_40 -> V_10 ) ;
V_9 -> V_43 = true ;
}
if ( V_41 -> V_10 ) {
V_9 = F_2 ( V_2 , V_41 -> V_10 ) ;
V_9 -> V_43 = true ;
}
}
if ( ! V_41 -> V_10 ) {
F_8 ( L_6 ,
V_16 -> V_30 . V_31 ,
V_16 -> V_32 ) ;
F_18 ( V_2 , V_41 , NULL ) ;
return 0 ;
}
V_25 = V_16 -> V_26 ;
if ( V_25 -> V_28 )
V_27 = V_25 -> V_28 ( V_16 ,
V_41 ) ;
else if ( V_25 -> V_29 )
V_27 = V_25 -> V_29 ( V_16 ) ;
else
V_27 = F_6 ( V_16 ) ;
if ( ! V_27 ) {
F_8 ( L_7 ,
V_16 -> V_30 . V_31 ,
V_16 -> V_32 ) ;
return - V_33 ;
}
if ( ! F_22 ( V_27 , V_41 -> V_10 ) ) {
F_8 ( L_8 ,
V_27 -> V_30 . V_31 ,
V_27 -> V_32 ,
V_41 -> V_10 -> V_30 . V_31 ,
V_41 -> V_10 -> V_32 ) ;
return - V_33 ;
}
if ( V_27 == V_41 -> V_29 ) {
F_18 ( V_2 , V_41 , V_27 ) ;
F_8 ( L_9 ,
V_16 -> V_30 . V_31 ,
V_16 -> V_32 ,
V_27 -> V_30 . V_31 ,
V_27 -> V_32 ,
V_41 -> V_10 -> V_30 . V_31 ,
V_41 -> V_10 -> V_32 ) ;
return 0 ;
}
F_19 ( V_2 , V_27 ) ;
F_18 ( V_2 , V_41 , V_27 ) ;
V_9 = F_2 ( V_2 , V_41 -> V_10 ) ;
V_9 -> V_43 = true ;
F_8 ( L_10 ,
V_16 -> V_30 . V_31 ,
V_16 -> V_32 ,
V_27 -> V_30 . V_31 ,
V_27 -> V_32 ,
V_41 -> V_10 -> V_30 . V_31 ,
V_41 -> V_10 -> V_32 ) ;
return 0 ;
}
static int
F_23 ( struct V_1 * V_2 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
int V_22 ;
int V_23 ;
F_24 (state, crtc, new_crtc_state, i) {
if ( ! V_44 -> V_45 &&
! V_44 -> V_43 )
continue;
F_25 ( & V_44 -> V_46 , & V_44 -> V_47 ) ;
}
F_5 (state, connector, new_conn_state, i) {
const struct V_48 * V_25 ;
struct V_19 * V_20 ;
F_3 ( ! ! V_14 -> V_29 != ! ! V_14 -> V_10 ) ;
if ( ! V_14 -> V_10 || ! V_14 -> V_29 )
continue;
V_44 =
F_2 ( V_2 , V_14 -> V_10 ) ;
V_20 = V_14 -> V_29 ;
V_25 = V_20 -> V_26 ;
V_23 = F_26 ( V_20 -> V_49 , & V_44 -> V_47 ,
& V_44 -> V_46 ) ;
if ( ! V_23 ) {
F_8 ( L_11 ) ;
return - V_33 ;
}
if ( V_25 && V_25 -> V_50 ) {
V_23 = V_25 -> V_50 ( V_20 , V_44 ,
V_14 ) ;
if ( V_23 ) {
F_8 ( L_12 ,
V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
return V_23 ;
}
} else if ( V_25 && V_25 -> F_23 ) {
V_23 = V_25 -> F_23 ( V_20 , & V_44 -> V_47 ,
& V_44 -> V_46 ) ;
if ( ! V_23 ) {
F_8 ( L_13 ,
V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
return - V_33 ;
}
}
}
F_24 (state, crtc, new_crtc_state, i) {
const struct V_51 * V_25 ;
if ( ! V_44 -> V_52 )
continue;
if ( ! V_44 -> V_45 &&
! V_44 -> V_43 )
continue;
V_25 = V_10 -> V_26 ;
if ( ! V_25 -> F_23 )
continue;
V_23 = V_25 -> F_23 ( V_10 , & V_44 -> V_47 ,
& V_44 -> V_46 ) ;
if ( ! V_23 ) {
F_8 ( L_14 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
return - V_33 ;
}
}
return 0 ;
}
static enum V_53 F_27 ( struct V_15 * V_16 ,
struct V_19 * V_20 ,
struct V_39 * V_10 ,
struct V_54 * V_47 )
{
enum V_53 V_23 ;
V_23 = F_28 ( V_20 , V_47 ) ;
if ( V_23 != V_55 ) {
F_8 ( L_15 ,
V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
return V_23 ;
}
V_23 = F_29 ( V_20 -> V_49 , V_47 ) ;
if ( V_23 != V_55 ) {
F_8 ( L_16 ) ;
return V_23 ;
}
V_23 = F_30 ( V_10 , V_47 ) ;
if ( V_23 != V_55 ) {
F_8 ( L_17 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
return V_23 ;
}
return V_23 ;
}
static int
F_31 ( struct V_1 * V_2 )
{
struct V_13 * V_38 ;
struct V_15 * V_16 ;
int V_22 ;
F_5 (state, connector, conn_state, i) {
struct V_19 * V_20 = V_38 -> V_29 ;
struct V_39 * V_10 = V_38 -> V_10 ;
struct V_8 * V_9 ;
enum V_53 V_56 ;
struct V_54 * V_47 ;
if ( ! V_10 || ! V_20 )
continue;
V_9 = F_2 ( V_2 , V_10 ) ;
if ( ! V_9 )
continue;
if ( ! V_9 -> V_45 && ! V_9 -> V_43 )
continue;
V_47 = & V_9 -> V_47 ;
V_56 = F_27 ( V_16 , V_20 , V_10 , V_47 ) ;
if ( V_56 != V_55 )
return - V_33 ;
}
return 0 ;
}
int
F_32 ( struct V_57 * V_34 ,
struct V_1 * V_2 )
{
struct V_39 * V_10 ;
struct V_8 * V_58 , * V_44 ;
struct V_15 * V_16 ;
struct V_13 * V_40 , * V_41 ;
int V_22 , V_23 ;
unsigned V_59 = 0 ;
F_33 (state, crtc, old_crtc_state, new_crtc_state, i) {
bool V_60 =
! ! V_44 -> V_36 ;
F_3 ( ! F_34 ( & V_10 -> V_61 ) ) ;
if ( ! F_35 ( & V_58 -> V_47 , & V_44 -> V_47 ) ) {
F_8 ( L_18 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
V_44 -> V_45 = true ;
}
if ( V_58 -> V_52 != V_44 -> V_52 ) {
F_8 ( L_19 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
V_44 -> V_45 = true ;
V_44 -> V_43 = true ;
}
if ( V_58 -> V_37 != V_44 -> V_37 ) {
F_8 ( L_20 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
V_44 -> V_62 = true ;
}
if ( V_44 -> V_52 != V_60 ) {
F_8 ( L_21 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
return - V_33 ;
}
}
V_23 = F_4 ( V_2 , false ) ;
if ( V_23 )
return V_23 ;
F_20 (state, connector, old_connector_state, new_connector_state, i) {
const struct V_24 * V_25 = V_16 -> V_26 ;
F_3 ( ! F_34 ( & V_34 -> V_63 . V_64 ) ) ;
V_23 = F_21 ( V_2 , V_16 ,
V_40 ,
V_41 ) ;
if ( V_23 )
return V_23 ;
if ( V_40 -> V_10 ) {
V_44 = F_2 ( V_2 ,
V_40 -> V_10 ) ;
if ( V_40 -> V_65 !=
V_41 -> V_65 )
V_44 -> V_43 = true ;
}
if ( V_25 -> V_50 )
V_23 = V_25 -> V_50 ( V_16 , V_41 ) ;
if ( V_23 )
return V_23 ;
V_59 += F_36 ( V_22 ) ;
}
F_33 (state, crtc, old_crtc_state, new_crtc_state, i) {
if ( ! F_37 ( V_44 ) )
continue;
F_8 ( L_22 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ,
V_44 -> V_52 ? 'y' : 'n' ,
V_44 -> V_37 ? 'y' : 'n' ) ;
V_23 = F_38 ( V_2 , V_10 ) ;
if ( V_23 != 0 )
return V_23 ;
V_23 = F_39 ( V_2 , V_10 ) ;
if ( V_23 != 0 )
return V_23 ;
}
F_20 (state, connector, old_connector_state, new_connector_state, i) {
const struct V_24 * V_25 = V_16 -> V_26 ;
if ( V_59 & F_36 ( V_22 ) )
continue;
if ( V_25 -> V_50 )
V_23 = V_25 -> V_50 ( V_16 , V_41 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_31 ( V_2 ) ;
if ( V_23 )
return V_23 ;
return F_23 ( V_2 ) ;
}
int
F_40 ( struct V_57 * V_34 ,
struct V_1 * V_2 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_6 * V_7 ;
struct V_3 * V_66 , * V_4 ;
int V_22 , V_23 = 0 ;
F_41 (state, plane, old_plane_state, new_plane_state, i) {
const struct V_67 * V_25 ;
F_3 ( ! F_34 ( & V_7 -> V_61 ) ) ;
V_25 = V_7 -> V_26 ;
F_1 ( V_2 , V_4 , V_66 , V_7 ) ;
if ( ! V_25 || ! V_25 -> V_50 )
continue;
V_23 = V_25 -> V_50 ( V_7 , V_66 ) ;
if ( V_23 ) {
F_8 ( L_23 ,
V_7 -> V_30 . V_31 , V_7 -> V_32 ) ;
return V_23 ;
}
}
F_24 (state, crtc, new_crtc_state, i) {
const struct V_51 * V_25 ;
V_25 = V_10 -> V_26 ;
if ( ! V_25 || ! V_25 -> V_50 )
continue;
V_23 = V_25 -> V_50 ( V_10 , V_44 ) ;
if ( V_23 ) {
F_8 ( L_24 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
return V_23 ;
}
}
return V_23 ;
}
int F_42 ( struct V_57 * V_34 ,
struct V_1 * V_2 )
{
int V_23 ;
V_23 = F_32 ( V_34 , V_2 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_40 ( V_34 , V_2 ) ;
if ( V_23 )
return V_23 ;
if ( V_2 -> V_68 )
V_2 -> V_69 = ! F_43 ( V_34 , V_2 ) ;
return V_23 ;
}
static void
F_44 ( struct V_57 * V_34 , struct V_1 * V_70 )
{
struct V_15 * V_16 ;
struct V_13 * V_71 , * V_14 ;
struct V_39 * V_10 ;
struct V_8 * V_58 , * V_44 ;
int V_22 ;
F_20 (old_state, connector, old_conn_state, new_conn_state, i) {
const struct V_48 * V_25 ;
struct V_19 * V_20 ;
if ( ! V_71 -> V_10 )
continue;
V_58 = F_45 ( V_70 , V_71 -> V_10 ) ;
if ( ! V_58 -> V_37 ||
! F_37 ( V_71 -> V_10 -> V_2 ) )
continue;
V_20 = V_71 -> V_29 ;
if ( F_3 ( ! V_20 ) )
continue;
V_25 = V_20 -> V_26 ;
F_8 ( L_25 ,
V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
F_46 ( V_20 -> V_49 ) ;
if ( V_25 ) {
if ( V_14 -> V_10 && V_25 -> V_72 )
V_25 -> V_72 ( V_20 ) ;
else if ( V_25 -> V_73 )
V_25 -> V_73 ( V_20 ) ;
else if ( V_25 -> V_74 )
V_25 -> V_74 ( V_20 , V_75 ) ;
}
F_47 ( V_20 -> V_49 ) ;
}
F_33 (old_state, crtc, old_crtc_state, new_crtc_state, i) {
const struct V_51 * V_25 ;
if ( ! F_37 ( V_44 ) )
continue;
if ( ! V_58 -> V_37 )
continue;
V_25 = V_10 -> V_26 ;
F_8 ( L_26 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
if ( V_44 -> V_52 && V_25 -> V_72 )
V_25 -> V_72 ( V_10 ) ;
else if ( V_25 -> V_76 )
V_25 -> V_76 ( V_10 , V_58 ) ;
else if ( V_25 -> V_73 )
V_25 -> V_73 ( V_10 ) ;
else
V_25 -> V_74 ( V_10 , V_75 ) ;
}
}
void
F_48 ( struct V_57 * V_34 ,
struct V_1 * V_70 )
{
struct V_15 * V_16 ;
struct V_13 * V_71 , * V_14 ;
struct V_39 * V_10 ;
struct V_8 * V_44 ;
int V_22 ;
F_20 (old_state, connector, old_conn_state, new_conn_state, i) {
if ( V_16 -> V_20 ) {
F_3 ( ! V_16 -> V_20 -> V_10 ) ;
V_16 -> V_20 -> V_10 = NULL ;
V_16 -> V_20 = NULL ;
}
V_10 = V_14 -> V_10 ;
if ( ( ! V_10 && V_71 -> V_10 ) ||
( V_10 && F_37 ( V_10 -> V_2 ) ) ) {
int V_47 = V_75 ;
if ( V_10 && V_10 -> V_2 -> V_37 )
V_47 = V_77 ;
V_16 -> V_74 = V_47 ;
}
}
F_5 (old_state, connector, new_conn_state, i) {
if ( ! V_14 -> V_10 )
continue;
if ( F_3 ( ! V_14 -> V_29 ) )
continue;
V_16 -> V_20 = V_14 -> V_29 ;
V_16 -> V_20 -> V_10 = V_14 -> V_10 ;
}
F_24 (old_state, crtc, new_crtc_state, i) {
struct V_6 * V_78 = V_10 -> V_78 ;
struct V_3 * V_66 ;
V_10 -> V_47 = V_44 -> V_47 ;
V_10 -> V_79 = V_44 -> V_52 ;
V_66 =
F_49 ( V_70 , V_78 ) ;
if ( V_66 && V_66 -> V_10 == V_10 ) {
V_10 -> V_80 = V_66 -> V_81 >> 16 ;
V_10 -> V_82 = V_66 -> V_83 >> 16 ;
}
if ( V_44 -> V_52 )
F_50 ( V_10 ,
& V_44 -> V_46 ) ;
}
}
static void
F_51 ( struct V_57 * V_34 , struct V_1 * V_70 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
int V_22 ;
F_24 (old_state, crtc, new_crtc_state, i) {
const struct V_51 * V_25 ;
if ( ! V_44 -> V_45 )
continue;
V_25 = V_10 -> V_26 ;
if ( V_44 -> V_52 && V_25 -> V_84 ) {
F_8 ( L_27 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
V_25 -> V_84 ( V_10 ) ;
}
}
F_5 (old_state, connector, new_conn_state, i) {
const struct V_48 * V_25 ;
struct V_19 * V_20 ;
struct V_54 * V_47 , * V_46 ;
if ( ! V_14 -> V_29 )
continue;
V_20 = V_14 -> V_29 ;
V_25 = V_20 -> V_26 ;
V_44 = V_14 -> V_10 -> V_2 ;
V_47 = & V_44 -> V_47 ;
V_46 = & V_44 -> V_46 ;
if ( ! V_44 -> V_45 )
continue;
F_8 ( L_28 ,
V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
if ( V_25 && V_25 -> V_85 ) {
V_25 -> V_85 ( V_20 , V_44 ,
V_14 ) ;
} else if ( V_25 && V_25 -> V_86 ) {
V_25 -> V_86 ( V_20 , V_47 , V_46 ) ;
}
F_52 ( V_20 -> V_49 , V_47 , V_46 ) ;
}
}
void F_53 ( struct V_57 * V_34 ,
struct V_1 * V_70 )
{
F_44 ( V_34 , V_70 ) ;
F_48 ( V_34 , V_70 ) ;
F_51 ( V_34 , V_70 ) ;
}
void F_54 ( struct V_57 * V_34 ,
struct V_1 * V_70 )
{
struct V_39 * V_10 ;
struct V_8 * V_58 ;
struct V_8 * V_44 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
int V_22 ;
F_33 (old_state, crtc, old_crtc_state, new_crtc_state, i) {
const struct V_51 * V_25 ;
if ( ! F_37 ( V_44 ) )
continue;
if ( ! V_44 -> V_37 )
continue;
V_25 = V_10 -> V_26 ;
if ( V_44 -> V_52 ) {
F_8 ( L_29 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
if ( V_25 -> V_87 )
V_25 -> V_87 ( V_10 , V_58 ) ;
else
V_25 -> V_88 ( V_10 ) ;
}
}
F_5 (old_state, connector, new_conn_state, i) {
const struct V_48 * V_25 ;
struct V_19 * V_20 ;
if ( ! V_14 -> V_29 )
continue;
if ( ! V_14 -> V_10 -> V_2 -> V_37 ||
! F_37 ( V_14 -> V_10 -> V_2 ) )
continue;
V_20 = V_14 -> V_29 ;
V_25 = V_20 -> V_26 ;
F_8 ( L_30 ,
V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
F_55 ( V_20 -> V_49 ) ;
if ( V_25 ) {
if ( V_25 -> V_52 )
V_25 -> V_52 ( V_20 ) ;
else if ( V_25 -> V_88 )
V_25 -> V_88 ( V_20 ) ;
}
F_56 ( V_20 -> V_49 ) ;
}
}
int F_57 ( struct V_57 * V_34 ,
struct V_1 * V_2 ,
bool V_89 )
{
struct V_6 * V_7 ;
struct V_3 * V_66 ;
int V_22 , V_23 ;
F_58 (state, plane, new_plane_state, i) {
if ( ! V_66 -> V_90 )
continue;
F_3 ( ! V_66 -> V_91 ) ;
V_23 = F_59 ( V_66 -> V_90 , V_89 ) ;
if ( V_23 )
return V_23 ;
F_60 ( V_66 -> V_90 ) ;
V_66 -> V_90 = NULL ;
}
return 0 ;
}
void
F_61 ( struct V_57 * V_34 ,
struct V_1 * V_70 )
{
struct V_39 * V_10 ;
struct V_8 * V_58 , * V_44 ;
int V_22 , V_23 ;
unsigned V_92 = 0 ;
if ( V_70 -> V_68 )
return;
F_33 (old_state, crtc, old_crtc_state, new_crtc_state, i) {
if ( ! V_44 -> V_37 || ! V_44 -> V_11 )
continue;
V_23 = F_62 ( V_10 ) ;
if ( V_23 != 0 )
continue;
V_92 |= F_63 ( V_10 ) ;
V_70 -> V_93 [ V_22 ] . V_94 = F_64 ( V_10 ) ;
}
F_65 (old_state, crtc, old_crtc_state, i) {
if ( ! ( V_92 & F_63 ( V_10 ) ) )
continue;
V_23 = F_66 ( V_34 -> V_95 [ V_22 ] . V_96 ,
V_70 -> V_93 [ V_22 ] . V_94 !=
F_64 ( V_10 ) ,
F_67 ( 50 ) ) ;
F_68 ( ! V_23 , L_31 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
F_69 ( V_10 ) ;
}
}
void F_70 ( struct V_57 * V_34 ,
struct V_1 * V_70 )
{
struct V_8 * V_97 ;
struct V_39 * V_10 ;
int V_22 ;
F_24 (old_state, crtc, unused, i) {
struct V_98 * V_88 = V_70 -> V_93 [ V_22 ] . V_88 ;
int V_23 ;
if ( ! V_88 )
continue;
V_23 = F_71 ( & V_88 -> V_99 , 10 * V_100 ) ;
if ( V_23 == 0 )
F_72 ( L_32 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
}
}
void F_73 ( struct V_1 * V_70 )
{
struct V_57 * V_34 = V_70 -> V_34 ;
F_53 ( V_34 , V_70 ) ;
F_74 ( V_34 , V_70 , 0 ) ;
F_54 ( V_34 , V_70 ) ;
F_75 ( V_70 ) ;
F_61 ( V_34 , V_70 ) ;
F_76 ( V_34 , V_70 ) ;
}
void F_77 ( struct V_1 * V_70 )
{
struct V_57 * V_34 = V_70 -> V_34 ;
F_53 ( V_34 , V_70 ) ;
F_54 ( V_34 , V_70 ) ;
F_74 ( V_34 , V_70 ,
V_101 ) ;
F_75 ( V_70 ) ;
F_61 ( V_34 , V_70 ) ;
F_76 ( V_34 , V_70 ) ;
}
static void F_78 ( struct V_1 * V_70 )
{
struct V_57 * V_34 = V_70 -> V_34 ;
const struct V_102 * V_25 ;
V_25 = V_34 -> V_63 . V_26 ;
F_57 ( V_34 , V_70 , false ) ;
F_79 ( V_70 ) ;
if ( V_25 && V_25 -> V_103 )
V_25 -> V_103 ( V_70 ) ;
else
F_73 ( V_70 ) ;
F_80 ( V_70 ) ;
F_81 ( V_70 ) ;
}
static void F_82 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = F_83 ( V_105 ,
struct V_1 ,
F_82 ) ;
F_78 ( V_2 ) ;
}
int F_43 ( struct V_57 * V_34 ,
struct V_1 * V_2 )
{
struct V_39 * V_10 ;
struct V_8 * V_9 ;
struct V_98 * V_88 ;
struct V_6 * V_106 , * V_7 = NULL ;
struct V_3 * V_107 , * V_5 = NULL ;
const struct V_67 * V_25 ;
int V_22 , V_108 , V_109 = 0 ;
F_24 (state, crtc, crtc_state, i) {
if ( F_37 ( V_9 ) )
return - V_33 ;
}
F_58 (state, __plane, __plane_state, i) {
V_109 ++ ;
V_7 = V_106 ;
V_5 = V_107 ;
}
if ( ! V_7 || V_109 != 1 )
return - V_33 ;
if ( ! V_5 -> V_10 )
return - V_33 ;
V_25 = V_7 -> V_26 ;
if ( ! V_25 -> V_110 )
return - V_33 ;
if ( V_5 -> V_90 )
return - V_33 ;
F_24 (state, crtc, crtc_state, i) {
if ( V_7 -> V_10 != V_10 )
continue;
F_84 ( & V_10 -> V_111 ) ;
V_88 = F_85 ( & V_10 -> V_112 ,
struct V_98 ,
V_113 ) ;
if ( ! V_88 ) {
F_86 ( & V_10 -> V_111 ) ;
continue;
}
F_86 ( & V_10 -> V_111 ) ;
if ( ! V_10 -> V_2 -> V_2 )
continue;
F_87 (crtc->state->state, __plane,
__plane_state, j) {
if ( V_106 == V_7 )
return - V_33 ;
}
}
return V_25 -> V_114 ( V_7 , V_5 ) ;
}
void F_88 ( struct V_57 * V_34 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_3 * V_5 ;
const struct V_67 * V_25 ;
int V_22 ;
F_58 (state, plane, plane_state, i) {
V_25 = V_7 -> V_26 ;
V_25 -> V_110 ( V_7 , V_5 ) ;
}
}
int F_89 ( struct V_57 * V_34 ,
struct V_1 * V_2 ,
bool V_115 )
{
int V_23 ;
if ( V_2 -> V_69 ) {
V_23 = F_90 ( V_34 , V_2 ) ;
if ( V_23 )
return V_23 ;
F_88 ( V_34 , V_2 ) ;
F_76 ( V_34 , V_2 ) ;
return 0 ;
}
V_23 = F_91 ( V_2 , V_115 ) ;
if ( V_23 )
return V_23 ;
F_92 ( & V_2 -> F_82 , F_82 ) ;
V_23 = F_90 ( V_34 , V_2 ) ;
if ( V_23 )
return V_23 ;
if ( ! V_115 ) {
V_23 = F_57 ( V_34 , V_2 , true ) ;
if ( V_23 )
goto V_116;
}
V_23 = F_93 ( V_2 , true ) ;
if ( V_23 )
goto V_116;
F_94 ( V_2 ) ;
if ( V_115 )
F_95 ( V_117 , & V_2 -> F_82 ) ;
else
F_78 ( V_2 ) ;
return 0 ;
V_116:
F_76 ( V_34 , V_2 ) ;
return V_23 ;
}
static int F_96 ( struct V_39 * V_10 , bool V_115 )
{
struct V_98 * V_88 , * V_118 = NULL ;
bool V_119 = true ;
int V_22 ;
long V_23 = 0 ;
F_84 ( & V_10 -> V_111 ) ;
V_22 = 0 ;
F_97 (commit, &crtc->commit_list, commit_entry) {
if ( V_22 == 0 ) {
V_119 = F_98 ( & V_88 -> V_99 ) ;
if ( ! V_119 && V_115 ) {
F_86 ( & V_10 -> V_111 ) ;
return - V_120 ;
}
} else if ( V_22 == 1 ) {
V_118 = V_88 ;
F_99 ( V_118 ) ;
break;
}
V_22 ++ ;
}
F_86 ( & V_10 -> V_111 ) ;
if ( ! V_118 )
return 0 ;
V_23 = F_100 ( & V_118 -> V_121 ,
10 * V_100 ) ;
if ( V_23 == 0 )
F_72 ( L_33 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
F_101 ( V_118 ) ;
return V_23 < 0 ? V_23 : 0 ;
}
static void F_102 ( struct V_122 * V_122 )
{
struct V_98 * V_88 = F_83 ( V_122 ,
F_103 ( * V_88 ) ,
V_99 ) ;
F_101 ( V_88 ) ;
}
int F_91 ( struct V_1 * V_2 ,
bool V_115 )
{
struct V_39 * V_10 ;
struct V_8 * V_58 , * V_44 ;
struct V_98 * V_88 ;
int V_22 , V_23 ;
F_33 (state, crtc, old_crtc_state, new_crtc_state, i) {
V_88 = F_104 ( sizeof( * V_88 ) , V_123 ) ;
if ( ! V_88 )
return - V_124 ;
F_105 ( & V_88 -> V_99 ) ;
F_105 ( & V_88 -> V_125 ) ;
F_105 ( & V_88 -> V_121 ) ;
F_106 ( & V_88 -> V_113 ) ;
F_107 ( & V_88 -> V_126 ) ;
V_88 -> V_10 = V_10 ;
V_2 -> V_93 [ V_22 ] . V_88 = V_88 ;
V_23 = F_96 ( V_10 , V_115 ) ;
if ( V_23 )
return V_23 ;
if ( ! V_58 -> V_37 && ! V_44 -> V_37 ) {
F_108 ( & V_88 -> V_99 ) ;
continue;
}
if ( V_2 -> V_68 ) {
F_108 ( & V_88 -> V_99 ) ;
continue;
}
if ( ! V_44 -> V_127 ) {
V_88 -> V_127 = F_104 ( sizeof( * V_88 -> V_127 ) ,
V_123 ) ;
if ( ! V_88 -> V_127 )
return - V_124 ;
V_44 -> V_127 = V_88 -> V_127 ;
}
V_44 -> V_127 -> V_30 . V_122 = & V_88 -> V_99 ;
V_44 -> V_127 -> V_30 . V_128 = F_102 ;
F_99 ( V_88 ) ;
}
return 0 ;
}
static struct V_98 * F_109 ( struct V_39 * V_10 )
{
struct V_98 * V_88 ;
int V_22 = 0 ;
F_97 (commit, &crtc->commit_list, commit_entry) {
if ( V_22 == 1 )
return V_88 ;
V_22 ++ ;
}
return NULL ;
}
void F_79 ( struct V_1 * V_70 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_98 * V_88 ;
int V_22 ;
long V_23 ;
F_24 (old_state, crtc, new_crtc_state, i) {
F_84 ( & V_10 -> V_111 ) ;
V_88 = F_109 ( V_10 ) ;
if ( V_88 )
F_99 ( V_88 ) ;
F_86 ( & V_10 -> V_111 ) ;
if ( ! V_88 )
continue;
V_23 = F_71 ( & V_88 -> V_125 ,
10 * V_100 ) ;
if ( V_23 == 0 )
F_72 ( L_34 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
V_23 = F_71 ( & V_88 -> V_99 ,
10 * V_100 ) ;
if ( V_23 == 0 )
F_72 ( L_32 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
F_101 ( V_88 ) ;
}
}
void F_75 ( struct V_1 * V_70 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_98 * V_88 ;
int V_22 ;
F_24 (old_state, crtc, new_crtc_state, i) {
V_88 = V_70 -> V_93 [ V_22 ] . V_88 ;
if ( ! V_88 )
continue;
F_3 ( V_44 -> V_127 ) ;
F_108 ( & V_88 -> V_125 ) ;
}
}
void F_80 ( struct V_1 * V_70 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_98 * V_88 ;
int V_22 ;
long V_23 ;
F_24 (old_state, crtc, new_crtc_state, i) {
V_88 = V_70 -> V_93 [ V_22 ] . V_88 ;
if ( F_3 ( ! V_88 ) )
continue;
F_108 ( & V_88 -> V_121 ) ;
F_3 ( ! F_98 ( & V_88 -> V_125 ) ) ;
if ( F_98 ( & V_88 -> V_99 ) )
goto V_129;
V_23 = F_71 ( & V_88 -> V_99 ,
10 * V_100 ) ;
if ( V_23 == 0 )
F_72 ( L_32 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
V_129:
F_84 ( & V_10 -> V_111 ) ;
F_110 ( & V_88 -> V_113 ) ;
F_86 ( & V_10 -> V_111 ) ;
}
}
int F_90 ( struct V_57 * V_34 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_3 * V_66 ;
int V_23 , V_22 , V_108 ;
F_58 (state, plane, new_plane_state, i) {
const struct V_67 * V_25 ;
V_25 = V_7 -> V_26 ;
if ( V_25 -> V_130 ) {
V_23 = V_25 -> V_130 ( V_7 , V_66 ) ;
if ( V_23 )
goto V_131;
}
}
return 0 ;
V_131:
F_58 (state, plane, new_plane_state, j) {
const struct V_67 * V_25 ;
if ( V_108 >= V_22 )
continue;
V_25 = V_7 -> V_26 ;
if ( V_25 -> V_132 )
V_25 -> V_132 ( V_7 , V_66 ) ;
}
return V_23 ;
}
static bool F_111 ( const struct V_3 * V_2 )
{
return V_2 -> V_10 && V_2 -> V_10 -> V_2 -> V_37 ;
}
void F_74 ( struct V_57 * V_34 ,
struct V_1 * V_70 ,
T_1 V_133 )
{
struct V_39 * V_10 ;
struct V_8 * V_58 , * V_44 ;
struct V_6 * V_7 ;
struct V_3 * V_4 , * V_66 ;
int V_22 ;
bool V_134 = V_133 & V_101 ;
bool V_135 = V_133 & V_136 ;
F_33 (old_state, crtc, old_crtc_state, new_crtc_state, i) {
const struct V_51 * V_25 ;
V_25 = V_10 -> V_26 ;
if ( ! V_25 || ! V_25 -> V_137 )
continue;
if ( V_134 && ! V_44 -> V_37 )
continue;
V_25 -> V_137 ( V_10 , V_58 ) ;
}
F_41 (old_state, plane, old_plane_state, new_plane_state, i) {
const struct V_67 * V_25 ;
bool V_138 ;
V_25 = V_7 -> V_26 ;
if ( ! V_25 )
continue;
V_138 = F_112 ( V_4 ,
V_66 ) ;
if ( V_134 ) {
if ( ! V_138 && ! F_111 ( V_66 ) )
continue;
if ( V_138 && ! F_111 ( V_4 ) )
continue;
}
if ( V_138 && V_25 -> V_76 ) {
struct V_8 * V_9 ;
V_9 = V_4 -> V_10 -> V_2 ;
if ( F_37 ( V_9 ) &&
V_135 )
continue;
V_25 -> V_76 ( V_7 , V_4 ) ;
} else if ( V_66 -> V_10 || V_138 ) {
V_25 -> V_139 ( V_7 , V_4 ) ;
}
}
F_33 (old_state, crtc, old_crtc_state, new_crtc_state, i) {
const struct V_51 * V_25 ;
V_25 = V_10 -> V_26 ;
if ( ! V_25 || ! V_25 -> V_140 )
continue;
if ( V_134 && ! V_44 -> V_37 )
continue;
V_25 -> V_140 ( V_10 , V_58 ) ;
}
}
void
F_113 ( struct V_8 * V_58 )
{
const struct V_51 * V_141 ;
struct V_39 * V_10 = V_58 -> V_10 ;
struct V_1 * V_70 = V_58 -> V_2 ;
struct V_6 * V_7 ;
unsigned V_142 ;
V_142 = V_58 -> V_142 ;
V_142 |= V_10 -> V_2 -> V_142 ;
V_141 = V_10 -> V_26 ;
if ( V_141 && V_141 -> V_137 )
V_141 -> V_137 ( V_10 , V_58 ) ;
F_114 (plane, crtc->dev, plane_mask) {
struct V_3 * V_4 =
F_115 ( V_70 , V_7 ) ;
const struct V_67 * V_143 ;
V_143 = V_7 -> V_26 ;
if ( ! V_4 || ! V_143 )
continue;
F_3 ( V_7 -> V_2 -> V_10 && V_7 -> V_2 -> V_10 != V_10 ) ;
if ( F_112 ( V_4 , V_7 -> V_2 ) &&
V_143 -> V_76 )
V_143 -> V_76 ( V_7 , V_4 ) ;
else if ( V_7 -> V_2 -> V_10 ||
F_112 ( V_4 , V_7 -> V_2 ) )
V_143 -> V_139 ( V_7 , V_4 ) ;
}
if ( V_141 && V_141 -> V_140 )
V_141 -> V_140 ( V_10 , V_58 ) ;
}
void
F_116 ( struct V_8 * V_58 ,
bool V_144 )
{
struct V_39 * V_10 = V_58 -> V_10 ;
const struct V_51 * V_141 =
V_10 -> V_26 ;
struct V_6 * V_7 ;
if ( V_144 && V_141 && V_141 -> V_137 )
V_141 -> V_137 ( V_10 , NULL ) ;
F_117 (plane, old_crtc_state) {
const struct V_67 * V_143 =
V_7 -> V_26 ;
if ( ! V_143 )
continue;
F_3 ( ! V_143 -> V_76 ) ;
if ( V_143 -> V_76 )
V_143 -> V_76 ( V_7 , NULL ) ;
}
if ( V_144 && V_141 && V_141 -> V_140 )
V_141 -> V_140 ( V_10 , NULL ) ;
}
void F_76 ( struct V_57 * V_34 ,
struct V_1 * V_70 )
{
struct V_6 * V_7 ;
struct V_3 * V_4 , * V_66 ;
int V_22 ;
F_41 (old_state, plane, old_plane_state, new_plane_state, i) {
const struct V_67 * V_25 ;
struct V_3 * V_5 ;
if ( V_4 == V_7 -> V_2 )
V_5 = V_66 ;
else
V_5 = V_4 ;
V_25 = V_7 -> V_26 ;
if ( V_25 -> V_132 )
V_25 -> V_132 ( V_7 , V_5 ) ;
}
}
int F_93 ( struct V_1 * V_2 ,
bool V_145 )
{
int V_22 , V_23 ;
struct V_15 * V_16 ;
struct V_13 * V_71 , * V_14 ;
struct V_39 * V_10 ;
struct V_8 * V_58 , * V_44 ;
struct V_6 * V_7 ;
struct V_3 * V_4 , * V_66 ;
struct V_98 * V_88 ;
struct V_146 * V_147 ;
struct V_148 * V_149 , * V_150 ;
if ( V_145 ) {
F_24 (state, crtc, new_crtc_state, i) {
F_84 ( & V_10 -> V_111 ) ;
V_88 = F_85 ( & V_10 -> V_112 ,
struct V_98 , V_113 ) ;
if ( V_88 )
F_99 ( V_88 ) ;
F_86 ( & V_10 -> V_111 ) ;
if ( ! V_88 )
continue;
V_23 = F_118 ( & V_88 -> V_125 ) ;
F_101 ( V_88 ) ;
if ( V_23 )
return V_23 ;
}
}
F_20 (state, connector, old_conn_state, new_conn_state, i) {
F_3 ( V_16 -> V_2 != V_71 ) ;
V_71 -> V_2 = V_2 ;
V_14 -> V_2 = NULL ;
V_2 -> V_151 [ V_22 ] . V_2 = V_71 ;
V_16 -> V_2 = V_14 ;
}
F_33 (state, crtc, old_crtc_state, new_crtc_state, i) {
F_3 ( V_10 -> V_2 != V_58 ) ;
V_58 -> V_2 = V_2 ;
V_44 -> V_2 = NULL ;
V_2 -> V_93 [ V_22 ] . V_2 = V_58 ;
V_10 -> V_2 = V_44 ;
if ( V_2 -> V_93 [ V_22 ] . V_88 ) {
F_84 ( & V_10 -> V_111 ) ;
F_119 ( & V_2 -> V_93 [ V_22 ] . V_88 -> V_113 ,
& V_10 -> V_112 ) ;
F_86 ( & V_10 -> V_111 ) ;
V_2 -> V_93 [ V_22 ] . V_88 -> V_127 = NULL ;
}
}
F_41 (state, plane, old_plane_state, new_plane_state, i) {
F_3 ( V_7 -> V_2 != V_4 ) ;
V_4 -> V_2 = V_2 ;
V_66 -> V_2 = NULL ;
V_2 -> V_152 [ V_22 ] . V_2 = V_4 ;
V_7 -> V_2 = V_66 ;
}
F_120 (state, obj, old_obj_state, new_obj_state, i) {
F_3 ( V_147 -> V_2 != V_149 ) ;
V_149 -> V_2 = V_2 ;
V_150 -> V_2 = NULL ;
V_2 -> V_153 [ V_22 ] . V_2 = V_149 ;
V_147 -> V_2 = V_150 ;
}
return 0 ;
}
int F_121 ( struct V_6 * V_7 ,
struct V_39 * V_10 ,
struct V_154 * V_91 ,
int V_155 , int V_156 ,
unsigned int V_157 , unsigned int V_158 ,
T_1 V_81 , T_1 V_83 ,
T_1 V_159 , T_1 V_160 ,
struct V_161 * V_162 )
{
struct V_1 * V_2 ;
struct V_3 * V_5 ;
int V_23 = 0 ;
V_2 = F_122 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_124 ;
V_2 -> V_163 = V_162 ;
V_5 = F_123 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) ) {
V_23 = F_14 ( V_5 ) ;
goto V_131;
}
V_23 = F_124 ( V_5 , V_10 ) ;
if ( V_23 != 0 )
goto V_131;
F_125 ( V_5 , V_91 ) ;
V_5 -> V_155 = V_155 ;
V_5 -> V_156 = V_156 ;
V_5 -> V_157 = V_157 ;
V_5 -> V_158 = V_158 ;
V_5 -> V_81 = V_81 ;
V_5 -> V_83 = V_83 ;
V_5 -> V_159 = V_159 ;
V_5 -> V_160 = V_160 ;
if ( V_7 == V_10 -> V_164 )
V_2 -> V_68 = true ;
V_23 = F_126 ( V_2 ) ;
V_131:
F_81 ( V_2 ) ;
return V_23 ;
}
int F_127 ( struct V_6 * V_7 ,
struct V_161 * V_162 )
{
struct V_1 * V_2 ;
struct V_3 * V_5 ;
int V_23 = 0 ;
V_2 = F_122 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_124 ;
V_2 -> V_163 = V_162 ;
V_5 = F_123 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) ) {
V_23 = F_14 ( V_5 ) ;
goto V_131;
}
if ( V_5 -> V_10 && ( V_7 == V_7 -> V_10 -> V_164 ) )
V_5 -> V_2 -> V_68 = true ;
V_23 = F_128 ( V_7 , V_5 ) ;
if ( V_23 != 0 )
goto V_131;
V_23 = F_126 ( V_2 ) ;
V_131:
F_81 ( V_2 ) ;
return V_23 ;
}
int F_128 ( struct V_6 * V_7 ,
struct V_3 * V_5 )
{
int V_23 ;
V_23 = F_124 ( V_5 , NULL ) ;
if ( V_23 != 0 )
return V_23 ;
F_125 ( V_5 , NULL ) ;
V_5 -> V_155 = 0 ;
V_5 -> V_156 = 0 ;
V_5 -> V_157 = 0 ;
V_5 -> V_158 = 0 ;
V_5 -> V_81 = 0 ;
V_5 -> V_83 = 0 ;
V_5 -> V_159 = 0 ;
V_5 -> V_160 = 0 ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 ,
struct V_165 * V_166 )
{
struct V_57 * V_34 = V_166 -> V_10 -> V_34 ;
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
int V_23 , V_22 ;
V_23 = F_130 ( & V_34 -> V_63 . V_64 ,
V_2 -> V_163 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_38 ( V_2 , V_166 -> V_10 ) ;
if ( V_23 )
return V_23 ;
F_5 (state, connector, new_conn_state, i) {
if ( V_14 -> V_10 == V_166 -> V_10 ) {
V_23 = F_15 ( V_14 ,
NULL ) ;
if ( V_23 )
return V_23 ;
V_14 -> V_65 = V_167 ;
}
}
for ( V_22 = 0 ; V_22 < V_166 -> V_168 ; V_22 ++ ) {
V_14 = F_12 ( V_2 ,
V_166 -> V_151 [ V_22 ] ) ;
if ( F_13 ( V_14 ) )
return F_14 ( V_14 ) ;
V_23 = F_15 ( V_14 ,
V_166 -> V_10 ) ;
if ( V_23 )
return V_23 ;
}
F_24 (state, crtc, new_crtc_state, i) {
if ( V_10 == V_166 -> V_10 )
continue;
if ( ! V_44 -> V_36 ) {
V_23 = F_16 ( V_44 ,
NULL ) ;
if ( V_23 < 0 )
return V_23 ;
V_44 -> V_37 = false ;
}
}
return 0 ;
}
int F_131 ( struct V_165 * V_166 ,
struct V_161 * V_162 )
{
struct V_1 * V_2 ;
struct V_39 * V_10 = V_166 -> V_10 ;
int V_23 = 0 ;
V_2 = F_122 ( V_10 -> V_34 ) ;
if ( ! V_2 )
return - V_124 ;
V_2 -> V_163 = V_162 ;
V_23 = F_132 ( V_166 , V_2 ) ;
if ( V_23 != 0 )
goto V_131;
V_23 = F_4 ( V_2 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = F_126 ( V_2 ) ;
V_131:
F_81 ( V_2 ) ;
return V_23 ;
}
int F_132 ( struct V_165 * V_166 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_3 * V_169 ;
struct V_39 * V_10 = V_166 -> V_10 ;
int V_170 , V_171 ;
int V_23 ;
V_9 = F_133 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) )
return F_14 ( V_9 ) ;
V_169 = F_123 ( V_2 , V_10 -> V_78 ) ;
if ( F_13 ( V_169 ) )
return F_14 ( V_169 ) ;
if ( ! V_166 -> V_47 ) {
F_3 ( V_166 -> V_91 ) ;
F_3 ( V_166 -> V_168 ) ;
V_23 = F_134 ( V_9 , NULL ) ;
if ( V_23 != 0 )
return V_23 ;
V_9 -> V_37 = false ;
V_23 = F_124 ( V_169 , NULL ) ;
if ( V_23 != 0 )
return V_23 ;
F_125 ( V_169 , NULL ) ;
goto V_88;
}
F_3 ( ! V_166 -> V_91 ) ;
F_3 ( ! V_166 -> V_168 ) ;
V_23 = F_134 ( V_9 , V_166 -> V_47 ) ;
if ( V_23 != 0 )
return V_23 ;
V_9 -> V_37 = true ;
V_23 = F_124 ( V_169 , V_10 ) ;
if ( V_23 != 0 )
return V_23 ;
F_135 ( V_166 -> V_47 , & V_170 , & V_171 ) ;
F_125 ( V_169 , V_166 -> V_91 ) ;
V_169 -> V_155 = 0 ;
V_169 -> V_156 = 0 ;
V_169 -> V_157 = V_170 ;
V_169 -> V_158 = V_171 ;
V_169 -> V_81 = V_166 -> V_80 << 16 ;
V_169 -> V_83 = V_166 -> V_82 << 16 ;
if ( F_136 ( V_169 -> V_172 ) ) {
V_169 -> V_159 = V_171 << 16 ;
V_169 -> V_160 = V_170 << 16 ;
} else {
V_169 -> V_159 = V_170 << 16 ;
V_169 -> V_160 = V_171 << 16 ;
}
V_88:
V_23 = F_129 ( V_2 , V_166 ) ;
if ( V_23 )
return V_23 ;
return 0 ;
}
int F_137 ( struct V_57 * V_34 ,
struct V_161 * V_162 )
{
struct V_1 * V_2 ;
struct V_13 * V_38 ;
struct V_15 * V_173 ;
struct V_3 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_39 * V_10 ;
unsigned V_142 = 0 ;
int V_23 , V_22 ;
V_2 = F_122 ( V_34 ) ;
if ( ! V_2 )
return - V_124 ;
V_2 -> V_163 = V_162 ;
F_138 (crtc, dev) {
V_9 = F_133 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) ) {
V_23 = F_14 ( V_9 ) ;
goto free;
}
V_9 -> V_37 = false ;
V_23 = F_16 ( V_9 , NULL ) ;
if ( V_23 < 0 )
goto free;
V_23 = F_39 ( V_2 , V_10 ) ;
if ( V_23 < 0 )
goto free;
V_23 = F_38 ( V_2 , V_10 ) ;
if ( V_23 < 0 )
goto free;
}
F_5 (state, conn, conn_state, i) {
V_23 = F_15 ( V_38 , NULL ) ;
if ( V_23 < 0 )
goto free;
}
F_58 (state, plane, plane_state, i) {
V_23 = F_124 ( V_5 , NULL ) ;
if ( V_23 < 0 )
goto free;
F_125 ( V_5 , NULL ) ;
V_142 |= F_36 ( F_139 ( V_7 ) ) ;
V_7 -> V_174 = V_7 -> V_91 ;
}
V_23 = F_126 ( V_2 ) ;
free:
if ( V_142 )
F_140 ( V_34 , V_142 , V_23 ) ;
F_81 ( V_2 ) ;
return V_23 ;
}
void F_141 ( struct V_57 * V_34 )
{
struct V_161 V_162 ;
int V_23 ;
F_142 ( & V_162 , 0 ) ;
while ( 1 ) {
V_23 = F_143 ( V_34 , & V_162 ) ;
if ( ! V_23 )
V_23 = F_137 ( V_34 , & V_162 ) ;
if ( V_23 != - V_175 )
break;
F_144 ( & V_162 ) ;
}
if ( V_23 )
F_72 ( L_35 , V_23 ) ;
F_145 ( & V_162 ) ;
F_146 ( & V_162 ) ;
}
struct V_1 * F_147 ( struct V_57 * V_34 )
{
struct V_161 V_162 ;
struct V_1 * V_2 ;
int V_116 ;
F_142 ( & V_162 , 0 ) ;
V_176:
V_116 = F_143 ( V_34 , & V_162 ) ;
if ( V_116 < 0 ) {
V_2 = F_148 ( V_116 ) ;
goto V_177;
}
V_2 = F_149 ( V_34 , & V_162 ) ;
if ( F_13 ( V_2 ) )
goto V_177;
V_116 = F_137 ( V_34 , & V_162 ) ;
if ( V_116 < 0 ) {
F_81 ( V_2 ) ;
V_2 = F_148 ( V_116 ) ;
goto V_177;
}
V_177:
if ( F_14 ( V_2 ) == - V_175 ) {
F_144 ( & V_162 ) ;
goto V_176;
}
F_145 ( & V_162 ) ;
F_146 ( & V_162 ) ;
return V_2 ;
}
int F_150 ( struct V_1 * V_2 ,
struct V_161 * V_162 )
{
int V_22 ;
struct V_6 * V_7 ;
struct V_3 * V_66 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
struct V_39 * V_10 ;
struct V_8 * V_44 ;
unsigned V_142 = 0 ;
struct V_57 * V_34 = V_2 -> V_34 ;
int V_23 ;
V_2 -> V_163 = V_162 ;
F_58 (state, plane, new_plane_state, i) {
V_142 |= F_36 ( F_139 ( V_7 ) ) ;
V_2 -> V_152 [ V_22 ] . V_70 = V_7 -> V_2 ;
}
F_24 (state, crtc, new_crtc_state, i)
V_2 -> V_93 [ V_22 ] . V_70 = V_10 -> V_2 ;
F_5 (state, connector, new_conn_state, i)
V_2 -> V_151 [ V_22 ] . V_70 = V_16 -> V_2 ;
V_23 = F_126 ( V_2 ) ;
if ( V_142 )
F_140 ( V_34 , V_142 , V_23 ) ;
return V_23 ;
}
int F_151 ( struct V_57 * V_34 ,
struct V_1 * V_2 )
{
struct V_161 V_162 ;
int V_116 ;
F_152 ( V_34 ) ;
F_142 ( & V_162 , 0 ) ;
while ( 1 ) {
V_116 = F_143 ( V_34 , & V_162 ) ;
if ( V_116 )
goto V_35;
V_116 = F_150 ( V_2 , & V_162 ) ;
V_35:
if ( V_116 != - V_175 )
break;
F_144 ( & V_162 ) ;
}
F_81 ( V_2 ) ;
F_145 ( & V_162 ) ;
F_146 ( & V_162 ) ;
return V_116 ;
}
static int F_153 ( struct V_1 * V_2 ,
struct V_39 * V_10 ,
struct V_154 * V_91 ,
struct V_178 * V_127 ,
T_1 V_133 )
{
struct V_6 * V_7 = V_10 -> V_78 ;
struct V_3 * V_5 ;
struct V_8 * V_9 ;
int V_23 = 0 ;
V_9 = F_133 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) )
return F_14 ( V_9 ) ;
V_9 -> V_127 = V_127 ;
V_9 -> V_179 = V_133 ;
V_5 = F_123 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) )
return F_14 ( V_5 ) ;
V_23 = F_124 ( V_5 , V_10 ) ;
if ( V_23 != 0 )
return V_23 ;
F_125 ( V_5 , V_91 ) ;
V_2 -> V_180 = false ;
if ( ! V_9 -> V_37 ) {
F_8 ( L_36 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
return - V_33 ;
}
return V_23 ;
}
int F_154 ( struct V_39 * V_10 ,
struct V_154 * V_91 ,
struct V_178 * V_127 ,
T_1 V_133 ,
struct V_161 * V_162 )
{
struct V_6 * V_7 = V_10 -> V_78 ;
struct V_1 * V_2 ;
int V_23 = 0 ;
V_2 = F_122 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_124 ;
V_2 -> V_163 = V_162 ;
V_23 = F_153 ( V_2 , V_10 , V_91 , V_127 , V_133 ) ;
if ( V_23 != 0 )
goto V_131;
V_23 = F_155 ( V_2 ) ;
V_131:
F_81 ( V_2 ) ;
return V_23 ;
}
int F_156 ( struct V_39 * V_10 ,
struct V_154 * V_91 ,
struct V_178 * V_127 ,
T_1 V_133 ,
T_1 V_181 ,
struct V_161 * V_162 )
{
struct V_6 * V_7 = V_10 -> V_78 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_23 = 0 ;
V_2 = F_122 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_124 ;
V_2 -> V_163 = V_162 ;
V_23 = F_153 ( V_2 , V_10 , V_91 , V_127 , V_133 ) ;
if ( V_23 != 0 )
goto V_131;
V_9 = F_2 ( V_2 , V_10 ) ;
if ( F_3 ( ! V_9 ) ) {
V_23 = - V_33 ;
goto V_131;
}
V_9 -> V_182 = V_181 ;
V_23 = F_155 ( V_2 ) ;
V_131:
F_81 ( V_2 ) ;
return V_23 ;
}
struct V_19 *
F_6 ( struct V_15 * V_16 )
{
F_3 ( V_16 -> V_183 [ 1 ] ) ;
return F_157 ( V_16 -> V_34 , V_16 -> V_183 [ 0 ] ) ;
}
void F_158 ( struct V_39 * V_10 )
{
if ( V_10 -> V_2 )
F_159 ( V_10 -> V_2 ) ;
F_160 ( V_10 -> V_2 ) ;
V_10 -> V_2 = F_104 ( sizeof( * V_10 -> V_2 ) , V_123 ) ;
if ( V_10 -> V_2 )
V_10 -> V_2 -> V_10 = V_10 ;
}
void F_161 ( struct V_39 * V_10 ,
struct V_8 * V_2 )
{
memcpy ( V_2 , V_10 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_184 )
F_162 ( V_2 -> V_184 ) ;
if ( V_2 -> V_185 )
F_162 ( V_2 -> V_185 ) ;
if ( V_2 -> V_186 )
F_162 ( V_2 -> V_186 ) ;
if ( V_2 -> V_187 )
F_162 ( V_2 -> V_187 ) ;
V_2 -> V_45 = false ;
V_2 -> V_62 = false ;
V_2 -> V_11 = false ;
V_2 -> V_43 = false ;
V_2 -> V_188 = false ;
V_2 -> V_189 = false ;
V_2 -> V_127 = NULL ;
V_2 -> V_179 = 0 ;
}
struct V_8 *
F_163 ( struct V_39 * V_10 )
{
struct V_8 * V_2 ;
if ( F_3 ( ! V_10 -> V_2 ) )
return NULL ;
V_2 = F_164 ( sizeof( * V_2 ) , V_123 ) ;
if ( V_2 )
F_161 ( V_10 , V_2 ) ;
return V_2 ;
}
void F_159 ( struct V_8 * V_2 )
{
F_165 ( V_2 -> V_184 ) ;
F_165 ( V_2 -> V_185 ) ;
F_165 ( V_2 -> V_186 ) ;
F_165 ( V_2 -> V_187 ) ;
}
void F_166 ( struct V_39 * V_10 ,
struct V_8 * V_2 )
{
F_159 ( V_2 ) ;
F_160 ( V_2 ) ;
}
void F_167 ( struct V_6 * V_7 )
{
if ( V_7 -> V_2 )
F_168 ( V_7 -> V_2 ) ;
F_160 ( V_7 -> V_2 ) ;
V_7 -> V_2 = F_104 ( sizeof( * V_7 -> V_2 ) , V_123 ) ;
if ( V_7 -> V_2 ) {
V_7 -> V_2 -> V_7 = V_7 ;
V_7 -> V_2 -> V_172 = V_190 ;
}
}
void F_169 ( struct V_6 * V_7 ,
struct V_3 * V_2 )
{
memcpy ( V_2 , V_7 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_91 )
F_170 ( V_2 -> V_91 ) ;
V_2 -> V_90 = NULL ;
}
struct V_3 *
F_171 ( struct V_6 * V_7 )
{
struct V_3 * V_2 ;
if ( F_3 ( ! V_7 -> V_2 ) )
return NULL ;
V_2 = F_164 ( sizeof( * V_2 ) , V_123 ) ;
if ( V_2 )
F_169 ( V_7 , V_2 ) ;
return V_2 ;
}
void F_168 ( struct V_3 * V_2 )
{
if ( V_2 -> V_91 )
F_172 ( V_2 -> V_91 ) ;
if ( V_2 -> V_90 )
F_60 ( V_2 -> V_90 ) ;
}
void F_173 ( struct V_6 * V_7 ,
struct V_3 * V_2 )
{
F_168 ( V_2 ) ;
F_160 ( V_2 ) ;
}
void
F_174 ( struct V_15 * V_16 ,
struct V_13 * V_38 )
{
if ( V_38 )
V_38 -> V_16 = V_16 ;
V_16 -> V_2 = V_38 ;
}
void F_175 ( struct V_15 * V_16 )
{
struct V_13 * V_38 =
F_104 ( sizeof( * V_38 ) , V_123 ) ;
if ( V_16 -> V_2 )
F_176 ( V_16 -> V_2 ) ;
F_160 ( V_16 -> V_2 ) ;
F_174 ( V_16 , V_38 ) ;
}
void
F_177 ( struct V_15 * V_16 ,
struct V_13 * V_2 )
{
memcpy ( V_2 , V_16 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_10 )
F_178 ( V_16 ) ;
}
struct V_13 *
F_179 ( struct V_15 * V_16 )
{
struct V_13 * V_2 ;
if ( F_3 ( ! V_16 -> V_2 ) )
return NULL ;
V_2 = F_164 ( sizeof( * V_2 ) , V_123 ) ;
if ( V_2 )
F_177 ( V_16 , V_2 ) ;
return V_2 ;
}
struct V_1 *
F_149 ( struct V_57 * V_34 ,
struct V_161 * V_162 )
{
struct V_1 * V_2 ;
struct V_15 * V_173 ;
struct V_17 V_18 ;
struct V_6 * V_7 ;
struct V_39 * V_10 ;
int V_116 = 0 ;
V_2 = F_122 ( V_34 ) ;
if ( ! V_2 )
return F_148 ( - V_124 ) ;
V_2 -> V_163 = V_162 ;
F_138 (crtc, dev) {
struct V_8 * V_9 ;
V_9 = F_133 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) ) {
V_116 = F_14 ( V_9 ) ;
goto free;
}
}
F_180 (plane, dev) {
struct V_3 * V_5 ;
V_5 = F_123 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) ) {
V_116 = F_14 ( V_5 ) ;
goto free;
}
}
F_9 ( V_34 , & V_18 ) ;
F_10 (conn, &conn_iter) {
struct V_13 * V_38 ;
V_38 = F_12 ( V_2 , V_173 ) ;
if ( F_13 ( V_38 ) ) {
V_116 = F_14 ( V_38 ) ;
F_17 ( & V_18 ) ;
goto free;
}
}
F_17 ( & V_18 ) ;
V_2 -> V_163 = NULL ;
free:
if ( V_116 < 0 ) {
F_81 ( V_2 ) ;
V_2 = F_148 ( V_116 ) ;
}
return V_2 ;
}
void
F_176 ( struct V_13 * V_2 )
{
if ( V_2 -> V_10 )
F_181 ( V_2 -> V_16 ) ;
}
void F_182 ( struct V_15 * V_16 ,
struct V_13 * V_2 )
{
F_176 ( V_2 ) ;
F_160 ( V_2 ) ;
}
int F_183 ( struct V_39 * V_10 ,
T_2 * V_191 , T_2 * V_192 , T_2 * V_193 ,
T_1 V_194 ,
struct V_161 * V_162 )
{
struct V_57 * V_34 = V_10 -> V_34 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_195 * V_196 = NULL ;
struct V_197 * V_198 ;
int V_22 , V_23 = 0 ;
bool V_199 ;
V_2 = F_122 ( V_10 -> V_34 ) ;
if ( ! V_2 )
return - V_124 ;
V_196 = F_184 ( V_34 ,
sizeof( struct V_197 ) * V_194 ,
NULL ) ;
if ( F_13 ( V_196 ) ) {
V_23 = F_14 ( V_196 ) ;
V_196 = NULL ;
goto V_131;
}
V_198 = (struct V_197 * ) V_196 -> V_200 ;
for ( V_22 = 0 ; V_22 < V_194 ; V_22 ++ ) {
V_198 [ V_22 ] . V_191 = V_191 [ V_22 ] ;
V_198 [ V_22 ] . V_192 = V_192 [ V_22 ] ;
V_198 [ V_22 ] . V_193 = V_193 [ V_22 ] ;
}
V_2 -> V_163 = V_162 ;
V_9 = F_133 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) ) {
V_23 = F_14 ( V_9 ) ;
goto V_131;
}
V_199 = F_185 ( & V_9 -> V_185 , NULL ) ;
V_199 |= F_185 ( & V_9 -> V_186 , NULL ) ;
V_199 |= F_185 ( & V_9 -> V_187 , V_196 ) ;
V_9 -> V_188 |= V_199 ;
V_23 = F_126 ( V_2 ) ;
V_131:
F_81 ( V_2 ) ;
F_165 ( V_196 ) ;
return V_23 ;
}
void F_186 ( struct V_146 * V_147 ,
struct V_148 * V_2 )
{
memcpy ( V_2 , V_147 -> V_2 , sizeof( * V_2 ) ) ;
}
