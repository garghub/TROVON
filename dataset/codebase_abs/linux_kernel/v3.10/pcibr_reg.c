void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
union V_3 T_2 * V_4 = (union V_3 T_2 * ) V_1 -> V_5 . V_6 ;
if ( V_1 ) {
switch ( V_1 -> V_7 ) {
case V_8 :
F_2 ( & V_4 -> V_9 . V_10 , V_2 ) ;
break;
case V_11 :
F_2 ( & V_4 -> V_12 . V_13 , V_2 ) ;
break;
default:
F_3
( L_1 ,
V_4 ) ;
}
}
}
void F_4 ( struct V_1 * V_1 , T_1 V_2 )
{
union V_3 T_2 * V_4 = (union V_3 T_2 * ) V_1 -> V_5 . V_6 ;
if ( V_1 ) {
switch ( V_1 -> V_7 ) {
case V_8 :
F_5 ( & V_4 -> V_9 . V_10 , V_2 ) ;
break;
case V_11 :
F_5 ( & V_4 -> V_12 . V_13 , V_2 ) ;
break;
default:
F_3
( L_2 ,
V_4 ) ;
}
}
}
T_1 F_6 ( struct V_1 * V_1 )
{
union V_3 T_2 * V_4 = (union V_3 T_2 * ) V_1 -> V_5 . V_6 ;
T_1 V_14 = 0 ;
if ( V_1 ) {
switch ( V_1 -> V_7 ) {
case V_8 :
V_14 = F_7 ( & V_4 -> V_9 . V_15 ) ;
break;
case V_11 :
V_14 = F_7 ( & V_4 -> V_12 . V_16 ) ;
break;
default:
F_3
( L_3 ,
V_4 ) ;
}
}
if ( V_14 != 0 )
F_3 ( L_4 ) ;
return V_14 ;
}
T_1 F_8 ( struct V_1 * V_1 )
{
union V_3 T_2 * V_4 = (union V_3 T_2 * ) V_1 -> V_5 . V_6 ;
T_1 V_14 = 0 ;
if ( V_1 ) {
switch ( V_1 -> V_7 ) {
case V_8 :
V_14 = F_7 ( & V_4 -> V_9 . V_17 ) ;
break;
case V_11 :
V_14 = F_7 ( & V_4 -> V_12 . V_18 ) ;
break;
default:
F_3
( L_5 ,
V_4 ) ;
}
}
return V_14 ;
}
void F_9 ( struct V_1 * V_1 , T_1 V_2 )
{
union V_3 T_2 * V_4 = (union V_3 T_2 * ) V_1 -> V_5 . V_6 ;
if ( V_1 ) {
switch ( V_1 -> V_7 ) {
case V_8 :
F_2 ( & V_4 -> V_9 . V_19 , V_2 ) ;
break;
case V_11 :
F_2 ( & V_4 -> V_12 . V_20 , V_2 ) ;
break;
default:
F_3
( L_6 ,
V_4 ) ;
}
}
}
void F_10 ( struct V_1 * V_1 , T_1 V_2 )
{
union V_3 T_2 * V_4 = (union V_3 T_2 * ) V_1 -> V_5 . V_6 ;
if ( V_1 ) {
switch ( V_1 -> V_7 ) {
case V_8 :
F_5 ( & V_4 -> V_9 . V_19 , V_2 ) ;
break;
case V_11 :
F_5 ( & V_4 -> V_12 . V_20 , V_2 ) ;
break;
default:
F_3
( L_7 ,
V_4 ) ;
}
}
}
void F_11 ( struct V_1 * V_1 , int V_21 ,
T_1 V_22 )
{
union V_3 T_2 * V_4 = (union V_3 T_2 * ) V_1 -> V_5 . V_6 ;
if ( V_1 ) {
switch ( V_1 -> V_7 ) {
case V_8 :
F_2 ( & V_4 -> V_9 . V_23 [ V_21 ] ,
V_24 ) ;
F_5 ( & V_4 -> V_9 . V_23 [ V_21 ] ,
( V_22 & V_24 ) ) ;
break;
case V_11 :
F_2 ( & V_4 -> V_12 . V_25 [ V_21 ] ,
V_26 ) ;
F_5 ( & V_4 -> V_12 . V_25 [ V_21 ] ,
( V_22 & V_26 ) ) ;
break;
default:
F_3
( L_8 ,
V_4 ) ;
}
}
}
void F_12 ( struct V_1 * V_1 , int V_21 )
{
union V_3 T_2 * V_4 = (union V_3 T_2 * ) V_1 -> V_5 . V_6 ;
if ( V_1 ) {
switch ( V_1 -> V_7 ) {
case V_8 :
F_13 ( 1 , & V_4 -> V_9 . V_27 [ V_21 ] ) ;
break;
case V_11 :
F_13 ( 1 , & V_4 -> V_12 . V_28 [ V_21 ] ) ;
break;
default:
F_3
( L_9 ,
V_4 ) ;
}
}
}
T_1 F_14 ( struct V_1 * V_1 , int V_29 )
{
union V_3 T_2 * V_4 = (union V_3 T_2 * ) V_1 -> V_5 . V_6 ;
T_1 V_14 = 0 ;
if ( V_1 ) {
switch ( V_1 -> V_7 ) {
case V_8 :
V_14 =
F_7 ( & V_4 -> V_9 . V_30 [ V_29 ] ) ;
break;
case V_11 :
V_14 =
F_7 ( & V_4 -> V_12 . V_31 [ V_29 ] ) ;
break;
default:
F_3 ( L_10 , V_4 ) ;
}
}
return V_14 ;
}
void F_15 ( struct V_1 * V_1 , int V_32 ,
T_1 V_33 )
{
union V_3 T_2 * V_4 = (union V_3 T_2 * ) V_1 -> V_5 . V_6 ;
if ( V_1 ) {
switch ( V_1 -> V_7 ) {
case V_8 :
F_13 ( V_33 , & V_4 -> V_9 . V_34 [ V_32 ] ) ;
break;
case V_11 :
F_13 ( V_33 , & V_4 -> V_12 . V_35 [ V_32 ] ) ;
break;
default:
F_3
( L_11 ,
V_4 ) ;
}
}
}
T_1 T_2 * F_16 ( struct V_1 * V_1 , int V_32 )
{
union V_3 T_2 * V_4 = (union V_3 T_2 * ) V_1 -> V_5 . V_6 ;
T_1 T_2 * V_14 = NULL ;
if ( V_1 ) {
switch ( V_1 -> V_7 ) {
case V_8 :
V_14 = & V_4 -> V_9 . V_34 [ V_32 ] ;
break;
case V_11 :
V_14 = & V_4 -> V_12 . V_35 [ V_32 ] ;
break;
default:
F_3
( L_12 ,
V_4 ) ;
}
}
return V_14 ;
}
