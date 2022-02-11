void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 ) {
if ( V_4 -> V_5 . V_6 )
F_3 ( & V_4 -> V_5 , V_4 -> V_7 . V_8 ) ;
F_4 ( & V_4 ) ;
}
}
int F_5 ( struct V_9 * V_10 , unsigned long V_11 ,
int V_12 , int V_13 ,
T_1 V_14 , bool V_15 ,
struct V_1 * * V_16 )
{
struct V_3 * V_4 ;
unsigned long V_17 ;
int V_18 ;
* V_16 = NULL ;
if ( V_12 < V_19 ) {
V_12 = V_19 ;
}
V_17 = V_10 -> V_20 . V_21 - V_10 -> V_22 ;
if ( V_11 > V_17 ) {
F_6 ( L_1 ,
V_11 >> 20 , V_17 >> 20 ) ;
return - V_23 ;
}
V_24:
V_18 = F_7 ( V_10 , V_11 , V_12 , V_15 , V_13 ,
V_14 , NULL , & V_4 ) ;
if ( V_18 ) {
if ( V_18 != - V_25 ) {
if ( V_13 == V_26 ) {
V_13 |= V_27 ;
goto V_24;
}
F_8 ( L_2 ,
V_11 , V_13 , V_12 , V_18 ) ;
}
return V_18 ;
}
* V_16 = & V_4 -> V_5 ;
V_4 -> V_28 = F_9 ( V_29 ) ;
F_10 ( & V_10 -> V_30 . V_31 ) ;
F_11 ( & V_4 -> V_32 , & V_10 -> V_30 . V_33 ) ;
F_12 ( & V_10 -> V_30 . V_31 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_2 V_34 , T_2 V_35 )
{
struct V_3 * V_4 ;
T_2 V_36 ;
int V_18 ;
V_4 = F_2 ( V_2 ) ;
V_36 = V_35 ;
if ( ! V_36 ) {
V_36 = V_34 ;
}
if ( ! V_36 ) {
F_14 ( V_37 L_3 ) ;
return 0 ;
}
if ( V_36 == V_38 ) {
V_18 = F_15 ( V_4 , NULL , false ) ;
if ( V_18 ) {
F_14 ( V_39 L_4 ) ;
return V_18 ;
}
}
return 0 ;
}
int F_16 ( struct V_9 * V_10 )
{
F_17 ( & V_10 -> V_30 . V_33 ) ;
return 0 ;
}
void F_18 ( struct V_9 * V_10 )
{
F_19 ( V_10 ) ;
}
int F_20 ( struct V_1 * V_16 , struct V_40 * V_41 )
{
struct V_3 * V_42 = F_2 ( V_16 ) ;
struct V_9 * V_10 = V_42 -> V_10 ;
struct V_43 * V_44 = V_41 -> V_45 ;
struct V_46 * V_47 = & V_44 -> V_47 ;
struct V_48 * V_49 ;
int V_18 ;
if ( V_10 -> V_50 < V_51 ) {
return 0 ;
}
V_18 = F_21 ( V_42 , false ) ;
if ( V_18 ) {
return V_18 ;
}
V_49 = F_22 ( V_47 , V_42 ) ;
if ( ! V_49 ) {
V_49 = F_23 ( V_10 , V_47 , V_42 ) ;
} else {
++ V_49 -> V_52 ;
}
F_24 ( V_42 ) ;
return 0 ;
}
void F_25 ( struct V_1 * V_16 ,
struct V_40 * V_41 )
{
struct V_3 * V_42 = F_2 ( V_16 ) ;
struct V_9 * V_10 = V_42 -> V_10 ;
struct V_43 * V_44 = V_41 -> V_45 ;
struct V_46 * V_47 = & V_44 -> V_47 ;
struct V_48 * V_49 ;
int V_18 ;
if ( V_10 -> V_50 < V_51 ) {
return;
}
V_18 = F_21 ( V_42 , true ) ;
if ( V_18 ) {
F_26 ( V_10 -> V_53 , L_5
L_6 , V_18 ) ;
return;
}
V_49 = F_22 ( V_47 , V_42 ) ;
if ( V_49 ) {
if ( -- V_49 -> V_52 == 0 ) {
F_27 ( V_10 , V_49 ) ;
}
}
F_24 ( V_42 ) ;
}
static int F_28 ( struct V_9 * V_10 , int V_18 )
{
if ( V_18 == - V_54 ) {
V_18 = F_29 ( V_10 ) ;
if ( ! V_18 )
V_18 = - V_55 ;
}
return V_18 ;
}
int F_30 ( struct V_56 * V_53 , void * V_57 ,
struct V_40 * V_58 )
{
struct V_9 * V_10 = V_53 -> V_59 ;
struct V_60 * args = V_57 ;
struct V_61 * V_62 ;
V_62 = & V_10 -> V_63 . V_64 . V_62 [ V_65 ] ;
args -> V_66 = V_10 -> V_20 . V_67 ;
args -> V_68 = ( V_69 ) V_62 -> V_11 << V_70 ;
args -> V_68 -= V_10 -> V_71 ;
args -> V_72 = V_10 -> V_20 . V_21 ;
args -> V_72 -= V_10 -> V_22 ;
return 0 ;
}
int F_31 ( struct V_56 * V_53 , void * V_57 ,
struct V_40 * V_58 )
{
F_8 ( L_7 , V_73 ) ;
return - V_74 ;
}
int F_32 ( struct V_56 * V_53 , void * V_57 ,
struct V_40 * V_58 )
{
F_8 ( L_7 , V_73 ) ;
return - V_74 ;
}
int F_33 ( struct V_56 * V_53 , void * V_57 ,
struct V_40 * V_58 )
{
struct V_9 * V_10 = V_53 -> V_59 ;
struct V_75 * args = V_57 ;
struct V_1 * V_2 ;
T_2 V_76 ;
int V_18 ;
F_34 ( & V_10 -> V_77 ) ;
args -> V_11 = F_35 ( args -> V_11 , V_19 ) ;
V_18 = F_5 ( V_10 , args -> V_11 , args -> V_12 ,
args -> V_13 , args -> V_14 ,
false , & V_2 ) ;
if ( V_18 ) {
F_36 ( & V_10 -> V_77 ) ;
V_18 = F_28 ( V_10 , V_18 ) ;
return V_18 ;
}
V_18 = F_37 ( V_58 , V_2 , & V_76 ) ;
F_38 ( V_2 ) ;
if ( V_18 ) {
F_36 ( & V_10 -> V_77 ) ;
V_18 = F_28 ( V_10 , V_18 ) ;
return V_18 ;
}
args -> V_76 = V_76 ;
F_36 ( & V_10 -> V_77 ) ;
return 0 ;
}
int F_39 ( struct V_56 * V_53 , void * V_57 ,
struct V_40 * V_58 )
{
struct V_9 * V_10 = V_53 -> V_59 ;
struct V_78 * args = V_57 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
F_34 ( & V_10 -> V_77 ) ;
V_2 = F_40 ( V_53 , V_58 , args -> V_76 ) ;
if ( V_2 == NULL ) {
F_36 ( & V_10 -> V_77 ) ;
return - V_79 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_13 ( V_2 , args -> V_80 , args -> V_81 ) ;
F_38 ( V_2 ) ;
F_36 ( & V_10 -> V_77 ) ;
V_18 = F_28 ( V_4 -> V_10 , V_18 ) ;
return V_18 ;
}
int F_41 ( struct V_40 * V_58 ,
struct V_56 * V_53 ,
T_2 V_76 , T_3 * V_82 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_40 ( V_53 , V_58 , V_76 ) ;
if ( V_2 == NULL ) {
return - V_79 ;
}
V_4 = F_2 ( V_2 ) ;
* V_82 = F_42 ( V_4 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
int F_43 ( struct V_56 * V_53 , void * V_57 ,
struct V_40 * V_58 )
{
struct V_83 * args = V_57 ;
return F_41 ( V_58 , V_53 , args -> V_76 , & args -> V_84 ) ;
}
int F_44 ( struct V_56 * V_53 , void * V_57 ,
struct V_40 * V_58 )
{
struct V_9 * V_10 = V_53 -> V_59 ;
struct V_85 * args = V_57 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
T_2 V_86 = 0 ;
V_2 = F_40 ( V_53 , V_58 , args -> V_76 ) ;
if ( V_2 == NULL ) {
return - V_79 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_15 ( V_4 , & V_86 , true ) ;
args -> V_36 = F_45 ( V_86 ) ;
F_38 ( V_2 ) ;
V_18 = F_28 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_46 ( struct V_56 * V_53 , void * V_57 ,
struct V_40 * V_58 )
{
struct V_9 * V_10 = V_53 -> V_59 ;
struct V_87 * args = V_57 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
T_2 V_86 = 0 ;
V_2 = F_40 ( V_53 , V_58 , args -> V_76 ) ;
if ( V_2 == NULL ) {
return - V_79 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_15 ( V_4 , & V_86 , false ) ;
if ( V_10 -> V_88 -> V_89 &&
F_45 ( V_86 ) == V_26 )
V_4 -> V_10 -> V_88 -> V_89 ( V_10 ) ;
F_38 ( V_2 ) ;
V_18 = F_28 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_47 ( struct V_56 * V_53 , void * V_57 ,
struct V_40 * V_58 )
{
struct V_90 * args = V_57 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = 0 ;
F_6 ( L_8 , args -> V_76 ) ;
V_2 = F_40 ( V_53 , V_58 , args -> V_76 ) ;
if ( V_2 == NULL )
return - V_79 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_48 ( V_4 , args -> V_91 , args -> V_92 ) ;
F_38 ( V_2 ) ;
return V_18 ;
}
int F_49 ( struct V_56 * V_53 , void * V_57 ,
struct V_40 * V_58 )
{
struct V_93 * args = V_57 ;
struct V_1 * V_2 ;
struct V_3 * V_42 ;
int V_18 = 0 ;
F_6 ( L_9 ) ;
V_2 = F_40 ( V_53 , V_58 , args -> V_76 ) ;
if ( V_2 == NULL )
return - V_79 ;
V_42 = F_2 ( V_2 ) ;
V_18 = F_21 ( V_42 , false ) ;
if ( F_50 ( V_18 != 0 ) )
goto V_94;
F_51 ( V_42 , & args -> V_91 , & args -> V_92 ) ;
F_24 ( V_42 ) ;
V_94:
F_38 ( V_2 ) ;
return V_18 ;
}
int F_52 ( struct V_56 * V_53 , void * V_57 ,
struct V_40 * V_58 )
{
struct V_95 * args = V_57 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_53 -> V_59 ;
struct V_43 * V_44 = V_58 -> V_45 ;
struct V_3 * V_42 ;
struct V_48 * V_49 ;
T_1 V_96 ;
int V_18 = 0 ;
if ( ! V_10 -> V_97 . V_98 ) {
args -> V_99 = V_100 ;
return - V_101 ;
}
if ( args -> V_102 ) {
args -> V_99 = V_100 ;
return - V_103 ;
}
if ( args -> V_104 < V_105 ) {
F_26 ( & V_53 -> V_106 -> V_53 ,
L_10 ,
( unsigned long ) args -> V_104 ,
V_105 ) ;
args -> V_99 = V_100 ;
return - V_103 ;
}
V_96 = V_107 | V_108 ;
if ( ( args -> V_14 & V_96 ) ) {
F_26 ( & V_53 -> V_106 -> V_53 , L_11 ,
args -> V_14 , V_96 ) ;
args -> V_99 = V_100 ;
return - V_103 ;
}
switch ( args -> V_99 ) {
case V_109 :
case V_110 :
break;
default:
F_26 ( & V_53 -> V_106 -> V_53 , L_12 ,
args -> V_99 ) ;
args -> V_99 = V_100 ;
return - V_103 ;
}
V_2 = F_40 ( V_53 , V_58 , args -> V_76 ) ;
if ( V_2 == NULL ) {
args -> V_99 = V_100 ;
return - V_79 ;
}
V_42 = F_2 ( V_2 ) ;
V_18 = F_21 ( V_42 , false ) ;
if ( V_18 ) {
args -> V_99 = V_100 ;
F_38 ( V_2 ) ;
return V_18 ;
}
V_49 = F_22 ( & V_44 -> V_47 , V_42 ) ;
if ( ! V_49 ) {
args -> V_99 = V_100 ;
F_38 ( V_2 ) ;
return - V_79 ;
}
switch ( args -> V_99 ) {
case V_109 :
if ( V_49 -> V_111 . V_112 ) {
args -> V_99 = V_113 ;
args -> V_104 = V_49 -> V_111 . V_112 * V_114 ;
goto V_94;
}
V_18 = F_53 ( V_10 , V_49 , args -> V_104 , args -> V_14 ) ;
break;
case V_110 :
V_18 = F_53 ( V_10 , V_49 , 0 , 0 ) ;
break;
default:
break;
}
args -> V_99 = V_115 ;
if ( V_18 ) {
args -> V_99 = V_100 ;
}
V_94:
F_24 ( V_42 ) ;
F_38 ( V_2 ) ;
return V_18 ;
}
int F_54 ( struct V_56 * V_53 , void * V_57 ,
struct V_40 * V_58 )
{
struct V_116 * args = V_57 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_2 = F_40 ( V_53 , V_58 , args -> V_76 ) ;
if ( V_2 == NULL ) {
return - V_79 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_21 ( V_4 , false ) ;
if ( F_50 ( V_18 ) )
goto V_94;
switch ( args -> V_117 ) {
case V_118 :
args -> V_119 = V_4 -> V_13 ;
break;
case V_120 :
V_4 -> V_13 = args -> V_119 & ( V_26 |
V_27 |
V_38 ) ;
break;
default:
V_18 = - V_103 ;
}
F_24 ( V_4 ) ;
V_94:
F_38 ( V_2 ) ;
return V_18 ;
}
int F_55 ( struct V_40 * V_41 ,
struct V_56 * V_53 ,
struct V_121 * args )
{
struct V_9 * V_10 = V_53 -> V_59 ;
struct V_1 * V_2 ;
T_2 V_76 ;
int V_18 ;
args -> V_92 = F_56 ( V_10 , args -> V_122 , args -> V_123 , 0 ) * ( ( args -> V_123 + 1 ) / 8 ) ;
args -> V_11 = args -> V_92 * args -> V_124 ;
args -> V_11 = F_57 ( args -> V_11 , V_19 ) ;
V_18 = F_5 ( V_10 , args -> V_11 , 0 ,
V_26 , 0 ,
false , & V_2 ) ;
if ( V_18 )
return - V_23 ;
V_18 = F_37 ( V_41 , V_2 , & V_76 ) ;
F_38 ( V_2 ) ;
if ( V_18 ) {
return V_18 ;
}
args -> V_76 = V_76 ;
return 0 ;
}
static int F_58 ( struct V_125 * V_126 , void * V_57 )
{
struct V_127 * V_128 = (struct V_127 * ) V_126 -> V_129 ;
struct V_56 * V_53 = V_128 -> V_130 -> V_53 ;
struct V_9 * V_10 = V_53 -> V_59 ;
struct V_3 * V_42 ;
unsigned V_131 = 0 ;
F_10 ( & V_10 -> V_30 . V_31 ) ;
F_59 (rbo, &rdev->gem.objects, list) {
unsigned V_36 ;
const char * V_132 ;
V_36 = F_45 ( V_42 -> V_7 . V_133 . V_134 ) ;
switch ( V_36 ) {
case V_26 :
V_132 = L_13 ;
break;
case V_27 :
V_132 = L_14 ;
break;
case V_38 :
default:
V_132 = L_15 ;
break;
}
F_60 ( V_126 , L_16 ,
V_131 , F_61 ( V_42 ) >> 10 , F_61 ( V_42 ) >> 20 ,
V_132 , ( unsigned long ) V_42 -> V_28 ) ;
V_131 ++ ;
}
F_12 ( & V_10 -> V_30 . V_31 ) ;
return 0 ;
}
int F_62 ( struct V_9 * V_10 )
{
#if F_63 ( V_135 )
return F_64 ( V_10 , V_136 , 1 ) ;
#endif
return 0 ;
}
