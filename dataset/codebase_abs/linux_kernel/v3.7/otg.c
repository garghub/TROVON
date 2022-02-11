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
static void F_4 ( struct V_7 * V_8 , void * V_9 )
{
struct V_1 * V_5 = * (struct V_1 * * ) V_9 ;
F_5 ( V_5 ) ;
}
static int F_6 ( struct V_7 * V_8 , void * V_9 , void * V_10 )
{
return V_9 == V_10 ;
}
struct V_1 * F_7 ( struct V_7 * V_8 , enum V_4 type )
{
struct V_1 * * V_11 , * V_5 ;
V_11 = F_8 ( F_4 , sizeof( * V_11 ) , V_12 ) ;
if ( ! V_11 )
return NULL ;
V_5 = F_9 ( type ) ;
if ( ! F_10 ( V_5 ) ) {
* V_11 = V_5 ;
F_11 ( V_8 , V_11 ) ;
} else
F_12 ( V_11 ) ;
return V_5 ;
}
struct V_1 * F_9 ( enum V_4 type )
{
struct V_1 * V_5 = NULL ;
unsigned long V_13 ;
F_13 ( & V_14 , V_13 ) ;
V_5 = F_1 ( & V_15 , type ) ;
if ( F_10 ( V_5 ) ) {
F_14 ( L_1 ,
F_15 ( type ) ) ;
goto V_16;
}
F_16 ( V_5 -> V_8 ) ;
V_16:
F_17 ( & V_14 , V_13 ) ;
return V_5 ;
}
void F_18 ( struct V_7 * V_8 , struct V_1 * V_5 )
{
int V_17 ;
V_17 = F_19 ( V_8 , F_4 , F_6 , V_5 ) ;
F_20 ( V_8 , V_17 , L_2 ) ;
}
void F_5 ( struct V_1 * V_18 )
{
if ( V_18 )
F_21 ( V_18 -> V_8 ) ;
}
int F_22 ( struct V_1 * V_18 , enum V_4 type )
{
int V_19 = 0 ;
unsigned long V_13 ;
struct V_1 * V_5 ;
if ( V_18 -> type != V_20 ) {
F_23 ( V_18 -> V_8 , L_3 , V_18 -> V_21 ) ;
return - V_22 ;
}
F_13 ( & V_14 , V_13 ) ;
F_2 (phy, &phy_list, head) {
if ( V_5 -> type == type ) {
V_19 = - V_23 ;
F_23 ( V_18 -> V_8 , L_4 ,
F_15 ( type ) ) ;
goto V_24;
}
}
V_18 -> type = type ;
F_24 ( & V_18 -> V_25 , & V_15 ) ;
V_24:
F_17 ( & V_14 , V_13 ) ;
return V_19 ;
}
void F_25 ( struct V_1 * V_18 )
{
unsigned long V_13 ;
F_13 ( & V_14 , V_13 ) ;
if ( V_18 )
F_26 ( & V_18 -> V_25 ) ;
F_17 ( & V_14 , V_13 ) ;
}
const char * F_27 ( enum V_26 V_27 )
{
switch ( V_27 ) {
case V_28 :
return L_5 ;
case V_29 :
return L_6 ;
case V_30 :
return L_7 ;
case V_31 :
return L_8 ;
case V_32 :
return L_9 ;
case V_33 :
return L_10 ;
case V_34 :
return L_11 ;
case V_35 :
return L_12 ;
case V_36 :
return L_13 ;
case V_37 :
return L_14 ;
case V_38 :
return L_15 ;
case V_39 :
return L_16 ;
case V_40 :
return L_17 ;
default:
return L_18 ;
}
}
