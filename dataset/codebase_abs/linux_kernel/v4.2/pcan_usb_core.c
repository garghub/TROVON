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
V_42 -> V_68 = V_69 ;
break;
default:
if ( F_17 () )
F_18 ( V_42 , L_7 ,
V_37 -> V_44 ) ;
case - V_70 :
case - V_46 :
case - V_47 :
case - V_48 :
break;
}
F_28 ( V_42 , V_40 -> V_71 ) ;
V_40 -> V_71 = V_72 ;
if ( ! V_37 -> V_44 )
F_29 ( V_42 ) ;
}
static T_3 F_30 ( struct V_30 * V_31 ,
struct V_41 * V_42 )
{
struct V_38 * V_39 = F_31 ( V_42 ) ;
struct V_62 * V_40 = NULL ;
struct V_73 * V_64 = & V_42 -> V_64 ;
struct V_74 * V_75 = (struct V_74 * ) V_31 -> V_76 ;
struct V_37 * V_37 ;
T_4 * V_77 ;
int V_78 , V_43 ;
T_5 V_79 = V_39 -> V_11 -> V_80 ;
if ( F_32 ( V_42 , V_31 ) )
return V_81 ;
for ( V_78 = 0 ; V_78 < V_72 ; V_78 ++ )
if ( V_39 -> V_82 [ V_78 ] . V_71 == V_72 ) {
V_40 = V_39 -> V_82 + V_78 ;
break;
}
if ( ! V_40 ) {
return V_83 ;
}
V_37 = V_40 -> V_37 ;
V_77 = V_37 -> V_54 ;
V_43 = V_39 -> V_11 -> V_84 ( V_39 , V_31 , V_77 , & V_79 ) ;
if ( V_43 ) {
if ( F_17 () )
F_18 ( V_42 , L_8 ) ;
F_33 ( V_31 ) ;
V_64 -> V_85 ++ ;
return V_81 ;
}
V_40 -> V_71 = V_78 ;
V_40 -> V_67 = V_75 -> V_86 ;
F_21 ( V_37 , & V_39 -> V_87 ) ;
F_34 ( V_31 , V_42 , V_40 -> V_71 ) ;
F_35 ( & V_39 -> V_63 ) ;
V_43 = F_22 ( V_37 , V_60 ) ;
if ( V_43 ) {
F_36 ( V_42 , V_40 -> V_71 ) ;
F_23 ( V_37 ) ;
V_40 -> V_71 = V_72 ;
F_27 ( & V_39 -> V_63 ) ;
switch ( V_43 ) {
case - V_61 :
F_24 ( V_42 ) ;
break;
default:
F_37 ( V_42 , L_9 ,
V_43 ) ;
case - V_46 :
V_64 -> V_85 ++ ;
}
} else {
V_42 -> V_68 = V_69 ;
if ( F_38 ( & V_39 -> V_63 ) >= V_72 )
F_39 ( V_42 ) ;
}
return V_81 ;
}
static int F_40 ( struct V_38 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_42 ;
int V_43 , V_78 ;
for ( V_78 = 0 ; V_78 < V_88 ; V_78 ++ ) {
struct V_37 * V_37 ;
T_4 * V_89 ;
V_37 = F_41 ( 0 , V_90 ) ;
if ( ! V_37 ) {
F_18 ( V_42 , L_10 ) ;
V_43 = - V_91 ;
break;
}
V_89 = F_42 ( V_39 -> V_11 -> V_58 , V_90 ) ;
if ( ! V_89 ) {
F_43 ( V_37 ) ;
V_43 = - V_91 ;
break;
}
F_19 ( V_37 , V_39 -> V_56 ,
F_20 ( V_39 -> V_56 , V_39 -> V_57 ) ,
V_89 , V_39 -> V_11 -> V_58 ,
F_15 , V_39 ) ;
V_37 -> V_92 |= V_93 ;
F_21 ( V_37 , & V_39 -> V_59 ) ;
V_43 = F_22 ( V_37 , V_90 ) ;
if ( V_43 ) {
if ( V_43 == - V_61 )
F_24 ( V_39 -> V_42 ) ;
F_23 ( V_37 ) ;
F_44 ( V_89 ) ;
F_43 ( V_37 ) ;
break;
}
F_43 ( V_37 ) ;
}
if ( V_78 < V_88 ) {
if ( V_78 == 0 ) {
F_18 ( V_42 , L_11 ) ;
return V_43 ;
}
F_37 ( V_42 , L_12 ) ;
}
for ( V_78 = 0 ; V_78 < V_72 ; V_78 ++ ) {
struct V_62 * V_40 ;
struct V_37 * V_37 ;
T_4 * V_89 ;
V_37 = F_41 ( 0 , V_90 ) ;
if ( ! V_37 ) {
F_18 ( V_42 , L_10 ) ;
V_43 = - V_91 ;
break;
}
V_89 = F_42 ( V_39 -> V_11 -> V_80 , V_90 ) ;
if ( ! V_89 ) {
F_43 ( V_37 ) ;
V_43 = - V_91 ;
break;
}
V_40 = V_39 -> V_82 + V_78 ;
V_40 -> V_39 = V_39 ;
V_40 -> V_37 = V_37 ;
F_19 ( V_37 , V_39 -> V_56 ,
F_45 ( V_39 -> V_56 , V_39 -> V_94 ) ,
V_89 , V_39 -> V_11 -> V_80 ,
F_25 , V_40 ) ;
V_37 -> V_92 |= V_93 ;
}
if ( V_78 < V_72 ) {
if ( V_78 == 0 ) {
F_18 ( V_42 , L_13 ) ;
goto V_95;
}
F_37 ( V_42 , L_14 ) ;
}
if ( V_39 -> V_11 -> V_96 ) {
V_43 = V_39 -> V_11 -> V_96 ( V_39 ) ;
if ( V_43 )
goto V_97;
}
V_39 -> V_52 |= V_53 ;
if ( V_39 -> V_11 -> V_98 ) {
V_43 = V_39 -> V_11 -> V_98 ( V_39 , 1 ) ;
if ( V_43 )
goto V_97;
}
V_39 -> V_99 . V_52 = V_100 ;
return 0 ;
V_97:
if ( V_43 == - V_61 )
F_24 ( V_39 -> V_42 ) ;
F_37 ( V_42 , L_15 , V_43 ) ;
for ( V_78 = 0 ; V_78 < V_72 ; V_78 ++ ) {
F_43 ( V_39 -> V_82 [ V_78 ] . V_37 ) ;
V_39 -> V_82 [ V_78 ] . V_37 = NULL ;
}
V_95:
F_46 ( & V_39 -> V_59 ) ;
return V_43 ;
}
static int F_47 ( struct V_41 * V_42 )
{
struct V_38 * V_39 = F_31 ( V_42 ) ;
int V_43 ;
V_43 = F_48 ( V_42 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_40 ( V_39 ) ;
if ( V_43 ) {
F_18 ( V_42 , L_16 , V_43 ) ;
F_49 ( V_42 ) ;
return V_43 ;
}
F_50 ( V_42 ) ;
return 0 ;
}
static void F_51 ( struct V_38 * V_39 )
{
int V_78 ;
F_46 ( & V_39 -> V_59 ) ;
for ( V_78 = 0 ; V_78 < V_72 ; V_78 ++ ) {
struct V_37 * V_37 = V_39 -> V_82 [ V_78 ] . V_37 ;
if ( ! V_37 ||
V_39 -> V_82 [ V_78 ] . V_71 != V_72 ) {
continue;
}
F_43 ( V_37 ) ;
V_39 -> V_82 [ V_78 ] . V_37 = NULL ;
}
F_46 ( & V_39 -> V_87 ) ;
F_52 ( & V_39 -> V_63 , 0 ) ;
}
static int F_53 ( struct V_41 * V_42 )
{
struct V_38 * V_39 = F_31 ( V_42 ) ;
V_39 -> V_52 &= ~ V_53 ;
F_39 ( V_42 ) ;
F_51 ( V_39 ) ;
if ( V_39 -> V_11 -> V_101 )
V_39 -> V_11 -> V_101 ( V_39 ) ;
F_49 ( V_42 ) ;
V_39 -> V_99 . V_52 = V_102 ;
if ( V_39 -> V_11 -> V_98 ) {
int V_43 = V_39 -> V_11 -> V_98 ( V_39 , 0 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
void F_54 ( struct V_38 * V_39 )
{
V_39 -> V_99 . V_52 = V_100 ;
F_29 ( V_39 -> V_42 ) ;
}
void F_55 ( struct V_37 * V_37 )
{
F_44 ( V_37 -> V_54 ) ;
F_43 ( V_37 ) ;
}
static int F_56 ( struct V_38 * V_39 )
{
struct V_37 * V_37 ;
int V_43 ;
T_4 * V_89 ;
if ( ! V_39 -> V_11 -> V_103 ) {
F_54 ( V_39 ) ;
return 0 ;
}
V_37 = F_41 ( 0 , V_60 ) ;
if ( ! V_37 ) {
F_18 ( V_39 -> V_42 , L_17 ) ;
return - V_91 ;
}
V_89 = F_42 ( V_104 , V_60 ) ;
if ( ! V_89 ) {
F_43 ( V_37 ) ;
return - V_91 ;
}
V_43 = V_39 -> V_11 -> V_103 ( V_39 , V_37 , V_89 ) ;
if ( ! V_43 )
return 0 ;
F_44 ( V_89 ) ;
F_43 ( V_37 ) ;
return V_43 ;
}
static int F_57 ( struct V_41 * V_42 , enum V_105 V_106 )
{
struct V_38 * V_39 = F_31 ( V_42 ) ;
int V_43 = 0 ;
switch ( V_106 ) {
case V_107 :
V_43 = F_56 ( V_39 ) ;
if ( V_43 )
F_18 ( V_42 , L_18 ,
V_43 ) ;
break;
default:
return - V_108 ;
}
return V_43 ;
}
static int F_58 ( struct V_41 * V_42 )
{
struct V_38 * V_39 = F_31 ( V_42 ) ;
const struct V_10 * V_109 = V_39 -> V_11 ;
if ( V_109 -> V_110 ) {
struct V_111 * V_112 = & V_39 -> V_99 . V_113 ;
int V_43 = V_109 -> V_110 ( V_39 , V_112 ) ;
if ( V_43 )
F_59 ( V_42 , L_19 ,
V_43 ) ;
return V_43 ;
}
return 0 ;
}
static int F_60 ( struct V_41 * V_42 )
{
struct V_38 * V_39 = F_31 ( V_42 ) ;
const struct V_10 * V_109 = V_39 -> V_11 ;
if ( V_109 -> V_114 ) {
struct V_111 * V_112 = & V_39 -> V_99 . V_115 ;
int V_43 = V_109 -> V_114 ( V_39 , V_112 ) ;
if ( V_43 )
F_59 ( V_42 ,
L_20 ,
V_43 ) ;
return V_43 ;
}
return 0 ;
}
static int F_61 ( const struct V_10 * V_10 ,
struct V_116 * V_117 , int V_118 )
{
struct V_119 * V_120 = F_62 ( V_117 ) ;
int V_121 = V_10 -> V_122 ;
struct V_38 * V_39 ;
struct V_41 * V_42 ;
int V_78 , V_43 ;
T_6 V_123 ;
if ( V_121 < sizeof( struct V_38 ) )
V_121 = sizeof( struct V_38 ) ;
V_42 = F_63 ( V_121 , V_72 ) ;
if ( ! V_42 ) {
F_64 ( & V_117 -> V_39 , L_21 ,
V_4 ) ;
return - V_91 ;
}
V_39 = F_31 ( V_42 ) ;
V_39 -> V_124 = F_42 ( V_104 , V_90 ) ;
if ( ! V_39 -> V_124 ) {
V_43 = - V_91 ;
goto V_125;
}
V_39 -> V_56 = V_120 ;
V_39 -> V_42 = V_42 ;
V_39 -> V_11 = V_10 ;
V_39 -> V_118 = V_118 ;
V_39 -> V_52 = V_126 ;
V_39 -> V_57 = V_10 -> V_57 ;
V_39 -> V_94 = V_10 -> V_94 [ V_118 ] ;
V_39 -> V_99 . clock = V_10 -> clock ;
V_39 -> V_99 . V_127 = V_10 -> V_127 ;
V_39 -> V_99 . V_128 = F_58 ;
V_39 -> V_99 . V_129 = V_10 -> V_129 ;
V_39 -> V_99 . V_130 = F_60 ;
V_39 -> V_99 . V_131 = F_57 ;
V_39 -> V_99 . V_132 = V_10 -> V_132 ;
V_39 -> V_99 . V_133 = V_10 -> V_133 ;
V_42 -> V_134 = & V_135 ;
V_42 -> V_136 |= V_137 ;
F_65 ( & V_39 -> V_59 ) ;
F_65 ( & V_39 -> V_87 ) ;
F_52 ( & V_39 -> V_63 , 0 ) ;
for ( V_78 = 0 ; V_78 < V_72 ; V_78 ++ )
V_39 -> V_82 [ V_78 ] . V_71 = V_72 ;
V_39 -> V_138 = F_66 ( V_117 ) ;
F_67 ( V_117 , V_39 ) ;
F_68 ( V_42 , & V_117 -> V_39 ) ;
V_42 -> V_139 = V_118 ;
V_43 = F_69 ( V_42 ) ;
if ( V_43 ) {
F_64 ( & V_117 -> V_39 , L_22 , V_43 ) ;
goto V_140;
}
if ( V_39 -> V_138 )
( V_39 -> V_138 ) -> V_141 = V_39 ;
V_123 = F_70 ( V_120 -> V_142 . V_143 ) ;
V_39 -> V_144 = V_123 >> 8 ;
if ( V_39 -> V_11 -> V_145 ) {
V_43 = V_39 -> V_11 -> V_145 ( V_39 ) ;
if ( V_43 )
goto V_146;
}
if ( V_39 -> V_11 -> V_98 ) {
V_43 = V_39 -> V_11 -> V_98 ( V_39 , 0 ) ;
if ( V_43 )
goto V_146;
}
if ( V_39 -> V_11 -> V_147 )
V_39 -> V_11 -> V_147 ( V_39 , & V_39 -> V_148 ) ;
F_59 ( V_42 , L_23 ,
V_10 -> V_149 , V_118 , V_39 -> V_148 ) ;
return 0 ;
V_146:
F_71 ( V_42 ) ;
V_140:
F_67 ( V_117 , V_39 -> V_138 ) ;
F_44 ( V_39 -> V_124 ) ;
V_125:
F_72 ( V_42 ) ;
return V_43 ;
}
static void F_73 ( struct V_116 * V_117 )
{
struct V_38 * V_39 ;
for ( V_39 = F_66 ( V_117 ) ; V_39 ; V_39 = V_39 -> V_138 ) {
struct V_41 * V_42 = V_39 -> V_42 ;
char V_149 [ V_150 ] ;
V_39 -> V_52 &= ~ V_126 ;
strncpy ( V_149 , V_42 -> V_149 , V_150 ) ;
F_74 ( V_42 ) ;
F_72 ( V_42 ) ;
F_44 ( V_39 -> V_124 ) ;
V_39 -> V_141 = NULL ;
if ( V_39 -> V_11 -> V_151 )
V_39 -> V_11 -> V_151 ( V_39 ) ;
F_75 ( & V_117 -> V_39 , L_24 , V_149 ) ;
}
F_67 ( V_117 , NULL ) ;
}
static int F_76 ( struct V_116 * V_117 ,
const struct V_152 * V_153 )
{
struct V_119 * V_120 = F_62 ( V_117 ) ;
const T_6 V_154 = F_70 ( V_120 -> V_142 . V_155 ) ;
const struct V_10 * V_10 = NULL ;
int V_78 , V_43 = - V_91 ;
V_120 = F_62 ( V_117 ) ;
for ( V_78 = 0 ; V_78 < F_77 ( V_156 ) ; V_78 ++ )
if ( V_156 [ V_78 ] -> V_157 == V_154 ) {
V_10 = V_156 [ V_78 ] ;
break;
}
if ( ! V_10 ) {
F_78 ( L_25 ,
V_4 , V_120 -> V_142 . V_155 ) ;
return - V_61 ;
}
if ( V_10 -> V_158 ) {
V_43 = V_10 -> V_158 ( V_117 ) ;
if ( V_43 )
return V_43 ;
}
for ( V_78 = 0 ; V_78 < V_10 -> V_159 ; V_78 ++ ) {
V_43 = F_61 ( V_10 , V_117 , V_78 ) ;
if ( V_43 ) {
F_73 ( V_117 ) ;
break;
}
}
return V_43 ;
}
static int T_7 F_79 ( void )
{
int V_43 ;
V_43 = F_80 ( & V_160 ) ;
if ( V_43 )
F_78 ( L_26 ,
V_4 , V_43 ) ;
return V_43 ;
}
static int F_81 ( struct V_161 * V_162 , void * V_163 )
{
struct V_116 * V_117 = F_82 ( V_162 ) ;
struct V_38 * V_39 ;
for ( V_39 = F_66 ( V_117 ) ; V_39 ; V_39 = V_39 -> V_138 ) {
struct V_41 * V_42 = V_39 -> V_42 ;
if ( F_16 ( V_42 ) )
if ( V_39 -> V_11 -> V_164 )
V_39 -> V_11 -> V_164 ( V_39 ) ;
}
return 0 ;
}
static void T_8 F_83 ( void )
{
int V_43 ;
V_43 = F_84 ( & V_160 . V_165 . V_166 , NULL ,
NULL , F_81 ) ;
if ( V_43 )
F_78 ( L_27 ,
V_4 , V_43 ) ;
F_85 ( & V_160 ) ;
F_2 ( L_28 ,
V_4 ) ;
}
