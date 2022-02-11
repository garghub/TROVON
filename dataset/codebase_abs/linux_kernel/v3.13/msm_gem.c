static struct V_1 * * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( ! V_5 -> V_6 ) {
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_1 * * V_9 = F_3 ( V_3 , 0 ) ;
int V_10 = V_3 -> V_11 >> V_12 ;
if ( F_4 ( V_9 ) ) {
F_5 ( V_8 -> V_8 , L_1 ,
F_6 ( V_9 ) ) ;
return V_9 ;
}
V_5 -> V_13 = F_7 ( V_9 , V_10 ) ;
if ( F_4 ( V_5 -> V_13 ) ) {
F_5 ( V_8 -> V_8 , L_2 ) ;
return F_8 ( V_5 -> V_13 ) ;
}
V_5 -> V_6 = V_9 ;
if ( V_5 -> V_14 & ( V_15 | V_16 ) )
F_9 ( V_8 -> V_8 , V_5 -> V_13 -> V_17 ,
V_5 -> V_13 -> V_18 , V_19 ) ;
}
return V_5 -> V_6 ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 -> V_6 ) {
if ( V_5 -> V_14 & ( V_15 | V_16 ) )
F_11 ( V_3 -> V_8 -> V_8 , V_5 -> V_13 -> V_17 ,
V_5 -> V_13 -> V_18 , V_19 ) ;
F_12 ( V_5 -> V_13 ) ;
F_13 ( V_5 -> V_13 ) ;
F_14 ( V_3 , V_5 -> V_6 , true , false ) ;
V_5 -> V_6 = NULL ;
}
}
struct V_1 * * F_15 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_1 * * V_9 ;
F_16 ( & V_8 -> V_20 ) ;
V_9 = F_1 ( V_3 ) ;
F_17 ( & V_8 -> V_20 ) ;
return V_9 ;
}
void F_18 ( struct V_2 * V_3 )
{
}
int F_19 ( struct V_2 * V_3 ,
struct V_21 * V_22 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_22 -> V_23 &= ~ V_24 ;
V_22 -> V_23 |= V_25 ;
if ( V_5 -> V_14 & V_15 ) {
V_22 -> V_26 = F_20 ( F_21 ( V_22 -> V_23 ) ) ;
} else if ( V_5 -> V_14 & V_16 ) {
V_22 -> V_26 = F_22 ( F_21 ( V_22 -> V_23 ) ) ;
} else {
F_23 ( V_22 -> V_27 ) ;
F_24 ( V_3 -> V_28 ) ;
V_22 -> V_29 = 0 ;
V_22 -> V_27 = V_3 -> V_28 ;
V_22 -> V_26 = F_21 ( V_22 -> V_23 ) ;
}
return 0 ;
}
int F_25 ( struct V_30 * V_28 , struct V_21 * V_22 )
{
int V_31 ;
V_31 = F_26 ( V_28 , V_22 ) ;
if ( V_31 ) {
F_27 ( L_3 , V_31 ) ;
return V_31 ;
}
return F_19 ( V_22 -> V_32 , V_22 ) ;
}
int F_28 ( struct V_21 * V_22 , struct V_33 * V_34 )
{
struct V_2 * V_3 = V_22 -> V_32 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_1 * * V_6 ;
unsigned long V_35 ;
T_1 V_36 ;
int V_31 ;
V_31 = F_29 ( & V_8 -> V_20 ) ;
if ( V_31 )
goto V_37;
V_6 = F_1 ( V_3 ) ;
if ( F_4 ( V_6 ) ) {
V_31 = F_6 ( V_6 ) ;
goto V_38;
}
V_36 = ( ( unsigned long ) V_34 -> V_39 -
V_22 -> V_40 ) >> V_12 ;
V_35 = F_30 ( V_5 -> V_6 [ V_36 ] ) ;
F_31 ( L_4 , V_34 -> V_39 ,
V_35 , V_35 << V_12 ) ;
V_31 = F_32 ( V_22 , ( unsigned long ) V_34 -> V_39 , V_35 ) ;
V_38:
F_17 ( & V_8 -> V_20 ) ;
V_37:
switch ( V_31 ) {
case - V_41 :
case 0 :
case - V_42 :
case - V_43 :
case - V_44 :
return V_45 ;
case - V_46 :
return V_47 ;
default:
return V_48 ;
}
}
static T_2 F_33 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
int V_31 ;
F_34 ( ! F_35 ( & V_8 -> V_20 ) ) ;
V_31 = F_36 ( V_3 ) ;
if ( V_31 ) {
F_5 ( V_8 -> V_8 , L_5 ) ;
return 0 ;
}
return F_37 ( & V_3 -> V_49 ) ;
}
T_2 F_38 ( struct V_2 * V_3 )
{
T_2 V_50 ;
F_16 ( & V_3 -> V_8 -> V_20 ) ;
V_50 = F_33 ( V_3 ) ;
F_17 ( & V_3 -> V_8 -> V_20 ) ;
return V_50 ;
}
static int F_39 ( struct V_51 * V_52 , unsigned int V_53 ,
struct V_54 * V_13 , unsigned int V_55 , int V_56 )
{
struct V_57 * V_58 ;
unsigned int V_59 = V_53 ;
unsigned int V_60 , V_61 ;
int V_31 ;
if ( ! V_52 || ! V_13 )
return - V_62 ;
F_40 (sgt->sgl, sg, sgt->nents, i) {
T_3 V_63 = F_41 ( V_58 ) - V_58 -> V_50 ;
T_4 V_64 = V_58 -> V_65 + V_58 -> V_50 ;
F_31 ( L_6 , V_60 , V_53 , V_63 , V_64 ) ;
V_31 = F_42 ( V_52 , V_59 , V_63 , V_64 , V_56 ) ;
if ( V_31 )
goto V_66;
V_59 += V_64 ;
}
return 0 ;
V_66:
V_59 = V_53 ;
F_40 (sgt->sgl, sg, i, j) {
T_4 V_64 = V_58 -> V_65 + V_58 -> V_50 ;
F_43 ( V_52 , V_59 , V_64 ) ;
V_59 += V_64 ;
}
return V_31 ;
}
static void F_44 ( struct V_51 * V_52 , unsigned int V_53 ,
struct V_54 * V_13 , unsigned int V_55 )
{
struct V_57 * V_58 ;
unsigned int V_59 = V_53 ;
int V_60 ;
F_40 (sgt->sgl, sg, sgt->nents, i) {
T_4 V_64 = V_58 -> V_65 + V_58 -> V_50 ;
T_4 V_67 ;
V_67 = F_43 ( V_52 , V_59 , V_64 ) ;
if ( V_67 < V_64 )
break;
F_31 ( L_7 , V_60 , V_53 , V_64 ) ;
F_45 ( ! F_46 ( V_64 , V_68 ) ) ;
V_59 += V_64 ;
}
}
int F_47 ( struct V_2 * V_3 , int V_69 ,
T_5 * V_53 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_31 = 0 ;
if ( ! V_5 -> V_52 [ V_69 ] . V_53 ) {
struct V_70 * V_71 = V_3 -> V_8 -> V_72 ;
T_5 V_50 = ( T_5 ) F_33 ( V_3 ) ;
struct V_1 * * V_6 ;
V_6 = F_1 ( V_3 ) ;
if ( F_4 ( V_6 ) )
return F_6 ( V_6 ) ;
V_31 = F_39 ( V_71 -> V_73 [ V_69 ] , V_50 , V_5 -> V_13 ,
V_3 -> V_11 , V_74 | V_75 ) ;
V_5 -> V_52 [ V_69 ] . V_53 = V_50 ;
}
if ( ! V_31 )
* V_53 = V_5 -> V_52 [ V_69 ] . V_53 ;
return V_31 ;
}
int F_48 ( struct V_2 * V_3 , int V_69 , T_5 * V_53 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_31 ;
if ( V_5 -> V_52 [ V_69 ] . V_53 ) {
* V_53 = V_5 -> V_52 [ V_69 ] . V_53 ;
return 0 ;
}
F_16 ( & V_3 -> V_8 -> V_20 ) ;
V_31 = F_47 ( V_3 , V_69 , V_53 ) ;
F_17 ( & V_3 -> V_8 -> V_20 ) ;
return V_31 ;
}
void F_49 ( struct V_2 * V_3 , int V_69 )
{
}
int F_50 ( struct V_76 * V_30 , struct V_7 * V_8 ,
struct V_77 * args )
{
args -> V_78 = F_51 ( args -> V_79 , args -> V_80 ) ;
args -> V_11 = F_52 ( args -> V_78 * args -> V_81 ) ;
return F_53 ( V_8 , V_30 , args -> V_11 ,
V_82 | V_15 , & args -> V_83 ) ;
}
int F_54 ( struct V_76 * V_30 , struct V_7 * V_8 ,
T_5 V_83 , T_2 * V_50 )
{
struct V_2 * V_3 ;
int V_31 = 0 ;
V_3 = F_55 ( V_8 , V_30 , V_83 ) ;
if ( V_3 == NULL ) {
V_31 = - V_84 ;
goto V_66;
}
* V_50 = F_38 ( V_3 ) ;
F_56 ( V_3 ) ;
V_66:
return V_31 ;
}
void * F_57 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_34 ( ! F_35 ( & V_3 -> V_8 -> V_20 ) ) ;
if ( ! V_5 -> V_85 ) {
struct V_1 * * V_6 = F_1 ( V_3 ) ;
if ( F_4 ( V_6 ) )
return F_8 ( V_6 ) ;
V_5 -> V_85 = F_58 ( V_6 , V_3 -> V_11 >> V_12 ,
V_86 , F_20 ( V_87 ) ) ;
}
return V_5 -> V_85 ;
}
void * F_59 ( struct V_2 * V_3 )
{
void * V_31 ;
F_16 ( & V_3 -> V_8 -> V_20 ) ;
V_31 = F_57 ( V_3 ) ;
F_17 ( & V_3 -> V_8 -> V_20 ) ;
return V_31 ;
}
int F_60 ( struct V_2 * V_3 ,
struct V_88 * V_89 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_70 * V_71 = V_8 -> V_72 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_31 = 0 ;
F_16 ( & V_8 -> V_20 ) ;
if ( ! F_61 ( & V_89 -> V_90 . V_91 ) ) {
V_31 = - V_62 ;
} else if ( F_62 ( V_5 ) ) {
V_89 -> V_92 = F_63 ( V_5 -> V_93 , V_5 -> V_94 ) ;
F_64 ( & V_89 -> V_90 . V_91 , & V_71 -> V_95 ) ;
} else {
F_65 ( V_71 -> V_96 , & V_89 -> V_90 ) ;
}
F_17 ( & V_8 -> V_20 ) ;
return V_31 ;
}
void F_66 ( struct V_2 * V_3 ,
struct V_97 * V_98 , bool V_99 , T_5 V_92 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_5 -> V_98 = V_98 ;
if ( V_99 )
V_5 -> V_94 = V_92 ;
else
V_5 -> V_93 = V_92 ;
F_67 ( & V_5 -> V_100 ) ;
F_64 ( & V_5 -> V_100 , & V_98 -> V_101 ) ;
}
void F_68 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_70 * V_71 = V_8 -> V_72 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_34 ( ! F_35 ( & V_8 -> V_20 ) ) ;
V_5 -> V_98 = NULL ;
V_5 -> V_93 = 0 ;
V_5 -> V_94 = 0 ;
F_67 ( & V_5 -> V_100 ) ;
F_64 ( & V_5 -> V_100 , & V_71 -> V_102 ) ;
}
int F_69 ( struct V_2 * V_3 , T_5 V_103 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_31 = 0 ;
if ( F_62 ( V_5 ) ) {
T_5 V_92 = 0 ;
if ( V_103 & V_106 )
V_92 = V_5 -> V_94 ;
if ( V_103 & V_107 )
V_92 = F_63 ( V_92 , V_5 -> V_93 ) ;
if ( V_103 & V_108 )
V_105 = NULL ;
V_31 = F_70 ( V_8 , V_92 , V_105 ) ;
}
return V_31 ;
}
int F_71 ( struct V_2 * V_3 )
{
return 0 ;
}
void F_72 ( struct V_2 * V_3 , struct V_109 * V_110 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_2 V_111 = F_73 ( & V_3 -> V_49 ) ;
F_34 ( ! F_35 ( & V_8 -> V_20 ) ) ;
F_74 ( V_110 , L_8 ,
V_5 -> V_14 , F_62 ( V_5 ) ? 'A' : 'I' ,
V_5 -> V_93 , V_5 -> V_94 ,
V_3 -> V_112 , V_3 -> V_113 . V_113 . V_114 ,
V_111 , V_5 -> V_85 , V_3 -> V_11 ) ;
}
void F_75 ( struct V_115 * V_116 , struct V_109 * V_110 )
{
struct V_4 * V_5 ;
int V_117 = 0 ;
T_4 V_11 = 0 ;
F_76 (msm_obj, list, mm_list) {
struct V_2 * V_3 = & V_5 -> V_118 ;
F_74 ( V_110 , L_9 ) ;
F_72 ( V_3 , V_110 ) ;
V_117 ++ ;
V_11 += V_3 -> V_11 ;
}
F_74 ( V_110 , L_10 , V_117 , V_11 ) ;
}
void F_77 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_69 ;
F_34 ( ! F_35 ( & V_8 -> V_20 ) ) ;
F_34 ( F_62 ( V_5 ) ) ;
F_78 ( & V_5 -> V_100 ) ;
for ( V_69 = 0 ; V_69 < F_79 ( V_5 -> V_52 ) ; V_69 ++ ) {
if ( V_5 -> V_52 [ V_69 ] . V_53 ) {
struct V_70 * V_71 = V_3 -> V_8 -> V_72 ;
T_5 V_50 = ( T_5 ) F_33 ( V_3 ) ;
F_44 ( V_71 -> V_73 [ V_69 ] , V_50 ,
V_5 -> V_13 , V_3 -> V_11 ) ;
}
}
F_80 ( V_3 ) ;
if ( V_3 -> V_119 ) {
if ( V_5 -> V_85 )
F_81 ( V_3 -> V_119 -> V_120 , V_5 -> V_85 ) ;
if ( V_5 -> V_6 )
F_82 ( V_5 -> V_6 ) ;
} else {
if ( V_5 -> V_85 )
F_83 ( V_5 -> V_85 ) ;
F_10 ( V_3 ) ;
}
if ( V_5 -> V_121 == & V_5 -> V_122 )
F_84 ( V_5 -> V_121 ) ;
F_85 ( V_3 ) ;
F_13 ( V_5 ) ;
}
int F_53 ( struct V_7 * V_8 , struct V_76 * V_30 ,
T_5 V_11 , T_5 V_14 , T_5 * V_83 )
{
struct V_2 * V_3 ;
int V_31 ;
V_31 = F_29 ( & V_8 -> V_20 ) ;
if ( V_31 )
return V_31 ;
V_3 = F_86 ( V_8 , V_11 , V_14 ) ;
F_17 ( & V_8 -> V_20 ) ;
if ( F_4 ( V_3 ) )
return F_6 ( V_3 ) ;
V_31 = F_87 ( V_30 , V_3 , V_83 ) ;
F_56 ( V_3 ) ;
return V_31 ;
}
static int F_88 ( struct V_7 * V_8 ,
T_5 V_11 , T_5 V_14 ,
struct V_2 * * V_3 )
{
struct V_70 * V_71 = V_8 -> V_72 ;
struct V_4 * V_5 ;
switch ( V_14 & V_123 ) {
case V_16 :
case V_124 :
case V_15 :
break;
default:
F_5 ( V_8 -> V_8 , L_11 ,
( V_14 & V_123 ) ) ;
return - V_62 ;
}
V_5 = F_89 ( sizeof( * V_5 ) , V_125 ) ;
if ( ! V_5 )
return - V_46 ;
V_5 -> V_14 = V_14 ;
V_5 -> V_121 = & V_5 -> V_122 ;
F_90 ( V_5 -> V_121 ) ;
F_91 ( & V_5 -> V_126 ) ;
F_64 ( & V_5 -> V_100 , & V_71 -> V_102 ) ;
* V_3 = & V_5 -> V_118 ;
return 0 ;
}
struct V_2 * F_86 ( struct V_7 * V_8 ,
T_5 V_11 , T_5 V_14 )
{
struct V_2 * V_3 ;
int V_31 ;
F_34 ( ! F_35 ( & V_8 -> V_20 ) ) ;
V_11 = F_52 ( V_11 ) ;
V_31 = F_88 ( V_8 , V_11 , V_14 , & V_3 ) ;
if ( V_31 )
goto V_66;
V_31 = F_92 ( V_8 , V_3 , V_11 ) ;
if ( V_31 )
goto V_66;
return V_3 ;
V_66:
if ( V_3 )
F_56 ( V_3 ) ;
return F_93 ( V_31 ) ;
}
struct V_2 * F_94 ( struct V_7 * V_8 ,
T_5 V_11 , struct V_54 * V_13 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
int V_31 , V_10 ;
V_11 = F_52 ( V_11 ) ;
V_31 = F_88 ( V_8 , V_11 , V_15 , & V_3 ) ;
if ( V_31 )
goto V_66;
F_95 ( V_8 , V_3 , V_11 ) ;
V_10 = V_11 / V_68 ;
V_5 = F_2 ( V_3 ) ;
V_5 -> V_13 = V_13 ;
V_5 -> V_6 = F_96 ( V_10 , sizeof( struct V_1 * ) ) ;
if ( ! V_5 -> V_6 ) {
V_31 = - V_46 ;
goto V_66;
}
V_31 = F_97 ( V_13 , V_5 -> V_6 , NULL , V_10 ) ;
if ( V_31 )
goto V_66;
return V_3 ;
V_66:
if ( V_3 )
F_56 ( V_3 ) ;
return F_93 ( V_31 ) ;
}
