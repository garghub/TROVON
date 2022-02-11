void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_4 ) ;
unsigned long V_5 ;
int V_6 ;
T_1 V_7 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
V_7 = V_3 -> V_10 ;
V_6 = V_3 -> V_11 ;
V_3 -> V_11 = F_5 ( V_3 -> V_12 ) ;
V_3 -> V_10 = F_6 ( V_3 -> V_12 ) ;
if ( V_6 == V_3 -> V_11 ) {
if ( ! V_3 -> V_11 )
F_4 ( & V_3 -> V_8 , V_5 ) ;
else {
if ( V_7 != V_3 -> V_10 ) {
V_3 -> V_13 -> V_14 . V_15 ++ ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_1 ) ;
F_8 ( & V_3 -> V_18 ) ;
if ( V_3 -> V_19 . V_5 & V_20 ) {
F_9 ( V_3 ) ;
return;
}
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_2 ) ;
F_10 ( & V_3 -> V_18 ) ;
} else
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
} else if ( V_3 -> V_11 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_19 . V_5 & V_20 ) {
F_9 ( V_3 ) ;
return;
}
F_7 ( V_16 , V_3 -> V_13 -> V_17 , L_2 ) ;
F_10 ( & V_3 -> V_18 ) ;
} else {
V_3 -> V_13 -> V_14 . V_15 ++ ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_7 ( V_16 , V_3 -> V_13 -> V_17 , L_1 ) ;
F_8 ( & V_3 -> V_18 ) ;
}
}
void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_21 ) ;
struct V_22 * V_23 = V_3 -> V_13 ;
unsigned long V_5 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
while ( ( V_25 = F_12 ( & V_3 -> V_28 ) ) ) {
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_13 ( V_25 ) ;
return;
}
V_27 = (struct V_26 * ) V_25 ;
if ( V_3 -> V_29 != V_30 &&
V_3 -> V_29 != V_31 ) {
F_14 ( & V_3 -> V_28 , V_25 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_15 ( V_23 , V_27 ) ;
}
}
void F_16 ( struct V_3 * V_3 )
{
struct V_32 * V_33 = NULL ;
struct V_32 * V_34 = NULL ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( F_17 ( & V_3 -> V_35 ) ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_18 (fevt, next, &fnic->evlist, list) {
F_19 ( & V_33 -> V_36 ) ;
F_20 ( V_33 ) ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_37 ) ;
struct V_32 * V_33 = NULL ;
struct V_32 * V_34 = NULL ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( F_17 ( & V_3 -> V_35 ) ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_18 (fevt, next, &fnic->evlist, list) {
if ( V_3 -> V_9 ) {
F_19 ( & V_33 -> V_36 ) ;
F_20 ( V_33 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
if ( V_3 -> V_29 != V_30 &&
V_3 -> V_29 != V_31 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_19 ( & V_33 -> V_36 ) ;
switch ( V_33 -> V_38 ) {
case V_39 :
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_9 ( V_3 ) ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
break;
case V_40 :
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_3 ) ;
F_22 ( V_3 ) ;
break;
default:
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_4 , V_33 -> V_38 ) ;
break;
}
F_20 ( V_33 ) ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
static inline int F_23 ( struct V_41 * V_42 ,
struct V_24 * V_25 )
{
struct V_22 * V_13 = V_42 -> V_23 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = NULL ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
enum V_51 V_52 = 0 ;
T_2 V_53 ;
T_3 V_54 ;
T_3 V_55 ;
T_4 V_56 = 0 ;
T_4 V_57 ;
T_4 V_58 = 0 ;
if ( F_24 ( V_25 ) )
return 0 ;
if ( V_25 -> V_59 < sizeof( * V_44 ) )
return 0 ;
V_44 = (struct V_43 * ) V_25 -> V_60 ;
V_53 = F_25 ( V_44 -> V_61 ) ;
V_55 = V_44 -> V_62 ;
if ( V_53 != V_63 )
return 0 ;
if ( V_55 != V_64 )
return 0 ;
V_57 = F_25 ( V_44 -> V_65 ) * 4 ;
if ( V_57 + sizeof( * V_44 ) > V_25 -> V_59 )
return 0 ;
V_48 = (struct V_47 * ) ( V_44 + 1 ) ;
V_58 = V_48 -> V_66 * V_67 ;
if ( V_48 -> V_68 == V_69 ) {
F_26 ( V_16 , V_13 -> V_17 ,
L_5
L_6 ,
V_42 -> V_70 -> V_71 , V_42 -> V_70 -> V_72 ,
V_42 -> V_70 -> V_73 ) ;
if ( V_58 < sizeof( * V_50 ) + sizeof( * V_46 ) + 1 )
return 0 ;
V_56 = V_58 - sizeof( * V_50 ) ;
V_50 = (struct V_49 * ) V_48 ;
V_46 = (struct V_45 * ) ( V_50 + 1 ) ;
V_52 = V_48 -> V_68 ;
if ( ! V_46 )
return 0 ;
V_54 = * ( T_3 * ) ( V_46 + 1 ) ;
if ( V_54 == V_74 ) {
F_26 ( V_75 , V_13 -> V_17 ,
L_7 ) ;
return 1 ;
}
F_26 ( V_75 , V_13 -> V_17 ,
L_8 ) ;
}
return 0 ;
}
static void F_9 ( struct V_3 * V_3 )
{
struct V_41 * V_42 = & V_3 -> V_18 ;
struct V_24 * V_25 ;
char * V_76 ;
int V_77 ;
struct V_78 * V_79 ;
T_5 V_80 ;
F_27 ( V_3 ) ;
V_3 -> V_81 ( V_3 , 0 ) ;
F_7 ( V_75 , V_3 -> V_13 -> V_17 ,
L_9 ) ;
V_25 = F_28 ( sizeof( struct V_78 ) ) ;
if ( ! V_25 )
return;
V_77 = sizeof( * V_79 ) ;
V_76 = ( char * ) V_25 -> V_60 ;
V_79 = (struct V_78 * ) V_76 ;
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
memcpy ( V_79 -> V_82 . V_83 , V_42 -> V_84 , V_85 ) ;
memcpy ( V_79 -> V_82 . V_86 , V_87 , V_85 ) ;
V_79 -> V_82 . V_88 = F_29 ( V_89 ) ;
V_79 -> V_42 . V_90 = F_30 ( V_91 ) ;
V_79 -> V_42 . V_61 = F_29 ( V_92 ) ;
V_79 -> V_42 . V_62 = V_93 ;
V_79 -> V_42 . V_65 = F_29 ( sizeof( V_79 -> V_48 ) / V_67 ) ;
V_79 -> V_48 . V_94 . V_95 . V_68 = V_96 ;
V_79 -> V_48 . V_94 . V_95 . V_66 = sizeof( V_79 -> V_48 . V_94 ) / V_67 ;
memcpy ( & V_79 -> V_48 . V_94 . V_97 , V_42 -> V_84 , V_85 ) ;
V_79 -> V_48 . V_98 . V_95 . V_68 = V_99 ;
V_79 -> V_48 . V_98 . V_95 . V_66 = sizeof( V_79 -> V_48 . V_98 ) / V_67 ;
F_31 ( V_42 -> V_23 -> V_98 , & V_79 -> V_48 . V_98 . V_100 ) ;
F_32 ( V_25 , sizeof( * V_79 ) ) ;
V_25 -> V_101 = F_29 ( V_89 ) ;
F_33 ( V_25 ) ;
F_34 ( V_25 ) ;
V_42 -> V_102 ( V_42 , V_25 ) ;
V_80 = V_103 + F_35 ( V_104 ) ;
F_36 ( & V_3 -> V_105 , F_37 ( V_80 ) ) ;
}
static void F_38 ( struct V_3 * V_3 , struct V_24 * V_25 )
{
struct V_41 * V_42 = & V_3 -> V_18 ;
struct V_43 * V_44 ;
struct V_47 * V_48 ;
T_2 V_106 ;
T_4 V_57 ;
T_4 V_58 ;
struct V_107 * V_79 ;
T_5 V_108 ;
unsigned long V_5 ;
F_7 ( V_75 , V_3 -> V_13 -> V_17 ,
L_10 ) ;
V_44 = (struct V_43 * ) V_25 -> V_60 ;
F_7 ( V_75 , V_3 -> V_13 -> V_17 ,
L_11 ,
F_25 ( V_44 -> V_61 ) , V_44 -> V_62 ) ;
V_57 = F_25 ( V_44 -> V_65 ) * 4 ;
F_27 ( V_3 ) ;
F_3 ( & V_3 -> V_109 , V_5 ) ;
V_48 = (struct V_47 * ) ( V_44 + 1 ) ;
while ( V_57 > 0 ) {
V_58 = V_48 -> V_66 * V_67 ;
switch ( V_48 -> V_68 ) {
case V_110 :
V_106 = F_25 ( ( (struct V_111 * ) V_48 ) -> V_112 ) ;
F_26 ( V_75 , V_3 -> V_13 -> V_17 ,
L_12 , V_106 ) ;
V_79 = F_39 ( sizeof( * V_79 ) ,
V_113 ) ;
if ( ! V_79 ) {
F_4 ( & V_3 -> V_109 ,
V_5 ) ;
goto V_114;
}
memset ( V_79 , 0 , sizeof( struct V_107 ) ) ;
V_79 -> V_106 = V_106 & 0x0fff ;
V_79 -> V_29 = V_115 ;
F_40 ( & V_79 -> V_36 , & V_3 -> V_116 ) ;
break;
}
V_48 = (struct V_47 * ) ( ( char * ) V_48 + V_58 ) ;
V_57 -= V_58 ;
}
if ( F_17 ( & V_3 -> V_116 ) ) {
F_7 ( V_75 , V_3 -> V_13 -> V_17 ,
L_13 ) ;
F_4 ( & V_3 -> V_109 , V_5 ) ;
goto V_114;
}
V_79 = F_41 ( & V_3 -> V_116 , struct V_107 , V_36 ) ;
V_3 -> V_81 ( V_3 , V_79 -> V_106 ) ;
V_79 -> V_29 = V_117 ;
V_79 -> V_118 ++ ;
F_4 ( & V_3 -> V_109 , V_5 ) ;
F_10 ( V_42 ) ;
V_108 = V_103 + F_35 ( V_119 ) ;
F_36 ( & V_3 -> V_105 , F_37 ( V_108 ) ) ;
V_114:
return;
}
static void F_22 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_107 * V_79 ;
T_5 V_108 ;
F_3 ( & V_3 -> V_109 , V_5 ) ;
V_79 = F_41 ( & V_3 -> V_116 , struct V_107 , V_36 ) ;
V_3 -> V_81 ( V_3 , V_79 -> V_106 ) ;
V_79 -> V_29 = V_117 ;
V_79 -> V_118 = 1 ;
F_4 ( & V_3 -> V_109 , V_5 ) ;
F_10 ( & V_3 -> V_18 ) ;
V_108 = V_103 + F_35 ( V_119 ) ;
F_36 ( & V_3 -> V_105 , F_37 ( V_108 ) ) ;
}
static int F_42 ( struct V_3 * V_3 , T_2 V_120 )
{
unsigned long V_5 ;
struct V_107 * V_121 ;
F_3 ( & V_3 -> V_109 , V_5 ) ;
if ( F_17 ( & V_3 -> V_116 ) ) {
F_4 ( & V_3 -> V_109 , V_5 ) ;
return - V_122 ;
}
V_121 = F_41 ( & V_3 -> V_116 , struct V_107 , V_36 ) ;
if ( V_121 -> V_29 == V_123 ) {
F_4 ( & V_3 -> V_109 , V_5 ) ;
return 0 ;
}
if ( V_121 -> V_29 == V_117 ) {
V_121 -> V_29 = V_123 ;
F_4 ( & V_3 -> V_109 , V_5 ) ;
return 0 ;
}
F_4 ( & V_3 -> V_109 , V_5 ) ;
return - V_122 ;
}
static void F_43 ( struct V_3 * V_3 , enum V_124 V_125 )
{
struct V_32 * V_33 ;
unsigned long V_5 ;
V_33 = F_39 ( sizeof( * V_33 ) , V_113 ) ;
if ( ! V_33 )
return;
V_33 -> V_3 = V_3 ;
V_33 -> V_38 = V_125 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
F_40 ( & V_33 -> V_36 , & V_3 -> V_35 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_44 ( & V_3 -> V_37 ) ;
}
static int F_45 ( struct V_3 * V_3 , struct V_24 * V_25 )
{
struct V_43 * V_44 ;
int V_126 = 1 ;
T_2 V_53 ;
T_3 V_55 ;
if ( ! V_25 || ! ( V_25 -> V_60 ) )
return - 1 ;
if ( F_24 ( V_25 ) )
goto V_127;
V_44 = (struct V_43 * ) V_25 -> V_60 ;
V_53 = F_25 ( V_44 -> V_61 ) ;
V_55 = V_44 -> V_62 ;
if ( F_46 ( V_44 -> V_90 ) != V_91 )
goto V_127;
if ( F_25 ( V_44 -> V_65 ) * V_67 + sizeof( * V_44 ) > V_25 -> V_59 )
goto V_127;
if ( V_53 == V_128 && V_55 == V_129 ) {
if ( F_42 ( V_3 , F_25 ( V_44 -> V_130 ) ) )
goto V_127;
V_126 = 1 ;
} else if ( V_53 == V_92 && V_55 == V_131 ) {
F_38 ( V_3 , V_25 ) ;
V_126 = 0 ;
} else if ( V_53 == V_132 && V_55 == V_133 ) {
F_43 ( V_3 , V_39 ) ;
V_126 = 1 ;
}
V_127:
return V_126 ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_134 ) ;
unsigned long V_5 ;
struct V_24 * V_25 ;
struct V_135 * V_136 ;
while ( ( V_25 = F_12 ( & V_3 -> V_137 ) ) ) {
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_13 ( V_25 ) ;
return;
}
if ( V_3 -> V_29 != V_30 &&
V_3 -> V_29 != V_31 ) {
F_14 ( & V_3 -> V_137 , V_25 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_136 = (struct V_135 * ) V_25 -> V_60 ;
if ( V_136 -> V_88 == F_29 ( V_89 ) ) {
F_48 ( V_25 , sizeof( * V_136 ) ) ;
if ( F_45 ( V_3 , V_25 ) <= 0 ) {
F_13 ( V_25 ) ;
continue;
}
if ( F_23 ( & V_3 -> V_18 , V_25 ) ) {
F_26 ( V_75 , V_3 -> V_13 -> V_17 ,
L_14 ) ;
F_8 ( & V_3 -> V_18 ) ;
F_9 ( V_3 ) ;
F_13 ( V_25 ) ;
continue;
}
F_49 ( & V_3 -> V_18 , V_25 ) ;
continue;
}
}
}
static inline int F_50 ( struct V_3 * V_3 , struct V_24 * V_25 )
{
struct V_26 * V_27 ;
struct V_135 * V_136 ;
struct V_138 * V_138 ;
struct V_139 * V_140 ;
V_136 = (struct V_135 * ) V_25 -> V_60 ;
if ( V_136 -> V_88 == F_29 ( V_141 ) ) {
memmove ( ( T_3 * ) V_136 + V_142 , V_136 , V_85 * 2 ) ;
V_136 = (struct V_135 * ) F_48 ( V_25 , V_142 ) ;
F_33 ( V_25 ) ;
}
if ( V_136 -> V_88 == F_29 ( V_89 ) ) {
if ( ! ( V_3 -> V_19 . V_5 & V_20 ) ) {
F_51 ( V_143 L_15
L_16
L_17 ) ;
goto V_127;
}
F_52 ( & V_3 -> V_137 , V_25 ) ;
F_53 ( V_144 , & V_3 -> V_134 ) ;
return 1 ;
}
if ( V_136 -> V_88 != F_29 ( V_145 ) )
goto V_127;
F_54 ( V_25 , sizeof( * V_136 ) ) ;
F_48 ( V_25 , sizeof( * V_136 ) ) ;
V_138 = (struct V_138 * ) V_25 -> V_60 ;
if ( F_55 ( V_138 ) != V_146 )
goto V_127;
V_27 = (struct V_26 * ) V_25 ;
F_56 ( V_27 ) ;
F_57 ( V_27 ) = V_138 -> V_147 ;
F_48 ( V_25 , sizeof( struct V_138 ) ) ;
F_58 ( V_25 ) ;
V_140 = (struct V_139 * ) ( V_25 -> V_60 + V_25 -> V_59 - sizeof( * V_140 ) ) ;
F_59 ( V_27 ) = V_140 -> V_148 ;
F_60 ( V_25 , V_25 -> V_59 - sizeof( * V_140 ) ) ;
return 0 ;
V_127:
F_61 ( V_25 ) ;
return - 1 ;
}
void F_62 ( struct V_3 * V_3 , T_3 * V_149 )
{
T_3 * V_150 = V_3 -> V_18 . V_84 ;
T_3 * V_60 = V_3 -> V_151 ;
if ( F_63 ( V_149 ) )
V_149 = V_150 ;
if ( ! F_64 ( V_60 , V_149 ) )
return;
F_7 ( V_16 , V_3 -> V_13 -> V_17 , L_18 , V_149 ) ;
if ( ! F_63 ( V_60 ) && F_64 ( V_60 , V_150 ) )
F_65 ( V_3 -> V_12 , V_60 ) ;
memcpy ( V_60 , V_149 , V_85 ) ;
if ( F_64 ( V_149 , V_150 ) )
F_66 ( V_3 -> V_12 , V_149 ) ;
}
void F_67 ( struct V_22 * V_13 , T_3 * V_149 )
{
struct V_3 * V_3 = F_68 ( V_13 ) ;
F_69 ( & V_3 -> V_8 ) ;
F_62 ( V_3 , V_149 ) ;
F_70 ( & V_3 -> V_8 ) ;
}
void F_71 ( struct V_22 * V_13 , T_1 V_152 , struct V_26 * V_27 )
{
struct V_3 * V_3 = F_68 ( V_13 ) ;
T_3 * V_94 ;
int V_126 ;
F_7 ( V_16 , V_13 -> V_17 , L_19 ,
V_152 , V_27 ) ;
if ( ! V_152 ) {
F_67 ( V_13 , V_3 -> V_18 . V_84 ) ;
F_72 ( V_3 ) ;
return;
}
if ( V_27 ) {
V_94 = F_73 ( V_27 ) -> V_153 ;
if ( F_63 ( V_94 ) ) {
F_74 ( & V_3 -> V_18 , V_13 , V_27 ) ;
}
F_67 ( V_13 , V_94 ) ;
}
F_69 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_29 == V_31 || V_3 -> V_29 == V_30 )
V_3 -> V_29 = V_154 ;
else {
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_20
L_21 ,
F_75 ( V_3 -> V_29 ) ) ;
F_70 ( & V_3 -> V_8 ) ;
return;
}
F_70 ( & V_3 -> V_8 ) ;
V_126 = F_76 ( V_3 , V_152 ) ;
if ( V_126 < 0 ) {
F_69 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_29 == V_154 )
V_3 -> V_29 = V_31 ;
F_70 ( & V_3 -> V_8 ) ;
}
}
static int F_77 ( struct V_155 * V_12 ,
struct V_156 * V_156 , T_3 type ,
T_2 V_157 , T_2 V_158 ,
void * V_159 )
{
struct V_3 * V_3 = F_78 ( V_12 ) ;
F_79 ( & V_3 -> V_160 [ V_157 ] , V_156 , V_158 ,
V_161 , V_162 ,
NULL ) ;
return 0 ;
}
int F_80 ( struct V_3 * V_3 , int V_163 )
{
unsigned int V_164 = 0 , V_165 ;
unsigned int V_166 ;
int V_167 ;
for ( V_166 = 0 ; V_166 < V_3 -> V_168 ; V_166 ++ ) {
V_165 = F_81 ( & V_3 -> V_169 [ V_166 ] , V_163 ,
F_77 ,
NULL ) ;
if ( V_165 ) {
V_167 = F_82 ( & V_3 -> V_160 [ V_166 ] , V_170 ) ;
if ( V_167 )
F_26 ( V_143 , V_3 -> V_13 -> V_17 ,
L_22
L_23 ) ;
}
V_164 += V_165 ;
}
return V_164 ;
}
int V_170 ( struct V_171 * V_160 )
{
struct V_3 * V_3 = F_78 ( V_160 -> V_12 ) ;
struct V_24 * V_25 ;
T_2 V_59 ;
T_6 V_172 ;
V_59 = V_173 + V_174 + V_175 ;
V_25 = F_28 ( V_59 ) ;
if ( ! V_25 ) {
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_24 ) ;
return - V_176 ;
}
F_33 ( V_25 ) ;
F_58 ( V_25 ) ;
F_34 ( V_25 ) ;
F_32 ( V_25 , V_59 ) ;
V_172 = F_83 ( V_3 -> V_177 , V_25 -> V_60 , V_59 , V_178 ) ;
F_84 ( V_160 , V_25 , V_172 , V_59 ) ;
return 0 ;
}
void F_85 ( struct V_171 * V_160 , struct V_179 * V_180 )
{
struct V_26 * V_27 = V_180 -> V_181 ;
struct V_3 * V_3 = F_78 ( V_160 -> V_12 ) ;
F_86 ( V_3 -> V_177 , V_180 -> V_182 , V_180 -> V_59 ,
V_178 ) ;
F_13 ( F_87 ( V_27 ) ) ;
V_180 -> V_181 = NULL ;
}
void F_88 ( struct V_41 * V_42 , struct V_24 * V_25 )
{
struct V_3 * V_3 = F_89 ( V_42 ) ;
struct V_183 * V_184 = & V_3 -> V_184 [ 0 ] ;
T_6 V_172 ;
struct V_135 * V_185 ;
struct V_186 * V_187 ;
unsigned long V_5 ;
if ( ! V_3 -> V_188 ) {
V_185 = (struct V_135 * ) F_90 ( V_25 ) ;
V_187 = (struct V_186 * ) F_91 ( V_25 ,
sizeof( * V_187 ) - sizeof( * V_185 ) ) ;
memcpy ( V_187 , V_185 , 2 * V_85 ) ;
V_187 -> V_189 = F_29 ( V_141 ) ;
V_187 -> V_190 = V_185 -> V_88 ;
V_187 -> V_191 = F_29 ( V_3 -> V_192 ) ;
}
V_172 = F_83 ( V_3 -> V_177 , V_25 -> V_60 , V_25 -> V_59 , V_193 ) ;
F_3 ( & V_3 -> V_194 [ 0 ] , V_5 ) ;
if ( ! F_92 ( V_184 ) ) {
F_86 ( V_3 -> V_177 , V_172 , V_25 -> V_59 , V_193 ) ;
F_4 ( & V_3 -> V_194 [ 0 ] , V_5 ) ;
F_93 ( V_25 ) ;
return;
}
F_94 ( V_184 , V_25 , V_172 , V_25 -> V_59 ,
0 ,
V_3 -> V_192 , 1 ) ;
F_4 ( & V_3 -> V_194 [ 0 ] , V_5 ) ;
}
static int F_95 ( struct V_3 * V_3 , struct V_26 * V_27 )
{
struct V_183 * V_184 = & V_3 -> V_184 [ 0 ] ;
struct V_24 * V_25 ;
T_6 V_172 ;
struct V_135 * V_185 ;
struct V_186 * V_187 ;
struct V_138 * V_138 ;
struct V_45 * V_46 ;
T_1 V_195 , V_196 ;
int V_126 = 0 ;
unsigned long V_5 ;
V_46 = F_96 ( V_27 ) ;
V_25 = F_87 ( V_27 ) ;
if ( F_97 ( V_46 -> V_197 == V_198 ) &&
F_98 ( & V_3 -> V_18 , V_3 -> V_13 , V_25 ) )
return 0 ;
if ( ! V_3 -> V_188 ) {
V_196 = sizeof( * V_187 ) + sizeof( * V_138 ) ;
V_187 = (struct V_186 * ) F_91 ( V_25 , V_196 ) ;
V_185 = (struct V_135 * ) V_187 ;
V_187 -> V_189 = F_29 ( V_141 ) ;
V_187 -> V_190 = F_29 ( V_145 ) ;
V_187 -> V_191 = F_29 ( V_3 -> V_192 ) ;
V_138 = (struct V_138 * ) ( V_187 + 1 ) ;
} else {
V_196 = sizeof( * V_185 ) + sizeof( * V_138 ) ;
V_185 = (struct V_135 * ) F_91 ( V_25 , V_196 ) ;
V_185 -> V_88 = F_29 ( V_145 ) ;
V_138 = (struct V_138 * ) ( V_185 + 1 ) ;
}
if ( V_3 -> V_18 . V_199 )
F_99 ( V_185 -> V_86 , V_46 -> V_200 ) ;
else
memcpy ( V_185 -> V_86 , V_3 -> V_18 . V_201 , V_85 ) ;
memcpy ( V_185 -> V_83 , V_3 -> V_151 , V_85 ) ;
V_195 = V_25 -> V_59 ;
F_100 ( V_195 % 4 ) ;
memset ( V_138 , 0 , sizeof( * V_138 ) ) ;
V_138 -> V_147 = F_57 ( V_27 ) ;
if ( V_146 )
F_101 ( V_138 , V_146 ) ;
V_172 = F_83 ( V_3 -> V_177 , V_185 , V_195 , V_193 ) ;
F_3 ( & V_3 -> V_194 [ 0 ] , V_5 ) ;
if ( ! F_92 ( V_184 ) ) {
F_86 ( V_3 -> V_177 , V_172 ,
V_195 , V_193 ) ;
V_126 = - 1 ;
goto V_202;
}
F_102 ( V_184 , V_25 , V_172 , V_195 , F_59 ( V_27 ) ,
0 ,
V_3 -> V_192 , 1 , 1 , 1 ) ;
V_202:
F_4 ( & V_3 -> V_194 [ 0 ] , V_5 ) ;
if ( V_126 )
F_103 ( F_87 ( V_27 ) ) ;
return V_126 ;
}
int F_104 ( struct V_22 * V_23 , struct V_26 * V_27 )
{
struct V_3 * V_3 = F_68 ( V_23 ) ;
unsigned long V_5 ;
if ( V_3 -> V_203 ) {
F_13 ( F_87 ( V_27 ) ) ;
return - 1 ;
}
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_29 != V_30 && V_3 -> V_29 != V_31 ) {
F_52 ( & V_3 -> V_204 , F_87 ( V_27 ) ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return 0 ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
return F_95 ( V_3 , V_27 ) ;
}
void F_105 ( struct V_3 * V_3 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 ;
while ( ( V_25 = F_12 ( & V_3 -> V_204 ) ) ) {
V_27 = (struct V_26 * ) V_25 ;
F_95 ( V_3 , V_27 ) ;
}
}
static void F_72 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
enum V_205 V_206 ;
int V_126 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
V_207:
V_206 = V_3 -> V_29 ;
switch ( V_206 ) {
case V_30 :
case V_154 :
default:
V_3 -> V_29 = V_208 ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_126 = F_106 ( V_3 ) ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_29 != V_208 )
goto V_207;
if ( V_126 )
V_3 -> V_29 = V_206 ;
break;
case V_208 :
case V_31 :
break;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
static void F_107 ( struct V_183 * V_184 ,
struct V_156 * V_156 ,
struct V_209 * V_180 , void * V_159 )
{
struct V_24 * V_25 = V_180 -> V_181 ;
struct V_26 * V_27 = (struct V_26 * ) V_25 ;
struct V_3 * V_3 = F_78 ( V_184 -> V_12 ) ;
F_86 ( V_3 -> V_177 , V_180 -> V_182 ,
V_180 -> V_59 , V_193 ) ;
F_61 ( F_87 ( V_27 ) ) ;
V_180 -> V_181 = NULL ;
}
static int F_108 ( struct V_155 * V_12 ,
struct V_156 * V_156 , T_3 type ,
T_2 V_157 , T_2 V_158 ,
void * V_159 )
{
struct V_3 * V_3 = F_78 ( V_12 ) ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_194 [ V_157 ] , V_5 ) ;
F_109 ( & V_3 -> V_184 [ V_157 ] , V_156 , V_158 ,
F_107 , NULL ) ;
F_4 ( & V_3 -> V_194 [ V_157 ] , V_5 ) ;
return 0 ;
}
int F_110 ( struct V_3 * V_3 , int V_210 )
{
unsigned int V_211 = 0 ;
unsigned int V_166 ;
for ( V_166 = 0 ; V_166 < V_3 -> V_212 ; V_166 ++ ) {
V_211 += F_81 ( & V_3 -> V_169 [ V_3 -> V_168 + V_166 ] ,
V_210 ,
F_108 ,
NULL ) ;
}
return V_211 ;
}
void F_111 ( struct V_183 * V_184 , struct V_209 * V_180 )
{
struct V_26 * V_27 = V_180 -> V_181 ;
struct V_3 * V_3 = F_78 ( V_184 -> V_12 ) ;
F_86 ( V_3 -> V_177 , V_180 -> V_182 ,
V_180 -> V_59 , V_193 ) ;
F_13 ( F_87 ( V_27 ) ) ;
V_180 -> V_181 = NULL ;
}
void F_27 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_107 * V_79 ;
struct V_107 * V_34 ;
F_3 ( & V_3 -> V_109 , V_5 ) ;
if ( ! F_17 ( & V_3 -> V_116 ) ) {
F_18 (vlan, next, &fnic->vlans, list) {
F_19 ( & V_79 -> V_36 ) ;
F_20 ( V_79 ) ;
}
}
F_4 ( & V_3 -> V_109 , V_5 ) ;
}
void F_112 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_107 * V_79 ;
T_5 V_108 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_18 . V_213 == V_214 )
return;
F_3 ( & V_3 -> V_109 , V_5 ) ;
if ( F_17 ( & V_3 -> V_116 ) ) {
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_25 ) ;
F_4 ( & V_3 -> V_109 , V_5 ) ;
F_43 ( V_3 , V_39 ) ;
return;
}
V_79 = F_41 ( & V_3 -> V_116 , struct V_107 , V_36 ) ;
F_26 ( V_16 , V_3 -> V_13 -> V_17 ,
L_26 ,
V_79 -> V_106 , V_79 -> V_29 , V_79 -> V_118 ) ;
switch ( V_79 -> V_29 ) {
case V_123 :
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_27 ) ;
F_4 ( & V_3 -> V_109 , V_5 ) ;
break;
case V_215 :
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_25 ) ;
F_4 ( & V_3 -> V_109 , V_5 ) ;
F_43 ( V_3 , V_39 ) ;
break;
case V_117 :
if ( V_79 -> V_118 >= V_216 ) {
F_26 ( V_75 , V_3 -> V_13 -> V_17 ,
L_28 ,
V_79 -> V_106 ) ;
F_19 ( & V_79 -> V_36 ) ;
F_20 ( V_79 ) ;
V_79 = NULL ;
if ( F_17 ( & V_3 -> V_116 ) ) {
F_4 ( & V_3 -> V_109 ,
V_5 ) ;
F_26 ( V_75 , V_3 -> V_13 -> V_17 ,
L_29
L_30 ) ;
F_43 ( V_3 , V_39 ) ;
return;
}
V_79 = F_41 ( & V_3 -> V_116 , struct V_107 ,
V_36 ) ;
V_3 -> V_81 ( V_3 , V_79 -> V_106 ) ;
V_79 -> V_29 = V_117 ;
}
F_4 ( & V_3 -> V_109 , V_5 ) ;
V_79 -> V_118 ++ ;
V_108 = V_103 + F_35
( V_119 ) ;
F_36 ( & V_3 -> V_105 , F_37 ( V_108 ) ) ;
break;
}
}
