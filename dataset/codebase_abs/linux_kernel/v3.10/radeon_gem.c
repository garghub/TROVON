int F_1 ( struct V_1 * V_2 )
{
F_2 () ;
return 0 ;
}
void F_3 ( struct V_1 * V_3 )
{
struct V_4 * V_5 = F_4 ( V_3 ) ;
if ( V_5 ) {
if ( V_5 -> V_6 . V_7 )
F_5 ( & V_5 -> V_6 , V_5 -> V_8 . V_9 ) ;
F_6 ( & V_5 ) ;
}
}
int F_7 ( struct V_10 * V_11 , int V_12 ,
int V_13 , int V_14 ,
bool V_15 , bool V_16 ,
struct V_1 * * V_2 )
{
struct V_4 * V_5 ;
unsigned long V_17 ;
int V_18 ;
* V_2 = NULL ;
if ( V_13 < V_19 ) {
V_13 = V_19 ;
}
V_17 = F_8 ( V_11 -> V_20 . V_21 , V_11 -> V_20 . V_22 ) ;
if ( V_12 > V_17 ) {
F_9 ( V_23 L_1 ,
V_24 , __LINE__ , V_12 >> 20 , V_17 >> 20 ) ;
return - V_25 ;
}
V_26:
V_18 = F_10 ( V_11 , V_12 , V_13 , V_16 , V_14 , NULL , & V_5 ) ;
if ( V_18 ) {
if ( V_18 != - V_27 ) {
if ( V_14 == V_28 ) {
V_14 |= V_29 ;
goto V_26;
}
F_11 ( L_2 ,
V_12 , V_14 , V_13 , V_18 ) ;
}
return V_18 ;
}
* V_2 = & V_5 -> V_6 ;
V_5 -> V_30 = F_12 ( V_31 ) ;
F_13 ( & V_11 -> V_32 . V_33 ) ;
F_14 ( & V_5 -> V_34 , & V_11 -> V_32 . V_35 ) ;
F_15 ( & V_11 -> V_32 . V_33 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_3 ,
T_1 V_36 , T_1 V_37 )
{
struct V_4 * V_5 ;
T_1 V_38 ;
int V_18 ;
V_5 = F_4 ( V_3 ) ;
V_38 = V_37 ;
if ( ! V_38 ) {
V_38 = V_36 ;
}
if ( ! V_38 ) {
F_9 ( V_23 L_3 ) ;
return 0 ;
}
if ( V_38 == V_39 ) {
V_18 = F_17 ( V_5 , NULL , false ) ;
if ( V_18 ) {
F_9 ( V_40 L_4 ) ;
return V_18 ;
}
}
return 0 ;
}
int F_18 ( struct V_10 * V_11 )
{
F_19 ( & V_11 -> V_32 . V_35 ) ;
return 0 ;
}
void F_20 ( struct V_10 * V_11 )
{
F_21 ( V_11 ) ;
}
int F_22 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_4 * V_43 = F_4 ( V_2 ) ;
struct V_10 * V_11 = V_43 -> V_11 ;
struct V_44 * V_45 = V_42 -> V_46 ;
struct V_47 * V_48 = & V_45 -> V_48 ;
struct V_49 * V_50 ;
int V_18 ;
if ( V_11 -> V_51 < V_52 ) {
return 0 ;
}
V_18 = F_23 ( V_43 , false ) ;
if ( V_18 ) {
return V_18 ;
}
V_50 = F_24 ( V_48 , V_43 ) ;
if ( ! V_50 ) {
V_50 = F_25 ( V_11 , V_48 , V_43 ) ;
} else {
++ V_50 -> V_53 ;
}
F_26 ( V_43 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_4 * V_43 = F_4 ( V_2 ) ;
struct V_10 * V_11 = V_43 -> V_11 ;
struct V_44 * V_45 = V_42 -> V_46 ;
struct V_47 * V_48 = & V_45 -> V_48 ;
struct V_49 * V_50 ;
int V_18 ;
if ( V_11 -> V_51 < V_52 ) {
return;
}
V_18 = F_23 ( V_43 , true ) ;
if ( V_18 ) {
F_28 ( V_11 -> V_54 , L_5
L_6 , V_18 ) ;
return;
}
V_50 = F_24 ( V_48 , V_43 ) ;
if ( V_50 ) {
if ( -- V_50 -> V_53 == 0 ) {
F_29 ( V_11 , V_50 ) ;
}
}
F_26 ( V_43 ) ;
}
static int F_30 ( struct V_10 * V_11 , int V_18 )
{
if ( V_18 == - V_55 ) {
V_18 = F_31 ( V_11 ) ;
if ( ! V_18 )
V_18 = - V_56 ;
}
return V_18 ;
}
int F_32 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_10 * V_11 = V_54 -> V_60 ;
struct V_61 * args = V_58 ;
struct V_62 * V_63 ;
unsigned V_64 ;
V_63 = & V_11 -> V_65 . V_66 . V_63 [ V_67 ] ;
args -> V_68 = V_11 -> V_20 . V_69 ;
args -> V_70 = ( V_71 ) V_63 -> V_12 << V_72 ;
if ( V_11 -> V_73 )
args -> V_70 -= F_33 ( V_11 -> V_73 ) ;
args -> V_70 -= F_34 ( V_11 ) ;
args -> V_74 = V_11 -> V_20 . V_22 - 4096 - V_75 * 64 * 1024 ;
for( V_64 = 0 ; V_64 < V_76 ; ++ V_64 )
args -> V_74 -= V_11 -> V_77 [ V_64 ] . V_78 ;
return 0 ;
}
int F_35 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
F_11 ( L_7 , V_24 ) ;
return - V_79 ;
}
int F_36 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
F_11 ( L_7 , V_24 ) ;
return - V_79 ;
}
int F_37 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_10 * V_11 = V_54 -> V_60 ;
struct V_80 * args = V_58 ;
struct V_1 * V_3 ;
T_1 V_81 ;
int V_18 ;
F_38 ( & V_11 -> V_82 ) ;
args -> V_12 = F_39 ( args -> V_12 , V_19 ) ;
V_18 = F_7 ( V_11 , args -> V_12 , args -> V_13 ,
args -> V_14 , false ,
false , & V_3 ) ;
if ( V_18 ) {
F_40 ( & V_11 -> V_82 ) ;
V_18 = F_30 ( V_11 , V_18 ) ;
return V_18 ;
}
V_18 = F_41 ( V_59 , V_3 , & V_81 ) ;
F_42 ( V_3 ) ;
if ( V_18 ) {
F_40 ( & V_11 -> V_82 ) ;
V_18 = F_30 ( V_11 , V_18 ) ;
return V_18 ;
}
args -> V_81 = V_81 ;
F_40 ( & V_11 -> V_82 ) ;
return 0 ;
}
int F_43 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_10 * V_11 = V_54 -> V_60 ;
struct V_83 * args = V_58 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_18 ;
F_38 ( & V_11 -> V_82 ) ;
V_3 = F_44 ( V_54 , V_59 , args -> V_81 ) ;
if ( V_3 == NULL ) {
F_40 ( & V_11 -> V_82 ) ;
return - V_84 ;
}
V_5 = F_4 ( V_3 ) ;
V_18 = F_16 ( V_3 , args -> V_85 , args -> V_86 ) ;
F_42 ( V_3 ) ;
F_40 ( & V_11 -> V_82 ) ;
V_18 = F_30 ( V_5 -> V_11 , V_18 ) ;
return V_18 ;
}
int F_45 ( struct V_41 * V_59 ,
struct V_57 * V_54 ,
T_1 V_81 , T_2 * V_87 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
V_3 = F_44 ( V_54 , V_59 , V_81 ) ;
if ( V_3 == NULL ) {
return - V_84 ;
}
V_5 = F_4 ( V_3 ) ;
* V_87 = F_46 ( V_5 ) ;
F_42 ( V_3 ) ;
return 0 ;
}
int F_47 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_88 * args = V_58 ;
return F_45 ( V_59 , V_54 , args -> V_81 , & args -> V_89 ) ;
}
int F_48 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_10 * V_11 = V_54 -> V_60 ;
struct V_90 * args = V_58 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_18 ;
T_1 V_91 = 0 ;
V_3 = F_44 ( V_54 , V_59 , args -> V_81 ) ;
if ( V_3 == NULL ) {
return - V_84 ;
}
V_5 = F_4 ( V_3 ) ;
V_18 = F_17 ( V_5 , & V_91 , true ) ;
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
F_42 ( V_3 ) ;
V_18 = F_30 ( V_11 , V_18 ) ;
return V_18 ;
}
int F_49 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_10 * V_11 = V_54 -> V_60 ;
struct V_94 * args = V_58 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_18 ;
V_3 = F_44 ( V_54 , V_59 , args -> V_81 ) ;
if ( V_3 == NULL ) {
return - V_84 ;
}
V_5 = F_4 ( V_3 ) ;
V_18 = F_17 ( V_5 , NULL , false ) ;
if ( V_11 -> V_95 -> V_96 )
V_5 -> V_11 -> V_95 -> V_96 ( V_11 , V_5 ) ;
F_42 ( V_3 ) ;
V_18 = F_30 ( V_11 , V_18 ) ;
return V_18 ;
}
int F_50 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_97 * args = V_58 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_18 = 0 ;
F_51 ( L_8 , args -> V_81 ) ;
V_3 = F_44 ( V_54 , V_59 , args -> V_81 ) ;
if ( V_3 == NULL )
return - V_84 ;
V_5 = F_4 ( V_3 ) ;
V_18 = F_52 ( V_5 , args -> V_98 , args -> V_99 ) ;
F_42 ( V_3 ) ;
return V_18 ;
}
int F_53 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_100 * args = V_58 ;
struct V_1 * V_3 ;
struct V_4 * V_43 ;
int V_18 = 0 ;
F_51 ( L_9 ) ;
V_3 = F_44 ( V_54 , V_59 , args -> V_81 ) ;
if ( V_3 == NULL )
return - V_84 ;
V_43 = F_4 ( V_3 ) ;
V_18 = F_23 ( V_43 , false ) ;
if ( F_54 ( V_18 != 0 ) )
goto V_101;
F_55 ( V_43 , & args -> V_98 , & args -> V_99 ) ;
F_26 ( V_43 ) ;
V_101:
F_42 ( V_3 ) ;
return V_18 ;
}
int F_56 ( struct V_57 * V_54 , void * V_58 ,
struct V_41 * V_59 )
{
struct V_102 * args = V_58 ;
struct V_1 * V_3 ;
struct V_10 * V_11 = V_54 -> V_60 ;
struct V_44 * V_45 = V_59 -> V_46 ;
struct V_4 * V_43 ;
struct V_49 * V_50 ;
T_3 V_103 ;
int V_18 = 0 ;
if ( ! V_11 -> V_104 . V_105 ) {
args -> V_106 = V_107 ;
return - V_108 ;
}
if ( args -> V_109 ) {
args -> V_106 = V_107 ;
return - V_110 ;
}
if ( args -> V_111 < V_112 ) {
F_28 ( & V_54 -> V_113 -> V_54 ,
L_10 ,
( unsigned long ) args -> V_111 ,
V_112 ) ;
args -> V_106 = V_107 ;
return - V_110 ;
}
V_103 = V_114 | V_115 ;
if ( ( args -> V_116 & V_103 ) ) {
F_28 ( & V_54 -> V_113 -> V_54 , L_11 ,
args -> V_116 , V_103 ) ;
args -> V_106 = V_107 ;
return - V_110 ;
}
if ( ! ( args -> V_116 & V_117 ) ) {
F_28 ( & V_54 -> V_113 -> V_54 , L_12 ) ;
args -> V_106 = V_107 ;
return - V_110 ;
}
switch ( args -> V_106 ) {
case V_118 :
case V_119 :
break;
default:
F_28 ( & V_54 -> V_113 -> V_54 , L_13 ,
args -> V_106 ) ;
args -> V_106 = V_107 ;
return - V_110 ;
}
V_3 = F_44 ( V_54 , V_59 , args -> V_81 ) ;
if ( V_3 == NULL ) {
args -> V_106 = V_107 ;
return - V_84 ;
}
V_43 = F_4 ( V_3 ) ;
V_18 = F_23 ( V_43 , false ) ;
if ( V_18 ) {
args -> V_106 = V_107 ;
F_42 ( V_3 ) ;
return V_18 ;
}
V_50 = F_24 ( & V_45 -> V_48 , V_43 ) ;
if ( ! V_50 ) {
args -> V_106 = V_107 ;
F_42 ( V_3 ) ;
return - V_84 ;
}
switch ( args -> V_106 ) {
case V_118 :
if ( V_50 -> V_120 ) {
args -> V_106 = V_121 ;
args -> V_111 = V_50 -> V_120 ;
goto V_101;
}
V_18 = F_57 ( V_11 , V_50 , args -> V_111 , args -> V_116 ) ;
break;
case V_119 :
V_18 = F_57 ( V_11 , V_50 , 0 , 0 ) ;
break;
default:
break;
}
args -> V_106 = V_122 ;
if ( V_18 ) {
args -> V_106 = V_107 ;
}
V_101:
F_26 ( V_43 ) ;
F_42 ( V_3 ) ;
return V_18 ;
}
int F_58 ( struct V_41 * V_42 ,
struct V_57 * V_54 ,
struct V_123 * args )
{
struct V_10 * V_11 = V_54 -> V_60 ;
struct V_1 * V_3 ;
T_1 V_81 ;
int V_18 ;
args -> V_99 = F_59 ( V_11 , args -> V_124 , args -> V_125 , 0 ) * ( ( args -> V_125 + 1 ) / 8 ) ;
args -> V_12 = args -> V_99 * args -> V_126 ;
args -> V_12 = F_60 ( args -> V_12 , V_19 ) ;
V_18 = F_7 ( V_11 , args -> V_12 , 0 ,
V_28 ,
false , V_127 ,
& V_3 ) ;
if ( V_18 )
return - V_25 ;
V_18 = F_41 ( V_42 , V_3 , & V_81 ) ;
F_42 ( V_3 ) ;
if ( V_18 ) {
return V_18 ;
}
args -> V_81 = V_81 ;
return 0 ;
}
int F_61 ( struct V_41 * V_42 ,
struct V_57 * V_54 ,
T_1 V_81 )
{
return F_62 ( V_42 , V_81 ) ;
}
static int F_63 ( struct V_128 * V_129 , void * V_58 )
{
struct V_130 * V_131 = (struct V_130 * ) V_129 -> V_132 ;
struct V_57 * V_54 = V_131 -> V_133 -> V_54 ;
struct V_10 * V_11 = V_54 -> V_60 ;
struct V_4 * V_43 ;
unsigned V_64 = 0 ;
F_13 ( & V_11 -> V_32 . V_33 ) ;
F_64 (rbo, &rdev->gem.objects, list) {
unsigned V_38 ;
const char * V_134 ;
V_38 = F_65 ( V_43 -> V_8 . V_135 . V_136 ) ;
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
F_66 ( V_129 , L_17 ,
V_64 , F_33 ( V_43 ) >> 10 , F_33 ( V_43 ) >> 20 ,
V_134 , ( unsigned long ) V_43 -> V_30 ) ;
V_64 ++ ;
}
F_15 ( & V_11 -> V_32 . V_33 ) ;
return 0 ;
}
int F_67 ( struct V_10 * V_11 )
{
#if F_68 ( V_137 )
return F_69 ( V_11 , V_138 , 1 ) ;
#endif
return 0 ;
}
