static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
switch ( V_3 ) {
case 0 :
F_2 ( V_2 , L_1 ) ;
break;
case 1 :
F_2 ( V_2 , L_2 ) ;
break;
case 2 :
case 3 :
F_2 ( V_2 , L_3 ) ;
break;
case 4 :
V_4 = - 1 ;
break;
}
return V_4 ;
}
static int F_3 ( struct V_5 * V_6 , const struct V_7 * V_8 )
{
struct V_9 * V_10 = V_6 -> V_11 -> V_12 ;
struct V_1 * V_2 = & V_6 -> V_2 -> V_2 ;
int V_13 = - V_14 ;
T_1 V_15 ;
T_1 V_3 ;
int V_4 = - 1 ;
bool V_16 = false ;
if ( V_10 -> V_17 . V_18 != V_19 )
goto V_20;
V_15 = V_6 -> V_2 -> V_21 -> V_17 . V_22 ;
F_2 ( V_2 , L_4 , V_15 ) ;
V_3 = V_10 -> V_17 . V_23 ;
F_2 ( V_2 , L_5 , V_3 ) ;
if ( V_15 == 1 ) {
if ( V_6 -> V_11 -> V_24 == 2 )
V_10 = & V_6 -> V_11 -> V_4 [ 1 ] ;
else if ( V_6 -> V_11 -> V_24 > 2 )
goto V_20;
if ( V_10 -> V_17 . V_25 == 2 &&
F_4 ( & V_10 -> V_26 [ 0 ] . V_17 ) &&
F_5 ( & V_10 -> V_26 [ 1 ] . V_17 ) ) {
F_2 ( V_2 , L_6 ) ;
if ( V_6 -> V_11 -> V_24 == 1 )
V_13 = 0 ;
else
V_4 = 1 ;
}
goto V_20;
}
V_4 = 0 ;
switch ( V_8 -> V_27 ) {
case V_28 :
if ( V_15 < 3 || V_15 > 4 ) {
F_6 ( V_2 , L_7 , V_15 ) ;
V_4 = - 1 ;
goto V_20;
}
if ( V_3 == 0 ) {
F_2 ( V_2 , L_8 ) ;
V_4 = 1 ;
} else if ( V_3 == 2 )
F_2 ( V_2 , L_9 ) ;
else
V_4 = - 1 ;
break;
case V_29 :
if ( V_15 == 5 && V_8 -> V_30 == V_31 ) {
V_4 = F_1 ( V_2 , V_3 ) ;
goto V_20;
}
if ( V_15 < 3 || V_15 > 4 ) {
F_6 ( V_2 , L_7 , V_15 ) ;
V_4 = - 1 ;
goto V_20;
}
switch ( V_3 ) {
case 0 :
V_4 = - 1 ;
break;
case 1 :
F_2 ( V_2 , L_10 ) ;
break;
case 2 :
F_2 ( V_2 , L_9 ) ;
break;
case 3 :
F_2 ( V_2 , L_11 ) ;
break;
}
break;
case V_32 :
switch ( V_3 ) {
case 0 :
F_2 ( V_2 , L_12 ) ;
break;
case 2 :
F_2 ( V_2 , L_13 ) ;
break;
case 3 :
F_2 ( V_2 , L_9 ) ;
V_16 = true ;
break;
default:
V_4 = - 1 ;
break;
}
break;
case V_33 :
switch ( V_10 -> V_17 . V_34 ) {
case 0x07 :
case 0x37 :
case 0x67 :
case 0x08 :
case 0x38 :
case 0x68 :
case 0x09 :
case 0x39 :
case 0x69 :
case 0x16 :
case 0x46 :
case 0x76 :
V_4 = - 1 ;
break;
default:
F_2 ( V_2 , L_14 ,
V_10 -> V_17 . V_18 ,
V_10 -> V_17 . V_35 ,
V_10 -> V_17 . V_34 ) ;
}
break;
default:
F_6 ( V_2 , L_15 ,
V_8 -> V_27 ) ;
break;
}
V_20:
if ( V_4 >= 0 ) {
V_13 = F_7 ( V_6 -> V_2 , V_3 , V_4 ) ;
if ( V_13 < 0 ) {
F_6 ( V_2 ,
L_16 ,
V_13 ) ;
V_13 = - V_14 ;
}
}
if ( ! V_13 )
F_8 ( V_6 , ( void * ) ( unsigned long ) V_16 ) ;
return V_13 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_36 * V_37 ;
bool V_16 ;
V_37 = F_10 ( sizeof( * V_37 ) , V_38 ) ;
if ( ! V_37 )
return - V_39 ;
V_16 = ! ! ( unsigned long ) ( F_11 ( V_6 ) ) ;
if ( V_16 )
V_37 -> V_40 = 1 ;
F_12 ( & V_37 -> V_41 ) ;
F_8 ( V_6 , V_37 ) ;
return 0 ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_36 * V_42 = F_11 ( V_6 ) ;
F_8 ( V_6 , NULL ) ;
F_14 ( V_42 ) ;
}
