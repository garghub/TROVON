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
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_2 * V_8 ;
if ( V_5 -> V_9 . V_10 < 4 )
return 0 ;
if ( ! F_3 ( V_7 -> V_11 ) ) {
V_2 -> V_3 = 7 ;
return V_12 [ V_2 -> V_3 ] ;
}
if ( ! F_4 ( V_7 -> V_11 ) ) {
V_2 -> V_3 = 0 ;
return V_12 [ V_2 -> V_3 ] ;
}
V_8 = F_5 ( V_7 ) ;
V_2 -> V_3 = * V_8 & V_13 ;
return F_6 ( V_5 , V_2 ) ;
}
T_1 F_7 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 = V_15 -> V_5 ;
struct V_16 * V_17 = NULL ;
const T_2 * V_18 = NULL ;
bool V_19 = false ;
if ( V_5 -> V_9 . V_10 < 4 || V_2 -> V_20 < 6 ) {
V_2 -> V_3 = 0 ;
return F_8 ( T_1 , V_5 -> V_9 . V_10 - 1 , V_21 ) ;
}
F_9 () ;
switch ( V_15 -> V_22 . type ) {
case V_23 :
V_17 = F_10 ( V_15 -> V_24 . V_25 . V_17 ) ;
if ( V_17 ) {
V_19 = F_11 ( V_17 , V_26 ) ;
break;
}
case V_27 :
V_18 = V_2 -> V_28 ;
break;
case V_29 :
V_18 = V_15 -> V_24 . V_30 . V_31 ;
break;
#ifdef F_12
case V_32 :
V_19 = true ;
break;
#endif
case V_33 :
V_18 = V_15 -> V_24 . V_34 . V_35 ;
break;
case V_36 :
V_18 = V_2 -> V_28 ;
break;
default:
break;
}
if ( ! V_17 && V_18 && ! F_13 ( V_18 ) ) {
V_17 = F_14 ( V_15 , V_18 ) ;
if ( V_17 )
V_19 = F_11 ( V_17 , V_26 ) ;
}
F_15 () ;
if ( ! V_19 ) {
V_2 -> V_3 = 0 ;
return V_21 ;
}
V_2 -> V_3 = F_16 ( V_2 ) ;
return F_6 ( V_5 , V_2 ) ;
}
T_1 F_6 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
while ( F_17 ( V_5 -> V_37 & F_18 ( V_2 -> V_3 ) ) ) {
if ( F_1 ( V_2 ) ) {
break;
}
}
return V_12 [ V_2 -> V_3 ] ;
}
void F_19 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = ( void * ) V_2 -> V_28 ;
struct V_38 * V_39 = F_20 ( V_2 ) ;
if ( F_4 ( V_7 -> V_11 ) ) {
T_2 * V_8 = F_5 ( V_7 ) ;
T_2 V_40 , V_41 ;
V_41 = V_2 -> V_3 & V_13 ;
V_40 = * V_8 & V_42 ;
if ( F_13 ( V_7 -> V_43 ) ||
V_15 -> V_44 & F_18 ( V_41 ) ) {
V_40 |= V_45 ;
V_39 -> V_46 |= V_47 ;
}
* V_8 ++ = V_40 | V_41 ;
* V_8 = F_21 ( & V_15 -> V_22 ) ?
( V_48 >> 8 ) : 0 ;
}
}
