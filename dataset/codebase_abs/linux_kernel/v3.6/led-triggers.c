T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
char V_9 [ V_10 ] ;
struct V_11 * V_12 ;
T_2 V_13 ;
V_9 [ sizeof( V_9 ) - 1 ] = '\0' ;
strncpy ( V_9 , V_5 , sizeof( V_9 ) - 1 ) ;
V_13 = strlen ( V_9 ) ;
if ( V_13 && V_9 [ V_13 - 1 ] == '\n' )
V_9 [ V_13 - 1 ] = '\0' ;
if ( ! strcmp ( V_9 , L_1 ) ) {
F_3 ( V_8 ) ;
return V_6 ;
}
F_4 ( & V_14 ) ;
F_5 (trig, &trigger_list, next_trig) {
if ( ! strcmp ( V_9 , V_12 -> V_15 ) ) {
F_6 ( & V_8 -> V_16 ) ;
F_7 ( V_8 , V_12 ) ;
F_8 ( & V_8 -> V_16 ) ;
F_9 ( & V_14 ) ;
return V_6 ;
}
}
F_9 ( & V_14 ) ;
return - V_17 ;
}
T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_13 = 0 ;
F_4 ( & V_14 ) ;
F_4 ( & V_8 -> V_16 ) ;
if ( ! V_8 -> V_18 )
V_13 += sprintf ( V_5 + V_13 , L_2 ) ;
else
V_13 += sprintf ( V_5 + V_13 , L_3 ) ;
F_5 (trig, &trigger_list, next_trig) {
if ( V_8 -> V_18 && ! strcmp ( V_8 -> V_18 -> V_15 ,
V_12 -> V_15 ) )
V_13 += sprintf ( V_5 + V_13 , L_4 , V_12 -> V_15 ) ;
else
V_13 += sprintf ( V_5 + V_13 , L_5 , V_12 -> V_15 ) ;
}
F_9 ( & V_8 -> V_16 ) ;
F_9 ( & V_14 ) ;
V_13 += sprintf ( V_13 + V_5 , L_6 ) ;
return V_13 ;
}
void F_7 ( struct V_7 * V_8 , struct V_11 * V_12 )
{
unsigned long V_19 ;
if ( V_8 -> V_18 ) {
F_11 ( & V_8 -> V_18 -> V_20 , V_19 ) ;
F_12 ( & V_8 -> V_21 ) ;
F_13 ( & V_8 -> V_18 -> V_20 ,
V_19 ) ;
if ( V_8 -> V_18 -> V_22 )
V_8 -> V_18 -> V_22 ( V_8 ) ;
V_8 -> V_18 = NULL ;
F_14 ( V_8 , V_23 ) ;
}
if ( V_12 ) {
F_11 ( & V_12 -> V_20 , V_19 ) ;
F_15 ( & V_8 -> V_21 , & V_12 -> V_24 ) ;
F_13 ( & V_12 -> V_20 , V_19 ) ;
V_8 -> V_18 = V_12 ;
if ( V_12 -> V_25 )
V_12 -> V_25 ( V_8 ) ;
}
}
void F_3 ( struct V_7 * V_8 )
{
F_6 ( & V_8 -> V_16 ) ;
F_7 ( V_8 , NULL ) ;
F_8 ( & V_8 -> V_16 ) ;
}
void F_16 ( struct V_7 * V_8 )
{
struct V_11 * V_12 ;
if ( ! V_8 -> V_26 )
return;
F_4 ( & V_14 ) ;
F_6 ( & V_8 -> V_16 ) ;
F_5 (trig, &trigger_list, next_trig) {
if ( ! strcmp ( V_8 -> V_26 , V_12 -> V_15 ) )
F_7 ( V_8 , V_12 ) ;
}
F_8 ( & V_8 -> V_16 ) ;
F_9 ( & V_14 ) ;
}
int F_17 ( struct V_11 * V_12 )
{
struct V_7 * V_8 ;
struct V_11 * V_27 ;
F_18 ( & V_12 -> V_20 ) ;
F_19 ( & V_12 -> V_24 ) ;
F_6 ( & V_14 ) ;
F_5 (_trig, &trigger_list, next_trig) {
if ( ! strcmp ( V_27 -> V_15 , V_12 -> V_15 ) ) {
F_8 ( & V_14 ) ;
return - V_28 ;
}
}
F_15 ( & V_12 -> V_29 , & V_30 ) ;
F_8 ( & V_14 ) ;
F_4 ( & V_31 ) ;
F_5 (led_cdev, &leds_list, node) {
F_6 ( & V_8 -> V_16 ) ;
if ( ! V_8 -> V_18 && V_8 -> V_26 &&
! strcmp ( V_8 -> V_26 , V_12 -> V_15 ) )
F_7 ( V_8 , V_12 ) ;
F_8 ( & V_8 -> V_16 ) ;
}
F_9 ( & V_31 ) ;
return 0 ;
}
void F_20 ( struct V_11 * V_12 )
{
struct V_7 * V_8 ;
F_6 ( & V_14 ) ;
F_12 ( & V_12 -> V_29 ) ;
F_8 ( & V_14 ) ;
F_4 ( & V_31 ) ;
F_5 (led_cdev, &leds_list, node) {
F_6 ( & V_8 -> V_16 ) ;
if ( V_8 -> V_18 == V_12 )
F_7 ( V_8 , NULL ) ;
F_8 ( & V_8 -> V_16 ) ;
}
F_9 ( & V_31 ) ;
}
void F_21 ( struct V_11 * V_12 ,
enum V_32 V_33 )
{
struct V_34 * V_35 ;
if ( ! V_12 )
return;
F_22 ( & V_12 -> V_20 ) ;
F_23 (entry, &trig->led_cdevs) {
struct V_7 * V_8 ;
V_8 = F_24 ( V_35 , struct V_7 , V_21 ) ;
F_25 ( V_8 , V_33 ) ;
}
F_26 ( & V_12 -> V_20 ) ;
}
static void F_27 ( struct V_11 * V_12 ,
unsigned long * V_36 ,
unsigned long * V_37 ,
int V_38 ,
int V_39 )
{
struct V_34 * V_35 ;
if ( ! V_12 )
return;
F_22 ( & V_12 -> V_20 ) ;
F_23 (entry, &trig->led_cdevs) {
struct V_7 * V_8 ;
V_8 = F_24 ( V_35 , struct V_7 , V_21 ) ;
if ( V_38 )
F_28 ( V_8 , V_36 , V_37 ,
V_39 ) ;
else
F_29 ( V_8 , V_36 , V_37 ) ;
}
F_26 ( & V_12 -> V_20 ) ;
}
void F_30 ( struct V_11 * V_12 ,
unsigned long * V_36 ,
unsigned long * V_37 )
{
F_27 ( V_12 , V_36 , V_37 , 0 , 0 ) ;
}
void F_31 ( struct V_11 * V_12 ,
unsigned long * V_36 ,
unsigned long * V_37 ,
int V_39 )
{
F_27 ( V_12 , V_36 , V_37 , 1 , V_39 ) ;
}
void F_32 ( const char * V_15 , struct V_11 * * V_40 )
{
struct V_11 * V_12 ;
int V_41 ;
V_12 = F_33 ( sizeof( struct V_11 ) , V_42 ) ;
if ( V_12 ) {
V_12 -> V_15 = V_15 ;
V_41 = F_17 ( V_12 ) ;
if ( V_41 < 0 ) {
F_34 ( V_12 ) ;
V_12 = NULL ;
F_35 ( V_43 L_7
L_8 , V_15 , V_41 ) ;
}
} else
F_35 ( V_43 L_7
L_9 , V_15 ) ;
* V_40 = V_12 ;
}
void F_36 ( struct V_11 * V_12 )
{
if ( V_12 )
F_20 ( V_12 ) ;
F_34 ( V_12 ) ;
}
