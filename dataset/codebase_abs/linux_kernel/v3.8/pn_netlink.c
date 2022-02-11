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
static int F_11 ( struct V_5 * V_6 , struct V_14 * V_15 , void * V_16 )
{
struct V_17 * V_17 = F_12 ( V_6 -> V_18 ) ;
struct V_19 * V_20 [ V_21 + 1 ] ;
struct V_2 * V_3 ;
struct V_9 * V_22 ;
int V_7 ;
T_1 V_23 ;
if ( ! F_13 ( V_24 ) )
return - V_25 ;
if ( ! F_13 ( V_26 ) )
return - V_25 ;
F_14 () ;
V_7 = F_15 ( V_15 , sizeof( * V_22 ) , V_20 , V_21 , V_27 ) ;
if ( V_7 < 0 )
return V_7 ;
V_22 = F_16 ( V_15 ) ;
if ( V_20 [ V_28 ] == NULL )
return - V_29 ;
V_23 = F_17 ( V_20 [ V_28 ] ) ;
if ( V_23 & 3 )
return - V_29 ;
V_3 = F_18 ( V_17 , V_22 -> V_30 ) ;
if ( V_3 == NULL )
return - V_31 ;
if ( V_15 -> V_32 == V_33 )
V_7 = F_19 ( V_3 , V_23 ) ;
else
V_7 = F_20 ( V_3 , V_23 ) ;
if ( ! V_7 )
F_1 ( V_15 -> V_32 , V_3 , V_23 ) ;
return V_7 ;
}
static int F_5 ( struct V_5 * V_6 , struct V_2 * V_3 , T_1 V_4 ,
T_2 V_34 , T_2 V_35 , int V_1 )
{
struct V_9 * V_22 ;
struct V_14 * V_15 ;
V_15 = F_21 ( V_6 , V_34 , V_35 , V_1 , sizeof( * V_22 ) , 0 ) ;
if ( V_15 == NULL )
return - V_12 ;
V_22 = F_16 ( V_15 ) ;
V_22 -> V_36 = V_37 ;
V_22 -> V_38 = 0 ;
V_22 -> V_39 = V_40 ;
V_22 -> V_41 = V_42 ;
V_22 -> V_30 = V_3 -> V_43 ;
if ( F_22 ( V_6 , V_28 , V_4 ) )
goto V_44;
return F_23 ( V_6 , V_15 ) ;
V_44:
F_24 ( V_6 , V_15 ) ;
return - V_12 ;
}
static int F_25 ( struct V_5 * V_6 , struct V_45 * V_46 )
{
struct V_47 * V_48 ;
struct V_49 * V_50 ;
int V_51 = 0 , V_52 = V_46 -> args [ 0 ] ;
int V_53 = 0 , V_54 = V_46 -> args [ 1 ] ;
V_48 = V_47 ( F_12 ( V_6 -> V_18 ) ) ;
F_26 () ;
F_27 (pnd, &pndevs->list, list) {
T_1 V_4 ;
if ( V_51 > V_52 )
V_54 = 0 ;
if ( V_51 ++ < V_52 )
continue;
V_53 = 0 ;
F_28 (addr, pnd->addrs, 64 ) {
if ( V_53 ++ < V_54 )
continue;
if ( F_5 ( V_6 , V_50 -> V_55 , V_4 << 2 ,
F_29 ( V_46 -> V_6 ) . V_34 ,
V_46 -> V_15 -> V_56 , V_33 ) < 0 )
goto V_57;
}
}
V_57:
F_30 () ;
V_46 -> args [ 0 ] = V_51 ;
V_46 -> args [ 1 ] = V_53 ;
return V_6 -> V_58 ;
}
static int F_31 ( struct V_5 * V_6 , struct V_2 * V_3 , T_1 V_59 ,
T_2 V_34 , T_2 V_35 , int V_1 )
{
struct V_60 * V_61 ;
struct V_14 * V_15 ;
V_15 = F_21 ( V_6 , V_34 , V_35 , V_1 , sizeof( * V_61 ) , 0 ) ;
if ( V_15 == NULL )
return - V_12 ;
V_61 = F_16 ( V_15 ) ;
V_61 -> V_62 = V_37 ;
V_61 -> V_63 = 6 ;
V_61 -> V_64 = 0 ;
V_61 -> V_65 = 0 ;
V_61 -> V_66 = V_67 ;
V_61 -> V_68 = V_69 ;
V_61 -> V_70 = V_71 ;
V_61 -> V_72 = V_73 ;
V_61 -> V_74 = 0 ;
if ( F_22 ( V_6 , V_75 , V_59 ) ||
F_32 ( V_6 , V_76 , V_3 -> V_43 ) )
goto V_44;
return F_23 ( V_6 , V_15 ) ;
V_44:
F_24 ( V_6 , V_15 ) ;
return - V_12 ;
}
void F_33 ( int V_1 , struct V_2 * V_3 , T_1 V_59 )
{
struct V_5 * V_6 ;
int V_7 = - V_8 ;
V_6 = F_2 ( F_3 ( sizeof( struct V_9 ) ) +
F_4 ( 1 ) + F_4 ( 4 ) , V_10 ) ;
if ( V_6 == NULL )
goto V_11;
V_7 = F_31 ( V_6 , V_3 , V_59 , 0 , 0 , V_1 ) ;
if ( V_7 < 0 ) {
F_6 ( V_7 == - V_12 ) ;
F_7 ( V_6 ) ;
goto V_11;
}
F_8 ( V_6 , F_9 ( V_3 ) , 0 ,
V_77 , NULL , V_10 ) ;
return;
V_11:
F_10 ( F_9 ( V_3 ) , V_77 , V_7 ) ;
}
static int F_34 ( struct V_5 * V_6 , struct V_14 * V_15 , void * V_16 )
{
struct V_17 * V_17 = F_12 ( V_6 -> V_18 ) ;
struct V_19 * V_20 [ V_78 + 1 ] ;
struct V_2 * V_3 ;
struct V_60 * V_61 ;
int V_7 ;
T_1 V_59 ;
if ( ! F_13 ( V_24 ) )
return - V_25 ;
if ( ! F_13 ( V_26 ) )
return - V_25 ;
F_14 () ;
V_7 = F_15 ( V_15 , sizeof( * V_61 ) , V_20 , V_78 , V_79 ) ;
if ( V_7 < 0 )
return V_7 ;
V_61 = F_16 ( V_15 ) ;
if ( V_61 -> V_66 != V_67 || V_61 -> V_72 != V_73 )
return - V_29 ;
if ( V_20 [ V_75 ] == NULL || V_20 [ V_76 ] == NULL )
return - V_29 ;
V_59 = F_17 ( V_20 [ V_75 ] ) ;
if ( V_59 & 3 )
return - V_29 ;
V_3 = F_18 ( V_17 , F_35 ( V_20 [ V_76 ] ) ) ;
if ( V_3 == NULL )
return - V_31 ;
if ( V_15 -> V_32 == V_80 )
V_7 = F_36 ( V_3 , V_59 ) ;
else
V_7 = F_37 ( V_3 , V_59 ) ;
if ( ! V_7 )
F_33 ( V_15 -> V_32 , V_3 , V_59 ) ;
return V_7 ;
}
static int F_38 ( struct V_5 * V_6 , struct V_45 * V_46 )
{
struct V_17 * V_17 = F_12 ( V_6 -> V_18 ) ;
T_1 V_4 , V_53 = 0 , V_54 = V_46 -> args [ 0 ] ;
F_26 () ;
for ( V_4 = 0 ; V_4 < 64 ; V_4 ++ ) {
struct V_2 * V_3 ;
V_3 = F_39 ( V_17 , V_4 << 2 ) ;
if ( ! V_3 )
continue;
if ( V_53 ++ < V_54 )
continue;
if ( F_31 ( V_6 , V_3 , V_4 << 2 , F_29 ( V_46 -> V_6 ) . V_34 ,
V_46 -> V_15 -> V_56 , V_80 ) )
goto V_57;
}
V_57:
F_30 () ;
V_46 -> args [ 0 ] = V_53 ;
V_46 -> args [ 1 ] = 0 ;
return V_6 -> V_58 ;
}
int T_3 F_40 ( void )
{
int V_7 = F_41 ( V_81 , V_33 , F_11 ,
NULL , NULL ) ;
if ( V_7 )
return V_7 ;
F_41 ( V_81 , V_82 , F_11 , NULL , NULL ) ;
F_41 ( V_81 , V_83 , NULL , F_25 , NULL ) ;
F_41 ( V_81 , V_80 , F_34 , NULL , NULL ) ;
F_41 ( V_81 , V_84 , F_34 , NULL , NULL ) ;
F_41 ( V_81 , V_85 , NULL , F_38 , NULL ) ;
return 0 ;
}
