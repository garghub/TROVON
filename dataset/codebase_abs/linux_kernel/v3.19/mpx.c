static const char * F_1 ( struct V_1 * V_2 )
{
return L_1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == & V_4 ) ;
}
static unsigned long F_3 ( unsigned long V_5 )
{
unsigned long V_6 ;
unsigned long V_7 , V_8 ;
struct V_9 * V_10 = V_11 -> V_10 ;
T_1 V_12 ;
struct V_1 * V_2 ;
if ( V_5 != V_13 && V_5 != V_14 )
return - V_15 ;
F_4 ( & V_10 -> V_16 ) ;
if ( V_10 -> V_17 > V_18 ) {
V_6 = - V_19 ;
goto V_20;
}
V_7 = F_5 ( NULL , 0 , V_5 , 0 , V_21 | V_22 ) ;
if ( V_7 & ~ V_23 ) {
V_6 = V_7 ;
goto V_20;
}
V_12 = V_24 | V_25 | V_26 |
V_10 -> V_27 | V_28 | V_29 | V_30 ;
V_8 = V_7 >> V_31 ;
V_6 = F_6 ( NULL , V_7 , V_5 , V_12 , V_8 ) ;
if ( F_7 ( V_6 ) )
goto V_20;
V_2 = F_8 ( V_10 , V_6 ) ;
if ( ! V_2 ) {
V_6 = - V_19 ;
goto V_20;
}
V_2 -> V_3 = & V_4 ;
if ( V_12 & V_32 ) {
F_9 ( & V_10 -> V_16 ) ;
F_10 ( V_6 , V_5 ) ;
return V_6 ;
}
V_20:
F_9 ( & V_10 -> V_16 ) ;
return V_6 ;
}
static int F_11 ( struct V_33 * V_33 , struct V_34 * V_35 ,
enum V_36 type )
{
int V_37 = 0 ;
static const int V_38 [] = {
F_12 ( struct V_34 , V_39 ) ,
F_12 ( struct V_34 , V_40 ) ,
F_12 ( struct V_34 , V_41 ) ,
F_12 ( struct V_34 , V_42 ) ,
F_12 ( struct V_34 , V_43 ) ,
F_12 ( struct V_34 , V_44 ) ,
F_12 ( struct V_34 , V_45 ) ,
F_12 ( struct V_34 , V_46 ) ,
#ifdef F_13
F_12 ( struct V_34 , V_47 ) ,
F_12 ( struct V_34 , V_48 ) ,
F_12 ( struct V_34 , V_49 ) ,
F_12 ( struct V_34 , V_50 ) ,
F_12 ( struct V_34 , V_51 ) ,
F_12 ( struct V_34 , V_52 ) ,
F_12 ( struct V_34 , V_53 ) ,
F_12 ( struct V_34 , V_54 ) ,
#endif
} ;
int V_55 = F_14 ( V_38 ) ;
if ( F_15 ( F_13 ) && ! V_33 -> V_56 )
V_55 -= 8 ;
switch ( type ) {
case V_57 :
V_37 = F_16 ( V_33 -> V_58 . V_59 ) ;
if ( F_17 ( V_33 -> V_60 . V_59 ) == 1 )
V_37 += 8 ;
break;
case V_61 :
V_37 = F_18 ( V_33 -> V_62 . V_59 ) ;
if ( F_19 ( V_33 -> V_60 . V_59 ) == 1 )
V_37 += 8 ;
break;
case V_63 :
V_37 = F_20 ( V_33 -> V_62 . V_59 ) ;
if ( F_17 ( V_33 -> V_60 . V_59 ) == 1 )
V_37 += 8 ;
break;
default:
F_21 ( L_2 ) ;
F_22 () ;
break;
}
if ( V_37 > V_55 ) {
F_23 ( 1 , L_3 ) ;
return - V_15 ;
}
return V_38 [ V_37 ] ;
}
static void T_2 * F_24 ( struct V_33 * V_33 , struct V_34 * V_35 )
{
unsigned long V_7 , V_64 , V_65 ;
int V_66 , V_67 , V_68 ;
T_3 V_62 ;
F_25 ( V_33 ) ;
F_26 ( V_33 ) ;
V_62 = V_33 -> V_62 . V_59 ;
if ( F_27 ( V_33 -> V_58 . V_59 ) == 3 ) {
V_66 = F_11 ( V_33 , V_35 , V_57 ) ;
if ( V_66 < 0 )
goto V_69;
V_7 = F_28 ( V_35 , V_66 ) ;
} else {
if ( V_33 -> V_62 . V_70 ) {
V_67 = F_11 ( V_33 , V_35 , V_63 ) ;
if ( V_67 < 0 )
goto V_69;
V_68 = F_11 ( V_33 , V_35 , V_61 ) ;
if ( V_68 < 0 )
goto V_69;
V_64 = F_28 ( V_35 , V_67 ) ;
V_65 = F_28 ( V_35 , V_68 ) ;
V_7 = V_64 + V_65 * ( 1 << F_29 ( V_62 ) ) ;
} else {
V_66 = F_11 ( V_33 , V_35 , V_57 ) ;
if ( V_66 < 0 )
goto V_69;
V_7 = F_28 ( V_35 , V_66 ) ;
}
V_7 += V_33 -> V_71 . V_59 ;
}
return ( void T_2 * ) V_7 ;
V_69:
return ( void T_2 * ) - 1 ;
}
static int F_30 ( struct V_33 * V_33 ,
struct V_34 * V_35 )
{
unsigned char V_72 [ V_73 ] ;
int V_56 = ! F_31 ( V_74 ) ;
int V_75 ;
int V_76 ;
V_75 = F_32 ( V_72 , ( void T_2 * ) V_35 -> V_77 , sizeof( V_72 ) ) ;
V_76 = sizeof( V_72 ) - V_75 ;
if ( ! V_76 )
return - V_78 ;
F_33 ( V_33 , V_72 , V_76 , V_56 ) ;
F_34 ( V_33 ) ;
if ( V_76 < V_33 -> V_79 )
return - V_78 ;
F_35 ( V_33 ) ;
if ( V_33 -> V_80 . V_81 [ 0 ] != 0x0f )
goto V_82;
if ( ( V_33 -> V_80 . V_81 [ 1 ] != 0x1a ) &&
( V_33 -> V_80 . V_81 [ 1 ] != 0x1b ) )
goto V_82;
return 0 ;
V_82:
return - V_15 ;
}
T_4 * F_36 ( struct V_34 * V_35 ,
struct V_83 * V_84 )
{
struct V_85 * V_86 , * V_85 ;
T_4 * V_87 = NULL ;
struct V_33 V_33 ;
T_5 V_88 ;
int V_89 ;
V_89 = F_30 ( & V_33 , V_35 ) ;
if ( V_89 )
goto V_90;
F_25 ( & V_33 ) ;
V_88 = F_37 ( V_33 . V_58 . V_59 ) ;
if ( V_88 > 3 ) {
V_89 = - V_15 ;
goto V_90;
}
V_86 = F_38 ( V_84 , V_91 ) ;
if ( ! V_86 ) {
V_89 = - V_15 ;
goto V_90;
}
V_85 = & V_86 [ V_88 ] ;
V_87 = F_39 ( sizeof( * V_87 ) , V_92 ) ;
if ( ! V_87 ) {
V_89 = - V_19 ;
goto V_90;
}
V_87 -> V_93 = ( void T_2 * ) ( unsigned long ) V_85 -> V_94 ;
V_87 -> V_95 = ( void T_2 * ) ( unsigned long ) ~ V_85 -> V_96 ;
V_87 -> V_97 = 0 ;
V_87 -> V_98 = V_99 ;
V_87 -> V_100 = 0 ;
V_87 -> V_101 = V_102 ;
V_87 -> V_103 = F_24 ( & V_33 , V_35 ) ;
if ( V_87 -> V_103 == ( void * ) - 1 ) {
V_89 = - V_15 ;
goto V_90;
}
return V_87 ;
V_90:
F_40 ( V_87 ) ;
return F_41 ( V_89 ) ;
}
static T_2 void * F_42 ( struct V_104 * V_105 )
{
struct V_106 * V_106 ;
if ( ! F_43 ( V_107 ) )
return V_108 ;
if ( F_15 ( F_13 ) && F_31 ( V_74 ) )
return V_108 ;
F_44 ( & V_105 -> V_109 . V_110 ) ;
V_106 = F_38 ( & V_105 -> V_109 . V_110 . V_111 -> V_112 , V_113 ) ;
if ( ! V_106 )
return V_108 ;
if ( ! ( V_106 -> V_114 & V_115 ) )
return V_108 ;
return ( void T_2 * ) ( unsigned long )
( V_106 -> V_114 & V_116 ) ;
}
int F_45 ( struct V_104 * V_105 )
{
void T_2 * V_117 = V_108 ;
struct V_9 * V_10 = V_105 -> V_10 ;
int V_6 = 0 ;
V_117 = F_42 ( V_105 ) ;
F_4 ( & V_10 -> V_16 ) ;
V_10 -> V_118 = V_117 ;
if ( V_10 -> V_118 == V_108 )
V_6 = - V_119 ;
F_9 ( & V_10 -> V_16 ) ;
return V_6 ;
}
int F_46 ( struct V_104 * V_105 )
{
struct V_9 * V_10 = V_11 -> V_10 ;
if ( ! F_43 ( V_107 ) )
return - V_119 ;
F_4 ( & V_10 -> V_16 ) ;
V_10 -> V_118 = V_108 ;
F_9 ( & V_10 -> V_16 ) ;
return 0 ;
}
static int F_47 ( long T_2 * V_120 )
{
unsigned long V_121 = 0 ;
unsigned long V_122 = 0 ;
unsigned long V_123 ;
int V_6 = 0 ;
V_123 = F_3 ( V_14 ) ;
if ( F_48 ( ( void * ) V_123 ) )
return F_49 ( ( void * ) V_123 ) ;
V_123 = V_123 | V_124 ;
V_6 = F_50 ( & V_122 , V_120 ,
V_121 , V_123 ) ;
if ( V_6 )
goto V_125;
if ( V_122 & V_124 ) {
V_6 = 0 ;
goto V_125;
}
if ( V_121 != V_122 ) {
V_6 = - V_15 ;
goto V_125;
}
return 0 ;
V_125:
F_51 ( V_123 & V_126 , V_14 ) ;
return V_6 ;
}
static int F_52 ( struct V_83 * V_84 )
{
unsigned long V_120 , V_117 ;
struct V_106 * V_106 ;
V_106 = F_38 ( V_84 , V_113 ) ;
if ( ! V_106 )
return - V_15 ;
V_117 = V_106 -> V_114 & V_116 ;
V_120 = V_106 -> V_127 & V_128 ;
if ( ( V_120 < V_117 ) ||
( V_120 >= V_117 + V_13 ) )
return - V_15 ;
return F_47 ( ( long T_2 * ) V_120 ) ;
}
int F_53 ( struct V_83 * V_84 )
{
if ( ! F_54 ( V_11 -> V_10 ) )
return - V_15 ;
if ( F_52 ( V_84 ) ) {
F_55 ( V_99 , V_11 ) ;
}
return 0 ;
}
static int F_56 ( long T_2 * V_7 , int V_129 )
{
long V_130 ;
int V_131 = 1 ;
int V_132 = 0 ;
V_130 = F_57 ( V_11 , V_11 -> V_10 , ( unsigned long ) V_7 ,
V_131 , V_129 , V_132 , NULL , NULL ) ;
if ( ! V_130 )
return - V_78 ;
if ( V_130 < 0 )
return V_130 ;
return 0 ;
}
static int F_58 ( struct V_9 * V_10 ,
long T_2 * V_120 , unsigned long * V_123 )
{
int V_6 ;
int V_133 ;
if ( ! F_59 ( V_134 , ( V_120 ) , sizeof( * V_120 ) ) )
return - V_78 ;
while ( 1 ) {
int V_135 = 0 ;
F_60 () ;
V_6 = F_61 ( * V_123 , V_120 ) ;
F_62 () ;
if ( ! V_6 )
break;
if ( V_6 == - V_78 )
V_6 = F_56 ( V_120 , V_135 ) ;
if ( V_6 )
return V_6 ;
}
V_133 = * V_123 & V_124 ;
* V_123 &= V_126 ;
if ( ! V_133 && * V_123 )
return - V_15 ;
if ( ! V_133 )
return - V_136 ;
return 0 ;
}
static int F_63 ( struct V_9 * V_10 ,
unsigned long V_123 ,
unsigned long V_137 , unsigned long V_138 )
{
struct V_1 * V_2 ;
unsigned long V_7 , V_5 ;
V_2 = F_8 ( V_10 , V_137 ) ;
if ( ! V_2 || V_2 -> V_139 > V_137 )
return - V_15 ;
V_7 = V_137 ;
while ( V_2 && V_2 -> V_139 < V_138 ) {
if ( ! F_2 ( V_2 ) )
return - V_15 ;
V_5 = F_64 ( V_2 -> V_140 , V_138 ) - V_7 ;
F_65 ( V_2 , V_7 , V_5 , NULL ) ;
V_2 = V_2 -> V_141 ;
V_7 = V_2 -> V_139 ;
}
return 0 ;
}
static int F_66 ( struct V_9 * V_10 ,
long T_2 * V_120 , unsigned long V_123 )
{
unsigned long V_121 = V_123 | V_124 ;
unsigned long V_122 = 0 ;
int V_6 ;
while ( 1 ) {
int V_135 = 1 ;
F_60 () ;
V_6 = F_50 ( & V_122 , V_120 ,
V_121 , 0 ) ;
F_62 () ;
if ( ! V_6 )
break;
if ( V_6 == - V_78 )
V_6 = F_56 ( V_120 , V_135 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_122 != V_121 ) {
if ( ! V_122 )
return 0 ;
return - V_15 ;
}
return F_67 ( V_10 , V_123 , V_14 ) ;
}
static int F_68 ( struct V_9 * V_10 ,
long T_2 * V_120 , unsigned long V_137 ,
unsigned long V_138 , bool V_142 , bool V_143 )
{
unsigned long V_123 ;
int V_6 ;
V_6 = F_58 ( V_10 , V_120 , & V_123 ) ;
if ( V_6 )
return V_6 ;
if ( V_142 && V_143 )
V_6 = F_63 ( V_10 , V_123 ,
V_123 + F_69 ( V_137 ) ,
V_123 + F_69 ( V_138 ) ) ;
else if ( V_142 )
V_6 = F_63 ( V_10 , V_123 ,
V_123 + F_69 ( V_137 ) ,
V_123 + V_14 ) ;
else if ( V_143 )
V_6 = F_63 ( V_10 , V_123 , V_123 ,
V_123 + F_69 ( V_138 ) ) ;
else
V_6 = F_66 ( V_10 , V_120 , V_123 ) ;
return V_6 ;
}
static int F_70 ( struct V_9 * V_10 ,
unsigned long V_137 , unsigned long V_138 )
{
int V_6 ;
long T_2 * V_144 , * V_145 ;
struct V_1 * V_146 , * V_147 ;
bool V_142 = false , V_143 = false ;
V_144 = V_10 -> V_118 + F_71 ( V_137 ) ;
V_145 = V_10 -> V_118 + F_71 ( V_138 - 1 ) ;
V_147 = F_72 ( V_10 , V_137 , & V_146 ) ;
if ( V_146 && ( V_10 -> V_118 + F_71 ( V_146 -> V_140 - 1 ) )
== V_144 )
V_142 = true ;
if ( V_147 && ( V_10 -> V_118 + F_71 ( V_147 -> V_139 ) )
== V_145 )
V_143 = true ;
if ( V_144 == V_145 ) {
return F_68 ( V_10 , V_144 , V_137 , V_138 ,
V_142 , V_143 ) ;
}
V_6 = F_68 ( V_10 , V_144 , V_137 , V_138 , V_142 , false ) ;
if ( V_6 )
return V_6 ;
V_6 = F_68 ( V_10 , V_145 , V_137 , V_138 , false , V_143 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static int F_73 ( struct V_9 * V_10 ,
unsigned long V_137 , unsigned long V_138 )
{
int V_6 ;
long T_2 * V_120 , * V_144 , * V_145 ;
unsigned long V_123 ;
V_6 = F_70 ( V_10 , V_137 , V_138 ) ;
switch ( V_6 ) {
case 0 :
case - V_136 :
break;
case - V_15 :
case - V_78 :
default:
return V_6 ;
}
V_144 = V_10 -> V_118 + F_71 ( V_137 ) ;
V_145 = V_10 -> V_118 + F_71 ( V_138 - 1 ) ;
for ( V_120 = V_144 + 1 ; V_120 < V_145 ; V_120 ++ ) {
V_6 = F_58 ( V_10 , V_120 , & V_123 ) ;
switch ( V_6 ) {
case 0 :
break;
case - V_136 :
continue;
case - V_15 :
case - V_78 :
default:
return V_6 ;
}
V_6 = F_66 ( V_10 , V_120 , V_123 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
void F_74 ( struct V_9 * V_10 , struct V_1 * V_2 ,
unsigned long V_137 , unsigned long V_138 )
{
int V_6 ;
if ( ! F_54 ( V_11 -> V_10 ) )
return;
do {
if ( V_2 -> V_12 & V_26 )
return;
V_2 = V_2 -> V_141 ;
} while ( V_2 && V_2 -> V_139 < V_138 );
V_6 = F_73 ( V_10 , V_137 , V_138 ) ;
if ( V_6 )
F_55 ( V_99 , V_11 ) ;
}
