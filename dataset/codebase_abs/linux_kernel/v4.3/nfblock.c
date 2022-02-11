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
struct V_18 V_19 ;
struct V_20 V_21 ;
int V_22 , V_23 , V_24 ;
T_3 V_25 = V_14 -> V_26 . V_27 ;
V_22 = F_6 ( V_14 ) ;
V_24 = V_16 -> V_28 ;
F_7 (bvec, bio, iter) {
V_23 = V_19 . V_29 ;
V_23 >>= 9 ;
F_1 ( V_16 -> V_30 , 0 , V_22 , V_25 >> V_24 , V_23 >> V_24 ,
F_8 ( & V_19 ) ) ;
V_25 += V_23 ;
}
F_9 ( V_14 ) ;
}
static int F_10 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_15 * V_16 = V_32 -> V_35 -> V_36 ;
V_34 -> V_37 = V_16 -> V_9 >> ( 6 - V_16 -> V_28 ) ;
V_34 -> V_38 = 4 ;
V_34 -> V_39 = 16 ;
return 0 ;
}
static int T_4 F_11 ( int V_30 , T_2 V_9 , T_2 V_40 )
{
struct V_15 * V_16 ;
int V_41 = V_30 - V_42 ;
F_12 ( L_1 , V_41 ,
V_9 , V_40 ) ;
if ( V_40 < 512 || ( V_40 & ( V_40 - 1 ) ) ) {
F_13 ( L_2 , V_41 ) ;
return - V_43 ;
}
V_16 = F_14 ( sizeof( struct V_15 ) , V_44 ) ;
if ( ! V_16 )
goto V_45;
V_16 -> V_30 = V_30 ;
V_16 -> V_9 = V_9 ;
V_16 -> V_40 = V_40 ;
V_16 -> V_28 = F_15 ( V_40 ) - 10 ;
V_16 -> V_13 = F_16 ( V_44 ) ;
if ( V_16 -> V_13 == NULL )
goto V_46;
V_16 -> V_13 -> V_17 = V_16 ;
F_17 ( V_16 -> V_13 , F_5 ) ;
F_18 ( V_16 -> V_13 , V_40 ) ;
V_16 -> V_47 = F_19 ( 16 ) ;
if ( ! V_16 -> V_47 )
goto V_48;
V_16 -> V_47 -> V_1 = V_49 ;
V_16 -> V_47 -> V_50 = V_41 * 16 ;
V_16 -> V_47 -> V_51 = & V_52 ;
V_16 -> V_47 -> V_36 = V_16 ;
sprintf ( V_16 -> V_47 -> V_53 , L_3 , V_41 ) ;
F_20 ( V_16 -> V_47 , ( T_3 ) V_9 * ( V_40 / 512 ) ) ;
V_16 -> V_47 -> V_13 = V_16 -> V_13 ;
F_21 ( V_16 -> V_47 ) ;
F_22 ( & V_16 -> V_54 , & V_55 ) ;
return 0 ;
V_48:
F_23 ( V_16 -> V_13 ) ;
V_46:
F_24 ( V_16 ) ;
V_45:
return - V_56 ;
}
static int T_4 F_25 ( void )
{
T_2 V_9 , V_40 ;
int V_57 ;
V_7 = F_26 ( L_4 ) ;
if ( ! V_7 )
return - V_58 ;
V_49 = F_27 ( V_49 , L_5 ) ;
if ( V_49 <= 0 ) {
F_13 ( L_6 ) ;
return V_49 ;
}
for ( V_57 = V_42 ; V_57 < 24 ; V_57 ++ ) {
if ( F_3 ( V_57 , 0 , & V_9 , & V_40 ) )
continue;
F_11 ( V_57 , V_9 , V_40 ) ;
}
return 0 ;
}
static void T_5 F_28 ( void )
{
struct V_15 * V_16 , * V_59 ;
F_29 (dev, next, &nfhd_list, list) {
F_30 ( & V_16 -> V_54 ) ;
F_31 ( V_16 -> V_47 ) ;
F_32 ( V_16 -> V_47 ) ;
F_23 ( V_16 -> V_13 ) ;
F_24 ( V_16 ) ;
}
F_33 ( V_49 , L_5 ) ;
}
