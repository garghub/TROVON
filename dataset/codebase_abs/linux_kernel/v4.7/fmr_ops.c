int
F_1 ( void )
{
V_1 = F_2 ( L_1 , V_2 , 0 ) ;
return ! V_1 ? - V_3 : 0 ;
}
void
F_3 ( void )
{
struct V_4 * V_5 ;
if ( ! V_1 )
return;
V_5 = V_1 ;
V_1 = NULL ;
F_4 ( V_5 ) ;
}
static int
F_5 ( struct V_6 * V_7 )
{
F_6 ( V_8 ) ;
F_7 ( & V_7 -> V_9 . V_9 -> V_10 , & V_8 ) ;
return F_8 ( & V_8 ) ;
}
static void
F_9 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_10 ( V_12 , struct V_6 ,
V_13 ) ;
struct V_14 * V_15 = V_7 -> V_16 ;
F_5 ( V_7 ) ;
F_11 ( V_15 , V_7 ) ;
return;
}
static void
F_12 ( struct V_6 * V_7 )
{
F_13 ( & V_7 -> V_13 , F_9 ) ;
F_14 ( V_1 , & V_7 -> V_13 ) ;
}
static int
F_15 ( struct V_17 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 )
{
F_16 ( V_18 , V_22 , F_17 (unsigned int, 1 ,
RPCRDMA_MAX_DATA_SEGS /
RPCRDMA_MAX_FMR_SGES) ) ;
return 0 ;
}
static T_1
F_18 ( struct V_14 * V_15 )
{
return F_19 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
RPCRDMA_MAX_HDR_SEGS * RPCRDMA_MAX_FMR_SGES) ;
}
static int
F_20 ( struct V_14 * V_15 )
{
struct V_23 * V_24 = & V_15 -> V_25 ;
int V_26 = V_27 | V_28 ;
struct V_29 V_30 = {
. V_31 = V_32 ,
. V_33 = 1 ,
. V_34 = V_35
} ;
struct V_36 * V_37 = V_15 -> V_38 . V_39 ;
struct V_6 * V_40 ;
int V_41 , V_42 ;
F_21 ( & V_24 -> V_43 ) ;
F_22 ( & V_24 -> V_44 ) ;
F_22 ( & V_24 -> V_45 ) ;
V_41 = F_17 ( int , V_46 / V_32 , 1 ) ;
V_41 += 2 ;
V_41 *= V_24 -> V_47 ;
F_23 ( L_2 , V_48 , V_41 ) ;
V_42 = - V_3 ;
while ( V_41 -- ) {
V_40 = F_24 ( sizeof( * V_40 ) , V_49 ) ;
if ( ! V_40 )
goto V_50;
V_40 -> V_9 . V_51 = F_25 ( V_32 *
sizeof( V_52 ) , V_49 ) ;
if ( ! V_40 -> V_9 . V_51 )
goto V_53;
V_40 -> V_9 . V_9 = F_26 ( V_37 , V_26 , & V_30 ) ;
if ( F_27 ( V_40 -> V_9 . V_9 ) )
goto V_54;
V_40 -> V_16 = V_15 ;
F_7 ( & V_40 -> V_55 , & V_24 -> V_44 ) ;
F_7 ( & V_40 -> V_56 , & V_24 -> V_45 ) ;
}
return 0 ;
V_54:
V_42 = F_28 ( V_40 -> V_9 . V_9 ) ;
F_23 ( L_3 , V_48 , V_42 ) ;
F_29 ( V_40 -> V_9 . V_51 ) ;
V_53:
F_29 ( V_40 ) ;
V_50:
return V_42 ;
}
static int
F_30 ( struct V_14 * V_15 , struct V_57 * V_58 ,
int V_59 , bool V_60 )
{
struct V_17 * V_18 = & V_15 -> V_38 ;
struct V_61 * V_62 = V_18 -> V_63 ;
enum V_64 V_65 = F_31 ( V_60 ) ;
struct V_57 * V_66 = V_58 ;
int V_67 , V_68 , V_41 , V_42 ;
struct V_6 * V_7 ;
V_7 = V_66 -> V_69 ;
V_66 -> V_69 = NULL ;
if ( ! V_7 ) {
V_7 = F_32 ( V_15 ) ;
if ( ! V_7 )
return - V_3 ;
} else {
V_42 = F_5 ( V_7 ) ;
if ( V_42 )
return V_42 ;
}
V_68 = F_33 ( V_66 -> V_70 ) ;
V_66 -> V_70 -= V_68 ;
V_66 -> V_71 += V_68 ;
V_67 = - V_68 ;
if ( V_59 > V_32 )
V_59 = V_32 ;
for ( V_41 = 0 ; V_41 < V_59 ; ) {
F_34 ( V_62 , V_58 , V_65 ) ;
V_7 -> V_9 . V_51 [ V_41 ] = V_58 -> V_72 ;
V_67 += V_58 -> V_71 ;
++ V_58 ;
++ V_41 ;
if ( ( V_41 < V_59 && F_33 ( V_58 -> V_70 ) ) ||
F_33 ( ( V_58 - 1 ) -> V_70 + ( V_58 - 1 ) -> V_71 ) )
break;
}
V_42 = F_35 ( V_7 -> V_9 . V_9 , V_7 -> V_9 . V_51 ,
V_41 , V_66 -> V_72 ) ;
if ( V_42 )
goto V_73;
V_66 -> V_69 = V_7 ;
V_66 -> V_74 = V_7 -> V_9 . V_9 -> V_75 ;
V_66 -> V_76 = V_66 -> V_72 + V_68 ;
V_66 -> V_77 = V_41 ;
V_66 -> V_71 = V_67 ;
return V_41 ;
V_73:
F_23 ( L_4 ,
V_48 , V_67 , ( unsigned long long ) V_66 -> V_72 ,
V_68 , V_41 , V_42 ) ;
while ( V_41 -- )
F_36 ( V_62 , -- V_58 ) ;
return V_42 ;
}
static void
F_37 ( struct V_14 * V_15 , struct V_57 * V_58 )
{
struct V_61 * V_62 = V_15 -> V_38 . V_63 ;
int V_59 = V_58 -> V_77 ;
while ( V_59 -- )
F_36 ( V_62 , V_58 ++ ) ;
}
static void
F_38 ( struct V_14 * V_15 , struct V_78 * V_79 )
{
struct V_57 * V_58 ;
unsigned int V_41 , V_80 ;
struct V_6 * V_7 ;
F_6 ( V_81 ) ;
int V_42 ;
F_23 ( L_5 , V_48 , V_79 ) ;
for ( V_41 = 0 , V_80 = V_79 -> V_82 ; V_80 ; V_80 -- ) {
V_58 = & V_79 -> V_83 [ V_41 ] ;
V_7 = V_58 -> V_69 ;
F_7 ( & V_7 -> V_9 . V_9 -> V_10 , & V_81 ) ;
V_41 += V_58 -> V_77 ;
}
V_42 = F_8 ( & V_81 ) ;
if ( V_42 )
F_39 ( L_6 , V_48 , V_42 ) ;
for ( V_41 = 0 , V_80 = V_79 -> V_82 ; V_80 ; V_80 -- ) {
V_58 = & V_79 -> V_83 [ V_41 ] ;
F_37 ( V_15 , V_58 ) ;
F_11 ( V_15 , V_58 -> V_69 ) ;
V_41 += V_58 -> V_77 ;
V_58 -> V_77 = 0 ;
V_58 -> V_69 = NULL ;
}
V_79 -> V_82 = 0 ;
}
static void
F_40 ( struct V_14 * V_15 , struct V_78 * V_79 ,
bool V_84 )
{
struct V_57 * V_58 ;
struct V_6 * V_7 ;
unsigned int V_41 ;
for ( V_41 = 0 ; V_79 -> V_82 ; V_79 -> V_82 -- ) {
V_58 = & V_79 -> V_83 [ V_41 ] ;
V_7 = V_58 -> V_69 ;
if ( V_84 ) {
F_5 ( V_7 ) ;
F_37 ( V_15 , V_58 ) ;
F_11 ( V_15 , V_7 ) ;
} else {
F_37 ( V_15 , V_58 ) ;
F_12 ( V_7 ) ;
}
V_41 += V_58 -> V_77 ;
V_58 -> V_77 = 0 ;
V_58 -> V_69 = NULL ;
}
}
static void
F_41 ( struct V_23 * V_24 )
{
struct V_6 * V_40 ;
int V_42 ;
while ( ! F_42 ( & V_24 -> V_45 ) ) {
V_40 = F_43 ( V_24 -> V_45 . V_85 , struct V_6 , V_56 ) ;
F_44 ( & V_40 -> V_56 ) ;
F_29 ( V_40 -> V_9 . V_51 ) ;
V_42 = F_45 ( V_40 -> V_9 . V_9 ) ;
if ( V_42 )
F_23 ( L_7 ,
V_48 , V_42 ) ;
F_29 ( V_40 ) ;
}
}
