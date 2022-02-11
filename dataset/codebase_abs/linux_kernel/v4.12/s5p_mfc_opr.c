void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
V_3 = F_3 () ;
V_2 -> V_4 = V_5 ;
} else {
V_3 = F_4 () ;
V_2 -> V_4 = V_6 ;
}
V_2 -> V_7 = V_3 ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
V_2 -> V_8 = F_6 ( V_2 ) ;
}
int F_7 ( struct V_1 * V_2 , unsigned int V_9 ,
struct V_10 * V_11 )
{
unsigned int V_12 = V_2 -> V_13 >> V_14 ;
unsigned int V_15 = V_11 -> V_16 >> V_14 ;
unsigned int V_17 = ( V_18 >> V_14 ) - 1 ;
unsigned int V_19 , V_20 ;
F_8 ( 3 , L_1 , V_11 -> V_16 ) ;
if ( V_2 -> V_21 ) {
V_19 = F_9 ( V_2 -> V_22 , V_12 , 0 , V_15 , V_17 ) ;
if ( V_19 > V_12 )
goto V_23;
F_10 ( V_2 -> V_22 , V_19 , V_15 ) ;
V_20 = V_19 << V_14 ;
V_11 -> V_24 = V_2 -> V_21 + V_20 ;
V_11 -> V_25 = V_2 -> V_26 + V_20 ;
} else {
struct V_27 * V_28 = V_2 -> V_28 [ V_9 ] ;
T_1 V_29 = V_2 -> V_30 [ V_9 ] ;
V_11 -> V_31 = V_9 ;
V_11 -> V_24 = F_11 ( V_28 , V_11 -> V_16 , & V_11 -> V_25 , V_32 ) ;
if ( ! V_11 -> V_24 )
goto V_23;
if ( V_11 -> V_25 < V_29 ) {
F_12 ( L_2 ,
& V_11 -> V_25 , & V_29 ) ;
F_13 ( V_28 , V_11 -> V_16 , V_11 -> V_24 , V_11 -> V_25 ) ;
return - V_33 ;
}
}
F_8 ( 3 , L_3 , V_11 -> V_24 , & V_11 -> V_25 ) ;
return 0 ;
V_23:
F_12 ( L_4 , V_11 -> V_16 ) ;
return - V_33 ;
}
int F_14 ( struct V_1 * V_2 , unsigned int V_9 ,
struct V_10 * V_11 )
{
struct V_27 * V_28 = V_2 -> V_28 [ V_9 ] ;
F_8 ( 3 , L_5 , V_11 -> V_16 ) ;
V_11 -> V_31 = V_9 ;
V_11 -> V_24 = F_11 ( V_28 , V_11 -> V_16 , & V_11 -> V_25 , V_32 ) ;
if ( ! V_11 -> V_24 )
goto V_23;
F_8 ( 3 , L_3 , V_11 -> V_24 , & V_11 -> V_25 ) ;
return 0 ;
V_23:
F_12 ( L_6 , V_11 -> V_16 ) ;
return - V_33 ;
}
void F_15 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
if ( V_2 -> V_21 ) {
unsigned int V_19 = ( V_11 -> V_25 - V_2 -> V_26 ) >> V_14 ;
unsigned int V_15 = V_11 -> V_16 >> V_14 ;
F_16 ( V_2 -> V_22 , V_19 , V_15 ) ;
} else {
struct V_27 * V_28 = V_2 -> V_28 [ V_11 -> V_31 ] ;
F_13 ( V_28 , V_11 -> V_16 , V_11 -> V_24 , V_11 -> V_25 ) ;
}
V_11 -> V_24 = NULL ;
V_11 -> V_25 = 0 ;
V_11 -> V_16 = 0 ;
}
void F_17 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_27 * V_28 = V_2 -> V_28 [ V_11 -> V_31 ] ;
F_13 ( V_28 , V_11 -> V_16 , V_11 -> V_24 , V_11 -> V_25 ) ;
V_11 -> V_24 = NULL ;
V_11 -> V_25 = 0 ;
V_11 -> V_16 = 0 ;
}
