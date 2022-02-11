void F_1 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_4 , unsigned V_5 )
{
struct V_6 * V_7 = NULL ;
struct V_6 * V_8 = NULL ;
struct V_9 * V_10 = NULL ;
T_1 V_11 , V_12 ;
unsigned long V_13 ;
unsigned long V_14 ;
unsigned long time ;
unsigned V_15 , V_16 , V_17 ;
int V_18 ;
V_17 = V_3 ;
V_16 = 1024 ;
V_18 = F_2 ( V_2 , V_17 , V_19 , true , V_4 , & V_8 ) ;
if ( V_18 ) {
goto V_20;
}
V_18 = F_3 ( V_8 , false ) ;
if ( F_4 ( V_18 != 0 ) )
goto V_20;
V_18 = F_5 ( V_8 , V_4 , & V_11 ) ;
F_6 ( V_8 ) ;
if ( V_18 ) {
goto V_20;
}
V_18 = F_2 ( V_2 , V_17 , V_19 , true , V_5 , & V_7 ) ;
if ( V_18 ) {
goto V_20;
}
V_18 = F_3 ( V_7 , false ) ;
if ( F_4 ( V_18 != 0 ) )
goto V_20;
V_18 = F_5 ( V_7 , V_5 , & V_12 ) ;
F_6 ( V_7 ) ;
if ( V_18 ) {
goto V_20;
}
if ( V_2 -> V_21 -> V_22 ) {
V_13 = V_23 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_18 = F_7 ( V_2 , & V_10 ) ;
if ( V_18 ) {
goto V_20;
}
V_18 = F_8 ( V_2 , V_11 , V_12 ,
V_17 / V_24 , V_10 ) ;
if ( V_18 ) {
goto V_20;
}
V_18 = F_9 ( V_10 , false ) ;
if ( V_18 ) {
goto V_20;
}
F_10 ( & V_10 ) ;
}
V_14 = V_23 ;
time = V_14 - V_13 ;
time = F_11 ( time ) ;
if ( time > 0 ) {
V_15 = ( ( V_16 * V_17 ) >> 10 ) / time ;
F_12 ( V_25 L_1
L_2 ,
V_16 , V_17 >> 10 ,
V_4 , V_5 , time ,
V_15 , V_15 * 1000 , ( V_15 * 1000 ) / 1024 ) ;
}
}
V_13 = V_23 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_18 = F_7 ( V_2 , & V_10 ) ;
if ( V_18 ) {
goto V_20;
}
V_18 = F_13 ( V_2 , V_11 , V_12 , V_17 / V_24 , V_10 ) ;
if ( V_18 ) {
goto V_20;
}
V_18 = F_9 ( V_10 , false ) ;
if ( V_18 ) {
goto V_20;
}
F_10 ( & V_10 ) ;
}
V_14 = V_23 ;
time = V_14 - V_13 ;
time = F_11 ( time ) ;
if ( time > 0 ) {
V_15 = ( ( V_16 * V_17 ) >> 10 ) / time ;
F_12 ( V_25 L_3
L_4 , V_16 , V_17 >> 10 ,
V_4 , V_5 , time , V_15 , V_15 * 1000 , ( V_15 * 1000 ) / 1024 ) ;
}
V_20:
if ( V_8 ) {
V_18 = F_3 ( V_8 , false ) ;
if ( F_14 ( V_18 == 0 ) ) {
F_15 ( V_8 ) ;
F_6 ( V_8 ) ;
}
F_16 ( & V_8 ) ;
}
if ( V_7 ) {
V_18 = F_3 ( V_7 , false ) ;
if ( F_14 ( V_18 == 0 ) ) {
F_15 ( V_7 ) ;
F_6 ( V_7 ) ;
}
F_16 ( & V_7 ) ;
}
if ( V_10 ) {
F_10 ( & V_10 ) ;
}
if ( V_18 ) {
F_12 ( V_26 L_5 ) ;
}
}
void F_17 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 1024 * 1024 , V_27 ,
V_28 ) ;
F_1 ( V_2 , 1024 * 1024 , V_28 ,
V_27 ) ;
}
