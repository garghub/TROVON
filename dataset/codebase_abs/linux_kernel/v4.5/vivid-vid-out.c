static int F_1 ( struct V_1 * V_2 ,
unsigned * V_3 , unsigned * V_4 ,
unsigned V_5 [] , void * V_6 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = V_8 -> V_11 ;
unsigned V_12 = V_10 -> V_13 ;
unsigned V_14 = V_8 -> V_15 . V_16 ;
unsigned V_17 = V_8 -> V_18 [ 0 ] * V_14 ;
unsigned V_19 ;
for ( V_19 = V_10 -> V_13 ; V_19 < V_10 -> V_12 ; V_19 ++ )
V_17 += V_8 -> V_18 [ V_19 ] * V_14 / V_10 -> V_20 [ V_19 ] ;
if ( V_8 -> V_21 == V_22 ) {
if ( F_3 ( V_2 ) )
return - V_23 ;
}
if ( V_8 -> V_24 ) {
V_8 -> V_24 = false ;
return - V_23 ;
}
if ( * V_4 ) {
if ( * V_4 != V_12 )
return - V_23 ;
if ( V_5 [ 0 ] < V_17 )
return - V_23 ;
for ( V_19 = 1 ; V_19 < V_12 ; V_19 ++ ) {
if ( V_5 [ V_19 ] < V_8 -> V_18 [ V_19 ] * V_14 )
return - V_23 ;
}
} else {
for ( V_19 = 0 ; V_19 < V_12 ; V_19 ++ )
V_5 [ V_19 ] = V_19 ? V_8 -> V_18 [ V_19 ] * V_14 : V_17 ;
}
if ( V_2 -> V_25 + * V_3 < 2 )
* V_3 = 2 - V_2 -> V_25 ;
* V_4 = V_12 ;
F_4 ( V_8 , 1 , L_1 , V_26 , * V_3 ) ;
for ( V_19 = 0 ; V_19 < V_12 ; V_19 ++ )
F_4 ( V_8 , 1 , L_2 , V_26 , V_19 , V_5 [ V_19 ] ) ;
return 0 ;
}
static int F_5 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_6 ( V_28 ) ;
struct V_7 * V_8 = F_2 ( V_28 -> V_1 ) ;
unsigned long V_17 ;
unsigned V_12 ;
unsigned V_19 ;
F_4 ( V_8 , 1 , L_3 , V_26 ) ;
if ( F_7 ( NULL == V_8 -> V_11 ) )
return - V_23 ;
V_12 = V_8 -> V_11 -> V_12 ;
if ( V_8 -> V_31 ) {
V_8 -> V_31 = false ;
return - V_23 ;
}
if ( V_8 -> V_21 != V_22 )
V_30 -> V_32 = V_8 -> V_21 ;
else if ( V_30 -> V_32 != V_33 &&
V_30 -> V_32 != V_34 )
return - V_23 ;
for ( V_19 = 0 ; V_19 < V_12 ; V_19 ++ ) {
V_17 = V_8 -> V_18 [ V_19 ] * V_8 -> V_15 . V_16 +
V_28 -> V_12 [ V_19 ] . V_35 ;
if ( F_8 ( V_28 , V_19 ) < V_17 ) {
F_4 ( V_8 , 1 , L_4 ,
V_26 , V_19 , F_8 ( V_28 , V_19 ) , V_17 ) ;
return - V_23 ;
}
}
return 0 ;
}
static void F_9 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_6 ( V_28 ) ;
struct V_7 * V_8 = F_2 ( V_28 -> V_1 ) ;
struct V_36 * V_37 = F_10 ( V_30 , struct V_36 , V_28 ) ;
F_4 ( V_8 , 1 , L_3 , V_26 ) ;
F_11 ( & V_8 -> V_38 ) ;
F_12 ( & V_37 -> V_39 , & V_8 -> V_40 ) ;
F_13 ( & V_8 -> V_38 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_41 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_42 ;
if ( F_15 ( & V_8 -> V_43 ) )
V_8 -> V_44 = F_16 ( V_8 ) ;
if ( V_8 -> V_45 )
return 0 ;
V_8 -> V_46 = 0 ;
F_4 ( V_8 , 1 , L_3 , V_26 ) ;
if ( V_8 -> V_47 ) {
V_8 -> V_47 = false ;
V_42 = - V_23 ;
} else {
V_42 = F_17 ( V_8 , & V_8 -> V_48 ) ;
}
if ( V_42 ) {
struct V_36 * V_37 , * V_49 ;
F_18 (buf, tmp, &dev->vid_out_active, list) {
F_19 ( & V_37 -> V_39 ) ;
F_20 ( & V_37 -> V_28 . V_50 ,
V_51 ) ;
}
}
return V_42 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_4 ( V_8 , 1 , L_3 , V_26 ) ;
F_22 ( V_8 , & V_8 -> V_48 ) ;
V_8 -> V_44 = false ;
}
void F_23 ( struct V_7 * V_8 )
{
struct V_52 * V_53 = & V_8 -> V_54 . V_53 ;
unsigned V_17 , V_19 ;
T_1 V_55 ;
switch ( V_8 -> V_56 [ V_8 -> V_57 ] ) {
case V_58 :
default:
V_8 -> V_21 = V_8 -> V_59 ;
V_8 -> V_60 . V_61 = 720 ;
if ( V_8 -> V_62 & V_63 ) {
V_8 -> V_60 . V_16 = 480 ;
V_8 -> V_64 = (struct V_65 ) { 1001 , 30000 } ;
V_8 -> V_66 = V_67 ;
} else {
V_8 -> V_60 . V_16 = 576 ;
V_8 -> V_64 = (struct V_65 ) { 1000 , 25000 } ;
V_8 -> V_66 = V_68 | V_69 ;
}
V_8 -> V_70 = V_71 ;
break;
case V_72 :
V_8 -> V_60 . V_61 = V_53 -> V_61 ;
V_8 -> V_60 . V_16 = V_53 -> V_16 ;
V_17 = F_24 ( V_53 ) * F_25 ( V_53 ) ;
if ( F_26 ( V_53 ) && ( V_53 -> V_73 & V_74 ) )
V_55 = F_27 ( V_53 -> V_55 * 1000 , 1001 ) ;
else
V_55 = V_53 -> V_55 ;
V_8 -> V_64 = (struct V_65 ) {
V_17 / 100 , ( V_75 ) V_55 / 100
} ;
if ( V_53 -> V_76 )
V_8 -> V_21 = V_22 ;
else
V_8 -> V_21 = V_77 ;
if ( ! V_8 -> V_78 && ( V_53 -> V_73 & V_79 ) ) {
if ( V_53 -> V_61 == 720 && V_53 -> V_16 <= 576 )
V_8 -> V_70 = V_71 ;
else
V_8 -> V_70 = V_80 ;
} else {
V_8 -> V_70 = V_81 ;
}
break;
}
V_8 -> V_82 = V_83 ;
V_8 -> V_84 = V_85 ;
V_8 -> V_86 = V_87 ;
V_8 -> V_88 = V_8 -> V_60 ;
V_8 -> V_89 = V_8 -> V_60 ;
V_8 -> V_90 = V_8 -> V_88 ;
if ( F_28 ( V_8 -> V_21 ) )
V_8 -> V_90 . V_16 /= 2 ;
V_8 -> V_15 = V_8 -> V_90 ;
for ( V_19 = 0 ; V_19 < V_8 -> V_11 -> V_12 ; V_19 ++ )
V_8 -> V_18 [ V_19 ] =
( V_8 -> V_60 . V_61 * V_8 -> V_11 -> V_91 [ V_19 ] ) / 8 ;
}
static enum V_92 F_29 ( struct V_7 * V_8 , enum V_92 V_32 )
{
if ( F_30 ( V_8 ) ) {
switch ( V_32 ) {
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_22 :
return V_32 ;
case V_97 :
default:
return V_97 ;
}
}
if ( F_31 ( V_8 ) )
return V_8 -> V_54 . V_53 . V_76 ? V_22 :
V_77 ;
return V_77 ;
}
static enum V_98 F_32 ( const struct V_7 * V_8 )
{
if ( F_30 ( V_8 ) )
return ( V_8 -> V_62 & V_63 ) ?
V_99 : V_100 ;
if ( F_31 ( V_8 ) &&
V_8 -> V_60 . V_61 == 720 && V_8 -> V_60 . V_16 <= 576 )
return V_8 -> V_60 . V_16 == 480 ?
V_99 : V_100 ;
return V_101 ;
}
int F_33 ( struct V_102 * V_102 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
struct V_106 * V_107 = & V_105 -> V_108 . V_109 ;
const struct V_9 * V_108 = V_8 -> V_11 ;
unsigned V_19 ;
V_107 -> V_61 = V_8 -> V_15 . V_61 ;
V_107 -> V_16 = V_8 -> V_15 . V_16 ;
V_107 -> V_32 = V_8 -> V_21 ;
V_107 -> V_110 = V_108 -> V_111 ;
V_107 -> V_112 = V_8 -> V_70 ;
V_107 -> V_113 = V_8 -> V_82 ;
V_107 -> V_114 = V_8 -> V_84 ;
V_107 -> V_115 = V_8 -> V_86 ;
V_107 -> V_116 = V_108 -> V_13 ;
for ( V_19 = 0 ; V_19 < V_107 -> V_116 ; V_19 ++ ) {
V_107 -> V_117 [ V_19 ] . V_118 = V_8 -> V_18 [ V_19 ] ;
V_107 -> V_117 [ V_19 ] . V_119 =
V_107 -> V_117 [ V_19 ] . V_118 * V_107 -> V_16 ;
}
for ( V_19 = V_108 -> V_13 ; V_19 < V_108 -> V_12 ; V_19 ++ ) {
unsigned V_120 = V_8 -> V_18 [ V_19 ] ;
V_107 -> V_117 [ 0 ] . V_119 +=
( V_120 * V_107 -> V_16 ) / V_108 -> V_20 [ V_19 ] ;
}
return 0 ;
}
int F_35 ( struct V_102 * V_102 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
struct V_52 * V_53 = & V_8 -> V_54 . V_53 ;
struct V_106 * V_107 = & V_105 -> V_108 . V_109 ;
struct V_121 * V_122 = V_107 -> V_117 ;
const struct V_9 * V_108 ;
unsigned V_118 , V_123 ;
unsigned V_124 = 1 ;
unsigned V_125 , V_14 ;
unsigned V_19 ;
V_108 = F_36 ( V_8 , V_107 -> V_110 ) ;
if ( ! V_108 ) {
F_4 ( V_8 , 1 , L_5 ,
V_107 -> V_110 ) ;
V_107 -> V_110 = V_126 ;
V_108 = F_36 ( V_8 , V_107 -> V_110 ) ;
}
V_107 -> V_32 = F_29 ( V_8 , V_107 -> V_32 ) ;
if ( F_30 ( V_8 ) ) {
V_125 = 720 ;
V_14 = ( V_8 -> V_62 & V_63 ) ? 480 : 576 ;
} else {
V_125 = V_8 -> V_60 . V_61 ;
V_14 = V_8 -> V_60 . V_16 ;
}
if ( F_28 ( V_107 -> V_32 ) )
V_124 = 2 ;
if ( ! V_8 -> V_127 && ! V_8 -> V_128 && ! V_8 -> V_129 ) {
V_107 -> V_61 = V_125 ;
V_107 -> V_16 = V_14 / V_124 ;
} else {
struct V_130 V_131 = { 0 , 0 , V_107 -> V_61 , V_107 -> V_16 * V_124 } ;
F_37 ( & V_131 , & V_132 ) ;
F_38 ( & V_131 , & V_133 ) ;
if ( V_8 -> V_127 && ! V_8 -> V_128 ) {
struct V_130 V_134 = { 0 , 0 , V_135 * V_125 , V_135 * V_14 } ;
F_38 ( & V_131 , & V_134 ) ;
} else if ( ! V_8 -> V_127 && V_8 -> V_129 && ! V_8 -> V_128 ) {
F_38 ( & V_131 , & V_8 -> V_60 ) ;
} else if ( ! V_8 -> V_127 && ! V_8 -> V_129 ) {
F_37 ( & V_131 , & V_8 -> V_60 ) ;
}
V_107 -> V_61 = V_131 . V_61 ;
V_107 -> V_16 = V_131 . V_16 / V_124 ;
}
V_118 = ( V_107 -> V_61 * V_108 -> V_91 [ 0 ] ) >> 3 ;
V_123 = ( V_135 * V_136 * V_108 -> V_91 [ 0 ] ) >> 3 ;
V_107 -> V_116 = V_108 -> V_13 ;
for ( V_19 = 0 ; V_19 < V_107 -> V_116 ; V_19 ++ ) {
if ( V_122 [ V_19 ] . V_118 > V_123 )
V_122 [ V_19 ] . V_118 = V_123 ;
if ( V_122 [ V_19 ] . V_118 < V_118 )
V_122 [ V_19 ] . V_118 = V_118 ;
V_122 [ V_19 ] . V_119 = V_122 [ V_19 ] . V_118 * V_107 -> V_16 ;
memset ( V_122 [ V_19 ] . V_137 , 0 , sizeof( V_122 [ V_19 ] . V_137 ) ) ;
}
for ( V_19 = V_108 -> V_13 ; V_19 < V_108 -> V_12 ; V_19 ++ )
V_122 [ 0 ] . V_119 += ( V_122 [ 0 ] . V_118 * V_108 -> V_91 [ V_19 ] ) /
( V_108 -> V_91 [ 0 ] * V_108 -> V_20 [ V_19 ] ) ;
V_107 -> V_113 = V_83 ;
V_107 -> V_114 = V_85 ;
V_107 -> V_115 = V_87 ;
if ( F_30 ( V_8 ) ) {
V_107 -> V_112 = V_71 ;
} else if ( V_8 -> V_78 || ! ( V_53 -> V_73 & V_79 ) ) {
V_107 -> V_112 = V_81 ;
if ( V_8 -> V_78 )
V_107 -> V_115 = V_138 ;
} else if ( V_53 -> V_61 == 720 && V_53 -> V_16 <= 576 ) {
V_107 -> V_112 = V_71 ;
} else if ( V_107 -> V_112 != V_71 &&
V_107 -> V_112 != V_80 &&
V_107 -> V_112 != V_139 &&
V_107 -> V_112 != V_140 &&
V_107 -> V_112 != V_81 ) {
V_107 -> V_112 = V_80 ;
}
memset ( V_107 -> V_137 , 0 , sizeof( V_107 -> V_137 ) ) ;
return 0 ;
}
int F_39 ( struct V_102 * V_102 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 = & V_105 -> V_108 . V_109 ;
struct V_7 * V_8 = F_34 ( V_102 ) ;
struct V_130 * V_141 = & V_8 -> V_90 ;
struct V_130 * V_142 = & V_8 -> V_88 ;
struct V_1 * V_143 = & V_8 -> V_144 ;
int V_145 = F_35 ( V_102 , V_103 , V_105 ) ;
unsigned V_124 = 1 ;
unsigned V_19 ;
if ( V_145 < 0 )
return V_145 ;
if ( F_40 ( V_143 ) &&
( F_30 ( V_8 ) ||
V_107 -> V_61 != V_8 -> V_15 . V_61 ||
V_107 -> V_16 != V_8 -> V_15 . V_16 ||
V_107 -> V_110 != V_8 -> V_11 -> V_111 ||
V_107 -> V_32 != V_8 -> V_21 ) ) {
F_4 ( V_8 , 1 , L_6 , V_26 ) ;
return - V_146 ;
}
if ( F_40 ( V_143 ) )
goto V_147;
V_8 -> V_11 = F_36 ( V_8 , V_107 -> V_110 ) ;
if ( F_28 ( V_107 -> V_32 ) )
V_124 = 2 ;
if ( V_8 -> V_127 || V_8 -> V_128 || V_8 -> V_129 ) {
struct V_130 V_131 = { 0 , 0 , V_107 -> V_61 , V_107 -> V_16 } ;
if ( V_8 -> V_127 ) {
if ( V_8 -> V_128 )
F_41 ( V_141 , & V_131 ) ;
else
* V_141 = V_131 ;
if ( V_8 -> V_129 && ! V_8 -> V_128 ) {
struct V_130 V_148 = {
0 , 0 ,
V_131 . V_61 / V_135 ,
V_124 * V_131 . V_16 / V_135
} ;
struct V_130 V_134 = {
0 , 0 ,
V_131 . V_61 * V_135 ,
V_124 * V_131 . V_16 * V_135
} ;
F_37 ( V_142 , & V_148 ) ;
F_38 ( V_142 , & V_134 ) ;
F_41 ( V_142 , & V_8 -> V_89 ) ;
} else if ( V_8 -> V_129 ) {
struct V_130 V_148 = {
0 , 0 ,
V_141 -> V_61 / V_135 ,
V_124 * V_141 -> V_16 / V_135
} ;
struct V_130 V_134 = {
0 , 0 ,
V_141 -> V_61 * V_135 ,
V_124 * V_141 -> V_16 * V_135
} ;
F_37 ( V_142 , & V_148 ) ;
F_38 ( V_142 , & V_134 ) ;
F_41 ( V_142 , & V_8 -> V_89 ) ;
}
} else if ( V_8 -> V_129 && ! V_8 -> V_128 ) {
F_42 ( V_141 , & V_131 ) ;
V_131 . V_16 *= V_124 ;
F_42 ( V_142 , & V_131 ) ;
F_41 ( V_142 , & V_8 -> V_89 ) ;
} else if ( ! V_8 -> V_129 ) {
F_41 ( V_141 , & V_131 ) ;
V_131 . V_16 /= V_124 ;
F_42 ( V_142 , & V_131 ) ;
} else {
V_131 . V_16 *= V_124 ;
F_38 ( V_142 , & V_131 ) ;
F_41 ( V_142 , & V_8 -> V_89 ) ;
V_141 -> V_149 *= V_124 ;
V_141 -> V_16 *= V_124 ;
F_42 ( V_141 , V_142 ) ;
F_41 ( V_141 , & V_131 ) ;
V_141 -> V_149 /= V_124 ;
V_141 -> V_16 /= V_124 ;
}
} else {
struct V_130 V_131 = { 0 , 0 , V_107 -> V_61 , V_107 -> V_16 } ;
F_42 ( V_141 , & V_131 ) ;
V_131 . V_16 /= V_124 ;
F_42 ( V_142 , & V_131 ) ;
}
V_8 -> V_15 . V_61 = V_107 -> V_61 ;
V_8 -> V_15 . V_16 = V_107 -> V_16 ;
for ( V_19 = 0 ; V_19 < V_107 -> V_116 ; V_19 ++ )
V_8 -> V_18 [ V_19 ] = V_107 -> V_117 [ V_19 ] . V_118 ;
for ( V_19 = V_8 -> V_11 -> V_13 ; V_19 < V_8 -> V_11 -> V_12 ; V_19 ++ )
V_8 -> V_18 [ V_19 ] =
( V_8 -> V_18 [ 0 ] * V_8 -> V_11 -> V_91 [ V_19 ] ) /
V_8 -> V_11 -> V_91 [ 0 ] ;
V_8 -> V_21 = V_107 -> V_32 ;
if ( F_30 ( V_8 ) )
V_8 -> V_59 = V_107 -> V_32 ;
V_147:
V_8 -> V_70 = V_107 -> V_112 ;
V_8 -> V_82 = V_107 -> V_113 ;
V_8 -> V_84 = V_107 -> V_114 ;
V_8 -> V_86 = V_107 -> V_115 ;
if ( V_8 -> V_150 ) {
F_43 ( V_8 , V_58 ) ;
F_43 ( V_8 , V_72 ) ;
}
return 0 ;
}
int F_44 ( struct V_102 * V_102 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( ! V_8 -> V_151 )
return - V_152 ;
return F_33 ( V_102 , V_103 , V_105 ) ;
}
int F_45 ( struct V_102 * V_102 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( ! V_8 -> V_151 )
return - V_152 ;
return F_35 ( V_102 , V_103 , V_105 ) ;
}
int F_46 ( struct V_102 * V_102 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( ! V_8 -> V_151 )
return - V_152 ;
return F_39 ( V_102 , V_103 , V_105 ) ;
}
int F_47 ( struct V_102 * V_102 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( V_8 -> V_151 )
return - V_152 ;
return F_48 ( V_102 , V_103 , V_105 , F_33 ) ;
}
int F_49 ( struct V_102 * V_102 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( V_8 -> V_151 )
return - V_152 ;
return F_48 ( V_102 , V_103 , V_105 , F_35 ) ;
}
int F_50 ( struct V_102 * V_102 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( V_8 -> V_151 )
return - V_152 ;
return F_48 ( V_102 , V_103 , V_105 , F_39 ) ;
}
int F_51 ( struct V_102 * V_102 , void * V_103 ,
struct V_153 * V_154 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( ! V_8 -> V_128 && ! V_8 -> V_129 )
return - V_152 ;
if ( V_154 -> type != V_155 )
return - V_23 ;
V_154 -> V_131 . V_156 = V_154 -> V_131 . V_149 = 0 ;
switch ( V_154 -> V_157 ) {
case V_158 :
if ( ! V_8 -> V_128 )
return - V_23 ;
V_154 -> V_131 = V_8 -> V_90 ;
break;
case V_159 :
if ( ! V_8 -> V_128 )
return - V_23 ;
V_154 -> V_131 = V_8 -> V_15 ;
break;
case V_160 :
if ( ! V_8 -> V_128 )
return - V_23 ;
V_154 -> V_131 = V_133 ;
break;
case V_161 :
if ( ! V_8 -> V_129 )
return - V_23 ;
V_154 -> V_131 = V_8 -> V_88 ;
break;
case V_162 :
case V_163 :
if ( ! V_8 -> V_129 )
return - V_23 ;
V_154 -> V_131 = V_8 -> V_60 ;
break;
default:
return - V_23 ;
}
return 0 ;
}
int F_52 ( struct V_102 * V_102 , void * V_164 , struct V_153 * V_165 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
struct V_130 * V_141 = & V_8 -> V_90 ;
struct V_130 * V_142 = & V_8 -> V_88 ;
unsigned V_124 = F_28 ( V_8 -> V_21 ) ? 2 : 1 ;
int V_145 ;
if ( ! V_8 -> V_128 && ! V_8 -> V_129 )
return - V_152 ;
if ( V_165 -> type != V_155 )
return - V_23 ;
switch ( V_165 -> V_157 ) {
case V_158 :
if ( ! V_8 -> V_128 )
return - V_23 ;
V_145 = F_53 ( V_165 -> V_73 , & V_165 -> V_131 ) ;
if ( V_145 )
return V_145 ;
F_37 ( & V_165 -> V_131 , & V_132 ) ;
F_38 ( & V_165 -> V_131 , & V_8 -> V_15 ) ;
if ( V_8 -> V_127 ) {
struct V_130 V_166 = {
0 , 0 ,
V_8 -> V_60 . V_61 * V_135 ,
( V_8 -> V_60 . V_16 / V_124 ) * V_135
} ;
F_38 ( & V_165 -> V_131 , & V_166 ) ;
if ( V_8 -> V_129 ) {
struct V_130 V_167 = {
0 , 0 ,
V_165 -> V_131 . V_61 / V_135 ,
( V_165 -> V_131 . V_16 * V_124 ) / V_135
} ;
struct V_130 V_166 = {
0 , 0 ,
V_165 -> V_131 . V_61 * V_135 ,
( V_165 -> V_131 . V_16 * V_124 ) * V_135
} ;
F_37 ( V_142 , & V_167 ) ;
F_38 ( V_142 , & V_166 ) ;
F_41 ( V_142 , & V_8 -> V_89 ) ;
}
} else if ( V_8 -> V_129 ) {
V_165 -> V_131 . V_149 *= V_124 ;
V_165 -> V_131 . V_16 *= V_124 ;
F_38 ( & V_165 -> V_131 , & V_8 -> V_60 ) ;
F_42 ( V_142 , & V_165 -> V_131 ) ;
F_41 ( V_142 , & V_8 -> V_89 ) ;
V_165 -> V_131 . V_149 /= V_124 ;
V_165 -> V_131 . V_16 /= V_124 ;
} else {
F_42 ( & V_165 -> V_131 , & V_8 -> V_60 ) ;
V_165 -> V_131 . V_16 /= V_124 ;
}
F_41 ( & V_165 -> V_131 , & V_8 -> V_15 ) ;
* V_141 = V_165 -> V_131 ;
break;
case V_161 :
if ( ! V_8 -> V_129 )
return - V_23 ;
V_145 = F_53 ( V_165 -> V_73 , & V_165 -> V_131 ) ;
if ( V_145 )
return V_145 ;
F_37 ( & V_165 -> V_131 , & V_132 ) ;
F_38 ( & V_165 -> V_131 , & V_8 -> V_60 ) ;
F_41 ( & V_165 -> V_131 , & V_8 -> V_89 ) ;
V_165 -> V_131 . V_149 /= V_124 ;
V_165 -> V_131 . V_16 /= V_124 ;
if ( V_8 -> V_127 ) {
struct V_130 V_108 = V_8 -> V_15 ;
struct V_130 V_166 = {
0 , 0 ,
V_165 -> V_131 . V_61 * V_135 ,
V_165 -> V_131 . V_16 * V_135
} ;
struct V_130 V_167 = {
0 , 0 ,
V_165 -> V_131 . V_61 / V_135 ,
V_165 -> V_131 . V_16 / V_135
} ;
F_37 ( & V_108 , & V_167 ) ;
if ( ! V_8 -> V_128 )
F_38 ( & V_108 , & V_166 ) ;
if ( ! F_54 ( & V_8 -> V_15 , & V_108 ) &&
F_40 ( & V_8 -> V_144 ) )
return - V_146 ;
if ( V_8 -> V_128 ) {
F_37 ( V_141 , & V_167 ) ;
F_38 ( V_141 , & V_166 ) ;
}
V_8 -> V_15 = V_108 ;
} else if ( V_8 -> V_128 ) {
struct V_130 V_108 = V_8 -> V_15 ;
F_37 ( & V_108 , & V_165 -> V_131 ) ;
if ( ! F_54 ( & V_8 -> V_15 , & V_108 ) &&
F_40 ( & V_8 -> V_144 ) )
return - V_146 ;
V_8 -> V_15 = V_108 ;
F_42 ( V_141 , & V_165 -> V_131 ) ;
F_41 ( V_141 , & V_8 -> V_15 ) ;
} else {
if ( ! F_54 ( & V_165 -> V_131 , & V_8 -> V_15 ) &&
F_40 ( & V_8 -> V_144 ) )
return - V_146 ;
F_42 ( & V_8 -> V_15 , & V_165 -> V_131 ) ;
F_42 ( V_141 , & V_165 -> V_131 ) ;
V_141 -> V_16 /= V_124 ;
F_41 ( V_141 , & V_8 -> V_15 ) ;
}
V_165 -> V_131 . V_149 *= V_124 ;
V_165 -> V_131 . V_16 *= V_124 ;
if ( V_8 -> V_168 && ( V_142 -> V_61 != V_165 -> V_131 . V_61 ||
V_142 -> V_16 != V_165 -> V_131 . V_16 ) ) {
F_55 ( V_8 -> V_168 ) ;
V_8 -> V_168 = NULL ;
}
* V_142 = V_165 -> V_131 ;
break;
default:
return - V_23 ;
}
return 0 ;
}
int F_56 ( struct V_102 * V_102 , void * V_103 ,
struct V_169 * V_170 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( V_170 -> type != V_155 )
return - V_23 ;
switch ( F_32 ( V_8 ) ) {
case V_99 :
V_170 -> V_171 . V_172 = 11 ;
V_170 -> V_171 . V_173 = 10 ;
break;
case V_100 :
V_170 -> V_171 . V_172 = 54 ;
V_170 -> V_171 . V_173 = 59 ;
break;
case V_101 :
V_170 -> V_171 . V_172 = 1 ;
V_170 -> V_171 . V_173 = 1 ;
break;
}
return 0 ;
}
int F_57 ( struct V_102 * V_102 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
const struct V_130 * V_142 = & V_8 -> V_88 ;
struct V_174 * V_175 = & V_105 -> V_108 . V_175 ;
unsigned V_176 = V_175 -> V_176 ;
if ( ! V_8 -> V_177 )
return - V_23 ;
V_175 -> V_125 . V_149 = V_8 -> V_178 ;
V_175 -> V_125 . V_156 = V_8 -> V_179 ;
V_175 -> V_125 . V_61 = V_142 -> V_61 ;
V_175 -> V_125 . V_16 = V_142 -> V_16 ;
V_175 -> V_176 = V_8 -> V_180 ;
V_175 -> V_32 = V_181 ;
V_175 -> V_182 = V_8 -> V_183 ;
V_175 -> V_184 = V_8 -> V_185 ;
if ( V_176 > V_8 -> V_180 )
V_176 = V_8 -> V_180 ;
if ( V_8 -> V_168 == NULL )
V_175 -> V_186 = NULL ;
else if ( V_175 -> V_186 ) {
if ( F_58 ( V_175 -> V_186 , V_8 -> V_168 ,
( ( V_8 -> V_88 . V_61 + 7 ) / 8 ) * V_8 -> V_88 . V_16 ) )
return - V_187 ;
}
if ( V_176 && V_175 -> V_188 ) {
if ( F_58 ( V_175 -> V_188 , V_8 -> V_189 ,
V_176 * sizeof( V_8 -> V_189 [ 0 ] ) ) )
return - V_187 ;
}
return 0 ;
}
int F_59 ( struct V_102 * V_102 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
const struct V_130 * V_142 = & V_8 -> V_88 ;
struct V_174 * V_175 = & V_105 -> V_108 . V_175 ;
int V_190 , V_191 ;
if ( ! V_8 -> V_177 )
return - V_23 ;
V_175 -> V_125 . V_156 = F_60 ( int , V_175 -> V_125 . V_156 ,
- V_8 -> V_192 , V_8 -> V_192 ) ;
V_175 -> V_125 . V_149 = F_60 ( int , V_175 -> V_125 . V_149 ,
- V_8 -> V_193 , V_8 -> V_193 ) ;
V_175 -> V_125 . V_61 = V_142 -> V_61 ;
V_175 -> V_125 . V_16 = V_142 -> V_16 ;
V_175 -> V_32 = V_181 ;
if ( V_175 -> V_176 && ! V_175 -> V_188 )
V_175 -> V_176 = 0 ;
if ( V_175 -> V_176 > V_194 )
V_175 -> V_176 = V_194 ;
if ( V_175 -> V_176 ) {
if ( F_61 ( V_8 -> V_195 , V_175 -> V_188 ,
V_175 -> V_176 * sizeof( V_8 -> V_189 [ 0 ] ) ) )
return - V_187 ;
for ( V_190 = 0 ; V_190 < V_175 -> V_176 ; V_190 ++ ) {
struct V_130 * V_131 = & V_8 -> V_195 [ V_190 ] . V_196 ;
V_131 -> V_149 = F_60 ( V_197 , V_131 -> V_149 , 0 , V_8 -> V_193 - 1 ) ;
V_131 -> V_16 = F_60 ( V_197 , V_131 -> V_16 , 1 , V_8 -> V_193 - V_131 -> V_149 ) ;
V_131 -> V_156 = F_60 ( V_75 , V_131 -> V_156 , 0 , V_8 -> V_192 - 1 ) ;
V_131 -> V_61 = F_60 ( V_75 , V_131 -> V_61 , 1 , V_8 -> V_192 - V_131 -> V_156 ) ;
}
for ( V_190 = 0 ; V_190 < V_175 -> V_176 - 1 ; V_190 ++ ) {
struct V_130 * V_198 = & V_8 -> V_195 [ V_190 ] . V_196 ;
for ( V_191 = V_190 + 1 ; V_191 < V_175 -> V_176 ; V_191 ++ ) {
struct V_130 * V_199 = & V_8 -> V_195 [ V_191 ] . V_196 ;
if ( F_62 ( V_198 , V_199 ) )
return - V_23 ;
}
}
if ( F_58 ( V_175 -> V_188 , V_8 -> V_195 ,
V_175 -> V_176 * sizeof( V_8 -> V_189 [ 0 ] ) ) )
return - V_187 ;
}
return 0 ;
}
int F_63 ( struct V_102 * V_102 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
const struct V_130 * V_142 = & V_8 -> V_88 ;
struct V_174 * V_175 = & V_105 -> V_108 . V_175 ;
int V_145 = F_59 ( V_102 , V_103 , V_105 ) ;
unsigned V_200 = ( ( V_142 -> V_61 + 7 ) / 8 ) * V_142 -> V_16 ;
unsigned V_201 = V_175 -> V_176 * sizeof( V_8 -> V_189 [ 0 ] ) ;
void * V_202 = NULL ;
if ( V_145 )
return V_145 ;
if ( V_175 -> V_186 ) {
V_202 = F_64 ( V_175 -> V_186 , V_200 ) ;
if ( F_65 ( V_202 ) )
return F_66 ( V_202 ) ;
}
V_8 -> V_178 = V_175 -> V_125 . V_149 ;
V_8 -> V_179 = V_175 -> V_125 . V_156 ;
F_55 ( V_8 -> V_168 ) ;
V_8 -> V_168 = V_202 ;
V_8 -> V_180 = V_175 -> V_176 ;
if ( V_8 -> V_180 )
memcpy ( V_8 -> V_189 , V_8 -> V_195 , V_201 ) ;
V_8 -> V_183 = V_175 -> V_182 ;
V_8 -> V_185 = V_175 -> V_184 ;
return V_145 ;
}
int F_67 ( struct V_102 * V_102 , void * V_164 , unsigned V_190 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( V_190 && ! V_8 -> V_11 -> V_203 ) {
F_4 ( V_8 , 1 , L_7 ) ;
return - V_23 ;
}
V_8 -> V_204 = V_190 ;
return 0 ;
}
int F_68 ( struct V_102 * V_102 , void * V_164 ,
struct V_205 * V_206 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
V_206 -> V_207 = V_208 |
V_209 |
V_210 |
V_211 |
V_212 |
V_213 |
V_214 |
V_215 ;
V_206 -> V_73 = V_216 | V_8 -> V_217 ;
V_206 -> V_218 = ( void * ) V_8 -> V_219 ;
V_206 -> V_108 . V_61 = V_8 -> V_192 ;
V_206 -> V_108 . V_16 = V_8 -> V_193 ;
if ( V_8 -> V_220 . V_221 . V_222 == 5 )
V_206 -> V_108 . V_110 = V_223 ;
else
V_206 -> V_108 . V_110 = V_224 ;
V_206 -> V_108 . V_118 = V_8 -> V_225 ;
V_206 -> V_108 . V_119 = V_206 -> V_108 . V_16 * V_206 -> V_108 . V_118 ;
V_206 -> V_108 . V_32 = V_77 ;
V_206 -> V_108 . V_112 = V_81 ;
V_206 -> V_108 . V_103 = 0 ;
return 0 ;
}
int F_69 ( struct V_102 * V_102 , void * V_164 ,
const struct V_205 * V_206 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
const unsigned V_226 = V_227 |
V_228 ;
const unsigned V_229 = V_230 |
V_231 |
V_232 ;
if ( ( V_206 -> V_73 & V_226 ) == V_226 )
return - V_23 ;
switch ( V_206 -> V_73 & V_229 ) {
case 0 :
case V_230 :
case V_231 :
case V_232 :
break;
default:
return - V_23 ;
}
V_8 -> V_217 &= ~ ( V_226 | V_229 ) ;
V_8 -> V_217 = V_206 -> V_73 & ( V_226 | V_229 ) ;
return 0 ;
}
int F_70 ( struct V_102 * V_102 , void * V_103 ,
struct V_233 * V_234 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( V_234 -> V_235 >= V_8 -> V_236 )
return - V_23 ;
V_234 -> type = V_237 ;
switch ( V_8 -> V_56 [ V_234 -> V_235 ] ) {
case V_58 :
snprintf ( V_234 -> V_238 , sizeof( V_234 -> V_238 ) , L_8 ,
V_8 -> V_239 [ V_234 -> V_235 ] ) ;
V_234 -> V_240 = V_241 ;
if ( V_8 -> V_242 )
V_234 -> V_243 = ( 1 << F_71 ( V_244 ) ) - 1 ;
V_234 -> V_245 = V_246 ;
break;
case V_72 :
snprintf ( V_234 -> V_238 , sizeof( V_234 -> V_238 ) , L_9 ,
V_8 -> V_239 [ V_234 -> V_235 ] ) ;
V_234 -> V_245 = V_247 ;
break;
}
return 0 ;
}
int F_72 ( struct V_102 * V_102 , void * V_103 , unsigned * V_248 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
* V_248 = V_8 -> V_57 ;
return 0 ;
}
int F_73 ( struct V_102 * V_102 , void * V_103 , unsigned V_248 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( V_248 >= V_8 -> V_236 )
return - V_23 ;
if ( V_248 == V_8 -> V_57 )
return 0 ;
if ( F_40 ( & V_8 -> V_144 ) || F_40 ( & V_8 -> V_249 ) )
return - V_146 ;
V_8 -> V_57 = V_248 ;
V_8 -> V_250 = 0 ;
if ( V_8 -> V_56 [ V_248 ] == V_58 )
V_8 -> V_251 . V_252 = V_241 ;
else
V_8 -> V_251 . V_252 = 0 ;
V_8 -> V_253 . V_252 = V_8 -> V_251 . V_252 ;
F_23 ( V_8 ) ;
return 0 ;
}
int F_74 ( struct V_102 * V_102 , void * V_164 , struct V_254 * V_255 )
{
if ( V_255 -> V_235 >= F_71 ( V_244 ) )
return - V_23 ;
* V_255 = V_244 [ V_255 -> V_235 ] ;
return 0 ;
}
int F_75 ( struct V_102 * V_102 , void * V_164 , struct V_254 * V_255 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( ! F_30 ( V_8 ) )
return - V_23 ;
* V_255 = V_244 [ V_8 -> V_250 ] ;
return 0 ;
}
int F_76 ( struct V_102 * V_102 , void * V_164 , const struct V_254 * V_255 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( ! F_30 ( V_8 ) )
return - V_23 ;
if ( V_255 -> V_235 >= F_71 ( V_244 ) )
return - V_23 ;
V_8 -> V_250 = V_255 -> V_235 ;
return 0 ;
}
int F_77 ( struct V_102 * V_102 , void * V_103 , T_2 V_256 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( ! F_30 ( V_8 ) )
return - V_257 ;
if ( V_8 -> V_62 == V_256 )
return 0 ;
if ( F_40 ( & V_8 -> V_144 ) || F_40 ( & V_8 -> V_249 ) )
return - V_146 ;
V_8 -> V_62 = V_256 ;
F_23 ( V_8 ) ;
return 0 ;
}
static bool F_78 ( struct V_258 * V_259 )
{
struct V_52 * V_53 = & V_259 -> V_53 ;
if ( ( V_53 -> V_260 & ( V_261 | V_262 ) ) &&
F_79 ( V_259 , & V_263 , NULL , NULL ) )
return true ;
return false ;
}
int F_80 ( struct V_102 * V_102 , void * V_264 ,
struct V_258 * V_259 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( ! F_31 ( V_8 ) )
return - V_257 ;
if ( ! F_81 ( V_259 , & V_263 ,
0 , NULL , NULL ) &&
! F_78 ( V_259 ) )
return - V_23 ;
if ( F_82 ( V_259 , & V_8 -> V_54 , 0 , true ) )
return 0 ;
if ( F_40 ( & V_8 -> V_144 ) )
return - V_146 ;
V_8 -> V_54 = * V_259 ;
F_23 ( V_8 ) ;
return 0 ;
}
int F_83 ( struct V_102 * V_102 , void * V_103 ,
struct V_265 * V_266 )
{
struct V_7 * V_8 = F_34 ( V_102 ) ;
if ( V_266 -> type != ( V_8 -> V_151 ?
V_267 :
V_155 ) )
return - V_23 ;
V_266 -> V_266 . V_57 . V_207 = V_268 ;
V_266 -> V_266 . V_57 . V_269 = V_8 -> V_64 ;
V_266 -> V_266 . V_57 . V_270 = 1 ;
return 0 ;
}
int F_84 ( struct V_271 * V_164 ,
const struct V_272 * V_273 )
{
switch ( V_273 -> type ) {
case V_274 :
return F_85 ( V_164 , V_273 ) ;
case V_275 :
if ( V_164 -> V_276 -> V_277 == V_278 )
return F_86 ( V_164 , V_273 ) ;
break;
default:
break;
}
return - V_23 ;
}
