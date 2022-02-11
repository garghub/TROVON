void F_1 ( char * V_1 , void * V_2 , int V_3 )
{
F_2 ( L_1 ,
V_4 , V_1 ? V_1 : L_2 , V_3 ) ;
F_3 ( V_5 , V_4 L_3 , V_6 ,
V_7 , 1 , V_2 , V_3 , false ) ;
}
void F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
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
static void F_11 ( struct V_30 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_34 * V_35 ;
int V_36 ;
V_35 = V_32 -> V_35 ;
if ( ! F_12 ( V_35 ) )
return;
switch ( V_30 -> V_37 ) {
case 0 :
break;
case - V_38 :
case - V_39 :
case - V_40 :
case - V_41 :
return;
default:
if ( F_13 () )
F_14 ( V_35 ,
L_4 , V_30 -> V_37 ) ;
goto V_42;
}
if ( ( V_30 -> V_43 > 0 ) && ( V_32 -> V_11 -> V_44 ) ) {
if ( V_32 -> V_45 & V_46 ) {
V_36 = V_32 -> V_11 -> V_44 ( V_32 , V_30 ) ;
if ( V_36 )
F_1 ( L_5 ,
V_30 -> V_47 ,
V_30 -> V_48 ) ;
}
}
V_42:
F_15 ( V_30 , V_32 -> V_49 ,
F_16 ( V_32 -> V_49 , V_32 -> V_50 ) ,
V_30 -> V_47 , V_32 -> V_11 -> V_51 ,
F_11 , V_32 ) ;
F_17 ( V_30 , & V_32 -> V_52 ) ;
V_36 = F_18 ( V_30 , V_53 ) ;
if ( ! V_36 )
return;
F_19 ( V_30 ) ;
if ( V_36 == - V_54 )
F_20 ( V_35 ) ;
else
F_14 ( V_35 , L_6 ,
V_36 ) ;
}
static void F_21 ( struct V_30 * V_30 )
{
struct V_55 * V_33 = V_30 -> V_33 ;
struct V_31 * V_32 ;
struct V_34 * V_35 ;
F_22 ( ! V_33 ) ;
V_32 = V_33 -> V_32 ;
V_35 = V_32 -> V_35 ;
F_23 ( & V_32 -> V_56 ) ;
if ( ! F_12 ( V_35 ) )
return;
switch ( V_30 -> V_37 ) {
case 0 :
V_35 -> V_57 . V_58 ++ ;
V_35 -> V_57 . V_59 += V_33 -> V_60 ;
V_35 -> V_61 = V_62 ;
break;
default:
if ( F_13 () )
F_14 ( V_35 , L_7 ,
V_30 -> V_37 ) ;
case - V_63 :
case - V_39 :
case - V_40 :
case - V_41 :
break;
}
F_24 ( V_35 , V_33 -> V_64 ) ;
V_33 -> V_64 = V_65 ;
if ( ! V_30 -> V_37 )
F_25 ( V_35 ) ;
}
static T_3 F_26 ( struct V_66 * V_67 ,
struct V_34 * V_35 )
{
struct V_31 * V_32 = F_27 ( V_35 ) ;
struct V_55 * V_33 = NULL ;
struct V_68 * V_57 = & V_35 -> V_57 ;
struct V_69 * V_70 = (struct V_69 * ) V_67 -> V_71 ;
struct V_30 * V_30 ;
T_4 * V_72 ;
int V_73 , V_36 ;
T_5 V_74 = V_32 -> V_11 -> V_75 ;
if ( F_28 ( V_35 , V_67 ) )
return V_76 ;
for ( V_73 = 0 ; V_73 < V_65 ; V_73 ++ )
if ( V_32 -> V_77 [ V_73 ] . V_64 == V_65 ) {
V_33 = V_32 -> V_77 + V_73 ;
break;
}
if ( ! V_33 ) {
return V_78 ;
}
V_30 = V_33 -> V_30 ;
V_72 = V_30 -> V_47 ;
V_36 = V_32 -> V_11 -> V_79 ( V_32 , V_67 , V_72 , & V_74 ) ;
if ( V_36 ) {
if ( F_13 () )
F_14 ( V_35 , L_8 ) ;
F_29 ( V_67 ) ;
V_57 -> V_80 ++ ;
return V_76 ;
}
V_33 -> V_64 = V_73 ;
V_33 -> V_60 = V_70 -> V_81 ;
F_17 ( V_30 , & V_32 -> V_82 ) ;
F_30 ( V_67 , V_35 , V_33 -> V_64 ) ;
F_31 ( & V_32 -> V_56 ) ;
V_36 = F_18 ( V_30 , V_53 ) ;
if ( V_36 ) {
F_32 ( V_35 , V_33 -> V_64 ) ;
F_19 ( V_30 ) ;
V_33 -> V_64 = V_65 ;
F_23 ( & V_32 -> V_56 ) ;
switch ( V_36 ) {
case - V_54 :
F_20 ( V_35 ) ;
break;
default:
F_33 ( V_35 , L_9 ,
V_36 ) ;
case - V_39 :
V_57 -> V_80 ++ ;
}
} else {
V_35 -> V_61 = V_62 ;
if ( F_34 ( & V_32 -> V_56 ) >= V_65 )
F_35 ( V_35 ) ;
}
return V_76 ;
}
static int F_36 ( struct V_31 * V_32 )
{
struct V_34 * V_35 = V_32 -> V_35 ;
int V_36 , V_73 ;
for ( V_73 = 0 ; V_73 < V_83 ; V_73 ++ ) {
struct V_30 * V_30 ;
T_4 * V_84 ;
V_30 = F_37 ( 0 , V_85 ) ;
if ( ! V_30 ) {
F_14 ( V_35 , L_10 ) ;
V_36 = - V_86 ;
break;
}
V_84 = F_38 ( V_32 -> V_11 -> V_51 , V_85 ) ;
if ( ! V_84 ) {
F_39 ( V_30 ) ;
V_36 = - V_86 ;
break;
}
F_15 ( V_30 , V_32 -> V_49 ,
F_16 ( V_32 -> V_49 , V_32 -> V_50 ) ,
V_84 , V_32 -> V_11 -> V_51 ,
F_11 , V_32 ) ;
V_30 -> V_87 |= V_88 ;
F_17 ( V_30 , & V_32 -> V_52 ) ;
V_36 = F_18 ( V_30 , V_85 ) ;
if ( V_36 ) {
if ( V_36 == - V_54 )
F_20 ( V_32 -> V_35 ) ;
F_19 ( V_30 ) ;
F_40 ( V_84 ) ;
F_39 ( V_30 ) ;
break;
}
F_39 ( V_30 ) ;
}
if ( V_73 < V_83 ) {
if ( V_73 == 0 ) {
F_14 ( V_35 , L_11 ) ;
return V_36 ;
}
F_33 ( V_35 , L_12 ) ;
}
for ( V_73 = 0 ; V_73 < V_65 ; V_73 ++ ) {
struct V_55 * V_33 ;
struct V_30 * V_30 ;
T_4 * V_84 ;
V_30 = F_37 ( 0 , V_85 ) ;
if ( ! V_30 ) {
F_14 ( V_35 , L_10 ) ;
V_36 = - V_86 ;
break;
}
V_84 = F_38 ( V_32 -> V_11 -> V_75 , V_85 ) ;
if ( ! V_84 ) {
F_39 ( V_30 ) ;
V_36 = - V_86 ;
break;
}
V_33 = V_32 -> V_77 + V_73 ;
V_33 -> V_32 = V_32 ;
V_33 -> V_30 = V_30 ;
F_15 ( V_30 , V_32 -> V_49 ,
F_41 ( V_32 -> V_49 , V_32 -> V_89 ) ,
V_84 , V_32 -> V_11 -> V_75 ,
F_21 , V_33 ) ;
V_30 -> V_87 |= V_88 ;
}
if ( V_73 < V_65 ) {
if ( V_73 == 0 ) {
F_14 ( V_35 , L_13 ) ;
goto V_90;
}
F_33 ( V_35 , L_14 ) ;
}
if ( V_32 -> V_11 -> V_91 ) {
V_36 = V_32 -> V_11 -> V_91 ( V_32 ) ;
if ( V_36 )
goto V_92;
}
V_32 -> V_45 |= V_46 ;
if ( V_32 -> V_11 -> V_93 ) {
V_36 = V_32 -> V_11 -> V_93 ( V_32 , 1 ) ;
if ( V_36 )
goto V_92;
}
V_32 -> V_94 . V_45 = V_95 ;
return 0 ;
V_92:
if ( V_36 == - V_54 )
F_20 ( V_32 -> V_35 ) ;
F_33 ( V_35 , L_15 , V_36 ) ;
for ( V_73 = 0 ; V_73 < V_65 ; V_73 ++ ) {
F_39 ( V_32 -> V_77 [ V_73 ] . V_30 ) ;
V_32 -> V_77 [ V_73 ] . V_30 = NULL ;
}
V_90:
F_42 ( & V_32 -> V_52 ) ;
return V_36 ;
}
static int F_43 ( struct V_34 * V_35 )
{
struct V_31 * V_32 = F_27 ( V_35 ) ;
int V_36 ;
V_36 = F_44 ( V_35 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_36 ( V_32 ) ;
if ( V_36 ) {
F_14 ( V_35 , L_16 , V_36 ) ;
F_45 ( V_35 ) ;
return V_36 ;
}
F_46 ( V_35 ) ;
return 0 ;
}
static void F_47 ( struct V_31 * V_32 )
{
int V_73 ;
F_42 ( & V_32 -> V_52 ) ;
for ( V_73 = 0 ; V_73 < V_65 ; V_73 ++ ) {
struct V_30 * V_30 = V_32 -> V_77 [ V_73 ] . V_30 ;
if ( ! V_30 ||
V_32 -> V_77 [ V_73 ] . V_64 != V_65 ) {
continue;
}
F_39 ( V_30 ) ;
V_32 -> V_77 [ V_73 ] . V_30 = NULL ;
}
F_42 ( & V_32 -> V_82 ) ;
F_48 ( & V_32 -> V_56 , 0 ) ;
}
static int F_49 ( struct V_34 * V_35 )
{
struct V_31 * V_32 = F_27 ( V_35 ) ;
V_32 -> V_45 &= ~ V_46 ;
F_35 ( V_35 ) ;
F_47 ( V_32 ) ;
if ( V_32 -> V_11 -> V_96 )
V_32 -> V_11 -> V_96 ( V_32 ) ;
F_45 ( V_35 ) ;
V_32 -> V_94 . V_45 = V_97 ;
if ( V_32 -> V_11 -> V_93 ) {
int V_36 = V_32 -> V_11 -> V_93 ( V_32 , 0 ) ;
if ( V_36 )
return V_36 ;
}
return 0 ;
}
void F_50 ( struct V_31 * V_32 )
{
V_32 -> V_94 . V_45 = V_95 ;
F_25 ( V_32 -> V_35 ) ;
}
void F_51 ( struct V_30 * V_30 )
{
F_40 ( V_30 -> V_47 ) ;
F_39 ( V_30 ) ;
}
static int F_52 ( struct V_31 * V_32 )
{
struct V_30 * V_30 ;
int V_36 ;
T_4 * V_84 ;
if ( ! V_32 -> V_11 -> V_98 ) {
F_50 ( V_32 ) ;
return 0 ;
}
V_30 = F_37 ( 0 , V_53 ) ;
if ( ! V_30 ) {
F_14 ( V_32 -> V_35 , L_17 ) ;
return - V_86 ;
}
V_84 = F_38 ( V_99 , V_53 ) ;
if ( ! V_84 ) {
F_39 ( V_30 ) ;
return - V_86 ;
}
V_36 = V_32 -> V_11 -> V_98 ( V_32 , V_30 , V_84 ) ;
if ( ! V_36 )
return 0 ;
F_40 ( V_84 ) ;
F_39 ( V_30 ) ;
return V_36 ;
}
static int F_53 ( struct V_34 * V_35 , enum V_100 V_101 )
{
struct V_31 * V_32 = F_27 ( V_35 ) ;
int V_36 = 0 ;
switch ( V_101 ) {
case V_102 :
V_36 = F_52 ( V_32 ) ;
if ( V_36 )
F_14 ( V_35 , L_18 ,
V_36 ) ;
break;
default:
return - V_103 ;
}
return V_36 ;
}
static int F_54 ( struct V_34 * V_35 )
{
struct V_31 * V_32 = F_27 ( V_35 ) ;
struct V_104 * V_105 = & V_32 -> V_94 . V_106 ;
if ( V_32 -> V_11 -> V_107 ) {
int V_36 = V_32 -> V_11 -> V_107 ( V_32 , V_105 ) ;
if ( V_36 )
F_55 ( V_35 , L_19 ,
V_36 ) ;
return V_36 ;
}
return 0 ;
}
static int F_56 ( struct V_10 * V_10 ,
struct V_108 * V_109 , int V_110 )
{
struct V_111 * V_112 = F_57 ( V_109 ) ;
int V_113 = V_10 -> V_114 ;
struct V_31 * V_32 ;
struct V_34 * V_35 ;
int V_73 , V_36 ;
T_6 V_115 ;
if ( V_113 < sizeof( struct V_31 ) )
V_113 = sizeof( struct V_31 ) ;
V_35 = F_58 ( V_113 , V_65 ) ;
if ( ! V_35 ) {
F_59 ( & V_109 -> V_32 , L_20 ,
V_4 ) ;
return - V_86 ;
}
V_32 = F_27 ( V_35 ) ;
V_32 -> V_116 = F_38 ( V_99 , V_85 ) ;
if ( ! V_32 -> V_116 ) {
V_36 = - V_86 ;
goto V_117;
}
V_32 -> V_49 = V_112 ;
V_32 -> V_35 = V_35 ;
V_32 -> V_11 = V_10 ;
V_32 -> V_110 = V_110 ;
V_32 -> V_45 = V_118 ;
V_32 -> V_50 = V_10 -> V_50 ;
V_32 -> V_89 = V_10 -> V_89 [ V_110 ] ;
V_32 -> V_94 . clock = V_10 -> clock ;
V_32 -> V_94 . V_119 = & V_10 -> V_119 ;
V_32 -> V_94 . V_120 = F_54 ;
V_32 -> V_94 . V_121 = F_53 ;
V_32 -> V_94 . V_122 = V_123 |
V_124 ;
V_35 -> V_125 = & V_126 ;
V_35 -> V_127 |= V_128 ;
F_60 ( & V_32 -> V_52 ) ;
F_60 ( & V_32 -> V_82 ) ;
F_48 ( & V_32 -> V_56 , 0 ) ;
for ( V_73 = 0 ; V_73 < V_65 ; V_73 ++ )
V_32 -> V_77 [ V_73 ] . V_64 = V_65 ;
V_32 -> V_129 = F_61 ( V_109 ) ;
F_62 ( V_109 , V_32 ) ;
F_63 ( V_35 , & V_109 -> V_32 ) ;
V_36 = F_64 ( V_35 ) ;
if ( V_36 ) {
F_59 ( & V_109 -> V_32 , L_21 , V_36 ) ;
goto V_130;
}
if ( V_32 -> V_129 )
( V_32 -> V_129 ) -> V_131 = V_32 ;
V_115 = F_65 ( V_112 -> V_132 . V_133 ) ;
V_32 -> V_134 = V_115 >> 8 ;
if ( V_32 -> V_11 -> V_135 ) {
V_36 = V_32 -> V_11 -> V_135 ( V_32 ) ;
if ( V_36 )
goto V_130;
}
if ( V_32 -> V_11 -> V_93 ) {
V_36 = V_32 -> V_11 -> V_93 ( V_32 , 0 ) ;
if ( V_36 )
goto V_130;
}
if ( V_32 -> V_11 -> V_136 )
V_32 -> V_11 -> V_136 ( V_32 , & V_32 -> V_137 ) ;
F_55 ( V_35 , L_22 ,
V_10 -> V_138 , V_110 , V_32 -> V_137 ) ;
return 0 ;
V_130:
F_40 ( V_32 -> V_116 ) ;
V_117:
F_62 ( V_109 , V_32 -> V_129 ) ;
F_66 ( V_35 ) ;
return V_36 ;
}
static void F_67 ( struct V_108 * V_109 )
{
struct V_31 * V_32 ;
for ( V_32 = F_61 ( V_109 ) ; V_32 ; V_32 = V_32 -> V_129 ) {
struct V_34 * V_35 = V_32 -> V_35 ;
char V_138 [ V_139 ] ;
V_32 -> V_45 &= ~ V_118 ;
strncpy ( V_138 , V_35 -> V_138 , V_139 ) ;
F_68 ( V_35 ) ;
F_66 ( V_35 ) ;
F_40 ( V_32 -> V_116 ) ;
V_32 -> V_131 = NULL ;
if ( V_32 -> V_11 -> V_140 )
V_32 -> V_11 -> V_140 ( V_32 ) ;
F_69 ( & V_109 -> V_32 , L_23 , V_138 ) ;
}
F_62 ( V_109 , NULL ) ;
}
static int F_70 ( struct V_108 * V_109 ,
const struct V_141 * V_142 )
{
struct V_111 * V_112 = F_57 ( V_109 ) ;
struct V_10 * V_10 , * * V_143 ;
int V_73 , V_36 = - V_86 ;
V_112 = F_57 ( V_109 ) ;
for ( V_143 = V_144 ; * V_143 ; V_143 ++ )
if ( ( * V_143 ) -> V_145 == V_112 -> V_132 . V_146 )
break;
V_10 = * V_143 ;
if ( ! V_10 ) {
F_71 ( L_24 ,
V_4 , V_112 -> V_132 . V_146 ) ;
return - V_54 ;
}
if ( V_10 -> V_147 ) {
V_36 = V_10 -> V_147 ( V_109 ) ;
if ( V_36 )
return V_36 ;
}
for ( V_73 = 0 ; V_73 < V_10 -> V_148 ; V_73 ++ ) {
V_36 = F_56 ( V_10 , V_109 , V_73 ) ;
if ( V_36 ) {
F_67 ( V_109 ) ;
break;
}
}
return V_36 ;
}
static int T_7 F_72 ( void )
{
int V_36 ;
V_36 = F_73 ( & V_149 ) ;
if ( V_36 )
F_71 ( L_25 ,
V_4 , V_36 ) ;
return V_36 ;
}
static int F_74 ( struct V_150 * V_151 , void * V_152 )
{
struct V_108 * V_109 = F_75 ( V_151 ) ;
struct V_31 * V_32 ;
for ( V_32 = F_61 ( V_109 ) ; V_32 ; V_32 = V_32 -> V_129 ) {
struct V_34 * V_35 = V_32 -> V_35 ;
if ( F_12 ( V_35 ) )
if ( V_32 -> V_11 -> V_153 )
V_32 -> V_11 -> V_153 ( V_32 ) ;
}
return 0 ;
}
static void T_8 F_76 ( void )
{
int V_36 ;
V_36 = F_77 ( & V_149 . V_154 . V_155 , NULL ,
NULL , F_74 ) ;
if ( V_36 )
F_71 ( L_26 ,
V_4 , V_36 ) ;
F_78 ( & V_149 ) ;
F_2 ( L_27 ,
V_4 ) ;
}
