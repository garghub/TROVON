static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , T_1 V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
int V_8 ;
if ( V_4 == V_9 ) {
F_5 ( L_1
L_2 , V_4 ) ;
* V_5 = 0 ;
return 0 ;
}
V_8 = F_6 ( V_7 , V_4 ) ;
if ( V_8 < 0 ) {
F_7 ( V_10 L_3
L_4 , V_4 ) ;
return V_8 ;
}
* V_5 = ( T_1 ) V_8 ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
int V_11 ;
if ( V_4 == V_12 || V_4 == V_13 ) {
F_5 ( L_5
L_6 , V_4 ) ;
return 0 ;
}
F_5 ( L_7 , V_4 , V_5 ) ;
V_11 = F_9 ( V_7 , V_4 , V_5 ) ;
if ( V_11 ) {
F_7 ( V_10 L_8
L_9 , V_4 , V_5 ) ;
}
return V_11 ;
}
static int F_10 ( struct V_2 * V_3 , T_1 V_4 ,
T_1 V_14 , T_1 * V_15 )
{
int V_16 , V_11 ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ ) {
V_11 = F_8 ( V_3 , V_4 + V_16 , V_15 [ V_16 ] ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
int V_16 ;
T_1 V_17 ;
for ( V_16 = 0 ; V_16 < 9 ; V_16 ++ ) {
F_3 ( V_3 , V_16 , & V_17 ) ;
F_5 ( L_10 , V_16 , V_17 ) ;
}
}
static int F_12 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_4 ;
int V_8 = 0 ;
switch ( V_19 -> V_21 ) {
case V_22 :
case V_23 :
V_8 = F_3 ( V_3 , V_24 , & V_4 ) ;
if ( V_8 )
return - V_25 ;
if ( V_19 -> V_21 == V_22 )
V_19 -> V_5 = ( V_4 & V_26 )
? 1 : 0 ;
else
V_19 -> V_5 = ( V_4 & V_27 )
? 1 : 0 ;
break;
case V_28 :
V_8 = F_3 ( V_3 , V_29 , & V_4 ) ;
if ( V_8 )
return - V_25 ;
V_19 -> V_5 = ( ( V_30 ) V_4 == 0x00 ) ? 0xff : ( ( V_30 ) V_4 - 1 ) ;
break;
case V_31 :
V_8 = F_3 ( V_3 , V_32 , & V_4 ) ;
if ( V_8 )
return - V_25 ;
V_19 -> V_5 = ( V_30 ) V_4 ;
break;
case V_33 :
V_8 = F_3 ( V_3 , V_34 , & V_4 ) ;
if ( V_8 )
return - V_25 ;
V_19 -> V_5 = ( V_30 ) V_4 ;
break;
case V_35 :
V_8 = F_3 ( V_3 , V_36 , & V_4 ) ;
if ( V_8 )
return - V_25 ;
V_19 -> V_5 = ( V_30 ) V_4 ;
break;
case V_37 :
V_8 = F_3 ( V_3 ,
V_38 , & V_4 ) ;
if ( V_8 )
return - V_25 ;
V_19 -> V_5 = ( V_30 ) V_4 ;
break;
case V_39 :
V_8 = F_3 ( V_3 ,
V_40 , & V_4 ) ;
if ( V_8 )
return - V_25 ;
V_19 -> V_5 = ( V_30 ) V_4 ;
break;
case V_41 :
if ( V_20 -> V_42 == V_43 ) {
V_8 = F_3 ( V_3 ,
V_44 , & V_4 ) ;
if ( V_8 )
return - V_25 ;
V_19 -> V_5 = ( V_30 ) V_4 ;
} else {
V_19 -> V_5 = V_45 ;
}
break;
default:
V_8 = - V_46 ;
}
return V_8 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_4 ;
int V_8 = 0 ;
switch ( V_19 -> V_21 ) {
case V_22 :
case V_23 :
V_8 = F_3 ( V_3 , V_24 , & V_4 ) ;
if ( V_8 )
break;
if ( V_19 -> V_21 == V_22 ) {
if ( V_19 -> V_5 )
V_4 |= V_26 ;
else
V_4 &= ~ V_26 ;
} else {
if ( V_19 -> V_5 )
V_4 |= V_27 ;
else
V_4 &= ~ V_27 ;
}
V_8 = F_8 ( V_3 , V_24 , V_4 ) ;
break;
case V_28 :
V_4 = ( V_19 -> V_5 == 0xff ) ? 0x00 : ( V_19 -> V_5 + 1 ) ;
V_8 = F_8 ( V_3 , V_29 , V_4 ) ;
break;
case V_31 :
V_8 = F_8 ( V_3 , V_32 , V_19 -> V_5 ) ;
break;
case V_33 :
V_8 = F_8 ( V_3 , V_34 ,
V_19 -> V_5 ) ;
break;
case V_35 :
V_8 = F_8 ( V_3 , V_36 ,
V_19 -> V_5 ) ;
break;
case V_37 :
V_8 = F_8 ( V_3 , V_38 ,
V_19 -> V_5 ) ;
break;
case V_39 :
V_8 = F_8 ( V_3 , V_40 ,
V_19 -> V_5 ) ;
break;
case V_41 :
if ( V_20 -> V_42 == V_43 ) {
V_8 = F_8 ( V_3 , V_44 ,
V_19 -> V_5 ) ;
}
break;
default:
V_8 = - V_46 ;
}
return V_8 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_47 * V_48 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
return F_15 ( V_7 , V_48 , V_49 ,
V_20 -> V_42 ) ;
}
static int F_16 ( struct V_6 * V_7 ,
const struct V_50 * V_21 )
{
int V_11 = 0 ;
struct V_1 * V_20 ;
struct V_2 * V_3 ;
F_17 ( V_7 , L_11 ,
V_7 -> V_51 << 1 , V_7 -> V_52 -> V_53 ) ;
V_20 = F_18 ( sizeof( struct V_1 ) , V_54 ) ;
if ( ! V_20 )
return - V_55 ;
V_3 = & V_20 -> V_3 ;
F_19 ( V_3 , V_7 , & V_56 ) ;
V_20 -> V_42 = F_6 ( V_7 ,
V_13 ) ;
if ( V_20 -> V_42 != V_57 &&
V_20 -> V_42 != V_43 ) {
F_20 ( V_20 ) ;
return - V_58 ;
}
F_7 ( V_59 L_12 ,
F_21 ( V_20 -> V_42 ) ,
F_22 ( V_20 -> V_42 ) ) ;
F_23 ( V_3 ) ;
V_11 = F_10 ( V_3 , 0 , sizeof( V_60 ) , ( T_1 * ) & V_60 ) ;
if ( V_11 ) {
F_7 ( V_10 L_13 ) ;
F_20 ( V_20 ) ;
return - V_25 ;
}
F_23 ( V_3 ) ;
V_11 = F_8 ( V_3 , V_24 ,
V_26 | V_27 ) ;
if ( V_11 ) {
F_7 ( V_10 L_14 ) ;
F_20 ( V_20 ) ;
return - V_25 ;
}
F_23 ( V_3 ) ;
F_7 ( V_59 L_15 ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_25 ( V_7 ) ;
F_26 ( V_3 ) ;
F_20 ( F_1 ( V_3 ) ) ;
return 0 ;
}
static T_2 int F_27 ( void )
{
return F_28 ( & V_61 ) ;
}
static T_3 void F_29 ( void )
{
F_30 ( & V_61 ) ;
}
