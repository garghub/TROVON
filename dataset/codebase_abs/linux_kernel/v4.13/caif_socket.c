static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ,
( void * ) & V_2 -> V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_5 ,
( void * ) & V_2 -> V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_3 ,
( void * ) & V_2 -> V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_3 ,
( void * ) & V_2 -> V_4 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_5 ( V_5 ,
( void * ) & V_2 -> V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_7 ( V_5 ,
( void * ) & V_2 -> V_4 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
F_12 ( & V_2 -> V_8 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
F_14 ( & V_2 -> V_8 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_9 / 4 ;
}
static void F_16 ( struct V_6 * V_7 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
if ( V_2 -> V_11 . V_12 && V_2 -> V_11 . V_12 -> V_13 )
V_2 -> V_11 . V_12 -> V_13 ( V_2 -> V_11 . V_12 , V_10 ) ;
}
static void F_17 ( struct V_6 * V_7 , struct V_14 * V_15 )
{
int V_16 ;
unsigned long V_17 ;
struct V_18 * V_19 = & V_7 -> V_20 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
bool V_21 = false ;
if ( F_18 ( & V_7 -> V_22 ) + V_15 -> V_23 >=
( unsigned int ) V_7 -> V_9 && F_1 ( V_2 ) ) {
F_19 ( L_1 ,
F_18 ( & V_2 -> V_7 . V_22 ) ,
F_15 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_16 ( V_7 , V_24 ) ;
}
V_16 = F_20 ( V_7 , V_15 ) ;
if ( V_16 )
goto V_25;
if ( ! F_21 ( V_7 , V_15 , V_15 -> V_23 ) && F_1 ( V_2 ) ) {
F_4 ( V_2 ) ;
F_19 ( L_2 ) ;
F_16 ( V_7 , V_24 ) ;
}
V_15 -> V_26 = NULL ;
F_22 ( V_15 , V_7 ) ;
F_23 ( & V_19 -> V_27 , V_17 ) ;
V_21 = ! F_24 ( V_7 , V_28 ) ;
if ( V_21 )
F_25 ( V_19 , V_15 ) ;
F_26 ( & V_19 -> V_27 , V_17 ) ;
V_25:
if ( V_21 )
V_7 -> V_29 ( V_7 ) ;
else
F_27 ( V_15 ) ;
}
static int F_28 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
V_2 = F_11 ( V_31 , struct V_1 , V_11 ) ;
V_15 = F_29 ( V_33 ) ;
if ( F_30 ( V_2 -> V_7 . V_34 != V_35 ) ) {
F_27 ( V_15 ) ;
return 0 ;
}
F_17 ( & V_2 -> V_7 , V_15 ) ;
return 0 ;
}
static void F_31 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_11 ( V_31 , struct V_1 , V_11 ) ;
F_32 ( & V_2 -> V_7 ) ;
}
static void F_33 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_11 ( V_31 , struct V_1 , V_11 ) ;
F_34 ( & V_2 -> V_7 ) ;
}
static void F_35 ( struct V_30 * V_31 ,
enum V_36 V_37 ,
int V_38 )
{
struct V_1 * V_2 = F_11 ( V_31 , struct V_1 , V_11 ) ;
switch ( V_37 ) {
case V_39 :
F_9 ( V_2 ) ;
V_2 -> V_7 . V_40 ( & V_2 -> V_7 ) ;
break;
case V_41 :
F_8 ( V_2 ) ;
V_2 -> V_7 . V_40 ( & V_2 -> V_7 ) ;
break;
case V_42 :
F_36 ( & V_2 -> V_11 ,
F_31 , F_33 ) ;
V_2 -> V_7 . V_34 = V_35 ;
F_9 ( V_2 ) ;
V_2 -> V_7 . V_43 = 0 ;
V_2 -> V_7 . V_40 ( & V_2 -> V_7 ) ;
break;
case V_44 :
V_2 -> V_7 . V_34 = V_45 ;
V_2 -> V_7 . V_40 ( & V_2 -> V_7 ) ;
break;
case V_46 :
V_2 -> V_7 . V_47 = V_48 ;
V_2 -> V_7 . V_34 = V_45 ;
V_2 -> V_7 . V_43 = V_49 ;
F_9 ( V_2 ) ;
V_2 -> V_7 . V_40 ( & V_2 -> V_7 ) ;
break;
case V_50 :
V_2 -> V_7 . V_43 = V_49 ;
V_2 -> V_7 . V_47 = V_51 ;
F_6 ( V_2 ) ;
V_2 -> V_7 . V_52 ( & V_2 -> V_7 ) ;
break;
default:
F_37 ( L_3 , V_37 ) ;
}
}
static void F_38 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
if ( F_1 ( V_2 ) )
return;
if ( F_18 ( & V_7 -> V_22 ) <= F_15 ( V_2 ) ) {
F_6 ( V_2 ) ;
F_16 ( V_7 , V_53 ) ;
}
}
static int F_39 ( struct V_54 * V_6 , struct V_55 * V_56 ,
T_1 V_57 , int V_17 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_14 * V_15 ;
int V_58 ;
int V_59 ;
V_58 = - V_60 ;
if ( V_17 & V_61 )
goto V_62;
V_15 = F_40 ( V_7 , V_17 , 0 , & V_58 ) ;
if ( ! V_15 )
goto V_62;
V_59 = V_15 -> V_57 ;
if ( V_57 < V_59 ) {
V_56 -> V_63 |= V_64 ;
V_59 = V_57 ;
}
V_58 = F_41 ( V_15 , 0 , V_56 , V_59 ) ;
if ( V_58 )
goto V_65;
V_58 = ( V_17 & V_64 ) ? V_15 -> V_57 : V_59 ;
V_65:
F_42 ( V_7 , V_15 ) ;
F_38 ( V_7 ) ;
return V_58 ;
V_62:
return V_58 ;
}
static long F_43 ( struct V_6 * V_7 , long V_66 )
{
F_44 ( V_67 ) ;
F_45 ( V_7 ) ;
for (; ; ) {
F_46 ( F_47 ( V_7 ) , & V_67 , V_68 ) ;
if ( ! F_48 ( & V_7 -> V_20 ) ||
V_7 -> V_47 ||
V_7 -> V_34 != V_35 ||
F_24 ( V_7 , V_28 ) ||
( V_7 -> V_43 & V_69 ) ||
F_49 ( V_70 ) ||
! V_66 )
break;
F_50 ( V_71 , V_7 ) ;
F_51 ( V_7 ) ;
V_66 = F_52 ( V_66 ) ;
F_45 ( V_7 ) ;
if ( F_24 ( V_7 , V_28 ) )
break;
F_53 ( V_71 , V_7 ) ;
}
F_54 ( F_47 ( V_7 ) , & V_67 ) ;
F_51 ( V_7 ) ;
return V_66 ;
}
static int F_55 ( struct V_54 * V_6 , struct V_55 * V_72 ,
T_1 V_73 , int V_17 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
int V_74 = 0 ;
int V_75 ;
int V_16 = 0 ;
long V_66 ;
V_16 = - V_60 ;
if ( V_17 & V_61 )
goto V_25;
V_16 = - V_76 ;
if ( V_7 -> V_34 == V_77 )
goto V_25;
F_10 ( V_7 ) ;
V_75 = F_56 ( V_7 , V_17 & V_78 , V_73 ) ;
V_66 = F_57 ( V_7 , V_17 & V_79 ) ;
do {
int V_80 ;
struct V_14 * V_15 ;
F_45 ( V_7 ) ;
if ( F_24 ( V_7 , V_28 ) ) {
V_16 = - V_51 ;
goto V_81;
}
V_15 = F_58 ( & V_7 -> V_20 ) ;
F_38 ( V_7 ) ;
if ( V_15 == NULL ) {
if ( V_74 >= V_75 )
goto V_81;
V_16 = F_59 ( V_7 ) ;
if ( V_16 )
goto V_81;
V_16 = - V_51 ;
if ( V_7 -> V_43 & V_69 )
goto V_81;
V_16 = - V_82 ;
if ( V_7 -> V_34 != V_35 )
goto V_81;
if ( F_24 ( V_7 , V_28 ) )
goto V_81;
F_51 ( V_7 ) ;
V_16 = - V_76 ;
if ( ! V_66 )
break;
F_13 ( V_7 ) ;
V_66 = F_43 ( V_7 , V_66 ) ;
if ( F_49 ( V_70 ) ) {
V_16 = F_60 ( V_66 ) ;
goto V_25;
}
F_10 ( V_7 ) ;
continue;
V_81:
F_51 ( V_7 ) ;
break;
}
F_51 ( V_7 ) ;
V_80 = F_61 (unsigned int, skb->len, size) ;
if ( F_62 ( V_72 , V_15 -> V_83 , V_80 ) ) {
F_63 ( & V_7 -> V_20 , V_15 ) ;
if ( V_74 == 0 )
V_74 = - V_84 ;
break;
}
V_74 += V_80 ;
V_73 -= V_80 ;
if ( ! ( V_17 & V_85 ) ) {
F_64 ( V_15 , V_80 ) ;
if ( V_15 -> V_57 ) {
F_63 ( & V_7 -> V_20 , V_15 ) ;
break;
}
F_27 ( V_15 ) ;
} else {
F_63 ( & V_7 -> V_20 , V_15 ) ;
break;
}
} while ( V_73 );
F_13 ( V_7 ) ;
V_25:
return V_74 ? : V_16 ;
}
static long F_65 ( struct V_1 * V_2 ,
int V_86 , long V_66 , int * V_16 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
F_44 ( V_67 ) ;
for (; ; ) {
* V_16 = 0 ;
if ( F_3 ( V_2 ) &&
( ! V_86 || F_66 ( & V_2 -> V_7 ) ) )
break;
* V_16 = - V_87 ;
if ( ! V_66 )
break;
* V_16 = - V_88 ;
if ( F_49 ( V_70 ) )
break;
F_46 ( F_47 ( V_7 ) , & V_67 , V_68 ) ;
* V_16 = - V_51 ;
if ( V_7 -> V_43 & V_49 )
break;
* V_16 = - V_7 -> V_47 ;
if ( V_7 -> V_47 )
break;
* V_16 = - V_82 ;
if ( V_2 -> V_7 . V_34 != V_35 )
break;
V_66 = F_52 ( V_66 ) ;
}
F_54 ( F_47 ( V_7 ) , & V_67 ) ;
return V_66 ;
}
static int F_67 ( struct V_14 * V_15 , struct V_1 * V_2 ,
int V_89 , long V_66 )
{
struct V_32 * V_33 ;
V_33 = F_68 ( V_90 , V_15 ) ;
memset ( V_15 -> V_91 , 0 , sizeof( struct V_92 ) ) ;
F_69 ( V_33 , V_2 -> V_7 . V_93 ) ;
if ( V_2 -> V_11 . V_12 == NULL ) {
F_27 ( V_15 ) ;
return - V_94 ;
}
return V_2 -> V_11 . V_12 -> V_95 ( V_2 -> V_11 . V_12 , V_33 ) ;
}
static int F_70 ( struct V_54 * V_6 , struct V_55 * V_72 ,
T_1 V_57 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_96 ;
int V_58 = 0 ;
struct V_14 * V_15 = NULL ;
int V_89 ;
long V_66 ;
F_71 ( V_2 ) ;
V_58 = F_59 ( V_7 ) ;
if ( V_58 )
goto V_16;
V_58 = - V_60 ;
if ( V_72 -> V_63 & V_61 )
goto V_16;
V_58 = - V_60 ;
if ( V_72 -> V_97 )
goto V_16;
V_58 = - V_94 ;
if ( F_30 ( V_72 -> V_98 . V_99 -> V_100 == NULL ) )
goto V_16;
V_89 = V_72 -> V_63 & V_79 ;
V_66 = F_72 ( V_7 , V_89 ) ;
V_66 = F_65 ( F_11 ( V_7 , struct V_1 , V_7 ) ,
1 , V_66 , & V_58 ) ;
if ( V_58 )
goto V_16;
V_58 = - V_82 ;
if ( V_2 -> V_7 . V_34 != V_35 ||
F_24 ( V_7 , V_28 ) ||
( V_7 -> V_43 & V_69 ) )
goto V_16;
V_58 = - V_101 ;
if ( V_57 > V_2 -> V_102 && V_2 -> V_7 . V_103 != V_104 )
goto V_16;
V_96 = V_57 + V_2 -> V_105 + V_2 -> V_106 ;
V_58 = - V_107 ;
V_15 = F_73 ( V_7 , V_96 , V_89 , & V_58 ) ;
if ( ! V_15 || F_74 ( V_15 ) < V_96 )
goto V_16;
F_75 ( V_15 , V_2 -> V_105 ) ;
V_58 = F_76 ( F_77 ( V_15 , V_57 ) , V_72 , V_57 ) ;
if ( V_58 )
goto V_16;
V_58 = F_67 ( V_15 , V_2 , V_89 , V_66 ) ;
if ( V_58 < 0 )
return V_58 ;
return V_57 ;
V_16:
F_27 ( V_15 ) ;
return V_58 ;
}
static int F_78 ( struct V_54 * V_6 , struct V_55 * V_72 ,
T_1 V_57 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_16 , V_73 ;
struct V_14 * V_15 ;
int V_108 = 0 ;
long V_66 ;
V_16 = - V_60 ;
if ( F_30 ( V_72 -> V_63 & V_61 ) )
goto V_109;
if ( F_30 ( V_72 -> V_97 ) )
goto V_109;
V_66 = F_72 ( V_7 , V_72 -> V_63 & V_79 ) ;
V_66 = F_65 ( V_2 , 1 , V_66 , & V_16 ) ;
if ( F_30 ( V_7 -> V_43 & V_110 ) )
goto V_111;
while ( V_108 < V_57 ) {
V_73 = V_57 - V_108 ;
if ( V_73 > V_2 -> V_102 )
V_73 = V_2 -> V_102 ;
if ( V_73 > ( ( V_7 -> V_112 >> 1 ) - 64 ) )
V_73 = ( V_7 -> V_112 >> 1 ) - 64 ;
if ( V_73 > V_113 )
V_73 = V_113 ;
V_15 = F_73 ( V_7 ,
V_73 + V_2 -> V_105 +
V_2 -> V_106 ,
V_72 -> V_63 & V_79 ,
& V_16 ) ;
if ( V_15 == NULL )
goto V_109;
F_75 ( V_15 , V_2 -> V_105 ) ;
V_73 = F_61 ( int , V_73 , F_74 ( V_15 ) ) ;
V_16 = F_76 ( F_77 ( V_15 , V_73 ) , V_72 , V_73 ) ;
if ( V_16 ) {
F_27 ( V_15 ) ;
goto V_109;
}
V_16 = F_67 ( V_15 , V_2 ,
V_72 -> V_63 & V_79 , V_66 ) ;
if ( V_16 < 0 )
goto V_111;
V_108 += V_73 ;
}
return V_108 ;
V_111:
if ( V_108 == 0 && ! ( V_72 -> V_63 & V_114 ) )
F_79 ( V_115 , V_70 , 0 ) ;
V_16 = - V_82 ;
V_109:
return V_108 ? : V_16 ;
}
static int F_80 ( struct V_54 * V_6 ,
int V_116 , int V_117 , char T_2 * V_118 , unsigned int V_119 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_120 ;
if ( V_2 -> V_7 . V_121 -> V_122 != V_123 )
return - V_124 ;
switch ( V_117 ) {
case V_125 :
if ( V_119 < sizeof( int ) )
return - V_94 ;
if ( V_116 != V_126 )
goto V_127;
if ( F_81 ( & V_120 , V_118 , sizeof( int ) ) )
return - V_94 ;
F_45 ( & ( V_2 -> V_7 ) ) ;
V_2 -> V_128 . V_129 = V_120 ;
F_51 ( & V_2 -> V_7 ) ;
return 0 ;
case V_130 :
if ( V_116 != V_126 )
goto V_127;
if ( V_2 -> V_7 . V_103 != V_131 )
return - V_124 ;
F_45 ( & ( V_2 -> V_7 ) ) ;
if ( V_119 > sizeof( V_2 -> V_128 . V_132 . V_83 ) ||
F_81 ( & V_2 -> V_128 . V_132 . V_83 , V_118 , V_119 ) ) {
F_51 ( & V_2 -> V_7 ) ;
return - V_94 ;
}
V_2 -> V_128 . V_132 . V_73 = V_119 ;
F_51 ( & V_2 -> V_7 ) ;
return 0 ;
default:
return - V_124 ;
}
return 0 ;
V_127:
return - V_124 ;
}
static int F_82 ( struct V_54 * V_6 , struct V_133 * V_134 ,
int V_135 , int V_17 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
long V_66 ;
int V_16 ;
int V_136 , V_105 , V_106 ;
unsigned int V_137 ;
struct V_138 * V_26 ;
F_45 ( V_7 ) ;
V_16 = - V_94 ;
if ( V_135 < F_83 ( struct V_133 , V_139 ) )
goto V_25;
V_16 = - V_140 ;
if ( V_134 -> V_139 != V_141 )
goto V_25;
switch ( V_6 -> V_122 ) {
case V_123 :
F_71 ( V_7 -> V_34 == V_45 ) ;
break;
case V_142 :
switch ( V_7 -> V_34 ) {
case V_35 :
V_6 -> V_122 = V_143 ;
V_16 = - V_144 ;
goto V_25;
case V_45 :
break;
case V_77 :
V_16 = - V_145 ;
if ( V_17 & V_146 )
goto V_25;
goto V_147;
}
break;
case V_143 :
F_71 ( V_7 -> V_34 == V_35 ||
V_7 -> V_34 == V_45 ) ;
if ( V_7 -> V_43 & V_49 ) {
F_84 ( F_85 ( V_7 ) , & V_2 -> V_11 ) ;
F_86 ( & V_2 -> V_11 ) ;
break;
}
V_16 = - V_144 ;
goto V_25;
case V_148 :
case V_149 :
F_71 ( 1 ) ;
break;
}
V_7 -> V_34 = V_45 ;
V_6 -> V_122 = V_123 ;
F_87 ( & V_2 -> V_7 ) ;
V_16 = - V_94 ;
if ( V_135 != sizeof( struct V_150 ) )
goto V_25;
memcpy ( & V_2 -> V_128 . V_133 , V_134 ,
sizeof( struct V_150 ) ) ;
V_6 -> V_122 = V_142 ;
V_7 -> V_34 = V_77 ;
if ( V_2 -> V_7 . V_93 > V_151 )
V_2 -> V_128 . V_152 = V_151 ;
else if ( V_2 -> V_7 . V_93 < V_153 )
V_2 -> V_128 . V_152 = V_153 ;
else
V_2 -> V_128 . V_152 = V_2 -> V_7 . V_93 ;
V_2 -> V_128 . V_136 = V_2 -> V_7 . V_154 ;
V_2 -> V_11 . V_155 = F_28 ;
V_16 = F_88 ( F_85 ( V_7 ) , & V_2 -> V_128 ,
& V_2 -> V_11 , & V_136 , & V_105 , & V_106 ) ;
if ( V_16 < 0 ) {
V_2 -> V_7 . V_121 -> V_122 = V_123 ;
V_2 -> V_7 . V_34 = V_45 ;
goto V_25;
}
V_16 = - V_156 ;
F_89 () ;
V_26 = F_90 ( F_85 ( V_7 ) , V_136 ) ;
if ( ! V_26 ) {
F_91 () ;
goto V_25;
}
V_2 -> V_105 = F_92 ( V_26 , V_105 ) ;
V_137 = V_26 -> V_137 ;
F_91 () ;
V_2 -> V_106 = V_106 ;
V_2 -> V_102 = V_137 - ( V_105 + V_106 ) ;
if ( V_2 -> V_102 < 1 ) {
F_93 ( L_4 , V_26 -> V_137 ) ;
V_16 = - V_156 ;
goto V_25;
}
V_16 = - V_157 ;
V_147:
if ( V_7 -> V_34 != V_35 && ( V_17 & V_146 ) )
goto V_25;
V_66 = F_72 ( V_7 , V_17 & V_146 ) ;
F_51 ( V_7 ) ;
V_16 = - V_88 ;
V_66 = F_94 ( * F_47 ( V_7 ) ,
V_7 -> V_34 != V_77 ,
V_66 ) ;
F_45 ( V_7 ) ;
if ( V_66 < 0 )
goto V_25;
V_16 = - V_87 ;
if ( V_66 == 0 && V_7 -> V_34 != V_35 )
goto V_25;
if ( V_7 -> V_34 != V_35 ) {
V_6 -> V_122 = V_123 ;
V_16 = F_59 ( V_7 ) ;
if ( ! V_16 )
V_16 = - V_48 ;
goto V_25;
}
V_6 -> V_122 = V_143 ;
V_16 = 0 ;
V_25:
F_51 ( V_7 ) ;
return V_16 ;
}
static int F_95 ( struct V_54 * V_6 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
if ( ! V_7 )
return 0 ;
F_8 ( V_2 ) ;
F_96 ( & V_7 -> V_20 . V_27 ) ;
F_97 ( V_7 , V_28 ) ;
F_98 ( & V_7 -> V_20 . V_27 ) ;
V_6 -> V_7 = NULL ;
F_99 ( F_100 ( V_2 -> V_158 ) ) ;
F_101 ( V_2 -> V_158 ) ;
F_45 ( & ( V_2 -> V_7 ) ) ;
V_7 -> V_34 = V_45 ;
V_7 -> V_43 = V_49 ;
F_84 ( F_85 ( V_7 ) , & V_2 -> V_11 ) ;
V_2 -> V_7 . V_121 -> V_122 = V_148 ;
F_102 ( F_47 ( V_7 ) , V_159 | V_160 ) ;
F_103 ( V_7 ) ;
F_87 ( & V_2 -> V_7 ) ;
F_51 ( V_7 ) ;
F_34 ( V_7 ) ;
return 0 ;
}
static unsigned int F_104 ( struct V_161 * V_161 ,
struct V_54 * V_6 , T_3 * V_67 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
unsigned int V_162 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
F_105 ( V_161 , F_47 ( V_7 ) , V_67 ) ;
V_162 = 0 ;
if ( V_7 -> V_47 )
V_162 |= V_159 ;
if ( V_7 -> V_43 == V_49 )
V_162 |= V_160 ;
if ( V_7 -> V_43 & V_69 )
V_162 |= V_163 ;
if ( ! F_48 ( & V_7 -> V_20 ) ||
( V_7 -> V_43 & V_69 ) )
V_162 |= V_164 | V_165 ;
if ( F_66 ( V_7 ) && F_3 ( V_2 ) )
V_162 |= V_166 | V_167 | V_168 ;
return V_162 ;
}
static void F_106 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
F_71 ( ! F_107 ( & V_7 -> V_169 ) ) ;
F_71 ( F_108 ( V_7 ) ) ;
F_71 ( ! V_7 -> V_121 ) ;
if ( ! F_24 ( V_7 , V_28 ) ) {
F_37 ( L_5 , V_7 ) ;
return;
}
F_87 ( & V_2 -> V_7 ) ;
F_86 ( & V_2 -> V_11 ) ;
}
static int F_109 ( struct V_170 * V_170 , struct V_54 * V_6 , int V_171 ,
int V_172 )
{
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
static struct V_173 V_174 = { . V_175 = L_6 ,
. V_176 = V_177 ,
. V_178 = sizeof( struct V_1 ) ,
} ;
if ( ! F_110 ( V_179 ) && ! F_110 ( V_180 ) )
return - V_181 ;
if ( V_6 -> type == V_182 )
V_6 -> V_183 = & V_184 ;
else if ( V_6 -> type == V_185 )
V_6 -> V_183 = & V_186 ;
else
return - V_187 ;
if ( V_171 < 0 || V_171 >= V_188 )
return - V_189 ;
V_7 = F_111 ( V_170 , V_190 , V_191 , & V_174 , V_172 ) ;
if ( ! V_7 )
return - V_107 ;
V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
V_7 -> V_103 = ( unsigned char ) V_171 ;
switch ( V_171 ) {
case V_192 :
V_7 -> V_93 = V_193 ;
break;
case V_104 :
V_7 -> V_93 = V_194 ;
break;
default:
V_7 -> V_93 = V_195 ;
}
F_45 ( & ( V_2 -> V_7 ) ) ;
F_112 ( V_6 , V_7 ) ;
V_7 -> V_196 = F_106 ;
F_113 ( & V_2 -> V_8 ) ;
V_2 -> V_11 . V_197 = F_35 ;
V_2 -> V_7 . V_121 -> V_122 = V_123 ;
V_2 -> V_7 . V_34 = V_45 ;
F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
V_2 -> V_128 . V_129 = V_198 ;
V_2 -> V_128 . V_171 = V_171 ;
F_51 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int T_4 F_114 ( void )
{
return F_115 ( & V_199 ) ;
}
static void T_5 F_116 ( void )
{
F_117 ( V_190 ) ;
}
