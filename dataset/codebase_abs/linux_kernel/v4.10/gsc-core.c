const struct V_1 * F_1 ( int V_2 )
{
if ( V_2 >= F_2 ( V_3 ) )
return NULL ;
return (struct V_1 * ) & V_3 [ V_2 ] ;
}
const struct V_1 * F_3 ( T_1 * V_4 , T_1 * V_5 , T_1 V_2 )
{
const struct V_1 * V_6 , * V_7 = NULL ;
unsigned int V_8 ;
if ( V_2 >= F_2 ( V_3 ) )
return NULL ;
for ( V_8 = 0 ; V_8 < F_2 ( V_3 ) ; ++ V_8 ) {
V_6 = F_1 ( V_8 ) ;
if ( V_4 && V_6 -> V_4 == * V_4 )
return V_6 ;
if ( V_5 && V_6 -> V_5 == * V_5 )
return V_6 ;
if ( V_2 == V_8 )
V_7 = V_6 ;
}
return V_7 ;
}
void F_4 ( struct V_9 * V_10 , int V_11 , int V_12 )
{
V_10 -> V_13 = V_11 ;
V_10 -> V_14 = V_12 ;
V_10 -> V_15 . V_11 = V_11 ;
V_10 -> V_15 . V_12 = V_12 ;
V_10 -> V_15 . V_16 = 0 ;
V_10 -> V_15 . V_17 = 0 ;
}
int F_5 ( struct V_18 * V_19 , T_1 V_20 , T_1 V_21 ,
T_1 * V_22 )
{
if ( ( V_21 > V_20 ) || ( V_21 >= V_20 / V_19 -> V_23 ) ) {
* V_22 = 1 ;
return 0 ;
}
if ( ( V_20 / V_19 -> V_23 / V_19 -> V_24 ) > V_21 ) {
F_6 ( L_1 ) ;
return - V_25 ;
}
* V_22 = ( V_21 > ( V_20 / 8 ) ) ? 2 : 4 ;
return 0 ;
}
void F_7 ( T_1 V_26 , T_1 V_27 , T_1 * V_28 )
{
if ( V_26 == 4 && V_27 == 4 )
* V_28 = 4 ;
else if ( ( V_26 == 4 && V_27 == 2 ) ||
( V_26 == 2 && V_27 == 4 ) )
* V_28 = 3 ;
else if ( ( V_26 == 4 && V_27 == 1 ) ||
( V_26 == 1 && V_27 == 4 ) ||
( V_26 == 2 && V_27 == 2 ) )
* V_28 = 2 ;
else if ( V_26 == 1 && V_27 == 1 )
* V_28 = 0 ;
else
* V_28 = 1 ;
}
void F_8 ( struct V_18 * V_19 ,
struct V_9 * V_29 , T_1 * V_30 ,
T_1 V_31 , T_1 V_32 , T_1 * V_26 )
{
int V_33 = 0 , V_34 , V_35 ;
if ( F_9 ( V_29 -> V_6 -> V_36 ) ) {
V_34 = V_37 ;
V_35 = V_37 ;
} else if ( F_10 ( V_29 -> V_6 -> V_36 ) ) {
V_34 = V_37 ;
V_35 = V_38 ;
} else {
V_34 = V_38 ;
V_35 = V_38 ;
}
V_33 = V_29 -> V_15 . V_11 % ( * V_30 * V_34 ) ;
if ( V_33 ) {
V_29 -> V_15 . V_11 -= V_33 ;
F_5 ( V_19 , V_29 -> V_15 . V_11 , V_31 , V_30 ) ;
F_11 ( L_2 ,
V_29 -> V_15 . V_11 + V_33 , V_29 -> V_15 . V_11 ) ;
}
V_33 = V_29 -> V_15 . V_12 % ( * V_26 * V_35 ) ;
if ( V_33 ) {
V_29 -> V_15 . V_12 -= V_33 ;
F_5 ( V_19 , V_29 -> V_15 . V_12 , V_32 , V_26 ) ;
F_11 ( L_3 ,
V_29 -> V_15 . V_12 + V_33 , V_29 -> V_15 . V_12 ) ;
}
}
int F_12 ( struct V_39 * V_40 )
{
const struct V_1 * V_6 ;
V_6 = F_3 ( NULL , NULL , V_40 -> V_2 ) ;
if ( ! V_6 )
return - V_25 ;
F_13 ( V_40 -> V_41 , V_6 -> V_42 , sizeof( V_40 -> V_41 ) ) ;
V_40 -> V_4 = V_6 -> V_4 ;
return 0 ;
}
static int F_14 ( struct V_9 * V_43 , T_1 V_44 , T_1 * V_2 , T_1 * V_45 )
{
if ( V_43 -> V_44 . V_46 == V_44 ) {
* V_2 = 0 ;
* V_45 = V_43 -> V_44 . V_46 ;
} else if ( V_43 -> V_44 . V_47 == V_44 ) {
* V_2 = 1 ;
* V_45 = V_43 -> V_44 . V_47 ;
} else if ( V_43 -> V_44 . V_48 == V_44 ) {
* V_2 = 2 ;
* V_45 = V_43 -> V_44 . V_48 ;
} else {
F_6 ( L_4 ) ;
return - V_25 ;
}
return 0 ;
}
void F_15 ( struct V_49 * V_50 , struct V_9 * V_43 )
{
T_1 V_51 , V_52 , V_53 , V_54 ;
V_51 = V_52 = V_53 = V_54 = 0 ;
V_51 = V_43 -> V_44 . V_46 ;
V_52 = V_43 -> V_55 [ 0 ] ;
if ( V_43 -> V_6 -> V_56 == 2 ) {
V_53 = V_43 -> V_44 . V_47 ;
V_54 = V_43 -> V_55 [ 1 ] ;
} else if ( V_43 -> V_6 -> V_56 == 3 ) {
T_1 V_57 , V_58 , V_59 , V_60 ;
T_1 V_61 , V_62 ;
T_1 V_63 , V_64 ;
V_63 = F_16 ( V_43 -> V_44 . V_46 , V_43 -> V_44 . V_47 , V_43 -> V_44 . V_48 ) ;
if ( F_14 ( V_43 , V_63 , & V_58 , & V_57 ) )
return;
V_64 = F_17 ( V_43 -> V_44 . V_46 , V_43 -> V_44 . V_47 , V_43 -> V_44 . V_48 ) ;
if ( F_14 ( V_43 , V_64 , & V_62 , & V_61 ) )
return;
V_60 = 3 - ( V_58 + V_62 ) ;
if ( V_60 == 0 )
V_59 = V_43 -> V_44 . V_46 ;
else if ( V_60 == 1 )
V_59 = V_43 -> V_44 . V_47 ;
else if ( V_60 == 2 )
V_59 = V_43 -> V_44 . V_48 ;
else
return;
V_51 = V_57 ;
if ( V_59 + V_43 -> V_55 [ V_60 ] - V_57 >
V_61 + V_43 -> V_55 [ V_62 ] - V_59 ) {
V_52 = V_43 -> V_55 [ V_58 ] ;
V_53 = V_59 ;
V_54 = V_61 +
V_43 -> V_55 [ V_62 ] - V_59 ;
} else {
V_52 = V_59 +
V_43 -> V_55 [ V_60 ] - V_57 ;
V_53 = V_61 ;
V_54 = V_43 -> V_55 [ V_62 ] ;
}
}
F_18 ( L_5 ,
V_51 , V_52 , V_53 , V_54 ) ;
}
int F_19 ( struct V_65 * V_66 , struct V_67 * V_40 )
{
struct V_49 * V_50 = V_66 -> V_49 ;
struct V_18 * V_68 = V_50 -> V_68 ;
struct V_69 * V_70 = & V_40 -> V_6 . V_70 ;
const struct V_1 * V_6 ;
T_1 V_71 , V_72 , V_73 , V_74 ;
T_1 V_75 , V_76 , V_77 , V_78 ;
int V_8 ;
F_18 ( L_6 , V_70 -> V_11 , V_70 -> V_12 ) ;
V_6 = F_3 ( & V_70 -> V_4 , NULL , 0 ) ;
if ( ! V_6 ) {
F_6 ( L_7 ,
V_70 -> V_4 ) ;
return - V_25 ;
}
if ( V_70 -> V_79 == V_80 )
V_70 -> V_79 = V_81 ;
else if ( V_70 -> V_79 != V_81 ) {
F_6 ( L_8 , V_70 -> V_79 ) ;
return - V_25 ;
}
V_71 = V_68 -> V_82 -> V_83 ;
V_72 = V_68 -> V_82 -> V_84 ;
V_73 = F_20 ( V_68 -> V_85 -> V_86 ) - 1 ;
if ( F_9 ( V_6 -> V_36 ) )
V_74 = F_20 ( V_68 -> V_85 -> V_87 ) - 1 ;
else
V_74 = F_20 ( V_68 -> V_85 -> V_87 ) - 2 ;
if ( F_21 ( V_40 -> type ) ) {
V_75 = V_68 -> V_88 -> V_86 ;
V_76 = V_68 -> V_88 -> V_87 ;
} else {
V_75 = V_68 -> V_88 -> V_83 ;
V_76 = V_68 -> V_88 -> V_84 ;
}
F_18 ( L_9 ,
V_73 , V_74 , V_71 , V_72 ) ;
V_77 = V_70 -> V_11 ;
V_78 = V_70 -> V_12 ;
F_22 ( & V_70 -> V_11 , V_75 , V_71 , V_73 ,
& V_70 -> V_12 , V_76 , V_72 , V_74 , 0 ) ;
if ( V_77 != V_70 -> V_11 || V_78 != V_70 -> V_12 )
F_18 ( L_10 ,
V_77 , V_78 , V_70 -> V_11 , V_70 -> V_12 ) ;
V_70 -> V_56 = V_6 -> V_56 ;
if ( V_70 -> V_11 >= 1280 )
V_70 -> V_89 = V_90 ;
else
V_70 -> V_89 = V_91 ;
for ( V_8 = 0 ; V_8 < V_70 -> V_56 ; ++ V_8 ) {
struct V_92 * V_93 = & V_70 -> V_93 [ V_8 ] ;
T_1 V_94 = V_93 -> V_95 ;
if ( V_6 -> V_96 == 1 &&
( V_94 == 0 || ( V_94 * 8 / V_6 -> V_97 [ V_8 ] ) < V_70 -> V_11 ) )
V_94 = V_70 -> V_11 * V_6 -> V_97 [ V_8 ] / 8 ;
if ( V_6 -> V_96 > 1 &&
( V_94 == 0 || V_94 < V_70 -> V_11 ) )
V_94 = V_70 -> V_11 ;
if ( V_8 != 0 && V_6 -> V_96 == 3 )
V_94 /= 2 ;
V_93 -> V_95 = V_94 ;
V_93 -> V_98 = F_23 ( V_70 -> V_11 * V_70 -> V_12 *
V_6 -> V_97 [ V_8 ] / 8 ,
V_93 -> V_98 ) ;
F_18 ( L_11 ,
V_8 , V_94 , V_70 -> V_93 [ V_8 ] . V_98 ) ;
}
return 0 ;
}
int F_24 ( struct V_65 * V_66 , struct V_67 * V_40 )
{
struct V_9 * V_10 ;
struct V_69 * V_70 ;
int V_8 ;
V_10 = F_25 ( V_66 , V_40 -> type ) ;
if ( F_26 ( V_10 ) )
return F_27 ( V_10 ) ;
V_70 = & V_40 -> V_6 . V_70 ;
V_70 -> V_11 = V_10 -> V_13 ;
V_70 -> V_12 = V_10 -> V_14 ;
V_70 -> V_79 = V_81 ;
V_70 -> V_4 = V_10 -> V_6 -> V_4 ;
V_70 -> V_89 = V_90 ;
V_70 -> V_56 = V_10 -> V_6 -> V_56 ;
for ( V_8 = 0 ; V_8 < V_70 -> V_56 ; ++ V_8 ) {
V_70 -> V_93 [ V_8 ] . V_95 = ( V_10 -> V_13 *
V_10 -> V_6 -> V_97 [ V_8 ] ) / 8 ;
V_70 -> V_93 [ V_8 ] . V_98 =
V_70 -> V_93 [ V_8 ] . V_95 * V_10 -> V_14 ;
}
return 0 ;
}
void F_28 ( T_1 V_77 , T_1 V_78 , T_1 * V_99 , T_1 * V_100 )
{
if ( V_77 != * V_99 || V_78 != * V_100 ) {
F_11 ( L_12 ,
* V_99 , * V_100 , V_77 , V_78 ) ;
* V_99 = V_77 ;
* V_100 = V_78 ;
}
}
int F_29 ( struct V_65 * V_66 , struct V_101 * V_48 )
{
struct V_9 * V_10 ;
V_10 = F_25 ( V_66 , V_48 -> type ) ;
if ( F_26 ( V_10 ) )
return F_27 ( V_10 ) ;
V_48 -> V_102 = V_10 -> V_15 ;
return 0 ;
}
int F_30 ( struct V_65 * V_66 , struct V_101 * V_48 )
{
struct V_9 * V_40 ;
struct V_49 * V_50 = V_66 -> V_49 ;
struct V_18 * V_68 = V_50 -> V_68 ;
T_1 V_73 = 0 , V_74 = 0 , V_77 , V_78 ;
T_1 V_75 , V_76 , V_71 , V_72 ;
if ( V_48 -> V_102 . V_17 < 0 || V_48 -> V_102 . V_16 < 0 ) {
F_6 ( L_13 ) ;
return - V_25 ;
}
F_18 ( L_6 , V_48 -> V_102 . V_11 , V_48 -> V_102 . V_12 ) ;
if ( V_48 -> type == V_103 )
V_40 = & V_66 -> V_104 ;
else if ( V_48 -> type == V_105 )
V_40 = & V_66 -> V_29 ;
else
return - V_25 ;
V_71 = V_40 -> V_13 ;
V_72 = V_40 -> V_14 ;
V_77 = V_48 -> V_102 . V_11 ;
V_78 = V_48 -> V_102 . V_12 ;
if ( F_21 ( V_48 -> type ) ) {
if ( ( F_10 ( V_40 -> V_6 -> V_36 ) && V_40 -> V_6 -> V_96 == 1 ) ||
F_31 ( V_40 -> V_6 -> V_36 ) )
V_75 = 32 ;
else
V_75 = 64 ;
if ( ( F_10 ( V_40 -> V_6 -> V_36 ) && V_40 -> V_6 -> V_96 == 3 ) ||
F_9 ( V_40 -> V_6 -> V_36 ) )
V_76 = 32 ;
else
V_76 = 16 ;
} else {
if ( F_9 ( V_40 -> V_6 -> V_36 ) || F_10 ( V_40 -> V_6 -> V_36 ) )
V_73 = F_20 ( V_68 -> V_85 -> V_106 ) - 1 ;
if ( F_9 ( V_40 -> V_6 -> V_36 ) )
V_74 = F_20 ( V_68 -> V_85 -> V_107 ) - 1 ;
if ( V_66 -> V_108 . V_109 -> V_110 == 90 ||
V_66 -> V_108 . V_109 -> V_110 == 270 ) {
V_71 = V_40 -> V_14 ;
V_72 = V_40 -> V_13 ;
V_75 = V_68 -> V_88 -> V_111 ;
V_76 = V_68 -> V_88 -> V_112 ;
V_77 = V_48 -> V_102 . V_12 ;
V_78 = V_48 -> V_102 . V_11 ;
} else {
V_75 = V_68 -> V_88 -> V_83 ;
V_76 = V_68 -> V_88 -> V_84 ;
}
}
F_18 ( L_14 ,
V_73 , V_74 , V_75 , V_76 ) ;
F_18 ( L_15 , V_77 , V_78 ) ;
F_22 ( & V_77 , V_75 , V_71 , V_73 ,
& V_78 , V_76 , V_72 , V_74 , 0 ) ;
if ( ! F_21 ( V_48 -> type ) &&
( V_66 -> V_108 . V_109 -> V_110 == 90 ||
V_66 -> V_108 . V_109 -> V_110 == 270 ) )
F_28 ( V_78 , V_77 ,
& V_48 -> V_102 . V_11 , & V_48 -> V_102 . V_12 ) ;
else
F_28 ( V_77 , V_78 ,
& V_48 -> V_102 . V_11 , & V_48 -> V_102 . V_12 ) ;
if ( V_48 -> V_102 . V_16 + V_77 > V_71 )
V_48 -> V_102 . V_16 = V_71 - V_77 ;
if ( V_48 -> V_102 . V_17 + V_78 > V_72 )
V_48 -> V_102 . V_17 = V_72 - V_78 ;
if ( ( F_9 ( V_40 -> V_6 -> V_36 ) || F_10 ( V_40 -> V_6 -> V_36 ) ) &&
V_48 -> V_102 . V_16 & 1 )
V_48 -> V_102 . V_16 -= 1 ;
F_18 ( L_16 ,
V_48 -> V_102 . V_16 , V_48 -> V_102 . V_17 , V_48 -> V_102 . V_11 , V_48 -> V_102 . V_12 , V_71 , V_72 ) ;
return 0 ;
}
int F_32 ( struct V_18 * V_19 , int V_113 , int V_28 , int V_114 ,
int V_115 , int V_116 , int V_117 )
{
int V_77 , V_78 , V_118 ;
if ( V_117 == V_119 )
V_118 = V_19 -> V_118 ;
else
V_118 = V_19 -> V_120 ;
if ( V_116 == 90 || V_116 == 270 ) {
V_77 = V_115 ;
V_78 = V_114 ;
} else {
V_77 = V_114 ;
V_78 = V_115 ;
}
if ( ( V_113 / V_77 ) > V_118 ||
( V_28 / V_78 ) > V_118 ||
( V_77 / V_113 ) > V_19 -> V_121 ||
( V_78 / V_28 ) > V_19 -> V_121 )
return - V_25 ;
return 0 ;
}
int F_33 ( struct V_65 * V_66 )
{
struct V_122 * V_123 = & V_66 -> V_124 ;
struct V_9 * V_29 = & V_66 -> V_29 ;
struct V_9 * V_104 = & V_66 -> V_104 ;
struct V_18 * V_68 = V_66 -> V_49 -> V_68 ;
struct V_125 * V_126 = & V_66 -> V_49 -> V_127 -> V_126 ;
int V_31 , V_32 ;
int V_128 ;
V_128 = F_32 ( V_68 , V_29 -> V_15 . V_11 ,
V_29 -> V_15 . V_12 , V_104 -> V_15 . V_11 , V_104 -> V_15 . V_12 ,
V_66 -> V_108 . V_109 -> V_110 , V_66 -> V_117 ) ;
if ( V_128 ) {
F_6 ( L_17 ) ;
return V_128 ;
}
if ( V_66 -> V_108 . V_109 -> V_110 == 90 ||
V_66 -> V_108 . V_109 -> V_110 == 270 ) {
V_32 = V_104 -> V_15 . V_11 ;
V_31 = V_104 -> V_15 . V_12 ;
} else {
V_31 = V_104 -> V_15 . V_11 ;
V_32 = V_104 -> V_15 . V_12 ;
}
if ( V_31 <= 0 || V_32 <= 0 ) {
F_34 ( V_126 , L_18 , V_31 , V_32 ) ;
return - V_25 ;
}
V_128 = F_5 ( V_68 , V_29 -> V_15 . V_11 ,
V_31 , & V_123 -> V_129 ) ;
if ( V_128 ) {
F_6 ( L_19 ) ;
return V_128 ;
}
V_128 = F_5 ( V_68 , V_29 -> V_15 . V_12 ,
V_32 , & V_123 -> V_130 ) ;
if ( V_128 ) {
F_6 ( L_20 ) ;
return V_128 ;
}
F_8 ( V_68 , V_29 , & V_123 -> V_129 ,
V_31 , V_32 , & V_123 -> V_130 ) ;
F_7 ( V_123 -> V_129 , V_123 -> V_130 ,
& V_123 -> V_131 ) ;
V_123 -> V_132 = ( V_29 -> V_15 . V_11 << 16 ) / V_31 ;
V_123 -> V_133 = ( V_29 -> V_15 . V_12 << 16 ) / V_32 ;
F_18 ( L_21 ,
V_29 -> V_15 . V_11 , V_29 -> V_15 . V_12 , V_31 , V_32 ) ;
F_18 ( L_22 ,
V_123 -> V_131 , V_123 -> V_129 ) ;
F_18 ( L_23 ,
V_123 -> V_130 , V_123 -> V_132 , V_123 -> V_133 ) ;
return 0 ;
}
static int F_35 ( struct V_65 * V_66 , struct V_134 * V_135 )
{
struct V_49 * V_50 = V_66 -> V_49 ;
struct V_18 * V_68 = V_50 -> V_68 ;
unsigned int V_136 = V_137 | V_138 ;
int V_128 = 0 ;
if ( V_135 -> V_136 & V_139 )
return 0 ;
switch ( V_135 -> V_140 ) {
case V_141 :
V_66 -> V_142 = V_135 -> V_110 ;
break;
case V_143 :
V_66 -> V_144 = V_135 -> V_110 ;
break;
case V_145 :
if ( ( V_66 -> V_146 & V_136 ) == V_136 ) {
V_128 = F_32 ( V_68 ,
V_66 -> V_29 . V_15 . V_11 ,
V_66 -> V_29 . V_15 . V_12 ,
V_66 -> V_104 . V_15 . V_11 ,
V_66 -> V_104 . V_15 . V_12 ,
V_66 -> V_108 . V_109 -> V_110 ,
V_66 -> V_117 ) ;
if ( V_128 )
return - V_25 ;
}
V_66 -> V_147 = V_135 -> V_110 ;
break;
case V_148 :
V_66 -> V_104 . V_149 = V_135 -> V_110 ;
break;
}
V_66 -> V_146 |= V_150 ;
return 0 ;
}
static int F_36 ( struct V_134 * V_135 )
{
struct V_65 * V_66 = F_37 ( V_135 ) ;
unsigned long V_136 ;
int V_128 ;
F_38 ( & V_66 -> V_49 -> V_151 , V_136 ) ;
V_128 = F_35 ( V_66 , V_135 ) ;
F_39 ( & V_66 -> V_49 -> V_151 , V_136 ) ;
return V_128 ;
}
int F_40 ( struct V_65 * V_66 )
{
if ( V_66 -> V_152 ) {
F_6 ( L_24 ) ;
return 0 ;
}
F_41 ( & V_66 -> V_153 , V_154 ) ;
V_66 -> V_108 . V_109 = F_42 ( & V_66 -> V_153 ,
& V_155 , V_145 , 0 , 270 , 90 , 0 ) ;
V_66 -> V_108 . V_142 = F_42 ( & V_66 -> V_153 ,
& V_155 , V_141 , 0 , 1 , 1 , 0 ) ;
V_66 -> V_108 . V_144 = F_42 ( & V_66 -> V_153 ,
& V_155 , V_143 , 0 , 1 , 1 , 0 ) ;
V_66 -> V_108 . V_156 = F_42 ( & V_66 -> V_153 ,
& V_155 , V_148 , 0 , 255 , 1 , 0 ) ;
V_66 -> V_152 = V_66 -> V_153 . error == 0 ;
if ( V_66 -> V_153 . error ) {
int V_157 = V_66 -> V_153 . error ;
F_43 ( & V_66 -> V_153 ) ;
F_6 ( L_25 ) ;
return V_157 ;
}
return 0 ;
}
void F_44 ( struct V_65 * V_66 )
{
if ( V_66 -> V_152 ) {
F_43 ( & V_66 -> V_153 ) ;
V_66 -> V_152 = false ;
}
}
int F_45 ( struct V_65 * V_66 , struct V_158 * V_159 ,
struct V_9 * V_10 , struct V_160 * V_44 )
{
int V_128 = 0 ;
T_1 V_161 ;
if ( ( V_159 == NULL ) || ( V_10 == NULL ) )
return - V_25 ;
V_161 = V_10 -> V_13 * V_10 -> V_14 ;
F_18 ( L_26 ,
V_10 -> V_6 -> V_56 , V_10 -> V_6 -> V_96 , V_161 ) ;
V_44 -> V_46 = F_46 ( V_159 , 0 ) ;
if ( V_10 -> V_6 -> V_56 == 1 ) {
switch ( V_10 -> V_6 -> V_96 ) {
case 1 :
V_44 -> V_47 = 0 ;
V_44 -> V_48 = 0 ;
break;
case 2 :
V_44 -> V_47 = ( V_162 ) ( V_44 -> V_46 + V_161 ) ;
V_44 -> V_48 = 0 ;
break;
case 3 :
V_44 -> V_47 = ( V_162 ) ( V_44 -> V_46 + V_161 ) ;
if ( V_163 == V_10 -> V_6 -> V_36 )
V_44 -> V_48 = ( V_162 ) ( V_44 -> V_47
+ ( V_161 >> 2 ) ) ;
else
V_44 -> V_48 = ( V_162 ) ( V_44 -> V_47
+ ( V_161 >> 1 ) ) ;
break;
default:
F_6 ( L_27 ) ;
return - V_25 ;
}
} else {
if ( V_10 -> V_6 -> V_56 >= 2 )
V_44 -> V_47 = F_46 ( V_159 , 1 ) ;
if ( V_10 -> V_6 -> V_56 == 3 )
V_44 -> V_48 = F_46 ( V_159 , 2 ) ;
}
if ( ( V_10 -> V_6 -> V_4 == V_164 ) ||
( V_10 -> V_6 -> V_4 == V_165 ) ||
( V_10 -> V_6 -> V_4 == V_166 ) ||
( V_10 -> V_6 -> V_4 == V_167 ) ||
( V_10 -> V_6 -> V_4 == V_168 ) ||
( V_10 -> V_6 -> V_4 == V_169 ) )
F_47 ( V_44 -> V_47 , V_44 -> V_48 ) ;
F_18 ( L_28 ,
& V_44 -> V_46 , & V_44 -> V_47 , & V_44 -> V_48 , V_128 ) ;
return V_128 ;
}
static T_2 F_48 ( int V_170 , void * V_171 )
{
struct V_49 * V_50 = V_171 ;
struct V_65 * V_66 ;
int V_172 ;
V_172 = F_49 ( V_50 ) ;
F_50 ( V_50 , V_172 ) ;
if ( V_172 == V_173 ) {
F_6 ( L_29 ) ;
return V_174 ;
}
F_51 ( & V_50 -> V_151 ) ;
if ( F_52 ( V_175 , & V_50 -> V_146 ) ) {
F_53 ( V_50 , false ) ;
if ( F_52 ( V_176 , & V_50 -> V_146 ) ) {
F_54 ( V_177 , & V_50 -> V_146 ) ;
F_55 ( & V_50 -> V_178 ) ;
goto V_179;
}
V_66 = F_56 ( V_50 -> V_180 . V_181 ) ;
if ( ! V_66 || ! V_66 -> V_182 )
goto V_179;
F_57 ( & V_50 -> V_151 ) ;
F_58 ( V_66 , V_183 ) ;
if ( V_66 -> V_146 & V_184 ) {
V_66 -> V_146 &= ~ V_184 ;
F_55 ( & V_50 -> V_178 ) ;
}
return V_174 ;
}
V_179:
F_57 ( & V_50 -> V_151 ) ;
return V_174 ;
}
static int F_59 ( struct V_185 * V_127 )
{
struct V_49 * V_50 ;
struct V_186 * V_187 ;
struct V_125 * V_126 = & V_127 -> V_126 ;
const struct V_188 * V_189 = F_60 ( V_126 ) ;
int V_128 ;
int V_8 ;
V_50 = F_61 ( V_126 , sizeof( struct V_49 ) , V_190 ) ;
if ( ! V_50 )
return - V_191 ;
V_128 = F_62 ( V_127 -> V_126 . V_192 , L_30 ) ;
if ( V_128 < 0 )
return V_128 ;
V_50 -> V_140 = V_128 ;
if ( V_50 -> V_140 >= V_189 -> V_193 ) {
F_34 ( V_126 , L_31 , V_50 -> V_140 ) ;
return - V_25 ;
}
V_50 -> V_194 = V_189 -> V_194 ;
V_50 -> V_68 = V_189 -> V_68 [ V_50 -> V_140 ] ;
V_50 -> V_127 = V_127 ;
F_63 ( & V_50 -> V_178 ) ;
F_64 ( & V_50 -> V_151 ) ;
F_65 ( & V_50 -> V_195 ) ;
V_187 = F_66 ( V_127 , V_196 , 0 ) ;
V_50 -> V_197 = F_67 ( V_126 , V_187 ) ;
if ( F_26 ( V_50 -> V_197 ) )
return F_27 ( V_50 -> V_197 ) ;
V_187 = F_66 ( V_127 , V_198 , 0 ) ;
if ( ! V_187 ) {
F_34 ( V_126 , L_32 ) ;
return - V_199 ;
}
for ( V_8 = 0 ; V_8 < V_50 -> V_194 ; V_8 ++ ) {
V_50 -> clock [ V_8 ] = F_68 ( V_126 , V_189 -> V_200 [ V_8 ] ) ;
if ( F_26 ( V_50 -> clock [ V_8 ] ) ) {
F_34 ( V_126 , L_33 ,
V_189 -> V_200 [ V_8 ] ) ;
return F_27 ( V_50 -> clock [ V_8 ] ) ;
}
}
for ( V_8 = 0 ; V_8 < V_50 -> V_194 ; V_8 ++ ) {
V_128 = F_69 ( V_50 -> clock [ V_8 ] ) ;
if ( V_128 ) {
F_34 ( V_126 , L_34 ,
V_189 -> V_200 [ V_8 ] ) ;
while ( -- V_8 >= 0 )
F_70 ( V_50 -> clock [ V_8 ] ) ;
return V_128 ;
}
}
V_128 = F_71 ( V_126 , V_187 -> V_201 , F_48 ,
0 , V_127 -> V_42 , V_50 ) ;
if ( V_128 ) {
F_34 ( V_126 , L_35 , V_128 ) ;
goto V_202;
}
V_128 = F_72 ( V_126 , & V_50 -> V_203 ) ;
if ( V_128 )
goto V_202;
V_128 = F_73 ( V_50 ) ;
if ( V_128 )
goto V_204;
F_74 ( V_127 , V_50 ) ;
F_75 ( V_50 ) ;
F_76 ( V_50 ) ;
F_77 ( V_126 , F_78 ( 32 ) ) ;
F_79 ( V_126 , L_36 , V_50 -> V_140 ) ;
F_80 ( V_126 ) ;
F_81 ( V_126 ) ;
return 0 ;
V_204:
F_82 ( & V_50 -> V_203 ) ;
V_202:
for ( V_8 = V_50 -> V_194 - 1 ; V_8 >= 0 ; V_8 -- )
F_70 ( V_50 -> clock [ V_8 ] ) ;
return V_128 ;
}
static int F_83 ( struct V_185 * V_127 )
{
struct V_49 * V_50 = F_84 ( V_127 ) ;
int V_8 ;
F_85 ( & V_127 -> V_126 ) ;
F_86 ( V_50 ) ;
F_82 ( & V_50 -> V_203 ) ;
F_87 ( & V_127 -> V_126 ) ;
for ( V_8 = 0 ; V_8 < V_50 -> V_194 ; V_8 ++ )
F_70 ( V_50 -> clock [ V_8 ] ) ;
F_88 ( & V_127 -> V_126 ) ;
F_79 ( & V_127 -> V_126 , L_37 , V_127 -> V_42 ) ;
return 0 ;
}
static int F_89 ( struct V_49 * V_50 )
{
unsigned long V_136 ;
int V_205 ;
F_38 ( & V_50 -> V_151 , V_136 ) ;
if ( ! F_90 ( V_50 ) ) {
F_39 ( & V_50 -> V_151 , V_136 ) ;
return 0 ;
}
F_91 ( V_177 , & V_50 -> V_146 ) ;
F_54 ( V_176 , & V_50 -> V_146 ) ;
F_39 ( & V_50 -> V_151 , V_136 ) ;
V_205 = F_92 ( V_50 -> V_178 ,
F_93 ( V_177 , & V_50 -> V_146 ) ,
V_206 ) ;
F_91 ( V_176 , & V_50 -> V_146 ) ;
return V_205 == 0 ? - V_207 : 0 ;
}
static void F_94 ( struct V_49 * V_50 )
{
struct V_65 * V_66 ;
unsigned long V_136 ;
F_38 ( & V_50 -> V_151 , V_136 ) ;
V_66 = V_50 -> V_180 . V_66 ;
V_50 -> V_180 . V_66 = NULL ;
F_39 ( & V_50 -> V_151 , V_136 ) ;
if ( F_52 ( V_177 , & V_50 -> V_146 ) )
F_58 ( V_66 , V_208 ) ;
}
static int F_95 ( struct V_125 * V_126 )
{
struct V_49 * V_50 = F_96 ( V_126 ) ;
int V_128 = 0 ;
int V_8 ;
F_18 ( L_38 , V_50 -> V_140 , V_50 -> V_146 ) ;
for ( V_8 = 0 ; V_8 < V_50 -> V_194 ; V_8 ++ ) {
V_128 = F_69 ( V_50 -> clock [ V_8 ] ) ;
if ( V_128 ) {
while ( -- V_8 >= 0 )
F_70 ( V_50 -> clock [ V_8 ] ) ;
return V_128 ;
}
}
F_75 ( V_50 ) ;
F_76 ( V_50 ) ;
F_94 ( V_50 ) ;
return 0 ;
}
static int F_97 ( struct V_125 * V_126 )
{
struct V_49 * V_50 = F_96 ( V_126 ) ;
int V_128 = 0 ;
int V_8 ;
V_128 = F_89 ( V_50 ) ;
if ( V_128 )
return V_128 ;
for ( V_8 = V_50 -> V_194 - 1 ; V_8 >= 0 ; V_8 -- )
F_70 ( V_50 -> clock [ V_8 ] ) ;
F_18 ( L_38 , V_50 -> V_140 , V_50 -> V_146 ) ;
return V_128 ;
}
