static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 = 0 ;
switch ( V_3 & V_10 ) {
case V_11 :
V_7 -> V_12 |= V_13 | V_14 ;
V_7 -> V_15 |= V_16 | V_17 ;
V_7 -> V_18 |= V_19 ;
V_7 -> V_20 |= V_21 ;
break;
case V_22 :
V_7 -> V_12 |= V_13 ;
V_7 -> V_15 |= V_16 ;
break;
case V_23 :
V_9 = - V_24 ;
break;
default:
F_3 ( V_25 L_1 , V_26 ) ;
V_9 = - V_24 ;
break;
}
switch ( V_3 & V_27 ) {
case V_28 :
break;
case V_29 :
case V_30 :
case V_31 :
V_9 = - V_24 ;
break;
default:
F_3 ( V_25 L_2 , V_26 ) ;
V_9 = - V_24 ;
break;
}
return V_9 ;
}
static int F_4 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_1 * V_36 )
{
struct V_4 * V_5 = F_2 ( V_36 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 = 0 ;
V_7 -> V_18 &= ~ 0x1f ;
V_7 -> V_20 &= ~ 0x1f ;
switch ( F_5 ( V_35 ) ) {
case V_37 :
V_7 -> V_18 |= 7 ;
V_7 -> V_20 |= 7 ;
V_5 -> V_38 = 1 ;
case V_39 :
V_7 -> V_18 |= 15 ;
V_7 -> V_20 |= 15 ;
V_5 -> V_38 = 2 ;
break;
case V_40 :
V_7 -> V_18 |= 23 ;
V_7 -> V_20 |= 23 ;
V_5 -> V_38 = 3 ;
break;
case V_41 :
V_7 -> V_18 |= 31 ;
V_7 -> V_20 |= 31 ;
V_5 -> V_38 = 4 ;
break;
}
if ( ! V_7 -> V_42 ) {
V_7 -> V_42 = 1 ;
V_9 = F_6 ( V_5 , V_7 -> V_15 ,
V_7 -> V_20 , 0 , 0 ) ;
if ( V_9 ) {
F_7 ( L_3 ) ;
return - V_43 ;
}
V_9 = F_8 ( V_5 , V_7 -> V_12 ,
V_7 -> V_18 , 0 , 0 ) ;
if ( V_9 ) {
F_7 ( L_3 ) ;
return - V_43 ;
}
}
return 0 ;
}
static void F_9 ( struct V_32 * V_33 ,
struct V_1 * V_36 )
{
struct V_4 * V_5 = F_2 ( V_36 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_10 ( L_4 , V_26 ) ;
if ( ! V_36 -> V_44 )
V_7 -> V_42 = 0 ;
}
static int F_11 ( struct V_1 * V_36 )
{
struct V_4 * V_5 = F_2 ( V_36 ) ;
F_10 ( L_5 , V_26 , V_36 -> V_45 ) ;
if ( V_36 -> V_46 )
F_12 ( V_5 ) ;
if ( V_36 -> V_47 )
F_13 ( V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_36 )
{
struct V_4 * V_5 = F_2 ( V_36 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
F_10 ( L_5 , V_26 , V_36 -> V_45 ) ;
V_9 = F_6 ( V_5 , V_7 -> V_15 ,
V_7 -> V_20 , 0 , 0 ) ;
if ( V_9 ) {
F_7 ( L_3 ) ;
return - V_43 ;
}
V_9 = F_8 ( V_5 , V_7 -> V_12 ,
V_7 -> V_18 , 0 , 0 ) ;
if ( V_9 ) {
F_7 ( L_3 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_15 ( struct V_48 * V_49 )
{
struct V_4 * V_5 ;
int V_9 ;
V_5 = F_16 ( V_49 , 4 , 2 * sizeof( V_50 ) ,
sizeof( struct V_6 ) ) ;
if ( ! V_5 )
return - V_51 ;
V_9 = F_17 ( & V_49 -> V_52 , & V_53 ,
& V_54 , 1 ) ;
if ( V_9 ) {
F_7 ( L_6 , V_9 ) ;
F_18 ( V_5 ) ;
return V_9 ;
}
return 0 ;
}
static int F_19 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_20 ( V_49 ) ;
F_10 ( L_4 , V_26 ) ;
F_21 ( & V_49 -> V_52 ) ;
F_18 ( V_5 ) ;
return 0 ;
}
