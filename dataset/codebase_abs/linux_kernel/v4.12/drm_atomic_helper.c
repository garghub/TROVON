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
int
F_27 ( struct V_53 * V_34 ,
struct V_1 * V_2 )
{
struct V_39 * V_10 ;
struct V_8 * V_54 , * V_44 ;
struct V_15 * V_16 ;
struct V_13 * V_40 , * V_41 ;
int V_22 , V_23 ;
unsigned V_55 = 0 ;
F_28 (state, crtc, old_crtc_state, new_crtc_state, i) {
bool V_56 =
! ! V_44 -> V_36 ;
F_3 ( ! F_29 ( & V_10 -> V_57 ) ) ;
if ( ! F_30 ( & V_54 -> V_47 , & V_44 -> V_47 ) ) {
F_8 ( L_15 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
V_44 -> V_45 = true ;
}
if ( V_54 -> V_52 != V_44 -> V_52 ) {
F_8 ( L_16 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
V_44 -> V_45 = true ;
V_44 -> V_43 = true ;
}
if ( V_54 -> V_37 != V_44 -> V_37 ) {
F_8 ( L_17 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
V_44 -> V_58 = true ;
}
if ( V_44 -> V_52 != V_56 ) {
F_8 ( L_18 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
return - V_33 ;
}
}
V_23 = F_4 ( V_2 , false ) ;
if ( V_23 )
return V_23 ;
F_20 (state, connector, old_connector_state, new_connector_state, i) {
const struct V_24 * V_25 = V_16 -> V_26 ;
F_3 ( ! F_29 ( & V_34 -> V_59 . V_60 ) ) ;
V_23 = F_21 ( V_2 , V_16 ,
V_40 ,
V_41 ) ;
if ( V_23 )
return V_23 ;
if ( V_40 -> V_10 ) {
V_44 = F_2 ( V_2 ,
V_40 -> V_10 ) ;
if ( V_40 -> V_61 !=
V_41 -> V_61 )
V_44 -> V_43 = true ;
}
if ( V_25 -> V_50 )
V_23 = V_25 -> V_50 ( V_16 , V_41 ) ;
if ( V_23 )
return V_23 ;
V_55 += F_31 ( V_22 ) ;
}
F_28 (state, crtc, old_crtc_state, new_crtc_state, i) {
if ( ! F_32 ( V_44 ) )
continue;
F_8 ( L_19 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ,
V_44 -> V_52 ? 'y' : 'n' ,
V_44 -> V_37 ? 'y' : 'n' ) ;
V_23 = F_33 ( V_2 , V_10 ) ;
if ( V_23 != 0 )
return V_23 ;
V_23 = F_34 ( V_2 , V_10 ) ;
if ( V_23 != 0 )
return V_23 ;
}
F_20 (state, connector, old_connector_state, new_connector_state, i) {
const struct V_24 * V_25 = V_16 -> V_26 ;
if ( V_55 & F_31 ( V_22 ) )
continue;
if ( V_25 -> V_50 )
V_23 = V_25 -> V_50 ( V_16 , V_41 ) ;
if ( V_23 )
return V_23 ;
}
return F_23 ( V_2 ) ;
}
int
F_35 ( struct V_53 * V_34 ,
struct V_1 * V_2 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_6 * V_7 ;
struct V_3 * V_62 , * V_4 ;
int V_22 , V_23 = 0 ;
F_36 (state, plane, old_plane_state, new_plane_state, i) {
const struct V_63 * V_25 ;
F_3 ( ! F_29 ( & V_7 -> V_57 ) ) ;
V_25 = V_7 -> V_26 ;
F_1 ( V_2 , V_4 , V_62 , V_7 ) ;
if ( ! V_25 || ! V_25 -> V_50 )
continue;
V_23 = V_25 -> V_50 ( V_7 , V_62 ) ;
if ( V_23 ) {
F_8 ( L_20 ,
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
F_8 ( L_21 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
return V_23 ;
}
}
return V_23 ;
}
int F_37 ( struct V_53 * V_34 ,
struct V_1 * V_2 )
{
int V_23 ;
V_23 = F_27 ( V_34 , V_2 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_35 ( V_34 , V_2 ) ;
if ( V_23 )
return V_23 ;
return V_23 ;
}
static void
F_38 ( struct V_53 * V_34 , struct V_1 * V_64 )
{
struct V_15 * V_16 ;
struct V_13 * V_65 , * V_14 ;
struct V_39 * V_10 ;
struct V_8 * V_54 , * V_44 ;
int V_22 ;
F_20 (old_state, connector, old_conn_state, new_conn_state, i) {
const struct V_48 * V_25 ;
struct V_19 * V_20 ;
if ( ! V_65 -> V_10 )
continue;
V_54 = F_39 ( V_64 , V_65 -> V_10 ) ;
if ( ! V_54 -> V_37 ||
! F_32 ( V_65 -> V_10 -> V_2 ) )
continue;
V_20 = V_65 -> V_29 ;
if ( F_3 ( ! V_20 ) )
continue;
V_25 = V_20 -> V_26 ;
F_8 ( L_22 ,
V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
F_40 ( V_20 -> V_49 ) ;
if ( V_25 ) {
if ( V_14 -> V_10 && V_25 -> V_66 )
V_25 -> V_66 ( V_20 ) ;
else if ( V_25 -> V_67 )
V_25 -> V_67 ( V_20 ) ;
else if ( V_25 -> V_68 )
V_25 -> V_68 ( V_20 , V_69 ) ;
}
F_41 ( V_20 -> V_49 ) ;
}
F_28 (old_state, crtc, old_crtc_state, new_crtc_state, i) {
const struct V_51 * V_25 ;
if ( ! F_32 ( V_44 ) )
continue;
if ( ! V_54 -> V_37 )
continue;
V_25 = V_10 -> V_26 ;
F_8 ( L_23 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
if ( V_44 -> V_52 && V_25 -> V_66 )
V_25 -> V_66 ( V_10 ) ;
else if ( V_25 -> V_70 )
V_25 -> V_70 ( V_10 , V_54 ) ;
else if ( V_25 -> V_67 )
V_25 -> V_67 ( V_10 ) ;
else
V_25 -> V_68 ( V_10 , V_69 ) ;
}
}
void
F_42 ( struct V_53 * V_34 ,
struct V_1 * V_64 )
{
struct V_15 * V_16 ;
struct V_13 * V_65 , * V_14 ;
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
if ( ( ! V_10 && V_65 -> V_10 ) ||
( V_10 && F_32 ( V_10 -> V_2 ) ) ) {
struct V_71 * V_72 =
V_34 -> V_59 . V_73 ;
int V_47 = V_69 ;
if ( V_10 && V_10 -> V_2 -> V_37 )
V_47 = V_74 ;
V_16 -> V_68 = V_47 ;
F_43 ( & V_16 -> V_30 ,
V_72 , V_47 ) ;
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
struct V_6 * V_75 = V_10 -> V_75 ;
struct V_3 * V_62 ;
V_10 -> V_47 = V_44 -> V_47 ;
V_10 -> V_76 = V_44 -> V_52 ;
V_62 =
F_44 ( V_64 , V_75 ) ;
if ( V_62 && V_62 -> V_10 == V_10 ) {
V_10 -> V_77 = V_62 -> V_78 >> 16 ;
V_10 -> V_79 = V_62 -> V_80 >> 16 ;
}
if ( V_44 -> V_52 )
F_45 ( V_10 ,
& V_44 -> V_46 ) ;
}
}
static void
F_46 ( struct V_53 * V_34 , struct V_1 * V_64 )
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
if ( V_44 -> V_52 && V_25 -> V_81 ) {
F_8 ( L_24 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
V_25 -> V_81 ( V_10 ) ;
}
}
F_5 (old_state, connector, new_conn_state, i) {
const struct V_48 * V_25 ;
struct V_19 * V_20 ;
struct V_82 * V_47 , * V_46 ;
if ( ! V_14 -> V_29 )
continue;
V_20 = V_14 -> V_29 ;
V_25 = V_20 -> V_26 ;
V_44 = V_14 -> V_10 -> V_2 ;
V_47 = & V_44 -> V_47 ;
V_46 = & V_44 -> V_46 ;
if ( ! V_44 -> V_45 )
continue;
F_8 ( L_25 ,
V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
if ( V_25 && V_25 -> V_83 ) {
V_25 -> V_83 ( V_20 , V_44 ,
V_14 ) ;
} else if ( V_25 && V_25 -> V_84 ) {
V_25 -> V_84 ( V_20 , V_47 , V_46 ) ;
}
F_47 ( V_20 -> V_49 , V_47 , V_46 ) ;
}
}
void F_48 ( struct V_53 * V_34 ,
struct V_1 * V_64 )
{
F_38 ( V_34 , V_64 ) ;
F_42 ( V_34 , V_64 ) ;
F_46 ( V_34 , V_64 ) ;
}
void F_49 ( struct V_53 * V_34 ,
struct V_1 * V_64 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
int V_22 ;
F_24 (old_state, crtc, new_crtc_state, i) {
const struct V_51 * V_25 ;
if ( ! F_32 ( V_44 ) )
continue;
if ( ! V_44 -> V_37 )
continue;
V_25 = V_10 -> V_26 ;
if ( V_44 -> V_52 ) {
F_8 ( L_26 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
if ( V_25 -> V_52 )
V_25 -> V_52 ( V_10 ) ;
else
V_25 -> V_85 ( V_10 ) ;
}
}
F_5 (old_state, connector, new_conn_state, i) {
const struct V_48 * V_25 ;
struct V_19 * V_20 ;
if ( ! V_14 -> V_29 )
continue;
if ( ! V_14 -> V_10 -> V_2 -> V_37 ||
! F_32 ( V_14 -> V_10 -> V_2 ) )
continue;
V_20 = V_14 -> V_29 ;
V_25 = V_20 -> V_26 ;
F_8 ( L_27 ,
V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
F_50 ( V_20 -> V_49 ) ;
if ( V_25 ) {
if ( V_25 -> V_52 )
V_25 -> V_52 ( V_20 ) ;
else if ( V_25 -> V_85 )
V_25 -> V_85 ( V_20 ) ;
}
F_51 ( V_20 -> V_49 ) ;
}
}
int F_52 ( struct V_53 * V_34 ,
struct V_1 * V_2 ,
bool V_86 )
{
struct V_6 * V_7 ;
struct V_3 * V_62 ;
int V_22 , V_23 ;
F_53 (state, plane, new_plane_state, i) {
if ( ! V_62 -> V_87 )
continue;
F_3 ( ! V_62 -> V_88 ) ;
V_23 = F_54 ( V_62 -> V_87 , V_86 ) ;
if ( V_23 )
return V_23 ;
F_55 ( V_62 -> V_87 ) ;
V_62 -> V_87 = NULL ;
}
return 0 ;
}
void
F_56 ( struct V_53 * V_34 ,
struct V_1 * V_64 )
{
struct V_39 * V_10 ;
struct V_8 * V_54 , * V_44 ;
int V_22 , V_23 ;
unsigned V_89 = 0 ;
if ( V_64 -> V_90 )
return;
F_28 (old_state, crtc, old_crtc_state, new_crtc_state, i) {
if ( ! V_44 -> V_37 || ! V_44 -> V_11 )
continue;
V_23 = F_57 ( V_10 ) ;
if ( V_23 != 0 )
continue;
V_89 |= F_58 ( V_10 ) ;
V_64 -> V_91 [ V_22 ] . V_92 = F_59 ( V_10 ) ;
}
F_60 (old_state, crtc, old_crtc_state, i) {
if ( ! ( V_89 & F_58 ( V_10 ) ) )
continue;
V_23 = F_61 ( V_34 -> V_93 [ V_22 ] . V_94 ,
V_64 -> V_91 [ V_22 ] . V_92 !=
F_59 ( V_10 ) ,
F_62 ( 50 ) ) ;
F_63 ( ! V_23 , L_28 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
F_64 ( V_10 ) ;
}
}
void F_65 ( struct V_1 * V_64 )
{
struct V_53 * V_34 = V_64 -> V_34 ;
F_48 ( V_34 , V_64 ) ;
F_66 ( V_34 , V_64 , 0 ) ;
F_49 ( V_34 , V_64 ) ;
F_67 ( V_64 ) ;
F_56 ( V_34 , V_64 ) ;
F_68 ( V_34 , V_64 ) ;
}
static void F_69 ( struct V_1 * V_64 )
{
struct V_53 * V_34 = V_64 -> V_34 ;
const struct V_95 * V_25 ;
V_25 = V_34 -> V_59 . V_26 ;
F_52 ( V_34 , V_64 , false ) ;
F_70 ( V_64 ) ;
if ( V_25 && V_25 -> V_96 )
V_25 -> V_96 ( V_64 ) ;
else
F_65 ( V_64 ) ;
F_71 ( V_64 ) ;
F_72 ( V_64 ) ;
}
static void F_73 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_74 ( V_98 ,
struct V_1 ,
F_73 ) ;
F_69 ( V_2 ) ;
}
int F_75 ( struct V_53 * V_34 ,
struct V_1 * V_2 ,
bool V_99 )
{
int V_23 ;
V_23 = F_76 ( V_2 , V_99 ) ;
if ( V_23 )
return V_23 ;
F_77 ( & V_2 -> F_73 , F_73 ) ;
V_23 = F_78 ( V_34 , V_2 ) ;
if ( V_23 )
return V_23 ;
if ( ! V_99 ) {
V_23 = F_52 ( V_34 , V_2 , true ) ;
if ( V_23 ) {
F_68 ( V_34 , V_2 ) ;
return V_23 ;
}
}
F_79 ( V_2 , true ) ;
F_80 ( V_2 ) ;
if ( V_99 )
F_81 ( V_100 , & V_2 -> F_73 ) ;
else
F_69 ( V_2 ) ;
return 0 ;
}
static int F_82 ( struct V_39 * V_10 , bool V_99 )
{
struct V_101 * V_85 , * V_102 = NULL ;
bool V_103 = true ;
int V_22 ;
long V_23 = 0 ;
F_83 ( & V_10 -> V_104 ) ;
V_22 = 0 ;
F_84 (commit, &crtc->commit_list, commit_entry) {
if ( V_22 == 0 ) {
V_103 = F_85 ( & V_85 -> V_105 ) ;
if ( ! V_103 && V_99 ) {
F_86 ( & V_10 -> V_104 ) ;
return - V_106 ;
}
} else if ( V_22 == 1 ) {
V_102 = V_85 ;
F_87 ( V_102 ) ;
break;
}
V_22 ++ ;
}
F_86 ( & V_10 -> V_104 ) ;
if ( ! V_102 )
return 0 ;
V_23 = F_88 ( & V_102 -> V_107 ,
10 * V_108 ) ;
if ( V_23 == 0 )
F_89 ( L_29 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
F_90 ( V_102 ) ;
return V_23 < 0 ? V_23 : 0 ;
}
static void F_91 ( struct V_109 * V_109 )
{
struct V_101 * V_85 = F_74 ( V_109 ,
F_92 ( * V_85 ) ,
V_105 ) ;
F_90 ( V_85 ) ;
}
int F_76 ( struct V_1 * V_2 ,
bool V_99 )
{
struct V_39 * V_10 ;
struct V_8 * V_54 , * V_44 ;
struct V_101 * V_85 ;
int V_22 , V_23 ;
F_28 (state, crtc, old_crtc_state, new_crtc_state, i) {
V_85 = F_93 ( sizeof( * V_85 ) , V_110 ) ;
if ( ! V_85 )
return - V_111 ;
F_94 ( & V_85 -> V_105 ) ;
F_94 ( & V_85 -> V_112 ) ;
F_94 ( & V_85 -> V_107 ) ;
F_95 ( & V_85 -> V_113 ) ;
F_96 ( & V_85 -> V_114 ) ;
V_85 -> V_10 = V_10 ;
V_2 -> V_91 [ V_22 ] . V_85 = V_85 ;
V_23 = F_82 ( V_10 , V_99 ) ;
if ( V_23 )
return V_23 ;
if ( ! V_54 -> V_37 && ! V_44 -> V_37 ) {
F_97 ( & V_85 -> V_105 ) ;
continue;
}
if ( V_2 -> V_90 ) {
F_97 ( & V_85 -> V_105 ) ;
continue;
}
if ( ! V_44 -> V_115 ) {
V_85 -> V_115 = F_93 ( sizeof( * V_85 -> V_115 ) ,
V_110 ) ;
if ( ! V_85 -> V_115 )
return - V_111 ;
V_44 -> V_115 = V_85 -> V_115 ;
}
V_44 -> V_115 -> V_30 . V_109 = & V_85 -> V_105 ;
V_44 -> V_115 -> V_30 . V_116 = F_91 ;
F_87 ( V_85 ) ;
}
return 0 ;
}
static struct V_101 * F_98 ( struct V_39 * V_10 )
{
struct V_101 * V_85 ;
int V_22 = 0 ;
F_84 (commit, &crtc->commit_list, commit_entry) {
if ( V_22 == 1 )
return V_85 ;
V_22 ++ ;
}
return NULL ;
}
void F_70 ( struct V_1 * V_64 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_101 * V_85 ;
int V_22 ;
long V_23 ;
F_24 (old_state, crtc, new_crtc_state, i) {
F_83 ( & V_10 -> V_104 ) ;
V_85 = F_98 ( V_10 ) ;
if ( V_85 )
F_87 ( V_85 ) ;
F_86 ( & V_10 -> V_104 ) ;
if ( ! V_85 )
continue;
V_23 = F_99 ( & V_85 -> V_112 ,
10 * V_108 ) ;
if ( V_23 == 0 )
F_89 ( L_30 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
V_23 = F_99 ( & V_85 -> V_105 ,
10 * V_108 ) ;
if ( V_23 == 0 )
F_89 ( L_31 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
F_90 ( V_85 ) ;
}
}
void F_67 ( struct V_1 * V_64 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_101 * V_85 ;
int V_22 ;
F_24 (old_state, crtc, new_crtc_state, i) {
V_85 = V_64 -> V_91 [ V_22 ] . V_85 ;
if ( ! V_85 )
continue;
F_3 ( V_44 -> V_115 ) ;
F_83 ( & V_10 -> V_104 ) ;
F_97 ( & V_85 -> V_112 ) ;
F_86 ( & V_10 -> V_104 ) ;
}
}
void F_71 ( struct V_1 * V_64 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_101 * V_85 ;
int V_22 ;
long V_23 ;
F_24 (old_state, crtc, new_crtc_state, i) {
V_85 = V_64 -> V_91 [ V_22 ] . V_85 ;
if ( F_3 ( ! V_85 ) )
continue;
F_83 ( & V_10 -> V_104 ) ;
F_97 ( & V_85 -> V_107 ) ;
F_3 ( ! F_85 ( & V_85 -> V_112 ) ) ;
if ( F_85 ( & V_85 -> V_105 ) )
goto V_117;
F_86 ( & V_10 -> V_104 ) ;
V_23 = F_99 ( & V_85 -> V_105 ,
10 * V_108 ) ;
if ( V_23 == 0 )
F_89 ( L_31 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
F_83 ( & V_10 -> V_104 ) ;
V_117:
F_100 ( & V_85 -> V_113 ) ;
F_86 ( & V_10 -> V_104 ) ;
}
}
int F_78 ( struct V_53 * V_34 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_3 * V_62 ;
int V_23 , V_22 , V_118 ;
F_53 (state, plane, new_plane_state, i) {
const struct V_63 * V_25 ;
V_25 = V_7 -> V_26 ;
if ( V_25 -> V_119 ) {
V_23 = V_25 -> V_119 ( V_7 , V_62 ) ;
if ( V_23 )
goto V_120;
}
}
return 0 ;
V_120:
F_53 (state, plane, new_plane_state, j) {
const struct V_63 * V_25 ;
if ( V_118 >= V_22 )
continue;
V_25 = V_7 -> V_26 ;
if ( V_25 -> V_121 )
V_25 -> V_121 ( V_7 , V_62 ) ;
}
return V_23 ;
}
static bool F_101 ( const struct V_3 * V_2 )
{
return V_2 -> V_10 && V_2 -> V_10 -> V_2 -> V_37 ;
}
void F_66 ( struct V_53 * V_34 ,
struct V_1 * V_64 ,
T_1 V_122 )
{
struct V_39 * V_10 ;
struct V_8 * V_54 , * V_44 ;
struct V_6 * V_7 ;
struct V_3 * V_4 , * V_62 ;
int V_22 ;
bool V_123 = V_122 & V_124 ;
bool V_125 = V_122 & V_126 ;
F_28 (old_state, crtc, old_crtc_state, new_crtc_state, i) {
const struct V_51 * V_25 ;
V_25 = V_10 -> V_26 ;
if ( ! V_25 || ! V_25 -> V_127 )
continue;
if ( V_123 && ! V_44 -> V_37 )
continue;
V_25 -> V_127 ( V_10 , V_54 ) ;
}
F_36 (old_state, plane, old_plane_state, new_plane_state, i) {
const struct V_63 * V_25 ;
bool V_128 ;
V_25 = V_7 -> V_26 ;
if ( ! V_25 )
continue;
V_128 = F_102 ( V_4 ,
V_62 ) ;
if ( V_123 ) {
if ( ! V_128 && ! F_101 ( V_62 ) )
continue;
if ( V_128 && ! F_101 ( V_4 ) )
continue;
}
if ( V_128 && V_25 -> V_70 ) {
struct V_8 * V_9 ;
V_9 = V_4 -> V_10 -> V_2 ;
if ( F_32 ( V_9 ) &&
V_125 )
continue;
V_25 -> V_70 ( V_7 , V_4 ) ;
} else if ( V_62 -> V_10 || V_128 ) {
V_25 -> V_129 ( V_7 , V_4 ) ;
}
}
F_28 (old_state, crtc, old_crtc_state, new_crtc_state, i) {
const struct V_51 * V_25 ;
V_25 = V_10 -> V_26 ;
if ( ! V_25 || ! V_25 -> V_130 )
continue;
if ( V_123 && ! V_44 -> V_37 )
continue;
V_25 -> V_130 ( V_10 , V_54 ) ;
}
}
void
F_103 ( struct V_8 * V_54 )
{
const struct V_51 * V_131 ;
struct V_39 * V_10 = V_54 -> V_10 ;
struct V_1 * V_64 = V_54 -> V_2 ;
struct V_6 * V_7 ;
unsigned V_132 ;
V_132 = V_54 -> V_132 ;
V_132 |= V_10 -> V_2 -> V_132 ;
V_131 = V_10 -> V_26 ;
if ( V_131 && V_131 -> V_127 )
V_131 -> V_127 ( V_10 , V_54 ) ;
F_104 (plane, crtc->dev, plane_mask) {
struct V_3 * V_4 =
F_105 ( V_64 , V_7 ) ;
const struct V_63 * V_133 ;
V_133 = V_7 -> V_26 ;
if ( ! V_4 || ! V_133 )
continue;
F_3 ( V_7 -> V_2 -> V_10 && V_7 -> V_2 -> V_10 != V_10 ) ;
if ( F_102 ( V_4 , V_7 -> V_2 ) &&
V_133 -> V_70 )
V_133 -> V_70 ( V_7 , V_4 ) ;
else if ( V_7 -> V_2 -> V_10 ||
F_102 ( V_4 , V_7 -> V_2 ) )
V_133 -> V_129 ( V_7 , V_4 ) ;
}
if ( V_131 && V_131 -> V_130 )
V_131 -> V_130 ( V_10 , V_54 ) ;
}
void
F_106 ( struct V_8 * V_54 ,
bool V_134 )
{
struct V_39 * V_10 = V_54 -> V_10 ;
const struct V_51 * V_131 =
V_10 -> V_26 ;
struct V_6 * V_7 ;
if ( V_134 && V_131 && V_131 -> V_127 )
V_131 -> V_127 ( V_10 , NULL ) ;
F_107 (plane, old_crtc_state) {
const struct V_63 * V_133 =
V_7 -> V_26 ;
if ( ! V_133 )
continue;
F_3 ( ! V_133 -> V_70 ) ;
if ( V_133 -> V_70 )
V_133 -> V_70 ( V_7 , NULL ) ;
}
if ( V_134 && V_131 && V_131 -> V_130 )
V_131 -> V_130 ( V_10 , NULL ) ;
}
void F_68 ( struct V_53 * V_34 ,
struct V_1 * V_64 )
{
struct V_6 * V_7 ;
struct V_3 * V_4 , * V_62 ;
int V_22 ;
F_36 (old_state, plane, old_plane_state, new_plane_state, i) {
const struct V_63 * V_25 ;
struct V_3 * V_5 ;
if ( V_4 == V_7 -> V_2 )
V_5 = V_62 ;
else
V_5 = V_4 ;
V_25 = V_7 -> V_26 ;
if ( V_25 -> V_121 )
V_25 -> V_121 ( V_7 , V_5 ) ;
}
}
void F_79 ( struct V_1 * V_2 ,
bool V_135 )
{
int V_22 ;
long V_23 ;
struct V_15 * V_16 ;
struct V_13 * V_65 , * V_14 ;
struct V_39 * V_10 ;
struct V_8 * V_54 , * V_44 ;
struct V_6 * V_7 ;
struct V_3 * V_4 , * V_62 ;
struct V_101 * V_85 ;
if ( V_135 ) {
F_24 (state, crtc, new_crtc_state, i) {
F_83 ( & V_10 -> V_104 ) ;
V_85 = F_108 ( & V_10 -> V_136 ,
struct V_101 , V_113 ) ;
if ( V_85 )
F_87 ( V_85 ) ;
F_86 ( & V_10 -> V_104 ) ;
if ( ! V_85 )
continue;
V_23 = F_99 ( & V_85 -> V_112 ,
10 * V_108 ) ;
if ( V_23 == 0 )
F_89 ( L_30 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
F_90 ( V_85 ) ;
}
}
F_20 (state, connector, old_conn_state, new_conn_state, i) {
F_3 ( V_16 -> V_2 != V_65 ) ;
V_65 -> V_2 = V_2 ;
V_14 -> V_2 = NULL ;
V_2 -> V_137 [ V_22 ] . V_2 = V_65 ;
V_16 -> V_2 = V_14 ;
}
F_28 (state, crtc, old_crtc_state, new_crtc_state, i) {
F_3 ( V_10 -> V_2 != V_54 ) ;
V_54 -> V_2 = V_2 ;
V_44 -> V_2 = NULL ;
V_2 -> V_91 [ V_22 ] . V_2 = V_54 ;
V_10 -> V_2 = V_44 ;
if ( V_2 -> V_91 [ V_22 ] . V_85 ) {
F_83 ( & V_10 -> V_104 ) ;
F_109 ( & V_2 -> V_91 [ V_22 ] . V_85 -> V_113 ,
& V_10 -> V_136 ) ;
F_86 ( & V_10 -> V_104 ) ;
V_2 -> V_91 [ V_22 ] . V_85 -> V_115 = NULL ;
}
}
F_36 (state, plane, old_plane_state, new_plane_state, i) {
F_3 ( V_7 -> V_2 != V_4 ) ;
V_4 -> V_2 = V_2 ;
V_62 -> V_2 = NULL ;
V_2 -> V_138 [ V_22 ] . V_2 = V_4 ;
V_7 -> V_2 = V_62 ;
}
}
int F_110 ( struct V_6 * V_7 ,
struct V_39 * V_10 ,
struct V_139 * V_88 ,
int V_140 , int V_141 ,
unsigned int V_142 , unsigned int V_143 ,
T_1 V_78 , T_1 V_80 ,
T_1 V_144 , T_1 V_145 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 ;
struct V_3 * V_5 ;
int V_23 = 0 ;
V_2 = F_111 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_111 ;
V_2 -> V_148 = V_147 ;
V_5 = F_112 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) ) {
V_23 = F_14 ( V_5 ) ;
goto V_120;
}
V_23 = F_113 ( V_5 , V_10 ) ;
if ( V_23 != 0 )
goto V_120;
F_114 ( V_5 , V_88 ) ;
V_5 -> V_140 = V_140 ;
V_5 -> V_141 = V_141 ;
V_5 -> V_142 = V_142 ;
V_5 -> V_143 = V_143 ;
V_5 -> V_78 = V_78 ;
V_5 -> V_80 = V_80 ;
V_5 -> V_144 = V_144 ;
V_5 -> V_145 = V_145 ;
if ( V_7 == V_10 -> V_149 )
V_2 -> V_90 = true ;
V_23 = F_115 ( V_2 ) ;
V_120:
F_72 ( V_2 ) ;
return V_23 ;
}
int F_116 ( struct V_6 * V_7 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 ;
struct V_3 * V_5 ;
int V_23 = 0 ;
V_2 = F_111 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_111 ;
V_2 -> V_148 = V_147 ;
V_5 = F_112 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) ) {
V_23 = F_14 ( V_5 ) ;
goto V_120;
}
if ( V_5 -> V_10 && ( V_7 == V_7 -> V_10 -> V_149 ) )
V_5 -> V_2 -> V_90 = true ;
V_23 = F_117 ( V_7 , V_5 ) ;
if ( V_23 != 0 )
goto V_120;
V_23 = F_115 ( V_2 ) ;
V_120:
F_72 ( V_2 ) ;
return V_23 ;
}
int F_117 ( struct V_6 * V_7 ,
struct V_3 * V_5 )
{
int V_23 ;
V_23 = F_113 ( V_5 , NULL ) ;
if ( V_23 != 0 )
return V_23 ;
F_114 ( V_5 , NULL ) ;
V_5 -> V_140 = 0 ;
V_5 -> V_141 = 0 ;
V_5 -> V_142 = 0 ;
V_5 -> V_143 = 0 ;
V_5 -> V_78 = 0 ;
V_5 -> V_80 = 0 ;
V_5 -> V_144 = 0 ;
V_5 -> V_145 = 0 ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_150 * V_151 )
{
struct V_53 * V_34 = V_151 -> V_10 -> V_34 ;
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
int V_23 , V_22 ;
V_23 = F_119 ( & V_34 -> V_59 . V_60 ,
V_2 -> V_148 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_33 ( V_2 , V_151 -> V_10 ) ;
if ( V_23 )
return V_23 ;
F_5 (state, connector, new_conn_state, i) {
if ( V_14 -> V_10 == V_151 -> V_10 ) {
V_23 = F_15 ( V_14 ,
NULL ) ;
if ( V_23 )
return V_23 ;
V_14 -> V_61 = V_152 ;
}
}
for ( V_22 = 0 ; V_22 < V_151 -> V_153 ; V_22 ++ ) {
V_14 = F_12 ( V_2 ,
V_151 -> V_137 [ V_22 ] ) ;
if ( F_13 ( V_14 ) )
return F_14 ( V_14 ) ;
V_23 = F_15 ( V_14 ,
V_151 -> V_10 ) ;
if ( V_23 )
return V_23 ;
}
F_24 (state, crtc, new_crtc_state, i) {
if ( V_10 == V_151 -> V_10 )
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
int F_120 ( struct V_150 * V_151 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 ;
struct V_39 * V_10 = V_151 -> V_10 ;
int V_23 = 0 ;
V_2 = F_111 ( V_10 -> V_34 ) ;
if ( ! V_2 )
return - V_111 ;
V_2 -> V_148 = V_147 ;
V_23 = F_121 ( V_151 , V_2 ) ;
if ( V_23 != 0 )
goto V_120;
V_23 = F_4 ( V_2 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = F_115 ( V_2 ) ;
V_120:
F_72 ( V_2 ) ;
return V_23 ;
}
int F_121 ( struct V_150 * V_151 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_3 * V_154 ;
struct V_39 * V_10 = V_151 -> V_10 ;
int V_155 , V_156 ;
int V_23 ;
V_9 = F_122 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) )
return F_14 ( V_9 ) ;
V_154 = F_112 ( V_2 , V_10 -> V_75 ) ;
if ( F_13 ( V_154 ) )
return F_14 ( V_154 ) ;
if ( ! V_151 -> V_47 ) {
F_3 ( V_151 -> V_88 ) ;
F_3 ( V_151 -> V_153 ) ;
V_23 = F_123 ( V_9 , NULL ) ;
if ( V_23 != 0 )
return V_23 ;
V_9 -> V_37 = false ;
V_23 = F_113 ( V_154 , NULL ) ;
if ( V_23 != 0 )
return V_23 ;
F_114 ( V_154 , NULL ) ;
goto V_85;
}
F_3 ( ! V_151 -> V_88 ) ;
F_3 ( ! V_151 -> V_153 ) ;
V_23 = F_123 ( V_9 , V_151 -> V_47 ) ;
if ( V_23 != 0 )
return V_23 ;
V_9 -> V_37 = true ;
V_23 = F_113 ( V_154 , V_10 ) ;
if ( V_23 != 0 )
return V_23 ;
F_124 ( V_151 -> V_47 , & V_155 , & V_156 ) ;
F_114 ( V_154 , V_151 -> V_88 ) ;
V_154 -> V_140 = 0 ;
V_154 -> V_141 = 0 ;
V_154 -> V_142 = V_155 ;
V_154 -> V_143 = V_156 ;
V_154 -> V_78 = V_151 -> V_77 << 16 ;
V_154 -> V_80 = V_151 -> V_79 << 16 ;
if ( F_125 ( V_154 -> V_157 ) ) {
V_154 -> V_144 = V_156 << 16 ;
V_154 -> V_145 = V_155 << 16 ;
} else {
V_154 -> V_144 = V_155 << 16 ;
V_154 -> V_145 = V_156 << 16 ;
}
V_85:
V_23 = F_118 ( V_2 , V_151 ) ;
if ( V_23 )
return V_23 ;
return 0 ;
}
int F_126 ( struct V_53 * V_34 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 ;
struct V_13 * V_38 ;
struct V_15 * V_158 ;
struct V_3 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_39 * V_10 ;
int V_23 , V_22 ;
V_2 = F_111 ( V_34 ) ;
if ( ! V_2 )
return - V_111 ;
V_2 -> V_148 = V_147 ;
F_127 (crtc, dev) {
V_9 = F_122 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) ) {
V_23 = F_14 ( V_9 ) ;
goto free;
}
V_9 -> V_37 = false ;
V_23 = F_16 ( V_9 , NULL ) ;
if ( V_23 < 0 )
goto free;
V_23 = F_34 ( V_2 , V_10 ) ;
if ( V_23 < 0 )
goto free;
V_23 = F_33 ( V_2 , V_10 ) ;
if ( V_23 < 0 )
goto free;
}
F_128 (state, conn, conn_state, i) {
V_23 = F_15 ( V_38 , NULL ) ;
if ( V_23 < 0 )
goto free;
}
F_129 (state, plane, plane_state, i) {
V_23 = F_113 ( V_5 , NULL ) ;
if ( V_23 < 0 )
goto free;
F_114 ( V_5 , NULL ) ;
}
V_23 = F_115 ( V_2 ) ;
free:
F_72 ( V_2 ) ;
return V_23 ;
}
void F_130 ( struct V_53 * V_34 )
{
struct V_146 V_147 ;
int V_23 ;
F_131 ( & V_147 , 0 ) ;
while ( 1 ) {
V_23 = F_132 ( V_34 , & V_147 ) ;
if ( ! V_23 )
V_23 = F_126 ( V_34 , & V_147 ) ;
if ( V_23 != - V_159 )
break;
F_133 ( & V_147 ) ;
}
if ( V_23 )
F_89 ( L_32 , V_23 ) ;
F_134 ( & V_147 ) ;
F_135 ( & V_147 ) ;
}
struct V_1 * F_136 ( struct V_53 * V_34 )
{
struct V_146 V_147 ;
struct V_1 * V_2 ;
int V_160 ;
F_131 ( & V_147 , 0 ) ;
V_161:
V_160 = F_132 ( V_34 , & V_147 ) ;
if ( V_160 < 0 ) {
V_2 = F_137 ( V_160 ) ;
goto V_162;
}
V_2 = F_138 ( V_34 , & V_147 ) ;
if ( F_13 ( V_2 ) )
goto V_162;
V_160 = F_126 ( V_34 , & V_147 ) ;
if ( V_160 < 0 ) {
F_72 ( V_2 ) ;
V_2 = F_137 ( V_160 ) ;
goto V_162;
}
V_162:
if ( F_14 ( V_2 ) == - V_159 ) {
F_133 ( & V_147 ) ;
goto V_161;
}
F_134 ( & V_147 ) ;
F_135 ( & V_147 ) ;
return V_2 ;
}
int F_139 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
int V_22 ;
struct V_6 * V_7 ;
struct V_3 * V_62 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
struct V_39 * V_10 ;
struct V_8 * V_44 ;
V_2 -> V_148 = V_147 ;
F_53 (state, plane, new_plane_state, i)
V_2 -> V_138 [ V_22 ] . V_64 = V_7 -> V_2 ;
F_24 (state, crtc, new_crtc_state, i)
V_2 -> V_91 [ V_22 ] . V_64 = V_10 -> V_2 ;
F_5 (state, connector, new_conn_state, i)
V_2 -> V_137 [ V_22 ] . V_64 = V_16 -> V_2 ;
return F_115 ( V_2 ) ;
}
int F_140 ( struct V_53 * V_34 ,
struct V_1 * V_2 )
{
struct V_146 V_147 ;
int V_160 ;
F_141 ( V_34 ) ;
F_131 ( & V_147 , 0 ) ;
while ( 1 ) {
V_160 = F_132 ( V_34 , & V_147 ) ;
if ( V_160 )
goto V_35;
V_160 = F_139 ( V_2 , & V_147 ) ;
V_35:
if ( V_160 != - V_159 )
break;
F_133 ( & V_147 ) ;
}
F_134 ( & V_147 ) ;
F_135 ( & V_147 ) ;
return V_160 ;
}
int
F_142 ( struct V_39 * V_10 ,
struct V_71 * V_163 ,
T_2 V_164 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_23 = 0 ;
V_2 = F_111 ( V_10 -> V_34 ) ;
if ( ! V_2 )
return - V_111 ;
V_2 -> V_148 = V_10 -> V_34 -> V_59 . V_148 ;
V_161:
V_9 = F_122 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) ) {
V_23 = F_14 ( V_9 ) ;
goto V_120;
}
V_23 = F_143 ( V_10 , V_9 ,
V_163 , V_164 ) ;
if ( V_23 )
goto V_120;
V_23 = F_115 ( V_2 ) ;
V_120:
if ( V_23 == - V_159 )
goto V_165;
F_72 ( V_2 ) ;
return V_23 ;
V_165:
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
goto V_161;
}
int
F_146 ( struct V_6 * V_7 ,
struct V_71 * V_163 ,
T_2 V_164 )
{
struct V_1 * V_2 ;
struct V_3 * V_5 ;
int V_23 = 0 ;
V_2 = F_111 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_111 ;
V_2 -> V_148 = V_7 -> V_34 -> V_59 . V_148 ;
V_161:
V_5 = F_112 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) ) {
V_23 = F_14 ( V_5 ) ;
goto V_120;
}
V_23 = F_147 ( V_7 , V_5 ,
V_163 , V_164 ) ;
if ( V_23 )
goto V_120;
V_23 = F_115 ( V_2 ) ;
V_120:
if ( V_23 == - V_159 )
goto V_165;
F_72 ( V_2 ) ;
return V_23 ;
V_165:
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
goto V_161;
}
int
F_148 ( struct V_15 * V_16 ,
struct V_71 * V_163 ,
T_2 V_164 )
{
struct V_1 * V_2 ;
struct V_13 * V_166 ;
int V_23 = 0 ;
V_2 = F_111 ( V_16 -> V_34 ) ;
if ( ! V_2 )
return - V_111 ;
V_2 -> V_148 = V_16 -> V_34 -> V_59 . V_148 ;
V_161:
V_166 = F_12 ( V_2 , V_16 ) ;
if ( F_13 ( V_166 ) ) {
V_23 = F_14 ( V_166 ) ;
goto V_120;
}
V_23 = F_149 ( V_16 , V_166 ,
V_163 , V_164 ) ;
if ( V_23 )
goto V_120;
V_23 = F_115 ( V_2 ) ;
V_120:
if ( V_23 == - V_159 )
goto V_165;
F_72 ( V_2 ) ;
return V_23 ;
V_165:
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
goto V_161;
}
static int F_150 (
struct V_1 * V_2 ,
struct V_39 * V_10 ,
struct V_139 * V_88 ,
struct V_167 * V_115 ,
T_1 V_122 )
{
struct V_6 * V_7 = V_10 -> V_75 ;
struct V_3 * V_5 ;
struct V_8 * V_9 ;
int V_23 = 0 ;
V_9 = F_122 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) )
return F_14 ( V_9 ) ;
V_9 -> V_115 = V_115 ;
V_9 -> V_168 = V_122 ;
V_5 = F_112 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) )
return F_14 ( V_5 ) ;
V_23 = F_113 ( V_5 , V_10 ) ;
if ( V_23 != 0 )
return V_23 ;
F_114 ( V_5 , V_88 ) ;
V_2 -> V_169 = false ;
if ( ! V_9 -> V_37 ) {
F_8 ( L_33 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
return - V_33 ;
}
return V_23 ;
}
int F_151 ( struct V_39 * V_10 ,
struct V_139 * V_88 ,
struct V_167 * V_115 ,
T_1 V_122 ,
struct V_146 * V_147 )
{
struct V_6 * V_7 = V_10 -> V_75 ;
struct V_1 * V_2 ;
int V_23 = 0 ;
V_2 = F_111 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_111 ;
V_2 -> V_148 = V_147 ;
V_23 = F_150 ( V_2 , V_10 , V_88 , V_115 , V_122 ) ;
if ( V_23 != 0 )
goto V_120;
V_23 = F_152 ( V_2 ) ;
V_120:
F_72 ( V_2 ) ;
return V_23 ;
}
int F_153 (
struct V_39 * V_10 ,
struct V_139 * V_88 ,
struct V_167 * V_115 ,
T_1 V_122 ,
T_1 V_170 ,
struct V_146 * V_147 )
{
struct V_6 * V_7 = V_10 -> V_75 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_23 = 0 ;
V_2 = F_111 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_111 ;
V_2 -> V_148 = V_147 ;
V_23 = F_150 ( V_2 , V_10 , V_88 , V_115 , V_122 ) ;
if ( V_23 != 0 )
goto V_120;
V_9 = F_2 ( V_2 , V_10 ) ;
if ( F_3 ( ! V_9 ) ) {
V_23 = - V_33 ;
goto V_120;
}
V_9 -> V_171 = V_170 ;
V_23 = F_152 ( V_2 ) ;
V_120:
F_72 ( V_2 ) ;
return V_23 ;
}
int F_154 ( struct V_15 * V_16 ,
int V_47 )
{
struct V_172 * V_173 = & V_16 -> V_34 -> V_59 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_39 * V_10 ;
struct V_15 * V_174 ;
struct V_17 V_18 ;
int V_23 ;
bool V_37 = false ;
int V_175 = V_16 -> V_68 ;
if ( V_47 != V_74 )
V_47 = V_69 ;
V_16 -> V_68 = V_47 ;
V_10 = V_16 -> V_2 -> V_10 ;
if ( ! V_10 )
return 0 ;
V_2 = F_111 ( V_16 -> V_34 ) ;
if ( ! V_2 )
return - V_111 ;
V_2 -> V_148 = V_10 -> V_34 -> V_59 . V_148 ;
V_161:
V_9 = F_122 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) ) {
V_23 = F_14 ( V_9 ) ;
goto V_120;
}
F_3 ( ! F_29 ( & V_173 -> V_60 ) ) ;
F_9 ( V_16 -> V_34 , & V_18 ) ;
F_10 (tmp_connector, &conn_iter) {
if ( V_174 -> V_2 -> V_10 != V_10 )
continue;
if ( V_174 -> V_68 == V_74 ) {
V_37 = true ;
break;
}
}
F_17 ( & V_18 ) ;
V_9 -> V_37 = V_37 ;
V_23 = F_115 ( V_2 ) ;
V_120:
if ( V_23 == - V_159 )
goto V_165;
if ( V_23 != 0 )
V_16 -> V_68 = V_175 ;
F_72 ( V_2 ) ;
return V_23 ;
V_165:
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
goto V_161;
}
struct V_19 *
F_6 ( struct V_15 * V_16 )
{
F_3 ( V_16 -> V_176 [ 1 ] ) ;
return F_155 ( V_16 -> V_34 , V_16 -> V_176 [ 0 ] ) ;
}
void F_156 ( struct V_39 * V_10 )
{
if ( V_10 -> V_2 )
F_157 ( V_10 -> V_2 ) ;
F_158 ( V_10 -> V_2 ) ;
V_10 -> V_2 = F_93 ( sizeof( * V_10 -> V_2 ) , V_110 ) ;
if ( V_10 -> V_2 )
V_10 -> V_2 -> V_10 = V_10 ;
}
void F_159 ( struct V_39 * V_10 ,
struct V_8 * V_2 )
{
memcpy ( V_2 , V_10 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_177 )
F_160 ( V_2 -> V_177 ) ;
if ( V_2 -> V_178 )
F_160 ( V_2 -> V_178 ) ;
if ( V_2 -> V_179 )
F_160 ( V_2 -> V_179 ) ;
if ( V_2 -> V_180 )
F_160 ( V_2 -> V_180 ) ;
V_2 -> V_45 = false ;
V_2 -> V_58 = false ;
V_2 -> V_11 = false ;
V_2 -> V_43 = false ;
V_2 -> V_181 = false ;
V_2 -> V_182 = false ;
V_2 -> V_115 = NULL ;
V_2 -> V_168 = 0 ;
}
struct V_8 *
F_161 ( struct V_39 * V_10 )
{
struct V_8 * V_2 ;
if ( F_3 ( ! V_10 -> V_2 ) )
return NULL ;
V_2 = F_162 ( sizeof( * V_2 ) , V_110 ) ;
if ( V_2 )
F_159 ( V_10 , V_2 ) ;
return V_2 ;
}
void F_157 ( struct V_8 * V_2 )
{
F_163 ( V_2 -> V_177 ) ;
F_163 ( V_2 -> V_178 ) ;
F_163 ( V_2 -> V_179 ) ;
F_163 ( V_2 -> V_180 ) ;
}
void F_164 ( struct V_39 * V_10 ,
struct V_8 * V_2 )
{
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
}
void F_165 ( struct V_6 * V_7 )
{
if ( V_7 -> V_2 )
F_166 ( V_7 -> V_2 ) ;
F_158 ( V_7 -> V_2 ) ;
V_7 -> V_2 = F_93 ( sizeof( * V_7 -> V_2 ) , V_110 ) ;
if ( V_7 -> V_2 ) {
V_7 -> V_2 -> V_7 = V_7 ;
V_7 -> V_2 -> V_157 = V_183 ;
}
}
void F_167 ( struct V_6 * V_7 ,
struct V_3 * V_2 )
{
memcpy ( V_2 , V_7 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_88 )
F_168 ( V_2 -> V_88 ) ;
V_2 -> V_87 = NULL ;
}
struct V_3 *
F_169 ( struct V_6 * V_7 )
{
struct V_3 * V_2 ;
if ( F_3 ( ! V_7 -> V_2 ) )
return NULL ;
V_2 = F_162 ( sizeof( * V_2 ) , V_110 ) ;
if ( V_2 )
F_167 ( V_7 , V_2 ) ;
return V_2 ;
}
void F_166 ( struct V_3 * V_2 )
{
if ( V_2 -> V_88 )
F_170 ( V_2 -> V_88 ) ;
if ( V_2 -> V_87 )
F_55 ( V_2 -> V_87 ) ;
}
void F_171 ( struct V_6 * V_7 ,
struct V_3 * V_2 )
{
F_166 ( V_2 ) ;
F_158 ( V_2 ) ;
}
void
F_172 ( struct V_15 * V_16 ,
struct V_13 * V_38 )
{
if ( V_38 )
V_38 -> V_16 = V_16 ;
V_16 -> V_2 = V_38 ;
}
void F_173 ( struct V_15 * V_16 )
{
struct V_13 * V_38 =
F_93 ( sizeof( * V_38 ) , V_110 ) ;
if ( V_16 -> V_2 )
F_174 ( V_16 -> V_2 ) ;
F_158 ( V_16 -> V_2 ) ;
F_172 ( V_16 , V_38 ) ;
}
void
F_175 ( struct V_15 * V_16 ,
struct V_13 * V_2 )
{
memcpy ( V_2 , V_16 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_10 )
F_176 ( V_16 ) ;
}
struct V_13 *
F_177 ( struct V_15 * V_16 )
{
struct V_13 * V_2 ;
if ( F_3 ( ! V_16 -> V_2 ) )
return NULL ;
V_2 = F_162 ( sizeof( * V_2 ) , V_110 ) ;
if ( V_2 )
F_175 ( V_16 , V_2 ) ;
return V_2 ;
}
struct V_1 *
F_138 ( struct V_53 * V_34 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 ;
struct V_15 * V_158 ;
struct V_17 V_18 ;
struct V_6 * V_7 ;
struct V_39 * V_10 ;
int V_160 = 0 ;
V_2 = F_111 ( V_34 ) ;
if ( ! V_2 )
return F_137 ( - V_111 ) ;
V_2 -> V_148 = V_147 ;
F_127 (crtc, dev) {
struct V_8 * V_9 ;
V_9 = F_122 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) ) {
V_160 = F_14 ( V_9 ) ;
goto free;
}
}
F_178 (plane, dev) {
struct V_3 * V_5 ;
V_5 = F_112 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) ) {
V_160 = F_14 ( V_5 ) ;
goto free;
}
}
F_9 ( V_34 , & V_18 ) ;
F_10 (conn, &conn_iter) {
struct V_13 * V_38 ;
V_38 = F_12 ( V_2 , V_158 ) ;
if ( F_13 ( V_38 ) ) {
V_160 = F_14 ( V_38 ) ;
F_17 ( & V_18 ) ;
goto free;
}
}
F_17 ( & V_18 ) ;
V_2 -> V_148 = NULL ;
free:
if ( V_160 < 0 ) {
F_72 ( V_2 ) ;
V_2 = F_137 ( V_160 ) ;
}
return V_2 ;
}
void
F_174 ( struct V_13 * V_2 )
{
if ( V_2 -> V_10 )
F_179 ( V_2 -> V_16 ) ;
}
void F_180 ( struct V_15 * V_16 ,
struct V_13 * V_2 )
{
F_174 ( V_2 ) ;
F_158 ( V_2 ) ;
}
int F_181 ( struct V_39 * V_10 ,
T_3 * V_184 , T_3 * V_185 , T_3 * V_186 ,
T_1 V_187 ,
struct V_146 * V_147 )
{
struct V_53 * V_34 = V_10 -> V_34 ;
struct V_172 * V_173 = & V_34 -> V_59 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_188 * V_189 = NULL ;
struct V_190 * V_191 ;
int V_22 , V_23 = 0 ;
V_2 = F_111 ( V_10 -> V_34 ) ;
if ( ! V_2 )
return - V_111 ;
V_189 = F_182 ( V_34 ,
sizeof( struct V_190 ) * V_187 ,
NULL ) ;
if ( F_13 ( V_189 ) ) {
V_23 = F_14 ( V_189 ) ;
V_189 = NULL ;
goto V_120;
}
V_191 = (struct V_190 * ) V_189 -> V_192 ;
for ( V_22 = 0 ; V_22 < V_187 ; V_22 ++ ) {
V_191 [ V_22 ] . V_184 = V_184 [ V_22 ] ;
V_191 [ V_22 ] . V_185 = V_185 [ V_22 ] ;
V_191 [ V_22 ] . V_186 = V_186 [ V_22 ] ;
}
V_2 -> V_148 = V_147 ;
V_9 = F_122 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) ) {
V_23 = F_14 ( V_9 ) ;
goto V_120;
}
V_23 = F_143 ( V_10 , V_9 ,
V_173 -> V_193 , 0 ) ;
if ( V_23 )
goto V_120;
V_23 = F_143 ( V_10 , V_9 ,
V_173 -> V_194 , 0 ) ;
if ( V_23 )
goto V_120;
V_23 = F_143 ( V_10 , V_9 ,
V_173 -> V_195 , V_189 -> V_30 . V_31 ) ;
if ( V_23 )
goto V_120;
V_23 = F_115 ( V_2 ) ;
V_120:
F_72 ( V_2 ) ;
F_163 ( V_189 ) ;
return V_23 ;
}
