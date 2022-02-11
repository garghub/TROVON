static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
void * V_7 = NULL ;
if ( V_8 )
V_7 = F_2 ( V_4 ) ;
if ( V_7 ) {
T_1 V_9 ;
for ( V_9 = 0 ; V_9 < V_6 ; V_9 += V_10 ) {
F_3 (
F_4 ( F_5 ( V_2 ) -> V_11 ) ,
( T_1 ) V_4 , F_6 ( V_6 - V_9 , V_10 ) ,
V_5 + V_9 * sizeof( T_1 ) , V_7 ) ;
}
F_7 ( V_4 , V_7 ) ;
}
}
static void F_8 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_14 -> V_2 ;
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_13 -> V_15 ; V_9 ++ ) {
struct V_16 * V_17 = & V_13 -> V_18 [ V_9 ] ;
T_1 V_19 = F_9 ( V_17 -> V_6 ) ;
T_1 V_20 = V_17 -> V_21 + V_17 -> V_5 ;
F_1 ( V_2 , V_17 -> V_4 , V_17 -> V_5 , V_19 & 0xffff ) ;
F_10 ( V_2 , V_19 , V_20 ) ;
}
}
static int F_11 ( struct V_12 * V_13 )
{
struct V_22 * V_23 = V_13 -> V_14 ;
struct V_24 * V_25 ;
T_1 V_26 = V_13 -> V_27 ;
T_1 V_28 = 0 ;
T_1 V_29 ;
int V_30 ;
struct V_31 * V_32 = NULL ;
struct V_33 * V_34 = F_12 ( V_23 -> V_11 -> V_35 ) ;
V_25 = V_34 -> V_36 + V_13 -> V_37 ;
F_13 ( F_4 ( V_23 -> V_11 ) ,
V_13 -> V_15 , V_13 -> V_38 ,
V_13 -> V_39 , V_13 -> V_37 ,
V_13 -> V_27 ) ;
V_28 = V_13 -> V_40 = F_14 ( V_25 ) ;
V_30 = F_15 ( & V_23 -> V_41 ) ;
if ( V_30 )
goto error;
V_32 = F_16 ( sizeof( * V_32 ) , V_42 ) ;
if ( ! V_32 ) {
F_17 ( & V_23 -> V_41 ) ;
V_30 = - V_43 ;
goto error;
}
V_30 = F_18 ( & V_23 -> V_2 , V_13 ) ;
if ( V_30 ) {
F_17 ( & V_23 -> V_41 ) ;
goto error;
}
if ( V_13 -> V_44 ) {
F_10 ( & V_23 -> V_2 ,
F_19 ( V_45 ,
F_20 () , 1 ) ,
F_21 ( V_13 -> V_37 ,
F_14 ( V_25 ) ) ) ;
}
V_29 = F_22 ( V_25 , V_26 ) ;
V_13 -> V_40 = V_29 ;
if ( V_13 -> V_46 )
F_10 ( & V_23 -> V_2 ,
F_19 ( V_13 -> V_46 , 0 , 0 ) ,
V_47 ) ;
F_8 ( V_13 ) ;
F_23 ( & V_23 -> V_2 , V_13 ) ;
F_24 ( F_4 ( V_23 -> V_11 ) , V_28 , V_29 ) ;
V_30 = F_25 ( V_34 , V_13 -> V_37 , V_29 ,
V_48 , V_23 ,
V_32 , NULL ) ;
V_32 = NULL ;
F_26 ( V_30 , L_1 ) ;
F_17 ( & V_23 -> V_41 ) ;
return 0 ;
error:
F_27 ( V_32 ) ;
return V_30 ;
}
static int F_28 ( struct V_22 * V_23 , struct V_33 * V_11 ,
unsigned int V_49 )
{
V_23 -> V_50 = V_49 ;
F_29 ( & V_23 -> V_51 ) ;
F_29 ( & V_23 -> V_41 ) ;
V_23 -> V_52 = V_11 -> V_52 + V_49 * V_53 ;
return 0 ;
}
