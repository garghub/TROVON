static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_5 ,
unsigned long V_6 , void * V_7 )
{
struct V_1 * V_8 = F_1 ( V_5 ) ;
if ( V_8 ) {
F_4 ( V_8 -> V_9 ) ;
F_4 ( V_8 -> V_10 ) ;
}
return V_11 ;
}
static int F_5 ( struct V_12 * V_13 , struct V_1 * V_8 ,
T_1 * V_14 )
{
const struct V_15 * V_16 ;
void * V_17 ;
T_1 V_18 ;
T_2 V_19 ;
int V_20 ;
V_20 = F_6 ( & V_16 , V_8 -> V_21 , V_13 ) ;
if ( V_20 ) {
F_7 ( V_13 , L_1 ,
V_8 -> V_21 , V_20 ) ;
return V_20 ;
}
V_19 = V_16 -> V_19 + V_22 ;
V_17 = F_8 ( V_13 , V_19 , & V_18 , V_23 ) ;
if ( V_17 ) {
V_17 = F_9 ( V_17 , V_22 ) ;
* V_14 = F_10 ( V_18 , V_22 ) ;
memcpy ( V_17 , V_16 -> V_24 , V_16 -> V_19 ) ;
} else {
F_7 ( V_13 , L_2 ) ;
V_20 = - V_25 ;
}
F_11 ( V_16 ) ;
return V_20 ;
}
static int F_12 ( struct V_26 * V_27 ,
struct V_1 * V_8 )
{
struct V_12 * V_13 = & V_27 -> V_13 ;
const struct V_28 * V_29 ;
T_3 V_30 ;
int V_20 ;
struct V_31 * V_32 ;
V_29 = F_13 ( V_13 ) ;
V_8 -> V_33 = F_14 ( V_13 , NULL ) ;
if ( F_15 ( V_8 -> V_33 ) ) {
F_7 ( V_13 , L_3 ) ;
return F_16 ( V_8 -> V_33 ) ;
}
V_32 = F_17 ( V_27 , V_34 , 0 ) ;
V_8 -> V_35 = F_18 ( V_13 , V_32 ) ;
if ( F_15 ( V_8 -> V_35 ) )
return F_16 ( V_8 -> V_35 ) ;
V_8 -> V_9 = F_19 ( V_13 , L_4 ) ;
if ( F_15 ( V_8 -> V_9 ) ) {
if ( F_16 ( V_8 -> V_9 ) != - V_36 )
F_7 ( V_13 , L_5 ) ;
return F_16 ( V_8 -> V_9 ) ;
}
V_8 -> V_10 = F_20 ( V_13 , L_6 ) ;
if ( F_15 ( V_8 -> V_10 ) )
return F_16 ( V_8 -> V_10 ) ;
V_20 = F_21 ( V_13 , L_7 , & V_30 ) ;
if ( V_20 )
V_30 = V_37 ;
switch ( V_30 ) {
case V_38 :
V_8 -> V_21 = V_29 -> V_39 ;
break;
case V_37 :
V_8 -> V_21 = V_29 -> V_40 ;
break;
default:
F_7 ( V_13 , L_8 , V_30 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_22 ( struct V_26 * V_27 )
{
struct V_12 * V_13 = & V_27 -> V_13 ;
struct V_1 * V_8 ;
T_1 V_17 = 0 ;
int V_20 ;
V_8 = F_23 ( V_13 , sizeof( * V_8 ) , V_23 ) ;
if ( ! V_8 )
return - V_25 ;
V_20 = F_12 ( V_27 , V_8 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_24 ( V_8 -> V_33 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_5 ( V_13 , V_8 , & V_17 ) ;
if ( V_20 ) {
F_25 ( V_8 -> V_33 ) ;
return V_20 ;
}
F_4 ( V_8 -> V_9 ) ;
F_4 ( V_8 -> V_10 ) ;
F_26 ( V_17 , V_8 -> V_35 ) ;
F_27 ( V_8 -> V_9 ) ;
F_27 ( V_8 -> V_10 ) ;
V_8 -> V_4 . V_42 = F_3 ;
V_8 -> V_4 . V_43 = - 1 ;
V_20 = F_28 ( & V_8 -> V_4 ) ;
if ( V_20 )
F_29 ( V_13 , L_9 ) ;
F_30 ( V_27 , V_8 ) ;
return V_20 ;
}
static int F_31 ( struct V_26 * V_27 )
{
struct V_12 * V_13 = & V_27 -> V_13 ;
struct V_1 * V_8 = F_32 ( V_27 ) ;
int V_20 ;
F_4 ( V_8 -> V_9 ) ;
F_4 ( V_8 -> V_10 ) ;
F_26 ( 0 , V_8 -> V_35 ) ;
F_25 ( V_8 -> V_33 ) ;
V_20 = F_33 ( & V_8 -> V_4 ) ;
if ( V_20 )
F_29 ( V_13 , L_10 ) ;
return 0 ;
}
