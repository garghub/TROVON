int F_1 ( struct V_1 * V_2 , char * V_3 ,
T_1 V_4 , T_2 V_5 )
{
struct V_6 * V_7 ;
T_3 V_8 ;
V_7 = F_2 ( V_2 ) -> V_7 ;
if ( ! V_7 )
return - V_9 ;
V_8 = F_3 ( V_7 , V_3 , V_5 , V_4 ) ;
F_4 ( V_2 ) ;
return V_8 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
T_2 V_12 , T_2 V_5 )
{
char * V_13 ;
T_1 V_4 ;
int V_8 ;
V_4 = ( ( ( ( T_1 ) V_11 -> V_14 ) << V_15 )
+ V_12 ) ;
V_13 = F_6 ( V_11 ) ;
V_8 = F_1 ( V_2 , V_13 , V_4 , V_5 ) ;
if ( V_8 > 0 )
V_8 = 0 ;
F_7 ( V_11 ) ;
return V_8 ;
}
int F_8 ( struct V_1 * V_2 , char * V_3 , T_1 V_4 ,
T_2 V_5 )
{
struct V_10 * V_16 ;
struct V_17 * V_18 ;
char * V_19 ;
T_1 V_20 = F_9 ( V_2 ) ;
T_1 V_21 = 0 ;
T_1 V_22 ;
int V_8 = 0 ;
V_18 = & F_2 ( V_2 ) -> V_18 ;
if ( V_4 > V_20 )
V_22 = V_20 ;
else
V_22 = V_4 ;
while ( V_22 < ( V_4 + V_5 ) ) {
T_4 V_23 = ( V_22 >> V_15 ) ;
T_2 V_24 = ( V_22 & ~ V_25 ) ;
T_2 V_26 = ( V_27 - V_24 ) ;
T_1 V_28 = ( ( V_4 + V_5 ) - V_22 ) ;
if ( F_10 ( V_29 ) ) {
V_8 = - V_30 ;
break;
}
if ( V_26 > V_28 )
V_26 = V_28 ;
if ( V_22 < V_4 ) {
T_1 V_31 = ( V_4 - V_22 ) ;
if ( V_26 > V_31 )
V_26 = V_31 ;
}
V_16 = F_11 ( V_2 ,
V_23 ) ;
if ( F_12 ( V_16 ) ) {
V_8 = F_13 ( V_16 ) ;
F_14 ( V_32 L_1
L_2
L_3 , V_33 ,
V_23 , V_8 ) ;
goto V_34;
}
V_19 = F_15 ( V_16 ) ;
if ( V_22 < V_4 || ! V_24 ) {
memset ( ( ( char * ) V_19
+ V_24 ) , 0 ,
V_27 - V_24 ) ;
}
if ( V_22 >= V_4 ) {
memcpy ( ( ( char * ) V_19
+ V_24 ) ,
( V_3 + V_21 ) , V_26 ) ;
V_21 += V_26 ;
}
F_16 ( V_19 ) ;
F_17 ( V_16 ) ;
F_18 ( V_16 ) ;
F_19 ( V_16 ) ;
if ( V_18 -> V_35 & V_36 )
V_8 = F_20 ( V_16 ) ;
else
V_8 = F_5 ( V_2 ,
V_16 ,
V_24 ,
V_21 ) ;
F_21 ( V_16 ) ;
if ( V_8 ) {
F_14 ( V_32 L_4
L_5 , V_33 , V_8 ) ;
goto V_34;
}
V_22 += V_26 ;
}
if ( V_22 > V_20 ) {
F_22 ( V_2 , V_22 ) ;
if ( V_18 -> V_35 & V_36 ) {
int V_37 ;
V_37 = F_23 (
V_2 ) ;
if ( V_37 ) {
F_14 ( V_32 L_6
L_7
L_8 , V_37 ) ;
if ( ! V_8 )
V_8 = V_37 ;
goto V_34;
}
}
}
V_34:
return V_8 ;
}
int F_24 ( char * V_3 , T_1 V_4 , T_2 V_5 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) -> V_7 ;
if ( ! V_7 )
return - V_9 ;
return F_25 ( V_7 , V_4 , V_3 , V_5 ) ;
}
int F_26 ( struct V_10 * V_38 ,
T_4 V_39 ,
T_2 V_12 , T_2 V_5 ,
struct V_1 * V_2 )
{
char * V_13 ;
T_1 V_4 ;
int V_8 ;
V_4 = ( ( ( ( T_1 ) V_39 ) << V_15 ) + V_12 ) ;
V_13 = F_6 ( V_38 ) ;
V_8 = F_24 ( V_13 , V_4 , V_5 , V_2 ) ;
if ( V_8 > 0 )
V_8 = 0 ;
F_7 ( V_38 ) ;
F_17 ( V_38 ) ;
return V_8 ;
}
