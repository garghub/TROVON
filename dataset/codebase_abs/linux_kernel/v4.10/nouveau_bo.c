static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
int V_11 = V_4 - V_10 -> V_12 . V_4 ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_14 ) ;
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_17 * V_12 = & V_16 -> V_12 . V_18 [ V_11 ] ;
F_3 ( & V_4 -> V_19 ) ;
if ( V_12 -> V_7 )
F_4 ( V_16 , V_11 , V_12 ) ;
if ( V_7 )
F_5 ( V_16 , V_11 , V_5 , V_6 , V_7 , V_8 , V_12 ) ;
F_6 ( V_16 , V_11 , V_12 ) ;
}
static struct V_3 *
F_7 ( struct V_1 * V_2 , int V_11 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_3 * V_12 = & V_10 -> V_12 . V_4 [ V_11 ] ;
F_8 ( & V_10 -> V_12 . V_20 ) ;
if ( ! V_12 -> V_21 &&
( ! V_12 -> V_19 || F_9 ( V_12 -> V_19 ) ) )
V_12 -> V_21 = true ;
else
V_12 = NULL ;
F_10 ( & V_10 -> V_12 . V_20 ) ;
return V_12 ;
}
static void
F_11 ( struct V_1 * V_2 , struct V_3 * V_12 ,
struct V_22 * V_19 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
if ( V_12 ) {
F_8 ( & V_10 -> V_12 . V_20 ) ;
V_12 -> V_19 = (struct V_23 * ) F_12 ( V_19 ) ;
V_12 -> V_21 = false ;
F_10 ( & V_10 -> V_12 . V_20 ) ;
}
}
static struct V_3 *
F_13 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_15 * V_16 = F_14 ( & V_10 -> V_14 ) ;
struct V_3 * V_12 , * V_24 = NULL ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_16 -> V_12 . V_25 ; V_11 ++ ) {
V_12 = F_7 ( V_2 , V_11 ) ;
if ( V_7 && ! V_24 ) {
V_24 = V_12 ;
continue;
} else if ( V_12 && V_16 -> V_12 . V_18 [ V_11 ] . V_7 ) {
F_1 ( V_2 , V_12 , 0 , 0 , 0 , 0 ) ;
}
F_11 ( V_2 , V_12 , NULL ) ;
}
if ( V_24 )
F_1 ( V_2 , V_24 , V_5 , V_6 ,
V_7 , V_8 ) ;
return V_24 ;
}
static void
F_15 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = F_16 ( V_27 -> V_28 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_29 * V_30 = V_29 ( V_27 ) ;
if ( F_17 ( V_30 -> V_31 . V_32 ) )
F_18 ( L_1 , V_27 ) ;
F_19 ( V_30 -> V_33 > 0 ) ;
F_11 ( V_2 , V_30 -> V_12 , NULL ) ;
F_20 ( V_30 ) ;
}
static void
F_21 ( struct V_29 * V_30 , T_1 V_8 ,
int * V_34 , int * V_6 )
{
struct V_9 * V_10 = F_16 ( V_30 -> V_27 . V_28 ) ;
struct V_35 * V_14 = & V_10 -> V_14 ;
if ( V_14 -> V_36 . V_37 < V_38 ) {
if ( V_30 -> V_39 ) {
if ( V_14 -> V_36 . V_40 >= 0x40 ) {
* V_34 = 65536 ;
* V_6 = F_22 ( * V_6 , 64 * V_30 -> V_39 ) ;
} else if ( V_14 -> V_36 . V_40 >= 0x30 ) {
* V_34 = 32768 ;
* V_6 = F_22 ( * V_6 , 64 * V_30 -> V_39 ) ;
} else if ( V_14 -> V_36 . V_40 >= 0x20 ) {
* V_34 = 16384 ;
* V_6 = F_22 ( * V_6 , 64 * V_30 -> V_39 ) ;
} else if ( V_14 -> V_36 . V_40 >= 0x10 ) {
* V_34 = 16384 ;
* V_6 = F_22 ( * V_6 , 32 * V_30 -> V_39 ) ;
}
}
} else {
* V_6 = F_22 ( * V_6 , ( 1 << V_30 -> V_41 ) ) ;
* V_34 = F_23 ( ( 1 << V_30 -> V_41 ) , * V_34 ) ;
}
* V_6 = F_22 ( * V_6 , V_42 ) ;
}
int
F_24 ( struct V_1 * V_2 , int V_6 , int V_34 ,
T_2 V_8 , T_2 V_39 , T_2 V_43 ,
struct V_44 * V_45 , struct V_46 * V_47 ,
struct V_29 * * V_48 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_29 * V_30 ;
T_3 V_49 ;
int V_50 ;
int type = V_51 ;
int V_52 = 12 ;
int V_53 ;
if ( V_10 -> V_54 . V_55 )
V_52 = V_10 -> V_54 . V_55 -> V_56 -> V_52 ;
V_53 = V_57 & ~ ( ( 1 << V_52 ) - 1 ) ;
if ( V_6 <= 0 || V_6 > V_53 ) {
F_25 ( V_10 , L_2 , ( T_1 ) V_6 ) ;
return - V_58 ;
}
if ( V_45 )
type = V_59 ;
V_30 = F_26 ( sizeof( struct V_29 ) , V_60 ) ;
if ( ! V_30 )
return - V_61 ;
F_27 ( & V_30 -> V_62 ) ;
F_27 ( & V_30 -> V_63 ) ;
F_27 ( & V_30 -> V_64 ) ;
V_30 -> V_39 = V_39 ;
V_30 -> V_43 = V_43 ;
V_30 -> V_27 . V_28 = & V_10 -> V_65 . V_28 ;
if ( ! F_2 ( & V_10 -> V_14 ) -> V_66 -> V_67 )
V_30 -> V_68 = V_8 & V_69 ;
V_30 -> V_41 = 12 ;
if ( V_10 -> V_54 . V_55 ) {
if ( ! ( V_8 & V_70 ) && V_6 > 256 * 1024 )
V_30 -> V_41 = V_10 -> V_54 . V_55 -> V_56 -> V_52 ;
}
F_21 ( V_30 , V_8 , & V_34 , & V_6 ) ;
V_30 -> V_27 . V_71 . V_72 = V_6 >> V_73 ;
F_28 ( V_30 , V_8 , 0 ) ;
V_49 = F_29 ( & V_10 -> V_65 . V_28 , V_6 ,
sizeof( struct V_29 ) ) ;
V_50 = F_30 ( & V_10 -> V_65 . V_28 , & V_30 -> V_27 , V_6 ,
type , & V_30 -> V_74 ,
V_34 >> V_73 , false , NULL , V_49 , V_45 ,
V_47 , F_15 ) ;
if ( V_50 ) {
return V_50 ;
}
* V_48 = V_30 ;
return 0 ;
}
static void
F_31 ( struct V_75 * V_76 , unsigned * V_77 , T_2 type , T_2 V_8 )
{
* V_77 = 0 ;
if ( type & V_78 )
V_76 [ ( * V_77 ) ++ ] . V_8 = V_78 | V_8 ;
if ( type & V_70 )
V_76 [ ( * V_77 ) ++ ] . V_8 = V_70 | V_8 ;
if ( type & V_79 )
V_76 [ ( * V_77 ) ++ ] . V_8 = V_79 | V_8 ;
}
static void
F_32 ( struct V_29 * V_30 , T_2 type )
{
struct V_9 * V_10 = F_16 ( V_30 -> V_27 . V_28 ) ;
T_1 V_80 = V_10 -> V_14 . V_36 . V_81 >> V_73 ;
unsigned V_11 , V_82 , V_83 ;
if ( V_10 -> V_14 . V_36 . V_37 == V_84 &&
V_30 -> V_39 && ( type & V_78 ) &&
V_30 -> V_27 . V_71 . V_72 < V_80 / 4 ) {
if ( V_30 -> V_43 & V_85 ) {
V_82 = V_80 / 2 ;
V_83 = ~ 0 ;
} else {
V_82 = 0 ;
V_83 = V_80 / 2 ;
}
for ( V_11 = 0 ; V_11 < V_30 -> V_74 . V_86 ; ++ V_11 ) {
V_30 -> V_87 [ V_11 ] . V_82 = V_82 ;
V_30 -> V_87 [ V_11 ] . V_83 = V_83 ;
}
for ( V_11 = 0 ; V_11 < V_30 -> V_74 . V_88 ; ++ V_11 ) {
V_30 -> V_89 [ V_11 ] . V_82 = V_82 ;
V_30 -> V_89 [ V_11 ] . V_83 = V_83 ;
}
}
}
void
F_28 ( struct V_29 * V_30 , T_2 type , T_2 V_90 )
{
struct V_91 * V_76 = & V_30 -> V_74 ;
T_2 V_8 = ( V_30 -> V_68 ? V_69 :
V_92 ) |
( V_30 -> V_33 ? V_93 : 0 ) ;
V_76 -> V_74 = V_30 -> V_87 ;
F_31 ( V_30 -> V_87 , & V_76 -> V_86 ,
type , V_8 ) ;
V_76 -> V_94 = V_30 -> V_89 ;
F_31 ( V_30 -> V_89 , & V_76 -> V_88 ,
type | V_90 , V_8 ) ;
F_32 ( V_30 , type ) ;
}
int
F_33 ( struct V_29 * V_30 , T_2 V_95 , bool V_96 )
{
struct V_9 * V_10 = F_16 ( V_30 -> V_27 . V_28 ) ;
struct V_26 * V_27 = & V_30 -> V_27 ;
bool V_97 = false , V_98 = false ;
int V_50 ;
V_50 = F_34 ( V_27 , false , false , NULL ) ;
if ( V_50 )
return V_50 ;
if ( V_10 -> V_14 . V_36 . V_37 >= V_38 &&
V_95 == V_78 && V_96 ) {
if ( V_30 -> V_43 & V_99 ) {
if ( V_27 -> V_71 . V_100 == V_101 ) {
struct V_102 * V_71 = V_27 -> V_71 . V_103 ;
if ( ! F_35 ( & V_71 -> V_25 ) )
V_98 = true ;
}
V_30 -> V_43 &= ~ V_99 ;
V_97 = true ;
}
}
if ( V_30 -> V_33 ) {
if ( ! ( V_95 & ( 1 << V_27 -> V_71 . V_100 ) ) || V_98 ) {
F_36 ( V_10 , L_3
L_4 , V_27 ,
1 << V_27 -> V_71 . V_100 , V_95 ) ;
V_50 = - V_104 ;
}
V_30 -> V_33 ++ ;
goto V_105;
}
if ( V_98 ) {
F_28 ( V_30 , V_70 , 0 ) ;
V_50 = F_37 ( V_30 , false , false ) ;
if ( V_50 )
goto V_105;
}
V_30 -> V_33 ++ ;
F_28 ( V_30 , V_95 , 0 ) ;
V_30 -> V_33 -- ;
V_50 = F_37 ( V_30 , false , false ) ;
if ( V_50 )
goto V_105;
V_30 -> V_33 ++ ;
switch ( V_27 -> V_71 . V_100 ) {
case V_101 :
V_10 -> V_31 . V_106 -= V_27 -> V_71 . V_6 ;
break;
case V_107 :
V_10 -> V_31 . V_108 -= V_27 -> V_71 . V_6 ;
break;
default:
break;
}
V_105:
if ( V_97 && V_50 )
V_30 -> V_43 |= V_99 ;
F_38 ( V_27 ) ;
return V_50 ;
}
int
F_39 ( struct V_29 * V_30 )
{
struct V_9 * V_10 = F_16 ( V_30 -> V_27 . V_28 ) ;
struct V_26 * V_27 = & V_30 -> V_27 ;
int V_50 , V_109 ;
V_50 = F_34 ( V_27 , false , false , NULL ) ;
if ( V_50 )
return V_50 ;
V_109 = -- V_30 -> V_33 ;
F_40 ( V_109 < 0 ) ;
if ( V_109 )
goto V_105;
F_28 ( V_30 , V_27 -> V_71 . V_74 , 0 ) ;
V_50 = F_37 ( V_30 , false , false ) ;
if ( V_50 == 0 ) {
switch ( V_27 -> V_71 . V_100 ) {
case V_101 :
V_10 -> V_31 . V_106 += V_27 -> V_71 . V_6 ;
break;
case V_107 :
V_10 -> V_31 . V_108 += V_27 -> V_71 . V_6 ;
break;
default:
break;
}
}
V_105:
F_38 ( V_27 ) ;
return V_50 ;
}
int
F_41 ( struct V_29 * V_30 )
{
int V_50 ;
V_50 = F_34 ( & V_30 -> V_27 , false , false , NULL ) ;
if ( V_50 )
return V_50 ;
V_50 = F_42 ( & V_30 -> V_27 , 0 , V_30 -> V_27 . V_71 . V_72 , & V_30 -> V_110 ) ;
F_38 ( & V_30 -> V_27 ) ;
return V_50 ;
}
void
F_43 ( struct V_29 * V_30 )
{
if ( ! V_30 )
return;
F_44 ( & V_30 -> V_110 ) ;
}
void
F_45 ( struct V_29 * V_30 )
{
struct V_9 * V_10 = F_16 ( V_30 -> V_27 . V_28 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_14 ) ;
struct V_111 * V_112 = (struct V_111 * ) V_30 -> V_27 . V_65 ;
int V_11 ;
if ( ! V_112 )
return;
if ( V_30 -> V_68 )
return;
for ( V_11 = 0 ; V_11 < V_112 -> V_65 . V_72 ; V_11 ++ )
F_46 ( V_14 -> V_2 , V_112 -> V_113 [ V_11 ] ,
V_42 , V_114 ) ;
}
void
F_47 ( struct V_29 * V_30 )
{
struct V_9 * V_10 = F_16 ( V_30 -> V_27 . V_28 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_14 ) ;
struct V_111 * V_112 = (struct V_111 * ) V_30 -> V_27 . V_65 ;
int V_11 ;
if ( ! V_112 )
return;
if ( V_30 -> V_68 )
return;
for ( V_11 = 0 ; V_11 < V_112 -> V_65 . V_72 ; V_11 ++ )
F_48 ( V_14 -> V_2 , V_112 -> V_113 [ V_11 ] ,
V_42 , V_115 ) ;
}
int
F_37 ( struct V_29 * V_30 , bool V_116 ,
bool V_117 )
{
int V_50 ;
V_50 = F_49 ( & V_30 -> V_27 , & V_30 -> V_74 ,
V_116 , V_117 ) ;
if ( V_50 )
return V_50 ;
F_45 ( V_30 ) ;
return 0 ;
}
void
F_50 ( struct V_29 * V_30 , unsigned V_118 , T_4 V_119 )
{
bool V_120 ;
T_4 * V_71 = F_51 ( & V_30 -> V_110 , & V_120 ) ;
V_71 += V_118 ;
if ( V_120 )
F_52 ( V_119 , ( void V_121 V_122 * ) V_71 ) ;
else
* V_71 = V_119 ;
}
T_1
F_53 ( struct V_29 * V_30 , unsigned V_118 )
{
bool V_120 ;
T_1 * V_71 = F_51 ( & V_30 -> V_110 , & V_120 ) ;
V_71 += V_118 ;
if ( V_120 )
return F_54 ( ( void V_121 V_122 * ) V_71 ) ;
else
return * V_71 ;
}
void
F_55 ( struct V_29 * V_30 , unsigned V_118 , T_1 V_119 )
{
bool V_120 ;
T_1 * V_71 = F_51 ( & V_30 -> V_110 , & V_120 ) ;
V_71 += V_118 ;
if ( V_120 )
F_56 ( V_119 , ( void V_121 V_122 * ) V_71 ) ;
else
* V_71 = V_119 ;
}
static struct V_123 *
F_57 ( struct V_124 * V_28 , unsigned long V_6 ,
T_2 V_125 , struct V_126 * V_127 )
{
#if F_58 ( V_128 )
struct V_9 * V_10 = F_16 ( V_28 ) ;
if ( V_10 -> V_129 . V_130 ) {
return F_59 ( V_28 , V_10 -> V_129 . V_130 , V_6 ,
V_125 , V_127 ) ;
}
#endif
return F_60 ( V_28 , V_6 , V_125 , V_127 ) ;
}
static int
F_61 ( struct V_124 * V_28 , T_2 V_8 )
{
return 0 ;
}
static int
F_62 ( struct V_124 * V_28 , T_2 type ,
struct V_131 * V_132 )
{
struct V_9 * V_10 = F_16 ( V_28 ) ;
switch ( type ) {
case V_133 :
V_132 -> V_8 = V_134 ;
V_132 -> V_135 = V_92 ;
V_132 -> V_136 = V_137 ;
break;
case V_101 :
V_132 -> V_8 = V_138 |
V_134 ;
V_132 -> V_135 = V_69 |
V_139 ;
V_132 -> V_136 = V_139 ;
if ( V_10 -> V_14 . V_36 . V_37 >= V_38 ) {
if ( F_63 ( & V_10 -> V_14 ) -> V_140 ) {
V_132 -> V_135 = V_69 ;
V_132 -> V_136 = V_69 ;
}
V_132 -> V_66 = & V_141 ;
V_132 -> V_142 = false ;
V_132 -> V_143 = true ;
} else {
V_132 -> V_66 = & V_144 ;
}
break;
case V_107 :
if ( V_10 -> V_14 . V_36 . V_37 >= V_38 )
V_132 -> V_66 = & V_145 ;
else
if ( ! V_10 -> V_129 . V_130 )
V_132 -> V_66 = & V_146 ;
else
V_132 -> V_66 = & V_144 ;
if ( V_10 -> V_129 . V_130 ) {
V_132 -> V_8 = V_134 ;
V_132 -> V_135 = V_69 |
V_139 ;
V_132 -> V_136 = V_139 ;
} else {
V_132 -> V_8 = V_134 |
V_147 ;
V_132 -> V_135 = V_92 ;
V_132 -> V_136 = V_137 ;
}
break;
default:
return - V_58 ;
}
return 0 ;
}
static void
F_64 ( struct V_26 * V_27 , struct V_91 * V_76 )
{
struct V_29 * V_30 = V_29 ( V_27 ) ;
switch ( V_27 -> V_71 . V_100 ) {
case V_101 :
F_28 ( V_30 , V_70 ,
V_79 ) ;
break;
default:
F_28 ( V_30 , V_79 , 0 ) ;
break;
}
* V_76 = V_30 -> V_74 ;
}
static int
F_65 ( struct V_148 * V_149 , T_1 V_150 )
{
int V_50 = F_66 ( V_149 , 2 ) ;
if ( V_50 == 0 ) {
F_67 ( V_149 , V_151 , 0x0000 , 1 ) ;
F_68 ( V_149 , V_150 & 0x0000ffff ) ;
F_69 ( V_149 ) ;
}
return V_50 ;
}
static int
F_70 ( struct V_148 * V_149 , struct V_26 * V_27 ,
struct V_152 * V_153 , struct V_152 * V_154 )
{
struct V_102 * V_155 = V_153 -> V_103 ;
int V_50 = F_66 ( V_149 , 10 ) ;
if ( V_50 == 0 ) {
F_67 ( V_149 , V_151 , 0x0400 , 8 ) ;
F_68 ( V_149 , F_71 ( V_155 -> V_156 [ 0 ] . V_157 ) ) ;
F_68 ( V_149 , F_72 ( V_155 -> V_156 [ 0 ] . V_157 ) ) ;
F_68 ( V_149 , F_71 ( V_155 -> V_156 [ 1 ] . V_157 ) ) ;
F_68 ( V_149 , F_72 ( V_155 -> V_156 [ 1 ] . V_157 ) ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_154 -> V_72 ) ;
F_73 ( V_149 , V_151 , 0x0300 , 0x0386 ) ;
}
return V_50 ;
}
static int
F_74 ( struct V_148 * V_149 , T_1 V_150 )
{
int V_50 = F_66 ( V_149 , 2 ) ;
if ( V_50 == 0 ) {
F_67 ( V_149 , V_151 , 0x0000 , 1 ) ;
F_68 ( V_149 , V_150 ) ;
}
return V_50 ;
}
static int
F_75 ( struct V_148 * V_149 , struct V_26 * V_27 ,
struct V_152 * V_153 , struct V_152 * V_154 )
{
struct V_102 * V_155 = V_153 -> V_103 ;
T_5 V_158 = V_155 -> V_156 [ 0 ] . V_157 ;
T_5 V_159 = V_155 -> V_156 [ 1 ] . V_157 ;
T_1 V_160 = V_154 -> V_72 ;
int V_50 ;
V_160 = V_154 -> V_72 ;
while ( V_160 ) {
int V_161 = ( V_160 > 8191 ) ? 8191 : V_160 ;
V_50 = F_66 ( V_149 , 11 ) ;
if ( V_50 )
return V_50 ;
F_67 ( V_149 , V_151 , 0x030c , 8 ) ;
F_68 ( V_149 , F_71 ( V_158 ) ) ;
F_68 ( V_149 , F_72 ( V_158 ) ) ;
F_68 ( V_149 , F_71 ( V_159 ) ) ;
F_68 ( V_149 , F_72 ( V_159 ) ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_161 ) ;
F_67 ( V_149 , V_151 , 0x0300 , 1 ) ;
F_68 ( V_149 , 0x00000110 ) ;
V_160 -= V_161 ;
V_158 += ( V_42 * V_161 ) ;
V_159 += ( V_42 * V_161 ) ;
}
return 0 ;
}
static int
F_76 ( struct V_148 * V_149 , struct V_26 * V_27 ,
struct V_152 * V_153 , struct V_152 * V_154 )
{
struct V_102 * V_155 = V_153 -> V_103 ;
T_5 V_158 = V_155 -> V_156 [ 0 ] . V_157 ;
T_5 V_159 = V_155 -> V_156 [ 1 ] . V_157 ;
T_1 V_160 = V_154 -> V_72 ;
int V_50 ;
V_160 = V_154 -> V_72 ;
while ( V_160 ) {
int V_161 = ( V_160 > 2047 ) ? 2047 : V_160 ;
V_50 = F_66 ( V_149 , 12 ) ;
if ( V_50 )
return V_50 ;
F_67 ( V_149 , V_151 , 0x0238 , 2 ) ;
F_68 ( V_149 , F_71 ( V_159 ) ) ;
F_68 ( V_149 , F_72 ( V_159 ) ) ;
F_67 ( V_149 , V_151 , 0x030c , 6 ) ;
F_68 ( V_149 , F_71 ( V_158 ) ) ;
F_68 ( V_149 , F_72 ( V_158 ) ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_161 ) ;
F_67 ( V_149 , V_151 , 0x0300 , 1 ) ;
F_68 ( V_149 , 0x00100110 ) ;
V_160 -= V_161 ;
V_158 += ( V_42 * V_161 ) ;
V_159 += ( V_42 * V_161 ) ;
}
return 0 ;
}
static int
F_77 ( struct V_148 * V_149 , struct V_26 * V_27 ,
struct V_152 * V_153 , struct V_152 * V_154 )
{
struct V_102 * V_155 = V_153 -> V_103 ;
T_5 V_158 = V_155 -> V_156 [ 0 ] . V_157 ;
T_5 V_159 = V_155 -> V_156 [ 1 ] . V_157 ;
T_1 V_160 = V_154 -> V_72 ;
int V_50 ;
V_160 = V_154 -> V_72 ;
while ( V_160 ) {
int V_161 = ( V_160 > 8191 ) ? 8191 : V_160 ;
V_50 = F_66 ( V_149 , 11 ) ;
if ( V_50 )
return V_50 ;
F_78 ( V_149 , V_151 , 0x030c , 8 ) ;
F_68 ( V_149 , F_71 ( V_158 ) ) ;
F_68 ( V_149 , F_72 ( V_158 ) ) ;
F_68 ( V_149 , F_71 ( V_159 ) ) ;
F_68 ( V_149 , F_72 ( V_159 ) ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_161 ) ;
F_78 ( V_149 , V_151 , 0x0300 , 1 ) ;
F_68 ( V_149 , 0x00000110 ) ;
V_160 -= V_161 ;
V_158 += ( V_42 * V_161 ) ;
V_159 += ( V_42 * V_161 ) ;
}
return 0 ;
}
static int
F_79 ( struct V_148 * V_149 , struct V_26 * V_27 ,
struct V_152 * V_153 , struct V_152 * V_154 )
{
struct V_102 * V_155 = V_153 -> V_103 ;
int V_50 = F_66 ( V_149 , 7 ) ;
if ( V_50 == 0 ) {
F_78 ( V_149 , V_151 , 0x0320 , 6 ) ;
F_68 ( V_149 , F_71 ( V_155 -> V_156 [ 0 ] . V_157 ) ) ;
F_68 ( V_149 , F_72 ( V_155 -> V_156 [ 0 ] . V_157 ) ) ;
F_68 ( V_149 , F_71 ( V_155 -> V_156 [ 1 ] . V_157 ) ) ;
F_68 ( V_149 , F_72 ( V_155 -> V_156 [ 1 ] . V_157 ) ) ;
F_68 ( V_149 , 0x00000000 ) ;
F_68 ( V_149 , V_154 -> V_72 << V_73 ) ;
}
return V_50 ;
}
static int
F_80 ( struct V_148 * V_149 , struct V_26 * V_27 ,
struct V_152 * V_153 , struct V_152 * V_154 )
{
struct V_102 * V_155 = V_153 -> V_103 ;
int V_50 = F_66 ( V_149 , 7 ) ;
if ( V_50 == 0 ) {
F_78 ( V_149 , V_151 , 0x0304 , 6 ) ;
F_68 ( V_149 , V_154 -> V_72 << V_73 ) ;
F_68 ( V_149 , F_71 ( V_155 -> V_156 [ 0 ] . V_157 ) ) ;
F_68 ( V_149 , F_72 ( V_155 -> V_156 [ 0 ] . V_157 ) ) ;
F_68 ( V_149 , F_71 ( V_155 -> V_156 [ 1 ] . V_157 ) ) ;
F_68 ( V_149 , F_72 ( V_155 -> V_156 [ 1 ] . V_157 ) ) ;
F_68 ( V_149 , 0x00000000 ) ;
}
return V_50 ;
}
static int
F_81 ( struct V_148 * V_149 , T_1 V_150 )
{
int V_50 = F_66 ( V_149 , 6 ) ;
if ( V_50 == 0 ) {
F_78 ( V_149 , V_151 , 0x0000 , 1 ) ;
F_68 ( V_149 , V_150 ) ;
F_78 ( V_149 , V_151 , 0x0180 , 3 ) ;
F_68 ( V_149 , V_149 -> V_10 -> V_162 . V_150 ) ;
F_68 ( V_149 , V_149 -> V_163 . V_150 ) ;
F_68 ( V_149 , V_149 -> V_163 . V_150 ) ;
}
return V_50 ;
}
static int
F_82 ( struct V_148 * V_149 , struct V_26 * V_27 ,
struct V_152 * V_153 , struct V_152 * V_154 )
{
struct V_102 * V_155 = V_153 -> V_103 ;
T_5 V_164 = ( V_154 -> V_72 << V_73 ) ;
T_5 V_158 = V_155 -> V_156 [ 0 ] . V_157 ;
T_5 V_159 = V_155 -> V_156 [ 1 ] . V_157 ;
int V_165 = ! ! V_155 -> V_95 ;
int V_166 = ! ! ( (struct V_102 * ) V_154 -> V_103 ) -> V_95 ;
int V_50 ;
while ( V_164 ) {
T_1 V_167 , V_168 , V_169 ;
V_50 = F_66 ( V_149 , 18 + 6 * ( V_165 + V_166 ) ) ;
if ( V_50 )
return V_50 ;
V_167 = F_83 ( V_164 , ( T_5 ) ( 4 * 1024 * 1024 ) ) ;
V_168 = 16 * 4 ;
V_169 = V_167 / V_168 ;
if ( V_165 ) {
F_78 ( V_149 , V_151 , 0x0200 , 7 ) ;
F_68 ( V_149 , 0 ) ;
F_68 ( V_149 , 0 ) ;
F_68 ( V_149 , V_168 ) ;
F_68 ( V_149 , V_169 ) ;
F_68 ( V_149 , 1 ) ;
F_68 ( V_149 , 0 ) ;
F_68 ( V_149 , 0 ) ;
} else {
F_78 ( V_149 , V_151 , 0x0200 , 1 ) ;
F_68 ( V_149 , 1 ) ;
}
if ( V_166 ) {
F_78 ( V_149 , V_151 , 0x021c , 7 ) ;
F_68 ( V_149 , 0 ) ;
F_68 ( V_149 , 0 ) ;
F_68 ( V_149 , V_168 ) ;
F_68 ( V_149 , V_169 ) ;
F_68 ( V_149 , 1 ) ;
F_68 ( V_149 , 0 ) ;
F_68 ( V_149 , 0 ) ;
} else {
F_78 ( V_149 , V_151 , 0x021c , 1 ) ;
F_68 ( V_149 , 1 ) ;
}
F_78 ( V_149 , V_151 , 0x0238 , 2 ) ;
F_68 ( V_149 , F_71 ( V_158 ) ) ;
F_68 ( V_149 , F_71 ( V_159 ) ) ;
F_78 ( V_149 , V_151 , 0x030c , 8 ) ;
F_68 ( V_149 , F_72 ( V_158 ) ) ;
F_68 ( V_149 , F_72 ( V_159 ) ) ;
F_68 ( V_149 , V_168 ) ;
F_68 ( V_149 , V_168 ) ;
F_68 ( V_149 , V_168 ) ;
F_68 ( V_149 , V_169 ) ;
F_68 ( V_149 , 0x00000101 ) ;
F_68 ( V_149 , 0x00000000 ) ;
F_78 ( V_149 , V_151 , V_170 , 1 ) ;
F_68 ( V_149 , 0 ) ;
V_164 -= V_167 ;
V_158 += V_167 ;
V_159 += V_167 ;
}
return 0 ;
}
static int
F_84 ( struct V_148 * V_149 , T_1 V_150 )
{
int V_50 = F_66 ( V_149 , 4 ) ;
if ( V_50 == 0 ) {
F_78 ( V_149 , V_151 , 0x0000 , 1 ) ;
F_68 ( V_149 , V_150 ) ;
F_78 ( V_149 , V_151 , 0x0180 , 1 ) ;
F_68 ( V_149 , V_149 -> V_10 -> V_162 . V_150 ) ;
}
return V_50 ;
}
static inline T_2
F_85 ( struct V_26 * V_27 ,
struct V_148 * V_149 , struct V_152 * V_71 )
{
if ( V_71 -> V_100 == V_107 )
return V_171 ;
return V_149 -> V_163 . V_150 ;
}
static int
F_86 ( struct V_148 * V_149 , struct V_26 * V_27 ,
struct V_152 * V_153 , struct V_152 * V_154 )
{
T_1 V_158 = V_153 -> V_172 << V_73 ;
T_1 V_159 = V_154 -> V_172 << V_73 ;
T_1 V_160 = V_154 -> V_72 ;
int V_50 ;
V_50 = F_66 ( V_149 , 3 ) ;
if ( V_50 )
return V_50 ;
F_78 ( V_149 , V_151 , V_173 , 2 ) ;
F_68 ( V_149 , F_85 ( V_27 , V_149 , V_153 ) ) ;
F_68 ( V_149 , F_85 ( V_27 , V_149 , V_154 ) ) ;
V_160 = V_154 -> V_72 ;
while ( V_160 ) {
int V_161 = ( V_160 > 2047 ) ? 2047 : V_160 ;
V_50 = F_66 ( V_149 , 11 ) ;
if ( V_50 )
return V_50 ;
F_78 ( V_149 , V_151 ,
V_174 , 8 ) ;
F_68 ( V_149 , V_158 ) ;
F_68 ( V_149 , V_159 ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_42 ) ;
F_68 ( V_149 , V_161 ) ;
F_68 ( V_149 , 0x00000101 ) ;
F_68 ( V_149 , 0x00000000 ) ;
F_78 ( V_149 , V_151 , V_170 , 1 ) ;
F_68 ( V_149 , 0 ) ;
V_160 -= V_161 ;
V_158 += ( V_42 * V_161 ) ;
V_159 += ( V_42 * V_161 ) ;
}
return 0 ;
}
static int
F_87 ( struct V_9 * V_10 , struct V_26 * V_27 ,
struct V_152 * V_71 )
{
struct V_102 * V_175 = V_27 -> V_71 . V_103 ;
struct V_102 * V_176 = V_71 -> V_103 ;
T_5 V_6 = ( T_5 ) V_71 -> V_72 << V_73 ;
int V_50 ;
V_50 = F_88 ( V_10 -> V_54 . V_55 , V_6 , V_175 -> V_41 ,
V_177 , & V_175 -> V_156 [ 0 ] ) ;
if ( V_50 )
return V_50 ;
V_50 = F_88 ( V_10 -> V_54 . V_55 , V_6 , V_176 -> V_41 ,
V_177 , & V_175 -> V_156 [ 1 ] ) ;
if ( V_50 ) {
F_89 ( & V_175 -> V_156 [ 0 ] ) ;
return V_50 ;
}
F_90 ( & V_175 -> V_156 [ 0 ] , V_175 ) ;
F_90 ( & V_175 -> V_156 [ 1 ] , V_176 ) ;
return 0 ;
}
static int
F_91 ( struct V_26 * V_27 , int V_98 , bool V_178 ,
bool V_117 , struct V_152 * V_154 )
{
struct V_9 * V_10 = F_16 ( V_27 -> V_28 ) ;
struct V_148 * V_149 = V_10 -> V_65 . V_149 ;
struct V_179 * V_180 = ( void * ) V_149 -> V_181 . V_54 ;
struct V_23 * V_19 ;
int V_50 ;
if ( V_10 -> V_14 . V_36 . V_37 >= V_38 ) {
V_50 = F_87 ( V_10 , V_27 , V_154 ) ;
if ( V_50 )
return V_50 ;
}
F_92 ( & V_180 -> V_182 , V_183 ) ;
V_50 = F_93 ( V_29 ( V_27 ) , V_149 , true , V_178 ) ;
if ( V_50 == 0 ) {
V_50 = V_10 -> V_65 . V_184 ( V_149 , V_27 , & V_27 -> V_71 , V_154 ) ;
if ( V_50 == 0 ) {
V_50 = F_94 ( V_149 , false , & V_19 ) ;
if ( V_50 == 0 ) {
V_50 = F_95 ( V_27 ,
& V_19 -> V_185 ,
V_98 ,
V_154 ) ;
F_3 ( & V_19 ) ;
}
}
}
F_96 ( & V_180 -> V_182 ) ;
return V_50 ;
}
void
F_97 ( struct V_9 * V_10 )
{
static const struct {
const char * V_186 ;
int V_187 ;
T_6 V_188 ;
int (* F_98)( struct V_148 * ,
struct V_26 * ,
struct V_152 * , struct V_152 * );
int (* F_99)( struct V_148 * , T_1 V_150 );
} V_189 [] = {
{ L_5 , 4 , 0xc1b5 , F_70 , F_65 } ,
{ L_6 , 0 , 0xc1b5 , F_70 , F_74 } ,
{ L_5 , 4 , 0xc0b5 , F_70 , F_65 } ,
{ L_6 , 0 , 0xc0b5 , F_70 , F_74 } ,
{ L_5 , 4 , 0xb0b5 , F_70 , F_65 } ,
{ L_6 , 0 , 0xb0b5 , F_70 , F_74 } ,
{ L_5 , 4 , 0xa0b5 , F_70 , F_65 } ,
{ L_6 , 0 , 0xa0b5 , F_70 , F_74 } ,
{ L_7 , 5 , 0x90b8 , F_75 , F_74 } ,
{ L_8 , 4 , 0x90b5 , F_75 , F_74 } ,
{ L_5 , 0 , 0x85b5 , F_77 , F_81 } ,
{ L_9 , 0 , 0x74c1 , F_80 , F_81 } ,
{ L_10 , 0 , 0x9039 , F_76 , F_74 } ,
{ L_10 , 0 , 0x5039 , F_82 , F_81 } ,
{ L_10 , 0 , 0x0039 , F_86 , F_84 } ,
{} ,
{ L_9 , 0 , 0x88b4 , F_79 , F_81 } ,
} , * V_190 = V_189 ;
const char * V_186 = L_11 ;
int V_50 ;
do {
struct V_148 * V_149 ;
if ( V_190 -> V_187 )
V_149 = V_10 -> V_191 ;
else
V_149 = V_10 -> V_192 ;
if ( V_149 == NULL )
continue;
V_50 = F_100 ( & V_149 -> V_181 ,
V_190 -> V_188 | ( V_190 -> V_187 << 16 ) ,
V_190 -> V_188 , NULL , 0 ,
& V_10 -> V_65 . V_193 ) ;
if ( V_50 == 0 ) {
V_50 = V_190 -> F_99 ( V_149 , V_10 -> V_65 . V_193 . V_150 ) ;
if ( V_50 ) {
F_101 ( & V_10 -> V_65 . V_193 ) ;
continue;
}
V_10 -> V_65 . V_184 = V_190 -> F_98 ;
V_10 -> V_65 . V_149 = V_149 ;
V_186 = V_190 -> V_186 ;
break;
}
} while ( ( ++ V_190 ) -> F_98 );
F_102 ( V_10 , L_12 , V_186 ) ;
}
static int
F_103 ( struct V_26 * V_27 , bool V_98 , bool V_178 ,
bool V_117 , struct V_152 * V_154 )
{
struct V_75 V_194 = {
. V_82 = 0 ,
. V_83 = 0 ,
. V_8 = V_70 | V_92
} ;
struct V_91 V_74 ;
struct V_152 V_195 ;
int V_50 ;
V_74 . V_86 = V_74 . V_88 = 1 ;
V_74 . V_74 = V_74 . V_94 = & V_194 ;
V_195 = * V_154 ;
V_195 . V_103 = NULL ;
V_50 = F_104 ( V_27 , & V_74 , & V_195 , V_178 , V_117 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_105 ( V_27 -> V_65 , & V_195 ) ;
if ( V_50 )
goto V_105;
V_50 = F_91 ( V_27 , true , V_178 , V_117 , & V_195 ) ;
if ( V_50 )
goto V_105;
V_50 = F_106 ( V_27 , V_178 , V_117 , V_154 ) ;
V_105:
F_107 ( V_27 , & V_195 ) ;
return V_50 ;
}
static int
F_108 ( struct V_26 * V_27 , bool V_98 , bool V_178 ,
bool V_117 , struct V_152 * V_154 )
{
struct V_75 V_194 = {
. V_82 = 0 ,
. V_83 = 0 ,
. V_8 = V_70 | V_92
} ;
struct V_91 V_74 ;
struct V_152 V_195 ;
int V_50 ;
V_74 . V_86 = V_74 . V_88 = 1 ;
V_74 . V_74 = V_74 . V_94 = & V_194 ;
V_195 = * V_154 ;
V_195 . V_103 = NULL ;
V_50 = F_104 ( V_27 , & V_74 , & V_195 , V_178 , V_117 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_106 ( V_27 , V_178 , V_117 , & V_195 ) ;
if ( V_50 )
goto V_105;
V_50 = F_91 ( V_27 , true , V_178 , V_117 , V_154 ) ;
if ( V_50 )
goto V_105;
V_105:
F_107 ( V_27 , & V_195 ) ;
return V_50 ;
}
static void
F_109 ( struct V_26 * V_27 , struct V_152 * V_154 )
{
struct V_29 * V_30 = V_29 ( V_27 ) ;
struct V_196 * V_156 ;
if ( V_27 -> V_197 != F_15 )
return;
F_110 (vma, &nvbo->vma_list, head) {
if ( V_154 && V_154 -> V_100 != V_133 &&
( V_154 -> V_100 == V_101 ||
V_30 -> V_41 != V_156 -> V_55 -> V_56 -> V_52 ) ) {
F_90 ( V_156 , V_154 -> V_103 ) ;
} else {
F_19 ( F_111 ( V_27 , false , false ) ) ;
F_112 ( V_156 ) ;
}
}
}
static int
F_113 ( struct V_26 * V_27 , struct V_152 * V_154 ,
struct V_3 * * V_198 )
{
struct V_9 * V_10 = F_16 ( V_27 -> V_28 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_29 * V_30 = V_29 ( V_27 ) ;
T_5 V_157 = V_154 -> V_172 << V_73 ;
* V_198 = NULL ;
if ( V_154 -> V_100 != V_101 )
return 0 ;
if ( V_10 -> V_14 . V_36 . V_37 >= V_84 ) {
* V_198 = F_13 ( V_2 , V_157 , V_154 -> V_6 ,
V_30 -> V_39 ,
V_30 -> V_43 ) ;
}
return 0 ;
}
static void
F_114 ( struct V_26 * V_27 ,
struct V_3 * V_198 ,
struct V_3 * * V_199 )
{
struct V_9 * V_10 = F_16 ( V_27 -> V_28 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_22 * V_19 = F_115 ( V_27 -> V_200 ) ;
F_11 ( V_2 , * V_199 , V_19 ) ;
* V_199 = V_198 ;
}
static int
F_116 ( struct V_26 * V_27 , bool V_98 , bool V_178 ,
bool V_117 , struct V_152 * V_154 )
{
struct V_9 * V_10 = F_16 ( V_27 -> V_28 ) ;
struct V_29 * V_30 = V_29 ( V_27 ) ;
struct V_152 * V_153 = & V_27 -> V_71 ;
struct V_3 * V_198 = NULL ;
int V_50 = 0 ;
V_50 = F_111 ( V_27 , V_178 , V_117 ) ;
if ( V_50 )
return V_50 ;
if ( V_30 -> V_33 )
F_25 ( V_10 , L_13 , V_30 ) ;
if ( V_10 -> V_14 . V_36 . V_37 < V_38 ) {
V_50 = F_113 ( V_27 , V_154 , & V_198 ) ;
if ( V_50 )
return V_50 ;
}
if ( V_153 -> V_100 == V_133 && ! V_27 -> V_65 ) {
F_117 ( V_27 -> V_71 . V_103 != NULL ) ;
V_27 -> V_71 = * V_154 ;
V_154 -> V_103 = NULL ;
goto V_105;
}
if ( V_10 -> V_65 . V_184 ) {
if ( V_154 -> V_100 == V_133 )
V_50 = F_103 ( V_27 , V_98 , V_178 ,
V_117 , V_154 ) ;
else if ( V_153 -> V_100 == V_133 )
V_50 = F_108 ( V_27 , V_98 , V_178 ,
V_117 , V_154 ) ;
else
V_50 = F_91 ( V_27 , V_98 , V_178 ,
V_117 , V_154 ) ;
if ( ! V_50 )
goto V_105;
}
V_50 = F_111 ( V_27 , V_178 , V_117 ) ;
if ( V_50 == 0 )
V_50 = F_118 ( V_27 , V_178 , V_117 , V_154 ) ;
V_105:
if ( V_10 -> V_14 . V_36 . V_37 < V_38 ) {
if ( V_50 )
F_114 ( V_27 , NULL , & V_198 ) ;
else
F_114 ( V_27 , V_198 , & V_30 -> V_12 ) ;
}
return V_50 ;
}
static int
F_119 ( struct V_26 * V_27 , struct V_201 * V_32 )
{
struct V_29 * V_30 = V_29 ( V_27 ) ;
return F_120 ( & V_30 -> V_31 . V_202 ,
V_32 -> V_203 ) ;
}
static int
F_121 ( struct V_124 * V_28 , struct V_152 * V_71 )
{
struct V_131 * V_132 = & V_28 -> V_132 [ V_71 -> V_100 ] ;
struct V_9 * V_10 = F_16 ( V_28 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_14 ) ;
struct V_102 * V_155 = V_71 -> V_103 ;
int V_50 ;
V_71 -> V_204 . V_5 = NULL ;
V_71 -> V_204 . V_157 = 0 ;
V_71 -> V_204 . V_6 = V_71 -> V_72 << V_73 ;
V_71 -> V_204 . V_185 = 0 ;
V_71 -> V_204 . V_120 = false ;
if ( ! ( V_132 -> V_8 & V_134 ) )
return - V_58 ;
switch ( V_71 -> V_100 ) {
case V_133 :
return 0 ;
case V_107 :
#if F_58 ( V_128 )
if ( V_10 -> V_129 . V_130 ) {
V_71 -> V_204 . V_157 = V_71 -> V_172 << V_73 ;
V_71 -> V_204 . V_185 = V_10 -> V_129 . V_185 ;
V_71 -> V_204 . V_120 = ! V_10 -> V_129 . V_205 ;
}
#endif
if ( V_10 -> V_14 . V_36 . V_37 < V_38 || ! V_155 -> V_95 )
break;
case V_101 :
V_71 -> V_204 . V_157 = V_71 -> V_172 << V_73 ;
V_71 -> V_204 . V_185 = V_14 -> V_66 -> V_206 ( V_14 , 1 ) ;
V_71 -> V_204 . V_120 = true ;
if ( V_10 -> V_14 . V_36 . V_37 >= V_38 ) {
struct V_207 * V_208 = F_63 ( & V_10 -> V_14 ) ;
int V_41 = 12 ;
if ( V_10 -> V_14 . V_36 . V_37 >= V_209 )
V_41 = V_155 -> V_41 ;
V_50 = F_122 ( V_208 , V_155 -> V_6 << 12 , V_41 ,
& V_155 -> V_210 ) ;
if ( V_50 )
return V_50 ;
F_90 ( & V_155 -> V_210 , V_155 ) ;
V_71 -> V_204 . V_157 = V_155 -> V_210 . V_157 ;
}
break;
default:
return - V_58 ;
}
return 0 ;
}
static void
F_123 ( struct V_124 * V_28 , struct V_152 * V_71 )
{
struct V_102 * V_155 = V_71 -> V_103 ;
if ( ! V_155 -> V_210 . V_155 )
return;
F_112 ( & V_155 -> V_210 ) ;
F_89 ( & V_155 -> V_210 ) ;
}
static int
F_124 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = F_16 ( V_27 -> V_28 ) ;
struct V_29 * V_30 = V_29 ( V_27 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_14 ) ;
T_1 V_211 = V_14 -> V_66 -> V_212 ( V_14 , 1 ) >> V_73 ;
int V_11 , V_50 ;
if ( V_27 -> V_71 . V_100 != V_101 ) {
if ( V_10 -> V_14 . V_36 . V_37 < V_38 ||
! F_125 ( V_30 ) )
return 0 ;
if ( V_27 -> V_71 . V_100 == V_133 ) {
F_28 ( V_30 , V_107 , 0 ) ;
V_50 = F_37 ( V_30 , false , false ) ;
if ( V_50 )
return V_50 ;
}
return 0 ;
}
if ( V_10 -> V_14 . V_36 . V_37 >= V_38 ||
V_27 -> V_71 . V_172 + V_27 -> V_71 . V_72 < V_211 )
return 0 ;
for ( V_11 = 0 ; V_11 < V_30 -> V_74 . V_86 ; ++ V_11 ) {
V_30 -> V_87 [ V_11 ] . V_82 = 0 ;
V_30 -> V_87 [ V_11 ] . V_83 = V_211 ;
}
for ( V_11 = 0 ; V_11 < V_30 -> V_74 . V_88 ; ++ V_11 ) {
V_30 -> V_89 [ V_11 ] . V_82 = 0 ;
V_30 -> V_89 [ V_11 ] . V_83 = V_211 ;
}
F_28 ( V_30 , V_78 , 0 ) ;
return F_37 ( V_30 , false , false ) ;
}
static int
F_126 ( struct V_123 * V_65 )
{
struct V_111 * V_112 = ( void * ) V_65 ;
struct V_9 * V_10 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_14 * V_213 ;
unsigned V_11 ;
int V_214 ;
bool V_215 = ! ! ( V_65 -> V_125 & V_216 ) ;
if ( V_65 -> V_217 != V_218 )
return 0 ;
if ( V_215 && V_65 -> V_45 ) {
F_127 ( V_65 -> V_45 , V_65 -> V_219 ,
V_112 -> V_113 , V_65 -> V_72 ) ;
V_65 -> V_217 = V_220 ;
return 0 ;
}
V_10 = F_16 ( V_65 -> V_28 ) ;
V_14 = F_2 ( & V_10 -> V_14 ) ;
V_2 = V_10 -> V_2 ;
V_213 = V_14 -> V_2 ;
#if F_58 ( V_128 )
if ( V_10 -> V_129 . V_130 ) {
return F_128 ( V_65 ) ;
}
#endif
#if F_58 ( V_221 ) && F_58 ( V_222 )
if ( F_129 () ) {
return F_130 ( ( void * ) V_65 , V_2 -> V_2 ) ;
}
#endif
V_214 = F_131 ( V_65 ) ;
if ( V_214 ) {
return V_214 ;
}
for ( V_11 = 0 ; V_11 < V_65 -> V_72 ; V_11 ++ ) {
T_7 V_5 ;
V_5 = F_132 ( V_213 , V_65 -> V_219 [ V_11 ] , 0 , V_42 ,
V_223 ) ;
if ( F_133 ( V_213 , V_5 ) ) {
while ( V_11 -- ) {
F_134 ( V_213 , V_112 -> V_113 [ V_11 ] ,
V_42 , V_223 ) ;
V_112 -> V_113 [ V_11 ] = 0 ;
}
F_135 ( V_65 ) ;
return - V_224 ;
}
V_112 -> V_113 [ V_11 ] = V_5 ;
}
return 0 ;
}
static void
F_136 ( struct V_123 * V_65 )
{
struct V_111 * V_112 = ( void * ) V_65 ;
struct V_9 * V_10 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_14 * V_213 ;
unsigned V_11 ;
bool V_215 = ! ! ( V_65 -> V_125 & V_216 ) ;
if ( V_215 )
return;
V_10 = F_16 ( V_65 -> V_28 ) ;
V_14 = F_2 ( & V_10 -> V_14 ) ;
V_2 = V_10 -> V_2 ;
V_213 = V_14 -> V_2 ;
#if F_58 ( V_128 )
if ( V_10 -> V_129 . V_130 ) {
F_137 ( V_65 ) ;
return;
}
#endif
#if F_58 ( V_221 ) && F_58 ( V_222 )
if ( F_129 () ) {
F_138 ( ( void * ) V_65 , V_2 -> V_2 ) ;
return;
}
#endif
for ( V_11 = 0 ; V_11 < V_65 -> V_72 ; V_11 ++ ) {
if ( V_112 -> V_113 [ V_11 ] ) {
F_134 ( V_213 , V_112 -> V_113 [ V_11 ] , V_42 ,
V_223 ) ;
}
}
F_135 ( V_65 ) ;
}
void
F_139 ( struct V_29 * V_30 , struct V_23 * V_19 , bool V_225 )
{
struct V_46 * V_200 = V_30 -> V_27 . V_200 ;
if ( V_225 )
F_140 ( V_200 , & V_19 -> V_185 ) ;
else if ( V_19 )
F_141 ( V_200 , & V_19 -> V_185 ) ;
}
struct V_196 *
F_142 ( struct V_29 * V_30 , struct V_226 * V_55 )
{
struct V_196 * V_156 ;
F_110 (vma, &nvbo->vma_list, head) {
if ( V_156 -> V_55 == V_55 )
return V_156 ;
}
return NULL ;
}
int
F_143 ( struct V_29 * V_30 , struct V_226 * V_55 ,
struct V_196 * V_156 )
{
const T_1 V_6 = V_30 -> V_27 . V_71 . V_72 << V_73 ;
int V_50 ;
V_50 = F_88 ( V_55 , V_6 , V_30 -> V_41 ,
V_177 , V_156 ) ;
if ( V_50 )
return V_50 ;
if ( V_30 -> V_27 . V_71 . V_100 != V_133 &&
( V_30 -> V_27 . V_71 . V_100 == V_101 ||
V_30 -> V_41 != V_156 -> V_55 -> V_56 -> V_52 ) )
F_90 ( V_156 , V_30 -> V_27 . V_71 . V_103 ) ;
F_144 ( & V_156 -> V_62 , & V_30 -> V_64 ) ;
V_156 -> V_227 = 1 ;
return 0 ;
}
void
F_145 ( struct V_29 * V_30 , struct V_196 * V_156 )
{
if ( V_156 -> V_155 ) {
if ( V_30 -> V_27 . V_71 . V_100 != V_133 )
F_112 ( V_156 ) ;
F_89 ( V_156 ) ;
F_146 ( & V_156 -> V_62 ) ;
}
}
