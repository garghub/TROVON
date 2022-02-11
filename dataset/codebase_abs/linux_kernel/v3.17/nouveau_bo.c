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
struct V_29 * V_20 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
if ( V_12 ) {
F_5 ( & V_10 -> V_12 . V_27 ) ;
V_12 -> V_20 = F_9 ( V_20 ) ;
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
struct V_50 * V_51 ,
struct V_35 * * V_52 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_35 * V_36 ;
T_3 V_53 ;
int V_54 ;
int type = V_55 ;
int V_56 = 12 ;
int V_57 ;
if ( V_10 -> V_58 . V_59 )
V_56 = V_10 -> V_58 . V_59 -> V_60 -> V_56 ;
V_57 = V_61 & ~ ( ( 1 << V_56 ) - 1 ) ;
if ( V_6 <= 0 || V_6 > V_57 ) {
F_21 ( V_10 , L_2 , ( T_1 ) V_6 ) ;
return - V_62 ;
}
if ( V_51 )
type = V_63 ;
V_36 = F_22 ( sizeof( struct V_35 ) , V_64 ) ;
if ( ! V_36 )
return - V_65 ;
F_23 ( & V_36 -> V_66 ) ;
F_23 ( & V_36 -> V_67 ) ;
F_23 ( & V_36 -> V_68 ) ;
V_36 -> V_45 = V_45 ;
V_36 -> V_49 = V_49 ;
V_36 -> V_33 . V_34 = & V_10 -> V_69 . V_34 ;
V_36 -> V_47 = 12 ;
if ( V_10 -> V_58 . V_59 ) {
if ( ! ( V_8 & V_70 ) && V_6 > 256 * 1024 )
V_36 -> V_47 = V_10 -> V_58 . V_59 -> V_60 -> V_56 ;
}
F_17 ( V_36 , V_8 , & V_40 , & V_6 ) ;
V_36 -> V_33 . V_71 . V_72 = V_6 >> V_73 ;
F_24 ( V_36 , V_8 , 0 ) ;
V_53 = F_25 ( & V_10 -> V_69 . V_34 , V_6 ,
sizeof( struct V_35 ) ) ;
V_54 = F_26 ( & V_10 -> V_69 . V_34 , & V_36 -> V_33 , V_6 ,
type , & V_36 -> V_74 ,
V_40 >> V_73 , false , NULL , V_53 , V_51 ,
F_11 ) ;
if ( V_54 ) {
return V_54 ;
}
* V_52 = V_36 ;
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
struct V_9 * V_10 = F_12 ( V_36 -> V_33 . V_34 ) ;
T_1 V_79 = V_10 -> V_15 . V_42 . V_80 >> V_73 ;
if ( V_10 -> V_15 . V_42 . V_43 == V_81 &&
V_36 -> V_45 && ( type & V_77 ) &&
V_36 -> V_33 . V_71 . V_72 < V_79 / 4 ) {
if ( V_36 -> V_49 & V_82 ) {
V_36 -> V_74 . V_83 = V_79 / 2 ;
V_36 -> V_74 . V_84 = ~ 0 ;
} else {
V_36 -> V_74 . V_83 = 0 ;
V_36 -> V_74 . V_84 = V_79 / 2 ;
}
}
}
void
F_24 ( struct V_35 * V_36 , T_2 type , T_2 V_85 )
{
struct V_86 * V_75 = & V_36 -> V_74 ;
T_2 V_8 = V_87 |
( V_36 -> V_39 ? V_88 : 0 ) ;
V_75 -> V_74 = V_36 -> V_89 ;
F_27 ( V_36 -> V_89 , & V_75 -> V_90 ,
type , V_8 ) ;
V_75 -> V_91 = V_36 -> V_92 ;
F_27 ( V_36 -> V_92 , & V_75 -> V_93 ,
type | V_85 , V_8 ) ;
F_28 ( V_36 , type ) ;
}
int
F_29 ( struct V_35 * V_36 , T_2 V_94 )
{
struct V_9 * V_10 = F_12 ( V_36 -> V_33 . V_34 ) ;
struct V_32 * V_33 = & V_36 -> V_33 ;
int V_54 ;
V_54 = F_30 ( V_33 , false , false , false , NULL ) ;
if ( V_54 )
goto V_95;
if ( V_36 -> V_39 && ! ( V_94 & ( 1 << V_33 -> V_71 . V_96 ) ) ) {
F_31 ( V_10 , L_3 , V_33 ,
1 << V_33 -> V_71 . V_96 , V_94 ) ;
V_54 = - V_62 ;
goto V_95;
}
if ( V_36 -> V_39 ++ )
goto V_95;
F_24 ( V_36 , V_94 , 0 ) ;
V_54 = F_32 ( V_36 , false , false ) ;
if ( V_54 == 0 ) {
switch ( V_33 -> V_71 . V_96 ) {
case V_97 :
V_10 -> V_37 . V_98 -= V_33 -> V_71 . V_6 ;
break;
case V_99 :
V_10 -> V_37 . V_100 -= V_33 -> V_71 . V_6 ;
break;
default:
break;
}
}
V_95:
F_33 ( V_33 ) ;
return V_54 ;
}
int
F_34 ( struct V_35 * V_36 )
{
struct V_9 * V_10 = F_12 ( V_36 -> V_33 . V_34 ) ;
struct V_32 * V_33 = & V_36 -> V_33 ;
int V_54 , V_101 ;
V_54 = F_30 ( V_33 , false , false , false , NULL ) ;
if ( V_54 )
return V_54 ;
V_101 = -- V_36 -> V_39 ;
F_35 ( V_101 < 0 ) ;
if ( V_101 )
goto V_95;
F_24 ( V_36 , V_33 -> V_71 . V_74 , 0 ) ;
V_54 = F_32 ( V_36 , false , false ) ;
if ( V_54 == 0 ) {
switch ( V_33 -> V_71 . V_96 ) {
case V_97 :
V_10 -> V_37 . V_98 += V_33 -> V_71 . V_6 ;
break;
case V_99 :
V_10 -> V_37 . V_100 += V_33 -> V_71 . V_6 ;
break;
default:
break;
}
}
V_95:
F_33 ( V_33 ) ;
return V_54 ;
}
int
F_36 ( struct V_35 * V_36 )
{
int V_54 ;
V_54 = F_30 ( & V_36 -> V_33 , false , false , false , NULL ) ;
if ( V_54 )
return V_54 ;
V_54 = F_37 ( & V_36 -> V_33 , 0 , V_36 -> V_33 . V_71 . V_72 , & V_36 -> V_102 ) ;
F_33 ( & V_36 -> V_33 ) ;
return V_54 ;
}
void
F_38 ( struct V_35 * V_36 )
{
if ( V_36 )
F_39 ( & V_36 -> V_102 ) ;
}
int
F_32 ( struct V_35 * V_36 , bool V_103 ,
bool V_104 )
{
int V_54 ;
V_54 = F_40 ( & V_36 -> V_33 , & V_36 -> V_74 ,
V_103 , V_104 ) ;
if ( V_54 )
return V_54 ;
return 0 ;
}
T_4
F_41 ( struct V_35 * V_36 , unsigned V_105 )
{
bool V_106 ;
T_4 * V_71 = F_42 ( & V_36 -> V_102 , & V_106 ) ;
V_71 = & V_71 [ V_105 ] ;
if ( V_106 )
return F_43 ( ( void V_107 V_108 * ) V_71 ) ;
else
return * V_71 ;
}
void
F_44 ( struct V_35 * V_36 , unsigned V_105 , T_4 V_109 )
{
bool V_106 ;
T_4 * V_71 = F_42 ( & V_36 -> V_102 , & V_106 ) ;
V_71 = & V_71 [ V_105 ] ;
if ( V_106 )
F_45 ( V_109 , ( void V_107 V_108 * ) V_71 ) ;
else
* V_71 = V_109 ;
}
T_1
F_46 ( struct V_35 * V_36 , unsigned V_105 )
{
bool V_106 ;
T_1 * V_71 = F_42 ( & V_36 -> V_102 , & V_106 ) ;
V_71 = & V_71 [ V_105 ] ;
if ( V_106 )
return F_47 ( ( void V_107 V_108 * ) V_71 ) ;
else
return * V_71 ;
}
void
F_48 ( struct V_35 * V_36 , unsigned V_105 , T_1 V_109 )
{
bool V_106 ;
T_1 * V_71 = F_42 ( & V_36 -> V_102 , & V_106 ) ;
V_71 = & V_71 [ V_105 ] ;
if ( V_106 )
F_49 ( V_109 , ( void V_107 V_108 * ) V_71 ) ;
else
* V_71 = V_109 ;
}
static struct V_110 *
F_50 ( struct V_111 * V_34 , unsigned long V_6 ,
T_2 V_112 , struct V_113 * V_114 )
{
#if V_115
struct V_9 * V_10 = F_12 ( V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_10 -> V_116 . V_117 == V_118 ) {
return F_51 ( V_34 , V_2 -> V_116 -> V_119 , V_6 ,
V_112 , V_114 ) ;
}
#endif
return F_52 ( V_34 , V_6 , V_112 , V_114 ) ;
}
static int
F_53 ( struct V_111 * V_34 , T_2 V_8 )
{
return 0 ;
}
static int
F_54 ( struct V_111 * V_34 , T_2 type ,
struct V_120 * V_121 )
{
struct V_9 * V_10 = F_12 ( V_34 ) ;
switch ( type ) {
case V_122 :
V_121 -> V_8 = V_123 ;
V_121 -> V_124 = V_87 ;
V_121 -> V_125 = V_126 ;
break;
case V_97 :
V_121 -> V_8 = V_127 |
V_123 ;
V_121 -> V_124 = V_128 |
V_129 ;
V_121 -> V_125 = V_129 ;
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 ) {
if ( F_55 ( & V_10 -> V_15 ) -> V_130 ) {
V_121 -> V_124 = V_128 ;
V_121 -> V_125 = V_128 ;
}
V_121 -> V_131 = & V_132 ;
V_121 -> V_133 = false ;
V_121 -> V_134 = true ;
} else {
V_121 -> V_131 = & V_135 ;
}
break;
case V_99 :
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 )
V_121 -> V_131 = & V_136 ;
else
if ( V_10 -> V_116 . V_117 != V_118 )
V_121 -> V_131 = & V_137 ;
else
V_121 -> V_131 = & V_135 ;
if ( V_10 -> V_116 . V_117 == V_118 ) {
V_121 -> V_8 = V_123 ;
V_121 -> V_124 = V_128 |
V_129 ;
V_121 -> V_125 = V_129 ;
} else {
V_121 -> V_8 = V_123 |
V_138 ;
V_121 -> V_124 = V_87 ;
V_121 -> V_125 = V_126 ;
}
break;
default:
return - V_62 ;
}
return 0 ;
}
static void
F_56 ( struct V_32 * V_33 , struct V_86 * V_75 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
switch ( V_33 -> V_71 . V_96 ) {
case V_97 :
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
F_57 ( struct V_139 * V_140 , T_1 V_141 )
{
int V_54 = F_58 ( V_140 , 2 ) ;
if ( V_54 == 0 ) {
F_59 ( V_140 , V_142 , 0x0000 , 1 ) ;
F_60 ( V_140 , V_141 & 0x0000ffff ) ;
F_61 ( V_140 ) ;
}
return V_54 ;
}
static int
F_62 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
struct V_146 * V_147 = V_144 -> V_148 ;
int V_54 = F_58 ( V_140 , 10 ) ;
if ( V_54 == 0 ) {
F_59 ( V_140 , V_142 , 0x0400 , 8 ) ;
F_60 ( V_140 , F_63 ( V_147 -> V_149 [ 0 ] . V_150 ) ) ;
F_60 ( V_140 , F_64 ( V_147 -> V_149 [ 0 ] . V_150 ) ) ;
F_60 ( V_140 , F_63 ( V_147 -> V_149 [ 1 ] . V_150 ) ) ;
F_60 ( V_140 , F_64 ( V_147 -> V_149 [ 1 ] . V_150 ) ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_145 -> V_72 ) ;
F_65 ( V_140 , V_142 , 0x0300 , 0x0386 ) ;
}
return V_54 ;
}
static int
F_66 ( struct V_139 * V_140 , T_1 V_141 )
{
int V_54 = F_58 ( V_140 , 2 ) ;
if ( V_54 == 0 ) {
F_59 ( V_140 , V_142 , 0x0000 , 1 ) ;
F_60 ( V_140 , V_141 ) ;
}
return V_54 ;
}
static int
F_67 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
struct V_146 * V_147 = V_144 -> V_148 ;
T_5 V_151 = V_147 -> V_149 [ 0 ] . V_150 ;
T_5 V_152 = V_147 -> V_149 [ 1 ] . V_150 ;
T_1 V_153 = V_145 -> V_72 ;
int V_54 ;
V_153 = V_145 -> V_72 ;
while ( V_153 ) {
int V_154 = ( V_153 > 8191 ) ? 8191 : V_153 ;
V_54 = F_58 ( V_140 , 11 ) ;
if ( V_54 )
return V_54 ;
F_59 ( V_140 , V_142 , 0x030c , 8 ) ;
F_60 ( V_140 , F_63 ( V_151 ) ) ;
F_60 ( V_140 , F_64 ( V_151 ) ) ;
F_60 ( V_140 , F_63 ( V_152 ) ) ;
F_60 ( V_140 , F_64 ( V_152 ) ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_154 ) ;
F_59 ( V_140 , V_142 , 0x0300 , 1 ) ;
F_60 ( V_140 , 0x00000110 ) ;
V_153 -= V_154 ;
V_151 += ( V_48 * V_154 ) ;
V_152 += ( V_48 * V_154 ) ;
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
int V_54 ;
V_153 = V_145 -> V_72 ;
while ( V_153 ) {
int V_154 = ( V_153 > 2047 ) ? 2047 : V_153 ;
V_54 = F_58 ( V_140 , 12 ) ;
if ( V_54 )
return V_54 ;
F_59 ( V_140 , V_142 , 0x0238 , 2 ) ;
F_60 ( V_140 , F_63 ( V_152 ) ) ;
F_60 ( V_140 , F_64 ( V_152 ) ) ;
F_59 ( V_140 , V_142 , 0x030c , 6 ) ;
F_60 ( V_140 , F_63 ( V_151 ) ) ;
F_60 ( V_140 , F_64 ( V_151 ) ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_154 ) ;
F_59 ( V_140 , V_142 , 0x0300 , 1 ) ;
F_60 ( V_140 , 0x00100110 ) ;
V_153 -= V_154 ;
V_151 += ( V_48 * V_154 ) ;
V_152 += ( V_48 * V_154 ) ;
}
return 0 ;
}
static int
F_69 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
struct V_146 * V_147 = V_144 -> V_148 ;
T_5 V_151 = V_147 -> V_149 [ 0 ] . V_150 ;
T_5 V_152 = V_147 -> V_149 [ 1 ] . V_150 ;
T_1 V_153 = V_145 -> V_72 ;
int V_54 ;
V_153 = V_145 -> V_72 ;
while ( V_153 ) {
int V_154 = ( V_153 > 8191 ) ? 8191 : V_153 ;
V_54 = F_58 ( V_140 , 11 ) ;
if ( V_54 )
return V_54 ;
F_70 ( V_140 , V_142 , 0x030c , 8 ) ;
F_60 ( V_140 , F_63 ( V_151 ) ) ;
F_60 ( V_140 , F_64 ( V_151 ) ) ;
F_60 ( V_140 , F_63 ( V_152 ) ) ;
F_60 ( V_140 , F_64 ( V_152 ) ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_154 ) ;
F_70 ( V_140 , V_142 , 0x0300 , 1 ) ;
F_60 ( V_140 , 0x00000110 ) ;
V_153 -= V_154 ;
V_151 += ( V_48 * V_154 ) ;
V_152 += ( V_48 * V_154 ) ;
}
return 0 ;
}
static int
F_71 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
struct V_146 * V_147 = V_144 -> V_148 ;
int V_54 = F_58 ( V_140 , 7 ) ;
if ( V_54 == 0 ) {
F_70 ( V_140 , V_142 , 0x0320 , 6 ) ;
F_60 ( V_140 , F_63 ( V_147 -> V_149 [ 0 ] . V_150 ) ) ;
F_60 ( V_140 , F_64 ( V_147 -> V_149 [ 0 ] . V_150 ) ) ;
F_60 ( V_140 , F_63 ( V_147 -> V_149 [ 1 ] . V_150 ) ) ;
F_60 ( V_140 , F_64 ( V_147 -> V_149 [ 1 ] . V_150 ) ) ;
F_60 ( V_140 , 0x00000000 ) ;
F_60 ( V_140 , V_145 -> V_72 << V_73 ) ;
}
return V_54 ;
}
static int
F_72 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
struct V_146 * V_147 = V_144 -> V_148 ;
int V_54 = F_58 ( V_140 , 7 ) ;
if ( V_54 == 0 ) {
F_70 ( V_140 , V_142 , 0x0304 , 6 ) ;
F_60 ( V_140 , V_145 -> V_72 << V_73 ) ;
F_60 ( V_140 , F_63 ( V_147 -> V_149 [ 0 ] . V_150 ) ) ;
F_60 ( V_140 , F_64 ( V_147 -> V_149 [ 0 ] . V_150 ) ) ;
F_60 ( V_140 , F_63 ( V_147 -> V_149 [ 1 ] . V_150 ) ) ;
F_60 ( V_140 , F_64 ( V_147 -> V_149 [ 1 ] . V_150 ) ) ;
F_60 ( V_140 , 0x00000000 ) ;
}
return V_54 ;
}
static int
F_73 ( struct V_139 * V_140 , T_1 V_141 )
{
int V_54 = F_58 ( V_140 , 6 ) ;
if ( V_54 == 0 ) {
F_70 ( V_140 , V_142 , 0x0000 , 1 ) ;
F_60 ( V_140 , V_141 ) ;
F_70 ( V_140 , V_142 , 0x0180 , 3 ) ;
F_60 ( V_140 , V_140 -> V_10 -> V_155 . V_141 ) ;
F_60 ( V_140 , V_140 -> V_156 . V_141 ) ;
F_60 ( V_140 , V_140 -> V_156 . V_141 ) ;
}
return V_54 ;
}
static int
F_74 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
struct V_146 * V_147 = V_144 -> V_148 ;
T_5 V_157 = ( V_145 -> V_72 << V_73 ) ;
T_5 V_151 = V_147 -> V_149 [ 0 ] . V_150 ;
T_5 V_152 = V_147 -> V_149 [ 1 ] . V_150 ;
int V_158 = ! ! V_147 -> V_94 ;
int V_159 = ! ! ( (struct V_146 * ) V_145 -> V_148 ) -> V_94 ;
int V_54 ;
while ( V_157 ) {
T_1 V_160 , V_161 , V_162 ;
V_54 = F_58 ( V_140 , 18 + 6 * ( V_158 + V_159 ) ) ;
if ( V_54 )
return V_54 ;
V_160 = F_75 ( V_157 , ( T_5 ) ( 4 * 1024 * 1024 ) ) ;
V_161 = 16 * 4 ;
V_162 = V_160 / V_161 ;
if ( V_158 ) {
F_70 ( V_140 , V_142 , 0x0200 , 7 ) ;
F_60 ( V_140 , 0 ) ;
F_60 ( V_140 , 0 ) ;
F_60 ( V_140 , V_161 ) ;
F_60 ( V_140 , V_162 ) ;
F_60 ( V_140 , 1 ) ;
F_60 ( V_140 , 0 ) ;
F_60 ( V_140 , 0 ) ;
} else {
F_70 ( V_140 , V_142 , 0x0200 , 1 ) ;
F_60 ( V_140 , 1 ) ;
}
if ( V_159 ) {
F_70 ( V_140 , V_142 , 0x021c , 7 ) ;
F_60 ( V_140 , 0 ) ;
F_60 ( V_140 , 0 ) ;
F_60 ( V_140 , V_161 ) ;
F_60 ( V_140 , V_162 ) ;
F_60 ( V_140 , 1 ) ;
F_60 ( V_140 , 0 ) ;
F_60 ( V_140 , 0 ) ;
} else {
F_70 ( V_140 , V_142 , 0x021c , 1 ) ;
F_60 ( V_140 , 1 ) ;
}
F_70 ( V_140 , V_142 , 0x0238 , 2 ) ;
F_60 ( V_140 , F_63 ( V_151 ) ) ;
F_60 ( V_140 , F_63 ( V_152 ) ) ;
F_70 ( V_140 , V_142 , 0x030c , 8 ) ;
F_60 ( V_140 , F_64 ( V_151 ) ) ;
F_60 ( V_140 , F_64 ( V_152 ) ) ;
F_60 ( V_140 , V_161 ) ;
F_60 ( V_140 , V_161 ) ;
F_60 ( V_140 , V_161 ) ;
F_60 ( V_140 , V_162 ) ;
F_60 ( V_140 , 0x00000101 ) ;
F_60 ( V_140 , 0x00000000 ) ;
F_70 ( V_140 , V_142 , V_163 , 1 ) ;
F_60 ( V_140 , 0 ) ;
V_157 -= V_160 ;
V_151 += V_160 ;
V_152 += V_160 ;
}
return 0 ;
}
static int
F_76 ( struct V_139 * V_140 , T_1 V_141 )
{
int V_54 = F_58 ( V_140 , 4 ) ;
if ( V_54 == 0 ) {
F_70 ( V_140 , V_142 , 0x0000 , 1 ) ;
F_60 ( V_140 , V_141 ) ;
F_70 ( V_140 , V_142 , 0x0180 , 1 ) ;
F_60 ( V_140 , V_140 -> V_10 -> V_155 . V_141 ) ;
}
return V_54 ;
}
static inline T_2
F_77 ( struct V_32 * V_33 ,
struct V_139 * V_140 , struct V_143 * V_71 )
{
if ( V_71 -> V_96 == V_99 )
return V_164 ;
return V_140 -> V_156 . V_141 ;
}
static int
F_78 ( struct V_139 * V_140 , struct V_32 * V_33 ,
struct V_143 * V_144 , struct V_143 * V_145 )
{
T_1 V_151 = V_144 -> V_165 << V_73 ;
T_1 V_152 = V_145 -> V_165 << V_73 ;
T_1 V_153 = V_145 -> V_72 ;
int V_54 ;
V_54 = F_58 ( V_140 , 3 ) ;
if ( V_54 )
return V_54 ;
F_70 ( V_140 , V_142 , V_166 , 2 ) ;
F_60 ( V_140 , F_77 ( V_33 , V_140 , V_144 ) ) ;
F_60 ( V_140 , F_77 ( V_33 , V_140 , V_145 ) ) ;
V_153 = V_145 -> V_72 ;
while ( V_153 ) {
int V_154 = ( V_153 > 2047 ) ? 2047 : V_153 ;
V_54 = F_58 ( V_140 , 11 ) ;
if ( V_54 )
return V_54 ;
F_70 ( V_140 , V_142 ,
V_167 , 8 ) ;
F_60 ( V_140 , V_151 ) ;
F_60 ( V_140 , V_152 ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_48 ) ;
F_60 ( V_140 , V_154 ) ;
F_60 ( V_140 , 0x00000101 ) ;
F_60 ( V_140 , 0x00000000 ) ;
F_70 ( V_140 , V_142 , V_163 , 1 ) ;
F_60 ( V_140 , 0 ) ;
V_153 -= V_154 ;
V_151 += ( V_48 * V_154 ) ;
V_152 += ( V_48 * V_154 ) ;
}
return 0 ;
}
static int
F_79 ( struct V_9 * V_10 , struct V_32 * V_33 ,
struct V_143 * V_71 )
{
struct V_146 * V_168 = V_33 -> V_71 . V_148 ;
struct V_146 * V_169 = V_71 -> V_148 ;
T_5 V_6 = ( T_5 ) V_71 -> V_72 << V_73 ;
int V_54 ;
V_54 = F_80 ( V_10 -> V_58 . V_59 , V_6 , V_168 -> V_47 ,
V_170 , & V_168 -> V_149 [ 0 ] ) ;
if ( V_54 )
return V_54 ;
V_54 = F_80 ( V_10 -> V_58 . V_59 , V_6 , V_169 -> V_47 ,
V_170 , & V_168 -> V_149 [ 1 ] ) ;
if ( V_54 ) {
F_81 ( & V_168 -> V_149 [ 0 ] ) ;
return V_54 ;
}
F_82 ( & V_168 -> V_149 [ 0 ] , V_168 ) ;
F_82 ( & V_168 -> V_149 [ 1 ] , V_169 ) ;
return 0 ;
}
static int
F_83 ( struct V_32 * V_33 , int V_171 , bool V_172 ,
bool V_104 , struct V_143 * V_145 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_139 * V_140 = V_10 -> V_69 . V_140 ;
struct V_173 * V_174 = ( void * ) F_84 ( & V_140 -> V_15 -> V_175 ) ;
struct V_29 * V_20 ;
int V_54 ;
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 ) {
V_54 = F_79 ( V_10 , V_33 , V_145 ) ;
if ( V_54 )
return V_54 ;
}
F_85 ( & V_174 -> V_176 , V_177 ) ;
V_54 = F_86 ( V_33 -> V_178 , V_140 ) ;
if ( V_54 == 0 ) {
V_54 = V_10 -> V_69 . V_179 ( V_140 , V_33 , & V_33 -> V_71 , V_145 ) ;
if ( V_54 == 0 ) {
V_54 = F_87 ( V_140 , false , & V_20 ) ;
if ( V_54 == 0 ) {
V_54 = F_88 ( V_33 , V_20 ,
V_171 ,
V_104 ,
V_145 ) ;
F_3 ( & V_20 ) ;
}
}
}
F_89 ( & V_174 -> V_176 ) ;
return V_54 ;
}
void
F_90 ( struct V_9 * V_10 )
{
static const struct {
const char * V_180 ;
int V_19 ;
T_1 V_181 ;
int (* F_91)( struct V_139 * ,
struct V_32 * ,
struct V_143 * , struct V_143 * );
int (* V_22)( struct V_139 * , T_1 V_141 );
} V_182 [] = {
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
} , * V_183 = V_182 ;
const char * V_180 = L_10 ;
int V_54 ;
do {
struct V_139 * V_140 ;
if ( V_183 -> V_19 )
V_140 = V_10 -> V_184 ;
else
V_140 = V_10 -> V_185 ;
if ( V_140 == NULL )
continue;
V_54 = F_92 ( V_140 -> V_186 , NULL ,
V_183 -> V_181 | ( V_183 -> V_19 << 16 ) ,
V_183 -> V_181 , NULL , 0 ,
& V_10 -> V_69 . V_187 ) ;
if ( V_54 == 0 ) {
V_54 = V_183 -> V_22 ( V_140 , V_10 -> V_69 . V_187 . V_141 ) ;
if ( V_54 ) {
F_93 ( & V_10 -> V_69 . V_187 ) ;
continue;
}
V_10 -> V_69 . V_179 = V_183 -> F_91 ;
V_10 -> V_69 . V_140 = V_140 ;
V_180 = V_183 -> V_180 ;
break;
}
} while ( ( ++ V_183 ) -> F_91 );
F_94 ( V_10 , L_11 , V_180 ) ;
}
static int
F_95 ( struct V_32 * V_33 , bool V_171 , bool V_172 ,
bool V_104 , struct V_143 * V_145 )
{
T_1 V_188 = V_70 | V_87 ;
struct V_86 V_74 ;
struct V_143 V_189 ;
int V_54 ;
V_74 . V_83 = V_74 . V_84 = 0 ;
V_74 . V_90 = V_74 . V_93 = 1 ;
V_74 . V_74 = V_74 . V_91 = & V_188 ;
V_189 = * V_145 ;
V_189 . V_148 = NULL ;
V_54 = F_96 ( V_33 , & V_74 , & V_189 , V_172 , V_104 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_97 ( V_33 -> V_69 , & V_189 ) ;
if ( V_54 )
goto V_95;
V_54 = F_83 ( V_33 , true , V_172 , V_104 , & V_189 ) ;
if ( V_54 )
goto V_95;
V_54 = F_98 ( V_33 , true , V_104 , V_145 ) ;
V_95:
F_99 ( V_33 , & V_189 ) ;
return V_54 ;
}
static int
F_100 ( struct V_32 * V_33 , bool V_171 , bool V_172 ,
bool V_104 , struct V_143 * V_145 )
{
T_1 V_188 = V_70 | V_87 ;
struct V_86 V_74 ;
struct V_143 V_189 ;
int V_54 ;
V_74 . V_83 = V_74 . V_84 = 0 ;
V_74 . V_90 = V_74 . V_93 = 1 ;
V_74 . V_74 = V_74 . V_91 = & V_188 ;
V_189 = * V_145 ;
V_189 . V_148 = NULL ;
V_54 = F_96 ( V_33 , & V_74 , & V_189 , V_172 , V_104 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_98 ( V_33 , true , V_104 , & V_189 ) ;
if ( V_54 )
goto V_95;
V_54 = F_83 ( V_33 , true , V_172 , V_104 , V_145 ) ;
if ( V_54 )
goto V_95;
V_95:
F_99 ( V_33 , & V_189 ) ;
return V_54 ;
}
static void
F_101 ( struct V_32 * V_33 , struct V_143 * V_145 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_190 * V_149 ;
if ( V_33 -> V_191 != F_11 )
return;
F_102 (vma, &nvbo->vma_list, head) {
if ( V_145 && V_145 -> V_96 != V_122 &&
( V_145 -> V_96 == V_97 ||
V_36 -> V_47 != V_149 -> V_59 -> V_60 -> V_56 ) ) {
F_82 ( V_149 , V_145 -> V_148 ) ;
} else {
F_103 ( V_149 ) ;
}
}
}
static int
F_104 ( struct V_32 * V_33 , struct V_143 * V_145 ,
struct V_3 * * V_192 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
T_5 V_150 = V_145 -> V_165 << V_73 ;
* V_192 = NULL ;
if ( V_145 -> V_96 != V_97 )
return 0 ;
if ( V_10 -> V_15 . V_42 . V_43 >= V_81 ) {
* V_192 = F_10 ( V_2 , V_150 , V_145 -> V_6 ,
V_36 -> V_45 ,
V_36 -> V_49 ) ;
}
return 0 ;
}
static void
F_105 ( struct V_32 * V_33 ,
struct V_3 * V_192 ,
struct V_3 * * V_193 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_8 ( V_2 , * V_193 , V_33 -> V_178 ) ;
* V_193 = V_192 ;
}
static int
F_106 ( struct V_32 * V_33 , bool V_171 , bool V_172 ,
bool V_104 , struct V_143 * V_145 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_143 * V_144 = & V_33 -> V_71 ;
struct V_3 * V_192 = NULL ;
int V_54 = 0 ;
if ( V_10 -> V_15 . V_42 . V_43 < V_44 ) {
V_54 = F_104 ( V_33 , V_145 , & V_192 ) ;
if ( V_54 )
return V_54 ;
}
if ( V_144 -> V_96 == V_122 && ! V_33 -> V_69 ) {
F_107 ( V_33 -> V_71 . V_148 != NULL ) ;
V_33 -> V_71 = * V_145 ;
V_145 -> V_148 = NULL ;
goto V_95;
}
if ( V_10 -> V_69 . V_179 ) {
if ( V_145 -> V_96 == V_122 )
V_54 = F_95 ( V_33 , V_171 , V_172 ,
V_104 , V_145 ) ;
else if ( V_144 -> V_96 == V_122 )
V_54 = F_100 ( V_33 , V_171 , V_172 ,
V_104 , V_145 ) ;
else
V_54 = F_83 ( V_33 , V_171 , V_172 ,
V_104 , V_145 ) ;
if ( ! V_54 )
goto V_95;
}
F_5 ( & V_33 -> V_34 -> V_194 ) ;
V_54 = F_108 ( V_33 , true , V_172 , V_104 ) ;
F_7 ( & V_33 -> V_34 -> V_194 ) ;
if ( V_54 == 0 )
V_54 = F_109 ( V_33 , V_171 , V_104 , V_145 ) ;
V_95:
if ( V_10 -> V_15 . V_42 . V_43 < V_44 ) {
if ( V_54 )
F_105 ( V_33 , NULL , & V_192 ) ;
else
F_105 ( V_33 , V_192 , & V_36 -> V_12 ) ;
}
return V_54 ;
}
static int
F_110 ( struct V_32 * V_33 , struct V_195 * V_38 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
return F_111 ( & V_36 -> V_37 . V_196 , V_38 ) ;
}
static int
F_112 ( struct V_111 * V_34 , struct V_143 * V_71 )
{
struct V_120 * V_121 = & V_34 -> V_121 [ V_71 -> V_96 ] ;
struct V_9 * V_10 = F_12 ( V_34 ) ;
struct V_146 * V_147 = V_71 -> V_148 ;
int V_54 ;
V_71 -> V_197 . V_5 = NULL ;
V_71 -> V_197 . V_150 = 0 ;
V_71 -> V_197 . V_6 = V_71 -> V_72 << V_73 ;
V_71 -> V_197 . V_175 = 0 ;
V_71 -> V_197 . V_106 = false ;
if ( ! ( V_121 -> V_8 & V_123 ) )
return - V_62 ;
switch ( V_71 -> V_96 ) {
case V_122 :
return 0 ;
case V_99 :
#if V_115
if ( V_10 -> V_116 . V_117 == V_118 ) {
V_71 -> V_197 . V_150 = V_71 -> V_165 << V_73 ;
V_71 -> V_197 . V_175 = V_10 -> V_116 . V_175 ;
V_71 -> V_197 . V_106 = ! V_10 -> V_2 -> V_116 -> V_198 ;
}
#endif
if ( V_10 -> V_15 . V_42 . V_43 < V_44 || ! V_147 -> V_94 )
break;
case V_97 :
V_71 -> V_197 . V_150 = V_71 -> V_165 << V_73 ;
V_71 -> V_197 . V_175 = F_113 ( F_114 ( & V_10 -> V_15 ) , 1 ) ;
V_71 -> V_197 . V_106 = true ;
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 ) {
struct V_199 * V_200 = F_55 ( & V_10 -> V_15 ) ;
V_54 = V_200 -> V_201 ( V_200 , V_147 , V_170 ,
& V_147 -> V_202 ) ;
if ( V_54 )
return V_54 ;
V_71 -> V_197 . V_150 = V_147 -> V_202 . V_150 ;
}
break;
default:
return - V_62 ;
}
return 0 ;
}
static void
F_115 ( struct V_111 * V_34 , struct V_143 * V_71 )
{
struct V_9 * V_10 = F_12 ( V_34 ) ;
struct V_199 * V_200 = F_55 ( & V_10 -> V_15 ) ;
struct V_146 * V_147 = V_71 -> V_148 ;
if ( ! V_147 -> V_202 . V_147 )
return;
V_200 -> V_203 ( V_200 , & V_147 -> V_202 ) ;
}
static int
F_116 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = F_12 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_41 * V_15 = & V_10 -> V_15 ;
T_1 V_204 = F_117 ( F_114 ( V_15 ) , 1 ) >> V_73 ;
int V_54 ;
if ( V_33 -> V_71 . V_96 != V_97 ) {
if ( V_10 -> V_15 . V_42 . V_43 < V_44 ||
! F_118 ( V_36 ) )
return 0 ;
if ( V_33 -> V_71 . V_96 == V_122 ) {
F_24 ( V_36 , V_99 , 0 ) ;
V_54 = F_32 ( V_36 , false , false ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
if ( V_10 -> V_15 . V_42 . V_43 >= V_44 ||
V_33 -> V_71 . V_165 + V_33 -> V_71 . V_72 < V_204 )
return 0 ;
V_36 -> V_74 . V_83 = 0 ;
V_36 -> V_74 . V_84 = V_204 ;
F_24 ( V_36 , V_77 , 0 ) ;
return F_32 ( V_36 , false , false ) ;
}
static int
F_119 ( struct V_110 * V_69 )
{
struct V_205 * V_206 = ( void * ) V_69 ;
struct V_9 * V_10 ;
struct V_207 * V_15 ;
struct V_1 * V_2 ;
struct V_15 * V_208 ;
unsigned V_11 ;
int V_209 ;
bool V_210 = ! ! ( V_69 -> V_112 & V_211 ) ;
if ( V_69 -> V_212 != V_213 )
return 0 ;
if ( V_210 && V_69 -> V_51 ) {
F_120 ( V_69 -> V_51 , V_69 -> V_214 ,
V_206 -> V_215 , V_69 -> V_72 ) ;
V_69 -> V_212 = V_216 ;
return 0 ;
}
V_10 = F_12 ( V_69 -> V_34 ) ;
V_15 = F_114 ( & V_10 -> V_15 ) ;
V_2 = V_10 -> V_2 ;
V_208 = F_121 ( V_15 ) ;
#if V_115
if ( V_10 -> V_116 . V_117 == V_118 ) {
return F_122 ( V_69 ) ;
}
#endif
#ifdef F_123
if ( F_124 () ) {
return F_125 ( ( void * ) V_69 , V_2 -> V_2 ) ;
}
#endif
V_209 = F_126 ( V_69 ) ;
if ( V_209 ) {
return V_209 ;
}
for ( V_11 = 0 ; V_11 < V_69 -> V_72 ; V_11 ++ ) {
T_6 V_5 ;
V_5 = F_127 ( V_208 , V_69 -> V_214 [ V_11 ] , 0 , V_48 ,
V_217 ) ;
if ( F_128 ( V_208 , V_5 ) ) {
while ( -- V_11 ) {
F_129 ( V_208 , V_206 -> V_215 [ V_11 ] ,
V_48 , V_217 ) ;
V_206 -> V_215 [ V_11 ] = 0 ;
}
F_130 ( V_69 ) ;
return - V_218 ;
}
V_206 -> V_215 [ V_11 ] = V_5 ;
}
return 0 ;
}
static void
F_131 ( struct V_110 * V_69 )
{
struct V_205 * V_206 = ( void * ) V_69 ;
struct V_9 * V_10 ;
struct V_207 * V_15 ;
struct V_1 * V_2 ;
struct V_15 * V_208 ;
unsigned V_11 ;
bool V_210 = ! ! ( V_69 -> V_112 & V_211 ) ;
if ( V_210 )
return;
V_10 = F_12 ( V_69 -> V_34 ) ;
V_15 = F_114 ( & V_10 -> V_15 ) ;
V_2 = V_10 -> V_2 ;
V_208 = F_121 ( V_15 ) ;
#if V_115
if ( V_10 -> V_116 . V_117 == V_118 ) {
F_132 ( V_69 ) ;
return;
}
#endif
#ifdef F_123
if ( F_124 () ) {
F_133 ( ( void * ) V_69 , V_2 -> V_2 ) ;
return;
}
#endif
for ( V_11 = 0 ; V_11 < V_69 -> V_72 ; V_11 ++ ) {
if ( V_206 -> V_215 [ V_11 ] ) {
F_129 ( V_208 , V_206 -> V_215 [ V_11 ] , V_48 ,
V_217 ) ;
}
}
F_130 ( V_69 ) ;
}
void
F_134 ( struct V_35 * V_36 , struct V_29 * V_20 )
{
struct V_29 * V_219 = F_9 ( V_20 ) ;
struct V_29 * V_220 = NULL ;
F_5 ( & V_36 -> V_33 . V_34 -> V_194 ) ;
V_220 = V_36 -> V_33 . V_178 ;
V_36 -> V_33 . V_178 = V_219 ;
F_7 ( & V_36 -> V_33 . V_34 -> V_194 ) ;
F_3 ( & V_220 ) ;
}
static void
F_135 ( void * * V_178 )
{
F_3 ( (struct V_29 * * ) V_178 ) ;
}
static void *
F_136 ( void * V_178 )
{
return F_9 ( V_178 ) ;
}
static bool
F_137 ( void * V_178 )
{
return F_6 ( V_178 ) ;
}
static int
F_138 ( void * V_178 , bool V_221 , bool V_172 )
{
return F_139 ( V_178 , V_221 , V_172 ) ;
}
static int
F_140 ( void * V_178 )
{
return 0 ;
}
struct V_190 *
F_141 ( struct V_35 * V_36 , struct V_222 * V_59 )
{
struct V_190 * V_149 ;
F_102 (vma, &nvbo->vma_list, head) {
if ( V_149 -> V_59 == V_59 )
return V_149 ;
}
return NULL ;
}
int
F_142 ( struct V_35 * V_36 , struct V_222 * V_59 ,
struct V_190 * V_149 )
{
const T_1 V_6 = V_36 -> V_33 . V_71 . V_72 << V_73 ;
int V_54 ;
V_54 = F_80 ( V_59 , V_6 , V_36 -> V_47 ,
V_170 , V_149 ) ;
if ( V_54 )
return V_54 ;
if ( V_36 -> V_33 . V_71 . V_96 != V_122 &&
( V_36 -> V_33 . V_71 . V_96 == V_97 ||
V_36 -> V_47 != V_149 -> V_59 -> V_60 -> V_56 ) )
F_82 ( V_149 , V_36 -> V_33 . V_71 . V_148 ) ;
F_143 ( & V_149 -> V_66 , & V_36 -> V_68 ) ;
V_149 -> V_223 = 1 ;
return 0 ;
}
void
F_144 ( struct V_35 * V_36 , struct V_190 * V_149 )
{
if ( V_149 -> V_147 ) {
if ( V_36 -> V_33 . V_71 . V_96 != V_122 )
F_103 ( V_149 ) ;
F_81 ( V_149 ) ;
F_145 ( & V_149 -> V_66 ) ;
}
}
