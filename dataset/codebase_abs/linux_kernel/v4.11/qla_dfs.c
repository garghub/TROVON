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
F_12 ( V_37 , V_4 , 0x705c ,
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
F_3 ( V_2 , L_16 ) ;
F_2 ( V_2 , L_17 ,
V_4 -> V_51 . V_52 ) ;
F_2 ( V_2 , L_18 ,
V_4 -> V_51 . V_53 ) ;
F_2 ( V_2 , L_19 ,
V_4 -> V_51 . V_54 ) ;
F_2 ( V_2 , L_20 ,
V_4 -> V_51 . V_55 ) ;
F_2 ( V_2 , L_21 ,
V_4 -> V_51 . V_56 ) ;
F_2 ( V_2 , L_22 ,
V_4 -> V_51 . V_57 ) ;
F_2 ( V_2 , L_23 ,
V_4 -> V_51 . V_58 ) ;
F_2 ( V_2 , L_24 ,
V_4 -> V_51 . V_59 ) ;
F_2 ( V_2 , L_25 ,
V_4 -> V_51 . V_60 ) ;
F_2 ( V_2 , L_26 ,
V_4 -> V_61 . V_62 . V_63 ) ;
F_2 ( V_2 , L_27 ,
V_4 -> V_61 . V_62 . V_64 ) ;
F_2 ( V_2 , L_28 ,
V_4 -> V_61 . V_62 . V_65 ) ;
F_2 ( V_2 , L_29 ,
V_4 -> V_61 . V_62 . V_66 ) ;
F_2 ( V_2 , L_30 ,
V_4 -> V_61 . V_62 . V_67 ) ;
F_2 ( V_2 , L_31 ,
V_4 -> V_61 . V_62 . V_68 ) ;
F_2 ( V_2 , L_32 ,
V_4 -> V_61 . V_62 . V_69 ) ;
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
T_5 V_70 ;
T_5 * V_71 ;
T_6 V_72 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_23 ( & V_7 -> V_73 ) ;
F_3 ( V_2 , L_33 ) ;
F_2 ( V_2 , L_34 , ( unsigned long long ) V_7 -> V_74 ) ;
F_2 ( V_2 , L_35 , ( unsigned long long ) V_7 -> V_75 ) ;
F_3 ( V_2 , L_36 ) ;
F_2 ( V_2 , L_37 ,
V_7 -> V_76 [ 0 ] , V_7 -> V_76 [ 2 ] , V_7 -> V_76 [ 3 ] , V_7 -> V_76 [ 4 ] ,
V_7 -> V_76 [ 5 ] , V_7 -> V_76 [ 6 ] ) ;
V_71 = ( T_5 * ) V_7 -> V_71 ;
V_72 = ( unsigned long long ) V_7 -> V_75 ;
for ( V_70 = 0 ; V_70 < F_24 ( V_7 -> V_77 ) / 4 ; V_70 ++ ) {
if ( V_70 % 8 == 0 )
F_2 ( V_2 , L_38 ,
( unsigned long long ) ( ( V_70 * 4 ) + V_72 ) ) ;
else
F_25 ( V_2 , ' ' ) ;
F_2 ( V_2 , L_39 , * V_71 ++ ) ;
}
F_3 ( V_2 , L_40 ) ;
F_26 ( & V_7 -> V_73 ) ;
return 0 ;
}
static int
F_27 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
T_1 * V_4 = V_24 -> V_26 ;
struct V_6 * V_7 = V_4 -> V_8 ;
int V_78 ;
if ( ! V_7 -> V_9 . V_79 )
goto V_80;
F_23 ( & V_7 -> V_73 ) ;
V_78 = F_28 ( V_4 , & V_7 -> V_74 , & V_7 -> V_81 ) ;
if ( V_78 )
F_12 ( V_37 , V_4 , 0x705c ,
L_41 , V_78 ) ;
V_7 -> V_9 . V_79 = 0 ;
F_26 ( & V_7 -> V_73 ) ;
V_80:
return F_8 ( V_25 , F_22 , V_4 ) ;
}
static int
F_29 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
T_1 * V_4 = V_24 -> V_26 ;
struct V_6 * V_7 = V_4 -> V_8 ;
int V_78 ;
if ( V_7 -> V_9 . V_79 )
goto V_80;
F_23 ( & V_7 -> V_73 ) ;
V_7 -> V_9 . V_79 = 1 ;
memset ( V_7 -> V_71 , 0 , F_24 ( V_7 -> V_77 ) ) ;
V_78 = F_30 ( V_4 , V_7 -> V_75 , V_7 -> V_77 ,
V_7 -> V_76 , & V_7 -> V_77 ) ;
if ( V_78 ) {
F_12 ( V_37 , V_4 , 0x700d ,
L_42 , V_78 ) ;
V_7 -> V_9 . V_79 = 0 ;
}
F_26 ( & V_7 -> V_73 ) ;
V_80:
return F_31 ( V_24 , V_25 ) ;
}
int
F_32 ( T_1 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
if ( ! F_33 ( V_7 ) && ! F_34 ( V_7 ) && ! F_35 ( V_7 ) &&
! F_36 ( V_7 ) )
goto V_80;
if ( ! V_7 -> V_71 )
goto V_80;
if ( V_82 )
goto V_83;
F_37 ( & V_84 , 0 ) ;
V_82 = F_38 ( V_85 , NULL ) ;
if ( ! V_82 ) {
F_39 ( V_86 , V_4 , 0x00f7 ,
L_43 ) ;
goto V_80;
}
V_83:
if ( V_7 -> V_87 )
goto V_88;
F_40 ( & V_7 -> V_73 ) ;
V_7 -> V_87 = F_38 ( V_4 -> V_15 , V_82 ) ;
if ( ! V_7 -> V_87 ) {
F_39 ( V_86 , V_4 , 0x00f8 ,
L_44 ) ;
goto V_80;
}
F_41 ( & V_84 ) ;
V_88:
V_7 -> V_89 = F_42 ( L_45 ,
V_90 , V_7 -> V_87 , V_4 , & V_91 ) ;
if ( ! V_7 -> V_89 ) {
F_39 ( V_86 , V_4 , 0x00fd ,
L_46 ) ;
goto V_80;
}
V_7 -> V_92 = F_42 ( L_47 , V_90 ,
V_7 -> V_87 , V_4 , & V_93 ) ;
if ( ! V_7 -> V_92 ) {
F_39 ( V_86 , V_4 , 0xd301 ,
L_48 ) ;
goto V_80;
}
V_7 -> V_13 . V_94 = F_42 ( L_49 ,
V_90 , V_7 -> V_87 , V_4 , & V_95 ) ;
if ( ! V_7 -> V_13 . V_94 ) {
F_39 ( V_86 , V_4 , 0xffff ,
L_50 ) ;
goto V_80;
}
V_7 -> V_96 = F_42 ( L_51 , V_90 , V_7 -> V_87 , V_4 ,
& V_97 ) ;
if ( ! V_7 -> V_96 ) {
F_39 ( V_86 , V_4 , 0x00f9 ,
L_52 ) ;
goto V_80;
}
V_7 -> V_13 . V_98 = F_42 ( L_53 ,
V_90 , V_7 -> V_87 , V_4 , & V_99 ) ;
if ( ! V_7 -> V_13 . V_98 ) {
F_39 ( V_86 , V_4 , 0xffff ,
L_54 ) ;
goto V_80;
}
V_80:
return 0 ;
}
int
F_43 ( T_1 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
if ( V_7 -> V_13 . V_98 ) {
F_44 ( V_7 -> V_13 . V_98 ) ;
V_7 -> V_13 . V_98 = NULL ;
}
if ( V_7 -> V_13 . V_94 ) {
F_44 ( V_7 -> V_13 . V_94 ) ;
V_7 -> V_13 . V_94 = NULL ;
}
if ( V_7 -> V_89 ) {
F_44 ( V_7 -> V_89 ) ;
V_7 -> V_89 = NULL ;
}
if ( V_7 -> V_92 ) {
F_44 ( V_7 -> V_92 ) ;
V_7 -> V_92 = NULL ;
}
if ( V_7 -> V_96 ) {
F_44 ( V_7 -> V_96 ) ;
V_7 -> V_96 = NULL ;
}
if ( V_7 -> V_87 ) {
F_44 ( V_7 -> V_87 ) ;
V_7 -> V_87 = NULL ;
F_45 ( & V_84 ) ;
}
if ( F_46 ( & V_84 ) == 0 &&
V_82 ) {
F_44 ( V_82 ) ;
V_82 = NULL ;
}
return 0 ;
}
