static struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 type )
{
struct V_1 * V_5 = NULL ;
F_2 (phy, list, head) {
if ( V_5 -> type != type )
continue;
return V_5 ;
}
return F_3 ( - V_6 ) ;
}
static struct V_1 * F_4 ( struct V_7 * V_8 ,
struct V_2 * V_3 , T_1 V_9 )
{
struct V_10 * V_11 = NULL ;
F_2 (phy_bind, list, list) {
if ( ! ( strcmp ( V_11 -> V_12 , V_12 ( V_8 ) ) ) &&
V_11 -> V_9 == V_9 ) {
if ( V_11 -> V_5 )
return V_11 -> V_5 ;
else
return F_3 ( - V_13 ) ;
}
}
return F_3 ( - V_6 ) ;
}
static struct V_1 * F_5 ( struct V_14 * V_15 )
{
struct V_1 * V_5 ;
F_2 (phy, &phy_list, head) {
if ( V_15 != V_5 -> V_8 -> V_16 )
continue;
return V_5 ;
}
return F_3 ( - V_6 ) ;
}
static void F_6 ( struct V_7 * V_8 , void * V_17 )
{
struct V_1 * V_5 = * (struct V_1 * * ) V_17 ;
F_7 ( V_5 ) ;
}
static int F_8 ( struct V_7 * V_8 , void * V_17 , void * V_18 )
{
return V_17 == V_18 ;
}
struct V_1 * F_9 ( struct V_7 * V_8 , enum V_4 type )
{
struct V_1 * * V_19 , * V_5 ;
V_19 = F_10 ( F_6 , sizeof( * V_19 ) , V_20 ) ;
if ( ! V_19 )
return NULL ;
V_5 = F_11 ( type ) ;
if ( ! F_12 ( V_5 ) ) {
* V_19 = V_5 ;
F_13 ( V_8 , V_19 ) ;
} else
F_14 ( V_19 ) ;
return V_5 ;
}
struct V_1 * F_11 ( enum V_4 type )
{
struct V_1 * V_5 = NULL ;
unsigned long V_21 ;
F_15 ( & V_22 , V_21 ) ;
V_5 = F_1 ( & V_23 , type ) ;
if ( F_12 ( V_5 ) || ! F_16 ( V_5 -> V_8 -> V_24 -> V_25 ) ) {
F_17 ( L_1 ,
F_18 ( type ) ) ;
goto V_26;
}
F_19 ( V_5 -> V_8 ) ;
V_26:
F_20 ( & V_22 , V_21 ) ;
return V_5 ;
}
struct V_1 * F_21 ( struct V_7 * V_8 ,
const char * V_27 , T_1 V_9 )
{
struct V_1 * V_5 = F_3 ( - V_28 ) , * * V_19 ;
unsigned long V_21 ;
struct V_14 * V_15 ;
if ( ! V_8 -> V_16 ) {
F_22 ( V_8 , L_2 ) ;
return F_3 ( - V_29 ) ;
}
V_15 = F_23 ( V_8 -> V_16 , V_27 , V_9 ) ;
if ( ! V_15 ) {
F_22 ( V_8 , L_3 , V_27 ,
V_8 -> V_16 -> V_30 ) ;
return F_3 ( - V_6 ) ;
}
V_19 = F_10 ( F_6 , sizeof( * V_19 ) , V_20 ) ;
if ( ! V_19 ) {
F_22 ( V_8 , L_4 ) ;
goto V_26;
}
F_15 ( & V_22 , V_21 ) ;
V_5 = F_5 ( V_15 ) ;
if ( F_12 ( V_5 ) || ! F_16 ( V_5 -> V_8 -> V_24 -> V_25 ) ) {
V_5 = F_3 ( - V_13 ) ;
F_14 ( V_19 ) ;
goto V_31;
}
* V_19 = V_5 ;
F_13 ( V_8 , V_19 ) ;
F_19 ( V_5 -> V_8 ) ;
V_31:
F_20 ( & V_22 , V_21 ) ;
V_26:
F_24 ( V_15 ) ;
return V_5 ;
}
struct V_1 * F_25 ( struct V_7 * V_8 , T_1 V_9 )
{
struct V_1 * V_5 = NULL ;
unsigned long V_21 ;
F_15 ( & V_22 , V_21 ) ;
V_5 = F_4 ( V_8 , & V_32 , V_9 ) ;
if ( F_12 ( V_5 ) || ! F_16 ( V_5 -> V_8 -> V_24 -> V_25 ) ) {
F_17 ( L_5 ) ;
goto V_26;
}
F_19 ( V_5 -> V_8 ) ;
V_26:
F_20 ( & V_22 , V_21 ) ;
return V_5 ;
}
struct V_1 * F_26 ( struct V_7 * V_8 , T_1 V_9 )
{
struct V_1 * * V_19 , * V_5 ;
V_19 = F_10 ( F_6 , sizeof( * V_19 ) , V_20 ) ;
if ( ! V_19 )
return NULL ;
V_5 = F_25 ( V_8 , V_9 ) ;
if ( ! F_12 ( V_5 ) ) {
* V_19 = V_5 ;
F_13 ( V_8 , V_19 ) ;
} else
F_14 ( V_19 ) ;
return V_5 ;
}
void F_27 ( struct V_7 * V_8 , struct V_1 * V_5 )
{
int V_33 ;
V_33 = F_28 ( V_8 , F_6 , F_8 , V_5 ) ;
F_29 ( V_8 , V_33 , L_6 ) ;
}
void F_7 ( struct V_1 * V_34 )
{
if ( V_34 ) {
struct V_35 * V_25 = V_34 -> V_8 -> V_24 -> V_25 ;
F_30 ( V_34 -> V_8 ) ;
F_31 ( V_25 ) ;
}
}
int F_32 ( struct V_1 * V_34 , enum V_4 type )
{
int V_36 = 0 ;
unsigned long V_21 ;
struct V_1 * V_5 ;
if ( V_34 -> type != V_37 ) {
F_33 ( V_34 -> V_8 , L_7 , V_34 -> V_38 ) ;
return - V_29 ;
}
F_15 ( & V_22 , V_21 ) ;
F_2 (phy, &phy_list, head) {
if ( V_5 -> type == type ) {
V_36 = - V_39 ;
F_33 ( V_34 -> V_8 , L_8 ,
F_18 ( type ) ) ;
goto V_40;
}
}
V_34 -> type = type ;
F_34 ( & V_34 -> V_41 , & V_23 ) ;
V_40:
F_20 ( & V_22 , V_21 ) ;
return V_36 ;
}
int F_35 ( struct V_1 * V_34 )
{
struct V_10 * V_11 ;
unsigned long V_21 ;
if ( ! V_34 -> V_8 ) {
F_33 ( V_34 -> V_8 , L_9 ) ;
return - V_29 ;
}
F_15 ( & V_22 , V_21 ) ;
F_2 (phy_bind, &phy_bind_list, list)
if ( ! ( strcmp ( V_11 -> V_42 , V_12 ( V_34 -> V_8 ) ) ) )
V_11 -> V_5 = V_34 ;
F_34 ( & V_34 -> V_41 , & V_23 ) ;
F_20 ( & V_22 , V_21 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_34 )
{
unsigned long V_21 ;
struct V_10 * V_11 ;
F_15 ( & V_22 , V_21 ) ;
if ( V_34 ) {
F_2 (phy_bind, &phy_bind_list, list)
if ( V_11 -> V_5 == V_34 )
V_11 -> V_5 = NULL ;
F_37 ( & V_34 -> V_41 ) ;
}
F_20 ( & V_22 , V_21 ) ;
}
int T_2 F_38 ( const char * V_12 , T_1 V_9 ,
const char * V_42 )
{
struct V_10 * V_11 ;
unsigned long V_21 ;
V_11 = F_39 ( sizeof( * V_11 ) , V_20 ) ;
if ( ! V_11 ) {
F_17 ( L_10 ) ;
return - V_28 ;
}
V_11 -> V_12 = V_12 ;
V_11 -> V_42 = V_42 ;
V_11 -> V_9 = V_9 ;
F_15 ( & V_22 , V_21 ) ;
F_34 ( & V_11 -> V_3 , & V_32 ) ;
F_20 ( & V_22 , V_21 ) ;
return 0 ;
}
const char * F_40 ( enum V_43 V_44 )
{
switch ( V_44 ) {
case V_45 :
return L_11 ;
case V_46 :
return L_12 ;
case V_47 :
return L_13 ;
case V_48 :
return L_14 ;
case V_49 :
return L_15 ;
case V_50 :
return L_16 ;
case V_51 :
return L_17 ;
case V_52 :
return L_18 ;
case V_53 :
return L_19 ;
case V_54 :
return L_20 ;
case V_55 :
return L_21 ;
case V_56 :
return L_22 ;
case V_57 :
return L_23 ;
default:
return L_24 ;
}
}
