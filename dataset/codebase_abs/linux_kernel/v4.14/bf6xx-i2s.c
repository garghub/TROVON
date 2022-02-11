static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_7 ;
int V_9 = 0 ;
V_10 . V_11 &= ~ ( V_12 | V_13 | V_14
| V_15 | V_16 ) ;
switch ( V_3 & V_17 ) {
case V_18 :
V_10 . V_11 |= V_12 | V_13
| V_15 ;
break;
case V_19 :
V_10 . V_11 |= V_14 ;
break;
case V_20 :
V_10 . V_11 |= V_12 | V_15
| V_16 ;
break;
default:
F_3 ( V_7 , L_1 , V_21 ) ;
V_9 = - V_22 ;
break;
}
V_10 . V_11 &= ~ ( V_23 | V_24 ) ;
switch ( V_3 & V_25 ) {
case V_26 :
break;
case V_27 :
case V_28 :
case V_29 :
V_9 = - V_22 ;
break;
default:
F_3 ( V_7 , L_2 , V_21 ) ;
V_9 = - V_22 ;
break;
}
return V_9 ;
}
static int F_4 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
struct V_1 * V_34 )
{
struct V_4 * V_5 = F_2 ( V_34 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_7 ;
int V_9 = 0 ;
V_10 . V_11 &= ~ V_35 ;
switch ( F_5 ( V_33 ) ) {
case V_36 :
V_10 . V_11 |= 0x70 ;
V_5 -> V_37 = 1 ;
break;
case V_38 :
V_10 . V_11 |= 0xf0 ;
V_5 -> V_37 = 2 ;
break;
case V_39 :
V_10 . V_11 |= 0x170 ;
V_5 -> V_37 = 3 ;
break;
case V_40 :
V_10 . V_11 |= 0x1f0 ;
V_5 -> V_37 = 4 ;
break;
}
if ( V_31 -> V_41 == V_42 ) {
V_9 = F_6 ( V_5 , & V_10 ) ;
if ( V_9 ) {
F_3 ( V_7 , L_3 ) ;
return V_9 ;
}
} else {
V_9 = F_7 ( V_5 , & V_10 ) ;
if ( V_9 ) {
F_3 ( V_7 , L_4 ) ;
return V_9 ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_34 )
{
struct V_4 * V_5 = F_2 ( V_34 ) ;
if ( V_34 -> V_43 )
F_9 ( V_5 ) ;
if ( V_34 -> V_44 )
F_10 ( V_5 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_34 )
{
struct V_4 * V_5 = F_2 ( V_34 ) ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_7 ;
int V_9 ;
V_9 = F_6 ( V_5 , & V_10 ) ;
if ( V_9 ) {
F_3 ( V_7 , L_3 ) ;
return V_9 ;
}
V_9 = F_7 ( V_5 , & V_10 ) ;
if ( V_9 ) {
F_3 ( V_7 , L_4 ) ;
return V_9 ;
}
return 0 ;
}
static int F_12 ( struct V_45 * V_8 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = & V_8 -> V_7 ;
int V_9 ;
V_5 = F_13 ( V_8 ) ;
if ( ! V_5 )
return - V_46 ;
V_9 = F_14 ( V_7 , & V_47 ,
& V_48 , 1 ) ;
if ( V_9 ) {
F_3 ( V_7 , L_5 , V_9 ) ;
F_15 ( V_5 ) ;
return V_9 ;
}
F_16 ( V_8 , V_5 ) ;
return 0 ;
}
static int F_17 ( struct V_45 * V_8 )
{
struct V_4 * V_5 = F_18 ( V_8 ) ;
F_19 ( & V_8 -> V_7 ) ;
F_15 ( V_5 ) ;
return 0 ;
}
