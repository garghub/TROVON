static void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 != - V_4 )
F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_5 * V_6 , const T_1 * V_7 ,
unsigned int V_8 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 = V_10 -> V_14 ;
struct V_15 V_16 ;
int V_3 = - V_17 ;
if ( F_5 ( & V_16 , V_7 , V_8 ) != 0 )
goto V_18;
F_6 ( V_12 , V_19 ) ;
F_7 ( V_12 , F_8 ( V_6 ) &
V_19 ) ;
V_3 = F_9 ( V_12 , V_16 . V_20 , V_16 . V_21 ) ;
F_10 ( V_6 , F_11 ( V_12 ) &
V_22 ) ;
if ( V_3 )
goto V_23;
F_12 ( V_14 , V_19 ) ;
F_13 ( V_14 , F_8 ( V_6 ) &
V_19 ) ;
V_3 = F_14 ( V_14 , V_16 . V_24 , V_16 . V_25 ) ;
F_10 ( V_6 , F_15 ( V_14 ) &
V_22 ) ;
V_23:
return V_3 ;
V_18:
F_10 ( V_6 , V_26 ) ;
goto V_23;
}
static void F_16 ( struct V_27 * V_28 ,
int V_3 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
struct V_5 * V_6 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = ( void * ) ( V_31 -> V_34 + V_10 -> V_35 ) ;
if ( V_3 )
goto V_23;
F_19 ( V_33 , V_31 -> V_36 , V_33 -> V_37 ,
V_31 -> V_38 ) ;
F_20 ( V_33 , F_21 ( V_2 ) &
V_39 ,
V_31 -> V_40 , V_2 ) ;
V_3 = F_22 ( V_33 ) ;
if ( V_3 )
goto V_23;
F_19 ( V_33 , V_31 -> V_41 , V_33 -> V_37 ,
V_31 -> V_42 ) ;
F_20 ( V_33 , F_21 ( V_2 ) &
V_39 ,
V_31 -> V_43 , V_2 ) ;
V_3 = F_23 ( V_33 ) ;
if ( V_3 )
goto V_23;
F_24 ( V_33 -> V_37 , V_31 -> V_36 ,
V_31 -> V_38 ,
F_25 ( V_6 ) , 1 ) ;
V_23:
F_1 ( V_2 , V_3 ) ;
}
static void F_26 ( struct V_27 * V_28 ,
int V_3 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
struct V_5 * V_6 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = ( void * ) ( V_31 -> V_34 + V_10 -> V_35 ) ;
if ( V_3 )
goto V_23;
F_19 ( V_33 , V_31 -> V_41 , V_33 -> V_37 ,
V_31 -> V_42 ) ;
F_20 ( V_33 , F_21 ( V_2 ) &
V_39 ,
V_31 -> V_43 , V_2 ) ;
V_3 = F_23 ( V_33 ) ;
if ( V_3 )
goto V_23;
F_24 ( V_33 -> V_37 , V_31 -> V_36 ,
V_31 -> V_38 ,
F_25 ( V_6 ) , 1 ) ;
V_23:
F_1 ( V_2 , V_3 ) ;
}
static void F_27 ( struct V_27 * V_28 ,
int V_3 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
struct V_5 * V_6 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = ( void * ) ( V_31 -> V_34 + V_10 -> V_35 ) ;
if ( V_3 )
goto V_23;
F_24 ( V_33 -> V_37 , V_31 -> V_36 ,
V_31 -> V_38 ,
F_25 ( V_6 ) , 1 ) ;
V_23:
F_2 ( V_2 , V_3 ) ;
}
static void F_28 ( struct V_27 * V_28 ,
int V_3 )
{
T_1 * V_44 ;
unsigned int V_45 ;
struct V_46 * V_47 ;
struct V_1 * V_2 = V_28 -> V_29 ;
struct V_5 * V_6 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = ( void * ) ( V_31 -> V_34 + V_10 -> V_35 ) ;
unsigned int V_38 = V_2 -> V_38 ;
if ( V_3 )
goto V_23;
F_19 ( V_33 , V_31 -> V_36 , V_33 -> V_37 ,
V_31 -> V_38 ) ;
F_20 ( V_33 ,
F_21 ( V_2 ) &
V_39 ,
V_31 -> V_40 , V_2 ) ;
V_3 = F_22 ( V_33 ) ;
if ( V_3 )
goto V_23;
F_19 ( V_33 , V_31 -> V_41 , V_33 -> V_37 ,
V_31 -> V_42 ) ;
F_20 ( V_33 , F_21 ( V_2 ) &
V_39 ,
V_31 -> V_43 , V_2 ) ;
V_3 = F_23 ( V_33 ) ;
if ( V_3 )
goto V_23;
V_45 = F_25 ( V_6 ) ;
V_38 -= V_45 ;
V_44 = V_33 -> V_37 + V_45 ;
F_24 ( V_44 , V_31 -> V_36 , V_31 -> V_38 ,
V_45 , 0 ) ;
V_3 = F_29 ( V_44 , V_33 -> V_37 , V_45 ) ? - V_48 : 0 ;
if ( V_3 )
goto V_23;
V_47 = F_18 ( V_2 ) ;
F_30 ( V_47 , V_10 -> V_14 ) ;
F_31 ( V_47 , F_21 ( V_2 ) ,
V_2 -> V_49 . V_43 , V_2 -> V_49 . V_29 ) ;
F_32 ( V_47 , V_2 -> V_50 , V_2 -> V_51 ,
V_38 , V_2 -> V_52 ) ;
V_3 = F_33 ( V_47 ) ;
V_23:
F_1 ( V_2 , V_3 ) ;
}
static void F_34 ( struct V_27 * V_28 ,
int V_3 )
{
T_1 * V_44 ;
unsigned int V_45 ;
struct V_46 * V_47 ;
struct V_1 * V_2 = V_28 -> V_29 ;
struct V_5 * V_6 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = ( void * ) ( V_31 -> V_34 + V_10 -> V_35 ) ;
unsigned int V_38 = V_2 -> V_38 ;
if ( V_3 )
goto V_23;
F_19 ( V_33 , V_31 -> V_41 , V_33 -> V_37 ,
V_31 -> V_42 ) ;
F_20 ( V_33 , F_21 ( V_2 ) &
V_39 ,
V_31 -> V_43 , V_2 ) ;
V_3 = F_23 ( V_33 ) ;
if ( V_3 )
goto V_23;
V_45 = F_25 ( V_6 ) ;
V_38 -= V_45 ;
V_44 = V_33 -> V_37 + V_45 ;
F_24 ( V_44 , V_31 -> V_36 , V_31 -> V_38 ,
V_45 , 0 ) ;
V_3 = F_29 ( V_44 , V_33 -> V_37 , V_45 ) ? - V_48 : 0 ;
if ( V_3 )
goto V_23;
V_47 = F_18 ( V_2 ) ;
F_30 ( V_47 , V_10 -> V_14 ) ;
F_31 ( V_47 , F_21 ( V_2 ) ,
V_2 -> V_49 . V_43 , V_2 -> V_49 . V_29 ) ;
F_32 ( V_47 , V_2 -> V_50 , V_2 -> V_51 ,
V_38 , V_2 -> V_52 ) ;
V_3 = F_33 ( V_47 ) ;
V_23:
F_1 ( V_2 , V_3 ) ;
}
static void F_35 ( struct V_27 * V_28 ,
int V_3 )
{
T_1 * V_44 ;
unsigned int V_45 ;
struct V_46 * V_47 ;
struct V_1 * V_2 = V_28 -> V_29 ;
struct V_5 * V_6 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = ( void * ) ( V_31 -> V_34 + V_10 -> V_35 ) ;
unsigned int V_38 = V_2 -> V_38 ;
if ( V_3 )
goto V_23;
V_45 = F_25 ( V_6 ) ;
V_38 -= V_45 ;
V_44 = V_33 -> V_37 + V_45 ;
F_24 ( V_44 , V_31 -> V_36 , V_31 -> V_38 ,
V_45 , 0 ) ;
V_3 = F_29 ( V_44 , V_33 -> V_37 , V_45 ) ? - V_48 : 0 ;
if ( V_3 )
goto V_23;
V_47 = F_18 ( V_2 ) ;
F_30 ( V_47 , V_10 -> V_14 ) ;
F_31 ( V_47 , F_21 ( V_2 ) ,
V_2 -> V_49 . V_43 , V_2 -> V_49 . V_29 ) ;
F_32 ( V_47 , V_2 -> V_50 , V_2 -> V_51 ,
V_38 , V_2 -> V_52 ) ;
V_3 = F_33 ( V_47 ) ;
V_23:
F_1 ( V_2 , V_3 ) ;
}
static T_1 * F_36 ( struct V_1 * V_2 ,
unsigned int V_53 )
{
struct V_5 * V_6 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_32 * V_33 = ( void * ) ( V_31 -> V_34 + V_10 -> V_35 ) ;
T_1 * V_54 = V_31 -> V_34 ;
int V_3 ;
V_54 = ( T_1 * ) F_37 ( ( unsigned long ) V_54 + F_38 ( V_12 ) ,
F_38 ( V_12 ) + 1 ) ;
F_39 ( V_33 , V_12 ) ;
V_3 = F_40 ( V_33 ) ;
if ( V_3 )
return F_41 ( V_3 ) ;
F_19 ( V_33 , V_31 -> V_55 , V_54 , V_31 -> V_56 ) ;
F_20 ( V_33 , F_21 ( V_2 ) & V_53 ,
V_31 -> V_57 , V_2 ) ;
V_3 = F_22 ( V_33 ) ;
if ( V_3 )
return F_41 ( V_3 ) ;
F_19 ( V_33 , V_31 -> V_36 , V_54 , V_31 -> V_38 ) ;
F_20 ( V_33 , F_21 ( V_2 ) & V_53 ,
V_31 -> V_40 , V_2 ) ;
V_3 = F_22 ( V_33 ) ;
if ( V_3 )
return F_41 ( V_3 ) ;
F_19 ( V_33 , V_31 -> V_41 , V_54 ,
V_31 -> V_42 ) ;
F_20 ( V_33 , F_21 ( V_2 ) & V_53 ,
V_31 -> V_43 , V_2 ) ;
V_3 = F_23 ( V_33 ) ;
if ( V_3 )
return F_41 ( V_3 ) ;
return V_54 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 * V_52 ,
unsigned int V_53 )
{
struct V_5 * V_6 = F_17 ( V_2 ) ;
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_58 * V_51 = V_2 -> V_51 ;
struct V_58 * V_59 = V_2 -> V_59 ;
struct V_58 * V_60 = V_31 -> V_60 ;
struct V_58 * V_55 = V_31 -> V_55 ;
struct V_58 * V_41 = V_31 -> V_41 ;
struct V_58 * V_61 ;
struct V_58 * V_62 ;
unsigned int V_63 = F_43 ( V_6 ) ;
unsigned int V_38 = V_2 -> V_38 ;
struct V_64 * V_65 ;
T_1 * V_66 ;
T_1 * V_54 ;
V_65 = F_44 ( V_51 ) ;
V_66 = F_45 ( V_65 ) ? NULL : F_46 ( V_65 ) + V_51 -> V_67 ;
if ( V_63 ) {
F_47 ( V_60 , 2 ) ;
F_48 ( V_60 , V_52 , V_63 ) ;
F_49 ( V_60 , V_51 , V_66 == V_52 + V_63 , 2 ) ;
V_51 = V_60 ;
V_38 += V_63 ;
}
if ( F_50 ( V_59 ) )
return - V_17 ;
V_61 = V_59 + 1 ;
if ( F_50 ( V_61 ) )
return - V_17 ;
V_62 = V_59 + 2 ;
if ( ! F_50 ( V_62 ) )
return - V_17 ;
F_47 ( V_55 , 2 ) ;
F_51 ( V_55 , F_44 ( V_59 ) , V_59 -> V_68 , V_59 -> V_67 ) ;
F_51 ( V_55 + 1 , F_44 ( V_62 ) , V_62 -> V_68 , V_62 -> V_67 ) ;
F_47 ( V_41 , 1 ) ;
F_51 ( V_41 , F_44 ( V_61 ) , V_61 -> V_68 , V_61 -> V_67 ) ;
V_31 -> V_38 = V_38 ;
V_31 -> V_56 = V_59 -> V_68 + V_62 -> V_68 ;
V_31 -> V_42 = V_61 -> V_68 ;
V_31 -> V_36 = V_51 ;
V_31 -> V_43 = F_27 ;
V_31 -> V_57 = F_16 ;
V_31 -> V_40 = F_26 ;
V_54 = F_36 ( V_2 , V_53 ) ;
if ( F_52 ( V_54 ) )
return F_53 ( V_54 ) ;
F_24 ( V_54 , V_51 , V_38 ,
F_25 ( V_6 ) , 1 ) ;
return 0 ;
}
static void F_54 ( struct V_27 * V_2 ,
int V_3 )
{
struct V_1 * V_28 = V_2 -> V_29 ;
if ( ! V_3 ) {
struct V_5 * V_6 = F_17 ( V_28 ) ;
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_46 * V_47 = F_18 ( V_28 ) ;
T_1 * V_52 = ( T_1 * ) ( V_47 + 1 ) +
F_55 ( V_10 -> V_14 ) ;
V_3 = F_42 ( V_28 , V_52 , 0 ) ;
}
F_1 ( V_28 , V_3 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_13 * V_14 = V_10 -> V_14 ;
struct V_58 * V_51 = V_2 -> V_51 ;
unsigned int V_38 = V_2 -> V_38 ;
struct V_46 * V_47 = ( void * ) ( V_31 -> V_34
+ V_10 -> V_35 ) ;
T_1 * V_52 = ( T_1 * ) V_47 - F_57 ( V_14 ) ;
int V_3 ;
F_30 ( V_47 , V_14 ) ;
F_31 ( V_47 , F_21 ( V_2 ) ,
F_54 , V_2 ) ;
F_32 ( V_47 , V_2 -> V_50 , V_51 , V_38 , V_2 -> V_52 ) ;
memcpy ( V_52 , V_2 -> V_52 , F_43 ( V_6 ) ) ;
V_3 = F_58 ( V_47 ) ;
if ( V_3 )
return V_3 ;
return F_42 ( V_2 , V_52 , V_39 ) ;
}
static void F_59 ( struct V_27 * V_2 ,
int V_3 )
{
struct V_1 * V_28 = V_2 -> V_29 ;
if ( ! V_3 ) {
struct V_69 * V_70 = F_18 ( V_28 ) ;
V_3 = F_42 ( V_28 , V_70 -> V_71 , 0 ) ;
}
F_1 ( V_28 , V_3 ) ;
}
static int F_60 ( struct V_72 * V_2 )
{
struct V_5 * V_6 = F_61 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_28 = & V_2 -> V_28 ;
struct V_69 * V_70 = F_18 ( V_28 ) ;
T_1 * V_52 = V_2 -> V_71 ;
int V_3 ;
F_62 ( V_70 , V_10 -> V_14 ) ;
F_63 ( V_70 , F_21 ( V_28 ) ,
F_59 , V_28 ) ;
F_64 ( V_70 , V_28 -> V_50 , V_28 -> V_51 , V_28 -> V_38 ,
V_28 -> V_52 ) ;
F_65 ( V_70 , V_52 , V_2 -> V_73 ) ;
V_3 = F_66 ( V_70 ) ;
if ( V_3 )
return V_3 ;
return F_42 ( V_28 , V_52 , V_39 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_17 ( V_2 ) ;
struct V_30 * V_31 = F_18 ( V_2 ) ;
T_1 * V_74 ;
T_1 * V_44 ;
unsigned int V_45 ;
V_31 -> V_43 = F_35 ;
V_31 -> V_57 = F_28 ;
V_74 = F_36 ( V_2 , V_39 ) ;
if ( F_52 ( V_74 ) )
return F_53 ( V_74 ) ;
V_45 = F_25 ( V_6 ) ;
V_44 = V_74 + V_45 ;
F_24 ( V_44 , V_31 -> V_36 , V_31 -> V_38 ,
V_45 , 0 ) ;
return F_29 ( V_44 , V_74 , V_45 ) ? - V_48 : 0 ;
}
static int F_68 ( struct V_1 * V_2 , T_1 * V_52 ,
unsigned int V_38 )
{
struct V_5 * V_6 = F_17 ( V_2 ) ;
struct V_30 * V_31 = F_18 ( V_2 ) ;
struct V_58 * V_50 = V_2 -> V_50 ;
struct V_58 * V_59 = V_2 -> V_59 ;
struct V_58 * V_60 = V_31 -> V_60 ;
struct V_58 * V_55 = V_31 -> V_55 ;
struct V_58 * V_41 = V_31 -> V_41 ;
struct V_58 * V_61 ;
struct V_58 * V_62 ;
unsigned int V_63 = F_43 ( V_6 ) ;
struct V_64 * V_75 ;
T_1 * V_76 ;
V_75 = F_44 ( V_50 ) ;
V_76 = F_45 ( V_75 ) ? NULL : F_46 ( V_75 ) + V_50 -> V_67 ;
if ( V_63 ) {
F_47 ( V_60 , 2 ) ;
F_48 ( V_60 , V_52 , V_63 ) ;
F_49 ( V_60 , V_50 , V_76 == V_52 + V_63 , 2 ) ;
V_50 = V_60 ;
V_38 += V_63 ;
}
if ( F_50 ( V_59 ) )
return - V_17 ;
V_61 = V_59 + 1 ;
if ( F_50 ( V_61 ) )
return - V_17 ;
V_62 = V_59 + 2 ;
if ( ! F_50 ( V_62 ) )
return - V_17 ;
F_47 ( V_55 , 2 ) ;
F_51 ( V_55 , F_44 ( V_59 ) , V_59 -> V_68 , V_59 -> V_67 ) ;
F_51 ( V_55 + 1 , F_44 ( V_62 ) , V_62 -> V_68 , V_62 -> V_67 ) ;
F_47 ( V_41 , 1 ) ;
F_51 ( V_41 , F_44 ( V_61 ) , V_61 -> V_68 , V_61 -> V_67 ) ;
V_31 -> V_38 = V_38 ;
V_31 -> V_56 = V_59 -> V_68 + V_62 -> V_68 ;
V_31 -> V_42 = V_61 -> V_68 ;
V_31 -> V_36 = V_50 ;
V_31 -> V_43 = F_35 ;
V_31 -> V_57 = F_28 ;
V_31 -> V_40 = F_34 ;
return F_67 ( V_2 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_17 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_46 * V_47 = F_18 ( V_2 ) ;
unsigned int V_38 = V_2 -> V_38 ;
unsigned int V_45 = F_25 ( V_6 ) ;
T_1 * V_52 = V_2 -> V_52 ;
int V_3 ;
if ( V_38 < V_45 )
return - V_17 ;
V_38 -= V_45 ;
V_3 = F_68 ( V_2 , V_52 , V_38 ) ;
if ( V_3 )
return V_3 ;
F_30 ( V_47 , V_10 -> V_14 ) ;
F_31 ( V_47 , F_21 ( V_2 ) ,
V_2 -> V_49 . V_43 , V_2 -> V_49 . V_29 ) ;
F_32 ( V_47 , V_2 -> V_50 , V_2 -> V_51 , V_38 , V_52 ) ;
return F_33 ( V_47 ) ;
}
static int F_70 ( struct V_77 * V_78 )
{
struct V_79 * V_80 = F_71 ( V_78 ) ;
struct V_81 * V_82 = F_72 ( V_80 ) ;
struct V_9 * V_10 = F_73 ( V_78 ) ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_3 ;
V_12 = F_74 ( & V_82 -> V_12 ) ;
if ( F_52 ( V_12 ) )
return F_53 ( V_12 ) ;
V_14 = F_75 ( & V_82 -> V_14 ) ;
V_3 = F_53 ( V_14 ) ;
if ( F_52 ( V_14 ) )
goto V_83;
V_10 -> V_12 = V_12 ;
V_10 -> V_14 = V_14 ;
V_10 -> V_35 = F_37 ( 2 * F_76 ( V_12 ) +
F_38 ( V_12 ) ,
F_38 ( V_12 ) + 1 ) +
F_57 ( V_14 ) ;
V_78 -> V_84 . V_85 = sizeof( struct V_30 ) +
V_10 -> V_35 +
F_77 (unsigned int,
crypto_ahash_reqsize(auth) +
sizeof(struct ahash_request),
sizeof(struct skcipher_givcrypt_request) +
crypto_ablkcipher_reqsize(enc)) ;
return 0 ;
V_83:
F_78 ( V_12 ) ;
return V_3 ;
}
static void F_79 ( struct V_77 * V_78 )
{
struct V_9 * V_10 = F_73 ( V_78 ) ;
F_78 ( V_10 -> V_12 ) ;
F_80 ( V_10 -> V_14 ) ;
}
static struct V_79 * F_81 ( struct V_86 * * V_87 )
{
struct V_88 * V_89 ;
struct V_79 * V_80 ;
struct V_90 * V_12 ;
struct V_91 * V_92 ;
struct V_91 * V_14 ;
struct V_81 * V_10 ;
const char * V_93 ;
int V_3 ;
V_89 = F_82 ( V_87 ) ;
if ( F_52 ( V_89 ) )
return F_83 ( V_89 ) ;
if ( ( V_89 -> type ^ V_94 ) & V_89 -> V_95 )
return F_41 ( - V_17 ) ;
V_12 = F_84 ( V_87 [ 1 ] , V_96 ,
V_97 ) ;
if ( F_52 ( V_12 ) )
return F_83 ( V_12 ) ;
V_92 = & V_12 -> V_49 ;
V_93 = F_85 ( V_87 [ 2 ] ) ;
V_3 = F_53 ( V_93 ) ;
if ( F_52 ( V_93 ) )
goto V_98;
V_80 = F_86 ( sizeof( * V_80 ) + sizeof( * V_10 ) , V_99 ) ;
V_3 = - V_100 ;
if ( ! V_80 )
goto V_98;
V_10 = F_72 ( V_80 ) ;
V_3 = F_87 ( & V_10 -> V_12 , V_12 , V_80 ) ;
if ( V_3 )
goto V_101;
F_88 ( & V_10 -> V_14 , V_80 ) ;
V_3 = F_89 ( & V_10 -> V_14 , V_93 , 0 ,
F_90 ( V_89 -> type ,
V_89 -> V_95 ) ) ;
if ( V_3 )
goto V_102;
V_14 = F_91 ( & V_10 -> V_14 ) ;
V_3 = - V_103 ;
if ( snprintf ( V_80 -> V_104 . V_105 , V_106 ,
L_1 , V_92 -> V_105 , V_14 -> V_105 ) >=
V_106 )
goto V_107;
if ( snprintf ( V_80 -> V_104 . V_108 , V_106 ,
L_1 , V_92 -> V_108 ,
V_14 -> V_108 ) >= V_106 )
goto V_107;
V_80 -> V_104 . V_109 = V_94 ;
V_80 -> V_104 . V_109 |= V_14 -> V_109 & V_110 ;
V_80 -> V_104 . V_111 = V_14 -> V_111 *
10 + V_92 -> V_111 ;
V_80 -> V_104 . V_112 = V_14 -> V_112 ;
V_80 -> V_104 . V_113 = V_92 -> V_113 | V_14 -> V_113 ;
V_80 -> V_104 . V_114 = & V_115 ;
V_80 -> V_104 . V_116 . V_63 = V_14 -> V_117 . V_63 ;
V_80 -> V_104 . V_116 . V_118 = V_12 -> V_119 ;
V_80 -> V_104 . V_120 = sizeof( struct V_9 ) ;
V_80 -> V_104 . V_121 = F_70 ;
V_80 -> V_104 . V_122 = F_79 ;
V_80 -> V_104 . V_116 . V_123 = F_3 ;
V_80 -> V_104 . V_116 . V_124 = F_56 ;
V_80 -> V_104 . V_116 . V_125 = F_69 ;
V_80 -> V_104 . V_116 . V_126 = F_60 ;
V_23:
F_92 ( V_92 ) ;
return V_80 ;
V_107:
F_93 ( & V_10 -> V_14 ) ;
V_102:
F_94 ( & V_10 -> V_12 ) ;
V_101:
F_95 ( V_80 ) ;
V_98:
V_80 = F_41 ( V_3 ) ;
goto V_23;
}
static void F_96 ( struct V_79 * V_80 )
{
struct V_81 * V_10 = F_72 ( V_80 ) ;
F_93 ( & V_10 -> V_14 ) ;
F_94 ( & V_10 -> V_12 ) ;
F_95 ( V_80 ) ;
}
static int T_2 F_97 ( void )
{
return F_98 ( & V_127 ) ;
}
static void T_3 F_99 ( void )
{
F_100 ( & V_127 ) ;
}
