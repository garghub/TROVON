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
struct V_1 * * V_2 , struct V_8 * * V_9 )
{
unsigned long V_10 ;
T_1 V_11 ;
int V_12 ;
V_10 = F_6 ( V_13 ) >> V_14 ;
if ( V_3 > V_10 ) {
V_12 = - V_15 ;
goto V_16;
}
F_2 ( V_17 , L_2 ,
( unsigned long ) V_3 , V_7 ) ;
for ( V_11 = 0 ; V_11 < V_3 ; V_11 += V_12 ) {
V_12 = F_7 ( V_18 , V_18 -> V_19 ,
V_7 + V_11 * V_20 ,
V_3 - V_11 , 1 , 1 ,
V_2 + V_11 , V_9 ) ;
if ( V_12 < 0 )
goto V_21;
}
V_18 -> V_19 -> V_22 += V_3 ;
V_12 = 0 ;
goto V_16;
V_21:
F_1 ( V_2 , V_11 , 0 ) ;
V_16:
return V_12 ;
}
T_2 F_8 ( struct V_23 * V_24 , struct V_1 * V_1 ,
unsigned long V_25 , T_1 V_26 , int V_27 )
{
T_2 V_28 ;
V_28 = F_9 ( V_24 , V_1 , V_25 , V_26 , V_27 ) ;
if ( V_28 == 0 ) {
F_10 ( V_24 , V_28 , V_26 , V_27 ) ;
V_28 = F_9 ( V_24 , V_1 , V_25 , V_26 , V_27 ) ;
}
return V_28 ;
}
T_2 F_11 ( struct V_23 * V_24 , void * V_29 , T_1 V_26 ,
int V_27 )
{
T_2 V_28 ;
V_28 = F_12 ( V_24 , V_29 , V_26 , V_27 ) ;
if ( V_28 == 0 ) {
F_13 ( V_24 , V_28 , V_26 , V_27 ) ;
V_28 = F_12 ( V_24 , V_29 , V_26 , V_27 ) ;
}
return V_28 ;
}
int F_14 ( unsigned long V_7 , T_1 V_3 ,
struct V_1 * * V_2 )
{
int V_12 ;
F_15 ( & V_18 -> V_19 -> V_30 ) ;
V_12 = F_5 ( V_7 , V_3 , V_2 , NULL ) ;
F_16 ( & V_18 -> V_19 -> V_30 ) ;
return V_12 ;
}
void F_17 ( struct V_1 * * V_2 , T_1 V_3 )
{
F_15 ( & V_18 -> V_19 -> V_30 ) ;
F_1 ( V_2 , V_3 , 1 ) ;
V_18 -> V_19 -> V_22 -= V_3 ;
F_16 ( & V_18 -> V_19 -> V_30 ) ;
}
static void F_18 ( struct V_31 * V_32 )
{
struct V_33 * V_34 =
F_19 ( V_32 , struct V_33 , V_34 ) ;
F_15 ( & V_34 -> V_19 -> V_30 ) ;
V_34 -> V_19 -> V_22 -= V_34 -> V_3 ;
F_16 ( & V_34 -> V_19 -> V_30 ) ;
F_20 ( V_34 -> V_19 ) ;
F_21 ( V_34 ) ;
}
void F_22 ( struct V_1 * * V_2 , T_1 V_3 )
{
struct V_33 * V_34 ;
struct V_35 * V_19 ;
F_1 ( V_2 , V_3 , 1 ) ;
V_19 = F_23 ( V_18 ) ;
if ( ! V_19 )
return;
V_34 = F_24 ( sizeof( * V_34 ) , V_36 ) ;
if ( ! V_34 )
goto V_37;
F_25 ( & V_34 -> V_34 , F_18 ) ;
V_34 -> V_19 = V_19 ;
V_34 -> V_3 = V_3 ;
F_26 ( V_38 , & V_34 -> V_34 ) ;
return;
V_37:
F_20 ( V_19 ) ;
return;
}
