static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 ,
unsigned int V_5 ,
unsigned int V_6 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 ;
struct V_1 * V_12 = NULL ;
F_2 ( & V_8 -> V_13 ) ;
F_3 (dev_entry, &dev_data->dev_list, list) {
if ( V_4 == ( unsigned int ) F_4 ( V_11 -> V_12 -> V_5 )
&& V_5 == ( unsigned int ) V_11 -> V_12 -> V_5 -> V_14
&& V_6 == V_11 -> V_12 -> V_6 ) {
V_12 = V_11 -> V_12 ;
break;
}
}
F_5 ( & V_8 -> V_13 ) ;
return V_12 ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_1 * V_12 ,
int V_15 , T_1 V_16 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 ;
unsigned int V_4 , V_5 , V_6 ;
int V_17 ;
V_11 = F_7 ( sizeof( * V_11 ) , V_18 ) ;
if ( ! V_11 )
return - V_19 ;
V_11 -> V_12 = V_12 ;
F_2 ( & V_8 -> V_13 ) ;
F_8 ( & V_11 -> V_20 , & V_8 -> V_21 ) ;
F_5 ( & V_8 -> V_13 ) ;
V_4 = ( unsigned int ) F_4 ( V_12 -> V_5 ) ;
V_5 = ( unsigned int ) V_12 -> V_5 -> V_14 ;
V_6 = V_12 -> V_6 ;
V_17 = V_16 ( V_3 , V_4 , V_5 , V_6 , V_15 ) ;
return V_17 ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_1 * V_12 , bool V_13 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 , * V_22 ;
struct V_1 * V_23 = NULL ;
F_2 ( & V_8 -> V_13 ) ;
F_10 (dev_entry, t, &dev_data->dev_list, list) {
if ( V_11 -> V_12 == V_12 ) {
F_11 ( & V_11 -> V_20 ) ;
V_23 = V_11 -> V_12 ;
F_12 ( V_11 ) ;
}
}
F_5 ( & V_8 -> V_13 ) ;
if ( V_23 ) {
if ( V_13 )
F_13 ( & V_23 -> V_12 ) ;
F_14 ( V_23 ) ;
if ( V_13 )
F_15 ( & V_23 -> V_12 ) ;
}
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
V_8 = F_7 ( sizeof( * V_8 ) , V_18 ) ;
if ( ! V_8 )
return - V_19 ;
F_17 ( & V_8 -> V_13 ) ;
F_18 ( & V_8 -> V_21 ) ;
V_3 -> V_9 = V_8 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 ,
T_2 V_24 )
{
int V_17 = 0 ;
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 , * V_25 ;
struct V_1 * V_12 ;
int V_26 ;
unsigned int V_4 , V_5 ;
F_2 ( & V_8 -> V_13 ) ;
F_3 (dev_entry, &dev_data->dev_list, list) {
V_26 = 0 ;
V_12 = V_11 -> V_12 -> V_5 -> V_27 ;
for (; ! V_26 && V_12 != NULL ; V_12 = V_12 -> V_5 -> V_27 ) {
F_3 (e, &dev_data->dev_list, list) {
if ( V_12 == V_25 -> V_12 ) {
V_26 = 1 ;
break;
}
}
}
V_4 = ( unsigned int ) F_4 ( V_11 -> V_12 -> V_5 ) ;
V_5 = ( unsigned int ) V_11 -> V_12 -> V_5 -> V_14 ;
if ( ! V_26 ) {
V_17 = V_24 ( V_3 , V_4 , V_5 ) ;
if ( V_17 )
break;
}
}
F_5 ( & V_8 -> V_13 ) ;
return V_17 ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 , * V_22 ;
F_10 (dev_entry, t, &dev_data->dev_list, list) {
struct V_1 * V_12 = V_11 -> V_12 ;
F_11 ( & V_11 -> V_20 ) ;
F_13 ( & V_12 -> V_12 ) ;
F_14 ( V_12 ) ;
F_15 ( & V_12 -> V_12 ) ;
F_12 ( V_11 ) ;
}
F_12 ( V_8 ) ;
V_3 -> V_9 = NULL ;
}
static int F_21 ( struct V_1 * V_28 ,
struct V_2 * V_3 ,
unsigned int * V_4 , unsigned int * V_5 ,
unsigned int * V_6 )
{
* V_4 = F_4 ( V_28 -> V_5 ) ;
* V_5 = V_28 -> V_5 -> V_14 ;
* V_6 = V_28 -> V_6 ;
return 1 ;
}
