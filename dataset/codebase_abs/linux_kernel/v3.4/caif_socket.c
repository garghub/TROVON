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
int V_17 ;
unsigned long V_18 ;
struct V_19 * V_20 = & V_7 -> V_21 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
if ( F_18 ( & V_7 -> V_22 ) + V_15 -> V_23 >=
( unsigned ) V_7 -> V_9 && F_1 ( V_2 ) ) {
if ( F_19 () )
F_20 ( L_1 ,
F_18 ( & V_2 -> V_7 . V_22 ) ,
F_15 ( V_2 ) ) ;
F_4 ( V_2 ) ;
F_16 ( V_7 , V_24 ) ;
}
V_16 = F_21 ( V_7 , V_15 ) ;
if ( V_16 )
return V_16 ;
if ( ! F_22 ( V_7 , V_15 -> V_23 ) && F_1 ( V_2 ) ) {
F_4 ( V_2 ) ;
if ( F_19 () )
F_20 ( L_2 ) ;
F_16 ( V_7 , V_24 ) ;
}
V_15 -> V_25 = NULL ;
F_23 ( V_15 , V_7 ) ;
V_17 = V_15 -> V_26 ;
F_24 ( & V_20 -> V_27 , V_18 ) ;
if ( ! F_25 ( V_7 , V_28 ) )
F_26 ( V_20 , V_15 ) ;
F_27 ( & V_20 -> V_27 , V_18 ) ;
if ( ! F_25 ( V_7 , V_28 ) )
V_7 -> V_29 ( V_7 , V_17 ) ;
else
F_28 ( V_15 ) ;
return 0 ;
}
static int F_29 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
V_2 = F_11 ( V_31 , struct V_1 , V_11 ) ;
V_15 = F_30 ( V_33 ) ;
if ( F_31 ( V_2 -> V_7 . V_34 != V_35 ) ) {
F_28 ( V_15 ) ;
return 0 ;
}
F_17 ( & V_2 -> V_7 , V_15 ) ;
return 0 ;
}
static void F_32 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_11 ( V_31 , struct V_1 , V_11 ) ;
F_33 ( & V_2 -> V_7 ) ;
}
static void F_34 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_11 ( V_31 , struct V_1 , V_11 ) ;
F_35 ( & V_2 -> V_7 ) ;
}
static void F_36 ( struct V_30 * V_31 ,
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
F_37 ( & V_2 -> V_11 ,
F_32 , F_34 ) ;
V_2 -> V_7 . V_34 = V_35 ;
F_9 ( V_2 ) ;
V_2 -> V_7 . V_40 ( & V_2 -> V_7 ) ;
break;
case V_43 :
V_2 -> V_7 . V_34 = V_44 ;
V_2 -> V_7 . V_40 ( & V_2 -> V_7 ) ;
break;
case V_45 :
V_2 -> V_7 . V_46 = V_47 ;
V_2 -> V_7 . V_34 = V_44 ;
V_2 -> V_7 . V_48 = V_49 ;
F_9 ( V_2 ) ;
V_2 -> V_7 . V_40 ( & V_2 -> V_7 ) ;
break;
case V_50 :
V_2 -> V_7 . V_48 = V_49 ;
V_2 -> V_7 . V_46 = V_51 ;
F_6 ( V_2 ) ;
V_2 -> V_7 . V_52 ( & V_2 -> V_7 ) ;
break;
default:
F_20 ( L_3 , V_37 ) ;
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
static int F_39 ( struct V_54 * V_55 , struct V_56 * V_6 ,
struct V_57 * V_58 , T_1 V_26 , int V_18 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_14 * V_15 ;
int V_59 ;
int V_60 ;
V_59 = - V_61 ;
if ( V_58 -> V_62 & V_63 )
goto V_64;
V_15 = F_40 ( V_7 , V_18 , 0 , & V_59 ) ;
if ( ! V_15 )
goto V_64;
V_60 = V_15 -> V_26 ;
if ( V_26 < V_60 ) {
V_58 -> V_62 |= V_65 ;
V_60 = V_26 ;
}
V_59 = F_41 ( V_15 , 0 , V_58 -> V_66 , V_60 ) ;
if ( V_59 )
goto V_67;
V_59 = ( V_18 & V_65 ) ? V_15 -> V_26 : V_60 ;
V_67:
F_42 ( V_7 , V_15 ) ;
F_38 ( V_7 ) ;
return V_59 ;
V_64:
return V_59 ;
}
static long F_43 ( struct V_6 * V_7 , long V_68 )
{
F_44 ( V_69 ) ;
F_45 ( V_7 ) ;
for (; ; ) {
F_46 ( F_47 ( V_7 ) , & V_69 , V_70 ) ;
if ( ! F_48 ( & V_7 -> V_21 ) ||
V_7 -> V_46 ||
V_7 -> V_34 != V_35 ||
F_25 ( V_7 , V_28 ) ||
( V_7 -> V_48 & V_71 ) ||
F_49 ( V_72 ) ||
! V_68 )
break;
F_7 ( V_73 , & V_7 -> V_74 -> V_18 ) ;
F_50 ( V_7 ) ;
V_68 = F_51 ( V_68 ) ;
F_45 ( V_7 ) ;
F_5 ( V_73 , & V_7 -> V_74 -> V_18 ) ;
}
F_52 ( F_47 ( V_7 ) , & V_69 ) ;
F_50 ( V_7 ) ;
return V_68 ;
}
static int F_53 ( struct V_54 * V_55 , struct V_56 * V_6 ,
struct V_57 * V_75 , T_1 V_76 ,
int V_18 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
int V_77 = 0 ;
int V_78 ;
int V_16 = 0 ;
long V_68 ;
V_16 = - V_61 ;
if ( V_18 & V_63 )
goto V_79;
V_75 -> V_80 = 0 ;
V_16 = - V_81 ;
if ( V_7 -> V_34 == V_82 )
goto V_79;
F_10 ( V_7 ) ;
V_78 = F_54 ( V_7 , V_18 & V_83 , V_76 ) ;
V_68 = F_55 ( V_7 , V_18 & V_84 ) ;
do {
int V_85 ;
struct V_14 * V_15 ;
F_45 ( V_7 ) ;
V_15 = F_56 ( & V_7 -> V_21 ) ;
F_38 ( V_7 ) ;
if ( V_15 == NULL ) {
if ( V_77 >= V_78 )
goto V_86;
V_16 = F_57 ( V_7 ) ;
if ( V_16 )
goto V_86;
V_16 = - V_51 ;
if ( V_7 -> V_48 & V_71 )
goto V_86;
V_16 = - V_87 ;
if ( V_7 -> V_34 != V_35 )
goto V_86;
if ( F_25 ( V_7 , V_28 ) )
goto V_86;
F_50 ( V_7 ) ;
V_16 = - V_81 ;
if ( ! V_68 )
break;
F_13 ( V_7 ) ;
V_68 = F_43 ( V_7 , V_68 ) ;
if ( F_49 ( V_72 ) ) {
V_16 = F_58 ( V_68 ) ;
goto V_79;
}
F_10 ( V_7 ) ;
continue;
V_86:
F_50 ( V_7 ) ;
break;
}
F_50 ( V_7 ) ;
V_85 = F_59 (unsigned int, skb->len, size) ;
if ( F_60 ( V_75 -> V_66 , V_15 -> V_88 , V_85 ) ) {
F_61 ( & V_7 -> V_21 , V_15 ) ;
if ( V_77 == 0 )
V_77 = - V_89 ;
break;
}
V_77 += V_85 ;
V_76 -= V_85 ;
if ( ! ( V_18 & V_90 ) ) {
F_62 ( V_15 , V_85 ) ;
if ( V_15 -> V_26 ) {
F_61 ( & V_7 -> V_21 , V_15 ) ;
break;
}
F_28 ( V_15 ) ;
} else {
F_61 ( & V_7 -> V_21 , V_15 ) ;
break;
}
} while ( V_76 );
F_13 ( V_7 ) ;
V_79:
return V_77 ? : V_16 ;
}
static long F_63 ( struct V_1 * V_2 ,
int V_91 , long V_68 , int * V_16 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
F_44 ( V_69 ) ;
for (; ; ) {
* V_16 = 0 ;
if ( F_3 ( V_2 ) &&
( ! V_91 || F_64 ( & V_2 -> V_7 ) ) )
break;
* V_16 = - V_92 ;
if ( ! V_68 )
break;
* V_16 = - V_93 ;
if ( F_49 ( V_72 ) )
break;
F_46 ( F_47 ( V_7 ) , & V_69 , V_70 ) ;
* V_16 = - V_51 ;
if ( V_7 -> V_48 & V_49 )
break;
* V_16 = - V_7 -> V_46 ;
if ( V_7 -> V_46 )
break;
* V_16 = - V_87 ;
if ( V_2 -> V_7 . V_34 != V_35 )
break;
V_68 = F_51 ( V_68 ) ;
}
F_52 ( F_47 ( V_7 ) , & V_69 ) ;
return V_68 ;
}
static int F_65 ( struct V_14 * V_15 , struct V_1 * V_2 ,
int V_94 , long V_68 )
{
struct V_32 * V_33 ;
V_33 = F_66 ( V_95 , V_15 ) ;
memset ( V_15 -> V_96 , 0 , sizeof( struct V_97 ) ) ;
if ( V_2 -> V_11 . V_12 == NULL ) {
F_28 ( V_15 ) ;
return - V_98 ;
}
return V_2 -> V_11 . V_12 -> V_99 ( V_2 -> V_11 . V_12 , V_33 ) ;
}
static int F_67 ( struct V_54 * V_54 , struct V_56 * V_6 ,
struct V_57 * V_75 , T_1 V_26 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_100 ;
int V_59 = 0 ;
struct V_14 * V_15 = NULL ;
int V_94 ;
long V_68 ;
F_68 ( V_2 ) ;
V_59 = F_57 ( V_7 ) ;
if ( V_59 )
goto V_16;
V_59 = - V_61 ;
if ( V_75 -> V_62 & V_63 )
goto V_16;
V_59 = - V_61 ;
if ( V_75 -> V_80 )
goto V_16;
V_59 = - V_98 ;
if ( F_31 ( V_75 -> V_66 -> V_101 == NULL ) )
goto V_16;
V_94 = V_75 -> V_62 & V_84 ;
V_68 = F_69 ( V_7 , V_94 ) ;
V_68 = F_63 ( F_11 ( V_7 , struct V_1 , V_7 ) ,
1 , V_68 , & V_59 ) ;
if ( V_59 )
goto V_16;
V_59 = - V_87 ;
if ( V_2 -> V_7 . V_34 != V_35 ||
F_25 ( V_7 , V_28 ) ||
( V_7 -> V_48 & V_71 ) )
goto V_16;
V_59 = - V_102 ;
if ( V_26 > V_2 -> V_103 && V_2 -> V_7 . V_104 != V_105 )
goto V_16;
V_100 = V_26 + V_2 -> V_106 + V_2 -> V_107 ;
V_59 = - V_108 ;
V_15 = F_70 ( V_7 , V_100 , V_94 , & V_59 ) ;
if ( ! V_15 || F_71 ( V_15 ) < V_100 )
goto V_16;
F_72 ( V_15 , V_2 -> V_106 ) ;
V_59 = F_73 ( F_74 ( V_15 , V_26 ) , V_75 -> V_66 , V_26 ) ;
if ( V_59 )
goto V_16;
V_59 = F_65 ( V_15 , V_2 , V_94 , V_68 ) ;
if ( V_59 < 0 )
return V_59 ;
return V_26 ;
V_16:
F_28 ( V_15 ) ;
return V_59 ;
}
static int F_75 ( struct V_54 * V_54 , struct V_56 * V_6 ,
struct V_57 * V_75 , T_1 V_26 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_16 , V_76 ;
struct V_14 * V_15 ;
int V_109 = 0 ;
long V_68 ;
V_16 = - V_61 ;
if ( F_31 ( V_75 -> V_62 & V_63 ) )
goto V_110;
if ( F_31 ( V_75 -> V_80 ) )
goto V_110;
V_68 = F_69 ( V_7 , V_75 -> V_62 & V_84 ) ;
V_68 = F_63 ( V_2 , 1 , V_68 , & V_16 ) ;
if ( F_31 ( V_7 -> V_48 & V_111 ) )
goto V_112;
while ( V_109 < V_26 ) {
V_76 = V_26 - V_109 ;
if ( V_76 > V_2 -> V_103 )
V_76 = V_2 -> V_103 ;
if ( V_76 > ( ( V_7 -> V_113 >> 1 ) - 64 ) )
V_76 = ( V_7 -> V_113 >> 1 ) - 64 ;
if ( V_76 > V_114 )
V_76 = V_114 ;
V_15 = F_70 ( V_7 ,
V_76 + V_2 -> V_106 +
V_2 -> V_107 ,
V_75 -> V_62 & V_84 ,
& V_16 ) ;
if ( V_15 == NULL )
goto V_110;
F_72 ( V_15 , V_2 -> V_106 ) ;
V_76 = F_59 ( int , V_76 , F_71 ( V_15 ) ) ;
V_16 = F_73 ( F_74 ( V_15 , V_76 ) , V_75 -> V_66 , V_76 ) ;
if ( V_16 ) {
F_28 ( V_15 ) ;
goto V_110;
}
V_16 = F_65 ( V_15 , V_2 ,
V_75 -> V_62 & V_84 , V_68 ) ;
if ( V_16 < 0 )
goto V_112;
V_109 += V_76 ;
}
return V_109 ;
V_112:
if ( V_109 == 0 && ! ( V_75 -> V_62 & V_115 ) )
F_76 ( V_116 , V_72 , 0 ) ;
V_16 = - V_87 ;
V_110:
return V_109 ? : V_16 ;
}
static int F_77 ( struct V_56 * V_6 ,
int V_117 , int V_118 , char T_2 * V_119 , unsigned int V_120 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_121 ;
if ( V_2 -> V_7 . V_74 -> V_122 != V_123 )
return - V_124 ;
switch ( V_118 ) {
case V_125 :
if ( V_120 < sizeof( int ) )
return - V_98 ;
if ( V_117 != V_126 )
goto V_127;
if ( F_78 ( & V_121 , V_119 , sizeof( int ) ) )
return - V_98 ;
F_45 ( & ( V_2 -> V_7 ) ) ;
V_2 -> V_128 . V_129 = V_121 ;
F_50 ( & V_2 -> V_7 ) ;
return 0 ;
case V_130 :
if ( V_117 != V_126 )
goto V_127;
if ( V_2 -> V_7 . V_104 != V_131 )
return - V_124 ;
F_45 ( & ( V_2 -> V_7 ) ) ;
if ( V_120 > sizeof( V_2 -> V_128 . V_132 . V_88 ) ||
F_78 ( & V_2 -> V_128 . V_132 . V_88 , V_119 , V_120 ) ) {
F_50 ( & V_2 -> V_7 ) ;
return - V_98 ;
}
V_2 -> V_128 . V_132 . V_76 = V_120 ;
F_50 ( & V_2 -> V_7 ) ;
return 0 ;
default:
return - V_124 ;
}
return 0 ;
V_127:
return - V_124 ;
}
static int F_79 ( struct V_56 * V_6 , struct V_133 * V_134 ,
int V_135 , int V_18 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
long V_68 ;
int V_16 ;
int V_136 , V_106 , V_107 ;
unsigned int V_137 ;
struct V_138 * V_25 ;
F_45 ( V_7 ) ;
V_16 = - V_139 ;
if ( V_134 -> V_140 != V_141 )
goto V_79;
switch ( V_6 -> V_122 ) {
case V_123 :
F_68 ( V_7 -> V_34 == V_44 ) ;
break;
case V_142 :
switch ( V_7 -> V_34 ) {
case V_35 :
V_6 -> V_122 = V_143 ;
V_16 = - V_144 ;
goto V_79;
case V_44 :
break;
case V_82 :
V_16 = - V_145 ;
if ( V_18 & V_146 )
goto V_79;
goto V_147;
}
break;
case V_143 :
F_68 ( V_7 -> V_34 == V_35 ||
V_7 -> V_34 == V_44 ) ;
if ( V_7 -> V_48 & V_49 ) {
F_80 ( F_81 ( V_7 ) , & V_2 -> V_11 ) ;
F_82 ( & V_2 -> V_11 ) ;
break;
}
V_16 = - V_144 ;
goto V_79;
case V_148 :
case V_149 :
F_68 ( 1 ) ;
break;
}
V_7 -> V_34 = V_44 ;
V_6 -> V_122 = V_123 ;
F_83 ( & V_2 -> V_7 ) ;
V_16 = - V_98 ;
if ( V_135 != sizeof( struct V_150 ) )
goto V_79;
memcpy ( & V_2 -> V_128 . V_133 , V_134 ,
sizeof( struct V_150 ) ) ;
V_6 -> V_122 = V_142 ;
V_7 -> V_34 = V_82 ;
if ( V_2 -> V_7 . V_151 > V_152 )
V_2 -> V_128 . V_153 = V_152 ;
else if ( V_2 -> V_7 . V_151 < V_154 )
V_2 -> V_128 . V_153 = V_154 ;
else
V_2 -> V_128 . V_153 = V_2 -> V_7 . V_151 ;
V_2 -> V_128 . V_136 = V_2 -> V_7 . V_155 ;
V_2 -> V_11 . V_156 = F_29 ;
V_16 = F_84 ( F_81 ( V_7 ) , & V_2 -> V_128 ,
& V_2 -> V_11 , & V_136 , & V_106 , & V_107 ) ;
if ( V_16 < 0 ) {
V_2 -> V_7 . V_74 -> V_122 = V_123 ;
V_2 -> V_7 . V_34 = V_44 ;
goto V_79;
}
V_16 = - V_157 ;
F_85 () ;
V_25 = F_86 ( F_81 ( V_7 ) , V_136 ) ;
if ( ! V_25 ) {
F_87 () ;
goto V_79;
}
V_2 -> V_106 = F_88 ( V_25 , V_106 ) ;
V_137 = V_25 -> V_137 ;
F_87 () ;
V_2 -> V_107 = V_107 ;
V_2 -> V_103 = V_137 - ( V_106 + V_107 ) ;
if ( V_2 -> V_103 < 1 ) {
F_89 ( L_4 , V_25 -> V_137 ) ;
V_16 = - V_157 ;
goto V_79;
}
V_16 = - V_158 ;
V_147:
if ( V_7 -> V_34 != V_35 && ( V_18 & V_146 ) )
goto V_79;
V_68 = F_69 ( V_7 , V_18 & V_146 ) ;
F_50 ( V_7 ) ;
V_16 = - V_93 ;
V_68 = F_90 ( * F_47 ( V_7 ) ,
V_7 -> V_34 != V_82 ,
V_68 ) ;
F_45 ( V_7 ) ;
if ( V_68 < 0 )
goto V_79;
V_16 = - V_92 ;
if ( V_68 == 0 && V_7 -> V_34 != V_35 )
goto V_79;
if ( V_7 -> V_34 != V_35 ) {
V_6 -> V_122 = V_123 ;
V_16 = F_57 ( V_7 ) ;
if ( ! V_16 )
V_16 = - V_47 ;
goto V_79;
}
V_6 -> V_122 = V_143 ;
V_16 = 0 ;
V_79:
F_50 ( V_7 ) ;
return V_16 ;
}
static int F_91 ( struct V_56 * V_6 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
if ( ! V_7 )
return 0 ;
F_8 ( V_2 ) ;
F_92 ( & V_7 -> V_21 . V_27 ) ;
F_93 ( V_7 , V_28 ) ;
F_94 ( & V_7 -> V_21 . V_27 ) ;
V_6 -> V_7 = NULL ;
F_95 ( F_96 ( V_2 -> V_159 ) ) ;
if ( V_2 -> V_159 != NULL )
F_97 ( V_2 -> V_159 ) ;
F_45 ( & ( V_2 -> V_7 ) ) ;
V_7 -> V_34 = V_44 ;
V_7 -> V_48 = V_49 ;
F_80 ( F_81 ( V_7 ) , & V_2 -> V_11 ) ;
V_2 -> V_7 . V_74 -> V_122 = V_148 ;
F_98 ( F_47 ( V_7 ) , V_160 | V_161 ) ;
F_99 ( V_7 ) ;
F_83 ( & V_2 -> V_7 ) ;
F_50 ( V_7 ) ;
F_35 ( V_7 ) ;
return 0 ;
}
static unsigned int F_100 ( struct V_162 * V_162 ,
struct V_56 * V_6 , T_3 * V_69 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
unsigned int V_163 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
F_101 ( V_162 , F_47 ( V_7 ) , V_69 ) ;
V_163 = 0 ;
if ( V_7 -> V_46 )
V_163 |= V_160 ;
if ( V_7 -> V_48 == V_49 )
V_163 |= V_161 ;
if ( V_7 -> V_48 & V_71 )
V_163 |= V_164 ;
if ( ! F_48 ( & V_7 -> V_21 ) ||
( V_7 -> V_48 & V_71 ) )
V_163 |= V_165 | V_166 ;
if ( F_64 ( V_7 ) && F_3 ( V_2 ) )
V_163 |= V_167 | V_168 | V_169 ;
return V_163 ;
}
static void F_102 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
F_68 ( ! F_18 ( & V_7 -> V_170 ) ) ;
F_68 ( F_103 ( V_7 ) ) ;
F_68 ( ! V_7 -> V_74 ) ;
if ( ! F_25 ( V_7 , V_28 ) ) {
F_20 ( L_5 , V_7 ) ;
return;
}
F_83 ( & V_2 -> V_7 ) ;
F_82 ( & V_2 -> V_11 ) ;
}
static int F_104 ( struct V_171 * V_171 , struct V_56 * V_6 , int V_172 ,
int V_173 )
{
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
static struct V_174 V_175 = { . V_176 = L_6 ,
. V_177 = V_178 ,
. V_179 = sizeof( struct V_1 ) ,
} ;
if ( ! F_105 ( V_180 ) && ! F_105 ( V_181 ) )
return - V_182 ;
if ( V_6 -> type == V_183 )
V_6 -> V_184 = & V_185 ;
else if ( V_6 -> type == V_186 )
V_6 -> V_184 = & V_187 ;
else
return - V_188 ;
if ( V_172 < 0 || V_172 >= V_189 )
return - V_190 ;
V_7 = F_106 ( V_171 , V_191 , V_192 , & V_175 ) ;
if ( ! V_7 )
return - V_108 ;
V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
V_7 -> V_104 = ( unsigned char ) V_172 ;
F_45 ( & ( V_2 -> V_7 ) ) ;
F_107 ( V_6 , V_7 ) ;
V_7 -> V_193 = F_102 ;
F_108 ( & V_2 -> V_8 ) ;
V_2 -> V_11 . V_194 = F_36 ;
V_2 -> V_7 . V_74 -> V_122 = V_123 ;
V_2 -> V_7 . V_34 = V_44 ;
F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
V_2 -> V_7 . V_151 = V_195 ;
V_2 -> V_128 . V_129 = V_196 ;
V_2 -> V_128 . V_172 = V_172 ;
F_50 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int T_4 F_109 ( void )
{
int V_16 = F_110 ( & V_197 ) ;
if ( ! V_16 )
return V_16 ;
return 0 ;
}
static void T_5 F_111 ( void )
{
F_112 ( V_191 ) ;
}
