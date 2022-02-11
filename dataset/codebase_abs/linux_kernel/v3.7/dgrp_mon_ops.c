void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_2 -> V_6 = & V_7 ;
V_2 -> V_8 = & V_9 ;
V_4 -> V_10 = V_2 ;
F_2 ( & V_4 -> V_11 , 1 ) ;
}
static int F_3 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
struct V_3 * V_14 ;
struct V_1 * V_2 ;
struct V_15 V_16 ;
T_1 time ;
T_2 * V_17 ;
int V_18 ;
V_18 = F_4 ( V_19 ) ;
if ( ! V_18 )
return - V_20 ;
V_18 = 0 ;
if ( ! F_5 ( V_21 ) ) {
V_18 = - V_22 ;
goto V_23;
}
if ( V_13 -> V_24 ) {
V_18 = - V_25 ;
goto V_23;
}
V_2 = F_6 ( V_12 ) ;
if ( ! V_2 ) {
V_18 = - V_20 ;
goto V_23;
}
V_14 = (struct V_3 * ) V_2 -> V_5 ;
if ( ! V_14 ) {
V_18 = - V_20 ;
goto V_23;
}
V_13 -> V_24 = ( void * ) V_14 ;
F_7 ( & V_14 -> V_11 ) ;
if ( V_14 -> V_26 ) {
V_18 = - V_27 ;
goto V_28;
}
V_14 -> V_26 = F_8 ( V_29 , V_30 ) ;
if ( ! V_14 -> V_26 ) {
V_18 = - V_31 ;
goto V_28;
}
V_17 = V_14 -> V_26 ;
strcpy ( V_17 , V_32 ) ;
V_17 += strlen ( V_17 ) + 1 ;
F_9 ( & V_16 ) ;
time = ( T_1 ) ( V_16 . V_33 & 0xffffffff ) ;
F_10 ( time , V_17 ) ;
F_11 ( 0 , V_17 + 4 ) ;
V_17 += 6 ;
if ( V_14 -> V_34 ) {
V_17 [ 0 ] = V_35 ;
F_10 ( 0 , V_17 + 1 ) ;
F_11 ( 1 , V_17 + 5 ) ;
V_17 [ 7 ] = 0xf0 + V_14 -> V_34 ;
V_17 += 8 ;
}
if ( V_14 -> V_36 ) {
V_17 [ 0 ] = V_37 ;
F_10 ( 0 , V_17 + 1 ) ;
F_11 ( 1 , V_17 + 5 ) ;
V_17 [ 7 ] = 0xf0 + V_14 -> V_36 ;
V_17 += 8 ;
}
V_14 -> V_38 = 0 ;
V_14 -> V_39 = V_17 - V_14 -> V_26 ;
V_14 -> V_40 = V_41 ;
V_28:
F_12 ( & V_14 -> V_11 ) ;
V_23:
if ( V_18 )
F_13 ( V_19 ) ;
return V_18 ;
}
static int F_14 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
struct V_3 * V_14 ;
V_14 = (struct V_3 * ) ( V_13 -> V_24 ) ;
if ( ! V_14 )
goto V_23;
F_7 ( & V_14 -> V_11 ) ;
F_15 ( V_14 -> V_26 ) ;
V_14 -> V_26 = NULL ;
V_14 -> V_38 = V_14 -> V_39 ;
if ( V_14 -> V_42 & V_43 ) {
V_14 -> V_42 &= ~ V_43 ;
F_16 ( & V_14 -> V_44 ) ;
}
F_12 ( & V_14 -> V_11 ) ;
F_7 ( & V_14 -> V_45 ) ;
F_12 ( & V_14 -> V_45 ) ;
V_23:
F_13 ( V_19 ) ;
V_13 -> V_24 = NULL ;
return 0 ;
}
static T_3 F_17 ( struct V_13 * V_13 , char T_4 * V_17 , T_5 V_46 ,
T_6 * V_47 )
{
struct V_3 * V_14 ;
int V_48 ;
int V_49 = 0 ;
int V_50 = 0 ;
T_3 V_18 ;
V_14 = (struct V_3 * ) ( V_13 -> V_24 ) ;
if ( ! V_14 )
return - V_20 ;
F_7 ( & V_14 -> V_11 ) ;
for (; ; ) {
V_50 = ( V_14 -> V_39 - V_14 -> V_38 ) & V_51 ;
if ( V_50 )
break;
V_14 -> V_42 |= V_52 ;
F_12 ( & V_14 -> V_11 ) ;
V_18 = F_18 ( V_14 -> V_44 ,
( ( V_14 -> V_42 & V_52 ) == 0 ) ) ;
if ( V_18 )
return V_18 ;
F_7 ( & V_14 -> V_11 ) ;
}
if ( V_50 > V_46 )
V_50 = V_46 ;
V_48 = V_29 - V_14 -> V_38 ;
if ( V_48 <= V_50 ) {
V_18 = F_19 ( ( void T_4 * ) V_17 ,
V_14 -> V_26 + V_14 -> V_38 , V_48 ) ;
if ( V_18 ) {
F_12 ( & V_14 -> V_11 ) ;
return - V_53 ;
}
V_14 -> V_38 = 0 ;
V_50 -= V_48 ;
V_49 = V_48 ;
}
V_18 = F_19 ( ( void T_4 * ) V_17 + V_49 ,
V_14 -> V_26 + V_14 -> V_38 , V_50 ) ;
if ( V_18 ) {
F_12 ( & V_14 -> V_11 ) ;
return - V_53 ;
}
V_14 -> V_38 += V_50 ;
* V_47 += V_50 ;
F_12 ( & V_14 -> V_11 ) ;
if ( V_14 -> V_42 & V_43 ) {
V_14 -> V_42 &= ~ V_43 ;
F_16 ( & V_14 -> V_44 ) ;
}
return V_50 ;
}
static long F_20 ( struct V_13 * V_13 , unsigned int V_54 ,
unsigned long V_55 )
{
return - V_25 ;
}
