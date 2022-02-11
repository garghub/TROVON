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
static inline void F_11 ( struct V_12 * V_13 )
{
struct V_22 * V_23 = F_12 ( V_13 -> V_14 -> V_11 -> V_24 ) ;
struct V_25 * V_26 = V_23 -> V_27 + V_13 -> V_28 ;
T_1 V_29 , V_30 ;
V_30 = F_13 ( V_26 ) ;
V_29 = V_26 -> V_21 -> V_29 ;
F_10 ( & V_13 -> V_14 -> V_2 ,
F_14 ( V_31 ,
V_32 , 1 ) ,
F_15 ( V_29 ) |
F_16 ( V_30 ) ) ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_33 * V_34 = V_13 -> V_14 ;
struct V_25 * V_26 ;
T_1 V_35 = V_13 -> V_36 ;
T_1 V_37 = 0 ;
T_1 V_38 ;
int V_39 ;
struct V_40 * V_41 = NULL ;
struct V_22 * V_23 = F_12 ( V_34 -> V_11 -> V_24 ) ;
V_26 = V_23 -> V_27 + V_13 -> V_28 ;
F_18 ( F_4 ( V_34 -> V_11 ) ,
V_13 -> V_15 , V_13 -> V_42 ,
V_13 -> V_43 , V_13 -> V_28 ,
V_13 -> V_36 ) ;
V_37 = V_13 -> V_44 = F_13 ( V_26 ) ;
V_39 = F_19 ( & V_34 -> V_45 ) ;
if ( V_39 )
goto error;
V_41 = F_20 ( sizeof( * V_41 ) , V_46 ) ;
if ( ! V_41 ) {
F_21 ( & V_34 -> V_45 ) ;
V_39 = - V_47 ;
goto error;
}
V_39 = F_22 ( & V_34 -> V_2 , V_13 ) ;
if ( V_39 ) {
F_21 ( & V_34 -> V_45 ) ;
goto error;
}
if ( V_13 -> V_48 ) {
F_10 ( & V_34 -> V_2 ,
F_14 ( V_31 ,
F_23 () , 1 ) ,
F_24 ( V_13 -> V_28 ,
F_13 ( V_26 ) ) ) ;
}
if ( V_26 -> V_21 )
F_11 ( V_13 ) ;
V_38 = F_25 ( V_26 , V_35 ) ;
V_13 -> V_44 = V_38 ;
if ( V_13 -> V_49 )
F_10 ( & V_34 -> V_2 ,
F_14 ( V_13 -> V_49 , 0 , 0 ) ,
V_50 ) ;
F_8 ( V_13 ) ;
F_26 ( & V_34 -> V_2 , V_13 ) ;
F_27 ( F_4 ( V_34 -> V_11 ) , V_37 , V_38 ) ;
V_39 = F_28 ( V_23 , V_13 -> V_28 , V_38 ,
V_51 , V_34 ,
V_41 , NULL ) ;
V_41 = NULL ;
F_29 ( V_39 , L_1 ) ;
F_21 ( & V_34 -> V_45 ) ;
return 0 ;
error:
F_30 ( V_41 ) ;
return V_39 ;
}
static int F_31 ( struct V_33 * V_34 , struct V_22 * V_11 ,
unsigned int V_52 )
{
V_34 -> V_29 = V_52 ;
F_32 ( & V_34 -> V_53 ) ;
F_32 ( & V_34 -> V_45 ) ;
V_34 -> V_54 = V_11 -> V_54 + V_52 * V_55 ;
return 0 ;
}
