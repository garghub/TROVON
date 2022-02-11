static void F_1 ( struct V_1 * * V_2 , T_1 V_3 ,
int V_4 )
{
T_1 V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
F_2 ( V_6 , L_1 , ( unsigned long ) V_5 ,
( unsigned long ) V_3 , V_2 [ V_5 ] ) ;
if ( V_4 )
F_3 ( V_2 [ V_5 ] ) ;
F_4 ( V_2 [ V_5 ] ) ;
}
}
static int F_5 ( unsigned long V_7 , T_1 V_3 ,
struct V_1 * * V_2 )
{
unsigned long V_8 ;
T_1 V_9 ;
int V_10 ;
V_8 = F_6 ( V_11 ) >> V_12 ;
if ( V_3 > V_8 ) {
V_10 = - V_13 ;
goto V_14;
}
F_2 ( V_15 , L_2 ,
( unsigned long ) V_3 , V_7 ) ;
for ( V_9 = 0 ; V_9 < V_3 ; V_9 += V_10 ) {
V_10 = F_7 ( V_16 , V_16 -> V_17 ,
V_7 + V_9 * V_18 ,
V_3 - V_9 , 1 , 1 ,
V_2 + V_9 , NULL ) ;
if ( V_10 < 0 )
goto V_19;
}
V_16 -> V_17 -> V_20 += V_3 ;
V_10 = 0 ;
goto V_14;
V_19:
F_1 ( V_2 , V_9 , 0 ) ;
V_14:
return V_10 ;
}
T_2 F_8 ( struct V_21 * V_22 , struct V_1 * V_1 ,
unsigned long V_23 , T_1 V_24 , int V_25 )
{
T_2 V_26 ;
V_26 = F_9 ( V_22 , V_1 , V_23 , V_24 , V_25 ) ;
if ( V_26 == 0 ) {
F_10 ( V_22 , V_26 , V_24 , V_25 ) ;
V_26 = F_9 ( V_22 , V_1 , V_23 , V_24 , V_25 ) ;
}
return V_26 ;
}
T_2 F_11 ( struct V_21 * V_22 , void * V_27 , T_1 V_24 ,
int V_25 )
{
T_2 V_26 ;
V_26 = F_12 ( V_22 , V_27 , V_24 , V_25 ) ;
if ( V_26 == 0 ) {
F_13 ( V_22 , V_26 , V_24 , V_25 ) ;
V_26 = F_12 ( V_22 , V_27 , V_24 , V_25 ) ;
}
return V_26 ;
}
int F_14 ( unsigned long V_7 , T_1 V_3 ,
struct V_1 * * V_2 )
{
int V_10 ;
F_15 ( & V_16 -> V_17 -> V_28 ) ;
V_10 = F_5 ( V_7 , V_3 , V_2 ) ;
F_16 ( & V_16 -> V_17 -> V_28 ) ;
return V_10 ;
}
void F_17 ( struct V_1 * * V_2 , T_1 V_3 )
{
F_15 ( & V_16 -> V_17 -> V_28 ) ;
F_1 ( V_2 , V_3 , 1 ) ;
V_16 -> V_17 -> V_20 -= V_3 ;
F_16 ( & V_16 -> V_17 -> V_28 ) ;
}
static void F_18 ( struct V_29 * V_30 )
{
struct V_31 * V_32 =
F_19 ( V_30 , struct V_31 , V_32 ) ;
F_15 ( & V_32 -> V_17 -> V_28 ) ;
V_32 -> V_17 -> V_20 -= V_32 -> V_3 ;
F_16 ( & V_32 -> V_17 -> V_28 ) ;
F_20 ( V_32 -> V_17 ) ;
F_21 ( V_32 ) ;
}
void F_22 ( struct V_1 * * V_2 , T_1 V_3 )
{
struct V_31 * V_32 ;
struct V_33 * V_17 ;
F_1 ( V_2 , V_3 , 1 ) ;
V_17 = F_23 ( V_16 ) ;
if ( ! V_17 )
return;
V_32 = F_24 ( sizeof( * V_32 ) , V_34 ) ;
if ( ! V_32 )
goto V_35;
F_25 ( & V_32 -> V_32 , F_18 ) ;
V_32 -> V_17 = V_17 ;
V_32 -> V_3 = V_3 ;
F_26 ( V_36 , & V_32 -> V_32 ) ;
return;
V_35:
F_20 ( V_17 ) ;
return;
}
