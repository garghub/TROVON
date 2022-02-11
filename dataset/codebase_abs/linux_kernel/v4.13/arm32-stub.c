T_1 F_1 ( T_2 * V_1 )
{
int V_2 ;
if ( ! F_2 ( V_3 ) )
return V_4 ;
V_2 = F_3 ( V_5 , 0 ) ;
if ( V_2 < 5 ) {
F_4 ( V_1 , L_1 ) ;
return V_6 ;
}
return V_4 ;
}
struct V_7 * F_5 ( T_2 * V_1 )
{
struct V_7 * V_8 ;
T_1 V_9 ;
V_9 = F_6 ( V_10 , V_11 ,
sizeof( * V_8 ) , ( void * * ) & V_8 ) ;
if ( V_9 != V_4 )
return NULL ;
V_9 = F_6 ( V_12 ,
& V_13 , V_8 ) ;
if ( V_9 == V_4 )
return V_8 ;
F_6 ( V_14 , V_8 ) ;
return NULL ;
}
void F_7 ( T_2 * V_1 , struct V_7 * V_8 )
{
if ( ! V_8 )
return;
F_6 ( V_12 , & V_13 , NULL ) ;
F_6 ( V_14 , V_8 ) ;
}
static T_1 F_8 ( T_2 * V_1 ,
unsigned long V_15 ,
unsigned long * V_16 ,
unsigned long * V_17 )
{
T_3 V_18 ;
T_4 * V_19 ;
unsigned long V_20 , V_21 , V_22 , V_23 ;
T_1 V_9 ;
unsigned long V_24 ;
struct V_25 V_26 = {
. V_26 = & V_19 ,
. V_21 = & V_21 ,
. V_22 = & V_22 ,
. V_27 = NULL ,
. V_28 = NULL ,
. V_23 = & V_23 ,
} ;
V_18 = V_15 + V_29 ;
V_20 = V_29 / V_30 ;
V_9 = F_6 ( V_31 , V_32 ,
V_33 , V_20 , & V_18 ) ;
if ( V_9 == V_4 ) {
if ( V_18 == V_15 ) {
* V_16 = V_18 ;
* V_17 = V_29 ;
return V_4 ;
}
}
V_9 = F_9 ( V_1 , & V_26 ) ;
if ( V_9 != V_4 ) {
F_4 ( V_1 ,
L_2 ) ;
return V_9 ;
}
for ( V_24 = 0 ; V_24 < V_21 ; V_24 += V_22 ) {
T_4 * V_34 ;
T_5 V_35 , V_36 ;
V_34 = ( void * ) V_19 + V_24 ;
V_35 = V_34 -> V_37 ;
V_36 = V_35 + V_34 -> V_38 * V_30 ;
if ( V_35 >= V_15 + V_29 ||
V_36 <= V_15 )
continue;
switch ( V_34 -> type ) {
case V_39 :
case V_33 :
continue;
case V_40 :
V_35 = F_10 ( V_35 , ( T_5 ) V_15 ) ;
V_36 = F_11 ( V_36 , ( T_5 ) V_15 + V_29 ) ;
V_9 = F_6 ( V_31 ,
V_41 ,
V_42 ,
( V_36 - V_35 ) / V_30 ,
& V_35 ) ;
if ( V_9 != V_4 ) {
F_4 ( V_1 ,
L_3 ) ;
goto V_43;
}
break;
case V_44 :
case V_42 :
default:
V_9 = V_45 ;
goto V_43;
}
}
V_9 = V_4 ;
V_43:
F_6 ( V_14 , V_19 ) ;
return V_9 ;
}
T_1 F_12 ( T_2 * V_46 ,
unsigned long * V_47 ,
unsigned long * V_48 ,
unsigned long * V_16 ,
unsigned long * V_17 ,
unsigned long V_15 ,
T_6 * V_49 )
{
T_1 V_9 ;
V_15 = F_13 ( V_15 , V_50 ) ;
V_9 = F_8 ( V_46 , V_15 , V_16 ,
V_17 ) ;
if ( V_9 != V_4 ) {
F_4 ( V_46 , L_4 ) ;
return V_9 ;
}
* V_48 = V_49 -> V_48 ;
V_9 = F_14 ( V_46 , V_47 , * V_48 ,
* V_48 ,
V_15 + V_29 , 0 ) ;
if ( V_9 != V_4 ) {
F_4 ( V_46 , L_5 ) ;
F_15 ( V_46 , * V_17 , * V_16 ) ;
* V_17 = 0 ;
return V_9 ;
}
if ( * V_47 + * V_48 > V_15 + V_51 ) {
F_4 ( V_46 , L_6 ) ;
F_15 ( V_46 , * V_17 , * V_16 ) ;
* V_17 = 0 ;
F_15 ( V_46 , * V_48 , * V_47 ) ;
* V_48 = 0 ;
return V_52 ;
}
return V_4 ;
}
