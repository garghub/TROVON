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
if ( V_4 == V_64 || V_4 == - V_65 ) {
F_21 ( 500 ) ;
F_15 ( V_39 , V_47 ) ;
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_55 = F_15 ( V_39 , V_50 ) ;
if ( V_55 == V_66 )
goto V_67;
F_21 ( 500 ) ;
}
F_22 ( V_68 , & V_58 -> V_39 ,
L_7 , V_55 ) ;
V_4 = V_21 ;
V_67:
F_23 ( V_58 ) ;
return V_4 ;
}
static int F_24 ( struct V_38 * V_39 , T_1 * V_69 )
{
struct V_24 * V_25 = V_39 -> V_34 -> V_12 -> V_26 ;
V_27 ;
V_28 -> V_29 . V_30 = V_70 ;
V_28 -> V_29 . V_44 = V_48 | V_45 | V_49 ;
memcpy ( V_28 -> V_29 . V_71 . V_69 , V_69 , 8 ) ;
V_28 -> V_29 . V_52 = F_16 ( ( V_53 ) ( unsigned long )
V_39 -> V_54 ) ;
V_32 ;
}
static int F_25 ( struct V_72 * V_73 )
{
struct V_24 * V_25 = V_73 -> V_39 -> V_34 -> V_12 -> V_26 ;
struct V_1 * V_74 = V_73 -> V_75 ;
V_27 ;
V_28 -> V_29 . V_30 = V_76 ;
memcpy ( V_28 -> V_29 . V_71 . V_69 , V_73 -> V_71 . V_77 , 8 ) ;
V_28 -> V_29 . V_71 . V_78 = V_74 -> V_78 ;
if ( V_73 -> V_39 -> V_62 )
V_28 -> V_29 . V_52 = F_16 ( ( V_53 ) ( unsigned long )
V_73 -> V_39 -> V_54 ) ;
V_32 ;
}
static int F_26 ( struct V_72 * V_73 )
{
struct V_24 * V_25 = V_73 -> V_39 -> V_34 -> V_12 -> V_26 ;
struct V_1 * V_74 = V_73 -> V_75 ;
V_27 ;
V_28 -> V_29 . V_30 = V_79 ;
if ( V_73 -> V_39 -> V_62 )
V_28 -> V_29 . V_52 = F_16 ( ( V_53 ) ( unsigned long )
V_73 -> V_39 -> V_54 ) ;
V_28 -> V_29 . V_80 = F_16 ( V_74 -> V_81 ) ;
V_32 ;
}
static void F_27 ( unsigned long V_7 )
{
struct V_1 * V_2 = ( void * ) V_7 ;
struct V_14 * V_15 = V_2 -> V_16 ;
F_9 ( L_8 ) ;
V_15 -> V_82 = V_21 ;
F_10 ( V_2 -> V_20 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_13 )
{
struct V_24 * V_25 = V_2 -> V_12 ;
unsigned long V_44 ;
struct V_83 {
T_2 V_84 ;
T_1 V_85 ;
T_1 V_44 ;
} V_86 ( ( V_87 ) ) * V_88 = ( void * ) V_13 -> V_89 ;
int V_90 = ( ( V_88 -> V_44 & 0x70 ) >> 4 ) - 1 ;
struct V_1 * V_91 ;
struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
int V_4 = V_21 ;
F_9 ( L_9 ) ;
F_29 ( & V_25 -> V_98 . V_99 , V_44 ) ;
V_91 = F_30 ( & V_25 -> V_98 ,
( int ) F_31 ( V_88 -> V_84 ) ) ;
F_32 ( & V_25 -> V_98 . V_99 , V_44 ) ;
if ( ! V_91 ) {
F_9 ( L_10 ) ;
return V_4 ;
}
V_93 = V_25 -> V_98 . V_100 [ V_90 + V_91 -> V_101 ] ;
V_2 -> V_78 = * ( V_102 * ) ( V_93 -> V_103 + 4 ) ;
V_95 = V_93 -> V_103 + 16 ;
V_97 = V_93 -> V_103 + 16 + sizeof( * V_95 ) ;
V_4 = V_97 -> V_104 ;
if ( V_97 -> V_105 == 1 )
V_4 = V_97 -> V_106 [ 3 ] ;
#if 0
ascb->tag = fh->tag;
#endif
V_2 -> V_107 = 1 ;
F_33 ( V_91 , V_90 ) ;
return V_4 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_3 * V_13 )
{
struct V_14 * V_15 ;
if ( ! F_7 ( & V_2 -> V_6 ) )
return;
V_15 = V_2 -> V_16 ;
F_9 ( L_11 ) ;
V_15 -> V_19 = V_13 -> V_18 ;
if ( V_13 -> V_18 == V_108 ) {
V_15 -> V_82 = F_28 ( V_2 , V_13 ) ;
V_15 -> V_107 = V_2 -> V_107 ;
V_15 -> V_78 = V_2 -> V_78 ;
}
F_10 ( V_2 -> V_20 ) ;
F_11 ( V_2 ) ;
}
static int F_35 ( struct V_72 * V_73 )
{
int V_4 = V_21 ;
int V_109 ;
struct V_1 * V_74 = V_73 -> V_75 ;
F_36 ( V_20 ) ;
unsigned long V_44 ;
V_74 -> V_20 = & V_20 ;
F_9 ( L_12 ) ;
if ( V_74 -> V_107 )
V_4 = F_25 ( V_73 ) ;
else
V_4 = F_26 ( V_73 ) ;
V_109 = F_37 ( & V_20 ,
V_11 ) ;
V_74 -> V_20 = NULL ;
F_9 ( L_13 ) ;
F_29 ( & V_73 -> V_110 , V_44 ) ;
if ( V_109 < 1 )
V_4 = V_21 ;
if ( V_73 -> V_111 & V_112 )
V_4 = V_64 ;
F_32 ( & V_73 -> V_110 , V_44 ) ;
return V_4 ;
}
int F_38 ( struct V_72 * V_73 )
{
struct V_1 * V_74 = V_73 -> V_75 ;
struct V_24 * V_25 = V_74 -> V_12 ;
int V_4 = 1 ;
unsigned long V_44 ;
struct V_1 * V_2 = NULL ;
struct V_28 * V_28 ;
int V_109 ;
F_39 ( V_15 ) ;
F_36 ( V_20 ) ;
F_36 ( V_113 ) ;
V_74 -> V_20 = & V_113 ;
F_29 ( & V_73 -> V_110 , V_44 ) ;
if ( V_73 -> V_111 & V_112 ) {
F_32 ( & V_73 -> V_110 , V_44 ) ;
V_4 = V_64 ;
F_9 ( L_14 , V_17 , V_73 ) ;
goto V_114;
}
F_32 ( & V_73 -> V_110 , V_44 ) ;
V_2 = F_40 ( V_25 , & V_4 , V_115 ) ;
if ( ! V_2 )
return - V_116 ;
V_2 -> V_16 = & V_15 ;
V_2 -> V_20 = & V_20 ;
V_28 = V_2 -> V_28 ;
V_28 -> V_117 . V_18 = V_118 ;
switch ( V_73 -> V_119 ) {
case V_120 :
case V_63 :
V_28 -> V_121 . V_122 = ( 1 << 5 ) ;
break;
case V_123 :
V_28 -> V_121 . V_122 = ( 1 << 4 ) ;
V_28 -> V_121 . V_122 |= V_73 -> V_39 -> V_124 ;
break;
case V_125 :
break;
default:
break;
}
if ( V_73 -> V_119 == V_123 ) {
V_28 -> V_121 . V_126 . V_127 = V_128 ;
memcpy ( V_28 -> V_121 . V_126 . V_129 ,
V_73 -> V_39 -> V_130 , V_131 ) ;
memcpy ( V_28 -> V_121 . V_126 . V_132 ,
V_73 -> V_39 -> V_34 -> V_12 -> V_130 ,
V_131 ) ;
V_28 -> V_121 . V_126 . V_133 = F_41 ( 0xFFFF ) ;
memcpy ( V_28 -> V_121 . V_71 . V_69 , V_73 -> V_71 . V_77 , 8 ) ;
V_28 -> V_121 . V_71 . V_134 = V_135 ;
V_28 -> V_121 . V_71 . V_78 = F_41 ( 0xFFFF ) ;
}
V_28 -> V_121 . V_136 = F_16 ( 0xFFFF ) ;
V_28 -> V_121 . V_52 = F_16 (
( V_53 ) ( unsigned long ) V_73 -> V_39 -> V_54 ) ;
V_28 -> V_121 . V_137 = 1 ;
V_28 -> V_121 . V_80 = F_16 ( ( V_53 ) V_74 -> V_81 ) ;
V_28 -> V_121 . V_138 = F_16 ( V_139 ) ;
V_4 = F_1 ( V_2 , F_34 ,
F_27 ) ;
if ( V_4 )
goto V_140;
F_42 ( & V_20 ) ;
F_9 ( L_15 ) ;
V_74 -> V_78 = V_15 . V_78 ;
V_74 -> V_107 = V_15 . V_107 ;
F_29 ( & V_73 -> V_110 , V_44 ) ;
if ( V_73 -> V_111 & V_112 ) {
F_32 ( & V_73 -> V_110 , V_44 ) ;
V_4 = V_64 ;
F_9 ( L_14 , V_17 , V_73 ) ;
goto V_114;
}
F_32 ( & V_73 -> V_110 , V_44 ) ;
if ( V_15 . V_19 == V_108 ) {
if ( V_15 . V_82 == V_64 )
V_4 = F_35 ( V_73 ) ;
else
V_4 = V_15 . V_82 ;
} else if ( V_15 . V_19 == V_141 &&
V_15 . V_82 == V_21 ) {
V_4 = V_21 ;
} else {
switch ( V_15 . V_19 ) {
default:
V_4 = F_35 ( V_73 ) ;
case V_141 :
break;
case V_142 :
V_4 = V_143 ;
break;
case V_144 :
V_4 = V_21 ;
V_109 =
F_37 ( & V_113 ,
V_11 ) ;
F_29 ( & V_73 -> V_110 , V_44 ) ;
if ( V_109 < 1 )
V_4 = V_21 ;
if ( V_73 -> V_111 & V_112 )
V_4 = V_64 ;
F_32 ( & V_73 -> V_110 , V_44 ) ;
break;
case V_145 :
case V_146 :
case V_147 :
V_4 = V_64 ;
break;
case V_148 :
V_4 = V_149 ;
break;
}
}
V_114:
V_74 -> V_20 = NULL ;
if ( V_4 == V_64 ) {
V_73 -> V_75 = NULL ;
F_43 () ;
F_11 ( V_74 ) ;
}
F_9 ( L_16 , V_73 , V_4 ) ;
return V_4 ;
V_140:
F_11 ( V_2 ) ;
F_9 ( L_16 , V_73 , V_4 ) ;
return V_4 ;
}
static int F_44 ( struct V_38 * V_39 , T_1 * V_69 ,
int V_134 , int V_80 )
{
struct V_24 * V_25 = V_39 -> V_34 -> V_12 -> V_26 ;
struct V_1 * V_2 ;
int V_4 = 1 ;
struct V_28 * V_28 ;
F_36 ( V_20 ) ;
F_39 ( V_15 ) ;
if ( ! ( V_39 -> V_62 & V_123 ) )
return V_149 ;
V_2 = F_40 ( V_25 , & V_4 , V_115 ) ;
if ( ! V_2 )
return - V_116 ;
V_2 -> V_20 = & V_20 ;
V_2 -> V_16 = & V_15 ;
V_28 = V_2 -> V_28 ;
if ( V_134 == V_150 )
V_28 -> V_117 . V_18 = V_151 ;
else
V_28 -> V_117 . V_18 = V_152 ;
V_28 -> V_153 . V_122 = ( 1 << 4 ) ;
V_28 -> V_153 . V_122 |= V_39 -> V_124 ;
V_28 -> V_153 . V_126 . V_127 = V_128 ;
memcpy ( V_28 -> V_153 . V_126 . V_129 ,
V_39 -> V_130 , V_131 ) ;
memcpy ( V_28 -> V_153 . V_126 . V_132 ,
V_39 -> V_34 -> V_12 -> V_130 , V_131 ) ;
V_28 -> V_153 . V_126 . V_133 = F_41 ( 0xFFFF ) ;
memcpy ( V_28 -> V_153 . V_71 . V_69 , V_69 , 8 ) ;
V_28 -> V_153 . V_71 . V_134 = V_134 ;
V_28 -> V_153 . V_136 = F_16 ( 0xFFFF ) ;
V_28 -> V_153 . V_52 = F_16 ( ( V_53 ) ( unsigned long )
V_39 -> V_54 ) ;
V_28 -> V_153 . V_137 = 1 ;
V_28 -> V_153 . V_138 = F_16 ( V_139 ) ;
if ( V_134 == V_150 )
V_28 -> V_153 . V_80 = F_16 ( V_80 ) ;
V_4 = F_1 ( V_2 , F_34 ,
F_27 ) ;
if ( V_4 )
goto V_154;
F_42 ( & V_20 ) ;
switch ( V_15 . V_19 ) {
case V_141 :
V_4 = V_64 ;
break;
case V_142 :
V_4 = V_143 ;
break;
case V_144 :
V_4 = V_21 ;
break;
case V_145 :
case V_146 :
case V_147 :
V_4 = V_64 ;
break;
case V_148 :
V_4 = V_149 ;
break;
default:
V_4 = V_15 . V_19 ;
break;
}
return V_4 ;
V_154:
F_11 ( V_2 ) ;
return V_4 ;
}
int F_45 ( struct V_38 * V_39 , T_1 * V_69 )
{
int V_4 = F_44 ( V_39 , V_69 , V_155 , 0 ) ;
if ( V_4 == V_64 )
F_24 ( V_39 , V_69 ) ;
return V_4 ;
}
int F_46 ( struct V_38 * V_39 , T_1 * V_69 )
{
int V_4 = F_44 ( V_39 , V_69 , V_156 , 0 ) ;
if ( V_4 == V_64 )
F_24 ( V_39 , V_69 ) ;
return V_4 ;
}
int F_47 ( struct V_38 * V_39 , T_1 * V_69 )
{
int V_4 = F_44 ( V_39 , V_69 , V_157 , 0 ) ;
if ( V_4 == V_64 )
F_24 ( V_39 , V_69 ) ;
return V_4 ;
}
int F_48 ( struct V_38 * V_39 , T_1 * V_69 )
{
int V_4 = F_44 ( V_39 , V_69 , V_158 , 0 ) ;
if ( V_4 == V_64 )
F_24 ( V_39 , V_69 ) ;
return V_4 ;
}
int F_49 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_75 ;
int V_80 ;
if ( V_2 ) {
V_80 = V_2 -> V_81 ;
return F_44 ( V_73 -> V_39 , V_73 -> V_71 . V_77 ,
V_150 , V_80 ) ;
}
return V_64 ;
}
