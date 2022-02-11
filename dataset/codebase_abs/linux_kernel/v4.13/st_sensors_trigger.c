static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
int V_6 ;
if ( ! V_4 -> V_7 -> V_8 . V_9 )
return - V_10 ;
if ( ! V_2 -> V_11 )
return 0 ;
V_6 = V_4 -> V_12 -> V_13 ( & V_4 -> V_14 , V_4 -> V_15 ,
V_4 -> V_7 -> V_8 . V_9 ,
& V_5 ) ;
if ( V_6 < 0 ) {
F_2 ( V_4 -> V_15 ,
L_1 ) ;
return V_6 ;
}
V_5 &= 0x07 ;
if ( V_5 & ( T_1 ) V_2 -> V_11 [ 0 ] )
return 1 ;
return 0 ;
}
static T_2 F_3 ( int V_16 , void * V_17 )
{
struct V_18 * V_19 = V_17 ;
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
V_4 -> V_20 = F_6 ( V_2 ) ;
return V_21 ;
}
static T_2 F_7 ( int V_16 , void * V_17 )
{
struct V_18 * V_19 = V_17 ;
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
if ( V_4 -> V_22 &&
F_1 ( V_2 , V_4 ) ) {
F_8 ( V_17 ) ;
} else {
F_9 ( V_4 -> V_15 , L_2 ) ;
return V_23 ;
}
if ( ! V_4 -> V_24 )
return V_25 ;
while ( V_4 -> V_22 &&
F_1 ( V_2 , V_4 ) ) {
F_9 ( V_4 -> V_15 , L_3 ) ;
V_4 -> V_20 = F_6 ( V_2 ) ;
F_8 ( V_17 ) ;
}
return V_25 ;
}
int F_10 ( struct V_1 * V_2 ,
const struct V_26 * V_27 )
{
int V_28 , V_16 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
unsigned long V_29 ;
V_4 -> V_19 = F_11 ( L_4 , V_2 -> V_30 ) ;
if ( V_4 -> V_19 == NULL ) {
F_2 ( & V_2 -> V_15 , L_5 ) ;
return - V_31 ;
}
F_12 ( V_4 -> V_19 , V_2 ) ;
V_4 -> V_19 -> V_32 = V_27 ;
V_4 -> V_19 -> V_15 . V_33 = V_4 -> V_15 ;
V_16 = V_4 -> V_34 ( V_2 ) ;
V_29 = F_13 ( F_14 ( V_16 ) ) ;
switch( V_29 ) {
case V_35 :
case V_36 :
if ( ! V_4 -> V_7 -> V_8 . V_37 ) {
F_2 ( & V_2 -> V_15 ,
L_6
L_7
L_8 ) ;
if ( V_29 == V_35 )
V_29 = V_38 ;
if ( V_29 == V_36 )
V_29 = V_39 ;
} else {
V_28 = F_15 ( V_2 ,
V_4 -> V_7 -> V_8 . V_37 ,
V_4 -> V_7 -> V_8 . V_40 , 1 ) ;
if ( V_28 < 0 )
goto V_41;
F_16 ( & V_2 -> V_15 ,
L_9
L_10 ) ;
}
break;
case V_38 :
F_16 ( & V_2 -> V_15 ,
L_11 ) ;
break;
case V_39 :
F_16 ( & V_2 -> V_15 ,
L_12 ) ;
break;
default:
F_2 ( & V_2 -> V_15 ,
L_13
L_14 , V_29 ) ;
V_29 = V_38 ;
}
if ( V_29 == V_35 ||
V_29 == V_38 )
V_4 -> V_24 = true ;
else
V_29 |= V_42 ;
if ( V_4 -> V_43 &&
V_4 -> V_7 -> V_8 . V_9 )
V_29 |= V_44 ;
V_28 = F_17 ( V_4 -> V_34 ( V_2 ) ,
F_3 ,
F_7 ,
V_29 ,
V_4 -> V_19 -> V_30 ,
V_4 -> V_19 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_15 , L_15 ) ;
goto V_41;
}
V_28 = F_18 ( V_4 -> V_19 ) ;
if ( V_28 < 0 ) {
F_2 ( & V_2 -> V_15 , L_16 ) ;
goto V_45;
}
V_2 -> V_19 = F_19 ( V_4 -> V_19 ) ;
return 0 ;
V_45:
F_20 ( V_4 -> V_34 ( V_2 ) , V_4 -> V_19 ) ;
V_41:
V_41 ( V_4 -> V_19 ) ;
return V_28 ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
F_22 ( V_4 -> V_19 ) ;
F_20 ( V_4 -> V_34 ( V_2 ) , V_4 -> V_19 ) ;
V_41 ( V_4 -> V_19 ) ;
}
int F_23 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_1 * V_46 = F_4 ( V_19 ) ;
if ( V_46 != V_2 )
return - V_10 ;
return 0 ;
}
