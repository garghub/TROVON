static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
static void T_1 * V_5 ;
T_2 V_6 ;
int V_7 ;
V_4 = F_2 ( NULL , V_8 ) ;
if ( ! V_4 ) {
return - V_9 ;
}
V_5 = F_3 ( V_4 , 0 ) ;
if ( ! V_5 )
return - V_9 ;
V_7 = F_4 ( V_10 ,
V_11 ,
V_12 | V_13 ) ;
if ( V_7 )
F_5 ( & V_2 -> V_14 , L_1 ) ;
F_6 ( V_15 , V_5 + V_16 ) ;
V_6 = F_7 ( V_5 + V_17 ) ;
V_6 |= V_18 ;
F_6 ( V_6 , V_5 + V_17 ) ;
F_6 ( 0 , V_5 + V_16 ) ;
F_8 ( V_5 ) ;
return 0 ;
}
static void F_9 ( struct V_19 * V_20 , int V_21 )
{
int V_7 ;
if ( V_21 ) {
V_7 = F_4 ( V_10 ,
V_22 ,
V_12 | V_13 ) ;
if ( V_7 )
F_10 ( L_2 ) ;
} else {
V_7 = F_4 ( V_10 ,
V_11 ,
V_12 | V_13 ) ;
if ( V_7 )
F_10 ( L_3 ) ;
}
}
static void F_11 ( struct V_19 * V_20 , int V_21 )
{
int V_7 ;
if ( V_21 ) {
V_7 = F_12 ( V_10 ,
V_23 ,
V_24 ,
V_25 | V_26 ) ;
if ( V_7 )
F_10 ( L_4 ) ;
} else {
V_7 = F_12 ( V_10 ,
V_23 ,
V_24 ,
0 ) ;
if ( V_7 )
F_10 ( L_4 ) ;
}
}
static void F_13 ( struct V_19 * V_20 , int V_21 )
{
int V_7 ;
V_7 = F_12 ( V_10 , V_27 ,
0x01 , ! ! V_21 ) ;
if ( V_7 )
F_10 ( L_5 ) ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_28 ,
struct V_19 * V_20 )
{
struct V_3 * V_29 ;
const struct V_30 * V_31 ;
struct V_32 * V_33 ;
static enum V_34 V_34 ;
int V_7 ;
if ( ! F_15 ( V_28 , L_6 ) )
return 0 ;
if ( ! V_10 ) {
V_29 = F_16 ( NULL ,
V_35 ,
& V_31 ) ;
if ( ! V_29 )
return - V_9 ;
V_34 = (enum V_34 ) V_31 -> V_36 ;
V_33 = F_17 ( V_29 ) ;
if ( F_18 ( V_33 ) )
return F_19 ( V_33 ) ;
V_10 = V_33 ;
}
switch ( V_34 ) {
case V_37 :
V_7 = F_1 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_20 -> V_38 = F_9 ;
F_20 ( & V_2 -> V_14 , L_7 ) ;
break;
case V_39 :
V_20 -> V_38 = F_11 ;
F_20 ( & V_2 -> V_14 , L_8 ) ;
break;
case V_40 :
case V_41 :
V_20 -> V_38 = F_13 ;
F_20 ( & V_2 -> V_14 , L_9 ) ;
break;
default:
F_20 ( & V_2 -> V_14 , L_10
L_11 ) ;
break;
}
return 0 ;
}
