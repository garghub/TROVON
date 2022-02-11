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
STATIC void
F_5 (
struct V_2 * log ,
struct V_17 * V_18 ,
struct V_17 * V_19 ,
int * V_20 ,
int * V_21 )
{
if ( V_18 -> V_22 != V_23 ) {
* V_20 += V_18 -> V_22 ;
* V_21 += V_18 -> V_24 ;
}
if ( ! V_19 )
V_18 -> V_25 -> V_26 -> V_27 ( V_18 -> V_25 ) ;
else if ( V_19 != V_18 ) {
ASSERT ( V_18 -> V_22 != V_23 ) ;
* V_20 -= V_19 -> V_22 ;
* V_21 -= V_19 -> V_24 ;
F_6 ( V_19 ) ;
}
V_18 -> V_25 -> V_28 = V_18 ;
if ( ! V_18 -> V_25 -> V_29 )
V_18 -> V_25 -> V_29 = log -> V_10 -> V_11 -> V_13 ;
}
static void
F_7 (
struct V_2 * log ,
struct V_30 * V_31 ,
int * V_20 ,
int * V_21 )
{
struct V_32 * V_33 ;
if ( F_8 ( & V_31 -> V_34 ) ) {
ASSERT ( 0 ) ;
return;
}
F_9 (lidp, &tp->t_items, lid_trans) {
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_17 * V_18 ;
struct V_17 * V_19 ;
int V_38 = 0 ;
int V_39 = 0 ;
int V_40 ;
bool V_41 = false ;
if ( ! ( V_33 -> V_42 & V_43 ) )
continue;
V_36 -> V_26 -> V_44 ( V_36 , & V_38 , & V_39 ) ;
if ( ! V_38 )
continue;
if ( V_38 == V_23 ) {
V_41 = true ;
V_38 = 0 ;
V_39 = 0 ;
}
V_39 += V_38 * sizeof( V_45 ) ;
V_39 = F_10 ( V_39 , sizeof( V_45 ) ) ;
V_19 = V_36 -> V_28 ;
V_40 = V_39 +
F_10 ( ( sizeof( struct V_17 ) +
V_38 * sizeof( struct V_46 ) ) ,
sizeof( V_45 ) ) ;
if ( V_36 -> V_28 && V_40 <= V_36 -> V_28 -> V_47 ) {
V_18 = V_36 -> V_28 ;
V_18 -> V_48 = NULL ;
if ( V_41 )
goto V_49;
* V_21 -= V_18 -> V_24 ;
* V_20 -= V_18 -> V_22 ;
} else {
V_18 = F_11 ( V_40 , V_5 | V_6 ) ;
V_18 -> V_25 = V_36 ;
V_18 -> V_47 = V_40 ;
if ( V_41 ) {
ASSERT ( V_36 -> V_28 == NULL ) ;
V_18 -> V_22 = V_23 ;
goto V_49;
}
V_18 -> V_50 = (struct V_46 * ) & V_18 [ 1 ] ;
}
V_18 -> V_24 = V_38 ;
V_18 -> V_22 = 0 ;
V_18 -> V_51 = ( char * ) V_18 + V_40 - V_39 ;
ASSERT ( F_12 ( ( unsigned long ) V_18 -> V_51 , sizeof( V_45 ) ) ) ;
V_36 -> V_26 -> V_52 ( V_36 , V_18 ) ;
V_49:
ASSERT ( V_18 -> V_22 <= V_39 ) ;
F_5 ( log , V_18 , V_19 , V_20 , V_21 ) ;
}
}
static void
F_13 (
struct V_2 * log ,
struct V_30 * V_31 )
{
struct V_53 * V_54 = log -> V_10 ;
struct V_55 * V_56 = V_54 -> V_11 ;
struct V_32 * V_33 ;
int V_57 = 0 ;
int V_21 = 0 ;
int V_58 ;
ASSERT ( V_31 ) ;
F_7 ( log , V_31 , & V_57 , & V_21 ) ;
F_14 ( & V_54 -> V_59 ) ;
F_9 (lidp, &tp->t_items, lid_trans) {
struct V_35 * V_36 = V_33 -> V_37 ;
if ( ! ( V_33 -> V_42 & V_43 ) )
continue;
F_15 ( & V_36 -> V_60 , & V_54 -> V_61 ) ;
}
V_57 += V_21 * sizeof( V_62 ) ;
V_56 -> V_63 += V_21 ;
if ( ! F_8 ( & V_31 -> V_64 ) )
F_16 ( & V_31 -> V_64 , & V_56 -> V_65 ) ;
if ( V_56 -> V_12 -> V_9 == 0 ) {
V_56 -> V_12 -> V_9 = V_56 -> V_12 -> V_66 ;
V_31 -> V_67 -> V_9 -= V_56 -> V_12 -> V_66 ;
}
V_58 = log -> V_68 - log -> V_69 ;
if ( V_57 > 0 && ( V_56 -> V_70 / V_58 !=
( V_56 -> V_70 + V_57 ) / V_58 ) ) {
int V_71 ;
V_71 = ( V_57 + V_58 - 1 ) / V_58 ;
V_71 *= log -> V_69 + sizeof( struct V_72 ) ;
V_56 -> V_12 -> V_66 += V_71 ;
V_56 -> V_12 -> V_9 += V_71 ;
V_31 -> V_67 -> V_9 -= V_71 ;
ASSERT ( V_31 -> V_67 -> V_9 >= V_57 ) ;
}
V_31 -> V_67 -> V_9 -= V_57 ;
V_56 -> V_70 += V_57 ;
F_17 ( & V_54 -> V_59 ) ;
}
static void
F_18 (
struct V_17 * V_73 )
{
struct V_17 * V_18 ;
for ( V_18 = V_73 ; V_18 ; ) {
struct V_17 * V_74 = V_18 -> V_48 ;
F_6 ( V_18 ) ;
V_18 = V_74 ;
}
}
static void
F_19 (
void * args ,
int abort )
{
struct V_55 * V_56 = args ;
struct V_75 * V_76 = V_56 -> V_54 -> V_77 -> V_78 ;
F_20 ( V_56 -> V_54 -> V_77 -> V_79 , V_56 -> V_80 ,
V_56 -> V_81 , abort ) ;
F_21 ( & V_56 -> V_65 ) ;
F_22 ( V_76 , & V_56 -> V_65 ,
( V_76 -> V_82 & V_83 ) && ! abort ) ;
F_14 ( & V_56 -> V_54 -> V_84 ) ;
F_23 ( & V_56 -> V_85 ) ;
F_17 ( & V_56 -> V_54 -> V_84 ) ;
F_18 ( V_56 -> V_80 ) ;
if ( ! F_8 ( & V_56 -> V_65 ) ) {
ASSERT ( V_76 -> V_82 & V_83 ) ;
F_24 ( V_76 , & V_56 -> V_65 ) ;
F_22 ( V_76 , & V_56 -> V_65 , false ) ;
}
F_6 ( V_56 ) ;
}
STATIC int
F_25 (
struct V_2 * log )
{
struct V_53 * V_54 = log -> V_10 ;
struct V_17 * V_18 ;
struct V_55 * V_56 ;
struct V_55 * V_86 ;
struct V_87 * V_88 ;
struct V_1 * V_3 ;
int V_89 ;
int error = 0 ;
struct V_90 V_91 ;
struct V_46 V_92 ;
struct V_17 V_93 = { NULL } ;
T_1 V_14 ;
T_1 V_94 ;
if ( ! V_54 )
return 0 ;
V_86 = F_11 ( sizeof( * V_86 ) , V_5 | V_6 ) ;
V_86 -> V_12 = F_1 ( log ) ;
F_26 ( & V_54 -> V_95 ) ;
V_56 = V_54 -> V_11 ;
F_14 ( & V_54 -> V_84 ) ;
V_94 = V_54 -> V_96 ;
ASSERT ( V_94 <= V_56 -> V_13 ) ;
if ( F_8 ( & V_54 -> V_61 ) ) {
V_54 -> V_96 = 0 ;
F_17 ( & V_54 -> V_84 ) ;
goto V_97;
}
F_17 ( & V_54 -> V_84 ) ;
if ( V_94 < V_54 -> V_11 -> V_13 )
goto V_97;
V_18 = NULL ;
V_89 = 0 ;
while ( ! F_8 ( & V_54 -> V_61 ) ) {
struct V_35 * V_98 ;
V_98 = F_27 ( & V_54 -> V_61 ,
struct V_35 , V_60 ) ;
F_28 ( & V_98 -> V_60 ) ;
if ( ! V_56 -> V_80 )
V_56 -> V_80 = V_98 -> V_28 ;
else
V_18 -> V_48 = V_98 -> V_28 ;
V_18 = V_98 -> V_28 ;
V_98 -> V_28 = NULL ;
V_89 += V_18 -> V_24 ;
}
F_29 ( & V_86 -> V_85 ) ;
F_29 ( & V_86 -> V_65 ) ;
V_86 -> V_13 = V_56 -> V_13 + 1 ;
V_86 -> V_54 = V_54 ;
V_54 -> V_11 = V_86 ;
V_54 -> V_99 = V_86 -> V_13 ;
F_14 ( & V_54 -> V_84 ) ;
F_30 ( & V_56 -> V_85 , & V_54 -> V_100 ) ;
F_17 ( & V_54 -> V_84 ) ;
F_31 ( & V_54 -> V_95 ) ;
V_3 = V_56 -> V_12 ;
V_91 . V_101 = V_102 ;
V_91 . V_103 = V_8 ;
V_91 . V_104 = V_3 -> V_105 ;
V_91 . V_106 = V_89 ;
V_92 . V_107 = & V_91 ;
V_92 . V_108 = sizeof( V_109 ) ;
V_92 . V_110 = V_111 ;
V_3 -> V_9 -= V_92 . V_108 + sizeof( V_62 ) ;
V_93 . V_24 = 1 ;
V_93 . V_50 = & V_92 ;
V_93 . V_48 = V_56 -> V_80 ;
error = F_32 ( log , & V_93 , V_3 , & V_56 -> V_81 , NULL , 0 ) ;
if ( error )
goto V_112;
V_113:
F_14 ( & V_54 -> V_84 ) ;
F_9 (new_ctx, &cil->xc_committing, committing) {
if ( V_86 -> V_13 >= V_56 -> V_13 )
continue;
if ( ! V_86 -> V_14 ) {
F_33 ( & V_54 -> V_114 , & V_54 -> V_84 ) ;
goto V_113;
}
}
F_17 ( & V_54 -> V_84 ) ;
V_14 = F_34 ( log -> V_78 , V_3 , & V_88 , 0 ) ;
if ( V_14 == - 1 )
goto V_115;
V_56 -> V_116 . V_117 = F_19 ;
V_56 -> V_116 . V_118 = V_56 ;
error = F_35 ( log -> V_78 , V_88 , & V_56 -> V_116 ) ;
if ( error )
goto V_115;
F_14 ( & V_54 -> V_84 ) ;
V_56 -> V_14 = V_14 ;
F_36 ( & V_54 -> V_114 ) ;
F_17 ( & V_54 -> V_84 ) ;
return F_37 ( log -> V_78 , V_88 ) ;
V_97:
F_31 ( & V_54 -> V_95 ) ;
F_38 ( V_86 -> V_12 ) ;
F_6 ( V_86 ) ;
return 0 ;
V_112:
F_38 ( V_3 ) ;
V_115:
F_19 ( V_56 , V_119 ) ;
return F_39 ( V_120 ) ;
}
static void
F_40 (
struct V_121 * V_122 )
{
struct V_53 * V_54 = F_41 ( V_122 , struct V_53 ,
V_123 ) ;
F_25 ( V_54 -> V_77 ) ;
}
static void
F_42 (
struct V_2 * log )
{
struct V_53 * V_54 = log -> V_10 ;
ASSERT ( ! F_8 ( & V_54 -> V_61 ) ) ;
if ( V_54 -> V_11 -> V_70 < F_43 ( log ) )
return;
F_14 ( & V_54 -> V_84 ) ;
if ( V_54 -> V_96 < V_54 -> V_99 ) {
V_54 -> V_96 = V_54 -> V_99 ;
F_44 ( log -> V_78 -> V_124 , & V_54 -> V_123 ) ;
}
F_17 ( & V_54 -> V_84 ) ;
}
static void
F_45 (
struct V_2 * log ,
T_1 V_94 )
{
struct V_53 * V_54 = log -> V_10 ;
if ( ! V_54 )
return;
ASSERT ( V_94 && V_94 <= V_54 -> V_99 ) ;
F_46 ( & V_54 -> V_123 ) ;
F_14 ( & V_54 -> V_84 ) ;
if ( F_8 ( & V_54 -> V_61 ) || V_94 <= V_54 -> V_96 ) {
F_17 ( & V_54 -> V_84 ) ;
return;
}
V_54 -> V_96 = V_94 ;
F_17 ( & V_54 -> V_84 ) ;
F_25 ( log ) ;
}
bool
F_47 (
struct V_2 * log )
{
struct V_53 * V_54 = log -> V_10 ;
bool V_125 = false ;
F_14 ( & V_54 -> V_84 ) ;
if ( F_8 ( & V_54 -> V_61 ) )
V_125 = true ;
F_17 ( & V_54 -> V_84 ) ;
return V_125 ;
}
int
F_48 (
struct V_75 * V_76 ,
struct V_30 * V_31 ,
T_1 * V_14 ,
int V_126 )
{
struct V_2 * log = V_76 -> V_127 ;
struct V_53 * V_54 = log -> V_10 ;
int V_128 = 0 ;
if ( V_126 & V_129 )
V_128 = V_130 ;
F_49 ( & V_54 -> V_95 ) ;
F_13 ( log , V_31 ) ;
if ( V_31 -> V_67 -> V_9 < 0 )
F_50 ( V_76 , V_31 -> V_67 ) ;
V_31 -> V_131 = V_54 -> V_11 -> V_13 ;
if ( V_14 )
* V_14 = V_31 -> V_131 ;
F_34 ( V_76 , V_31 -> V_67 , NULL , V_128 ) ;
F_51 ( V_31 ) ;
F_52 ( V_31 , V_31 -> V_131 , 0 ) ;
F_42 ( log ) ;
F_53 ( & V_54 -> V_95 ) ;
return 0 ;
}
T_1
F_54 (
struct V_2 * log ,
T_1 V_13 )
{
struct V_53 * V_54 = log -> V_10 ;
struct V_55 * V_56 ;
T_1 V_14 = V_132 ;
ASSERT ( V_13 <= V_54 -> V_99 ) ;
F_45 ( log , V_13 ) ;
V_113:
F_14 ( & V_54 -> V_84 ) ;
F_9 (ctx, &cil->xc_committing, committing) {
if ( V_56 -> V_13 > V_13 )
continue;
if ( ! V_56 -> V_14 ) {
F_33 ( & V_54 -> V_114 , & V_54 -> V_84 ) ;
goto V_113;
}
if ( V_56 -> V_13 != V_13 )
continue;
V_14 = V_56 -> V_14 ;
}
F_17 ( & V_54 -> V_84 ) ;
return V_14 ;
}
bool
F_55 (
struct V_35 * V_36 )
{
struct V_55 * V_56 ;
if ( F_8 ( & V_36 -> V_60 ) )
return false ;
V_56 = V_36 -> V_133 -> V_127 -> V_10 -> V_11 ;
if ( F_56 ( V_36 -> V_29 , V_56 -> V_13 ) != 0 )
return false ;
return true ;
}
int
F_57 (
struct V_2 * log )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
V_54 = F_11 ( sizeof( * V_54 ) , V_5 | V_134 ) ;
if ( ! V_54 )
return V_135 ;
V_56 = F_11 ( sizeof( * V_56 ) , V_5 | V_134 ) ;
if ( ! V_56 ) {
F_6 ( V_54 ) ;
return V_135 ;
}
F_58 ( & V_54 -> V_123 , F_40 ) ;
F_29 ( & V_54 -> V_61 ) ;
F_29 ( & V_54 -> V_100 ) ;
F_59 ( & V_54 -> V_59 ) ;
F_59 ( & V_54 -> V_84 ) ;
F_60 ( & V_54 -> V_95 ) ;
F_61 ( & V_54 -> V_114 ) ;
F_29 ( & V_56 -> V_85 ) ;
F_29 ( & V_56 -> V_65 ) ;
V_56 -> V_13 = 1 ;
V_56 -> V_54 = V_54 ;
V_54 -> V_11 = V_56 ;
V_54 -> V_99 = V_56 -> V_13 ;
V_54 -> V_77 = log ;
log -> V_10 = V_54 ;
return 0 ;
}
void
F_62 (
struct V_2 * log )
{
if ( log -> V_10 -> V_11 ) {
if ( log -> V_10 -> V_11 -> V_12 )
F_38 ( log -> V_10 -> V_11 -> V_12 ) ;
F_6 ( log -> V_10 -> V_11 ) ;
}
ASSERT ( F_8 ( & log -> V_10 -> V_61 ) ) ;
F_6 ( log -> V_10 ) ;
}
