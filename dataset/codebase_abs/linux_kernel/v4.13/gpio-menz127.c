static int F_1 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_10 ;
T_1 V_11 , V_12 ;
if ( ! F_3 ( V_4 ) ) {
F_4 ( V_8 , L_1 , V_4 ) ;
return - V_13 ;
}
if ( V_4 > 0 ) {
V_10 = F_5 ( V_4 ) - 1 ;
if ( V_10 && ( V_4 & F_6 ( V_10 - 1 ) ) )
V_4 = F_7 ( V_4 , V_14 ) ;
else
V_4 = F_8 ( V_4 , V_14 ) ;
if ( V_4 > V_15 )
V_4 = V_15 ;
V_4 /= 50 ;
}
F_9 ( & V_2 -> V_16 ) ;
V_11 = F_10 ( V_6 -> V_17 + V_18 ) ;
if ( V_4 == 0 ) {
V_11 &= ~ F_6 ( V_3 ) ;
V_12 = 0 ;
} else {
V_11 |= F_6 ( V_3 ) ;
V_12 = V_4 ;
}
F_11 ( V_11 , V_6 -> V_17 + V_18 ) ;
F_11 ( V_12 , V_6 -> V_17 + F_12 ( V_3 ) ) ;
F_13 ( & V_2 -> V_16 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned V_19 ,
enum V_20 V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_22 ;
F_9 ( & V_2 -> V_16 ) ;
V_22 = F_10 ( V_6 -> V_17 + V_23 ) ;
if ( V_21 == V_24 )
V_22 |= F_6 ( V_19 ) ;
else
V_22 &= ~ F_6 ( V_19 ) ;
F_11 ( V_22 , V_6 -> V_17 + V_23 ) ;
F_13 ( & V_2 -> V_16 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_19 ,
unsigned long V_25 )
{
enum V_20 V_21 = F_16 ( V_25 ) ;
switch ( V_21 ) {
case V_24 :
case V_26 :
return F_14 ( V_2 , V_19 , V_21 ) ;
case V_27 :
return F_1 ( V_2 , V_19 ,
F_17 ( V_25 ) ) ;
default:
break;
}
return - V_28 ;
}
static int F_18 ( struct V_29 * V_30 ,
const struct V_31 * V_32 )
{
struct V_5 * V_5 ;
struct V_7 * V_8 = & V_30 -> V_8 ;
int V_33 ;
V_5 = F_19 ( V_8 , sizeof( struct V_5 ) ,
V_34 ) ;
if ( ! V_5 )
return - V_35 ;
V_5 -> V_36 = F_20 ( V_30 , F_21 ( V_8 ) ) ;
if ( F_22 ( V_5 -> V_36 ) ) {
F_4 ( V_8 , L_2 ) ;
return F_23 ( V_5 -> V_36 ) ;
}
V_5 -> V_17 = F_24 ( V_5 -> V_36 -> V_37 ,
F_25 ( V_5 -> V_36 ) ) ;
if ( V_5 -> V_17 == NULL ) {
V_33 = - V_38 ;
goto V_39;
}
F_26 ( V_30 , V_5 ) ;
V_33 = F_27 ( & V_5 -> V_2 , & V_30 -> V_8 , 4 ,
V_5 -> V_17 + V_40 ,
V_5 -> V_17 + V_41 ,
NULL ,
V_5 -> V_17 + V_42 ,
NULL , 0 ) ;
if ( V_33 )
goto V_43;
V_5 -> V_2 . V_44 = F_15 ;
V_33 = F_28 ( & V_5 -> V_2 , V_5 ) ;
if ( V_33 ) {
F_4 ( V_8 , L_3 ) ;
goto V_43;
}
F_29 ( V_8 , L_4 ) ;
return 0 ;
V_43:
F_30 ( V_5 -> V_17 ) ;
V_39:
F_31 ( V_5 -> V_36 ) ;
return V_33 ;
}
static void F_32 ( struct V_29 * V_30 )
{
struct V_5 * V_5 = F_33 ( V_30 ) ;
F_34 ( & V_5 -> V_2 ) ;
F_30 ( V_5 -> V_17 ) ;
F_31 ( V_5 -> V_36 ) ;
}
