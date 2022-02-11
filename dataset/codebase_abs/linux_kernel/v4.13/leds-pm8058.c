static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 ;
int V_7 = 0 ;
unsigned int V_8 = 0 ;
unsigned int V_9 = 0 ;
V_6 = F_2 ( V_2 , struct V_5 , V_10 ) ;
switch ( V_6 -> V_11 ) {
case V_12 :
V_8 = V_13 ;
V_9 = V_4 << V_14 ;
break;
case V_15 :
case V_16 :
V_8 = V_17 ;
V_9 = V_4 << V_18 ;
break;
default:
break;
}
V_7 = F_3 ( V_6 -> V_19 , V_6 -> V_20 , V_8 , V_9 ) ;
if ( V_7 )
F_4 ( L_1 ) ;
}
static enum V_3 F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_7 ;
unsigned int V_9 ;
V_6 = F_2 ( V_2 , struct V_5 , V_10 ) ;
V_7 = F_6 ( V_6 -> V_19 , V_6 -> V_20 , & V_9 ) ;
if ( V_7 ) {
F_4 ( L_2 ) ;
return V_21 ;
}
switch ( V_6 -> V_11 ) {
case V_12 :
V_9 &= V_13 ;
V_9 >>= V_14 ;
break;
case V_15 :
case V_16 :
V_9 &= V_17 ;
V_9 >>= V_18 ;
break;
default:
V_9 = V_21 ;
break;
}
return V_9 ;
}
static int F_7 ( struct V_22 * V_23 )
{
struct V_5 * V_6 ;
struct V_24 * V_25 = V_23 -> V_26 . V_27 ;
int V_7 ;
struct V_28 * V_19 ;
const char * V_29 ;
enum V_3 V_30 ;
V_6 = F_8 ( & V_23 -> V_26 , sizeof( * V_6 ) , V_31 ) ;
if ( ! V_6 )
return - V_32 ;
V_6 -> V_11 = ( V_33 ) F_9 ( & V_23 -> V_26 ) ;
V_19 = F_10 ( V_23 -> V_26 . V_34 , NULL ) ;
if ( ! V_19 ) {
F_11 ( & V_23 -> V_26 , L_3 ) ;
return - V_35 ;
}
V_6 -> V_19 = V_19 ;
V_7 = F_12 ( V_25 , L_4 , & V_6 -> V_20 ) ;
if ( V_7 ) {
F_11 ( & V_23 -> V_26 , L_5 ) ;
return - V_36 ;
}
V_6 -> V_10 . V_37 = F_13 ( V_25 , L_6 , NULL ) ? : V_25 -> V_37 ;
V_6 -> V_10 . V_38 =
F_13 ( V_25 , L_7 , NULL ) ;
V_6 -> V_10 . V_39 = F_1 ;
V_6 -> V_10 . V_40 = F_5 ;
if ( V_6 -> V_11 == V_12 )
V_30 = 31 ;
else
V_30 = 15 ;
V_6 -> V_10 . V_41 = V_30 ;
V_29 = F_13 ( V_25 , L_8 , NULL ) ;
if ( V_29 ) {
if ( ! strcmp ( V_29 , L_9 ) ) {
V_6 -> V_10 . V_42 = F_5 ( & V_6 -> V_10 ) ;
} else if ( ! strcmp ( V_29 , L_10 ) ) {
V_6 -> V_10 . V_42 = V_30 ;
F_1 ( & V_6 -> V_10 , V_30 ) ;
} else {
V_6 -> V_10 . V_42 = V_21 ;
F_1 ( & V_6 -> V_10 , V_21 ) ;
}
}
if ( V_6 -> V_11 == V_15 ||
V_6 -> V_11 == V_16 )
V_6 -> V_10 . V_43 = V_44 ;
V_7 = F_14 ( & V_23 -> V_26 , & V_6 -> V_10 ) ;
if ( V_7 ) {
F_11 ( & V_23 -> V_26 , L_11 ,
V_6 -> V_10 . V_37 ) ;
return V_7 ;
}
return 0 ;
}
