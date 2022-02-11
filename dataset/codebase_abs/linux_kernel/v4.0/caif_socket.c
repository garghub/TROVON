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
static int F_39 ( struct V_52 * V_53 , struct V_54 * V_6 ,
struct V_55 * V_56 , T_1 V_57 , int V_17 )
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
V_7 -> V_45 ||
V_7 -> V_32 != V_33 ||
F_24 ( V_7 , V_26 ) ||
( V_7 -> V_41 & V_69 ) ||
F_49 ( V_70 ) ||
! V_66 )
break;
F_7 ( V_71 , & V_7 -> V_72 -> V_17 ) ;
F_50 ( V_7 ) ;
V_66 = F_51 ( V_66 ) ;
F_45 ( V_7 ) ;
F_5 ( V_71 , & V_7 -> V_72 -> V_17 ) ;
}
F_52 ( F_47 ( V_7 ) , & V_67 ) ;
F_50 ( V_7 ) ;
return V_66 ;
}
static int F_53 ( struct V_52 * V_53 , struct V_54 * V_6 ,
struct V_55 * V_73 , T_1 V_74 ,
int V_17 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
int V_75 = 0 ;
int V_76 ;
int V_16 = 0 ;
long V_66 ;
V_16 = - V_60 ;
if ( V_17 & V_61 )
goto V_77;
V_16 = - V_78 ;
if ( V_7 -> V_32 == V_79 )
goto V_77;
F_10 ( V_7 ) ;
V_76 = F_54 ( V_7 , V_17 & V_80 , V_74 ) ;
V_66 = F_55 ( V_7 , V_17 & V_81 ) ;
do {
int V_82 ;
struct V_14 * V_15 ;
F_45 ( V_7 ) ;
V_15 = F_56 ( & V_7 -> V_20 ) ;
F_38 ( V_7 ) ;
if ( V_15 == NULL ) {
if ( V_75 >= V_76 )
goto V_83;
V_16 = F_57 ( V_7 ) ;
if ( V_16 )
goto V_83;
V_16 = - V_49 ;
if ( V_7 -> V_41 & V_69 )
goto V_83;
V_16 = - V_84 ;
if ( V_7 -> V_32 != V_33 )
goto V_83;
if ( F_24 ( V_7 , V_26 ) )
goto V_83;
F_50 ( V_7 ) ;
V_16 = - V_78 ;
if ( ! V_66 )
break;
F_13 ( V_7 ) ;
V_66 = F_43 ( V_7 , V_66 ) ;
if ( F_49 ( V_70 ) ) {
V_16 = F_58 ( V_66 ) ;
goto V_77;
}
F_10 ( V_7 ) ;
continue;
V_83:
F_50 ( V_7 ) ;
break;
}
F_50 ( V_7 ) ;
V_82 = F_59 (unsigned int, skb->len, size) ;
if ( F_60 ( V_73 , V_15 -> V_85 , V_82 ) ) {
F_61 ( & V_7 -> V_20 , V_15 ) ;
if ( V_75 == 0 )
V_75 = - V_86 ;
break;
}
V_75 += V_82 ;
V_74 -= V_82 ;
if ( ! ( V_17 & V_87 ) ) {
F_62 ( V_15 , V_82 ) ;
if ( V_15 -> V_57 ) {
F_61 ( & V_7 -> V_20 , V_15 ) ;
break;
}
F_27 ( V_15 ) ;
} else {
F_61 ( & V_7 -> V_20 , V_15 ) ;
break;
}
} while ( V_74 );
F_13 ( V_7 ) ;
V_77:
return V_75 ? : V_16 ;
}
static long F_63 ( struct V_1 * V_2 ,
int V_88 , long V_66 , int * V_16 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
F_44 ( V_67 ) ;
for (; ; ) {
* V_16 = 0 ;
if ( F_3 ( V_2 ) &&
( ! V_88 || F_64 ( & V_2 -> V_7 ) ) )
break;
* V_16 = - V_89 ;
if ( ! V_66 )
break;
* V_16 = - V_90 ;
if ( F_49 ( V_70 ) )
break;
F_46 ( F_47 ( V_7 ) , & V_67 , V_68 ) ;
* V_16 = - V_49 ;
if ( V_7 -> V_41 & V_47 )
break;
* V_16 = - V_7 -> V_45 ;
if ( V_7 -> V_45 )
break;
* V_16 = - V_84 ;
if ( V_2 -> V_7 . V_32 != V_33 )
break;
V_66 = F_51 ( V_66 ) ;
}
F_52 ( F_47 ( V_7 ) , & V_67 ) ;
return V_66 ;
}
static int F_65 ( struct V_14 * V_15 , struct V_1 * V_2 ,
int V_91 , long V_66 )
{
struct V_30 * V_31 ;
V_31 = F_66 ( V_92 , V_15 ) ;
memset ( V_15 -> V_93 , 0 , sizeof( struct V_94 ) ) ;
F_67 ( V_31 , V_2 -> V_7 . V_95 ) ;
if ( V_2 -> V_11 . V_12 == NULL ) {
F_27 ( V_15 ) ;
return - V_96 ;
}
return V_2 -> V_11 . V_12 -> V_97 ( V_2 -> V_11 . V_12 , V_31 ) ;
}
static int F_68 ( struct V_52 * V_52 , struct V_54 * V_6 ,
struct V_55 * V_73 , T_1 V_57 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_98 ;
int V_58 = 0 ;
struct V_14 * V_15 = NULL ;
int V_91 ;
long V_66 ;
F_69 ( V_2 ) ;
V_58 = F_57 ( V_7 ) ;
if ( V_58 )
goto V_16;
V_58 = - V_60 ;
if ( V_73 -> V_63 & V_61 )
goto V_16;
V_58 = - V_60 ;
if ( V_73 -> V_99 )
goto V_16;
V_58 = - V_96 ;
if ( F_30 ( V_73 -> V_100 . V_101 -> V_102 == NULL ) )
goto V_16;
V_91 = V_73 -> V_63 & V_81 ;
V_66 = F_70 ( V_7 , V_91 ) ;
V_66 = F_63 ( F_11 ( V_7 , struct V_1 , V_7 ) ,
1 , V_66 , & V_58 ) ;
if ( V_58 )
goto V_16;
V_58 = - V_84 ;
if ( V_2 -> V_7 . V_32 != V_33 ||
F_24 ( V_7 , V_26 ) ||
( V_7 -> V_41 & V_69 ) )
goto V_16;
V_58 = - V_103 ;
if ( V_57 > V_2 -> V_104 && V_2 -> V_7 . V_105 != V_106 )
goto V_16;
V_98 = V_57 + V_2 -> V_107 + V_2 -> V_108 ;
V_58 = - V_109 ;
V_15 = F_71 ( V_7 , V_98 , V_91 , & V_58 ) ;
if ( ! V_15 || F_72 ( V_15 ) < V_98 )
goto V_16;
F_73 ( V_15 , V_2 -> V_107 ) ;
V_58 = F_74 ( F_75 ( V_15 , V_57 ) , V_73 , V_57 ) ;
if ( V_58 )
goto V_16;
V_58 = F_65 ( V_15 , V_2 , V_91 , V_66 ) ;
if ( V_58 < 0 )
return V_58 ;
return V_57 ;
V_16:
F_27 ( V_15 ) ;
return V_58 ;
}
static int F_76 ( struct V_52 * V_52 , struct V_54 * V_6 ,
struct V_55 * V_73 , T_1 V_57 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_16 , V_74 ;
struct V_14 * V_15 ;
int V_110 = 0 ;
long V_66 ;
V_16 = - V_60 ;
if ( F_30 ( V_73 -> V_63 & V_61 ) )
goto V_111;
if ( F_30 ( V_73 -> V_99 ) )
goto V_111;
V_66 = F_70 ( V_7 , V_73 -> V_63 & V_81 ) ;
V_66 = F_63 ( V_2 , 1 , V_66 , & V_16 ) ;
if ( F_30 ( V_7 -> V_41 & V_112 ) )
goto V_113;
while ( V_110 < V_57 ) {
V_74 = V_57 - V_110 ;
if ( V_74 > V_2 -> V_104 )
V_74 = V_2 -> V_104 ;
if ( V_74 > ( ( V_7 -> V_114 >> 1 ) - 64 ) )
V_74 = ( V_7 -> V_114 >> 1 ) - 64 ;
if ( V_74 > V_115 )
V_74 = V_115 ;
V_15 = F_71 ( V_7 ,
V_74 + V_2 -> V_107 +
V_2 -> V_108 ,
V_73 -> V_63 & V_81 ,
& V_16 ) ;
if ( V_15 == NULL )
goto V_111;
F_73 ( V_15 , V_2 -> V_107 ) ;
V_74 = F_59 ( int , V_74 , F_72 ( V_15 ) ) ;
V_16 = F_74 ( F_75 ( V_15 , V_74 ) , V_73 , V_74 ) ;
if ( V_16 ) {
F_27 ( V_15 ) ;
goto V_111;
}
V_16 = F_65 ( V_15 , V_2 ,
V_73 -> V_63 & V_81 , V_66 ) ;
if ( V_16 < 0 )
goto V_113;
V_110 += V_74 ;
}
return V_110 ;
V_113:
if ( V_110 == 0 && ! ( V_73 -> V_63 & V_116 ) )
F_77 ( V_117 , V_70 , 0 ) ;
V_16 = - V_84 ;
V_111:
return V_110 ? : V_16 ;
}
static int F_78 ( struct V_54 * V_6 ,
int V_118 , int V_119 , char T_2 * V_120 , unsigned int V_121 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
int V_122 ;
if ( V_2 -> V_7 . V_72 -> V_123 != V_124 )
return - V_125 ;
switch ( V_119 ) {
case V_126 :
if ( V_121 < sizeof( int ) )
return - V_96 ;
if ( V_118 != V_127 )
goto V_128;
if ( F_79 ( & V_122 , V_120 , sizeof( int ) ) )
return - V_96 ;
F_45 ( & ( V_2 -> V_7 ) ) ;
V_2 -> V_129 . V_130 = V_122 ;
F_50 ( & V_2 -> V_7 ) ;
return 0 ;
case V_131 :
if ( V_118 != V_127 )
goto V_128;
if ( V_2 -> V_7 . V_105 != V_132 )
return - V_125 ;
F_45 ( & ( V_2 -> V_7 ) ) ;
if ( V_121 > sizeof( V_2 -> V_129 . V_133 . V_85 ) ||
F_79 ( & V_2 -> V_129 . V_133 . V_85 , V_120 , V_121 ) ) {
F_50 ( & V_2 -> V_7 ) ;
return - V_96 ;
}
V_2 -> V_129 . V_133 . V_74 = V_121 ;
F_50 ( & V_2 -> V_7 ) ;
return 0 ;
default:
return - V_125 ;
}
return 0 ;
V_128:
return - V_125 ;
}
static int F_80 ( struct V_54 * V_6 , struct V_134 * V_135 ,
int V_136 , int V_17 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
long V_66 ;
int V_16 ;
int V_137 , V_107 , V_108 ;
unsigned int V_138 ;
struct V_139 * V_24 ;
F_45 ( V_7 ) ;
V_16 = - V_140 ;
if ( V_135 -> V_141 != V_142 )
goto V_77;
switch ( V_6 -> V_123 ) {
case V_124 :
F_69 ( V_7 -> V_32 == V_43 ) ;
break;
case V_143 :
switch ( V_7 -> V_32 ) {
case V_33 :
V_6 -> V_123 = V_144 ;
V_16 = - V_145 ;
goto V_77;
case V_43 :
break;
case V_79 :
V_16 = - V_146 ;
if ( V_17 & V_147 )
goto V_77;
goto V_148;
}
break;
case V_144 :
F_69 ( V_7 -> V_32 == V_33 ||
V_7 -> V_32 == V_43 ) ;
if ( V_7 -> V_41 & V_47 ) {
F_81 ( F_82 ( V_7 ) , & V_2 -> V_11 ) ;
F_83 ( & V_2 -> V_11 ) ;
break;
}
V_16 = - V_145 ;
goto V_77;
case V_149 :
case V_150 :
F_69 ( 1 ) ;
break;
}
V_7 -> V_32 = V_43 ;
V_6 -> V_123 = V_124 ;
F_84 ( & V_2 -> V_7 ) ;
V_16 = - V_96 ;
if ( V_136 != sizeof( struct V_151 ) )
goto V_77;
memcpy ( & V_2 -> V_129 . V_134 , V_135 ,
sizeof( struct V_151 ) ) ;
V_6 -> V_123 = V_143 ;
V_7 -> V_32 = V_79 ;
if ( V_2 -> V_7 . V_95 > V_152 )
V_2 -> V_129 . V_153 = V_152 ;
else if ( V_2 -> V_7 . V_95 < V_154 )
V_2 -> V_129 . V_153 = V_154 ;
else
V_2 -> V_129 . V_153 = V_2 -> V_7 . V_95 ;
V_2 -> V_129 . V_137 = V_2 -> V_7 . V_155 ;
V_2 -> V_11 . V_156 = F_28 ;
V_16 = F_85 ( F_82 ( V_7 ) , & V_2 -> V_129 ,
& V_2 -> V_11 , & V_137 , & V_107 , & V_108 ) ;
if ( V_16 < 0 ) {
V_2 -> V_7 . V_72 -> V_123 = V_124 ;
V_2 -> V_7 . V_32 = V_43 ;
goto V_77;
}
V_16 = - V_157 ;
F_86 () ;
V_24 = F_87 ( F_82 ( V_7 ) , V_137 ) ;
if ( ! V_24 ) {
F_88 () ;
goto V_77;
}
V_2 -> V_107 = F_89 ( V_24 , V_107 ) ;
V_138 = V_24 -> V_138 ;
F_88 () ;
V_2 -> V_108 = V_108 ;
V_2 -> V_104 = V_138 - ( V_107 + V_108 ) ;
if ( V_2 -> V_104 < 1 ) {
F_90 ( L_4 , V_24 -> V_138 ) ;
V_16 = - V_157 ;
goto V_77;
}
V_16 = - V_158 ;
V_148:
if ( V_7 -> V_32 != V_33 && ( V_17 & V_147 ) )
goto V_77;
V_66 = F_70 ( V_7 , V_17 & V_147 ) ;
F_50 ( V_7 ) ;
V_16 = - V_90 ;
V_66 = F_91 ( * F_47 ( V_7 ) ,
V_7 -> V_32 != V_79 ,
V_66 ) ;
F_45 ( V_7 ) ;
if ( V_66 < 0 )
goto V_77;
V_16 = - V_89 ;
if ( V_66 == 0 && V_7 -> V_32 != V_33 )
goto V_77;
if ( V_7 -> V_32 != V_33 ) {
V_6 -> V_123 = V_124 ;
V_16 = F_57 ( V_7 ) ;
if ( ! V_16 )
V_16 = - V_46 ;
goto V_77;
}
V_6 -> V_123 = V_144 ;
V_16 = 0 ;
V_77:
F_50 ( V_7 ) ;
return V_16 ;
}
static int F_92 ( struct V_54 * V_6 )
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
F_96 ( F_97 ( V_2 -> V_159 ) ) ;
F_98 ( V_2 -> V_159 ) ;
F_45 ( & ( V_2 -> V_7 ) ) ;
V_7 -> V_32 = V_43 ;
V_7 -> V_41 = V_47 ;
F_81 ( F_82 ( V_7 ) , & V_2 -> V_11 ) ;
V_2 -> V_7 . V_72 -> V_123 = V_149 ;
F_99 ( F_47 ( V_7 ) , V_160 | V_161 ) ;
F_100 ( V_7 ) ;
F_84 ( & V_2 -> V_7 ) ;
F_50 ( V_7 ) ;
F_34 ( V_7 ) ;
return 0 ;
}
static unsigned int F_101 ( struct V_162 * V_162 ,
struct V_54 * V_6 , T_3 * V_67 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
unsigned int V_163 ;
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
F_102 ( V_162 , F_47 ( V_7 ) , V_67 ) ;
V_163 = 0 ;
if ( V_7 -> V_45 )
V_163 |= V_160 ;
if ( V_7 -> V_41 == V_47 )
V_163 |= V_161 ;
if ( V_7 -> V_41 & V_69 )
V_163 |= V_164 ;
if ( ! F_48 ( & V_7 -> V_20 ) ||
( V_7 -> V_41 & V_69 ) )
V_163 |= V_165 | V_166 ;
if ( F_64 ( V_7 ) && F_3 ( V_2 ) )
V_163 |= V_167 | V_168 | V_169 ;
return V_163 ;
}
static void F_103 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
F_69 ( ! F_18 ( & V_7 -> V_170 ) ) ;
F_69 ( F_104 ( V_7 ) ) ;
F_69 ( ! V_7 -> V_72 ) ;
if ( ! F_24 ( V_7 , V_26 ) ) {
F_37 ( L_5 , V_7 ) ;
return;
}
F_84 ( & V_2 -> V_7 ) ;
F_83 ( & V_2 -> V_11 ) ;
}
static int F_105 ( struct V_171 * V_171 , struct V_54 * V_6 , int V_172 ,
int V_173 )
{
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
static struct V_174 V_175 = { . V_176 = L_6 ,
. V_177 = V_178 ,
. V_179 = sizeof( struct V_1 ) ,
} ;
if ( ! F_106 ( V_180 ) && ! F_106 ( V_181 ) )
return - V_182 ;
if ( V_6 -> type == V_183 )
V_6 -> V_184 = & V_185 ;
else if ( V_6 -> type == V_186 )
V_6 -> V_184 = & V_187 ;
else
return - V_188 ;
if ( V_172 < 0 || V_172 >= V_189 )
return - V_190 ;
V_7 = F_107 ( V_171 , V_191 , V_192 , & V_175 ) ;
if ( ! V_7 )
return - V_109 ;
V_2 = F_11 ( V_7 , struct V_1 , V_7 ) ;
V_7 -> V_105 = ( unsigned char ) V_172 ;
switch ( V_172 ) {
case V_193 :
V_7 -> V_95 = V_194 ;
break;
case V_106 :
V_7 -> V_95 = V_195 ;
break;
default:
V_7 -> V_95 = V_196 ;
}
F_45 ( & ( V_2 -> V_7 ) ) ;
F_108 ( V_6 , V_7 ) ;
V_7 -> V_197 = F_103 ;
F_109 ( & V_2 -> V_8 ) ;
V_2 -> V_11 . V_198 = F_35 ;
V_2 -> V_7 . V_72 -> V_123 = V_124 ;
V_2 -> V_7 . V_32 = V_43 ;
F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
V_2 -> V_129 . V_130 = V_199 ;
V_2 -> V_129 . V_172 = V_172 ;
F_50 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int T_4 F_110 ( void )
{
int V_16 = F_111 ( & V_200 ) ;
if ( ! V_16 )
return V_16 ;
return 0 ;
}
static void T_5 F_112 ( void )
{
F_113 ( V_191 ) ;
}
