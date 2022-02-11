static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_4 ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
return V_6 -> V_7 ? sizeof ( struct V_8 ) :
sizeof ( struct V_9 ) ;
}
static struct V_10 * F_5 ( struct V_5 * V_6 , int V_11 )
{
return V_6 -> V_12 ? NULL : V_6 -> V_13 [ V_11 ] ;
}
static int F_6 ( struct V_5 * V_6 ,
struct V_10 * V_13 ,
struct V_14 * V_15 )
{
int V_16 = 1 ;
F_7 ( & V_6 -> V_17 ) ;
for ( V_15 -> V_18 . V_19 . V_11 = 0 ;
V_15 -> V_18 . V_19 . V_11 < V_20 ;
V_15 -> V_18 . V_19 . V_11 ++ )
if ( V_13 == F_5 ( V_6 , V_15 -> V_18 . V_19 . V_11 ) ) {
F_8 ( & V_15 -> V_21 , & V_6 -> V_22 ) ;
F_9 ( & V_6 -> V_23 ) ;
V_16 = 0 ;
break;
}
F_10 ( & V_6 -> V_17 ) ;
return V_16 ;
}
static void F_11 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
F_12 ( & V_6 -> V_24 ) ;
F_13 ( & V_15 -> V_21 ) ;
F_14 ( & V_6 -> V_24 ) ;
}
static void F_15 ( struct V_10 * V_13 ,
struct V_25 * V_26 )
{
struct V_5 * V_6 = V_13 -> V_27 ;
struct V_14 * V_15 = V_26 -> V_28 -> V_27 [ 0 ] ;
F_11 ( V_6 , V_15 ) ;
F_16 ( V_15 -> V_29 -> V_30 ) ;
F_17 ( V_15 -> V_29 ) ;
if ( V_26 -> V_31 == V_32 ) {
V_15 -> V_33 = V_34 ;
V_15 -> V_18 . V_19 . V_31 = V_35 ;
if ( ! F_6 ( V_6 , V_13 , V_15 ) )
return;
}
F_3 ( V_15 ) ;
}
static void F_18 ( struct V_10 * V_13 ,
struct V_36 * V_37 )
{
struct V_5 * V_6 = V_13 -> V_27 ;
struct V_14 * V_15 ;
if ( V_37 -> V_38 -> V_31 != V_39 )
goto V_40;
V_15 = F_19 ( sizeof *V_15 , V_41 ) ;
if ( ! V_15 )
goto V_40;
V_15 -> V_33 = V_37 -> V_42 ;
V_15 -> V_43 = V_37 ;
V_15 -> V_18 . V_19 . V_31 = 0 ;
V_15 -> V_18 . V_19 . V_33 = F_4 ( V_6 ) + V_37 -> V_42 ;
V_15 -> V_18 . V_19 . V_44 = F_20 ( V_37 -> V_38 -> V_45 ) ;
V_15 -> V_18 . V_19 . V_46 = F_21 ( V_37 -> V_38 -> V_47 ) ;
V_15 -> V_18 . V_19 . V_48 = V_37 -> V_38 -> V_48 ;
V_15 -> V_18 . V_19 . V_49 = V_37 -> V_38 -> V_50 ;
V_15 -> V_18 . V_19 . V_51 = V_37 -> V_38 -> V_51 ;
V_15 -> V_18 . V_19 . V_52 = ! ! ( V_37 -> V_38 -> V_53 & V_54 ) ;
if ( V_15 -> V_18 . V_19 . V_52 ) {
struct V_55 V_56 ;
F_22 ( V_13 -> V_57 , V_13 -> V_58 ,
V_37 -> V_38 , V_37 -> V_59 . V_60 ,
& V_56 ) ;
V_15 -> V_18 . V_19 . V_61 = V_56 . V_60 . V_62 ;
V_15 -> V_18 . V_19 . V_63 = V_56 . V_60 . V_63 ;
V_15 -> V_18 . V_19 . V_64 = V_56 . V_60 . V_64 ;
memcpy ( V_15 -> V_18 . V_19 . V_65 , & V_56 . V_60 . V_66 , 16 ) ;
V_15 -> V_18 . V_19 . V_67 = F_20 ( V_56 . V_60 . V_67 ) ;
}
if ( F_6 ( V_6 , V_13 , V_15 ) )
goto V_68;
return;
V_68:
F_3 ( V_15 ) ;
V_40:
F_23 ( V_37 ) ;
}
static T_1 F_24 ( struct V_5 * V_6 , char T_2 * V_69 ,
struct V_14 * V_15 , T_3 V_70 )
{
struct V_71 * V_59 ;
int V_72 , V_73 , V_74 , V_75 ;
V_59 = & V_15 -> V_43 -> V_59 ;
if ( ( V_15 -> V_33 <= sizeof ( * V_59 -> V_18 ) &&
V_70 < F_4 ( V_6 ) + V_15 -> V_33 ) ||
( V_15 -> V_33 > sizeof ( * V_59 -> V_18 ) &&
V_70 < F_4 ( V_6 ) + sizeof ( * V_59 -> V_18 ) ) )
return - V_76 ;
if ( F_25 ( V_69 , & V_15 -> V_18 , F_4 ( V_6 ) ) )
return - V_77 ;
V_69 += F_4 ( V_6 ) ;
V_73 = F_26 ( int , V_15 -> V_33 , sizeof ( * V_59 -> V_18 ) ) ;
if ( F_25 ( V_69 , V_59 -> V_18 , V_73 ) )
return - V_77 ;
if ( V_73 < V_15 -> V_33 ) {
if ( V_70 < F_4 ( V_6 ) + V_15 -> V_33 ) {
return - V_78 ;
}
V_74 = F_27 ( V_59 -> V_18 -> V_79 . V_80 ) ;
V_75 = sizeof ( struct V_81 ) - V_74 ;
for ( V_72 = V_15 -> V_33 - V_73 , V_69 += V_73 ;
V_72 ; V_72 -= V_73 , V_69 += V_73 ) {
V_59 = F_2 ( V_59 -> V_21 . V_82 ,
struct V_71 , V_21 ) ;
V_73 = F_28 ( V_72 , V_75 ) ;
if ( F_25 ( V_69 , ( ( void * ) V_59 -> V_18 ) + V_74 ,
V_73 ) )
return - V_77 ;
}
}
return F_4 ( V_6 ) + V_15 -> V_33 ;
}
static T_1 F_29 ( struct V_5 * V_6 , char T_2 * V_69 ,
struct V_14 * V_15 , T_3 V_70 )
{
T_1 V_83 = F_4 ( V_6 ) + V_15 -> V_33 ;
if ( V_70 < V_83 )
return - V_76 ;
if ( F_25 ( V_69 , & V_15 -> V_18 , F_4 ( V_6 ) ) )
return - V_77 ;
V_69 += F_4 ( V_6 ) ;
if ( F_25 ( V_69 , V_15 -> V_18 . V_84 , V_15 -> V_33 ) )
return - V_77 ;
return V_83 ;
}
static T_1 F_30 ( struct V_6 * V_85 , char T_2 * V_69 ,
T_3 V_70 , T_4 * V_86 )
{
struct V_5 * V_6 = V_85 -> V_87 ;
struct V_14 * V_15 ;
T_1 V_16 ;
if ( V_70 < F_4 ( V_6 ) )
return - V_76 ;
F_7 ( & V_6 -> V_17 ) ;
while ( F_31 ( & V_6 -> V_22 ) ) {
F_10 ( & V_6 -> V_17 ) ;
if ( V_85 -> V_88 & V_89 )
return - V_90 ;
if ( F_32 ( V_6 -> V_23 ,
! F_31 ( & V_6 -> V_22 ) ) )
return - V_91 ;
F_7 ( & V_6 -> V_17 ) ;
}
V_15 = F_33 ( V_6 -> V_22 . V_82 , struct V_14 , V_21 ) ;
F_13 ( & V_15 -> V_21 ) ;
F_10 ( & V_6 -> V_17 ) ;
if ( V_15 -> V_43 )
V_16 = F_24 ( V_6 , V_69 , V_15 , V_70 ) ;
else
V_16 = F_29 ( V_6 , V_69 , V_15 , V_70 ) ;
if ( V_16 < 0 ) {
F_7 ( & V_6 -> V_17 ) ;
F_34 ( & V_15 -> V_21 , & V_6 -> V_22 ) ;
F_10 ( & V_6 -> V_17 ) ;
} else {
if ( V_15 -> V_43 )
F_23 ( V_15 -> V_43 ) ;
F_3 ( V_15 ) ;
}
return V_16 ;
}
static int F_35 ( struct V_92 * V_29 , const char T_2 * V_69 )
{
int V_72 , V_93 ;
if ( ( V_29 -> V_94 > V_95 ) &&
F_36 ( V_29 -> V_18 + V_95 , V_69 + V_95 ,
V_29 -> V_94 - V_95 ) )
return - V_77 ;
for ( V_93 = 1 , V_72 = V_29 -> V_96 , V_69 += V_29 -> V_94 ; V_72 > 0 ;
V_93 ++ , V_72 -= V_29 -> V_97 , V_69 += V_29 -> V_97 ) {
if ( F_36 ( F_37 ( V_29 , V_93 ) , V_69 ,
F_28 ( V_72 , V_29 -> V_97 ) ) )
return - V_77 ;
}
return 0 ;
}
static int F_38 ( struct V_8 * V_98 ,
struct V_8 * V_99 )
{
if ( ! V_98 -> V_52 && ! V_99 -> V_52 )
return ( V_98 -> V_46 == V_99 -> V_46 ) ;
if ( V_98 -> V_52 && V_99 -> V_52 )
return ! memcmp ( V_98 -> V_65 , V_99 -> V_65 , 16 ) ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_14 * V_100 ;
struct V_101 * V_102 , * V_19 ;
V_19 = (struct V_101 * ) V_15 -> V_18 . V_84 ;
F_40 (sent_packet, &file->send_list, list) {
V_102 = (struct V_101 * ) V_100 -> V_18 . V_84 ;
if ( ( V_19 -> V_103 != V_102 -> V_103 ) ||
( V_19 -> V_80 != V_102 -> V_80 ) )
continue;
if ( ! F_41 ( (struct V_81 * ) V_19 ) ) {
if ( ! F_41 ( (struct V_81 * ) V_102 ) )
return 1 ;
continue;
} else if ( ! F_41 ( (struct V_81 * ) V_102 ) )
continue;
if ( F_38 ( & V_15 -> V_18 . V_19 , & V_100 -> V_18 . V_19 ) )
return 1 ;
}
return 0 ;
}
static T_1 F_42 ( struct V_6 * V_85 , const char T_2 * V_69 ,
T_3 V_70 , T_4 * V_86 )
{
struct V_5 * V_6 = V_85 -> V_87 ;
struct V_14 * V_15 ;
struct V_10 * V_13 ;
struct V_55 V_56 ;
struct V_104 * V_30 ;
struct V_105 * V_106 ;
T_5 * V_103 ;
int V_16 , V_96 , V_94 , V_107 , V_108 ;
if ( V_70 < F_4 ( V_6 ) + V_95 )
return - V_76 ;
V_15 = F_19 ( sizeof *V_15 + V_95 , V_41 ) ;
if ( ! V_15 )
return - V_109 ;
if ( F_36 ( & V_15 -> V_18 , V_69 , F_4 ( V_6 ) ) ) {
V_16 = - V_77 ;
goto V_110;
}
if ( V_15 -> V_18 . V_19 . V_11 < 0 ||
V_15 -> V_18 . V_19 . V_11 >= V_20 ) {
V_16 = - V_76 ;
goto V_110;
}
V_69 += F_4 ( V_6 ) ;
if ( F_36 ( V_15 -> V_18 . V_84 , V_69 , V_95 ) ) {
V_16 = - V_77 ;
goto V_110;
}
F_7 ( & V_6 -> V_17 ) ;
V_13 = F_5 ( V_6 , V_15 -> V_18 . V_19 . V_11 ) ;
if ( ! V_13 ) {
V_16 = - V_76 ;
goto V_111;
}
memset ( & V_56 , 0 , sizeof V_56 ) ;
V_56 . V_112 = F_43 ( V_15 -> V_18 . V_19 . V_46 ) ;
V_56 . V_48 = V_15 -> V_18 . V_19 . V_48 ;
V_56 . V_113 = V_15 -> V_18 . V_19 . V_49 ;
V_56 . V_58 = V_6 -> V_114 -> V_58 ;
if ( V_15 -> V_18 . V_19 . V_52 ) {
V_56 . V_115 = V_116 ;
memcpy ( V_56 . V_60 . V_66 . V_117 , V_15 -> V_18 . V_19 . V_65 , 16 ) ;
V_56 . V_60 . V_62 = V_15 -> V_18 . V_19 . V_61 ;
V_56 . V_60 . V_67 = F_44 ( V_15 -> V_18 . V_19 . V_67 ) ;
V_56 . V_60 . V_63 = V_15 -> V_18 . V_19 . V_63 ;
V_56 . V_60 . V_64 = V_15 -> V_18 . V_19 . V_64 ;
}
V_30 = F_45 ( V_13 -> V_118 -> V_119 , & V_56 ) ;
if ( F_46 ( V_30 ) ) {
V_16 = F_47 ( V_30 ) ;
goto V_111;
}
V_106 = (struct V_105 * ) V_15 -> V_18 . V_84 ;
V_94 = F_27 ( V_106 -> V_79 . V_80 ) ;
if ( ! F_48 ( V_106 -> V_79 . V_80 ) ) {
V_107 = V_34 ;
V_108 = 0 ;
} else {
V_107 = V_95 ;
V_108 = F_49 ( & V_106 -> V_120 ) &
V_121 ;
}
V_96 = V_70 - F_4 ( V_6 ) - V_94 ;
V_15 -> V_29 = F_50 ( V_13 ,
F_44 ( V_15 -> V_18 . V_19 . V_44 ) ,
V_15 -> V_18 . V_19 . V_51 , V_108 ,
V_94 , V_96 , V_41 ) ;
if ( F_46 ( V_15 -> V_29 ) ) {
V_16 = F_47 ( V_15 -> V_29 ) ;
goto V_122;
}
V_15 -> V_29 -> V_30 = V_30 ;
V_15 -> V_29 -> V_123 = V_15 -> V_18 . V_19 . V_123 ;
V_15 -> V_29 -> V_124 = V_15 -> V_18 . V_19 . V_124 ;
V_15 -> V_29 -> V_27 [ 0 ] = V_15 ;
memcpy ( V_15 -> V_29 -> V_18 , V_15 -> V_18 . V_84 , V_34 ) ;
if ( ! V_108 ) {
if ( F_36 ( V_15 -> V_29 -> V_18 + V_107 ,
V_69 + V_107 ,
V_94 + V_96 - V_107 ) ) {
V_16 = - V_77 ;
goto V_125;
}
} else {
V_16 = F_35 ( V_15 -> V_29 , V_69 ) ;
if ( V_16 )
goto V_125;
}
if ( ! F_41 ( V_15 -> V_29 -> V_18 ) ) {
V_103 = & ( (struct V_101 * ) V_15 -> V_29 -> V_18 ) -> V_103 ;
* V_103 = F_51 ( ( ( V_126 ) V_13 -> V_127 ) << 32 |
( F_52 ( V_103 ) & 0xffffffff ) ) ;
V_106 -> V_79 . V_103 = * V_103 ;
}
F_12 ( & V_6 -> V_24 ) ;
V_16 = F_39 ( V_6 , V_15 ) ;
if ( ! V_16 )
F_8 ( & V_15 -> V_21 , & V_6 -> V_128 ) ;
F_14 ( & V_6 -> V_24 ) ;
if ( V_16 ) {
V_16 = - V_76 ;
goto V_125;
}
V_16 = F_53 ( V_15 -> V_29 , NULL ) ;
if ( V_16 )
goto V_129;
F_10 ( & V_6 -> V_17 ) ;
return V_70 ;
V_129:
F_11 ( V_6 , V_15 ) ;
V_125:
F_17 ( V_15 -> V_29 ) ;
V_122:
F_16 ( V_30 ) ;
V_111:
F_10 ( & V_6 -> V_17 ) ;
V_110:
F_3 ( V_15 ) ;
return V_16 ;
}
static unsigned int F_54 ( struct V_6 * V_85 , struct V_130 * V_131 )
{
struct V_5 * V_6 = V_85 -> V_87 ;
unsigned int V_132 = V_133 | V_134 ;
F_55 ( V_85 , & V_6 -> V_23 , V_131 ) ;
if ( ! F_31 ( & V_6 -> V_22 ) )
V_132 |= V_135 | V_136 ;
return V_132 ;
}
static int F_56 ( struct V_5 * V_6 , void T_2 * V_137 ,
int V_138 )
{
struct V_139 V_140 ;
struct V_141 V_142 ;
struct V_10 * V_13 = NULL ;
int V_143 ;
int V_16 ;
F_7 ( & V_6 -> V_114 -> V_144 ) ;
F_7 ( & V_6 -> V_17 ) ;
if ( ! V_6 -> V_114 -> V_145 ) {
V_16 = - V_146 ;
goto V_147;
}
if ( F_36 ( & V_140 , V_137 , sizeof V_140 ) ) {
V_16 = - V_77 ;
goto V_147;
}
if ( V_140 . V_44 != 0 && V_140 . V_44 != 1 ) {
V_16 = - V_76 ;
goto V_147;
}
for ( V_143 = 0 ; V_143 < V_20 ; ++ V_143 )
if ( ! F_5 ( V_6 , V_143 ) )
goto V_148;
V_16 = - V_109 ;
goto V_147;
V_148:
if ( V_140 . V_80 ) {
V_142 . V_80 = V_140 . V_80 ;
V_142 . V_149 = V_140 . V_149 ;
memcpy ( V_142 . V_150 , V_140 . V_150 , sizeof V_142 . V_150 ) ;
if ( V_138 ) {
T_6 * V_151 = ( T_6 * ) V_140 . V_152 ;
int V_153 ;
for ( V_153 = 0 ; V_153 < F_57 ( V_154 ) ; ++ V_153 )
V_142 . V_152 [ V_153 ] =
V_151 [ V_153 * 2 ] | ( ( V_126 ) V_151 [ V_153 * 2 + 1 ] << 32 ) ;
} else
memcpy ( V_142 . V_152 , V_140 . V_152 ,
sizeof V_142 . V_152 ) ;
}
V_13 = F_58 ( V_6 -> V_114 -> V_145 , V_6 -> V_114 -> V_58 ,
V_140 . V_44 ? V_155 : V_156 ,
V_140 . V_80 ? & V_142 : NULL ,
V_140 . V_157 ,
F_15 , F_18 , V_6 ) ;
if ( F_46 ( V_13 ) ) {
V_16 = F_47 ( V_13 ) ;
V_13 = NULL ;
goto V_147;
}
if ( F_59 ( V_143 ,
( T_6 T_2 * ) ( V_137 + F_60 ( struct V_139 , V_11 ) ) ) ) {
V_16 = - V_77 ;
goto V_147;
}
if ( ! V_6 -> V_158 ) {
V_6 -> V_158 = 1 ;
if ( ! V_6 -> V_7 ) {
F_61 ( V_159 L_1
L_2 , V_160 -> V_161 ) ;
F_61 ( V_159 L_3
L_4 ) ;
}
}
V_6 -> V_13 [ V_143 ] = V_13 ;
V_16 = 0 ;
V_147:
F_10 ( & V_6 -> V_17 ) ;
if ( V_16 && V_13 )
F_62 ( V_13 ) ;
F_10 ( & V_6 -> V_114 -> V_144 ) ;
return V_16 ;
}
static int F_63 ( struct V_5 * V_6 , T_6 T_2 * V_137 )
{
struct V_10 * V_13 = NULL ;
T_6 V_11 ;
int V_16 = 0 ;
if ( F_64 ( V_11 , V_137 ) )
return - V_77 ;
F_7 ( & V_6 -> V_114 -> V_144 ) ;
F_7 ( & V_6 -> V_17 ) ;
if ( V_11 < 0 || V_11 >= V_20 || ! F_5 ( V_6 , V_11 ) ) {
V_16 = - V_76 ;
goto V_147;
}
V_13 = V_6 -> V_13 [ V_11 ] ;
V_6 -> V_13 [ V_11 ] = NULL ;
V_147:
F_10 ( & V_6 -> V_17 ) ;
if ( V_13 )
F_62 ( V_13 ) ;
F_10 ( & V_6 -> V_114 -> V_144 ) ;
return V_16 ;
}
static long F_65 ( struct V_5 * V_6 )
{
int V_16 = 0 ;
F_7 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_158 )
V_16 = - V_76 ;
else
V_6 -> V_7 = 1 ;
F_10 ( & V_6 -> V_17 ) ;
return V_16 ;
}
static long F_66 ( struct V_6 * V_85 , unsigned int V_162 ,
unsigned long V_137 )
{
switch ( V_162 ) {
case V_163 :
return F_56 ( V_85 -> V_87 , ( void T_2 * ) V_137 , 0 ) ;
case V_164 :
return F_63 ( V_85 -> V_87 , ( V_165 T_2 * ) V_137 ) ;
case V_166 :
return F_65 ( V_85 -> V_87 ) ;
default:
return - V_167 ;
}
}
static long F_67 ( struct V_6 * V_85 , unsigned int V_162 ,
unsigned long V_137 )
{
switch ( V_162 ) {
case V_163 :
return F_56 ( V_85 -> V_87 , F_68 ( V_137 ) , 1 ) ;
case V_164 :
return F_63 ( V_85 -> V_87 , F_68 ( V_137 ) ) ;
case V_166 :
return F_65 ( V_85 -> V_87 ) ;
default:
return - V_167 ;
}
}
static int F_69 ( struct V_168 * V_168 , struct V_6 * V_85 )
{
struct V_169 * V_114 ;
struct V_5 * V_6 ;
int V_16 ;
V_114 = F_2 ( V_168 -> V_170 , struct V_169 , V_171 ) ;
if ( V_114 )
F_70 ( & V_114 -> V_172 -> V_2 ) ;
else
return - V_173 ;
F_7 ( & V_114 -> V_144 ) ;
if ( ! V_114 -> V_145 ) {
V_16 = - V_173 ;
goto V_147;
}
V_6 = F_19 ( sizeof *V_6 , V_41 ) ;
if ( ! V_6 ) {
F_71 ( & V_114 -> V_172 -> V_2 , F_1 ) ;
V_16 = - V_109 ;
goto V_147;
}
F_72 ( & V_6 -> V_17 ) ;
F_73 ( & V_6 -> V_24 ) ;
F_74 ( & V_6 -> V_22 ) ;
F_74 ( & V_6 -> V_128 ) ;
F_75 ( & V_6 -> V_23 ) ;
V_6 -> V_114 = V_114 ;
V_85 -> V_87 = V_6 ;
F_8 ( & V_6 -> V_174 , & V_114 -> V_175 ) ;
V_16 = F_76 ( V_168 , V_85 ) ;
V_147:
F_10 ( & V_114 -> V_144 ) ;
return V_16 ;
}
static int F_77 ( struct V_168 * V_168 , struct V_6 * V_85 )
{
struct V_5 * V_6 = V_85 -> V_87 ;
struct V_3 * V_4 = V_6 -> V_114 -> V_172 ;
struct V_14 * V_15 , * V_176 ;
int V_177 ;
int V_153 ;
F_7 ( & V_6 -> V_114 -> V_144 ) ;
F_7 ( & V_6 -> V_17 ) ;
V_177 = V_6 -> V_12 ;
V_6 -> V_12 = 1 ;
F_78 (packet, tmp, &file->recv_list, list) {
if ( V_15 -> V_43 )
F_23 ( V_15 -> V_43 ) ;
F_3 ( V_15 ) ;
}
F_13 ( & V_6 -> V_174 ) ;
F_10 ( & V_6 -> V_17 ) ;
if ( ! V_177 )
for ( V_153 = 0 ; V_153 < V_20 ; ++ V_153 )
if ( V_6 -> V_13 [ V_153 ] )
F_62 ( V_6 -> V_13 [ V_153 ] ) ;
F_10 ( & V_6 -> V_114 -> V_144 ) ;
F_3 ( V_6 ) ;
F_71 ( & V_4 -> V_2 , F_1 ) ;
return 0 ;
}
static int F_79 ( struct V_168 * V_168 , struct V_6 * V_85 )
{
struct V_169 * V_114 ;
struct V_178 V_179 = {
. V_180 = V_181
} ;
int V_16 ;
V_114 = F_2 ( V_168 -> V_170 , struct V_169 , V_182 ) ;
if ( V_114 )
F_70 ( & V_114 -> V_172 -> V_2 ) ;
else
return - V_173 ;
if ( V_85 -> V_88 & V_89 ) {
if ( F_80 ( & V_114 -> V_183 ) ) {
V_16 = - V_90 ;
goto V_184;
}
} else {
if ( F_81 ( & V_114 -> V_183 ) ) {
V_16 = - V_91 ;
goto V_184;
}
}
V_16 = F_82 ( V_114 -> V_145 , V_114 -> V_58 , 0 , & V_179 ) ;
if ( V_16 ) {
F_83 ( & V_114 -> V_183 ) ;
goto V_184;
}
V_85 -> V_87 = V_114 ;
return F_76 ( V_168 , V_85 ) ;
V_184:
F_71 ( & V_114 -> V_172 -> V_2 , F_1 ) ;
return V_16 ;
}
static int F_84 ( struct V_168 * V_168 , struct V_6 * V_85 )
{
struct V_169 * V_114 = V_85 -> V_87 ;
struct V_178 V_179 = {
. V_185 = V_181
} ;
int V_16 = 0 ;
F_7 ( & V_114 -> V_144 ) ;
if ( V_114 -> V_145 )
V_16 = F_82 ( V_114 -> V_145 , V_114 -> V_58 , 0 , & V_179 ) ;
F_10 ( & V_114 -> V_144 ) ;
F_83 ( & V_114 -> V_183 ) ;
F_71 ( & V_114 -> V_172 -> V_2 , F_1 ) ;
return V_16 ;
}
static T_1 F_85 ( struct V_57 * V_4 , struct V_186 * V_187 ,
char * V_69 )
{
struct V_169 * V_114 = F_86 ( V_4 ) ;
if ( ! V_114 )
return - V_188 ;
return sprintf ( V_69 , L_5 , V_114 -> V_145 -> V_189 ) ;
}
static T_1 F_87 ( struct V_57 * V_4 , struct V_186 * V_187 ,
char * V_69 )
{
struct V_169 * V_114 = F_86 ( V_4 ) ;
if ( ! V_114 )
return - V_188 ;
return sprintf ( V_69 , L_6 , V_114 -> V_58 ) ;
}
static int F_88 ( void )
{
int V_16 ;
if ( ! V_190 ) {
V_16 = F_89 ( & V_190 , 0 , V_191 * 2 ,
L_7 ) ;
if ( V_16 ) {
F_61 ( V_192 L_8 ) ;
return V_16 ;
}
}
V_16 = F_90 ( V_193 , V_191 ) ;
if ( V_16 >= V_191 )
return - 1 ;
return V_16 ;
}
static int F_91 ( struct V_194 * V_57 , int V_58 ,
struct V_169 * V_114 )
{
int V_195 ;
T_7 V_196 ;
F_92 ( & V_197 ) ;
V_195 = F_90 ( V_198 , V_191 ) ;
if ( V_195 >= V_191 ) {
F_93 ( & V_197 ) ;
V_195 = F_88 () ;
if ( V_195 < 0 )
return - 1 ;
F_92 ( & V_197 ) ;
V_114 -> V_199 = V_195 + V_191 ;
V_196 = V_195 + V_190 ;
F_94 ( V_195 , V_193 ) ;
} else {
V_114 -> V_199 = V_195 ;
V_196 = V_195 + V_200 ;
F_94 ( V_195 , V_198 ) ;
}
F_93 ( & V_197 ) ;
V_114 -> V_145 = V_57 ;
V_114 -> V_58 = V_58 ;
F_95 ( & V_114 -> V_183 , 1 ) ;
F_72 ( & V_114 -> V_144 ) ;
F_74 ( & V_114 -> V_175 ) ;
F_96 ( & V_114 -> V_171 , & V_201 ) ;
V_114 -> V_171 . V_202 = V_203 ;
F_97 ( & V_114 -> V_171 . V_204 , L_9 , V_114 -> V_199 ) ;
if ( F_98 ( & V_114 -> V_171 , V_196 , 1 ) )
goto V_205;
V_114 -> V_4 = F_99 ( V_206 , V_57 -> V_207 ,
V_114 -> V_171 . V_4 , V_114 ,
L_9 , V_114 -> V_199 ) ;
if ( F_46 ( V_114 -> V_4 ) )
goto V_205;
if ( F_100 ( V_114 -> V_4 , & V_208 ) )
goto V_209;
if ( F_100 ( V_114 -> V_4 , & V_210 ) )
goto V_209;
V_196 += V_191 ;
F_96 ( & V_114 -> V_182 , & V_211 ) ;
V_114 -> V_182 . V_202 = V_203 ;
F_97 ( & V_114 -> V_182 . V_204 , L_10 , V_114 -> V_199 ) ;
if ( F_98 ( & V_114 -> V_182 , V_196 , 1 ) )
goto V_212;
V_114 -> V_213 = F_99 ( V_206 , V_57 -> V_207 ,
V_114 -> V_182 . V_4 , V_114 ,
L_10 , V_114 -> V_199 ) ;
if ( F_46 ( V_114 -> V_213 ) )
goto V_212;
if ( F_100 ( V_114 -> V_213 , & V_208 ) )
goto V_214;
if ( F_100 ( V_114 -> V_213 , & V_210 ) )
goto V_214;
return 0 ;
V_214:
F_101 ( V_206 , V_114 -> V_182 . V_4 ) ;
V_212:
F_102 ( & V_114 -> V_182 ) ;
V_209:
F_101 ( V_206 , V_114 -> V_171 . V_4 ) ;
V_205:
F_102 ( & V_114 -> V_171 ) ;
if ( V_114 -> V_199 < V_191 )
F_103 ( V_195 , V_198 ) ;
else
F_103 ( V_195 , V_193 ) ;
return - 1 ;
}
static void F_104 ( struct V_169 * V_114 )
{
struct V_5 * V_6 ;
int V_11 ;
F_105 ( V_114 -> V_4 , NULL ) ;
F_105 ( V_114 -> V_213 , NULL ) ;
F_101 ( V_206 , V_114 -> V_171 . V_4 ) ;
F_101 ( V_206 , V_114 -> V_182 . V_4 ) ;
F_102 ( & V_114 -> V_171 ) ;
F_102 ( & V_114 -> V_182 ) ;
F_7 ( & V_114 -> V_144 ) ;
V_114 -> V_145 = NULL ;
F_40 (file, &port->file_list, port_list) {
F_7 ( & V_6 -> V_17 ) ;
V_6 -> V_12 = 1 ;
F_10 ( & V_6 -> V_17 ) ;
for ( V_11 = 0 ; V_11 < V_20 ; ++ V_11 )
if ( V_6 -> V_13 [ V_11 ] )
F_62 ( V_6 -> V_13 [ V_11 ] ) ;
}
F_10 ( & V_114 -> V_144 ) ;
if ( V_114 -> V_199 < V_191 )
F_103 ( V_114 -> V_199 , V_198 ) ;
else
F_103 ( V_114 -> V_199 - V_191 , V_193 ) ;
}
static void F_106 ( struct V_194 * V_57 )
{
struct V_3 * V_172 ;
int V_215 , V_216 , V_153 ;
if ( F_107 ( V_57 -> V_217 ) != V_218 )
return;
if ( V_57 -> V_217 == V_219 )
V_215 = V_216 = 0 ;
else {
V_215 = 1 ;
V_216 = V_57 -> V_220 ;
}
V_172 = F_19 ( sizeof *V_172 +
( V_216 - V_215 + 1 ) * sizeof ( struct V_169 ) ,
V_41 ) ;
if ( ! V_172 )
return;
F_108 ( & V_172 -> V_2 ) ;
V_172 -> V_221 = V_215 ;
V_172 -> V_222 = V_216 ;
for ( V_153 = V_215 ; V_153 <= V_216 ; ++ V_153 ) {
V_172 -> V_114 [ V_153 - V_215 ] . V_172 = V_172 ;
if ( F_91 ( V_57 , V_153 , & V_172 -> V_114 [ V_153 - V_215 ] ) )
goto V_110;
}
F_109 ( V_57 , & V_223 , V_172 ) ;
return;
V_110:
while ( -- V_153 >= V_215 )
F_104 ( & V_172 -> V_114 [ V_153 - V_215 ] ) ;
F_71 ( & V_172 -> V_2 , F_1 ) ;
}
static void F_110 ( struct V_194 * V_57 )
{
struct V_3 * V_172 = F_111 ( V_57 , & V_223 ) ;
int V_153 ;
if ( ! V_172 )
return;
for ( V_153 = 0 ; V_153 <= V_172 -> V_222 - V_172 -> V_221 ; ++ V_153 )
F_104 ( & V_172 -> V_114 [ V_153 ] ) ;
F_71 ( & V_172 -> V_2 , F_1 ) ;
}
static char * F_112 ( struct V_57 * V_4 , T_8 * V_224 )
{
return F_113 ( V_41 , L_11 , F_114 ( V_4 ) ) ;
}
static int T_9 F_115 ( void )
{
int V_16 ;
V_16 = F_116 ( V_200 , V_191 * 2 ,
L_7 ) ;
if ( V_16 ) {
F_61 ( V_192 L_12 ) ;
goto V_147;
}
V_206 = F_117 ( V_203 , L_7 ) ;
if ( F_46 ( V_206 ) ) {
V_16 = F_47 ( V_206 ) ;
F_61 ( V_192 L_13 ) ;
goto V_225;
}
V_206 -> V_226 = F_112 ;
V_16 = F_118 ( V_206 , & V_227 . V_187 ) ;
if ( V_16 ) {
F_61 ( V_192 L_14 ) ;
goto V_228;
}
V_16 = F_119 ( & V_223 ) ;
if ( V_16 ) {
F_61 ( V_192 L_15 ) ;
goto V_228;
}
return 0 ;
V_228:
F_120 ( V_206 ) ;
V_225:
F_121 ( V_200 , V_191 * 2 ) ;
V_147:
return V_16 ;
}
static void T_10 F_122 ( void )
{
F_123 ( & V_223 ) ;
F_120 ( V_206 ) ;
F_121 ( V_200 , V_191 * 2 ) ;
if ( V_190 )
F_121 ( V_190 , V_191 * 2 ) ;
}
