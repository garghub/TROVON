static int
F_1 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
unsigned long V_9 ;
struct V_10 * V_11 = NULL ;
struct V_12 * V_13 = V_4 -> V_14 . V_12 ;
F_2 ( V_2 , L_1 , V_4 -> V_15 ) ;
if ( V_13 ) {
F_3 ( V_2 , L_2 ) ;
F_4 ( & V_7 -> V_13 . V_16 , V_9 ) ;
F_5 (sess, &vha->vp_fcports, list)
F_2 ( V_2 , L_3 ,
V_11 -> V_17 . V_18 . V_19 , V_11 -> V_17 . V_18 . V_20 ,
V_11 -> V_17 . V_18 . V_21 , V_11 -> V_22 ,
V_11 -> V_23 ) ;
F_6 ( & V_7 -> V_13 . V_16 , V_9 ) ;
}
return 0 ;
}
static int
F_7 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
T_1 * V_4 = V_24 -> V_26 ;
return F_8 ( V_25 , F_1 , V_4 ) ;
}
static int
F_9 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_27 * V_28 ;
T_2 V_29 ;
T_3 V_10 ;
char * V_30 ;
int V_31 , V_32 ;
T_4 V_33 , V_23 ;
struct V_12 * V_13 = V_4 -> V_14 . V_12 ;
F_2 ( V_2 , L_1 , V_4 -> V_15 ) ;
if ( V_13 ) {
V_28 = F_10 ( & V_7 -> V_34 -> V_35 ,
F_11 ( V_7 ) ,
& V_29 , V_36 ) ;
if ( ! V_28 ) {
F_12 ( V_37 , V_4 , 0x7018 ,
L_4 ,
F_11 ( V_7 ) ) ;
return 0 ;
}
V_31 = F_13 ( V_4 , V_28 , V_29 ,
& V_33 ) ;
if ( V_31 != V_38 )
goto V_39;
V_30 = ( char * ) V_28 ;
F_3 ( V_2 , L_5 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
struct V_27 * V_40 =
(struct V_27 * ) V_30 ;
V_23 = F_14 ( V_40 -> V_23 ) ;
memset ( & V_10 , 0 , sizeof( T_3 ) ) ;
V_10 . V_23 = V_23 ;
V_31 = F_15 ( V_4 , & V_10 , 0 ) ;
F_2 ( V_2 , L_6 ,
V_10 . V_22 , V_10 . V_17 . V_18 . V_19 ,
V_10 . V_17 . V_18 . V_20 , V_10 . V_17 . V_18 . V_21 ,
V_10 . V_23 ) ;
V_30 += V_7 -> V_41 ;
}
V_39:
F_16 ( & V_7 -> V_34 -> V_35 , F_11 ( V_7 ) ,
V_28 , V_29 ) ;
}
return 0 ;
}
static int
F_17 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
T_1 * V_4 = V_24 -> V_26 ;
return F_8 ( V_25 , F_9 , V_4 ) ;
}
static int
F_18 ( struct V_1 * V_2 , void * V_3 )
{
struct V_42 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_3 ( V_2 , L_7 ) ;
F_2 ( V_2 , L_8 ,
V_7 -> V_43 ) ;
F_2 ( V_2 , L_9 ,
V_7 -> V_44 ) ;
F_2 ( V_2 , L_10 ,
V_7 -> V_45 ) ;
F_2 ( V_2 , L_11 ,
V_7 -> V_46 ) ;
F_2 ( V_2 , L_12 , V_7 -> V_47 ) ;
F_2 ( V_2 , L_13 , V_7 -> V_48 ) ;
F_2 ( V_2 , L_14 , V_7 -> V_49 ) ;
F_2 ( V_2 , L_15 , V_7 -> V_50 ) ;
return 0 ;
}
static int
F_19 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_42 * V_4 = V_24 -> V_26 ;
return F_8 ( V_25 , F_18 , V_4 ) ;
}
static int
F_20 ( struct V_1 * V_2 , void * V_3 )
{
struct V_42 * V_4 = V_2 -> V_5 ;
struct V_51 * V_52 = V_4 -> V_8 -> V_53 ;
T_5 V_54 , V_55 , V_56 ,
V_57 , V_58 , V_59 ,
V_60 , V_61 , V_62 ;
T_6 V_32 ;
V_54 = V_52 -> V_63 . V_54 ;
V_55 = V_52 -> V_63 . V_55 ;
V_56 = V_52 -> V_63 . V_56 ;
V_57 = V_52 -> V_63 . V_57 ;
V_58 = V_52 -> V_63 . V_58 ;
V_59 = V_52 -> V_63 . V_59 ;
V_60 = V_52 -> V_63 . V_60 ;
V_61 = V_52 -> V_63 . V_61 ;
V_62 = V_52 -> V_63 . V_62 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_8 -> V_64 ; V_32 ++ ) {
V_52 = V_4 -> V_8 -> V_65 [ V_32 ] ;
V_54 += V_52 -> V_63 . V_54 ;
V_55 += V_52 -> V_63 . V_55 ;
V_56 += V_52 -> V_63 . V_56 ;
V_57 += V_52 -> V_63 . V_57 ;
V_58 +=
V_52 -> V_63 . V_58 ;
V_59 += V_52 -> V_63 . V_59 ;
V_60 += V_52 -> V_63 . V_60 ;
V_61 +=
V_52 -> V_63 . V_61 ;
V_62 += V_52 -> V_63 . V_62 ;
}
F_3 ( V_2 , L_16 ) ;
F_2 ( V_2 , L_17 ,
V_54 ) ;
F_2 ( V_2 , L_18 ,
V_58 ) ;
F_2 ( V_2 , L_19 ,
V_56 ) ;
F_2 ( V_2 , L_20 ,
V_55 ) ;
F_2 ( V_2 , L_21 ,
V_57 ) ;
F_2 ( V_2 , L_22 ,
V_59 ) ;
F_2 ( V_2 , L_23 ,
V_61 ) ;
F_2 ( V_2 , L_24 ,
V_62 ) ;
F_2 ( V_2 , L_25 ,
V_60 ) ;
F_2 ( V_2 , L_26 ,
V_4 -> V_66 . V_67 . V_68 ) ;
F_2 ( V_2 , L_27 ,
V_4 -> V_66 . V_67 . V_69 ) ;
F_2 ( V_2 , L_28 ,
V_4 -> V_66 . V_67 . V_70 ) ;
F_2 ( V_2 , L_29 ,
V_4 -> V_66 . V_67 . V_71 ) ;
F_2 ( V_2 , L_30 ,
V_4 -> V_66 . V_67 . V_72 ) ;
F_2 ( V_2 , L_31 ,
V_4 -> V_66 . V_67 . V_73 ) ;
F_2 ( V_2 , L_32 ,
V_4 -> V_66 . V_67 . V_74 ) ;
return 0 ;
}
static int
F_21 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_42 * V_4 = V_24 -> V_26 ;
return F_8 ( V_25 , F_20 , V_4 ) ;
}
static int
F_22 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
T_7 V_75 ;
T_7 * V_76 ;
T_5 V_77 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_23 ( & V_7 -> V_78 ) ;
F_3 ( V_2 , L_33 ) ;
F_2 ( V_2 , L_34 , ( unsigned long long ) V_7 -> V_79 ) ;
F_2 ( V_2 , L_35 , ( unsigned long long ) V_7 -> V_80 ) ;
F_3 ( V_2 , L_36 ) ;
F_2 ( V_2 , L_37 ,
V_7 -> V_81 [ 0 ] , V_7 -> V_81 [ 2 ] , V_7 -> V_81 [ 3 ] , V_7 -> V_81 [ 4 ] ,
V_7 -> V_81 [ 5 ] , V_7 -> V_81 [ 6 ] ) ;
V_76 = ( T_7 * ) V_7 -> V_76 ;
V_77 = ( unsigned long long ) V_7 -> V_80 ;
for ( V_75 = 0 ; V_75 < F_24 ( V_7 -> V_82 ) / 4 ; V_75 ++ ) {
if ( V_75 % 8 == 0 )
F_2 ( V_2 , L_38 ,
( unsigned long long ) ( ( V_75 * 4 ) + V_77 ) ) ;
else
F_25 ( V_2 , ' ' ) ;
F_2 ( V_2 , L_39 , * V_76 ++ ) ;
}
F_3 ( V_2 , L_40 ) ;
F_26 ( & V_7 -> V_78 ) ;
return 0 ;
}
static int
F_27 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
T_1 * V_4 = V_24 -> V_26 ;
struct V_6 * V_7 = V_4 -> V_8 ;
int V_83 ;
if ( ! V_7 -> V_9 . V_84 )
goto V_85;
F_23 ( & V_7 -> V_78 ) ;
V_83 = F_28 ( V_4 , & V_7 -> V_79 , & V_7 -> V_86 ) ;
if ( V_83 )
F_12 ( V_37 , V_4 , 0x705c ,
L_41 , V_83 ) ;
V_7 -> V_9 . V_84 = 0 ;
F_26 ( & V_7 -> V_78 ) ;
V_85:
return F_8 ( V_25 , F_22 , V_4 ) ;
}
static int
F_29 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
T_1 * V_4 = V_24 -> V_26 ;
struct V_6 * V_7 = V_4 -> V_8 ;
int V_83 ;
if ( V_7 -> V_9 . V_84 )
goto V_85;
F_23 ( & V_7 -> V_78 ) ;
V_7 -> V_9 . V_84 = 1 ;
memset ( V_7 -> V_76 , 0 , F_24 ( V_7 -> V_82 ) ) ;
V_83 = F_30 ( V_4 , V_7 -> V_80 , V_7 -> V_82 ,
V_7 -> V_81 , & V_7 -> V_82 ) ;
if ( V_83 ) {
F_12 ( V_37 , V_4 , 0x700d ,
L_42 , V_83 ) ;
V_7 -> V_9 . V_84 = 0 ;
}
F_26 ( & V_7 -> V_78 ) ;
V_85:
return F_31 ( V_24 , V_25 ) ;
}
static int
F_32 ( struct V_1 * V_2 , void * V_3 )
{
struct V_42 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_2 ( V_2 , L_43 , V_7 -> V_13 . V_87 ) ;
return 0 ;
}
static int
F_33 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_42 * V_4 = V_24 -> V_26 ;
return F_8 ( V_25 , F_32 , V_4 ) ;
}
static T_8
F_34 ( struct V_25 * V_25 , const char T_9 * V_88 ,
T_10 V_89 , T_11 * V_90 )
{
struct V_1 * V_2 = V_25 -> V_91 ;
struct V_42 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
char * V_92 ;
int V_31 = 0 ;
unsigned long V_93 ;
if ( ! ( F_35 ( V_7 ) || F_36 ( V_7 ) ) ) {
F_37 ( L_44 ,
V_4 -> V_94 ) ;
return - V_95 ;
}
if ( ! V_4 -> V_9 . V_96 ) {
F_37 ( L_45 ,
V_4 -> V_94 ) ;
return - V_95 ;
}
V_92 = F_38 ( V_88 , V_89 ) ;
if ( F_39 ( V_92 ) ) {
F_37 ( L_46 ,
V_4 -> V_94 ) ;
return F_40 ( V_92 ) ;
}
V_93 = F_41 ( V_92 , NULL , 0 ) ;
if ( V_93 >= V_4 -> V_8 -> V_64 ) {
F_37 ( L_47 ,
V_93 , V_4 -> V_8 -> V_64 ) ;
V_31 = - V_95 ;
goto V_97;
}
if ( V_93 != V_7 -> V_13 . V_87 ) {
V_7 -> V_13 . V_87 = V_93 ;
F_42 ( V_4 ) ;
}
V_31 = V_89 ;
V_97:
F_43 ( V_92 ) ;
return V_31 ;
}
int
F_44 ( T_1 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
if ( ! F_45 ( V_7 ) && ! F_46 ( V_7 ) && ! F_36 ( V_7 ) &&
! F_35 ( V_7 ) )
goto V_85;
if ( ! V_7 -> V_76 )
goto V_85;
if ( V_98 )
goto V_99;
F_47 ( & V_100 , 0 ) ;
V_98 = F_48 ( V_101 , NULL ) ;
if ( ! V_98 ) {
F_49 ( V_102 , V_4 , 0x00f7 ,
L_48 ) ;
goto V_85;
}
V_99:
if ( V_7 -> V_103 )
goto V_104;
F_50 ( & V_7 -> V_78 ) ;
V_7 -> V_103 = F_48 ( V_4 -> V_15 , V_98 ) ;
if ( ! V_7 -> V_103 ) {
F_49 ( V_102 , V_4 , 0x00f8 ,
L_49 ) ;
goto V_85;
}
F_51 ( & V_100 ) ;
V_104:
V_7 -> V_105 = F_52 ( L_50 ,
V_106 , V_7 -> V_103 , V_4 , & V_107 ) ;
if ( ! V_7 -> V_105 ) {
F_49 ( V_102 , V_4 , 0x00fd ,
L_51 ) ;
goto V_85;
}
V_7 -> V_108 = F_52 ( L_52 , V_106 ,
V_7 -> V_103 , V_4 , & V_109 ) ;
if ( ! V_7 -> V_108 ) {
F_49 ( V_102 , V_4 , 0xd301 ,
L_53 ) ;
goto V_85;
}
V_7 -> V_13 . V_110 = F_52 ( L_54 ,
V_106 , V_7 -> V_103 , V_4 , & V_111 ) ;
if ( ! V_7 -> V_13 . V_110 ) {
F_49 ( V_102 , V_4 , 0xd03f ,
L_55 ) ;
goto V_85;
}
V_7 -> V_112 = F_52 ( L_56 , V_106 , V_7 -> V_103 , V_4 ,
& V_113 ) ;
if ( ! V_7 -> V_112 ) {
F_49 ( V_102 , V_4 , 0x00f9 ,
L_57 ) ;
goto V_85;
}
V_7 -> V_13 . V_114 = F_52 ( L_58 ,
V_106 , V_7 -> V_103 , V_4 , & V_115 ) ;
if ( ! V_7 -> V_13 . V_114 ) {
F_49 ( V_102 , V_4 , 0xd040 ,
L_59 ) ;
goto V_85;
}
if ( F_35 ( V_7 ) || F_36 ( V_7 ) ) {
V_7 -> V_13 . V_116 = F_52 ( L_60 ,
0400 , V_7 -> V_103 , V_4 , & V_117 ) ;
if ( ! V_7 -> V_13 . V_116 ) {
F_49 ( V_102 , V_4 , 0xd011 ,
L_61 ) ;
goto V_85;
}
}
V_85:
return 0 ;
}
int
F_53 ( T_1 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
if ( V_7 -> V_13 . V_116 ) {
F_54 ( V_7 -> V_13 . V_116 ) ;
V_7 -> V_13 . V_116 = NULL ;
}
if ( V_7 -> V_13 . V_114 ) {
F_54 ( V_7 -> V_13 . V_114 ) ;
V_7 -> V_13 . V_114 = NULL ;
}
if ( V_7 -> V_13 . V_110 ) {
F_54 ( V_7 -> V_13 . V_110 ) ;
V_7 -> V_13 . V_110 = NULL ;
}
if ( V_7 -> V_105 ) {
F_54 ( V_7 -> V_105 ) ;
V_7 -> V_105 = NULL ;
}
if ( V_7 -> V_108 ) {
F_54 ( V_7 -> V_108 ) ;
V_7 -> V_108 = NULL ;
}
if ( V_7 -> V_112 ) {
F_54 ( V_7 -> V_112 ) ;
V_7 -> V_112 = NULL ;
}
if ( V_7 -> V_103 ) {
F_54 ( V_7 -> V_103 ) ;
V_7 -> V_103 = NULL ;
F_55 ( & V_100 ) ;
}
if ( F_56 ( & V_100 ) == 0 &&
V_98 ) {
F_54 ( V_98 ) ;
V_98 = NULL ;
}
return 0 ;
}
