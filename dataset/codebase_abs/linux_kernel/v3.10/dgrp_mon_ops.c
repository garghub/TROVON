static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
T_1 time ;
T_2 * V_7 ;
int V_8 ;
V_8 = F_2 ( V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_8 = 0 ;
if ( ! F_3 ( V_11 ) ) {
V_8 = - V_12 ;
goto V_13;
}
if ( V_2 -> V_14 ) {
V_8 = - V_15 ;
goto V_13;
}
V_4 = F_4 ( V_1 ) ;
if ( ! V_4 ) {
V_8 = - V_10 ;
goto V_13;
}
V_2 -> V_14 = ( void * ) V_4 ;
F_5 ( & V_4 -> V_16 ) ;
if ( V_4 -> V_17 ) {
V_8 = - V_18 ;
goto V_19;
}
V_4 -> V_17 = F_6 ( V_20 , V_21 ) ;
if ( ! V_4 -> V_17 ) {
V_8 = - V_22 ;
goto V_19;
}
V_7 = V_4 -> V_17 ;
strcpy ( V_7 , V_23 ) ;
V_7 += strlen ( V_7 ) + 1 ;
F_7 ( & V_6 ) ;
time = ( T_1 ) ( V_6 . V_24 & 0xffffffff ) ;
F_8 ( time , V_7 ) ;
F_9 ( 0 , V_7 + 4 ) ;
V_7 += 6 ;
if ( V_4 -> V_25 ) {
V_7 [ 0 ] = V_26 ;
F_8 ( 0 , V_7 + 1 ) ;
F_9 ( 1 , V_7 + 5 ) ;
V_7 [ 7 ] = 0xf0 + V_4 -> V_25 ;
V_7 += 8 ;
}
if ( V_4 -> V_27 ) {
V_7 [ 0 ] = V_28 ;
F_8 ( 0 , V_7 + 1 ) ;
F_9 ( 1 , V_7 + 5 ) ;
V_7 [ 7 ] = 0xf0 + V_4 -> V_27 ;
V_7 += 8 ;
}
V_4 -> V_29 = 0 ;
V_4 -> V_30 = V_7 - V_4 -> V_17 ;
V_4 -> V_31 = V_32 ;
V_19:
F_10 ( & V_4 -> V_16 ) ;
V_13:
if ( V_8 )
F_11 ( V_9 ) ;
return V_8 ;
}
static int F_12 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) ( V_2 -> V_14 ) ;
if ( ! V_4 )
goto V_13;
F_5 ( & V_4 -> V_16 ) ;
F_13 ( V_4 -> V_17 ) ;
V_4 -> V_17 = NULL ;
V_4 -> V_29 = V_4 -> V_30 ;
if ( V_4 -> V_33 & V_34 ) {
V_4 -> V_33 &= ~ V_34 ;
F_14 ( & V_4 -> V_35 ) ;
}
F_10 ( & V_4 -> V_16 ) ;
F_5 ( & V_4 -> V_36 ) ;
F_10 ( & V_4 -> V_36 ) ;
V_13:
F_11 ( V_9 ) ;
V_2 -> V_14 = NULL ;
return 0 ;
}
static T_3 F_15 ( struct V_2 * V_2 , char T_4 * V_7 , T_5 V_37 ,
T_6 * V_38 )
{
struct V_3 * V_4 ;
int V_39 ;
int V_40 = 0 ;
int V_41 = 0 ;
T_3 V_8 ;
V_4 = (struct V_3 * ) ( V_2 -> V_14 ) ;
if ( ! V_4 )
return - V_10 ;
F_5 ( & V_4 -> V_16 ) ;
for (; ; ) {
V_41 = ( V_4 -> V_30 - V_4 -> V_29 ) & V_42 ;
if ( V_41 )
break;
V_4 -> V_33 |= V_43 ;
F_10 ( & V_4 -> V_16 ) ;
V_8 = F_16 ( V_4 -> V_35 ,
( ( V_4 -> V_33 & V_43 ) == 0 ) ) ;
if ( V_8 )
return V_8 ;
F_5 ( & V_4 -> V_16 ) ;
}
if ( V_41 > V_37 )
V_41 = V_37 ;
V_39 = V_20 - V_4 -> V_29 ;
if ( V_39 <= V_41 ) {
V_8 = F_17 ( ( void T_4 * ) V_7 ,
V_4 -> V_17 + V_4 -> V_29 , V_39 ) ;
if ( V_8 ) {
F_10 ( & V_4 -> V_16 ) ;
return - V_44 ;
}
V_4 -> V_29 = 0 ;
V_41 -= V_39 ;
V_40 = V_39 ;
}
V_8 = F_17 ( ( void T_4 * ) V_7 + V_40 ,
V_4 -> V_17 + V_4 -> V_29 , V_41 ) ;
if ( V_8 ) {
F_10 ( & V_4 -> V_16 ) ;
return - V_44 ;
}
V_4 -> V_29 += V_41 ;
* V_38 += V_41 ;
F_10 ( & V_4 -> V_16 ) ;
if ( V_4 -> V_33 & V_34 ) {
V_4 -> V_33 &= ~ V_34 ;
F_14 ( & V_4 -> V_35 ) ;
}
return V_41 ;
}
static long F_18 ( struct V_2 * V_2 , unsigned int V_45 ,
unsigned long V_46 )
{
return - V_15 ;
}
