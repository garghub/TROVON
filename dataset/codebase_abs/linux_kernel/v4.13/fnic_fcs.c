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
switch ( F_7 ( V_3 -> V_12 ) ) {
case V_13 :
F_8 ( V_3 -> V_14 -> V_15 ) = V_16 ;
V_3 -> V_14 -> V_17 = V_16 ;
break;
case V_18 :
F_8 ( V_3 -> V_14 -> V_15 ) = V_19 ;
V_3 -> V_14 -> V_17 = V_19 ;
break;
case V_20 :
case V_21 :
F_8 ( V_3 -> V_14 -> V_15 ) = V_22 ;
V_3 -> V_14 -> V_17 = V_22 ;
break;
case V_23 :
F_8 ( V_3 -> V_14 -> V_15 ) = V_24 ;
V_3 -> V_14 -> V_17 = V_24 ;
break;
default:
F_8 ( V_3 -> V_14 -> V_15 ) = V_25 ;
V_3 -> V_14 -> V_17 = V_25 ;
break;
}
if ( V_6 == V_3 -> V_11 ) {
if ( ! V_3 -> V_11 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_9 ( V_3 -> V_14 -> V_15 -> V_26 ,
V_27 , L_1 ,
strlen ( L_1 ) ) ;
} else {
if ( V_7 != V_3 -> V_10 ) {
V_3 -> V_14 -> V_28 . V_29 ++ ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_9 (
V_3 -> V_14 -> V_15 -> V_26 ,
V_27 ,
L_2 ,
strlen ( L_3 )
) ;
F_10 ( V_30 , V_3 -> V_14 -> V_15 ,
L_4 ) ;
F_11 ( & V_3 -> V_31 ) ;
if ( V_3 -> V_32 . V_5 & V_33 ) {
F_9 (
V_3 -> V_14 -> V_15 -> V_26 ,
V_27 ,
L_5 ,
strlen (
L_5 )
) ;
F_12 ( V_3 ) ;
return;
}
F_10 ( V_30 , V_3 -> V_14 -> V_15 ,
L_6 ) ;
F_13 ( & V_3 -> V_31 ) ;
} else {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_9 (
V_3 -> V_14 -> V_15 -> V_26 , V_27 ,
L_7 ,
strlen ( L_7 ) ) ;
}
}
} else if ( V_3 -> V_11 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_32 . V_5 & V_33 ) {
F_9 (
V_3 -> V_14 -> V_15 -> V_26 ,
V_27 , L_8 ,
strlen ( L_8 ) ) ;
F_12 ( V_3 ) ;
return;
}
F_10 ( V_30 , V_3 -> V_14 -> V_15 , L_6 ) ;
F_9 ( V_3 -> V_14 -> V_15 -> V_26 , V_27 ,
L_9 , strlen ( L_9 ) ) ;
F_13 ( & V_3 -> V_31 ) ;
} else {
V_3 -> V_14 -> V_28 . V_29 ++ ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_10 ( V_30 , V_3 -> V_14 -> V_15 , L_4 ) ;
F_9 (
V_3 -> V_14 -> V_15 -> V_26 , V_27 ,
L_10 ,
strlen ( L_10 ) ) ;
if ( V_3 -> V_32 . V_5 & V_33 ) {
F_10 ( V_30 , V_3 -> V_14 -> V_15 ,
L_11 ) ;
F_14 ( & V_3 -> V_34 ) ;
}
F_11 ( & V_3 -> V_31 ) ;
}
}
void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_35 ) ;
struct V_36 * V_37 = V_3 -> V_14 ;
unsigned long V_5 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
while ( ( V_39 = F_16 ( & V_3 -> V_42 ) ) ) {
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_17 ( V_39 ) ;
return;
}
V_41 = (struct V_40 * ) V_39 ;
if ( V_3 -> V_43 != V_44 &&
V_3 -> V_43 != V_45 ) {
F_18 ( & V_3 -> V_42 , V_39 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_19 ( V_37 , V_41 ) ;
}
}
void F_20 ( struct V_3 * V_3 )
{
struct V_46 * V_47 = NULL ;
struct V_46 * V_48 = NULL ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( F_21 ( & V_3 -> V_49 ) ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_22 (fevt, next, &fnic->evlist, list) {
F_23 ( & V_47 -> V_50 ) ;
F_24 ( V_47 ) ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_51 ) ;
struct V_46 * V_47 = NULL ;
struct V_46 * V_48 = NULL ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( F_21 ( & V_3 -> V_49 ) ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_22 (fevt, next, &fnic->evlist, list) {
if ( V_3 -> V_9 ) {
F_23 ( & V_47 -> V_50 ) ;
F_24 ( V_47 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
if ( V_3 -> V_43 != V_44 &&
V_3 -> V_43 != V_45 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_23 ( & V_47 -> V_50 ) ;
switch ( V_47 -> V_52 ) {
case V_53 :
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_12 ( V_3 ) ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
break;
case V_54 :
F_10 ( V_30 , V_3 -> V_14 -> V_15 ,
L_12 ) ;
F_26 ( V_3 ) ;
break;
default:
F_10 ( V_30 , V_3 -> V_14 -> V_15 ,
L_13 , V_47 -> V_52 ) ;
break;
}
F_24 ( V_47 ) ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
static inline int F_27 ( struct V_55 * V_56 ,
struct V_38 * V_39 )
{
struct V_36 * V_14 = V_56 -> V_37 ;
struct V_57 * V_58 ;
struct V_59 * V_60 = NULL ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
enum V_65 V_66 = 0 ;
T_2 V_67 ;
T_3 V_68 ;
T_3 V_69 ;
T_4 V_70 = 0 ;
T_4 V_71 ;
T_4 V_72 = 0 ;
if ( F_28 ( V_39 ) )
return 0 ;
if ( V_39 -> V_73 < sizeof( * V_58 ) )
return 0 ;
V_58 = (struct V_57 * ) V_39 -> V_74 ;
V_67 = F_29 ( V_58 -> V_75 ) ;
V_69 = V_58 -> V_76 ;
if ( V_67 != V_77 )
return 0 ;
if ( V_69 != V_78 )
return 0 ;
V_71 = F_29 ( V_58 -> V_79 ) * 4 ;
if ( V_71 + sizeof( * V_58 ) > V_39 -> V_73 )
return 0 ;
V_62 = (struct V_61 * ) ( V_58 + 1 ) ;
V_72 = V_62 -> V_80 * V_81 ;
if ( V_62 -> V_82 == V_83 ) {
if ( V_72 < sizeof( * V_64 ) + sizeof( * V_60 ) + 1 )
return 0 ;
V_70 = V_72 - sizeof( * V_64 ) ;
V_64 = (struct V_63 * ) V_62 ;
V_60 = (struct V_59 * ) ( V_64 + 1 ) ;
V_66 = V_62 -> V_82 ;
if ( ! V_60 )
return 0 ;
V_68 = * ( T_3 * ) ( V_60 + 1 ) ;
if ( V_68 == V_84 ) {
F_30 ( V_85 , V_14 -> V_15 ,
L_14 ) ;
return 1 ;
}
F_30 ( V_85 , V_14 -> V_15 ,
L_15 ) ;
}
return 0 ;
}
static void F_12 ( struct V_3 * V_3 )
{
struct V_55 * V_56 = & V_3 -> V_31 ;
struct V_86 * V_86 = & V_3 -> V_86 ;
struct V_38 * V_39 ;
char * V_87 ;
int V_88 ;
struct V_89 * V_90 ;
T_5 V_91 ;
F_31 ( V_3 ) ;
V_3 -> V_92 ( V_3 , 0 ) ;
if ( F_32 () )
F_10 ( V_85 , V_3 -> V_14 -> V_15 ,
L_16 ) ;
V_39 = F_33 ( sizeof( struct V_89 ) ) ;
if ( ! V_39 )
return;
V_88 = sizeof( * V_90 ) ;
V_87 = ( char * ) V_39 -> V_74 ;
V_90 = (struct V_89 * ) V_87 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
memcpy ( V_90 -> V_93 . V_94 , V_56 -> V_95 , V_96 ) ;
memcpy ( V_90 -> V_93 . V_97 , V_98 , V_96 ) ;
V_90 -> V_93 . V_99 = F_34 ( V_100 ) ;
V_90 -> V_56 . V_101 = F_35 ( V_102 ) ;
V_90 -> V_56 . V_75 = F_34 ( V_103 ) ;
V_90 -> V_56 . V_76 = V_104 ;
V_90 -> V_56 . V_79 = F_34 ( sizeof( V_90 -> V_62 ) / V_81 ) ;
V_90 -> V_62 . V_105 . V_106 . V_82 = V_107 ;
V_90 -> V_62 . V_105 . V_106 . V_80 = sizeof( V_90 -> V_62 . V_105 ) / V_81 ;
memcpy ( & V_90 -> V_62 . V_105 . V_108 , V_56 -> V_95 , V_96 ) ;
V_90 -> V_62 . V_109 . V_106 . V_82 = V_110 ;
V_90 -> V_62 . V_109 . V_106 . V_80 = sizeof( V_90 -> V_62 . V_109 ) / V_81 ;
F_36 ( V_56 -> V_37 -> V_109 , & V_90 -> V_62 . V_109 . V_111 ) ;
F_37 ( & V_86 -> V_112 . V_113 ) ;
F_38 ( V_39 , sizeof( * V_90 ) ) ;
V_39 -> V_114 = F_34 ( V_100 ) ;
F_39 ( V_39 ) ;
F_40 ( V_39 ) ;
V_56 -> V_115 ( V_56 , V_39 ) ;
V_91 = V_116 + F_41 ( V_117 ) ;
F_42 ( & V_3 -> V_34 , F_43 ( V_91 ) ) ;
}
static void F_44 ( struct V_3 * V_3 , struct V_38 * V_39 )
{
struct V_55 * V_56 = & V_3 -> V_31 ;
struct V_57 * V_58 ;
struct V_61 * V_62 ;
struct V_86 * V_86 = & V_3 -> V_86 ;
T_2 V_118 ;
T_4 V_71 ;
T_4 V_72 ;
struct V_119 * V_90 ;
T_5 V_120 ;
unsigned long V_5 ;
F_10 ( V_85 , V_3 -> V_14 -> V_15 ,
L_17 ) ;
V_58 = (struct V_57 * ) V_39 -> V_74 ;
F_10 ( V_85 , V_3 -> V_14 -> V_15 ,
L_18 ,
F_29 ( V_58 -> V_75 ) , V_58 -> V_76 ) ;
V_71 = F_29 ( V_58 -> V_79 ) * 4 ;
F_31 ( V_3 ) ;
F_3 ( & V_3 -> V_121 , V_5 ) ;
V_62 = (struct V_61 * ) ( V_58 + 1 ) ;
while ( V_71 > 0 ) {
V_72 = V_62 -> V_80 * V_81 ;
switch ( V_62 -> V_82 ) {
case V_122 :
V_118 = F_29 ( ( (struct V_123 * ) V_62 ) -> V_124 ) ;
F_30 ( V_85 , V_3 -> V_14 -> V_15 ,
L_19 , V_118 ) ;
V_90 = F_45 ( sizeof( * V_90 ) ,
V_125 ) ;
if ( ! V_90 ) {
F_4 ( & V_3 -> V_121 ,
V_5 ) ;
goto V_126;
}
memset ( V_90 , 0 , sizeof( struct V_119 ) ) ;
V_90 -> V_118 = V_118 & 0x0fff ;
V_90 -> V_43 = V_127 ;
F_46 ( & V_90 -> V_50 , & V_3 -> V_128 ) ;
break;
}
V_62 = (struct V_61 * ) ( ( char * ) V_62 + V_72 ) ;
V_71 -= V_72 ;
}
if ( F_21 ( & V_3 -> V_128 ) ) {
F_37 ( & V_86 -> V_112 . V_129 ) ;
F_10 ( V_85 , V_3 -> V_14 -> V_15 ,
L_20 ) ;
F_4 ( & V_3 -> V_121 , V_5 ) ;
goto V_126;
}
V_90 = F_47 ( & V_3 -> V_128 , struct V_119 , V_50 ) ;
V_3 -> V_92 ( V_3 , V_90 -> V_118 ) ;
V_90 -> V_43 = V_130 ;
V_90 -> V_131 ++ ;
F_4 ( & V_3 -> V_121 , V_5 ) ;
F_13 ( V_56 ) ;
V_120 = V_116 + F_41 ( V_132 ) ;
F_42 ( & V_3 -> V_34 , F_43 ( V_120 ) ) ;
V_126:
return;
}
static void F_26 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_119 * V_90 ;
T_5 V_120 ;
F_3 ( & V_3 -> V_121 , V_5 ) ;
V_90 = F_47 ( & V_3 -> V_128 , struct V_119 , V_50 ) ;
V_3 -> V_92 ( V_3 , V_90 -> V_118 ) ;
V_90 -> V_43 = V_130 ;
V_90 -> V_131 = 1 ;
F_4 ( & V_3 -> V_121 , V_5 ) ;
F_13 ( & V_3 -> V_31 ) ;
V_120 = V_116 + F_41 ( V_132 ) ;
F_42 ( & V_3 -> V_34 , F_43 ( V_120 ) ) ;
}
static int F_48 ( struct V_3 * V_3 , T_2 V_133 )
{
unsigned long V_5 ;
struct V_119 * V_134 ;
F_3 ( & V_3 -> V_121 , V_5 ) ;
if ( F_21 ( & V_3 -> V_128 ) ) {
F_4 ( & V_3 -> V_121 , V_5 ) ;
return - V_135 ;
}
V_134 = F_47 ( & V_3 -> V_128 , struct V_119 , V_50 ) ;
if ( V_134 -> V_43 == V_136 ) {
F_4 ( & V_3 -> V_121 , V_5 ) ;
return 0 ;
}
if ( V_134 -> V_43 == V_130 ) {
V_134 -> V_43 = V_136 ;
F_4 ( & V_3 -> V_121 , V_5 ) ;
return 0 ;
}
F_4 ( & V_3 -> V_121 , V_5 ) ;
return - V_135 ;
}
static void F_49 ( struct V_3 * V_3 , enum V_137 V_138 )
{
struct V_46 * V_47 ;
unsigned long V_5 ;
V_47 = F_45 ( sizeof( * V_47 ) , V_125 ) ;
if ( ! V_47 )
return;
V_47 -> V_3 = V_3 ;
V_47 -> V_52 = V_138 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
F_46 ( & V_47 -> V_50 , & V_3 -> V_49 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_50 ( & V_3 -> V_51 ) ;
}
static int F_51 ( struct V_3 * V_3 , struct V_38 * V_39 )
{
struct V_57 * V_58 ;
int V_139 = 1 ;
T_2 V_67 ;
T_3 V_69 ;
if ( ! V_39 || ! ( V_39 -> V_74 ) )
return - 1 ;
if ( F_28 ( V_39 ) )
goto V_140;
V_58 = (struct V_57 * ) V_39 -> V_74 ;
V_67 = F_29 ( V_58 -> V_75 ) ;
V_69 = V_58 -> V_76 ;
if ( F_52 ( V_58 -> V_101 ) != V_102 )
goto V_140;
if ( F_29 ( V_58 -> V_79 ) * V_81 + sizeof( * V_58 ) > V_39 -> V_73 )
goto V_140;
if ( V_67 == V_141 && V_69 == V_142 ) {
if ( F_48 ( V_3 , F_29 ( V_58 -> V_143 ) ) )
goto V_140;
V_139 = 1 ;
} else if ( V_67 == V_103 && V_69 == V_144 ) {
F_44 ( V_3 , V_39 ) ;
V_139 = 0 ;
} else if ( V_67 == V_145 && V_69 == V_146 ) {
F_49 ( V_3 , V_53 ) ;
V_139 = 1 ;
}
V_140:
return V_139 ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_147 ) ;
struct V_86 * V_86 = & V_3 -> V_86 ;
unsigned long V_5 ;
struct V_38 * V_39 ;
struct V_148 * V_149 ;
while ( ( V_39 = F_16 ( & V_3 -> V_150 ) ) ) {
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_17 ( V_39 ) ;
return;
}
if ( V_3 -> V_43 != V_44 &&
V_3 -> V_43 != V_45 ) {
F_18 ( & V_3 -> V_150 , V_39 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_149 = (struct V_148 * ) V_39 -> V_74 ;
if ( V_149 -> V_99 == F_34 ( V_100 ) ) {
F_54 ( V_39 , sizeof( * V_149 ) ) ;
if ( F_51 ( V_3 , V_39 ) <= 0 ) {
F_17 ( V_39 ) ;
continue;
}
if ( F_27 ( & V_3 -> V_31 , V_39 ) ) {
F_37 (
& V_86 -> V_112 . V_151 ) ;
F_30 ( V_85 , V_3 -> V_14 -> V_15 ,
L_21 ) ;
F_11 ( & V_3 -> V_31 ) ;
F_12 ( V_3 ) ;
F_17 ( V_39 ) ;
continue;
}
F_55 ( & V_3 -> V_31 , V_39 ) ;
continue;
}
}
}
static inline int F_56 ( struct V_3 * V_3 , struct V_38 * V_39 )
{
struct V_40 * V_41 ;
struct V_148 * V_149 ;
struct V_152 * V_152 ;
struct V_153 * V_154 ;
V_149 = (struct V_148 * ) V_39 -> V_74 ;
if ( V_149 -> V_99 == F_34 ( V_155 ) ) {
memmove ( ( T_3 * ) V_149 + V_156 , V_149 , V_96 * 2 ) ;
V_149 = F_54 ( V_39 , V_156 ) ;
F_39 ( V_39 ) ;
}
if ( V_149 -> V_99 == F_34 ( V_100 ) ) {
if ( ! ( V_3 -> V_32 . V_5 & V_33 ) ) {
F_57 ( V_157 L_22
L_23
L_24 ) ;
goto V_140;
}
if ( ( F_9 ( V_3 -> V_14 -> V_15 -> V_26 ,
V_158 | 0x80 , ( char * ) V_39 -> V_74 , V_39 -> V_73 ) ) != 0 ) {
F_57 ( V_157 L_25 ) ;
}
F_58 ( & V_3 -> V_150 , V_39 ) ;
F_59 ( V_159 , & V_3 -> V_147 ) ;
return 1 ;
}
if ( V_149 -> V_99 != F_34 ( V_160 ) )
goto V_140;
F_60 ( V_39 , sizeof( * V_149 ) ) ;
F_54 ( V_39 , sizeof( * V_149 ) ) ;
V_152 = (struct V_152 * ) V_39 -> V_74 ;
if ( F_61 ( V_152 ) != V_161 )
goto V_140;
V_41 = (struct V_40 * ) V_39 ;
F_62 ( V_41 ) ;
F_63 ( V_41 ) = V_152 -> V_162 ;
F_54 ( V_39 , sizeof( struct V_152 ) ) ;
F_64 ( V_39 ) ;
V_154 = (struct V_153 * ) ( V_39 -> V_74 + V_39 -> V_73 - sizeof( * V_154 ) ) ;
F_65 ( V_41 ) = V_154 -> V_163 ;
F_66 ( V_39 , V_39 -> V_73 - sizeof( * V_154 ) ) ;
return 0 ;
V_140:
F_67 ( V_39 ) ;
return - 1 ;
}
void F_68 ( struct V_3 * V_3 , T_3 * V_164 )
{
T_3 * V_165 = V_3 -> V_31 . V_95 ;
T_3 * V_74 = V_3 -> V_166 ;
if ( F_69 ( V_164 ) )
V_164 = V_165 ;
if ( F_70 ( V_74 , V_164 ) )
return;
F_10 ( V_30 , V_3 -> V_14 -> V_15 , L_26 , V_164 ) ;
if ( ! F_69 ( V_74 ) && ! F_70 ( V_74 , V_165 ) )
F_71 ( V_3 -> V_12 , V_74 ) ;
memcpy ( V_74 , V_164 , V_96 ) ;
if ( ! F_70 ( V_164 , V_165 ) )
F_72 ( V_3 -> V_12 , V_164 ) ;
}
void F_73 ( struct V_36 * V_14 , T_3 * V_164 )
{
struct V_3 * V_3 = F_74 ( V_14 ) ;
F_75 ( & V_3 -> V_8 ) ;
F_68 ( V_3 , V_164 ) ;
F_76 ( & V_3 -> V_8 ) ;
}
void F_77 ( struct V_36 * V_14 , T_1 V_167 , struct V_40 * V_41 )
{
struct V_3 * V_3 = F_74 ( V_14 ) ;
T_3 * V_105 ;
int V_139 ;
F_10 ( V_30 , V_14 -> V_15 , L_27 ,
V_167 , V_41 ) ;
if ( ! V_167 ) {
F_73 ( V_14 , V_3 -> V_31 . V_95 ) ;
F_78 ( V_3 ) ;
return;
}
if ( V_41 ) {
V_105 = F_79 ( V_41 ) -> V_168 ;
if ( F_69 ( V_105 ) ) {
F_80 ( & V_3 -> V_31 , V_14 , V_41 ) ;
}
F_73 ( V_14 , V_105 ) ;
}
F_75 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_43 == V_45 || V_3 -> V_43 == V_44 )
V_3 -> V_43 = V_169 ;
else {
F_10 ( V_30 , V_3 -> V_14 -> V_15 ,
L_28
L_29 ,
F_81 ( V_3 -> V_43 ) ) ;
F_76 ( & V_3 -> V_8 ) ;
return;
}
F_76 ( & V_3 -> V_8 ) ;
V_139 = F_82 ( V_3 , V_167 ) ;
if ( V_139 < 0 ) {
F_75 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_43 == V_169 )
V_3 -> V_43 = V_45 ;
F_76 ( & V_3 -> V_8 ) ;
}
}
static int F_83 ( struct V_170 * V_12 ,
struct V_171 * V_171 , T_3 type ,
T_2 V_172 , T_2 V_173 ,
void * V_174 )
{
struct V_3 * V_3 = F_84 ( V_12 ) ;
F_85 ( & V_3 -> V_175 [ V_172 ] , V_171 , V_173 ,
V_176 , V_177 ,
NULL ) ;
return 0 ;
}
int F_86 ( struct V_3 * V_3 , int V_178 )
{
unsigned int V_179 = 0 , V_180 ;
unsigned int V_181 ;
int V_182 ;
for ( V_181 = 0 ; V_181 < V_3 -> V_183 ; V_181 ++ ) {
V_180 = F_87 ( & V_3 -> V_184 [ V_181 ] , V_178 ,
F_83 ,
NULL ) ;
if ( V_180 ) {
V_182 = F_88 ( & V_3 -> V_175 [ V_181 ] , V_185 ) ;
if ( V_182 )
F_30 ( V_157 , V_3 -> V_14 -> V_15 ,
L_30
L_31 ) ;
}
V_179 += V_180 ;
}
return V_179 ;
}
int V_185 ( struct V_186 * V_175 )
{
struct V_3 * V_3 = F_84 ( V_175 -> V_12 ) ;
struct V_38 * V_39 ;
T_2 V_73 ;
T_6 V_187 ;
int V_188 ;
V_73 = V_189 + V_190 + V_191 ;
V_39 = F_33 ( V_73 ) ;
if ( ! V_39 ) {
F_10 ( V_30 , V_3 -> V_14 -> V_15 ,
L_32 ) ;
return - V_192 ;
}
F_39 ( V_39 ) ;
F_64 ( V_39 ) ;
F_40 ( V_39 ) ;
F_38 ( V_39 , V_73 ) ;
V_187 = F_89 ( V_3 -> V_193 , V_39 -> V_74 , V_73 , V_194 ) ;
if ( F_90 ( V_3 -> V_193 , V_187 ) ) {
V_188 = - V_192 ;
F_57 ( V_157 L_33 , V_188 ) ;
goto V_195;
}
F_91 ( V_175 , V_39 , V_187 , V_73 ) ;
return 0 ;
V_195:
F_92 ( V_39 ) ;
return V_188 ;
}
void F_93 ( struct V_186 * V_175 , struct V_196 * V_197 )
{
struct V_40 * V_41 = V_197 -> V_198 ;
struct V_3 * V_3 = F_84 ( V_175 -> V_12 ) ;
F_94 ( V_3 -> V_193 , V_197 -> V_199 , V_197 -> V_73 ,
V_194 ) ;
F_17 ( F_95 ( V_41 ) ) ;
V_197 -> V_198 = NULL ;
}
void F_96 ( struct V_55 * V_56 , struct V_38 * V_39 )
{
struct V_3 * V_3 = F_97 ( V_56 ) ;
struct V_200 * V_201 = & V_3 -> V_201 [ 0 ] ;
T_6 V_187 ;
struct V_148 * V_202 ;
struct V_203 * V_204 ;
unsigned long V_5 ;
int V_188 ;
if ( ! V_3 -> V_205 ) {
V_202 = (struct V_148 * ) F_98 ( V_39 ) ;
V_204 = F_99 ( V_39 , sizeof( * V_204 ) - sizeof( * V_202 ) ) ;
memcpy ( V_204 , V_202 , 2 * V_96 ) ;
V_204 -> V_206 = F_34 ( V_155 ) ;
V_204 -> V_207 = V_202 -> V_99 ;
V_204 -> V_208 = F_34 ( V_3 -> V_209 ) ;
if ( ( F_9 ( V_3 -> V_14 -> V_15 -> V_26 ,
V_210 | 0x80 , ( char * ) V_202 , V_39 -> V_73 ) ) != 0 ) {
F_57 ( V_157 L_25 ) ;
}
} else {
if ( ( F_9 ( V_3 -> V_14 -> V_15 -> V_26 ,
V_210 | 0x80 , ( char * ) V_39 -> V_74 , V_39 -> V_73 ) ) != 0 ) {
F_57 ( V_157 L_25 ) ;
}
}
V_187 = F_89 ( V_3 -> V_193 , V_39 -> V_74 , V_39 -> V_73 , V_211 ) ;
V_188 = F_90 ( V_3 -> V_193 , V_187 ) ;
if ( V_188 ) {
F_57 ( V_157 L_33 , V_188 ) ;
goto V_195;
}
F_3 ( & V_3 -> V_212 [ 0 ] , V_5 ) ;
if ( ! F_100 ( V_201 ) )
goto V_213;
F_101 ( V_201 , V_39 , V_187 , V_39 -> V_73 ,
0 ,
V_3 -> V_209 , 1 ) ;
F_4 ( & V_3 -> V_212 [ 0 ] , V_5 ) ;
return;
V_213:
F_4 ( & V_3 -> V_212 [ 0 ] , V_5 ) ;
F_94 ( V_3 -> V_193 , V_187 , V_39 -> V_73 , V_211 ) ;
V_195:
F_92 ( V_39 ) ;
}
static int F_102 ( struct V_3 * V_3 , struct V_40 * V_41 )
{
struct V_200 * V_201 = & V_3 -> V_201 [ 0 ] ;
struct V_38 * V_39 ;
T_6 V_187 ;
struct V_148 * V_202 ;
struct V_203 * V_204 ;
struct V_152 * V_152 ;
struct V_59 * V_60 ;
T_1 V_214 , V_215 ;
int V_139 = 0 ;
unsigned long V_5 ;
V_60 = F_103 ( V_41 ) ;
V_39 = F_95 ( V_41 ) ;
if ( F_104 ( V_60 -> V_216 == V_217 ) &&
F_105 ( & V_3 -> V_31 , V_3 -> V_14 , V_39 ) )
return 0 ;
if ( ! V_3 -> V_205 ) {
V_215 = sizeof( * V_204 ) + sizeof( * V_152 ) ;
V_204 = F_99 ( V_39 , V_215 ) ;
V_202 = (struct V_148 * ) V_204 ;
V_204 -> V_206 = F_34 ( V_155 ) ;
V_204 -> V_207 = F_34 ( V_160 ) ;
V_204 -> V_208 = F_34 ( V_3 -> V_209 ) ;
V_152 = (struct V_152 * ) ( V_204 + 1 ) ;
} else {
V_215 = sizeof( * V_202 ) + sizeof( * V_152 ) ;
V_202 = F_99 ( V_39 , V_215 ) ;
V_202 -> V_99 = F_34 ( V_160 ) ;
V_152 = (struct V_152 * ) ( V_202 + 1 ) ;
}
if ( V_3 -> V_31 . V_218 )
F_106 ( V_202 -> V_97 , V_60 -> V_219 ) ;
else
memcpy ( V_202 -> V_97 , V_3 -> V_31 . V_220 , V_96 ) ;
memcpy ( V_202 -> V_94 , V_3 -> V_166 , V_96 ) ;
V_214 = V_39 -> V_73 ;
F_107 ( V_214 % 4 ) ;
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
V_152 -> V_162 = F_63 ( V_41 ) ;
if ( V_161 )
F_108 ( V_152 , V_161 ) ;
V_187 = F_89 ( V_3 -> V_193 , V_202 , V_214 , V_211 ) ;
if ( F_90 ( V_3 -> V_193 , V_187 ) ) {
V_139 = - V_192 ;
F_57 ( V_157 L_34 , V_139 ) ;
goto V_221;
}
if ( ( F_9 ( V_3 -> V_14 -> V_15 -> V_26 , V_210 ,
( char * ) V_202 , V_214 ) ) != 0 ) {
F_57 ( V_157 L_25 ) ;
}
F_3 ( & V_3 -> V_212 [ 0 ] , V_5 ) ;
if ( ! F_100 ( V_201 ) ) {
F_94 ( V_3 -> V_193 , V_187 ,
V_214 , V_211 ) ;
V_139 = - 1 ;
goto V_213;
}
F_109 ( V_201 , V_39 , V_187 , V_214 , F_65 ( V_41 ) ,
0 ,
V_3 -> V_209 , 1 , 1 , 1 ) ;
V_213:
F_4 ( & V_3 -> V_212 [ 0 ] , V_5 ) ;
V_221:
if ( V_139 )
F_110 ( F_95 ( V_41 ) ) ;
return V_139 ;
}
int F_111 ( struct V_36 * V_37 , struct V_40 * V_41 )
{
struct V_3 * V_3 = F_74 ( V_37 ) ;
unsigned long V_5 ;
if ( V_3 -> V_222 ) {
F_17 ( F_95 ( V_41 ) ) ;
return - 1 ;
}
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_43 != V_44 && V_3 -> V_43 != V_45 ) {
F_58 ( & V_3 -> V_223 , F_95 ( V_41 ) ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return 0 ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
return F_102 ( V_3 , V_41 ) ;
}
void F_112 ( struct V_3 * V_3 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
while ( ( V_39 = F_16 ( & V_3 -> V_223 ) ) ) {
V_41 = (struct V_40 * ) V_39 ;
F_102 ( V_3 , V_41 ) ;
}
}
static void F_78 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
enum V_224 V_225 ;
int V_139 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
V_226:
V_225 = V_3 -> V_43 ;
switch ( V_225 ) {
case V_44 :
case V_169 :
default:
V_3 -> V_43 = V_227 ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_139 = F_113 ( V_3 ) ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_43 != V_227 )
goto V_226;
if ( V_139 )
V_3 -> V_43 = V_225 ;
break;
case V_227 :
case V_45 :
break;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
static void F_114 ( struct V_200 * V_201 ,
struct V_171 * V_171 ,
struct V_228 * V_197 , void * V_174 )
{
struct V_38 * V_39 = V_197 -> V_198 ;
struct V_40 * V_41 = (struct V_40 * ) V_39 ;
struct V_3 * V_3 = F_84 ( V_201 -> V_12 ) ;
F_94 ( V_3 -> V_193 , V_197 -> V_199 ,
V_197 -> V_73 , V_211 ) ;
F_67 ( F_95 ( V_41 ) ) ;
V_197 -> V_198 = NULL ;
}
static int F_115 ( struct V_170 * V_12 ,
struct V_171 * V_171 , T_3 type ,
T_2 V_172 , T_2 V_173 ,
void * V_174 )
{
struct V_3 * V_3 = F_84 ( V_12 ) ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_212 [ V_172 ] , V_5 ) ;
F_116 ( & V_3 -> V_201 [ V_172 ] , V_171 , V_173 ,
F_114 , NULL ) ;
F_4 ( & V_3 -> V_212 [ V_172 ] , V_5 ) ;
return 0 ;
}
int F_117 ( struct V_3 * V_3 , int V_229 )
{
unsigned int V_230 = 0 ;
unsigned int V_181 ;
for ( V_181 = 0 ; V_181 < V_3 -> V_231 ; V_181 ++ ) {
V_230 += F_87 ( & V_3 -> V_184 [ V_3 -> V_183 + V_181 ] ,
V_229 ,
F_115 ,
NULL ) ;
}
return V_230 ;
}
void F_118 ( struct V_200 * V_201 , struct V_228 * V_197 )
{
struct V_40 * V_41 = V_197 -> V_198 ;
struct V_3 * V_3 = F_84 ( V_201 -> V_12 ) ;
F_94 ( V_3 -> V_193 , V_197 -> V_199 ,
V_197 -> V_73 , V_211 ) ;
F_17 ( F_95 ( V_41 ) ) ;
V_197 -> V_198 = NULL ;
}
void F_31 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_119 * V_90 ;
struct V_119 * V_48 ;
F_3 ( & V_3 -> V_121 , V_5 ) ;
if ( ! F_21 ( & V_3 -> V_128 ) ) {
F_22 (vlan, next, &fnic->vlans, list) {
F_23 ( & V_90 -> V_50 ) ;
F_24 ( V_90 ) ;
}
}
F_4 ( & V_3 -> V_121 , V_5 ) ;
}
void F_119 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_119 * V_90 ;
struct V_86 * V_86 = & V_3 -> V_86 ;
T_5 V_120 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_31 . V_232 == V_233 )
return;
F_3 ( & V_3 -> V_121 , V_5 ) ;
if ( F_21 ( & V_3 -> V_128 ) ) {
F_4 ( & V_3 -> V_121 , V_5 ) ;
if ( F_32 () )
F_10 ( V_30 , V_3 -> V_14 -> V_15 ,
L_35 ) ;
F_49 ( V_3 , V_53 ) ;
return;
}
V_90 = F_47 ( & V_3 -> V_128 , struct V_119 , V_50 ) ;
F_30 ( V_30 , V_3 -> V_14 -> V_15 ,
L_36 ,
V_90 -> V_118 , V_90 -> V_43 , V_90 -> V_131 ) ;
switch ( V_90 -> V_43 ) {
case V_136 :
F_10 ( V_30 , V_3 -> V_14 -> V_15 ,
L_37 ) ;
F_4 ( & V_3 -> V_121 , V_5 ) ;
break;
case V_234 :
F_4 ( & V_3 -> V_121 , V_5 ) ;
if ( F_32 () )
F_10 ( V_30 , V_3 -> V_14 -> V_15 ,
L_35 ) ;
F_49 ( V_3 , V_53 ) ;
break;
case V_130 :
if ( V_90 -> V_131 >= V_235 ) {
F_30 ( V_85 , V_3 -> V_14 -> V_15 ,
L_38 ,
V_90 -> V_118 ) ;
F_23 ( & V_90 -> V_50 ) ;
F_24 ( V_90 ) ;
V_90 = NULL ;
if ( F_21 ( & V_3 -> V_128 ) ) {
F_4 ( & V_3 -> V_121 ,
V_5 ) ;
F_30 ( V_85 , V_3 -> V_14 -> V_15 ,
L_39
L_40 ) ;
F_49 ( V_3 , V_53 ) ;
return;
}
V_90 = F_47 ( & V_3 -> V_128 , struct V_119 ,
V_50 ) ;
V_3 -> V_92 ( V_3 , V_90 -> V_118 ) ;
V_90 -> V_43 = V_130 ;
}
F_4 ( & V_3 -> V_121 , V_5 ) ;
F_37 ( & V_86 -> V_112 . V_236 ) ;
V_90 -> V_131 ++ ;
V_120 = V_116 + F_41
( V_132 ) ;
F_42 ( & V_3 -> V_34 , F_43 ( V_120 ) ) ;
break;
}
}
