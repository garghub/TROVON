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
F_56 ( struct V_139 * V_140 , T_1 V_141 )
{
int V_53 = F_57 ( V_140 , 2 ) ;
if ( V_53 == 0 ) {
F_58 ( V_140 , V_142 , 0x0000 , 1 ) ;
F_59 ( V_140 , V_141 & 0x0000ffff ) ;
F_60 ( V_140 ) ;
}
return V_53 ;
}
static int
F_61 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
struct V_146 * V_147 = V_144 -> V_148 ;
int V_53 = F_57 ( V_140 , 10 ) ;
if ( V_53 == 0 ) {
F_58 ( V_140 , V_142 , 0x0400 , 8 ) ;
F_59 ( V_140 , F_62 ( V_147 -> V_149 [ 0 ] . V_150 ) ) ;
F_59 ( V_140 , F_63 ( V_147 -> V_149 [ 0 ] . V_150 ) ) ;
F_59 ( V_140 , F_62 ( V_147 -> V_149 [ 1 ] . V_150 ) ) ;
F_59 ( V_140 , F_63 ( V_147 -> V_149 [ 1 ] . V_150 ) ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_145 -> V_72 ) ;
F_64 ( V_140 , V_142 , 0x0300 , 0x0386 ) ;
}
return V_53 ;
}
static int
F_65 ( struct V_139 * V_140 , T_1 V_141 )
{
int V_53 = F_57 ( V_140 , 2 ) ;
if ( V_53 == 0 ) {
F_58 ( V_140 , V_142 , 0x0000 , 1 ) ;
F_59 ( V_140 , V_141 ) ;
}
return V_53 ;
}
static int
F_66 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
struct V_146 * V_147 = V_144 -> V_148 ;
T_5 V_151 = V_147 -> V_149 [ 0 ] . V_150 ;
T_5 V_152 = V_147 -> V_149 [ 1 ] . V_150 ;
T_1 V_153 = V_145 -> V_72 ;
int V_53 ;
V_153 = V_145 -> V_72 ;
while ( V_153 ) {
int V_154 = ( V_153 > 8191 ) ? 8191 : V_153 ;
V_53 = F_57 ( V_140 , 11 ) ;
if ( V_53 )
return V_53 ;
F_58 ( V_140 , V_142 , 0x030c , 8 ) ;
F_59 ( V_140 , F_62 ( V_151 ) ) ;
F_59 ( V_140 , F_63 ( V_151 ) ) ;
F_59 ( V_140 , F_62 ( V_152 ) ) ;
F_59 ( V_140 , F_63 ( V_152 ) ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_154 ) ;
F_58 ( V_140 , V_142 , 0x0300 , 1 ) ;
F_59 ( V_140 , 0x00000110 ) ;
V_153 -= V_154 ;
V_151 += ( V_47 * V_154 ) ;
V_152 += ( V_47 * V_154 ) ;
}
return 0 ;
}
static int
F_67 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
struct V_146 * V_147 = V_144 -> V_148 ;
T_5 V_151 = V_147 -> V_149 [ 0 ] . V_150 ;
T_5 V_152 = V_147 -> V_149 [ 1 ] . V_150 ;
T_1 V_153 = V_145 -> V_72 ;
int V_53 ;
V_153 = V_145 -> V_72 ;
while ( V_153 ) {
int V_154 = ( V_153 > 2047 ) ? 2047 : V_153 ;
V_53 = F_57 ( V_140 , 12 ) ;
if ( V_53 )
return V_53 ;
F_58 ( V_140 , V_142 , 0x0238 , 2 ) ;
F_59 ( V_140 , F_62 ( V_152 ) ) ;
F_59 ( V_140 , F_63 ( V_152 ) ) ;
F_58 ( V_140 , V_142 , 0x030c , 6 ) ;
F_59 ( V_140 , F_62 ( V_151 ) ) ;
F_59 ( V_140 , F_63 ( V_151 ) ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_154 ) ;
F_58 ( V_140 , V_142 , 0x0300 , 1 ) ;
F_59 ( V_140 , 0x00100110 ) ;
V_153 -= V_154 ;
V_151 += ( V_47 * V_154 ) ;
V_152 += ( V_47 * V_154 ) ;
}
return 0 ;
}
static int
F_68 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
struct V_146 * V_147 = V_144 -> V_148 ;
T_5 V_151 = V_147 -> V_149 [ 0 ] . V_150 ;
T_5 V_152 = V_147 -> V_149 [ 1 ] . V_150 ;
T_1 V_153 = V_145 -> V_72 ;
int V_53 ;
V_153 = V_145 -> V_72 ;
while ( V_153 ) {
int V_154 = ( V_153 > 8191 ) ? 8191 : V_153 ;
V_53 = F_57 ( V_140 , 11 ) ;
if ( V_53 )
return V_53 ;
F_69 ( V_140 , V_142 , 0x030c , 8 ) ;
F_59 ( V_140 , F_62 ( V_151 ) ) ;
F_59 ( V_140 , F_63 ( V_151 ) ) ;
F_59 ( V_140 , F_62 ( V_152 ) ) ;
F_59 ( V_140 , F_63 ( V_152 ) ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_154 ) ;
F_69 ( V_140 , V_142 , 0x0300 , 1 ) ;
F_59 ( V_140 , 0x00000110 ) ;
V_153 -= V_154 ;
V_151 += ( V_47 * V_154 ) ;
V_152 += ( V_47 * V_154 ) ;
}
return 0 ;
}
static int
F_70 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
struct V_146 * V_147 = V_144 -> V_148 ;
int V_53 = F_57 ( V_140 , 7 ) ;
if ( V_53 == 0 ) {
F_69 ( V_140 , V_142 , 0x0320 , 6 ) ;
F_59 ( V_140 , F_62 ( V_147 -> V_149 [ 0 ] . V_150 ) ) ;
F_59 ( V_140 , F_63 ( V_147 -> V_149 [ 0 ] . V_150 ) ) ;
F_59 ( V_140 , F_62 ( V_147 -> V_149 [ 1 ] . V_150 ) ) ;
F_59 ( V_140 , F_63 ( V_147 -> V_149 [ 1 ] . V_150 ) ) ;
F_59 ( V_140 , 0x00000000 ) ;
F_59 ( V_140 , V_145 -> V_72 << V_73 ) ;
}
return V_53 ;
}
static int
F_71 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
struct V_146 * V_147 = V_144 -> V_148 ;
int V_53 = F_57 ( V_140 , 7 ) ;
if ( V_53 == 0 ) {
F_69 ( V_140 , V_142 , 0x0304 , 6 ) ;
F_59 ( V_140 , V_145 -> V_72 << V_73 ) ;
F_59 ( V_140 , F_62 ( V_147 -> V_149 [ 0 ] . V_150 ) ) ;
F_59 ( V_140 , F_63 ( V_147 -> V_149 [ 0 ] . V_150 ) ) ;
F_59 ( V_140 , F_62 ( V_147 -> V_149 [ 1 ] . V_150 ) ) ;
F_59 ( V_140 , F_63 ( V_147 -> V_149 [ 1 ] . V_150 ) ) ;
F_59 ( V_140 , 0x00000000 ) ;
}
return V_53 ;
}
static int
F_72 ( struct V_139 * V_140 , T_1 V_141 )
{
int V_53 = F_57 ( V_140 , 6 ) ;
if ( V_53 == 0 ) {
F_69 ( V_140 , V_142 , 0x0000 , 1 ) ;
F_59 ( V_140 , V_141 ) ;
F_69 ( V_140 , V_142 , 0x0180 , 3 ) ;
F_59 ( V_140 , V_155 ) ;
F_59 ( V_140 , V_156 ) ;
F_59 ( V_140 , V_156 ) ;
}
return V_53 ;
}
static int
F_73 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
struct V_146 * V_147 = V_144 -> V_148 ;
T_5 V_157 = ( V_145 -> V_72 << V_73 ) ;
T_5 V_151 = V_147 -> V_149 [ 0 ] . V_150 ;
T_5 V_152 = V_147 -> V_149 [ 1 ] . V_150 ;
int V_158 = ! ! V_147 -> V_95 ;
int V_159 = ! ! ( (struct V_146 * ) V_145 -> V_148 ) -> V_95 ;
int V_53 ;
while ( V_157 ) {
T_1 V_160 , V_161 , V_162 ;
V_53 = F_57 ( V_140 , 18 + 6 * ( V_158 + V_159 ) ) ;
if ( V_53 )
return V_53 ;
V_160 = F_74 ( V_157 , ( T_5 ) ( 4 * 1024 * 1024 ) ) ;
V_161 = 16 * 4 ;
V_162 = V_160 / V_161 ;
if ( V_158 ) {
F_69 ( V_140 , V_142 , 0x0200 , 7 ) ;
F_59 ( V_140 , 0 ) ;
F_59 ( V_140 , 0 ) ;
F_59 ( V_140 , V_161 ) ;
F_59 ( V_140 , V_162 ) ;
F_59 ( V_140 , 1 ) ;
F_59 ( V_140 , 0 ) ;
F_59 ( V_140 , 0 ) ;
} else {
F_69 ( V_140 , V_142 , 0x0200 , 1 ) ;
F_59 ( V_140 , 1 ) ;
}
if ( V_159 ) {
F_69 ( V_140 , V_142 , 0x021c , 7 ) ;
F_59 ( V_140 , 0 ) ;
F_59 ( V_140 , 0 ) ;
F_59 ( V_140 , V_161 ) ;
F_59 ( V_140 , V_162 ) ;
F_59 ( V_140 , 1 ) ;
F_59 ( V_140 , 0 ) ;
F_59 ( V_140 , 0 ) ;
} else {
F_69 ( V_140 , V_142 , 0x021c , 1 ) ;
F_59 ( V_140 , 1 ) ;
}
F_69 ( V_140 , V_142 , 0x0238 , 2 ) ;
F_59 ( V_140 , F_62 ( V_151 ) ) ;
F_59 ( V_140 , F_62 ( V_152 ) ) ;
F_69 ( V_140 , V_142 , 0x030c , 8 ) ;
F_59 ( V_140 , F_63 ( V_151 ) ) ;
F_59 ( V_140 , F_63 ( V_152 ) ) ;
F_59 ( V_140 , V_161 ) ;
F_59 ( V_140 , V_161 ) ;
F_59 ( V_140 , V_161 ) ;
F_59 ( V_140 , V_162 ) ;
F_59 ( V_140 , 0x00000101 ) ;
F_59 ( V_140 , 0x00000000 ) ;
F_69 ( V_140 , V_142 , V_163 , 1 ) ;
F_59 ( V_140 , 0 ) ;
V_157 -= V_160 ;
V_151 += V_160 ;
V_152 += V_160 ;
}
return 0 ;
}
static int
F_75 ( struct V_139 * V_140 , T_1 V_141 )
{
int V_53 = F_57 ( V_140 , 4 ) ;
if ( V_53 == 0 ) {
F_69 ( V_140 , V_142 , 0x0000 , 1 ) ;
F_59 ( V_140 , V_141 ) ;
F_69 ( V_140 , V_142 , 0x0180 , 1 ) ;
F_59 ( V_140 , V_155 ) ;
}
return V_53 ;
}
static inline T_2
F_76 ( struct V_32 * V_33 ,
struct V_139 * V_140 , struct V_143 * V_71 )
{
if ( V_71 -> V_97 == V_100 )
return V_164 ;
return V_156 ;
}
static int
F_77 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
T_1 V_151 = V_144 -> V_165 << V_73 ;
T_1 V_152 = V_145 -> V_165 << V_73 ;
T_1 V_153 = V_145 -> V_72 ;
int V_53 ;
V_53 = F_57 ( V_140 , 3 ) ;
if ( V_53 )
return V_53 ;
F_69 ( V_140 , V_142 , V_166 , 2 ) ;
F_59 ( V_140 , F_76 ( V_33 , V_140 , V_144 ) ) ;
F_59 ( V_140 , F_76 ( V_33 , V_140 , V_145 ) ) ;
V_153 = V_145 -> V_72 ;
while ( V_153 ) {
int V_154 = ( V_153 > 2047 ) ? 2047 : V_153 ;
V_53 = F_57 ( V_140 , 11 ) ;
if ( V_53 )
return V_53 ;
F_69 ( V_140 , V_142 ,
V_167 , 8 ) ;
F_59 ( V_140 , V_151 ) ;
F_59 ( V_140 , V_152 ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_47 ) ;
F_59 ( V_140 , V_154 ) ;
F_59 ( V_140 , 0x00000101 ) ;
F_59 ( V_140 , 0x00000000 ) ;
F_69 ( V_140 , V_142 , V_163 , 1 ) ;
F_59 ( V_140 , 0 ) ;
V_153 -= V_154 ;
V_151 += ( V_47 * V_154 ) ;
V_152 += ( V_47 * V_154 ) ;
}
return 0 ;
}
static int
F_78 ( struct V_9 * V_10 , struct V_32 * V_33 ,
struct V_143 * V_71 )
{
struct V_146 * V_168 = V_33 -> V_71 . V_148 ;
struct V_146 * V_169 = V_71 -> V_148 ;
T_5 V_6 = ( T_5 ) V_71 -> V_72 << V_73 ;
int V_53 ;
V_53 = F_79 ( F_80 ( V_10 ) -> V_59 , V_6 , V_168 -> V_46 ,
V_170 , & V_168 -> V_149 [ 0 ] ) ;
if ( V_53 )
return V_53 ;
V_53 = F_79 ( F_80 ( V_10 ) -> V_59 , V_6 , V_169 -> V_46 ,
V_170 , & V_168 -> V_149 [ 1 ] ) ;
if ( V_53 ) {
F_81 ( & V_168 -> V_149 [ 0 ] ) ;
return V_53 ;
}
F_82 ( & V_168 -> V_149 [ 0 ] , V_168 ) ;
F_82 ( & V_168 -> V_149 [ 1 ] , V_169 ) ;
return 0 ;
}
static int
F_83 ( struct V_32 * V_33 , int V_171 , bool V_172 ,
bool V_105 , struct V_143 * V_145 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_139 * V_140 = V_10 -> V_69 . V_140 ;
struct V_29 * V_20 ;
int V_53 ;
if ( F_17 ( V_10 -> V_15 ) -> V_42 >= V_43 ) {
V_53 = F_78 ( V_10 , V_33 , V_145 ) ;
if ( V_53 )
return V_53 ;
}
F_84 ( & V_140 -> V_173 -> V_174 , V_175 ) ;
V_53 = F_85 ( V_33 -> V_176 , V_140 ) ;
if ( V_53 == 0 ) {
V_53 = V_10 -> V_69 . V_177 ( V_140 , V_33 , & V_33 -> V_71 , V_145 ) ;
if ( V_53 == 0 ) {
V_53 = F_86 ( V_140 , false , & V_20 ) ;
if ( V_53 == 0 ) {
V_53 = F_87 ( V_33 , V_20 ,
V_171 ,
V_105 ,
V_145 ) ;
F_2 ( & V_20 ) ;
}
}
}
F_88 ( & V_140 -> V_173 -> V_174 ) ;
return V_53 ;
}
void
F_89 ( struct V_9 * V_10 )
{
static const struct {
const char * V_178 ;
int V_19 ;
T_1 V_179 ;
int (* F_90)( struct V_139 * ,
struct V_32 * ,
struct V_143 * , struct V_143 * );
int (* V_22)( struct V_139 * , T_1 V_141 );
} V_180 [] = {
{ L_4 , 4 , 0xa0b5 , F_61 , F_56 } ,
{ L_5 , 0 , 0xa0b5 , F_61 , F_65 } ,
{ L_6 , 5 , 0x90b8 , F_66 , F_65 } ,
{ L_7 , 4 , 0x90b5 , F_66 , F_65 } ,
{ L_4 , 0 , 0x85b5 , F_68 , F_72 } ,
{ L_8 , 0 , 0x74c1 , F_71 , F_72 } ,
{ L_9 , 0 , 0x9039 , F_67 , F_65 } ,
{ L_9 , 0 , 0x5039 , F_73 , F_72 } ,
{ L_9 , 0 , 0x0039 , F_77 , F_75 } ,
{} ,
{ L_8 , 0 , 0x88b4 , F_70 , F_72 } ,
} , * V_181 = V_180 ;
const char * V_178 = L_10 ;
int V_53 ;
do {
struct V_182 * V_183 ;
struct V_139 * V_140 ;
T_1 V_141 = ( V_181 -> V_19 << 16 ) | V_181 -> V_179 ;
if ( V_181 -> V_19 )
V_140 = V_10 -> V_184 ;
else
V_140 = V_10 -> V_185 ;
if ( V_140 == NULL )
continue;
V_53 = F_91 ( F_92 ( V_10 ) , V_140 -> V_141 , V_141 ,
V_181 -> V_179 , NULL , 0 , & V_183 ) ;
if ( V_53 == 0 ) {
V_53 = V_181 -> V_22 ( V_140 , V_141 ) ;
if ( V_53 ) {
F_93 ( F_92 ( V_10 ) ,
V_140 -> V_141 , V_141 ) ;
continue;
}
V_10 -> V_69 . V_177 = V_181 -> F_90 ;
V_10 -> V_69 . V_140 = V_140 ;
V_178 = V_181 -> V_178 ;
break;
}
} while ( ( ++ V_181 ) -> F_90 );
F_94 ( V_10 , L_11 , V_178 ) ;
}
static int
F_95 ( struct V_32 * V_33 , bool V_171 , bool V_172 ,
bool V_105 , struct V_143 * V_145 )
{
T_1 V_186 = V_70 | V_88 ;
struct V_87 V_74 ;
struct V_143 V_187 ;
int V_53 ;
V_74 . V_84 = V_74 . V_85 = 0 ;
V_74 . V_91 = V_74 . V_94 = 1 ;
V_74 . V_74 = V_74 . V_92 = & V_186 ;
V_187 = * V_145 ;
V_187 . V_148 = NULL ;
V_53 = F_96 ( V_33 , & V_74 , & V_187 , V_172 , V_105 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_97 ( V_33 -> V_69 , & V_187 ) ;
if ( V_53 )
goto V_96;
V_53 = F_83 ( V_33 , true , V_172 , V_105 , & V_187 ) ;
if ( V_53 )
goto V_96;
V_53 = F_98 ( V_33 , true , V_105 , V_145 ) ;
V_96:
F_99 ( V_33 , & V_187 ) ;
return V_53 ;
}
static int
F_100 ( struct V_32 * V_33 , bool V_171 , bool V_172 ,
bool V_105 , struct V_143 * V_145 )
{
T_1 V_186 = V_70 | V_88 ;
struct V_87 V_74 ;
struct V_143 V_187 ;
int V_53 ;
V_74 . V_84 = V_74 . V_85 = 0 ;
V_74 . V_91 = V_74 . V_94 = 1 ;
V_74 . V_74 = V_74 . V_92 = & V_186 ;
V_187 = * V_145 ;
V_187 . V_148 = NULL ;
V_53 = F_96 ( V_33 , & V_74 , & V_187 , V_172 , V_105 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_98 ( V_33 , true , V_105 , & V_187 ) ;
if ( V_53 )
goto V_96;
V_53 = F_83 ( V_33 , true , V_172 , V_105 , V_145 ) ;
if ( V_53 )
goto V_96;
V_96:
F_99 ( V_33 , & V_187 ) ;
return V_53 ;
}
static void
F_101 ( struct V_32 * V_33 , struct V_143 * V_145 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_188 * V_149 ;
if ( V_33 -> V_189 != F_10 )
return;
F_102 (vma, &nvbo->vma_list, head) {
if ( V_145 && V_145 -> V_97 != V_123 &&
( V_145 -> V_97 == V_98 ||
V_36 -> V_46 != V_149 -> V_59 -> V_60 -> V_55 ) ) {
F_82 ( V_149 , V_145 -> V_148 ) ;
} else {
F_103 ( V_149 ) ;
}
}
}
static int
F_104 ( struct V_32 * V_33 , struct V_143 * V_145 ,
struct V_3 * * V_190 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
T_5 V_150 = V_145 -> V_165 << V_73 ;
* V_190 = NULL ;
if ( V_145 -> V_97 != V_98 )
return 0 ;
if ( F_17 ( V_10 -> V_15 ) -> V_42 >= V_81 ) {
* V_190 = F_9 ( V_2 , V_150 , V_145 -> V_6 ,
V_36 -> V_44 ,
V_36 -> V_48 ) ;
}
return 0 ;
}
static void
F_105 ( struct V_32 * V_33 ,
struct V_3 * V_190 ,
struct V_3 * * V_191 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_7 ( V_2 , * V_191 , V_33 -> V_176 ) ;
* V_191 = V_190 ;
}
static int
F_106 ( struct V_32 * V_33 , bool V_171 , bool V_172 ,
bool V_105 , struct V_143 * V_145 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_143 * V_144 = & V_33 -> V_71 ;
struct V_3 * V_190 = NULL ;
int V_53 = 0 ;
if ( F_17 ( V_10 -> V_15 ) -> V_42 < V_43 ) {
V_53 = F_104 ( V_33 , V_145 , & V_190 ) ;
if ( V_53 )
return V_53 ;
}
if ( V_144 -> V_97 == V_123 && ! V_33 -> V_69 ) {
F_107 ( V_33 -> V_71 . V_148 != NULL ) ;
V_33 -> V_71 = * V_145 ;
V_145 -> V_148 = NULL ;
goto V_96;
}
if ( V_10 -> V_69 . V_177 ) {
if ( V_145 -> V_97 == V_123 )
V_53 = F_95 ( V_33 , V_171 , V_172 ,
V_105 , V_145 ) ;
else if ( V_144 -> V_97 == V_123 )
V_53 = F_100 ( V_33 , V_171 , V_172 ,
V_105 , V_145 ) ;
else
V_53 = F_83 ( V_33 , V_171 , V_172 ,
V_105 , V_145 ) ;
if ( ! V_53 )
goto V_96;
}
F_4 ( & V_33 -> V_34 -> V_192 ) ;
V_53 = F_108 ( V_33 , true , V_172 , V_105 ) ;
F_6 ( & V_33 -> V_34 -> V_192 ) ;
if ( V_53 == 0 )
V_53 = F_109 ( V_33 , V_171 , V_105 , V_145 ) ;
V_96:
if ( F_17 ( V_10 -> V_15 ) -> V_42 < V_43 ) {
if ( V_53 )
F_105 ( V_33 , NULL , & V_190 ) ;
else
F_105 ( V_33 , V_190 , & V_36 -> V_12 ) ;
}
return V_53 ;
}
static int
F_110 ( struct V_32 * V_33 , struct V_193 * V_38 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
return F_111 ( & V_36 -> V_37 . V_194 , V_38 ) ;
}
static int
F_112 ( struct V_112 * V_34 , struct V_143 * V_71 )
{
struct V_121 * V_122 = & V_34 -> V_122 [ V_71 -> V_97 ] ;
struct V_9 * V_10 = F_11 ( V_34 ) ;
struct V_146 * V_147 = V_71 -> V_148 ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_53 ;
V_71 -> V_195 . V_5 = NULL ;
V_71 -> V_195 . V_150 = 0 ;
V_71 -> V_195 . V_6 = V_71 -> V_72 << V_73 ;
V_71 -> V_195 . V_58 = 0 ;
V_71 -> V_195 . V_107 = false ;
if ( ! ( V_122 -> V_8 & V_124 ) )
return - V_62 ;
switch ( V_71 -> V_97 ) {
case V_123 :
return 0 ;
case V_100 :
#if V_116
if ( V_10 -> V_117 . V_118 == V_119 ) {
V_71 -> V_195 . V_150 = V_71 -> V_165 << V_73 ;
V_71 -> V_195 . V_58 = V_10 -> V_117 . V_58 ;
V_71 -> V_195 . V_107 = ! V_2 -> V_117 -> V_196 ;
}
#endif
if ( F_17 ( V_10 -> V_15 ) -> V_42 < V_43 || ! V_147 -> V_95 )
break;
case V_98 :
V_71 -> V_195 . V_150 = V_71 -> V_165 << V_73 ;
V_71 -> V_195 . V_58 = F_113 ( F_114 ( V_2 ) , 1 ) ;
V_71 -> V_195 . V_107 = true ;
if ( F_17 ( V_10 -> V_15 ) -> V_42 >= V_43 ) {
struct V_197 * V_198 = V_197 ( V_10 -> V_15 ) ;
V_53 = V_198 -> V_199 ( V_198 , V_147 , V_170 ,
& V_147 -> V_200 ) ;
if ( V_53 )
return V_53 ;
V_71 -> V_195 . V_150 = V_147 -> V_200 . V_150 ;
}
break;
default:
return - V_62 ;
}
return 0 ;
}
static void
F_115 ( struct V_112 * V_34 , struct V_143 * V_71 )
{
struct V_9 * V_10 = F_11 ( V_34 ) ;
struct V_197 * V_198 = V_197 ( V_10 -> V_15 ) ;
struct V_146 * V_147 = V_71 -> V_148 ;
if ( ! V_147 -> V_200 . V_147 )
return;
V_198 -> V_201 ( V_198 , & V_147 -> V_200 ) ;
}
static int
F_116 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_41 * V_15 = F_17 ( V_10 -> V_15 ) ;
T_1 V_202 = F_117 ( V_15 , 1 ) >> V_73 ;
int V_53 ;
if ( V_33 -> V_71 . V_97 != V_98 ) {
if ( F_17 ( V_10 -> V_15 ) -> V_42 < V_43 ||
! F_118 ( V_36 ) )
return 0 ;
if ( V_33 -> V_71 . V_97 == V_123 ) {
F_24 ( V_36 , V_100 , 0 ) ;
V_53 = F_32 ( V_36 , false , false ) ;
if ( V_53 )
return V_53 ;
}
return 0 ;
}
if ( F_17 ( V_10 -> V_15 ) -> V_42 >= V_43 ||
V_33 -> V_71 . V_165 + V_33 -> V_71 . V_72 < V_202 )
return 0 ;
V_36 -> V_74 . V_84 = 0 ;
V_36 -> V_74 . V_85 = V_202 ;
F_24 ( V_36 , V_77 , 0 ) ;
return F_32 ( V_36 , false , false ) ;
}
static int
F_119 ( struct V_111 * V_69 )
{
struct V_203 * V_204 = ( void * ) V_69 ;
struct V_9 * V_10 ;
struct V_41 * V_15 ;
struct V_1 * V_2 ;
unsigned V_11 ;
int V_205 ;
bool V_206 = ! ! ( V_69 -> V_113 & V_207 ) ;
if ( V_69 -> V_208 != V_209 )
return 0 ;
if ( V_206 && V_69 -> V_50 ) {
F_120 ( V_69 -> V_50 , V_69 -> V_210 ,
V_204 -> V_211 , V_69 -> V_72 ) ;
V_69 -> V_208 = V_212 ;
return 0 ;
}
V_10 = F_11 ( V_69 -> V_34 ) ;
V_15 = F_17 ( V_10 -> V_15 ) ;
V_2 = V_10 -> V_2 ;
#if V_116
if ( V_10 -> V_117 . V_118 == V_119 ) {
return F_121 ( V_69 ) ;
}
#endif
#ifdef F_122
if ( F_123 () ) {
return F_124 ( ( void * ) V_69 , V_2 -> V_2 ) ;
}
#endif
V_205 = F_125 ( V_69 ) ;
if ( V_205 ) {
return V_205 ;
}
for ( V_11 = 0 ; V_11 < V_69 -> V_72 ; V_11 ++ ) {
V_204 -> V_211 [ V_11 ] = F_126 ( V_15 ,
V_69 -> V_210 [ V_11 ] ) ;
if ( ! V_204 -> V_211 [ V_11 ] ) {
while ( -- V_11 ) {
F_127 ( V_15 ,
V_204 -> V_211 [ V_11 ] ) ;
V_204 -> V_211 [ V_11 ] = 0 ;
}
F_128 ( V_69 ) ;
return - V_213 ;
}
}
return 0 ;
}
static void
F_129 ( struct V_111 * V_69 )
{
struct V_203 * V_204 = ( void * ) V_69 ;
struct V_9 * V_10 ;
struct V_41 * V_15 ;
struct V_1 * V_2 ;
unsigned V_11 ;
bool V_206 = ! ! ( V_69 -> V_113 & V_207 ) ;
if ( V_206 )
return;
V_10 = F_11 ( V_69 -> V_34 ) ;
V_15 = F_17 ( V_10 -> V_15 ) ;
V_2 = V_10 -> V_2 ;
#if V_116
if ( V_10 -> V_117 . V_118 == V_119 ) {
F_130 ( V_69 ) ;
return;
}
#endif
#ifdef F_122
if ( F_123 () ) {
F_131 ( ( void * ) V_69 , V_2 -> V_2 ) ;
return;
}
#endif
for ( V_11 = 0 ; V_11 < V_69 -> V_72 ; V_11 ++ ) {
if ( V_204 -> V_211 [ V_11 ] ) {
F_127 ( V_15 , V_204 -> V_211 [ V_11 ] ) ;
}
}
F_128 ( V_69 ) ;
}
void
F_132 ( struct V_35 * V_36 , struct V_29 * V_20 )
{
struct V_29 * V_214 = F_8 ( V_20 ) ;
struct V_29 * V_215 = NULL ;
F_4 ( & V_36 -> V_33 . V_34 -> V_192 ) ;
V_215 = V_36 -> V_33 . V_176 ;
V_36 -> V_33 . V_176 = V_214 ;
F_6 ( & V_36 -> V_33 . V_34 -> V_192 ) ;
F_2 ( & V_215 ) ;
}
static void
F_133 ( void * * V_176 )
{
F_2 ( (struct V_29 * * ) V_176 ) ;
}
static void *
F_134 ( void * V_176 )
{
return F_8 ( V_176 ) ;
}
static bool
F_135 ( void * V_176 )
{
return F_5 ( V_176 ) ;
}
static int
F_136 ( void * V_176 , bool V_216 , bool V_172 )
{
return F_137 ( V_176 , V_216 , V_172 ) ;
}
static int
F_138 ( void * V_176 )
{
return 0 ;
}
struct V_188 *
F_139 ( struct V_35 * V_36 , struct V_217 * V_59 )
{
struct V_188 * V_149 ;
F_102 (vma, &nvbo->vma_list, head) {
if ( V_149 -> V_59 == V_59 )
return V_149 ;
}
return NULL ;
}
int
F_140 ( struct V_35 * V_36 , struct V_217 * V_59 ,
struct V_188 * V_149 )
{
const T_1 V_6 = V_36 -> V_33 . V_71 . V_72 << V_73 ;
int V_53 ;
V_53 = F_79 ( V_59 , V_6 , V_36 -> V_46 ,
V_170 , V_149 ) ;
if ( V_53 )
return V_53 ;
if ( V_36 -> V_33 . V_71 . V_97 != V_123 &&
( V_36 -> V_33 . V_71 . V_97 == V_98 ||
V_36 -> V_46 != V_149 -> V_59 -> V_60 -> V_55 ) )
F_82 ( V_149 , V_36 -> V_33 . V_71 . V_148 ) ;
F_141 ( & V_149 -> V_66 , & V_36 -> V_68 ) ;
V_149 -> V_218 = 1 ;
return 0 ;
}
void
F_142 ( struct V_35 * V_36 , struct V_188 * V_149 )
{
if ( V_149 -> V_147 ) {
if ( V_36 -> V_33 . V_71 . V_97 != V_123 )
F_103 ( V_149 ) ;
F_81 ( V_149 ) ;
F_143 ( & V_149 -> V_66 ) ;
}
}
