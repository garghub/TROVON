int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 * V_4 )
{
struct V_5 * V_6 ;
T_2 * V_7 ;
int V_8 , V_9 , V_10 ;
V_10 = - V_11 ;
V_6 = F_2 ( V_2 , * V_3 + V_12 , V_7 ) ;
if ( ! V_6 )
return - V_13 ;
switch ( F_3 ( * V_7 ) ) {
case V_14 :
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
V_16 = (struct V_15 * ) V_6 -> V_19 ;
V_18 = V_16 -> V_20 ;
V_9 = 42 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_18 ++ , V_8 ++ ) {
if ( V_18 -> V_21 && V_18 -> V_22 &&
V_18 -> V_23 == F_4 ( 0x54465331 ) &&
( F_5 ( V_2 ) -> V_24 < 0 || F_5 ( V_2 ) -> V_24 == V_8 ) ) {
* V_3 += F_6 ( V_18 -> V_21 ) ;
* V_4 = F_6 ( V_18 -> V_22 ) ;
V_10 = 0 ;
}
}
break;
}
case V_25 :
{
struct V_26 * V_16 ;
V_16 = (struct V_26 * ) V_6 -> V_19 ;
V_9 = F_6 ( V_16 -> V_27 ) ;
for ( V_8 = 0 ; V_8 < V_9 ; ) {
if ( ! memcmp ( V_16 -> V_28 , L_1 , 9 ) &&
( F_5 ( V_2 ) -> V_24 < 0 || F_5 ( V_2 ) -> V_24 == V_8 ) ) {
* V_3 += F_6 ( V_16 -> V_29 ) ;
* V_4 = F_6 ( V_16 -> V_30 ) ;
V_10 = 0 ;
break;
}
F_7 ( V_6 ) ;
V_6 = F_2 ( V_2 , * V_3 + V_12 + ++ V_8 , V_16 ) ;
if ( ! V_6 )
return - V_13 ;
if ( V_16 -> V_31 != F_8 ( V_25 ) )
break;
}
break;
}
}
F_7 ( V_6 ) ;
return V_10 ;
}
