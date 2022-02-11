void F_1 ( int V_1 , struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
int V_7 = - V_8 ;
V_6 = F_2 ( F_3 ( sizeof( struct V_9 ) ) +
F_4 ( 1 ) , V_10 ) ;
if ( V_6 == NULL )
goto V_11;
V_7 = F_5 ( V_6 , V_3 , V_4 , 0 , 0 , V_1 ) ;
if ( V_7 < 0 ) {
F_6 ( V_7 == - V_12 ) ;
F_7 ( V_6 ) ;
goto V_11;
}
F_8 ( V_6 , F_9 ( V_3 ) , 0 ,
V_13 , NULL , V_10 ) ;
return;
V_11:
F_10 ( F_9 ( V_3 ) , V_13 , V_7 ) ;
}
static int F_11 ( struct V_5 * V_6 , struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_18 = F_12 ( V_6 -> V_19 ) ;
struct V_20 * V_21 [ V_22 + 1 ] ;
struct V_2 * V_3 ;
struct V_9 * V_23 ;
int V_7 ;
T_1 V_24 ;
if ( ! F_13 ( V_6 , V_25 ) )
return - V_26 ;
if ( ! F_13 ( V_6 , V_27 ) )
return - V_26 ;
F_14 () ;
V_7 = F_15 ( V_15 , sizeof( * V_23 ) , V_21 , V_22 , V_28 ,
V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 = F_16 ( V_15 ) ;
if ( V_21 [ V_29 ] == NULL )
return - V_30 ;
V_24 = F_17 ( V_21 [ V_29 ] ) ;
if ( V_24 & 3 )
return - V_30 ;
V_3 = F_18 ( V_18 , V_23 -> V_31 ) ;
if ( V_3 == NULL )
return - V_32 ;
if ( V_15 -> V_33 == V_34 )
V_7 = F_19 ( V_3 , V_24 ) ;
else
V_7 = F_20 ( V_3 , V_24 ) ;
if ( ! V_7 )
F_1 ( V_15 -> V_33 , V_3 , V_24 ) ;
return V_7 ;
}
static int F_5 ( struct V_5 * V_6 , struct V_2 * V_3 , T_1 V_4 ,
T_2 V_35 , T_2 V_36 , int V_1 )
{
struct V_9 * V_23 ;
struct V_14 * V_15 ;
V_15 = F_21 ( V_6 , V_35 , V_36 , V_1 , sizeof( * V_23 ) , 0 ) ;
if ( V_15 == NULL )
return - V_12 ;
V_23 = F_16 ( V_15 ) ;
V_23 -> V_37 = V_38 ;
V_23 -> V_39 = 0 ;
V_23 -> V_40 = V_41 ;
V_23 -> V_42 = V_43 ;
V_23 -> V_31 = V_3 -> V_44 ;
if ( F_22 ( V_6 , V_29 , V_4 ) )
goto V_45;
F_23 ( V_6 , V_15 ) ;
return 0 ;
V_45:
F_24 ( V_6 , V_15 ) ;
return - V_12 ;
}
static int F_25 ( struct V_5 * V_6 , struct V_46 * V_47 )
{
struct V_48 * V_49 ;
struct V_50 * V_51 ;
int V_52 = 0 , V_53 = V_47 -> args [ 0 ] ;
int V_54 = 0 , V_55 = V_47 -> args [ 1 ] ;
V_49 = V_48 ( F_12 ( V_6 -> V_19 ) ) ;
F_26 () ;
F_27 (pnd, &pndevs->list, list) {
T_1 V_4 ;
if ( V_52 > V_53 )
V_55 = 0 ;
if ( V_52 ++ < V_53 )
continue;
V_54 = 0 ;
F_28 (addr, pnd->addrs, 64 ) {
if ( V_54 ++ < V_55 )
continue;
if ( F_5 ( V_6 , V_51 -> V_56 , V_4 << 2 ,
F_29 ( V_47 -> V_6 ) . V_35 ,
V_47 -> V_15 -> V_57 , V_34 ) < 0 )
goto V_58;
}
}
V_58:
F_30 () ;
V_47 -> args [ 0 ] = V_52 ;
V_47 -> args [ 1 ] = V_54 ;
return V_6 -> V_59 ;
}
static int F_31 ( struct V_5 * V_6 , struct V_2 * V_3 , T_1 V_60 ,
T_2 V_35 , T_2 V_36 , int V_1 )
{
struct V_61 * V_62 ;
struct V_14 * V_15 ;
V_15 = F_21 ( V_6 , V_35 , V_36 , V_1 , sizeof( * V_62 ) , 0 ) ;
if ( V_15 == NULL )
return - V_12 ;
V_62 = F_16 ( V_15 ) ;
V_62 -> V_63 = V_38 ;
V_62 -> V_64 = 6 ;
V_62 -> V_65 = 0 ;
V_62 -> V_66 = 0 ;
V_62 -> V_67 = V_68 ;
V_62 -> V_69 = V_70 ;
V_62 -> V_71 = V_72 ;
V_62 -> V_73 = V_74 ;
V_62 -> V_75 = 0 ;
if ( F_22 ( V_6 , V_76 , V_60 ) ||
F_32 ( V_6 , V_77 , V_3 -> V_44 ) )
goto V_45;
F_23 ( V_6 , V_15 ) ;
return 0 ;
V_45:
F_24 ( V_6 , V_15 ) ;
return - V_12 ;
}
void F_33 ( int V_1 , struct V_2 * V_3 , T_1 V_60 )
{
struct V_5 * V_6 ;
int V_7 = - V_8 ;
V_6 = F_2 ( F_3 ( sizeof( struct V_9 ) ) +
F_4 ( 1 ) + F_4 ( 4 ) , V_10 ) ;
if ( V_6 == NULL )
goto V_11;
V_7 = F_31 ( V_6 , V_3 , V_60 , 0 , 0 , V_1 ) ;
if ( V_7 < 0 ) {
F_6 ( V_7 == - V_12 ) ;
F_7 ( V_6 ) ;
goto V_11;
}
F_8 ( V_6 , F_9 ( V_3 ) , 0 ,
V_78 , NULL , V_10 ) ;
return;
V_11:
F_10 ( F_9 ( V_3 ) , V_78 , V_7 ) ;
}
static int F_34 ( struct V_5 * V_6 , struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_18 = F_12 ( V_6 -> V_19 ) ;
struct V_20 * V_21 [ V_79 + 1 ] ;
struct V_2 * V_3 ;
struct V_61 * V_62 ;
int V_7 ;
T_1 V_60 ;
if ( ! F_13 ( V_6 , V_25 ) )
return - V_26 ;
if ( ! F_13 ( V_6 , V_27 ) )
return - V_26 ;
F_14 () ;
V_7 = F_15 ( V_15 , sizeof( * V_62 ) , V_21 , V_79 , V_80 ,
V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
V_62 = F_16 ( V_15 ) ;
if ( V_62 -> V_67 != V_68 || V_62 -> V_73 != V_74 )
return - V_30 ;
if ( V_21 [ V_76 ] == NULL || V_21 [ V_77 ] == NULL )
return - V_30 ;
V_60 = F_17 ( V_21 [ V_76 ] ) ;
if ( V_60 & 3 )
return - V_30 ;
V_3 = F_18 ( V_18 , F_35 ( V_21 [ V_77 ] ) ) ;
if ( V_3 == NULL )
return - V_32 ;
if ( V_15 -> V_33 == V_81 )
V_7 = F_36 ( V_3 , V_60 ) ;
else
V_7 = F_37 ( V_3 , V_60 ) ;
if ( ! V_7 )
F_33 ( V_15 -> V_33 , V_3 , V_60 ) ;
return V_7 ;
}
static int F_38 ( struct V_5 * V_6 , struct V_46 * V_47 )
{
struct V_18 * V_18 = F_12 ( V_6 -> V_19 ) ;
T_1 V_4 ;
F_26 () ;
for ( V_4 = V_47 -> args [ 0 ] ; V_4 < 64 ; V_4 ++ ) {
struct V_2 * V_3 = F_39 ( V_18 , V_4 << 2 ) ;
if ( ! V_3 )
continue;
if ( F_31 ( V_6 , V_3 , V_4 << 2 , F_29 ( V_47 -> V_6 ) . V_35 ,
V_47 -> V_15 -> V_57 , V_81 ) < 0 )
goto V_58;
}
V_58:
F_30 () ;
V_47 -> args [ 0 ] = V_4 ;
return V_6 -> V_59 ;
}
int T_3 F_40 ( void )
{
int V_7 = F_41 ( V_82 , V_34 , F_11 ,
NULL , 0 ) ;
if ( V_7 )
return V_7 ;
F_41 ( V_82 , V_83 , F_11 , NULL , 0 ) ;
F_41 ( V_82 , V_84 , NULL , F_25 , 0 ) ;
F_41 ( V_82 , V_81 , F_34 , NULL , 0 ) ;
F_41 ( V_82 , V_85 , F_34 , NULL , 0 ) ;
F_41 ( V_82 , V_86 , NULL , F_38 , 0 ) ;
return 0 ;
}
