static inline void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 ) ;
V_4 -> V_5 = V_2 -> V_6 [ 0 ] ;
}
static inline void
F_3 ( struct V_7 * V_8 , struct V_3 * V_4 )
{
F_2 ( V_4 -> V_9 ) ;
V_4 -> V_9 = V_8 -> V_10 [ 0 ] ;
}
static inline T_1
F_4 ( struct V_11 * V_12 , T_2 V_13 , T_1 V_14 )
{
F_2 ( V_12 -> V_15 % V_14 ) ;
return ( V_13 * ( V_12 -> V_15 / V_14 ) ) ;
}
int
F_5 ( struct V_11 * V_12 , T_1 V_14 )
{
struct V_3 * V_4 = F_6 ( V_12 ) ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
char * V_20 , * V_21 ;
V_17 = F_7 ( V_12 , F_4 ( V_12 , V_4 -> V_22 , V_14 ) ) ;
if ( ! V_17 || ! V_17 -> V_23 )
goto V_24;
V_19 = (struct V_18 * ) V_17 -> V_23 ;
if ( V_19 -> V_25 != V_26 ) {
F_8 ( V_27 L_1 ) ;
goto V_24;
}
if ( V_4 -> V_28 > 1 ) {
F_8 ( V_27 L_2 ) ;
F_8 ( V_27 L_3 ) ;
goto V_24;
}
V_20 = V_17 -> V_23 + V_19 -> V_29 ;
V_21 = V_17 -> V_23 + ( V_4 -> V_28 * V_12 -> V_15 ) ;
while ( V_20 < V_21 ) {
struct V_30 * V_31 =
(struct V_30 * ) V_20 ;
switch ( V_31 -> V_32 ) {
case V_33 :
F_1 ( (struct V_1 * ) V_20 , V_4 ) ;
break;
case V_34 :
F_3 ( (struct V_7 * ) V_20 , V_4 ) ;
break;
}
V_20 += V_31 -> V_29 ;
}
F_9 ( V_17 ) ;
return 0 ;
V_24:
F_9 ( V_17 ) ;
return - V_35 ;
}
