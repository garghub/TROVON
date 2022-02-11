static int F_1 ( struct V_1 * * V_2 ,
struct V_3 * V_4 , T_1 type )
{
struct V_1 * V_1 ;
if ( type == V_5 )
V_1 = F_2 ( V_4 -> V_6 . V_7 . V_8 ,
V_9 ) ;
else
V_1 = F_2 ( 0 , V_9 ) ;
if ( ! V_1 )
goto V_10;
F_3 ( V_4 , V_1 , V_11 , 0 ) ;
if ( V_1 -> V_12 > 0 ) {
V_1 -> V_13 = F_4 ( V_1 -> V_12 ,
V_9 ) ;
if ( ! V_1 -> V_13 )
goto V_14;
}
V_1 -> V_15 = F_5 ( & V_4 -> V_6 . V_7 . V_16 , 8 ,
V_9 ) ;
if ( ! V_1 -> V_15 )
goto V_17;
V_1 -> V_18 |= V_4 -> V_19 . V_20 == V_21 ?
V_22 : V_23 ;
* V_2 = V_1 ;
return 0 ;
V_17:
F_6 ( V_1 -> V_13 ) ;
V_1 -> V_13 = NULL ;
V_14:
F_7 ( V_1 ) ;
V_10:
return - V_24 ;
}
static int F_8 ( struct V_25 * V_26 ,
struct V_3 * V_4 )
{
unsigned long V_27 ;
struct V_2 * V_28 ;
F_9 ( & V_26 -> V_29 , V_27 ) ;
F_10 (urb_p, &udc->urb_queue, urb_entry) {
if ( V_28 -> V_30 != V_4 -> V_6 . V_31 . V_30 )
continue;
V_28 -> V_1 -> V_32 = - V_33 ;
V_28 -> V_30 = V_4 -> V_19 . V_30 ;
F_11 ( V_26 , V_34 ) ;
F_12 ( & V_26 -> V_29 , V_27 ) ;
return 0 ;
}
F_13 ( & V_26 -> V_35 ) ;
F_14 ( V_26 , V_4 -> V_19 . V_30 , 0 ) ;
F_15 ( & V_26 -> V_36 ) ;
F_16 ( & V_26 -> V_35 ) ;
F_12 ( & V_26 -> V_29 , V_27 ) ;
return 0 ;
}
static int F_17 ( struct V_25 * V_26 ,
struct V_3 * V_4 )
{
int V_37 = 0 ;
struct V_2 * V_28 ;
T_1 V_38 ;
unsigned long V_27 ;
V_28 = F_18 () ;
if ( ! V_28 ) {
F_19 ( & V_26 -> V_39 , V_40 ) ;
return - V_24 ;
}
V_38 = V_4 -> V_19 . V_41 ;
if ( V_4 -> V_19 . V_20 == V_21 )
V_38 |= V_22 ;
F_20 ( & V_26 -> V_29 ) ;
V_28 -> V_41 = F_21 ( V_26 , V_38 ) ;
if ( ! V_28 -> V_41 ) {
F_22 ( & V_26 -> V_42 -> V_43 , L_1 ) ;
F_23 ( & V_26 -> V_29 ) ;
F_19 ( & V_26 -> V_39 , V_44 ) ;
V_37 = - V_45 ;
goto V_46;
}
V_28 -> type = V_28 -> V_41 -> type ;
F_23 ( & V_26 -> V_29 ) ;
V_28 -> V_47 = 1 ;
V_28 -> V_30 = V_4 -> V_19 . V_30 ;
V_37 = F_1 ( & V_28 -> V_1 , V_4 , V_28 -> V_41 -> type ) ;
if ( V_37 ) {
F_19 ( & V_26 -> V_39 , V_40 ) ;
V_37 = - V_24 ;
goto V_46;
}
V_28 -> V_1 -> V_48 = - V_49 ;
V_28 -> V_1 -> V_18 &= ~ ( 11 << 30 ) ;
switch ( V_28 -> V_41 -> type ) {
case V_50 :
V_28 -> V_1 -> V_18 |= ( V_51 << 30 ) ;
break;
case V_52 :
V_28 -> V_1 -> V_18 |= ( V_53 << 30 ) ;
break;
case V_54 :
V_28 -> V_1 -> V_18 |= ( V_55 << 30 ) ;
break;
case V_5 :
V_28 -> V_1 -> V_18 |= ( V_56 << 30 ) ;
break;
}
V_37 = F_24 ( & V_26 -> V_39 , V_28 -> V_1 ) ;
if ( V_37 < 0 )
goto V_46;
V_37 = F_25 ( & V_26 -> V_39 , V_28 -> V_1 ) ;
if ( V_37 < 0 )
goto V_46;
F_9 ( & V_26 -> V_29 , V_27 ) ;
F_11 ( V_26 , V_34 ) ;
F_26 ( & V_28 -> V_57 , & V_26 -> V_58 ) ;
F_12 ( & V_26 -> V_29 , V_27 ) ;
return 0 ;
V_46:
F_27 ( V_28 ) ;
return V_37 ;
}
static int F_28 ( struct V_59 * V_39 )
{
int V_37 ;
struct V_3 V_4 ;
struct V_25 * V_26 = F_29 ( V_39 , struct V_25 , V_39 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_37 = F_30 ( V_39 -> V_60 , & V_4 , sizeof( V_4 ) ) ;
if ( V_37 != sizeof( V_4 ) ) {
F_19 ( V_39 , V_44 ) ;
if ( V_37 >= 0 )
return - V_45 ;
return V_37 ;
}
F_31 ( & V_4 , 0 ) ;
F_20 ( & V_39 -> V_29 ) ;
V_37 = ( V_39 -> V_48 == V_61 ) ;
F_23 ( & V_39 -> V_29 ) ;
if ( ! V_37 ) {
F_19 ( V_39 , V_44 ) ;
return - V_62 ;
}
switch ( V_4 . V_19 . V_63 ) {
case V_64 :
V_37 = F_8 ( V_26 , & V_4 ) ;
break;
case V_11 :
V_37 = F_17 ( V_26 , & V_4 ) ;
break;
default:
V_37 = - V_45 ;
F_32 ( L_2 ) ;
break;
}
return V_37 ;
}
int F_33 ( void * V_65 )
{
struct V_59 * V_39 = V_65 ;
int V_37 = 0 ;
while ( ! F_34 () ) {
if ( F_35 ( V_39 ) )
break;
V_37 = F_28 ( V_39 ) ;
if ( V_37 < 0 ) {
F_36 ( L_3 , V_37 ) ;
break;
}
}
return V_37 ;
}
