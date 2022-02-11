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
F_15 ( & V_2 -> V_8 -> V_34 , V_28 ) ;
F_16 (orb, &lu->orb_list, link) {
if ( F_17 ( V_27 ) == 0 &&
F_18 ( V_27 ) == V_13 -> V_35 ) {
V_13 -> V_36 = V_33 ;
F_19 ( & V_13 -> V_37 ) ;
break;
}
}
F_20 ( & V_2 -> V_8 -> V_34 , V_28 ) ;
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
F_15 ( & V_13 -> V_2 -> V_8 -> V_34 , V_28 ) ;
if ( V_13 -> V_36 == - 1 )
V_13 -> V_36 = V_36 ;
if ( V_13 -> V_36 != V_33 ) {
F_19 ( & V_13 -> V_37 ) ;
F_20 ( & V_13 -> V_2 -> V_8 -> V_34 , V_28 ) ;
V_13 -> V_39 ( V_13 , NULL ) ;
F_21 ( & V_13 -> V_11 , F_7 ) ;
} else {
F_20 ( & V_13 -> V_2 -> V_8 -> V_34 , V_28 ) ;
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
V_13 -> V_2 = V_2 ;
F_15 ( & V_2 -> V_8 -> V_34 , V_28 ) ;
F_26 ( & V_13 -> V_37 , & V_2 -> V_38 ) ;
F_20 ( & V_2 -> V_8 -> V_34 , V_28 ) ;
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
int V_50 = - V_51 ;
F_30 ( & V_49 ) ;
F_31 ( & V_2 -> V_8 -> V_34 ) ;
F_32 ( & V_2 -> V_38 , & V_49 ) ;
F_33 ( & V_2 -> V_8 -> V_34 ) ;
F_34 (orb, next, &list, link) {
V_50 = 0 ;
if ( F_35 ( V_10 -> V_15 , & V_13 -> V_45 ) == 0 )
continue;
V_13 -> V_36 = V_52 ;
V_13 -> V_39 ( V_13 , NULL ) ;
F_21 ( & V_13 -> V_11 , F_7 ) ;
}
return V_50 ;
}
static void F_36 ( struct V_12 * V_53 ,
struct V_26 * V_27 )
{
struct V_54 * V_13 =
F_8 ( V_53 , struct V_54 , V_55 ) ;
if ( V_27 )
memcpy ( & V_13 -> V_27 , V_27 , sizeof( * V_27 ) ) ;
F_37 ( & V_13 -> V_56 ) ;
}
static int F_38 ( struct V_1 * V_2 , int V_40 ,
int V_21 , int V_57 ,
int V_58 , void * V_59 )
{
struct V_6 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_54 * V_13 ;
unsigned int V_60 ;
int V_50 = - V_61 ;
if ( V_57 == V_62 && F_39 ( V_10 ) )
return 0 ;
V_13 = F_40 ( sizeof( * V_13 ) , V_63 ) ;
if ( V_13 == NULL )
return - V_61 ;
F_41 ( & V_13 -> V_55 . V_11 ) ;
V_13 -> V_64 =
F_42 ( V_10 -> V_15 -> V_10 , & V_13 -> V_59 ,
sizeof( V_13 -> V_59 ) , V_65 ) ;
if ( F_43 ( V_10 -> V_15 -> V_10 , V_13 -> V_64 ) )
goto V_66;
V_13 -> V_17 . V_59 . V_43 = 0 ;
V_13 -> V_17 . V_59 . V_44 = F_25 ( V_13 -> V_64 ) ;
V_13 -> V_17 . V_67 = F_25 (
V_68 |
F_44 ( V_57 ) |
F_45 ( V_58 ) ) ;
V_13 -> V_17 . V_24 = F_25 (
F_46 ( sizeof( V_13 -> V_59 ) ) ) ;
V_13 -> V_17 . V_69 . V_43 =
F_25 ( V_2 -> V_70 . V_22 >> 32 ) ;
V_13 -> V_17 . V_69 . V_44 =
F_25 ( V_2 -> V_70 . V_22 ) ;
if ( V_57 == V_71 ) {
V_13 -> V_17 . V_67 |= F_25 (
F_47 ( 2 ) |
F_48 ( V_72 ) ) ;
V_60 = V_2 -> V_8 -> V_73 ;
} else {
V_60 = V_74 ;
}
F_49 ( & V_13 -> V_56 ) ;
V_13 -> V_55 . V_39 = F_36 ;
V_13 -> V_55 . V_35 =
F_42 ( V_10 -> V_15 -> V_10 , & V_13 -> V_17 ,
sizeof( V_13 -> V_17 ) , V_75 ) ;
if ( F_43 ( V_10 -> V_15 -> V_10 , V_13 -> V_55 . V_35 ) )
goto V_76;
F_24 ( & V_13 -> V_55 , V_2 , V_40 , V_21 ,
V_2 -> V_8 -> V_77 ) ;
F_50 ( & V_13 -> V_56 , F_51 ( V_60 ) ) ;
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
if ( F_52 ( V_13 -> V_27 ) != 0 ||
F_53 ( V_13 -> V_27 ) != 0 ) {
F_22 ( F_6 ( V_2 ) , L_5 ,
F_52 ( V_13 -> V_27 ) ,
F_53 ( V_13 -> V_27 ) ) ;
goto V_79;
}
V_50 = 0 ;
V_79:
F_54 ( V_10 -> V_15 -> V_10 , V_13 -> V_55 . V_35 ,
sizeof( V_13 -> V_17 ) , V_75 ) ;
V_76:
F_54 ( V_10 -> V_15 -> V_10 , V_13 -> V_64 ,
sizeof( V_13 -> V_59 ) , V_65 ) ;
V_66:
if ( V_59 )
memcpy ( V_59 , V_13 -> V_59 , sizeof( V_13 -> V_59 ) ) ;
F_21 ( & V_13 -> V_55 . V_11 , F_7 ) ;
return V_50 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_6 * V_10 = F_3 ( V_2 -> V_8 ) ;
T_3 V_80 = 0 ;
F_56 ( V_10 -> V_15 , V_81 ,
V_2 -> V_8 -> V_40 , V_2 -> V_21 , V_10 -> V_46 ,
V_2 -> V_82 + V_83 ,
& V_80 , 4 ) ;
}
static void F_57 ( struct V_14 * V_15 ,
int V_36 , void * V_23 , T_1 V_24 , void * V_32 )
{
F_9 ( V_32 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_6 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_84 * V_45 ;
static T_3 V_80 ;
V_45 = F_59 ( sizeof( * V_45 ) , V_85 ) ;
if ( V_45 == NULL )
return;
F_28 ( V_10 -> V_15 , V_45 , V_81 ,
V_2 -> V_8 -> V_40 , V_2 -> V_21 , V_10 -> V_46 ,
V_2 -> V_82 + V_83 ,
& V_80 , 4 , F_57 , V_45 ) ;
}
static inline void F_60 ( struct V_7 * V_8 )
{
F_31 ( & V_8 -> V_34 ) ;
-- V_8 -> V_86 ;
F_33 ( & V_8 -> V_34 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_14 * V_15 = F_3 ( V_8 ) -> V_15 ;
struct V_87 * V_88 =
F_8 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
unsigned long V_28 ;
F_15 ( & V_8 -> V_34 , V_28 ) ;
if ( ! V_8 -> V_86 && ! V_2 -> V_90 &&
V_2 -> V_21 != V_15 -> V_21 ) {
V_2 -> V_90 = true ;
if ( ++ V_8 -> V_90 == 1 )
F_62 ( V_88 ) ;
}
F_20 ( & V_8 -> V_34 , V_28 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_14 * V_15 = F_3 ( V_8 ) -> V_15 ;
struct V_87 * V_88 =
F_8 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
bool V_91 = false ;
F_31 ( & V_8 -> V_34 ) ;
if ( V_2 -> V_90 && V_2 -> V_21 == V_15 -> V_21 ) {
V_2 -> V_90 = false ;
V_91 = -- V_8 -> V_90 == 0 ;
}
F_33 ( & V_8 -> V_34 ) ;
if ( V_91 )
F_64 ( V_88 ) ;
}
static void F_65 ( struct V_7 * V_8 )
{
struct V_87 * V_88 =
F_8 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
F_31 ( & V_8 -> V_34 ) ;
++ V_8 -> V_86 ;
F_33 ( & V_8 -> V_34 ) ;
F_64 ( V_88 ) ;
}
static int F_66 ( T_4 V_92 )
{
struct V_93 V_94 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_93 [ 0 ] = ( V_92 >> 8 ) & 0xff ;
V_94 . V_93 [ 1 ] = V_92 & 0xff ;
return F_67 ( & V_94 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_6 * V_10 = F_3 ( V_2 -> V_8 ) ;
T_3 V_80 = F_25 ( V_95 | V_96 ) ;
F_56 ( V_10 -> V_15 , V_81 ,
V_2 -> V_8 -> V_40 , V_2 -> V_21 , V_10 -> V_46 ,
V_97 + V_98 , & V_80 , 4 ) ;
}
static void F_69 ( struct V_99 * V_5 )
{
struct V_1 * V_2 =
F_8 ( V_5 , struct V_1 , V_5 . V_5 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_6 * V_10 = F_3 ( V_8 ) ;
struct V_87 * V_88 ;
struct V_100 * V_101 ;
struct V_102 V_59 ;
int V_21 , V_40 , V_103 ;
if ( F_39 ( V_10 ) )
return;
V_21 = V_10 -> V_21 ;
F_70 () ;
V_40 = V_10 -> V_40 ;
V_103 = V_10 -> V_15 -> V_40 ;
if ( V_2 -> V_104 )
F_38 ( V_2 , V_10 -> V_40 , V_21 ,
V_62 , V_2 -> V_105 , NULL ) ;
if ( F_38 ( V_2 , V_40 , V_21 ,
V_71 , V_2 -> V_92 , & V_59 ) < 0 ) {
if ( V_2 -> V_106 ++ < 5 ) {
F_1 ( V_2 , F_71 ( V_107 , 5 ) ) ;
} else {
F_22 ( F_5 ( V_8 ) , L_6 ,
V_2 -> V_92 ) ;
F_65 ( V_2 -> V_8 ) ;
}
return;
}
V_8 -> V_40 = V_40 ;
V_8 -> V_108 = V_103 << 16 ;
F_72 () ;
V_2 -> V_21 = V_21 ;
V_2 -> V_82 =
( ( T_2 ) ( F_73 ( V_59 . V_109 . V_43 ) & 0xffff )
<< 32 ) | F_73 ( V_59 . V_109 . V_44 ) ;
V_2 -> V_105 = F_73 ( V_59 . V_67 ) & 0xffff ;
F_14 ( F_5 ( V_8 ) , L_7 ,
V_2 -> V_92 , V_2 -> V_106 ) ;
F_68 ( V_2 ) ;
V_2 -> V_110 = V_111 ;
F_55 ( V_2 ) ;
if ( V_2 -> V_104 ) {
F_29 ( V_2 ) ;
F_63 ( V_2 ) ;
return;
}
if ( V_2 -> V_8 -> V_112 & V_113 )
F_74 ( V_114 ) ;
V_88 = F_8 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
V_101 = F_75 ( V_88 , 0 , 0 , F_66 ( V_2 -> V_92 ) , V_2 ) ;
if ( F_76 ( V_101 ) )
goto V_115;
F_70 () ;
if ( V_21 != V_10 -> V_15 -> V_21 ) {
F_77 ( V_101 ) ;
F_78 ( V_101 ) ;
goto V_115;
}
V_2 -> V_104 = true ;
F_78 ( V_101 ) ;
F_60 ( V_8 ) ;
return;
V_115:
F_70 () ;
V_21 = V_10 -> V_21 ;
F_70 () ;
F_38 ( V_2 , V_10 -> V_40 , V_21 ,
V_62 , V_2 -> V_105 , NULL ) ;
V_2 -> V_110 = F_69 ;
}
static void V_111 ( struct V_99 * V_5 )
{
struct V_1 * V_2 =
F_8 ( V_5 , struct V_1 , V_5 . V_5 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_6 * V_10 = F_3 ( V_8 ) ;
int V_21 , V_40 , V_103 ;
if ( F_39 ( V_10 ) )
return;
V_21 = V_10 -> V_21 ;
F_70 () ;
V_40 = V_10 -> V_40 ;
V_103 = V_10 -> V_15 -> V_40 ;
if ( F_38 ( V_2 , V_40 , V_21 ,
V_116 ,
V_2 -> V_105 , NULL ) < 0 ) {
F_70 () ;
if ( V_21 == V_10 -> V_15 -> V_21 ||
V_2 -> V_106 ++ >= 5 ) {
F_22 ( F_5 ( V_8 ) , L_8 ) ;
V_2 -> V_106 = 0 ;
V_2 -> V_110 = F_69 ;
}
F_1 ( V_2 , F_71 ( V_107 , 5 ) ) ;
return;
}
V_8 -> V_40 = V_40 ;
V_8 -> V_108 = V_103 << 16 ;
F_72 () ;
V_2 -> V_21 = V_21 ;
F_14 ( F_5 ( V_8 ) , L_9 ,
V_2 -> V_92 , V_2 -> V_106 ) ;
F_55 ( V_2 ) ;
F_29 ( V_2 ) ;
F_63 ( V_2 ) ;
}
static void F_79 ( struct V_99 * V_5 )
{
struct V_1 * V_2 = F_8 ( F_80 ( V_5 ) ,
struct V_1 , V_5 ) ;
V_2 -> V_110 ( V_5 ) ;
}
static int F_81 ( struct V_7 * V_8 , int V_117 )
{
struct V_1 * V_2 ;
V_2 = F_59 ( sizeof( * V_2 ) , V_118 ) ;
if ( ! V_2 )
return - V_61 ;
V_2 -> V_70 . V_24 = 0x100 ;
V_2 -> V_70 . V_119 = F_10 ;
V_2 -> V_70 . V_25 = V_2 ;
if ( F_82 ( & V_2 -> V_70 ,
& V_120 ) < 0 ) {
F_9 ( V_2 ) ;
return - V_61 ;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_92 = V_117 & 0xffff ;
V_2 -> V_105 = V_121 ;
V_2 -> V_106 = 0 ;
V_2 -> V_104 = false ;
V_2 -> V_90 = false ;
++ V_8 -> V_86 ;
F_30 ( & V_2 -> V_38 ) ;
V_2 -> V_110 = F_69 ;
F_83 ( & V_2 -> V_5 , F_79 ) ;
F_26 ( & V_2 -> V_37 , & V_8 -> V_122 ) ;
return 0 ;
}
static void F_84 ( struct V_7 * V_8 ,
const T_5 * V_123 )
{
if ( ( V_123 [ 0 ] & 0xffff0000 ) == 0x00020000 )
V_8 -> V_124 = ( T_2 ) V_123 [ 1 ] << 32 | V_123 [ 2 ] ;
}
static int F_85 ( struct V_7 * V_8 ,
const T_5 * V_125 )
{
struct V_126 V_127 ;
int V_128 , V_129 ;
F_86 ( & V_127 , V_125 ) ;
while ( F_87 ( & V_127 , & V_128 , & V_129 ) )
if ( V_128 == V_130 &&
F_81 ( V_8 , V_129 ) < 0 )
return - V_61 ;
return 0 ;
}
static int F_88 ( struct V_7 * V_8 , const T_5 * V_125 ,
T_5 * V_131 , T_5 * V_132 )
{
struct V_126 V_127 ;
int V_128 , V_129 ;
F_86 ( & V_127 , V_125 ) ;
while ( F_87 ( & V_127 , & V_128 , & V_129 ) ) {
switch ( V_128 ) {
case V_133 | V_134 :
V_8 -> V_77 =
V_97 + 4 * V_129 ;
break;
case V_135 :
V_8 -> V_136 = V_129 ;
break;
case V_137 :
* V_131 = V_129 ;
break;
case V_138 :
* V_132 = V_129 ;
break;
case V_139 :
V_8 -> V_73 = ( V_129 >> 8 & 0xff ) * 500 ;
break;
case V_130 :
if ( F_81 ( V_8 , V_129 ) < 0 )
return - V_61 ;
break;
case V_140 :
F_84 ( V_8 , V_127 . V_141 - 1 + V_129 ) ;
break;
case V_142 :
if ( F_85 ( V_8 , V_127 . V_141 - 1 + V_129 ) < 0 )
return - V_61 ;
break;
}
}
return 0 ;
}
static void F_89 ( struct V_7 * V_8 )
{
unsigned int V_60 = V_8 -> V_73 ;
if ( V_60 > 40000 )
F_14 ( F_5 ( V_8 ) , L_10 ,
V_60 / 1000 ) ;
V_8 -> V_73 = F_90 ( V_60 , 5000 , 40000 ) ;
}
static void F_91 ( struct V_7 * V_8 , T_5 V_131 ,
T_5 V_132 )
{
int V_143 ;
unsigned int V_144 = V_145 ;
if ( V_144 )
F_14 ( F_5 ( V_8 ) ,
L_11
L_12 ) ;
if ( V_144 & V_146 )
goto V_79;
for ( V_143 = 0 ; V_143 < F_92 ( V_147 ) ; V_143 ++ ) {
if ( V_147 [ V_143 ] . V_132 !=
( V_132 & 0xffffff00 ) )
continue;
if ( V_147 [ V_143 ] . V_131 != V_131 &&
V_147 [ V_143 ] . V_131 != V_148 )
continue;
V_144 |= V_147 [ V_143 ] . V_112 ;
break;
}
V_79:
if ( V_144 )
F_14 ( F_5 ( V_8 ) , L_13
L_14 ,
V_144 , V_132 , V_131 ) ;
V_8 -> V_112 = V_144 ;
}
static int F_93 ( struct V_149 * V_9 , const struct V_150 * V_151 )
{
struct V_6 * V_10 = F_4 ( V_9 ) ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_87 * V_88 ;
T_5 V_131 , V_132 ;
if ( V_10 -> V_152 )
return - V_153 ;
if ( F_94 ( V_10 -> V_15 -> V_10 ) > V_154 )
F_95 ( F_96 ( V_10 -> V_15 -> V_10 ,
V_154 ) ) ;
V_88 = F_97 ( & V_155 , sizeof( * V_8 ) ) ;
if ( V_88 == NULL )
return - V_61 ;
V_8 = (struct V_7 * ) V_88 -> V_89 ;
F_98 ( & V_9 -> V_10 , V_8 ) ;
V_8 -> V_9 = V_9 ;
F_30 ( & V_8 -> V_122 ) ;
F_99 ( & V_8 -> V_34 ) ;
V_8 -> V_124 = ( T_2 ) V_10 -> V_156 [ 3 ] << 32 | V_10 -> V_156 [ 4 ] ;
if ( F_100 ( V_10 ) < 0 )
goto V_157;
V_88 -> V_158 = V_159 ;
if ( F_101 ( V_88 , & V_9 -> V_10 ,
V_10 -> V_15 -> V_10 ) < 0 )
goto V_157;
V_8 -> V_136 = ( ( V_9 -> V_125 - V_10 -> V_156 ) * 4
+ V_160 ) & 0xffffff ;
V_132 = V_161 ;
V_131 = V_161 ;
if ( F_88 ( V_8 , V_9 -> V_125 , & V_131 ,
& V_132 ) < 0 )
goto V_162;
F_89 ( V_8 ) ;
F_91 ( V_8 , V_131 , V_132 ) ;
V_8 -> V_163 = F_102 ( V_10 -> V_46 + 7 , 10U ,
V_10 -> V_15 -> V_164 - 1 ) ;
F_16 (lu, &tgt->lu_list, link)
F_1 ( V_2 , F_71 ( V_107 , 5 ) ) ;
return 0 ;
V_162:
F_103 ( V_9 ) ;
return - V_61 ;
V_157:
F_104 ( V_88 ) ;
return - V_61 ;
}
static void F_105 ( struct V_149 * V_9 )
{
struct V_7 * V_8 = F_106 ( & V_9 -> V_10 ) ;
struct V_1 * V_2 ;
F_100 ( F_4 ( V_9 ) ) ;
F_16 (lu, &tgt->lu_list, link) {
F_61 ( V_2 ) ;
V_2 -> V_106 = 0 ;
F_1 ( V_2 , 0 ) ;
}
}
static void F_103 ( struct V_149 * V_9 )
{
struct V_6 * V_10 = F_4 ( V_9 ) ;
struct V_7 * V_8 = F_106 ( & V_9 -> V_10 ) ;
struct V_1 * V_2 , * V_47 ;
struct V_87 * V_88 =
F_8 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
struct V_100 * V_101 ;
F_65 ( V_8 ) ;
F_34 (lu, next, &tgt->lu_list, link) {
F_107 ( & V_2 -> V_5 ) ;
V_101 = F_108 ( V_88 , 0 , 0 , F_66 ( V_2 -> V_92 ) ) ;
if ( V_101 ) {
F_77 ( V_101 ) ;
F_78 ( V_101 ) ;
}
if ( V_2 -> V_105 != V_121 ) {
int V_21 , V_40 ;
V_21 = V_10 -> V_21 ;
F_70 () ;
V_40 = V_10 -> V_40 ;
F_38 ( V_2 , V_40 , V_21 ,
V_62 ,
V_2 -> V_105 , NULL ) ;
}
F_109 ( & V_2 -> V_70 ) ;
F_19 ( & V_2 -> V_37 ) ;
F_9 ( V_2 ) ;
}
F_110 ( V_88 ) ;
F_14 ( & V_9 -> V_10 , L_15 , V_88 -> V_165 ) ;
F_104 ( V_88 ) ;
}
static void F_111 ( struct V_10 * V_166 ,
struct V_167 * V_13 )
{
F_112 ( V_13 -> V_168 ) ;
if ( V_13 -> V_17 . V_67 & F_25 ( V_169 ) )
F_54 ( V_166 , V_13 -> V_170 ,
sizeof( V_13 -> V_171 ) , V_75 ) ;
}
static unsigned int F_113 ( T_6 * V_26 , T_6 * V_172 )
{
int V_173 ;
int V_174 = ( V_26 [ 0 ] >> 6 ) & 0x03 ;
if ( V_174 == 2 || V_174 == 3 ) {
return V_175 << 16 ;
}
V_172 [ 0 ] = 0x70 | V_174 | ( V_26 [ 1 ] & 0x80 ) ;
V_172 [ 1 ] = 0x0 ;
V_172 [ 2 ] = ( ( V_26 [ 1 ] << 1 ) & 0xe0 ) | ( V_26 [ 1 ] & 0x0f ) ;
V_172 [ 3 ] = V_26 [ 4 ] ;
V_172 [ 4 ] = V_26 [ 5 ] ;
V_172 [ 5 ] = V_26 [ 6 ] ;
V_172 [ 6 ] = V_26 [ 7 ] ;
V_172 [ 7 ] = 10 ;
V_172 [ 8 ] = V_26 [ 8 ] ;
V_172 [ 9 ] = V_26 [ 9 ] ;
V_172 [ 10 ] = V_26 [ 10 ] ;
V_172 [ 11 ] = V_26 [ 11 ] ;
V_172 [ 12 ] = V_26 [ 2 ] ;
V_172 [ 13 ] = V_26 [ 3 ] ;
V_172 [ 14 ] = V_26 [ 12 ] ;
V_172 [ 15 ] = V_26 [ 13 ] ;
V_173 = V_26 [ 0 ] & 0x3f ;
switch ( V_173 ) {
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
return V_182 << 16 | V_173 ;
default:
return V_175 << 16 ;
}
}
static void F_114 ( struct V_12 * V_53 ,
struct V_26 * V_27 )
{
struct V_167 * V_13 =
F_8 ( V_53 , struct V_167 , V_55 ) ;
struct V_6 * V_10 = F_3 ( V_53 -> V_2 -> V_8 ) ;
int V_183 ;
if ( V_27 != NULL ) {
if ( F_115 ( * V_27 ) )
F_58 ( V_53 -> V_2 ) ;
switch ( F_52 ( * V_27 ) ) {
case V_184 :
V_183 = V_182 << 16 ;
break;
case V_185 :
V_183 = V_186 << 16 ;
break;
case V_187 :
case V_188 :
default:
V_183 = V_175 << 16 ;
break;
}
if ( V_183 == V_182 << 16 && F_116 ( * V_27 ) > 1 )
V_183 = F_113 ( F_117 ( * V_27 ) ,
V_13 -> V_168 -> V_189 ) ;
} else {
V_183 = V_186 << 16 ;
F_61 ( V_53 -> V_2 ) ;
}
F_54 ( V_10 -> V_15 -> V_10 , V_13 -> V_55 . V_35 ,
sizeof( V_13 -> V_17 ) , V_75 ) ;
F_111 ( V_10 -> V_15 -> V_10 , V_13 ) ;
V_13 -> V_168 -> V_183 = V_183 ;
V_13 -> V_168 -> V_190 ( V_13 -> V_168 ) ;
}
static int F_118 ( struct V_167 * V_13 ,
struct V_6 * V_10 , struct V_1 * V_2 )
{
struct V_191 * V_192 = F_119 ( V_13 -> V_168 ) ;
int V_143 , V_193 ;
V_193 = F_120 ( V_13 -> V_168 ) ;
if ( V_193 <= 0 )
goto V_194;
if ( V_193 == 1 ) {
V_13 -> V_17 . V_195 . V_43 =
F_25 ( V_2 -> V_8 -> V_108 ) ;
V_13 -> V_17 . V_195 . V_44 =
F_25 ( F_121 ( V_192 ) ) ;
V_13 -> V_17 . V_67 |=
F_25 ( F_122 ( F_123 ( V_192 ) ) ) ;
return 0 ;
}
F_124 (sg, sg, n, i) {
V_13 -> V_171 [ V_143 ] . V_43 = F_25 ( F_123 ( V_192 ) << 16 ) ;
V_13 -> V_171 [ V_143 ] . V_44 = F_25 ( F_121 ( V_192 ) ) ;
}
V_13 -> V_170 =
F_42 ( V_10 -> V_15 -> V_10 , V_13 -> V_171 ,
sizeof( V_13 -> V_171 ) , V_75 ) ;
if ( F_43 ( V_10 -> V_15 -> V_10 , V_13 -> V_170 ) )
goto V_196;
V_13 -> V_17 . V_195 . V_43 = F_25 ( V_2 -> V_8 -> V_108 ) ;
V_13 -> V_17 . V_195 . V_44 = F_25 ( V_13 -> V_170 ) ;
V_13 -> V_17 . V_67 |= F_25 ( V_169 |
F_122 ( V_193 ) ) ;
return 0 ;
V_196:
F_112 ( V_13 -> V_168 ) ;
V_194:
return - V_61 ;
}
static int F_125 ( struct V_87 * V_88 ,
struct V_197 * V_168 )
{
struct V_1 * V_2 = V_168 -> V_10 -> V_89 ;
struct V_6 * V_10 = F_3 ( V_2 -> V_8 ) ;
struct V_167 * V_13 ;
int V_21 , V_50 = V_198 ;
V_13 = F_40 ( sizeof( * V_13 ) , V_85 ) ;
if ( V_13 == NULL )
return V_198 ;
V_13 -> V_55 . V_36 = - 1 ;
F_41 ( & V_13 -> V_55 . V_11 ) ;
V_13 -> V_168 = V_168 ;
V_13 -> V_17 . V_47 . V_43 = F_25 ( V_199 ) ;
V_13 -> V_17 . V_67 = F_25 (
F_126 ( V_2 -> V_8 -> V_163 ) |
F_127 ( V_10 -> V_46 ) |
V_200 ) ;
if ( V_168 -> V_201 == V_65 )
V_13 -> V_17 . V_67 |= F_25 ( V_202 ) ;
V_21 = V_10 -> V_21 ;
F_70 () ;
if ( F_128 ( V_168 ) && F_118 ( V_13 , V_10 , V_2 ) < 0 )
goto V_79;
memcpy ( V_13 -> V_17 . V_203 , V_168 -> V_204 , V_168 -> V_205 ) ;
V_13 -> V_55 . V_39 = F_114 ;
V_13 -> V_55 . V_35 =
F_42 ( V_10 -> V_15 -> V_10 , & V_13 -> V_17 ,
sizeof( V_13 -> V_17 ) , V_75 ) ;
if ( F_43 ( V_10 -> V_15 -> V_10 , V_13 -> V_55 . V_35 ) ) {
F_111 ( V_10 -> V_15 -> V_10 , V_13 ) ;
goto V_79;
}
F_24 ( & V_13 -> V_55 , V_2 , V_2 -> V_8 -> V_40 , V_21 ,
V_2 -> V_82 + V_206 ) ;
V_50 = 0 ;
V_79:
F_21 ( & V_13 -> V_55 . V_11 , F_7 ) ;
return V_50 ;
}
static int F_129 ( struct V_100 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_89 ;
if ( ! V_2 )
return - V_207 ;
V_101 -> V_208 = 1 ;
F_130 ( V_101 -> V_209 , 4 - 1 ) ;
if ( V_2 -> V_8 -> V_112 & V_210 )
V_101 -> V_211 = 36 ;
return 0 ;
}
static int F_131 ( struct V_100 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_89 ;
V_101 -> V_212 = 1 ;
if ( V_72 )
V_101 -> V_213 = 1 ;
if ( V_101 -> type == V_214 )
V_101 -> V_215 = 1 ;
if ( V_101 -> type == V_216 &&
V_2 -> V_8 -> V_112 & V_217 )
V_101 -> V_218 = 1 ;
if ( V_2 -> V_8 -> V_112 & V_219 )
V_101 -> V_220 = 1 ;
if ( V_2 -> V_8 -> V_112 & V_221 )
V_101 -> V_222 = 1 ;
if ( V_2 -> V_8 -> V_112 & V_223 )
F_132 ( V_101 -> V_209 , 128 * 1024 / 512 ) ;
return 0 ;
}
static int F_133 ( struct V_197 * V_168 )
{
struct V_1 * V_2 = V_168 -> V_10 -> V_89 ;
F_14 ( F_6 ( V_2 ) , L_16 ) ;
F_55 ( V_2 ) ;
F_29 ( V_2 ) ;
return V_224 ;
}
static T_7 F_134 ( struct V_10 * V_225 ,
struct V_226 * V_227 , char * V_228 )
{
struct V_100 * V_101 = F_135 ( V_225 ) ;
struct V_1 * V_2 ;
if ( ! V_101 )
return 0 ;
V_2 = V_101 -> V_89 ;
return sprintf ( V_228 , L_17 ,
( unsigned long long ) V_2 -> V_8 -> V_124 ,
V_2 -> V_8 -> V_136 , V_2 -> V_92 ) ;
}
static int T_8 F_136 ( void )
{
return F_137 ( & V_229 . V_230 ) ;
}
static void T_9 F_138 ( void )
{
F_139 ( & V_229 . V_230 ) ;
}
