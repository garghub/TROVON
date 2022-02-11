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
V_8 = F_7 ( V_2 , V_2 -> V_10 -> V_11 , 0 ) ;
if ( V_8 ) {
F_8 ( & V_2 -> V_12 -> V_13 , L_1 , V_8 ) ;
return V_8 ;
}
V_8 = F_7 ( V_2 , V_2 -> V_10 -> V_14 , 0 ) ;
if ( V_8 )
goto V_15;
V_8 = F_7 ( V_2 , V_2 -> V_10 -> V_16 , 0 ) ;
if ( V_8 )
goto V_15;
V_8 = F_7 ( V_2 , V_2 -> V_10 -> V_16 ,
V_17 ) ;
if ( V_8 )
goto V_15;
F_1 ( V_2 ) ;
if ( V_2 -> V_18 . V_19 ||
V_2 -> V_18 . V_20 ) {
V_8 = F_7 ( V_2 , V_2 -> V_10 -> V_11 ,
V_21 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_7 ( V_2 , V_2 -> V_10 -> V_16 ,
V_22 ) ;
if ( V_8 )
goto V_15;
V_9 = 0 ;
if ( V_2 -> V_18 . V_20 )
V_9 |= V_23 ;
if ( V_2 -> V_18 . V_19 )
V_9 |= V_24 ;
V_8 = F_7 ( V_2 , V_2 -> V_10 -> V_14 , V_9 ) ;
if ( V_8 )
goto V_15;
return 0 ;
V_15:
F_8 ( & V_2 -> V_12 -> V_13 , L_2 , V_8 ) ;
V_8 = F_7 ( V_2 , V_2 -> V_10 -> V_11 ,
V_21 ) ;
return V_8 ;
}
T_2 F_9 ( int V_25 , void * V_26 )
{
struct V_27 * V_28 = V_26 ;
struct V_6 * V_7 = V_28 -> V_7 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_3 V_29 ;
V_29 = F_10 () ;
F_11 ( & V_2 -> V_5 , & V_29 , 1 ,
& V_2 -> V_4 ) ;
return V_30 ;
}
T_2 F_12 ( int V_25 , void * V_26 )
{
struct V_27 * V_28 = V_26 ;
struct V_6 * V_7 = V_28 -> V_7 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_4 V_31 ;
int V_8 ;
T_1 V_32 [ V_33 ] ;
T_5 V_34 ;
T_3 V_29 ;
F_13 ( & V_7 -> V_35 ) ;
if ( ! ( V_2 -> V_18 . V_19 |
V_2 -> V_18 . V_20 ) )
goto V_36;
V_31 = 0 ;
if ( V_2 -> V_18 . V_19 )
V_31 += V_37 ;
if ( V_2 -> V_18 . V_20 )
V_31 += V_37 ;
V_8 = F_14 ( V_2 -> V_12 ,
V_2 -> V_10 -> V_38 ,
V_39 , V_32 ) ;
if ( V_8 != V_39 )
goto V_36;
V_34 = F_15 ( ( V_40 * ) ( & V_32 [ 0 ] ) ) ;
if ( V_34 < V_31 )
goto V_36;
if ( V_34 & 1 )
goto V_41;
if ( V_34 > V_42 )
goto V_41;
if ( F_16 ( & V_2 -> V_5 ) >
V_34 / V_31 + V_43 )
goto V_41;
while ( V_34 >= V_31 ) {
V_8 = F_14 ( V_2 -> V_12 ,
V_2 -> V_10 -> V_44 ,
V_31 , V_32 ) ;
if ( V_8 != V_31 )
goto V_41;
V_8 = F_17 ( & V_2 -> V_5 , & V_29 , 1 ) ;
if ( 0 == V_8 )
V_29 = 0 ;
V_8 = F_18 ( V_7 , V_32 ,
V_29 ) ;
if ( V_8 )
goto V_41;
V_34 -= V_31 ;
}
V_36:
F_19 ( & V_7 -> V_35 ) ;
F_20 ( V_7 -> V_45 ) ;
return V_46 ;
V_41:
F_5 ( V_7 ) ;
F_19 ( & V_7 -> V_35 ) ;
F_20 ( V_7 -> V_45 ) ;
return V_46 ;
}
