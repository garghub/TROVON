static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = V_6 -> V_8 ;
unsigned char * V_9 = ( unsigned char * ) ( V_4 -> V_10 + V_7 ) ;
* V_9 ++ = F_2 ( V_2 , V_11 ) ;
if ( ++ V_7 >= V_6 -> V_12 ) {
V_7 = 0 ;
V_9 = ( unsigned char * ) V_4 -> V_10 ;
}
* V_9 ++ = F_2 ( V_2 , V_13 ) ;
if ( ++ V_7 >= V_6 -> V_12 ) {
V_7 = 0 ;
V_9 = ( unsigned char * ) V_4 -> V_10 ;
}
* V_9 ++ = F_2 ( V_2 , V_14 ) ;
if ( ++ V_7 >= V_6 -> V_12 ) {
V_7 = 0 ;
V_9 = ( unsigned char * ) V_4 -> V_10 ;
}
V_6 -> V_8 = V_7 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 * V_15 ,
unsigned int * V_16 )
{
V_16 [ 0 ] = ( unsigned int ) ( ( * V_15 ) >> 24 ) & V_17 ;
V_16 [ 1 ] = ( unsigned int ) ( * V_15 ) & V_18 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_19 * V_20 ,
struct V_5 * V_6 )
{
if ( ! ( V_6 -> V_21 & V_22 ) )
return 0 ;
V_20 -> V_23 [ 0 ] |= V_24 ;
F_3 ( V_2 , & V_6 -> V_25 , & V_20 -> V_23 [ 1 ] ) ;
if ( V_6 -> V_21 & V_26 )
V_20 -> V_23 [ 1 ] |= V_27 ;
if ( V_6 -> V_21 & V_28 )
V_20 -> V_23 [ 1 ] |= V_29 ;
if ( V_6 -> V_21 & V_30 )
V_20 -> V_23 [ 1 ] |= V_31 ;
V_20 -> V_32 += 2 ;
return 2 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_5 * V_6 ,
unsigned int V_33 )
{
struct V_19 V_20 ;
F_6 ( & V_20 , V_6 -> V_34 ?
V_35 : V_36 ) ;
V_20 . V_23 [ 0 ] |= V_6 -> V_37 << V_38 ;
F_4 ( V_2 , & V_20 , V_6 ) ;
V_20 . V_23 [ V_20 . V_32 ] = ( V_33 & 0xFFFFFF00 ) >> 8 ;
V_20 . V_23 [ V_20 . V_32 + 1 ] = ( V_33 & 0xFF ) << 16 ;
V_20 . V_32 += 2 ;
return F_7 ( V_2 , & V_20 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_3 * V_4 )
{
unsigned int V_39 = V_40 ;
if ( V_4 -> V_41 == 1 )
V_39 |= V_42 ;
if ( F_9 ( V_4 -> V_43 ) )
V_39 |= V_44 ;
if ( V_4 -> V_45 < 32000 && V_4 -> V_45 > 11025 )
V_39 |= V_46 ;
else if ( V_4 -> V_45 <= 11025 )
V_39 |= V_47 ;
switch ( F_10 ( V_4 -> V_43 ) ) {
case 16 : V_39 |= V_48 ; break;
case 24 : V_39 |= V_49 ; break;
default :
F_11 () ;
return - V_50 ;
} ;
return F_5 ( V_2 , V_6 , V_39 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
int V_53 ;
struct V_19 V_20 ;
F_6 ( & V_20 , V_54 ) ;
V_20 . V_23 [ 0 ] |= V_52 -> V_55 & 0x03ffff ;
V_53 = F_7 ( V_2 , & V_20 ) ;
if ( V_53 < 0 )
return V_53 ;
V_52 -> V_55 = V_20 . V_56 [ 0 ] ;
V_52 -> V_57 = V_20 . V_56 [ 1 ] ;
V_52 -> V_58 = V_20 . V_56 [ 2 ] ;
V_52 -> V_59 = V_20 . V_56 [ 3 ] ;
F_13 ( V_60 L_1 ,
V_52 -> V_55 , V_52 -> V_57 , V_52 -> V_58 , V_52 -> V_59 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_5 * V_6 , int * V_61 )
{
int V_53 ;
struct V_19 V_20 ;
F_6 ( & V_20 , V_62 ) ;
F_15 ( & V_20 , V_6 -> V_34 , V_6 -> V_37 , 0 ) ;
V_53 = F_16 ( V_2 , & V_20 ) ;
if ( ! V_53 )
* V_61 = ( V_20 . V_56 [ 0 ] & ( 1 << V_6 -> V_37 ) ) ? 1 : 0 ;
return V_53 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_63 ;
struct V_19 V_20 ;
F_6 ( & V_20 , V_64 ) ;
F_15 ( & V_20 , V_6 -> V_34 , V_6 -> V_37 , 0 ) ;
if ( V_6 -> V_34 )
V_20 . V_23 [ 0 ] |= 0x00000001 ;
V_63 = F_7 ( V_2 , & V_20 ) ;
if ( ! V_63 )
V_63 = V_20 . V_56 [ 0 ] & 0xffff ;
return V_63 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_53 ;
struct V_19 V_20 ;
F_6 ( & V_20 , V_65 ) ;
F_15 ( & V_20 , V_6 -> V_34 , V_6 -> V_37 , 0 ) ;
V_20 . V_23 [ 0 ] |= 1 ;
V_53 = F_16 ( V_2 , & V_20 ) ;
if ( ! V_53 ) {
if ( V_20 . V_56 [ 0 ] )
V_53 = 1 ;
}
return V_53 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_19 V_20 ;
F_6 ( & V_20 , V_66 ) ;
if ( V_6 -> V_34 )
V_20 . V_23 [ 0 ] |= V_67 ;
V_20 . V_23 [ 1 ] = 1 << V_6 -> V_37 ;
return F_16 ( V_2 , & V_20 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_19 V_20 ;
F_6 ( & V_20 , V_68 ) ;
return F_16 ( V_2 , & V_20 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_5 * V_6 , int V_61 )
{
int V_53 , V_69 , V_70 ;
if ( F_14 ( V_2 , V_6 , & V_70 ) < 0 )
return - V_71 ;
if ( V_61 == V_70 )
return 0 ;
if ( V_61 ) {
for ( V_69 = 0 ; V_69 < V_72 ; V_69 ++ ) {
V_53 = F_18 ( V_2 , V_6 ) ;
if ( V_53 > 0 )
break;
F_22 ( 1 ) ;
}
}
if ( ( V_53 = F_19 ( V_2 , V_6 ) ) < 0 )
return V_53 ;
if ( ( V_53 = F_20 ( V_2 ) ) < 0 )
return V_53 ;
for ( V_69 = 0 ; V_69 < V_72 ; V_69 ++ ) {
V_53 = F_14 ( V_2 , V_6 , & V_70 ) ;
if ( V_53 < 0 || V_70 == V_61 )
break;
V_53 = - V_73 ;
F_22 ( 1 ) ;
}
return V_53 < 0 ? - V_73 : 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_19 V_20 ;
F_6 ( & V_20 , V_74 ) ;
F_15 ( & V_20 , V_6 -> V_34 , V_6 -> V_37 , 0 ) ;
return F_16 ( V_2 , & V_20 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_75 ,
int V_76 , int V_77 ,
struct V_5 * * V_78 )
{
int V_53 ;
struct V_5 * V_6 ;
struct V_19 V_20 ;
int V_79 ;
* V_78 = NULL ;
F_6 ( & V_20 , V_80 ) ;
F_15 ( & V_20 , V_75 , V_76 , V_77 ) ;
#if 0
if (underrun_skip_sound)
rmh.Cmd[0] |= BIT_SKIP_SOUND;
#endif
V_79 = ( V_2 -> V_81 & V_82 ) != 0 ;
if ( ! V_75 && V_79 )
V_20 . V_23 [ 0 ] |= V_83 ;
V_53 = F_7 ( V_2 , & V_20 ) ;
if ( V_53 < 0 )
return V_53 ;
V_6 = F_25 ( sizeof( * V_6 ) , V_84 ) ;
if ( ! V_6 ) {
F_6 ( & V_20 , V_85 ) ;
F_15 ( & V_20 , V_75 , V_76 , 0 ) ;
F_7 ( V_2 , & V_20 ) ;
return - V_86 ;
}
V_6 -> V_37 = V_76 ;
V_6 -> V_34 = V_75 ;
V_6 -> V_41 = V_77 ;
V_6 -> V_21 = 0 ;
V_6 -> V_25 = 0 ;
V_6 -> V_79 = V_79 ;
* V_78 = V_6 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_19 V_20 ;
F_6 ( & V_20 , V_85 ) ;
F_15 ( & V_20 , V_6 -> V_34 , V_6 -> V_37 , 0 ) ;
F_7 ( V_2 , & V_20 ) ;
F_27 ( V_6 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_19 V_20 ;
F_6 ( & V_20 , V_87 ) ;
F_29 ( & V_20 , V_6 -> V_34 , V_6 -> V_37 ) ;
F_4 ( V_2 , & V_20 , V_6 ) ;
return F_16 ( V_2 , & V_20 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_19 V_20 ;
F_6 ( & V_20 , V_88 ) ;
F_29 ( & V_20 , V_6 -> V_34 , V_6 -> V_37 ) ;
return F_16 ( V_2 , & V_20 ) ;
}
static int F_31 ( struct V_89 * V_90 )
{
struct V_3 * V_4 = V_90 -> V_4 ;
struct V_1 * V_2 = F_32 ( V_90 ) ;
struct V_5 * V_6 = NULL ;
unsigned int V_91 ;
int V_53 ;
if ( V_2 -> V_92 & V_93 )
return - V_94 ;
V_91 = V_90 -> V_95 -> V_96 * 2 ;
if ( F_33 ( V_91 >= V_2 -> V_97 ) )
return - V_50 ;
V_6 = V_2 -> V_98 [ V_91 ] ;
if ( ! V_6 ) {
V_53 = F_24 ( V_2 , 0 , V_91 , 2 , & V_6 ) ;
if ( V_53 < 0 )
return V_53 ;
V_2 -> V_98 [ V_91 ] = V_6 ;
}
V_6 -> V_99 ++ ;
V_6 -> V_100 = V_90 ;
F_34 ( & V_6 -> V_101 , V_102 , ( unsigned long ) V_90 ) ;
V_2 -> V_98 [ V_91 ] = V_6 ;
V_4 -> V_103 = V_104 ;
V_4 -> V_103 . V_105 = V_2 -> V_106 . V_55 ;
V_4 -> V_107 = V_6 ;
F_35 ( V_4 , 0 , V_108 , 4 ) ;
F_35 ( V_4 , 0 , V_109 , 4 ) ;
return 0 ;
}
static int F_36 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_32 ( V_90 ) ;
struct V_5 * V_6 ;
if ( ! V_90 -> V_4 -> V_107 )
return - V_50 ;
V_6 = V_90 -> V_4 -> V_107 ;
if ( -- V_6 -> V_99 == 0 ) {
V_2 -> V_98 [ V_6 -> V_37 ] = NULL ;
F_26 ( V_2 , V_6 ) ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_53 ;
struct V_19 V_20 ;
F_38 ( V_2 , V_110 ) ;
F_6 ( & V_20 , V_111 ) ;
F_29 ( & V_20 , 0 , V_6 -> V_37 ) ;
V_53 = F_16 ( V_2 , & V_20 ) ;
if ( V_53 < 0 )
return V_53 ;
F_38 ( V_2 , V_110 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , int V_55 )
{
int V_112 , V_53 = 0 ;
V_112 = F_17 ( V_2 , V_6 ) ;
if ( V_112 < 0 ) {
F_40 ( V_2 , V_113 ) ;
F_41 ( L_2 ) ;
return V_112 ;
}
if ( V_112 < V_55 ) {
F_40 ( V_2 , V_113 ) ;
F_41 ( L_3 , V_112 ) ;
return - V_73 ;
}
F_42 ( & V_2 -> V_114 ) ;
F_43 ( V_2 , V_4 , V_6 , V_55 ) ;
V_53 = F_37 ( V_2 , V_6 ) ;
F_38 ( V_2 , V_113 ) ;
F_44 ( & V_2 -> V_114 ) ;
return V_53 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_19 V_20 ;
int V_53 , V_115 ;
T_2 V_116 ;
F_6 ( & V_20 , V_117 ) ;
F_15 ( & V_20 , V_6 -> V_34 , V_6 -> V_37 , 0 ) ;
V_53 = F_7 ( V_2 , & V_20 ) ;
if ( V_53 < 0 )
return V_53 ;
V_116 = ( ( T_2 ) ( V_20 . V_56 [ 0 ] & 0xfffff ) << 24 ) | ( T_2 ) V_20 . V_56 [ 1 ] ;
V_115 = ( int ) ( V_116 - V_6 -> V_118 ) ;
V_6 -> V_118 = V_116 ;
V_6 -> V_119 += V_115 ;
if ( V_6 -> V_119 >= ( int ) V_4 -> V_120 )
V_6 -> V_119 %= V_4 -> V_120 ;
V_6 -> V_121 += V_115 ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
struct V_5 * V_6 , int V_122 )
{
int V_69 , V_53 ;
struct V_3 * V_4 = V_90 -> V_4 ;
if ( ! V_6 -> V_123 || ( V_2 -> V_92 & V_93 ) )
return;
for ( V_69 = 0 ; V_69 < V_122 ; V_69 ++ ) {
if ( ( V_53 = F_39 ( V_2 , V_4 , V_6 ,
V_2 -> V_106 . V_55 ) ) < 0 )
return;
}
}
static void F_47 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
struct V_5 * V_6 )
{
int V_53 ;
struct V_3 * V_4 = V_90 -> V_4 ;
if ( V_6 -> V_124 && ! ( V_2 -> V_92 & V_93 ) ) {
if ( ( V_53 = F_45 ( V_2 , V_4 , V_6 ) ) < 0 )
return;
if ( V_6 -> V_121 >= ( int ) V_4 -> V_125 ) {
V_6 -> V_121 %= V_4 -> V_125 ;
F_48 ( V_90 ) ;
}
}
}
static void V_102 ( unsigned long V_126 )
{
struct V_89 * V_90 = (struct V_89 * ) V_126 ;
struct V_1 * V_2 = V_90 -> V_95 -> V_107 ;
struct V_5 * V_6 = V_90 -> V_4 -> V_107 ;
int V_53 ;
if ( ( V_53 = F_28 ( V_2 , V_6 ) ) < 0 ) {
F_49 ( V_127 L_4 ) ;
return;
}
if ( ( V_53 = F_21 ( V_2 , V_6 , 1 ) ) < 0 ) {
F_49 ( V_127 L_5 ) ;
return;
}
}
static int F_50 ( struct V_89 * V_90 , int V_128 )
{
struct V_1 * V_2 = F_32 ( V_90 ) ;
struct V_5 * V_6 = V_90 -> V_4 -> V_107 ;
int V_53 ;
if ( V_2 -> V_92 & V_93 )
return - V_94 ;
switch ( V_128 ) {
case V_129 :
case V_130 :
if ( ! V_6 -> V_34 )
F_46 ( V_2 , V_90 , V_6 , 2 ) ;
F_51 ( & V_6 -> V_101 ) ;
V_2 -> V_131 ++ ;
V_6 -> V_124 = 1 ;
break;
case V_132 :
case V_133 :
F_21 ( V_2 , V_6 , 0 ) ;
F_23 ( V_2 , V_6 ) ;
F_30 ( V_2 , V_6 ) ;
V_2 -> V_131 -- ;
V_6 -> V_124 = 0 ;
break;
case V_134 :
if ( ( V_53 = F_21 ( V_2 , V_6 , 0 ) ) < 0 )
return V_53 ;
break;
case V_135 :
if ( ( V_53 = F_21 ( V_2 , V_6 , 1 ) ) < 0 )
return V_53 ;
break;
default:
return - V_50 ;
}
return 0 ;
}
static T_3 F_52 ( struct V_89 * V_90 )
{
struct V_3 * V_4 = V_90 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_107 ;
return V_6 -> V_119 ;
}
static int F_53 ( struct V_89 * V_90 ,
struct V_136 * V_137 )
{
return F_54
( V_90 , F_55 ( V_137 ) ) ;
}
static int F_56 ( struct V_89 * V_90 )
{
return F_57 ( V_90 ) ;
}
static int F_58 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_32 ( V_90 ) ;
struct V_3 * V_4 = V_90 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_107 ;
int V_53 , V_79 ;
if ( V_2 -> V_92 & V_93 )
return - V_94 ;
V_79 = ( V_2 -> V_81 & V_82 ) != 0 ;
if ( V_79 != V_6 -> V_79 && ! V_6 -> V_34 ) {
struct V_19 V_20 ;
F_13 ( V_60 L_6 , V_79 ) ;
F_6 ( & V_20 , V_85 ) ;
F_15 ( & V_20 , 0 , V_6 -> V_37 , 0 ) ;
if ( ( V_53 = F_7 ( V_2 , & V_20 ) ) < 0 )
return V_53 ;
F_6 ( & V_20 , V_80 ) ;
F_15 ( & V_20 , 0 , V_6 -> V_37 , V_6 -> V_41 ) ;
if ( V_79 )
V_20 . V_23 [ 0 ] |= V_83 ;
if ( ( V_53 = F_7 ( V_2 , & V_20 ) ) < 0 )
return V_53 ;
V_6 -> V_79 = V_79 ;
}
if ( V_2 -> V_131 && V_2 -> V_138 != V_4 -> V_45 ) {
F_49 ( V_127 L_7
L_8 , V_4 -> V_45 , V_2 -> V_138 ) ;
return - V_50 ;
}
F_59 ( V_2 , V_4 -> V_45 ) ;
if ( ( V_53 = F_8 ( V_2 , V_6 , V_4 ) ) < 0 )
return V_53 ;
if ( F_60 ( V_2 ) ) {
V_6 -> V_139 = 2 ;
} else {
V_6 -> V_139 = 4 ;
}
V_6 -> V_12 = F_61 ( V_4 , V_4 -> V_120 ) ;
V_6 -> V_140 = F_61 ( V_4 , V_4 -> V_125 ) ;
V_6 -> V_8 = 0 ;
F_45 ( V_2 , V_4 , V_6 ) ;
V_6 -> V_121 = 0 ;
V_6 -> V_119 = 0 ;
V_6 -> V_123 = 1 ;
return 0 ;
}
static int F_62 ( struct V_89 * V_90 )
{
struct V_3 * V_4 = V_90 -> V_4 ;
struct V_1 * V_2 = F_32 ( V_90 ) ;
struct V_5 * V_6 ;
struct V_5 * V_141 = NULL ;
unsigned int V_91 ;
int V_53 ;
if ( V_2 -> V_92 & V_93 )
return - V_94 ;
V_91 = V_90 -> V_95 -> V_96 * 2 ;
if ( F_33 ( V_91 >= V_2 -> V_142 ) )
return - V_50 ;
V_53 = F_24 ( V_2 , 1 , V_91 , 2 , & V_6 ) ;
if ( V_53 < 0 )
return V_53 ;
V_6 -> V_100 = V_90 ;
F_34 ( & V_6 -> V_101 , V_102 , ( unsigned long ) V_90 ) ;
V_2 -> V_143 [ V_91 ] = V_6 ;
if ( V_2 -> V_144 [ V_91 ] ) {
V_141 = V_2 -> V_98 [ V_91 ] ;
if ( ! V_141 ) {
V_53 = F_24 ( V_2 , 0 , V_91 , 2 , & V_141 ) ;
if ( V_53 < 0 )
return V_53 ;
V_2 -> V_98 [ V_91 ] = V_141 ;
}
V_141 -> V_99 ++ ;
F_63 ( V_2 , V_91 , V_2 -> V_145 [ V_91 ] ,
V_2 -> V_144 [ V_91 ] ) ;
F_63 ( V_2 , V_91 + 1 , V_2 -> V_145 [ V_91 + 1 ] ,
V_2 -> V_144 [ V_91 + 1 ] ) ;
}
V_6 -> V_146 = V_141 ;
V_4 -> V_103 = V_147 ;
V_4 -> V_103 . V_105 = V_2 -> V_106 . V_55 ;
V_4 -> V_107 = V_6 ;
F_35 ( V_4 , 0 , V_108 , 4 ) ;
F_35 ( V_4 , 0 , V_109 , 4 ) ;
return 0 ;
}
static int F_64 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_32 ( V_90 ) ;
struct V_5 * V_6 ;
struct V_5 * V_141 ;
if ( ! V_90 -> V_4 -> V_107 )
return - V_50 ;
V_6 = V_90 -> V_4 -> V_107 ;
V_2 -> V_143 [ V_6 -> V_37 ] = NULL ;
V_141 = V_6 -> V_146 ;
if ( V_141 ) {
if ( -- V_141 -> V_99 == 0 ) {
F_26 ( V_2 , V_141 ) ;
V_2 -> V_98 [ V_6 -> V_37 ] = NULL ;
V_6 -> V_146 = NULL ;
}
}
F_26 ( V_2 , V_6 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , struct V_89 * V_90 ,
struct V_5 * V_6 )
{
int V_55 , V_112 , V_116 ;
struct V_3 * V_4 = V_90 -> V_4 ;
if ( ! V_6 -> V_123 || ( V_2 -> V_92 & V_93 ) )
return;
V_55 = V_4 -> V_120 - F_66 ( V_4 ) ;
if ( ! V_55 )
return;
V_55 = F_61 ( V_4 , V_55 ) ;
V_112 = F_17 ( V_2 , V_6 ) ;
if ( V_112 < 0 )
goto V_148;
if ( V_55 > V_112 )
V_55 = V_112 ;
V_55 = ( V_55 / 3 ) * 3 ;
if ( V_55 < V_149 )
goto V_148;
V_116 = V_55 - V_149 ;
while ( V_116 > 0 ) {
if ( ( V_6 -> V_8 % V_6 -> V_139 ) == 0 )
break;
if ( F_67 ( V_2 ) < 0 )
goto V_148;
F_1 ( V_2 , V_4 , V_6 ) ;
V_116 -= 3 ;
}
if ( V_116 > 0 ) {
int V_139 = V_6 -> V_139 * 3 ;
V_112 = ( V_116 / V_139 ) * V_139 ;
F_68 ( V_2 , V_4 , V_6 , V_112 ) ;
V_116 -= V_112 ;
}
while ( V_116 > 0 ) {
if ( F_67 ( V_2 ) < 0 )
goto V_148;
F_1 ( V_2 , V_4 , V_6 ) ;
V_116 -= 3 ;
}
F_38 ( V_2 , V_113 ) ;
V_116 = V_149 ;
while ( V_116 > 0 ) {
F_1 ( V_2 , V_4 , V_6 ) ;
V_116 -= 3 ;
}
V_6 -> V_121 += V_55 ;
if ( V_6 -> V_121 >= V_6 -> V_140 ) {
V_6 -> V_121 %= V_6 -> V_140 ;
F_48 ( V_90 ) ;
}
return;
V_148:
F_38 ( V_2 , V_113 ) ;
return;
}
static T_3 F_69 ( struct V_89 * V_90 )
{
struct V_3 * V_4 = V_90 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_107 ;
return F_70 ( V_4 , V_6 -> V_8 ) ;
}
void F_71 ( struct V_1 * V_2 , unsigned int V_150 )
{
unsigned int V_69 ;
struct V_5 * V_6 ;
#define F_72 (END_OF_BUFFER_EVENTS_PENDING|ASYNC_EVENTS_PENDING)
if ( V_150 & F_72 ) {
F_6 ( & V_2 -> V_151 , V_152 ) ;
if ( V_150 & V_153 )
V_2 -> V_151 . V_23 [ 0 ] |= 0x00000001 ;
if ( V_150 & V_154 )
V_2 -> V_151 . V_23 [ 0 ] |= 0x00000002 ;
if ( F_7 ( V_2 , & V_2 -> V_151 ) < 0 ) {
F_13 ( V_127 L_9 ) ;
return;
}
V_69 = 1 ;
while ( V_69 < V_2 -> V_151 . V_155 ) {
int V_156 , V_9 , V_75 , V_157 ;
V_156 = V_2 -> V_151 . V_56 [ V_69 ] & V_158 ;
V_75 = ( V_2 -> V_151 . V_56 [ V_69 ] & 0x400000 ) ? 1 : 0 ;
V_157 = ( V_2 -> V_151 . V_56 [ V_69 ] & 0x800000 ) ? 1 : 0 ;
V_69 ++ ;
if ( V_150 & V_153 )
V_69 ++ ;
V_9 = 1 ;
if ( V_150 & V_154 ) {
if ( V_157 )
V_9 = V_2 -> V_151 . V_56 [ V_69 ] ;
V_69 ++ ;
}
if ( V_75 )
continue;
if ( F_33 ( V_156 < 0 || V_156 >= V_2 -> V_97 ) )
continue;
V_6 = V_2 -> V_98 [ V_156 ] ;
if ( V_6 && V_6 -> V_100 ) {
F_47 ( V_2 , V_6 -> V_100 , V_6 ) ;
F_46 ( V_2 , V_6 -> V_100 , V_6 , V_9 ) ;
}
}
}
for ( V_69 = 0 ; V_69 < V_2 -> V_142 ; V_69 ++ ) {
V_6 = V_2 -> V_143 [ V_69 ] ;
if ( V_6 && V_6 -> V_100 )
F_65 ( V_2 , V_6 -> V_100 , V_6 ) ;
}
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_19 V_20 ;
int V_159 ;
F_6 ( & V_20 , V_160 ) ;
if ( F_7 ( V_2 , & V_20 ) < 0 ) {
F_49 ( V_127 L_10 ) ;
return - V_161 ;
}
V_2 -> V_97 = V_20 . V_56 [ 0 ] & V_158 ;
V_2 -> V_142 = ( V_20 . V_56 [ 0 ] >> ( V_38 * 2 ) ) & V_158 ;
V_2 -> V_162 = V_20 . V_56 [ 1 ] ;
V_2 -> V_98 = F_74 ( V_2 -> V_97 , sizeof( struct V_5 * ) , V_84 ) ;
if ( ! V_2 -> V_98 )
return - V_86 ;
V_2 -> V_143 = F_74 ( V_2 -> V_142 , sizeof( struct V_5 * ) , V_84 ) ;
if ( ! V_2 -> V_143 ) {
F_27 ( V_2 -> V_98 ) ;
return - V_86 ;
}
V_159 = V_2 -> V_106 . V_55 ;
V_2 -> V_106 . V_55 = 0 ;
F_12 ( V_2 , & V_2 -> V_106 ) ;
if ( V_159 > 0 ) {
V_2 -> V_106 . V_55 = ( ( V_159 + V_2 -> V_106 . V_59 - 1 ) /
V_2 -> V_106 . V_59 ) * V_2 -> V_106 . V_59 ;
if ( V_2 -> V_106 . V_55 > V_2 -> V_106 . V_57 )
V_2 -> V_106 . V_55 = V_2 -> V_106 . V_57 ;
} else
V_2 -> V_106 . V_55 = V_2 -> V_106 . V_58 ;
F_12 ( V_2 , & V_2 -> V_106 ) ;
return 0 ;
}
static void F_75 ( struct V_163 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_107 ;
V_2 -> V_95 [ V_95 -> V_96 ] = NULL ;
F_27 ( V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
F_27 ( V_2 -> V_143 ) ;
V_2 -> V_143 = NULL ;
}
int F_76 ( struct V_1 * V_2 )
{
struct V_163 * V_95 ;
unsigned int V_69 ;
int V_53 ;
if ( ( V_53 = F_73 ( V_2 ) ) < 0 )
return V_53 ;
for ( V_69 = 0 ; V_69 < V_2 -> V_103 -> V_164 ; V_69 ++ ) {
unsigned int V_165 , V_166 ;
V_165 = V_2 -> V_97 > V_69 * 2 ? 1 : 0 ;
V_166 = V_2 -> V_142 > V_69 * 2 ? 1 : 0 ;
if ( ! V_165 && ! V_166 )
break;
V_53 = F_77 ( V_2 -> V_167 , L_11 , V_69 ,
V_165 , V_166 , & V_95 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_165 )
F_78 ( V_95 , V_168 , & V_169 ) ;
if ( V_166 )
F_78 ( V_95 , V_170 , & V_171 ) ;
V_95 -> V_107 = V_2 ;
V_95 -> V_172 = F_75 ;
V_95 -> V_173 = 0 ;
strcpy ( V_95 -> V_174 , V_2 -> V_167 -> V_175 ) ;
V_2 -> V_95 [ V_69 ] = V_95 ;
}
return 0 ;
}
