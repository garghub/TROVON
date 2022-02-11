int
F_1 (
struct log * log )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_5 | V_6 ) ;
if ( ! V_2 )
return V_7 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 | V_6 ) ;
if ( ! V_4 ) {
F_3 ( V_2 ) ;
return V_7 ;
}
F_4 ( & V_2 -> V_8 ) ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( & V_2 -> V_10 ) ;
F_6 ( & V_2 -> V_11 ) ;
F_7 ( & V_2 -> V_12 ) ;
F_4 ( & V_4 -> V_13 ) ;
F_4 ( & V_4 -> V_14 ) ;
V_4 -> V_15 = 1 ;
V_4 -> V_2 = V_2 ;
V_2 -> V_16 = V_4 ;
V_2 -> V_17 = V_4 -> V_15 ;
V_2 -> V_18 = log ;
log -> V_19 = V_2 ;
return 0 ;
}
void
F_8 (
struct log * log )
{
if ( log -> V_19 -> V_16 ) {
if ( log -> V_19 -> V_16 -> V_20 )
F_9 ( log -> V_19 -> V_16 -> V_20 ) ;
F_3 ( log -> V_19 -> V_16 ) ;
}
ASSERT ( F_10 ( & log -> V_19 -> V_8 ) ) ;
F_3 ( log -> V_19 ) ;
}
static struct V_21 *
F_11 (
struct log * log )
{
struct V_21 * V_22 ;
V_22 = F_12 ( log , 0 , 1 , V_23 , 0 ,
V_5 | V_24 ) ;
V_22 -> V_25 = V_26 ;
V_22 -> V_27 = 0 ;
return V_22 ;
}
void
F_13 (
struct log * log )
{
log -> V_19 -> V_16 -> V_20 = F_11 ( log ) ;
log -> V_19 -> V_16 -> V_15 = 1 ;
log -> V_19 -> V_16 -> V_28 = F_14 ( log -> V_29 ,
log -> V_30 ) ;
}
static struct V_31 *
F_15 (
struct V_32 * V_33 )
{
struct V_34 * V_35 ;
struct V_31 * V_36 = NULL ;
struct V_31 * V_37 = NULL ;
if ( F_10 ( & V_33 -> V_38 ) ) {
ASSERT ( 0 ) ;
return NULL ;
}
F_16 (lidp, &tp->t_items, lid_trans) {
struct V_31 * V_39 ;
void * V_40 ;
int V_41 ;
int V_42 = 0 ;
T_1 V_43 ;
if ( ! ( V_35 -> V_44 & V_45 ) )
continue;
V_43 = F_17 ( V_35 -> V_46 ) ;
if ( ! V_43 )
continue;
V_39 = F_2 ( sizeof( * V_39 ) +
V_43 * sizeof( struct V_47 ) ,
V_5 ) ;
V_39 -> V_48 = (struct V_47 * ) & V_39 [ 1 ] ;
V_39 -> V_49 = V_43 ;
V_39 -> V_50 = V_35 -> V_46 ;
F_18 ( V_39 -> V_50 , V_39 -> V_48 ) ;
for ( V_41 = 0 ; V_41 < V_39 -> V_49 ; V_41 ++ )
V_42 += V_39 -> V_48 [ V_41 ] . V_51 ;
V_39 -> V_52 = V_42 ;
V_39 -> V_53 = F_19 ( V_39 -> V_52 ,
V_5 | V_24 ) ;
V_40 = V_39 -> V_53 ;
for ( V_41 = 0 ; V_41 < V_39 -> V_49 ; V_41 ++ ) {
struct V_47 * V_54 = & V_39 -> V_48 [ V_41 ] ;
memcpy ( V_40 , V_54 -> V_55 , V_54 -> V_51 ) ;
V_54 -> V_55 = V_40 ;
V_40 += V_54 -> V_51 ;
}
ASSERT ( V_40 == V_39 -> V_53 + V_39 -> V_52 ) ;
if ( ! V_37 )
V_37 = V_39 ;
else
V_36 -> V_56 = V_39 ;
V_36 = V_39 ;
}
return V_37 ;
}
STATIC void
F_20 (
struct log * log ,
struct V_31 * V_36 ,
int * V_42 ,
int * V_57 )
{
struct V_31 * V_58 = V_36 -> V_50 -> V_59 ;
if ( V_58 ) {
ASSERT ( ! F_10 ( & V_36 -> V_50 -> V_60 ) ) ;
ASSERT ( V_58 -> V_53 && V_58 -> V_52 && V_58 -> V_49 ) ;
* V_42 += V_36 -> V_52 - V_58 -> V_52 ;
* V_57 += V_36 -> V_49 - V_58 -> V_49 ;
F_3 ( V_58 -> V_53 ) ;
F_3 ( V_58 ) ;
} else {
ASSERT ( ! V_36 -> V_50 -> V_59 ) ;
ASSERT ( F_10 ( & V_36 -> V_50 -> V_60 ) ) ;
* V_42 += V_36 -> V_52 ;
* V_57 += V_36 -> V_49 ;
F_21 ( V_36 -> V_50 ) ;
}
V_36 -> V_50 -> V_59 = V_36 ;
if ( ! V_36 -> V_50 -> V_61 )
V_36 -> V_50 -> V_61 = log -> V_19 -> V_16 -> V_15 ;
}
static void
F_22 (
struct log * log ,
struct V_31 * V_62 ,
struct V_21 * V_20 )
{
struct V_1 * V_2 = log -> V_19 ;
struct V_3 * V_4 = V_2 -> V_16 ;
struct V_31 * V_36 ;
int V_42 = 0 ;
int V_57 = 0 ;
int V_63 ;
ASSERT ( V_62 ) ;
for ( V_36 = V_62 ; V_36 ; V_36 = V_36 -> V_56 )
F_20 ( log , V_36 , & V_42 , & V_57 ) ;
V_42 += V_57 * sizeof( V_64 ) ;
F_23 ( & V_2 -> V_10 ) ;
for ( V_36 = V_62 ; V_36 ; V_36 = V_36 -> V_56 )
F_24 ( & V_36 -> V_50 -> V_60 , & V_2 -> V_8 ) ;
V_4 -> V_65 += V_57 ;
if ( V_4 -> V_20 -> V_27 == 0 ) {
ASSERT ( V_20 -> V_27 >= V_4 -> V_20 -> V_66 + V_42 ) ;
V_4 -> V_20 -> V_27 = V_4 -> V_20 -> V_66 ;
V_20 -> V_27 -= V_4 -> V_20 -> V_66 ;
}
V_63 = log -> V_67 - log -> V_68 ;
if ( V_42 > 0 && ( V_4 -> V_69 / V_63 !=
( V_4 -> V_69 + V_42 ) / V_63 ) ) {
int V_70 ;
V_70 = ( V_42 + V_63 - 1 ) / V_63 ;
V_70 *= log -> V_68 + sizeof( struct V_71 ) ;
V_4 -> V_20 -> V_66 += V_70 ;
V_4 -> V_20 -> V_27 += V_70 ;
V_20 -> V_27 -= V_70 ;
ASSERT ( V_20 -> V_27 >= V_42 ) ;
}
V_20 -> V_27 -= V_42 ;
V_4 -> V_69 += V_42 ;
F_25 ( & V_2 -> V_10 ) ;
}
static void
F_26 (
struct V_31 * V_62 )
{
struct V_31 * V_36 ;
for ( V_36 = V_62 ; V_36 ; ) {
struct V_31 * V_72 = V_36 -> V_56 ;
F_3 ( V_36 -> V_53 ) ;
F_3 ( V_36 ) ;
V_36 = V_72 ;
}
}
static void
F_27 (
void * args ,
int abort )
{
struct V_3 * V_4 = args ;
struct V_73 * V_74 = V_4 -> V_2 -> V_18 -> V_75 ;
F_28 ( V_4 -> V_2 -> V_18 -> V_76 , V_4 -> V_77 ,
V_4 -> V_78 , abort ) ;
F_29 ( & V_4 -> V_14 ) ;
F_30 ( V_74 , & V_4 -> V_14 ,
( V_74 -> V_79 & V_80 ) && ! abort ) ;
F_23 ( & V_4 -> V_2 -> V_10 ) ;
F_31 ( & V_4 -> V_13 ) ;
F_25 ( & V_4 -> V_2 -> V_10 ) ;
F_26 ( V_4 -> V_77 ) ;
if ( ! F_10 ( & V_4 -> V_14 ) ) {
ASSERT ( V_74 -> V_79 & V_80 ) ;
F_32 ( V_74 , & V_4 -> V_14 ) ;
F_30 ( V_74 , & V_4 -> V_14 , false ) ;
}
F_3 ( V_4 ) ;
}
STATIC int
F_33 (
struct log * log ,
T_2 V_81 )
{
struct V_1 * V_2 = log -> V_19 ;
struct V_31 * V_36 ;
struct V_3 * V_4 ;
struct V_3 * V_82 ;
struct V_83 * V_84 ;
struct V_21 * V_22 ;
int V_85 ;
int V_86 ;
int V_42 ;
int error = 0 ;
struct V_87 V_88 ;
struct V_47 V_89 ;
struct V_31 V_90 = { NULL } ;
T_2 V_28 ;
if ( ! V_2 )
return 0 ;
ASSERT ( ! V_81 || V_81 <= V_2 -> V_16 -> V_15 ) ;
V_82 = F_2 ( sizeof( * V_82 ) , V_5 | V_24 ) ;
V_82 -> V_20 = F_11 ( log ) ;
if ( ! F_34 ( & V_2 -> V_11 ) ) {
if ( ! V_81 &&
V_2 -> V_16 -> V_69 < F_35 ( log ) )
goto V_91;
F_36 ( & V_2 -> V_11 ) ;
}
V_4 = V_2 -> V_16 ;
if ( F_10 ( & V_2 -> V_8 ) )
goto V_92;
if ( ! V_81 && V_2 -> V_16 -> V_69 < F_37 ( log ) )
goto V_92;
if ( V_81 && V_81 < V_2 -> V_16 -> V_15 )
goto V_92;
V_36 = NULL ;
V_85 = 0 ;
V_86 = 0 ;
V_42 = 0 ;
while ( ! F_10 ( & V_2 -> V_8 ) ) {
struct V_93 * V_94 ;
int V_95 ;
V_94 = F_38 ( & V_2 -> V_8 ,
struct V_93 , V_60 ) ;
F_39 ( & V_94 -> V_60 ) ;
if ( ! V_4 -> V_77 )
V_4 -> V_77 = V_94 -> V_59 ;
else
V_36 -> V_56 = V_94 -> V_59 ;
V_36 = V_94 -> V_59 ;
V_94 -> V_59 = NULL ;
V_85 ++ ;
V_86 += V_36 -> V_49 ;
for ( V_95 = 0 ; V_95 < V_36 -> V_49 ; V_95 ++ )
V_42 += V_36 -> V_48 [ V_95 ] . V_51 ;
}
F_4 ( & V_82 -> V_13 ) ;
F_4 ( & V_82 -> V_14 ) ;
V_82 -> V_15 = V_4 -> V_15 + 1 ;
V_82 -> V_2 = V_2 ;
V_2 -> V_16 = V_82 ;
V_2 -> V_17 = V_82 -> V_15 ;
F_23 ( & V_2 -> V_10 ) ;
F_40 ( & V_4 -> V_13 , & V_2 -> V_9 ) ;
F_25 ( & V_2 -> V_10 ) ;
F_41 ( & V_2 -> V_11 ) ;
V_22 = V_4 -> V_20 ;
V_88 . V_96 = V_97 ;
V_88 . V_98 = V_26 ;
V_88 . V_99 = V_22 -> V_100 ;
V_88 . V_101 = V_86 ;
V_89 . V_55 = & V_88 ;
V_89 . V_51 = sizeof( V_102 ) ;
V_89 . V_103 = V_104 ;
V_22 -> V_27 -= V_89 . V_51 + sizeof( V_64 ) ;
V_90 . V_49 = 1 ;
V_90 . V_48 = & V_89 ;
V_90 . V_56 = V_4 -> V_77 ;
error = F_42 ( log , & V_90 , V_22 , & V_4 -> V_78 , NULL , 0 ) ;
if ( error )
goto V_105;
V_106:
F_23 ( & V_2 -> V_10 ) ;
F_16 (new_ctx, &cil->xc_committing, committing) {
if ( V_82 -> V_15 >= V_4 -> V_15 )
continue;
if ( ! V_82 -> V_28 ) {
F_43 ( & V_2 -> V_12 , & V_2 -> V_10 ) ;
goto V_106;
}
}
F_25 ( & V_2 -> V_10 ) ;
V_28 = F_44 ( log -> V_75 , V_22 , & V_84 , 0 ) ;
if ( V_28 == - 1 )
goto V_107;
V_4 -> V_108 . V_109 = F_27 ;
V_4 -> V_108 . V_110 = V_4 ;
error = F_45 ( log -> V_75 , V_84 , & V_4 -> V_108 ) ;
if ( error )
goto V_107;
F_23 ( & V_2 -> V_10 ) ;
V_4 -> V_28 = V_28 ;
F_46 ( & V_2 -> V_12 ) ;
F_25 ( & V_2 -> V_10 ) ;
return F_47 ( log -> V_75 , V_84 ) ;
V_92:
F_41 ( & V_2 -> V_11 ) ;
V_91:
F_9 ( V_82 -> V_20 ) ;
F_3 ( V_82 ) ;
return 0 ;
V_105:
F_9 ( V_22 ) ;
V_107:
F_27 ( V_4 , V_111 ) ;
return F_48 ( V_112 ) ;
}
int
F_49 (
struct V_73 * V_74 ,
struct V_32 * V_33 ,
T_2 * V_28 ,
int V_113 )
{
struct log * log = V_74 -> V_114 ;
int V_115 = 0 ;
int V_116 = 0 ;
struct V_31 * V_62 ;
if ( V_113 & V_117 )
V_115 = V_118 ;
V_62 = F_15 ( V_33 ) ;
if ( ! V_62 )
return V_7 ;
F_50 ( & log -> V_19 -> V_11 ) ;
if ( V_28 )
* V_28 = log -> V_19 -> V_16 -> V_15 ;
F_22 ( log , V_62 , V_33 -> V_119 ) ;
if ( V_33 -> V_119 -> V_27 < 0 )
F_51 ( log -> V_75 , V_33 -> V_119 ) ;
if ( ! F_10 ( & V_33 -> V_120 ) ) {
F_23 ( & log -> V_19 -> V_10 ) ;
F_52 ( & V_33 -> V_120 ,
& log -> V_19 -> V_16 -> V_14 ) ;
F_25 ( & log -> V_19 -> V_10 ) ;
}
V_33 -> V_121 = * V_28 ;
F_44 ( V_74 , V_33 -> V_119 , NULL , V_115 ) ;
F_53 ( V_33 ) ;
F_54 ( V_33 , * V_28 , 0 ) ;
if ( log -> V_19 -> V_16 -> V_69 > F_37 ( log ) )
V_116 = 1 ;
F_55 ( & log -> V_19 -> V_11 ) ;
if ( V_116 )
F_33 ( log , 0 ) ;
return 0 ;
}
T_2
F_56 (
struct log * log ,
T_2 V_15 )
{
struct V_1 * V_2 = log -> V_19 ;
struct V_3 * V_4 ;
T_2 V_28 = V_122 ;
ASSERT ( V_15 <= V_2 -> V_17 ) ;
if ( V_15 == V_2 -> V_17 )
F_33 ( log , V_15 ) ;
V_106:
F_23 ( & V_2 -> V_10 ) ;
F_16 (ctx, &cil->xc_committing, committing) {
if ( V_4 -> V_15 > V_15 )
continue;
if ( ! V_4 -> V_28 ) {
F_43 ( & V_2 -> V_12 , & V_2 -> V_10 ) ;
goto V_106;
}
if ( V_4 -> V_15 != V_15 )
continue;
V_28 = V_4 -> V_28 ;
}
F_25 ( & V_2 -> V_10 ) ;
return V_28 ;
}
bool
F_57 (
struct V_93 * V_123 )
{
struct V_3 * V_4 ;
if ( F_10 ( & V_123 -> V_60 ) )
return false ;
V_4 = V_123 -> V_124 -> V_114 -> V_19 -> V_16 ;
if ( F_58 ( V_123 -> V_61 , V_4 -> V_15 ) != 0 )
return false ;
return true ;
}
