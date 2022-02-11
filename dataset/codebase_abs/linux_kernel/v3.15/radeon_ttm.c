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
int V_11 ;
V_118 -> V_106 = ( unsigned long ) ( V_116 -> V_89 << V_90 ) ;
if ( ! V_98 -> V_94 ) {
F_52 ( 1 , L_8 ,
V_98 -> V_94 , V_116 , V_98 ) ;
}
V_11 = F_53 ( V_118 -> V_6 , V_118 -> V_106 ,
V_98 -> V_94 , V_98 -> V_119 , V_118 -> V_98 . V_120 ) ;
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
unsigned long V_16 , T_1 V_121 ,
struct V_122 * V_123 )
{
struct V_1 * V_6 ;
struct V_117 * V_118 ;
V_6 = F_1 ( V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_60 ( V_3 , V_6 -> V_44 -> V_45 -> V_124 ,
V_16 , V_121 , V_123 ) ;
}
#endif
V_118 = F_61 ( sizeof( struct V_117 ) , V_125 ) ;
if ( V_118 == NULL ) {
return NULL ;
}
V_118 -> V_98 . V_98 . V_36 = & V_126 ;
V_118 -> V_6 = V_6 ;
if ( F_62 ( & V_118 -> V_98 , V_3 , V_16 , V_121 , V_123 ) ) {
F_58 ( V_118 ) ;
return NULL ;
}
return & V_118 -> V_98 . V_98 ;
}
static int F_63 ( struct V_115 * V_98 )
{
struct V_1 * V_6 ;
struct V_117 * V_118 = ( void * ) V_98 ;
unsigned V_127 ;
int V_11 ;
bool V_128 = ! ! ( V_98 -> V_121 & V_129 ) ;
if ( V_98 -> V_130 != V_131 )
return 0 ;
if ( V_128 && V_98 -> V_132 ) {
F_64 ( V_98 -> V_132 , V_98 -> V_119 ,
V_118 -> V_98 . V_120 , V_98 -> V_94 ) ;
V_98 -> V_130 = V_133 ;
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
return F_68 ( & V_118 -> V_98 , V_6 -> V_134 ) ;
}
#endif
V_11 = F_69 ( V_98 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_127 = 0 ; V_127 < V_98 -> V_94 ; V_127 ++ ) {
V_118 -> V_98 . V_120 [ V_127 ] = F_70 ( V_6 -> V_135 , V_98 -> V_119 [ V_127 ] ,
0 , V_91 ,
V_136 ) ;
if ( F_71 ( V_6 -> V_135 , V_118 -> V_98 . V_120 [ V_127 ] ) ) {
while ( -- V_127 ) {
F_72 ( V_6 -> V_135 , V_118 -> V_98 . V_120 [ V_127 ] ,
V_91 , V_136 ) ;
V_118 -> V_98 . V_120 [ V_127 ] = 0 ;
}
F_73 ( V_98 ) ;
return - V_137 ;
}
}
return 0 ;
}
static void F_74 ( struct V_115 * V_98 )
{
struct V_1 * V_6 ;
struct V_117 * V_118 = ( void * ) V_98 ;
unsigned V_127 ;
bool V_128 = ! ! ( V_98 -> V_121 & V_129 ) ;
if ( V_128 )
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
F_76 ( & V_118 -> V_98 , V_6 -> V_134 ) ;
return;
}
#endif
for ( V_127 = 0 ; V_127 < V_98 -> V_94 ; V_127 ++ ) {
if ( V_118 -> V_98 . V_120 [ V_127 ] ) {
F_72 ( V_6 -> V_135 , V_118 -> V_98 . V_120 [ V_127 ] ,
V_91 , V_136 ) ;
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
& V_138 ,
V_6 -> V_44 -> V_139 -> V_140 ,
V_141 ,
V_6 -> V_142 ) ;
if ( V_11 ) {
F_9 ( L_10 , V_11 ) ;
return V_11 ;
}
V_6 -> V_5 . V_143 = true ;
V_11 = F_79 ( & V_6 -> V_5 . V_3 , V_50 ,
V_6 -> V_39 . V_144 >> V_90 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
F_80 ( V_6 , V_6 -> V_39 . V_110 ) ;
V_11 = F_81 ( V_6 , 256 * 1024 , V_91 , true ,
V_145 ,
NULL , & V_6 -> V_146 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_82 ( V_6 -> V_146 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_83 ( V_6 -> V_146 , V_145 , NULL ) ;
F_84 ( V_6 -> V_146 ) ;
if ( V_11 ) {
F_85 ( & V_6 -> V_146 ) ;
return V_11 ;
}
F_86 ( L_12 ,
( unsigned ) ( V_6 -> V_39 . V_144 / ( 1024 * 1024 ) ) ) ;
V_11 = F_79 ( & V_6 -> V_5 . V_3 , V_35 ,
V_6 -> V_39 . V_147 >> V_90 ) ;
if ( V_11 ) {
F_9 ( L_13 ) ;
return V_11 ;
}
F_86 ( L_14 ,
( unsigned ) ( V_6 -> V_39 . V_147 / ( 1024 * 1024 ) ) ) ;
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
if ( ! V_6 -> V_5 . V_143 )
return;
F_89 ( V_6 ) ;
if ( V_6 -> V_146 ) {
V_11 = F_82 ( V_6 -> V_146 , false ) ;
if ( V_11 == 0 ) {
F_90 ( V_6 -> V_146 ) ;
F_84 ( V_6 -> V_146 ) ;
}
F_85 ( & V_6 -> V_146 ) ;
}
F_91 ( & V_6 -> V_5 . V_3 , V_50 ) ;
F_91 ( & V_6 -> V_5 . V_3 , V_35 ) ;
F_92 ( & V_6 -> V_5 . V_3 ) ;
F_93 ( V_6 ) ;
F_11 ( V_6 ) ;
V_6 -> V_5 . V_143 = false ;
F_86 ( L_16 ) ;
}
void F_80 ( struct V_1 * V_6 , V_102 V_16 )
{
struct V_27 * V_28 ;
if ( ! V_6 -> V_5 . V_143 )
return;
V_28 = & V_6 -> V_5 . V_3 . V_28 [ V_50 ] ;
V_28 -> V_16 = V_16 >> V_90 ;
}
static int F_94 ( struct V_148 * V_149 , struct V_150 * V_151 )
{
struct V_53 * V_54 ;
struct V_1 * V_6 ;
int V_11 ;
V_54 = (struct V_53 * ) V_149 -> V_152 ;
if ( V_54 == NULL ) {
return V_153 ;
}
V_6 = F_1 ( V_54 -> V_3 ) ;
F_95 ( & V_6 -> V_154 . V_155 ) ;
V_11 = V_156 -> V_157 ( V_149 , V_151 ) ;
F_96 ( & V_6 -> V_154 . V_155 ) ;
return V_11 ;
}
int F_97 ( struct V_74 * V_75 , struct V_148 * V_149 )
{
struct V_158 * V_159 ;
struct V_1 * V_6 ;
int V_11 ;
if ( F_29 ( V_149 -> V_160 < V_141 ) ) {
return F_98 ( V_75 , V_149 ) ;
}
V_159 = V_75 -> V_161 ;
V_6 = V_159 -> V_162 -> V_134 -> V_163 ;
if ( V_6 == NULL ) {
return - V_46 ;
}
V_11 = F_99 ( V_75 , V_149 , & V_6 -> V_5 . V_3 ) ;
if ( F_29 ( V_11 != 0 ) ) {
return V_11 ;
}
if ( F_29 ( V_156 == NULL ) ) {
V_156 = V_149 -> V_164 ;
V_165 = * V_156 ;
V_165 . V_157 = & F_94 ;
}
V_149 -> V_164 = & V_165 ;
return 0 ;
}
static int F_100 ( struct V_166 * V_167 , void * V_168 )
{
struct V_169 * V_170 = (struct V_169 * ) V_167 -> V_171 ;
unsigned V_172 = * ( int * ) V_170 -> V_173 -> V_168 ;
struct V_174 * V_134 = V_170 -> V_162 -> V_134 ;
struct V_1 * V_6 = V_134 -> V_163 ;
struct V_175 * V_176 = (struct V_175 * ) V_6 -> V_5 . V_3 . V_28 [ V_172 ] . V_177 ;
int V_178 ;
struct V_23 * V_179 = V_6 -> V_5 . V_3 . V_179 ;
F_101 ( & V_179 -> V_180 ) ;
V_178 = F_102 ( V_167 , V_176 ) ;
F_103 ( & V_179 -> V_180 ) ;
return V_178 ;
}
static int F_104 ( struct V_181 * V_181 , struct V_74 * V_182 )
{
struct V_1 * V_6 = V_181 -> V_183 ;
F_105 ( V_181 , V_6 -> V_39 . V_184 ) ;
V_182 -> V_161 = V_181 -> V_183 ;
return 0 ;
}
static T_4 F_106 ( struct V_74 * V_185 , char T_5 * V_186 ,
T_6 V_16 , T_7 * V_187 )
{
struct V_1 * V_6 = V_185 -> V_161 ;
T_4 V_188 = 0 ;
int V_11 ;
if ( V_16 & 0x3 || * V_187 & 0x3 )
return - V_46 ;
while ( V_16 ) {
unsigned long V_26 ;
T_1 V_189 ;
if ( * V_187 >= V_6 -> V_39 . V_184 )
return V_188 ;
F_107 ( & V_6 -> V_190 , V_26 ) ;
F_108 ( V_191 , ( ( T_1 ) * V_187 ) | 0x80000000 ) ;
if ( V_6 -> V_192 >= V_193 )
F_108 ( V_194 , * V_187 >> 31 ) ;
V_189 = F_109 ( V_195 ) ;
F_110 ( & V_6 -> V_190 , V_26 ) ;
V_11 = F_111 ( V_189 , ( T_1 * ) V_186 ) ;
if ( V_11 )
return V_11 ;
V_188 += 4 ;
V_186 += 4 ;
* V_187 += 4 ;
V_16 -= 4 ;
}
return V_188 ;
}
static int F_112 ( struct V_181 * V_181 , struct V_74 * V_182 )
{
struct V_1 * V_6 = V_181 -> V_183 ;
F_105 ( V_181 , V_6 -> V_39 . V_147 ) ;
V_182 -> V_161 = V_181 -> V_183 ;
return 0 ;
}
static T_4 F_113 ( struct V_74 * V_185 , char T_5 * V_186 ,
T_6 V_16 , T_7 * V_187 )
{
struct V_1 * V_6 = V_185 -> V_161 ;
T_4 V_188 = 0 ;
int V_11 ;
while ( V_16 ) {
T_7 V_196 = * V_187 / V_91 ;
unsigned V_197 = * V_187 & ~ V_198 ;
T_6 V_199 = F_114 ( T_6 , V_16 , V_91 - V_197 ) ;
struct V_122 * V_122 ;
void * V_200 ;
if ( V_196 >= V_6 -> V_201 . V_202 )
return V_188 ;
V_122 = V_6 -> V_201 . V_119 [ V_196 ] ;
if ( V_122 ) {
V_200 = F_115 ( V_122 ) ;
V_200 += V_197 ;
V_11 = F_116 ( V_186 , V_200 , V_199 ) ;
F_117 ( V_6 -> V_201 . V_119 [ V_196 ] ) ;
} else
V_11 = F_118 ( V_186 , V_199 ) ;
if ( V_11 )
return - V_137 ;
V_188 += V_199 ;
V_186 += V_199 ;
* V_187 += V_199 ;
V_16 -= V_199 ;
}
return V_188 ;
}
static int F_87 ( struct V_1 * V_6 )
{
#if F_119 ( V_203 )
unsigned V_204 ;
struct V_205 * V_162 = V_6 -> V_44 -> V_206 ;
struct V_207 * V_208 , * V_209 = V_162 -> V_210 ;
V_208 = F_120 ( L_17 , V_211 | V_212 , V_209 ,
V_6 , & V_213 ) ;
if ( F_121 ( V_208 ) )
return F_122 ( V_208 ) ;
V_6 -> V_5 . V_214 = V_208 ;
V_208 = F_120 ( L_18 , V_211 | V_212 , V_209 ,
V_6 , & V_215 ) ;
if ( F_121 ( V_208 ) )
return F_122 ( V_208 ) ;
V_6 -> V_5 . V_118 = V_208 ;
V_204 = F_123 ( V_216 ) ;
#ifdef F_66
if ( ! F_67 () )
-- V_204 ;
#endif
return F_124 ( V_6 , V_216 , V_204 ) ;
#else
return 0 ;
#endif
}
static void F_89 ( struct V_1 * V_6 )
{
#if F_119 ( V_203 )
F_125 ( V_6 -> V_5 . V_214 ) ;
V_6 -> V_5 . V_214 = NULL ;
F_125 ( V_6 -> V_5 . V_118 ) ;
V_6 -> V_5 . V_118 = NULL ;
#endif
}
