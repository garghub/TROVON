void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 ) {
if ( V_4 -> V_5 . V_6 )
F_3 ( & V_4 -> V_5 , V_4 -> V_7 . V_8 ) ;
F_4 ( & V_4 ) ;
}
}
int F_5 ( struct V_9 * V_10 , int V_11 ,
int V_12 , int V_13 ,
bool V_14 , bool V_15 ,
struct V_1 * * V_16 )
{
struct V_3 * V_4 ;
unsigned long V_17 ;
int V_18 ;
* V_16 = NULL ;
if ( V_12 < V_19 ) {
V_12 = V_19 ;
}
V_17 = F_6 ( V_10 -> V_20 . V_21 , V_10 -> V_20 . V_22 ) ;
if ( V_11 > V_17 ) {
F_7 ( V_23 L_1 ,
V_24 , __LINE__ , V_11 >> 20 , V_17 >> 20 ) ;
return - V_25 ;
}
V_26:
V_18 = F_8 ( V_10 , V_11 , V_12 , V_15 , V_13 , NULL , & V_4 ) ;
if ( V_18 ) {
if ( V_18 != - V_27 ) {
if ( V_13 == V_28 ) {
V_13 |= V_29 ;
goto V_26;
}
F_9 ( L_2 ,
V_11 , V_13 , V_12 , V_18 ) ;
}
return V_18 ;
}
* V_16 = & V_4 -> V_5 ;
V_4 -> V_30 = F_10 ( V_31 ) ;
F_11 ( & V_10 -> V_32 . V_33 ) ;
F_12 ( & V_4 -> V_34 , & V_10 -> V_32 . V_35 ) ;
F_13 ( & V_10 -> V_32 . V_33 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
T_1 V_36 , T_1 V_37 )
{
struct V_3 * V_4 ;
T_1 V_38 ;
int V_18 ;
V_4 = F_2 ( V_2 ) ;
V_38 = V_37 ;
if ( ! V_38 ) {
V_38 = V_36 ;
}
if ( ! V_38 ) {
F_7 ( V_23 L_3 ) ;
return 0 ;
}
if ( V_38 == V_39 ) {
V_18 = F_15 ( V_4 , NULL , false ) ;
if ( V_18 ) {
F_7 ( V_40 L_4 ) ;
return V_18 ;
}
}
return 0 ;
}
int F_16 ( struct V_9 * V_10 )
{
F_17 ( & V_10 -> V_32 . V_35 ) ;
return 0 ;
}
void F_18 ( struct V_9 * V_10 )
{
F_19 ( V_10 ) ;
}
int F_20 ( struct V_1 * V_16 , struct V_41 * V_42 )
{
struct V_3 * V_43 = F_2 ( V_16 ) ;
struct V_9 * V_10 = V_43 -> V_10 ;
struct V_44 * V_45 = V_42 -> V_46 ;
struct V_47 * V_48 = & V_45 -> V_48 ;
struct V_49 * V_50 ;
int V_18 ;
if ( V_10 -> V_51 < V_52 ) {
return 0 ;
}
V_18 = F_21 ( V_43 , false ) ;
if ( V_18 ) {
return V_18 ;
}
V_50 = F_22 ( V_48 , V_43 ) ;
if ( ! V_50 ) {
V_50 = F_23 ( V_10 , V_48 , V_43 ) ;
} else {
++ V_50 -> V_53 ;
}
F_24 ( V_43 ) ;
return 0 ;
}
void F_25 ( struct V_1 * V_16 ,
struct V_41 * V_42 )
{
struct V_3 * V_43 = F_2 ( V_16 ) ;
struct V_9 * V_10 = V_43 -> V_10 ;
struct V_44 * V_45 = V_42 -> V_46 ;
struct V_47 * V_48 = & V_45 -> V_48 ;
struct V_49 * V_50 ;
int V_18 ;
if ( V_10 -> V_51 < V_52 ) {
return;
}
V_18 = F_21 ( V_43 , true ) ;
if ( V_18 ) {
F_26 ( V_10 -> V_54 , L_5
L_6 , V_18 ) ;
return;
}
V_50 = F_22 ( V_48 , V_43 ) ;
if ( V_50 ) {
if ( -- V_50 -> V_53 == 0 ) {
F_27 ( V_10 , V_50 ) ;
}
}
F_24 ( V_43 ) ;
}
static int F_28 ( struct V_9 * V_10 , int V_18 )
{
if ( V_18 == - V_55 ) {
V_18 = F_29 ( V_10 ) ;
if ( ! V_18 )
V_18 = - V_56 ;
}
return V_18 ;
}
int F_30 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_9 * V_10 = V_54 -> V_60 ;
struct V_61 * args = V_58 ;
struct V_62 * V_63 ;
unsigned V_64 ;
V_63 = & V_10 -> V_65 . V_66 . V_63 [ V_67 ] ;
args -> V_68 = V_10 -> V_20 . V_69 ;
args -> V_70 = ( V_71 ) V_63 -> V_11 << V_72 ;
if ( V_10 -> V_73 )
args -> V_70 -= F_31 ( V_10 -> V_73 ) ;
args -> V_70 -= F_32 ( V_10 ) ;
args -> V_74 = V_10 -> V_20 . V_22 - 4096 - V_75 * 64 * 1024 ;
for( V_64 = 0 ; V_64 < V_76 ; ++ V_64 )
args -> V_74 -= V_10 -> V_77 [ V_64 ] . V_78 ;
return 0 ;
}
int F_33 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
F_9 ( L_7 , V_24 ) ;
return - V_79 ;
}
int F_34 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
F_9 ( L_7 , V_24 ) ;
return - V_79 ;
}
int F_35 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_9 * V_10 = V_54 -> V_60 ;
struct V_80 * args = V_58 ;
struct V_1 * V_2 ;
T_1 V_81 ;
int V_18 ;
F_36 ( & V_10 -> V_82 ) ;
args -> V_11 = F_37 ( args -> V_11 , V_19 ) ;
V_18 = F_5 ( V_10 , args -> V_11 , args -> V_12 ,
args -> V_13 , false ,
false , & V_2 ) ;
if ( V_18 ) {
F_38 ( & V_10 -> V_82 ) ;
V_18 = F_28 ( V_10 , V_18 ) ;
return V_18 ;
}
V_18 = F_39 ( V_59 , V_2 , & V_81 ) ;
F_40 ( V_2 ) ;
if ( V_18 ) {
F_38 ( & V_10 -> V_82 ) ;
V_18 = F_28 ( V_10 , V_18 ) ;
return V_18 ;
}
args -> V_81 = V_81 ;
F_38 ( & V_10 -> V_82 ) ;
return 0 ;
}
int F_41 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_9 * V_10 = V_54 -> V_60 ;
struct V_83 * args = V_58 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
F_36 ( & V_10 -> V_82 ) ;
V_2 = F_42 ( V_54 , V_59 , args -> V_81 ) ;
if ( V_2 == NULL ) {
F_38 ( & V_10 -> V_82 ) ;
return - V_84 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_14 ( V_2 , args -> V_85 , args -> V_86 ) ;
F_40 ( V_2 ) ;
F_38 ( & V_10 -> V_82 ) ;
V_18 = F_28 ( V_4 -> V_10 , V_18 ) ;
return V_18 ;
}
int F_43 ( struct V_41 * V_59 ,
struct V_57 * V_54 ,
T_1 V_81 , T_2 * V_87 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_42 ( V_54 , V_59 , V_81 ) ;
if ( V_2 == NULL ) {
return - V_84 ;
}
V_4 = F_2 ( V_2 ) ;
* V_87 = F_44 ( V_4 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
int F_45 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_88 * args = V_58 ;
return F_43 ( V_59 , V_54 , args -> V_81 , & args -> V_89 ) ;
}
int F_46 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_9 * V_10 = V_54 -> V_60 ;
struct V_90 * args = V_58 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
T_1 V_91 = 0 ;
V_2 = F_42 ( V_54 , V_59 , args -> V_81 ) ;
if ( V_2 == NULL ) {
return - V_84 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_15 ( V_4 , & V_91 , true ) ;
switch ( V_91 ) {
case V_67 :
args -> V_38 = V_28 ;
break;
case V_92 :
args -> V_38 = V_29 ;
break;
case V_93 :
args -> V_38 = V_39 ;
default:
break;
}
F_40 ( V_2 ) ;
V_18 = F_28 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_47 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_9 * V_10 = V_54 -> V_60 ;
struct V_94 * args = V_58 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_2 = F_42 ( V_54 , V_59 , args -> V_81 ) ;
if ( V_2 == NULL ) {
return - V_84 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_15 ( V_4 , NULL , false ) ;
if ( V_10 -> V_95 -> V_96 )
V_4 -> V_10 -> V_95 -> V_96 ( V_10 , V_4 ) ;
F_40 ( V_2 ) ;
V_18 = F_28 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_48 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_97 * args = V_58 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = 0 ;
F_49 ( L_8 , args -> V_81 ) ;
V_2 = F_42 ( V_54 , V_59 , args -> V_81 ) ;
if ( V_2 == NULL )
return - V_84 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_50 ( V_4 , args -> V_98 , args -> V_99 ) ;
F_40 ( V_2 ) ;
return V_18 ;
}
int F_51 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_100 * args = V_58 ;
struct V_1 * V_2 ;
struct V_3 * V_43 ;
int V_18 = 0 ;
F_49 ( L_9 ) ;
V_2 = F_42 ( V_54 , V_59 , args -> V_81 ) ;
if ( V_2 == NULL )
return - V_84 ;
V_43 = F_2 ( V_2 ) ;
V_18 = F_21 ( V_43 , false ) ;
if ( F_52 ( V_18 != 0 ) )
goto V_101;
F_53 ( V_43 , & args -> V_98 , & args -> V_99 ) ;
F_24 ( V_43 ) ;
V_101:
F_40 ( V_2 ) ;
return V_18 ;
}
int F_54 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_102 * args = V_58 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_54 -> V_60 ;
struct V_44 * V_45 = V_59 -> V_46 ;
struct V_3 * V_43 ;
struct V_49 * V_50 ;
T_3 V_103 ;
int V_18 = 0 ;
if ( ! V_10 -> V_104 . V_105 ) {
args -> V_106 = V_107 ;
return - V_108 ;
}
if ( args -> V_109 ) {
args -> V_106 = V_107 ;
return - V_110 ;
}
if ( args -> V_111 < V_112 ) {
F_26 ( & V_54 -> V_113 -> V_54 ,
L_10 ,
( unsigned long ) args -> V_111 ,
V_112 ) ;
args -> V_106 = V_107 ;
return - V_110 ;
}
V_103 = V_114 | V_115 ;
if ( ( args -> V_116 & V_103 ) ) {
F_26 ( & V_54 -> V_113 -> V_54 , L_11 ,
args -> V_116 , V_103 ) ;
args -> V_106 = V_107 ;
return - V_110 ;
}
if ( ! ( args -> V_116 & V_117 ) ) {
F_26 ( & V_54 -> V_113 -> V_54 , L_12 ) ;
args -> V_106 = V_107 ;
return - V_110 ;
}
switch ( args -> V_106 ) {
case V_118 :
case V_119 :
break;
default:
F_26 ( & V_54 -> V_113 -> V_54 , L_13 ,
args -> V_106 ) ;
args -> V_106 = V_107 ;
return - V_110 ;
}
V_2 = F_42 ( V_54 , V_59 , args -> V_81 ) ;
if ( V_2 == NULL ) {
args -> V_106 = V_107 ;
return - V_84 ;
}
V_43 = F_2 ( V_2 ) ;
V_18 = F_21 ( V_43 , false ) ;
if ( V_18 ) {
args -> V_106 = V_107 ;
F_40 ( V_2 ) ;
return V_18 ;
}
V_50 = F_22 ( & V_45 -> V_48 , V_43 ) ;
if ( ! V_50 ) {
args -> V_106 = V_107 ;
F_40 ( V_2 ) ;
return - V_84 ;
}
switch ( args -> V_106 ) {
case V_118 :
if ( V_50 -> V_120 ) {
args -> V_106 = V_121 ;
args -> V_111 = V_50 -> V_120 ;
goto V_101;
}
V_18 = F_55 ( V_10 , V_50 , args -> V_111 , args -> V_116 ) ;
break;
case V_119 :
V_18 = F_55 ( V_10 , V_50 , 0 , 0 ) ;
break;
default:
break;
}
args -> V_106 = V_122 ;
if ( V_18 ) {
args -> V_106 = V_107 ;
}
V_101:
F_24 ( V_43 ) ;
F_40 ( V_2 ) ;
return V_18 ;
}
int F_56 ( struct V_41 * V_42 ,
struct V_57 * V_54 ,
struct V_123 * args )
{
struct V_9 * V_10 = V_54 -> V_60 ;
struct V_1 * V_2 ;
T_1 V_81 ;
int V_18 ;
args -> V_99 = F_57 ( V_10 , args -> V_124 , args -> V_125 , 0 ) * ( ( args -> V_125 + 1 ) / 8 ) ;
args -> V_11 = args -> V_99 * args -> V_126 ;
args -> V_11 = F_58 ( args -> V_11 , V_19 ) ;
V_18 = F_5 ( V_10 , args -> V_11 , 0 ,
V_28 ,
false , V_127 ,
& V_2 ) ;
if ( V_18 )
return - V_25 ;
V_18 = F_39 ( V_42 , V_2 , & V_81 ) ;
F_40 ( V_2 ) ;
if ( V_18 ) {
return V_18 ;
}
args -> V_81 = V_81 ;
return 0 ;
}
static int F_59 ( struct V_128 * V_129 , void * V_58 )
{
struct V_130 * V_131 = (struct V_130 * ) V_129 -> V_132 ;
struct V_57 * V_54 = V_131 -> V_133 -> V_54 ;
struct V_9 * V_10 = V_54 -> V_60 ;
struct V_3 * V_43 ;
unsigned V_64 = 0 ;
F_11 ( & V_10 -> V_32 . V_33 ) ;
F_60 (rbo, &rdev->gem.objects, list) {
unsigned V_38 ;
const char * V_134 ;
V_38 = F_61 ( V_43 -> V_7 . V_135 . V_136 ) ;
switch ( V_38 ) {
case V_28 :
V_134 = L_14 ;
break;
case V_29 :
V_134 = L_15 ;
break;
case V_39 :
default:
V_134 = L_16 ;
break;
}
F_62 ( V_129 , L_17 ,
V_64 , F_31 ( V_43 ) >> 10 , F_31 ( V_43 ) >> 20 ,
V_134 , ( unsigned long ) V_43 -> V_30 ) ;
V_64 ++ ;
}
F_13 ( & V_10 -> V_32 . V_33 ) ;
return 0 ;
}
int F_63 ( struct V_9 * V_10 )
{
#if F_64 ( V_137 )
return F_65 ( V_10 , V_138 , 1 ) ;
#endif
return 0 ;
}
