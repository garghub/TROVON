static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_5 ;
unsigned int V_6 , V_7 ;
unsigned int V_8 ;
char V_9 = V_10 ;
F_2 ( & V_4 -> V_11 , V_5 ) ;
V_6 = F_3 ( V_12 ) ;
if ( V_6 & V_4 -> V_13 & V_14 )
V_6 &= ~ ( V_15 | V_16 ) ;
V_6 &= V_4 -> V_17 ;
V_6 &= ~ V_4 -> V_13 ;
if ( ( V_6 & V_16 ) ||
( V_6 & V_15 ) ) {
while ( ( F_3 ( V_18 ) &
V_19 ) != V_19 ) {
V_8 = F_3 ( V_20 ) ;
V_4 -> V_21 . V_22 ++ ;
if ( V_6 & V_14 ) {
V_4 -> V_21 . V_23 ++ ;
V_9 = V_24 ;
} else if ( V_6 & V_25 ) {
V_4 -> V_21 . V_26 ++ ;
V_9 = V_27 ;
} else if ( V_6 & V_28 )
V_4 -> V_21 . V_29 ++ ;
F_4 ( V_4 , V_6 , V_28 ,
V_8 , V_9 ) ;
}
F_5 ( & V_4 -> V_11 ) ;
F_6 ( & V_4 -> V_30 -> V_4 ) ;
F_7 ( & V_4 -> V_11 ) ;
}
if ( ( V_6 & V_31 ) == V_31 ) {
if ( F_8 ( & V_4 -> V_30 -> V_32 ) ) {
F_9 ( V_31 ,
V_33 ) ;
} else {
V_7 = V_4 -> V_34 ;
while ( V_7 -- ) {
if ( F_8 ( & V_4 -> V_30 -> V_32 ) )
break;
F_9 (
V_4 -> V_30 -> V_32 . V_35 [ V_4 -> V_30 -> V_32 .
V_36 ] , V_20 ) ;
V_4 -> V_21 . V_37 ++ ;
V_4 -> V_30 -> V_32 . V_36 =
( V_4 -> V_30 -> V_32 . V_36 + 1 ) & \
( V_38 - 1 ) ;
}
if ( F_10 (
& V_4 -> V_30 -> V_32 ) < V_39 )
F_11 ( V_4 ) ;
}
}
F_9 ( V_6 , V_12 ) ;
F_12 ( & V_4 -> V_11 , V_5 ) ;
return V_40 ;
}
static unsigned int F_13 ( struct V_3 * V_4 ,
unsigned int V_41 )
{
unsigned int V_42 ;
unsigned int V_43 = 0 ;
unsigned int V_44 , V_45 ;
unsigned int V_46 ;
V_42 = V_4 -> V_47 ;
if ( F_3 ( V_48 ) & V_49 )
V_42 = V_42 / 8 ;
for ( V_45 = 4 ; V_45 < 255 ; V_45 ++ ) {
V_44 = V_42 / ( V_41 * ( V_45 + 1 ) ) ;
if ( V_44 < 2 || V_44 > 65535 )
continue;
V_43 = V_42 / ( V_44 * ( V_45 + 1 ) ) ;
if ( V_41 > V_43 )
V_46 = V_41 - V_43 ;
else
V_46 = V_43 - V_41 ;
if ( ( ( V_46 * 100 ) / V_41 ) < 3 ) {
V_43 = V_41 ;
break;
}
}
F_9 ( V_44 , V_50 ) ;
F_9 ( V_45 , V_51 ) ;
return V_43 ;
}
static void F_14 ( struct V_3 * V_4 )
{
unsigned int V_9 , V_7 = V_4 -> V_34 ;
if ( F_8 ( & V_4 -> V_30 -> V_32 ) || F_15 ( V_4 ) )
return;
V_9 = F_3 ( V_52 ) ;
F_9 ( ( V_9 & ~ V_53 ) | V_54 ,
V_52 ) ;
while ( V_7 -- && ( ( F_3 ( V_18 )
& V_55 ) ) != V_55 ) {
if ( F_8 ( & V_4 -> V_30 -> V_32 ) )
break;
F_9 (
V_4 -> V_30 -> V_32 . V_35 [ V_4 -> V_30 -> V_32 . V_36 ] ,
V_20 ) ;
V_4 -> V_21 . V_37 ++ ;
V_4 -> V_30 -> V_32 . V_36 = ( V_4 -> V_30 -> V_32 . V_36 + 1 ) &
( V_38 - 1 ) ;
}
F_9 ( V_31 , V_56 ) ;
if ( F_10 ( & V_4 -> V_30 -> V_32 ) < V_39 )
F_11 ( V_4 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
unsigned int V_57 ;
V_57 = F_3 ( V_52 ) ;
V_57 |= V_53 ;
F_9 ( V_57 , V_52 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
unsigned int V_57 ;
V_57 = F_3 ( V_52 ) ;
V_57 |= V_58 ;
F_9 ( V_57 , V_52 ) ;
}
static unsigned int F_18 ( struct V_3 * V_4 )
{
unsigned int V_9 ;
V_9 = F_3 ( V_12 ) & V_31 ;
return V_9 ? V_59 : 0 ;
}
static void F_19 ( struct V_3 * V_4 , int V_60 )
{
unsigned int V_9 ;
unsigned long V_5 ;
F_2 ( & V_4 -> V_11 , V_5 ) ;
V_9 = F_3 ( V_52 ) ;
if ( V_60 == - 1 )
F_9 ( V_61 | V_9 ,
V_52 ) ;
else {
if ( ( V_9 & V_62 ) == 0 )
F_9 ( V_62 | V_9 ,
V_52 ) ;
}
F_12 ( & V_4 -> V_11 , V_5 ) ;
}
static void F_20 ( struct V_3 * V_4 ,
struct V_63 * V_64 , struct V_63 * V_65 )
{
unsigned int V_66 = 0 ;
unsigned int V_41 ;
unsigned long V_5 ;
unsigned int V_67 , V_68 ;
F_2 ( & V_4 -> V_11 , V_5 ) ;
while ( ( F_3 ( V_18 ) &
V_19 ) != V_19 ) {
F_3 ( V_20 ) ;
}
F_9 ( F_3 ( V_52 ) |
( V_53 | V_58 ) ,
V_52 ) ;
V_41 = F_21 ( V_4 , V_64 , V_65 , 0 , 10000000 ) ;
V_41 = F_13 ( V_4 , V_41 ) ;
if ( F_22 ( V_64 ) )
F_23 ( V_64 , V_41 , V_41 ) ;
F_24 ( V_4 , V_64 -> V_69 , V_41 ) ;
F_9 ( F_3 ( V_52 ) |
( V_70 | V_71 ) ,
V_52 ) ;
V_67 = F_3 ( V_52 ) ;
F_9 (
( V_67 & ~ ( V_53 | V_58 ) )
| ( V_54 | V_72 ) ,
V_52 ) ;
F_9 ( 10 , V_73 ) ;
V_4 -> V_17 = V_31 | V_15 |
V_28 | V_16 ;
V_4 -> V_13 = 0 ;
if ( V_64 -> V_74 & V_75 )
V_4 -> V_17 |= V_14 |
V_25 ;
if ( V_64 -> V_74 & V_76 )
V_4 -> V_13 |= V_14 |
V_25 | V_28 ;
if ( ( V_64 -> V_69 & V_77 ) == 0 )
V_4 -> V_13 |= V_15 |
V_16 | V_14 |
V_25 | V_28 ;
V_68 = F_3 ( V_48 ) ;
switch ( V_64 -> V_69 & V_78 ) {
case V_79 :
V_66 |= V_80 ;
break;
case V_81 :
V_66 |= V_82 ;
break;
default:
case V_83 :
V_66 |= V_84 ;
V_64 -> V_69 &= ~ V_78 ;
V_64 -> V_69 |= V_83 ;
break;
}
if ( V_64 -> V_69 & V_85 )
V_66 |= V_86 ;
else
V_66 |= V_87 ;
if ( V_64 -> V_69 & V_88 ) {
if ( V_64 -> V_69 & V_89 ) {
if ( V_64 -> V_69 & V_90 )
V_66 |= V_91 ;
else
V_66 |= V_92 ;
} else if ( V_64 -> V_69 & V_90 )
V_66 |= V_93 ;
else
V_66 |= V_94 ;
} else
V_66 |= V_95 ;
F_9 ( V_66 , V_48 ) ;
F_12 ( & V_4 -> V_11 , V_5 ) ;
}
static int F_25 ( struct V_3 * V_4 )
{
unsigned int V_96 = 0 , V_9 = 0 ;
V_96 = F_26 ( V_4 -> V_1 , F_1 , 0 , V_97 ,
( void * ) V_4 ) ;
if ( V_96 )
return V_96 ;
F_9 ( V_53 | V_58 ,
V_52 ) ;
F_9 ( V_70 | V_71 ,
V_52 ) ;
V_9 = F_3 ( V_52 ) ;
F_9 ( ( V_9 & ~ ( V_53 | V_58 ) )
| ( V_54 | V_72 |
V_62 ) , V_52 ) ;
F_9 ( V_98 | V_87
| V_95 | V_84 ,
V_48 ) ;
F_9 ( 14 , V_99 ) ;
F_9 ( 10 , V_73 ) ;
F_9 ( F_3 ( V_12 ) , V_12 ) ;
F_9 ( V_31 | V_14 |
V_25 | V_28 |
V_15 | V_16 , V_56 ) ;
F_9 ( ~ ( V_31 | V_14 |
V_25 | V_28 |
V_15 | V_16 ) , V_33 ) ;
return V_96 ;
}
static void F_27 ( struct V_3 * V_4 )
{
int V_9 ;
V_9 = F_3 ( V_100 ) ;
F_9 ( V_9 , V_33 ) ;
F_9 ( V_53 | V_58 ,
V_52 ) ;
F_28 ( V_4 -> V_1 , V_4 ) ;
}
static const char * F_29 ( struct V_3 * V_4 )
{
return V_4 -> type == V_101 ? V_97 : NULL ;
}
static int F_30 ( struct V_3 * V_4 ,
struct V_102 * V_103 )
{
if ( V_103 -> type != V_104 && V_103 -> type != V_101 )
return - V_105 ;
if ( V_4 -> V_1 != V_103 -> V_1 )
return - V_105 ;
if ( V_103 -> V_106 != V_107 )
return - V_105 ;
if ( V_4 -> V_108 != V_103 -> V_4 )
return - V_105 ;
if ( V_103 -> V_109 != 0 )
return - V_105 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
if ( ! F_32 ( V_4 -> V_110 , V_111 ,
V_97 ) ) {
return - V_112 ;
}
V_4 -> V_113 = F_33 ( V_4 -> V_110 , V_111 ) ;
if ( ! V_4 -> V_113 ) {
F_34 ( V_4 -> V_114 , L_1 ) ;
F_35 ( V_4 -> V_110 , V_111 ) ;
return - V_112 ;
}
return 0 ;
}
static void F_36 ( struct V_3 * V_4 )
{
F_35 ( V_4 -> V_110 , V_111 ) ;
F_37 ( V_4 -> V_113 ) ;
V_4 -> V_113 = NULL ;
}
static void F_38 ( struct V_3 * V_4 , int V_5 )
{
if ( V_5 & V_115 && F_31 ( V_4 ) == 0 )
V_4 -> type = V_101 ;
}
static unsigned int F_39 ( struct V_3 * V_4 )
{
return V_116 | V_117 | V_118 ;
}
static void F_40 ( struct V_3 * V_4 , unsigned int V_119 )
{
}
static void F_41 ( struct V_3 * V_4 )
{
}
static struct V_3 * F_42 ( void )
{
struct V_3 * V_4 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_121 ; V_120 ++ )
if ( V_122 [ V_120 ] . V_110 == 0 )
break;
if ( V_120 >= V_121 )
return NULL ;
V_4 = & V_122 [ V_120 ] ;
F_43 ( & V_4 -> V_11 ) ;
V_4 -> V_113 = NULL ;
V_4 -> V_108 = 1 ;
V_4 -> V_1 = 0 ;
V_4 -> type = V_104 ;
V_4 -> V_123 = V_124 ;
V_4 -> V_5 = V_125 ;
V_4 -> V_126 = & V_127 ;
V_4 -> V_34 = V_128 ;
V_4 -> line = V_120 ;
V_4 -> V_114 = NULL ;
return V_4 ;
}
static void F_44 ( struct V_3 * V_4 )
{
while ( ( F_3 ( V_18 ) & V_129 )
!= V_129 )
F_45 () ;
}
static void F_46 ( struct V_3 * V_4 , int V_130 )
{
F_44 ( V_4 ) ;
F_9 ( V_130 , V_20 ) ;
}
static void F_47 ( struct V_131 * V_132 , const char * V_133 ,
unsigned int V_134 )
{
struct V_3 * V_4 = & V_122 [ V_132 -> V_135 ] ;
unsigned long V_5 ;
unsigned int V_136 ;
int V_137 = 1 ;
if ( V_138 )
V_137 = F_48 ( & V_4 -> V_11 , V_5 ) ;
else
F_2 ( & V_4 -> V_11 , V_5 ) ;
V_136 = F_3 ( V_100 ) ;
F_9 ( V_136 , V_33 ) ;
F_49 ( V_4 , V_133 , V_134 , F_46 ) ;
F_44 ( V_4 ) ;
F_9 ( ~ V_136 , V_33 ) ;
F_9 ( V_136 , V_56 ) ;
if ( V_137 )
F_12 ( & V_4 -> V_11 , V_5 ) ;
}
static int T_2 F_50 ( struct V_131 * V_132 , char * V_139 )
{
struct V_3 * V_4 = & V_122 [ V_132 -> V_135 ] ;
int V_41 = 9600 ;
int V_140 = 8 ;
int V_23 = 'n' ;
int V_141 = 'n' ;
if ( V_132 -> V_135 < 0 || V_132 -> V_135 >= V_121 )
return - V_105 ;
if ( ! V_4 -> V_110 ) {
F_51 ( L_2 , V_132 -> V_135 ) ;
return - V_142 ;
}
if ( V_139 )
F_52 ( V_139 , & V_41 , & V_23 , & V_140 , & V_141 ) ;
return F_53 ( V_4 , V_132 , V_41 , V_23 , V_140 , V_141 ) ;
}
static int T_2 F_54 ( void )
{
F_55 ( & V_143 ) ;
return 0 ;
}
static int F_56 ( struct V_144 * V_145 )
{
int V_146 ;
struct V_3 * V_4 ;
struct V_147 * V_148 , * V_149 ;
struct V_150 * V_150 ;
V_150 = F_57 ( V_145 -> V_114 . V_151 , 0 ) ;
if ( F_58 ( V_150 ) ) {
F_34 ( & V_145 -> V_114 , L_3 ) ;
return F_59 ( V_150 ) ;
}
V_146 = F_60 ( V_150 ) ;
if ( V_146 ) {
F_34 ( & V_145 -> V_114 , L_4 ) ;
return - V_152 ;
}
V_148 = F_61 ( V_145 , V_153 , 0 ) ;
if ( ! V_148 )
return - V_142 ;
V_149 = F_61 ( V_145 , V_154 , 0 ) ;
if ( ! V_149 )
return - V_142 ;
V_4 = F_42 () ;
if ( ! V_4 ) {
F_34 ( & V_145 -> V_114 , L_5 ) ;
return - V_142 ;
} else {
V_4 -> V_110 = V_148 -> V_155 ;
V_4 -> V_1 = V_149 -> V_155 ;
V_4 -> V_114 = & V_145 -> V_114 ;
V_4 -> V_47 = F_62 ( V_150 ) ;
V_4 -> V_156 = V_150 ;
F_63 ( & V_145 -> V_114 , V_4 ) ;
V_146 = F_64 ( & V_157 , V_4 ) ;
if ( V_146 ) {
F_34 ( & V_145 -> V_114 ,
L_6 , V_146 ) ;
F_63 ( & V_145 -> V_114 , NULL ) ;
return V_146 ;
}
return 0 ;
}
}
static int F_65 ( struct V_144 * V_145 )
{
struct V_3 * V_4 = F_66 ( & V_145 -> V_114 ) ;
struct V_150 * V_150 = V_4 -> V_156 ;
int V_146 ;
V_146 = F_67 ( & V_157 , V_4 ) ;
F_63 ( & V_145 -> V_114 , NULL ) ;
V_4 -> V_110 = 0 ;
F_68 ( V_150 ) ;
return V_146 ;
}
static int F_69 ( struct V_144 * V_145 , T_3 V_30 )
{
F_70 ( & V_157 , & V_122 [ V_145 -> V_120 ] ) ;
return 0 ;
}
static int F_71 ( struct V_144 * V_145 )
{
F_72 ( & V_157 , & V_122 [ V_145 -> V_120 ] ) ;
return 0 ;
}
static int T_2 F_73 ( void )
{
int V_96 = 0 ;
V_96 = F_74 ( & V_157 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_75 ( & V_158 ) ;
if ( V_96 )
F_76 ( & V_157 ) ;
return V_96 ;
}
static void T_4 F_77 ( void )
{
F_78 ( & V_158 ) ;
F_76 ( & V_157 ) ;
}
