static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
V_5 = F_2 ( V_3 , struct V_4 , V_3 ) ;
V_6 = F_2 ( V_5 , struct V_1 , V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
F_6 ( V_8 -> V_9 ) ;
}
static int F_7 ( struct V_1 * V_6 )
{
struct V_7 * V_10 ;
int V_11 ;
V_6 -> V_5 . V_12 = false ;
V_10 = & V_6 -> V_5 . V_13 ;
V_10 -> V_14 = V_15 ;
V_10 -> V_16 = sizeof( struct V_17 ) ;
V_10 -> V_18 = & F_3 ;
V_10 -> V_19 = & F_5 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_1
L_2 ) ;
return V_11 ;
}
V_6 -> V_5 . V_20 . V_21 =
V_6 -> V_5 . V_13 . V_9 ;
V_10 = & V_6 -> V_5 . V_20 . V_8 ;
V_10 -> V_14 = V_22 ;
V_10 -> V_16 = sizeof( struct V_23 ) ;
V_10 -> V_18 = & V_24 ;
V_10 -> V_19 = & V_25 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_3 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
return V_11 ;
}
V_6 -> V_5 . V_12 = true ;
return 0 ;
}
static void F_11 ( struct V_1 * V_6 )
{
if ( V_6 -> V_5 . V_12 ) {
F_10 ( & V_6 -> V_5 . V_20 . V_8 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
V_6 -> V_5 . V_12 = false ;
}
}
static int F_12 ( struct V_2 * V_3 , T_1 V_26 )
{
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , T_1 type ,
struct V_27 * V_28 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
switch ( type ) {
case V_29 :
V_28 -> V_26 = V_30 ;
V_28 -> V_31 = V_32 ;
V_28 -> V_33 = V_34 ;
break;
case V_35 :
V_28 -> V_36 = & V_37 ;
V_28 -> V_38 = V_6 -> V_39 . V_40 ;
V_28 -> V_31 = V_32 ;
V_28 -> V_33 = V_34 ;
V_28 -> V_26 = V_30 | V_41 ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
if ( ! V_6 -> V_44 -> V_45 ) {
F_9 ( L_4 ,
( unsigned ) type ) ;
return - V_46 ;
}
if ( ! V_6 -> V_44 -> V_45 -> V_47 )
V_28 -> V_26 = V_30 ;
V_28 -> V_31 = V_48 |
V_49 ;
V_28 -> V_33 = V_49 ;
}
#endif
break;
case V_50 :
V_28 -> V_36 = & V_37 ;
V_28 -> V_38 = V_6 -> V_39 . V_51 ;
V_28 -> V_26 = V_52 |
V_30 ;
V_28 -> V_31 = V_48 | V_49 ;
V_28 -> V_33 = V_49 ;
break;
default:
F_9 ( L_5 , ( unsigned ) type ) ;
return - V_46 ;
}
return 0 ;
}
static void F_14 ( struct V_53 * V_54 ,
struct V_55 * V_56 )
{
struct V_57 * V_58 ;
static T_2 V_59 = V_32 | V_60 ;
if ( ! F_15 ( V_54 ) ) {
V_56 -> V_61 = 0 ;
V_56 -> V_62 = 0 ;
V_56 -> V_56 = & V_59 ;
V_56 -> V_63 = & V_59 ;
V_56 -> V_64 = 1 ;
V_56 -> V_65 = 1 ;
return;
}
V_58 = F_2 ( V_54 , struct V_57 , V_66 ) ;
switch ( V_54 -> V_67 . V_68 ) {
case V_50 :
if ( V_58 -> V_6 -> V_69 [ V_70 ] . V_71 == false )
F_16 ( V_58 , V_72 ) ;
else
F_16 ( V_58 , V_73 ) ;
break;
case V_35 :
default:
F_16 ( V_58 , V_72 ) ;
}
* V_56 = V_58 -> V_56 ;
}
static int F_17 ( struct V_53 * V_54 , struct V_74 * V_75 )
{
struct V_57 * V_58 = F_2 ( V_54 , struct V_57 , V_66 ) ;
return F_18 ( & V_58 -> V_76 . V_77 , V_75 ) ;
}
static void F_19 ( struct V_53 * V_54 ,
struct V_78 * V_79 )
{
struct V_78 * V_80 = & V_54 -> V_67 ;
F_20 ( V_80 -> V_81 != NULL ) ;
* V_80 = * V_79 ;
V_79 -> V_81 = NULL ;
}
static int F_21 ( struct V_53 * V_54 ,
bool V_82 , bool V_83 ,
struct V_78 * V_79 ,
struct V_78 * V_80 )
{
struct V_1 * V_6 ;
T_3 V_84 , V_85 ;
struct V_86 * V_87 ;
int V_11 , V_88 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_88 = F_22 ( V_6 ) ;
V_84 = V_80 -> V_89 << V_90 ;
V_85 = V_79 -> V_89 << V_90 ;
switch ( V_80 -> V_68 ) {
case V_50 :
V_84 += V_6 -> V_39 . V_51 ;
break;
case V_35 :
V_84 += V_6 -> V_39 . V_40 ;
break;
default:
F_9 ( L_6 , V_80 -> V_68 ) ;
return - V_46 ;
}
switch ( V_79 -> V_68 ) {
case V_50 :
V_85 += V_6 -> V_39 . V_51 ;
break;
case V_35 :
V_85 += V_6 -> V_39 . V_40 ;
break;
default:
F_9 ( L_6 , V_80 -> V_68 ) ;
return - V_46 ;
}
if ( ! V_6 -> V_69 [ V_88 ] . V_71 ) {
F_9 ( L_7 ) ;
return - V_46 ;
}
F_23 ( ( V_91 % V_92 ) != 0 ) ;
V_87 = V_54 -> V_93 ;
V_11 = F_24 ( V_6 , V_84 , V_85 ,
V_79 -> V_94 * ( V_91 / V_92 ) ,
& V_87 ) ;
V_11 = F_25 ( V_54 , ( void * ) V_87 ,
V_82 , V_83 , V_79 ) ;
F_26 ( & V_87 ) ;
return V_11 ;
}
static int F_27 ( struct V_53 * V_54 ,
bool V_82 , bool V_95 ,
bool V_83 ,
struct V_78 * V_79 )
{
struct V_1 * V_6 ;
struct V_78 * V_80 = & V_54 -> V_67 ;
struct V_78 V_96 ;
T_2 V_59 ;
struct V_55 V_56 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_96 = * V_79 ;
V_96 . V_81 = NULL ;
V_56 . V_61 = 0 ;
V_56 . V_62 = 0 ;
V_56 . V_64 = 1 ;
V_56 . V_56 = & V_59 ;
V_56 . V_65 = 1 ;
V_56 . V_63 = & V_59 ;
V_59 = V_32 | V_97 ;
V_11 = F_28 ( V_54 , & V_56 , & V_96 ,
V_95 , V_83 ) ;
if ( F_29 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_30 ( V_54 -> V_98 , V_96 . V_56 ) ;
if ( F_29 ( V_11 ) ) {
goto V_99;
}
V_11 = F_31 ( V_54 -> V_98 , & V_96 ) ;
if ( F_29 ( V_11 ) ) {
goto V_99;
}
V_11 = F_21 ( V_54 , true , V_83 , & V_96 , V_80 ) ;
if ( F_29 ( V_11 ) ) {
goto V_99;
}
V_11 = F_32 ( V_54 , true , V_83 , V_79 ) ;
V_99:
F_33 ( V_54 , & V_96 ) ;
return V_11 ;
}
static int F_34 ( struct V_53 * V_54 ,
bool V_82 , bool V_95 ,
bool V_83 ,
struct V_78 * V_79 )
{
struct V_1 * V_6 ;
struct V_78 * V_80 = & V_54 -> V_67 ;
struct V_78 V_96 ;
struct V_55 V_56 ;
T_2 V_59 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_96 = * V_79 ;
V_96 . V_81 = NULL ;
V_56 . V_61 = 0 ;
V_56 . V_62 = 0 ;
V_56 . V_64 = 1 ;
V_56 . V_56 = & V_59 ;
V_56 . V_65 = 1 ;
V_56 . V_63 = & V_59 ;
V_59 = V_32 | V_97 ;
V_11 = F_28 ( V_54 , & V_56 , & V_96 ,
V_95 , V_83 ) ;
if ( F_29 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_32 ( V_54 , true , V_83 , & V_96 ) ;
if ( F_29 ( V_11 ) ) {
goto V_99;
}
V_11 = F_21 ( V_54 , true , V_83 , V_79 , V_80 ) ;
if ( F_29 ( V_11 ) ) {
goto V_99;
}
V_99:
F_33 ( V_54 , & V_96 ) ;
return V_11 ;
}
static int F_35 ( struct V_53 * V_54 ,
bool V_82 , bool V_95 ,
bool V_83 ,
struct V_78 * V_79 )
{
struct V_1 * V_6 ;
struct V_78 * V_80 = & V_54 -> V_67 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
if ( V_80 -> V_68 == V_29 && V_54 -> V_98 == NULL ) {
F_19 ( V_54 , V_79 ) ;
return 0 ;
}
if ( ( V_80 -> V_68 == V_35 &&
V_79 -> V_68 == V_29 ) ||
( V_80 -> V_68 == V_29 &&
V_79 -> V_68 == V_35 ) ) {
F_19 ( V_54 , V_79 ) ;
return 0 ;
}
if ( ! V_6 -> V_69 [ F_22 ( V_6 ) ] . V_71 ||
V_6 -> V_100 -> V_101 . V_101 == NULL ) {
goto memcpy;
}
if ( V_80 -> V_68 == V_50 &&
V_79 -> V_68 == V_29 ) {
V_11 = F_27 ( V_54 , V_82 , V_95 ,
V_83 , V_79 ) ;
} else if ( V_80 -> V_68 == V_29 &&
V_79 -> V_68 == V_50 ) {
V_11 = F_34 ( V_54 , V_82 , V_95 ,
V_83 , V_79 ) ;
} else {
V_11 = F_21 ( V_54 , V_82 , V_83 , V_79 , V_80 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_36 ( V_54 , V_82 , V_83 , V_79 ) ;
if ( V_11 ) {
return V_11 ;
}
}
F_37 ( ( V_102 ) V_54 -> V_94 << V_90 , & V_6 -> V_103 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , struct V_78 * V_67 )
{
struct V_27 * V_28 = & V_3 -> V_28 [ V_67 -> V_68 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_67 -> V_104 . V_105 = NULL ;
V_67 -> V_104 . V_106 = 0 ;
V_67 -> V_104 . V_16 = V_67 -> V_94 << V_90 ;
V_67 -> V_104 . V_107 = 0 ;
V_67 -> V_104 . V_108 = false ;
if ( ! ( V_28 -> V_26 & V_30 ) )
return - V_46 ;
switch ( V_67 -> V_68 ) {
case V_29 :
return 0 ;
case V_35 :
#if V_42
if ( V_6 -> V_26 & V_43 ) {
V_67 -> V_104 . V_106 = V_67 -> V_89 << V_90 ;
V_67 -> V_104 . V_107 = V_6 -> V_39 . V_109 ;
V_67 -> V_104 . V_108 = ! V_6 -> V_44 -> V_45 -> V_47 ;
}
#endif
break;
case V_50 :
V_67 -> V_104 . V_106 = V_67 -> V_89 << V_90 ;
if ( ( V_67 -> V_104 . V_106 + V_67 -> V_104 . V_16 ) > V_6 -> V_39 . V_110 )
return - V_46 ;
V_67 -> V_104 . V_107 = V_6 -> V_39 . V_111 ;
V_67 -> V_104 . V_108 = true ;
#ifdef F_39
if ( V_67 -> V_56 & V_49 )
V_67 -> V_104 . V_105 =
F_40 ( V_67 -> V_104 . V_107 + V_67 -> V_104 . V_106 ,
V_67 -> V_104 . V_16 ) ;
else
V_67 -> V_104 . V_105 =
F_41 ( V_67 -> V_104 . V_107 + V_67 -> V_104 . V_106 ,
V_67 -> V_104 . V_16 ) ;
V_67 -> V_104 . V_107 = ( V_67 -> V_104 . V_107 & 0x0ffffffffUL ) +
V_6 -> V_44 -> V_112 -> V_113 ;
#endif
break;
default:
return - V_46 ;
}
return 0 ;
}
static void F_42 ( struct V_2 * V_3 , struct V_78 * V_67 )
{
}
static int F_43 ( void * V_93 , bool V_114 , bool V_95 )
{
return F_44 ( (struct V_86 * ) V_93 , V_95 ) ;
}
static int F_45 ( void * V_93 )
{
return 0 ;
}
static void F_46 ( void * * V_93 )
{
F_26 ( (struct V_86 * * ) V_93 ) ;
}
static void * F_47 ( void * V_93 )
{
return F_48 ( (struct V_86 * ) V_93 ) ;
}
static bool F_49 ( void * V_93 )
{
return F_50 ( (struct V_86 * ) V_93 ) ;
}
static int F_51 ( struct V_115 * V_98 ,
struct V_78 * V_116 )
{
struct V_117 * V_118 = ( void * ) V_98 ;
T_1 V_26 = V_119 | V_120 |
V_121 ;
int V_11 ;
V_118 -> V_106 = ( unsigned long ) ( V_116 -> V_89 << V_90 ) ;
if ( ! V_98 -> V_94 ) {
F_52 ( 1 , L_8 ,
V_98 -> V_94 , V_116 , V_98 ) ;
}
if ( V_98 -> V_122 == V_123 )
V_26 |= V_124 ;
V_11 = F_53 ( V_118 -> V_6 , V_118 -> V_106 , V_98 -> V_94 ,
V_98 -> V_125 , V_118 -> V_98 . V_126 , V_26 ) ;
if ( V_11 ) {
F_9 ( L_9 ,
V_98 -> V_94 , ( unsigned ) V_118 -> V_106 ) ;
return V_11 ;
}
return 0 ;
}
static int F_54 ( struct V_115 * V_98 )
{
struct V_117 * V_118 = ( void * ) V_98 ;
F_55 ( V_118 -> V_6 , V_118 -> V_106 , V_98 -> V_94 ) ;
return 0 ;
}
static void F_56 ( struct V_115 * V_98 )
{
struct V_117 * V_118 = ( void * ) V_98 ;
F_57 ( & V_118 -> V_98 ) ;
F_58 ( V_118 ) ;
}
static struct V_115 * F_59 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_127 ,
struct V_128 * V_129 )
{
struct V_1 * V_6 ;
struct V_117 * V_118 ;
V_6 = F_1 ( V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_60 ( V_3 , V_6 -> V_44 -> V_45 -> V_130 ,
V_16 , V_127 , V_129 ) ;
}
#endif
V_118 = F_61 ( sizeof( struct V_117 ) , V_131 ) ;
if ( V_118 == NULL ) {
return NULL ;
}
V_118 -> V_98 . V_98 . V_36 = & V_132 ;
V_118 -> V_6 = V_6 ;
if ( F_62 ( & V_118 -> V_98 , V_3 , V_16 , V_127 , V_129 ) ) {
F_58 ( V_118 ) ;
return NULL ;
}
return & V_118 -> V_98 . V_98 ;
}
static int F_63 ( struct V_115 * V_98 )
{
struct V_1 * V_6 ;
struct V_117 * V_118 = ( void * ) V_98 ;
unsigned V_133 ;
int V_11 ;
bool V_134 = ! ! ( V_98 -> V_127 & V_135 ) ;
if ( V_98 -> V_136 != V_137 )
return 0 ;
if ( V_134 && V_98 -> V_138 ) {
F_64 ( V_98 -> V_138 , V_98 -> V_125 ,
V_118 -> V_98 . V_126 , V_98 -> V_94 ) ;
V_98 -> V_136 = V_139 ;
return 0 ;
}
V_6 = F_1 ( V_98 -> V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_65 ( V_98 ) ;
}
#endif
#ifdef F_66
if ( F_67 () ) {
return F_68 ( & V_118 -> V_98 , V_6 -> V_140 ) ;
}
#endif
V_11 = F_69 ( V_98 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_133 = 0 ; V_133 < V_98 -> V_94 ; V_133 ++ ) {
V_118 -> V_98 . V_126 [ V_133 ] = F_70 ( V_6 -> V_141 , V_98 -> V_125 [ V_133 ] ,
0 , V_91 ,
V_142 ) ;
if ( F_71 ( V_6 -> V_141 , V_118 -> V_98 . V_126 [ V_133 ] ) ) {
while ( -- V_133 ) {
F_72 ( V_6 -> V_141 , V_118 -> V_98 . V_126 [ V_133 ] ,
V_91 , V_142 ) ;
V_118 -> V_98 . V_126 [ V_133 ] = 0 ;
}
F_73 ( V_98 ) ;
return - V_143 ;
}
}
return 0 ;
}
static void F_74 ( struct V_115 * V_98 )
{
struct V_1 * V_6 ;
struct V_117 * V_118 = ( void * ) V_98 ;
unsigned V_133 ;
bool V_134 = ! ! ( V_98 -> V_127 & V_135 ) ;
if ( V_134 )
return;
V_6 = F_1 ( V_98 -> V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
F_75 ( V_98 ) ;
return;
}
#endif
#ifdef F_66
if ( F_67 () ) {
F_76 ( & V_118 -> V_98 , V_6 -> V_140 ) ;
return;
}
#endif
for ( V_133 = 0 ; V_133 < V_98 -> V_94 ; V_133 ++ ) {
if ( V_118 -> V_98 . V_126 [ V_133 ] ) {
F_72 ( V_6 -> V_141 , V_118 -> V_98 . V_126 [ V_133 ] ,
V_91 , V_142 ) ;
}
}
F_73 ( V_98 ) ;
}
int F_77 ( struct V_1 * V_6 )
{
int V_11 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_78 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_144 ,
V_6 -> V_44 -> V_145 -> V_146 ,
V_147 ,
V_6 -> V_148 ) ;
if ( V_11 ) {
F_9 ( L_10 , V_11 ) ;
return V_11 ;
}
V_6 -> V_5 . V_149 = true ;
V_11 = F_79 ( & V_6 -> V_5 . V_3 , V_50 ,
V_6 -> V_39 . V_150 >> V_90 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
F_80 ( V_6 , V_6 -> V_39 . V_110 ) ;
V_11 = F_81 ( V_6 , 256 * 1024 , V_91 , true ,
V_151 , 0 ,
NULL , & V_6 -> V_152 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_82 ( V_6 -> V_152 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_83 ( V_6 -> V_152 , V_151 , NULL ) ;
F_84 ( V_6 -> V_152 ) ;
if ( V_11 ) {
F_85 ( & V_6 -> V_152 ) ;
return V_11 ;
}
F_86 ( L_12 ,
( unsigned ) ( V_6 -> V_39 . V_150 / ( 1024 * 1024 ) ) ) ;
V_11 = F_79 ( & V_6 -> V_5 . V_3 , V_35 ,
V_6 -> V_39 . V_153 >> V_90 ) ;
if ( V_11 ) {
F_9 ( L_13 ) ;
return V_11 ;
}
F_86 ( L_14 ,
( unsigned ) ( V_6 -> V_39 . V_153 / ( 1024 * 1024 ) ) ) ;
V_11 = F_87 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_15 ) ;
return V_11 ;
}
return 0 ;
}
void F_88 ( struct V_1 * V_6 )
{
int V_11 ;
if ( ! V_6 -> V_5 . V_149 )
return;
F_89 ( V_6 ) ;
if ( V_6 -> V_152 ) {
V_11 = F_82 ( V_6 -> V_152 , false ) ;
if ( V_11 == 0 ) {
F_90 ( V_6 -> V_152 ) ;
F_84 ( V_6 -> V_152 ) ;
}
F_85 ( & V_6 -> V_152 ) ;
}
F_91 ( & V_6 -> V_5 . V_3 , V_50 ) ;
F_91 ( & V_6 -> V_5 . V_3 , V_35 ) ;
F_92 ( & V_6 -> V_5 . V_3 ) ;
F_93 ( V_6 ) ;
F_11 ( V_6 ) ;
V_6 -> V_5 . V_149 = false ;
F_86 ( L_16 ) ;
}
void F_80 ( struct V_1 * V_6 , V_102 V_16 )
{
struct V_27 * V_28 ;
if ( ! V_6 -> V_5 . V_149 )
return;
V_28 = & V_6 -> V_5 . V_3 . V_28 [ V_50 ] ;
V_28 -> V_16 = V_16 >> V_90 ;
}
static int F_94 ( struct V_154 * V_155 , struct V_156 * V_157 )
{
struct V_53 * V_54 ;
struct V_1 * V_6 ;
int V_11 ;
V_54 = (struct V_53 * ) V_155 -> V_158 ;
if ( V_54 == NULL ) {
return V_159 ;
}
V_6 = F_1 ( V_54 -> V_3 ) ;
F_95 ( & V_6 -> V_160 . V_161 ) ;
V_11 = V_162 -> V_163 ( V_155 , V_157 ) ;
F_96 ( & V_6 -> V_160 . V_161 ) ;
return V_11 ;
}
int F_97 ( struct V_74 * V_75 , struct V_154 * V_155 )
{
struct V_164 * V_165 ;
struct V_1 * V_6 ;
int V_11 ;
if ( F_29 ( V_155 -> V_166 < V_147 ) ) {
return F_98 ( V_75 , V_155 ) ;
}
V_165 = V_75 -> V_167 ;
V_6 = V_165 -> V_168 -> V_140 -> V_169 ;
if ( V_6 == NULL ) {
return - V_46 ;
}
V_11 = F_99 ( V_75 , V_155 , & V_6 -> V_5 . V_3 ) ;
if ( F_29 ( V_11 != 0 ) ) {
return V_11 ;
}
if ( F_29 ( V_162 == NULL ) ) {
V_162 = V_155 -> V_170 ;
V_171 = * V_162 ;
V_171 . V_163 = & F_94 ;
}
V_155 -> V_170 = & V_171 ;
return 0 ;
}
static int F_100 ( struct V_172 * V_173 , void * V_174 )
{
struct V_175 * V_176 = (struct V_175 * ) V_173 -> V_177 ;
unsigned V_178 = * ( int * ) V_176 -> V_179 -> V_174 ;
struct V_180 * V_140 = V_176 -> V_168 -> V_140 ;
struct V_1 * V_6 = V_140 -> V_169 ;
struct V_181 * V_182 = (struct V_181 * ) V_6 -> V_5 . V_3 . V_28 [ V_178 ] . V_183 ;
int V_184 ;
struct V_23 * V_185 = V_6 -> V_5 . V_3 . V_185 ;
F_101 ( & V_185 -> V_186 ) ;
V_184 = F_102 ( V_173 , V_182 ) ;
F_103 ( & V_185 -> V_186 ) ;
return V_184 ;
}
static int F_104 ( struct V_187 * V_187 , struct V_74 * V_188 )
{
struct V_1 * V_6 = V_187 -> V_189 ;
F_105 ( V_187 , V_6 -> V_39 . V_190 ) ;
V_188 -> V_167 = V_187 -> V_189 ;
return 0 ;
}
static T_4 F_106 ( struct V_74 * V_191 , char T_5 * V_192 ,
T_6 V_16 , T_7 * V_193 )
{
struct V_1 * V_6 = V_191 -> V_167 ;
T_4 V_194 = 0 ;
int V_11 ;
if ( V_16 & 0x3 || * V_193 & 0x3 )
return - V_46 ;
while ( V_16 ) {
unsigned long V_26 ;
T_1 V_195 ;
if ( * V_193 >= V_6 -> V_39 . V_190 )
return V_194 ;
F_107 ( & V_6 -> V_196 , V_26 ) ;
F_108 ( V_197 , ( ( T_1 ) * V_193 ) | 0x80000000 ) ;
if ( V_6 -> V_198 >= V_199 )
F_108 ( V_200 , * V_193 >> 31 ) ;
V_195 = F_109 ( V_201 ) ;
F_110 ( & V_6 -> V_196 , V_26 ) ;
V_11 = F_111 ( V_195 , ( T_1 * ) V_192 ) ;
if ( V_11 )
return V_11 ;
V_194 += 4 ;
V_192 += 4 ;
* V_193 += 4 ;
V_16 -= 4 ;
}
return V_194 ;
}
static int F_112 ( struct V_187 * V_187 , struct V_74 * V_188 )
{
struct V_1 * V_6 = V_187 -> V_189 ;
F_105 ( V_187 , V_6 -> V_39 . V_153 ) ;
V_188 -> V_167 = V_187 -> V_189 ;
return 0 ;
}
static T_4 F_113 ( struct V_74 * V_191 , char T_5 * V_192 ,
T_6 V_16 , T_7 * V_193 )
{
struct V_1 * V_6 = V_191 -> V_167 ;
T_4 V_194 = 0 ;
int V_11 ;
while ( V_16 ) {
T_7 V_202 = * V_193 / V_91 ;
unsigned V_203 = * V_193 & ~ V_204 ;
T_6 V_205 = F_114 ( T_6 , V_16 , V_91 - V_203 ) ;
struct V_128 * V_128 ;
void * V_206 ;
if ( V_202 >= V_6 -> V_207 . V_208 )
return V_194 ;
V_128 = V_6 -> V_207 . V_125 [ V_202 ] ;
if ( V_128 ) {
V_206 = F_115 ( V_128 ) ;
V_206 += V_203 ;
V_11 = F_116 ( V_192 , V_206 , V_205 ) ;
F_117 ( V_6 -> V_207 . V_125 [ V_202 ] ) ;
} else
V_11 = F_118 ( V_192 , V_205 ) ;
if ( V_11 )
return - V_143 ;
V_194 += V_205 ;
V_192 += V_205 ;
* V_193 += V_205 ;
V_16 -= V_205 ;
}
return V_194 ;
}
static int F_87 ( struct V_1 * V_6 )
{
#if F_119 ( V_209 )
unsigned V_210 ;
struct V_211 * V_168 = V_6 -> V_44 -> V_212 ;
struct V_213 * V_214 , * V_215 = V_168 -> V_216 ;
V_214 = F_120 ( L_17 , V_217 | V_218 , V_215 ,
V_6 , & V_219 ) ;
if ( F_121 ( V_214 ) )
return F_122 ( V_214 ) ;
V_6 -> V_5 . V_220 = V_214 ;
V_214 = F_120 ( L_18 , V_217 | V_218 , V_215 ,
V_6 , & V_221 ) ;
if ( F_121 ( V_214 ) )
return F_122 ( V_214 ) ;
V_6 -> V_5 . V_118 = V_214 ;
V_210 = F_123 ( V_222 ) ;
#ifdef F_66
if ( ! F_67 () )
-- V_210 ;
#endif
return F_124 ( V_6 , V_222 , V_210 ) ;
#else
return 0 ;
#endif
}
static void F_89 ( struct V_1 * V_6 )
{
#if F_119 ( V_209 )
F_125 ( V_6 -> V_5 . V_220 ) ;
V_6 -> V_5 . V_220 = NULL ;
F_125 ( V_6 -> V_5 . V_118 ) ;
V_6 -> V_5 . V_118 = NULL ;
#endif
}
