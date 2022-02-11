bool
F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 -> V_4 ) {
F_2 ( L_1 ,
V_2 -> V_3 -> V_5 ) ;
return false ;
}
return true ;
}
static int
F_3 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
static struct V_8 V_9 = {
. V_10 = V_11 ,
. V_12 = 1 ,
. V_13 = V_14
} ;
V_7 -> V_15 . V_16 = F_4 ( V_11 ,
sizeof( V_17 ) , V_18 ) ;
if ( ! V_7 -> V_15 . V_16 )
goto V_19;
V_7 -> V_20 = F_4 ( V_11 ,
sizeof( * V_7 -> V_20 ) , V_18 ) ;
if ( ! V_7 -> V_20 )
goto V_19;
F_5 ( V_7 -> V_20 , V_11 ) ;
V_7 -> V_15 . V_21 = F_6 ( V_2 -> V_22 , V_23 ,
& V_9 ) ;
if ( F_7 ( V_7 -> V_15 . V_21 ) )
goto V_24;
return 0 ;
V_24:
F_8 ( L_2 , V_25 ,
F_9 ( V_7 -> V_15 . V_21 ) ) ;
V_19:
F_10 ( V_7 -> V_20 ) ;
F_10 ( V_7 -> V_15 . V_16 ) ;
return - V_26 ;
}
static int
F_11 ( struct V_6 * V_7 )
{
F_12 ( V_27 ) ;
int V_28 ;
F_13 ( & V_7 -> V_15 . V_21 -> V_29 , & V_27 ) ;
V_28 = F_14 ( & V_27 ) ;
F_15 ( & V_7 -> V_15 . V_21 -> V_29 ) ;
return V_28 ;
}
static void
F_16 ( struct V_6 * V_30 )
{
F_12 ( V_31 ) ;
int V_28 ;
if ( ! F_17 ( & V_30 -> V_32 ) )
F_18 ( & V_30 -> V_32 ) ;
F_10 ( V_30 -> V_15 . V_16 ) ;
F_10 ( V_30 -> V_20 ) ;
V_28 = F_11 ( V_30 ) ;
if ( V_28 )
F_19 ( L_3 ,
V_30 , V_28 ) ;
V_28 = F_20 ( V_30 -> V_15 . V_21 ) ;
if ( V_28 )
F_19 ( L_4 ,
V_30 , V_28 ) ;
F_10 ( V_30 ) ;
}
static void
F_21 ( struct V_6 * V_7 )
{
struct V_33 * V_34 = V_7 -> V_35 ;
int V_28 ;
V_28 = F_11 ( V_7 ) ;
F_22 ( V_34 -> V_36 . V_3 ,
V_7 -> V_20 , V_7 -> V_37 , V_7 -> V_38 ) ;
if ( V_28 )
goto V_39;
F_23 ( V_34 , V_7 ) ;
V_34 -> V_40 . V_41 ++ ;
return;
V_39:
F_19 ( L_5 , V_28 , V_7 ) ;
V_34 -> V_40 . V_42 ++ ;
F_24 ( & V_34 -> V_43 . V_44 ) ;
F_18 ( & V_7 -> V_45 ) ;
F_25 ( & V_34 -> V_43 . V_44 ) ;
F_16 ( V_7 ) ;
}
static int
F_26 ( struct V_1 * V_2 , struct V_46 * V_47 ,
struct V_48 * V_49 )
{
F_27 ( V_2 , V_49 , F_28 (unsigned int, 1 ,
RPCRDMA_MAX_DATA_SEGS /
RPCRDMA_MAX_FMR_SGES) ) ;
return 0 ;
}
static T_1
F_29 ( struct V_33 * V_34 )
{
return F_30 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
RPCRDMA_MAX_HDR_SEGS * RPCRDMA_MAX_FMR_SGES) ;
}
static int
F_31 ( struct V_33 * V_34 , struct V_50 * V_51 ,
int V_52 , bool V_53 , struct V_6 * * V_54 )
{
struct V_50 * V_55 = V_51 ;
int V_56 , V_57 , V_58 , V_28 ;
struct V_6 * V_7 ;
V_17 * V_59 ;
V_7 = F_32 ( V_34 ) ;
if ( ! V_7 )
return - V_60 ;
V_57 = F_33 ( V_55 -> V_61 ) ;
V_55 -> V_61 -= V_57 ;
V_55 -> V_62 += V_57 ;
V_56 = - V_57 ;
if ( V_52 > V_11 )
V_52 = V_11 ;
for ( V_58 = 0 ; V_58 < V_52 ; ) {
if ( V_51 -> V_63 )
F_34 ( & V_7 -> V_20 [ V_58 ] ,
V_51 -> V_63 ,
V_51 -> V_62 ,
F_33 ( V_51 -> V_61 ) ) ;
else
F_35 ( & V_7 -> V_20 [ V_58 ] , V_51 -> V_61 ,
V_51 -> V_62 ) ;
V_56 += V_51 -> V_62 ;
++ V_51 ;
++ V_58 ;
if ( ( V_58 < V_52 && F_33 ( V_51 -> V_61 ) ) ||
F_33 ( ( V_51 - 1 ) -> V_61 + ( V_51 - 1 ) -> V_62 ) )
break;
}
V_7 -> V_37 = V_58 ;
V_7 -> V_38 = F_36 ( V_53 ) ;
if ( V_58 == 0 )
goto V_64;
if ( ! F_37 ( V_34 -> V_36 . V_3 ,
V_7 -> V_20 , V_7 -> V_37 , V_7 -> V_38 ) )
goto V_64;
for ( V_58 = 0 , V_59 = V_7 -> V_15 . V_16 ; V_58 < V_7 -> V_37 ; V_58 ++ )
V_59 [ V_58 ] = F_38 ( & V_7 -> V_20 [ V_58 ] ) ;
V_28 = F_39 ( V_7 -> V_15 . V_21 , V_59 , V_7 -> V_37 ,
V_59 [ 0 ] ) ;
if ( V_28 )
goto V_65;
V_7 -> V_66 = V_7 -> V_15 . V_21 -> V_67 ;
V_7 -> V_68 = V_56 ;
V_7 -> V_69 = V_59 [ 0 ] + V_57 ;
* V_54 = V_7 ;
return V_7 -> V_37 ;
V_64:
F_19 ( L_6 ,
V_7 -> V_20 , V_7 -> V_37 ) ;
F_40 ( V_7 ) ;
return - V_70 ;
V_65:
F_19 ( L_7 ,
V_56 , ( unsigned long long ) V_59 [ 0 ] ,
V_57 , V_7 -> V_37 , V_28 ) ;
F_40 ( V_7 ) ;
return - V_70 ;
}
static void
F_41 ( struct V_33 * V_34 , struct V_71 * V_72 )
{
struct V_6 * V_7 , * V_73 ;
F_12 ( V_31 ) ;
int V_28 ;
F_8 ( L_8 , V_25 , V_72 ) ;
F_42 (mw, &req->rl_registered, mw_list)
F_43 ( & V_7 -> V_15 . V_21 -> V_29 , & V_31 ) ;
V_28 = F_14 ( & V_31 ) ;
if ( V_28 )
goto V_74;
F_44 (mw, tmp, &req->rl_registered, mw_list) {
F_15 ( & V_7 -> V_32 ) ;
F_15 ( & V_7 -> V_15 . V_21 -> V_29 ) ;
F_22 ( V_34 -> V_36 . V_3 ,
V_7 -> V_20 , V_7 -> V_37 , V_7 -> V_38 ) ;
F_23 ( V_34 , V_7 ) ;
}
return;
V_74:
F_19 ( L_9 , V_28 ) ;
F_44 (mw, tmp, &req->rl_registered, mw_list) {
F_15 ( & V_7 -> V_15 . V_21 -> V_29 ) ;
F_21 ( V_7 ) ;
}
}
static void
F_45 ( struct V_33 * V_34 , struct V_71 * V_72 ,
bool V_75 )
{
struct V_6 * V_7 ;
while ( ! F_17 ( & V_72 -> V_76 ) ) {
V_7 = F_46 ( & V_72 -> V_76 ,
struct V_6 , V_32 ) ;
F_15 ( & V_7 -> V_32 ) ;
if ( V_75 )
F_21 ( V_7 ) ;
else
F_40 ( V_7 ) ;
}
}
