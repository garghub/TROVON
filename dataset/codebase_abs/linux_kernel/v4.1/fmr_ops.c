static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
return 0 ;
}
static T_1
F_2 ( struct V_7 * V_8 )
{
return F_3 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
rpcrdma_max_segments(r_xprt) * RPCRDMA_MAX_FMR_SGES) ;
}
static int
F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = & V_8 -> V_11 ;
int V_12 = V_13 | V_14 ;
struct V_15 V_16 = {
. V_17 = V_18 ,
. V_19 = 1 ,
. V_20 = V_21
} ;
struct V_22 * V_23 = V_8 -> V_24 . V_25 ;
struct V_26 * V_27 ;
int V_28 , V_29 ;
F_5 ( & V_10 -> V_30 ) ;
F_5 ( & V_10 -> V_31 ) ;
V_28 = ( V_10 -> V_32 + 1 ) * V_33 ;
F_6 ( L_1 , V_34 , V_28 ) ;
while ( V_28 -- ) {
V_27 = F_7 ( sizeof( * V_27 ) , V_35 ) ;
if ( ! V_27 )
return - V_36 ;
V_27 -> V_27 . V_37 = F_8 ( V_23 , V_12 , & V_16 ) ;
if ( F_9 ( V_27 -> V_27 . V_37 ) )
goto V_38;
F_10 ( & V_27 -> V_39 , & V_10 -> V_30 ) ;
F_10 ( & V_27 -> V_40 , & V_10 -> V_31 ) ;
}
return 0 ;
V_38:
V_29 = F_11 ( V_27 -> V_27 . V_37 ) ;
F_6 ( L_2 , V_34 , V_29 ) ;
F_12 ( V_27 ) ;
return V_29 ;
}
static int
F_13 ( struct V_7 * V_8 , struct V_41 * V_42 ,
int V_43 , bool V_44 )
{
struct V_1 * V_2 = & V_8 -> V_24 ;
struct V_45 * V_46 = V_2 -> V_47 -> V_46 ;
enum V_48 V_49 = F_14 ( V_44 ) ;
struct V_41 * V_50 = V_42 ;
struct V_26 * V_51 = V_50 -> V_52 ;
T_2 V_53 [ V_54 ] ;
int V_55 , V_56 , V_28 , V_29 ;
V_56 = F_15 ( V_50 -> V_57 ) ;
V_50 -> V_57 -= V_56 ;
V_50 -> V_58 += V_56 ;
V_55 = - V_56 ;
if ( V_43 > V_18 )
V_43 = V_18 ;
for ( V_28 = 0 ; V_28 < V_43 ; ) {
F_16 ( V_46 , V_42 , V_49 ) ;
V_53 [ V_28 ] = V_42 -> V_59 ;
V_55 += V_42 -> V_58 ;
++ V_42 ;
++ V_28 ;
if ( ( V_28 < V_43 && F_15 ( V_42 -> V_57 ) ) ||
F_15 ( ( V_42 - 1 ) -> V_57 + ( V_42 - 1 ) -> V_58 ) )
break;
}
V_29 = F_17 ( V_51 -> V_27 . V_37 , V_53 , V_28 , V_50 -> V_59 ) ;
if ( V_29 )
goto V_60;
V_50 -> V_61 = V_51 -> V_27 . V_37 -> V_62 ;
V_50 -> V_63 = V_50 -> V_59 + V_56 ;
V_50 -> V_64 = V_28 ;
V_50 -> V_58 = V_55 ;
return V_28 ;
V_60:
F_6 ( L_3 ,
V_34 , V_55 , ( unsigned long long ) V_50 -> V_59 ,
V_56 , V_28 , V_29 ) ;
while ( V_28 -- )
F_18 ( V_46 , -- V_42 ) ;
return V_29 ;
}
static int
F_19 ( struct V_7 * V_8 , struct V_41 * V_42 )
{
struct V_1 * V_2 = & V_8 -> V_24 ;
struct V_41 * V_50 = V_42 ;
struct V_45 * V_46 ;
int V_29 , V_43 = V_42 -> V_64 ;
F_20 ( V_65 ) ;
F_10 ( & V_50 -> V_52 -> V_27 . V_37 -> V_66 , & V_65 ) ;
V_29 = F_21 ( & V_65 ) ;
F_22 ( & V_2 -> V_67 ) ;
V_46 = V_2 -> V_47 -> V_46 ;
while ( V_50 -> V_64 -- )
F_18 ( V_46 , V_42 ++ ) ;
F_23 ( & V_2 -> V_67 ) ;
if ( V_29 )
goto V_68;
return V_43 ;
V_68:
F_6 ( L_4 , V_34 , V_29 ) ;
return V_43 ;
}
static void
F_24 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = & V_8 -> V_11 ;
struct V_26 * V_27 ;
F_20 ( V_66 ) ;
int V_29 ;
F_25 (r, &buf->rb_all, mw_all)
F_10 ( & V_27 -> V_27 . V_37 -> V_66 , & V_66 ) ;
V_29 = F_21 ( & V_66 ) ;
if ( V_29 )
F_6 ( L_5 ,
V_34 , V_29 ) ;
}
static void
F_26 ( struct V_9 * V_10 )
{
struct V_26 * V_27 ;
int V_29 ;
while ( ! F_27 ( & V_10 -> V_31 ) ) {
V_27 = F_28 ( V_10 -> V_31 . V_69 , struct V_26 , V_40 ) ;
F_29 ( & V_27 -> V_40 ) ;
V_29 = F_30 ( V_27 -> V_27 . V_37 ) ;
if ( V_29 )
F_6 ( L_6 ,
V_34 , V_29 ) ;
F_12 ( V_27 ) ;
}
}
