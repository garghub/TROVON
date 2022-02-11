T_1 F_1 ( T_2 * V_1 )
{
T_1 V_2 = V_3 ;
T_3 * V_4 ;
T_2 V_5 = NULL ;
int V_6 ;
F_2 ( V_7 , L_1 , V_8 ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
V_4 = F_3 () ;
if ( V_4 )
break;
F_4 ( 500 ) ;
}
if ( V_6 == V_9 ) {
F_5 ( V_7 ,
L_2 , V_8 ) ;
goto V_10;
} else if ( V_6 > 0 ) {
F_6 ( V_7 ,
L_3 , V_8 , V_6 ) ;
}
V_5 = F_7 ( sizeof( * V_5 ) , V_11 ) ;
if ( ! V_5 ) {
F_5 ( V_7 ,
L_4 , V_8 ) ;
goto V_10;
}
V_5 -> V_12 = 0 ;
V_5 -> V_4 = V_4 ;
F_8 ( & V_5 -> V_13 ) ;
F_9 ( & V_5 -> V_14 ) ;
* V_1 = V_5 ;
V_2 = V_15 ;
V_10:
F_2 ( V_7 ,
L_5 , V_8 , V_5 , V_2 ) ;
return V_2 ;
}
T_1 F_10 ( T_2 V_5 )
{
T_1 V_2 ;
T_3 * V_4 = V_5 -> V_4 ;
F_2 ( V_7 ,
L_6 , V_8 , V_5 ) ;
if ( F_11 ( & V_4 -> V_16 ) != 0 )
return V_17 ;
V_2 = F_12 ( V_4 , V_5 ) ;
F_13 ( & V_4 -> V_16 ) ;
F_2 ( V_7 ,
L_5 , V_8 , V_5 , V_2 ) ;
if ( V_2 == V_15 ) {
struct V_18 * V_19 , * V_20 ;
F_14 (pos, next,
&instance->bulk_waiter_list) {
struct V_21 * V_22 ;
V_22 = F_15 ( V_19 ,
struct V_21 ,
V_23 ) ;
F_16 ( V_19 ) ;
F_17 ( V_24 ,
L_7
L_8 ,
( unsigned int ) V_22 , V_22 -> V_25 ) ;
F_18 ( V_22 ) ;
}
F_18 ( V_5 ) ;
}
return V_2 ;
}
int F_19 ( T_2 V_5 )
{
return V_5 -> V_12 ;
}
T_1 F_20 ( T_2 V_5 )
{
T_1 V_2 ;
T_3 * V_4 = V_5 -> V_4 ;
F_2 ( V_7 ,
L_6 , V_8 , V_5 ) ;
if ( F_11 ( & V_4 -> V_16 ) != 0 ) {
F_2 ( V_7 ,
L_9 , V_8 ) ;
V_2 = V_17 ;
goto V_10;
}
V_2 = F_21 ( V_4 , V_5 ) ;
if ( V_2 == V_15 )
V_5 -> V_12 = 1 ;
F_13 ( & V_4 -> V_16 ) ;
V_10:
F_2 ( V_7 ,
L_5 , V_8 , V_5 , V_2 ) ;
return V_2 ;
}
T_1 F_22 (
T_2 V_5 ,
const T_4 * V_26 ,
T_5 * V_27 )
{
T_1 V_2 ;
T_3 * V_4 = V_5 -> V_4 ;
T_6 * V_28 = NULL ;
int V_29 ;
F_2 ( V_7 ,
L_6 , V_8 , V_5 ) ;
* V_27 = V_30 ;
V_29 = F_19 ( V_5 )
? V_31
: V_32 ;
V_28 = F_23 (
V_4 ,
V_26 ,
V_29 ,
V_5 ,
NULL ) ;
if ( V_28 ) {
* V_27 = V_28 -> V_33 ;
V_2 = V_15 ;
} else
V_2 = V_3 ;
F_2 ( V_7 ,
L_5 , V_8 , V_5 , V_2 ) ;
return V_2 ;
}
T_1 F_24 (
T_2 V_5 ,
const T_4 * V_26 ,
T_5 * V_27 )
{
T_1 V_2 = V_3 ;
T_3 * V_4 = V_5 -> V_4 ;
T_6 * V_28 = NULL ;
F_2 ( V_7 ,
L_6 , V_8 , V_5 ) ;
* V_27 = V_30 ;
if ( ! F_19 ( V_5 ) )
goto V_10;
V_28 = F_23 ( V_4 ,
V_26 ,
V_34 ,
V_5 ,
NULL ) ;
if ( V_28 ) {
* V_27 = V_28 -> V_33 ;
V_2 = F_25 ( V_28 , V_35 -> V_25 ) ;
if ( V_2 != V_15 ) {
F_26 ( V_28 -> V_33 ) ;
* V_27 = V_30 ;
}
}
V_10:
F_2 ( V_7 ,
L_5 , V_8 , V_5 , V_2 ) ;
return V_2 ;
}
T_1
F_27 ( T_5 V_33 ,
const void * V_36 , unsigned int V_37 , void * V_38 )
{
return F_28 ( V_33 ,
V_39 , ( void * ) V_36 , V_37 , V_38 ,
V_40 , V_41 ) ;
}
T_1
F_29 ( T_5 V_33 , void * V_36 ,
unsigned int V_37 , void * V_38 )
{
return F_28 ( V_33 ,
V_39 , V_36 , V_37 , V_38 ,
V_40 , V_42 ) ;
}
T_1
F_30 ( T_5 V_33 , const void * V_36 ,
unsigned int V_37 , void * V_38 , T_7 V_43 )
{
T_1 V_2 ;
switch ( V_43 ) {
case V_44 :
case V_40 :
V_2 = F_28 ( V_33 ,
V_39 , ( void * ) V_36 , V_37 , V_38 ,
V_43 , V_41 ) ;
break;
case V_45 :
V_2 = F_31 ( V_33 ,
( void * ) V_36 , V_37 , V_41 ) ;
break;
default:
return V_3 ;
}
return V_2 ;
}
T_1
F_32 ( T_5 V_33 , void * V_36 ,
unsigned int V_37 , void * V_38 , T_7 V_43 )
{
T_1 V_2 ;
switch ( V_43 ) {
case V_44 :
case V_40 :
V_2 = F_28 ( V_33 ,
V_39 , V_36 , V_37 , V_38 ,
V_43 , V_42 ) ;
break;
case V_45 :
V_2 = F_31 ( V_33 ,
( void * ) V_36 , V_37 , V_42 ) ;
break;
default:
return V_3 ;
}
return V_2 ;
}
static T_1
F_31 ( T_5 V_33 , void * V_36 ,
unsigned int V_37 , T_8 V_46 )
{
T_2 V_5 ;
T_6 * V_28 ;
T_1 V_2 ;
struct V_21 * V_22 = NULL ;
struct V_18 * V_19 ;
V_28 = F_33 ( V_33 ) ;
if ( ! V_28 )
return V_3 ;
V_5 = V_28 -> V_5 ;
F_34 ( V_28 ) ;
F_35 ( & V_5 -> V_13 ) ;
F_36 (pos, &instance->bulk_waiter_list) {
if ( F_15 ( V_19 , struct V_21 ,
V_23 ) -> V_25 == V_35 -> V_25 ) {
V_22 = F_15 ( V_19 ,
struct V_21 ,
V_23 ) ;
F_16 ( V_19 ) ;
break;
}
}
F_13 ( & V_5 -> V_13 ) ;
if ( V_22 ) {
T_9 * V_47 = V_22 -> V_48 . V_47 ;
if ( V_47 ) {
if ( ( V_47 -> V_36 != V_36 ) ||
( V_47 -> V_37 != V_37 ) ) {
F_37 ( & V_49 ) ;
V_47 -> V_38 = NULL ;
F_38 ( & V_49 ) ;
}
}
}
if ( ! V_22 ) {
V_22 = F_7 ( sizeof( struct V_21 ) , V_11 ) ;
if ( ! V_22 ) {
F_5 ( V_7 ,
L_10 , V_8 ) ;
return V_3 ;
}
}
V_2 = F_28 ( V_33 , V_39 ,
V_36 , V_37 , & V_22 -> V_48 , V_45 ,
V_46 ) ;
if ( ( V_2 != V_17 ) || F_39 ( V_35 ) ||
! V_22 -> V_48 . V_47 ) {
T_9 * V_47 = V_22 -> V_48 . V_47 ;
if ( V_47 ) {
F_37 ( & V_49 ) ;
V_47 -> V_38 = NULL ;
F_38 ( & V_49 ) ;
}
F_18 ( V_22 ) ;
} else {
V_22 -> V_25 = V_35 -> V_25 ;
F_35 ( & V_5 -> V_13 ) ;
F_40 ( & V_22 -> V_23 , & V_5 -> V_14 ) ;
F_13 ( & V_5 -> V_13 ) ;
F_17 ( V_24 ,
L_11 ,
( unsigned int ) V_22 , V_35 -> V_25 ) ;
}
return V_2 ;
}
