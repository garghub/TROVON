static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_2 , 0 ) ;
return V_3 ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 , * V_10 ;
unsigned long V_11 ;
struct V_12 * V_13 ;
int V_1 , V_14 = 0 , V_15 = 0 ;
do {
V_13 = F_4 ( V_5 ,
V_16 , V_15 ) ;
if ( V_13 == NULL ) {
if ( V_15 == 0 )
F_5 ( & V_5 -> V_17 , L_1 ) ;
break;
}
V_11 = ( V_13 -> V_18 & V_19 ) | V_20 ;
for ( V_1 = V_13 -> V_21 ; V_1 <= V_13 -> V_22 ; V_1 ++ ) {
V_9 = F_6 ( L_2 , V_1 ) ;
if ( ! V_9 ) {
V_14 = - V_23 ;
goto V_24;
}
V_7 = F_7 ( sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 ) {
V_14 = - V_23 ;
goto V_26;
}
F_8 ( V_9 , V_7 ) ;
V_7 -> V_1 = V_1 ;
V_9 -> V_27 = & V_28 ;
V_14 = F_9 ( V_1 , F_1 ,
V_11 , V_9 -> V_29 , V_9 ) ;
if ( V_14 ) {
F_5 ( & V_5 -> V_17 ,
L_3 , V_1 ) ;
goto V_30;
}
V_14 = F_10 ( V_9 ) ;
if ( V_14 )
goto V_31;
F_11 ( & V_9 -> V_32 ,
& V_33 ) ;
}
V_15 ++ ;
} while ( V_13 != NULL );
return 0 ;
V_31:
F_12 ( V_1 , V_9 ) ;
V_30:
F_13 ( V_7 ) ;
V_26:
F_14 ( V_9 ) ;
V_24:
F_15 (trig,
trig2,
&iio_gpio_trigger_list,
alloc_list) {
V_7 = F_16 ( V_9 ) ;
F_12 ( F_17 ( V_7 -> V_1 ) , V_9 ) ;
F_13 ( V_7 ) ;
F_18 ( V_9 ) ;
}
return V_14 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_8 * V_9 , * V_10 ;
struct V_6 * V_7 ;
F_20 ( & V_34 ) ;
F_15 (trig,
trig2,
&iio_gpio_trigger_list,
alloc_list) {
V_7 = F_16 ( V_9 ) ;
F_18 ( V_9 ) ;
F_12 ( V_7 -> V_1 , V_9 ) ;
F_13 ( V_7 ) ;
F_14 ( V_9 ) ;
}
F_21 ( & V_34 ) ;
return 0 ;
}
