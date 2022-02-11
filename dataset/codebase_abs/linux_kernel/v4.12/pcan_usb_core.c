void F_1 ( char * V_1 , void * V_2 , int V_3 )
{
F_2 ( L_1 ,
V_4 , V_1 ? V_1 : L_2 , V_3 ) ;
F_3 ( V_5 , V_4 L_3 , V_6 ,
V_7 , 1 , V_2 , V_3 , false ) ;
}
void F_4 ( struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
if ( V_9 ) {
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 -> V_11 = V_11 ;
}
}
static void F_5 ( struct V_12 * V_13 , T_1 V_14 )
{
T_1 V_15 = V_14 / 1000000 ;
V_14 -= V_15 * 1000000 ;
V_13 -> V_16 += V_14 ;
if ( V_13 -> V_16 >= 1000000 ) {
V_13 -> V_16 -= 1000000 ;
V_15 ++ ;
}
V_13 -> V_17 += V_15 ;
}
void F_6 ( struct V_8 * V_9 , T_1 V_18 )
{
V_9 -> V_19 = V_18 ;
if ( V_9 -> V_20 . V_17 > 0 ) {
T_1 V_21 = V_9 -> V_19 - V_9 -> V_22 ;
if ( V_9 -> V_19 < V_9 -> V_22 )
V_21 &= ( 1 << V_9 -> V_11 -> V_23 ) - 1 ;
V_9 -> V_24 += V_21 ;
}
}
void F_7 ( struct V_8 * V_9 , T_1 V_18 )
{
if ( V_9 -> V_25 . V_17 == 0 ) {
V_9 -> V_25 = F_8 ( F_9 () ) ;
V_9 -> V_20 . V_17 = 0 ;
} else {
if ( V_9 -> V_20 . V_17 != 0 ) {
T_1 V_15 = V_9 -> V_20 . V_17
- V_9 -> V_25 . V_17 ;
if ( V_15 > 4200 ) {
V_9 -> V_25 = V_9 -> V_20 ;
V_9 -> V_24 = 0 ;
}
}
V_9 -> V_20 = F_8 ( F_9 () ) ;
V_9 -> V_26 ++ ;
}
V_9 -> V_22 = V_9 -> V_19 ;
F_6 ( V_9 , V_18 ) ;
}
void F_10 ( struct V_8 * V_9 , T_1 V_27 ,
struct V_12 * V_13 )
{
if ( V_9 -> V_20 . V_17 > 0 ) {
T_2 V_14 ;
V_14 = V_27 - V_9 -> V_19 ;
if ( V_27 < V_9 -> V_19 )
V_14 &= ( 1 << V_9 -> V_11 -> V_23 ) - 1 ;
V_14 += V_9 -> V_24 ;
V_14 *= V_9 -> V_11 -> V_28 ;
V_14 >>= V_9 -> V_11 -> V_29 ;
* V_13 = V_9 -> V_25 ;
F_5 ( V_13 , ( T_1 ) V_14 ) ;
} else {
* V_13 = F_8 ( F_9 () ) ;
}
}
int F_11 ( struct V_30 * V_31 ,
struct V_8 * V_9 , T_1 V_32 , T_1 V_33 )
{
struct V_34 * V_35 = F_12 ( V_31 ) ;
struct V_12 V_13 ;
F_10 ( V_9 , V_32 , & V_13 ) ;
V_35 -> V_36 = F_13 ( V_13 ) ;
return F_14 ( V_31 ) ;
}
static void F_15 ( struct V_37 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_40 ;
struct V_41 * V_42 ;
int V_43 ;
V_42 = V_39 -> V_42 ;
if ( ! F_16 ( V_42 ) )
return;
switch ( V_37 -> V_44 ) {
case 0 :
break;
case - V_45 :
case - V_46 :
case - V_47 :
case - V_48 :
return;
default:
if ( F_17 () )
F_18 ( V_42 ,
L_4 , V_37 -> V_44 ) ;
goto V_49;
}
if ( ( V_37 -> V_50 > 0 ) && ( V_39 -> V_11 -> V_51 ) ) {
if ( V_39 -> V_52 & V_53 ) {
V_43 = V_39 -> V_11 -> V_51 ( V_39 , V_37 ) ;
if ( V_43 )
F_1 ( L_5 ,
V_37 -> V_54 ,
V_37 -> V_55 ) ;
}
}
V_49:
F_19 ( V_37 , V_39 -> V_56 ,
F_20 ( V_39 -> V_56 , V_39 -> V_57 ) ,
V_37 -> V_54 , V_39 -> V_11 -> V_58 ,
F_15 , V_39 ) ;
F_21 ( V_37 , & V_39 -> V_59 ) ;
V_43 = F_22 ( V_37 , V_60 ) ;
if ( ! V_43 )
return;
F_23 ( V_37 ) ;
if ( V_43 == - V_61 )
F_24 ( V_42 ) ;
else
F_18 ( V_42 , L_6 ,
V_43 ) ;
}
static void F_25 ( struct V_37 * V_37 )
{
struct V_62 * V_40 = V_37 -> V_40 ;
struct V_38 * V_39 ;
struct V_41 * V_42 ;
F_26 ( ! V_40 ) ;
V_39 = V_40 -> V_39 ;
V_42 = V_39 -> V_42 ;
F_27 ( & V_39 -> V_63 ) ;
if ( ! F_16 ( V_42 ) )
return;
switch ( V_37 -> V_44 ) {
case 0 :
V_42 -> V_64 . V_65 ++ ;
V_42 -> V_64 . V_66 += V_40 -> V_67 ;
F_28 ( V_42 ) ;
break;
default:
if ( F_17 () )
F_18 ( V_42 , L_7 ,
V_37 -> V_44 ) ;
case - V_68 :
case - V_46 :
case - V_47 :
case - V_48 :
break;
}
F_29 ( V_42 , V_40 -> V_69 ) ;
V_40 -> V_69 = V_70 ;
if ( ! V_37 -> V_44 )
F_30 ( V_42 ) ;
}
static T_3 F_31 ( struct V_30 * V_31 ,
struct V_41 * V_42 )
{
struct V_38 * V_39 = F_32 ( V_42 ) ;
struct V_62 * V_40 = NULL ;
struct V_71 * V_64 = & V_42 -> V_64 ;
struct V_72 * V_73 = (struct V_72 * ) V_31 -> V_74 ;
struct V_37 * V_37 ;
T_4 * V_75 ;
int V_76 , V_43 ;
T_5 V_77 = V_39 -> V_11 -> V_78 ;
if ( F_33 ( V_42 , V_31 ) )
return V_79 ;
for ( V_76 = 0 ; V_76 < V_70 ; V_76 ++ )
if ( V_39 -> V_80 [ V_76 ] . V_69 == V_70 ) {
V_40 = V_39 -> V_80 + V_76 ;
break;
}
if ( ! V_40 ) {
return V_81 ;
}
V_37 = V_40 -> V_37 ;
V_75 = V_37 -> V_54 ;
V_43 = V_39 -> V_11 -> V_82 ( V_39 , V_31 , V_75 , & V_77 ) ;
if ( V_43 ) {
if ( F_17 () )
F_18 ( V_42 , L_8 ) ;
F_34 ( V_31 ) ;
V_64 -> V_83 ++ ;
return V_79 ;
}
V_40 -> V_69 = V_76 ;
V_40 -> V_67 = V_73 -> V_84 ;
F_21 ( V_37 , & V_39 -> V_85 ) ;
F_35 ( V_31 , V_42 , V_40 -> V_69 ) ;
F_36 ( & V_39 -> V_63 ) ;
V_43 = F_22 ( V_37 , V_60 ) ;
if ( V_43 ) {
F_37 ( V_42 , V_40 -> V_69 ) ;
F_23 ( V_37 ) ;
V_40 -> V_69 = V_70 ;
F_27 ( & V_39 -> V_63 ) ;
switch ( V_43 ) {
case - V_61 :
F_24 ( V_42 ) ;
break;
default:
F_38 ( V_42 , L_9 ,
V_43 ) ;
case - V_46 :
V_64 -> V_83 ++ ;
}
} else {
F_28 ( V_42 ) ;
if ( F_39 ( & V_39 -> V_63 ) >= V_70 )
F_40 ( V_42 ) ;
}
return V_79 ;
}
static int F_41 ( struct V_38 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_42 ;
int V_43 , V_76 ;
for ( V_76 = 0 ; V_76 < V_86 ; V_76 ++ ) {
struct V_37 * V_37 ;
T_4 * V_87 ;
V_37 = F_42 ( 0 , V_88 ) ;
if ( ! V_37 ) {
V_43 = - V_89 ;
break;
}
V_87 = F_43 ( V_39 -> V_11 -> V_58 , V_88 ) ;
if ( ! V_87 ) {
F_44 ( V_37 ) ;
V_43 = - V_89 ;
break;
}
F_19 ( V_37 , V_39 -> V_56 ,
F_20 ( V_39 -> V_56 , V_39 -> V_57 ) ,
V_87 , V_39 -> V_11 -> V_58 ,
F_15 , V_39 ) ;
V_37 -> V_90 |= V_91 ;
F_21 ( V_37 , & V_39 -> V_59 ) ;
V_43 = F_22 ( V_37 , V_88 ) ;
if ( V_43 ) {
if ( V_43 == - V_61 )
F_24 ( V_39 -> V_42 ) ;
F_23 ( V_37 ) ;
F_45 ( V_87 ) ;
F_44 ( V_37 ) ;
break;
}
F_44 ( V_37 ) ;
}
if ( V_76 < V_86 ) {
if ( V_76 == 0 ) {
F_18 ( V_42 , L_10 ) ;
return V_43 ;
}
F_38 ( V_42 , L_11 ) ;
}
for ( V_76 = 0 ; V_76 < V_70 ; V_76 ++ ) {
struct V_62 * V_40 ;
struct V_37 * V_37 ;
T_4 * V_87 ;
V_37 = F_42 ( 0 , V_88 ) ;
if ( ! V_37 ) {
V_43 = - V_89 ;
break;
}
V_87 = F_43 ( V_39 -> V_11 -> V_78 , V_88 ) ;
if ( ! V_87 ) {
F_44 ( V_37 ) ;
V_43 = - V_89 ;
break;
}
V_40 = V_39 -> V_80 + V_76 ;
V_40 -> V_39 = V_39 ;
V_40 -> V_37 = V_37 ;
F_19 ( V_37 , V_39 -> V_56 ,
F_46 ( V_39 -> V_56 , V_39 -> V_92 ) ,
V_87 , V_39 -> V_11 -> V_78 ,
F_25 , V_40 ) ;
V_37 -> V_90 |= V_91 ;
}
if ( V_76 < V_70 ) {
if ( V_76 == 0 ) {
F_18 ( V_42 , L_12 ) ;
goto V_93;
}
F_38 ( V_42 , L_13 ) ;
}
if ( V_39 -> V_11 -> V_94 ) {
V_43 = V_39 -> V_11 -> V_94 ( V_39 ) ;
if ( V_43 )
goto V_95;
}
V_39 -> V_52 |= V_53 ;
if ( V_39 -> V_11 -> V_96 ) {
V_43 = V_39 -> V_11 -> V_96 ( V_39 , 1 ) ;
if ( V_43 )
goto V_95;
}
V_39 -> V_97 . V_52 = V_98 ;
return 0 ;
V_95:
if ( V_43 == - V_61 )
F_24 ( V_39 -> V_42 ) ;
F_38 ( V_42 , L_14 , V_43 ) ;
for ( V_76 = 0 ; V_76 < V_70 ; V_76 ++ ) {
F_44 ( V_39 -> V_80 [ V_76 ] . V_37 ) ;
V_39 -> V_80 [ V_76 ] . V_37 = NULL ;
}
V_93:
F_47 ( & V_39 -> V_59 ) ;
return V_43 ;
}
static int F_48 ( struct V_41 * V_42 )
{
struct V_38 * V_39 = F_32 ( V_42 ) ;
int V_43 ;
V_43 = F_49 ( V_42 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_41 ( V_39 ) ;
if ( V_43 ) {
F_18 ( V_42 , L_15 , V_43 ) ;
F_50 ( V_42 ) ;
return V_43 ;
}
F_51 ( V_42 ) ;
return 0 ;
}
static void F_52 ( struct V_38 * V_39 )
{
int V_76 ;
F_47 ( & V_39 -> V_59 ) ;
for ( V_76 = 0 ; V_76 < V_70 ; V_76 ++ ) {
struct V_37 * V_37 = V_39 -> V_80 [ V_76 ] . V_37 ;
if ( ! V_37 ||
V_39 -> V_80 [ V_76 ] . V_69 != V_70 ) {
continue;
}
F_44 ( V_37 ) ;
V_39 -> V_80 [ V_76 ] . V_37 = NULL ;
}
F_47 ( & V_39 -> V_85 ) ;
F_53 ( & V_39 -> V_63 , 0 ) ;
}
static int F_54 ( struct V_41 * V_42 )
{
struct V_38 * V_39 = F_32 ( V_42 ) ;
V_39 -> V_52 &= ~ V_53 ;
F_40 ( V_42 ) ;
F_52 ( V_39 ) ;
if ( V_39 -> V_11 -> V_99 )
V_39 -> V_11 -> V_99 ( V_39 ) ;
F_50 ( V_42 ) ;
V_39 -> V_97 . V_52 = V_100 ;
if ( V_39 -> V_11 -> V_96 ) {
int V_43 = V_39 -> V_11 -> V_96 ( V_39 , 0 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
void F_55 ( struct V_38 * V_39 )
{
V_39 -> V_97 . V_52 = V_98 ;
F_30 ( V_39 -> V_42 ) ;
}
void F_56 ( struct V_37 * V_37 )
{
F_45 ( V_37 -> V_54 ) ;
F_44 ( V_37 ) ;
}
static int F_57 ( struct V_38 * V_39 )
{
struct V_37 * V_37 ;
int V_43 ;
T_4 * V_87 ;
if ( ! V_39 -> V_11 -> V_101 ) {
F_55 ( V_39 ) ;
return 0 ;
}
V_37 = F_42 ( 0 , V_60 ) ;
if ( ! V_37 )
return - V_89 ;
V_87 = F_43 ( V_102 , V_60 ) ;
if ( ! V_87 ) {
F_44 ( V_37 ) ;
return - V_89 ;
}
V_43 = V_39 -> V_11 -> V_101 ( V_39 , V_37 , V_87 ) ;
if ( ! V_43 )
return 0 ;
F_45 ( V_87 ) ;
F_44 ( V_37 ) ;
return V_43 ;
}
static int F_58 ( struct V_41 * V_42 , enum V_103 V_104 )
{
struct V_38 * V_39 = F_32 ( V_42 ) ;
int V_43 = 0 ;
switch ( V_104 ) {
case V_105 :
V_43 = F_57 ( V_39 ) ;
if ( V_43 )
F_18 ( V_42 , L_16 ,
V_43 ) ;
break;
default:
return - V_106 ;
}
return V_43 ;
}
static int F_59 ( struct V_41 * V_42 )
{
struct V_38 * V_39 = F_32 ( V_42 ) ;
const struct V_10 * V_107 = V_39 -> V_11 ;
if ( V_107 -> V_108 ) {
struct V_109 * V_110 = & V_39 -> V_97 . V_111 ;
int V_43 = V_107 -> V_108 ( V_39 , V_110 ) ;
if ( V_43 )
F_60 ( V_42 , L_17 ,
V_43 ) ;
return V_43 ;
}
return 0 ;
}
static int F_61 ( struct V_41 * V_42 )
{
struct V_38 * V_39 = F_32 ( V_42 ) ;
const struct V_10 * V_107 = V_39 -> V_11 ;
if ( V_107 -> V_112 ) {
struct V_109 * V_110 = & V_39 -> V_97 . V_113 ;
int V_43 = V_107 -> V_112 ( V_39 , V_110 ) ;
if ( V_43 )
F_60 ( V_42 ,
L_18 ,
V_43 ) ;
return V_43 ;
}
return 0 ;
}
static int F_62 ( const struct V_10 * V_10 ,
struct V_114 * V_115 , int V_116 )
{
struct V_117 * V_118 = F_63 ( V_115 ) ;
int V_119 = V_10 -> V_120 ;
struct V_38 * V_39 ;
struct V_41 * V_42 ;
int V_76 , V_43 ;
T_6 V_121 ;
if ( V_119 < sizeof( struct V_38 ) )
V_119 = sizeof( struct V_38 ) ;
V_42 = F_64 ( V_119 , V_70 ) ;
if ( ! V_42 ) {
F_65 ( & V_115 -> V_39 , L_19 ,
V_4 ) ;
return - V_89 ;
}
V_39 = F_32 ( V_42 ) ;
V_39 -> V_122 = F_43 ( V_102 , V_88 ) ;
if ( ! V_39 -> V_122 ) {
V_43 = - V_89 ;
goto V_123;
}
V_39 -> V_56 = V_118 ;
V_39 -> V_42 = V_42 ;
V_39 -> V_11 = V_10 ;
V_39 -> V_116 = V_116 ;
V_39 -> V_52 = V_124 ;
V_39 -> V_57 = V_10 -> V_57 ;
V_39 -> V_92 = V_10 -> V_92 [ V_116 ] ;
V_39 -> V_97 . clock = V_10 -> clock ;
V_39 -> V_97 . V_125 = V_10 -> V_125 ;
V_39 -> V_97 . V_126 = F_59 ;
V_39 -> V_97 . V_127 = V_10 -> V_127 ;
V_39 -> V_97 . V_128 = F_61 ;
V_39 -> V_97 . V_129 = F_58 ;
V_39 -> V_97 . V_130 = V_10 -> V_130 ;
V_39 -> V_97 . V_131 = V_10 -> V_131 ;
V_42 -> V_132 = & V_133 ;
V_42 -> V_134 |= V_135 ;
F_66 ( & V_39 -> V_59 ) ;
F_66 ( & V_39 -> V_85 ) ;
F_53 ( & V_39 -> V_63 , 0 ) ;
for ( V_76 = 0 ; V_76 < V_70 ; V_76 ++ )
V_39 -> V_80 [ V_76 ] . V_69 = V_70 ;
V_39 -> V_136 = F_67 ( V_115 ) ;
F_68 ( V_115 , V_39 ) ;
F_69 ( V_42 , & V_115 -> V_39 ) ;
V_42 -> V_137 = V_116 ;
V_43 = F_70 ( V_42 ) ;
if ( V_43 ) {
F_65 ( & V_115 -> V_39 , L_20 , V_43 ) ;
goto V_138;
}
if ( V_39 -> V_136 )
( V_39 -> V_136 ) -> V_139 = V_39 ;
V_121 = F_71 ( V_118 -> V_140 . V_141 ) ;
V_39 -> V_142 = V_121 >> 8 ;
if ( V_39 -> V_11 -> V_143 ) {
V_43 = V_39 -> V_11 -> V_143 ( V_39 ) ;
if ( V_43 )
goto V_144;
}
if ( V_39 -> V_11 -> V_96 ) {
V_43 = V_39 -> V_11 -> V_96 ( V_39 , 0 ) ;
if ( V_43 )
goto V_144;
}
if ( V_39 -> V_11 -> V_145 )
V_39 -> V_11 -> V_145 ( V_39 , & V_39 -> V_146 ) ;
F_60 ( V_42 , L_21 ,
V_10 -> V_147 , V_116 , V_39 -> V_146 ) ;
return 0 ;
V_144:
F_72 ( V_42 ) ;
V_138:
F_68 ( V_115 , V_39 -> V_136 ) ;
F_45 ( V_39 -> V_122 ) ;
V_123:
F_73 ( V_42 ) ;
return V_43 ;
}
static void F_74 ( struct V_114 * V_115 )
{
struct V_38 * V_39 ;
struct V_38 * V_148 ;
for ( V_39 = F_67 ( V_115 ) ; V_39 ; V_39 = V_148 ) {
struct V_41 * V_42 = V_39 -> V_42 ;
char V_147 [ V_149 ] ;
V_148 = V_39 -> V_136 ;
V_39 -> V_52 &= ~ V_124 ;
strncpy ( V_147 , V_42 -> V_147 , V_149 ) ;
F_75 ( V_42 ) ;
F_45 ( V_39 -> V_122 ) ;
V_39 -> V_139 = NULL ;
if ( V_39 -> V_11 -> V_150 )
V_39 -> V_11 -> V_150 ( V_39 ) ;
F_73 ( V_42 ) ;
F_76 ( & V_115 -> V_39 , L_22 , V_147 ) ;
}
F_68 ( V_115 , NULL ) ;
}
static int F_77 ( struct V_114 * V_115 ,
const struct V_151 * V_152 )
{
struct V_117 * V_118 = F_63 ( V_115 ) ;
const T_6 V_153 = F_71 ( V_118 -> V_140 . V_154 ) ;
const struct V_10 * V_10 = NULL ;
int V_76 , V_43 = - V_89 ;
for ( V_76 = 0 ; V_76 < F_78 ( V_155 ) ; V_76 ++ )
if ( V_155 [ V_76 ] -> V_156 == V_153 ) {
V_10 = V_155 [ V_76 ] ;
break;
}
if ( ! V_10 ) {
F_79 ( L_23 ,
V_4 , V_153 ) ;
return - V_61 ;
}
if ( V_10 -> V_157 ) {
V_43 = V_10 -> V_157 ( V_115 ) ;
if ( V_43 )
return V_43 ;
}
for ( V_76 = 0 ; V_76 < V_10 -> V_158 ; V_76 ++ ) {
V_43 = F_62 ( V_10 , V_115 , V_76 ) ;
if ( V_43 ) {
F_74 ( V_115 ) ;
break;
}
}
return V_43 ;
}
static int T_7 F_80 ( void )
{
int V_43 ;
V_43 = F_81 ( & V_159 ) ;
if ( V_43 )
F_79 ( L_24 ,
V_4 , V_43 ) ;
return V_43 ;
}
static int F_82 ( struct V_160 * V_161 , void * V_162 )
{
struct V_114 * V_115 = F_83 ( V_161 ) ;
struct V_38 * V_39 ;
for ( V_39 = F_67 ( V_115 ) ; V_39 ; V_39 = V_39 -> V_136 ) {
struct V_41 * V_42 = V_39 -> V_42 ;
if ( F_16 ( V_42 ) )
if ( V_39 -> V_11 -> V_163 )
V_39 -> V_11 -> V_163 ( V_39 ) ;
}
return 0 ;
}
static void T_8 F_84 ( void )
{
int V_43 ;
V_43 = F_85 ( & V_159 . V_164 . V_165 , NULL ,
NULL , F_82 ) ;
if ( V_43 )
F_79 ( L_25 ,
V_4 , V_43 ) ;
F_86 ( & V_159 ) ;
F_2 ( L_26 ,
V_4 ) ;
}
