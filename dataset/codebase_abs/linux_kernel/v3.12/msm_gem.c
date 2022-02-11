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
int F_15 ( struct V_2 * V_3 ,
struct V_20 * V_21 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_21 -> V_22 &= ~ V_23 ;
V_21 -> V_22 |= V_24 ;
if ( V_5 -> V_14 & V_15 ) {
V_21 -> V_25 = F_16 ( F_17 ( V_21 -> V_22 ) ) ;
} else if ( V_5 -> V_14 & V_16 ) {
V_21 -> V_25 = F_18 ( F_17 ( V_21 -> V_22 ) ) ;
} else {
F_19 ( V_21 -> V_26 ) ;
F_20 ( V_3 -> V_27 ) ;
V_21 -> V_28 = 0 ;
V_21 -> V_26 = V_3 -> V_27 ;
V_21 -> V_25 = F_17 ( V_21 -> V_22 ) ;
}
return 0 ;
}
int F_21 ( struct V_29 * V_27 , struct V_20 * V_21 )
{
int V_30 ;
V_30 = F_22 ( V_27 , V_21 ) ;
if ( V_30 ) {
F_23 ( L_3 , V_30 ) ;
return V_30 ;
}
return F_15 ( V_21 -> V_31 , V_21 ) ;
}
int F_24 ( struct V_20 * V_21 , struct V_32 * V_33 )
{
struct V_2 * V_3 = V_21 -> V_31 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_1 * * V_6 ;
unsigned long V_34 ;
T_1 V_35 ;
int V_30 ;
V_30 = F_25 ( & V_8 -> V_36 ) ;
if ( V_30 )
goto V_37;
V_6 = F_1 ( V_3 ) ;
if ( F_4 ( V_6 ) ) {
V_30 = F_6 ( V_6 ) ;
goto V_38;
}
V_35 = ( ( unsigned long ) V_33 -> V_39 -
V_21 -> V_40 ) >> V_12 ;
V_34 = F_26 ( V_5 -> V_6 [ V_35 ] ) ;
F_27 ( L_4 , V_33 -> V_39 ,
V_34 , V_34 << V_12 ) ;
V_30 = F_28 ( V_21 , ( unsigned long ) V_33 -> V_39 , V_34 ) ;
V_38:
F_29 ( & V_8 -> V_36 ) ;
V_37:
switch ( V_30 ) {
case - V_41 :
case 0 :
case - V_42 :
case - V_43 :
return V_44 ;
case - V_45 :
return V_46 ;
default:
return V_47 ;
}
}
static T_2 F_30 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
int V_30 ;
F_31 ( ! F_32 ( & V_8 -> V_36 ) ) ;
V_30 = F_33 ( V_3 ) ;
if ( V_30 ) {
F_5 ( V_8 -> V_8 , L_5 ) ;
return 0 ;
}
return F_34 ( & V_3 -> V_48 ) ;
}
T_2 F_35 ( struct V_2 * V_3 )
{
T_2 V_49 ;
F_36 ( & V_3 -> V_8 -> V_36 ) ;
V_49 = F_30 ( V_3 ) ;
F_29 ( & V_3 -> V_8 -> V_36 ) ;
return V_49 ;
}
static int F_37 ( struct V_50 * V_51 , unsigned int V_52 ,
struct V_53 * V_13 , unsigned int V_54 , int V_55 )
{
struct V_56 * V_57 ;
unsigned int V_58 = V_52 ;
unsigned int V_59 , V_60 ;
int V_30 ;
if ( ! V_51 || ! V_13 )
return - V_61 ;
F_38 (sgt->sgl, sg, sgt->nents, i) {
T_3 V_62 = F_39 ( V_57 ) - V_57 -> V_49 ;
T_4 V_63 = V_57 -> V_64 + V_57 -> V_49 ;
F_27 ( L_6 , V_59 , V_52 , V_62 , V_63 ) ;
V_30 = F_40 ( V_51 , V_58 , V_62 , V_63 , V_55 ) ;
if ( V_30 )
goto V_65;
V_58 += V_63 ;
}
return 0 ;
V_65:
V_58 = V_52 ;
F_38 (sgt->sgl, sg, i, j) {
T_4 V_63 = V_57 -> V_64 + V_57 -> V_49 ;
F_41 ( V_51 , V_58 , V_63 ) ;
V_58 += V_63 ;
}
return V_30 ;
}
static void F_42 ( struct V_50 * V_51 , unsigned int V_52 ,
struct V_53 * V_13 , unsigned int V_54 )
{
struct V_56 * V_57 ;
unsigned int V_58 = V_52 ;
int V_59 ;
F_38 (sgt->sgl, sg, sgt->nents, i) {
T_4 V_63 = V_57 -> V_64 + V_57 -> V_49 ;
T_4 V_66 ;
V_66 = F_41 ( V_51 , V_58 , V_63 ) ;
if ( V_66 < V_63 )
break;
F_27 ( L_7 , V_59 , V_52 , V_63 ) ;
F_43 ( ! F_44 ( V_63 , V_67 ) ) ;
V_58 += V_63 ;
}
}
int F_45 ( struct V_2 * V_3 , int V_68 ,
T_5 * V_52 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_30 = 0 ;
if ( ! V_5 -> V_51 [ V_68 ] . V_52 ) {
struct V_69 * V_70 = V_3 -> V_8 -> V_71 ;
T_5 V_49 = ( T_5 ) F_30 ( V_3 ) ;
struct V_1 * * V_6 ;
V_6 = F_1 ( V_3 ) ;
if ( F_4 ( V_6 ) )
return F_6 ( V_6 ) ;
V_30 = F_37 ( V_70 -> V_72 [ V_68 ] , V_49 , V_5 -> V_13 ,
V_3 -> V_11 , V_73 | V_74 ) ;
V_5 -> V_51 [ V_68 ] . V_52 = V_49 ;
}
if ( ! V_30 )
* V_52 = V_5 -> V_51 [ V_68 ] . V_52 ;
return V_30 ;
}
int F_46 ( struct V_2 * V_3 , int V_68 , T_5 * V_52 )
{
int V_30 ;
F_36 ( & V_3 -> V_8 -> V_36 ) ;
V_30 = F_45 ( V_3 , V_68 , V_52 ) ;
F_29 ( & V_3 -> V_8 -> V_36 ) ;
return V_30 ;
}
void F_47 ( struct V_2 * V_3 , int V_68 )
{
}
int F_48 ( struct V_75 * V_29 , struct V_7 * V_8 ,
struct V_76 * args )
{
args -> V_77 = F_49 ( args -> V_78 , args -> V_79 ) ;
args -> V_11 = F_50 ( args -> V_77 * args -> V_80 ) ;
return F_51 ( V_8 , V_29 , args -> V_11 ,
V_81 | V_15 , & args -> V_82 ) ;
}
int F_52 ( struct V_75 * V_29 , struct V_7 * V_8 ,
T_5 V_82 , T_2 * V_49 )
{
struct V_2 * V_3 ;
int V_30 = 0 ;
V_3 = F_53 ( V_8 , V_29 , V_82 ) ;
if ( V_3 == NULL ) {
V_30 = - V_83 ;
goto V_65;
}
* V_49 = F_35 ( V_3 ) ;
F_54 ( V_3 ) ;
V_65:
return V_30 ;
}
void * F_55 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_31 ( ! F_32 ( & V_3 -> V_8 -> V_36 ) ) ;
if ( ! V_5 -> V_84 ) {
struct V_1 * * V_6 = F_1 ( V_3 ) ;
if ( F_4 ( V_6 ) )
return F_8 ( V_6 ) ;
V_5 -> V_84 = F_56 ( V_6 , V_3 -> V_11 >> V_12 ,
V_85 , F_16 ( V_86 ) ) ;
}
return V_5 -> V_84 ;
}
void * F_57 ( struct V_2 * V_3 )
{
void * V_30 ;
F_36 ( & V_3 -> V_8 -> V_36 ) ;
V_30 = F_55 ( V_3 ) ;
F_29 ( & V_3 -> V_8 -> V_36 ) ;
return V_30 ;
}
int F_58 ( struct V_2 * V_3 ,
struct V_87 * V_88 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_69 * V_70 = V_8 -> V_71 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_30 = 0 ;
F_36 ( & V_8 -> V_36 ) ;
if ( ! F_59 ( & V_88 -> V_89 ) ) {
V_30 = - V_61 ;
} else if ( F_60 ( V_5 ) ) {
F_61 ( & V_88 -> V_89 , & V_5 -> V_90 ) ;
} else {
F_62 ( V_70 -> V_91 , V_88 ) ;
}
F_29 ( & V_8 -> V_36 ) ;
return V_30 ;
}
void F_63 ( struct V_2 * V_3 ,
struct V_92 * V_93 , bool V_94 , T_5 V_95 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_5 -> V_93 = V_93 ;
if ( V_94 )
V_5 -> V_96 = V_95 ;
else
V_5 -> V_97 = V_95 ;
F_64 ( & V_5 -> V_98 ) ;
F_61 ( & V_5 -> V_98 , & V_93 -> V_99 ) ;
}
void F_65 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_69 * V_70 = V_8 -> V_71 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_31 ( ! F_32 ( & V_8 -> V_36 ) ) ;
V_5 -> V_93 = NULL ;
V_5 -> V_97 = 0 ;
V_5 -> V_96 = 0 ;
F_64 ( & V_5 -> V_98 ) ;
F_61 ( & V_5 -> V_98 , & V_70 -> V_100 ) ;
while ( ! F_59 ( & V_5 -> V_90 ) ) {
struct V_87 * V_88 ;
V_88 = F_66 ( & V_5 -> V_90 ,
struct V_87 , V_89 ) ;
F_64 ( & V_88 -> V_89 ) ;
F_62 ( V_70 -> V_91 , V_88 ) ;
}
}
int F_67 ( struct V_2 * V_3 , T_5 V_101 ,
struct V_102 * V_103 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_30 = 0 ;
if ( F_60 ( V_5 ) ) {
T_5 V_95 = 0 ;
if ( V_101 & V_104 )
V_95 = V_5 -> V_96 ;
if ( V_101 & V_105 )
V_95 = F_68 ( V_95 , V_5 -> V_97 ) ;
if ( V_101 & V_106 )
V_103 = NULL ;
V_30 = F_69 ( V_8 , V_95 , V_103 ) ;
}
return V_30 ;
}
int F_70 ( struct V_2 * V_3 )
{
return 0 ;
}
void F_71 ( struct V_2 * V_3 , struct V_107 * V_108 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_2 V_109 = F_72 ( & V_3 -> V_48 ) ;
F_31 ( ! F_32 ( & V_8 -> V_36 ) ) ;
F_73 ( V_108 , L_8 ,
V_5 -> V_14 , F_60 ( V_5 ) ? 'A' : 'I' ,
V_5 -> V_97 , V_5 -> V_96 ,
V_3 -> V_110 , V_3 -> V_111 . V_111 . V_112 ,
V_109 , V_5 -> V_84 , V_3 -> V_11 ) ;
}
void F_74 ( struct V_113 * V_114 , struct V_107 * V_108 )
{
struct V_4 * V_5 ;
int V_115 = 0 ;
T_4 V_11 = 0 ;
F_75 (msm_obj, list, mm_list) {
struct V_2 * V_3 = & V_5 -> V_116 ;
F_73 ( V_108 , L_9 ) ;
F_71 ( V_3 , V_108 ) ;
V_115 ++ ;
V_11 += V_3 -> V_11 ;
}
F_73 ( V_108 , L_10 , V_115 , V_11 ) ;
}
void F_76 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_68 ;
F_31 ( ! F_32 ( & V_8 -> V_36 ) ) ;
F_31 ( F_60 ( V_5 ) ) ;
F_77 ( & V_5 -> V_98 ) ;
for ( V_68 = 0 ; V_68 < F_78 ( V_5 -> V_51 ) ; V_68 ++ ) {
if ( V_5 -> V_51 [ V_68 ] . V_52 ) {
struct V_69 * V_70 = V_3 -> V_8 -> V_71 ;
T_5 V_49 = ( T_5 ) F_30 ( V_3 ) ;
F_42 ( V_70 -> V_72 [ V_68 ] , V_49 ,
V_5 -> V_13 , V_3 -> V_11 ) ;
}
}
F_79 ( V_3 ) ;
if ( V_5 -> V_84 )
F_80 ( V_5 -> V_84 ) ;
F_10 ( V_3 ) ;
if ( V_5 -> V_117 == & V_5 -> V_118 )
F_81 ( V_5 -> V_117 ) ;
F_82 ( V_3 ) ;
F_13 ( V_5 ) ;
}
int F_51 ( struct V_7 * V_8 , struct V_75 * V_29 ,
T_5 V_11 , T_5 V_14 , T_5 * V_82 )
{
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_25 ( & V_8 -> V_36 ) ;
if ( V_30 )
return V_30 ;
V_3 = F_83 ( V_8 , V_11 , V_14 ) ;
F_29 ( & V_8 -> V_36 ) ;
if ( F_4 ( V_3 ) )
return F_6 ( V_3 ) ;
V_30 = F_84 ( V_29 , V_3 , V_82 ) ;
F_54 ( V_3 ) ;
return V_30 ;
}
struct V_2 * F_83 ( struct V_7 * V_8 ,
T_5 V_11 , T_5 V_14 )
{
struct V_69 * V_70 = V_8 -> V_71 ;
struct V_4 * V_5 ;
struct V_2 * V_3 = NULL ;
int V_30 ;
F_31 ( ! F_32 ( & V_8 -> V_36 ) ) ;
V_11 = F_50 ( V_11 ) ;
switch ( V_14 & V_119 ) {
case V_16 :
case V_120 :
case V_15 :
break;
default:
F_5 ( V_8 -> V_8 , L_11 ,
( V_14 & V_119 ) ) ;
V_30 = - V_61 ;
goto V_65;
}
V_5 = F_85 ( sizeof( * V_5 ) , V_121 ) ;
if ( ! V_5 ) {
V_30 = - V_45 ;
goto V_65;
}
V_3 = & V_5 -> V_116 ;
V_30 = F_86 ( V_8 , V_3 , V_11 ) ;
if ( V_30 )
goto V_65;
V_5 -> V_14 = V_14 ;
V_5 -> V_117 = & V_5 -> V_118 ;
F_87 ( V_5 -> V_117 ) ;
F_88 ( & V_5 -> V_122 ) ;
F_88 ( & V_5 -> V_90 ) ;
F_61 ( & V_5 -> V_98 , & V_70 -> V_100 ) ;
return V_3 ;
V_65:
if ( V_3 )
F_54 ( V_3 ) ;
return F_89 ( V_30 ) ;
}
