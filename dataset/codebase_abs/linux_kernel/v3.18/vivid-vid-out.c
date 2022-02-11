static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned * V_5 , unsigned * V_6 ,
unsigned V_7 [] , void * V_8 [] )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
unsigned V_11 = V_10 -> V_12 -> V_11 ;
unsigned V_13 = V_10 -> V_14 . V_15 ;
unsigned V_16 = V_10 -> V_17 [ 0 ] * V_13 ;
if ( V_10 -> V_18 == V_19 ) {
if ( F_3 ( V_2 ) )
return - V_20 ;
}
if ( V_10 -> V_21 ) {
V_10 -> V_21 = false ;
return - V_20 ;
}
if ( V_4 ) {
const struct V_22 * V_23 ;
struct V_3 V_24 ;
if ( ! F_4 ( V_4 -> type ) ) {
F_5 ( V_4 , & V_24 ) ;
V_4 = & V_24 ;
}
V_23 = & V_4 -> V_4 . V_25 ;
if ( V_23 -> V_26 != V_11 )
return - V_20 ;
V_7 [ 0 ] = V_23 -> V_27 [ 0 ] . V_28 ;
if ( V_11 == 2 ) {
V_7 [ 1 ] = V_23 -> V_27 [ 1 ] . V_28 ;
if ( V_7 [ 0 ] < V_10 -> V_17 [ 0 ] * V_13 ||
V_7 [ 1 ] < V_10 -> V_17 [ 1 ] * V_13 )
return - V_20 ;
} else if ( V_7 [ 0 ] < V_16 ) {
return - V_20 ;
}
} else {
if ( V_11 == 2 ) {
V_7 [ 0 ] = V_10 -> V_17 [ 0 ] * V_13 ;
V_7 [ 1 ] = V_10 -> V_17 [ 1 ] * V_13 ;
} else {
V_7 [ 0 ] = V_16 ;
}
}
if ( V_2 -> V_29 + * V_5 < 2 )
* V_5 = 2 - V_2 -> V_29 ;
* V_6 = V_11 ;
if ( V_11 == 2 )
F_6 ( V_10 , 1 , L_1 , V_30 ,
* V_5 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
else
F_6 ( V_10 , 1 , L_2 , V_30 ,
* V_5 , V_7 [ 0 ] ) ;
return 0 ;
}
static int F_7 ( struct V_31 * V_32 )
{
struct V_9 * V_10 = F_2 ( V_32 -> V_1 ) ;
unsigned long V_16 ;
unsigned V_11 = V_10 -> V_12 -> V_11 ;
unsigned V_33 ;
F_6 ( V_10 , 1 , L_3 , V_30 ) ;
if ( F_8 ( NULL == V_10 -> V_12 ) )
return - V_20 ;
if ( V_10 -> V_34 ) {
V_10 -> V_34 = false ;
return - V_20 ;
}
if ( V_10 -> V_18 != V_19 )
V_32 -> V_35 . V_36 = V_10 -> V_18 ;
else if ( V_32 -> V_35 . V_36 != V_37 &&
V_32 -> V_35 . V_36 != V_38 )
return - V_20 ;
for ( V_33 = 0 ; V_33 < V_11 ; V_33 ++ ) {
V_16 = V_10 -> V_17 [ V_33 ] * V_10 -> V_14 . V_15 +
V_32 -> V_39 [ V_33 ] . V_40 ;
if ( F_9 ( V_32 , V_33 ) < V_16 ) {
F_6 ( V_10 , 1 , L_4 ,
V_30 , V_33 , F_9 ( V_32 , V_33 ) , V_16 ) ;
return - V_20 ;
}
}
return 0 ;
}
static void F_10 ( struct V_31 * V_32 )
{
struct V_9 * V_10 = F_2 ( V_32 -> V_1 ) ;
struct V_41 * V_42 = F_11 ( V_32 , struct V_41 , V_32 ) ;
F_6 ( V_10 , 1 , L_3 , V_30 ) ;
F_12 ( & V_10 -> V_43 ) ;
F_13 ( & V_42 -> V_44 , & V_10 -> V_45 ) ;
F_14 ( & V_10 -> V_43 ) ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_46 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_47 ;
if ( F_16 ( & V_10 -> V_48 ) )
V_10 -> V_49 = F_17 ( V_10 ) ;
if ( V_10 -> V_50 )
return 0 ;
V_10 -> V_51 = 0 ;
F_6 ( V_10 , 1 , L_3 , V_30 ) ;
if ( V_10 -> V_52 ) {
V_10 -> V_52 = false ;
V_47 = - V_20 ;
} else {
V_47 = F_18 ( V_10 , & V_10 -> V_53 ) ;
}
if ( V_47 ) {
struct V_41 * V_42 , * V_54 ;
F_19 (buf, tmp, &dev->vid_out_active, list) {
F_20 ( & V_42 -> V_44 ) ;
F_21 ( & V_42 -> V_32 , V_55 ) ;
}
}
return V_47 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_6 ( V_10 , 1 , L_3 , V_30 ) ;
F_23 ( V_10 , & V_10 -> V_53 ) ;
V_10 -> V_49 = false ;
}
void F_24 ( struct V_9 * V_10 )
{
struct V_56 * V_57 = & V_10 -> V_58 . V_57 ;
unsigned V_16 ;
switch ( V_10 -> V_59 [ V_10 -> V_60 ] ) {
case V_61 :
default:
V_10 -> V_18 = V_10 -> V_62 ;
V_10 -> V_63 . V_64 = 720 ;
if ( V_10 -> V_65 & V_66 ) {
V_10 -> V_63 . V_15 = 480 ;
V_10 -> V_67 = (struct V_68 ) { 1001 , 30000 } ;
V_10 -> V_69 = V_70 ;
} else {
V_10 -> V_63 . V_15 = 576 ;
V_10 -> V_67 = (struct V_68 ) { 1000 , 25000 } ;
V_10 -> V_69 = V_71 | V_72 ;
}
V_10 -> V_73 = V_74 ;
break;
case V_75 :
V_10 -> V_63 . V_64 = V_57 -> V_64 ;
V_10 -> V_63 . V_15 = V_57 -> V_15 ;
V_16 = F_25 ( V_57 ) * F_26 ( V_57 ) ;
V_10 -> V_67 = (struct V_68 ) {
V_16 / 100 , ( V_76 ) V_57 -> V_77 / 100
} ;
if ( V_57 -> V_78 )
V_10 -> V_18 = V_19 ;
else
V_10 -> V_18 = V_79 ;
if ( ! V_10 -> V_80 && ( V_57 -> V_81 & V_82 ) ) {
if ( V_57 -> V_64 == 720 && V_57 -> V_15 <= 576 )
V_10 -> V_73 = V_74 ;
else
V_10 -> V_73 = V_83 ;
} else {
V_10 -> V_73 = V_84 ;
}
break;
}
V_10 -> V_85 = V_10 -> V_63 ;
V_10 -> V_86 = V_10 -> V_63 ;
V_10 -> V_87 = V_10 -> V_85 ;
if ( F_27 ( V_10 -> V_18 ) )
V_10 -> V_87 . V_15 /= 2 ;
V_10 -> V_14 = V_10 -> V_87 ;
V_10 -> V_17 [ 0 ] = ( V_10 -> V_63 . V_64 * V_10 -> V_12 -> V_88 ) / 8 ;
if ( V_10 -> V_12 -> V_11 == 2 )
V_10 -> V_17 [ 1 ] = ( V_10 -> V_63 . V_64 * V_10 -> V_12 -> V_88 ) / 8 ;
}
static enum V_89 F_28 ( struct V_9 * V_10 , enum V_89 V_36 )
{
if ( F_29 ( V_10 ) ) {
switch ( V_36 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_19 :
return V_36 ;
case V_94 :
default:
return V_94 ;
}
}
if ( F_30 ( V_10 ) )
return V_10 -> V_58 . V_57 . V_78 ? V_19 :
V_79 ;
return V_79 ;
}
static enum V_95 F_31 ( const struct V_9 * V_10 )
{
if ( F_29 ( V_10 ) )
return ( V_10 -> V_65 & V_66 ) ?
V_96 : V_97 ;
if ( F_30 ( V_10 ) &&
V_10 -> V_63 . V_64 == 720 && V_10 -> V_63 . V_15 <= 576 )
return V_10 -> V_63 . V_15 == 480 ?
V_96 : V_97 ;
return V_98 ;
}
int F_32 ( struct V_99 * V_99 , void * V_100 ,
struct V_3 * V_101 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
struct V_22 * V_23 = & V_101 -> V_4 . V_25 ;
unsigned V_33 ;
V_23 -> V_64 = V_10 -> V_14 . V_64 ;
V_23 -> V_15 = V_10 -> V_14 . V_15 ;
V_23 -> V_36 = V_10 -> V_18 ;
V_23 -> V_102 = V_10 -> V_12 -> V_103 ;
V_23 -> V_104 = V_10 -> V_73 ;
V_23 -> V_26 = V_10 -> V_12 -> V_11 ;
for ( V_33 = 0 ; V_33 < V_23 -> V_26 ; V_33 ++ ) {
V_23 -> V_27 [ V_33 ] . V_105 = V_10 -> V_17 [ V_33 ] ;
V_23 -> V_27 [ V_33 ] . V_28 =
V_23 -> V_27 [ V_33 ] . V_105 * V_23 -> V_15 ;
}
return 0 ;
}
int F_34 ( struct V_99 * V_99 , void * V_100 ,
struct V_3 * V_101 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
struct V_56 * V_57 = & V_10 -> V_58 . V_57 ;
struct V_22 * V_23 = & V_101 -> V_4 . V_25 ;
struct V_106 * V_107 = V_23 -> V_27 ;
const struct V_108 * V_4 ;
unsigned V_105 , V_109 ;
unsigned V_110 = 1 ;
unsigned V_111 , V_13 ;
unsigned V_33 ;
V_4 = F_35 ( V_10 , V_23 -> V_102 ) ;
if ( ! V_4 ) {
F_6 ( V_10 , 1 , L_5 ,
V_23 -> V_102 ) ;
V_23 -> V_102 = V_112 ;
V_4 = F_35 ( V_10 , V_23 -> V_102 ) ;
}
V_23 -> V_36 = F_28 ( V_10 , V_23 -> V_36 ) ;
if ( F_29 ( V_10 ) ) {
V_111 = 720 ;
V_13 = ( V_10 -> V_65 & V_66 ) ? 480 : 576 ;
} else {
V_111 = V_10 -> V_63 . V_64 ;
V_13 = V_10 -> V_63 . V_15 ;
}
if ( F_27 ( V_23 -> V_36 ) )
V_110 = 2 ;
if ( ! V_10 -> V_113 && ! V_10 -> V_114 && ! V_10 -> V_115 ) {
V_23 -> V_64 = V_111 ;
V_23 -> V_15 = V_13 / V_110 ;
} else {
struct V_116 V_117 = { 0 , 0 , V_23 -> V_64 , V_23 -> V_15 * V_110 } ;
F_36 ( & V_117 , & V_118 ) ;
F_37 ( & V_117 , & V_119 ) ;
if ( V_10 -> V_113 && ! V_10 -> V_114 ) {
struct V_116 V_120 = { 0 , 0 , V_121 * V_111 , V_121 * V_13 } ;
F_37 ( & V_117 , & V_120 ) ;
} else if ( ! V_10 -> V_113 && V_10 -> V_115 && ! V_10 -> V_114 ) {
F_37 ( & V_117 , & V_10 -> V_63 ) ;
} else if ( ! V_10 -> V_113 && ! V_10 -> V_115 ) {
F_36 ( & V_117 , & V_10 -> V_63 ) ;
}
V_23 -> V_64 = V_117 . V_64 ;
V_23 -> V_15 = V_117 . V_15 / V_110 ;
}
V_105 = ( V_23 -> V_64 * V_4 -> V_88 ) >> 3 ;
V_109 = ( V_121 * V_122 * V_4 -> V_88 ) >> 3 ;
V_23 -> V_26 = V_4 -> V_11 ;
for ( V_33 = 0 ; V_33 < V_23 -> V_26 ; V_33 ++ ) {
if ( V_107 [ V_33 ] . V_105 > V_109 )
V_107 [ V_33 ] . V_105 = V_109 ;
if ( V_107 [ V_33 ] . V_105 < V_105 )
V_107 [ V_33 ] . V_105 = V_105 ;
V_107 [ V_33 ] . V_28 = V_107 [ V_33 ] . V_105 * V_23 -> V_15 ;
memset ( V_107 [ V_33 ] . V_123 , 0 , sizeof( V_107 [ V_33 ] . V_123 ) ) ;
}
if ( F_29 ( V_10 ) )
V_23 -> V_104 = V_74 ;
else if ( V_10 -> V_80 || ! ( V_57 -> V_81 & V_82 ) )
V_23 -> V_104 = V_84 ;
else if ( V_57 -> V_64 == 720 && V_57 -> V_15 <= 576 )
V_23 -> V_104 = V_74 ;
else if ( V_23 -> V_104 != V_74 &&
V_23 -> V_104 != V_83 &&
V_23 -> V_104 != V_84 )
V_23 -> V_104 = V_83 ;
memset ( V_23 -> V_123 , 0 , sizeof( V_23 -> V_123 ) ) ;
return 0 ;
}
int F_38 ( struct V_99 * V_99 , void * V_100 ,
struct V_3 * V_101 )
{
struct V_22 * V_23 = & V_101 -> V_4 . V_25 ;
struct V_9 * V_10 = F_33 ( V_99 ) ;
struct V_116 * V_124 = & V_10 -> V_87 ;
struct V_116 * V_125 = & V_10 -> V_85 ;
struct V_1 * V_126 = & V_10 -> V_127 ;
int V_128 = F_34 ( V_99 , V_100 , V_101 ) ;
unsigned V_110 = 1 ;
if ( V_128 < 0 )
return V_128 ;
if ( F_39 ( V_126 ) &&
( F_29 ( V_10 ) ||
V_23 -> V_64 != V_10 -> V_14 . V_64 ||
V_23 -> V_15 != V_10 -> V_14 . V_15 ||
V_23 -> V_102 != V_10 -> V_12 -> V_103 ||
V_23 -> V_36 != V_10 -> V_18 ) ) {
F_6 ( V_10 , 1 , L_6 , V_30 ) ;
return - V_129 ;
}
if ( F_39 ( V_126 ) )
goto V_130;
V_10 -> V_12 = F_35 ( V_10 , V_23 -> V_102 ) ;
if ( F_27 ( V_23 -> V_36 ) )
V_110 = 2 ;
if ( V_10 -> V_113 || V_10 -> V_114 || V_10 -> V_115 ) {
struct V_116 V_117 = { 0 , 0 , V_23 -> V_64 , V_23 -> V_15 } ;
if ( V_10 -> V_113 ) {
if ( V_10 -> V_114 )
F_40 ( V_124 , & V_117 ) ;
else
* V_124 = V_117 ;
if ( V_10 -> V_115 && ! V_10 -> V_114 ) {
struct V_116 V_131 = {
0 , 0 ,
V_117 . V_64 / V_121 ,
V_110 * V_117 . V_15 / V_121
} ;
struct V_116 V_120 = {
0 , 0 ,
V_117 . V_64 * V_121 ,
V_110 * V_117 . V_15 * V_121
} ;
F_36 ( V_125 , & V_131 ) ;
F_37 ( V_125 , & V_120 ) ;
F_40 ( V_125 , & V_10 -> V_86 ) ;
} else if ( V_10 -> V_115 ) {
struct V_116 V_131 = {
0 , 0 ,
V_124 -> V_64 / V_121 ,
V_110 * V_124 -> V_15 / V_121
} ;
struct V_116 V_120 = {
0 , 0 ,
V_124 -> V_64 * V_121 ,
V_110 * V_124 -> V_15 * V_121
} ;
F_36 ( V_125 , & V_131 ) ;
F_37 ( V_125 , & V_120 ) ;
F_40 ( V_125 , & V_10 -> V_86 ) ;
}
} else if ( V_10 -> V_115 && ! V_10 -> V_114 ) {
F_41 ( V_124 , & V_117 ) ;
V_117 . V_15 *= V_110 ;
F_41 ( V_125 , & V_117 ) ;
F_40 ( V_125 , & V_10 -> V_86 ) ;
} else if ( ! V_10 -> V_115 ) {
F_40 ( V_124 , & V_117 ) ;
V_117 . V_15 /= V_110 ;
F_41 ( V_125 , & V_117 ) ;
} else {
V_117 . V_15 *= V_110 ;
F_37 ( V_125 , & V_117 ) ;
F_40 ( V_125 , & V_10 -> V_86 ) ;
V_124 -> V_132 *= V_110 ;
V_124 -> V_15 *= V_110 ;
F_41 ( V_124 , V_125 ) ;
F_40 ( V_124 , & V_117 ) ;
V_124 -> V_132 /= V_110 ;
V_124 -> V_15 /= V_110 ;
}
} else {
struct V_116 V_117 = { 0 , 0 , V_23 -> V_64 , V_23 -> V_15 } ;
F_41 ( V_124 , & V_117 ) ;
V_117 . V_15 /= V_110 ;
F_41 ( V_125 , & V_117 ) ;
}
V_10 -> V_14 . V_64 = V_23 -> V_64 ;
V_10 -> V_14 . V_15 = V_23 -> V_15 ;
V_10 -> V_17 [ 0 ] = V_23 -> V_27 [ 0 ] . V_105 ;
if ( V_23 -> V_26 > 1 )
V_10 -> V_17 [ 1 ] = V_23 -> V_27 [ 1 ] . V_105 ;
V_10 -> V_18 = V_23 -> V_36 ;
if ( F_29 ( V_10 ) )
V_10 -> V_62 = V_23 -> V_36 ;
V_130:
V_10 -> V_73 = V_23 -> V_104 ;
if ( V_10 -> V_133 ) {
F_42 ( V_10 , V_61 ) ;
F_42 ( V_10 , V_75 ) ;
}
return 0 ;
}
int F_43 ( struct V_99 * V_99 , void * V_100 ,
struct V_3 * V_101 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( ! V_10 -> V_134 )
return - V_135 ;
return F_32 ( V_99 , V_100 , V_101 ) ;
}
int F_44 ( struct V_99 * V_99 , void * V_100 ,
struct V_3 * V_101 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( ! V_10 -> V_134 )
return - V_135 ;
return F_34 ( V_99 , V_100 , V_101 ) ;
}
int F_45 ( struct V_99 * V_99 , void * V_100 ,
struct V_3 * V_101 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( ! V_10 -> V_134 )
return - V_135 ;
return F_38 ( V_99 , V_100 , V_101 ) ;
}
int F_46 ( struct V_99 * V_99 , void * V_100 ,
struct V_3 * V_101 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( V_10 -> V_134 )
return - V_135 ;
return F_47 ( V_99 , V_100 , V_101 , F_32 ) ;
}
int F_48 ( struct V_99 * V_99 , void * V_100 ,
struct V_3 * V_101 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( V_10 -> V_134 )
return - V_135 ;
return F_47 ( V_99 , V_100 , V_101 , F_34 ) ;
}
int F_49 ( struct V_99 * V_99 , void * V_100 ,
struct V_3 * V_101 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( V_10 -> V_134 )
return - V_135 ;
return F_47 ( V_99 , V_100 , V_101 , F_38 ) ;
}
int F_50 ( struct V_99 * V_99 , void * V_100 ,
struct V_136 * V_137 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( ! V_10 -> V_114 && ! V_10 -> V_115 )
return - V_135 ;
if ( V_137 -> type != V_138 )
return - V_20 ;
V_137 -> V_117 . V_139 = V_137 -> V_117 . V_132 = 0 ;
switch ( V_137 -> V_140 ) {
case V_141 :
if ( ! V_10 -> V_114 )
return - V_20 ;
V_137 -> V_117 = V_10 -> V_87 ;
break;
case V_142 :
if ( ! V_10 -> V_114 )
return - V_20 ;
V_137 -> V_117 = V_10 -> V_14 ;
break;
case V_143 :
if ( ! V_10 -> V_115 )
return - V_20 ;
V_137 -> V_117 = V_119 ;
break;
case V_144 :
if ( ! V_10 -> V_115 )
return - V_20 ;
V_137 -> V_117 = V_10 -> V_85 ;
break;
case V_145 :
case V_146 :
if ( ! V_10 -> V_115 )
return - V_20 ;
V_137 -> V_117 = V_10 -> V_63 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
int F_51 ( struct V_99 * V_99 , void * V_147 , struct V_136 * V_148 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
struct V_116 * V_124 = & V_10 -> V_87 ;
struct V_116 * V_125 = & V_10 -> V_85 ;
unsigned V_110 = F_27 ( V_10 -> V_18 ) ? 2 : 1 ;
int V_128 ;
if ( ! V_10 -> V_114 && ! V_10 -> V_115 )
return - V_135 ;
if ( V_148 -> type != V_138 )
return - V_20 ;
switch ( V_148 -> V_140 ) {
case V_141 :
if ( ! V_10 -> V_114 )
return - V_20 ;
V_128 = F_52 ( V_148 -> V_149 , & V_148 -> V_117 ) ;
if ( V_128 )
return V_128 ;
F_36 ( & V_148 -> V_117 , & V_118 ) ;
F_37 ( & V_148 -> V_117 , & V_10 -> V_14 ) ;
if ( V_10 -> V_113 ) {
struct V_116 V_150 = {
0 , 0 ,
V_10 -> V_63 . V_64 * V_121 ,
( V_10 -> V_63 . V_15 / V_110 ) * V_121
} ;
F_37 ( & V_148 -> V_117 , & V_150 ) ;
if ( V_10 -> V_115 ) {
struct V_116 V_151 = {
0 , 0 ,
V_148 -> V_117 . V_64 / V_121 ,
( V_148 -> V_117 . V_15 * V_110 ) / V_121
} ;
struct V_116 V_150 = {
0 , 0 ,
V_148 -> V_117 . V_64 * V_121 ,
( V_148 -> V_117 . V_15 * V_110 ) * V_121
} ;
F_36 ( V_125 , & V_151 ) ;
F_37 ( V_125 , & V_150 ) ;
F_40 ( V_125 , & V_10 -> V_86 ) ;
}
} else if ( V_10 -> V_115 ) {
V_148 -> V_117 . V_132 *= V_110 ;
V_148 -> V_117 . V_15 *= V_110 ;
F_37 ( & V_148 -> V_117 , & V_10 -> V_63 ) ;
F_41 ( V_125 , & V_148 -> V_117 ) ;
F_40 ( V_125 , & V_10 -> V_86 ) ;
V_148 -> V_117 . V_132 /= V_110 ;
V_148 -> V_117 . V_15 /= V_110 ;
} else {
F_41 ( & V_148 -> V_117 , & V_10 -> V_63 ) ;
V_148 -> V_117 . V_15 /= V_110 ;
}
F_40 ( & V_148 -> V_117 , & V_10 -> V_14 ) ;
* V_124 = V_148 -> V_117 ;
break;
case V_144 :
if ( ! V_10 -> V_115 )
return - V_20 ;
V_128 = F_52 ( V_148 -> V_149 , & V_148 -> V_117 ) ;
if ( V_128 )
return V_128 ;
F_36 ( & V_148 -> V_117 , & V_118 ) ;
F_37 ( & V_148 -> V_117 , & V_10 -> V_63 ) ;
F_40 ( & V_148 -> V_117 , & V_10 -> V_86 ) ;
V_148 -> V_117 . V_132 /= V_110 ;
V_148 -> V_117 . V_15 /= V_110 ;
if ( V_10 -> V_113 ) {
struct V_116 V_4 = V_10 -> V_14 ;
struct V_116 V_150 = {
0 , 0 ,
V_148 -> V_117 . V_64 * V_121 ,
V_148 -> V_117 . V_15 * V_121
} ;
struct V_116 V_151 = {
0 , 0 ,
V_148 -> V_117 . V_64 / V_121 ,
V_148 -> V_117 . V_15 / V_121
} ;
F_36 ( & V_4 , & V_151 ) ;
if ( ! V_10 -> V_114 )
F_37 ( & V_4 , & V_150 ) ;
if ( ! F_53 ( & V_10 -> V_14 , & V_4 ) &&
F_39 ( & V_10 -> V_127 ) )
return - V_129 ;
if ( V_10 -> V_114 ) {
F_36 ( V_124 , & V_151 ) ;
F_37 ( V_124 , & V_150 ) ;
}
V_10 -> V_14 = V_4 ;
} else if ( V_10 -> V_114 ) {
struct V_116 V_4 = V_10 -> V_14 ;
F_36 ( & V_4 , & V_148 -> V_117 ) ;
if ( ! F_53 ( & V_10 -> V_14 , & V_4 ) &&
F_39 ( & V_10 -> V_127 ) )
return - V_129 ;
V_10 -> V_14 = V_4 ;
F_41 ( V_124 , & V_148 -> V_117 ) ;
F_40 ( V_124 , & V_10 -> V_14 ) ;
} else {
if ( ! F_53 ( & V_148 -> V_117 , & V_10 -> V_14 ) &&
F_39 ( & V_10 -> V_127 ) )
return - V_129 ;
F_41 ( & V_10 -> V_14 , & V_148 -> V_117 ) ;
F_41 ( V_124 , & V_148 -> V_117 ) ;
V_124 -> V_15 /= V_110 ;
F_40 ( V_124 , & V_10 -> V_14 ) ;
}
V_148 -> V_117 . V_132 *= V_110 ;
V_148 -> V_117 . V_15 *= V_110 ;
if ( V_10 -> V_152 && ( V_125 -> V_64 != V_148 -> V_117 . V_64 ||
V_125 -> V_15 != V_148 -> V_117 . V_15 ) ) {
F_54 ( V_10 -> V_152 ) ;
V_10 -> V_152 = NULL ;
}
* V_125 = V_148 -> V_117 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
int F_55 ( struct V_99 * V_99 , void * V_100 ,
struct V_153 * V_154 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( V_154 -> type != V_138 )
return - V_20 ;
switch ( F_31 ( V_10 ) ) {
case V_96 :
V_154 -> V_155 . V_156 = 11 ;
V_154 -> V_155 . V_157 = 10 ;
break;
case V_97 :
V_154 -> V_155 . V_156 = 54 ;
V_154 -> V_155 . V_157 = 59 ;
break;
case V_98 :
V_154 -> V_155 . V_156 = 1 ;
V_154 -> V_155 . V_157 = 1 ;
break;
}
return 0 ;
}
int F_56 ( struct V_99 * V_99 , void * V_100 ,
struct V_3 * V_101 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
const struct V_116 * V_125 = & V_10 -> V_85 ;
struct V_158 * V_159 = & V_101 -> V_4 . V_159 ;
unsigned V_160 = V_159 -> V_160 ;
if ( ! V_10 -> V_161 )
return - V_20 ;
V_159 -> V_111 . V_132 = V_10 -> V_162 ;
V_159 -> V_111 . V_139 = V_10 -> V_163 ;
V_159 -> V_111 . V_64 = V_125 -> V_64 ;
V_159 -> V_111 . V_15 = V_125 -> V_15 ;
V_159 -> V_160 = V_10 -> V_164 ;
V_159 -> V_36 = V_165 ;
V_159 -> V_166 = V_10 -> V_167 ;
V_159 -> V_168 = V_10 -> V_169 ;
if ( V_160 > V_10 -> V_164 )
V_160 = V_10 -> V_164 ;
if ( V_10 -> V_152 == NULL )
V_159 -> V_170 = NULL ;
else if ( V_159 -> V_170 ) {
if ( F_57 ( V_159 -> V_170 , V_10 -> V_152 ,
( ( V_10 -> V_85 . V_64 + 7 ) / 8 ) * V_10 -> V_85 . V_15 ) )
return - V_171 ;
}
if ( V_160 && V_159 -> V_172 ) {
if ( F_57 ( V_159 -> V_172 , V_10 -> V_173 ,
V_160 * sizeof( V_10 -> V_173 [ 0 ] ) ) )
return - V_171 ;
}
return 0 ;
}
int F_58 ( struct V_99 * V_99 , void * V_100 ,
struct V_3 * V_101 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
const struct V_116 * V_125 = & V_10 -> V_85 ;
struct V_158 * V_159 = & V_101 -> V_4 . V_159 ;
int V_174 , V_175 ;
if ( ! V_10 -> V_161 )
return - V_20 ;
V_159 -> V_111 . V_139 = F_59 ( int , V_159 -> V_111 . V_139 ,
- V_10 -> V_176 , V_10 -> V_176 ) ;
V_159 -> V_111 . V_132 = F_59 ( int , V_159 -> V_111 . V_132 ,
- V_10 -> V_177 , V_10 -> V_177 ) ;
V_159 -> V_111 . V_64 = V_125 -> V_64 ;
V_159 -> V_111 . V_15 = V_125 -> V_15 ;
V_159 -> V_36 = V_165 ;
if ( V_159 -> V_160 && ! V_159 -> V_172 )
V_159 -> V_160 = 0 ;
if ( V_159 -> V_160 > V_178 )
V_159 -> V_160 = V_178 ;
if ( V_159 -> V_160 ) {
if ( F_60 ( V_10 -> V_179 , V_159 -> V_172 ,
V_159 -> V_160 * sizeof( V_10 -> V_173 [ 0 ] ) ) )
return - V_171 ;
for ( V_174 = 0 ; V_174 < V_159 -> V_160 ; V_174 ++ ) {
struct V_116 * V_117 = & V_10 -> V_179 [ V_174 ] . V_180 ;
V_117 -> V_132 = F_59 ( V_181 , V_117 -> V_132 , 0 , V_10 -> V_177 - 1 ) ;
V_117 -> V_15 = F_59 ( V_181 , V_117 -> V_15 , 1 , V_10 -> V_177 - V_117 -> V_132 ) ;
V_117 -> V_139 = F_59 ( V_76 , V_117 -> V_139 , 0 , V_10 -> V_176 - 1 ) ;
V_117 -> V_64 = F_59 ( V_76 , V_117 -> V_64 , 1 , V_10 -> V_176 - V_117 -> V_139 ) ;
}
for ( V_174 = 0 ; V_174 < V_159 -> V_160 - 1 ; V_174 ++ ) {
struct V_116 * V_182 = & V_10 -> V_179 [ V_174 ] . V_180 ;
for ( V_175 = V_174 + 1 ; V_175 < V_159 -> V_160 ; V_175 ++ ) {
struct V_116 * V_183 = & V_10 -> V_179 [ V_175 ] . V_180 ;
if ( F_61 ( V_182 , V_183 ) )
return - V_20 ;
}
}
if ( F_57 ( V_159 -> V_172 , V_10 -> V_179 ,
V_159 -> V_160 * sizeof( V_10 -> V_173 [ 0 ] ) ) )
return - V_171 ;
}
return 0 ;
}
int F_62 ( struct V_99 * V_99 , void * V_100 ,
struct V_3 * V_101 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
const struct V_116 * V_125 = & V_10 -> V_85 ;
struct V_158 * V_159 = & V_101 -> V_4 . V_159 ;
int V_128 = F_58 ( V_99 , V_100 , V_101 ) ;
unsigned V_184 = ( ( V_125 -> V_64 + 7 ) / 8 ) * V_125 -> V_15 ;
unsigned V_185 = V_159 -> V_160 * sizeof( V_10 -> V_173 [ 0 ] ) ;
void * V_186 = NULL ;
if ( V_128 )
return V_128 ;
if ( V_159 -> V_170 ) {
V_186 = F_63 ( V_159 -> V_170 , V_184 ) ;
if ( F_64 ( V_186 ) )
return F_65 ( V_186 ) ;
}
V_10 -> V_162 = V_159 -> V_111 . V_132 ;
V_10 -> V_163 = V_159 -> V_111 . V_139 ;
F_54 ( V_10 -> V_152 ) ;
V_10 -> V_152 = V_186 ;
V_10 -> V_164 = V_159 -> V_160 ;
if ( V_10 -> V_164 )
memcpy ( V_10 -> V_173 , V_10 -> V_179 , V_185 ) ;
V_10 -> V_167 = V_159 -> V_166 ;
V_10 -> V_169 = V_159 -> V_168 ;
return V_128 ;
}
int F_66 ( struct V_99 * V_99 , void * V_147 , unsigned V_174 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( V_174 && ! V_10 -> V_12 -> V_187 ) {
F_6 ( V_10 , 1 , L_7 ) ;
return - V_20 ;
}
V_10 -> V_188 = V_174 ;
return 0 ;
}
int F_67 ( struct V_99 * V_99 , void * V_147 ,
struct V_189 * V_190 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
V_190 -> V_191 = V_192 |
V_193 |
V_194 |
V_195 |
V_196 |
V_197 |
V_198 |
V_199 ;
V_190 -> V_149 = V_200 | V_10 -> V_201 ;
V_190 -> V_202 = ( void * ) V_10 -> V_203 ;
V_190 -> V_4 . V_64 = V_10 -> V_176 ;
V_190 -> V_4 . V_15 = V_10 -> V_177 ;
if ( V_10 -> V_204 . V_205 . V_206 == 5 )
V_190 -> V_4 . V_102 = V_207 ;
else
V_190 -> V_4 . V_102 = V_208 ;
V_190 -> V_4 . V_105 = V_10 -> V_209 ;
V_190 -> V_4 . V_28 = V_190 -> V_4 . V_15 * V_190 -> V_4 . V_105 ;
V_190 -> V_4 . V_36 = V_79 ;
V_190 -> V_4 . V_104 = V_84 ;
V_190 -> V_4 . V_100 = 0 ;
return 0 ;
}
int F_68 ( struct V_99 * V_99 , void * V_147 ,
const struct V_189 * V_190 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
const unsigned V_210 = V_211 |
V_212 ;
const unsigned V_213 = V_214 |
V_215 |
V_216 ;
if ( ( V_190 -> V_149 & V_210 ) == V_210 )
return - V_20 ;
switch ( V_190 -> V_149 & V_213 ) {
case 0 :
case V_214 :
case V_215 :
case V_216 :
break;
default:
return - V_20 ;
}
V_10 -> V_201 &= ~ ( V_210 | V_213 ) ;
V_10 -> V_201 = V_190 -> V_149 & ( V_210 | V_213 ) ;
return 0 ;
}
int F_69 ( struct V_99 * V_99 , void * V_100 ,
struct V_217 * V_218 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( V_218 -> V_219 >= V_10 -> V_220 )
return - V_20 ;
V_218 -> type = V_221 ;
switch ( V_10 -> V_59 [ V_218 -> V_219 ] ) {
case V_61 :
snprintf ( V_218 -> V_222 , sizeof( V_218 -> V_222 ) , L_8 ,
V_10 -> V_223 [ V_218 -> V_219 ] ) ;
V_218 -> V_224 = V_225 ;
if ( V_10 -> V_226 )
V_218 -> V_227 = ( 1 << F_70 ( V_228 ) ) - 1 ;
V_218 -> V_229 = V_230 ;
break;
case V_75 :
snprintf ( V_218 -> V_222 , sizeof( V_218 -> V_222 ) , L_9 ,
V_10 -> V_223 [ V_218 -> V_219 ] ) ;
V_218 -> V_229 = V_231 ;
break;
}
return 0 ;
}
int F_71 ( struct V_99 * V_99 , void * V_100 , unsigned * V_232 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
* V_232 = V_10 -> V_60 ;
return 0 ;
}
int F_72 ( struct V_99 * V_99 , void * V_100 , unsigned V_232 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( V_232 >= V_10 -> V_220 )
return - V_20 ;
if ( V_232 == V_10 -> V_60 )
return 0 ;
if ( F_39 ( & V_10 -> V_127 ) || F_39 ( & V_10 -> V_233 ) )
return - V_129 ;
V_10 -> V_60 = V_232 ;
V_10 -> V_234 = 0 ;
if ( V_10 -> V_59 [ V_232 ] == V_61 )
V_10 -> V_235 . V_236 = V_225 ;
else
V_10 -> V_235 . V_236 = 0 ;
V_10 -> V_237 . V_236 = V_10 -> V_235 . V_236 ;
F_24 ( V_10 ) ;
return 0 ;
}
int F_73 ( struct V_99 * V_99 , void * V_147 , struct V_238 * V_239 )
{
if ( V_239 -> V_219 >= F_70 ( V_228 ) )
return - V_20 ;
* V_239 = V_228 [ V_239 -> V_219 ] ;
return 0 ;
}
int F_74 ( struct V_99 * V_99 , void * V_147 , struct V_238 * V_239 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( ! F_29 ( V_10 ) )
return - V_20 ;
* V_239 = V_228 [ V_10 -> V_234 ] ;
return 0 ;
}
int F_75 ( struct V_99 * V_99 , void * V_147 , const struct V_238 * V_239 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( ! F_29 ( V_10 ) )
return - V_20 ;
if ( V_239 -> V_219 >= F_70 ( V_228 ) )
return - V_20 ;
V_10 -> V_234 = V_239 -> V_219 ;
return 0 ;
}
int F_76 ( struct V_99 * V_99 , void * V_100 , T_1 V_240 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( ! F_29 ( V_10 ) )
return - V_241 ;
if ( V_10 -> V_65 == V_240 )
return 0 ;
if ( F_39 ( & V_10 -> V_127 ) || F_39 ( & V_10 -> V_233 ) )
return - V_129 ;
V_10 -> V_65 = V_240 ;
F_24 ( V_10 ) ;
return 0 ;
}
int F_77 ( struct V_99 * V_99 , void * V_242 ,
struct V_243 * V_244 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( ! F_30 ( V_10 ) )
return - V_241 ;
if ( F_39 ( & V_10 -> V_127 ) )
return - V_129 ;
if ( ! F_78 ( V_244 , & V_245 ,
0 , NULL , NULL ) )
return - V_20 ;
if ( F_79 ( V_244 , & V_10 -> V_58 , 0 ) )
return 0 ;
V_10 -> V_58 = * V_244 ;
F_24 ( V_10 ) ;
return 0 ;
}
int F_80 ( struct V_99 * V_99 , void * V_100 ,
struct V_246 * V_247 )
{
struct V_9 * V_10 = F_33 ( V_99 ) ;
if ( V_247 -> type != ( V_10 -> V_134 ?
V_248 :
V_138 ) )
return - V_20 ;
V_247 -> V_247 . V_60 . V_191 = V_249 ;
V_247 -> V_247 . V_60 . V_250 = V_10 -> V_67 ;
V_247 -> V_247 . V_60 . V_251 = 1 ;
return 0 ;
}
int F_81 ( struct V_252 * V_147 ,
const struct V_253 * V_254 )
{
switch ( V_254 -> type ) {
case V_255 :
return F_82 ( V_147 , V_254 ) ;
case V_256 :
if ( V_147 -> V_257 -> V_258 == V_259 )
return F_83 ( V_147 , V_254 ) ;
break;
default:
break;
}
return - V_20 ;
}
