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
V_36 -> V_47 = 12 ;
if ( V_10 -> V_60 . V_61 ) {
if ( ! ( V_8 & V_72 ) && V_6 > 256 * 1024 )
V_36 -> V_47 = V_10 -> V_60 . V_61 -> V_62 -> V_58 ;
}
F_17 ( V_36 , V_8 , & V_40 , & V_6 ) ;
V_36 -> V_33 . V_73 . V_74 = V_6 >> V_75 ;
F_24 ( V_36 , V_8 , 0 ) ;
V_55 = F_25 ( & V_10 -> V_71 . V_34 , V_6 ,
sizeof( struct V_35 ) ) ;
V_56 = F_26 ( & V_10 -> V_71 . V_34 , & V_36 -> V_33 , V_6 ,
type , & V_36 -> V_76 ,
V_40 >> V_75 , false , NULL , V_55 , V_51 ,
V_53 , F_11 ) ;
if ( V_56 ) {
return V_56 ;
}
* V_54 = V_36 ;
return 0 ;
}
static void
F_27 ( struct V_77 * V_78 , unsigned * V_79 , T_2 type , T_2 V_8 )
{
* V_79 = 0 ;
if ( type & V_80 )
V_78 [ ( * V_79 ) ++ ] . V_8 = V_80 | V_8 ;
if ( type & V_72 )
V_78 [ ( * V_79 ) ++ ] . V_8 = V_72 | V_8 ;
if ( type & V_81 )
V_78 [ ( * V_79 ) ++ ] . V_8 = V_81 | V_8 ;
}
static void
F_28 ( struct V_35 * V_36 , T_2 type )
{
struct V_9 * V_10 = F_12 ( V_36 -> V_33 . V_34 ) ;
T_1 V_82 = V_10 -> V_15 . V_42 . V_83 >> V_75 ;
unsigned V_11 , V_84 , V_85 ;
if ( V_10 -> V_15 . V_42 . V_43 == V_86 &&
V_36 -> V_45 && ( type & V_80 ) &&
V_36 -> V_33 . V_73 . V_74 < V_82 / 4 ) {
if ( V_36 -> V_49 & V_87 ) {
V_84 = V_82 / 2 ;
V_85 = ~ 0 ;
} else {
V_84 = 0 ;
V_85 = V_82 / 2 ;
}
for ( V_11 = 0 ; V_11 < V_36 -> V_76 . V_88 ; ++ V_11 ) {
V_36 -> V_89 [ V_11 ] . V_84 = V_84 ;
V_36 -> V_89 [ V_11 ] . V_85 = V_85 ;
}
for ( V_11 = 0 ; V_11 < V_36 -> V_76 . V_90 ; ++ V_11 ) {
V_36 -> V_91 [ V_11 ] . V_84 = V_84 ;
V_36 -> V_91 [ V_11 ] . V_85 = V_85 ;
}
}
}
void
F_24 ( struct V_35 * V_36 , T_2 type , T_2 V_92 )
{
struct V_93 * V_78 = & V_36 -> V_76 ;
T_2 V_8 = V_94 |
( V_36 -> V_39 ? V_95 : 0 ) ;
V_78 -> V_76 = V_36 -> V_89 ;
F_27 ( V_36 -> V_89 , & V_78 -> V_88 ,
type , V_8 ) ;
V_78 -> V_96 = V_36 -> V_91 ;
F_27 ( V_36 -> V_91 , & V_78 -> V_90 ,
type | V_92 , V_8 ) ;
F_28 ( V_36 , type ) ;
}
int
F_29 ( struct V_35 * V_36 , T_2 V_97 )
{
struct V_9 * V_10 = F_12 ( V_36 -> V_33 . V_34 ) ;
struct V_32 * V_33 = & V_36 -> V_33 ;
int V_56 ;
V_56 = F_30 ( V_33 , false , false , false , NULL ) ;
if ( V_56 )
goto V_98;
if ( V_36 -> V_39 && ! ( V_97 & ( 1 << V_33 -> V_73 . V_99 ) ) ) {
F_31 ( V_10 , L_3 , V_33 ,
1 << V_33 -> V_73 . V_99 , V_97 ) ;
V_56 = - V_64 ;
goto V_98;
}
if ( V_36 -> V_39 ++ )
goto V_98;
F_24 ( V_36 , V_97 , 0 ) ;
V_56 = F_32 ( V_36 , false , false ) ;
if ( V_56 == 0 ) {
switch ( V_33 -> V_73 . V_99 ) {
case V_100 :
V_10 -> V_37 . V_101 -= V_33 -> V_73 . V_6 ;
break;
case V_102 :
V_10 -> V_37 . V_103 -= V_33 -> V_73 . V_6 ;
break;
default:
break;
}
}
V_98:
F_33 ( V_33 ) ;
return V_56 ;
}
int
F_34 ( struct V_35 * V_36 )
{
struct V_9 * V_10 = F_12 ( V_36 -> V_33 . V_34 ) ;
struct V_32 * V_33 = & V_36 -> V_33 ;
int V_56 , V_104 ;
V_56 = F_30 ( V_33 , false , false , false , NULL ) ;
if ( V_56 )
return V_56 ;
V_104 = -- V_36 -> V_39 ;
F_35 ( V_104 < 0 ) ;
if ( V_104 )
goto V_98;
F_24 ( V_36 , V_33 -> V_73 . V_76 , 0 ) ;
V_56 = F_32 ( V_36 , false , false ) ;
if ( V_56 == 0 ) {
switch ( V_33 -> V_73 . V_99 ) {
case V_100 :
V_10 -> V_37 . V_101 += V_33 -> V_73 . V_6 ;
break;
case V_102 :
V_10 -> V_37 . V_103 += V_33 -> V_73 . V_6 ;
break;
default:
break;
}
}
V_98:
F_33 ( V_33 ) ;
return V_56 ;
}
int
F_36 ( struct V_35 * V_36 )
{
int V_56 ;
V_56 = F_30 ( & V_36 -> V_33 , false , false , false , NULL ) ;
if ( V_56 )
return V_56 ;
V_56 = F_37 ( & V_36 -> V_33 , 0 , V_36 -> V_33 . V_73 . V_74 , & V_36 -> V_105 ) ;
F_33 ( & V_36 -> V_33 ) ;
return V_56 ;
}
void
F_38 ( struct V_35 * V_36 )
{
if ( V_36 )
F_39 ( & V_36 -> V_105 ) ;
}
int
F_32 ( struct V_35 * V_36 , bool V_106 ,
bool V_107 )
{
int V_56 ;
V_56 = F_40 ( & V_36 -> V_33 , & V_36 -> V_76 ,
V_106 , V_107 ) ;
if ( V_56 )
return V_56 ;
return 0 ;
}
T_4
F_41 ( struct V_35 * V_36 , unsigned V_108 )
{
bool V_109 ;
T_4 * V_73 = F_42 ( & V_36 -> V_105 , & V_109 ) ;
V_73 = & V_73 [ V_108 ] ;
if ( V_109 )
return F_43 ( ( void V_110 V_111 * ) V_73 ) ;
else
return * V_73 ;
}
void
F_44 ( struct V_35 * V_36 , unsigned V_108 , T_4 V_112 )
{
bool V_109 ;
T_4 * V_73 = F_42 ( & V_36 -> V_105 , & V_109 ) ;
V_73 = & V_73 [ V_108 ] ;
if ( V_109 )
F_45 ( V_112 , ( void V_110 V_111 * ) V_73 ) ;
else
* V_73 = V_112 ;
}
T_1
F_46 ( struct V_35 * V_36 , unsigned V_108 )
{
bool V_109 ;
T_1 * V_73 = F_42 ( & V_36 -> V_105 , & V_109 ) ;
V_73 = & V_73 [ V_108 ] ;
if ( V_109 )
return F_47 ( ( void V_110 V_111 * ) V_73 ) ;
else
return * V_73 ;
}
void
F_48 ( struct V_35 * V_36 , unsigned V_108 , T_1 V_112 )
{
bool V_109 ;
T_1 * V_73 = F_42 ( & V_36 -> V_105 , & V_109 ) ;
V_73 = & V_73 [ V_108 ] ;
if ( V_109 )
F_49 ( V_112 , ( void V_110 V_111 * ) V_73 ) ;
else
* V_73 = V_112 ;
}
static struct V_113 *
F_50 ( struct V_114 * V_34 , unsigned long V_6 ,
T_2 V_115 , struct V_116 * V_117 )
{
#if V_118
struct V_9 * V_10 = F_12 ( V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_10 -> V_119 . V_120 == V_121 ) {
return F_51 ( V_34 , V_2 -> V_119 -> V_122 , V_6 ,
V_115 , V_117 ) ;
}
#endif
return F_52 ( V_34 , V_6 , V_115 , V_117 ) ;
}
static int
F_53 ( struct V_114 * V_34 , T_2 V_8 )
{
return 0 ;
}
static int
F_54 ( struct V_114 * V_34 , T_2 type ,
struct V_123 * V_124 )
{
struct V_9 * V_10 = F_12 ( V_34 ) ;
switch ( type ) {
case V_125 :
V_124 -> V_8 = V_126 ;
V_124 -> V_127 = V_94 ;
V_124 -> V_128 = V_129 ;
break;
case V_100 :
V_124 -> V_8 = V_130 |
V_126 ;
V_124 -> V_127 = V_131 |
V_132 ;
V_124 -> V_128 = V_132 ;
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 ) {
if ( F_55 ( & V_10 -> V_15 ) -> V_133 ) {
V_124 -> V_127 = V_131 ;
V_124 -> V_128 = V_131 ;
}
V_124 -> V_134 = & V_135 ;
V_124 -> V_136 = false ;
V_124 -> V_137 = true ;
} else {
V_124 -> V_134 = & V_138 ;
}
break;
case V_102 :
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 )
V_124 -> V_134 = & V_139 ;
else
if ( V_10 -> V_119 . V_120 != V_121 )
V_124 -> V_134 = & V_140 ;
else
V_124 -> V_134 = & V_138 ;
if ( V_10 -> V_119 . V_120 == V_121 ) {
V_124 -> V_8 = V_126 ;
V_124 -> V_127 = V_131 |
V_132 ;
V_124 -> V_128 = V_132 ;
} else {
V_124 -> V_8 = V_126 |
V_141 ;
V_124 -> V_127 = V_94 ;
V_124 -> V_128 = V_129 ;
}
break;
default:
return - V_64 ;
}
return 0 ;
}
static void
F_56 ( struct V_32 * V_33 , struct V_93 * V_78 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
switch ( V_33 -> V_73 . V_99 ) {
case V_100 :
F_24 ( V_36 , V_72 ,
V_81 ) ;
break;
default:
F_24 ( V_36 , V_81 , 0 ) ;
break;
}
* V_78 = V_36 -> V_76 ;
}
static int
F_57 ( struct V_142 * V_143 , T_1 V_144 )
{
int V_56 = F_58 ( V_143 , 2 ) ;
if ( V_56 == 0 ) {
F_59 ( V_143 , V_145 , 0x0000 , 1 ) ;
F_60 ( V_143 , V_144 & 0x0000ffff ) ;
F_61 ( V_143 ) ;
}
return V_56 ;
}
static int
F_62 ( struct V_142 * V_143 , struct V_32 * V_33 ,
struct V_146 * V_147 , struct V_146 * V_148 )
{
struct V_149 * V_150 = V_147 -> V_151 ;
int V_56 = F_58 ( V_143 , 10 ) ;
if ( V_56 == 0 ) {
F_59 ( V_143 , V_145 , 0x0400 , 8 ) ;
F_60 ( V_143 , F_63 ( V_150 -> V_152 [ 0 ] . V_153 ) ) ;
F_60 ( V_143 , F_64 ( V_150 -> V_152 [ 0 ] . V_153 ) ) ;
F_60 ( V_143 , F_63 ( V_150 -> V_152 [ 1 ] . V_153 ) ) ;
F_60 ( V_143 , F_64 ( V_150 -> V_152 [ 1 ] . V_153 ) ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_148 -> V_74 ) ;
F_65 ( V_143 , V_145 , 0x0300 , 0x0386 ) ;
}
return V_56 ;
}
static int
F_66 ( struct V_142 * V_143 , T_1 V_144 )
{
int V_56 = F_58 ( V_143 , 2 ) ;
if ( V_56 == 0 ) {
F_59 ( V_143 , V_145 , 0x0000 , 1 ) ;
F_60 ( V_143 , V_144 ) ;
}
return V_56 ;
}
static int
F_67 ( struct V_142 * V_143 , struct V_32 * V_33 ,
struct V_146 * V_147 , struct V_146 * V_148 )
{
struct V_149 * V_150 = V_147 -> V_151 ;
T_5 V_154 = V_150 -> V_152 [ 0 ] . V_153 ;
T_5 V_155 = V_150 -> V_152 [ 1 ] . V_153 ;
T_1 V_156 = V_148 -> V_74 ;
int V_56 ;
V_156 = V_148 -> V_74 ;
while ( V_156 ) {
int V_157 = ( V_156 > 8191 ) ? 8191 : V_156 ;
V_56 = F_58 ( V_143 , 11 ) ;
if ( V_56 )
return V_56 ;
F_59 ( V_143 , V_145 , 0x030c , 8 ) ;
F_60 ( V_143 , F_63 ( V_154 ) ) ;
F_60 ( V_143 , F_64 ( V_154 ) ) ;
F_60 ( V_143 , F_63 ( V_155 ) ) ;
F_60 ( V_143 , F_64 ( V_155 ) ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_157 ) ;
F_59 ( V_143 , V_145 , 0x0300 , 1 ) ;
F_60 ( V_143 , 0x00000110 ) ;
V_156 -= V_157 ;
V_154 += ( V_48 * V_157 ) ;
V_155 += ( V_48 * V_157 ) ;
}
return 0 ;
}
static int
F_68 ( struct V_142 * V_143 , struct V_32 * V_33 ,
struct V_146 * V_147 , struct V_146 * V_148 )
{
struct V_149 * V_150 = V_147 -> V_151 ;
T_5 V_154 = V_150 -> V_152 [ 0 ] . V_153 ;
T_5 V_155 = V_150 -> V_152 [ 1 ] . V_153 ;
T_1 V_156 = V_148 -> V_74 ;
int V_56 ;
V_156 = V_148 -> V_74 ;
while ( V_156 ) {
int V_157 = ( V_156 > 2047 ) ? 2047 : V_156 ;
V_56 = F_58 ( V_143 , 12 ) ;
if ( V_56 )
return V_56 ;
F_59 ( V_143 , V_145 , 0x0238 , 2 ) ;
F_60 ( V_143 , F_63 ( V_155 ) ) ;
F_60 ( V_143 , F_64 ( V_155 ) ) ;
F_59 ( V_143 , V_145 , 0x030c , 6 ) ;
F_60 ( V_143 , F_63 ( V_154 ) ) ;
F_60 ( V_143 , F_64 ( V_154 ) ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_157 ) ;
F_59 ( V_143 , V_145 , 0x0300 , 1 ) ;
F_60 ( V_143 , 0x00100110 ) ;
V_156 -= V_157 ;
V_154 += ( V_48 * V_157 ) ;
V_155 += ( V_48 * V_157 ) ;
}
return 0 ;
}
static int
F_69 ( struct V_142 * V_143 , struct V_32 * V_33 ,
struct V_146 * V_147 , struct V_146 * V_148 )
{
struct V_149 * V_150 = V_147 -> V_151 ;
T_5 V_154 = V_150 -> V_152 [ 0 ] . V_153 ;
T_5 V_155 = V_150 -> V_152 [ 1 ] . V_153 ;
T_1 V_156 = V_148 -> V_74 ;
int V_56 ;
V_156 = V_148 -> V_74 ;
while ( V_156 ) {
int V_157 = ( V_156 > 8191 ) ? 8191 : V_156 ;
V_56 = F_58 ( V_143 , 11 ) ;
if ( V_56 )
return V_56 ;
F_70 ( V_143 , V_145 , 0x030c , 8 ) ;
F_60 ( V_143 , F_63 ( V_154 ) ) ;
F_60 ( V_143 , F_64 ( V_154 ) ) ;
F_60 ( V_143 , F_63 ( V_155 ) ) ;
F_60 ( V_143 , F_64 ( V_155 ) ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_157 ) ;
F_70 ( V_143 , V_145 , 0x0300 , 1 ) ;
F_60 ( V_143 , 0x00000110 ) ;
V_156 -= V_157 ;
V_154 += ( V_48 * V_157 ) ;
V_155 += ( V_48 * V_157 ) ;
}
return 0 ;
}
static int
F_71 ( struct V_142 * V_143 , struct V_32 * V_33 ,
struct V_146 * V_147 , struct V_146 * V_148 )
{
struct V_149 * V_150 = V_147 -> V_151 ;
int V_56 = F_58 ( V_143 , 7 ) ;
if ( V_56 == 0 ) {
F_70 ( V_143 , V_145 , 0x0320 , 6 ) ;
F_60 ( V_143 , F_63 ( V_150 -> V_152 [ 0 ] . V_153 ) ) ;
F_60 ( V_143 , F_64 ( V_150 -> V_152 [ 0 ] . V_153 ) ) ;
F_60 ( V_143 , F_63 ( V_150 -> V_152 [ 1 ] . V_153 ) ) ;
F_60 ( V_143 , F_64 ( V_150 -> V_152 [ 1 ] . V_153 ) ) ;
F_60 ( V_143 , 0x00000000 ) ;
F_60 ( V_143 , V_148 -> V_74 << V_75 ) ;
}
return V_56 ;
}
static int
F_72 ( struct V_142 * V_143 , struct V_32 * V_33 ,
struct V_146 * V_147 , struct V_146 * V_148 )
{
struct V_149 * V_150 = V_147 -> V_151 ;
int V_56 = F_58 ( V_143 , 7 ) ;
if ( V_56 == 0 ) {
F_70 ( V_143 , V_145 , 0x0304 , 6 ) ;
F_60 ( V_143 , V_148 -> V_74 << V_75 ) ;
F_60 ( V_143 , F_63 ( V_150 -> V_152 [ 0 ] . V_153 ) ) ;
F_60 ( V_143 , F_64 ( V_150 -> V_152 [ 0 ] . V_153 ) ) ;
F_60 ( V_143 , F_63 ( V_150 -> V_152 [ 1 ] . V_153 ) ) ;
F_60 ( V_143 , F_64 ( V_150 -> V_152 [ 1 ] . V_153 ) ) ;
F_60 ( V_143 , 0x00000000 ) ;
}
return V_56 ;
}
static int
F_73 ( struct V_142 * V_143 , T_1 V_144 )
{
int V_56 = F_58 ( V_143 , 6 ) ;
if ( V_56 == 0 ) {
F_70 ( V_143 , V_145 , 0x0000 , 1 ) ;
F_60 ( V_143 , V_144 ) ;
F_70 ( V_143 , V_145 , 0x0180 , 3 ) ;
F_60 ( V_143 , V_143 -> V_10 -> V_158 . V_144 ) ;
F_60 ( V_143 , V_143 -> V_159 . V_144 ) ;
F_60 ( V_143 , V_143 -> V_159 . V_144 ) ;
}
return V_56 ;
}
static int
F_74 ( struct V_142 * V_143 , struct V_32 * V_33 ,
struct V_146 * V_147 , struct V_146 * V_148 )
{
struct V_149 * V_150 = V_147 -> V_151 ;
T_5 V_160 = ( V_148 -> V_74 << V_75 ) ;
T_5 V_154 = V_150 -> V_152 [ 0 ] . V_153 ;
T_5 V_155 = V_150 -> V_152 [ 1 ] . V_153 ;
int V_161 = ! ! V_150 -> V_97 ;
int V_162 = ! ! ( (struct V_149 * ) V_148 -> V_151 ) -> V_97 ;
int V_56 ;
while ( V_160 ) {
T_1 V_163 , V_164 , V_165 ;
V_56 = F_58 ( V_143 , 18 + 6 * ( V_161 + V_162 ) ) ;
if ( V_56 )
return V_56 ;
V_163 = F_75 ( V_160 , ( T_5 ) ( 4 * 1024 * 1024 ) ) ;
V_164 = 16 * 4 ;
V_165 = V_163 / V_164 ;
if ( V_161 ) {
F_70 ( V_143 , V_145 , 0x0200 , 7 ) ;
F_60 ( V_143 , 0 ) ;
F_60 ( V_143 , 0 ) ;
F_60 ( V_143 , V_164 ) ;
F_60 ( V_143 , V_165 ) ;
F_60 ( V_143 , 1 ) ;
F_60 ( V_143 , 0 ) ;
F_60 ( V_143 , 0 ) ;
} else {
F_70 ( V_143 , V_145 , 0x0200 , 1 ) ;
F_60 ( V_143 , 1 ) ;
}
if ( V_162 ) {
F_70 ( V_143 , V_145 , 0x021c , 7 ) ;
F_60 ( V_143 , 0 ) ;
F_60 ( V_143 , 0 ) ;
F_60 ( V_143 , V_164 ) ;
F_60 ( V_143 , V_165 ) ;
F_60 ( V_143 , 1 ) ;
F_60 ( V_143 , 0 ) ;
F_60 ( V_143 , 0 ) ;
} else {
F_70 ( V_143 , V_145 , 0x021c , 1 ) ;
F_60 ( V_143 , 1 ) ;
}
F_70 ( V_143 , V_145 , 0x0238 , 2 ) ;
F_60 ( V_143 , F_63 ( V_154 ) ) ;
F_60 ( V_143 , F_63 ( V_155 ) ) ;
F_70 ( V_143 , V_145 , 0x030c , 8 ) ;
F_60 ( V_143 , F_64 ( V_154 ) ) ;
F_60 ( V_143 , F_64 ( V_155 ) ) ;
F_60 ( V_143 , V_164 ) ;
F_60 ( V_143 , V_164 ) ;
F_60 ( V_143 , V_164 ) ;
F_60 ( V_143 , V_165 ) ;
F_60 ( V_143 , 0x00000101 ) ;
F_60 ( V_143 , 0x00000000 ) ;
F_70 ( V_143 , V_145 , V_166 , 1 ) ;
F_60 ( V_143 , 0 ) ;
V_160 -= V_163 ;
V_154 += V_163 ;
V_155 += V_163 ;
}
return 0 ;
}
static int
F_76 ( struct V_142 * V_143 , T_1 V_144 )
{
int V_56 = F_58 ( V_143 , 4 ) ;
if ( V_56 == 0 ) {
F_70 ( V_143 , V_145 , 0x0000 , 1 ) ;
F_60 ( V_143 , V_144 ) ;
F_70 ( V_143 , V_145 , 0x0180 , 1 ) ;
F_60 ( V_143 , V_143 -> V_10 -> V_158 . V_144 ) ;
}
return V_56 ;
}
static inline T_2
F_77 ( struct V_32 * V_33 ,
struct V_142 * V_143 , struct V_146 * V_73 )
{
if ( V_73 -> V_99 == V_102 )
return V_167 ;
return V_143 -> V_159 . V_144 ;
}
static int
F_78 ( struct V_142 * V_143 , struct V_32 * V_33 ,
struct V_146 * V_147 , struct V_146 * V_148 )
{
T_1 V_154 = V_147 -> V_168 << V_75 ;
T_1 V_155 = V_148 -> V_168 << V_75 ;
T_1 V_156 = V_148 -> V_74 ;
int V_56 ;
V_56 = F_58 ( V_143 , 3 ) ;
if ( V_56 )
return V_56 ;
F_70 ( V_143 , V_145 , V_169 , 2 ) ;
F_60 ( V_143 , F_77 ( V_33 , V_143 , V_147 ) ) ;
F_60 ( V_143 , F_77 ( V_33 , V_143 , V_148 ) ) ;
V_156 = V_148 -> V_74 ;
while ( V_156 ) {
int V_157 = ( V_156 > 2047 ) ? 2047 : V_156 ;
V_56 = F_58 ( V_143 , 11 ) ;
if ( V_56 )
return V_56 ;
F_70 ( V_143 , V_145 ,
V_170 , 8 ) ;
F_60 ( V_143 , V_154 ) ;
F_60 ( V_143 , V_155 ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_48 ) ;
F_60 ( V_143 , V_157 ) ;
F_60 ( V_143 , 0x00000101 ) ;
F_60 ( V_143 , 0x00000000 ) ;
F_70 ( V_143 , V_145 , V_166 , 1 ) ;
F_60 ( V_143 , 0 ) ;
V_156 -= V_157 ;
V_154 += ( V_48 * V_157 ) ;
V_155 += ( V_48 * V_157 ) ;
}
return 0 ;
}
static int
F_79 ( struct V_9 * V_10 , struct V_32 * V_33 ,
struct V_146 * V_73 )
{
struct V_149 * V_171 = V_33 -> V_73 . V_151 ;
struct V_149 * V_172 = V_73 -> V_151 ;
T_5 V_6 = ( T_5 ) V_73 -> V_74 << V_75 ;
int V_56 ;
V_56 = F_80 ( V_10 -> V_60 . V_61 , V_6 , V_171 -> V_47 ,
V_173 , & V_171 -> V_152 [ 0 ] ) ;
if ( V_56 )
return V_56 ;
V_56 = F_80 ( V_10 -> V_60 . V_61 , V_6 , V_172 -> V_47 ,
V_173 , & V_171 -> V_152 [ 1 ] ) ;
if ( V_56 ) {
F_81 ( & V_171 -> V_152 [ 0 ] ) ;
return V_56 ;
}
F_82 ( & V_171 -> V_152 [ 0 ] , V_171 ) ;
F_82 ( & V_171 -> V_152 [ 1 ] , V_172 ) ;
return 0 ;
}
static int
F_83 ( struct V_32 * V_33 , int V_174 , bool V_175 ,
bool V_107 , struct V_146 * V_148 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_142 * V_143 = V_10 -> V_71 . V_143 ;
struct V_176 * V_177 = ( void * ) F_84 ( & V_143 -> V_15 -> V_178 ) ;
struct V_29 * V_20 ;
int V_56 ;
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 ) {
V_56 = F_79 ( V_10 , V_33 , V_148 ) ;
if ( V_56 )
return V_56 ;
}
F_85 ( & V_177 -> V_179 , V_180 ) ;
V_56 = F_86 ( V_35 ( V_33 ) , V_143 , true , V_175 ) ;
if ( V_56 == 0 ) {
V_56 = V_10 -> V_71 . V_181 ( V_143 , V_33 , & V_33 -> V_73 , V_148 ) ;
if ( V_56 == 0 ) {
V_56 = F_87 ( V_143 , false , & V_20 ) ;
if ( V_56 == 0 ) {
V_56 = F_88 ( V_33 ,
& V_20 -> V_178 ,
V_174 ,
V_107 ,
V_148 ) ;
F_3 ( & V_20 ) ;
}
}
}
F_89 ( & V_177 -> V_179 ) ;
return V_56 ;
}
void
F_90 ( struct V_9 * V_10 )
{
static const struct {
const char * V_182 ;
int V_19 ;
T_1 V_183 ;
int (* F_91)( struct V_142 * ,
struct V_32 * ,
struct V_146 * , struct V_146 * );
int (* V_22)( struct V_142 * , T_1 V_144 );
} V_184 [] = {
{ L_4 , 4 , 0xa0b5 , F_62 , F_57 } ,
{ L_5 , 0 , 0xa0b5 , F_62 , F_66 } ,
{ L_6 , 5 , 0x90b8 , F_67 , F_66 } ,
{ L_7 , 4 , 0x90b5 , F_67 , F_66 } ,
{ L_4 , 0 , 0x85b5 , F_69 , F_73 } ,
{ L_8 , 0 , 0x74c1 , F_72 , F_73 } ,
{ L_9 , 0 , 0x9039 , F_68 , F_66 } ,
{ L_9 , 0 , 0x5039 , F_74 , F_73 } ,
{ L_9 , 0 , 0x0039 , F_78 , F_76 } ,
{} ,
{ L_8 , 0 , 0x88b4 , F_71 , F_73 } ,
} , * V_185 = V_184 ;
const char * V_182 = L_10 ;
int V_56 ;
do {
struct V_142 * V_143 ;
if ( V_185 -> V_19 )
V_143 = V_10 -> V_186 ;
else
V_143 = V_10 -> V_187 ;
if ( V_143 == NULL )
continue;
V_56 = F_92 ( V_143 -> V_188 , NULL ,
V_185 -> V_183 | ( V_185 -> V_19 << 16 ) ,
V_185 -> V_183 , NULL , 0 ,
& V_10 -> V_71 . V_189 ) ;
if ( V_56 == 0 ) {
V_56 = V_185 -> V_22 ( V_143 , V_10 -> V_71 . V_189 . V_144 ) ;
if ( V_56 ) {
F_93 ( & V_10 -> V_71 . V_189 ) ;
continue;
}
V_10 -> V_71 . V_181 = V_185 -> F_91 ;
V_10 -> V_71 . V_143 = V_143 ;
V_182 = V_185 -> V_182 ;
break;
}
} while ( ( ++ V_185 ) -> F_91 );
F_94 ( V_10 , L_11 , V_182 ) ;
}
static int
F_95 ( struct V_32 * V_33 , bool V_174 , bool V_175 ,
bool V_107 , struct V_146 * V_148 )
{
struct V_77 V_190 = {
. V_84 = 0 ,
. V_85 = 0 ,
. V_8 = V_72 | V_94
} ;
struct V_93 V_76 ;
struct V_146 V_191 ;
int V_56 ;
V_76 . V_88 = V_76 . V_90 = 1 ;
V_76 . V_76 = V_76 . V_96 = & V_190 ;
V_191 = * V_148 ;
V_191 . V_151 = NULL ;
V_56 = F_96 ( V_33 , & V_76 , & V_191 , V_175 , V_107 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_97 ( V_33 -> V_71 , & V_191 ) ;
if ( V_56 )
goto V_98;
V_56 = F_83 ( V_33 , true , V_175 , V_107 , & V_191 ) ;
if ( V_56 )
goto V_98;
V_56 = F_98 ( V_33 , true , V_107 , V_148 ) ;
V_98:
F_99 ( V_33 , & V_191 ) ;
return V_56 ;
}
static int
F_100 ( struct V_32 * V_33 , bool V_174 , bool V_175 ,
bool V_107 , struct V_146 * V_148 )
{
struct V_77 V_190 = {
. V_84 = 0 ,
. V_85 = 0 ,
. V_8 = V_72 | V_94
} ;
struct V_93 V_76 ;
struct V_146 V_191 ;
int V_56 ;
V_76 . V_88 = V_76 . V_90 = 1 ;
V_76 . V_76 = V_76 . V_96 = & V_190 ;
V_191 = * V_148 ;
V_191 . V_151 = NULL ;
V_56 = F_96 ( V_33 , & V_76 , & V_191 , V_175 , V_107 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_98 ( V_33 , true , V_107 , & V_191 ) ;
if ( V_56 )
goto V_98;
V_56 = F_83 ( V_33 , true , V_175 , V_107 , V_148 ) ;
if ( V_56 )
goto V_98;
V_98:
F_99 ( V_33 , & V_191 ) ;
return V_56 ;
}
static void
F_101 ( struct V_32 * V_33 , struct V_146 * V_148 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_192 * V_152 ;
if ( V_33 -> V_193 != F_11 )
return;
F_102 (vma, &nvbo->vma_list, head) {
if ( V_148 && V_148 -> V_99 != V_125 &&
( V_148 -> V_99 == V_100 ||
V_36 -> V_47 != V_152 -> V_61 -> V_62 -> V_58 ) ) {
F_82 ( V_152 , V_148 -> V_151 ) ;
} else {
F_103 ( V_152 ) ;
}
}
}
static int
F_104 ( struct V_32 * V_33 , struct V_146 * V_148 ,
struct V_3 * * V_194 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
T_5 V_153 = V_148 -> V_168 << V_75 ;
* V_194 = NULL ;
if ( V_148 -> V_99 != V_100 )
return 0 ;
if ( V_10 -> V_15 . V_42 . V_43 >= V_86 ) {
* V_194 = F_10 ( V_2 , V_153 , V_148 -> V_6 ,
V_36 -> V_45 ,
V_36 -> V_49 ) ;
}
return 0 ;
}
static void
F_105 ( struct V_32 * V_33 ,
struct V_3 * V_194 ,
struct V_3 * * V_195 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_20 * V_20 = F_106 ( V_33 -> V_196 ) ;
F_8 ( V_2 , * V_195 , V_20 ) ;
* V_195 = V_194 ;
}
static int
F_107 ( struct V_32 * V_33 , bool V_174 , bool V_175 ,
bool V_107 , struct V_146 * V_148 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_146 * V_147 = & V_33 -> V_73 ;
struct V_3 * V_194 = NULL ;
int V_56 = 0 ;
if ( V_10 -> V_15 . V_42 . V_43 < V_44 ) {
V_56 = F_104 ( V_33 , V_148 , & V_194 ) ;
if ( V_56 )
return V_56 ;
}
if ( V_147 -> V_99 == V_125 && ! V_33 -> V_71 ) {
F_108 ( V_33 -> V_73 . V_151 != NULL ) ;
V_33 -> V_73 = * V_148 ;
V_148 -> V_151 = NULL ;
goto V_98;
}
if ( V_10 -> V_71 . V_181 ) {
if ( V_148 -> V_99 == V_125 )
V_56 = F_95 ( V_33 , V_174 , V_175 ,
V_107 , V_148 ) ;
else if ( V_147 -> V_99 == V_125 )
V_56 = F_100 ( V_33 , V_174 , V_175 ,
V_107 , V_148 ) ;
else
V_56 = F_83 ( V_33 , V_174 , V_175 ,
V_107 , V_148 ) ;
if ( ! V_56 )
goto V_98;
}
V_56 = F_109 ( V_33 , true , V_175 , V_107 ) ;
if ( V_56 == 0 )
V_56 = F_110 ( V_33 , V_174 , V_107 , V_148 ) ;
V_98:
if ( V_10 -> V_15 . V_42 . V_43 < V_44 ) {
if ( V_56 )
F_105 ( V_33 , NULL , & V_194 ) ;
else
F_105 ( V_33 , V_194 , & V_36 -> V_12 ) ;
}
return V_56 ;
}
static int
F_111 ( struct V_32 * V_33 , struct V_197 * V_38 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
return F_112 ( & V_36 -> V_37 . V_198 , V_38 ) ;
}
static int
F_113 ( struct V_114 * V_34 , struct V_146 * V_73 )
{
struct V_123 * V_124 = & V_34 -> V_124 [ V_73 -> V_99 ] ;
struct V_9 * V_10 = F_12 ( V_34 ) ;
struct V_149 * V_150 = V_73 -> V_151 ;
int V_56 ;
V_73 -> V_199 . V_5 = NULL ;
V_73 -> V_199 . V_153 = 0 ;
V_73 -> V_199 . V_6 = V_73 -> V_74 << V_75 ;
V_73 -> V_199 . V_178 = 0 ;
V_73 -> V_199 . V_109 = false ;
if ( ! ( V_124 -> V_8 & V_126 ) )
return - V_64 ;
switch ( V_73 -> V_99 ) {
case V_125 :
return 0 ;
case V_102 :
#if V_118
if ( V_10 -> V_119 . V_120 == V_121 ) {
V_73 -> V_199 . V_153 = V_73 -> V_168 << V_75 ;
V_73 -> V_199 . V_178 = V_10 -> V_119 . V_178 ;
V_73 -> V_199 . V_109 = ! V_10 -> V_2 -> V_119 -> V_200 ;
}
#endif
if ( V_10 -> V_15 . V_42 . V_43 < V_44 || ! V_150 -> V_97 )
break;
case V_100 :
V_73 -> V_199 . V_153 = V_73 -> V_168 << V_75 ;
V_73 -> V_199 . V_178 = F_114 ( F_115 ( & V_10 -> V_15 ) , 1 ) ;
V_73 -> V_199 . V_109 = true ;
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 ) {
struct V_201 * V_202 = F_55 ( & V_10 -> V_15 ) ;
V_56 = V_202 -> V_203 ( V_202 , V_150 , V_173 ,
& V_150 -> V_204 ) ;
if ( V_56 )
return V_56 ;
V_73 -> V_199 . V_153 = V_150 -> V_204 . V_153 ;
}
break;
default:
return - V_64 ;
}
return 0 ;
}
static void
F_116 ( struct V_114 * V_34 , struct V_146 * V_73 )
{
struct V_9 * V_10 = F_12 ( V_34 ) ;
struct V_201 * V_202 = F_55 ( & V_10 -> V_15 ) ;
struct V_149 * V_150 = V_73 -> V_151 ;
if ( ! V_150 -> V_204 . V_150 )
return;
V_202 -> V_205 ( V_202 , & V_150 -> V_204 ) ;
}
static int
F_117 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_41 * V_15 = & V_10 -> V_15 ;
T_1 V_206 = F_118 ( F_115 ( V_15 ) , 1 ) >> V_75 ;
int V_11 , V_56 ;
if ( V_33 -> V_73 . V_99 != V_100 ) {
if ( V_10 -> V_15 . V_42 . V_43 < V_44 ||
! F_119 ( V_36 ) )
return 0 ;
if ( V_33 -> V_73 . V_99 == V_125 ) {
F_24 ( V_36 , V_102 , 0 ) ;
V_56 = F_32 ( V_36 , false , false ) ;
if ( V_56 )
return V_56 ;
}
return 0 ;
}
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 ||
V_33 -> V_73 . V_168 + V_33 -> V_73 . V_74 < V_206 )
return 0 ;
for ( V_11 = 0 ; V_11 < V_36 -> V_76 . V_88 ; ++ V_11 ) {
V_36 -> V_89 [ V_11 ] . V_84 = 0 ;
V_36 -> V_89 [ V_11 ] . V_85 = V_206 ;
}
for ( V_11 = 0 ; V_11 < V_36 -> V_76 . V_90 ; ++ V_11 ) {
V_36 -> V_91 [ V_11 ] . V_84 = 0 ;
V_36 -> V_91 [ V_11 ] . V_85 = V_206 ;
}
F_24 ( V_36 , V_80 , 0 ) ;
return F_32 ( V_36 , false , false ) ;
}
static int
F_120 ( struct V_113 * V_71 )
{
struct V_207 * V_208 = ( void * ) V_71 ;
struct V_9 * V_10 ;
struct V_209 * V_15 ;
struct V_1 * V_2 ;
struct V_15 * V_210 ;
unsigned V_11 ;
int V_211 ;
bool V_212 = ! ! ( V_71 -> V_115 & V_213 ) ;
if ( V_71 -> V_214 != V_215 )
return 0 ;
if ( V_212 && V_71 -> V_51 ) {
F_121 ( V_71 -> V_51 , V_71 -> V_216 ,
V_208 -> V_217 , V_71 -> V_74 ) ;
V_71 -> V_214 = V_218 ;
return 0 ;
}
V_10 = F_12 ( V_71 -> V_34 ) ;
V_15 = F_115 ( & V_10 -> V_15 ) ;
V_2 = V_10 -> V_2 ;
V_210 = F_122 ( V_15 ) ;
#if V_118
if ( V_10 -> V_119 . V_120 == V_121 ) {
return F_123 ( V_71 ) ;
}
#endif
#ifdef F_124
if ( F_125 () ) {
return F_126 ( ( void * ) V_71 , V_2 -> V_2 ) ;
}
#endif
V_211 = F_127 ( V_71 ) ;
if ( V_211 ) {
return V_211 ;
}
for ( V_11 = 0 ; V_11 < V_71 -> V_74 ; V_11 ++ ) {
T_6 V_5 ;
V_5 = F_128 ( V_210 , V_71 -> V_216 [ V_11 ] , 0 , V_48 ,
V_219 ) ;
if ( F_129 ( V_210 , V_5 ) ) {
while ( -- V_11 ) {
F_130 ( V_210 , V_208 -> V_217 [ V_11 ] ,
V_48 , V_219 ) ;
V_208 -> V_217 [ V_11 ] = 0 ;
}
F_131 ( V_71 ) ;
return - V_220 ;
}
V_208 -> V_217 [ V_11 ] = V_5 ;
}
return 0 ;
}
static void
F_132 ( struct V_113 * V_71 )
{
struct V_207 * V_208 = ( void * ) V_71 ;
struct V_9 * V_10 ;
struct V_209 * V_15 ;
struct V_1 * V_2 ;
struct V_15 * V_210 ;
unsigned V_11 ;
bool V_212 = ! ! ( V_71 -> V_115 & V_213 ) ;
if ( V_212 )
return;
V_10 = F_12 ( V_71 -> V_34 ) ;
V_15 = F_115 ( & V_10 -> V_15 ) ;
V_2 = V_10 -> V_2 ;
V_210 = F_122 ( V_15 ) ;
#if V_118
if ( V_10 -> V_119 . V_120 == V_121 ) {
F_133 ( V_71 ) ;
return;
}
#endif
#ifdef F_124
if ( F_125 () ) {
F_134 ( ( void * ) V_71 , V_2 -> V_2 ) ;
return;
}
#endif
for ( V_11 = 0 ; V_11 < V_71 -> V_74 ; V_11 ++ ) {
if ( V_208 -> V_217 [ V_11 ] ) {
F_130 ( V_210 , V_208 -> V_217 [ V_11 ] , V_48 ,
V_219 ) ;
}
}
F_131 ( V_71 ) ;
}
void
F_135 ( struct V_35 * V_36 , struct V_29 * V_20 , bool V_221 )
{
struct V_52 * V_196 = V_36 -> V_33 . V_196 ;
if ( V_221 )
F_136 ( V_196 , & V_20 -> V_178 ) ;
else if ( V_20 )
F_137 ( V_196 , & V_20 -> V_178 ) ;
}
struct V_192 *
F_138 ( struct V_35 * V_36 , struct V_222 * V_61 )
{
struct V_192 * V_152 ;
F_102 (vma, &nvbo->vma_list, head) {
if ( V_152 -> V_61 == V_61 )
return V_152 ;
}
return NULL ;
}
int
F_139 ( struct V_35 * V_36 , struct V_222 * V_61 ,
struct V_192 * V_152 )
{
const T_1 V_6 = V_36 -> V_33 . V_73 . V_74 << V_75 ;
int V_56 ;
V_56 = F_80 ( V_61 , V_6 , V_36 -> V_47 ,
V_173 , V_152 ) ;
if ( V_56 )
return V_56 ;
if ( V_36 -> V_33 . V_73 . V_99 != V_125 &&
( V_36 -> V_33 . V_73 . V_99 == V_100 ||
V_36 -> V_47 != V_152 -> V_61 -> V_62 -> V_58 ) )
F_82 ( V_152 , V_36 -> V_33 . V_73 . V_151 ) ;
F_140 ( & V_152 -> V_68 , & V_36 -> V_70 ) ;
V_152 -> V_223 = 1 ;
return 0 ;
}
void
F_141 ( struct V_35 * V_36 , struct V_192 * V_152 )
{
if ( V_152 -> V_150 ) {
if ( V_36 -> V_33 . V_73 . V_99 != V_125 )
F_103 ( V_152 ) ;
F_81 ( V_152 ) ;
F_142 ( & V_152 -> V_68 ) ;
}
}
