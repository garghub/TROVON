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
if ( ! V_3 -> V_11 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_7 ( V_3 -> V_13 -> V_14 -> V_15 ,
V_16 , L_1 ,
strlen ( L_1 ) ) ;
} else {
if ( V_7 != V_3 -> V_10 ) {
V_3 -> V_13 -> V_17 . V_18 ++ ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_7 (
V_3 -> V_13 -> V_14 -> V_15 ,
V_16 ,
L_2 ,
strlen ( L_3 )
) ;
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_4 ) ;
F_9 ( & V_3 -> V_20 ) ;
if ( V_3 -> V_21 . V_5 & V_22 ) {
F_7 (
V_3 -> V_13 -> V_14 -> V_15 ,
V_16 ,
L_5 ,
strlen (
L_5 )
) ;
F_10 ( V_3 ) ;
return;
}
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_6 ) ;
F_11 ( & V_3 -> V_20 ) ;
} else
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_7 (
V_3 -> V_13 -> V_14 -> V_15 , V_16 ,
L_7 ,
strlen ( L_7 ) ) ;
}
} else if ( V_3 -> V_11 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_21 . V_5 & V_22 ) {
F_7 (
V_3 -> V_13 -> V_14 -> V_15 ,
V_16 , L_8 ,
strlen ( L_8 ) ) ;
F_10 ( V_3 ) ;
return;
}
F_8 ( V_19 , V_3 -> V_13 -> V_14 , L_6 ) ;
F_7 ( V_3 -> V_13 -> V_14 -> V_15 , V_16 ,
L_9 , strlen ( L_9 ) ) ;
F_11 ( & V_3 -> V_20 ) ;
} else {
V_3 -> V_13 -> V_17 . V_18 ++ ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_8 ( V_19 , V_3 -> V_13 -> V_14 , L_4 ) ;
F_7 (
V_3 -> V_13 -> V_14 -> V_15 , V_16 ,
L_10 ,
strlen ( L_10 ) ) ;
F_9 ( & V_3 -> V_20 ) ;
}
}
void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_23 ) ;
struct V_24 * V_25 = V_3 -> V_13 ;
unsigned long V_5 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
while ( ( V_27 = F_13 ( & V_3 -> V_30 ) ) ) {
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_14 ( V_27 ) ;
return;
}
V_29 = (struct V_28 * ) V_27 ;
if ( V_3 -> V_31 != V_32 &&
V_3 -> V_31 != V_33 ) {
F_15 ( & V_3 -> V_30 , V_27 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_16 ( V_25 , V_29 ) ;
}
}
void F_17 ( struct V_3 * V_3 )
{
struct V_34 * V_35 = NULL ;
struct V_34 * V_36 = NULL ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( F_18 ( & V_3 -> V_37 ) ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_19 (fevt, next, &fnic->evlist, list) {
F_20 ( & V_35 -> V_38 ) ;
F_21 ( V_35 ) ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_39 ) ;
struct V_34 * V_35 = NULL ;
struct V_34 * V_36 = NULL ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( F_18 ( & V_3 -> V_37 ) ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_19 (fevt, next, &fnic->evlist, list) {
if ( V_3 -> V_9 ) {
F_20 ( & V_35 -> V_38 ) ;
F_21 ( V_35 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
if ( V_3 -> V_31 != V_32 &&
V_3 -> V_31 != V_33 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_20 ( & V_35 -> V_38 ) ;
switch ( V_35 -> V_40 ) {
case V_41 :
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_10 ( V_3 ) ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
break;
case V_42 :
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_11 ) ;
F_23 ( V_3 ) ;
break;
default:
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_12 , V_35 -> V_40 ) ;
break;
}
F_21 ( V_35 ) ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
static inline int F_24 ( struct V_43 * V_44 ,
struct V_26 * V_27 )
{
struct V_24 * V_13 = V_44 -> V_25 ;
struct V_45 * V_46 ;
struct V_47 * V_48 = NULL ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
enum V_53 V_54 = 0 ;
T_2 V_55 ;
T_3 V_56 ;
T_3 V_57 ;
T_4 V_58 = 0 ;
T_4 V_59 ;
T_4 V_60 = 0 ;
if ( F_25 ( V_27 ) )
return 0 ;
if ( V_27 -> V_61 < sizeof( * V_46 ) )
return 0 ;
V_46 = (struct V_45 * ) V_27 -> V_62 ;
V_55 = F_26 ( V_46 -> V_63 ) ;
V_57 = V_46 -> V_64 ;
if ( V_55 != V_65 )
return 0 ;
if ( V_57 != V_66 )
return 0 ;
V_59 = F_26 ( V_46 -> V_67 ) * 4 ;
if ( V_59 + sizeof( * V_46 ) > V_27 -> V_61 )
return 0 ;
V_50 = (struct V_49 * ) ( V_46 + 1 ) ;
V_60 = V_50 -> V_68 * V_69 ;
if ( V_50 -> V_70 == V_71 ) {
if ( V_60 < sizeof( * V_52 ) + sizeof( * V_48 ) + 1 )
return 0 ;
V_58 = V_60 - sizeof( * V_52 ) ;
V_52 = (struct V_51 * ) V_50 ;
V_48 = (struct V_47 * ) ( V_52 + 1 ) ;
V_54 = V_50 -> V_70 ;
if ( ! V_48 )
return 0 ;
V_56 = * ( T_3 * ) ( V_48 + 1 ) ;
if ( V_56 == V_72 ) {
F_27 ( V_73 , V_13 -> V_14 ,
L_13 ) ;
return 1 ;
}
F_27 ( V_73 , V_13 -> V_14 ,
L_14 ) ;
}
return 0 ;
}
static void F_10 ( struct V_3 * V_3 )
{
struct V_43 * V_44 = & V_3 -> V_20 ;
struct V_74 * V_74 = & V_3 -> V_74 ;
struct V_26 * V_27 ;
char * V_75 ;
int V_76 ;
struct V_77 * V_78 ;
T_5 V_79 ;
F_28 ( V_3 ) ;
V_3 -> V_80 ( V_3 , 0 ) ;
F_8 ( V_73 , V_3 -> V_13 -> V_14 ,
L_15 ) ;
V_27 = F_29 ( sizeof( struct V_77 ) ) ;
if ( ! V_27 )
return;
V_76 = sizeof( * V_78 ) ;
V_75 = ( char * ) V_27 -> V_62 ;
V_78 = (struct V_77 * ) V_75 ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
memcpy ( V_78 -> V_81 . V_82 , V_44 -> V_83 , V_84 ) ;
memcpy ( V_78 -> V_81 . V_85 , V_86 , V_84 ) ;
V_78 -> V_81 . V_87 = F_30 ( V_88 ) ;
V_78 -> V_44 . V_89 = F_31 ( V_90 ) ;
V_78 -> V_44 . V_63 = F_30 ( V_91 ) ;
V_78 -> V_44 . V_64 = V_92 ;
V_78 -> V_44 . V_67 = F_30 ( sizeof( V_78 -> V_50 ) / V_69 ) ;
V_78 -> V_50 . V_93 . V_94 . V_70 = V_95 ;
V_78 -> V_50 . V_93 . V_94 . V_68 = sizeof( V_78 -> V_50 . V_93 ) / V_69 ;
memcpy ( & V_78 -> V_50 . V_93 . V_96 , V_44 -> V_83 , V_84 ) ;
V_78 -> V_50 . V_97 . V_94 . V_70 = V_98 ;
V_78 -> V_50 . V_97 . V_94 . V_68 = sizeof( V_78 -> V_50 . V_97 ) / V_69 ;
F_32 ( V_44 -> V_25 -> V_97 , & V_78 -> V_50 . V_97 . V_99 ) ;
F_33 ( & V_74 -> V_100 . V_101 ) ;
F_34 ( V_27 , sizeof( * V_78 ) ) ;
V_27 -> V_102 = F_30 ( V_88 ) ;
F_35 ( V_27 ) ;
F_36 ( V_27 ) ;
V_44 -> V_103 ( V_44 , V_27 ) ;
V_79 = V_104 + F_37 ( V_105 ) ;
F_38 ( & V_3 -> V_106 , F_39 ( V_79 ) ) ;
}
static void F_40 ( struct V_3 * V_3 , struct V_26 * V_27 )
{
struct V_43 * V_44 = & V_3 -> V_20 ;
struct V_45 * V_46 ;
struct V_49 * V_50 ;
struct V_74 * V_74 = & V_3 -> V_74 ;
T_2 V_107 ;
T_4 V_59 ;
T_4 V_60 ;
struct V_108 * V_78 ;
T_5 V_109 ;
unsigned long V_5 ;
F_8 ( V_73 , V_3 -> V_13 -> V_14 ,
L_16 ) ;
V_46 = (struct V_45 * ) V_27 -> V_62 ;
F_8 ( V_73 , V_3 -> V_13 -> V_14 ,
L_17 ,
F_26 ( V_46 -> V_63 ) , V_46 -> V_64 ) ;
V_59 = F_26 ( V_46 -> V_67 ) * 4 ;
F_28 ( V_3 ) ;
F_3 ( & V_3 -> V_110 , V_5 ) ;
V_50 = (struct V_49 * ) ( V_46 + 1 ) ;
while ( V_59 > 0 ) {
V_60 = V_50 -> V_68 * V_69 ;
switch ( V_50 -> V_70 ) {
case V_111 :
V_107 = F_26 ( ( (struct V_112 * ) V_50 ) -> V_113 ) ;
F_27 ( V_73 , V_3 -> V_13 -> V_14 ,
L_18 , V_107 ) ;
V_78 = F_41 ( sizeof( * V_78 ) ,
V_114 ) ;
if ( ! V_78 ) {
F_4 ( & V_3 -> V_110 ,
V_5 ) ;
goto V_115;
}
memset ( V_78 , 0 , sizeof( struct V_108 ) ) ;
V_78 -> V_107 = V_107 & 0x0fff ;
V_78 -> V_31 = V_116 ;
F_42 ( & V_78 -> V_38 , & V_3 -> V_117 ) ;
break;
}
V_50 = (struct V_49 * ) ( ( char * ) V_50 + V_60 ) ;
V_59 -= V_60 ;
}
if ( F_18 ( & V_3 -> V_117 ) ) {
F_33 ( & V_74 -> V_100 . V_118 ) ;
F_8 ( V_73 , V_3 -> V_13 -> V_14 ,
L_19 ) ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
goto V_115;
}
V_78 = F_43 ( & V_3 -> V_117 , struct V_108 , V_38 ) ;
V_3 -> V_80 ( V_3 , V_78 -> V_107 ) ;
V_78 -> V_31 = V_119 ;
V_78 -> V_120 ++ ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
F_11 ( V_44 ) ;
V_109 = V_104 + F_37 ( V_121 ) ;
F_38 ( & V_3 -> V_106 , F_39 ( V_109 ) ) ;
V_115:
return;
}
static void F_23 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_108 * V_78 ;
T_5 V_109 ;
F_3 ( & V_3 -> V_110 , V_5 ) ;
V_78 = F_43 ( & V_3 -> V_117 , struct V_108 , V_38 ) ;
V_3 -> V_80 ( V_3 , V_78 -> V_107 ) ;
V_78 -> V_31 = V_119 ;
V_78 -> V_120 = 1 ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
F_11 ( & V_3 -> V_20 ) ;
V_109 = V_104 + F_37 ( V_121 ) ;
F_38 ( & V_3 -> V_106 , F_39 ( V_109 ) ) ;
}
static int F_44 ( struct V_3 * V_3 , T_2 V_122 )
{
unsigned long V_5 ;
struct V_108 * V_123 ;
F_3 ( & V_3 -> V_110 , V_5 ) ;
if ( F_18 ( & V_3 -> V_117 ) ) {
F_4 ( & V_3 -> V_110 , V_5 ) ;
return - V_124 ;
}
V_123 = F_43 ( & V_3 -> V_117 , struct V_108 , V_38 ) ;
if ( V_123 -> V_31 == V_125 ) {
F_4 ( & V_3 -> V_110 , V_5 ) ;
return 0 ;
}
if ( V_123 -> V_31 == V_119 ) {
V_123 -> V_31 = V_125 ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
return 0 ;
}
F_4 ( & V_3 -> V_110 , V_5 ) ;
return - V_124 ;
}
static void F_45 ( struct V_3 * V_3 , enum V_126 V_127 )
{
struct V_34 * V_35 ;
unsigned long V_5 ;
V_35 = F_41 ( sizeof( * V_35 ) , V_114 ) ;
if ( ! V_35 )
return;
V_35 -> V_3 = V_3 ;
V_35 -> V_40 = V_127 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
F_42 ( & V_35 -> V_38 , & V_3 -> V_37 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_46 ( & V_3 -> V_39 ) ;
}
static int F_47 ( struct V_3 * V_3 , struct V_26 * V_27 )
{
struct V_45 * V_46 ;
int V_128 = 1 ;
T_2 V_55 ;
T_3 V_57 ;
if ( ! V_27 || ! ( V_27 -> V_62 ) )
return - 1 ;
if ( F_25 ( V_27 ) )
goto V_129;
V_46 = (struct V_45 * ) V_27 -> V_62 ;
V_55 = F_26 ( V_46 -> V_63 ) ;
V_57 = V_46 -> V_64 ;
if ( F_48 ( V_46 -> V_89 ) != V_90 )
goto V_129;
if ( F_26 ( V_46 -> V_67 ) * V_69 + sizeof( * V_46 ) > V_27 -> V_61 )
goto V_129;
if ( V_55 == V_130 && V_57 == V_131 ) {
if ( F_44 ( V_3 , F_26 ( V_46 -> V_132 ) ) )
goto V_129;
V_128 = 1 ;
} else if ( V_55 == V_91 && V_57 == V_133 ) {
F_40 ( V_3 , V_27 ) ;
V_128 = 0 ;
} else if ( V_55 == V_134 && V_57 == V_135 ) {
F_45 ( V_3 , V_41 ) ;
V_128 = 1 ;
}
V_129:
return V_128 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_136 ) ;
struct V_74 * V_74 = & V_3 -> V_74 ;
unsigned long V_5 ;
struct V_26 * V_27 ;
struct V_137 * V_138 ;
while ( ( V_27 = F_13 ( & V_3 -> V_139 ) ) ) {
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_14 ( V_27 ) ;
return;
}
if ( V_3 -> V_31 != V_32 &&
V_3 -> V_31 != V_33 ) {
F_15 ( & V_3 -> V_139 , V_27 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_138 = (struct V_137 * ) V_27 -> V_62 ;
if ( V_138 -> V_87 == F_30 ( V_88 ) ) {
F_50 ( V_27 , sizeof( * V_138 ) ) ;
if ( F_47 ( V_3 , V_27 ) <= 0 ) {
F_14 ( V_27 ) ;
continue;
}
if ( F_24 ( & V_3 -> V_20 , V_27 ) ) {
F_33 (
& V_74 -> V_100 . V_140 ) ;
F_27 ( V_73 , V_3 -> V_13 -> V_14 ,
L_20 ) ;
F_9 ( & V_3 -> V_20 ) ;
F_10 ( V_3 ) ;
F_14 ( V_27 ) ;
continue;
}
F_51 ( & V_3 -> V_20 , V_27 ) ;
continue;
}
}
}
static inline int F_52 ( struct V_3 * V_3 , struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_137 * V_138 ;
struct V_141 * V_141 ;
struct V_142 * V_143 ;
V_138 = (struct V_137 * ) V_27 -> V_62 ;
if ( V_138 -> V_87 == F_30 ( V_144 ) ) {
memmove ( ( T_3 * ) V_138 + V_145 , V_138 , V_84 * 2 ) ;
V_138 = (struct V_137 * ) F_50 ( V_27 , V_145 ) ;
F_35 ( V_27 ) ;
}
if ( V_138 -> V_87 == F_30 ( V_88 ) ) {
if ( ! ( V_3 -> V_21 . V_5 & V_22 ) ) {
F_53 ( V_146 L_21
L_22
L_23 ) ;
goto V_129;
}
if ( ( F_7 ( V_3 -> V_13 -> V_14 -> V_15 ,
V_147 | 0x80 , ( char * ) V_27 -> V_62 , V_27 -> V_61 ) ) != 0 ) {
F_53 ( V_146 L_24 ) ;
}
F_54 ( & V_3 -> V_139 , V_27 ) ;
F_55 ( V_148 , & V_3 -> V_136 ) ;
return 1 ;
}
if ( V_138 -> V_87 != F_30 ( V_149 ) )
goto V_129;
F_56 ( V_27 , sizeof( * V_138 ) ) ;
F_50 ( V_27 , sizeof( * V_138 ) ) ;
V_141 = (struct V_141 * ) V_27 -> V_62 ;
if ( F_57 ( V_141 ) != V_150 )
goto V_129;
V_29 = (struct V_28 * ) V_27 ;
F_58 ( V_29 ) ;
F_59 ( V_29 ) = V_141 -> V_151 ;
F_50 ( V_27 , sizeof( struct V_141 ) ) ;
F_60 ( V_27 ) ;
V_143 = (struct V_142 * ) ( V_27 -> V_62 + V_27 -> V_61 - sizeof( * V_143 ) ) ;
F_61 ( V_29 ) = V_143 -> V_152 ;
F_62 ( V_27 , V_27 -> V_61 - sizeof( * V_143 ) ) ;
return 0 ;
V_129:
F_63 ( V_27 ) ;
return - 1 ;
}
void F_64 ( struct V_3 * V_3 , T_3 * V_153 )
{
T_3 * V_154 = V_3 -> V_20 . V_83 ;
T_3 * V_62 = V_3 -> V_155 ;
if ( F_65 ( V_153 ) )
V_153 = V_154 ;
if ( F_66 ( V_62 , V_153 ) )
return;
F_8 ( V_19 , V_3 -> V_13 -> V_14 , L_25 , V_153 ) ;
if ( ! F_65 ( V_62 ) && ! F_66 ( V_62 , V_154 ) )
F_67 ( V_3 -> V_12 , V_62 ) ;
memcpy ( V_62 , V_153 , V_84 ) ;
if ( ! F_66 ( V_153 , V_154 ) )
F_68 ( V_3 -> V_12 , V_153 ) ;
}
void F_69 ( struct V_24 * V_13 , T_3 * V_153 )
{
struct V_3 * V_3 = F_70 ( V_13 ) ;
F_71 ( & V_3 -> V_8 ) ;
F_64 ( V_3 , V_153 ) ;
F_72 ( & V_3 -> V_8 ) ;
}
void F_73 ( struct V_24 * V_13 , T_1 V_156 , struct V_28 * V_29 )
{
struct V_3 * V_3 = F_70 ( V_13 ) ;
T_3 * V_93 ;
int V_128 ;
F_8 ( V_19 , V_13 -> V_14 , L_26 ,
V_156 , V_29 ) ;
if ( ! V_156 ) {
F_69 ( V_13 , V_3 -> V_20 . V_83 ) ;
F_74 ( V_3 ) ;
return;
}
if ( V_29 ) {
V_93 = F_75 ( V_29 ) -> V_157 ;
if ( F_65 ( V_93 ) ) {
F_76 ( & V_3 -> V_20 , V_13 , V_29 ) ;
}
F_69 ( V_13 , V_93 ) ;
}
F_71 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_31 == V_33 || V_3 -> V_31 == V_32 )
V_3 -> V_31 = V_158 ;
else {
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_27
L_28 ,
F_77 ( V_3 -> V_31 ) ) ;
F_72 ( & V_3 -> V_8 ) ;
return;
}
F_72 ( & V_3 -> V_8 ) ;
V_128 = F_78 ( V_3 , V_156 ) ;
if ( V_128 < 0 ) {
F_71 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_31 == V_158 )
V_3 -> V_31 = V_33 ;
F_72 ( & V_3 -> V_8 ) ;
}
}
static int F_79 ( struct V_159 * V_12 ,
struct V_160 * V_160 , T_3 type ,
T_2 V_161 , T_2 V_162 ,
void * V_163 )
{
struct V_3 * V_3 = F_80 ( V_12 ) ;
F_81 ( & V_3 -> V_164 [ V_161 ] , V_160 , V_162 ,
V_165 , V_166 ,
NULL ) ;
return 0 ;
}
int F_82 ( struct V_3 * V_3 , int V_167 )
{
unsigned int V_168 = 0 , V_169 ;
unsigned int V_170 ;
int V_171 ;
for ( V_170 = 0 ; V_170 < V_3 -> V_172 ; V_170 ++ ) {
V_169 = F_83 ( & V_3 -> V_173 [ V_170 ] , V_167 ,
F_79 ,
NULL ) ;
if ( V_169 ) {
V_171 = F_84 ( & V_3 -> V_164 [ V_170 ] , V_174 ) ;
if ( V_171 )
F_27 ( V_146 , V_3 -> V_13 -> V_14 ,
L_29
L_30 ) ;
}
V_168 += V_169 ;
}
return V_168 ;
}
int V_174 ( struct V_175 * V_164 )
{
struct V_3 * V_3 = F_80 ( V_164 -> V_12 ) ;
struct V_26 * V_27 ;
T_2 V_61 ;
T_6 V_176 ;
V_61 = V_177 + V_178 + V_179 ;
V_27 = F_29 ( V_61 ) ;
if ( ! V_27 ) {
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_31 ) ;
return - V_180 ;
}
F_35 ( V_27 ) ;
F_60 ( V_27 ) ;
F_36 ( V_27 ) ;
F_34 ( V_27 , V_61 ) ;
V_176 = F_85 ( V_3 -> V_181 , V_27 -> V_62 , V_61 , V_182 ) ;
F_86 ( V_164 , V_27 , V_176 , V_61 ) ;
return 0 ;
}
void F_87 ( struct V_175 * V_164 , struct V_183 * V_184 )
{
struct V_28 * V_29 = V_184 -> V_185 ;
struct V_3 * V_3 = F_80 ( V_164 -> V_12 ) ;
F_88 ( V_3 -> V_181 , V_184 -> V_186 , V_184 -> V_61 ,
V_182 ) ;
F_14 ( F_89 ( V_29 ) ) ;
V_184 -> V_185 = NULL ;
}
void F_90 ( struct V_43 * V_44 , struct V_26 * V_27 )
{
struct V_3 * V_3 = F_91 ( V_44 ) ;
struct V_187 * V_188 = & V_3 -> V_188 [ 0 ] ;
T_6 V_176 ;
struct V_137 * V_189 ;
struct V_190 * V_191 ;
unsigned long V_5 ;
if ( ! V_3 -> V_192 ) {
V_189 = (struct V_137 * ) F_92 ( V_27 ) ;
V_191 = (struct V_190 * ) F_93 ( V_27 ,
sizeof( * V_191 ) - sizeof( * V_189 ) ) ;
memcpy ( V_191 , V_189 , 2 * V_84 ) ;
V_191 -> V_193 = F_30 ( V_144 ) ;
V_191 -> V_194 = V_189 -> V_87 ;
V_191 -> V_195 = F_30 ( V_3 -> V_196 ) ;
if ( ( F_7 ( V_3 -> V_13 -> V_14 -> V_15 ,
V_197 | 0x80 , ( char * ) V_189 , V_27 -> V_61 ) ) != 0 ) {
F_53 ( V_146 L_24 ) ;
}
} else {
if ( ( F_7 ( V_3 -> V_13 -> V_14 -> V_15 ,
V_197 | 0x80 , ( char * ) V_27 -> V_62 , V_27 -> V_61 ) ) != 0 ) {
F_53 ( V_146 L_24 ) ;
}
}
V_176 = F_85 ( V_3 -> V_181 , V_27 -> V_62 , V_27 -> V_61 , V_198 ) ;
F_3 ( & V_3 -> V_199 [ 0 ] , V_5 ) ;
if ( ! F_94 ( V_188 ) ) {
F_88 ( V_3 -> V_181 , V_176 , V_27 -> V_61 , V_198 ) ;
F_4 ( & V_3 -> V_199 [ 0 ] , V_5 ) ;
F_95 ( V_27 ) ;
return;
}
F_96 ( V_188 , V_27 , V_176 , V_27 -> V_61 ,
0 ,
V_3 -> V_196 , 1 ) ;
F_4 ( & V_3 -> V_199 [ 0 ] , V_5 ) ;
}
static int F_97 ( struct V_3 * V_3 , struct V_28 * V_29 )
{
struct V_187 * V_188 = & V_3 -> V_188 [ 0 ] ;
struct V_26 * V_27 ;
T_6 V_176 ;
struct V_137 * V_189 ;
struct V_190 * V_191 ;
struct V_141 * V_141 ;
struct V_47 * V_48 ;
T_1 V_200 , V_201 ;
int V_128 = 0 ;
unsigned long V_5 ;
V_48 = F_98 ( V_29 ) ;
V_27 = F_89 ( V_29 ) ;
if ( F_99 ( V_48 -> V_202 == V_203 ) &&
F_100 ( & V_3 -> V_20 , V_3 -> V_13 , V_27 ) )
return 0 ;
if ( ! V_3 -> V_192 ) {
V_201 = sizeof( * V_191 ) + sizeof( * V_141 ) ;
V_191 = (struct V_190 * ) F_93 ( V_27 , V_201 ) ;
V_189 = (struct V_137 * ) V_191 ;
V_191 -> V_193 = F_30 ( V_144 ) ;
V_191 -> V_194 = F_30 ( V_149 ) ;
V_191 -> V_195 = F_30 ( V_3 -> V_196 ) ;
V_141 = (struct V_141 * ) ( V_191 + 1 ) ;
} else {
V_201 = sizeof( * V_189 ) + sizeof( * V_141 ) ;
V_189 = (struct V_137 * ) F_93 ( V_27 , V_201 ) ;
V_189 -> V_87 = F_30 ( V_149 ) ;
V_141 = (struct V_141 * ) ( V_189 + 1 ) ;
}
if ( V_3 -> V_20 . V_204 )
F_101 ( V_189 -> V_85 , V_48 -> V_205 ) ;
else
memcpy ( V_189 -> V_85 , V_3 -> V_20 . V_206 , V_84 ) ;
memcpy ( V_189 -> V_82 , V_3 -> V_155 , V_84 ) ;
V_200 = V_27 -> V_61 ;
F_102 ( V_200 % 4 ) ;
memset ( V_141 , 0 , sizeof( * V_141 ) ) ;
V_141 -> V_151 = F_59 ( V_29 ) ;
if ( V_150 )
F_103 ( V_141 , V_150 ) ;
V_176 = F_85 ( V_3 -> V_181 , V_189 , V_200 , V_198 ) ;
if ( ( F_7 ( V_3 -> V_13 -> V_14 -> V_15 , V_197 ,
( char * ) V_189 , V_200 ) ) != 0 ) {
F_53 ( V_146 L_24 ) ;
}
F_3 ( & V_3 -> V_199 [ 0 ] , V_5 ) ;
if ( ! F_94 ( V_188 ) ) {
F_88 ( V_3 -> V_181 , V_176 ,
V_200 , V_198 ) ;
V_128 = - 1 ;
goto V_207;
}
F_104 ( V_188 , V_27 , V_176 , V_200 , F_61 ( V_29 ) ,
0 ,
V_3 -> V_196 , 1 , 1 , 1 ) ;
V_207:
F_4 ( & V_3 -> V_199 [ 0 ] , V_5 ) ;
if ( V_128 )
F_105 ( F_89 ( V_29 ) ) ;
return V_128 ;
}
int F_106 ( struct V_24 * V_25 , struct V_28 * V_29 )
{
struct V_3 * V_3 = F_70 ( V_25 ) ;
unsigned long V_5 ;
if ( V_3 -> V_208 ) {
F_14 ( F_89 ( V_29 ) ) ;
return - 1 ;
}
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_31 != V_32 && V_3 -> V_31 != V_33 ) {
F_54 ( & V_3 -> V_209 , F_89 ( V_29 ) ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return 0 ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
return F_97 ( V_3 , V_29 ) ;
}
void F_107 ( struct V_3 * V_3 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
while ( ( V_27 = F_13 ( & V_3 -> V_209 ) ) ) {
V_29 = (struct V_28 * ) V_27 ;
F_97 ( V_3 , V_29 ) ;
}
}
static void F_74 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
enum V_210 V_211 ;
int V_128 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
V_212:
V_211 = V_3 -> V_31 ;
switch ( V_211 ) {
case V_32 :
case V_158 :
default:
V_3 -> V_31 = V_213 ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_128 = F_108 ( V_3 ) ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_31 != V_213 )
goto V_212;
if ( V_128 )
V_3 -> V_31 = V_211 ;
break;
case V_213 :
case V_33 :
break;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
static void F_109 ( struct V_187 * V_188 ,
struct V_160 * V_160 ,
struct V_214 * V_184 , void * V_163 )
{
struct V_26 * V_27 = V_184 -> V_185 ;
struct V_28 * V_29 = (struct V_28 * ) V_27 ;
struct V_3 * V_3 = F_80 ( V_188 -> V_12 ) ;
F_88 ( V_3 -> V_181 , V_184 -> V_186 ,
V_184 -> V_61 , V_198 ) ;
F_63 ( F_89 ( V_29 ) ) ;
V_184 -> V_185 = NULL ;
}
static int F_110 ( struct V_159 * V_12 ,
struct V_160 * V_160 , T_3 type ,
T_2 V_161 , T_2 V_162 ,
void * V_163 )
{
struct V_3 * V_3 = F_80 ( V_12 ) ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_199 [ V_161 ] , V_5 ) ;
F_111 ( & V_3 -> V_188 [ V_161 ] , V_160 , V_162 ,
F_109 , NULL ) ;
F_4 ( & V_3 -> V_199 [ V_161 ] , V_5 ) ;
return 0 ;
}
int F_112 ( struct V_3 * V_3 , int V_215 )
{
unsigned int V_216 = 0 ;
unsigned int V_170 ;
for ( V_170 = 0 ; V_170 < V_3 -> V_217 ; V_170 ++ ) {
V_216 += F_83 ( & V_3 -> V_173 [ V_3 -> V_172 + V_170 ] ,
V_215 ,
F_110 ,
NULL ) ;
}
return V_216 ;
}
void F_113 ( struct V_187 * V_188 , struct V_214 * V_184 )
{
struct V_28 * V_29 = V_184 -> V_185 ;
struct V_3 * V_3 = F_80 ( V_188 -> V_12 ) ;
F_88 ( V_3 -> V_181 , V_184 -> V_186 ,
V_184 -> V_61 , V_198 ) ;
F_14 ( F_89 ( V_29 ) ) ;
V_184 -> V_185 = NULL ;
}
void F_28 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_108 * V_78 ;
struct V_108 * V_36 ;
F_3 ( & V_3 -> V_110 , V_5 ) ;
if ( ! F_18 ( & V_3 -> V_117 ) ) {
F_19 (vlan, next, &fnic->vlans, list) {
F_20 ( & V_78 -> V_38 ) ;
F_21 ( V_78 ) ;
}
}
F_4 ( & V_3 -> V_110 , V_5 ) ;
}
void F_114 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_108 * V_78 ;
struct V_74 * V_74 = & V_3 -> V_74 ;
T_5 V_109 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_20 . V_218 == V_219 )
return;
F_3 ( & V_3 -> V_110 , V_5 ) ;
if ( F_18 ( & V_3 -> V_117 ) ) {
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_32 ) ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
F_45 ( V_3 , V_41 ) ;
return;
}
V_78 = F_43 ( & V_3 -> V_117 , struct V_108 , V_38 ) ;
F_27 ( V_19 , V_3 -> V_13 -> V_14 ,
L_33 ,
V_78 -> V_107 , V_78 -> V_31 , V_78 -> V_120 ) ;
switch ( V_78 -> V_31 ) {
case V_125 :
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_34 ) ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
break;
case V_220 :
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_32 ) ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
F_45 ( V_3 , V_41 ) ;
break;
case V_119 :
if ( V_78 -> V_120 >= V_221 ) {
F_27 ( V_73 , V_3 -> V_13 -> V_14 ,
L_35 ,
V_78 -> V_107 ) ;
F_20 ( & V_78 -> V_38 ) ;
F_21 ( V_78 ) ;
V_78 = NULL ;
if ( F_18 ( & V_3 -> V_117 ) ) {
F_4 ( & V_3 -> V_110 ,
V_5 ) ;
F_27 ( V_73 , V_3 -> V_13 -> V_14 ,
L_36
L_37 ) ;
F_45 ( V_3 , V_41 ) ;
return;
}
V_78 = F_43 ( & V_3 -> V_117 , struct V_108 ,
V_38 ) ;
V_3 -> V_80 ( V_3 , V_78 -> V_107 ) ;
V_78 -> V_31 = V_119 ;
}
F_4 ( & V_3 -> V_110 , V_5 ) ;
F_33 ( & V_74 -> V_100 . V_222 ) ;
V_78 -> V_120 ++ ;
V_109 = V_104 + F_37
( V_121 ) ;
F_38 ( & V_3 -> V_106 , F_39 ( V_109 ) ) ;
break;
}
}
