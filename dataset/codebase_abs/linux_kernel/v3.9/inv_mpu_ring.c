int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_6 , V_6 -> V_7 -> V_8 , 0 ) ;
if ( V_3 ) {
F_4 ( & V_6 -> V_9 -> V_10 , L_1 , V_3 ) ;
return V_3 ;
}
V_3 = F_3 ( V_6 , V_6 -> V_7 -> V_11 , 0 ) ;
if ( V_3 )
goto V_12;
V_3 = F_3 ( V_6 , V_6 -> V_7 -> V_13 , 0 ) ;
if ( V_3 )
goto V_12;
V_3 = F_3 ( V_6 , V_6 -> V_7 -> V_13 ,
V_14 ) ;
if ( V_3 )
goto V_12;
if ( V_6 -> V_15 . V_16 ||
V_6 -> V_15 . V_17 ) {
V_3 = F_3 ( V_6 , V_6 -> V_7 -> V_8 ,
V_18 ) ;
if ( V_3 )
return V_3 ;
}
V_3 = F_3 ( V_6 , V_6 -> V_7 -> V_13 ,
V_19 ) ;
if ( V_3 )
goto V_12;
V_4 = 0 ;
if ( V_6 -> V_15 . V_17 )
V_4 |= V_20 ;
if ( V_6 -> V_15 . V_16 )
V_4 |= V_21 ;
V_3 = F_3 ( V_6 , V_6 -> V_7 -> V_11 , V_4 ) ;
if ( V_3 )
goto V_12;
return 0 ;
V_12:
F_4 ( & V_6 -> V_9 -> V_10 , L_2 , V_3 ) ;
V_3 = F_3 ( V_6 , V_6 -> V_7 -> V_8 ,
V_18 ) ;
return V_3 ;
}
static void F_5 ( struct V_5 * V_6 )
{
unsigned long V_22 ;
F_6 ( & V_6 -> V_23 , V_22 ) ;
F_7 ( & V_6 -> V_24 ) ;
F_8 ( & V_6 -> V_23 , V_22 ) ;
}
T_2 F_9 ( int V_25 , void * V_26 )
{
struct V_27 * V_28 = V_26 ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_3 V_29 ;
V_29 = F_10 () ;
F_11 ( & V_6 -> V_23 ) ;
F_12 ( & V_6 -> V_24 , & V_29 , 1 ) ;
F_13 ( & V_6 -> V_23 ) ;
return V_30 ;
}
T_2 F_14 ( int V_25 , void * V_26 )
{
struct V_27 * V_28 = V_26 ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_31 ;
int V_3 ;
T_1 V_32 [ V_33 ] ;
T_5 V_34 ;
T_3 V_29 ;
T_6 * V_35 ;
F_15 ( & V_2 -> V_36 ) ;
if ( ! ( V_6 -> V_15 . V_16 |
V_6 -> V_15 . V_17 ) )
goto V_37;
V_31 = 0 ;
if ( V_6 -> V_15 . V_16 )
V_31 += V_38 ;
if ( V_6 -> V_15 . V_17 )
V_31 += V_38 ;
V_3 = F_16 ( V_6 -> V_9 ,
V_6 -> V_7 -> V_39 ,
V_40 , V_32 ) ;
if ( V_3 != V_40 )
goto V_37;
V_34 = F_17 ( ( V_41 * ) ( & V_32 [ 0 ] ) ) ;
if ( V_34 < V_31 )
goto V_37;
if ( V_34 & 1 )
goto V_42;
if ( V_34 > V_43 )
goto V_42;
if ( F_18 ( & V_6 -> V_24 ) >
V_34 / V_31 + V_44 )
goto V_42;
while ( V_34 >= V_31 ) {
V_3 = F_16 ( V_6 -> V_9 ,
V_6 -> V_7 -> V_45 ,
V_31 , V_32 ) ;
if ( V_3 != V_31 )
goto V_42;
V_3 = F_19 ( & V_6 -> V_24 , & V_29 , 1 ) ;
if ( 0 == V_3 )
V_29 = 0 ;
V_35 = ( T_6 * ) V_32 ;
V_35 [ F_20 ( V_31 , 8 ) ] = V_29 ;
V_3 = F_21 ( V_2 , V_32 ) ;
if ( V_3 )
goto V_42;
V_34 -= V_31 ;
}
V_37:
F_22 ( & V_2 -> V_36 ) ;
F_23 ( V_2 -> V_46 ) ;
return V_47 ;
V_42:
F_1 ( V_2 ) ;
F_5 ( V_6 ) ;
F_22 ( & V_2 -> V_36 ) ;
F_23 ( V_2 -> V_46 ) ;
return V_47 ;
}
