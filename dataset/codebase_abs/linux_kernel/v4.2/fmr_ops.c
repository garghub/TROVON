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
F_6 ( & V_10 -> V_31 ) ;
F_6 ( & V_10 -> V_32 ) ;
V_28 = F_7 ( int , V_33 / V_18 , 1 ) ;
V_28 += 2 ;
V_28 *= V_10 -> V_34 ;
F_8 ( L_1 , V_35 , V_28 ) ;
V_29 = - V_36 ;
while ( V_28 -- ) {
V_27 = F_9 ( sizeof( * V_27 ) , V_37 ) ;
if ( ! V_27 )
goto V_38;
V_27 -> V_27 . V_39 . V_40 = F_10 ( V_18 *
sizeof( V_41 ) , V_37 ) ;
if ( ! V_27 -> V_27 . V_39 . V_40 )
goto V_42;
V_27 -> V_27 . V_39 . V_39 = F_11 ( V_23 , V_12 , & V_16 ) ;
if ( F_12 ( V_27 -> V_27 . V_39 . V_39 ) )
goto V_43;
F_13 ( & V_27 -> V_44 , & V_10 -> V_31 ) ;
F_13 ( & V_27 -> V_45 , & V_10 -> V_32 ) ;
}
return 0 ;
V_43:
V_29 = F_14 ( V_27 -> V_27 . V_39 . V_39 ) ;
F_8 ( L_2 , V_35 , V_29 ) ;
F_15 ( V_27 -> V_27 . V_39 . V_40 ) ;
V_42:
F_15 ( V_27 ) ;
V_38:
return V_29 ;
}
static int
F_16 ( struct V_26 * V_27 )
{
F_17 ( V_46 ) ;
F_13 ( & V_27 -> V_27 . V_39 . V_39 -> V_47 , & V_46 ) ;
return F_18 ( & V_46 ) ;
}
static int
F_19 ( struct V_7 * V_8 , struct V_48 * V_49 ,
int V_50 , bool V_51 )
{
struct V_1 * V_2 = & V_8 -> V_24 ;
struct V_52 * V_53 = V_2 -> V_54 ;
enum V_55 V_56 = F_20 ( V_51 ) ;
struct V_48 * V_57 = V_49 ;
int V_58 , V_59 , V_28 , V_29 ;
struct V_26 * V_60 ;
V_60 = V_57 -> V_61 ;
V_57 -> V_61 = NULL ;
if ( ! V_60 ) {
V_60 = F_21 ( V_8 ) ;
if ( ! V_60 )
return - V_36 ;
} else {
V_29 = F_16 ( V_60 ) ;
if ( V_29 )
return V_29 ;
}
V_59 = F_22 ( V_57 -> V_62 ) ;
V_57 -> V_62 -= V_59 ;
V_57 -> V_63 += V_59 ;
V_58 = - V_59 ;
if ( V_50 > V_18 )
V_50 = V_18 ;
for ( V_28 = 0 ; V_28 < V_50 ; ) {
F_23 ( V_53 , V_49 , V_56 ) ;
V_60 -> V_27 . V_39 . V_40 [ V_28 ] = V_49 -> V_64 ;
V_58 += V_49 -> V_63 ;
++ V_49 ;
++ V_28 ;
if ( ( V_28 < V_50 && F_22 ( V_49 -> V_62 ) ) ||
F_22 ( ( V_49 - 1 ) -> V_62 + ( V_49 - 1 ) -> V_63 ) )
break;
}
V_29 = F_24 ( V_60 -> V_27 . V_39 . V_39 , V_60 -> V_27 . V_39 . V_40 ,
V_28 , V_57 -> V_64 ) ;
if ( V_29 )
goto V_65;
V_57 -> V_61 = V_60 ;
V_57 -> V_66 = V_60 -> V_27 . V_39 . V_39 -> V_67 ;
V_57 -> V_68 = V_57 -> V_64 + V_59 ;
V_57 -> V_69 = V_28 ;
V_57 -> V_63 = V_58 ;
return V_28 ;
V_65:
F_8 ( L_3 ,
V_35 , V_58 , ( unsigned long long ) V_57 -> V_64 ,
V_59 , V_28 , V_29 ) ;
while ( V_28 -- )
F_25 ( V_53 , -- V_49 ) ;
return V_29 ;
}
static int
F_26 ( struct V_7 * V_8 , struct V_48 * V_49 )
{
struct V_1 * V_2 = & V_8 -> V_24 ;
struct V_48 * V_57 = V_49 ;
struct V_26 * V_60 = V_57 -> V_61 ;
int V_29 , V_50 = V_49 -> V_69 ;
F_8 ( L_4 , V_35 , V_60 ) ;
V_57 -> V_61 = NULL ;
while ( V_57 -> V_69 -- )
F_25 ( V_2 -> V_54 , V_49 ++ ) ;
V_29 = F_16 ( V_60 ) ;
if ( V_29 )
goto V_70;
F_27 ( V_8 , V_60 ) ;
return V_50 ;
V_70:
F_8 ( L_5 , V_35 , V_29 ) ;
return V_50 ;
}
static void
F_28 ( struct V_9 * V_10 )
{
struct V_26 * V_27 ;
int V_29 ;
while ( ! F_29 ( & V_10 -> V_32 ) ) {
V_27 = F_30 ( V_10 -> V_32 . V_71 , struct V_26 , V_45 ) ;
F_31 ( & V_27 -> V_45 ) ;
F_15 ( V_27 -> V_27 . V_39 . V_40 ) ;
V_29 = F_32 ( V_27 -> V_27 . V_39 . V_39 ) ;
if ( V_29 )
F_8 ( L_6 ,
V_35 , V_29 ) ;
F_15 ( V_27 ) ;
}
}
