static void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 != - V_4 )
F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_5 * V_6 , const T_1 * V_7 ,
unsigned int V_8 )
{
unsigned int V_9 ;
unsigned int V_10 ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = V_12 -> V_16 ;
struct V_17 * V_18 = ( void * ) V_7 ;
struct V_19 * V_20 ;
int V_3 = - V_21 ;
if ( ! F_5 ( V_18 , V_8 ) )
goto V_22;
if ( V_18 -> V_23 != V_24 )
goto V_22;
if ( F_6 ( V_18 ) < sizeof( * V_20 ) )
goto V_22;
V_20 = F_7 ( V_18 ) ;
V_10 = F_8 ( V_20 -> V_10 ) ;
V_7 += F_9 ( V_18 -> V_25 ) ;
V_8 -= F_9 ( V_18 -> V_25 ) ;
if ( V_8 < V_10 )
goto V_22;
V_9 = V_8 - V_10 ;
F_10 ( V_14 , V_26 ) ;
F_11 ( V_14 , F_12 ( V_6 ) &
V_26 ) ;
V_3 = F_13 ( V_14 , V_7 , V_9 ) ;
F_14 ( V_6 , F_15 ( V_14 ) &
V_27 ) ;
if ( V_3 )
goto V_28;
F_16 ( V_16 , V_26 ) ;
F_17 ( V_16 , F_12 ( V_6 ) &
V_26 ) ;
V_3 = F_18 ( V_16 , V_7 + V_9 , V_10 ) ;
F_14 ( V_6 , F_19 ( V_16 ) &
V_27 ) ;
V_28:
return V_3 ;
V_22:
F_14 ( V_6 , V_29 ) ;
goto V_28;
}
static void F_20 ( struct V_30 * V_31 ,
int V_3 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_35 * V_36 = ( void * ) ( V_34 -> V_37 + V_12 -> V_38 ) ;
if ( V_3 )
goto V_28;
F_23 ( V_36 , V_34 -> V_39 , V_36 -> V_40 ,
V_34 -> V_41 ) ;
F_24 ( V_36 , F_25 ( V_2 ) &
V_42 ,
V_34 -> V_43 , V_2 ) ;
V_3 = F_26 ( V_36 ) ;
if ( V_3 )
goto V_28;
F_23 ( V_36 , V_34 -> V_44 , V_36 -> V_40 ,
V_34 -> V_45 ) ;
F_24 ( V_36 , F_25 ( V_2 ) &
V_42 ,
V_34 -> V_46 , V_2 ) ;
V_3 = F_27 ( V_36 ) ;
if ( V_3 )
goto V_28;
F_28 ( V_36 -> V_40 , V_34 -> V_39 ,
V_34 -> V_41 ,
F_29 ( V_6 ) , 1 ) ;
V_28:
F_1 ( V_2 , V_3 ) ;
}
static void F_30 ( struct V_30 * V_31 ,
int V_3 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_35 * V_36 = ( void * ) ( V_34 -> V_37 + V_12 -> V_38 ) ;
if ( V_3 )
goto V_28;
F_23 ( V_36 , V_34 -> V_44 , V_36 -> V_40 ,
V_34 -> V_45 ) ;
F_24 ( V_36 , F_25 ( V_2 ) &
V_42 ,
V_34 -> V_46 , V_2 ) ;
V_3 = F_27 ( V_36 ) ;
if ( V_3 )
goto V_28;
F_28 ( V_36 -> V_40 , V_34 -> V_39 ,
V_34 -> V_41 ,
F_29 ( V_6 ) , 1 ) ;
V_28:
F_1 ( V_2 , V_3 ) ;
}
static void F_31 ( struct V_30 * V_31 ,
int V_3 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_35 * V_36 = ( void * ) ( V_34 -> V_37 + V_12 -> V_38 ) ;
if ( V_3 )
goto V_28;
F_28 ( V_36 -> V_40 , V_34 -> V_39 ,
V_34 -> V_41 ,
F_29 ( V_6 ) , 1 ) ;
V_28:
F_2 ( V_2 , V_3 ) ;
}
static void F_32 ( struct V_30 * V_31 ,
int V_3 )
{
T_1 * V_47 ;
unsigned int V_48 ;
struct V_49 * V_50 ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_35 * V_36 = ( void * ) ( V_34 -> V_37 + V_12 -> V_38 ) ;
unsigned int V_41 = V_2 -> V_41 ;
if ( V_3 )
goto V_28;
F_23 ( V_36 , V_34 -> V_39 , V_36 -> V_40 ,
V_34 -> V_41 ) ;
F_24 ( V_36 ,
F_25 ( V_2 ) &
V_42 ,
V_34 -> V_43 , V_2 ) ;
V_3 = F_26 ( V_36 ) ;
if ( V_3 )
goto V_28;
F_23 ( V_36 , V_34 -> V_44 , V_36 -> V_40 ,
V_34 -> V_45 ) ;
F_24 ( V_36 , F_25 ( V_2 ) &
V_42 ,
V_34 -> V_46 , V_2 ) ;
V_3 = F_27 ( V_36 ) ;
if ( V_3 )
goto V_28;
V_48 = F_29 ( V_6 ) ;
V_41 -= V_48 ;
V_47 = V_36 -> V_40 + V_48 ;
F_28 ( V_47 , V_34 -> V_39 , V_34 -> V_41 ,
V_48 , 0 ) ;
V_3 = memcmp ( V_47 , V_36 -> V_40 , V_48 ) ? - V_51 : 0 ;
if ( V_3 )
goto V_28;
V_50 = F_22 ( V_2 ) ;
F_33 ( V_50 , V_12 -> V_16 ) ;
F_34 ( V_50 , F_25 ( V_2 ) ,
V_2 -> V_52 . V_46 , V_2 -> V_52 . V_32 ) ;
F_35 ( V_50 , V_2 -> V_53 , V_2 -> V_54 ,
V_41 , V_2 -> V_55 ) ;
V_3 = F_36 ( V_50 ) ;
V_28:
F_1 ( V_2 , V_3 ) ;
}
static void F_37 ( struct V_30 * V_31 ,
int V_3 )
{
T_1 * V_47 ;
unsigned int V_48 ;
struct V_49 * V_50 ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_35 * V_36 = ( void * ) ( V_34 -> V_37 + V_12 -> V_38 ) ;
unsigned int V_41 = V_2 -> V_41 ;
if ( V_3 )
goto V_28;
F_23 ( V_36 , V_34 -> V_44 , V_36 -> V_40 ,
V_34 -> V_45 ) ;
F_24 ( V_36 , F_25 ( V_2 ) &
V_42 ,
V_34 -> V_46 , V_2 ) ;
V_3 = F_27 ( V_36 ) ;
if ( V_3 )
goto V_28;
V_48 = F_29 ( V_6 ) ;
V_41 -= V_48 ;
V_47 = V_36 -> V_40 + V_48 ;
F_28 ( V_47 , V_34 -> V_39 , V_34 -> V_41 ,
V_48 , 0 ) ;
V_3 = memcmp ( V_47 , V_36 -> V_40 , V_48 ) ? - V_51 : 0 ;
if ( V_3 )
goto V_28;
V_50 = F_22 ( V_2 ) ;
F_33 ( V_50 , V_12 -> V_16 ) ;
F_34 ( V_50 , F_25 ( V_2 ) ,
V_2 -> V_52 . V_46 , V_2 -> V_52 . V_32 ) ;
F_35 ( V_50 , V_2 -> V_53 , V_2 -> V_54 ,
V_41 , V_2 -> V_55 ) ;
V_3 = F_36 ( V_50 ) ;
V_28:
F_1 ( V_2 , V_3 ) ;
}
static void F_38 ( struct V_30 * V_31 ,
int V_3 )
{
T_1 * V_47 ;
unsigned int V_48 ;
struct V_49 * V_50 ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_35 * V_36 = ( void * ) ( V_34 -> V_37 + V_12 -> V_38 ) ;
unsigned int V_41 = V_2 -> V_41 ;
if ( V_3 )
goto V_28;
V_48 = F_29 ( V_6 ) ;
V_41 -= V_48 ;
V_47 = V_36 -> V_40 + V_48 ;
F_28 ( V_47 , V_34 -> V_39 , V_34 -> V_41 ,
V_48 , 0 ) ;
V_3 = memcmp ( V_47 , V_36 -> V_40 , V_48 ) ? - V_51 : 0 ;
if ( V_3 )
goto V_28;
V_50 = F_22 ( V_2 ) ;
F_33 ( V_50 , V_12 -> V_16 ) ;
F_34 ( V_50 , F_25 ( V_2 ) ,
V_2 -> V_52 . V_46 , V_2 -> V_52 . V_32 ) ;
F_35 ( V_50 , V_2 -> V_53 , V_2 -> V_54 ,
V_41 , V_2 -> V_55 ) ;
V_3 = F_36 ( V_50 ) ;
V_28:
F_1 ( V_2 , V_3 ) ;
}
static T_1 * F_39 ( struct V_1 * V_2 ,
unsigned int V_56 )
{
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_35 * V_36 = ( void * ) ( V_34 -> V_37 + V_12 -> V_38 ) ;
T_1 * V_57 = V_34 -> V_37 ;
int V_3 ;
V_57 = ( T_1 * ) F_40 ( ( unsigned long ) V_57 + F_41 ( V_14 ) ,
F_41 ( V_14 ) + 1 ) ;
F_42 ( V_36 , V_14 ) ;
V_3 = F_43 ( V_36 ) ;
if ( V_3 )
return F_44 ( V_3 ) ;
F_23 ( V_36 , V_34 -> V_58 , V_57 , V_34 -> V_59 ) ;
F_24 ( V_36 , F_25 ( V_2 ) & V_56 ,
V_34 -> V_60 , V_2 ) ;
V_3 = F_26 ( V_36 ) ;
if ( V_3 )
return F_44 ( V_3 ) ;
F_23 ( V_36 , V_34 -> V_39 , V_57 , V_34 -> V_41 ) ;
F_24 ( V_36 , F_25 ( V_2 ) & V_56 ,
V_34 -> V_43 , V_2 ) ;
V_3 = F_26 ( V_36 ) ;
if ( V_3 )
return F_44 ( V_3 ) ;
F_23 ( V_36 , V_34 -> V_44 , V_57 ,
V_34 -> V_45 ) ;
F_24 ( V_36 , F_25 ( V_2 ) & V_56 ,
V_34 -> V_46 , V_2 ) ;
V_3 = F_27 ( V_36 ) ;
if ( V_3 )
return F_44 ( V_3 ) ;
return V_57 ;
}
static int F_45 ( struct V_1 * V_2 , T_1 * V_55 ,
unsigned int V_56 )
{
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_61 * V_54 = V_2 -> V_54 ;
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_61 * V_63 = V_34 -> V_63 ;
struct V_61 * V_58 = V_34 -> V_58 ;
struct V_61 * V_44 = V_34 -> V_44 ;
struct V_61 * V_64 ;
struct V_61 * V_65 ;
unsigned int V_66 = F_46 ( V_6 ) ;
unsigned int V_41 = V_2 -> V_41 ;
struct V_67 * V_68 ;
T_1 * V_69 ;
T_1 * V_57 ;
V_68 = F_47 ( V_54 ) ;
V_69 = F_48 ( V_68 ) ? NULL : F_49 ( V_68 ) + V_54 -> V_70 ;
if ( V_66 ) {
F_50 ( V_63 , 2 ) ;
F_51 ( V_63 , V_55 , V_66 ) ;
F_52 ( V_63 , V_54 , V_69 == V_55 + V_66 , 2 ) ;
V_54 = V_63 ;
V_41 += V_66 ;
}
if ( F_53 ( V_62 ) )
return - V_21 ;
V_64 = V_62 + 1 ;
if ( F_53 ( V_64 ) )
return - V_21 ;
V_65 = V_62 + 2 ;
if ( ! F_53 ( V_65 ) )
return - V_21 ;
F_50 ( V_58 , 2 ) ;
F_54 ( V_58 , F_47 ( V_62 ) , V_62 -> V_71 , V_62 -> V_70 ) ;
F_54 ( V_58 + 1 , F_47 ( V_65 ) , V_65 -> V_71 , V_65 -> V_70 ) ;
F_50 ( V_44 , 1 ) ;
F_54 ( V_44 , F_47 ( V_64 ) , V_64 -> V_71 , V_64 -> V_70 ) ;
V_34 -> V_41 = V_41 ;
V_34 -> V_59 = V_62 -> V_71 + V_65 -> V_71 ;
V_34 -> V_45 = V_64 -> V_71 ;
V_34 -> V_39 = V_54 ;
V_34 -> V_46 = F_31 ;
V_34 -> V_60 = F_20 ;
V_34 -> V_43 = F_30 ;
V_57 = F_39 ( V_2 , V_56 ) ;
if ( F_55 ( V_57 ) )
return F_56 ( V_57 ) ;
F_28 ( V_57 , V_54 , V_41 ,
F_29 ( V_6 ) , 1 ) ;
return 0 ;
}
static void F_57 ( struct V_30 * V_2 ,
int V_3 )
{
struct V_1 * V_31 = V_2 -> V_32 ;
if ( ! V_3 ) {
struct V_5 * V_6 = F_21 ( V_31 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_49 * V_50 = F_22 ( V_31 ) ;
T_1 * V_55 = ( T_1 * ) ( V_50 + 1 ) +
F_58 ( V_12 -> V_16 ) ;
V_3 = F_45 ( V_31 , V_55 , 0 ) ;
}
F_1 ( V_31 , V_3 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_15 * V_16 = V_12 -> V_16 ;
struct V_61 * V_54 = V_2 -> V_54 ;
unsigned int V_41 = V_2 -> V_41 ;
struct V_49 * V_50 = ( void * ) ( V_34 -> V_37
+ V_12 -> V_38 ) ;
T_1 * V_55 = ( T_1 * ) V_50 - F_60 ( V_16 ) ;
int V_3 ;
F_33 ( V_50 , V_16 ) ;
F_34 ( V_50 , F_25 ( V_2 ) ,
F_57 , V_2 ) ;
F_35 ( V_50 , V_2 -> V_53 , V_54 , V_41 , V_2 -> V_55 ) ;
memcpy ( V_55 , V_2 -> V_55 , F_46 ( V_6 ) ) ;
V_3 = F_61 ( V_50 ) ;
if ( V_3 )
return V_3 ;
return F_45 ( V_2 , V_55 , V_42 ) ;
}
static void F_62 ( struct V_30 * V_2 ,
int V_3 )
{
struct V_1 * V_31 = V_2 -> V_32 ;
if ( ! V_3 ) {
struct V_72 * V_73 = F_22 ( V_31 ) ;
V_3 = F_45 ( V_31 , V_73 -> V_74 , 0 ) ;
}
F_1 ( V_31 , V_3 ) ;
}
static int F_63 ( struct V_75 * V_2 )
{
struct V_5 * V_6 = F_64 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_1 * V_31 = & V_2 -> V_31 ;
struct V_72 * V_73 = F_22 ( V_31 ) ;
T_1 * V_55 = V_2 -> V_74 ;
int V_3 ;
F_65 ( V_73 , V_12 -> V_16 ) ;
F_66 ( V_73 , F_25 ( V_31 ) ,
F_62 , V_31 ) ;
F_67 ( V_73 , V_31 -> V_53 , V_31 -> V_54 , V_31 -> V_41 ,
V_31 -> V_55 ) ;
F_68 ( V_73 , V_55 , V_2 -> V_76 ) ;
V_3 = F_69 ( V_73 ) ;
if ( V_3 )
return V_3 ;
return F_45 ( V_31 , V_55 , V_42 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
T_1 * V_77 ;
T_1 * V_47 ;
unsigned int V_48 ;
V_34 -> V_46 = F_38 ;
V_34 -> V_60 = F_32 ;
V_77 = F_39 ( V_2 , V_42 ) ;
if ( F_55 ( V_77 ) )
return F_56 ( V_77 ) ;
V_48 = F_29 ( V_6 ) ;
V_47 = V_77 + V_48 ;
F_28 ( V_47 , V_34 -> V_39 , V_34 -> V_41 ,
V_48 , 0 ) ;
return memcmp ( V_47 , V_77 , V_48 ) ? - V_51 : 0 ;
}
static int F_71 ( struct V_1 * V_2 , T_1 * V_55 ,
unsigned int V_41 )
{
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_33 * V_34 = F_22 ( V_2 ) ;
struct V_61 * V_53 = V_2 -> V_53 ;
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_61 * V_63 = V_34 -> V_63 ;
struct V_61 * V_58 = V_34 -> V_58 ;
struct V_61 * V_44 = V_34 -> V_44 ;
struct V_61 * V_64 ;
struct V_61 * V_65 ;
unsigned int V_66 = F_46 ( V_6 ) ;
struct V_67 * V_78 ;
T_1 * V_79 ;
V_78 = F_47 ( V_53 ) ;
V_79 = F_48 ( V_78 ) ? NULL : F_49 ( V_78 ) + V_53 -> V_70 ;
if ( V_66 ) {
F_50 ( V_63 , 2 ) ;
F_51 ( V_63 , V_55 , V_66 ) ;
F_52 ( V_63 , V_53 , V_79 == V_55 + V_66 , 2 ) ;
V_53 = V_63 ;
V_41 += V_66 ;
}
if ( F_53 ( V_62 ) )
return - V_21 ;
V_64 = V_62 + 1 ;
if ( F_53 ( V_64 ) )
return - V_21 ;
V_65 = V_62 + 2 ;
if ( ! F_53 ( V_65 ) )
return - V_21 ;
F_50 ( V_58 , 2 ) ;
F_54 ( V_58 , F_47 ( V_62 ) , V_62 -> V_71 , V_62 -> V_70 ) ;
F_54 ( V_58 + 1 , F_47 ( V_65 ) , V_65 -> V_71 , V_65 -> V_70 ) ;
F_50 ( V_44 , 1 ) ;
F_54 ( V_44 , F_47 ( V_64 ) , V_64 -> V_71 , V_64 -> V_70 ) ;
V_34 -> V_41 = V_41 ;
V_34 -> V_59 = V_62 -> V_71 + V_65 -> V_71 ;
V_34 -> V_45 = V_64 -> V_71 ;
V_34 -> V_39 = V_53 ;
V_34 -> V_46 = F_38 ;
V_34 -> V_60 = F_32 ;
V_34 -> V_43 = F_37 ;
return F_70 ( V_2 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_49 * V_50 = F_22 ( V_2 ) ;
unsigned int V_41 = V_2 -> V_41 ;
unsigned int V_48 = F_29 ( V_6 ) ;
T_1 * V_55 = V_2 -> V_55 ;
int V_3 ;
if ( V_41 < V_48 )
return - V_21 ;
V_41 -= V_48 ;
V_3 = F_71 ( V_2 , V_55 , V_41 ) ;
if ( V_3 )
return V_3 ;
F_33 ( V_50 , V_12 -> V_16 ) ;
F_34 ( V_50 , F_25 ( V_2 ) ,
V_2 -> V_52 . V_46 , V_2 -> V_52 . V_32 ) ;
F_35 ( V_50 , V_2 -> V_53 , V_2 -> V_54 , V_41 , V_55 ) ;
return F_36 ( V_50 ) ;
}
static int F_73 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_74 ( V_81 ) ;
struct V_84 * V_85 = F_75 ( V_83 ) ;
struct V_11 * V_12 = F_76 ( V_81 ) ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_3 ;
V_14 = F_77 ( & V_85 -> V_14 ) ;
if ( F_55 ( V_14 ) )
return F_56 ( V_14 ) ;
V_16 = F_78 ( & V_85 -> V_16 ) ;
V_3 = F_56 ( V_16 ) ;
if ( F_55 ( V_16 ) )
goto V_86;
V_12 -> V_14 = V_14 ;
V_12 -> V_16 = V_16 ;
V_12 -> V_38 = F_40 ( 2 * F_79 ( V_14 ) +
F_41 ( V_14 ) ,
F_41 ( V_14 ) + 1 ) +
F_60 ( V_16 ) ;
V_81 -> V_87 . V_88 = sizeof( struct V_33 ) +
V_12 -> V_38 +
F_80 (unsigned int,
crypto_ahash_reqsize(auth) +
sizeof(struct ahash_request),
sizeof(struct skcipher_givcrypt_request) +
crypto_ablkcipher_reqsize(enc)) ;
return 0 ;
V_86:
F_81 ( V_14 ) ;
return V_3 ;
}
static void F_82 ( struct V_80 * V_81 )
{
struct V_11 * V_12 = F_76 ( V_81 ) ;
F_81 ( V_12 -> V_14 ) ;
F_83 ( V_12 -> V_16 ) ;
}
static struct V_82 * F_84 ( struct V_17 * * V_89 )
{
struct V_90 * V_91 ;
struct V_82 * V_83 ;
struct V_92 * V_14 ;
struct V_93 * V_94 ;
struct V_93 * V_16 ;
struct V_84 * V_12 ;
const char * V_95 ;
int V_3 ;
V_91 = F_85 ( V_89 ) ;
if ( F_55 ( V_91 ) )
return F_86 ( V_91 ) ;
if ( ( V_91 -> type ^ V_96 ) & V_91 -> V_97 )
return F_44 ( - V_21 ) ;
V_14 = F_87 ( V_89 [ 1 ] , V_98 ,
V_99 ) ;
if ( F_55 ( V_14 ) )
return F_86 ( V_14 ) ;
V_94 = & V_14 -> V_52 ;
V_95 = F_88 ( V_89 [ 2 ] ) ;
V_3 = F_56 ( V_95 ) ;
if ( F_55 ( V_95 ) )
goto V_100;
V_83 = F_89 ( sizeof( * V_83 ) + sizeof( * V_12 ) , V_101 ) ;
V_3 = - V_102 ;
if ( ! V_83 )
goto V_100;
V_12 = F_75 ( V_83 ) ;
V_3 = F_90 ( & V_12 -> V_14 , V_14 , V_83 ) ;
if ( V_3 )
goto V_103;
F_91 ( & V_12 -> V_16 , V_83 ) ;
V_3 = F_92 ( & V_12 -> V_16 , V_95 , 0 ,
F_93 ( V_91 -> type ,
V_91 -> V_97 ) ) ;
if ( V_3 )
goto V_104;
V_16 = F_94 ( & V_12 -> V_16 ) ;
V_3 = - V_105 ;
if ( snprintf ( V_83 -> V_106 . V_107 , V_108 ,
L_1 , V_94 -> V_107 , V_16 -> V_107 ) >=
V_108 )
goto V_109;
if ( snprintf ( V_83 -> V_106 . V_110 , V_108 ,
L_1 , V_94 -> V_110 ,
V_16 -> V_110 ) >= V_108 )
goto V_109;
V_83 -> V_106 . V_111 = V_96 ;
V_83 -> V_106 . V_111 |= V_16 -> V_111 & V_112 ;
V_83 -> V_106 . V_113 = V_16 -> V_113 *
10 + V_94 -> V_113 ;
V_83 -> V_106 . V_114 = V_16 -> V_114 ;
V_83 -> V_106 . V_115 = V_94 -> V_115 | V_16 -> V_115 ;
V_83 -> V_106 . V_116 = & V_117 ;
V_83 -> V_106 . V_118 . V_66 = V_16 -> V_119 . V_66 ;
V_83 -> V_106 . V_118 . V_120 = V_14 -> V_121 ;
V_83 -> V_106 . V_122 = sizeof( struct V_11 ) ;
V_83 -> V_106 . V_123 = F_73 ;
V_83 -> V_106 . V_124 = F_82 ;
V_83 -> V_106 . V_118 . V_125 = F_3 ;
V_83 -> V_106 . V_118 . V_126 = F_59 ;
V_83 -> V_106 . V_118 . V_127 = F_72 ;
V_83 -> V_106 . V_118 . V_128 = F_63 ;
V_28:
F_95 ( V_94 ) ;
return V_83 ;
V_109:
F_96 ( & V_12 -> V_16 ) ;
V_104:
F_97 ( & V_12 -> V_14 ) ;
V_103:
F_98 ( V_83 ) ;
V_100:
V_83 = F_44 ( V_3 ) ;
goto V_28;
}
static void F_99 ( struct V_82 * V_83 )
{
struct V_84 * V_12 = F_75 ( V_83 ) ;
F_96 ( & V_12 -> V_16 ) ;
F_97 ( & V_12 -> V_14 ) ;
F_98 ( V_83 ) ;
}
static int T_2 F_100 ( void )
{
return F_101 ( & V_129 ) ;
}
static void T_3 F_102 ( void )
{
F_103 ( & V_129 ) ;
}
