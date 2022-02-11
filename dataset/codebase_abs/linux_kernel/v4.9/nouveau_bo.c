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
struct V_19 * V_19 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
if ( V_12 ) {
F_8 ( & V_10 -> V_12 . V_20 ) ;
V_12 -> V_19 = (struct V_22 * ) F_12 ( V_19 ) ;
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
struct V_3 * V_12 , * V_23 = NULL ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_16 -> V_12 . V_24 ; V_11 ++ ) {
V_12 = F_7 ( V_2 , V_11 ) ;
if ( V_7 && ! V_23 ) {
V_23 = V_12 ;
continue;
} else if ( V_12 && V_16 -> V_12 . V_18 [ V_11 ] . V_7 ) {
F_1 ( V_2 , V_12 , 0 , 0 , 0 , 0 ) ;
}
F_11 ( V_2 , V_12 , NULL ) ;
}
if ( V_23 )
F_1 ( V_2 , V_23 , V_5 , V_6 ,
V_7 , V_8 ) ;
return V_23 ;
}
static void
F_15 ( struct V_25 * V_26 )
{
struct V_9 * V_10 = F_16 ( V_26 -> V_27 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_28 * V_29 = V_28 ( V_26 ) ;
if ( F_17 ( V_29 -> V_30 . V_31 ) )
F_18 ( L_1 , V_26 ) ;
F_19 ( V_29 -> V_32 > 0 ) ;
F_11 ( V_2 , V_29 -> V_12 , NULL ) ;
F_20 ( V_29 ) ;
}
static void
F_21 ( struct V_28 * V_29 , T_1 V_8 ,
int * V_33 , int * V_6 )
{
struct V_9 * V_10 = F_16 ( V_29 -> V_26 . V_27 ) ;
struct V_34 * V_14 = & V_10 -> V_14 ;
if ( V_14 -> V_35 . V_36 < V_37 ) {
if ( V_29 -> V_38 ) {
if ( V_14 -> V_35 . V_39 >= 0x40 ) {
* V_33 = 65536 ;
* V_6 = F_22 ( * V_6 , 64 * V_29 -> V_38 ) ;
} else if ( V_14 -> V_35 . V_39 >= 0x30 ) {
* V_33 = 32768 ;
* V_6 = F_22 ( * V_6 , 64 * V_29 -> V_38 ) ;
} else if ( V_14 -> V_35 . V_39 >= 0x20 ) {
* V_33 = 16384 ;
* V_6 = F_22 ( * V_6 , 64 * V_29 -> V_38 ) ;
} else if ( V_14 -> V_35 . V_39 >= 0x10 ) {
* V_33 = 16384 ;
* V_6 = F_22 ( * V_6 , 32 * V_29 -> V_38 ) ;
}
}
} else {
* V_6 = F_22 ( * V_6 , ( 1 << V_29 -> V_40 ) ) ;
* V_33 = F_23 ( ( 1 << V_29 -> V_40 ) , * V_33 ) ;
}
* V_6 = F_22 ( * V_6 , V_41 ) ;
}
int
F_24 ( struct V_1 * V_2 , int V_6 , int V_33 ,
T_2 V_8 , T_2 V_38 , T_2 V_42 ,
struct V_43 * V_44 , struct V_45 * V_46 ,
struct V_28 * * V_47 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_28 * V_29 ;
T_3 V_48 ;
int V_49 ;
int type = V_50 ;
int V_51 = 12 ;
int V_52 ;
if ( V_10 -> V_53 . V_54 )
V_51 = V_10 -> V_53 . V_54 -> V_55 -> V_51 ;
V_52 = V_56 & ~ ( ( 1 << V_51 ) - 1 ) ;
if ( V_6 <= 0 || V_6 > V_52 ) {
F_25 ( V_10 , L_2 , ( T_1 ) V_6 ) ;
return - V_57 ;
}
if ( V_44 )
type = V_58 ;
V_29 = F_26 ( sizeof( struct V_28 ) , V_59 ) ;
if ( ! V_29 )
return - V_60 ;
F_27 ( & V_29 -> V_61 ) ;
F_27 ( & V_29 -> V_62 ) ;
F_27 ( & V_29 -> V_63 ) ;
V_29 -> V_38 = V_38 ;
V_29 -> V_42 = V_42 ;
V_29 -> V_26 . V_27 = & V_10 -> V_64 . V_27 ;
if ( ! F_2 ( & V_10 -> V_14 ) -> V_65 -> V_66 )
V_29 -> V_67 = V_8 & V_68 ;
V_29 -> V_40 = 12 ;
if ( V_10 -> V_53 . V_54 ) {
if ( ! ( V_8 & V_69 ) && V_6 > 256 * 1024 )
V_29 -> V_40 = V_10 -> V_53 . V_54 -> V_55 -> V_51 ;
}
F_21 ( V_29 , V_8 , & V_33 , & V_6 ) ;
V_29 -> V_26 . V_70 . V_71 = V_6 >> V_72 ;
F_28 ( V_29 , V_8 , 0 ) ;
V_48 = F_29 ( & V_10 -> V_64 . V_27 , V_6 ,
sizeof( struct V_28 ) ) ;
V_49 = F_30 ( & V_10 -> V_64 . V_27 , & V_29 -> V_26 , V_6 ,
type , & V_29 -> V_73 ,
V_33 >> V_72 , false , NULL , V_48 , V_44 ,
V_46 , F_15 ) ;
if ( V_49 ) {
return V_49 ;
}
* V_47 = V_29 ;
return 0 ;
}
static void
F_31 ( struct V_74 * V_75 , unsigned * V_76 , T_2 type , T_2 V_8 )
{
* V_76 = 0 ;
if ( type & V_77 )
V_75 [ ( * V_76 ) ++ ] . V_8 = V_77 | V_8 ;
if ( type & V_69 )
V_75 [ ( * V_76 ) ++ ] . V_8 = V_69 | V_8 ;
if ( type & V_78 )
V_75 [ ( * V_76 ) ++ ] . V_8 = V_78 | V_8 ;
}
static void
F_32 ( struct V_28 * V_29 , T_2 type )
{
struct V_9 * V_10 = F_16 ( V_29 -> V_26 . V_27 ) ;
T_1 V_79 = V_10 -> V_14 . V_35 . V_80 >> V_72 ;
unsigned V_11 , V_81 , V_82 ;
if ( V_10 -> V_14 . V_35 . V_36 == V_83 &&
V_29 -> V_38 && ( type & V_77 ) &&
V_29 -> V_26 . V_70 . V_71 < V_79 / 4 ) {
if ( V_29 -> V_42 & V_84 ) {
V_81 = V_79 / 2 ;
V_82 = ~ 0 ;
} else {
V_81 = 0 ;
V_82 = V_79 / 2 ;
}
for ( V_11 = 0 ; V_11 < V_29 -> V_73 . V_85 ; ++ V_11 ) {
V_29 -> V_86 [ V_11 ] . V_81 = V_81 ;
V_29 -> V_86 [ V_11 ] . V_82 = V_82 ;
}
for ( V_11 = 0 ; V_11 < V_29 -> V_73 . V_87 ; ++ V_11 ) {
V_29 -> V_88 [ V_11 ] . V_81 = V_81 ;
V_29 -> V_88 [ V_11 ] . V_82 = V_82 ;
}
}
}
void
F_28 ( struct V_28 * V_29 , T_2 type , T_2 V_89 )
{
struct V_90 * V_75 = & V_29 -> V_73 ;
T_2 V_8 = ( V_29 -> V_67 ? V_68 :
V_91 ) |
( V_29 -> V_32 ? V_92 : 0 ) ;
V_75 -> V_73 = V_29 -> V_86 ;
F_31 ( V_29 -> V_86 , & V_75 -> V_85 ,
type , V_8 ) ;
V_75 -> V_93 = V_29 -> V_88 ;
F_31 ( V_29 -> V_88 , & V_75 -> V_87 ,
type | V_89 , V_8 ) ;
F_32 ( V_29 , type ) ;
}
int
F_33 ( struct V_28 * V_29 , T_2 V_94 , bool V_95 )
{
struct V_9 * V_10 = F_16 ( V_29 -> V_26 . V_27 ) ;
struct V_25 * V_26 = & V_29 -> V_26 ;
bool V_96 = false , V_97 = false ;
int V_49 ;
V_49 = F_34 ( V_26 , false , false , NULL ) ;
if ( V_49 )
return V_49 ;
if ( V_10 -> V_14 . V_35 . V_36 >= V_37 &&
V_94 == V_77 && V_95 ) {
if ( V_29 -> V_42 & V_98 ) {
if ( V_26 -> V_70 . V_99 == V_100 ) {
struct V_101 * V_70 = V_26 -> V_70 . V_102 ;
if ( ! F_35 ( & V_70 -> V_24 ) )
V_97 = true ;
}
V_29 -> V_42 &= ~ V_98 ;
V_96 = true ;
}
}
if ( V_29 -> V_32 ) {
if ( ! ( V_94 & ( 1 << V_26 -> V_70 . V_99 ) ) || V_97 ) {
F_36 ( V_10 , L_3
L_4 , V_26 ,
1 << V_26 -> V_70 . V_99 , V_94 ) ;
V_49 = - V_103 ;
}
V_29 -> V_32 ++ ;
goto V_104;
}
if ( V_97 ) {
F_28 ( V_29 , V_69 , 0 ) ;
V_49 = F_37 ( V_29 , false , false ) ;
if ( V_49 )
goto V_104;
}
V_29 -> V_32 ++ ;
F_28 ( V_29 , V_94 , 0 ) ;
V_29 -> V_32 -- ;
V_49 = F_37 ( V_29 , false , false ) ;
if ( V_49 )
goto V_104;
V_29 -> V_32 ++ ;
switch ( V_26 -> V_70 . V_99 ) {
case V_100 :
V_10 -> V_30 . V_105 -= V_26 -> V_70 . V_6 ;
break;
case V_106 :
V_10 -> V_30 . V_107 -= V_26 -> V_70 . V_6 ;
break;
default:
break;
}
V_104:
if ( V_96 && V_49 )
V_29 -> V_42 |= V_98 ;
F_38 ( V_26 ) ;
return V_49 ;
}
int
F_39 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = F_16 ( V_29 -> V_26 . V_27 ) ;
struct V_25 * V_26 = & V_29 -> V_26 ;
int V_49 , V_108 ;
V_49 = F_34 ( V_26 , false , false , NULL ) ;
if ( V_49 )
return V_49 ;
V_108 = -- V_29 -> V_32 ;
F_40 ( V_108 < 0 ) ;
if ( V_108 )
goto V_104;
F_28 ( V_29 , V_26 -> V_70 . V_73 , 0 ) ;
V_49 = F_37 ( V_29 , false , false ) ;
if ( V_49 == 0 ) {
switch ( V_26 -> V_70 . V_99 ) {
case V_100 :
V_10 -> V_30 . V_105 += V_26 -> V_70 . V_6 ;
break;
case V_106 :
V_10 -> V_30 . V_107 += V_26 -> V_70 . V_6 ;
break;
default:
break;
}
}
V_104:
F_38 ( V_26 ) ;
return V_49 ;
}
int
F_41 ( struct V_28 * V_29 )
{
int V_49 ;
V_49 = F_34 ( & V_29 -> V_26 , false , false , NULL ) ;
if ( V_49 )
return V_49 ;
V_49 = F_42 ( & V_29 -> V_26 , 0 , V_29 -> V_26 . V_70 . V_71 , & V_29 -> V_109 ) ;
F_38 ( & V_29 -> V_26 ) ;
return V_49 ;
}
void
F_43 ( struct V_28 * V_29 )
{
if ( ! V_29 )
return;
F_44 ( & V_29 -> V_109 ) ;
}
void
F_45 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = F_16 ( V_29 -> V_26 . V_27 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_14 ) ;
struct V_110 * V_111 = (struct V_110 * ) V_29 -> V_26 . V_64 ;
int V_11 ;
if ( ! V_111 )
return;
if ( V_29 -> V_67 )
return;
for ( V_11 = 0 ; V_11 < V_111 -> V_64 . V_71 ; V_11 ++ )
F_46 ( V_14 -> V_2 , V_111 -> V_112 [ V_11 ] ,
V_41 , V_113 ) ;
}
void
F_47 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = F_16 ( V_29 -> V_26 . V_27 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_14 ) ;
struct V_110 * V_111 = (struct V_110 * ) V_29 -> V_26 . V_64 ;
int V_11 ;
if ( ! V_111 )
return;
if ( V_29 -> V_67 )
return;
for ( V_11 = 0 ; V_11 < V_111 -> V_64 . V_71 ; V_11 ++ )
F_48 ( V_14 -> V_2 , V_111 -> V_112 [ V_11 ] ,
V_41 , V_114 ) ;
}
int
F_37 ( struct V_28 * V_29 , bool V_115 ,
bool V_116 )
{
int V_49 ;
V_49 = F_49 ( & V_29 -> V_26 , & V_29 -> V_73 ,
V_115 , V_116 ) ;
if ( V_49 )
return V_49 ;
F_45 ( V_29 ) ;
return 0 ;
}
void
F_50 ( struct V_28 * V_29 , unsigned V_117 , T_4 V_118 )
{
bool V_119 ;
T_4 * V_70 = F_51 ( & V_29 -> V_109 , & V_119 ) ;
V_70 += V_117 ;
if ( V_119 )
F_52 ( V_118 , ( void V_120 V_121 * ) V_70 ) ;
else
* V_70 = V_118 ;
}
T_1
F_53 ( struct V_28 * V_29 , unsigned V_117 )
{
bool V_119 ;
T_1 * V_70 = F_51 ( & V_29 -> V_109 , & V_119 ) ;
V_70 += V_117 ;
if ( V_119 )
return F_54 ( ( void V_120 V_121 * ) V_70 ) ;
else
return * V_70 ;
}
void
F_55 ( struct V_28 * V_29 , unsigned V_117 , T_1 V_118 )
{
bool V_119 ;
T_1 * V_70 = F_51 ( & V_29 -> V_109 , & V_119 ) ;
V_70 += V_117 ;
if ( V_119 )
F_56 ( V_118 , ( void V_120 V_121 * ) V_70 ) ;
else
* V_70 = V_118 ;
}
static struct V_122 *
F_57 ( struct V_123 * V_27 , unsigned long V_6 ,
T_2 V_124 , struct V_125 * V_126 )
{
#if F_58 ( V_127 )
struct V_9 * V_10 = F_16 ( V_27 ) ;
if ( V_10 -> V_128 . V_129 ) {
return F_59 ( V_27 , V_10 -> V_128 . V_129 , V_6 ,
V_124 , V_126 ) ;
}
#endif
return F_60 ( V_27 , V_6 , V_124 , V_126 ) ;
}
static int
F_61 ( struct V_123 * V_27 , T_2 V_8 )
{
return 0 ;
}
static int
F_62 ( struct V_123 * V_27 , T_2 type ,
struct V_130 * V_131 )
{
struct V_9 * V_10 = F_16 ( V_27 ) ;
switch ( type ) {
case V_132 :
V_131 -> V_8 = V_133 ;
V_131 -> V_134 = V_91 ;
V_131 -> V_135 = V_136 ;
break;
case V_100 :
V_131 -> V_8 = V_137 |
V_133 ;
V_131 -> V_134 = V_68 |
V_138 ;
V_131 -> V_135 = V_138 ;
if ( V_10 -> V_14 . V_35 . V_36 >= V_37 ) {
if ( F_63 ( & V_10 -> V_14 ) -> V_139 ) {
V_131 -> V_134 = V_68 ;
V_131 -> V_135 = V_68 ;
}
V_131 -> V_65 = & V_140 ;
V_131 -> V_141 = false ;
V_131 -> V_142 = true ;
} else {
V_131 -> V_65 = & V_143 ;
}
break;
case V_106 :
if ( V_10 -> V_14 . V_35 . V_36 >= V_37 )
V_131 -> V_65 = & V_144 ;
else
if ( ! V_10 -> V_128 . V_129 )
V_131 -> V_65 = & V_145 ;
else
V_131 -> V_65 = & V_143 ;
if ( V_10 -> V_128 . V_129 ) {
V_131 -> V_8 = V_133 ;
V_131 -> V_134 = V_68 |
V_138 ;
V_131 -> V_135 = V_138 ;
} else {
V_131 -> V_8 = V_133 |
V_146 ;
V_131 -> V_134 = V_91 ;
V_131 -> V_135 = V_136 ;
}
break;
default:
return - V_57 ;
}
return 0 ;
}
static void
F_64 ( struct V_25 * V_26 , struct V_90 * V_75 )
{
struct V_28 * V_29 = V_28 ( V_26 ) ;
switch ( V_26 -> V_70 . V_99 ) {
case V_100 :
F_28 ( V_29 , V_69 ,
V_78 ) ;
break;
default:
F_28 ( V_29 , V_78 , 0 ) ;
break;
}
* V_75 = V_29 -> V_73 ;
}
static int
F_65 ( struct V_147 * V_148 , T_1 V_149 )
{
int V_49 = F_66 ( V_148 , 2 ) ;
if ( V_49 == 0 ) {
F_67 ( V_148 , V_150 , 0x0000 , 1 ) ;
F_68 ( V_148 , V_149 & 0x0000ffff ) ;
F_69 ( V_148 ) ;
}
return V_49 ;
}
static int
F_70 ( struct V_147 * V_148 , struct V_25 * V_26 ,
struct V_151 * V_152 , struct V_151 * V_153 )
{
struct V_101 * V_154 = V_152 -> V_102 ;
int V_49 = F_66 ( V_148 , 10 ) ;
if ( V_49 == 0 ) {
F_67 ( V_148 , V_150 , 0x0400 , 8 ) ;
F_68 ( V_148 , F_71 ( V_154 -> V_155 [ 0 ] . V_156 ) ) ;
F_68 ( V_148 , F_72 ( V_154 -> V_155 [ 0 ] . V_156 ) ) ;
F_68 ( V_148 , F_71 ( V_154 -> V_155 [ 1 ] . V_156 ) ) ;
F_68 ( V_148 , F_72 ( V_154 -> V_155 [ 1 ] . V_156 ) ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_153 -> V_71 ) ;
F_73 ( V_148 , V_150 , 0x0300 , 0x0386 ) ;
}
return V_49 ;
}
static int
F_74 ( struct V_147 * V_148 , T_1 V_149 )
{
int V_49 = F_66 ( V_148 , 2 ) ;
if ( V_49 == 0 ) {
F_67 ( V_148 , V_150 , 0x0000 , 1 ) ;
F_68 ( V_148 , V_149 ) ;
}
return V_49 ;
}
static int
F_75 ( struct V_147 * V_148 , struct V_25 * V_26 ,
struct V_151 * V_152 , struct V_151 * V_153 )
{
struct V_101 * V_154 = V_152 -> V_102 ;
T_5 V_157 = V_154 -> V_155 [ 0 ] . V_156 ;
T_5 V_158 = V_154 -> V_155 [ 1 ] . V_156 ;
T_1 V_159 = V_153 -> V_71 ;
int V_49 ;
V_159 = V_153 -> V_71 ;
while ( V_159 ) {
int V_160 = ( V_159 > 8191 ) ? 8191 : V_159 ;
V_49 = F_66 ( V_148 , 11 ) ;
if ( V_49 )
return V_49 ;
F_67 ( V_148 , V_150 , 0x030c , 8 ) ;
F_68 ( V_148 , F_71 ( V_157 ) ) ;
F_68 ( V_148 , F_72 ( V_157 ) ) ;
F_68 ( V_148 , F_71 ( V_158 ) ) ;
F_68 ( V_148 , F_72 ( V_158 ) ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_160 ) ;
F_67 ( V_148 , V_150 , 0x0300 , 1 ) ;
F_68 ( V_148 , 0x00000110 ) ;
V_159 -= V_160 ;
V_157 += ( V_41 * V_160 ) ;
V_158 += ( V_41 * V_160 ) ;
}
return 0 ;
}
static int
F_76 ( struct V_147 * V_148 , struct V_25 * V_26 ,
struct V_151 * V_152 , struct V_151 * V_153 )
{
struct V_101 * V_154 = V_152 -> V_102 ;
T_5 V_157 = V_154 -> V_155 [ 0 ] . V_156 ;
T_5 V_158 = V_154 -> V_155 [ 1 ] . V_156 ;
T_1 V_159 = V_153 -> V_71 ;
int V_49 ;
V_159 = V_153 -> V_71 ;
while ( V_159 ) {
int V_160 = ( V_159 > 2047 ) ? 2047 : V_159 ;
V_49 = F_66 ( V_148 , 12 ) ;
if ( V_49 )
return V_49 ;
F_67 ( V_148 , V_150 , 0x0238 , 2 ) ;
F_68 ( V_148 , F_71 ( V_158 ) ) ;
F_68 ( V_148 , F_72 ( V_158 ) ) ;
F_67 ( V_148 , V_150 , 0x030c , 6 ) ;
F_68 ( V_148 , F_71 ( V_157 ) ) ;
F_68 ( V_148 , F_72 ( V_157 ) ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_160 ) ;
F_67 ( V_148 , V_150 , 0x0300 , 1 ) ;
F_68 ( V_148 , 0x00100110 ) ;
V_159 -= V_160 ;
V_157 += ( V_41 * V_160 ) ;
V_158 += ( V_41 * V_160 ) ;
}
return 0 ;
}
static int
F_77 ( struct V_147 * V_148 , struct V_25 * V_26 ,
struct V_151 * V_152 , struct V_151 * V_153 )
{
struct V_101 * V_154 = V_152 -> V_102 ;
T_5 V_157 = V_154 -> V_155 [ 0 ] . V_156 ;
T_5 V_158 = V_154 -> V_155 [ 1 ] . V_156 ;
T_1 V_159 = V_153 -> V_71 ;
int V_49 ;
V_159 = V_153 -> V_71 ;
while ( V_159 ) {
int V_160 = ( V_159 > 8191 ) ? 8191 : V_159 ;
V_49 = F_66 ( V_148 , 11 ) ;
if ( V_49 )
return V_49 ;
F_78 ( V_148 , V_150 , 0x030c , 8 ) ;
F_68 ( V_148 , F_71 ( V_157 ) ) ;
F_68 ( V_148 , F_72 ( V_157 ) ) ;
F_68 ( V_148 , F_71 ( V_158 ) ) ;
F_68 ( V_148 , F_72 ( V_158 ) ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_160 ) ;
F_78 ( V_148 , V_150 , 0x0300 , 1 ) ;
F_68 ( V_148 , 0x00000110 ) ;
V_159 -= V_160 ;
V_157 += ( V_41 * V_160 ) ;
V_158 += ( V_41 * V_160 ) ;
}
return 0 ;
}
static int
F_79 ( struct V_147 * V_148 , struct V_25 * V_26 ,
struct V_151 * V_152 , struct V_151 * V_153 )
{
struct V_101 * V_154 = V_152 -> V_102 ;
int V_49 = F_66 ( V_148 , 7 ) ;
if ( V_49 == 0 ) {
F_78 ( V_148 , V_150 , 0x0320 , 6 ) ;
F_68 ( V_148 , F_71 ( V_154 -> V_155 [ 0 ] . V_156 ) ) ;
F_68 ( V_148 , F_72 ( V_154 -> V_155 [ 0 ] . V_156 ) ) ;
F_68 ( V_148 , F_71 ( V_154 -> V_155 [ 1 ] . V_156 ) ) ;
F_68 ( V_148 , F_72 ( V_154 -> V_155 [ 1 ] . V_156 ) ) ;
F_68 ( V_148 , 0x00000000 ) ;
F_68 ( V_148 , V_153 -> V_71 << V_72 ) ;
}
return V_49 ;
}
static int
F_80 ( struct V_147 * V_148 , struct V_25 * V_26 ,
struct V_151 * V_152 , struct V_151 * V_153 )
{
struct V_101 * V_154 = V_152 -> V_102 ;
int V_49 = F_66 ( V_148 , 7 ) ;
if ( V_49 == 0 ) {
F_78 ( V_148 , V_150 , 0x0304 , 6 ) ;
F_68 ( V_148 , V_153 -> V_71 << V_72 ) ;
F_68 ( V_148 , F_71 ( V_154 -> V_155 [ 0 ] . V_156 ) ) ;
F_68 ( V_148 , F_72 ( V_154 -> V_155 [ 0 ] . V_156 ) ) ;
F_68 ( V_148 , F_71 ( V_154 -> V_155 [ 1 ] . V_156 ) ) ;
F_68 ( V_148 , F_72 ( V_154 -> V_155 [ 1 ] . V_156 ) ) ;
F_68 ( V_148 , 0x00000000 ) ;
}
return V_49 ;
}
static int
F_81 ( struct V_147 * V_148 , T_1 V_149 )
{
int V_49 = F_66 ( V_148 , 6 ) ;
if ( V_49 == 0 ) {
F_78 ( V_148 , V_150 , 0x0000 , 1 ) ;
F_68 ( V_148 , V_149 ) ;
F_78 ( V_148 , V_150 , 0x0180 , 3 ) ;
F_68 ( V_148 , V_148 -> V_10 -> V_161 . V_149 ) ;
F_68 ( V_148 , V_148 -> V_162 . V_149 ) ;
F_68 ( V_148 , V_148 -> V_162 . V_149 ) ;
}
return V_49 ;
}
static int
F_82 ( struct V_147 * V_148 , struct V_25 * V_26 ,
struct V_151 * V_152 , struct V_151 * V_153 )
{
struct V_101 * V_154 = V_152 -> V_102 ;
T_5 V_163 = ( V_153 -> V_71 << V_72 ) ;
T_5 V_157 = V_154 -> V_155 [ 0 ] . V_156 ;
T_5 V_158 = V_154 -> V_155 [ 1 ] . V_156 ;
int V_164 = ! ! V_154 -> V_94 ;
int V_165 = ! ! ( (struct V_101 * ) V_153 -> V_102 ) -> V_94 ;
int V_49 ;
while ( V_163 ) {
T_1 V_166 , V_167 , V_168 ;
V_49 = F_66 ( V_148 , 18 + 6 * ( V_164 + V_165 ) ) ;
if ( V_49 )
return V_49 ;
V_166 = F_83 ( V_163 , ( T_5 ) ( 4 * 1024 * 1024 ) ) ;
V_167 = 16 * 4 ;
V_168 = V_166 / V_167 ;
if ( V_164 ) {
F_78 ( V_148 , V_150 , 0x0200 , 7 ) ;
F_68 ( V_148 , 0 ) ;
F_68 ( V_148 , 0 ) ;
F_68 ( V_148 , V_167 ) ;
F_68 ( V_148 , V_168 ) ;
F_68 ( V_148 , 1 ) ;
F_68 ( V_148 , 0 ) ;
F_68 ( V_148 , 0 ) ;
} else {
F_78 ( V_148 , V_150 , 0x0200 , 1 ) ;
F_68 ( V_148 , 1 ) ;
}
if ( V_165 ) {
F_78 ( V_148 , V_150 , 0x021c , 7 ) ;
F_68 ( V_148 , 0 ) ;
F_68 ( V_148 , 0 ) ;
F_68 ( V_148 , V_167 ) ;
F_68 ( V_148 , V_168 ) ;
F_68 ( V_148 , 1 ) ;
F_68 ( V_148 , 0 ) ;
F_68 ( V_148 , 0 ) ;
} else {
F_78 ( V_148 , V_150 , 0x021c , 1 ) ;
F_68 ( V_148 , 1 ) ;
}
F_78 ( V_148 , V_150 , 0x0238 , 2 ) ;
F_68 ( V_148 , F_71 ( V_157 ) ) ;
F_68 ( V_148 , F_71 ( V_158 ) ) ;
F_78 ( V_148 , V_150 , 0x030c , 8 ) ;
F_68 ( V_148 , F_72 ( V_157 ) ) ;
F_68 ( V_148 , F_72 ( V_158 ) ) ;
F_68 ( V_148 , V_167 ) ;
F_68 ( V_148 , V_167 ) ;
F_68 ( V_148 , V_167 ) ;
F_68 ( V_148 , V_168 ) ;
F_68 ( V_148 , 0x00000101 ) ;
F_68 ( V_148 , 0x00000000 ) ;
F_78 ( V_148 , V_150 , V_169 , 1 ) ;
F_68 ( V_148 , 0 ) ;
V_163 -= V_166 ;
V_157 += V_166 ;
V_158 += V_166 ;
}
return 0 ;
}
static int
F_84 ( struct V_147 * V_148 , T_1 V_149 )
{
int V_49 = F_66 ( V_148 , 4 ) ;
if ( V_49 == 0 ) {
F_78 ( V_148 , V_150 , 0x0000 , 1 ) ;
F_68 ( V_148 , V_149 ) ;
F_78 ( V_148 , V_150 , 0x0180 , 1 ) ;
F_68 ( V_148 , V_148 -> V_10 -> V_161 . V_149 ) ;
}
return V_49 ;
}
static inline T_2
F_85 ( struct V_25 * V_26 ,
struct V_147 * V_148 , struct V_151 * V_70 )
{
if ( V_70 -> V_99 == V_106 )
return V_170 ;
return V_148 -> V_162 . V_149 ;
}
static int
F_86 ( struct V_147 * V_148 , struct V_25 * V_26 ,
struct V_151 * V_152 , struct V_151 * V_153 )
{
T_1 V_157 = V_152 -> V_171 << V_72 ;
T_1 V_158 = V_153 -> V_171 << V_72 ;
T_1 V_159 = V_153 -> V_71 ;
int V_49 ;
V_49 = F_66 ( V_148 , 3 ) ;
if ( V_49 )
return V_49 ;
F_78 ( V_148 , V_150 , V_172 , 2 ) ;
F_68 ( V_148 , F_85 ( V_26 , V_148 , V_152 ) ) ;
F_68 ( V_148 , F_85 ( V_26 , V_148 , V_153 ) ) ;
V_159 = V_153 -> V_71 ;
while ( V_159 ) {
int V_160 = ( V_159 > 2047 ) ? 2047 : V_159 ;
V_49 = F_66 ( V_148 , 11 ) ;
if ( V_49 )
return V_49 ;
F_78 ( V_148 , V_150 ,
V_173 , 8 ) ;
F_68 ( V_148 , V_157 ) ;
F_68 ( V_148 , V_158 ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_41 ) ;
F_68 ( V_148 , V_160 ) ;
F_68 ( V_148 , 0x00000101 ) ;
F_68 ( V_148 , 0x00000000 ) ;
F_78 ( V_148 , V_150 , V_169 , 1 ) ;
F_68 ( V_148 , 0 ) ;
V_159 -= V_160 ;
V_157 += ( V_41 * V_160 ) ;
V_158 += ( V_41 * V_160 ) ;
}
return 0 ;
}
static int
F_87 ( struct V_9 * V_10 , struct V_25 * V_26 ,
struct V_151 * V_70 )
{
struct V_101 * V_174 = V_26 -> V_70 . V_102 ;
struct V_101 * V_175 = V_70 -> V_102 ;
T_5 V_6 = ( T_5 ) V_70 -> V_71 << V_72 ;
int V_49 ;
V_49 = F_88 ( V_10 -> V_53 . V_54 , V_6 , V_174 -> V_40 ,
V_176 , & V_174 -> V_155 [ 0 ] ) ;
if ( V_49 )
return V_49 ;
V_49 = F_88 ( V_10 -> V_53 . V_54 , V_6 , V_175 -> V_40 ,
V_176 , & V_174 -> V_155 [ 1 ] ) ;
if ( V_49 ) {
F_89 ( & V_174 -> V_155 [ 0 ] ) ;
return V_49 ;
}
F_90 ( & V_174 -> V_155 [ 0 ] , V_174 ) ;
F_90 ( & V_174 -> V_155 [ 1 ] , V_175 ) ;
return 0 ;
}
static int
F_91 ( struct V_25 * V_26 , int V_97 , bool V_177 ,
bool V_116 , struct V_151 * V_153 )
{
struct V_9 * V_10 = F_16 ( V_26 -> V_27 ) ;
struct V_147 * V_148 = V_10 -> V_64 . V_148 ;
struct V_178 * V_179 = ( void * ) V_148 -> V_180 . V_53 ;
struct V_22 * V_19 ;
int V_49 ;
if ( V_10 -> V_14 . V_35 . V_36 >= V_37 ) {
V_49 = F_87 ( V_10 , V_26 , V_153 ) ;
if ( V_49 )
return V_49 ;
}
F_92 ( & V_179 -> V_181 , V_182 ) ;
V_49 = F_93 ( V_28 ( V_26 ) , V_148 , true , V_177 ) ;
if ( V_49 == 0 ) {
V_49 = V_10 -> V_64 . V_183 ( V_148 , V_26 , & V_26 -> V_70 , V_153 ) ;
if ( V_49 == 0 ) {
V_49 = F_94 ( V_148 , false , & V_19 ) ;
if ( V_49 == 0 ) {
V_49 = F_95 ( V_26 ,
& V_19 -> V_184 ,
V_97 ,
V_153 ) ;
F_3 ( & V_19 ) ;
}
}
}
F_96 ( & V_179 -> V_181 ) ;
return V_49 ;
}
void
F_97 ( struct V_9 * V_10 )
{
static const struct {
const char * V_185 ;
int V_186 ;
T_6 V_187 ;
int (* F_98)( struct V_147 * ,
struct V_25 * ,
struct V_151 * , struct V_151 * );
int (* F_99)( struct V_147 * , T_1 V_149 );
} V_188 [] = {
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
} , * V_189 = V_188 ;
const char * V_185 = L_11 ;
int V_49 ;
do {
struct V_147 * V_148 ;
if ( V_189 -> V_186 )
V_148 = V_10 -> V_190 ;
else
V_148 = V_10 -> V_191 ;
if ( V_148 == NULL )
continue;
V_49 = F_100 ( & V_148 -> V_180 ,
V_189 -> V_187 | ( V_189 -> V_186 << 16 ) ,
V_189 -> V_187 , NULL , 0 ,
& V_10 -> V_64 . V_192 ) ;
if ( V_49 == 0 ) {
V_49 = V_189 -> F_99 ( V_148 , V_10 -> V_64 . V_192 . V_149 ) ;
if ( V_49 ) {
F_101 ( & V_10 -> V_64 . V_192 ) ;
continue;
}
V_10 -> V_64 . V_183 = V_189 -> F_98 ;
V_10 -> V_64 . V_148 = V_148 ;
V_185 = V_189 -> V_185 ;
break;
}
} while ( ( ++ V_189 ) -> F_98 );
F_102 ( V_10 , L_12 , V_185 ) ;
}
static int
F_103 ( struct V_25 * V_26 , bool V_97 , bool V_177 ,
bool V_116 , struct V_151 * V_153 )
{
struct V_74 V_193 = {
. V_81 = 0 ,
. V_82 = 0 ,
. V_8 = V_69 | V_91
} ;
struct V_90 V_73 ;
struct V_151 V_194 ;
int V_49 ;
V_73 . V_85 = V_73 . V_87 = 1 ;
V_73 . V_73 = V_73 . V_93 = & V_193 ;
V_194 = * V_153 ;
V_194 . V_102 = NULL ;
V_49 = F_104 ( V_26 , & V_73 , & V_194 , V_177 , V_116 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_105 ( V_26 -> V_64 , & V_194 ) ;
if ( V_49 )
goto V_104;
V_49 = F_91 ( V_26 , true , V_177 , V_116 , & V_194 ) ;
if ( V_49 )
goto V_104;
V_49 = F_106 ( V_26 , V_177 , V_116 , V_153 ) ;
V_104:
F_107 ( V_26 , & V_194 ) ;
return V_49 ;
}
static int
F_108 ( struct V_25 * V_26 , bool V_97 , bool V_177 ,
bool V_116 , struct V_151 * V_153 )
{
struct V_74 V_193 = {
. V_81 = 0 ,
. V_82 = 0 ,
. V_8 = V_69 | V_91
} ;
struct V_90 V_73 ;
struct V_151 V_194 ;
int V_49 ;
V_73 . V_85 = V_73 . V_87 = 1 ;
V_73 . V_73 = V_73 . V_93 = & V_193 ;
V_194 = * V_153 ;
V_194 . V_102 = NULL ;
V_49 = F_104 ( V_26 , & V_73 , & V_194 , V_177 , V_116 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_106 ( V_26 , V_177 , V_116 , & V_194 ) ;
if ( V_49 )
goto V_104;
V_49 = F_91 ( V_26 , true , V_177 , V_116 , V_153 ) ;
if ( V_49 )
goto V_104;
V_104:
F_107 ( V_26 , & V_194 ) ;
return V_49 ;
}
static void
F_109 ( struct V_25 * V_26 , struct V_151 * V_153 )
{
struct V_28 * V_29 = V_28 ( V_26 ) ;
struct V_195 * V_155 ;
if ( V_26 -> V_196 != F_15 )
return;
F_110 (vma, &nvbo->vma_list, head) {
if ( V_153 && V_153 -> V_99 != V_132 &&
( V_153 -> V_99 == V_100 ||
V_29 -> V_40 != V_155 -> V_54 -> V_55 -> V_51 ) ) {
F_90 ( V_155 , V_153 -> V_102 ) ;
} else {
F_111 ( V_155 ) ;
}
}
}
static int
F_112 ( struct V_25 * V_26 , struct V_151 * V_153 ,
struct V_3 * * V_197 )
{
struct V_9 * V_10 = F_16 ( V_26 -> V_27 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_28 * V_29 = V_28 ( V_26 ) ;
T_5 V_156 = V_153 -> V_171 << V_72 ;
* V_197 = NULL ;
if ( V_153 -> V_99 != V_100 )
return 0 ;
if ( V_10 -> V_14 . V_35 . V_36 >= V_83 ) {
* V_197 = F_13 ( V_2 , V_156 , V_153 -> V_6 ,
V_29 -> V_38 ,
V_29 -> V_42 ) ;
}
return 0 ;
}
static void
F_113 ( struct V_25 * V_26 ,
struct V_3 * V_197 ,
struct V_3 * * V_198 )
{
struct V_9 * V_10 = F_16 ( V_26 -> V_27 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_19 * V_19 = F_114 ( V_26 -> V_199 ) ;
F_11 ( V_2 , * V_198 , V_19 ) ;
* V_198 = V_197 ;
}
static int
F_115 ( struct V_25 * V_26 , bool V_97 , bool V_177 ,
bool V_116 , struct V_151 * V_153 )
{
struct V_9 * V_10 = F_16 ( V_26 -> V_27 ) ;
struct V_28 * V_29 = V_28 ( V_26 ) ;
struct V_151 * V_152 = & V_26 -> V_70 ;
struct V_3 * V_197 = NULL ;
int V_49 = 0 ;
V_49 = F_116 ( V_26 , V_177 , V_116 ) ;
if ( V_49 )
return V_49 ;
if ( V_29 -> V_32 )
F_25 ( V_10 , L_13 , V_29 ) ;
if ( V_10 -> V_14 . V_35 . V_36 < V_37 ) {
V_49 = F_112 ( V_26 , V_153 , & V_197 ) ;
if ( V_49 )
return V_49 ;
}
if ( V_152 -> V_99 == V_132 && ! V_26 -> V_64 ) {
F_117 ( V_26 -> V_70 . V_102 != NULL ) ;
V_26 -> V_70 = * V_153 ;
V_153 -> V_102 = NULL ;
goto V_104;
}
if ( V_10 -> V_64 . V_183 ) {
if ( V_153 -> V_99 == V_132 )
V_49 = F_103 ( V_26 , V_97 , V_177 ,
V_116 , V_153 ) ;
else if ( V_152 -> V_99 == V_132 )
V_49 = F_108 ( V_26 , V_97 , V_177 ,
V_116 , V_153 ) ;
else
V_49 = F_91 ( V_26 , V_97 , V_177 ,
V_116 , V_153 ) ;
if ( ! V_49 )
goto V_104;
}
V_49 = F_116 ( V_26 , V_177 , V_116 ) ;
if ( V_49 == 0 )
V_49 = F_118 ( V_26 , V_177 , V_116 , V_153 ) ;
V_104:
if ( V_10 -> V_14 . V_35 . V_36 < V_37 ) {
if ( V_49 )
F_113 ( V_26 , NULL , & V_197 ) ;
else
F_113 ( V_26 , V_197 , & V_29 -> V_12 ) ;
}
return V_49 ;
}
static int
F_119 ( struct V_25 * V_26 , struct V_200 * V_31 )
{
struct V_28 * V_29 = V_28 ( V_26 ) ;
return F_120 ( & V_29 -> V_30 . V_201 ,
V_31 -> V_202 ) ;
}
static int
F_121 ( struct V_123 * V_27 , struct V_151 * V_70 )
{
struct V_130 * V_131 = & V_27 -> V_131 [ V_70 -> V_99 ] ;
struct V_9 * V_10 = F_16 ( V_27 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_14 ) ;
struct V_101 * V_154 = V_70 -> V_102 ;
int V_49 ;
V_70 -> V_203 . V_5 = NULL ;
V_70 -> V_203 . V_156 = 0 ;
V_70 -> V_203 . V_6 = V_70 -> V_71 << V_72 ;
V_70 -> V_203 . V_184 = 0 ;
V_70 -> V_203 . V_119 = false ;
if ( ! ( V_131 -> V_8 & V_133 ) )
return - V_57 ;
switch ( V_70 -> V_99 ) {
case V_132 :
return 0 ;
case V_106 :
#if F_58 ( V_127 )
if ( V_10 -> V_128 . V_129 ) {
V_70 -> V_203 . V_156 = V_70 -> V_171 << V_72 ;
V_70 -> V_203 . V_184 = V_10 -> V_128 . V_184 ;
V_70 -> V_203 . V_119 = ! V_10 -> V_128 . V_204 ;
}
#endif
if ( V_10 -> V_14 . V_35 . V_36 < V_37 || ! V_154 -> V_94 )
break;
case V_100 :
V_70 -> V_203 . V_156 = V_70 -> V_171 << V_72 ;
V_70 -> V_203 . V_184 = V_14 -> V_65 -> V_205 ( V_14 , 1 ) ;
V_70 -> V_203 . V_119 = true ;
if ( V_10 -> V_14 . V_35 . V_36 >= V_37 ) {
struct V_206 * V_207 = F_63 ( & V_10 -> V_14 ) ;
int V_40 = 12 ;
if ( V_10 -> V_14 . V_35 . V_36 >= V_208 )
V_40 = V_154 -> V_40 ;
V_49 = F_122 ( V_207 , V_154 -> V_6 << 12 , V_40 ,
& V_154 -> V_209 ) ;
if ( V_49 )
return V_49 ;
F_90 ( & V_154 -> V_209 , V_154 ) ;
V_70 -> V_203 . V_156 = V_154 -> V_209 . V_156 ;
}
break;
default:
return - V_57 ;
}
return 0 ;
}
static void
F_123 ( struct V_123 * V_27 , struct V_151 * V_70 )
{
struct V_101 * V_154 = V_70 -> V_102 ;
if ( ! V_154 -> V_209 . V_154 )
return;
F_111 ( & V_154 -> V_209 ) ;
F_89 ( & V_154 -> V_209 ) ;
}
static int
F_124 ( struct V_25 * V_26 )
{
struct V_9 * V_10 = F_16 ( V_26 -> V_27 ) ;
struct V_28 * V_29 = V_28 ( V_26 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_14 ) ;
T_1 V_210 = V_14 -> V_65 -> V_211 ( V_14 , 1 ) >> V_72 ;
int V_11 , V_49 ;
if ( V_26 -> V_70 . V_99 != V_100 ) {
if ( V_10 -> V_14 . V_35 . V_36 < V_37 ||
! F_125 ( V_29 ) )
return 0 ;
if ( V_26 -> V_70 . V_99 == V_132 ) {
F_28 ( V_29 , V_106 , 0 ) ;
V_49 = F_37 ( V_29 , false , false ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
if ( V_10 -> V_14 . V_35 . V_36 >= V_37 ||
V_26 -> V_70 . V_171 + V_26 -> V_70 . V_71 < V_210 )
return 0 ;
for ( V_11 = 0 ; V_11 < V_29 -> V_73 . V_85 ; ++ V_11 ) {
V_29 -> V_86 [ V_11 ] . V_81 = 0 ;
V_29 -> V_86 [ V_11 ] . V_82 = V_210 ;
}
for ( V_11 = 0 ; V_11 < V_29 -> V_73 . V_87 ; ++ V_11 ) {
V_29 -> V_88 [ V_11 ] . V_81 = 0 ;
V_29 -> V_88 [ V_11 ] . V_82 = V_210 ;
}
F_28 ( V_29 , V_77 , 0 ) ;
return F_37 ( V_29 , false , false ) ;
}
static int
F_126 ( struct V_122 * V_64 )
{
struct V_110 * V_111 = ( void * ) V_64 ;
struct V_9 * V_10 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_14 * V_212 ;
unsigned V_11 ;
int V_213 ;
bool V_214 = ! ! ( V_64 -> V_124 & V_215 ) ;
if ( V_64 -> V_216 != V_217 )
return 0 ;
if ( V_214 && V_64 -> V_44 ) {
F_127 ( V_64 -> V_44 , V_64 -> V_218 ,
V_111 -> V_112 , V_64 -> V_71 ) ;
V_64 -> V_216 = V_219 ;
return 0 ;
}
V_10 = F_16 ( V_64 -> V_27 ) ;
V_14 = F_2 ( & V_10 -> V_14 ) ;
V_2 = V_10 -> V_2 ;
V_212 = V_14 -> V_2 ;
#if F_58 ( V_127 )
if ( V_10 -> V_128 . V_129 ) {
return F_128 ( V_64 ) ;
}
#endif
#if F_58 ( V_220 ) && F_58 ( V_221 )
if ( F_129 () ) {
return F_130 ( ( void * ) V_64 , V_2 -> V_2 ) ;
}
#endif
V_213 = F_131 ( V_64 ) ;
if ( V_213 ) {
return V_213 ;
}
for ( V_11 = 0 ; V_11 < V_64 -> V_71 ; V_11 ++ ) {
T_7 V_5 ;
V_5 = F_132 ( V_212 , V_64 -> V_218 [ V_11 ] , 0 , V_41 ,
V_222 ) ;
if ( F_133 ( V_212 , V_5 ) ) {
while ( V_11 -- ) {
F_134 ( V_212 , V_111 -> V_112 [ V_11 ] ,
V_41 , V_222 ) ;
V_111 -> V_112 [ V_11 ] = 0 ;
}
F_135 ( V_64 ) ;
return - V_223 ;
}
V_111 -> V_112 [ V_11 ] = V_5 ;
}
return 0 ;
}
static void
F_136 ( struct V_122 * V_64 )
{
struct V_110 * V_111 = ( void * ) V_64 ;
struct V_9 * V_10 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_14 * V_212 ;
unsigned V_11 ;
bool V_214 = ! ! ( V_64 -> V_124 & V_215 ) ;
if ( V_214 )
return;
V_10 = F_16 ( V_64 -> V_27 ) ;
V_14 = F_2 ( & V_10 -> V_14 ) ;
V_2 = V_10 -> V_2 ;
V_212 = V_14 -> V_2 ;
#if F_58 ( V_127 )
if ( V_10 -> V_128 . V_129 ) {
F_137 ( V_64 ) ;
return;
}
#endif
#if F_58 ( V_220 ) && F_58 ( V_221 )
if ( F_129 () ) {
F_138 ( ( void * ) V_64 , V_2 -> V_2 ) ;
return;
}
#endif
for ( V_11 = 0 ; V_11 < V_64 -> V_71 ; V_11 ++ ) {
if ( V_111 -> V_112 [ V_11 ] ) {
F_134 ( V_212 , V_111 -> V_112 [ V_11 ] , V_41 ,
V_222 ) ;
}
}
F_135 ( V_64 ) ;
}
void
F_139 ( struct V_28 * V_29 , struct V_22 * V_19 , bool V_224 )
{
struct V_45 * V_199 = V_29 -> V_26 . V_199 ;
if ( V_224 )
F_140 ( V_199 , & V_19 -> V_184 ) ;
else if ( V_19 )
F_141 ( V_199 , & V_19 -> V_184 ) ;
}
struct V_195 *
F_142 ( struct V_28 * V_29 , struct V_225 * V_54 )
{
struct V_195 * V_155 ;
F_110 (vma, &nvbo->vma_list, head) {
if ( V_155 -> V_54 == V_54 )
return V_155 ;
}
return NULL ;
}
int
F_143 ( struct V_28 * V_29 , struct V_225 * V_54 ,
struct V_195 * V_155 )
{
const T_1 V_6 = V_29 -> V_26 . V_70 . V_71 << V_72 ;
int V_49 ;
V_49 = F_88 ( V_54 , V_6 , V_29 -> V_40 ,
V_176 , V_155 ) ;
if ( V_49 )
return V_49 ;
if ( V_29 -> V_26 . V_70 . V_99 != V_132 &&
( V_29 -> V_26 . V_70 . V_99 == V_100 ||
V_29 -> V_40 != V_155 -> V_54 -> V_55 -> V_51 ) )
F_90 ( V_155 , V_29 -> V_26 . V_70 . V_102 ) ;
F_144 ( & V_155 -> V_61 , & V_29 -> V_63 ) ;
V_155 -> V_226 = 1 ;
return 0 ;
}
void
F_145 ( struct V_28 * V_29 , struct V_195 * V_155 )
{
if ( V_155 -> V_154 ) {
if ( V_29 -> V_26 . V_70 . V_99 != V_132 )
F_111 ( V_155 ) ;
F_89 ( V_155 ) ;
F_146 ( & V_155 -> V_61 ) ;
}
}
