static int T_1 F_1 ( char * V_1 )
{
V_2 = 0 ;
return 1 ;
}
void F_2 ( void )
{
V_3 = F_3 ( V_4 , V_5 ) ;
F_4 ( & V_6 ) ;
}
void F_5 ( struct V_7 * V_8 )
{
V_8 -> V_9 = F_6 ( V_3 , V_10 ) ;
if ( V_8 -> V_9 )
F_7 ( & V_8 -> V_9 -> V_11 ) ;
}
static void F_8 ( T_2 * V_12 , T_2 * V_13 , T_3 * V_14 )
{
T_4 V_15 = F_9 () - * V_12 ;
unsigned long V_16 ;
if ( V_15 > 0 ) {
F_10 ( & V_17 -> V_9 -> V_11 , V_16 ) ;
* V_13 += V_15 ;
( * V_14 ) ++ ;
F_11 ( & V_17 -> V_9 -> V_11 , V_16 ) ;
}
}
void F_12 ( void )
{
V_17 -> V_9 -> V_18 = F_9 () ;
}
void F_13 ( void )
{
if ( V_17 -> V_9 -> V_16 & V_19 )
F_8 ( & V_17 -> V_9 -> V_18 ,
& V_17 -> V_9 -> V_20 ,
& V_17 -> V_9 -> V_21 ) ;
else
F_8 ( & V_17 -> V_9 -> V_18 ,
& V_17 -> V_9 -> V_22 ,
& V_17 -> V_9 -> V_23 ) ;
}
int F_14 ( struct V_24 * V_25 , struct V_7 * V_8 )
{
T_5 V_26 , V_27 , V_28 , V_29 ;
unsigned long long V_30 , V_31 ;
unsigned long V_16 , V_32 ;
T_4 V_33 ;
F_15 ( V_8 , & V_26 , & V_27 ) ;
V_33 = ( T_4 ) V_25 -> V_34 ;
V_33 += F_16 ( V_26 + V_27 ) ;
V_25 -> V_34 = ( V_33 < ( T_4 ) V_25 -> V_34 ) ? 0 : V_33 ;
F_17 ( V_8 , & V_29 , & V_28 ) ;
V_33 = ( T_4 ) V_25 -> V_35 ;
V_33 += F_16 ( V_29 + V_28 ) ;
V_25 -> V_35 =
( V_33 < ( T_4 ) V_25 -> V_35 ) ? 0 : V_33 ;
V_32 = V_8 -> V_36 . V_37 ;
V_30 = V_8 -> V_36 . V_38 ;
V_31 = V_8 -> V_39 . V_40 ;
V_25 -> V_41 += V_32 ;
V_33 = ( T_4 ) V_25 -> V_42 + V_30 ;
V_25 -> V_42 = ( V_33 < ( T_4 ) V_25 -> V_42 ) ? 0 : V_33 ;
V_33 = ( T_4 ) V_25 -> V_43 + V_31 ;
V_25 -> V_43 =
( V_33 < ( T_4 ) V_25 -> V_43 ) ? 0 : V_33 ;
F_10 ( & V_8 -> V_9 -> V_11 , V_16 ) ;
V_33 = V_25 -> V_44 + V_8 -> V_9 -> V_22 ;
V_25 -> V_44 = ( V_33 < V_25 -> V_44 ) ? 0 : V_33 ;
V_33 = V_25 -> V_45 + V_8 -> V_9 -> V_20 ;
V_25 -> V_45 = ( V_33 < V_25 -> V_45 ) ? 0 : V_33 ;
V_33 = V_25 -> V_46 + V_8 -> V_9 -> V_47 ;
V_25 -> V_46 = ( V_33 < V_25 -> V_46 ) ? 0 : V_33 ;
V_25 -> V_23 += V_8 -> V_9 -> V_23 ;
V_25 -> V_21 += V_8 -> V_9 -> V_21 ;
V_25 -> V_48 += V_8 -> V_9 -> V_48 ;
F_11 ( & V_8 -> V_9 -> V_11 , V_16 ) ;
return 0 ;
}
T_6 F_18 ( struct V_7 * V_8 )
{
T_6 V_49 ;
unsigned long V_16 ;
F_10 ( & V_8 -> V_9 -> V_11 , V_16 ) ;
V_49 = F_19 ( V_8 -> V_9 -> V_22 +
V_8 -> V_9 -> V_20 ) ;
F_11 ( & V_8 -> V_9 -> V_11 , V_16 ) ;
return V_49 ;
}
void F_20 ( void )
{
V_17 -> V_9 -> V_50 = F_9 () ;
}
void F_21 ( void )
{
F_8 ( & V_17 -> V_9 -> V_50 ,
& V_17 -> V_9 -> V_47 ,
& V_17 -> V_9 -> V_48 ) ;
}
