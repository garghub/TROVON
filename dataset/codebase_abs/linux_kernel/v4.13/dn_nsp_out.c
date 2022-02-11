static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
F_3 ( V_2 ) ;
V_6 -> V_11 = V_12 ;
V_8 = F_4 ( V_4 , 0 ) ;
if ( V_8 ) {
V_13:
F_5 ( V_2 , V_8 ) ;
F_6 ( & V_14 , V_2 -> V_4 , V_2 ) ;
return;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_15 = V_4 -> V_16 ;
V_10 . V_17 = F_7 ( & V_6 -> V_18 ) ;
V_10 . V_19 = F_7 ( & V_6 -> V_20 ) ;
F_8 ( & V_10 , V_6 ) ;
V_10 . V_21 = V_22 ;
if ( F_9 ( & V_4 -> V_23 , & V_10 , V_4 , 0 ) == 0 ) {
V_8 = F_10 ( V_4 ) ;
V_4 -> V_24 = V_8 -> V_25 -> V_26 ;
goto V_13;
}
V_4 -> V_27 = V_28 ;
if ( ! F_11 ( V_4 , V_29 ) )
V_4 -> V_30 ( V_4 ) ;
}
struct V_1 * F_12 ( struct V_3 * V_4 , int V_31 , T_1 V_32 )
{
struct V_1 * V_2 ;
int V_33 = 64 ;
if ( ( V_2 = F_13 ( V_31 + V_33 , V_32 ) ) == NULL )
return NULL ;
V_2 -> V_34 = F_14 ( V_35 ) ;
V_2 -> V_36 = V_37 ;
if ( V_4 )
F_15 ( V_2 , V_4 ) ;
F_16 ( V_2 , V_33 ) ;
return V_2 ;
}
unsigned long F_17 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned long V_38 = ( ( V_6 -> V_39 >> 2 ) + V_6 -> V_40 ) >> 1 ;
V_38 *= V_41 [ V_6 -> V_42 ] ;
if ( V_38 < V_43 ) V_38 = V_43 ;
if ( V_38 > ( 600 * V_43 ) ) V_38 = ( 600 * V_43 ) ;
if ( V_6 -> V_42 < V_44 )
V_6 -> V_42 ++ ;
return V_38 ;
}
static void F_18 ( struct V_3 * V_4 , long V_45 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
long V_46 = ( long ) V_6 -> V_39 ;
long V_47 = ( long ) V_6 -> V_40 ;
long V_48 ;
if ( V_45 < 0 )
V_45 = - V_45 ;
V_48 = ( ( V_45 << 3 ) - V_46 ) ;
V_46 += ( V_48 >> 3 ) ;
if ( V_46 >= 1 )
V_6 -> V_39 = ( unsigned long ) V_46 ;
else
V_6 -> V_39 = 1 ;
V_48 >>= 1 ;
V_47 += ( ( ( ( V_48 > 0 ) ? ( V_48 ) : ( - V_48 ) ) - V_47 ) >> 2 ) ;
if ( V_47 >= 1 )
V_6 -> V_40 = ( unsigned long ) V_47 ;
else
V_6 -> V_40 = 1 ;
}
static inline unsigned int F_19 ( struct V_1 * V_2 ,
T_1 V_49 )
{
struct V_50 * V_51 = F_20 ( V_2 ) ;
struct V_1 * V_52 ;
int V_53 = 0 ;
if ( ( V_52 = F_21 ( V_2 , V_49 ) ) != NULL ) {
V_53 = V_51 -> V_54 ;
V_51 -> V_54 ++ ;
V_51 -> V_11 = V_12 ;
V_52 -> V_4 = V_2 -> V_4 ;
F_1 ( V_52 ) ;
}
return V_53 ;
}
void F_22 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 ;
unsigned int V_55 = 0 ;
if ( ( V_2 = F_23 ( & V_6 -> V_56 ) ) != NULL )
V_55 = F_19 ( V_2 , V_57 ) ;
if ( V_55 || ( V_6 -> V_58 != V_59 ) )
goto V_60;
if ( ( V_2 = F_23 ( & V_6 -> V_61 ) ) != NULL )
V_55 = F_19 ( V_2 , V_57 ) ;
V_60:
if ( V_55 ) {
V_6 -> V_62 >>= 1 ;
if ( V_6 -> V_62 < V_63 )
V_6 -> V_62 = V_63 ;
}
}
int F_24 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_22 ( V_4 ) ;
if ( ! F_25 ( & V_6 -> V_61 ) ||
! F_25 ( & V_6 -> V_56 ) )
V_6 -> V_64 = F_17 ( V_4 ) ;
return 0 ;
}
static inline T_2 * F_26 ( struct V_5 * V_6 , struct V_1 * V_2 , unsigned char V_65 , int V_66 )
{
unsigned char * V_67 = F_27 ( V_2 , V_66 ) ;
F_28 ( V_66 < 5 ) ;
* V_67 ++ = V_65 ;
* ( ( T_2 * ) V_67 ) = V_6 -> V_68 ;
V_67 += 2 ;
* ( ( T_2 * ) V_67 ) = V_6 -> V_69 ;
V_67 += 2 ;
return ( T_2 V_70 * ) V_67 ;
}
static T_2 * F_29 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char V_65 , int V_71 , int V_72 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned short V_73 = V_6 -> V_74 & 0x0FFF ;
unsigned short V_75 = V_6 -> V_76 & 0x0FFF ;
T_2 * V_67 ;
F_28 ( V_71 < 9 ) ;
V_6 -> V_77 = V_73 ;
V_6 -> V_78 = V_75 ;
V_73 |= 0x8000 ;
V_75 |= 0x8000 ;
if ( V_72 ) {
unsigned short V_79 = V_73 ;
V_73 = V_75 ;
V_75 = V_79 ;
}
V_75 |= 0x2000 ;
V_67 = F_26 ( V_6 , V_2 , V_65 , V_71 ) ;
* V_67 ++ = F_30 ( V_73 ) ;
* V_67 ++ = F_30 ( V_75 ) ;
return V_67 ;
}
static T_2 * F_31 ( struct V_3 * V_4 , struct V_1 * V_2 , int V_80 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_50 * V_51 = F_20 ( V_2 ) ;
T_2 * V_67 = F_29 ( V_4 , V_2 , V_51 -> V_81 , 11 , V_80 ) ;
if ( F_32 ( V_80 ) ) {
V_51 -> V_82 = V_6 -> V_83 ;
F_33 ( & V_6 -> V_83 , 1 ) ;
} else {
V_51 -> V_82 = V_6 -> V_84 ;
F_33 ( & V_6 -> V_84 , 1 ) ;
}
* ( V_67 ++ ) = F_30 ( V_51 -> V_82 ) ;
return V_67 ;
}
void F_34 ( struct V_3 * V_4 , struct V_1 * V_2 ,
T_1 V_49 , int V_80 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_50 * V_51 = F_20 ( V_2 ) ;
unsigned long V_38 = ( ( V_6 -> V_39 >> 2 ) + V_6 -> V_40 ) >> 1 ;
V_51 -> V_54 = 0 ;
F_31 ( V_4 , V_2 , V_80 ) ;
if ( ( V_12 - V_6 -> V_11 ) > V_38 )
V_6 -> V_62 = V_63 ;
if ( V_80 )
F_35 ( & V_6 -> V_56 , V_2 ) ;
else
F_35 ( & V_6 -> V_61 , V_2 ) ;
if ( V_6 -> V_58 != V_59 )
return;
F_19 ( V_2 , V_49 ) ;
}
int F_36 ( struct V_3 * V_4 , struct V_1 * V_2 , struct V_85 * V_86 , unsigned short V_73 )
{
struct V_50 * V_51 = F_20 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_52 , * V_87 , * V_88 = NULL ;
int V_89 = 0 ;
int V_90 = 0 ;
unsigned long V_91 = V_51 -> V_11 ;
unsigned long V_92 ;
unsigned short V_54 ;
unsigned short V_82 ;
F_37 (q, skb2, n) {
struct V_50 * V_93 = F_20 ( V_52 ) ;
if ( F_38 ( V_93 -> V_82 , V_73 ) )
V_88 = V_52 ;
if ( V_88 == NULL )
continue;
V_90 = 0 ;
V_89 = 1 ;
V_92 = V_93 -> V_11 ;
V_54 = V_93 -> V_54 ;
V_82 = V_93 -> V_82 ;
F_39 ( V_88 , V_86 ) ;
F_40 ( V_88 ) ;
V_88 = NULL ;
F_41 ( V_54 == 0 ) ;
if ( V_54 == 1 ) {
if ( F_42 ( V_82 , V_73 ) )
F_18 ( V_4 , ( long ) ( V_92 - V_91 ) ) ;
if ( V_6 -> V_62 < V_6 -> V_94 )
V_6 -> V_62 ++ ;
}
if ( V_54 > 1 )
V_90 = 1 ;
}
if ( V_90 )
F_22 ( V_4 ) ;
return V_89 ;
}
void F_43 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = NULL ;
if ( ( V_2 = F_12 ( V_4 , 9 , V_57 ) ) == NULL )
return;
F_16 ( V_2 , 9 ) ;
F_29 ( V_4 , V_2 , 0x04 , 9 , 0 ) ;
F_1 ( V_2 ) ;
}
void F_44 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = NULL ;
if ( ( V_2 = F_12 ( V_4 , 9 , V_57 ) ) == NULL )
return;
F_16 ( V_2 , 9 ) ;
F_29 ( V_4 , V_2 , 0x14 , 9 , 1 ) ;
F_1 ( V_2 ) ;
}
void F_45 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 = NULL ;
struct V_95 * V_96 ;
if ( ( V_2 = F_12 ( V_4 , 3 , V_4 -> V_97 ) ) == NULL )
return;
V_96 = F_46 ( V_2 , 3 ) ;
V_96 -> V_98 = 0x24 ;
V_96 -> V_99 = V_6 -> V_68 ;
F_1 ( V_2 ) ;
}
void F_47 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_6 -> V_78 != V_6 -> V_76 )
F_44 ( V_4 ) ;
if ( V_6 -> V_77 != V_6 -> V_74 )
F_43 ( V_4 ) ;
}
static int F_48 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_6 -> V_100 == V_101 )
F_49 ( V_4 , V_57 ) ;
return 0 ;
}
void F_49 ( struct V_3 * V_4 , T_1 V_49 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 = NULL ;
struct V_102 * V_96 ;
T_3 V_66 = ( T_3 ) F_50 ( V_6 -> V_103 . V_104 ) ;
if ( ( V_2 = F_12 ( V_4 , 50 + V_66 , V_49 ) ) == NULL )
return;
V_96 = F_46 ( V_2 , sizeof( * V_96 ) ) ;
V_96 -> V_98 = 0x28 ;
V_96 -> V_99 = V_6 -> V_68 ;
V_96 -> V_105 = V_6 -> V_69 ;
V_96 -> V_106 = V_6 -> V_107 ;
V_96 -> V_108 = V_6 -> V_109 ;
V_96 -> V_110 = F_30 ( V_6 -> V_111 ) ;
F_51 ( V_2 , V_66 ) ;
if ( V_66 > 0 )
F_52 ( V_2 , V_6 -> V_103 . V_112 , V_66 ) ;
F_1 ( V_2 ) ;
V_6 -> V_64 = F_17 ( V_4 ) ;
V_6 -> V_113 = F_48 ;
}
static T_4 void F_53 ( struct V_3 * V_4 , unsigned char V_98 ,
unsigned short V_114 , T_1 V_49 ,
struct V_7 * V_8 ,
int V_115 , unsigned char * V_116 , T_2 V_117 , T_2 V_118 )
{
struct V_1 * V_2 = NULL ;
int V_31 = 7 + V_115 + ( ( V_98 == V_119 ) ? 1 : 0 ) ;
unsigned char * V_96 ;
if ( ( V_8 == NULL ) || ( V_117 == 0 ) ) {
F_54 ( L_1 ,
F_50 ( V_117 ) , V_8 ) ;
return;
}
if ( ( V_2 = F_12 ( V_4 , V_31 , V_49 ) ) == NULL )
return;
V_96 = F_46 ( V_2 , V_31 ) ;
* V_96 ++ = V_98 ;
* ( T_2 * ) V_96 = V_117 ;
V_96 += 2 ;
* ( T_2 * ) V_96 = V_118 ;
V_96 += 2 ;
* ( T_2 * ) V_96 = F_30 ( V_114 ) ;
V_96 += 2 ;
if ( V_98 == V_119 )
* V_96 ++ = V_115 ;
if ( V_115 ) {
memcpy ( V_96 , V_116 , V_115 ) ;
}
F_5 ( V_2 , F_55 ( V_8 ) ) ;
F_6 ( & V_14 , V_2 -> V_4 , V_2 ) ;
}
void F_56 ( struct V_3 * V_4 , unsigned char V_98 ,
unsigned short V_114 , T_1 V_49 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_115 = 0 ;
if ( V_98 == V_119 )
V_115 = F_50 ( V_6 -> V_120 . V_104 ) ;
if ( V_114 == 0 )
V_114 = F_50 ( V_6 -> V_120 . V_121 ) ;
F_53 ( V_4 , V_98 , V_114 , V_49 , F_57 ( V_4 ) , V_115 ,
V_6 -> V_120 . V_112 , V_6 -> V_68 , V_6 -> V_69 ) ;
}
void F_58 ( struct V_1 * V_2 , unsigned char V_98 ,
unsigned short V_114 )
{
struct V_50 * V_51 = F_20 ( V_2 ) ;
int V_115 = 0 ;
T_1 V_49 = V_57 ;
F_53 ( NULL , V_98 , V_114 , V_49 , F_59 ( V_2 ) , V_115 ,
NULL , V_51 -> V_122 , V_51 -> V_123 ) ;
}
void F_60 ( struct V_3 * V_4 , unsigned char V_124 , char V_125 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 ;
unsigned char * V_67 ;
T_1 V_49 = V_57 ;
if ( ( V_2 = F_12 ( V_4 , V_126 + 2 , V_49 ) ) == NULL )
return;
F_16 ( V_2 , V_126 ) ;
V_67 = F_46 ( V_2 , 2 ) ;
F_20 ( V_2 ) -> V_81 = 0x10 ;
* V_67 ++ = V_124 ;
* V_67 = V_125 ;
F_34 ( V_4 , V_2 , V_49 , 1 ) ;
V_6 -> V_64 = F_17 ( V_4 ) ;
V_6 -> V_113 = F_24 ;
}
static int F_61 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_6 -> V_100 == V_127 )
F_62 ( V_4 , V_128 ) ;
return 0 ;
}
void F_62 ( struct V_3 * V_4 , unsigned char V_98 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_102 * V_96 ;
unsigned char V_129 ;
unsigned char V_130 ;
struct V_50 * V_51 ;
unsigned char type = 1 ;
T_1 V_131 = ( V_98 == V_132 ) ? V_4 -> V_97 : V_57 ;
struct V_1 * V_2 = F_12 ( V_4 , 200 , V_131 ) ;
if ( ! V_2 )
return;
V_51 = F_20 ( V_2 ) ;
V_96 = F_46 ( V_2 , sizeof( * V_96 ) ) ;
V_96 -> V_98 = V_98 ;
V_96 -> V_99 = 0x0000 ;
V_96 -> V_105 = V_6 -> V_69 ;
V_96 -> V_106 = V_6 -> V_107 ;
V_96 -> V_108 = V_6 -> V_109 ;
V_96 -> V_110 = F_30 ( V_6 -> V_111 ) ;
if ( V_6 -> V_20 . V_133 )
type = 0 ;
F_46 ( V_2 , F_63 ( & V_6 -> V_20 ,
F_64 ( V_2 ) , type ) ) ;
F_46 ( V_2 , F_63 ( & V_6 -> V_18 ,
F_64 ( V_2 ) , 2 ) ) ;
V_130 = V_134 | V_135 ;
if ( V_6 -> V_20 . V_136 & V_137 )
V_130 |= V_138 ;
if ( V_6 -> V_20 . V_136 & V_139 )
V_130 |= V_140 ;
F_51 ( V_2 , V_130 ) ;
V_129 = V_6 -> V_141 . V_142 ;
F_51 ( V_2 , V_129 ) ;
if ( V_129 > 0 )
F_52 ( V_2 , V_6 -> V_141 . V_143 , V_129 ) ;
V_129 = V_6 -> V_141 . V_144 ;
F_51 ( V_2 , V_129 ) ;
if ( V_129 > 0 )
F_52 ( V_2 , V_6 -> V_141 . V_145 , V_129 ) ;
V_129 = V_6 -> V_141 . V_146 ;
F_51 ( V_2 , V_129 ) ;
if ( V_129 > 0 )
F_52 ( V_2 , V_6 -> V_141 . V_147 , V_129 ) ;
V_129 = ( T_3 ) F_50 ( V_6 -> V_103 . V_104 ) ;
F_51 ( V_2 , V_129 ) ;
if ( V_129 > 0 )
F_52 ( V_2 , V_6 -> V_103 . V_112 , V_129 ) ;
V_6 -> V_64 = F_17 ( V_4 ) ;
V_6 -> V_113 = F_61 ;
V_51 -> V_148 = V_149 ;
F_1 ( V_2 ) ;
}
