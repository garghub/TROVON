static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
void * V_8 ;
int V_9 = - V_10 ;
F_2 ( V_2 -> V_11 , L_1 ,
V_3 , V_4 , V_5 , V_6 ) ;
V_8 = F_3 ( V_6 , V_12 ) ;
if ( ! V_8 )
goto V_13;
V_9 = F_4 (
V_2 -> V_14 ,
F_5 ( V_2 -> V_14 , 0 ) ,
V_3 ,
V_15 | V_16 | V_17 ,
V_4 ,
V_5 ,
V_8 ,
V_6 ,
V_18 ) ;
if ( V_9 == V_6 )
memcpy ( V_7 , V_8 , V_6 ) ;
else if ( V_9 >= 0 )
V_9 = - V_19 ;
F_6 ( V_8 ) ;
V_13:
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
void * V_8 = NULL ;
int V_9 = - V_10 ;
F_2 ( V_2 -> V_11 , L_2 ,
V_3 , V_4 , V_5 , V_6 ) ;
if ( V_7 ) {
V_8 = F_8 ( V_7 , V_6 , V_12 ) ;
if ( ! V_8 )
goto V_13;
}
V_9 = F_4 (
V_2 -> V_14 ,
F_9 ( V_2 -> V_14 , 0 ) ,
V_3 ,
V_20 | V_16 | V_17 ,
V_4 ,
V_5 ,
V_8 ,
V_6 ,
V_21 ) ;
F_6 ( V_8 ) ;
V_13:
return V_9 ;
}
static void F_10 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = (struct V_23 * ) V_22 -> V_25 ;
int V_26 = V_22 -> V_26 ;
if ( V_26 < 0 )
F_11 ( V_27 L_3 ,
V_26 ) ;
F_6 ( V_24 ) ;
F_12 ( V_22 ) ;
}
static void
F_13 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
struct V_23 * V_24 ;
int V_26 ;
struct V_22 * V_22 ;
F_2 ( V_2 -> V_11 , L_4 ,
V_3 , V_4 , V_5 , V_6 ) ;
if ( ( V_22 = F_14 ( 0 , V_28 ) ) == NULL ) {
F_15 ( V_2 -> V_11 , L_5 ) ;
return;
}
if ( ( V_24 = F_3 ( sizeof( struct V_23 ) , V_28 ) ) == NULL ) {
F_15 ( V_2 -> V_11 , L_6 ) ;
F_12 ( V_22 ) ;
return;
}
V_24 -> V_29 = V_20 | V_16 | V_17 ;
V_24 -> V_30 = V_3 ;
V_24 -> V_31 = F_16 ( V_4 ) ;
V_24 -> V_32 = F_16 ( V_5 ) ;
V_24 -> V_33 = F_16 ( V_6 ) ;
F_17 ( V_22 , V_2 -> V_14 ,
F_9 ( V_2 -> V_14 , 0 ) ,
( void * ) V_24 , V_7 , V_6 ,
F_10 , V_24 ) ;
if( ( V_26 = F_18 ( V_22 , V_28 ) ) < 0 ) {
F_15 ( V_2 -> V_11 , L_7 ,
V_26 ) ;
F_6 ( V_24 ) ;
F_12 ( V_22 ) ;
}
}
static int F_19 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
T_1 * V_36 ;
T_3 V_37 ;
char * V_38 ;
struct V_34 * V_39 ;
T_2 V_6 ;
V_36 = ( T_1 * ) V_35 -> V_7 ;
memcpy ( & V_37 , V_36 , sizeof( V_37 ) ) ;
F_20 ( & V_37 ) ;
V_38 = V_36 + sizeof( V_37 ) ;
F_21 ( V_35 , 4 ) ;
while ( V_35 -> V_40 > 0 ) {
if ( ( short ) ( V_37 & 0x0000ffff ) !=
~ ( ( short ) ( ( V_37 & 0xffff0000 ) >> 16 ) ) ) {
F_15 ( V_2 -> V_11 , L_8 ) ;
}
V_6 = ( T_2 ) ( V_37 & 0x0000ffff ) ;
if ( ( V_35 -> V_40 ) - ( ( V_6 + 1 ) & 0xfffe ) == 0 ) {
T_1 V_41 = ( unsigned long ) V_35 -> V_7 & 0x3 ;
if ( V_41 != 0x2 ) {
T_1 V_42 = ( V_41 + 2 ) & 0x3 ;
memmove ( V_35 -> V_7 - V_42 ,
V_35 -> V_7 ,
V_6 ) ;
V_35 -> V_7 -= V_42 ;
F_22 ( V_35 , V_6 ) ;
}
return 2 ;
}
if ( V_6 > V_2 -> V_11 -> V_43 + V_44 ) {
F_15 ( V_2 -> V_11 , L_9 ,
V_6 ) ;
return 0 ;
}
V_39 = F_23 ( V_35 , V_28 ) ;
if ( V_39 ) {
T_1 V_41 = ( unsigned long ) V_38 & 0x3 ;
V_39 -> V_40 = V_6 ;
if ( V_41 != 0x2 ) {
T_1 V_42 = ( V_41 + 2 ) & 0x3 ;
memmove ( V_38 - V_42 , V_38 , V_6 ) ;
V_38 -= V_42 ;
}
V_39 -> V_7 = V_38 ;
F_22 ( V_39 , V_6 ) ;
F_24 ( V_2 , V_39 ) ;
} else {
return 0 ;
}
F_21 ( V_35 , ( V_6 + 1 ) & 0xfffe ) ;
if ( V_35 -> V_40 == 0 )
break;
V_36 = ( T_1 * ) V_35 -> V_7 ;
memcpy ( & V_37 , V_36 , sizeof( V_37 ) ) ;
F_20 ( & V_37 ) ;
V_38 = V_36 + sizeof( V_37 ) ;
F_21 ( V_35 , 4 ) ;
}
if ( V_35 -> V_40 < 0 ) {
F_15 ( V_2 -> V_11 , L_10 ,
V_35 -> V_40 ) ;
return 0 ;
}
return 1 ;
}
static struct V_34 * F_25 ( struct V_1 * V_2 , struct V_34 * V_35 ,
T_4 V_45 )
{
int V_46 ;
int V_47 = F_26 ( V_35 ) ;
int V_48 = F_27 ( V_35 ) ;
T_3 V_49 ;
T_3 V_50 = 0xffff0000 ;
V_46 = ( ( V_35 -> V_40 + 4 ) % 512 ) ? 0 : 4 ;
if ( ( ! F_28 ( V_35 ) ) &&
( ( V_47 + V_48 ) >= ( 4 + V_46 ) ) ) {
if ( ( V_47 < 4 ) || ( V_48 < V_46 ) ) {
V_35 -> V_7 = memmove ( V_35 -> V_36 + 4 , V_35 -> V_7 , V_35 -> V_40 ) ;
F_22 ( V_35 , V_35 -> V_40 ) ;
}
} else {
struct V_34 * V_51 ;
V_51 = F_29 ( V_35 , 4 , V_46 , V_45 ) ;
F_30 ( V_35 ) ;
V_35 = V_51 ;
if ( ! V_35 )
return NULL ;
}
F_31 ( V_35 , 4 ) ;
V_49 = ( ( ( V_35 -> V_40 - 4 ) ^ 0x0000ffff ) << 16 ) + ( V_35 -> V_40 - 4 ) ;
F_32 ( & V_49 ) ;
F_33 ( V_35 , & V_49 , sizeof( V_49 ) ) ;
if ( ( V_35 -> V_40 % 512 ) == 0 ) {
F_32 ( & V_50 ) ;
memcpy ( F_34 ( V_35 ) , & V_50 , sizeof( V_50 ) ) ;
F_35 ( V_35 , sizeof( V_50 ) ) ;
}
return V_35 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_22 * V_22 )
{
struct V_52 * V_53 ;
int V_54 ;
if ( V_22 -> V_55 < 8 )
return;
V_53 = V_22 -> V_56 ;
V_54 = V_53 -> V_54 & 0x01 ;
if ( F_37 ( V_2 -> V_11 ) != V_54 ) {
if ( V_54 ) {
F_38 ( V_2 -> V_11 ) ;
F_39 ( V_2 , V_57 ) ;
} else
F_40 ( V_2 -> V_11 ) ;
F_2 ( V_2 -> V_11 , L_11 , V_54 ) ;
}
}
static inline int F_41 ( struct V_1 * V_2 )
{
int V_58 ;
V_58 = F_7 ( V_2 , V_59 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_58 < 0 )
F_15 ( V_2 -> V_11 , L_12 ) ;
return V_58 ;
}
static inline int F_42 ( struct V_1 * V_2 )
{
int V_58 ;
V_58 = F_7 ( V_2 , V_60 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_58 < 0 )
F_15 ( V_2 -> V_11 , L_13 ) ;
return V_58 ;
}
static inline int F_43 ( struct V_1 * V_2 )
{
T_1 V_8 [ 2 ] ;
int V_58 = F_1 ( V_2 , V_61 , 0 , 0 , 2 , V_8 ) ;
F_2 ( V_2 -> V_11 , L_14 ) ;
if ( V_58 < 0 ) {
F_15 ( V_2 -> V_11 , L_15 , V_58 ) ;
goto V_13;
}
F_2 ( V_2 -> V_11 , L_16 ,
* ( ( V_62 * ) V_8 ) ) ;
V_58 = V_8 [ 1 ] ;
V_13:
return V_58 ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_45 )
{
int V_58 ;
V_58 = F_7 ( V_2 , V_63 , V_45 , 0 , 0 , NULL ) ;
if ( V_58 < 0 )
F_15 ( V_2 -> V_11 , L_17 , V_58 ) ;
return V_58 ;
}
static T_2 F_45 ( struct V_1 * V_2 )
{
V_62 V_64 ;
int V_58 = F_1 ( V_2 , V_65 , 0 , 0 , 2 , & V_64 ) ;
if ( V_58 < 0 ) {
F_15 ( V_2 -> V_11 , L_18 , V_58 ) ;
goto V_13;
}
V_58 = F_46 ( V_64 ) ;
V_13:
return V_58 ;
}
static int F_47 ( struct V_1 * V_2 , T_2 V_66 )
{
int V_58 ;
F_2 ( V_2 -> V_11 , L_19 , V_66 ) ;
V_58 = F_7 ( V_2 , V_67 , V_66 , 0 , 0 , NULL ) ;
if ( V_58 < 0 )
F_15 ( V_2 -> V_11 , L_20 ,
V_66 , V_58 ) ;
return V_58 ;
}
static T_2 F_48 ( struct V_1 * V_2 )
{
V_62 V_64 ;
int V_58 = F_1 ( V_2 , V_68 , 0 , 0 , 2 , & V_64 ) ;
if ( V_58 < 0 ) {
F_15 ( V_2 -> V_11 , L_21 ,
V_58 ) ;
goto V_13;
}
V_58 = F_46 ( V_64 ) ;
V_13:
return V_58 ;
}
static int F_49 ( struct V_1 * V_2 , T_2 V_66 )
{
int V_58 ;
F_2 ( V_2 -> V_11 , L_22 , V_66 ) ;
V_58 = F_7 ( V_2 , V_69 , V_66 , 0 , 0 , NULL ) ;
if ( V_58 < 0 )
F_15 ( V_2 -> V_11 , L_23 ,
V_66 , V_58 ) ;
return V_58 ;
}
static int F_50 ( struct V_1 * V_2 , T_2 V_4 , int V_70 )
{
int V_58 ;
F_2 ( V_2 -> V_11 , L_24 , V_4 ) ;
V_58 = F_7 ( V_2 , V_71 , V_4 , 0 , 0 , NULL ) ;
if ( V_58 < 0 )
F_15 ( V_2 -> V_11 , L_25 ,
V_4 , V_58 ) ;
if ( V_70 )
F_51 ( V_70 ) ;
return V_58 ;
}
static void F_52 ( struct V_72 * V_11 )
{
struct V_1 * V_2 = F_53 ( V_11 ) ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
T_2 V_74 = V_75 ;
if ( V_11 -> V_45 & V_76 ) {
V_74 |= V_77 ;
} else if ( V_11 -> V_45 & V_78 ||
F_54 ( V_11 ) > V_79 ) {
V_74 |= V_80 ;
} else if ( F_55 ( V_11 ) ) {
} else {
struct V_81 * V_82 ;
T_3 V_83 ;
memset ( V_7 -> V_84 , 0 , V_85 ) ;
F_56 (ha, net) {
V_83 = F_57 ( V_86 , V_82 -> V_87 ) >> 26 ;
V_7 -> V_84 [ V_83 >> 3 ] |=
1 << ( V_83 & 7 ) ;
}
F_13 ( V_2 , V_88 , 0 , 0 ,
V_85 , V_7 -> V_84 ) ;
V_74 |= V_89 ;
}
F_13 ( V_2 , V_67 , V_74 , 0 , 0 , NULL ) ;
}
static int F_58 ( struct V_72 * V_90 , int V_91 , int V_92 )
{
struct V_1 * V_2 = F_53 ( V_90 ) ;
V_62 V_93 ;
F_59 ( & V_2 -> V_94 ) ;
F_41 ( V_2 ) ;
F_1 ( V_2 , V_95 , V_91 ,
( V_96 ) V_92 , 2 , & V_93 ) ;
F_42 ( V_2 ) ;
F_60 ( & V_2 -> V_94 ) ;
F_2 ( V_2 -> V_11 , L_26 ,
V_91 , V_92 , F_46 ( V_93 ) ) ;
return F_46 ( V_93 ) ;
}
static void
F_61 ( struct V_72 * V_90 , int V_91 , int V_92 , int V_97 )
{
struct V_1 * V_2 = F_53 ( V_90 ) ;
V_62 V_93 = F_16 ( V_97 ) ;
F_2 ( V_2 -> V_11 , L_27 ,
V_91 , V_92 , V_97 ) ;
F_59 ( & V_2 -> V_94 ) ;
F_41 ( V_2 ) ;
F_7 ( V_2 , V_98 , V_91 , ( V_96 ) V_92 , 2 , & V_93 ) ;
F_42 ( V_2 ) ;
F_60 ( & V_2 -> V_94 ) ;
}
static T_3 F_62 ( struct V_1 * V_2 )
{
int V_99 ;
T_3 V_91 ;
V_99 = F_58 ( V_2 -> V_11 , V_2 -> V_100 . V_91 , V_101 ) ;
if ( V_99 < 0 )
return 0 ;
V_91 = ( V_99 & 0xffff ) << 16 ;
V_99 = F_58 ( V_2 -> V_11 , V_2 -> V_100 . V_91 , V_102 ) ;
if ( V_99 < 0 )
return 0 ;
V_91 |= ( V_99 & 0xffff ) ;
return V_91 ;
}
static void
F_63 ( struct V_72 * V_11 , struct V_103 * V_104 )
{
struct V_1 * V_2 = F_53 ( V_11 ) ;
T_1 V_105 ;
if ( F_1 ( V_2 , V_106 , 0 , 0 , 1 , & V_105 ) < 0 ) {
V_104 -> V_107 = 0 ;
V_104 -> V_108 = 0 ;
return;
}
V_104 -> V_107 = V_109 | V_110 ;
V_104 -> V_108 = 0 ;
if ( V_105 & V_111 ) {
if ( V_105 & V_112 )
V_104 -> V_108 |= V_109 ;
if ( V_105 & V_113 )
V_104 -> V_108 |= V_110 ;
}
}
static int
F_64 ( struct V_72 * V_11 , struct V_103 * V_104 )
{
struct V_1 * V_2 = F_53 ( V_11 ) ;
T_1 V_105 = 0 ;
if ( V_104 -> V_108 & V_109 )
V_105 |= V_112 ;
if ( V_104 -> V_108 & V_110 )
V_105 |= V_113 ;
if ( V_105 != 0 )
V_105 |= V_111 ;
if ( F_7 ( V_2 , V_114 ,
V_105 , 0 , 0 , NULL ) < 0 )
return - V_19 ;
return 0 ;
}
static int F_65 ( struct V_72 * V_11 )
{
struct V_1 * V_2 = F_53 ( V_11 ) ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
return V_7 -> V_115 ;
}
static int F_66 ( struct V_72 * V_11 ,
struct V_116 * V_117 , T_1 * V_7 )
{
struct V_1 * V_2 = F_53 ( V_11 ) ;
V_62 * V_118 = ( V_62 * ) V_7 ;
int V_119 ;
if ( V_117 -> V_40 % 2 )
return - V_19 ;
V_117 -> V_120 = V_121 ;
for ( V_119 = 0 ; V_119 < V_117 -> V_40 / 2 ; V_119 ++ ) {
if ( F_1 ( V_2 , V_122 ,
V_117 -> V_123 + V_119 , 0 , 2 , & V_118 [ V_119 ] ) < 0 )
return - V_19 ;
}
return 0 ;
}
static void F_67 ( struct V_72 * V_11 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = F_53 ( V_11 ) ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
F_68 ( V_11 , V_125 ) ;
strncpy ( V_125 -> V_126 , V_127 , sizeof V_125 -> V_126 ) ;
strncpy ( V_125 -> V_128 , V_129 , sizeof V_125 -> V_128 ) ;
V_125 -> V_130 = V_7 -> V_115 ;
}
static T_3 F_69 ( struct V_72 * V_11 )
{
struct V_1 * V_2 = F_53 ( V_11 ) ;
return F_70 ( & V_2 -> V_100 ) ;
}
static int F_71 ( struct V_72 * V_11 , struct V_131 * V_132 , int V_3 )
{
struct V_1 * V_2 = F_53 ( V_11 ) ;
return F_72 ( & V_2 -> V_100 , F_73 ( V_132 ) , V_3 , NULL ) ;
}
static int F_74 ( struct V_72 * V_11 , void * V_133 )
{
struct V_1 * V_2 = F_53 ( V_11 ) ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
struct V_134 * V_87 = V_133 ;
if ( F_75 ( V_11 ) )
return - V_135 ;
if ( ! F_76 ( V_87 -> V_136 ) )
return - V_137 ;
memcpy ( V_11 -> V_138 , V_87 -> V_136 , V_86 ) ;
memcpy ( V_7 -> V_139 , V_87 -> V_136 , V_86 ) ;
F_13 ( V_2 , V_140 , 0 , 0 , V_86 ,
V_7 -> V_139 ) ;
return 0 ;
}
static void F_77 ( struct V_72 * V_11 )
{
struct V_1 * V_2 = F_53 ( V_11 ) ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
T_1 V_74 = 0x8c ;
if ( V_11 -> V_45 & V_76 ) {
V_74 |= 0x01 ;
} else if ( V_11 -> V_45 & V_78 ||
F_54 ( V_11 ) > V_79 ) {
V_74 |= 0x02 ;
} else if ( F_55 ( V_11 ) ) {
} else {
struct V_81 * V_82 ;
T_3 V_83 ;
memset ( V_7 -> V_84 , 0 , V_85 ) ;
F_56 (ha, net) {
V_83 = F_57 ( V_86 , V_82 -> V_87 ) >> 26 ;
V_7 -> V_84 [ V_83 >> 3 ] |=
1 << ( V_83 & 7 ) ;
}
F_13 ( V_2 , V_88 , 0 , 0 ,
V_85 , V_7 -> V_84 ) ;
V_74 |= 0x10 ;
}
F_13 ( V_2 , V_67 , V_74 , 0 , 0 , NULL ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
T_1 V_66 ;
struct V_141 V_142 = { . V_3 = V_143 } ;
F_79 ( & V_2 -> V_100 , 1 , 1 ) ;
F_80 ( & V_2 -> V_100 , & V_142 ) ;
V_66 = V_144 ;
if ( V_142 . V_145 != V_146 )
V_66 |= ~ V_147 ;
F_2 ( V_2 -> V_11 , L_28 ,
F_81 ( & V_142 ) , V_142 . V_145 , V_66 ) ;
F_49 ( V_2 , V_66 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_148 * V_149 )
{
int V_58 = 0 ;
T_1 V_8 [ V_86 ] ;
int V_119 ;
unsigned long V_150 = V_2 -> V_151 -> V_7 ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
V_7 -> V_115 = V_152 ;
F_83 ( V_2 , V_149 ) ;
for ( V_119 = 2 ; V_119 >= 0 ; V_119 -- ) {
if ( ( V_58 = F_7 ( V_2 , V_71 ,
( V_150 >> ( V_119 * 8 ) ) & 0xff , 0 , 0 ,
NULL ) ) < 0 )
goto V_13;
F_51 ( 5 ) ;
}
if ( ( V_58 = F_47 ( V_2 , 0x80 ) ) < 0 )
goto V_13;
if ( ( V_58 = F_1 ( V_2 , V_153 ,
0 , 0 , V_86 , V_8 ) ) < 0 ) {
F_84 ( L_29 , V_58 ) ;
goto V_13;
}
memcpy ( V_2 -> V_11 -> V_138 , V_8 , V_86 ) ;
V_2 -> V_100 . V_2 = V_2 -> V_11 ;
V_2 -> V_100 . V_154 = F_58 ;
V_2 -> V_100 . V_155 = F_61 ;
V_2 -> V_100 . V_156 = 0x3f ;
V_2 -> V_100 . V_157 = 0x1f ;
V_2 -> V_100 . V_91 = F_43 ( V_2 ) ;
V_2 -> V_11 -> V_158 = & V_159 ;
V_2 -> V_11 -> V_160 = & V_161 ;
F_61 ( V_2 -> V_11 , V_2 -> V_100 . V_91 , V_162 , V_163 ) ;
F_61 ( V_2 -> V_11 , V_2 -> V_100 . V_91 , V_164 ,
V_165 | V_166 | V_167 ) ;
F_85 ( & V_2 -> V_100 ) ;
return 0 ;
V_13:
return V_58 ;
}
static int F_86 ( struct V_1 * V_2 )
{
T_2 V_66 ;
struct V_141 V_142 = { . V_3 = V_143 } ;
F_79 ( & V_2 -> V_100 , 1 , 1 ) ;
F_80 ( & V_2 -> V_100 , & V_142 ) ;
V_66 = V_168 ;
if ( F_81 ( & V_142 ) != V_169 )
V_66 &= ~ V_170 ;
if ( V_142 . V_145 != V_146 )
V_66 &= ~ V_171 ;
F_2 ( V_2 -> V_11 , L_30 ,
F_81 ( & V_142 ) , V_142 . V_145 , V_66 ) ;
F_49 ( V_2 , V_66 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_148 * V_149 )
{
int V_58 , V_172 ;
T_2 V_74 ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
T_1 V_8 [ V_86 ] ;
T_3 V_173 ;
V_7 -> V_115 = V_174 ;
F_83 ( V_2 , V_149 ) ;
if ( ( V_58 = F_50 ( V_2 ,
V_175 | V_176 | V_177 , 5 ) ) < 0 )
goto V_13;
V_172 = ( ( F_43 ( V_2 ) & 0x1f ) == 0x10 ? 1 : 0 ) ;
if ( ( V_58 = F_7 ( V_2 , V_178 ,
V_172 , 0 , 0 , NULL ) ) < 0 ) {
F_84 ( L_31 , V_58 ) ;
goto V_13;
}
if ( ( V_58 = F_44 ( V_2 , V_179 | V_180 ) ) < 0 )
goto V_13;
F_51 ( 150 ) ;
if ( ( V_58 = F_44 ( V_2 , V_181 ) ) < 0 )
goto V_13;
F_51 ( 150 ) ;
if ( V_172 ) {
if ( ( V_58 = F_44 ( V_2 , V_182 ) ) < 0 )
goto V_13;
}
else {
if ( ( V_58 = F_44 ( V_2 , V_183 ) ) < 0 )
goto V_13;
}
F_51 ( 150 ) ;
V_74 = F_45 ( V_2 ) ;
F_84 ( L_32 , V_74 ) ;
if ( ( V_58 = F_47 ( V_2 , 0x0000 ) ) < 0 )
goto V_13;
V_74 = F_45 ( V_2 ) ;
F_84 ( L_33 , V_74 ) ;
if ( ( V_58 = F_1 ( V_2 , V_184 ,
0 , 0 , V_86 , V_8 ) ) < 0 ) {
F_84 ( L_34 , V_58 ) ;
goto V_13;
}
memcpy ( V_2 -> V_11 -> V_138 , V_8 , V_86 ) ;
V_2 -> V_100 . V_2 = V_2 -> V_11 ;
V_2 -> V_100 . V_154 = F_58 ;
V_2 -> V_100 . V_155 = F_61 ;
V_2 -> V_100 . V_156 = 0x1f ;
V_2 -> V_100 . V_157 = 0x1f ;
V_2 -> V_100 . V_91 = F_43 ( V_2 ) ;
V_173 = F_62 ( V_2 ) ;
F_84 ( L_35 , V_173 ) ;
if ( ( V_58 = F_44 ( V_2 , V_180 ) ) < 0 )
goto V_13;
F_51 ( 150 ) ;
if ( ( V_58 = F_44 ( V_2 , V_182 | V_180 ) ) < 0 )
goto V_13;
F_51 ( 150 ) ;
V_2 -> V_11 -> V_158 = & V_185 ;
V_2 -> V_11 -> V_160 = & V_186 ;
F_61 ( V_2 -> V_11 , V_2 -> V_100 . V_91 , V_162 , V_163 ) ;
F_61 ( V_2 -> V_11 , V_2 -> V_100 . V_91 , V_164 ,
V_165 | V_166 ) ;
F_85 ( & V_2 -> V_100 ) ;
if ( ( V_58 = F_49 ( V_2 , V_168 ) ) < 0 )
goto V_13;
if ( ( V_58 = F_7 ( V_2 , V_187 ,
V_188 | V_189 ,
V_190 , 0 , NULL ) ) < 0 ) {
F_84 ( L_36 , V_58 ) ;
goto V_13;
}
if ( ( V_58 = F_47 ( V_2 , V_75 ) ) < 0 )
goto V_13;
V_74 = F_45 ( V_2 ) ;
F_84 ( L_37 , V_74 ) ;
V_74 = F_48 ( V_2 ) ;
F_84 ( L_38 , V_74 ) ;
if ( V_2 -> V_151 -> V_45 & V_191 ) {
V_2 -> V_192 = 2048 ;
}
return 0 ;
V_13:
return V_58 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
T_2 V_193 ;
F_2 ( V_2 -> V_11 , L_39 ) ;
V_193 = F_58 ( V_2 -> V_11 , V_2 -> V_100 . V_91 , V_194 ) ;
F_2 ( V_2 -> V_11 , L_40 , V_193 ) ;
F_61 ( V_2 -> V_11 , V_2 -> V_100 . V_91 , V_195 ,
V_196 | V_197 ) ;
if ( V_7 -> V_198 ) {
V_193 = F_58 ( V_2 -> V_11 , V_2 -> V_100 . V_91 ,
V_199 ) ;
F_2 ( V_2 -> V_11 , L_41 , V_193 ) ;
V_193 &= 0xf8ff ;
V_193 |= ( 1 + 0x0100 ) ;
F_61 ( V_2 -> V_11 , V_2 -> V_100 . V_91 ,
V_199 , V_193 ) ;
V_193 = F_58 ( V_2 -> V_11 , V_2 -> V_100 . V_91 ,
V_199 ) ;
F_2 ( V_2 -> V_11 , L_42 , V_193 ) ;
V_193 &= 0xfc0f ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , T_2 V_200 )
{
T_2 V_193 = F_58 ( V_2 -> V_11 , V_2 -> V_100 . V_91 , V_201 ) ;
F_2 ( V_2 -> V_11 , L_43 , V_193 ) ;
V_193 &= 0xfc0f ;
switch ( V_200 ) {
case V_202 :
V_193 |= 0x03e0 ;
break;
case V_169 :
V_193 |= 0x03b0 ;
break;
default:
V_193 |= 0x02f0 ;
}
F_2 ( V_2 -> V_11 , L_44 , V_193 ) ;
F_61 ( V_2 -> V_11 , V_2 -> V_100 . V_91 , V_201 , V_193 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
T_2 V_66 ;
struct V_141 V_142 = { . V_3 = V_143 } ;
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
T_3 V_200 ;
F_2 ( V_2 -> V_11 , L_45 ) ;
F_79 ( & V_2 -> V_100 , 1 , 1 ) ;
F_80 ( & V_2 -> V_100 , & V_142 ) ;
V_66 = V_203 ;
V_200 = F_81 ( & V_142 ) ;
if ( V_200 == V_202 )
V_66 |= V_204 ;
else if ( V_200 == V_169 )
V_66 |= V_170 ;
else
V_66 &= ~ ( V_170 | V_204 ) ;
V_66 |= V_205 ;
if ( V_142 . V_145 == V_146 )
V_66 |= V_171 ;
else
V_66 &= ~ V_171 ;
F_2 ( V_2 -> V_11 , L_46 ,
V_200 , V_142 . V_145 , V_66 ) ;
F_49 ( V_2 , V_66 ) ;
if ( V_7 -> V_206 == V_207 && V_7 -> V_198 )
F_89 ( V_2 , V_200 ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
T_2 V_208 = V_209 ;
T_2 V_210 ;
T_2 V_211 ;
int V_212 = V_2 -> V_192 ;
if ( V_2 -> V_213 < 2048 ) {
V_2 -> V_192 = 2048 ;
V_208 = V_214 ;
} else if ( V_2 -> V_213 < 4096 ) {
V_2 -> V_192 = 4096 ;
V_208 = V_215 ;
} else if ( V_2 -> V_213 < 8192 ) {
V_2 -> V_192 = 8192 ;
V_208 = V_216 ;
} else if ( V_2 -> V_213 < 16384 ) {
V_2 -> V_192 = 16384 ;
V_208 = V_209 ;
}
V_210 = F_45 ( V_2 ) ;
F_47 ( V_2 , ( V_210 & ~ V_209 ) | V_208 ) ;
V_211 = F_48 ( V_2 ) ;
if ( V_2 -> V_11 -> V_43 > 1500 )
V_211 |= V_217 ;
else
V_211 &= ~ V_217 ;
F_49 ( V_2 , V_211 ) ;
if ( V_2 -> V_192 > V_212 )
F_92 ( V_2 ) ;
}
static int F_93 ( struct V_72 * V_11 , int V_218 )
{
struct V_1 * V_2 = F_53 ( V_11 ) ;
int V_219 = V_218 + V_11 -> V_220 + 4 ;
F_2 ( V_2 -> V_11 , L_47 , V_218 ) ;
if ( V_218 <= 0 || V_219 > 16384 )
return - V_19 ;
if ( ( V_219 % V_2 -> V_221 ) == 0 )
return - V_222 ;
V_11 -> V_43 = V_218 ;
V_2 -> V_213 = V_11 -> V_43 + V_11 -> V_220 ;
F_91 ( V_2 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 , struct V_148 * V_149 )
{
struct V_73 * V_7 = (struct V_73 * ) & V_2 -> V_7 ;
int V_58 ;
T_1 V_8 [ V_86 ] ;
V_62 V_117 ;
T_1 V_26 ;
int V_223 = 0 ;
T_3 V_173 ;
F_83 ( V_2 , V_149 ) ;
F_1 ( V_2 , V_224 , 0 , 0 , 1 , & V_26 ) ;
F_84 ( L_48 , V_26 ) ;
F_7 ( V_2 , V_225 , 0 , 0 , 0 , NULL ) ;
F_1 ( V_2 , V_122 , 0x0017 , 0 , 2 , & V_117 ) ;
F_7 ( V_2 , V_226 , 0 , 0 , 0 , NULL ) ;
F_84 ( L_49 , V_117 ) ;
if ( V_117 == F_16 ( 0xffff ) ) {
V_7 -> V_206 = V_207 ;
V_7 -> V_198 = 0 ;
V_223 = 1 ;
} else {
V_7 -> V_206 = F_46 ( V_117 ) & 7 ;
V_7 -> V_198 = F_46 ( V_117 ) >> 8 ;
V_223 = ( F_46 ( V_117 ) & 0x80 ) ? 0 : 1 ;
}
F_84 ( L_50 , V_223 , V_7 -> V_206 ) ;
F_50 ( V_2 , V_175 | V_227 | V_228 , 40 ) ;
if ( ( F_46 ( V_117 ) >> 8 ) != 1 ) {
F_50 ( V_2 , 0x003c , 30 ) ;
F_50 ( V_2 , 0x001c , 300 ) ;
F_50 ( V_2 , 0x003c , 30 ) ;
} else {
F_84 ( L_51 ) ;
F_50 ( V_2 , V_228 , 30 ) ;
F_50 ( V_2 , V_228 | V_227 , 30 ) ;
}
F_44 ( V_2 , 0 ) ;
F_51 ( 150 ) ;
F_44 ( V_2 , V_180 | V_179 ) ;
F_51 ( 150 ) ;
F_47 ( V_2 , 0 ) ;
if ( ( V_58 = F_1 ( V_2 , V_184 ,
0 , 0 , V_86 , V_8 ) ) < 0 ) {
F_84 ( L_34 , V_58 ) ;
goto V_13;
}
memcpy ( V_2 -> V_11 -> V_138 , V_8 , V_86 ) ;
V_2 -> V_100 . V_2 = V_2 -> V_11 ;
V_2 -> V_100 . V_154 = F_58 ;
V_2 -> V_100 . V_155 = F_61 ;
V_2 -> V_100 . V_156 = 0x1f ;
V_2 -> V_100 . V_157 = 0xff ;
V_2 -> V_100 . V_229 = 1 ;
V_2 -> V_100 . V_91 = F_43 ( V_2 ) ;
V_2 -> V_11 -> V_158 = & V_230 ;
V_2 -> V_11 -> V_160 = & V_231 ;
V_173 = F_62 ( V_2 ) ;
F_84 ( L_35 , V_173 ) ;
if ( V_7 -> V_206 == V_207 ) {
F_88 ( V_2 ) ;
F_51 ( 60 ) ;
}
F_61 ( V_2 -> V_11 , V_2 -> V_100 . V_91 , V_162 ,
V_163 | V_232 ) ;
F_61 ( V_2 -> V_11 , V_2 -> V_100 . V_91 , V_164 ,
V_165 | V_166 | V_167 ) ;
F_61 ( V_2 -> V_11 , V_2 -> V_100 . V_91 , V_233 ,
V_234 ) ;
F_85 ( & V_2 -> V_100 ) ;
if ( ( V_58 = F_49 ( V_2 , V_203 ) ) < 0 )
goto V_13;
if ( ( V_58 = F_47 ( V_2 , V_75 ) ) < 0 )
goto V_13;
if ( V_2 -> V_151 -> V_45 & V_191 ) {
V_2 -> V_192 = 2048 ;
}
return 0 ;
V_13:
return V_58 ;
}
static int T_5 F_95 ( void )
{
return F_96 ( & V_235 ) ;
}
static void T_6 F_97 ( void )
{
F_98 ( & V_235 ) ;
}
