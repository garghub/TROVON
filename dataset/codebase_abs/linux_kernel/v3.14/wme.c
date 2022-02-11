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
struct V_22 * V_23 ;
if ( V_11 -> V_13 . V_14 < V_15 || V_2 -> V_24 < 6 ) {
V_2 -> V_3 = 0 ;
return 0 ;
}
F_10 () ;
switch ( V_5 -> V_25 . type ) {
case V_26 :
V_19 = F_11 ( V_5 -> V_27 . V_28 . V_19 ) ;
if ( V_19 ) {
V_21 = F_12 ( V_19 , V_29 ) ;
break;
}
case V_30 :
V_20 = V_2 -> V_31 ;
break;
case V_32 :
V_20 = V_5 -> V_27 . V_33 . V_34 ;
break;
#ifdef F_13
case V_35 :
V_21 = true ;
break;
#endif
case V_36 :
V_20 = V_5 -> V_27 . V_37 . V_38 ;
break;
case V_39 :
V_20 = V_2 -> V_31 ;
break;
default:
break;
}
if ( ! V_19 && V_20 && ! F_14 ( V_20 ) ) {
V_19 = F_15 ( V_5 , V_20 ) ;
if ( V_19 )
V_21 = F_12 ( V_19 , V_29 ) ;
}
F_16 () ;
if ( ! V_21 ) {
V_2 -> V_3 = 0 ;
return V_40 ;
}
if ( V_2 -> V_41 == V_5 -> V_42 ) {
V_2 -> V_3 = 7 ;
return F_2 ( V_5 , V_2 ) ;
}
F_10 () ;
V_23 = F_11 ( V_5 -> V_23 ) ;
V_2 -> V_3 = F_17 ( V_2 , V_23 ?
& V_23 -> V_23 : NULL ) ;
F_16 () ;
return F_2 ( V_5 , V_2 ) ;
}
void F_18 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = ( void * ) V_2 -> V_31 ;
struct V_43 * V_44 = F_19 ( V_2 ) ;
T_2 * V_12 ;
T_2 V_45 , V_46 ;
if ( ! F_7 ( V_9 -> V_16 ) )
return;
V_12 = F_8 ( V_9 ) ;
V_46 = V_2 -> V_3 & V_17 ;
V_45 = * V_12 & V_47 ;
if ( F_14 ( V_9 -> V_48 ) ||
V_5 -> V_49 & F_4 ( V_46 ) ) {
V_45 |= V_50 ;
V_44 -> V_51 |= V_52 ;
}
* V_12 ++ = V_45 | V_46 ;
if ( F_20 ( & V_5 -> V_25 ) ) {
* V_12 &= ( ( V_53 |
V_54 ) >> 8 ) ;
if ( ! F_21 ( V_9 -> V_16 ) )
* V_12 |= ( V_55 >> 8 ) ;
} else {
* V_12 = 0 ;
}
}
