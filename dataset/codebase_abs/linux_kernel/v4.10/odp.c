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
void F_9 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = & V_24 -> V_27 ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
if ( ! F_10 ( V_24 -> V_28 , V_29 ) )
return;
V_26 -> V_30 = V_31 ;
if ( F_11 ( V_24 -> V_28 , V_32 . V_33 ) )
V_26 -> V_34 . V_32 |= V_35 ;
if ( F_11 ( V_24 -> V_28 , V_36 . V_33 ) )
V_26 -> V_34 . V_36 |= V_35 ;
if ( F_11 ( V_24 -> V_28 , V_36 . V_37 ) )
V_26 -> V_34 . V_36 |= V_38 ;
if ( F_11 ( V_24 -> V_28 , V_36 . V_39 ) )
V_26 -> V_34 . V_36 |= V_40 ;
if ( F_11 ( V_24 -> V_28 , V_36 . V_41 ) )
V_26 -> V_34 . V_36 |= V_42 ;
return;
}
static struct V_5 * F_12 ( struct V_23 * V_24 ,
T_2 V_43 )
{
T_2 V_44 = F_13 ( V_43 ) ;
struct V_45 * V_46 = F_14 ( V_24 -> V_28 , V_44 ) ;
struct V_5 * V_6 = F_15 ( V_46 , struct V_5 , V_46 ) ;
if ( ! V_46 || V_46 -> V_43 != V_43 || ! V_6 -> V_47 )
return NULL ;
return F_15 ( V_46 , struct V_5 , V_46 ) ;
}
static void F_16 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
int error )
{
struct V_23 * V_24 = F_17 ( V_49 -> V_52 . V_16 -> V_53 ) ;
T_2 V_54 = V_49 -> V_55 . V_56 . V_57 . V_54 ;
int V_58 = F_18 ( V_24 -> V_28 ,
V_54 ,
V_51 -> V_59 . V_60 ,
error ) ;
if ( V_58 )
F_2 ( L_2 , V_54 ) ;
}
static int F_19 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
T_2 V_43 , T_1 V_61 , T_3 V_62 ,
T_2 * V_63 )
{
struct V_23 * V_64 = F_17 ( V_49 -> V_52 . V_16 -> V_53 ) ;
int V_65 ;
unsigned int V_66 ;
T_1 V_67 ;
int V_68 = 0 , V_58 = 0 ;
struct V_5 * V_6 ;
T_1 V_69 = V_20 ;
V_65 = F_20 ( & V_64 -> V_70 ) ;
V_6 = F_12 ( V_64 , V_43 ) ;
if ( ! V_6 || ! V_6 -> V_15 . V_16 ) {
F_2 ( L_3 ,
V_43 ) ;
V_58 = - V_71 ;
goto V_72;
}
if ( ! V_6 -> V_2 -> V_13 ) {
F_21 ( L_4 ,
V_43 ) ;
if ( V_63 )
* V_63 +=
( V_62 - V_51 -> V_59 . V_73 ) ;
goto V_72;
}
if ( V_6 -> V_15 . V_16 != V_49 -> V_52 . V_16 ) {
F_2 ( L_5 ) ;
V_58 = - V_71 ;
goto V_72;
}
V_66 = F_22 ( V_6 -> V_2 -> V_13 -> V_74 ) ;
F_23 () ;
V_61 += V_51 -> V_59 . V_73 ;
V_62 -= V_51 -> V_59 . V_73 ;
V_67 = ( V_61 - ( V_6 -> V_46 . V_75 & V_76 ) ) >> V_77 ;
if ( V_6 -> V_2 -> V_78 )
V_69 |= V_21 ;
V_68 = F_24 ( V_6 -> V_2 , V_61 , V_62 ,
V_69 , V_66 ) ;
if ( V_68 < 0 ) {
V_58 = V_68 ;
goto V_72;
}
if ( V_68 > 0 ) {
F_25 ( & V_6 -> V_2 -> V_13 -> V_79 ) ;
if ( ! F_26 ( V_6 -> V_2 , V_66 ) ) {
V_58 = F_7 ( V_6 , V_67 , V_68 , 0 ) ;
} else {
V_58 = - V_80 ;
}
F_27 ( & V_6 -> V_2 -> V_13 -> V_79 ) ;
if ( V_58 < 0 ) {
if ( V_58 != - V_80 )
F_2 ( L_6 ) ;
goto V_72;
}
if ( V_63 ) {
T_2 V_81 = V_68 * V_18 -
( V_61 - F_28 ( V_61 , V_18 ) ) ;
* V_63 += F_5 ( T_2 , V_81 , V_62 ) ;
}
}
V_72:
if ( V_58 == - V_80 ) {
if ( ! V_6 -> V_2 -> V_13 -> V_82 ) {
struct V_83 * V_13 = V_6 -> V_2 -> V_13 ;
unsigned long V_84 =
F_29 ( V_85 ) ;
if ( ! F_30 (
& V_13 -> V_86 ,
V_84 ) ) {
F_31 ( L_7 ) ;
}
} else {
V_58 = - V_71 ;
}
}
F_32 ( & V_64 -> V_70 , V_65 ) ;
V_51 -> V_59 . V_73 = 0 ;
return V_58 ? V_58 : V_68 ;
}
static int F_33 ( struct V_48 * V_49 ,
struct V_50 * V_51 , void * V_87 ,
void * V_88 , T_2 * V_63 ,
T_2 * V_89 , int V_90 )
{
int V_58 = 0 , V_68 = 0 ;
T_1 V_61 ;
T_2 V_43 ;
T_2 V_91 ;
T_3 V_62 ;
int V_92 ;
if ( V_90 && V_49 -> V_52 . V_93 )
V_87 += sizeof( struct V_94 ) ;
if ( V_63 )
* V_63 = 0 ;
if ( V_89 )
* V_89 = 0 ;
while ( V_87 < V_88 ) {
struct V_95 * V_96 = V_87 ;
V_61 = F_34 ( V_96 -> V_12 ) ;
V_43 = F_35 ( V_96 -> V_97 ) ;
V_91 = F_35 ( V_96 -> V_91 ) ;
V_92 = ! ! ( V_91 & V_98 ) ;
V_62 = V_91 & ~ V_98 ;
if ( V_92 ) {
V_62 = V_62 & V_99 ;
V_87 += F_36 ( sizeof( struct V_100 ) + V_62 ,
16 ) ;
} else {
V_87 += sizeof( * V_96 ) ;
}
if ( V_90 && V_62 == 0 && V_43 == V_101 &&
V_61 == 0 )
break;
if ( ! V_92 && V_89 ) {
* V_89 += V_62 - F_5 ( T_3 , V_62 ,
V_51 -> V_59 . V_73 ) ;
}
if ( V_62 == 0 )
V_62 = 1U << 31 ;
if ( V_92 || V_62 <= V_51 -> V_59 . V_73 ) {
V_51 -> V_59 . V_73 -=
F_5 ( T_3 , V_62 ,
V_51 -> V_59 . V_73 ) ;
continue;
}
V_58 = F_19 ( V_49 , V_51 , V_43 , V_61 ,
V_62 , V_63 ) ;
if ( V_58 < 0 )
break;
V_68 += V_58 ;
}
return V_58 < 0 ? V_58 : V_68 ;
}
static int F_37 (
struct V_48 * V_49 , struct V_50 * V_51 ,
void * * V_87 , void * * V_88 , int V_102 )
{
struct V_23 * V_24 = F_17 ( V_49 -> V_52 . V_16 -> V_53 ) ;
struct V_103 * V_104 = * V_87 ;
T_4 V_105 = V_51 -> V_59 . V_87 . V_105 ;
unsigned V_106 , V_107 ;
#if F_38 ( V_108 )
T_2 V_109 , V_110 ;
#endif
T_2 V_54 = V_49 -> V_55 . V_56 . V_57 . V_54 ;
V_106 = F_35 ( V_104 -> V_111 ) & V_112 ;
if ( V_106 * V_113 > V_102 ) {
F_39 ( V_24 , L_8 ,
V_106 , V_102 ) ;
return - V_71 ;
}
if ( V_106 == 0 ) {
F_39 ( V_24 , L_9 ,
V_105 , V_54 ) ;
return - V_71 ;
}
#if F_38 ( V_108 )
V_109 = ( F_35 ( V_104 -> V_114 ) &
V_115 ) >>
V_116 ;
if ( V_105 != V_109 ) {
F_39 ( V_24 , L_10 ,
V_105 , V_54 ,
V_109 ) ;
return - V_71 ;
}
V_110 = ( F_35 ( V_104 -> V_111 ) & V_117 ) >>
V_118 ;
if ( V_54 != V_110 ) {
F_39 ( V_24 , L_11 ,
V_105 , V_54 ,
V_110 ) ;
return - V_71 ;
}
#endif
* V_88 = * V_87 + V_106 * V_113 ;
* V_87 += sizeof( * V_104 ) ;
V_107 = F_35 ( V_104 -> V_114 ) &
V_119 ;
switch ( V_49 -> V_52 . V_120 ) {
case V_121 :
switch ( V_107 ) {
case V_122 :
case V_123 :
case V_124 :
if ( ! ( V_24 -> V_27 . V_34 . V_36 &
V_35 ) )
goto V_125;
break;
case V_126 :
case V_127 :
if ( ! ( V_24 -> V_27 . V_34 . V_36 &
V_40 ) )
goto V_125;
* V_87 += sizeof( struct V_128 ) ;
break;
case V_129 :
if ( ! ( V_24 -> V_27 . V_34 . V_36 &
V_42 ) )
goto V_125;
* V_87 += sizeof( struct V_128 ) ;
break;
default:
goto V_125;
}
break;
case V_130 :
switch ( V_107 ) {
case V_122 :
case V_123 :
if ( ! ( V_24 -> V_27 . V_34 . V_32 &
V_35 ) )
goto V_125;
* V_87 += sizeof( struct V_131 ) ;
break;
default:
goto V_125;
}
break;
default:
V_125:
F_39 ( V_24 , L_12 ,
V_49 -> V_52 . V_120 , V_107 ) ;
return - V_71 ;
}
return 0 ;
}
static int F_40 (
struct V_48 * V_49 , struct V_50 * V_51 ,
void * * V_87 , void * * V_88 , int V_102 )
{
struct V_23 * V_24 = F_17 ( V_49 -> V_52 . V_16 -> V_53 ) ;
struct V_132 * V_133 = & V_49 -> V_134 ;
int V_135 = 1 << V_133 -> V_136 ;
if ( V_49 -> V_52 . V_93 ) {
F_39 ( V_24 , L_13 ) ;
return - V_71 ;
}
if ( V_49 -> V_137 ) {
F_39 ( V_24 , L_14 ) ;
return - V_71 ;
}
if ( V_135 > V_102 ) {
F_39 ( V_24 , L_15 ) ;
return - V_71 ;
}
switch ( V_49 -> V_52 . V_120 ) {
case V_121 :
if ( ! ( V_24 -> V_27 . V_34 . V_36 &
V_38 ) )
goto V_125;
break;
default:
V_125:
F_39 ( V_24 , L_16 ,
V_49 -> V_52 . V_120 ) ;
return - V_71 ;
}
* V_88 = * V_87 + V_135 ;
return 0 ;
}
static void F_41 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_23 * V_24 = F_17 ( V_49 -> V_52 . V_16 -> V_53 ) ;
int V_58 ;
void * V_87 , * V_88 ;
T_2 V_63 , V_89 ;
char * V_138 = NULL ;
int V_139 = 0 ;
T_4 V_105 = V_51 -> V_59 . V_87 . V_105 ;
int V_140 = V_51 -> V_59 . V_60 & V_141 ;
T_2 V_54 = V_49 -> V_55 . V_56 . V_57 . V_54 ;
V_138 = ( char * ) F_42 ( V_142 ) ;
if ( ! V_138 ) {
F_39 ( V_24 , L_17 ) ;
V_139 = 1 ;
goto V_143;
}
V_58 = F_43 ( V_49 , V_140 , V_105 , V_138 ,
V_18 , & V_49 -> V_55 . V_56 ) ;
if ( V_58 < 0 ) {
F_39 ( V_24 , L_18 ,
- V_58 , V_105 , V_54 ) ;
V_139 = 1 ;
goto V_143;
}
V_87 = V_138 ;
if ( V_140 )
V_58 = F_37 ( V_49 , V_51 , & V_87 ,
& V_88 , V_58 ) ;
else
V_58 = F_40 ( V_49 , V_51 , & V_87 ,
& V_88 , V_58 ) ;
if ( V_58 < 0 ) {
V_139 = 1 ;
goto V_143;
}
if ( V_87 >= V_88 ) {
F_39 ( V_24 , L_19 ) ;
V_139 = 1 ;
goto V_143;
}
V_58 = F_33 ( V_49 , V_51 , V_87 , V_88 , & V_63 ,
& V_89 , ! V_140 ) ;
if ( V_58 == - V_80 ) {
goto V_143;
} else if ( V_58 < 0 || V_89 > V_63 ) {
F_39 ( V_24 , L_20 ,
- V_58 ) ;
V_139 = 1 ;
goto V_143;
}
V_143:
F_16 ( V_49 , V_51 , V_139 ) ;
F_44 ( V_24 , L_21 ,
V_54 , V_139 ,
V_51 -> V_59 . V_60 ) ;
F_45 ( ( unsigned long ) V_138 ) ;
}
static int F_46 ( T_1 V_144 , T_2 V_145 )
{
return ( F_36 ( V_144 + V_145 , V_18 ) -
( V_144 & V_76 ) ) >> V_77 ;
}
static void F_47 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_146 * V_59 = & V_51 -> V_59 ;
T_1 V_144 ;
T_2 V_145 ;
T_2 V_147 = V_59 -> V_73 ;
int V_148 = 0 ;
T_2 V_149 = V_59 -> V_150 . V_151 ;
int V_58 ;
struct V_50 V_152 = {} ;
V_152 . V_59 . V_73 = 0 ;
V_59 -> V_150 . V_153 += V_59 -> V_73 ;
V_59 -> V_150 . V_154 -= F_48 ( V_59 -> V_73 ,
V_59 -> V_150 . V_154 ) ;
V_59 -> V_73 = 0 ;
V_144 = V_59 -> V_150 . V_153 ;
V_145 = V_59 -> V_150 . V_154 ;
if ( V_145 == 0 ) {
V_148 = 1 ;
V_145 = V_59 -> V_150 . V_155 ;
V_147 = F_48 ( V_156 , V_147 ) ;
}
V_58 = F_19 ( V_49 , V_51 , V_149 , V_144 , V_145 ,
NULL ) ;
if ( V_58 == - V_80 ) {
V_148 = 0 ;
} else if ( V_58 < 0 || F_46 ( V_144, V_145 ) > V_58 ) {
F_16 ( V_49 , V_51 , 1 ) ;
return;
}
F_16 ( V_49 , V_51 , 0 ) ;
if ( V_148 ) {
V_58 = F_19 ( V_49 , & V_152 , V_149 ,
V_144 ,
V_147 ,
NULL ) ;
if ( V_58 < 0 ) {
F_31 ( L_22 ,
V_58 , V_148 ,
V_49 -> V_52 . V_157 , V_144 , V_147 ) ;
}
}
}
void F_49 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
T_5 V_158 = V_51 -> V_59 . V_158 ;
switch ( V_158 ) {
case V_159 :
F_41 ( V_49 , V_51 ) ;
break;
case V_160 :
F_47 ( V_49 , V_51 ) ;
break;
default:
F_31 ( L_23 ,
V_158 ) ;
F_16 ( V_49 , V_51 , 1 ) ;
break;
}
}
static void F_50 ( struct V_161 * V_162 )
{
struct V_50 * V_51 = F_15 ( V_162 ,
struct V_50 ,
V_162 ) ;
enum V_163 V_164 =
F_51 ( & V_51 -> V_59 ) ;
struct V_48 * V_49 = F_15 ( V_51 , struct V_48 ,
V_165 [ V_164 ] ) ;
F_49 ( V_49 , V_51 ) ;
}
void F_52 ( struct V_48 * V_49 )
{
unsigned long V_60 ;
F_53 ( & V_49 -> V_166 , V_60 ) ;
V_49 -> V_167 = 1 ;
F_54 ( & V_49 -> V_166 , V_60 ) ;
F_55 ( V_168 ) ;
}
void F_56 ( struct V_48 * V_49 )
{
unsigned long V_60 ;
F_53 ( & V_49 -> V_166 , V_60 ) ;
V_49 -> V_167 = 0 ;
F_54 ( & V_49 -> V_166 , V_60 ) ;
}
static void F_57 ( struct V_169 * V_49 ,
struct V_146 * V_51 )
{
struct V_48 * V_170 = F_58 ( V_49 ) ;
enum V_163 V_164 =
F_51 ( V_51 ) ;
struct V_50 * V_171 = & V_170 -> V_165 [ V_164 ] ;
V_171 -> V_59 = * V_51 ;
F_59 ( & V_170 -> V_166 ) ;
if ( ! V_170 -> V_167 )
F_60 ( V_168 , & V_171 -> V_162 ) ;
F_61 ( & V_170 -> V_166 ) ;
}
void F_62 ( struct V_48 * V_49 )
{
int V_172 ;
V_49 -> V_167 = 1 ;
F_63 ( & V_49 -> V_166 ) ;
V_49 -> V_55 . V_56 . V_57 . V_173 = F_57 ;
for ( V_172 = 0 ; V_172 < V_174 ; ++ V_172 )
F_64 ( & V_49 -> V_165 [ V_172 ] . V_162 , F_50 ) ;
}
int F_65 ( struct V_23 * V_175 )
{
int V_58 ;
V_58 = F_66 ( & V_175 -> V_70 ) ;
if ( V_58 )
return V_58 ;
return 0 ;
}
void F_67 ( struct V_23 * V_175 )
{
F_68 ( & V_175 -> V_70 ) ;
}
int T_6 F_69 ( void )
{
V_168 = F_70 ( L_24 ,
V_176 ) ;
if ( ! V_168 )
return - V_177 ;
return 0 ;
}
void F_71 ( void )
{
F_72 ( V_168 ) ;
}
