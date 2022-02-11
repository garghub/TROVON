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
static int F_11 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_16 * V_16 = F_12 ( V_6 -> V_17 ) ;
struct V_18 * V_19 [ V_20 + 1 ] ;
struct V_2 * V_3 ;
struct V_9 * V_21 ;
int V_7 ;
T_1 V_22 ;
if ( ! F_13 ( V_6 , V_23 ) )
return - V_24 ;
if ( ! F_13 ( V_6 , V_25 ) )
return - V_24 ;
F_14 () ;
V_7 = F_15 ( V_15 , sizeof( * V_21 ) , V_19 , V_20 , V_26 ) ;
if ( V_7 < 0 )
return V_7 ;
V_21 = F_16 ( V_15 ) ;
if ( V_19 [ V_27 ] == NULL )
return - V_28 ;
V_22 = F_17 ( V_19 [ V_27 ] ) ;
if ( V_22 & 3 )
return - V_28 ;
V_3 = F_18 ( V_16 , V_21 -> V_29 ) ;
if ( V_3 == NULL )
return - V_30 ;
if ( V_15 -> V_31 == V_32 )
V_7 = F_19 ( V_3 , V_22 ) ;
else
V_7 = F_20 ( V_3 , V_22 ) ;
if ( ! V_7 )
F_1 ( V_15 -> V_31 , V_3 , V_22 ) ;
return V_7 ;
}
static int F_5 ( struct V_5 * V_6 , struct V_2 * V_3 , T_1 V_4 ,
T_2 V_33 , T_2 V_34 , int V_1 )
{
struct V_9 * V_21 ;
struct V_14 * V_15 ;
V_15 = F_21 ( V_6 , V_33 , V_34 , V_1 , sizeof( * V_21 ) , 0 ) ;
if ( V_15 == NULL )
return - V_12 ;
V_21 = F_16 ( V_15 ) ;
V_21 -> V_35 = V_36 ;
V_21 -> V_37 = 0 ;
V_21 -> V_38 = V_39 ;
V_21 -> V_40 = V_41 ;
V_21 -> V_29 = V_3 -> V_42 ;
if ( F_22 ( V_6 , V_27 , V_4 ) )
goto V_43;
return F_23 ( V_6 , V_15 ) ;
V_43:
F_24 ( V_6 , V_15 ) ;
return - V_12 ;
}
static int F_25 ( struct V_5 * V_6 , struct V_44 * V_45 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_50 = 0 , V_51 = V_45 -> args [ 0 ] ;
int V_52 = 0 , V_53 = V_45 -> args [ 1 ] ;
V_47 = V_46 ( F_12 ( V_6 -> V_17 ) ) ;
F_26 () ;
F_27 (pnd, &pndevs->list, list) {
T_1 V_4 ;
if ( V_50 > V_51 )
V_53 = 0 ;
if ( V_50 ++ < V_51 )
continue;
V_52 = 0 ;
F_28 (addr, pnd->addrs, 64 ) {
if ( V_52 ++ < V_53 )
continue;
if ( F_5 ( V_6 , V_49 -> V_54 , V_4 << 2 ,
F_29 ( V_45 -> V_6 ) . V_33 ,
V_45 -> V_15 -> V_55 , V_32 ) < 0 )
goto V_56;
}
}
V_56:
F_30 () ;
V_45 -> args [ 0 ] = V_50 ;
V_45 -> args [ 1 ] = V_52 ;
return V_6 -> V_57 ;
}
static int F_31 ( struct V_5 * V_6 , struct V_2 * V_3 , T_1 V_58 ,
T_2 V_33 , T_2 V_34 , int V_1 )
{
struct V_59 * V_60 ;
struct V_14 * V_15 ;
V_15 = F_21 ( V_6 , V_33 , V_34 , V_1 , sizeof( * V_60 ) , 0 ) ;
if ( V_15 == NULL )
return - V_12 ;
V_60 = F_16 ( V_15 ) ;
V_60 -> V_61 = V_36 ;
V_60 -> V_62 = 6 ;
V_60 -> V_63 = 0 ;
V_60 -> V_64 = 0 ;
V_60 -> V_65 = V_66 ;
V_60 -> V_67 = V_68 ;
V_60 -> V_69 = V_70 ;
V_60 -> V_71 = V_72 ;
V_60 -> V_73 = 0 ;
if ( F_22 ( V_6 , V_74 , V_58 ) ||
F_32 ( V_6 , V_75 , V_3 -> V_42 ) )
goto V_43;
return F_23 ( V_6 , V_15 ) ;
V_43:
F_24 ( V_6 , V_15 ) ;
return - V_12 ;
}
void F_33 ( int V_1 , struct V_2 * V_3 , T_1 V_58 )
{
struct V_5 * V_6 ;
int V_7 = - V_8 ;
V_6 = F_2 ( F_3 ( sizeof( struct V_9 ) ) +
F_4 ( 1 ) + F_4 ( 4 ) , V_10 ) ;
if ( V_6 == NULL )
goto V_11;
V_7 = F_31 ( V_6 , V_3 , V_58 , 0 , 0 , V_1 ) ;
if ( V_7 < 0 ) {
F_6 ( V_7 == - V_12 ) ;
F_7 ( V_6 ) ;
goto V_11;
}
F_8 ( V_6 , F_9 ( V_3 ) , 0 ,
V_76 , NULL , V_10 ) ;
return;
V_11:
F_10 ( F_9 ( V_3 ) , V_76 , V_7 ) ;
}
static int F_34 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_16 * V_16 = F_12 ( V_6 -> V_17 ) ;
struct V_18 * V_19 [ V_77 + 1 ] ;
struct V_2 * V_3 ;
struct V_59 * V_60 ;
int V_7 ;
T_1 V_58 ;
if ( ! F_13 ( V_6 , V_23 ) )
return - V_24 ;
if ( ! F_13 ( V_6 , V_25 ) )
return - V_24 ;
F_14 () ;
V_7 = F_15 ( V_15 , sizeof( * V_60 ) , V_19 , V_77 , V_78 ) ;
if ( V_7 < 0 )
return V_7 ;
V_60 = F_16 ( V_15 ) ;
if ( V_60 -> V_65 != V_66 || V_60 -> V_71 != V_72 )
return - V_28 ;
if ( V_19 [ V_74 ] == NULL || V_19 [ V_75 ] == NULL )
return - V_28 ;
V_58 = F_17 ( V_19 [ V_74 ] ) ;
if ( V_58 & 3 )
return - V_28 ;
V_3 = F_18 ( V_16 , F_35 ( V_19 [ V_75 ] ) ) ;
if ( V_3 == NULL )
return - V_30 ;
if ( V_15 -> V_31 == V_79 )
V_7 = F_36 ( V_3 , V_58 ) ;
else
V_7 = F_37 ( V_3 , V_58 ) ;
if ( ! V_7 )
F_33 ( V_15 -> V_31 , V_3 , V_58 ) ;
return V_7 ;
}
static int F_38 ( struct V_5 * V_6 , struct V_44 * V_45 )
{
struct V_16 * V_16 = F_12 ( V_6 -> V_17 ) ;
T_1 V_4 , V_52 = 0 , V_53 = V_45 -> args [ 0 ] ;
F_26 () ;
for ( V_4 = 0 ; V_4 < 64 ; V_4 ++ ) {
struct V_2 * V_3 ;
V_3 = F_39 ( V_16 , V_4 << 2 ) ;
if ( ! V_3 )
continue;
if ( V_52 ++ < V_53 )
continue;
if ( F_31 ( V_6 , V_3 , V_4 << 2 , F_29 ( V_45 -> V_6 ) . V_33 ,
V_45 -> V_15 -> V_55 , V_79 ) )
goto V_56;
}
V_56:
F_30 () ;
V_45 -> args [ 0 ] = V_52 ;
V_45 -> args [ 1 ] = 0 ;
return V_6 -> V_57 ;
}
int T_3 F_40 ( void )
{
int V_7 = F_41 ( V_80 , V_32 , F_11 ,
NULL , NULL ) ;
if ( V_7 )
return V_7 ;
F_41 ( V_80 , V_81 , F_11 , NULL , NULL ) ;
F_41 ( V_80 , V_82 , NULL , F_25 , NULL ) ;
F_41 ( V_80 , V_79 , F_34 , NULL , NULL ) ;
F_41 ( V_80 , V_83 , F_34 , NULL , NULL ) ;
F_41 ( V_80 , V_84 , NULL , F_38 , NULL ) ;
return 0 ;
}
