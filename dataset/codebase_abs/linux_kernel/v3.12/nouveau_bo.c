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
if ( V_20 ) {
V_12 -> V_20 = V_20 ;
F_8 ( V_20 ) ;
}
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
if ( F_12 ( V_36 -> V_37 ) )
F_13 ( L_1 , V_33 ) ;
F_14 ( V_36 -> V_38 > 0 ) ;
F_7 ( V_2 , V_36 -> V_12 , NULL ) ;
F_15 ( V_36 ) ;
}
static void
F_16 ( struct V_35 * V_36 , T_1 V_8 ,
int * V_39 , int * V_6 )
{
struct V_9 * V_10 = F_11 ( V_36 -> V_33 . V_34 ) ;
struct V_40 * V_15 = F_17 ( V_10 -> V_15 ) ;
if ( V_15 -> V_41 < V_42 ) {
if ( V_36 -> V_43 ) {
if ( V_15 -> V_44 >= 0x40 ) {
* V_39 = 65536 ;
* V_6 = F_18 ( * V_6 , 64 * V_36 -> V_43 ) ;
} else if ( V_15 -> V_44 >= 0x30 ) {
* V_39 = 32768 ;
* V_6 = F_18 ( * V_6 , 64 * V_36 -> V_43 ) ;
} else if ( V_15 -> V_44 >= 0x20 ) {
* V_39 = 16384 ;
* V_6 = F_18 ( * V_6 , 64 * V_36 -> V_43 ) ;
} else if ( V_15 -> V_44 >= 0x10 ) {
* V_39 = 16384 ;
* V_6 = F_18 ( * V_6 , 32 * V_36 -> V_43 ) ;
}
}
} else {
* V_6 = F_18 ( * V_6 , ( 1 << V_36 -> V_45 ) ) ;
* V_39 = F_19 ( ( 1 << V_36 -> V_45 ) , * V_39 ) ;
}
* V_6 = F_18 ( * V_6 , V_46 ) ;
}
int
F_20 ( struct V_1 * V_2 , int V_6 , int V_39 ,
T_2 V_8 , T_2 V_43 , T_2 V_47 ,
struct V_48 * V_49 ,
struct V_35 * * V_50 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_35 * V_36 ;
T_3 V_51 ;
int V_52 ;
int type = V_53 ;
int V_54 = 12 ;
int V_55 ;
if ( V_10 -> V_56 . V_57 . V_58 )
V_54 = V_10 -> V_56 . V_57 . V_58 -> V_59 -> V_54 ;
V_55 = V_60 & ~ ( ( 1 << V_54 ) - 1 ) ;
if ( V_6 <= 0 || V_6 > V_55 ) {
F_21 ( V_10 , L_2 , ( T_1 ) V_6 ) ;
return - V_61 ;
}
if ( V_49 )
type = V_62 ;
V_36 = F_22 ( sizeof( struct V_35 ) , V_63 ) ;
if ( ! V_36 )
return - V_64 ;
F_23 ( & V_36 -> V_65 ) ;
F_23 ( & V_36 -> V_66 ) ;
F_23 ( & V_36 -> V_67 ) ;
V_36 -> V_43 = V_43 ;
V_36 -> V_47 = V_47 ;
V_36 -> V_33 . V_34 = & V_10 -> V_68 . V_34 ;
V_36 -> V_45 = 12 ;
if ( V_10 -> V_56 . V_57 . V_58 ) {
if ( ! ( V_8 & V_69 ) && V_6 > 256 * 1024 )
V_36 -> V_45 = V_10 -> V_56 . V_57 . V_58 -> V_59 -> V_54 ;
}
F_16 ( V_36 , V_8 , & V_39 , & V_6 ) ;
V_36 -> V_33 . V_70 . V_71 = V_6 >> V_72 ;
F_24 ( V_36 , V_8 , 0 ) ;
V_51 = F_25 ( & V_10 -> V_68 . V_34 , V_6 ,
sizeof( struct V_35 ) ) ;
V_52 = F_26 ( & V_10 -> V_68 . V_34 , & V_36 -> V_33 , V_6 ,
type , & V_36 -> V_73 ,
V_39 >> V_72 , false , NULL , V_51 , V_49 ,
F_10 ) ;
if ( V_52 ) {
return V_52 ;
}
* V_50 = V_36 ;
return 0 ;
}
static void
F_27 ( T_2 * V_74 , unsigned * V_75 , T_2 type , T_2 V_8 )
{
* V_75 = 0 ;
if ( type & V_76 )
V_74 [ ( * V_75 ) ++ ] = V_76 | V_8 ;
if ( type & V_69 )
V_74 [ ( * V_75 ) ++ ] = V_69 | V_8 ;
if ( type & V_77 )
V_74 [ ( * V_75 ) ++ ] = V_77 | V_8 ;
}
static void
F_28 ( struct V_35 * V_36 , T_2 type )
{
struct V_9 * V_10 = F_11 ( V_36 -> V_33 . V_34 ) ;
struct V_13 * V_14 = V_13 ( V_10 -> V_15 ) ;
T_1 V_78 = V_14 -> V_79 -> V_6 >> V_72 ;
if ( F_17 ( V_10 -> V_15 ) -> V_41 == V_80 &&
V_36 -> V_43 && ( type & V_76 ) &&
V_36 -> V_33 . V_70 . V_71 < V_78 / 4 ) {
if ( V_36 -> V_47 & V_81 ) {
V_36 -> V_73 . V_82 = V_78 / 2 ;
V_36 -> V_73 . V_83 = ~ 0 ;
} else {
V_36 -> V_73 . V_82 = 0 ;
V_36 -> V_73 . V_83 = V_78 / 2 ;
}
}
}
void
F_24 ( struct V_35 * V_36 , T_2 type , T_2 V_84 )
{
struct V_85 * V_74 = & V_36 -> V_73 ;
T_2 V_8 = V_86 |
( V_36 -> V_38 ? V_87 : 0 ) ;
V_74 -> V_73 = V_36 -> V_88 ;
F_27 ( V_36 -> V_88 , & V_74 -> V_89 ,
type , V_8 ) ;
V_74 -> V_90 = V_36 -> V_91 ;
F_27 ( V_36 -> V_91 , & V_74 -> V_92 ,
type | V_84 , V_8 ) ;
F_28 ( V_36 , type ) ;
}
int
F_29 ( struct V_35 * V_36 , T_2 V_93 )
{
struct V_9 * V_10 = F_11 ( V_36 -> V_33 . V_34 ) ;
struct V_32 * V_33 = & V_36 -> V_33 ;
int V_52 ;
V_52 = F_30 ( V_33 , false , false , false , 0 ) ;
if ( V_52 )
goto V_94;
if ( V_36 -> V_38 && ! ( V_93 & ( 1 << V_33 -> V_70 . V_95 ) ) ) {
F_31 ( V_10 , L_3 , V_33 ,
1 << V_33 -> V_70 . V_95 , V_93 ) ;
V_52 = - V_61 ;
goto V_94;
}
if ( V_36 -> V_38 ++ )
goto V_94;
F_24 ( V_36 , V_93 , 0 ) ;
V_52 = F_32 ( V_36 , false , false ) ;
if ( V_52 == 0 ) {
switch ( V_33 -> V_70 . V_95 ) {
case V_96 :
V_10 -> V_37 . V_97 -= V_33 -> V_70 . V_6 ;
break;
case V_98 :
V_10 -> V_37 . V_99 -= V_33 -> V_70 . V_6 ;
break;
default:
break;
}
}
V_94:
F_33 ( V_33 ) ;
return V_52 ;
}
int
F_34 ( struct V_35 * V_36 )
{
struct V_9 * V_10 = F_11 ( V_36 -> V_33 . V_34 ) ;
struct V_32 * V_33 = & V_36 -> V_33 ;
int V_52 , V_100 ;
V_52 = F_30 ( V_33 , false , false , false , 0 ) ;
if ( V_52 )
return V_52 ;
V_100 = -- V_36 -> V_38 ;
F_35 ( V_100 < 0 ) ;
if ( V_100 )
goto V_94;
F_24 ( V_36 , V_33 -> V_70 . V_73 , 0 ) ;
V_52 = F_32 ( V_36 , false , false ) ;
if ( V_52 == 0 ) {
switch ( V_33 -> V_70 . V_95 ) {
case V_96 :
V_10 -> V_37 . V_97 += V_33 -> V_70 . V_6 ;
break;
case V_98 :
V_10 -> V_37 . V_99 += V_33 -> V_70 . V_6 ;
break;
default:
break;
}
}
V_94:
F_33 ( V_33 ) ;
return V_52 ;
}
int
F_36 ( struct V_35 * V_36 )
{
int V_52 ;
V_52 = F_30 ( & V_36 -> V_33 , false , false , false , 0 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_37 ( & V_36 -> V_33 , 0 , V_36 -> V_33 . V_70 . V_71 , & V_36 -> V_101 ) ;
F_33 ( & V_36 -> V_33 ) ;
return V_52 ;
}
void
F_38 ( struct V_35 * V_36 )
{
if ( V_36 )
F_39 ( & V_36 -> V_101 ) ;
}
int
F_32 ( struct V_35 * V_36 , bool V_102 ,
bool V_103 )
{
int V_52 ;
V_52 = F_40 ( & V_36 -> V_33 , & V_36 -> V_73 ,
V_102 , V_103 ) ;
if ( V_52 )
return V_52 ;
return 0 ;
}
T_4
F_41 ( struct V_35 * V_36 , unsigned V_104 )
{
bool V_105 ;
T_4 * V_70 = F_42 ( & V_36 -> V_101 , & V_105 ) ;
V_70 = & V_70 [ V_104 ] ;
if ( V_105 )
return F_43 ( ( void V_106 V_107 * ) V_70 ) ;
else
return * V_70 ;
}
void
F_44 ( struct V_35 * V_36 , unsigned V_104 , T_4 V_108 )
{
bool V_105 ;
T_4 * V_70 = F_42 ( & V_36 -> V_101 , & V_105 ) ;
V_70 = & V_70 [ V_104 ] ;
if ( V_105 )
F_45 ( V_108 , ( void V_106 V_107 * ) V_70 ) ;
else
* V_70 = V_108 ;
}
T_1
F_46 ( struct V_35 * V_36 , unsigned V_104 )
{
bool V_105 ;
T_1 * V_70 = F_42 ( & V_36 -> V_101 , & V_105 ) ;
V_70 = & V_70 [ V_104 ] ;
if ( V_105 )
return F_47 ( ( void V_106 V_107 * ) V_70 ) ;
else
return * V_70 ;
}
void
F_48 ( struct V_35 * V_36 , unsigned V_104 , T_1 V_108 )
{
bool V_105 ;
T_1 * V_70 = F_42 ( & V_36 -> V_101 , & V_105 ) ;
V_70 = & V_70 [ V_104 ] ;
if ( V_105 )
F_49 ( V_108 , ( void V_106 V_107 * ) V_70 ) ;
else
* V_70 = V_108 ;
}
static struct V_109 *
F_50 ( struct V_110 * V_34 , unsigned long V_6 ,
T_2 V_111 , struct V_112 * V_113 )
{
#if V_114
struct V_9 * V_10 = F_11 ( V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_10 -> V_115 . V_116 == V_117 ) {
return F_51 ( V_34 , V_2 -> V_115 -> V_118 , V_6 ,
V_111 , V_113 ) ;
}
#endif
return F_52 ( V_34 , V_6 , V_111 , V_113 ) ;
}
static int
F_53 ( struct V_110 * V_34 , T_2 V_8 )
{
return 0 ;
}
static int
F_54 ( struct V_110 * V_34 , T_2 type ,
struct V_119 * V_120 )
{
struct V_9 * V_10 = F_11 ( V_34 ) ;
switch ( type ) {
case V_121 :
V_120 -> V_8 = V_122 ;
V_120 -> V_123 = V_86 ;
V_120 -> V_124 = V_125 ;
break;
case V_96 :
if ( F_17 ( V_10 -> V_15 ) -> V_41 >= V_42 ) {
V_120 -> V_126 = & V_127 ;
V_120 -> V_128 = false ;
V_120 -> V_129 = true ;
} else {
V_120 -> V_126 = & V_130 ;
}
V_120 -> V_8 = V_131 |
V_122 ;
V_120 -> V_123 = V_132 |
V_133 ;
V_120 -> V_124 = V_133 ;
break;
case V_98 :
if ( F_17 ( V_10 -> V_15 ) -> V_41 >= V_42 )
V_120 -> V_126 = & V_134 ;
else
if ( V_10 -> V_115 . V_116 != V_117 )
V_120 -> V_126 = & V_135 ;
else
V_120 -> V_126 = & V_130 ;
if ( V_10 -> V_115 . V_116 == V_117 ) {
V_120 -> V_8 = V_122 ;
V_120 -> V_123 = V_132 |
V_133 ;
V_120 -> V_124 = V_133 ;
} else {
V_120 -> V_8 = V_122 |
V_136 ;
V_120 -> V_123 = V_86 ;
V_120 -> V_124 = V_125 ;
}
break;
default:
return - V_61 ;
}
return 0 ;
}
static void
F_55 ( struct V_32 * V_33 , struct V_85 * V_74 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
switch ( V_33 -> V_70 . V_95 ) {
case V_96 :
F_24 ( V_36 , V_69 ,
V_77 ) ;
break;
default:
F_24 ( V_36 , V_77 , 0 ) ;
break;
}
* V_74 = V_36 -> V_73 ;
}
static int
F_56 ( struct V_137 * V_138 ,
struct V_35 * V_36 , bool V_139 ,
bool V_103 , struct V_140 * V_141 )
{
struct V_29 * V_20 = NULL ;
int V_52 ;
V_52 = F_57 ( V_138 , false , & V_20 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_58 ( & V_36 -> V_33 , V_20 , V_139 ,
V_103 , V_141 ) ;
F_2 ( & V_20 ) ;
return V_52 ;
}
static int
F_59 ( struct V_137 * V_138 , T_1 V_142 )
{
int V_52 = F_60 ( V_138 , 2 ) ;
if ( V_52 == 0 ) {
F_61 ( V_138 , V_143 , 0x0000 , 1 ) ;
F_62 ( V_138 , V_142 & 0x0000ffff ) ;
F_63 ( V_138 ) ;
}
return V_52 ;
}
static int
F_64 ( struct V_137 * V_138 , struct V_32 * V_33 ,
struct V_140 * V_144 , struct V_140 * V_141 )
{
struct V_145 * V_146 = V_144 -> V_147 ;
int V_52 = F_60 ( V_138 , 10 ) ;
if ( V_52 == 0 ) {
F_61 ( V_138 , V_143 , 0x0400 , 8 ) ;
F_62 ( V_138 , F_65 ( V_146 -> V_148 [ 0 ] . V_149 ) ) ;
F_62 ( V_138 , F_66 ( V_146 -> V_148 [ 0 ] . V_149 ) ) ;
F_62 ( V_138 , F_65 ( V_146 -> V_148 [ 1 ] . V_149 ) ) ;
F_62 ( V_138 , F_66 ( V_146 -> V_148 [ 1 ] . V_149 ) ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_141 -> V_71 ) ;
F_67 ( V_138 , V_143 , 0x0300 , 0x0386 ) ;
}
return V_52 ;
}
static int
F_68 ( struct V_137 * V_138 , T_1 V_142 )
{
int V_52 = F_60 ( V_138 , 2 ) ;
if ( V_52 == 0 ) {
F_61 ( V_138 , V_143 , 0x0000 , 1 ) ;
F_62 ( V_138 , V_142 ) ;
}
return V_52 ;
}
static int
F_69 ( struct V_137 * V_138 , struct V_32 * V_33 ,
struct V_140 * V_144 , struct V_140 * V_141 )
{
struct V_145 * V_146 = V_144 -> V_147 ;
T_5 V_150 = V_146 -> V_148 [ 0 ] . V_149 ;
T_5 V_151 = V_146 -> V_148 [ 1 ] . V_149 ;
T_1 V_152 = V_141 -> V_71 ;
int V_52 ;
V_152 = V_141 -> V_71 ;
while ( V_152 ) {
int V_153 = ( V_152 > 8191 ) ? 8191 : V_152 ;
V_52 = F_60 ( V_138 , 11 ) ;
if ( V_52 )
return V_52 ;
F_61 ( V_138 , V_143 , 0x030c , 8 ) ;
F_62 ( V_138 , F_65 ( V_150 ) ) ;
F_62 ( V_138 , F_66 ( V_150 ) ) ;
F_62 ( V_138 , F_65 ( V_151 ) ) ;
F_62 ( V_138 , F_66 ( V_151 ) ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_153 ) ;
F_61 ( V_138 , V_143 , 0x0300 , 1 ) ;
F_62 ( V_138 , 0x00000110 ) ;
V_152 -= V_153 ;
V_150 += ( V_46 * V_153 ) ;
V_151 += ( V_46 * V_153 ) ;
}
return 0 ;
}
static int
F_70 ( struct V_137 * V_138 , struct V_32 * V_33 ,
struct V_140 * V_144 , struct V_140 * V_141 )
{
struct V_145 * V_146 = V_144 -> V_147 ;
T_5 V_150 = V_146 -> V_148 [ 0 ] . V_149 ;
T_5 V_151 = V_146 -> V_148 [ 1 ] . V_149 ;
T_1 V_152 = V_141 -> V_71 ;
int V_52 ;
V_152 = V_141 -> V_71 ;
while ( V_152 ) {
int V_153 = ( V_152 > 2047 ) ? 2047 : V_152 ;
V_52 = F_60 ( V_138 , 12 ) ;
if ( V_52 )
return V_52 ;
F_61 ( V_138 , V_143 , 0x0238 , 2 ) ;
F_62 ( V_138 , F_65 ( V_151 ) ) ;
F_62 ( V_138 , F_66 ( V_151 ) ) ;
F_61 ( V_138 , V_143 , 0x030c , 6 ) ;
F_62 ( V_138 , F_65 ( V_150 ) ) ;
F_62 ( V_138 , F_66 ( V_150 ) ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_153 ) ;
F_61 ( V_138 , V_143 , 0x0300 , 1 ) ;
F_62 ( V_138 , 0x00100110 ) ;
V_152 -= V_153 ;
V_150 += ( V_46 * V_153 ) ;
V_151 += ( V_46 * V_153 ) ;
}
return 0 ;
}
static int
F_71 ( struct V_137 * V_138 , struct V_32 * V_33 ,
struct V_140 * V_144 , struct V_140 * V_141 )
{
struct V_145 * V_146 = V_144 -> V_147 ;
T_5 V_150 = V_146 -> V_148 [ 0 ] . V_149 ;
T_5 V_151 = V_146 -> V_148 [ 1 ] . V_149 ;
T_1 V_152 = V_141 -> V_71 ;
int V_52 ;
V_152 = V_141 -> V_71 ;
while ( V_152 ) {
int V_153 = ( V_152 > 8191 ) ? 8191 : V_152 ;
V_52 = F_60 ( V_138 , 11 ) ;
if ( V_52 )
return V_52 ;
F_72 ( V_138 , V_143 , 0x030c , 8 ) ;
F_62 ( V_138 , F_65 ( V_150 ) ) ;
F_62 ( V_138 , F_66 ( V_150 ) ) ;
F_62 ( V_138 , F_65 ( V_151 ) ) ;
F_62 ( V_138 , F_66 ( V_151 ) ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_153 ) ;
F_72 ( V_138 , V_143 , 0x0300 , 1 ) ;
F_62 ( V_138 , 0x00000110 ) ;
V_152 -= V_153 ;
V_150 += ( V_46 * V_153 ) ;
V_151 += ( V_46 * V_153 ) ;
}
return 0 ;
}
static int
F_73 ( struct V_137 * V_138 , struct V_32 * V_33 ,
struct V_140 * V_144 , struct V_140 * V_141 )
{
struct V_145 * V_146 = V_144 -> V_147 ;
int V_52 = F_60 ( V_138 , 7 ) ;
if ( V_52 == 0 ) {
F_72 ( V_138 , V_143 , 0x0320 , 6 ) ;
F_62 ( V_138 , F_65 ( V_146 -> V_148 [ 0 ] . V_149 ) ) ;
F_62 ( V_138 , F_66 ( V_146 -> V_148 [ 0 ] . V_149 ) ) ;
F_62 ( V_138 , F_65 ( V_146 -> V_148 [ 1 ] . V_149 ) ) ;
F_62 ( V_138 , F_66 ( V_146 -> V_148 [ 1 ] . V_149 ) ) ;
F_62 ( V_138 , 0x00000000 ) ;
F_62 ( V_138 , V_141 -> V_71 << V_72 ) ;
}
return V_52 ;
}
static int
F_74 ( struct V_137 * V_138 , struct V_32 * V_33 ,
struct V_140 * V_144 , struct V_140 * V_141 )
{
struct V_145 * V_146 = V_144 -> V_147 ;
int V_52 = F_60 ( V_138 , 7 ) ;
if ( V_52 == 0 ) {
F_72 ( V_138 , V_143 , 0x0304 , 6 ) ;
F_62 ( V_138 , V_141 -> V_71 << V_72 ) ;
F_62 ( V_138 , F_65 ( V_146 -> V_148 [ 0 ] . V_149 ) ) ;
F_62 ( V_138 , F_66 ( V_146 -> V_148 [ 0 ] . V_149 ) ) ;
F_62 ( V_138 , F_65 ( V_146 -> V_148 [ 1 ] . V_149 ) ) ;
F_62 ( V_138 , F_66 ( V_146 -> V_148 [ 1 ] . V_149 ) ) ;
F_62 ( V_138 , 0x00000000 ) ;
}
return V_52 ;
}
static int
F_75 ( struct V_137 * V_138 , T_1 V_142 )
{
int V_52 = F_60 ( V_138 , 6 ) ;
if ( V_52 == 0 ) {
F_72 ( V_138 , V_143 , 0x0000 , 1 ) ;
F_62 ( V_138 , V_142 ) ;
F_72 ( V_138 , V_143 , 0x0180 , 3 ) ;
F_62 ( V_138 , V_154 ) ;
F_62 ( V_138 , V_155 ) ;
F_62 ( V_138 , V_155 ) ;
}
return V_52 ;
}
static int
F_76 ( struct V_137 * V_138 , struct V_32 * V_33 ,
struct V_140 * V_144 , struct V_140 * V_141 )
{
struct V_145 * V_146 = V_144 -> V_147 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
T_5 V_156 = ( V_141 -> V_71 << V_72 ) ;
T_5 V_150 = V_146 -> V_148 [ 0 ] . V_149 ;
T_5 V_151 = V_146 -> V_148 [ 1 ] . V_149 ;
int V_52 ;
while ( V_156 ) {
T_1 V_157 , V_158 , V_159 ;
V_157 = F_77 ( V_156 , ( T_5 ) ( 4 * 1024 * 1024 ) ) ;
V_158 = 16 * 4 ;
V_159 = V_157 / V_158 ;
if ( V_144 -> V_95 == V_96 &&
F_78 ( V_36 ) ) {
V_52 = F_60 ( V_138 , 8 ) ;
if ( V_52 )
return V_52 ;
F_72 ( V_138 , V_143 , 0x0200 , 7 ) ;
F_62 ( V_138 , 0 ) ;
F_62 ( V_138 , 0 ) ;
F_62 ( V_138 , V_158 ) ;
F_62 ( V_138 , V_159 ) ;
F_62 ( V_138 , 1 ) ;
F_62 ( V_138 , 0 ) ;
F_62 ( V_138 , 0 ) ;
} else {
V_52 = F_60 ( V_138 , 2 ) ;
if ( V_52 )
return V_52 ;
F_72 ( V_138 , V_143 , 0x0200 , 1 ) ;
F_62 ( V_138 , 1 ) ;
}
if ( V_141 -> V_95 == V_96 &&
F_78 ( V_36 ) ) {
V_52 = F_60 ( V_138 , 8 ) ;
if ( V_52 )
return V_52 ;
F_72 ( V_138 , V_143 , 0x021c , 7 ) ;
F_62 ( V_138 , 0 ) ;
F_62 ( V_138 , 0 ) ;
F_62 ( V_138 , V_158 ) ;
F_62 ( V_138 , V_159 ) ;
F_62 ( V_138 , 1 ) ;
F_62 ( V_138 , 0 ) ;
F_62 ( V_138 , 0 ) ;
} else {
V_52 = F_60 ( V_138 , 2 ) ;
if ( V_52 )
return V_52 ;
F_72 ( V_138 , V_143 , 0x021c , 1 ) ;
F_62 ( V_138 , 1 ) ;
}
V_52 = F_60 ( V_138 , 14 ) ;
if ( V_52 )
return V_52 ;
F_72 ( V_138 , V_143 , 0x0238 , 2 ) ;
F_62 ( V_138 , F_65 ( V_150 ) ) ;
F_62 ( V_138 , F_65 ( V_151 ) ) ;
F_72 ( V_138 , V_143 , 0x030c , 8 ) ;
F_62 ( V_138 , F_66 ( V_150 ) ) ;
F_62 ( V_138 , F_66 ( V_151 ) ) ;
F_62 ( V_138 , V_158 ) ;
F_62 ( V_138 , V_158 ) ;
F_62 ( V_138 , V_158 ) ;
F_62 ( V_138 , V_159 ) ;
F_62 ( V_138 , 0x00000101 ) ;
F_62 ( V_138 , 0x00000000 ) ;
F_72 ( V_138 , V_143 , V_160 , 1 ) ;
F_62 ( V_138 , 0 ) ;
V_156 -= V_157 ;
V_150 += V_157 ;
V_151 += V_157 ;
}
return 0 ;
}
static int
F_79 ( struct V_137 * V_138 , T_1 V_142 )
{
int V_52 = F_60 ( V_138 , 4 ) ;
if ( V_52 == 0 ) {
F_72 ( V_138 , V_143 , 0x0000 , 1 ) ;
F_62 ( V_138 , V_142 ) ;
F_72 ( V_138 , V_143 , 0x0180 , 1 ) ;
F_62 ( V_138 , V_154 ) ;
}
return V_52 ;
}
static inline T_2
F_80 ( struct V_32 * V_33 ,
struct V_137 * V_138 , struct V_140 * V_70 )
{
if ( V_70 -> V_95 == V_98 )
return V_161 ;
return V_155 ;
}
static int
F_81 ( struct V_137 * V_138 , struct V_32 * V_33 ,
struct V_140 * V_144 , struct V_140 * V_141 )
{
T_1 V_150 = V_144 -> V_162 << V_72 ;
T_1 V_151 = V_141 -> V_162 << V_72 ;
T_1 V_152 = V_141 -> V_71 ;
int V_52 ;
V_52 = F_60 ( V_138 , 3 ) ;
if ( V_52 )
return V_52 ;
F_72 ( V_138 , V_143 , V_163 , 2 ) ;
F_62 ( V_138 , F_80 ( V_33 , V_138 , V_144 ) ) ;
F_62 ( V_138 , F_80 ( V_33 , V_138 , V_141 ) ) ;
V_152 = V_141 -> V_71 ;
while ( V_152 ) {
int V_153 = ( V_152 > 2047 ) ? 2047 : V_152 ;
V_52 = F_60 ( V_138 , 11 ) ;
if ( V_52 )
return V_52 ;
F_72 ( V_138 , V_143 ,
V_164 , 8 ) ;
F_62 ( V_138 , V_150 ) ;
F_62 ( V_138 , V_151 ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_46 ) ;
F_62 ( V_138 , V_153 ) ;
F_62 ( V_138 , 0x00000101 ) ;
F_62 ( V_138 , 0x00000000 ) ;
F_72 ( V_138 , V_143 , V_160 , 1 ) ;
F_62 ( V_138 , 0 ) ;
V_152 -= V_153 ;
V_150 += ( V_46 * V_153 ) ;
V_151 += ( V_46 * V_153 ) ;
}
return 0 ;
}
static int
F_82 ( struct V_137 * V_138 , struct V_35 * V_36 ,
struct V_140 * V_70 , struct V_165 * V_148 )
{
struct V_145 * V_146 = V_70 -> V_147 ;
int V_52 ;
V_52 = F_83 ( F_84 ( V_138 -> V_166 ) -> V_58 , V_70 -> V_71 <<
V_72 , V_146 -> V_45 ,
V_167 , V_148 ) ;
if ( V_52 )
return V_52 ;
if ( V_70 -> V_95 == V_96 )
F_85 ( V_148 , V_146 ) ;
else
F_86 ( V_148 , 0 , V_70 -> V_71 << V_72 , V_146 ) ;
return 0 ;
}
static int
F_87 ( struct V_32 * V_33 , int V_139 , bool V_168 ,
bool V_103 , struct V_140 * V_141 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_137 * V_138 = V_138 = V_10 -> V_68 . V_138 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_140 * V_144 = & V_33 -> V_70 ;
int V_52 ;
F_88 ( & V_138 -> V_166 -> V_169 , V_170 ) ;
if ( F_17 ( V_10 -> V_15 ) -> V_41 >= V_42 ) {
struct V_145 * V_146 = V_144 -> V_147 ;
V_52 = F_82 ( V_138 , V_36 , V_144 , & V_146 -> V_148 [ 0 ] ) ;
if ( V_52 )
goto V_94;
V_52 = F_82 ( V_138 , V_36 , V_141 , & V_146 -> V_148 [ 1 ] ) ;
if ( V_52 )
goto V_94;
}
V_52 = V_10 -> V_68 . V_171 ( V_138 , V_33 , & V_33 -> V_70 , V_141 ) ;
if ( V_52 == 0 ) {
V_52 = F_56 ( V_138 , V_36 , V_139 ,
V_103 , V_141 ) ;
}
V_94:
F_89 ( & V_138 -> V_166 -> V_169 ) ;
return V_52 ;
}
void
F_90 ( struct V_9 * V_10 )
{
static const struct {
const char * V_172 ;
int V_19 ;
T_1 V_173 ;
int (* F_91)( struct V_137 * ,
struct V_32 * ,
struct V_140 * , struct V_140 * );
int (* V_22)( struct V_137 * , T_1 V_142 );
} V_174 [] = {
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
} , * V_175 = V_174 ;
const char * V_172 = L_10 ;
int V_52 ;
do {
struct V_176 * V_177 ;
struct V_137 * V_138 ;
T_1 V_142 = ( V_175 -> V_19 << 16 ) | V_175 -> V_173 ;
if ( V_175 -> V_19 )
V_138 = V_10 -> V_178 ;
else
V_138 = V_10 -> V_179 ;
if ( V_138 == NULL )
continue;
V_52 = F_92 ( F_93 ( V_10 ) , V_138 -> V_142 , V_142 ,
V_175 -> V_173 , NULL , 0 , & V_177 ) ;
if ( V_52 == 0 ) {
V_52 = V_175 -> V_22 ( V_138 , V_142 ) ;
if ( V_52 ) {
F_94 ( F_93 ( V_10 ) ,
V_138 -> V_142 , V_142 ) ;
continue;
}
V_10 -> V_68 . V_171 = V_175 -> F_91 ;
V_10 -> V_68 . V_138 = V_138 ;
V_172 = V_175 -> V_172 ;
break;
}
} while ( ( ++ V_175 ) -> F_91 );
F_95 ( V_10 , L_11 , V_172 ) ;
}
static int
F_96 ( struct V_32 * V_33 , bool V_139 , bool V_168 ,
bool V_103 , struct V_140 * V_141 )
{
T_1 V_180 = V_69 | V_86 ;
struct V_85 V_73 ;
struct V_140 V_181 ;
int V_52 ;
V_73 . V_82 = V_73 . V_83 = 0 ;
V_73 . V_89 = V_73 . V_92 = 1 ;
V_73 . V_73 = V_73 . V_90 = & V_180 ;
V_181 = * V_141 ;
V_181 . V_147 = NULL ;
V_52 = F_97 ( V_33 , & V_73 , & V_181 , V_168 , V_103 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_98 ( V_33 -> V_68 , & V_181 ) ;
if ( V_52 )
goto V_94;
V_52 = F_87 ( V_33 , true , V_168 , V_103 , & V_181 ) ;
if ( V_52 )
goto V_94;
V_52 = F_99 ( V_33 , true , V_103 , V_141 ) ;
V_94:
F_100 ( V_33 , & V_181 ) ;
return V_52 ;
}
static int
F_101 ( struct V_32 * V_33 , bool V_139 , bool V_168 ,
bool V_103 , struct V_140 * V_141 )
{
T_1 V_180 = V_69 | V_86 ;
struct V_85 V_73 ;
struct V_140 V_181 ;
int V_52 ;
V_73 . V_82 = V_73 . V_83 = 0 ;
V_73 . V_89 = V_73 . V_92 = 1 ;
V_73 . V_73 = V_73 . V_90 = & V_180 ;
V_181 = * V_141 ;
V_181 . V_147 = NULL ;
V_52 = F_97 ( V_33 , & V_73 , & V_181 , V_168 , V_103 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_99 ( V_33 , true , V_103 , & V_181 ) ;
if ( V_52 )
goto V_94;
V_52 = F_87 ( V_33 , true , V_168 , V_103 , V_141 ) ;
if ( V_52 )
goto V_94;
V_94:
F_100 ( V_33 , & V_181 ) ;
return V_52 ;
}
static void
F_102 ( struct V_32 * V_33 , struct V_140 * V_141 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_165 * V_148 ;
if ( V_33 -> V_182 != F_10 )
return;
F_103 (vma, &nvbo->vma_list, head) {
if ( V_141 && V_141 -> V_95 == V_96 ) {
F_85 ( V_148 , V_141 -> V_147 ) ;
} else
if ( V_141 && V_141 -> V_95 == V_98 &&
V_36 -> V_45 == V_148 -> V_58 -> V_59 -> V_183 ) {
if ( ( (struct V_145 * ) V_141 -> V_147 ) -> V_49 )
F_104 ( V_148 , 0 , V_141 ->
V_71 << V_72 ,
V_141 -> V_147 ) ;
else
F_86 ( V_148 , 0 , V_141 ->
V_71 << V_72 ,
V_141 -> V_147 ) ;
} else {
F_105 ( V_148 ) ;
}
}
}
static int
F_106 ( struct V_32 * V_33 , struct V_140 * V_141 ,
struct V_3 * * V_184 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
T_5 V_149 = V_141 -> V_162 << V_72 ;
* V_184 = NULL ;
if ( V_141 -> V_95 != V_96 )
return 0 ;
if ( F_17 ( V_10 -> V_15 ) -> V_41 >= V_80 ) {
* V_184 = F_9 ( V_2 , V_149 , V_141 -> V_6 ,
V_36 -> V_43 ,
V_36 -> V_47 ) ;
}
return 0 ;
}
static void
F_107 ( struct V_32 * V_33 ,
struct V_3 * V_184 ,
struct V_3 * * V_185 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_7 ( V_2 , * V_185 , V_33 -> V_186 ) ;
* V_185 = V_184 ;
}
static int
F_108 ( struct V_32 * V_33 , bool V_139 , bool V_168 ,
bool V_103 , struct V_140 * V_141 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_140 * V_144 = & V_33 -> V_70 ;
struct V_3 * V_184 = NULL ;
int V_52 = 0 ;
if ( F_17 ( V_10 -> V_15 ) -> V_41 < V_42 ) {
V_52 = F_106 ( V_33 , V_141 , & V_184 ) ;
if ( V_52 )
return V_52 ;
}
if ( V_144 -> V_95 == V_121 && ! V_33 -> V_68 ) {
F_109 ( V_33 -> V_70 . V_147 != NULL ) ;
V_33 -> V_70 = * V_141 ;
V_141 -> V_147 = NULL ;
goto V_94;
}
if ( ! V_10 -> V_68 . V_171 ) {
V_52 = F_110 ( V_33 , V_139 , V_103 , V_141 ) ;
goto V_94;
}
if ( V_141 -> V_95 == V_121 )
V_52 = F_96 ( V_33 , V_139 , V_168 ,
V_103 , V_141 ) ;
else if ( V_144 -> V_95 == V_121 )
V_52 = F_101 ( V_33 , V_139 , V_168 ,
V_103 , V_141 ) ;
else
V_52 = F_87 ( V_33 , V_139 , V_168 ,
V_103 , V_141 ) ;
if ( ! V_52 )
goto V_94;
V_52 = F_110 ( V_33 , V_139 , V_103 , V_141 ) ;
V_94:
if ( F_17 ( V_10 -> V_15 ) -> V_41 < V_42 ) {
if ( V_52 )
F_107 ( V_33 , NULL , & V_184 ) ;
else
F_107 ( V_33 , V_184 , & V_36 -> V_12 ) ;
}
return V_52 ;
}
static int
F_111 ( struct V_32 * V_33 , struct V_187 * V_188 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
return F_112 ( & V_36 -> V_37 -> V_189 , V_188 ) ;
}
static int
F_113 ( struct V_110 * V_34 , struct V_140 * V_70 )
{
struct V_119 * V_120 = & V_34 -> V_120 [ V_70 -> V_95 ] ;
struct V_9 * V_10 = F_11 ( V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_52 ;
V_70 -> V_190 . V_5 = NULL ;
V_70 -> V_190 . V_149 = 0 ;
V_70 -> V_190 . V_6 = V_70 -> V_71 << V_72 ;
V_70 -> V_190 . V_57 = 0 ;
V_70 -> V_190 . V_105 = false ;
if ( ! ( V_120 -> V_8 & V_122 ) )
return - V_61 ;
switch ( V_70 -> V_95 ) {
case V_121 :
return 0 ;
case V_98 :
#if V_114
if ( V_10 -> V_115 . V_116 == V_117 ) {
V_70 -> V_190 . V_149 = V_70 -> V_162 << V_72 ;
V_70 -> V_190 . V_57 = V_10 -> V_115 . V_57 ;
V_70 -> V_190 . V_105 = ! V_2 -> V_115 -> V_191 ;
}
#endif
break;
case V_96 :
V_70 -> V_190 . V_149 = V_70 -> V_162 << V_72 ;
V_70 -> V_190 . V_57 = F_114 ( V_2 -> V_192 , 1 ) ;
V_70 -> V_190 . V_105 = true ;
if ( F_17 ( V_10 -> V_15 ) -> V_41 >= V_42 ) {
struct V_193 * V_194 = V_193 ( V_10 -> V_15 ) ;
struct V_145 * V_146 = V_70 -> V_147 ;
V_52 = V_194 -> V_195 ( V_194 , V_146 , V_167 ,
& V_146 -> V_196 ) ;
if ( V_52 )
return V_52 ;
V_70 -> V_190 . V_149 = V_146 -> V_196 . V_149 ;
}
break;
default:
return - V_61 ;
}
return 0 ;
}
static void
F_115 ( struct V_110 * V_34 , struct V_140 * V_70 )
{
struct V_9 * V_10 = F_11 ( V_34 ) ;
struct V_193 * V_194 = V_193 ( V_10 -> V_15 ) ;
struct V_145 * V_146 = V_70 -> V_147 ;
if ( ! V_146 -> V_196 . V_146 )
return;
V_194 -> V_197 ( V_194 , & V_146 -> V_196 ) ;
}
static int
F_116 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_40 * V_15 = F_17 ( V_10 -> V_15 ) ;
T_1 V_198 = F_117 ( V_15 -> V_192 , 1 ) >> V_72 ;
if ( V_33 -> V_70 . V_95 != V_96 ) {
if ( F_17 ( V_10 -> V_15 ) -> V_41 < V_42 ||
! F_78 ( V_36 ) )
return 0 ;
}
if ( V_33 -> V_70 . V_162 + V_33 -> V_70 . V_71 < V_198 )
return 0 ;
V_36 -> V_73 . V_82 = 0 ;
V_36 -> V_73 . V_83 = V_198 ;
F_24 ( V_36 , V_76 , 0 ) ;
return F_32 ( V_36 , false , false ) ;
}
static int
F_118 ( struct V_109 * V_68 )
{
struct V_199 * V_200 = ( void * ) V_68 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned V_11 ;
int V_201 ;
bool V_202 = ! ! ( V_68 -> V_111 & V_203 ) ;
if ( V_68 -> V_204 != V_205 )
return 0 ;
if ( V_202 && V_68 -> V_49 ) {
F_119 ( V_68 -> V_49 , V_68 -> V_206 ,
V_200 -> V_207 , V_68 -> V_71 ) ;
V_68 -> V_204 = V_208 ;
return 0 ;
}
V_10 = F_11 ( V_68 -> V_34 ) ;
V_2 = V_10 -> V_2 ;
#if V_114
if ( V_10 -> V_115 . V_116 == V_117 ) {
return F_120 ( V_68 ) ;
}
#endif
#ifdef F_121
if ( F_122 () ) {
return F_123 ( ( void * ) V_68 , V_2 -> V_2 ) ;
}
#endif
V_201 = F_124 ( V_68 ) ;
if ( V_201 ) {
return V_201 ;
}
for ( V_11 = 0 ; V_11 < V_68 -> V_71 ; V_11 ++ ) {
V_200 -> V_207 [ V_11 ] = F_125 ( V_2 -> V_192 , V_68 -> V_206 [ V_11 ] ,
0 , V_46 ,
V_209 ) ;
if ( F_126 ( V_2 -> V_192 , V_200 -> V_207 [ V_11 ] ) ) {
while ( -- V_11 ) {
F_127 ( V_2 -> V_192 , V_200 -> V_207 [ V_11 ] ,
V_46 , V_209 ) ;
V_200 -> V_207 [ V_11 ] = 0 ;
}
F_128 ( V_68 ) ;
return - V_210 ;
}
}
return 0 ;
}
static void
F_129 ( struct V_109 * V_68 )
{
struct V_199 * V_200 = ( void * ) V_68 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned V_11 ;
bool V_202 = ! ! ( V_68 -> V_111 & V_203 ) ;
if ( V_202 )
return;
V_10 = F_11 ( V_68 -> V_34 ) ;
V_2 = V_10 -> V_2 ;
#if V_114
if ( V_10 -> V_115 . V_116 == V_117 ) {
F_130 ( V_68 ) ;
return;
}
#endif
#ifdef F_121
if ( F_122 () ) {
F_131 ( ( void * ) V_68 , V_2 -> V_2 ) ;
return;
}
#endif
for ( V_11 = 0 ; V_11 < V_68 -> V_71 ; V_11 ++ ) {
if ( V_200 -> V_207 [ V_11 ] ) {
F_127 ( V_2 -> V_192 , V_200 -> V_207 [ V_11 ] ,
V_46 , V_209 ) ;
}
}
F_128 ( V_68 ) ;
}
void
F_132 ( struct V_35 * V_36 , struct V_29 * V_20 )
{
struct V_29 * V_211 = NULL ;
if ( F_133 ( V_20 ) )
F_8 ( V_20 ) ;
F_4 ( & V_36 -> V_33 . V_34 -> V_212 ) ;
V_211 = V_36 -> V_33 . V_186 ;
V_36 -> V_33 . V_186 = V_20 ;
F_6 ( & V_36 -> V_33 . V_34 -> V_212 ) ;
F_2 ( & V_211 ) ;
}
static void
F_134 ( void * * V_186 )
{
F_2 ( (struct V_29 * * ) V_186 ) ;
}
static void *
F_135 ( void * V_186 )
{
return F_8 ( V_186 ) ;
}
static bool
F_136 ( void * V_186 )
{
return F_5 ( V_186 ) ;
}
static int
F_137 ( void * V_186 , bool V_213 , bool V_168 )
{
return F_138 ( V_186 , V_213 , V_168 ) ;
}
static int
F_139 ( void * V_186 )
{
return 0 ;
}
struct V_165 *
F_140 ( struct V_35 * V_36 , struct V_214 * V_58 )
{
struct V_165 * V_148 ;
F_103 (vma, &nvbo->vma_list, head) {
if ( V_148 -> V_58 == V_58 )
return V_148 ;
}
return NULL ;
}
int
F_141 ( struct V_35 * V_36 , struct V_214 * V_58 ,
struct V_165 * V_148 )
{
const T_1 V_6 = V_36 -> V_33 . V_70 . V_71 << V_72 ;
struct V_145 * V_146 = V_36 -> V_33 . V_70 . V_147 ;
int V_52 ;
V_52 = F_83 ( V_58 , V_6 , V_36 -> V_45 ,
V_167 , V_148 ) ;
if ( V_52 )
return V_52 ;
if ( V_36 -> V_33 . V_70 . V_95 == V_96 )
F_85 ( V_148 , V_36 -> V_33 . V_70 . V_147 ) ;
else if ( V_36 -> V_33 . V_70 . V_95 == V_98 ) {
if ( V_146 -> V_49 )
F_104 ( V_148 , 0 , V_6 , V_146 ) ;
else
F_86 ( V_148 , 0 , V_6 , V_146 ) ;
}
F_142 ( & V_148 -> V_65 , & V_36 -> V_67 ) ;
V_148 -> V_215 = 1 ;
return 0 ;
}
void
F_143 ( struct V_35 * V_36 , struct V_165 * V_148 )
{
if ( V_148 -> V_146 ) {
if ( V_36 -> V_33 . V_70 . V_95 != V_121 )
F_105 ( V_148 ) ;
F_144 ( V_148 ) ;
F_145 ( & V_148 -> V_65 ) ;
}
}
