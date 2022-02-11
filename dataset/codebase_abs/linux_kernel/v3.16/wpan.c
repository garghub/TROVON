static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
int V_7 = 0 ;
if ( V_6 -> V_8 ) {
struct V_9 V_10 ;
int V_11 = 0 ;
V_10 . V_12 = V_4 -> V_12 ;
V_11 |= V_13 ;
V_10 . V_14 = V_4 -> V_15 ;
V_11 |= V_16 ;
V_7 = V_6 -> V_8 -> V_17 ( V_2 , & V_10 , V_11 ) ;
}
return V_7 ;
}
static int
F_3 ( struct V_1 * V_2 , struct V_18 * V_19 , int V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_21 * V_22 =
(struct V_21 * ) & V_19 -> V_23 ;
int V_24 = - V_25 ;
F_4 ( & V_4 -> V_26 ) ;
switch ( V_20 ) {
case V_27 :
{
T_1 V_12 , V_28 ;
V_12 = F_5 ( V_4 -> V_12 ) ;
V_28 = F_5 ( V_4 -> V_28 ) ;
if ( V_12 == V_29 ||
V_28 == V_30 ) {
V_24 = - V_31 ;
break;
}
V_22 -> V_32 = V_33 ;
V_22 -> V_34 . V_35 = V_36 ;
V_22 -> V_34 . V_12 = V_12 ;
V_22 -> V_34 . V_28 = V_28 ;
V_24 = 0 ;
break;
}
case V_37 :
F_6 ( & V_2 -> V_2 ,
L_1 ) ;
if ( V_22 -> V_32 != V_33 ||
V_22 -> V_34 . V_35 != V_36 ||
V_22 -> V_34 . V_12 == V_29 ||
V_22 -> V_34 . V_28 == V_30 ||
V_22 -> V_34 . V_28 == V_38 ) {
V_24 = - V_39 ;
break;
}
V_4 -> V_12 = F_7 ( V_22 -> V_34 . V_12 ) ;
V_4 -> V_28 = F_7 ( V_22 -> V_34 . V_28 ) ;
V_24 = F_1 ( V_2 ) ;
break;
}
F_8 ( & V_4 -> V_26 ) ;
return V_24 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_40 )
{
struct V_41 * V_34 = V_40 ;
if ( F_10 ( V_2 ) )
return - V_42 ;
memcpy ( V_2 -> V_43 , V_34 -> V_44 , V_2 -> V_45 ) ;
F_11 ( V_2 ) ;
return F_1 ( V_2 ) ;
}
int F_12 ( struct V_1 * V_2 ,
const struct V_46 * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_13 ( & V_4 -> V_47 -> V_48 ) ;
V_4 -> V_49 = * V_10 ;
F_14 ( & V_4 -> V_47 -> V_48 ) ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 ,
struct V_46 * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_13 ( & V_4 -> V_47 -> V_48 ) ;
* V_10 = V_4 -> V_49 ;
F_14 ( & V_4 -> V_47 -> V_48 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_7 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_50 * V_51 = V_4 -> V_47 -> V_51 ;
V_7 = F_17 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_13 ( & V_51 -> V_52 ) ;
if ( V_51 -> V_53 ) {
V_7 = V_51 -> V_53 ( V_51 , V_4 -> V_49 . V_54 ) ;
if ( V_7 < 0 )
goto V_55;
}
if ( V_51 -> V_56 ) {
V_7 = V_51 -> V_56 ( V_51 , V_4 -> V_49 . V_57 ) ;
if ( V_7 < 0 )
goto V_55;
}
if ( V_51 -> V_58 ) {
V_7 = V_51 -> V_58 ( V_51 , V_4 -> V_49 . V_59 ) ;
if ( V_7 < 0 )
goto V_55;
}
if ( V_51 -> V_60 ) {
V_7 = V_51 -> V_60 ( V_51 , V_4 -> V_49 . V_61 ) ;
if ( V_7 < 0 )
goto V_55;
}
if ( V_51 -> V_62 ) {
V_7 = V_51 -> V_62 ( V_51 , V_4 -> V_49 . V_63 ,
V_4 -> V_49 . V_64 ,
V_4 -> V_49 . V_65 ) ;
if ( V_7 < 0 )
goto V_55;
}
if ( V_51 -> V_66 ) {
V_7 = V_51 -> V_66 ( V_51 ,
V_4 -> V_49 . V_67 ) ;
if ( V_7 < 0 )
goto V_55;
}
F_14 ( & V_51 -> V_52 ) ;
return 0 ;
V_55:
F_14 ( & V_51 -> V_52 ) ;
return V_7 ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_68 * V_69 ,
const struct V_70 * V_71 )
{
struct V_9 V_10 ;
T_2 V_72 ;
F_19 ( & V_4 -> V_73 , & V_10 ) ;
if ( ! V_10 . V_74 && V_71 -> V_75 && V_71 -> V_76 )
return - V_39 ;
if ( ! V_10 . V_74 ||
( V_71 -> V_75 && ! V_71 -> V_76 ) ||
! V_10 . V_77 )
return 0 ;
if ( V_71 -> V_78 && ! V_71 -> V_79 )
return - V_39 ;
V_72 = V_71 -> V_78 ? V_71 -> V_79 : V_10 . V_77 ;
V_69 -> V_80 . V_81 = 1 ;
V_69 -> V_73 . V_72 = V_72 ;
V_69 -> V_73 . V_82 = V_10 . V_83 . V_84 ;
if ( V_10 . V_83 . V_84 == V_85 )
V_69 -> V_73 . V_86 = V_10 . V_83 . V_87 ;
else if ( V_10 . V_83 . V_84 == V_88 )
V_69 -> V_73 . V_89 = V_10 . V_83 . V_90 ;
V_69 -> V_73 . V_91 = V_10 . V_83 . V_92 ;
return 0 ;
}
static int F_20 ( struct V_93 * V_94 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_95 ,
const void * V_96 ,
unsigned V_97 )
{
struct V_68 V_69 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 = F_21 ( V_94 ) ;
int V_98 ;
if ( ! V_95 )
return - V_39 ;
memset ( & V_69 . V_80 , 0 , sizeof( V_69 . V_80 ) ) ;
V_69 . V_80 . type = V_71 -> type ;
V_69 . V_80 . V_81 = V_71 -> V_76 ;
V_69 . V_80 . V_99 = V_71 -> V_100 ;
V_69 . V_101 = V_5 ( V_2 ) -> F_22 ( V_2 ) ;
if ( F_18 ( V_4 , & V_69 , V_71 ) < 0 )
return - V_39 ;
if ( ! V_96 ) {
F_4 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_28 == F_7 ( V_30 ) ||
V_4 -> V_28 == F_7 ( V_38 ) ||
V_4 -> V_12 == F_7 ( V_29 ) ) {
V_69 . V_102 . V_84 = V_103 ;
V_69 . V_102 . V_15 = V_4 -> V_15 ;
} else {
V_69 . V_102 . V_84 = V_36 ;
V_69 . V_102 . V_28 = V_4 -> V_28 ;
}
V_69 . V_102 . V_12 = V_4 -> V_12 ;
F_8 ( & V_4 -> V_26 ) ;
} else {
V_69 . V_102 = * ( const struct V_104 * ) V_96 ;
}
V_69 . V_105 = * ( const struct V_104 * ) V_95 ;
V_98 = F_23 ( V_94 , & V_69 ) ;
if ( V_98 < 0 )
return - V_39 ;
F_24 ( V_94 ) ;
V_94 -> V_106 = V_98 ;
if ( V_97 > F_25 ( & V_69 ) )
return - V_107 ;
return V_98 ;
}
static int
F_26 ( const struct V_93 * V_94 , unsigned char * V_108 )
{
struct V_68 V_69 ;
struct V_104 * V_34 = (struct V_104 * ) V_108 ;
if ( F_27 ( V_94 , & V_69 ) < 0 ) {
F_28 ( L_2 ) ;
return 0 ;
}
* V_34 = V_69 . V_102 ;
return sizeof( * V_34 ) ;
}
static T_3
F_29 ( struct V_93 * V_94 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_2 V_109 , V_110 ;
int V_7 ;
V_4 = F_2 ( V_2 ) ;
F_4 ( & V_4 -> V_26 ) ;
V_109 = V_4 -> V_109 ;
V_110 = V_4 -> V_110 ;
F_8 ( & V_4 -> V_26 ) ;
if ( V_109 == V_111 ||
V_110 >= V_112 ||
V_109 >= V_113 ) {
F_30 ( V_94 ) ;
return V_114 ;
}
V_7 = F_31 ( & V_4 -> V_73 , V_94 ) ;
if ( V_7 ) {
F_32 ( L_3 , V_7 ) ;
F_30 ( V_94 ) ;
return V_114 ;
}
V_94 -> V_115 = V_2 -> V_116 ;
V_2 -> V_117 . V_118 ++ ;
V_2 -> V_117 . V_119 += V_94 -> V_97 ;
return F_33 ( V_4 -> V_47 , V_94 , V_110 , V_109 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_35 ( & V_4 -> V_73 ) ;
F_36 ( V_2 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_2 -> V_45 = V_120 ;
memset ( V_2 -> V_121 , 0xff , V_120 ) ;
V_2 -> V_122 = V_123 ;
V_2 -> V_124 = & V_125 ;
V_2 -> V_126 = 2 + 16 ;
V_2 -> V_127 = V_128 ;
V_2 -> V_129 = 300 ;
V_2 -> type = V_130 ;
V_2 -> V_131 = V_132 | V_133 ;
V_2 -> V_134 = 0 ;
V_2 -> V_135 = F_34 ;
V_2 -> V_136 = & V_137 ;
V_2 -> V_138 = & V_139 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> type = V_140 ;
V_4 -> V_109 = V_111 ;
V_4 -> V_110 = 0 ;
F_38 ( & V_4 -> V_26 ) ;
F_39 ( & V_4 -> V_141 ) ;
F_40 ( & V_4 -> V_142 , 1 ) ;
F_40 ( & V_4 -> V_143 , 1 ) ;
V_4 -> V_49 . V_63 = 3 ;
V_4 -> V_49 . V_64 = 5 ;
V_4 -> V_49 . V_65 = 4 ;
V_4 -> V_49 . V_67 = - 1 ;
V_4 -> V_12 = F_7 ( V_29 ) ;
V_4 -> V_28 = F_7 ( V_30 ) ;
F_41 ( & V_4 -> V_73 ) ;
}
static int F_42 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
return F_43 ( V_94 ) ;
}
static int
F_44 ( struct V_3 * V_144 , struct V_93 * V_94 ,
const struct V_68 * V_69 )
{
T_4 V_145 , V_146 ;
int V_7 ;
F_28 ( L_4 , V_144 -> V_2 -> V_147 ) ;
F_4 ( & V_144 -> V_26 ) ;
V_145 = V_144 -> V_12 ;
V_146 = V_144 -> V_28 ;
switch ( F_21 ( V_94 ) -> V_105 . V_84 ) {
case V_148 :
if ( F_21 ( V_94 ) -> V_105 . V_84 != V_148 )
V_94 -> V_149 = V_150 ;
else
V_94 -> V_149 = V_151 ;
break;
case V_103 :
if ( F_21 ( V_94 ) -> V_105 . V_12 != V_145 &&
F_21 ( V_94 ) -> V_105 . V_12 != F_7 ( V_29 ) )
V_94 -> V_149 = V_150 ;
else if ( F_21 ( V_94 ) -> V_105 . V_15 == V_144 -> V_15 )
V_94 -> V_149 = V_151 ;
else
V_94 -> V_149 = V_150 ;
break;
case V_36 :
if ( F_21 ( V_94 ) -> V_105 . V_12 != V_145 &&
F_21 ( V_94 ) -> V_105 . V_12 != F_7 ( V_29 ) )
V_94 -> V_149 = V_150 ;
else if ( F_21 ( V_94 ) -> V_105 . V_28 == V_146 )
V_94 -> V_149 = V_151 ;
else if ( F_21 ( V_94 ) -> V_105 . V_28 ==
F_7 ( V_30 ) )
V_94 -> V_149 = V_152 ;
else
V_94 -> V_149 = V_150 ;
break;
default:
break;
}
F_8 ( & V_144 -> V_26 ) ;
V_94 -> V_2 = V_144 -> V_2 ;
V_7 = F_45 ( & V_144 -> V_73 , V_94 ) ;
if ( V_7 ) {
F_28 ( L_5 , V_7 ) ;
F_30 ( V_94 ) ;
return V_153 ;
}
V_144 -> V_2 -> V_117 . V_154 ++ ;
V_144 -> V_2 -> V_117 . V_155 += V_94 -> V_97 ;
switch ( F_21 ( V_94 ) -> type ) {
case V_156 :
return F_42 ( V_144 -> V_2 , V_94 ) ;
default:
F_32 ( L_6 ,
F_21 ( V_94 ) -> type ) ;
F_30 ( V_94 ) ;
return V_153 ;
}
}
static void F_46 ( const char * V_147 ,
const struct V_104 * V_34 )
{
if ( V_34 -> V_84 == V_148 )
F_28 ( L_7 , V_147 ) ;
F_28 ( L_8 , V_147 , F_5 ( V_34 -> V_12 ) ) ;
if ( V_34 -> V_84 == V_36 ) {
F_28 ( L_9 , V_147 ,
F_5 ( V_34 -> V_28 ) ) ;
} else {
T_5 V_47 = F_47 ( ( V_157 T_5 ) V_34 -> V_15 ) ;
F_28 ( L_10 , V_147 , & V_47 ) ;
}
}
static int F_48 ( struct V_93 * V_94 ,
struct V_68 * V_69 )
{
int V_98 ;
struct V_70 * V_71 = F_49 ( V_94 ) ;
V_98 = F_50 ( V_94 , V_69 ) ;
if ( V_98 < 0 )
return - V_39 ;
V_94 -> V_106 = V_98 ;
F_28 ( L_11 , F_51 ( ( T_4 * ) & V_69 -> V_80 ) ,
V_69 -> V_101 ) ;
V_71 -> type = V_69 -> V_80 . type ;
V_71 -> V_100 = V_69 -> V_80 . V_99 ;
V_71 -> V_76 = V_69 -> V_80 . V_81 ;
F_46 ( L_12 , & V_69 -> V_105 ) ;
F_46 ( L_13 , & V_69 -> V_102 ) ;
V_71 -> V_102 = V_69 -> V_102 ;
V_71 -> V_105 = V_69 -> V_105 ;
if ( V_69 -> V_80 . V_81 ) {
T_5 V_158 ;
F_28 ( L_14 , V_69 -> V_73 . V_72 ) ;
switch ( V_69 -> V_73 . V_82 ) {
case V_159 :
F_28 ( L_15 ) ;
break;
case V_160 :
F_28 ( L_16 , V_69 -> V_73 . V_91 ) ;
break;
case V_85 :
F_28 ( L_17 ,
F_52 ( V_69 -> V_73 . V_86 ) >> 16 ,
F_52 ( V_69 -> V_73 . V_86 ) & 0xffff ,
V_69 -> V_73 . V_91 ) ;
break;
case V_88 :
V_158 = F_47 ( ( V_157 T_5 ) V_69 -> V_73 . V_89 ) ;
F_28 ( L_18 , & V_158 ,
V_69 -> V_73 . V_91 ) ;
break;
}
}
return 0 ;
}
void F_53 ( struct V_161 * V_4 , struct V_93 * V_94 )
{
int V_162 ;
struct V_3 * V_144 ;
struct V_68 V_69 ;
V_162 = F_48 ( V_94 , & V_69 ) ;
if ( V_162 ) {
F_28 ( L_19 ) ;
return;
}
F_54 () ;
F_55 (sdata, &priv->slaves, list) {
if ( V_144 -> type != V_140 ||
! F_10 ( V_144 -> V_2 ) )
continue;
F_44 ( V_144 , V_94 , & V_69 ) ;
V_94 = NULL ;
break;
}
F_56 () ;
if ( V_94 )
F_30 ( V_94 ) ;
}
