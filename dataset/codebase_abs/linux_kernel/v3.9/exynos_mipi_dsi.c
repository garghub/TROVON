static struct V_1 * F_1 ( struct V_2
* V_3 )
{
return V_3 -> V_4 . V_5 ;
}
static int F_2 ( struct V_6 * V_7 )
{
int V_8 ;
F_3 ( & V_7 -> V_9 ) ;
V_8 = F_4 ( F_5 ( V_10 ) , V_10 ) ;
F_6 ( & V_7 -> V_9 ) ;
return V_8 ;
}
static int F_7 ( struct V_6 * V_7 )
{
int V_8 ;
F_3 ( & V_7 -> V_9 ) ;
V_8 = F_8 ( F_5 ( V_10 ) , V_10 ) ;
F_6 ( & V_7 -> V_9 ) ;
return V_8 ;
}
static void F_9 ( struct V_6 * V_7 )
{
F_10 ( V_7 , 0 ) ;
F_11 ( V_7 ) ;
F_12 ( V_7 ) ;
F_13 ( V_7 ) ;
F_14 ( V_7 , V_7 -> V_11 ) ;
F_15 ( V_7 ) ;
F_10 ( V_7 , 1 ) ;
}
static int F_16 ( struct V_6 * V_7 ,
int V_12 )
{
struct V_13 * V_14 = V_7 -> V_15 ;
struct V_16 * V_17 = V_7 -> V_18 ;
switch ( V_12 ) {
case V_19 :
if ( V_7 -> V_20 )
return 0 ;
if ( V_14 && V_14 -> V_21 )
V_14 -> V_21 ( V_17 ) ;
F_17 ( V_7 -> clock ) ;
F_7 ( V_7 ) ;
V_7 -> V_20 = true ;
break;
default:
break;
}
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , int V_12 )
{
struct V_2 * V_3 = F_19 ( V_7 -> V_4 ) ;
struct V_13 * V_14 = V_7 -> V_15 ;
struct V_16 * V_17 = V_7 -> V_18 ;
switch ( V_12 ) {
case V_22 :
if ( ! V_7 -> V_20 )
return 0 ;
if ( V_14 && V_14 -> V_23 )
V_14 -> V_23 ( V_17 , 1 ) ;
F_2 ( V_7 ) ;
if ( V_7 -> V_24 -> V_25 )
V_7 -> V_24 -> V_25 ( V_3 , true ) ;
F_20 ( V_7 -> clock ) ;
F_9 ( V_7 ) ;
if ( V_14 && V_14 -> V_26 )
V_14 -> V_26 ( V_17 ) ;
V_7 -> V_20 = false ;
break;
case V_27 :
break;
default:
break;
}
return 0 ;
}
int F_21 ( struct V_16 * V_28 )
{
struct V_29 * V_30 ;
if ( ! V_28 -> V_31 ) {
F_22 ( L_1 ) ;
return - V_32 ;
}
V_30 = F_23 ( sizeof( struct V_29 ) , V_33 ) ;
if ( ! V_30 ) {
F_22 ( L_2 ) ;
return - V_34 ;
}
V_30 -> V_18 = V_28 ;
F_3 ( & V_35 ) ;
F_24 ( & V_30 -> V_36 , & V_37 ) ;
F_6 ( & V_35 ) ;
return 0 ;
}
static struct V_29 * F_25 (
struct V_13 * V_38 )
{
struct V_29 * V_30 , * V_39 ;
struct V_16 * V_28 ;
F_3 ( & V_35 ) ;
F_26 (dsim_ddi, next, &dsim_ddi_list, list) {
if ( ! V_30 )
goto V_40;
V_28 = V_30 -> V_18 ;
if ( ! V_28 )
continue;
if ( ( strcmp ( V_38 -> V_31 , V_28 -> V_31 ) ) == 0 ) {
V_30 -> V_41 = V_28 -> V_41 ;
F_6 ( & V_35 ) ;
return V_30 ;
}
F_27 ( & V_30 -> V_36 ) ;
F_28 ( V_30 ) ;
}
V_40:
F_6 ( & V_35 ) ;
return NULL ;
}
int F_29 ( struct V_13 * V_38 )
{
struct V_29 * V_30 ;
if ( ! V_38 -> V_31 ) {
F_22 ( L_3 ) ;
return - V_32 ;
}
V_30 = F_25 ( V_38 ) ;
if ( ! V_30 ) {
F_22 ( L_4 ) ;
return - V_32 ;
}
V_30 -> V_15 = V_38 ;
F_30 ( L_5 ,
V_38 -> V_31 ) ;
return 0 ;
}
static struct V_29 * F_31 (
struct V_6 * V_7 ,
const char * V_31 )
{
struct V_29 * V_30 , * V_39 ;
struct V_13 * V_38 ;
struct V_16 * V_28 ;
int V_8 ;
F_3 ( & V_7 -> V_9 ) ;
F_26 (dsim_ddi, next, &dsim_ddi_list, list) {
V_38 = V_30 -> V_15 ;
V_28 = V_30 -> V_18 ;
if ( ! V_38 || ! V_28 ||
( V_7 -> V_42 != V_30 -> V_41 ) )
continue;
F_32 ( V_7 -> V_4 , L_6 ,
V_38 -> V_42 , V_28 -> V_42 ) ;
F_32 ( V_7 -> V_4 , L_7 ,
V_28 -> V_41 , V_7 -> V_42 ) ;
if ( ( strcmp ( V_38 -> V_31 , V_31 ) == 0 ) ) {
V_28 -> V_43 = V_7 ;
V_28 -> V_4 . V_44 = V_7 -> V_4 ;
F_33 ( & V_28 -> V_4 , L_8 , V_38 -> V_31 ) ;
V_8 = F_34 ( & V_28 -> V_4 ) ;
if ( V_8 < 0 ) {
F_35 ( V_7 -> V_4 ,
L_9 ,
F_36 ( & V_28 -> V_4 ) , V_8 ) ;
F_6 ( & V_7 -> V_9 ) ;
return NULL ;
}
V_7 -> V_18 = V_28 ;
V_7 -> V_15 = V_38 ;
F_6 ( & V_7 -> V_9 ) ;
return V_30 ;
}
}
F_6 ( & V_7 -> V_9 ) ;
return NULL ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_45 * V_46 ;
struct V_6 * V_7 ;
struct V_47 * V_11 ;
struct V_1 * V_48 ;
struct V_29 * V_30 ;
int V_8 = - V_49 ;
V_7 = F_38 ( & V_3 -> V_4 , sizeof( struct V_6 ) ,
V_33 ) ;
if ( ! V_7 ) {
F_35 ( & V_3 -> V_4 , L_10 ) ;
return - V_34 ;
}
V_7 -> V_24 = F_1 ( V_3 ) ;
V_7 -> V_4 = & V_3 -> V_4 ;
V_7 -> V_42 = V_3 -> V_42 ;
V_48 = (struct V_1 * ) V_7 -> V_24 ;
if ( V_48 == NULL ) {
F_35 ( & V_3 -> V_4 , L_11 ) ;
return - V_49 ;
}
V_11 = V_48 -> V_11 ;
if ( V_11 == NULL ) {
F_35 ( & V_3 -> V_4 , L_12 ) ;
return - V_49 ;
}
V_7 -> V_11 = V_11 ;
V_7 -> V_50 = & V_50 ;
F_39 ( & V_7 -> V_9 ) ;
V_8 = F_40 ( & V_3 -> V_4 , F_5 ( V_10 ) ,
V_10 ) ;
if ( V_8 ) {
F_35 ( & V_3 -> V_4 , L_13 , V_8 ) ;
return V_8 ;
}
V_7 -> clock = F_41 ( & V_3 -> V_4 , L_14 ) ;
if ( F_42 ( V_7 -> clock ) ) {
F_35 ( & V_3 -> V_4 , L_15 ) ;
return - V_51 ;
}
F_20 ( V_7 -> clock ) ;
V_46 = F_43 ( V_3 , V_52 , 0 ) ;
V_7 -> V_53 = F_44 ( & V_3 -> V_4 , V_46 ) ;
if ( ! V_7 -> V_53 ) {
F_35 ( & V_3 -> V_4 , L_16 ) ;
V_8 = - V_34 ;
goto error;
}
F_39 ( & V_7 -> V_9 ) ;
V_30 = F_31 ( V_7 , V_48 -> V_54 ) ;
if ( ! V_30 ) {
F_35 ( & V_3 -> V_4 , L_4 ) ;
V_8 = - V_49 ;
goto error;
}
V_7 -> V_55 = F_45 ( V_3 , 0 ) ;
if ( F_46 ( V_7 -> V_55 ) ) {
F_35 ( & V_3 -> V_4 , L_17 ) ;
V_8 = - V_49 ;
goto error;
}
F_47 ( & V_56 ) ;
F_47 ( & V_57 ) ;
F_48 ( V_3 , V_7 ) ;
V_8 = F_49 ( & V_3 -> V_4 , V_7 -> V_55 ,
V_58 ,
V_59 , F_36 ( & V_3 -> V_4 ) , V_7 ) ;
if ( V_8 != 0 ) {
F_35 ( & V_3 -> V_4 , L_18 ) ;
V_8 = - V_49 ;
goto error;
}
F_15 ( V_7 ) ;
if ( V_30 -> V_15 && V_30 -> V_15 -> V_60 )
V_30 -> V_15 -> V_60 ( V_30 -> V_18 ) ;
if ( V_48 -> V_61 ) {
F_2 ( V_7 ) ;
goto V_62;
}
if ( V_30 -> V_15 && V_30 -> V_15 -> V_23 )
V_30 -> V_15 -> V_23 ( V_30 -> V_18 , 1 ) ;
F_2 ( V_7 ) ;
if ( V_7 -> V_24 -> V_25 )
V_7 -> V_24 -> V_25 ( V_3 , true ) ;
F_9 ( V_7 ) ;
if ( V_30 -> V_15 && V_30 -> V_15 -> V_26 )
V_30 -> V_15 -> V_26 ( V_30 -> V_18 ) ;
V_7 -> V_20 = false ;
V_62:
F_48 ( V_3 , V_7 ) ;
F_32 ( & V_3 -> V_4 , L_19 , V_63 ,
V_11 -> V_64 == V_65 ? L_20 : L_21 ) ;
return 0 ;
error:
F_17 ( V_7 -> clock ) ;
return V_8 ;
}
static int F_50 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_51 ( V_3 ) ;
struct V_29 * V_30 , * V_39 ;
struct V_13 * V_15 ;
F_17 ( V_7 -> clock ) ;
F_26 (dsim_ddi, next, &dsim_ddi_list, list) {
if ( V_30 ) {
if ( V_7 -> V_42 != V_30 -> V_41 )
continue;
V_15 = V_30 -> V_15 ;
if ( V_15 -> remove )
V_15 -> remove ( V_30 -> V_18 ) ;
F_28 ( V_30 ) ;
}
}
return 0 ;
}
static int F_52 ( struct V_66 * V_4 )
{
struct V_2 * V_3 = F_19 ( V_4 ) ;
struct V_6 * V_7 = F_51 ( V_3 ) ;
struct V_13 * V_14 = V_7 -> V_15 ;
struct V_16 * V_17 = V_7 -> V_18 ;
F_53 ( V_7 -> V_55 ) ;
if ( V_7 -> V_20 )
return 0 ;
if ( V_14 && V_14 -> V_21 )
V_14 -> V_21 ( V_17 ) ;
if ( V_7 -> V_24 -> V_25 )
V_7 -> V_24 -> V_25 ( V_3 , false ) ;
F_17 ( V_7 -> clock ) ;
F_7 ( V_7 ) ;
V_7 -> V_20 = true ;
return 0 ;
}
static int F_54 ( struct V_66 * V_4 )
{
struct V_2 * V_3 = F_19 ( V_4 ) ;
struct V_6 * V_7 = F_51 ( V_3 ) ;
struct V_13 * V_14 = V_7 -> V_15 ;
struct V_16 * V_17 = V_7 -> V_18 ;
F_55 ( V_7 -> V_55 ) ;
if ( ! V_7 -> V_20 )
return 0 ;
if ( V_14 && V_14 -> V_23 )
V_14 -> V_23 ( V_17 , 1 ) ;
F_2 ( V_7 ) ;
if ( V_7 -> V_24 -> V_25 )
V_7 -> V_24 -> V_25 ( V_3 , true ) ;
F_20 ( V_7 -> clock ) ;
F_9 ( V_7 ) ;
if ( V_14 && V_14 -> V_26 )
V_14 -> V_26 ( V_17 ) ;
V_7 -> V_20 = false ;
return 0 ;
}
