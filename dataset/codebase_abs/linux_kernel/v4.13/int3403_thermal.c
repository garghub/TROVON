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
F_2 ( V_7 -> V_11 ,
V_12 ) ;
break;
case V_13 :
F_3 ( V_7 -> V_11 ) ;
F_2 ( V_7 -> V_11 ,
V_14 ) ;
break;
default:
F_4 ( & V_5 -> V_15 -> V_16 , L_1 , V_2 ) ;
break;
}
}
static int F_5 ( struct V_4 * V_5 )
{
int V_17 = 0 ;
struct V_6 * V_7 ;
V_7 = F_6 ( & V_5 -> V_15 -> V_16 , sizeof( * V_7 ) , V_18 ) ;
if ( ! V_7 )
return - V_19 ;
V_5 -> V_5 = V_7 ;
V_7 -> V_11 = F_7 ( V_5 -> V_20 , NULL ) ;
if ( F_8 ( V_7 -> V_11 ) )
return F_9 ( V_7 -> V_11 ) ;
V_17 = F_10 ( V_5 -> V_20 -> V_1 ,
V_21 , F_1 ,
( void * ) V_5 ) ;
if ( V_17 )
goto V_22;
return 0 ;
V_22:
F_11 ( V_7 -> V_11 ) ;
return V_17 ;
}
static int F_12 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_5 ;
F_13 ( V_5 -> V_20 -> V_1 ,
V_21 , F_1 ) ;
F_11 ( V_7 -> V_11 ) ;
return 0 ;
}
static int F_14 ( struct V_23 * V_24 ,
unsigned long * V_25 )
{
struct V_4 * V_5 = V_24 -> V_26 ;
struct V_27 * V_7 = V_5 -> V_5 ;
* V_25 = V_7 -> V_28 ;
return 0 ;
}
static int F_15 ( struct V_23 * V_24 ,
unsigned long * V_25 )
{
struct V_4 * V_5 = V_24 -> V_26 ;
unsigned long long V_29 ;
T_3 V_30 ;
V_30 = F_16 ( V_5 -> V_20 -> V_1 , L_2 , NULL , & V_29 ) ;
if ( F_17 ( V_30 ) ) {
* V_25 = V_29 ;
return 0 ;
} else
return - V_31 ;
}
static int
F_18 ( struct V_23 * V_24 , unsigned long V_25 )
{
struct V_4 * V_5 = V_24 -> V_26 ;
T_3 V_30 ;
V_30 = F_19 ( V_5 -> V_20 -> V_1 , L_3 , V_25 ) ;
if ( F_17 ( V_30 ) )
return 0 ;
else
return - V_31 ;
}
static int F_20 ( struct V_4 * V_5 )
{
int V_17 = 0 ;
T_3 V_30 ;
struct V_27 * V_7 ;
struct V_32 V_33 = { V_34 , NULL } ;
union V_35 * V_36 ;
V_7 = F_6 ( & V_5 -> V_15 -> V_16 , sizeof( * V_7 ) , V_18 ) ;
if ( ! V_7 )
return - V_19 ;
V_30 = F_21 ( V_5 -> V_20 -> V_1 , L_4 , NULL , & V_33 ) ;
if ( F_22 ( V_30 ) )
return - V_37 ;
V_36 = V_33 . V_38 ;
if ( ! V_36 || ( V_36 -> type != V_39 ) ) {
F_23 ( V_40 L_5 ) ;
F_24 ( V_33 . V_38 ) ;
return - V_41 ;
}
V_7 -> V_28 = V_36 -> V_42 . V_43 - 1 ;
V_7 -> V_24 =
F_25 ( F_26 ( V_5 -> V_20 ) ,
V_5 , & V_44 ) ;
if ( F_8 ( V_7 -> V_24 ) )
V_17 = F_9 ( V_7 -> V_24 ) ;
V_5 -> V_5 = V_7 ;
F_24 ( V_33 . V_38 ) ;
return V_17 ;
}
static int F_27 ( struct V_4 * V_5 )
{
struct V_27 * V_7 = V_5 -> V_5 ;
F_28 ( V_7 -> V_24 ) ;
return 0 ;
}
static int F_29 ( struct V_45 * V_15 )
{
struct V_4 * V_5 ;
int V_17 = 0 ;
T_3 V_30 ;
V_5 = F_6 ( & V_15 -> V_16 , sizeof( struct V_4 ) ,
V_18 ) ;
if ( ! V_5 )
return - V_19 ;
V_5 -> V_15 = V_15 ;
V_5 -> V_20 = F_30 ( & ( V_15 -> V_16 ) ) ;
if ( ! V_5 -> V_20 ) {
V_17 = - V_31 ;
goto V_46;
}
V_30 = F_16 ( V_5 -> V_20 -> V_1 , L_6 ,
NULL , & V_5 -> type ) ;
if ( F_22 ( V_30 ) ) {
unsigned long long V_47 ;
V_30 = F_16 ( V_5 -> V_20 -> V_1 , L_7 ,
NULL , & V_47 ) ;
if ( F_22 ( V_30 ) ) {
V_17 = - V_31 ;
goto V_46;
} else {
V_5 -> type = V_8 ;
}
}
F_31 ( V_15 , V_5 ) ;
switch ( V_5 -> type ) {
case V_8 :
V_17 = F_5 ( V_5 ) ;
break;
case V_48 :
case V_49 :
V_17 = F_20 ( V_5 ) ;
break;
default:
V_17 = - V_31 ;
}
if ( V_17 )
goto V_46;
return V_17 ;
V_46:
return V_17 ;
}
static int F_32 ( struct V_45 * V_15 )
{
struct V_4 * V_5 = F_33 ( V_15 ) ;
switch ( V_5 -> type ) {
case V_8 :
F_12 ( V_5 ) ;
break;
case V_48 :
case V_49 :
F_27 ( V_5 ) ;
break;
default:
break;
}
return 0 ;
}
