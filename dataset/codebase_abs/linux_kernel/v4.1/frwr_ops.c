static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = & V_2 -> V_2 . V_10 ;
int V_11 ;
V_9 -> V_12 = F_2 ( V_4 , V_7 ) ;
if ( F_3 ( V_9 -> V_12 ) )
goto V_13;
V_9 -> V_14 = F_4 ( V_6 , V_7 ) ;
if ( F_3 ( V_9 -> V_14 ) )
goto V_15;
return 0 ;
V_13:
V_11 = F_5 ( V_9 -> V_12 ) ;
F_6 ( L_1 ,
V_16 , V_11 ) ;
return V_11 ;
V_15:
V_11 = F_5 ( V_9 -> V_14 ) ;
F_6 ( L_2 ,
V_16 , V_11 ) ;
F_7 ( V_9 -> V_12 ) ;
return V_11 ;
}
static void
F_8 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_7 ( V_2 -> V_2 . V_10 . V_12 ) ;
if ( V_11 )
F_6 ( L_3 ,
V_16 , V_11 ) ;
F_9 ( V_2 -> V_2 . V_10 . V_14 ) ;
}
static int
F_10 ( struct V_17 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_18 -> V_25 ;
int V_7 , V_26 ;
V_18 -> V_27 =
F_11 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
devattr->max_fast_reg_page_list_len) ;
F_6 ( L_4 ,
V_16 , V_18 -> V_27 ) ;
V_7 = 7 ;
if ( V_18 -> V_27 < V_28 ) {
V_26 = V_28 - V_18 -> V_27 ;
do {
V_7 += 2 ;
V_26 -= V_18 -> V_27 ;
} while ( V_26 > 0 );
}
V_20 -> V_29 . V_30 . V_31 *= V_7 ;
if ( V_20 -> V_29 . V_30 . V_31 > V_24 -> V_32 ) {
V_22 -> V_33 = V_24 -> V_32 / V_7 ;
if ( ! V_22 -> V_33 )
return - V_34 ;
V_20 -> V_29 . V_30 . V_31 = V_22 -> V_33 *
V_7 ;
}
return 0 ;
}
static T_1
F_12 ( struct V_35 * V_36 )
{
struct V_17 * V_18 = & V_36 -> V_37 ;
return F_11 (unsigned int, RPCRDMA_MAX_DATA_SEGS,
rpcrdma_max_segments(r_xprt) * ia->ri_max_frmr_depth) ;
}
static void
F_13 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
if ( F_14 ( V_39 -> V_40 == V_41 ) )
return;
V_2 = (struct V_1 * ) ( unsigned long ) V_39 -> V_42 ;
F_6 ( L_5 ,
V_16 , V_2 , V_39 -> V_40 ) ;
V_2 -> V_2 . V_10 . V_43 = V_44 ;
}
static int
F_15 ( struct V_35 * V_36 )
{
struct V_45 * V_46 = & V_36 -> V_47 ;
struct V_5 * V_6 = V_36 -> V_37 . V_48 -> V_6 ;
unsigned int V_7 = V_36 -> V_37 . V_27 ;
struct V_3 * V_4 = V_36 -> V_37 . V_49 ;
int V_50 ;
F_16 ( & V_46 -> V_51 ) ;
F_16 ( & V_46 -> V_52 ) ;
V_50 = ( V_46 -> V_53 + 1 ) * V_54 ;
F_6 ( L_6 , V_16 , V_50 ) ;
while ( V_50 -- ) {
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return - V_56 ;
V_11 = F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
if ( V_11 ) {
F_18 ( V_2 ) ;
return V_11 ;
}
F_19 ( & V_2 -> V_57 , & V_46 -> V_51 ) ;
F_19 ( & V_2 -> V_58 , & V_46 -> V_52 ) ;
V_2 -> V_59 = F_13 ;
}
return 0 ;
}
static int
F_20 ( struct V_35 * V_36 , struct V_60 * V_61 ,
int V_62 , bool V_63 )
{
struct V_17 * V_18 = & V_36 -> V_37 ;
struct V_5 * V_6 = V_18 -> V_48 -> V_6 ;
enum V_64 V_65 = F_21 ( V_63 ) ;
struct V_60 * V_66 = V_61 ;
struct V_1 * V_67 = V_66 -> V_68 ;
struct V_8 * V_10 = & V_67 -> V_2 . V_10 ;
struct V_69 * V_70 = V_10 -> V_12 ;
struct V_71 V_72 , * V_73 ;
T_2 V_74 ;
int V_75 , V_76 ;
int V_50 , V_11 ;
int V_77 ;
T_3 V_78 ;
int V_79 ;
V_76 = F_22 ( V_66 -> V_80 ) ;
V_66 -> V_80 -= V_76 ;
V_66 -> V_81 += V_76 ;
V_75 = - V_76 ;
if ( V_62 > V_18 -> V_27 )
V_62 = V_18 -> V_27 ;
for ( V_79 = V_50 = 0 ; V_50 < V_62 ; ) {
F_23 ( V_6 , V_61 , V_65 ) ;
V_78 = V_61 -> V_82 ;
for ( V_77 = V_61 -> V_81 ; V_77 > 0 ; V_77 -= V_83 ) {
V_10 -> V_14 -> V_84 [ V_79 ++ ] = V_78 ;
V_78 += V_83 ;
}
V_75 += V_61 -> V_81 ;
++ V_61 ;
++ V_50 ;
if ( ( V_50 < V_62 && F_22 ( V_61 -> V_80 ) ) ||
F_22 ( ( V_61 - 1 ) -> V_80 + ( V_61 - 1 ) -> V_81 ) )
break;
}
F_6 ( L_7 ,
V_16 , V_67 , V_50 , V_75 ) ;
V_10 -> V_43 = V_85 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_42 = ( unsigned long ) ( void * ) V_67 ;
V_72 . V_86 = V_87 ;
V_72 . V_88 . V_89 . V_90 = V_66 -> V_82 + V_76 ;
V_72 . V_88 . V_89 . V_84 = V_10 -> V_14 ;
V_72 . V_88 . V_89 . V_91 = V_92 ;
V_72 . V_88 . V_89 . V_93 = V_79 ;
V_72 . V_88 . V_89 . V_94 = V_75 ;
V_72 . V_88 . V_89 . V_95 = V_63 ?
V_96 | V_97 :
V_98 ;
V_74 = ( T_2 ) ( V_70 -> V_99 & 0x000000FF ) ;
F_24 ( V_70 , ++ V_74 ) ;
V_72 . V_88 . V_89 . V_99 = V_70 -> V_99 ;
F_25 ( & V_36 -> V_100 ) ;
V_11 = F_26 ( V_18 -> V_48 -> V_101 , & V_72 , & V_73 ) ;
if ( V_11 )
goto V_102;
V_66 -> V_103 = V_70 -> V_99 ;
V_66 -> V_104 = V_66 -> V_82 + V_76 ;
V_66 -> V_105 = V_50 ;
V_66 -> V_81 = V_75 ;
return V_50 ;
V_102:
F_6 ( L_8 , V_16 , V_11 ) ;
F_24 ( V_70 , -- V_74 ) ;
V_10 -> V_43 = V_106 ;
while ( V_50 -- )
F_27 ( V_6 , -- V_61 ) ;
return V_11 ;
}
static int
F_28 ( struct V_35 * V_36 , struct V_60 * V_61 )
{
struct V_60 * V_66 = V_61 ;
struct V_17 * V_18 = & V_36 -> V_37 ;
struct V_71 V_107 , * V_73 ;
int V_11 , V_62 = V_61 -> V_105 ;
struct V_5 * V_6 ;
V_66 -> V_68 -> V_2 . V_10 . V_43 = V_106 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
V_107 . V_42 = ( unsigned long ) ( void * ) V_66 -> V_68 ;
V_107 . V_86 = V_108 ;
V_107 . V_109 . V_110 = V_66 -> V_68 -> V_2 . V_10 . V_12 -> V_99 ;
F_25 ( & V_36 -> V_100 ) ;
F_29 ( & V_18 -> V_111 ) ;
V_6 = V_18 -> V_48 -> V_6 ;
while ( V_66 -> V_105 -- )
F_27 ( V_6 , V_61 ++ ) ;
V_11 = F_26 ( V_18 -> V_48 -> V_101 , & V_107 , & V_73 ) ;
F_30 ( & V_18 -> V_111 ) ;
if ( V_11 )
goto V_112;
return V_62 ;
V_112:
V_66 -> V_68 -> V_2 . V_10 . V_43 = V_44 ;
F_6 ( L_8 , V_16 , V_11 ) ;
return V_62 ;
}
static void
F_31 ( struct V_35 * V_36 )
{
struct V_45 * V_46 = & V_36 -> V_47 ;
struct V_5 * V_6 = V_36 -> V_37 . V_48 -> V_6 ;
unsigned int V_7 = V_36 -> V_37 . V_27 ;
struct V_3 * V_4 = V_36 -> V_37 . V_49 ;
struct V_1 * V_2 ;
int V_11 ;
F_32 (r, &buf->rb_all, mw_all) {
if ( V_2 -> V_2 . V_10 . V_43 == V_106 )
continue;
F_8 ( V_2 ) ;
V_11 = F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
if ( V_11 ) {
F_6 ( L_9 ,
V_16 , V_2 ,
( V_2 -> V_2 . V_10 . V_43 == V_44 ?
L_10 : L_11 ) ) ;
continue;
}
V_2 -> V_2 . V_10 . V_43 = V_106 ;
}
}
static void
F_33 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
while ( ! F_34 ( & V_46 -> V_52 ) ) {
V_2 = F_35 ( V_46 -> V_52 . V_113 , struct V_1 , V_58 ) ;
F_36 ( & V_2 -> V_58 ) ;
F_8 ( V_2 ) ;
F_18 ( V_2 ) ;
}
}
