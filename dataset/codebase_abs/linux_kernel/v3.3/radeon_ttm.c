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
V_11 = F_22 ( V_6 , & V_86 , V_6 -> V_88 ) ;
if ( F_23 ( V_11 ) ) {
return V_11 ;
}
V_83 = V_78 -> V_89 << V_90 ;
V_84 = V_77 -> V_89 << V_90 ;
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
if ( ! V_6 -> V_69 [ V_6 -> V_88 ] . V_71 ) {
F_9 ( L_7 ) ;
return - V_46 ;
}
F_24 ( ( V_91 % V_92 ) != 0 ) ;
if ( V_6 -> V_93 >= V_94 ) {
for ( V_87 = 0 ; V_87 < V_95 ; ++ V_87 ) {
if ( V_87 == V_6 -> V_88 || ! V_6 -> V_69 [ V_87 ] . V_71 )
continue;
if ( ! V_86 -> V_96 ) {
V_11 = F_25 ( V_6 , & V_86 -> V_96 ) ;
if ( V_11 )
continue;
}
V_11 = F_26 ( V_6 , & V_6 -> V_69 [ V_87 ] , 3 ) ;
if ( V_11 )
continue;
F_27 ( V_6 , V_87 , V_86 -> V_96 ) ;
F_28 ( V_6 , & V_6 -> V_69 [ V_87 ] ) ;
V_11 = F_26 ( V_6 , & V_6 -> V_69 [ V_6 -> V_88 ] , 3 ) ;
if ( V_11 )
continue;
F_29 ( V_6 , V_6 -> V_88 , V_86 -> V_96 ) ;
F_28 ( V_6 , & V_6 -> V_69 [ V_6 -> V_88 ] ) ;
}
}
V_11 = F_30 ( V_6 , V_83 , V_84 ,
V_77 -> V_97 * ( V_91 / V_92 ) ,
V_86 ) ;
V_11 = F_31 ( V_54 , ( void * ) V_86 , NULL ,
V_80 , V_81 , V_82 , V_77 ) ;
F_32 ( & V_86 ) ;
return V_11 ;
}
static int F_33 ( struct V_53 * V_54 ,
bool V_80 , bool V_98 ,
bool V_81 , bool V_82 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_54 -> V_67 ;
struct V_76 V_99 ;
T_2 V_59 ;
struct V_55 V_56 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_99 = * V_77 ;
V_99 . V_79 = NULL ;
V_56 . V_61 = 0 ;
V_56 . V_62 = 0 ;
V_56 . V_64 = 1 ;
V_56 . V_56 = & V_59 ;
V_56 . V_65 = 1 ;
V_56 . V_63 = & V_59 ;
V_59 = V_32 | V_100 ;
V_11 = F_34 ( V_54 , & V_56 , & V_99 ,
V_98 , V_81 , V_82 ) ;
if ( F_23 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_35 ( V_54 -> V_101 , V_99 . V_56 ) ;
if ( F_23 ( V_11 ) ) {
goto V_102;
}
V_11 = F_36 ( V_54 -> V_101 , & V_99 ) ;
if ( F_23 ( V_11 ) ) {
goto V_102;
}
V_11 = F_21 ( V_54 , true , V_81 , V_82 , & V_99 , V_78 ) ;
if ( F_23 ( V_11 ) ) {
goto V_102;
}
V_11 = F_37 ( V_54 , true , V_81 , V_82 , V_77 ) ;
V_102:
F_38 ( V_54 , & V_99 ) ;
return V_11 ;
}
static int F_39 ( struct V_53 * V_54 ,
bool V_80 , bool V_98 ,
bool V_81 , bool V_82 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_54 -> V_67 ;
struct V_76 V_99 ;
struct V_55 V_56 ;
T_2 V_59 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_99 = * V_77 ;
V_99 . V_79 = NULL ;
V_56 . V_61 = 0 ;
V_56 . V_62 = 0 ;
V_56 . V_64 = 1 ;
V_56 . V_56 = & V_59 ;
V_56 . V_65 = 1 ;
V_56 . V_63 = & V_59 ;
V_59 = V_32 | V_100 ;
V_11 = F_34 ( V_54 , & V_56 , & V_99 , V_98 , V_81 , V_82 ) ;
if ( F_23 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_37 ( V_54 , true , V_81 , V_82 , & V_99 ) ;
if ( F_23 ( V_11 ) ) {
goto V_102;
}
V_11 = F_21 ( V_54 , true , V_81 , V_82 , V_77 , V_78 ) ;
if ( F_23 ( V_11 ) ) {
goto V_102;
}
V_102:
F_38 ( V_54 , & V_99 ) ;
return V_11 ;
}
static int F_40 ( struct V_53 * V_54 ,
bool V_80 , bool V_98 ,
bool V_81 , bool V_82 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_54 -> V_67 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
if ( V_78 -> V_68 == V_29 && V_54 -> V_101 == NULL ) {
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
if ( ! V_6 -> V_69 [ V_70 ] . V_71 || V_6 -> V_103 -> V_104 == NULL ) {
goto memcpy;
}
if ( V_78 -> V_68 == V_50 &&
V_77 -> V_68 == V_29 ) {
V_11 = F_33 ( V_54 , V_80 , V_98 ,
V_81 , V_82 , V_77 ) ;
} else if ( V_78 -> V_68 == V_29 &&
V_77 -> V_68 == V_50 ) {
V_11 = F_39 ( V_54 , V_80 , V_98 ,
V_81 , V_82 , V_77 ) ;
} else {
V_11 = F_21 ( V_54 , V_80 , V_81 , V_82 , V_77 , V_78 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_41 ( V_54 , V_80 , V_81 , V_82 , V_77 ) ;
}
return V_11 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_76 * V_67 )
{
struct V_27 * V_28 = & V_3 -> V_28 [ V_67 -> V_68 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_67 -> V_105 . V_106 = NULL ;
V_67 -> V_105 . V_107 = 0 ;
V_67 -> V_105 . V_16 = V_67 -> V_97 << V_90 ;
V_67 -> V_105 . V_108 = 0 ;
V_67 -> V_105 . V_109 = false ;
if ( ! ( V_28 -> V_26 & V_30 ) )
return - V_46 ;
switch ( V_67 -> V_68 ) {
case V_29 :
return 0 ;
case V_35 :
#if V_42
if ( V_6 -> V_26 & V_43 ) {
V_67 -> V_105 . V_107 = V_67 -> V_89 << V_90 ;
V_67 -> V_105 . V_108 = V_6 -> V_39 . V_110 ;
V_67 -> V_105 . V_109 = ! V_6 -> V_44 -> V_45 -> V_47 ;
}
#endif
break;
case V_50 :
V_67 -> V_105 . V_107 = V_67 -> V_89 << V_90 ;
if ( ( V_67 -> V_105 . V_107 + V_67 -> V_105 . V_16 ) > V_6 -> V_39 . V_111 )
return - V_46 ;
V_67 -> V_105 . V_108 = V_6 -> V_39 . V_112 ;
V_67 -> V_105 . V_109 = true ;
#ifdef F_43
if ( V_67 -> V_56 & V_49 )
V_67 -> V_105 . V_106 =
F_44 ( V_67 -> V_105 . V_108 + V_67 -> V_105 . V_107 ,
V_67 -> V_105 . V_16 ) ;
else
V_67 -> V_105 . V_106 =
F_45 ( V_67 -> V_105 . V_108 + V_67 -> V_105 . V_107 ,
V_67 -> V_105 . V_16 ) ;
V_67 -> V_105 . V_108 = ( V_67 -> V_105 . V_108 & 0x0ffffffffUL ) +
V_6 -> V_44 -> V_113 -> V_114 ;
#endif
break;
default:
return - V_46 ;
}
return 0 ;
}
static void F_46 ( struct V_2 * V_3 , struct V_76 * V_67 )
{
}
static int F_47 ( void * V_115 , void * V_116 ,
bool V_117 , bool V_98 )
{
return F_48 ( (struct V_85 * ) V_115 , V_98 ) ;
}
static int F_49 ( void * V_115 , void * V_116 )
{
return 0 ;
}
static void F_50 ( void * * V_115 )
{
F_32 ( (struct V_85 * * ) V_115 ) ;
}
static void * F_51 ( void * V_115 )
{
return F_52 ( (struct V_85 * ) V_115 ) ;
}
static bool F_53 ( void * V_115 , void * V_116 )
{
return F_54 ( (struct V_85 * ) V_115 ) ;
}
static int F_55 ( struct V_118 * V_101 ,
struct V_76 * V_119 )
{
struct V_120 * V_121 = ( void * ) V_101 ;
int V_11 ;
V_121 -> V_107 = ( unsigned long ) ( V_119 -> V_89 << V_90 ) ;
if ( ! V_101 -> V_97 ) {
F_56 ( 1 , L_8 ,
V_101 -> V_97 , V_119 , V_101 ) ;
}
V_11 = F_57 ( V_121 -> V_6 , V_121 -> V_107 ,
V_101 -> V_97 , V_101 -> V_122 , V_121 -> V_101 . V_123 ) ;
if ( V_11 ) {
F_9 ( L_9 ,
V_101 -> V_97 , ( unsigned ) V_121 -> V_107 ) ;
return V_11 ;
}
return 0 ;
}
static int F_58 ( struct V_118 * V_101 )
{
struct V_120 * V_121 = ( void * ) V_101 ;
F_59 ( V_121 -> V_6 , V_121 -> V_107 , V_101 -> V_97 ) ;
return 0 ;
}
static void F_60 ( struct V_118 * V_101 )
{
struct V_120 * V_121 = ( void * ) V_101 ;
F_61 ( & V_121 -> V_101 ) ;
F_62 ( V_121 ) ;
}
struct V_118 * F_63 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_124 ,
struct V_125 * V_126 )
{
struct V_1 * V_6 ;
struct V_120 * V_121 ;
V_6 = F_1 ( V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_64 ( V_3 , V_6 -> V_44 -> V_45 -> V_127 ,
V_16 , V_124 , V_126 ) ;
}
#endif
V_121 = F_65 ( sizeof( struct V_120 ) , V_128 ) ;
if ( V_121 == NULL ) {
return NULL ;
}
V_121 -> V_101 . V_101 . V_36 = & V_129 ;
V_121 -> V_6 = V_6 ;
if ( F_66 ( & V_121 -> V_101 , V_3 , V_16 , V_124 , V_126 ) ) {
F_62 ( V_121 ) ;
return NULL ;
}
return & V_121 -> V_101 . V_101 ;
}
static int F_67 ( struct V_118 * V_101 )
{
struct V_1 * V_6 ;
struct V_120 * V_121 = ( void * ) V_101 ;
unsigned V_87 ;
int V_11 ;
if ( V_101 -> V_130 != V_131 )
return 0 ;
V_6 = F_1 ( V_101 -> V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_68 ( V_101 ) ;
}
#endif
#ifdef F_69
if ( F_70 () ) {
return F_71 ( & V_121 -> V_101 , V_6 -> V_132 ) ;
}
#endif
V_11 = F_72 ( V_101 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_87 = 0 ; V_87 < V_101 -> V_97 ; V_87 ++ ) {
V_121 -> V_101 . V_123 [ V_87 ] = F_73 ( V_6 -> V_133 , V_101 -> V_122 [ V_87 ] ,
0 , V_91 ,
V_134 ) ;
if ( F_74 ( V_6 -> V_133 , V_121 -> V_101 . V_123 [ V_87 ] ) ) {
while ( -- V_87 ) {
F_75 ( V_6 -> V_133 , V_121 -> V_101 . V_123 [ V_87 ] ,
V_91 , V_134 ) ;
V_121 -> V_101 . V_123 [ V_87 ] = 0 ;
}
F_76 ( V_101 ) ;
return - V_135 ;
}
}
return 0 ;
}
static void F_77 ( struct V_118 * V_101 )
{
struct V_1 * V_6 ;
struct V_120 * V_121 = ( void * ) V_101 ;
unsigned V_87 ;
V_6 = F_1 ( V_101 -> V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
F_78 ( V_101 ) ;
return;
}
#endif
#ifdef F_69
if ( F_70 () ) {
F_79 ( & V_121 -> V_101 , V_6 -> V_132 ) ;
return;
}
#endif
for ( V_87 = 0 ; V_87 < V_101 -> V_97 ; V_87 ++ ) {
if ( V_121 -> V_101 . V_123 [ V_87 ] ) {
F_75 ( V_6 -> V_133 , V_121 -> V_101 . V_123 [ V_87 ] ,
V_91 , V_134 ) ;
}
}
F_76 ( V_101 ) ;
}
int F_80 ( struct V_1 * V_6 )
{
int V_11 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_81 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_136 , V_137 ,
V_6 -> V_138 ) ;
if ( V_11 ) {
F_9 ( L_10 , V_11 ) ;
return V_11 ;
}
V_6 -> V_5 . V_139 = true ;
V_11 = F_82 ( & V_6 -> V_5 . V_3 , V_50 ,
V_6 -> V_39 . V_140 >> V_90 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
V_11 = F_83 ( V_6 , 256 * 1024 , V_91 , true ,
V_141 ,
& V_6 -> V_142 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_84 ( V_6 -> V_142 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_85 ( V_6 -> V_142 , V_141 , NULL ) ;
F_86 ( V_6 -> V_142 ) ;
if ( V_11 ) {
F_87 ( & V_6 -> V_142 ) ;
return V_11 ;
}
F_88 ( L_12 ,
( unsigned ) V_6 -> V_39 . V_140 / ( 1024 * 1024 ) ) ;
V_11 = F_82 ( & V_6 -> V_5 . V_3 , V_35 ,
V_6 -> V_39 . V_143 >> V_90 ) ;
if ( V_11 ) {
F_9 ( L_13 ) ;
return V_11 ;
}
F_88 ( L_14 ,
( unsigned ) ( V_6 -> V_39 . V_143 / ( 1024 * 1024 ) ) ) ;
if ( F_23 ( V_6 -> V_5 . V_3 . V_144 == NULL ) ) {
V_6 -> V_5 . V_3 . V_144 = V_6 -> V_44 -> V_144 ;
}
V_11 = F_89 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_15 ) ;
return V_11 ;
}
return 0 ;
}
void F_90 ( struct V_1 * V_6 )
{
int V_11 ;
if ( ! V_6 -> V_5 . V_139 )
return;
if ( V_6 -> V_142 ) {
V_11 = F_84 ( V_6 -> V_142 , false ) ;
if ( V_11 == 0 ) {
F_91 ( V_6 -> V_142 ) ;
F_86 ( V_6 -> V_142 ) ;
}
F_87 ( & V_6 -> V_142 ) ;
}
F_92 ( & V_6 -> V_5 . V_3 , V_50 ) ;
F_92 ( & V_6 -> V_5 . V_3 , V_35 ) ;
F_93 ( & V_6 -> V_5 . V_3 ) ;
F_94 ( V_6 ) ;
F_11 ( V_6 ) ;
V_6 -> V_5 . V_139 = false ;
F_88 ( L_16 ) ;
}
void F_95 ( struct V_1 * V_6 , T_4 V_16 )
{
struct V_27 * V_28 ;
if ( ! V_6 -> V_5 . V_139 )
return;
V_28 = & V_6 -> V_5 . V_3 . V_28 [ V_50 ] ;
V_28 -> V_16 = V_16 >> V_90 ;
}
static int F_96 ( struct V_145 * V_146 , struct V_147 * V_148 )
{
struct V_53 * V_54 ;
struct V_1 * V_6 ;
int V_11 ;
V_54 = (struct V_53 * ) V_146 -> V_149 ;
if ( V_54 == NULL ) {
return V_150 ;
}
V_6 = F_1 ( V_54 -> V_3 ) ;
F_97 ( & V_6 -> V_151 ) ;
V_11 = V_152 -> V_153 ( V_146 , V_148 ) ;
F_98 ( & V_6 -> V_151 ) ;
return V_11 ;
}
int F_99 ( struct V_74 * V_75 , struct V_145 * V_146 )
{
struct V_154 * V_155 ;
struct V_1 * V_6 ;
int V_11 ;
if ( F_23 ( V_146 -> V_156 < V_137 ) ) {
return F_100 ( V_75 , V_146 ) ;
}
V_155 = V_75 -> V_157 ;
V_6 = V_155 -> V_158 -> V_132 -> V_159 ;
if ( V_6 == NULL ) {
return - V_46 ;
}
V_11 = F_101 ( V_75 , V_146 , & V_6 -> V_5 . V_3 ) ;
if ( F_23 ( V_11 != 0 ) ) {
return V_11 ;
}
if ( F_23 ( V_152 == NULL ) ) {
V_152 = V_146 -> V_160 ;
V_161 = * V_152 ;
V_161 . V_153 = & F_96 ;
}
V_146 -> V_160 = & V_161 ;
return 0 ;
}
static int F_102 ( struct V_162 * V_163 , void * V_164 )
{
struct V_165 * V_166 = (struct V_165 * ) V_163 -> V_167 ;
struct V_168 * V_169 = (struct V_168 * ) V_166 -> V_170 -> V_164 ;
struct V_171 * V_132 = V_166 -> V_158 -> V_132 ;
struct V_1 * V_6 = V_132 -> V_159 ;
int V_172 ;
struct V_23 * V_173 = V_6 -> V_5 . V_3 . V_173 ;
F_103 ( & V_173 -> V_174 ) ;
V_172 = F_104 ( V_163 , V_169 ) ;
F_105 ( & V_173 -> V_174 ) ;
return V_172 ;
}
static int F_89 ( struct V_1 * V_6 )
{
#if F_106 ( V_175 )
static struct V_176 V_177 [ V_178 + 2 ] ;
static char V_179 [ V_178 + 2 ] [ 32 ] ;
unsigned V_87 ;
for ( V_87 = 0 ; V_87 < V_178 ; V_87 ++ ) {
if ( V_87 == 0 )
sprintf ( V_179 [ V_87 ] , L_17 ) ;
else
sprintf ( V_179 [ V_87 ] , L_18 ) ;
V_177 [ V_87 ] . V_180 = V_179 [ V_87 ] ;
V_177 [ V_87 ] . V_181 = & F_102 ;
V_177 [ V_87 ] . V_182 = 0 ;
if ( V_87 == 0 )
V_177 [ V_87 ] . V_164 = V_6 -> V_5 . V_3 . V_28 [ V_50 ] . V_183 ;
else
V_177 [ V_87 ] . V_164 = V_6 -> V_5 . V_3 . V_28 [ V_35 ] . V_183 ;
}
sprintf ( V_179 [ V_87 ] , L_19 ) ;
V_177 [ V_87 ] . V_180 = V_179 [ V_87 ] ;
V_177 [ V_87 ] . V_181 = & V_184 ;
V_177 [ V_87 ] . V_182 = 0 ;
V_177 [ V_87 ++ ] . V_164 = NULL ;
#ifdef F_69
if ( F_70 () ) {
sprintf ( V_179 [ V_87 ] , L_20 ) ;
V_177 [ V_87 ] . V_180 = V_179 [ V_87 ] ;
V_177 [ V_87 ] . V_181 = & V_185 ;
V_177 [ V_87 ] . V_182 = 0 ;
V_177 [ V_87 ++ ] . V_164 = NULL ;
}
#endif
return F_107 ( V_6 , V_177 , V_87 ) ;
#endif
return 0 ;
}
