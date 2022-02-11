static int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_3 ;
int V_10 , V_11 ;
V_10 = V_5 -> V_12 . V_13 . V_14 ;
V_11 = V_5 -> V_12 . V_13 . V_15 ;
F_3 ( L_1 , V_10 , V_11 ) ;
if ( V_10 || V_11 ) {
V_10 = V_10 * 0xff / 0xffff ;
V_11 = V_11 * 0xff / 0xffff ;
if ( V_11 == 0x0a )
V_11 = 0x0b ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0x51 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 1 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 2 ] = V_11 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 4 ] = V_10 ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0xfa ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 1 ] = 0xfe ;
} else {
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0xf3 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 1 ] = 0x00 ;
}
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 2 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 4 ] = 0x00 ;
F_3 ( L_2 , V_10 , V_11 ) ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_20 * V_16 ;
struct V_21 * V_22 = F_6 ( & V_7 -> V_23 ,
struct V_21 , V_24 ) ;
struct V_25 * V_26 =
& V_7 -> V_27 [ V_28 ] . V_26 ;
struct V_1 * V_2 = V_22 -> V_29 ;
int error ;
if ( F_7 ( V_26 ) ) {
F_8 ( V_7 , L_3 ) ;
return - V_30 ;
}
V_16 = F_6 ( V_26 , struct V_20 , V_24 ) ;
if ( V_16 -> V_31 < 1 ) {
F_8 ( V_7 , L_4 ) ;
return - V_30 ;
}
if ( V_16 -> V_17 [ 0 ] -> V_32 < 7 ) {
F_8 ( V_7 , L_5 ) ;
return - V_30 ;
}
V_9 = F_9 ( sizeof( struct V_8 ) , V_33 ) ;
if ( ! V_9 )
return - V_34 ;
F_10 ( V_35 , V_2 -> V_36 ) ;
error = F_11 ( V_2 , V_9 , F_1 ) ;
if ( error ) {
F_12 ( V_9 ) ;
return error ;
}
V_9 -> V_16 = V_16 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0xf3 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 1 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 2 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 3 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 4 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 5 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 6 ] = 0x00 ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
F_13 ( V_7 , L_6
L_7 ) ;
return 0 ;
}
static inline int F_5 ( struct V_6 * V_7 )
{
return 0 ;
}
static T_1 * F_14 ( struct V_6 * V_37 , T_1 * V_38 ,
unsigned int * V_39 )
{
switch ( V_37 -> V_40 ) {
case 0x0011 :
if ( * V_39 == V_41 ) {
V_38 = V_42 ;
* V_39 = sizeof( V_42 ) ;
}
break;
}
return V_38 ;
}
static int F_15 ( struct V_6 * V_37 , struct V_21 * V_43 ,
struct V_44 * V_17 , struct V_45 * V_46 ,
unsigned long * * V_47 , int * V_48 )
{
switch ( V_46 -> V_7 ) {
case V_49 : case V_50 : case V_51 :
case V_52 : case V_53 : case V_54 :
if ( V_17 -> V_55 & V_56 )
F_16 ( V_46 -> V_7 & 0xf ) ;
else
F_17 ( V_46 -> V_7 & 0xf ) ;
return 1 ;
}
return 0 ;
}
static int F_18 ( struct V_6 * V_37 , const struct V_57 * V_58 )
{
int V_59 ;
F_19 ( & V_37 -> V_2 , L_8 ) ;
V_59 = F_20 ( V_37 ) ;
if ( V_59 ) {
F_8 ( V_37 , L_9 ) ;
goto V_60;
}
V_59 = F_21 ( V_37 , V_61 & ~ V_62 ) ;
if ( V_59 ) {
F_8 ( V_37 , L_10 ) ;
goto V_60;
}
switch ( V_37 -> V_40 ) {
case 0x0006 :
V_59 = F_5 ( V_37 ) ;
if ( V_59 ) {
F_22 ( & V_37 -> V_2 , L_11 ) ;
F_23 ( V_37 ) ;
goto V_60;
}
break;
}
return 0 ;
V_60:
return V_59 ;
}
