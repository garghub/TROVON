static inline T_1 F_1 ( T_2 V_1 , T_2 V_2 , T_2 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 )
{
return F_2 ( V_7 + V_8 , V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 ) ;
}
static inline T_1 F_3 ( T_2 V_1 , T_2 V_2 , T_2 * V_9 ,
T_2 * V_10 )
{
return F_2 ( V_7 + V_11 , V_1 , V_2 ,
F_4 ( V_9 ) , F_4 ( V_10 ) ) ;
}
static void F_5 ( struct V_12 * V_13 , struct V_14 * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_18 * V_19 ;
int V_20 , V_21 , V_22 , V_23 ;
T_3 V_24 = V_14 -> V_25 ;
V_21 = F_6 ( V_14 ) ;
V_23 = V_16 -> V_26 ;
F_7 (bvec, bio, i) {
V_22 = V_19 -> V_27 ;
V_22 >>= 9 ;
F_1 ( V_16 -> V_28 , 0 , V_21 , V_24 >> V_23 , V_22 >> V_23 ,
F_8 ( V_19 ) ) ;
V_24 += V_22 ;
}
F_9 ( V_14 , 0 ) ;
}
static int F_10 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_15 * V_16 = V_30 -> V_33 -> V_34 ;
V_32 -> V_35 = V_16 -> V_9 >> ( 6 - V_16 -> V_26 ) ;
V_32 -> V_36 = 4 ;
V_32 -> V_37 = 16 ;
return 0 ;
}
static int T_4 F_11 ( int V_28 , T_2 V_9 , T_2 V_38 )
{
struct V_15 * V_16 ;
int V_39 = V_28 - V_40 ;
F_12 ( L_1 , V_39 ,
V_9 , V_38 ) ;
if ( V_38 < 512 || ( V_38 & ( V_38 - 1 ) ) ) {
F_13 ( L_2 , V_39 ) ;
return - V_41 ;
}
V_16 = F_14 ( sizeof( struct V_15 ) , V_42 ) ;
if ( ! V_16 )
goto V_43;
V_16 -> V_28 = V_28 ;
V_16 -> V_9 = V_9 ;
V_16 -> V_38 = V_38 ;
V_16 -> V_26 = F_15 ( V_38 ) - 10 ;
V_16 -> V_13 = F_16 ( V_42 ) ;
if ( V_16 -> V_13 == NULL )
goto V_44;
V_16 -> V_13 -> V_17 = V_16 ;
F_17 ( V_16 -> V_13 , F_5 ) ;
F_18 ( V_16 -> V_13 , V_38 ) ;
V_16 -> V_45 = F_19 ( 16 ) ;
if ( ! V_16 -> V_45 )
goto V_46;
V_16 -> V_45 -> V_1 = V_47 ;
V_16 -> V_45 -> V_48 = V_39 * 16 ;
V_16 -> V_45 -> V_49 = & V_50 ;
V_16 -> V_45 -> V_34 = V_16 ;
sprintf ( V_16 -> V_45 -> V_51 , L_3 , V_39 ) ;
F_20 ( V_16 -> V_45 , ( T_3 ) V_9 * ( V_38 / 512 ) ) ;
V_16 -> V_45 -> V_13 = V_16 -> V_13 ;
F_21 ( V_16 -> V_45 ) ;
F_22 ( & V_16 -> V_52 , & V_53 ) ;
return 0 ;
V_46:
F_23 ( V_16 -> V_13 ) ;
V_44:
F_24 ( V_16 ) ;
V_43:
return - V_54 ;
}
static int T_4 F_25 ( void )
{
T_2 V_9 , V_38 ;
int V_20 ;
V_7 = F_26 ( L_4 ) ;
if ( ! V_7 )
return - V_55 ;
V_47 = F_27 ( V_47 , L_5 ) ;
if ( V_47 <= 0 ) {
F_13 ( L_6 ) ;
return V_47 ;
}
for ( V_20 = V_40 ; V_20 < 24 ; V_20 ++ ) {
if ( F_3 ( V_20 , 0 , & V_9 , & V_38 ) )
continue;
F_11 ( V_20 , V_9 , V_38 ) ;
}
return 0 ;
}
static void T_5 F_28 ( void )
{
struct V_15 * V_16 , * V_56 ;
F_29 (dev, next, &nfhd_list, list) {
F_30 ( & V_16 -> V_52 ) ;
F_31 ( V_16 -> V_45 ) ;
F_32 ( V_16 -> V_45 ) ;
F_23 ( V_16 -> V_13 ) ;
F_24 ( V_16 ) ;
}
F_33 ( V_47 , L_5 ) ;
}
