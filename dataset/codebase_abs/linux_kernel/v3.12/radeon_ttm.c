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
if ( ! ( F_14 ( V_6 -> V_44 ) && V_6 -> V_44 -> V_45 ) ) {
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
static void F_15 ( struct V_53 * V_54 ,
struct V_55 * V_56 )
{
struct V_57 * V_58 ;
static T_2 V_59 = V_32 | V_60 ;
if ( ! F_16 ( V_54 ) ) {
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
F_17 ( V_58 , V_72 ) ;
else
F_17 ( V_58 , V_73 ) ;
break;
case V_35 :
default:
F_17 ( V_58 , V_72 ) ;
}
* V_56 = V_58 -> V_56 ;
}
static int F_18 ( struct V_53 * V_54 , struct V_74 * V_75 )
{
struct V_57 * V_58 = F_2 ( V_54 , struct V_57 , V_66 ) ;
return F_19 ( & V_58 -> V_76 . V_77 , V_75 ) ;
}
static void F_20 ( struct V_53 * V_54 ,
struct V_78 * V_79 )
{
struct V_78 * V_80 = & V_54 -> V_67 ;
F_21 ( V_80 -> V_81 != NULL ) ;
* V_80 = * V_79 ;
V_79 -> V_81 = NULL ;
}
static int F_22 ( struct V_53 * V_54 ,
bool V_82 , bool V_83 ,
struct V_78 * V_79 ,
struct V_78 * V_80 )
{
struct V_1 * V_6 ;
T_3 V_84 , V_85 ;
struct V_86 * V_87 ;
int V_11 , V_88 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_88 = F_23 ( V_6 ) ;
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
F_24 ( ( V_91 % V_92 ) != 0 ) ;
V_87 = V_54 -> V_93 ;
V_11 = F_25 ( V_6 , V_84 , V_85 ,
V_79 -> V_94 * ( V_91 / V_92 ) ,
& V_87 ) ;
V_11 = F_26 ( V_54 , ( void * ) V_87 ,
V_82 , V_83 , V_79 ) ;
F_27 ( & V_87 ) ;
return V_11 ;
}
static int F_28 ( struct V_53 * V_54 ,
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
V_11 = F_29 ( V_54 , & V_56 , & V_96 ,
V_95 , V_83 ) ;
if ( F_30 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_31 ( V_54 -> V_98 , V_96 . V_56 ) ;
if ( F_30 ( V_11 ) ) {
goto V_99;
}
V_11 = F_32 ( V_54 -> V_98 , & V_96 ) ;
if ( F_30 ( V_11 ) ) {
goto V_99;
}
V_11 = F_22 ( V_54 , true , V_83 , & V_96 , V_80 ) ;
if ( F_30 ( V_11 ) ) {
goto V_99;
}
V_11 = F_33 ( V_54 , true , V_83 , V_79 ) ;
V_99:
F_34 ( V_54 , & V_96 ) ;
return V_11 ;
}
static int F_35 ( struct V_53 * V_54 ,
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
V_11 = F_29 ( V_54 , & V_56 , & V_96 ,
V_95 , V_83 ) ;
if ( F_30 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_33 ( V_54 , true , V_83 , & V_96 ) ;
if ( F_30 ( V_11 ) ) {
goto V_99;
}
V_11 = F_22 ( V_54 , true , V_83 , V_79 , V_80 ) ;
if ( F_30 ( V_11 ) ) {
goto V_99;
}
V_99:
F_34 ( V_54 , & V_96 ) ;
return V_11 ;
}
static int F_36 ( struct V_53 * V_54 ,
bool V_82 , bool V_95 ,
bool V_83 ,
struct V_78 * V_79 )
{
struct V_1 * V_6 ;
struct V_78 * V_80 = & V_54 -> V_67 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
if ( V_80 -> V_68 == V_29 && V_54 -> V_98 == NULL ) {
F_20 ( V_54 , V_79 ) ;
return 0 ;
}
if ( ( V_80 -> V_68 == V_35 &&
V_79 -> V_68 == V_29 ) ||
( V_80 -> V_68 == V_29 &&
V_79 -> V_68 == V_35 ) ) {
F_20 ( V_54 , V_79 ) ;
return 0 ;
}
if ( ! V_6 -> V_69 [ F_23 ( V_6 ) ] . V_71 ||
V_6 -> V_100 -> V_101 . V_101 == NULL ) {
goto memcpy;
}
if ( V_80 -> V_68 == V_50 &&
V_79 -> V_68 == V_29 ) {
V_11 = F_28 ( V_54 , V_82 , V_95 ,
V_83 , V_79 ) ;
} else if ( V_80 -> V_68 == V_29 &&
V_79 -> V_68 == V_50 ) {
V_11 = F_35 ( V_54 , V_82 , V_95 ,
V_83 , V_79 ) ;
} else {
V_11 = F_22 ( V_54 , V_82 , V_83 , V_79 , V_80 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_37 ( V_54 , V_82 , V_83 , V_79 ) ;
}
return V_11 ;
}
static int F_38 ( struct V_2 * V_3 , struct V_78 * V_67 )
{
struct V_27 * V_28 = & V_3 -> V_28 [ V_67 -> V_68 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_67 -> V_102 . V_103 = NULL ;
V_67 -> V_102 . V_104 = 0 ;
V_67 -> V_102 . V_16 = V_67 -> V_94 << V_90 ;
V_67 -> V_102 . V_105 = 0 ;
V_67 -> V_102 . V_106 = false ;
if ( ! ( V_28 -> V_26 & V_30 ) )
return - V_46 ;
switch ( V_67 -> V_68 ) {
case V_29 :
return 0 ;
case V_35 :
#if V_42
if ( V_6 -> V_26 & V_43 ) {
V_67 -> V_102 . V_104 = V_67 -> V_89 << V_90 ;
V_67 -> V_102 . V_105 = V_6 -> V_39 . V_107 ;
V_67 -> V_102 . V_106 = ! V_6 -> V_44 -> V_45 -> V_47 ;
}
#endif
break;
case V_50 :
V_67 -> V_102 . V_104 = V_67 -> V_89 << V_90 ;
if ( ( V_67 -> V_102 . V_104 + V_67 -> V_102 . V_16 ) > V_6 -> V_39 . V_108 )
return - V_46 ;
V_67 -> V_102 . V_105 = V_6 -> V_39 . V_109 ;
V_67 -> V_102 . V_106 = true ;
#ifdef F_39
if ( V_67 -> V_56 & V_49 )
V_67 -> V_102 . V_103 =
F_40 ( V_67 -> V_102 . V_105 + V_67 -> V_102 . V_104 ,
V_67 -> V_102 . V_16 ) ;
else
V_67 -> V_102 . V_103 =
F_41 ( V_67 -> V_102 . V_105 + V_67 -> V_102 . V_104 ,
V_67 -> V_102 . V_16 ) ;
V_67 -> V_102 . V_105 = ( V_67 -> V_102 . V_105 & 0x0ffffffffUL ) +
V_6 -> V_44 -> V_110 -> V_111 ;
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
static int F_43 ( void * V_93 , bool V_112 , bool V_95 )
{
return F_44 ( (struct V_86 * ) V_93 , V_95 ) ;
}
static int F_45 ( void * V_93 )
{
return 0 ;
}
static void F_46 ( void * * V_93 )
{
F_27 ( (struct V_86 * * ) V_93 ) ;
}
static void * F_47 ( void * V_93 )
{
return F_48 ( (struct V_86 * ) V_93 ) ;
}
static bool F_49 ( void * V_93 )
{
return F_50 ( (struct V_86 * ) V_93 ) ;
}
static int F_51 ( struct V_113 * V_98 ,
struct V_78 * V_114 )
{
struct V_115 * V_116 = ( void * ) V_98 ;
int V_11 ;
V_116 -> V_104 = ( unsigned long ) ( V_114 -> V_89 << V_90 ) ;
if ( ! V_98 -> V_94 ) {
F_52 ( 1 , L_8 ,
V_98 -> V_94 , V_114 , V_98 ) ;
}
V_11 = F_53 ( V_116 -> V_6 , V_116 -> V_104 ,
V_98 -> V_94 , V_98 -> V_117 , V_116 -> V_98 . V_118 ) ;
if ( V_11 ) {
F_9 ( L_9 ,
V_98 -> V_94 , ( unsigned ) V_116 -> V_104 ) ;
return V_11 ;
}
return 0 ;
}
static int F_54 ( struct V_113 * V_98 )
{
struct V_115 * V_116 = ( void * ) V_98 ;
F_55 ( V_116 -> V_6 , V_116 -> V_104 , V_98 -> V_94 ) ;
return 0 ;
}
static void F_56 ( struct V_113 * V_98 )
{
struct V_115 * V_116 = ( void * ) V_98 ;
F_57 ( & V_116 -> V_98 ) ;
F_58 ( V_116 ) ;
}
static struct V_113 * F_59 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_119 ,
struct V_120 * V_121 )
{
struct V_1 * V_6 ;
struct V_115 * V_116 ;
V_6 = F_1 ( V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_60 ( V_3 , V_6 -> V_44 -> V_45 -> V_122 ,
V_16 , V_119 , V_121 ) ;
}
#endif
V_116 = F_61 ( sizeof( struct V_115 ) , V_123 ) ;
if ( V_116 == NULL ) {
return NULL ;
}
V_116 -> V_98 . V_98 . V_36 = & V_124 ;
V_116 -> V_6 = V_6 ;
if ( F_62 ( & V_116 -> V_98 , V_3 , V_16 , V_119 , V_121 ) ) {
F_58 ( V_116 ) ;
return NULL ;
}
return & V_116 -> V_98 . V_98 ;
}
static int F_63 ( struct V_113 * V_98 )
{
struct V_1 * V_6 ;
struct V_115 * V_116 = ( void * ) V_98 ;
unsigned V_125 ;
int V_11 ;
bool V_126 = ! ! ( V_98 -> V_119 & V_127 ) ;
if ( V_98 -> V_128 != V_129 )
return 0 ;
if ( V_126 && V_98 -> V_130 ) {
F_64 ( V_98 -> V_130 , V_98 -> V_117 ,
V_116 -> V_98 . V_118 , V_98 -> V_94 ) ;
V_98 -> V_128 = V_131 ;
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
return F_68 ( & V_116 -> V_98 , V_6 -> V_132 ) ;
}
#endif
V_11 = F_69 ( V_98 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_125 = 0 ; V_125 < V_98 -> V_94 ; V_125 ++ ) {
V_116 -> V_98 . V_118 [ V_125 ] = F_70 ( V_6 -> V_133 , V_98 -> V_117 [ V_125 ] ,
0 , V_91 ,
V_134 ) ;
if ( F_71 ( V_6 -> V_133 , V_116 -> V_98 . V_118 [ V_125 ] ) ) {
while ( -- V_125 ) {
F_72 ( V_6 -> V_133 , V_116 -> V_98 . V_118 [ V_125 ] ,
V_91 , V_134 ) ;
V_116 -> V_98 . V_118 [ V_125 ] = 0 ;
}
F_73 ( V_98 ) ;
return - V_135 ;
}
}
return 0 ;
}
static void F_74 ( struct V_113 * V_98 )
{
struct V_1 * V_6 ;
struct V_115 * V_116 = ( void * ) V_98 ;
unsigned V_125 ;
bool V_126 = ! ! ( V_98 -> V_119 & V_127 ) ;
if ( V_126 )
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
F_76 ( & V_116 -> V_98 , V_6 -> V_132 ) ;
return;
}
#endif
for ( V_125 = 0 ; V_125 < V_98 -> V_94 ; V_125 ++ ) {
if ( V_116 -> V_98 . V_118 [ V_125 ] ) {
F_72 ( V_6 -> V_133 , V_116 -> V_98 . V_118 [ V_125 ] ,
V_91 , V_134 ) ;
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
& V_136 , V_137 ,
V_6 -> V_138 ) ;
if ( V_11 ) {
F_9 ( L_10 , V_11 ) ;
return V_11 ;
}
V_6 -> V_5 . V_139 = true ;
V_11 = F_79 ( & V_6 -> V_5 . V_3 , V_50 ,
V_6 -> V_39 . V_140 >> V_90 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
V_11 = F_80 ( V_6 , 256 * 1024 , V_91 , true ,
V_141 ,
NULL , & V_6 -> V_142 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_81 ( V_6 -> V_142 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_82 ( V_6 -> V_142 , V_141 , NULL ) ;
F_83 ( V_6 -> V_142 ) ;
if ( V_11 ) {
F_84 ( & V_6 -> V_142 ) ;
return V_11 ;
}
F_85 ( L_12 ,
( unsigned ) ( V_6 -> V_39 . V_140 / ( 1024 * 1024 ) ) ) ;
V_11 = F_79 ( & V_6 -> V_5 . V_3 , V_35 ,
V_6 -> V_39 . V_143 >> V_90 ) ;
if ( V_11 ) {
F_9 ( L_13 ) ;
return V_11 ;
}
F_85 ( L_14 ,
( unsigned ) ( V_6 -> V_39 . V_143 / ( 1024 * 1024 ) ) ) ;
V_6 -> V_5 . V_3 . V_144 = V_6 -> V_44 -> V_144 ;
V_11 = F_86 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_15 ) ;
return V_11 ;
}
return 0 ;
}
void F_87 ( struct V_1 * V_6 )
{
int V_11 ;
if ( ! V_6 -> V_5 . V_139 )
return;
if ( V_6 -> V_142 ) {
V_11 = F_81 ( V_6 -> V_142 , false ) ;
if ( V_11 == 0 ) {
F_88 ( V_6 -> V_142 ) ;
F_83 ( V_6 -> V_142 ) ;
}
F_84 ( & V_6 -> V_142 ) ;
}
F_89 ( & V_6 -> V_5 . V_3 , V_50 ) ;
F_89 ( & V_6 -> V_5 . V_3 , V_35 ) ;
F_90 ( & V_6 -> V_5 . V_3 ) ;
F_91 ( V_6 ) ;
F_11 ( V_6 ) ;
V_6 -> V_5 . V_139 = false ;
F_85 ( L_16 ) ;
}
void F_92 ( struct V_1 * V_6 , T_4 V_16 )
{
struct V_27 * V_28 ;
if ( ! V_6 -> V_5 . V_139 )
return;
V_28 = & V_6 -> V_5 . V_3 . V_28 [ V_50 ] ;
V_28 -> V_16 = V_16 >> V_90 ;
}
static int F_93 ( struct V_145 * V_146 , struct V_147 * V_148 )
{
struct V_53 * V_54 ;
struct V_1 * V_6 ;
int V_11 ;
V_54 = (struct V_53 * ) V_146 -> V_149 ;
if ( V_54 == NULL ) {
return V_150 ;
}
V_6 = F_1 ( V_54 -> V_3 ) ;
F_94 ( & V_6 -> V_151 . V_152 ) ;
V_11 = V_153 -> V_154 ( V_146 , V_148 ) ;
F_95 ( & V_6 -> V_151 . V_152 ) ;
return V_11 ;
}
int F_96 ( struct V_74 * V_75 , struct V_145 * V_146 )
{
struct V_155 * V_156 ;
struct V_1 * V_6 ;
int V_11 ;
if ( F_30 ( V_146 -> V_157 < V_137 ) ) {
return F_97 ( V_75 , V_146 ) ;
}
V_156 = V_75 -> V_158 ;
V_6 = V_156 -> V_159 -> V_132 -> V_160 ;
if ( V_6 == NULL ) {
return - V_46 ;
}
V_11 = F_98 ( V_75 , V_146 , & V_6 -> V_5 . V_3 ) ;
if ( F_30 ( V_11 != 0 ) ) {
return V_11 ;
}
if ( F_30 ( V_153 == NULL ) ) {
V_153 = V_146 -> V_161 ;
V_162 = * V_153 ;
V_162 . V_154 = & F_93 ;
}
V_146 -> V_161 = & V_162 ;
return 0 ;
}
static int F_99 ( struct V_163 * V_164 , void * V_165 )
{
struct V_166 * V_167 = (struct V_166 * ) V_164 -> V_168 ;
struct V_169 * V_170 = (struct V_169 * ) V_167 -> V_171 -> V_165 ;
struct V_172 * V_132 = V_167 -> V_159 -> V_132 ;
struct V_1 * V_6 = V_132 -> V_160 ;
int V_173 ;
struct V_23 * V_174 = V_6 -> V_5 . V_3 . V_174 ;
F_100 ( & V_174 -> V_175 ) ;
V_173 = F_101 ( V_164 , V_170 ) ;
F_102 ( & V_174 -> V_175 ) ;
return V_173 ;
}
static int F_86 ( struct V_1 * V_6 )
{
#if F_103 ( V_176 )
static struct V_177 V_178 [ V_179 + 2 ] ;
static char V_180 [ V_179 + 2 ] [ 32 ] ;
unsigned V_125 ;
for ( V_125 = 0 ; V_125 < V_179 ; V_125 ++ ) {
if ( V_125 == 0 )
sprintf ( V_180 [ V_125 ] , L_17 ) ;
else
sprintf ( V_180 [ V_125 ] , L_18 ) ;
V_178 [ V_125 ] . V_181 = V_180 [ V_125 ] ;
V_178 [ V_125 ] . V_182 = & F_99 ;
V_178 [ V_125 ] . V_183 = 0 ;
if ( V_125 == 0 )
V_178 [ V_125 ] . V_165 = V_6 -> V_5 . V_3 . V_28 [ V_50 ] . V_184 ;
else
V_178 [ V_125 ] . V_165 = V_6 -> V_5 . V_3 . V_28 [ V_35 ] . V_184 ;
}
sprintf ( V_180 [ V_125 ] , L_19 ) ;
V_178 [ V_125 ] . V_181 = V_180 [ V_125 ] ;
V_178 [ V_125 ] . V_182 = & V_185 ;
V_178 [ V_125 ] . V_183 = 0 ;
V_178 [ V_125 ++ ] . V_165 = NULL ;
#ifdef F_66
if ( F_67 () ) {
sprintf ( V_180 [ V_125 ] , L_20 ) ;
V_178 [ V_125 ] . V_181 = V_180 [ V_125 ] ;
V_178 [ V_125 ] . V_182 = & V_186 ;
V_178 [ V_125 ] . V_183 = 0 ;
V_178 [ V_125 ++ ] . V_165 = NULL ;
}
#endif
return F_104 ( V_6 , V_178 , V_125 ) ;
#endif
return 0 ;
}
