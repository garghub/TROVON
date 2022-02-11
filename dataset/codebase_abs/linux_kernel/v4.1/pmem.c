static void F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
unsigned int V_4 , unsigned int V_5 , int V_6 ,
T_1 V_7 )
{
void * V_8 = F_2 ( V_3 ) ;
T_2 V_9 = V_7 << 9 ;
if ( V_6 == V_10 ) {
memcpy ( V_8 + V_5 , V_2 -> V_11 + V_9 , V_4 ) ;
F_3 ( V_3 ) ;
} else {
F_3 ( V_3 ) ;
memcpy ( V_2 -> V_11 + V_9 , V_8 + V_5 , V_4 ) ;
}
F_4 ( V_8 ) ;
}
static void F_5 ( struct V_12 * V_13 , struct V_14 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_1 * V_2 = V_16 -> V_18 -> V_19 ;
int V_6 ;
struct V_20 V_21 ;
T_1 V_7 ;
struct V_22 V_23 ;
int V_24 = 0 ;
if ( F_6 ( V_14 ) > F_7 ( V_16 -> V_18 ) ) {
V_24 = - V_25 ;
goto V_26;
}
F_8 ( V_14 -> V_27 & V_28 ) ;
V_6 = F_9 ( V_14 ) ;
V_7 = V_14 -> V_29 . V_30 ;
F_10 (bvec, bio, iter) {
F_1 ( V_2 , V_21 . V_31 , V_21 . V_32 , V_21 . V_33 ,
V_6 , V_7 ) ;
V_7 += V_21 . V_32 >> 9 ;
}
V_26:
F_11 ( V_14 , V_24 ) ;
}
static int F_12 ( struct V_15 * V_16 , T_1 V_7 ,
struct V_3 * V_3 , int V_6 )
{
struct V_1 * V_2 = V_16 -> V_18 -> V_19 ;
F_1 ( V_2 , V_3 , V_34 , 0 , V_6 , V_7 ) ;
F_13 ( V_3 , V_6 & V_35 , 0 ) ;
return 0 ;
}
static long F_14 ( struct V_15 * V_16 , T_1 V_7 ,
void * * V_36 , unsigned long * V_37 , long V_38 )
{
struct V_1 * V_2 = V_16 -> V_18 -> V_19 ;
T_2 V_39 = V_7 << 9 ;
if ( ! V_2 )
return - V_40 ;
* V_36 = V_2 -> V_11 + V_39 ;
* V_37 = ( V_2 -> V_41 + V_39 ) >> V_42 ;
return V_2 -> V_38 - V_39 ;
}
static struct V_1 * F_15 ( struct V_43 * V_44 , struct V_45 * V_46 )
{
struct V_1 * V_2 ;
struct V_47 * V_48 ;
int V_49 , V_24 ;
V_24 = - V_50 ;
V_2 = F_16 ( sizeof( * V_2 ) , V_51 ) ;
if ( ! V_2 )
goto V_26;
V_2 -> V_41 = V_46 -> V_52 ;
V_2 -> V_38 = F_17 ( V_46 ) ;
V_24 = - V_53 ;
if ( ! F_18 ( V_2 -> V_41 , V_2 -> V_38 , L_1 ) ) {
F_19 ( V_44 , L_2 , & V_2 -> V_41 , V_2 -> V_38 ) ;
goto V_54;
}
V_24 = - V_50 ;
V_2 -> V_11 = F_20 ( V_2 -> V_41 , V_2 -> V_38 ) ;
if ( ! V_2 -> V_11 )
goto V_55;
V_2 -> V_56 = F_21 ( V_51 ) ;
if ( ! V_2 -> V_56 )
goto V_57;
F_22 ( V_2 -> V_56 , F_5 ) ;
F_23 ( V_2 -> V_56 , 1024 ) ;
F_24 ( V_2 -> V_56 , V_58 ) ;
V_48 = F_25 ( V_59 ) ;
if ( ! V_48 )
goto V_60;
V_49 = F_26 ( & V_61 ) - 1 ;
V_48 -> V_62 = V_63 ;
V_48 -> V_64 = V_59 * V_49 ;
V_48 -> V_65 = & V_66 ;
V_48 -> V_19 = V_2 ;
V_48 -> V_67 = V_2 -> V_56 ;
V_48 -> V_68 = V_69 ;
sprintf ( V_48 -> V_70 , L_3 , V_49 ) ;
V_48 -> V_71 = V_44 ;
F_27 ( V_48 , V_2 -> V_38 >> 9 ) ;
V_2 -> V_72 = V_48 ;
F_28 ( V_48 ) ;
return V_2 ;
V_60:
F_29 ( V_2 -> V_56 ) ;
V_57:
F_30 ( V_2 -> V_11 ) ;
V_55:
F_31 ( V_2 -> V_41 , V_2 -> V_38 ) ;
V_54:
F_32 ( V_2 ) ;
V_26:
return F_33 ( V_24 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( V_2 -> V_72 ) ;
F_36 ( V_2 -> V_72 ) ;
F_29 ( V_2 -> V_56 ) ;
F_30 ( V_2 -> V_11 ) ;
F_31 ( V_2 -> V_41 , V_2 -> V_38 ) ;
F_32 ( V_2 ) ;
}
static int F_37 ( struct V_73 * V_74 )
{
struct V_1 * V_2 ;
struct V_45 * V_46 ;
if ( F_38 ( V_74 -> V_75 > 1 ) )
return - V_76 ;
V_46 = F_39 ( V_74 , V_77 , 0 ) ;
if ( ! V_46 )
return - V_76 ;
V_2 = F_15 ( & V_74 -> V_44 , V_46 ) ;
if ( F_40 ( V_2 ) )
return F_41 ( V_2 ) ;
F_42 ( V_74 , V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_44 ( V_74 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
static int T_3 F_45 ( void )
{
int error ;
V_63 = F_46 ( 0 , L_1 ) ;
if ( V_63 < 0 )
return V_63 ;
error = F_47 ( & V_78 ) ;
if ( error )
F_48 ( V_63 , L_1 ) ;
return error ;
}
static void F_49 ( void )
{
F_50 ( & V_78 ) ;
F_48 ( V_63 , L_1 ) ;
}
