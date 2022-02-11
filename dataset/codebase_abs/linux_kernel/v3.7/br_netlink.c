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
if ( F_10 ( V_5 , V_31 , V_15 -> V_21 ) ||
F_11 ( V_5 , V_32 , V_13 -> V_15 -> V_28 ) ||
F_11 ( V_5 , V_33 , V_15 -> V_34 ) ||
F_12 ( V_5 , V_35 , V_19 ) ||
( V_15 -> V_36 &&
F_13 ( V_5 , V_37 , V_15 -> V_36 , V_15 -> V_38 ) ) ||
( V_15 -> V_28 != V_15 -> V_39 &&
F_11 ( V_5 , V_40 , V_15 -> V_39 ) ) ||
( V_10 == V_41 &&
F_12 ( V_5 , V_42 , V_7 -> V_43 ) ) )
goto V_44;
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
( unsigned int ) V_7 -> V_48 , V_7 -> V_15 -> V_21 , V_10 ) ;
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
F_28 ( V_53 -> V_5 ) . V_57 ,
V_53 -> V_18 -> V_58 , V_41 ,
V_59 ) < 0 )
break;
V_56:
++ V_55 ;
}
F_29 () ;
V_53 -> args [ 0 ] = V_55 ;
return V_5 -> V_60 ;
}
static int F_30 ( struct V_4 * V_5 , struct V_17 * V_18 , void * V_61 )
{
struct V_45 * V_45 = F_24 ( V_5 -> V_54 ) ;
struct V_1 * V_62 ;
struct V_63 * V_64 ;
struct V_14 * V_15 ;
struct V_6 * V_65 ;
T_3 V_66 ;
if ( F_31 ( V_18 ) < sizeof( * V_62 ) )
return - V_67 ;
V_62 = F_8 ( V_18 ) ;
if ( V_62 -> V_23 != V_24 )
return - V_68 ;
V_64 = F_32 ( V_18 , sizeof( * V_62 ) , V_42 ) ;
if ( ! V_64 || F_33 ( V_64 ) < sizeof( T_3 ) )
return - V_67 ;
V_66 = F_34 ( V_64 ) ;
if ( V_66 > V_69 )
return - V_67 ;
V_15 = F_35 ( V_45 , V_62 -> V_27 ) ;
if ( ! V_15 )
return - V_70 ;
V_65 = F_36 ( V_15 ) ;
if ( ! V_65 )
return - V_67 ;
if ( V_65 -> V_13 -> V_71 == V_72 )
return - V_73 ;
if ( ! F_5 ( V_15 ) ||
( ! F_37 ( V_15 ) && V_66 != V_74 ) )
return - V_75 ;
V_65 -> V_43 = V_66 ;
F_38 ( V_65 ) ;
F_39 ( & V_65 -> V_13 -> V_76 ) ;
F_40 ( V_65 -> V_13 ) ;
F_41 ( & V_65 -> V_13 -> V_76 ) ;
F_16 ( V_41 , V_65 ) ;
return 0 ;
}
static int F_42 ( struct V_63 * V_77 [] , struct V_63 * V_78 [] )
{
if ( V_77 [ V_37 ] ) {
if ( F_33 ( V_77 [ V_37 ] ) != V_79 )
return - V_67 ;
if ( ! F_43 ( F_44 ( V_77 [ V_37 ] ) ) )
return - V_80 ;
}
return 0 ;
}
int T_4 F_45 ( void )
{
int V_46 ;
V_46 = F_46 ( & V_81 ) ;
if ( V_46 < 0 )
goto V_82;
V_46 = F_47 ( V_83 , V_84 , NULL ,
F_23 , NULL ) ;
if ( V_46 )
goto V_85;
V_46 = F_47 ( V_83 , V_86 ,
F_30 , NULL , NULL ) ;
if ( V_46 )
goto V_87;
return 0 ;
V_87:
F_48 ( V_83 ) ;
V_85:
F_49 ( & V_81 ) ;
V_82:
return V_46 ;
}
void T_5 F_50 ( void )
{
F_49 ( & V_81 ) ;
F_48 ( V_83 ) ;
}
