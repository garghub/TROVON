static inline T_1 F_1 ( void )
{
return F_2 ( sizeof( struct V_1 ) )
+ F_3 ( V_2 )
+ F_3 ( V_3 )
+ F_3 ( 4 )
+ F_3 ( 4 )
+ F_3 ( 4 )
+ F_3 ( 1 )
+ F_3 ( 1 ) ;
}
static int F_4 ( struct V_4 * V_5 , const struct V_6 * V_7 ,
T_2 V_8 , T_2 V_9 , int V_10 , unsigned int V_11 )
{
const struct V_12 * V_13 = V_7 -> V_13 ;
const struct V_14 * V_15 = V_7 -> V_15 ;
struct V_1 * V_16 ;
struct V_17 * V_18 ;
T_3 V_19 = F_5 ( V_15 ) ? V_15 -> V_19 : V_20 ;
F_6 ( V_13 , L_1 ,
V_10 , V_15 -> V_21 , V_13 -> V_15 -> V_21 ) ;
V_18 = F_7 ( V_5 , V_8 , V_9 , V_10 , sizeof( * V_16 ) , V_11 ) ;
if ( V_18 == NULL )
return - V_22 ;
V_16 = F_8 ( V_18 ) ;
V_16 -> V_23 = V_24 ;
V_16 -> V_25 = 0 ;
V_16 -> V_26 = V_15 -> type ;
V_16 -> V_27 = V_15 -> V_28 ;
V_16 -> V_29 = F_9 ( V_15 ) ;
V_16 -> V_30 = 0 ;
F_10 ( V_5 , V_31 , V_15 -> V_21 ) ;
F_11 ( V_5 , V_32 , V_13 -> V_15 -> V_28 ) ;
F_11 ( V_5 , V_33 , V_15 -> V_34 ) ;
F_12 ( V_5 , V_35 , V_19 ) ;
if ( V_15 -> V_36 )
F_13 ( V_5 , V_37 , V_15 -> V_36 , V_15 -> V_38 ) ;
if ( V_15 -> V_28 != V_15 -> V_39 )
F_11 ( V_5 , V_40 , V_15 -> V_39 ) ;
if ( V_10 == V_41 )
F_12 ( V_5 , V_42 , V_7 -> V_43 ) ;
return F_14 ( V_5 , V_18 ) ;
V_44:
F_15 ( V_5 , V_18 ) ;
return - V_22 ;
}
void F_16 ( int V_10 , struct V_6 * V_7 )
{
struct V_45 * V_45 = F_17 ( V_7 -> V_15 ) ;
struct V_4 * V_5 ;
int V_46 = - V_47 ;
F_6 ( V_7 -> V_13 , L_2 ,
( unsigned ) V_7 -> V_48 , V_7 -> V_15 -> V_21 , V_10 ) ;
V_5 = F_18 ( F_1 () , V_49 ) ;
if ( V_5 == NULL )
goto V_50;
V_46 = F_4 ( V_5 , V_7 , 0 , 0 , V_10 , 0 ) ;
if ( V_46 < 0 ) {
F_19 ( V_46 == - V_22 ) ;
F_20 ( V_5 ) ;
goto V_50;
}
F_21 ( V_5 , V_45 , 0 , V_51 , NULL , V_49 ) ;
return;
V_50:
if ( V_46 < 0 )
F_22 ( V_45 , V_51 , V_46 ) ;
}
static int F_23 ( struct V_4 * V_5 , struct V_52 * V_53 )
{
struct V_45 * V_45 = F_24 ( V_5 -> V_54 ) ;
struct V_14 * V_15 ;
int V_55 ;
V_55 = 0 ;
F_25 () ;
F_26 (net, dev) {
struct V_6 * V_7 = F_27 ( V_15 ) ;
if ( ! V_7 || V_55 < V_53 -> args [ 0 ] )
goto V_56;
if ( F_4 ( V_5 , V_7 ,
F_28 ( V_53 -> V_5 ) . V_8 ,
V_53 -> V_18 -> V_57 , V_41 ,
V_58 ) < 0 )
break;
V_56:
++ V_55 ;
}
F_29 () ;
V_53 -> args [ 0 ] = V_55 ;
return V_5 -> V_59 ;
}
static int F_30 ( struct V_4 * V_5 , struct V_17 * V_18 , void * V_60 )
{
struct V_45 * V_45 = F_24 ( V_5 -> V_54 ) ;
struct V_1 * V_61 ;
struct V_62 * V_63 ;
struct V_14 * V_15 ;
struct V_6 * V_64 ;
T_3 V_65 ;
if ( F_31 ( V_18 ) < sizeof( * V_61 ) )
return - V_66 ;
V_61 = F_8 ( V_18 ) ;
if ( V_61 -> V_23 != V_24 )
return - V_67 ;
V_63 = F_32 ( V_18 , sizeof( * V_61 ) , V_42 ) ;
if ( ! V_63 || F_33 ( V_63 ) < sizeof( T_3 ) )
return - V_66 ;
V_65 = F_34 ( V_63 ) ;
if ( V_65 > V_68 )
return - V_66 ;
V_15 = F_35 ( V_45 , V_61 -> V_27 ) ;
if ( ! V_15 )
return - V_69 ;
V_64 = F_36 ( V_15 ) ;
if ( ! V_64 )
return - V_66 ;
if ( V_64 -> V_13 -> V_70 == V_71 )
return - V_72 ;
if ( ! F_5 ( V_15 ) ||
( ! F_37 ( V_15 ) && V_65 != V_73 ) )
return - V_74 ;
V_64 -> V_43 = V_65 ;
F_38 ( V_64 ) ;
return 0 ;
}
static int F_39 ( struct V_62 * V_75 [] , struct V_62 * V_76 [] )
{
if ( V_75 [ V_37 ] ) {
if ( F_33 ( V_75 [ V_37 ] ) != V_77 )
return - V_66 ;
if ( ! F_40 ( F_41 ( V_75 [ V_37 ] ) ) )
return - V_78 ;
}
return 0 ;
}
int T_4 F_42 ( void )
{
int V_46 ;
V_46 = F_43 ( & V_79 ) ;
if ( V_46 < 0 )
goto V_80;
V_46 = F_44 ( V_81 , V_82 , NULL , F_23 ) ;
if ( V_46 )
goto V_83;
V_46 = F_44 ( V_81 , V_84 , F_30 , NULL ) ;
if ( V_46 )
goto V_85;
V_46 = F_44 ( V_81 , V_86 , V_87 , NULL ) ;
if ( V_46 )
goto V_85;
V_46 = F_44 ( V_81 , V_88 , V_89 , NULL ) ;
if ( V_46 )
goto V_85;
V_46 = F_44 ( V_81 , V_90 , NULL , V_91 ) ;
if ( V_46 )
goto V_85;
return 0 ;
V_85:
F_45 ( V_81 ) ;
V_83:
F_46 ( & V_79 ) ;
V_80:
return V_46 ;
}
void T_5 F_47 ( void )
{
F_46 ( & V_79 ) ;
F_45 ( V_81 ) ;
}
