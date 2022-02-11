static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
int V_11 = V_4 - V_10 -> V_12 . V_4 ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_15 ) ;
struct V_16 * V_12 = & V_14 -> V_12 . V_17 [ V_11 ] ;
struct V_18 * V_19 ;
F_3 ( & V_4 -> V_20 ) ;
if ( V_12 -> V_7 )
V_14 -> V_12 . V_21 ( V_14 , V_11 , V_12 ) ;
if ( V_7 )
V_14 -> V_12 . V_22 ( V_14 , V_11 , V_5 , V_6 , V_7 , V_8 , V_12 ) ;
V_14 -> V_12 . V_23 ( V_14 , V_11 , V_12 ) ;
if ( ( V_19 = V_18 ( V_14 , V_24 ) ) )
V_19 -> V_25 ( V_19 , V_11 ) ;
if ( ( V_19 = V_18 ( V_14 , V_26 ) ) )
V_19 -> V_25 ( V_19 , V_11 ) ;
}
static struct V_3 *
F_4 ( struct V_1 * V_2 , int V_11 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_3 * V_12 = & V_10 -> V_12 . V_4 [ V_11 ] ;
F_5 ( & V_10 -> V_12 . V_27 ) ;
if ( ! V_12 -> V_28 &&
( ! V_12 -> V_20 || F_6 ( V_12 -> V_20 ) ) )
V_12 -> V_28 = true ;
else
V_12 = NULL ;
F_7 ( & V_10 -> V_12 . V_27 ) ;
return V_12 ;
}
static void
F_8 ( struct V_1 * V_2 , struct V_3 * V_12 ,
struct V_20 * V_20 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
if ( V_12 ) {
F_5 ( & V_10 -> V_12 . V_27 ) ;
V_12 -> V_20 = (struct V_29 * ) F_9 ( V_20 ) ;
V_12 -> V_28 = false ;
F_7 ( & V_10 -> V_12 . V_27 ) ;
}
}
static struct V_3 *
F_10 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_15 ) ;
struct V_3 * V_12 , * V_30 = NULL ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_14 -> V_12 . V_31 ; V_11 ++ ) {
V_12 = F_4 ( V_2 , V_11 ) ;
if ( V_7 && ! V_30 ) {
V_30 = V_12 ;
continue;
} else if ( V_12 && V_14 -> V_12 . V_17 [ V_11 ] . V_7 ) {
F_1 ( V_2 , V_12 , 0 , 0 , 0 , 0 ) ;
}
F_8 ( V_2 , V_12 , NULL ) ;
}
if ( V_30 )
F_1 ( V_2 , V_30 , V_5 , V_6 ,
V_7 , V_8 ) ;
return V_30 ;
}
static void
F_11 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
if ( F_13 ( V_36 -> V_37 . V_38 ) )
F_14 ( L_1 , V_33 ) ;
F_15 ( V_36 -> V_39 > 0 ) ;
F_8 ( V_2 , V_36 -> V_12 , NULL ) ;
F_16 ( V_36 ) ;
}
static void
F_17 ( struct V_35 * V_36 , T_1 V_8 ,
int * V_40 , int * V_6 )
{
struct V_9 * V_10 = F_12 ( V_36 -> V_33 . V_34 ) ;
struct V_41 * V_15 = & V_10 -> V_15 ;
if ( V_15 -> V_42 . V_43 < V_44 ) {
if ( V_36 -> V_45 ) {
if ( V_15 -> V_42 . V_46 >= 0x40 ) {
* V_40 = 65536 ;
* V_6 = F_18 ( * V_6 , 64 * V_36 -> V_45 ) ;
} else if ( V_15 -> V_42 . V_46 >= 0x30 ) {
* V_40 = 32768 ;
* V_6 = F_18 ( * V_6 , 64 * V_36 -> V_45 ) ;
} else if ( V_15 -> V_42 . V_46 >= 0x20 ) {
* V_40 = 16384 ;
* V_6 = F_18 ( * V_6 , 64 * V_36 -> V_45 ) ;
} else if ( V_15 -> V_42 . V_46 >= 0x10 ) {
* V_40 = 16384 ;
* V_6 = F_18 ( * V_6 , 32 * V_36 -> V_45 ) ;
}
}
} else {
* V_6 = F_18 ( * V_6 , ( 1 << V_36 -> V_47 ) ) ;
* V_40 = F_19 ( ( 1 << V_36 -> V_47 ) , * V_40 ) ;
}
* V_6 = F_18 ( * V_6 , V_48 ) ;
}
int
F_20 ( struct V_1 * V_2 , int V_6 , int V_40 ,
T_2 V_8 , T_2 V_45 , T_2 V_49 ,
struct V_50 * V_51 , struct V_52 * V_53 ,
struct V_35 * * V_54 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_35 * V_36 ;
T_3 V_55 ;
int V_56 ;
int type = V_57 ;
int V_58 = 12 ;
int V_59 ;
if ( V_10 -> V_60 . V_61 )
V_58 = V_10 -> V_60 . V_61 -> V_62 -> V_58 ;
V_59 = V_63 & ~ ( ( 1 << V_58 ) - 1 ) ;
if ( V_6 <= 0 || V_6 > V_59 ) {
F_21 ( V_10 , L_2 , ( T_1 ) V_6 ) ;
return - V_64 ;
}
if ( V_51 )
type = V_65 ;
V_36 = F_22 ( sizeof( struct V_35 ) , V_66 ) ;
if ( ! V_36 )
return - V_67 ;
F_23 ( & V_36 -> V_68 ) ;
F_23 ( & V_36 -> V_69 ) ;
F_23 ( & V_36 -> V_70 ) ;
V_36 -> V_45 = V_45 ;
V_36 -> V_49 = V_49 ;
V_36 -> V_33 . V_34 = & V_10 -> V_71 . V_34 ;
if ( ! F_24 ( F_25 ( & V_10 -> V_15 ) ) )
V_36 -> V_72 = V_8 & V_73 ;
V_36 -> V_47 = 12 ;
if ( V_10 -> V_60 . V_61 ) {
if ( ! ( V_8 & V_74 ) && V_6 > 256 * 1024 )
V_36 -> V_47 = V_10 -> V_60 . V_61 -> V_62 -> V_58 ;
}
F_17 ( V_36 , V_8 , & V_40 , & V_6 ) ;
V_36 -> V_33 . V_75 . V_76 = V_6 >> V_77 ;
F_26 ( V_36 , V_8 , 0 ) ;
V_55 = F_27 ( & V_10 -> V_71 . V_34 , V_6 ,
sizeof( struct V_35 ) ) ;
V_56 = F_28 ( & V_10 -> V_71 . V_34 , & V_36 -> V_33 , V_6 ,
type , & V_36 -> V_78 ,
V_40 >> V_77 , false , NULL , V_55 , V_51 ,
V_53 , F_11 ) ;
if ( V_56 ) {
return V_56 ;
}
* V_54 = V_36 ;
return 0 ;
}
static void
F_29 ( struct V_79 * V_80 , unsigned * V_81 , T_2 type , T_2 V_8 )
{
* V_81 = 0 ;
if ( type & V_82 )
V_80 [ ( * V_81 ) ++ ] . V_8 = V_82 | V_8 ;
if ( type & V_74 )
V_80 [ ( * V_81 ) ++ ] . V_8 = V_74 | V_8 ;
if ( type & V_83 )
V_80 [ ( * V_81 ) ++ ] . V_8 = V_83 | V_8 ;
}
static void
F_30 ( struct V_35 * V_36 , T_2 type )
{
struct V_9 * V_10 = F_12 ( V_36 -> V_33 . V_34 ) ;
T_1 V_84 = V_10 -> V_15 . V_42 . V_85 >> V_77 ;
unsigned V_11 , V_86 , V_87 ;
if ( V_10 -> V_15 . V_42 . V_43 == V_88 &&
V_36 -> V_45 && ( type & V_82 ) &&
V_36 -> V_33 . V_75 . V_76 < V_84 / 4 ) {
if ( V_36 -> V_49 & V_89 ) {
V_86 = V_84 / 2 ;
V_87 = ~ 0 ;
} else {
V_86 = 0 ;
V_87 = V_84 / 2 ;
}
for ( V_11 = 0 ; V_11 < V_36 -> V_78 . V_90 ; ++ V_11 ) {
V_36 -> V_91 [ V_11 ] . V_86 = V_86 ;
V_36 -> V_91 [ V_11 ] . V_87 = V_87 ;
}
for ( V_11 = 0 ; V_11 < V_36 -> V_78 . V_92 ; ++ V_11 ) {
V_36 -> V_93 [ V_11 ] . V_86 = V_86 ;
V_36 -> V_93 [ V_11 ] . V_87 = V_87 ;
}
}
}
void
F_26 ( struct V_35 * V_36 , T_2 type , T_2 V_94 )
{
struct V_95 * V_80 = & V_36 -> V_78 ;
T_2 V_8 = ( V_36 -> V_72 ? V_73 :
V_96 ) |
( V_36 -> V_39 ? V_97 : 0 ) ;
V_80 -> V_78 = V_36 -> V_91 ;
F_29 ( V_36 -> V_91 , & V_80 -> V_90 ,
type , V_8 ) ;
V_80 -> V_98 = V_36 -> V_93 ;
F_29 ( V_36 -> V_93 , & V_80 -> V_92 ,
type | V_94 , V_8 ) ;
F_30 ( V_36 , type ) ;
}
int
F_31 ( struct V_35 * V_36 , T_2 V_99 , bool V_100 )
{
struct V_9 * V_10 = F_12 ( V_36 -> V_33 . V_34 ) ;
struct V_32 * V_33 = & V_36 -> V_33 ;
bool V_101 = false , V_102 = false ;
int V_56 ;
V_56 = F_32 ( V_33 , false , false , false , NULL ) ;
if ( V_56 )
return V_56 ;
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 &&
V_99 == V_82 && V_100 ) {
if ( V_36 -> V_49 & V_103 ) {
if ( V_33 -> V_75 . V_104 == V_105 ) {
struct V_106 * V_75 = V_33 -> V_75 . V_107 ;
if ( ! F_33 ( & V_75 -> V_31 ) )
V_102 = true ;
}
V_36 -> V_49 &= ~ V_103 ;
V_101 = true ;
}
}
if ( V_36 -> V_39 ) {
if ( ! ( V_99 & ( 1 << V_33 -> V_75 . V_104 ) ) || V_102 ) {
F_34 ( V_10 , L_3
L_4 , V_33 ,
1 << V_33 -> V_75 . V_104 , V_99 ) ;
V_56 = - V_108 ;
}
V_36 -> V_39 ++ ;
goto V_109;
}
if ( V_102 ) {
F_26 ( V_36 , V_74 , 0 ) ;
V_56 = F_35 ( V_36 , false , false ) ;
if ( V_56 )
goto V_109;
}
V_36 -> V_39 ++ ;
F_26 ( V_36 , V_99 , 0 ) ;
V_36 -> V_39 -- ;
V_56 = F_35 ( V_36 , false , false ) ;
if ( V_56 )
goto V_109;
V_36 -> V_39 ++ ;
switch ( V_33 -> V_75 . V_104 ) {
case V_105 :
V_10 -> V_37 . V_110 -= V_33 -> V_75 . V_6 ;
break;
case V_111 :
V_10 -> V_37 . V_112 -= V_33 -> V_75 . V_6 ;
break;
default:
break;
}
V_109:
if ( V_101 && V_56 )
V_36 -> V_49 |= V_103 ;
F_36 ( V_33 ) ;
return V_56 ;
}
int
F_37 ( struct V_35 * V_36 )
{
struct V_9 * V_10 = F_12 ( V_36 -> V_33 . V_34 ) ;
struct V_32 * V_33 = & V_36 -> V_33 ;
int V_56 , V_113 ;
V_56 = F_32 ( V_33 , false , false , false , NULL ) ;
if ( V_56 )
return V_56 ;
V_113 = -- V_36 -> V_39 ;
F_38 ( V_113 < 0 ) ;
if ( V_113 )
goto V_109;
F_26 ( V_36 , V_33 -> V_75 . V_78 , 0 ) ;
V_56 = F_35 ( V_36 , false , false ) ;
if ( V_56 == 0 ) {
switch ( V_33 -> V_75 . V_104 ) {
case V_105 :
V_10 -> V_37 . V_110 += V_33 -> V_75 . V_6 ;
break;
case V_111 :
V_10 -> V_37 . V_112 += V_33 -> V_75 . V_6 ;
break;
default:
break;
}
}
V_109:
F_36 ( V_33 ) ;
return V_56 ;
}
int
F_39 ( struct V_35 * V_36 )
{
int V_56 ;
V_56 = F_32 ( & V_36 -> V_33 , false , false , false , NULL ) ;
if ( V_56 )
return V_56 ;
if ( ! V_36 -> V_72 )
V_56 = F_40 ( & V_36 -> V_33 , 0 , V_36 -> V_33 . V_75 . V_76 ,
& V_36 -> V_114 ) ;
F_36 ( & V_36 -> V_33 ) ;
return V_56 ;
}
void
F_41 ( struct V_35 * V_36 )
{
if ( ! V_36 )
return;
if ( ! V_36 -> V_72 )
F_42 ( & V_36 -> V_114 ) ;
}
void
F_43 ( struct V_35 * V_36 )
{
struct V_9 * V_10 = F_12 ( V_36 -> V_33 . V_34 ) ;
struct V_115 * V_15 = F_25 ( & V_10 -> V_15 ) ;
struct V_116 * V_117 = (struct V_116 * ) V_36 -> V_33 . V_71 ;
int V_11 ;
if ( ! V_117 )
return;
if ( V_36 -> V_72 )
return;
for ( V_11 = 0 ; V_11 < V_117 -> V_71 . V_76 ; V_11 ++ )
F_44 ( F_45 ( V_15 ) ,
V_117 -> V_118 [ V_11 ] , V_48 , V_119 ) ;
}
void
F_46 ( struct V_35 * V_36 )
{
struct V_9 * V_10 = F_12 ( V_36 -> V_33 . V_34 ) ;
struct V_115 * V_15 = F_25 ( & V_10 -> V_15 ) ;
struct V_116 * V_117 = (struct V_116 * ) V_36 -> V_33 . V_71 ;
int V_11 ;
if ( ! V_117 )
return;
if ( V_36 -> V_72 )
return;
for ( V_11 = 0 ; V_11 < V_117 -> V_71 . V_76 ; V_11 ++ )
F_47 ( F_45 ( V_15 ) ,
V_117 -> V_118 [ V_11 ] , V_48 , V_120 ) ;
}
int
F_35 ( struct V_35 * V_36 , bool V_121 ,
bool V_122 )
{
int V_56 ;
V_56 = F_48 ( & V_36 -> V_33 , & V_36 -> V_78 ,
V_121 , V_122 ) ;
if ( V_56 )
return V_56 ;
F_43 ( V_36 ) ;
return 0 ;
}
static inline void *
F_49 ( struct V_35 * V_36 , unsigned V_123 , void * V_75 , T_4 V_124 )
{
struct V_116 * V_125 ;
T_4 * V_126 = V_75 ;
V_123 *= V_124 ;
if ( V_126 ) {
V_126 += V_123 ;
} else {
V_125 = (struct V_116 * ) V_36 -> V_33 . V_71 ;
V_126 = V_125 -> V_127 [ V_123 / V_48 ] ;
V_126 += V_123 % V_48 ;
}
return V_126 ;
}
T_5
F_50 ( struct V_35 * V_36 , unsigned V_123 )
{
bool V_128 ;
T_5 * V_75 = F_51 ( & V_36 -> V_114 , & V_128 ) ;
V_75 = F_52 ( V_36 , V_123 , V_75 ) ;
if ( V_128 )
return F_53 ( ( void V_129 V_130 * ) V_75 ) ;
else
return * V_75 ;
}
void
F_54 ( struct V_35 * V_36 , unsigned V_123 , T_5 V_131 )
{
bool V_128 ;
T_5 * V_75 = F_51 ( & V_36 -> V_114 , & V_128 ) ;
V_75 = F_52 ( V_36 , V_123 , V_75 ) ;
if ( V_128 )
F_55 ( V_131 , ( void V_129 V_130 * ) V_75 ) ;
else
* V_75 = V_131 ;
}
T_1
F_56 ( struct V_35 * V_36 , unsigned V_123 )
{
bool V_128 ;
T_1 * V_75 = F_51 ( & V_36 -> V_114 , & V_128 ) ;
V_75 = F_52 ( V_36 , V_123 , V_75 ) ;
if ( V_128 )
return F_57 ( ( void V_129 V_130 * ) V_75 ) ;
else
return * V_75 ;
}
void
F_58 ( struct V_35 * V_36 , unsigned V_123 , T_1 V_131 )
{
bool V_128 ;
T_1 * V_75 = F_51 ( & V_36 -> V_114 , & V_128 ) ;
V_75 = F_52 ( V_36 , V_123 , V_75 ) ;
if ( V_128 )
F_59 ( V_131 , ( void V_129 V_130 * ) V_75 ) ;
else
* V_75 = V_131 ;
}
static struct V_132 *
F_60 ( struct V_133 * V_34 , unsigned long V_6 ,
T_2 V_134 , struct V_135 * V_136 )
{
#if V_137
struct V_9 * V_10 = F_12 ( V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_10 -> V_138 . V_139 == V_140 ) {
return F_61 ( V_34 , V_2 -> V_138 -> V_141 , V_6 ,
V_134 , V_136 ) ;
}
#endif
return F_62 ( V_34 , V_6 , V_134 , V_136 ) ;
}
static int
F_63 ( struct V_133 * V_34 , T_2 V_8 )
{
return 0 ;
}
static int
F_64 ( struct V_133 * V_34 , T_2 type ,
struct V_142 * V_143 )
{
struct V_9 * V_10 = F_12 ( V_34 ) ;
switch ( type ) {
case V_144 :
V_143 -> V_8 = V_145 ;
V_143 -> V_146 = V_96 ;
V_143 -> V_147 = V_148 ;
break;
case V_105 :
V_143 -> V_8 = V_149 |
V_145 ;
V_143 -> V_146 = V_73 |
V_150 ;
V_143 -> V_147 = V_150 ;
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 ) {
if ( F_65 ( & V_10 -> V_15 ) -> V_151 ) {
V_143 -> V_146 = V_73 ;
V_143 -> V_147 = V_73 ;
}
V_143 -> V_152 = & V_153 ;
V_143 -> V_154 = false ;
V_143 -> V_155 = true ;
} else {
V_143 -> V_152 = & V_156 ;
}
break;
case V_111 :
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 )
V_143 -> V_152 = & V_157 ;
else
if ( V_10 -> V_138 . V_139 != V_140 )
V_143 -> V_152 = & V_158 ;
else
V_143 -> V_152 = & V_156 ;
if ( V_10 -> V_138 . V_139 == V_140 ) {
V_143 -> V_8 = V_145 ;
V_143 -> V_146 = V_73 |
V_150 ;
V_143 -> V_147 = V_150 ;
} else {
V_143 -> V_8 = V_145 |
V_159 ;
V_143 -> V_146 = V_96 ;
V_143 -> V_147 = V_148 ;
}
break;
default:
return - V_64 ;
}
return 0 ;
}
static void
F_66 ( struct V_32 * V_33 , struct V_95 * V_80 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
switch ( V_33 -> V_75 . V_104 ) {
case V_105 :
F_26 ( V_36 , V_74 ,
V_83 ) ;
break;
default:
F_26 ( V_36 , V_83 , 0 ) ;
break;
}
* V_80 = V_36 -> V_78 ;
}
static int
F_67 ( struct V_160 * V_161 , T_1 V_162 )
{
int V_56 = F_68 ( V_161 , 2 ) ;
if ( V_56 == 0 ) {
F_69 ( V_161 , V_163 , 0x0000 , 1 ) ;
F_70 ( V_161 , V_162 & 0x0000ffff ) ;
F_71 ( V_161 ) ;
}
return V_56 ;
}
static int
F_72 ( struct V_160 * V_161 , struct V_32 * V_33 ,
struct V_164 * V_165 , struct V_164 * V_166 )
{
struct V_106 * V_167 = V_165 -> V_107 ;
int V_56 = F_68 ( V_161 , 10 ) ;
if ( V_56 == 0 ) {
F_69 ( V_161 , V_163 , 0x0400 , 8 ) ;
F_70 ( V_161 , F_73 ( V_167 -> V_168 [ 0 ] . V_169 ) ) ;
F_70 ( V_161 , F_74 ( V_167 -> V_168 [ 0 ] . V_169 ) ) ;
F_70 ( V_161 , F_73 ( V_167 -> V_168 [ 1 ] . V_169 ) ) ;
F_70 ( V_161 , F_74 ( V_167 -> V_168 [ 1 ] . V_169 ) ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_166 -> V_76 ) ;
F_75 ( V_161 , V_163 , 0x0300 , 0x0386 ) ;
}
return V_56 ;
}
static int
F_76 ( struct V_160 * V_161 , T_1 V_162 )
{
int V_56 = F_68 ( V_161 , 2 ) ;
if ( V_56 == 0 ) {
F_69 ( V_161 , V_163 , 0x0000 , 1 ) ;
F_70 ( V_161 , V_162 ) ;
}
return V_56 ;
}
static int
F_77 ( struct V_160 * V_161 , struct V_32 * V_33 ,
struct V_164 * V_165 , struct V_164 * V_166 )
{
struct V_106 * V_167 = V_165 -> V_107 ;
T_6 V_170 = V_167 -> V_168 [ 0 ] . V_169 ;
T_6 V_171 = V_167 -> V_168 [ 1 ] . V_169 ;
T_1 V_172 = V_166 -> V_76 ;
int V_56 ;
V_172 = V_166 -> V_76 ;
while ( V_172 ) {
int V_173 = ( V_172 > 8191 ) ? 8191 : V_172 ;
V_56 = F_68 ( V_161 , 11 ) ;
if ( V_56 )
return V_56 ;
F_69 ( V_161 , V_163 , 0x030c , 8 ) ;
F_70 ( V_161 , F_73 ( V_170 ) ) ;
F_70 ( V_161 , F_74 ( V_170 ) ) ;
F_70 ( V_161 , F_73 ( V_171 ) ) ;
F_70 ( V_161 , F_74 ( V_171 ) ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_173 ) ;
F_69 ( V_161 , V_163 , 0x0300 , 1 ) ;
F_70 ( V_161 , 0x00000110 ) ;
V_172 -= V_173 ;
V_170 += ( V_48 * V_173 ) ;
V_171 += ( V_48 * V_173 ) ;
}
return 0 ;
}
static int
F_78 ( struct V_160 * V_161 , struct V_32 * V_33 ,
struct V_164 * V_165 , struct V_164 * V_166 )
{
struct V_106 * V_167 = V_165 -> V_107 ;
T_6 V_170 = V_167 -> V_168 [ 0 ] . V_169 ;
T_6 V_171 = V_167 -> V_168 [ 1 ] . V_169 ;
T_1 V_172 = V_166 -> V_76 ;
int V_56 ;
V_172 = V_166 -> V_76 ;
while ( V_172 ) {
int V_173 = ( V_172 > 2047 ) ? 2047 : V_172 ;
V_56 = F_68 ( V_161 , 12 ) ;
if ( V_56 )
return V_56 ;
F_69 ( V_161 , V_163 , 0x0238 , 2 ) ;
F_70 ( V_161 , F_73 ( V_171 ) ) ;
F_70 ( V_161 , F_74 ( V_171 ) ) ;
F_69 ( V_161 , V_163 , 0x030c , 6 ) ;
F_70 ( V_161 , F_73 ( V_170 ) ) ;
F_70 ( V_161 , F_74 ( V_170 ) ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_173 ) ;
F_69 ( V_161 , V_163 , 0x0300 , 1 ) ;
F_70 ( V_161 , 0x00100110 ) ;
V_172 -= V_173 ;
V_170 += ( V_48 * V_173 ) ;
V_171 += ( V_48 * V_173 ) ;
}
return 0 ;
}
static int
F_79 ( struct V_160 * V_161 , struct V_32 * V_33 ,
struct V_164 * V_165 , struct V_164 * V_166 )
{
struct V_106 * V_167 = V_165 -> V_107 ;
T_6 V_170 = V_167 -> V_168 [ 0 ] . V_169 ;
T_6 V_171 = V_167 -> V_168 [ 1 ] . V_169 ;
T_1 V_172 = V_166 -> V_76 ;
int V_56 ;
V_172 = V_166 -> V_76 ;
while ( V_172 ) {
int V_173 = ( V_172 > 8191 ) ? 8191 : V_172 ;
V_56 = F_68 ( V_161 , 11 ) ;
if ( V_56 )
return V_56 ;
F_80 ( V_161 , V_163 , 0x030c , 8 ) ;
F_70 ( V_161 , F_73 ( V_170 ) ) ;
F_70 ( V_161 , F_74 ( V_170 ) ) ;
F_70 ( V_161 , F_73 ( V_171 ) ) ;
F_70 ( V_161 , F_74 ( V_171 ) ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_173 ) ;
F_80 ( V_161 , V_163 , 0x0300 , 1 ) ;
F_70 ( V_161 , 0x00000110 ) ;
V_172 -= V_173 ;
V_170 += ( V_48 * V_173 ) ;
V_171 += ( V_48 * V_173 ) ;
}
return 0 ;
}
static int
F_81 ( struct V_160 * V_161 , struct V_32 * V_33 ,
struct V_164 * V_165 , struct V_164 * V_166 )
{
struct V_106 * V_167 = V_165 -> V_107 ;
int V_56 = F_68 ( V_161 , 7 ) ;
if ( V_56 == 0 ) {
F_80 ( V_161 , V_163 , 0x0320 , 6 ) ;
F_70 ( V_161 , F_73 ( V_167 -> V_168 [ 0 ] . V_169 ) ) ;
F_70 ( V_161 , F_74 ( V_167 -> V_168 [ 0 ] . V_169 ) ) ;
F_70 ( V_161 , F_73 ( V_167 -> V_168 [ 1 ] . V_169 ) ) ;
F_70 ( V_161 , F_74 ( V_167 -> V_168 [ 1 ] . V_169 ) ) ;
F_70 ( V_161 , 0x00000000 ) ;
F_70 ( V_161 , V_166 -> V_76 << V_77 ) ;
}
return V_56 ;
}
static int
F_82 ( struct V_160 * V_161 , struct V_32 * V_33 ,
struct V_164 * V_165 , struct V_164 * V_166 )
{
struct V_106 * V_167 = V_165 -> V_107 ;
int V_56 = F_68 ( V_161 , 7 ) ;
if ( V_56 == 0 ) {
F_80 ( V_161 , V_163 , 0x0304 , 6 ) ;
F_70 ( V_161 , V_166 -> V_76 << V_77 ) ;
F_70 ( V_161 , F_73 ( V_167 -> V_168 [ 0 ] . V_169 ) ) ;
F_70 ( V_161 , F_74 ( V_167 -> V_168 [ 0 ] . V_169 ) ) ;
F_70 ( V_161 , F_73 ( V_167 -> V_168 [ 1 ] . V_169 ) ) ;
F_70 ( V_161 , F_74 ( V_167 -> V_168 [ 1 ] . V_169 ) ) ;
F_70 ( V_161 , 0x00000000 ) ;
}
return V_56 ;
}
static int
F_83 ( struct V_160 * V_161 , T_1 V_162 )
{
int V_56 = F_68 ( V_161 , 6 ) ;
if ( V_56 == 0 ) {
F_80 ( V_161 , V_163 , 0x0000 , 1 ) ;
F_70 ( V_161 , V_162 ) ;
F_80 ( V_161 , V_163 , 0x0180 , 3 ) ;
F_70 ( V_161 , V_161 -> V_10 -> V_174 . V_162 ) ;
F_70 ( V_161 , V_161 -> V_175 . V_162 ) ;
F_70 ( V_161 , V_161 -> V_175 . V_162 ) ;
}
return V_56 ;
}
static int
F_84 ( struct V_160 * V_161 , struct V_32 * V_33 ,
struct V_164 * V_165 , struct V_164 * V_166 )
{
struct V_106 * V_167 = V_165 -> V_107 ;
T_6 V_176 = ( V_166 -> V_76 << V_77 ) ;
T_6 V_170 = V_167 -> V_168 [ 0 ] . V_169 ;
T_6 V_171 = V_167 -> V_168 [ 1 ] . V_169 ;
int V_177 = ! ! V_167 -> V_99 ;
int V_178 = ! ! ( (struct V_106 * ) V_166 -> V_107 ) -> V_99 ;
int V_56 ;
while ( V_176 ) {
T_1 V_179 , V_180 , V_181 ;
V_56 = F_68 ( V_161 , 18 + 6 * ( V_177 + V_178 ) ) ;
if ( V_56 )
return V_56 ;
V_179 = F_85 ( V_176 , ( T_6 ) ( 4 * 1024 * 1024 ) ) ;
V_180 = 16 * 4 ;
V_181 = V_179 / V_180 ;
if ( V_177 ) {
F_80 ( V_161 , V_163 , 0x0200 , 7 ) ;
F_70 ( V_161 , 0 ) ;
F_70 ( V_161 , 0 ) ;
F_70 ( V_161 , V_180 ) ;
F_70 ( V_161 , V_181 ) ;
F_70 ( V_161 , 1 ) ;
F_70 ( V_161 , 0 ) ;
F_70 ( V_161 , 0 ) ;
} else {
F_80 ( V_161 , V_163 , 0x0200 , 1 ) ;
F_70 ( V_161 , 1 ) ;
}
if ( V_178 ) {
F_80 ( V_161 , V_163 , 0x021c , 7 ) ;
F_70 ( V_161 , 0 ) ;
F_70 ( V_161 , 0 ) ;
F_70 ( V_161 , V_180 ) ;
F_70 ( V_161 , V_181 ) ;
F_70 ( V_161 , 1 ) ;
F_70 ( V_161 , 0 ) ;
F_70 ( V_161 , 0 ) ;
} else {
F_80 ( V_161 , V_163 , 0x021c , 1 ) ;
F_70 ( V_161 , 1 ) ;
}
F_80 ( V_161 , V_163 , 0x0238 , 2 ) ;
F_70 ( V_161 , F_73 ( V_170 ) ) ;
F_70 ( V_161 , F_73 ( V_171 ) ) ;
F_80 ( V_161 , V_163 , 0x030c , 8 ) ;
F_70 ( V_161 , F_74 ( V_170 ) ) ;
F_70 ( V_161 , F_74 ( V_171 ) ) ;
F_70 ( V_161 , V_180 ) ;
F_70 ( V_161 , V_180 ) ;
F_70 ( V_161 , V_180 ) ;
F_70 ( V_161 , V_181 ) ;
F_70 ( V_161 , 0x00000101 ) ;
F_70 ( V_161 , 0x00000000 ) ;
F_80 ( V_161 , V_163 , V_182 , 1 ) ;
F_70 ( V_161 , 0 ) ;
V_176 -= V_179 ;
V_170 += V_179 ;
V_171 += V_179 ;
}
return 0 ;
}
static int
F_86 ( struct V_160 * V_161 , T_1 V_162 )
{
int V_56 = F_68 ( V_161 , 4 ) ;
if ( V_56 == 0 ) {
F_80 ( V_161 , V_163 , 0x0000 , 1 ) ;
F_70 ( V_161 , V_162 ) ;
F_80 ( V_161 , V_163 , 0x0180 , 1 ) ;
F_70 ( V_161 , V_161 -> V_10 -> V_174 . V_162 ) ;
}
return V_56 ;
}
static inline T_2
F_87 ( struct V_32 * V_33 ,
struct V_160 * V_161 , struct V_164 * V_75 )
{
if ( V_75 -> V_104 == V_111 )
return V_183 ;
return V_161 -> V_175 . V_162 ;
}
static int
F_88 ( struct V_160 * V_161 , struct V_32 * V_33 ,
struct V_164 * V_165 , struct V_164 * V_166 )
{
T_1 V_170 = V_165 -> V_184 << V_77 ;
T_1 V_171 = V_166 -> V_184 << V_77 ;
T_1 V_172 = V_166 -> V_76 ;
int V_56 ;
V_56 = F_68 ( V_161 , 3 ) ;
if ( V_56 )
return V_56 ;
F_80 ( V_161 , V_163 , V_185 , 2 ) ;
F_70 ( V_161 , F_87 ( V_33 , V_161 , V_165 ) ) ;
F_70 ( V_161 , F_87 ( V_33 , V_161 , V_166 ) ) ;
V_172 = V_166 -> V_76 ;
while ( V_172 ) {
int V_173 = ( V_172 > 2047 ) ? 2047 : V_172 ;
V_56 = F_68 ( V_161 , 11 ) ;
if ( V_56 )
return V_56 ;
F_80 ( V_161 , V_163 ,
V_186 , 8 ) ;
F_70 ( V_161 , V_170 ) ;
F_70 ( V_161 , V_171 ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_48 ) ;
F_70 ( V_161 , V_173 ) ;
F_70 ( V_161 , 0x00000101 ) ;
F_70 ( V_161 , 0x00000000 ) ;
F_80 ( V_161 , V_163 , V_182 , 1 ) ;
F_70 ( V_161 , 0 ) ;
V_172 -= V_173 ;
V_170 += ( V_48 * V_173 ) ;
V_171 += ( V_48 * V_173 ) ;
}
return 0 ;
}
static int
F_89 ( struct V_9 * V_10 , struct V_32 * V_33 ,
struct V_164 * V_75 )
{
struct V_106 * V_187 = V_33 -> V_75 . V_107 ;
struct V_106 * V_188 = V_75 -> V_107 ;
T_6 V_6 = ( T_6 ) V_75 -> V_76 << V_77 ;
int V_56 ;
V_56 = F_90 ( V_10 -> V_60 . V_61 , V_6 , V_187 -> V_47 ,
V_189 , & V_187 -> V_168 [ 0 ] ) ;
if ( V_56 )
return V_56 ;
V_56 = F_90 ( V_10 -> V_60 . V_61 , V_6 , V_188 -> V_47 ,
V_189 , & V_187 -> V_168 [ 1 ] ) ;
if ( V_56 ) {
F_91 ( & V_187 -> V_168 [ 0 ] ) ;
return V_56 ;
}
F_92 ( & V_187 -> V_168 [ 0 ] , V_187 ) ;
F_92 ( & V_187 -> V_168 [ 1 ] , V_188 ) ;
return 0 ;
}
static int
F_93 ( struct V_32 * V_33 , int V_102 , bool V_190 ,
bool V_122 , struct V_164 * V_166 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_160 * V_161 = V_10 -> V_71 . V_161 ;
struct V_191 * V_192 = ( void * ) F_94 ( & V_161 -> V_15 -> V_193 ) ;
struct V_29 * V_20 ;
int V_56 ;
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 ) {
V_56 = F_89 ( V_10 , V_33 , V_166 ) ;
if ( V_56 )
return V_56 ;
}
F_95 ( & V_192 -> V_194 , V_195 ) ;
V_56 = F_96 ( V_35 ( V_33 ) , V_161 , true , V_190 ) ;
if ( V_56 == 0 ) {
V_56 = V_10 -> V_71 . V_196 ( V_161 , V_33 , & V_33 -> V_75 , V_166 ) ;
if ( V_56 == 0 ) {
V_56 = F_97 ( V_161 , false , & V_20 ) ;
if ( V_56 == 0 ) {
V_56 = F_98 ( V_33 ,
& V_20 -> V_193 ,
V_102 ,
V_122 ,
V_166 ) ;
F_3 ( & V_20 ) ;
}
}
}
F_99 ( & V_192 -> V_194 ) ;
return V_56 ;
}
void
F_100 ( struct V_9 * V_10 )
{
static const struct {
const char * V_197 ;
int V_19 ;
T_1 V_198 ;
int (* F_101)( struct V_160 * ,
struct V_32 * ,
struct V_164 * , struct V_164 * );
int (* V_22)( struct V_160 * , T_1 V_162 );
} V_199 [] = {
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
} , * V_200 = V_199 ;
const char * V_197 = L_11 ;
int V_56 ;
do {
struct V_160 * V_161 ;
if ( V_200 -> V_19 )
V_161 = V_10 -> V_201 ;
else
V_161 = V_10 -> V_202 ;
if ( V_161 == NULL )
continue;
V_56 = F_102 ( V_161 -> V_203 , NULL ,
V_200 -> V_198 | ( V_200 -> V_19 << 16 ) ,
V_200 -> V_198 , NULL , 0 ,
& V_10 -> V_71 . V_204 ) ;
if ( V_56 == 0 ) {
V_56 = V_200 -> V_22 ( V_161 , V_10 -> V_71 . V_204 . V_162 ) ;
if ( V_56 ) {
F_103 ( & V_10 -> V_71 . V_204 ) ;
continue;
}
V_10 -> V_71 . V_196 = V_200 -> F_101 ;
V_10 -> V_71 . V_161 = V_161 ;
V_197 = V_200 -> V_197 ;
break;
}
} while ( ( ++ V_200 ) -> F_101 );
F_104 ( V_10 , L_12 , V_197 ) ;
}
static int
F_105 ( struct V_32 * V_33 , bool V_102 , bool V_190 ,
bool V_122 , struct V_164 * V_166 )
{
struct V_79 V_205 = {
. V_86 = 0 ,
. V_87 = 0 ,
. V_8 = V_74 | V_96
} ;
struct V_95 V_78 ;
struct V_164 V_206 ;
int V_56 ;
V_78 . V_90 = V_78 . V_92 = 1 ;
V_78 . V_78 = V_78 . V_98 = & V_205 ;
V_206 = * V_166 ;
V_206 . V_107 = NULL ;
V_56 = F_106 ( V_33 , & V_78 , & V_206 , V_190 , V_122 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_107 ( V_33 -> V_71 , & V_206 ) ;
if ( V_56 )
goto V_109;
V_56 = F_93 ( V_33 , true , V_190 , V_122 , & V_206 ) ;
if ( V_56 )
goto V_109;
V_56 = F_108 ( V_33 , true , V_122 , V_166 ) ;
V_109:
F_109 ( V_33 , & V_206 ) ;
return V_56 ;
}
static int
F_110 ( struct V_32 * V_33 , bool V_102 , bool V_190 ,
bool V_122 , struct V_164 * V_166 )
{
struct V_79 V_205 = {
. V_86 = 0 ,
. V_87 = 0 ,
. V_8 = V_74 | V_96
} ;
struct V_95 V_78 ;
struct V_164 V_206 ;
int V_56 ;
V_78 . V_90 = V_78 . V_92 = 1 ;
V_78 . V_78 = V_78 . V_98 = & V_205 ;
V_206 = * V_166 ;
V_206 . V_107 = NULL ;
V_56 = F_106 ( V_33 , & V_78 , & V_206 , V_190 , V_122 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_108 ( V_33 , true , V_122 , & V_206 ) ;
if ( V_56 )
goto V_109;
V_56 = F_93 ( V_33 , true , V_190 , V_122 , V_166 ) ;
if ( V_56 )
goto V_109;
V_109:
F_109 ( V_33 , & V_206 ) ;
return V_56 ;
}
static void
F_111 ( struct V_32 * V_33 , struct V_164 * V_166 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_207 * V_168 ;
if ( V_33 -> V_208 != F_11 )
return;
F_112 (vma, &nvbo->vma_list, head) {
if ( V_166 && V_166 -> V_104 != V_144 &&
( V_166 -> V_104 == V_105 ||
V_36 -> V_47 != V_168 -> V_61 -> V_62 -> V_58 ) ) {
F_92 ( V_168 , V_166 -> V_107 ) ;
} else {
F_113 ( V_168 ) ;
}
}
}
static int
F_114 ( struct V_32 * V_33 , struct V_164 * V_166 ,
struct V_3 * * V_209 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
T_6 V_169 = V_166 -> V_184 << V_77 ;
* V_209 = NULL ;
if ( V_166 -> V_104 != V_105 )
return 0 ;
if ( V_10 -> V_15 . V_42 . V_43 >= V_88 ) {
* V_209 = F_10 ( V_2 , V_169 , V_166 -> V_6 ,
V_36 -> V_45 ,
V_36 -> V_49 ) ;
}
return 0 ;
}
static void
F_115 ( struct V_32 * V_33 ,
struct V_3 * V_209 ,
struct V_3 * * V_210 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_20 * V_20 = F_116 ( V_33 -> V_211 ) ;
F_8 ( V_2 , * V_210 , V_20 ) ;
* V_210 = V_209 ;
}
static int
F_117 ( struct V_32 * V_33 , bool V_102 , bool V_190 ,
bool V_122 , struct V_164 * V_166 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_164 * V_165 = & V_33 -> V_75 ;
struct V_3 * V_209 = NULL ;
int V_56 = 0 ;
if ( V_36 -> V_39 )
F_21 ( V_10 , L_13 , V_36 ) ;
if ( V_10 -> V_15 . V_42 . V_43 < V_44 ) {
V_56 = F_114 ( V_33 , V_166 , & V_209 ) ;
if ( V_56 )
return V_56 ;
}
if ( V_165 -> V_104 == V_144 && ! V_33 -> V_71 ) {
F_118 ( V_33 -> V_75 . V_107 != NULL ) ;
V_33 -> V_75 = * V_166 ;
V_166 -> V_107 = NULL ;
goto V_109;
}
if ( V_10 -> V_71 . V_196 ) {
if ( V_166 -> V_104 == V_144 )
V_56 = F_105 ( V_33 , V_102 , V_190 ,
V_122 , V_166 ) ;
else if ( V_165 -> V_104 == V_144 )
V_56 = F_110 ( V_33 , V_102 , V_190 ,
V_122 , V_166 ) ;
else
V_56 = F_93 ( V_33 , V_102 , V_190 ,
V_122 , V_166 ) ;
if ( ! V_56 )
goto V_109;
}
V_56 = F_119 ( V_33 , true , V_190 , V_122 ) ;
if ( V_56 == 0 )
V_56 = F_120 ( V_33 , V_102 , V_122 , V_166 ) ;
V_109:
if ( V_10 -> V_15 . V_42 . V_43 < V_44 ) {
if ( V_56 )
F_115 ( V_33 , NULL , & V_209 ) ;
else
F_115 ( V_33 , V_209 , & V_36 -> V_12 ) ;
}
return V_56 ;
}
static int
F_121 ( struct V_32 * V_33 , struct V_212 * V_38 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
return F_122 ( & V_36 -> V_37 . V_213 , V_38 ) ;
}
static int
F_123 ( struct V_133 * V_34 , struct V_164 * V_75 )
{
struct V_142 * V_143 = & V_34 -> V_143 [ V_75 -> V_104 ] ;
struct V_9 * V_10 = F_12 ( V_34 ) ;
struct V_106 * V_167 = V_75 -> V_107 ;
int V_56 ;
V_75 -> V_214 . V_5 = NULL ;
V_75 -> V_214 . V_169 = 0 ;
V_75 -> V_214 . V_6 = V_75 -> V_76 << V_77 ;
V_75 -> V_214 . V_193 = 0 ;
V_75 -> V_214 . V_128 = false ;
if ( ! ( V_143 -> V_8 & V_145 ) )
return - V_64 ;
switch ( V_75 -> V_104 ) {
case V_144 :
return 0 ;
case V_111 :
#if V_137
if ( V_10 -> V_138 . V_139 == V_140 ) {
V_75 -> V_214 . V_169 = V_75 -> V_184 << V_77 ;
V_75 -> V_214 . V_193 = V_10 -> V_138 . V_193 ;
V_75 -> V_214 . V_128 = ! V_10 -> V_2 -> V_138 -> V_215 ;
}
#endif
if ( V_10 -> V_15 . V_42 . V_43 < V_44 || ! V_167 -> V_99 )
break;
case V_105 :
V_75 -> V_214 . V_169 = V_75 -> V_184 << V_77 ;
V_75 -> V_214 . V_193 = F_124 ( F_25 ( & V_10 -> V_15 ) , 1 ) ;
V_75 -> V_214 . V_128 = true ;
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 ) {
struct V_216 * V_217 = F_65 ( & V_10 -> V_15 ) ;
V_56 = V_217 -> V_218 ( V_217 , V_167 , V_189 ,
& V_167 -> V_219 ) ;
if ( V_56 )
return V_56 ;
V_75 -> V_214 . V_169 = V_167 -> V_219 . V_169 ;
}
break;
default:
return - V_64 ;
}
return 0 ;
}
static void
F_125 ( struct V_133 * V_34 , struct V_164 * V_75 )
{
struct V_9 * V_10 = F_12 ( V_34 ) ;
struct V_216 * V_217 = F_65 ( & V_10 -> V_15 ) ;
struct V_106 * V_167 = V_75 -> V_107 ;
if ( ! V_167 -> V_219 . V_167 )
return;
V_217 -> V_220 ( V_217 , & V_167 -> V_219 ) ;
}
static int
F_126 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_41 * V_15 = & V_10 -> V_15 ;
T_1 V_221 = F_127 ( F_25 ( V_15 ) , 1 ) >> V_77 ;
int V_11 , V_56 ;
if ( V_33 -> V_75 . V_104 != V_105 ) {
if ( V_10 -> V_15 . V_42 . V_43 < V_44 ||
! F_128 ( V_36 ) )
return 0 ;
if ( V_33 -> V_75 . V_104 == V_144 ) {
F_26 ( V_36 , V_111 , 0 ) ;
V_56 = F_35 ( V_36 , false , false ) ;
if ( V_56 )
return V_56 ;
}
return 0 ;
}
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 ||
V_33 -> V_75 . V_184 + V_33 -> V_75 . V_76 < V_221 )
return 0 ;
for ( V_11 = 0 ; V_11 < V_36 -> V_78 . V_90 ; ++ V_11 ) {
V_36 -> V_91 [ V_11 ] . V_86 = 0 ;
V_36 -> V_91 [ V_11 ] . V_87 = V_221 ;
}
for ( V_11 = 0 ; V_11 < V_36 -> V_78 . V_92 ; ++ V_11 ) {
V_36 -> V_93 [ V_11 ] . V_86 = 0 ;
V_36 -> V_93 [ V_11 ] . V_87 = V_221 ;
}
F_26 ( V_36 , V_82 , 0 ) ;
return F_35 ( V_36 , false , false ) ;
}
static int
F_129 ( struct V_132 * V_71 )
{
struct V_116 * V_117 = ( void * ) V_71 ;
struct V_9 * V_10 ;
struct V_115 * V_15 ;
struct V_1 * V_2 ;
struct V_15 * V_222 ;
unsigned V_11 ;
int V_223 ;
bool V_224 = ! ! ( V_71 -> V_134 & V_225 ) ;
if ( V_71 -> V_226 != V_227 )
return 0 ;
if ( V_224 && V_71 -> V_51 ) {
F_130 ( V_71 -> V_51 , V_71 -> V_228 ,
V_117 -> V_118 , V_71 -> V_76 ) ;
V_71 -> V_226 = V_229 ;
return 0 ;
}
V_10 = F_12 ( V_71 -> V_34 ) ;
V_15 = F_25 ( & V_10 -> V_15 ) ;
V_2 = V_10 -> V_2 ;
V_222 = F_45 ( V_15 ) ;
if ( ! F_24 ( V_15 ) &&
V_71 -> V_230 == V_231 )
return F_131 ( V_117 , V_2 -> V_2 ) ;
#if V_137
if ( V_10 -> V_138 . V_139 == V_140 ) {
return F_132 ( V_71 ) ;
}
#endif
#ifdef F_133
if ( F_134 () ) {
return F_131 ( ( void * ) V_71 , V_2 -> V_2 ) ;
}
#endif
V_223 = F_135 ( V_71 ) ;
if ( V_223 ) {
return V_223 ;
}
for ( V_11 = 0 ; V_11 < V_71 -> V_76 ; V_11 ++ ) {
T_7 V_5 ;
V_5 = F_136 ( V_222 , V_71 -> V_228 [ V_11 ] , 0 , V_48 ,
V_232 ) ;
if ( F_137 ( V_222 , V_5 ) ) {
while ( -- V_11 ) {
F_138 ( V_222 , V_117 -> V_118 [ V_11 ] ,
V_48 , V_232 ) ;
V_117 -> V_118 [ V_11 ] = 0 ;
}
F_139 ( V_71 ) ;
return - V_233 ;
}
V_117 -> V_118 [ V_11 ] = V_5 ;
}
return 0 ;
}
static void
F_140 ( struct V_132 * V_71 )
{
struct V_116 * V_117 = ( void * ) V_71 ;
struct V_9 * V_10 ;
struct V_115 * V_15 ;
struct V_1 * V_2 ;
struct V_15 * V_222 ;
unsigned V_11 ;
bool V_224 = ! ! ( V_71 -> V_134 & V_225 ) ;
if ( V_224 )
return;
V_10 = F_12 ( V_71 -> V_34 ) ;
V_15 = F_25 ( & V_10 -> V_15 ) ;
V_2 = V_10 -> V_2 ;
V_222 = F_45 ( V_15 ) ;
if ( ! F_24 ( V_15 ) &&
V_71 -> V_230 == V_231 ) {
F_141 ( V_117 , V_2 -> V_2 ) ;
return;
}
#if V_137
if ( V_10 -> V_138 . V_139 == V_140 ) {
F_142 ( V_71 ) ;
return;
}
#endif
#ifdef F_133
if ( F_134 () ) {
F_141 ( ( void * ) V_71 , V_2 -> V_2 ) ;
return;
}
#endif
for ( V_11 = 0 ; V_11 < V_71 -> V_76 ; V_11 ++ ) {
if ( V_117 -> V_118 [ V_11 ] ) {
F_138 ( V_222 , V_117 -> V_118 [ V_11 ] , V_48 ,
V_232 ) ;
}
}
F_139 ( V_71 ) ;
}
void
F_143 ( struct V_35 * V_36 , struct V_29 * V_20 , bool V_234 )
{
struct V_52 * V_211 = V_36 -> V_33 . V_211 ;
if ( V_234 )
F_144 ( V_211 , & V_20 -> V_193 ) ;
else if ( V_20 )
F_145 ( V_211 , & V_20 -> V_193 ) ;
}
struct V_207 *
F_146 ( struct V_35 * V_36 , struct V_235 * V_61 )
{
struct V_207 * V_168 ;
F_112 (vma, &nvbo->vma_list, head) {
if ( V_168 -> V_61 == V_61 )
return V_168 ;
}
return NULL ;
}
int
F_147 ( struct V_35 * V_36 , struct V_235 * V_61 ,
struct V_207 * V_168 )
{
const T_1 V_6 = V_36 -> V_33 . V_75 . V_76 << V_77 ;
int V_56 ;
V_56 = F_90 ( V_61 , V_6 , V_36 -> V_47 ,
V_189 , V_168 ) ;
if ( V_56 )
return V_56 ;
if ( V_36 -> V_33 . V_75 . V_104 != V_144 &&
( V_36 -> V_33 . V_75 . V_104 == V_105 ||
V_36 -> V_47 != V_168 -> V_61 -> V_62 -> V_58 ) )
F_92 ( V_168 , V_36 -> V_33 . V_75 . V_107 ) ;
F_148 ( & V_168 -> V_68 , & V_36 -> V_70 ) ;
V_168 -> V_236 = 1 ;
return 0 ;
}
void
F_149 ( struct V_35 * V_36 , struct V_207 * V_168 )
{
if ( V_168 -> V_167 ) {
if ( V_36 -> V_33 . V_75 . V_104 != V_144 )
F_113 ( V_168 ) ;
F_91 ( V_168 ) ;
F_150 ( & V_168 -> V_68 ) ;
}
}
