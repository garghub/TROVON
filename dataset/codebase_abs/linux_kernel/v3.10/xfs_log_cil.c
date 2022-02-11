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
log -> V_10 -> V_11 -> V_14 = F_4 ( log -> V_15 ,
log -> V_16 ) ;
}
static struct V_17 *
F_5 (
struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_17 * V_22 = NULL ;
struct V_17 * V_23 = NULL ;
if ( F_6 ( & V_19 -> V_24 ) ) {
ASSERT ( 0 ) ;
return NULL ;
}
F_7 (lidp, &tp->t_items, lid_trans) {
struct V_17 * V_25 ;
void * V_26 ;
int V_27 ;
int V_28 = 0 ;
T_1 V_29 ;
if ( ! ( V_21 -> V_30 & V_31 ) )
continue;
V_29 = F_8 ( V_21 -> V_32 ) ;
if ( ! V_29 )
continue;
V_25 = F_9 ( sizeof( * V_25 ) +
V_29 * sizeof( struct V_33 ) ,
V_5 | V_6 ) ;
V_25 -> V_34 = (struct V_33 * ) & V_25 [ 1 ] ;
V_25 -> V_35 = V_29 ;
V_25 -> V_36 = V_21 -> V_32 ;
F_10 ( V_25 -> V_36 , V_25 -> V_34 ) ;
for ( V_27 = 0 ; V_27 < V_25 -> V_35 ; V_27 ++ )
V_28 += V_25 -> V_34 [ V_27 ] . V_37 ;
V_25 -> V_38 = V_28 ;
V_25 -> V_39 = F_11 ( V_25 -> V_38 ,
V_5 | V_6 ) ;
V_26 = V_25 -> V_39 ;
for ( V_27 = 0 ; V_27 < V_25 -> V_35 ; V_27 ++ ) {
struct V_33 * V_40 = & V_25 -> V_34 [ V_27 ] ;
memcpy ( V_26 , V_40 -> V_41 , V_40 -> V_37 ) ;
V_40 -> V_41 = V_26 ;
V_26 += V_40 -> V_37 ;
}
ASSERT ( V_26 == V_25 -> V_39 + V_25 -> V_38 ) ;
if ( ! V_23 )
V_23 = V_25 ;
else
V_22 -> V_42 = V_25 ;
V_22 = V_25 ;
}
return V_23 ;
}
STATIC void
F_12 (
struct V_2 * log ,
struct V_17 * V_22 ,
int * V_28 ,
int * V_43 )
{
struct V_17 * V_44 = V_22 -> V_36 -> V_45 ;
if ( V_44 ) {
ASSERT ( ! F_6 ( & V_22 -> V_36 -> V_46 ) ) ;
ASSERT ( V_44 -> V_39 && V_44 -> V_38 && V_44 -> V_35 ) ;
* V_28 += V_22 -> V_38 - V_44 -> V_38 ;
* V_43 += V_22 -> V_35 - V_44 -> V_35 ;
F_13 ( V_44 -> V_39 ) ;
F_13 ( V_44 ) ;
} else {
ASSERT ( ! V_22 -> V_36 -> V_45 ) ;
ASSERT ( F_6 ( & V_22 -> V_36 -> V_46 ) ) ;
* V_28 += V_22 -> V_38 ;
* V_43 += V_22 -> V_35 ;
F_14 ( V_22 -> V_36 ) ;
}
V_22 -> V_36 -> V_45 = V_22 ;
if ( ! V_22 -> V_36 -> V_47 )
V_22 -> V_36 -> V_47 = log -> V_10 -> V_11 -> V_13 ;
}
static void
F_15 (
struct V_2 * log ,
struct V_17 * V_48 ,
struct V_1 * V_12 )
{
struct V_49 * V_50 = log -> V_10 ;
struct V_51 * V_52 = V_50 -> V_11 ;
struct V_17 * V_22 ;
int V_28 = 0 ;
int V_43 = 0 ;
int V_53 ;
ASSERT ( V_48 ) ;
for ( V_22 = V_48 ; V_22 ; V_22 = V_22 -> V_42 )
F_12 ( log , V_22 , & V_28 , & V_43 ) ;
V_28 += V_43 * sizeof( V_54 ) ;
F_16 ( & V_50 -> V_55 ) ;
for ( V_22 = V_48 ; V_22 ; V_22 = V_22 -> V_42 )
F_17 ( & V_22 -> V_36 -> V_46 , & V_50 -> V_56 ) ;
V_52 -> V_57 += V_43 ;
if ( V_52 -> V_12 -> V_9 == 0 ) {
ASSERT ( V_12 -> V_9 >= V_52 -> V_12 -> V_58 + V_28 ) ;
V_52 -> V_12 -> V_9 = V_52 -> V_12 -> V_58 ;
V_12 -> V_9 -= V_52 -> V_12 -> V_58 ;
}
V_53 = log -> V_59 - log -> V_60 ;
if ( V_28 > 0 && ( V_52 -> V_61 / V_53 !=
( V_52 -> V_61 + V_28 ) / V_53 ) ) {
int V_62 ;
V_62 = ( V_28 + V_53 - 1 ) / V_53 ;
V_62 *= log -> V_60 + sizeof( struct V_63 ) ;
V_52 -> V_12 -> V_58 += V_62 ;
V_52 -> V_12 -> V_9 += V_62 ;
V_12 -> V_9 -= V_62 ;
ASSERT ( V_12 -> V_9 >= V_28 ) ;
}
V_12 -> V_9 -= V_28 ;
V_52 -> V_61 += V_28 ;
F_18 ( & V_50 -> V_55 ) ;
}
static void
F_19 (
struct V_17 * V_48 )
{
struct V_17 * V_22 ;
for ( V_22 = V_48 ; V_22 ; ) {
struct V_17 * V_64 = V_22 -> V_42 ;
F_13 ( V_22 -> V_39 ) ;
F_13 ( V_22 ) ;
V_22 = V_64 ;
}
}
static void
F_20 (
void * args ,
int abort )
{
struct V_51 * V_52 = args ;
struct V_65 * V_66 = V_52 -> V_50 -> V_67 -> V_68 ;
F_21 ( V_52 -> V_50 -> V_67 -> V_69 , V_52 -> V_70 ,
V_52 -> V_71 , abort ) ;
F_22 ( & V_52 -> V_72 ) ;
F_23 ( V_66 , & V_52 -> V_72 ,
( V_66 -> V_73 & V_74 ) && ! abort ) ;
F_16 ( & V_52 -> V_50 -> V_55 ) ;
F_24 ( & V_52 -> V_75 ) ;
F_18 ( & V_52 -> V_50 -> V_55 ) ;
F_19 ( V_52 -> V_70 ) ;
if ( ! F_6 ( & V_52 -> V_72 ) ) {
ASSERT ( V_66 -> V_73 & V_74 ) ;
F_25 ( V_66 , & V_52 -> V_72 ) ;
F_23 ( V_66 , & V_52 -> V_72 , false ) ;
}
F_13 ( V_52 ) ;
}
STATIC int
F_26 (
struct V_2 * log )
{
struct V_49 * V_50 = log -> V_10 ;
struct V_17 * V_22 ;
struct V_51 * V_52 ;
struct V_51 * V_76 ;
struct V_77 * V_78 ;
struct V_1 * V_3 ;
int V_79 ;
int V_80 ;
int V_28 ;
int error = 0 ;
struct V_81 V_82 ;
struct V_33 V_83 ;
struct V_17 V_84 = { NULL } ;
T_2 V_14 ;
T_2 V_85 ;
if ( ! V_50 )
return 0 ;
V_76 = F_9 ( sizeof( * V_76 ) , V_5 | V_6 ) ;
V_76 -> V_12 = F_1 ( log ) ;
F_27 ( & V_50 -> V_86 ) ;
V_52 = V_50 -> V_11 ;
F_16 ( & V_50 -> V_55 ) ;
V_85 = V_50 -> V_87 ;
ASSERT ( V_85 <= V_52 -> V_13 ) ;
if ( F_6 ( & V_50 -> V_56 ) ) {
V_50 -> V_87 = 0 ;
F_18 ( & V_50 -> V_55 ) ;
goto V_88;
}
F_18 ( & V_50 -> V_55 ) ;
if ( V_85 < V_50 -> V_11 -> V_13 )
goto V_88;
V_22 = NULL ;
V_79 = 0 ;
V_80 = 0 ;
V_28 = 0 ;
while ( ! F_6 ( & V_50 -> V_56 ) ) {
struct V_89 * V_90 ;
int V_91 ;
V_90 = F_28 ( & V_50 -> V_56 ,
struct V_89 , V_46 ) ;
F_29 ( & V_90 -> V_46 ) ;
if ( ! V_52 -> V_70 )
V_52 -> V_70 = V_90 -> V_45 ;
else
V_22 -> V_42 = V_90 -> V_45 ;
V_22 = V_90 -> V_45 ;
V_90 -> V_45 = NULL ;
V_79 ++ ;
V_80 += V_22 -> V_35 ;
for ( V_91 = 0 ; V_91 < V_22 -> V_35 ; V_91 ++ )
V_28 += V_22 -> V_34 [ V_91 ] . V_37 ;
}
F_30 ( & V_76 -> V_75 ) ;
F_30 ( & V_76 -> V_72 ) ;
V_76 -> V_13 = V_52 -> V_13 + 1 ;
V_76 -> V_50 = V_50 ;
V_50 -> V_11 = V_76 ;
V_50 -> V_92 = V_76 -> V_13 ;
F_16 ( & V_50 -> V_55 ) ;
F_31 ( & V_52 -> V_75 , & V_50 -> V_93 ) ;
F_18 ( & V_50 -> V_55 ) ;
F_32 ( & V_50 -> V_86 ) ;
V_3 = V_52 -> V_12 ;
V_82 . V_94 = V_95 ;
V_82 . V_96 = V_8 ;
V_82 . V_97 = V_3 -> V_98 ;
V_82 . V_99 = V_80 ;
V_83 . V_41 = & V_82 ;
V_83 . V_37 = sizeof( V_100 ) ;
V_83 . V_101 = V_102 ;
V_3 -> V_9 -= V_83 . V_37 + sizeof( V_54 ) ;
V_84 . V_35 = 1 ;
V_84 . V_34 = & V_83 ;
V_84 . V_42 = V_52 -> V_70 ;
error = F_33 ( log , & V_84 , V_3 , & V_52 -> V_71 , NULL , 0 ) ;
if ( error )
goto V_103;
V_104:
F_16 ( & V_50 -> V_55 ) ;
F_7 (new_ctx, &cil->xc_committing, committing) {
if ( V_76 -> V_13 >= V_52 -> V_13 )
continue;
if ( ! V_76 -> V_14 ) {
F_34 ( & V_50 -> V_105 , & V_50 -> V_55 ) ;
goto V_104;
}
}
F_18 ( & V_50 -> V_55 ) ;
V_14 = F_35 ( log -> V_68 , V_3 , & V_78 , 0 ) ;
if ( V_14 == - 1 )
goto V_106;
V_52 -> V_107 . V_108 = F_20 ;
V_52 -> V_107 . V_109 = V_52 ;
error = F_36 ( log -> V_68 , V_78 , & V_52 -> V_107 ) ;
if ( error )
goto V_106;
F_16 ( & V_50 -> V_55 ) ;
V_52 -> V_14 = V_14 ;
F_37 ( & V_50 -> V_105 ) ;
F_18 ( & V_50 -> V_55 ) ;
return F_38 ( log -> V_68 , V_78 ) ;
V_88:
F_32 ( & V_50 -> V_86 ) ;
F_39 ( V_76 -> V_12 ) ;
F_13 ( V_76 ) ;
return 0 ;
V_103:
F_39 ( V_3 ) ;
V_106:
F_20 ( V_52 , V_110 ) ;
return F_40 ( V_111 ) ;
}
static void
F_41 (
struct V_112 * V_113 )
{
struct V_49 * V_50 = F_42 ( V_113 , struct V_49 ,
V_114 ) ;
F_26 ( V_50 -> V_67 ) ;
}
static void
F_43 (
struct V_2 * log )
{
struct V_49 * V_50 = log -> V_10 ;
ASSERT ( ! F_6 ( & V_50 -> V_56 ) ) ;
if ( V_50 -> V_11 -> V_61 < F_44 ( log ) )
return;
F_16 ( & V_50 -> V_55 ) ;
if ( V_50 -> V_87 < V_50 -> V_92 ) {
V_50 -> V_87 = V_50 -> V_92 ;
F_45 ( log -> V_68 -> V_115 , & V_50 -> V_114 ) ;
}
F_18 ( & V_50 -> V_55 ) ;
}
static void
F_46 (
struct V_2 * log ,
T_2 V_85 )
{
struct V_49 * V_50 = log -> V_10 ;
if ( ! V_50 )
return;
ASSERT ( V_85 && V_85 <= V_50 -> V_92 ) ;
F_47 ( & V_50 -> V_114 ) ;
F_16 ( & V_50 -> V_55 ) ;
if ( F_6 ( & V_50 -> V_56 ) || V_85 <= V_50 -> V_87 ) {
F_18 ( & V_50 -> V_55 ) ;
return;
}
V_50 -> V_87 = V_85 ;
F_18 ( & V_50 -> V_55 ) ;
F_26 ( log ) ;
}
int
F_48 (
struct V_65 * V_66 ,
struct V_18 * V_19 ,
T_2 * V_14 ,
int V_116 )
{
struct V_2 * log = V_66 -> V_117 ;
int V_118 = 0 ;
struct V_17 * V_48 ;
if ( V_116 & V_119 )
V_118 = V_120 ;
V_48 = F_5 ( V_19 ) ;
if ( ! V_48 )
return V_121 ;
F_49 ( & log -> V_10 -> V_86 ) ;
if ( V_14 )
* V_14 = log -> V_10 -> V_11 -> V_13 ;
F_15 ( log , V_48 , V_19 -> V_122 ) ;
if ( V_19 -> V_122 -> V_9 < 0 )
F_50 ( log -> V_68 , V_19 -> V_122 ) ;
if ( ! F_6 ( & V_19 -> V_123 ) ) {
F_16 ( & log -> V_10 -> V_55 ) ;
F_51 ( & V_19 -> V_123 ,
& log -> V_10 -> V_11 -> V_72 ) ;
F_18 ( & log -> V_10 -> V_55 ) ;
}
V_19 -> V_124 = * V_14 ;
F_35 ( V_66 , V_19 -> V_122 , NULL , V_118 ) ;
F_52 ( V_19 ) ;
F_53 ( V_19 , * V_14 , 0 ) ;
F_43 ( log ) ;
F_54 ( & log -> V_10 -> V_86 ) ;
return 0 ;
}
T_2
F_55 (
struct V_2 * log ,
T_2 V_13 )
{
struct V_49 * V_50 = log -> V_10 ;
struct V_51 * V_52 ;
T_2 V_14 = V_125 ;
ASSERT ( V_13 <= V_50 -> V_92 ) ;
F_46 ( log , V_13 ) ;
V_104:
F_16 ( & V_50 -> V_55 ) ;
F_7 (ctx, &cil->xc_committing, committing) {
if ( V_52 -> V_13 > V_13 )
continue;
if ( ! V_52 -> V_14 ) {
F_34 ( & V_50 -> V_105 , & V_50 -> V_55 ) ;
goto V_104;
}
if ( V_52 -> V_13 != V_13 )
continue;
V_14 = V_52 -> V_14 ;
}
F_18 ( & V_50 -> V_55 ) ;
return V_14 ;
}
bool
F_56 (
struct V_89 * V_126 )
{
struct V_51 * V_52 ;
if ( F_6 ( & V_126 -> V_46 ) )
return false ;
V_52 = V_126 -> V_127 -> V_117 -> V_10 -> V_11 ;
if ( F_57 ( V_126 -> V_47 , V_52 -> V_13 ) != 0 )
return false ;
return true ;
}
int
F_58 (
struct V_2 * log )
{
struct V_49 * V_50 ;
struct V_51 * V_52 ;
V_50 = F_9 ( sizeof( * V_50 ) , V_5 | V_128 ) ;
if ( ! V_50 )
return V_121 ;
V_52 = F_9 ( sizeof( * V_52 ) , V_5 | V_128 ) ;
if ( ! V_52 ) {
F_13 ( V_50 ) ;
return V_121 ;
}
F_59 ( & V_50 -> V_114 , F_41 ) ;
F_30 ( & V_50 -> V_56 ) ;
F_30 ( & V_50 -> V_93 ) ;
F_60 ( & V_50 -> V_55 ) ;
F_61 ( & V_50 -> V_86 ) ;
F_62 ( & V_50 -> V_105 ) ;
F_30 ( & V_52 -> V_75 ) ;
F_30 ( & V_52 -> V_72 ) ;
V_52 -> V_13 = 1 ;
V_52 -> V_50 = V_50 ;
V_50 -> V_11 = V_52 ;
V_50 -> V_92 = V_52 -> V_13 ;
V_50 -> V_67 = log ;
log -> V_10 = V_50 ;
return 0 ;
}
void
F_63 (
struct V_2 * log )
{
if ( log -> V_10 -> V_11 ) {
if ( log -> V_10 -> V_11 -> V_12 )
F_39 ( log -> V_10 -> V_11 -> V_12 ) ;
F_13 ( log -> V_10 -> V_11 ) ;
}
ASSERT ( F_6 ( & log -> V_10 -> V_56 ) ) ;
F_13 ( log -> V_10 ) ;
}
