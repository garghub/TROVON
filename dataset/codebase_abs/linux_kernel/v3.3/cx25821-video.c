int F_1 ( void )
{
return F_2 ( V_1 ) ;
}
struct V_2 * F_3 ( unsigned int V_3 )
{
unsigned int V_4 ;
if ( V_3 == V_5 || V_3 == V_6 )
return V_1 + 1 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_1 ) ; V_4 ++ )
if ( V_1 [ V_4 ] . V_3 == V_3 )
return V_1 + V_4 ;
F_4 ( L_1 , V_7 , V_3 ) ;
return NULL ;
}
void F_5 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
F_6 ( 1 , L_2 , V_7 ) ;
if ( ! F_7 ( & V_11 -> V_16 ) ) {
F_8 (item, &q->active)
V_13 = F_9 ( V_15 , struct V_12 , V_17 . V_18 ) ;
}
if ( ! F_7 ( & V_11 -> V_19 ) ) {
F_8 (item, &q->queued)
V_13 = F_9 ( V_15 , struct V_12 , V_17 . V_18 ) ;
}
}
void F_10 ( struct V_8 * V_9 , struct V_10 * V_11 ,
T_1 V_20 )
{
struct V_12 * V_13 ;
int V_21 ;
for ( V_21 = 0 ; ; V_21 ++ ) {
if ( F_7 ( & V_11 -> V_16 ) ) {
F_6 ( 1 , L_3 , V_21 ) ;
break;
}
V_13 = F_9 ( V_11 -> V_16 . V_22 , struct V_12 ,
V_17 . V_18 ) ;
if ( ( V_23 ) ( V_20 - V_13 -> V_20 ) < 0 )
break;
F_11 ( & V_13 -> V_17 . V_24 ) ;
V_13 -> V_17 . V_25 = V_26 ;
F_12 ( & V_13 -> V_17 . V_18 ) ;
F_13 ( & V_13 -> V_17 . V_27 ) ;
}
if ( F_7 ( & V_11 -> V_16 ) )
F_14 ( & V_11 -> V_28 ) ;
else
F_15 ( & V_11 -> V_28 , V_29 + V_30 ) ;
if ( V_21 != 1 )
F_4 ( L_4 , V_7 , V_21 ) ;
}
int F_16 ( struct V_8 * V_9 , T_2 V_31 )
{
F_6 ( 1 , L_5 ,
V_7 , ( unsigned int ) V_31 , F_17 ( V_31 ) ) ;
V_9 -> V_32 = V_31 ;
F_18 ( V_9 , V_33 , V_34 , V_31 ) ;
return 0 ;
}
struct V_35 * F_19 ( struct V_8 * V_9 ,
struct V_36 * V_37 ,
struct V_35 * V_38 ,
char * type )
{
struct V_35 * V_39 ;
F_6 ( 1 , L_2 , V_7 ) ;
V_39 = F_20 () ;
if ( NULL == V_39 )
return NULL ;
* V_39 = * V_38 ;
V_39 -> V_40 = & V_9 -> V_40 ;
V_39 -> V_41 = V_42 ;
snprintf ( V_39 -> V_43 , sizeof( V_39 -> V_43 ) , L_6 , V_9 -> V_43 , type ,
V_44 [ V_9 -> V_45 ] . V_43 ) ;
F_21 ( V_39 , V_9 ) ;
return V_39 ;
}
int F_22 ( struct V_8 * V_9 , struct V_46 * V_47 ,
unsigned int V_48 )
{
F_6 ( 1 , L_2 , V_7 ) ;
if ( V_47 -> V_49 & V_48 )
return 1 ;
F_23 ( & V_9 -> V_50 ) ;
if ( V_9 -> V_51 [ V_47 -> V_52 ] . V_49 & V_48 ) {
F_24 ( & V_9 -> V_50 ) ;
return 0 ;
}
V_47 -> V_49 |= V_48 ;
V_9 -> V_51 [ V_47 -> V_52 ] . V_49 |= V_48 ;
F_6 ( 1 , L_7 , V_48 ) ;
F_24 ( & V_9 -> V_50 ) ;
return 1 ;
}
int F_25 ( struct V_46 * V_47 , unsigned int V_48 )
{
return V_47 -> V_49 & V_48 ;
}
int F_26 ( struct V_46 * V_47 , unsigned int V_48 )
{
return V_47 -> V_9 -> V_51 [ V_47 -> V_52 ] . V_49 & V_48 ;
}
void F_27 ( struct V_8 * V_9 , struct V_46 * V_47 ,
unsigned int V_53 )
{
F_28 ( ( V_47 -> V_49 & V_53 ) != V_53 ) ;
F_6 ( 1 , L_2 , V_7 ) ;
F_23 ( & V_9 -> V_50 ) ;
V_47 -> V_49 &= ~ V_53 ;
V_9 -> V_51 [ V_47 -> V_52 ] . V_49 &= ~ V_53 ;
F_6 ( 1 , L_8 , V_53 ) ;
F_24 ( & V_9 -> V_50 ) ;
}
int F_29 ( struct V_8 * V_9 , unsigned int V_54 )
{
struct V_55 V_56 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
F_6 ( 1 , L_9 ,
V_7 , V_54 , F_30 ( V_54 ) -> V_57 , F_30 ( V_54 ) -> V_58 ,
F_30 ( V_54 ) -> V_59 , F_30 ( V_54 ) -> V_60 , F_30 ( V_54 ) -> V_61 ) ;
V_9 -> V_54 = V_54 ;
V_56 . V_54 = F_30 ( V_54 ) -> V_57 ;
F_18 ( V_9 , V_62 , V_63 , F_30 ( V_54 ) -> V_57 , 0 , 0 ) ;
return 0 ;
}
int F_31 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_64 * V_65 )
{
int V_66 = 0 ;
F_32 ( V_9 , V_65 , V_13 -> V_67 , V_13 -> V_68 . V_69 ) ;
F_33 ( V_65 -> V_70 , 3 ) ;
V_11 -> V_20 = 1 ;
F_34 ( V_71 , F_35 ( V_71 ) | ( 1 << V_65 -> V_4 ) ) ;
F_34 ( V_65 -> V_72 , 0x11 ) ;
F_33 ( V_65 -> V_73 , 0x11 ) ;
V_66 = F_35 ( V_74 ) ;
F_33 ( V_74 , V_66 & 0xFFFFFE00 ) ;
return 0 ;
}
int F_36 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_64 * V_65 )
{
struct V_12 * V_13 , * V_75 ;
struct V_14 * V_15 ;
if ( ! F_7 ( & V_11 -> V_16 ) ) {
V_13 = F_9 ( V_11 -> V_16 . V_22 , struct V_12 ,
V_17 . V_18 ) ;
F_31 ( V_9 , V_11 , V_13 , V_65 ) ;
F_8 (item, &q->active) {
V_13 = F_9 ( V_15 , struct V_12 , V_17 . V_18 ) ;
V_13 -> V_20 = V_11 -> V_20 ++ ;
}
F_15 ( & V_11 -> V_28 , V_29 + V_30 ) ;
return 0 ;
}
V_75 = NULL ;
for (; ; ) {
if ( F_7 ( & V_11 -> V_19 ) )
return 0 ;
V_13 = F_9 ( V_11 -> V_19 . V_22 , struct V_12 ,
V_17 . V_18 ) ;
if ( NULL == V_75 ) {
F_37 ( & V_13 -> V_17 . V_18 , & V_11 -> V_16 ) ;
F_31 ( V_9 , V_11 , V_13 , V_65 ) ;
V_13 -> V_17 . V_25 = V_76 ;
V_13 -> V_20 = V_11 -> V_20 ++ ;
F_15 ( & V_11 -> V_28 , V_29 + V_30 ) ;
} else if ( V_75 -> V_17 . V_77 == V_13 -> V_17 . V_77 &&
V_75 -> V_17 . V_78 == V_13 -> V_17 . V_78 &&
V_75 -> V_79 == V_13 -> V_79 ) {
F_37 ( & V_13 -> V_17 . V_18 , & V_11 -> V_16 ) ;
V_13 -> V_17 . V_25 = V_76 ;
V_13 -> V_20 = V_11 -> V_20 ++ ;
V_75 -> V_68 . V_80 [ 1 ] = F_38 ( V_13 -> V_68 . V_69 ) ;
V_75 -> V_68 . V_80 [ 2 ] = F_38 ( 0 ) ;
} else {
return 0 ;
}
V_75 = V_13 ;
}
}
void F_39 ( unsigned long V_81 )
{
struct V_82 * V_83 = (struct V_82 * ) V_81 ;
struct V_8 * V_9 = V_83 -> V_9 ;
struct V_64 * V_65 = V_83 -> V_65 ;
struct V_10 * V_11 = & V_9 -> V_51 [ V_65 -> V_4 ] . V_84 ;
struct V_12 * V_13 ;
unsigned long V_85 ;
F_40 ( V_65 -> V_73 , 0x11 ) ;
F_41 ( & V_9 -> V_86 , V_85 ) ;
while ( ! F_7 ( & V_11 -> V_16 ) ) {
V_13 = F_9 ( V_11 -> V_16 . V_22 , struct V_12 ,
V_17 . V_18 ) ;
F_12 ( & V_13 -> V_17 . V_18 ) ;
V_13 -> V_17 . V_25 = V_87 ;
F_13 ( & V_13 -> V_17 . V_27 ) ;
}
F_36 ( V_9 , V_11 , V_65 ) ;
F_42 ( & V_9 -> V_86 , V_85 ) ;
}
int F_43 ( struct V_8 * V_9 , int V_88 , T_1 V_89 )
{
T_1 V_20 = 0 ;
int V_90 = 0 ;
T_1 V_91 ;
struct V_64 * V_65 = V_9 -> V_51 [ V_88 ] . V_92 ;
V_91 = F_35 ( V_65 -> V_72 ) ;
if ( 0 == ( V_89 & V_91 ) )
return V_90 ;
F_33 ( V_65 -> V_93 , V_89 ) ;
if ( V_89 & ( 1 << 16 ) ) {
F_44 ( L_10 ,
V_9 -> V_43 , V_65 -> V_43 ) ;
F_40 ( V_65 -> V_73 , 0x11 ) ;
F_45 ( V_9 , V_65 ) ;
}
if ( V_89 & V_94 ) {
F_46 ( & V_9 -> V_86 ) ;
V_20 = F_35 ( V_65 -> V_95 ) ;
F_10 ( V_9 , & V_9 -> V_51 [ V_65 -> V_4 ] . V_84 ,
V_20 ) ;
F_47 ( & V_9 -> V_86 ) ;
V_90 ++ ;
}
if ( V_89 & 0x10 ) {
F_6 ( 2 , L_11 ) ;
F_46 ( & V_9 -> V_86 ) ;
F_36 ( V_9 ,
& V_9 -> V_51 [ V_65 -> V_4 ] . V_84 , V_65 ) ;
F_47 ( & V_9 -> V_86 ) ;
V_90 ++ ;
}
return V_90 ;
}
void F_48 ( struct V_8 * V_9 )
{
if ( V_9 -> V_96 ) {
if ( F_49 ( V_9 -> V_96 ) )
F_50 ( V_9 -> V_96 ) ;
else
V_42 ( V_9 -> V_96 ) ;
V_9 -> V_96 = NULL ;
}
}
void F_51 ( struct V_8 * V_9 , int V_88 )
{
F_40 ( V_71 , 1 ) ;
if ( V_9 -> V_51 [ V_88 ] . V_97 ) {
if ( F_49 ( V_9 -> V_51 [ V_88 ] . V_97 ) )
F_50 (
V_9 -> V_51 [ V_88 ] . V_97 ) ;
else
V_42 (
V_9 -> V_51 [ V_88 ] . V_97 ) ;
V_9 -> V_51 [ V_88 ] . V_97 = NULL ;
F_52 ( V_9 -> V_37 ,
& V_9 -> V_51 [ V_88 ] . V_84 . V_98 ) ;
F_44 ( L_12 , V_88 ) ;
}
}
int F_53 ( struct V_8 * V_9 )
{
int V_99 ;
int V_4 ;
struct V_35 V_100 = {
. V_43 = L_13 ,
. V_101 = & V_102 ,
. V_103 = - 1 ,
. V_104 = & V_105 ,
. V_106 = V_107 ,
. V_108 = V_109 ,
} ;
F_54 ( & V_9 -> V_86 ) ;
for ( V_4 = 0 ; V_4 < V_110 - 1 ; ++ V_4 ) {
F_55 ( V_9 , V_4 ) ;
F_56 ( V_9 -> V_37 , & V_9 -> V_51 [ V_4 ] . V_84 . V_98 ,
V_9 -> V_51 [ V_4 ] . V_92 -> V_73 , 0x11 , 0 ) ;
V_9 -> V_51 [ V_4 ] . V_92 = & V_111 [ V_4 ] ;
V_9 -> V_51 [ V_4 ] . V_97 = NULL ;
V_9 -> V_51 [ V_4 ] . V_49 = 0 ;
F_33 ( V_9 -> V_51 [ V_4 ] . V_92 -> V_93 , 0xffffffff ) ;
F_57 ( & V_9 -> V_51 [ V_4 ] . V_84 . V_16 ) ;
F_57 ( & V_9 -> V_51 [ V_4 ] . V_84 . V_19 ) ;
V_9 -> V_51 [ V_4 ] . V_83 . V_9 = V_9 ;
V_9 -> V_51 [ V_4 ] . V_83 . V_65 =
& V_111 [ V_4 ] ;
V_9 -> V_51 [ V_4 ] . V_84 . V_28 . V_112 = F_39 ;
V_9 -> V_51 [ V_4 ] . V_84 . V_28 . V_81 =
( unsigned long ) & V_9 -> V_51 [ V_4 ] . V_83 ;
F_58 ( & V_9 -> V_51 [ V_4 ] . V_84 . V_28 ) ;
V_9 -> V_51 [ V_4 ] . V_97 = F_19 ( V_9 , V_9 -> V_37 ,
& V_100 , L_14 ) ;
V_99 = F_59 ( V_9 -> V_51 [ V_4 ] . V_97 ,
V_113 , V_114 [ V_9 -> V_115 ] ) ;
if ( V_99 < 0 )
goto V_116;
}
F_34 ( V_71 , 0xff ) ;
F_23 ( & V_9 -> V_50 ) ;
#ifdef F_60
V_9 -> V_32 = V_100 . V_108 ;
F_16 ( V_9 , V_9 -> V_32 ) ;
#endif
F_24 ( & V_9 -> V_50 ) ;
return 0 ;
V_116:
F_51 ( V_9 , V_4 ) ;
return V_99 ;
}
int F_61 ( struct V_117 * V_11 , unsigned int * V_20 ,
unsigned int * V_118 )
{
struct V_46 * V_47 = V_11 -> V_119 ;
* V_118 = V_47 -> V_79 -> V_120 * V_47 -> V_77 * V_47 -> V_78 >> 3 ;
if ( 0 == * V_20 )
* V_20 = 32 ;
if ( * V_118 * * V_20 > V_121 * 1024 * 1024 )
* V_20 = ( V_121 * 1024 * 1024 ) / * V_118 ;
return 0 ;
}
int F_62 ( struct V_117 * V_11 , struct V_122 * V_17 ,
enum V_123 V_124 )
{
struct V_46 * V_47 = V_11 -> V_119 ;
struct V_8 * V_9 = V_47 -> V_9 ;
struct V_12 * V_13 =
F_63 ( V_17 , struct V_12 , V_17 ) ;
int V_125 , V_126 = 0 ;
T_1 V_127 , V_128 ;
struct V_129 * V_69 = F_64 ( & V_13 -> V_17 ) ;
int V_130 = V_131 ;
int V_132 = V_47 -> V_52 ;
F_28 ( NULL == V_47 -> V_79 ) ;
if ( V_47 -> V_77 < 48 || V_47 -> V_77 > 720 ||
V_47 -> V_78 < 32 || V_47 -> V_78 > 576 )
return - V_133 ;
V_13 -> V_17 . V_118 = ( V_47 -> V_77 * V_47 -> V_78 * V_47 -> V_79 -> V_120 ) >> 3 ;
if ( 0 != V_13 -> V_17 . V_134 && V_13 -> V_17 . V_135 < V_13 -> V_17 . V_118 )
return - V_133 ;
if ( V_13 -> V_79 != V_47 -> V_79 ||
V_13 -> V_17 . V_77 != V_47 -> V_77 ||
V_13 -> V_17 . V_78 != V_47 -> V_78 || V_13 -> V_17 . V_124 != V_124 ) {
V_13 -> V_79 = V_47 -> V_79 ;
V_13 -> V_17 . V_77 = V_47 -> V_77 ;
V_13 -> V_17 . V_78 = V_47 -> V_78 ;
V_13 -> V_17 . V_124 = V_124 ;
V_126 = 1 ;
}
if ( V_136 == V_13 -> V_17 . V_25 ) {
V_126 = 1 ;
V_125 = F_65 ( V_11 , & V_13 -> V_17 , NULL ) ;
if ( 0 != V_125 ) {
F_66 (KERN_DEBUG pr_fmt(L_15)) ;
goto V_137;
}
}
F_6 ( 1 , L_16 , V_126 ) ;
if ( V_126 ) {
V_132 = V_9 -> V_132 ;
if ( V_132 < 0 || V_132 > 7 )
V_132 = 7 ;
if ( V_9 -> V_51 [ V_132 ] . V_138 ==
V_139 )
V_13 -> V_67 = ( V_13 -> V_79 -> V_120 * V_13 -> V_17 . V_77 ) >> 3 ;
else
V_13 -> V_67 = ( V_13 -> V_79 -> V_120 >> 3 ) * ( V_13 -> V_17 . V_77 ) ;
if ( V_9 -> V_51 [ V_132 ] . V_138 ==
V_139 ) {
V_130 = V_13 -> V_67 ;
} else {
V_130 = V_13 -> V_67 ;
if ( V_132 >= 0 && V_132 <= 7 ) {
if ( V_9 -> V_51 [ V_132 ]
. V_140 ) {
if ( V_9 -> V_32 & V_141 ||
V_9 -> V_32 & V_142 )
V_130 = 352 << 1 ;
else
V_130 = V_9 -> V_51 [
V_132 ] .
V_143 << 1 ;
}
}
}
switch ( V_13 -> V_17 . V_124 ) {
case V_144 :
F_67 ( V_9 -> V_37 , & V_13 -> V_68 ,
V_69 -> V_145 , 0 , V_146 ,
V_13 -> V_67 , 0 , V_13 -> V_17 . V_78 ) ;
break;
case V_147 :
F_67 ( V_9 -> V_37 , & V_13 -> V_68 ,
V_69 -> V_145 , V_146 , 0 ,
V_13 -> V_67 , 0 , V_13 -> V_17 . V_78 ) ;
break;
case V_148 :
V_127 = 0 ;
V_128 = V_13 -> V_67 ;
F_6 ( 1 , L_17 ) ;
F_67 ( V_9 -> V_37 , & V_13 -> V_68 ,
V_69 -> V_145 , V_127 ,
V_130 , V_130 , V_130 ,
V_13 -> V_17 . V_78 >> 1 ) ;
break;
case V_149 :
F_67 ( V_9 -> V_37 , & V_13 -> V_68 ,
V_69 -> V_145 ,
0 , V_13 -> V_67 * ( V_13 -> V_17 . V_78 >> 1 ) ,
V_13 -> V_67 , 0 , V_13 -> V_17 . V_78 >> 1 ) ;
break;
case V_150 :
F_67 ( V_9 -> V_37 , & V_13 -> V_68 ,
V_69 -> V_145 ,
V_13 -> V_67 * ( V_13 -> V_17 . V_78 >> 1 ) , 0 ,
V_13 -> V_67 , 0 , V_13 -> V_17 . V_78 >> 1 ) ;
break;
default:
F_68 () ;
}
}
F_6 ( 2 , L_18 ,
V_13 , V_13 -> V_17 . V_4 , V_47 -> V_77 , V_47 -> V_78 , V_47 -> V_79 -> V_120 ,
V_47 -> V_79 -> V_43 , ( unsigned long ) V_13 -> V_68 . V_69 ) ;
V_13 -> V_17 . V_25 = V_151 ;
return 0 ;
V_137:
F_69 ( V_11 , V_13 ) ;
return V_125 ;
}
void F_70 ( struct V_117 * V_11 ,
struct V_122 * V_17 )
{
struct V_12 * V_13 =
F_63 ( V_17 , struct V_12 , V_17 ) ;
F_69 ( V_11 , V_13 ) ;
}
struct V_117 * F_71 ( struct V_46 * V_47 )
{
switch ( V_47 -> type ) {
case V_152 :
return & V_47 -> V_84 ;
default:
F_68 () ;
return NULL ;
}
}
int F_72 ( struct V_46 * V_47 , int V_153 )
{
switch ( V_47 -> type ) {
case V_152 :
return V_153 ;
default:
F_68 () ;
return 0 ;
}
}
int F_73 ( struct V_154 * V_154 , struct V_155 * V_156 )
{
struct V_46 * V_47 = V_154 -> V_157 ;
return F_74 ( F_71 ( V_47 ) , V_156 ) ;
}
static void F_75 ( struct V_117 * V_158 , struct V_122 * V_17 )
{
struct V_12 * V_13 =
F_63 ( V_17 , struct V_12 , V_17 ) ;
struct V_12 * V_75 ;
struct V_46 * V_47 = V_158 -> V_119 ;
struct V_8 * V_9 = V_47 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_51 [ V_47 -> V_52 ] . V_84 ;
V_13 -> V_68 . V_80 [ 0 ] = F_38 ( V_159 | V_160 | V_161 ) ;
V_13 -> V_68 . V_80 [ 1 ] = F_38 ( V_11 -> V_98 . V_69 ) ;
V_13 -> V_68 . V_80 [ 2 ] = F_38 ( 0 ) ;
F_6 ( 2 , L_19 , V_13 -> V_68 . V_80 [ 1 ] ) ;
if ( ! F_7 ( & V_11 -> V_19 ) ) {
F_76 ( & V_13 -> V_17 . V_18 , & V_11 -> V_19 ) ;
V_13 -> V_17 . V_25 = V_162 ;
F_6 ( 2 , L_20 , V_13 ,
V_13 -> V_17 . V_4 ) ;
} else if ( F_7 ( & V_11 -> V_16 ) ) {
F_76 ( & V_13 -> V_17 . V_18 , & V_11 -> V_16 ) ;
F_31 ( V_9 , V_11 , V_13 ,
V_9 -> V_51 [ V_47 -> V_52 ] . V_92 ) ;
V_13 -> V_17 . V_25 = V_76 ;
V_13 -> V_20 = V_11 -> V_20 ++ ;
F_15 ( & V_11 -> V_28 , V_29 + V_30 ) ;
F_6 ( 2 , L_21 ,
V_13 , V_13 -> V_17 . V_4 , V_13 -> V_20 , V_11 -> V_20 ) ;
} else {
V_75 = F_9 ( V_11 -> V_16 . V_75 , struct V_12 ,
V_17 . V_18 ) ;
if ( V_75 -> V_17 . V_77 == V_13 -> V_17 . V_77
&& V_75 -> V_17 . V_78 == V_13 -> V_17 . V_78
&& V_75 -> V_79 == V_13 -> V_79 ) {
F_76 ( & V_13 -> V_17 . V_18 , & V_11 -> V_16 ) ;
V_13 -> V_17 . V_25 = V_76 ;
V_13 -> V_20 = V_11 -> V_20 ++ ;
V_75 -> V_68 . V_80 [ 1 ] = F_38 ( V_13 -> V_68 . V_69 ) ;
V_75 -> V_68 . V_80 [ 2 ] = F_38 ( 0 ) ;
F_6 ( 2 , L_22 ,
V_13 , V_13 -> V_17 . V_4 , V_13 -> V_20 ) ;
} else {
F_76 ( & V_13 -> V_17 . V_18 , & V_11 -> V_19 ) ;
V_13 -> V_17 . V_25 = V_162 ;
F_6 ( 2 , L_23 , V_13 ,
V_13 -> V_17 . V_4 ) ;
}
}
if ( F_7 ( & V_11 -> V_16 ) )
F_6 ( 2 , L_24 ) ;
}
static int F_77 ( struct V_154 * V_154 )
{
struct V_35 * V_163 = F_78 ( V_154 ) ;
struct V_8 * V_164 , * V_9 = F_79 ( V_154 ) ;
struct V_46 * V_47 ;
struct V_14 * V_165 ;
int V_103 = F_78 ( V_154 ) -> V_103 ;
enum V_166 type = V_152 ;
T_1 V_167 ;
int V_168 = 0 ;
int V_4 ;
F_6 ( 1 , L_25 , F_80 ( V_163 ) ,
V_169 [ type ] ) ;
V_47 = F_81 ( sizeof( * V_47 ) , V_170 ) ;
if ( NULL == V_47 )
return - V_171 ;
F_23 ( & V_172 ) ;
F_8 (list, &cx25821_devlist)
{
V_164 = F_9 ( V_165 , struct V_8 , V_173 ) ;
for ( V_4 = 0 ; V_4 < V_110 ; V_4 ++ ) {
if ( V_164 -> V_51 [ V_4 ] . V_97 &&
V_164 -> V_51 [ V_4 ] . V_97 -> V_103 == V_103 ) {
V_9 = V_164 ;
V_168 = V_4 ;
type = V_152 ;
}
}
}
if ( NULL == V_9 ) {
F_24 ( & V_172 ) ;
F_82 ( V_47 ) ;
return - V_174 ;
}
V_154 -> V_157 = V_47 ;
V_47 -> V_9 = V_9 ;
V_47 -> type = type ;
V_47 -> V_77 = 720 ;
V_47 -> V_52 = V_168 ;
if ( V_9 -> V_32 & V_141 || V_9 -> V_32 & V_142 )
V_47 -> V_78 = 576 ;
else
V_47 -> V_78 = 480 ;
V_9 -> V_132 = V_47 -> V_52 ;
if ( V_9 -> V_51 [ V_168 ] . V_138 == V_139 )
V_167 = V_5 ;
else
V_167 = V_175 ;
V_47 -> V_79 = F_3 ( V_167 ) ;
F_83 ( & V_9 -> V_51 [ V_168 ] . V_176 , & V_47 -> V_176 ) ;
F_84 ( & V_47 -> V_84 , & V_177 , & V_9 -> V_37 -> V_9 ,
& V_9 -> V_86 , V_152 ,
V_148 , sizeof( struct V_12 ) ,
V_47 , NULL ) ;
F_6 ( 1 , L_26 ) ;
F_24 ( & V_172 ) ;
return 0 ;
}
static T_3 F_85 ( struct V_154 * V_154 , char T_4 * V_81 , T_5 V_20 ,
T_6 * V_178 )
{
struct V_46 * V_47 = V_154 -> V_157 ;
switch ( V_47 -> type ) {
case V_152 :
if ( F_26 ( V_47 , V_179 ) )
return - V_180 ;
return F_86 ( & V_47 -> V_84 , V_81 , V_20 , V_178 ,
V_154 -> V_181 & V_182 ) ;
default:
F_68 () ;
return 0 ;
}
}
static unsigned int F_87 ( struct V_154 * V_154 ,
struct V_183 * V_184 )
{
struct V_46 * V_47 = V_154 -> V_157 ;
struct V_12 * V_13 ;
if ( F_25 ( V_47 , V_179 ) ) {
if ( F_7 ( & V_47 -> V_84 . V_185 ) )
return V_186 ;
V_13 = F_9 ( V_47 -> V_84 . V_185 . V_22 ,
struct V_12 , V_17 . V_185 ) ;
} else {
V_13 = (struct V_12 * ) V_47 -> V_84 . V_187 ;
if ( NULL == V_13 )
return V_186 ;
}
F_88 ( V_154 , & V_13 -> V_17 . V_27 , V_184 ) ;
if ( V_13 -> V_17 . V_25 == V_26 || V_13 -> V_17 . V_25 == V_87 ) {
if ( V_13 -> V_17 . V_25 == V_26 ) {
struct V_8 * V_9 = V_47 -> V_9 ;
if ( V_9 && V_9 -> V_51 [ V_47 -> V_52 ]
. V_140 ) {
T_7 V_188 = * ( ( char * ) V_13 -> V_17 . V_134 + 3 ) ;
memcpy ( ( char * ) V_13 -> V_17 . V_134 ,
( char * ) V_13 -> V_17 . V_134 + ( V_47 -> V_77 * 2 ) ,
( V_47 -> V_77 * 2 ) ) ;
* ( ( char * ) V_13 -> V_17 . V_134 + 3 ) = V_188 ;
}
}
return V_189 | V_190 ;
}
return 0 ;
}
static int F_89 ( struct V_154 * V_154 )
{
struct V_46 * V_47 = V_154 -> V_157 ;
struct V_8 * V_9 = V_47 -> V_9 ;
F_33 ( V_191 -> V_73 , 0 ) ;
if ( F_25 ( V_47 , V_179 ) ) {
F_90 ( & V_47 -> V_84 ) ;
F_27 ( V_9 , V_47 , V_179 ) ;
}
if ( V_47 -> V_84 . V_187 ) {
F_70 ( & V_47 -> V_84 , V_47 -> V_84 . V_187 ) ;
F_82 ( V_47 -> V_84 . V_187 ) ;
}
F_91 ( & V_47 -> V_84 ) ;
F_92 ( & V_9 -> V_51 [ V_47 -> V_52 ] . V_176 , V_47 -> V_176 ) ;
V_154 -> V_157 = NULL ;
F_82 ( V_47 ) ;
return 0 ;
}
static int F_93 ( struct V_154 * V_154 , void * V_192 , enum V_166 V_4 )
{
struct V_46 * V_47 = V_192 ;
struct V_8 * V_9 = V_47 -> V_9 ;
if ( F_94 ( V_47 -> type != V_152 ) )
return - V_133 ;
if ( F_94 ( V_4 != V_47 -> type ) )
return - V_133 ;
if ( F_94 ( ! F_22 ( V_9 , V_47 , F_72 ( V_47 ,
V_179 ) ) ) )
return - V_180 ;
return F_95 ( F_71 ( V_47 ) ) ;
}
static int F_96 ( struct V_154 * V_154 , void * V_192 , enum V_166 V_4 )
{
struct V_46 * V_47 = V_192 ;
struct V_8 * V_9 = V_47 -> V_9 ;
int V_99 , V_193 ;
if ( V_47 -> type != V_152 )
return - V_133 ;
if ( V_4 != V_47 -> type )
return - V_133 ;
V_193 = F_72 ( V_47 , V_179 ) ;
V_99 = F_97 ( F_71 ( V_47 ) ) ;
if ( V_99 < 0 )
return V_99 ;
F_27 ( V_9 , V_47 , V_193 ) ;
return 0 ;
}
static int F_98 ( struct V_154 * V_154 , void * V_192 ,
struct V_194 * V_195 )
{
struct V_46 * V_47 = V_192 ;
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
struct V_196 V_197 ;
int V_99 ;
int V_167 = V_198 ;
if ( V_47 ) {
V_99 = F_99 ( & V_9 -> V_51 [ V_47 -> V_52 ] . V_176 ,
V_47 -> V_176 ) ;
if ( 0 != V_99 )
return V_99 ;
}
F_6 ( 2 , L_2 , V_7 ) ;
V_99 = F_100 ( V_154 , V_192 , V_195 ) ;
if ( 0 != V_99 )
return V_99 ;
V_47 -> V_79 = F_3 ( V_195 -> V_79 . V_199 . V_200 ) ;
V_47 -> V_84 . V_124 = V_195 -> V_79 . V_199 . V_124 ;
if ( F_101 ( V_195 -> V_79 . V_199 . V_77 , V_9 -> V_32 ) )
V_47 -> V_77 = V_195 -> V_79 . V_199 . V_77 ;
if ( F_102 ( V_195 -> V_79 . V_199 . V_78 , V_9 -> V_32 ) )
V_47 -> V_78 = V_195 -> V_79 . V_199 . V_78 ;
if ( V_195 -> V_79 . V_199 . V_200 == V_5 )
V_167 = V_139 ;
else if ( V_195 -> V_79 . V_199 . V_200 == V_175 )
V_167 = V_198 ;
else
return - V_133 ;
F_103 ( V_9 , V_201 , V_167 ) ;
if ( V_47 -> V_77 == 320 || V_47 -> V_77 == 352 )
V_9 -> V_51 [ V_47 -> V_52 ] . V_140 = 1 ;
else
V_9 -> V_51 [ V_47 -> V_52 ] . V_140 = 0 ;
V_9 -> V_51 [ V_47 -> V_52 ] . V_143 = V_47 -> V_77 ;
F_104 ( V_9 , V_47 -> V_77 , V_201 ) ;
F_6 ( 2 , L_27 , V_7 , V_47 -> V_77 ,
V_47 -> V_78 , V_47 -> V_84 . V_124 ) ;
F_105 ( & V_197 , & V_195 -> V_79 . V_199 , V_202 ) ;
F_18 ( V_9 , V_62 , V_203 , & V_197 ) ;
return 0 ;
}
static int F_106 ( struct V_154 * V_154 , void * V_192 , struct V_204 * V_205 )
{
int V_206 = 0 ;
struct V_46 * V_47 = V_192 ;
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
V_206 = F_107 ( F_71 ( V_47 ) , V_205 , V_154 -> V_181 & V_182 ) ;
V_205 -> V_207 = V_9 -> V_51 [ V_47 -> V_52 ] . V_84 . V_20 ;
return V_206 ;
}
static int F_108 ( struct V_154 * V_154 , void * V_192 )
{
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
struct V_46 * V_47 = V_192 ;
char V_43 [ 32 + 2 ] ;
struct V_64 * V_208 = V_9 -> V_51 [ V_47 -> V_52 ]
. V_92 ;
T_1 V_66 = 0 ;
snprintf ( V_43 , sizeof( V_43 ) , L_28 , V_9 -> V_43 ) ;
F_109 ( L_29 ,
V_9 -> V_43 ) ;
F_18 ( V_9 , V_33 , V_209 ) ;
V_66 = F_35 ( V_208 -> V_73 ) ;
F_109 ( L_30 ,
( V_66 & 0x11 ) ? L_31 : L_32 ) ;
F_109 ( L_33 ,
V_9 -> V_43 ) ;
return 0 ;
}
static int F_110 ( struct V_154 * V_154 , void * V_192 ,
struct V_210 * V_211 )
{
struct V_46 * V_47 = V_192 ;
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
int V_99 ;
if ( V_47 ) {
V_99 = F_99 ( & V_9 -> V_51 [ V_47 -> V_52 ] . V_176 ,
V_47 -> V_176 ) ;
if ( 0 != V_99 )
return V_99 ;
}
return F_111 ( V_9 , V_211 , V_47 -> V_52 ) ;
}
int F_112 ( struct V_154 * V_154 , void * V_192 ,
struct V_194 * V_195 )
{
struct V_46 * V_47 = V_192 ;
V_195 -> V_79 . V_199 . V_77 = V_47 -> V_77 ;
V_195 -> V_79 . V_199 . V_78 = V_47 -> V_78 ;
V_195 -> V_79 . V_199 . V_124 = V_47 -> V_84 . V_124 ;
V_195 -> V_79 . V_199 . V_200 = V_47 -> V_79 -> V_3 ;
V_195 -> V_79 . V_199 . V_212 = ( V_195 -> V_79 . V_199 . V_77 * V_47 -> V_79 -> V_120 ) >> 3 ;
V_195 -> V_79 . V_199 . V_213 = V_195 -> V_79 . V_199 . V_78 * V_195 -> V_79 . V_199 . V_212 ;
return 0 ;
}
int F_100 ( struct V_154 * V_154 , void * V_192 ,
struct V_194 * V_195 )
{
struct V_2 * V_79 ;
enum V_123 V_124 ;
unsigned int V_214 , V_215 ;
V_79 = F_3 ( V_195 -> V_79 . V_199 . V_200 ) ;
if ( NULL == V_79 )
return - V_133 ;
V_124 = V_195 -> V_79 . V_199 . V_124 ;
V_214 = 720 ;
V_215 = 576 ;
if ( V_216 == V_124 ) {
if ( V_195 -> V_79 . V_199 . V_78 > V_215 / 2 )
V_124 = V_148 ;
else
V_124 = V_144 ;
}
switch ( V_124 ) {
case V_144 :
case V_147 :
V_215 = V_215 / 2 ;
break;
case V_148 :
break;
default:
return - V_133 ;
}
V_195 -> V_79 . V_199 . V_124 = V_124 ;
if ( V_195 -> V_79 . V_199 . V_78 < 32 )
V_195 -> V_79 . V_199 . V_78 = 32 ;
if ( V_195 -> V_79 . V_199 . V_78 > V_215 )
V_195 -> V_79 . V_199 . V_78 = V_215 ;
if ( V_195 -> V_79 . V_199 . V_77 < 48 )
V_195 -> V_79 . V_199 . V_77 = 48 ;
if ( V_195 -> V_79 . V_199 . V_77 > V_214 )
V_195 -> V_79 . V_199 . V_77 = V_214 ;
V_195 -> V_79 . V_199 . V_77 &= ~ 0x03 ;
V_195 -> V_79 . V_199 . V_212 = ( V_195 -> V_79 . V_199 . V_77 * V_79 -> V_120 ) >> 3 ;
V_195 -> V_79 . V_199 . V_213 = V_195 -> V_79 . V_199 . V_78 * V_195 -> V_79 . V_199 . V_212 ;
return 0 ;
}
int F_113 ( struct V_154 * V_154 , void * V_192 ,
struct V_217 * V_218 )
{
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
strcpy ( V_218 -> V_219 , L_34 ) ;
F_114 ( V_218 -> V_220 , V_44 [ V_9 -> V_45 ] . V_43 , sizeof( V_218 -> V_220 ) ) ;
sprintf ( V_218 -> V_221 , L_35 , F_115 ( V_9 -> V_37 ) ) ;
V_218 -> V_222 = V_223 ;
V_218 -> V_224 = V_225 | V_226 |
V_227 ;
if ( V_146 != V_9 -> V_228 )
V_218 -> V_224 |= V_229 ;
return 0 ;
}
int F_116 ( struct V_154 * V_154 , void * V_192 ,
struct V_230 * V_195 )
{
if ( F_94 ( V_195 -> V_231 >= F_2 ( V_1 ) ) )
return - V_133 ;
F_114 ( V_195 -> V_232 , V_1 [ V_195 -> V_231 ] . V_43 , sizeof( V_195 -> V_232 ) ) ;
V_195 -> V_200 = V_1 [ V_195 -> V_231 ] . V_3 ;
return 0 ;
}
int F_117 ( struct V_154 * V_154 , void * V_192 ,
struct V_233 * V_205 )
{
struct V_46 * V_47 = V_192 ;
return F_118 ( F_71 ( V_47 ) , V_205 ) ;
}
int F_119 ( struct V_154 * V_154 , void * V_192 ,
struct V_204 * V_205 )
{
struct V_46 * V_47 = V_192 ;
return F_120 ( F_71 ( V_47 ) , V_205 ) ;
}
int F_121 ( struct V_154 * V_154 , void * V_192 , struct V_204 * V_205 )
{
struct V_46 * V_47 = V_192 ;
return F_122 ( F_71 ( V_47 ) , V_205 ) ;
}
int F_123 ( struct V_154 * V_154 , void * V_195 , enum V_234 * V_205 )
{
struct V_8 * V_9 = ( (struct V_46 * ) V_195 ) -> V_9 ;
struct V_46 * V_47 = V_195 ;
* V_205 = F_124 ( & V_9 -> V_51 [ V_47 -> V_52 ] . V_176 ) ;
return 0 ;
}
int F_125 ( struct V_154 * V_154 , void * V_195 ,
enum V_234 V_176 )
{
struct V_46 * V_47 = V_195 ;
struct V_8 * V_9 = ( (struct V_46 * ) V_195 ) -> V_9 ;
return F_126 ( & V_9 -> V_51 [ V_47 -> V_52 ] . V_176 , & V_47 -> V_176 ,
V_176 ) ;
}
int F_127 ( struct V_154 * V_154 , void * V_192 , T_2 * V_106 )
{
struct V_46 * V_47 = V_192 ;
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
int V_99 ;
F_6 ( 1 , L_2 , V_7 ) ;
if ( V_47 ) {
V_99 = F_99 ( & V_9 -> V_51 [ V_47 -> V_52 ] . V_176 ,
V_47 -> V_176 ) ;
if ( 0 != V_99 )
return V_99 ;
}
if ( V_9 -> V_32 == * V_106 )
return 0 ;
F_23 ( & V_9 -> V_50 ) ;
F_16 ( V_9 , * V_106 ) ;
F_24 ( & V_9 -> V_50 ) ;
F_128 ( V_9 ) ;
return 0 ;
}
int F_129 ( struct V_8 * V_9 , struct V_235 * V_4 )
{
static const char * const V_236 [] = {
[ V_237 ] = L_36 ,
[ V_238 ] = L_37 ,
[ V_239 ] = L_38 ,
} ;
unsigned int V_240 ;
F_6 ( 1 , L_2 , V_7 ) ;
V_240 = V_4 -> V_231 ;
if ( V_240 >= 2 )
return - V_133 ;
if ( 0 == F_30 ( V_240 ) -> type )
return - V_133 ;
V_4 -> type = V_241 ;
strcpy ( V_4 -> V_43 , V_236 [ F_30 ( V_240 ) -> type ] ) ;
V_4 -> V_242 = V_107 ;
return 0 ;
}
int F_130 ( struct V_154 * V_154 , void * V_192 ,
struct V_235 * V_4 )
{
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
F_6 ( 1 , L_2 , V_7 ) ;
return F_129 ( V_9 , V_4 ) ;
}
int F_131 ( struct V_154 * V_154 , void * V_192 , unsigned int * V_4 )
{
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
* V_4 = V_9 -> V_54 ;
F_6 ( 1 , L_39 , V_7 , * V_4 ) ;
return 0 ;
}
int F_132 ( struct V_154 * V_154 , void * V_192 , unsigned int V_4 )
{
struct V_46 * V_47 = V_192 ;
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
int V_99 ;
F_6 ( 1 , L_40 , V_7 , V_4 ) ;
if ( V_47 ) {
V_99 = F_99 ( & V_9 -> V_51 [ V_47 -> V_52 ] . V_176 ,
V_47 -> V_176 ) ;
if ( 0 != V_99 )
return V_99 ;
}
if ( V_4 >= V_243 ) {
F_6 ( 1 , L_41 , V_7 ) ;
return - V_133 ;
}
F_23 ( & V_9 -> V_50 ) ;
F_29 ( V_9 , V_4 ) ;
F_24 ( & V_9 -> V_50 ) ;
return 0 ;
}
int F_133 ( struct V_154 * V_154 , void * V_192 ,
struct V_244 * V_195 )
{
struct V_46 * V_47 = V_192 ;
struct V_8 * V_9 = V_47 -> V_9 ;
V_195 -> V_245 = V_9 -> V_246 ;
F_18 ( V_9 , V_247 , V_248 , V_195 ) ;
return 0 ;
}
int F_134 ( struct V_8 * V_9 , struct V_244 * V_195 )
{
F_23 ( & V_9 -> V_50 ) ;
V_9 -> V_246 = V_195 -> V_245 ;
F_18 ( V_9 , V_247 , V_249 , V_195 ) ;
F_135 ( 10 ) ;
F_24 ( & V_9 -> V_50 ) ;
return 0 ;
}
int F_136 ( struct V_154 * V_154 , void * V_192 ,
struct V_244 * V_195 )
{
struct V_46 * V_47 = V_192 ;
struct V_8 * V_9 ;
int V_99 ;
if ( V_47 ) {
V_9 = V_47 -> V_9 ;
V_99 = F_99 ( & V_9 -> V_51 [ V_47 -> V_52 ] . V_176 ,
V_47 -> V_176 ) ;
if ( 0 != V_99 )
return V_99 ;
} else {
F_4 ( L_42 ) ;
return - V_133 ;
}
return F_134 ( V_9 , V_195 ) ;
}
int F_137 ( struct V_154 * V_154 , void * V_47 ,
struct V_250 * V_251 )
{
struct V_8 * V_9 = ( (struct V_46 * ) V_47 ) -> V_9 ;
if ( ! F_138 ( & V_251 -> V_252 ) )
return - V_133 ;
F_18 ( V_9 , V_33 , V_253 , V_251 ) ;
return 0 ;
}
int F_139 ( struct V_154 * V_154 , void * V_47 ,
struct V_250 * V_251 )
{
struct V_8 * V_9 = ( (struct V_46 * ) V_47 ) -> V_9 ;
if ( ! F_138 ( & V_251 -> V_252 ) )
return - V_133 ;
F_18 ( V_9 , V_33 , V_254 , V_251 ) ;
return 0 ;
}
int F_140 ( struct V_154 * V_154 , void * V_192 , struct V_255 * V_256 )
{
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
if ( F_94 ( V_146 == V_9 -> V_228 ) )
return - V_133 ;
if ( 0 != V_256 -> V_231 )
return - V_133 ;
strcpy ( V_256 -> V_43 , L_43 ) ;
V_256 -> type = V_257 ;
V_256 -> V_258 = V_259 ;
V_256 -> V_260 = 0xffffffffUL ;
V_256 -> signal = 0xffff ;
return 0 ;
}
int F_141 ( struct V_154 * V_154 , void * V_192 , struct V_255 * V_256 )
{
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
struct V_46 * V_47 = V_192 ;
int V_99 ;
if ( V_47 ) {
V_99 = F_99 ( & V_9 -> V_51 [ V_47 -> V_52 ] . V_176 ,
V_47 -> V_176 ) ;
if ( 0 != V_99 )
return V_99 ;
}
F_6 ( 1 , L_2 , V_7 ) ;
if ( V_146 == V_9 -> V_228 )
return - V_133 ;
if ( 0 != V_256 -> V_231 )
return - V_133 ;
return 0 ;
}
static int F_142 ( struct V_261 * V_262 )
{
int V_4 ;
if ( V_262 -> V_263 < V_264 || V_262 -> V_263 >= V_265 )
return - V_133 ;
for ( V_4 = 0 ; V_4 < V_266 ; V_4 ++ )
if ( V_267 [ V_4 ] . V_263 == V_262 -> V_263 )
break;
if ( V_4 == V_266 ) {
* V_262 = V_268 ;
return 0 ;
}
* V_262 = V_267 [ V_4 ] ;
return 0 ;
}
int F_143 ( struct V_154 * V_154 , void * V_192 ,
struct V_261 * V_262 )
{
return F_142 ( V_262 ) ;
}
static const struct V_261 * F_144 ( unsigned int V_263 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_266 ; V_4 ++ )
if ( V_267 [ V_4 ] . V_263 == V_263 )
return V_267 + V_4 ;
return NULL ;
}
int F_145 ( struct V_154 * V_154 , void * V_192 ,
struct V_210 * V_211 )
{
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
struct V_46 * V_47 = V_192 ;
const struct V_261 * V_269 ;
V_269 = F_144 ( V_211 -> V_263 ) ;
if ( NULL == V_269 )
return - V_133 ;
switch ( V_211 -> V_263 ) {
case V_270 :
V_211 -> V_271 = V_9 -> V_51 [ V_47 -> V_52 ] . V_272 ;
break;
case V_273 :
V_211 -> V_271 = V_9 -> V_51 [ V_47 -> V_52 ] . V_274 ;
break;
case V_275 :
V_211 -> V_271 = V_9 -> V_51 [ V_47 -> V_52 ] . V_276 ;
break;
case V_277 :
V_211 -> V_271 = V_9 -> V_51 [ V_47 -> V_52 ] . V_278 ;
break;
}
return 0 ;
}
int F_111 ( struct V_8 * V_9 ,
struct V_210 * V_211 , int V_88 )
{
int V_99 ;
const struct V_261 * V_269 ;
V_99 = - V_133 ;
V_269 = F_144 ( V_211 -> V_263 ) ;
if ( NULL == V_269 )
return V_99 ;
switch ( V_269 -> type ) {
case V_279 :
case V_280 :
case V_281 :
if ( V_211 -> V_271 < V_269 -> V_282 )
V_211 -> V_271 = V_269 -> V_282 ;
if ( V_211 -> V_271 > V_269 -> V_283 )
V_211 -> V_271 = V_269 -> V_283 ;
break;
default:
;
}
switch ( V_211 -> V_263 ) {
case V_270 :
V_9 -> V_51 [ V_88 ] . V_272 = V_211 -> V_271 ;
F_146 ( V_9 , V_211 -> V_271 , V_88 ) ;
break;
case V_273 :
V_9 -> V_51 [ V_88 ] . V_274 = V_211 -> V_271 ;
F_147 ( V_9 , V_211 -> V_271 , V_88 ) ;
break;
case V_275 :
V_9 -> V_51 [ V_88 ] . V_276 = V_211 -> V_271 ;
F_148 ( V_9 , V_211 -> V_271 , V_88 ) ;
break;
case V_277 :
V_9 -> V_51 [ V_88 ] . V_278 = V_211 -> V_271 ;
F_149 ( V_9 , V_211 -> V_271 , V_88 ) ;
break;
}
V_99 = 0 ;
return V_99 ;
}
static void F_55 ( struct V_8 * V_9 , int V_88 )
{
struct V_210 V_269 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_266 ; V_4 ++ ) {
V_269 . V_263 = V_267 [ V_4 ] . V_263 ;
V_269 . V_271 = V_267 [ V_4 ] . V_284 ;
F_111 ( V_9 , & V_269 , V_88 ) ;
}
}
int F_150 ( struct V_154 * V_154 , void * V_192 ,
struct V_285 * V_286 )
{
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
if ( V_286 -> type != V_152 )
return - V_133 ;
V_286 -> V_287 . V_288 = 0 ;
V_286 -> V_287 . V_289 = 0 ;
V_286 -> V_287 . V_77 = 720 ;
V_286 -> V_287 . V_78 = V_9 -> V_32 == V_141 ? 576 : 480 ;
V_286 -> V_290 . V_291 =
V_9 -> V_32 == V_141 ? 59 : 10 ;
V_286 -> V_290 . V_292 =
V_9 -> V_32 == V_141 ? 54 : 11 ;
V_286 -> V_293 = V_286 -> V_287 ;
return 0 ;
}
int F_151 ( struct V_154 * V_154 , void * V_192 , struct V_294 * V_295 )
{
struct V_8 * V_9 = ( (struct V_46 * ) V_192 ) -> V_9 ;
struct V_46 * V_47 = V_192 ;
int V_99 ;
if ( V_47 ) {
V_99 = F_99 ( & V_9 -> V_51 [ V_47 -> V_52 ] . V_176 ,
V_47 -> V_176 ) ;
if ( 0 != V_99 )
return V_99 ;
}
return - V_133 ;
}
int F_152 ( struct V_154 * V_154 , void * V_192 , struct V_294 * V_295 )
{
return - V_133 ;
}
int F_153 ( struct V_154 * V_154 , void * V_192 , T_2 * V_31 )
{
* V_31 = V_107 ;
return 0 ;
}
int F_101 ( T_1 V_77 , T_2 V_32 )
{
if ( V_32 == V_141 ) {
if ( V_77 == 352 || V_77 == 720 )
return 1 ;
else
return 0 ;
}
if ( V_32 == V_109 ) {
if ( V_77 == 320 || V_77 == 352 || V_77 == 720 )
return 1 ;
else
return 0 ;
}
return 0 ;
}
int F_102 ( T_1 V_78 , T_2 V_32 )
{
if ( V_32 == V_141 ) {
if ( V_78 == 576 || V_78 == 288 )
return 1 ;
else
return 0 ;
}
if ( V_32 == V_109 ) {
if ( V_78 == 480 || V_78 == 240 )
return 1 ;
else
return 0 ;
}
return 0 ;
}
static long F_154 ( struct V_154 * V_154 , unsigned int V_296 ,
unsigned long V_297 )
{
struct V_46 * V_47 = V_154 -> V_157 ;
struct V_8 * V_9 = V_47 -> V_9 ;
int V_298 = 0 ;
struct V_299 * V_300 ;
V_300 = (struct V_299 * ) V_297 ;
if ( ! V_300 ) {
F_4 ( L_44 , V_7 ) ;
return 0 ;
}
V_298 = V_300 -> V_298 ;
if ( V_298 != V_301 && V_298 != V_302 )
return 0 ;
V_9 -> V_303 = V_300 -> V_303 ;
V_9 -> V_304 = V_300 -> V_303 ;
V_9 -> V_305 = V_300 -> V_305 ;
V_9 -> V_306 = V_300 -> V_306 ;
V_9 -> V_307 = V_300 -> V_307 ;
V_9 -> V_298 = V_300 -> V_298 ;
switch ( V_298 ) {
case V_301 :
F_155 ( V_9 , V_300 ) ;
break;
case V_302 :
F_156 ( V_9 ) ;
break;
}
return 0 ;
}
static long F_157 ( struct V_154 * V_154 , unsigned int V_296 ,
unsigned long V_297 )
{
struct V_46 * V_47 = V_154 -> V_157 ;
struct V_8 * V_9 = V_47 -> V_9 ;
int V_298 = 0 ;
struct V_299 * V_300 ;
V_300 = (struct V_299 * ) V_297 ;
if ( ! V_300 ) {
F_4 ( L_44 , V_7 ) ;
return 0 ;
}
V_298 = V_300 -> V_298 ;
if ( V_298 != V_301 && V_298 != V_302 )
return 0 ;
V_9 -> V_308 = V_300 -> V_303 ;
V_9 -> V_304 = V_300 -> V_303 ;
V_9 -> V_309 = V_300 -> V_305 ;
V_9 -> V_310 = V_300 -> V_306 ;
V_9 -> V_311 = V_300 -> V_307 ;
V_9 -> V_312 = V_300 -> V_298 ;
switch ( V_298 ) {
case V_301 :
F_158 ( V_9 , V_300 ) ;
break;
case V_302 :
F_159 ( V_9 ) ;
break;
}
return 0 ;
}
static long F_160 ( struct V_154 * V_154 , unsigned int V_296 ,
unsigned long V_297 )
{
struct V_46 * V_47 = V_154 -> V_157 ;
struct V_8 * V_9 = V_47 -> V_9 ;
int V_298 = 0 ;
struct V_299 * V_300 ;
V_300 = (struct V_299 * ) V_297 ;
if ( ! V_300 ) {
F_4 ( L_44 , V_7 ) ;
return 0 ;
}
V_298 = V_300 -> V_298 ;
if ( V_298 != V_313 && V_298 != V_314 )
return 0 ;
V_9 -> V_303 = V_300 -> V_303 ;
V_9 -> V_304 = V_300 -> V_303 ;
V_9 -> V_305 = V_300 -> V_305 ;
V_9 -> V_306 = V_300 -> V_306 ;
V_9 -> V_307 = V_300 -> V_307 ;
V_9 -> V_298 = V_300 -> V_298 ;
switch ( V_298 ) {
case V_313 :
F_161 ( V_9 , V_300 ) ;
break;
case V_314 :
F_162 ( V_9 ) ;
break;
}
return 0 ;
}
static long F_163 ( struct V_154 * V_154 , unsigned int V_296 ,
unsigned long V_297 )
{
struct V_46 * V_47 = V_154 -> V_157 ;
struct V_8 * V_9 = V_47 -> V_9 ;
struct V_315 * V_300 ;
int V_298 ;
int V_77 = 720 ;
int V_316 = 0 ;
int V_167 = 0 ;
int V_4 = 0 ;
int V_317 = 0 ;
int V_143 = 0 ;
T_1 V_271 = 0 ;
V_300 = (struct V_315 * ) V_297 ;
if ( ! V_300 ) {
F_4 ( L_45 , V_7 ) ;
return 0 ;
}
V_298 = V_300 -> V_298 ;
if ( V_298 != V_318 && V_298 != V_319
&& V_298 != V_320 && V_298 != V_321
&& V_298 != V_322 && V_298 != V_323
&& V_298 != V_324 ) {
return 0 ;
}
switch ( V_298 ) {
case V_318 :
if ( ! strcmp ( V_300 -> V_305 , L_46 ) )
V_9 -> V_32 = V_141 ;
else
V_9 -> V_32 = V_109 ;
F_128 ( V_9 ) ;
break;
case V_319 :
V_316 = V_300 -> V_325 ;
V_167 = V_300 -> V_306 ;
if ( ! ( V_316 <= 7 && V_316 >= 0 ) ) {
V_316 -= 4 ;
V_316 = V_316 % 8 ;
}
if ( V_316 >= 0 )
F_103 ( V_9 , V_316 ,
V_167 ) ;
break;
case V_320 :
V_316 = V_300 -> V_325 ;
V_317 = V_300 -> V_326 ;
V_143 = V_300 -> V_143 ;
if ( V_317 ) {
if ( V_9 -> V_32 & V_141
|| V_9 -> V_32 & V_142 ) {
V_77 = 352 ;
} else {
V_77 = V_143 ;
if ( V_143 != 320 && V_143 != 352 )
V_77 = 320 ;
}
}
if ( ! ( V_316 <= 7 && V_316 >= 0 ) ) {
V_316 -= 4 ;
V_316 = V_316 % 8 ;
}
if ( V_316 <= 7 && V_316 >= 0 ) {
V_9 -> V_51 [ V_316 ] . V_140 =
V_317 ;
V_9 -> V_51 [ V_316 ] . V_143 = V_77 ;
} else {
for ( V_4 = 0 ; V_4 < V_327 ; V_4 ++ ) {
V_9 -> V_51 [ V_4 ] . V_140 =
V_317 ;
V_9 -> V_51 [ V_4 ] . V_143 = V_77 ;
}
}
F_104 ( V_9 , V_77 , V_316 ) ;
break;
case V_321 :
V_300 -> V_328 = F_35 ( V_300 -> V_329 ) ;
break;
case V_322 :
F_33 ( V_300 -> V_329 , V_300 -> V_328 ) ;
break;
case V_323 :
V_271 = F_164 ( & V_9 -> V_330 [ 0 ] ,
( V_331 ) V_300 -> V_329 ,
& V_300 -> V_328 ) ;
break;
case V_324 :
F_165 ( & V_9 -> V_330 [ 0 ] ,
( V_331 ) V_300 -> V_329 ,
V_300 -> V_328 ) ;
break;
}
return 0 ;
}
static long F_166 ( struct V_154 * V_154 ,
unsigned int V_296 , unsigned long V_297 )
{
int V_332 = 0 ;
struct V_46 * V_47 = V_154 -> V_157 ;
if ( V_47 -> V_52 == V_333 ) {
V_332 = F_154 ( V_154 , V_296 , V_297 ) ;
return V_332 ;
} else if ( V_47 -> V_52 == V_334 ) {
V_332 = F_157 ( V_154 , V_296 , V_297 ) ;
return V_332 ;
} else if ( V_47 -> V_52 == V_335 ) {
V_332 = F_160 ( V_154 , V_296 , V_297 ) ;
V_332 = F_163 ( V_154 , V_296 , V_297 ) ;
return V_332 ;
}
return F_167 ( V_154 , V_296 , V_297 ) ;
}
