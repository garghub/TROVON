static struct V_1 *
F_1 (
struct V_2 * log )
{
struct V_1 * V_3 ;
V_3 = F_2 ( log , 0 , 1 , V_4 , 0 ,
V_5 | V_6 ) ;
V_3 -> V_7 = 0 ;
return V_3 ;
}
void
F_3 (
struct V_2 * log )
{
log -> V_8 -> V_9 -> V_10 = F_1 ( log ) ;
log -> V_8 -> V_9 -> V_11 = 1 ;
}
STATIC void
F_4 (
struct V_2 * log ,
struct V_12 * V_13 ,
struct V_12 * V_14 ,
int * V_15 ,
int * V_16 )
{
if ( V_13 -> V_17 != V_18 ) {
* V_15 += V_13 -> V_19 ;
* V_16 += V_13 -> V_20 ;
}
if ( ! V_14 )
V_13 -> V_21 -> V_22 -> V_23 ( V_13 -> V_21 ) ;
else if ( V_14 != V_13 ) {
ASSERT ( V_13 -> V_17 != V_18 ) ;
* V_15 -= V_14 -> V_19 ;
* V_16 -= V_14 -> V_20 ;
F_5 ( V_14 ) ;
}
V_13 -> V_21 -> V_24 = V_13 ;
if ( ! V_13 -> V_21 -> V_25 )
V_13 -> V_21 -> V_25 = log -> V_8 -> V_9 -> V_11 ;
}
static void
F_6 (
struct V_2 * log ,
struct V_26 * V_27 ,
int * V_15 ,
int * V_16 )
{
struct V_28 * V_29 ;
if ( F_7 ( & V_27 -> V_30 ) ) {
ASSERT ( 0 ) ;
return;
}
F_8 (lidp, &tp->t_items, lid_trans) {
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_12 * V_13 ;
struct V_12 * V_14 ;
int V_34 = 0 ;
int V_35 = 0 ;
int V_36 ;
bool V_37 = false ;
if ( ! ( V_29 -> V_38 & V_39 ) )
continue;
V_32 -> V_22 -> V_40 ( V_32 , & V_34 , & V_35 ) ;
if ( ! V_34 )
continue;
if ( V_34 == V_18 ) {
V_37 = true ;
V_34 = 0 ;
V_35 = 0 ;
}
V_35 += V_34 * sizeof( V_41 ) ;
V_35 = F_9 ( V_35 , sizeof( V_41 ) ) ;
V_14 = V_32 -> V_24 ;
V_36 = V_35 +
F_9 ( ( sizeof( struct V_12 ) +
V_34 * sizeof( struct V_42 ) ) ,
sizeof( V_41 ) ) ;
if ( V_32 -> V_24 && V_36 <= V_32 -> V_24 -> V_43 ) {
V_13 = V_32 -> V_24 ;
V_13 -> V_44 = NULL ;
if ( V_37 )
goto V_45;
* V_16 -= V_13 -> V_20 ;
* V_15 -= V_13 -> V_19 ;
} else {
V_13 = F_10 ( V_36 , V_5 | V_6 ) ;
V_13 -> V_21 = V_32 ;
V_13 -> V_43 = V_36 ;
if ( V_37 ) {
ASSERT ( V_32 -> V_24 == NULL ) ;
V_13 -> V_17 = V_18 ;
goto V_45;
}
V_13 -> V_46 = (struct V_42 * ) & V_13 [ 1 ] ;
}
V_13 -> V_20 = V_34 ;
V_13 -> V_17 = 0 ;
V_13 -> V_19 = 0 ;
V_13 -> V_47 = ( char * ) V_13 + V_36 - V_35 ;
ASSERT ( F_11 ( ( unsigned long ) V_13 -> V_47 , sizeof( V_41 ) ) ) ;
V_32 -> V_22 -> V_48 ( V_32 , V_13 ) ;
V_45:
ASSERT ( V_13 -> V_17 <= V_35 ) ;
F_4 ( log , V_13 , V_14 , V_15 , V_16 ) ;
}
}
static void
F_12 (
struct V_2 * log ,
struct V_26 * V_27 )
{
struct V_49 * V_50 = log -> V_8 ;
struct V_51 * V_52 = V_50 -> V_9 ;
struct V_28 * V_29 ;
int V_53 = 0 ;
int V_16 = 0 ;
int V_54 ;
ASSERT ( V_27 ) ;
F_6 ( log , V_27 , & V_53 , & V_16 ) ;
F_13 ( & V_50 -> V_55 ) ;
F_8 (lidp, &tp->t_items, lid_trans) {
struct V_31 * V_32 = V_29 -> V_33 ;
if ( ! ( V_29 -> V_38 & V_39 ) )
continue;
if ( ! F_14 ( & V_32 -> V_56 , & V_50 -> V_57 ) )
F_15 ( & V_32 -> V_56 , & V_50 -> V_57 ) ;
}
V_53 += V_16 * sizeof( V_58 ) ;
V_52 -> V_59 += V_16 ;
if ( ! F_7 ( & V_27 -> V_60 ) )
F_16 ( & V_27 -> V_60 , & V_52 -> V_61 ) ;
if ( V_52 -> V_10 -> V_7 == 0 ) {
V_52 -> V_10 -> V_7 = V_52 -> V_10 -> V_62 ;
V_27 -> V_63 -> V_7 -= V_52 -> V_10 -> V_62 ;
}
V_54 = log -> V_64 - log -> V_65 ;
if ( V_53 > 0 && ( V_52 -> V_66 / V_54 !=
( V_52 -> V_66 + V_53 ) / V_54 ) ) {
int V_67 ;
V_67 = ( V_53 + V_54 - 1 ) / V_54 ;
V_67 *= log -> V_65 + sizeof( struct V_68 ) ;
V_52 -> V_10 -> V_62 += V_67 ;
V_52 -> V_10 -> V_7 += V_67 ;
V_27 -> V_63 -> V_7 -= V_67 ;
ASSERT ( V_27 -> V_63 -> V_7 >= V_53 ) ;
}
V_27 -> V_63 -> V_7 -= V_53 ;
V_52 -> V_66 += V_53 ;
F_17 ( & V_50 -> V_55 ) ;
}
static void
F_18 (
struct V_12 * V_69 )
{
struct V_12 * V_13 ;
for ( V_13 = V_69 ; V_13 ; ) {
struct V_12 * V_70 = V_13 -> V_44 ;
F_5 ( V_13 ) ;
V_13 = V_70 ;
}
}
static void
F_19 (
void * args ,
int abort )
{
struct V_51 * V_52 = args ;
struct V_71 * V_72 = V_52 -> V_50 -> V_73 -> V_74 ;
F_20 ( V_52 -> V_50 -> V_73 -> V_75 , V_52 -> V_76 ,
V_52 -> V_77 , abort ) ;
F_21 ( & V_52 -> V_61 ) ;
F_22 ( V_72 , & V_52 -> V_61 ,
( V_72 -> V_78 & V_79 ) && ! abort ) ;
F_13 ( & V_52 -> V_50 -> V_80 ) ;
if ( abort )
F_23 ( & V_52 -> V_50 -> V_81 ) ;
F_24 ( & V_52 -> V_82 ) ;
F_17 ( & V_52 -> V_50 -> V_80 ) ;
F_18 ( V_52 -> V_76 ) ;
if ( ! F_7 ( & V_52 -> V_61 ) ) {
ASSERT ( V_72 -> V_78 & V_79 ) ;
F_25 ( V_72 , & V_52 -> V_61 ) ;
F_22 ( V_72 , & V_52 -> V_61 , false ) ;
}
F_5 ( V_52 ) ;
}
STATIC int
F_26 (
struct V_2 * log )
{
struct V_49 * V_50 = log -> V_8 ;
struct V_12 * V_13 ;
struct V_51 * V_52 ;
struct V_51 * V_83 ;
struct V_84 * V_85 ;
struct V_1 * V_3 ;
int V_86 ;
int error = 0 ;
struct V_87 V_88 ;
struct V_42 V_89 ;
struct V_12 V_90 = { NULL } ;
T_1 V_91 ;
T_1 V_92 ;
if ( ! V_50 )
return 0 ;
V_83 = F_10 ( sizeof( * V_83 ) , V_5 | V_6 ) ;
V_83 -> V_10 = F_1 ( log ) ;
F_27 ( & V_50 -> V_93 ) ;
V_52 = V_50 -> V_9 ;
F_13 ( & V_50 -> V_80 ) ;
V_92 = V_50 -> V_94 ;
ASSERT ( V_92 <= V_52 -> V_11 ) ;
if ( F_7 ( & V_50 -> V_57 ) ) {
V_50 -> V_94 = 0 ;
F_17 ( & V_50 -> V_80 ) ;
goto V_95;
}
if ( V_92 < V_50 -> V_9 -> V_11 ) {
F_17 ( & V_50 -> V_80 ) ;
goto V_95;
}
F_28 ( & V_52 -> V_82 , & V_50 -> V_96 ) ;
F_17 ( & V_50 -> V_80 ) ;
V_13 = NULL ;
V_86 = 0 ;
while ( ! F_7 ( & V_50 -> V_57 ) ) {
struct V_31 * V_97 ;
V_97 = F_29 ( & V_50 -> V_57 ,
struct V_31 , V_56 ) ;
F_30 ( & V_97 -> V_56 ) ;
if ( ! V_52 -> V_76 )
V_52 -> V_76 = V_97 -> V_24 ;
else
V_13 -> V_44 = V_97 -> V_24 ;
V_13 = V_97 -> V_24 ;
V_97 -> V_24 = NULL ;
V_86 += V_13 -> V_20 ;
}
F_31 ( & V_83 -> V_82 ) ;
F_31 ( & V_83 -> V_61 ) ;
V_83 -> V_11 = V_52 -> V_11 + 1 ;
V_83 -> V_50 = V_50 ;
V_50 -> V_9 = V_83 ;
F_13 ( & V_50 -> V_80 ) ;
V_50 -> V_98 = V_83 -> V_11 ;
F_17 ( & V_50 -> V_80 ) ;
F_32 ( & V_50 -> V_93 ) ;
V_3 = V_52 -> V_10 ;
V_88 . V_99 = V_100 ;
V_88 . V_101 = V_102 ;
V_88 . V_103 = V_3 -> V_104 ;
V_88 . V_105 = V_86 ;
V_89 . V_106 = & V_88 ;
V_89 . V_107 = sizeof( V_108 ) ;
V_89 . V_109 = V_110 ;
V_3 -> V_7 -= V_89 . V_107 + sizeof( V_58 ) ;
V_90 . V_20 = 1 ;
V_90 . V_46 = & V_89 ;
V_90 . V_44 = V_52 -> V_76 ;
error = F_33 ( log , & V_90 , V_3 , & V_52 -> V_77 , NULL , 0 ) ;
if ( error )
goto V_111;
V_112:
F_13 ( & V_50 -> V_80 ) ;
F_8 (new_ctx, &cil->xc_committing, committing) {
if ( F_34 ( log ) ) {
F_17 ( & V_50 -> V_80 ) ;
goto V_111;
}
if ( V_83 -> V_11 >= V_52 -> V_11 )
continue;
if ( ! V_83 -> V_91 ) {
F_35 ( & V_50 -> V_81 , & V_50 -> V_80 ) ;
goto V_112;
}
}
F_17 ( & V_50 -> V_80 ) ;
V_91 = F_36 ( log -> V_74 , V_3 , & V_85 , false ) ;
if ( V_91 == - 1 )
goto V_113;
V_52 -> V_114 . V_115 = F_19 ;
V_52 -> V_114 . V_116 = V_52 ;
error = F_37 ( log -> V_74 , V_85 , & V_52 -> V_114 ) ;
if ( error )
goto V_113;
F_13 ( & V_50 -> V_80 ) ;
V_52 -> V_91 = V_91 ;
F_23 ( & V_50 -> V_81 ) ;
F_17 ( & V_50 -> V_80 ) ;
return F_38 ( log -> V_74 , V_85 ) ;
V_95:
F_32 ( & V_50 -> V_93 ) ;
F_39 ( V_83 -> V_10 ) ;
F_5 ( V_83 ) ;
return 0 ;
V_111:
F_39 ( V_3 ) ;
V_113:
F_19 ( V_52 , V_117 ) ;
return - V_118 ;
}
static void
F_40 (
struct V_119 * V_120 )
{
struct V_49 * V_50 = F_41 ( V_120 , struct V_49 ,
V_121 ) ;
F_26 ( V_50 -> V_73 ) ;
}
static void
F_42 (
struct V_2 * log )
{
struct V_49 * V_50 = log -> V_8 ;
ASSERT ( ! F_7 ( & V_50 -> V_57 ) ) ;
if ( V_50 -> V_9 -> V_66 < F_43 ( log ) )
return;
F_13 ( & V_50 -> V_80 ) ;
if ( V_50 -> V_94 < V_50 -> V_98 ) {
V_50 -> V_94 = V_50 -> V_98 ;
F_44 ( log -> V_74 -> V_122 , & V_50 -> V_121 ) ;
}
F_17 ( & V_50 -> V_80 ) ;
}
static void
F_45 (
struct V_2 * log ,
T_1 V_92 )
{
struct V_49 * V_50 = log -> V_8 ;
if ( ! V_50 )
return;
ASSERT ( V_92 && V_92 <= V_50 -> V_98 ) ;
F_46 ( & V_50 -> V_121 ) ;
F_13 ( & V_50 -> V_80 ) ;
if ( F_7 ( & V_50 -> V_57 ) || V_92 <= V_50 -> V_94 ) {
F_17 ( & V_50 -> V_80 ) ;
return;
}
V_50 -> V_94 = V_92 ;
F_44 ( log -> V_74 -> V_122 , & V_50 -> V_121 ) ;
F_17 ( & V_50 -> V_80 ) ;
}
bool
F_47 (
struct V_2 * log )
{
struct V_49 * V_50 = log -> V_8 ;
bool V_123 = false ;
F_13 ( & V_50 -> V_80 ) ;
if ( F_7 ( & V_50 -> V_57 ) )
V_123 = true ;
F_17 ( & V_50 -> V_80 ) ;
return V_123 ;
}
void
F_48 (
struct V_71 * V_72 ,
struct V_26 * V_27 ,
T_1 * V_91 ,
bool V_124 )
{
struct V_2 * log = V_72 -> V_125 ;
struct V_49 * V_50 = log -> V_8 ;
F_49 ( & V_50 -> V_93 ) ;
F_12 ( log , V_27 ) ;
if ( V_27 -> V_63 -> V_7 < 0 )
F_50 ( V_72 , V_27 -> V_63 ) ;
V_27 -> V_126 = V_50 -> V_9 -> V_11 ;
if ( V_91 )
* V_91 = V_27 -> V_126 ;
F_36 ( V_72 , V_27 -> V_63 , NULL , V_124 ) ;
F_51 ( V_27 ) ;
F_52 ( V_27 , V_27 -> V_126 , false ) ;
F_42 ( log ) ;
F_53 ( & V_50 -> V_93 ) ;
}
T_1
F_54 (
struct V_2 * log ,
T_1 V_11 )
{
struct V_49 * V_50 = log -> V_8 ;
struct V_51 * V_52 ;
T_1 V_91 = V_127 ;
ASSERT ( V_11 <= V_50 -> V_98 ) ;
V_112:
F_45 ( log , V_11 ) ;
F_13 ( & V_50 -> V_80 ) ;
F_8 (ctx, &cil->xc_committing, committing) {
if ( F_34 ( log ) )
goto V_128;
if ( V_52 -> V_11 > V_11 )
continue;
if ( ! V_52 -> V_91 ) {
F_35 ( & V_50 -> V_81 , & V_50 -> V_80 ) ;
goto V_112;
}
if ( V_52 -> V_11 != V_11 )
continue;
V_91 = V_52 -> V_91 ;
}
if ( V_11 == V_50 -> V_98 &&
! F_7 ( & V_50 -> V_57 ) ) {
F_17 ( & V_50 -> V_80 ) ;
goto V_112;
}
F_17 ( & V_50 -> V_80 ) ;
return V_91 ;
V_128:
F_17 ( & V_50 -> V_80 ) ;
return 0 ;
}
bool
F_55 (
struct V_31 * V_32 )
{
struct V_51 * V_52 ;
if ( F_7 ( & V_32 -> V_56 ) )
return false ;
V_52 = V_32 -> V_129 -> V_125 -> V_8 -> V_9 ;
if ( F_56 ( V_32 -> V_25 , V_52 -> V_11 ) != 0 )
return false ;
return true ;
}
int
F_57 (
struct V_2 * log )
{
struct V_49 * V_50 ;
struct V_51 * V_52 ;
V_50 = F_10 ( sizeof( * V_50 ) , V_5 | V_130 ) ;
if ( ! V_50 )
return - V_131 ;
V_52 = F_10 ( sizeof( * V_52 ) , V_5 | V_130 ) ;
if ( ! V_52 ) {
F_5 ( V_50 ) ;
return - V_131 ;
}
F_58 ( & V_50 -> V_121 , F_40 ) ;
F_31 ( & V_50 -> V_57 ) ;
F_31 ( & V_50 -> V_96 ) ;
F_59 ( & V_50 -> V_55 ) ;
F_59 ( & V_50 -> V_80 ) ;
F_60 ( & V_50 -> V_93 ) ;
F_61 ( & V_50 -> V_81 ) ;
F_31 ( & V_52 -> V_82 ) ;
F_31 ( & V_52 -> V_61 ) ;
V_52 -> V_11 = 1 ;
V_52 -> V_50 = V_50 ;
V_50 -> V_9 = V_52 ;
V_50 -> V_98 = V_52 -> V_11 ;
V_50 -> V_73 = log ;
log -> V_8 = V_50 ;
return 0 ;
}
void
F_62 (
struct V_2 * log )
{
if ( log -> V_8 -> V_9 ) {
if ( log -> V_8 -> V_9 -> V_10 )
F_39 ( log -> V_8 -> V_9 -> V_10 ) ;
F_5 ( log -> V_8 -> V_9 ) ;
}
ASSERT ( F_7 ( & log -> V_8 -> V_57 ) ) ;
F_5 ( log -> V_8 ) ;
}
