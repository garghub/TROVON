static int F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
int V_3 ;
V_2 = V_4 / ( V_1 / 100 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ ) {
if ( V_5 [ V_3 ] == V_2 )
return V_3 ;
}
return - 1 ;
}
static int F_3 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
unsigned long V_1 ;
int V_10 ;
T_1 V_11 ;
if ( ! V_7 -> V_12 [ 1 ] ) {
F_4 ( V_9 , L_1 ) ;
return - V_13 ;
}
V_1 = F_5 ( V_7 -> V_12 [ 1 ] ) ;
if ( ( V_1 % 100 ) != 0 ) {
F_4 ( V_9 , L_2 ) ;
return - V_13 ;
}
V_10 = F_1 ( V_1 ) ;
if ( V_10 < 0 ) {
F_4 ( V_9 , L_3 ) ;
return - V_13 ;
}
V_11 = F_6 ( V_10 ) | F_7 ( 1 ) |
F_8 ( 4 ) | F_9 ( 1 ) |
F_10 ( 3 ) | F_11 ( 1 ) ;
F_12 ( V_11 , V_7 -> V_14 + V_15 ) ;
V_11 = F_7 ( 1 ) | F_8 ( 4 ) |
F_9 ( 1 ) | F_10 ( 3 ) ;
F_12 ( V_11 , V_7 -> V_14 + V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_17 * V_18 ,
unsigned int * V_19 , unsigned long V_20 )
{
int V_21 , V_22 ;
V_21 = F_14 ( V_18 ) ;
V_22 = F_15 ( V_18 , V_19 , V_21 , V_20 , V_23 ) ;
if ( V_21 && V_22 == - V_24 )
return F_15 ( V_18 , V_19 , 0 ,
V_20 , V_23 ) ;
return V_22 ;
}
static int F_16 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = & V_26 -> V_9 ;
struct V_6 * V_7 ;
int V_27 ;
V_7 = F_17 ( V_26 ) ;
if ( F_18 ( V_7 ) )
return F_19 ( V_7 ) ;
V_27 = F_20 ( V_7 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_3 ( V_7 , V_9 ) ;
if ( V_27 )
goto V_28;
V_27 = F_21 ( V_26 , V_7 ,
& V_29 ,
& V_30 ) ;
if ( V_27 )
goto V_28;
return 0 ;
V_28:
F_22 ( V_7 ) ;
return V_27 ;
}
