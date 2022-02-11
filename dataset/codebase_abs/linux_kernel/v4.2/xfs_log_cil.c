static struct V_1 *
F_1 (
struct V_2 * log )
{
struct V_1 * V_3 ;
V_3 = F_2 ( log , 0 , 1 , V_4 , 0 ,
V_5 | V_6 ) ;
V_3 -> V_7 = V_8 ;
V_3 -> V_9 = 0 ;
return V_3 ;
}
void
F_3 (
struct V_2 * log )
{
log -> V_10 -> V_11 -> V_12 = F_1 ( log ) ;
log -> V_10 -> V_11 -> V_13 = 1 ;
}
STATIC void
F_4 (
struct V_2 * log ,
struct V_14 * V_15 ,
struct V_14 * V_16 ,
int * V_17 ,
int * V_18 )
{
if ( V_15 -> V_19 != V_20 ) {
* V_17 += V_15 -> V_21 ;
* V_18 += V_15 -> V_22 ;
}
if ( ! V_16 )
V_15 -> V_23 -> V_24 -> V_25 ( V_15 -> V_23 ) ;
else if ( V_16 != V_15 ) {
ASSERT ( V_15 -> V_19 != V_20 ) ;
* V_17 -= V_16 -> V_21 ;
* V_18 -= V_16 -> V_22 ;
F_5 ( V_16 ) ;
}
V_15 -> V_23 -> V_26 = V_15 ;
if ( ! V_15 -> V_23 -> V_27 )
V_15 -> V_23 -> V_27 = log -> V_10 -> V_11 -> V_13 ;
}
static void
F_6 (
struct V_2 * log ,
struct V_28 * V_29 ,
int * V_17 ,
int * V_18 )
{
struct V_30 * V_31 ;
if ( F_7 ( & V_29 -> V_32 ) ) {
ASSERT ( 0 ) ;
return;
}
F_8 (lidp, &tp->t_items, lid_trans) {
struct V_33 * V_34 = V_31 -> V_35 ;
struct V_14 * V_15 ;
struct V_14 * V_16 ;
int V_36 = 0 ;
int V_37 = 0 ;
int V_38 ;
bool V_39 = false ;
if ( ! ( V_31 -> V_40 & V_41 ) )
continue;
V_34 -> V_24 -> V_42 ( V_34 , & V_36 , & V_37 ) ;
if ( ! V_36 )
continue;
if ( V_36 == V_20 ) {
V_39 = true ;
V_36 = 0 ;
V_37 = 0 ;
}
V_37 += V_36 * sizeof( V_43 ) ;
V_37 = F_9 ( V_37 , sizeof( V_43 ) ) ;
V_16 = V_34 -> V_26 ;
V_38 = V_37 +
F_9 ( ( sizeof( struct V_14 ) +
V_36 * sizeof( struct V_44 ) ) ,
sizeof( V_43 ) ) ;
if ( V_34 -> V_26 && V_38 <= V_34 -> V_26 -> V_45 ) {
V_15 = V_34 -> V_26 ;
V_15 -> V_46 = NULL ;
if ( V_39 )
goto V_47;
* V_18 -= V_15 -> V_22 ;
* V_17 -= V_15 -> V_21 ;
} else {
V_15 = F_10 ( V_38 , V_5 | V_6 ) ;
V_15 -> V_23 = V_34 ;
V_15 -> V_45 = V_38 ;
if ( V_39 ) {
ASSERT ( V_34 -> V_26 == NULL ) ;
V_15 -> V_19 = V_20 ;
goto V_47;
}
V_15 -> V_48 = (struct V_44 * ) & V_15 [ 1 ] ;
}
V_15 -> V_22 = V_36 ;
V_15 -> V_19 = 0 ;
V_15 -> V_21 = 0 ;
V_15 -> V_49 = ( char * ) V_15 + V_38 - V_37 ;
ASSERT ( F_11 ( ( unsigned long ) V_15 -> V_49 , sizeof( V_43 ) ) ) ;
V_34 -> V_24 -> V_50 ( V_34 , V_15 ) ;
V_47:
ASSERT ( V_15 -> V_19 <= V_37 ) ;
F_4 ( log , V_15 , V_16 , V_17 , V_18 ) ;
}
}
static void
F_12 (
struct V_2 * log ,
struct V_28 * V_29 )
{
struct V_51 * V_52 = log -> V_10 ;
struct V_53 * V_54 = V_52 -> V_11 ;
struct V_30 * V_31 ;
int V_55 = 0 ;
int V_18 = 0 ;
int V_56 ;
ASSERT ( V_29 ) ;
F_6 ( log , V_29 , & V_55 , & V_18 ) ;
F_13 ( & V_52 -> V_57 ) ;
F_8 (lidp, &tp->t_items, lid_trans) {
struct V_33 * V_34 = V_31 -> V_35 ;
if ( ! ( V_31 -> V_40 & V_41 ) )
continue;
F_14 ( & V_34 -> V_58 , & V_52 -> V_59 ) ;
}
V_55 += V_18 * sizeof( V_60 ) ;
V_54 -> V_61 += V_18 ;
if ( ! F_7 ( & V_29 -> V_62 ) )
F_15 ( & V_29 -> V_62 , & V_54 -> V_63 ) ;
if ( V_54 -> V_12 -> V_9 == 0 ) {
V_54 -> V_12 -> V_9 = V_54 -> V_12 -> V_64 ;
V_29 -> V_65 -> V_9 -= V_54 -> V_12 -> V_64 ;
}
V_56 = log -> V_66 - log -> V_67 ;
if ( V_55 > 0 && ( V_54 -> V_68 / V_56 !=
( V_54 -> V_68 + V_55 ) / V_56 ) ) {
int V_69 ;
V_69 = ( V_55 + V_56 - 1 ) / V_56 ;
V_69 *= log -> V_67 + sizeof( struct V_70 ) ;
V_54 -> V_12 -> V_64 += V_69 ;
V_54 -> V_12 -> V_9 += V_69 ;
V_29 -> V_65 -> V_9 -= V_69 ;
ASSERT ( V_29 -> V_65 -> V_9 >= V_55 ) ;
}
V_29 -> V_65 -> V_9 -= V_55 ;
V_54 -> V_68 += V_55 ;
F_16 ( & V_52 -> V_57 ) ;
}
static void
F_17 (
struct V_14 * V_71 )
{
struct V_14 * V_15 ;
for ( V_15 = V_71 ; V_15 ; ) {
struct V_14 * V_72 = V_15 -> V_46 ;
F_5 ( V_15 ) ;
V_15 = V_72 ;
}
}
static void
F_18 (
void * args ,
int abort )
{
struct V_53 * V_54 = args ;
struct V_73 * V_74 = V_54 -> V_52 -> V_75 -> V_76 ;
F_19 ( V_54 -> V_52 -> V_75 -> V_77 , V_54 -> V_78 ,
V_54 -> V_79 , abort ) ;
F_20 ( & V_54 -> V_63 ) ;
F_21 ( V_74 , & V_54 -> V_63 ,
( V_74 -> V_80 & V_81 ) && ! abort ) ;
F_13 ( & V_54 -> V_52 -> V_82 ) ;
if ( abort )
F_22 ( & V_54 -> V_52 -> V_83 ) ;
F_23 ( & V_54 -> V_84 ) ;
F_16 ( & V_54 -> V_52 -> V_82 ) ;
F_17 ( V_54 -> V_78 ) ;
if ( ! F_7 ( & V_54 -> V_63 ) ) {
ASSERT ( V_74 -> V_80 & V_81 ) ;
F_24 ( V_74 , & V_54 -> V_63 ) ;
F_21 ( V_74 , & V_54 -> V_63 , false ) ;
}
F_5 ( V_54 ) ;
}
STATIC int
F_25 (
struct V_2 * log )
{
struct V_51 * V_52 = log -> V_10 ;
struct V_14 * V_15 ;
struct V_53 * V_54 ;
struct V_53 * V_85 ;
struct V_86 * V_87 ;
struct V_1 * V_3 ;
int V_88 ;
int error = 0 ;
struct V_89 V_90 ;
struct V_44 V_91 ;
struct V_14 V_92 = { NULL } ;
T_1 V_93 ;
T_1 V_94 ;
if ( ! V_52 )
return 0 ;
V_85 = F_10 ( sizeof( * V_85 ) , V_5 | V_6 ) ;
V_85 -> V_12 = F_1 ( log ) ;
F_26 ( & V_52 -> V_95 ) ;
V_54 = V_52 -> V_11 ;
F_13 ( & V_52 -> V_82 ) ;
V_94 = V_52 -> V_96 ;
ASSERT ( V_94 <= V_54 -> V_13 ) ;
if ( F_7 ( & V_52 -> V_59 ) ) {
V_52 -> V_96 = 0 ;
F_16 ( & V_52 -> V_82 ) ;
goto V_97;
}
if ( V_94 < V_52 -> V_11 -> V_13 ) {
F_16 ( & V_52 -> V_82 ) ;
goto V_97;
}
F_27 ( & V_54 -> V_84 , & V_52 -> V_98 ) ;
F_16 ( & V_52 -> V_82 ) ;
V_15 = NULL ;
V_88 = 0 ;
while ( ! F_7 ( & V_52 -> V_59 ) ) {
struct V_33 * V_99 ;
V_99 = F_28 ( & V_52 -> V_59 ,
struct V_33 , V_58 ) ;
F_29 ( & V_99 -> V_58 ) ;
if ( ! V_54 -> V_78 )
V_54 -> V_78 = V_99 -> V_26 ;
else
V_15 -> V_46 = V_99 -> V_26 ;
V_15 = V_99 -> V_26 ;
V_99 -> V_26 = NULL ;
V_88 += V_15 -> V_22 ;
}
F_30 ( & V_85 -> V_84 ) ;
F_30 ( & V_85 -> V_63 ) ;
V_85 -> V_13 = V_54 -> V_13 + 1 ;
V_85 -> V_52 = V_52 ;
V_52 -> V_11 = V_85 ;
F_13 ( & V_52 -> V_82 ) ;
V_52 -> V_100 = V_85 -> V_13 ;
F_16 ( & V_52 -> V_82 ) ;
F_31 ( & V_52 -> V_95 ) ;
V_3 = V_54 -> V_12 ;
V_90 . V_101 = V_102 ;
V_90 . V_103 = V_8 ;
V_90 . V_104 = V_3 -> V_105 ;
V_90 . V_106 = V_88 ;
V_91 . V_107 = & V_90 ;
V_91 . V_108 = sizeof( V_109 ) ;
V_91 . V_110 = V_111 ;
V_3 -> V_9 -= V_91 . V_108 + sizeof( V_60 ) ;
V_92 . V_22 = 1 ;
V_92 . V_48 = & V_91 ;
V_92 . V_46 = V_54 -> V_78 ;
error = F_32 ( log , & V_92 , V_3 , & V_54 -> V_79 , NULL , 0 ) ;
if ( error )
goto V_112;
V_113:
F_13 ( & V_52 -> V_82 ) ;
F_8 (new_ctx, &cil->xc_committing, committing) {
if ( F_33 ( log ) ) {
F_16 ( & V_52 -> V_82 ) ;
goto V_112;
}
if ( V_85 -> V_13 >= V_54 -> V_13 )
continue;
if ( ! V_85 -> V_93 ) {
F_34 ( & V_52 -> V_83 , & V_52 -> V_82 ) ;
goto V_113;
}
}
F_16 ( & V_52 -> V_82 ) ;
V_93 = F_35 ( log -> V_76 , V_3 , & V_87 , false ) ;
if ( V_93 == - 1 )
goto V_114;
V_54 -> V_115 . V_116 = F_18 ;
V_54 -> V_115 . V_117 = V_54 ;
error = F_36 ( log -> V_76 , V_87 , & V_54 -> V_115 ) ;
if ( error )
goto V_114;
F_13 ( & V_52 -> V_82 ) ;
V_54 -> V_93 = V_93 ;
F_22 ( & V_52 -> V_83 ) ;
F_16 ( & V_52 -> V_82 ) ;
return F_37 ( log -> V_76 , V_87 ) ;
V_97:
F_31 ( & V_52 -> V_95 ) ;
F_38 ( V_85 -> V_12 ) ;
F_5 ( V_85 ) ;
return 0 ;
V_112:
F_38 ( V_3 ) ;
V_114:
F_18 ( V_54 , V_118 ) ;
return - V_119 ;
}
static void
F_39 (
struct V_120 * V_121 )
{
struct V_51 * V_52 = F_40 ( V_121 , struct V_51 ,
V_122 ) ;
F_25 ( V_52 -> V_75 ) ;
}
static void
F_41 (
struct V_2 * log )
{
struct V_51 * V_52 = log -> V_10 ;
ASSERT ( ! F_7 ( & V_52 -> V_59 ) ) ;
if ( V_52 -> V_11 -> V_68 < F_42 ( log ) )
return;
F_13 ( & V_52 -> V_82 ) ;
if ( V_52 -> V_96 < V_52 -> V_100 ) {
V_52 -> V_96 = V_52 -> V_100 ;
F_43 ( log -> V_76 -> V_123 , & V_52 -> V_122 ) ;
}
F_16 ( & V_52 -> V_82 ) ;
}
static void
F_44 (
struct V_2 * log ,
T_1 V_94 )
{
struct V_51 * V_52 = log -> V_10 ;
if ( ! V_52 )
return;
ASSERT ( V_94 && V_94 <= V_52 -> V_100 ) ;
F_45 ( & V_52 -> V_122 ) ;
F_13 ( & V_52 -> V_82 ) ;
if ( F_7 ( & V_52 -> V_59 ) || V_94 <= V_52 -> V_96 ) {
F_16 ( & V_52 -> V_82 ) ;
return;
}
V_52 -> V_96 = V_94 ;
F_43 ( log -> V_76 -> V_123 , & V_52 -> V_122 ) ;
F_16 ( & V_52 -> V_82 ) ;
}
bool
F_46 (
struct V_2 * log )
{
struct V_51 * V_52 = log -> V_10 ;
bool V_124 = false ;
F_13 ( & V_52 -> V_82 ) ;
if ( F_7 ( & V_52 -> V_59 ) )
V_124 = true ;
F_16 ( & V_52 -> V_82 ) ;
return V_124 ;
}
void
F_47 (
struct V_73 * V_74 ,
struct V_28 * V_29 ,
T_1 * V_93 ,
bool V_125 )
{
struct V_2 * log = V_74 -> V_126 ;
struct V_51 * V_52 = log -> V_10 ;
F_48 ( & V_52 -> V_95 ) ;
F_12 ( log , V_29 ) ;
if ( V_29 -> V_65 -> V_9 < 0 )
F_49 ( V_74 , V_29 -> V_65 ) ;
V_29 -> V_127 = V_52 -> V_11 -> V_13 ;
if ( V_93 )
* V_93 = V_29 -> V_127 ;
F_35 ( V_74 , V_29 -> V_65 , NULL , V_125 ) ;
F_50 ( V_29 ) ;
F_51 ( V_29 , V_29 -> V_127 , false ) ;
F_41 ( log ) ;
F_52 ( & V_52 -> V_95 ) ;
}
T_1
F_53 (
struct V_2 * log ,
T_1 V_13 )
{
struct V_51 * V_52 = log -> V_10 ;
struct V_53 * V_54 ;
T_1 V_93 = V_128 ;
ASSERT ( V_13 <= V_52 -> V_100 ) ;
V_113:
F_44 ( log , V_13 ) ;
F_13 ( & V_52 -> V_82 ) ;
F_8 (ctx, &cil->xc_committing, committing) {
if ( F_33 ( log ) )
goto V_129;
if ( V_54 -> V_13 > V_13 )
continue;
if ( ! V_54 -> V_93 ) {
F_34 ( & V_52 -> V_83 , & V_52 -> V_82 ) ;
goto V_113;
}
if ( V_54 -> V_13 != V_13 )
continue;
V_93 = V_54 -> V_93 ;
}
if ( V_13 == V_52 -> V_100 &&
! F_7 ( & V_52 -> V_59 ) ) {
F_16 ( & V_52 -> V_82 ) ;
goto V_113;
}
F_16 ( & V_52 -> V_82 ) ;
return V_93 ;
V_129:
F_16 ( & V_52 -> V_82 ) ;
return 0 ;
}
bool
F_54 (
struct V_33 * V_34 )
{
struct V_53 * V_54 ;
if ( F_7 ( & V_34 -> V_58 ) )
return false ;
V_54 = V_34 -> V_130 -> V_126 -> V_10 -> V_11 ;
if ( F_55 ( V_34 -> V_27 , V_54 -> V_13 ) != 0 )
return false ;
return true ;
}
int
F_56 (
struct V_2 * log )
{
struct V_51 * V_52 ;
struct V_53 * V_54 ;
V_52 = F_10 ( sizeof( * V_52 ) , V_5 | V_131 ) ;
if ( ! V_52 )
return - V_132 ;
V_54 = F_10 ( sizeof( * V_54 ) , V_5 | V_131 ) ;
if ( ! V_54 ) {
F_5 ( V_52 ) ;
return - V_132 ;
}
F_57 ( & V_52 -> V_122 , F_39 ) ;
F_30 ( & V_52 -> V_59 ) ;
F_30 ( & V_52 -> V_98 ) ;
F_58 ( & V_52 -> V_57 ) ;
F_58 ( & V_52 -> V_82 ) ;
F_59 ( & V_52 -> V_95 ) ;
F_60 ( & V_52 -> V_83 ) ;
F_30 ( & V_54 -> V_84 ) ;
F_30 ( & V_54 -> V_63 ) ;
V_54 -> V_13 = 1 ;
V_54 -> V_52 = V_52 ;
V_52 -> V_11 = V_54 ;
V_52 -> V_100 = V_54 -> V_13 ;
V_52 -> V_75 = log ;
log -> V_10 = V_52 ;
return 0 ;
}
void
F_61 (
struct V_2 * log )
{
if ( log -> V_10 -> V_11 ) {
if ( log -> V_10 -> V_11 -> V_12 )
F_38 ( log -> V_10 -> V_11 -> V_12 ) ;
F_5 ( log -> V_10 -> V_11 ) ;
}
ASSERT ( F_7 ( & log -> V_10 -> V_59 ) ) ;
F_5 ( log -> V_10 ) ;
}
