static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 , V_4 , V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_4 ( V_2 , V_4 , V_3 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_4 )
{
return V_4 ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_4 )
{
V_4 . V_5 ^= 0x8000 ;
return V_4 ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_4 )
{
V_4 . V_5 &= 0x7fff ;
return V_4 ;
}
unsigned int F_8 ( struct V_1 * V_2 , const unsigned int V_6 , T_2 * V_7 )
{
T_3 * V_8 = F_9 () ;
T_1 V_4 ;
unsigned int V_9 , V_10 ;
V_9 = F_10 ( V_6 ) ;
if ( F_11 ( V_6 ) ) {
V_4 = F_12 ( V_9 ) ;
} else {
switch ( V_8 -> V_11 [ V_9 ] ) {
case V_12 :
V_4 = F_13 ( V_8 -> V_13 [ V_9 ] . V_14 ) ;
break;
case V_15 :
V_4 = F_14 ( V_8 -> V_13 [ V_9 ] . V_16 ) ;
break;
case V_17 :
V_4 = V_8 -> V_13 [ V_9 ] . V_18 ;
break;
default:
return 0 ;
}
}
V_10 = ( V_6 & V_19 ) >> 20 ;
if ( ! F_15 ( V_6 ) ) {
unsigned int V_20 = F_16 ( V_6 ) ;
T_1 V_3 ;
switch ( V_8 -> V_11 [ V_20 ] ) {
case V_12 :
V_3 = F_13 ( V_8 -> V_13 [ V_20 ] . V_14 ) ;
break;
case V_15 :
V_3 = F_14 ( V_8 -> V_13 [ V_20 ] . V_16 ) ;
break;
case V_17 :
V_3 = V_8 -> V_13 [ V_20 ] . V_18 ;
break;
default:
return 0 ;
}
if ( V_21 [ V_10 ] ) {
V_7 -> V_18 = V_21 [ V_10 ] ( V_2 , V_3 , V_4 ) ;
} else {
return 0 ;
}
} else {
if ( V_22 [ V_10 ] ) {
V_7 -> V_18 = V_22 [ V_10 ] ( V_2 , V_4 ) ;
} else {
return 0 ;
}
}
return 1 ;
}
