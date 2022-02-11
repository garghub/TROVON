static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
int V_11 = V_4 - V_10 -> V_12 . V_4 ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_15 . V_14 ) ;
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_18 * V_12 = & V_17 -> V_12 . V_19 [ V_11 ] ;
F_3 ( & V_4 -> V_20 ) ;
if ( V_12 -> V_7 )
F_4 ( V_17 , V_11 , V_12 ) ;
if ( V_7 )
F_5 ( V_17 , V_11 , V_5 , V_6 , V_7 , V_8 , V_12 ) ;
F_6 ( V_17 , V_11 , V_12 ) ;
}
static struct V_3 *
F_7 ( struct V_1 * V_2 , int V_11 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_3 * V_12 = & V_10 -> V_12 . V_4 [ V_11 ] ;
F_8 ( & V_10 -> V_12 . V_21 ) ;
if ( ! V_12 -> V_22 &&
( ! V_12 -> V_20 || F_9 ( V_12 -> V_20 ) ) )
V_12 -> V_22 = true ;
else
V_12 = NULL ;
F_10 ( & V_10 -> V_12 . V_21 ) ;
return V_12 ;
}
static void
F_11 ( struct V_1 * V_2 , struct V_3 * V_12 ,
struct V_23 * V_20 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
if ( V_12 ) {
F_8 ( & V_10 -> V_12 . V_21 ) ;
V_12 -> V_20 = (struct V_24 * ) F_12 ( V_20 ) ;
V_12 -> V_22 = false ;
F_10 ( & V_10 -> V_12 . V_21 ) ;
}
}
static struct V_3 *
F_13 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_16 * V_17 = F_14 ( & V_10 -> V_15 . V_14 ) ;
struct V_3 * V_12 , * V_25 = NULL ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_17 -> V_12 . V_26 ; V_11 ++ ) {
V_12 = F_7 ( V_2 , V_11 ) ;
if ( V_7 && ! V_25 ) {
V_25 = V_12 ;
continue;
} else if ( V_12 && V_17 -> V_12 . V_19 [ V_11 ] . V_7 ) {
F_1 ( V_2 , V_12 , 0 , 0 , 0 , 0 ) ;
}
F_11 ( V_2 , V_12 , NULL ) ;
}
if ( V_25 )
F_1 ( V_2 , V_25 , V_5 , V_6 ,
V_7 , V_8 ) ;
return V_25 ;
}
static void
F_15 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = F_16 ( V_28 -> V_29 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_30 * V_31 = V_30 ( V_28 ) ;
if ( F_17 ( V_31 -> V_32 . V_33 ) )
F_18 ( L_1 , V_28 ) ;
F_19 ( V_31 -> V_34 > 0 ) ;
F_11 ( V_2 , V_31 -> V_12 , NULL ) ;
F_20 ( V_31 ) ;
}
static inline T_2
F_21 ( T_2 V_35 , T_1 V_36 )
{
V_35 += V_36 - 1 ;
F_22 ( V_35 , V_36 ) ;
return V_35 * V_36 ;
}
static void
F_23 ( struct V_30 * V_31 , T_1 V_8 ,
int * V_37 , T_2 * V_6 )
{
struct V_9 * V_10 = F_16 ( V_31 -> V_28 . V_29 ) ;
struct V_38 * V_14 = & V_10 -> V_15 . V_14 ;
if ( V_14 -> V_39 . V_40 < V_41 ) {
if ( V_31 -> V_42 ) {
if ( V_14 -> V_39 . V_43 >= 0x40 ) {
* V_37 = 65536 ;
* V_6 = F_21 ( * V_6 , 64 * V_31 -> V_42 ) ;
} else if ( V_14 -> V_39 . V_43 >= 0x30 ) {
* V_37 = 32768 ;
* V_6 = F_21 ( * V_6 , 64 * V_31 -> V_42 ) ;
} else if ( V_14 -> V_39 . V_43 >= 0x20 ) {
* V_37 = 16384 ;
* V_6 = F_21 ( * V_6 , 64 * V_31 -> V_42 ) ;
} else if ( V_14 -> V_39 . V_43 >= 0x10 ) {
* V_37 = 16384 ;
* V_6 = F_21 ( * V_6 , 32 * V_31 -> V_42 ) ;
}
}
} else {
* V_6 = F_21 ( * V_6 , ( 1 << V_31 -> V_44 ) ) ;
* V_37 = F_24 ( ( 1 << V_31 -> V_44 ) , * V_37 ) ;
}
* V_6 = F_21 ( * V_6 , V_45 ) ;
}
int
F_25 ( struct V_46 * V_47 , T_2 V_6 , int V_37 ,
T_3 V_8 , T_3 V_42 , T_3 V_48 ,
struct V_49 * V_50 , struct V_51 * V_52 ,
struct V_30 * * V_53 )
{
struct V_9 * V_10 = V_9 ( V_47 -> V_2 ) ;
struct V_30 * V_31 ;
T_4 V_54 ;
int V_55 ;
int type = V_56 ;
if ( ! V_6 ) {
F_26 ( V_10 , L_2 , V_6 ) ;
return - V_57 ;
}
if ( V_50 )
type = V_58 ;
V_31 = F_27 ( sizeof( struct V_30 ) , V_59 ) ;
if ( ! V_31 )
return - V_60 ;
F_28 ( & V_31 -> V_61 ) ;
F_28 ( & V_31 -> V_62 ) ;
F_28 ( & V_31 -> V_63 ) ;
V_31 -> V_42 = V_42 ;
V_31 -> V_48 = V_48 ;
V_31 -> V_28 . V_29 = & V_10 -> V_64 . V_29 ;
V_31 -> V_47 = V_47 ;
if ( ! F_2 ( & V_10 -> V_15 . V_14 ) -> V_65 -> V_66 )
V_31 -> V_67 = V_8 & V_68 ;
V_31 -> V_44 = 12 ;
if ( V_10 -> V_15 . V_69 ) {
if ( ! ( V_8 & V_70 ) && V_6 > 256 * 1024 )
V_31 -> V_44 = V_10 -> V_15 . V_69 -> V_71 -> V_72 ;
}
F_23 ( V_31 , V_8 , & V_37 , & V_6 ) ;
V_31 -> V_28 . V_73 . V_74 = V_6 >> V_75 ;
F_29 ( V_31 , V_8 , 0 ) ;
V_54 = F_30 ( & V_10 -> V_64 . V_29 , V_6 ,
sizeof( struct V_30 ) ) ;
V_55 = F_31 ( & V_10 -> V_64 . V_29 , & V_31 -> V_28 , V_6 ,
type , & V_31 -> V_76 ,
V_37 >> V_75 , false , NULL , V_54 , V_50 ,
V_52 , F_15 ) ;
if ( V_55 ) {
return V_55 ;
}
* V_53 = V_31 ;
return 0 ;
}
static void
F_32 ( struct V_77 * V_78 , unsigned * V_79 , T_3 type , T_3 V_8 )
{
* V_79 = 0 ;
if ( type & V_80 )
V_78 [ ( * V_79 ) ++ ] . V_8 = V_80 | V_8 ;
if ( type & V_70 )
V_78 [ ( * V_79 ) ++ ] . V_8 = V_70 | V_8 ;
if ( type & V_81 )
V_78 [ ( * V_79 ) ++ ] . V_8 = V_81 | V_8 ;
}
static void
F_33 ( struct V_30 * V_31 , T_3 type )
{
struct V_9 * V_10 = F_16 ( V_31 -> V_28 . V_29 ) ;
T_1 V_82 = V_10 -> V_15 . V_14 . V_39 . V_83 >> V_75 ;
unsigned V_11 , V_84 , V_85 ;
if ( V_10 -> V_15 . V_14 . V_39 . V_40 == V_86 &&
V_31 -> V_42 && ( type & V_80 ) &&
V_31 -> V_28 . V_73 . V_74 < V_82 / 4 ) {
if ( V_31 -> V_48 & V_87 ) {
V_84 = V_82 / 2 ;
V_85 = ~ 0 ;
} else {
V_84 = 0 ;
V_85 = V_82 / 2 ;
}
for ( V_11 = 0 ; V_11 < V_31 -> V_76 . V_88 ; ++ V_11 ) {
V_31 -> V_89 [ V_11 ] . V_84 = V_84 ;
V_31 -> V_89 [ V_11 ] . V_85 = V_85 ;
}
for ( V_11 = 0 ; V_11 < V_31 -> V_76 . V_90 ; ++ V_11 ) {
V_31 -> V_91 [ V_11 ] . V_84 = V_84 ;
V_31 -> V_91 [ V_11 ] . V_85 = V_85 ;
}
}
}
void
F_29 ( struct V_30 * V_31 , T_3 type , T_3 V_92 )
{
struct V_93 * V_78 = & V_31 -> V_76 ;
T_3 V_8 = ( V_31 -> V_67 ? V_68 :
V_94 ) |
( V_31 -> V_34 ? V_95 : 0 ) ;
V_78 -> V_76 = V_31 -> V_89 ;
F_32 ( V_31 -> V_89 , & V_78 -> V_88 ,
type , V_8 ) ;
V_78 -> V_96 = V_31 -> V_91 ;
F_32 ( V_31 -> V_91 , & V_78 -> V_90 ,
type | V_92 , V_8 ) ;
F_33 ( V_31 , type ) ;
}
int
F_34 ( struct V_30 * V_31 , T_3 V_97 , bool V_98 )
{
struct V_9 * V_10 = F_16 ( V_31 -> V_28 . V_29 ) ;
struct V_27 * V_28 = & V_31 -> V_28 ;
bool V_99 = false , V_100 = false ;
int V_55 ;
V_55 = F_35 ( V_28 , false , false , NULL ) ;
if ( V_55 )
return V_55 ;
if ( V_10 -> V_15 . V_14 . V_39 . V_40 >= V_41 &&
V_97 == V_80 && V_98 ) {
if ( V_31 -> V_48 & V_101 ) {
if ( V_28 -> V_73 . V_102 == V_103 ) {
struct V_104 * V_73 = V_28 -> V_73 . V_105 ;
if ( ! F_36 ( V_73 -> V_73 ) )
V_100 = true ;
}
V_31 -> V_48 &= ~ V_101 ;
V_99 = true ;
}
}
if ( V_31 -> V_34 ) {
if ( ! ( V_97 & ( 1 << V_28 -> V_73 . V_102 ) ) || V_100 ) {
F_37 ( V_10 , L_3
L_4 , V_28 ,
1 << V_28 -> V_73 . V_102 , V_97 ) ;
V_55 = - V_106 ;
}
V_31 -> V_34 ++ ;
goto V_107;
}
if ( V_100 ) {
F_29 ( V_31 , V_70 , 0 ) ;
V_55 = F_38 ( V_31 , false , false ) ;
if ( V_55 )
goto V_107;
}
V_31 -> V_34 ++ ;
F_29 ( V_31 , V_97 , 0 ) ;
V_31 -> V_34 -- ;
V_55 = F_38 ( V_31 , false , false ) ;
if ( V_55 )
goto V_107;
V_31 -> V_34 ++ ;
switch ( V_28 -> V_73 . V_102 ) {
case V_103 :
V_10 -> V_32 . V_108 -= V_28 -> V_73 . V_6 ;
break;
case V_109 :
V_10 -> V_32 . V_110 -= V_28 -> V_73 . V_6 ;
break;
default:
break;
}
V_107:
if ( V_99 && V_55 )
V_31 -> V_48 |= V_101 ;
F_39 ( V_28 ) ;
return V_55 ;
}
int
F_40 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = F_16 ( V_31 -> V_28 . V_29 ) ;
struct V_27 * V_28 = & V_31 -> V_28 ;
int V_55 , V_111 ;
V_55 = F_35 ( V_28 , false , false , NULL ) ;
if ( V_55 )
return V_55 ;
V_111 = -- V_31 -> V_34 ;
F_41 ( V_111 < 0 ) ;
if ( V_111 )
goto V_107;
F_29 ( V_31 , V_28 -> V_73 . V_76 , 0 ) ;
V_55 = F_38 ( V_31 , false , false ) ;
if ( V_55 == 0 ) {
switch ( V_28 -> V_73 . V_102 ) {
case V_103 :
V_10 -> V_32 . V_108 += V_28 -> V_73 . V_6 ;
break;
case V_109 :
V_10 -> V_32 . V_110 += V_28 -> V_73 . V_6 ;
break;
default:
break;
}
}
V_107:
F_39 ( V_28 ) ;
return V_55 ;
}
int
F_42 ( struct V_30 * V_31 )
{
int V_55 ;
V_55 = F_35 ( & V_31 -> V_28 , false , false , NULL ) ;
if ( V_55 )
return V_55 ;
V_55 = F_43 ( & V_31 -> V_28 , 0 , V_31 -> V_28 . V_73 . V_74 , & V_31 -> V_112 ) ;
F_39 ( & V_31 -> V_28 ) ;
return V_55 ;
}
void
F_44 ( struct V_30 * V_31 )
{
if ( ! V_31 )
return;
F_45 ( & V_31 -> V_112 ) ;
}
void
F_46 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = F_16 ( V_31 -> V_28 . V_29 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_15 . V_14 ) ;
struct V_113 * V_114 = (struct V_113 * ) V_31 -> V_28 . V_64 ;
int V_11 ;
if ( ! V_114 )
return;
if ( V_31 -> V_67 )
return;
for ( V_11 = 0 ; V_11 < V_114 -> V_64 . V_74 ; V_11 ++ )
F_47 ( V_14 -> V_2 , V_114 -> V_115 [ V_11 ] ,
V_45 , V_116 ) ;
}
void
F_48 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = F_16 ( V_31 -> V_28 . V_29 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_15 . V_14 ) ;
struct V_113 * V_114 = (struct V_113 * ) V_31 -> V_28 . V_64 ;
int V_11 ;
if ( ! V_114 )
return;
if ( V_31 -> V_67 )
return;
for ( V_11 = 0 ; V_11 < V_114 -> V_64 . V_74 ; V_11 ++ )
F_49 ( V_14 -> V_2 , V_114 -> V_115 [ V_11 ] ,
V_45 , V_117 ) ;
}
int
F_38 ( struct V_30 * V_31 , bool V_118 ,
bool V_119 )
{
int V_55 ;
V_55 = F_50 ( & V_31 -> V_28 , & V_31 -> V_76 ,
V_118 , V_119 ) ;
if ( V_55 )
return V_55 ;
F_46 ( V_31 ) ;
return 0 ;
}
void
F_51 ( struct V_30 * V_31 , unsigned V_120 , T_5 V_121 )
{
bool V_122 ;
T_5 * V_73 = F_52 ( & V_31 -> V_112 , & V_122 ) ;
V_73 += V_120 ;
if ( V_122 )
F_53 ( V_121 , ( void V_123 V_124 * ) V_73 ) ;
else
* V_73 = V_121 ;
}
T_1
F_54 ( struct V_30 * V_31 , unsigned V_120 )
{
bool V_122 ;
T_1 * V_73 = F_52 ( & V_31 -> V_112 , & V_122 ) ;
V_73 += V_120 ;
if ( V_122 )
return F_55 ( ( void V_123 V_124 * ) V_73 ) ;
else
return * V_73 ;
}
void
F_56 ( struct V_30 * V_31 , unsigned V_120 , T_1 V_121 )
{
bool V_122 ;
T_1 * V_73 = F_52 ( & V_31 -> V_112 , & V_122 ) ;
V_73 += V_120 ;
if ( V_122 )
F_57 ( V_121 , ( void V_123 V_124 * ) V_73 ) ;
else
* V_73 = V_121 ;
}
static struct V_125 *
F_58 ( struct V_126 * V_29 , unsigned long V_6 ,
T_3 V_127 , struct V_128 * V_129 )
{
#if F_59 ( V_130 )
struct V_9 * V_10 = F_16 ( V_29 ) ;
if ( V_10 -> V_131 . V_132 ) {
return F_60 ( V_29 , V_10 -> V_131 . V_132 , V_6 ,
V_127 , V_129 ) ;
}
#endif
return F_61 ( V_29 , V_6 , V_127 , V_129 ) ;
}
static int
F_62 ( struct V_126 * V_29 , T_3 V_8 )
{
return 0 ;
}
static int
F_63 ( struct V_126 * V_29 , T_3 type ,
struct V_133 * V_134 )
{
struct V_9 * V_10 = F_16 ( V_29 ) ;
switch ( type ) {
case V_135 :
V_134 -> V_8 = V_136 ;
V_134 -> V_137 = V_94 ;
V_134 -> V_138 = V_139 ;
break;
case V_103 :
V_134 -> V_8 = V_140 |
V_136 ;
V_134 -> V_137 = V_68 |
V_141 ;
V_134 -> V_138 = V_141 ;
if ( V_10 -> V_15 . V_14 . V_39 . V_40 >= V_41 ) {
if ( F_64 ( & V_10 -> V_15 . V_14 ) -> V_142 ) {
V_134 -> V_137 = V_68 ;
V_134 -> V_138 = V_68 ;
}
V_134 -> V_65 = & V_143 ;
V_134 -> V_144 = false ;
V_134 -> V_145 = true ;
} else {
V_134 -> V_65 = & V_146 ;
}
break;
case V_109 :
if ( V_10 -> V_15 . V_14 . V_39 . V_40 >= V_41 )
V_134 -> V_65 = & V_147 ;
else
if ( ! V_10 -> V_131 . V_132 )
V_134 -> V_65 = & V_148 ;
else
V_134 -> V_65 = & V_146 ;
if ( V_10 -> V_131 . V_132 ) {
V_134 -> V_8 = V_136 ;
V_134 -> V_137 = V_68 |
V_141 ;
V_134 -> V_138 = V_141 ;
} else {
V_134 -> V_8 = V_136 |
V_149 ;
V_134 -> V_137 = V_94 ;
V_134 -> V_138 = V_139 ;
}
break;
default:
return - V_57 ;
}
return 0 ;
}
static void
F_65 ( struct V_27 * V_28 , struct V_93 * V_78 )
{
struct V_30 * V_31 = V_30 ( V_28 ) ;
switch ( V_28 -> V_73 . V_102 ) {
case V_103 :
F_29 ( V_31 , V_70 ,
V_81 ) ;
break;
default:
F_29 ( V_31 , V_81 , 0 ) ;
break;
}
* V_78 = V_31 -> V_76 ;
}
static int
F_66 ( struct V_150 * V_151 , T_1 V_152 )
{
int V_55 = F_67 ( V_151 , 2 ) ;
if ( V_55 == 0 ) {
F_68 ( V_151 , V_153 , 0x0000 , 1 ) ;
F_69 ( V_151 , V_152 & 0x0000ffff ) ;
F_70 ( V_151 ) ;
}
return V_55 ;
}
static int
F_71 ( struct V_150 * V_151 , struct V_27 * V_28 ,
struct V_154 * V_155 , struct V_154 * V_156 )
{
struct V_104 * V_73 = V_155 -> V_105 ;
int V_55 = F_67 ( V_151 , 10 ) ;
if ( V_55 == 0 ) {
F_68 ( V_151 , V_153 , 0x0400 , 8 ) ;
F_69 ( V_151 , F_72 ( V_73 -> V_157 [ 0 ] . V_158 ) ) ;
F_69 ( V_151 , F_73 ( V_73 -> V_157 [ 0 ] . V_158 ) ) ;
F_69 ( V_151 , F_72 ( V_73 -> V_157 [ 1 ] . V_158 ) ) ;
F_69 ( V_151 , F_73 ( V_73 -> V_157 [ 1 ] . V_158 ) ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_156 -> V_74 ) ;
F_74 ( V_151 , V_153 , 0x0300 , 0x0386 ) ;
}
return V_55 ;
}
static int
F_75 ( struct V_150 * V_151 , T_1 V_152 )
{
int V_55 = F_67 ( V_151 , 2 ) ;
if ( V_55 == 0 ) {
F_68 ( V_151 , V_153 , 0x0000 , 1 ) ;
F_69 ( V_151 , V_152 ) ;
}
return V_55 ;
}
static int
F_76 ( struct V_150 * V_151 , struct V_27 * V_28 ,
struct V_154 * V_155 , struct V_154 * V_156 )
{
struct V_104 * V_73 = V_155 -> V_105 ;
T_2 V_159 = V_73 -> V_157 [ 0 ] . V_158 ;
T_2 V_160 = V_73 -> V_157 [ 1 ] . V_158 ;
T_1 V_161 = V_156 -> V_74 ;
int V_55 ;
V_161 = V_156 -> V_74 ;
while ( V_161 ) {
int V_162 = ( V_161 > 8191 ) ? 8191 : V_161 ;
V_55 = F_67 ( V_151 , 11 ) ;
if ( V_55 )
return V_55 ;
F_68 ( V_151 , V_153 , 0x030c , 8 ) ;
F_69 ( V_151 , F_72 ( V_159 ) ) ;
F_69 ( V_151 , F_73 ( V_159 ) ) ;
F_69 ( V_151 , F_72 ( V_160 ) ) ;
F_69 ( V_151 , F_73 ( V_160 ) ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_162 ) ;
F_68 ( V_151 , V_153 , 0x0300 , 1 ) ;
F_69 ( V_151 , 0x00000110 ) ;
V_161 -= V_162 ;
V_159 += ( V_45 * V_162 ) ;
V_160 += ( V_45 * V_162 ) ;
}
return 0 ;
}
static int
F_77 ( struct V_150 * V_151 , struct V_27 * V_28 ,
struct V_154 * V_155 , struct V_154 * V_156 )
{
struct V_104 * V_73 = V_155 -> V_105 ;
T_2 V_159 = V_73 -> V_157 [ 0 ] . V_158 ;
T_2 V_160 = V_73 -> V_157 [ 1 ] . V_158 ;
T_1 V_161 = V_156 -> V_74 ;
int V_55 ;
V_161 = V_156 -> V_74 ;
while ( V_161 ) {
int V_162 = ( V_161 > 2047 ) ? 2047 : V_161 ;
V_55 = F_67 ( V_151 , 12 ) ;
if ( V_55 )
return V_55 ;
F_68 ( V_151 , V_153 , 0x0238 , 2 ) ;
F_69 ( V_151 , F_72 ( V_160 ) ) ;
F_69 ( V_151 , F_73 ( V_160 ) ) ;
F_68 ( V_151 , V_153 , 0x030c , 6 ) ;
F_69 ( V_151 , F_72 ( V_159 ) ) ;
F_69 ( V_151 , F_73 ( V_159 ) ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_162 ) ;
F_68 ( V_151 , V_153 , 0x0300 , 1 ) ;
F_69 ( V_151 , 0x00100110 ) ;
V_161 -= V_162 ;
V_159 += ( V_45 * V_162 ) ;
V_160 += ( V_45 * V_162 ) ;
}
return 0 ;
}
static int
F_78 ( struct V_150 * V_151 , struct V_27 * V_28 ,
struct V_154 * V_155 , struct V_154 * V_156 )
{
struct V_104 * V_73 = V_155 -> V_105 ;
T_2 V_159 = V_73 -> V_157 [ 0 ] . V_158 ;
T_2 V_160 = V_73 -> V_157 [ 1 ] . V_158 ;
T_1 V_161 = V_156 -> V_74 ;
int V_55 ;
V_161 = V_156 -> V_74 ;
while ( V_161 ) {
int V_162 = ( V_161 > 8191 ) ? 8191 : V_161 ;
V_55 = F_67 ( V_151 , 11 ) ;
if ( V_55 )
return V_55 ;
F_79 ( V_151 , V_153 , 0x030c , 8 ) ;
F_69 ( V_151 , F_72 ( V_159 ) ) ;
F_69 ( V_151 , F_73 ( V_159 ) ) ;
F_69 ( V_151 , F_72 ( V_160 ) ) ;
F_69 ( V_151 , F_73 ( V_160 ) ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_162 ) ;
F_79 ( V_151 , V_153 , 0x0300 , 1 ) ;
F_69 ( V_151 , 0x00000110 ) ;
V_161 -= V_162 ;
V_159 += ( V_45 * V_162 ) ;
V_160 += ( V_45 * V_162 ) ;
}
return 0 ;
}
static int
F_80 ( struct V_150 * V_151 , struct V_27 * V_28 ,
struct V_154 * V_155 , struct V_154 * V_156 )
{
struct V_104 * V_73 = V_155 -> V_105 ;
int V_55 = F_67 ( V_151 , 7 ) ;
if ( V_55 == 0 ) {
F_79 ( V_151 , V_153 , 0x0320 , 6 ) ;
F_69 ( V_151 , F_72 ( V_73 -> V_157 [ 0 ] . V_158 ) ) ;
F_69 ( V_151 , F_73 ( V_73 -> V_157 [ 0 ] . V_158 ) ) ;
F_69 ( V_151 , F_72 ( V_73 -> V_157 [ 1 ] . V_158 ) ) ;
F_69 ( V_151 , F_73 ( V_73 -> V_157 [ 1 ] . V_158 ) ) ;
F_69 ( V_151 , 0x00000000 ) ;
F_69 ( V_151 , V_156 -> V_74 << V_75 ) ;
}
return V_55 ;
}
static int
F_81 ( struct V_150 * V_151 , struct V_27 * V_28 ,
struct V_154 * V_155 , struct V_154 * V_156 )
{
struct V_104 * V_73 = V_155 -> V_105 ;
int V_55 = F_67 ( V_151 , 7 ) ;
if ( V_55 == 0 ) {
F_79 ( V_151 , V_153 , 0x0304 , 6 ) ;
F_69 ( V_151 , V_156 -> V_74 << V_75 ) ;
F_69 ( V_151 , F_72 ( V_73 -> V_157 [ 0 ] . V_158 ) ) ;
F_69 ( V_151 , F_73 ( V_73 -> V_157 [ 0 ] . V_158 ) ) ;
F_69 ( V_151 , F_72 ( V_73 -> V_157 [ 1 ] . V_158 ) ) ;
F_69 ( V_151 , F_73 ( V_73 -> V_157 [ 1 ] . V_158 ) ) ;
F_69 ( V_151 , 0x00000000 ) ;
}
return V_55 ;
}
static int
F_82 ( struct V_150 * V_151 , T_1 V_152 )
{
int V_55 = F_67 ( V_151 , 6 ) ;
if ( V_55 == 0 ) {
F_79 ( V_151 , V_153 , 0x0000 , 1 ) ;
F_69 ( V_151 , V_152 ) ;
F_79 ( V_151 , V_153 , 0x0180 , 3 ) ;
F_69 ( V_151 , V_151 -> V_10 -> V_163 . V_152 ) ;
F_69 ( V_151 , V_151 -> V_164 . V_152 ) ;
F_69 ( V_151 , V_151 -> V_164 . V_152 ) ;
}
return V_55 ;
}
static int
F_83 ( struct V_150 * V_151 , struct V_27 * V_28 ,
struct V_154 * V_155 , struct V_154 * V_156 )
{
struct V_104 * V_73 = V_155 -> V_105 ;
T_2 V_165 = ( V_156 -> V_74 << V_75 ) ;
T_2 V_159 = V_73 -> V_157 [ 0 ] . V_158 ;
T_2 V_160 = V_73 -> V_157 [ 1 ] . V_158 ;
int V_166 = ! ! V_73 -> V_97 ;
int V_167 = ! ! ( (struct V_104 * ) V_156 -> V_105 ) -> V_97 ;
int V_55 ;
while ( V_165 ) {
T_1 V_168 , V_169 , V_170 ;
V_55 = F_67 ( V_151 , 18 + 6 * ( V_166 + V_167 ) ) ;
if ( V_55 )
return V_55 ;
V_168 = F_84 ( V_165 , ( T_2 ) ( 4 * 1024 * 1024 ) ) ;
V_169 = 16 * 4 ;
V_170 = V_168 / V_169 ;
if ( V_166 ) {
F_79 ( V_151 , V_153 , 0x0200 , 7 ) ;
F_69 ( V_151 , 0 ) ;
F_69 ( V_151 , 0 ) ;
F_69 ( V_151 , V_169 ) ;
F_69 ( V_151 , V_170 ) ;
F_69 ( V_151 , 1 ) ;
F_69 ( V_151 , 0 ) ;
F_69 ( V_151 , 0 ) ;
} else {
F_79 ( V_151 , V_153 , 0x0200 , 1 ) ;
F_69 ( V_151 , 1 ) ;
}
if ( V_167 ) {
F_79 ( V_151 , V_153 , 0x021c , 7 ) ;
F_69 ( V_151 , 0 ) ;
F_69 ( V_151 , 0 ) ;
F_69 ( V_151 , V_169 ) ;
F_69 ( V_151 , V_170 ) ;
F_69 ( V_151 , 1 ) ;
F_69 ( V_151 , 0 ) ;
F_69 ( V_151 , 0 ) ;
} else {
F_79 ( V_151 , V_153 , 0x021c , 1 ) ;
F_69 ( V_151 , 1 ) ;
}
F_79 ( V_151 , V_153 , 0x0238 , 2 ) ;
F_69 ( V_151 , F_72 ( V_159 ) ) ;
F_69 ( V_151 , F_72 ( V_160 ) ) ;
F_79 ( V_151 , V_153 , 0x030c , 8 ) ;
F_69 ( V_151 , F_73 ( V_159 ) ) ;
F_69 ( V_151 , F_73 ( V_160 ) ) ;
F_69 ( V_151 , V_169 ) ;
F_69 ( V_151 , V_169 ) ;
F_69 ( V_151 , V_169 ) ;
F_69 ( V_151 , V_170 ) ;
F_69 ( V_151 , 0x00000101 ) ;
F_69 ( V_151 , 0x00000000 ) ;
F_79 ( V_151 , V_153 , V_171 , 1 ) ;
F_69 ( V_151 , 0 ) ;
V_165 -= V_168 ;
V_159 += V_168 ;
V_160 += V_168 ;
}
return 0 ;
}
static int
F_85 ( struct V_150 * V_151 , T_1 V_152 )
{
int V_55 = F_67 ( V_151 , 4 ) ;
if ( V_55 == 0 ) {
F_79 ( V_151 , V_153 , 0x0000 , 1 ) ;
F_69 ( V_151 , V_152 ) ;
F_79 ( V_151 , V_153 , 0x0180 , 1 ) ;
F_69 ( V_151 , V_151 -> V_10 -> V_163 . V_152 ) ;
}
return V_55 ;
}
static inline T_3
F_86 ( struct V_27 * V_28 ,
struct V_150 * V_151 , struct V_154 * V_4 )
{
if ( V_4 -> V_102 == V_109 )
return V_172 ;
return V_151 -> V_164 . V_152 ;
}
static int
F_87 ( struct V_150 * V_151 , struct V_27 * V_28 ,
struct V_154 * V_155 , struct V_154 * V_156 )
{
T_1 V_159 = V_155 -> V_173 << V_75 ;
T_1 V_160 = V_156 -> V_173 << V_75 ;
T_1 V_161 = V_156 -> V_74 ;
int V_55 ;
V_55 = F_67 ( V_151 , 3 ) ;
if ( V_55 )
return V_55 ;
F_79 ( V_151 , V_153 , V_174 , 2 ) ;
F_69 ( V_151 , F_86 ( V_28 , V_151 , V_155 ) ) ;
F_69 ( V_151 , F_86 ( V_28 , V_151 , V_156 ) ) ;
V_161 = V_156 -> V_74 ;
while ( V_161 ) {
int V_162 = ( V_161 > 2047 ) ? 2047 : V_161 ;
V_55 = F_67 ( V_151 , 11 ) ;
if ( V_55 )
return V_55 ;
F_79 ( V_151 , V_153 ,
V_175 , 8 ) ;
F_69 ( V_151 , V_159 ) ;
F_69 ( V_151 , V_160 ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_45 ) ;
F_69 ( V_151 , V_162 ) ;
F_69 ( V_151 , 0x00000101 ) ;
F_69 ( V_151 , 0x00000000 ) ;
F_79 ( V_151 , V_153 , V_171 , 1 ) ;
F_69 ( V_151 , 0 ) ;
V_161 -= V_162 ;
V_159 += ( V_45 * V_162 ) ;
V_160 += ( V_45 * V_162 ) ;
}
return 0 ;
}
static int
F_88 ( struct V_9 * V_10 , struct V_27 * V_28 ,
struct V_154 * V_4 )
{
struct V_104 * V_176 = V_28 -> V_73 . V_105 ;
struct V_104 * V_177 = V_4 -> V_105 ;
T_2 V_6 = ( T_2 ) V_4 -> V_74 << V_75 ;
int V_55 ;
V_55 = F_89 ( V_10 -> V_15 . V_69 , V_6 , V_176 -> V_44 ,
V_178 , & V_176 -> V_157 [ 0 ] ) ;
if ( V_55 )
return V_55 ;
V_55 = F_89 ( V_10 -> V_15 . V_69 , V_6 , V_177 -> V_44 ,
V_178 , & V_176 -> V_157 [ 1 ] ) ;
if ( V_55 ) {
F_90 ( & V_176 -> V_157 [ 0 ] ) ;
return V_55 ;
}
F_91 ( & V_176 -> V_157 [ 0 ] , V_176 ) ;
F_91 ( & V_176 -> V_157 [ 1 ] , V_177 ) ;
return 0 ;
}
static int
F_92 ( struct V_27 * V_28 , int V_100 , bool V_179 ,
bool V_119 , struct V_154 * V_156 )
{
struct V_9 * V_10 = F_16 ( V_28 -> V_29 ) ;
struct V_150 * V_151 = V_10 -> V_64 . V_151 ;
struct V_46 * V_47 = ( void * ) V_151 -> V_180 . V_15 ;
struct V_24 * V_20 ;
int V_55 ;
if ( V_10 -> V_15 . V_14 . V_39 . V_40 >= V_41 ) {
V_55 = F_88 ( V_10 , V_28 , V_156 ) ;
if ( V_55 )
return V_55 ;
}
F_93 ( & V_47 -> V_181 , V_182 ) ;
V_55 = F_94 ( V_30 ( V_28 ) , V_151 , true , V_179 ) ;
if ( V_55 == 0 ) {
V_55 = V_10 -> V_64 . V_183 ( V_151 , V_28 , & V_28 -> V_73 , V_156 ) ;
if ( V_55 == 0 ) {
V_55 = F_95 ( V_151 , false , & V_20 ) ;
if ( V_55 == 0 ) {
V_55 = F_96 ( V_28 ,
& V_20 -> V_184 ,
V_100 ,
V_156 ) ;
F_3 ( & V_20 ) ;
}
}
}
F_97 ( & V_47 -> V_181 ) ;
return V_55 ;
}
void
F_98 ( struct V_9 * V_10 )
{
static const struct {
const char * V_185 ;
int V_186 ;
T_6 V_187 ;
int (* F_99)( struct V_150 * ,
struct V_27 * ,
struct V_154 * , struct V_154 * );
int (* F_100)( struct V_150 * , T_1 V_152 );
} V_188 [] = {
{ L_5 , 4 , 0xc1b5 , F_71 , F_66 } ,
{ L_6 , 0 , 0xc1b5 , F_71 , F_75 } ,
{ L_5 , 4 , 0xc0b5 , F_71 , F_66 } ,
{ L_6 , 0 , 0xc0b5 , F_71 , F_75 } ,
{ L_5 , 4 , 0xb0b5 , F_71 , F_66 } ,
{ L_6 , 0 , 0xb0b5 , F_71 , F_75 } ,
{ L_5 , 4 , 0xa0b5 , F_71 , F_66 } ,
{ L_6 , 0 , 0xa0b5 , F_71 , F_75 } ,
{ L_7 , 5 , 0x90b8 , F_76 , F_75 } ,
{ L_8 , 4 , 0x90b5 , F_76 , F_75 } ,
{ L_5 , 0 , 0x85b5 , F_78 , F_82 } ,
{ L_9 , 0 , 0x74c1 , F_81 , F_82 } ,
{ L_10 , 0 , 0x9039 , F_77 , F_75 } ,
{ L_10 , 0 , 0x5039 , F_83 , F_82 } ,
{ L_10 , 0 , 0x0039 , F_87 , F_85 } ,
{} ,
{ L_9 , 0 , 0x88b4 , F_80 , F_82 } ,
} , * V_189 = V_188 ;
const char * V_185 = L_11 ;
int V_55 ;
do {
struct V_150 * V_151 ;
if ( V_189 -> V_186 )
V_151 = V_10 -> V_190 ;
else
V_151 = V_10 -> V_191 ;
if ( V_151 == NULL )
continue;
V_55 = F_101 ( & V_151 -> V_180 ,
V_189 -> V_187 | ( V_189 -> V_186 << 16 ) ,
V_189 -> V_187 , NULL , 0 ,
& V_10 -> V_64 . V_192 ) ;
if ( V_55 == 0 ) {
V_55 = V_189 -> F_100 ( V_151 , V_10 -> V_64 . V_192 . V_152 ) ;
if ( V_55 ) {
F_102 ( & V_10 -> V_64 . V_192 ) ;
continue;
}
V_10 -> V_64 . V_183 = V_189 -> F_99 ;
V_10 -> V_64 . V_151 = V_151 ;
V_185 = V_189 -> V_185 ;
break;
}
} while ( ( ++ V_189 ) -> F_99 );
F_103 ( V_10 , L_12 , V_185 ) ;
}
static int
F_104 ( struct V_27 * V_28 , bool V_100 , bool V_179 ,
bool V_119 , struct V_154 * V_156 )
{
struct V_77 V_193 = {
. V_84 = 0 ,
. V_85 = 0 ,
. V_8 = V_70 | V_94
} ;
struct V_93 V_76 ;
struct V_154 V_194 ;
int V_55 ;
V_76 . V_88 = V_76 . V_90 = 1 ;
V_76 . V_76 = V_76 . V_96 = & V_193 ;
V_194 = * V_156 ;
V_194 . V_105 = NULL ;
V_55 = F_105 ( V_28 , & V_76 , & V_194 , V_179 , V_119 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_106 ( V_28 -> V_64 , & V_194 ) ;
if ( V_55 )
goto V_107;
V_55 = F_92 ( V_28 , true , V_179 , V_119 , & V_194 ) ;
if ( V_55 )
goto V_107;
V_55 = F_107 ( V_28 , V_179 , V_119 , V_156 ) ;
V_107:
F_108 ( V_28 , & V_194 ) ;
return V_55 ;
}
static int
F_109 ( struct V_27 * V_28 , bool V_100 , bool V_179 ,
bool V_119 , struct V_154 * V_156 )
{
struct V_77 V_193 = {
. V_84 = 0 ,
. V_85 = 0 ,
. V_8 = V_70 | V_94
} ;
struct V_93 V_76 ;
struct V_154 V_194 ;
int V_55 ;
V_76 . V_88 = V_76 . V_90 = 1 ;
V_76 . V_76 = V_76 . V_96 = & V_193 ;
V_194 = * V_156 ;
V_194 . V_105 = NULL ;
V_55 = F_105 ( V_28 , & V_76 , & V_194 , V_179 , V_119 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_107 ( V_28 , V_179 , V_119 , & V_194 ) ;
if ( V_55 )
goto V_107;
V_55 = F_92 ( V_28 , true , V_179 , V_119 , V_156 ) ;
if ( V_55 )
goto V_107;
V_107:
F_108 ( V_28 , & V_194 ) ;
return V_55 ;
}
static void
F_110 ( struct V_27 * V_28 , bool V_100 ,
struct V_154 * V_156 )
{
struct V_30 * V_31 = V_30 ( V_28 ) ;
struct V_195 * V_157 ;
if ( V_28 -> V_196 != F_15 )
return;
F_111 (vma, &nvbo->vma_list, head) {
if ( V_156 && V_156 -> V_102 != V_135 &&
( V_156 -> V_102 == V_103 ||
V_31 -> V_44 != V_157 -> V_69 -> V_71 -> V_72 ) ) {
F_91 ( V_157 , V_156 -> V_105 ) ;
} else {
F_19 ( F_112 ( V_28 , false , false ) ) ;
F_113 ( V_157 ) ;
}
}
}
static int
F_114 ( struct V_27 * V_28 , struct V_154 * V_156 ,
struct V_3 * * V_197 )
{
struct V_9 * V_10 = F_16 ( V_28 -> V_29 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_30 * V_31 = V_30 ( V_28 ) ;
T_2 V_158 = V_156 -> V_173 << V_75 ;
* V_197 = NULL ;
if ( V_156 -> V_102 != V_103 )
return 0 ;
if ( V_10 -> V_15 . V_14 . V_39 . V_40 >= V_86 ) {
* V_197 = F_13 ( V_2 , V_158 , V_156 -> V_6 ,
V_31 -> V_42 ,
V_31 -> V_48 ) ;
}
return 0 ;
}
static void
F_115 ( struct V_27 * V_28 ,
struct V_3 * V_197 ,
struct V_3 * * V_198 )
{
struct V_9 * V_10 = F_16 ( V_28 -> V_29 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_23 * V_20 = F_116 ( V_28 -> V_199 ) ;
F_11 ( V_2 , * V_198 , V_20 ) ;
* V_198 = V_197 ;
}
static int
F_117 ( struct V_27 * V_28 , bool V_100 , bool V_179 ,
bool V_119 , struct V_154 * V_156 )
{
struct V_9 * V_10 = F_16 ( V_28 -> V_29 ) ;
struct V_30 * V_31 = V_30 ( V_28 ) ;
struct V_154 * V_155 = & V_28 -> V_73 ;
struct V_3 * V_197 = NULL ;
int V_55 = 0 ;
V_55 = F_112 ( V_28 , V_179 , V_119 ) ;
if ( V_55 )
return V_55 ;
if ( V_31 -> V_34 )
F_26 ( V_10 , L_13 , V_31 ) ;
if ( V_10 -> V_15 . V_14 . V_39 . V_40 < V_41 ) {
V_55 = F_114 ( V_28 , V_156 , & V_197 ) ;
if ( V_55 )
return V_55 ;
}
if ( V_155 -> V_102 == V_135 && ! V_28 -> V_64 ) {
F_118 ( V_28 -> V_73 . V_105 != NULL ) ;
V_28 -> V_73 = * V_156 ;
V_156 -> V_105 = NULL ;
goto V_107;
}
if ( V_10 -> V_64 . V_183 ) {
if ( V_156 -> V_102 == V_135 )
V_55 = F_104 ( V_28 , V_100 , V_179 ,
V_119 , V_156 ) ;
else if ( V_155 -> V_102 == V_135 )
V_55 = F_109 ( V_28 , V_100 , V_179 ,
V_119 , V_156 ) ;
else
V_55 = F_92 ( V_28 , V_100 , V_179 ,
V_119 , V_156 ) ;
if ( ! V_55 )
goto V_107;
}
V_55 = F_112 ( V_28 , V_179 , V_119 ) ;
if ( V_55 == 0 )
V_55 = F_119 ( V_28 , V_179 , V_119 , V_156 ) ;
V_107:
if ( V_10 -> V_15 . V_14 . V_39 . V_40 < V_41 ) {
if ( V_55 )
F_115 ( V_28 , NULL , & V_197 ) ;
else
F_115 ( V_28 , V_197 , & V_31 -> V_12 ) ;
}
return V_55 ;
}
static int
F_120 ( struct V_27 * V_28 , struct V_200 * V_33 )
{
struct V_30 * V_31 = V_30 ( V_28 ) ;
return F_121 ( & V_31 -> V_32 . V_201 ,
V_33 -> V_202 ) ;
}
static int
F_122 ( struct V_126 * V_29 , struct V_154 * V_4 )
{
struct V_133 * V_134 = & V_29 -> V_134 [ V_4 -> V_102 ] ;
struct V_9 * V_10 = F_16 ( V_29 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_15 . V_14 ) ;
struct V_104 * V_73 = V_4 -> V_105 ;
int V_55 ;
V_4 -> V_203 . V_5 = NULL ;
V_4 -> V_203 . V_158 = 0 ;
V_4 -> V_203 . V_6 = V_4 -> V_74 << V_75 ;
V_4 -> V_203 . V_184 = 0 ;
V_4 -> V_203 . V_122 = false ;
if ( ! ( V_134 -> V_8 & V_136 ) )
return - V_57 ;
switch ( V_4 -> V_102 ) {
case V_135 :
return 0 ;
case V_109 :
#if F_59 ( V_130 )
if ( V_10 -> V_131 . V_132 ) {
V_4 -> V_203 . V_158 = V_4 -> V_173 << V_75 ;
V_4 -> V_203 . V_184 = V_10 -> V_131 . V_184 ;
V_4 -> V_203 . V_122 = ! V_10 -> V_131 . V_204 ;
}
#endif
if ( V_10 -> V_15 . V_14 . V_39 . V_40 < V_41 || ! V_73 -> V_97 )
break;
case V_103 :
V_4 -> V_203 . V_158 = V_4 -> V_173 << V_75 ;
V_4 -> V_203 . V_184 = V_14 -> V_65 -> V_205 ( V_14 , 1 ) ;
V_4 -> V_203 . V_122 = true ;
if ( V_10 -> V_15 . V_14 . V_39 . V_40 >= V_41 ) {
struct V_206 * V_207 = F_64 ( & V_10 -> V_15 . V_14 ) ;
int V_44 = 12 ;
if ( V_10 -> V_15 . V_14 . V_39 . V_40 >= V_208 )
V_44 = V_73 -> V_44 ;
V_55 = F_123 ( V_207 , V_73 -> V_6 << 12 , V_44 ,
& V_73 -> V_209 ) ;
if ( V_55 )
return V_55 ;
F_91 ( & V_73 -> V_209 , V_73 ) ;
V_4 -> V_203 . V_158 = V_73 -> V_209 . V_158 ;
}
break;
default:
return - V_57 ;
}
return 0 ;
}
static void
F_124 ( struct V_126 * V_29 , struct V_154 * V_4 )
{
struct V_104 * V_73 = V_4 -> V_105 ;
if ( ! V_73 -> V_209 . V_210 )
return;
F_113 ( & V_73 -> V_209 ) ;
F_90 ( & V_73 -> V_209 ) ;
}
static int
F_125 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = F_16 ( V_28 -> V_29 ) ;
struct V_30 * V_31 = V_30 ( V_28 ) ;
struct V_13 * V_14 = F_2 ( & V_10 -> V_15 . V_14 ) ;
T_1 V_211 = V_14 -> V_65 -> V_212 ( V_14 , 1 ) >> V_75 ;
int V_11 , V_55 ;
if ( V_28 -> V_73 . V_102 != V_103 ) {
if ( V_10 -> V_15 . V_14 . V_39 . V_40 < V_41 ||
! F_126 ( V_31 ) )
return 0 ;
if ( V_28 -> V_73 . V_102 == V_135 ) {
F_29 ( V_31 , V_109 , 0 ) ;
V_55 = F_38 ( V_31 , false , false ) ;
if ( V_55 )
return V_55 ;
}
return 0 ;
}
if ( V_10 -> V_15 . V_14 . V_39 . V_40 >= V_41 ||
V_28 -> V_73 . V_173 + V_28 -> V_73 . V_74 < V_211 )
return 0 ;
for ( V_11 = 0 ; V_11 < V_31 -> V_76 . V_88 ; ++ V_11 ) {
V_31 -> V_89 [ V_11 ] . V_84 = 0 ;
V_31 -> V_89 [ V_11 ] . V_85 = V_211 ;
}
for ( V_11 = 0 ; V_11 < V_31 -> V_76 . V_90 ; ++ V_11 ) {
V_31 -> V_91 [ V_11 ] . V_84 = 0 ;
V_31 -> V_91 [ V_11 ] . V_85 = V_211 ;
}
F_29 ( V_31 , V_80 , 0 ) ;
return F_38 ( V_31 , false , false ) ;
}
static int
F_127 ( struct V_125 * V_64 )
{
struct V_113 * V_114 = ( void * ) V_64 ;
struct V_9 * V_10 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_14 * V_213 ;
unsigned V_11 ;
int V_214 ;
bool V_215 = ! ! ( V_64 -> V_127 & V_216 ) ;
if ( V_64 -> V_217 != V_218 )
return 0 ;
if ( V_215 && V_64 -> V_50 ) {
F_128 ( V_64 -> V_50 , V_64 -> V_219 ,
V_114 -> V_115 , V_64 -> V_74 ) ;
V_64 -> V_217 = V_220 ;
return 0 ;
}
V_10 = F_16 ( V_64 -> V_29 ) ;
V_14 = F_2 ( & V_10 -> V_15 . V_14 ) ;
V_2 = V_10 -> V_2 ;
V_213 = V_14 -> V_2 ;
#if F_59 ( V_130 )
if ( V_10 -> V_131 . V_132 ) {
return F_129 ( V_64 ) ;
}
#endif
#if F_59 ( V_221 ) && F_59 ( V_222 )
if ( F_130 () ) {
return F_131 ( ( void * ) V_64 , V_2 -> V_2 ) ;
}
#endif
V_214 = F_132 ( V_64 ) ;
if ( V_214 ) {
return V_214 ;
}
for ( V_11 = 0 ; V_11 < V_64 -> V_74 ; V_11 ++ ) {
T_7 V_5 ;
V_5 = F_133 ( V_213 , V_64 -> V_219 [ V_11 ] , 0 , V_45 ,
V_223 ) ;
if ( F_134 ( V_213 , V_5 ) ) {
while ( V_11 -- ) {
F_135 ( V_213 , V_114 -> V_115 [ V_11 ] ,
V_45 , V_223 ) ;
V_114 -> V_115 [ V_11 ] = 0 ;
}
F_136 ( V_64 ) ;
return - V_224 ;
}
V_114 -> V_115 [ V_11 ] = V_5 ;
}
return 0 ;
}
static void
F_137 ( struct V_125 * V_64 )
{
struct V_113 * V_114 = ( void * ) V_64 ;
struct V_9 * V_10 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_14 * V_213 ;
unsigned V_11 ;
bool V_215 = ! ! ( V_64 -> V_127 & V_216 ) ;
if ( V_215 )
return;
V_10 = F_16 ( V_64 -> V_29 ) ;
V_14 = F_2 ( & V_10 -> V_15 . V_14 ) ;
V_2 = V_10 -> V_2 ;
V_213 = V_14 -> V_2 ;
#if F_59 ( V_130 )
if ( V_10 -> V_131 . V_132 ) {
F_138 ( V_64 ) ;
return;
}
#endif
#if F_59 ( V_221 ) && F_59 ( V_222 )
if ( F_130 () ) {
F_139 ( ( void * ) V_64 , V_2 -> V_2 ) ;
return;
}
#endif
for ( V_11 = 0 ; V_11 < V_64 -> V_74 ; V_11 ++ ) {
if ( V_114 -> V_115 [ V_11 ] ) {
F_135 ( V_213 , V_114 -> V_115 [ V_11 ] , V_45 ,
V_223 ) ;
}
}
F_136 ( V_64 ) ;
}
void
F_140 ( struct V_30 * V_31 , struct V_24 * V_20 , bool V_225 )
{
struct V_51 * V_199 = V_31 -> V_28 . V_199 ;
if ( V_225 )
F_141 ( V_199 , & V_20 -> V_184 ) ;
else if ( V_20 )
F_142 ( V_199 , & V_20 -> V_184 ) ;
}
struct V_195 *
F_143 ( struct V_30 * V_31 , struct V_226 * V_69 )
{
struct V_195 * V_157 ;
F_111 (vma, &nvbo->vma_list, head) {
if ( V_157 -> V_69 == V_69 )
return V_157 ;
}
return NULL ;
}
int
F_144 ( struct V_30 * V_31 , struct V_226 * V_69 ,
struct V_195 * V_157 )
{
const T_1 V_6 = V_31 -> V_28 . V_73 . V_74 << V_75 ;
int V_55 ;
V_55 = F_89 ( V_69 , V_6 , V_31 -> V_44 ,
V_178 , V_157 ) ;
if ( V_55 )
return V_55 ;
if ( V_31 -> V_28 . V_73 . V_102 != V_135 &&
( V_31 -> V_28 . V_73 . V_102 == V_103 ||
V_31 -> V_44 != V_157 -> V_69 -> V_71 -> V_72 ) )
F_91 ( V_157 , V_31 -> V_28 . V_73 . V_105 ) ;
F_145 ( & V_157 -> V_61 , & V_31 -> V_63 ) ;
V_157 -> V_227 = 1 ;
return 0 ;
}
void
F_146 ( struct V_30 * V_31 , struct V_195 * V_157 )
{
if ( V_157 -> V_210 ) {
if ( V_31 -> V_28 . V_73 . V_102 != V_135 )
F_113 ( V_157 ) ;
F_90 ( V_157 ) ;
F_147 ( & V_157 -> V_61 ) ;
}
}
