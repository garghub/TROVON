static void F_1 ( T_1 V_1 ,
T_2 V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_5 ;
if ( V_5 -> type != V_8 || ! V_7 )
return;
switch ( V_2 ) {
case V_9 :
break;
case V_10 :
F_2 ( V_7 -> V_11 ) ;
break;
default:
F_3 ( & V_5 -> V_12 -> V_13 , L_1 , V_2 ) ;
break;
}
}
static int F_4 ( struct V_4 * V_5 )
{
int V_14 = 0 ;
struct V_6 * V_7 ;
V_7 = F_5 ( & V_5 -> V_12 -> V_13 , sizeof( * V_7 ) , V_15 ) ;
if ( ! V_7 )
return - V_16 ;
V_5 -> V_5 = V_7 ;
V_7 -> V_11 = F_6 ( V_5 -> V_17 , NULL ) ;
if ( F_7 ( V_7 -> V_11 ) )
return F_8 ( V_7 -> V_11 ) ;
V_14 = F_9 ( V_5 -> V_17 -> V_1 ,
V_18 , F_1 ,
( void * ) V_5 ) ;
if ( V_14 )
goto V_19;
return 0 ;
V_19:
F_10 ( V_7 -> V_11 ) ;
return V_14 ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_5 ;
F_12 ( V_5 -> V_17 -> V_1 ,
V_18 , F_1 ) ;
F_10 ( V_7 -> V_11 ) ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 ,
unsigned long * V_22 )
{
struct V_4 * V_5 = V_21 -> V_23 ;
struct V_24 * V_7 = V_5 -> V_5 ;
* V_22 = V_7 -> V_25 ;
return 0 ;
}
static int F_14 ( struct V_20 * V_21 ,
unsigned long * V_22 )
{
struct V_4 * V_5 = V_21 -> V_23 ;
unsigned long long V_26 ;
T_3 V_27 ;
V_27 = F_15 ( V_5 -> V_17 -> V_1 , L_2 , NULL , & V_26 ) ;
if ( F_16 ( V_27 ) ) {
* V_22 = V_26 ;
return 0 ;
} else
return - V_28 ;
}
static int
F_17 ( struct V_20 * V_21 , unsigned long V_22 )
{
struct V_4 * V_5 = V_21 -> V_23 ;
T_3 V_27 ;
V_27 = F_18 ( V_5 -> V_17 -> V_1 , L_3 , V_22 ) ;
if ( F_16 ( V_27 ) )
return 0 ;
else
return - V_28 ;
}
static int F_19 ( struct V_4 * V_5 )
{
int V_14 = 0 ;
T_3 V_27 ;
struct V_24 * V_7 ;
struct V_29 V_30 = { V_31 , NULL } ;
union V_32 * V_33 ;
V_7 = F_5 ( & V_5 -> V_12 -> V_13 , sizeof( * V_7 ) , V_15 ) ;
if ( ! V_7 )
return - V_16 ;
V_27 = F_20 ( V_5 -> V_17 -> V_1 , L_4 , NULL , & V_30 ) ;
if ( F_21 ( V_27 ) )
return - V_34 ;
V_33 = V_30 . V_35 ;
if ( ! V_33 || ( V_33 -> type != V_36 ) ) {
F_22 ( V_37 L_5 ) ;
F_23 ( V_30 . V_35 ) ;
return - V_38 ;
}
V_7 -> V_25 = V_33 -> V_39 . V_40 - 1 ;
V_7 -> V_21 =
F_24 ( F_25 ( V_5 -> V_17 ) ,
V_5 , & V_41 ) ;
if ( F_7 ( V_7 -> V_21 ) )
V_14 = F_8 ( V_7 -> V_21 ) ;
V_5 -> V_5 = V_7 ;
F_23 ( V_30 . V_35 ) ;
return V_14 ;
}
static int F_26 ( struct V_4 * V_5 )
{
struct V_24 * V_7 = V_5 -> V_5 ;
F_27 ( V_7 -> V_21 ) ;
return 0 ;
}
static int F_28 ( struct V_42 * V_12 )
{
struct V_4 * V_5 ;
int V_14 = 0 ;
T_3 V_27 ;
V_5 = F_5 ( & V_12 -> V_13 , sizeof( struct V_4 ) ,
V_15 ) ;
if ( ! V_5 )
return - V_16 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_17 = F_29 ( & ( V_12 -> V_13 ) ) ;
if ( ! V_5 -> V_17 ) {
V_14 = - V_28 ;
goto V_43;
}
V_27 = F_15 ( V_5 -> V_17 -> V_1 , L_6 ,
NULL , & V_5 -> type ) ;
if ( F_21 ( V_27 ) ) {
V_14 = - V_28 ;
goto V_43;
}
F_30 ( V_12 , V_5 ) ;
switch ( V_5 -> type ) {
case V_8 :
V_14 = F_4 ( V_5 ) ;
break;
case V_44 :
case V_45 :
V_14 = F_19 ( V_5 ) ;
break;
default:
V_14 = - V_28 ;
}
if ( V_14 )
goto V_43;
return V_14 ;
V_43:
return V_14 ;
}
static int F_31 ( struct V_42 * V_12 )
{
struct V_4 * V_5 = F_32 ( V_12 ) ;
switch ( V_5 -> type ) {
case V_8 :
F_11 ( V_5 ) ;
break;
case V_44 :
case V_45 :
F_26 ( V_5 ) ;
break;
default:
break;
}
return 0 ;
}
