static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_6 == 0 )
return - V_7 ;
F_3 ( V_8 L_1 , V_5 -> V_6 ) ;
return F_4 ( V_5 -> V_9 , & V_5 -> V_10 , V_3 ) ;
}
static T_1 F_5 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
return sprintf ( V_15 , L_2 , V_5 -> V_6 ) ;
}
static T_1 F_7 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_16 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_17 ;
int V_18 ;
V_18 = F_8 ( V_15 , 10 , & V_17 ) ;
if ( V_18 )
goto V_19;
V_18 = F_9 ( V_5 -> V_9 , & V_5 -> V_10 , V_17 ) ;
if ( V_18 )
goto V_19;
V_5 -> V_6 = V_17 ;
return V_16 ;
V_19:
return V_18 ;
}
static void F_10 ( void * V_20 )
{
F_11 ( V_20 , 0 ) ;
}
static int F_12 ( struct V_21 * V_12 )
{
char * * V_22 = V_12 -> V_12 . V_23 ;
struct V_4 * V_5 ;
struct V_1 * V_2 , * V_24 ;
int V_25 , V_18 ;
for ( V_25 = 0 ; ; V_25 ++ ) {
if ( V_22 [ V_25 ] == NULL )
break;
V_2 = F_13 ( L_3 , V_22 [ V_25 ] ) ;
if ( ! V_2 ) {
V_18 = - V_26 ;
goto V_27;
}
F_14 ( & V_2 -> V_28 , & V_29 ) ;
V_5 = F_15 ( sizeof( * V_5 ) , V_30 ) ;
if ( ! V_5 ) {
V_18 = - V_26 ;
goto V_31;
}
F_16 ( V_2 , V_5 ) ;
V_2 -> V_32 = & V_33 ;
V_5 -> V_9
= F_17 ( V_22 [ V_25 ] ) ;
if ( V_5 -> V_9 == NULL ) {
V_18 = - V_7 ;
goto V_34;
}
V_5 -> V_10 . V_35 = F_10 ;
V_5 -> V_10 . V_20 = V_2 ;
V_18 = F_18 ( V_5 -> V_9 , & V_5 -> V_10 ) ;
if ( V_18 )
goto V_36;
V_2 -> V_12 . V_37 = V_38 ;
V_18 = F_19 ( V_2 ) ;
if ( V_18 )
goto V_39;
}
return 0 ;
V_39:
F_20 ( V_5 -> V_9 , & V_5 -> V_10 ) ;
V_36:
F_21 ( V_5 -> V_9 ) ;
V_34:
F_22 ( V_5 ) ;
V_31:
F_23 ( & V_2 -> V_28 ) ;
F_24 ( V_2 ) ;
V_27:
F_25 (trig,
trig2,
&iio_prtc_trigger_list,
alloc_list) {
V_5 = F_2 ( V_2 ) ;
F_20 ( V_5 -> V_9 , & V_5 -> V_10 ) ;
F_21 ( V_5 -> V_9 ) ;
F_22 ( V_5 ) ;
F_26 ( V_2 ) ;
}
return V_18 ;
}
static int F_27 ( struct V_21 * V_12 )
{
struct V_1 * V_2 , * V_24 ;
struct V_4 * V_5 ;
F_28 ( & V_40 ) ;
F_25 (trig,
trig2,
&iio_prtc_trigger_list,
alloc_list) {
V_5 = F_2 ( V_2 ) ;
F_20 ( V_5 -> V_9 , & V_5 -> V_10 ) ;
F_21 ( V_5 -> V_9 ) ;
F_22 ( V_5 ) ;
F_26 ( V_2 ) ;
}
F_29 ( & V_40 ) ;
return 0 ;
}
