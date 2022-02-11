static enum V_1
F_1 ( struct V_2 * V_3 , bool V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_6 -> V_7 && ! V_6 -> V_7 -> V_3 )
F_3 ( V_6 -> V_7 , & V_6 -> V_3 ) ;
return V_8 ;
}
static void F_4 ( struct V_2 * V_3 )
{
F_5 ( V_3 ) ;
F_6 ( V_3 ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_6 -> V_9 ) {
struct V_10 * V_11 ;
V_11 = F_8 ( V_3 -> V_12 ) ;
if ( ! V_11 ) {
F_9 ( L_1 ) ;
return 0 ;
}
F_10 ( V_6 -> V_9 , V_11 ) ;
V_11 -> type = V_13 | V_14 ;
F_11 ( V_3 , V_11 ) ;
return 1 ;
}
if ( V_6 -> V_7 )
return V_6 -> V_7 -> V_15 -> V_16 ( V_6 -> V_7 ) ;
return 0 ;
}
static struct V_17 *
F_12 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
return V_6 -> V_18 ;
}
static int F_13 ( struct V_19 * V_20 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = V_20 -> V_6 ;
struct V_2 * V_3 = & V_6 -> V_3 ;
int V_21 ;
V_6 -> V_18 = V_18 ;
V_3 -> V_22 = V_23 ;
V_21 = F_14 ( V_18 -> V_12 , V_3 ,
& V_24 ,
V_25 ) ;
if ( V_21 ) {
F_9 ( L_2 ) ;
return V_21 ;
}
F_15 ( V_3 , & V_26 ) ;
F_16 ( V_3 ) ;
F_17 ( V_3 , V_18 ) ;
return 0 ;
}
static void F_18 ( struct V_5 * V_6 )
{
if ( V_6 -> V_7 ) {
F_19 ( V_6 -> V_7 ) ;
F_20 ( V_6 -> V_7 ) ;
}
}
static void F_21 ( struct V_5 * V_6 )
{
if ( V_6 -> V_7 ) {
F_22 ( V_6 -> V_7 ) ;
F_23 ( V_6 -> V_7 ) ;
}
}
static void F_24 ( struct V_19 * V_20 , int V_11 )
{
struct V_5 * V_6 = V_20 -> V_6 ;
switch ( V_11 ) {
case V_27 :
if ( V_6 -> V_28 != V_27 )
F_18 ( V_6 ) ;
break;
case V_29 :
case V_30 :
case V_31 :
if ( V_6 -> V_28 == V_27 )
F_21 ( V_6 ) ;
break;
default:
break;
}
V_6 -> V_28 = V_11 ;
}
static struct V_32 *
F_25 ( struct V_32 * V_33 , const char * V_34 , T_1 V_35 )
{
struct V_32 * V_36 ;
F_26 (parent, np) {
T_1 V_37 ;
if ( ! V_36 -> V_34 || F_27 ( V_36 -> V_34 , V_34 ) )
continue;
if ( F_28 ( V_36 , L_3 , & V_37 ) < 0 )
V_37 = 0 ;
if ( V_35 == V_37 )
break;
}
return V_36 ;
}
static struct V_32 * F_29 ( struct V_32 * V_33 ,
T_1 V_35 )
{
struct V_32 * V_38 , * V_39 ;
V_38 = F_30 ( V_33 , L_4 ) ;
if ( V_38 )
V_33 = V_38 ;
V_39 = F_25 ( V_33 , L_5 , V_35 ) ;
F_31 ( V_38 ) ;
return V_39 ;
}
static struct V_32 *
F_32 ( struct V_32 * V_39 , T_1 V_35 )
{
return F_25 ( V_39 , L_6 , V_35 ) ;
}
static struct V_32 *
F_33 ( const struct V_32 * V_40 )
{
struct V_32 * V_36 ;
unsigned int V_41 ;
V_36 = F_34 ( V_40 , L_7 , 0 ) ;
for ( V_41 = 3 ; V_41 && V_36 ; V_41 -- ) {
V_36 = F_35 ( V_36 ) ;
if ( V_41 == 2 && F_27 ( V_36 -> V_34 , L_4 ) )
break;
}
return V_36 ;
}
static struct V_32 * F_36 ( struct V_42 * V_12 )
{
struct V_32 * V_36 , * V_43 ;
V_36 = F_29 ( V_12 -> V_44 , V_45 ) ;
if ( ! V_36 )
return NULL ;
V_43 = F_32 ( V_36 , 0 ) ;
F_31 ( V_36 ) ;
if ( ! V_43 )
return NULL ;
V_36 = F_33 ( V_43 ) ;
F_31 ( V_43 ) ;
return V_36 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_42 * V_12 = V_6 -> V_12 ;
struct V_32 * V_46 = V_12 -> V_44 ;
struct V_32 * V_36 ;
V_6 -> V_47 = F_36 ( V_12 ) ;
V_36 = F_30 ( V_46 , L_8 ) ;
if ( V_36 ) {
struct V_48 * V_9 ;
int V_21 ;
F_31 ( V_36 ) ;
V_9 = F_38 ( V_12 , sizeof( * V_6 -> V_9 ) , V_49 ) ;
if ( ! V_9 )
return - V_50 ;
V_21 = F_39 ( V_46 , V_9 , 0 ) ;
if ( V_21 < 0 ) {
F_40 ( V_12 , V_9 ) ;
return V_21 ;
}
V_6 -> V_9 = V_9 ;
return 0 ;
}
if ( ! V_6 -> V_47 )
return - V_51 ;
return 0 ;
}
struct V_19 * F_41 ( struct V_42 * V_12 )
{
struct V_5 * V_6 ;
int V_21 ;
V_21 = F_42 ( V_12 ,
V_52 ,
V_53 . type ) ;
if ( V_21 )
return F_43 ( V_21 ) ;
V_6 = F_38 ( V_12 , sizeof( * V_6 ) , V_49 ) ;
if ( ! V_6 )
goto V_54;
V_6 -> V_12 = V_12 ;
V_53 . V_6 = V_6 ;
V_6 -> V_28 = V_31 ;
V_21 = F_37 ( V_6 ) ;
if ( V_21 < 0 ) {
F_40 ( V_12 , V_6 ) ;
goto V_54;
}
if ( V_6 -> V_47 ) {
V_6 -> V_7 = F_44 ( V_6 -> V_47 ) ;
if ( ! V_6 -> V_7 ) {
F_45 ( V_12 ,
V_52 ) ;
return F_43 ( - V_55 ) ;
}
}
return & V_53 ;
V_54:
F_45 ( V_12 , V_52 ) ;
return NULL ;
}
int F_46 ( struct V_42 * V_12 )
{
struct V_5 * V_6 = V_53 . V_6 ;
F_24 ( & V_53 , V_31 ) ;
if ( V_6 -> V_7 )
F_47 ( V_6 -> V_7 ) ;
F_45 ( V_12 , V_52 ) ;
return 0 ;
}
