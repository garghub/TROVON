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
struct V_76 * V_76 = & V_3 -> V_76 ;
struct V_24 * V_25 ;
char * V_77 ;
int V_78 ;
struct V_79 * V_80 ;
T_5 V_81 ;
F_27 ( V_3 ) ;
V_3 -> V_82 ( V_3 , 0 ) ;
F_7 ( V_75 , V_3 -> V_13 -> V_17 ,
L_9 ) ;
V_25 = F_28 ( sizeof( struct V_79 ) ) ;
if ( ! V_25 )
return;
V_78 = sizeof( * V_80 ) ;
V_77 = ( char * ) V_25 -> V_60 ;
V_80 = (struct V_79 * ) V_77 ;
memset ( V_80 , 0 , sizeof( * V_80 ) ) ;
memcpy ( V_80 -> V_83 . V_84 , V_42 -> V_85 , V_86 ) ;
memcpy ( V_80 -> V_83 . V_87 , V_88 , V_86 ) ;
V_80 -> V_83 . V_89 = F_29 ( V_90 ) ;
V_80 -> V_42 . V_91 = F_30 ( V_92 ) ;
V_80 -> V_42 . V_61 = F_29 ( V_93 ) ;
V_80 -> V_42 . V_62 = V_94 ;
V_80 -> V_42 . V_65 = F_29 ( sizeof( V_80 -> V_48 ) / V_67 ) ;
V_80 -> V_48 . V_95 . V_96 . V_68 = V_97 ;
V_80 -> V_48 . V_95 . V_96 . V_66 = sizeof( V_80 -> V_48 . V_95 ) / V_67 ;
memcpy ( & V_80 -> V_48 . V_95 . V_98 , V_42 -> V_85 , V_86 ) ;
V_80 -> V_48 . V_99 . V_96 . V_68 = V_100 ;
V_80 -> V_48 . V_99 . V_96 . V_66 = sizeof( V_80 -> V_48 . V_99 ) / V_67 ;
F_31 ( V_42 -> V_23 -> V_99 , & V_80 -> V_48 . V_99 . V_101 ) ;
F_32 ( & V_76 -> V_102 . V_103 ) ;
F_33 ( V_25 , sizeof( * V_80 ) ) ;
V_25 -> V_104 = F_29 ( V_90 ) ;
F_34 ( V_25 ) ;
F_35 ( V_25 ) ;
V_42 -> V_105 ( V_42 , V_25 ) ;
V_81 = V_106 + F_36 ( V_107 ) ;
F_37 ( & V_3 -> V_108 , F_38 ( V_81 ) ) ;
}
static void F_39 ( struct V_3 * V_3 , struct V_24 * V_25 )
{
struct V_41 * V_42 = & V_3 -> V_18 ;
struct V_43 * V_44 ;
struct V_47 * V_48 ;
struct V_76 * V_76 = & V_3 -> V_76 ;
T_2 V_109 ;
T_4 V_57 ;
T_4 V_58 ;
struct V_110 * V_80 ;
T_5 V_111 ;
unsigned long V_5 ;
F_7 ( V_75 , V_3 -> V_13 -> V_17 ,
L_10 ) ;
V_44 = (struct V_43 * ) V_25 -> V_60 ;
F_7 ( V_75 , V_3 -> V_13 -> V_17 ,
L_11 ,
F_25 ( V_44 -> V_61 ) , V_44 -> V_62 ) ;
V_57 = F_25 ( V_44 -> V_65 ) * 4 ;
F_27 ( V_3 ) ;
F_3 ( & V_3 -> V_112 , V_5 ) ;
V_48 = (struct V_47 * ) ( V_44 + 1 ) ;
while ( V_57 > 0 ) {
V_58 = V_48 -> V_66 * V_67 ;
switch ( V_48 -> V_68 ) {
case V_113 :
V_109 = F_25 ( ( (struct V_114 * ) V_48 ) -> V_115 ) ;
F_26 ( V_75 , V_3 -> V_13 -> V_17 ,
L_12 , V_109 ) ;
V_80 = F_40 ( sizeof( * V_80 ) ,
V_116 ) ;
if ( ! V_80 ) {
F_4 ( & V_3 -> V_112 ,
V_5 ) ;
goto V_117;
}
memset ( V_80 , 0 , sizeof( struct V_110 ) ) ;
V_80 -> V_109 = V_109 & 0x0fff ;
V_80 -> V_29 = V_118 ;
F_41 ( & V_80 -> V_36 , & V_3 -> V_119 ) ;
break;
}
V_48 = (struct V_47 * ) ( ( char * ) V_48 + V_58 ) ;
V_57 -= V_58 ;
}
if ( F_17 ( & V_3 -> V_119 ) ) {
F_32 ( & V_76 -> V_102 . V_120 ) ;
F_7 ( V_75 , V_3 -> V_13 -> V_17 ,
L_13 ) ;
F_4 ( & V_3 -> V_112 , V_5 ) ;
goto V_117;
}
V_80 = F_42 ( & V_3 -> V_119 , struct V_110 , V_36 ) ;
V_3 -> V_82 ( V_3 , V_80 -> V_109 ) ;
V_80 -> V_29 = V_121 ;
V_80 -> V_122 ++ ;
F_4 ( & V_3 -> V_112 , V_5 ) ;
F_10 ( V_42 ) ;
V_111 = V_106 + F_36 ( V_123 ) ;
F_37 ( & V_3 -> V_108 , F_38 ( V_111 ) ) ;
V_117:
return;
}
static void F_22 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_110 * V_80 ;
T_5 V_111 ;
F_3 ( & V_3 -> V_112 , V_5 ) ;
V_80 = F_42 ( & V_3 -> V_119 , struct V_110 , V_36 ) ;
V_3 -> V_82 ( V_3 , V_80 -> V_109 ) ;
V_80 -> V_29 = V_121 ;
V_80 -> V_122 = 1 ;
F_4 ( & V_3 -> V_112 , V_5 ) ;
F_10 ( & V_3 -> V_18 ) ;
V_111 = V_106 + F_36 ( V_123 ) ;
F_37 ( & V_3 -> V_108 , F_38 ( V_111 ) ) ;
}
static int F_43 ( struct V_3 * V_3 , T_2 V_124 )
{
unsigned long V_5 ;
struct V_110 * V_125 ;
F_3 ( & V_3 -> V_112 , V_5 ) ;
if ( F_17 ( & V_3 -> V_119 ) ) {
F_4 ( & V_3 -> V_112 , V_5 ) ;
return - V_126 ;
}
V_125 = F_42 ( & V_3 -> V_119 , struct V_110 , V_36 ) ;
if ( V_125 -> V_29 == V_127 ) {
F_4 ( & V_3 -> V_112 , V_5 ) ;
return 0 ;
}
if ( V_125 -> V_29 == V_121 ) {
V_125 -> V_29 = V_127 ;
F_4 ( & V_3 -> V_112 , V_5 ) ;
return 0 ;
}
F_4 ( & V_3 -> V_112 , V_5 ) ;
return - V_126 ;
}
static void F_44 ( struct V_3 * V_3 , enum V_128 V_129 )
{
struct V_32 * V_33 ;
unsigned long V_5 ;
V_33 = F_40 ( sizeof( * V_33 ) , V_116 ) ;
if ( ! V_33 )
return;
V_33 -> V_3 = V_3 ;
V_33 -> V_38 = V_129 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
F_41 ( & V_33 -> V_36 , & V_3 -> V_35 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_45 ( & V_3 -> V_37 ) ;
}
static int F_46 ( struct V_3 * V_3 , struct V_24 * V_25 )
{
struct V_43 * V_44 ;
int V_130 = 1 ;
T_2 V_53 ;
T_3 V_55 ;
if ( ! V_25 || ! ( V_25 -> V_60 ) )
return - 1 ;
if ( F_24 ( V_25 ) )
goto V_131;
V_44 = (struct V_43 * ) V_25 -> V_60 ;
V_53 = F_25 ( V_44 -> V_61 ) ;
V_55 = V_44 -> V_62 ;
if ( F_47 ( V_44 -> V_91 ) != V_92 )
goto V_131;
if ( F_25 ( V_44 -> V_65 ) * V_67 + sizeof( * V_44 ) > V_25 -> V_59 )
goto V_131;
if ( V_53 == V_132 && V_55 == V_133 ) {
if ( F_43 ( V_3 , F_25 ( V_44 -> V_134 ) ) )
goto V_131;
V_130 = 1 ;
} else if ( V_53 == V_93 && V_55 == V_135 ) {
F_39 ( V_3 , V_25 ) ;
V_130 = 0 ;
} else if ( V_53 == V_136 && V_55 == V_137 ) {
F_44 ( V_3 , V_39 ) ;
V_130 = 1 ;
}
V_131:
return V_130 ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_138 ) ;
struct V_76 * V_76 = & V_3 -> V_76 ;
unsigned long V_5 ;
struct V_24 * V_25 ;
struct V_139 * V_140 ;
while ( ( V_25 = F_12 ( & V_3 -> V_141 ) ) ) {
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_13 ( V_25 ) ;
return;
}
if ( V_3 -> V_29 != V_30 &&
V_3 -> V_29 != V_31 ) {
F_14 ( & V_3 -> V_141 , V_25 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_140 = (struct V_139 * ) V_25 -> V_60 ;
if ( V_140 -> V_89 == F_29 ( V_90 ) ) {
F_49 ( V_25 , sizeof( * V_140 ) ) ;
if ( F_46 ( V_3 , V_25 ) <= 0 ) {
F_13 ( V_25 ) ;
continue;
}
if ( F_23 ( & V_3 -> V_18 , V_25 ) ) {
F_32 (
& V_76 -> V_102 . V_142 ) ;
F_26 ( V_75 , V_3 -> V_13 -> V_17 ,
L_14 ) ;
F_8 ( & V_3 -> V_18 ) ;
F_9 ( V_3 ) ;
F_13 ( V_25 ) ;
continue;
}
F_50 ( & V_3 -> V_18 , V_25 ) ;
continue;
}
}
}
static inline int F_51 ( struct V_3 * V_3 , struct V_24 * V_25 )
{
struct V_26 * V_27 ;
struct V_139 * V_140 ;
struct V_143 * V_143 ;
struct V_144 * V_145 ;
V_140 = (struct V_139 * ) V_25 -> V_60 ;
if ( V_140 -> V_89 == F_29 ( V_146 ) ) {
memmove ( ( T_3 * ) V_140 + V_147 , V_140 , V_86 * 2 ) ;
V_140 = (struct V_139 * ) F_49 ( V_25 , V_147 ) ;
F_34 ( V_25 ) ;
}
if ( V_140 -> V_89 == F_29 ( V_90 ) ) {
if ( ! ( V_3 -> V_19 . V_5 & V_20 ) ) {
F_52 ( V_148 L_15
L_16
L_17 ) ;
goto V_131;
}
F_53 ( & V_3 -> V_141 , V_25 ) ;
F_54 ( V_149 , & V_3 -> V_138 ) ;
return 1 ;
}
if ( V_140 -> V_89 != F_29 ( V_150 ) )
goto V_131;
F_55 ( V_25 , sizeof( * V_140 ) ) ;
F_49 ( V_25 , sizeof( * V_140 ) ) ;
V_143 = (struct V_143 * ) V_25 -> V_60 ;
if ( F_56 ( V_143 ) != V_151 )
goto V_131;
V_27 = (struct V_26 * ) V_25 ;
F_57 ( V_27 ) ;
F_58 ( V_27 ) = V_143 -> V_152 ;
F_49 ( V_25 , sizeof( struct V_143 ) ) ;
F_59 ( V_25 ) ;
V_145 = (struct V_144 * ) ( V_25 -> V_60 + V_25 -> V_59 - sizeof( * V_145 ) ) ;
F_60 ( V_27 ) = V_145 -> V_153 ;
F_61 ( V_25 , V_25 -> V_59 - sizeof( * V_145 ) ) ;
return 0 ;
V_131:
F_62 ( V_25 ) ;
return - 1 ;
}
void F_63 ( struct V_3 * V_3 , T_3 * V_154 )
{
T_3 * V_155 = V_3 -> V_18 . V_85 ;
T_3 * V_60 = V_3 -> V_156 ;
if ( F_64 ( V_154 ) )
V_154 = V_155 ;
if ( F_65 ( V_60 , V_154 ) )
return;
F_7 ( V_16 , V_3 -> V_13 -> V_17 , L_18 , V_154 ) ;
if ( ! F_64 ( V_60 ) && ! F_65 ( V_60 , V_155 ) )
F_66 ( V_3 -> V_12 , V_60 ) ;
memcpy ( V_60 , V_154 , V_86 ) ;
if ( ! F_65 ( V_154 , V_155 ) )
F_67 ( V_3 -> V_12 , V_154 ) ;
}
void F_68 ( struct V_22 * V_13 , T_3 * V_154 )
{
struct V_3 * V_3 = F_69 ( V_13 ) ;
F_70 ( & V_3 -> V_8 ) ;
F_63 ( V_3 , V_154 ) ;
F_71 ( & V_3 -> V_8 ) ;
}
void F_72 ( struct V_22 * V_13 , T_1 V_157 , struct V_26 * V_27 )
{
struct V_3 * V_3 = F_69 ( V_13 ) ;
T_3 * V_95 ;
int V_130 ;
F_7 ( V_16 , V_13 -> V_17 , L_19 ,
V_157 , V_27 ) ;
if ( ! V_157 ) {
F_68 ( V_13 , V_3 -> V_18 . V_85 ) ;
F_73 ( V_3 ) ;
return;
}
if ( V_27 ) {
V_95 = F_74 ( V_27 ) -> V_158 ;
if ( F_64 ( V_95 ) ) {
F_75 ( & V_3 -> V_18 , V_13 , V_27 ) ;
}
F_68 ( V_13 , V_95 ) ;
}
F_70 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_29 == V_31 || V_3 -> V_29 == V_30 )
V_3 -> V_29 = V_159 ;
else {
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_20
L_21 ,
F_76 ( V_3 -> V_29 ) ) ;
F_71 ( & V_3 -> V_8 ) ;
return;
}
F_71 ( & V_3 -> V_8 ) ;
V_130 = F_77 ( V_3 , V_157 ) ;
if ( V_130 < 0 ) {
F_70 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_29 == V_159 )
V_3 -> V_29 = V_31 ;
F_71 ( & V_3 -> V_8 ) ;
}
}
static int F_78 ( struct V_160 * V_12 ,
struct V_161 * V_161 , T_3 type ,
T_2 V_162 , T_2 V_163 ,
void * V_164 )
{
struct V_3 * V_3 = F_79 ( V_12 ) ;
F_80 ( & V_3 -> V_165 [ V_162 ] , V_161 , V_163 ,
V_166 , V_167 ,
NULL ) ;
return 0 ;
}
int F_81 ( struct V_3 * V_3 , int V_168 )
{
unsigned int V_169 = 0 , V_170 ;
unsigned int V_171 ;
int V_172 ;
for ( V_171 = 0 ; V_171 < V_3 -> V_173 ; V_171 ++ ) {
V_170 = F_82 ( & V_3 -> V_174 [ V_171 ] , V_168 ,
F_78 ,
NULL ) ;
if ( V_170 ) {
V_172 = F_83 ( & V_3 -> V_165 [ V_171 ] , V_175 ) ;
if ( V_172 )
F_26 ( V_148 , V_3 -> V_13 -> V_17 ,
L_22
L_23 ) ;
}
V_169 += V_170 ;
}
return V_169 ;
}
int V_175 ( struct V_176 * V_165 )
{
struct V_3 * V_3 = F_79 ( V_165 -> V_12 ) ;
struct V_24 * V_25 ;
T_2 V_59 ;
T_6 V_177 ;
V_59 = V_178 + V_179 + V_180 ;
V_25 = F_28 ( V_59 ) ;
if ( ! V_25 ) {
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_24 ) ;
return - V_181 ;
}
F_34 ( V_25 ) ;
F_59 ( V_25 ) ;
F_35 ( V_25 ) ;
F_33 ( V_25 , V_59 ) ;
V_177 = F_84 ( V_3 -> V_182 , V_25 -> V_60 , V_59 , V_183 ) ;
F_85 ( V_165 , V_25 , V_177 , V_59 ) ;
return 0 ;
}
void F_86 ( struct V_176 * V_165 , struct V_184 * V_185 )
{
struct V_26 * V_27 = V_185 -> V_186 ;
struct V_3 * V_3 = F_79 ( V_165 -> V_12 ) ;
F_87 ( V_3 -> V_182 , V_185 -> V_187 , V_185 -> V_59 ,
V_183 ) ;
F_13 ( F_88 ( V_27 ) ) ;
V_185 -> V_186 = NULL ;
}
void F_89 ( struct V_41 * V_42 , struct V_24 * V_25 )
{
struct V_3 * V_3 = F_90 ( V_42 ) ;
struct V_188 * V_189 = & V_3 -> V_189 [ 0 ] ;
T_6 V_177 ;
struct V_139 * V_190 ;
struct V_191 * V_192 ;
unsigned long V_5 ;
if ( ! V_3 -> V_193 ) {
V_190 = (struct V_139 * ) F_91 ( V_25 ) ;
V_192 = (struct V_191 * ) F_92 ( V_25 ,
sizeof( * V_192 ) - sizeof( * V_190 ) ) ;
memcpy ( V_192 , V_190 , 2 * V_86 ) ;
V_192 -> V_194 = F_29 ( V_146 ) ;
V_192 -> V_195 = V_190 -> V_89 ;
V_192 -> V_196 = F_29 ( V_3 -> V_197 ) ;
}
V_177 = F_84 ( V_3 -> V_182 , V_25 -> V_60 , V_25 -> V_59 , V_198 ) ;
F_3 ( & V_3 -> V_199 [ 0 ] , V_5 ) ;
if ( ! F_93 ( V_189 ) ) {
F_87 ( V_3 -> V_182 , V_177 , V_25 -> V_59 , V_198 ) ;
F_4 ( & V_3 -> V_199 [ 0 ] , V_5 ) ;
F_94 ( V_25 ) ;
return;
}
F_95 ( V_189 , V_25 , V_177 , V_25 -> V_59 ,
0 ,
V_3 -> V_197 , 1 ) ;
F_4 ( & V_3 -> V_199 [ 0 ] , V_5 ) ;
}
static int F_96 ( struct V_3 * V_3 , struct V_26 * V_27 )
{
struct V_188 * V_189 = & V_3 -> V_189 [ 0 ] ;
struct V_24 * V_25 ;
T_6 V_177 ;
struct V_139 * V_190 ;
struct V_191 * V_192 ;
struct V_143 * V_143 ;
struct V_45 * V_46 ;
T_1 V_200 , V_201 ;
int V_130 = 0 ;
unsigned long V_5 ;
V_46 = F_97 ( V_27 ) ;
V_25 = F_88 ( V_27 ) ;
if ( F_98 ( V_46 -> V_202 == V_203 ) &&
F_99 ( & V_3 -> V_18 , V_3 -> V_13 , V_25 ) )
return 0 ;
if ( ! V_3 -> V_193 ) {
V_201 = sizeof( * V_192 ) + sizeof( * V_143 ) ;
V_192 = (struct V_191 * ) F_92 ( V_25 , V_201 ) ;
V_190 = (struct V_139 * ) V_192 ;
V_192 -> V_194 = F_29 ( V_146 ) ;
V_192 -> V_195 = F_29 ( V_150 ) ;
V_192 -> V_196 = F_29 ( V_3 -> V_197 ) ;
V_143 = (struct V_143 * ) ( V_192 + 1 ) ;
} else {
V_201 = sizeof( * V_190 ) + sizeof( * V_143 ) ;
V_190 = (struct V_139 * ) F_92 ( V_25 , V_201 ) ;
V_190 -> V_89 = F_29 ( V_150 ) ;
V_143 = (struct V_143 * ) ( V_190 + 1 ) ;
}
if ( V_3 -> V_18 . V_204 )
F_100 ( V_190 -> V_87 , V_46 -> V_205 ) ;
else
memcpy ( V_190 -> V_87 , V_3 -> V_18 . V_206 , V_86 ) ;
memcpy ( V_190 -> V_84 , V_3 -> V_156 , V_86 ) ;
V_200 = V_25 -> V_59 ;
F_101 ( V_200 % 4 ) ;
memset ( V_143 , 0 , sizeof( * V_143 ) ) ;
V_143 -> V_152 = F_58 ( V_27 ) ;
if ( V_151 )
F_102 ( V_143 , V_151 ) ;
V_177 = F_84 ( V_3 -> V_182 , V_190 , V_200 , V_198 ) ;
F_3 ( & V_3 -> V_199 [ 0 ] , V_5 ) ;
if ( ! F_93 ( V_189 ) ) {
F_87 ( V_3 -> V_182 , V_177 ,
V_200 , V_198 ) ;
V_130 = - 1 ;
goto V_207;
}
F_103 ( V_189 , V_25 , V_177 , V_200 , F_60 ( V_27 ) ,
0 ,
V_3 -> V_197 , 1 , 1 , 1 ) ;
V_207:
F_4 ( & V_3 -> V_199 [ 0 ] , V_5 ) ;
if ( V_130 )
F_104 ( F_88 ( V_27 ) ) ;
return V_130 ;
}
int F_105 ( struct V_22 * V_23 , struct V_26 * V_27 )
{
struct V_3 * V_3 = F_69 ( V_23 ) ;
unsigned long V_5 ;
if ( V_3 -> V_208 ) {
F_13 ( F_88 ( V_27 ) ) ;
return - 1 ;
}
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_29 != V_30 && V_3 -> V_29 != V_31 ) {
F_53 ( & V_3 -> V_209 , F_88 ( V_27 ) ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return 0 ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
return F_96 ( V_3 , V_27 ) ;
}
void F_106 ( struct V_3 * V_3 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 ;
while ( ( V_25 = F_12 ( & V_3 -> V_209 ) ) ) {
V_27 = (struct V_26 * ) V_25 ;
F_96 ( V_3 , V_27 ) ;
}
}
static void F_73 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
enum V_210 V_211 ;
int V_130 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
V_212:
V_211 = V_3 -> V_29 ;
switch ( V_211 ) {
case V_30 :
case V_159 :
default:
V_3 -> V_29 = V_213 ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_130 = F_107 ( V_3 ) ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_29 != V_213 )
goto V_212;
if ( V_130 )
V_3 -> V_29 = V_211 ;
break;
case V_213 :
case V_31 :
break;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
static void F_108 ( struct V_188 * V_189 ,
struct V_161 * V_161 ,
struct V_214 * V_185 , void * V_164 )
{
struct V_24 * V_25 = V_185 -> V_186 ;
struct V_26 * V_27 = (struct V_26 * ) V_25 ;
struct V_3 * V_3 = F_79 ( V_189 -> V_12 ) ;
F_87 ( V_3 -> V_182 , V_185 -> V_187 ,
V_185 -> V_59 , V_198 ) ;
F_62 ( F_88 ( V_27 ) ) ;
V_185 -> V_186 = NULL ;
}
static int F_109 ( struct V_160 * V_12 ,
struct V_161 * V_161 , T_3 type ,
T_2 V_162 , T_2 V_163 ,
void * V_164 )
{
struct V_3 * V_3 = F_79 ( V_12 ) ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_199 [ V_162 ] , V_5 ) ;
F_110 ( & V_3 -> V_189 [ V_162 ] , V_161 , V_163 ,
F_108 , NULL ) ;
F_4 ( & V_3 -> V_199 [ V_162 ] , V_5 ) ;
return 0 ;
}
int F_111 ( struct V_3 * V_3 , int V_215 )
{
unsigned int V_216 = 0 ;
unsigned int V_171 ;
for ( V_171 = 0 ; V_171 < V_3 -> V_217 ; V_171 ++ ) {
V_216 += F_82 ( & V_3 -> V_174 [ V_3 -> V_173 + V_171 ] ,
V_215 ,
F_109 ,
NULL ) ;
}
return V_216 ;
}
void F_112 ( struct V_188 * V_189 , struct V_214 * V_185 )
{
struct V_26 * V_27 = V_185 -> V_186 ;
struct V_3 * V_3 = F_79 ( V_189 -> V_12 ) ;
F_87 ( V_3 -> V_182 , V_185 -> V_187 ,
V_185 -> V_59 , V_198 ) ;
F_13 ( F_88 ( V_27 ) ) ;
V_185 -> V_186 = NULL ;
}
void F_27 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_110 * V_80 ;
struct V_110 * V_34 ;
F_3 ( & V_3 -> V_112 , V_5 ) ;
if ( ! F_17 ( & V_3 -> V_119 ) ) {
F_18 (vlan, next, &fnic->vlans, list) {
F_19 ( & V_80 -> V_36 ) ;
F_20 ( V_80 ) ;
}
}
F_4 ( & V_3 -> V_112 , V_5 ) ;
}
void F_113 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_110 * V_80 ;
struct V_76 * V_76 = & V_3 -> V_76 ;
T_5 V_111 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_18 . V_218 == V_219 )
return;
F_3 ( & V_3 -> V_112 , V_5 ) ;
if ( F_17 ( & V_3 -> V_119 ) ) {
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_25 ) ;
F_4 ( & V_3 -> V_112 , V_5 ) ;
F_44 ( V_3 , V_39 ) ;
return;
}
V_80 = F_42 ( & V_3 -> V_119 , struct V_110 , V_36 ) ;
F_26 ( V_16 , V_3 -> V_13 -> V_17 ,
L_26 ,
V_80 -> V_109 , V_80 -> V_29 , V_80 -> V_122 ) ;
switch ( V_80 -> V_29 ) {
case V_127 :
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_27 ) ;
F_4 ( & V_3 -> V_112 , V_5 ) ;
break;
case V_220 :
F_7 ( V_16 , V_3 -> V_13 -> V_17 ,
L_25 ) ;
F_4 ( & V_3 -> V_112 , V_5 ) ;
F_44 ( V_3 , V_39 ) ;
break;
case V_121 :
if ( V_80 -> V_122 >= V_221 ) {
F_26 ( V_75 , V_3 -> V_13 -> V_17 ,
L_28 ,
V_80 -> V_109 ) ;
F_19 ( & V_80 -> V_36 ) ;
F_20 ( V_80 ) ;
V_80 = NULL ;
if ( F_17 ( & V_3 -> V_119 ) ) {
F_4 ( & V_3 -> V_112 ,
V_5 ) ;
F_26 ( V_75 , V_3 -> V_13 -> V_17 ,
L_29
L_30 ) ;
F_44 ( V_3 , V_39 ) ;
return;
}
V_80 = F_42 ( & V_3 -> V_119 , struct V_110 ,
V_36 ) ;
V_3 -> V_82 ( V_3 , V_80 -> V_109 ) ;
V_80 -> V_29 = V_121 ;
}
F_4 ( & V_3 -> V_112 , V_5 ) ;
F_32 ( & V_76 -> V_102 . V_222 ) ;
V_80 -> V_122 ++ ;
V_111 = V_106 + F_36
( V_123 ) ;
F_37 ( & V_3 -> V_108 , F_38 ( V_111 ) ) ;
break;
}
}
