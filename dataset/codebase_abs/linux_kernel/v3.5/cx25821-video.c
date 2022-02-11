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
void F_5 ( struct V_8 * V_9 , struct V_10 * V_11 ,
T_1 V_12 )
{
struct V_13 * V_14 ;
int V_15 ;
for ( V_15 = 0 ; ; V_15 ++ ) {
if ( F_6 ( & V_11 -> V_16 ) ) {
F_7 ( 1 , L_2 , V_15 ) ;
break;
}
V_14 = F_8 ( V_11 -> V_16 . V_17 , struct V_13 ,
V_18 . V_19 ) ;
if ( ( V_20 ) ( V_12 - V_14 -> V_12 ) < 0 )
break;
F_9 ( & V_14 -> V_18 . V_21 ) ;
V_14 -> V_18 . V_22 = V_23 ;
F_10 ( & V_14 -> V_18 . V_19 ) ;
F_11 ( & V_14 -> V_18 . V_24 ) ;
}
if ( F_6 ( & V_11 -> V_16 ) )
F_12 ( & V_11 -> V_25 ) ;
else
F_13 ( & V_11 -> V_25 , V_26 + V_27 ) ;
if ( V_15 != 1 )
F_4 ( L_3 , V_7 , V_15 ) ;
}
int F_14 ( struct V_8 * V_9 , T_2 V_28 )
{
F_7 ( 1 , L_4 ,
V_7 , ( unsigned int ) V_28 , F_15 ( V_28 ) ) ;
V_9 -> V_29 = V_28 ;
F_16 ( V_9 , V_30 , V_31 , V_28 ) ;
return 0 ;
}
struct V_32 * F_17 ( struct V_8 * V_9 ,
struct V_33 * V_34 ,
struct V_32 * V_35 ,
char * type )
{
struct V_32 * V_36 ;
F_7 ( 1 , L_5 , V_7 ) ;
V_36 = F_18 () ;
if ( NULL == V_36 )
return NULL ;
* V_36 = * V_35 ;
V_36 -> V_37 = & V_9 -> V_37 ;
V_36 -> V_38 = V_39 ;
snprintf ( V_36 -> V_40 , sizeof( V_36 -> V_40 ) , L_6 , V_9 -> V_40 , type ,
V_41 [ V_9 -> V_42 ] . V_40 ) ;
F_19 ( V_36 , V_9 ) ;
return V_36 ;
}
int F_20 ( struct V_8 * V_9 , struct V_43 * V_44 ,
unsigned int V_45 )
{
F_7 ( 1 , L_5 , V_7 ) ;
if ( V_44 -> V_46 & V_45 )
return 1 ;
F_21 ( & V_9 -> V_47 ) ;
if ( V_9 -> V_48 [ V_44 -> V_49 ] . V_46 & V_45 ) {
F_22 ( & V_9 -> V_47 ) ;
return 0 ;
}
V_44 -> V_46 |= V_45 ;
V_9 -> V_48 [ V_44 -> V_49 ] . V_46 |= V_45 ;
F_7 ( 1 , L_7 , V_45 ) ;
F_22 ( & V_9 -> V_47 ) ;
return 1 ;
}
int F_23 ( struct V_43 * V_44 , unsigned int V_45 )
{
return V_44 -> V_46 & V_45 ;
}
int F_24 ( struct V_43 * V_44 , unsigned int V_45 )
{
return V_44 -> V_9 -> V_48 [ V_44 -> V_49 ] . V_46 & V_45 ;
}
void F_25 ( struct V_8 * V_9 , struct V_43 * V_44 ,
unsigned int V_50 )
{
F_26 ( ( V_44 -> V_46 & V_50 ) != V_50 ) ;
F_7 ( 1 , L_5 , V_7 ) ;
F_21 ( & V_9 -> V_47 ) ;
V_44 -> V_46 &= ~ V_50 ;
V_9 -> V_48 [ V_44 -> V_49 ] . V_46 &= ~ V_50 ;
F_7 ( 1 , L_8 , V_50 ) ;
F_22 ( & V_9 -> V_47 ) ;
}
int F_27 ( struct V_8 * V_9 , unsigned int V_51 )
{
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
F_7 ( 1 , L_9 ,
V_7 , V_51 , F_28 ( V_51 ) -> V_54 , F_28 ( V_51 ) -> V_55 ,
F_28 ( V_51 ) -> V_56 , F_28 ( V_51 ) -> V_57 , F_28 ( V_51 ) -> V_58 ) ;
V_9 -> V_51 = V_51 ;
V_53 . V_51 = F_28 ( V_51 ) -> V_54 ;
F_16 ( V_9 , V_59 , V_60 , F_28 ( V_51 ) -> V_54 , 0 , 0 ) ;
return 0 ;
}
int F_29 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_13 * V_14 ,
struct V_61 * V_62 )
{
int V_63 = 0 ;
F_30 ( V_9 , V_62 , V_14 -> V_64 , V_14 -> V_65 . V_66 ) ;
F_31 ( V_62 -> V_67 , 3 ) ;
V_11 -> V_12 = 1 ;
F_32 ( V_68 , F_33 ( V_68 ) | ( 1 << V_62 -> V_4 ) ) ;
F_32 ( V_62 -> V_69 , 0x11 ) ;
F_31 ( V_62 -> V_70 , 0x11 ) ;
V_63 = F_33 ( V_71 ) ;
F_31 ( V_71 , V_63 & 0xFFFFFE00 ) ;
return 0 ;
}
int F_34 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_61 * V_62 )
{
struct V_13 * V_14 , * V_72 ;
struct V_73 * V_74 ;
if ( ! F_6 ( & V_11 -> V_16 ) ) {
V_14 = F_8 ( V_11 -> V_16 . V_17 , struct V_13 ,
V_18 . V_19 ) ;
F_29 ( V_9 , V_11 , V_14 , V_62 ) ;
F_35 (item, &q->active) {
V_14 = F_8 ( V_74 , struct V_13 , V_18 . V_19 ) ;
V_14 -> V_12 = V_11 -> V_12 ++ ;
}
F_13 ( & V_11 -> V_25 , V_26 + V_27 ) ;
return 0 ;
}
V_72 = NULL ;
for (; ; ) {
if ( F_6 ( & V_11 -> V_75 ) )
return 0 ;
V_14 = F_8 ( V_11 -> V_75 . V_17 , struct V_13 ,
V_18 . V_19 ) ;
if ( NULL == V_72 ) {
F_36 ( & V_14 -> V_18 . V_19 , & V_11 -> V_16 ) ;
F_29 ( V_9 , V_11 , V_14 , V_62 ) ;
V_14 -> V_18 . V_22 = V_76 ;
V_14 -> V_12 = V_11 -> V_12 ++ ;
F_13 ( & V_11 -> V_25 , V_26 + V_27 ) ;
} else if ( V_72 -> V_18 . V_77 == V_14 -> V_18 . V_77 &&
V_72 -> V_18 . V_78 == V_14 -> V_18 . V_78 &&
V_72 -> V_79 == V_14 -> V_79 ) {
F_36 ( & V_14 -> V_18 . V_19 , & V_11 -> V_16 ) ;
V_14 -> V_18 . V_22 = V_76 ;
V_14 -> V_12 = V_11 -> V_12 ++ ;
V_72 -> V_65 . V_80 [ 1 ] = F_37 ( V_14 -> V_65 . V_66 ) ;
V_72 -> V_65 . V_80 [ 2 ] = F_37 ( 0 ) ;
} else {
return 0 ;
}
V_72 = V_14 ;
}
}
void F_38 ( unsigned long V_81 )
{
struct V_82 * V_83 = (struct V_82 * ) V_81 ;
struct V_8 * V_9 = V_83 -> V_9 ;
struct V_61 * V_62 = V_83 -> V_62 ;
struct V_10 * V_11 = & V_9 -> V_48 [ V_62 -> V_4 ] . V_84 ;
struct V_13 * V_14 ;
unsigned long V_85 ;
F_39 ( V_62 -> V_70 , 0x11 ) ;
F_40 ( & V_9 -> V_86 , V_85 ) ;
while ( ! F_6 ( & V_11 -> V_16 ) ) {
V_14 = F_8 ( V_11 -> V_16 . V_17 , struct V_13 ,
V_18 . V_19 ) ;
F_10 ( & V_14 -> V_18 . V_19 ) ;
V_14 -> V_18 . V_22 = V_87 ;
F_11 ( & V_14 -> V_18 . V_24 ) ;
}
F_34 ( V_9 , V_11 , V_62 ) ;
F_41 ( & V_9 -> V_86 , V_85 ) ;
}
int F_42 ( struct V_8 * V_9 , int V_88 , T_1 V_89 )
{
T_1 V_12 = 0 ;
int V_90 = 0 ;
T_1 V_91 ;
struct V_61 * V_62 = V_9 -> V_48 [ V_88 ] . V_92 ;
V_91 = F_33 ( V_62 -> V_69 ) ;
if ( 0 == ( V_89 & V_91 ) )
return V_90 ;
F_31 ( V_62 -> V_93 , V_89 ) ;
if ( V_89 & ( 1 << 16 ) ) {
F_43 ( L_10 ,
V_9 -> V_40 , V_62 -> V_40 ) ;
F_39 ( V_62 -> V_70 , 0x11 ) ;
F_44 ( V_9 , V_62 ) ;
}
if ( V_89 & V_94 ) {
F_45 ( & V_9 -> V_86 ) ;
V_12 = F_33 ( V_62 -> V_95 ) ;
F_5 ( V_9 , & V_9 -> V_48 [ V_62 -> V_4 ] . V_84 ,
V_12 ) ;
F_46 ( & V_9 -> V_86 ) ;
V_90 ++ ;
}
if ( V_89 & 0x10 ) {
F_7 ( 2 , L_11 ) ;
F_45 ( & V_9 -> V_86 ) ;
F_34 ( V_9 ,
& V_9 -> V_48 [ V_62 -> V_4 ] . V_84 , V_62 ) ;
F_46 ( & V_9 -> V_86 ) ;
V_90 ++ ;
}
return V_90 ;
}
void F_47 ( struct V_8 * V_9 )
{
if ( V_9 -> V_96 ) {
if ( F_48 ( V_9 -> V_96 ) )
F_49 ( V_9 -> V_96 ) ;
else
V_39 ( V_9 -> V_96 ) ;
V_9 -> V_96 = NULL ;
}
}
void F_50 ( struct V_8 * V_9 , int V_88 )
{
F_39 ( V_68 , 1 ) ;
if ( V_9 -> V_48 [ V_88 ] . V_97 ) {
if ( F_48 ( V_9 -> V_48 [ V_88 ] . V_97 ) )
F_49 (
V_9 -> V_48 [ V_88 ] . V_97 ) ;
else
V_39 (
V_9 -> V_48 [ V_88 ] . V_97 ) ;
V_9 -> V_48 [ V_88 ] . V_97 = NULL ;
F_51 ( V_9 -> V_34 ,
& V_9 -> V_48 [ V_88 ] . V_84 . V_98 ) ;
F_43 ( L_12 , V_88 ) ;
}
}
int F_52 ( struct V_8 * V_9 )
{
int V_99 ;
int V_4 ;
struct V_32 V_100 = {
. V_40 = L_13 ,
. V_101 = & V_102 ,
. V_103 = - 1 ,
. V_104 = & V_105 ,
. V_106 = V_107 ,
. V_108 = V_109 ,
} ;
F_53 ( & V_9 -> V_86 ) ;
for ( V_4 = 0 ; V_4 < V_110 - 1 ; ++ V_4 ) {
F_54 ( V_9 , V_4 ) ;
F_55 ( V_9 -> V_34 , & V_9 -> V_48 [ V_4 ] . V_84 . V_98 ,
V_9 -> V_48 [ V_4 ] . V_92 -> V_70 , 0x11 , 0 ) ;
V_9 -> V_48 [ V_4 ] . V_92 = & V_111 [ V_4 ] ;
V_9 -> V_48 [ V_4 ] . V_97 = NULL ;
V_9 -> V_48 [ V_4 ] . V_46 = 0 ;
F_31 ( V_9 -> V_48 [ V_4 ] . V_92 -> V_93 , 0xffffffff ) ;
F_56 ( & V_9 -> V_48 [ V_4 ] . V_84 . V_16 ) ;
F_56 ( & V_9 -> V_48 [ V_4 ] . V_84 . V_75 ) ;
V_9 -> V_48 [ V_4 ] . V_83 . V_9 = V_9 ;
V_9 -> V_48 [ V_4 ] . V_83 . V_62 =
& V_111 [ V_4 ] ;
V_9 -> V_48 [ V_4 ] . V_84 . V_25 . V_112 = F_38 ;
V_9 -> V_48 [ V_4 ] . V_84 . V_25 . V_81 =
( unsigned long ) & V_9 -> V_48 [ V_4 ] . V_83 ;
F_57 ( & V_9 -> V_48 [ V_4 ] . V_84 . V_25 ) ;
V_9 -> V_48 [ V_4 ] . V_97 = F_17 ( V_9 , V_9 -> V_34 ,
& V_100 , L_14 ) ;
V_99 = F_58 ( V_9 -> V_48 [ V_4 ] . V_97 ,
V_113 , V_114 [ V_9 -> V_115 ] ) ;
if ( V_99 < 0 )
goto V_116;
}
F_32 ( V_68 , 0xff ) ;
F_21 ( & V_9 -> V_47 ) ;
#ifdef F_59
V_9 -> V_29 = V_100 . V_108 ;
F_14 ( V_9 , V_9 -> V_29 ) ;
#endif
F_22 ( & V_9 -> V_47 ) ;
return 0 ;
V_116:
F_50 ( V_9 , V_4 ) ;
return V_99 ;
}
int F_60 ( struct V_117 * V_11 , unsigned int * V_12 ,
unsigned int * V_118 )
{
struct V_43 * V_44 = V_11 -> V_119 ;
* V_118 = V_44 -> V_79 -> V_120 * V_44 -> V_77 * V_44 -> V_78 >> 3 ;
if ( 0 == * V_12 )
* V_12 = 32 ;
if ( * V_118 * * V_12 > V_121 * 1024 * 1024 )
* V_12 = ( V_121 * 1024 * 1024 ) / * V_118 ;
return 0 ;
}
int F_61 ( struct V_117 * V_11 , struct V_122 * V_18 ,
enum V_123 V_124 )
{
struct V_43 * V_44 = V_11 -> V_119 ;
struct V_8 * V_9 = V_44 -> V_9 ;
struct V_13 * V_14 =
F_62 ( V_18 , struct V_13 , V_18 ) ;
int V_125 , V_126 = 0 ;
T_1 V_127 ;
struct V_128 * V_66 = F_63 ( & V_14 -> V_18 ) ;
int V_129 = V_130 ;
int V_131 = V_44 -> V_49 ;
F_26 ( NULL == V_44 -> V_79 ) ;
if ( V_44 -> V_77 < 48 || V_44 -> V_77 > 720 ||
V_44 -> V_78 < 32 || V_44 -> V_78 > 576 )
return - V_132 ;
V_14 -> V_18 . V_118 = ( V_44 -> V_77 * V_44 -> V_78 * V_44 -> V_79 -> V_120 ) >> 3 ;
if ( 0 != V_14 -> V_18 . V_133 && V_14 -> V_18 . V_134 < V_14 -> V_18 . V_118 )
return - V_132 ;
if ( V_14 -> V_79 != V_44 -> V_79 ||
V_14 -> V_18 . V_77 != V_44 -> V_77 ||
V_14 -> V_18 . V_78 != V_44 -> V_78 || V_14 -> V_18 . V_124 != V_124 ) {
V_14 -> V_79 = V_44 -> V_79 ;
V_14 -> V_18 . V_77 = V_44 -> V_77 ;
V_14 -> V_18 . V_78 = V_44 -> V_78 ;
V_14 -> V_18 . V_124 = V_124 ;
V_126 = 1 ;
}
if ( V_135 == V_14 -> V_18 . V_22 ) {
V_126 = 1 ;
V_125 = F_64 ( V_11 , & V_14 -> V_18 , NULL ) ;
if ( 0 != V_125 ) {
F_65 (KERN_DEBUG pr_fmt(L_15)) ;
goto V_136;
}
}
F_7 ( 1 , L_16 , V_126 ) ;
if ( V_126 ) {
V_131 = V_9 -> V_131 ;
if ( V_131 < 0 || V_131 > 7 )
V_131 = 7 ;
if ( V_9 -> V_48 [ V_131 ] . V_137 ==
V_138 )
V_14 -> V_64 = ( V_14 -> V_79 -> V_120 * V_14 -> V_18 . V_77 ) >> 3 ;
else
V_14 -> V_64 = ( V_14 -> V_79 -> V_120 >> 3 ) * ( V_14 -> V_18 . V_77 ) ;
if ( V_9 -> V_48 [ V_131 ] . V_137 ==
V_138 ) {
V_129 = V_14 -> V_64 ;
} else {
V_129 = V_14 -> V_64 ;
if ( V_131 >= 0 && V_131 <= 7 ) {
if ( V_9 -> V_48 [ V_131 ]
. V_139 ) {
if ( V_9 -> V_29 & V_140 ||
V_9 -> V_29 & V_141 )
V_129 = 352 << 1 ;
else
V_129 = V_9 -> V_48 [
V_131 ] .
V_142 << 1 ;
}
}
}
switch ( V_14 -> V_18 . V_124 ) {
case V_143 :
F_66 ( V_9 -> V_34 , & V_14 -> V_65 ,
V_66 -> V_144 , 0 , V_145 ,
V_14 -> V_64 , 0 , V_14 -> V_18 . V_78 ) ;
break;
case V_146 :
F_66 ( V_9 -> V_34 , & V_14 -> V_65 ,
V_66 -> V_144 , V_145 , 0 ,
V_14 -> V_64 , 0 , V_14 -> V_18 . V_78 ) ;
break;
case V_147 :
V_127 = 0 ;
F_7 ( 1 , L_17 ) ;
F_66 ( V_9 -> V_34 , & V_14 -> V_65 ,
V_66 -> V_144 , V_127 ,
V_129 , V_129 , V_129 ,
V_14 -> V_18 . V_78 >> 1 ) ;
break;
case V_148 :
F_66 ( V_9 -> V_34 , & V_14 -> V_65 ,
V_66 -> V_144 ,
0 , V_14 -> V_64 * ( V_14 -> V_18 . V_78 >> 1 ) ,
V_14 -> V_64 , 0 , V_14 -> V_18 . V_78 >> 1 ) ;
break;
case V_149 :
F_66 ( V_9 -> V_34 , & V_14 -> V_65 ,
V_66 -> V_144 ,
V_14 -> V_64 * ( V_14 -> V_18 . V_78 >> 1 ) , 0 ,
V_14 -> V_64 , 0 , V_14 -> V_18 . V_78 >> 1 ) ;
break;
default:
F_67 () ;
}
}
F_7 ( 2 , L_18 ,
V_14 , V_14 -> V_18 . V_4 , V_44 -> V_77 , V_44 -> V_78 , V_44 -> V_79 -> V_120 ,
V_44 -> V_79 -> V_40 , ( unsigned long ) V_14 -> V_65 . V_66 ) ;
V_14 -> V_18 . V_22 = V_150 ;
return 0 ;
V_136:
F_68 ( V_11 , V_14 ) ;
return V_125 ;
}
void F_69 ( struct V_117 * V_11 ,
struct V_122 * V_18 )
{
struct V_13 * V_14 =
F_62 ( V_18 , struct V_13 , V_18 ) ;
F_68 ( V_11 , V_14 ) ;
}
struct V_117 * F_70 ( struct V_43 * V_44 )
{
switch ( V_44 -> type ) {
case V_151 :
return & V_44 -> V_84 ;
default:
F_67 () ;
return NULL ;
}
}
int F_71 ( struct V_43 * V_44 , int V_152 )
{
switch ( V_44 -> type ) {
case V_151 :
return V_152 ;
default:
F_67 () ;
return 0 ;
}
}
int F_72 ( struct V_153 * V_153 , struct V_154 * V_155 )
{
struct V_43 * V_44 = V_153 -> V_156 ;
return F_73 ( F_70 ( V_44 ) , V_155 ) ;
}
static void F_74 ( struct V_117 * V_157 , struct V_122 * V_18 )
{
struct V_13 * V_14 =
F_62 ( V_18 , struct V_13 , V_18 ) ;
struct V_13 * V_72 ;
struct V_43 * V_44 = V_157 -> V_119 ;
struct V_8 * V_9 = V_44 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_48 [ V_44 -> V_49 ] . V_84 ;
V_14 -> V_65 . V_80 [ 0 ] = F_37 ( V_158 | V_159 | V_160 ) ;
V_14 -> V_65 . V_80 [ 1 ] = F_37 ( V_11 -> V_98 . V_66 ) ;
V_14 -> V_65 . V_80 [ 2 ] = F_37 ( 0 ) ;
F_7 ( 2 , L_19 , V_14 -> V_65 . V_80 [ 1 ] ) ;
if ( ! F_6 ( & V_11 -> V_75 ) ) {
F_75 ( & V_14 -> V_18 . V_19 , & V_11 -> V_75 ) ;
V_14 -> V_18 . V_22 = V_161 ;
F_7 ( 2 , L_20 , V_14 ,
V_14 -> V_18 . V_4 ) ;
} else if ( F_6 ( & V_11 -> V_16 ) ) {
F_75 ( & V_14 -> V_18 . V_19 , & V_11 -> V_16 ) ;
F_29 ( V_9 , V_11 , V_14 ,
V_9 -> V_48 [ V_44 -> V_49 ] . V_92 ) ;
V_14 -> V_18 . V_22 = V_76 ;
V_14 -> V_12 = V_11 -> V_12 ++ ;
F_13 ( & V_11 -> V_25 , V_26 + V_27 ) ;
F_7 ( 2 , L_21 ,
V_14 , V_14 -> V_18 . V_4 , V_14 -> V_12 , V_11 -> V_12 ) ;
} else {
V_72 = F_8 ( V_11 -> V_16 . V_72 , struct V_13 ,
V_18 . V_19 ) ;
if ( V_72 -> V_18 . V_77 == V_14 -> V_18 . V_77
&& V_72 -> V_18 . V_78 == V_14 -> V_18 . V_78
&& V_72 -> V_79 == V_14 -> V_79 ) {
F_75 ( & V_14 -> V_18 . V_19 , & V_11 -> V_16 ) ;
V_14 -> V_18 . V_22 = V_76 ;
V_14 -> V_12 = V_11 -> V_12 ++ ;
V_72 -> V_65 . V_80 [ 1 ] = F_37 ( V_14 -> V_65 . V_66 ) ;
V_72 -> V_65 . V_80 [ 2 ] = F_37 ( 0 ) ;
F_7 ( 2 , L_22 ,
V_14 , V_14 -> V_18 . V_4 , V_14 -> V_12 ) ;
} else {
F_75 ( & V_14 -> V_18 . V_19 , & V_11 -> V_75 ) ;
V_14 -> V_18 . V_22 = V_161 ;
F_7 ( 2 , L_23 , V_14 ,
V_14 -> V_18 . V_4 ) ;
}
}
if ( F_6 ( & V_11 -> V_16 ) )
F_7 ( 2 , L_24 ) ;
}
static int F_76 ( struct V_153 * V_153 )
{
struct V_32 * V_162 = F_77 ( V_153 ) ;
struct V_8 * V_163 , * V_9 = F_78 ( V_153 ) ;
struct V_43 * V_44 ;
struct V_73 * V_164 ;
int V_103 = F_77 ( V_153 ) -> V_103 ;
enum V_165 type = V_151 ;
T_1 V_166 ;
int V_167 = 0 ;
int V_4 ;
F_7 ( 1 , L_25 , F_79 ( V_162 ) ,
V_168 [ type ] ) ;
V_44 = F_80 ( sizeof( * V_44 ) , V_169 ) ;
if ( NULL == V_44 )
return - V_170 ;
F_21 ( & V_171 ) ;
F_35 (list, &cx25821_devlist)
{
V_163 = F_8 ( V_164 , struct V_8 , V_172 ) ;
for ( V_4 = 0 ; V_4 < V_110 ; V_4 ++ ) {
if ( V_163 -> V_48 [ V_4 ] . V_97 &&
V_163 -> V_48 [ V_4 ] . V_97 -> V_103 == V_103 ) {
V_9 = V_163 ;
V_167 = V_4 ;
type = V_151 ;
}
}
}
if ( NULL == V_9 ) {
F_22 ( & V_171 ) ;
F_81 ( V_44 ) ;
return - V_173 ;
}
V_153 -> V_156 = V_44 ;
V_44 -> V_9 = V_9 ;
V_44 -> type = type ;
V_44 -> V_77 = 720 ;
V_44 -> V_49 = V_167 ;
if ( V_9 -> V_29 & V_140 || V_9 -> V_29 & V_141 )
V_44 -> V_78 = 576 ;
else
V_44 -> V_78 = 480 ;
V_9 -> V_131 = V_44 -> V_49 ;
if ( V_9 -> V_48 [ V_167 ] . V_137 == V_138 )
V_166 = V_5 ;
else
V_166 = V_174 ;
V_44 -> V_79 = F_3 ( V_166 ) ;
F_82 ( & V_9 -> V_48 [ V_167 ] . V_175 , & V_44 -> V_175 ) ;
F_83 ( & V_44 -> V_84 , & V_176 , & V_9 -> V_34 -> V_9 ,
& V_9 -> V_86 , V_151 ,
V_147 , sizeof( struct V_13 ) ,
V_44 , NULL ) ;
F_7 ( 1 , L_26 ) ;
F_22 ( & V_171 ) ;
return 0 ;
}
static T_3 F_84 ( struct V_153 * V_153 , char T_4 * V_81 , T_5 V_12 ,
T_6 * V_177 )
{
struct V_43 * V_44 = V_153 -> V_156 ;
switch ( V_44 -> type ) {
case V_151 :
if ( F_24 ( V_44 , V_178 ) )
return - V_179 ;
return F_85 ( & V_44 -> V_84 , V_81 , V_12 , V_177 ,
V_153 -> V_180 & V_181 ) ;
default:
F_67 () ;
return 0 ;
}
}
static unsigned int F_86 ( struct V_153 * V_153 ,
struct V_182 * V_183 )
{
struct V_43 * V_44 = V_153 -> V_156 ;
struct V_13 * V_14 ;
if ( F_23 ( V_44 , V_178 ) ) {
if ( F_6 ( & V_44 -> V_84 . V_184 ) )
return V_185 ;
V_14 = F_8 ( V_44 -> V_84 . V_184 . V_17 ,
struct V_13 , V_18 . V_184 ) ;
} else {
V_14 = (struct V_13 * ) V_44 -> V_84 . V_186 ;
if ( NULL == V_14 )
return V_185 ;
}
F_87 ( V_153 , & V_14 -> V_18 . V_24 , V_183 ) ;
if ( V_14 -> V_18 . V_22 == V_23 || V_14 -> V_18 . V_22 == V_87 ) {
if ( V_14 -> V_18 . V_22 == V_23 ) {
struct V_8 * V_9 = V_44 -> V_9 ;
if ( V_9 && V_9 -> V_48 [ V_44 -> V_49 ]
. V_139 ) {
T_7 V_187 = * ( ( char * ) V_14 -> V_18 . V_133 + 3 ) ;
memcpy ( ( char * ) V_14 -> V_18 . V_133 ,
( char * ) V_14 -> V_18 . V_133 + ( V_44 -> V_77 * 2 ) ,
( V_44 -> V_77 * 2 ) ) ;
* ( ( char * ) V_14 -> V_18 . V_133 + 3 ) = V_187 ;
}
}
return V_188 | V_189 ;
}
return 0 ;
}
static int F_88 ( struct V_153 * V_153 )
{
struct V_43 * V_44 = V_153 -> V_156 ;
struct V_8 * V_9 = V_44 -> V_9 ;
F_31 ( V_190 -> V_70 , 0 ) ;
if ( F_23 ( V_44 , V_178 ) ) {
F_89 ( & V_44 -> V_84 ) ;
F_25 ( V_9 , V_44 , V_178 ) ;
}
if ( V_44 -> V_84 . V_186 ) {
F_69 ( & V_44 -> V_84 , V_44 -> V_84 . V_186 ) ;
F_81 ( V_44 -> V_84 . V_186 ) ;
}
F_90 ( & V_44 -> V_84 ) ;
F_91 ( & V_9 -> V_48 [ V_44 -> V_49 ] . V_175 , V_44 -> V_175 ) ;
V_153 -> V_156 = NULL ;
F_81 ( V_44 ) ;
return 0 ;
}
static int F_92 ( struct V_153 * V_153 , void * V_191 , enum V_165 V_4 )
{
struct V_43 * V_44 = V_191 ;
struct V_8 * V_9 = V_44 -> V_9 ;
if ( F_93 ( V_44 -> type != V_151 ) )
return - V_132 ;
if ( F_93 ( V_4 != V_44 -> type ) )
return - V_132 ;
if ( F_93 ( ! F_20 ( V_9 , V_44 , F_71 ( V_44 ,
V_178 ) ) ) )
return - V_179 ;
return F_94 ( F_70 ( V_44 ) ) ;
}
static int F_95 ( struct V_153 * V_153 , void * V_191 , enum V_165 V_4 )
{
struct V_43 * V_44 = V_191 ;
struct V_8 * V_9 = V_44 -> V_9 ;
int V_99 , V_192 ;
if ( V_44 -> type != V_151 )
return - V_132 ;
if ( V_4 != V_44 -> type )
return - V_132 ;
V_192 = F_71 ( V_44 , V_178 ) ;
V_99 = F_96 ( F_70 ( V_44 ) ) ;
if ( V_99 < 0 )
return V_99 ;
F_25 ( V_9 , V_44 , V_192 ) ;
return 0 ;
}
static int F_97 ( struct V_153 * V_153 , void * V_191 ,
struct V_193 * V_194 )
{
struct V_43 * V_44 = V_191 ;
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
struct V_195 V_196 ;
int V_99 ;
int V_166 = V_197 ;
if ( V_44 ) {
V_99 = F_98 ( & V_9 -> V_48 [ V_44 -> V_49 ] . V_175 ,
V_44 -> V_175 ) ;
if ( 0 != V_99 )
return V_99 ;
}
F_7 ( 2 , L_5 , V_7 ) ;
V_99 = F_99 ( V_153 , V_191 , V_194 ) ;
if ( 0 != V_99 )
return V_99 ;
V_44 -> V_79 = F_3 ( V_194 -> V_79 . V_198 . V_199 ) ;
V_44 -> V_84 . V_124 = V_194 -> V_79 . V_198 . V_124 ;
if ( F_100 ( V_194 -> V_79 . V_198 . V_77 , V_9 -> V_29 ) )
V_44 -> V_77 = V_194 -> V_79 . V_198 . V_77 ;
if ( F_101 ( V_194 -> V_79 . V_198 . V_78 , V_9 -> V_29 ) )
V_44 -> V_78 = V_194 -> V_79 . V_198 . V_78 ;
if ( V_194 -> V_79 . V_198 . V_199 == V_5 )
V_166 = V_138 ;
else if ( V_194 -> V_79 . V_198 . V_199 == V_174 )
V_166 = V_197 ;
else
return - V_132 ;
F_102 ( V_9 , V_200 , V_166 ) ;
if ( V_44 -> V_77 == 320 || V_44 -> V_77 == 352 )
V_9 -> V_48 [ V_44 -> V_49 ] . V_139 = 1 ;
else
V_9 -> V_48 [ V_44 -> V_49 ] . V_139 = 0 ;
V_9 -> V_48 [ V_44 -> V_49 ] . V_142 = V_44 -> V_77 ;
F_103 ( V_9 , V_44 -> V_77 , V_200 ) ;
F_7 ( 2 , L_27 , V_7 , V_44 -> V_77 ,
V_44 -> V_78 , V_44 -> V_84 . V_124 ) ;
F_104 ( & V_196 , & V_194 -> V_79 . V_198 , V_201 ) ;
F_16 ( V_9 , V_59 , V_202 , & V_196 ) ;
return 0 ;
}
static int F_105 ( struct V_153 * V_153 , void * V_191 , struct V_203 * V_204 )
{
int V_205 = 0 ;
struct V_43 * V_44 = V_191 ;
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
V_205 = F_106 ( F_70 ( V_44 ) , V_204 , V_153 -> V_180 & V_181 ) ;
V_204 -> V_206 = V_9 -> V_48 [ V_44 -> V_49 ] . V_84 . V_12 ;
return V_205 ;
}
static int F_107 ( struct V_153 * V_153 , void * V_191 )
{
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
struct V_43 * V_44 = V_191 ;
char V_40 [ 32 + 2 ] ;
struct V_61 * V_207 = V_9 -> V_48 [ V_44 -> V_49 ]
. V_92 ;
T_1 V_63 = 0 ;
snprintf ( V_40 , sizeof( V_40 ) , L_28 , V_9 -> V_40 ) ;
F_108 ( L_29 ,
V_9 -> V_40 ) ;
F_16 ( V_9 , V_30 , V_208 ) ;
V_63 = F_33 ( V_207 -> V_70 ) ;
F_108 ( L_30 ,
( V_63 & 0x11 ) ? L_31 : L_32 ) ;
F_108 ( L_33 ,
V_9 -> V_40 ) ;
return 0 ;
}
static int F_109 ( struct V_153 * V_153 , void * V_191 ,
struct V_209 * V_210 )
{
struct V_43 * V_44 = V_191 ;
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
int V_99 ;
if ( V_44 ) {
V_99 = F_98 ( & V_9 -> V_48 [ V_44 -> V_49 ] . V_175 ,
V_44 -> V_175 ) ;
if ( 0 != V_99 )
return V_99 ;
}
return F_110 ( V_9 , V_210 , V_44 -> V_49 ) ;
}
int F_111 ( struct V_153 * V_153 , void * V_191 ,
struct V_193 * V_194 )
{
struct V_43 * V_44 = V_191 ;
V_194 -> V_79 . V_198 . V_77 = V_44 -> V_77 ;
V_194 -> V_79 . V_198 . V_78 = V_44 -> V_78 ;
V_194 -> V_79 . V_198 . V_124 = V_44 -> V_84 . V_124 ;
V_194 -> V_79 . V_198 . V_199 = V_44 -> V_79 -> V_3 ;
V_194 -> V_79 . V_198 . V_211 = ( V_194 -> V_79 . V_198 . V_77 * V_44 -> V_79 -> V_120 ) >> 3 ;
V_194 -> V_79 . V_198 . V_212 = V_194 -> V_79 . V_198 . V_78 * V_194 -> V_79 . V_198 . V_211 ;
return 0 ;
}
int F_99 ( struct V_153 * V_153 , void * V_191 ,
struct V_193 * V_194 )
{
struct V_2 * V_79 ;
enum V_123 V_124 ;
unsigned int V_213 , V_214 ;
V_79 = F_3 ( V_194 -> V_79 . V_198 . V_199 ) ;
if ( NULL == V_79 )
return - V_132 ;
V_124 = V_194 -> V_79 . V_198 . V_124 ;
V_213 = 720 ;
V_214 = 576 ;
if ( V_215 == V_124 ) {
if ( V_194 -> V_79 . V_198 . V_78 > V_214 / 2 )
V_124 = V_147 ;
else
V_124 = V_143 ;
}
switch ( V_124 ) {
case V_143 :
case V_146 :
V_214 = V_214 / 2 ;
break;
case V_147 :
break;
default:
return - V_132 ;
}
V_194 -> V_79 . V_198 . V_124 = V_124 ;
if ( V_194 -> V_79 . V_198 . V_78 < 32 )
V_194 -> V_79 . V_198 . V_78 = 32 ;
if ( V_194 -> V_79 . V_198 . V_78 > V_214 )
V_194 -> V_79 . V_198 . V_78 = V_214 ;
if ( V_194 -> V_79 . V_198 . V_77 < 48 )
V_194 -> V_79 . V_198 . V_77 = 48 ;
if ( V_194 -> V_79 . V_198 . V_77 > V_213 )
V_194 -> V_79 . V_198 . V_77 = V_213 ;
V_194 -> V_79 . V_198 . V_77 &= ~ 0x03 ;
V_194 -> V_79 . V_198 . V_211 = ( V_194 -> V_79 . V_198 . V_77 * V_79 -> V_120 ) >> 3 ;
V_194 -> V_79 . V_198 . V_212 = V_194 -> V_79 . V_198 . V_78 * V_194 -> V_79 . V_198 . V_211 ;
return 0 ;
}
int F_112 ( struct V_153 * V_153 , void * V_191 ,
struct V_216 * V_217 )
{
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
strcpy ( V_217 -> V_218 , L_34 ) ;
F_113 ( V_217 -> V_219 , V_41 [ V_9 -> V_42 ] . V_40 , sizeof( V_217 -> V_219 ) ) ;
sprintf ( V_217 -> V_220 , L_35 , F_114 ( V_9 -> V_34 ) ) ;
V_217 -> V_221 = V_222 ;
V_217 -> V_223 = V_224 | V_225 |
V_226 ;
if ( V_145 != V_9 -> V_227 )
V_217 -> V_223 |= V_228 ;
return 0 ;
}
int F_115 ( struct V_153 * V_153 , void * V_191 ,
struct V_229 * V_194 )
{
if ( F_93 ( V_194 -> V_230 >= F_2 ( V_1 ) ) )
return - V_132 ;
F_113 ( V_194 -> V_231 , V_1 [ V_194 -> V_230 ] . V_40 , sizeof( V_194 -> V_231 ) ) ;
V_194 -> V_199 = V_1 [ V_194 -> V_230 ] . V_3 ;
return 0 ;
}
int F_116 ( struct V_153 * V_153 , void * V_191 ,
struct V_232 * V_204 )
{
struct V_43 * V_44 = V_191 ;
return F_117 ( F_70 ( V_44 ) , V_204 ) ;
}
int F_118 ( struct V_153 * V_153 , void * V_191 ,
struct V_203 * V_204 )
{
struct V_43 * V_44 = V_191 ;
return F_119 ( F_70 ( V_44 ) , V_204 ) ;
}
int F_120 ( struct V_153 * V_153 , void * V_191 , struct V_203 * V_204 )
{
struct V_43 * V_44 = V_191 ;
return F_121 ( F_70 ( V_44 ) , V_204 ) ;
}
int F_122 ( struct V_153 * V_153 , void * V_194 , enum V_233 * V_204 )
{
struct V_8 * V_9 = ( (struct V_43 * ) V_194 ) -> V_9 ;
struct V_43 * V_44 = V_194 ;
* V_204 = F_123 ( & V_9 -> V_48 [ V_44 -> V_49 ] . V_175 ) ;
return 0 ;
}
int F_124 ( struct V_153 * V_153 , void * V_194 ,
enum V_233 V_175 )
{
struct V_43 * V_44 = V_194 ;
struct V_8 * V_9 = ( (struct V_43 * ) V_194 ) -> V_9 ;
return F_125 ( & V_9 -> V_48 [ V_44 -> V_49 ] . V_175 , & V_44 -> V_175 ,
V_175 ) ;
}
int F_126 ( struct V_153 * V_153 , void * V_191 , T_2 * V_106 )
{
struct V_43 * V_44 = V_191 ;
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
int V_99 ;
F_7 ( 1 , L_5 , V_7 ) ;
if ( V_44 ) {
V_99 = F_98 ( & V_9 -> V_48 [ V_44 -> V_49 ] . V_175 ,
V_44 -> V_175 ) ;
if ( 0 != V_99 )
return V_99 ;
}
if ( V_9 -> V_29 == * V_106 )
return 0 ;
F_21 ( & V_9 -> V_47 ) ;
F_14 ( V_9 , * V_106 ) ;
F_22 ( & V_9 -> V_47 ) ;
F_127 ( V_9 ) ;
return 0 ;
}
int F_128 ( struct V_8 * V_9 , struct V_234 * V_4 )
{
static const char * const V_235 [] = {
[ V_236 ] = L_36 ,
[ V_237 ] = L_37 ,
[ V_238 ] = L_38 ,
} ;
unsigned int V_239 ;
F_7 ( 1 , L_5 , V_7 ) ;
V_239 = V_4 -> V_230 ;
if ( V_239 >= 2 )
return - V_132 ;
if ( 0 == F_28 ( V_239 ) -> type )
return - V_132 ;
V_4 -> type = V_240 ;
strcpy ( V_4 -> V_40 , V_235 [ F_28 ( V_239 ) -> type ] ) ;
V_4 -> V_241 = V_107 ;
return 0 ;
}
int F_129 ( struct V_153 * V_153 , void * V_191 ,
struct V_234 * V_4 )
{
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
F_7 ( 1 , L_5 , V_7 ) ;
return F_128 ( V_9 , V_4 ) ;
}
int F_130 ( struct V_153 * V_153 , void * V_191 , unsigned int * V_4 )
{
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
* V_4 = V_9 -> V_51 ;
F_7 ( 1 , L_39 , V_7 , * V_4 ) ;
return 0 ;
}
int F_131 ( struct V_153 * V_153 , void * V_191 , unsigned int V_4 )
{
struct V_43 * V_44 = V_191 ;
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
int V_99 ;
F_7 ( 1 , L_40 , V_7 , V_4 ) ;
if ( V_44 ) {
V_99 = F_98 ( & V_9 -> V_48 [ V_44 -> V_49 ] . V_175 ,
V_44 -> V_175 ) ;
if ( 0 != V_99 )
return V_99 ;
}
if ( V_4 >= V_242 ) {
F_7 ( 1 , L_41 , V_7 ) ;
return - V_132 ;
}
F_21 ( & V_9 -> V_47 ) ;
F_27 ( V_9 , V_4 ) ;
F_22 ( & V_9 -> V_47 ) ;
return 0 ;
}
int F_132 ( struct V_153 * V_153 , void * V_191 ,
struct V_243 * V_194 )
{
struct V_43 * V_44 = V_191 ;
struct V_8 * V_9 = V_44 -> V_9 ;
V_194 -> V_244 = V_9 -> V_245 ;
F_16 ( V_9 , V_246 , V_247 , V_194 ) ;
return 0 ;
}
int F_133 ( struct V_8 * V_9 , struct V_243 * V_194 )
{
F_21 ( & V_9 -> V_47 ) ;
V_9 -> V_245 = V_194 -> V_244 ;
F_16 ( V_9 , V_246 , V_248 , V_194 ) ;
F_134 ( 10 ) ;
F_22 ( & V_9 -> V_47 ) ;
return 0 ;
}
int F_135 ( struct V_153 * V_153 , void * V_191 ,
struct V_243 * V_194 )
{
struct V_43 * V_44 = V_191 ;
struct V_8 * V_9 ;
int V_99 ;
if ( V_44 ) {
V_9 = V_44 -> V_9 ;
V_99 = F_98 ( & V_9 -> V_48 [ V_44 -> V_49 ] . V_175 ,
V_44 -> V_175 ) ;
if ( 0 != V_99 )
return V_99 ;
} else {
F_4 ( L_42 ) ;
return - V_132 ;
}
return F_133 ( V_9 , V_194 ) ;
}
int F_136 ( struct V_153 * V_153 , void * V_44 ,
struct V_249 * V_250 )
{
struct V_8 * V_9 = ( (struct V_43 * ) V_44 ) -> V_9 ;
if ( ! F_137 ( & V_250 -> V_251 ) )
return - V_132 ;
F_16 ( V_9 , V_30 , V_252 , V_250 ) ;
return 0 ;
}
int F_138 ( struct V_153 * V_153 , void * V_44 ,
struct V_249 * V_250 )
{
struct V_8 * V_9 = ( (struct V_43 * ) V_44 ) -> V_9 ;
if ( ! F_137 ( & V_250 -> V_251 ) )
return - V_132 ;
F_16 ( V_9 , V_30 , V_253 , V_250 ) ;
return 0 ;
}
int F_139 ( struct V_153 * V_153 , void * V_191 , struct V_254 * V_255 )
{
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
if ( F_93 ( V_145 == V_9 -> V_227 ) )
return - V_132 ;
if ( 0 != V_255 -> V_230 )
return - V_132 ;
strcpy ( V_255 -> V_40 , L_43 ) ;
V_255 -> type = V_256 ;
V_255 -> V_257 = V_258 ;
V_255 -> V_259 = 0xffffffffUL ;
V_255 -> signal = 0xffff ;
return 0 ;
}
int F_140 ( struct V_153 * V_153 , void * V_191 , struct V_254 * V_255 )
{
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
struct V_43 * V_44 = V_191 ;
int V_99 ;
if ( V_44 ) {
V_99 = F_98 ( & V_9 -> V_48 [ V_44 -> V_49 ] . V_175 ,
V_44 -> V_175 ) ;
if ( 0 != V_99 )
return V_99 ;
}
F_7 ( 1 , L_5 , V_7 ) ;
if ( V_145 == V_9 -> V_227 )
return - V_132 ;
if ( 0 != V_255 -> V_230 )
return - V_132 ;
return 0 ;
}
static int F_141 ( struct V_260 * V_261 )
{
int V_4 ;
if ( V_261 -> V_262 < V_263 || V_261 -> V_262 >= V_264 )
return - V_132 ;
for ( V_4 = 0 ; V_4 < V_265 ; V_4 ++ )
if ( V_266 [ V_4 ] . V_262 == V_261 -> V_262 )
break;
if ( V_4 == V_265 ) {
* V_261 = V_267 ;
return 0 ;
}
* V_261 = V_266 [ V_4 ] ;
return 0 ;
}
int F_142 ( struct V_153 * V_153 , void * V_191 ,
struct V_260 * V_261 )
{
return F_141 ( V_261 ) ;
}
static const struct V_260 * F_143 ( unsigned int V_262 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_265 ; V_4 ++ )
if ( V_266 [ V_4 ] . V_262 == V_262 )
return V_266 + V_4 ;
return NULL ;
}
int F_144 ( struct V_153 * V_153 , void * V_191 ,
struct V_209 * V_210 )
{
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
struct V_43 * V_44 = V_191 ;
const struct V_260 * V_268 ;
V_268 = F_143 ( V_210 -> V_262 ) ;
if ( NULL == V_268 )
return - V_132 ;
switch ( V_210 -> V_262 ) {
case V_269 :
V_210 -> V_270 = V_9 -> V_48 [ V_44 -> V_49 ] . V_271 ;
break;
case V_272 :
V_210 -> V_270 = V_9 -> V_48 [ V_44 -> V_49 ] . V_273 ;
break;
case V_274 :
V_210 -> V_270 = V_9 -> V_48 [ V_44 -> V_49 ] . V_275 ;
break;
case V_276 :
V_210 -> V_270 = V_9 -> V_48 [ V_44 -> V_49 ] . V_277 ;
break;
}
return 0 ;
}
int F_110 ( struct V_8 * V_9 ,
struct V_209 * V_210 , int V_88 )
{
int V_99 ;
const struct V_260 * V_268 ;
V_99 = - V_132 ;
V_268 = F_143 ( V_210 -> V_262 ) ;
if ( NULL == V_268 )
return V_99 ;
switch ( V_268 -> type ) {
case V_278 :
case V_279 :
case V_280 :
if ( V_210 -> V_270 < V_268 -> V_281 )
V_210 -> V_270 = V_268 -> V_281 ;
if ( V_210 -> V_270 > V_268 -> V_282 )
V_210 -> V_270 = V_268 -> V_282 ;
break;
default:
;
}
switch ( V_210 -> V_262 ) {
case V_269 :
V_9 -> V_48 [ V_88 ] . V_271 = V_210 -> V_270 ;
F_145 ( V_9 , V_210 -> V_270 , V_88 ) ;
break;
case V_272 :
V_9 -> V_48 [ V_88 ] . V_273 = V_210 -> V_270 ;
F_146 ( V_9 , V_210 -> V_270 , V_88 ) ;
break;
case V_274 :
V_9 -> V_48 [ V_88 ] . V_275 = V_210 -> V_270 ;
F_147 ( V_9 , V_210 -> V_270 , V_88 ) ;
break;
case V_276 :
V_9 -> V_48 [ V_88 ] . V_277 = V_210 -> V_270 ;
F_148 ( V_9 , V_210 -> V_270 , V_88 ) ;
break;
}
V_99 = 0 ;
return V_99 ;
}
static void F_54 ( struct V_8 * V_9 , int V_88 )
{
struct V_209 V_268 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_265 ; V_4 ++ ) {
V_268 . V_262 = V_266 [ V_4 ] . V_262 ;
V_268 . V_270 = V_266 [ V_4 ] . V_283 ;
F_110 ( V_9 , & V_268 , V_88 ) ;
}
}
int F_149 ( struct V_153 * V_153 , void * V_191 ,
struct V_284 * V_285 )
{
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
if ( V_285 -> type != V_151 )
return - V_132 ;
V_285 -> V_286 . V_287 = 0 ;
V_285 -> V_286 . V_288 = 0 ;
V_285 -> V_286 . V_77 = 720 ;
V_285 -> V_286 . V_78 = V_9 -> V_29 == V_140 ? 576 : 480 ;
V_285 -> V_289 . V_290 =
V_9 -> V_29 == V_140 ? 59 : 10 ;
V_285 -> V_289 . V_291 =
V_9 -> V_29 == V_140 ? 54 : 11 ;
V_285 -> V_292 = V_285 -> V_286 ;
return 0 ;
}
int F_150 ( struct V_153 * V_153 , void * V_191 , struct V_293 * V_294 )
{
struct V_8 * V_9 = ( (struct V_43 * ) V_191 ) -> V_9 ;
struct V_43 * V_44 = V_191 ;
int V_99 ;
if ( V_44 ) {
V_99 = F_98 ( & V_9 -> V_48 [ V_44 -> V_49 ] . V_175 ,
V_44 -> V_175 ) ;
if ( 0 != V_99 )
return V_99 ;
}
return - V_132 ;
}
int F_151 ( struct V_153 * V_153 , void * V_191 , struct V_293 * V_294 )
{
return - V_132 ;
}
int F_152 ( struct V_153 * V_153 , void * V_191 , T_2 * V_28 )
{
* V_28 = V_107 ;
return 0 ;
}
int F_100 ( T_1 V_77 , T_2 V_29 )
{
if ( V_29 == V_140 ) {
if ( V_77 == 352 || V_77 == 720 )
return 1 ;
else
return 0 ;
}
if ( V_29 == V_109 ) {
if ( V_77 == 320 || V_77 == 352 || V_77 == 720 )
return 1 ;
else
return 0 ;
}
return 0 ;
}
int F_101 ( T_1 V_78 , T_2 V_29 )
{
if ( V_29 == V_140 ) {
if ( V_78 == 576 || V_78 == 288 )
return 1 ;
else
return 0 ;
}
if ( V_29 == V_109 ) {
if ( V_78 == 480 || V_78 == 240 )
return 1 ;
else
return 0 ;
}
return 0 ;
}
static long F_153 ( struct V_153 * V_153 , unsigned int V_295 ,
unsigned long V_296 )
{
struct V_43 * V_44 = V_153 -> V_156 ;
struct V_8 * V_9 = V_44 -> V_9 ;
int V_297 = 0 ;
struct V_298 * V_299 ;
V_299 = (struct V_298 * ) V_296 ;
if ( ! V_299 ) {
F_4 ( L_44 , V_7 ) ;
return 0 ;
}
V_297 = V_299 -> V_297 ;
if ( V_297 != V_300 && V_297 != V_301 )
return 0 ;
V_9 -> V_302 = V_299 -> V_302 ;
V_9 -> V_303 = V_299 -> V_302 ;
V_9 -> V_304 = V_299 -> V_304 ;
V_9 -> V_305 = V_299 -> V_305 ;
V_9 -> V_306 = V_299 -> V_306 ;
V_9 -> V_297 = V_299 -> V_297 ;
switch ( V_297 ) {
case V_300 :
F_154 ( V_9 , V_299 ) ;
break;
case V_301 :
F_155 ( V_9 ) ;
break;
}
return 0 ;
}
static long F_156 ( struct V_153 * V_153 , unsigned int V_295 ,
unsigned long V_296 )
{
struct V_43 * V_44 = V_153 -> V_156 ;
struct V_8 * V_9 = V_44 -> V_9 ;
int V_297 = 0 ;
struct V_298 * V_299 ;
V_299 = (struct V_298 * ) V_296 ;
if ( ! V_299 ) {
F_4 ( L_44 , V_7 ) ;
return 0 ;
}
V_297 = V_299 -> V_297 ;
if ( V_297 != V_300 && V_297 != V_301 )
return 0 ;
V_9 -> V_307 = V_299 -> V_302 ;
V_9 -> V_303 = V_299 -> V_302 ;
V_9 -> V_308 = V_299 -> V_304 ;
V_9 -> V_309 = V_299 -> V_305 ;
V_9 -> V_310 = V_299 -> V_306 ;
V_9 -> V_311 = V_299 -> V_297 ;
switch ( V_297 ) {
case V_300 :
F_157 ( V_9 , V_299 ) ;
break;
case V_301 :
F_158 ( V_9 ) ;
break;
}
return 0 ;
}
static long F_159 ( struct V_153 * V_153 , unsigned int V_295 ,
unsigned long V_296 )
{
struct V_43 * V_44 = V_153 -> V_156 ;
struct V_8 * V_9 = V_44 -> V_9 ;
int V_297 = 0 ;
struct V_298 * V_299 ;
V_299 = (struct V_298 * ) V_296 ;
if ( ! V_299 ) {
F_4 ( L_44 , V_7 ) ;
return 0 ;
}
V_297 = V_299 -> V_297 ;
if ( V_297 != V_312 && V_297 != V_313 )
return 0 ;
V_9 -> V_302 = V_299 -> V_302 ;
V_9 -> V_303 = V_299 -> V_302 ;
V_9 -> V_304 = V_299 -> V_304 ;
V_9 -> V_305 = V_299 -> V_305 ;
V_9 -> V_306 = V_299 -> V_306 ;
V_9 -> V_297 = V_299 -> V_297 ;
switch ( V_297 ) {
case V_312 :
F_160 ( V_9 , V_299 ) ;
break;
case V_313 :
F_161 ( V_9 ) ;
break;
}
return 0 ;
}
static long F_162 ( struct V_153 * V_153 , unsigned int V_295 ,
unsigned long V_296 )
{
struct V_43 * V_44 = V_153 -> V_156 ;
struct V_8 * V_9 = V_44 -> V_9 ;
struct V_314 * V_299 ;
int V_297 ;
int V_77 = 720 ;
int V_315 = 0 ;
int V_166 = 0 ;
int V_4 = 0 ;
int V_316 = 0 ;
int V_142 = 0 ;
V_299 = (struct V_314 * ) V_296 ;
if ( ! V_299 ) {
F_4 ( L_45 , V_7 ) ;
return 0 ;
}
V_297 = V_299 -> V_297 ;
if ( V_297 != V_317 && V_297 != V_318
&& V_297 != V_319 && V_297 != V_320
&& V_297 != V_321 && V_297 != V_322
&& V_297 != V_323 ) {
return 0 ;
}
switch ( V_297 ) {
case V_317 :
if ( ! strcmp ( V_299 -> V_304 , L_46 ) )
V_9 -> V_29 = V_140 ;
else
V_9 -> V_29 = V_109 ;
F_127 ( V_9 ) ;
break;
case V_318 :
V_315 = V_299 -> V_324 ;
V_166 = V_299 -> V_305 ;
if ( ! ( V_315 <= 7 && V_315 >= 0 ) ) {
V_315 -= 4 ;
V_315 = V_315 % 8 ;
}
if ( V_315 >= 0 )
F_102 ( V_9 , V_315 ,
V_166 ) ;
break;
case V_319 :
V_315 = V_299 -> V_324 ;
V_316 = V_299 -> V_325 ;
V_142 = V_299 -> V_142 ;
if ( V_316 ) {
if ( V_9 -> V_29 & V_140
|| V_9 -> V_29 & V_141 ) {
V_77 = 352 ;
} else {
V_77 = V_142 ;
if ( V_142 != 320 && V_142 != 352 )
V_77 = 320 ;
}
}
if ( ! ( V_315 <= 7 && V_315 >= 0 ) ) {
V_315 -= 4 ;
V_315 = V_315 % 8 ;
}
if ( V_315 <= 7 && V_315 >= 0 ) {
V_9 -> V_48 [ V_315 ] . V_139 =
V_316 ;
V_9 -> V_48 [ V_315 ] . V_142 = V_77 ;
} else {
for ( V_4 = 0 ; V_4 < V_326 ; V_4 ++ ) {
V_9 -> V_48 [ V_4 ] . V_139 =
V_316 ;
V_9 -> V_48 [ V_4 ] . V_142 = V_77 ;
}
}
F_103 ( V_9 , V_77 , V_315 ) ;
break;
case V_320 :
V_299 -> V_327 = F_33 ( V_299 -> V_328 ) ;
break;
case V_321 :
F_31 ( V_299 -> V_328 , V_299 -> V_327 ) ;
break;
case V_322 :
F_163 ( & V_9 -> V_329 [ 0 ] ,
( V_330 ) V_299 -> V_328 ,
& V_299 -> V_327 ) ;
break;
case V_323 :
F_164 ( & V_9 -> V_329 [ 0 ] ,
( V_330 ) V_299 -> V_328 ,
V_299 -> V_327 ) ;
break;
}
return 0 ;
}
static long F_165 ( struct V_153 * V_153 ,
unsigned int V_295 , unsigned long V_296 )
{
int V_331 = 0 ;
struct V_43 * V_44 = V_153 -> V_156 ;
if ( V_44 -> V_49 == V_332 ) {
V_331 = F_153 ( V_153 , V_295 , V_296 ) ;
return V_331 ;
} else if ( V_44 -> V_49 == V_333 ) {
V_331 = F_156 ( V_153 , V_295 , V_296 ) ;
return V_331 ;
} else if ( V_44 -> V_49 == V_334 ) {
V_331 = F_159 ( V_153 , V_295 , V_296 ) ;
V_331 = F_162 ( V_153 , V_295 , V_296 ) ;
return V_331 ;
}
return F_166 ( V_153 , V_295 , V_296 ) ;
}
