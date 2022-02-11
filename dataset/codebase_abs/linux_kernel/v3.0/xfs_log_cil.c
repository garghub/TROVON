int
F_1 (
struct log * log )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
log -> V_5 = NULL ;
if ( ! ( log -> V_6 -> V_7 & V_8 ) )
return 0 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_9 | V_10 ) ;
if ( ! V_2 )
return V_11 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_9 | V_10 ) ;
if ( ! V_4 ) {
F_3 ( V_2 ) ;
return V_11 ;
}
F_4 ( & V_2 -> V_12 ) ;
F_4 ( & V_2 -> V_13 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_15 ) ;
F_7 ( & V_2 -> V_16 ) ;
F_4 ( & V_4 -> V_17 ) ;
F_4 ( & V_4 -> V_18 ) ;
V_4 -> V_19 = 1 ;
V_4 -> V_2 = V_2 ;
V_2 -> V_20 = V_4 ;
V_2 -> V_21 = V_4 -> V_19 ;
V_2 -> V_22 = log ;
log -> V_5 = V_2 ;
return 0 ;
}
void
F_8 (
struct log * log )
{
if ( ! log -> V_5 )
return;
if ( log -> V_5 -> V_20 ) {
if ( log -> V_5 -> V_20 -> V_23 )
F_9 ( log -> V_5 -> V_20 -> V_23 ) ;
F_3 ( log -> V_5 -> V_20 ) ;
}
ASSERT ( F_10 ( & log -> V_5 -> V_12 ) ) ;
F_3 ( log -> V_5 ) ;
}
static struct V_24 *
F_11 (
struct log * log )
{
struct V_24 * V_25 ;
V_25 = F_12 ( log , 0 , 1 , V_26 , 0 ,
V_9 | V_27 ) ;
V_25 -> V_28 = V_29 ;
V_25 -> V_30 = 0 ;
return V_25 ;
}
void
F_13 (
struct log * log )
{
if ( ! log -> V_5 )
return;
log -> V_5 -> V_20 -> V_23 = F_11 ( log ) ;
log -> V_5 -> V_20 -> V_19 = 1 ;
log -> V_5 -> V_20 -> V_31 = F_14 ( log -> V_32 ,
log -> V_33 ) ;
}
static void
F_15 (
struct log * log ,
struct V_34 * V_35 )
{
struct V_34 * V_36 ;
ASSERT ( V_35 ) ;
for ( V_36 = V_35 ; V_36 ; V_36 = V_36 -> V_37 ) {
void * V_38 ;
int V_39 ;
int V_40 = 0 ;
F_16 ( V_36 -> V_41 , V_36 -> V_42 ) ;
for ( V_39 = 0 ; V_39 < V_36 -> V_43 ; V_39 ++ )
V_40 += V_36 -> V_42 [ V_39 ] . V_44 ;
V_36 -> V_45 = V_40 ;
V_36 -> V_46 = F_17 ( V_36 -> V_45 , V_9 | V_27 ) ;
V_38 = V_36 -> V_46 ;
for ( V_39 = 0 ; V_39 < V_36 -> V_43 ; V_39 ++ ) {
struct V_47 * V_48 = & V_36 -> V_42 [ V_39 ] ;
memcpy ( V_38 , V_48 -> V_49 , V_48 -> V_44 ) ;
V_48 -> V_49 = V_38 ;
V_38 += V_48 -> V_44 ;
}
ASSERT ( V_38 == V_36 -> V_46 + V_36 -> V_45 ) ;
}
}
STATIC void
F_18 (
struct log * log ,
struct V_34 * V_36 ,
int * V_40 ,
int * V_50 )
{
struct V_34 * V_51 = V_36 -> V_41 -> V_52 ;
if ( V_51 ) {
ASSERT ( ! F_10 ( & V_36 -> V_41 -> V_53 ) ) ;
ASSERT ( V_51 -> V_46 && V_51 -> V_45 && V_51 -> V_43 ) ;
* V_40 += V_36 -> V_45 - V_51 -> V_45 ;
* V_50 += V_36 -> V_43 - V_51 -> V_43 ;
F_3 ( V_51 -> V_46 ) ;
F_3 ( V_51 ) ;
} else {
ASSERT ( ! V_36 -> V_41 -> V_52 ) ;
ASSERT ( F_10 ( & V_36 -> V_41 -> V_53 ) ) ;
* V_40 += V_36 -> V_45 ;
* V_50 += V_36 -> V_43 ;
F_19 ( V_36 -> V_41 ) ;
}
V_36 -> V_41 -> V_52 = V_36 ;
if ( ! V_36 -> V_41 -> V_54 )
V_36 -> V_41 -> V_54 = log -> V_5 -> V_20 -> V_19 ;
}
static void
F_20 (
struct log * log ,
struct V_34 * V_35 ,
struct V_24 * V_23 )
{
struct V_1 * V_2 = log -> V_5 ;
struct V_3 * V_4 = V_2 -> V_20 ;
struct V_34 * V_36 ;
int V_40 = 0 ;
int V_50 = 0 ;
int V_55 ;
ASSERT ( V_35 ) ;
for ( V_36 = V_35 ; V_36 ; V_36 = V_36 -> V_37 )
F_18 ( log , V_36 , & V_40 , & V_50 ) ;
V_40 += V_50 * sizeof( V_56 ) ;
F_21 ( & V_2 -> V_14 ) ;
for ( V_36 = V_35 ; V_36 ; V_36 = V_36 -> V_37 )
F_22 ( & V_36 -> V_41 -> V_53 , & V_2 -> V_12 ) ;
V_4 -> V_57 += V_50 ;
if ( V_4 -> V_23 -> V_30 == 0 ) {
ASSERT ( V_23 -> V_30 >= V_4 -> V_23 -> V_58 + V_40 ) ;
V_4 -> V_23 -> V_30 = V_4 -> V_23 -> V_58 ;
V_23 -> V_30 -= V_4 -> V_23 -> V_58 ;
}
V_55 = log -> V_59 - log -> V_60 ;
if ( V_40 > 0 && ( V_4 -> V_61 / V_55 !=
( V_4 -> V_61 + V_40 ) / V_55 ) ) {
int V_62 ;
V_62 = ( V_40 + V_55 - 1 ) / V_55 ;
V_62 *= log -> V_60 + sizeof( struct V_63 ) ;
V_4 -> V_23 -> V_58 += V_62 ;
V_4 -> V_23 -> V_30 += V_62 ;
V_23 -> V_30 -= V_62 ;
ASSERT ( V_23 -> V_30 >= V_40 ) ;
}
V_23 -> V_30 -= V_40 ;
V_4 -> V_61 += V_40 ;
F_23 ( & V_2 -> V_14 ) ;
}
static void
F_24 (
struct V_34 * V_35 )
{
struct V_34 * V_36 ;
for ( V_36 = V_35 ; V_36 ; ) {
struct V_34 * V_64 = V_36 -> V_37 ;
F_3 ( V_36 -> V_46 ) ;
F_3 ( V_36 ) ;
V_36 = V_64 ;
}
}
static void
F_25 (
void * args ,
int abort )
{
struct V_3 * V_4 = args ;
struct V_65 * V_66 = V_4 -> V_2 -> V_22 -> V_6 ;
F_26 ( V_4 -> V_2 -> V_22 -> V_67 , V_4 -> V_68 ,
V_4 -> V_69 , abort ) ;
F_27 ( & V_4 -> V_18 ) ;
F_28 ( V_66 , & V_4 -> V_18 ,
( V_66 -> V_7 & V_70 ) && ! abort ) ;
F_21 ( & V_4 -> V_2 -> V_14 ) ;
F_29 ( & V_4 -> V_17 ) ;
F_23 ( & V_4 -> V_2 -> V_14 ) ;
F_24 ( V_4 -> V_68 ) ;
if ( ! F_10 ( & V_4 -> V_18 ) ) {
ASSERT ( V_66 -> V_7 & V_70 ) ;
F_30 ( V_66 , & V_4 -> V_18 ) ;
F_28 ( V_66 , & V_4 -> V_18 , false ) ;
}
F_3 ( V_4 ) ;
}
STATIC int
F_31 (
struct log * log ,
T_1 V_71 )
{
struct V_1 * V_2 = log -> V_5 ;
struct V_34 * V_36 ;
struct V_3 * V_4 ;
struct V_3 * V_72 ;
struct V_73 * V_74 ;
struct V_24 * V_25 ;
int V_75 ;
int V_76 ;
int V_40 ;
int error = 0 ;
struct V_77 V_78 ;
struct V_47 V_79 ;
struct V_34 V_80 = { NULL } ;
T_1 V_31 ;
if ( ! V_2 )
return 0 ;
ASSERT ( ! V_71 || V_71 <= V_2 -> V_20 -> V_19 ) ;
V_72 = F_2 ( sizeof( * V_72 ) , V_9 | V_27 ) ;
V_72 -> V_23 = F_11 ( log ) ;
if ( ! F_32 ( & V_2 -> V_15 ) ) {
if ( ! V_71 &&
V_2 -> V_20 -> V_61 < F_33 ( log ) )
goto V_81;
F_34 ( & V_2 -> V_15 ) ;
}
V_4 = V_2 -> V_20 ;
if ( F_10 ( & V_2 -> V_12 ) )
goto V_82;
if ( ! V_71 && V_2 -> V_20 -> V_61 < F_35 ( log ) )
goto V_82;
if ( V_71 && V_71 < V_2 -> V_20 -> V_19 )
goto V_82;
V_36 = NULL ;
V_75 = 0 ;
V_76 = 0 ;
V_40 = 0 ;
while ( ! F_10 ( & V_2 -> V_12 ) ) {
struct V_83 * V_84 ;
int V_85 ;
V_84 = F_36 ( & V_2 -> V_12 ,
struct V_83 , V_53 ) ;
F_37 ( & V_84 -> V_53 ) ;
if ( ! V_4 -> V_68 )
V_4 -> V_68 = V_84 -> V_52 ;
else
V_36 -> V_37 = V_84 -> V_52 ;
V_36 = V_84 -> V_52 ;
V_84 -> V_52 = NULL ;
V_75 ++ ;
V_76 += V_36 -> V_43 ;
for ( V_85 = 0 ; V_85 < V_36 -> V_43 ; V_85 ++ )
V_40 += V_36 -> V_42 [ V_85 ] . V_44 ;
}
F_4 ( & V_72 -> V_17 ) ;
F_4 ( & V_72 -> V_18 ) ;
V_72 -> V_19 = V_4 -> V_19 + 1 ;
V_72 -> V_2 = V_2 ;
V_2 -> V_20 = V_72 ;
V_2 -> V_21 = V_72 -> V_19 ;
F_21 ( & V_2 -> V_14 ) ;
F_38 ( & V_4 -> V_17 , & V_2 -> V_13 ) ;
F_23 ( & V_2 -> V_14 ) ;
F_39 ( & V_2 -> V_15 ) ;
V_25 = V_4 -> V_23 ;
V_78 . V_86 = V_87 ;
V_78 . V_88 = V_29 ;
V_78 . V_89 = V_25 -> V_90 ;
V_78 . V_91 = V_76 ;
V_79 . V_49 = & V_78 ;
V_79 . V_44 = sizeof( V_92 ) ;
V_79 . V_93 = V_94 ;
V_25 -> V_30 -= V_79 . V_44 + sizeof( V_56 ) ;
V_80 . V_43 = 1 ;
V_80 . V_42 = & V_79 ;
V_80 . V_37 = V_4 -> V_68 ;
error = F_40 ( log , & V_80 , V_25 , & V_4 -> V_69 , NULL , 0 ) ;
if ( error )
goto V_95;
V_96:
F_21 ( & V_2 -> V_14 ) ;
F_41 (new_ctx, &cil->xc_committing, committing) {
if ( V_72 -> V_19 >= V_4 -> V_19 )
continue;
if ( ! V_72 -> V_31 ) {
F_42 ( & V_2 -> V_16 , & V_2 -> V_14 ) ;
goto V_96;
}
}
F_23 ( & V_2 -> V_14 ) ;
V_31 = F_43 ( log -> V_6 , V_25 , & V_74 , 0 ) ;
if ( V_31 == - 1 )
goto V_97;
V_4 -> V_98 . V_99 = F_25 ;
V_4 -> V_98 . V_100 = V_4 ;
error = F_44 ( log -> V_6 , V_74 , & V_4 -> V_98 ) ;
if ( error )
goto V_97;
F_21 ( & V_2 -> V_14 ) ;
V_4 -> V_31 = V_31 ;
F_45 ( & V_2 -> V_16 ) ;
F_23 ( & V_2 -> V_14 ) ;
return F_46 ( log -> V_6 , V_74 ) ;
V_82:
F_39 ( & V_2 -> V_15 ) ;
V_81:
F_9 ( V_72 -> V_23 ) ;
F_3 ( V_72 ) ;
return 0 ;
V_95:
F_9 ( V_25 ) ;
V_97:
F_25 ( V_4 , V_101 ) ;
return F_47 ( V_102 ) ;
}
void
F_48 (
struct V_65 * V_66 ,
struct V_103 * V_104 ,
struct V_34 * V_35 ,
T_1 * V_31 ,
int V_105 )
{
struct log * log = V_66 -> V_106 ;
int V_107 = 0 ;
int V_108 = 0 ;
if ( V_105 & V_109 )
V_107 = V_110 ;
F_15 ( log , V_35 ) ;
F_49 ( & log -> V_5 -> V_15 ) ;
if ( V_31 )
* V_31 = log -> V_5 -> V_20 -> V_19 ;
F_20 ( log , V_35 , V_104 -> V_111 ) ;
if ( V_104 -> V_111 -> V_30 < 0 )
F_50 ( log -> V_6 , V_104 -> V_111 ) ;
if ( ! F_10 ( & V_104 -> V_112 ) ) {
F_21 ( & log -> V_5 -> V_14 ) ;
F_51 ( & V_104 -> V_112 ,
& log -> V_5 -> V_20 -> V_18 ) ;
F_23 ( & log -> V_5 -> V_14 ) ;
}
V_104 -> V_113 = * V_31 ;
F_43 ( V_66 , V_104 -> V_111 , NULL , V_107 ) ;
F_52 ( V_104 ) ;
F_53 ( V_104 , * V_31 , 0 ) ;
if ( log -> V_5 -> V_20 -> V_61 > F_35 ( log ) )
V_108 = 1 ;
F_54 ( & log -> V_5 -> V_15 ) ;
if ( V_108 )
F_31 ( log , 0 ) ;
}
T_1
F_55 (
struct log * log ,
T_1 V_19 )
{
struct V_1 * V_2 = log -> V_5 ;
struct V_3 * V_4 ;
T_1 V_31 = V_114 ;
ASSERT ( V_19 <= V_2 -> V_21 ) ;
if ( V_19 == V_2 -> V_21 )
F_31 ( log , V_19 ) ;
V_96:
F_21 ( & V_2 -> V_14 ) ;
F_41 (ctx, &cil->xc_committing, committing) {
if ( V_4 -> V_19 > V_19 )
continue;
if ( ! V_4 -> V_31 ) {
F_42 ( & V_2 -> V_16 , & V_2 -> V_14 ) ;
goto V_96;
}
if ( V_4 -> V_19 != V_19 )
continue;
V_31 = V_4 -> V_31 ;
}
F_23 ( & V_2 -> V_14 ) ;
return V_31 ;
}
bool
F_56 (
struct V_83 * V_115 )
{
struct V_3 * V_4 ;
if ( ! ( V_115 -> V_116 -> V_7 & V_8 ) )
return false ;
if ( F_10 ( & V_115 -> V_53 ) )
return false ;
V_4 = V_115 -> V_116 -> V_106 -> V_5 -> V_20 ;
if ( F_57 ( V_115 -> V_54 , V_4 -> V_19 ) != 0 )
return false ;
return true ;
}
