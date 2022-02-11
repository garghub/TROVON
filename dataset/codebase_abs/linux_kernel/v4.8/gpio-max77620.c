static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_3 ( V_5 -> V_7 , F_4 ( V_3 ) ,
V_8 ,
V_9 ) ;
if ( V_6 < 0 )
F_5 ( V_5 -> V_10 , L_1 , V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_11 ;
int V_6 ;
V_6 = F_7 ( V_5 -> V_7 , F_4 ( V_3 ) , & V_11 ) ;
if ( V_6 < 0 ) {
F_5 ( V_5 -> V_10 , L_2 , V_6 ) ;
return V_6 ;
}
if ( V_11 & V_8 )
return ! ! ( V_11 & V_12 ) ;
else
return ! ! ( V_11 & V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_11 ;
int V_6 ;
V_11 = ( V_14 ) ? V_15 :
V_16 ;
V_6 = F_3 ( V_5 -> V_7 , F_4 ( V_3 ) ,
V_13 , V_11 ) ;
if ( V_6 < 0 ) {
F_5 ( V_5 -> V_10 , L_3 , V_6 ) ;
return V_6 ;
}
V_6 = F_3 ( V_5 -> V_7 , F_4 ( V_3 ) ,
V_8 ,
V_17 ) ;
if ( V_6 < 0 )
F_5 ( V_5 -> V_10 , L_1 , V_6 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_18 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_11 ;
int V_6 ;
switch ( V_18 ) {
case 0 :
V_11 = V_19 ;
break;
case 1 ... 8 :
V_11 = V_20 ;
break;
case 9 ... 16 :
V_11 = V_21 ;
break;
case 17 ... 32 :
V_11 = V_22 ;
break;
default:
F_5 ( V_5 -> V_10 , L_4 , V_18 ) ;
return - V_23 ;
}
V_6 = F_3 ( V_5 -> V_7 , F_4 ( V_3 ) ,
V_24 , V_11 ) ;
if ( V_6 < 0 )
F_5 ( V_5 -> V_10 , L_5 , V_6 ) ;
return V_6 ;
}
static void F_10 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_11 ;
int V_6 ;
V_11 = ( V_14 ) ? V_15 :
V_16 ;
V_6 = F_3 ( V_5 -> V_7 , F_4 ( V_3 ) ,
V_13 , V_11 ) ;
if ( V_6 < 0 )
F_5 ( V_5 -> V_10 , L_6 , V_6 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_25 V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_26 ) {
case V_27 :
return F_3 ( V_5 -> V_7 , F_4 ( V_3 ) ,
V_28 ,
V_29 ) ;
case V_30 :
return F_3 ( V_5 -> V_7 , F_4 ( V_3 ) ,
V_28 ,
V_31 ) ;
default:
break;
}
return - V_32 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_33 * V_34 = F_13 ( V_5 -> V_10 -> V_35 ) ;
return F_14 ( V_34 -> V_36 , V_3 ) ;
}
static int F_15 ( struct V_37 * V_38 )
{
struct V_33 * V_34 = F_13 ( V_38 -> V_10 . V_35 ) ;
struct V_4 * V_5 ;
int V_39 ;
int V_6 ;
V_39 = F_16 ( V_38 , 0 ) ;
if ( V_39 <= 0 ) {
F_5 ( & V_38 -> V_10 , L_7 , V_39 ) ;
return - V_40 ;
}
V_5 = F_17 ( & V_38 -> V_10 , sizeof( * V_5 ) , V_41 ) ;
if ( ! V_5 )
return - V_42 ;
V_5 -> V_7 = V_34 -> V_7 ;
V_5 -> V_10 = & V_38 -> V_10 ;
V_5 -> V_39 = V_39 ;
V_5 -> V_1 . V_43 = V_38 -> V_44 ;
V_5 -> V_1 . V_35 = & V_38 -> V_10 ;
V_5 -> V_1 . V_45 = F_1 ;
V_5 -> V_1 . V_46 = F_6 ;
V_5 -> V_1 . V_47 = F_8 ;
V_5 -> V_1 . V_48 = F_9 ;
V_5 -> V_1 . V_49 = F_10 ;
V_5 -> V_1 . V_50 = F_11 ;
V_5 -> V_1 . V_51 = F_12 ;
V_5 -> V_1 . V_52 = V_53 ;
V_5 -> V_1 . V_54 = 1 ;
V_5 -> V_1 . V_55 = - 1 ;
V_5 -> V_56 = - 1 ;
#ifdef F_18
V_5 -> V_1 . V_57 = V_38 -> V_10 . V_35 -> V_57 ;
#endif
F_19 ( V_38 , V_5 ) ;
V_6 = F_20 ( & V_38 -> V_10 , & V_5 -> V_1 , V_5 ) ;
if ( V_6 < 0 ) {
F_5 ( & V_38 -> V_10 , L_8 ) ;
return V_6 ;
}
V_5 -> V_58 = V_5 -> V_1 . V_55 ;
V_6 = F_21 ( & V_38 -> V_10 , V_34 -> V_7 , V_5 -> V_39 ,
V_59 , V_5 -> V_56 ,
& V_60 ,
& V_34 -> V_36 ) ;
if ( V_6 < 0 ) {
F_5 ( & V_38 -> V_10 , L_9 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
