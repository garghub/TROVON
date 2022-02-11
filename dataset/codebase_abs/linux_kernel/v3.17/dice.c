static unsigned int F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; ++ V_2 )
if ( V_3 [ V_2 ] == V_1 )
return V_2 ;
return 0 ;
}
static unsigned int F_3 ( unsigned int V_4 )
{
return ( ( int ) V_4 - 1 ) / 2 ;
}
static void F_4 ( struct V_5 * V_5 )
{
V_5 -> V_6 = true ;
F_5 ( & V_5 -> V_7 ) ;
}
static int F_6 ( struct V_5 * V_5 )
{
int V_8 ;
F_7 ( & V_5 -> V_9 ) ;
if ( V_5 -> V_10 < 0 ) {
V_8 = - V_11 ;
goto V_12;
}
if ( V_5 -> V_10 ++ == 0 )
F_4 ( V_5 ) ;
V_8 = 0 ;
V_12:
F_8 ( & V_5 -> V_9 ) ;
return V_8 ;
}
static void F_9 ( struct V_5 * V_5 )
{
F_7 ( & V_5 -> V_9 ) ;
if ( F_10 ( V_5 -> V_10 <= 0 ) )
goto V_12;
if ( -- V_5 -> V_10 == 0 )
F_4 ( V_5 ) ;
V_12:
F_8 ( & V_5 -> V_9 ) ;
}
static inline T_1 F_11 ( struct V_5 * V_5 , unsigned int V_13 )
{
return V_14 + V_5 -> V_15 + V_13 ;
}
static inline T_1 F_12 ( struct V_5 * V_5 , unsigned int V_13 )
{
return V_14 + V_5 -> V_16 + V_13 ;
}
static int F_13 ( struct V_5 * V_5 )
{
struct V_17 * V_18 = F_14 ( V_5 -> V_19 ) ;
T_2 * V_20 ;
int V_8 , V_21 = 0 ;
V_20 = F_15 ( 2 * 8 , V_22 ) ;
if ( ! V_20 )
return - V_23 ;
for (; ; ) {
V_20 [ 0 ] = F_16 ( V_24 ) ;
V_20 [ 1 ] = F_16 (
( ( T_1 ) V_18 -> V_25 -> V_26 << V_27 ) |
V_5 -> V_28 . V_13 ) ;
V_5 -> V_29 = V_18 -> V_30 ;
F_17 () ;
V_8 = F_18 ( V_5 -> V_19 ,
V_31 ,
F_11 ( V_5 , V_32 ) ,
V_20 , 2 * 8 ,
V_33 |
V_5 -> V_29 ) ;
if ( V_8 == 0 ) {
if ( V_20 [ 0 ] != F_16 ( V_24 ) ) {
F_19 ( & V_5 -> V_19 -> V_18 ,
L_1 ) ;
V_8 = - V_11 ;
}
break;
}
if ( V_8 != - V_34 || ++ V_21 >= 3 )
break;
F_20 ( 20 ) ;
}
F_21 ( V_20 ) ;
return V_8 ;
}
static int F_22 ( struct V_5 * V_5 )
{
struct V_17 * V_18 = F_14 ( V_5 -> V_19 ) ;
T_2 * V_20 ;
int V_8 ;
if ( V_5 -> V_29 == - 1 )
return 0 ;
V_20 = F_15 ( 2 * 8 , V_22 ) ;
if ( ! V_20 )
return - V_23 ;
V_20 [ 0 ] = F_16 ( V_24 ) ;
V_20 [ 1 ] = F_16 (
( ( T_1 ) V_18 -> V_25 -> V_26 << V_27 ) |
V_5 -> V_28 . V_13 ) ;
V_5 -> V_29 = V_18 -> V_30 ;
F_17 () ;
V_8 = F_18 ( V_5 -> V_19 , V_31 ,
F_11 ( V_5 , V_32 ) ,
V_20 , 2 * 8 ,
V_33 | V_5 -> V_29 ) ;
if ( V_8 == 0 ) {
if ( V_20 [ 0 ] != F_16 ( V_24 ) ) {
F_19 ( & V_5 -> V_19 -> V_18 ,
L_1 ) ;
V_8 = - V_11 ;
}
} else if ( V_8 == - V_34 ) {
V_8 = 0 ;
}
F_21 ( V_20 ) ;
if ( V_8 < 0 )
V_5 -> V_29 = - 1 ;
return V_8 ;
}
static void F_23 ( struct V_5 * V_5 )
{
struct V_17 * V_18 = F_14 ( V_5 -> V_19 ) ;
T_2 * V_20 ;
V_20 = F_15 ( 2 * 8 , V_22 ) ;
if ( ! V_20 )
return;
V_20 [ 0 ] = F_16 (
( ( T_1 ) V_18 -> V_25 -> V_26 << V_27 ) |
V_5 -> V_28 . V_13 ) ;
V_20 [ 1 ] = F_16 ( V_24 ) ;
F_18 ( V_5 -> V_19 , V_31 ,
F_11 ( V_5 , V_32 ) ,
V_20 , 2 * 8 , V_35 |
V_33 | V_5 -> V_29 ) ;
F_21 ( V_20 ) ;
V_5 -> V_29 = - 1 ;
}
static int F_24 ( struct V_5 * V_5 )
{
T_3 V_36 ;
int V_8 ;
V_36 = F_25 ( 1 ) ;
V_8 = F_18 ( V_5 -> V_19 , V_37 ,
F_11 ( V_5 , V_38 ) ,
& V_36 , 4 ,
V_33 | V_5 -> V_29 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 -> V_39 = true ;
return 0 ;
}
static void F_26 ( struct V_5 * V_5 )
{
T_3 V_36 ;
if ( ! V_5 -> V_39 )
return;
V_36 = 0 ;
F_18 ( V_5 -> V_19 , V_37 ,
F_11 ( V_5 , V_38 ) ,
& V_36 , 4 , V_35 |
V_33 | V_5 -> V_29 ) ;
V_5 -> V_39 = false ;
}
static void F_27 ( struct V_40 * V_25 , struct V_41 * V_42 ,
int V_43 , int V_44 , int V_45 ,
int V_30 , unsigned long long V_13 ,
void * V_46 , T_4 V_47 , void * V_48 )
{
struct V_5 * V_5 = V_48 ;
T_5 V_49 ;
unsigned long V_50 ;
if ( V_43 != V_37 ) {
F_28 ( V_25 , V_42 , V_51 ) ;
return;
}
if ( ( V_13 & 3 ) != 0 ) {
F_28 ( V_25 , V_42 , V_52 ) ;
return;
}
V_49 = F_29 ( V_46 ) ;
F_30 ( & V_5 -> V_9 , V_50 ) ;
V_5 -> V_53 |= V_49 ;
F_31 ( & V_5 -> V_9 , V_50 ) ;
F_28 ( V_25 , V_42 , V_54 ) ;
if ( V_49 & V_55 )
F_32 ( & V_5 -> V_56 ) ;
F_5 ( & V_5 -> V_7 ) ;
}
static int F_33 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_5 * V_5 = V_60 -> V_61 ;
const struct V_62 * V_63 =
F_34 ( V_58 , V_64 ) ;
struct V_62 * V_1 =
F_35 ( V_58 , V_65 ) ;
struct V_62 V_66 = {
. V_67 = V_68 , . V_69 = 0 , . integer = 1
} ;
unsigned int V_2 , V_70 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; ++ V_2 ) {
V_70 = F_3 ( V_2 ) ;
if ( ( V_5 -> V_71 & ( 1 << V_2 ) ) &&
F_36 ( V_63 , V_5 -> V_72 [ V_70 ] ) ) {
V_66 . V_67 = V_67 ( V_66 . V_67 ,
V_3 [ V_2 ] ) ;
V_66 . V_69 = V_69 ( V_66 . V_69 ,
V_3 [ V_2 ] ) ;
}
}
return F_37 ( V_1 , & V_66 ) ;
}
static int F_38 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_5 * V_5 = V_60 -> V_61 ;
const struct V_62 * V_1 =
F_34 ( V_58 , V_65 ) ;
struct V_62 * V_63 =
F_35 ( V_58 , V_64 ) ;
struct V_62 V_73 = {
. V_67 = V_68 , . V_69 = 0 , . integer = 1
} ;
unsigned int V_2 , V_70 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; ++ V_2 )
if ( ( V_5 -> V_71 & ( 1 << V_2 ) ) &&
F_36 ( V_1 , V_3 [ V_2 ] ) ) {
V_70 = F_3 ( V_2 ) ;
V_73 . V_67 = V_67 ( V_73 . V_67 ,
V_5 -> V_72 [ V_70 ] ) ;
V_73 . V_69 = V_69 ( V_73 . V_69 ,
V_5 -> V_72 [ V_70 ] ) ;
}
return F_37 ( V_63 , & V_73 ) ;
}
static int F_39 ( struct V_74 * V_75 )
{
static const struct V_76 V_77 = {
. V_78 = V_79 |
V_80 |
V_81 |
V_82 |
V_83 ,
. V_84 = V_85 ,
. V_86 = V_68 ,
. V_87 = 0 ,
. V_88 = 16 * 1024 * 1024 ,
. V_89 = 1 ,
. V_90 = V_68 ,
. V_91 = 1 ,
. V_92 = V_68 ,
} ;
struct V_5 * V_5 = V_75 -> V_93 ;
struct V_94 * V_95 = V_75 -> V_95 ;
unsigned int V_2 ;
int V_8 ;
V_8 = F_6 ( V_5 ) ;
if ( V_8 < 0 )
goto error;
V_95 -> V_96 = V_77 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; ++ V_2 )
if ( V_5 -> V_71 & ( 1 << V_2 ) )
V_95 -> V_96 . V_97 |=
F_40 ( V_3 [ V_2 ] ) ;
F_41 ( V_95 ) ;
for ( V_2 = 0 ; V_2 < 3 ; ++ V_2 )
if ( V_5 -> V_72 [ V_2 ] ) {
V_95 -> V_96 . V_86 = V_67 ( V_95 -> V_96 . V_86 ,
V_5 -> V_72 [ V_2 ] ) ;
V_95 -> V_96 . V_87 = V_69 ( V_95 -> V_96 . V_87 ,
V_5 -> V_72 [ V_2 ] ) ;
}
V_8 = F_42 ( V_95 , 0 , V_65 ,
F_33 , V_5 ,
V_64 , - 1 ) ;
if ( V_8 < 0 )
goto V_98;
V_8 = F_42 ( V_95 , 0 , V_64 ,
F_38 , V_5 ,
V_65 , - 1 ) ;
if ( V_8 < 0 )
goto V_98;
V_8 = F_43 ( & V_5 -> V_99 , V_95 ) ;
if ( V_8 < 0 )
goto V_98;
return 0 ;
V_98:
F_9 ( V_5 ) ;
error:
return V_8 ;
}
static int F_44 ( struct V_74 * V_75 )
{
struct V_5 * V_5 = V_75 -> V_93 ;
F_9 ( V_5 ) ;
return 0 ;
}
static int F_45 ( struct V_5 * V_5 )
{
int V_8 ;
if ( F_46 ( & V_5 -> V_99 ) )
return 0 ;
V_8 = F_47 ( & V_5 -> V_99 , V_5 -> V_100 . V_101 ,
F_14 ( V_5 -> V_19 ) -> V_102 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_24 ( V_5 ) ;
if ( V_8 < 0 ) {
F_48 ( & V_5 -> V_99 ) ;
return V_8 ;
}
return 0 ;
}
static int F_49 ( struct V_5 * V_5 )
{
T_3 V_101 ;
int V_8 ;
if ( ! V_5 -> V_100 . V_103 ) {
V_8 = F_50 ( & V_5 -> V_100 ,
F_51 ( & V_5 -> V_99 ) ,
F_14 ( V_5 -> V_19 ) -> V_102 ) ;
if ( V_8 < 0 )
goto error;
V_101 = F_25 ( V_5 -> V_100 . V_101 ) ;
V_8 = F_18 ( V_5 -> V_19 ,
V_37 ,
F_12 ( V_5 , V_104 ) ,
& V_101 , 4 , 0 ) ;
if ( V_8 < 0 )
goto V_105;
}
V_8 = F_45 ( V_5 ) ;
if ( V_8 < 0 )
goto V_106;
return 0 ;
V_106:
V_101 = F_25 ( ( T_5 ) - 1 ) ;
F_18 ( V_5 -> V_19 , V_37 ,
F_12 ( V_5 , V_104 ) , & V_101 , 4 , 0 ) ;
V_105:
F_52 ( & V_5 -> V_100 ) ;
error:
return V_8 ;
}
static void F_53 ( struct V_5 * V_5 )
{
if ( F_46 ( & V_5 -> V_99 ) ) {
F_26 ( V_5 ) ;
F_48 ( & V_5 -> V_99 ) ;
}
}
static void F_54 ( struct V_5 * V_5 )
{
T_3 V_101 ;
F_53 ( V_5 ) ;
if ( ! V_5 -> V_100 . V_103 )
return;
V_101 = F_25 ( ( T_5 ) - 1 ) ;
F_18 ( V_5 -> V_19 , V_37 ,
F_12 ( V_5 , V_104 ) , & V_101 , 4 , 0 ) ;
F_52 ( & V_5 -> V_100 ) ;
}
static int F_55 ( struct V_5 * V_5 , unsigned int V_107 )
{
T_3 V_36 ;
int V_8 ;
F_56 ( & V_5 -> V_56 ) ;
V_36 = F_25 ( V_107 | V_108 ) ;
V_8 = F_18 ( V_5 -> V_19 , V_37 ,
F_11 ( V_5 , V_109 ) ,
& V_36 , 4 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! F_57 ( & V_5 -> V_56 ,
F_58 ( 100 ) ) )
F_59 ( & V_5 -> V_19 -> V_18 , L_2 ) ;
return 0 ;
}
static int F_60 ( struct V_74 * V_75 ,
struct V_57 * V_110 )
{
struct V_5 * V_5 = V_75 -> V_93 ;
unsigned int V_4 , V_70 , V_1 , V_63 , V_2 ;
int V_8 ;
F_61 ( & V_5 -> V_111 ) ;
F_54 ( V_5 ) ;
F_62 ( & V_5 -> V_111 ) ;
V_8 = F_63 ( V_75 ,
F_64 ( V_110 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_1 = F_65 ( V_110 ) ;
V_4 = F_1 ( V_1 ) ;
V_8 = F_55 ( V_5 , V_4 << V_112 ) ;
if ( V_8 < 0 )
return V_8 ;
V_63 = F_66 ( V_110 ) ;
if ( V_4 > 4 ) {
if ( V_63 > V_113 / 2 ) {
V_8 = - V_114 ;
return V_8 ;
}
V_1 /= 2 ;
V_63 *= 2 ;
V_5 -> V_99 . V_115 = true ;
} else {
V_5 -> V_99 . V_115 = false ;
}
V_70 = F_3 ( V_4 ) ;
F_67 ( & V_5 -> V_99 , V_1 , V_63 ,
V_5 -> V_116 [ V_70 ] ) ;
if ( V_4 > 4 ) {
V_63 /= 2 ;
for ( V_2 = 0 ; V_2 < V_63 ; V_2 ++ ) {
V_5 -> V_99 . V_117 [ V_2 ] = V_2 * 2 ;
V_5 -> V_99 . V_117 [ V_2 + V_63 ] = V_2 * 2 + 1 ;
}
}
F_68 ( & V_5 -> V_99 ,
F_69 ( V_110 ) ) ;
return 0 ;
}
static int F_70 ( struct V_74 * V_75 )
{
struct V_5 * V_5 = V_75 -> V_93 ;
F_61 ( & V_5 -> V_111 ) ;
F_54 ( V_5 ) ;
F_62 ( & V_5 -> V_111 ) ;
return F_71 ( V_75 ) ;
}
static int F_72 ( struct V_74 * V_75 )
{
struct V_5 * V_5 = V_75 -> V_93 ;
int V_8 ;
F_61 ( & V_5 -> V_111 ) ;
if ( F_73 ( & V_5 -> V_99 ) )
F_53 ( V_5 ) ;
V_8 = F_49 ( V_5 ) ;
if ( V_8 < 0 ) {
F_62 ( & V_5 -> V_111 ) ;
return V_8 ;
}
F_62 ( & V_5 -> V_111 ) ;
F_74 ( & V_5 -> V_99 ) ;
return 0 ;
}
static int F_75 ( struct V_74 * V_75 , int V_118 )
{
struct V_5 * V_5 = V_75 -> V_93 ;
struct V_74 * V_119 ;
switch ( V_118 ) {
case V_120 :
V_119 = V_75 ;
break;
case V_121 :
V_119 = NULL ;
break;
default:
return - V_122 ;
}
F_76 ( & V_5 -> V_99 , V_119 ) ;
return 0 ;
}
static T_6 F_77 ( struct V_74 * V_75 )
{
struct V_5 * V_5 = V_75 -> V_93 ;
return F_78 ( & V_5 -> V_99 ) ;
}
static int F_79 ( struct V_5 * V_5 )
{
static struct V_123 V_124 = {
. V_125 = F_39 ,
. V_126 = F_44 ,
. V_127 = V_128 ,
. V_110 = F_60 ,
. V_129 = F_70 ,
. V_130 = F_72 ,
. V_131 = F_75 ,
. V_132 = F_77 ,
. V_133 = V_134 ,
. V_135 = V_136 ,
} ;
struct V_137 * V_119 ;
int V_8 ;
V_8 = F_80 ( V_5 -> V_25 , L_3 , 0 , 1 , 0 , & V_119 ) ;
if ( V_8 < 0 )
return V_8 ;
V_119 -> V_93 = V_5 ;
strcpy ( V_119 -> V_138 , V_5 -> V_25 -> V_139 ) ;
V_119 -> V_140 [ V_141 ] . V_75 -> V_124 = & V_124 ;
return 0 ;
}
static long F_81 ( struct V_142 * V_143 , char T_7 * V_144 ,
long V_145 , T_8 * V_13 )
{
struct V_5 * V_5 = V_143 -> V_93 ;
F_82 ( V_146 ) ;
union V_147 V_148 ;
F_7 ( & V_5 -> V_9 ) ;
while ( ! V_5 -> V_6 && V_5 -> V_53 == 0 ) {
F_83 ( & V_5 -> V_7 , & V_146 , V_149 ) ;
F_8 ( & V_5 -> V_9 ) ;
F_84 () ;
F_85 ( & V_5 -> V_7 , & V_146 ) ;
if ( F_86 ( V_150 ) )
return - V_151 ;
F_7 ( & V_5 -> V_9 ) ;
}
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
if ( V_5 -> V_6 ) {
V_148 . V_152 . type = V_153 ;
V_148 . V_152 . V_154 = V_5 -> V_10 > 0 ;
V_5 -> V_6 = false ;
V_145 = V_67 ( V_145 , ( long ) sizeof( V_148 . V_152 ) ) ;
} else {
V_148 . F_27 . type = V_155 ;
V_148 . F_27 . V_156 = V_5 -> V_53 ;
V_5 -> V_53 = 0 ;
V_145 = V_67 ( V_145 , ( long ) sizeof( V_148 . F_27 ) ) ;
}
F_8 ( & V_5 -> V_9 ) ;
if ( F_87 ( V_144 , & V_148 , V_145 ) )
return - V_157 ;
return V_145 ;
}
static unsigned int F_88 ( struct V_142 * V_143 , struct V_158 * V_158 ,
T_9 * V_146 )
{
struct V_5 * V_5 = V_143 -> V_93 ;
unsigned int V_159 ;
F_89 ( V_158 , & V_5 -> V_7 , V_146 ) ;
F_7 ( & V_5 -> V_9 ) ;
if ( V_5 -> V_6 || V_5 -> V_53 != 0 )
V_159 = V_160 | V_161 ;
else
V_159 = 0 ;
F_8 ( & V_5 -> V_9 ) ;
return V_159 ;
}
static int F_90 ( struct V_5 * V_5 , void T_7 * V_162 )
{
struct V_17 * V_163 = F_14 ( V_5 -> V_19 ) ;
struct V_164 V_78 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . type = V_165 ;
V_78 . V_25 = V_163 -> V_25 -> V_166 ;
* ( T_3 * ) & V_78 . V_167 [ 0 ] = F_25 ( V_163 -> V_168 [ 3 ] ) ;
* ( T_3 * ) & V_78 . V_167 [ 4 ] = F_25 ( V_163 -> V_168 [ 4 ] ) ;
F_91 ( V_78 . V_169 , F_92 ( & V_163 -> V_18 ) ,
sizeof( V_78 . V_169 ) ) ;
if ( F_87 ( V_162 , & V_78 , sizeof( V_78 ) ) )
return - V_157 ;
return 0 ;
}
static int F_93 ( struct V_5 * V_5 )
{
int V_8 ;
F_7 ( & V_5 -> V_9 ) ;
if ( V_5 -> V_10 == 0 ) {
V_5 -> V_10 = - 1 ;
V_8 = 0 ;
} else {
V_8 = - V_11 ;
}
F_8 ( & V_5 -> V_9 ) ;
return V_8 ;
}
static int F_94 ( struct V_5 * V_5 )
{
int V_8 ;
F_7 ( & V_5 -> V_9 ) ;
if ( V_5 -> V_10 == - 1 ) {
V_5 -> V_10 = 0 ;
V_8 = 0 ;
} else {
V_8 = - V_170 ;
}
F_8 ( & V_5 -> V_9 ) ;
return V_8 ;
}
static int F_95 ( struct V_142 * V_143 , struct V_158 * V_158 )
{
struct V_5 * V_5 = V_143 -> V_93 ;
F_7 ( & V_5 -> V_9 ) ;
if ( V_5 -> V_10 == - 1 )
V_5 -> V_10 = 0 ;
F_8 ( & V_5 -> V_9 ) ;
return 0 ;
}
static int F_96 ( struct V_142 * V_143 , struct V_158 * V_158 ,
unsigned int V_118 , unsigned long V_162 )
{
struct V_5 * V_5 = V_143 -> V_93 ;
switch ( V_118 ) {
case V_171 :
return F_90 ( V_5 , ( void T_7 * ) V_162 ) ;
case V_172 :
return F_93 ( V_5 ) ;
case V_173 :
return F_94 ( V_5 ) ;
default:
return - V_174 ;
}
}
static int F_97 ( struct V_142 * V_143 , struct V_158 * V_158 ,
unsigned int V_118 , unsigned long V_162 )
{
return F_96 ( V_143 , V_158 , V_118 ,
( unsigned long ) F_98 ( V_162 ) ) ;
}
static int F_99 ( struct V_5 * V_5 )
{
static const struct V_175 V_124 = {
. V_176 = F_81 ,
. V_177 = F_95 ,
. V_178 = F_88 ,
. V_127 = F_96 ,
. V_179 = F_97 ,
} ;
struct V_142 * V_143 ;
int V_8 ;
V_8 = F_100 ( V_5 -> V_25 , L_3 , 0 , & V_143 ) ;
if ( V_8 < 0 )
return V_8 ;
strcpy ( V_143 -> V_138 , L_3 ) ;
V_143 -> V_180 = V_181 ;
V_143 -> V_124 = V_124 ;
V_143 -> V_93 = V_5 ;
V_143 -> V_182 = true ;
return 0 ;
}
static int F_101 ( struct V_5 * V_5 , void * V_20 ,
unsigned int V_183 , unsigned int V_184 )
{
unsigned int V_2 ;
int V_8 ;
V_8 = F_18 ( V_5 -> V_19 , V_185 ,
V_14 + 4 * V_183 ,
V_20 , 4 * V_184 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_2 = 0 ; V_2 < V_184 ; ++ V_2 )
F_102 ( & ( ( T_5 * ) V_20 ) [ V_2 ] ) ;
return 0 ;
}
static const char * F_103 ( const char * const V_186 [] , unsigned int V_145 ,
unsigned int V_2 )
{
if ( V_2 < V_145 )
return V_186 [ V_2 ] ;
else
return L_4 ;
}
static void F_104 ( char * V_187 , unsigned int V_188 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_188 ; V_2 += 4 )
F_105 ( ( T_5 * ) ( V_187 + V_2 ) ) ;
for ( V_2 = 0 ; V_2 < V_188 - 2 ; ++ V_2 ) {
if ( V_187 [ V_2 ] == '\0' )
return;
if ( V_187 [ V_2 ] == '\\' && V_187 [ V_2 + 1 ] == '\\' ) {
V_187 [ V_2 + 2 ] = '\0' ;
return;
}
}
V_187 [ V_188 - 1 ] = '\0' ;
}
static void F_106 ( struct V_189 * V_190 ,
struct V_191 * V_20 )
{
static const char * const V_192 [ 5 ] = {
L_5 , L_6 , L_7 , L_8 , L_9
} ;
static const char * const V_193 [] = {
L_10 , L_11 , L_12 , L_13 , L_14 , L_15 , L_16 ,
L_17 , L_18 , L_19 , L_20 , L_21 , L_22
} ;
static const char * const V_97 [] = {
L_23 , L_24 , L_25 , L_26 , L_27 , L_28 , L_29 ,
L_30 , L_31 , L_32 , L_33
} ;
struct V_5 * V_5 = V_190 -> V_93 ;
T_5 V_194 [ F_2 ( V_192 ) * 2 ] ;
struct {
T_5 V_195 ;
T_5 V_188 ;
} V_196 ;
union {
struct {
T_5 V_197 , V_198 ;
T_5 V_156 ;
char V_199 [ V_200 ] ;
T_5 V_201 ;
T_5 V_202 ;
T_5 V_154 ;
T_5 V_203 ;
T_5 V_204 ;
T_5 V_205 ;
T_5 V_71 ;
char V_206 [ V_207 ] ;
} V_208 ;
struct {
T_5 V_209 ;
T_5 V_210 ;
T_5 V_211 ;
T_5 V_212 ;
char V_213 [ V_214 ] ;
T_5 V_215 ;
T_5 V_216 ;
} V_217 ;
struct {
T_5 V_209 ;
T_5 V_218 ;
T_5 V_210 ;
T_5 V_211 ;
char V_213 [ V_219 ] ;
T_5 V_215 ;
T_5 V_216 ;
} V_220 ;
struct {
T_5 V_221 ;
T_5 V_222 ;
T_5 V_1 ;
T_5 V_223 ;
} V_224 ;
} V_144 ;
unsigned int V_184 , V_99 , V_2 ;
if ( F_101 ( V_5 , V_194 , 0 , F_2 ( V_194 ) ) < 0 )
return;
F_107 ( V_20 , L_34 ) ;
for ( V_2 = 0 ; V_2 < F_2 ( V_192 ) ; ++ V_2 )
F_107 ( V_20 , L_35 ,
V_192 [ V_2 ] ,
V_194 [ V_2 * 2 ] , V_194 [ V_2 * 2 + 1 ] ) ;
V_184 = F_108 ( T_5 , V_194 [ 1 ] , sizeof( V_144 . V_208 ) / 4 ) ;
if ( F_101 ( V_5 , & V_144 . V_208 , V_194 [ 0 ] , V_184 ) < 0 )
return;
F_107 ( V_20 , L_36 ) ;
F_107 ( V_20 , L_37 ,
V_144 . V_208 . V_197 >> 16 ,
V_144 . V_208 . V_197 & 0xffff , V_144 . V_208 . V_198 ) ;
F_107 ( V_20 , L_38 , V_144 . V_208 . V_156 ) ;
F_104 ( V_144 . V_208 . V_199 , V_200 ) ;
F_107 ( V_20 , L_39 , V_144 . V_208 . V_199 ) ;
F_107 ( V_20 , L_40 ,
F_103 ( V_193 , F_2 ( V_193 ) ,
V_144 . V_208 . V_201 & V_225 ) ,
F_103 ( V_97 , F_2 ( V_97 ) ,
( V_144 . V_208 . V_201 & V_226 )
>> V_112 ) ) ;
F_107 ( V_20 , L_41 , V_144 . V_208 . V_202 ) ;
F_107 ( V_20 , L_42 ,
V_144 . V_208 . V_154 & V_227 ? L_43 : L_44 ,
F_103 ( V_97 , F_2 ( V_97 ) ,
( V_144 . V_208 . V_154 &
V_228 )
>> V_112 ) ) ;
F_107 ( V_20 , L_45 , V_144 . V_208 . V_203 ) ;
F_107 ( V_20 , L_46 , V_144 . V_208 . V_204 ) ;
F_107 ( V_20 , L_47 ,
( V_144 . V_208 . V_205 >> 24 ) & 0xff ,
( V_144 . V_208 . V_205 >> 16 ) & 0xff ,
( V_144 . V_208 . V_205 >> 8 ) & 0xff ,
( V_144 . V_208 . V_205 >> 0 ) & 0xff ) ;
if ( V_184 >= 90 ) {
F_107 ( V_20 , L_48 ) ;
for ( V_2 = 0 ; V_2 <= 6 ; ++ V_2 )
if ( V_144 . V_208 . V_71 & ( 1 << V_2 ) )
F_107 ( V_20 , L_49 , V_97 [ V_2 ] ) ;
for ( V_2 = 0 ; V_2 <= 12 ; ++ V_2 )
if ( V_144 . V_208 . V_71 & ( 1 << ( 16 + V_2 ) ) )
F_107 ( V_20 , L_49 , V_193 [ V_2 ] ) ;
F_107 ( V_20 , L_50 ) ;
F_104 ( V_144 . V_208 . V_206 ,
V_207 ) ;
F_107 ( V_20 , L_51 ,
V_144 . V_208 . V_206 ) ;
}
if ( F_101 ( V_5 , & V_196 , V_194 [ 2 ] , 2 ) < 0 )
return;
V_184 = F_108 ( T_5 , V_196 . V_188 , sizeof( V_144 . V_217 ) / 4 ) ;
for ( V_99 = 0 ; V_99 < V_196 . V_195 ; ++ V_99 ) {
if ( F_101 ( V_5 , & V_144 . V_217 , V_194 [ 2 ] + 2 +
V_99 * V_196 . V_188 ,
V_184 ) < 0 )
break;
F_107 ( V_20 , L_52 , V_99 ) ;
F_107 ( V_20 , L_53 , ( int ) V_144 . V_217 . V_209 ) ;
F_107 ( V_20 , L_54 ,
V_144 . V_217 . V_210 ) ;
F_107 ( V_20 , L_55 , V_144 . V_217 . V_211 ) ;
F_107 ( V_20 , L_56 , 100u << V_144 . V_217 . V_212 ) ;
if ( V_184 >= 68 ) {
F_104 ( V_144 . V_217 . V_213 , V_214 ) ;
F_107 ( V_20 , L_57 , V_144 . V_217 . V_213 ) ;
}
if ( V_184 >= 70 ) {
F_107 ( V_20 , L_58 ,
V_144 . V_217 . V_215 ) ;
F_107 ( V_20 , L_59 ,
V_144 . V_217 . V_216 ) ;
}
}
if ( F_101 ( V_5 , & V_196 , V_194 [ 4 ] , 2 ) < 0 )
return;
V_184 = F_108 ( T_5 , V_196 . V_188 , sizeof( V_144 . V_220 ) / 4 ) ;
for ( V_99 = 0 ; V_99 < V_196 . V_195 ; ++ V_99 ) {
if ( F_101 ( V_5 , & V_144 . V_220 , V_194 [ 4 ] + 2 +
V_99 * V_196 . V_188 ,
V_184 ) < 0 )
break;
F_107 ( V_20 , L_60 , V_99 ) ;
F_107 ( V_20 , L_53 , ( int ) V_144 . V_220 . V_209 ) ;
F_107 ( V_20 , L_61 , V_144 . V_220 . V_218 ) ;
F_107 ( V_20 , L_54 ,
V_144 . V_220 . V_210 ) ;
F_107 ( V_20 , L_55 , V_144 . V_220 . V_211 ) ;
if ( V_184 >= 68 ) {
F_104 ( V_144 . V_220 . V_213 , V_219 ) ;
F_107 ( V_20 , L_57 , V_144 . V_220 . V_213 ) ;
}
if ( V_184 >= 70 ) {
F_107 ( V_20 , L_58 ,
V_144 . V_220 . V_215 ) ;
F_107 ( V_20 , L_59 ,
V_144 . V_220 . V_216 ) ;
}
}
V_184 = F_108 ( T_5 , V_194 [ 7 ] , sizeof( V_144 . V_224 ) / 4 ) ;
if ( V_184 >= 4 ) {
if ( F_101 ( V_5 , & V_144 . V_224 ,
V_194 [ 6 ] , 4 ) < 0 )
return;
F_107 ( V_20 , L_62 ) ;
F_107 ( V_20 , L_63 ,
F_103 ( V_193 ,
F_2 ( V_193 ) ,
V_144 . V_224 . V_221 ) ) ;
F_107 ( V_20 , L_64 , V_144 . V_224 . V_222 ) ;
F_107 ( V_20 , L_65 ,
F_103 ( V_97 , F_2 ( V_97 ) ,
V_144 . V_224 . V_1 ) ) ;
F_107 ( V_20 , L_66 ) ;
if ( V_144 . V_224 . V_223 & V_229 )
F_107 ( V_20 , L_67 ) ;
else
F_107 ( V_20 , L_68 ,
V_144 . V_224 . V_223 ) ;
}
}
static void F_109 ( struct V_5 * V_5 )
{
struct V_189 * V_190 ;
if ( ! F_110 ( V_5 -> V_25 , L_69 , & V_190 ) )
F_111 ( V_190 , V_5 , F_106 ) ;
}
static void F_112 ( struct V_230 * V_25 )
{
struct V_5 * V_5 = V_25 -> V_93 ;
F_113 ( & V_5 -> V_99 ) ;
F_114 ( & V_5 -> V_28 ) ;
F_115 ( & V_5 -> V_111 ) ;
}
static int F_116 ( struct V_231 * V_19 )
{
static const int V_232 [ 10 ] = {
10 , 0x64 / 4 ,
10 , 0x18 / 4 ,
10 , 0x18 / 4 ,
0 , 0 ,
0 , 0 ,
} ;
struct V_17 * V_18 = F_14 ( V_19 ) ;
struct V_233 V_234 ;
int V_235 , V_36 , V_236 = - 1 , V_237 = - 1 , V_8 ;
unsigned int V_238 , V_2 ;
T_3 V_239 [ F_2 ( V_232 ) ] ;
T_3 V_240 [ 4 ] ;
T_3 V_205 ;
F_117 ( & V_234 , V_19 -> V_241 ) ;
while ( F_118 ( & V_234 , & V_235 , & V_36 ) ) {
switch ( V_235 ) {
case V_242 :
V_236 = V_36 ;
break;
case V_243 :
V_237 = V_36 ;
break;
}
}
if ( V_236 == V_244 )
V_238 = V_245 ;
else
V_238 = V_246 ;
if ( V_18 -> V_168 [ 3 ] != ( ( V_236 << 8 ) | V_238 ) ||
V_18 -> V_168 [ 4 ] >> 22 != V_237 )
return - V_247 ;
V_8 = F_18 ( V_19 , V_185 ,
V_14 ,
V_239 , sizeof( V_239 ) , 0 ) ;
if ( V_8 < 0 )
return - V_247 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_239 ) ; ++ V_2 ) {
V_36 = F_119 ( V_239 [ V_2 ] ) ;
if ( V_36 < V_232 [ V_2 ] || V_36 >= 0x40000 )
return - V_247 ;
}
V_8 = F_18 ( V_19 , V_185 ,
V_14 +
F_119 ( V_239 [ 2 ] ) * 4 ,
V_240 , sizeof( V_240 ) , 0 ) ;
if ( V_8 < 0 || ( V_240 [ 0 ] && V_240 [ 3 ] ) )
return - V_247 ;
V_8 = F_18 ( V_19 , V_248 ,
V_14 +
F_119 ( V_239 [ 0 ] ) * 4 + V_249 ,
& V_205 , 4 , 0 ) ;
if ( V_8 < 0 )
return - V_247 ;
if ( ( V_205 & F_25 ( 0xff000000 ) ) != F_25 ( 0x01000000 ) ) {
F_19 ( & V_19 -> V_18 ,
L_70 , F_119 ( V_205 ) ) ;
return - V_247 ;
}
return 0 ;
}
static int F_120 ( struct V_5 * V_5 , unsigned int V_70 )
{
int V_2 ;
for ( V_2 = F_2 ( V_3 ) - 1 ; V_2 >= 0 ; -- V_2 )
if ( ( V_5 -> V_71 & ( 1 << V_2 ) ) &&
F_3 ( V_2 ) == V_70 )
return V_2 ;
return - 1 ;
}
static int F_121 ( struct V_5 * V_5 , unsigned int V_70 )
{
T_3 V_250 [ 2 ] ;
int V_4 , V_8 ;
V_4 = F_120 ( V_5 , V_70 ) ;
if ( V_4 < 0 ) {
V_5 -> V_72 [ V_70 ] = 0 ;
V_5 -> V_116 [ V_70 ] = 0 ;
return 0 ;
}
V_8 = F_55 ( V_5 , V_4 << V_112 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_18 ( V_5 -> V_19 , V_185 ,
F_12 ( V_5 , V_251 ) ,
V_250 , 2 * 4 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 -> V_72 [ V_70 ] = F_119 ( V_250 [ 0 ] ) ;
V_5 -> V_116 [ V_70 ] = F_119 ( V_250 [ 1 ] ) ;
return 0 ;
}
static int F_122 ( struct V_5 * V_5 )
{
T_3 V_239 [ 6 ] ;
T_3 V_36 ;
int V_70 , V_8 ;
V_8 = F_18 ( V_5 -> V_19 , V_185 ,
V_14 ,
V_239 , sizeof( V_239 ) , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 -> V_15 = F_119 ( V_239 [ 0 ] ) * 4 ;
V_5 -> V_16 = F_119 ( V_239 [ 4 ] ) * 4 ;
if ( F_119 ( V_239 [ 1 ] ) * 4 >= V_252 + 4 ) {
V_8 = F_18 (
V_5 -> V_19 , V_248 ,
F_11 ( V_5 , V_252 ) ,
& V_36 , 4 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 -> V_71 = F_119 ( V_36 ) ;
} else {
V_5 -> V_71 = V_253 |
V_254 |
V_255 |
V_256 ;
}
for ( V_70 = 2 ; V_70 >= 0 ; -- V_70 ) {
V_8 = F_121 ( V_5 , V_70 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static void F_123 ( struct V_5 * V_5 )
{
struct V_230 * V_25 = V_5 -> V_25 ;
struct V_17 * V_163 = F_14 ( V_5 -> V_19 ) ;
char V_236 [ 32 ] , V_237 [ 32 ] ;
unsigned int V_2 ;
int V_8 ;
strcpy ( V_25 -> V_257 , L_3 ) ;
strcpy ( V_25 -> V_139 , L_3 ) ;
F_124 ( V_200 < sizeof( V_25 -> V_139 ) ) ;
V_8 = F_18 ( V_5 -> V_19 , V_185 ,
F_11 ( V_5 , V_258 ) ,
V_25 -> V_139 , sizeof( V_25 -> V_139 ) , 0 ) ;
if ( V_8 >= 0 ) {
F_124 ( sizeof( V_25 -> V_139 ) % 4 != 0 ) ;
for ( V_2 = 0 ; V_2 < sizeof( V_25 -> V_139 ) ; V_2 += 4 )
F_125 ( ( T_5 * ) & V_25 -> V_139 [ V_2 ] ) ;
V_25 -> V_139 [ sizeof( V_25 -> V_139 ) - 1 ] = '\0' ;
}
strcpy ( V_236 , L_71 ) ;
F_126 ( V_163 -> V_168 + 5 , V_259 , V_236 , sizeof( V_236 ) ) ;
strcpy ( V_237 , L_71 ) ;
F_126 ( V_5 -> V_19 -> V_241 , V_243 , V_237 , sizeof( V_237 ) ) ;
snprintf ( V_25 -> V_260 , sizeof( V_25 -> V_260 ) ,
L_72 ,
V_236 , V_237 , V_163 -> V_168 [ 4 ] & 0x3fffff ,
F_92 ( & V_5 -> V_19 -> V_18 ) , 100 << V_163 -> V_102 ) ;
strcpy ( V_25 -> V_261 , L_3 ) ;
}
static int F_127 ( struct V_231 * V_19 , const struct V_262 * V_263 )
{
struct V_230 * V_25 ;
struct V_5 * V_5 ;
T_3 V_264 ;
int V_8 ;
V_8 = F_116 ( V_19 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_128 ( & V_19 -> V_18 , - 1 , NULL , V_265 ,
sizeof( * V_5 ) , & V_25 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 = V_25 -> V_93 ;
V_5 -> V_25 = V_25 ;
F_129 ( & V_5 -> V_9 ) ;
F_130 ( & V_5 -> V_111 ) ;
V_5 -> V_19 = V_19 ;
F_131 ( & V_5 -> V_56 ) ;
F_132 ( & V_5 -> V_7 ) ;
V_5 -> V_28 . V_47 = 4 ;
V_5 -> V_28 . V_266 = F_27 ;
V_5 -> V_28 . V_48 = V_5 ;
V_8 = F_133 ( & V_5 -> V_28 ,
& V_267 ) ;
if ( V_8 < 0 )
goto V_268;
V_8 = F_13 ( V_5 ) ;
if ( V_8 < 0 )
goto V_269;
V_8 = F_122 ( V_5 ) ;
if ( V_8 < 0 )
goto V_270;
V_8 = F_134 ( & V_5 -> V_100 , V_19 ) ;
if ( V_8 < 0 )
goto V_270;
V_5 -> V_100 . V_271 = 0x00000000ffffffffuLL ;
V_8 = F_135 ( & V_5 -> V_99 , V_19 , V_272 ,
V_273 ) ;
if ( V_8 < 0 )
goto V_105;
V_25 -> V_274 = F_112 ;
F_123 ( V_5 ) ;
V_8 = F_18 ( V_19 , V_248 ,
F_11 ( V_5 , V_109 ) ,
& V_264 , 4 , 0 ) ;
if ( V_8 < 0 )
goto error;
V_264 &= F_25 ( ~ V_225 ) ;
V_264 |= F_25 ( V_108 ) ;
V_8 = F_18 ( V_19 , V_37 ,
F_11 ( V_5 , V_109 ) ,
& V_264 , 4 , 0 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_79 ( V_5 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_99 ( V_5 ) ;
if ( V_8 < 0 )
goto error;
F_109 ( V_5 ) ;
V_8 = F_136 ( V_25 ) ;
if ( V_8 < 0 )
goto error;
F_137 ( & V_19 -> V_18 , V_5 ) ;
return 0 ;
V_105:
F_138 ( & V_5 -> V_100 ) ;
V_270:
F_23 ( V_5 ) ;
V_269:
F_114 ( & V_5 -> V_28 ) ;
V_268:
F_115 ( & V_5 -> V_111 ) ;
error:
F_139 ( V_25 ) ;
return V_8 ;
}
static void F_140 ( struct V_231 * V_19 )
{
struct V_5 * V_5 = F_141 ( & V_19 -> V_18 ) ;
F_142 ( & V_5 -> V_99 ) ;
F_143 ( V_5 -> V_25 ) ;
F_61 ( & V_5 -> V_111 ) ;
F_54 ( V_5 ) ;
F_23 ( V_5 ) ;
F_62 ( & V_5 -> V_111 ) ;
F_144 ( V_5 -> V_25 ) ;
}
static void F_145 ( struct V_231 * V_19 )
{
struct V_5 * V_5 = F_141 ( & V_19 -> V_18 ) ;
F_142 ( & V_5 -> V_99 ) ;
F_61 ( & V_5 -> V_111 ) ;
V_5 -> V_39 = false ;
F_53 ( V_5 ) ;
F_22 ( V_5 ) ;
F_146 ( & V_5 -> V_100 ) ;
F_62 ( & V_5 -> V_111 ) ;
}
static int T_10 F_147 ( void )
{
return F_148 ( & V_275 . V_257 ) ;
}
static void T_11 F_149 ( void )
{
F_150 ( & V_275 . V_257 ) ;
}
