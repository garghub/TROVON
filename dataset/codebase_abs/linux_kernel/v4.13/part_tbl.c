static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_5 , T_1 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 42 ; V_9 ++ ) {
struct V_10 * V_11 = & V_4 -> V_12 [ V_9 ] ;
if ( V_11 -> V_13 && V_11 -> V_14 &&
V_11 -> V_15 == F_3 ( 0x54465331 ) &&
( V_8 -> V_16 < 0 || V_8 -> V_16 == V_9 ) ) {
* V_5 += F_4 ( V_11 -> V_13 ) ;
* V_6 = F_4 ( V_11 -> V_14 ) ;
return 0 ;
}
}
return - V_17 ;
}
static int F_5 ( struct V_1 * V_2 , void * V_18 ,
struct V_19 * V_4 , T_1 * V_5 , T_1 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_20 = F_4 ( V_4 -> V_21 ) ;
int V_22 = F_6 ( V_2 ) ;
int V_23 ;
int V_9 = 0 ;
do {
if ( ! memcmp ( V_4 -> V_24 , L_1 , 9 ) &&
( V_8 -> V_16 < 0 || V_8 -> V_16 == V_9 ) ) {
* V_5 += F_4 ( V_4 -> V_25 ) ;
* V_6 = F_4 ( V_4 -> V_26 ) ;
return 0 ;
}
if ( ++ V_9 >= V_20 )
return - V_17 ;
V_4 = (struct V_19 * ) ( ( V_27 * ) V_4 + V_28 ) ;
if ( ( V_27 * ) V_4 - ( V_27 * ) V_18 >= V_22 ) {
V_23 = F_7 ( V_2 ,
* V_5 + V_29 + V_9 ,
V_18 , ( void * * ) & V_4 , V_30 ,
0 ) ;
if ( V_23 )
return V_23 ;
}
} while ( V_4 -> V_31 == F_8 ( V_32 ) );
return - V_17 ;
}
int F_9 ( struct V_1 * V_2 ,
T_1 * V_5 , T_1 * V_6 )
{
void * V_18 , * V_33 ;
int V_23 ;
V_18 = F_10 ( F_6 ( V_2 ) , V_34 ) ;
if ( ! V_18 )
return - V_35 ;
V_23 = F_7 ( V_2 , * V_5 + V_29 ,
V_18 , & V_33 , V_30 , 0 ) ;
if ( V_23 )
goto V_36;
switch ( F_11 ( * ( ( V_37 * ) V_33 ) ) ) {
case V_38 :
V_23 = F_1 ( V_2 , V_33 , V_5 , V_6 ) ;
break;
case V_32 :
V_23 = F_5 ( V_2 , V_18 , V_33 , V_5 , V_6 ) ;
break;
default:
V_23 = - V_17 ;
break;
}
V_36:
F_12 ( V_18 ) ;
return V_23 ;
}
