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
bool V_80 , int V_81 , bool V_82 ,
struct V_76 * V_77 ,
struct V_76 * V_78 )
{
struct V_1 * V_6 ;
T_3 V_83 , V_84 ;
struct V_85 * V_86 ;
int V_11 , V_87 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_87 = F_22 ( V_6 ) ;
V_83 = V_78 -> V_88 << V_89 ;
V_84 = V_77 -> V_88 << V_89 ;
switch ( V_78 -> V_68 ) {
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
switch ( V_77 -> V_68 ) {
case V_50 :
V_84 += V_6 -> V_39 . V_51 ;
break;
case V_35 :
V_84 += V_6 -> V_39 . V_40 ;
break;
default:
F_9 ( L_6 , V_78 -> V_68 ) ;
return - V_46 ;
}
if ( ! V_6 -> V_69 [ V_87 ] . V_71 ) {
F_9 ( L_7 ) ;
return - V_46 ;
}
F_23 ( ( V_90 % V_91 ) != 0 ) ;
V_86 = V_54 -> V_92 ;
V_11 = F_24 ( V_6 , V_83 , V_84 ,
V_77 -> V_93 * ( V_90 / V_91 ) ,
& V_86 ) ;
V_11 = F_25 ( V_54 , ( void * ) V_86 , NULL ,
V_80 , V_81 , V_82 , V_77 ) ;
F_26 ( & V_86 ) ;
return V_11 ;
}
static int F_27 ( struct V_53 * V_54 ,
bool V_80 , bool V_94 ,
bool V_81 , bool V_82 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_54 -> V_67 ;
struct V_76 V_95 ;
T_2 V_59 ;
struct V_55 V_56 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_95 = * V_77 ;
V_95 . V_79 = NULL ;
V_56 . V_61 = 0 ;
V_56 . V_62 = 0 ;
V_56 . V_64 = 1 ;
V_56 . V_56 = & V_59 ;
V_56 . V_65 = 1 ;
V_56 . V_63 = & V_59 ;
V_59 = V_32 | V_96 ;
V_11 = F_28 ( V_54 , & V_56 , & V_95 ,
V_94 , V_81 , V_82 ) ;
if ( F_29 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_30 ( V_54 -> V_97 , V_95 . V_56 ) ;
if ( F_29 ( V_11 ) ) {
goto V_98;
}
V_11 = F_31 ( V_54 -> V_97 , & V_95 ) ;
if ( F_29 ( V_11 ) ) {
goto V_98;
}
V_11 = F_21 ( V_54 , true , V_81 , V_82 , & V_95 , V_78 ) ;
if ( F_29 ( V_11 ) ) {
goto V_98;
}
V_11 = F_32 ( V_54 , true , V_81 , V_82 , V_77 ) ;
V_98:
F_33 ( V_54 , & V_95 ) ;
return V_11 ;
}
static int F_34 ( struct V_53 * V_54 ,
bool V_80 , bool V_94 ,
bool V_81 , bool V_82 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_54 -> V_67 ;
struct V_76 V_95 ;
struct V_55 V_56 ;
T_2 V_59 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_95 = * V_77 ;
V_95 . V_79 = NULL ;
V_56 . V_61 = 0 ;
V_56 . V_62 = 0 ;
V_56 . V_64 = 1 ;
V_56 . V_56 = & V_59 ;
V_56 . V_65 = 1 ;
V_56 . V_63 = & V_59 ;
V_59 = V_32 | V_96 ;
V_11 = F_28 ( V_54 , & V_56 , & V_95 , V_94 , V_81 , V_82 ) ;
if ( F_29 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_32 ( V_54 , true , V_81 , V_82 , & V_95 ) ;
if ( F_29 ( V_11 ) ) {
goto V_98;
}
V_11 = F_21 ( V_54 , true , V_81 , V_82 , V_77 , V_78 ) ;
if ( F_29 ( V_11 ) ) {
goto V_98;
}
V_98:
F_33 ( V_54 , & V_95 ) ;
return V_11 ;
}
static int F_35 ( struct V_53 * V_54 ,
bool V_80 , bool V_94 ,
bool V_81 , bool V_82 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_54 -> V_67 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
if ( V_78 -> V_68 == V_29 && V_54 -> V_97 == NULL ) {
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
V_6 -> V_99 -> V_100 . V_100 == NULL ) {
goto memcpy;
}
if ( V_78 -> V_68 == V_50 &&
V_77 -> V_68 == V_29 ) {
V_11 = F_27 ( V_54 , V_80 , V_94 ,
V_81 , V_82 , V_77 ) ;
} else if ( V_78 -> V_68 == V_29 &&
V_77 -> V_68 == V_50 ) {
V_11 = F_34 ( V_54 , V_80 , V_94 ,
V_81 , V_82 , V_77 ) ;
} else {
V_11 = F_21 ( V_54 , V_80 , V_81 , V_82 , V_77 , V_78 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_36 ( V_54 , V_80 , V_81 , V_82 , V_77 ) ;
}
return V_11 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_76 * V_67 )
{
struct V_27 * V_28 = & V_3 -> V_28 [ V_67 -> V_68 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_67 -> V_101 . V_102 = NULL ;
V_67 -> V_101 . V_103 = 0 ;
V_67 -> V_101 . V_16 = V_67 -> V_93 << V_89 ;
V_67 -> V_101 . V_104 = 0 ;
V_67 -> V_101 . V_105 = false ;
if ( ! ( V_28 -> V_26 & V_30 ) )
return - V_46 ;
switch ( V_67 -> V_68 ) {
case V_29 :
return 0 ;
case V_35 :
#if V_42
if ( V_6 -> V_26 & V_43 ) {
V_67 -> V_101 . V_103 = V_67 -> V_88 << V_89 ;
V_67 -> V_101 . V_104 = V_6 -> V_39 . V_106 ;
V_67 -> V_101 . V_105 = ! V_6 -> V_44 -> V_45 -> V_47 ;
}
#endif
break;
case V_50 :
V_67 -> V_101 . V_103 = V_67 -> V_88 << V_89 ;
if ( ( V_67 -> V_101 . V_103 + V_67 -> V_101 . V_16 ) > V_6 -> V_39 . V_107 )
return - V_46 ;
V_67 -> V_101 . V_104 = V_6 -> V_39 . V_108 ;
V_67 -> V_101 . V_105 = true ;
#ifdef F_38
if ( V_67 -> V_56 & V_49 )
V_67 -> V_101 . V_102 =
F_39 ( V_67 -> V_101 . V_104 + V_67 -> V_101 . V_103 ,
V_67 -> V_101 . V_16 ) ;
else
V_67 -> V_101 . V_102 =
F_40 ( V_67 -> V_101 . V_104 + V_67 -> V_101 . V_103 ,
V_67 -> V_101 . V_16 ) ;
V_67 -> V_101 . V_104 = ( V_67 -> V_101 . V_104 & 0x0ffffffffUL ) +
V_6 -> V_44 -> V_109 -> V_110 ;
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
static int F_42 ( void * V_92 , void * V_111 ,
bool V_112 , bool V_94 )
{
return F_43 ( (struct V_85 * ) V_92 , V_94 ) ;
}
static int F_44 ( void * V_92 , void * V_111 )
{
return 0 ;
}
static void F_45 ( void * * V_92 )
{
F_26 ( (struct V_85 * * ) V_92 ) ;
}
static void * F_46 ( void * V_92 )
{
return F_47 ( (struct V_85 * ) V_92 ) ;
}
static bool F_48 ( void * V_92 , void * V_111 )
{
return F_49 ( (struct V_85 * ) V_92 ) ;
}
static int F_50 ( struct V_113 * V_97 ,
struct V_76 * V_114 )
{
struct V_115 * V_116 = ( void * ) V_97 ;
int V_11 ;
V_116 -> V_103 = ( unsigned long ) ( V_114 -> V_88 << V_89 ) ;
if ( ! V_97 -> V_93 ) {
F_51 ( 1 , L_8 ,
V_97 -> V_93 , V_114 , V_97 ) ;
}
V_11 = F_52 ( V_116 -> V_6 , V_116 -> V_103 ,
V_97 -> V_93 , V_97 -> V_117 , V_116 -> V_97 . V_118 ) ;
if ( V_11 ) {
F_9 ( L_9 ,
V_97 -> V_93 , ( unsigned ) V_116 -> V_103 ) ;
return V_11 ;
}
return 0 ;
}
static int F_53 ( struct V_113 * V_97 )
{
struct V_115 * V_116 = ( void * ) V_97 ;
F_54 ( V_116 -> V_6 , V_116 -> V_103 , V_97 -> V_93 ) ;
return 0 ;
}
static void F_55 ( struct V_113 * V_97 )
{
struct V_115 * V_116 = ( void * ) V_97 ;
F_56 ( & V_116 -> V_97 ) ;
F_57 ( V_116 ) ;
}
static struct V_113 * F_58 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_119 ,
struct V_120 * V_121 )
{
struct V_1 * V_6 ;
struct V_115 * V_116 ;
V_6 = F_1 ( V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_59 ( V_3 , V_6 -> V_44 -> V_45 -> V_122 ,
V_16 , V_119 , V_121 ) ;
}
#endif
V_116 = F_60 ( sizeof( struct V_115 ) , V_123 ) ;
if ( V_116 == NULL ) {
return NULL ;
}
V_116 -> V_97 . V_97 . V_36 = & V_124 ;
V_116 -> V_6 = V_6 ;
if ( F_61 ( & V_116 -> V_97 , V_3 , V_16 , V_119 , V_121 ) ) {
F_57 ( V_116 ) ;
return NULL ;
}
return & V_116 -> V_97 . V_97 ;
}
static int F_62 ( struct V_113 * V_97 )
{
struct V_1 * V_6 ;
struct V_115 * V_116 = ( void * ) V_97 ;
unsigned V_125 ;
int V_11 ;
bool V_126 = ! ! ( V_97 -> V_119 & V_127 ) ;
if ( V_97 -> V_128 != V_129 )
return 0 ;
if ( V_126 && V_97 -> V_130 ) {
F_63 ( V_97 -> V_130 , V_97 -> V_117 ,
V_116 -> V_97 . V_118 , V_97 -> V_93 ) ;
V_97 -> V_128 = V_131 ;
return 0 ;
}
V_6 = F_1 ( V_97 -> V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_64 ( V_97 ) ;
}
#endif
#ifdef F_65
if ( F_66 () ) {
return F_67 ( & V_116 -> V_97 , V_6 -> V_132 ) ;
}
#endif
V_11 = F_68 ( V_97 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_125 = 0 ; V_125 < V_97 -> V_93 ; V_125 ++ ) {
V_116 -> V_97 . V_118 [ V_125 ] = F_69 ( V_6 -> V_133 , V_97 -> V_117 [ V_125 ] ,
0 , V_90 ,
V_134 ) ;
if ( F_70 ( V_6 -> V_133 , V_116 -> V_97 . V_118 [ V_125 ] ) ) {
while ( -- V_125 ) {
F_71 ( V_6 -> V_133 , V_116 -> V_97 . V_118 [ V_125 ] ,
V_90 , V_134 ) ;
V_116 -> V_97 . V_118 [ V_125 ] = 0 ;
}
F_72 ( V_97 ) ;
return - V_135 ;
}
}
return 0 ;
}
static void F_73 ( struct V_113 * V_97 )
{
struct V_1 * V_6 ;
struct V_115 * V_116 = ( void * ) V_97 ;
unsigned V_125 ;
bool V_126 = ! ! ( V_97 -> V_119 & V_127 ) ;
if ( V_126 )
return;
V_6 = F_1 ( V_97 -> V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
F_74 ( V_97 ) ;
return;
}
#endif
#ifdef F_65
if ( F_66 () ) {
F_75 ( & V_116 -> V_97 , V_6 -> V_132 ) ;
return;
}
#endif
for ( V_125 = 0 ; V_125 < V_97 -> V_93 ; V_125 ++ ) {
if ( V_116 -> V_97 . V_118 [ V_125 ] ) {
F_71 ( V_6 -> V_133 , V_116 -> V_97 . V_118 [ V_125 ] ,
V_90 , V_134 ) ;
}
}
F_72 ( V_97 ) ;
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
& V_136 , V_137 ,
V_6 -> V_138 ) ;
if ( V_11 ) {
F_9 ( L_10 , V_11 ) ;
return V_11 ;
}
V_6 -> V_5 . V_139 = true ;
V_11 = F_78 ( & V_6 -> V_5 . V_3 , V_50 ,
V_6 -> V_39 . V_140 >> V_89 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
V_11 = F_79 ( V_6 , 256 * 1024 , V_90 , true ,
V_141 ,
NULL , & V_6 -> V_142 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_80 ( V_6 -> V_142 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_81 ( V_6 -> V_142 , V_141 , NULL ) ;
F_82 ( V_6 -> V_142 ) ;
if ( V_11 ) {
F_83 ( & V_6 -> V_142 ) ;
return V_11 ;
}
F_84 ( L_12 ,
( unsigned ) V_6 -> V_39 . V_140 / ( 1024 * 1024 ) ) ;
V_11 = F_78 ( & V_6 -> V_5 . V_3 , V_35 ,
V_6 -> V_39 . V_143 >> V_89 ) ;
if ( V_11 ) {
F_9 ( L_13 ) ;
return V_11 ;
}
F_84 ( L_14 ,
( unsigned ) ( V_6 -> V_39 . V_143 / ( 1024 * 1024 ) ) ) ;
V_6 -> V_5 . V_3 . V_144 = V_6 -> V_44 -> V_144 ;
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
if ( ! V_6 -> V_5 . V_139 )
return;
if ( V_6 -> V_142 ) {
V_11 = F_80 ( V_6 -> V_142 , false ) ;
if ( V_11 == 0 ) {
F_87 ( V_6 -> V_142 ) ;
F_82 ( V_6 -> V_142 ) ;
}
F_83 ( & V_6 -> V_142 ) ;
}
F_88 ( & V_6 -> V_5 . V_3 , V_50 ) ;
F_88 ( & V_6 -> V_5 . V_3 , V_35 ) ;
F_89 ( & V_6 -> V_5 . V_3 ) ;
F_90 ( V_6 ) ;
F_11 ( V_6 ) ;
V_6 -> V_5 . V_139 = false ;
F_84 ( L_16 ) ;
}
void F_91 ( struct V_1 * V_6 , T_4 V_16 )
{
struct V_27 * V_28 ;
if ( ! V_6 -> V_5 . V_139 )
return;
V_28 = & V_6 -> V_5 . V_3 . V_28 [ V_50 ] ;
V_28 -> V_16 = V_16 >> V_89 ;
}
static int F_92 ( struct V_145 * V_146 , struct V_147 * V_148 )
{
struct V_53 * V_54 ;
struct V_1 * V_6 ;
int V_11 ;
V_54 = (struct V_53 * ) V_146 -> V_149 ;
if ( V_54 == NULL ) {
return V_150 ;
}
V_6 = F_1 ( V_54 -> V_3 ) ;
F_93 ( & V_6 -> V_151 . V_152 ) ;
V_11 = V_153 -> V_154 ( V_146 , V_148 ) ;
F_94 ( & V_6 -> V_151 . V_152 ) ;
return V_11 ;
}
int F_95 ( struct V_74 * V_75 , struct V_145 * V_146 )
{
struct V_155 * V_156 ;
struct V_1 * V_6 ;
int V_11 ;
if ( F_29 ( V_146 -> V_157 < V_137 ) ) {
return F_96 ( V_75 , V_146 ) ;
}
V_156 = V_75 -> V_158 ;
V_6 = V_156 -> V_159 -> V_132 -> V_160 ;
if ( V_6 == NULL ) {
return - V_46 ;
}
V_11 = F_97 ( V_75 , V_146 , & V_6 -> V_5 . V_3 ) ;
if ( F_29 ( V_11 != 0 ) ) {
return V_11 ;
}
if ( F_29 ( V_153 == NULL ) ) {
V_153 = V_146 -> V_161 ;
V_162 = * V_153 ;
V_162 . V_154 = & F_92 ;
}
V_146 -> V_161 = & V_162 ;
return 0 ;
}
static int F_98 ( struct V_163 * V_164 , void * V_165 )
{
struct V_166 * V_167 = (struct V_166 * ) V_164 -> V_168 ;
struct V_169 * V_170 = (struct V_169 * ) V_167 -> V_171 -> V_165 ;
struct V_172 * V_132 = V_167 -> V_159 -> V_132 ;
struct V_1 * V_6 = V_132 -> V_160 ;
int V_173 ;
struct V_23 * V_174 = V_6 -> V_5 . V_3 . V_174 ;
F_99 ( & V_174 -> V_175 ) ;
V_173 = F_100 ( V_164 , V_170 ) ;
F_101 ( & V_174 -> V_175 ) ;
return V_173 ;
}
static int F_85 ( struct V_1 * V_6 )
{
#if F_102 ( V_176 )
static struct V_177 V_178 [ V_179 + 2 ] ;
static char V_180 [ V_179 + 2 ] [ 32 ] ;
unsigned V_125 ;
for ( V_125 = 0 ; V_125 < V_179 ; V_125 ++ ) {
if ( V_125 == 0 )
sprintf ( V_180 [ V_125 ] , L_17 ) ;
else
sprintf ( V_180 [ V_125 ] , L_18 ) ;
V_178 [ V_125 ] . V_181 = V_180 [ V_125 ] ;
V_178 [ V_125 ] . V_182 = & F_98 ;
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
#ifdef F_65
if ( F_66 () ) {
sprintf ( V_180 [ V_125 ] , L_20 ) ;
V_178 [ V_125 ] . V_181 = V_180 [ V_125 ] ;
V_178 [ V_125 ] . V_182 = & V_186 ;
V_178 [ V_125 ] . V_183 = 0 ;
V_178 [ V_125 ++ ] . V_165 = NULL ;
}
#endif
return F_103 ( V_6 , V_178 , V_125 ) ;
#endif
return 0 ;
}
