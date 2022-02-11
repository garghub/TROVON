static int F_1 ( struct V_1 * V_2 ,
unsigned long const * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 , V_7 ;
V_7 = 0 ;
F_3 (bit, active_scan_mask, ADC108S102_MAX_CHANNELS)
V_5 -> V_8 [ V_7 ++ ] = F_4 ( F_5 ( V_6 ) ) ;
V_5 -> V_8 [ V_7 ++ ] = 0x00 ;
V_5 -> V_9 . V_8 = & V_5 -> V_8 [ 0 ] ;
V_5 -> V_9 . V_10 = & V_5 -> V_10 [ 0 ] ;
V_5 -> V_9 . V_11 = V_7 * sizeof( V_5 -> V_8 [ 0 ] ) ;
F_6 ( & V_5 -> V_12 , & V_5 -> V_9 , 1 ) ;
return 0 ;
}
static T_1 F_7 ( int V_13 , void * V_14 )
{
struct V_15 * V_16 = V_14 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_17 ;
V_17 = F_8 ( V_5 -> V_18 , & V_5 -> V_12 ) ;
if ( V_17 < 0 )
goto V_19;
F_9 ( V_2 ,
( V_20 * ) & V_5 -> V_10 [ 1 ] ,
F_10 ( V_2 ) ) ;
V_19:
F_11 ( V_2 -> V_21 ) ;
return V_22 ;
}
static int F_12 ( struct V_4 * V_5 , unsigned int V_23 )
{
int V_17 ;
V_5 -> V_8 [ 0 ] = F_4 ( F_5 ( V_23 ) ) ;
V_17 = F_8 ( V_5 -> V_18 , & V_5 -> V_24 ) ;
if ( V_17 )
return V_17 ;
return F_13 ( V_5 -> V_10 [ 1 ] ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_25 const * V_26 ,
int * V_27 , int * V_28 , long V_29 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_17 ;
switch ( V_29 ) {
case V_30 :
V_17 = F_15 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_12 ( V_5 , V_26 -> V_31 ) ;
F_16 ( V_2 ) ;
if ( V_17 < 0 )
return V_17 ;
* V_27 = F_17 ( V_17 ) ;
return V_32 ;
case V_33 :
if ( V_26 -> type != V_34 )
break;
* V_27 = V_5 -> V_35 ;
* V_28 = V_26 -> V_36 . V_37 ;
return V_38 ;
default:
break;
}
return - V_39 ;
}
static int F_18 ( struct V_40 * V_18 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_19 ( & V_18 -> V_41 , sizeof( * V_5 ) ) ;
if ( ! V_2 )
return - V_42 ;
V_5 = F_2 ( V_2 ) ;
if ( F_20 ( & V_18 -> V_41 ) ) {
V_5 -> V_35 = V_43 ;
} else {
V_5 -> V_44 = F_21 ( & V_18 -> V_41 , L_1 ) ;
if ( F_22 ( V_5 -> V_44 ) )
return F_23 ( V_5 -> V_44 ) ;
V_17 = F_24 ( V_5 -> V_44 ) ;
if ( V_17 < 0 ) {
F_25 ( & V_18 -> V_41 , L_2 ) ;
return V_17 ;
}
V_17 = F_26 ( V_5 -> V_44 ) ;
if ( V_17 < 0 ) {
F_25 ( & V_18 -> V_41 , L_3 ) ;
return V_17 ;
}
V_5 -> V_35 = V_17 / 1000 ;
}
F_27 ( V_18 , V_2 ) ;
V_5 -> V_18 = V_18 ;
V_2 -> V_45 = V_18 -> V_46 ;
V_2 -> V_41 . V_47 = & V_18 -> V_41 ;
V_2 -> V_48 = V_49 ;
V_2 -> V_50 = V_51 ;
V_2 -> V_52 = F_28 ( V_51 ) ;
V_2 -> V_53 = & V_54 ;
V_5 -> V_55 . V_8 = V_5 -> V_8 ;
V_5 -> V_55 . V_10 = V_5 -> V_10 ;
V_5 -> V_55 . V_11 = 2 * sizeof( V_5 -> V_8 [ 0 ] ) ;
F_6 ( & V_5 -> V_24 ,
& V_5 -> V_55 , 1 ) ;
V_17 = F_29 ( V_2 , NULL ,
& F_7 , NULL ) ;
if ( V_17 )
goto V_56;
V_17 = F_30 ( V_2 ) ;
if ( V_17 ) {
F_25 ( & V_18 -> V_41 , L_4 ) ;
goto V_57;
}
return 0 ;
V_57:
F_31 ( V_2 ) ;
V_56:
F_32 ( V_5 -> V_44 ) ;
return V_17 ;
}
static int F_33 ( struct V_40 * V_18 )
{
struct V_1 * V_2 = F_34 ( V_18 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_35 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_5 -> V_44 ) ;
return 0 ;
}
