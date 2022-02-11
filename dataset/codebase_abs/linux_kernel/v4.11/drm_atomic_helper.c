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
struct V_16 V_17 ;
struct V_18 * V_19 ;
unsigned V_20 = 0 ;
int V_21 , V_22 = 0 ;
F_5 (state, connector, conn_state, i) {
const struct V_23 * V_24 = V_15 -> V_25 ;
struct V_18 * V_26 ;
if ( ! V_13 -> V_9 )
continue;
if ( V_24 -> V_27 )
V_26 = V_24 -> V_27 ( V_15 , V_13 ) ;
else if ( V_24 -> V_28 )
V_26 = V_24 -> V_28 ( V_15 ) ;
else
V_26 = F_6 ( V_15 ) ;
if ( V_26 ) {
if ( V_20 & ( 1 << F_7 ( V_26 ) ) ) {
F_8 ( L_1 ,
V_26 -> V_29 . V_30 , V_26 -> V_31 ,
V_15 -> V_29 . V_30 , V_15 -> V_31 ) ;
return - V_32 ;
}
V_20 |= 1 << F_7 ( V_26 ) ;
}
}
if ( ! V_20 )
return 0 ;
F_9 ( V_2 -> V_33 , & V_17 ) ;
F_10 (connector, &conn_iter) {
struct V_7 * V_8 ;
if ( F_11 ( V_2 , V_15 ) )
continue;
V_19 = V_15 -> V_2 -> V_28 ;
if ( ! V_19 || ! ( V_20 & ( 1 << F_7 ( V_19 ) ) ) )
continue;
if ( ! V_11 ) {
F_8 ( L_2 ,
V_19 -> V_29 . V_30 , V_19 -> V_31 ,
V_15 -> V_2 -> V_9 -> V_29 . V_30 ,
V_15 -> V_2 -> V_9 -> V_31 ,
V_15 -> V_29 . V_30 , V_15 -> V_31 ) ;
V_22 = - V_32 ;
goto V_34;
}
V_13 = F_12 ( V_2 , V_15 ) ;
if ( F_13 ( V_13 ) ) {
V_22 = F_14 ( V_13 ) ;
goto V_34;
}
F_8 ( L_3 ,
V_19 -> V_29 . V_30 , V_19 -> V_31 ,
V_13 -> V_9 -> V_29 . V_30 , V_13 -> V_9 -> V_31 ,
V_15 -> V_29 . V_30 , V_15 -> V_31 ) ;
V_8 = F_2 ( V_2 , V_13 -> V_9 ) ;
V_22 = F_15 ( V_13 , NULL ) ;
if ( V_22 )
goto V_34;
if ( ! V_8 -> V_35 ) {
V_22 = F_16 ( V_8 ,
NULL ) ;
if ( V_22 < 0 )
goto V_34;
V_8 -> V_36 = false ;
}
}
V_34:
F_17 ( & V_17 ) ;
return V_22 ;
}
static void
F_18 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_18 * V_19 )
{
struct V_7 * V_8 ;
struct V_37 * V_9 ;
if ( V_13 -> V_28 ) {
V_9 = V_13 -> V_15 -> V_2 -> V_9 ;
F_3 ( ! V_9 && V_19 != V_13 -> V_28 ) ;
if ( V_9 ) {
V_8 = F_2 ( V_2 , V_9 ) ;
V_8 -> V_20 &=
~ ( 1 << F_7 ( V_13 -> V_28 ) ) ;
}
}
if ( V_19 ) {
V_9 = V_13 -> V_9 ;
F_3 ( ! V_9 ) ;
if ( V_9 ) {
V_8 = F_2 ( V_2 , V_9 ) ;
V_8 -> V_20 |=
1 << F_7 ( V_19 ) ;
}
}
V_13 -> V_28 = V_19 ;
}
static void
F_19 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_12 * V_38 ;
int V_21 ;
F_5 (state, connector, connector_state, i) {
struct V_37 * V_39 ;
if ( V_38 -> V_28 != V_19 )
continue;
V_39 = V_15 -> V_2 -> V_9 ;
F_8 ( L_4 ,
V_19 -> V_29 . V_30 , V_19 -> V_31 ,
V_39 -> V_29 . V_30 , V_39 -> V_31 ) ;
F_18 ( V_2 , V_38 , NULL ) ;
V_8 = F_2 ( V_2 , V_39 ) ;
V_8 -> V_40 = true ;
return;
}
}
static int
F_20 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_12 * V_38 )
{
const struct V_23 * V_24 ;
struct V_18 * V_26 ;
struct V_7 * V_8 ;
F_8 ( L_5 ,
V_15 -> V_29 . V_30 ,
V_15 -> V_31 ) ;
if ( V_15 -> V_2 -> V_9 != V_38 -> V_9 ) {
if ( V_15 -> V_2 -> V_9 ) {
V_8 = F_2 ( V_2 , V_15 -> V_2 -> V_9 ) ;
V_8 -> V_40 = true ;
}
if ( V_38 -> V_9 ) {
V_8 = F_2 ( V_2 , V_38 -> V_9 ) ;
V_8 -> V_40 = true ;
}
}
if ( ! V_38 -> V_9 ) {
F_8 ( L_6 ,
V_15 -> V_29 . V_30 ,
V_15 -> V_31 ) ;
F_18 ( V_2 , V_38 , NULL ) ;
return 0 ;
}
V_24 = V_15 -> V_25 ;
if ( V_24 -> V_27 )
V_26 = V_24 -> V_27 ( V_15 ,
V_38 ) ;
else if ( V_24 -> V_28 )
V_26 = V_24 -> V_28 ( V_15 ) ;
else
V_26 = F_6 ( V_15 ) ;
if ( ! V_26 ) {
F_8 ( L_7 ,
V_15 -> V_29 . V_30 ,
V_15 -> V_31 ) ;
return - V_32 ;
}
if ( ! F_21 ( V_26 , V_38 -> V_9 ) ) {
F_8 ( L_8 ,
V_26 -> V_29 . V_30 ,
V_26 -> V_31 ,
V_38 -> V_9 -> V_29 . V_30 ) ;
return - V_32 ;
}
if ( V_26 == V_38 -> V_28 ) {
F_18 ( V_2 , V_38 , V_26 ) ;
F_8 ( L_9 ,
V_15 -> V_29 . V_30 ,
V_15 -> V_31 ,
V_26 -> V_29 . V_30 ,
V_26 -> V_31 ,
V_38 -> V_9 -> V_29 . V_30 ,
V_38 -> V_9 -> V_31 ) ;
return 0 ;
}
F_19 ( V_2 , V_26 ) ;
F_18 ( V_2 , V_38 , V_26 ) ;
V_8 = F_2 ( V_2 , V_38 -> V_9 ) ;
V_8 -> V_40 = true ;
F_8 ( L_10 ,
V_15 -> V_29 . V_30 ,
V_15 -> V_31 ,
V_26 -> V_29 . V_30 ,
V_26 -> V_31 ,
V_38 -> V_9 -> V_29 . V_30 ,
V_38 -> V_9 -> V_31 ) ;
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 )
{
struct V_37 * V_9 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_12 * V_13 ;
int V_21 ;
int V_22 ;
F_23 (state, crtc, crtc_state, i) {
if ( ! V_8 -> V_41 &&
! V_8 -> V_40 )
continue;
F_24 ( & V_8 -> V_42 , & V_8 -> V_43 ) ;
}
F_5 (state, connector, conn_state, i) {
const struct V_44 * V_24 ;
struct V_18 * V_19 ;
F_3 ( ! ! V_13 -> V_28 != ! ! V_13 -> V_9 ) ;
if ( ! V_13 -> V_9 || ! V_13 -> V_28 )
continue;
V_8 = F_2 ( V_2 ,
V_13 -> V_9 ) ;
V_19 = V_13 -> V_28 ;
V_24 = V_19 -> V_25 ;
V_22 = F_25 ( V_19 -> V_45 , & V_8 -> V_43 ,
& V_8 -> V_42 ) ;
if ( ! V_22 ) {
F_8 ( L_11 ) ;
return - V_32 ;
}
if ( V_24 && V_24 -> V_46 ) {
V_22 = V_24 -> V_46 ( V_19 , V_8 ,
V_13 ) ;
if ( V_22 ) {
F_8 ( L_12 ,
V_19 -> V_29 . V_30 , V_19 -> V_31 ) ;
return V_22 ;
}
} else if ( V_24 && V_24 -> F_22 ) {
V_22 = V_24 -> F_22 ( V_19 , & V_8 -> V_43 ,
& V_8 -> V_42 ) ;
if ( ! V_22 ) {
F_8 ( L_13 ,
V_19 -> V_29 . V_30 , V_19 -> V_31 ) ;
return - V_32 ;
}
}
}
F_23 (state, crtc, crtc_state, i) {
const struct V_47 * V_24 ;
if ( ! V_8 -> V_48 )
continue;
if ( ! V_8 -> V_41 &&
! V_8 -> V_40 )
continue;
V_24 = V_9 -> V_25 ;
if ( ! V_24 -> F_22 )
continue;
V_22 = V_24 -> F_22 ( V_9 , & V_8 -> V_43 ,
& V_8 -> V_42 ) ;
if ( ! V_22 ) {
F_8 ( L_14 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
return - V_32 ;
}
}
return 0 ;
}
int
F_26 ( struct V_49 * V_33 ,
struct V_1 * V_2 )
{
struct V_37 * V_9 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_12 * V_38 ;
int V_21 , V_22 ;
F_23 (state, crtc, crtc_state, i) {
if ( ! F_27 ( & V_9 -> V_2 -> V_43 , & V_8 -> V_43 ) ) {
F_8 ( L_15 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
V_8 -> V_41 = true ;
}
if ( V_9 -> V_2 -> V_48 != V_8 -> V_48 ) {
F_8 ( L_16 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
V_8 -> V_41 = true ;
V_8 -> V_40 = true ;
}
}
V_22 = F_4 ( V_2 , V_2 -> V_50 ) ;
if ( V_22 )
return V_22 ;
F_5 (state, connector, connector_state, i) {
V_22 = F_20 ( V_2 , V_15 ,
V_38 ) ;
if ( V_22 )
return V_22 ;
}
F_23 (state, crtc, crtc_state, i) {
bool V_51 =
! ! V_8 -> V_35 ;
if ( V_9 -> V_2 -> V_36 != V_8 -> V_36 ) {
F_8 ( L_17 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
V_8 -> V_52 = true ;
}
if ( ! F_28 ( V_8 ) )
continue;
F_8 ( L_18 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ,
V_8 -> V_48 ? 'y' : 'n' ,
V_8 -> V_36 ? 'y' : 'n' ) ;
V_22 = F_29 ( V_2 , V_9 ) ;
if ( V_22 != 0 )
return V_22 ;
V_22 = F_30 ( V_2 , V_9 ) ;
if ( V_22 != 0 )
return V_22 ;
if ( V_8 -> V_48 != V_51 ) {
F_8 ( L_19 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
return - V_32 ;
}
}
return F_22 ( V_2 ) ;
}
int
F_31 ( struct V_49 * V_33 ,
struct V_1 * V_2 )
{
struct V_37 * V_9 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_21 , V_22 = 0 ;
F_32 (state, plane, plane_state, i) {
const struct V_53 * V_24 ;
V_24 = V_6 -> V_25 ;
F_1 ( V_2 , V_4 , V_6 ) ;
if ( ! V_24 || ! V_24 -> V_46 )
continue;
V_22 = V_24 -> V_46 ( V_6 , V_4 ) ;
if ( V_22 ) {
F_8 ( L_20 ,
V_6 -> V_29 . V_30 , V_6 -> V_31 ) ;
return V_22 ;
}
}
F_23 (state, crtc, crtc_state, i) {
const struct V_47 * V_24 ;
V_24 = V_9 -> V_25 ;
if ( ! V_24 || ! V_24 -> V_46 )
continue;
V_22 = V_24 -> V_46 ( V_9 , V_8 ) ;
if ( V_22 ) {
F_8 ( L_21 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
return V_22 ;
}
}
return V_22 ;
}
int F_33 ( struct V_49 * V_33 ,
struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_26 ( V_33 , V_2 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_31 ( V_33 , V_2 ) ;
if ( V_22 )
return V_22 ;
return V_22 ;
}
static void
F_34 ( struct V_49 * V_33 , struct V_1 * V_54 )
{
struct V_14 * V_15 ;
struct V_12 * V_55 ;
struct V_37 * V_9 ;
struct V_7 * V_56 ;
int V_21 ;
F_5 (old_state, connector, old_conn_state, i) {
const struct V_44 * V_24 ;
struct V_18 * V_19 ;
if ( ! V_55 -> V_9 )
continue;
V_56 = F_2 ( V_54 ,
V_55 -> V_9 ) ;
if ( ! V_56 -> V_36 ||
! F_28 ( V_55 -> V_9 -> V_2 ) )
continue;
V_19 = V_55 -> V_28 ;
if ( F_3 ( ! V_19 ) )
continue;
V_24 = V_19 -> V_25 ;
F_8 ( L_22 ,
V_19 -> V_29 . V_30 , V_19 -> V_31 ) ;
F_35 ( V_19 -> V_45 ) ;
if ( V_24 ) {
if ( V_15 -> V_2 -> V_9 && V_24 -> V_57 )
V_24 -> V_57 ( V_19 ) ;
else if ( V_24 -> V_58 )
V_24 -> V_58 ( V_19 ) ;
else if ( V_24 -> V_59 )
V_24 -> V_59 ( V_19 , V_60 ) ;
}
F_36 ( V_19 -> V_45 ) ;
}
F_23 (old_state, crtc, old_crtc_state, i) {
const struct V_47 * V_24 ;
if ( ! F_28 ( V_9 -> V_2 ) )
continue;
if ( ! V_56 -> V_36 )
continue;
V_24 = V_9 -> V_25 ;
F_8 ( L_23 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
if ( V_9 -> V_2 -> V_48 && V_24 -> V_57 )
V_24 -> V_57 ( V_9 ) ;
else if ( V_24 -> V_61 )
V_24 -> V_61 ( V_9 , V_56 ) ;
else if ( V_24 -> V_58 )
V_24 -> V_58 ( V_9 ) ;
else
V_24 -> V_59 ( V_9 , V_60 ) ;
}
}
void
F_37 ( struct V_49 * V_33 ,
struct V_1 * V_54 )
{
struct V_14 * V_15 ;
struct V_12 * V_55 ;
struct V_37 * V_9 ;
struct V_7 * V_56 ;
int V_21 ;
F_5 (old_state, connector, old_conn_state, i) {
if ( V_15 -> V_19 ) {
F_3 ( ! V_15 -> V_19 -> V_9 ) ;
V_15 -> V_19 -> V_9 = NULL ;
V_15 -> V_19 = NULL ;
}
V_9 = V_15 -> V_2 -> V_9 ;
if ( ( ! V_9 && V_55 -> V_9 ) ||
( V_9 && F_28 ( V_9 -> V_2 ) ) ) {
struct V_62 * V_63 =
V_33 -> V_64 . V_65 ;
int V_43 = V_60 ;
if ( V_9 && V_9 -> V_2 -> V_36 )
V_43 = V_66 ;
V_15 -> V_59 = V_43 ;
F_38 ( & V_15 -> V_29 ,
V_63 , V_43 ) ;
}
}
F_5 (old_state, connector, old_conn_state, i) {
if ( ! V_15 -> V_2 -> V_9 )
continue;
if ( F_3 ( ! V_15 -> V_2 -> V_28 ) )
continue;
V_15 -> V_19 = V_15 -> V_2 -> V_28 ;
V_15 -> V_19 -> V_9 = V_15 -> V_2 -> V_9 ;
}
F_23 (old_state, crtc, old_crtc_state, i) {
struct V_5 * V_67 = V_9 -> V_67 ;
V_9 -> V_43 = V_9 -> V_2 -> V_43 ;
V_9 -> V_68 = V_9 -> V_2 -> V_48 ;
if ( F_39 ( V_54 , V_67 ) &&
V_67 -> V_2 -> V_9 == V_9 ) {
V_9 -> V_69 = V_67 -> V_2 -> V_70 >> 16 ;
V_9 -> V_71 = V_67 -> V_2 -> V_72 >> 16 ;
}
if ( V_9 -> V_2 -> V_48 )
F_40 ( V_9 ,
& V_9 -> V_2 -> V_42 ) ;
}
}
static void
F_41 ( struct V_49 * V_33 , struct V_1 * V_54 )
{
struct V_37 * V_9 ;
struct V_7 * V_56 ;
struct V_14 * V_15 ;
struct V_12 * V_55 ;
int V_21 ;
F_23 (old_state, crtc, old_crtc_state, i) {
const struct V_47 * V_24 ;
if ( ! V_9 -> V_2 -> V_41 )
continue;
V_24 = V_9 -> V_25 ;
if ( V_9 -> V_2 -> V_48 && V_24 -> V_73 ) {
F_8 ( L_24 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
V_24 -> V_73 ( V_9 ) ;
}
}
F_5 (old_state, connector, old_conn_state, i) {
const struct V_44 * V_24 ;
struct V_7 * V_74 ;
struct V_18 * V_19 ;
struct V_75 * V_43 , * V_42 ;
if ( ! V_15 -> V_2 -> V_28 )
continue;
V_19 = V_15 -> V_2 -> V_28 ;
V_24 = V_19 -> V_25 ;
V_74 = V_15 -> V_2 -> V_9 -> V_2 ;
V_43 = & V_74 -> V_43 ;
V_42 = & V_74 -> V_42 ;
if ( ! V_74 -> V_41 )
continue;
F_8 ( L_25 ,
V_19 -> V_29 . V_30 , V_19 -> V_31 ) ;
if ( V_24 && V_24 -> V_76 ) {
V_24 -> V_76 ( V_19 , V_74 ,
V_15 -> V_2 ) ;
} else if ( V_24 && V_24 -> V_77 ) {
V_24 -> V_77 ( V_19 , V_43 , V_42 ) ;
}
F_42 ( V_19 -> V_45 , V_43 , V_42 ) ;
}
}
void F_43 ( struct V_49 * V_33 ,
struct V_1 * V_54 )
{
F_34 ( V_33 , V_54 ) ;
F_37 ( V_33 , V_54 ) ;
F_41 ( V_33 , V_54 ) ;
}
void F_44 ( struct V_49 * V_33 ,
struct V_1 * V_54 )
{
struct V_37 * V_9 ;
struct V_7 * V_56 ;
struct V_14 * V_15 ;
struct V_12 * V_55 ;
int V_21 ;
F_23 (old_state, crtc, old_crtc_state, i) {
const struct V_47 * V_24 ;
if ( ! F_28 ( V_9 -> V_2 ) )
continue;
if ( ! V_9 -> V_2 -> V_36 )
continue;
V_24 = V_9 -> V_25 ;
if ( V_9 -> V_2 -> V_48 ) {
F_8 ( L_26 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
if ( V_24 -> V_48 )
V_24 -> V_48 ( V_9 ) ;
else
V_24 -> V_78 ( V_9 ) ;
}
}
F_5 (old_state, connector, old_conn_state, i) {
const struct V_44 * V_24 ;
struct V_18 * V_19 ;
if ( ! V_15 -> V_2 -> V_28 )
continue;
if ( ! V_15 -> V_2 -> V_9 -> V_2 -> V_36 ||
! F_28 ( V_15 -> V_2 -> V_9 -> V_2 ) )
continue;
V_19 = V_15 -> V_2 -> V_28 ;
V_24 = V_19 -> V_25 ;
F_8 ( L_27 ,
V_19 -> V_29 . V_30 , V_19 -> V_31 ) ;
F_45 ( V_19 -> V_45 ) ;
if ( V_24 ) {
if ( V_24 -> V_48 )
V_24 -> V_48 ( V_19 ) ;
else if ( V_24 -> V_78 )
V_24 -> V_78 ( V_19 ) ;
}
F_46 ( V_19 -> V_45 ) ;
}
}
int F_47 ( struct V_49 * V_33 ,
struct V_1 * V_2 ,
bool V_79 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_21 , V_22 ;
F_32 (state, plane, plane_state, i) {
if ( ! V_79 )
V_4 = V_6 -> V_2 ;
if ( ! V_4 -> V_80 )
continue;
F_3 ( ! V_4 -> V_81 ) ;
V_22 = F_48 ( V_4 -> V_80 , V_79 ) ;
if ( V_22 )
return V_22 ;
F_49 ( V_4 -> V_80 ) ;
V_4 -> V_80 = NULL ;
}
return 0 ;
}
void
F_50 ( struct V_49 * V_33 ,
struct V_1 * V_54 )
{
struct V_37 * V_9 ;
struct V_7 * V_56 ;
int V_21 , V_22 ;
unsigned V_82 = 0 ;
if ( V_54 -> V_83 )
return;
F_23 (old_state, crtc, old_crtc_state, i) {
struct V_7 * V_74 = V_9 -> V_2 ;
if ( ! V_74 -> V_36 || ! V_74 -> V_10 )
continue;
V_22 = F_51 ( V_9 ) ;
if ( V_22 != 0 )
continue;
V_82 |= F_52 ( V_9 ) ;
V_54 -> V_84 [ V_21 ] . V_85 = F_53 ( V_9 ) ;
}
F_23 (old_state, crtc, old_crtc_state, i) {
if ( ! ( V_82 & F_52 ( V_9 ) ) )
continue;
V_22 = F_54 ( V_33 -> V_86 [ V_21 ] . V_87 ,
V_54 -> V_84 [ V_21 ] . V_85 !=
F_53 ( V_9 ) ,
F_55 ( 50 ) ) ;
F_56 ( ! V_22 , L_28 , V_9 -> V_29 . V_30 ) ;
F_57 ( V_9 ) ;
}
}
void F_58 ( struct V_1 * V_54 )
{
struct V_49 * V_33 = V_54 -> V_33 ;
F_43 ( V_33 , V_54 ) ;
F_59 ( V_33 , V_54 , 0 ) ;
F_44 ( V_33 , V_54 ) ;
F_60 ( V_54 ) ;
F_50 ( V_33 , V_54 ) ;
F_61 ( V_33 , V_54 ) ;
}
static void F_62 ( struct V_1 * V_54 )
{
struct V_49 * V_33 = V_54 -> V_33 ;
struct V_88 * V_24 ;
V_24 = V_33 -> V_64 . V_25 ;
F_47 ( V_33 , V_54 , false ) ;
F_63 ( V_54 ) ;
if ( V_24 && V_24 -> V_89 )
V_24 -> V_89 ( V_54 ) ;
else
F_58 ( V_54 ) ;
F_64 ( V_54 ) ;
F_65 ( V_54 ) ;
}
static void F_66 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_67 ( V_91 ,
struct V_1 ,
F_66 ) ;
F_62 ( V_2 ) ;
}
int F_68 ( struct V_49 * V_33 ,
struct V_1 * V_2 ,
bool V_92 )
{
int V_22 ;
V_22 = F_69 ( V_2 , V_92 ) ;
if ( V_22 )
return V_22 ;
F_70 ( & V_2 -> F_66 , F_66 ) ;
V_22 = F_71 ( V_33 , V_2 ) ;
if ( V_22 )
return V_22 ;
if ( ! V_92 ) {
V_22 = F_47 ( V_33 , V_2 , true ) ;
if ( V_22 ) {
F_61 ( V_33 , V_2 ) ;
return V_22 ;
}
}
F_72 ( V_2 , true ) ;
F_73 ( V_2 ) ;
if ( V_92 )
F_74 ( V_93 , & V_2 -> F_66 ) ;
else
F_62 ( V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_37 * V_9 , bool V_92 )
{
struct V_94 * V_78 , * V_95 = NULL ;
bool V_96 = true ;
int V_21 ;
long V_22 = 0 ;
F_76 ( & V_9 -> V_97 ) ;
V_21 = 0 ;
F_77 (commit, &crtc->commit_list, commit_entry) {
if ( V_21 == 0 ) {
V_96 = F_78 ( & V_78 -> V_98 ) ;
if ( ! V_96 && V_92 ) {
F_79 ( & V_9 -> V_97 ) ;
return - V_99 ;
}
} else if ( V_21 == 1 ) {
V_95 = V_78 ;
F_80 ( V_95 ) ;
break;
}
V_21 ++ ;
}
F_79 ( & V_9 -> V_97 ) ;
if ( ! V_95 )
return 0 ;
V_22 = F_81 ( & V_95 -> V_100 ,
10 * V_101 ) ;
if ( V_22 == 0 )
F_82 ( L_29 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
F_83 ( V_95 ) ;
return V_22 < 0 ? V_22 : 0 ;
}
static void F_84 ( struct V_102 * V_102 )
{
struct V_94 * V_78 = F_67 ( V_102 ,
F_85 ( * V_78 ) ,
V_98 ) ;
F_83 ( V_78 ) ;
}
int F_69 ( struct V_1 * V_2 ,
bool V_92 )
{
struct V_37 * V_9 ;
struct V_7 * V_8 ;
struct V_94 * V_78 ;
int V_21 , V_22 ;
F_23 (state, crtc, crtc_state, i) {
V_78 = F_86 ( sizeof( * V_78 ) , V_103 ) ;
if ( ! V_78 )
return - V_104 ;
F_87 ( & V_78 -> V_98 ) ;
F_87 ( & V_78 -> V_105 ) ;
F_87 ( & V_78 -> V_100 ) ;
F_88 ( & V_78 -> V_106 ) ;
F_89 ( & V_78 -> V_107 ) ;
V_78 -> V_9 = V_9 ;
V_2 -> V_84 [ V_21 ] . V_78 = V_78 ;
V_22 = F_75 ( V_9 , V_92 ) ;
if ( V_22 )
return V_22 ;
if ( ! V_9 -> V_2 -> V_36 && ! V_8 -> V_36 ) {
F_90 ( & V_78 -> V_98 ) ;
continue;
}
if ( V_2 -> V_83 ) {
F_90 ( & V_78 -> V_98 ) ;
continue;
}
if ( ! V_8 -> V_108 ) {
V_78 -> V_108 = F_86 ( sizeof( * V_78 -> V_108 ) ,
V_103 ) ;
if ( ! V_78 -> V_108 )
return - V_104 ;
V_8 -> V_108 = V_78 -> V_108 ;
}
V_8 -> V_108 -> V_29 . V_102 = & V_78 -> V_98 ;
V_8 -> V_108 -> V_29 . V_109 = F_84 ;
F_80 ( V_78 ) ;
}
return 0 ;
}
static struct V_94 * F_91 ( struct V_37 * V_9 )
{
struct V_94 * V_78 ;
int V_21 = 0 ;
F_77 (commit, &crtc->commit_list, commit_entry) {
if ( V_21 == 1 )
return V_78 ;
V_21 ++ ;
}
return NULL ;
}
void F_63 ( struct V_1 * V_54 )
{
struct V_37 * V_9 ;
struct V_7 * V_8 ;
struct V_94 * V_78 ;
int V_21 ;
long V_22 ;
F_23 (old_state, crtc, crtc_state, i) {
F_76 ( & V_9 -> V_97 ) ;
V_78 = F_91 ( V_9 ) ;
if ( V_78 )
F_80 ( V_78 ) ;
F_79 ( & V_9 -> V_97 ) ;
if ( ! V_78 )
continue;
V_22 = F_92 ( & V_78 -> V_105 ,
10 * V_101 ) ;
if ( V_22 == 0 )
F_82 ( L_30 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
V_22 = F_92 ( & V_78 -> V_98 ,
10 * V_101 ) ;
if ( V_22 == 0 )
F_82 ( L_31 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
F_83 ( V_78 ) ;
}
}
void F_60 ( struct V_1 * V_54 )
{
struct V_37 * V_9 ;
struct V_7 * V_8 ;
struct V_94 * V_78 ;
int V_21 ;
F_23 (old_state, crtc, crtc_state, i) {
V_78 = V_54 -> V_84 [ V_21 ] . V_78 ;
if ( ! V_78 )
continue;
F_3 ( V_9 -> V_2 -> V_108 ) ;
F_76 ( & V_9 -> V_97 ) ;
F_90 ( & V_78 -> V_105 ) ;
F_79 ( & V_9 -> V_97 ) ;
}
}
void F_64 ( struct V_1 * V_54 )
{
struct V_37 * V_9 ;
struct V_7 * V_8 ;
struct V_94 * V_78 ;
int V_21 ;
long V_22 ;
F_23 (old_state, crtc, crtc_state, i) {
V_78 = V_54 -> V_84 [ V_21 ] . V_78 ;
if ( F_3 ( ! V_78 ) )
continue;
F_76 ( & V_9 -> V_97 ) ;
F_90 ( & V_78 -> V_100 ) ;
F_3 ( ! F_78 ( & V_78 -> V_105 ) ) ;
if ( F_78 ( & V_78 -> V_98 ) )
goto V_110;
F_79 ( & V_9 -> V_97 ) ;
V_22 = F_92 ( & V_78 -> V_98 ,
10 * V_101 ) ;
if ( V_22 == 0 )
F_82 ( L_31 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
F_76 ( & V_9 -> V_97 ) ;
V_110:
F_93 ( & V_78 -> V_106 ) ;
F_79 ( & V_9 -> V_97 ) ;
}
}
int F_71 ( struct V_49 * V_33 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_22 , V_21 , V_111 ;
F_32 (state, plane, plane_state, i) {
const struct V_53 * V_24 ;
V_24 = V_6 -> V_25 ;
if ( V_24 -> V_112 ) {
V_22 = V_24 -> V_112 ( V_6 , V_4 ) ;
if ( V_22 )
goto V_113;
}
}
return 0 ;
V_113:
F_32 (state, plane, plane_state, j) {
const struct V_53 * V_24 ;
if ( V_111 >= V_21 )
continue;
V_24 = V_6 -> V_25 ;
if ( V_24 -> V_114 )
V_24 -> V_114 ( V_6 , V_4 ) ;
}
return V_22 ;
}
static bool F_94 ( const struct V_3 * V_2 )
{
return V_2 -> V_9 && V_2 -> V_9 -> V_2 -> V_36 ;
}
void F_59 ( struct V_49 * V_33 ,
struct V_1 * V_54 ,
T_1 V_115 )
{
struct V_37 * V_9 ;
struct V_7 * V_56 ;
struct V_5 * V_6 ;
struct V_3 * V_116 ;
int V_21 ;
bool V_117 = V_115 & V_118 ;
bool V_119 = V_115 & V_120 ;
F_23 (old_state, crtc, old_crtc_state, i) {
const struct V_47 * V_24 ;
V_24 = V_9 -> V_25 ;
if ( ! V_24 || ! V_24 -> V_121 )
continue;
if ( V_117 && ! V_9 -> V_2 -> V_36 )
continue;
V_24 -> V_121 ( V_9 , V_56 ) ;
}
F_32 (old_state, plane, old_plane_state, i) {
const struct V_53 * V_24 ;
bool V_122 ;
V_24 = V_6 -> V_25 ;
if ( ! V_24 )
continue;
V_122 = F_95 ( V_6 , V_116 ) ;
if ( V_117 ) {
if ( ! V_122 && ! F_94 ( V_6 -> V_2 ) )
continue;
if ( V_122 && ! F_94 ( V_116 ) )
continue;
}
if ( V_122 && V_24 -> V_61 ) {
struct V_7 * V_8 ;
V_8 = V_116 -> V_9 -> V_2 ;
if ( F_28 ( V_8 ) &&
V_119 )
continue;
V_24 -> V_61 ( V_6 , V_116 ) ;
} else if ( V_6 -> V_2 -> V_9 || V_122 ) {
V_24 -> V_123 ( V_6 , V_116 ) ;
}
}
F_23 (old_state, crtc, old_crtc_state, i) {
const struct V_47 * V_24 ;
V_24 = V_9 -> V_25 ;
if ( ! V_24 || ! V_24 -> V_124 )
continue;
if ( V_117 && ! V_9 -> V_2 -> V_36 )
continue;
V_24 -> V_124 ( V_9 , V_56 ) ;
}
}
void
F_96 ( struct V_7 * V_56 )
{
const struct V_47 * V_125 ;
struct V_37 * V_9 = V_56 -> V_9 ;
struct V_1 * V_54 = V_56 -> V_2 ;
struct V_5 * V_6 ;
unsigned V_126 ;
V_126 = V_56 -> V_126 ;
V_126 |= V_9 -> V_2 -> V_126 ;
V_125 = V_9 -> V_25 ;
if ( V_125 && V_125 -> V_121 )
V_125 -> V_121 ( V_9 , V_56 ) ;
F_97 (plane, crtc->dev, plane_mask) {
struct V_3 * V_116 =
F_39 ( V_54 , V_6 ) ;
const struct V_53 * V_127 ;
V_127 = V_6 -> V_25 ;
if ( ! V_116 || ! V_127 )
continue;
F_3 ( V_6 -> V_2 -> V_9 && V_6 -> V_2 -> V_9 != V_9 ) ;
if ( F_95 ( V_6 , V_116 ) &&
V_127 -> V_61 )
V_127 -> V_61 ( V_6 , V_116 ) ;
else if ( V_6 -> V_2 -> V_9 ||
F_95 ( V_6 , V_116 ) )
V_127 -> V_123 ( V_6 , V_116 ) ;
}
if ( V_125 && V_125 -> V_124 )
V_125 -> V_124 ( V_9 , V_56 ) ;
}
void
F_98 ( struct V_7 * V_56 ,
bool V_128 )
{
struct V_37 * V_9 = V_56 -> V_9 ;
const struct V_47 * V_125 =
V_9 -> V_25 ;
struct V_5 * V_6 ;
if ( V_128 && V_125 && V_125 -> V_121 )
V_125 -> V_121 ( V_9 , NULL ) ;
F_99 (plane, old_crtc_state) {
const struct V_53 * V_127 =
V_6 -> V_25 ;
if ( ! V_127 )
continue;
F_3 ( ! V_127 -> V_61 ) ;
if ( V_127 -> V_61 )
V_127 -> V_61 ( V_6 , NULL ) ;
}
if ( V_128 && V_125 && V_125 -> V_124 )
V_125 -> V_124 ( V_9 , NULL ) ;
}
void F_61 ( struct V_49 * V_33 ,
struct V_1 * V_54 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_21 ;
F_32 (old_state, plane, plane_state, i) {
const struct V_53 * V_24 ;
V_24 = V_6 -> V_25 ;
if ( V_24 -> V_114 )
V_24 -> V_114 ( V_6 , V_4 ) ;
}
}
void F_72 ( struct V_1 * V_2 ,
bool V_129 )
{
int V_21 ;
long V_22 ;
struct V_14 * V_15 ;
struct V_12 * V_13 ;
struct V_37 * V_9 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_94 * V_78 ;
if ( V_129 ) {
F_23 (state, crtc, crtc_state, i) {
F_76 ( & V_9 -> V_97 ) ;
V_78 = F_100 ( & V_9 -> V_130 ,
struct V_94 , V_106 ) ;
if ( V_78 )
F_80 ( V_78 ) ;
F_79 ( & V_9 -> V_97 ) ;
if ( ! V_78 )
continue;
V_22 = F_92 ( & V_78 -> V_105 ,
10 * V_101 ) ;
if ( V_22 == 0 )
F_82 ( L_30 ,
V_9 -> V_29 . V_30 , V_9 -> V_31 ) ;
F_83 ( V_78 ) ;
}
}
F_5 (state, connector, conn_state, i) {
V_15 -> V_2 -> V_2 = V_2 ;
F_101 ( V_2 -> V_131 [ V_21 ] . V_2 , V_15 -> V_2 ) ;
V_15 -> V_2 -> V_2 = NULL ;
}
F_23 (state, crtc, crtc_state, i) {
V_9 -> V_2 -> V_2 = V_2 ;
F_101 ( V_2 -> V_84 [ V_21 ] . V_2 , V_9 -> V_2 ) ;
V_9 -> V_2 -> V_2 = NULL ;
if ( V_2 -> V_84 [ V_21 ] . V_78 ) {
F_76 ( & V_9 -> V_97 ) ;
F_102 ( & V_2 -> V_84 [ V_21 ] . V_78 -> V_106 ,
& V_9 -> V_130 ) ;
F_79 ( & V_9 -> V_97 ) ;
V_2 -> V_84 [ V_21 ] . V_78 -> V_108 = NULL ;
}
}
F_32 (state, plane, plane_state, i) {
V_6 -> V_2 -> V_2 = V_2 ;
F_101 ( V_2 -> V_132 [ V_21 ] . V_2 , V_6 -> V_2 ) ;
V_6 -> V_2 -> V_2 = NULL ;
}
}
int F_103 ( struct V_5 * V_6 ,
struct V_37 * V_9 ,
struct V_133 * V_81 ,
int V_134 , int V_135 ,
unsigned int V_136 , unsigned int V_137 ,
T_1 V_70 , T_1 V_72 ,
T_1 V_138 , T_1 V_139 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_22 = 0 ;
V_2 = F_104 ( V_6 -> V_33 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_140 = F_105 ( V_9 ) ;
V_141:
V_4 = F_106 ( V_2 , V_6 ) ;
if ( F_13 ( V_4 ) ) {
V_22 = F_14 ( V_4 ) ;
goto V_113;
}
V_22 = F_107 ( V_4 , V_9 ) ;
if ( V_22 != 0 )
goto V_113;
F_108 ( V_4 , V_81 ) ;
V_4 -> V_134 = V_134 ;
V_4 -> V_135 = V_135 ;
V_4 -> V_136 = V_136 ;
V_4 -> V_137 = V_137 ;
V_4 -> V_70 = V_70 ;
V_4 -> V_72 = V_72 ;
V_4 -> V_138 = V_138 ;
V_4 -> V_139 = V_139 ;
if ( V_6 == V_9 -> V_142 )
V_2 -> V_83 = true ;
V_22 = F_109 ( V_2 ) ;
V_113:
if ( V_22 == - V_143 )
goto V_144;
F_65 ( V_2 ) ;
return V_22 ;
V_144:
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
V_6 -> V_145 = V_6 -> V_81 ;
goto V_141;
}
int F_112 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_22 = 0 ;
if ( ! V_6 -> V_9 )
return 0 ;
V_2 = F_104 ( V_6 -> V_33 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_140 = F_105 ( V_6 -> V_9 ) ;
V_141:
V_4 = F_106 ( V_2 , V_6 ) ;
if ( F_13 ( V_4 ) ) {
V_22 = F_14 ( V_4 ) ;
goto V_113;
}
if ( V_4 -> V_9 && ( V_6 == V_6 -> V_9 -> V_142 ) )
V_4 -> V_2 -> V_83 = true ;
V_22 = F_113 ( V_6 , V_4 ) ;
if ( V_22 != 0 )
goto V_113;
V_22 = F_109 ( V_2 ) ;
V_113:
if ( V_22 == - V_143 )
goto V_144;
F_65 ( V_2 ) ;
return V_22 ;
V_144:
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
V_6 -> V_145 = V_6 -> V_81 ;
goto V_141;
}
int F_113 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
int V_22 ;
V_22 = F_107 ( V_4 , NULL ) ;
if ( V_22 != 0 )
return V_22 ;
F_108 ( V_4 , NULL ) ;
V_4 -> V_134 = 0 ;
V_4 -> V_135 = 0 ;
V_4 -> V_136 = 0 ;
V_4 -> V_137 = 0 ;
V_4 -> V_70 = 0 ;
V_4 -> V_72 = 0 ;
V_4 -> V_138 = 0 ;
V_4 -> V_139 = 0 ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
struct V_49 * V_33 = V_147 -> V_9 -> V_33 ;
struct V_37 * V_9 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_12 * V_13 ;
int V_22 , V_21 ;
V_22 = F_115 ( & V_33 -> V_64 . V_148 ,
V_2 -> V_140 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_29 ( V_2 , V_147 -> V_9 ) ;
if ( V_22 )
return V_22 ;
F_5 (state, connector, conn_state, i) {
if ( V_13 -> V_9 == V_147 -> V_9 ) {
V_22 = F_15 ( V_13 ,
NULL ) ;
if ( V_22 )
return V_22 ;
}
}
for ( V_21 = 0 ; V_21 < V_147 -> V_149 ; V_21 ++ ) {
V_13 = F_12 ( V_2 ,
V_147 -> V_131 [ V_21 ] ) ;
if ( F_13 ( V_13 ) )
return F_14 ( V_13 ) ;
V_22 = F_15 ( V_13 ,
V_147 -> V_9 ) ;
if ( V_22 )
return V_22 ;
}
F_23 (state, crtc, crtc_state, i) {
if ( V_9 == V_147 -> V_9 )
continue;
if ( ! V_8 -> V_35 ) {
V_22 = F_16 ( V_8 ,
NULL ) ;
if ( V_22 < 0 )
return V_22 ;
V_8 -> V_36 = false ;
}
}
return 0 ;
}
int F_116 ( struct V_146 * V_147 )
{
struct V_1 * V_2 ;
struct V_37 * V_9 = V_147 -> V_9 ;
int V_22 = 0 ;
V_2 = F_104 ( V_9 -> V_33 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_50 = true ;
V_2 -> V_140 = F_105 ( V_9 ) ;
V_141:
V_22 = F_117 ( V_147 , V_2 ) ;
if ( V_22 != 0 )
goto V_113;
V_22 = F_109 ( V_2 ) ;
V_113:
if ( V_22 == - V_143 )
goto V_144;
F_65 ( V_2 ) ;
return V_22 ;
V_144:
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
V_9 -> V_67 -> V_145 = V_9 -> V_67 -> V_81 ;
goto V_141;
}
int F_117 ( struct V_146 * V_147 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_3 * V_150 ;
struct V_37 * V_9 = V_147 -> V_9 ;
int V_151 , V_152 ;
int V_22 ;
V_8 = F_118 ( V_2 , V_9 ) ;
if ( F_13 ( V_8 ) )
return F_14 ( V_8 ) ;
V_150 = F_106 ( V_2 , V_9 -> V_67 ) ;
if ( F_13 ( V_150 ) )
return F_14 ( V_150 ) ;
if ( ! V_147 -> V_43 ) {
F_3 ( V_147 -> V_81 ) ;
F_3 ( V_147 -> V_149 ) ;
V_22 = F_119 ( V_8 , NULL ) ;
if ( V_22 != 0 )
return V_22 ;
V_8 -> V_36 = false ;
V_22 = F_107 ( V_150 , NULL ) ;
if ( V_22 != 0 )
return V_22 ;
F_108 ( V_150 , NULL ) ;
goto V_78;
}
F_3 ( ! V_147 -> V_81 ) ;
F_3 ( ! V_147 -> V_149 ) ;
V_22 = F_119 ( V_8 , V_147 -> V_43 ) ;
if ( V_22 != 0 )
return V_22 ;
V_8 -> V_36 = true ;
V_22 = F_107 ( V_150 , V_9 ) ;
if ( V_22 != 0 )
return V_22 ;
F_120 ( V_147 -> V_43 , & V_151 , & V_152 ) ;
F_108 ( V_150 , V_147 -> V_81 ) ;
V_150 -> V_134 = 0 ;
V_150 -> V_135 = 0 ;
V_150 -> V_136 = V_151 ;
V_150 -> V_137 = V_152 ;
V_150 -> V_70 = V_147 -> V_69 << 16 ;
V_150 -> V_72 = V_147 -> V_71 << 16 ;
if ( F_121 ( V_150 -> V_153 ) ) {
V_150 -> V_138 = V_152 << 16 ;
V_150 -> V_139 = V_151 << 16 ;
} else {
V_150 -> V_138 = V_151 << 16 ;
V_150 -> V_139 = V_152 << 16 ;
}
V_78:
V_22 = F_114 ( V_2 , V_147 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
int F_122 ( struct V_49 * V_33 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 ;
struct V_14 * V_156 ;
struct V_16 V_17 ;
int V_157 ;
V_2 = F_104 ( V_33 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_140 = V_155 ;
F_9 ( V_33 , & V_17 ) ;
F_10 (conn, &conn_iter) {
struct V_37 * V_9 = V_156 -> V_2 -> V_9 ;
struct V_7 * V_8 ;
if ( ! V_9 || V_156 -> V_59 != V_66 )
continue;
V_8 = F_118 ( V_2 , V_9 ) ;
if ( F_13 ( V_8 ) ) {
V_157 = F_14 ( V_8 ) ;
goto free;
}
V_8 -> V_36 = false ;
}
V_157 = F_109 ( V_2 ) ;
free:
F_17 ( & V_17 ) ;
F_65 ( V_2 ) ;
return V_157 ;
}
struct V_1 * F_123 ( struct V_49 * V_33 )
{
struct V_154 V_155 ;
struct V_1 * V_2 ;
int V_157 ;
F_124 ( & V_155 , 0 ) ;
V_141:
V_157 = F_125 ( V_33 , & V_155 ) ;
if ( V_157 < 0 ) {
V_2 = F_126 ( V_157 ) ;
goto V_158;
}
V_2 = F_127 ( V_33 , & V_155 ) ;
if ( F_13 ( V_2 ) )
goto V_158;
V_157 = F_122 ( V_33 , & V_155 ) ;
if ( V_157 < 0 ) {
F_65 ( V_2 ) ;
V_2 = F_126 ( V_157 ) ;
goto V_158;
}
V_158:
if ( F_14 ( V_2 ) == - V_143 ) {
F_128 ( & V_155 ) ;
goto V_141;
}
F_129 ( & V_155 ) ;
F_130 ( & V_155 ) ;
return V_2 ;
}
int F_131 ( struct V_49 * V_33 ,
struct V_1 * V_2 )
{
struct V_159 * V_160 = & V_33 -> V_64 ;
int V_157 ;
F_132 ( V_33 ) ;
F_133 ( V_33 ) ;
V_2 -> V_140 = V_160 -> V_140 ;
V_157 = F_109 ( V_2 ) ;
F_134 ( V_33 ) ;
return V_157 ;
}
int
F_135 ( struct V_37 * V_9 ,
struct V_62 * V_161 ,
T_2 V_162 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_22 = 0 ;
V_2 = F_104 ( V_9 -> V_33 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_140 = V_9 -> V_33 -> V_64 . V_140 ;
V_141:
V_8 = F_118 ( V_2 , V_9 ) ;
if ( F_13 ( V_8 ) ) {
V_22 = F_14 ( V_8 ) ;
goto V_113;
}
V_22 = F_136 ( V_9 , V_8 ,
V_161 , V_162 ) ;
if ( V_22 )
goto V_113;
V_22 = F_109 ( V_2 ) ;
V_113:
if ( V_22 == - V_143 )
goto V_144;
F_65 ( V_2 ) ;
return V_22 ;
V_144:
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
goto V_141;
}
int
F_137 ( struct V_5 * V_6 ,
struct V_62 * V_161 ,
T_2 V_162 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_22 = 0 ;
V_2 = F_104 ( V_6 -> V_33 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_140 = V_6 -> V_33 -> V_64 . V_140 ;
V_141:
V_4 = F_106 ( V_2 , V_6 ) ;
if ( F_13 ( V_4 ) ) {
V_22 = F_14 ( V_4 ) ;
goto V_113;
}
V_22 = F_138 ( V_6 , V_4 ,
V_161 , V_162 ) ;
if ( V_22 )
goto V_113;
V_22 = F_109 ( V_2 ) ;
V_113:
if ( V_22 == - V_143 )
goto V_144;
F_65 ( V_2 ) ;
return V_22 ;
V_144:
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
goto V_141;
}
int
F_139 ( struct V_14 * V_15 ,
struct V_62 * V_161 ,
T_2 V_162 )
{
struct V_1 * V_2 ;
struct V_12 * V_38 ;
int V_22 = 0 ;
V_2 = F_104 ( V_15 -> V_33 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_140 = V_15 -> V_33 -> V_64 . V_140 ;
V_141:
V_38 = F_12 ( V_2 , V_15 ) ;
if ( F_13 ( V_38 ) ) {
V_22 = F_14 ( V_38 ) ;
goto V_113;
}
V_22 = F_140 ( V_15 , V_38 ,
V_161 , V_162 ) ;
if ( V_22 )
goto V_113;
V_22 = F_109 ( V_2 ) ;
V_113:
if ( V_22 == - V_143 )
goto V_144;
F_65 ( V_2 ) ;
return V_22 ;
V_144:
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
goto V_141;
}
static int F_141 (
struct V_1 * V_2 ,
struct V_37 * V_9 ,
struct V_133 * V_81 ,
struct V_163 * V_108 )
{
struct V_5 * V_6 = V_9 -> V_67 ;
struct V_3 * V_4 ;
struct V_7 * V_8 ;
int V_22 = 0 ;
V_8 = F_118 ( V_2 , V_9 ) ;
if ( F_13 ( V_8 ) )
return F_14 ( V_8 ) ;
V_8 -> V_108 = V_108 ;
V_4 = F_106 ( V_2 , V_6 ) ;
if ( F_13 ( V_4 ) )
return F_14 ( V_4 ) ;
V_22 = F_107 ( V_4 , V_9 ) ;
if ( V_22 != 0 )
return V_22 ;
F_108 ( V_4 , V_81 ) ;
V_2 -> V_164 = false ;
if ( ! V_8 -> V_36 ) {
F_8 ( L_32 ,
V_9 -> V_29 . V_30 ) ;
return - V_32 ;
}
return V_22 ;
}
int F_142 ( struct V_37 * V_9 ,
struct V_133 * V_81 ,
struct V_163 * V_108 ,
T_1 V_115 )
{
struct V_5 * V_6 = V_9 -> V_67 ;
struct V_1 * V_2 ;
int V_22 = 0 ;
if ( V_115 & V_165 )
return - V_32 ;
V_2 = F_104 ( V_6 -> V_33 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_140 = F_105 ( V_9 ) ;
V_141:
V_22 = F_141 ( V_2 , V_9 , V_81 , V_108 ) ;
if ( V_22 != 0 )
goto V_113;
V_22 = F_143 ( V_2 ) ;
V_113:
if ( V_22 == - V_143 )
goto V_144;
F_65 ( V_2 ) ;
return V_22 ;
V_144:
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
V_6 -> V_145 = V_6 -> V_81 ;
goto V_141;
}
int F_144 (
struct V_37 * V_9 ,
struct V_133 * V_81 ,
struct V_163 * V_108 ,
T_1 V_115 ,
T_1 V_166 )
{
struct V_5 * V_6 = V_9 -> V_67 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_22 = 0 ;
if ( V_115 & V_165 )
return - V_32 ;
V_2 = F_104 ( V_6 -> V_33 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_140 = F_105 ( V_9 ) ;
V_141:
V_22 = F_141 ( V_2 , V_9 , V_81 , V_108 ) ;
if ( V_22 != 0 )
goto V_113;
V_8 = F_2 ( V_2 , V_9 ) ;
if ( F_3 ( ! V_8 ) ) {
V_22 = - V_32 ;
goto V_113;
}
V_8 -> V_167 = V_166 ;
V_22 = F_143 ( V_2 ) ;
V_113:
if ( V_22 == - V_143 )
goto V_144;
F_65 ( V_2 ) ;
return V_22 ;
V_144:
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
V_6 -> V_145 = V_6 -> V_81 ;
goto V_141;
}
int F_145 ( struct V_14 * V_15 ,
int V_43 )
{
struct V_159 * V_160 = & V_15 -> V_33 -> V_64 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_37 * V_9 ;
struct V_14 * V_168 ;
struct V_16 V_17 ;
int V_22 ;
bool V_36 = false ;
int V_169 = V_15 -> V_59 ;
if ( V_43 != V_66 )
V_43 = V_60 ;
V_15 -> V_59 = V_43 ;
V_9 = V_15 -> V_2 -> V_9 ;
if ( ! V_9 )
return 0 ;
V_2 = F_104 ( V_15 -> V_33 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_140 = F_105 ( V_9 ) ;
V_141:
V_8 = F_118 ( V_2 , V_9 ) ;
if ( F_13 ( V_8 ) ) {
V_22 = F_14 ( V_8 ) ;
goto V_113;
}
F_3 ( ! F_146 ( & V_160 -> V_148 ) ) ;
F_9 ( V_15 -> V_33 , & V_17 ) ;
F_10 (tmp_connector, &conn_iter) {
if ( V_168 -> V_2 -> V_9 != V_9 )
continue;
if ( V_168 -> V_59 == V_66 ) {
V_36 = true ;
break;
}
}
F_17 ( & V_17 ) ;
V_8 -> V_36 = V_36 ;
V_22 = F_109 ( V_2 ) ;
V_113:
if ( V_22 == - V_143 )
goto V_144;
if ( V_22 != 0 )
V_15 -> V_59 = V_169 ;
F_65 ( V_2 ) ;
return V_22 ;
V_144:
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
goto V_141;
}
struct V_18 *
F_6 ( struct V_14 * V_15 )
{
F_3 ( V_15 -> V_170 [ 1 ] ) ;
return F_147 ( V_15 -> V_33 , V_15 -> V_170 [ 0 ] ) ;
}
void F_148 ( struct V_37 * V_9 )
{
if ( V_9 -> V_2 )
F_149 ( V_9 -> V_2 ) ;
F_150 ( V_9 -> V_2 ) ;
V_9 -> V_2 = F_86 ( sizeof( * V_9 -> V_2 ) , V_103 ) ;
if ( V_9 -> V_2 )
V_9 -> V_2 -> V_9 = V_9 ;
}
void F_151 ( struct V_37 * V_9 ,
struct V_7 * V_2 )
{
memcpy ( V_2 , V_9 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_171 )
F_152 ( V_2 -> V_171 ) ;
if ( V_2 -> V_172 )
F_152 ( V_2 -> V_172 ) ;
if ( V_2 -> V_173 )
F_152 ( V_2 -> V_173 ) ;
if ( V_2 -> V_174 )
F_152 ( V_2 -> V_174 ) ;
V_2 -> V_41 = false ;
V_2 -> V_52 = false ;
V_2 -> V_10 = false ;
V_2 -> V_40 = false ;
V_2 -> V_175 = false ;
V_2 -> V_176 = false ;
V_2 -> V_108 = NULL ;
}
struct V_7 *
F_153 ( struct V_37 * V_9 )
{
struct V_7 * V_2 ;
if ( F_3 ( ! V_9 -> V_2 ) )
return NULL ;
V_2 = F_154 ( sizeof( * V_2 ) , V_103 ) ;
if ( V_2 )
F_151 ( V_9 , V_2 ) ;
return V_2 ;
}
void F_149 ( struct V_7 * V_2 )
{
F_155 ( V_2 -> V_171 ) ;
F_155 ( V_2 -> V_172 ) ;
F_155 ( V_2 -> V_173 ) ;
F_155 ( V_2 -> V_174 ) ;
}
void F_156 ( struct V_37 * V_9 ,
struct V_7 * V_2 )
{
F_149 ( V_2 ) ;
F_150 ( V_2 ) ;
}
void F_157 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 )
F_158 ( V_6 -> V_2 ) ;
F_150 ( V_6 -> V_2 ) ;
V_6 -> V_2 = F_86 ( sizeof( * V_6 -> V_2 ) , V_103 ) ;
if ( V_6 -> V_2 ) {
V_6 -> V_2 -> V_6 = V_6 ;
V_6 -> V_2 -> V_153 = V_177 ;
}
}
void F_159 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
memcpy ( V_2 , V_6 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_81 )
F_160 ( V_2 -> V_81 ) ;
V_2 -> V_80 = NULL ;
}
struct V_3 *
F_161 ( struct V_5 * V_6 )
{
struct V_3 * V_2 ;
if ( F_3 ( ! V_6 -> V_2 ) )
return NULL ;
V_2 = F_154 ( sizeof( * V_2 ) , V_103 ) ;
if ( V_2 )
F_159 ( V_6 , V_2 ) ;
return V_2 ;
}
void F_158 ( struct V_3 * V_2 )
{
if ( V_2 -> V_81 )
F_162 ( V_2 -> V_81 ) ;
if ( V_2 -> V_80 )
F_49 ( V_2 -> V_80 ) ;
}
void F_163 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
F_158 ( V_2 ) ;
F_150 ( V_2 ) ;
}
void
F_164 ( struct V_14 * V_15 ,
struct V_12 * V_13 )
{
if ( V_13 )
V_13 -> V_15 = V_15 ;
V_15 -> V_2 = V_13 ;
}
void F_165 ( struct V_14 * V_15 )
{
struct V_12 * V_13 =
F_86 ( sizeof( * V_13 ) , V_103 ) ;
if ( V_15 -> V_2 )
F_166 ( V_15 -> V_2 ) ;
F_150 ( V_15 -> V_2 ) ;
F_164 ( V_15 , V_13 ) ;
}
void
F_167 ( struct V_14 * V_15 ,
struct V_12 * V_2 )
{
memcpy ( V_2 , V_15 -> V_2 , sizeof( * V_2 ) ) ;
if ( V_2 -> V_9 )
F_168 ( V_15 ) ;
}
struct V_12 *
F_169 ( struct V_14 * V_15 )
{
struct V_12 * V_2 ;
if ( F_3 ( ! V_15 -> V_2 ) )
return NULL ;
V_2 = F_154 ( sizeof( * V_2 ) , V_103 ) ;
if ( V_2 )
F_167 ( V_15 , V_2 ) ;
return V_2 ;
}
struct V_1 *
F_127 ( struct V_49 * V_33 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 ;
struct V_14 * V_156 ;
struct V_16 V_17 ;
struct V_5 * V_6 ;
struct V_37 * V_9 ;
int V_157 = 0 ;
V_2 = F_104 ( V_33 ) ;
if ( ! V_2 )
return F_126 ( - V_104 ) ;
V_2 -> V_140 = V_155 ;
F_170 (crtc, dev) {
struct V_7 * V_8 ;
V_8 = F_118 ( V_2 , V_9 ) ;
if ( F_13 ( V_8 ) ) {
V_157 = F_14 ( V_8 ) ;
goto free;
}
}
F_171 (plane, dev) {
struct V_3 * V_4 ;
V_4 = F_106 ( V_2 , V_6 ) ;
if ( F_13 ( V_4 ) ) {
V_157 = F_14 ( V_4 ) ;
goto free;
}
}
F_9 ( V_33 , & V_17 ) ;
F_10 (conn, &conn_iter) {
struct V_12 * V_13 ;
V_13 = F_12 ( V_2 , V_156 ) ;
if ( F_13 ( V_13 ) ) {
V_157 = F_14 ( V_13 ) ;
F_17 ( & V_17 ) ;
goto free;
}
}
F_17 ( & V_17 ) ;
V_2 -> V_140 = NULL ;
free:
if ( V_157 < 0 ) {
F_65 ( V_2 ) ;
V_2 = F_126 ( V_157 ) ;
}
return V_2 ;
}
void
F_166 ( struct V_12 * V_2 )
{
if ( V_2 -> V_9 )
F_172 ( V_2 -> V_15 ) ;
}
void F_173 ( struct V_14 * V_15 ,
struct V_12 * V_2 )
{
F_166 ( V_2 ) ;
F_150 ( V_2 ) ;
}
int F_174 ( struct V_37 * V_9 ,
T_3 * V_178 , T_3 * V_179 , T_3 * V_180 ,
T_1 V_181 )
{
struct V_49 * V_33 = V_9 -> V_33 ;
struct V_159 * V_160 = & V_33 -> V_64 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_182 * V_183 = NULL ;
struct V_184 * V_185 ;
int V_21 , V_22 = 0 ;
V_2 = F_104 ( V_9 -> V_33 ) ;
if ( ! V_2 )
return - V_104 ;
V_183 = F_175 ( V_33 ,
sizeof( struct V_184 ) * V_181 ,
NULL ) ;
if ( F_13 ( V_183 ) ) {
V_22 = F_14 ( V_183 ) ;
V_183 = NULL ;
goto V_113;
}
V_185 = (struct V_184 * ) V_183 -> V_186 ;
for ( V_21 = 0 ; V_21 < V_181 ; V_21 ++ ) {
V_185 [ V_21 ] . V_178 = V_178 [ V_21 ] ;
V_185 [ V_21 ] . V_179 = V_179 [ V_21 ] ;
V_185 [ V_21 ] . V_180 = V_180 [ V_21 ] ;
}
V_2 -> V_140 = V_9 -> V_33 -> V_64 . V_140 ;
V_141:
V_8 = F_118 ( V_2 , V_9 ) ;
if ( F_13 ( V_8 ) ) {
V_22 = F_14 ( V_8 ) ;
goto V_113;
}
V_22 = F_136 ( V_9 , V_8 ,
V_160 -> V_187 , 0 ) ;
if ( V_22 )
goto V_113;
V_22 = F_136 ( V_9 , V_8 ,
V_160 -> V_188 , 0 ) ;
if ( V_22 )
goto V_113;
V_22 = F_136 ( V_9 , V_8 ,
V_160 -> V_189 , V_183 -> V_29 . V_30 ) ;
if ( V_22 )
goto V_113;
V_22 = F_109 ( V_2 ) ;
V_113:
if ( V_22 == - V_143 )
goto V_144;
F_65 ( V_2 ) ;
F_155 ( V_183 ) ;
return V_22 ;
V_144:
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
goto V_141;
}
