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
V_19 += F_15 ( V_5 + V_19 , V_21 - V_19 , L_2 ) ;
else
V_19 += F_15 ( V_5 + V_19 , V_21 - V_19 , L_3 ) ;
F_8 (trig, &trigger_list, next_trig) {
if ( V_8 -> V_20 && ! strcmp ( V_8 -> V_20 -> V_16 ,
V_10 -> V_16 ) )
V_19 += F_15 ( V_5 + V_19 , V_21 - V_19 , L_4 ,
V_10 -> V_16 ) ;
else
V_19 += F_15 ( V_5 + V_19 , V_21 - V_19 , L_5 ,
V_10 -> V_16 ) ;
}
F_12 ( & V_8 -> V_17 ) ;
F_12 ( & V_15 ) ;
V_19 += F_15 ( V_19 + V_5 , V_21 - V_19 , L_6 ) ;
return V_19 ;
}
void F_10 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
unsigned long V_22 ;
char * V_23 = NULL ;
char * V_24 [ 2 ] ;
const char * V_16 ;
if ( ! V_8 -> V_20 && ! V_10 )
return;
V_16 = V_10 ? V_10 -> V_16 : L_1 ;
V_23 = F_16 ( V_25 , L_7 , V_16 ) ;
if ( V_8 -> V_20 ) {
F_17 ( & V_8 -> V_20 -> V_26 , V_22 ) ;
F_18 ( & V_8 -> V_27 ) ;
F_19 ( & V_8 -> V_20 -> V_26 ,
V_22 ) ;
F_20 ( & V_8 -> V_28 ) ;
F_21 ( V_8 ) ;
if ( V_8 -> V_20 -> V_29 )
V_8 -> V_20 -> V_29 ( V_8 ) ;
V_8 -> V_20 = NULL ;
F_22 ( V_8 , V_30 ) ;
}
if ( V_10 ) {
F_17 ( & V_10 -> V_26 , V_22 ) ;
F_23 ( & V_8 -> V_27 , & V_10 -> V_31 ) ;
F_19 ( & V_10 -> V_26 , V_22 ) ;
V_8 -> V_20 = V_10 ;
if ( V_10 -> V_32 )
V_10 -> V_32 ( V_8 ) ;
}
if ( V_23 ) {
V_24 [ 0 ] = V_23 ;
V_24 [ 1 ] = NULL ;
if ( F_24 ( & V_8 -> V_2 -> V_33 , V_34 , V_24 ) )
F_25 ( V_8 -> V_2 ,
L_8 , V_35 ) ;
F_26 ( V_23 ) ;
}
}
void F_6 ( struct V_7 * V_8 )
{
F_9 ( & V_8 -> V_17 ) ;
F_10 ( V_8 , NULL ) ;
F_11 ( & V_8 -> V_17 ) ;
}
void F_27 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
if ( ! V_8 -> V_36 )
return;
F_7 ( & V_15 ) ;
F_9 ( & V_8 -> V_17 ) ;
F_8 (trig, &trigger_list, next_trig) {
if ( ! strcmp ( V_8 -> V_36 , V_10 -> V_16 ) )
F_10 ( V_8 , V_10 ) ;
}
F_11 ( & V_8 -> V_17 ) ;
F_12 ( & V_15 ) ;
}
void F_28 ( const char * V_16 , struct V_9 * V_10 )
{
F_29 ( V_16 == V_10 -> V_16 ) ;
F_9 ( & V_15 ) ;
strcpy ( ( char * ) V_10 -> V_16 , V_16 ) ;
F_11 ( & V_15 ) ;
}
int F_30 ( struct V_9 * V_10 )
{
struct V_7 * V_8 ;
struct V_9 * V_37 ;
F_31 ( & V_10 -> V_26 ) ;
F_32 ( & V_10 -> V_31 ) ;
F_9 ( & V_15 ) ;
F_8 (_trig, &trigger_list, next_trig) {
if ( ! strcmp ( V_37 -> V_16 , V_10 -> V_16 ) ) {
F_11 ( & V_15 ) ;
return - V_38 ;
}
}
F_23 ( & V_10 -> V_39 , & V_40 ) ;
F_11 ( & V_15 ) ;
F_7 ( & V_41 ) ;
F_8 (led_cdev, &leds_list, node) {
F_9 ( & V_8 -> V_17 ) ;
if ( ! V_8 -> V_20 && V_8 -> V_36 &&
! strcmp ( V_8 -> V_36 , V_10 -> V_16 ) )
F_10 ( V_8 , V_10 ) ;
F_11 ( & V_8 -> V_17 ) ;
}
F_12 ( & V_41 ) ;
return 0 ;
}
void F_33 ( struct V_9 * V_10 )
{
struct V_7 * V_8 ;
if ( F_34 ( & V_10 -> V_39 ) )
return;
F_9 ( & V_15 ) ;
F_35 ( & V_10 -> V_39 ) ;
F_11 ( & V_15 ) ;
F_7 ( & V_41 ) ;
F_8 (led_cdev, &leds_list, node) {
F_9 ( & V_8 -> V_17 ) ;
if ( V_8 -> V_20 == V_10 )
F_10 ( V_8 , NULL ) ;
F_11 ( & V_8 -> V_17 ) ;
}
F_12 ( & V_41 ) ;
}
static void F_36 ( struct V_1 * V_2 , void * V_42 )
{
F_33 ( * (struct V_9 * * ) V_42 ) ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_9 * * V_43 ;
int V_44 ;
V_43 = F_38 ( F_36 , sizeof( * V_43 ) ,
V_25 ) ;
if ( ! V_43 )
return - V_45 ;
* V_43 = V_10 ;
V_44 = F_30 ( V_10 ) ;
if ( V_44 )
F_39 ( V_43 ) ;
else
F_40 ( V_2 , V_43 ) ;
return V_44 ;
}
void F_41 ( struct V_9 * V_10 ,
enum V_46 V_47 )
{
struct V_7 * V_8 ;
if ( ! V_10 )
return;
F_42 ( & V_10 -> V_26 ) ;
F_8 (led_cdev, &trig->led_cdevs, trig_list)
F_22 ( V_8 , V_47 ) ;
F_43 ( & V_10 -> V_26 ) ;
}
static void F_44 ( struct V_9 * V_10 ,
unsigned long * V_48 ,
unsigned long * V_49 ,
int V_50 ,
int V_51 )
{
struct V_7 * V_8 ;
if ( ! V_10 )
return;
F_42 ( & V_10 -> V_26 ) ;
F_8 (led_cdev, &trig->led_cdevs, trig_list) {
if ( V_50 )
F_45 ( V_8 , V_48 , V_49 ,
V_51 ) ;
else
F_46 ( V_8 , V_48 , V_49 ) ;
}
F_43 ( & V_10 -> V_26 ) ;
}
void F_47 ( struct V_9 * V_10 ,
unsigned long * V_48 ,
unsigned long * V_49 )
{
F_44 ( V_10 , V_48 , V_49 , 0 , 0 ) ;
}
void F_48 ( struct V_9 * V_10 ,
unsigned long * V_48 ,
unsigned long * V_49 ,
int V_51 )
{
F_44 ( V_10 , V_48 , V_49 , 1 , V_51 ) ;
}
void F_49 ( const char * V_16 , struct V_9 * * V_52 )
{
struct V_9 * V_10 ;
int V_53 ;
V_10 = F_50 ( sizeof( struct V_9 ) , V_25 ) ;
if ( V_10 ) {
V_10 -> V_16 = V_16 ;
V_53 = F_30 ( V_10 ) ;
if ( V_53 < 0 ) {
F_26 ( V_10 ) ;
V_10 = NULL ;
F_51 ( L_9 ,
V_16 , V_53 ) ;
}
} else {
F_51 ( L_10 ,
V_16 ) ;
}
* V_52 = V_10 ;
}
void F_52 ( struct V_9 * V_10 )
{
if ( V_10 )
F_33 ( V_10 ) ;
F_26 ( V_10 ) ;
}
