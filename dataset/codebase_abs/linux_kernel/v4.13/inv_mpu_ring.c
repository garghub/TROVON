static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_4 , V_3 ) ;
}
int F_5 ( struct V_6 * V_7 )
{
int V_8 ;
T_1 V_9 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
V_8 = F_7 ( V_2 -> V_10 , V_2 -> V_11 -> V_12 , 0 ) ;
if ( V_8 ) {
F_8 ( F_9 ( V_2 -> V_10 ) , L_1 ,
V_8 ) ;
return V_8 ;
}
V_8 = F_7 ( V_2 -> V_10 , V_2 -> V_11 -> V_13 , 0 ) ;
if ( V_8 )
goto V_14;
V_8 = F_7 ( V_2 -> V_10 , V_2 -> V_11 -> V_15 , 0 ) ;
if ( V_8 )
goto V_14;
V_8 = F_7 ( V_2 -> V_10 , V_2 -> V_11 -> V_15 ,
V_16 ) ;
if ( V_8 )
goto V_14;
F_1 ( V_2 ) ;
if ( V_2 -> V_17 . V_18 ||
V_2 -> V_17 . V_19 ) {
V_8 = F_7 ( V_2 -> V_10 , V_2 -> V_11 -> V_12 ,
V_20 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_7 ( V_2 -> V_10 , V_2 -> V_11 -> V_15 ,
V_21 ) ;
if ( V_8 )
goto V_14;
V_9 = 0 ;
if ( V_2 -> V_17 . V_19 )
V_9 |= V_22 ;
if ( V_2 -> V_17 . V_18 )
V_9 |= V_23 ;
V_8 = F_7 ( V_2 -> V_10 , V_2 -> V_11 -> V_13 , V_9 ) ;
if ( V_8 )
goto V_14;
return 0 ;
V_14:
F_8 ( F_9 ( V_2 -> V_10 ) , L_2 , V_8 ) ;
V_8 = F_7 ( V_2 -> V_10 , V_2 -> V_11 -> V_12 ,
V_20 ) ;
return V_8 ;
}
T_2 F_10 ( int V_24 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_6 * V_7 = V_27 -> V_7 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_3 V_28 ;
V_28 = F_11 ( V_7 ) ;
F_12 ( & V_2 -> V_5 , & V_28 , 1 ,
& V_2 -> V_4 ) ;
return V_29 ;
}
T_2 F_13 ( int V_24 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_6 * V_7 = V_27 -> V_7 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_4 V_30 ;
int V_8 ;
T_1 V_31 [ V_32 ] ;
T_5 V_33 ;
T_3 V_28 ;
F_14 ( & V_2 -> V_34 ) ;
if ( ! ( V_2 -> V_17 . V_18 |
V_2 -> V_17 . V_19 ) )
goto V_35;
V_30 = 0 ;
if ( V_2 -> V_17 . V_18 )
V_30 += V_36 ;
if ( V_2 -> V_17 . V_19 )
V_30 += V_36 ;
V_8 = F_15 ( V_2 -> V_10 , V_2 -> V_11 -> V_37 , V_31 ,
V_38 ) ;
if ( V_8 )
goto V_35;
V_33 = F_16 ( ( V_39 * ) ( & V_31 [ 0 ] ) ) ;
if ( V_33 < V_30 )
goto V_35;
if ( V_33 & 1 )
goto V_40;
if ( V_33 > V_41 )
goto V_40;
if ( F_17 ( & V_2 -> V_5 ) >
V_33 / V_30 + V_42 )
goto V_40;
while ( V_33 >= V_30 ) {
V_8 = F_15 ( V_2 -> V_10 , V_2 -> V_11 -> V_43 ,
V_31 , V_30 ) ;
if ( V_8 )
goto V_40;
V_8 = F_18 ( & V_2 -> V_5 , & V_28 , 1 ) ;
if ( V_8 == 0 )
V_28 = 0 ;
V_8 = F_19 ( V_7 , V_31 ,
V_28 ) ;
if ( V_8 )
goto V_40;
V_33 -= V_30 ;
}
V_35:
F_20 ( & V_2 -> V_34 ) ;
F_21 ( V_7 -> V_44 ) ;
return V_45 ;
V_40:
F_5 ( V_7 ) ;
F_20 ( & V_2 -> V_34 ) ;
F_21 ( V_7 -> V_44 ) ;
return V_45 ;
}
