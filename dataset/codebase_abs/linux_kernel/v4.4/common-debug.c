static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
T_5 V_8 = 0 , V_9 = 6000 ;
char * V_10 ;
T_3 V_11 ;
V_10 = F_2 ( V_9 , V_12 ) ;
if ( V_10 == NULL )
return - V_13 ;
V_8 = V_6 -> V_14 -> V_15 ( V_6 , false , V_10 , V_8 , V_9 ) ;
V_11 = F_3 ( V_2 , V_3 , V_4 , V_10 , V_8 ) ;
F_4 ( V_10 ) ;
return V_11 ;
}
void F_5 ( struct V_16 * V_17 ,
struct V_5 * V_6 )
{
F_6 ( L_1 , V_18 , V_17 , V_6 ,
& V_19 ) ;
}
static T_1 F_7 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
T_5 V_8 = 0 , V_9 = 1500 ;
T_1 V_11 = 0 ;
char * V_10 ;
V_10 = F_2 ( V_9 , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
V_8 = V_6 -> V_14 -> V_15 ( V_6 , true , V_10 , V_8 , V_9 ) ;
V_11 = F_3 ( V_2 , V_3 , V_4 , V_10 , V_8 ) ;
F_4 ( V_10 ) ;
return V_11 ;
}
void F_8 ( struct V_16 * V_17 ,
struct V_5 * V_6 )
{
F_6 ( L_2 , V_18 , V_17 , V_6 ,
& V_20 ) ;
}
void F_9 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
#define F_10 ( T_6 ) rxstats->phy_err_stats[c]++
#define F_11 ( T_6 ) (rxstats->c++)
F_11 ( V_25 ) ;
V_22 -> V_26 += V_24 -> V_27 ;
if ( V_24 -> V_28 & V_29 )
F_11 ( V_30 ) ;
if ( V_24 -> V_28 & V_31 )
F_11 ( V_32 ) ;
if ( V_24 -> V_28 & V_33 )
F_11 ( V_34 ) ;
if ( V_24 -> V_28 & V_35 )
F_11 ( V_36 ) ;
if ( V_24 -> V_28 & V_37 )
F_11 ( V_38 ) ;
if ( V_24 -> V_28 & V_39 )
F_11 ( V_40 ) ;
if ( V_24 -> V_28 & V_41 ) {
F_11 ( V_42 ) ;
if ( V_24 -> V_43 < V_44 )
F_10 ( V_24 -> V_43 ) ;
}
#undef F_11
#undef F_10
}
static T_1 F_12 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
#define F_13 ( T_7 , T_8 ) \
do { \
len += scnprintf(buf + len, size - len, \
"%18s : %10u\n", s, \
rxstats->e); \
} while (0)
struct V_21 * V_22 = V_1 -> V_7 ;
char * V_10 ;
unsigned int V_8 = 0 , V_9 = 1600 ;
T_1 V_11 = 0 ;
V_10 = F_2 ( V_9 , V_12 ) ;
if ( V_10 == NULL )
return - V_13 ;
F_13 ( L_3 , V_25 ) ;
F_13 ( L_4 , V_26 ) ;
F_13 ( L_5 , V_45 ) ;
F_13 ( L_6 , V_46 ) ;
F_13 ( L_7 , V_47 ) ;
F_13 ( L_8 , V_30 ) ;
F_13 ( L_9 , V_32 ) ;
F_13 ( L_10 , V_42 ) ;
F_13 ( L_11 , V_34 ) ;
F_13 ( L_12 , V_36 ) ;
F_13 ( L_13 , V_38 ) ;
F_13 ( L_14 , V_40 ) ;
F_13 ( L_15 , V_48 ) ;
F_13 ( L_16 , V_49 ) ;
F_13 ( L_17 , V_50 ) ;
F_13 ( L_18 , V_51 ) ;
if ( V_8 > V_9 )
V_8 = V_9 ;
V_11 = F_3 ( V_2 , V_3 , V_4 , V_10 , V_8 ) ;
F_4 ( V_10 ) ;
return V_11 ;
#undef F_13
}
void F_14 ( struct V_16 * V_17 ,
struct V_21 * V_22 )
{
F_6 ( L_19 , V_18 , V_17 , V_22 ,
& V_52 ) ;
}
static T_1 F_15 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
#define F_16 ( T_7 , T_9 ) \
len += scnprintf(buf + len, size - len, "%22s : %10u\n", s, \
rxstats->phy_err_stats[p]);
struct V_21 * V_22 = V_1 -> V_7 ;
char * V_10 ;
unsigned int V_8 = 0 , V_9 = 1600 ;
T_1 V_11 = 0 ;
V_10 = F_2 ( V_9 , V_12 ) ;
if ( V_10 == NULL )
return - V_13 ;
F_16 ( L_20 , V_53 ) ;
F_16 ( L_21 , V_54 ) ;
F_16 ( L_22 , V_55 ) ;
F_16 ( L_23 , V_56 ) ;
F_16 ( L_24 , V_57 ) ;
F_16 ( L_25 , V_58 ) ;
F_16 ( L_26 , V_59 ) ;
F_16 ( L_27 , V_60 ) ;
F_16 ( L_28 , V_61 ) ;
F_16 ( L_29 , V_62 ) ;
F_16 ( L_30 , V_63 ) ;
F_16 ( L_31 , V_64 ) ;
F_16 ( L_32 , V_65 ) ;
F_16 ( L_33 , V_66 ) ;
F_16 ( L_34 , V_67 ) ;
F_16 ( L_35 , V_68 ) ;
F_16 ( L_36 , V_69 ) ;
F_16 ( L_37 , V_70 ) ;
F_16 ( L_38 , V_71 ) ;
F_16 ( L_39 , V_72 ) ;
F_16 ( L_40 , V_73 ) ;
F_16 ( L_41 , V_74 ) ;
F_16 ( L_42 , V_75 ) ;
F_16 ( L_43 , V_76 ) ;
F_16 ( L_44 , V_77 ) ;
F_16 ( L_45 , V_78 ) ;
F_16 ( L_46 , V_79 ) ;
F_16 ( L_47 , V_80 ) ;
F_16 ( L_48 , V_81 ) ;
F_16 ( L_49 , V_82 ) ;
if ( V_8 > V_9 )
V_8 = V_9 ;
V_11 = F_3 ( V_2 , V_3 , V_4 , V_10 , V_8 ) ;
F_4 ( V_10 ) ;
return V_11 ;
#undef F_16
}
void F_17 ( struct V_16 * V_17 ,
struct V_21 * V_22 )
{
F_6 ( L_50 , V_18 , V_17 , V_22 ,
& V_83 ) ;
}
