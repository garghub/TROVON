static int F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_7 ;
F_2 ( & V_5 -> V_8 , V_7 ) ;
V_5 -> V_9 [ V_5 -> V_10 ] = V_3 ;
V_5 -> V_10 = ( V_5 -> V_10 + 1 ) % V_11 ;
if ( V_5 -> V_10 == V_5 -> V_12 )
F_3 ( V_13 . V_14 ,
L_1 ) ;
F_4 ( & V_5 -> V_8 , V_7 ) ;
F_5 ( & V_5 -> V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
struct V_4 * V_5 ;
V_5 = F_7 ( sizeof( struct V_4 ) , V_18 ) ;
if ( ! V_5 )
return - V_19 ;
F_8 ( & V_5 -> V_20 ) ;
F_9 ( & V_5 -> V_8 ) ;
F_10 ( & V_5 -> V_15 ) ;
V_5 -> V_1 = F_7 ( sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_5 -> V_1 ) {
F_11 ( V_5 ) ;
return - V_19 ;
}
V_5 -> V_1 -> V_21 = F_1 ;
V_5 -> V_1 -> V_6 = V_5 ;
V_17 -> V_22 = V_5 ;
return 0 ;
}
static int F_12 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
struct V_4 * V_5 = V_17 -> V_22 ;
if ( V_5 -> V_23 ) {
F_13 ( V_5 -> V_1 ) ;
} else {
F_11 ( V_5 -> V_1 ) ;
}
F_11 ( V_5 ) ;
return 0 ;
}
static T_1 F_14 ( struct V_17 * V_17 , char T_2 * V_24 ,
T_3 V_25 , T_4 * V_26 )
{
struct V_4 * V_5 = V_17 -> V_22 ;
int error ;
T_3 V_27 , V_28 ;
unsigned char V_9 [ V_11 ] ;
unsigned long V_7 ;
for (; ; ) {
F_2 ( & V_5 -> V_8 , V_7 ) ;
V_27 = F_15 ( V_5 -> V_10 ,
V_5 -> V_12 ,
V_11 ) ;
V_28 = F_16 ( V_27 , V_25 ) ;
if ( V_28 ) {
memcpy ( V_9 , & V_5 -> V_9 [ V_5 -> V_12 ] , V_28 ) ;
V_5 -> V_12 = ( V_5 -> V_12 + V_28 ) %
V_11 ;
}
F_4 ( & V_5 -> V_8 , V_7 ) ;
if ( V_27 )
break;
if ( V_17 -> V_29 & V_30 )
return - V_31 ;
if ( V_25 == 0 )
return 0 ;
error = F_17 ( V_5 -> V_15 ,
V_5 -> V_10 != V_5 -> V_12 ) ;
if ( error )
return error ;
}
if ( V_28 )
if ( F_18 ( V_24 , V_9 , V_28 ) )
return - V_32 ;
return V_28 ;
}
static T_1 F_19 ( struct V_17 * V_17 , const char T_2 * V_33 ,
T_3 V_25 , T_4 * V_26 )
{
struct V_4 * V_5 = V_17 -> V_22 ;
struct V_34 V_35 ;
int error ;
if ( V_25 != sizeof( V_35 ) ) {
F_3 ( V_13 . V_14 , L_2 ) ;
return - V_36 ;
}
if ( F_20 ( & V_35 , V_33 , sizeof( V_35 ) ) )
return - V_32 ;
error = F_21 ( & V_5 -> V_20 ) ;
if ( error )
return error ;
switch ( V_35 . type ) {
case V_37 :
if ( ! V_5 -> V_1 -> V_2 . type ) {
F_3 ( V_13 . V_14 ,
L_3 ) ;
error = - V_36 ;
goto V_38;
}
if ( V_5 -> V_23 ) {
F_3 ( V_13 . V_14 ,
L_4 ) ;
error = - V_39 ;
goto V_38;
}
V_5 -> V_23 = true ;
F_22 ( V_5 -> V_1 ) ;
break;
case V_40 :
if ( V_5 -> V_23 ) {
F_3 ( V_13 . V_14 ,
L_5 ) ;
error = - V_39 ;
goto V_38;
}
V_5 -> V_1 -> V_2 . type = V_35 . V_41 ;
break;
case V_42 :
if ( ! V_5 -> V_23 ) {
F_3 ( V_13 . V_14 ,
L_6 ) ;
error = - V_43 ;
goto V_38;
}
F_23 ( V_5 -> V_1 , V_35 . V_41 , 0 ) ;
break;
default:
error = - V_44 ;
goto V_38;
}
V_38:
F_24 ( & V_5 -> V_20 ) ;
return error ? : V_25 ;
}
static unsigned int F_25 ( struct V_17 * V_17 , T_5 * V_45 )
{
struct V_4 * V_5 = V_17 -> V_22 ;
F_26 ( V_17 , & V_5 -> V_15 , V_45 ) ;
if ( V_5 -> V_10 != V_5 -> V_12 )
return V_46 | V_47 ;
return 0 ;
}
