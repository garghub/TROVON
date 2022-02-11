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
char * V_20 = NULL ;
char * V_21 [ 2 ] ;
const char * V_15 ;
V_15 = V_12 ? V_12 -> V_15 : L_1 ;
V_20 = F_11 ( V_22 , L_7 , V_15 ) ;
if ( V_8 -> V_18 ) {
F_12 ( & V_8 -> V_18 -> V_23 , V_19 ) ;
F_13 ( & V_8 -> V_24 ) ;
F_14 ( & V_8 -> V_18 -> V_23 ,
V_19 ) ;
F_15 ( & V_8 -> V_25 ) ;
F_16 ( V_8 ) ;
if ( V_8 -> V_18 -> V_26 )
V_8 -> V_18 -> V_26 ( V_8 ) ;
V_8 -> V_18 = NULL ;
F_17 ( V_8 , V_27 ) ;
}
if ( V_12 ) {
F_12 ( & V_12 -> V_23 , V_19 ) ;
F_18 ( & V_8 -> V_24 , & V_12 -> V_28 ) ;
F_14 ( & V_12 -> V_23 , V_19 ) ;
V_8 -> V_18 = V_12 ;
if ( V_12 -> V_29 )
V_12 -> V_29 ( V_8 ) ;
}
if ( V_20 ) {
V_21 [ 0 ] = V_20 ;
V_21 [ 1 ] = NULL ;
F_19 ( & V_8 -> V_2 -> V_30 , V_31 , V_21 ) ;
F_20 ( V_20 ) ;
}
}
void F_3 ( struct V_7 * V_8 )
{
F_6 ( & V_8 -> V_16 ) ;
F_7 ( V_8 , NULL ) ;
F_8 ( & V_8 -> V_16 ) ;
}
void F_21 ( struct V_7 * V_8 )
{
struct V_11 * V_12 ;
if ( ! V_8 -> V_32 )
return;
F_4 ( & V_14 ) ;
F_6 ( & V_8 -> V_16 ) ;
F_5 (trig, &trigger_list, next_trig) {
if ( ! strcmp ( V_8 -> V_32 , V_12 -> V_15 ) )
F_7 ( V_8 , V_12 ) ;
}
F_8 ( & V_8 -> V_16 ) ;
F_9 ( & V_14 ) ;
}
void F_22 ( const char * V_15 , struct V_11 * V_12 )
{
F_23 ( V_15 == V_12 -> V_15 ) ;
F_6 ( & V_14 ) ;
strcpy ( ( char * ) V_12 -> V_15 , V_15 ) ;
F_8 ( & V_14 ) ;
}
int F_24 ( struct V_11 * V_12 )
{
struct V_7 * V_8 ;
struct V_11 * V_33 ;
F_25 ( & V_12 -> V_23 ) ;
F_26 ( & V_12 -> V_28 ) ;
F_6 ( & V_14 ) ;
F_5 (_trig, &trigger_list, next_trig) {
if ( ! strcmp ( V_33 -> V_15 , V_12 -> V_15 ) ) {
F_8 ( & V_14 ) ;
return - V_34 ;
}
}
F_18 ( & V_12 -> V_35 , & V_36 ) ;
F_8 ( & V_14 ) ;
F_4 ( & V_37 ) ;
F_5 (led_cdev, &leds_list, node) {
F_6 ( & V_8 -> V_16 ) ;
if ( ! V_8 -> V_18 && V_8 -> V_32 &&
! strcmp ( V_8 -> V_32 , V_12 -> V_15 ) )
F_7 ( V_8 , V_12 ) ;
F_8 ( & V_8 -> V_16 ) ;
}
F_9 ( & V_37 ) ;
return 0 ;
}
void F_27 ( struct V_11 * V_12 )
{
struct V_7 * V_8 ;
F_6 ( & V_14 ) ;
F_13 ( & V_12 -> V_35 ) ;
F_8 ( & V_14 ) ;
F_4 ( & V_37 ) ;
F_5 (led_cdev, &leds_list, node) {
F_6 ( & V_8 -> V_16 ) ;
if ( V_8 -> V_18 == V_12 )
F_7 ( V_8 , NULL ) ;
F_8 ( & V_8 -> V_16 ) ;
}
F_9 ( & V_37 ) ;
}
void F_28 ( struct V_11 * V_12 ,
enum V_38 V_39 )
{
struct V_40 * V_41 ;
if ( ! V_12 )
return;
F_29 ( & V_12 -> V_23 ) ;
F_30 (entry, &trig->led_cdevs) {
struct V_7 * V_8 ;
V_8 = F_31 ( V_41 , struct V_7 , V_24 ) ;
F_17 ( V_8 , V_39 ) ;
}
F_32 ( & V_12 -> V_23 ) ;
}
static void F_33 ( struct V_11 * V_12 ,
unsigned long * V_42 ,
unsigned long * V_43 ,
int V_44 ,
int V_45 )
{
struct V_40 * V_41 ;
if ( ! V_12 )
return;
F_29 ( & V_12 -> V_23 ) ;
F_30 (entry, &trig->led_cdevs) {
struct V_7 * V_8 ;
V_8 = F_31 ( V_41 , struct V_7 , V_24 ) ;
if ( V_44 )
F_34 ( V_8 , V_42 , V_43 ,
V_45 ) ;
else
F_35 ( V_8 , V_42 , V_43 ) ;
}
F_32 ( & V_12 -> V_23 ) ;
}
void F_36 ( struct V_11 * V_12 ,
unsigned long * V_42 ,
unsigned long * V_43 )
{
F_33 ( V_12 , V_42 , V_43 , 0 , 0 ) ;
}
void F_37 ( struct V_11 * V_12 ,
unsigned long * V_42 ,
unsigned long * V_43 ,
int V_45 )
{
F_33 ( V_12 , V_42 , V_43 , 1 , V_45 ) ;
}
void F_38 ( const char * V_15 , struct V_11 * * V_46 )
{
struct V_11 * V_12 ;
int V_47 ;
V_12 = F_39 ( sizeof( struct V_11 ) , V_22 ) ;
if ( V_12 ) {
V_12 -> V_15 = V_15 ;
V_47 = F_24 ( V_12 ) ;
if ( V_47 < 0 ) {
F_20 ( V_12 ) ;
V_12 = NULL ;
F_40 ( L_8 ,
V_15 , V_47 ) ;
}
} else {
F_40 ( L_9 ,
V_15 ) ;
}
* V_46 = V_12 ;
}
void F_41 ( struct V_11 * V_12 )
{
if ( V_12 )
F_27 ( V_12 ) ;
F_20 ( V_12 ) ;
}
