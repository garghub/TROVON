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
static T_1 F_2 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
while ( F_3 ( V_5 -> V_6 & F_4 ( V_2 -> V_3 ) ) ) {
if ( F_1 ( V_2 ) ) {
break;
}
}
return V_7 [ V_2 -> V_3 ] ;
}
T_1 F_5 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = V_5 -> V_11 ;
T_2 * V_12 ;
if ( V_11 -> V_13 . V_14 < V_15 )
return 0 ;
if ( ! F_6 ( V_9 -> V_16 ) ) {
V_2 -> V_3 = 7 ;
return V_7 [ V_2 -> V_3 ] ;
}
if ( ! F_7 ( V_9 -> V_16 ) ) {
V_2 -> V_3 = 0 ;
return V_7 [ V_2 -> V_3 ] ;
}
V_12 = F_8 ( V_9 ) ;
V_2 -> V_3 = * V_12 & V_17 ;
return F_2 ( V_5 , V_2 ) ;
}
T_1 F_9 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_10 * V_11 = V_5 -> V_11 ;
struct V_18 * V_19 = NULL ;
const T_2 * V_20 = NULL ;
bool V_21 = false ;
if ( V_11 -> V_13 . V_14 < V_15 || V_2 -> V_22 < 6 ) {
V_2 -> V_3 = 0 ;
return 0 ;
}
F_10 () ;
switch ( V_5 -> V_23 . type ) {
case V_24 :
V_19 = F_11 ( V_5 -> V_25 . V_26 . V_19 ) ;
if ( V_19 ) {
V_21 = F_12 ( V_19 , V_27 ) ;
break;
}
case V_28 :
V_20 = V_2 -> V_29 ;
break;
case V_30 :
V_20 = V_5 -> V_25 . V_31 . V_32 ;
break;
#ifdef F_13
case V_33 :
V_21 = true ;
break;
#endif
case V_34 :
V_20 = V_5 -> V_25 . V_35 . V_36 ;
break;
case V_37 :
V_20 = V_2 -> V_29 ;
break;
default:
break;
}
if ( ! V_19 && V_20 && ! F_14 ( V_20 ) ) {
V_19 = F_15 ( V_5 , V_20 ) ;
if ( V_19 )
V_21 = F_12 ( V_19 , V_27 ) ;
}
F_16 () ;
if ( ! V_21 ) {
V_2 -> V_3 = 0 ;
return V_38 ;
}
V_2 -> V_3 = F_17 ( V_2 ) ;
return F_2 ( V_5 , V_2 ) ;
}
void F_18 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = ( void * ) V_2 -> V_29 ;
struct V_39 * V_40 = F_19 ( V_2 ) ;
T_2 * V_12 ;
T_2 V_41 , V_42 ;
if ( ! F_7 ( V_9 -> V_16 ) )
return;
V_12 = F_8 ( V_9 ) ;
V_42 = V_2 -> V_3 & V_17 ;
V_41 = * V_12 & V_43 ;
if ( F_14 ( V_9 -> V_44 ) ||
V_5 -> V_45 & F_4 ( V_42 ) ) {
V_41 |= V_46 ;
V_40 -> V_47 |= V_48 ;
}
* V_12 ++ = V_41 | V_42 ;
* V_12 = F_20 ( & V_5 -> V_23 ) ?
( V_49 >> 8 ) : 0 ;
}
