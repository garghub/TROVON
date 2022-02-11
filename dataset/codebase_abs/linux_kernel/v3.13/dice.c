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
V_8 = F_43 ( V_95 , 0 ,
V_99 , 32 ) ;
if ( V_8 < 0 )
goto V_98;
V_8 = F_43 ( V_95 , 0 ,
V_100 , 32 ) ;
if ( V_8 < 0 )
goto V_98;
V_8 = F_44 ( V_95 ,
V_101 ,
5000 , V_68 ) ;
if ( V_8 < 0 )
goto V_98;
V_8 = F_45 ( V_95 , 0 , 32 , 24 ) ;
if ( V_8 < 0 )
goto V_98;
return 0 ;
V_98:
F_9 ( V_5 ) ;
error:
return V_8 ;
}
static int F_46 ( struct V_74 * V_75 )
{
struct V_5 * V_5 = V_75 -> V_93 ;
F_9 ( V_5 ) ;
return 0 ;
}
static int F_47 ( struct V_5 * V_5 )
{
int V_8 ;
if ( F_48 ( & V_5 -> V_102 ) )
return 0 ;
V_8 = F_49 ( & V_5 -> V_102 , V_5 -> V_103 . V_104 ,
F_14 ( V_5 -> V_19 ) -> V_105 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_24 ( V_5 ) ;
if ( V_8 < 0 ) {
F_50 ( & V_5 -> V_102 ) ;
return V_8 ;
}
return 0 ;
}
static int F_51 ( struct V_5 * V_5 )
{
T_3 V_104 ;
int V_8 ;
if ( ! V_5 -> V_103 . V_106 ) {
V_8 = F_52 ( & V_5 -> V_103 ,
F_53 ( & V_5 -> V_102 ) ,
F_14 ( V_5 -> V_19 ) -> V_105 ) ;
if ( V_8 < 0 )
goto error;
V_104 = F_25 ( V_5 -> V_103 . V_104 ) ;
V_8 = F_18 ( V_5 -> V_19 ,
V_37 ,
F_12 ( V_5 , V_107 ) ,
& V_104 , 4 , 0 ) ;
if ( V_8 < 0 )
goto V_108;
}
V_8 = F_47 ( V_5 ) ;
if ( V_8 < 0 )
goto V_109;
return 0 ;
V_109:
V_104 = F_25 ( ( T_5 ) - 1 ) ;
F_18 ( V_5 -> V_19 , V_37 ,
F_12 ( V_5 , V_107 ) , & V_104 , 4 , 0 ) ;
V_108:
F_54 ( & V_5 -> V_103 ) ;
error:
return V_8 ;
}
static void F_55 ( struct V_5 * V_5 )
{
if ( F_48 ( & V_5 -> V_102 ) ) {
F_26 ( V_5 ) ;
F_50 ( & V_5 -> V_102 ) ;
}
}
static void F_56 ( struct V_5 * V_5 )
{
T_3 V_104 ;
F_55 ( V_5 ) ;
if ( ! V_5 -> V_103 . V_106 )
return;
V_104 = F_25 ( ( T_5 ) - 1 ) ;
F_18 ( V_5 -> V_19 , V_37 ,
F_12 ( V_5 , V_107 ) , & V_104 , 4 , 0 ) ;
F_54 ( & V_5 -> V_103 ) ;
}
static int F_57 ( struct V_5 * V_5 , unsigned int V_110 )
{
T_3 V_36 ;
int V_8 ;
F_58 ( & V_5 -> V_56 ) ;
V_36 = F_25 ( V_110 | V_111 ) ;
V_8 = F_18 ( V_5 -> V_19 , V_37 ,
F_11 ( V_5 , V_112 ) ,
& V_36 , 4 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! F_59 ( & V_5 -> V_56 ,
F_60 ( 100 ) ) )
F_61 ( & V_5 -> V_19 -> V_18 , L_2 ) ;
return 0 ;
}
static int F_62 ( struct V_74 * V_75 ,
struct V_57 * V_113 )
{
struct V_5 * V_5 = V_75 -> V_93 ;
unsigned int V_4 , V_70 ;
int V_8 ;
F_63 ( & V_5 -> V_114 ) ;
F_56 ( V_5 ) ;
F_64 ( & V_5 -> V_114 ) ;
V_8 = F_65 ( V_75 ,
F_66 ( V_113 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_4 = F_1 ( F_67 ( V_113 ) ) ;
V_8 = F_57 ( V_5 , V_4 << V_115 ) ;
if ( V_8 < 0 )
return V_8 ;
V_70 = F_3 ( V_4 ) ;
F_68 ( & V_5 -> V_102 ,
F_67 ( V_113 ) ,
F_69 ( V_113 ) ,
V_5 -> V_116 [ V_70 ] ) ;
F_70 ( & V_5 -> V_102 ,
F_71 ( V_113 ) ) ;
return 0 ;
}
static int F_72 ( struct V_74 * V_75 )
{
struct V_5 * V_5 = V_75 -> V_93 ;
F_63 ( & V_5 -> V_114 ) ;
F_56 ( V_5 ) ;
F_64 ( & V_5 -> V_114 ) ;
return F_73 ( V_75 ) ;
}
static int F_74 ( struct V_74 * V_75 )
{
struct V_5 * V_5 = V_75 -> V_93 ;
int V_8 ;
F_63 ( & V_5 -> V_114 ) ;
if ( F_75 ( & V_5 -> V_102 ) )
F_55 ( V_5 ) ;
V_8 = F_51 ( V_5 ) ;
if ( V_8 < 0 ) {
F_64 ( & V_5 -> V_114 ) ;
return V_8 ;
}
F_64 ( & V_5 -> V_114 ) ;
F_76 ( & V_5 -> V_102 ) ;
return 0 ;
}
static int F_77 ( struct V_74 * V_75 , int V_117 )
{
struct V_5 * V_5 = V_75 -> V_93 ;
struct V_74 * V_118 ;
switch ( V_117 ) {
case V_119 :
V_118 = V_75 ;
break;
case V_120 :
V_118 = NULL ;
break;
default:
return - V_121 ;
}
F_78 ( & V_5 -> V_102 , V_118 ) ;
return 0 ;
}
static T_6 F_79 ( struct V_74 * V_75 )
{
struct V_5 * V_5 = V_75 -> V_93 ;
return F_80 ( & V_5 -> V_102 ) ;
}
static int F_81 ( struct V_5 * V_5 )
{
static struct V_122 V_123 = {
. V_124 = F_39 ,
. V_125 = F_46 ,
. V_126 = V_127 ,
. V_113 = F_62 ,
. V_128 = F_72 ,
. V_129 = F_74 ,
. V_130 = F_77 ,
. V_131 = F_79 ,
. V_132 = V_133 ,
. V_134 = V_135 ,
} ;
struct V_136 * V_118 ;
int V_8 ;
V_8 = F_82 ( V_5 -> V_25 , L_3 , 0 , 1 , 0 , & V_118 ) ;
if ( V_8 < 0 )
return V_8 ;
V_118 -> V_93 = V_5 ;
strcpy ( V_118 -> V_137 , V_5 -> V_25 -> V_138 ) ;
V_118 -> V_139 [ V_140 ] . V_75 -> V_123 = & V_123 ;
return 0 ;
}
static long F_83 ( struct V_141 * V_142 , char T_7 * V_143 ,
long V_144 , T_8 * V_13 )
{
struct V_5 * V_5 = V_142 -> V_93 ;
F_84 ( V_145 ) ;
union V_146 V_147 ;
F_7 ( & V_5 -> V_9 ) ;
while ( ! V_5 -> V_6 && V_5 -> V_53 == 0 ) {
F_85 ( & V_5 -> V_7 , & V_145 , V_148 ) ;
F_8 ( & V_5 -> V_9 ) ;
F_86 () ;
F_87 ( & V_5 -> V_7 , & V_145 ) ;
if ( F_88 ( V_149 ) )
return - V_150 ;
F_7 ( & V_5 -> V_9 ) ;
}
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
if ( V_5 -> V_6 ) {
V_147 . V_151 . type = V_152 ;
V_147 . V_151 . V_153 = V_5 -> V_10 > 0 ;
V_5 -> V_6 = false ;
V_144 = V_67 ( V_144 , ( long ) sizeof( V_147 . V_151 ) ) ;
} else {
V_147 . F_27 . type = V_154 ;
V_147 . F_27 . V_155 = V_5 -> V_53 ;
V_5 -> V_53 = 0 ;
V_144 = V_67 ( V_144 , ( long ) sizeof( V_147 . F_27 ) ) ;
}
F_8 ( & V_5 -> V_9 ) ;
if ( F_89 ( V_143 , & V_147 , V_144 ) )
return - V_156 ;
return V_144 ;
}
static unsigned int F_90 ( struct V_141 * V_142 , struct V_157 * V_157 ,
T_9 * V_145 )
{
struct V_5 * V_5 = V_142 -> V_93 ;
unsigned int V_158 ;
F_91 ( V_157 , & V_5 -> V_7 , V_145 ) ;
F_7 ( & V_5 -> V_9 ) ;
if ( V_5 -> V_6 || V_5 -> V_53 != 0 )
V_158 = V_159 | V_160 ;
else
V_158 = 0 ;
F_8 ( & V_5 -> V_9 ) ;
return V_158 ;
}
static int F_92 ( struct V_5 * V_5 , void T_7 * V_161 )
{
struct V_17 * V_162 = F_14 ( V_5 -> V_19 ) ;
struct V_163 V_78 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . type = V_164 ;
V_78 . V_25 = V_162 -> V_25 -> V_165 ;
* ( T_3 * ) & V_78 . V_166 [ 0 ] = F_25 ( V_162 -> V_167 [ 3 ] ) ;
* ( T_3 * ) & V_78 . V_166 [ 4 ] = F_25 ( V_162 -> V_167 [ 4 ] ) ;
F_93 ( V_78 . V_168 , F_94 ( & V_162 -> V_18 ) ,
sizeof( V_78 . V_168 ) ) ;
if ( F_89 ( V_161 , & V_78 , sizeof( V_78 ) ) )
return - V_156 ;
return 0 ;
}
static int F_95 ( struct V_5 * V_5 )
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
static int F_96 ( struct V_5 * V_5 )
{
int V_8 ;
F_7 ( & V_5 -> V_9 ) ;
if ( V_5 -> V_10 == - 1 ) {
V_5 -> V_10 = 0 ;
V_8 = 0 ;
} else {
V_8 = - V_169 ;
}
F_8 ( & V_5 -> V_9 ) ;
return V_8 ;
}
static int F_97 ( struct V_141 * V_142 , struct V_157 * V_157 )
{
struct V_5 * V_5 = V_142 -> V_93 ;
F_7 ( & V_5 -> V_9 ) ;
if ( V_5 -> V_10 == - 1 )
V_5 -> V_10 = 0 ;
F_8 ( & V_5 -> V_9 ) ;
return 0 ;
}
static int F_98 ( struct V_141 * V_142 , struct V_157 * V_157 ,
unsigned int V_117 , unsigned long V_161 )
{
struct V_5 * V_5 = V_142 -> V_93 ;
switch ( V_117 ) {
case V_170 :
return F_92 ( V_5 , ( void T_7 * ) V_161 ) ;
case V_171 :
return F_95 ( V_5 ) ;
case V_172 :
return F_96 ( V_5 ) ;
default:
return - V_173 ;
}
}
static int F_99 ( struct V_141 * V_142 , struct V_157 * V_157 ,
unsigned int V_117 , unsigned long V_161 )
{
return F_98 ( V_142 , V_157 , V_117 ,
( unsigned long ) F_100 ( V_161 ) ) ;
}
static int F_101 ( struct V_5 * V_5 )
{
static const struct V_174 V_123 = {
. V_175 = F_83 ,
. V_176 = F_97 ,
. V_177 = F_90 ,
. V_126 = F_98 ,
. V_178 = F_99 ,
} ;
struct V_141 * V_142 ;
int V_8 ;
V_8 = F_102 ( V_5 -> V_25 , L_3 , 0 , & V_142 ) ;
if ( V_8 < 0 )
return V_8 ;
strcpy ( V_142 -> V_137 , L_3 ) ;
V_142 -> V_179 = V_180 ;
V_142 -> V_123 = V_123 ;
V_142 -> V_93 = V_5 ;
V_142 -> V_181 = true ;
return 0 ;
}
static int F_103 ( struct V_5 * V_5 , void * V_20 ,
unsigned int V_182 , unsigned int V_183 )
{
unsigned int V_2 ;
int V_8 ;
V_8 = F_18 ( V_5 -> V_19 , V_184 ,
V_14 + 4 * V_182 ,
V_20 , 4 * V_183 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_2 = 0 ; V_2 < V_183 ; ++ V_2 )
F_104 ( & ( ( T_5 * ) V_20 ) [ V_2 ] ) ;
return 0 ;
}
static const char * F_105 ( const char * const V_185 [] , unsigned int V_144 ,
unsigned int V_2 )
{
if ( V_2 < V_144 )
return V_185 [ V_2 ] ;
else
return L_4 ;
}
static void F_106 ( char * V_186 , unsigned int V_187 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_187 ; V_2 += 4 )
F_107 ( ( T_5 * ) ( V_186 + V_2 ) ) ;
for ( V_2 = 0 ; V_2 < V_187 - 2 ; ++ V_2 ) {
if ( V_186 [ V_2 ] == '\0' )
return;
if ( V_186 [ V_2 ] == '\\' && V_186 [ V_2 + 1 ] == '\\' ) {
V_186 [ V_2 + 2 ] = '\0' ;
return;
}
}
V_186 [ V_187 - 1 ] = '\0' ;
}
static void F_108 ( struct V_188 * V_189 ,
struct V_190 * V_20 )
{
static const char * const V_191 [ 5 ] = {
L_5 , L_6 , L_7 , L_8 , L_9
} ;
static const char * const V_192 [] = {
L_10 , L_11 , L_12 , L_13 , L_14 , L_15 , L_16 ,
L_17 , L_18 , L_19 , L_20 , L_21 , L_22
} ;
static const char * const V_97 [] = {
L_23 , L_24 , L_25 , L_26 , L_27 , L_28 , L_29 ,
L_30 , L_31 , L_32 , L_33
} ;
struct V_5 * V_5 = V_189 -> V_93 ;
T_5 V_193 [ F_2 ( V_191 ) * 2 ] ;
struct {
T_5 V_194 ;
T_5 V_187 ;
} V_195 ;
union {
struct {
T_5 V_196 , V_197 ;
T_5 V_155 ;
char V_198 [ V_199 ] ;
T_5 V_200 ;
T_5 V_201 ;
T_5 V_153 ;
T_5 V_202 ;
T_5 V_203 ;
T_5 V_204 ;
T_5 V_71 ;
char V_205 [ V_206 ] ;
} V_207 ;
struct {
T_5 V_208 ;
T_5 V_209 ;
T_5 V_210 ;
T_5 V_211 ;
char V_212 [ V_213 ] ;
T_5 V_214 ;
T_5 V_215 ;
} V_216 ;
struct {
T_5 V_208 ;
T_5 V_217 ;
T_5 V_209 ;
T_5 V_210 ;
char V_212 [ V_218 ] ;
T_5 V_214 ;
T_5 V_215 ;
} V_219 ;
struct {
T_5 V_220 ;
T_5 V_221 ;
T_5 V_1 ;
T_5 V_222 ;
} V_223 ;
} V_143 ;
unsigned int V_183 , V_102 , V_2 ;
if ( F_103 ( V_5 , V_193 , 0 , F_2 ( V_193 ) ) < 0 )
return;
F_109 ( V_20 , L_34 ) ;
for ( V_2 = 0 ; V_2 < F_2 ( V_191 ) ; ++ V_2 )
F_109 ( V_20 , L_35 ,
V_191 [ V_2 ] ,
V_193 [ V_2 * 2 ] , V_193 [ V_2 * 2 + 1 ] ) ;
V_183 = F_110 ( T_5 , V_193 [ 1 ] , sizeof( V_143 . V_207 ) / 4 ) ;
if ( F_103 ( V_5 , & V_143 . V_207 , V_193 [ 0 ] , V_183 ) < 0 )
return;
F_109 ( V_20 , L_36 ) ;
F_109 ( V_20 , L_37 ,
V_143 . V_207 . V_196 >> 16 ,
V_143 . V_207 . V_196 & 0xffff , V_143 . V_207 . V_197 ) ;
F_109 ( V_20 , L_38 , V_143 . V_207 . V_155 ) ;
F_106 ( V_143 . V_207 . V_198 , V_199 ) ;
F_109 ( V_20 , L_39 , V_143 . V_207 . V_198 ) ;
F_109 ( V_20 , L_40 ,
F_105 ( V_192 , F_2 ( V_192 ) ,
V_143 . V_207 . V_200 & V_224 ) ,
F_105 ( V_97 , F_2 ( V_97 ) ,
( V_143 . V_207 . V_200 & V_225 )
>> V_115 ) ) ;
F_109 ( V_20 , L_41 , V_143 . V_207 . V_201 ) ;
F_109 ( V_20 , L_42 ,
V_143 . V_207 . V_153 & V_226 ? L_43 : L_44 ,
F_105 ( V_97 , F_2 ( V_97 ) ,
( V_143 . V_207 . V_153 &
V_227 )
>> V_115 ) ) ;
F_109 ( V_20 , L_45 , V_143 . V_207 . V_202 ) ;
F_109 ( V_20 , L_46 , V_143 . V_207 . V_203 ) ;
F_109 ( V_20 , L_47 ,
( V_143 . V_207 . V_204 >> 24 ) & 0xff ,
( V_143 . V_207 . V_204 >> 16 ) & 0xff ,
( V_143 . V_207 . V_204 >> 8 ) & 0xff ,
( V_143 . V_207 . V_204 >> 0 ) & 0xff ) ;
if ( V_183 >= 90 ) {
F_109 ( V_20 , L_48 ) ;
for ( V_2 = 0 ; V_2 <= 6 ; ++ V_2 )
if ( V_143 . V_207 . V_71 & ( 1 << V_2 ) )
F_109 ( V_20 , L_49 , V_97 [ V_2 ] ) ;
for ( V_2 = 0 ; V_2 <= 12 ; ++ V_2 )
if ( V_143 . V_207 . V_71 & ( 1 << ( 16 + V_2 ) ) )
F_109 ( V_20 , L_49 , V_192 [ V_2 ] ) ;
F_109 ( V_20 , L_50 ) ;
F_106 ( V_143 . V_207 . V_205 ,
V_206 ) ;
F_109 ( V_20 , L_51 ,
V_143 . V_207 . V_205 ) ;
}
if ( F_103 ( V_5 , & V_195 , V_193 [ 2 ] , 2 ) < 0 )
return;
V_183 = F_110 ( T_5 , V_195 . V_187 , sizeof( V_143 . V_216 ) / 4 ) ;
for ( V_102 = 0 ; V_102 < V_195 . V_194 ; ++ V_102 ) {
if ( F_103 ( V_5 , & V_143 . V_216 , V_193 [ 2 ] + 2 +
V_102 * V_195 . V_187 ,
V_183 ) < 0 )
break;
F_109 ( V_20 , L_52 , V_102 ) ;
F_109 ( V_20 , L_53 , ( int ) V_143 . V_216 . V_208 ) ;
F_109 ( V_20 , L_54 ,
V_143 . V_216 . V_209 ) ;
F_109 ( V_20 , L_55 , V_143 . V_216 . V_210 ) ;
F_109 ( V_20 , L_56 , 100u << V_143 . V_216 . V_211 ) ;
if ( V_183 >= 68 ) {
F_106 ( V_143 . V_216 . V_212 , V_213 ) ;
F_109 ( V_20 , L_57 , V_143 . V_216 . V_212 ) ;
}
if ( V_183 >= 70 ) {
F_109 ( V_20 , L_58 ,
V_143 . V_216 . V_214 ) ;
F_109 ( V_20 , L_59 ,
V_143 . V_216 . V_215 ) ;
}
}
if ( F_103 ( V_5 , & V_195 , V_193 [ 4 ] , 2 ) < 0 )
return;
V_183 = F_110 ( T_5 , V_195 . V_187 , sizeof( V_143 . V_219 ) / 4 ) ;
for ( V_102 = 0 ; V_102 < V_195 . V_194 ; ++ V_102 ) {
if ( F_103 ( V_5 , & V_143 . V_219 , V_193 [ 4 ] + 2 +
V_102 * V_195 . V_187 ,
V_183 ) < 0 )
break;
F_109 ( V_20 , L_60 , V_102 ) ;
F_109 ( V_20 , L_53 , ( int ) V_143 . V_219 . V_208 ) ;
F_109 ( V_20 , L_61 , V_143 . V_219 . V_217 ) ;
F_109 ( V_20 , L_54 ,
V_143 . V_219 . V_209 ) ;
F_109 ( V_20 , L_55 , V_143 . V_219 . V_210 ) ;
if ( V_183 >= 68 ) {
F_106 ( V_143 . V_219 . V_212 , V_218 ) ;
F_109 ( V_20 , L_57 , V_143 . V_219 . V_212 ) ;
}
if ( V_183 >= 70 ) {
F_109 ( V_20 , L_58 ,
V_143 . V_219 . V_214 ) ;
F_109 ( V_20 , L_59 ,
V_143 . V_219 . V_215 ) ;
}
}
V_183 = F_110 ( T_5 , V_193 [ 7 ] , sizeof( V_143 . V_223 ) / 4 ) ;
if ( V_183 >= 4 ) {
if ( F_103 ( V_5 , & V_143 . V_223 ,
V_193 [ 6 ] , 4 ) < 0 )
return;
F_109 ( V_20 , L_62 ) ;
F_109 ( V_20 , L_63 ,
F_105 ( V_192 ,
F_2 ( V_192 ) ,
V_143 . V_223 . V_220 ) ) ;
F_109 ( V_20 , L_64 , V_143 . V_223 . V_221 ) ;
F_109 ( V_20 , L_65 ,
F_105 ( V_97 , F_2 ( V_97 ) ,
V_143 . V_223 . V_1 ) ) ;
F_109 ( V_20 , L_66 ) ;
if ( V_143 . V_223 . V_222 & V_228 )
F_109 ( V_20 , L_67 ) ;
else
F_109 ( V_20 , L_68 ,
V_143 . V_223 . V_222 ) ;
}
}
static void F_111 ( struct V_5 * V_5 )
{
struct V_188 * V_189 ;
if ( ! F_112 ( V_5 -> V_25 , L_69 , & V_189 ) )
F_113 ( V_189 , V_5 , F_108 ) ;
}
static void F_114 ( struct V_229 * V_25 )
{
struct V_5 * V_5 = V_25 -> V_93 ;
F_115 ( & V_5 -> V_102 ) ;
F_116 ( & V_5 -> V_28 ) ;
F_117 ( & V_5 -> V_114 ) ;
}
static int F_118 ( struct V_230 * V_19 )
{
static const int V_231 [ 10 ] = {
10 , 0x64 / 4 ,
10 , 0x18 / 4 ,
10 , 0x18 / 4 ,
0 , 0 ,
0 , 0 ,
} ;
struct V_17 * V_18 = F_14 ( V_19 ) ;
struct V_232 V_233 ;
int V_234 , V_36 , V_235 = - 1 , V_236 = - 1 , V_8 ;
unsigned int V_237 , V_2 ;
T_3 V_238 [ F_2 ( V_231 ) ] ;
T_3 V_239 [ 4 ] ;
T_3 V_204 ;
F_119 ( & V_233 , V_19 -> V_240 ) ;
while ( F_120 ( & V_233 , & V_234 , & V_36 ) ) {
switch ( V_234 ) {
case V_241 :
V_235 = V_36 ;
break;
case V_242 :
V_236 = V_36 ;
break;
}
}
if ( V_235 == V_243 )
V_237 = V_244 ;
else
V_237 = V_245 ;
if ( V_18 -> V_167 [ 3 ] != ( ( V_235 << 8 ) | V_237 ) ||
V_18 -> V_167 [ 4 ] >> 22 != V_236 )
return - V_246 ;
V_8 = F_18 ( V_19 , V_184 ,
V_14 ,
V_238 , sizeof( V_238 ) , 0 ) ;
if ( V_8 < 0 )
return - V_246 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_238 ) ; ++ V_2 ) {
V_36 = F_121 ( V_238 [ V_2 ] ) ;
if ( V_36 < V_231 [ V_2 ] || V_36 >= 0x40000 )
return - V_246 ;
}
V_8 = F_18 ( V_19 , V_184 ,
V_14 +
F_121 ( V_238 [ 2 ] ) * 4 ,
V_239 , sizeof( V_239 ) , 0 ) ;
if ( V_8 < 0 || ( V_239 [ 0 ] && V_239 [ 3 ] ) )
return - V_246 ;
V_8 = F_18 ( V_19 , V_247 ,
V_14 +
F_121 ( V_238 [ 0 ] ) * 4 + V_248 ,
& V_204 , 4 , 0 ) ;
if ( V_8 < 0 )
return - V_246 ;
if ( ( V_204 & F_25 ( 0xff000000 ) ) != F_25 ( 0x01000000 ) ) {
F_19 ( & V_19 -> V_18 ,
L_70 , F_121 ( V_204 ) ) ;
return - V_246 ;
}
return 0 ;
}
static int F_122 ( struct V_5 * V_5 , unsigned int V_70 )
{
int V_2 ;
for ( V_2 = F_2 ( V_3 ) - 1 ; V_2 >= 0 ; -- V_2 )
if ( ( V_5 -> V_71 & ( 1 << V_2 ) ) &&
F_3 ( V_2 ) == V_70 )
return V_2 ;
return - 1 ;
}
static int F_123 ( struct V_5 * V_5 , unsigned int V_70 )
{
T_3 V_249 [ 2 ] ;
int V_4 , V_8 ;
V_4 = F_122 ( V_5 , V_70 ) ;
if ( V_4 < 0 ) {
V_5 -> V_72 [ V_70 ] = 0 ;
V_5 -> V_116 [ V_70 ] = 0 ;
return 0 ;
}
V_8 = F_57 ( V_5 , V_4 << V_115 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_18 ( V_5 -> V_19 , V_184 ,
F_12 ( V_5 , V_250 ) ,
V_249 , 2 * 4 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 -> V_72 [ V_70 ] = F_121 ( V_249 [ 0 ] ) ;
V_5 -> V_116 [ V_70 ] = F_121 ( V_249 [ 1 ] ) ;
return 0 ;
}
static int F_124 ( struct V_5 * V_5 )
{
T_3 V_238 [ 6 ] ;
T_3 V_36 ;
int V_70 , V_8 ;
V_8 = F_18 ( V_5 -> V_19 , V_184 ,
V_14 ,
V_238 , sizeof( V_238 ) , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 -> V_15 = F_121 ( V_238 [ 0 ] ) * 4 ;
V_5 -> V_16 = F_121 ( V_238 [ 4 ] ) * 4 ;
if ( F_121 ( V_238 [ 1 ] ) * 4 >= V_251 + 4 ) {
V_8 = F_18 (
V_5 -> V_19 , V_247 ,
F_11 ( V_5 , V_251 ) ,
& V_36 , 4 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 -> V_71 = F_121 ( V_36 ) ;
} else {
V_5 -> V_71 = V_252 |
V_253 |
V_254 |
V_255 ;
}
for ( V_70 = 2 ; V_70 >= 0 ; -- V_70 ) {
V_8 = F_123 ( V_5 , V_70 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static void F_125 ( struct V_5 * V_5 )
{
struct V_229 * V_25 = V_5 -> V_25 ;
struct V_17 * V_162 = F_14 ( V_5 -> V_19 ) ;
char V_235 [ 32 ] , V_236 [ 32 ] ;
unsigned int V_2 ;
int V_8 ;
strcpy ( V_25 -> V_256 , L_3 ) ;
strcpy ( V_25 -> V_138 , L_3 ) ;
F_126 ( V_199 < sizeof( V_25 -> V_138 ) ) ;
V_8 = F_18 ( V_5 -> V_19 , V_184 ,
F_11 ( V_5 , V_257 ) ,
V_25 -> V_138 , sizeof( V_25 -> V_138 ) , 0 ) ;
if ( V_8 >= 0 ) {
F_126 ( sizeof( V_25 -> V_138 ) % 4 != 0 ) ;
for ( V_2 = 0 ; V_2 < sizeof( V_25 -> V_138 ) ; V_2 += 4 )
F_127 ( ( T_5 * ) & V_25 -> V_138 [ V_2 ] ) ;
V_25 -> V_138 [ sizeof( V_25 -> V_138 ) - 1 ] = '\0' ;
}
strcpy ( V_235 , L_71 ) ;
F_128 ( V_162 -> V_167 + 5 , V_258 , V_235 , sizeof( V_235 ) ) ;
strcpy ( V_236 , L_71 ) ;
F_128 ( V_5 -> V_19 -> V_240 , V_242 , V_236 , sizeof( V_236 ) ) ;
snprintf ( V_25 -> V_259 , sizeof( V_25 -> V_259 ) ,
L_72 ,
V_235 , V_236 , V_162 -> V_167 [ 4 ] & 0x3fffff ,
F_94 ( & V_5 -> V_19 -> V_18 ) , 100 << V_162 -> V_105 ) ;
strcpy ( V_25 -> V_260 , L_3 ) ;
}
static int F_129 ( struct V_230 * V_19 , const struct V_261 * V_262 )
{
struct V_229 * V_25 ;
struct V_5 * V_5 ;
T_3 V_263 ;
int V_8 ;
V_8 = F_118 ( V_19 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_130 ( - 1 , NULL , V_264 , sizeof( * V_5 ) , & V_25 ) ;
if ( V_8 < 0 )
return V_8 ;
F_131 ( V_25 , & V_19 -> V_18 ) ;
V_5 = V_25 -> V_93 ;
V_5 -> V_25 = V_25 ;
F_132 ( & V_5 -> V_9 ) ;
F_133 ( & V_5 -> V_114 ) ;
V_5 -> V_19 = V_19 ;
F_134 ( & V_5 -> V_56 ) ;
F_135 ( & V_5 -> V_7 ) ;
V_5 -> V_28 . V_47 = 4 ;
V_5 -> V_28 . V_265 = F_27 ;
V_5 -> V_28 . V_48 = V_5 ;
V_8 = F_136 ( & V_5 -> V_28 ,
& V_266 ) ;
if ( V_8 < 0 )
goto V_267;
V_8 = F_13 ( V_5 ) ;
if ( V_8 < 0 )
goto V_268;
V_8 = F_124 ( V_5 ) ;
if ( V_8 < 0 )
goto V_269;
V_8 = F_137 ( & V_5 -> V_103 , V_19 ) ;
if ( V_8 < 0 )
goto V_269;
V_5 -> V_103 . V_270 = 0x00000000ffffffffuLL ;
V_8 = F_138 ( & V_5 -> V_102 , V_19 ,
V_271 | V_272 ) ;
if ( V_8 < 0 )
goto V_108;
V_25 -> V_273 = F_114 ;
F_125 ( V_5 ) ;
V_8 = F_18 ( V_19 , V_247 ,
F_11 ( V_5 , V_112 ) ,
& V_263 , 4 , 0 ) ;
if ( V_8 < 0 )
goto error;
V_263 &= F_25 ( ~ V_224 ) ;
V_263 |= F_25 ( V_111 ) ;
V_8 = F_18 ( V_19 , V_37 ,
F_11 ( V_5 , V_112 ) ,
& V_263 , 4 , 0 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_81 ( V_5 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_101 ( V_5 ) ;
if ( V_8 < 0 )
goto error;
F_111 ( V_5 ) ;
V_8 = F_139 ( V_25 ) ;
if ( V_8 < 0 )
goto error;
F_140 ( & V_19 -> V_18 , V_5 ) ;
return 0 ;
V_108:
F_141 ( & V_5 -> V_103 ) ;
V_269:
F_23 ( V_5 ) ;
V_268:
F_116 ( & V_5 -> V_28 ) ;
V_267:
F_117 ( & V_5 -> V_114 ) ;
error:
F_142 ( V_25 ) ;
return V_8 ;
}
static void F_143 ( struct V_230 * V_19 )
{
struct V_5 * V_5 = F_144 ( & V_19 -> V_18 ) ;
F_145 ( & V_5 -> V_102 ) ;
F_146 ( V_5 -> V_25 ) ;
F_63 ( & V_5 -> V_114 ) ;
F_56 ( V_5 ) ;
F_23 ( V_5 ) ;
F_64 ( & V_5 -> V_114 ) ;
F_147 ( V_5 -> V_25 ) ;
}
static void F_148 ( struct V_230 * V_19 )
{
struct V_5 * V_5 = F_144 ( & V_19 -> V_18 ) ;
F_145 ( & V_5 -> V_102 ) ;
F_63 ( & V_5 -> V_114 ) ;
V_5 -> V_39 = false ;
F_55 ( V_5 ) ;
F_22 ( V_5 ) ;
F_149 ( & V_5 -> V_103 ) ;
F_64 ( & V_5 -> V_114 ) ;
}
static int T_10 F_150 ( void )
{
return F_151 ( & V_274 . V_256 ) ;
}
static void T_11 F_152 ( void )
{
F_153 ( & V_274 . V_256 ) ;
}
