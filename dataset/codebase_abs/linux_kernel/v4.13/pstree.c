union V_1 * F_1 ( union V_1 * V_2 , T_1 V_3 )
{
union V_1 * V_4 = NULL ;
const struct V_5 * V_6 ;
F_2 () ;
V_6 = F_3 ( V_2 -> V_7 . V_8 ) ;
if ( V_6 -> V_9 == V_10 ) {
return ( NULL ) ;
}
if ( ! ( V_6 -> V_11 & V_12 ) ) {
return ( NULL ) ;
}
V_4 = V_2 -> V_7 . V_13 . V_4 ;
while ( V_4 && V_3 ) {
V_3 -- ;
V_4 = V_4 -> V_7 . V_14 ;
}
return ( V_4 ) ;
}
void
F_4 ( union V_1 * V_2 , union V_1 * V_4 )
{
union V_1 * V_15 ;
const struct V_5 * V_6 ;
F_5 ( V_16 ) ;
if ( ! V_2 ) {
V_17 ;
}
V_6 = F_3 ( V_2 -> V_7 . V_8 ) ;
if ( V_6 -> V_9 == V_10 ) {
F_6 ( ( V_18 , L_1 ,
V_2 -> V_7 . V_8 ) ) ;
V_17 ;
}
if ( ! ( V_6 -> V_11 & V_12 ) ) {
V_17 ;
}
if ( V_2 -> V_7 . V_13 . V_4 ) {
V_15 = V_2 -> V_7 . V_13 . V_4 ;
while ( V_15 -> V_7 . V_14 ) {
V_15 = V_15 -> V_7 . V_14 ;
}
V_15 -> V_7 . V_14 = V_4 ;
} else {
V_2 -> V_7 . V_13 . V_4 = V_4 ;
}
while ( V_4 ) {
V_4 -> V_7 . V_19 = V_2 ;
V_4 = V_4 -> V_7 . V_14 ;
V_2 -> V_7 . V_20 ++ ;
}
V_17 ;
}
union V_1 * F_7 ( union V_1 * V_21 ,
union V_1 * V_2 )
{
union V_1 * V_14 = NULL ;
union V_1 * V_19 ;
union V_1 * V_4 ;
F_2 () ;
if ( ! V_2 ) {
return ( NULL ) ;
}
V_14 = F_1 ( V_2 , 0 ) ;
if ( V_14 ) {
F_8 ( V_14 ) ;
return ( V_14 ) ;
}
V_14 = V_2 -> V_7 . V_14 ;
if ( V_14 ) {
F_8 ( V_14 ) ;
return ( V_14 ) ;
}
V_19 = V_2 -> V_7 . V_19 ;
while ( V_19 ) {
V_4 = F_1 ( V_19 , 0 ) ;
while ( V_4 && ( V_4 != V_21 ) && ( V_4 != V_2 ) ) {
F_8 ( V_4 ) ;
V_4 = V_4 -> V_7 . V_14 ;
}
if ( V_4 == V_21 ) {
return ( NULL ) ;
}
if ( V_19 -> V_7 . V_14 ) {
F_8 ( V_19 -> V_7 . V_14 ) ;
return ( V_19 -> V_7 . V_14 ) ;
}
V_2 = V_19 ;
V_19 = V_19 -> V_7 . V_19 ;
}
F_8 ( V_14 ) ;
return ( V_14 ) ;
}
union V_1 * F_9 ( union V_1 * V_2 )
{
union V_1 * V_22 = NULL ;
F_2 () ;
switch ( V_2 -> V_7 . V_8 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_22 = F_1 ( V_2 , 0 ) ;
break;
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
V_22 = F_1 ( V_2 , 1 ) ;
break;
case V_34 :
case V_35 :
V_22 = F_1 ( V_2 , 2 ) ;
break;
case V_36 :
case V_37 :
V_22 = F_1 ( V_2 , 3 ) ;
break;
default:
break;
}
return ( V_22 ) ;
}
