static int F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case 6 :
case 7 :
V_2 -> V_3 = 5 ;
return 0 ;
case 4 :
case 5 :
V_2 -> V_3 = 3 ;
return 0 ;
case 0 :
case 3 :
V_2 -> V_3 = 2 ;
return 0 ;
default:
return - 1 ;
}
}
T_1 F_2 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = NULL ;
const T_2 * V_10 = NULL ;
bool V_11 = false ;
if ( V_7 -> V_12 . V_13 < 4 || V_2 -> V_14 < 6 ) {
V_2 -> V_3 = 0 ;
return F_3 ( T_1 , V_7 -> V_12 . V_13 - 1 , V_15 ) ;
}
F_4 () ;
switch ( V_5 -> V_16 . type ) {
case V_17 :
V_9 = F_5 ( V_5 -> V_18 . V_19 . V_9 ) ;
if ( V_9 ) {
V_11 = F_6 ( V_9 ) & V_20 ;
break;
}
case V_21 :
V_10 = V_2 -> V_22 ;
break;
case V_23 :
V_10 = V_5 -> V_18 . V_24 . V_25 ;
break;
#ifdef F_7
case V_26 :
break;
#endif
case V_27 :
V_10 = V_5 -> V_18 . V_28 . V_29 ;
break;
case V_30 :
V_10 = V_2 -> V_22 ;
break;
default:
break;
}
if ( ! V_9 && V_10 && ! F_8 ( V_10 ) ) {
V_9 = F_9 ( V_5 , V_10 ) ;
if ( V_9 )
V_11 = F_6 ( V_9 ) & V_20 ;
}
F_10 () ;
if ( ! V_11 ) {
V_2 -> V_3 = 0 ;
return V_15 ;
}
V_2 -> V_3 = F_11 ( V_2 ) ;
return F_12 ( V_7 , V_2 ) ;
}
T_1 F_12 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
while ( F_13 ( V_7 -> V_31 & F_14 ( V_2 -> V_3 ) ) ) {
if ( F_1 ( V_2 ) ) {
break;
}
}
return V_32 [ V_2 -> V_3 ] ;
}
void F_15 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_33 * V_34 = ( void * ) V_2 -> V_22 ;
if ( F_16 ( V_34 -> V_35 ) ) {
T_2 * V_36 = F_17 ( V_34 ) ;
T_2 V_37 = 0 , V_38 ;
V_38 = V_2 -> V_3 & V_39 ;
if ( F_13 ( V_7 -> V_40 ) )
V_37 |= V_41 ;
* V_36 ++ = V_37 | V_38 ;
* V_36 = 0 ;
}
}
