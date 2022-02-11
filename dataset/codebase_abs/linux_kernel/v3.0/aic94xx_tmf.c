static int F_1 ( struct V_1 * V_2 ,
void (* F_2)( struct V_1 * ,
struct V_3 * ) ,
void (* F_3)( unsigned long ) )
{
int V_4 ;
V_2 -> F_2 = F_2 ;
V_2 -> V_5 = 1 ;
V_2 -> V_6 . V_7 = ( unsigned long ) V_2 ;
V_2 -> V_6 . V_8 = F_3 ;
V_2 -> V_6 . V_9 = V_10 + V_11 ;
F_4 ( & V_2 -> V_6 ) ;
V_4 = F_5 ( V_2 -> V_12 , V_2 , 1 ) ;
if ( F_6 ( V_4 ) )
F_7 ( & V_2 -> V_6 ) ;
return V_4 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
F_9 ( L_1 , V_17 ) ;
if ( ! F_7 ( & V_2 -> V_6 ) ) {
F_9 ( L_2 , V_17 ) ;
return;
}
F_9 ( L_3 , V_17 , V_13 -> V_18 ) ;
V_15 -> V_19 = V_13 -> V_18 ;
F_10 ( V_2 -> V_20 ) ;
F_11 ( V_2 ) ;
}
static void F_12 ( unsigned long V_7 )
{
struct V_1 * V_2 = ( void * ) V_7 ;
struct V_14 * V_15 = V_2 -> V_16 ;
F_9 ( L_1 , V_17 ) ;
V_15 -> V_19 = V_21 ;
F_10 ( V_2 -> V_20 ) ;
}
int F_13 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_26 ;
V_27 ;
V_28 -> V_29 . V_30 = V_31 ;
V_32 ;
}
int F_14 ( struct V_33 * V_34 )
{
struct V_24 * V_25 = V_34 -> V_12 -> V_26 ;
V_27 ;
V_28 -> V_29 . V_30 = V_35 ;
V_28 -> V_29 . V_36 = V_34 -> V_37 ;
V_32 ;
}
static int F_15 ( struct V_38 * V_39 ,
enum V_40 V_41 )
{
struct V_24 * V_25 = V_39 -> V_34 -> V_12 -> V_26 ;
V_27 ;
V_28 -> V_29 . V_30 = V_42 ;
switch ( V_41 ) {
case V_43 :
V_28 -> V_29 . V_44 = V_45 | V_46 ;
break;
case V_47 :
V_28 -> V_29 . V_44 = V_48 | V_49 ;
break;
case V_50 :
V_28 -> V_29 . V_44 = V_51 ;
}
V_28 -> V_29 . V_52 = F_16 ( ( V_53 ) ( unsigned long )
V_39 -> V_54 ) ;
V_32 ;
}
int F_17 ( struct V_38 * V_39 )
{
int V_4 , V_55 , V_56 ;
struct V_57 * V_58 = F_18 ( V_39 ) ;
int V_59 = ( V_39 -> V_60 == V_61 ||
( V_39 -> V_62 & V_63 ) ) ? 0 : 1 ;
F_15 ( V_39 , V_43 ) ;
F_9 ( L_4 ,
V_59 ? L_5 : L_6 , F_19 ( & V_58 -> V_39 ) ) ;
V_4 = F_20 ( V_58 , V_59 ) ;
if ( V_4 == V_64 ) {
F_21 ( 500 ) ;
F_15 ( V_39 , V_47 ) ;
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_55 = F_15 ( V_39 , V_50 ) ;
if ( V_55 == V_65 )
return V_4 ;
F_21 ( 500 ) ;
}
F_22 ( V_66 , & V_58 -> V_39 ,
L_7 , V_55 ) ;
return V_21 ;
}
static int F_23 ( struct V_38 * V_39 , T_1 * V_67 )
{
struct V_24 * V_25 = V_39 -> V_34 -> V_12 -> V_26 ;
V_27 ;
V_28 -> V_29 . V_30 = V_68 ;
V_28 -> V_29 . V_44 = V_48 | V_45 | V_49 ;
memcpy ( V_28 -> V_29 . V_69 . V_67 , V_67 , 8 ) ;
V_28 -> V_29 . V_52 = F_16 ( ( V_53 ) ( unsigned long )
V_39 -> V_54 ) ;
V_32 ;
}
static int F_24 ( struct V_70 * V_71 )
{
struct V_24 * V_25 = V_71 -> V_39 -> V_34 -> V_12 -> V_26 ;
struct V_1 * V_72 = V_71 -> V_73 ;
V_27 ;
V_28 -> V_29 . V_30 = V_74 ;
memcpy ( V_28 -> V_29 . V_69 . V_67 , V_71 -> V_69 . V_75 , 8 ) ;
V_28 -> V_29 . V_69 . V_76 = V_72 -> V_76 ;
if ( V_71 -> V_39 -> V_62 )
V_28 -> V_29 . V_52 = F_16 ( ( V_53 ) ( unsigned long )
V_71 -> V_39 -> V_54 ) ;
V_32 ;
}
static int F_25 ( struct V_70 * V_71 )
{
struct V_24 * V_25 = V_71 -> V_39 -> V_34 -> V_12 -> V_26 ;
struct V_1 * V_72 = V_71 -> V_73 ;
V_27 ;
V_28 -> V_29 . V_30 = V_77 ;
if ( V_71 -> V_39 -> V_62 )
V_28 -> V_29 . V_52 = F_16 ( ( V_53 ) ( unsigned long )
V_71 -> V_39 -> V_54 ) ;
V_28 -> V_29 . V_78 = F_16 ( V_72 -> V_79 ) ;
V_32 ;
}
static void F_26 ( unsigned long V_7 )
{
struct V_1 * V_2 = ( void * ) V_7 ;
struct V_14 * V_15 = V_2 -> V_16 ;
F_9 ( L_8 ) ;
V_15 -> V_80 = V_21 ;
F_10 ( V_2 -> V_20 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_13 )
{
struct V_24 * V_25 = V_2 -> V_12 ;
unsigned long V_44 ;
struct V_81 {
T_2 V_82 ;
T_1 V_83 ;
T_1 V_44 ;
} V_84 ( ( V_85 ) ) * V_86 = ( void * ) V_13 -> V_87 ;
int V_88 = ( ( V_86 -> V_44 & 0x70 ) >> 4 ) - 1 ;
struct V_1 * V_89 ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_94 * V_95 ;
int V_4 = V_21 ;
F_9 ( L_9 ) ;
F_28 ( & V_25 -> V_96 . V_97 , V_44 ) ;
V_89 = F_29 ( & V_25 -> V_96 ,
( int ) F_30 ( V_86 -> V_82 ) ) ;
F_31 ( & V_25 -> V_96 . V_97 , V_44 ) ;
if ( ! V_89 ) {
F_9 ( L_10 ) ;
return V_4 ;
}
V_91 = V_25 -> V_96 . V_98 [ V_88 + V_89 -> V_99 ] ;
V_2 -> V_76 = * ( V_100 * ) ( V_91 -> V_101 + 4 ) ;
V_93 = V_91 -> V_101 + 16 ;
V_95 = V_91 -> V_101 + 16 + sizeof( * V_93 ) ;
V_4 = V_95 -> V_102 ;
if ( V_95 -> V_103 == 1 )
V_4 = V_95 -> V_104 [ 3 ] ;
#if 0
ascb->tag = fh->tag;
#endif
V_2 -> V_105 = 1 ;
F_32 ( V_89 , V_88 ) ;
return V_4 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_3 * V_13 )
{
struct V_14 * V_15 ;
if ( ! F_7 ( & V_2 -> V_6 ) )
return;
V_15 = V_2 -> V_16 ;
F_9 ( L_11 ) ;
V_15 -> V_19 = V_13 -> V_18 ;
if ( V_13 -> V_18 == V_106 ) {
V_15 -> V_80 = F_27 ( V_2 , V_13 ) ;
V_15 -> V_105 = V_2 -> V_105 ;
V_15 -> V_76 = V_2 -> V_76 ;
}
F_10 ( V_2 -> V_20 ) ;
F_11 ( V_2 ) ;
}
static int F_34 ( struct V_70 * V_71 )
{
int V_4 = V_21 ;
int V_107 ;
struct V_1 * V_72 = V_71 -> V_73 ;
F_35 ( V_20 ) ;
unsigned long V_44 ;
V_72 -> V_20 = & V_20 ;
F_9 ( L_12 ) ;
if ( V_72 -> V_105 )
V_4 = F_24 ( V_71 ) ;
else
V_4 = F_25 ( V_71 ) ;
V_107 = F_36 ( & V_20 ,
V_11 ) ;
V_72 -> V_20 = NULL ;
F_9 ( L_13 ) ;
F_28 ( & V_71 -> V_108 , V_44 ) ;
if ( V_107 < 1 )
V_4 = V_21 ;
if ( V_71 -> V_109 & V_110 )
V_4 = V_64 ;
F_31 ( & V_71 -> V_108 , V_44 ) ;
return V_4 ;
}
int F_37 ( struct V_70 * V_71 )
{
struct V_1 * V_72 = V_71 -> V_73 ;
struct V_24 * V_25 = V_72 -> V_12 ;
int V_4 = 1 ;
unsigned long V_44 ;
struct V_1 * V_2 = NULL ;
struct V_28 * V_28 ;
int V_107 ;
F_38 ( V_15 ) ;
F_35 ( V_20 ) ;
F_35 ( V_111 ) ;
V_72 -> V_20 = & V_111 ;
F_28 ( & V_71 -> V_108 , V_44 ) ;
if ( V_71 -> V_109 & V_110 ) {
F_31 ( & V_71 -> V_108 , V_44 ) ;
V_4 = V_64 ;
F_9 ( L_14 , V_17 , V_71 ) ;
goto V_112;
}
F_31 ( & V_71 -> V_108 , V_44 ) ;
V_2 = F_39 ( V_25 , & V_4 , V_113 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_16 = & V_15 ;
V_2 -> V_20 = & V_20 ;
V_28 = V_2 -> V_28 ;
V_28 -> V_115 . V_18 = V_116 ;
switch ( V_71 -> V_117 ) {
case V_118 :
case V_63 :
V_28 -> V_119 . V_120 = ( 1 << 5 ) ;
break;
case V_121 :
V_28 -> V_119 . V_120 = ( 1 << 4 ) ;
V_28 -> V_119 . V_120 |= V_71 -> V_39 -> V_122 ;
break;
case V_123 :
break;
default:
break;
}
if ( V_71 -> V_117 == V_121 ) {
V_28 -> V_119 . V_124 . V_125 = V_126 ;
memcpy ( V_28 -> V_119 . V_124 . V_127 ,
V_71 -> V_39 -> V_128 , V_129 ) ;
memcpy ( V_28 -> V_119 . V_124 . V_130 ,
V_71 -> V_39 -> V_34 -> V_12 -> V_128 ,
V_129 ) ;
V_28 -> V_119 . V_124 . V_131 = F_40 ( 0xFFFF ) ;
memcpy ( V_28 -> V_119 . V_69 . V_67 , V_71 -> V_69 . V_75 , 8 ) ;
V_28 -> V_119 . V_69 . V_132 = V_133 ;
V_28 -> V_119 . V_69 . V_76 = F_40 ( 0xFFFF ) ;
}
V_28 -> V_119 . V_134 = F_16 ( 0xFFFF ) ;
V_28 -> V_119 . V_52 = F_16 (
( V_53 ) ( unsigned long ) V_71 -> V_39 -> V_54 ) ;
V_28 -> V_119 . V_135 = 1 ;
V_28 -> V_119 . V_78 = F_16 ( ( V_53 ) V_72 -> V_79 ) ;
V_28 -> V_119 . V_136 = F_16 ( V_137 ) ;
V_4 = F_1 ( V_2 , F_33 ,
F_26 ) ;
if ( V_4 )
goto V_138;
F_41 ( & V_20 ) ;
F_9 ( L_15 ) ;
V_72 -> V_76 = V_15 . V_76 ;
V_72 -> V_105 = V_15 . V_105 ;
F_28 ( & V_71 -> V_108 , V_44 ) ;
if ( V_71 -> V_109 & V_110 ) {
F_31 ( & V_71 -> V_108 , V_44 ) ;
V_4 = V_64 ;
F_9 ( L_14 , V_17 , V_71 ) ;
goto V_112;
}
F_31 ( & V_71 -> V_108 , V_44 ) ;
if ( V_15 . V_19 == V_106 ) {
if ( V_15 . V_80 == V_64 )
V_4 = F_34 ( V_71 ) ;
else
V_4 = V_15 . V_80 ;
} else if ( V_15 . V_19 == V_139 &&
V_15 . V_80 == V_21 ) {
V_4 = V_21 ;
} else {
switch ( V_15 . V_19 ) {
default:
V_4 = F_34 ( V_71 ) ;
case V_139 :
break;
case V_140 :
V_4 = V_141 ;
break;
case V_142 :
V_4 = V_21 ;
V_107 =
F_36 ( & V_111 ,
V_11 ) ;
F_28 ( & V_71 -> V_108 , V_44 ) ;
if ( V_107 < 1 )
V_4 = V_21 ;
if ( V_71 -> V_109 & V_110 )
V_4 = V_64 ;
F_31 ( & V_71 -> V_108 , V_44 ) ;
break;
case V_143 :
case V_144 :
case V_145 :
V_4 = V_64 ;
break;
case V_146 :
V_4 = V_147 ;
break;
}
}
V_112:
V_72 -> V_20 = NULL ;
if ( V_4 == V_64 ) {
V_71 -> V_73 = NULL ;
F_42 () ;
F_11 ( V_72 ) ;
}
F_9 ( L_16 , V_71 , V_4 ) ;
return V_4 ;
V_138:
F_11 ( V_2 ) ;
F_9 ( L_16 , V_71 , V_4 ) ;
return V_4 ;
}
static int F_43 ( struct V_38 * V_39 , T_1 * V_67 ,
int V_132 , int V_78 )
{
struct V_24 * V_25 = V_39 -> V_34 -> V_12 -> V_26 ;
struct V_1 * V_2 ;
int V_4 = 1 ;
struct V_28 * V_28 ;
F_35 ( V_20 ) ;
F_38 ( V_15 ) ;
if ( ! ( V_39 -> V_62 & V_121 ) )
return V_147 ;
V_2 = F_39 ( V_25 , & V_4 , V_113 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_20 = & V_20 ;
V_2 -> V_16 = & V_15 ;
V_28 = V_2 -> V_28 ;
if ( V_132 == V_148 )
V_28 -> V_115 . V_18 = V_149 ;
else
V_28 -> V_115 . V_18 = V_150 ;
V_28 -> V_151 . V_120 = ( 1 << 4 ) ;
V_28 -> V_151 . V_120 |= V_39 -> V_122 ;
V_28 -> V_151 . V_124 . V_125 = V_126 ;
memcpy ( V_28 -> V_151 . V_124 . V_127 ,
V_39 -> V_128 , V_129 ) ;
memcpy ( V_28 -> V_151 . V_124 . V_130 ,
V_39 -> V_34 -> V_12 -> V_128 , V_129 ) ;
V_28 -> V_151 . V_124 . V_131 = F_40 ( 0xFFFF ) ;
memcpy ( V_28 -> V_151 . V_69 . V_67 , V_67 , 8 ) ;
V_28 -> V_151 . V_69 . V_132 = V_132 ;
V_28 -> V_151 . V_134 = F_16 ( 0xFFFF ) ;
V_28 -> V_151 . V_52 = F_16 ( ( V_53 ) ( unsigned long )
V_39 -> V_54 ) ;
V_28 -> V_151 . V_135 = 1 ;
V_28 -> V_151 . V_136 = F_16 ( V_137 ) ;
if ( V_132 == V_148 )
V_28 -> V_151 . V_78 = F_16 ( V_78 ) ;
V_4 = F_1 ( V_2 , F_33 ,
F_26 ) ;
if ( V_4 )
goto V_152;
F_41 ( & V_20 ) ;
switch ( V_15 . V_19 ) {
case V_139 :
V_4 = V_64 ;
break;
case V_140 :
V_4 = V_141 ;
break;
case V_142 :
V_4 = V_21 ;
break;
case V_143 :
case V_144 :
case V_145 :
V_4 = V_64 ;
break;
case V_146 :
V_4 = V_147 ;
break;
default:
V_4 = V_15 . V_19 ;
break;
}
return V_4 ;
V_152:
F_11 ( V_2 ) ;
return V_4 ;
}
int F_44 ( struct V_38 * V_39 , T_1 * V_67 )
{
int V_4 = F_43 ( V_39 , V_67 , V_153 , 0 ) ;
if ( V_4 == V_64 )
F_23 ( V_39 , V_67 ) ;
return V_4 ;
}
int F_45 ( struct V_38 * V_39 , T_1 * V_67 )
{
int V_4 = F_43 ( V_39 , V_67 , V_154 , 0 ) ;
if ( V_4 == V_64 )
F_23 ( V_39 , V_67 ) ;
return V_4 ;
}
int F_46 ( struct V_38 * V_39 , T_1 * V_67 )
{
int V_4 = F_43 ( V_39 , V_67 , V_155 , 0 ) ;
if ( V_4 == V_64 )
F_23 ( V_39 , V_67 ) ;
return V_4 ;
}
int F_47 ( struct V_38 * V_39 , T_1 * V_67 )
{
int V_4 = F_43 ( V_39 , V_67 , V_156 , 0 ) ;
if ( V_4 == V_64 )
F_23 ( V_39 , V_67 ) ;
return V_4 ;
}
int F_48 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_73 ;
int V_78 ;
if ( V_2 ) {
V_78 = V_2 -> V_79 ;
return F_43 ( V_71 -> V_39 , V_71 -> V_69 . V_75 ,
V_148 , V_78 ) ;
}
return V_64 ;
}
