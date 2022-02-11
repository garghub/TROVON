static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
int V_11 = V_4 - V_10 -> V_12 . V_4 ;
struct V_13 * V_14 = V_13 ( V_10 -> V_15 ) ;
struct V_16 * V_12 = & V_14 -> V_12 . V_17 [ V_11 ] ;
struct V_18 * V_19 ;
F_2 ( & V_4 -> V_20 ) ;
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
F_3 ( struct V_1 * V_2 , int V_11 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_3 * V_12 = & V_10 -> V_12 . V_4 [ V_11 ] ;
F_4 ( & V_10 -> V_12 . V_27 ) ;
if ( ! V_12 -> V_28 &&
( ! V_12 -> V_20 || F_5 ( V_12 -> V_20 ) ) )
V_12 -> V_28 = true ;
else
V_12 = NULL ;
F_6 ( & V_10 -> V_12 . V_27 ) ;
return V_12 ;
}
static void
F_7 ( struct V_1 * V_2 , struct V_3 * V_12 ,
struct V_29 * V_20 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
if ( V_12 ) {
F_4 ( & V_10 -> V_12 . V_27 ) ;
V_12 -> V_20 = F_8 ( V_20 ) ;
V_12 -> V_28 = false ;
F_6 ( & V_10 -> V_12 . V_27 ) ;
}
}
static struct V_3 *
F_9 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_13 * V_14 = V_13 ( V_10 -> V_15 ) ;
struct V_3 * V_12 , * V_30 = NULL ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_14 -> V_12 . V_31 ; V_11 ++ ) {
V_12 = F_3 ( V_2 , V_11 ) ;
if ( V_7 && ! V_30 ) {
V_30 = V_12 ;
continue;
} else if ( V_12 && V_14 -> V_12 . V_17 [ V_11 ] . V_7 ) {
F_1 ( V_2 , V_12 , 0 , 0 , 0 , 0 ) ;
}
F_7 ( V_2 , V_12 , NULL ) ;
}
if ( V_30 )
F_1 ( V_2 , V_30 , V_5 , V_6 ,
V_7 , V_8 ) ;
return V_30 ;
}
static void
F_10 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
if ( F_12 ( V_36 -> V_37 . V_38 ) )
F_13 ( L_1 , V_33 ) ;
F_14 ( V_36 -> V_39 > 0 ) ;
F_7 ( V_2 , V_36 -> V_12 , NULL ) ;
F_15 ( V_36 ) ;
}
static void
F_16 ( struct V_35 * V_36 , T_1 V_8 ,
int * V_40 , int * V_6 )
{
struct V_9 * V_10 = F_11 ( V_36 -> V_33 . V_34 ) ;
struct V_41 * V_15 = F_17 ( V_10 -> V_15 ) ;
if ( V_15 -> V_42 < V_43 ) {
if ( V_36 -> V_44 ) {
if ( V_15 -> V_45 >= 0x40 ) {
* V_40 = 65536 ;
* V_6 = F_18 ( * V_6 , 64 * V_36 -> V_44 ) ;
} else if ( V_15 -> V_45 >= 0x30 ) {
* V_40 = 32768 ;
* V_6 = F_18 ( * V_6 , 64 * V_36 -> V_44 ) ;
} else if ( V_15 -> V_45 >= 0x20 ) {
* V_40 = 16384 ;
* V_6 = F_18 ( * V_6 , 64 * V_36 -> V_44 ) ;
} else if ( V_15 -> V_45 >= 0x10 ) {
* V_40 = 16384 ;
* V_6 = F_18 ( * V_6 , 32 * V_36 -> V_44 ) ;
}
}
} else {
* V_6 = F_18 ( * V_6 , ( 1 << V_36 -> V_46 ) ) ;
* V_40 = F_19 ( ( 1 << V_36 -> V_46 ) , * V_40 ) ;
}
* V_6 = F_18 ( * V_6 , V_47 ) ;
}
int
F_20 ( struct V_1 * V_2 , int V_6 , int V_40 ,
T_2 V_8 , T_2 V_44 , T_2 V_48 ,
struct V_49 * V_50 ,
struct V_35 * * V_51 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_35 * V_36 ;
T_3 V_52 ;
int V_53 ;
int type = V_54 ;
int V_55 = 12 ;
int V_56 ;
if ( V_10 -> V_57 . V_58 . V_59 )
V_55 = V_10 -> V_57 . V_58 . V_59 -> V_60 -> V_55 ;
V_56 = V_61 & ~ ( ( 1 << V_55 ) - 1 ) ;
if ( V_6 <= 0 || V_6 > V_56 ) {
F_21 ( V_10 , L_2 , ( T_1 ) V_6 ) ;
return - V_62 ;
}
if ( V_50 )
type = V_63 ;
V_36 = F_22 ( sizeof( struct V_35 ) , V_64 ) ;
if ( ! V_36 )
return - V_65 ;
F_23 ( & V_36 -> V_66 ) ;
F_23 ( & V_36 -> V_67 ) ;
F_23 ( & V_36 -> V_68 ) ;
V_36 -> V_44 = V_44 ;
V_36 -> V_48 = V_48 ;
V_36 -> V_33 . V_34 = & V_10 -> V_69 . V_34 ;
V_36 -> V_46 = 12 ;
if ( V_10 -> V_57 . V_58 . V_59 ) {
if ( ! ( V_8 & V_70 ) && V_6 > 256 * 1024 )
V_36 -> V_46 = V_10 -> V_57 . V_58 . V_59 -> V_60 -> V_55 ;
}
F_16 ( V_36 , V_8 , & V_40 , & V_6 ) ;
V_36 -> V_33 . V_71 . V_72 = V_6 >> V_73 ;
F_24 ( V_36 , V_8 , 0 ) ;
V_52 = F_25 ( & V_10 -> V_69 . V_34 , V_6 ,
sizeof( struct V_35 ) ) ;
V_53 = F_26 ( & V_10 -> V_69 . V_34 , & V_36 -> V_33 , V_6 ,
type , & V_36 -> V_74 ,
V_40 >> V_73 , false , NULL , V_52 , V_50 ,
F_10 ) ;
if ( V_53 ) {
return V_53 ;
}
* V_51 = V_36 ;
return 0 ;
}
static void
F_27 ( T_2 * V_75 , unsigned * V_76 , T_2 type , T_2 V_8 )
{
* V_76 = 0 ;
if ( type & V_77 )
V_75 [ ( * V_76 ) ++ ] = V_77 | V_8 ;
if ( type & V_70 )
V_75 [ ( * V_76 ) ++ ] = V_70 | V_8 ;
if ( type & V_78 )
V_75 [ ( * V_76 ) ++ ] = V_78 | V_8 ;
}
static void
F_28 ( struct V_35 * V_36 , T_2 type )
{
struct V_9 * V_10 = F_11 ( V_36 -> V_33 . V_34 ) ;
struct V_13 * V_14 = V_13 ( V_10 -> V_15 ) ;
T_1 V_79 = V_14 -> V_80 -> V_6 >> V_73 ;
if ( ( F_17 ( V_10 -> V_15 ) -> V_42 == V_81 ||
F_17 ( V_10 -> V_15 ) -> V_42 == V_82 ) &&
V_36 -> V_44 && ( type & V_77 ) &&
V_36 -> V_33 . V_71 . V_72 < V_79 / 4 ) {
if ( V_36 -> V_48 & V_83 ) {
V_36 -> V_74 . V_84 = V_79 / 2 ;
V_36 -> V_74 . V_85 = ~ 0 ;
} else {
V_36 -> V_74 . V_84 = 0 ;
V_36 -> V_74 . V_85 = V_79 / 2 ;
}
}
}
void
F_24 ( struct V_35 * V_36 , T_2 type , T_2 V_86 )
{
struct V_87 * V_75 = & V_36 -> V_74 ;
T_2 V_8 = V_88 |
( V_36 -> V_39 ? V_89 : 0 ) ;
V_75 -> V_74 = V_36 -> V_90 ;
F_27 ( V_36 -> V_90 , & V_75 -> V_91 ,
type , V_8 ) ;
V_75 -> V_92 = V_36 -> V_93 ;
F_27 ( V_36 -> V_93 , & V_75 -> V_94 ,
type | V_86 , V_8 ) ;
F_28 ( V_36 , type ) ;
}
int
F_29 ( struct V_35 * V_36 , T_2 V_95 )
{
struct V_9 * V_10 = F_11 ( V_36 -> V_33 . V_34 ) ;
struct V_32 * V_33 = & V_36 -> V_33 ;
int V_53 ;
V_53 = F_30 ( V_33 , false , false , false , 0 ) ;
if ( V_53 )
goto V_96;
if ( V_36 -> V_39 && ! ( V_95 & ( 1 << V_33 -> V_71 . V_97 ) ) ) {
F_31 ( V_10 , L_3 , V_33 ,
1 << V_33 -> V_71 . V_97 , V_95 ) ;
V_53 = - V_62 ;
goto V_96;
}
if ( V_36 -> V_39 ++ )
goto V_96;
F_24 ( V_36 , V_95 , 0 ) ;
V_53 = F_32 ( V_36 , false , false ) ;
if ( V_53 == 0 ) {
switch ( V_33 -> V_71 . V_97 ) {
case V_98 :
V_10 -> V_37 . V_99 -= V_33 -> V_71 . V_6 ;
break;
case V_100 :
V_10 -> V_37 . V_101 -= V_33 -> V_71 . V_6 ;
break;
default:
break;
}
}
V_96:
F_33 ( V_33 ) ;
return V_53 ;
}
int
F_34 ( struct V_35 * V_36 )
{
struct V_9 * V_10 = F_11 ( V_36 -> V_33 . V_34 ) ;
struct V_32 * V_33 = & V_36 -> V_33 ;
int V_53 , V_102 ;
V_53 = F_30 ( V_33 , false , false , false , 0 ) ;
if ( V_53 )
return V_53 ;
V_102 = -- V_36 -> V_39 ;
F_35 ( V_102 < 0 ) ;
if ( V_102 )
goto V_96;
F_24 ( V_36 , V_33 -> V_71 . V_74 , 0 ) ;
V_53 = F_32 ( V_36 , false , false ) ;
if ( V_53 == 0 ) {
switch ( V_33 -> V_71 . V_97 ) {
case V_98 :
V_10 -> V_37 . V_99 += V_33 -> V_71 . V_6 ;
break;
case V_100 :
V_10 -> V_37 . V_101 += V_33 -> V_71 . V_6 ;
break;
default:
break;
}
}
V_96:
F_33 ( V_33 ) ;
return V_53 ;
}
int
F_36 ( struct V_35 * V_36 )
{
int V_53 ;
V_53 = F_30 ( & V_36 -> V_33 , false , false , false , 0 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_37 ( & V_36 -> V_33 , 0 , V_36 -> V_33 . V_71 . V_72 , & V_36 -> V_103 ) ;
F_33 ( & V_36 -> V_33 ) ;
return V_53 ;
}
void
F_38 ( struct V_35 * V_36 )
{
if ( V_36 )
F_39 ( & V_36 -> V_103 ) ;
}
int
F_32 ( struct V_35 * V_36 , bool V_104 ,
bool V_105 )
{
int V_53 ;
V_53 = F_40 ( & V_36 -> V_33 , & V_36 -> V_74 ,
V_104 , V_105 ) ;
if ( V_53 )
return V_53 ;
return 0 ;
}
T_4
F_41 ( struct V_35 * V_36 , unsigned V_106 )
{
bool V_107 ;
T_4 * V_71 = F_42 ( & V_36 -> V_103 , & V_107 ) ;
V_71 = & V_71 [ V_106 ] ;
if ( V_107 )
return F_43 ( ( void V_108 V_109 * ) V_71 ) ;
else
return * V_71 ;
}
void
F_44 ( struct V_35 * V_36 , unsigned V_106 , T_4 V_110 )
{
bool V_107 ;
T_4 * V_71 = F_42 ( & V_36 -> V_103 , & V_107 ) ;
V_71 = & V_71 [ V_106 ] ;
if ( V_107 )
F_45 ( V_110 , ( void V_108 V_109 * ) V_71 ) ;
else
* V_71 = V_110 ;
}
T_1
F_46 ( struct V_35 * V_36 , unsigned V_106 )
{
bool V_107 ;
T_1 * V_71 = F_42 ( & V_36 -> V_103 , & V_107 ) ;
V_71 = & V_71 [ V_106 ] ;
if ( V_107 )
return F_47 ( ( void V_108 V_109 * ) V_71 ) ;
else
return * V_71 ;
}
void
F_48 ( struct V_35 * V_36 , unsigned V_106 , T_1 V_110 )
{
bool V_107 ;
T_1 * V_71 = F_42 ( & V_36 -> V_103 , & V_107 ) ;
V_71 = & V_71 [ V_106 ] ;
if ( V_107 )
F_49 ( V_110 , ( void V_108 V_109 * ) V_71 ) ;
else
* V_71 = V_110 ;
}
static struct V_111 *
F_50 ( struct V_112 * V_34 , unsigned long V_6 ,
T_2 V_113 , struct V_114 * V_115 )
{
#if V_116
struct V_9 * V_10 = F_11 ( V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_10 -> V_117 . V_118 == V_119 ) {
return F_51 ( V_34 , V_2 -> V_117 -> V_120 , V_6 ,
V_113 , V_115 ) ;
}
#endif
return F_52 ( V_34 , V_6 , V_113 , V_115 ) ;
}
static int
F_53 ( struct V_112 * V_34 , T_2 V_8 )
{
return 0 ;
}
static int
F_54 ( struct V_112 * V_34 , T_2 type ,
struct V_121 * V_122 )
{
struct V_9 * V_10 = F_11 ( V_34 ) ;
switch ( type ) {
case V_123 :
V_122 -> V_8 = V_124 ;
V_122 -> V_125 = V_88 ;
V_122 -> V_126 = V_127 ;
break;
case V_98 :
if ( F_17 ( V_10 -> V_15 ) -> V_42 >= V_43 ) {
V_122 -> V_128 = & V_129 ;
V_122 -> V_130 = false ;
V_122 -> V_131 = true ;
} else {
V_122 -> V_128 = & V_132 ;
}
V_122 -> V_8 = V_133 |
V_124 ;
V_122 -> V_125 = V_134 |
V_135 ;
V_122 -> V_126 = V_135 ;
break;
case V_100 :
if ( F_17 ( V_10 -> V_15 ) -> V_42 >= V_43 )
V_122 -> V_128 = & V_136 ;
else
if ( V_10 -> V_117 . V_118 != V_119 )
V_122 -> V_128 = & V_137 ;
else
V_122 -> V_128 = & V_132 ;
if ( V_10 -> V_117 . V_118 == V_119 ) {
V_122 -> V_8 = V_124 ;
V_122 -> V_125 = V_134 |
V_135 ;
V_122 -> V_126 = V_135 ;
} else {
V_122 -> V_8 = V_124 |
V_138 ;
V_122 -> V_125 = V_88 ;
V_122 -> V_126 = V_127 ;
}
break;
default:
return - V_62 ;
}
return 0 ;
}
static void
F_55 ( struct V_32 * V_33 , struct V_87 * V_75 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
switch ( V_33 -> V_71 . V_97 ) {
case V_98 :
F_24 ( V_36 , V_70 ,
V_78 ) ;
break;
default:
F_24 ( V_36 , V_78 , 0 ) ;
break;
}
* V_75 = V_36 -> V_74 ;
}
static int
F_56 ( struct V_139 * V_140 ,
struct V_35 * V_36 , bool V_141 ,
bool V_105 , struct V_142 * V_143 )
{
struct V_29 * V_20 = NULL ;
int V_53 ;
V_53 = F_57 ( V_140 , false , & V_20 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_58 ( & V_36 -> V_33 , V_20 , V_141 ,
V_105 , V_143 ) ;
F_2 ( & V_20 ) ;
return V_53 ;
}
static int
F_59 ( struct V_139 * V_140 , T_1 V_144 )
{
int V_53 = F_60 ( V_140 , 2 ) ;
if ( V_53 == 0 ) {
F_61 ( V_140 , V_145 , 0x0000 , 1 ) ;
F_62 ( V_140 , V_144 & 0x0000ffff ) ;
F_63 ( V_140 ) ;
}
return V_53 ;
}
static int
F_64 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_142 * V_146 , struct V_142 * V_143 )
{
struct V_147 * V_148 = V_146 -> V_149 ;
int V_53 = F_60 ( V_140 , 10 ) ;
if ( V_53 == 0 ) {
F_61 ( V_140 , V_145 , 0x0400 , 8 ) ;
F_62 ( V_140 , F_65 ( V_148 -> V_150 [ 0 ] . V_151 ) ) ;
F_62 ( V_140 , F_66 ( V_148 -> V_150 [ 0 ] . V_151 ) ) ;
F_62 ( V_140 , F_65 ( V_148 -> V_150 [ 1 ] . V_151 ) ) ;
F_62 ( V_140 , F_66 ( V_148 -> V_150 [ 1 ] . V_151 ) ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_143 -> V_72 ) ;
F_67 ( V_140 , V_145 , 0x0300 , 0x0386 ) ;
}
return V_53 ;
}
static int
F_68 ( struct V_139 * V_140 , T_1 V_144 )
{
int V_53 = F_60 ( V_140 , 2 ) ;
if ( V_53 == 0 ) {
F_61 ( V_140 , V_145 , 0x0000 , 1 ) ;
F_62 ( V_140 , V_144 ) ;
}
return V_53 ;
}
static int
F_69 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_142 * V_146 , struct V_142 * V_143 )
{
struct V_147 * V_148 = V_146 -> V_149 ;
T_5 V_152 = V_148 -> V_150 [ 0 ] . V_151 ;
T_5 V_153 = V_148 -> V_150 [ 1 ] . V_151 ;
T_1 V_154 = V_143 -> V_72 ;
int V_53 ;
V_154 = V_143 -> V_72 ;
while ( V_154 ) {
int V_155 = ( V_154 > 8191 ) ? 8191 : V_154 ;
V_53 = F_60 ( V_140 , 11 ) ;
if ( V_53 )
return V_53 ;
F_61 ( V_140 , V_145 , 0x030c , 8 ) ;
F_62 ( V_140 , F_65 ( V_152 ) ) ;
F_62 ( V_140 , F_66 ( V_152 ) ) ;
F_62 ( V_140 , F_65 ( V_153 ) ) ;
F_62 ( V_140 , F_66 ( V_153 ) ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_155 ) ;
F_61 ( V_140 , V_145 , 0x0300 , 1 ) ;
F_62 ( V_140 , 0x00000110 ) ;
V_154 -= V_155 ;
V_152 += ( V_47 * V_155 ) ;
V_153 += ( V_47 * V_155 ) ;
}
return 0 ;
}
static int
F_70 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_142 * V_146 , struct V_142 * V_143 )
{
struct V_147 * V_148 = V_146 -> V_149 ;
T_5 V_152 = V_148 -> V_150 [ 0 ] . V_151 ;
T_5 V_153 = V_148 -> V_150 [ 1 ] . V_151 ;
T_1 V_154 = V_143 -> V_72 ;
int V_53 ;
V_154 = V_143 -> V_72 ;
while ( V_154 ) {
int V_155 = ( V_154 > 2047 ) ? 2047 : V_154 ;
V_53 = F_60 ( V_140 , 12 ) ;
if ( V_53 )
return V_53 ;
F_61 ( V_140 , V_145 , 0x0238 , 2 ) ;
F_62 ( V_140 , F_65 ( V_153 ) ) ;
F_62 ( V_140 , F_66 ( V_153 ) ) ;
F_61 ( V_140 , V_145 , 0x030c , 6 ) ;
F_62 ( V_140 , F_65 ( V_152 ) ) ;
F_62 ( V_140 , F_66 ( V_152 ) ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_155 ) ;
F_61 ( V_140 , V_145 , 0x0300 , 1 ) ;
F_62 ( V_140 , 0x00100110 ) ;
V_154 -= V_155 ;
V_152 += ( V_47 * V_155 ) ;
V_153 += ( V_47 * V_155 ) ;
}
return 0 ;
}
static int
F_71 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_142 * V_146 , struct V_142 * V_143 )
{
struct V_147 * V_148 = V_146 -> V_149 ;
T_5 V_152 = V_148 -> V_150 [ 0 ] . V_151 ;
T_5 V_153 = V_148 -> V_150 [ 1 ] . V_151 ;
T_1 V_154 = V_143 -> V_72 ;
int V_53 ;
V_154 = V_143 -> V_72 ;
while ( V_154 ) {
int V_155 = ( V_154 > 8191 ) ? 8191 : V_154 ;
V_53 = F_60 ( V_140 , 11 ) ;
if ( V_53 )
return V_53 ;
F_72 ( V_140 , V_145 , 0x030c , 8 ) ;
F_62 ( V_140 , F_65 ( V_152 ) ) ;
F_62 ( V_140 , F_66 ( V_152 ) ) ;
F_62 ( V_140 , F_65 ( V_153 ) ) ;
F_62 ( V_140 , F_66 ( V_153 ) ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_155 ) ;
F_72 ( V_140 , V_145 , 0x0300 , 1 ) ;
F_62 ( V_140 , 0x00000110 ) ;
V_154 -= V_155 ;
V_152 += ( V_47 * V_155 ) ;
V_153 += ( V_47 * V_155 ) ;
}
return 0 ;
}
static int
F_73 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_142 * V_146 , struct V_142 * V_143 )
{
struct V_147 * V_148 = V_146 -> V_149 ;
int V_53 = F_60 ( V_140 , 7 ) ;
if ( V_53 == 0 ) {
F_72 ( V_140 , V_145 , 0x0320 , 6 ) ;
F_62 ( V_140 , F_65 ( V_148 -> V_150 [ 0 ] . V_151 ) ) ;
F_62 ( V_140 , F_66 ( V_148 -> V_150 [ 0 ] . V_151 ) ) ;
F_62 ( V_140 , F_65 ( V_148 -> V_150 [ 1 ] . V_151 ) ) ;
F_62 ( V_140 , F_66 ( V_148 -> V_150 [ 1 ] . V_151 ) ) ;
F_62 ( V_140 , 0x00000000 ) ;
F_62 ( V_140 , V_143 -> V_72 << V_73 ) ;
}
return V_53 ;
}
static int
F_74 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_142 * V_146 , struct V_142 * V_143 )
{
struct V_147 * V_148 = V_146 -> V_149 ;
int V_53 = F_60 ( V_140 , 7 ) ;
if ( V_53 == 0 ) {
F_72 ( V_140 , V_145 , 0x0304 , 6 ) ;
F_62 ( V_140 , V_143 -> V_72 << V_73 ) ;
F_62 ( V_140 , F_65 ( V_148 -> V_150 [ 0 ] . V_151 ) ) ;
F_62 ( V_140 , F_66 ( V_148 -> V_150 [ 0 ] . V_151 ) ) ;
F_62 ( V_140 , F_65 ( V_148 -> V_150 [ 1 ] . V_151 ) ) ;
F_62 ( V_140 , F_66 ( V_148 -> V_150 [ 1 ] . V_151 ) ) ;
F_62 ( V_140 , 0x00000000 ) ;
}
return V_53 ;
}
static int
F_75 ( struct V_139 * V_140 , T_1 V_144 )
{
int V_53 = F_60 ( V_140 , 6 ) ;
if ( V_53 == 0 ) {
F_72 ( V_140 , V_145 , 0x0000 , 1 ) ;
F_62 ( V_140 , V_144 ) ;
F_72 ( V_140 , V_145 , 0x0180 , 3 ) ;
F_62 ( V_140 , V_156 ) ;
F_62 ( V_140 , V_157 ) ;
F_62 ( V_140 , V_157 ) ;
}
return V_53 ;
}
static int
F_76 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_142 * V_146 , struct V_142 * V_143 )
{
struct V_147 * V_148 = V_146 -> V_149 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
T_5 V_158 = ( V_143 -> V_72 << V_73 ) ;
T_5 V_152 = V_148 -> V_150 [ 0 ] . V_151 ;
T_5 V_153 = V_148 -> V_150 [ 1 ] . V_151 ;
int V_53 ;
while ( V_158 ) {
T_1 V_159 , V_160 , V_161 ;
V_159 = F_77 ( V_158 , ( T_5 ) ( 4 * 1024 * 1024 ) ) ;
V_160 = 16 * 4 ;
V_161 = V_159 / V_160 ;
if ( V_146 -> V_97 == V_98 &&
F_78 ( V_36 ) ) {
V_53 = F_60 ( V_140 , 8 ) ;
if ( V_53 )
return V_53 ;
F_72 ( V_140 , V_145 , 0x0200 , 7 ) ;
F_62 ( V_140 , 0 ) ;
F_62 ( V_140 , 0 ) ;
F_62 ( V_140 , V_160 ) ;
F_62 ( V_140 , V_161 ) ;
F_62 ( V_140 , 1 ) ;
F_62 ( V_140 , 0 ) ;
F_62 ( V_140 , 0 ) ;
} else {
V_53 = F_60 ( V_140 , 2 ) ;
if ( V_53 )
return V_53 ;
F_72 ( V_140 , V_145 , 0x0200 , 1 ) ;
F_62 ( V_140 , 1 ) ;
}
if ( V_143 -> V_97 == V_98 &&
F_78 ( V_36 ) ) {
V_53 = F_60 ( V_140 , 8 ) ;
if ( V_53 )
return V_53 ;
F_72 ( V_140 , V_145 , 0x021c , 7 ) ;
F_62 ( V_140 , 0 ) ;
F_62 ( V_140 , 0 ) ;
F_62 ( V_140 , V_160 ) ;
F_62 ( V_140 , V_161 ) ;
F_62 ( V_140 , 1 ) ;
F_62 ( V_140 , 0 ) ;
F_62 ( V_140 , 0 ) ;
} else {
V_53 = F_60 ( V_140 , 2 ) ;
if ( V_53 )
return V_53 ;
F_72 ( V_140 , V_145 , 0x021c , 1 ) ;
F_62 ( V_140 , 1 ) ;
}
V_53 = F_60 ( V_140 , 14 ) ;
if ( V_53 )
return V_53 ;
F_72 ( V_140 , V_145 , 0x0238 , 2 ) ;
F_62 ( V_140 , F_65 ( V_152 ) ) ;
F_62 ( V_140 , F_65 ( V_153 ) ) ;
F_72 ( V_140 , V_145 , 0x030c , 8 ) ;
F_62 ( V_140 , F_66 ( V_152 ) ) ;
F_62 ( V_140 , F_66 ( V_153 ) ) ;
F_62 ( V_140 , V_160 ) ;
F_62 ( V_140 , V_160 ) ;
F_62 ( V_140 , V_160 ) ;
F_62 ( V_140 , V_161 ) ;
F_62 ( V_140 , 0x00000101 ) ;
F_62 ( V_140 , 0x00000000 ) ;
F_72 ( V_140 , V_145 , V_162 , 1 ) ;
F_62 ( V_140 , 0 ) ;
V_158 -= V_159 ;
V_152 += V_159 ;
V_153 += V_159 ;
}
return 0 ;
}
static int
F_79 ( struct V_139 * V_140 , T_1 V_144 )
{
int V_53 = F_60 ( V_140 , 4 ) ;
if ( V_53 == 0 ) {
F_72 ( V_140 , V_145 , 0x0000 , 1 ) ;
F_62 ( V_140 , V_144 ) ;
F_72 ( V_140 , V_145 , 0x0180 , 1 ) ;
F_62 ( V_140 , V_156 ) ;
}
return V_53 ;
}
static inline T_2
F_80 ( struct V_32 * V_33 ,
struct V_139 * V_140 , struct V_142 * V_71 )
{
if ( V_71 -> V_97 == V_100 )
return V_163 ;
return V_157 ;
}
static int
F_81 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_142 * V_146 , struct V_142 * V_143 )
{
T_1 V_152 = V_146 -> V_164 << V_73 ;
T_1 V_153 = V_143 -> V_164 << V_73 ;
T_1 V_154 = V_143 -> V_72 ;
int V_53 ;
V_53 = F_60 ( V_140 , 3 ) ;
if ( V_53 )
return V_53 ;
F_72 ( V_140 , V_145 , V_165 , 2 ) ;
F_62 ( V_140 , F_80 ( V_33 , V_140 , V_146 ) ) ;
F_62 ( V_140 , F_80 ( V_33 , V_140 , V_143 ) ) ;
V_154 = V_143 -> V_72 ;
while ( V_154 ) {
int V_155 = ( V_154 > 2047 ) ? 2047 : V_154 ;
V_53 = F_60 ( V_140 , 11 ) ;
if ( V_53 )
return V_53 ;
F_72 ( V_140 , V_145 ,
V_166 , 8 ) ;
F_62 ( V_140 , V_152 ) ;
F_62 ( V_140 , V_153 ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_47 ) ;
F_62 ( V_140 , V_155 ) ;
F_62 ( V_140 , 0x00000101 ) ;
F_62 ( V_140 , 0x00000000 ) ;
F_72 ( V_140 , V_145 , V_162 , 1 ) ;
F_62 ( V_140 , 0 ) ;
V_154 -= V_155 ;
V_152 += ( V_47 * V_155 ) ;
V_153 += ( V_47 * V_155 ) ;
}
return 0 ;
}
static int
F_82 ( struct V_139 * V_140 , struct V_35 * V_36 ,
struct V_142 * V_71 , struct V_167 * V_150 )
{
struct V_147 * V_148 = V_71 -> V_149 ;
int V_53 ;
V_53 = F_83 ( F_84 ( V_140 -> V_168 ) -> V_59 , V_71 -> V_72 <<
V_73 , V_148 -> V_46 ,
V_169 , V_150 ) ;
if ( V_53 )
return V_53 ;
if ( V_71 -> V_97 == V_98 )
F_85 ( V_150 , V_148 ) ;
else
F_86 ( V_150 , 0 , V_71 -> V_72 << V_73 , V_148 ) ;
return 0 ;
}
static int
F_87 ( struct V_32 * V_33 , int V_141 , bool V_170 ,
bool V_105 , struct V_142 * V_143 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_139 * V_140 = V_10 -> V_69 . V_140 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_142 * V_146 = & V_33 -> V_71 ;
int V_53 ;
F_88 ( & V_140 -> V_168 -> V_171 , V_172 ) ;
if ( F_17 ( V_10 -> V_15 ) -> V_42 >= V_43 ) {
struct V_147 * V_148 = V_146 -> V_149 ;
V_53 = F_82 ( V_140 , V_36 , V_146 , & V_148 -> V_150 [ 0 ] ) ;
if ( V_53 )
goto V_96;
V_53 = F_82 ( V_140 , V_36 , V_143 , & V_148 -> V_150 [ 1 ] ) ;
if ( V_53 )
goto V_96;
}
V_53 = V_10 -> V_69 . V_173 ( V_140 , V_33 , & V_33 -> V_71 , V_143 ) ;
if ( V_53 == 0 ) {
V_53 = F_56 ( V_140 , V_36 , V_141 ,
V_105 , V_143 ) ;
}
V_96:
F_89 ( & V_140 -> V_168 -> V_171 ) ;
return V_53 ;
}
void
F_90 ( struct V_9 * V_10 )
{
static const struct {
const char * V_174 ;
int V_19 ;
T_1 V_175 ;
int (* F_91)( struct V_139 * ,
struct V_32 * ,
struct V_142 * , struct V_142 * );
int (* V_22)( struct V_139 * , T_1 V_144 );
} V_176 [] = {
{ L_4 , 4 , 0xa0b5 , F_64 , F_59 } ,
{ L_5 , 0 , 0xa0b5 , F_64 , F_68 } ,
{ L_6 , 5 , 0x90b8 , F_69 , F_68 } ,
{ L_7 , 4 , 0x90b5 , F_69 , F_68 } ,
{ L_4 , 0 , 0x85b5 , F_71 , F_75 } ,
{ L_8 , 0 , 0x74c1 , F_74 , F_75 } ,
{ L_9 , 0 , 0x9039 , F_70 , F_68 } ,
{ L_9 , 0 , 0x5039 , F_76 , F_75 } ,
{ L_9 , 0 , 0x0039 , F_81 , F_79 } ,
{} ,
{ L_8 , 0 , 0x88b4 , F_73 , F_75 } ,
} , * V_177 = V_176 ;
const char * V_174 = L_10 ;
int V_53 ;
do {
struct V_178 * V_179 ;
struct V_139 * V_140 ;
T_1 V_144 = ( V_177 -> V_19 << 16 ) | V_177 -> V_175 ;
if ( V_177 -> V_19 )
V_140 = V_10 -> V_180 ;
else
V_140 = V_10 -> V_181 ;
if ( V_140 == NULL )
continue;
V_53 = F_92 ( F_93 ( V_10 ) , V_140 -> V_144 , V_144 ,
V_177 -> V_175 , NULL , 0 , & V_179 ) ;
if ( V_53 == 0 ) {
V_53 = V_177 -> V_22 ( V_140 , V_144 ) ;
if ( V_53 ) {
F_94 ( F_93 ( V_10 ) ,
V_140 -> V_144 , V_144 ) ;
continue;
}
V_10 -> V_69 . V_173 = V_177 -> F_91 ;
V_10 -> V_69 . V_140 = V_140 ;
V_174 = V_177 -> V_174 ;
break;
}
} while ( ( ++ V_177 ) -> F_91 );
F_95 ( V_10 , L_11 , V_174 ) ;
}
static int
F_96 ( struct V_32 * V_33 , bool V_141 , bool V_170 ,
bool V_105 , struct V_142 * V_143 )
{
T_1 V_182 = V_70 | V_88 ;
struct V_87 V_74 ;
struct V_142 V_183 ;
int V_53 ;
V_74 . V_84 = V_74 . V_85 = 0 ;
V_74 . V_91 = V_74 . V_94 = 1 ;
V_74 . V_74 = V_74 . V_92 = & V_182 ;
V_183 = * V_143 ;
V_183 . V_149 = NULL ;
V_53 = F_97 ( V_33 , & V_74 , & V_183 , V_170 , V_105 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_98 ( V_33 -> V_69 , & V_183 ) ;
if ( V_53 )
goto V_96;
V_53 = F_87 ( V_33 , true , V_170 , V_105 , & V_183 ) ;
if ( V_53 )
goto V_96;
V_53 = F_99 ( V_33 , true , V_105 , V_143 ) ;
V_96:
F_100 ( V_33 , & V_183 ) ;
return V_53 ;
}
static int
F_101 ( struct V_32 * V_33 , bool V_141 , bool V_170 ,
bool V_105 , struct V_142 * V_143 )
{
T_1 V_182 = V_70 | V_88 ;
struct V_87 V_74 ;
struct V_142 V_183 ;
int V_53 ;
V_74 . V_84 = V_74 . V_85 = 0 ;
V_74 . V_91 = V_74 . V_94 = 1 ;
V_74 . V_74 = V_74 . V_92 = & V_182 ;
V_183 = * V_143 ;
V_183 . V_149 = NULL ;
V_53 = F_97 ( V_33 , & V_74 , & V_183 , V_170 , V_105 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_99 ( V_33 , true , V_105 , & V_183 ) ;
if ( V_53 )
goto V_96;
V_53 = F_87 ( V_33 , true , V_170 , V_105 , V_143 ) ;
if ( V_53 )
goto V_96;
V_96:
F_100 ( V_33 , & V_183 ) ;
return V_53 ;
}
static void
F_102 ( struct V_32 * V_33 , struct V_142 * V_143 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_167 * V_150 ;
if ( V_33 -> V_184 != F_10 )
return;
F_103 (vma, &nvbo->vma_list, head) {
if ( V_143 && V_143 -> V_97 == V_98 ) {
F_85 ( V_150 , V_143 -> V_149 ) ;
} else
if ( V_143 && V_143 -> V_97 == V_100 &&
V_36 -> V_46 == V_150 -> V_59 -> V_60 -> V_185 ) {
if ( ( (struct V_147 * ) V_143 -> V_149 ) -> V_50 )
F_104 ( V_150 , 0 , V_143 ->
V_72 << V_73 ,
V_143 -> V_149 ) ;
else
F_86 ( V_150 , 0 , V_143 ->
V_72 << V_73 ,
V_143 -> V_149 ) ;
} else {
F_105 ( V_150 ) ;
}
}
}
static int
F_106 ( struct V_32 * V_33 , struct V_142 * V_143 ,
struct V_3 * * V_186 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
T_5 V_151 = V_143 -> V_164 << V_73 ;
* V_186 = NULL ;
if ( V_143 -> V_97 != V_98 )
return 0 ;
if ( F_17 ( V_10 -> V_15 ) -> V_42 >= V_81 ) {
* V_186 = F_9 ( V_2 , V_151 , V_143 -> V_6 ,
V_36 -> V_44 ,
V_36 -> V_48 ) ;
}
return 0 ;
}
static void
F_107 ( struct V_32 * V_33 ,
struct V_3 * V_186 ,
struct V_3 * * V_187 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_7 ( V_2 , * V_187 , V_33 -> V_188 ) ;
* V_187 = V_186 ;
}
static int
F_108 ( struct V_32 * V_33 , bool V_141 , bool V_170 ,
bool V_105 , struct V_142 * V_143 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_142 * V_146 = & V_33 -> V_71 ;
struct V_3 * V_186 = NULL ;
int V_53 = 0 ;
if ( F_17 ( V_10 -> V_15 ) -> V_42 < V_43 ) {
V_53 = F_106 ( V_33 , V_143 , & V_186 ) ;
if ( V_53 )
return V_53 ;
}
if ( V_146 -> V_97 == V_123 && ! V_33 -> V_69 ) {
F_109 ( V_33 -> V_71 . V_149 != NULL ) ;
V_33 -> V_71 = * V_143 ;
V_143 -> V_149 = NULL ;
goto V_96;
}
if ( ! V_10 -> V_69 . V_173 ) {
V_53 = F_110 ( V_33 , V_141 , V_105 , V_143 ) ;
goto V_96;
}
if ( V_143 -> V_97 == V_123 )
V_53 = F_96 ( V_33 , V_141 , V_170 ,
V_105 , V_143 ) ;
else if ( V_146 -> V_97 == V_123 )
V_53 = F_101 ( V_33 , V_141 , V_170 ,
V_105 , V_143 ) ;
else
V_53 = F_87 ( V_33 , V_141 , V_170 ,
V_105 , V_143 ) ;
if ( ! V_53 )
goto V_96;
V_53 = F_110 ( V_33 , V_141 , V_105 , V_143 ) ;
V_96:
if ( F_17 ( V_10 -> V_15 ) -> V_42 < V_43 ) {
if ( V_53 )
F_107 ( V_33 , NULL , & V_186 ) ;
else
F_107 ( V_33 , V_186 , & V_36 -> V_12 ) ;
}
return V_53 ;
}
static int
F_111 ( struct V_32 * V_33 , struct V_189 * V_38 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
return F_112 ( & V_36 -> V_37 . V_190 , V_38 ) ;
}
static int
F_113 ( struct V_112 * V_34 , struct V_142 * V_71 )
{
struct V_121 * V_122 = & V_34 -> V_122 [ V_71 -> V_97 ] ;
struct V_9 * V_10 = F_11 ( V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_53 ;
V_71 -> V_191 . V_5 = NULL ;
V_71 -> V_191 . V_151 = 0 ;
V_71 -> V_191 . V_6 = V_71 -> V_72 << V_73 ;
V_71 -> V_191 . V_58 = 0 ;
V_71 -> V_191 . V_107 = false ;
if ( ! ( V_122 -> V_8 & V_124 ) )
return - V_62 ;
switch ( V_71 -> V_97 ) {
case V_123 :
return 0 ;
case V_100 :
#if V_116
if ( V_10 -> V_117 . V_118 == V_119 ) {
V_71 -> V_191 . V_151 = V_71 -> V_164 << V_73 ;
V_71 -> V_191 . V_58 = V_10 -> V_117 . V_58 ;
V_71 -> V_191 . V_107 = ! V_2 -> V_117 -> V_192 ;
}
#endif
break;
case V_98 :
V_71 -> V_191 . V_151 = V_71 -> V_164 << V_73 ;
V_71 -> V_191 . V_58 = F_114 ( V_2 -> V_193 , 1 ) ;
V_71 -> V_191 . V_107 = true ;
if ( F_17 ( V_10 -> V_15 ) -> V_42 >= V_43 ) {
struct V_194 * V_195 = V_194 ( V_10 -> V_15 ) ;
struct V_147 * V_148 = V_71 -> V_149 ;
V_53 = V_195 -> V_196 ( V_195 , V_148 , V_169 ,
& V_148 -> V_197 ) ;
if ( V_53 )
return V_53 ;
V_71 -> V_191 . V_151 = V_148 -> V_197 . V_151 ;
}
break;
default:
return - V_62 ;
}
return 0 ;
}
static void
F_115 ( struct V_112 * V_34 , struct V_142 * V_71 )
{
struct V_9 * V_10 = F_11 ( V_34 ) ;
struct V_194 * V_195 = V_194 ( V_10 -> V_15 ) ;
struct V_147 * V_148 = V_71 -> V_149 ;
if ( ! V_148 -> V_197 . V_148 )
return;
V_195 -> V_198 ( V_195 , & V_148 -> V_197 ) ;
}
static int
F_116 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_41 * V_15 = F_17 ( V_10 -> V_15 ) ;
T_1 V_199 = F_117 ( V_15 -> V_193 , 1 ) >> V_73 ;
if ( V_33 -> V_71 . V_97 != V_98 ) {
if ( F_17 ( V_10 -> V_15 ) -> V_42 < V_43 ||
! F_78 ( V_36 ) )
return 0 ;
}
if ( V_33 -> V_71 . V_164 + V_33 -> V_71 . V_72 < V_199 )
return 0 ;
V_36 -> V_74 . V_84 = 0 ;
V_36 -> V_74 . V_85 = V_199 ;
F_24 ( V_36 , V_77 , 0 ) ;
return F_32 ( V_36 , false , false ) ;
}
static int
F_118 ( struct V_111 * V_69 )
{
struct V_200 * V_201 = ( void * ) V_69 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned V_11 ;
int V_202 ;
bool V_203 = ! ! ( V_69 -> V_113 & V_204 ) ;
if ( V_69 -> V_205 != V_206 )
return 0 ;
if ( V_203 && V_69 -> V_50 ) {
F_119 ( V_69 -> V_50 , V_69 -> V_207 ,
V_201 -> V_208 , V_69 -> V_72 ) ;
V_69 -> V_205 = V_209 ;
return 0 ;
}
V_10 = F_11 ( V_69 -> V_34 ) ;
V_2 = V_10 -> V_2 ;
#if V_116
if ( V_10 -> V_117 . V_118 == V_119 ) {
return F_120 ( V_69 ) ;
}
#endif
#ifdef F_121
if ( F_122 () ) {
return F_123 ( ( void * ) V_69 , V_2 -> V_2 ) ;
}
#endif
V_202 = F_124 ( V_69 ) ;
if ( V_202 ) {
return V_202 ;
}
for ( V_11 = 0 ; V_11 < V_69 -> V_72 ; V_11 ++ ) {
V_201 -> V_208 [ V_11 ] = F_125 ( V_2 -> V_193 , V_69 -> V_207 [ V_11 ] ,
0 , V_47 ,
V_210 ) ;
if ( F_126 ( V_2 -> V_193 , V_201 -> V_208 [ V_11 ] ) ) {
while ( -- V_11 ) {
F_127 ( V_2 -> V_193 , V_201 -> V_208 [ V_11 ] ,
V_47 , V_210 ) ;
V_201 -> V_208 [ V_11 ] = 0 ;
}
F_128 ( V_69 ) ;
return - V_211 ;
}
}
return 0 ;
}
static void
F_129 ( struct V_111 * V_69 )
{
struct V_200 * V_201 = ( void * ) V_69 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned V_11 ;
bool V_203 = ! ! ( V_69 -> V_113 & V_204 ) ;
if ( V_203 )
return;
V_10 = F_11 ( V_69 -> V_34 ) ;
V_2 = V_10 -> V_2 ;
#if V_116
if ( V_10 -> V_117 . V_118 == V_119 ) {
F_130 ( V_69 ) ;
return;
}
#endif
#ifdef F_121
if ( F_122 () ) {
F_131 ( ( void * ) V_69 , V_2 -> V_2 ) ;
return;
}
#endif
for ( V_11 = 0 ; V_11 < V_69 -> V_72 ; V_11 ++ ) {
if ( V_201 -> V_208 [ V_11 ] ) {
F_127 ( V_2 -> V_193 , V_201 -> V_208 [ V_11 ] ,
V_47 , V_210 ) ;
}
}
F_128 ( V_69 ) ;
}
void
F_132 ( struct V_35 * V_36 , struct V_29 * V_20 )
{
struct V_29 * V_212 = F_8 ( V_20 ) ;
struct V_29 * V_213 = NULL ;
F_4 ( & V_36 -> V_33 . V_34 -> V_214 ) ;
V_213 = V_36 -> V_33 . V_188 ;
V_36 -> V_33 . V_188 = V_212 ;
F_6 ( & V_36 -> V_33 . V_34 -> V_214 ) ;
F_2 ( & V_213 ) ;
}
static void
F_133 ( void * * V_188 )
{
F_2 ( (struct V_29 * * ) V_188 ) ;
}
static void *
F_134 ( void * V_188 )
{
return F_8 ( V_188 ) ;
}
static bool
F_135 ( void * V_188 )
{
return F_5 ( V_188 ) ;
}
static int
F_136 ( void * V_188 , bool V_215 , bool V_170 )
{
return F_137 ( V_188 , V_215 , V_170 ) ;
}
static int
F_138 ( void * V_188 )
{
return 0 ;
}
struct V_167 *
F_139 ( struct V_35 * V_36 , struct V_216 * V_59 )
{
struct V_167 * V_150 ;
F_103 (vma, &nvbo->vma_list, head) {
if ( V_150 -> V_59 == V_59 )
return V_150 ;
}
return NULL ;
}
int
F_140 ( struct V_35 * V_36 , struct V_216 * V_59 ,
struct V_167 * V_150 )
{
const T_1 V_6 = V_36 -> V_33 . V_71 . V_72 << V_73 ;
struct V_147 * V_148 = V_36 -> V_33 . V_71 . V_149 ;
int V_53 ;
V_53 = F_83 ( V_59 , V_6 , V_36 -> V_46 ,
V_169 , V_150 ) ;
if ( V_53 )
return V_53 ;
if ( V_36 -> V_33 . V_71 . V_97 == V_98 )
F_85 ( V_150 , V_36 -> V_33 . V_71 . V_149 ) ;
else if ( V_36 -> V_33 . V_71 . V_97 == V_100 &&
V_36 -> V_46 == V_150 -> V_59 -> V_60 -> V_185 ) {
if ( V_148 -> V_50 )
F_104 ( V_150 , 0 , V_6 , V_148 ) ;
else
F_86 ( V_150 , 0 , V_6 , V_148 ) ;
}
F_141 ( & V_150 -> V_66 , & V_36 -> V_68 ) ;
V_150 -> V_217 = 1 ;
return 0 ;
}
void
F_142 ( struct V_35 * V_36 , struct V_167 * V_150 )
{
if ( V_150 -> V_148 ) {
if ( V_36 -> V_33 . V_71 . V_97 != V_123 )
F_105 ( V_150 ) ;
F_143 ( V_150 ) ;
F_144 ( & V_150 -> V_66 ) ;
}
}
