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
static int F_17 ( struct V_6 * V_7 , struct V_14 * V_15 )
{
int V_16 ;
unsigned long V_17 ;
struct V_18 * V_19 = & V_7 -> V_20 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
if ( F_18 ( & V_7 -> V_21 ) + V_15 -> V_22 >=
( unsigned int ) V_7 -> V_9 && F_1 ( V_2 ) ) {
F_19 ( L_1 ,
F_18 ( & V_2 -> V_7 . V_21 ) ,
F_15 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_16 ( V_7 , V_23 ) ;
}
V_16 = F_20 ( V_7 , V_15 ) ;
if ( V_16 )
return V_16 ;
if ( ! F_21 ( V_7 , V_15 , V_15 -> V_22 ) && F_1 ( V_2 ) ) {
F_4 ( V_2 ) ;
F_19 ( L_2 ) ;
F_16 ( V_7 , V_23 ) ;
}
V_15 -> V_24 = NULL ;
F_22 ( V_15 , V_7 ) ;
F_23 ( & V_19 -> V_25 , V_17 ) ;
if ( ! F_24 ( V_7 , V_26 ) )
F_25 ( V_19 , V_15 ) ;
F_26 ( & V_19 -> V_25 , V_17 ) ;
if ( ! F_24 ( V_7 , V_26 ) )
V_7 -> V_27 ( V_7 ) ;
else
F_27 ( V_15 ) ;
return 0 ;
}
static int F_28 ( struct V_28 * V_29 , struct V_30 * V_31 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
V_2 = F_11 ( V_29 , struct V_1 , V_11 ) ;
V_15 = F_29 ( V_31 ) ;
if ( F_30 ( V_2 -> V_7 . V_32 != V_33 ) ) {
F_27 ( V_15 ) ;
return 0 ;
}
F_17 ( & V_2 -> V_7 , V_15 ) ;
return 0 ;
}
static void F_31 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_11 ( V_29 , struct V_1 , V_11 ) ;
F_32 ( & V_2 -> V_7 ) ;
}
static void F_33 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_11 ( V_29 , struct V_1 , V_11 ) ;
F_34 ( & V_2 -> V_7 ) ;
}
static void F_35 ( struct V_28 * V_29 ,
enum V_34 V_35 ,
int V_36 )
{
struct V_1 * V_2 = F_11 ( V_29 , struct V_1 , V_11 ) ;
switch ( V_35 ) {
case V_37 :
F_9 ( V_2 ) ;
V_2 -> V_7 . V_38 ( & V_2 -> V_7 ) ;
break;
case V_39 :
F_8 ( V_2 ) ;
V_2 -> V_7 . V_38 ( & V_2 -> V_7 ) ;
break;
case V_40 :
F_36 ( & V_2 -> V_11 ,
F_31 , F_33 ) ;
V_2 -> V_7 . V_32 = V_33 ;
F_9 ( V_2 ) ;
V_2 -> V_7 . V_41 = 0 ;
V_2 -> V_7 . V_38 ( & V_2 -> V_7 ) ;
break;
case V_42 :
V_2 -> V_7 . V_32 = V_43 ;
V_2 -> V_7 . V_38 ( & V_2 -> V_7 ) ;
break;
case V_44 :
V_2 -> V_7 . V_45 = V_46 ;
V_2 -> V_7 . V_32 = V_43 ;
V_2 -> V_7 . V_41 = V_47 ;
F_9 ( V_2 ) ;
V_2 -> V_7 . V_38 ( & V_2 -> V_7 ) ;
break;
case V_48 :
V_2 -> V_7 . V_41 = V_47 ;
V_2 -> V_7 . V_45 = V_49 ;
F_6 ( V_2 ) ;
V_2 -> V_7 . V_50 ( & V_2 -> V_7 ) ;
break;
default:
F_37 ( L_3 , V_35 ) ;
}
}
static void F_38 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
if ( F_1 ( V_2 ) )
return;
if ( F_18 ( & V_7 -> V_21 ) <= F_15 ( V_2 ) ) {
F_6 ( V_2 ) ;
F_16 ( V_7 , V_51 ) ;
}
}
static int F_39 ( struct V_52 * V_6 , struct V_53 * V_54 ,
T_1 V_55 , int V_17 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_14 * V_15 ;
int V_56 ;
int V_57 ;
V_56 = - V_58 ;
if ( V_17 & V_59 )
goto V_60;
V_15 = F_40 ( V_7 , V_17 , 0 , & V_56 ) ;
if ( ! V_15 )
goto V_60;
V_57 = V_15 -> V_55 ;
if ( V_55 < V_57 ) {
V_54 -> V_61 |= V_62 ;
V_57 = V_55 ;
}
V_56 = F_41 ( V_15 , 0 , V_54 , V_57 ) ;
if ( V_56 )
goto V_63;
V_56 = ( V_17 & V_62 ) ? V_15 -> V_55 : V_57 ;
V_63:
F_42 ( V_7 , V_15 ) ;
F_38 ( V_7 ) ;
return V_56 ;
V_60:
return V_56 ;
}
static long F_43 ( struct V_6 * V_7 , long V_64 )
{
F_44 ( V_65 ) ;
F_45 ( V_7 ) ;
for (; ; ) {
F_46 ( F_47 ( V_7 ) , & V_65 , V_66 ) ;
if ( ! F_48 ( & V_7 -> V_20 ) ||
V_7 -> V_45 ||
V_7 -> V_32 != V_33 ||
F_24 ( V_7 , V_26 ) ||
( V_7 -> V_41 & V_67 ) ||
F_49 ( V_68 ) ||
! V_64 )
break;
F_7 ( V_69 , & V_7 -> V_70 -> V_17 ) ;
F_50 ( V_7 ) ;
V_64 = F_51 ( V_64 ) ;
F_45 ( V_7 ) ;
if ( F_24 ( V_7 , V_26 ) )
break;
F_5 ( V_69 , & V_7 -> V_70 -> V_17 ) ;
}
F_52 ( F_47 ( V_7 ) , & V_65 ) ;
F_50 ( V_7 ) ;
return V_64 ;
}
static int F_53 ( struct V_52 * V_6 , struct V_53 * V_71 ,
T_1 V_72 , int V_17 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
int V_73 = 0 ;
int V_74 ;
int V_16 = 0 ;
long V_64 ;
V_16 = - V_58 ;
if ( V_17 & V_59 )
goto V_75;
V_16 = - V_76 ;
if ( V_7 -> V_32 == V_77 )
goto V_75;
F_10 ( V_7 ) ;
V_74 = F_54 ( V_7 , V_17 & V_78 , V_72 ) ;
V_64 = F_55 ( V_7 , V_17 & V_79 ) ;
do {
int V_80 ;
struct V_14 * V_15 ;
F_45 ( V_7 ) ;
if ( F_24 ( V_7 , V_26 ) ) {
V_16 = - V_49 ;
goto V_81;
}
V_15 = F_56 ( & V_7 -> V_20 ) ;
F_38 ( V_7 ) ;
if ( V_15 == NULL ) {
if ( V_73 >= V_74 )
goto V_81;
V_16 = F_57 ( V_7 ) ;
if ( V_16 )
goto V_81;
V_16 = - V_49 ;
if ( V_7 -> V_41 & V_67 )
goto V_81;
V_16 = - V_82 ;
if ( V_7 -> V_32 != V_33 )
goto V_81;
if ( F_24 ( V_7 , V_26 ) )
goto V_81;
F_50 ( V_7 ) ;
V_16 = - V_76 ;
if ( ! V_64 )
break;
F_13 ( V_7 ) ;
V_64 = F_43 ( V_7 , V_64 ) ;
if ( F_49 ( V_68 ) ) {
V_16 = F_58 ( V_64 ) ;
goto V_75;
}
F_10 ( V_7 ) ;
continue;
V_81:
F_50 ( V_7 ) ;
break;
}
F_50 ( V_7 ) ;
V_80 = F_59 (unsigned int, skb->len, size) ;
if ( F_60 ( V_71 , V_15 -> V_83 , V_80 ) ) {
F_61 ( & V_7 -> V_20 , V_15 ) ;
if ( V_73 == 0 )
V_73 = - V_84 ;
break;
}
V_73 += V_80 ;
V_72 -= V_80 ;
if ( ! ( V_17 & V_85 ) ) {
F_62 ( V_15 , V_80 ) ;
if ( V_15 -> V_55 ) {
F_61 ( & V_7 -> V_20 , V_15 ) ;
break;
}
F_27 ( V_15 ) ;
} else {
F_61 ( & V_7 -> V_20 , V_15 ) ;
break;
}
} while ( V_72 );
F_13 ( V_7 ) ;
V_75:
return V_73 ? : V_16 ;
}
static long F_63 ( struct V_1 * V_2 ,
int V_86 , long V_64 , int * V_16 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
F_44 ( V_65 ) ;
for (; ; ) {
* V_16 = 0 ;
if ( F_3 ( V_2 ) &&
( ! V_86 || F_64 ( & V_2 -> V_7 ) ) )
break;
* V_16 = - V_87 ;
if ( ! V_64 )
break;
* V_16 = - V_88 ;
if ( F_49 ( V_68 ) )
break;
F_46 ( F_47 ( V_7 ) , & V_65 , V_66 ) ;
* V_16 = - V_49 ;
if ( V_7 -> V_41 & V_47 )
break;
* V_16 = - V_7 -> V_45 ;
if ( V_7 -> V_45 )
break;
* V_16 = - V_82 ;
if ( V_2 -> V_7 . V_32 != V_33 )
break;
V_64 = F_51 ( V_64 ) ;
}
F_52 ( F_47 ( V_7 ) , & V_65 ) ;
return V_64 ;
}
static int F_65 ( struct V_14 * V_15 , struct V_1 * V_2 ,
int V_89 , long V_64 )
{
struct V_30 * V_31 ;
V_31 = F_66 ( V_90 , V_15 ) ;
memset ( V_15 -> V_91 , 0 , sizeof( struct V_92 ) ) ;
F_67 ( V_31 , V_2 -> V_7 . V_93 ) ;
if ( V_2 -> V_11 . V_12 == NULL ) {
F_27 ( V_15 ) ;
return - V_94 ;
}
return V_2 -> V_11 . V_12 -> V_95 ( V_2 -> V_11 . V_12 , V_31 ) ;
}
static int F_68 ( struct V_52 * V_6 , struct V_53 * V_71 ,
T_1 V_55 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_96 ;
int V_56 = 0 ;
struct V_14 * V_15 = NULL ;
int V_89 ;
long V_64 ;
F_69 ( V_2 ) ;
V_56 = F_57 ( V_7 ) ;
if ( V_56 )
goto V_16;
V_56 = - V_58 ;
if ( V_71 -> V_61 & V_59 )
goto V_16;
V_56 = - V_58 ;
if ( V_71 -> V_97 )
goto V_16;
V_56 = - V_94 ;
if ( F_30 ( V_71 -> V_98 . V_99 -> V_100 == NULL ) )
goto V_16;
V_89 = V_71 -> V_61 & V_79 ;
V_64 = F_70 ( V_7 , V_89 ) ;
V_64 = F_63 ( F_11 ( V_7 , struct V_1 , V_7 ) ,
1 , V_64 , & V_56 ) ;
if ( V_56 )
goto V_16;
V_56 = - V_82 ;
if ( V_2 -> V_7 . V_32 != V_33 ||
F_24 ( V_7 , V_26 ) ||
( V_7 -> V_41 & V_67 ) )
goto V_16;
V_56 = - V_101 ;
if ( V_55 > V_2 -> V_102 && V_2 -> V_7 . V_103 != V_104 )
goto V_16;
V_96 = V_55 + V_2 -> V_105 + V_2 -> V_106 ;
V_56 = - V_107 ;
V_15 = F_71 ( V_7 , V_96 , V_89 , & V_56 ) ;
if ( ! V_15 || F_72 ( V_15 ) < V_96 )
goto V_16;
F_73 ( V_15 , V_2 -> V_105 ) ;
V_56 = F_74 ( F_75 ( V_15 , V_55 ) , V_71 , V_55 ) ;
if ( V_56 )
goto V_16;
V_56 = F_65 ( V_15 , V_2 , V_89 , V_64 ) ;
if ( V_56 < 0 )
return V_56 ;
return V_55 ;
V_16:
F_27 ( V_15 ) ;
return V_56 ;
}
static int F_76 ( struct V_52 * V_6 , struct V_53 * V_71 ,
T_1 V_55 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_16 , V_72 ;
struct V_14 * V_15 ;
int V_108 = 0 ;
long V_64 ;
V_16 = - V_58 ;
if ( F_30 ( V_71 -> V_61 & V_59 ) )
goto V_109;
if ( F_30 ( V_71 -> V_97 ) )
goto V_109;
V_64 = F_70 ( V_7 , V_71 -> V_61 & V_79 ) ;
V_64 = F_63 ( V_2 , 1 , V_64 , & V_16 ) ;
if ( F_30 ( V_7 -> V_41 & V_110 ) )
goto V_111;
while ( V_108 < V_55 ) {
V_72 = V_55 - V_108 ;
if ( V_72 > V_2 -> V_102 )
V_72 = V_2 -> V_102 ;
if ( V_72 > ( ( V_7 -> V_112 >> 1 ) - 64 ) )
V_72 = ( V_7 -> V_112 >> 1 ) - 64 ;
if ( V_72 > V_113 )
V_72 = V_113 ;
V_15 = F_71 ( V_7 ,
V_72 + V_2 -> V_105 +
V_2 -> V_106 ,
V_71 -> V_61 & V_79 ,
& V_16 ) ;
if ( V_15 == NULL )
goto V_109;
F_73 ( V_15 , V_2 -> V_105 ) ;
V_72 = F_59 ( int , V_72 , F_72 ( V_15 ) ) ;
V_16 = F_74 ( F_75 ( V_15 , V_72 ) , V_71 , V_72 ) ;
if ( V_16 ) {
F_27 ( V_15 ) ;
goto V_109;
}
V_16 = F_65 ( V_15 , V_2 ,
V_71 -> V_61 & V_79 , V_64 ) ;
if ( V_16 < 0 )
goto V_111;
V_108 += V_72 ;
}
return V_108 ;
V_111:
if ( V_108 == 0 && ! ( V_71 -> V_61 & V_114 ) )
F_77 ( V_115 , V_68 , 0 ) ;
V_16 = - V_82 ;
V_109:
return V_108 ? : V_16 ;
}
static int F_78 ( struct V_52 * V_6 ,
int V_116 , int V_117 , char T_2 * V_118 , unsigned int V_119 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_120 ;
if ( V_2 -> V_7 . V_70 -> V_121 != V_122 )
return - V_123 ;
switch ( V_117 ) {
case V_124 :
if ( V_119 < sizeof( int ) )
return - V_94 ;
if ( V_116 != V_125 )
goto V_126;
if ( F_79 ( & V_120 , V_118 , sizeof( int ) ) )
return - V_94 ;
F_45 ( & ( V_2 -> V_7 ) ) ;
V_2 -> V_127 . V_128 = V_120 ;
F_50 ( & V_2 -> V_7 ) ;
return 0 ;
case V_129 :
if ( V_116 != V_125 )
goto V_126;
if ( V_2 -> V_7 . V_103 != V_130 )
return - V_123 ;
F_45 ( & ( V_2 -> V_7 ) ) ;
if ( V_119 > sizeof( V_2 -> V_127 . V_131 . V_83 ) ||
F_79 ( & V_2 -> V_127 . V_131 . V_83 , V_118 , V_119 ) ) {
F_50 ( & V_2 -> V_7 ) ;
return - V_94 ;
}
V_2 -> V_127 . V_131 . V_72 = V_119 ;
F_50 ( & V_2 -> V_7 ) ;
return 0 ;
default:
return - V_123 ;
}
return 0 ;
V_126:
return - V_123 ;
}
static int F_80 ( struct V_52 * V_6 , struct V_132 * V_133 ,
int V_134 , int V_17 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
long V_64 ;
int V_16 ;
int V_135 , V_105 , V_106 ;
unsigned int V_136 ;
struct V_137 * V_24 ;
F_45 ( V_7 ) ;
V_16 = - V_138 ;
if ( V_133 -> V_139 != V_140 )
goto V_75;
switch ( V_6 -> V_121 ) {
case V_122 :
F_69 ( V_7 -> V_32 == V_43 ) ;
break;
case V_141 :
switch ( V_7 -> V_32 ) {
case V_33 :
V_6 -> V_121 = V_142 ;
V_16 = - V_143 ;
goto V_75;
case V_43 :
break;
case V_77 :
V_16 = - V_144 ;
if ( V_17 & V_145 )
goto V_75;
goto V_146;
}
break;
case V_142 :
F_69 ( V_7 -> V_32 == V_33 ||
V_7 -> V_32 == V_43 ) ;
if ( V_7 -> V_41 & V_47 ) {
F_81 ( F_82 ( V_7 ) , & V_2 -> V_11 ) ;
F_83 ( & V_2 -> V_11 ) ;
break;
}
V_16 = - V_143 ;
goto V_75;
case V_147 :
case V_148 :
F_69 ( 1 ) ;
break;
}
V_7 -> V_32 = V_43 ;
V_6 -> V_121 = V_122 ;
F_84 ( & V_2 -> V_7 ) ;
V_16 = - V_94 ;
if ( V_134 != sizeof( struct V_149 ) )
goto V_75;
memcpy ( & V_2 -> V_127 . V_132 , V_133 ,
sizeof( struct V_149 ) ) ;
V_6 -> V_121 = V_141 ;
V_7 -> V_32 = V_77 ;
if ( V_2 -> V_7 . V_93 > V_150 )
V_2 -> V_127 . V_151 = V_150 ;
else if ( V_2 -> V_7 . V_93 < V_152 )
V_2 -> V_127 . V_151 = V_152 ;
else
V_2 -> V_127 . V_151 = V_2 -> V_7 . V_93 ;
V_2 -> V_127 . V_135 = V_2 -> V_7 . V_153 ;
V_2 -> V_11 . V_154 = F_28 ;
V_16 = F_85 ( F_82 ( V_7 ) , & V_2 -> V_127 ,
& V_2 -> V_11 , & V_135 , & V_105 , & V_106 ) ;
if ( V_16 < 0 ) {
V_2 -> V_7 . V_70 -> V_121 = V_122 ;
V_2 -> V_7 . V_32 = V_43 ;
goto V_75;
}
V_16 = - V_155 ;
F_86 () ;
V_24 = F_87 ( F_82 ( V_7 ) , V_135 ) ;
if ( ! V_24 ) {
F_88 () ;
goto V_75;
}
V_2 -> V_105 = F_89 ( V_24 , V_105 ) ;
V_136 = V_24 -> V_136 ;
F_88 () ;
V_2 -> V_106 = V_106 ;
V_2 -> V_102 = V_136 - ( V_105 + V_106 ) ;
if ( V_2 -> V_102 < 1 ) {
F_90 ( L_4 , V_24 -> V_136 ) ;
V_16 = - V_155 ;
goto V_75;
}
V_16 = - V_156 ;
V_146:
if ( V_7 -> V_32 != V_33 && ( V_17 & V_145 ) )
goto V_75;
V_64 = F_70 ( V_7 , V_17 & V_145 ) ;
F_50 ( V_7 ) ;
V_16 = - V_88 ;
V_64 = F_91 ( * F_47 ( V_7 ) ,
V_7 -> V_32 != V_77 ,
V_64 ) ;
F_45 ( V_7 ) ;
if ( V_64 < 0 )
goto V_75;
V_16 = - V_87 ;
if ( V_64 == 0 && V_7 -> V_32 != V_33 )
goto V_75;
if ( V_7 -> V_32 != V_33 ) {
V_6 -> V_121 = V_122 ;
V_16 = F_57 ( V_7 ) ;
if ( ! V_16 )
V_16 = - V_46 ;
goto V_75;
}
V_6 -> V_121 = V_142 ;
V_16 = 0 ;
V_75:
F_50 ( V_7 ) ;
return V_16 ;
}
static int F_92 ( struct V_52 * V_6 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
if ( ! V_7 )
return 0 ;
F_8 ( V_2 ) ;
F_93 ( & V_7 -> V_20 . V_25 ) ;
F_94 ( V_7 , V_26 ) ;
F_95 ( & V_7 -> V_20 . V_25 ) ;
V_6 -> V_7 = NULL ;
F_96 ( F_97 ( V_2 -> V_157 ) ) ;
F_98 ( V_2 -> V_157 ) ;
F_45 ( & ( V_2 -> V_7 ) ) ;
V_7 -> V_32 = V_43 ;
V_7 -> V_41 = V_47 ;
F_81 ( F_82 ( V_7 ) , & V_2 -> V_11 ) ;
V_2 -> V_7 . V_70 -> V_121 = V_147 ;
F_99 ( F_47 ( V_7 ) , V_158 | V_159 ) ;
F_100 ( V_7 ) ;
F_84 ( & V_2 -> V_7 ) ;
F_50 ( V_7 ) ;
F_34 ( V_7 ) ;
return 0 ;
}
static unsigned int F_101 ( struct V_160 * V_160 ,
struct V_52 * V_6 , T_3 * V_65 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
unsigned int V_161 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
F_102 ( V_160 , F_47 ( V_7 ) , V_65 ) ;
V_161 = 0 ;
if ( V_7 -> V_45 )
V_161 |= V_158 ;
if ( V_7 -> V_41 == V_47 )
V_161 |= V_159 ;
if ( V_7 -> V_41 & V_67 )
V_161 |= V_162 ;
if ( ! F_48 ( & V_7 -> V_20 ) ||
( V_7 -> V_41 & V_67 ) )
V_161 |= V_163 | V_164 ;
if ( F_64 ( V_7 ) && F_3 ( V_2 ) )
V_161 |= V_165 | V_166 | V_167 ;
return V_161 ;
}
static void F_103 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
F_69 ( ! F_18 ( & V_7 -> V_168 ) ) ;
F_69 ( F_104 ( V_7 ) ) ;
F_69 ( ! V_7 -> V_70 ) ;
if ( ! F_24 ( V_7 , V_26 ) ) {
F_37 ( L_5 , V_7 ) ;
return;
}
F_84 ( & V_2 -> V_7 ) ;
F_83 ( & V_2 -> V_11 ) ;
}
static int F_105 ( struct V_169 * V_169 , struct V_52 * V_6 , int V_170 ,
int V_171 )
{
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
static struct V_172 V_173 = { . V_174 = L_6 ,
. V_175 = V_176 ,
. V_177 = sizeof( struct V_1 ) ,
} ;
if ( ! F_106 ( V_178 ) && ! F_106 ( V_179 ) )
return - V_180 ;
if ( V_6 -> type == V_181 )
V_6 -> V_182 = & V_183 ;
else if ( V_6 -> type == V_184 )
V_6 -> V_182 = & V_185 ;
else
return - V_186 ;
if ( V_170 < 0 || V_170 >= V_187 )
return - V_188 ;
V_7 = F_107 ( V_169 , V_189 , V_190 , & V_173 ) ;
if ( ! V_7 )
return - V_107 ;
V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
V_7 -> V_103 = ( unsigned char ) V_170 ;
switch ( V_170 ) {
case V_191 :
V_7 -> V_93 = V_192 ;
break;
case V_104 :
V_7 -> V_93 = V_193 ;
break;
default:
V_7 -> V_93 = V_194 ;
}
F_45 ( & ( V_2 -> V_7 ) ) ;
F_108 ( V_6 , V_7 ) ;
V_7 -> V_195 = F_103 ;
F_109 ( & V_2 -> V_8 ) ;
V_2 -> V_11 . V_196 = F_35 ;
V_2 -> V_7 . V_70 -> V_121 = V_122 ;
V_2 -> V_7 . V_32 = V_43 ;
F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
V_2 -> V_127 . V_128 = V_197 ;
V_2 -> V_127 . V_170 = V_170 ;
F_50 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int T_4 F_110 ( void )
{
int V_16 = F_111 ( & V_198 ) ;
if ( ! V_16 )
return V_16 ;
return 0 ;
}
static void T_5 F_112 ( void )
{
F_113 ( V_189 ) ;
}
