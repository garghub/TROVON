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
union V_5 V_6 ;
V_6 . V_7 = V_4 ;
#ifdef F_7
V_6 . V_8 [ 0 ] ^= 0x80000000 ;
#else
V_6 . V_8 [ 1 ] ^= 0x80000000 ;
#endif
return V_6 . V_7 ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_1 V_4 )
{
union V_5 V_6 ;
V_6 . V_7 = V_4 ;
#ifdef F_7
V_6 . V_8 [ 0 ] &= 0x7fffffff ;
#else
V_6 . V_8 [ 1 ] &= 0x7fffffff ;
#endif
return V_6 . V_7 ;
}
unsigned int F_9 ( struct V_1 * V_2 , const unsigned int V_9 , T_2 * V_10 )
{
T_3 * V_11 = F_10 () ;
T_1 V_4 ;
unsigned int V_12 , V_13 ;
V_12 = F_11 ( V_9 ) ;
if ( F_12 ( V_9 ) ) {
V_4 = F_13 ( V_12 ) ;
} else {
switch ( V_11 -> V_14 [ V_12 ] ) {
case V_15 :
V_4 = F_14 ( V_11 -> V_16 [ V_12 ] . V_17 ) ;
break;
case V_18 :
V_4 = V_11 -> V_16 [ V_12 ] . V_19 ;
break;
default:
return 0 ;
}
}
V_13 = ( V_9 & V_20 ) >> 20 ;
if ( ! F_15 ( V_9 ) ) {
unsigned int V_21 = F_16 ( V_9 ) ;
T_1 V_3 ;
switch ( V_11 -> V_14 [ V_21 ] ) {
case V_15 :
V_3 = F_14 ( V_11 -> V_16 [ V_21 ] . V_17 ) ;
break;
case V_18 :
V_3 = V_11 -> V_16 [ V_21 ] . V_19 ;
break;
default:
return 0 ;
}
if ( V_22 [ V_13 ] ) {
V_10 -> V_19 = V_22 [ V_13 ] ( V_2 , V_3 , V_4 ) ;
} else {
return 0 ;
}
} else {
if ( V_23 [ V_13 ] ) {
V_10 -> V_19 = V_23 [ V_13 ] ( V_2 , V_4 ) ;
} else {
return 0 ;
}
}
return 1 ;
}
