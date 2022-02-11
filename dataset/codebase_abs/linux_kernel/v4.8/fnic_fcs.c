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
} else {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_7 (
V_3 -> V_13 -> V_14 -> V_15 , V_16 ,
L_7 ,
strlen ( L_7 ) ) ;
}
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
if ( V_3 -> V_21 . V_5 & V_22 ) {
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_11 ) ;
F_12 ( & V_3 -> V_23 ) ;
}
F_9 ( & V_3 -> V_20 ) ;
}
}
void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_24 ) ;
struct V_25 * V_26 = V_3 -> V_13 ;
unsigned long V_5 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
while ( ( V_28 = F_14 ( & V_3 -> V_31 ) ) ) {
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_15 ( V_28 ) ;
return;
}
V_30 = (struct V_29 * ) V_28 ;
if ( V_3 -> V_32 != V_33 &&
V_3 -> V_32 != V_34 ) {
F_16 ( & V_3 -> V_31 , V_28 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_17 ( V_26 , V_30 ) ;
}
}
void F_18 ( struct V_3 * V_3 )
{
struct V_35 * V_36 = NULL ;
struct V_35 * V_37 = NULL ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( F_19 ( & V_3 -> V_38 ) ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_20 (fevt, next, &fnic->evlist, list) {
F_21 ( & V_36 -> V_39 ) ;
F_22 ( V_36 ) ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_40 ) ;
struct V_35 * V_36 = NULL ;
struct V_35 * V_37 = NULL ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( F_19 ( & V_3 -> V_38 ) ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_20 (fevt, next, &fnic->evlist, list) {
if ( V_3 -> V_9 ) {
F_21 ( & V_36 -> V_39 ) ;
F_22 ( V_36 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
if ( V_3 -> V_32 != V_33 &&
V_3 -> V_32 != V_34 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_21 ( & V_36 -> V_39 ) ;
switch ( V_36 -> V_41 ) {
case V_42 :
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_10 ( V_3 ) ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
break;
case V_43 :
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_12 ) ;
F_24 ( V_3 ) ;
break;
default:
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_13 , V_36 -> V_41 ) ;
break;
}
F_22 ( V_36 ) ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
static inline int F_25 ( struct V_44 * V_45 ,
struct V_27 * V_28 )
{
struct V_25 * V_13 = V_45 -> V_26 ;
struct V_46 * V_47 ;
struct V_48 * V_49 = NULL ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
enum V_54 V_55 = 0 ;
T_2 V_56 ;
T_3 V_57 ;
T_3 V_58 ;
T_4 V_59 = 0 ;
T_4 V_60 ;
T_4 V_61 = 0 ;
if ( F_26 ( V_28 ) )
return 0 ;
if ( V_28 -> V_62 < sizeof( * V_47 ) )
return 0 ;
V_47 = (struct V_46 * ) V_28 -> V_63 ;
V_56 = F_27 ( V_47 -> V_64 ) ;
V_58 = V_47 -> V_65 ;
if ( V_56 != V_66 )
return 0 ;
if ( V_58 != V_67 )
return 0 ;
V_60 = F_27 ( V_47 -> V_68 ) * 4 ;
if ( V_60 + sizeof( * V_47 ) > V_28 -> V_62 )
return 0 ;
V_51 = (struct V_50 * ) ( V_47 + 1 ) ;
V_61 = V_51 -> V_69 * V_70 ;
if ( V_51 -> V_71 == V_72 ) {
if ( V_61 < sizeof( * V_53 ) + sizeof( * V_49 ) + 1 )
return 0 ;
V_59 = V_61 - sizeof( * V_53 ) ;
V_53 = (struct V_52 * ) V_51 ;
V_49 = (struct V_48 * ) ( V_53 + 1 ) ;
V_55 = V_51 -> V_71 ;
if ( ! V_49 )
return 0 ;
V_57 = * ( T_3 * ) ( V_49 + 1 ) ;
if ( V_57 == V_73 ) {
F_28 ( V_74 , V_13 -> V_14 ,
L_14 ) ;
return 1 ;
}
F_28 ( V_74 , V_13 -> V_14 ,
L_15 ) ;
}
return 0 ;
}
static void F_10 ( struct V_3 * V_3 )
{
struct V_44 * V_45 = & V_3 -> V_20 ;
struct V_75 * V_75 = & V_3 -> V_75 ;
struct V_27 * V_28 ;
char * V_76 ;
int V_77 ;
struct V_78 * V_79 ;
T_5 V_80 ;
F_29 ( V_3 ) ;
V_3 -> V_81 ( V_3 , 0 ) ;
F_8 ( V_74 , V_3 -> V_13 -> V_14 ,
L_16 ) ;
V_28 = F_30 ( sizeof( struct V_78 ) ) ;
if ( ! V_28 )
return;
V_77 = sizeof( * V_79 ) ;
V_76 = ( char * ) V_28 -> V_63 ;
V_79 = (struct V_78 * ) V_76 ;
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
memcpy ( V_79 -> V_82 . V_83 , V_45 -> V_84 , V_85 ) ;
memcpy ( V_79 -> V_82 . V_86 , V_87 , V_85 ) ;
V_79 -> V_82 . V_88 = F_31 ( V_89 ) ;
V_79 -> V_45 . V_90 = F_32 ( V_91 ) ;
V_79 -> V_45 . V_64 = F_31 ( V_92 ) ;
V_79 -> V_45 . V_65 = V_93 ;
V_79 -> V_45 . V_68 = F_31 ( sizeof( V_79 -> V_51 ) / V_70 ) ;
V_79 -> V_51 . V_94 . V_95 . V_71 = V_96 ;
V_79 -> V_51 . V_94 . V_95 . V_69 = sizeof( V_79 -> V_51 . V_94 ) / V_70 ;
memcpy ( & V_79 -> V_51 . V_94 . V_97 , V_45 -> V_84 , V_85 ) ;
V_79 -> V_51 . V_98 . V_95 . V_71 = V_99 ;
V_79 -> V_51 . V_98 . V_95 . V_69 = sizeof( V_79 -> V_51 . V_98 ) / V_70 ;
F_33 ( V_45 -> V_26 -> V_98 , & V_79 -> V_51 . V_98 . V_100 ) ;
F_34 ( & V_75 -> V_101 . V_102 ) ;
F_35 ( V_28 , sizeof( * V_79 ) ) ;
V_28 -> V_103 = F_31 ( V_89 ) ;
F_36 ( V_28 ) ;
F_37 ( V_28 ) ;
V_45 -> V_104 ( V_45 , V_28 ) ;
V_80 = V_105 + F_38 ( V_106 ) ;
F_39 ( & V_3 -> V_23 , F_40 ( V_80 ) ) ;
}
static void F_41 ( struct V_3 * V_3 , struct V_27 * V_28 )
{
struct V_44 * V_45 = & V_3 -> V_20 ;
struct V_46 * V_47 ;
struct V_50 * V_51 ;
struct V_75 * V_75 = & V_3 -> V_75 ;
T_2 V_107 ;
T_4 V_60 ;
T_4 V_61 ;
struct V_108 * V_79 ;
T_5 V_109 ;
unsigned long V_5 ;
F_8 ( V_74 , V_3 -> V_13 -> V_14 ,
L_17 ) ;
V_47 = (struct V_46 * ) V_28 -> V_63 ;
F_8 ( V_74 , V_3 -> V_13 -> V_14 ,
L_18 ,
F_27 ( V_47 -> V_64 ) , V_47 -> V_65 ) ;
V_60 = F_27 ( V_47 -> V_68 ) * 4 ;
F_29 ( V_3 ) ;
F_3 ( & V_3 -> V_110 , V_5 ) ;
V_51 = (struct V_50 * ) ( V_47 + 1 ) ;
while ( V_60 > 0 ) {
V_61 = V_51 -> V_69 * V_70 ;
switch ( V_51 -> V_71 ) {
case V_111 :
V_107 = F_27 ( ( (struct V_112 * ) V_51 ) -> V_113 ) ;
F_28 ( V_74 , V_3 -> V_13 -> V_14 ,
L_19 , V_107 ) ;
V_79 = F_42 ( sizeof( * V_79 ) ,
V_114 ) ;
if ( ! V_79 ) {
F_4 ( & V_3 -> V_110 ,
V_5 ) ;
goto V_115;
}
memset ( V_79 , 0 , sizeof( struct V_108 ) ) ;
V_79 -> V_107 = V_107 & 0x0fff ;
V_79 -> V_32 = V_116 ;
F_43 ( & V_79 -> V_39 , & V_3 -> V_117 ) ;
break;
}
V_51 = (struct V_50 * ) ( ( char * ) V_51 + V_61 ) ;
V_60 -= V_61 ;
}
if ( F_19 ( & V_3 -> V_117 ) ) {
F_34 ( & V_75 -> V_101 . V_118 ) ;
F_8 ( V_74 , V_3 -> V_13 -> V_14 ,
L_20 ) ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
goto V_115;
}
V_79 = F_44 ( & V_3 -> V_117 , struct V_108 , V_39 ) ;
V_3 -> V_81 ( V_3 , V_79 -> V_107 ) ;
V_79 -> V_32 = V_119 ;
V_79 -> V_120 ++ ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
F_11 ( V_45 ) ;
V_109 = V_105 + F_38 ( V_121 ) ;
F_39 ( & V_3 -> V_23 , F_40 ( V_109 ) ) ;
V_115:
return;
}
static void F_24 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_108 * V_79 ;
T_5 V_109 ;
F_3 ( & V_3 -> V_110 , V_5 ) ;
V_79 = F_44 ( & V_3 -> V_117 , struct V_108 , V_39 ) ;
V_3 -> V_81 ( V_3 , V_79 -> V_107 ) ;
V_79 -> V_32 = V_119 ;
V_79 -> V_120 = 1 ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
F_11 ( & V_3 -> V_20 ) ;
V_109 = V_105 + F_38 ( V_121 ) ;
F_39 ( & V_3 -> V_23 , F_40 ( V_109 ) ) ;
}
static int F_45 ( struct V_3 * V_3 , T_2 V_122 )
{
unsigned long V_5 ;
struct V_108 * V_123 ;
F_3 ( & V_3 -> V_110 , V_5 ) ;
if ( F_19 ( & V_3 -> V_117 ) ) {
F_4 ( & V_3 -> V_110 , V_5 ) ;
return - V_124 ;
}
V_123 = F_44 ( & V_3 -> V_117 , struct V_108 , V_39 ) ;
if ( V_123 -> V_32 == V_125 ) {
F_4 ( & V_3 -> V_110 , V_5 ) ;
return 0 ;
}
if ( V_123 -> V_32 == V_119 ) {
V_123 -> V_32 = V_125 ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
return 0 ;
}
F_4 ( & V_3 -> V_110 , V_5 ) ;
return - V_124 ;
}
static void F_46 ( struct V_3 * V_3 , enum V_126 V_127 )
{
struct V_35 * V_36 ;
unsigned long V_5 ;
V_36 = F_42 ( sizeof( * V_36 ) , V_114 ) ;
if ( ! V_36 )
return;
V_36 -> V_3 = V_3 ;
V_36 -> V_41 = V_127 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
F_43 ( & V_36 -> V_39 , & V_3 -> V_38 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_47 ( & V_3 -> V_40 ) ;
}
static int F_48 ( struct V_3 * V_3 , struct V_27 * V_28 )
{
struct V_46 * V_47 ;
int V_128 = 1 ;
T_2 V_56 ;
T_3 V_58 ;
if ( ! V_28 || ! ( V_28 -> V_63 ) )
return - 1 ;
if ( F_26 ( V_28 ) )
goto V_129;
V_47 = (struct V_46 * ) V_28 -> V_63 ;
V_56 = F_27 ( V_47 -> V_64 ) ;
V_58 = V_47 -> V_65 ;
if ( F_49 ( V_47 -> V_90 ) != V_91 )
goto V_129;
if ( F_27 ( V_47 -> V_68 ) * V_70 + sizeof( * V_47 ) > V_28 -> V_62 )
goto V_129;
if ( V_56 == V_130 && V_58 == V_131 ) {
if ( F_45 ( V_3 , F_27 ( V_47 -> V_132 ) ) )
goto V_129;
V_128 = 1 ;
} else if ( V_56 == V_92 && V_58 == V_93 ) {
F_41 ( V_3 , V_28 ) ;
V_128 = 0 ;
} else if ( V_56 == V_133 && V_58 == V_134 ) {
F_46 ( V_3 , V_42 ) ;
V_128 = 1 ;
}
V_129:
return V_128 ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 , struct V_3 , V_135 ) ;
struct V_75 * V_75 = & V_3 -> V_75 ;
unsigned long V_5 ;
struct V_27 * V_28 ;
struct V_136 * V_137 ;
while ( ( V_28 = F_14 ( & V_3 -> V_138 ) ) ) {
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_15 ( V_28 ) ;
return;
}
if ( V_3 -> V_32 != V_33 &&
V_3 -> V_32 != V_34 ) {
F_16 ( & V_3 -> V_138 , V_28 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_137 = (struct V_136 * ) V_28 -> V_63 ;
if ( V_137 -> V_88 == F_31 ( V_89 ) ) {
F_51 ( V_28 , sizeof( * V_137 ) ) ;
if ( F_48 ( V_3 , V_28 ) <= 0 ) {
F_15 ( V_28 ) ;
continue;
}
if ( F_25 ( & V_3 -> V_20 , V_28 ) ) {
F_34 (
& V_75 -> V_101 . V_139 ) ;
F_28 ( V_74 , V_3 -> V_13 -> V_14 ,
L_21 ) ;
F_9 ( & V_3 -> V_20 ) ;
F_10 ( V_3 ) ;
F_15 ( V_28 ) ;
continue;
}
F_52 ( & V_3 -> V_20 , V_28 ) ;
continue;
}
}
}
static inline int F_53 ( struct V_3 * V_3 , struct V_27 * V_28 )
{
struct V_29 * V_30 ;
struct V_136 * V_137 ;
struct V_140 * V_140 ;
struct V_141 * V_142 ;
V_137 = (struct V_136 * ) V_28 -> V_63 ;
if ( V_137 -> V_88 == F_31 ( V_143 ) ) {
memmove ( ( T_3 * ) V_137 + V_144 , V_137 , V_85 * 2 ) ;
V_137 = (struct V_136 * ) F_51 ( V_28 , V_144 ) ;
F_36 ( V_28 ) ;
}
if ( V_137 -> V_88 == F_31 ( V_89 ) ) {
if ( ! ( V_3 -> V_21 . V_5 & V_22 ) ) {
F_54 ( V_145 L_22
L_23
L_24 ) ;
goto V_129;
}
if ( ( F_7 ( V_3 -> V_13 -> V_14 -> V_15 ,
V_146 | 0x80 , ( char * ) V_28 -> V_63 , V_28 -> V_62 ) ) != 0 ) {
F_54 ( V_145 L_25 ) ;
}
F_55 ( & V_3 -> V_138 , V_28 ) ;
F_56 ( V_147 , & V_3 -> V_135 ) ;
return 1 ;
}
if ( V_137 -> V_88 != F_31 ( V_148 ) )
goto V_129;
F_57 ( V_28 , sizeof( * V_137 ) ) ;
F_51 ( V_28 , sizeof( * V_137 ) ) ;
V_140 = (struct V_140 * ) V_28 -> V_63 ;
if ( F_58 ( V_140 ) != V_149 )
goto V_129;
V_30 = (struct V_29 * ) V_28 ;
F_59 ( V_30 ) ;
F_60 ( V_30 ) = V_140 -> V_150 ;
F_51 ( V_28 , sizeof( struct V_140 ) ) ;
F_61 ( V_28 ) ;
V_142 = (struct V_141 * ) ( V_28 -> V_63 + V_28 -> V_62 - sizeof( * V_142 ) ) ;
F_62 ( V_30 ) = V_142 -> V_151 ;
F_63 ( V_28 , V_28 -> V_62 - sizeof( * V_142 ) ) ;
return 0 ;
V_129:
F_64 ( V_28 ) ;
return - 1 ;
}
void F_65 ( struct V_3 * V_3 , T_3 * V_152 )
{
T_3 * V_153 = V_3 -> V_20 . V_84 ;
T_3 * V_63 = V_3 -> V_154 ;
if ( F_66 ( V_152 ) )
V_152 = V_153 ;
if ( F_67 ( V_63 , V_152 ) )
return;
F_8 ( V_19 , V_3 -> V_13 -> V_14 , L_26 , V_152 ) ;
if ( ! F_66 ( V_63 ) && ! F_67 ( V_63 , V_153 ) )
F_68 ( V_3 -> V_12 , V_63 ) ;
memcpy ( V_63 , V_152 , V_85 ) ;
if ( ! F_67 ( V_152 , V_153 ) )
F_69 ( V_3 -> V_12 , V_152 ) ;
}
void F_70 ( struct V_25 * V_13 , T_3 * V_152 )
{
struct V_3 * V_3 = F_71 ( V_13 ) ;
F_72 ( & V_3 -> V_8 ) ;
F_65 ( V_3 , V_152 ) ;
F_73 ( & V_3 -> V_8 ) ;
}
void F_74 ( struct V_25 * V_13 , T_1 V_155 , struct V_29 * V_30 )
{
struct V_3 * V_3 = F_71 ( V_13 ) ;
T_3 * V_94 ;
int V_128 ;
F_8 ( V_19 , V_13 -> V_14 , L_27 ,
V_155 , V_30 ) ;
if ( ! V_155 ) {
F_70 ( V_13 , V_3 -> V_20 . V_84 ) ;
F_75 ( V_3 ) ;
return;
}
if ( V_30 ) {
V_94 = F_76 ( V_30 ) -> V_156 ;
if ( F_66 ( V_94 ) ) {
F_77 ( & V_3 -> V_20 , V_13 , V_30 ) ;
}
F_70 ( V_13 , V_94 ) ;
}
F_72 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_32 == V_34 || V_3 -> V_32 == V_33 )
V_3 -> V_32 = V_157 ;
else {
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_28
L_29 ,
F_78 ( V_3 -> V_32 ) ) ;
F_73 ( & V_3 -> V_8 ) ;
return;
}
F_73 ( & V_3 -> V_8 ) ;
V_128 = F_79 ( V_3 , V_155 ) ;
if ( V_128 < 0 ) {
F_72 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_32 == V_157 )
V_3 -> V_32 = V_34 ;
F_73 ( & V_3 -> V_8 ) ;
}
}
static int F_80 ( struct V_158 * V_12 ,
struct V_159 * V_159 , T_3 type ,
T_2 V_160 , T_2 V_161 ,
void * V_162 )
{
struct V_3 * V_3 = F_81 ( V_12 ) ;
F_82 ( & V_3 -> V_163 [ V_160 ] , V_159 , V_161 ,
V_164 , V_165 ,
NULL ) ;
return 0 ;
}
int F_83 ( struct V_3 * V_3 , int V_166 )
{
unsigned int V_167 = 0 , V_168 ;
unsigned int V_169 ;
int V_170 ;
for ( V_169 = 0 ; V_169 < V_3 -> V_171 ; V_169 ++ ) {
V_168 = F_84 ( & V_3 -> V_172 [ V_169 ] , V_166 ,
F_80 ,
NULL ) ;
if ( V_168 ) {
V_170 = F_85 ( & V_3 -> V_163 [ V_169 ] , V_173 ) ;
if ( V_170 )
F_28 ( V_145 , V_3 -> V_13 -> V_14 ,
L_30
L_31 ) ;
}
V_167 += V_168 ;
}
return V_167 ;
}
int V_173 ( struct V_174 * V_163 )
{
struct V_3 * V_3 = F_81 ( V_163 -> V_12 ) ;
struct V_27 * V_28 ;
T_2 V_62 ;
T_6 V_175 ;
int V_176 ;
V_62 = V_177 + V_178 + V_179 ;
V_28 = F_30 ( V_62 ) ;
if ( ! V_28 ) {
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_32 ) ;
return - V_180 ;
}
F_36 ( V_28 ) ;
F_61 ( V_28 ) ;
F_37 ( V_28 ) ;
F_35 ( V_28 , V_62 ) ;
V_175 = F_86 ( V_3 -> V_181 , V_28 -> V_63 , V_62 , V_182 ) ;
if ( F_87 ( V_3 -> V_181 , V_175 ) ) {
V_176 = - V_180 ;
F_54 ( V_145 L_33 , V_176 ) ;
goto V_183;
}
F_88 ( V_163 , V_28 , V_175 , V_62 ) ;
return 0 ;
V_183:
F_89 ( V_28 ) ;
return V_176 ;
}
void F_90 ( struct V_174 * V_163 , struct V_184 * V_185 )
{
struct V_29 * V_30 = V_185 -> V_186 ;
struct V_3 * V_3 = F_81 ( V_163 -> V_12 ) ;
F_91 ( V_3 -> V_181 , V_185 -> V_187 , V_185 -> V_62 ,
V_182 ) ;
F_15 ( F_92 ( V_30 ) ) ;
V_185 -> V_186 = NULL ;
}
void F_93 ( struct V_44 * V_45 , struct V_27 * V_28 )
{
struct V_3 * V_3 = F_94 ( V_45 ) ;
struct V_188 * V_189 = & V_3 -> V_189 [ 0 ] ;
T_6 V_175 ;
struct V_136 * V_190 ;
struct V_191 * V_192 ;
unsigned long V_5 ;
int V_176 ;
if ( ! V_3 -> V_193 ) {
V_190 = (struct V_136 * ) F_95 ( V_28 ) ;
V_192 = (struct V_191 * ) F_96 ( V_28 ,
sizeof( * V_192 ) - sizeof( * V_190 ) ) ;
memcpy ( V_192 , V_190 , 2 * V_85 ) ;
V_192 -> V_194 = F_31 ( V_143 ) ;
V_192 -> V_195 = V_190 -> V_88 ;
V_192 -> V_196 = F_31 ( V_3 -> V_197 ) ;
if ( ( F_7 ( V_3 -> V_13 -> V_14 -> V_15 ,
V_198 | 0x80 , ( char * ) V_190 , V_28 -> V_62 ) ) != 0 ) {
F_54 ( V_145 L_25 ) ;
}
} else {
if ( ( F_7 ( V_3 -> V_13 -> V_14 -> V_15 ,
V_198 | 0x80 , ( char * ) V_28 -> V_63 , V_28 -> V_62 ) ) != 0 ) {
F_54 ( V_145 L_25 ) ;
}
}
V_175 = F_86 ( V_3 -> V_181 , V_28 -> V_63 , V_28 -> V_62 , V_199 ) ;
V_176 = F_87 ( V_3 -> V_181 , V_175 ) ;
if ( V_176 ) {
F_54 ( V_145 L_33 , V_176 ) ;
goto V_183;
}
F_3 ( & V_3 -> V_200 [ 0 ] , V_5 ) ;
if ( ! F_97 ( V_189 ) )
goto V_201;
F_98 ( V_189 , V_28 , V_175 , V_28 -> V_62 ,
0 ,
V_3 -> V_197 , 1 ) ;
F_4 ( & V_3 -> V_200 [ 0 ] , V_5 ) ;
return;
V_201:
F_4 ( & V_3 -> V_200 [ 0 ] , V_5 ) ;
F_91 ( V_3 -> V_181 , V_175 , V_28 -> V_62 , V_199 ) ;
V_183:
F_89 ( V_28 ) ;
}
static int F_99 ( struct V_3 * V_3 , struct V_29 * V_30 )
{
struct V_188 * V_189 = & V_3 -> V_189 [ 0 ] ;
struct V_27 * V_28 ;
T_6 V_175 ;
struct V_136 * V_190 ;
struct V_191 * V_192 ;
struct V_140 * V_140 ;
struct V_48 * V_49 ;
T_1 V_202 , V_203 ;
int V_128 = 0 ;
unsigned long V_5 ;
V_49 = F_100 ( V_30 ) ;
V_28 = F_92 ( V_30 ) ;
if ( F_101 ( V_49 -> V_204 == V_205 ) &&
F_102 ( & V_3 -> V_20 , V_3 -> V_13 , V_28 ) )
return 0 ;
if ( ! V_3 -> V_193 ) {
V_203 = sizeof( * V_192 ) + sizeof( * V_140 ) ;
V_192 = (struct V_191 * ) F_96 ( V_28 , V_203 ) ;
V_190 = (struct V_136 * ) V_192 ;
V_192 -> V_194 = F_31 ( V_143 ) ;
V_192 -> V_195 = F_31 ( V_148 ) ;
V_192 -> V_196 = F_31 ( V_3 -> V_197 ) ;
V_140 = (struct V_140 * ) ( V_192 + 1 ) ;
} else {
V_203 = sizeof( * V_190 ) + sizeof( * V_140 ) ;
V_190 = (struct V_136 * ) F_96 ( V_28 , V_203 ) ;
V_190 -> V_88 = F_31 ( V_148 ) ;
V_140 = (struct V_140 * ) ( V_190 + 1 ) ;
}
if ( V_3 -> V_20 . V_206 )
F_103 ( V_190 -> V_86 , V_49 -> V_207 ) ;
else
memcpy ( V_190 -> V_86 , V_3 -> V_20 . V_208 , V_85 ) ;
memcpy ( V_190 -> V_83 , V_3 -> V_154 , V_85 ) ;
V_202 = V_28 -> V_62 ;
F_104 ( V_202 % 4 ) ;
memset ( V_140 , 0 , sizeof( * V_140 ) ) ;
V_140 -> V_150 = F_60 ( V_30 ) ;
if ( V_149 )
F_105 ( V_140 , V_149 ) ;
V_175 = F_86 ( V_3 -> V_181 , V_190 , V_202 , V_199 ) ;
if ( F_87 ( V_3 -> V_181 , V_175 ) ) {
V_128 = - V_180 ;
F_54 ( V_145 L_34 , V_128 ) ;
goto V_209;
}
if ( ( F_7 ( V_3 -> V_13 -> V_14 -> V_15 , V_198 ,
( char * ) V_190 , V_202 ) ) != 0 ) {
F_54 ( V_145 L_25 ) ;
}
F_3 ( & V_3 -> V_200 [ 0 ] , V_5 ) ;
if ( ! F_97 ( V_189 ) ) {
F_91 ( V_3 -> V_181 , V_175 ,
V_202 , V_199 ) ;
V_128 = - 1 ;
goto V_201;
}
F_106 ( V_189 , V_28 , V_175 , V_202 , F_62 ( V_30 ) ,
0 ,
V_3 -> V_197 , 1 , 1 , 1 ) ;
V_201:
F_4 ( & V_3 -> V_200 [ 0 ] , V_5 ) ;
V_209:
if ( V_128 )
F_107 ( F_92 ( V_30 ) ) ;
return V_128 ;
}
int F_108 ( struct V_25 * V_26 , struct V_29 * V_30 )
{
struct V_3 * V_3 = F_71 ( V_26 ) ;
unsigned long V_5 ;
if ( V_3 -> V_210 ) {
F_15 ( F_92 ( V_30 ) ) ;
return - 1 ;
}
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_32 != V_33 && V_3 -> V_32 != V_34 ) {
F_55 ( & V_3 -> V_211 , F_92 ( V_30 ) ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
return 0 ;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
return F_99 ( V_3 , V_30 ) ;
}
void F_109 ( struct V_3 * V_3 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 ;
while ( ( V_28 = F_14 ( & V_3 -> V_211 ) ) ) {
V_30 = (struct V_29 * ) V_28 ;
F_99 ( V_3 , V_30 ) ;
}
}
static void F_75 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
enum V_212 V_213 ;
int V_128 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
V_214:
V_213 = V_3 -> V_32 ;
switch ( V_213 ) {
case V_33 :
case V_157 :
default:
V_3 -> V_32 = V_215 ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_128 = F_110 ( V_3 ) ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_32 != V_215 )
goto V_214;
if ( V_128 )
V_3 -> V_32 = V_213 ;
break;
case V_215 :
case V_34 :
break;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
}
static void F_111 ( struct V_188 * V_189 ,
struct V_159 * V_159 ,
struct V_216 * V_185 , void * V_162 )
{
struct V_27 * V_28 = V_185 -> V_186 ;
struct V_29 * V_30 = (struct V_29 * ) V_28 ;
struct V_3 * V_3 = F_81 ( V_189 -> V_12 ) ;
F_91 ( V_3 -> V_181 , V_185 -> V_187 ,
V_185 -> V_62 , V_199 ) ;
F_64 ( F_92 ( V_30 ) ) ;
V_185 -> V_186 = NULL ;
}
static int F_112 ( struct V_158 * V_12 ,
struct V_159 * V_159 , T_3 type ,
T_2 V_160 , T_2 V_161 ,
void * V_162 )
{
struct V_3 * V_3 = F_81 ( V_12 ) ;
unsigned long V_5 ;
F_3 ( & V_3 -> V_200 [ V_160 ] , V_5 ) ;
F_113 ( & V_3 -> V_189 [ V_160 ] , V_159 , V_161 ,
F_111 , NULL ) ;
F_4 ( & V_3 -> V_200 [ V_160 ] , V_5 ) ;
return 0 ;
}
int F_114 ( struct V_3 * V_3 , int V_217 )
{
unsigned int V_218 = 0 ;
unsigned int V_169 ;
for ( V_169 = 0 ; V_169 < V_3 -> V_219 ; V_169 ++ ) {
V_218 += F_84 ( & V_3 -> V_172 [ V_3 -> V_171 + V_169 ] ,
V_217 ,
F_112 ,
NULL ) ;
}
return V_218 ;
}
void F_115 ( struct V_188 * V_189 , struct V_216 * V_185 )
{
struct V_29 * V_30 = V_185 -> V_186 ;
struct V_3 * V_3 = F_81 ( V_189 -> V_12 ) ;
F_91 ( V_3 -> V_181 , V_185 -> V_187 ,
V_185 -> V_62 , V_199 ) ;
F_15 ( F_92 ( V_30 ) ) ;
V_185 -> V_186 = NULL ;
}
void F_29 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_108 * V_79 ;
struct V_108 * V_37 ;
F_3 ( & V_3 -> V_110 , V_5 ) ;
if ( ! F_19 ( & V_3 -> V_117 ) ) {
F_20 (vlan, next, &fnic->vlans, list) {
F_21 ( & V_79 -> V_39 ) ;
F_22 ( V_79 ) ;
}
}
F_4 ( & V_3 -> V_110 , V_5 ) ;
}
void F_116 ( struct V_3 * V_3 )
{
unsigned long V_5 ;
struct V_108 * V_79 ;
struct V_75 * V_75 = & V_3 -> V_75 ;
T_5 V_109 ;
F_3 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_9 ) {
F_4 ( & V_3 -> V_8 , V_5 ) ;
return;
}
F_4 ( & V_3 -> V_8 , V_5 ) ;
if ( V_3 -> V_20 . V_220 == V_221 )
return;
F_3 ( & V_3 -> V_110 , V_5 ) ;
if ( F_19 ( & V_3 -> V_117 ) ) {
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_35 ) ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
F_46 ( V_3 , V_42 ) ;
return;
}
V_79 = F_44 ( & V_3 -> V_117 , struct V_108 , V_39 ) ;
F_28 ( V_19 , V_3 -> V_13 -> V_14 ,
L_36 ,
V_79 -> V_107 , V_79 -> V_32 , V_79 -> V_120 ) ;
switch ( V_79 -> V_32 ) {
case V_125 :
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_37 ) ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
break;
case V_222 :
F_8 ( V_19 , V_3 -> V_13 -> V_14 ,
L_35 ) ;
F_4 ( & V_3 -> V_110 , V_5 ) ;
F_46 ( V_3 , V_42 ) ;
break;
case V_119 :
if ( V_79 -> V_120 >= V_223 ) {
F_28 ( V_74 , V_3 -> V_13 -> V_14 ,
L_38 ,
V_79 -> V_107 ) ;
F_21 ( & V_79 -> V_39 ) ;
F_22 ( V_79 ) ;
V_79 = NULL ;
if ( F_19 ( & V_3 -> V_117 ) ) {
F_4 ( & V_3 -> V_110 ,
V_5 ) ;
F_28 ( V_74 , V_3 -> V_13 -> V_14 ,
L_39
L_40 ) ;
F_46 ( V_3 , V_42 ) ;
return;
}
V_79 = F_44 ( & V_3 -> V_117 , struct V_108 ,
V_39 ) ;
V_3 -> V_81 ( V_3 , V_79 -> V_107 ) ;
V_79 -> V_32 = V_119 ;
}
F_4 ( & V_3 -> V_110 , V_5 ) ;
F_34 ( & V_75 -> V_101 . V_224 ) ;
V_79 -> V_120 ++ ;
V_109 = V_105 + F_38
( V_121 ) ;
F_39 ( & V_3 -> V_23 , F_40 ( V_109 ) ) ;
break;
}
}
