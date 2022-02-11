static inline const char * F_1 ( int V_1 )
{
return ( V_1 == 1 ? L_1 : L_2 ) ;
}
static int F_2 ( struct V_2 * V_3 )
{
return V_3 -> V_4 == V_5
&& V_3 -> V_6 == 2
&& V_3 -> V_7 == 0xff ;
}
static int F_3 ( struct V_2 * V_3 )
{
return V_3 -> V_4 == V_8
&& V_3 -> V_6 == 1
&& V_3 -> V_7 == 1 ;
}
int F_4 ( struct V_9 * V_10 )
{
int V_11 ;
int V_12 ;
int V_13 = 0 ;
struct V_14 * V_15 , * V_16 ;
V_16 = NULL ;
V_15 = V_10 -> V_17 ;
V_12 = V_10 -> V_18 . V_19 ;
for ( V_11 = 0 ; V_11 < V_12 ; ( V_11 ++ , V_15 ++ ) ) {
struct V_2 * V_3 = NULL ;
if ( V_15 -> V_3 . V_20 > 0 )
V_3 = & V_15 -> V_21 [ 0 ] -> V_22 -> V_3 ;
#if 0
if (bus_powered && (c->desc.bmAttributes &
USB_CONFIG_ATT_SELFPOWER))
continue;
#endif
if ( V_15 -> V_3 . V_23 * 2 > V_10 -> V_24 ) {
V_13 ++ ;
continue;
}
if ( V_11 == 0 && V_12 > 1 && V_3 &&
( F_2 ( V_3 ) || F_3 ( V_3 ) ) ) {
#if ! F_5 ( V_25 ) && ! F_5 ( V_26 )
continue;
#else
V_16 = V_15 ;
#endif
}
else if ( V_10 -> V_18 . V_27 !=
V_28 &&
( V_3 && V_3 -> V_4 !=
V_28 ) ) {
V_16 = V_15 ;
break;
}
else if ( ! V_16 )
V_16 = V_15 ;
}
if ( V_13 > 0 )
F_6 ( & V_10 -> V_29 , L_3
L_4 ,
V_13 , F_1 ( V_13 ) ) ;
if ( V_16 ) {
V_11 = V_16 -> V_3 . V_30 ;
F_7 ( & V_10 -> V_29 ,
L_5 ,
V_11 , V_12 , F_1 ( V_12 ) ) ;
} else {
V_11 = - 1 ;
F_8 ( & V_10 -> V_29 ,
L_6 ,
V_12 , F_1 ( V_12 ) ) ;
}
return V_11 ;
}
static int F_9 ( struct V_9 * V_10 )
{
int V_31 , V_15 ;
if ( F_10 ( V_10 ) )
;
else if ( V_10 -> V_32 == 0 )
F_11 ( & V_10 -> V_29 , L_7 ) ;
else {
V_15 = F_4 ( V_10 ) ;
if ( V_15 >= 0 ) {
V_31 = F_12 ( V_10 , V_15 ) ;
if ( V_31 ) {
F_11 ( & V_10 -> V_29 , L_8 ,
V_15 , V_31 ) ;
}
}
}
F_13 ( V_10 ) ;
return 0 ;
}
static void F_14 ( struct V_9 * V_10 )
{
F_15 ( V_10 ) ;
if ( V_10 -> V_33 )
F_12 ( V_10 , - 1 ) ;
}
static int F_16 ( struct V_9 * V_10 , T_1 V_34 )
{
int V_35 ;
if ( ! V_10 -> V_36 )
V_35 = F_17 ( V_10 , V_34 ) ;
else if ( V_34 . V_37 == V_38 || V_34 . V_37 == V_39 )
V_35 = 0 ;
else
V_35 = F_18 ( V_10 , V_34 ) ;
return V_35 ;
}
static int F_19 ( struct V_9 * V_10 , T_1 V_34 )
{
int V_35 ;
if ( ! V_10 -> V_36 )
V_35 = F_20 ( V_10 , V_34 ) ;
else
V_35 = F_21 ( V_10 , V_34 ) ;
return V_35 ;
}
