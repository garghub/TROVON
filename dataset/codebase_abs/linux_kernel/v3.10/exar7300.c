void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , 0 ) ;
F_2 ( V_2 , V_4 , 0 ) ;
F_2 ( V_2 , V_5 , 0 ) ;
F_2 ( V_2 , V_6 ,
V_7 |
V_8 ) ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_9 )
{
T_1 V_10 ;
switch ( V_9 ) {
case V_8 :
case V_11 :
case V_12 :
case V_13 :
break;
default:
return;
}
V_10 = F_4 ( V_2 , V_6 ) ;
V_10 &= ~ ( V_14 | V_15 ) ;
V_10 |= V_9 ;
F_2 ( V_2 , V_6 , V_10 ) ;
}
void F_5 ( struct V_1 * V_2 , T_1 type )
{
T_1 V_10 ;
switch ( type ) {
case V_16 :
case V_17 :
case V_18 :
case V_19 :
break;
default:
return;
}
V_10 = F_4 ( V_2 , V_6 ) ;
V_10 &= ~ ( V_7 |
V_20 ) ;
switch ( type ) {
case V_16 :
case V_17 :
V_10 |= V_7 ;
break;
case V_18 :
case V_19 :
V_10 |= V_20 ;
break;
default:
return;
}
F_2 ( V_2 , V_6 , V_10 ) ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_9 )
{
if ( V_2 -> V_21 . V_22 == V_9 )
return;
switch ( V_9 ) {
case V_23 :
F_7 ( V_2 , V_3 ,
V_24 ) ;
break;
case V_25 :
F_8 ( V_2 , V_3 ,
V_24 ) ;
break;
default:
return;
}
V_2 -> V_21 . V_22 = V_9 ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_9 )
{
if ( V_2 -> V_21 . V_26 == V_9 )
return;
switch ( V_9 ) {
case V_25 :
F_7 ( V_2 , V_4 ,
V_27 ) ;
break;
case V_23 :
F_8 ( V_2 , V_4 ,
V_27 ) ;
break;
default:
return;
}
V_2 -> V_21 . V_26 = V_9 ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_9 )
{
if ( V_2 -> V_21 . V_28 == V_9 )
return;
switch ( V_9 ) {
case V_25 :
F_7 ( V_2 , V_3 ,
V_29 ) ;
F_9 ( V_2 , V_25 ) ;
break;
case V_23 :
F_8 ( V_2 , V_3 ,
V_29 ) ;
F_9 ( V_2 , V_23 ) ;
break;
default:
return;
}
V_2 -> V_21 . V_28 = V_9 ;
}
void F_11 ( struct V_1 * V_2 , T_1 V_9 )
{
switch ( V_9 ) {
case V_25 :
F_8 ( V_2 , V_5 ,
V_30 ) ;
F_8 ( V_2 , V_3 ,
V_31 ) ;
break;
case V_23 :
F_7 ( V_2 , V_5 ,
V_30 ) ;
F_7 ( V_2 , V_3 ,
V_31 ) ;
break;
}
}
