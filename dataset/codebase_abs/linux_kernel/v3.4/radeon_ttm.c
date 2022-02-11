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
V_11 = F_22 ( V_6 , & V_86 , F_23 ( V_6 ) ) ;
if ( F_24 ( V_11 ) ) {
return V_11 ;
}
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
if ( ! V_6 -> V_69 [ F_23 ( V_6 ) ] . V_71 ) {
F_9 ( L_7 ) ;
return - V_46 ;
}
F_25 ( ( V_90 % V_91 ) != 0 ) ;
if ( V_6 -> V_92 >= V_93 ) {
for ( V_87 = 0 ; V_87 < V_94 ; ++ V_87 ) {
if ( V_87 == F_23 ( V_6 ) || ! V_6 -> V_69 [ V_87 ] . V_71 )
continue;
if ( ! V_86 -> V_95 ) {
V_11 = F_26 ( V_6 , & V_86 -> V_95 ) ;
if ( V_11 )
continue;
}
V_11 = F_27 ( V_6 , & V_6 -> V_69 [ V_87 ] , 3 ) ;
if ( V_11 )
continue;
F_28 ( V_6 , V_87 , V_86 -> V_95 ) ;
F_29 ( V_6 , & V_6 -> V_69 [ V_87 ] ) ;
V_11 = F_27 ( V_6 , & V_6 -> V_69 [ F_23 ( V_6 ) ] , 3 ) ;
if ( V_11 )
continue;
F_30 ( V_6 , F_23 ( V_6 ) , V_86 -> V_95 ) ;
F_29 ( V_6 , & V_6 -> V_69 [ F_23 ( V_6 ) ] ) ;
}
}
V_11 = F_31 ( V_6 , V_83 , V_84 ,
V_77 -> V_96 * ( V_90 / V_91 ) ,
V_86 ) ;
V_11 = F_32 ( V_54 , ( void * ) V_86 , NULL ,
V_80 , V_81 , V_82 , V_77 ) ;
F_33 ( & V_86 ) ;
return V_11 ;
}
static int F_34 ( struct V_53 * V_54 ,
bool V_80 , bool V_97 ,
bool V_81 , bool V_82 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_54 -> V_67 ;
struct V_76 V_98 ;
T_2 V_59 ;
struct V_55 V_56 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_98 = * V_77 ;
V_98 . V_79 = NULL ;
V_56 . V_61 = 0 ;
V_56 . V_62 = 0 ;
V_56 . V_64 = 1 ;
V_56 . V_56 = & V_59 ;
V_56 . V_65 = 1 ;
V_56 . V_63 = & V_59 ;
V_59 = V_32 | V_99 ;
V_11 = F_35 ( V_54 , & V_56 , & V_98 ,
V_97 , V_81 , V_82 ) ;
if ( F_24 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_36 ( V_54 -> V_100 , V_98 . V_56 ) ;
if ( F_24 ( V_11 ) ) {
goto V_101;
}
V_11 = F_37 ( V_54 -> V_100 , & V_98 ) ;
if ( F_24 ( V_11 ) ) {
goto V_101;
}
V_11 = F_21 ( V_54 , true , V_81 , V_82 , & V_98 , V_78 ) ;
if ( F_24 ( V_11 ) ) {
goto V_101;
}
V_11 = F_38 ( V_54 , true , V_81 , V_82 , V_77 ) ;
V_101:
F_39 ( V_54 , & V_98 ) ;
return V_11 ;
}
static int F_40 ( struct V_53 * V_54 ,
bool V_80 , bool V_97 ,
bool V_81 , bool V_82 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_54 -> V_67 ;
struct V_76 V_98 ;
struct V_55 V_56 ;
T_2 V_59 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
V_98 = * V_77 ;
V_98 . V_79 = NULL ;
V_56 . V_61 = 0 ;
V_56 . V_62 = 0 ;
V_56 . V_64 = 1 ;
V_56 . V_56 = & V_59 ;
V_56 . V_65 = 1 ;
V_56 . V_63 = & V_59 ;
V_59 = V_32 | V_99 ;
V_11 = F_35 ( V_54 , & V_56 , & V_98 , V_97 , V_81 , V_82 ) ;
if ( F_24 ( V_11 ) ) {
return V_11 ;
}
V_11 = F_38 ( V_54 , true , V_81 , V_82 , & V_98 ) ;
if ( F_24 ( V_11 ) ) {
goto V_101;
}
V_11 = F_21 ( V_54 , true , V_81 , V_82 , V_77 , V_78 ) ;
if ( F_24 ( V_11 ) ) {
goto V_101;
}
V_101:
F_39 ( V_54 , & V_98 ) ;
return V_11 ;
}
static int F_41 ( struct V_53 * V_54 ,
bool V_80 , bool V_97 ,
bool V_81 , bool V_82 ,
struct V_76 * V_77 )
{
struct V_1 * V_6 ;
struct V_76 * V_78 = & V_54 -> V_67 ;
int V_11 ;
V_6 = F_1 ( V_54 -> V_3 ) ;
if ( V_78 -> V_68 == V_29 && V_54 -> V_100 == NULL ) {
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
if ( ! V_6 -> V_69 [ F_23 ( V_6 ) ] . V_71 ||
V_6 -> V_102 -> V_103 . V_103 == NULL ) {
goto memcpy;
}
if ( V_78 -> V_68 == V_50 &&
V_77 -> V_68 == V_29 ) {
V_11 = F_34 ( V_54 , V_80 , V_97 ,
V_81 , V_82 , V_77 ) ;
} else if ( V_78 -> V_68 == V_29 &&
V_77 -> V_68 == V_50 ) {
V_11 = F_40 ( V_54 , V_80 , V_97 ,
V_81 , V_82 , V_77 ) ;
} else {
V_11 = F_21 ( V_54 , V_80 , V_81 , V_82 , V_77 , V_78 ) ;
}
if ( V_11 ) {
memcpy:
V_11 = F_42 ( V_54 , V_80 , V_81 , V_82 , V_77 ) ;
}
return V_11 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_76 * V_67 )
{
struct V_27 * V_28 = & V_3 -> V_28 [ V_67 -> V_68 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_67 -> V_104 . V_105 = NULL ;
V_67 -> V_104 . V_106 = 0 ;
V_67 -> V_104 . V_16 = V_67 -> V_96 << V_89 ;
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
V_67 -> V_104 . V_106 = V_67 -> V_88 << V_89 ;
V_67 -> V_104 . V_107 = V_6 -> V_39 . V_109 ;
V_67 -> V_104 . V_108 = ! V_6 -> V_44 -> V_45 -> V_47 ;
}
#endif
break;
case V_50 :
V_67 -> V_104 . V_106 = V_67 -> V_88 << V_89 ;
if ( ( V_67 -> V_104 . V_106 + V_67 -> V_104 . V_16 ) > V_6 -> V_39 . V_110 )
return - V_46 ;
V_67 -> V_104 . V_107 = V_6 -> V_39 . V_111 ;
V_67 -> V_104 . V_108 = true ;
#ifdef F_44
if ( V_67 -> V_56 & V_49 )
V_67 -> V_104 . V_105 =
F_45 ( V_67 -> V_104 . V_107 + V_67 -> V_104 . V_106 ,
V_67 -> V_104 . V_16 ) ;
else
V_67 -> V_104 . V_105 =
F_46 ( V_67 -> V_104 . V_107 + V_67 -> V_104 . V_106 ,
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
static void F_47 ( struct V_2 * V_3 , struct V_76 * V_67 )
{
}
static int F_48 ( void * V_114 , void * V_115 ,
bool V_116 , bool V_97 )
{
return F_49 ( (struct V_85 * ) V_114 , V_97 ) ;
}
static int F_50 ( void * V_114 , void * V_115 )
{
return 0 ;
}
static void F_51 ( void * * V_114 )
{
F_33 ( (struct V_85 * * ) V_114 ) ;
}
static void * F_52 ( void * V_114 )
{
return F_53 ( (struct V_85 * ) V_114 ) ;
}
static bool F_54 ( void * V_114 , void * V_115 )
{
return F_55 ( (struct V_85 * ) V_114 ) ;
}
static int F_56 ( struct V_117 * V_100 ,
struct V_76 * V_118 )
{
struct V_119 * V_120 = ( void * ) V_100 ;
int V_11 ;
V_120 -> V_106 = ( unsigned long ) ( V_118 -> V_88 << V_89 ) ;
if ( ! V_100 -> V_96 ) {
F_57 ( 1 , L_8 ,
V_100 -> V_96 , V_118 , V_100 ) ;
}
V_11 = F_58 ( V_120 -> V_6 , V_120 -> V_106 ,
V_100 -> V_96 , V_100 -> V_121 , V_120 -> V_100 . V_122 ) ;
if ( V_11 ) {
F_9 ( L_9 ,
V_100 -> V_96 , ( unsigned ) V_120 -> V_106 ) ;
return V_11 ;
}
return 0 ;
}
static int F_59 ( struct V_117 * V_100 )
{
struct V_119 * V_120 = ( void * ) V_100 ;
F_60 ( V_120 -> V_6 , V_120 -> V_106 , V_100 -> V_96 ) ;
return 0 ;
}
static void F_61 ( struct V_117 * V_100 )
{
struct V_119 * V_120 = ( void * ) V_100 ;
F_62 ( & V_120 -> V_100 ) ;
F_63 ( V_120 ) ;
}
struct V_117 * F_64 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_123 ,
struct V_124 * V_125 )
{
struct V_1 * V_6 ;
struct V_119 * V_120 ;
V_6 = F_1 ( V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_65 ( V_3 , V_6 -> V_44 -> V_45 -> V_126 ,
V_16 , V_123 , V_125 ) ;
}
#endif
V_120 = F_66 ( sizeof( struct V_119 ) , V_127 ) ;
if ( V_120 == NULL ) {
return NULL ;
}
V_120 -> V_100 . V_100 . V_36 = & V_128 ;
V_120 -> V_6 = V_6 ;
if ( F_67 ( & V_120 -> V_100 , V_3 , V_16 , V_123 , V_125 ) ) {
F_63 ( V_120 ) ;
return NULL ;
}
return & V_120 -> V_100 . V_100 ;
}
static int F_68 ( struct V_117 * V_100 )
{
struct V_1 * V_6 ;
struct V_119 * V_120 = ( void * ) V_100 ;
unsigned V_87 ;
int V_11 ;
if ( V_100 -> V_129 != V_130 )
return 0 ;
V_6 = F_1 ( V_100 -> V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
return F_69 ( V_100 ) ;
}
#endif
#ifdef F_70
if ( F_71 () ) {
return F_72 ( & V_120 -> V_100 , V_6 -> V_131 ) ;
}
#endif
V_11 = F_73 ( V_100 ) ;
if ( V_11 ) {
return V_11 ;
}
for ( V_87 = 0 ; V_87 < V_100 -> V_96 ; V_87 ++ ) {
V_120 -> V_100 . V_122 [ V_87 ] = F_74 ( V_6 -> V_132 , V_100 -> V_121 [ V_87 ] ,
0 , V_90 ,
V_133 ) ;
if ( F_75 ( V_6 -> V_132 , V_120 -> V_100 . V_122 [ V_87 ] ) ) {
while ( -- V_87 ) {
F_76 ( V_6 -> V_132 , V_120 -> V_100 . V_122 [ V_87 ] ,
V_90 , V_133 ) ;
V_120 -> V_100 . V_122 [ V_87 ] = 0 ;
}
F_77 ( V_100 ) ;
return - V_134 ;
}
}
return 0 ;
}
static void F_78 ( struct V_117 * V_100 )
{
struct V_1 * V_6 ;
struct V_119 * V_120 = ( void * ) V_100 ;
unsigned V_87 ;
V_6 = F_1 ( V_100 -> V_3 ) ;
#if V_42
if ( V_6 -> V_26 & V_43 ) {
F_79 ( V_100 ) ;
return;
}
#endif
#ifdef F_70
if ( F_71 () ) {
F_80 ( & V_120 -> V_100 , V_6 -> V_131 ) ;
return;
}
#endif
for ( V_87 = 0 ; V_87 < V_100 -> V_96 ; V_87 ++ ) {
if ( V_120 -> V_100 . V_122 [ V_87 ] ) {
F_76 ( V_6 -> V_132 , V_120 -> V_100 . V_122 [ V_87 ] ,
V_90 , V_133 ) ;
}
}
F_77 ( V_100 ) ;
}
int F_81 ( struct V_1 * V_6 )
{
int V_11 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_82 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_135 , V_136 ,
V_6 -> V_137 ) ;
if ( V_11 ) {
F_9 ( L_10 , V_11 ) ;
return V_11 ;
}
V_6 -> V_5 . V_138 = true ;
V_11 = F_83 ( & V_6 -> V_5 . V_3 , V_50 ,
V_6 -> V_39 . V_139 >> V_89 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
V_11 = F_84 ( V_6 , 256 * 1024 , V_90 , true ,
V_140 ,
& V_6 -> V_141 ) ;
if ( V_11 ) {
return V_11 ;
}
V_11 = F_85 ( V_6 -> V_141 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_86 ( V_6 -> V_141 , V_140 , NULL ) ;
F_87 ( V_6 -> V_141 ) ;
if ( V_11 ) {
F_88 ( & V_6 -> V_141 ) ;
return V_11 ;
}
F_89 ( L_12 ,
( unsigned ) V_6 -> V_39 . V_139 / ( 1024 * 1024 ) ) ;
V_11 = F_83 ( & V_6 -> V_5 . V_3 , V_35 ,
V_6 -> V_39 . V_142 >> V_89 ) ;
if ( V_11 ) {
F_9 ( L_13 ) ;
return V_11 ;
}
F_89 ( L_14 ,
( unsigned ) ( V_6 -> V_39 . V_142 / ( 1024 * 1024 ) ) ) ;
if ( F_24 ( V_6 -> V_5 . V_3 . V_143 == NULL ) ) {
V_6 -> V_5 . V_3 . V_143 = V_6 -> V_44 -> V_143 ;
}
V_11 = F_90 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_15 ) ;
return V_11 ;
}
return 0 ;
}
void F_91 ( struct V_1 * V_6 )
{
int V_11 ;
if ( ! V_6 -> V_5 . V_138 )
return;
if ( V_6 -> V_141 ) {
V_11 = F_85 ( V_6 -> V_141 , false ) ;
if ( V_11 == 0 ) {
F_92 ( V_6 -> V_141 ) ;
F_87 ( V_6 -> V_141 ) ;
}
F_88 ( & V_6 -> V_141 ) ;
}
F_93 ( & V_6 -> V_5 . V_3 , V_50 ) ;
F_93 ( & V_6 -> V_5 . V_3 , V_35 ) ;
F_94 ( & V_6 -> V_5 . V_3 ) ;
F_95 ( V_6 ) ;
F_11 ( V_6 ) ;
V_6 -> V_5 . V_138 = false ;
F_89 ( L_16 ) ;
}
void F_96 ( struct V_1 * V_6 , T_4 V_16 )
{
struct V_27 * V_28 ;
if ( ! V_6 -> V_5 . V_138 )
return;
V_28 = & V_6 -> V_5 . V_3 . V_28 [ V_50 ] ;
V_28 -> V_16 = V_16 >> V_89 ;
}
static int F_97 ( struct V_144 * V_145 , struct V_146 * V_147 )
{
struct V_53 * V_54 ;
struct V_1 * V_6 ;
int V_11 ;
V_54 = (struct V_53 * ) V_145 -> V_148 ;
if ( V_54 == NULL ) {
return V_149 ;
}
V_6 = F_1 ( V_54 -> V_3 ) ;
F_98 ( & V_6 -> V_150 ) ;
V_11 = V_151 -> V_152 ( V_145 , V_147 ) ;
F_99 ( & V_6 -> V_150 ) ;
return V_11 ;
}
int F_100 ( struct V_74 * V_75 , struct V_144 * V_145 )
{
struct V_153 * V_154 ;
struct V_1 * V_6 ;
int V_11 ;
if ( F_24 ( V_145 -> V_155 < V_136 ) ) {
return F_101 ( V_75 , V_145 ) ;
}
V_154 = V_75 -> V_156 ;
V_6 = V_154 -> V_157 -> V_131 -> V_158 ;
if ( V_6 == NULL ) {
return - V_46 ;
}
V_11 = F_102 ( V_75 , V_145 , & V_6 -> V_5 . V_3 ) ;
if ( F_24 ( V_11 != 0 ) ) {
return V_11 ;
}
if ( F_24 ( V_151 == NULL ) ) {
V_151 = V_145 -> V_159 ;
V_160 = * V_151 ;
V_160 . V_152 = & F_97 ;
}
V_145 -> V_159 = & V_160 ;
return 0 ;
}
static int F_103 ( struct V_161 * V_162 , void * V_163 )
{
struct V_164 * V_165 = (struct V_164 * ) V_162 -> V_166 ;
struct V_167 * V_168 = (struct V_167 * ) V_165 -> V_169 -> V_163 ;
struct V_170 * V_131 = V_165 -> V_157 -> V_131 ;
struct V_1 * V_6 = V_131 -> V_158 ;
int V_171 ;
struct V_23 * V_172 = V_6 -> V_5 . V_3 . V_172 ;
F_104 ( & V_172 -> V_173 ) ;
V_171 = F_105 ( V_162 , V_168 ) ;
F_106 ( & V_172 -> V_173 ) ;
return V_171 ;
}
static int F_90 ( struct V_1 * V_6 )
{
#if F_107 ( V_174 )
static struct V_175 V_176 [ V_177 + 2 ] ;
static char V_178 [ V_177 + 2 ] [ 32 ] ;
unsigned V_87 ;
for ( V_87 = 0 ; V_87 < V_177 ; V_87 ++ ) {
if ( V_87 == 0 )
sprintf ( V_178 [ V_87 ] , L_17 ) ;
else
sprintf ( V_178 [ V_87 ] , L_18 ) ;
V_176 [ V_87 ] . V_179 = V_178 [ V_87 ] ;
V_176 [ V_87 ] . V_180 = & F_103 ;
V_176 [ V_87 ] . V_181 = 0 ;
if ( V_87 == 0 )
V_176 [ V_87 ] . V_163 = V_6 -> V_5 . V_3 . V_28 [ V_50 ] . V_182 ;
else
V_176 [ V_87 ] . V_163 = V_6 -> V_5 . V_3 . V_28 [ V_35 ] . V_182 ;
}
sprintf ( V_178 [ V_87 ] , L_19 ) ;
V_176 [ V_87 ] . V_179 = V_178 [ V_87 ] ;
V_176 [ V_87 ] . V_180 = & V_183 ;
V_176 [ V_87 ] . V_181 = 0 ;
V_176 [ V_87 ++ ] . V_163 = NULL ;
#ifdef F_70
if ( F_71 () ) {
sprintf ( V_178 [ V_87 ] , L_20 ) ;
V_176 [ V_87 ] . V_179 = V_178 [ V_87 ] ;
V_176 [ V_87 ] . V_180 = & V_184 ;
V_176 [ V_87 ] . V_181 = 0 ;
V_176 [ V_87 ++ ] . V_163 = NULL ;
}
#endif
return F_108 ( V_6 , V_176 , V_87 ) ;
#endif
return 0 ;
}
