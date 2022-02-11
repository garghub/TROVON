static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
return ( ( ( T_1 ) V_4 -> V_9 -> V_10 ) << V_11 ) +
V_6 -> V_12 . V_13 ;
}
static bool F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ! V_4 -> V_9 ;
}
static struct V_14 * * F_4 ( struct V_1 * V_2 ,
int V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
T_1 V_13 ;
struct V_14 * * V_16 ;
int V_17 , V_18 ;
V_16 = F_5 ( V_15 , sizeof( struct V_14 * ) ) ;
if ( ! V_16 )
return F_6 ( - V_19 ) ;
V_17 = F_7 ( & V_6 -> V_12 . V_20 , V_4 -> V_9 ,
V_15 , 0 , V_21 ) ;
if ( V_17 ) {
F_8 ( V_16 ) ;
return F_6 ( V_17 ) ;
}
V_13 = F_1 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_15 ; V_18 ++ ) {
V_16 [ V_18 ] = F_9 ( V_13 ) ;
V_13 += V_22 ;
}
return V_16 ;
}
static struct V_14 * * F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_23 ) {
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_14 * * V_16 ;
int V_15 = V_2 -> V_25 >> V_11 ;
if ( F_3 ( V_2 ) )
V_16 = F_11 ( V_2 ) ;
else
V_16 = F_4 ( V_2 , V_15 ) ;
if ( F_12 ( V_16 ) ) {
F_13 ( V_7 -> V_7 , L_1 ,
F_14 ( V_16 ) ) ;
return V_16 ;
}
V_4 -> V_26 = F_15 ( V_16 , V_15 ) ;
if ( F_12 ( V_4 -> V_26 ) ) {
F_13 ( V_7 -> V_7 , L_2 ) ;
return F_16 ( V_4 -> V_26 ) ;
}
V_4 -> V_23 = V_16 ;
if ( V_4 -> V_27 & ( V_28 | V_29 ) )
F_17 ( V_7 -> V_7 , V_4 -> V_26 -> V_30 ,
V_4 -> V_26 -> V_31 , V_32 ) ;
}
return V_4 -> V_23 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_23 ) {
if ( V_4 -> V_27 & ( V_28 | V_29 ) )
F_19 ( V_2 -> V_7 -> V_7 , V_4 -> V_26 -> V_30 ,
V_4 -> V_26 -> V_31 , V_32 ) ;
F_20 ( V_4 -> V_26 ) ;
F_21 ( V_4 -> V_26 ) ;
if ( F_3 ( V_2 ) )
F_22 ( V_2 , V_4 -> V_23 , true , false ) ;
else {
F_23 ( V_4 -> V_9 ) ;
F_8 ( V_4 -> V_23 ) ;
}
V_4 -> V_23 = NULL ;
}
}
struct V_14 * * F_24 ( struct V_1 * V_2 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_14 * * V_16 ;
F_25 ( & V_7 -> V_33 ) ;
V_16 = F_10 ( V_2 ) ;
F_26 ( & V_7 -> V_33 ) ;
return V_16 ;
}
void F_27 ( struct V_1 * V_2 )
{
}
int F_28 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_35 -> V_36 &= ~ V_37 ;
V_35 -> V_36 |= V_38 ;
if ( V_4 -> V_27 & V_28 ) {
V_35 -> V_39 = F_29 ( F_30 ( V_35 -> V_36 ) ) ;
} else if ( V_4 -> V_27 & V_29 ) {
V_35 -> V_39 = F_31 ( F_30 ( V_35 -> V_36 ) ) ;
} else {
F_32 ( V_35 -> V_40 ) ;
F_33 ( V_2 -> V_41 ) ;
V_35 -> V_42 = 0 ;
V_35 -> V_40 = V_2 -> V_41 ;
V_35 -> V_39 = F_30 ( V_35 -> V_36 ) ;
}
return 0 ;
}
int F_34 ( struct V_43 * V_41 , struct V_34 * V_35 )
{
int V_17 ;
V_17 = F_35 ( V_41 , V_35 ) ;
if ( V_17 ) {
F_36 ( L_3 , V_17 ) ;
return V_17 ;
}
return F_28 ( V_35 -> V_44 , V_35 ) ;
}
int F_37 ( struct V_34 * V_35 , struct V_45 * V_46 )
{
struct V_1 * V_2 = V_35 -> V_44 ;
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_14 * * V_23 ;
unsigned long V_47 ;
T_2 V_48 ;
int V_17 ;
V_17 = F_38 ( & V_7 -> V_33 ) ;
if ( V_17 )
goto V_49;
V_23 = F_10 ( V_2 ) ;
if ( F_12 ( V_23 ) ) {
V_17 = F_14 ( V_23 ) ;
goto V_50;
}
V_48 = ( ( unsigned long ) V_46 -> V_51 -
V_35 -> V_52 ) >> V_11 ;
V_47 = F_39 ( V_23 [ V_48 ] ) ;
F_40 ( L_4 , V_46 -> V_51 ,
V_47 , V_47 << V_11 ) ;
V_17 = F_41 ( V_35 , ( unsigned long ) V_46 -> V_51 ,
F_42 ( V_47 , V_53 ) ) ;
V_50:
F_26 ( & V_7 -> V_33 ) ;
V_49:
switch ( V_17 ) {
case - V_54 :
case 0 :
case - V_55 :
case - V_56 :
case - V_57 :
return V_58 ;
case - V_19 :
return V_59 ;
default:
return V_60 ;
}
}
static T_3 F_43 ( struct V_1 * V_2 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
int V_17 ;
F_44 ( ! F_45 ( & V_7 -> V_33 ) ) ;
V_17 = F_46 ( V_2 ) ;
if ( V_17 ) {
F_13 ( V_7 -> V_7 , L_5 ) ;
return 0 ;
}
return F_47 ( & V_2 -> V_61 ) ;
}
T_3 F_48 ( struct V_1 * V_2 )
{
T_3 V_62 ;
F_25 ( & V_2 -> V_7 -> V_33 ) ;
V_62 = F_43 ( V_2 ) ;
F_26 ( & V_2 -> V_7 -> V_33 ) ;
return V_62 ;
}
int F_49 ( struct V_1 * V_2 , int V_63 ,
T_4 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_17 = 0 ;
if ( ! V_4 -> V_65 [ V_63 ] . V_64 ) {
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
struct V_14 * * V_23 = F_10 ( V_2 ) ;
if ( F_12 ( V_23 ) )
return F_14 ( V_23 ) ;
if ( F_50 ( & V_66 ) ) {
struct V_67 * V_68 = V_6 -> V_69 [ V_63 ] ;
T_4 V_62 ;
if ( F_44 ( ! V_68 ) )
return - V_70 ;
V_62 = ( T_4 ) F_43 ( V_2 ) ;
V_17 = V_68 -> V_71 -> V_72 ( V_68 , V_62 , V_4 -> V_26 ,
V_2 -> V_25 , V_73 | V_74 ) ;
V_4 -> V_65 [ V_63 ] . V_64 = V_62 ;
} else {
V_4 -> V_65 [ V_63 ] . V_64 = F_1 ( V_2 ) ;
}
}
if ( ! V_17 )
* V_64 = V_4 -> V_65 [ V_63 ] . V_64 ;
return V_17 ;
}
int F_51 ( struct V_1 * V_2 , int V_63 , T_4 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_17 ;
if ( V_4 -> V_65 [ V_63 ] . V_64 ) {
* V_64 = V_4 -> V_65 [ V_63 ] . V_64 ;
return 0 ;
}
F_25 ( & V_2 -> V_7 -> V_33 ) ;
V_17 = F_49 ( V_2 , V_63 , V_64 ) ;
F_26 ( & V_2 -> V_7 -> V_33 ) ;
return V_17 ;
}
T_4 F_52 ( struct V_1 * V_2 , int V_63 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_44 ( ! V_4 -> V_65 [ V_63 ] . V_64 ) ;
return V_4 -> V_65 [ V_63 ] . V_64 ;
}
void F_53 ( struct V_1 * V_2 , int V_63 )
{
}
int F_54 ( struct V_75 * V_43 , struct V_24 * V_7 ,
struct V_76 * args )
{
args -> V_77 = F_55 ( args -> V_78 , args -> V_79 ) ;
args -> V_25 = F_56 ( args -> V_77 * args -> V_80 ) ;
return F_57 ( V_7 , V_43 , args -> V_25 ,
V_81 | V_28 , & args -> V_82 ) ;
}
int F_58 ( struct V_75 * V_43 , struct V_24 * V_7 ,
T_4 V_82 , T_3 * V_62 )
{
struct V_1 * V_2 ;
int V_17 = 0 ;
V_2 = F_59 ( V_43 , V_82 ) ;
if ( V_2 == NULL ) {
V_17 = - V_83 ;
goto V_84;
}
* V_62 = F_48 ( V_2 ) ;
F_60 ( V_2 ) ;
V_84:
return V_17 ;
}
void * F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_44 ( ! F_45 ( & V_2 -> V_7 -> V_33 ) ) ;
if ( ! V_4 -> V_85 ) {
struct V_14 * * V_23 = F_10 ( V_2 ) ;
if ( F_12 ( V_23 ) )
return F_16 ( V_23 ) ;
V_4 -> V_85 = F_62 ( V_23 , V_2 -> V_25 >> V_11 ,
V_86 , F_29 ( V_87 ) ) ;
if ( V_4 -> V_85 == NULL )
return F_6 ( - V_19 ) ;
}
return V_4 -> V_85 ;
}
void * F_63 ( struct V_1 * V_2 )
{
void * V_17 ;
F_25 ( & V_2 -> V_7 -> V_33 ) ;
V_17 = F_61 ( V_2 ) ;
F_26 ( & V_2 -> V_7 -> V_33 ) ;
return V_17 ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_88 * V_89 , bool V_90 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_91 * V_92 ;
struct V_93 * V_93 ;
int V_18 , V_17 ;
if ( ! V_90 ) {
V_17 = F_65 ( V_4 -> V_94 ) ;
if ( V_17 )
return V_17 ;
}
V_92 = F_66 ( V_4 -> V_94 ) ;
if ( ! V_92 || ( V_92 -> V_95 == 0 ) ) {
V_93 = F_67 ( V_4 -> V_94 ) ;
if ( V_93 && ( V_93 -> V_96 != V_89 -> V_96 ) ) {
V_17 = F_68 ( V_93 , true ) ;
if ( V_17 )
return V_17 ;
}
}
if ( ! V_90 || ! V_92 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_92 -> V_95 ; V_18 ++ ) {
V_93 = F_69 ( V_92 -> V_97 [ V_18 ] ,
F_70 ( V_4 -> V_94 ) ) ;
if ( V_93 -> V_96 != V_89 -> V_96 ) {
V_17 = F_68 ( V_93 , true ) ;
if ( V_17 )
return V_17 ;
}
}
return 0 ;
}
void F_71 ( struct V_1 * V_2 ,
struct V_98 * V_99 , bool V_90 , struct V_93 * V_93 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_99 = V_99 ;
if ( V_90 )
F_72 ( V_4 -> V_94 , V_93 ) ;
else
F_73 ( V_4 -> V_94 , V_93 ) ;
F_74 ( & V_4 -> V_100 ) ;
F_75 ( & V_4 -> V_100 , & V_99 -> V_101 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_44 ( ! F_45 ( & V_7 -> V_33 ) ) ;
V_4 -> V_99 = NULL ;
F_74 ( & V_4 -> V_100 ) ;
F_75 ( & V_4 -> V_100 , & V_6 -> V_102 ) ;
}
int F_77 ( struct V_1 * V_2 , T_4 V_103 , T_5 * V_104 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_105 = ! ! ( V_103 & V_106 ) ;
if ( V_103 & V_107 ) {
if ( ! F_78 ( V_4 -> V_94 , V_105 ) )
return - V_57 ;
} else {
int V_17 ;
V_17 = F_79 ( V_4 -> V_94 , V_105 ,
true , F_80 ( V_104 ) ) ;
if ( V_17 <= 0 )
return V_17 == 0 ? - V_108 : V_17 ;
}
return 0 ;
}
int F_81 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_82 ( struct V_93 * V_93 , const char * type ,
struct V_109 * V_110 )
{
if ( ! F_83 ( V_93 ) )
F_84 ( V_110 , L_6 , type ,
V_93 -> V_111 -> V_112 ( V_93 ) ,
V_93 -> V_111 -> V_113 ( V_93 ) ,
V_93 -> V_114 ) ;
}
void F_85 ( struct V_1 * V_2 , struct V_109 * V_110 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_115 * V_116 = V_4 -> V_94 ;
struct V_91 * V_92 ;
struct V_93 * V_93 ;
T_3 V_117 = F_86 ( & V_2 -> V_61 ) ;
F_44 ( ! F_45 ( & V_2 -> V_7 -> V_33 ) ) ;
F_84 ( V_110 , L_7 ,
V_4 -> V_27 , F_87 ( V_4 ) ? 'A' : 'I' ,
V_2 -> V_118 , V_2 -> V_119 . V_119 . V_120 ,
V_117 , V_4 -> V_85 , V_2 -> V_25 ) ;
F_88 () ;
V_92 = F_89 ( V_116 -> V_93 ) ;
if ( V_92 ) {
unsigned int V_18 , V_95 = V_92 -> V_95 ;
for ( V_18 = 0 ; V_18 < V_95 ; V_18 ++ ) {
V_93 = F_89 ( V_92 -> V_97 [ V_18 ] ) ;
F_82 ( V_93 , L_8 , V_110 ) ;
}
}
V_93 = F_89 ( V_116 -> V_121 ) ;
if ( V_93 )
F_82 ( V_93 , L_9 , V_110 ) ;
F_90 () ;
}
void F_91 ( struct V_122 * V_123 , struct V_109 * V_110 )
{
struct V_3 * V_4 ;
int V_124 = 0 ;
T_6 V_25 = 0 ;
F_92 (msm_obj, list, mm_list) {
struct V_1 * V_2 = & V_4 -> V_125 ;
F_84 ( V_110 , L_10 ) ;
F_85 ( V_2 , V_110 ) ;
V_124 ++ ;
V_25 += V_2 -> V_25 ;
}
F_84 ( V_110 , L_11 , V_124 , V_25 ) ;
}
void F_93 ( struct V_1 * V_2 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_63 ;
F_44 ( ! F_45 ( & V_7 -> V_33 ) ) ;
F_44 ( F_87 ( V_4 ) ) ;
F_94 ( & V_4 -> V_100 ) ;
for ( V_63 = 0 ; V_63 < F_95 ( V_4 -> V_65 ) ; V_63 ++ ) {
struct V_67 * V_68 = V_6 -> V_69 [ V_63 ] ;
if ( V_68 && V_4 -> V_65 [ V_63 ] . V_64 ) {
T_4 V_62 = V_4 -> V_65 [ V_63 ] . V_64 ;
V_68 -> V_71 -> V_126 ( V_68 , V_62 , V_4 -> V_26 , V_2 -> V_25 ) ;
}
}
if ( V_2 -> V_127 ) {
if ( V_4 -> V_85 )
F_96 ( V_2 -> V_127 -> V_128 , V_4 -> V_85 ) ;
if ( V_4 -> V_23 )
F_8 ( V_4 -> V_23 ) ;
F_97 ( V_2 , V_4 -> V_26 ) ;
} else {
F_98 ( V_4 -> V_85 ) ;
F_18 ( V_2 ) ;
}
if ( V_4 -> V_94 == & V_4 -> V_129 )
F_99 ( V_4 -> V_94 ) ;
F_100 ( V_2 ) ;
F_21 ( V_4 ) ;
}
int F_57 ( struct V_24 * V_7 , struct V_75 * V_43 ,
T_4 V_25 , T_4 V_27 , T_4 * V_82 )
{
struct V_1 * V_2 ;
int V_17 ;
V_17 = F_38 ( & V_7 -> V_33 ) ;
if ( V_17 )
return V_17 ;
V_2 = F_101 ( V_7 , V_25 , V_27 ) ;
F_26 ( & V_7 -> V_33 ) ;
if ( F_12 ( V_2 ) )
return F_14 ( V_2 ) ;
V_17 = F_102 ( V_43 , V_2 , V_82 ) ;
F_60 ( V_2 ) ;
return V_17 ;
}
static int F_103 ( struct V_24 * V_7 ,
T_4 V_25 , T_4 V_27 ,
struct V_115 * V_94 ,
struct V_1 * * V_2 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_3 * V_4 ;
unsigned V_130 ;
bool V_131 = false ;
switch ( V_27 & V_132 ) {
case V_29 :
case V_133 :
case V_28 :
break;
default:
F_13 ( V_7 -> V_7 , L_12 ,
( V_27 & V_132 ) ) ;
return - V_70 ;
}
if ( ! F_50 ( & V_66 ) )
V_131 = true ;
else if ( ( V_27 & V_134 ) && V_6 -> V_12 . V_25 )
V_131 = true ;
if ( F_44 ( V_131 && ! V_6 -> V_12 . V_25 ) )
return - V_70 ;
V_130 = sizeof( * V_4 ) ;
if ( V_131 )
V_130 += sizeof( struct V_135 ) ;
V_4 = F_104 ( V_130 , V_136 ) ;
if ( ! V_4 )
return - V_19 ;
if ( V_131 )
V_4 -> V_9 = ( void * ) & V_4 [ 1 ] ;
V_4 -> V_27 = V_27 ;
if ( V_94 ) {
V_4 -> V_94 = V_94 ;
} else {
V_4 -> V_94 = & V_4 -> V_129 ;
F_105 ( V_4 -> V_94 ) ;
}
F_106 ( & V_4 -> V_137 ) ;
F_75 ( & V_4 -> V_100 , & V_6 -> V_102 ) ;
* V_2 = & V_4 -> V_125 ;
return 0 ;
}
struct V_1 * F_101 ( struct V_24 * V_7 ,
T_4 V_25 , T_4 V_27 )
{
struct V_1 * V_2 = NULL ;
int V_17 ;
F_44 ( ! F_45 ( & V_7 -> V_33 ) ) ;
V_25 = F_56 ( V_25 ) ;
V_17 = F_103 ( V_7 , V_25 , V_27 , NULL , & V_2 ) ;
if ( V_17 )
goto V_84;
if ( F_3 ( V_2 ) ) {
V_17 = F_107 ( V_7 , V_2 , V_25 ) ;
if ( V_17 )
goto V_84;
} else {
F_108 ( V_7 , V_2 , V_25 ) ;
}
return V_2 ;
V_84:
if ( V_2 )
F_109 ( V_2 ) ;
return F_6 ( V_17 ) ;
}
struct V_1 * F_110 ( struct V_24 * V_7 ,
struct V_138 * V_128 , struct V_139 * V_26 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_4 V_25 ;
int V_17 , V_15 ;
if ( ! F_50 ( & V_66 ) ) {
F_13 ( V_7 -> V_7 , L_13 ) ;
return F_6 ( - V_70 ) ;
}
V_25 = F_56 ( V_128 -> V_25 ) ;
V_17 = F_103 ( V_7 , V_25 , V_28 , V_128 -> V_94 , & V_2 ) ;
if ( V_17 )
goto V_84;
F_108 ( V_7 , V_2 , V_25 ) ;
V_15 = V_25 / V_22 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_26 = V_26 ;
V_4 -> V_23 = F_5 ( V_15 , sizeof( struct V_14 * ) ) ;
if ( ! V_4 -> V_23 ) {
V_17 = - V_19 ;
goto V_84;
}
V_17 = F_111 ( V_26 , V_4 -> V_23 , NULL , V_15 ) ;
if ( V_17 )
goto V_84;
return V_2 ;
V_84:
if ( V_2 )
F_60 ( V_2 ) ;
return F_6 ( V_17 ) ;
}
