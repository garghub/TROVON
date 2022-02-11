T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
char V_9 [ V_10 ] ;
struct V_11 * V_12 ;
T_2 V_13 ;
int V_14 = V_6 ;
F_3 ( & V_8 -> V_15 ) ;
if ( F_4 ( V_8 ) ) {
V_14 = - V_16 ;
goto V_17;
}
V_9 [ sizeof( V_9 ) - 1 ] = '\0' ;
strncpy ( V_9 , V_5 , sizeof( V_9 ) - 1 ) ;
V_13 = strlen ( V_9 ) ;
if ( V_13 && V_9 [ V_13 - 1 ] == '\n' )
V_9 [ V_13 - 1 ] = '\0' ;
if ( ! strcmp ( V_9 , L_1 ) ) {
F_5 ( V_8 ) ;
goto V_17;
}
F_6 ( & V_18 ) ;
F_7 (trig, &trigger_list, next_trig) {
if ( ! strcmp ( V_9 , V_12 -> V_19 ) ) {
F_8 ( & V_8 -> V_20 ) ;
F_9 ( V_8 , V_12 ) ;
F_10 ( & V_8 -> V_20 ) ;
F_11 ( & V_18 ) ;
goto V_17;
}
}
F_11 ( & V_18 ) ;
V_17:
F_12 ( & V_8 -> V_15 ) ;
return V_14 ;
}
T_1 F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_13 = 0 ;
F_6 ( & V_18 ) ;
F_6 ( & V_8 -> V_20 ) ;
if ( ! V_8 -> V_21 )
V_13 += sprintf ( V_5 + V_13 , L_2 ) ;
else
V_13 += sprintf ( V_5 + V_13 , L_3 ) ;
F_7 (trig, &trigger_list, next_trig) {
if ( V_8 -> V_21 && ! strcmp ( V_8 -> V_21 -> V_19 ,
V_12 -> V_19 ) )
V_13 += sprintf ( V_5 + V_13 , L_4 , V_12 -> V_19 ) ;
else
V_13 += sprintf ( V_5 + V_13 , L_5 , V_12 -> V_19 ) ;
}
F_11 ( & V_8 -> V_20 ) ;
F_11 ( & V_18 ) ;
V_13 += sprintf ( V_13 + V_5 , L_6 ) ;
return V_13 ;
}
void F_9 ( struct V_7 * V_8 , struct V_11 * V_12 )
{
unsigned long V_22 ;
char * V_23 = NULL ;
char * V_24 [ 2 ] ;
const char * V_19 ;
V_19 = V_12 ? V_12 -> V_19 : L_1 ;
V_23 = F_14 ( V_25 , L_7 , V_19 ) ;
if ( V_8 -> V_21 ) {
F_15 ( & V_8 -> V_21 -> V_26 , V_22 ) ;
F_16 ( & V_8 -> V_27 ) ;
F_17 ( & V_8 -> V_21 -> V_26 ,
V_22 ) ;
F_18 ( & V_8 -> V_28 ) ;
F_19 ( V_8 ) ;
if ( V_8 -> V_21 -> V_29 )
V_8 -> V_21 -> V_29 ( V_8 ) ;
V_8 -> V_21 = NULL ;
F_20 ( V_8 , V_30 ) ;
}
if ( V_12 ) {
F_15 ( & V_12 -> V_26 , V_22 ) ;
F_21 ( & V_8 -> V_27 , & V_12 -> V_31 ) ;
F_17 ( & V_12 -> V_26 , V_22 ) ;
V_8 -> V_21 = V_12 ;
if ( V_12 -> V_32 )
V_12 -> V_32 ( V_8 ) ;
}
if ( V_23 ) {
V_24 [ 0 ] = V_23 ;
V_24 [ 1 ] = NULL ;
F_22 ( & V_8 -> V_2 -> V_33 , V_34 , V_24 ) ;
F_23 ( V_23 ) ;
}
}
void F_5 ( struct V_7 * V_8 )
{
F_8 ( & V_8 -> V_20 ) ;
F_9 ( V_8 , NULL ) ;
F_10 ( & V_8 -> V_20 ) ;
}
void F_24 ( struct V_7 * V_8 )
{
struct V_11 * V_12 ;
if ( ! V_8 -> V_35 )
return;
F_6 ( & V_18 ) ;
F_8 ( & V_8 -> V_20 ) ;
F_7 (trig, &trigger_list, next_trig) {
if ( ! strcmp ( V_8 -> V_35 , V_12 -> V_19 ) )
F_9 ( V_8 , V_12 ) ;
}
F_10 ( & V_8 -> V_20 ) ;
F_11 ( & V_18 ) ;
}
void F_25 ( const char * V_19 , struct V_11 * V_12 )
{
F_26 ( V_19 == V_12 -> V_19 ) ;
F_8 ( & V_18 ) ;
strcpy ( ( char * ) V_12 -> V_19 , V_19 ) ;
F_10 ( & V_18 ) ;
}
int F_27 ( struct V_11 * V_12 )
{
struct V_7 * V_8 ;
struct V_11 * V_36 ;
F_28 ( & V_12 -> V_26 ) ;
F_29 ( & V_12 -> V_31 ) ;
F_8 ( & V_18 ) ;
F_7 (_trig, &trigger_list, next_trig) {
if ( ! strcmp ( V_36 -> V_19 , V_12 -> V_19 ) ) {
F_10 ( & V_18 ) ;
return - V_37 ;
}
}
F_21 ( & V_12 -> V_38 , & V_39 ) ;
F_10 ( & V_18 ) ;
F_6 ( & V_40 ) ;
F_7 (led_cdev, &leds_list, node) {
F_8 ( & V_8 -> V_20 ) ;
if ( ! V_8 -> V_21 && V_8 -> V_35 &&
! strcmp ( V_8 -> V_35 , V_12 -> V_19 ) )
F_9 ( V_8 , V_12 ) ;
F_10 ( & V_8 -> V_20 ) ;
}
F_11 ( & V_40 ) ;
return 0 ;
}
void F_30 ( struct V_11 * V_12 )
{
struct V_7 * V_8 ;
if ( F_31 ( & V_12 -> V_38 ) )
return;
F_8 ( & V_18 ) ;
F_32 ( & V_12 -> V_38 ) ;
F_10 ( & V_18 ) ;
F_6 ( & V_40 ) ;
F_7 (led_cdev, &leds_list, node) {
F_8 ( & V_8 -> V_20 ) ;
if ( V_8 -> V_21 == V_12 )
F_9 ( V_8 , NULL ) ;
F_10 ( & V_8 -> V_20 ) ;
}
F_11 ( & V_40 ) ;
}
static void F_33 ( struct V_1 * V_2 , void * V_41 )
{
F_30 ( * (struct V_11 * * ) V_41 ) ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * * V_42 ;
int V_43 ;
V_42 = F_35 ( F_33 , sizeof( * V_42 ) ,
V_25 ) ;
if ( ! V_42 )
return - V_44 ;
* V_42 = V_12 ;
V_43 = F_27 ( V_12 ) ;
if ( V_43 )
F_36 ( V_42 ) ;
else
F_37 ( V_2 , V_42 ) ;
return V_43 ;
}
void F_38 ( struct V_11 * V_12 ,
enum V_45 V_46 )
{
struct V_7 * V_8 ;
if ( ! V_12 )
return;
F_39 ( & V_12 -> V_26 ) ;
F_7 (led_cdev, &trig->led_cdevs, trig_list)
F_20 ( V_8 , V_46 ) ;
F_40 ( & V_12 -> V_26 ) ;
}
static void F_41 ( struct V_11 * V_12 ,
unsigned long * V_47 ,
unsigned long * V_48 ,
int V_49 ,
int V_50 )
{
struct V_7 * V_8 ;
if ( ! V_12 )
return;
F_39 ( & V_12 -> V_26 ) ;
F_7 (led_cdev, &trig->led_cdevs, trig_list) {
if ( V_49 )
F_42 ( V_8 , V_47 , V_48 ,
V_50 ) ;
else
F_43 ( V_8 , V_47 , V_48 ) ;
}
F_40 ( & V_12 -> V_26 ) ;
}
void F_44 ( struct V_11 * V_12 ,
unsigned long * V_47 ,
unsigned long * V_48 )
{
F_41 ( V_12 , V_47 , V_48 , 0 , 0 ) ;
}
void F_45 ( struct V_11 * V_12 ,
unsigned long * V_47 ,
unsigned long * V_48 ,
int V_50 )
{
F_41 ( V_12 , V_47 , V_48 , 1 , V_50 ) ;
}
void F_46 ( const char * V_19 , struct V_11 * * V_51 )
{
struct V_11 * V_12 ;
int V_52 ;
V_12 = F_47 ( sizeof( struct V_11 ) , V_25 ) ;
if ( V_12 ) {
V_12 -> V_19 = V_19 ;
V_52 = F_27 ( V_12 ) ;
if ( V_52 < 0 ) {
F_23 ( V_12 ) ;
V_12 = NULL ;
F_48 ( L_8 ,
V_19 , V_52 ) ;
}
} else {
F_48 ( L_9 ,
V_19 ) ;
}
* V_51 = V_12 ;
}
void F_49 ( struct V_11 * V_12 )
{
if ( V_12 )
F_30 ( V_12 ) ;
F_23 ( V_12 ) ;
}
