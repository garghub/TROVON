void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_2 (ior, &disp->ior, head) {
if ( ( V_4 = V_6 -> V_7 . V_4 ) && V_6 -> V_7 . V_4 != V_6 -> V_8 . V_4 ) {
F_3 ( V_4 , L_1 , V_6 -> V_9 ) ;
if ( V_6 -> V_10 -> V_11 . V_12 )
V_6 -> V_10 -> V_11 . V_12 ( V_4 , NULL ) ;
V_6 -> V_7 . V_4 = NULL ;
}
}
F_2 (ior, &disp->ior, head) {
if ( ( V_4 = V_6 -> V_8 . V_4 ) ) {
F_3 ( V_4 , L_2 , V_6 -> V_9 ) ;
if ( V_6 -> V_8 . V_4 != V_6 -> V_7 . V_4 ) {
if ( V_6 -> V_10 -> V_11 . V_12 )
V_6 -> V_10 -> V_11 . V_12 ( V_4 , V_6 ) ;
V_6 -> V_7 . V_4 = V_6 -> V_8 . V_4 ;
}
}
}
}
static enum V_13
F_4 ( struct V_3 * V_4 , enum V_14 * type )
{
switch ( V_4 -> V_15 . V_16 ) {
case 0 :
switch ( V_4 -> V_15 . type ) {
case V_17 : * type = V_18 ; return V_19 ;
case V_20 : * type = V_18 ; return V_21 ;
case V_22 : * type = V_23 ; return V_24 ;
case V_25 : * type = V_23 ; return V_26 ;
case V_27 : * type = V_23 ; return V_28 ;
default:
break;
}
break;
case 1 :
switch ( V_4 -> V_15 . type ) {
case V_22 : * type = V_29 ; return V_24 ;
case V_27 : * type = V_29 ; return V_24 ;
default:
break;
}
break;
default:
break;
}
F_5 ( 1 ) ;
return V_30 ;
}
void
F_6 ( struct V_3 * V_4 , T_1 V_31 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
F_7 ( V_4 , L_3 , V_4 -> V_32 , ~ V_31 , V_6 ) ;
if ( V_6 ) {
V_4 -> V_32 &= ~ V_31 ;
if ( ! V_4 -> V_32 ) {
V_4 -> V_6 -> V_8 . V_4 = NULL ;
V_4 -> V_6 = NULL ;
}
}
}
static inline int
F_8 ( struct V_3 * V_4 , T_1 V_31 , struct V_5 * V_6 )
{
V_4 -> V_6 = V_6 ;
V_4 -> V_6 -> V_8 . V_4 = V_4 ;
V_4 -> V_6 -> V_8 . V_33 = V_4 -> V_15 . V_34 . V_33 ;
V_4 -> V_32 |= V_31 ;
return 0 ;
}
int
F_9 ( struct V_3 * V_4 , T_1 V_31 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
enum V_13 V_35 ;
enum V_14 type ;
F_7 ( V_4 , L_4 , V_4 -> V_32 , V_31 , V_6 ) ;
if ( V_6 ) {
V_4 -> V_32 |= V_31 ;
return 0 ;
}
V_35 = F_4 ( V_4 , & type ) ;
if ( V_35 == V_30 )
return - V_36 ;
F_2 (ior, &outp->disp->ior, head) {
if ( ! V_6 -> V_8 . V_4 && V_6 -> V_7 . V_4 == V_4 )
return F_8 ( V_4 , V_31 , V_6 ) ;
}
F_2 (ior, &outp->disp->ior, head) {
if ( ! V_6 -> V_8 . V_4 && V_6 -> type == type && ! V_6 -> V_7 . V_4 &&
( V_6 -> V_10 -> V_11 . V_12 || V_6 -> V_37 == F_10 ( V_4 -> V_15 . V_38 ) ) )
return F_8 ( V_4 , V_31 , V_6 ) ;
}
F_2 (ior, &outp->disp->ior, head) {
if ( ! V_6 -> V_8 . V_4 && V_6 -> type == type &&
( V_6 -> V_10 -> V_11 . V_12 || V_6 -> V_37 == F_10 ( V_4 -> V_15 . V_38 ) ) )
return F_8 ( V_4 , V_31 , V_6 ) ;
}
return - V_39 ;
}
void
F_11 ( struct V_3 * V_4 )
{
if ( V_4 -> V_10 -> V_40 )
V_4 -> V_10 -> V_40 ( V_4 ) ;
}
static void
F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_13 V_35 ;
enum V_14 type ;
struct V_5 * V_6 ;
int V_37 , V_33 ;
V_35 = F_4 ( V_4 , & type ) ;
if ( V_35 == V_30 )
return;
V_6 = F_13 ( V_2 , type , - 1 ) ;
if ( ! V_6 ) {
F_5 ( 1 ) ;
return;
}
if ( V_6 -> V_10 -> V_11 . V_41 ) {
V_37 = V_6 -> V_10 -> V_11 . V_41 ( V_4 , & V_33 ) ;
if ( V_37 < 0 ) {
F_3 ( V_4 , L_5 ) ;
return;
}
} else {
V_37 = F_14 ( V_4 -> V_15 . V_38 ) - 1 ;
V_33 = ( V_6 -> type == V_23 ) ? V_4 -> V_15 . V_34 . V_33 : 0 ;
}
V_6 = F_13 ( V_2 , type , V_37 ) ;
if ( ! V_6 ) {
F_5 ( 1 ) ;
return;
}
V_6 -> V_10 -> V_42 ( V_6 , & V_6 -> V_7 ) ;
if ( ! V_6 -> V_7 . V_43 || V_6 -> V_7 . V_35 != V_35 ) {
F_3 ( V_4 , L_6 , V_6 -> V_7 . V_43 ,
V_6 -> V_7 . V_35 , V_35 ) ;
return;
}
F_3 ( V_4 , L_7 , V_6 -> V_9 , V_6 -> V_7 . V_33 ) ;
V_6 -> V_7 . V_4 = V_4 ;
}
void
F_15 ( struct V_3 * V_4 )
{
F_12 ( V_4 ) ;
if ( V_4 -> V_10 -> V_44 )
V_4 -> V_10 -> V_44 ( V_4 ) ;
}
void
F_16 ( struct V_3 * * V_45 )
{
struct V_3 * V_4 = * V_45 ;
if ( V_4 && ! F_5 ( ! V_4 -> V_10 ) ) {
if ( V_4 -> V_10 -> V_46 )
* V_45 = V_4 -> V_10 -> V_46 ( V_4 ) ;
F_17 ( * V_45 ) ;
* V_45 = NULL ;
}
}
int
F_18 ( const struct V_47 * V_10 , struct V_1 * V_2 ,
int V_48 , struct V_49 * V_50 , struct V_3 * V_4 )
{
struct V_51 * V_52 = V_2 -> V_53 . V_54 . V_55 -> V_52 ;
enum V_13 V_35 ;
enum V_14 type ;
V_4 -> V_10 = V_10 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_48 = V_48 ;
V_4 -> V_15 = * V_50 ;
V_4 -> V_52 = F_19 ( V_52 , V_50 -> V_56 ) ;
V_4 -> V_38 = F_14 ( V_4 -> V_15 . V_38 ) - 1 ;
F_3 ( V_4 , L_8
L_9 ,
V_4 -> V_15 . type , V_4 -> V_15 . V_16 , V_4 -> V_15 . V_38 ,
V_4 -> V_15 . type >= 2 ? V_4 -> V_15 . V_34 . V_33 : 0 ,
V_4 -> V_15 . V_57 , V_4 -> V_15 . V_56 ,
V_4 -> V_15 . V_58 , V_4 -> V_15 . V_59 ) ;
V_35 = F_4 ( V_4 , & type ) ;
if ( V_35 == V_30 )
return - V_60 ;
return 0 ;
}
int
F_20 ( struct V_1 * V_2 , int V_48 , struct V_49 * V_50 ,
struct V_3 * * V_45 )
{
if ( ! ( * V_45 = F_21 ( sizeof( * * V_45 ) , V_61 ) ) )
return - V_62 ;
return F_18 ( & V_3 , V_2 , V_48 , V_50 , * V_45 ) ;
}
