T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 ;
int V_11 = V_6 ;
F_3 ( & V_8 -> V_12 ) ;
if ( F_4 ( V_8 ) ) {
V_11 = - V_13 ;
goto V_14;
}
if ( F_5 ( V_5 , L_1 ) ) {
F_6 ( V_8 ) ;
goto V_14;
}
F_7 ( & V_15 ) ;
F_8 (trig, &trigger_list, next_trig) {
if ( F_5 ( V_5 , V_10 -> V_16 ) ) {
F_9 ( & V_8 -> V_17 ) ;
F_10 ( V_8 , V_10 ) ;
F_11 ( & V_8 -> V_17 ) ;
F_12 ( & V_15 ) ;
goto V_14;
}
}
V_11 = - V_18 ;
F_12 ( & V_15 ) ;
V_14:
F_13 ( & V_8 -> V_12 ) ;
return V_11 ;
}
T_1 F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 ;
int V_19 = 0 ;
F_7 ( & V_15 ) ;
F_7 ( & V_8 -> V_17 ) ;
if ( ! V_8 -> V_20 )
V_19 += sprintf ( V_5 + V_19 , L_2 ) ;
else
V_19 += sprintf ( V_5 + V_19 , L_3 ) ;
F_8 (trig, &trigger_list, next_trig) {
if ( V_8 -> V_20 && ! strcmp ( V_8 -> V_20 -> V_16 ,
V_10 -> V_16 ) )
V_19 += sprintf ( V_5 + V_19 , L_4 , V_10 -> V_16 ) ;
else
V_19 += sprintf ( V_5 + V_19 , L_5 , V_10 -> V_16 ) ;
}
F_12 ( & V_8 -> V_17 ) ;
F_12 ( & V_15 ) ;
V_19 += sprintf ( V_19 + V_5 , L_6 ) ;
return V_19 ;
}
void F_10 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
unsigned long V_21 ;
char * V_22 = NULL ;
char * V_23 [ 2 ] ;
const char * V_16 ;
V_16 = V_10 ? V_10 -> V_16 : L_1 ;
V_22 = F_15 ( V_24 , L_7 , V_16 ) ;
if ( V_8 -> V_20 ) {
F_16 ( & V_8 -> V_20 -> V_25 , V_21 ) ;
F_17 ( & V_8 -> V_26 ) ;
F_18 ( & V_8 -> V_20 -> V_25 ,
V_21 ) ;
F_19 ( & V_8 -> V_27 ) ;
F_20 ( V_8 ) ;
if ( V_8 -> V_20 -> V_28 )
V_8 -> V_20 -> V_28 ( V_8 ) ;
V_8 -> V_20 = NULL ;
F_21 ( V_8 , V_29 ) ;
}
if ( V_10 ) {
F_16 ( & V_10 -> V_25 , V_21 ) ;
F_22 ( & V_8 -> V_26 , & V_10 -> V_30 ) ;
F_18 ( & V_10 -> V_25 , V_21 ) ;
V_8 -> V_20 = V_10 ;
if ( V_10 -> V_31 )
V_10 -> V_31 ( V_8 ) ;
}
if ( V_22 ) {
V_23 [ 0 ] = V_22 ;
V_23 [ 1 ] = NULL ;
F_23 ( & V_8 -> V_2 -> V_32 , V_33 , V_23 ) ;
F_24 ( V_22 ) ;
}
}
void F_6 ( struct V_7 * V_8 )
{
F_9 ( & V_8 -> V_17 ) ;
F_10 ( V_8 , NULL ) ;
F_11 ( & V_8 -> V_17 ) ;
}
void F_25 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
if ( ! V_8 -> V_34 )
return;
F_7 ( & V_15 ) ;
F_9 ( & V_8 -> V_17 ) ;
F_8 (trig, &trigger_list, next_trig) {
if ( ! strcmp ( V_8 -> V_34 , V_10 -> V_16 ) )
F_10 ( V_8 , V_10 ) ;
}
F_11 ( & V_8 -> V_17 ) ;
F_12 ( & V_15 ) ;
}
void F_26 ( const char * V_16 , struct V_9 * V_10 )
{
F_27 ( V_16 == V_10 -> V_16 ) ;
F_9 ( & V_15 ) ;
strcpy ( ( char * ) V_10 -> V_16 , V_16 ) ;
F_11 ( & V_15 ) ;
}
int F_28 ( struct V_9 * V_10 )
{
struct V_7 * V_8 ;
struct V_9 * V_35 ;
F_29 ( & V_10 -> V_25 ) ;
F_30 ( & V_10 -> V_30 ) ;
F_9 ( & V_15 ) ;
F_8 (_trig, &trigger_list, next_trig) {
if ( ! strcmp ( V_35 -> V_16 , V_10 -> V_16 ) ) {
F_11 ( & V_15 ) ;
return - V_36 ;
}
}
F_22 ( & V_10 -> V_37 , & V_38 ) ;
F_11 ( & V_15 ) ;
F_7 ( & V_39 ) ;
F_8 (led_cdev, &leds_list, node) {
F_9 ( & V_8 -> V_17 ) ;
if ( ! V_8 -> V_20 && V_8 -> V_34 &&
! strcmp ( V_8 -> V_34 , V_10 -> V_16 ) )
F_10 ( V_8 , V_10 ) ;
F_11 ( & V_8 -> V_17 ) ;
}
F_12 ( & V_39 ) ;
return 0 ;
}
void F_31 ( struct V_9 * V_10 )
{
struct V_7 * V_8 ;
if ( F_32 ( & V_10 -> V_37 ) )
return;
F_9 ( & V_15 ) ;
F_33 ( & V_10 -> V_37 ) ;
F_11 ( & V_15 ) ;
F_7 ( & V_39 ) ;
F_8 (led_cdev, &leds_list, node) {
F_9 ( & V_8 -> V_17 ) ;
if ( V_8 -> V_20 == V_10 )
F_10 ( V_8 , NULL ) ;
F_11 ( & V_8 -> V_17 ) ;
}
F_12 ( & V_39 ) ;
}
static void F_34 ( struct V_1 * V_2 , void * V_40 )
{
F_31 ( * (struct V_9 * * ) V_40 ) ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_9 * * V_41 ;
int V_42 ;
V_41 = F_36 ( F_34 , sizeof( * V_41 ) ,
V_24 ) ;
if ( ! V_41 )
return - V_43 ;
* V_41 = V_10 ;
V_42 = F_28 ( V_10 ) ;
if ( V_42 )
F_37 ( V_41 ) ;
else
F_38 ( V_2 , V_41 ) ;
return V_42 ;
}
void F_39 ( struct V_9 * V_10 ,
enum V_44 V_45 )
{
struct V_7 * V_8 ;
if ( ! V_10 )
return;
F_40 ( & V_10 -> V_25 ) ;
F_8 (led_cdev, &trig->led_cdevs, trig_list)
F_21 ( V_8 , V_45 ) ;
F_41 ( & V_10 -> V_25 ) ;
}
static void F_42 ( struct V_9 * V_10 ,
unsigned long * V_46 ,
unsigned long * V_47 ,
int V_48 ,
int V_49 )
{
struct V_7 * V_8 ;
if ( ! V_10 )
return;
F_40 ( & V_10 -> V_25 ) ;
F_8 (led_cdev, &trig->led_cdevs, trig_list) {
if ( V_48 )
F_43 ( V_8 , V_46 , V_47 ,
V_49 ) ;
else
F_44 ( V_8 , V_46 , V_47 ) ;
}
F_41 ( & V_10 -> V_25 ) ;
}
void F_45 ( struct V_9 * V_10 ,
unsigned long * V_46 ,
unsigned long * V_47 )
{
F_42 ( V_10 , V_46 , V_47 , 0 , 0 ) ;
}
void F_46 ( struct V_9 * V_10 ,
unsigned long * V_46 ,
unsigned long * V_47 ,
int V_49 )
{
F_42 ( V_10 , V_46 , V_47 , 1 , V_49 ) ;
}
void F_47 ( const char * V_16 , struct V_9 * * V_50 )
{
struct V_9 * V_10 ;
int V_51 ;
V_10 = F_48 ( sizeof( struct V_9 ) , V_24 ) ;
if ( V_10 ) {
V_10 -> V_16 = V_16 ;
V_51 = F_28 ( V_10 ) ;
if ( V_51 < 0 ) {
F_24 ( V_10 ) ;
V_10 = NULL ;
F_49 ( L_8 ,
V_16 , V_51 ) ;
}
} else {
F_49 ( L_9 ,
V_16 ) ;
}
* V_50 = V_10 ;
}
void F_50 ( struct V_9 * V_10 )
{
if ( V_10 )
F_31 ( V_10 ) ;
F_24 ( V_10 ) ;
}
