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
struct V_13 * V_14 = V_7 -> V_15 ;
struct V_16 * V_17 = V_7 -> V_18 ;
switch ( V_12 ) {
case V_22 :
if ( ! V_7 -> V_20 )
return 0 ;
if ( V_14 && V_14 -> V_23 )
V_14 -> V_23 ( V_17 , 1 ) ;
F_2 ( V_7 ) ;
F_19 ( V_7 -> V_24 ) ;
F_20 ( V_7 -> clock ) ;
F_9 ( V_7 ) ;
if ( V_14 && V_14 -> V_25 )
V_14 -> V_25 ( V_17 ) ;
V_7 -> V_20 = false ;
break;
case V_26 :
break;
default:
break;
}
return 0 ;
}
int F_21 ( struct V_16 * V_27 )
{
struct V_28 * V_29 ;
if ( ! V_27 -> V_30 ) {
F_22 ( L_1 ) ;
return - V_31 ;
}
V_29 = F_23 ( sizeof( struct V_28 ) , V_32 ) ;
if ( ! V_29 ) {
F_22 ( L_2 ) ;
return - V_33 ;
}
V_29 -> V_18 = V_27 ;
F_3 ( & V_34 ) ;
F_24 ( & V_29 -> V_35 , & V_36 ) ;
F_6 ( & V_34 ) ;
return 0 ;
}
static struct V_28 * F_25 (
struct V_13 * V_37 )
{
struct V_28 * V_29 , * V_38 ;
struct V_16 * V_27 ;
F_3 ( & V_34 ) ;
F_26 (dsim_ddi, next, &dsim_ddi_list, list) {
if ( ! V_29 )
goto V_39;
V_27 = V_29 -> V_18 ;
if ( ! V_27 )
continue;
if ( ( strcmp ( V_37 -> V_30 , V_27 -> V_30 ) ) == 0 ) {
V_29 -> V_40 = V_27 -> V_40 ;
F_6 ( & V_34 ) ;
return V_29 ;
}
F_27 ( & V_29 -> V_35 ) ;
F_28 ( V_29 ) ;
}
V_39:
F_6 ( & V_34 ) ;
return NULL ;
}
int F_29 ( struct V_13 * V_37 )
{
struct V_28 * V_29 ;
if ( ! V_37 -> V_30 ) {
F_22 ( L_3 ) ;
return - V_31 ;
}
V_29 = F_25 ( V_37 ) ;
if ( ! V_29 ) {
F_22 ( L_4 ) ;
return - V_31 ;
}
V_29 -> V_15 = V_37 ;
F_30 ( L_5 ,
V_37 -> V_30 ) ;
return 0 ;
}
static struct V_28 * F_31 (
struct V_6 * V_7 ,
const char * V_30 )
{
struct V_28 * V_29 , * V_38 ;
struct V_13 * V_37 ;
struct V_16 * V_27 ;
int V_8 ;
F_3 ( & V_7 -> V_9 ) ;
F_26 (dsim_ddi, next, &dsim_ddi_list, list) {
V_37 = V_29 -> V_15 ;
V_27 = V_29 -> V_18 ;
if ( ! V_37 || ! V_27 ||
( V_7 -> V_41 != V_29 -> V_40 ) )
continue;
F_32 ( V_7 -> V_4 , L_6 ,
V_37 -> V_41 , V_27 -> V_41 ) ;
F_32 ( V_7 -> V_4 , L_7 ,
V_27 -> V_40 , V_7 -> V_41 ) ;
if ( ( strcmp ( V_37 -> V_30 , V_30 ) == 0 ) ) {
V_27 -> V_42 = V_7 ;
V_27 -> V_4 . V_43 = V_7 -> V_4 ;
F_33 ( & V_27 -> V_4 , L_8 , V_37 -> V_30 ) ;
V_8 = F_34 ( & V_27 -> V_4 ) ;
if ( V_8 < 0 ) {
F_35 ( V_7 -> V_4 ,
L_9 ,
F_36 ( & V_27 -> V_4 ) , V_8 ) ;
F_6 ( & V_7 -> V_9 ) ;
return NULL ;
}
V_7 -> V_18 = V_27 ;
V_7 -> V_15 = V_37 ;
F_6 ( & V_7 -> V_9 ) ;
return V_29 ;
}
}
F_6 ( & V_7 -> V_9 ) ;
return NULL ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_44 * V_45 ;
struct V_6 * V_7 ;
struct V_46 * V_11 ;
struct V_1 * V_47 ;
struct V_28 * V_29 ;
int V_8 = - V_48 ;
V_7 = F_38 ( & V_3 -> V_4 , sizeof( struct V_6 ) ,
V_32 ) ;
if ( ! V_7 ) {
F_35 ( & V_3 -> V_4 , L_10 ) ;
return - V_33 ;
}
V_7 -> V_49 = F_1 ( V_3 ) ;
V_7 -> V_4 = & V_3 -> V_4 ;
V_7 -> V_41 = V_3 -> V_41 ;
V_47 = (struct V_1 * ) V_7 -> V_49 ;
if ( V_47 == NULL ) {
F_35 ( & V_3 -> V_4 , L_11 ) ;
return - V_48 ;
}
V_11 = V_47 -> V_11 ;
if ( V_11 == NULL ) {
F_35 ( & V_3 -> V_4 , L_12 ) ;
return - V_48 ;
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
V_7 -> V_24 = F_41 ( & V_3 -> V_4 , L_14 ) ;
if ( F_42 ( V_7 -> V_24 ) )
return F_43 ( V_7 -> V_24 ) ;
V_7 -> clock = F_44 ( & V_3 -> V_4 , L_15 ) ;
if ( F_42 ( V_7 -> clock ) ) {
F_35 ( & V_3 -> V_4 , L_16 ) ;
return - V_51 ;
}
F_20 ( V_7 -> clock ) ;
V_45 = F_45 ( V_3 , V_52 , 0 ) ;
V_7 -> V_53 = F_46 ( & V_3 -> V_4 , V_45 ) ;
if ( F_42 ( V_7 -> V_53 ) ) {
V_8 = F_43 ( V_7 -> V_53 ) ;
goto error;
}
F_39 ( & V_7 -> V_9 ) ;
V_29 = F_31 ( V_7 , V_47 -> V_54 ) ;
if ( ! V_29 ) {
F_35 ( & V_3 -> V_4 , L_4 ) ;
V_8 = - V_48 ;
goto error;
}
V_8 = F_47 ( V_3 , 0 ) ;
if ( V_8 < 0 ) {
F_35 ( & V_3 -> V_4 , L_17 ) ;
goto error;
}
V_7 -> V_55 = V_8 ;
F_48 ( & V_56 ) ;
F_48 ( & V_57 ) ;
F_49 ( V_3 , V_7 ) ;
V_8 = F_50 ( & V_3 -> V_4 , V_7 -> V_55 ,
V_58 ,
V_59 , F_36 ( & V_3 -> V_4 ) , V_7 ) ;
if ( V_8 != 0 ) {
F_35 ( & V_3 -> V_4 , L_18 ) ;
V_8 = - V_48 ;
goto error;
}
F_15 ( V_7 ) ;
if ( V_29 -> V_15 && V_29 -> V_15 -> V_60 )
V_29 -> V_15 -> V_60 ( V_29 -> V_18 ) ;
if ( V_47 -> V_61 ) {
F_2 ( V_7 ) ;
goto V_62;
}
if ( V_29 -> V_15 && V_29 -> V_15 -> V_23 )
V_29 -> V_15 -> V_23 ( V_29 -> V_18 , 1 ) ;
F_2 ( V_7 ) ;
F_19 ( V_7 -> V_24 ) ;
F_9 ( V_7 ) ;
if ( V_29 -> V_15 && V_29 -> V_15 -> V_25 )
V_29 -> V_15 -> V_25 ( V_29 -> V_18 ) ;
V_7 -> V_20 = false ;
V_62:
F_49 ( V_3 , V_7 ) ;
F_32 ( & V_3 -> V_4 , L_19 , V_63 ,
V_11 -> V_64 == V_65 ? L_20 : L_21 ) ;
return 0 ;
error:
F_17 ( V_7 -> clock ) ;
return V_8 ;
}
static int F_51 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_52 ( V_3 ) ;
struct V_28 * V_29 , * V_38 ;
struct V_13 * V_15 ;
F_17 ( V_7 -> clock ) ;
F_26 (dsim_ddi, next, &dsim_ddi_list, list) {
if ( V_29 ) {
if ( V_7 -> V_41 != V_29 -> V_40 )
continue;
V_15 = V_29 -> V_15 ;
if ( V_15 -> remove )
V_15 -> remove ( V_29 -> V_18 ) ;
F_28 ( V_29 ) ;
}
}
return 0 ;
}
static int F_53 ( struct V_66 * V_4 )
{
struct V_2 * V_3 = F_54 ( V_4 ) ;
struct V_6 * V_7 = F_52 ( V_3 ) ;
struct V_13 * V_14 = V_7 -> V_15 ;
struct V_16 * V_17 = V_7 -> V_18 ;
F_55 ( V_7 -> V_55 ) ;
if ( V_7 -> V_20 )
return 0 ;
if ( V_14 && V_14 -> V_21 )
V_14 -> V_21 ( V_17 ) ;
F_56 ( V_7 -> V_24 ) ;
F_17 ( V_7 -> clock ) ;
F_7 ( V_7 ) ;
V_7 -> V_20 = true ;
return 0 ;
}
static int F_57 ( struct V_66 * V_4 )
{
struct V_2 * V_3 = F_54 ( V_4 ) ;
struct V_6 * V_7 = F_52 ( V_3 ) ;
struct V_13 * V_14 = V_7 -> V_15 ;
struct V_16 * V_17 = V_7 -> V_18 ;
F_58 ( V_7 -> V_55 ) ;
if ( ! V_7 -> V_20 )
return 0 ;
if ( V_14 && V_14 -> V_23 )
V_14 -> V_23 ( V_17 , 1 ) ;
F_2 ( V_7 ) ;
F_19 ( V_7 -> V_24 ) ;
F_20 ( V_7 -> clock ) ;
F_9 ( V_7 ) ;
if ( V_14 && V_14 -> V_25 )
V_14 -> V_25 ( V_17 ) ;
V_7 -> V_20 = false ;
return 0 ;
}
