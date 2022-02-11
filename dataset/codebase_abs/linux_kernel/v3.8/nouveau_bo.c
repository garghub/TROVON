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
F_7 ( V_2 , V_36 -> V_12 , NULL ) ;
F_14 ( V_36 ) ;
}
static void
F_15 ( struct V_35 * V_36 , T_1 V_8 ,
int * V_38 , int * V_6 )
{
struct V_9 * V_10 = F_11 ( V_36 -> V_33 . V_34 ) ;
struct V_39 * V_15 = F_16 ( V_10 -> V_15 ) ;
if ( V_15 -> V_40 < V_41 ) {
if ( V_36 -> V_42 ) {
if ( V_15 -> V_43 >= 0x40 ) {
* V_38 = 65536 ;
* V_6 = F_17 ( * V_6 , 64 * V_36 -> V_42 ) ;
} else if ( V_15 -> V_43 >= 0x30 ) {
* V_38 = 32768 ;
* V_6 = F_17 ( * V_6 , 64 * V_36 -> V_42 ) ;
} else if ( V_15 -> V_43 >= 0x20 ) {
* V_38 = 16384 ;
* V_6 = F_17 ( * V_6 , 64 * V_36 -> V_42 ) ;
} else if ( V_15 -> V_43 >= 0x10 ) {
* V_38 = 16384 ;
* V_6 = F_17 ( * V_6 , 32 * V_36 -> V_42 ) ;
}
}
} else {
* V_6 = F_17 ( * V_6 , ( 1 << V_36 -> V_44 ) ) ;
* V_38 = F_18 ( ( 1 << V_36 -> V_44 ) , * V_38 ) ;
}
* V_6 = F_17 ( * V_6 , V_45 ) ;
}
int
F_19 ( struct V_1 * V_2 , int V_6 , int V_38 ,
T_2 V_8 , T_2 V_42 , T_2 V_46 ,
struct V_47 * V_48 ,
struct V_35 * * V_49 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_35 * V_36 ;
T_3 V_50 ;
int V_51 ;
int type = V_52 ;
if ( V_48 )
type = V_53 ;
V_36 = F_20 ( sizeof( struct V_35 ) , V_54 ) ;
if ( ! V_36 )
return - V_55 ;
F_21 ( & V_36 -> V_56 ) ;
F_21 ( & V_36 -> V_57 ) ;
F_21 ( & V_36 -> V_58 ) ;
V_36 -> V_42 = V_42 ;
V_36 -> V_46 = V_46 ;
V_36 -> V_33 . V_34 = & V_10 -> V_59 . V_34 ;
V_36 -> V_44 = 12 ;
if ( V_10 -> V_60 . V_61 . V_62 ) {
if ( ! ( V_8 & V_63 ) && V_6 > 256 * 1024 )
V_36 -> V_44 = V_10 -> V_60 . V_61 . V_62 -> V_64 -> V_65 ;
}
F_15 ( V_36 , V_8 , & V_38 , & V_6 ) ;
V_36 -> V_33 . V_66 . V_67 = V_6 >> V_68 ;
F_22 ( V_36 , V_8 , 0 ) ;
V_50 = F_23 ( & V_10 -> V_59 . V_34 , V_6 ,
sizeof( struct V_35 ) ) ;
V_51 = F_24 ( & V_10 -> V_59 . V_34 , & V_36 -> V_33 , V_6 ,
type , & V_36 -> V_69 ,
V_38 >> V_68 , false , NULL , V_50 , V_48 ,
F_10 ) ;
if ( V_51 ) {
return V_51 ;
}
* V_49 = V_36 ;
return 0 ;
}
static void
F_25 ( T_2 * V_70 , unsigned * V_71 , T_2 type , T_2 V_8 )
{
* V_71 = 0 ;
if ( type & V_72 )
V_70 [ ( * V_71 ) ++ ] = V_72 | V_8 ;
if ( type & V_63 )
V_70 [ ( * V_71 ) ++ ] = V_63 | V_8 ;
if ( type & V_73 )
V_70 [ ( * V_71 ) ++ ] = V_73 | V_8 ;
}
static void
F_26 ( struct V_35 * V_36 , T_2 type )
{
struct V_9 * V_10 = F_11 ( V_36 -> V_33 . V_34 ) ;
struct V_13 * V_14 = V_13 ( V_10 -> V_15 ) ;
T_1 V_74 = V_14 -> V_75 . V_6 >> V_68 ;
if ( F_16 ( V_10 -> V_15 ) -> V_40 == V_76 &&
V_36 -> V_42 && ( type & V_72 ) &&
V_36 -> V_33 . V_66 . V_67 < V_74 / 4 ) {
if ( V_36 -> V_46 & V_77 ) {
V_36 -> V_69 . V_78 = V_74 / 2 ;
V_36 -> V_69 . V_79 = ~ 0 ;
} else {
V_36 -> V_69 . V_78 = 0 ;
V_36 -> V_69 . V_79 = V_74 / 2 ;
}
}
}
void
F_22 ( struct V_35 * V_36 , T_2 type , T_2 V_80 )
{
struct V_81 * V_70 = & V_36 -> V_69 ;
T_2 V_8 = V_82 |
( V_36 -> V_83 ? V_84 : 0 ) ;
V_70 -> V_69 = V_36 -> V_85 ;
F_25 ( V_36 -> V_85 , & V_70 -> V_86 ,
type , V_8 ) ;
V_70 -> V_87 = V_36 -> V_88 ;
F_25 ( V_36 -> V_88 , & V_70 -> V_89 ,
type | V_80 , V_8 ) ;
F_26 ( V_36 , type ) ;
}
int
F_27 ( struct V_35 * V_36 , T_2 V_90 )
{
struct V_9 * V_10 = F_11 ( V_36 -> V_33 . V_34 ) ;
struct V_32 * V_33 = & V_36 -> V_33 ;
int V_51 ;
if ( V_36 -> V_83 && ! ( V_90 & ( 1 << V_33 -> V_66 . V_91 ) ) ) {
F_28 ( V_10 , L_2 , V_33 ,
1 << V_33 -> V_66 . V_91 , V_90 ) ;
return - V_92 ;
}
if ( V_36 -> V_83 ++ )
return 0 ;
V_51 = F_29 ( V_33 , false , false , false , 0 ) ;
if ( V_51 )
goto V_93;
F_22 ( V_36 , V_90 , 0 ) ;
V_51 = F_30 ( V_36 , false , false ) ;
if ( V_51 == 0 ) {
switch ( V_33 -> V_66 . V_91 ) {
case V_94 :
V_10 -> V_37 . V_95 -= V_33 -> V_66 . V_6 ;
break;
case V_96 :
V_10 -> V_37 . V_97 -= V_33 -> V_66 . V_6 ;
break;
default:
break;
}
}
F_31 ( V_33 ) ;
V_93:
if ( F_12 ( V_51 ) )
V_36 -> V_83 -- ;
return V_51 ;
}
int
F_32 ( struct V_35 * V_36 )
{
struct V_9 * V_10 = F_11 ( V_36 -> V_33 . V_34 ) ;
struct V_32 * V_33 = & V_36 -> V_33 ;
int V_51 ;
if ( -- V_36 -> V_83 )
return 0 ;
V_51 = F_29 ( V_33 , false , false , false , 0 ) ;
if ( V_51 )
return V_51 ;
F_22 ( V_36 , V_33 -> V_66 . V_69 , 0 ) ;
V_51 = F_30 ( V_36 , false , false ) ;
if ( V_51 == 0 ) {
switch ( V_33 -> V_66 . V_91 ) {
case V_94 :
V_10 -> V_37 . V_95 += V_33 -> V_66 . V_6 ;
break;
case V_96 :
V_10 -> V_37 . V_97 += V_33 -> V_66 . V_6 ;
break;
default:
break;
}
}
F_31 ( V_33 ) ;
return V_51 ;
}
int
F_33 ( struct V_35 * V_36 )
{
int V_51 ;
V_51 = F_29 ( & V_36 -> V_33 , false , false , false , 0 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_34 ( & V_36 -> V_33 , 0 , V_36 -> V_33 . V_66 . V_67 , & V_36 -> V_98 ) ;
F_31 ( & V_36 -> V_33 ) ;
return V_51 ;
}
void
F_35 ( struct V_35 * V_36 )
{
if ( V_36 )
F_36 ( & V_36 -> V_98 ) ;
}
int
F_30 ( struct V_35 * V_36 , bool V_99 ,
bool V_100 )
{
int V_51 ;
V_51 = F_37 ( & V_36 -> V_33 , & V_36 -> V_69 ,
V_99 , V_100 ) ;
if ( V_51 )
return V_51 ;
return 0 ;
}
T_4
F_38 ( struct V_35 * V_36 , unsigned V_101 )
{
bool V_102 ;
T_4 * V_66 = F_39 ( & V_36 -> V_98 , & V_102 ) ;
V_66 = & V_66 [ V_101 ] ;
if ( V_102 )
return F_40 ( ( void V_103 V_104 * ) V_66 ) ;
else
return * V_66 ;
}
void
F_41 ( struct V_35 * V_36 , unsigned V_101 , T_4 V_105 )
{
bool V_102 ;
T_4 * V_66 = F_39 ( & V_36 -> V_98 , & V_102 ) ;
V_66 = & V_66 [ V_101 ] ;
if ( V_102 )
F_42 ( V_105 , ( void V_103 V_104 * ) V_66 ) ;
else
* V_66 = V_105 ;
}
T_1
F_43 ( struct V_35 * V_36 , unsigned V_101 )
{
bool V_102 ;
T_1 * V_66 = F_39 ( & V_36 -> V_98 , & V_102 ) ;
V_66 = & V_66 [ V_101 ] ;
if ( V_102 )
return F_44 ( ( void V_103 V_104 * ) V_66 ) ;
else
return * V_66 ;
}
void
F_45 ( struct V_35 * V_36 , unsigned V_101 , T_1 V_105 )
{
bool V_102 ;
T_1 * V_66 = F_39 ( & V_36 -> V_98 , & V_102 ) ;
V_66 = & V_66 [ V_101 ] ;
if ( V_102 )
F_46 ( V_105 , ( void V_103 V_104 * ) V_66 ) ;
else
* V_66 = V_105 ;
}
static struct V_106 *
F_47 ( struct V_107 * V_34 , unsigned long V_6 ,
T_2 V_108 , struct V_109 * V_110 )
{
#if V_111
struct V_9 * V_10 = F_11 ( V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_10 -> V_112 . V_113 == V_114 ) {
return F_48 ( V_34 , V_2 -> V_112 -> V_115 , V_6 ,
V_108 , V_110 ) ;
}
#endif
return F_49 ( V_34 , V_6 , V_108 , V_110 ) ;
}
static int
F_50 ( struct V_107 * V_34 , T_2 V_8 )
{
return 0 ;
}
static int
F_51 ( struct V_107 * V_34 , T_2 type ,
struct V_116 * V_117 )
{
struct V_9 * V_10 = F_11 ( V_34 ) ;
switch ( type ) {
case V_118 :
V_117 -> V_8 = V_119 ;
V_117 -> V_120 = V_82 ;
V_117 -> V_121 = V_122 ;
break;
case V_94 :
if ( F_16 ( V_10 -> V_15 ) -> V_40 >= V_41 ) {
V_117 -> V_123 = & V_124 ;
V_117 -> V_125 = false ;
V_117 -> V_126 = true ;
} else {
V_117 -> V_123 = & V_127 ;
}
V_117 -> V_8 = V_128 |
V_119 ;
V_117 -> V_120 = V_129 |
V_130 ;
V_117 -> V_121 = V_130 ;
break;
case V_96 :
if ( F_16 ( V_10 -> V_15 ) -> V_40 >= V_41 )
V_117 -> V_123 = & V_131 ;
else
if ( V_10 -> V_112 . V_113 != V_114 )
V_117 -> V_123 = & V_132 ;
else
V_117 -> V_123 = & V_127 ;
if ( V_10 -> V_112 . V_113 == V_114 ) {
V_117 -> V_8 = V_119 ;
V_117 -> V_120 = V_129 |
V_130 ;
V_117 -> V_121 = V_130 ;
} else {
V_117 -> V_8 = V_119 |
V_133 ;
V_117 -> V_120 = V_82 ;
V_117 -> V_121 = V_122 ;
}
break;
default:
return - V_92 ;
}
return 0 ;
}
static void
F_52 ( struct V_32 * V_33 , struct V_81 * V_70 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
switch ( V_33 -> V_66 . V_91 ) {
case V_94 :
F_22 ( V_36 , V_63 ,
V_73 ) ;
break;
default:
F_22 ( V_36 , V_73 , 0 ) ;
break;
}
* V_70 = V_36 -> V_69 ;
}
static int
F_53 ( struct V_134 * V_135 ,
struct V_35 * V_36 , bool V_136 ,
bool V_100 , struct V_137 * V_138 )
{
struct V_29 * V_20 = NULL ;
int V_51 ;
V_51 = F_54 ( V_135 , & V_20 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_55 ( & V_36 -> V_33 , V_20 , V_136 ,
V_100 , V_138 ) ;
F_2 ( & V_20 ) ;
return V_51 ;
}
static int
F_56 ( struct V_134 * V_135 , T_1 V_139 )
{
int V_51 = F_57 ( V_135 , 2 ) ;
if ( V_51 == 0 ) {
F_58 ( V_135 , V_140 , 0x0000 , 1 ) ;
F_59 ( V_135 , V_139 ) ;
F_60 ( V_135 ) ;
}
return V_51 ;
}
static int
F_61 ( struct V_134 * V_135 , struct V_32 * V_33 ,
struct V_137 * V_141 , struct V_137 * V_138 )
{
struct V_142 * V_143 = V_141 -> V_144 ;
int V_51 = F_57 ( V_135 , 10 ) ;
if ( V_51 == 0 ) {
F_58 ( V_135 , V_140 , 0x0400 , 8 ) ;
F_59 ( V_135 , F_62 ( V_143 -> V_145 [ 0 ] . V_146 ) ) ;
F_59 ( V_135 , F_63 ( V_143 -> V_145 [ 0 ] . V_146 ) ) ;
F_59 ( V_135 , F_62 ( V_143 -> V_145 [ 1 ] . V_146 ) ) ;
F_59 ( V_135 , F_63 ( V_143 -> V_145 [ 1 ] . V_146 ) ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_138 -> V_67 ) ;
F_64 ( V_135 , V_140 , 0x0300 , 0x0386 ) ;
}
return V_51 ;
}
static int
F_65 ( struct V_134 * V_135 , T_1 V_139 )
{
int V_51 = F_57 ( V_135 , 2 ) ;
if ( V_51 == 0 ) {
F_58 ( V_135 , V_140 , 0x0000 , 1 ) ;
F_59 ( V_135 , V_139 ) ;
}
return V_51 ;
}
static int
F_66 ( struct V_134 * V_135 , struct V_32 * V_33 ,
struct V_137 * V_141 , struct V_137 * V_138 )
{
struct V_142 * V_143 = V_141 -> V_144 ;
T_5 V_147 = V_143 -> V_145 [ 0 ] . V_146 ;
T_5 V_148 = V_143 -> V_145 [ 1 ] . V_146 ;
T_1 V_149 = V_138 -> V_67 ;
int V_51 ;
V_149 = V_138 -> V_67 ;
while ( V_149 ) {
int V_150 = ( V_149 > 8191 ) ? 8191 : V_149 ;
V_51 = F_57 ( V_135 , 11 ) ;
if ( V_51 )
return V_51 ;
F_58 ( V_135 , V_140 , 0x030c , 8 ) ;
F_59 ( V_135 , F_62 ( V_147 ) ) ;
F_59 ( V_135 , F_63 ( V_147 ) ) ;
F_59 ( V_135 , F_62 ( V_148 ) ) ;
F_59 ( V_135 , F_63 ( V_148 ) ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_150 ) ;
F_58 ( V_135 , V_140 , 0x0300 , 1 ) ;
F_59 ( V_135 , 0x00000110 ) ;
V_149 -= V_150 ;
V_147 += ( V_45 * V_150 ) ;
V_148 += ( V_45 * V_150 ) ;
}
return 0 ;
}
static int
F_67 ( struct V_134 * V_135 , struct V_32 * V_33 ,
struct V_137 * V_141 , struct V_137 * V_138 )
{
struct V_142 * V_143 = V_141 -> V_144 ;
T_5 V_147 = V_143 -> V_145 [ 0 ] . V_146 ;
T_5 V_148 = V_143 -> V_145 [ 1 ] . V_146 ;
T_1 V_149 = V_138 -> V_67 ;
int V_51 ;
V_149 = V_138 -> V_67 ;
while ( V_149 ) {
int V_150 = ( V_149 > 2047 ) ? 2047 : V_149 ;
V_51 = F_57 ( V_135 , 12 ) ;
if ( V_51 )
return V_51 ;
F_58 ( V_135 , V_140 , 0x0238 , 2 ) ;
F_59 ( V_135 , F_62 ( V_148 ) ) ;
F_59 ( V_135 , F_63 ( V_148 ) ) ;
F_58 ( V_135 , V_140 , 0x030c , 6 ) ;
F_59 ( V_135 , F_62 ( V_147 ) ) ;
F_59 ( V_135 , F_63 ( V_147 ) ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_150 ) ;
F_58 ( V_135 , V_140 , 0x0300 , 1 ) ;
F_59 ( V_135 , 0x00100110 ) ;
V_149 -= V_150 ;
V_147 += ( V_45 * V_150 ) ;
V_148 += ( V_45 * V_150 ) ;
}
return 0 ;
}
static int
F_68 ( struct V_134 * V_135 , struct V_32 * V_33 ,
struct V_137 * V_141 , struct V_137 * V_138 )
{
struct V_142 * V_143 = V_141 -> V_144 ;
T_5 V_147 = V_143 -> V_145 [ 0 ] . V_146 ;
T_5 V_148 = V_143 -> V_145 [ 1 ] . V_146 ;
T_1 V_149 = V_138 -> V_67 ;
int V_51 ;
V_149 = V_138 -> V_67 ;
while ( V_149 ) {
int V_150 = ( V_149 > 8191 ) ? 8191 : V_149 ;
V_51 = F_57 ( V_135 , 11 ) ;
if ( V_51 )
return V_51 ;
F_69 ( V_135 , V_140 , 0x030c , 8 ) ;
F_59 ( V_135 , F_62 ( V_147 ) ) ;
F_59 ( V_135 , F_63 ( V_147 ) ) ;
F_59 ( V_135 , F_62 ( V_148 ) ) ;
F_59 ( V_135 , F_63 ( V_148 ) ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_150 ) ;
F_69 ( V_135 , V_140 , 0x0300 , 1 ) ;
F_59 ( V_135 , 0x00000110 ) ;
V_149 -= V_150 ;
V_147 += ( V_45 * V_150 ) ;
V_148 += ( V_45 * V_150 ) ;
}
return 0 ;
}
static int
F_70 ( struct V_134 * V_135 , struct V_32 * V_33 ,
struct V_137 * V_141 , struct V_137 * V_138 )
{
struct V_142 * V_143 = V_141 -> V_144 ;
int V_51 = F_57 ( V_135 , 7 ) ;
if ( V_51 == 0 ) {
F_69 ( V_135 , V_140 , 0x0320 , 6 ) ;
F_59 ( V_135 , F_62 ( V_143 -> V_145 [ 0 ] . V_146 ) ) ;
F_59 ( V_135 , F_63 ( V_143 -> V_145 [ 0 ] . V_146 ) ) ;
F_59 ( V_135 , F_62 ( V_143 -> V_145 [ 1 ] . V_146 ) ) ;
F_59 ( V_135 , F_63 ( V_143 -> V_145 [ 1 ] . V_146 ) ) ;
F_59 ( V_135 , 0x00000000 ) ;
F_59 ( V_135 , V_138 -> V_67 << V_68 ) ;
}
return V_51 ;
}
static int
F_71 ( struct V_134 * V_135 , struct V_32 * V_33 ,
struct V_137 * V_141 , struct V_137 * V_138 )
{
struct V_142 * V_143 = V_141 -> V_144 ;
int V_51 = F_57 ( V_135 , 7 ) ;
if ( V_51 == 0 ) {
F_69 ( V_135 , V_140 , 0x0304 , 6 ) ;
F_59 ( V_135 , V_138 -> V_67 << V_68 ) ;
F_59 ( V_135 , F_62 ( V_143 -> V_145 [ 0 ] . V_146 ) ) ;
F_59 ( V_135 , F_63 ( V_143 -> V_145 [ 0 ] . V_146 ) ) ;
F_59 ( V_135 , F_62 ( V_143 -> V_145 [ 1 ] . V_146 ) ) ;
F_59 ( V_135 , F_63 ( V_143 -> V_145 [ 1 ] . V_146 ) ) ;
F_59 ( V_135 , 0x00000000 ) ;
}
return V_51 ;
}
static int
F_72 ( struct V_134 * V_135 , T_1 V_139 )
{
int V_51 = F_57 ( V_135 , 6 ) ;
if ( V_51 == 0 ) {
F_69 ( V_135 , V_140 , 0x0000 , 1 ) ;
F_59 ( V_135 , V_139 ) ;
F_69 ( V_135 , V_140 , 0x0180 , 3 ) ;
F_59 ( V_135 , V_151 ) ;
F_59 ( V_135 , V_152 ) ;
F_59 ( V_135 , V_152 ) ;
}
return V_51 ;
}
static int
F_73 ( struct V_134 * V_135 , struct V_32 * V_33 ,
struct V_137 * V_141 , struct V_137 * V_138 )
{
struct V_142 * V_143 = V_141 -> V_144 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
T_5 V_153 = ( V_138 -> V_67 << V_68 ) ;
T_5 V_147 = V_143 -> V_145 [ 0 ] . V_146 ;
T_5 V_148 = V_143 -> V_145 [ 1 ] . V_146 ;
int V_51 ;
while ( V_153 ) {
T_1 V_154 , V_155 , V_156 ;
V_154 = F_74 ( V_153 , ( T_5 ) ( 4 * 1024 * 1024 ) ) ;
V_155 = 16 * 4 ;
V_156 = V_154 / V_155 ;
if ( V_138 -> V_91 == V_94 &&
F_75 ( V_36 ) ) {
V_51 = F_57 ( V_135 , 8 ) ;
if ( V_51 )
return V_51 ;
F_69 ( V_135 , V_140 , 0x0200 , 7 ) ;
F_59 ( V_135 , 0 ) ;
F_59 ( V_135 , 0 ) ;
F_59 ( V_135 , V_155 ) ;
F_59 ( V_135 , V_156 ) ;
F_59 ( V_135 , 1 ) ;
F_59 ( V_135 , 0 ) ;
F_59 ( V_135 , 0 ) ;
} else {
V_51 = F_57 ( V_135 , 2 ) ;
if ( V_51 )
return V_51 ;
F_69 ( V_135 , V_140 , 0x0200 , 1 ) ;
F_59 ( V_135 , 1 ) ;
}
if ( V_141 -> V_91 == V_94 &&
F_75 ( V_36 ) ) {
V_51 = F_57 ( V_135 , 8 ) ;
if ( V_51 )
return V_51 ;
F_69 ( V_135 , V_140 , 0x021c , 7 ) ;
F_59 ( V_135 , 0 ) ;
F_59 ( V_135 , 0 ) ;
F_59 ( V_135 , V_155 ) ;
F_59 ( V_135 , V_156 ) ;
F_59 ( V_135 , 1 ) ;
F_59 ( V_135 , 0 ) ;
F_59 ( V_135 , 0 ) ;
} else {
V_51 = F_57 ( V_135 , 2 ) ;
if ( V_51 )
return V_51 ;
F_69 ( V_135 , V_140 , 0x021c , 1 ) ;
F_59 ( V_135 , 1 ) ;
}
V_51 = F_57 ( V_135 , 14 ) ;
if ( V_51 )
return V_51 ;
F_69 ( V_135 , V_140 , 0x0238 , 2 ) ;
F_59 ( V_135 , F_62 ( V_147 ) ) ;
F_59 ( V_135 , F_62 ( V_148 ) ) ;
F_69 ( V_135 , V_140 , 0x030c , 8 ) ;
F_59 ( V_135 , F_63 ( V_147 ) ) ;
F_59 ( V_135 , F_63 ( V_148 ) ) ;
F_59 ( V_135 , V_155 ) ;
F_59 ( V_135 , V_155 ) ;
F_59 ( V_135 , V_155 ) ;
F_59 ( V_135 , V_156 ) ;
F_59 ( V_135 , 0x00000101 ) ;
F_59 ( V_135 , 0x00000000 ) ;
F_69 ( V_135 , V_140 , V_157 , 1 ) ;
F_59 ( V_135 , 0 ) ;
V_153 -= V_154 ;
V_147 += V_154 ;
V_148 += V_154 ;
}
return 0 ;
}
static int
F_76 ( struct V_134 * V_135 , T_1 V_139 )
{
int V_51 = F_57 ( V_135 , 4 ) ;
if ( V_51 == 0 ) {
F_69 ( V_135 , V_140 , 0x0000 , 1 ) ;
F_59 ( V_135 , V_139 ) ;
F_69 ( V_135 , V_140 , 0x0180 , 1 ) ;
F_59 ( V_135 , V_151 ) ;
}
return V_51 ;
}
static inline T_2
F_77 ( struct V_32 * V_33 ,
struct V_134 * V_135 , struct V_137 * V_66 )
{
if ( V_66 -> V_91 == V_96 )
return V_158 ;
return V_152 ;
}
static int
F_78 ( struct V_134 * V_135 , struct V_32 * V_33 ,
struct V_137 * V_141 , struct V_137 * V_138 )
{
T_1 V_147 = V_141 -> V_159 << V_68 ;
T_1 V_148 = V_138 -> V_159 << V_68 ;
T_1 V_149 = V_138 -> V_67 ;
int V_51 ;
V_51 = F_57 ( V_135 , 3 ) ;
if ( V_51 )
return V_51 ;
F_69 ( V_135 , V_140 , V_160 , 2 ) ;
F_59 ( V_135 , F_77 ( V_33 , V_135 , V_141 ) ) ;
F_59 ( V_135 , F_77 ( V_33 , V_135 , V_138 ) ) ;
V_149 = V_138 -> V_67 ;
while ( V_149 ) {
int V_150 = ( V_149 > 2047 ) ? 2047 : V_149 ;
V_51 = F_57 ( V_135 , 11 ) ;
if ( V_51 )
return V_51 ;
F_69 ( V_135 , V_140 ,
V_161 , 8 ) ;
F_59 ( V_135 , V_147 ) ;
F_59 ( V_135 , V_148 ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_45 ) ;
F_59 ( V_135 , V_150 ) ;
F_59 ( V_135 , 0x00000101 ) ;
F_59 ( V_135 , 0x00000000 ) ;
F_69 ( V_135 , V_140 , V_157 , 1 ) ;
F_59 ( V_135 , 0 ) ;
V_149 -= V_150 ;
V_147 += ( V_45 * V_150 ) ;
V_148 += ( V_45 * V_150 ) ;
}
return 0 ;
}
static int
F_79 ( struct V_134 * V_135 , struct V_35 * V_36 ,
struct V_137 * V_66 , struct V_162 * V_145 )
{
struct V_142 * V_143 = V_66 -> V_144 ;
int V_51 ;
V_51 = F_80 ( F_81 ( V_135 -> V_163 ) -> V_62 , V_66 -> V_67 <<
V_68 , V_143 -> V_44 ,
V_164 , V_145 ) ;
if ( V_51 )
return V_51 ;
if ( V_66 -> V_91 == V_94 )
F_82 ( V_145 , V_143 ) ;
else
F_83 ( V_145 , 0 , V_66 -> V_67 << V_68 , V_143 ) ;
return 0 ;
}
static int
F_84 ( struct V_32 * V_33 , int V_136 , bool V_165 ,
bool V_100 , struct V_137 * V_138 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_134 * V_135 = V_135 = V_10 -> V_166 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_137 * V_141 = & V_33 -> V_66 ;
int V_51 ;
F_85 ( & V_135 -> V_163 -> V_167 ) ;
if ( F_16 ( V_10 -> V_15 ) -> V_40 >= V_41 ) {
struct V_142 * V_143 = V_141 -> V_144 ;
V_51 = F_79 ( V_135 , V_36 , V_141 , & V_143 -> V_145 [ 0 ] ) ;
if ( V_51 )
goto V_93;
V_51 = F_79 ( V_135 , V_36 , V_138 , & V_143 -> V_145 [ 1 ] ) ;
if ( V_51 )
goto V_93;
}
V_51 = V_10 -> V_59 . V_168 ( V_135 , V_33 , & V_33 -> V_66 , V_138 ) ;
if ( V_51 == 0 ) {
V_51 = F_53 ( V_135 , V_36 , V_136 ,
V_100 , V_138 ) ;
}
V_93:
F_86 ( & V_135 -> V_163 -> V_167 ) ;
return V_51 ;
}
void
F_87 ( struct V_9 * V_10 )
{
static const struct {
const char * V_169 ;
int V_19 ;
T_1 V_170 ;
int (* F_88)( struct V_134 * ,
struct V_32 * ,
struct V_137 * , struct V_137 * );
int (* V_22)( struct V_134 * , T_1 V_139 );
} V_171 [] = {
{ L_3 , 0 , 0xa0b5 , F_61 , F_56 } ,
{ L_4 , 0 , 0xa0b5 , F_61 , F_65 } ,
{ L_5 , 5 , 0x90b8 , F_66 , F_65 } ,
{ L_6 , 4 , 0x90b5 , F_66 , F_65 } ,
{ L_3 , 0 , 0x85b5 , F_68 , F_72 } ,
{ L_7 , 0 , 0x74c1 , F_71 , F_72 } ,
{ L_8 , 0 , 0x9039 , F_67 , F_65 } ,
{ L_8 , 0 , 0x5039 , F_73 , F_72 } ,
{ L_8 , 0 , 0x0039 , F_78 , F_76 } ,
{} ,
{ L_7 , 0 , 0x88b4 , F_70 , F_72 } ,
} , * V_172 = V_171 ;
const char * V_169 = L_9 ;
int V_51 ;
do {
struct V_173 * V_174 ;
struct V_134 * V_135 ;
T_1 V_139 = ( V_172 -> V_19 << 16 ) | V_172 -> V_170 ;
if ( V_172 -> V_22 == F_56 )
V_135 = V_10 -> V_175 ;
else
V_135 = V_10 -> V_166 ;
if ( V_135 == NULL )
continue;
V_51 = F_89 ( F_90 ( V_10 ) , V_135 -> V_139 , V_139 ,
V_172 -> V_170 , NULL , 0 , & V_174 ) ;
if ( V_51 == 0 ) {
V_51 = V_172 -> V_22 ( V_135 , V_139 ) ;
if ( V_51 ) {
F_91 ( F_90 ( V_10 ) ,
V_135 -> V_139 , V_139 ) ;
continue;
}
V_10 -> V_59 . V_168 = V_172 -> F_88 ;
V_169 = V_172 -> V_169 ;
break;
}
} while ( ( ++ V_172 ) -> F_88 );
F_92 ( V_10 , L_10 , V_169 ) ;
}
static int
F_93 ( struct V_32 * V_33 , bool V_136 , bool V_165 ,
bool V_100 , struct V_137 * V_138 )
{
T_1 V_176 = V_63 | V_82 ;
struct V_81 V_69 ;
struct V_137 V_177 ;
int V_51 ;
V_69 . V_78 = V_69 . V_79 = 0 ;
V_69 . V_86 = V_69 . V_89 = 1 ;
V_69 . V_69 = V_69 . V_87 = & V_176 ;
V_177 = * V_138 ;
V_177 . V_144 = NULL ;
V_51 = F_94 ( V_33 , & V_69 , & V_177 , V_165 , V_100 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_95 ( V_33 -> V_59 , & V_177 ) ;
if ( V_51 )
goto V_93;
V_51 = F_84 ( V_33 , true , V_165 , V_100 , & V_177 ) ;
if ( V_51 )
goto V_93;
V_51 = F_96 ( V_33 , true , V_100 , V_138 ) ;
V_93:
F_97 ( V_33 , & V_177 ) ;
return V_51 ;
}
static int
F_98 ( struct V_32 * V_33 , bool V_136 , bool V_165 ,
bool V_100 , struct V_137 * V_138 )
{
T_1 V_176 = V_63 | V_82 ;
struct V_81 V_69 ;
struct V_137 V_177 ;
int V_51 ;
V_69 . V_78 = V_69 . V_79 = 0 ;
V_69 . V_86 = V_69 . V_89 = 1 ;
V_69 . V_69 = V_69 . V_87 = & V_176 ;
V_177 = * V_138 ;
V_177 . V_144 = NULL ;
V_51 = F_94 ( V_33 , & V_69 , & V_177 , V_165 , V_100 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_96 ( V_33 , true , V_100 , & V_177 ) ;
if ( V_51 )
goto V_93;
V_51 = F_84 ( V_33 , true , V_165 , V_100 , V_138 ) ;
if ( V_51 )
goto V_93;
V_93:
F_97 ( V_33 , & V_177 ) ;
return V_51 ;
}
static void
F_99 ( struct V_32 * V_33 , struct V_137 * V_138 )
{
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_162 * V_145 ;
if ( V_33 -> V_178 != F_10 )
return;
F_100 (vma, &nvbo->vma_list, head) {
if ( V_138 && V_138 -> V_91 == V_94 ) {
F_82 ( V_145 , V_138 -> V_144 ) ;
} else
if ( V_138 && V_138 -> V_91 == V_96 &&
V_36 -> V_44 == V_145 -> V_62 -> V_64 -> V_179 ) {
if ( ( (struct V_142 * ) V_138 -> V_144 ) -> V_48 )
F_101 ( V_145 , 0 , V_138 ->
V_67 << V_68 ,
V_138 -> V_144 ) ;
else
F_83 ( V_145 , 0 , V_138 ->
V_67 << V_68 ,
V_138 -> V_144 ) ;
} else {
F_102 ( V_145 ) ;
}
}
}
static int
F_103 ( struct V_32 * V_33 , struct V_137 * V_138 ,
struct V_3 * * V_180 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
T_5 V_146 = V_138 -> V_159 << V_68 ;
* V_180 = NULL ;
if ( V_138 -> V_91 != V_94 )
return 0 ;
if ( F_16 ( V_10 -> V_15 ) -> V_40 >= V_76 ) {
* V_180 = F_9 ( V_2 , V_146 , V_138 -> V_6 ,
V_36 -> V_42 ,
V_36 -> V_46 ) ;
}
return 0 ;
}
static void
F_104 ( struct V_32 * V_33 ,
struct V_3 * V_180 ,
struct V_3 * * V_181 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_7 ( V_2 , * V_181 , V_33 -> V_182 ) ;
* V_181 = V_180 ;
}
static int
F_105 ( struct V_32 * V_33 , bool V_136 , bool V_165 ,
bool V_100 , struct V_137 * V_138 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_137 * V_141 = & V_33 -> V_66 ;
struct V_3 * V_180 = NULL ;
int V_51 = 0 ;
if ( F_16 ( V_10 -> V_15 ) -> V_40 < V_41 ) {
V_51 = F_103 ( V_33 , V_138 , & V_180 ) ;
if ( V_51 )
return V_51 ;
}
if ( V_141 -> V_91 == V_118 && ! V_33 -> V_59 ) {
F_106 ( V_33 -> V_66 . V_144 != NULL ) ;
V_33 -> V_66 = * V_138 ;
V_138 -> V_144 = NULL ;
goto V_93;
}
if ( ! V_10 -> V_59 . V_168 ) {
V_51 = F_107 ( V_33 , V_136 , V_100 , V_138 ) ;
goto V_93;
}
if ( V_138 -> V_91 == V_118 )
V_51 = F_93 ( V_33 , V_136 , V_165 ,
V_100 , V_138 ) ;
else if ( V_141 -> V_91 == V_118 )
V_51 = F_98 ( V_33 , V_136 , V_165 ,
V_100 , V_138 ) ;
else
V_51 = F_84 ( V_33 , V_136 , V_165 ,
V_100 , V_138 ) ;
if ( ! V_51 )
goto V_93;
V_51 = F_107 ( V_33 , V_136 , V_100 , V_138 ) ;
V_93:
if ( F_16 ( V_10 -> V_15 ) -> V_40 < V_41 ) {
if ( V_51 )
F_104 ( V_33 , NULL , & V_180 ) ;
else
F_104 ( V_33 , V_180 , & V_36 -> V_12 ) ;
}
return V_51 ;
}
static int
F_108 ( struct V_32 * V_33 , struct V_183 * V_184 )
{
return 0 ;
}
static int
F_109 ( struct V_107 * V_34 , struct V_137 * V_66 )
{
struct V_116 * V_117 = & V_34 -> V_117 [ V_66 -> V_91 ] ;
struct V_9 * V_10 = F_11 ( V_34 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_51 ;
V_66 -> V_185 . V_5 = NULL ;
V_66 -> V_185 . V_146 = 0 ;
V_66 -> V_185 . V_6 = V_66 -> V_67 << V_68 ;
V_66 -> V_185 . V_61 = 0 ;
V_66 -> V_185 . V_102 = false ;
if ( ! ( V_117 -> V_8 & V_119 ) )
return - V_92 ;
switch ( V_66 -> V_91 ) {
case V_118 :
return 0 ;
case V_96 :
#if V_111
if ( V_10 -> V_112 . V_113 == V_114 ) {
V_66 -> V_185 . V_146 = V_66 -> V_159 << V_68 ;
V_66 -> V_185 . V_61 = V_10 -> V_112 . V_61 ;
V_66 -> V_185 . V_102 = ! V_2 -> V_112 -> V_186 ;
}
#endif
break;
case V_94 :
V_66 -> V_185 . V_146 = V_66 -> V_159 << V_68 ;
V_66 -> V_185 . V_61 = F_110 ( V_2 -> V_187 , 1 ) ;
V_66 -> V_185 . V_102 = true ;
if ( F_16 ( V_10 -> V_15 ) -> V_40 >= V_41 ) {
struct V_188 * V_189 = V_188 ( V_10 -> V_15 ) ;
struct V_142 * V_143 = V_66 -> V_144 ;
V_51 = V_189 -> V_190 ( V_189 , V_143 , V_164 ,
& V_143 -> V_191 ) ;
if ( V_51 )
return V_51 ;
V_66 -> V_185 . V_146 = V_143 -> V_191 . V_146 ;
}
break;
default:
return - V_92 ;
}
return 0 ;
}
static void
F_111 ( struct V_107 * V_34 , struct V_137 * V_66 )
{
struct V_9 * V_10 = F_11 ( V_34 ) ;
struct V_188 * V_189 = V_188 ( V_10 -> V_15 ) ;
struct V_142 * V_143 = V_66 -> V_144 ;
if ( ! V_143 -> V_191 . V_143 )
return;
V_189 -> V_192 ( V_189 , & V_143 -> V_191 ) ;
}
static int
F_112 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = F_11 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_35 ( V_33 ) ;
struct V_39 * V_15 = F_16 ( V_10 -> V_15 ) ;
T_1 V_193 = F_113 ( V_15 -> V_187 , 1 ) >> V_68 ;
if ( V_33 -> V_66 . V_91 != V_94 ) {
if ( F_16 ( V_10 -> V_15 ) -> V_40 < V_41 ||
! F_75 ( V_36 ) )
return 0 ;
}
if ( V_33 -> V_66 . V_159 + V_33 -> V_66 . V_67 < V_193 )
return 0 ;
V_36 -> V_69 . V_78 = 0 ;
V_36 -> V_69 . V_79 = V_193 ;
F_22 ( V_36 , V_72 , 0 ) ;
return F_30 ( V_36 , false , false ) ;
}
static int
F_114 ( struct V_106 * V_59 )
{
struct V_194 * V_195 = ( void * ) V_59 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned V_11 ;
int V_196 ;
bool V_197 = ! ! ( V_59 -> V_108 & V_198 ) ;
if ( V_59 -> V_199 != V_200 )
return 0 ;
if ( V_197 && V_59 -> V_48 ) {
F_115 ( V_59 -> V_48 , V_59 -> V_201 ,
V_195 -> V_202 , V_59 -> V_67 ) ;
V_59 -> V_199 = V_203 ;
return 0 ;
}
V_10 = F_11 ( V_59 -> V_34 ) ;
V_2 = V_10 -> V_2 ;
#if V_111
if ( V_10 -> V_112 . V_113 == V_114 ) {
return F_116 ( V_59 ) ;
}
#endif
#ifdef F_117
if ( F_118 () ) {
return F_119 ( ( void * ) V_59 , V_2 -> V_2 ) ;
}
#endif
V_196 = F_120 ( V_59 ) ;
if ( V_196 ) {
return V_196 ;
}
for ( V_11 = 0 ; V_11 < V_59 -> V_67 ; V_11 ++ ) {
V_195 -> V_202 [ V_11 ] = F_121 ( V_2 -> V_187 , V_59 -> V_201 [ V_11 ] ,
0 , V_45 ,
V_204 ) ;
if ( F_122 ( V_2 -> V_187 , V_195 -> V_202 [ V_11 ] ) ) {
while ( -- V_11 ) {
F_123 ( V_2 -> V_187 , V_195 -> V_202 [ V_11 ] ,
V_45 , V_204 ) ;
V_195 -> V_202 [ V_11 ] = 0 ;
}
F_124 ( V_59 ) ;
return - V_205 ;
}
}
return 0 ;
}
static void
F_125 ( struct V_106 * V_59 )
{
struct V_194 * V_195 = ( void * ) V_59 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned V_11 ;
bool V_197 = ! ! ( V_59 -> V_108 & V_198 ) ;
if ( V_197 )
return;
V_10 = F_11 ( V_59 -> V_34 ) ;
V_2 = V_10 -> V_2 ;
#if V_111
if ( V_10 -> V_112 . V_113 == V_114 ) {
F_126 ( V_59 ) ;
return;
}
#endif
#ifdef F_117
if ( F_118 () ) {
F_127 ( ( void * ) V_59 , V_2 -> V_2 ) ;
return;
}
#endif
for ( V_11 = 0 ; V_11 < V_59 -> V_67 ; V_11 ++ ) {
if ( V_195 -> V_202 [ V_11 ] ) {
F_123 ( V_2 -> V_187 , V_195 -> V_202 [ V_11 ] ,
V_45 , V_204 ) ;
}
}
F_124 ( V_59 ) ;
}
void
F_128 ( struct V_35 * V_36 , struct V_29 * V_20 )
{
struct V_29 * V_206 = NULL ;
if ( F_129 ( V_20 ) )
F_8 ( V_20 ) ;
F_4 ( & V_36 -> V_33 . V_34 -> V_207 ) ;
V_206 = V_36 -> V_33 . V_182 ;
V_36 -> V_33 . V_182 = V_20 ;
F_6 ( & V_36 -> V_33 . V_34 -> V_207 ) ;
F_2 ( & V_206 ) ;
}
static void
F_130 ( void * * V_182 )
{
F_2 ( (struct V_29 * * ) V_182 ) ;
}
static void *
F_131 ( void * V_182 )
{
return F_8 ( V_182 ) ;
}
static bool
F_132 ( void * V_182 )
{
return F_5 ( V_182 ) ;
}
static int
F_133 ( void * V_182 , bool V_208 , bool V_165 )
{
return F_134 ( V_182 , V_208 , V_165 ) ;
}
static int
F_135 ( void * V_182 )
{
return 0 ;
}
struct V_162 *
F_136 ( struct V_35 * V_36 , struct V_209 * V_62 )
{
struct V_162 * V_145 ;
F_100 (vma, &nvbo->vma_list, head) {
if ( V_145 -> V_62 == V_62 )
return V_145 ;
}
return NULL ;
}
int
F_137 ( struct V_35 * V_36 , struct V_209 * V_62 ,
struct V_162 * V_145 )
{
const T_1 V_6 = V_36 -> V_33 . V_66 . V_67 << V_68 ;
struct V_142 * V_143 = V_36 -> V_33 . V_66 . V_144 ;
int V_51 ;
V_51 = F_80 ( V_62 , V_6 , V_36 -> V_44 ,
V_164 , V_145 ) ;
if ( V_51 )
return V_51 ;
if ( V_36 -> V_33 . V_66 . V_91 == V_94 )
F_82 ( V_145 , V_36 -> V_33 . V_66 . V_144 ) ;
else if ( V_36 -> V_33 . V_66 . V_91 == V_96 ) {
if ( V_143 -> V_48 )
F_101 ( V_145 , 0 , V_6 , V_143 ) ;
else
F_83 ( V_145 , 0 , V_6 , V_143 ) ;
}
F_138 ( & V_145 -> V_56 , & V_36 -> V_58 ) ;
V_145 -> V_210 = 1 ;
return 0 ;
}
void
F_139 ( struct V_35 * V_36 , struct V_162 * V_145 )
{
if ( V_145 -> V_143 ) {
if ( V_36 -> V_33 . V_66 . V_91 != V_118 ) {
F_4 ( & V_36 -> V_33 . V_34 -> V_207 ) ;
F_140 ( & V_36 -> V_33 , false , false , false ) ;
F_6 ( & V_36 -> V_33 . V_34 -> V_207 ) ;
F_102 ( V_145 ) ;
}
F_141 ( V_145 ) ;
F_142 ( & V_145 -> V_56 ) ;
}
}
