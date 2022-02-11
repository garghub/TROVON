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
F_6 ( V_2 ) ;
return;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_14 = V_4 -> V_15 ;
V_10 . V_16 = F_7 ( & V_6 -> V_17 ) ;
V_10 . V_18 = F_7 ( & V_6 -> V_19 ) ;
F_8 ( & V_10 , V_6 ) ;
V_10 . V_20 = V_21 ;
if ( F_9 ( & V_4 -> V_22 , & V_10 , V_4 , 0 ) == 0 ) {
V_8 = F_10 ( V_4 ) ;
V_4 -> V_23 = V_8 -> V_24 -> V_25 ;
goto V_13;
}
V_4 -> V_26 = V_27 ;
if ( ! F_11 ( V_4 , V_28 ) )
V_4 -> V_29 ( V_4 ) ;
}
struct V_1 * F_12 ( struct V_3 * V_4 , int V_30 , T_1 V_31 )
{
struct V_1 * V_2 ;
int V_32 = 64 ;
if ( ( V_2 = F_13 ( V_30 + V_32 , V_31 ) ) == NULL )
return NULL ;
V_2 -> V_33 = F_14 ( V_34 ) ;
V_2 -> V_35 = V_36 ;
if ( V_4 )
F_15 ( V_2 , V_4 ) ;
F_16 ( V_2 , V_32 ) ;
return V_2 ;
}
unsigned long F_17 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned long V_37 = ( ( V_6 -> V_38 >> 2 ) + V_6 -> V_39 ) >> 1 ;
V_37 *= V_40 [ V_6 -> V_41 ] ;
if ( V_37 < V_42 ) V_37 = V_42 ;
if ( V_37 > ( 600 * V_42 ) ) V_37 = ( 600 * V_42 ) ;
if ( V_6 -> V_41 < V_43 )
V_6 -> V_41 ++ ;
return V_37 ;
}
static void F_18 ( struct V_3 * V_4 , long V_44 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
long V_45 = ( long ) V_6 -> V_38 ;
long V_46 = ( long ) V_6 -> V_39 ;
long V_47 ;
if ( V_44 < 0 )
V_44 = - V_44 ;
V_47 = ( ( V_44 << 3 ) - V_45 ) ;
V_45 += ( V_47 >> 3 ) ;
if ( V_45 >= 1 )
V_6 -> V_38 = ( unsigned long ) V_45 ;
else
V_6 -> V_38 = 1 ;
V_47 >>= 1 ;
V_46 += ( ( ( ( V_47 > 0 ) ? ( V_47 ) : ( - V_47 ) ) - V_46 ) >> 2 ) ;
if ( V_46 >= 1 )
V_6 -> V_39 = ( unsigned long ) V_46 ;
else
V_6 -> V_39 = 1 ;
}
static inline unsigned int F_19 ( struct V_1 * V_2 ,
T_1 V_48 )
{
struct V_49 * V_50 = F_20 ( V_2 ) ;
struct V_1 * V_51 ;
int V_52 = 0 ;
if ( ( V_51 = F_21 ( V_2 , V_48 ) ) != NULL ) {
V_52 = V_50 -> V_53 ;
V_50 -> V_53 ++ ;
V_50 -> V_11 = V_12 ;
V_51 -> V_4 = V_2 -> V_4 ;
F_1 ( V_51 ) ;
}
return V_52 ;
}
void F_22 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 ;
unsigned int V_54 = 0 ;
if ( ( V_2 = F_23 ( & V_6 -> V_55 ) ) != NULL )
V_54 = F_19 ( V_2 , V_56 ) ;
if ( V_54 || ( V_6 -> V_57 != V_58 ) )
goto V_59;
if ( ( V_2 = F_23 ( & V_6 -> V_60 ) ) != NULL )
V_54 = F_19 ( V_2 , V_56 ) ;
V_59:
if ( V_54 ) {
V_6 -> V_61 >>= 1 ;
if ( V_6 -> V_61 < V_62 )
V_6 -> V_61 = V_62 ;
}
}
int F_24 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_22 ( V_4 ) ;
if ( ! F_25 ( & V_6 -> V_60 ) ||
! F_25 ( & V_6 -> V_55 ) )
V_6 -> V_63 = F_17 ( V_4 ) ;
return 0 ;
}
static inline T_2 * F_26 ( struct V_5 * V_6 , struct V_1 * V_2 , unsigned char V_64 , int V_65 )
{
unsigned char * V_66 = F_27 ( V_2 , V_65 ) ;
F_28 ( V_65 < 5 ) ;
* V_66 ++ = V_64 ;
* ( ( T_2 * ) V_66 ) = V_6 -> V_67 ;
V_66 += 2 ;
* ( ( T_2 * ) V_66 ) = V_6 -> V_68 ;
V_66 += 2 ;
return ( T_2 V_69 * ) V_66 ;
}
static T_2 * F_29 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char V_64 , int V_70 , int V_71 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned short V_72 = V_6 -> V_73 & 0x0FFF ;
unsigned short V_74 = V_6 -> V_75 & 0x0FFF ;
T_2 * V_66 ;
F_28 ( V_70 < 9 ) ;
V_6 -> V_76 = V_72 ;
V_6 -> V_77 = V_74 ;
V_72 |= 0x8000 ;
V_74 |= 0x8000 ;
if ( V_71 ) {
unsigned short V_78 = V_72 ;
V_72 = V_74 ;
V_74 = V_78 ;
}
V_74 |= 0x2000 ;
V_66 = F_26 ( V_6 , V_2 , V_64 , V_70 ) ;
* V_66 ++ = F_30 ( V_72 ) ;
* V_66 ++ = F_30 ( V_74 ) ;
return V_66 ;
}
static T_2 * F_31 ( struct V_3 * V_4 , struct V_1 * V_2 , int V_79 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_49 * V_50 = F_20 ( V_2 ) ;
T_2 * V_66 = F_29 ( V_4 , V_2 , V_50 -> V_80 , 11 , V_79 ) ;
if ( F_32 ( V_79 ) ) {
V_50 -> V_81 = V_6 -> V_82 ;
F_33 ( & V_6 -> V_82 , 1 ) ;
} else {
V_50 -> V_81 = V_6 -> V_83 ;
F_33 ( & V_6 -> V_83 , 1 ) ;
}
* ( V_66 ++ ) = F_30 ( V_50 -> V_81 ) ;
return V_66 ;
}
void F_34 ( struct V_3 * V_4 , struct V_1 * V_2 ,
T_1 V_48 , int V_79 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_49 * V_50 = F_20 ( V_2 ) ;
unsigned long V_37 = ( ( V_6 -> V_38 >> 2 ) + V_6 -> V_39 ) >> 1 ;
V_50 -> V_53 = 0 ;
F_31 ( V_4 , V_2 , V_79 ) ;
if ( ( V_12 - V_6 -> V_11 ) > V_37 )
V_6 -> V_61 = V_62 ;
if ( V_79 )
F_35 ( & V_6 -> V_55 , V_2 ) ;
else
F_35 ( & V_6 -> V_60 , V_2 ) ;
if ( V_6 -> V_57 != V_58 )
return;
F_19 ( V_2 , V_48 ) ;
}
int F_36 ( struct V_3 * V_4 , struct V_1 * V_2 , struct V_84 * V_85 , unsigned short V_72 )
{
struct V_49 * V_50 = F_20 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_51 , * V_86 , * V_87 = NULL ;
int V_88 = 0 ;
int V_89 = 0 ;
unsigned long V_90 = V_50 -> V_11 ;
unsigned long V_91 ;
unsigned short V_53 ;
unsigned short V_81 ;
F_37 (q, skb2, n) {
struct V_49 * V_92 = F_20 ( V_51 ) ;
if ( F_38 ( V_92 -> V_81 , V_72 ) )
V_87 = V_51 ;
if ( V_87 == NULL )
continue;
V_89 = 0 ;
V_88 = 1 ;
V_91 = V_92 -> V_11 ;
V_53 = V_92 -> V_53 ;
V_81 = V_92 -> V_81 ;
F_39 ( V_87 , V_85 ) ;
F_40 ( V_87 ) ;
V_87 = NULL ;
F_41 ( V_53 == 0 ) ;
if ( V_53 == 1 ) {
if ( F_42 ( V_81 , V_72 ) )
F_18 ( V_4 , ( long ) ( V_91 - V_90 ) ) ;
if ( V_6 -> V_61 < V_6 -> V_93 )
V_6 -> V_61 ++ ;
}
if ( V_53 > 1 )
V_89 = 1 ;
}
if ( V_89 )
F_22 ( V_4 ) ;
return V_88 ;
}
void F_43 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = NULL ;
if ( ( V_2 = F_12 ( V_4 , 9 , V_56 ) ) == NULL )
return;
F_16 ( V_2 , 9 ) ;
F_29 ( V_4 , V_2 , 0x04 , 9 , 0 ) ;
F_1 ( V_2 ) ;
}
void F_44 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = NULL ;
if ( ( V_2 = F_12 ( V_4 , 9 , V_56 ) ) == NULL )
return;
F_16 ( V_2 , 9 ) ;
F_29 ( V_4 , V_2 , 0x14 , 9 , 1 ) ;
F_1 ( V_2 ) ;
}
void F_45 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 = NULL ;
struct V_94 * V_95 ;
if ( ( V_2 = F_12 ( V_4 , 3 , V_4 -> V_96 ) ) == NULL )
return;
V_95 = (struct V_94 * ) F_46 ( V_2 , 3 ) ;
V_95 -> V_97 = 0x24 ;
V_95 -> V_98 = V_6 -> V_67 ;
F_1 ( V_2 ) ;
}
void F_47 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_6 -> V_77 != V_6 -> V_75 )
F_44 ( V_4 ) ;
if ( V_6 -> V_76 != V_6 -> V_73 )
F_43 ( V_4 ) ;
}
static int F_48 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_6 -> V_99 == V_100 )
F_49 ( V_4 , V_56 ) ;
return 0 ;
}
void F_49 ( struct V_3 * V_4 , T_1 V_48 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 = NULL ;
struct V_101 * V_95 ;
T_3 V_65 = ( T_3 ) F_50 ( V_6 -> V_102 . V_103 ) ;
if ( ( V_2 = F_12 ( V_4 , 50 + V_65 , V_48 ) ) == NULL )
return;
V_95 = (struct V_101 * ) F_46 ( V_2 , sizeof( * V_95 ) ) ;
V_95 -> V_97 = 0x28 ;
V_95 -> V_98 = V_6 -> V_67 ;
V_95 -> V_104 = V_6 -> V_68 ;
V_95 -> V_105 = V_6 -> V_106 ;
V_95 -> V_107 = V_6 -> V_108 ;
V_95 -> V_109 = F_30 ( V_6 -> V_110 ) ;
* F_46 ( V_2 , 1 ) = V_65 ;
if ( V_65 > 0 )
memcpy ( F_46 ( V_2 , V_65 ) , V_6 -> V_102 . V_111 , V_65 ) ;
F_1 ( V_2 ) ;
V_6 -> V_63 = F_17 ( V_4 ) ;
V_6 -> V_112 = F_48 ;
}
static T_4 void F_51 ( struct V_3 * V_4 , unsigned char V_97 ,
unsigned short V_113 , T_1 V_48 ,
struct V_7 * V_8 ,
int V_114 , unsigned char * V_115 , T_2 V_116 , T_2 V_117 )
{
struct V_1 * V_2 = NULL ;
int V_30 = 7 + V_114 + ( ( V_97 == V_118 ) ? 1 : 0 ) ;
unsigned char * V_95 ;
if ( ( V_8 == NULL ) || ( V_116 == 0 ) ) {
F_52 ( L_1 ,
F_50 ( V_116 ) , V_8 ) ;
return;
}
if ( ( V_2 = F_12 ( V_4 , V_30 , V_48 ) ) == NULL )
return;
V_95 = F_46 ( V_2 , V_30 ) ;
* V_95 ++ = V_97 ;
* ( T_2 * ) V_95 = V_116 ;
V_95 += 2 ;
* ( T_2 * ) V_95 = V_117 ;
V_95 += 2 ;
* ( T_2 * ) V_95 = F_30 ( V_113 ) ;
V_95 += 2 ;
if ( V_97 == V_118 )
* V_95 ++ = V_114 ;
if ( V_114 ) {
memcpy ( V_95 , V_115 , V_114 ) ;
}
F_5 ( V_2 , F_53 ( V_8 ) ) ;
F_6 ( V_2 ) ;
}
void F_54 ( struct V_3 * V_4 , unsigned char V_97 ,
unsigned short V_113 , T_1 V_48 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_114 = 0 ;
if ( V_97 == V_118 )
V_114 = F_50 ( V_6 -> V_119 . V_103 ) ;
if ( V_113 == 0 )
V_113 = F_50 ( V_6 -> V_119 . V_120 ) ;
F_51 ( V_4 , V_97 , V_113 , V_48 , F_55 ( V_4 ) , V_114 ,
V_6 -> V_119 . V_111 , V_6 -> V_67 , V_6 -> V_68 ) ;
}
void F_56 ( struct V_1 * V_2 , unsigned char V_97 ,
unsigned short V_113 )
{
struct V_49 * V_50 = F_20 ( V_2 ) ;
int V_114 = 0 ;
T_1 V_48 = V_56 ;
F_51 ( NULL , V_97 , V_113 , V_48 , F_57 ( V_2 ) , V_114 ,
NULL , V_50 -> V_121 , V_50 -> V_122 ) ;
}
void F_58 ( struct V_3 * V_4 , unsigned char V_123 , char V_124 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 ;
unsigned char * V_66 ;
T_1 V_48 = V_56 ;
if ( ( V_2 = F_12 ( V_4 , V_125 + 2 , V_48 ) ) == NULL )
return;
F_16 ( V_2 , V_125 ) ;
V_66 = F_46 ( V_2 , 2 ) ;
F_20 ( V_2 ) -> V_80 = 0x10 ;
* V_66 ++ = V_123 ;
* V_66 = V_124 ;
F_34 ( V_4 , V_2 , V_48 , 1 ) ;
V_6 -> V_63 = F_17 ( V_4 ) ;
V_6 -> V_112 = F_24 ;
}
static int F_59 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_6 -> V_99 == V_126 )
F_60 ( V_4 , V_127 ) ;
return 0 ;
}
void F_60 ( struct V_3 * V_4 , unsigned char V_97 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_101 * V_95 ;
unsigned char V_128 ;
unsigned char V_129 ;
struct V_49 * V_50 ;
unsigned char type = 1 ;
T_1 V_130 = ( V_97 == V_131 ) ? V_4 -> V_96 : V_56 ;
struct V_1 * V_2 = F_12 ( V_4 , 200 , V_130 ) ;
if ( ! V_2 )
return;
V_50 = F_20 ( V_2 ) ;
V_95 = (struct V_101 * ) F_46 ( V_2 , sizeof( * V_95 ) ) ;
V_95 -> V_97 = V_97 ;
V_95 -> V_98 = 0x0000 ;
V_95 -> V_104 = V_6 -> V_68 ;
V_95 -> V_105 = V_6 -> V_106 ;
V_95 -> V_107 = V_6 -> V_108 ;
V_95 -> V_109 = F_30 ( V_6 -> V_110 ) ;
if ( V_6 -> V_19 . V_132 )
type = 0 ;
F_46 ( V_2 , F_61 ( & V_6 -> V_19 ,
F_62 ( V_2 ) , type ) ) ;
F_46 ( V_2 , F_61 ( & V_6 -> V_17 ,
F_62 ( V_2 ) , 2 ) ) ;
V_129 = V_133 | V_134 ;
if ( V_6 -> V_19 . V_135 & V_136 )
V_129 |= V_137 ;
if ( V_6 -> V_19 . V_135 & V_138 )
V_129 |= V_139 ;
* F_46 ( V_2 , 1 ) = V_129 ;
V_128 = V_6 -> V_140 . V_141 ;
* F_46 ( V_2 , 1 ) = V_128 ;
if ( V_128 > 0 )
memcpy ( F_46 ( V_2 , V_128 ) , V_6 -> V_140 . V_142 , V_128 ) ;
V_128 = V_6 -> V_140 . V_143 ;
* F_46 ( V_2 , 1 ) = V_128 ;
if ( V_128 > 0 )
memcpy ( F_46 ( V_2 , V_128 ) , V_6 -> V_140 . V_144 , V_128 ) ;
V_128 = V_6 -> V_140 . V_145 ;
* F_46 ( V_2 , 1 ) = V_128 ;
if ( V_128 > 0 )
memcpy ( F_46 ( V_2 , V_128 ) , V_6 -> V_140 . V_146 , V_128 ) ;
V_128 = ( T_3 ) F_50 ( V_6 -> V_102 . V_103 ) ;
* F_46 ( V_2 , 1 ) = V_128 ;
if ( V_128 > 0 )
memcpy ( F_46 ( V_2 , V_128 ) , V_6 -> V_102 . V_111 , V_128 ) ;
V_6 -> V_63 = F_17 ( V_4 ) ;
V_6 -> V_112 = F_59 ;
V_50 -> V_147 = V_148 ;
F_1 ( V_2 ) ;
}
