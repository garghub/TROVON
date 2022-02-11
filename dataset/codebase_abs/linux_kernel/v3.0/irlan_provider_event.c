void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
F_2 (*state[ self->provider.state] != NULL, return;) ;
(* F_3 [ V_2 -> V_6 . F_3 ]) ( V_2 , V_3 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
F_5 ( 4 , L_1 , V_7 ) ;
F_2 (self != NULL, return -1;) ;
switch( V_3 ) {
case V_8 :
F_6 ( V_2 , V_2 -> V_6 . V_9 ) ;
F_7 ( V_2 , V_10 ) ;
break;
default:
F_5 ( 4 , L_2 , V_7 , V_3 ) ;
break;
}
if ( V_5 )
F_8 ( V_5 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
int V_11 ;
F_5 ( 4 , L_1 , V_7 ) ;
F_2 (self != NULL, return -1;) ;
switch( V_3 ) {
case V_12 :
if ( V_2 -> V_6 . V_13 == V_14 ) {
V_2 -> V_15 = V_16 ;
if ( V_2 -> V_17 . F_3 == V_18 ) {
F_10 ( 8 ) ;
}
}
F_11 ( V_2 , V_19 ,
V_20 ) ;
break;
case V_21 :
F_11 ( V_2 , V_22 ,
V_20 ) ;
break;
case V_23 :
V_11 = F_12 ( V_2 , V_5 ) ;
if ( V_2 -> V_6 . V_13 == V_14 ) {
V_2 -> V_6 . V_24 = ( V_25 & 0xffff ) ;
}
F_11 ( V_2 , V_26 , V_11 ) ;
if ( V_11 == V_20 ) {
F_7 ( V_2 , V_27 ) ;
F_13 ( V_2 , V_28 , NULL ) ;
}
break;
case V_29 :
case V_30 :
F_7 ( V_2 , V_18 ) ;
break;
default:
F_5 ( 0 , L_2 , V_7 , V_3 ) ;
break;
}
if ( V_5 )
F_8 ( V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
F_5 ( 4 , L_1 , V_7 ) ;
F_2 (self != NULL, return -1;) ;
switch( V_3 ) {
case V_31 :
F_15 ( V_2 , V_32 , V_5 ) ;
F_11 ( V_2 , V_32 ,
V_20 ) ;
break;
case V_33 :
F_7 ( V_2 , V_34 ) ;
F_6 ( V_2 , V_2 -> V_35 ) ;
break;
case V_29 :
case V_30 :
F_7 ( V_2 , V_18 ) ;
break;
default:
F_5 ( 2 , L_2 , V_7 , V_3 ) ;
break;
}
if ( V_5 )
F_8 ( V_5 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
F_5 ( 4 , L_1 , V_7 ) ;
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == IRLAN_MAGIC, return -1;) ;
switch( V_3 ) {
case V_31 :
F_15 ( V_2 , V_32 , V_5 ) ;
F_11 ( V_2 , V_32 ,
V_20 ) ;
break;
case V_29 :
case V_30 :
F_7 ( V_2 , V_18 ) ;
break;
default:
F_5 ( 0 , L_2 , V_7 , V_3 ) ;
break;
}
if ( V_5 )
F_8 ( V_5 ) ;
return 0 ;
}
