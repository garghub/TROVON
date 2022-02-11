static int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
const struct V_3 * V_4 )
{
if ( V_4 == NULL )
V_4 = & V_5 ;
return V_1 -> V_6 ( V_1 , V_2 , V_4 ) ;
}
static void F_2 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = V_8 -> V_9 ;
struct V_10 * V_11 = V_1 -> V_11 ;
struct V_3 V_4 ;
F_3 ( V_11 , L_1 , V_12 , V_8 -> V_13 ) ;
switch ( V_8 -> V_13 ) {
case V_14 :
F_4 ( V_8 , & V_4 ) ;
F_3 ( V_11 , L_2 ,
V_15 , V_4 . V_16 ) ;
F_1 ( V_1 , V_8 -> V_2 , & V_4 ) ;
break;
case V_17 :
F_3 ( V_11 , L_3 ) ;
F_1 ( V_1 , 0 , NULL ) ;
break;
default:
F_3 ( V_11 , L_4 , V_8 -> V_13 ) ;
break;
}
}
int F_5 ( struct V_1 * V_1 )
{
struct V_18 * V_19 = V_1 -> V_18 ;
struct V_7 * V_8 ;
struct V_20 V_21 ;
int V_22 ;
if ( V_19 == NULL )
return - V_23 ;
V_8 = F_6 ( V_19 , F_2 , V_1 ) ;
if ( V_8 == NULL )
return - V_24 ;
V_21 . V_25 [ 0 ] = V_1 -> V_26 ;
V_21 . V_25 [ 1 ] = 0 ;
V_8 -> V_27 . type = V_28 ;
V_8 -> V_27 . V_29 = V_21 ;
V_8 -> type = V_30 ;
V_8 -> V_31 = 256 ;
V_8 -> V_32 = 15 ;
V_8 -> V_33 = 1 ;
V_8 -> V_34 = true ;
V_22 = F_7 ( V_8 ) ;
if ( V_22 == 0 )
V_1 -> V_8 = V_8 ;
else
F_8 ( V_8 ) ;
return V_22 ;
}
void F_9 ( struct V_1 * V_1 )
{
if ( V_1 -> V_8 ) {
F_10 ( V_1 -> V_8 ) ;
F_8 ( V_1 -> V_8 ) ;
V_1 -> V_8 = NULL ;
}
}
