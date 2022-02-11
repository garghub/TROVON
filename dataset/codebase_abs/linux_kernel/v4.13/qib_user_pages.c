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
struct V_1 * * V_2 )
{
unsigned long V_7 ;
T_1 V_8 ;
int V_9 ;
V_7 = F_5 ( V_10 ) >> V_11 ;
if ( V_3 > V_7 && ! F_6 ( V_12 ) ) {
V_9 = - V_13 ;
goto V_14;
}
for ( V_8 = 0 ; V_8 < V_3 ; V_8 += V_9 ) {
V_9 = F_7 ( V_6 + V_8 * V_15 ,
V_3 - V_8 ,
V_16 | V_17 ,
V_2 + V_8 , NULL ) ;
if ( V_9 < 0 )
goto V_18;
}
V_19 -> V_20 -> V_21 += V_3 ;
V_9 = 0 ;
goto V_14;
V_18:
F_1 ( V_2 , V_8 , 0 ) ;
V_14:
return V_9 ;
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
int V_9 ;
F_12 ( & V_19 -> V_20 -> V_28 ) ;
V_9 = F_4 ( V_6 , V_3 , V_2 ) ;
F_13 ( & V_19 -> V_20 -> V_28 ) ;
return V_9 ;
}
void F_14 ( struct V_1 * * V_2 , T_1 V_3 )
{
if ( V_19 -> V_20 )
F_12 ( & V_19 -> V_20 -> V_28 ) ;
F_1 ( V_2 , V_3 , 1 ) ;
if ( V_19 -> V_20 ) {
V_19 -> V_20 -> V_21 -= V_3 ;
F_13 ( & V_19 -> V_20 -> V_28 ) ;
}
}
