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
return 0 ;
}
static void F_19 ( struct V_53 * V_54 ,
struct V_76 * V_77 )
{
struct V_76 * V_78 = & V_54 -> V_67 ;
F_20 ( V_78 -> V_79 != NULL ) ;
* V_78 = * V_77 ;
V_77 -> V_79 = NULL ;
}
static int F_21 ( struct V_53 * V_54 ,
bool V_80 , bool V_81 ,
struct V_76 * V_77 ,
struct V_76 * V_78 )
{
struct V_1 * V_6 ;
T_3 V_82 , V_83 ;
struct V_84 * V_85 ;
int V_11 , V_86 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_86 = F_22 ( V_6 ) ;
V_82 = V_78 -> V_87 << V_88 ;
V_83 = V_77 -> V_87 << V_88 ;
switch ( V_78 -> V_68 ) {
case V_50 :
V_82 += V_6 -> V_39 . V_51 ;
break;
case V_35 :
V_82 += V_6 -> V_39 . V_40 ;
break;
default:
F_9 ( L_6 , V_78 -> V_68 ) ;
return - V_46 ;
}
switch ( V_77 -> V_68 ) {
case V_50 :
V_83 += V_6 -> V_39 . V_51 ;
break;
case V_35 :
V_83 += V_6 -> V_39 . V_40 ;
break;
default:
F_9 ( L_6 , V_78 -> V_68 ) ;
return - V_46 ;
}
if ( ! V_6 -> V_69 [ V_86 ] . V_71 ) {
F_9 ( L_7 ) ;
return - V_46 ;
}
F_23 ( ( V_89 % V_90 ) != 0 ) ;
V_85 = V_54 -> V_91 ;
V_11 = F_24 ( V_6 , V_82 , V_83 ,
V_77 -> V_92 * ( V_89 / V_90 ) ,
& V_85 ) ;
V_11 = F_25 ( V_54 , ( void * ) V_85 ,
V_80 , V_81 , V_77 ) ;
F_26 ( & V_85 ) ;
return V_11 ;
}
static int F_27 ( struct V_53 * V_54 ,
bool V_80 , bool V_93 ,
bool V_81 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_54 -> V_67 ;
struct V_76 V_94 ;
T_2 V_59 ;
struct V_55 V_56 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_94 = * V_77 ;
V_94 . V_79 = NULL ;
V_56 . V_61 = 0 ;
V_56 . V_62 = 0 ;
V_56 . V_64 = 1 ;
V_56 . V_56 = & V_59 ;
V_56 . V_65 = 1 ;
V_56 . V_63 = & V_59 ;
V_59 = V_32 | V_95 ;
V_11 = F_28 ( V_54 , & V_56 , & V_94 ,
V_93 , V_81 ) ;
if ( F_29 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_30 ( V_54 -> V_96 , V_94 . V_56 ) ;
if ( F_29 ( V_11 ) ) {
goto V_97;
}
V_11 = F_31 ( V_54 -> V_96 , & V_94 ) ;
if ( F_29 ( V_11 ) ) {
goto V_97;
}
V_11 = F_21 ( V_54 , true , V_81 , & V_94 , V_78 ) ;
if ( F_29 ( V_11 ) ) {
goto V_97;
}
V_11 = F_32 ( V_54 , true , V_81 , V_77 ) ;
V_97:
F_33 ( V_54 , & V_94 ) ;
return V_11 ;
}
static int F_34 ( struct V_53 * V_54 ,
bool V_80 , bool V_93 ,
bool V_81 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_54 -> V_67 ;
struct V_76 V_94 ;
struct V_55 V_56 ;
T_2 V_59 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_94 = * V_77 ;
V_94 . V_79 = NULL ;
V_56 . V_61 = 0 ;
V_56 . V_62 = 0 ;
V_56 . V_64 = 1 ;
V_56 . V_56 = & V_59 ;
V_56 . V_65 = 1 ;
V_56 . V_63 = & V_59 ;
V_59 = V_32 | V_95 ;
V_11 = F_28 ( V_54 , & V_56 , & V_94 ,
V_93 , V_81 ) ;
if ( F_29 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_32 ( V_54 , true , V_81 , & V_94 ) ;
if ( F_29 ( V_11 ) ) {
goto V_97;
}
V_11 = F_21 ( V_54 , true , V_81 , V_77 , V_78 ) ;
if ( F_29 ( V_11 ) ) {
goto V_97;
}
V_97:
F_33 ( V_54 , & V_94 ) ;
return V_11 ;
}
static int F_35 ( struct V_53 * V_54 ,
bool V_80 , bool V_93 ,
bool V_81 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_54 -> V_67 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
if ( V_78 -> V_68 == V_29 && V_54 -> V_96 == NULL ) {
F_19 ( V_54 , V_77 ) ;
return 0 ;
}
if ( ( V_78 -> V_68 == V_35 &&
V_77 -> V_68 == V_29 ) ||
( V_78 -> V_68 == V_29 &&
V_77 -> V_68 == V_35 ) ) {
F_19 ( V_54 , V_77 ) ;
return 0 ;
}
if ( ! V_6 -> V_69 [ F_22 ( V_6 ) ] . V_71 ||
V_6 -> V_98 -> V_99 . V_99 == NULL ) {
goto memcpy;
}
if ( V_78 -> V_68 == V_50 &&
V_77 -> V_68 == V_29 ) {
V_11 = F_27 ( V_54 , V_80 , V_93 ,
V_81 , V_77 ) ;
} else if ( V_78 -> V_68 == V_29 &&
V_77 -> V_68 == V_50 ) {
V_11 = F_34 ( V_54 , V_80 , V_93 ,
V_81 , V_77 ) ;
} else {
V_11 = F_21 ( V_54 , V_80 , V_81 , V_77 , V_78 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_36 ( V_54 , V_80 , V_81 , V_77 ) ;
}
return V_11 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_76 * V_67 )
{
struct V_27 * V_28 = & V_3 -> V_28 [ V_67 -> V_68 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_67 -> V_100 . V_101 = NULL ;
V_67 -> V_100 . V_102 = 0 ;
V_67 -> V_100 . V_16 = V_67 -> V_92 << V_88 ;
V_67 -> V_100 . V_103 = 0 ;
V_67 -> V_100 . V_104 = false ;
if ( ! ( V_28 -> V_26 & V_30 ) )
return - V_46 ;
switch ( V_67 -> V_68 ) {
case V_29 :
return 0 ;
case V_35 :
#if V_42
if ( V_6 -> V_26 & V_43 ) {
V_67 -> V_100 . V_102 = V_67 -> V_87 << V_88 ;
V_67 -> V_100 . V_103 = V_6 -> V_39 . V_105 ;
V_67 -> V_100 . V_104 = ! V_6 -> V_44 -> V_45 -> V_47 ;
}
#endif
break;
case V_50 :
V_67 -> V_100 . V_102 = V_67 -> V_87 << V_88 ;
if ( ( V_67 -> V_100 . V_102 + V_67 -> V_100 . V_16 ) > V_6 -> V_39 . V_106 )
return - V_46 ;
V_67 -> V_100 . V_103 = V_6 -> V_39 . V_107 ;
V_67 -> V_100 . V_104 = true ;
#ifdef F_38
if ( V_67 -> V_56 & V_49 )
V_67 -> V_100 . V_101 =
F_39 ( V_67 -> V_100 . V_103 + V_67 -> V_100 . V_102 ,
V_67 -> V_100 . V_16 ) ;
else
V_67 -> V_100 . V_101 =
F_40 ( V_67 -> V_100 . V_103 + V_67 -> V_100 . V_102 ,
V_67 -> V_100 . V_16 ) ;
V_67 -> V_100 . V_103 = ( V_67 -> V_100 . V_103 & 0x0ffffffffUL ) +
V_6 -> V_44 -> V_108 -> V_109 ;
#endif
break;
default:
return - V_46 ;
}
return 0 ;
}
static void F_41 ( struct V_2 * V_3 , struct V_76 * V_67 )
{
}
static int F_42 ( void * V_91 , bool V_110 , bool V_93 )
{
return F_43 ( (struct V_84 * ) V_91 , V_93 ) ;
}
static int F_44 ( void * V_91 )
{
return 0 ;
}
static void F_45 ( void * * V_91 )
{
F_26 ( (struct V_84 * * ) V_91 ) ;
}
static void * F_46 ( void * V_91 )
{
return F_47 ( (struct V_84 * ) V_91 ) ;
}
static bool F_48 ( void * V_91 )
{
return F_49 ( (struct V_84 * ) V_91 ) ;
}
static int F_50 ( struct V_111 * V_96 ,
struct V_76 * V_112 )
{
struct V_113 * V_114 = ( void * ) V_96 ;
int V_11 ;
V_114 -> V_102 = ( unsigned long ) ( V_112 -> V_87 << V_88 ) ;
if ( ! V_96 -> V_92 ) {
F_51 ( 1 , L_8 ,
V_96 -> V_92 , V_112 , V_96 ) ;
}
V_11 = F_52 ( V_114 -> V_6 , V_114 -> V_102 ,
V_96 -> V_92 , V_96 -> V_115 , V_114 -> V_96 . V_116 ) ;
if ( V_11 ) {
F_9 ( L_9 ,
V_96 -> V_92 , ( unsigned ) V_114 -> V_102 ) ;
return V_11 ;
}
return 0 ;
}
static int F_53 ( struct V_111 * V_96 )
{
struct V_113 * V_114 = ( void * ) V_96 ;
F_54 ( V_114 -> V_6 , V_114 -> V_102 , V_96 -> V_92 ) ;
return 0 ;
}
static void F_55 ( struct V_111 * V_96 )
{
struct V_113 * V_114 = ( void * ) V_96 ;
F_56 ( & V_114 -> V_96 ) ;
F_57 ( V_114 ) ;
}
static struct V_111 * F_58 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_117 ,
struct V_118 * V_119 )
{
struct V_1 * V_6 ;
struct V_113 * V_114 ;
V_6 = F_1 ( V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_59 ( V_3 , V_6 -> V_44 -> V_45 -> V_120 ,
V_16 , V_117 , V_119 ) ;
}
#endif
V_114 = F_60 ( sizeof( struct V_113 ) , V_121 ) ;
if ( V_114 == NULL ) {
return NULL ;
}
V_114 -> V_96 . V_96 . V_36 = & V_122 ;
V_114 -> V_6 = V_6 ;
if ( F_61 ( & V_114 -> V_96 , V_3 , V_16 , V_117 , V_119 ) ) {
F_57 ( V_114 ) ;
return NULL ;
}
return & V_114 -> V_96 . V_96 ;
}
static int F_62 ( struct V_111 * V_96 )
{
struct V_1 * V_6 ;
struct V_113 * V_114 = ( void * ) V_96 ;
unsigned V_123 ;
int V_11 ;
bool V_124 = ! ! ( V_96 -> V_117 & V_125 ) ;
if ( V_96 -> V_126 != V_127 )
return 0 ;
if ( V_124 && V_96 -> V_128 ) {
F_63 ( V_96 -> V_128 , V_96 -> V_115 ,
V_114 -> V_96 . V_116 , V_96 -> V_92 ) ;
V_96 -> V_126 = V_129 ;
return 0 ;
}
V_6 = F_1 ( V_96 -> V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_64 ( V_96 ) ;
}
#endif
#ifdef F_65
if ( F_66 () ) {
return F_67 ( & V_114 -> V_96 , V_6 -> V_130 ) ;
}
#endif
V_11 = F_68 ( V_96 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_123 = 0 ; V_123 < V_96 -> V_92 ; V_123 ++ ) {
V_114 -> V_96 . V_116 [ V_123 ] = F_69 ( V_6 -> V_131 , V_96 -> V_115 [ V_123 ] ,
0 , V_89 ,
V_132 ) ;
if ( F_70 ( V_6 -> V_131 , V_114 -> V_96 . V_116 [ V_123 ] ) ) {
while ( -- V_123 ) {
F_71 ( V_6 -> V_131 , V_114 -> V_96 . V_116 [ V_123 ] ,
V_89 , V_132 ) ;
V_114 -> V_96 . V_116 [ V_123 ] = 0 ;
}
F_72 ( V_96 ) ;
return - V_133 ;
}
}
return 0 ;
}
static void F_73 ( struct V_111 * V_96 )
{
struct V_1 * V_6 ;
struct V_113 * V_114 = ( void * ) V_96 ;
unsigned V_123 ;
bool V_124 = ! ! ( V_96 -> V_117 & V_125 ) ;
if ( V_124 )
return;
V_6 = F_1 ( V_96 -> V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
F_74 ( V_96 ) ;
return;
}
#endif
#ifdef F_65
if ( F_66 () ) {
F_75 ( & V_114 -> V_96 , V_6 -> V_130 ) ;
return;
}
#endif
for ( V_123 = 0 ; V_123 < V_96 -> V_92 ; V_123 ++ ) {
if ( V_114 -> V_96 . V_116 [ V_123 ] ) {
F_71 ( V_6 -> V_131 , V_114 -> V_96 . V_116 [ V_123 ] ,
V_89 , V_132 ) ;
}
}
F_72 ( V_96 ) ;
}
int F_76 ( struct V_1 * V_6 )
{
int V_11 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_77 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_134 , V_135 ,
V_6 -> V_136 ) ;
if ( V_11 ) {
F_9 ( L_10 , V_11 ) ;
return V_11 ;
}
V_6 -> V_5 . V_137 = true ;
V_11 = F_78 ( & V_6 -> V_5 . V_3 , V_50 ,
V_6 -> V_39 . V_138 >> V_88 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
V_11 = F_79 ( V_6 , 256 * 1024 , V_89 , true ,
V_139 ,
NULL , & V_6 -> V_140 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_80 ( V_6 -> V_140 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_81 ( V_6 -> V_140 , V_139 , NULL ) ;
F_82 ( V_6 -> V_140 ) ;
if ( V_11 ) {
F_83 ( & V_6 -> V_140 ) ;
return V_11 ;
}
F_84 ( L_12 ,
( unsigned ) V_6 -> V_39 . V_138 / ( 1024 * 1024 ) ) ;
V_11 = F_78 ( & V_6 -> V_5 . V_3 , V_35 ,
V_6 -> V_39 . V_141 >> V_88 ) ;
if ( V_11 ) {
F_9 ( L_13 ) ;
return V_11 ;
}
F_84 ( L_14 ,
( unsigned ) ( V_6 -> V_39 . V_141 / ( 1024 * 1024 ) ) ) ;
V_6 -> V_5 . V_3 . V_142 = V_6 -> V_44 -> V_142 ;
V_11 = F_85 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_15 ) ;
return V_11 ;
}
return 0 ;
}
void F_86 ( struct V_1 * V_6 )
{
int V_11 ;
if ( ! V_6 -> V_5 . V_137 )
return;
if ( V_6 -> V_140 ) {
V_11 = F_80 ( V_6 -> V_140 , false ) ;
if ( V_11 == 0 ) {
F_87 ( V_6 -> V_140 ) ;
F_82 ( V_6 -> V_140 ) ;
}
F_83 ( & V_6 -> V_140 ) ;
}
F_88 ( & V_6 -> V_5 . V_3 , V_50 ) ;
F_88 ( & V_6 -> V_5 . V_3 , V_35 ) ;
F_89 ( & V_6 -> V_5 . V_3 ) ;
F_90 ( V_6 ) ;
F_11 ( V_6 ) ;
V_6 -> V_5 . V_137 = false ;
F_84 ( L_16 ) ;
}
void F_91 ( struct V_1 * V_6 , T_4 V_16 )
{
struct V_27 * V_28 ;
if ( ! V_6 -> V_5 . V_137 )
return;
V_28 = & V_6 -> V_5 . V_3 . V_28 [ V_50 ] ;
V_28 -> V_16 = V_16 >> V_88 ;
}
static int F_92 ( struct V_143 * V_144 , struct V_145 * V_146 )
{
struct V_53 * V_54 ;
struct V_1 * V_6 ;
int V_11 ;
V_54 = (struct V_53 * ) V_144 -> V_147 ;
if ( V_54 == NULL ) {
return V_148 ;
}
V_6 = F_1 ( V_54 -> V_3 ) ;
F_93 ( & V_6 -> V_149 . V_150 ) ;
V_11 = V_151 -> V_152 ( V_144 , V_146 ) ;
F_94 ( & V_6 -> V_149 . V_150 ) ;
return V_11 ;
}
int F_95 ( struct V_74 * V_75 , struct V_143 * V_144 )
{
struct V_153 * V_154 ;
struct V_1 * V_6 ;
int V_11 ;
if ( F_29 ( V_144 -> V_155 < V_135 ) ) {
return F_96 ( V_75 , V_144 ) ;
}
V_154 = V_75 -> V_156 ;
V_6 = V_154 -> V_157 -> V_130 -> V_158 ;
if ( V_6 == NULL ) {
return - V_46 ;
}
V_11 = F_97 ( V_75 , V_144 , & V_6 -> V_5 . V_3 ) ;
if ( F_29 ( V_11 != 0 ) ) {
return V_11 ;
}
if ( F_29 ( V_151 == NULL ) ) {
V_151 = V_144 -> V_159 ;
V_160 = * V_151 ;
V_160 . V_152 = & F_92 ;
}
V_144 -> V_159 = & V_160 ;
return 0 ;
}
static int F_98 ( struct V_161 * V_162 , void * V_163 )
{
struct V_164 * V_165 = (struct V_164 * ) V_162 -> V_166 ;
struct V_167 * V_168 = (struct V_167 * ) V_165 -> V_169 -> V_163 ;
struct V_170 * V_130 = V_165 -> V_157 -> V_130 ;
struct V_1 * V_6 = V_130 -> V_158 ;
int V_171 ;
struct V_23 * V_172 = V_6 -> V_5 . V_3 . V_172 ;
F_99 ( & V_172 -> V_173 ) ;
V_171 = F_100 ( V_162 , V_168 ) ;
F_101 ( & V_172 -> V_173 ) ;
return V_171 ;
}
static int F_85 ( struct V_1 * V_6 )
{
#if F_102 ( V_174 )
static struct V_175 V_176 [ V_177 + 2 ] ;
static char V_178 [ V_177 + 2 ] [ 32 ] ;
unsigned V_123 ;
for ( V_123 = 0 ; V_123 < V_177 ; V_123 ++ ) {
if ( V_123 == 0 )
sprintf ( V_178 [ V_123 ] , L_17 ) ;
else
sprintf ( V_178 [ V_123 ] , L_18 ) ;
V_176 [ V_123 ] . V_179 = V_178 [ V_123 ] ;
V_176 [ V_123 ] . V_180 = & F_98 ;
V_176 [ V_123 ] . V_181 = 0 ;
if ( V_123 == 0 )
V_176 [ V_123 ] . V_163 = V_6 -> V_5 . V_3 . V_28 [ V_50 ] . V_182 ;
else
V_176 [ V_123 ] . V_163 = V_6 -> V_5 . V_3 . V_28 [ V_35 ] . V_182 ;
}
sprintf ( V_178 [ V_123 ] , L_19 ) ;
V_176 [ V_123 ] . V_179 = V_178 [ V_123 ] ;
V_176 [ V_123 ] . V_180 = & V_183 ;
V_176 [ V_123 ] . V_181 = 0 ;
V_176 [ V_123 ++ ] . V_163 = NULL ;
#ifdef F_65
if ( F_66 () ) {
sprintf ( V_178 [ V_123 ] , L_20 ) ;
V_176 [ V_123 ] . V_179 = V_178 [ V_123 ] ;
V_176 [ V_123 ] . V_180 = & V_184 ;
V_176 [ V_123 ] . V_181 = 0 ;
V_176 [ V_123 ++ ] . V_163 = NULL ;
}
#endif
return F_103 ( V_6 , V_176 , V_123 ) ;
#endif
return 0 ;
}
