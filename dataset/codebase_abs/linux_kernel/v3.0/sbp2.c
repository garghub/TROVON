static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static void F_3 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 , struct V_6 , V_5 ) ;
F_5 ( V_7 ) ;
}
static void F_6 ( struct V_8 * V_9 , struct V_10 * V_11 ,
int V_12 , int V_13 , int V_14 ,
int V_15 , unsigned long long V_16 ,
void * V_17 , T_1 V_18 , void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_6 * V_7 ;
struct V_22 V_23 ;
unsigned long V_24 ;
if ( V_12 != V_25 ||
V_18 < 8 || V_18 > sizeof( V_23 ) ) {
F_7 ( V_9 , V_11 , V_26 ) ;
return;
}
V_23 . V_23 = F_8 ( V_17 ) ;
V_23 . V_27 = F_8 ( V_17 + 4 ) ;
memset ( V_23 . V_28 , 0 , sizeof( V_23 . V_28 ) ) ;
if ( V_18 > 8 )
memcpy ( V_23 . V_28 , V_17 + 8 , V_18 - 8 ) ;
if ( F_9 ( V_23 ) == 2 || F_9 ( V_23 ) == 3 ) {
F_10 ( L_1 ) ;
F_7 ( V_9 , V_11 , V_29 ) ;
return;
}
F_11 ( & V_9 -> V_30 , V_24 ) ;
F_12 (orb, &lu->orb_list, link) {
if ( F_13 ( V_23 ) == 0 &&
F_14 ( V_23 ) == V_7 -> V_31 ) {
V_7 -> V_32 = V_29 ;
F_15 ( & V_7 -> V_33 ) ;
break;
}
}
F_16 ( & V_9 -> V_30 , V_24 ) ;
if ( & V_7 -> V_33 != & V_21 -> V_34 ) {
V_7 -> V_35 ( V_7 , & V_23 ) ;
F_17 ( & V_7 -> V_5 , F_3 ) ;
} else {
F_18 ( L_2 ) ;
}
F_7 ( V_9 , V_11 , V_29 ) ;
}
static void F_19 ( struct V_8 * V_9 , int V_32 ,
void * V_17 , T_1 V_18 , void * V_28 )
{
struct V_6 * V_7 = V_28 ;
unsigned long V_24 ;
F_11 ( & V_9 -> V_30 , V_24 ) ;
if ( V_7 -> V_32 == - 1 )
V_7 -> V_32 = V_32 ;
if ( V_7 -> V_32 != V_29 ) {
F_15 ( & V_7 -> V_33 ) ;
F_16 ( & V_9 -> V_30 , V_24 ) ;
V_7 -> V_35 ( V_7 , NULL ) ;
F_17 ( & V_7 -> V_5 , F_3 ) ;
} else {
F_16 ( & V_9 -> V_30 , V_24 ) ;
}
F_17 ( & V_7 -> V_5 , F_3 ) ;
}
static void F_20 ( struct V_6 * V_7 , struct V_20 * V_21 ,
int V_36 , int V_15 , T_2 V_16 )
{
struct V_1 * V_37 = F_1 ( V_21 -> V_3 ) ;
struct V_38 V_39 ;
unsigned long V_24 ;
V_39 . V_40 = 0 ;
V_39 . V_41 = F_21 ( V_7 -> V_31 ) ;
F_11 ( & V_37 -> V_9 -> V_30 , V_24 ) ;
F_22 ( & V_7 -> V_33 , & V_21 -> V_34 ) ;
F_16 ( & V_37 -> V_9 -> V_30 , V_24 ) ;
F_23 ( & V_7 -> V_5 ) ;
F_23 ( & V_7 -> V_5 ) ;
F_24 ( V_37 -> V_9 , & V_7 -> V_42 , V_25 ,
V_36 , V_15 , V_37 -> V_43 , V_16 ,
& V_39 , 8 , F_19 , V_7 ) ;
}
static int F_25 ( struct V_20 * V_21 )
{
struct V_1 * V_37 = F_1 ( V_21 -> V_3 ) ;
struct V_6 * V_7 , * V_44 ;
struct V_45 V_46 ;
unsigned long V_24 ;
int V_47 = - V_48 ;
F_26 ( & V_46 ) ;
F_11 ( & V_37 -> V_9 -> V_30 , V_24 ) ;
F_27 ( & V_21 -> V_34 , & V_46 ) ;
F_16 ( & V_37 -> V_9 -> V_30 , V_24 ) ;
F_28 (orb, next, &list, link) {
V_47 = 0 ;
if ( F_29 ( V_37 -> V_9 , & V_7 -> V_42 ) == 0 )
continue;
V_7 -> V_32 = V_49 ;
V_7 -> V_35 ( V_7 , NULL ) ;
F_17 ( & V_7 -> V_5 , F_3 ) ;
}
return V_47 ;
}
static void F_30 ( struct V_6 * V_50 ,
struct V_22 * V_23 )
{
struct V_51 * V_7 =
F_4 ( V_50 , struct V_51 , V_52 ) ;
if ( V_23 )
memcpy ( & V_7 -> V_23 , V_23 , sizeof( * V_23 ) ) ;
F_31 ( & V_7 -> V_53 ) ;
}
static int F_32 ( struct V_20 * V_21 , int V_36 ,
int V_15 , int V_54 ,
int V_55 , void * V_56 )
{
struct V_1 * V_37 = F_1 ( V_21 -> V_3 ) ;
struct V_51 * V_7 ;
unsigned int V_57 ;
int V_47 = - V_58 ;
if ( V_54 == V_59 && F_33 ( V_37 ) )
return 0 ;
V_7 = F_34 ( sizeof( * V_7 ) , V_60 ) ;
if ( V_7 == NULL )
return - V_58 ;
F_35 ( & V_7 -> V_52 . V_5 ) ;
V_7 -> V_61 =
F_36 ( V_37 -> V_9 -> V_37 , & V_7 -> V_56 ,
sizeof( V_7 -> V_56 ) , V_62 ) ;
if ( F_37 ( V_37 -> V_9 -> V_37 , V_7 -> V_61 ) )
goto V_63;
V_7 -> V_11 . V_56 . V_40 = 0 ;
V_7 -> V_11 . V_56 . V_41 = F_21 ( V_7 -> V_61 ) ;
V_7 -> V_11 . V_64 = F_21 (
V_65 |
F_38 ( V_54 ) |
F_39 ( V_55 ) ) ;
V_7 -> V_11 . V_18 = F_21 (
F_40 ( sizeof( V_7 -> V_56 ) ) ) ;
V_7 -> V_11 . V_66 . V_40 =
F_21 ( V_21 -> V_67 . V_16 >> 32 ) ;
V_7 -> V_11 . V_66 . V_41 =
F_21 ( V_21 -> V_67 . V_16 ) ;
if ( V_54 == V_68 ) {
V_7 -> V_11 . V_64 |= F_21 (
F_41 ( 2 ) |
F_42 ( V_69 ) ) ;
V_57 = V_21 -> V_3 -> V_70 ;
} else {
V_57 = V_71 ;
}
F_43 ( & V_7 -> V_53 ) ;
V_7 -> V_52 . V_35 = F_30 ;
V_7 -> V_52 . V_31 =
F_36 ( V_37 -> V_9 -> V_37 , & V_7 -> V_11 ,
sizeof( V_7 -> V_11 ) , V_72 ) ;
if ( F_37 ( V_37 -> V_9 -> V_37 , V_7 -> V_52 . V_31 ) )
goto V_73;
F_20 ( & V_7 -> V_52 , V_21 , V_36 , V_15 ,
V_21 -> V_3 -> V_74 ) ;
F_44 ( & V_7 -> V_53 , F_45 ( V_57 ) ) ;
V_47 = - V_75 ;
if ( F_25 ( V_21 ) == 0 ) {
F_18 ( L_3 ,
V_21 -> V_3 -> V_76 , V_7 -> V_52 . V_32 ) ;
goto V_77;
}
if ( V_7 -> V_52 . V_32 != V_29 ) {
F_18 ( L_4 ,
V_21 -> V_3 -> V_76 , V_7 -> V_52 . V_32 ) ;
goto V_77;
}
if ( F_46 ( V_7 -> V_23 ) != 0 ||
F_47 ( V_7 -> V_23 ) != 0 ) {
F_18 ( L_5 , V_21 -> V_3 -> V_76 ,
F_46 ( V_7 -> V_23 ) ,
F_47 ( V_7 -> V_23 ) ) ;
goto V_77;
}
V_47 = 0 ;
V_77:
F_48 ( V_37 -> V_9 -> V_37 , V_7 -> V_52 . V_31 ,
sizeof( V_7 -> V_11 ) , V_72 ) ;
V_73:
F_48 ( V_37 -> V_9 -> V_37 , V_7 -> V_61 ,
sizeof( V_7 -> V_56 ) , V_62 ) ;
V_63:
if ( V_56 )
memcpy ( V_56 , V_7 -> V_56 , sizeof( V_7 -> V_56 ) ) ;
F_17 ( & V_7 -> V_52 . V_5 , F_3 ) ;
return V_47 ;
}
static void F_49 ( struct V_20 * V_21 )
{
struct V_1 * V_37 = F_1 ( V_21 -> V_3 ) ;
T_3 V_78 = 0 ;
F_50 ( V_37 -> V_9 , V_79 ,
V_21 -> V_3 -> V_36 , V_21 -> V_15 , V_37 -> V_43 ,
V_21 -> V_80 + V_81 ,
& V_78 , 4 ) ;
}
static void F_51 ( struct V_8 * V_9 ,
int V_32 , void * V_17 , T_1 V_18 , void * V_28 )
{
F_5 ( V_28 ) ;
}
static void F_52 ( struct V_20 * V_21 )
{
struct V_1 * V_37 = F_1 ( V_21 -> V_3 ) ;
struct V_82 * V_42 ;
static T_3 V_78 ;
V_42 = F_53 ( sizeof( * V_42 ) , V_60 ) ;
if ( V_42 == NULL )
return;
F_24 ( V_37 -> V_9 , V_42 , V_79 ,
V_21 -> V_3 -> V_36 , V_21 -> V_15 , V_37 -> V_43 ,
V_21 -> V_80 + V_81 ,
& V_78 , 4 , F_51 , V_42 ) ;
}
static inline void F_54 ( struct V_20 * V_21 )
{
-- V_21 -> V_3 -> V_83 ;
}
static void F_55 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = V_21 -> V_3 ;
struct V_8 * V_9 = F_1 ( V_3 ) -> V_9 ;
struct V_84 * V_85 =
F_4 ( ( void * ) V_3 , struct V_84 , V_86 [ 0 ] ) ;
unsigned long V_24 ;
F_11 ( & V_9 -> V_30 , V_24 ) ;
if ( ! V_3 -> V_83 && ! V_21 -> V_87 &&
V_21 -> V_15 != V_9 -> V_15 ) {
V_21 -> V_87 = true ;
if ( ++ V_3 -> V_87 == 1 )
F_56 ( V_85 ) ;
}
F_16 ( & V_9 -> V_30 , V_24 ) ;
}
static void F_57 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = V_21 -> V_3 ;
struct V_8 * V_9 = F_1 ( V_3 ) -> V_9 ;
struct V_84 * V_85 =
F_4 ( ( void * ) V_3 , struct V_84 , V_86 [ 0 ] ) ;
unsigned long V_24 ;
bool V_88 = false ;
F_11 ( & V_9 -> V_30 , V_24 ) ;
if ( V_21 -> V_87 && V_21 -> V_15 == V_9 -> V_15 ) {
V_21 -> V_87 = false ;
V_88 = -- V_3 -> V_87 == 0 ;
}
F_16 ( & V_9 -> V_30 , V_24 ) ;
if ( V_88 )
F_58 ( V_85 ) ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_1 ( V_3 ) -> V_9 ;
struct V_84 * V_85 =
F_4 ( ( void * ) V_3 , struct V_84 , V_86 [ 0 ] ) ;
unsigned long V_24 ;
F_11 ( & V_9 -> V_30 , V_24 ) ;
++ V_3 -> V_83 ;
F_16 ( & V_9 -> V_30 , V_24 ) ;
F_58 ( V_85 ) ;
}
static int F_60 ( T_4 V_89 )
{
struct V_90 V_91 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_90 [ 0 ] = ( V_89 >> 8 ) & 0xff ;
V_91 . V_90 [ 1 ] = V_89 & 0xff ;
return F_61 ( & V_91 ) ;
}
static void F_62 ( struct V_5 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 , struct V_2 , V_5 ) ;
struct V_20 * V_21 , * V_44 ;
struct V_84 * V_85 =
F_4 ( ( void * ) V_3 , struct V_84 , V_86 [ 0 ] ) ;
struct V_92 * V_93 ;
struct V_1 * V_37 = F_1 ( V_3 ) ;
F_59 ( V_3 ) ;
F_28 (lu, next, &tgt->lu_list, link) {
V_93 = F_63 ( V_85 , 0 , 0 , F_60 ( V_21 -> V_89 ) ) ;
if ( V_93 ) {
F_64 ( V_93 ) ;
F_65 ( V_93 ) ;
}
if ( V_21 -> V_94 != V_95 ) {
int V_15 , V_36 ;
V_15 = V_37 -> V_15 ;
F_66 () ;
V_36 = V_37 -> V_36 ;
F_32 ( V_21 , V_36 , V_15 ,
V_59 ,
V_21 -> V_94 , NULL ) ;
}
F_67 ( & V_21 -> V_67 ) ;
F_15 ( & V_21 -> V_33 ) ;
F_5 ( V_21 ) ;
}
F_68 ( V_85 ) ;
F_10 ( L_6 , V_3 -> V_76 , V_85 -> V_96 ) ;
F_69 ( V_3 -> V_4 ) ;
F_70 ( V_85 ) ;
F_71 ( V_37 ) ;
}
static void F_72 ( struct V_2 * V_3 )
{
F_23 ( & V_3 -> V_5 ) ;
}
static void F_73 ( struct V_2 * V_3 )
{
F_17 ( & V_3 -> V_5 , F_62 ) ;
}
static void F_74 ( struct V_20 * V_21 , unsigned long V_97 )
{
F_72 ( V_21 -> V_3 ) ;
if ( ! F_75 ( V_98 , & V_21 -> V_99 , V_97 ) )
F_73 ( V_21 -> V_3 ) ;
}
static void F_76 ( struct V_20 * V_21 )
{
struct V_1 * V_37 = F_1 ( V_21 -> V_3 ) ;
T_3 V_78 = F_21 ( V_100 | V_101 ) ;
F_50 ( V_37 -> V_9 , V_79 ,
V_21 -> V_3 -> V_36 , V_21 -> V_15 , V_37 -> V_43 ,
V_102 + V_103 , & V_78 , 4 ) ;
}
static void F_77 ( struct V_104 * V_99 )
{
struct V_20 * V_21 =
F_4 ( V_99 , struct V_20 , V_99 . V_99 ) ;
struct V_2 * V_3 = V_21 -> V_3 ;
struct V_1 * V_37 = F_1 ( V_3 ) ;
struct V_84 * V_85 ;
struct V_92 * V_93 ;
struct V_105 V_56 ;
int V_15 , V_36 , V_106 ;
if ( F_33 ( V_37 ) )
goto V_77;
V_15 = V_37 -> V_15 ;
F_66 () ;
V_36 = V_37 -> V_36 ;
V_106 = V_37 -> V_9 -> V_36 ;
if ( V_21 -> V_107 )
F_32 ( V_21 , V_37 -> V_36 , V_15 ,
V_59 , V_21 -> V_94 , NULL ) ;
if ( F_32 ( V_21 , V_36 , V_15 ,
V_68 , V_21 -> V_89 , & V_56 ) < 0 ) {
if ( V_21 -> V_108 ++ < 5 ) {
F_74 ( V_21 , F_78 ( V_109 , 5 ) ) ;
} else {
F_18 ( L_7 ,
V_3 -> V_76 , V_21 -> V_89 ) ;
F_59 ( V_21 -> V_3 ) ;
}
goto V_77;
}
V_3 -> V_36 = V_36 ;
V_3 -> V_110 = V_106 << 16 ;
F_79 () ;
V_21 -> V_15 = V_15 ;
V_21 -> V_80 =
( ( T_2 ) ( F_80 ( V_56 . V_111 . V_40 ) & 0xffff )
<< 32 ) | F_80 ( V_56 . V_111 . V_41 ) ;
V_21 -> V_94 = F_80 ( V_56 . V_64 ) & 0xffff ;
F_10 ( L_8 ,
V_3 -> V_76 , V_21 -> V_89 , V_21 -> V_108 ) ;
F_76 ( V_21 ) ;
F_81 ( & V_21 -> V_99 , V_112 ) ;
F_49 ( V_21 ) ;
if ( V_21 -> V_107 ) {
F_25 ( V_21 ) ;
F_57 ( V_21 ) ;
goto V_77;
}
if ( V_21 -> V_3 -> V_113 & V_114 )
F_82 ( V_115 ) ;
V_85 = F_4 ( ( void * ) V_3 , struct V_84 , V_86 [ 0 ] ) ;
V_93 = F_83 ( V_85 , 0 , 0 , F_60 ( V_21 -> V_89 ) , V_21 ) ;
if ( F_84 ( V_93 ) )
goto V_116;
F_66 () ;
if ( V_15 != V_37 -> V_9 -> V_15 ) {
F_64 ( V_93 ) ;
F_65 ( V_93 ) ;
goto V_116;
}
V_21 -> V_107 = true ;
F_65 ( V_93 ) ;
F_54 ( V_21 ) ;
goto V_77;
V_116:
F_66 () ;
V_15 = V_37 -> V_15 ;
F_66 () ;
F_32 ( V_21 , V_37 -> V_36 , V_15 ,
V_59 , V_21 -> V_94 , NULL ) ;
F_81 ( & V_21 -> V_99 , F_77 ) ;
V_77:
F_73 ( V_3 ) ;
}
static int F_85 ( struct V_2 * V_3 , int V_117 )
{
struct V_20 * V_21 ;
V_21 = F_53 ( sizeof( * V_21 ) , V_118 ) ;
if ( ! V_21 )
return - V_58 ;
V_21 -> V_67 . V_18 = 0x100 ;
V_21 -> V_67 . V_119 = F_6 ;
V_21 -> V_67 . V_19 = V_21 ;
if ( F_86 ( & V_21 -> V_67 ,
& V_120 ) < 0 ) {
F_5 ( V_21 ) ;
return - V_58 ;
}
V_21 -> V_3 = V_3 ;
V_21 -> V_89 = V_117 & 0xffff ;
V_21 -> V_94 = V_95 ;
V_21 -> V_108 = 0 ;
V_21 -> V_107 = false ;
V_21 -> V_87 = false ;
++ V_3 -> V_83 ;
F_26 ( & V_21 -> V_34 ) ;
F_87 ( & V_21 -> V_99 , F_77 ) ;
F_22 ( & V_21 -> V_33 , & V_3 -> V_121 ) ;
return 0 ;
}
static int F_88 ( struct V_2 * V_3 ,
const T_5 * V_122 )
{
struct V_123 V_124 ;
int V_125 , V_126 ;
F_89 ( & V_124 , V_122 ) ;
while ( F_90 ( & V_124 , & V_125 , & V_126 ) )
if ( V_125 == V_127 &&
F_85 ( V_3 , V_126 ) < 0 )
return - V_58 ;
return 0 ;
}
static int F_91 ( struct V_2 * V_3 , const T_5 * V_122 ,
T_5 * V_128 , T_5 * V_129 )
{
struct V_123 V_124 ;
int V_125 , V_126 ;
F_89 ( & V_124 , V_122 ) ;
while ( F_90 ( & V_124 , & V_125 , & V_126 ) ) {
switch ( V_125 ) {
case V_130 | V_131 :
V_3 -> V_74 =
V_102 + 4 * V_126 ;
break;
case V_132 :
V_3 -> V_133 = V_126 ;
break;
case V_134 :
* V_128 = V_126 ;
break;
case V_135 :
* V_129 = V_126 ;
break;
case V_136 :
V_3 -> V_70 = ( V_126 >> 8 & 0xff ) * 500 ;
break;
case V_127 :
if ( F_85 ( V_3 , V_126 ) < 0 )
return - V_58 ;
break;
case V_137 :
if ( F_88 ( V_3 , V_124 . V_138 - 1 + V_126 ) < 0 )
return - V_58 ;
break;
}
}
return 0 ;
}
static void F_92 ( struct V_2 * V_3 )
{
unsigned int V_57 = V_3 -> V_70 ;
if ( V_57 > 40000 )
F_10 ( L_9 ,
V_3 -> V_76 , V_57 / 1000 ) ;
V_3 -> V_70 = F_93 ( V_57 , 5000 , 40000 ) ;
}
static void F_94 ( struct V_2 * V_3 , T_5 V_128 ,
T_5 V_129 )
{
int V_139 ;
unsigned int V_140 = V_141 ;
if ( V_140 )
F_10 ( L_10
L_11 ,
V_3 -> V_76 ) ;
if ( V_140 & V_142 )
goto V_77;
for ( V_139 = 0 ; V_139 < F_95 ( V_143 ) ; V_139 ++ ) {
if ( V_143 [ V_139 ] . V_129 !=
( V_129 & 0xffffff00 ) )
continue;
if ( V_143 [ V_139 ] . V_128 != V_128 &&
V_143 [ V_139 ] . V_128 != V_144 )
continue;
V_140 |= V_143 [ V_139 ] . V_113 ;
break;
}
V_77:
if ( V_140 )
F_10 ( L_12
L_13 ,
V_3 -> V_76 , V_140 , V_129 , V_128 ) ;
V_3 -> V_113 = V_140 ;
}
static int F_96 ( struct V_37 * V_145 )
{
struct V_146 * V_4 = V_146 ( V_145 ) ;
struct V_1 * V_37 = F_2 ( V_4 ) ;
struct V_2 * V_3 ;
struct V_20 * V_21 ;
struct V_84 * V_85 ;
T_5 V_128 , V_129 ;
if ( F_97 ( V_37 -> V_9 -> V_37 ) > V_147 )
F_98 ( F_99 ( V_37 -> V_9 -> V_37 ,
V_147 ) ) ;
V_85 = F_100 ( & V_148 , sizeof( * V_3 ) ) ;
if ( V_85 == NULL )
return - V_58 ;
V_3 = (struct V_2 * ) V_85 -> V_86 ;
F_101 ( & V_4 -> V_37 , V_3 ) ;
V_3 -> V_4 = V_4 ;
F_35 ( & V_3 -> V_5 ) ;
F_26 ( & V_3 -> V_121 ) ;
V_3 -> V_76 = F_102 ( & V_4 -> V_37 ) ;
V_3 -> V_149 = ( T_2 ) V_37 -> V_150 [ 3 ] << 32 | V_37 -> V_150 [ 4 ] ;
if ( F_103 ( V_37 ) < 0 )
goto V_151;
V_85 -> V_152 = V_153 ;
if ( F_104 ( V_85 , & V_4 -> V_37 ) < 0 )
goto V_151;
F_105 ( V_37 ) ;
F_106 ( V_4 ) ;
V_3 -> V_133 = ( ( V_4 -> V_122 - V_37 -> V_150 ) * 4
+ V_154 ) & 0xffffff ;
V_129 = V_155 ;
V_128 = V_155 ;
if ( F_91 ( V_3 , V_4 -> V_122 , & V_128 ,
& V_129 ) < 0 )
goto V_156;
F_92 ( V_3 ) ;
F_94 ( V_3 , V_128 , V_129 ) ;
V_3 -> V_157 = F_107 ( V_37 -> V_43 + 7 , 10U ) ;
V_3 -> V_157 = F_107 ( V_3 -> V_157 , V_37 -> V_9 -> V_158 - 1 ) ;
F_12 (lu, &tgt->lu_list, link)
F_74 ( V_21 , F_78 ( V_109 , 5 ) ) ;
return 0 ;
V_156:
F_73 ( V_3 ) ;
return - V_58 ;
V_151:
F_70 ( V_85 ) ;
return - V_58 ;
}
static int F_108 ( struct V_37 * V_145 )
{
struct V_146 * V_4 = V_146 ( V_145 ) ;
struct V_2 * V_3 = F_109 ( & V_4 -> V_37 ) ;
F_73 ( V_3 ) ;
return 0 ;
}
static void V_112 ( struct V_104 * V_99 )
{
struct V_20 * V_21 =
F_4 ( V_99 , struct V_20 , V_99 . V_99 ) ;
struct V_2 * V_3 = V_21 -> V_3 ;
struct V_1 * V_37 = F_1 ( V_3 ) ;
int V_15 , V_36 , V_106 ;
if ( F_33 ( V_37 ) )
goto V_77;
V_15 = V_37 -> V_15 ;
F_66 () ;
V_36 = V_37 -> V_36 ;
V_106 = V_37 -> V_9 -> V_36 ;
if ( F_32 ( V_21 , V_36 , V_15 ,
V_159 ,
V_21 -> V_94 , NULL ) < 0 ) {
F_66 () ;
if ( V_15 == V_37 -> V_9 -> V_15 ||
V_21 -> V_108 ++ >= 5 ) {
F_18 ( L_14 , V_3 -> V_76 ) ;
V_21 -> V_108 = 0 ;
F_81 ( & V_21 -> V_99 , F_77 ) ;
}
F_74 ( V_21 , F_78 ( V_109 , 5 ) ) ;
goto V_77;
}
V_3 -> V_36 = V_36 ;
V_3 -> V_110 = V_106 << 16 ;
F_79 () ;
V_21 -> V_15 = V_15 ;
F_10 ( L_15 ,
V_3 -> V_76 , V_21 -> V_89 , V_21 -> V_108 ) ;
F_49 ( V_21 ) ;
F_25 ( V_21 ) ;
F_57 ( V_21 ) ;
V_77:
F_73 ( V_3 ) ;
}
static void F_110 ( struct V_146 * V_4 )
{
struct V_2 * V_3 = F_109 ( & V_4 -> V_37 ) ;
struct V_20 * V_21 ;
F_103 ( F_2 ( V_4 ) ) ;
F_12 (lu, &tgt->lu_list, link) {
F_55 ( V_21 ) ;
V_21 -> V_108 = 0 ;
F_74 ( V_21 , 0 ) ;
}
}
static void F_111 ( struct V_37 * V_160 ,
struct V_161 * V_7 )
{
if ( F_112 ( V_7 -> V_162 ) )
F_113 ( V_160 , F_114 ( V_7 -> V_162 ) ,
F_112 ( V_7 -> V_162 ) ,
V_7 -> V_162 -> V_163 ) ;
if ( V_7 -> V_11 . V_64 & F_21 ( V_164 ) )
F_48 ( V_160 , V_7 -> V_165 ,
sizeof( V_7 -> V_166 ) , V_72 ) ;
}
static unsigned int F_115 ( T_6 * V_22 , T_6 * V_167 )
{
int V_168 ;
V_167 [ 0 ] = 0x70 ;
V_167 [ 1 ] = 0x0 ;
V_167 [ 2 ] = V_22 [ 1 ] ;
V_167 [ 3 ] = V_22 [ 4 ] ;
V_167 [ 4 ] = V_22 [ 5 ] ;
V_167 [ 5 ] = V_22 [ 6 ] ;
V_167 [ 6 ] = V_22 [ 7 ] ;
V_167 [ 7 ] = 10 ;
V_167 [ 8 ] = V_22 [ 8 ] ;
V_167 [ 9 ] = V_22 [ 9 ] ;
V_167 [ 10 ] = V_22 [ 10 ] ;
V_167 [ 11 ] = V_22 [ 11 ] ;
V_167 [ 12 ] = V_22 [ 2 ] ;
V_167 [ 13 ] = V_22 [ 3 ] ;
V_167 [ 14 ] = V_22 [ 12 ] ;
V_167 [ 15 ] = V_22 [ 13 ] ;
V_168 = V_22 [ 0 ] & 0x3f ;
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
static void F_116 ( struct V_6 * V_50 ,
struct V_22 * V_23 )
{
struct V_161 * V_7 =
F_4 ( V_50 , struct V_161 , V_52 ) ;
struct V_1 * V_37 = F_1 ( V_7 -> V_21 -> V_3 ) ;
int V_177 ;
if ( V_23 != NULL ) {
if ( F_117 ( * V_23 ) )
F_52 ( V_7 -> V_21 ) ;
switch ( F_46 ( * V_23 ) ) {
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
if ( V_177 == V_175 << 16 && F_118 ( * V_23 ) > 1 )
V_177 = F_115 ( F_119 ( * V_23 ) ,
V_7 -> V_162 -> V_183 ) ;
} else {
V_177 = V_180 << 16 ;
F_55 ( V_7 -> V_21 ) ;
}
F_48 ( V_37 -> V_9 -> V_37 , V_7 -> V_52 . V_31 ,
sizeof( V_7 -> V_11 ) , V_72 ) ;
F_111 ( V_37 -> V_9 -> V_37 , V_7 ) ;
V_7 -> V_162 -> V_177 = V_177 ;
V_7 -> V_162 -> V_184 ( V_7 -> V_162 ) ;
}
static int F_120 ( struct V_161 * V_7 ,
struct V_1 * V_37 , struct V_20 * V_21 )
{
struct V_185 * V_186 = F_114 ( V_7 -> V_162 ) ;
int V_139 , V_187 ;
V_187 = F_121 ( V_37 -> V_9 -> V_37 , V_186 , F_112 ( V_7 -> V_162 ) ,
V_7 -> V_162 -> V_163 ) ;
if ( V_187 == 0 )
goto V_188;
if ( V_187 == 1 ) {
V_7 -> V_11 . V_189 . V_40 =
F_21 ( V_21 -> V_3 -> V_110 ) ;
V_7 -> V_11 . V_189 . V_41 =
F_21 ( F_122 ( V_186 ) ) ;
V_7 -> V_11 . V_64 |=
F_21 ( F_123 ( F_124 ( V_186 ) ) ) ;
return 0 ;
}
F_125 (sg, sg, n, i) {
V_7 -> V_166 [ V_139 ] . V_40 = F_21 ( F_124 ( V_186 ) << 16 ) ;
V_7 -> V_166 [ V_139 ] . V_41 = F_21 ( F_122 ( V_186 ) ) ;
}
V_7 -> V_165 =
F_36 ( V_37 -> V_9 -> V_37 , V_7 -> V_166 ,
sizeof( V_7 -> V_166 ) , V_72 ) ;
if ( F_37 ( V_37 -> V_9 -> V_37 , V_7 -> V_165 ) )
goto V_190;
V_7 -> V_11 . V_189 . V_40 = F_21 ( V_21 -> V_3 -> V_110 ) ;
V_7 -> V_11 . V_189 . V_41 = F_21 ( V_7 -> V_165 ) ;
V_7 -> V_11 . V_64 |= F_21 ( V_164 |
F_123 ( V_187 ) ) ;
return 0 ;
V_190:
F_113 ( V_37 -> V_9 -> V_37 , F_114 ( V_7 -> V_162 ) ,
F_112 ( V_7 -> V_162 ) , V_7 -> V_162 -> V_163 ) ;
V_188:
return - V_58 ;
}
static int F_126 ( struct V_84 * V_85 ,
struct V_191 * V_162 )
{
struct V_20 * V_21 = V_162 -> V_37 -> V_86 ;
struct V_1 * V_37 = F_1 ( V_21 -> V_3 ) ;
struct V_161 * V_7 ;
int V_15 , V_47 = V_192 ;
if ( V_162 -> V_163 == V_193 ) {
F_18 ( L_16 ) ;
V_162 -> V_177 = V_176 << 16 ;
V_162 -> V_184 ( V_162 ) ;
return 0 ;
}
V_7 = F_34 ( sizeof( * V_7 ) , V_60 ) ;
if ( V_7 == NULL ) {
F_10 ( L_17 ) ;
return V_192 ;
}
V_7 -> V_52 . V_32 = - 1 ;
F_35 ( & V_7 -> V_52 . V_5 ) ;
V_7 -> V_21 = V_21 ;
V_7 -> V_162 = V_162 ;
V_7 -> V_11 . V_44 . V_40 = F_21 ( V_194 ) ;
V_7 -> V_11 . V_64 = F_21 (
F_127 ( V_21 -> V_3 -> V_157 ) |
F_128 ( V_37 -> V_43 ) |
V_195 ) ;
if ( V_162 -> V_163 == V_62 )
V_7 -> V_11 . V_64 |= F_21 ( V_196 ) ;
V_15 = V_37 -> V_15 ;
F_66 () ;
if ( F_112 ( V_162 ) && F_120 ( V_7 , V_37 , V_21 ) < 0 )
goto V_77;
memcpy ( V_7 -> V_11 . V_197 , V_162 -> V_198 , V_162 -> V_199 ) ;
V_7 -> V_52 . V_35 = F_116 ;
V_7 -> V_52 . V_31 =
F_36 ( V_37 -> V_9 -> V_37 , & V_7 -> V_11 ,
sizeof( V_7 -> V_11 ) , V_72 ) ;
if ( F_37 ( V_37 -> V_9 -> V_37 , V_7 -> V_52 . V_31 ) ) {
F_111 ( V_37 -> V_9 -> V_37 , V_7 ) ;
goto V_77;
}
F_20 ( & V_7 -> V_52 , V_21 , V_21 -> V_3 -> V_36 , V_15 ,
V_21 -> V_80 + V_200 ) ;
V_47 = 0 ;
V_77:
F_17 ( & V_7 -> V_52 . V_5 , F_3 ) ;
return V_47 ;
}
static int F_129 ( struct V_92 * V_93 )
{
struct V_20 * V_21 = V_93 -> V_86 ;
if ( ! V_21 )
return - V_201 ;
V_93 -> V_202 = 1 ;
F_130 ( V_93 -> V_203 , 4 - 1 ) ;
if ( V_21 -> V_3 -> V_113 & V_204 )
V_93 -> V_205 = 36 ;
return 0 ;
}
static int F_131 ( struct V_92 * V_93 )
{
struct V_20 * V_21 = V_93 -> V_86 ;
V_93 -> V_206 = 1 ;
if ( V_69 )
V_93 -> V_207 = 1 ;
if ( V_93 -> type == V_208 )
V_93 -> V_209 = 1 ;
if ( V_93 -> type == V_210 &&
V_21 -> V_3 -> V_113 & V_211 )
V_93 -> V_212 = 1 ;
if ( V_21 -> V_3 -> V_113 & V_213 )
V_93 -> V_214 = 1 ;
if ( V_21 -> V_3 -> V_113 & V_215 )
V_93 -> V_216 = 1 ;
if ( V_21 -> V_3 -> V_113 & V_217 )
F_132 ( V_93 -> V_203 , 128 * 1024 / 512 ) ;
F_133 ( V_93 -> V_203 , V_147 ) ;
return 0 ;
}
static int F_134 ( struct V_191 * V_162 )
{
struct V_20 * V_21 = V_162 -> V_37 -> V_86 ;
F_10 ( L_18 , V_21 -> V_3 -> V_76 ) ;
F_49 ( V_21 ) ;
F_25 ( V_21 ) ;
return V_218 ;
}
static T_7 F_135 ( struct V_37 * V_145 ,
struct V_219 * V_220 , char * V_221 )
{
struct V_92 * V_93 = F_136 ( V_145 ) ;
struct V_20 * V_21 ;
if ( ! V_93 )
return 0 ;
V_21 = V_93 -> V_86 ;
return sprintf ( V_221 , L_19 ,
( unsigned long long ) V_21 -> V_3 -> V_149 ,
V_21 -> V_3 -> V_133 , V_21 -> V_89 ) ;
}
static int T_8 F_137 ( void )
{
return F_138 ( & V_222 . V_223 ) ;
}
static void T_9 F_139 ( void )
{
F_140 ( & V_222 . V_223 ) ;
}
