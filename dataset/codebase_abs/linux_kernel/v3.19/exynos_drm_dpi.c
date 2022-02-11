static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static enum V_5
F_3 ( struct V_6 * V_7 , bool V_8 )
{
struct V_1 * V_9 = F_4 ( V_7 ) ;
if ( V_9 -> V_10 && ! V_9 -> V_10 -> V_7 )
F_5 ( V_9 -> V_10 , & V_9 -> V_7 ) ;
return V_11 ;
}
static void F_6 ( struct V_6 * V_7 )
{
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_9 = F_4 ( V_7 ) ;
if ( V_9 -> V_12 ) {
struct V_13 * V_14 ;
V_14 = F_10 ( V_7 -> V_15 ) ;
if ( ! V_14 ) {
F_11 ( L_1 ) ;
return 0 ;
}
F_12 ( V_9 -> V_12 , V_14 ) ;
V_14 -> type = V_16 | V_17 ;
F_13 ( V_7 , V_14 ) ;
return 1 ;
}
if ( V_9 -> V_10 )
return V_9 -> V_10 -> V_18 -> V_19 ( V_9 -> V_10 ) ;
return 0 ;
}
static struct V_20 *
F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_9 = F_4 ( V_7 ) ;
return V_9 -> V_21 ;
}
static int F_15 ( struct V_2 * V_4 ,
struct V_20 * V_21 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_6 * V_7 = & V_9 -> V_7 ;
int V_22 ;
V_9 -> V_21 = V_21 ;
V_7 -> V_23 = V_24 ;
V_22 = F_16 ( V_21 -> V_15 , V_7 ,
& V_25 ,
V_26 ) ;
if ( V_22 ) {
F_11 ( L_2 ) ;
return V_22 ;
}
F_17 ( V_7 , & V_27 ) ;
F_18 ( V_7 ) ;
F_19 ( V_7 , V_21 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_9 )
{
if ( V_9 -> V_10 ) {
F_21 ( V_9 -> V_10 ) ;
F_22 ( V_9 -> V_10 ) ;
}
}
static void F_23 ( struct V_1 * V_9 )
{
if ( V_9 -> V_10 ) {
F_24 ( V_9 -> V_10 ) ;
F_25 ( V_9 -> V_10 ) ;
}
}
static void F_26 ( struct V_2 * V_4 , int V_14 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
switch ( V_14 ) {
case V_28 :
if ( V_9 -> V_29 != V_28 )
F_20 ( V_9 ) ;
break;
case V_30 :
case V_31 :
case V_32 :
if ( V_9 -> V_29 == V_28 )
F_23 ( V_9 ) ;
break;
default:
break;
}
V_9 -> V_29 = V_14 ;
}
static struct V_33 *
F_27 ( struct V_33 * V_34 , const char * V_35 , T_1 V_36 )
{
struct V_33 * V_37 ;
F_28 (parent, np) {
T_1 V_38 ;
if ( ! V_37 -> V_35 || F_29 ( V_37 -> V_35 , V_35 ) )
continue;
if ( F_30 ( V_37 , L_3 , & V_38 ) < 0 )
V_38 = 0 ;
if ( V_36 == V_38 )
break;
}
return V_37 ;
}
static struct V_33 * F_31 ( struct V_33 * V_34 ,
T_1 V_36 )
{
struct V_33 * V_39 , * V_40 ;
V_39 = F_32 ( V_34 , L_4 ) ;
if ( V_39 )
V_34 = V_39 ;
V_40 = F_27 ( V_34 , L_5 , V_36 ) ;
F_33 ( V_39 ) ;
return V_40 ;
}
static struct V_33 *
F_34 ( struct V_33 * V_40 , T_1 V_36 )
{
return F_27 ( V_40 , L_6 , V_36 ) ;
}
static struct V_33 *
F_35 ( const struct V_33 * V_41 )
{
struct V_33 * V_37 ;
unsigned int V_42 ;
V_37 = F_36 ( V_41 , L_7 , 0 ) ;
for ( V_42 = 3 ; V_42 && V_37 ; V_42 -- ) {
V_37 = F_37 ( V_37 ) ;
if ( V_42 == 2 && F_29 ( V_37 -> V_35 , L_4 ) )
break;
}
return V_37 ;
}
static struct V_33 * F_38 ( struct V_43 * V_15 )
{
struct V_33 * V_37 , * V_44 ;
V_37 = F_31 ( V_15 -> V_45 , V_46 ) ;
if ( ! V_37 )
return NULL ;
V_44 = F_34 ( V_37 , 0 ) ;
F_33 ( V_37 ) ;
if ( ! V_44 )
return NULL ;
V_37 = F_35 ( V_44 ) ;
F_33 ( V_44 ) ;
return V_37 ;
}
static int F_39 ( struct V_1 * V_9 )
{
struct V_43 * V_15 = V_9 -> V_15 ;
struct V_33 * V_47 = V_15 -> V_45 ;
struct V_33 * V_37 ;
V_9 -> V_48 = F_38 ( V_15 ) ;
V_37 = F_32 ( V_47 , L_8 ) ;
if ( V_37 ) {
struct V_49 * V_12 ;
int V_22 ;
F_33 ( V_37 ) ;
V_12 = F_40 ( V_15 , sizeof( * V_9 -> V_12 ) , V_50 ) ;
if ( ! V_12 )
return - V_51 ;
V_22 = F_41 ( V_47 , V_12 , 0 ) ;
if ( V_22 < 0 ) {
F_42 ( V_15 , V_12 ) ;
return V_22 ;
}
V_9 -> V_12 = V_12 ;
return 0 ;
}
if ( ! V_9 -> V_48 )
return - V_52 ;
return 0 ;
}
struct V_2 * F_43 ( struct V_43 * V_15 )
{
struct V_1 * V_9 ;
int V_22 ;
V_9 = F_40 ( V_15 , sizeof( * V_9 ) , V_50 ) ;
if ( ! V_9 )
return F_44 ( - V_51 ) ;
V_9 -> V_4 . type = V_53 ;
V_9 -> V_4 . V_54 = & V_55 ;
V_9 -> V_15 = V_15 ;
V_9 -> V_29 = V_32 ;
V_22 = F_45 ( V_15 ,
V_56 ,
V_9 -> V_4 . type ) ;
if ( V_22 )
return F_44 ( V_22 ) ;
V_22 = F_39 ( V_9 ) ;
if ( V_22 < 0 ) {
F_42 ( V_15 , V_9 ) ;
goto V_57;
}
if ( V_9 -> V_48 ) {
V_9 -> V_10 = F_46 ( V_9 -> V_48 ) ;
if ( ! V_9 -> V_10 ) {
F_47 ( V_15 ,
V_56 ) ;
return F_44 ( - V_58 ) ;
}
}
return & V_9 -> V_4 ;
V_57:
F_47 ( V_15 , V_56 ) ;
return NULL ;
}
int F_48 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
F_26 ( & V_9 -> V_4 , V_32 ) ;
if ( V_9 -> V_10 )
F_49 ( V_9 -> V_10 ) ;
F_47 ( V_9 -> V_15 , V_56 ) ;
return 0 ;
}
