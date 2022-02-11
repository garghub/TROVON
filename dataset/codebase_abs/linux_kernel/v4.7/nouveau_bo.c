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
if ( ! V_29 -> V_67 )
V_49 = F_42 ( & V_29 -> V_26 , 0 , V_29 -> V_26 . V_70 . V_71 ,
& V_29 -> V_109 ) ;
F_38 ( & V_29 -> V_26 ) ;
return V_49 ;
}
void
F_43 ( struct V_28 * V_29 )
{
if ( ! V_29 )
return;
if ( ! V_29 -> V_67 )
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
static inline void *
F_50 ( struct V_28 * V_29 , unsigned V_117 , void * V_70 , T_4 V_118 )
{
struct V_110 * V_119 ;
T_4 * V_120 = V_70 ;
V_117 *= V_118 ;
if ( V_120 ) {
V_120 += V_117 ;
} else {
V_119 = (struct V_110 * ) V_29 -> V_26 . V_64 ;
V_120 = V_119 -> V_121 [ V_117 / V_41 ] ;
V_120 += V_117 % V_41 ;
}
return V_120 ;
}
void
F_51 ( struct V_28 * V_29 , unsigned V_117 , T_5 V_122 )
{
bool V_123 ;
T_5 * V_70 = F_52 ( & V_29 -> V_109 , & V_123 ) ;
V_70 = F_53 ( V_29 , V_117 , V_70 ) ;
if ( V_123 )
F_54 ( V_122 , ( void V_124 V_125 * ) V_70 ) ;
else
* V_70 = V_122 ;
}
T_1
F_55 ( struct V_28 * V_29 , unsigned V_117 )
{
bool V_123 ;
T_1 * V_70 = F_52 ( & V_29 -> V_109 , & V_123 ) ;
V_70 = F_53 ( V_29 , V_117 , V_70 ) ;
if ( V_123 )
return F_56 ( ( void V_124 V_125 * ) V_70 ) ;
else
return * V_70 ;
}
void
F_57 ( struct V_28 * V_29 , unsigned V_117 , T_1 V_122 )
{
bool V_123 ;
T_1 * V_70 = F_52 ( & V_29 -> V_109 , & V_123 ) ;
V_70 = F_53 ( V_29 , V_117 , V_70 ) ;
if ( V_123 )
F_58 ( V_122 , ( void V_124 V_125 * ) V_70 ) ;
else
* V_70 = V_122 ;
}
static struct V_126 *
F_59 ( struct V_127 * V_27 , unsigned long V_6 ,
T_2 V_128 , struct V_129 * V_130 )
{
#if F_60 ( V_131 )
struct V_9 * V_10 = F_16 ( V_27 ) ;
if ( V_10 -> V_132 . V_133 ) {
return F_61 ( V_27 , V_10 -> V_132 . V_133 , V_6 ,
V_128 , V_130 ) ;
}
#endif
return F_62 ( V_27 , V_6 , V_128 , V_130 ) ;
}
static int
F_63 ( struct V_127 * V_27 , T_2 V_8 )
{
return 0 ;
}
static int
F_64 ( struct V_127 * V_27 , T_2 type ,
struct V_134 * V_135 )
{
struct V_9 * V_10 = F_16 ( V_27 ) ;
switch ( type ) {
case V_136 :
V_135 -> V_8 = V_137 ;
V_135 -> V_138 = V_91 ;
V_135 -> V_139 = V_140 ;
break;
case V_100 :
V_135 -> V_8 = V_141 |
V_137 ;
V_135 -> V_138 = V_68 |
V_142 ;
V_135 -> V_139 = V_142 ;
if ( V_10 -> V_14 . V_35 . V_36 >= V_37 ) {
if ( F_65 ( & V_10 -> V_14 ) -> V_143 ) {
V_135 -> V_138 = V_68 ;
V_135 -> V_139 = V_68 ;
}
V_135 -> V_65 = & V_144 ;
V_135 -> V_145 = false ;
V_135 -> V_146 = true ;
} else {
V_135 -> V_65 = & V_147 ;
}
break;
case V_106 :
if ( V_10 -> V_14 . V_35 . V_36 >= V_37 )
V_135 -> V_65 = & V_148 ;
else
if ( ! V_10 -> V_132 . V_133 )
V_135 -> V_65 = & V_149 ;
else
V_135 -> V_65 = & V_147 ;
if ( V_10 -> V_132 . V_133 ) {
V_135 -> V_8 = V_137 ;
V_135 -> V_138 = V_68 |
V_142 ;
V_135 -> V_139 = V_142 ;
} else {
V_135 -> V_8 = V_137 |
V_150 ;
V_135 -> V_138 = V_91 ;
V_135 -> V_139 = V_140 ;
}
break;
default:
return - V_57 ;
}
return 0 ;
}
static void
F_66 ( struct V_25 * V_26 , struct V_90 * V_75 )
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
F_67 ( struct V_151 * V_152 , T_1 V_153 )
{
int V_49 = F_68 ( V_152 , 2 ) ;
if ( V_49 == 0 ) {
F_69 ( V_152 , V_154 , 0x0000 , 1 ) ;
F_70 ( V_152 , V_153 & 0x0000ffff ) ;
F_71 ( V_152 ) ;
}
return V_49 ;
}
static int
F_72 ( struct V_151 * V_152 , struct V_25 * V_26 ,
struct V_155 * V_156 , struct V_155 * V_157 )
{
struct V_101 * V_158 = V_156 -> V_102 ;
int V_49 = F_68 ( V_152 , 10 ) ;
if ( V_49 == 0 ) {
F_69 ( V_152 , V_154 , 0x0400 , 8 ) ;
F_70 ( V_152 , F_73 ( V_158 -> V_159 [ 0 ] . V_160 ) ) ;
F_70 ( V_152 , F_74 ( V_158 -> V_159 [ 0 ] . V_160 ) ) ;
F_70 ( V_152 , F_73 ( V_158 -> V_159 [ 1 ] . V_160 ) ) ;
F_70 ( V_152 , F_74 ( V_158 -> V_159 [ 1 ] . V_160 ) ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_157 -> V_71 ) ;
F_75 ( V_152 , V_154 , 0x0300 , 0x0386 ) ;
}
return V_49 ;
}
static int
F_76 ( struct V_151 * V_152 , T_1 V_153 )
{
int V_49 = F_68 ( V_152 , 2 ) ;
if ( V_49 == 0 ) {
F_69 ( V_152 , V_154 , 0x0000 , 1 ) ;
F_70 ( V_152 , V_153 ) ;
}
return V_49 ;
}
static int
F_77 ( struct V_151 * V_152 , struct V_25 * V_26 ,
struct V_155 * V_156 , struct V_155 * V_157 )
{
struct V_101 * V_158 = V_156 -> V_102 ;
T_6 V_161 = V_158 -> V_159 [ 0 ] . V_160 ;
T_6 V_162 = V_158 -> V_159 [ 1 ] . V_160 ;
T_1 V_163 = V_157 -> V_71 ;
int V_49 ;
V_163 = V_157 -> V_71 ;
while ( V_163 ) {
int V_164 = ( V_163 > 8191 ) ? 8191 : V_163 ;
V_49 = F_68 ( V_152 , 11 ) ;
if ( V_49 )
return V_49 ;
F_69 ( V_152 , V_154 , 0x030c , 8 ) ;
F_70 ( V_152 , F_73 ( V_161 ) ) ;
F_70 ( V_152 , F_74 ( V_161 ) ) ;
F_70 ( V_152 , F_73 ( V_162 ) ) ;
F_70 ( V_152 , F_74 ( V_162 ) ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_164 ) ;
F_69 ( V_152 , V_154 , 0x0300 , 1 ) ;
F_70 ( V_152 , 0x00000110 ) ;
V_163 -= V_164 ;
V_161 += ( V_41 * V_164 ) ;
V_162 += ( V_41 * V_164 ) ;
}
return 0 ;
}
static int
F_78 ( struct V_151 * V_152 , struct V_25 * V_26 ,
struct V_155 * V_156 , struct V_155 * V_157 )
{
struct V_101 * V_158 = V_156 -> V_102 ;
T_6 V_161 = V_158 -> V_159 [ 0 ] . V_160 ;
T_6 V_162 = V_158 -> V_159 [ 1 ] . V_160 ;
T_1 V_163 = V_157 -> V_71 ;
int V_49 ;
V_163 = V_157 -> V_71 ;
while ( V_163 ) {
int V_164 = ( V_163 > 2047 ) ? 2047 : V_163 ;
V_49 = F_68 ( V_152 , 12 ) ;
if ( V_49 )
return V_49 ;
F_69 ( V_152 , V_154 , 0x0238 , 2 ) ;
F_70 ( V_152 , F_73 ( V_162 ) ) ;
F_70 ( V_152 , F_74 ( V_162 ) ) ;
F_69 ( V_152 , V_154 , 0x030c , 6 ) ;
F_70 ( V_152 , F_73 ( V_161 ) ) ;
F_70 ( V_152 , F_74 ( V_161 ) ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_164 ) ;
F_69 ( V_152 , V_154 , 0x0300 , 1 ) ;
F_70 ( V_152 , 0x00100110 ) ;
V_163 -= V_164 ;
V_161 += ( V_41 * V_164 ) ;
V_162 += ( V_41 * V_164 ) ;
}
return 0 ;
}
static int
F_79 ( struct V_151 * V_152 , struct V_25 * V_26 ,
struct V_155 * V_156 , struct V_155 * V_157 )
{
struct V_101 * V_158 = V_156 -> V_102 ;
T_6 V_161 = V_158 -> V_159 [ 0 ] . V_160 ;
T_6 V_162 = V_158 -> V_159 [ 1 ] . V_160 ;
T_1 V_163 = V_157 -> V_71 ;
int V_49 ;
V_163 = V_157 -> V_71 ;
while ( V_163 ) {
int V_164 = ( V_163 > 8191 ) ? 8191 : V_163 ;
V_49 = F_68 ( V_152 , 11 ) ;
if ( V_49 )
return V_49 ;
F_80 ( V_152 , V_154 , 0x030c , 8 ) ;
F_70 ( V_152 , F_73 ( V_161 ) ) ;
F_70 ( V_152 , F_74 ( V_161 ) ) ;
F_70 ( V_152 , F_73 ( V_162 ) ) ;
F_70 ( V_152 , F_74 ( V_162 ) ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_164 ) ;
F_80 ( V_152 , V_154 , 0x0300 , 1 ) ;
F_70 ( V_152 , 0x00000110 ) ;
V_163 -= V_164 ;
V_161 += ( V_41 * V_164 ) ;
V_162 += ( V_41 * V_164 ) ;
}
return 0 ;
}
static int
F_81 ( struct V_151 * V_152 , struct V_25 * V_26 ,
struct V_155 * V_156 , struct V_155 * V_157 )
{
struct V_101 * V_158 = V_156 -> V_102 ;
int V_49 = F_68 ( V_152 , 7 ) ;
if ( V_49 == 0 ) {
F_80 ( V_152 , V_154 , 0x0320 , 6 ) ;
F_70 ( V_152 , F_73 ( V_158 -> V_159 [ 0 ] . V_160 ) ) ;
F_70 ( V_152 , F_74 ( V_158 -> V_159 [ 0 ] . V_160 ) ) ;
F_70 ( V_152 , F_73 ( V_158 -> V_159 [ 1 ] . V_160 ) ) ;
F_70 ( V_152 , F_74 ( V_158 -> V_159 [ 1 ] . V_160 ) ) ;
F_70 ( V_152 , 0x00000000 ) ;
F_70 ( V_152 , V_157 -> V_71 << V_72 ) ;
}
return V_49 ;
}
static int
F_82 ( struct V_151 * V_152 , struct V_25 * V_26 ,
struct V_155 * V_156 , struct V_155 * V_157 )
{
struct V_101 * V_158 = V_156 -> V_102 ;
int V_49 = F_68 ( V_152 , 7 ) ;
if ( V_49 == 0 ) {
F_80 ( V_152 , V_154 , 0x0304 , 6 ) ;
F_70 ( V_152 , V_157 -> V_71 << V_72 ) ;
F_70 ( V_152 , F_73 ( V_158 -> V_159 [ 0 ] . V_160 ) ) ;
F_70 ( V_152 , F_74 ( V_158 -> V_159 [ 0 ] . V_160 ) ) ;
F_70 ( V_152 , F_73 ( V_158 -> V_159 [ 1 ] . V_160 ) ) ;
F_70 ( V_152 , F_74 ( V_158 -> V_159 [ 1 ] . V_160 ) ) ;
F_70 ( V_152 , 0x00000000 ) ;
}
return V_49 ;
}
static int
F_83 ( struct V_151 * V_152 , T_1 V_153 )
{
int V_49 = F_68 ( V_152 , 6 ) ;
if ( V_49 == 0 ) {
F_80 ( V_152 , V_154 , 0x0000 , 1 ) ;
F_70 ( V_152 , V_153 ) ;
F_80 ( V_152 , V_154 , 0x0180 , 3 ) ;
F_70 ( V_152 , V_152 -> V_10 -> V_165 . V_153 ) ;
F_70 ( V_152 , V_152 -> V_166 . V_153 ) ;
F_70 ( V_152 , V_152 -> V_166 . V_153 ) ;
}
return V_49 ;
}
static int
F_84 ( struct V_151 * V_152 , struct V_25 * V_26 ,
struct V_155 * V_156 , struct V_155 * V_157 )
{
struct V_101 * V_158 = V_156 -> V_102 ;
T_6 V_167 = ( V_157 -> V_71 << V_72 ) ;
T_6 V_161 = V_158 -> V_159 [ 0 ] . V_160 ;
T_6 V_162 = V_158 -> V_159 [ 1 ] . V_160 ;
int V_168 = ! ! V_158 -> V_94 ;
int V_169 = ! ! ( (struct V_101 * ) V_157 -> V_102 ) -> V_94 ;
int V_49 ;
while ( V_167 ) {
T_1 V_170 , V_171 , V_172 ;
V_49 = F_68 ( V_152 , 18 + 6 * ( V_168 + V_169 ) ) ;
if ( V_49 )
return V_49 ;
V_170 = F_85 ( V_167 , ( T_6 ) ( 4 * 1024 * 1024 ) ) ;
V_171 = 16 * 4 ;
V_172 = V_170 / V_171 ;
if ( V_168 ) {
F_80 ( V_152 , V_154 , 0x0200 , 7 ) ;
F_70 ( V_152 , 0 ) ;
F_70 ( V_152 , 0 ) ;
F_70 ( V_152 , V_171 ) ;
F_70 ( V_152 , V_172 ) ;
F_70 ( V_152 , 1 ) ;
F_70 ( V_152 , 0 ) ;
F_70 ( V_152 , 0 ) ;
} else {
F_80 ( V_152 , V_154 , 0x0200 , 1 ) ;
F_70 ( V_152 , 1 ) ;
}
if ( V_169 ) {
F_80 ( V_152 , V_154 , 0x021c , 7 ) ;
F_70 ( V_152 , 0 ) ;
F_70 ( V_152 , 0 ) ;
F_70 ( V_152 , V_171 ) ;
F_70 ( V_152 , V_172 ) ;
F_70 ( V_152 , 1 ) ;
F_70 ( V_152 , 0 ) ;
F_70 ( V_152 , 0 ) ;
} else {
F_80 ( V_152 , V_154 , 0x021c , 1 ) ;
F_70 ( V_152 , 1 ) ;
}
F_80 ( V_152 , V_154 , 0x0238 , 2 ) ;
F_70 ( V_152 , F_73 ( V_161 ) ) ;
F_70 ( V_152 , F_73 ( V_162 ) ) ;
F_80 ( V_152 , V_154 , 0x030c , 8 ) ;
F_70 ( V_152 , F_74 ( V_161 ) ) ;
F_70 ( V_152 , F_74 ( V_162 ) ) ;
F_70 ( V_152 , V_171 ) ;
F_70 ( V_152 , V_171 ) ;
F_70 ( V_152 , V_171 ) ;
F_70 ( V_152 , V_172 ) ;
F_70 ( V_152 , 0x00000101 ) ;
F_70 ( V_152 , 0x00000000 ) ;
F_80 ( V_152 , V_154 , V_173 , 1 ) ;
F_70 ( V_152 , 0 ) ;
V_167 -= V_170 ;
V_161 += V_170 ;
V_162 += V_170 ;
}
return 0 ;
}
static int
F_86 ( struct V_151 * V_152 , T_1 V_153 )
{
int V_49 = F_68 ( V_152 , 4 ) ;
if ( V_49 == 0 ) {
F_80 ( V_152 , V_154 , 0x0000 , 1 ) ;
F_70 ( V_152 , V_153 ) ;
F_80 ( V_152 , V_154 , 0x0180 , 1 ) ;
F_70 ( V_152 , V_152 -> V_10 -> V_165 . V_153 ) ;
}
return V_49 ;
}
static inline T_2
F_87 ( struct V_25 * V_26 ,
struct V_151 * V_152 , struct V_155 * V_70 )
{
if ( V_70 -> V_99 == V_106 )
return V_174 ;
return V_152 -> V_166 . V_153 ;
}
static int
F_88 ( struct V_151 * V_152 , struct V_25 * V_26 ,
struct V_155 * V_156 , struct V_155 * V_157 )
{
T_1 V_161 = V_156 -> V_175 << V_72 ;
T_1 V_162 = V_157 -> V_175 << V_72 ;
T_1 V_163 = V_157 -> V_71 ;
int V_49 ;
V_49 = F_68 ( V_152 , 3 ) ;
if ( V_49 )
return V_49 ;
F_80 ( V_152 , V_154 , V_176 , 2 ) ;
F_70 ( V_152 , F_87 ( V_26 , V_152 , V_156 ) ) ;
F_70 ( V_152 , F_87 ( V_26 , V_152 , V_157 ) ) ;
V_163 = V_157 -> V_71 ;
while ( V_163 ) {
int V_164 = ( V_163 > 2047 ) ? 2047 : V_163 ;
V_49 = F_68 ( V_152 , 11 ) ;
if ( V_49 )
return V_49 ;
F_80 ( V_152 , V_154 ,
V_177 , 8 ) ;
F_70 ( V_152 , V_161 ) ;
F_70 ( V_152 , V_162 ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_41 ) ;
F_70 ( V_152 , V_164 ) ;
F_70 ( V_152 , 0x00000101 ) ;
F_70 ( V_152 , 0x00000000 ) ;
F_80 ( V_152 , V_154 , V_173 , 1 ) ;
F_70 ( V_152 , 0 ) ;
V_163 -= V_164 ;
V_161 += ( V_41 * V_164 ) ;
V_162 += ( V_41 * V_164 ) ;
}
return 0 ;
}
static int
F_89 ( struct V_9 * V_10 , struct V_25 * V_26 ,
struct V_155 * V_70 )
{
struct V_101 * V_178 = V_26 -> V_70 . V_102 ;
struct V_101 * V_179 = V_70 -> V_102 ;
T_6 V_6 = ( T_6 ) V_70 -> V_71 << V_72 ;
int V_49 ;
V_49 = F_90 ( V_10 -> V_53 . V_54 , V_6 , V_178 -> V_40 ,
V_180 , & V_178 -> V_159 [ 0 ] ) ;
if ( V_49 )
return V_49 ;
V_49 = F_90 ( V_10 -> V_53 . V_54 , V_6 , V_179 -> V_40 ,
V_180 , & V_178 -> V_159 [ 1 ] ) ;
if ( V_49 ) {
F_91 ( & V_178 -> V_159 [ 0 ] ) ;
return V_49 ;
}
F_92 ( & V_178 -> V_159 [ 0 ] , V_178 ) ;
F_92 ( & V_178 -> V_159 [ 1 ] , V_179 ) ;
return 0 ;
}
static int
F_93 ( struct V_25 * V_26 , int V_97 , bool V_181 ,
bool V_116 , struct V_155 * V_157 )
{
struct V_9 * V_10 = F_16 ( V_26 -> V_27 ) ;
struct V_151 * V_152 = V_10 -> V_64 . V_152 ;
struct V_182 * V_183 = ( void * ) V_152 -> V_184 . V_53 ;
struct V_22 * V_19 ;
int V_49 ;
if ( V_10 -> V_14 . V_35 . V_36 >= V_37 ) {
V_49 = F_89 ( V_10 , V_26 , V_157 ) ;
if ( V_49 )
return V_49 ;
}
F_94 ( & V_183 -> V_185 , V_186 ) ;
V_49 = F_95 ( V_28 ( V_26 ) , V_152 , true , V_181 ) ;
if ( V_49 == 0 ) {
V_49 = V_10 -> V_64 . V_187 ( V_152 , V_26 , & V_26 -> V_70 , V_157 ) ;
if ( V_49 == 0 ) {
V_49 = F_96 ( V_152 , false , & V_19 ) ;
if ( V_49 == 0 ) {
V_49 = F_97 ( V_26 ,
& V_19 -> V_188 ,
V_97 ,
V_116 ,
V_157 ) ;
F_3 ( & V_19 ) ;
}
}
}
F_98 ( & V_183 -> V_185 ) ;
return V_49 ;
}
void
F_99 ( struct V_9 * V_10 )
{
static const struct {
const char * V_189 ;
int V_190 ;
T_7 V_191 ;
int (* F_100)( struct V_151 * ,
struct V_25 * ,
struct V_155 * , struct V_155 * );
int (* F_101)( struct V_151 * , T_1 V_153 );
} V_192 [] = {
{ L_5 , 4 , 0xb0b5 , F_72 , F_67 } ,
{ L_6 , 0 , 0xb0b5 , F_72 , F_76 } ,
{ L_5 , 4 , 0xa0b5 , F_72 , F_67 } ,
{ L_6 , 0 , 0xa0b5 , F_72 , F_76 } ,
{ L_7 , 5 , 0x90b8 , F_77 , F_76 } ,
{ L_8 , 4 , 0x90b5 , F_77 , F_76 } ,
{ L_5 , 0 , 0x85b5 , F_79 , F_83 } ,
{ L_9 , 0 , 0x74c1 , F_82 , F_83 } ,
{ L_10 , 0 , 0x9039 , F_78 , F_76 } ,
{ L_10 , 0 , 0x5039 , F_84 , F_83 } ,
{ L_10 , 0 , 0x0039 , F_88 , F_86 } ,
{} ,
{ L_9 , 0 , 0x88b4 , F_81 , F_83 } ,
} , * V_193 = V_192 ;
const char * V_189 = L_11 ;
int V_49 ;
do {
struct V_151 * V_152 ;
if ( V_193 -> V_190 )
V_152 = V_10 -> V_194 ;
else
V_152 = V_10 -> V_195 ;
if ( V_152 == NULL )
continue;
V_49 = F_102 ( & V_152 -> V_184 ,
V_193 -> V_191 | ( V_193 -> V_190 << 16 ) ,
V_193 -> V_191 , NULL , 0 ,
& V_10 -> V_64 . V_196 ) ;
if ( V_49 == 0 ) {
V_49 = V_193 -> F_101 ( V_152 , V_10 -> V_64 . V_196 . V_153 ) ;
if ( V_49 ) {
F_103 ( & V_10 -> V_64 . V_196 ) ;
continue;
}
V_10 -> V_64 . V_187 = V_193 -> F_100 ;
V_10 -> V_64 . V_152 = V_152 ;
V_189 = V_193 -> V_189 ;
break;
}
} while ( ( ++ V_193 ) -> F_100 );
F_104 ( V_10 , L_12 , V_189 ) ;
}
static int
F_105 ( struct V_25 * V_26 , bool V_97 , bool V_181 ,
bool V_116 , struct V_155 * V_157 )
{
struct V_74 V_197 = {
. V_81 = 0 ,
. V_82 = 0 ,
. V_8 = V_69 | V_91
} ;
struct V_90 V_73 ;
struct V_155 V_198 ;
int V_49 ;
V_73 . V_85 = V_73 . V_87 = 1 ;
V_73 . V_73 = V_73 . V_93 = & V_197 ;
V_198 = * V_157 ;
V_198 . V_102 = NULL ;
V_49 = F_106 ( V_26 , & V_73 , & V_198 , V_181 , V_116 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_107 ( V_26 -> V_64 , & V_198 ) ;
if ( V_49 )
goto V_104;
V_49 = F_93 ( V_26 , true , V_181 , V_116 , & V_198 ) ;
if ( V_49 )
goto V_104;
V_49 = F_108 ( V_26 , true , V_116 , V_157 ) ;
V_104:
F_109 ( V_26 , & V_198 ) ;
return V_49 ;
}
static int
F_110 ( struct V_25 * V_26 , bool V_97 , bool V_181 ,
bool V_116 , struct V_155 * V_157 )
{
struct V_74 V_197 = {
. V_81 = 0 ,
. V_82 = 0 ,
. V_8 = V_69 | V_91
} ;
struct V_90 V_73 ;
struct V_155 V_198 ;
int V_49 ;
V_73 . V_85 = V_73 . V_87 = 1 ;
V_73 . V_73 = V_73 . V_93 = & V_197 ;
V_198 = * V_157 ;
V_198 . V_102 = NULL ;
V_49 = F_106 ( V_26 , & V_73 , & V_198 , V_181 , V_116 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_108 ( V_26 , true , V_116 , & V_198 ) ;
if ( V_49 )
goto V_104;
V_49 = F_93 ( V_26 , true , V_181 , V_116 , V_157 ) ;
if ( V_49 )
goto V_104;
V_104:
F_109 ( V_26 , & V_198 ) ;
return V_49 ;
}
static void
F_111 ( struct V_25 * V_26 , struct V_155 * V_157 )
{
struct V_28 * V_29 = V_28 ( V_26 ) ;
struct V_199 * V_159 ;
if ( V_26 -> V_200 != F_15 )
return;
F_112 (vma, &nvbo->vma_list, head) {
if ( V_157 && V_157 -> V_99 != V_136 &&
( V_157 -> V_99 == V_100 ||
V_29 -> V_40 != V_159 -> V_54 -> V_55 -> V_51 ) ) {
F_92 ( V_159 , V_157 -> V_102 ) ;
} else {
F_113 ( V_159 ) ;
}
}
}
static int
F_114 ( struct V_25 * V_26 , struct V_155 * V_157 ,
struct V_3 * * V_201 )
{
struct V_9 * V_10 = F_16 ( V_26 -> V_27 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_28 * V_29 = V_28 ( V_26 ) ;
T_6 V_160 = V_157 -> V_175 << V_72 ;
* V_201 = NULL ;
if ( V_157 -> V_99 != V_100 )
return 0 ;
if ( V_10 -> V_14 . V_35 . V_36 >= V_83 ) {
* V_201 = F_13 ( V_2 , V_160 , V_157 -> V_6 ,
V_29 -> V_38 ,
V_29 -> V_42 ) ;
}
return 0 ;
}
static void
F_115 ( struct V_25 * V_26 ,
struct V_3 * V_201 ,
struct V_3 * * V_202 )
{
struct V_9 * V_10 = F_16 ( V_26 -> V_27 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_19 * V_19 = F_116 ( V_26 -> V_203 ) ;
F_11 ( V_2 , * V_202 , V_19 ) ;
* V_202 = V_201 ;
}
static int
F_117 ( struct V_25 * V_26 , bool V_97 , bool V_181 ,
bool V_116 , struct V_155 * V_157 )
{
struct V_9 * V_10 = F_16 ( V_26 -> V_27 ) ;
struct V_28 * V_29 = V_28 ( V_26 ) ;
struct V_155 * V_156 = & V_26 -> V_70 ;
struct V_3 * V_201 = NULL ;
int V_49 = 0 ;
if ( V_29 -> V_32 )
F_25 ( V_10 , L_13 , V_29 ) ;
if ( V_10 -> V_14 . V_35 . V_36 < V_37 ) {
V_49 = F_114 ( V_26 , V_157 , & V_201 ) ;
if ( V_49 )
return V_49 ;
}
if ( V_156 -> V_99 == V_136 && ! V_26 -> V_64 ) {
F_118 ( V_26 -> V_70 . V_102 != NULL ) ;
V_26 -> V_70 = * V_157 ;
V_157 -> V_102 = NULL ;
goto V_104;
}
if ( V_10 -> V_64 . V_187 ) {
if ( V_157 -> V_99 == V_136 )
V_49 = F_105 ( V_26 , V_97 , V_181 ,
V_116 , V_157 ) ;
else if ( V_156 -> V_99 == V_136 )
V_49 = F_110 ( V_26 , V_97 , V_181 ,
V_116 , V_157 ) ;
else
V_49 = F_93 ( V_26 , V_97 , V_181 ,
V_116 , V_157 ) ;
if ( ! V_49 )
goto V_104;
}
V_49 = F_119 ( V_26 , V_181 , V_116 ) ;
if ( V_49 == 0 )
V_49 = F_120 ( V_26 , V_97 , V_116 , V_157 ) ;
V_104:
if ( V_10 -> V_14 . V_35 . V_36 < V_37 ) {
if ( V_49 )
F_115 ( V_26 , NULL , & V_201 ) ;
else
F_115 ( V_26 , V_201 , & V_29 -> V_12 ) ;
}
return V_49 ;
}
static int
F_121 ( struct V_25 * V_26 , struct V_204 * V_31 )
{
struct V_28 * V_29 = V_28 ( V_26 ) ;
return F_122 ( & V_29 -> V_30 . V_205 , V_31 ) ;
}
static int
F_123 ( struct V_127 * V_27 , struct V_155 * V_70 )
{
struct V_134 * V_135 = & V_27 -> V_135 [ V_70 -> V_99 ] ;
struct V_9 * V_10 = F_16 ( V_27 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_14 ) ;
struct V_101 * V_158 = V_70 -> V_102 ;
int V_49 ;
V_70 -> V_206 . V_5 = NULL ;
V_70 -> V_206 . V_160 = 0 ;
V_70 -> V_206 . V_6 = V_70 -> V_71 << V_72 ;
V_70 -> V_206 . V_188 = 0 ;
V_70 -> V_206 . V_123 = false ;
if ( ! ( V_135 -> V_8 & V_137 ) )
return - V_57 ;
switch ( V_70 -> V_99 ) {
case V_136 :
return 0 ;
case V_106 :
#if F_60 ( V_131 )
if ( V_10 -> V_132 . V_133 ) {
V_70 -> V_206 . V_160 = V_70 -> V_175 << V_72 ;
V_70 -> V_206 . V_188 = V_10 -> V_132 . V_188 ;
V_70 -> V_206 . V_123 = ! V_10 -> V_132 . V_207 ;
}
#endif
if ( V_10 -> V_14 . V_35 . V_36 < V_37 || ! V_158 -> V_94 )
break;
case V_100 :
V_70 -> V_206 . V_160 = V_70 -> V_175 << V_72 ;
V_70 -> V_206 . V_188 = V_14 -> V_65 -> V_208 ( V_14 , 1 ) ;
V_70 -> V_206 . V_123 = true ;
if ( V_10 -> V_14 . V_35 . V_36 >= V_37 ) {
struct V_209 * V_210 = F_65 ( & V_10 -> V_14 ) ;
int V_40 = 12 ;
if ( V_10 -> V_14 . V_35 . V_36 >= V_211 )
V_40 = V_158 -> V_40 ;
V_49 = F_124 ( V_210 , V_158 -> V_6 << 12 , V_40 ,
& V_158 -> V_212 ) ;
if ( V_49 )
return V_49 ;
F_92 ( & V_158 -> V_212 , V_158 ) ;
V_70 -> V_206 . V_160 = V_158 -> V_212 . V_160 ;
}
break;
default:
return - V_57 ;
}
return 0 ;
}
static void
F_125 ( struct V_127 * V_27 , struct V_155 * V_70 )
{
struct V_101 * V_158 = V_70 -> V_102 ;
if ( ! V_158 -> V_212 . V_158 )
return;
F_113 ( & V_158 -> V_212 ) ;
F_91 ( & V_158 -> V_212 ) ;
}
static int
F_126 ( struct V_25 * V_26 )
{
struct V_9 * V_10 = F_16 ( V_26 -> V_27 ) ;
struct V_28 * V_29 = V_28 ( V_26 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_14 ) ;
T_1 V_213 = V_14 -> V_65 -> V_214 ( V_14 , 1 ) >> V_72 ;
int V_11 , V_49 ;
if ( V_26 -> V_70 . V_99 != V_100 ) {
if ( V_10 -> V_14 . V_35 . V_36 < V_37 ||
! F_127 ( V_29 ) )
return 0 ;
if ( V_26 -> V_70 . V_99 == V_136 ) {
F_28 ( V_29 , V_106 , 0 ) ;
V_49 = F_37 ( V_29 , false , false ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
if ( V_10 -> V_14 . V_35 . V_36 >= V_37 ||
V_26 -> V_70 . V_175 + V_26 -> V_70 . V_71 < V_213 )
return 0 ;
for ( V_11 = 0 ; V_11 < V_29 -> V_73 . V_85 ; ++ V_11 ) {
V_29 -> V_86 [ V_11 ] . V_81 = 0 ;
V_29 -> V_86 [ V_11 ] . V_82 = V_213 ;
}
for ( V_11 = 0 ; V_11 < V_29 -> V_73 . V_87 ; ++ V_11 ) {
V_29 -> V_88 [ V_11 ] . V_81 = 0 ;
V_29 -> V_88 [ V_11 ] . V_82 = V_213 ;
}
F_28 ( V_29 , V_77 , 0 ) ;
return F_37 ( V_29 , false , false ) ;
}
static int
F_128 ( struct V_126 * V_64 )
{
struct V_110 * V_111 = ( void * ) V_64 ;
struct V_9 * V_10 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_14 * V_215 ;
unsigned V_11 ;
int V_216 ;
bool V_217 = ! ! ( V_64 -> V_128 & V_218 ) ;
if ( V_64 -> V_219 != V_220 )
return 0 ;
if ( V_217 && V_64 -> V_44 ) {
F_129 ( V_64 -> V_44 , V_64 -> V_221 ,
V_111 -> V_112 , V_64 -> V_71 ) ;
V_64 -> V_219 = V_222 ;
return 0 ;
}
V_10 = F_16 ( V_64 -> V_27 ) ;
V_14 = F_2 ( & V_10 -> V_14 ) ;
V_2 = V_10 -> V_2 ;
V_215 = V_14 -> V_2 ;
if ( ! F_2 ( & V_10 -> V_14 ) -> V_65 -> V_66 &&
V_64 -> V_223 == V_224 )
return F_130 ( V_111 , V_2 -> V_2 ) ;
#if F_60 ( V_131 )
if ( V_10 -> V_132 . V_133 ) {
return F_131 ( V_64 ) ;
}
#endif
#if F_60 ( V_225 ) && F_60 ( V_226 )
if ( F_132 () ) {
return F_130 ( ( void * ) V_64 , V_2 -> V_2 ) ;
}
#endif
V_216 = F_133 ( V_64 ) ;
if ( V_216 ) {
return V_216 ;
}
for ( V_11 = 0 ; V_11 < V_64 -> V_71 ; V_11 ++ ) {
T_8 V_5 ;
V_5 = F_134 ( V_215 , V_64 -> V_221 [ V_11 ] , 0 , V_41 ,
V_227 ) ;
if ( F_135 ( V_215 , V_5 ) ) {
while ( V_11 -- ) {
F_136 ( V_215 , V_111 -> V_112 [ V_11 ] ,
V_41 , V_227 ) ;
V_111 -> V_112 [ V_11 ] = 0 ;
}
F_137 ( V_64 ) ;
return - V_228 ;
}
V_111 -> V_112 [ V_11 ] = V_5 ;
}
return 0 ;
}
static void
F_138 ( struct V_126 * V_64 )
{
struct V_110 * V_111 = ( void * ) V_64 ;
struct V_9 * V_10 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_14 * V_215 ;
unsigned V_11 ;
bool V_217 = ! ! ( V_64 -> V_128 & V_218 ) ;
if ( V_217 )
return;
V_10 = F_16 ( V_64 -> V_27 ) ;
V_14 = F_2 ( & V_10 -> V_14 ) ;
V_2 = V_10 -> V_2 ;
V_215 = V_14 -> V_2 ;
if ( ! F_2 ( & V_10 -> V_14 ) -> V_65 -> V_66 &&
V_64 -> V_223 == V_224 ) {
F_139 ( V_111 , V_2 -> V_2 ) ;
return;
}
#if F_60 ( V_131 )
if ( V_10 -> V_132 . V_133 ) {
F_140 ( V_64 ) ;
return;
}
#endif
#if F_60 ( V_225 ) && F_60 ( V_226 )
if ( F_132 () ) {
F_139 ( ( void * ) V_64 , V_2 -> V_2 ) ;
return;
}
#endif
for ( V_11 = 0 ; V_11 < V_64 -> V_71 ; V_11 ++ ) {
if ( V_111 -> V_112 [ V_11 ] ) {
F_136 ( V_215 , V_111 -> V_112 [ V_11 ] , V_41 ,
V_227 ) ;
}
}
F_137 ( V_64 ) ;
}
void
F_141 ( struct V_28 * V_29 , struct V_22 * V_19 , bool V_229 )
{
struct V_45 * V_203 = V_29 -> V_26 . V_203 ;
if ( V_229 )
F_142 ( V_203 , & V_19 -> V_188 ) ;
else if ( V_19 )
F_143 ( V_203 , & V_19 -> V_188 ) ;
}
struct V_199 *
F_144 ( struct V_28 * V_29 , struct V_230 * V_54 )
{
struct V_199 * V_159 ;
F_112 (vma, &nvbo->vma_list, head) {
if ( V_159 -> V_54 == V_54 )
return V_159 ;
}
return NULL ;
}
int
F_145 ( struct V_28 * V_29 , struct V_230 * V_54 ,
struct V_199 * V_159 )
{
const T_1 V_6 = V_29 -> V_26 . V_70 . V_71 << V_72 ;
int V_49 ;
V_49 = F_90 ( V_54 , V_6 , V_29 -> V_40 ,
V_180 , V_159 ) ;
if ( V_49 )
return V_49 ;
if ( V_29 -> V_26 . V_70 . V_99 != V_136 &&
( V_29 -> V_26 . V_70 . V_99 == V_100 ||
V_29 -> V_40 != V_159 -> V_54 -> V_55 -> V_51 ) )
F_92 ( V_159 , V_29 -> V_26 . V_70 . V_102 ) ;
F_146 ( & V_159 -> V_61 , & V_29 -> V_63 ) ;
V_159 -> V_231 = 1 ;
return 0 ;
}
void
F_147 ( struct V_28 * V_29 , struct V_199 * V_159 )
{
if ( V_159 -> V_158 ) {
if ( V_29 -> V_26 . V_70 . V_99 != V_136 )
F_113 ( V_159 ) ;
F_91 ( V_159 ) ;
F_148 ( & V_159 -> V_61 ) ;
}
}
