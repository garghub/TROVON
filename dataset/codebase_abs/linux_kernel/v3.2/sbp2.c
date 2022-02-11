static void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
F_2 ( V_4 , & V_2 -> V_5 , V_3 ) ;
}
static struct V_6 * F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 -> V_9 ) ;
}
static void F_5 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_6 ( V_10 , struct V_11 , V_10 ) ;
F_7 ( V_12 ) ;
}
static void F_8 ( struct V_13 * V_14 , struct V_15 * V_16 ,
int V_17 , int V_18 , int V_19 ,
int V_20 , unsigned long long V_21 ,
void * V_22 , T_1 V_23 , void * V_24 )
{
struct V_1 * V_2 = V_24 ;
struct V_11 * V_12 ;
struct V_25 V_26 ;
unsigned long V_27 ;
if ( V_17 != V_28 ||
V_23 < 8 || V_23 > sizeof( V_26 ) ) {
F_9 ( V_14 , V_16 , V_29 ) ;
return;
}
V_26 . V_26 = F_10 ( V_22 ) ;
V_26 . V_30 = F_10 ( V_22 + 4 ) ;
memset ( V_26 . V_31 , 0 , sizeof( V_26 . V_31 ) ) ;
if ( V_23 > 8 )
memcpy ( V_26 . V_31 , V_22 + 8 , V_23 - 8 ) ;
if ( F_11 ( V_26 ) == 2 || F_11 ( V_26 ) == 3 ) {
F_12 ( L_1 ) ;
F_9 ( V_14 , V_16 , V_32 ) ;
return;
}
F_13 ( & V_14 -> V_33 , V_27 ) ;
F_14 (orb, &lu->orb_list, link) {
if ( F_15 ( V_26 ) == 0 &&
F_16 ( V_26 ) == V_12 -> V_34 ) {
V_12 -> V_35 = V_32 ;
F_17 ( & V_12 -> V_36 ) ;
break;
}
}
F_18 ( & V_14 -> V_33 , V_27 ) ;
if ( & V_12 -> V_36 != & V_2 -> V_37 ) {
V_12 -> V_38 ( V_12 , & V_26 ) ;
F_19 ( & V_12 -> V_10 , F_5 ) ;
} else {
F_20 ( L_2 ) ;
}
F_9 ( V_14 , V_16 , V_32 ) ;
}
static void F_21 ( struct V_13 * V_14 , int V_35 ,
void * V_22 , T_1 V_23 , void * V_31 )
{
struct V_11 * V_12 = V_31 ;
unsigned long V_27 ;
F_13 ( & V_14 -> V_33 , V_27 ) ;
if ( V_12 -> V_35 == - 1 )
V_12 -> V_35 = V_35 ;
if ( V_12 -> V_35 != V_32 ) {
F_17 ( & V_12 -> V_36 ) ;
F_18 ( & V_14 -> V_33 , V_27 ) ;
V_12 -> V_38 ( V_12 , NULL ) ;
F_19 ( & V_12 -> V_10 , F_5 ) ;
} else {
F_18 ( & V_14 -> V_33 , V_27 ) ;
}
F_19 ( & V_12 -> V_10 , F_5 ) ;
}
static void F_22 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_39 , int V_20 , T_2 V_21 )
{
struct V_6 * V_40 = F_3 ( V_2 -> V_8 ) ;
struct V_41 V_42 ;
unsigned long V_27 ;
V_42 . V_43 = 0 ;
V_42 . V_44 = F_23 ( V_12 -> V_34 ) ;
F_13 ( & V_40 -> V_14 -> V_33 , V_27 ) ;
F_24 ( & V_12 -> V_36 , & V_2 -> V_37 ) ;
F_18 ( & V_40 -> V_14 -> V_33 , V_27 ) ;
F_25 ( & V_12 -> V_10 ) ;
F_25 ( & V_12 -> V_10 ) ;
F_26 ( V_40 -> V_14 , & V_12 -> V_45 , V_28 ,
V_39 , V_20 , V_40 -> V_46 , V_21 ,
& V_42 , 8 , F_21 , V_12 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_40 = F_3 ( V_2 -> V_8 ) ;
struct V_11 * V_12 , * V_47 ;
struct V_48 V_49 ;
unsigned long V_27 ;
int V_50 = - V_51 ;
F_28 ( & V_49 ) ;
F_13 ( & V_40 -> V_14 -> V_33 , V_27 ) ;
F_29 ( & V_2 -> V_37 , & V_49 ) ;
F_18 ( & V_40 -> V_14 -> V_33 , V_27 ) ;
F_30 (orb, next, &list, link) {
V_50 = 0 ;
if ( F_31 ( V_40 -> V_14 , & V_12 -> V_45 ) == 0 )
continue;
V_12 -> V_35 = V_52 ;
V_12 -> V_38 ( V_12 , NULL ) ;
F_19 ( & V_12 -> V_10 , F_5 ) ;
}
return V_50 ;
}
static void F_32 ( struct V_11 * V_53 ,
struct V_25 * V_26 )
{
struct V_54 * V_12 =
F_6 ( V_53 , struct V_54 , V_55 ) ;
if ( V_26 )
memcpy ( & V_12 -> V_26 , V_26 , sizeof( * V_26 ) ) ;
F_33 ( & V_12 -> V_56 ) ;
}
static int F_34 ( struct V_1 * V_2 , int V_39 ,
int V_20 , int V_57 ,
int V_58 , void * V_59 )
{
struct V_6 * V_40 = F_3 ( V_2 -> V_8 ) ;
struct V_54 * V_12 ;
unsigned int V_60 ;
int V_50 = - V_61 ;
if ( V_57 == V_62 && F_35 ( V_40 ) )
return 0 ;
V_12 = F_36 ( sizeof( * V_12 ) , V_63 ) ;
if ( V_12 == NULL )
return - V_61 ;
F_37 ( & V_12 -> V_55 . V_10 ) ;
V_12 -> V_64 =
F_38 ( V_40 -> V_14 -> V_40 , & V_12 -> V_59 ,
sizeof( V_12 -> V_59 ) , V_65 ) ;
if ( F_39 ( V_40 -> V_14 -> V_40 , V_12 -> V_64 ) )
goto V_66;
V_12 -> V_16 . V_59 . V_43 = 0 ;
V_12 -> V_16 . V_59 . V_44 = F_23 ( V_12 -> V_64 ) ;
V_12 -> V_16 . V_67 = F_23 (
V_68 |
F_40 ( V_57 ) |
F_41 ( V_58 ) ) ;
V_12 -> V_16 . V_23 = F_23 (
F_42 ( sizeof( V_12 -> V_59 ) ) ) ;
V_12 -> V_16 . V_69 . V_43 =
F_23 ( V_2 -> V_70 . V_21 >> 32 ) ;
V_12 -> V_16 . V_69 . V_44 =
F_23 ( V_2 -> V_70 . V_21 ) ;
if ( V_57 == V_71 ) {
V_12 -> V_16 . V_67 |= F_23 (
F_43 ( 2 ) |
F_44 ( V_72 ) ) ;
V_60 = V_2 -> V_8 -> V_73 ;
} else {
V_60 = V_74 ;
}
F_45 ( & V_12 -> V_56 ) ;
V_12 -> V_55 . V_38 = F_32 ;
V_12 -> V_55 . V_34 =
F_38 ( V_40 -> V_14 -> V_40 , & V_12 -> V_16 ,
sizeof( V_12 -> V_16 ) , V_75 ) ;
if ( F_39 ( V_40 -> V_14 -> V_40 , V_12 -> V_55 . V_34 ) )
goto V_76;
F_22 ( & V_12 -> V_55 , V_2 , V_39 , V_20 ,
V_2 -> V_8 -> V_77 ) ;
F_46 ( & V_12 -> V_56 , F_47 ( V_60 ) ) ;
V_50 = - V_78 ;
if ( F_27 ( V_2 ) == 0 ) {
F_20 ( L_3 ,
V_2 -> V_8 -> V_79 , V_12 -> V_55 . V_35 ) ;
goto V_80;
}
if ( V_12 -> V_55 . V_35 != V_32 ) {
F_20 ( L_4 ,
V_2 -> V_8 -> V_79 , V_12 -> V_55 . V_35 ) ;
goto V_80;
}
if ( F_48 ( V_12 -> V_26 ) != 0 ||
F_49 ( V_12 -> V_26 ) != 0 ) {
F_20 ( L_5 , V_2 -> V_8 -> V_79 ,
F_48 ( V_12 -> V_26 ) ,
F_49 ( V_12 -> V_26 ) ) ;
goto V_80;
}
V_50 = 0 ;
V_80:
F_50 ( V_40 -> V_14 -> V_40 , V_12 -> V_55 . V_34 ,
sizeof( V_12 -> V_16 ) , V_75 ) ;
V_76:
F_50 ( V_40 -> V_14 -> V_40 , V_12 -> V_64 ,
sizeof( V_12 -> V_59 ) , V_65 ) ;
V_66:
if ( V_59 )
memcpy ( V_59 , V_12 -> V_59 , sizeof( V_12 -> V_59 ) ) ;
F_19 ( & V_12 -> V_55 . V_10 , F_5 ) ;
return V_50 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_6 * V_40 = F_3 ( V_2 -> V_8 ) ;
T_3 V_81 = 0 ;
F_52 ( V_40 -> V_14 , V_82 ,
V_2 -> V_8 -> V_39 , V_2 -> V_20 , V_40 -> V_46 ,
V_2 -> V_83 + V_84 ,
& V_81 , 4 ) ;
}
static void F_53 ( struct V_13 * V_14 ,
int V_35 , void * V_22 , T_1 V_23 , void * V_31 )
{
F_7 ( V_31 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_6 * V_40 = F_3 ( V_2 -> V_8 ) ;
struct V_85 * V_45 ;
static T_3 V_81 ;
V_45 = F_55 ( sizeof( * V_45 ) , V_63 ) ;
if ( V_45 == NULL )
return;
F_26 ( V_40 -> V_14 , V_45 , V_82 ,
V_2 -> V_8 -> V_39 , V_2 -> V_20 , V_40 -> V_46 ,
V_2 -> V_83 + V_84 ,
& V_81 , 4 , F_53 , V_45 ) ;
}
static inline void F_56 ( struct V_1 * V_2 )
{
-- V_2 -> V_8 -> V_86 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_13 * V_14 = F_3 ( V_8 ) -> V_14 ;
struct V_87 * V_88 =
F_6 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
unsigned long V_27 ;
F_13 ( & V_14 -> V_33 , V_27 ) ;
if ( ! V_8 -> V_86 && ! V_2 -> V_90 &&
V_2 -> V_20 != V_14 -> V_20 ) {
V_2 -> V_90 = true ;
if ( ++ V_8 -> V_90 == 1 )
F_58 ( V_88 ) ;
}
F_18 ( & V_14 -> V_33 , V_27 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_13 * V_14 = F_3 ( V_8 ) -> V_14 ;
struct V_87 * V_88 =
F_6 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
unsigned long V_27 ;
bool V_91 = false ;
F_13 ( & V_14 -> V_33 , V_27 ) ;
if ( V_2 -> V_90 && V_2 -> V_20 == V_14 -> V_20 ) {
V_2 -> V_90 = false ;
V_91 = -- V_8 -> V_90 == 0 ;
}
F_18 ( & V_14 -> V_33 , V_27 ) ;
if ( V_91 )
F_60 ( V_88 ) ;
}
static void F_61 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_3 ( V_8 ) -> V_14 ;
struct V_87 * V_88 =
F_6 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
unsigned long V_27 ;
F_13 ( & V_14 -> V_33 , V_27 ) ;
++ V_8 -> V_86 ;
F_18 ( & V_14 -> V_33 , V_27 ) ;
F_60 ( V_88 ) ;
}
static int F_62 ( T_4 V_92 )
{
struct V_93 V_94 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_93 [ 0 ] = ( V_92 >> 8 ) & 0xff ;
V_94 . V_93 [ 1 ] = V_92 & 0xff ;
return F_63 ( & V_94 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_6 * V_40 = F_3 ( V_2 -> V_8 ) ;
T_3 V_81 = F_23 ( V_95 | V_96 ) ;
F_52 ( V_40 -> V_14 , V_82 ,
V_2 -> V_8 -> V_39 , V_2 -> V_20 , V_40 -> V_46 ,
V_97 + V_98 , & V_81 , 4 ) ;
}
static void F_65 ( struct V_99 * V_5 )
{
struct V_1 * V_2 =
F_6 ( V_5 , struct V_1 , V_5 . V_5 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_6 * V_40 = F_3 ( V_8 ) ;
struct V_87 * V_88 ;
struct V_100 * V_101 ;
struct V_102 V_59 ;
int V_20 , V_39 , V_103 ;
if ( F_35 ( V_40 ) )
return;
V_20 = V_40 -> V_20 ;
F_66 () ;
V_39 = V_40 -> V_39 ;
V_103 = V_40 -> V_14 -> V_39 ;
if ( V_2 -> V_104 )
F_34 ( V_2 , V_40 -> V_39 , V_20 ,
V_62 , V_2 -> V_105 , NULL ) ;
if ( F_34 ( V_2 , V_39 , V_20 ,
V_71 , V_2 -> V_92 , & V_59 ) < 0 ) {
if ( V_2 -> V_106 ++ < 5 ) {
F_1 ( V_2 , F_67 ( V_107 , 5 ) ) ;
} else {
F_20 ( L_6 ,
V_8 -> V_79 , V_2 -> V_92 ) ;
F_61 ( V_2 -> V_8 ) ;
}
return;
}
V_8 -> V_39 = V_39 ;
V_8 -> V_108 = V_103 << 16 ;
F_68 () ;
V_2 -> V_20 = V_20 ;
V_2 -> V_83 =
( ( T_2 ) ( F_69 ( V_59 . V_109 . V_43 ) & 0xffff )
<< 32 ) | F_69 ( V_59 . V_109 . V_44 ) ;
V_2 -> V_105 = F_69 ( V_59 . V_67 ) & 0xffff ;
F_12 ( L_7 ,
V_8 -> V_79 , V_2 -> V_92 , V_2 -> V_106 ) ;
F_64 ( V_2 ) ;
F_70 ( & V_2 -> V_5 , V_110 ) ;
F_51 ( V_2 ) ;
if ( V_2 -> V_104 ) {
F_27 ( V_2 ) ;
F_59 ( V_2 ) ;
return;
}
if ( V_2 -> V_8 -> V_111 & V_112 )
F_71 ( V_113 ) ;
V_88 = F_6 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
V_101 = F_72 ( V_88 , 0 , 0 , F_62 ( V_2 -> V_92 ) , V_2 ) ;
if ( F_73 ( V_101 ) )
goto V_114;
F_66 () ;
if ( V_20 != V_40 -> V_14 -> V_20 ) {
F_74 ( V_101 ) ;
F_75 ( V_101 ) ;
goto V_114;
}
V_2 -> V_104 = true ;
F_75 ( V_101 ) ;
F_56 ( V_2 ) ;
return;
V_114:
F_66 () ;
V_20 = V_40 -> V_20 ;
F_66 () ;
F_34 ( V_2 , V_40 -> V_39 , V_20 ,
V_62 , V_2 -> V_105 , NULL ) ;
F_70 ( & V_2 -> V_5 , F_65 ) ;
}
static void V_110 ( struct V_99 * V_5 )
{
struct V_1 * V_2 =
F_6 ( V_5 , struct V_1 , V_5 . V_5 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_6 * V_40 = F_3 ( V_8 ) ;
int V_20 , V_39 , V_103 ;
if ( F_35 ( V_40 ) )
return;
V_20 = V_40 -> V_20 ;
F_66 () ;
V_39 = V_40 -> V_39 ;
V_103 = V_40 -> V_14 -> V_39 ;
if ( F_34 ( V_2 , V_39 , V_20 ,
V_115 ,
V_2 -> V_105 , NULL ) < 0 ) {
F_66 () ;
if ( V_20 == V_40 -> V_14 -> V_20 ||
V_2 -> V_106 ++ >= 5 ) {
F_20 ( L_8 , V_8 -> V_79 ) ;
V_2 -> V_106 = 0 ;
F_70 ( & V_2 -> V_5 , F_65 ) ;
}
F_1 ( V_2 , F_67 ( V_107 , 5 ) ) ;
return;
}
V_8 -> V_39 = V_39 ;
V_8 -> V_108 = V_103 << 16 ;
F_68 () ;
V_2 -> V_20 = V_20 ;
F_12 ( L_9 ,
V_8 -> V_79 , V_2 -> V_92 , V_2 -> V_106 ) ;
F_51 ( V_2 ) ;
F_27 ( V_2 ) ;
F_59 ( V_2 ) ;
}
static int F_76 ( struct V_7 * V_8 , int V_116 )
{
struct V_1 * V_2 ;
V_2 = F_55 ( sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 )
return - V_61 ;
V_2 -> V_70 . V_23 = 0x100 ;
V_2 -> V_70 . V_118 = F_8 ;
V_2 -> V_70 . V_24 = V_2 ;
if ( F_77 ( & V_2 -> V_70 ,
& V_119 ) < 0 ) {
F_7 ( V_2 ) ;
return - V_61 ;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_92 = V_116 & 0xffff ;
V_2 -> V_105 = V_120 ;
V_2 -> V_106 = 0 ;
V_2 -> V_104 = false ;
V_2 -> V_90 = false ;
++ V_8 -> V_86 ;
F_28 ( & V_2 -> V_37 ) ;
F_78 ( & V_2 -> V_5 , F_65 ) ;
F_24 ( & V_2 -> V_36 , & V_8 -> V_121 ) ;
return 0 ;
}
static int F_79 ( struct V_7 * V_8 ,
const T_5 * V_122 )
{
struct V_123 V_124 ;
int V_125 , V_126 ;
F_80 ( & V_124 , V_122 ) ;
while ( F_81 ( & V_124 , & V_125 , & V_126 ) )
if ( V_125 == V_127 &&
F_76 ( V_8 , V_126 ) < 0 )
return - V_61 ;
return 0 ;
}
static int F_82 ( struct V_7 * V_8 , const T_5 * V_122 ,
T_5 * V_128 , T_5 * V_129 )
{
struct V_123 V_124 ;
int V_125 , V_126 ;
F_80 ( & V_124 , V_122 ) ;
while ( F_81 ( & V_124 , & V_125 , & V_126 ) ) {
switch ( V_125 ) {
case V_130 | V_131 :
V_8 -> V_77 =
V_97 + 4 * V_126 ;
break;
case V_132 :
V_8 -> V_133 = V_126 ;
break;
case V_134 :
* V_128 = V_126 ;
break;
case V_135 :
* V_129 = V_126 ;
break;
case V_136 :
V_8 -> V_73 = ( V_126 >> 8 & 0xff ) * 500 ;
break;
case V_127 :
if ( F_76 ( V_8 , V_126 ) < 0 )
return - V_61 ;
break;
case V_137 :
if ( F_79 ( V_8 , V_124 . V_138 - 1 + V_126 ) < 0 )
return - V_61 ;
break;
}
}
return 0 ;
}
static void F_83 ( struct V_7 * V_8 )
{
unsigned int V_60 = V_8 -> V_73 ;
if ( V_60 > 40000 )
F_12 ( L_10 ,
V_8 -> V_79 , V_60 / 1000 ) ;
V_8 -> V_73 = F_84 ( V_60 , 5000 , 40000 ) ;
}
static void F_85 ( struct V_7 * V_8 , T_5 V_128 ,
T_5 V_129 )
{
int V_139 ;
unsigned int V_140 = V_141 ;
if ( V_140 )
F_12 ( L_11
L_12 ,
V_8 -> V_79 ) ;
if ( V_140 & V_142 )
goto V_80;
for ( V_139 = 0 ; V_139 < F_86 ( V_143 ) ; V_139 ++ ) {
if ( V_143 [ V_139 ] . V_129 !=
( V_129 & 0xffffff00 ) )
continue;
if ( V_143 [ V_139 ] . V_128 != V_128 &&
V_143 [ V_139 ] . V_128 != V_144 )
continue;
V_140 |= V_143 [ V_139 ] . V_111 ;
break;
}
V_80:
if ( V_140 )
F_12 ( L_13
L_14 ,
V_8 -> V_79 , V_140 , V_129 , V_128 ) ;
V_8 -> V_111 = V_140 ;
}
static int F_87 ( struct V_40 * V_145 )
{
struct V_146 * V_9 = V_146 ( V_145 ) ;
struct V_6 * V_40 = F_4 ( V_9 ) ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_87 * V_88 ;
T_5 V_128 , V_129 ;
if ( F_88 ( V_40 -> V_14 -> V_40 ) > V_147 )
F_89 ( F_90 ( V_40 -> V_14 -> V_40 ,
V_147 ) ) ;
V_88 = F_91 ( & V_148 , sizeof( * V_8 ) ) ;
if ( V_88 == NULL )
return - V_61 ;
V_8 = (struct V_7 * ) V_88 -> V_89 ;
F_92 ( & V_9 -> V_40 , V_8 ) ;
V_8 -> V_9 = V_9 ;
F_28 ( & V_8 -> V_121 ) ;
V_8 -> V_79 = F_93 ( & V_9 -> V_40 ) ;
V_8 -> V_149 = ( T_2 ) V_40 -> V_150 [ 3 ] << 32 | V_40 -> V_150 [ 4 ] ;
if ( F_94 ( V_40 ) < 0 )
goto V_151;
V_88 -> V_152 = V_153 ;
if ( F_95 ( V_88 , & V_9 -> V_40 ) < 0 )
goto V_151;
V_8 -> V_133 = ( ( V_9 -> V_122 - V_40 -> V_150 ) * 4
+ V_154 ) & 0xffffff ;
V_129 = V_155 ;
V_128 = V_155 ;
if ( F_82 ( V_8 , V_9 -> V_122 , & V_128 ,
& V_129 ) < 0 )
goto V_156;
F_83 ( V_8 ) ;
F_85 ( V_8 , V_128 , V_129 ) ;
V_8 -> V_157 = F_96 ( V_40 -> V_46 + 7 , 10U ,
V_40 -> V_14 -> V_158 - 1 ) ;
F_14 (lu, &tgt->lu_list, link)
F_1 ( V_2 , F_67 ( V_107 , 5 ) ) ;
return 0 ;
V_156:
F_97 ( V_145 ) ;
return - V_61 ;
V_151:
F_98 ( V_88 ) ;
return - V_61 ;
}
static void F_99 ( struct V_146 * V_9 )
{
struct V_7 * V_8 = F_100 ( & V_9 -> V_40 ) ;
struct V_1 * V_2 ;
F_94 ( F_4 ( V_9 ) ) ;
F_14 (lu, &tgt->lu_list, link) {
F_57 ( V_2 ) ;
V_2 -> V_106 = 0 ;
F_1 ( V_2 , 0 ) ;
}
}
static int F_97 ( struct V_40 * V_145 )
{
struct V_146 * V_9 = V_146 ( V_145 ) ;
struct V_6 * V_40 = F_4 ( V_9 ) ;
struct V_7 * V_8 = F_100 ( & V_9 -> V_40 ) ;
struct V_1 * V_2 , * V_47 ;
struct V_87 * V_88 =
F_6 ( ( void * ) V_8 , struct V_87 , V_89 [ 0 ] ) ;
struct V_100 * V_101 ;
F_61 ( V_8 ) ;
F_30 (lu, next, &tgt->lu_list, link) {
F_101 ( & V_2 -> V_5 ) ;
V_101 = F_102 ( V_88 , 0 , 0 , F_62 ( V_2 -> V_92 ) ) ;
if ( V_101 ) {
F_74 ( V_101 ) ;
F_75 ( V_101 ) ;
}
if ( V_2 -> V_105 != V_120 ) {
int V_20 , V_39 ;
V_20 = V_40 -> V_20 ;
F_66 () ;
V_39 = V_40 -> V_39 ;
F_34 ( V_2 , V_39 , V_20 ,
V_62 ,
V_2 -> V_105 , NULL ) ;
}
F_103 ( & V_2 -> V_70 ) ;
F_17 ( & V_2 -> V_36 ) ;
F_7 ( V_2 ) ;
}
F_104 ( V_88 ) ;
F_12 ( L_15 , V_8 -> V_79 , V_88 -> V_159 ) ;
F_98 ( V_88 ) ;
return 0 ;
}
static void F_105 ( struct V_40 * V_160 ,
struct V_161 * V_12 )
{
if ( F_106 ( V_12 -> V_162 ) )
F_107 ( V_160 , F_108 ( V_12 -> V_162 ) ,
F_106 ( V_12 -> V_162 ) ,
V_12 -> V_162 -> V_163 ) ;
if ( V_12 -> V_16 . V_67 & F_23 ( V_164 ) )
F_50 ( V_160 , V_12 -> V_165 ,
sizeof( V_12 -> V_166 ) , V_75 ) ;
}
static unsigned int F_109 ( T_6 * V_25 , T_6 * V_167 )
{
int V_168 ;
V_167 [ 0 ] = 0x70 ;
V_167 [ 1 ] = 0x0 ;
V_167 [ 2 ] = V_25 [ 1 ] ;
V_167 [ 3 ] = V_25 [ 4 ] ;
V_167 [ 4 ] = V_25 [ 5 ] ;
V_167 [ 5 ] = V_25 [ 6 ] ;
V_167 [ 6 ] = V_25 [ 7 ] ;
V_167 [ 7 ] = 10 ;
V_167 [ 8 ] = V_25 [ 8 ] ;
V_167 [ 9 ] = V_25 [ 9 ] ;
V_167 [ 10 ] = V_25 [ 10 ] ;
V_167 [ 11 ] = V_25 [ 11 ] ;
V_167 [ 12 ] = V_25 [ 2 ] ;
V_167 [ 13 ] = V_25 [ 3 ] ;
V_167 [ 14 ] = V_25 [ 12 ] ;
V_167 [ 15 ] = V_25 [ 13 ] ;
V_168 = V_25 [ 0 ] & 0x3f ;
switch ( V_168 ) {
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
return V_175 << 16 | V_168 ;
default:
return V_176 << 16 ;
}
}
static void F_110 ( struct V_11 * V_53 ,
struct V_25 * V_26 )
{
struct V_161 * V_12 =
F_6 ( V_53 , struct V_161 , V_55 ) ;
struct V_6 * V_40 = F_3 ( V_12 -> V_2 -> V_8 ) ;
int V_177 ;
if ( V_26 != NULL ) {
if ( F_111 ( * V_26 ) )
F_54 ( V_12 -> V_2 ) ;
switch ( F_48 ( * V_26 ) ) {
case V_178 :
V_177 = V_175 << 16 ;
break;
case V_179 :
V_177 = V_180 << 16 ;
break;
case V_181 :
case V_182 :
default:
V_177 = V_176 << 16 ;
break;
}
if ( V_177 == V_175 << 16 && F_112 ( * V_26 ) > 1 )
V_177 = F_109 ( F_113 ( * V_26 ) ,
V_12 -> V_162 -> V_183 ) ;
} else {
V_177 = V_180 << 16 ;
F_57 ( V_12 -> V_2 ) ;
}
F_50 ( V_40 -> V_14 -> V_40 , V_12 -> V_55 . V_34 ,
sizeof( V_12 -> V_16 ) , V_75 ) ;
F_105 ( V_40 -> V_14 -> V_40 , V_12 ) ;
V_12 -> V_162 -> V_177 = V_177 ;
V_12 -> V_162 -> V_184 ( V_12 -> V_162 ) ;
}
static int F_114 ( struct V_161 * V_12 ,
struct V_6 * V_40 , struct V_1 * V_2 )
{
struct V_185 * V_186 = F_108 ( V_12 -> V_162 ) ;
int V_139 , V_187 ;
V_187 = F_115 ( V_40 -> V_14 -> V_40 , V_186 , F_106 ( V_12 -> V_162 ) ,
V_12 -> V_162 -> V_163 ) ;
if ( V_187 == 0 )
goto V_188;
if ( V_187 == 1 ) {
V_12 -> V_16 . V_189 . V_43 =
F_23 ( V_2 -> V_8 -> V_108 ) ;
V_12 -> V_16 . V_189 . V_44 =
F_23 ( F_116 ( V_186 ) ) ;
V_12 -> V_16 . V_67 |=
F_23 ( F_117 ( F_118 ( V_186 ) ) ) ;
return 0 ;
}
F_119 (sg, sg, n, i) {
V_12 -> V_166 [ V_139 ] . V_43 = F_23 ( F_118 ( V_186 ) << 16 ) ;
V_12 -> V_166 [ V_139 ] . V_44 = F_23 ( F_116 ( V_186 ) ) ;
}
V_12 -> V_165 =
F_38 ( V_40 -> V_14 -> V_40 , V_12 -> V_166 ,
sizeof( V_12 -> V_166 ) , V_75 ) ;
if ( F_39 ( V_40 -> V_14 -> V_40 , V_12 -> V_165 ) )
goto V_190;
V_12 -> V_16 . V_189 . V_43 = F_23 ( V_2 -> V_8 -> V_108 ) ;
V_12 -> V_16 . V_189 . V_44 = F_23 ( V_12 -> V_165 ) ;
V_12 -> V_16 . V_67 |= F_23 ( V_164 |
F_117 ( V_187 ) ) ;
return 0 ;
V_190:
F_107 ( V_40 -> V_14 -> V_40 , F_108 ( V_12 -> V_162 ) ,
F_106 ( V_12 -> V_162 ) , V_12 -> V_162 -> V_163 ) ;
V_188:
return - V_61 ;
}
static int F_120 ( struct V_87 * V_88 ,
struct V_191 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_40 -> V_89 ;
struct V_6 * V_40 = F_3 ( V_2 -> V_8 ) ;
struct V_161 * V_12 ;
int V_20 , V_50 = V_192 ;
if ( V_162 -> V_163 == V_193 ) {
F_20 ( L_16 ) ;
V_162 -> V_177 = V_176 << 16 ;
V_162 -> V_184 ( V_162 ) ;
return 0 ;
}
V_12 = F_36 ( sizeof( * V_12 ) , V_63 ) ;
if ( V_12 == NULL ) {
F_12 ( L_17 ) ;
return V_192 ;
}
V_12 -> V_55 . V_35 = - 1 ;
F_37 ( & V_12 -> V_55 . V_10 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_162 = V_162 ;
V_12 -> V_16 . V_47 . V_43 = F_23 ( V_194 ) ;
V_12 -> V_16 . V_67 = F_23 (
F_121 ( V_2 -> V_8 -> V_157 ) |
F_122 ( V_40 -> V_46 ) |
V_195 ) ;
if ( V_162 -> V_163 == V_65 )
V_12 -> V_16 . V_67 |= F_23 ( V_196 ) ;
V_20 = V_40 -> V_20 ;
F_66 () ;
if ( F_106 ( V_162 ) && F_114 ( V_12 , V_40 , V_2 ) < 0 )
goto V_80;
memcpy ( V_12 -> V_16 . V_197 , V_162 -> V_198 , V_162 -> V_199 ) ;
V_12 -> V_55 . V_38 = F_110 ;
V_12 -> V_55 . V_34 =
F_38 ( V_40 -> V_14 -> V_40 , & V_12 -> V_16 ,
sizeof( V_12 -> V_16 ) , V_75 ) ;
if ( F_39 ( V_40 -> V_14 -> V_40 , V_12 -> V_55 . V_34 ) ) {
F_105 ( V_40 -> V_14 -> V_40 , V_12 ) ;
goto V_80;
}
F_22 ( & V_12 -> V_55 , V_2 , V_2 -> V_8 -> V_39 , V_20 ,
V_2 -> V_83 + V_200 ) ;
V_50 = 0 ;
V_80:
F_19 ( & V_12 -> V_55 . V_10 , F_5 ) ;
return V_50 ;
}
static int F_123 ( struct V_100 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_89 ;
if ( ! V_2 )
return - V_201 ;
V_101 -> V_202 = 1 ;
F_124 ( V_101 -> V_203 , 4 - 1 ) ;
if ( V_2 -> V_8 -> V_111 & V_204 )
V_101 -> V_205 = 36 ;
return 0 ;
}
static int F_125 ( struct V_100 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_89 ;
V_101 -> V_206 = 1 ;
if ( V_72 )
V_101 -> V_207 = 1 ;
if ( V_101 -> type == V_208 )
V_101 -> V_209 = 1 ;
if ( V_101 -> type == V_210 &&
V_2 -> V_8 -> V_111 & V_211 )
V_101 -> V_212 = 1 ;
if ( V_2 -> V_8 -> V_111 & V_213 )
V_101 -> V_214 = 1 ;
if ( V_2 -> V_8 -> V_111 & V_215 )
V_101 -> V_216 = 1 ;
if ( V_2 -> V_8 -> V_111 & V_217 )
F_126 ( V_101 -> V_203 , 128 * 1024 / 512 ) ;
F_127 ( V_101 -> V_203 , V_147 ) ;
return 0 ;
}
static int F_128 ( struct V_191 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_40 -> V_89 ;
F_12 ( L_18 , V_2 -> V_8 -> V_79 ) ;
F_51 ( V_2 ) ;
F_27 ( V_2 ) ;
return V_218 ;
}
static T_7 F_129 ( struct V_40 * V_145 ,
struct V_219 * V_220 , char * V_221 )
{
struct V_100 * V_101 = F_130 ( V_145 ) ;
struct V_1 * V_2 ;
if ( ! V_101 )
return 0 ;
V_2 = V_101 -> V_89 ;
return sprintf ( V_221 , L_19 ,
( unsigned long long ) V_2 -> V_8 -> V_149 ,
V_2 -> V_8 -> V_133 , V_2 -> V_92 ) ;
}
static int T_8 F_131 ( void )
{
return F_132 ( & V_222 . V_223 ) ;
}
static void T_9 F_133 ( void )
{
F_134 ( & V_222 . V_223 ) ;
}
