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
V_17 = F_41 ( V_35 , ( unsigned long ) V_46 -> V_51 , V_47 ) ;
V_50:
F_26 ( & V_7 -> V_33 ) ;
V_49:
switch ( V_17 ) {
case - V_53 :
case 0 :
case - V_54 :
case - V_55 :
case - V_56 :
return V_57 ;
case - V_19 :
return V_58 ;
default:
return V_59 ;
}
}
static T_3 F_42 ( struct V_1 * V_2 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
int V_17 ;
F_43 ( ! F_44 ( & V_7 -> V_33 ) ) ;
V_17 = F_45 ( V_2 ) ;
if ( V_17 ) {
F_13 ( V_7 -> V_7 , L_5 ) ;
return 0 ;
}
return F_46 ( & V_2 -> V_60 ) ;
}
T_3 F_47 ( struct V_1 * V_2 )
{
T_3 V_61 ;
F_25 ( & V_2 -> V_7 -> V_33 ) ;
V_61 = F_42 ( V_2 ) ;
F_26 ( & V_2 -> V_7 -> V_33 ) ;
return V_61 ;
}
int F_48 ( struct V_1 * V_2 , int V_62 ,
T_4 * V_63 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_17 = 0 ;
if ( ! V_4 -> V_64 [ V_62 ] . V_63 ) {
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
struct V_14 * * V_23 = F_10 ( V_2 ) ;
if ( F_12 ( V_23 ) )
return F_14 ( V_23 ) ;
if ( F_49 ( & V_65 ) ) {
struct V_66 * V_67 = V_6 -> V_68 [ V_62 ] ;
T_4 V_61 ;
if ( F_43 ( ! V_67 ) )
return - V_69 ;
V_61 = ( T_4 ) F_42 ( V_2 ) ;
V_17 = V_67 -> V_70 -> V_71 ( V_67 , V_61 , V_4 -> V_26 ,
V_2 -> V_25 , V_72 | V_73 ) ;
V_4 -> V_64 [ V_62 ] . V_63 = V_61 ;
} else {
V_4 -> V_64 [ V_62 ] . V_63 = F_1 ( V_2 ) ;
}
}
if ( ! V_17 )
* V_63 = V_4 -> V_64 [ V_62 ] . V_63 ;
return V_17 ;
}
int F_50 ( struct V_1 * V_2 , int V_62 , T_4 * V_63 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_17 ;
if ( V_4 -> V_64 [ V_62 ] . V_63 ) {
* V_63 = V_4 -> V_64 [ V_62 ] . V_63 ;
return 0 ;
}
F_25 ( & V_2 -> V_7 -> V_33 ) ;
V_17 = F_48 ( V_2 , V_62 , V_63 ) ;
F_26 ( & V_2 -> V_7 -> V_33 ) ;
return V_17 ;
}
T_4 F_51 ( struct V_1 * V_2 , int V_62 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_43 ( ! V_4 -> V_64 [ V_62 ] . V_63 ) ;
return V_4 -> V_64 [ V_62 ] . V_63 ;
}
void F_52 ( struct V_1 * V_2 , int V_62 )
{
}
int F_53 ( struct V_74 * V_43 , struct V_24 * V_7 ,
struct V_75 * args )
{
args -> V_76 = F_54 ( args -> V_77 , args -> V_78 ) ;
args -> V_25 = F_55 ( args -> V_76 * args -> V_79 ) ;
return F_56 ( V_7 , V_43 , args -> V_25 ,
V_80 | V_28 , & args -> V_81 ) ;
}
int F_57 ( struct V_74 * V_43 , struct V_24 * V_7 ,
T_4 V_81 , T_3 * V_61 )
{
struct V_1 * V_2 ;
int V_17 = 0 ;
V_2 = F_58 ( V_7 , V_43 , V_81 ) ;
if ( V_2 == NULL ) {
V_17 = - V_82 ;
goto V_83;
}
* V_61 = F_47 ( V_2 ) ;
F_59 ( V_2 ) ;
V_83:
return V_17 ;
}
void * F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_43 ( ! F_44 ( & V_2 -> V_7 -> V_33 ) ) ;
if ( ! V_4 -> V_84 ) {
struct V_14 * * V_23 = F_10 ( V_2 ) ;
if ( F_12 ( V_23 ) )
return F_16 ( V_23 ) ;
V_4 -> V_84 = F_61 ( V_23 , V_2 -> V_25 >> V_11 ,
V_85 , F_29 ( V_86 ) ) ;
}
return V_4 -> V_84 ;
}
void * F_62 ( struct V_1 * V_2 )
{
void * V_17 ;
F_25 ( & V_2 -> V_7 -> V_33 ) ;
V_17 = F_60 ( V_2 ) ;
F_26 ( & V_2 -> V_7 -> V_33 ) ;
return V_17 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 V_89 = F_64 ( V_4 ,
V_90 | V_91 ) ;
return F_65 ( V_2 -> V_7 , V_88 , V_89 ) ;
}
void F_66 ( struct V_1 * V_2 ,
struct V_92 * V_93 , bool V_94 , T_4 V_89 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_93 = V_93 ;
if ( V_94 )
V_4 -> V_95 = V_89 ;
else
V_4 -> V_96 = V_89 ;
F_67 ( & V_4 -> V_97 ) ;
F_68 ( & V_4 -> V_97 , & V_93 -> V_98 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_43 ( ! F_44 ( & V_7 -> V_33 ) ) ;
V_4 -> V_93 = NULL ;
V_4 -> V_96 = 0 ;
V_4 -> V_95 = 0 ;
F_67 ( & V_4 -> V_97 ) ;
F_68 ( & V_4 -> V_97 , & V_6 -> V_99 ) ;
}
int F_70 ( struct V_1 * V_2 , T_4 V_100 ,
struct V_101 * V_102 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_17 = 0 ;
if ( F_71 ( V_4 ) ) {
T_4 V_89 = F_64 ( V_4 , V_100 ) ;
if ( V_100 & V_103 )
V_102 = NULL ;
V_17 = F_72 ( V_7 , V_89 , V_102 ) ;
}
return V_17 ;
}
int F_73 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_74 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_106 = F_75 ( & V_2 -> V_60 ) ;
F_43 ( ! F_44 ( & V_7 -> V_33 ) ) ;
F_76 ( V_105 , L_6 ,
V_4 -> V_27 , F_71 ( V_4 ) ? 'A' : 'I' ,
V_4 -> V_96 , V_4 -> V_95 ,
V_2 -> V_107 , V_2 -> V_108 . V_108 . V_109 ,
V_106 , V_4 -> V_84 , V_2 -> V_25 ) ;
}
void F_77 ( struct V_110 * V_111 , struct V_104 * V_105 )
{
struct V_3 * V_4 ;
int V_112 = 0 ;
T_5 V_25 = 0 ;
F_78 (msm_obj, list, mm_list) {
struct V_1 * V_2 = & V_4 -> V_113 ;
F_76 ( V_105 , L_7 ) ;
F_74 ( V_2 , V_105 ) ;
V_112 ++ ;
V_25 += V_2 -> V_25 ;
}
F_76 ( V_105 , L_8 , V_112 , V_25 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_62 ;
F_43 ( ! F_44 ( & V_7 -> V_33 ) ) ;
F_43 ( F_71 ( V_4 ) ) ;
F_80 ( & V_4 -> V_97 ) ;
for ( V_62 = 0 ; V_62 < F_81 ( V_4 -> V_64 ) ; V_62 ++ ) {
struct V_66 * V_67 = V_6 -> V_68 [ V_62 ] ;
if ( V_67 && V_4 -> V_64 [ V_62 ] . V_63 ) {
T_4 V_61 = V_4 -> V_64 [ V_62 ] . V_63 ;
V_67 -> V_70 -> V_114 ( V_67 , V_61 , V_4 -> V_26 , V_2 -> V_25 ) ;
}
}
if ( V_2 -> V_115 ) {
if ( V_4 -> V_84 )
F_82 ( V_2 -> V_115 -> V_116 , V_4 -> V_84 ) ;
if ( V_4 -> V_23 )
F_8 ( V_4 -> V_23 ) ;
} else {
F_83 ( V_4 -> V_84 ) ;
F_18 ( V_2 ) ;
}
if ( V_4 -> V_117 == & V_4 -> V_118 )
F_84 ( V_4 -> V_117 ) ;
F_85 ( V_2 ) ;
F_21 ( V_4 ) ;
}
int F_56 ( struct V_24 * V_7 , struct V_74 * V_43 ,
T_4 V_25 , T_4 V_27 , T_4 * V_81 )
{
struct V_1 * V_2 ;
int V_17 ;
V_17 = F_38 ( & V_7 -> V_33 ) ;
if ( V_17 )
return V_17 ;
V_2 = F_86 ( V_7 , V_25 , V_27 ) ;
F_26 ( & V_7 -> V_33 ) ;
if ( F_12 ( V_2 ) )
return F_14 ( V_2 ) ;
V_17 = F_87 ( V_43 , V_2 , V_81 ) ;
F_59 ( V_2 ) ;
return V_17 ;
}
static int F_88 ( struct V_24 * V_7 ,
T_4 V_25 , T_4 V_27 ,
struct V_1 * * V_2 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_3 * V_4 ;
unsigned V_119 ;
bool V_120 = false ;
switch ( V_27 & V_121 ) {
case V_29 :
case V_122 :
case V_28 :
break;
default:
F_13 ( V_7 -> V_7 , L_9 ,
( V_27 & V_121 ) ) ;
return - V_69 ;
}
if ( ! F_49 ( & V_65 ) )
V_120 = true ;
else if ( ( V_27 & V_123 ) && V_6 -> V_12 . V_25 )
V_120 = true ;
if ( F_43 ( V_120 && ! V_6 -> V_12 . V_25 ) )
return - V_69 ;
V_119 = sizeof( * V_4 ) ;
if ( V_120 )
V_119 += sizeof( struct V_124 ) ;
V_4 = F_89 ( V_119 , V_125 ) ;
if ( ! V_4 )
return - V_19 ;
if ( V_120 )
V_4 -> V_9 = ( void * ) & V_4 [ 1 ] ;
V_4 -> V_27 = V_27 ;
V_4 -> V_117 = & V_4 -> V_118 ;
F_90 ( V_4 -> V_117 ) ;
F_91 ( & V_4 -> V_126 ) ;
F_68 ( & V_4 -> V_97 , & V_6 -> V_99 ) ;
* V_2 = & V_4 -> V_113 ;
return 0 ;
}
struct V_1 * F_86 ( struct V_24 * V_7 ,
T_4 V_25 , T_4 V_27 )
{
struct V_1 * V_2 = NULL ;
int V_17 ;
F_43 ( ! F_44 ( & V_7 -> V_33 ) ) ;
V_25 = F_55 ( V_25 ) ;
V_17 = F_88 ( V_7 , V_25 , V_27 , & V_2 ) ;
if ( V_17 )
goto V_83;
if ( F_3 ( V_2 ) ) {
V_17 = F_92 ( V_7 , V_2 , V_25 ) ;
if ( V_17 )
goto V_83;
} else {
F_93 ( V_7 , V_2 , V_25 ) ;
}
return V_2 ;
V_83:
if ( V_2 )
F_94 ( V_2 ) ;
return F_6 ( V_17 ) ;
}
struct V_1 * F_95 ( struct V_24 * V_7 ,
T_4 V_25 , struct V_127 * V_26 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_17 , V_15 ;
if ( ! F_49 ( & V_65 ) ) {
F_13 ( V_7 -> V_7 , L_10 ) ;
return F_6 ( - V_69 ) ;
}
V_25 = F_55 ( V_25 ) ;
V_17 = F_88 ( V_7 , V_25 , V_28 , & V_2 ) ;
if ( V_17 )
goto V_83;
F_93 ( V_7 , V_2 , V_25 ) ;
V_15 = V_25 / V_22 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_26 = V_26 ;
V_4 -> V_23 = F_5 ( V_15 , sizeof( struct V_14 * ) ) ;
if ( ! V_4 -> V_23 ) {
V_17 = - V_19 ;
goto V_83;
}
V_17 = F_96 ( V_26 , V_4 -> V_23 , NULL , V_15 ) ;
if ( V_17 )
goto V_83;
return V_2 ;
V_83:
if ( V_2 )
F_59 ( V_2 ) ;
return F_6 ( V_17 ) ;
}
