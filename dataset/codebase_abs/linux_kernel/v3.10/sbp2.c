static void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
F_2 ( V_4 , & V_2 -> V_5 , V_3 ) ;
}
static struct V_6 * F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 -> V_9 ) ;
}
static const struct V_10 * F_5 ( const struct V_7 * V_8 )
{
return & V_8 -> V_9 -> V_10 ;
}
static const struct V_10 * F_6 ( const struct V_1 * V_2 )
{
return & V_2 -> V_8 -> V_9 -> V_10 ;
}
static void F_7 ( struct V_11 * V_11 )
{
struct V_12 * V_13 = F_8 ( V_11 , struct V_12 , V_11 ) ;
F_9 ( V_13 ) ;
}
static void F_10 ( struct V_14 * V_15 , struct V_16 * V_17 ,
int V_18 , int V_19 , int V_20 ,
int V_21 , unsigned long long V_22 ,
void * V_23 , T_1 V_24 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
struct V_12 * V_13 ;
struct V_26 V_27 ;
unsigned long V_28 ;
if ( V_18 != V_29 ||
V_24 < 8 || V_24 > sizeof( V_27 ) ) {
F_11 ( V_15 , V_17 , V_30 ) ;
return;
}
V_27 . V_27 = F_12 ( V_23 ) ;
V_27 . V_31 = F_12 ( V_23 + 4 ) ;
memset ( V_27 . V_32 , 0 , sizeof( V_27 . V_32 ) ) ;
if ( V_24 > 8 )
memcpy ( V_27 . V_32 , V_23 + 8 , V_24 - 8 ) ;
if ( F_13 ( V_27 ) == 2 || F_13 ( V_27 ) == 3 ) {
F_14 ( F_6 ( V_2 ) ,
L_1 ) ;
F_11 ( V_15 , V_17 , V_33 ) ;
return;
}
F_15 ( & V_15 -> V_34 , V_28 ) ;
F_16 (orb, &lu->orb_list, link) {
if ( F_17 ( V_27 ) == 0 &&
F_18 ( V_27 ) == V_13 -> V_35 ) {
V_13 -> V_36 = V_33 ;
F_19 ( & V_13 -> V_37 ) ;
break;
}
}
F_20 ( & V_15 -> V_34 , V_28 ) ;
if ( & V_13 -> V_37 != & V_2 -> V_38 ) {
V_13 -> V_39 ( V_13 , & V_27 ) ;
F_21 ( & V_13 -> V_11 , F_7 ) ;
} else {
F_22 ( F_6 ( V_2 ) , L_2 ) ;
}
F_11 ( V_15 , V_17 , V_33 ) ;
}
static void F_23 ( struct V_14 * V_15 , int V_36 ,
void * V_23 , T_1 V_24 , void * V_32 )
{
struct V_12 * V_13 = V_32 ;
unsigned long V_28 ;
F_15 ( & V_15 -> V_34 , V_28 ) ;
if ( V_13 -> V_36 == - 1 )
V_13 -> V_36 = V_36 ;
if ( V_13 -> V_36 != V_33 ) {
F_19 ( & V_13 -> V_37 ) ;
F_20 ( & V_15 -> V_34 , V_28 ) ;
V_13 -> V_39 ( V_13 , NULL ) ;
F_21 ( & V_13 -> V_11 , F_7 ) ;
} else {
F_20 ( & V_15 -> V_34 , V_28 ) ;
}
F_21 ( & V_13 -> V_11 , F_7 ) ;
}
static void F_24 ( struct V_12 * V_13 , struct V_1 * V_2 ,
int V_40 , int V_21 , T_2 V_22 )
{
struct V_6 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_41 V_42 ;
unsigned long V_28 ;
V_42 . V_43 = 0 ;
V_42 . V_44 = F_25 ( V_13 -> V_35 ) ;
F_15 ( & V_10 -> V_15 -> V_34 , V_28 ) ;
F_26 ( & V_13 -> V_37 , & V_2 -> V_38 ) ;
F_20 ( & V_10 -> V_15 -> V_34 , V_28 ) ;
F_27 ( & V_13 -> V_11 ) ;
F_27 ( & V_13 -> V_11 ) ;
F_28 ( V_10 -> V_15 , & V_13 -> V_45 , V_29 ,
V_40 , V_21 , V_10 -> V_46 , V_22 ,
& V_42 , 8 , F_23 , V_13 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_6 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_12 * V_13 , * V_47 ;
struct V_48 V_49 ;
unsigned long V_28 ;
int V_50 = - V_51 ;
F_30 ( & V_49 ) ;
F_15 ( & V_10 -> V_15 -> V_34 , V_28 ) ;
F_31 ( & V_2 -> V_38 , & V_49 ) ;
F_20 ( & V_10 -> V_15 -> V_34 , V_28 ) ;
F_32 (orb, next, &list, link) {
V_50 = 0 ;
if ( F_33 ( V_10 -> V_15 , & V_13 -> V_45 ) == 0 )
continue;
V_13 -> V_36 = V_52 ;
V_13 -> V_39 ( V_13 , NULL ) ;
F_21 ( & V_13 -> V_11 , F_7 ) ;
}
return V_50 ;
}
static void F_34 ( struct V_12 * V_53 ,
struct V_26 * V_27 )
{
struct V_54 * V_13 =
F_8 ( V_53 , struct V_54 , V_55 ) ;
if ( V_27 )
memcpy ( & V_13 -> V_27 , V_27 , sizeof( * V_27 ) ) ;
F_35 ( & V_13 -> V_56 ) ;
}
static int F_36 ( struct V_1 * V_2 , int V_40 ,
int V_21 , int V_57 ,
int V_58 , void * V_59 )
{
struct V_6 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_54 * V_13 ;
unsigned int V_60 ;
int V_50 = - V_61 ;
if ( V_57 == V_62 && F_37 ( V_10 ) )
return 0 ;
V_13 = F_38 ( sizeof( * V_13 ) , V_63 ) ;
if ( V_13 == NULL )
return - V_61 ;
F_39 ( & V_13 -> V_55 . V_11 ) ;
V_13 -> V_64 =
F_40 ( V_10 -> V_15 -> V_10 , & V_13 -> V_59 ,
sizeof( V_13 -> V_59 ) , V_65 ) ;
if ( F_41 ( V_10 -> V_15 -> V_10 , V_13 -> V_64 ) )
goto V_66;
V_13 -> V_17 . V_59 . V_43 = 0 ;
V_13 -> V_17 . V_59 . V_44 = F_25 ( V_13 -> V_64 ) ;
V_13 -> V_17 . V_67 = F_25 (
V_68 |
F_42 ( V_57 ) |
F_43 ( V_58 ) ) ;
V_13 -> V_17 . V_24 = F_25 (
F_44 ( sizeof( V_13 -> V_59 ) ) ) ;
V_13 -> V_17 . V_69 . V_43 =
F_25 ( V_2 -> V_70 . V_22 >> 32 ) ;
V_13 -> V_17 . V_69 . V_44 =
F_25 ( V_2 -> V_70 . V_22 ) ;
if ( V_57 == V_71 ) {
V_13 -> V_17 . V_67 |= F_25 (
F_45 ( 2 ) |
F_46 ( V_72 ) ) ;
V_60 = V_2 -> V_8 -> V_73 ;
} else {
V_60 = V_74 ;
}
F_47 ( & V_13 -> V_56 ) ;
V_13 -> V_55 . V_39 = F_34 ;
V_13 -> V_55 . V_35 =
F_40 ( V_10 -> V_15 -> V_10 , & V_13 -> V_17 ,
sizeof( V_13 -> V_17 ) , V_75 ) ;
if ( F_41 ( V_10 -> V_15 -> V_10 , V_13 -> V_55 . V_35 ) )
goto V_76;
F_24 ( & V_13 -> V_55 , V_2 , V_40 , V_21 ,
V_2 -> V_8 -> V_77 ) ;
F_48 ( & V_13 -> V_56 , F_49 ( V_60 ) ) ;
V_50 = - V_78 ;
if ( F_29 ( V_2 ) == 0 ) {
F_22 ( F_6 ( V_2 ) , L_3 ,
V_13 -> V_55 . V_36 ) ;
goto V_79;
}
if ( V_13 -> V_55 . V_36 != V_33 ) {
F_22 ( F_6 ( V_2 ) , L_4 ,
V_13 -> V_55 . V_36 ) ;
goto V_79;
}
if ( F_50 ( V_13 -> V_27 ) != 0 ||
F_51 ( V_13 -> V_27 ) != 0 ) {
F_22 ( F_6 ( V_2 ) , L_5 ,
F_50 ( V_13 -> V_27 ) ,
F_51 ( V_13 -> V_27 ) ) ;
goto V_79;
}
V_50 = 0 ;
V_79:
F_52 ( V_10 -> V_15 -> V_10 , V_13 -> V_55 . V_35 ,
sizeof( V_13 -> V_17 ) , V_75 ) ;
V_76:
F_52 ( V_10 -> V_15 -> V_10 , V_13 -> V_64 ,
sizeof( V_13 -> V_59 ) , V_65 ) ;
V_66:
if ( V_59 )
memcpy ( V_59 , V_13 -> V_59 , sizeof( V_13 -> V_59 ) ) ;
F_21 ( & V_13 -> V_55 . V_11 , F_7 ) ;
return V_50 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_6 * V_10 = F_3 ( V_2 -> V_8 ) ;
T_3 V_80 = 0 ;
F_54 ( V_10 -> V_15 , V_81 ,
V_2 -> V_8 -> V_40 , V_2 -> V_21 , V_10 -> V_46 ,
V_2 -> V_82 + V_83 ,
& V_80 , 4 ) ;
}
static void F_55 ( struct V_14 * V_15 ,
int V_36 , void * V_23 , T_1 V_24 , void * V_32 )
{
F_9 ( V_32 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_6 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_84 * V_45 ;
static T_3 V_80 ;
V_45 = F_57 ( sizeof( * V_45 ) , V_85 ) ;
if ( V_45 == NULL )
return;
F_28 ( V_10 -> V_15 , V_45 , V_81 ,
V_2 -> V_8 -> V_40 , V_2 -> V_21 , V_10 -> V_46 ,
V_2 -> V_82 + V_83 ,
& V_80 , 4 , F_55 , V_45 ) ;
}
static inline void F_58 ( struct V_1 * V_2 )
{
-- V_2 -> V_8 -> V_86 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_14 * V_15 = F_3 ( V_8 ) -> V_15 ;
struct V_87 * V_88 =
F_8 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
unsigned long V_28 ;
F_15 ( & V_15 -> V_34 , V_28 ) ;
if ( ! V_8 -> V_86 && ! V_2 -> V_90 &&
V_2 -> V_21 != V_15 -> V_21 ) {
V_2 -> V_90 = true ;
if ( ++ V_8 -> V_90 == 1 )
F_60 ( V_88 ) ;
}
F_20 ( & V_15 -> V_34 , V_28 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_14 * V_15 = F_3 ( V_8 ) -> V_15 ;
struct V_87 * V_88 =
F_8 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
unsigned long V_28 ;
bool V_91 = false ;
F_15 ( & V_15 -> V_34 , V_28 ) ;
if ( V_2 -> V_90 && V_2 -> V_21 == V_15 -> V_21 ) {
V_2 -> V_90 = false ;
V_91 = -- V_8 -> V_90 == 0 ;
}
F_20 ( & V_15 -> V_34 , V_28 ) ;
if ( V_91 )
F_62 ( V_88 ) ;
}
static void F_63 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = F_3 ( V_8 ) -> V_15 ;
struct V_87 * V_88 =
F_8 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
unsigned long V_28 ;
F_15 ( & V_15 -> V_34 , V_28 ) ;
++ V_8 -> V_86 ;
F_20 ( & V_15 -> V_34 , V_28 ) ;
F_62 ( V_88 ) ;
}
static int F_64 ( T_4 V_92 )
{
struct V_93 V_94 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_93 [ 0 ] = ( V_92 >> 8 ) & 0xff ;
V_94 . V_93 [ 1 ] = V_92 & 0xff ;
return F_65 ( & V_94 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_6 * V_10 = F_3 ( V_2 -> V_8 ) ;
T_3 V_80 = F_25 ( V_95 | V_96 ) ;
F_54 ( V_10 -> V_15 , V_81 ,
V_2 -> V_8 -> V_40 , V_2 -> V_21 , V_10 -> V_46 ,
V_97 + V_98 , & V_80 , 4 ) ;
}
static void F_67 ( struct V_99 * V_5 )
{
struct V_1 * V_2 =
F_8 ( V_5 , struct V_1 , V_5 . V_5 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_6 * V_10 = F_3 ( V_8 ) ;
struct V_87 * V_88 ;
struct V_100 * V_101 ;
struct V_102 V_59 ;
int V_21 , V_40 , V_103 ;
if ( F_37 ( V_10 ) )
return;
V_21 = V_10 -> V_21 ;
F_68 () ;
V_40 = V_10 -> V_40 ;
V_103 = V_10 -> V_15 -> V_40 ;
if ( V_2 -> V_104 )
F_36 ( V_2 , V_10 -> V_40 , V_21 ,
V_62 , V_2 -> V_105 , NULL ) ;
if ( F_36 ( V_2 , V_40 , V_21 ,
V_71 , V_2 -> V_92 , & V_59 ) < 0 ) {
if ( V_2 -> V_106 ++ < 5 ) {
F_1 ( V_2 , F_69 ( V_107 , 5 ) ) ;
} else {
F_22 ( F_5 ( V_8 ) , L_6 ,
V_2 -> V_92 ) ;
F_63 ( V_2 -> V_8 ) ;
}
return;
}
V_8 -> V_40 = V_40 ;
V_8 -> V_108 = V_103 << 16 ;
F_70 () ;
V_2 -> V_21 = V_21 ;
V_2 -> V_82 =
( ( T_2 ) ( F_71 ( V_59 . V_109 . V_43 ) & 0xffff )
<< 32 ) | F_71 ( V_59 . V_109 . V_44 ) ;
V_2 -> V_105 = F_71 ( V_59 . V_67 ) & 0xffff ;
F_14 ( F_5 ( V_8 ) , L_7 ,
V_2 -> V_92 , V_2 -> V_106 ) ;
F_66 ( V_2 ) ;
F_72 ( & V_2 -> V_5 , V_110 ) ;
F_53 ( V_2 ) ;
if ( V_2 -> V_104 ) {
F_29 ( V_2 ) ;
F_61 ( V_2 ) ;
return;
}
if ( V_2 -> V_8 -> V_111 & V_112 )
F_73 ( V_113 ) ;
V_88 = F_8 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
V_101 = F_74 ( V_88 , 0 , 0 , F_64 ( V_2 -> V_92 ) , V_2 ) ;
if ( F_75 ( V_101 ) )
goto V_114;
F_68 () ;
if ( V_21 != V_10 -> V_15 -> V_21 ) {
F_76 ( V_101 ) ;
F_77 ( V_101 ) ;
goto V_114;
}
V_2 -> V_104 = true ;
F_77 ( V_101 ) ;
F_58 ( V_2 ) ;
return;
V_114:
F_68 () ;
V_21 = V_10 -> V_21 ;
F_68 () ;
F_36 ( V_2 , V_10 -> V_40 , V_21 ,
V_62 , V_2 -> V_105 , NULL ) ;
F_72 ( & V_2 -> V_5 , F_67 ) ;
}
static void V_110 ( struct V_99 * V_5 )
{
struct V_1 * V_2 =
F_8 ( V_5 , struct V_1 , V_5 . V_5 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_6 * V_10 = F_3 ( V_8 ) ;
int V_21 , V_40 , V_103 ;
if ( F_37 ( V_10 ) )
return;
V_21 = V_10 -> V_21 ;
F_68 () ;
V_40 = V_10 -> V_40 ;
V_103 = V_10 -> V_15 -> V_40 ;
if ( F_36 ( V_2 , V_40 , V_21 ,
V_115 ,
V_2 -> V_105 , NULL ) < 0 ) {
F_68 () ;
if ( V_21 == V_10 -> V_15 -> V_21 ||
V_2 -> V_106 ++ >= 5 ) {
F_22 ( F_5 ( V_8 ) , L_8 ) ;
V_2 -> V_106 = 0 ;
F_72 ( & V_2 -> V_5 , F_67 ) ;
}
F_1 ( V_2 , F_69 ( V_107 , 5 ) ) ;
return;
}
V_8 -> V_40 = V_40 ;
V_8 -> V_108 = V_103 << 16 ;
F_70 () ;
V_2 -> V_21 = V_21 ;
F_14 ( F_5 ( V_8 ) , L_9 ,
V_2 -> V_92 , V_2 -> V_106 ) ;
F_53 ( V_2 ) ;
F_29 ( V_2 ) ;
F_61 ( V_2 ) ;
}
static int F_78 ( struct V_7 * V_8 , int V_116 )
{
struct V_1 * V_2 ;
V_2 = F_57 ( sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 )
return - V_61 ;
V_2 -> V_70 . V_24 = 0x100 ;
V_2 -> V_70 . V_118 = F_10 ;
V_2 -> V_70 . V_25 = V_2 ;
if ( F_79 ( & V_2 -> V_70 ,
& V_119 ) < 0 ) {
F_9 ( V_2 ) ;
return - V_61 ;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_92 = V_116 & 0xffff ;
V_2 -> V_105 = V_120 ;
V_2 -> V_106 = 0 ;
V_2 -> V_104 = false ;
V_2 -> V_90 = false ;
++ V_8 -> V_86 ;
F_30 ( & V_2 -> V_38 ) ;
F_80 ( & V_2 -> V_5 , F_67 ) ;
F_26 ( & V_2 -> V_37 , & V_8 -> V_121 ) ;
return 0 ;
}
static void F_81 ( struct V_7 * V_8 ,
const T_5 * V_122 )
{
if ( ( V_122 [ 0 ] & 0xffff0000 ) == 0x00020000 )
V_8 -> V_123 = ( T_2 ) V_122 [ 1 ] << 32 | V_122 [ 2 ] ;
}
static int F_82 ( struct V_7 * V_8 ,
const T_5 * V_124 )
{
struct V_125 V_126 ;
int V_127 , V_128 ;
F_83 ( & V_126 , V_124 ) ;
while ( F_84 ( & V_126 , & V_127 , & V_128 ) )
if ( V_127 == V_129 &&
F_78 ( V_8 , V_128 ) < 0 )
return - V_61 ;
return 0 ;
}
static int F_85 ( struct V_7 * V_8 , const T_5 * V_124 ,
T_5 * V_130 , T_5 * V_131 )
{
struct V_125 V_126 ;
int V_127 , V_128 ;
F_83 ( & V_126 , V_124 ) ;
while ( F_84 ( & V_126 , & V_127 , & V_128 ) ) {
switch ( V_127 ) {
case V_132 | V_133 :
V_8 -> V_77 =
V_97 + 4 * V_128 ;
break;
case V_134 :
V_8 -> V_135 = V_128 ;
break;
case V_136 :
* V_130 = V_128 ;
break;
case V_137 :
* V_131 = V_128 ;
break;
case V_138 :
V_8 -> V_73 = ( V_128 >> 8 & 0xff ) * 500 ;
break;
case V_129 :
if ( F_78 ( V_8 , V_128 ) < 0 )
return - V_61 ;
break;
case V_139 :
F_81 ( V_8 , V_126 . V_140 - 1 + V_128 ) ;
break;
case V_141 :
if ( F_82 ( V_8 , V_126 . V_140 - 1 + V_128 ) < 0 )
return - V_61 ;
break;
}
}
return 0 ;
}
static void F_86 ( struct V_7 * V_8 )
{
unsigned int V_60 = V_8 -> V_73 ;
if ( V_60 > 40000 )
F_14 ( F_5 ( V_8 ) , L_10 ,
V_60 / 1000 ) ;
V_8 -> V_73 = F_87 ( V_60 , 5000 , 40000 ) ;
}
static void F_88 ( struct V_7 * V_8 , T_5 V_130 ,
T_5 V_131 )
{
int V_142 ;
unsigned int V_143 = V_144 ;
if ( V_143 )
F_14 ( F_5 ( V_8 ) ,
L_11
L_12 ) ;
if ( V_143 & V_145 )
goto V_79;
for ( V_142 = 0 ; V_142 < F_89 ( V_146 ) ; V_142 ++ ) {
if ( V_146 [ V_142 ] . V_131 !=
( V_131 & 0xffffff00 ) )
continue;
if ( V_146 [ V_142 ] . V_130 != V_130 &&
V_146 [ V_142 ] . V_130 != V_147 )
continue;
V_143 |= V_146 [ V_142 ] . V_111 ;
break;
}
V_79:
if ( V_143 )
F_14 ( F_5 ( V_8 ) , L_13
L_14 ,
V_143 , V_131 , V_130 ) ;
V_8 -> V_111 = V_143 ;
}
static int F_90 ( struct V_10 * V_148 )
{
struct V_149 * V_9 = V_149 ( V_148 ) ;
struct V_6 * V_10 = F_4 ( V_9 ) ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_87 * V_88 ;
T_5 V_130 , V_131 ;
if ( V_10 -> V_150 )
return - V_151 ;
if ( F_91 ( V_10 -> V_15 -> V_10 ) > V_152 )
F_92 ( F_93 ( V_10 -> V_15 -> V_10 ,
V_152 ) ) ;
V_88 = F_94 ( & V_153 , sizeof( * V_8 ) ) ;
if ( V_88 == NULL )
return - V_61 ;
V_8 = (struct V_7 * ) V_88 -> V_89 ;
F_95 ( & V_9 -> V_10 , V_8 ) ;
V_8 -> V_9 = V_9 ;
F_30 ( & V_8 -> V_121 ) ;
V_8 -> V_123 = ( T_2 ) V_10 -> V_154 [ 3 ] << 32 | V_10 -> V_154 [ 4 ] ;
if ( F_96 ( V_10 ) < 0 )
goto V_155;
V_88 -> V_156 = V_157 ;
if ( F_97 ( V_88 , & V_9 -> V_10 ,
V_10 -> V_15 -> V_10 ) < 0 )
goto V_155;
V_8 -> V_135 = ( ( V_9 -> V_124 - V_10 -> V_154 ) * 4
+ V_158 ) & 0xffffff ;
V_131 = V_159 ;
V_130 = V_159 ;
if ( F_85 ( V_8 , V_9 -> V_124 , & V_130 ,
& V_131 ) < 0 )
goto V_160;
F_86 ( V_8 ) ;
F_88 ( V_8 , V_130 , V_131 ) ;
V_8 -> V_161 = F_98 ( V_10 -> V_46 + 7 , 10U ,
V_10 -> V_15 -> V_162 - 1 ) ;
F_16 (lu, &tgt->lu_list, link)
F_1 ( V_2 , F_69 ( V_107 , 5 ) ) ;
return 0 ;
V_160:
F_99 ( V_148 ) ;
return - V_61 ;
V_155:
F_100 ( V_88 ) ;
return - V_61 ;
}
static void F_101 ( struct V_149 * V_9 )
{
struct V_7 * V_8 = F_102 ( & V_9 -> V_10 ) ;
struct V_1 * V_2 ;
F_96 ( F_4 ( V_9 ) ) ;
F_16 (lu, &tgt->lu_list, link) {
F_59 ( V_2 ) ;
V_2 -> V_106 = 0 ;
F_1 ( V_2 , 0 ) ;
}
}
static int F_99 ( struct V_10 * V_148 )
{
struct V_149 * V_9 = V_149 ( V_148 ) ;
struct V_6 * V_10 = F_4 ( V_9 ) ;
struct V_7 * V_8 = F_102 ( & V_9 -> V_10 ) ;
struct V_1 * V_2 , * V_47 ;
struct V_87 * V_88 =
F_8 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
struct V_100 * V_101 ;
F_63 ( V_8 ) ;
F_32 (lu, next, &tgt->lu_list, link) {
F_103 ( & V_2 -> V_5 ) ;
V_101 = F_104 ( V_88 , 0 , 0 , F_64 ( V_2 -> V_92 ) ) ;
if ( V_101 ) {
F_76 ( V_101 ) ;
F_77 ( V_101 ) ;
}
if ( V_2 -> V_105 != V_120 ) {
int V_21 , V_40 ;
V_21 = V_10 -> V_21 ;
F_68 () ;
V_40 = V_10 -> V_40 ;
F_36 ( V_2 , V_40 , V_21 ,
V_62 ,
V_2 -> V_105 , NULL ) ;
}
F_105 ( & V_2 -> V_70 ) ;
F_19 ( & V_2 -> V_37 ) ;
F_9 ( V_2 ) ;
}
F_106 ( V_88 ) ;
F_14 ( V_148 , L_15 , V_88 -> V_163 ) ;
F_100 ( V_88 ) ;
return 0 ;
}
static void F_107 ( struct V_10 * V_164 ,
struct V_165 * V_13 )
{
F_108 ( V_13 -> V_166 ) ;
if ( V_13 -> V_17 . V_67 & F_25 ( V_167 ) )
F_52 ( V_164 , V_13 -> V_168 ,
sizeof( V_13 -> V_169 ) , V_75 ) ;
}
static unsigned int F_109 ( T_6 * V_26 , T_6 * V_170 )
{
int V_171 ;
int V_172 = ( V_26 [ 0 ] >> 6 ) & 0x03 ;
if ( V_172 == 2 || V_172 == 3 ) {
return V_173 << 16 ;
}
V_170 [ 0 ] = 0x70 | V_172 | ( V_26 [ 1 ] & 0x80 ) ;
V_170 [ 1 ] = 0x0 ;
V_170 [ 2 ] = ( ( V_26 [ 1 ] << 1 ) & 0xe0 ) | ( V_26 [ 1 ] & 0x0f ) ;
V_170 [ 3 ] = V_26 [ 4 ] ;
V_170 [ 4 ] = V_26 [ 5 ] ;
V_170 [ 5 ] = V_26 [ 6 ] ;
V_170 [ 6 ] = V_26 [ 7 ] ;
V_170 [ 7 ] = 10 ;
V_170 [ 8 ] = V_26 [ 8 ] ;
V_170 [ 9 ] = V_26 [ 9 ] ;
V_170 [ 10 ] = V_26 [ 10 ] ;
V_170 [ 11 ] = V_26 [ 11 ] ;
V_170 [ 12 ] = V_26 [ 2 ] ;
V_170 [ 13 ] = V_26 [ 3 ] ;
V_170 [ 14 ] = V_26 [ 12 ] ;
V_170 [ 15 ] = V_26 [ 13 ] ;
V_171 = V_26 [ 0 ] & 0x3f ;
switch ( V_171 ) {
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
return V_180 << 16 | V_171 ;
default:
return V_173 << 16 ;
}
}
static void F_110 ( struct V_12 * V_53 ,
struct V_26 * V_27 )
{
struct V_165 * V_13 =
F_8 ( V_53 , struct V_165 , V_55 ) ;
struct V_6 * V_10 = F_3 ( V_13 -> V_2 -> V_8 ) ;
int V_181 ;
if ( V_27 != NULL ) {
if ( F_111 ( * V_27 ) )
F_56 ( V_13 -> V_2 ) ;
switch ( F_50 ( * V_27 ) ) {
case V_182 :
V_181 = V_180 << 16 ;
break;
case V_183 :
V_181 = V_184 << 16 ;
break;
case V_185 :
case V_186 :
default:
V_181 = V_173 << 16 ;
break;
}
if ( V_181 == V_180 << 16 && F_112 ( * V_27 ) > 1 )
V_181 = F_109 ( F_113 ( * V_27 ) ,
V_13 -> V_166 -> V_187 ) ;
} else {
V_181 = V_184 << 16 ;
F_59 ( V_13 -> V_2 ) ;
}
F_52 ( V_10 -> V_15 -> V_10 , V_13 -> V_55 . V_35 ,
sizeof( V_13 -> V_17 ) , V_75 ) ;
F_107 ( V_10 -> V_15 -> V_10 , V_13 ) ;
V_13 -> V_166 -> V_181 = V_181 ;
V_13 -> V_166 -> V_188 ( V_13 -> V_166 ) ;
}
static int F_114 ( struct V_165 * V_13 ,
struct V_6 * V_10 , struct V_1 * V_2 )
{
struct V_189 * V_190 = F_115 ( V_13 -> V_166 ) ;
int V_142 , V_191 ;
V_191 = F_116 ( V_13 -> V_166 ) ;
if ( V_191 <= 0 )
goto V_192;
if ( V_191 == 1 ) {
V_13 -> V_17 . V_193 . V_43 =
F_25 ( V_2 -> V_8 -> V_108 ) ;
V_13 -> V_17 . V_193 . V_44 =
F_25 ( F_117 ( V_190 ) ) ;
V_13 -> V_17 . V_67 |=
F_25 ( F_118 ( F_119 ( V_190 ) ) ) ;
return 0 ;
}
F_120 (sg, sg, n, i) {
V_13 -> V_169 [ V_142 ] . V_43 = F_25 ( F_119 ( V_190 ) << 16 ) ;
V_13 -> V_169 [ V_142 ] . V_44 = F_25 ( F_117 ( V_190 ) ) ;
}
V_13 -> V_168 =
F_40 ( V_10 -> V_15 -> V_10 , V_13 -> V_169 ,
sizeof( V_13 -> V_169 ) , V_75 ) ;
if ( F_41 ( V_10 -> V_15 -> V_10 , V_13 -> V_168 ) )
goto V_194;
V_13 -> V_17 . V_193 . V_43 = F_25 ( V_2 -> V_8 -> V_108 ) ;
V_13 -> V_17 . V_193 . V_44 = F_25 ( V_13 -> V_168 ) ;
V_13 -> V_17 . V_67 |= F_25 ( V_167 |
F_118 ( V_191 ) ) ;
return 0 ;
V_194:
F_108 ( V_13 -> V_166 ) ;
V_192:
return - V_61 ;
}
static int F_121 ( struct V_87 * V_88 ,
struct V_195 * V_166 )
{
struct V_1 * V_2 = V_166 -> V_10 -> V_89 ;
struct V_6 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_165 * V_13 ;
int V_21 , V_50 = V_196 ;
if ( V_166 -> V_197 == V_198 ) {
F_22 ( F_6 ( V_2 ) , L_16 ) ;
V_166 -> V_181 = V_173 << 16 ;
V_166 -> V_188 ( V_166 ) ;
return 0 ;
}
V_13 = F_38 ( sizeof( * V_13 ) , V_85 ) ;
if ( V_13 == NULL )
return V_196 ;
V_13 -> V_55 . V_36 = - 1 ;
F_39 ( & V_13 -> V_55 . V_11 ) ;
V_13 -> V_2 = V_2 ;
V_13 -> V_166 = V_166 ;
V_13 -> V_17 . V_47 . V_43 = F_25 ( V_199 ) ;
V_13 -> V_17 . V_67 = F_25 (
F_122 ( V_2 -> V_8 -> V_161 ) |
F_123 ( V_10 -> V_46 ) |
V_200 ) ;
if ( V_166 -> V_197 == V_65 )
V_13 -> V_17 . V_67 |= F_25 ( V_201 ) ;
V_21 = V_10 -> V_21 ;
F_68 () ;
if ( F_124 ( V_166 ) && F_114 ( V_13 , V_10 , V_2 ) < 0 )
goto V_79;
memcpy ( V_13 -> V_17 . V_202 , V_166 -> V_203 , V_166 -> V_204 ) ;
V_13 -> V_55 . V_39 = F_110 ;
V_13 -> V_55 . V_35 =
F_40 ( V_10 -> V_15 -> V_10 , & V_13 -> V_17 ,
sizeof( V_13 -> V_17 ) , V_75 ) ;
if ( F_41 ( V_10 -> V_15 -> V_10 , V_13 -> V_55 . V_35 ) ) {
F_107 ( V_10 -> V_15 -> V_10 , V_13 ) ;
goto V_79;
}
F_24 ( & V_13 -> V_55 , V_2 , V_2 -> V_8 -> V_40 , V_21 ,
V_2 -> V_82 + V_205 ) ;
V_50 = 0 ;
V_79:
F_21 ( & V_13 -> V_55 . V_11 , F_7 ) ;
return V_50 ;
}
static int F_125 ( struct V_100 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_89 ;
if ( ! V_2 )
return - V_206 ;
V_101 -> V_207 = 1 ;
F_126 ( V_101 -> V_208 , 4 - 1 ) ;
if ( V_2 -> V_8 -> V_111 & V_209 )
V_101 -> V_210 = 36 ;
return 0 ;
}
static int F_127 ( struct V_100 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_89 ;
V_101 -> V_211 = 1 ;
if ( V_72 )
V_101 -> V_212 = 1 ;
if ( V_101 -> type == V_213 )
V_101 -> V_214 = 1 ;
if ( V_101 -> type == V_215 &&
V_2 -> V_8 -> V_111 & V_216 )
V_101 -> V_217 = 1 ;
if ( V_2 -> V_8 -> V_111 & V_218 )
V_101 -> V_219 = 1 ;
if ( V_2 -> V_8 -> V_111 & V_220 )
V_101 -> V_221 = 1 ;
if ( V_2 -> V_8 -> V_111 & V_222 )
F_128 ( V_101 -> V_208 , 128 * 1024 / 512 ) ;
return 0 ;
}
static int F_129 ( struct V_195 * V_166 )
{
struct V_1 * V_2 = V_166 -> V_10 -> V_89 ;
F_14 ( F_6 ( V_2 ) , L_17 ) ;
F_53 ( V_2 ) ;
F_29 ( V_2 ) ;
return V_223 ;
}
static T_7 F_130 ( struct V_10 * V_148 ,
struct V_224 * V_225 , char * V_226 )
{
struct V_100 * V_101 = F_131 ( V_148 ) ;
struct V_1 * V_2 ;
if ( ! V_101 )
return 0 ;
V_2 = V_101 -> V_89 ;
return sprintf ( V_226 , L_18 ,
( unsigned long long ) V_2 -> V_8 -> V_123 ,
V_2 -> V_8 -> V_135 , V_2 -> V_92 ) ;
}
static int T_8 F_132 ( void )
{
return F_133 ( & V_227 . V_228 ) ;
}
static void T_9 F_134 ( void )
{
F_135 ( & V_227 . V_228 ) ;
}
