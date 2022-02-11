static struct V_1 * F_1 ( T_1 V_2 ,
struct V_3 * V_3 , T_2 V_4 )
{
struct V_1 * V_1 ;
V_1 = F_2 ( V_2 , 1 ) ;
if ( V_1 ) {
V_1 -> V_5 = F_3 ( V_3 , & V_1 -> V_6 ) ;
V_1 -> V_5 <<= V_7 - 9 ;
V_1 -> V_8 [ 0 ] . V_9 = V_3 ;
V_1 -> V_8 [ 0 ] . V_10 = V_11 ;
V_1 -> V_8 [ 0 ] . V_12 = 0 ;
V_1 -> V_13 = 1 ;
V_1 -> V_14 = 0 ;
V_1 -> V_15 = V_11 ;
V_1 -> V_16 = V_4 ;
}
return V_1 ;
}
static void F_4 ( struct V_1 * V_1 , int V_17 )
{
const int V_18 = F_5 ( V_19 , & V_1 -> V_20 ) ;
struct V_3 * V_3 = V_1 -> V_8 [ 0 ] . V_9 ;
if ( ! V_18 ) {
F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
F_8 ( V_21 L_1 ,
F_9 ( V_1 -> V_6 -> V_22 ) ,
F_10 ( V_1 -> V_6 -> V_22 ) ,
( unsigned long long ) V_1 -> V_5 ) ;
F_11 ( V_3 ) ;
}
F_12 ( V_3 ) ;
F_13 ( V_1 ) ;
}
void F_14 ( struct V_1 * V_1 , int V_17 )
{
const int V_18 = F_5 ( V_19 , & V_1 -> V_20 ) ;
struct V_3 * V_3 = V_1 -> V_8 [ 0 ] . V_9 ;
if ( ! V_18 ) {
F_6 ( V_3 ) ;
F_15 ( V_3 ) ;
F_8 ( V_21 L_2 ,
F_9 ( V_1 -> V_6 -> V_22 ) ,
F_10 ( V_1 -> V_6 -> V_22 ) ,
( unsigned long long ) V_1 -> V_5 ) ;
} else {
F_16 ( V_3 ) ;
}
F_17 ( V_3 ) ;
F_13 ( V_1 ) ;
}
int F_18 ( struct V_3 * V_3 , struct V_23 * V_24 )
{
struct V_1 * V_1 ;
int V_25 = 0 , V_26 = V_27 ;
if ( F_19 ( V_3 ) ) {
F_17 ( V_3 ) ;
goto V_28;
}
if ( F_20 ( V_3 ) == 0 ) {
F_21 ( V_3 ) ;
F_17 ( V_3 ) ;
F_12 ( V_3 ) ;
goto V_28;
}
V_1 = F_1 ( V_29 , V_3 , F_4 ) ;
if ( V_1 == NULL ) {
F_7 ( V_3 ) ;
F_17 ( V_3 ) ;
V_25 = - V_30 ;
goto V_28;
}
if ( V_24 -> V_31 == V_32 )
V_26 |= V_33 ;
F_22 ( V_34 ) ;
F_21 ( V_3 ) ;
F_17 ( V_3 ) ;
F_23 ( V_26 , V_1 ) ;
V_28:
return V_25 ;
}
int F_24 ( struct V_3 * V_3 )
{
struct V_1 * V_1 ;
int V_25 = 0 ;
F_25 ( ! F_26 ( V_3 ) ) ;
F_25 ( F_27 ( V_3 ) ) ;
if ( F_28 ( V_3 ) == 0 ) {
F_16 ( V_3 ) ;
F_17 ( V_3 ) ;
goto V_28;
}
V_1 = F_1 ( V_35 , V_3 , F_14 ) ;
if ( V_1 == NULL ) {
F_17 ( V_3 ) ;
V_25 = - V_30 ;
goto V_28;
}
F_22 ( V_36 ) ;
F_23 ( V_37 , V_1 ) ;
V_28:
return V_25 ;
}
