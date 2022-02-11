static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_5 -> V_7 == 0 && V_3 )
return - V_8 ;
F_3 ( & V_5 -> V_9 -> V_10 , L_1 ,
V_5 -> V_7 ) ;
V_6 = F_4 ( V_5 -> V_9 , & V_5 -> V_11 , V_3 ) ;
if ( ! V_6 )
V_5 -> V_3 = V_3 ;
return V_6 ;
}
static T_1 F_5 ( struct V_12 * V_10 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
return sprintf ( V_15 , L_2 , V_5 -> V_7 ) ;
}
static T_1 F_7 ( struct V_12 * V_10 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_2 V_16 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_17 ;
int V_6 ;
V_6 = F_8 ( V_15 , 10 , & V_17 ) ;
if ( V_6 )
goto V_18;
if ( V_17 > 0 ) {
V_6 = F_9 ( V_5 -> V_9 , & V_5 -> V_11 , V_17 ) ;
if ( V_6 == 0 && V_5 -> V_3 && V_5 -> V_7 == 0 )
V_6 = F_4 ( V_5 -> V_9 ,
& V_5 -> V_11 , 1 ) ;
} else {
V_6 = F_4 ( V_5 -> V_9 , & V_5 -> V_11 , 0 ) ;
}
if ( V_6 )
goto V_18;
V_5 -> V_7 = V_17 ;
return V_16 ;
V_18:
return V_6 ;
}
static void F_10 ( void * V_19 )
{
F_11 ( V_19 ) ;
}
static int F_12 ( struct V_20 * V_10 )
{
char * * V_21 = V_10 -> V_10 . V_22 ;
struct V_4 * V_5 ;
struct V_1 * V_2 , * V_23 ;
int V_24 , V_6 ;
for ( V_24 = 0 ; ; V_24 ++ ) {
if ( ! V_21 [ V_24 ] )
break;
V_2 = F_13 ( L_3 , V_21 [ V_24 ] ) ;
if ( ! V_2 ) {
V_6 = - V_25 ;
goto V_26;
}
F_14 ( & V_2 -> V_27 , & V_28 ) ;
V_5 = F_15 ( sizeof( * V_5 ) , V_29 ) ;
if ( ! V_5 ) {
V_6 = - V_25 ;
goto V_30;
}
F_16 ( V_2 , V_5 ) ;
V_2 -> V_31 = & V_32 ;
V_5 -> V_9 = F_17 ( V_21 [ V_24 ] ) ;
if ( ! V_5 -> V_9 ) {
V_6 = - V_8 ;
goto V_33;
}
V_5 -> V_11 . V_34 = F_10 ;
V_5 -> V_11 . V_19 = V_2 ;
V_6 = F_18 ( V_5 -> V_9 , & V_5 -> V_11 ) ;
if ( V_6 )
goto V_35;
V_2 -> V_10 . V_36 = V_37 ;
V_6 = F_19 ( V_2 ) ;
if ( V_6 )
goto V_38;
}
return 0 ;
V_38:
F_20 ( V_5 -> V_9 , & V_5 -> V_11 ) ;
V_35:
F_21 ( V_5 -> V_9 ) ;
V_33:
F_22 ( V_5 ) ;
V_30:
F_23 ( & V_2 -> V_27 ) ;
F_24 ( V_2 ) ;
V_26:
F_25 (trig,
trig2,
&iio_prtc_trigger_list,
alloc_list) {
V_5 = F_2 ( V_2 ) ;
F_20 ( V_5 -> V_9 , & V_5 -> V_11 ) ;
F_21 ( V_5 -> V_9 ) ;
F_22 ( V_5 ) ;
F_26 ( V_2 ) ;
}
return V_6 ;
}
static int F_27 ( struct V_20 * V_10 )
{
struct V_1 * V_2 , * V_23 ;
struct V_4 * V_5 ;
F_28 ( & V_39 ) ;
F_25 (trig,
trig2,
&iio_prtc_trigger_list,
alloc_list) {
V_5 = F_2 ( V_2 ) ;
F_20 ( V_5 -> V_9 , & V_5 -> V_11 ) ;
F_21 ( V_5 -> V_9 ) ;
F_22 ( V_5 ) ;
F_26 ( V_2 ) ;
}
F_29 ( & V_39 ) ;
return 0 ;
}
