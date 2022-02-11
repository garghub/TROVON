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
int error ) {
struct V_23 * V_24 = F_17 ( V_49 -> V_52 . V_16 -> V_53 ) ;
int V_54 = F_18 ( V_24 -> V_28 , V_49 -> V_55 . V_56 ,
V_51 -> V_57 . V_58 ,
error ) ;
if ( V_54 )
F_2 ( L_2 ,
V_49 -> V_55 . V_56 ) ;
}
static int F_19 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
T_2 V_43 , T_1 V_59 , T_3 V_60 ,
T_2 * V_61 )
{
struct V_23 * V_62 = F_17 ( V_49 -> V_52 . V_16 -> V_53 ) ;
int V_63 ;
unsigned int V_64 ;
T_1 V_65 ;
int V_66 = 0 , V_54 = 0 ;
struct V_5 * V_6 ;
T_1 V_67 = V_20 ;
V_63 = F_20 ( & V_62 -> V_68 ) ;
V_6 = F_12 ( V_62 , V_43 ) ;
if ( ! V_6 || ! V_6 -> V_15 . V_16 ) {
F_2 ( L_3 ,
V_43 ) ;
V_54 = - V_69 ;
goto V_70;
}
if ( ! V_6 -> V_2 -> V_13 ) {
F_21 ( L_4 ,
V_43 ) ;
if ( V_61 )
* V_61 +=
( V_60 - V_51 -> V_57 . V_71 ) ;
goto V_70;
}
if ( V_6 -> V_15 . V_16 != V_49 -> V_52 . V_16 ) {
F_2 ( L_5 ) ;
V_54 = - V_69 ;
goto V_70;
}
V_64 = F_22 ( V_6 -> V_2 -> V_13 -> V_72 ) ;
F_23 () ;
V_59 += V_51 -> V_57 . V_71 ;
V_60 -= V_51 -> V_57 . V_71 ;
V_65 = ( V_59 - ( V_6 -> V_46 . V_73 & V_74 ) ) >> V_75 ;
if ( V_6 -> V_2 -> V_76 )
V_67 |= V_21 ;
V_66 = F_24 ( V_6 -> V_2 , V_59 , V_60 ,
V_67 , V_64 ) ;
if ( V_66 < 0 ) {
V_54 = V_66 ;
goto V_70;
}
if ( V_66 > 0 ) {
F_25 ( & V_6 -> V_2 -> V_13 -> V_77 ) ;
if ( ! F_26 ( V_6 -> V_2 , V_64 ) ) {
V_54 = F_7 ( V_6 , V_65 , V_66 , 0 ) ;
} else {
V_54 = - V_78 ;
}
F_27 ( & V_6 -> V_2 -> V_13 -> V_77 ) ;
if ( V_54 < 0 ) {
if ( V_54 != - V_78 )
F_2 ( L_6 ) ;
goto V_70;
}
if ( V_61 ) {
T_2 V_79 = V_66 * V_18 -
( V_59 - F_28 ( V_59 , V_18 ) ) ;
* V_61 += F_5 ( T_2 , V_79 , V_60 ) ;
}
}
V_70:
if ( V_54 == - V_78 ) {
if ( ! V_6 -> V_2 -> V_13 -> V_80 ) {
struct V_81 * V_13 = V_6 -> V_2 -> V_13 ;
unsigned long V_82 =
F_29 ( V_83 ) ;
if ( ! F_30 (
& V_13 -> V_84 ,
V_82 ) ) {
F_31 ( L_7 ) ;
}
} else {
V_54 = - V_69 ;
}
}
F_32 ( & V_62 -> V_68 , V_63 ) ;
V_51 -> V_57 . V_71 = 0 ;
return V_54 ? V_54 : V_66 ;
}
static int F_33 ( struct V_48 * V_49 ,
struct V_50 * V_51 , void * V_85 ,
void * V_86 , T_2 * V_61 ,
T_2 * V_87 , int V_88 )
{
int V_54 = 0 , V_66 = 0 ;
T_1 V_59 ;
T_2 V_43 ;
T_2 V_89 ;
T_3 V_60 ;
int V_90 ;
if ( V_88 && V_49 -> V_52 . V_91 )
V_85 += sizeof( struct V_92 ) ;
if ( V_61 )
* V_61 = 0 ;
if ( V_87 )
* V_87 = 0 ;
while ( V_85 < V_86 ) {
struct V_93 * V_94 = V_85 ;
V_59 = F_34 ( V_94 -> V_12 ) ;
V_43 = F_35 ( V_94 -> V_95 ) ;
V_89 = F_35 ( V_94 -> V_89 ) ;
V_90 = ! ! ( V_89 & V_96 ) ;
V_60 = V_89 & ~ V_96 ;
if ( V_90 ) {
V_60 = V_60 & V_97 ;
V_85 += F_36 ( sizeof( struct V_98 ) + V_60 ,
16 ) ;
} else {
V_85 += sizeof( * V_94 ) ;
}
if ( V_88 && V_60 == 0 && V_43 == V_99 &&
V_59 == 0 )
break;
if ( ! V_90 && V_87 ) {
* V_87 += V_60 - F_5 ( T_3 , V_60 ,
V_51 -> V_57 . V_71 ) ;
}
if ( V_60 == 0 )
V_60 = 1U << 31 ;
if ( V_90 || V_60 <= V_51 -> V_57 . V_71 ) {
V_51 -> V_57 . V_71 -=
F_5 ( T_3 , V_60 ,
V_51 -> V_57 . V_71 ) ;
continue;
}
V_54 = F_19 ( V_49 , V_51 , V_43 , V_59 ,
V_60 , V_61 ) ;
if ( V_54 < 0 )
break;
V_66 += V_54 ;
}
return V_54 < 0 ? V_54 : V_66 ;
}
static int F_37 (
struct V_48 * V_49 , struct V_50 * V_51 ,
void * * V_85 , void * * V_86 , int V_100 )
{
struct V_23 * V_24 = F_17 ( V_49 -> V_52 . V_16 -> V_53 ) ;
struct V_101 * V_102 = * V_85 ;
T_4 V_103 = V_51 -> V_57 . V_85 . V_103 ;
unsigned V_104 , V_105 ;
#if F_38 ( V_106 )
T_2 V_107 , V_108 ;
#endif
V_104 = F_35 ( V_102 -> V_109 ) & V_110 ;
if ( V_104 * V_111 > V_100 ) {
F_39 ( V_24 , L_8 ,
V_104 , V_100 ) ;
return - V_69 ;
}
if ( V_104 == 0 ) {
F_39 ( V_24 , L_9 ,
V_103 , V_49 -> V_55 . V_56 ) ;
return - V_69 ;
}
#if F_38 ( V_106 )
V_107 = ( F_35 ( V_102 -> V_112 ) &
V_113 ) >>
V_114 ;
if ( V_103 != V_107 ) {
F_39 ( V_24 , L_10 ,
V_103 , V_49 -> V_55 . V_56 ,
V_107 ) ;
return - V_69 ;
}
V_108 = ( F_35 ( V_102 -> V_109 ) & V_115 ) >>
V_116 ;
if ( V_49 -> V_55 . V_56 != V_108 ) {
F_39 ( V_24 , L_11 ,
V_103 , V_49 -> V_55 . V_56 ,
V_108 ) ;
return - V_69 ;
}
#endif
* V_86 = * V_85 + V_104 * V_111 ;
* V_85 += sizeof( * V_102 ) ;
V_105 = F_35 ( V_102 -> V_112 ) &
V_117 ;
switch ( V_49 -> V_52 . V_118 ) {
case V_119 :
switch ( V_105 ) {
case V_120 :
case V_121 :
case V_122 :
if ( ! ( V_24 -> V_27 . V_34 . V_36 &
V_35 ) )
goto V_123;
break;
case V_124 :
case V_125 :
if ( ! ( V_24 -> V_27 . V_34 . V_36 &
V_40 ) )
goto V_123;
* V_85 += sizeof( struct V_126 ) ;
break;
case V_127 :
if ( ! ( V_24 -> V_27 . V_34 . V_36 &
V_42 ) )
goto V_123;
* V_85 += sizeof( struct V_126 ) ;
break;
default:
goto V_123;
}
break;
case V_128 :
switch ( V_105 ) {
case V_120 :
case V_121 :
if ( ! ( V_24 -> V_27 . V_34 . V_32 &
V_35 ) )
goto V_123;
* V_85 += sizeof( struct V_129 ) ;
break;
default:
goto V_123;
}
break;
default:
V_123:
F_39 ( V_24 , L_12 ,
V_49 -> V_52 . V_118 , V_105 ) ;
return - V_69 ;
}
return 0 ;
}
static int F_40 (
struct V_48 * V_49 , struct V_50 * V_51 ,
void * * V_85 , void * * V_86 , int V_100 )
{
struct V_23 * V_24 = F_17 ( V_49 -> V_52 . V_16 -> V_53 ) ;
struct V_130 * V_131 = & V_49 -> V_132 ;
int V_133 = 1 << V_131 -> V_134 ;
if ( V_49 -> V_52 . V_91 ) {
F_39 ( V_24 , L_13 ) ;
return - V_69 ;
}
if ( V_49 -> V_135 ) {
F_39 ( V_24 , L_14 ) ;
return - V_69 ;
}
if ( V_133 > V_100 ) {
F_39 ( V_24 , L_15 ) ;
return - V_69 ;
}
switch ( V_49 -> V_52 . V_118 ) {
case V_119 :
if ( ! ( V_24 -> V_27 . V_34 . V_36 &
V_38 ) )
goto V_123;
break;
default:
V_123:
F_39 ( V_24 , L_16 ,
V_49 -> V_52 . V_118 ) ;
return - V_69 ;
}
* V_86 = * V_85 + V_133 ;
return 0 ;
}
static void F_41 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_23 * V_24 = F_17 ( V_49 -> V_52 . V_16 -> V_53 ) ;
int V_54 ;
void * V_85 , * V_86 ;
T_2 V_61 , V_87 ;
char * V_136 = NULL ;
int V_137 = 0 ;
T_4 V_103 = V_51 -> V_57 . V_85 . V_103 ;
int V_138 = V_51 -> V_57 . V_58 & V_139 ;
V_136 = ( char * ) F_42 ( V_140 ) ;
if ( ! V_136 ) {
F_39 ( V_24 , L_17 ) ;
V_137 = 1 ;
goto V_141;
}
V_54 = F_43 ( V_49 , V_138 , V_103 , V_136 ,
V_18 ) ;
if ( V_54 < 0 ) {
F_39 ( V_24 , L_18 ,
- V_54 , V_103 , V_49 -> V_55 . V_56 ) ;
V_137 = 1 ;
goto V_141;
}
V_85 = V_136 ;
if ( V_138 )
V_54 = F_37 ( V_49 , V_51 , & V_85 ,
& V_86 , V_54 ) ;
else
V_54 = F_40 ( V_49 , V_51 , & V_85 ,
& V_86 , V_54 ) ;
if ( V_54 < 0 ) {
V_137 = 1 ;
goto V_141;
}
if ( V_85 >= V_86 ) {
F_39 ( V_24 , L_19 ) ;
V_137 = 1 ;
goto V_141;
}
V_54 = F_33 ( V_49 , V_51 , V_85 , V_86 , & V_61 ,
& V_87 , ! V_138 ) ;
if ( V_54 == - V_78 ) {
goto V_141;
} else if ( V_54 < 0 || V_87 > V_61 ) {
F_39 ( V_24 , L_20 ,
- V_54 ) ;
V_137 = 1 ;
goto V_141;
}
V_141:
F_16 ( V_49 , V_51 , V_137 ) ;
F_44 ( V_24 , L_21 ,
V_49 -> V_55 . V_56 , V_137 , V_51 -> V_57 . V_58 ) ;
F_45 ( ( unsigned long ) V_136 ) ;
}
static int F_46 ( T_1 V_142 , T_2 V_143 )
{
return ( F_36 ( V_142 + V_143 , V_18 ) -
( V_142 & V_74 ) ) >> V_75 ;
}
static void F_47 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_144 * V_57 = & V_51 -> V_57 ;
T_1 V_142 ;
T_2 V_143 ;
T_2 V_145 = V_57 -> V_71 ;
int V_146 = 0 ;
T_2 V_147 = V_57 -> V_148 . V_149 ;
int V_54 ;
struct V_50 V_150 = {} ;
V_150 . V_57 . V_71 = 0 ;
V_57 -> V_148 . V_151 += V_57 -> V_71 ;
V_57 -> V_148 . V_152 -= F_48 ( V_57 -> V_71 ,
V_57 -> V_148 . V_152 ) ;
V_57 -> V_71 = 0 ;
V_142 = V_57 -> V_148 . V_151 ;
V_143 = V_57 -> V_148 . V_152 ;
if ( V_143 == 0 ) {
V_146 = 1 ;
V_143 = V_57 -> V_148 . V_153 ;
V_145 = F_48 ( V_154 , V_145 ) ;
}
V_54 = F_19 ( V_49 , V_51 , V_147 , V_142 , V_143 ,
NULL ) ;
if ( V_54 == - V_78 ) {
V_146 = 0 ;
} else if ( V_54 < 0 || F_46 ( V_142, V_143 ) > V_54 ) {
F_16 ( V_49 , V_51 , 1 ) ;
return;
}
F_16 ( V_49 , V_51 , 0 ) ;
if ( V_146 ) {
V_54 = F_19 ( V_49 , & V_150 , V_147 ,
V_142 ,
V_145 ,
NULL ) ;
if ( V_54 < 0 ) {
F_31 ( L_22 ,
V_54 , V_146 ,
V_49 -> V_52 . V_155 , V_142 , V_145 ) ;
}
}
}
void F_49 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
T_5 V_156 = V_51 -> V_57 . V_156 ;
switch ( V_156 ) {
case V_157 :
F_41 ( V_49 , V_51 ) ;
break;
case V_158 :
F_47 ( V_49 , V_51 ) ;
break;
default:
F_31 ( L_23 ,
V_156 ) ;
F_16 ( V_49 , V_51 , 1 ) ;
break;
}
}
static void F_50 ( struct V_159 * V_160 )
{
struct V_50 * V_51 = F_15 ( V_160 ,
struct V_50 ,
V_160 ) ;
enum V_161 V_162 =
F_51 ( & V_51 -> V_57 ) ;
struct V_48 * V_49 = F_15 ( V_51 , struct V_48 ,
V_163 [ V_162 ] ) ;
F_49 ( V_49 , V_51 ) ;
}
void F_52 ( struct V_48 * V_49 )
{
unsigned long V_58 ;
F_53 ( & V_49 -> V_164 , V_58 ) ;
V_49 -> V_165 = 1 ;
F_54 ( & V_49 -> V_164 , V_58 ) ;
F_55 ( V_166 ) ;
}
void F_56 ( struct V_48 * V_49 )
{
unsigned long V_58 ;
F_53 ( & V_49 -> V_164 , V_58 ) ;
V_49 -> V_165 = 0 ;
F_54 ( & V_49 -> V_164 , V_58 ) ;
}
static void F_57 ( struct V_167 * V_49 ,
struct V_144 * V_51 )
{
struct V_48 * V_168 = F_58 ( V_49 ) ;
enum V_161 V_162 =
F_51 ( V_51 ) ;
struct V_50 * V_169 = & V_168 -> V_163 [ V_162 ] ;
V_169 -> V_57 = * V_51 ;
F_59 ( & V_168 -> V_164 ) ;
if ( ! V_168 -> V_165 )
F_60 ( V_166 , & V_169 -> V_160 ) ;
F_61 ( & V_168 -> V_164 ) ;
}
void F_62 ( struct V_48 * V_49 )
{
int V_170 ;
V_49 -> V_165 = 1 ;
F_63 ( & V_49 -> V_164 ) ;
V_49 -> V_55 . V_171 = F_57 ;
for ( V_170 = 0 ; V_170 < V_172 ; ++ V_170 )
F_64 ( & V_49 -> V_163 [ V_170 ] . V_160 , F_50 ) ;
}
int F_65 ( struct V_23 * V_173 )
{
int V_54 ;
V_54 = F_66 ( & V_173 -> V_68 ) ;
if ( V_54 )
return V_54 ;
return 0 ;
}
void F_67 ( struct V_23 * V_173 )
{
F_68 ( & V_173 -> V_68 ) ;
}
int T_6 F_69 ( void )
{
V_166 =
F_70 ( L_24 ) ;
if ( ! V_166 )
return - V_174 ;
return 0 ;
}
void F_71 ( void )
{
F_72 ( V_166 ) ;
}
