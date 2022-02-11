void F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
struct V_5 * V_6 ;
const T_1 V_7 = ( V_8 / sizeof( T_1 ) ) - 1 ;
T_1 V_9 = 0 , V_10 = 0 ;
int V_11 = 0 ;
T_1 V_12 ;
if ( ! V_2 || ! V_2 -> V_13 ) {
F_2 ( L_1 ) ;
return;
}
V_6 = V_2 -> V_13 -> V_14 ;
if ( ! V_6 || ! V_6 -> V_15 . V_16 )
return;
V_3 = F_3 ( T_1 , F_4 ( V_2 ) , V_3 ) ;
V_4 = F_5 ( T_1 , F_6 ( V_2 ) , V_4 ) ;
for ( V_12 = V_3 ; V_12 < V_4 ; V_12 += ( T_1 ) V_2 -> V_17 ) {
V_9 = ( V_12 - F_4 ( V_2 ) ) / V_18 ;
if ( V_2 -> V_13 -> V_19 [ V_9 ] &
( V_20 | V_21 ) ) {
if ( ! V_11 ) {
V_10 = V_9 ;
V_11 = 1 ;
}
} else {
T_1 V_22 = V_9 & V_7 ;
if ( V_11 && V_22 == 0 ) {
F_7 ( V_6 , V_10 ,
V_9 - V_10 , 1 ) ;
V_11 = 0 ;
}
}
}
if ( V_11 )
F_7 ( V_6 , V_10 , V_9 - V_10 + 1 ,
1 ) ;
F_8 ( V_2 , V_3 , V_4 ) ;
}
int F_9 ( struct V_23 * V_24 )
{
int V_25 ;
struct V_26 V_27 ;
struct V_28 * V_29 = & V_24 -> V_30 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
if ( ! ( V_24 -> V_31 -> V_29 . V_32 . V_33 & V_34 ) )
return 0 ;
V_25 = F_10 ( V_24 -> V_31 , & V_27 ) ;
if ( V_25 )
goto V_35;
V_29 -> V_36 = V_37 ;
F_11 ( V_27 , V_29 , V_38 . V_39 ,
V_40 ) ;
F_11 ( V_27 , V_29 , V_38 . V_41 ,
V_40 ) ;
F_11 ( V_27 , V_29 , V_38 . V_41 ,
V_42 ) ;
F_11 ( V_27 , V_29 , V_38 . V_41 ,
V_43 ) ;
F_11 ( V_27 , V_29 , V_38 . V_41 ,
V_44 ) ;
V_35:
return V_25 ;
}
static struct V_5 * F_12 ( struct V_23 * V_24 ,
T_2 V_45 )
{
T_2 V_46 = F_13 ( V_45 ) ;
struct V_47 * V_48 = F_14 ( V_24 -> V_31 , V_46 ) ;
struct V_5 * V_6 = F_15 ( V_48 , struct V_5 , V_48 ) ;
if ( ! V_48 || V_48 -> V_45 != V_45 || ! V_6 -> V_49 )
return NULL ;
return F_15 ( V_48 , struct V_5 , V_48 ) ;
}
static void F_16 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
int error ) {
struct V_23 * V_24 = F_17 ( V_51 -> V_54 . V_16 -> V_55 ) ;
int V_56 = F_18 ( V_24 -> V_31 , V_51 -> V_57 . V_58 ,
V_53 -> V_59 . V_33 ,
error ) ;
if ( V_56 )
F_2 ( L_2 ,
V_51 -> V_57 . V_58 ) ;
}
static int F_19 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
T_2 V_45 , T_1 V_60 , T_3 V_61 ,
T_2 * V_62 )
{
struct V_23 * V_63 = F_17 ( V_51 -> V_54 . V_16 -> V_55 ) ;
int V_64 ;
unsigned int V_65 ;
T_1 V_66 ;
int V_67 = 0 , V_56 = 0 ;
struct V_5 * V_6 ;
T_1 V_68 = V_20 ;
V_64 = F_20 ( & V_63 -> V_69 ) ;
V_6 = F_12 ( V_63 , V_45 ) ;
if ( ! V_6 || ! V_6 -> V_15 . V_16 ) {
F_2 ( L_3 ,
V_45 ) ;
V_56 = - V_70 ;
goto V_71;
}
if ( ! V_6 -> V_2 -> V_13 ) {
F_21 ( L_4 ,
V_45 ) ;
if ( V_62 )
* V_62 +=
( V_61 - V_53 -> V_59 . V_72 ) ;
goto V_71;
}
if ( V_6 -> V_15 . V_16 != V_51 -> V_54 . V_16 ) {
F_2 ( L_5 ) ;
V_56 = - V_70 ;
goto V_71;
}
V_65 = F_22 ( V_6 -> V_2 -> V_13 -> V_73 ) ;
F_23 () ;
V_60 += V_53 -> V_59 . V_72 ;
V_61 -= V_53 -> V_59 . V_72 ;
V_66 = ( V_60 - ( V_6 -> V_48 . V_74 & V_75 ) ) >> V_76 ;
if ( V_6 -> V_2 -> V_77 )
V_68 |= V_21 ;
V_67 = F_24 ( V_6 -> V_2 , V_60 , V_61 ,
V_68 , V_65 ) ;
if ( V_67 < 0 ) {
V_56 = V_67 ;
goto V_71;
}
if ( V_67 > 0 ) {
F_25 ( & V_6 -> V_2 -> V_13 -> V_78 ) ;
if ( ! F_26 ( V_6 -> V_2 , V_65 ) ) {
V_56 = F_7 ( V_6 , V_66 , V_67 , 0 ) ;
} else {
V_56 = - V_79 ;
}
F_27 ( & V_6 -> V_2 -> V_13 -> V_78 ) ;
if ( V_56 < 0 ) {
if ( V_56 != - V_79 )
F_2 ( L_6 ) ;
goto V_71;
}
if ( V_62 ) {
T_2 V_80 = V_67 * V_18 -
( V_60 - F_28 ( V_60 , V_18 ) ) ;
* V_62 += F_5 ( T_2 , V_80 , V_61 ) ;
}
}
V_71:
if ( V_56 == - V_79 ) {
if ( ! V_6 -> V_2 -> V_13 -> V_81 ) {
struct V_82 * V_13 = V_6 -> V_2 -> V_13 ;
unsigned long V_83 =
F_29 ( V_84 ) ;
if ( ! F_30 (
& V_13 -> V_85 ,
V_83 ) ) {
F_31 ( L_7 ) ;
}
} else {
V_56 = - V_70 ;
}
}
F_32 ( & V_63 -> V_69 , V_64 ) ;
V_53 -> V_59 . V_72 = 0 ;
return V_56 ? V_56 : V_67 ;
}
static int F_33 ( struct V_50 * V_51 ,
struct V_52 * V_53 , void * V_86 ,
void * V_87 , T_2 * V_62 ,
T_2 * V_88 , int V_89 )
{
int V_56 = 0 , V_67 = 0 ;
T_1 V_60 ;
T_2 V_45 ;
T_2 V_90 ;
T_3 V_61 ;
int V_91 ;
if ( V_89 && V_51 -> V_54 . V_92 )
V_86 += sizeof( struct V_93 ) ;
if ( V_62 )
* V_62 = 0 ;
if ( V_88 )
* V_88 = 0 ;
while ( V_86 < V_87 ) {
struct V_94 * V_95 = V_86 ;
V_60 = F_34 ( V_95 -> V_12 ) ;
V_45 = F_35 ( V_95 -> V_96 ) ;
V_90 = F_35 ( V_95 -> V_90 ) ;
V_91 = ! ! ( V_90 & V_97 ) ;
V_61 = V_90 & ~ V_97 ;
if ( V_91 ) {
V_61 = V_61 & V_98 ;
V_86 += F_36 ( sizeof( struct V_99 ) + V_61 ,
16 ) ;
} else {
V_86 += sizeof( * V_95 ) ;
}
if ( V_89 && V_61 == 0 && V_45 == V_100 &&
V_60 == 0 )
break;
if ( ! V_91 && V_88 ) {
* V_88 += V_61 - F_5 ( T_3 , V_61 ,
V_53 -> V_59 . V_72 ) ;
}
if ( V_61 == 0 )
V_61 = 1U << 31 ;
if ( V_91 || V_61 <= V_53 -> V_59 . V_72 ) {
V_53 -> V_59 . V_72 -=
F_5 ( T_3 , V_61 ,
V_53 -> V_59 . V_72 ) ;
continue;
}
V_56 = F_19 ( V_51 , V_53 , V_45 , V_60 ,
V_61 , V_62 ) ;
if ( V_56 < 0 )
break;
V_67 += V_56 ;
}
return V_56 < 0 ? V_56 : V_67 ;
}
static int F_37 (
struct V_50 * V_51 , struct V_52 * V_53 ,
void * * V_86 , void * * V_87 , int V_101 )
{
struct V_23 * V_24 = F_17 ( V_51 -> V_54 . V_16 -> V_55 ) ;
struct V_102 * V_103 = * V_86 ;
T_4 V_104 = V_53 -> V_59 . V_86 . V_104 ;
unsigned V_105 , V_106 ;
#if F_38 ( V_107 )
T_2 V_108 , V_109 ;
#endif
V_105 = F_35 ( V_103 -> V_110 ) & V_111 ;
if ( V_105 * V_112 > V_101 ) {
F_39 ( V_24 , L_8 ,
V_105 , V_101 ) ;
return - V_70 ;
}
if ( V_105 == 0 ) {
F_39 ( V_24 , L_9 ,
V_104 , V_51 -> V_57 . V_58 ) ;
return - V_70 ;
}
#if F_38 ( V_107 )
V_108 = ( F_35 ( V_103 -> V_113 ) &
V_114 ) >>
V_115 ;
if ( V_104 != V_108 ) {
F_39 ( V_24 , L_10 ,
V_104 , V_51 -> V_57 . V_58 ,
V_108 ) ;
return - V_70 ;
}
V_109 = ( F_35 ( V_103 -> V_110 ) & V_116 ) >>
V_117 ;
if ( V_51 -> V_57 . V_58 != V_109 ) {
F_39 ( V_24 , L_11 ,
V_104 , V_51 -> V_57 . V_58 ,
V_109 ) ;
return - V_70 ;
}
#endif
* V_87 = * V_86 + V_105 * V_112 ;
* V_86 += sizeof( * V_103 ) ;
V_106 = F_35 ( V_103 -> V_113 ) &
V_118 ;
switch ( V_51 -> V_54 . V_119 ) {
case V_120 :
switch ( V_106 ) {
case V_121 :
case V_122 :
case V_123 :
if ( ! ( V_24 -> V_30 . V_38 . V_41 &
V_124 ) )
goto V_125;
break;
case V_126 :
case V_127 :
if ( ! ( V_24 -> V_30 . V_38 . V_41 &
V_128 ) )
goto V_125;
* V_86 += sizeof( struct V_129 ) ;
break;
case V_130 :
if ( ! ( V_24 -> V_30 . V_38 . V_41 &
V_131 ) )
goto V_125;
* V_86 += sizeof( struct V_129 ) ;
break;
default:
goto V_125;
}
break;
case V_132 :
switch ( V_106 ) {
case V_121 :
case V_122 :
if ( ! ( V_24 -> V_30 . V_38 . V_39 &
V_124 ) )
goto V_125;
* V_86 += sizeof( struct V_133 ) ;
break;
default:
goto V_125;
}
break;
default:
V_125:
F_39 ( V_24 , L_12 ,
V_51 -> V_54 . V_119 , V_106 ) ;
return - V_70 ;
}
return 0 ;
}
static int F_40 (
struct V_50 * V_51 , struct V_52 * V_53 ,
void * * V_86 , void * * V_87 , int V_101 )
{
struct V_23 * V_24 = F_17 ( V_51 -> V_54 . V_16 -> V_55 ) ;
struct V_134 * V_135 = & V_51 -> V_136 ;
int V_137 = 1 << V_135 -> V_138 ;
if ( V_51 -> V_54 . V_92 ) {
F_39 ( V_24 , L_13 ) ;
return - V_70 ;
}
if ( V_51 -> V_139 ) {
F_39 ( V_24 , L_14 ) ;
return - V_70 ;
}
if ( V_137 > V_101 ) {
F_39 ( V_24 , L_15 ) ;
return - V_70 ;
}
switch ( V_51 -> V_54 . V_119 ) {
case V_120 :
if ( ! ( V_24 -> V_30 . V_38 . V_41 &
V_140 ) )
goto V_125;
break;
default:
V_125:
F_39 ( V_24 , L_16 ,
V_51 -> V_54 . V_119 ) ;
return - V_70 ;
}
* V_87 = * V_86 + V_137 ;
return 0 ;
}
static void F_41 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_23 * V_24 = F_17 ( V_51 -> V_54 . V_16 -> V_55 ) ;
int V_56 ;
void * V_86 , * V_87 ;
T_2 V_62 , V_88 ;
char * V_141 = NULL ;
int V_142 = 0 ;
T_4 V_104 = V_53 -> V_59 . V_86 . V_104 ;
int V_143 = V_53 -> V_59 . V_33 & V_144 ;
V_141 = ( char * ) F_42 ( V_145 ) ;
if ( ! V_141 ) {
F_39 ( V_24 , L_17 ) ;
V_142 = 1 ;
goto V_146;
}
V_56 = F_43 ( V_51 , V_143 , V_104 , V_141 ,
V_18 ) ;
if ( V_56 < 0 ) {
F_39 ( V_24 , L_18 ,
- V_56 , V_104 , V_51 -> V_57 . V_58 ) ;
V_142 = 1 ;
goto V_146;
}
V_86 = V_141 ;
if ( V_143 )
V_56 = F_37 ( V_51 , V_53 , & V_86 ,
& V_87 , V_56 ) ;
else
V_56 = F_40 ( V_51 , V_53 , & V_86 ,
& V_87 , V_56 ) ;
if ( V_56 < 0 ) {
V_142 = 1 ;
goto V_146;
}
if ( V_86 >= V_87 ) {
F_39 ( V_24 , L_19 ) ;
V_142 = 1 ;
goto V_146;
}
V_56 = F_33 ( V_51 , V_53 , V_86 , V_87 , & V_62 ,
& V_88 , ! V_143 ) ;
if ( V_56 == - V_79 ) {
goto V_146;
} else if ( V_56 < 0 || V_88 > V_62 ) {
F_39 ( V_24 , L_20 ,
- V_56 ) ;
V_142 = 1 ;
goto V_146;
}
V_146:
F_16 ( V_51 , V_53 , V_142 ) ;
F_44 ( V_24 , L_21 ,
V_51 -> V_57 . V_58 , V_142 , V_53 -> V_59 . V_33 ) ;
F_45 ( ( unsigned long ) V_141 ) ;
}
static int F_46 ( T_1 V_147 , T_2 V_148 )
{
return ( F_36 ( V_147 + V_148 , V_18 ) -
( V_147 & V_75 ) ) >> V_76 ;
}
static void F_47 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_149 * V_59 = & V_53 -> V_59 ;
T_1 V_147 ;
T_2 V_148 ;
T_2 V_150 = V_59 -> V_72 ;
int V_151 = 0 ;
T_2 V_152 = V_59 -> V_153 . V_154 ;
int V_56 ;
struct V_52 V_155 = {} ;
V_155 . V_59 . V_72 = 0 ;
V_59 -> V_153 . V_156 += V_59 -> V_72 ;
V_59 -> V_153 . V_157 -= F_48 ( V_59 -> V_72 ,
V_59 -> V_153 . V_157 ) ;
V_59 -> V_72 = 0 ;
V_147 = V_59 -> V_153 . V_156 ;
V_148 = V_59 -> V_153 . V_157 ;
if ( V_148 == 0 ) {
V_151 = 1 ;
V_148 = V_59 -> V_153 . V_158 ;
V_150 = F_48 ( V_159 , V_150 ) ;
}
V_56 = F_19 ( V_51 , V_53 , V_152 , V_147 , V_148 ,
NULL ) ;
if ( V_56 == - V_79 ) {
V_151 = 0 ;
} else if ( V_56 < 0 || F_46 ( V_147, V_148 ) > V_56 ) {
F_16 ( V_51 , V_53 , 1 ) ;
return;
}
F_16 ( V_51 , V_53 , 0 ) ;
if ( V_151 ) {
V_56 = F_19 ( V_51 , & V_155 , V_152 ,
V_147 ,
V_150 ,
NULL ) ;
if ( V_56 < 0 ) {
F_31 ( L_22 ,
V_56 , V_151 ,
V_51 -> V_54 . V_160 , V_147 , V_150 ) ;
}
}
}
void F_49 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
T_5 V_161 = V_53 -> V_59 . V_161 ;
switch ( V_161 ) {
case V_162 :
F_41 ( V_51 , V_53 ) ;
break;
case V_163 :
F_47 ( V_51 , V_53 ) ;
break;
default:
F_31 ( L_23 ,
V_161 ) ;
F_16 ( V_51 , V_53 , 1 ) ;
break;
}
}
static void F_50 ( struct V_164 * V_165 )
{
struct V_52 * V_53 = F_15 ( V_165 ,
struct V_52 ,
V_165 ) ;
enum V_166 V_167 =
F_51 ( & V_53 -> V_59 ) ;
struct V_50 * V_51 = F_15 ( V_53 , struct V_50 ,
V_168 [ V_167 ] ) ;
F_49 ( V_51 , V_53 ) ;
}
void F_52 ( struct V_50 * V_51 )
{
unsigned long V_33 ;
F_53 ( & V_51 -> V_169 , V_33 ) ;
V_51 -> V_170 = 1 ;
F_54 ( & V_51 -> V_169 , V_33 ) ;
F_55 ( V_171 ) ;
}
void F_56 ( struct V_50 * V_51 )
{
unsigned long V_33 ;
F_53 ( & V_51 -> V_169 , V_33 ) ;
V_51 -> V_170 = 0 ;
F_54 ( & V_51 -> V_169 , V_33 ) ;
}
static void F_57 ( struct V_172 * V_51 ,
struct V_149 * V_53 )
{
struct V_50 * V_173 = F_58 ( V_51 ) ;
enum V_166 V_167 =
F_51 ( V_53 ) ;
struct V_52 * V_174 = & V_173 -> V_168 [ V_167 ] ;
V_174 -> V_59 = * V_53 ;
F_59 ( & V_173 -> V_169 ) ;
if ( ! V_173 -> V_170 )
F_60 ( V_171 , & V_174 -> V_165 ) ;
F_61 ( & V_173 -> V_169 ) ;
}
void F_62 ( struct V_50 * V_51 )
{
int V_175 ;
V_51 -> V_170 = 1 ;
F_63 ( & V_51 -> V_169 ) ;
V_51 -> V_57 . V_176 = F_57 ;
for ( V_175 = 0 ; V_175 < V_177 ; ++ V_175 )
F_64 ( & V_51 -> V_168 [ V_175 ] . V_165 , F_50 ) ;
}
int F_65 ( struct V_23 * V_178 )
{
int V_56 ;
V_56 = F_66 ( & V_178 -> V_69 ) ;
if ( V_56 )
return V_56 ;
return 0 ;
}
void F_67 ( struct V_23 * V_178 )
{
F_68 ( & V_178 -> V_69 ) ;
}
int T_6 F_69 ( void )
{
V_171 =
F_70 ( L_24 ) ;
if ( ! V_171 )
return - V_179 ;
return 0 ;
}
void F_71 ( void )
{
F_72 ( V_171 ) ;
}
