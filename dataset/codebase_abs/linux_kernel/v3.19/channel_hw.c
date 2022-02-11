static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) -> V_8 ;
void * V_9 = NULL ;
if ( V_10 )
V_9 = F_3 ( V_4 ) ;
if ( V_9 ) {
T_1 V_11 ;
for ( V_11 = 0 ; V_11 < V_6 ; V_11 += V_12 ) {
T_1 V_13 = F_4 ( V_6 - V_11 , V_12 ) ;
V_5 += V_11 * sizeof( T_1 ) ;
F_5 ( F_6 ( V_8 ) , V_4 ,
V_13 , V_5 ,
V_9 ) ;
}
F_7 ( V_4 , V_9 ) ;
}
}
static void F_8 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = & V_15 -> V_16 -> V_2 ;
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_15 -> V_17 ; V_11 ++ ) {
struct V_18 * V_19 = & V_15 -> V_20 [ V_11 ] ;
T_1 V_21 = F_9 ( V_19 -> V_6 ) ;
T_1 V_22 = V_19 -> V_23 + V_19 -> V_5 ;
F_1 ( V_2 , V_19 -> V_4 , V_19 -> V_5 , V_21 & 0xffff ) ;
F_10 ( V_2 , V_21 , V_22 ) ;
}
}
static inline void F_11 ( struct V_14 * V_15 )
{
struct V_24 * V_25 = F_12 ( V_15 -> V_16 -> V_8 -> V_26 ) ;
struct V_27 * V_28 = V_25 -> V_29 + V_15 -> V_30 ;
T_1 V_31 , V_32 ;
V_32 = F_13 ( V_28 ) ;
V_31 = V_28 -> V_23 -> V_31 ;
F_10 ( & V_15 -> V_16 -> V_2 ,
F_14 ( V_33 ,
V_34 , 1 ) ,
F_15 ( V_31 ) |
F_16 ( V_32 ) ) ;
}
static int F_17 ( struct V_14 * V_15 )
{
struct V_35 * V_36 = V_15 -> V_16 ;
struct V_27 * V_28 ;
T_1 V_37 = V_15 -> V_38 ;
T_1 V_39 = 0 ;
T_1 V_40 ;
int V_41 ;
struct V_42 * V_43 = NULL ;
struct V_24 * V_25 = F_12 ( V_36 -> V_8 -> V_26 ) ;
V_28 = V_25 -> V_29 + V_15 -> V_30 ;
F_18 ( F_6 ( V_36 -> V_8 ) ,
V_15 -> V_17 , V_15 -> V_44 ,
V_15 -> V_45 , V_15 -> V_30 ,
V_15 -> V_38 ) ;
V_39 = V_15 -> V_46 = F_13 ( V_28 ) ;
V_41 = F_19 ( & V_36 -> V_47 ) ;
if ( V_41 )
goto error;
V_43 = F_20 ( sizeof( * V_43 ) , V_48 ) ;
if ( ! V_43 ) {
F_21 ( & V_36 -> V_47 ) ;
V_41 = - V_49 ;
goto error;
}
V_41 = F_22 ( & V_36 -> V_2 , V_15 ) ;
if ( V_41 ) {
F_21 ( & V_36 -> V_47 ) ;
goto error;
}
if ( V_15 -> V_50 ) {
F_10 ( & V_36 -> V_2 ,
F_14 ( V_33 ,
F_23 () , 1 ) ,
F_24 ( V_15 -> V_30 ,
F_13 ( V_28 ) ) ) ;
}
if ( V_28 -> V_23 )
F_11 ( V_15 ) ;
V_40 = F_25 ( V_28 , V_37 ) ;
V_15 -> V_46 = V_40 ;
if ( V_15 -> V_51 )
F_10 ( & V_36 -> V_2 ,
F_14 ( V_15 -> V_51 , 0 , 0 ) ,
V_52 ) ;
F_8 ( V_15 ) ;
F_26 ( & V_36 -> V_2 , V_15 ) ;
F_27 ( F_6 ( V_36 -> V_8 ) , V_39 , V_40 ) ;
V_41 = F_28 ( V_25 , V_15 -> V_30 , V_40 ,
V_53 , V_36 ,
V_43 , NULL ) ;
V_43 = NULL ;
F_29 ( V_41 , L_1 ) ;
F_21 ( & V_36 -> V_47 ) ;
return 0 ;
error:
F_30 ( V_43 ) ;
return V_41 ;
}
static int F_31 ( struct V_35 * V_36 , struct V_24 * V_8 ,
unsigned int V_54 )
{
V_36 -> V_31 = V_54 ;
F_32 ( & V_36 -> V_55 ) ;
F_32 ( & V_36 -> V_47 ) ;
V_36 -> V_56 = V_8 -> V_56 + V_54 * V_57 ;
return 0 ;
}
