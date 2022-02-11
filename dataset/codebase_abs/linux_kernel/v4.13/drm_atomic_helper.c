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
return V_23 ;
}
static void
F_43 ( struct V_57 * V_34 , struct V_1 * V_68 )
{
struct V_15 * V_16 ;
struct V_13 * V_69 , * V_14 ;
struct V_39 * V_10 ;
struct V_8 * V_58 , * V_44 ;
int V_22 ;
F_20 (old_state, connector, old_conn_state, new_conn_state, i) {
const struct V_48 * V_25 ;
struct V_19 * V_20 ;
if ( ! V_69 -> V_10 )
continue;
V_58 = F_44 ( V_68 , V_69 -> V_10 ) ;
if ( ! V_58 -> V_37 ||
! F_37 ( V_69 -> V_10 -> V_2 ) )
continue;
V_20 = V_69 -> V_29 ;
if ( F_3 ( ! V_20 ) )
continue;
V_25 = V_20 -> V_26 ;
F_8 ( L_25 ,
V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
F_45 ( V_20 -> V_49 ) ;
if ( V_25 ) {
if ( V_14 -> V_10 && V_25 -> V_70 )
V_25 -> V_70 ( V_20 ) ;
else if ( V_25 -> V_71 )
V_25 -> V_71 ( V_20 ) ;
else if ( V_25 -> V_72 )
V_25 -> V_72 ( V_20 , V_73 ) ;
}
F_46 ( V_20 -> V_49 ) ;
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
if ( V_44 -> V_52 && V_25 -> V_70 )
V_25 -> V_70 ( V_10 ) ;
else if ( V_25 -> V_74 )
V_25 -> V_74 ( V_10 , V_58 ) ;
else if ( V_25 -> V_71 )
V_25 -> V_71 ( V_10 ) ;
else
V_25 -> V_72 ( V_10 , V_73 ) ;
}
}
void
F_47 ( struct V_57 * V_34 ,
struct V_1 * V_68 )
{
struct V_15 * V_16 ;
struct V_13 * V_69 , * V_14 ;
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
if ( ( ! V_10 && V_69 -> V_10 ) ||
( V_10 && F_37 ( V_10 -> V_2 ) ) ) {
struct V_75 * V_76 =
V_34 -> V_63 . V_77 ;
int V_47 = V_73 ;
if ( V_10 && V_10 -> V_2 -> V_37 )
V_47 = V_78 ;
V_16 -> V_72 = V_47 ;
F_48 ( & V_16 -> V_30 ,
V_76 , V_47 ) ;
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
struct V_6 * V_79 = V_10 -> V_79 ;
struct V_3 * V_66 ;
V_10 -> V_47 = V_44 -> V_47 ;
V_10 -> V_80 = V_44 -> V_52 ;
V_66 =
F_49 ( V_68 , V_79 ) ;
if ( V_66 && V_66 -> V_10 == V_10 ) {
V_10 -> V_81 = V_66 -> V_82 >> 16 ;
V_10 -> V_83 = V_66 -> V_84 >> 16 ;
}
if ( V_44 -> V_52 )
F_50 ( V_10 ,
& V_44 -> V_46 ) ;
}
}
static void
F_51 ( struct V_57 * V_34 , struct V_1 * V_68 )
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
if ( V_44 -> V_52 && V_25 -> V_85 ) {
F_8 ( L_27 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
V_25 -> V_85 ( V_10 ) ;
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
if ( V_25 && V_25 -> V_86 ) {
V_25 -> V_86 ( V_20 , V_44 ,
V_14 ) ;
} else if ( V_25 && V_25 -> V_87 ) {
V_25 -> V_87 ( V_20 , V_47 , V_46 ) ;
}
F_52 ( V_20 -> V_49 , V_47 , V_46 ) ;
}
}
void F_53 ( struct V_57 * V_34 ,
struct V_1 * V_68 )
{
F_43 ( V_34 , V_68 ) ;
F_47 ( V_34 , V_68 ) ;
F_51 ( V_34 , V_68 ) ;
}
void F_54 ( struct V_57 * V_34 ,
struct V_1 * V_68 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
int V_22 ;
F_24 (old_state, crtc, new_crtc_state, i) {
const struct V_51 * V_25 ;
if ( ! F_37 ( V_44 ) )
continue;
if ( ! V_44 -> V_37 )
continue;
V_25 = V_10 -> V_26 ;
if ( V_44 -> V_52 ) {
F_8 ( L_29 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
if ( V_25 -> V_52 )
V_25 -> V_52 ( V_10 ) ;
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
struct V_1 * V_68 )
{
struct V_39 * V_10 ;
struct V_8 * V_58 , * V_44 ;
int V_22 , V_23 ;
unsigned V_92 = 0 ;
if ( V_68 -> V_93 )
return;
F_33 (old_state, crtc, old_crtc_state, new_crtc_state, i) {
if ( ! V_44 -> V_37 || ! V_44 -> V_11 )
continue;
V_23 = F_62 ( V_10 ) ;
if ( V_23 != 0 )
continue;
V_92 |= F_63 ( V_10 ) ;
V_68 -> V_94 [ V_22 ] . V_95 = F_64 ( V_10 ) ;
}
F_65 (old_state, crtc, old_crtc_state, i) {
if ( ! ( V_92 & F_63 ( V_10 ) ) )
continue;
V_23 = F_66 ( V_34 -> V_96 [ V_22 ] . V_97 ,
V_68 -> V_94 [ V_22 ] . V_95 !=
F_64 ( V_10 ) ,
F_67 ( 50 ) ) ;
F_68 ( ! V_23 , L_31 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
F_69 ( V_10 ) ;
}
}
void F_70 ( struct V_1 * V_68 )
{
struct V_57 * V_34 = V_68 -> V_34 ;
F_53 ( V_34 , V_68 ) ;
F_71 ( V_34 , V_68 , 0 ) ;
F_54 ( V_34 , V_68 ) ;
F_72 ( V_68 ) ;
F_61 ( V_34 , V_68 ) ;
F_73 ( V_34 , V_68 ) ;
}
static void F_74 ( struct V_1 * V_68 )
{
struct V_57 * V_34 = V_68 -> V_34 ;
const struct V_98 * V_25 ;
V_25 = V_34 -> V_63 . V_26 ;
F_57 ( V_34 , V_68 , false ) ;
F_75 ( V_68 ) ;
if ( V_25 && V_25 -> V_99 )
V_25 -> V_99 ( V_68 ) ;
else
F_70 ( V_68 ) ;
F_76 ( V_68 ) ;
F_77 ( V_68 ) ;
}
static void F_78 ( struct V_100 * V_101 )
{
struct V_1 * V_2 = F_79 ( V_101 ,
struct V_1 ,
F_78 ) ;
F_74 ( V_2 ) ;
}
int F_80 ( struct V_57 * V_34 ,
struct V_1 * V_2 ,
bool V_102 )
{
int V_23 ;
V_23 = F_81 ( V_2 , V_102 ) ;
if ( V_23 )
return V_23 ;
F_82 ( & V_2 -> F_78 , F_78 ) ;
V_23 = F_83 ( V_34 , V_2 ) ;
if ( V_23 )
return V_23 ;
if ( ! V_102 ) {
V_23 = F_57 ( V_34 , V_2 , true ) ;
if ( V_23 ) {
F_73 ( V_34 , V_2 ) ;
return V_23 ;
}
}
F_84 ( V_2 , true ) ;
F_85 ( V_2 ) ;
if ( V_102 )
F_86 ( V_103 , & V_2 -> F_78 ) ;
else
F_74 ( V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_39 * V_10 , bool V_102 )
{
struct V_104 * V_88 , * V_105 = NULL ;
bool V_106 = true ;
int V_22 ;
long V_23 = 0 ;
F_88 ( & V_10 -> V_107 ) ;
V_22 = 0 ;
F_89 (commit, &crtc->commit_list, commit_entry) {
if ( V_22 == 0 ) {
V_106 = F_90 ( & V_88 -> V_108 ) ;
if ( ! V_106 && V_102 ) {
F_91 ( & V_10 -> V_107 ) ;
return - V_109 ;
}
} else if ( V_22 == 1 ) {
V_105 = V_88 ;
F_92 ( V_105 ) ;
break;
}
V_22 ++ ;
}
F_91 ( & V_10 -> V_107 ) ;
if ( ! V_105 )
return 0 ;
V_23 = F_93 ( & V_105 -> V_110 ,
10 * V_111 ) ;
if ( V_23 == 0 )
F_94 ( L_32 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
F_95 ( V_105 ) ;
return V_23 < 0 ? V_23 : 0 ;
}
static void F_96 ( struct V_112 * V_112 )
{
struct V_104 * V_88 = F_79 ( V_112 ,
F_97 ( * V_88 ) ,
V_108 ) ;
F_95 ( V_88 ) ;
}
int F_81 ( struct V_1 * V_2 ,
bool V_102 )
{
struct V_39 * V_10 ;
struct V_8 * V_58 , * V_44 ;
struct V_104 * V_88 ;
int V_22 , V_23 ;
F_33 (state, crtc, old_crtc_state, new_crtc_state, i) {
V_88 = F_98 ( sizeof( * V_88 ) , V_113 ) ;
if ( ! V_88 )
return - V_114 ;
F_99 ( & V_88 -> V_108 ) ;
F_99 ( & V_88 -> V_115 ) ;
F_99 ( & V_88 -> V_110 ) ;
F_100 ( & V_88 -> V_116 ) ;
F_101 ( & V_88 -> V_117 ) ;
V_88 -> V_10 = V_10 ;
V_2 -> V_94 [ V_22 ] . V_88 = V_88 ;
V_23 = F_87 ( V_10 , V_102 ) ;
if ( V_23 )
return V_23 ;
if ( ! V_58 -> V_37 && ! V_44 -> V_37 ) {
F_102 ( & V_88 -> V_108 ) ;
continue;
}
if ( V_2 -> V_93 ) {
F_102 ( & V_88 -> V_108 ) ;
continue;
}
if ( ! V_44 -> V_118 ) {
V_88 -> V_118 = F_98 ( sizeof( * V_88 -> V_118 ) ,
V_113 ) ;
if ( ! V_88 -> V_118 )
return - V_114 ;
V_44 -> V_118 = V_88 -> V_118 ;
}
V_44 -> V_118 -> V_30 . V_112 = & V_88 -> V_108 ;
V_44 -> V_118 -> V_30 . V_119 = F_96 ;
F_92 ( V_88 ) ;
}
return 0 ;
}
static struct V_104 * F_103 ( struct V_39 * V_10 )
{
struct V_104 * V_88 ;
int V_22 = 0 ;
F_89 (commit, &crtc->commit_list, commit_entry) {
if ( V_22 == 1 )
return V_88 ;
V_22 ++ ;
}
return NULL ;
}
void F_75 ( struct V_1 * V_68 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_104 * V_88 ;
int V_22 ;
long V_23 ;
F_24 (old_state, crtc, new_crtc_state, i) {
F_88 ( & V_10 -> V_107 ) ;
V_88 = F_103 ( V_10 ) ;
if ( V_88 )
F_92 ( V_88 ) ;
F_91 ( & V_10 -> V_107 ) ;
if ( ! V_88 )
continue;
V_23 = F_104 ( & V_88 -> V_115 ,
10 * V_111 ) ;
if ( V_23 == 0 )
F_94 ( L_33 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
V_23 = F_104 ( & V_88 -> V_108 ,
10 * V_111 ) ;
if ( V_23 == 0 )
F_94 ( L_34 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
F_95 ( V_88 ) ;
}
}
void F_72 ( struct V_1 * V_68 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_104 * V_88 ;
int V_22 ;
F_24 (old_state, crtc, new_crtc_state, i) {
V_88 = V_68 -> V_94 [ V_22 ] . V_88 ;
if ( ! V_88 )
continue;
F_3 ( V_44 -> V_118 ) ;
F_88 ( & V_10 -> V_107 ) ;
F_102 ( & V_88 -> V_115 ) ;
F_91 ( & V_10 -> V_107 ) ;
}
}
void F_76 ( struct V_1 * V_68 )
{
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_104 * V_88 ;
int V_22 ;
long V_23 ;
F_24 (old_state, crtc, new_crtc_state, i) {
V_88 = V_68 -> V_94 [ V_22 ] . V_88 ;
if ( F_3 ( ! V_88 ) )
continue;
F_88 ( & V_10 -> V_107 ) ;
F_102 ( & V_88 -> V_110 ) ;
F_3 ( ! F_90 ( & V_88 -> V_115 ) ) ;
if ( F_90 ( & V_88 -> V_108 ) )
goto V_120;
F_91 ( & V_10 -> V_107 ) ;
V_23 = F_104 ( & V_88 -> V_108 ,
10 * V_111 ) ;
if ( V_23 == 0 )
F_94 ( L_34 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
F_88 ( & V_10 -> V_107 ) ;
V_120:
F_105 ( & V_88 -> V_116 ) ;
F_91 ( & V_10 -> V_107 ) ;
}
}
int F_83 ( struct V_57 * V_34 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_3 * V_66 ;
int V_23 , V_22 , V_121 ;
F_58 (state, plane, new_plane_state, i) {
const struct V_67 * V_25 ;
V_25 = V_7 -> V_26 ;
if ( V_25 -> V_122 ) {
V_23 = V_25 -> V_122 ( V_7 , V_66 ) ;
if ( V_23 )
goto V_123;
}
}
return 0 ;
V_123:
F_58 (state, plane, new_plane_state, j) {
const struct V_67 * V_25 ;
if ( V_121 >= V_22 )
continue;
V_25 = V_7 -> V_26 ;
if ( V_25 -> V_124 )
V_25 -> V_124 ( V_7 , V_66 ) ;
}
return V_23 ;
}
static bool F_106 ( const struct V_3 * V_2 )
{
return V_2 -> V_10 && V_2 -> V_10 -> V_2 -> V_37 ;
}
void F_71 ( struct V_57 * V_34 ,
struct V_1 * V_68 ,
T_1 V_125 )
{
struct V_39 * V_10 ;
struct V_8 * V_58 , * V_44 ;
struct V_6 * V_7 ;
struct V_3 * V_4 , * V_66 ;
int V_22 ;
bool V_126 = V_125 & V_127 ;
bool V_128 = V_125 & V_129 ;
F_33 (old_state, crtc, old_crtc_state, new_crtc_state, i) {
const struct V_51 * V_25 ;
V_25 = V_10 -> V_26 ;
if ( ! V_25 || ! V_25 -> V_130 )
continue;
if ( V_126 && ! V_44 -> V_37 )
continue;
V_25 -> V_130 ( V_10 , V_58 ) ;
}
F_41 (old_state, plane, old_plane_state, new_plane_state, i) {
const struct V_67 * V_25 ;
bool V_131 ;
V_25 = V_7 -> V_26 ;
if ( ! V_25 )
continue;
V_131 = F_107 ( V_4 ,
V_66 ) ;
if ( V_126 ) {
if ( ! V_131 && ! F_106 ( V_66 ) )
continue;
if ( V_131 && ! F_106 ( V_4 ) )
continue;
}
if ( V_131 && V_25 -> V_74 ) {
struct V_8 * V_9 ;
V_9 = V_4 -> V_10 -> V_2 ;
if ( F_37 ( V_9 ) &&
V_128 )
continue;
V_25 -> V_74 ( V_7 , V_4 ) ;
} else if ( V_66 -> V_10 || V_131 ) {
V_25 -> V_132 ( V_7 , V_4 ) ;
}
}
F_33 (old_state, crtc, old_crtc_state, new_crtc_state, i) {
const struct V_51 * V_25 ;
V_25 = V_10 -> V_26 ;
if ( ! V_25 || ! V_25 -> V_133 )
continue;
if ( V_126 && ! V_44 -> V_37 )
continue;
V_25 -> V_133 ( V_10 , V_58 ) ;
}
}
void
F_108 ( struct V_8 * V_58 )
{
const struct V_51 * V_134 ;
struct V_39 * V_10 = V_58 -> V_10 ;
struct V_1 * V_68 = V_58 -> V_2 ;
struct V_6 * V_7 ;
unsigned V_135 ;
V_135 = V_58 -> V_135 ;
V_135 |= V_10 -> V_2 -> V_135 ;
V_134 = V_10 -> V_26 ;
if ( V_134 && V_134 -> V_130 )
V_134 -> V_130 ( V_10 , V_58 ) ;
F_109 (plane, crtc->dev, plane_mask) {
struct V_3 * V_4 =
F_110 ( V_68 , V_7 ) ;
const struct V_67 * V_136 ;
V_136 = V_7 -> V_26 ;
if ( ! V_4 || ! V_136 )
continue;
F_3 ( V_7 -> V_2 -> V_10 && V_7 -> V_2 -> V_10 != V_10 ) ;
if ( F_107 ( V_4 , V_7 -> V_2 ) &&
V_136 -> V_74 )
V_136 -> V_74 ( V_7 , V_4 ) ;
else if ( V_7 -> V_2 -> V_10 ||
F_107 ( V_4 , V_7 -> V_2 ) )
V_136 -> V_132 ( V_7 , V_4 ) ;
}
if ( V_134 && V_134 -> V_133 )
V_134 -> V_133 ( V_10 , V_58 ) ;
}
void
F_111 ( struct V_8 * V_58 ,
bool V_137 )
{
struct V_39 * V_10 = V_58 -> V_10 ;
const struct V_51 * V_134 =
V_10 -> V_26 ;
struct V_6 * V_7 ;
if ( V_137 && V_134 && V_134 -> V_130 )
V_134 -> V_130 ( V_10 , NULL ) ;
F_112 (plane, old_crtc_state) {
const struct V_67 * V_136 =
V_7 -> V_26 ;
if ( ! V_136 )
continue;
F_3 ( ! V_136 -> V_74 ) ;
if ( V_136 -> V_74 )
V_136 -> V_74 ( V_7 , NULL ) ;
}
if ( V_137 && V_134 && V_134 -> V_133 )
V_134 -> V_133 ( V_10 , NULL ) ;
}
void F_73 ( struct V_57 * V_34 ,
struct V_1 * V_68 )
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
if ( V_25 -> V_124 )
V_25 -> V_124 ( V_7 , V_5 ) ;
}
}
void F_84 ( struct V_1 * V_2 ,
bool V_138 )
{
int V_22 ;
long V_23 ;
struct V_15 * V_16 ;
struct V_13 * V_69 , * V_14 ;
struct V_39 * V_10 ;
struct V_8 * V_58 , * V_44 ;
struct V_6 * V_7 ;
struct V_3 * V_4 , * V_66 ;
struct V_104 * V_88 ;
void * V_139 , * V_140 ;
const struct V_141 * V_25 ;
if ( V_138 ) {
F_24 (state, crtc, new_crtc_state, i) {
F_88 ( & V_10 -> V_107 ) ;
V_88 = F_113 ( & V_10 -> V_142 ,
struct V_104 , V_116 ) ;
if ( V_88 )
F_92 ( V_88 ) ;
F_91 ( & V_10 -> V_107 ) ;
if ( ! V_88 )
continue;
V_23 = F_104 ( & V_88 -> V_115 ,
10 * V_111 ) ;
if ( V_23 == 0 )
F_94 ( L_33 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
F_95 ( V_88 ) ;
}
}
F_20 (state, connector, old_conn_state, new_conn_state, i) {
F_3 ( V_16 -> V_2 != V_69 ) ;
V_69 -> V_2 = V_2 ;
V_14 -> V_2 = NULL ;
V_2 -> V_143 [ V_22 ] . V_2 = V_69 ;
V_16 -> V_2 = V_14 ;
}
F_33 (state, crtc, old_crtc_state, new_crtc_state, i) {
F_3 ( V_10 -> V_2 != V_58 ) ;
V_58 -> V_2 = V_2 ;
V_44 -> V_2 = NULL ;
V_2 -> V_94 [ V_22 ] . V_2 = V_58 ;
V_10 -> V_2 = V_44 ;
if ( V_2 -> V_94 [ V_22 ] . V_88 ) {
F_88 ( & V_10 -> V_107 ) ;
F_114 ( & V_2 -> V_94 [ V_22 ] . V_88 -> V_116 ,
& V_10 -> V_142 ) ;
F_91 ( & V_10 -> V_107 ) ;
V_2 -> V_94 [ V_22 ] . V_88 -> V_118 = NULL ;
}
}
F_41 (state, plane, old_plane_state, new_plane_state, i) {
F_3 ( V_7 -> V_2 != V_4 ) ;
V_4 -> V_2 = V_2 ;
V_66 -> V_2 = NULL ;
V_2 -> V_144 [ V_22 ] . V_2 = V_4 ;
V_7 -> V_2 = V_66 ;
}
F_115 (state, obj, obj_state, i, funcs)
V_25 -> V_145 ( V_139 , & V_2 -> V_146 [ V_22 ] . V_140 ) ;
}
int F_116 ( struct V_6 * V_7 ,
struct V_39 * V_10 ,
struct V_147 * V_91 ,
int V_148 , int V_149 ,
unsigned int V_150 , unsigned int V_151 ,
T_1 V_82 , T_1 V_84 ,
T_1 V_152 , T_1 V_153 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 ;
struct V_3 * V_5 ;
int V_23 = 0 ;
V_2 = F_117 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_156 = V_155 ;
V_5 = F_118 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) ) {
V_23 = F_14 ( V_5 ) ;
goto V_123;
}
V_23 = F_119 ( V_5 , V_10 ) ;
if ( V_23 != 0 )
goto V_123;
F_120 ( V_5 , V_91 ) ;
V_5 -> V_148 = V_148 ;
V_5 -> V_149 = V_149 ;
V_5 -> V_150 = V_150 ;
V_5 -> V_151 = V_151 ;
V_5 -> V_82 = V_82 ;
V_5 -> V_84 = V_84 ;
V_5 -> V_152 = V_152 ;
V_5 -> V_153 = V_153 ;
if ( V_7 == V_10 -> V_157 )
V_2 -> V_93 = true ;
V_23 = F_121 ( V_2 ) ;
V_123:
F_77 ( V_2 ) ;
return V_23 ;
}
int F_122 ( struct V_6 * V_7 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 ;
struct V_3 * V_5 ;
int V_23 = 0 ;
V_2 = F_117 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_156 = V_155 ;
V_5 = F_118 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) ) {
V_23 = F_14 ( V_5 ) ;
goto V_123;
}
if ( V_5 -> V_10 && ( V_7 == V_7 -> V_10 -> V_157 ) )
V_5 -> V_2 -> V_93 = true ;
V_23 = F_123 ( V_7 , V_5 ) ;
if ( V_23 != 0 )
goto V_123;
V_23 = F_121 ( V_2 ) ;
V_123:
F_77 ( V_2 ) ;
return V_23 ;
}
int F_123 ( struct V_6 * V_7 ,
struct V_3 * V_5 )
{
int V_23 ;
V_23 = F_119 ( V_5 , NULL ) ;
if ( V_23 != 0 )
return V_23 ;
F_120 ( V_5 , NULL ) ;
V_5 -> V_148 = 0 ;
V_5 -> V_149 = 0 ;
V_5 -> V_150 = 0 ;
V_5 -> V_151 = 0 ;
V_5 -> V_82 = 0 ;
V_5 -> V_84 = 0 ;
V_5 -> V_152 = 0 ;
V_5 -> V_153 = 0 ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_158 * V_159 )
{
struct V_57 * V_34 = V_159 -> V_10 -> V_34 ;
struct V_39 * V_10 ;
struct V_8 * V_44 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
int V_23 , V_22 ;
V_23 = F_125 ( & V_34 -> V_63 . V_64 ,
V_2 -> V_156 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_38 ( V_2 , V_159 -> V_10 ) ;
if ( V_23 )
return V_23 ;
F_5 (state, connector, new_conn_state, i) {
if ( V_14 -> V_10 == V_159 -> V_10 ) {
V_23 = F_15 ( V_14 ,
NULL ) ;
if ( V_23 )
return V_23 ;
V_14 -> V_65 = V_160 ;
}
}
for ( V_22 = 0 ; V_22 < V_159 -> V_161 ; V_22 ++ ) {
V_14 = F_12 ( V_2 ,
V_159 -> V_143 [ V_22 ] ) ;
if ( F_13 ( V_14 ) )
return F_14 ( V_14 ) ;
V_23 = F_15 ( V_14 ,
V_159 -> V_10 ) ;
if ( V_23 )
return V_23 ;
}
F_24 (state, crtc, new_crtc_state, i) {
if ( V_10 == V_159 -> V_10 )
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
int F_126 ( struct V_158 * V_159 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 ;
struct V_39 * V_10 = V_159 -> V_10 ;
int V_23 = 0 ;
V_2 = F_117 ( V_10 -> V_34 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_156 = V_155 ;
V_23 = F_127 ( V_159 , V_2 ) ;
if ( V_23 != 0 )
goto V_123;
V_23 = F_4 ( V_2 , true ) ;
if ( V_23 )
return V_23 ;
V_23 = F_121 ( V_2 ) ;
V_123:
F_77 ( V_2 ) ;
return V_23 ;
}
int F_127 ( struct V_158 * V_159 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_3 * V_162 ;
struct V_39 * V_10 = V_159 -> V_10 ;
int V_163 , V_164 ;
int V_23 ;
V_9 = F_128 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) )
return F_14 ( V_9 ) ;
V_162 = F_118 ( V_2 , V_10 -> V_79 ) ;
if ( F_13 ( V_162 ) )
return F_14 ( V_162 ) ;
if ( ! V_159 -> V_47 ) {
F_3 ( V_159 -> V_91 ) ;
F_3 ( V_159 -> V_161 ) ;
V_23 = F_129 ( V_9 , NULL ) ;
if ( V_23 != 0 )
return V_23 ;
V_9 -> V_37 = false ;
V_23 = F_119 ( V_162 , NULL ) ;
if ( V_23 != 0 )
return V_23 ;
F_120 ( V_162 , NULL ) ;
goto V_88;
}
F_3 ( ! V_159 -> V_91 ) ;
F_3 ( ! V_159 -> V_161 ) ;
V_23 = F_129 ( V_9 , V_159 -> V_47 ) ;
if ( V_23 != 0 )
return V_23 ;
V_9 -> V_37 = true ;
V_23 = F_119 ( V_162 , V_10 ) ;
if ( V_23 != 0 )
return V_23 ;
F_130 ( V_159 -> V_47 , & V_163 , & V_164 ) ;
F_120 ( V_162 , V_159 -> V_91 ) ;
V_162 -> V_148 = 0 ;
V_162 -> V_149 = 0 ;
V_162 -> V_150 = V_163 ;
V_162 -> V_151 = V_164 ;
V_162 -> V_82 = V_159 -> V_81 << 16 ;
V_162 -> V_84 = V_159 -> V_83 << 16 ;
if ( F_131 ( V_162 -> V_165 ) ) {
V_162 -> V_152 = V_164 << 16 ;
V_162 -> V_153 = V_163 << 16 ;
} else {
V_162 -> V_152 = V_163 << 16 ;
V_162 -> V_153 = V_164 << 16 ;
}
V_88:
V_23 = F_124 ( V_2 , V_159 ) ;
if ( V_23 )
return V_23 ;
return 0 ;
}
int F_132 ( struct V_57 * V_34 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 ;
struct V_13 * V_38 ;
struct V_15 * V_166 ;
struct V_3 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_39 * V_10 ;
int V_23 , V_22 ;
V_2 = F_117 ( V_34 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_156 = V_155 ;
F_133 (crtc, dev) {
V_9 = F_128 ( V_2 , V_10 ) ;
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
F_134 (state, conn, conn_state, i) {
V_23 = F_15 ( V_38 , NULL ) ;
if ( V_23 < 0 )
goto free;
}
F_135 (state, plane, plane_state, i) {
V_23 = F_119 ( V_5 , NULL ) ;
if ( V_23 < 0 )
goto free;
F_120 ( V_5 , NULL ) ;
}
V_23 = F_121 ( V_2 ) ;
free:
F_77 ( V_2 ) ;
return V_23 ;
}
void F_136 ( struct V_57 * V_34 )
{
struct V_154 V_155 ;
int V_23 ;
F_137 ( & V_155 , 0 ) ;
while ( 1 ) {
V_23 = F_138 ( V_34 , & V_155 ) ;
if ( ! V_23 )
V_23 = F_132 ( V_34 , & V_155 ) ;
if ( V_23 != - V_167 )
break;
F_139 ( & V_155 ) ;
}
if ( V_23 )
F_94 ( L_35 , V_23 ) ;
F_140 ( & V_155 ) ;
F_141 ( & V_155 ) ;
}
struct V_1 * F_142 ( struct V_57 * V_34 )
{
struct V_154 V_155 ;
struct V_1 * V_2 ;
int V_168 ;
F_137 ( & V_155 , 0 ) ;
V_169:
V_168 = F_138 ( V_34 , & V_155 ) ;
if ( V_168 < 0 ) {
V_2 = F_143 ( V_168 ) ;
goto V_170;
}
V_2 = F_144 ( V_34 , & V_155 ) ;
if ( F_13 ( V_2 ) )
goto V_170;
V_168 = F_132 ( V_34 , & V_155 ) ;
if ( V_168 < 0 ) {
F_77 ( V_2 ) ;
V_2 = F_143 ( V_168 ) ;
goto V_170;
}
V_170:
if ( F_14 ( V_2 ) == - V_167 ) {
F_139 ( & V_155 ) ;
goto V_169;
}
F_140 ( & V_155 ) ;
F_141 ( & V_155 ) ;
return V_2 ;
}
int F_145 ( struct V_1 * V_2 ,
struct V_154 * V_155 )
{
int V_22 ;
struct V_6 * V_7 ;
struct V_3 * V_66 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
struct V_39 * V_10 ;
struct V_8 * V_44 ;
V_2 -> V_156 = V_155 ;
F_58 (state, plane, new_plane_state, i)
V_2 -> V_144 [ V_22 ] . V_68 = V_7 -> V_2 ;
F_24 (state, crtc, new_crtc_state, i)
V_2 -> V_94 [ V_22 ] . V_68 = V_10 -> V_2 ;
F_5 (state, connector, new_conn_state, i)
V_2 -> V_143 [ V_22 ] . V_68 = V_16 -> V_2 ;
return F_121 ( V_2 ) ;
}
int F_146 ( struct V_57 * V_34 ,
struct V_1 * V_2 )
{
struct V_154 V_155 ;
int V_168 ;
F_147 ( V_34 ) ;
F_137 ( & V_155 , 0 ) ;
while ( 1 ) {
V_168 = F_138 ( V_34 , & V_155 ) ;
if ( V_168 )
goto V_35;
V_168 = F_145 ( V_2 , & V_155 ) ;
V_35:
if ( V_168 != - V_167 )
break;
F_139 ( & V_155 ) ;
}
F_140 ( & V_155 ) ;
F_141 ( & V_155 ) ;
return V_168 ;
}
int
F_148 ( struct V_39 * V_10 ,
struct V_75 * V_171 ,
T_2 V_172 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_23 = 0 ;
V_2 = F_117 ( V_10 -> V_34 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_156 = V_10 -> V_34 -> V_63 . V_156 ;
V_169:
V_9 = F_128 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) ) {
V_23 = F_14 ( V_9 ) ;
goto V_123;
}
V_23 = F_149 ( V_10 , V_9 ,
V_171 , V_172 ) ;
if ( V_23 )
goto V_123;
V_23 = F_121 ( V_2 ) ;
V_123:
if ( V_23 == - V_167 )
goto V_173;
F_77 ( V_2 ) ;
return V_23 ;
V_173:
F_150 ( V_2 ) ;
F_151 ( V_2 ) ;
goto V_169;
}
int
F_152 ( struct V_6 * V_7 ,
struct V_75 * V_171 ,
T_2 V_172 )
{
struct V_1 * V_2 ;
struct V_3 * V_5 ;
int V_23 = 0 ;
V_2 = F_117 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_156 = V_7 -> V_34 -> V_63 . V_156 ;
V_169:
V_5 = F_118 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) ) {
V_23 = F_14 ( V_5 ) ;
goto V_123;
}
V_23 = F_153 ( V_7 , V_5 ,
V_171 , V_172 ) ;
if ( V_23 )
goto V_123;
V_23 = F_121 ( V_2 ) ;
V_123:
if ( V_23 == - V_167 )
goto V_173;
F_77 ( V_2 ) ;
return V_23 ;
V_173:
F_150 ( V_2 ) ;
F_151 ( V_2 ) ;
goto V_169;
}
int
F_154 ( struct V_15 * V_16 ,
struct V_75 * V_171 ,
T_2 V_172 )
{
struct V_1 * V_2 ;
struct V_13 * V_174 ;
int V_23 = 0 ;
V_2 = F_117 ( V_16 -> V_34 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_156 = V_16 -> V_34 -> V_63 . V_156 ;
V_169:
V_174 = F_12 ( V_2 , V_16 ) ;
if ( F_13 ( V_174 ) ) {
V_23 = F_14 ( V_174 ) ;
goto V_123;
}
V_23 = F_155 ( V_16 , V_174 ,
V_171 , V_172 ) ;
if ( V_23 )
goto V_123;
V_23 = F_121 ( V_2 ) ;
V_123:
if ( V_23 == - V_167 )
goto V_173;
F_77 ( V_2 ) ;
return V_23 ;
V_173:
F_150 ( V_2 ) ;
F_151 ( V_2 ) ;
goto V_169;
}
static int F_156 (
struct V_1 * V_2 ,
struct V_39 * V_10 ,
struct V_147 * V_91 ,
struct V_175 * V_118 ,
T_1 V_125 )
{
struct V_6 * V_7 = V_10 -> V_79 ;
struct V_3 * V_5 ;
struct V_8 * V_9 ;
int V_23 = 0 ;
V_9 = F_128 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) )
return F_14 ( V_9 ) ;
V_9 -> V_118 = V_118 ;
V_9 -> V_176 = V_125 ;
V_5 = F_118 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) )
return F_14 ( V_5 ) ;
V_23 = F_119 ( V_5 , V_10 ) ;
if ( V_23 != 0 )
return V_23 ;
F_120 ( V_5 , V_91 ) ;
V_2 -> V_177 = false ;
if ( ! V_9 -> V_37 ) {
F_8 ( L_36 ,
V_10 -> V_30 . V_31 , V_10 -> V_32 ) ;
return - V_33 ;
}
return V_23 ;
}
int F_157 ( struct V_39 * V_10 ,
struct V_147 * V_91 ,
struct V_175 * V_118 ,
T_1 V_125 ,
struct V_154 * V_155 )
{
struct V_6 * V_7 = V_10 -> V_79 ;
struct V_1 * V_2 ;
int V_23 = 0 ;
V_2 = F_117 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_156 = V_155 ;
V_23 = F_156 ( V_2 , V_10 , V_91 , V_118 , V_125 ) ;
if ( V_23 != 0 )
goto V_123;
V_23 = F_158 ( V_2 ) ;
V_123:
F_77 ( V_2 ) ;
return V_23 ;
}
int F_159 (
struct V_39 * V_10 ,
struct V_147 * V_91 ,
struct V_175 * V_118 ,
T_1 V_125 ,
T_1 V_178 ,
struct V_154 * V_155 )
{
struct V_6 * V_7 = V_10 -> V_79 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_23 = 0 ;
V_2 = F_117 ( V_7 -> V_34 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_156 = V_155 ;
V_23 = F_156 ( V_2 , V_10 , V_91 , V_118 , V_125 ) ;
if ( V_23 != 0 )
goto V_123;
V_9 = F_2 ( V_2 , V_10 ) ;
if ( F_3 ( ! V_9 ) ) {
V_23 = - V_33 ;
goto V_123;
}
V_9 -> V_179 = V_178 ;
V_23 = F_158 ( V_2 ) ;
V_123:
F_77 ( V_2 ) ;
return V_23 ;
}
int F_160 ( struct V_15 * V_16 ,
int V_47 )
{
struct V_180 * V_181 = & V_16 -> V_34 -> V_63 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_39 * V_10 ;
struct V_15 * V_182 ;
struct V_17 V_18 ;
int V_23 ;
bool V_37 = false ;
int V_183 = V_16 -> V_72 ;
if ( V_47 != V_78 )
V_47 = V_73 ;
V_16 -> V_72 = V_47 ;
V_10 = V_16 -> V_2 -> V_10 ;
if ( ! V_10 )
return 0 ;
V_2 = F_117 ( V_16 -> V_34 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_156 = V_10 -> V_34 -> V_63 . V_156 ;
V_169:
V_9 = F_128 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) ) {
V_23 = F_14 ( V_9 ) ;
goto V_123;
}
F_3 ( ! F_34 ( & V_181 -> V_64 ) ) ;
F_9 ( V_16 -> V_34 , & V_18 ) ;
F_10 (tmp_connector, &conn_iter) {
if ( V_182 -> V_2 -> V_10 != V_10 )
continue;
if ( V_182 -> V_72 == V_78 ) {
V_37 = true ;
break;
}
}
F_17 ( & V_18 ) ;
V_9 -> V_37 = V_37 ;
V_23 = F_121 ( V_2 ) ;
V_123:
if ( V_23 == - V_167 )
goto V_173;
if ( V_23 != 0 )
V_16 -> V_72 = V_183 ;
F_77 ( V_2 ) ;
return V_23 ;
V_173:
F_150 ( V_2 ) ;
F_151 ( V_2 ) ;
goto V_169;
}
struct V_19 *
F_6 ( struct V_15 * V_16 )
{
F_3 ( V_16 -> V_184 [ 1 ] ) ;
return F_161 ( V_16 -> V_34 , V_16 -> V_184 [ 0 ] ) ;
}
void F_162 ( struct V_39 * V_10 )
{
if ( V_10 -> V_2 )
F_163 ( V_10 -> V_2 ) ;
F_164 ( V_10 -> V_2 ) ;
V_10 -> V_2 = F_98 ( sizeof( * V_10 -> V_2 ) , V_113 ) ;
if ( V_10 -> V_2 )
V_10 -> V_2 -> V_10 = V_10 ;
}
void F_165 ( struct V_39 * V_10 ,
struct V_8 * V_2 )
{
memcpy ( V_2 , V_10 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_185 )
F_166 ( V_2 -> V_185 ) ;
if ( V_2 -> V_186 )
F_166 ( V_2 -> V_186 ) ;
if ( V_2 -> V_187 )
F_166 ( V_2 -> V_187 ) ;
if ( V_2 -> V_188 )
F_166 ( V_2 -> V_188 ) ;
V_2 -> V_45 = false ;
V_2 -> V_62 = false ;
V_2 -> V_11 = false ;
V_2 -> V_43 = false ;
V_2 -> V_189 = false ;
V_2 -> V_190 = false ;
V_2 -> V_118 = NULL ;
V_2 -> V_176 = 0 ;
}
struct V_8 *
F_167 ( struct V_39 * V_10 )
{
struct V_8 * V_2 ;
if ( F_3 ( ! V_10 -> V_2 ) )
return NULL ;
V_2 = F_168 ( sizeof( * V_2 ) , V_113 ) ;
if ( V_2 )
F_165 ( V_10 , V_2 ) ;
return V_2 ;
}
void F_163 ( struct V_8 * V_2 )
{
F_169 ( V_2 -> V_185 ) ;
F_169 ( V_2 -> V_186 ) ;
F_169 ( V_2 -> V_187 ) ;
F_169 ( V_2 -> V_188 ) ;
}
void F_170 ( struct V_39 * V_10 ,
struct V_8 * V_2 )
{
F_163 ( V_2 ) ;
F_164 ( V_2 ) ;
}
void F_171 ( struct V_6 * V_7 )
{
if ( V_7 -> V_2 )
F_172 ( V_7 -> V_2 ) ;
F_164 ( V_7 -> V_2 ) ;
V_7 -> V_2 = F_98 ( sizeof( * V_7 -> V_2 ) , V_113 ) ;
if ( V_7 -> V_2 ) {
V_7 -> V_2 -> V_7 = V_7 ;
V_7 -> V_2 -> V_165 = V_191 ;
}
}
void F_173 ( struct V_6 * V_7 ,
struct V_3 * V_2 )
{
memcpy ( V_2 , V_7 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_91 )
F_174 ( V_2 -> V_91 ) ;
V_2 -> V_90 = NULL ;
}
struct V_3 *
F_175 ( struct V_6 * V_7 )
{
struct V_3 * V_2 ;
if ( F_3 ( ! V_7 -> V_2 ) )
return NULL ;
V_2 = F_168 ( sizeof( * V_2 ) , V_113 ) ;
if ( V_2 )
F_173 ( V_7 , V_2 ) ;
return V_2 ;
}
void F_172 ( struct V_3 * V_2 )
{
if ( V_2 -> V_91 )
F_176 ( V_2 -> V_91 ) ;
if ( V_2 -> V_90 )
F_60 ( V_2 -> V_90 ) ;
}
void F_177 ( struct V_6 * V_7 ,
struct V_3 * V_2 )
{
F_172 ( V_2 ) ;
F_164 ( V_2 ) ;
}
void
F_178 ( struct V_15 * V_16 ,
struct V_13 * V_38 )
{
if ( V_38 )
V_38 -> V_16 = V_16 ;
V_16 -> V_2 = V_38 ;
}
void F_179 ( struct V_15 * V_16 )
{
struct V_13 * V_38 =
F_98 ( sizeof( * V_38 ) , V_113 ) ;
if ( V_16 -> V_2 )
F_180 ( V_16 -> V_2 ) ;
F_164 ( V_16 -> V_2 ) ;
F_178 ( V_16 , V_38 ) ;
}
void
F_181 ( struct V_15 * V_16 ,
struct V_13 * V_2 )
{
memcpy ( V_2 , V_16 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_10 )
F_182 ( V_16 ) ;
}
struct V_13 *
F_183 ( struct V_15 * V_16 )
{
struct V_13 * V_2 ;
if ( F_3 ( ! V_16 -> V_2 ) )
return NULL ;
V_2 = F_168 ( sizeof( * V_2 ) , V_113 ) ;
if ( V_2 )
F_181 ( V_16 , V_2 ) ;
return V_2 ;
}
struct V_1 *
F_144 ( struct V_57 * V_34 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 ;
struct V_15 * V_166 ;
struct V_17 V_18 ;
struct V_6 * V_7 ;
struct V_39 * V_10 ;
int V_168 = 0 ;
V_2 = F_117 ( V_34 ) ;
if ( ! V_2 )
return F_143 ( - V_114 ) ;
V_2 -> V_156 = V_155 ;
F_133 (crtc, dev) {
struct V_8 * V_9 ;
V_9 = F_128 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) ) {
V_168 = F_14 ( V_9 ) ;
goto free;
}
}
F_184 (plane, dev) {
struct V_3 * V_5 ;
V_5 = F_118 ( V_2 , V_7 ) ;
if ( F_13 ( V_5 ) ) {
V_168 = F_14 ( V_5 ) ;
goto free;
}
}
F_9 ( V_34 , & V_18 ) ;
F_10 (conn, &conn_iter) {
struct V_13 * V_38 ;
V_38 = F_12 ( V_2 , V_166 ) ;
if ( F_13 ( V_38 ) ) {
V_168 = F_14 ( V_38 ) ;
F_17 ( & V_18 ) ;
goto free;
}
}
F_17 ( & V_18 ) ;
V_2 -> V_156 = NULL ;
free:
if ( V_168 < 0 ) {
F_77 ( V_2 ) ;
V_2 = F_143 ( V_168 ) ;
}
return V_2 ;
}
void
F_180 ( struct V_13 * V_2 )
{
if ( V_2 -> V_10 )
F_185 ( V_2 -> V_16 ) ;
}
void F_186 ( struct V_15 * V_16 ,
struct V_13 * V_2 )
{
F_180 ( V_2 ) ;
F_164 ( V_2 ) ;
}
int F_187 ( struct V_39 * V_10 ,
T_3 * V_192 , T_3 * V_193 , T_3 * V_194 ,
T_1 V_195 ,
struct V_154 * V_155 )
{
struct V_57 * V_34 = V_10 -> V_34 ;
struct V_180 * V_181 = & V_34 -> V_63 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_196 * V_197 = NULL ;
struct V_198 * V_199 ;
int V_22 , V_23 = 0 ;
V_2 = F_117 ( V_10 -> V_34 ) ;
if ( ! V_2 )
return - V_114 ;
V_197 = F_188 ( V_34 ,
sizeof( struct V_198 ) * V_195 ,
NULL ) ;
if ( F_13 ( V_197 ) ) {
V_23 = F_14 ( V_197 ) ;
V_197 = NULL ;
goto V_123;
}
V_199 = (struct V_198 * ) V_197 -> V_200 ;
for ( V_22 = 0 ; V_22 < V_195 ; V_22 ++ ) {
V_199 [ V_22 ] . V_192 = V_192 [ V_22 ] ;
V_199 [ V_22 ] . V_193 = V_193 [ V_22 ] ;
V_199 [ V_22 ] . V_194 = V_194 [ V_22 ] ;
}
V_2 -> V_156 = V_155 ;
V_9 = F_128 ( V_2 , V_10 ) ;
if ( F_13 ( V_9 ) ) {
V_23 = F_14 ( V_9 ) ;
goto V_123;
}
V_23 = F_149 ( V_10 , V_9 ,
V_181 -> V_201 , 0 ) ;
if ( V_23 )
goto V_123;
V_23 = F_149 ( V_10 , V_9 ,
V_181 -> V_202 , 0 ) ;
if ( V_23 )
goto V_123;
V_23 = F_149 ( V_10 , V_9 ,
V_181 -> V_203 , V_197 -> V_30 . V_31 ) ;
if ( V_23 )
goto V_123;
V_23 = F_121 ( V_2 ) ;
V_123:
F_77 ( V_2 ) ;
F_169 ( V_197 ) ;
return V_23 ;
}
