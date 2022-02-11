static void F_1 ( struct V_1 * * V_2 , T_1 V_3 ,
int V_4 )
{
T_1 V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
if ( V_4 )
F_2 ( V_2 [ V_5 ] ) ;
F_3 ( V_2 [ V_5 ] ) ;
}
}
static int F_4 ( unsigned long V_6 , T_1 V_3 ,
struct V_1 * * V_2 , struct V_7 * * V_8 )
{
unsigned long V_9 ;
T_1 V_10 ;
int V_11 ;
V_9 = F_5 ( V_12 ) >> V_13 ;
if ( V_3 > V_9 && ! F_6 ( V_14 ) ) {
V_11 = - V_15 ;
goto V_16;
}
for ( V_10 = 0 ; V_10 < V_3 ; V_10 += V_11 ) {
V_11 = F_7 ( V_17 , V_17 -> V_18 ,
V_6 + V_10 * V_19 ,
V_3 - V_10 , 1 , 1 ,
V_2 + V_10 , V_8 ) ;
if ( V_11 < 0 )
goto V_20;
}
V_17 -> V_18 -> V_21 += V_3 ;
V_11 = 0 ;
goto V_16;
V_20:
F_1 ( V_2 , V_10 , 0 ) ;
V_16:
return V_11 ;
}
T_2 F_8 ( struct V_22 * V_23 , struct V_1 * V_1 ,
unsigned long V_24 , T_1 V_25 , int V_26 )
{
T_2 V_27 ;
V_27 = F_9 ( V_23 , V_1 , V_24 , V_25 , V_26 ) ;
if ( V_27 == 0 ) {
F_10 ( V_23 , V_27 , V_25 , V_26 ) ;
V_27 = F_9 ( V_23 , V_1 , V_24 , V_25 , V_26 ) ;
}
return V_27 ;
}
int F_11 ( unsigned long V_6 , T_1 V_3 ,
struct V_1 * * V_2 )
{
int V_11 ;
F_12 ( & V_17 -> V_18 -> V_28 ) ;
V_11 = F_4 ( V_6 , V_3 , V_2 , NULL ) ;
F_13 ( & V_17 -> V_18 -> V_28 ) ;
return V_11 ;
}
void F_14 ( struct V_1 * * V_2 , T_1 V_3 )
{
if ( V_17 -> V_18 )
F_12 ( & V_17 -> V_18 -> V_28 ) ;
F_1 ( V_2 , V_3 , 1 ) ;
if ( V_17 -> V_18 ) {
V_17 -> V_18 -> V_21 -= V_3 ;
F_13 ( & V_17 -> V_18 -> V_28 ) ;
}
}
