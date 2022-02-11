static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
T_2 V_4 ,
T_2 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = (struct V_9 * ) V_7 -> V_11 ;
T_2 V_12 , V_13 ;
T_2 V_14 = V_10 -> V_15 ;
T_2 V_16 ;
T_2 V_17 ;
V_17 = V_18 ;
for ( V_12 = 0 , V_13 = 0 ; V_13 < V_5 ; V_13 ++ , V_12 += V_14 ) {
V_16 = V_17 ;
if ( F_2 ( V_7 ,
V_16 ,
( T_1 * ) ( V_3 + V_12 ) ,
V_14 ) ) {
F_3 ( V_19 ,
L_1 , V_20 ,
V_21 ) ;
return - V_22 ;
}
F_3 ( V_23 , L_2 , V_20 , V_13 ) ;
V_17 += V_14 ;
}
if ( V_4 % V_14 ) {
V_16 = V_17 ;
if ( F_2 ( V_7 ,
V_16 ,
( T_1 * ) ( V_3 + V_12 ) ,
V_4 % V_14 ) ) {
F_3 ( V_19 ,
L_1 , V_20 ,
V_21 ) ;
return - V_22 ;
}
}
F_3 ( V_23 ,
L_3 , V_20 ,
V_21 ) ;
F_3 ( V_23 , L_4 , V_20 ) ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = (struct V_9 * ) V_7 -> V_11 ;
int V_24 ;
do {
F_5 ( & V_10 -> V_25 . V_26 , V_27 ) ;
if ( F_6 ( & V_10 -> V_25 . V_28 ) )
goto V_29;
F_7 ( & V_2 -> V_30 ) ;
V_24 = F_8 ( V_2 , 0 ) ;
if ( V_24 ) {
F_3 ( V_19 , L_5 , V_20 ) ;
F_9 ( & V_2 -> V_30 ) ;
return;
}
F_9 ( & V_2 -> V_30 ) ;
F_10 ( & V_10 -> V_25 . V_26 ) ;
if ( V_7 -> V_31 ( V_7 ) ) {
F_3 ( V_19 ,
L_6 , V_20 ) ;
return;
}
} while ( 1 );
V_29:
F_3 ( V_32 , L_7 , V_20 ) ;
F_11 ( & V_10 -> V_25 . V_33 , 0 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = (struct V_9 * ) V_7 -> V_11 ;
const struct V_34 * V_35 = NULL ;
T_2 V_14 = V_10 -> V_15 ;
const T_1 * V_3 ;
T_2 V_5 , V_4 ;
int V_24 = 0 ;
V_24 = F_13 ( & V_35 , V_21 , V_7 -> V_36 ) ;
if ( V_24 < 0 ) {
F_3 ( V_19 , L_8 ,
V_20 , V_21 ) ;
return V_24 ;
}
V_3 = F_14 ( V_35 -> V_37 , V_35 -> V_38 , V_39 ) ;
if ( ! V_3 )
return - V_40 ;
V_4 = V_35 -> V_38 ;
if ( V_4 % 4 )
V_4 += ( 4 - ( V_4 % 4 ) ) ;
V_5 = ( V_4 / V_14 ) ;
F_3 ( V_23 , L_9 , V_20 , V_4 ) ;
F_3 ( V_23 , L_10 , V_20 , V_5 ) ;
V_24 = F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
F_15 ( V_3 ) ;
F_16 ( V_35 ) ;
return V_24 ;
}
int F_17 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) )
return - V_22 ;
return 0 ;
}
