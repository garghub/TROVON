static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_7 == 0 )
return - V_8 ;
F_2 ( V_9 L_1 , V_5 -> V_7 ) ;
return F_3 ( V_5 -> V_10 , & V_5 -> V_11 , V_3 ) ;
}
static T_1 F_4 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_1 * V_2 = F_5 ( V_13 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
return sprintf ( V_16 , L_2 , V_5 -> V_7 ) ;
}
static T_1 F_6 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 ,
T_2 V_17 )
{
struct V_1 * V_2 = F_5 ( V_13 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_18 ;
int V_19 ;
V_19 = F_7 ( V_16 , 10 , & V_18 ) ;
if ( V_19 )
goto V_20;
V_19 = F_8 ( V_5 -> V_10 , & V_5 -> V_11 , V_18 ) ;
if ( V_19 )
goto V_20;
V_5 -> V_7 = V_18 ;
return V_17 ;
V_20:
return V_19 ;
}
static void F_9 ( void * V_6 )
{
F_10 ( V_6 , 0 ) ;
}
static int F_11 ( struct V_21 * V_13 )
{
char * * V_22 = V_13 -> V_13 . V_23 ;
struct V_4 * V_5 ;
struct V_1 * V_2 , * V_24 ;
int V_25 , V_19 ;
for ( V_25 = 0 ; ; V_25 ++ ) {
if ( V_22 [ V_25 ] == NULL )
break;
V_2 = F_12 ( L_3 , V_22 [ V_25 ] ) ;
if ( ! V_2 ) {
V_19 = - V_26 ;
goto V_27;
}
F_13 ( & V_2 -> V_28 , & V_29 ) ;
V_5 = F_14 ( sizeof( * V_5 ) , V_30 ) ;
if ( ! V_5 ) {
V_19 = - V_26 ;
goto V_31;
}
V_2 -> V_6 = V_5 ;
V_2 -> V_32 = & V_33 ;
V_5 -> V_10
= F_15 ( V_22 [ V_25 ] ) ;
if ( V_5 -> V_10 == NULL ) {
V_19 = - V_8 ;
goto V_34;
}
V_5 -> V_11 . V_35 = F_9 ;
V_5 -> V_11 . V_6 = V_2 ;
V_19 = F_16 ( V_5 -> V_10 , & V_5 -> V_11 ) ;
if ( V_19 )
goto V_36;
V_2 -> V_13 . V_37 = V_38 ;
V_19 = F_17 ( V_2 ) ;
if ( V_19 )
goto V_39;
}
return 0 ;
V_39:
F_18 ( V_5 -> V_10 , & V_5 -> V_11 ) ;
V_36:
F_19 ( V_5 -> V_10 ) ;
V_34:
F_20 ( V_5 ) ;
V_31:
F_21 ( & V_2 -> V_28 ) ;
F_22 ( V_2 ) ;
V_27:
F_23 (trig,
trig2,
&iio_prtc_trigger_list,
alloc_list) {
V_5 = V_2 -> V_6 ;
F_18 ( V_5 -> V_10 , & V_5 -> V_11 ) ;
F_19 ( V_5 -> V_10 ) ;
F_20 ( V_5 ) ;
F_24 ( V_2 ) ;
}
return V_19 ;
}
static int F_25 ( struct V_21 * V_13 )
{
struct V_1 * V_2 , * V_24 ;
struct V_4 * V_5 ;
F_26 ( & V_40 ) ;
F_23 (trig,
trig2,
&iio_prtc_trigger_list,
alloc_list) {
V_5 = V_2 -> V_6 ;
F_18 ( V_5 -> V_10 , & V_5 -> V_11 ) ;
F_19 ( V_5 -> V_10 ) ;
F_20 ( V_5 ) ;
F_24 ( V_2 ) ;
}
F_27 ( & V_40 ) ;
return 0 ;
}
