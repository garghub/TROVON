static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 ,
unsigned int V_5 ,
unsigned int V_6 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 ;
struct V_1 * V_12 = NULL ;
unsigned long V_13 ;
F_2 ( & V_8 -> V_14 , V_13 ) ;
F_3 (dev_entry, &dev_data->dev_list, list) {
if ( V_4 == ( unsigned int ) F_4 ( V_11 -> V_12 -> V_5 )
&& V_5 == ( unsigned int ) V_11 -> V_12 -> V_5 -> V_15
&& V_6 == V_11 -> V_12 -> V_6 ) {
V_12 = V_11 -> V_12 ;
break;
}
}
F_5 ( & V_8 -> V_14 , V_13 ) ;
return V_12 ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_1 * V_12 ,
int V_16 , T_1 V_17 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 ;
unsigned long V_13 ;
unsigned int V_4 , V_5 , V_6 ;
int V_18 ;
V_11 = F_7 ( sizeof( * V_11 ) , V_19 ) ;
if ( ! V_11 )
return - V_20 ;
V_11 -> V_12 = V_12 ;
F_2 ( & V_8 -> V_14 , V_13 ) ;
F_8 ( & V_11 -> V_21 , & V_8 -> V_22 ) ;
F_5 ( & V_8 -> V_14 , V_13 ) ;
V_4 = ( unsigned int ) F_4 ( V_12 -> V_5 ) ;
V_5 = ( unsigned int ) V_12 -> V_5 -> V_15 ;
V_6 = V_12 -> V_6 ;
V_18 = V_17 ( V_3 , V_4 , V_5 , V_6 , V_16 ) ;
return V_18 ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_1 * V_12 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 , * V_23 ;
struct V_1 * V_24 = NULL ;
unsigned long V_13 ;
F_2 ( & V_8 -> V_14 , V_13 ) ;
F_10 (dev_entry, t, &dev_data->dev_list, list) {
if ( V_11 -> V_12 == V_12 ) {
F_11 ( & V_11 -> V_21 ) ;
V_24 = V_11 -> V_12 ;
F_12 ( V_11 ) ;
}
}
F_5 ( & V_8 -> V_14 , V_13 ) ;
if ( V_24 )
F_13 ( V_24 ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
V_8 = F_7 ( sizeof( * V_8 ) , V_19 ) ;
if ( ! V_8 )
return - V_20 ;
F_15 ( & V_8 -> V_14 ) ;
F_16 ( & V_8 -> V_22 ) ;
V_3 -> V_9 = V_8 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
T_2 V_25 )
{
int V_18 = 0 ;
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 , * V_26 , * V_27 ;
struct V_1 * V_12 ;
int V_28 ;
unsigned int V_4 , V_5 ;
F_18 ( & V_8 -> V_14 ) ;
F_10 (dev_entry, tmp, &dev_data->dev_list, list) {
V_28 = 0 ;
V_12 = V_11 -> V_12 -> V_5 -> V_29 ;
for (; ! V_28 && V_12 != NULL ; V_12 = V_12 -> V_5 -> V_29 ) {
F_3 (e, &dev_data->dev_list, list) {
if ( V_12 == V_26 -> V_12 ) {
V_28 = 1 ;
break;
}
}
}
V_4 = ( unsigned int ) F_4 ( V_11 -> V_12 -> V_5 ) ;
V_5 = ( unsigned int ) V_11 -> V_12 -> V_5 -> V_15 ;
if ( ! V_28 ) {
F_19 ( & V_8 -> V_14 ) ;
V_18 = V_25 ( V_3 , V_4 , V_5 ) ;
if ( V_18 )
break;
F_18 ( & V_8 -> V_14 ) ;
}
}
if ( ! V_18 )
F_19 ( & V_8 -> V_14 ) ;
return V_18 ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 , * V_23 ;
F_10 (dev_entry, t, &dev_data->dev_list, list) {
F_11 ( & V_11 -> V_21 ) ;
F_13 ( V_11 -> V_12 ) ;
F_12 ( V_11 ) ;
}
F_12 ( V_8 ) ;
V_3 -> V_9 = NULL ;
}
static int F_21 ( struct V_1 * V_30 ,
struct V_2 * V_3 ,
unsigned int * V_4 , unsigned int * V_5 ,
unsigned int * V_6 )
{
* V_4 = F_4 ( V_30 -> V_5 ) ;
* V_5 = V_30 -> V_5 -> V_15 ;
* V_6 = V_30 -> V_6 ;
return 1 ;
}
