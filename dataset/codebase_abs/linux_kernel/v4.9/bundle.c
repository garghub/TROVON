static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_9 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_10 == NULL )
return sprintf ( V_5 , L_3 ) ;
return sprintf ( V_5 , L_4 , V_7 -> V_10 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_6 ( V_7 -> V_10 ) ;
V_7 -> V_10 = F_7 ( V_5 , V_12 ) ;
if ( ! V_7 -> V_10 )
return - V_13 ;
F_8 ( & V_7 -> V_2 . V_14 , NULL , L_5 ) ;
return V_11 ;
}
static struct V_6 * F_9 ( struct V_15 * V_16 ,
T_3 V_17 )
{
struct V_6 * V_7 ;
F_10 (bundle, &intf->bundles, links) {
if ( V_7 -> V_9 == V_17 )
return V_7 ;
}
return NULL ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( V_7 ) ;
F_6 ( V_7 -> V_10 ) ;
F_6 ( V_7 -> V_18 ) ;
F_6 ( V_7 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_19 * V_20 ;
F_10 (connection, &bundle->connections, bundle_links)
F_14 ( V_20 ) ;
}
static void F_15 ( struct V_6 * V_7 )
{
struct V_19 * V_20 ;
F_10 (connection, &bundle->connections, bundle_links)
F_16 ( V_20 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
int V_24 ;
if ( V_22 && V_22 -> V_25 ) {
V_24 = V_22 -> V_25 ( & V_7 -> V_2 ) ;
if ( V_24 )
return V_24 ;
} else {
F_13 ( V_7 ) ;
}
V_24 = F_18 ( V_7 -> V_16 -> V_26 , V_7 -> V_9 ) ;
if ( V_24 ) {
if ( V_22 && V_22 -> V_27 )
V_24 = V_22 -> V_27 ( V_2 ) ;
else
F_15 ( V_7 ) ;
return V_24 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_21 * V_22 = V_2 -> V_23 -> V_22 ;
int V_24 ;
V_24 = F_20 ( V_7 -> V_16 -> V_26 , V_7 -> V_9 ) ;
if ( V_24 )
return V_24 ;
if ( V_22 && V_22 -> V_27 ) {
V_24 = V_22 -> V_27 ( V_2 ) ;
if ( V_24 )
return V_24 ;
} else {
F_15 ( V_7 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
struct V_6 * F_24 ( struct V_15 * V_16 , T_3 V_17 ,
T_3 V_8 )
{
struct V_6 * V_7 ;
if ( V_17 == V_28 ) {
F_25 ( & V_16 -> V_2 , L_6 , V_17 ) ;
return NULL ;
}
if ( F_9 ( V_16 , V_17 ) ) {
F_25 ( & V_16 -> V_2 , L_7 , V_17 ) ;
return NULL ;
}
V_7 = F_26 ( sizeof( * V_7 ) , V_12 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_16 = V_16 ;
V_7 -> V_9 = V_17 ;
V_7 -> V_8 = V_8 ;
F_27 ( & V_7 -> V_29 ) ;
V_7 -> V_2 . V_30 = & V_16 -> V_2 ;
V_7 -> V_2 . V_31 = & V_32 ;
V_7 -> V_2 . type = & V_33 ;
V_7 -> V_2 . V_34 = V_35 ;
V_7 -> V_2 . V_36 = V_16 -> V_2 . V_36 ;
F_28 ( & V_7 -> V_2 ) ;
F_29 ( & V_7 -> V_2 , L_8 , F_30 ( & V_16 -> V_2 ) , V_17 ) ;
F_31 ( & V_7 -> V_37 , & V_16 -> V_38 ) ;
F_32 ( V_7 ) ;
return V_7 ;
}
int F_33 ( struct V_6 * V_7 )
{
int V_24 ;
V_24 = F_34 ( & V_7 -> V_2 ) ;
if ( V_24 ) {
F_25 ( & V_7 -> V_2 , L_9 , V_24 ) ;
return V_24 ;
}
F_35 ( V_7 ) ;
return 0 ;
}
void F_36 ( struct V_6 * V_7 )
{
F_37 ( V_7 ) ;
if ( F_38 ( & V_7 -> V_2 ) )
F_39 ( & V_7 -> V_2 ) ;
F_40 ( & V_7 -> V_37 ) ;
F_41 ( & V_7 -> V_2 ) ;
}
