static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3
* V_4 )
{
return F_2 ( V_2 , V_5 . V_6 ) ;
}
static void T_2 F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
static int T_3 F_5 ( void )
{
int V_7 ;
V_7 = F_6 ( & V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_8 . V_9 =
( char * ) V_5 . V_6 ;
return F_7 ( & V_8 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_8 ) ;
F_10 ( & V_5 ) ;
}
static int T_3 F_5 ( void )
{
return F_6 ( & V_5 ) ;
}
static void T_4 F_8 ( void )
{
F_10 ( & V_5 ) ;
}
static int
F_11 ( struct V_10 * V_2 , int V_11 , int V_12 ,
struct V_1 * * V_13 )
{
struct V_1 * V_1 = NULL ;
* V_13 = NULL ;
for ( V_1 = F_12 ( V_14 , V_15 , NULL ) ;
V_1 != NULL ;
V_1 = F_12 ( V_14 ,
V_15 , V_1 ) ) {
if ( V_11 || V_12 ) {
if ( V_11 != V_1 -> V_11 -> V_16
|| V_12 != F_13 ( V_1 -> V_17 ) )
continue;
}
if ( V_18 -> V_19 == V_20 ) {
int V_21 ;
for ( V_21 = 0 ; V_21 < F_14 ( V_22 ) ; V_21 ++ ) {
if ( V_22 [ V_21 ] . V_23 != V_24 )
continue;
if ( V_1 -> V_25 == V_22 [ V_21 ] . V_26 ) {
V_2 -> V_27 = & V_22 [ V_21 ] ;
break;
}
}
if ( V_21 == F_14 ( V_22 ) )
continue;
} else {
if ( V_1 -> V_25 != V_18 -> V_26 )
continue;
}
* V_13 = V_1 ;
return 0 ;
}
if ( V_11 || V_12 ) {
F_15 ( V_28
L_1 ,
V_2 -> V_29 , V_18 -> V_9 , V_11 , V_12 ) ;
} else {
F_15 ( V_28 L_2 ,
V_2 -> V_29 , V_18 -> V_9 ) ;
}
return - V_30 ;
}
static int
F_16 ( unsigned V_29 , unsigned long V_31 , unsigned long V_32 )
{
if ( ! V_31 || ! F_17 ( V_31 , V_32 , V_33 ) ) {
F_15 ( V_28 L_3 ,
V_29 , V_31 , V_32 ) ;
return - V_30 ;
}
return 0 ;
}
static int
F_18 ( struct V_10 * V_2 ,
struct V_34 * V_35 ,
struct V_36 * V_37 , unsigned int * V_38 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
if ( V_40 -> V_42 ) {
V_38 [ 1 ] = F_19 ( V_40 -> V_43 ) & V_40 -> V_44 ;
} else {
V_38 [ 0 ] = 0 ;
}
return 2 ;
}
static void F_20 ( struct V_10 * V_2 ,
struct V_34 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
V_40 -> V_45 = 0 ;
V_40 -> V_46 = 0 ;
if ( V_40 -> V_42 )
F_21 ( 0 , V_40 -> V_43 ) ;
}
static int F_22 ( struct V_10 * V_2 ,
struct V_34 * V_35 )
{
unsigned int V_47 ;
unsigned V_48 ;
struct V_39 * V_40 = V_35 -> V_41 ;
struct V_49 * V_50 = & V_35 -> V_51 -> V_50 ;
int V_7 = 0 ;
if ( ! V_40 -> V_52 && V_40 -> V_53 == 0 ) {
V_35 -> V_51 -> V_54 |= V_55 ;
V_40 -> V_45 = 0 ;
V_7 = 1 ;
} else {
V_48 = 0 ;
if ( V_50 -> V_56 ) {
for ( V_47 = 0 ; V_47 < V_50 -> V_57 ; V_47 ++ )
V_48 |= ( 1U << F_23 ( V_50 -> V_56 [ V_47 ] ) ) ;
}
V_48 &= V_40 -> V_44 ;
V_40 -> V_46 = V_48 ;
if ( V_40 -> V_42 )
F_21 ( V_48 , V_40 -> V_43 ) ;
}
return V_7 ;
}
static int
F_24 ( struct V_10 * V_2 , struct V_34 * V_35 ,
unsigned int V_58 )
{
struct V_39 * V_40 ;
unsigned long V_59 ;
int V_60 = 0 ;
if ( V_58 != 0 )
return - V_61 ;
V_40 = V_35 -> V_41 ;
F_25 ( & V_40 -> V_62 , V_59 ) ;
V_35 -> V_51 -> V_63 = NULL ;
if ( V_40 -> V_45 )
V_60 = F_22 ( V_2 , V_35 ) ;
F_26 ( & V_40 -> V_62 , V_59 ) ;
if ( V_60 )
F_27 ( V_2 , V_35 ) ;
return 1 ;
}
static int F_28 ( struct V_10 * V_2 ,
struct V_34 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
unsigned V_64 ;
unsigned V_65 ;
unsigned V_66 ;
unsigned int V_67 ;
unsigned long V_59 ;
V_64 = 0 ;
F_25 ( & V_40 -> V_62 , V_59 ) ;
V_67 = V_35 -> V_51 -> V_54 ;
if ( V_40 -> V_42 ) {
V_66 = V_40 -> V_46 ;
while ( ( V_65 = ( F_19 ( V_40 -> V_43 ) & V_40 -> V_44
& ~ V_64 ) ) != 0 ) {
V_64 |= V_65 ;
V_66 &= ~ V_64 ;
F_21 ( V_66 , V_40 -> V_43 ) ;
}
} else {
V_64 = V_40 -> V_46 ;
}
if ( V_64 ) {
V_66 = V_40 -> V_46 ;
if ( V_40 -> V_42 )
F_21 ( V_66 , V_40 -> V_43 ) ;
if ( V_40 -> V_45 ) {
if ( V_64 & V_40 -> V_46 ) {
short V_68 ;
unsigned int V_47 , V_69 , V_70 ;
V_68 = 0 ;
V_70 = V_35 -> V_51 -> V_50 . V_57 ;
for ( V_47 = 0 ; V_47 < V_70 ; V_47 ++ ) {
V_69 = F_23 ( V_35 -> V_51 -> V_50 . V_56 [ V_47 ] ) ;
if ( V_64 & ( 1U << V_69 ) )
V_68 |= ( 1U << V_47 ) ;
}
if ( F_29 ( V_35 -> V_51 , V_68 ) ) {
V_35 -> V_51 -> V_54 |= ( V_71 |
V_72 ) ;
} else {
F_20 ( V_2 , V_35 ) ;
V_35 -> V_51 -> V_54 |= V_73
| V_74 ;
F_30 ( V_2 , L_4 ) ;
}
if ( ! V_40 -> V_52 ) {
if ( V_40 -> V_53 > 0 ) {
V_40 -> V_53 -- ;
if ( V_40 -> V_53 == 0 ) {
V_35 -> V_51 -> V_54 |=
V_55 ;
F_20 ( V_2 ,
V_35 ) ;
}
}
}
}
}
}
F_26 ( & V_40 -> V_62 , V_59 ) ;
if ( V_67 != V_35 -> V_51 -> V_54 )
F_27 ( V_2 , V_35 ) ;
return ( V_64 != 0 ) ;
}
static int F_31 ( struct V_10 * V_2 ,
struct V_34 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
unsigned long V_59 ;
F_25 ( & V_40 -> V_62 , V_59 ) ;
if ( V_40 -> V_45 )
F_20 ( V_2 , V_35 ) ;
F_26 ( & V_40 -> V_62 , V_59 ) ;
return 0 ;
}
static int
F_32 ( struct V_10 * V_2 ,
struct V_34 * V_35 , struct V_49 * V_50 )
{
int V_75 = 0 ;
unsigned int V_76 ;
V_76 = V_50 -> V_77 ;
V_50 -> V_77 &= ( V_78 | V_79 ) ;
if ( ! V_50 -> V_77 || V_76 != V_50 -> V_77 )
V_75 ++ ;
V_76 = V_50 -> V_80 ;
V_50 -> V_80 &= V_81 ;
if ( ! V_50 -> V_80 || V_76 != V_50 -> V_80 )
V_75 ++ ;
V_76 = V_50 -> V_82 ;
V_50 -> V_82 &= V_78 ;
if ( ! V_50 -> V_82 || V_76 != V_50 -> V_82 )
V_75 ++ ;
V_76 = V_50 -> V_83 ;
V_50 -> V_83 &= V_84 ;
if ( ! V_50 -> V_83 || V_76 != V_50 -> V_83 )
V_75 ++ ;
V_76 = V_50 -> V_85 ;
V_50 -> V_85 &= ( V_84 | V_86 ) ;
if ( ! V_50 -> V_85 || V_76 != V_50 -> V_85 )
V_75 ++ ;
if ( V_75 )
return 1 ;
if ( ( V_50 -> V_77 & ( V_50 -> V_77 - 1 ) ) != 0 )
V_75 ++ ;
if ( ( V_50 -> V_80 & ( V_50 -> V_80 - 1 ) ) != 0 )
V_75 ++ ;
if ( ( V_50 -> V_82 & ( V_50 -> V_82 - 1 ) ) != 0 )
V_75 ++ ;
if ( ( V_50 -> V_83 & ( V_50 -> V_83 - 1 ) ) != 0 )
V_75 ++ ;
if ( ( V_50 -> V_85 & ( V_50 -> V_85 - 1 ) ) != 0 )
V_75 ++ ;
if ( V_75 )
return 2 ;
if ( V_50 -> V_87 != 0 ) {
V_50 -> V_87 = 0 ;
V_75 ++ ;
}
if ( V_50 -> V_88 != 0 ) {
V_50 -> V_88 = 0 ;
V_75 ++ ;
}
if ( V_50 -> V_89 != 0 ) {
V_50 -> V_89 = 0 ;
V_75 ++ ;
}
if ( V_50 -> V_90 != V_50 -> V_57 ) {
V_50 -> V_90 = V_50 -> V_57 ;
V_75 ++ ;
}
switch ( V_50 -> V_85 ) {
case V_84 :
break;
case V_86 :
if ( V_50 -> V_91 != 0 ) {
V_50 -> V_91 = 0 ;
V_75 ++ ;
}
break;
default:
break;
}
if ( V_75 )
return 3 ;
return 0 ;
}
static int F_33 ( struct V_10 * V_2 ,
struct V_34 * V_35 )
{
struct V_49 * V_50 = & V_35 -> V_51 -> V_50 ;
struct V_39 * V_40 = V_35 -> V_41 ;
unsigned long V_59 ;
int V_60 = 0 ;
F_25 ( & V_40 -> V_62 , V_59 ) ;
V_40 -> V_45 = 1 ;
switch ( V_50 -> V_85 ) {
case V_84 :
V_40 -> V_52 = 0 ;
V_40 -> V_53 = V_50 -> V_91 ;
break;
default:
V_40 -> V_52 = 1 ;
V_40 -> V_53 = 0 ;
break;
}
switch ( V_50 -> V_77 ) {
case V_79 :
V_35 -> V_51 -> V_63 = F_24 ;
break;
default:
V_60 = F_22 ( V_2 , V_35 ) ;
break;
}
F_26 ( & V_40 -> V_62 , V_59 ) ;
if ( V_60 )
F_27 ( V_2 , V_35 ) ;
return 0 ;
}
static int
F_34 ( struct V_10 * V_2 , struct V_34 * V_35 ,
unsigned long V_43 , unsigned V_44 ,
int V_42 )
{
struct V_39 * V_40 ;
V_40 = F_35 ( sizeof( * V_40 ) , V_92 ) ;
if ( ! V_40 ) {
F_15 ( V_28 L_5 ,
V_2 -> V_29 ) ;
return - V_93 ;
}
V_40 -> V_43 = V_43 ;
V_40 -> V_42 = V_42 ;
V_40 -> V_44 = V_44 ;
F_36 ( & V_40 -> V_62 ) ;
if ( V_42 )
F_21 ( 0 , V_40 -> V_43 ) ;
V_35 -> V_41 = V_40 ;
V_35 -> type = V_94 ;
V_35 -> V_95 = V_96 | V_97 ;
if ( V_42 ) {
V_35 -> V_98 = V_99 ;
V_35 -> V_100 = V_99 ;
} else {
V_35 -> V_98 = 1 ;
V_35 -> V_100 = 1 ;
}
V_35 -> V_101 = & V_102 ;
V_35 -> V_103 = 1 ;
V_35 -> V_104 = F_18 ;
V_35 -> V_105 = F_32 ;
V_35 -> V_106 = F_33 ;
V_35 -> V_107 = F_31 ;
return 0 ;
}
static void
F_37 ( struct V_10 * V_2 ,
struct V_34 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
F_38 ( V_40 ) ;
}
static T_5 F_39 ( int V_108 , void * V_109 )
{
struct V_10 * V_2 = V_109 ;
int V_110 ;
if ( ! V_2 -> V_111 )
return V_112 ;
if ( V_113 -> V_114 >= 0 ) {
V_110 = F_28 ( V_2 ,
V_2 -> V_115 +
V_113 -> V_114 ) ;
} else {
V_110 = 0 ;
}
return F_40 ( V_110 ) ;
}
static int
F_41 ( struct V_10 * V_2 , struct V_34 * V_35 ,
struct V_36 * V_37 , unsigned int * V_38 )
{
struct V_116 * V_40 = V_35 -> V_41 ;
int V_117 = F_23 ( V_37 -> V_118 ) ;
unsigned long V_59 ;
F_25 ( & V_40 -> V_62 , V_59 ) ;
V_38 [ 0 ] = F_42 ( V_40 -> V_43 , 0 , V_117 ) ;
F_26 ( & V_40 -> V_62 , V_59 ) ;
return 1 ;
}
static int
F_43 ( struct V_10 * V_2 , struct V_34 * V_35 ,
struct V_36 * V_37 , unsigned int * V_38 )
{
struct V_116 * V_40 = V_35 -> V_41 ;
int V_117 = F_23 ( V_37 -> V_118 ) ;
unsigned long V_59 ;
F_25 ( & V_40 -> V_62 , V_59 ) ;
F_44 ( V_40 -> V_43 , 0 , V_117 , V_38 [ 0 ] ) ;
F_26 ( & V_40 -> V_62 , V_59 ) ;
return 1 ;
}
static int
F_45 ( struct V_116 * V_40 ,
unsigned int V_119 , unsigned int V_120 )
{
unsigned char V_121 ;
if ( ! V_40 -> V_122 )
return - 1 ;
if ( V_119 > 2 )
return - 1 ;
if ( V_120 > 7 )
return - 1 ;
V_40 -> V_120 [ V_119 ] = V_120 ;
V_121 = F_46 ( V_40 -> V_123 , V_119 , V_120 ) ;
F_21 ( V_121 , V_40 -> V_124 ) ;
return 0 ;
}
static int
F_47 ( struct V_116 * V_40 ,
unsigned int V_119 )
{
if ( ! V_40 -> V_122 )
return - 1 ;
if ( V_119 > 2 )
return - 1 ;
return V_40 -> V_120 [ V_119 ] ;
}
static int
F_48 ( struct V_116 * V_40 ,
unsigned int V_119 , unsigned int V_125 )
{
unsigned char V_121 ;
if ( ! V_40 -> V_122 )
return - 1 ;
if ( V_119 > 2 )
return - 1 ;
if ( V_125 > 7 )
return - 1 ;
V_40 -> V_125 [ V_119 ] = V_125 ;
V_121 = F_49 ( V_40 -> V_123 , V_119 , V_125 ) ;
F_21 ( V_121 , V_40 -> V_126 ) ;
return 0 ;
}
static int
F_50 ( struct V_116 * V_40 ,
unsigned int V_119 , unsigned int * V_127 )
{
unsigned V_125 ;
if ( ! V_40 -> V_122 )
return - 1 ;
if ( V_119 > 2 )
return - 1 ;
V_125 = V_40 -> V_125 [ V_119 ] ;
* V_127 = V_128 [ V_125 ] ;
return V_125 ;
}
static int
F_51 ( struct V_10 * V_2 , struct V_34 * V_35 ,
struct V_36 * V_37 , unsigned int * V_38 )
{
struct V_116 * V_40 = V_35 -> V_41 ;
int V_129 = 0 ;
int V_117 = F_23 ( V_37 -> V_118 ) ;
unsigned long V_59 ;
F_25 ( & V_40 -> V_62 , V_59 ) ;
switch ( V_38 [ 0 ] ) {
case V_130 :
V_129 = F_52 ( V_40 -> V_43 , 0 , V_117 , V_38 [ 1 ] ) ;
if ( V_129 < 0 )
V_129 = - V_61 ;
break;
case V_131 :
V_38 [ 1 ] = F_53 ( V_40 -> V_43 , 0 , V_117 ) ;
break;
case V_132 :
V_129 = F_45 ( V_40 , V_117 , V_38 [ 2 ] ) ;
if ( V_129 < 0 )
V_129 = - V_61 ;
break;
case V_133 :
V_129 = F_47 ( V_40 , V_117 ) ;
if ( V_129 < 0 ) {
V_129 = - V_61 ;
break;
}
V_38 [ 2 ] = V_129 ;
break;
case V_134 :
V_129 = F_48 ( V_40 , V_117 , V_38 [ 1 ] ) ;
if ( V_129 < 0 )
V_129 = - V_61 ;
break;
case V_135 :
V_129 = F_50 ( V_40 , V_117 , & V_38 [ 2 ] ) ;
if ( V_129 < 0 ) {
V_129 = - V_61 ;
break;
}
V_38 [ 1 ] = V_129 ;
break;
default:
V_129 = - V_61 ;
break;
}
F_26 ( & V_40 -> V_62 , V_59 ) ;
return V_129 < 0 ? V_129 : V_37 -> V_47 ;
}
static int
F_54 ( struct V_10 * V_2 , struct V_34 * V_35 ,
unsigned long V_43 , unsigned V_136 ,
int V_122 )
{
struct V_116 * V_40 ;
unsigned int V_117 ;
V_40 = F_35 ( sizeof( * V_40 ) , V_92 ) ;
if ( ! V_40 ) {
F_15 ( V_28 L_5 ,
V_2 -> V_29 ) ;
return - V_93 ;
}
V_35 -> V_41 = V_40 ;
V_35 -> type = V_137 ;
V_35 -> V_95 = V_138 | V_96 ;
V_35 -> V_98 = 3 ;
V_35 -> V_103 = 0xFFFF ;
V_35 -> V_139 = F_41 ;
V_35 -> V_140 = F_43 ;
V_35 -> V_141 = F_51 ;
F_36 ( & V_40 -> V_62 ) ;
V_40 -> V_43 = V_136 + V_43 ;
V_40 -> V_122 = V_122 ;
if ( V_122 ) {
V_40 -> V_126 =
V_142 + ( V_136 >> 3 ) + V_43 ;
V_40 -> V_124 =
V_143 + ( V_136 >> 3 ) + V_43 ;
V_40 -> V_123 = ( V_136 >> 2 ) & 1 ;
}
for ( V_117 = 0 ; V_117 < 3 ; V_117 ++ ) {
F_52 ( V_40 -> V_43 , 0 , V_117 ,
V_144 | V_145 ) ;
if ( V_40 -> V_122 ) {
F_45 ( V_40 , V_117 , 0 ) ;
F_48 ( V_40 , V_117 , 0 ) ;
}
}
return 0 ;
}
static void
F_55 ( struct V_10 * V_2 ,
struct V_34 * V_35 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
F_38 ( V_40 ) ;
}
static int F_56 ( struct V_10 * V_2 , struct V_146 * V_147 )
{
struct V_34 * V_35 ;
unsigned long V_43 = 0 ;
unsigned int V_108 = 0 ;
#ifdef F_57
struct V_1 * V_1 = NULL ;
int V_11 = 0 , V_12 = 0 ;
#endif
const struct V_148 * V_149 ;
int V_150 = 0 ;
int V_151 ;
unsigned V_47 ;
int V_129 ;
F_15 ( V_152 L_6 , V_2 -> V_29 ,
V_33 ) ;
V_129 = F_58 ( V_2 , sizeof( struct V_153 ) ) ;
if ( V_129 < 0 ) {
F_15 ( V_28 L_5 ,
V_2 -> V_29 ) ;
return V_129 ;
}
switch ( V_18 -> V_23 ) {
case V_154 :
V_43 = V_147 -> V_155 [ 0 ] ;
V_108 = V_147 -> V_155 [ 1 ] ;
V_150 = 0 ;
break;
#ifdef F_57
case V_24 :
V_11 = V_147 -> V_155 [ 0 ] ;
V_12 = V_147 -> V_155 [ 1 ] ;
V_150 = 1 ;
V_129 = F_11 ( V_2 , V_11 , V_12 , & V_1 ) ;
if ( V_129 < 0 )
return V_129 ;
V_113 -> V_1 = V_1 ;
break;
#endif
default:
F_15 ( V_28
L_7 ,
V_2 -> V_29 , V_33 ) ;
return - V_61 ;
break;
}
V_113 -> V_114 = - 1 ;
#ifdef F_57
if ( V_1 ) {
V_129 = F_59 ( V_1 , V_33 ) ;
if ( V_129 < 0 ) {
F_15 ( V_28
L_8 ,
V_2 -> V_29 ) ;
return V_129 ;
}
V_43 = F_60 ( V_1 , 2 ) ;
V_108 = V_1 -> V_108 ;
} else
#endif
{
V_129 = F_16 ( V_2 -> V_29 , V_43 , V_156 ) ;
if ( V_129 < 0 )
return V_129 ;
}
V_2 -> V_43 = V_43 ;
V_149 = V_157 ;
V_129 = F_61 ( V_2 , V_149 -> V_158 ) ;
if ( V_129 < 0 ) {
F_15 ( V_28 L_5 ,
V_2 -> V_29 ) ;
return V_129 ;
}
for ( V_47 = 0 ; V_47 < V_2 -> V_159 ; V_47 ++ ) {
V_35 = & V_2 -> V_115 [ V_47 ] ;
switch ( V_149 -> V_160 [ V_47 ] ) {
case V_161 :
V_129 = F_54 ( V_2 , V_35 , V_43 ,
V_149 -> V_162 [ V_47 ] ,
V_149 -> V_122 ) ;
if ( V_129 < 0 )
return V_129 ;
break;
case V_163 :
V_129 = F_62 ( V_2 , V_35 , NULL ,
V_43 + V_149 -> V_162 [ V_47 ] ) ;
if ( V_129 < 0 )
return V_129 ;
break;
case V_164 :
if ( V_108 ) {
V_129 = F_34 ( V_2 , V_35 ,
V_43 +
V_165 ,
V_149 -> V_162 [ V_47 ] ,
V_149 ->
V_42 ) ;
if ( V_129 < 0 )
return V_129 ;
V_113 -> V_114 = V_47 ;
} else {
V_35 -> type = V_166 ;
}
break;
default:
V_35 -> type = V_166 ;
break;
}
}
V_151 = V_113 -> V_114 ;
if ( V_151 >= 0 && V_151 < V_2 -> V_159 )
V_2 -> V_167 = & V_2 -> V_115 [ V_151 ] ;
V_2 -> V_168 = V_18 -> V_9 ;
if ( V_108 ) {
unsigned long V_59 = V_150 ? V_169 : 0 ;
if ( F_63 ( V_108 , F_39 , V_59 ,
V_33 , V_2 ) >= 0 ) {
V_2 -> V_108 = V_108 ;
} else {
F_15 ( V_170
L_9 ,
V_2 -> V_29 , V_108 ) ;
}
}
F_15 ( V_171 L_10 , V_2 -> V_29 , V_2 -> V_168 ) ;
if ( V_18 -> V_23 == V_154 ) {
F_15 ( L_11 , V_43 ) ;
} else {
#ifdef F_57
F_15 ( L_12 , F_64 ( V_1 ) ) ;
#endif
}
if ( V_108 )
F_15 ( L_13 , V_108 , ( V_2 -> V_108 ? L_14 : L_15 ) ) ;
else
F_15 ( L_16 ) ;
F_15 ( L_17 ) ;
return 1 ;
}
static int F_65 ( struct V_10 * V_2 )
{
const struct V_148 * V_149 ;
unsigned V_47 ;
F_15 ( V_152 L_18 , V_2 -> V_29 ,
V_33 ) ;
if ( V_2 -> V_108 )
F_66 ( V_2 -> V_108 , V_2 ) ;
if ( V_2 -> V_115 ) {
V_149 = V_157 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_159 ; V_47 ++ ) {
struct V_34 * V_35 = & V_2 -> V_115 [ V_47 ] ;
switch ( V_149 -> V_160 [ V_47 ] ) {
case V_161 :
F_55 ( V_2 , V_35 ) ;
break;
case V_163 :
F_67 ( V_2 , V_35 ) ;
break;
case V_164 :
F_37 ( V_2 , V_35 ) ;
break;
default:
break;
}
}
}
if ( V_113 ) {
#ifdef F_57
if ( V_113 -> V_1 ) {
if ( V_2 -> V_43 )
F_68 ( V_113 -> V_1 ) ;
F_69 ( V_113 -> V_1 ) ;
} else
#endif
{
if ( V_2 -> V_43 )
F_70 ( V_2 -> V_43 , V_156 ) ;
}
}
if ( V_2 -> V_168 )
F_15 ( V_171 L_19 ,
V_2 -> V_29 , V_2 -> V_168 ) ;
return 0 ;
}
