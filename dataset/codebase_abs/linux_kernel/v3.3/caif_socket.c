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
F_21 ( & V_24 . V_25 ) ;
F_16 ( V_7 , V_26 ) ;
}
V_16 = F_22 ( V_7 , V_15 ) ;
if ( V_16 )
return V_16 ;
if ( ! F_23 ( V_7 , V_15 -> V_23 ) && F_1 ( V_2 ) ) {
F_4 ( V_2 ) ;
if ( F_19 () )
F_20 ( L_2 ) ;
F_21 ( & V_24 . V_25 ) ;
F_16 ( V_7 , V_26 ) ;
}
V_15 -> V_27 = NULL ;
F_24 ( V_15 , V_7 ) ;
V_17 = V_15 -> V_28 ;
F_25 ( & V_20 -> V_29 , V_18 ) ;
if ( ! F_26 ( V_7 , V_30 ) )
F_27 ( V_20 , V_15 ) ;
F_28 ( & V_20 -> V_29 , V_18 ) ;
if ( ! F_26 ( V_7 , V_30 ) )
V_7 -> V_31 ( V_7 , V_17 ) ;
else
F_29 ( V_15 ) ;
return 0 ;
}
static int F_30 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
V_2 = F_11 ( V_33 , struct V_1 , V_11 ) ;
V_15 = F_31 ( V_35 ) ;
if ( F_32 ( V_2 -> V_7 . V_36 != V_37 ) ) {
F_29 ( V_15 ) ;
return 0 ;
}
F_17 ( & V_2 -> V_7 , V_15 ) ;
return 0 ;
}
static void F_33 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_11 ( V_33 , struct V_1 , V_11 ) ;
F_34 ( & V_2 -> V_7 ) ;
}
static void F_35 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_11 ( V_33 , struct V_1 , V_11 ) ;
F_36 ( & V_2 -> V_7 ) ;
}
static void F_37 ( struct V_32 * V_33 ,
enum V_38 V_39 ,
int V_40 )
{
struct V_1 * V_2 = F_11 ( V_33 , struct V_1 , V_11 ) ;
switch ( V_39 ) {
case V_41 :
F_21 ( & V_24 . V_42 ) ;
F_9 ( V_2 ) ;
V_2 -> V_7 . V_43 ( & V_2 -> V_7 ) ;
break;
case V_44 :
F_21 ( & V_24 . V_45 ) ;
F_8 ( V_2 ) ;
V_2 -> V_7 . V_43 ( & V_2 -> V_7 ) ;
break;
case V_46 :
F_38 ( & V_2 -> V_11 ,
F_33 , F_35 ) ;
F_21 ( & V_24 . V_47 ) ;
V_2 -> V_7 . V_36 = V_37 ;
F_9 ( V_2 ) ;
V_2 -> V_7 . V_43 ( & V_2 -> V_7 ) ;
break;
case V_48 :
V_2 -> V_7 . V_36 = V_49 ;
V_2 -> V_7 . V_43 ( & V_2 -> V_7 ) ;
break;
case V_50 :
F_21 ( & V_24 . V_51 ) ;
V_2 -> V_7 . V_52 = V_53 ;
V_2 -> V_7 . V_36 = V_49 ;
V_2 -> V_7 . V_54 = V_55 ;
F_9 ( V_2 ) ;
V_2 -> V_7 . V_43 ( & V_2 -> V_7 ) ;
break;
case V_56 :
F_21 ( & V_24 . V_57 ) ;
V_2 -> V_7 . V_54 = V_55 ;
V_2 -> V_7 . V_52 = V_58 ;
F_6 ( V_2 ) ;
V_2 -> V_7 . V_59 ( & V_2 -> V_7 ) ;
break;
default:
F_20 ( L_3 , V_39 ) ;
}
}
static void F_39 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
if ( F_1 ( V_2 ) )
return;
if ( F_18 ( & V_7 -> V_22 ) <= F_15 ( V_2 ) ) {
F_21 ( & V_24 . V_60 ) ;
F_6 ( V_2 ) ;
F_16 ( V_7 , V_61 ) ;
}
}
static int F_40 ( struct V_62 * V_63 , struct V_64 * V_6 ,
struct V_65 * V_66 , T_1 V_28 , int V_18 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_14 * V_15 ;
int V_67 ;
int V_68 ;
V_67 = - V_69 ;
if ( V_66 -> V_70 & V_71 )
goto V_72;
V_15 = F_41 ( V_7 , V_18 , 0 , & V_67 ) ;
if ( ! V_15 )
goto V_72;
V_68 = V_15 -> V_28 ;
if ( V_28 < V_68 ) {
V_66 -> V_70 |= V_73 ;
V_68 = V_28 ;
}
V_67 = F_42 ( V_15 , 0 , V_66 -> V_74 , V_68 ) ;
if ( V_67 )
goto V_75;
V_67 = ( V_18 & V_73 ) ? V_15 -> V_28 : V_68 ;
V_75:
F_43 ( V_7 , V_15 ) ;
F_39 ( V_7 ) ;
return V_67 ;
V_72:
return V_67 ;
}
static long F_44 ( struct V_6 * V_7 , long V_76 )
{
F_45 ( V_77 ) ;
F_46 ( V_7 ) ;
for (; ; ) {
F_47 ( F_48 ( V_7 ) , & V_77 , V_78 ) ;
if ( ! F_49 ( & V_7 -> V_21 ) ||
V_7 -> V_52 ||
V_7 -> V_36 != V_37 ||
F_26 ( V_7 , V_30 ) ||
( V_7 -> V_54 & V_79 ) ||
F_50 ( V_80 ) ||
! V_76 )
break;
F_7 ( V_81 , & V_7 -> V_82 -> V_18 ) ;
F_51 ( V_7 ) ;
V_76 = F_52 ( V_76 ) ;
F_46 ( V_7 ) ;
F_5 ( V_81 , & V_7 -> V_82 -> V_18 ) ;
}
F_53 ( F_48 ( V_7 ) , & V_77 ) ;
F_51 ( V_7 ) ;
return V_76 ;
}
static int F_54 ( struct V_62 * V_63 , struct V_64 * V_6 ,
struct V_65 * V_83 , T_1 V_84 ,
int V_18 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
int V_85 = 0 ;
int V_86 ;
int V_16 = 0 ;
long V_76 ;
V_16 = - V_69 ;
if ( V_18 & V_71 )
goto V_87;
V_83 -> V_88 = 0 ;
V_16 = - V_89 ;
if ( V_7 -> V_36 == V_90 )
goto V_87;
F_10 ( V_7 ) ;
V_86 = F_55 ( V_7 , V_18 & V_91 , V_84 ) ;
V_76 = F_56 ( V_7 , V_18 & V_92 ) ;
do {
int V_93 ;
struct V_14 * V_15 ;
F_46 ( V_7 ) ;
V_15 = F_57 ( & V_7 -> V_21 ) ;
F_39 ( V_7 ) ;
if ( V_15 == NULL ) {
if ( V_85 >= V_86 )
goto V_94;
V_16 = F_58 ( V_7 ) ;
if ( V_16 )
goto V_94;
V_16 = - V_58 ;
if ( V_7 -> V_54 & V_79 )
goto V_94;
V_16 = - V_95 ;
if ( V_7 -> V_36 != V_37 )
goto V_94;
if ( F_26 ( V_7 , V_30 ) )
goto V_94;
F_51 ( V_7 ) ;
V_16 = - V_89 ;
if ( ! V_76 )
break;
F_13 ( V_7 ) ;
V_76 = F_44 ( V_7 , V_76 ) ;
if ( F_50 ( V_80 ) ) {
V_16 = F_59 ( V_76 ) ;
goto V_87;
}
F_10 ( V_7 ) ;
continue;
V_94:
F_51 ( V_7 ) ;
break;
}
F_51 ( V_7 ) ;
V_93 = F_60 (unsigned int, skb->len, size) ;
if ( F_61 ( V_83 -> V_74 , V_15 -> V_96 , V_93 ) ) {
F_62 ( & V_7 -> V_21 , V_15 ) ;
if ( V_85 == 0 )
V_85 = - V_97 ;
break;
}
V_85 += V_93 ;
V_84 -= V_93 ;
if ( ! ( V_18 & V_98 ) ) {
F_63 ( V_15 , V_93 ) ;
if ( V_15 -> V_28 ) {
F_62 ( & V_7 -> V_21 , V_15 ) ;
break;
}
F_29 ( V_15 ) ;
} else {
F_62 ( & V_7 -> V_21 , V_15 ) ;
break;
}
} while ( V_84 );
F_13 ( V_7 ) ;
V_87:
return V_85 ? : V_16 ;
}
static long F_64 ( struct V_1 * V_2 ,
int V_99 , long V_76 , int * V_16 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
F_45 ( V_77 ) ;
for (; ; ) {
* V_16 = 0 ;
if ( F_3 ( V_2 ) &&
( ! V_99 || F_65 ( & V_2 -> V_7 ) ) )
break;
* V_16 = - V_100 ;
if ( ! V_76 )
break;
* V_16 = - V_101 ;
if ( F_50 ( V_80 ) )
break;
F_47 ( F_48 ( V_7 ) , & V_77 , V_78 ) ;
* V_16 = - V_58 ;
if ( V_7 -> V_54 & V_55 )
break;
* V_16 = - V_7 -> V_52 ;
if ( V_7 -> V_52 )
break;
* V_16 = - V_95 ;
if ( V_2 -> V_7 . V_36 != V_37 )
break;
V_76 = F_52 ( V_76 ) ;
}
F_53 ( F_48 ( V_7 ) , & V_77 ) ;
return V_76 ;
}
static int F_66 ( struct V_14 * V_15 , struct V_1 * V_2 ,
int V_102 , long V_76 )
{
struct V_34 * V_35 ;
V_35 = F_67 ( V_103 , V_15 ) ;
memset ( V_15 -> V_104 , 0 , sizeof( struct V_105 ) ) ;
if ( V_2 -> V_11 . V_12 == NULL ) {
F_29 ( V_15 ) ;
return - V_106 ;
}
return V_2 -> V_11 . V_12 -> V_107 ( V_2 -> V_11 . V_12 , V_35 ) ;
}
static int F_68 ( struct V_62 * V_62 , struct V_64 * V_6 ,
struct V_65 * V_83 , T_1 V_28 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_108 ;
int V_67 = 0 ;
struct V_14 * V_15 = NULL ;
int V_102 ;
long V_76 ;
F_69 ( V_2 ) ;
V_67 = F_58 ( V_7 ) ;
if ( V_67 )
goto V_16;
V_67 = - V_69 ;
if ( V_83 -> V_70 & V_71 )
goto V_16;
V_67 = - V_69 ;
if ( V_83 -> V_88 )
goto V_16;
V_67 = - V_106 ;
if ( F_32 ( V_83 -> V_74 -> V_109 == NULL ) )
goto V_16;
V_102 = V_83 -> V_70 & V_92 ;
V_76 = F_70 ( V_7 , V_102 ) ;
V_76 = F_64 ( F_11 ( V_7 , struct V_1 , V_7 ) ,
1 , V_76 , & V_67 ) ;
if ( V_67 )
goto V_16;
V_67 = - V_95 ;
if ( V_2 -> V_7 . V_36 != V_37 ||
F_26 ( V_7 , V_30 ) ||
( V_7 -> V_54 & V_79 ) )
goto V_16;
V_67 = - V_110 ;
if ( V_28 > V_2 -> V_111 && V_2 -> V_7 . V_112 != V_113 )
goto V_16;
V_108 = V_28 + V_2 -> V_114 + V_2 -> V_115 ;
V_67 = - V_116 ;
V_15 = F_71 ( V_7 , V_108 , V_102 , & V_67 ) ;
if ( ! V_15 || F_72 ( V_15 ) < V_108 )
goto V_16;
F_73 ( V_15 , V_2 -> V_114 ) ;
V_67 = F_74 ( F_75 ( V_15 , V_28 ) , V_83 -> V_74 , V_28 ) ;
if ( V_67 )
goto V_16;
V_67 = F_66 ( V_15 , V_2 , V_102 , V_76 ) ;
if ( V_67 < 0 )
return V_67 ;
return V_28 ;
V_16:
F_29 ( V_15 ) ;
return V_67 ;
}
static int F_76 ( struct V_62 * V_62 , struct V_64 * V_6 ,
struct V_65 * V_83 , T_1 V_28 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_16 , V_84 ;
struct V_14 * V_15 ;
int V_117 = 0 ;
long V_76 ;
V_16 = - V_69 ;
if ( F_32 ( V_83 -> V_70 & V_71 ) )
goto V_118;
if ( F_32 ( V_83 -> V_88 ) )
goto V_118;
V_76 = F_70 ( V_7 , V_83 -> V_70 & V_92 ) ;
V_76 = F_64 ( V_2 , 1 , V_76 , & V_16 ) ;
if ( F_32 ( V_7 -> V_54 & V_119 ) )
goto V_120;
while ( V_117 < V_28 ) {
V_84 = V_28 - V_117 ;
if ( V_84 > V_2 -> V_111 )
V_84 = V_2 -> V_111 ;
if ( V_84 > ( ( V_7 -> V_121 >> 1 ) - 64 ) )
V_84 = ( V_7 -> V_121 >> 1 ) - 64 ;
if ( V_84 > V_122 )
V_84 = V_122 ;
V_15 = F_71 ( V_7 ,
V_84 + V_2 -> V_114 +
V_2 -> V_115 ,
V_83 -> V_70 & V_92 ,
& V_16 ) ;
if ( V_15 == NULL )
goto V_118;
F_73 ( V_15 , V_2 -> V_114 ) ;
V_84 = F_60 ( int , V_84 , F_72 ( V_15 ) ) ;
V_16 = F_74 ( F_75 ( V_15 , V_84 ) , V_83 -> V_74 , V_84 ) ;
if ( V_16 ) {
F_29 ( V_15 ) ;
goto V_118;
}
V_16 = F_66 ( V_15 , V_2 ,
V_83 -> V_70 & V_92 , V_76 ) ;
if ( V_16 < 0 )
goto V_120;
V_117 += V_84 ;
}
return V_117 ;
V_120:
if ( V_117 == 0 && ! ( V_83 -> V_70 & V_123 ) )
F_77 ( V_124 , V_80 , 0 ) ;
V_16 = - V_95 ;
V_118:
return V_117 ? : V_16 ;
}
static int F_78 ( struct V_64 * V_6 ,
int V_125 , int V_126 , char T_2 * V_127 , unsigned int V_128 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_129 ;
if ( V_2 -> V_7 . V_82 -> V_130 != V_131 )
return - V_132 ;
switch ( V_126 ) {
case V_133 :
if ( V_128 < sizeof( int ) )
return - V_106 ;
if ( V_125 != V_134 )
goto V_135;
if ( F_79 ( & V_129 , V_127 , sizeof( int ) ) )
return - V_106 ;
F_46 ( & ( V_2 -> V_7 ) ) ;
V_2 -> V_136 . V_137 = V_129 ;
F_51 ( & V_2 -> V_7 ) ;
return 0 ;
case V_138 :
if ( V_125 != V_134 )
goto V_135;
if ( V_2 -> V_7 . V_112 != V_139 )
return - V_132 ;
F_46 ( & ( V_2 -> V_7 ) ) ;
if ( V_128 > sizeof( V_2 -> V_136 . V_140 . V_96 ) ||
F_79 ( & V_2 -> V_136 . V_140 . V_96 , V_127 , V_128 ) ) {
F_51 ( & V_2 -> V_7 ) ;
return - V_106 ;
}
V_2 -> V_136 . V_140 . V_84 = V_128 ;
F_51 ( & V_2 -> V_7 ) ;
return 0 ;
default:
return - V_132 ;
}
return 0 ;
V_135:
return - V_132 ;
}
static int F_80 ( struct V_64 * V_6 , struct V_141 * V_142 ,
int V_143 , int V_18 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
long V_76 ;
int V_16 ;
int V_144 , V_114 , V_115 ;
unsigned int V_145 ;
struct V_146 * V_27 ;
F_46 ( V_7 ) ;
V_16 = - V_147 ;
if ( V_142 -> V_148 != V_149 )
goto V_87;
switch ( V_6 -> V_130 ) {
case V_131 :
F_69 ( V_7 -> V_36 == V_49 ) ;
break;
case V_150 :
switch ( V_7 -> V_36 ) {
case V_37 :
V_6 -> V_130 = V_151 ;
V_16 = - V_152 ;
goto V_87;
case V_49 :
break;
case V_90 :
V_16 = - V_153 ;
if ( V_18 & V_154 )
goto V_87;
goto V_155;
}
break;
case V_151 :
F_69 ( V_7 -> V_36 == V_37 ||
V_7 -> V_36 == V_49 ) ;
if ( V_7 -> V_54 & V_55 ) {
F_81 ( F_82 ( V_7 ) , & V_2 -> V_11 ) ;
F_83 ( & V_2 -> V_11 ) ;
break;
}
V_16 = - V_152 ;
goto V_87;
case V_156 :
case V_157 :
F_69 ( 1 ) ;
break;
}
V_7 -> V_36 = V_49 ;
V_6 -> V_130 = V_131 ;
F_84 ( & V_2 -> V_7 ) ;
V_16 = - V_106 ;
if ( V_143 != sizeof( struct V_158 ) )
goto V_87;
memcpy ( & V_2 -> V_136 . V_141 , V_142 ,
sizeof( struct V_158 ) ) ;
V_6 -> V_130 = V_150 ;
V_7 -> V_36 = V_90 ;
if ( V_2 -> V_7 . V_159 > V_160 )
V_2 -> V_136 . V_161 = V_160 ;
else if ( V_2 -> V_7 . V_159 < V_162 )
V_2 -> V_136 . V_161 = V_162 ;
else
V_2 -> V_136 . V_161 = V_2 -> V_7 . V_159 ;
V_2 -> V_136 . V_144 = V_2 -> V_7 . V_163 ;
F_21 ( & V_24 . V_164 ) ;
V_2 -> V_11 . V_165 = F_30 ;
V_16 = F_85 ( F_82 ( V_7 ) , & V_2 -> V_136 ,
& V_2 -> V_11 , & V_144 , & V_114 , & V_115 ) ;
if ( V_16 < 0 ) {
V_2 -> V_7 . V_82 -> V_130 = V_131 ;
V_2 -> V_7 . V_36 = V_49 ;
goto V_87;
}
V_16 = - V_166 ;
F_86 () ;
V_27 = F_87 ( F_82 ( V_7 ) , V_144 ) ;
if ( ! V_27 ) {
F_88 () ;
goto V_87;
}
V_2 -> V_114 = F_89 ( V_27 , V_114 ) ;
V_145 = V_27 -> V_145 ;
F_88 () ;
V_2 -> V_115 = V_115 ;
V_2 -> V_111 = V_145 - ( V_114 + V_115 ) ;
if ( V_2 -> V_111 < 1 ) {
F_90 ( L_4 , V_27 -> V_145 ) ;
V_16 = - V_166 ;
goto V_87;
}
V_16 = - V_167 ;
V_155:
if ( V_7 -> V_36 != V_37 && ( V_18 & V_154 ) )
goto V_87;
V_76 = F_70 ( V_7 , V_18 & V_154 ) ;
F_51 ( V_7 ) ;
V_16 = - V_101 ;
V_76 = F_91 ( * F_48 ( V_7 ) ,
V_7 -> V_36 != V_90 ,
V_76 ) ;
F_46 ( V_7 ) ;
if ( V_76 < 0 )
goto V_87;
V_16 = - V_100 ;
if ( V_76 == 0 && V_7 -> V_36 != V_37 )
goto V_87;
if ( V_7 -> V_36 != V_37 ) {
V_6 -> V_130 = V_131 ;
V_16 = F_58 ( V_7 ) ;
if ( ! V_16 )
V_16 = - V_53 ;
goto V_87;
}
V_6 -> V_130 = V_151 ;
V_16 = 0 ;
V_87:
F_51 ( V_7 ) ;
return V_16 ;
}
static int F_92 ( struct V_64 * V_6 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
if ( ! V_7 )
return 0 ;
F_8 ( V_2 ) ;
F_93 ( & V_7 -> V_21 . V_29 ) ;
F_94 ( V_7 , V_30 ) ;
F_95 ( & V_7 -> V_21 . V_29 ) ;
V_6 -> V_7 = NULL ;
F_21 ( & V_24 . V_168 ) ;
F_96 ( F_97 ( V_2 -> V_169 ) ) ;
if ( V_2 -> V_169 != NULL )
F_98 ( V_2 -> V_169 ) ;
F_46 ( & ( V_2 -> V_7 ) ) ;
V_7 -> V_36 = V_49 ;
V_7 -> V_54 = V_55 ;
F_81 ( F_82 ( V_7 ) , & V_2 -> V_11 ) ;
V_2 -> V_7 . V_82 -> V_130 = V_156 ;
F_99 ( F_48 ( V_7 ) , V_170 | V_171 ) ;
F_100 ( V_7 ) ;
F_84 ( & V_2 -> V_7 ) ;
F_51 ( V_7 ) ;
F_36 ( V_7 ) ;
return 0 ;
}
static unsigned int F_101 ( struct V_172 * V_172 ,
struct V_64 * V_6 , T_3 * V_77 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
unsigned int V_173 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
F_102 ( V_172 , F_48 ( V_7 ) , V_77 ) ;
V_173 = 0 ;
if ( V_7 -> V_52 )
V_173 |= V_170 ;
if ( V_7 -> V_54 == V_55 )
V_173 |= V_171 ;
if ( V_7 -> V_54 & V_79 )
V_173 |= V_174 ;
if ( ! F_49 ( & V_7 -> V_21 ) ||
( V_7 -> V_54 & V_79 ) )
V_173 |= V_175 | V_176 ;
if ( F_65 ( V_7 ) && F_3 ( V_2 ) )
V_173 |= V_177 | V_178 | V_179 ;
return V_173 ;
}
static void F_103 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
F_69 ( ! F_18 ( & V_7 -> V_180 ) ) ;
F_69 ( F_104 ( V_7 ) ) ;
F_69 ( ! V_7 -> V_82 ) ;
if ( ! F_26 ( V_7 , V_30 ) ) {
F_20 ( L_5 , V_7 ) ;
return;
}
F_84 ( & V_2 -> V_7 ) ;
F_105 ( & V_24 . V_181 ) ;
F_83 ( & V_2 -> V_11 ) ;
}
static int F_106 ( struct V_182 * V_182 , struct V_64 * V_6 , int V_183 ,
int V_184 )
{
int V_185 ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
static struct V_186 V_187 = { . V_188 = L_6 ,
. V_189 = V_190 ,
. V_191 = sizeof( struct V_1 ) ,
} ;
if ( ! F_107 ( V_192 ) && ! F_107 ( V_193 ) )
return - V_194 ;
if ( V_6 -> type == V_195 )
V_6 -> V_196 = & V_197 ;
else if ( V_6 -> type == V_198 )
V_6 -> V_196 = & V_199 ;
else
return - V_200 ;
if ( V_183 < 0 || V_183 >= V_201 )
return - V_202 ;
V_7 = F_108 ( V_182 , V_203 , V_204 , & V_187 ) ;
if ( ! V_7 )
return - V_116 ;
V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
V_7 -> V_112 = ( unsigned char ) V_183 ;
F_46 ( & ( V_2 -> V_7 ) ) ;
F_109 ( V_6 , V_7 ) ;
V_7 -> V_205 = F_103 ;
F_110 ( & V_2 -> V_8 ) ;
V_2 -> V_11 . V_206 = F_37 ;
V_2 -> V_7 . V_82 -> V_130 = V_131 ;
V_2 -> V_7 . V_36 = V_49 ;
F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
V_2 -> V_7 . V_159 = V_207 ;
V_2 -> V_136 . V_137 = V_208 ;
V_2 -> V_136 . V_183 = V_183 ;
F_21 ( & V_24 . V_181 ) ;
V_185 = F_21 ( & V_24 . V_209 ) ;
#ifdef F_111
if ( ! F_97 ( V_210 ) ) {
snprintf ( V_2 -> V_188 , sizeof( V_2 -> V_188 ) , L_7 , V_185 ) ;
V_2 -> V_169 =
F_112 ( V_2 -> V_188 , V_210 ) ;
F_113 ( L_8 , V_211 | V_212 ,
V_2 -> V_169 ,
( V_213 * ) & V_2 -> V_7 . V_36 ) ;
F_113 ( L_9 , V_211 | V_212 ,
V_2 -> V_169 , & V_2 -> V_4 ) ;
F_113 ( L_10 , V_211 | V_212 ,
V_2 -> V_169 ,
( V_213 * ) & V_2 -> V_7 . V_22 ) ;
F_113 ( L_11 , V_211 | V_212 ,
V_2 -> V_169 ,
( V_213 * ) & V_2 -> V_7 . V_180 ) ;
F_113 ( L_12 , V_211 | V_212 ,
V_2 -> V_169 ,
( V_213 * ) & V_2 -> V_11 . V_214 ) ;
}
#endif
F_51 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_114 ( void )
{
int V_16 = F_115 ( & V_215 ) ;
if ( ! V_16 )
return V_16 ;
return 0 ;
}
static int T_4 F_116 ( void )
{
#ifdef F_111
V_210 = F_112 ( L_13 , NULL ) ;
if ( ! F_97 ( V_210 ) ) {
F_113 ( L_14 , V_211 | V_212 ,
V_210 ,
( V_213 * ) & V_24 . V_181 ) ;
F_113 ( L_15 , V_211 | V_212 ,
V_210 ,
( V_213 * ) & V_24 . V_209 ) ;
F_113 ( L_16 , V_211 | V_212 ,
V_210 ,
( V_213 * ) & V_24 . V_164 ) ;
F_113 ( L_17 , V_211 | V_212 ,
V_210 ,
( V_213 * ) & V_24 . V_47 ) ;
F_113 ( L_18 , V_211 | V_212 ,
V_210 ,
( V_213 * ) & V_24 . V_51 ) ;
F_113 ( L_19 , V_211 | V_212 ,
V_210 ,
( V_213 * ) & V_24 . V_168 ) ;
F_113 ( L_20 ,
V_211 | V_212 , V_210 ,
( V_213 * ) & V_24 . V_57 ) ;
F_113 ( L_21 , V_211 | V_212 ,
V_210 ,
( V_213 * ) & V_24 . V_45 ) ;
F_113 ( L_22 , V_211 | V_212 ,
V_210 ,
( V_213 * ) & V_24 . V_42 ) ;
F_113 ( L_23 , V_211 | V_212 ,
V_210 ,
( V_213 * ) & V_24 . V_25 ) ;
F_113 ( L_24 , V_211 | V_212 ,
V_210 ,
( V_213 * ) & V_24 . V_60 ) ;
}
#endif
return F_114 () ;
}
static void T_5 F_117 ( void )
{
F_118 ( V_203 ) ;
if ( V_210 != NULL )
F_98 ( V_210 ) ;
}
