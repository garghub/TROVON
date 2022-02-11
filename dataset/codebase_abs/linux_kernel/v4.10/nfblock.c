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
static T_3 F_5 ( struct V_12 * V_13 , struct V_14 * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_18 V_19 ;
struct V_20 V_21 ;
int V_22 , V_23 , V_24 ;
T_4 V_25 = V_14 -> V_26 . V_27 ;
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
return V_31 ;
}
static int F_10 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
struct V_15 * V_16 = V_33 -> V_36 -> V_37 ;
V_35 -> V_38 = V_16 -> V_9 >> ( 6 - V_16 -> V_28 ) ;
V_35 -> V_39 = 4 ;
V_35 -> V_40 = 16 ;
return 0 ;
}
static int T_5 F_11 ( int V_30 , T_2 V_9 , T_2 V_41 )
{
struct V_15 * V_16 ;
int V_42 = V_30 - V_43 ;
F_12 ( L_1 , V_42 ,
V_9 , V_41 ) ;
if ( V_41 < 512 || ( V_41 & ( V_41 - 1 ) ) ) {
F_13 ( L_2 , V_42 ) ;
return - V_44 ;
}
V_16 = F_14 ( sizeof( struct V_15 ) , V_45 ) ;
if ( ! V_16 )
goto V_46;
V_16 -> V_30 = V_30 ;
V_16 -> V_9 = V_9 ;
V_16 -> V_41 = V_41 ;
V_16 -> V_28 = F_15 ( V_41 ) - 10 ;
V_16 -> V_13 = F_16 ( V_45 ) ;
if ( V_16 -> V_13 == NULL )
goto V_47;
V_16 -> V_13 -> V_17 = V_16 ;
F_17 ( V_16 -> V_13 , F_5 ) ;
F_18 ( V_16 -> V_13 , V_41 ) ;
V_16 -> V_48 = F_19 ( 16 ) ;
if ( ! V_16 -> V_48 )
goto V_49;
V_16 -> V_48 -> V_1 = V_50 ;
V_16 -> V_48 -> V_51 = V_42 * 16 ;
V_16 -> V_48 -> V_52 = & V_53 ;
V_16 -> V_48 -> V_37 = V_16 ;
sprintf ( V_16 -> V_48 -> V_54 , L_3 , V_42 ) ;
F_20 ( V_16 -> V_48 , ( T_4 ) V_9 * ( V_41 / 512 ) ) ;
V_16 -> V_48 -> V_13 = V_16 -> V_13 ;
F_21 ( V_16 -> V_48 ) ;
F_22 ( & V_16 -> V_55 , & V_56 ) ;
return 0 ;
V_49:
F_23 ( V_16 -> V_13 ) ;
V_47:
F_24 ( V_16 ) ;
V_46:
return - V_57 ;
}
static int T_5 F_25 ( void )
{
T_2 V_9 , V_41 ;
int V_58 ;
V_7 = F_26 ( L_4 ) ;
if ( ! V_7 )
return - V_59 ;
V_50 = F_27 ( V_50 , L_5 ) ;
if ( V_50 <= 0 ) {
F_13 ( L_6 ) ;
return V_50 ;
}
for ( V_58 = V_43 ; V_58 < 24 ; V_58 ++ ) {
if ( F_3 ( V_58 , 0 , & V_9 , & V_41 ) )
continue;
F_11 ( V_58 , V_9 , V_41 ) ;
}
return 0 ;
}
static void T_6 F_28 ( void )
{
struct V_15 * V_16 , * V_60 ;
F_29 (dev, next, &nfhd_list, list) {
F_30 ( & V_16 -> V_55 ) ;
F_31 ( V_16 -> V_48 ) ;
F_32 ( V_16 -> V_48 ) ;
F_23 ( V_16 -> V_13 ) ;
F_24 ( V_16 ) ;
}
F_33 ( V_50 , L_5 ) ;
}
