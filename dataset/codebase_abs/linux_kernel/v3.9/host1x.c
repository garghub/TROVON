static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return - V_7 ;
F_3 ( & V_5 -> V_8 ) ;
V_5 -> V_3 = F_4 ( V_3 ) ;
F_5 ( & V_5 -> V_8 , & V_1 -> V_9 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 ,
struct V_4 * V_10 ,
struct V_11 * V_5 )
{
F_7 ( & V_1 -> V_12 ) ;
F_8 ( & V_10 -> V_8 ) ;
F_5 ( & V_10 -> V_8 , & V_1 -> V_13 ) ;
V_10 -> V_5 = V_5 ;
F_9 ( & V_1 -> V_12 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 ,
struct V_4 * V_5 )
{
F_7 ( & V_1 -> V_12 ) ;
F_8 ( & V_5 -> V_8 ) ;
F_9 ( & V_1 -> V_12 ) ;
F_11 ( V_5 -> V_3 ) ;
F_12 ( V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 )
{
static const char * const V_14 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
} ;
unsigned int V_15 ;
int V_16 ;
for ( V_15 = 0 ; V_15 < F_14 ( V_14 ) ; V_15 ++ ) {
struct V_2 * V_3 ;
F_15 (host1x->dev->of_node, np) {
if ( F_16 ( V_3 , V_14 [ V_15 ] ) &&
F_17 ( V_3 ) ) {
V_16 = F_1 ( V_1 , V_3 ) ;
if ( V_16 < 0 )
return V_16 ;
}
}
}
return 0 ;
}
static int F_18 ( struct V_17 * V_18 )
{
struct V_1 * V_1 ;
struct V_19 * V_20 ;
int V_16 ;
V_1 = F_19 ( & V_18 -> V_21 , sizeof( * V_1 ) , V_6 ) ;
if ( ! V_1 )
return - V_7 ;
F_20 ( & V_1 -> V_12 ) ;
F_3 ( & V_1 -> V_9 ) ;
F_3 ( & V_1 -> V_13 ) ;
F_20 ( & V_1 -> V_22 ) ;
F_3 ( & V_1 -> V_23 ) ;
V_1 -> V_21 = & V_18 -> V_21 ;
V_16 = F_13 ( V_1 ) ;
if ( V_16 < 0 ) {
F_21 ( & V_18 -> V_21 , L_5 , V_16 ) ;
return V_16 ;
}
V_1 -> V_24 = F_22 ( & V_18 -> V_21 , NULL ) ;
if ( F_23 ( V_1 -> V_24 ) )
return F_24 ( V_1 -> V_24 ) ;
V_16 = F_25 ( V_1 -> V_24 ) ;
if ( V_16 < 0 )
return V_16 ;
V_20 = F_26 ( V_18 , V_25 , 0 ) ;
if ( ! V_20 ) {
V_16 = - V_26 ;
goto V_16;
}
V_16 = F_27 ( V_18 , 0 ) ;
if ( V_16 < 0 )
goto V_16;
V_1 -> V_27 = V_16 ;
V_16 = F_27 ( V_18 , 1 ) ;
if ( V_16 < 0 )
goto V_16;
V_1 -> V_28 = V_16 ;
V_1 -> V_20 = F_28 ( & V_18 -> V_21 , V_20 ) ;
if ( F_23 ( V_1 -> V_20 ) ) {
V_16 = F_24 ( V_1 -> V_20 ) ;
goto V_16;
}
F_29 ( V_18 , V_1 ) ;
return 0 ;
V_16:
F_30 ( V_1 -> V_24 ) ;
return V_16 ;
}
static int F_31 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_32 ( V_18 ) ;
F_30 ( V_1 -> V_24 ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_1 , struct V_29 * V_10 )
{
struct V_11 * V_5 ;
F_7 ( & V_1 -> V_22 ) ;
F_34 (client, &host1x->clients, list) {
if ( V_5 -> V_30 && V_5 -> V_30 -> V_31 ) {
int V_16 = V_5 -> V_30 -> V_31 ( V_5 , V_10 ) ;
if ( V_16 < 0 ) {
F_21 ( V_1 -> V_21 ,
L_6 ,
F_35 ( V_5 -> V_21 ) , V_16 ) ;
return V_16 ;
}
}
}
F_9 ( & V_1 -> V_22 ) ;
return 0 ;
}
int F_36 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = F_37 ( V_1 -> V_21 ) ;
struct V_11 * V_5 ;
if ( ! V_1 -> V_10 )
return 0 ;
F_7 ( & V_1 -> V_22 ) ;
F_38 (client, &host1x->clients, list) {
if ( V_5 -> V_30 && V_5 -> V_30 -> V_32 ) {
int V_16 = V_5 -> V_30 -> V_32 ( V_5 ) ;
if ( V_16 < 0 ) {
F_21 ( V_1 -> V_21 ,
L_7 ,
F_35 ( V_5 -> V_21 ) , V_16 ) ;
return V_16 ;
}
}
}
F_9 ( & V_1 -> V_22 ) ;
F_39 ( & V_33 , V_18 ) ;
V_1 -> V_10 = NULL ;
return 0 ;
}
int F_40 ( struct V_1 * V_1 , struct V_11 * V_5 )
{
struct V_4 * V_10 , * V_34 ;
int V_16 ;
F_7 ( & V_1 -> V_22 ) ;
F_5 ( & V_5 -> V_8 , & V_1 -> V_23 ) ;
F_9 ( & V_1 -> V_22 ) ;
F_41 (drm, tmp, &host1x->drm_clients, list)
if ( V_10 -> V_3 == V_5 -> V_21 -> V_35 )
F_6 ( V_1 , V_10 , V_5 ) ;
if ( F_42 ( & V_1 -> V_9 ) ) {
struct V_17 * V_18 = F_37 ( V_1 -> V_21 ) ;
V_16 = F_43 ( & V_33 , V_18 ) ;
if ( V_16 < 0 ) {
F_21 ( V_1 -> V_21 , L_8 , V_16 ) ;
return V_16 ;
}
}
V_5 -> V_1 = V_1 ;
return 0 ;
}
int F_44 ( struct V_1 * V_1 ,
struct V_11 * V_5 )
{
struct V_4 * V_10 , * V_34 ;
int V_16 ;
F_41 (drm, tmp, &host1x->drm_active, list) {
if ( V_10 -> V_5 == V_5 ) {
V_16 = F_36 ( V_1 ) ;
if ( V_16 < 0 ) {
F_21 ( V_1 -> V_21 , L_9 ,
V_16 ) ;
return V_16 ;
}
F_10 ( V_1 , V_10 ) ;
break;
}
}
F_7 ( & V_1 -> V_22 ) ;
F_8 ( & V_5 -> V_8 ) ;
F_9 ( & V_1 -> V_22 ) ;
return 0 ;
}
static int T_1 F_45 ( void )
{
int V_16 ;
V_16 = F_46 ( & V_36 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_46 ( & V_37 ) ;
if ( V_16 < 0 )
goto V_38;
V_16 = F_46 ( & V_39 ) ;
if ( V_16 < 0 )
goto V_40;
return 0 ;
V_40:
F_47 ( & V_37 ) ;
V_38:
F_47 ( & V_36 ) ;
return V_16 ;
}
static void T_2 F_48 ( void )
{
F_47 ( & V_39 ) ;
F_47 ( & V_37 ) ;
F_47 ( & V_36 ) ;
}
