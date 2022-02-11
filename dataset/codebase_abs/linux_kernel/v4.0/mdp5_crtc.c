static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_2 * V_3 , T_1 V_9 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_6 ( V_9 , & V_10 -> V_9 ) ;
F_7 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
}
static void F_8 ( struct V_2 * V_3 , T_2 V_13 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_9 ( L_1 , V_10 -> V_14 , V_13 ) ;
F_10 ( V_10 -> V_15 , V_13 ) ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_16 * V_17 ;
T_1 V_13 = 0 ;
if ( F_12 ( ! V_10 -> V_15 ) )
return;
F_13 (plane, crtc) {
V_13 |= F_14 ( V_17 ) ;
}
V_13 |= F_15 ( V_10 -> V_15 ) ;
V_13 |= F_16 ( V_10 -> V_18 ) ;
F_8 ( V_3 , V_13 ) ;
}
static void F_17 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_21 * V_6 = V_3 -> V_6 ;
struct V_22 * V_23 ;
struct V_16 * V_17 ;
unsigned long V_24 ;
F_18 ( & V_6 -> V_25 , V_24 ) ;
V_23 = V_10 -> V_23 ;
if ( V_23 ) {
if ( ! V_20 || ( V_23 -> V_11 . V_26 == V_20 ) ) {
V_10 -> V_23 = NULL ;
F_9 ( L_2 , V_10 -> V_14 , V_23 ) ;
F_19 ( V_6 , V_10 -> V_27 , V_23 ) ;
}
}
F_20 ( & V_6 -> V_25 , V_24 ) ;
F_13 (plane, crtc) {
F_21 ( V_17 ) ;
}
if ( V_10 -> V_15 && ! V_3 -> V_28 -> V_29 ) {
F_22 ( V_10 -> V_15 ) ;
V_10 -> V_15 = NULL ;
}
}
static void F_23 ( struct V_30 * V_31 , void * V_32 )
{
struct V_10 * V_10 =
F_24 ( V_31 , struct V_10 , V_33 ) ;
struct V_1 * V_1 = F_1 ( & V_10 -> V_11 ) ;
F_25 ( V_32 , V_1 -> V_27 ) ;
F_26 ( V_32 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_28 ( V_3 ) ;
F_29 ( & V_10 -> V_33 ) ;
F_30 ( V_10 ) ;
}
static bool F_31 ( struct V_2 * V_3 ,
const struct V_34 * V_35 ,
struct V_34 * V_36 )
{
return true ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_17 ;
const struct V_37 * V_38 ;
T_1 V_18 = V_10 -> V_18 , V_39 = 0 ;
unsigned long V_24 ;
#define F_33 ( T_3 ) ((stage) - STAGE_BASE)
V_38 = F_34 ( V_1 -> V_40 ) ;
F_18 ( & V_10 -> V_41 , V_24 ) ;
if ( ! V_10 -> V_15 )
goto V_42;
F_13 (plane, crtc) {
enum V_43 T_3 =
F_35 ( V_17 -> V_28 ) -> T_3 ;
F_36 ( T_3 > V_38 -> V_18 . V_44 ) ;
F_37 ( V_1 ,
F_38 ( V_18 , F_33 ( T_3 ) ) ,
F_39 ( V_45 ) |
F_40 ( V_46 ) ) ;
F_37 ( V_1 , F_41 ( V_18 ,
F_33 ( T_3 ) ) , 0xff ) ;
F_37 ( V_1 , F_42 ( V_18 ,
F_33 ( T_3 ) ) , 0x00 ) ;
V_39 |= F_43 ( F_44 ( V_17 ) , T_3 ) ;
F_9 ( L_3 , V_10 -> V_14 ,
F_45 ( F_44 ( V_17 ) ) , T_3 ) ;
}
F_9 ( L_4 , V_10 -> V_14 , V_18 , V_39 ) ;
F_46 ( V_10 -> V_15 , V_18 , V_39 ) ;
V_42:
F_20 ( & V_10 -> V_41 , V_24 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_24 ;
struct V_34 * V_35 ;
if ( F_12 ( ! V_3 -> V_28 ) )
return;
V_35 = & V_3 -> V_28 -> V_36 ;
F_9 ( L_5 ,
V_10 -> V_14 , V_35 -> V_11 . V_27 , V_35 -> V_14 ,
V_35 -> V_47 , V_35 -> clock ,
V_35 -> V_48 , V_35 -> V_49 ,
V_35 -> V_50 , V_35 -> V_51 ,
V_35 -> V_52 , V_35 -> V_53 ,
V_35 -> V_54 , V_35 -> V_55 ,
V_35 -> type , V_35 -> V_24 ) ;
F_18 ( & V_10 -> V_41 , V_24 ) ;
F_37 ( V_1 , F_48 ( V_10 -> V_18 ) ,
F_49 ( V_35 -> V_48 ) |
F_50 ( V_35 -> V_52 ) ) ;
F_20 ( & V_10 -> V_41 , V_24 ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_9 ( L_6 , V_10 -> V_14 ) ;
if ( F_12 ( ! V_10 -> V_56 ) )
return;
F_46 ( V_10 -> V_15 , V_10 -> V_18 , 0x00000000 ) ;
F_52 ( & V_1 -> V_11 , & V_10 -> V_57 ) ;
F_53 ( V_1 ) ;
V_10 -> V_56 = false ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_9 ( L_6 , V_10 -> V_14 ) ;
if ( F_12 ( V_10 -> V_56 ) )
return;
F_55 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_57 ) ;
F_11 ( V_3 ) ;
V_10 -> V_56 = true ;
}
static int F_56 ( const void * V_58 , const void * V_59 )
{
struct V_60 * V_61 = (struct V_60 * ) V_58 ;
struct V_60 * V_62 = (struct V_60 * ) V_59 ;
return V_61 -> V_28 -> V_63 - V_62 -> V_28 -> V_63 ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_64 * V_28 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_17 ;
struct V_21 * V_6 = V_3 -> V_6 ;
struct V_60 V_65 [ V_66 + 1 ] ;
int V_67 = 0 , V_68 ;
F_9 ( L_7 , V_10 -> V_14 ) ;
if ( V_28 -> V_29 && ! V_10 -> V_15 ) {
V_10 -> V_15 = F_58 ( V_1 -> V_69 , V_3 ) ;
if ( F_12 ( ! V_10 -> V_15 ) )
return - V_70 ;
}
F_59 (plane, state) {
struct V_71 * V_72 ;
if ( V_67 >= F_60 ( V_65 ) ) {
F_61 ( V_6 -> V_6 , L_8 ) ;
return - V_70 ;
}
V_72 = V_28 -> V_28 -> V_73 [ F_62 ( V_17 ) ] ;
if ( ! V_72 )
V_72 = V_17 -> V_28 ;
V_65 [ V_67 ] . V_17 = V_17 ;
V_65 [ V_67 ] . V_28 = F_35 ( V_72 ) ;
V_67 ++ ;
}
F_63 ( V_65 , V_67 , sizeof( V_65 [ 0 ] ) , F_56 , NULL ) ;
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
V_65 [ V_68 ] . V_28 -> T_3 = V_74 + V_68 ;
F_9 ( L_9 , V_10 -> V_14 ,
F_45 ( F_44 ( V_65 [ V_68 ] . V_17 ) ) ,
V_65 [ V_68 ] . V_28 -> T_3 ) ;
}
return 0 ;
}
static void F_64 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_9 ( L_10 , V_10 -> V_14 ) ;
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_21 * V_6 = V_3 -> V_6 ;
unsigned long V_24 ;
F_9 ( L_11 , V_10 -> V_14 , V_3 -> V_28 -> V_23 ) ;
F_12 ( V_10 -> V_23 ) ;
F_18 ( & V_6 -> V_25 , V_24 ) ;
V_10 -> V_23 = V_3 -> V_28 -> V_23 ;
F_20 ( & V_6 -> V_25 , V_24 ) ;
if ( F_66 ( ! V_10 -> V_15 ) )
return;
F_32 ( V_3 ) ;
F_11 ( V_3 ) ;
F_4 ( V_3 , V_75 ) ;
}
static int F_67 ( struct V_2 * V_3 ,
struct V_76 * V_77 , T_4 V_32 )
{
return - V_70 ;
}
static void F_68 ( struct V_2 * V_3 , T_1 * V_78 , T_1 * V_79 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_80 = V_3 -> V_35 . V_48 ;
T_1 V_81 = V_3 -> V_35 . V_52 ;
* V_78 = F_69 ( V_10 -> V_82 . V_83 , V_80 -
V_10 -> V_82 . V_84 ) ;
* V_79 = F_69 ( V_10 -> V_82 . V_85 , V_81 -
V_10 -> V_82 . V_86 ) ;
}
static int F_70 ( struct V_2 * V_3 ,
struct V_19 * V_20 , T_1 V_87 ,
T_1 V_83 , T_1 V_85 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_21 * V_6 = V_3 -> V_6 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_88 * V_89 , * V_90 ;
T_1 V_91 , V_92 , V_93 ;
int V_94 , V_95 , V_18 ;
unsigned int V_96 ;
enum V_97 V_98 = V_99 ;
T_1 V_13 = F_71 ( 0 ) ;
T_1 V_78 , V_79 ;
unsigned long V_24 ;
if ( ( V_83 > V_100 ) || ( V_85 > V_101 ) ) {
F_61 ( V_6 -> V_6 , L_12 , V_83 , V_85 ) ;
return - V_70 ;
}
if ( NULL == V_10 -> V_15 )
return - V_70 ;
if ( ! V_87 ) {
F_9 ( L_13 ) ;
return F_72 ( V_10 -> V_15 , false ) ;
}
V_89 = F_73 ( V_6 , V_20 , V_87 ) ;
if ( ! V_89 )
return - V_102 ;
V_94 = F_74 ( V_89 , V_1 -> V_27 , & V_92 ) ;
if ( V_94 )
return - V_70 ;
V_18 = V_10 -> V_18 ;
F_75 ( V_103 , & V_96 , & V_95 ) ;
V_93 = V_83 * ( V_95 >> 3 ) ;
F_18 ( & V_10 -> V_82 . V_104 , V_24 ) ;
V_90 = V_10 -> V_82 . V_105 ;
V_10 -> V_82 . V_105 = V_89 ;
V_10 -> V_82 . V_83 = V_83 ;
V_10 -> V_82 . V_85 = V_85 ;
F_68 ( V_3 , & V_78 , & V_79 ) ;
F_37 ( V_1 , F_76 ( V_18 ) , V_93 ) ;
F_37 ( V_1 , F_77 ( V_18 ) ,
F_78 ( V_106 ) ) ;
F_37 ( V_1 , F_79 ( V_18 ) ,
F_80 ( V_85 ) |
F_81 ( V_83 ) ) ;
F_37 ( V_1 , F_82 ( V_18 ) ,
F_83 ( V_79 ) |
F_84 ( V_78 ) ) ;
F_37 ( V_1 , F_85 ( V_18 ) , V_92 ) ;
V_91 = V_107 ;
V_91 |= F_86 ( V_98 ) ;
F_37 ( V_1 , F_87 ( V_18 ) , V_91 ) ;
F_20 ( & V_10 -> V_82 . V_104 , V_24 ) ;
V_94 = F_72 ( V_10 -> V_15 , true ) ;
if ( V_94 )
goto V_108;
V_13 |= F_15 ( V_10 -> V_15 ) ;
F_8 ( V_3 , V_13 ) ;
V_108:
if ( V_90 ) {
F_88 ( & V_10 -> V_33 , V_90 ) ;
F_4 ( V_3 , V_109 ) ;
}
return V_94 ;
}
static int F_89 ( struct V_2 * V_3 , int V_84 , int V_86 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_13 = F_71 ( 0 ) ;
T_1 V_78 ;
T_1 V_79 ;
unsigned long V_24 ;
if ( F_66 ( ! V_3 -> V_28 -> V_29 ) )
return 0 ;
V_10 -> V_82 . V_84 = V_84 = F_90 ( V_84 , 0 ) ;
V_10 -> V_82 . V_86 = V_86 = F_90 ( V_86 , 0 ) ;
F_68 ( V_3 , & V_78 , & V_79 ) ;
F_18 ( & V_10 -> V_82 . V_104 , V_24 ) ;
F_37 ( V_1 , F_82 ( V_10 -> V_18 ) ,
F_83 ( V_79 ) |
F_84 ( V_78 ) ) ;
F_37 ( V_1 , F_91 ( V_10 -> V_18 ) ,
F_92 ( V_86 ) |
F_93 ( V_84 ) ) ;
F_20 ( & V_10 -> V_82 . V_104 , V_24 ) ;
F_8 ( V_3 , V_13 ) ;
return 0 ;
}
static void F_94 ( struct V_110 * V_111 , T_1 V_112 )
{
struct V_10 * V_10 = F_24 ( V_111 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_52 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_95 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_75 ) {
F_17 ( V_3 , NULL ) ;
}
if ( V_9 & V_109 )
F_96 ( & V_10 -> V_33 , V_5 -> V_113 ) ;
}
static void F_97 ( struct V_110 * V_111 , T_1 V_112 )
{
struct V_10 * V_10 = F_24 ( V_111 , struct V_10 , V_57 ) ;
F_9 ( L_14 , V_10 -> V_14 , V_112 ) ;
}
T_1 F_98 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_114 ;
}
void F_99 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
F_9 ( L_15 , V_20 ) ;
F_17 ( V_3 , V_20 ) ;
}
void F_100 ( struct V_2 * V_3 , int V_115 ,
enum V_116 V_117 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_13 = 0 ;
T_1 V_118 ;
unsigned long V_24 ;
V_10 -> V_57 . V_114 = F_101 ( V_115 ) ;
V_10 -> V_12 . V_114 = F_102 ( V_115 ) ;
F_103 ( & V_1 -> V_11 ) ;
F_18 ( & V_1 -> V_119 , V_24 ) ;
V_118 = F_104 ( V_1 , V_120 ) ;
switch ( V_115 ) {
case 0 :
V_118 &= ~ V_121 ;
V_118 |= F_105 ( V_117 ) ;
break;
case 1 :
V_118 &= ~ V_122 ;
V_118 |= F_106 ( V_117 ) ;
break;
case 2 :
V_118 &= ~ V_123 ;
V_118 |= F_107 ( V_117 ) ;
break;
case 3 :
V_118 &= ~ V_124 ;
V_118 |= F_108 ( V_117 ) ;
break;
default:
F_109 () ;
break;
}
F_37 ( V_1 , V_120 , V_118 ) ;
F_20 ( & V_1 -> V_119 , V_24 ) ;
F_9 ( L_16 , V_10 -> V_14 , V_118 ) ;
F_110 ( V_10 -> V_15 , V_115 ) ;
V_13 |= F_15 ( V_10 -> V_15 ) ;
V_13 |= F_16 ( V_10 -> V_18 ) ;
F_8 ( V_3 , V_13 ) ;
}
int F_111 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
if ( F_12 ( ! V_3 ) )
return - V_70 ;
return V_10 -> V_18 ;
}
struct V_2 * F_112 ( struct V_21 * V_6 ,
struct V_16 * V_17 , int V_27 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_113 ( sizeof( * V_10 ) , V_125 ) ;
if ( ! V_10 )
return F_114 ( - V_126 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_27 = V_27 ;
V_10 -> V_18 = F_115 ( V_27 ) ;
F_116 ( & V_10 -> V_41 ) ;
F_116 ( & V_10 -> V_82 . V_104 ) ;
V_10 -> V_12 . V_111 = F_94 ;
V_10 -> V_57 . V_111 = F_97 ;
snprintf ( V_10 -> V_14 , sizeof( V_10 -> V_14 ) , L_17 ,
F_45 ( F_44 ( V_17 ) ) , V_27 ) ;
F_117 ( V_6 , V_3 , V_17 , NULL , & V_127 ) ;
F_118 ( & V_10 -> V_33 ,
L_18 , F_23 ) ;
F_119 ( V_3 , & V_128 ) ;
V_17 -> V_3 = V_3 ;
F_120 ( V_17 , & V_3 -> V_11 ) ;
return V_3 ;
}
