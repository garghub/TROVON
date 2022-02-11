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
V_14 , NULL , NULL , & V_4 ) ;
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
long V_18 ;
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
V_18 = F_15 ( V_4 -> V_7 . V_39 , true , true , 30 * V_40 ) ;
if ( ! V_18 )
V_18 = - V_41 ;
if ( V_18 < 0 && V_18 != - V_42 ) {
F_14 ( V_43 L_4 , V_18 ) ;
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
int F_20 ( struct V_1 * V_16 , struct V_44 * V_45 )
{
struct V_3 * V_46 = F_2 ( V_16 ) ;
struct V_9 * V_10 = V_46 -> V_10 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_50 * V_51 = & V_48 -> V_51 ;
struct V_52 * V_53 ;
int V_18 ;
if ( V_10 -> V_54 < V_55 ) {
return 0 ;
}
V_18 = F_21 ( V_46 , false ) ;
if ( V_18 ) {
return V_18 ;
}
V_53 = F_22 ( V_51 , V_46 ) ;
if ( ! V_53 ) {
V_53 = F_23 ( V_10 , V_51 , V_46 ) ;
} else {
++ V_53 -> V_56 ;
}
F_24 ( V_46 ) ;
return 0 ;
}
void F_25 ( struct V_1 * V_16 ,
struct V_44 * V_45 )
{
struct V_3 * V_46 = F_2 ( V_16 ) ;
struct V_9 * V_10 = V_46 -> V_10 ;
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_50 * V_51 = & V_48 -> V_51 ;
struct V_52 * V_53 ;
int V_18 ;
if ( V_10 -> V_54 < V_55 ) {
return;
}
V_18 = F_21 ( V_46 , true ) ;
if ( V_18 ) {
F_26 ( V_10 -> V_57 , L_5
L_6 , V_18 ) ;
return;
}
V_53 = F_22 ( V_51 , V_46 ) ;
if ( V_53 ) {
if ( -- V_53 -> V_56 == 0 ) {
F_27 ( V_10 , V_53 ) ;
}
}
F_24 ( V_46 ) ;
}
static int F_28 ( struct V_9 * V_10 , int V_18 )
{
if ( V_18 == - V_58 ) {
V_18 = F_29 ( V_10 ) ;
if ( ! V_18 )
V_18 = - V_59 ;
}
return V_18 ;
}
int F_30 ( struct V_60 * V_57 , void * V_61 ,
struct V_44 * V_62 )
{
struct V_9 * V_10 = V_57 -> V_63 ;
struct V_64 * args = V_61 ;
struct V_65 * V_66 ;
V_66 = & V_10 -> V_67 . V_68 . V_66 [ V_69 ] ;
args -> V_70 = V_10 -> V_20 . V_71 ;
args -> V_72 = ( V_73 ) V_66 -> V_11 << V_74 ;
args -> V_72 -= V_10 -> V_75 ;
args -> V_76 = V_10 -> V_20 . V_21 ;
args -> V_76 -= V_10 -> V_22 ;
return 0 ;
}
int F_31 ( struct V_60 * V_57 , void * V_61 ,
struct V_44 * V_62 )
{
F_8 ( L_7 , V_77 ) ;
return - V_78 ;
}
int F_32 ( struct V_60 * V_57 , void * V_61 ,
struct V_44 * V_62 )
{
F_8 ( L_7 , V_77 ) ;
return - V_78 ;
}
int F_33 ( struct V_60 * V_57 , void * V_61 ,
struct V_44 * V_62 )
{
struct V_9 * V_10 = V_57 -> V_63 ;
struct V_79 * args = V_61 ;
struct V_1 * V_2 ;
T_2 V_80 ;
int V_18 ;
F_34 ( & V_10 -> V_81 ) ;
args -> V_11 = F_35 ( args -> V_11 , V_19 ) ;
V_18 = F_5 ( V_10 , args -> V_11 , args -> V_12 ,
args -> V_13 , args -> V_14 ,
false , & V_2 ) ;
if ( V_18 ) {
F_36 ( & V_10 -> V_81 ) ;
V_18 = F_28 ( V_10 , V_18 ) ;
return V_18 ;
}
V_18 = F_37 ( V_62 , V_2 , & V_80 ) ;
F_38 ( V_2 ) ;
if ( V_18 ) {
F_36 ( & V_10 -> V_81 ) ;
V_18 = F_28 ( V_10 , V_18 ) ;
return V_18 ;
}
args -> V_80 = V_80 ;
F_36 ( & V_10 -> V_81 ) ;
return 0 ;
}
int F_39 ( struct V_60 * V_57 , void * V_61 ,
struct V_44 * V_62 )
{
struct V_9 * V_10 = V_57 -> V_63 ;
struct V_82 * args = V_61 ;
struct V_1 * V_2 ;
struct V_3 * V_83 ;
T_2 V_80 ;
int V_18 ;
if ( F_40 ( args -> V_84 | args -> V_11 ) )
return - V_85 ;
if ( args -> V_14 & ~ ( V_86 |
V_87 | V_88 |
V_89 ) )
return - V_85 ;
if ( args -> V_14 & V_86 ) {
if ( V_10 -> V_54 < V_90 )
return - V_85 ;
} else if ( ! ( args -> V_14 & V_87 ) ||
! ( args -> V_14 & V_89 ) ) {
return - V_91 ;
}
F_34 ( & V_10 -> V_81 ) ;
V_18 = F_5 ( V_10 , args -> V_11 , 0 ,
V_38 , 0 ,
false , & V_2 ) ;
if ( V_18 )
goto V_92;
V_83 = F_2 ( V_2 ) ;
V_18 = F_41 ( V_83 -> V_7 . V_93 , args -> V_84 , args -> V_14 ) ;
if ( V_18 )
goto V_94;
if ( args -> V_14 & V_89 ) {
V_18 = F_42 ( V_83 , args -> V_84 ) ;
if ( V_18 )
goto V_94;
}
if ( args -> V_14 & V_88 ) {
F_34 ( & V_29 -> V_95 -> V_96 ) ;
V_18 = F_21 ( V_83 , true ) ;
if ( V_18 ) {
F_36 ( & V_29 -> V_95 -> V_96 ) ;
goto V_94;
}
F_43 ( V_83 , V_27 ) ;
V_18 = F_44 ( & V_83 -> V_7 , & V_83 -> V_97 , true , false ) ;
F_24 ( V_83 ) ;
F_36 ( & V_29 -> V_95 -> V_96 ) ;
if ( V_18 )
goto V_94;
}
V_18 = F_37 ( V_62 , V_2 , & V_80 ) ;
F_38 ( V_2 ) ;
if ( V_18 )
goto V_92;
args -> V_80 = V_80 ;
F_36 ( & V_10 -> V_81 ) ;
return 0 ;
V_94:
F_38 ( V_2 ) ;
V_92:
F_36 ( & V_10 -> V_81 ) ;
V_18 = F_28 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_45 ( struct V_60 * V_57 , void * V_61 ,
struct V_44 * V_62 )
{
struct V_9 * V_10 = V_57 -> V_63 ;
struct V_98 * args = V_61 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
F_34 ( & V_10 -> V_81 ) ;
V_2 = F_46 ( V_57 , V_62 , args -> V_80 ) ;
if ( V_2 == NULL ) {
F_36 ( & V_10 -> V_81 ) ;
return - V_99 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_13 ( V_2 , args -> V_100 , args -> V_101 ) ;
F_38 ( V_2 ) ;
F_36 ( & V_10 -> V_81 ) ;
V_18 = F_28 ( V_4 -> V_10 , V_18 ) ;
return V_18 ;
}
int F_47 ( struct V_44 * V_62 ,
struct V_60 * V_57 ,
T_2 V_80 , T_3 * V_102 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_46 ( V_57 , V_62 , V_80 ) ;
if ( V_2 == NULL ) {
return - V_99 ;
}
V_4 = F_2 ( V_2 ) ;
if ( F_48 ( V_4 -> V_7 . V_93 ) ) {
F_38 ( V_2 ) ;
return - V_103 ;
}
* V_102 = F_49 ( V_4 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
int F_50 ( struct V_60 * V_57 , void * V_61 ,
struct V_44 * V_62 )
{
struct V_104 * args = V_61 ;
return F_47 ( V_62 , V_57 , args -> V_80 , & args -> V_105 ) ;
}
int F_51 ( struct V_60 * V_57 , void * V_61 ,
struct V_44 * V_62 )
{
struct V_9 * V_10 = V_57 -> V_63 ;
struct V_106 * args = V_61 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
T_2 V_107 = 0 ;
V_2 = F_46 ( V_57 , V_62 , args -> V_80 ) ;
if ( V_2 == NULL ) {
return - V_99 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = F_52 ( V_4 , & V_107 , true ) ;
args -> V_36 = F_53 ( V_107 ) ;
F_38 ( V_2 ) ;
V_18 = F_28 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_54 ( struct V_60 * V_57 , void * V_61 ,
struct V_44 * V_62 )
{
struct V_9 * V_10 = V_57 -> V_63 ;
struct V_108 * args = V_61 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = 0 ;
T_2 V_107 = 0 ;
long V_109 ;
V_2 = F_46 ( V_57 , V_62 , args -> V_80 ) ;
if ( V_2 == NULL ) {
return - V_99 ;
}
V_4 = F_2 ( V_2 ) ;
V_109 = F_15 ( V_4 -> V_7 . V_39 , true , true , 30 * V_40 ) ;
if ( V_109 == 0 )
V_18 = - V_41 ;
else if ( V_109 < 0 )
V_18 = V_109 ;
if ( V_10 -> V_110 -> V_111 &&
F_53 ( V_107 ) == V_26 )
V_4 -> V_10 -> V_110 -> V_111 ( V_10 ) ;
F_38 ( V_2 ) ;
V_18 = F_28 ( V_10 , V_18 ) ;
return V_18 ;
}
int F_55 ( struct V_60 * V_57 , void * V_61 ,
struct V_44 * V_62 )
{
struct V_112 * args = V_61 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 = 0 ;
F_6 ( L_8 , args -> V_80 ) ;
V_2 = F_46 ( V_57 , V_62 , args -> V_80 ) ;
if ( V_2 == NULL )
return - V_99 ;
V_4 = F_2 ( V_2 ) ;
V_18 = F_56 ( V_4 , args -> V_113 , args -> V_114 ) ;
F_38 ( V_2 ) ;
return V_18 ;
}
int F_57 ( struct V_60 * V_57 , void * V_61 ,
struct V_44 * V_62 )
{
struct V_115 * args = V_61 ;
struct V_1 * V_2 ;
struct V_3 * V_46 ;
int V_18 = 0 ;
F_6 ( L_9 ) ;
V_2 = F_46 ( V_57 , V_62 , args -> V_80 ) ;
if ( V_2 == NULL )
return - V_99 ;
V_46 = F_2 ( V_2 ) ;
V_18 = F_21 ( V_46 , false ) ;
if ( F_58 ( V_18 != 0 ) )
goto V_116;
F_59 ( V_46 , & args -> V_113 , & args -> V_114 ) ;
F_24 ( V_46 ) ;
V_116:
F_38 ( V_2 ) ;
return V_18 ;
}
int F_60 ( struct V_60 * V_57 , void * V_61 ,
struct V_44 * V_62 )
{
struct V_117 * args = V_61 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_57 -> V_63 ;
struct V_47 * V_48 = V_62 -> V_49 ;
struct V_3 * V_46 ;
struct V_52 * V_53 ;
T_1 V_118 ;
int V_18 = 0 ;
if ( ! V_10 -> V_119 . V_120 ) {
args -> V_121 = V_122 ;
return - V_123 ;
}
if ( args -> V_124 ) {
args -> V_121 = V_122 ;
return - V_85 ;
}
if ( args -> V_125 < V_126 ) {
F_26 ( & V_57 -> V_127 -> V_57 ,
L_10 ,
( unsigned long ) args -> V_125 ,
V_126 ) ;
args -> V_121 = V_122 ;
return - V_85 ;
}
V_118 = V_128 | V_129 ;
if ( ( args -> V_14 & V_118 ) ) {
F_26 ( & V_57 -> V_127 -> V_57 , L_11 ,
args -> V_14 , V_118 ) ;
args -> V_121 = V_122 ;
return - V_85 ;
}
switch ( args -> V_121 ) {
case V_130 :
case V_131 :
break;
default:
F_26 ( & V_57 -> V_127 -> V_57 , L_12 ,
args -> V_121 ) ;
args -> V_121 = V_122 ;
return - V_85 ;
}
V_2 = F_46 ( V_57 , V_62 , args -> V_80 ) ;
if ( V_2 == NULL ) {
args -> V_121 = V_122 ;
return - V_99 ;
}
V_46 = F_2 ( V_2 ) ;
V_18 = F_21 ( V_46 , false ) ;
if ( V_18 ) {
args -> V_121 = V_122 ;
F_38 ( V_2 ) ;
return V_18 ;
}
V_53 = F_22 ( & V_48 -> V_51 , V_46 ) ;
if ( ! V_53 ) {
args -> V_121 = V_122 ;
F_38 ( V_2 ) ;
return - V_99 ;
}
switch ( args -> V_121 ) {
case V_130 :
if ( V_53 -> V_132 . V_133 ) {
args -> V_121 = V_134 ;
args -> V_125 = V_53 -> V_132 . V_133 * V_135 ;
goto V_116;
}
V_18 = F_61 ( V_10 , V_53 , args -> V_125 , args -> V_14 ) ;
break;
case V_131 :
V_18 = F_61 ( V_10 , V_53 , 0 , 0 ) ;
break;
default:
break;
}
args -> V_121 = V_136 ;
if ( V_18 ) {
args -> V_121 = V_122 ;
}
V_116:
F_24 ( V_46 ) ;
F_38 ( V_2 ) ;
return V_18 ;
}
int F_62 ( struct V_60 * V_57 , void * V_61 ,
struct V_44 * V_62 )
{
struct V_137 * args = V_61 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_2 = F_46 ( V_57 , V_62 , args -> V_80 ) ;
if ( V_2 == NULL ) {
return - V_99 ;
}
V_4 = F_2 ( V_2 ) ;
V_18 = - V_103 ;
if ( F_48 ( V_4 -> V_7 . V_93 ) )
goto V_116;
V_18 = F_21 ( V_4 , false ) ;
if ( F_58 ( V_18 ) )
goto V_116;
switch ( args -> V_138 ) {
case V_139 :
args -> V_140 = V_4 -> V_13 ;
break;
case V_141 :
V_4 -> V_13 = args -> V_140 & ( V_26 |
V_27 |
V_38 ) ;
break;
default:
V_18 = - V_85 ;
}
F_24 ( V_4 ) ;
V_116:
F_38 ( V_2 ) ;
return V_18 ;
}
int F_63 ( struct V_44 * V_45 ,
struct V_60 * V_57 ,
struct V_142 * args )
{
struct V_9 * V_10 = V_57 -> V_63 ;
struct V_1 * V_2 ;
T_2 V_80 ;
int V_18 ;
args -> V_114 = F_64 ( V_10 , args -> V_143 , args -> V_144 , 0 ) * ( ( args -> V_144 + 1 ) / 8 ) ;
args -> V_11 = args -> V_114 * args -> V_145 ;
args -> V_11 = F_65 ( args -> V_11 , V_19 ) ;
V_18 = F_5 ( V_10 , args -> V_11 , 0 ,
V_26 , 0 ,
false , & V_2 ) ;
if ( V_18 )
return - V_23 ;
V_18 = F_37 ( V_45 , V_2 , & V_80 ) ;
F_38 ( V_2 ) ;
if ( V_18 ) {
return V_18 ;
}
args -> V_80 = V_80 ;
return 0 ;
}
static int F_66 ( struct V_146 * V_147 , void * V_61 )
{
struct V_148 * V_149 = (struct V_148 * ) V_147 -> V_150 ;
struct V_60 * V_57 = V_149 -> V_151 -> V_57 ;
struct V_9 * V_10 = V_57 -> V_63 ;
struct V_3 * V_46 ;
unsigned V_152 = 0 ;
F_10 ( & V_10 -> V_30 . V_31 ) ;
F_67 (rbo, &rdev->gem.objects, list) {
unsigned V_36 ;
const char * V_97 ;
V_36 = F_53 ( V_46 -> V_7 . V_153 . V_154 ) ;
switch ( V_36 ) {
case V_26 :
V_97 = L_13 ;
break;
case V_27 :
V_97 = L_14 ;
break;
case V_38 :
default:
V_97 = L_15 ;
break;
}
F_68 ( V_147 , L_16 ,
V_152 , F_69 ( V_46 ) >> 10 , F_69 ( V_46 ) >> 20 ,
V_97 , ( unsigned long ) V_46 -> V_28 ) ;
V_152 ++ ;
}
F_12 ( & V_10 -> V_30 . V_31 ) ;
return 0 ;
}
int F_70 ( struct V_9 * V_10 )
{
#if F_71 ( V_155 )
return F_72 ( V_10 , V_156 , 1 ) ;
#endif
return 0 ;
}
