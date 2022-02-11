static T_1 T_2 F_1 ( unsigned char * V_1 , int V_2 , T_1 V_3 )
{
for (; V_2 -- > 0 ; V_3 = F_2 ( V_3 , * V_1 ++ ) ) ;
return V_3 ;
}
static void F_3 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned char * V_8 = V_4 -> V_9 ;
unsigned char V_10 = V_4 -> V_11 ;
int V_11 ;
T_1 V_3 ;
if ( ! V_10 )
return;
if ( ! V_12 )
goto V_13;
if ( V_10 < 2 ) {
F_4 ( & V_6 -> V_14 , L_1 ) ;
return;
}
V_3 = F_1 ( V_8 , V_10 , V_15 ) ;
if ( V_3 ) {
F_4 ( & V_6 -> V_14 , L_2 , V_16 , V_3 ) ;
return;
}
V_11 = V_8 [ V_10 - 2 ] >> 2 ;
if ( V_11 > ( V_10 - 2 ) ) {
F_4 ( & V_6 -> V_14 , L_3 ,
V_16 , V_11 , V_10 ) ;
return;
}
F_5 ( & V_4 -> V_14 -> V_14 , L_4 , V_16 , V_11 ) ;
V_10 = V_11 ;
V_13:
F_6 ( & V_6 -> V_6 , V_8 , V_10 ) ;
F_7 ( & V_6 -> V_6 ) ;
}
static int F_8 ( struct V_5 * V_6 ,
void * V_17 , T_3 V_18 )
{
unsigned char * V_19 = V_17 ;
int V_20 ;
int V_21 ;
int V_22 ;
T_1 V_3 ;
V_21 = V_12 ? 2 : 0 ;
V_20 = F_9 ( & V_6 -> V_23 , V_19 , V_18 - V_21 ,
& V_6 -> V_24 ) ;
if ( ! V_12 )
return V_20 ;
if ( V_25 ) {
V_22 = V_18 ;
memset ( V_19 + V_20 , '0' , V_22 - V_20 - V_21 ) ;
} else {
V_22 = V_20 + V_21 ;
}
V_19 [ V_22 - 2 ] = V_20 << 2 ;
V_19 [ V_22 - 1 ] = 0 ;
V_3 = F_1 ( V_19 , V_22 , V_15 ) ;
V_19 [ V_22 - 2 ] |= V_3 >> 8 ;
V_19 [ V_22 - 1 ] |= V_3 & 0xff ;
return V_22 ;
}
static int F_10 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
if ( V_27 -> V_14 -> V_30 . V_31 != V_32 )
return - V_33 ;
V_29 = & V_27 -> V_34 -> V_35 -> V_29 ;
if ( V_29 -> V_36 != V_37 )
return - V_33 ;
if ( V_29 -> V_38 != V_39 )
return - V_33 ;
switch ( V_29 -> V_40 ) {
case V_41 :
break;
case V_42 :
V_25 = true ;
break;
default:
return - V_43 ;
}
return 0 ;
}
